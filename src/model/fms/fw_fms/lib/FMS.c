/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1936
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Sep 19 22:34:32 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S38>/Motion Status' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<S196>/Motion Status' */
#define FMS_IN_Brake_o                 ((uint8_T)1U)
#define FMS_IN_Hold_h                  ((uint8_T)2U)
#define FMS_IN_Move_j                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_o       ((uint8_T)0U)

/* Named constants for Chart: '<Root>/FMS State Machine' */
#define FMS_IN_Acro                    ((uint8_T)1U)
#define FMS_IN_Altitude                ((uint8_T)2U)
#define FMS_IN_Arm                     ((uint8_T)1U)
#define FMS_IN_Assist                  ((uint8_T)1U)
#define FMS_IN_Auto                    ((uint8_T)2U)
#define FMS_IN_Check                   ((uint8_T)1U)
#define FMS_IN_Disarm                  ((uint8_T)2U)
#define FMS_IN_Disarming               ((uint8_T)1U)
#define FMS_IN_Hold_h4                 ((uint8_T)1U)
#define FMS_IN_Idle                    ((uint8_T)3U)
#define FMS_IN_InValidManualMode       ((uint8_T)1U)
#define FMS_IN_InvalidArmMode          ((uint8_T)3U)
#define FMS_IN_InvalidAssistMode       ((uint8_T)3U)
#define FMS_IN_InvalidAutoMode         ((uint8_T)1U)
#define FMS_IN_Land                    ((uint8_T)2U)
#define FMS_IN_Listen                  ((uint8_T)2U)
#define FMS_IN_Loiter                  ((uint8_T)3U)
#define FMS_IN_Manual                  ((uint8_T)4U)
#define FMS_IN_Manual_g                ((uint8_T)2U)
#define FMS_IN_Mission                 ((uint8_T)2U)
#define FMS_IN_NextWP                  ((uint8_T)4U)
#define FMS_IN_Offboard                ((uint8_T)3U)
#define FMS_IN_Position                ((uint8_T)4U)
#define FMS_IN_Return                  ((uint8_T)3U)
#define FMS_IN_Return_h                ((uint8_T)5U)
#define FMS_IN_Send                    ((uint8_T)3U)
#define FMS_IN_Stabilize               ((uint8_T)5U)
#define FMS_IN_Standby                 ((uint8_T)3U)
#define FMS_IN_SubMode                 ((uint8_T)5U)
#define FMS_IN_Takeoff                 ((uint8_T)4U)
#define FMS_IN_Takeoff_d               ((uint8_T)6U)
#define FMS_IN_Waypoint                ((uint8_T)7U)
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
  0U,                                  /* throttle_cmd */

  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
  ,                                    /* actuator_cmd */
  0U,                                  /* status */
  0U,                                  /* state */
  0U,                                  /* ctrl_mode */
  0U,                                  /* mode */
  0U,                                  /* reset */
  0U,                                  /* wp_consume */
  0U,                                  /* wp_current */
  0U                                   /* reserved1 */
} ;                                    /* FMS_Out_Bus ground */

/* Exported block parameters */
struct_E1qbCEGvnS3XtzDqfoNznD FMS_PARAM = {
  0.15F,
  0.15F,
  0.1F,
  0.1F,
  0.95F,
  1.0F,
  2.5F,
  2.5F,
  1.04719758F,
  0.52359879F,
  15.0F,
  13.0F,
  1.5F,
  15.0F,
  50.0F,
  0.95F,
  5.0F,
  0.785398185F,
  0.785398185F,
  30.0F,

  { 1000.0F, 1000.0F, 1500.0F, 1500.0F, 1500.0F, 1500.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F },

  { 1000.0F, 1000.0F, 1500.0F, 1500.0F, 1500.0F, 1500.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F },
  5.0F
} ;                                    /* Variable: FMS_PARAM
                                        * Referenced by:
                                        *   '<Root>/ACCEPT_R'
                                        *   '<S246>/Constant'
                                        *   '<S19>/Constant6'
                                        *   '<S20>/Constant6'
                                        *   '<S143>/L1'
                                        *   '<S33>/Gain'
                                        *   '<S35>/Gain'
                                        *   '<S36>/Gain1'
                                        *   '<S54>/Gain'
                                        *   '<S56>/Gain1'
                                        *   '<S100>/Gain'
                                        *   '<S100>/Gain1'
                                        *   '<S101>/Gain1'
                                        *   '<S116>/Constant4'
                                        *   '<S146>/Gain2'
                                        *   '<S147>/L1'
                                        *   '<S147>/R'
                                        *   '<S164>/Saturation1'
                                        *   '<S237>/Gain2'
                                        *   '<S237>/Saturation1'
                                        *   '<S37>/Saturation1'
                                        *   '<S48>/Dead Zone'
                                        *   '<S48>/Gain'
                                        *   '<S51>/Dead Zone'
                                        *   '<S51>/Gain'
                                        *   '<S58>/Saturation1'
                                        *   '<S69>/Dead Zone'
                                        *   '<S69>/Gain'
                                        *   '<S72>/Saturation1'
                                        *   '<S103>/Dead Zone'
                                        *   '<S103>/Gain'
                                        *   '<S104>/Dead Zone'
                                        *   '<S104>/Gain'
                                        *   '<S109>/Dead Zone'
                                        *   '<S109>/Gain'
                                        *   '<S117>/Gain'
                                        *   '<S117>/Saturation1'
                                        *   '<S165>/Gain2'
                                        *   '<S187>/vel'
                                        *   '<S187>/Saturation'
                                        *   '<S187>/Switch'
                                        *   '<S40>/Gain2'
                                        *   '<S41>/Gain1'
                                        *   '<S46>/Constant'
                                        *   '<S61>/Gain2'
                                        *   '<S62>/Gain1'
                                        *   '<S67>/Constant'
                                        *   '<S75>/L1'
                                        *   '<S76>/Gain6'
                                        *   '<S96>/Constant'
                                        *   '<S122>/L1'
                                        *   '<S122>/Saturation1'
                                        *   '<S174>/Gain2'
                                        *   '<S174>/Saturation'
                                        *   '<S175>/Integrator'
                                        *   '<S43>/Dead Zone'
                                        *   '<S43>/Gain'
                                        *   '<S64>/Dead Zone'
                                        *   '<S64>/Gain'
                                        *   '<S93>/Dead Zone'
                                        *   '<S93>/Gain'
                                        *   '<S195>/Saturation1'
                                        *   '<S205>/Saturation1'
                                        *   '<S198>/Gain2'
                                        *   '<S199>/Gain1'
                                        *   '<S208>/Gain2'
                                        *   '<S209>/Gain6'
                                        *   '<S201>/Dead Zone'
                                        *   '<S201>/Gain'
                                        *   '<S213>/Dead Zone'
                                        *   '<S213>/Gain'
                                        *   '<S214>/Dead Zone'
                                        *   '<S214>/Gain'
                                        */

struct_i6HyuFQRjfkj8sSCv2bg5D FMS_EXPORT = {
  4U,

  { 70, 87, 32, 70, 77, 83, 32, 118, 48, 46, 48, 46, 49, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S5>/Constant1'
                                        *   '<S244>/Constant'
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
static void FMS_exit_internal_Auto(void);
static real_T FMS_getArmMode(PilotMode pilotMode);
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
 * System initialize for action system:
 *    '<S195>/Hold Control'
 *    '<S37>/Hold Control'
 *    '<S58>/Hold Control'
 */
void FMS_HoldControl_Init(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S198>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S195>/Hold Control'
 *    '<S37>/Hold Control'
 *    '<S58>/Hold Control'
 */
void FMS_HoldControl_Reset(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S198>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S195>/Hold Control'
 *    '<S37>/Hold Control'
 *    '<S58>/Hold Control'
 */
void FMS_HoldControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
                     DW_HoldControl_FMS_T *localDW)
{
  /* Delay: '<S198>/Delay' incorporates:
   *  Gain: '<S200>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S198>/Gain2' incorporates:
   *  Delay: '<S198>/Delay'
   *  Gain: '<S200>/Gain'
   *  Sum: '<S198>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.Z_P;

  /* Update for Delay: '<S198>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S195>/Brake Control'
 *    '<S37>/Brake Control'
 *    '<S58>/Brake Control'
 */
void FMS_BrakeControl(real32_T *rty_psi_rate_cmd_radPs)
{
  /* SignalConversion: '<S197>/OutportBuffer_InsertedFor_psi_rate_cmd_radPs_at_inport_0' incorporates:
   *  Constant: '<S197>/Brake Speed'
   */
  *rty_psi_rate_cmd_radPs = 0.0F;
}

/*
 * Output and update for atomic system:
 *    '<S189>/NearbyRefWP'
 *    '<S124>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_g, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S220>/TmpSignal ConversionAt SFunction Inport2' */
  P3P2_idx_0 = rtu_P2[0] - rtu_P3;
  P3P2_idx_1 = rtu_P2[1] - rtu_P3_g;
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

  /* BusAssignment: '<S145>/Bus Assignment' incorporates:
   *  Constant: '<S145>/Constant'
   *  Constant: '<S145>/Constant2'
   *  SignalConversion: '<S145>/TmpHiddenBufferAtBus AssignmentInport1'
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

  /* End of BusAssignment: '<S145>/Bus Assignment' */
}

/*
 * Output and update for action system:
 *    '<S37>/Move Control'
 *    '<S58>/Move Control'
 */
void FMS_MoveControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs)
{
  real32_T rtu_FMS_In_0;

  /* DeadZone: '<S43>/Dead Zone' */
  if (rtu_FMS_In > FMS_PARAM.PITCH_DZ) {
    rtu_FMS_In_0 = rtu_FMS_In - FMS_PARAM.PITCH_DZ;
  } else if (rtu_FMS_In >= -FMS_PARAM.PITCH_DZ) {
    rtu_FMS_In_0 = 0.0F;
  } else {
    rtu_FMS_In_0 = rtu_FMS_In - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S43>/Dead Zone' */

  /* Gain: '<S41>/Gain1' incorporates:
   *  Gain: '<S43>/Gain'
   */
  *rty_w_cmd_mPs = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) * rtu_FMS_In_0 *
    FMS_PARAM.VEL_Z_LIM;
}

/*
 * System initialize for atomic system:
 *    '<S38>/Motion Status'
 *    '<S59>/Motion Status'
 */
void FMS_MotionStatus_Init(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c17_FMS = 0U;
  localDW->is_c17_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * System reset for atomic system:
 *    '<S38>/Motion Status'
 *    '<S59>/Motion Status'
 */
void FMS_MotionStatus_Reset(DW_MotionStatus_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c17_FMS = 0U;
  localDW->is_c17_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * Output and update for atomic system:
 *    '<S38>/Motion Status'
 *    '<S59>/Motion Status'
 */
void FMS_MotionStatus(boolean_T rtu_motion_req, real32_T rtu_speed, MotionState *
                      rty_state, DW_MotionStatus_FMS_T *localDW)
{
  /* Chart: '<S38>/Motion Status' */
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

  /* End of Chart: '<S38>/Motion Status' */
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
    if (((ins_flag & 1U) != 0U) && ((ins_flag & 4U) != 0U) && ((ins_flag & 8U)
         != 0U) && ((ins_flag & 16U) != 0U) && ((ins_flag & 64U) != 0U) &&
        ((ins_flag & 128U) != 0U)) {
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
    FMS_DW.M_msgHandle = FMS_pop(&FMS_DW.Queue_FMS_Cmd_p, &FMS_DW.Msg_FMS_Cmd_c
      [0]) != 0 ? (void *)&FMS_DW.Msg_FMS_Cmd_c[0] : NULL;
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
static void FMS_exit_internal_Auto(void)
{
  if (FMS_DW.is_Auto == FMS_IN_Mission) {
    FMS_DW.is_Mission = FMS_IN_NO_ACTIVE_CHILD_o;
    FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_o;
  } else {
    FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_o;
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
  uint32_T qY_tmp;
  FMS_B.stick_val[0] = FMS_DW.stick_val[0];
  FMS_B.stick_val[1] = FMS_DW.stick_val[1];
  FMS_B.stick_val[2] = FMS_DW.stick_val[2];
  FMS_B.stick_val[3] = FMS_DW.stick_val[3];
  FMS_B.pilot_cmd = FMS_B.BusConversion_InsertedFor_FMS_f;

  /* Outputs for Function Call SubSystem: '<S3>/Vehicle.StickMoved' */
  /* RelationalOperator: '<S258>/Compare' incorporates:
   *  Abs: '<S247>/Abs'
   *  Constant: '<S258>/Constant'
   *  MinMax: '<S247>/Max'
   *  Sum: '<S247>/Sum'
   */
  FMS_B.Compare = (fmax(fmax(fmax(fabs(FMS_B.stick_val[0] -
    FMS_B.pilot_cmd.stick_yaw), fabs(FMS_B.stick_val[1] -
    FMS_B.pilot_cmd.stick_throttle)), fabs(FMS_B.stick_val[2] -
    FMS_B.pilot_cmd.stick_roll)), fabs(FMS_B.stick_val[3] -
    FMS_B.pilot_cmd.stick_pitch)) >= 0.1);

  /* End of Outputs for SubSystem: '<S3>/Vehicle.StickMoved' */
  if (FMS_B.Compare && (FMS_B.target_mode != PilotMode_None)) {
    if (FMS_getArmMode(FMS_B.target_mode) == 3.0) {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_o;
      FMS_DW.is_Arm = FMS_IN_Auto;
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
        FMS_B.Cmd_In.cur_waypoint[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
        FMS_B.Cmd_In.cur_waypoint[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
        FMS_B.Cmd_In.cur_waypoint[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
        FMS_DW.is_Mission = FMS_IN_NextWP;

        /* Inport: '<Root>/Mission_Data' */
        if (FMS_B.wp_index <= FMS_U.Mission_Data.valid_items) {
          FMS_DW.nav_cmd = FMS_U.Mission_Data.command[FMS_B.wp_index - 1];
        } else {
          FMS_DW.nav_cmd = (uint16_T)NAV_Cmd_None;
          qY_tmp = FMS_B.wp_index - /*MW:OvSatOk*/ 1U;
          if (qY_tmp > FMS_B.wp_index) {
            qY_tmp = 0U;
          }

          FMS_B.wp_consume = (uint8_T)qY_tmp;
        }
        break;

       default:
        FMS_DW.is_Auto = FMS_IN_InvalidAutoMode;
        break;
      }
    } else if (FMS_getArmMode(FMS_B.target_mode) == 2.0) {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_o;
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
    } else if (FMS_getArmMode(FMS_B.target_mode) == 1.0) {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_o;
      FMS_DW.is_Arm = FMS_IN_Manual;
      if (FMS_B.target_mode == PilotMode_Manual) {
        FMS_DW.is_Manual = FMS_IN_Manual_g;
        FMS_B.state = VehicleState_Manual;
      } else {
        FMS_DW.is_Manual = FMS_IN_InValidManualMode;
      }
    } else {
      FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_o;
      FMS_DW.is_Arm = FMS_IN_InvalidArmMode;
    }
  } else {
    if (FMS_sf_msg_pop_M()) {
      b_sf_internal_predicateOutput = (FMS_DW.M_msgReservedData == FMS_Cmd_Pause);
    } else {
      b_sf_internal_predicateOutput = false;
    }

    if (b_sf_internal_predicateOutput) {
      FMS_DW.is_SubMode = FMS_IN_Hold_h4;
      FMS_B.state = VehicleState_Hold;
    } else {
      switch (FMS_DW.is_SubMode) {
       case FMS_IN_Hold_h4:
        if (FMS_sf_msg_pop_M()) {
          b_sf_internal_predicateOutput = ((FMS_DW.M_msgReservedData ==
            FMS_Cmd_Continue) && (FMS_B.target_mode != PilotMode_None));
        } else {
          b_sf_internal_predicateOutput = false;
        }

        if (b_sf_internal_predicateOutput) {
          FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_o;
          FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_o;
          FMS_enter_internal_Arm();
        }
        break;

       case FMS_IN_Land:
        FMS_DW.durationLastReferenceTick_1_j = FMS_DW.chartAbsoluteTimeCounter;

        /* Constant: '<Root>/Constant' */
        FMS_DW.condWasTrueAtLastTimeStep_1_d = false;
        if (FMS_DW.chartAbsoluteTimeCounter -
            FMS_DW.durationLastReferenceTick_1_j >= 500) {
          FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_o;
          FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_o;
          FMS_DW.is_Vehicle = FMS_IN_Disarm;
          FMS_B.state = VehicleState_Disarm;
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
          FMS_B.Cmd_In.sp_land[0] = FMS_DW.home[0];
          FMS_B.Cmd_In.sp_land[1] = FMS_DW.home[1];
          FMS_DW.durationLastReferenceTick_1_j = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.is_SubMode = FMS_IN_Land;
          FMS_B.state = VehicleState_Land;

          /* Constant: '<Root>/Constant' */
          FMS_DW.condWasTrueAtLastTimeStep_1_d = false;
        }

        /* End of Constant: '<Root>/ACCEPT_R' */
        break;

       case FMS_IN_Takeoff:
        if (FMS_B.BusConversion_InsertedFor_FMSSt.h_R >=
            FMS_B.Cmd_In.sp_takeoff[2]) {
          if (FMS_B.target_mode != PilotMode_None) {
            tmp = FMS_getArmMode(FMS_B.target_mode);
            if (tmp == 3.0) {
              FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_o;
              FMS_DW.is_Arm = FMS_IN_Auto;
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
                  qY_tmp = FMS_B.wp_index - /*MW:OvSatOk*/ 1U;
                  if (qY_tmp > FMS_B.wp_index) {
                    qY_tmp = 0U;
                  }

                  FMS_B.wp_consume = (uint8_T)qY_tmp;
                }
                break;

               default:
                FMS_DW.is_Auto = FMS_IN_InvalidAutoMode;
                break;
              }
            } else if (tmp == 2.0) {
              FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_o;
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
              FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_o;
              FMS_DW.is_Arm = FMS_IN_Manual;
              if (FMS_B.target_mode == PilotMode_Manual) {
                FMS_DW.is_Manual = FMS_IN_Manual_g;
                FMS_B.state = VehicleState_Manual;
              } else {
                FMS_DW.is_Manual = FMS_IN_InValidManualMode;
              }
            } else {
              FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_o;
              FMS_DW.is_Arm = FMS_IN_InvalidArmMode;
            }
          } else {
            FMS_DW.is_SubMode = FMS_IN_Hold_h4;
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
    FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_o;
  } else {
    FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_o;
    FMS_DW.is_Manual = FMS_IN_NO_ACTIVE_CHILD_o;
    FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_o;
    FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_o;
  }
}

/* Function for Chart: '<Root>/FMS State Machine' */
static void FMS_Arm(void)
{
  boolean_T c_sf_internal_predicateOutput;
  real_T rtb_Multiply2;
  real_T rtb_Sum2_m;
  real_T rtb_Gain;
  real_T rtb_Sum_d;
  real32_T tmp[2];
  int32_T rtb_Compare_d_0;
  real_T rtb_Sum_idx_0;
  uint32_T qY;
  FMS_DW.durationLastReferenceTick_1_c = FMS_DW.chartAbsoluteTimeCounter;

  /* Constant: '<Root>/Constant' */
  FMS_DW.condWasTrueAtLastTimeStep_1_d0 = false;
  if ((FMS_DW.chartAbsoluteTimeCounter - FMS_DW.durationLastReferenceTick_1_c >=
       500) && (FMS_B.target_mode != PilotMode_Mission)) {
    FMS_exit_internal_Arm();
    FMS_DW.is_Vehicle = FMS_IN_Disarm;
    FMS_B.state = VehicleState_Disarm;
  } else if ((FMS_DW.mode_prev != FMS_DW.mode_start) && (FMS_B.target_mode !=
              PilotMode_None)) {
    rtb_Sum_idx_0 = FMS_getArmMode(FMS_B.target_mode);
    if (rtb_Sum_idx_0 == 3.0) {
      FMS_exit_internal_Arm();
      FMS_DW.is_Arm = FMS_IN_Auto;
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
    } else if (rtb_Sum_idx_0 == 2.0) {
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
      c_sf_internal_predicateOutput = (FMS_DW.M_msgReservedData == FMS_Cmd_Land);
    } else {
      c_sf_internal_predicateOutput = false;
    }

    if (c_sf_internal_predicateOutput) {
      FMS_B.Cmd_In.sp_land[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
      FMS_B.Cmd_In.sp_land[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
      FMS_exit_internal_Arm();
      FMS_DW.is_Arm = FMS_IN_SubMode;
      FMS_DW.stick_val[0] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw;
      FMS_DW.stick_val[1] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle;
      FMS_DW.stick_val[2] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_roll;
      FMS_DW.stick_val[3] = FMS_B.BusConversion_InsertedFor_FMS_f.stick_pitch;
      FMS_DW.durationLastReferenceTick_1_j = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_SubMode = FMS_IN_Land;
      FMS_B.state = VehicleState_Land;

      /* Constant: '<Root>/Constant' */
      FMS_DW.condWasTrueAtLastTimeStep_1_d = false;
    } else {
      if (FMS_sf_msg_pop_M()) {
        c_sf_internal_predicateOutput = (FMS_DW.M_msgReservedData ==
          FMS_Cmd_Return);
      } else {
        c_sf_internal_predicateOutput = false;
      }

      if (c_sf_internal_predicateOutput) {
        FMS_B.Cmd_In.sp_return[0] = FMS_DW.home[0];
        FMS_B.Cmd_In.sp_return[1] = FMS_DW.home[1];
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
            FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_o;
            FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_o;
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
            FMS_DW.is_SubMode = FMS_IN_Hold_h4;
            FMS_B.state = VehicleState_Hold;
          } else {
            switch (FMS_DW.is_Auto) {
             case FMS_IN_InvalidAutoMode:
              FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_o;
              FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_o;
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
                  FMS_DW.is_Mission = FMS_IN_NO_ACTIVE_CHILD_o;
                  FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_o;
                  FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_o;
                  FMS_DW.is_Vehicle = FMS_IN_Disarm;
                  FMS_B.state = VehicleState_Disarm;
                  break;

                 case FMS_IN_Land:
                  FMS_DW.durationLastReferenceTick_1 =
                    FMS_DW.chartAbsoluteTimeCounter;

                  /* Constant: '<Root>/Constant' */
                  FMS_DW.condWasTrueAtLastTimeStep_1 = false;
                  if (FMS_DW.chartAbsoluteTimeCounter -
                      FMS_DW.durationLastReferenceTick_1 >= 500) {
                    rtb_Compare_d_0 = (int32_T)(FMS_B.wp_index + 1U);
                    if ((uint32_T)rtb_Compare_d_0 > 255U) {
                      rtb_Compare_d_0 = 255;
                    }

                    FMS_B.wp_index = (uint8_T)rtb_Compare_d_0;
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

                 case FMS_IN_Loiter:
                  break;

                 case FMS_IN_NextWP:
                  if (FMS_DW.nav_cmd == (int32_T)NAV_Cmd_Waypoint) {
                    FMS_DW.is_Mission = FMS_IN_Waypoint;

                    /* Inport: '<Root>/Mission_Data' */
                    FMS_B.lla[0] = (real_T)FMS_U.Mission_Data.x[FMS_B.wp_index -
                      1] * 1.0E-7;
                    FMS_B.lla[1] = (real_T)FMS_U.Mission_Data.y[FMS_B.wp_index -
                      1] * 1.0E-7;
                    FMS_B.lla[2] = -(FMS_U.Mission_Data.z[FMS_B.wp_index - 1] +
                                     FMS_DW.home[2]);
                    FMS_B.href = 0.0;
                    FMS_B.psio = 0.0;
                    FMS_B.llo[0] = FMS_DW.llo[0];

                    /* Outputs for Function Call SubSystem: '<S3>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
                    /* Sum: '<S248>/Sum' */
                    rtb_Sum_idx_0 = FMS_B.lla[0] - FMS_B.llo[0];

                    /* End of Outputs for SubSystem: '<S3>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
                    FMS_B.llo[1] = FMS_DW.llo[1];

                    /* Outputs for Function Call SubSystem: '<S3>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
                    /* Gain: '<S248>/deg2rad' */
                    rtb_Multiply2 = 0.017453292519943295 * FMS_B.llo[0];

                    /* Trigonometry: '<S249>/Sin' */
                    rtb_Sum2_m = sin(rtb_Multiply2);

                    /* Math: '<S249>/Square1' */
                    rtb_Sum2_m *= rtb_Sum2_m;

                    /* Product: '<S249>/Multiply1' incorporates:
                     *  Product: '<S249>/Multiply'
                     */
                    rtb_Gain = FMS_ConstB.ff * rtb_Sum2_m;

                    /* Product: '<S249>/Divide' incorporates:
                     *  Constant: '<S249>/Constant'
                     *  Constant: '<S249>/R'
                     *  Sqrt: '<S249>/Sqrt'
                     *  Sum: '<S249>/Sum1'
                     */
                    rtb_Sum2_m = 6.378137E+6 / sqrt(1.0 - rtb_Gain);

                    /* Product: '<S249>/Product3' incorporates:
                     *  Constant: '<S249>/Constant1'
                     *  Product: '<S249>/Multiply1'
                     *  Sum: '<S249>/Sum2'
                     */
                    rtb_Gain = 1.0 / (1.0 - rtb_Gain) * FMS_ConstB.Sum4 *
                      rtb_Sum2_m;

                    /* Product: '<S249>/Multiply2' incorporates:
                     *  Trigonometry: '<S249>/Cos'
                     */
                    rtb_Sum2_m *= cos(rtb_Multiply2);

                    /* Abs: '<S253>/Abs' incorporates:
                     *  Abs: '<S256>/Abs1'
                     *  Switch: '<S253>/Switch1'
                     */
                    rtb_Multiply2 = fabs(rtb_Sum_idx_0);

                    /* Switch: '<S253>/Switch1' incorporates:
                     *  Abs: '<S253>/Abs'
                     *  Bias: '<S253>/Bias2'
                     *  Bias: '<S253>/Bias3'
                     *  Constant: '<S250>/Constant'
                     *  Constant: '<S250>/Constant1'
                     *  Constant: '<S255>/Constant'
                     *  Gain: '<S253>/Gain1'
                     *  Product: '<S253>/Multiply'
                     *  RelationalOperator: '<S255>/Compare'
                     *  Switch: '<S250>/Switch'
                     */
                    if (rtb_Multiply2 > 90.0) {
                      /* Switch: '<S256>/Switch1' incorporates:
                       *  Bias: '<S256>/Bias2'
                       *  Bias: '<S256>/Bias3'
                       *  Constant: '<S256>/Constant'
                       *  Constant: '<S257>/Constant'
                       *  Math: '<S256>/Math Function'
                       *  RelationalOperator: '<S257>/Compare'
                       */
                      if (rtb_Multiply2 > 180.0) {
                        rtb_Sum_idx_0 = rt_modd(rtb_Sum_idx_0 + 180.0, 360.0) +
                          -180.0;
                      }

                      /* End of Switch: '<S256>/Switch1' */

                      /* Signum: '<S253>/Sign' */
                      if (rtb_Sum_idx_0 < 0.0) {
                        rtb_Sum_idx_0 = -1.0;
                      } else {
                        if (rtb_Sum_idx_0 > 0.0) {
                          rtb_Sum_idx_0 = 1.0;
                        }
                      }

                      /* End of Signum: '<S253>/Sign' */
                      rtb_Multiply2 = (-(rtb_Multiply2 + -90.0) + 90.0) *
                        rtb_Sum_idx_0;
                      rtb_Compare_d_0 = 180;
                    } else {
                      rtb_Multiply2 = rtb_Sum_idx_0;
                      rtb_Compare_d_0 = 0;
                    }

                    /* Sum: '<S250>/Sum' incorporates:
                     *  Sum: '<S248>/Sum'
                     */
                    rtb_Sum_d = (FMS_B.lla[1] - FMS_B.llo[1]) + (real_T)
                      rtb_Compare_d_0;

                    /* Product: '<S248>/Multiply' incorporates:
                     *  Gain: '<S248>/deg2rad1'
                     */
                    rtb_Sum_idx_0 = 0.017453292519943295 * rtb_Multiply2 *
                      rtb_Gain;

                    /* Switch: '<S252>/Switch1' incorporates:
                     *  Abs: '<S252>/Abs1'
                     *  Bias: '<S252>/Bias2'
                     *  Bias: '<S252>/Bias3'
                     *  Constant: '<S252>/Constant'
                     *  Constant: '<S254>/Constant'
                     *  Math: '<S252>/Math Function'
                     *  RelationalOperator: '<S254>/Compare'
                     */
                    if (fabs(rtb_Sum_d) > 180.0) {
                      rtb_Sum_d = rt_modd(rtb_Sum_d + 180.0, 360.0) + -180.0;
                    }

                    /* End of Switch: '<S252>/Switch1' */

                    /* Product: '<S248>/Multiply' incorporates:
                     *  Gain: '<S248>/deg2rad1'
                     */
                    rtb_Multiply2 = 0.017453292519943295 * rtb_Sum_d *
                      rtb_Sum2_m;

                    /* Gain: '<S248>/deg2rad2' */
                    rtb_Sum2_m = 0.017453292519943295 * FMS_B.psio;

                    /* Trigonometry: '<S251>/SinCos' */
                    rtb_Sum_d = sin(rtb_Sum2_m);
                    rtb_Gain = cos(rtb_Sum2_m);

                    /* Sum: '<S251>/Sum2' incorporates:
                     *  Product: '<S251>/Multiply1'
                     *  Product: '<S251>/Multiply2'
                     */
                    rtb_Sum2_m = rtb_Sum_idx_0 * rtb_Gain + rtb_Multiply2 *
                      rtb_Sum_d;

                    /* Product: '<S251>/Multiply3' */
                    rtb_Sum_d *= rtb_Sum_idx_0;

                    /* Product: '<S251>/Multiply4' */
                    rtb_Gain *= rtb_Multiply2;

                    /* Sum: '<S251>/Sum3' */
                    rtb_Sum_d = rtb_Gain - rtb_Sum_d;

                    /* DataTypeConversion: '<S245>/Data Type Conversion' incorporates:
                     *  Gain: '<S248>/Gain'
                     *  Sum: '<S248>/Sum1'
                     */
                    FMS_B.DataTypeConversion[0] = (real32_T)rtb_Sum2_m;
                    FMS_B.DataTypeConversion[1] = (real32_T)rtb_Sum_d;
                    FMS_B.DataTypeConversion[2] = (real32_T)-(FMS_B.lla[2] +
                      FMS_B.href);

                    /* End of Outputs for SubSystem: '<S3>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
                    FMS_B.Cmd_In.sp_waypoint[0] = FMS_B.DataTypeConversion[0];
                    FMS_B.Cmd_In.sp_waypoint[1] = FMS_B.DataTypeConversion[1];
                    FMS_B.Cmd_In.sp_waypoint[2] = FMS_B.DataTypeConversion[2];
                    FMS_B.state = VehicleState_Mission;
                  } else {
                    FMS_DW.is_Mission = FMS_IN_Loiter;
                    FMS_B.state = VehicleState_Hold;
                  }
                  break;

                 case FMS_IN_Return_h:
                  tmp[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R -
                    FMS_B.Cmd_In.sp_return[0];
                  tmp[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R -
                    FMS_B.Cmd_In.sp_return[1];
                  if (FMS_norm(tmp) < 0.5F) {
                    FMS_DW.durationLastReferenceTick_1 =
                      FMS_DW.chartAbsoluteTimeCounter;
                    FMS_DW.is_Mission = FMS_IN_Land;
                    FMS_B.Cmd_In.sp_land[0] =
                      FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
                    FMS_B.Cmd_In.sp_land[1] =
                      FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
                    FMS_B.state = VehicleState_Land;

                    /* Constant: '<Root>/Constant' */
                    FMS_DW.condWasTrueAtLastTimeStep_1 = false;
                  }
                  break;

                 case FMS_IN_Takeoff_d:
                  if (FMS_B.BusConversion_InsertedFor_FMSSt.h_R >=
                      FMS_B.Cmd_In.sp_takeoff[2]) {
                    FMS_B.Cmd_In.cur_waypoint[0] = FMS_B.Cmd_In.sp_takeoff[0];
                    FMS_B.Cmd_In.cur_waypoint[1] = FMS_B.Cmd_In.sp_takeoff[1];
                    FMS_B.Cmd_In.cur_waypoint[2] = FMS_B.Cmd_In.sp_takeoff[2];
                    rtb_Compare_d_0 = (int32_T)(FMS_B.wp_index + 1U);
                    if ((uint32_T)rtb_Compare_d_0 > 255U) {
                      rtb_Compare_d_0 = 255;
                    }

                    FMS_B.wp_index = (uint8_T)rtb_Compare_d_0;
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
                    FMS_B.Cmd_In.cur_waypoint[0] = FMS_B.Cmd_In.sp_waypoint[0];
                    FMS_B.Cmd_In.cur_waypoint[1] = FMS_B.Cmd_In.sp_waypoint[1];
                    FMS_B.Cmd_In.cur_waypoint[2] = FMS_B.Cmd_In.sp_waypoint[2];
                    rtb_Compare_d_0 = (int32_T)(FMS_B.wp_index + 1U);
                    if ((uint32_T)rtb_Compare_d_0 > 255U) {
                      rtb_Compare_d_0 = 255;
                    }

                    FMS_B.wp_index = (uint8_T)rtb_Compare_d_0;
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
          FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_o;
          FMS_DW.is_Vehicle = FMS_IN_Disarm;
          FMS_B.state = VehicleState_Disarm;
          break;

         case FMS_IN_Manual:
          if (FMS_DW.is_Manual == FMS_IN_InValidManualMode) {
            FMS_DW.is_Manual = FMS_IN_NO_ACTIVE_CHILD_o;
            FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_o;
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
      FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD_o;
      break;

     case FMS_IN_Standby:
      FMS_DW.prep_takeoff = 0.0;
      sf_internal_predicateOutput = (FMS_DW.prep_takeoff == 1.0);
      if ((!sf_internal_predicateOutput) ||
          (!FMS_DW.condWasTrueAtLastTimeStep_1_k)) {
        FMS_DW.durationLastReferenceTick_1_k = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_1_k = sf_internal_predicateOutput;
      FMS_DW.prep_mission_takeoff = 0.0;
      sf_internal_predicateOutput = (FMS_DW.prep_mission_takeoff == 1.0);
      if ((!sf_internal_predicateOutput) || (!FMS_DW.condWasTrueAtLastTimeStep_2))
      {
        FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_2 = sf_internal_predicateOutput;
      FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD_o;
      break;

     default:
      FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD_o;
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
              (!FMS_DW.condWasTrueAtLastTimeStep_1_k)) {
            FMS_DW.durationLastReferenceTick_1_k =
              FMS_DW.chartAbsoluteTimeCounter;
          }

          FMS_DW.condWasTrueAtLastTimeStep_1_k = sf_internal_predicateOutput;
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
            (!FMS_DW.condWasTrueAtLastTimeStep_1_k)) {
          FMS_DW.durationLastReferenceTick_1_k = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1_k = sf_internal_predicateOutput;
        if (FMS_DW.chartAbsoluteTimeCounter -
            FMS_DW.durationLastReferenceTick_1_k >= 500) {
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
                (!FMS_DW.condWasTrueAtLastTimeStep_1_k)) {
              FMS_DW.durationLastReferenceTick_1_k =
                FMS_DW.chartAbsoluteTimeCounter;
            }

            FMS_DW.condWasTrueAtLastTimeStep_1_k = sf_internal_predicateOutput;
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
      /* Reshape: '<S246>/Reshape' incorporates:
       *  Constant: '<S246>/Constant'
       */
      FMS_B.Reshape[0] = FMS_B.xy_R[0];
      FMS_B.Reshape[1] = FMS_B.xy_R[1];
      FMS_B.Reshape[2] = FMS_PARAM.TAKEOFF_H;

      /* End of Outputs for SubSystem: '<S3>/Vehicle.PrepTakeoff' */
      FMS_B.Cmd_In.sp_takeoff[0] = FMS_B.Reshape[0];
      FMS_B.Cmd_In.sp_takeoff[1] = FMS_B.Reshape[1];
      FMS_B.Cmd_In.sp_takeoff[2] = FMS_B.Reshape[2];
      FMS_B.Cmd_In.sp_takeoff[2] += FMS_DW.home[2];
      FMS_DW.prep_takeoff = 0.0;
      sf_internal_predicateOutput = (FMS_DW.prep_takeoff == 1.0);
      if ((!sf_internal_predicateOutput) ||
          (!FMS_DW.condWasTrueAtLastTimeStep_1_k)) {
        FMS_DW.durationLastReferenceTick_1_k = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_1_k = sf_internal_predicateOutput;
      FMS_DW.prep_mission_takeoff = 0.0;
      sf_internal_predicateOutput = (FMS_DW.prep_mission_takeoff == 1.0);
      if ((!sf_internal_predicateOutput) || (!FMS_DW.condWasTrueAtLastTimeStep_2))
      {
        FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_2 = sf_internal_predicateOutput;
      FMS_DW.durationLastReferenceTick_1_c = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_Vehicle = FMS_IN_Arm;

      /* Constant: '<Root>/Constant' */
      FMS_DW.condWasTrueAtLastTimeStep_1_d0 = false;
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
          (!FMS_DW.condWasTrueAtLastTimeStep_1_k)) {
        FMS_DW.durationLastReferenceTick_1_k = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_1_k = sf_internal_predicateOutput;
      FMS_DW.prep_mission_takeoff = 0.0;
      sf_internal_predicateOutput = (FMS_DW.prep_mission_takeoff == 1.0);
      if ((!sf_internal_predicateOutput) || (!FMS_DW.condWasTrueAtLastTimeStep_2))
      {
        FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
      }

      FMS_DW.condWasTrueAtLastTimeStep_2 = sf_internal_predicateOutput;
      FMS_DW.durationLastReferenceTick_1_c = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_Vehicle = FMS_IN_Arm;

      /* Constant: '<Root>/Constant' */
      FMS_DW.condWasTrueAtLastTimeStep_1_d0 = false;
      FMS_enter_internal_Arm();
    }

    if (guard1) {
      FMS_DW.condWasTrueAtLastTimeStep_2 = false;
      FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.condWasTrueAtLastTimeStep_1_k = false;
      FMS_DW.durationLastReferenceTick_1_k = FMS_DW.chartAbsoluteTimeCounter;
      FMS_DW.is_Vehicle = FMS_IN_Standby;
      FMS_DW.temporalCounter_i1 = 0U;
      guard4 = false;
      if (FMS_B.target_mode == PilotMode_Mission) {
        if ((FMS_U.Mission_Data.valid_items > 0) &&
            (FMS_U.Mission_Data.command[FMS_B.wp_index - 1] == (int32_T)
             NAV_Cmd_Takeoff)) {
          FMS_DW.prep_mission_takeoff = 1.0;
          FMS_DW.condWasTrueAtLastTimeStep_2 = (FMS_DW.prep_mission_takeoff ==
            1.0);
          FMS_DW.prep_takeoff = 0.0;
          FMS_DW.condWasTrueAtLastTimeStep_1_k = (FMS_DW.prep_takeoff == 1.0);
          guard4 = true;
        } else {
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
      } else {
        guard4 = true;
      }

      if (guard4) {
        FMS_DW.home[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R;
        FMS_DW.home[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
        FMS_DW.home[2] = FMS_B.BusConversion_InsertedFor_FMSSt.h_R;
        FMS_B.state = VehicleState_Standby;
      }

      if (FMS_DW.is_Vehicle == FMS_IN_Standby) {
        sf_internal_predicateOutput = (FMS_DW.prep_takeoff == 1.0);
        if ((!sf_internal_predicateOutput) ||
            (!FMS_DW.condWasTrueAtLastTimeStep_1_k)) {
          FMS_DW.durationLastReferenceTick_1_k = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1_k = sf_internal_predicateOutput;
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
    FMS_DW.durationLastReferenceTick_2_a = FMS_DW.chartAbsoluteTimeCounter;
    FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
    FMS_DW.is_Combo_Stick = FMS_IN_Idle;
    FMS_DW.condWasTrueAtLastTimeStep_1_h = FMS_DW.br;
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
          FMS_DW.durationLastReferenceTick_2_a = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.is_Combo_Stick = FMS_IN_Idle;
          FMS_DW.condWasTrueAtLastTimeStep_1_h = FMS_DW.br;
          FMS_DW.condWasTrueAtLastTimeStep_2_g = FMS_DW.bl;
        }
        break;

       case FMS_IN_Disarm:
        if (!FMS_BottomLeft(FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
                            FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle))
        {
          FMS_DW.durationLastReferenceTick_2_a = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
          FMS_DW.is_Combo_Stick = FMS_IN_Idle;
          FMS_DW.condWasTrueAtLastTimeStep_1_h = FMS_DW.br;
          FMS_DW.condWasTrueAtLastTimeStep_2_g = FMS_DW.bl;
        }
        break;

       case FMS_IN_Idle:
        if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_h)) {
          FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
        }

        FMS_DW.condWasTrueAtLastTimeStep_1_h = FMS_DW.br;
        if (FMS_DW.chartAbsoluteTimeCounter -
            FMS_DW.durationLastReferenceTick_1_n > 375) {
          FMS_DW.is_Combo_Stick = FMS_IN_Arm;
          FMS_DW.M_msgReservedData = FMS_Cmd_PreArm;
          FMS_sf_msg_send_M();
        } else {
          if ((!FMS_DW.bl) || (!FMS_DW.condWasTrueAtLastTimeStep_2_g)) {
            FMS_DW.durationLastReferenceTick_2_a =
              FMS_DW.chartAbsoluteTimeCounter;
          }

          FMS_DW.condWasTrueAtLastTimeStep_2_g = FMS_DW.bl;
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
            if ((!FMS_DW.bl) || (!FMS_DW.condWasTrueAtLastTimeStep_2_g)) {
              FMS_DW.durationLastReferenceTick_2_a =
                FMS_DW.chartAbsoluteTimeCounter;
            }

            FMS_DW.condWasTrueAtLastTimeStep_2_g = FMS_DW.bl;
            FMS_DW.br = FMS_BottomRight
              (FMS_B.BusConversion_InsertedFor_FMS_f.stick_yaw,
               FMS_B.BusConversion_InsertedFor_FMS_f.stick_throttle);
            if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_h)) {
              FMS_DW.durationLastReferenceTick_1_n =
                FMS_DW.chartAbsoluteTimeCounter;
            }

            FMS_DW.condWasTrueAtLastTimeStep_1_h = FMS_DW.br;
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
                (Msg_FMS_Cmd *)&FMS_DW.Msg_FMS_Cmd_c[1]);
}

/* Model step function */
void FMS_step(void)
{
  real32_T A;
  real32_T B;
  real32_T D;
  int8_T rtPrevAction;
  uint16_T rtb_DataTypeConversion;
  uint16_T rtb_DataTypeConversion1_l;
  real32_T rtb_Saturation_l;
  real32_T rtb_VectorConcatenate_hm[9];
  real32_T rtb_Sqrt;
  MotionState rtb_state_a;
  real32_T rtb_Switch_l[3];
  real32_T rtb_Divide_f[2];
  real32_T rtb_Rem_k;
  real32_T rtb_Divide_fw[2];
  real32_T rtb_Rem_o;
  boolean_T rtb_Compare_i;
  MotionState rtb_state;
  real32_T rtb_Add3;
  real32_T rtb_MathFunction1;
  real32_T rtb_MathFunction_aq[3];
  int32_T i;
  real32_T rtb_VectorConcatenate_a[3];
  boolean_T u;
  real32_T rtb_Subtract3_idx_1;
  real32_T rtb_Subtract3_idx_0;
  real32_T rtb_a_idx_1;
  real32_T rtb_Sign1_n_idx_0;
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
  rtb_MathFunction1 = (real32_T)FMS_DW.DiscreteTimeIntegrator1_DSTATE +
    (real32_T)FMS_EXPORT.period;
  if (rtb_MathFunction1 < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = (uint32_T)rtb_MathFunction1;
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
   *  Constant: '<Root>/Constant'
   *  Inport: '<Root>/Mission_Data'
   */
  FMS_DW.chartAbsoluteTimeCounter++;
  FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
  FMS_DW.condWasTrueAtLastTimeStep_1 = false;
  FMS_DW.durationLastReferenceTick_1_j = FMS_DW.chartAbsoluteTimeCounter;
  FMS_DW.condWasTrueAtLastTimeStep_1_d = false;
  rtb_Compare_i = (FMS_DW.prep_takeoff == 1.0);
  if ((!rtb_Compare_i) || (!FMS_DW.condWasTrueAtLastTimeStep_1_k)) {
    FMS_DW.durationLastReferenceTick_1_k = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_k = rtb_Compare_i;
  rtb_Compare_i = (FMS_DW.prep_mission_takeoff == 1.0);
  if ((!rtb_Compare_i) || (!FMS_DW.condWasTrueAtLastTimeStep_2)) {
    FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_2 = rtb_Compare_i;
  FMS_DW.durationLastReferenceTick_1_c = FMS_DW.chartAbsoluteTimeCounter;
  FMS_DW.condWasTrueAtLastTimeStep_1_d0 = false;
  if ((!FMS_DW.br) || (!FMS_DW.condWasTrueAtLastTimeStep_1_h)) {
    FMS_DW.durationLastReferenceTick_1_n = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_h = FMS_DW.br;
  if ((!FMS_DW.bl) || (!FMS_DW.condWasTrueAtLastTimeStep_2_g)) {
    FMS_DW.durationLastReferenceTick_2_a = FMS_DW.chartAbsoluteTimeCounter;
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
  /* SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1' */
  rtb_Divide_fw[0] = FMS_B.Cmd_In.sp_return[0];
  rtb_Divide_fw[1] = FMS_B.Cmd_In.sp_return[1];
  rtb_MathFunction_aq[0] = FMS_B.Cmd_In.sp_waypoint[0];
  rtb_MathFunction_aq[1] = FMS_B.Cmd_In.sp_waypoint[1];
  rtb_MathFunction_aq[2] = FMS_B.Cmd_In.sp_waypoint[2];

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
      if (FMS_DW.SwitchCase_ActiveSubsystem_a == 2) {
        /* Disable for SwitchCase: '<S205>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

        /* Disable for SwitchCase: '<S195>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
      }

      FMS_DW.SwitchCase_ActiveSubsystem_a = -1;
      break;

     case 1:
      /* Disable for SwitchCase: '<S22>/Switch Case' */
      FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
      break;

     case 2:
      /* Disable for SwitchCase: '<S21>/Switch Case' */
      switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
       case 0:
       case 1:
       case 4:
        break;

       case 2:
        /* Disable for SwitchCase: '<S37>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_m = -1;
        break;

       case 3:
        /* Disable for SwitchCase: '<S72>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

        /* Disable for SwitchCase: '<S58>/Switch Case' */
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
      rtb_MathFunction1 = fmodf(floorf(FMS_PARAM.DISARM_OUT[i]), 65536.0F);
      FMS_Y.FMS_Out.actuator_cmd[i] = (uint16_T)(rtb_MathFunction1 < 0.0F ?
        (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_MathFunction1 : (int32_T)
        (uint16_T)rtb_MathFunction1);
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
      rtb_MathFunction1 = fmodf(floorf(FMS_PARAM.STANDBY_OUT[i]), 65536.0F);
      FMS_Y.FMS_Out.actuator_cmd[i] = (uint16_T)(rtb_MathFunction1 < 0.0F ?
        (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_MathFunction1 : (int32_T)
        (uint16_T)rtb_MathFunction1);
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
        if (FMS_DW.SwitchCase_ActiveSubsystem_a == 2) {
          /* Disable for SwitchCase: '<S205>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

          /* Disable for SwitchCase: '<S195>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
        }

        FMS_DW.SwitchCase_ActiveSubsystem_a = -1;
        break;

       case 1:
        /* Disable for SwitchCase: '<S22>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_i = -1;
        break;

       case 2:
        /* Disable for SwitchCase: '<S21>/Switch Case' */
        switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
         case 0:
         case 1:
         case 4:
          break;

         case 2:
          /* Disable for SwitchCase: '<S37>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_m = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S72>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S58>/Switch Case' */
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
      /* Outputs for IfAction SubSystem: '<S17>/SubMode' incorporates:
       *  ActionPort: '<S24>/Action Port'
       */
      /* SwitchCase: '<S24>/Switch Case' incorporates:
       *  Math: '<S159>/Math Function'
       *  Math: '<S227>/Math Function'
       *  Product: '<S229>/Divide'
       *  Sum: '<S150>/Subtract'
       *  Sum: '<S190>/Subtract'
       *  Switch: '<S149>/Switch'
       */
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
      if ((rtPrevAction != FMS_DW.SwitchCase_ActiveSubsystem_a) && (rtPrevAction
           == 2)) {
        /* Disable for SwitchCase: '<S205>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

        /* Disable for SwitchCase: '<S195>/Switch Case' */
        FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_a) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S24>/Takeoff' incorporates:
         *  ActionPort: '<S144>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S242>/Sum2' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S236>/Sum'
         */
        rtb_Sqrt = FMS_U.INS_Out.h_R - FMS_B.Cmd_In.cur_waypoint[2];

        /* Product: '<S242>/Divide' incorporates:
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S242>/Sum1'
         *  Sum: '<S242>/Sum2'
         */
        rtb_Saturation_l = 1.0F / (FMS_B.Cmd_In.sp_takeoff[2] -
          FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Sqrt;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Saturate: '<S242>/Saturation' */
        if (rtb_Saturation_l > 1.0F) {
          rtb_Saturation_l = 1.0F;
        } else {
          if (rtb_Saturation_l < 0.0F) {
            rtb_Saturation_l = 0.0F;
          }
        }

        /* End of Saturate: '<S242>/Saturation' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Trigonometry: '<S243>/Trigonometric Function1' incorporates:
         *  Gain: '<S241>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  Trigonometry: '<S243>/Trigonometric Function3'
         */
        rtb_Subtract3_idx_0 = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_VectorConcatenate_hm[0] = rtb_Subtract3_idx_0;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Trigonometry: '<S243>/Trigonometric Function' incorporates:
         *  Gain: '<S241>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  Trigonometry: '<S243>/Trigonometric Function2'
         */
        rtb_MathFunction1 = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_VectorConcatenate_hm[1] = rtb_MathFunction1;

        /* SignalConversion: '<S243>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S243>/Constant3'
         */
        rtb_VectorConcatenate_hm[2] = 0.0F;

        /* Gain: '<S243>/Gain' */
        rtb_VectorConcatenate_hm[3] = -rtb_MathFunction1;

        /* Trigonometry: '<S243>/Trigonometric Function3' */
        rtb_VectorConcatenate_hm[4] = rtb_Subtract3_idx_0;

        /* SignalConversion: '<S243>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S243>/Constant4'
         */
        rtb_VectorConcatenate_hm[5] = 0.0F;

        /* SignalConversion: '<S243>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_VectorConcatenate_hm[6] = FMS_ConstB.VectorConcatenate3_fb[0];
        rtb_VectorConcatenate_hm[7] = FMS_ConstB.VectorConcatenate3_fb[1];
        rtb_VectorConcatenate_hm[8] = FMS_ConstB.VectorConcatenate3_fb[2];

        /* Saturate: '<S237>/Saturation1' */
        rtb_Subtract3_idx_1 = FMS_PARAM.VEL_XY_LIM / 5.0F;
        rtb_Add3 = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* SignalConversion: '<S237>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S242>/Multiply'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S237>/Sum'
         *  Sum: '<S242>/Sum3'
         *  Sum: '<S242>/Sum4'
         */
        rtb_Subtract3_idx_0 = ((FMS_B.Cmd_In.sp_takeoff[0] -
          FMS_B.Cmd_In.cur_waypoint[0]) * rtb_Saturation_l +
          FMS_B.Cmd_In.cur_waypoint[0]) - FMS_U.INS_Out.x_R;
        rtb_MathFunction1 = ((FMS_B.Cmd_In.sp_takeoff[1] -
                              FMS_B.Cmd_In.cur_waypoint[1]) * rtb_Saturation_l +
                             FMS_B.Cmd_In.cur_waypoint[1]) - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Product: '<S237>/Multiply' */
        for (i = 0; i < 3; i++) {
          rtb_VectorConcatenate_a[i] = rtb_VectorConcatenate_hm[i + 3] *
            rtb_MathFunction1 + rtb_VectorConcatenate_hm[i] *
            rtb_Subtract3_idx_0;
        }

        /* Saturate: '<S237>/Saturation1' incorporates:
         *  Gain: '<S237>/Gain2'
         *  Product: '<S237>/Multiply'
         */
        rtb_Subtract3_idx_0 = FMS_PARAM.XY_P * rtb_VectorConcatenate_a[0];
        rtb_MathFunction1 = FMS_PARAM.XY_P * rtb_VectorConcatenate_a[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S144>/Bus Assignment1'
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S144>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S144>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S144>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ld;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_dh;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_d;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S237>/Saturation1' */
        if (rtb_Subtract3_idx_0 > rtb_Subtract3_idx_1) {
          /* BusAssignment: '<S144>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Subtract3_idx_1;
        } else if (rtb_Subtract3_idx_0 < rtb_Add3) {
          /* BusAssignment: '<S144>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Add3;
        } else {
          /* BusAssignment: '<S144>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Subtract3_idx_0;
        }

        if (rtb_MathFunction1 > rtb_Subtract3_idx_1) {
          /* BusAssignment: '<S144>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Subtract3_idx_1;
        } else if (rtb_MathFunction1 < rtb_Add3) {
          /* BusAssignment: '<S144>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Add3;
        } else {
          /* BusAssignment: '<S144>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_MathFunction1;
        }

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Switch: '<S236>/Switch' incorporates:
         *  Abs: '<S236>/Abs'
         *  Abs: '<S236>/Abs1'
         *  Constant: '<S238>/Constant'
         *  Constant: '<S239>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Logic: '<S236>/Logical Operator'
         *  RelationalOperator: '<S238>/Compare'
         *  RelationalOperator: '<S239>/Compare'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S236>/Sum1'
         */
        if ((fabsf(FMS_B.Cmd_In.sp_takeoff[2] - FMS_U.INS_Out.h_R) > 2.0F) &&
            (fabsf(rtb_Sqrt) > 2.0F)) {
          /* BusAssignment: '<S144>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Constant: '<S236>/Constant6'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -1.0F;
        } else {
          /* BusAssignment: '<S144>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Constant: '<S236>/Constant4'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -0.5F;
        }

        /* End of Switch: '<S236>/Switch' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S24>/Takeoff' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S24>/Land' incorporates:
         *  ActionPort: '<S142>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Trigonometry: '<S168>/Trigonometric Function1' incorporates:
         *  Gain: '<S167>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_VectorConcatenate_hm[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S168>/Trigonometric Function' incorporates:
         *  Gain: '<S167>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_VectorConcatenate_hm[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* SignalConversion: '<S168>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S168>/Constant3'
         */
        rtb_VectorConcatenate_hm[2] = 0.0F;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Gain: '<S168>/Gain' incorporates:
         *  Gain: '<S167>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  Trigonometry: '<S168>/Trigonometric Function2'
         */
        rtb_VectorConcatenate_hm[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S168>/Trigonometric Function3' incorporates:
         *  Gain: '<S167>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_VectorConcatenate_hm[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* SignalConversion: '<S168>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S168>/Constant4'
         */
        rtb_VectorConcatenate_hm[5] = 0.0F;

        /* SignalConversion: '<S168>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_VectorConcatenate_hm[6] = FMS_ConstB.VectorConcatenate3_f[0];
        rtb_VectorConcatenate_hm[7] = FMS_ConstB.VectorConcatenate3_f[1];
        rtb_VectorConcatenate_hm[8] = FMS_ConstB.VectorConcatenate3_f[2];

        /* Saturate: '<S164>/Saturation1' */
        rtb_Subtract3_idx_1 = FMS_PARAM.VEL_XY_LIM / 5.0F;
        rtb_Saturation_l = -FMS_PARAM.VEL_XY_LIM / 5.0F;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* SignalConversion: '<S165>/TmpSignal ConversionAtMultiplyInport2' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S165>/Sum'
         */
        rtb_Subtract3_idx_0 = FMS_B.Cmd_In.sp_land[0] - FMS_U.INS_Out.x_R;
        rtb_MathFunction1 = FMS_B.Cmd_In.sp_land[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Product: '<S165>/Multiply' */
        for (i = 0; i < 3; i++) {
          rtb_VectorConcatenate_a[i] = rtb_VectorConcatenate_hm[i + 3] *
            rtb_MathFunction1 + rtb_VectorConcatenate_hm[i] *
            rtb_Subtract3_idx_0;
        }

        /* Saturate: '<S164>/Saturation1' incorporates:
         *  Gain: '<S165>/Gain2'
         *  Product: '<S165>/Multiply'
         */
        rtb_Subtract3_idx_0 = FMS_PARAM.XY_P * rtb_VectorConcatenate_a[0];
        rtb_MathFunction1 = FMS_PARAM.XY_P * rtb_VectorConcatenate_a[1];

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S142>/Bus Assignment1'
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S142>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S142>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S142>/Constant'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_c;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_h;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_ml;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;

        /* Saturate: '<S164>/Saturation1' */
        if (rtb_Subtract3_idx_0 > rtb_Subtract3_idx_1) {
          /* BusAssignment: '<S142>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Subtract3_idx_1;
        } else if (rtb_Subtract3_idx_0 < rtb_Saturation_l) {
          /* BusAssignment: '<S142>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Saturation_l;
        } else {
          /* BusAssignment: '<S142>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.u_cmd = rtb_Subtract3_idx_0;
        }

        if (rtb_MathFunction1 > rtb_Subtract3_idx_1) {
          /* BusAssignment: '<S142>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Subtract3_idx_1;
        } else if (rtb_MathFunction1 < rtb_Saturation_l) {
          /* BusAssignment: '<S142>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_Saturation_l;
        } else {
          /* BusAssignment: '<S142>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.v_cmd = rtb_MathFunction1;
        }

        /* BusAssignment: '<S142>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S142>/Constant4'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.w_cmd = 0.5F;

        /* End of Outputs for SubSystem: '<S24>/Land' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S24>/Return' incorporates:
           *  ActionPort: '<S143>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S24>/Switch Case' incorporates:
           *  Delay: '<S171>/Delay'
           *  Delay: '<S172>/Delay'
           *  Delay: '<S191>/Delay'
           *  DiscreteIntegrator: '<S175>/Integrator'
           *  DiscreteIntegrator: '<S175>/Integrator1'
           *  DiscreteIntegrator: '<S232>/Discrete-Time Integrator'
           */
          FMS_DW.icLoad_o = 1U;
          FMS_DW.l1_heading = 0.0F;
          FMS_DW.icLoad_cg = 1U;
          FMS_DW.icLoad_j = 1U;
          FMS_DW.Integrator1_IC_LOADING = 1U;
          FMS_DW.Integrator_DSTATE = 0.0F;

          /* End of InitializeConditions for SubSystem: '<S24>/Return' */

          /* SystemReset for IfAction SubSystem: '<S24>/Return' incorporates:
           *  ActionPort: '<S143>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S24>/Switch Case' incorporates:
           *  Chart: '<S196>/Motion Status'
           *  Chart: '<S206>/Motion State'
           */
          FMS_DW.temporalCounter_i1_j = 0U;
          FMS_DW.is_active_c2_FMS = 0U;
          FMS_DW.is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_o;
          FMS_DW.temporalCounter_i1_a = 0U;
          FMS_DW.is_active_c1_FMS = 0U;
          FMS_DW.is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD_o;

          /* End of SystemReset for SubSystem: '<S24>/Return' */
        }

        /* Outputs for IfAction SubSystem: '<S24>/Return' incorporates:
         *  ActionPort: '<S143>/Action Port'
         */
        /* Delay: '<S191>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        if (FMS_DW.icLoad_o != 0) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_DW.Delay_DSTATE_e[0] = FMS_U.INS_Out.x_R;
          FMS_DW.Delay_DSTATE_e[1] = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S187>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S192>/Square'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Saturation_l = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.sp_return[0];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_Divide_f[0] = rtb_Saturation_l * rtb_Saturation_l;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        rtb_Saturation_l = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.sp_return[1];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Math: '<S192>/Square' */
        rtb_Saturation_l *= rtb_Saturation_l;

        /* Sqrt: '<S192>/Sqrt' incorporates:
         *  Sum: '<S192>/Sum of Elements'
         */
        rtb_Sqrt = sqrtf(rtb_Divide_f[0] + rtb_Saturation_l);

        /* Switch: '<S187>/Switch' incorporates:
         *  Constant: '<S187>/vel'
         */
        if (rtb_Sqrt > FMS_PARAM.L1) {
          rtb_Sqrt = FMS_PARAM.CRUISE_SPEED;
        } else {
          /* Gain: '<S187>/Gain' */
          rtb_Sqrt *= 0.5F;

          /* Saturate: '<S187>/Saturation' */
          if (rtb_Sqrt > FMS_PARAM.CRUISE_SPEED) {
            rtb_Sqrt = FMS_PARAM.CRUISE_SPEED;
          } else {
            if (rtb_Sqrt < 0.5F) {
              rtb_Sqrt = 0.5F;
            }
          }

          /* End of Saturate: '<S187>/Saturation' */
        }

        /* End of Switch: '<S187>/Switch' */

        /* Chart: '<S206>/Motion State' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S206>/Square'
         *  Math: '<S206>/Square1'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  Sqrt: '<S206>/Sqrt'
         *  Sum: '<S206>/Add'
         */
        if (FMS_DW.temporalCounter_i1_j < 1023U) {
          FMS_DW.temporalCounter_i1_j++;
        }

        if (FMS_DW.is_active_c2_FMS == 0U) {
          FMS_DW.is_active_c2_FMS = 1U;
          FMS_DW.is_c2_FMS = FMS_IN_Move_j;
          rtb_state_a = MotionState_Move;
        } else {
          switch (FMS_DW.is_c2_FMS) {
           case FMS_IN_Brake_o:
            rtb_state_a = MotionState_Brake;

            /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
            if ((sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
                       FMS_U.INS_Out.ve) <= 0.2) || (FMS_DW.temporalCounter_i1_j
                 >= 625U)) {
              FMS_DW.is_c2_FMS = FMS_IN_Hold_h;
              rtb_state_a = MotionState_Hold;
            }

            /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
            break;

           case FMS_IN_Hold_h:
            rtb_state_a = MotionState_Hold;
            break;

           default:
            FMS_DW.is_c2_FMS = FMS_IN_Brake_o;
            FMS_DW.temporalCounter_i1_j = 0U;
            rtb_state_a = MotionState_Brake;
            break;
          }
        }

        /* End of Chart: '<S206>/Motion State' */

        /* SwitchCase: '<S205>/Switch Case' */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_k;
        FMS_DW.SwitchCase_ActiveSubsystem_k = -1;
        switch (rtb_state_a) {
         case MotionState_Hold:
          FMS_DW.SwitchCase_ActiveSubsystem_k = 0;
          break;

         case MotionState_Brake:
          FMS_DW.SwitchCase_ActiveSubsystem_k = 1;
          break;

         case MotionState_Move:
          FMS_DW.SwitchCase_ActiveSubsystem_k = 2;
          break;
        }

        switch (FMS_DW.SwitchCase_ActiveSubsystem_k) {
         case 0:
          if (FMS_DW.SwitchCase_ActiveSubsystem_k != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S205>/Hold Control' incorporates:
             *  ActionPort: '<S208>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S205>/Switch Case' incorporates:
             *  Delay: '<S208>/Delay'
             */
            FMS_DW.icLoad_i = 1U;

            /* End of InitializeConditions for SubSystem: '<S205>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S205>/Hold Control' incorporates:
           *  ActionPort: '<S208>/Action Port'
           */
          /* Delay: '<S208>/Delay' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          if (FMS_DW.icLoad_i != 0) {
            /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
            FMS_DW.Delay_DSTATE_n[0] = FMS_U.INS_Out.x_R;
            FMS_DW.Delay_DSTATE_n[1] = FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          }

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Trigonometry: '<S212>/Trigonometric Function1' incorporates:
           *  Gain: '<S211>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          rtb_VectorConcatenate_hm[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S212>/Trigonometric Function' incorporates:
           *  Gain: '<S211>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          rtb_VectorConcatenate_hm[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* SignalConversion: '<S212>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S212>/Constant3'
           */
          rtb_VectorConcatenate_hm[2] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Gain: '<S212>/Gain' incorporates:
           *  Gain: '<S211>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           *  Trigonometry: '<S212>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_hm[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

          /* Trigonometry: '<S212>/Trigonometric Function3' incorporates:
           *  Gain: '<S211>/Gain'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          rtb_VectorConcatenate_hm[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* SignalConversion: '<S212>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S212>/Constant4'
           */
          rtb_VectorConcatenate_hm[5] = 0.0F;

          /* SignalConversion: '<S212>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_hm[6] = FMS_ConstB.VectorConcatenate3_g[0];
          rtb_VectorConcatenate_hm[7] = FMS_ConstB.VectorConcatenate3_g[1];
          rtb_VectorConcatenate_hm[8] = FMS_ConstB.VectorConcatenate3_g[2];

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* SignalConversion: '<S208>/TmpSignal ConversionAtMultiplyInport2' incorporates:
           *  Delay: '<S208>/Delay'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           *  Sum: '<S208>/Sum'
           */
          rtb_Subtract3_idx_0 = FMS_DW.Delay_DSTATE_n[0] - FMS_U.INS_Out.x_R;
          rtb_MathFunction1 = FMS_DW.Delay_DSTATE_n[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Product: '<S208>/Multiply' incorporates:
           *  SignalConversion: '<S208>/TmpSignal ConversionAtMultiplyInport2'
           */
          for (i = 0; i < 3; i++) {
            rtb_VectorConcatenate_a[i] = rtb_VectorConcatenate_hm[i + 3] *
              rtb_MathFunction1 + rtb_VectorConcatenate_hm[i] *
              rtb_Subtract3_idx_0;
          }

          /* End of Product: '<S208>/Multiply' */

          /* Gain: '<S208>/Gain2' */
          FMS_B.Merge_m[0] = FMS_PARAM.XY_P * rtb_VectorConcatenate_a[0];
          FMS_B.Merge_m[1] = FMS_PARAM.XY_P * rtb_VectorConcatenate_a[1];

          /* Update for Delay: '<S208>/Delay' */
          FMS_DW.icLoad_i = 0U;

          /* End of Outputs for SubSystem: '<S205>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S205>/Brake Control' incorporates:
           *  ActionPort: '<S207>/Action Port'
           */
          /* SignalConversion: '<S207>/OutportBuffer_InsertedFor_uv_cmd_mPs_at_inport_0' */
          FMS_B.Merge_m[0] = 0.0F;
          FMS_B.Merge_m[1] = 0.0F;

          /* End of Outputs for SubSystem: '<S205>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_k != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S205>/Move Control' incorporates:
             *  ActionPort: '<S209>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S205>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S215>/Integrator'
             *  DiscreteIntegrator: '<S215>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_p[0] = 0.0F;
            FMS_DW.Integrator_DSTATE_p[0] = 0.0F;
            FMS_DW.Integrator1_DSTATE_p[1] = 0.0F;
            FMS_DW.Integrator_DSTATE_p[1] = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S205>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S205>/Move Control' incorporates:
           *  ActionPort: '<S209>/Action Port'
           */
          /* SignalConversion: '<S209>/OutportBufferForuv_cmd_mPs' incorporates:
           *  DiscreteIntegrator: '<S215>/Integrator1'
           */
          FMS_B.Merge_m[0] = FMS_DW.Integrator1_DSTATE_p[0];

          /* Product: '<S216>/Multiply1' incorporates:
           *  Constant: '<S216>/const1'
           *  DiscreteIntegrator: '<S215>/Integrator'
           */
          rtb_Divide_f[0] = FMS_DW.Integrator_DSTATE_p[0] * 0.05F;

          /* SignalConversion: '<S209>/OutportBufferForuv_cmd_mPs' incorporates:
           *  DiscreteIntegrator: '<S215>/Integrator1'
           */
          FMS_B.Merge_m[1] = FMS_DW.Integrator1_DSTATE_p[1];

          /* Product: '<S216>/Multiply1' incorporates:
           *  Constant: '<S216>/const1'
           *  DiscreteIntegrator: '<S215>/Integrator'
           */
          rtb_Divide_f[1] = FMS_DW.Integrator_DSTATE_p[1] * 0.05F;

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* DeadZone: '<S213>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S16>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
            rtb_MathFunction1 = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
            rtb_MathFunction1 = 0.0F;
          } else {
            rtb_MathFunction1 = FMS_U.Pilot_Cmd.stick_pitch -
              (-FMS_PARAM.PITCH_DZ);
          }

          /* End of DeadZone: '<S213>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Sum: '<S216>/Add' incorporates:
           *  DiscreteIntegrator: '<S215>/Integrator1'
           *  Gain: '<S209>/Gain6'
           *  Gain: '<S213>/Gain'
           *  Sum: '<S215>/Subtract'
           */
          rtb_Subtract3_idx_0 = (FMS_DW.Integrator1_DSTATE_p[0] - 1.0F / (1.0F -
            FMS_PARAM.PITCH_DZ) * rtb_MathFunction1 * FMS_PARAM.VEL_XY_LIM) +
            rtb_Divide_f[0];

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* DeadZone: '<S214>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S16>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            rtb_MathFunction1 = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            rtb_MathFunction1 = 0.0F;
          } else {
            rtb_MathFunction1 = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
          }

          /* End of DeadZone: '<S214>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Sum: '<S216>/Add' incorporates:
           *  DiscreteIntegrator: '<S215>/Integrator1'
           *  Gain: '<S209>/Gain6'
           *  Gain: '<S214>/Gain'
           *  Sum: '<S215>/Subtract'
           */
          rtb_Subtract3_idx_1 = (FMS_DW.Integrator1_DSTATE_p[1] - 1.0F / (1.0F -
            FMS_PARAM.ROLL_DZ) * rtb_MathFunction1 * FMS_PARAM.VEL_XY_LIM) +
            rtb_Divide_f[1];

          /* Signum: '<S216>/Sign' */
          if (rtb_Subtract3_idx_0 < 0.0F) {
            rtb_Add3 = -1.0F;
          } else if (rtb_Subtract3_idx_0 > 0.0F) {
            rtb_Add3 = 1.0F;
          } else {
            rtb_Add3 = rtb_Subtract3_idx_0;
          }

          /* Sum: '<S216>/Add2' incorporates:
           *  Abs: '<S216>/Abs'
           *  Gain: '<S216>/Gain'
           *  Gain: '<S216>/Gain1'
           *  Product: '<S216>/Multiply2'
           *  Product: '<S216>/Multiply3'
           *  Signum: '<S216>/Sign'
           *  Sqrt: '<S216>/Sqrt'
           *  Sum: '<S216>/Add1'
           *  Sum: '<S216>/Subtract'
           */
          rtb_Add3 = (sqrtf((8.0F * fabsf(rtb_Subtract3_idx_0) + FMS_ConstB.d_n)
                            * FMS_ConstB.d_n) - FMS_ConstB.d_n) * 0.5F *
            rtb_Add3 + rtb_Divide_f[0];

          /* Sum: '<S216>/Add3' incorporates:
           *  Signum: '<S216>/Sign'
           */
          rtb_MathFunction1 = rtb_Subtract3_idx_0 + FMS_ConstB.d_n;

          /* Sum: '<S216>/Subtract1' incorporates:
           *  Signum: '<S216>/Sign'
           */
          rtb_Saturation_l = rtb_Subtract3_idx_0 - FMS_ConstB.d_n;

          /* Signum: '<S216>/Sign1' */
          if (rtb_MathFunction1 < 0.0F) {
            rtb_MathFunction1 = -1.0F;
          } else {
            if (rtb_MathFunction1 > 0.0F) {
              rtb_MathFunction1 = 1.0F;
            }
          }

          /* Signum: '<S216>/Sign2' */
          if (rtb_Saturation_l < 0.0F) {
            rtb_Saturation_l = -1.0F;
          } else {
            if (rtb_Saturation_l > 0.0F) {
              rtb_Saturation_l = 1.0F;
            }
          }

          /* Sum: '<S216>/Add5' incorporates:
           *  Gain: '<S216>/Gain2'
           *  Product: '<S216>/Multiply4'
           *  Signum: '<S216>/Sign'
           *  Sum: '<S216>/Add2'
           *  Sum: '<S216>/Add4'
           *  Sum: '<S216>/Subtract2'
           */
          rtb_Add3 += ((rtb_Subtract3_idx_0 - rtb_Add3) + rtb_Divide_f[0]) *
            ((rtb_MathFunction1 - rtb_Saturation_l) * 0.5F);

          /* Update for DiscreteIntegrator: '<S215>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S215>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_p[0] += 0.004F * FMS_DW.Integrator_DSTATE_p
            [0];

          /* Signum: '<S216>/Sign4' incorporates:
           *  Sum: '<S216>/Subtract3'
           */
          rtb_MathFunction1 = rtb_Add3 - FMS_ConstB.d_n;

          /* Signum: '<S216>/Sign3' incorporates:
           *  Sum: '<S216>/Add6'
           */
          B = rtb_Add3 + FMS_ConstB.d_n;

          /* Signum: '<S216>/Sign5' */
          if (rtb_Add3 < 0.0F) {
            rtb_Subtract3_idx_0 = -1.0F;
          } else if (rtb_Add3 > 0.0F) {
            rtb_Subtract3_idx_0 = 1.0F;
          } else {
            rtb_Subtract3_idx_0 = rtb_Add3;
          }

          /* Signum: '<S216>/Sign3' */
          if (B < 0.0F) {
            B = -1.0F;
          } else {
            if (B > 0.0F) {
              B = 1.0F;
            }
          }

          /* Signum: '<S216>/Sign4' */
          if (rtb_MathFunction1 < 0.0F) {
            rtb_MathFunction1 = -1.0F;
          } else {
            if (rtb_MathFunction1 > 0.0F) {
              rtb_MathFunction1 = 1.0F;
            }
          }

          /* Signum: '<S216>/Sign6' */
          if (rtb_Add3 < 0.0F) {
            rtb_Saturation_l = -1.0F;
          } else if (rtb_Add3 > 0.0F) {
            rtb_Saturation_l = 1.0F;
          } else {
            rtb_Saturation_l = rtb_Add3;
          }

          /* Update for DiscreteIntegrator: '<S215>/Integrator' incorporates:
           *  Constant: '<S216>/const'
           *  Gain: '<S216>/Gain3'
           *  Product: '<S216>/Divide'
           *  Product: '<S216>/Multiply5'
           *  Product: '<S216>/Multiply6'
           *  Sum: '<S216>/Subtract4'
           *  Sum: '<S216>/Subtract5'
           *  Sum: '<S216>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_p[0] += ((rtb_Add3 / FMS_ConstB.d_n -
            rtb_Subtract3_idx_0) * FMS_ConstB.Gain4_a * ((B - rtb_MathFunction1)
            * 0.5F) - rtb_Saturation_l * 58.836F) * 0.004F;

          /* Signum: '<S216>/Sign' */
          if (rtb_Subtract3_idx_1 < 0.0F) {
            rtb_Subtract3_idx_0 = -1.0F;
          } else if (rtb_Subtract3_idx_1 > 0.0F) {
            rtb_Subtract3_idx_0 = 1.0F;
          } else {
            rtb_Subtract3_idx_0 = rtb_Subtract3_idx_1;
          }

          /* Sum: '<S216>/Add2' incorporates:
           *  Abs: '<S216>/Abs'
           *  Gain: '<S216>/Gain'
           *  Gain: '<S216>/Gain1'
           *  Product: '<S216>/Multiply2'
           *  Product: '<S216>/Multiply3'
           *  Signum: '<S216>/Sign'
           *  Sqrt: '<S216>/Sqrt'
           *  Sum: '<S216>/Add1'
           *  Sum: '<S216>/Subtract'
           */
          rtb_Add3 = (sqrtf((8.0F * fabsf(rtb_Subtract3_idx_1) + FMS_ConstB.d_n)
                            * FMS_ConstB.d_n) - FMS_ConstB.d_n) * 0.5F *
            rtb_Subtract3_idx_0 + rtb_Divide_f[1];

          /* Sum: '<S216>/Add3' incorporates:
           *  Signum: '<S216>/Sign'
           */
          rtb_MathFunction1 = rtb_Subtract3_idx_1 + FMS_ConstB.d_n;

          /* Sum: '<S216>/Subtract1' incorporates:
           *  Signum: '<S216>/Sign'
           */
          rtb_Saturation_l = rtb_Subtract3_idx_1 - FMS_ConstB.d_n;

          /* Signum: '<S216>/Sign1' */
          if (rtb_MathFunction1 < 0.0F) {
            rtb_MathFunction1 = -1.0F;
          } else {
            if (rtb_MathFunction1 > 0.0F) {
              rtb_MathFunction1 = 1.0F;
            }
          }

          /* Signum: '<S216>/Sign2' */
          if (rtb_Saturation_l < 0.0F) {
            rtb_Saturation_l = -1.0F;
          } else {
            if (rtb_Saturation_l > 0.0F) {
              rtb_Saturation_l = 1.0F;
            }
          }

          /* Sum: '<S216>/Add5' incorporates:
           *  Gain: '<S216>/Gain2'
           *  Product: '<S216>/Multiply4'
           *  Signum: '<S216>/Sign'
           *  Sum: '<S216>/Add2'
           *  Sum: '<S216>/Add4'
           *  Sum: '<S216>/Subtract2'
           */
          rtb_Add3 += ((rtb_Subtract3_idx_1 - rtb_Add3) + rtb_Divide_f[1]) *
            ((rtb_MathFunction1 - rtb_Saturation_l) * 0.5F);

          /* Update for DiscreteIntegrator: '<S215>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S215>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_p[1] += 0.004F * FMS_DW.Integrator_DSTATE_p
            [1];

          /* Signum: '<S216>/Sign4' incorporates:
           *  Sum: '<S216>/Subtract3'
           */
          rtb_MathFunction1 = rtb_Add3 - FMS_ConstB.d_n;

          /* Signum: '<S216>/Sign3' incorporates:
           *  Sum: '<S216>/Add6'
           */
          B = rtb_Add3 + FMS_ConstB.d_n;

          /* Signum: '<S216>/Sign5' */
          if (rtb_Add3 < 0.0F) {
            rtb_Subtract3_idx_0 = -1.0F;
          } else if (rtb_Add3 > 0.0F) {
            rtb_Subtract3_idx_0 = 1.0F;
          } else {
            rtb_Subtract3_idx_0 = rtb_Add3;
          }

          /* Signum: '<S216>/Sign3' */
          if (B < 0.0F) {
            B = -1.0F;
          } else {
            if (B > 0.0F) {
              B = 1.0F;
            }
          }

          /* Signum: '<S216>/Sign4' */
          if (rtb_MathFunction1 < 0.0F) {
            rtb_MathFunction1 = -1.0F;
          } else {
            if (rtb_MathFunction1 > 0.0F) {
              rtb_MathFunction1 = 1.0F;
            }
          }

          /* Signum: '<S216>/Sign6' */
          if (rtb_Add3 < 0.0F) {
            rtb_Saturation_l = -1.0F;
          } else if (rtb_Add3 > 0.0F) {
            rtb_Saturation_l = 1.0F;
          } else {
            rtb_Saturation_l = rtb_Add3;
          }

          /* Update for DiscreteIntegrator: '<S215>/Integrator' incorporates:
           *  Constant: '<S216>/const'
           *  Gain: '<S216>/Gain3'
           *  Product: '<S216>/Divide'
           *  Product: '<S216>/Multiply5'
           *  Product: '<S216>/Multiply6'
           *  Sum: '<S216>/Subtract4'
           *  Sum: '<S216>/Subtract5'
           *  Sum: '<S216>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_p[1] += ((rtb_Add3 / FMS_ConstB.d_n -
            rtb_Subtract3_idx_0) * FMS_ConstB.Gain4_a * ((B - rtb_MathFunction1)
            * 0.5F) - rtb_Saturation_l * 58.836F) * 0.004F;

          /* End of Outputs for SubSystem: '<S205>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S205>/Switch Case' */

        /* Chart: '<S196>/Motion Status' incorporates:
         *  Abs: '<S196>/Abs'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        if (FMS_DW.temporalCounter_i1_a < 511U) {
          FMS_DW.temporalCounter_i1_a++;
        }

        if (FMS_DW.is_active_c1_FMS == 0U) {
          FMS_DW.is_active_c1_FMS = 1U;
          FMS_DW.is_c1_FMS = FMS_IN_Move_j;
          rtb_state_a = MotionState_Move;
        } else {
          switch (FMS_DW.is_c1_FMS) {
           case FMS_IN_Brake_o:
            rtb_state_a = MotionState_Brake;

            /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
            if ((fabsf(FMS_U.INS_Out.vd) <= 0.15) ||
                (FMS_DW.temporalCounter_i1_a >= 375U)) {
              FMS_DW.is_c1_FMS = FMS_IN_Hold_h;
              rtb_state_a = MotionState_Hold;
            }

            /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
            break;

           case FMS_IN_Hold_h:
            rtb_state_a = MotionState_Hold;
            break;

           default:
            FMS_DW.is_c1_FMS = FMS_IN_Brake_o;
            FMS_DW.temporalCounter_i1_a = 0U;
            rtb_state_a = MotionState_Brake;
            break;
          }
        }

        /* End of Chart: '<S196>/Motion Status' */

        /* SwitchCase: '<S195>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_g;
        FMS_DW.SwitchCase_ActiveSubsystem_g = -1;
        switch (rtb_state_a) {
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
            /* SystemReset for IfAction SubSystem: '<S195>/Hold Control' incorporates:
             *  ActionPort: '<S198>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S195>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl);

            /* End of SystemReset for SubSystem: '<S195>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S195>/Hold Control' incorporates:
           *  ActionPort: '<S198>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_mu,
                          &FMS_DW.HoldControl);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S195>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S195>/Brake Control' incorporates:
           *  ActionPort: '<S197>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_mu);

          /* End of Outputs for SubSystem: '<S195>/Brake Control' */
          break;

         case 2:
          if (FMS_DW.SwitchCase_ActiveSubsystem_g != rtPrevAction) {
            /* InitializeConditions for IfAction SubSystem: '<S195>/Move Control' incorporates:
             *  ActionPort: '<S199>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S195>/Switch Case' incorporates:
             *  DiscreteIntegrator: '<S202>/Integrator'
             *  DiscreteIntegrator: '<S202>/Integrator1'
             */
            FMS_DW.Integrator1_DSTATE_n = 0.0F;
            FMS_DW.Integrator_DSTATE_l = 0.0F;

            /* End of InitializeConditions for SubSystem: '<S195>/Move Control' */
          }

          /* Outputs for IfAction SubSystem: '<S195>/Move Control' incorporates:
           *  ActionPort: '<S199>/Action Port'
           */
          /* Product: '<S203>/Multiply1' incorporates:
           *  Constant: '<S203>/const1'
           *  DiscreteIntegrator: '<S202>/Integrator'
           */
          rtb_Add3 = FMS_DW.Integrator_DSTATE_l * 0.05F;

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* DeadZone: '<S201>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S16>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_throttle > FMS_PARAM.THROTTLE_DZ) {
            rtb_MathFunction1 = FMS_U.Pilot_Cmd.stick_throttle -
              FMS_PARAM.THROTTLE_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_throttle >= -FMS_PARAM.THROTTLE_DZ) {
            rtb_MathFunction1 = 0.0F;
          } else {
            rtb_MathFunction1 = FMS_U.Pilot_Cmd.stick_throttle -
              (-FMS_PARAM.THROTTLE_DZ);
          }

          /* End of DeadZone: '<S201>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Sum: '<S203>/Add' incorporates:
           *  DiscreteIntegrator: '<S202>/Integrator1'
           *  Gain: '<S199>/Gain1'
           *  Gain: '<S201>/Gain'
           *  Sum: '<S202>/Subtract'
           */
          rtb_Subtract3_idx_1 = (FMS_DW.Integrator1_DSTATE_n - 1.0F / (1.0F -
            FMS_PARAM.THROTTLE_DZ) * rtb_MathFunction1 * -FMS_PARAM.VEL_Z_LIM) +
            rtb_Add3;

          /* Signum: '<S203>/Sign' */
          if (rtb_Subtract3_idx_1 < 0.0F) {
            rtb_Subtract3_idx_0 = -1.0F;
          } else if (rtb_Subtract3_idx_1 > 0.0F) {
            rtb_Subtract3_idx_0 = 1.0F;
          } else {
            rtb_Subtract3_idx_0 = rtb_Subtract3_idx_1;
          }

          /* End of Signum: '<S203>/Sign' */

          /* Sum: '<S203>/Add2' incorporates:
           *  Abs: '<S203>/Abs'
           *  Gain: '<S203>/Gain'
           *  Gain: '<S203>/Gain1'
           *  Product: '<S203>/Multiply2'
           *  Product: '<S203>/Multiply3'
           *  Sqrt: '<S203>/Sqrt'
           *  Sum: '<S203>/Add1'
           *  Sum: '<S203>/Subtract'
           */
          rtb_Subtract3_idx_0 = (sqrtf((8.0F * fabsf(rtb_Subtract3_idx_1) +
            FMS_ConstB.d_a) * FMS_ConstB.d_a) - FMS_ConstB.d_a) * 0.5F *
            rtb_Subtract3_idx_0 + rtb_Add3;

          /* Sum: '<S203>/Add4' */
          rtb_Add3 += rtb_Subtract3_idx_1 - rtb_Subtract3_idx_0;

          /* Sum: '<S203>/Add3' */
          rtb_MathFunction1 = rtb_Subtract3_idx_1 + FMS_ConstB.d_a;

          /* Sum: '<S203>/Subtract1' */
          rtb_Subtract3_idx_1 -= FMS_ConstB.d_a;

          /* Signum: '<S203>/Sign1' */
          if (rtb_MathFunction1 < 0.0F) {
            rtb_MathFunction1 = -1.0F;
          } else {
            if (rtb_MathFunction1 > 0.0F) {
              rtb_MathFunction1 = 1.0F;
            }
          }

          /* End of Signum: '<S203>/Sign1' */

          /* Signum: '<S203>/Sign2' */
          if (rtb_Subtract3_idx_1 < 0.0F) {
            rtb_Subtract3_idx_1 = -1.0F;
          } else {
            if (rtb_Subtract3_idx_1 > 0.0F) {
              rtb_Subtract3_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S203>/Sign2' */

          /* Sum: '<S203>/Add5' incorporates:
           *  Gain: '<S203>/Gain2'
           *  Product: '<S203>/Multiply4'
           *  Sum: '<S203>/Subtract2'
           */
          rtb_Subtract3_idx_0 += (rtb_MathFunction1 - rtb_Subtract3_idx_1) *
            0.5F * rtb_Add3;

          /* SignalConversion: '<S199>/OutportBufferForw_cmd_mPs' incorporates:
           *  DiscreteIntegrator: '<S202>/Integrator1'
           */
          FMS_B.Merge_mu = FMS_DW.Integrator1_DSTATE_n;

          /* Update for DiscreteIntegrator: '<S202>/Integrator1' incorporates:
           *  DiscreteIntegrator: '<S202>/Integrator'
           */
          FMS_DW.Integrator1_DSTATE_n += 0.004F * FMS_DW.Integrator_DSTATE_l;

          /* Sum: '<S203>/Subtract3' */
          rtb_MathFunction1 = rtb_Subtract3_idx_0 - FMS_ConstB.d_a;

          /* Sum: '<S203>/Add6' */
          B = rtb_Subtract3_idx_0 + FMS_ConstB.d_a;

          /* Signum: '<S203>/Sign5' incorporates:
           *  Signum: '<S203>/Sign6'
           */
          if (rtb_Subtract3_idx_0 < 0.0F) {
            rtb_Subtract3_idx_1 = -1.0F;

            /* Signum: '<S203>/Sign6' */
            rtb_Saturation_l = -1.0F;
          } else if (rtb_Subtract3_idx_0 > 0.0F) {
            rtb_Subtract3_idx_1 = 1.0F;

            /* Signum: '<S203>/Sign6' */
            rtb_Saturation_l = 1.0F;
          } else {
            rtb_Subtract3_idx_1 = rtb_Subtract3_idx_0;

            /* Signum: '<S203>/Sign6' */
            rtb_Saturation_l = rtb_Subtract3_idx_0;
          }

          /* End of Signum: '<S203>/Sign5' */

          /* Signum: '<S203>/Sign3' */
          if (B < 0.0F) {
            B = -1.0F;
          } else {
            if (B > 0.0F) {
              B = 1.0F;
            }
          }

          /* End of Signum: '<S203>/Sign3' */

          /* Signum: '<S203>/Sign4' */
          if (rtb_MathFunction1 < 0.0F) {
            rtb_MathFunction1 = -1.0F;
          } else {
            if (rtb_MathFunction1 > 0.0F) {
              rtb_MathFunction1 = 1.0F;
            }
          }

          /* End of Signum: '<S203>/Sign4' */

          /* Update for DiscreteIntegrator: '<S202>/Integrator' incorporates:
           *  Constant: '<S203>/const'
           *  Gain: '<S203>/Gain3'
           *  Product: '<S203>/Divide'
           *  Product: '<S203>/Multiply5'
           *  Product: '<S203>/Multiply6'
           *  Sum: '<S203>/Subtract4'
           *  Sum: '<S203>/Subtract5'
           *  Sum: '<S203>/Subtract6'
           */
          FMS_DW.Integrator_DSTATE_l += ((rtb_Subtract3_idx_0 / FMS_ConstB.d_a -
            rtb_Subtract3_idx_1) * FMS_ConstB.Gain4_c * ((B - rtb_MathFunction1)
            * 0.5F) - rtb_Saturation_l * 78.448F) * 0.004F;

          /* End of Outputs for SubSystem: '<S195>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S195>/Switch Case' */

        /* Delay: '<S171>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        if (FMS_DW.icLoad_cg != 0) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_DW.Delay_DSTATE_p[0] = FMS_U.INS_Out.x_R;
          FMS_DW.Delay_DSTATE_p[1] = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S143>/Sum' incorporates:
         *  Delay: '<S171>/Delay'
         *  MATLAB Function: '<S189>/OutRegionRegWP'
         *  MATLAB Function: '<S189>/SearchL1RefWP'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Sign1_n_idx_0 = FMS_B.Cmd_In.sp_return[0] - FMS_DW.Delay_DSTATE_p[0];
        rtb_Saturation_l = FMS_B.Cmd_In.sp_return[1] - FMS_DW.Delay_DSTATE_p[1];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Sum: '<S186>/Sum of Elements' incorporates:
         *  Math: '<S186>/Math Function'
         *  Sum: '<S143>/Sum'
         */
        rtb_MathFunction1 = rtb_Saturation_l * rtb_Saturation_l +
          rtb_Sign1_n_idx_0 * rtb_Sign1_n_idx_0;

        /* Math: '<S186>/Math Function1' incorporates:
         *  Sum: '<S186>/Sum of Elements'
         *
         * About '<S186>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_MathFunction1 < 0.0F) {
          rtb_Add3 = -sqrtf(fabsf(rtb_MathFunction1));
        } else {
          rtb_Add3 = sqrtf(rtb_MathFunction1);
        }

        /* End of Math: '<S186>/Math Function1' */

        /* Switch: '<S186>/Switch' incorporates:
         *  Constant: '<S186>/Constant'
         *  Product: '<S186>/Product'
         *  Sum: '<S143>/Sum'
         */
        if (rtb_Add3 > 0.0F) {
          rtb_Switch_l[0] = rtb_Saturation_l;
          rtb_Switch_l[1] = rtb_Sign1_n_idx_0;
          rtb_Switch_l[2] = rtb_Add3;
        } else {
          rtb_Switch_l[0] = 0.0F;
          rtb_Switch_l[1] = 0.0F;
          rtb_Switch_l[2] = 1.0F;
        }

        /* End of Switch: '<S186>/Switch' */

        /* Product: '<S186>/Divide' */
        rtb_Divide_f[0] = rtb_Switch_l[0] / rtb_Switch_l[2];
        rtb_Divide_f[1] = rtb_Switch_l[1] / rtb_Switch_l[2];

        /* Sum: '<S184>/Subtract' incorporates:
         *  Product: '<S184>/Multiply'
         *  Product: '<S184>/Multiply1'
         */
        rtb_Add3 = rtb_Divide_f[0] * FMS_ConstB.Divide[1] - rtb_Divide_f[1] *
          FMS_ConstB.Divide[0];

        /* Signum: '<S173>/Sign1' */
        if (rtb_Add3 < 0.0F) {
          rtb_Add3 = -1.0F;
        } else {
          if (rtb_Add3 > 0.0F) {
            rtb_Add3 = 1.0F;
          }
        }

        /* End of Signum: '<S173>/Sign1' */

        /* Switch: '<S173>/Switch2' incorporates:
         *  Constant: '<S173>/Constant4'
         */
        if (rtb_Add3 == 0.0F) {
          rtb_Add3 = 1.0F;
        }

        /* End of Switch: '<S173>/Switch2' */

        /* DotProduct: '<S173>/Dot Product' */
        rtb_Subtract3_idx_0 = FMS_ConstB.Divide[0] * rtb_Divide_f[0] +
          FMS_ConstB.Divide[1] * rtb_Divide_f[1];

        /* Trigonometry: '<S173>/Acos' incorporates:
         *  DotProduct: '<S173>/Dot Product'
         */
        if (rtb_Subtract3_idx_0 > 1.0F) {
          rtb_Subtract3_idx_0 = 1.0F;
        } else {
          if (rtb_Subtract3_idx_0 < -1.0F) {
            rtb_Subtract3_idx_0 = -1.0F;
          }
        }

        /* Product: '<S173>/Multiply' incorporates:
         *  Trigonometry: '<S173>/Acos'
         */
        rtb_Add3 *= acosf(rtb_Subtract3_idx_0);

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Math: '<S177>/Rem' incorporates:
         *  Constant: '<S177>/Constant1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  Sum: '<S172>/Sum1'
         */
        rtb_Subtract3_idx_0 = rt_remf(rtb_Add3 - FMS_U.INS_Out.psi, 6.28318548F);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Switch: '<S177>/Switch' incorporates:
         *  Abs: '<S177>/Abs'
         *  Constant: '<S177>/Constant'
         *  Constant: '<S183>/Constant'
         *  Product: '<S177>/Multiply'
         *  RelationalOperator: '<S183>/Compare'
         *  Sum: '<S177>/Add'
         */
        if (fabsf(rtb_Subtract3_idx_0) > 3.14159274F) {
          /* Signum: '<S177>/Sign' */
          if (rtb_Subtract3_idx_0 < 0.0F) {
            rtb_Subtract3_idx_1 = -1.0F;
          } else if (rtb_Subtract3_idx_0 > 0.0F) {
            rtb_Subtract3_idx_1 = 1.0F;
          } else {
            rtb_Subtract3_idx_1 = rtb_Subtract3_idx_0;
          }

          /* End of Signum: '<S177>/Sign' */
          rtb_Subtract3_idx_0 -= 6.28318548F * rtb_Subtract3_idx_1;
        }

        /* End of Switch: '<S177>/Switch' */

        /* Abs: '<S170>/Abs' */
        rtb_Subtract3_idx_0 = fabsf(rtb_Subtract3_idx_0);

        /* Switch: '<S170>/Switch' incorporates:
         *  Product: '<S191>/Multiply'
         *  Sum: '<S191>/Sum'
         */
        if (rtb_Subtract3_idx_0 > 0.34906584F) {
          /* Saturate: '<S205>/Saturation1' */
          if (FMS_B.Merge_m[0] > FMS_PARAM.VEL_XY_LIM) {
            rtb_Switch_l[0] = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_m[0] < -FMS_PARAM.VEL_XY_LIM) {
            rtb_Switch_l[0] = -FMS_PARAM.VEL_XY_LIM;
          } else {
            rtb_Switch_l[0] = FMS_B.Merge_m[0];
          }

          if (FMS_B.Merge_m[1] > FMS_PARAM.VEL_XY_LIM) {
            rtb_Switch_l[1] = FMS_PARAM.VEL_XY_LIM;
          } else if (FMS_B.Merge_m[1] < -FMS_PARAM.VEL_XY_LIM) {
            rtb_Switch_l[1] = -FMS_PARAM.VEL_XY_LIM;
          } else {
            rtb_Switch_l[1] = FMS_B.Merge_m[1];
          }

          /* End of Saturate: '<S205>/Saturation1' */

          /* Saturate: '<S195>/Saturation1' */
          if (FMS_B.Merge_mu > FMS_PARAM.VEL_Z_LIM) {
            rtb_Switch_l[2] = FMS_PARAM.VEL_Z_LIM;
          } else if (FMS_B.Merge_mu < -FMS_PARAM.VEL_Z_LIM) {
            rtb_Switch_l[2] = -FMS_PARAM.VEL_Z_LIM;
          } else {
            rtb_Switch_l[2] = FMS_B.Merge_mu;
          }

          /* End of Saturate: '<S195>/Saturation1' */
        } else {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Sum: '<S191>/Sum' incorporates:
           *  Delay: '<S191>/Delay'
           *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Subtract3_idx_1 = FMS_B.Cmd_In.sp_return[0] -
            FMS_DW.Delay_DSTATE_e[0];

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* SignalConversion: '<S233>/TmpSignal ConversionAtMath FunctionInport1' */
          rtb_Switch_l[0] = rtb_Subtract3_idx_1;
          rtb_Divide_f[0] = rtb_Subtract3_idx_1;

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Sum: '<S191>/Sum' incorporates:
           *  Delay: '<S191>/Delay'
           *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
           */
          rtb_Subtract3_idx_1 = FMS_B.Cmd_In.sp_return[1] -
            FMS_DW.Delay_DSTATE_e[1];

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* SignalConversion: '<S235>/ConcatBufferAtVector Concatenate2In3' incorporates:
           *  Constant: '<S235>/Constant4'
           */
          rtb_VectorConcatenate_hm[5] = 0.0F;

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Gain: '<S234>/Gain' incorporates:
           *  DiscreteIntegrator: '<S232>/Discrete-Time Integrator'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           *  Sum: '<S232>/Add'
           */
          rtb_MathFunction1 = -(FMS_U.INS_Out.psi - FMS_DW.l1_heading);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Trigonometry: '<S235>/Trigonometric Function3' incorporates:
           *  Trigonometry: '<S235>/Trigonometric Function1'
           */
          rtb_Subtract3_idx_0 = arm_cos_f32(rtb_MathFunction1);
          rtb_VectorConcatenate_hm[4] = rtb_Subtract3_idx_0;

          /* Trigonometry: '<S235>/Trigonometric Function2' incorporates:
           *  Trigonometry: '<S235>/Trigonometric Function'
           */
          rtb_MathFunction1 = arm_sin_f32(rtb_MathFunction1);

          /* Gain: '<S235>/Gain' incorporates:
           *  Trigonometry: '<S235>/Trigonometric Function2'
           */
          rtb_VectorConcatenate_hm[3] = -rtb_MathFunction1;

          /* SignalConversion: '<S235>/ConcatBufferAtVector Concatenate1In3' incorporates:
           *  Constant: '<S235>/Constant3'
           */
          rtb_VectorConcatenate_hm[2] = 0.0F;

          /* Trigonometry: '<S235>/Trigonometric Function' */
          rtb_VectorConcatenate_hm[1] = rtb_MathFunction1;

          /* Trigonometry: '<S235>/Trigonometric Function1' */
          rtb_VectorConcatenate_hm[0] = rtb_Subtract3_idx_0;

          /* SignalConversion: '<S235>/ConcatBufferAtVector ConcatenateIn3' */
          rtb_VectorConcatenate_hm[6] = FMS_ConstB.VectorConcatenate3_k[0];
          rtb_VectorConcatenate_hm[7] = FMS_ConstB.VectorConcatenate3_k[1];
          rtb_VectorConcatenate_hm[8] = FMS_ConstB.VectorConcatenate3_k[2];

          /* Sum: '<S233>/Sum of Elements' incorporates:
           *  Math: '<S233>/Math Function'
           */
          rtb_MathFunction1 = rtb_Switch_l[0] * rtb_Switch_l[0] +
            rtb_Subtract3_idx_1 * rtb_Subtract3_idx_1;

          /* Math: '<S233>/Math Function1' incorporates:
           *  Sum: '<S233>/Sum of Elements'
           *
           * About '<S233>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_MathFunction1 < 0.0F) {
            rtb_MathFunction1 = -sqrtf(fabsf(rtb_MathFunction1));
          } else {
            rtb_MathFunction1 = sqrtf(rtb_MathFunction1);
          }

          /* End of Math: '<S233>/Math Function1' */

          /* Switch: '<S233>/Switch' incorporates:
           *  Constant: '<S233>/Constant'
           *  Product: '<S233>/Product'
           */
          if (rtb_MathFunction1 > 0.0F) {
            rtb_Subtract3_idx_0 = rtb_Divide_f[0];
          } else {
            rtb_Subtract3_idx_0 = 0.0F;
            rtb_Subtract3_idx_1 = 0.0F;
            rtb_MathFunction1 = 1.0F;
          }

          /* End of Switch: '<S233>/Switch' */

          /* Product: '<S231>/Multiply2' incorporates:
           *  Product: '<S233>/Divide'
           */
          rtb_Subtract3_idx_0 = rtb_Subtract3_idx_0 / rtb_MathFunction1 *
            rtb_Sqrt;
          rtb_Subtract3_idx_1 = rtb_Subtract3_idx_1 / rtb_MathFunction1 *
            rtb_Sqrt;
          for (i = 0; i < 3; i++) {
            rtb_Switch_l[i] = rtb_VectorConcatenate_hm[i + 3] *
              rtb_Subtract3_idx_1 + rtb_VectorConcatenate_hm[i] *
              rtb_Subtract3_idx_0;
          }
        }

        /* End of Switch: '<S170>/Switch' */

        /* Delay: '<S172>/Delay' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        if (FMS_DW.icLoad_j != 0) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_DW.Delay_DSTATE_a = FMS_U.INS_Out.psi;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        }

        /* DiscreteIntegrator: '<S175>/Integrator1' incorporates:
         *  Delay: '<S172>/Delay'
         */
        if (FMS_DW.Integrator1_IC_LOADING != 0) {
          FMS_DW.Integrator1_DSTATE = FMS_DW.Delay_DSTATE_a;
        }

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Math: '<S179>/Rem' incorporates:
         *  Constant: '<S179>/Constant1'
         *  DiscreteIntegrator: '<S175>/Integrator1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  Sum: '<S174>/Sum'
         */
        rtb_Rem_k = rt_remf(FMS_DW.Integrator1_DSTATE - FMS_U.INS_Out.psi,
                            6.28318548F);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Switch: '<S179>/Switch' incorporates:
         *  Abs: '<S179>/Abs'
         *  Constant: '<S179>/Constant'
         *  Constant: '<S180>/Constant'
         *  Product: '<S179>/Multiply'
         *  RelationalOperator: '<S180>/Compare'
         *  Sum: '<S179>/Add'
         */
        if (fabsf(rtb_Rem_k) > 3.14159274F) {
          /* Signum: '<S179>/Sign' */
          if (rtb_Rem_k < 0.0F) {
            rtb_Subtract3_idx_0 = -1.0F;
          } else if (rtb_Rem_k > 0.0F) {
            rtb_Subtract3_idx_0 = 1.0F;
          } else {
            rtb_Subtract3_idx_0 = rtb_Rem_k;
          }

          /* End of Signum: '<S179>/Sign' */
          rtb_Rem_k -= 6.28318548F * rtb_Subtract3_idx_0;
        }

        /* End of Switch: '<S179>/Switch' */

        /* Gain: '<S174>/Gain2' */
        rtb_Rem_k *= FMS_PARAM.YAW_P;

        /* Saturate: '<S174>/Saturation' */
        if (rtb_Rem_k > FMS_PARAM.YAW_RATE_LIM) {
          rtb_Rem_k = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (rtb_Rem_k < -FMS_PARAM.YAW_RATE_LIM) {
            rtb_Rem_k = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Saturate: '<S174>/Saturation' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S143>/Bus Assignment1'
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S143>/Constant2'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S143>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_p;
        FMS_Y.FMS_Out.u_cmd = rtb_Switch_l[0];
        FMS_Y.FMS_Out.v_cmd = rtb_Switch_l[1];
        FMS_Y.FMS_Out.w_cmd = rtb_Switch_l[2];
        FMS_Y.FMS_Out.psi_rate_cmd = rtb_Rem_k;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Math: '<S226>/Math Function' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_Subtract3_idx_0 = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn;
        rtb_Subtract3_idx_1 = FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Sum: '<S226>/Sum of Elements' incorporates:
         *  Math: '<S226>/Math Function'
         */
        rtb_MathFunction1 = rtb_Subtract3_idx_0 + rtb_Subtract3_idx_1;

        /* Math: '<S226>/Math Function1' incorporates:
         *  Sum: '<S226>/Sum of Elements'
         *
         * About '<S226>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_MathFunction1 < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_MathFunction1));
        } else {
          rtb_Rem_k = sqrtf(rtb_MathFunction1);
        }

        /* End of Math: '<S226>/Math Function1' */

        /* Switch: '<S226>/Switch' incorporates:
         *  Constant: '<S226>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S226>/Product'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        if (rtb_Rem_k > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_Switch_l[0] = FMS_U.INS_Out.vn;
          rtb_Switch_l[1] = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          rtb_Switch_l[2] = rtb_Rem_k;
        } else {
          rtb_Switch_l[0] = 0.0F;
          rtb_Switch_l[1] = 0.0F;
          rtb_Switch_l[2] = 1.0F;
        }

        /* End of Switch: '<S226>/Switch' */

        /* Product: '<S226>/Divide' */
        rtb_Divide_f[0] = rtb_Switch_l[0] / rtb_Switch_l[2];
        rtb_Divide_f[1] = rtb_Switch_l[1] / rtb_Switch_l[2];

        /* Sum: '<S229>/Sum of Elements' incorporates:
         *  Math: '<S229>/Math Function'
         *  SignalConversion: '<S229>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_MathFunction1 = rtb_Divide_f[1] * rtb_Divide_f[1] + rtb_Divide_f[0] *
          rtb_Divide_f[0];

        /* Math: '<S229>/Math Function1' incorporates:
         *  Sum: '<S229>/Sum of Elements'
         *
         * About '<S229>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_MathFunction1 < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_MathFunction1));
        } else {
          rtb_Rem_k = sqrtf(rtb_MathFunction1);
        }

        /* End of Math: '<S229>/Math Function1' */

        /* Switch: '<S229>/Switch' incorporates:
         *  Constant: '<S229>/Constant'
         *  Product: '<S229>/Product'
         */
        if (rtb_Rem_k > 0.0F) {
          rtb_Switch_l[0] = rtb_Divide_f[1];
          rtb_Switch_l[1] = rtb_Divide_f[0];
          rtb_Switch_l[2] = rtb_Rem_k;
        } else {
          rtb_Switch_l[0] = 0.0F;
          rtb_Switch_l[1] = 0.0F;
          rtb_Switch_l[2] = 1.0F;
        }

        /* End of Switch: '<S229>/Switch' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* MATLAB Function: '<S189>/NearbyRefWP' incorporates:
         *  Constant: '<S143>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        FMS_NearbyRefWP(rtb_Divide_fw, FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                        FMS_PARAM.L1, rtb_Divide_f, &rtb_Rem_o);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* MATLAB Function: '<S189>/SearchL1RefWP' incorporates:
         *  Constant: '<S143>/L1'
         *  Delay: '<S171>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        A = rtb_Sign1_n_idx_0 * rtb_Sign1_n_idx_0 + rtb_Saturation_l *
          rtb_Saturation_l;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        B = (rtb_Sign1_n_idx_0 * (FMS_DW.Delay_DSTATE_p[0] - FMS_U.INS_Out.x_R)
             + rtb_Saturation_l * (FMS_DW.Delay_DSTATE_p[1] - FMS_U.INS_Out.y_R))
          * 2.0F;
        D = B * B - (((((FMS_U.INS_Out.x_R * FMS_U.INS_Out.x_R +
                         FMS_U.INS_Out.y_R * FMS_U.INS_Out.y_R) +
                        FMS_DW.Delay_DSTATE_p[0] * FMS_DW.Delay_DSTATE_p[0]) +
                       FMS_DW.Delay_DSTATE_p[1] * FMS_DW.Delay_DSTATE_p[1]) -
                      (FMS_U.INS_Out.x_R * FMS_DW.Delay_DSTATE_p[0] +
                       FMS_U.INS_Out.y_R * FMS_DW.Delay_DSTATE_p[1]) * 2.0F) -
                     FMS_PARAM.L1 * FMS_PARAM.L1) * (4.0F * A);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_MathFunction1 = -1.0F;
        rtb_Rem_k = 0.0F;
        rtb_a_idx_1 = 0.0F;
        guard1 = false;
        if (D > 0.0F) {
          u1_tmp = sqrtf(D);
          D = (-B + u1_tmp) / (2.0F * A);
          B = (-B - u1_tmp) / (2.0F * A);
          if ((D >= 0.0F) && (D <= 1.0F) && (B >= 0.0F) && (B <= 1.0F)) {
            rtb_MathFunction1 = fmaxf(D, B);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_MathFunction1 = D;
            guard1 = true;
          } else {
            if ((B >= 0.0F) && (B <= 1.0F)) {
              rtb_MathFunction1 = B;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -B / (2.0F * A);
            if ((D >= 0.0F) && (D <= 1.0F)) {
              rtb_MathFunction1 = D;
              guard1 = true;
            }
          }
        }

        if (guard1) {
          rtb_Rem_k = rtb_Sign1_n_idx_0 * rtb_MathFunction1 +
            FMS_DW.Delay_DSTATE_p[0];
          rtb_a_idx_1 = rtb_Saturation_l * rtb_MathFunction1 +
            FMS_DW.Delay_DSTATE_p[1];
        }

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* MATLAB Function: '<S189>/OutRegionRegWP' incorporates:
         *  Delay: '<S171>/Delay'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        B = ((FMS_U.INS_Out.y_R - FMS_DW.Delay_DSTATE_p[1]) * rtb_Saturation_l +
             (FMS_U.INS_Out.x_R - FMS_DW.Delay_DSTATE_p[0]) * rtb_Sign1_n_idx_0)
          / (rtb_Sign1_n_idx_0 * rtb_Sign1_n_idx_0 + rtb_Saturation_l *
             rtb_Saturation_l);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_Compare_i = (B <= 0.0F);
        u = (B >= 1.0F);
        if (rtb_Compare_i) {
          rtb_Sign1_n_idx_0 = FMS_DW.Delay_DSTATE_p[0];
        } else if (u) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_Sign1_n_idx_0 = FMS_B.Cmd_In.sp_return[0];

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        } else {
          rtb_Sign1_n_idx_0 = B * rtb_Sign1_n_idx_0 + FMS_DW.Delay_DSTATE_p[0];
        }

        /* Switch: '<S189>/Switch1' incorporates:
         *  Constant: '<S219>/Constant'
         *  RelationalOperator: '<S219>/Compare'
         */
        if (rtb_Rem_o <= 0.0F) {
          /* Switch: '<S189>/Switch' incorporates:
           *  Constant: '<S218>/Constant'
           *  MATLAB Function: '<S189>/SearchL1RefWP'
           *  RelationalOperator: '<S218>/Compare'
           */
          if (rtb_MathFunction1 >= 0.0F) {
            rtb_Divide_f[0] = rtb_Rem_k;
            rtb_Divide_f[1] = rtb_a_idx_1;
          } else {
            rtb_Divide_f[0] = rtb_Sign1_n_idx_0;

            /* MATLAB Function: '<S189>/OutRegionRegWP' incorporates:
             *  Delay: '<S171>/Delay'
             *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_Compare_i) {
              rtb_Divide_f[1] = FMS_DW.Delay_DSTATE_p[1];
            } else if (u) {
              /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
              rtb_Divide_f[1] = FMS_B.Cmd_In.sp_return[1];

              /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
            } else {
              rtb_Divide_f[1] = B * rtb_Saturation_l + FMS_DW.Delay_DSTATE_p[1];
            }
          }

          /* End of Switch: '<S189>/Switch' */
        }

        /* End of Switch: '<S189>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S190>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_Saturation_l = rtb_Divide_f[0] - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_Divide_f[0] = rtb_Saturation_l;
        rtb_Sign1_n_idx_0 = rtb_Saturation_l * rtb_Saturation_l;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S190>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S227>/Math Function'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_Saturation_l = rtb_Divide_f[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Math: '<S227>/Math Function' incorporates:
         *  Math: '<S225>/Square'
         */
        rtb_MathFunction1 = rtb_Saturation_l * rtb_Saturation_l;

        /* Sum: '<S227>/Sum of Elements' incorporates:
         *  Math: '<S227>/Math Function'
         */
        rtb_Sign1_n_idx_0 += rtb_MathFunction1;

        /* Math: '<S227>/Math Function1' incorporates:
         *  Sum: '<S227>/Sum of Elements'
         *
         * About '<S227>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Sign1_n_idx_0 < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_Sign1_n_idx_0));
        } else {
          rtb_Rem_k = sqrtf(rtb_Sign1_n_idx_0);
        }

        /* End of Math: '<S227>/Math Function1' */

        /* Switch: '<S227>/Switch' incorporates:
         *  Constant: '<S227>/Constant'
         *  Product: '<S227>/Product'
         */
        if (rtb_Rem_k > 0.0F) {
          rtb_MathFunction_aq[0] = rtb_Divide_f[0];
          rtb_MathFunction_aq[1] = rtb_Saturation_l;
          rtb_MathFunction_aq[2] = rtb_Rem_k;
        } else {
          rtb_MathFunction_aq[0] = 0.0F;
          rtb_MathFunction_aq[1] = 0.0F;
          rtb_MathFunction_aq[2] = 1.0F;
        }

        /* End of Switch: '<S227>/Switch' */

        /* Product: '<S227>/Divide' */
        rtb_Divide_fw[0] = rtb_MathFunction_aq[0] / rtb_MathFunction_aq[2];
        rtb_Divide_fw[1] = rtb_MathFunction_aq[1] / rtb_MathFunction_aq[2];

        /* Sum: '<S230>/Sum of Elements' incorporates:
         *  Math: '<S230>/Math Function'
         *  SignalConversion: '<S230>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Sign1_n_idx_0 = rtb_Divide_fw[1] * rtb_Divide_fw[1] + rtb_Divide_fw
          [0] * rtb_Divide_fw[0];

        /* Math: '<S230>/Math Function1' incorporates:
         *  Sum: '<S230>/Sum of Elements'
         *
         * About '<S230>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Sign1_n_idx_0 < 0.0F) {
          rtb_Rem_k = -sqrtf(fabsf(rtb_Sign1_n_idx_0));
        } else {
          rtb_Rem_k = sqrtf(rtb_Sign1_n_idx_0);
        }

        /* End of Math: '<S230>/Math Function1' */

        /* Switch: '<S230>/Switch' incorporates:
         *  Constant: '<S230>/Constant'
         *  Product: '<S230>/Product'
         */
        if (rtb_Rem_k > 0.0F) {
          rtb_MathFunction_aq[0] = rtb_Divide_fw[1];
          rtb_MathFunction_aq[1] = rtb_Divide_fw[0];
          rtb_MathFunction_aq[2] = rtb_Rem_k;
        } else {
          rtb_MathFunction_aq[0] = 0.0F;
          rtb_MathFunction_aq[1] = 0.0F;
          rtb_MathFunction_aq[2] = 1.0F;
        }

        /* End of Switch: '<S230>/Switch' */

        /* Product: '<S230>/Divide' */
        rtb_Divide_fw[0] = rtb_MathFunction_aq[0] / rtb_MathFunction_aq[2];

        /* Math: '<S225>/Square' */
        rtb_Sign1_n_idx_0 = rtb_Divide_f[0] * rtb_Divide_f[0];
        rtb_Divide_f[0] = rtb_Switch_l[0] / rtb_Switch_l[2];

        /* Product: '<S230>/Divide' incorporates:
         *  Product: '<S229>/Divide'
         */
        rtb_Divide_fw[1] = rtb_MathFunction_aq[1] / rtb_MathFunction_aq[2];

        /* Product: '<S229>/Divide' */
        rtb_Saturation_l = rtb_Switch_l[1] / rtb_Switch_l[2];

        /* Sqrt: '<S224>/Sqrt' incorporates:
         *  Math: '<S226>/Math Function'
         *  Sum: '<S224>/Sum of Elements'
         */
        rtb_Rem_k = sqrtf(rtb_Subtract3_idx_0 + rtb_Subtract3_idx_1);

        /* Gain: '<S190>/Gain' incorporates:
         *  Math: '<S190>/Square'
         */
        rtb_Subtract3_idx_0 = rtb_Rem_k * rtb_Rem_k * 2.0F;

        /* Sum: '<S228>/Subtract' incorporates:
         *  Product: '<S228>/Multiply'
         *  Product: '<S228>/Multiply1'
         */
        rtb_Rem_k = rtb_Divide_fw[0] * rtb_Saturation_l - rtb_Divide_fw[1] *
          rtb_Divide_f[0];

        /* Signum: '<S223>/Sign1' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S223>/Sign1' */

        /* Switch: '<S223>/Switch2' incorporates:
         *  Constant: '<S223>/Constant4'
         */
        if (rtb_Rem_k == 0.0F) {
          rtb_Rem_k = 1.0F;
        }

        /* End of Switch: '<S223>/Switch2' */

        /* DotProduct: '<S223>/Dot Product' */
        rtb_Saturation_l = rtb_Divide_f[0] * rtb_Divide_fw[0] + rtb_Saturation_l
          * rtb_Divide_fw[1];

        /* Trigonometry: '<S223>/Acos' incorporates:
         *  DotProduct: '<S223>/Dot Product'
         */
        if (rtb_Saturation_l > 1.0F) {
          rtb_Saturation_l = 1.0F;
        } else {
          if (rtb_Saturation_l < -1.0F) {
            rtb_Saturation_l = -1.0F;
          }
        }

        /* Product: '<S223>/Multiply' incorporates:
         *  Trigonometry: '<S223>/Acos'
         */
        rtb_Rem_k *= acosf(rtb_Saturation_l);

        /* Saturate: '<S190>/Saturation' */
        if (rtb_Rem_k > 1.57079637F) {
          rtb_Rem_k = 1.57079637F;
        } else {
          if (rtb_Rem_k < -1.57079637F) {
            rtb_Rem_k = -1.57079637F;
          }
        }

        /* End of Saturate: '<S190>/Saturation' */

        /* Product: '<S190>/Divide' incorporates:
         *  Constant: '<S143>/L1'
         *  Constant: '<S190>/Constant'
         *  MinMax: '<S190>/Max'
         *  MinMax: '<S190>/Min'
         *  Product: '<S190>/Multiply1'
         *  Sqrt: '<S225>/Sqrt'
         *  Sum: '<S225>/Sum of Elements'
         *  Trigonometry: '<S190>/Sin'
         */
        rtb_Subtract3_idx_0 = arm_sin_f32(rtb_Rem_k) * rtb_Subtract3_idx_0 /
          fminf(FMS_PARAM.L1, fmaxf(sqrtf(rtb_MathFunction1 + rtb_Sign1_n_idx_0),
                 0.5F));

        /* Sum: '<S172>/Sum2' incorporates:
         *  Delay: '<S172>/Delay'
         */
        rtb_Add3 -= FMS_DW.Delay_DSTATE_a;

        /* Math: '<S176>/Rem' incorporates:
         *  Constant: '<S176>/Constant1'
         */
        rtb_Rem_o = rt_remf(rtb_Add3, 6.28318548F);

        /* Switch: '<S176>/Switch' incorporates:
         *  Abs: '<S176>/Abs'
         *  Constant: '<S176>/Constant'
         *  Constant: '<S182>/Constant'
         *  Product: '<S176>/Multiply'
         *  RelationalOperator: '<S182>/Compare'
         *  Sum: '<S176>/Add'
         */
        if (fabsf(rtb_Rem_o) > 3.14159274F) {
          /* Signum: '<S176>/Sign' */
          if (rtb_Rem_o < 0.0F) {
            rtb_Subtract3_idx_1 = -1.0F;
          } else if (rtb_Rem_o > 0.0F) {
            rtb_Subtract3_idx_1 = 1.0F;
          } else {
            rtb_Subtract3_idx_1 = rtb_Rem_o;
          }

          /* End of Signum: '<S176>/Sign' */
          rtb_Rem_o -= 6.28318548F * rtb_Subtract3_idx_1;
        }

        /* End of Switch: '<S176>/Switch' */

        /* Sum: '<S172>/Sum' incorporates:
         *  Delay: '<S172>/Delay'
         */
        rtb_Subtract3_idx_1 = rtb_Rem_o + FMS_DW.Delay_DSTATE_a;

        /* Product: '<S181>/Multiply1' incorporates:
         *  Constant: '<S181>/const1'
         *  DiscreteIntegrator: '<S175>/Integrator'
         */
        rtb_Rem_o = FMS_DW.Integrator_DSTATE * 0.785398185F;

        /* Sum: '<S181>/Add' incorporates:
         *  DiscreteIntegrator: '<S175>/Integrator1'
         *  Sum: '<S175>/Subtract'
         */
        rtb_Rem_k = (FMS_DW.Integrator1_DSTATE - rtb_Subtract3_idx_1) +
          rtb_Rem_o;

        /* Signum: '<S181>/Sign' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Subtract3_idx_1 = -1.0F;
        } else if (rtb_Rem_k > 0.0F) {
          rtb_Subtract3_idx_1 = 1.0F;
        } else {
          rtb_Subtract3_idx_1 = rtb_Rem_k;
        }

        /* End of Signum: '<S181>/Sign' */

        /* Sum: '<S181>/Add2' incorporates:
         *  Abs: '<S181>/Abs'
         *  Gain: '<S181>/Gain'
         *  Gain: '<S181>/Gain1'
         *  Product: '<S181>/Multiply2'
         *  Product: '<S181>/Multiply3'
         *  Sqrt: '<S181>/Sqrt'
         *  Sum: '<S181>/Add1'
         *  Sum: '<S181>/Subtract'
         */
        rtb_Add3 = (sqrtf((8.0F * fabsf(rtb_Rem_k) + FMS_ConstB.d) *
                          FMS_ConstB.d) - FMS_ConstB.d) * 0.5F *
          rtb_Subtract3_idx_1 + rtb_Rem_o;

        /* Sum: '<S181>/Add4' */
        rtb_Subtract3_idx_1 = (rtb_Rem_k - rtb_Add3) + rtb_Rem_o;

        /* Sum: '<S181>/Add3' */
        rtb_MathFunction1 = rtb_Rem_k + FMS_ConstB.d;

        /* Sum: '<S181>/Subtract1' */
        rtb_Rem_k -= FMS_ConstB.d;

        /* Signum: '<S181>/Sign1' */
        if (rtb_MathFunction1 < 0.0F) {
          rtb_MathFunction1 = -1.0F;
        } else {
          if (rtb_MathFunction1 > 0.0F) {
            rtb_MathFunction1 = 1.0F;
          }
        }

        /* End of Signum: '<S181>/Sign1' */

        /* Signum: '<S181>/Sign2' */
        if (rtb_Rem_k < 0.0F) {
          rtb_Rem_k = -1.0F;
        } else {
          if (rtb_Rem_k > 0.0F) {
            rtb_Rem_k = 1.0F;
          }
        }

        /* End of Signum: '<S181>/Sign2' */

        /* Sum: '<S181>/Add5' incorporates:
         *  Gain: '<S181>/Gain2'
         *  Product: '<S181>/Multiply4'
         *  Sum: '<S181>/Subtract2'
         */
        rtb_Add3 += (rtb_MathFunction1 - rtb_Rem_k) * 0.5F * rtb_Subtract3_idx_1;

        /* Update for Delay: '<S191>/Delay' */
        FMS_DW.icLoad_o = 0U;

        /* Update for DiscreteIntegrator: '<S232>/Discrete-Time Integrator' incorporates:
         *  Product: '<S191>/Divide1'
         */
        FMS_DW.l1_heading += rtb_Subtract3_idx_0 / rtb_Sqrt * 0.004F;

        /* Update for Delay: '<S171>/Delay' */
        FMS_DW.icLoad_cg = 0U;

        /* Update for Delay: '<S172>/Delay' */
        FMS_DW.icLoad_j = 0U;

        /* Update for DiscreteIntegrator: '<S175>/Integrator1' incorporates:
         *  DiscreteIntegrator: '<S175>/Integrator'
         */
        FMS_DW.Integrator1_IC_LOADING = 0U;
        FMS_DW.Integrator1_DSTATE += 0.004F * FMS_DW.Integrator_DSTATE;

        /* Sum: '<S181>/Subtract3' */
        rtb_MathFunction1 = rtb_Add3 - FMS_ConstB.d;

        /* Sum: '<S181>/Add6' */
        B = rtb_Add3 + FMS_ConstB.d;

        /* Signum: '<S181>/Sign5' incorporates:
         *  Signum: '<S181>/Sign6'
         */
        if (rtb_Add3 < 0.0F) {
          rtb_Subtract3_idx_1 = -1.0F;

          /* Signum: '<S181>/Sign6' */
          rtb_Saturation_l = -1.0F;
        } else if (rtb_Add3 > 0.0F) {
          rtb_Subtract3_idx_1 = 1.0F;

          /* Signum: '<S181>/Sign6' */
          rtb_Saturation_l = 1.0F;
        } else {
          rtb_Subtract3_idx_1 = rtb_Add3;

          /* Signum: '<S181>/Sign6' */
          rtb_Saturation_l = rtb_Add3;
        }

        /* End of Signum: '<S181>/Sign5' */

        /* Signum: '<S181>/Sign3' */
        if (B < 0.0F) {
          B = -1.0F;
        } else {
          if (B > 0.0F) {
            B = 1.0F;
          }
        }

        /* End of Signum: '<S181>/Sign3' */

        /* Signum: '<S181>/Sign4' */
        if (rtb_MathFunction1 < 0.0F) {
          rtb_MathFunction1 = -1.0F;
        } else {
          if (rtb_MathFunction1 > 0.0F) {
            rtb_MathFunction1 = 1.0F;
          }
        }

        /* End of Signum: '<S181>/Sign4' */

        /* Update for DiscreteIntegrator: '<S175>/Integrator' incorporates:
         *  Constant: '<S181>/const'
         *  Gain: '<S181>/Gain3'
         *  Product: '<S181>/Divide'
         *  Product: '<S181>/Multiply5'
         *  Product: '<S181>/Multiply6'
         *  Sum: '<S181>/Subtract4'
         *  Sum: '<S181>/Subtract5'
         *  Sum: '<S181>/Subtract6'
         */
        FMS_DW.Integrator_DSTATE += ((rtb_Add3 / FMS_ConstB.d -
          rtb_Subtract3_idx_1) * FMS_ConstB.Gain4 * ((B - rtb_MathFunction1) *
          0.5F) - rtb_Saturation_l * 1.04719758F) * 0.004F;
        if (FMS_DW.Integrator_DSTATE >= FMS_PARAM.YAW_RATE_LIM) {
          FMS_DW.Integrator_DSTATE = FMS_PARAM.YAW_RATE_LIM;
        } else {
          if (FMS_DW.Integrator_DSTATE <= -FMS_PARAM.YAW_RATE_LIM) {
            FMS_DW.Integrator_DSTATE = -FMS_PARAM.YAW_RATE_LIM;
          }
        }

        /* End of Update for DiscreteIntegrator: '<S175>/Integrator' */
        /* End of Outputs for SubSystem: '<S24>/Return' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_a != rtPrevAction) {
          /* InitializeConditions for IfAction SubSystem: '<S24>/Hold' incorporates:
           *  ActionPort: '<S141>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S24>/Switch Case' incorporates:
           *  Delay: '<S146>/Delay'
           *  Delay: '<S151>/start_vel'
           *  Delay: '<S151>/start_wp'
           */
          FMS_DW.icLoad_n = 1U;
          FMS_DW.icLoad_m = 1U;
          FMS_DW.icLoad_b = 1U;

          /* End of InitializeConditions for SubSystem: '<S24>/Hold' */
        }

        /* Outputs for IfAction SubSystem: '<S24>/Hold' incorporates:
         *  ActionPort: '<S141>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S158>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S158>/Math Function'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_MathFunction1 = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Math: '<S158>/Math Function1' incorporates:
         *  Sum: '<S158>/Sum of Elements'
         *
         * About '<S158>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_MathFunction1 < 0.0F) {
          rtb_Subtract3_idx_0 = -sqrtf(fabsf(rtb_MathFunction1));
        } else {
          rtb_Subtract3_idx_0 = sqrtf(rtb_MathFunction1);
        }

        /* End of Math: '<S158>/Math Function1' */

        /* Switch: '<S158>/Switch' incorporates:
         *  Constant: '<S158>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S158>/Product'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        if (rtb_Subtract3_idx_0 > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_Switch_l[0] = FMS_U.INS_Out.vn;
          rtb_Switch_l[1] = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          rtb_Switch_l[2] = rtb_Subtract3_idx_0;
        } else {
          rtb_Switch_l[0] = 0.0F;
          rtb_Switch_l[1] = 0.0F;
          rtb_Switch_l[2] = 1.0F;
        }

        /* End of Switch: '<S158>/Switch' */

        /* Delay: '<S151>/start_vel' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        if (FMS_DW.icLoad_n != 0) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_DW.start_vel_DSTATE_g[0] = FMS_U.INS_Out.vn;
          FMS_DW.start_vel_DSTATE_g[1] = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        }

        /* Sum: '<S163>/Sum of Elements' incorporates:
         *  Delay: '<S151>/start_vel'
         *  Math: '<S163>/Math Function'
         */
        rtb_MathFunction1 = FMS_DW.start_vel_DSTATE_g[0] *
          FMS_DW.start_vel_DSTATE_g[0] + FMS_DW.start_vel_DSTATE_g[1] *
          FMS_DW.start_vel_DSTATE_g[1];

        /* Math: '<S163>/Math Function1' incorporates:
         *  Sum: '<S163>/Sum of Elements'
         *
         * About '<S163>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_MathFunction1 < 0.0F) {
          rtb_Subtract3_idx_0 = -sqrtf(fabsf(rtb_MathFunction1));
        } else {
          rtb_Subtract3_idx_0 = sqrtf(rtb_MathFunction1);
        }

        /* End of Math: '<S163>/Math Function1' */

        /* Switch: '<S163>/Switch' incorporates:
         *  Constant: '<S163>/Constant'
         *  Delay: '<S151>/start_vel'
         *  Product: '<S163>/Product'
         */
        if (rtb_Subtract3_idx_0 > 0.0F) {
          rtb_MathFunction_aq[0] = FMS_DW.start_vel_DSTATE_g[0];
          rtb_MathFunction_aq[1] = FMS_DW.start_vel_DSTATE_g[1];
          rtb_MathFunction_aq[2] = rtb_Subtract3_idx_0;
        } else {
          rtb_MathFunction_aq[0] = 0.0F;
          rtb_MathFunction_aq[1] = 0.0F;
          rtb_MathFunction_aq[2] = 1.0F;
        }

        /* End of Switch: '<S163>/Switch' */

        /* Product: '<S158>/Divide' */
        rtb_Divide_f[0] = rtb_Switch_l[0] / rtb_Switch_l[2];
        rtb_Divide_f[1] = rtb_Switch_l[1] / rtb_Switch_l[2];

        /* Sum: '<S161>/Sum of Elements' incorporates:
         *  Math: '<S161>/Math Function'
         *  SignalConversion: '<S161>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_MathFunction1 = rtb_Divide_f[1] * rtb_Divide_f[1] + rtb_Divide_f[0] *
          rtb_Divide_f[0];

        /* Math: '<S161>/Math Function1' incorporates:
         *  Sum: '<S161>/Sum of Elements'
         *
         * About '<S161>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_MathFunction1 < 0.0F) {
          rtb_Subtract3_idx_0 = -sqrtf(fabsf(rtb_MathFunction1));
        } else {
          rtb_Subtract3_idx_0 = sqrtf(rtb_MathFunction1);
        }

        /* End of Math: '<S161>/Math Function1' */

        /* Switch: '<S161>/Switch' incorporates:
         *  Constant: '<S161>/Constant'
         *  Product: '<S161>/Product'
         */
        if (rtb_Subtract3_idx_0 > 0.0F) {
          rtb_Switch_l[0] = rtb_Divide_f[1];
          rtb_Switch_l[1] = rtb_Divide_f[0];
          rtb_Switch_l[2] = rtb_Subtract3_idx_0;
        } else {
          rtb_Switch_l[0] = 0.0F;
          rtb_Switch_l[1] = 0.0F;
          rtb_Switch_l[2] = 1.0F;
        }

        /* End of Switch: '<S161>/Switch' */

        /* MinMax: '<S149>/Max' incorporates:
         *  Constant: '<S147>/L1'
         *  Constant: '<S147>/R'
         *  Gain: '<S149>/Gain'
         */
        rtb_Subtract3_idx_0 = fmaxf(FMS_PARAM.LOITER_R, 0.5F * FMS_PARAM.L1);

        /* Delay: '<S151>/start_wp' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        if (FMS_DW.icLoad_m != 0) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_DW.start_wp_DSTATE_d[0] = FMS_U.INS_Out.x_R;
          FMS_DW.start_wp_DSTATE_d[1] = FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        }

        /* MATLAB Function: '<S149>/SearchL1RefWP' incorporates:
         *  Constant: '<S147>/L1'
         *  Delay: '<S151>/start_wp'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_Divide_fw[0] = 0.0F;
        rtb_Divide_fw[1] = 0.0F;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        if ((FMS_U.INS_Out.x_R == FMS_DW.start_wp_DSTATE_d[0]) &&
            (FMS_U.INS_Out.y_R == FMS_DW.start_wp_DSTATE_d[1]) &&
            (rtb_Subtract3_idx_0 == FMS_PARAM.L1)) {
          i = 0;
        } else {
          rtb_MathFunction1 = FMS_DW.start_wp_DSTATE_d[0] - FMS_U.INS_Out.x_R;
          rtb_Sqrt = FMS_DW.start_wp_DSTATE_d[1] - FMS_U.INS_Out.y_R;
          rtb_Subtract3_idx_1 = sqrtf(rtb_Sqrt * rtb_Sqrt + rtb_MathFunction1 *
            rtb_MathFunction1);
          rtb_Add3 = ((rtb_Subtract3_idx_1 * rtb_Subtract3_idx_1 + FMS_PARAM.L1 *
                       FMS_PARAM.L1) - rtb_Subtract3_idx_0 * rtb_Subtract3_idx_0)
            / (2.0F * rtb_Subtract3_idx_1);
          rtb_Sign1_n_idx_0 = rtb_MathFunction1 / rtb_Subtract3_idx_1;
          rtb_Sqrt /= rtb_Subtract3_idx_1;
          rtb_MathFunction1 = rtb_Add3 * rtb_Add3;
          if (rtb_MathFunction1 > FMS_PARAM.L1 * FMS_PARAM.L1) {
            i = 0;
          } else if (rtb_MathFunction1 == FMS_PARAM.L1 * FMS_PARAM.L1) {
            i = 1;
            rtb_Divide_fw[0] = rtb_Add3 * rtb_Sign1_n_idx_0 + FMS_U.INS_Out.x_R;
            rtb_Divide_fw[1] = rtb_Add3 * rtb_Sqrt + FMS_U.INS_Out.y_R;
          } else {
            i = 2;
            rtb_Subtract3_idx_1 = sqrtf(FMS_PARAM.L1 * FMS_PARAM.L1 -
              rtb_MathFunction1);
            rtb_Divide_fw[0] = (rtb_Add3 * rtb_Sign1_n_idx_0 + FMS_U.INS_Out.x_R)
              + rtb_Subtract3_idx_1 * -rtb_Sqrt;
            rtb_Divide_fw[1] = (rtb_Add3 * rtb_Sqrt + FMS_U.INS_Out.y_R) +
              rtb_Subtract3_idx_1 * rtb_Sign1_n_idx_0;
          }
        }

        /* End of MATLAB Function: '<S149>/SearchL1RefWP' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* RelationalOperator: '<S152>/Compare' incorporates:
         *  Constant: '<S152>/Constant'
         */
        rtb_Compare_i = (i > 0);

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* MATLAB Function: '<S149>/OutRegionRegWP' incorporates:
         *  Delay: '<S151>/start_wp'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_Sqrt = FMS_U.INS_Out.x_R - FMS_DW.start_wp_DSTATE_d[0];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_Rem_k = rtb_Sqrt * rtb_Sqrt;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        rtb_Sqrt = FMS_U.INS_Out.y_R - FMS_DW.start_wp_DSTATE_d[1];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        u = (rtb_Sqrt * rtb_Sqrt + rtb_Rem_k > rtb_Subtract3_idx_0 *
             rtb_Subtract3_idx_0);

        /* Switch: '<S149>/Switch' incorporates:
         *  Constant: '<S147>/L1'
         *  Inport: '<Root>/INS_Out'
         *  MATLAB Function: '<S149>/OutRegionRegWP'
         *  Product: '<S163>/Divide'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        if (rtb_Compare_i) {
          rtb_Sqrt = rtb_Divide_fw[0];
        } else if (u) {
          /* MATLAB Function: '<S149>/OutRegionRegWP' incorporates:
           *  Delay: '<S151>/start_wp'
           */
          rtb_Sqrt = FMS_DW.start_wp_DSTATE_d[0];
        } else {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_Sqrt = rtb_MathFunction_aq[0] / rtb_MathFunction_aq[2] *
            FMS_PARAM.L1 + FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S150>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_Sqrt -= FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_Divide_fw[0] = rtb_Sqrt;
        rtb_Divide_f[0] = rtb_Sqrt * rtb_Sqrt;

        /* Switch: '<S149>/Switch' incorporates:
         *  Constant: '<S147>/L1'
         *  Inport: '<Root>/INS_Out'
         *  MATLAB Function: '<S149>/OutRegionRegWP'
         *  Math: '<S159>/Math Function'
         *  Product: '<S163>/Divide'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  Sum: '<S150>/Subtract'
         */
        if (rtb_Compare_i) {
          rtb_Sqrt = rtb_Divide_fw[1];
        } else if (u) {
          /* MATLAB Function: '<S149>/OutRegionRegWP' incorporates:
           *  Delay: '<S151>/start_wp'
           */
          rtb_Sqrt = FMS_DW.start_wp_DSTATE_d[1];
        } else {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_Sqrt = rtb_MathFunction_aq[1] / rtb_MathFunction_aq[2] *
            FMS_PARAM.L1 + FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S150>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_Sqrt -= FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Sum: '<S159>/Sum of Elements' incorporates:
         *  Math: '<S159>/Math Function'
         */
        rtb_MathFunction1 = rtb_Sqrt * rtb_Sqrt + rtb_Divide_f[0];

        /* Math: '<S159>/Math Function1' incorporates:
         *  Sum: '<S159>/Sum of Elements'
         *
         * About '<S159>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_MathFunction1 < 0.0F) {
          rtb_Subtract3_idx_0 = -sqrtf(fabsf(rtb_MathFunction1));
        } else {
          rtb_Subtract3_idx_0 = sqrtf(rtb_MathFunction1);
        }

        /* End of Math: '<S159>/Math Function1' */

        /* Switch: '<S159>/Switch' incorporates:
         *  Constant: '<S159>/Constant'
         *  Product: '<S159>/Product'
         */
        if (rtb_Subtract3_idx_0 > 0.0F) {
          rtb_MathFunction_aq[0] = rtb_Divide_fw[0];
          rtb_MathFunction_aq[1] = rtb_Sqrt;
          rtb_MathFunction_aq[2] = rtb_Subtract3_idx_0;
        } else {
          rtb_MathFunction_aq[0] = 0.0F;
          rtb_MathFunction_aq[1] = 0.0F;
          rtb_MathFunction_aq[2] = 1.0F;
        }

        /* End of Switch: '<S159>/Switch' */

        /* Product: '<S159>/Divide' */
        rtb_Divide_f[0] = rtb_MathFunction_aq[0] / rtb_MathFunction_aq[2];
        rtb_Divide_f[1] = rtb_MathFunction_aq[1] / rtb_MathFunction_aq[2];

        /* Sum: '<S162>/Sum of Elements' incorporates:
         *  Math: '<S162>/Math Function'
         *  SignalConversion: '<S162>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_MathFunction1 = rtb_Divide_f[1] * rtb_Divide_f[1] + rtb_Divide_f[0] *
          rtb_Divide_f[0];

        /* Math: '<S162>/Math Function1' incorporates:
         *  Sum: '<S162>/Sum of Elements'
         *
         * About '<S162>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_MathFunction1 < 0.0F) {
          rtb_Subtract3_idx_0 = -sqrtf(fabsf(rtb_MathFunction1));
        } else {
          rtb_Subtract3_idx_0 = sqrtf(rtb_MathFunction1);
        }

        /* End of Math: '<S162>/Math Function1' */

        /* Switch: '<S162>/Switch' incorporates:
         *  Constant: '<S162>/Constant'
         *  Product: '<S162>/Product'
         */
        if (rtb_Subtract3_idx_0 > 0.0F) {
          rtb_MathFunction_aq[0] = rtb_Divide_f[1];
          rtb_MathFunction_aq[1] = rtb_Divide_f[0];
          rtb_MathFunction_aq[2] = rtb_Subtract3_idx_0;
        } else {
          rtb_MathFunction_aq[0] = 0.0F;
          rtb_MathFunction_aq[1] = 0.0F;
          rtb_MathFunction_aq[2] = 1.0F;
        }

        /* End of Switch: '<S162>/Switch' */

        /* Product: '<S162>/Divide' */
        rtb_Divide_f[0] = rtb_MathFunction_aq[0] / rtb_MathFunction_aq[2];

        /* Product: '<S161>/Divide' */
        rtb_Divide_fw[0] = rtb_Switch_l[0] / rtb_Switch_l[2];

        /* Product: '<S162>/Divide' */
        rtb_Divide_f[1] = rtb_MathFunction_aq[1] / rtb_MathFunction_aq[2];

        /* Product: '<S161>/Divide' */
        rtb_Divide_fw[1] = rtb_Switch_l[1] / rtb_Switch_l[2];

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sqrt: '<S157>/Sqrt' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S157>/Square'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  Sum: '<S157>/Sum of Elements'
         */
        rtb_Subtract3_idx_1 = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Sum: '<S160>/Subtract' incorporates:
         *  Product: '<S160>/Multiply'
         *  Product: '<S160>/Multiply1'
         */
        rtb_Subtract3_idx_0 = rtb_Divide_f[0] * rtb_Divide_fw[1] - rtb_Divide_f
          [1] * rtb_Divide_fw[0];

        /* Signum: '<S156>/Sign1' */
        if (rtb_Subtract3_idx_0 < 0.0F) {
          rtb_Subtract3_idx_0 = -1.0F;
        } else {
          if (rtb_Subtract3_idx_0 > 0.0F) {
            rtb_Subtract3_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S156>/Sign1' */

        /* Switch: '<S156>/Switch2' incorporates:
         *  Constant: '<S156>/Constant4'
         */
        if (rtb_Subtract3_idx_0 == 0.0F) {
          rtb_Subtract3_idx_0 = 1.0F;
        }

        /* End of Switch: '<S156>/Switch2' */

        /* DotProduct: '<S156>/Dot Product' */
        rtb_Sqrt = rtb_Divide_fw[0] * rtb_Divide_f[0] + rtb_Divide_fw[1] *
          rtb_Divide_f[1];

        /* Trigonometry: '<S156>/Acos' incorporates:
         *  DotProduct: '<S156>/Dot Product'
         */
        if (rtb_Sqrt > 1.0F) {
          rtb_Sqrt = 1.0F;
        } else {
          if (rtb_Sqrt < -1.0F) {
            rtb_Sqrt = -1.0F;
          }
        }

        /* Product: '<S156>/Multiply' incorporates:
         *  Trigonometry: '<S156>/Acos'
         */
        rtb_Subtract3_idx_0 *= acosf(rtb_Sqrt);

        /* Saturate: '<S155>/Saturation' */
        if (rtb_Subtract3_idx_0 > 1.57079637F) {
          rtb_Subtract3_idx_0 = 1.57079637F;
        } else {
          if (rtb_Subtract3_idx_0 < -1.57079637F) {
            rtb_Subtract3_idx_0 = -1.57079637F;
          }
        }

        /* End of Saturate: '<S155>/Saturation' */

        /* Delay: '<S146>/Delay' incorporates:
         *  Gain: '<S148>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        if (FMS_DW.icLoad_b != 0) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_DW.Delay_DSTATE = -FMS_U.INS_Out.h_R;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        }

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S141>/Bus Assignment'
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S141>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S141>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S141>/Constant3'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_g;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_i;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_j;
        FMS_Y.FMS_Out.u_cmd = 15.0F;

        /* Product: '<S155>/Divide' incorporates:
         *  Constant: '<S147>/L1'
         *  Gain: '<S155>/Gain'
         *  Math: '<S155>/Square'
         *  Product: '<S155>/Multiply1'
         *  Sqrt: '<S157>/Sqrt'
         *  Trigonometry: '<S155>/Sin'
         */
        rtb_Subtract3_idx_0 = 2.0F * (rtb_Subtract3_idx_1 * rtb_Subtract3_idx_1)
          * arm_sin_f32(rtb_Subtract3_idx_0) / FMS_PARAM.L1;

        /* Saturate: '<S150>/Saturation' */
        if (rtb_Subtract3_idx_0 > 9.81F) {
          /* BusAssignment: '<S141>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = 9.81F;
        } else if (rtb_Subtract3_idx_0 < -9.81F) {
          /* BusAssignment: '<S141>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = -9.81F;
        } else {
          /* BusAssignment: '<S141>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = rtb_Subtract3_idx_0;
        }

        /* End of Saturate: '<S150>/Saturation' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* BusAssignment: '<S141>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Delay: '<S146>/Delay'
         *  Gain: '<S146>/Gain2'
         *  Gain: '<S148>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  Outport: '<Root>/FMS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  Sum: '<S146>/Sum'
         */
        FMS_Y.FMS_Out.w_cmd = (FMS_DW.Delay_DSTATE - (-FMS_U.INS_Out.h_R)) *
          FMS_PARAM.Z_P;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Update for Delay: '<S151>/start_vel' */
        FMS_DW.icLoad_n = 0U;

        /* Update for Delay: '<S151>/start_wp' */
        FMS_DW.icLoad_m = 0U;

        /* Update for Delay: '<S146>/Delay' */
        FMS_DW.icLoad_b = 0U;

        /* End of Outputs for SubSystem: '<S24>/Hold' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S24>/Unknown' incorporates:
         *  ActionPort: '<S145>/Action Port'
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
       *  RelationalOperator: '<S115>/FixPt Relational Operator'
       *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy5Inport1'
       *  UnitDelay: '<S115>/Delay Input1'
       *
       * Block description for '<S115>/Delay Input1':
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
         *  ActionPort: '<S113>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S113>/Bus Assignment'
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S113>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S113>/Bus Assignment' incorporates:
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
           *  ActionPort: '<S112>/Action Port'
           */
          /* InitializeConditions for SwitchCase: '<S22>/Switch Case' incorporates:
           *  UnitDelay: '<S115>/Delay Input1'
           *
           * Block description for '<S115>/Delay Input1':
           *
           *  Store in Global RAM
           */
          FMS_DW.DelayInput1_DSTATE_pe = 0U;

          /* End of InitializeConditions for SubSystem: '<S22>/Mission' */
        }

        /* Outputs for IfAction SubSystem: '<S22>/Mission' incorporates:
         *  ActionPort: '<S112>/Action Port'
         */
        /* Outputs for Resettable SubSystem: '<S112>/Mission_SubSystem' incorporates:
         *  ResetPort: '<S116>/Reset'
         */
        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = (ZCSigState)(FMS_B.wp_index !=
          FMS_DW.DelayInput1_DSTATE_pe);

        /* Math: '<S134>/Math Function' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  RelationalOperator: '<S115>/FixPt Relational Operator'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy5Inport1'
         *  UnitDelay: '<S115>/Delay Input1'
         *
         * Block description for '<S115>/Delay Input1':
         *
         *  Store in Global RAM
         */
        rtb_Divide_f[0] = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn;
        rtb_Divide_f[1] = FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* Sum: '<S134>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S134>/Math Function'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_MathFunction1 = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Math: '<S134>/Math Function1' incorporates:
         *  Sum: '<S134>/Sum of Elements'
         *
         * About '<S134>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_MathFunction1 < 0.0F) {
          rtb_Subtract3_idx_0 = -sqrtf(fabsf(rtb_MathFunction1));
        } else {
          rtb_Subtract3_idx_0 = sqrtf(rtb_MathFunction1);
        }

        /* End of Math: '<S134>/Math Function1' */

        /* Switch: '<S134>/Switch' incorporates:
         *  Constant: '<S134>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S134>/Product'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        if (rtb_Subtract3_idx_0 > 0.0F) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_Switch_l[0] = FMS_U.INS_Out.vn;
          rtb_Switch_l[1] = FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          rtb_Switch_l[2] = rtb_Subtract3_idx_0;
        } else {
          rtb_Switch_l[0] = 0.0F;
          rtb_Switch_l[1] = 0.0F;
          rtb_Switch_l[2] = 1.0F;
        }

        /* End of Switch: '<S134>/Switch' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* MATLAB Function: '<S124>/NearbyRefWP' incorporates:
         *  Constant: '<S122>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_MathFunction_aq[0], FMS_U.INS_Out.x_R,
                        FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_Divide_f, &rtb_Sqrt);

        /* MATLAB Function: '<S124>/SearchL1RefWP' incorporates:
         *  Constant: '<S122>/L1'
         *  Inport: '<Root>/INS_Out'
         *  MATLAB Function: '<S124>/OutRegionRegWP'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S119>/Sum1'
         */
        rtb_Add3 = FMS_B.Cmd_In.sp_waypoint[0] - FMS_B.Cmd_In.cur_waypoint[0];
        rtb_Saturation_l = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        A = rtb_Add3 * rtb_Add3 + rtb_Saturation_l * rtb_Saturation_l;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        B = (rtb_Add3 * (FMS_B.Cmd_In.cur_waypoint[0] - FMS_U.INS_Out.x_R) +
             rtb_Saturation_l * (FMS_B.Cmd_In.cur_waypoint[1] -
              FMS_U.INS_Out.y_R)) * 2.0F;
        D = B * B - (((((FMS_U.INS_Out.x_R * FMS_U.INS_Out.x_R +
                         FMS_U.INS_Out.y_R * FMS_U.INS_Out.y_R) +
                        FMS_B.Cmd_In.cur_waypoint[0] *
                        FMS_B.Cmd_In.cur_waypoint[0]) +
                       FMS_B.Cmd_In.cur_waypoint[1] * FMS_B.Cmd_In.cur_waypoint
                       [1]) - (FMS_U.INS_Out.x_R * FMS_B.Cmd_In.cur_waypoint[0]
          + FMS_U.INS_Out.y_R * FMS_B.Cmd_In.cur_waypoint[1]) * 2.0F) -
                     FMS_PARAM.L1 * FMS_PARAM.L1) * (4.0F * A);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_MathFunction1 = -1.0F;
        rtb_Subtract3_idx_0 = 0.0F;
        rtb_Subtract3_idx_1 = 0.0F;
        guard1 = false;
        if (D > 0.0F) {
          u1_tmp = sqrtf(D);
          D = (-B + u1_tmp) / (2.0F * A);
          B = (-B - u1_tmp) / (2.0F * A);
          if ((D >= 0.0F) && (D <= 1.0F) && (B >= 0.0F) && (B <= 1.0F)) {
            rtb_MathFunction1 = fmaxf(D, B);
            guard1 = true;
          } else if ((D >= 0.0F) && (D <= 1.0F)) {
            rtb_MathFunction1 = D;
            guard1 = true;
          } else {
            if ((B >= 0.0F) && (B <= 1.0F)) {
              rtb_MathFunction1 = B;
              guard1 = true;
            }
          }
        } else {
          if (D == 0.0F) {
            D = -B / (2.0F * A);
            if ((D >= 0.0F) && (D <= 1.0F)) {
              rtb_MathFunction1 = D;
              guard1 = true;
            }
          }
        }

        if (guard1) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_Subtract3_idx_0 = rtb_Add3 * rtb_MathFunction1 +
            FMS_B.Cmd_In.cur_waypoint[0];
          rtb_Subtract3_idx_1 = rtb_Saturation_l * rtb_MathFunction1 +
            FMS_B.Cmd_In.cur_waypoint[1];

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        }

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* MATLAB Function: '<S124>/OutRegionRegWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S119>/Sum'
         */
        rtb_Sign1_n_idx_0 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
        rtb_Rem_o = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        B = (rtb_Rem_o * rtb_Saturation_l + rtb_Sign1_n_idx_0 * rtb_Add3) /
          (rtb_Add3 * rtb_Add3 + rtb_Saturation_l * rtb_Saturation_l);
        rtb_Compare_i = (B <= 0.0F);
        u = (B >= 1.0F);
        if (rtb_Compare_i) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_Rem_k = FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        } else if (u) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_Rem_k = FMS_B.Cmd_In.sp_waypoint[0];

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        } else {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_Rem_k = B * rtb_Add3 + FMS_B.Cmd_In.cur_waypoint[0];

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        }

        /* Switch: '<S124>/Switch1' incorporates:
         *  Constant: '<S127>/Constant'
         *  RelationalOperator: '<S127>/Compare'
         */
        if (rtb_Sqrt <= 0.0F) {
          /* Switch: '<S124>/Switch' incorporates:
           *  Constant: '<S126>/Constant'
           *  MATLAB Function: '<S124>/SearchL1RefWP'
           *  RelationalOperator: '<S126>/Compare'
           */
          if (rtb_MathFunction1 >= 0.0F) {
            rtb_Divide_f[0] = rtb_Subtract3_idx_0;
            rtb_Divide_f[1] = rtb_Subtract3_idx_1;
          } else {
            rtb_Divide_f[0] = rtb_Rem_k;

            /* MATLAB Function: '<S124>/OutRegionRegWP' incorporates:
             *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
             */
            if (rtb_Compare_i) {
              /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
              rtb_Divide_f[1] = FMS_B.Cmd_In.cur_waypoint[1];

              /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
            } else if (u) {
              /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
              rtb_Divide_f[1] = FMS_B.Cmd_In.sp_waypoint[1];

              /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
            } else {
              /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
              rtb_Divide_f[1] = B * rtb_Saturation_l +
                FMS_B.Cmd_In.cur_waypoint[1];

              /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
            }
          }

          /* End of Switch: '<S124>/Switch' */
        }

        /* End of Switch: '<S124>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S125>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_Divide_fw[0] = rtb_Divide_f[0] - FMS_U.INS_Out.x_R;
        rtb_Divide_fw[1] = rtb_Divide_f[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Sum: '<S135>/Sum of Elements' incorporates:
         *  Math: '<S135>/Math Function'
         */
        rtb_MathFunction1 = rtb_Divide_fw[0] * rtb_Divide_fw[0] + rtb_Divide_fw
          [1] * rtb_Divide_fw[1];

        /* Math: '<S135>/Math Function1' incorporates:
         *  Sum: '<S135>/Sum of Elements'
         *
         * About '<S135>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_MathFunction1 < 0.0F) {
          rtb_Subtract3_idx_0 = -sqrtf(fabsf(rtb_MathFunction1));
        } else {
          rtb_Subtract3_idx_0 = sqrtf(rtb_MathFunction1);
        }

        /* End of Math: '<S135>/Math Function1' */

        /* Switch: '<S135>/Switch' incorporates:
         *  Constant: '<S135>/Constant'
         *  Product: '<S135>/Product'
         */
        if (rtb_Subtract3_idx_0 > 0.0F) {
          rtb_MathFunction_aq[0] = rtb_Divide_fw[0];
          rtb_MathFunction_aq[1] = rtb_Divide_fw[1];
          rtb_MathFunction_aq[2] = rtb_Subtract3_idx_0;
        } else {
          rtb_MathFunction_aq[0] = 0.0F;
          rtb_MathFunction_aq[1] = 0.0F;
          rtb_MathFunction_aq[2] = 1.0F;
        }

        /* End of Switch: '<S135>/Switch' */

        /* Product: '<S134>/Divide' */
        rtb_Divide_fw[0] = rtb_Switch_l[0] / rtb_Switch_l[2];
        rtb_Divide_fw[1] = rtb_Switch_l[1] / rtb_Switch_l[2];

        /* Sum: '<S137>/Sum of Elements' incorporates:
         *  Math: '<S137>/Math Function'
         *  SignalConversion: '<S137>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_MathFunction1 = rtb_Divide_fw[1] * rtb_Divide_fw[1] + rtb_Divide_fw
          [0] * rtb_Divide_fw[0];

        /* Math: '<S137>/Math Function1' incorporates:
         *  Sum: '<S137>/Sum of Elements'
         *
         * About '<S137>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_MathFunction1 < 0.0F) {
          rtb_Subtract3_idx_0 = -sqrtf(fabsf(rtb_MathFunction1));
        } else {
          rtb_Subtract3_idx_0 = sqrtf(rtb_MathFunction1);
        }

        /* End of Math: '<S137>/Math Function1' */

        /* Switch: '<S137>/Switch' incorporates:
         *  Constant: '<S137>/Constant'
         *  Product: '<S137>/Product'
         */
        if (rtb_Subtract3_idx_0 > 0.0F) {
          rtb_Switch_l[0] = rtb_Divide_fw[1];
          rtb_Switch_l[1] = rtb_Divide_fw[0];
          rtb_Switch_l[2] = rtb_Subtract3_idx_0;
        } else {
          rtb_Switch_l[0] = 0.0F;
          rtb_Switch_l[1] = 0.0F;
          rtb_Switch_l[2] = 1.0F;
        }

        /* End of Switch: '<S137>/Switch' */

        /* Product: '<S135>/Divide' */
        rtb_Divide_fw[0] = rtb_MathFunction_aq[0] / rtb_MathFunction_aq[2];
        rtb_Divide_fw[1] = rtb_MathFunction_aq[1] / rtb_MathFunction_aq[2];

        /* Sum: '<S138>/Sum of Elements' incorporates:
         *  Math: '<S138>/Math Function'
         *  SignalConversion: '<S138>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_MathFunction1 = rtb_Divide_fw[1] * rtb_Divide_fw[1] + rtb_Divide_fw
          [0] * rtb_Divide_fw[0];

        /* Math: '<S138>/Math Function1' incorporates:
         *  Sum: '<S138>/Sum of Elements'
         *
         * About '<S138>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_MathFunction1 < 0.0F) {
          rtb_Subtract3_idx_0 = -sqrtf(fabsf(rtb_MathFunction1));
        } else {
          rtb_Subtract3_idx_0 = sqrtf(rtb_MathFunction1);
        }

        /* End of Math: '<S138>/Math Function1' */

        /* Switch: '<S138>/Switch' incorporates:
         *  Constant: '<S138>/Constant'
         *  Product: '<S138>/Product'
         */
        if (rtb_Subtract3_idx_0 > 0.0F) {
          rtb_MathFunction_aq[0] = rtb_Divide_fw[1];
          rtb_MathFunction_aq[1] = rtb_Divide_fw[0];
          rtb_MathFunction_aq[2] = rtb_Subtract3_idx_0;
        } else {
          rtb_MathFunction_aq[0] = 0.0F;
          rtb_MathFunction_aq[1] = 0.0F;
          rtb_MathFunction_aq[2] = 1.0F;
        }

        /* End of Switch: '<S138>/Switch' */

        /* Product: '<S138>/Divide' */
        rtb_Divide_fw[0] = rtb_MathFunction_aq[0] / rtb_MathFunction_aq[2];

        /* Product: '<S137>/Divide' */
        rtb_Divide_f[0] = rtb_Switch_l[0] / rtb_Switch_l[2];

        /* Product: '<S138>/Divide' */
        rtb_Divide_fw[1] = rtb_MathFunction_aq[1] / rtb_MathFunction_aq[2];

        /* Product: '<S137>/Divide' */
        rtb_Divide_f[1] = rtb_Switch_l[1] / rtb_Switch_l[2];

        /* Product: '<S119>/Divide' incorporates:
         *  Math: '<S120>/Square'
         *  Math: '<S121>/Square'
         *  Sqrt: '<S120>/Sqrt'
         *  Sqrt: '<S121>/Sqrt'
         *  Sum: '<S120>/Sum of Elements'
         *  Sum: '<S121>/Sum of Elements'
         */
        rtb_Subtract3_idx_1 = sqrtf(rtb_Rem_o * rtb_Rem_o + rtb_Sign1_n_idx_0 *
          rtb_Sign1_n_idx_0) / sqrtf(rtb_Add3 * rtb_Add3 + rtb_Saturation_l *
          rtb_Saturation_l);

        /* Saturate: '<S119>/Saturation' */
        if (rtb_Subtract3_idx_1 > 1.0F) {
          rtb_Subtract3_idx_1 = 1.0F;
        } else {
          if (rtb_Subtract3_idx_1 < 0.0F) {
            rtb_Subtract3_idx_1 = 0.0F;
          }
        }

        /* End of Saturate: '<S119>/Saturation' */

        /* Sum: '<S136>/Subtract' incorporates:
         *  Product: '<S136>/Multiply'
         *  Product: '<S136>/Multiply1'
         */
        rtb_Subtract3_idx_0 = rtb_Divide_fw[0] * rtb_Divide_f[1] -
          rtb_Divide_fw[1] * rtb_Divide_f[0];

        /* Signum: '<S132>/Sign1' */
        if (rtb_Subtract3_idx_0 < 0.0F) {
          rtb_Subtract3_idx_0 = -1.0F;
        } else {
          if (rtb_Subtract3_idx_0 > 0.0F) {
            rtb_Subtract3_idx_0 = 1.0F;
          }
        }

        /* End of Signum: '<S132>/Sign1' */

        /* Switch: '<S132>/Switch2' incorporates:
         *  Constant: '<S132>/Constant4'
         */
        if (rtb_Subtract3_idx_0 == 0.0F) {
          rtb_Subtract3_idx_0 = 1.0F;
        }

        /* End of Switch: '<S132>/Switch2' */

        /* DotProduct: '<S132>/Dot Product' */
        rtb_Saturation_l = rtb_Divide_f[0] * rtb_Divide_fw[0] + rtb_Divide_f[1] *
          rtb_Divide_fw[1];

        /* Trigonometry: '<S132>/Acos' incorporates:
         *  DotProduct: '<S132>/Dot Product'
         */
        if (rtb_Saturation_l > 1.0F) {
          rtb_Saturation_l = 1.0F;
        } else {
          if (rtb_Saturation_l < -1.0F) {
            rtb_Saturation_l = -1.0F;
          }
        }

        /* Product: '<S132>/Multiply' incorporates:
         *  Trigonometry: '<S132>/Acos'
         */
        rtb_Subtract3_idx_0 *= acosf(rtb_Saturation_l);

        /* Saturate: '<S131>/Saturation' */
        if (rtb_Subtract3_idx_0 > 1.57079637F) {
          rtb_Subtract3_idx_0 = 1.57079637F;
        } else {
          if (rtb_Subtract3_idx_0 < -1.57079637F) {
            rtb_Subtract3_idx_0 = -1.57079637F;
          }
        }

        /* End of Saturate: '<S131>/Saturation' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sqrt: '<S133>/Sqrt' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S133>/Square'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  Sum: '<S133>/Sum of Elements'
         */
        rtb_Sqrt = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn + FMS_U.INS_Out.ve *
                         FMS_U.INS_Out.ve);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S116>/Bus Assignment'
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S116>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S116>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S116>/Constant4'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_l;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_b;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_by;
        FMS_Y.FMS_Out.u_cmd = FMS_PARAM.CRUISE_SPEED;

        /* Product: '<S131>/Divide' incorporates:
         *  Constant: '<S122>/L1'
         *  Gain: '<S131>/Gain'
         *  Math: '<S131>/Square'
         *  Product: '<S131>/Multiply1'
         *  Sqrt: '<S133>/Sqrt'
         *  Trigonometry: '<S131>/Sin'
         */
        rtb_Subtract3_idx_0 = rtb_Sqrt * rtb_Sqrt * 2.0F * arm_sin_f32
          (rtb_Subtract3_idx_0) / FMS_PARAM.L1;

        /* Saturate: '<S122>/Saturation1' */
        if (rtb_Subtract3_idx_0 > FMS_PARAM.ACC_Y_LIM) {
          /* BusAssignment: '<S116>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.ACC_Y_LIM;
        } else if (rtb_Subtract3_idx_0 < -FMS_PARAM.ACC_Y_LIM) {
          /* BusAssignment: '<S116>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.ACC_Y_LIM;
        } else {
          /* BusAssignment: '<S116>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = rtb_Subtract3_idx_0;
        }

        /* End of Saturate: '<S122>/Saturation1' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Gain: '<S117>/Gain' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S119>/Multiply'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S117>/Sum2'
         *  Sum: '<S119>/Add'
         *  Sum: '<S119>/Subtract'
         */
        rtb_Subtract3_idx_0 = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2]
          - FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Subtract3_idx_1 +
          FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Saturate: '<S117>/Saturation1' */
        if (rtb_Subtract3_idx_0 > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S116>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (rtb_Subtract3_idx_0 < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S116>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S116>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = rtb_Subtract3_idx_0;
        }

        /* End of Saturate: '<S117>/Saturation1' */
        /* End of Outputs for SubSystem: '<S112>/Mission_SubSystem' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Update for UnitDelay: '<S115>/Delay Input1' incorporates:
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy5Inport1'
         *
         * Block description for '<S115>/Delay Input1':
         *
         *  Store in Global RAM
         */
        FMS_DW.DelayInput1_DSTATE_pe = FMS_B.wp_index;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        /* End of Outputs for SubSystem: '<S22>/Mission' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S22>/Unknown' incorporates:
         *  ActionPort: '<S114>/Action Port'
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
          /* Disable for SwitchCase: '<S37>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_m = -1;
          break;

         case 3:
          /* Disable for SwitchCase: '<S72>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

          /* Disable for SwitchCase: '<S58>/Switch Case' */
          FMS_DW.SwitchCase_ActiveSubsystem_ba = -1;
          break;
        }
      }

      switch (FMS_DW.SwitchCase_ActiveSubsystem_f) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S21>/Acro' incorporates:
         *  ActionPort: '<S26>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  BusAssignment: '<S26>/Bus Assignment'
         *  Constant: '<S26>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S26>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Gain: '<S31>/Gain'
         *  Gain: '<S31>/Gain1'
         *  Gain: '<S31>/Gain2'
         *  Inport: '<Root>/Pilot_Cmd'
         *  Outport: '<Root>/FMS_Out'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_j;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_do;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_b;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        FMS_Y.FMS_Out.p_cmd = 3.14159274F * FMS_U.Pilot_Cmd.stick_roll;
        FMS_Y.FMS_Out.q_cmd = -3.14159274F * FMS_U.Pilot_Cmd.stick_pitch;
        FMS_Y.FMS_Out.r_cmd = 1.57079637F * FMS_U.Pilot_Cmd.stick_yaw;

        /* Saturate: '<S32>/Saturation' incorporates:
         *  Constant: '<S32>/Constant4'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         *  Sum: '<S32>/Sum'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
          rtb_MathFunction1 = 2.0F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
          rtb_MathFunction1 = 0.0F;
        } else {
          rtb_MathFunction1 = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
        }

        /* End of Saturate: '<S32>/Saturation' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* BusAssignment: '<S26>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S32>/Constant5'
         *  Gain: '<S32>/Gain2'
         *  Outport: '<Root>/FMS_Out'
         *  Sum: '<S32>/Add'
         */
        FMS_Y.FMS_Out.throttle_cmd = (uint32_T)fmodf(floorf(500.0F *
          rtb_MathFunction1), 4.2949673E+9F) + 1000U;

        /* End of Outputs for SubSystem: '<S21>/Acro' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S21>/Stabilize' incorporates:
         *  ActionPort: '<S29>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  BusAssignment: '<S29>/Bus Assignment'
         *  Constant: '<S29>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S29>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_ba;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_k;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_o;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* DeadZone: '<S103>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          rtb_MathFunction1 = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_MathFunction1 = 0.0F;
        } else {
          rtb_MathFunction1 = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S103>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* BusAssignment: '<S29>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Gain: '<S100>/Gain'
         *  Gain: '<S103>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.phi_cmd = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) *
          rtb_MathFunction1 * FMS_PARAM.ROLL_LIM;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* DeadZone: '<S104>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          rtb_MathFunction1 = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          rtb_MathFunction1 = 0.0F;
        } else {
          rtb_MathFunction1 = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
        }

        /* End of DeadZone: '<S104>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* BusAssignment: '<S29>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Gain: '<S100>/Gain1'
         *  Gain: '<S104>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.theta_cmd = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) *
          rtb_MathFunction1 * -FMS_PARAM.PITCH_LIM;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* DeadZone: '<S109>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
          rtb_MathFunction1 = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
          rtb_MathFunction1 = 0.0F;
        } else {
          rtb_MathFunction1 = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
        }

        /* End of DeadZone: '<S109>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* BusAssignment: '<S29>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Gain: '<S101>/Gain1'
         *  Gain: '<S109>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.psi_rate_cmd = 1.0F / (1.0F - FMS_PARAM.YAW_DZ) *
          rtb_MathFunction1 * FMS_PARAM.YAW_RATE_LIM;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Saturate: '<S102>/Saturation' incorporates:
         *  Constant: '<S102>/Constant4'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         *  Sum: '<S102>/Sum'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
          rtb_MathFunction1 = 2.0F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
          rtb_MathFunction1 = 0.0F;
        } else {
          rtb_MathFunction1 = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
        }

        /* End of Saturate: '<S102>/Saturation' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* BusAssignment: '<S29>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S102>/Constant5'
         *  Gain: '<S102>/Gain2'
         *  Outport: '<Root>/FMS_Out'
         *  Sum: '<S102>/Add'
         */
        FMS_Y.FMS_Out.throttle_cmd = (uint32_T)fmodf(floorf(500.0F *
          rtb_MathFunction1), 4.2949673E+9F) + 1000U;

        /* End of Outputs for SubSystem: '<S21>/Stabilize' */
        break;

       case 2:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S21>/Altitude' incorporates:
           *  ActionPort: '<S27>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S21>/Switch Case' incorporates:
           *  Chart: '<S38>/Motion Status'
           */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_b);

          /* End of SystemReset for SubSystem: '<S21>/Altitude' */
        }

        /* Outputs for IfAction SubSystem: '<S21>/Altitude' incorporates:
         *  ActionPort: '<S27>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Chart: '<S38>/Motion Status' incorporates:
         *  Abs: '<S38>/Abs'
         *  Abs: '<S38>/Abs1'
         *  Constant: '<S46>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S46>/Compare'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_pitch) > FMS_PARAM.PITCH_DZ,
                         fabsf(FMS_U.INS_Out.vd), &rtb_state_a,
                         &FMS_DW.sf_MotionStatus_b);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* SwitchCase: '<S37>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_m;
        FMS_DW.SwitchCase_ActiveSubsystem_m = -1;
        switch (rtb_state_a) {
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
            /* SystemReset for IfAction SubSystem: '<S37>/Hold Control' incorporates:
             *  ActionPort: '<S40>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S37>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_k2);

            /* End of SystemReset for SubSystem: '<S37>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S37>/Hold Control' incorporates:
           *  ActionPort: '<S40>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_l,
                          &FMS_DW.HoldControl_k2);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S37>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S37>/Brake Control' incorporates:
           *  ActionPort: '<S39>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge_l);

          /* End of Outputs for SubSystem: '<S37>/Brake Control' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S37>/Move Control' incorporates:
           *  ActionPort: '<S41>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_pitch, &FMS_B.Merge_l);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S37>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S37>/Switch Case' */

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
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion1_d;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion2_n;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion3;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* DeadZone: '<S48>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
          rtb_MathFunction1 = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_MathFunction1 = 0.0F;
        } else {
          rtb_MathFunction1 = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
        }

        /* End of DeadZone: '<S48>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* BusAssignment: '<S27>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Gain: '<S35>/Gain'
         *  Gain: '<S48>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.phi_cmd = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) *
          rtb_MathFunction1 * FMS_PARAM.ROLL_LIM;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* DeadZone: '<S51>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
          rtb_MathFunction1 = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
          rtb_MathFunction1 = 0.0F;
        } else {
          rtb_MathFunction1 = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
        }

        /* End of DeadZone: '<S51>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* BusAssignment: '<S27>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Gain: '<S36>/Gain1'
         *  Gain: '<S51>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.psi_rate_cmd = 1.0F / (1.0F - FMS_PARAM.YAW_DZ) *
          rtb_MathFunction1 * FMS_PARAM.YAW_RATE_LIM;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Gain: '<S33>/Gain1' incorporates:
         *  Bias: '<S33>/Bias'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        rtb_Sqrt = (FMS_U.Pilot_Cmd.stick_throttle + 1.0F) * 0.5F;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Saturate: '<S33>/Saturation' incorporates:
         *  Gain: '<S33>/Gain1'
         */
        if (rtb_Sqrt > 1.0F) {
          rtb_Sqrt = 1.0F;
        } else {
          if (rtb_Sqrt < 0.0F) {
            rtb_Sqrt = 0.0F;
          }
        }

        /* End of Saturate: '<S33>/Saturation' */

        /* BusAssignment: '<S27>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Gain: '<S33>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_AIRSPD_MAX * rtb_Sqrt;

        /* Saturate: '<S37>/Saturation1' */
        if (FMS_B.Merge_l > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S27>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge_l < -FMS_PARAM.VEL_Z_LIM) {
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
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge_l;
        }

        /* End of Saturate: '<S37>/Saturation1' */
        /* End of Outputs for SubSystem: '<S21>/Altitude' */
        break;

       case 3:
        if (FMS_DW.SwitchCase_ActiveSubsystem_f != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S21>/Position' incorporates:
           *  ActionPort: '<S28>/Action Port'
           */
          /* SystemReset for SwitchCase: '<S21>/Switch Case' incorporates:
           *  Chart: '<S59>/Motion Status'
           *  Chart: '<S73>/Motion State'
           */
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus_j);
          FMS_DW.temporalCounter_i1_i = 0U;
          FMS_DW.is_active_c16_FMS = 0U;
          FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_o;

          /* End of SystemReset for SubSystem: '<S21>/Position' */
        }

        /* Outputs for IfAction SubSystem: '<S21>/Position' incorporates:
         *  ActionPort: '<S28>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Trigonometry: '<S99>/Trigonometric Function1' incorporates:
         *  Gain: '<S98>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_VectorConcatenate_hm[0] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S99>/Trigonometric Function' incorporates:
         *  Gain: '<S98>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_VectorConcatenate_hm[1] = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* SignalConversion: '<S99>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S99>/Constant3'
         */
        rtb_VectorConcatenate_hm[2] = 0.0F;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Gain: '<S99>/Gain' incorporates:
         *  Gain: '<S98>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  Trigonometry: '<S99>/Trigonometric Function2'
         */
        rtb_VectorConcatenate_hm[3] = -arm_sin_f32(-FMS_U.INS_Out.psi);

        /* Trigonometry: '<S99>/Trigonometric Function3' incorporates:
         *  Gain: '<S98>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_VectorConcatenate_hm[4] = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* SignalConversion: '<S99>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S99>/Constant4'
         */
        rtb_VectorConcatenate_hm[5] = 0.0F;

        /* SignalConversion: '<S99>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_VectorConcatenate_hm[6] = FMS_ConstB.VectorConcatenate3[0];
        rtb_VectorConcatenate_hm[7] = FMS_ConstB.VectorConcatenate3[1];
        rtb_VectorConcatenate_hm[8] = FMS_ConstB.VectorConcatenate3[2];

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Chart: '<S59>/Motion Status' incorporates:
         *  Abs: '<S59>/Abs'
         *  Abs: '<S59>/Abs1'
         *  Constant: '<S67>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  RelationalOperator: '<S67>/Compare'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        FMS_MotionStatus(fabsf(FMS_U.Pilot_Cmd.stick_pitch) > FMS_PARAM.PITCH_DZ,
                         fabsf(FMS_U.INS_Out.vd), &rtb_state_a,
                         &FMS_DW.sf_MotionStatus_j);

        /* RelationalOperator: '<S96>/Compare' incorporates:
         *  Abs: '<S73>/Abs1'
         *  Constant: '<S96>/Constant'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        rtb_Compare_i = (fabsf(FMS_U.Pilot_Cmd.stick_roll) > FMS_PARAM.ROLL_DZ);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Chart: '<S73>/Motion State' incorporates:
         *  Abs: '<S73>/Abs'
         */
        if (FMS_DW.temporalCounter_i1_i < 1023U) {
          FMS_DW.temporalCounter_i1_i++;
        }

        if (FMS_DW.is_active_c16_FMS == 0U) {
          FMS_DW.is_active_c16_FMS = 1U;
          FMS_DW.is_c16_FMS = FMS_IN_Move_j;
          rtb_state = MotionState_Move;
        } else {
          switch (FMS_DW.is_c16_FMS) {
           case FMS_IN_Brake_o:
            rtb_state = MotionState_Brake;

            /* Product: '<S73>/Multiply' incorporates:
             *  Inport: '<Root>/INS_Out'
             *  SignalConversion: '<S16>/Signal Copy1'
             */
            for (i = 0; i < 3; i++) {
              /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
              rtb_VectorConcatenate_a[i] = rtb_VectorConcatenate_hm[i + 6] *
                FMS_U.INS_Out.vd + (rtb_VectorConcatenate_hm[i + 3] *
                                    FMS_U.INS_Out.ve +
                                    rtb_VectorConcatenate_hm[i] *
                                    FMS_U.INS_Out.vn);

              /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
            }

            /* End of Product: '<S73>/Multiply' */
            if ((fabsf(rtb_VectorConcatenate_a[1]) <= 0.2) ||
                (FMS_DW.temporalCounter_i1_i >= 625U)) {
              FMS_DW.is_c16_FMS = FMS_IN_Hold_h;
              rtb_state = MotionState_Hold;
            } else {
              if (rtb_Compare_i) {
                FMS_DW.is_c16_FMS = FMS_IN_Move_j;
                rtb_state = MotionState_Move;
              }
            }
            break;

           case FMS_IN_Hold_h:
            rtb_state = MotionState_Hold;
            if (rtb_Compare_i) {
              FMS_DW.is_c16_FMS = FMS_IN_Move_j;
              rtb_state = MotionState_Move;
            }
            break;

           default:
            rtb_state = MotionState_Move;
            if (!rtb_Compare_i) {
              FMS_DW.is_c16_FMS = FMS_IN_Brake_o;
              FMS_DW.temporalCounter_i1_i = 0U;
              rtb_state = MotionState_Brake;
            }
            break;
          }
        }

        /* End of Chart: '<S73>/Motion State' */

        /* SwitchCase: '<S72>/Switch Case' incorporates:
         *  Math: '<S86>/Square'
         *  Product: '<S92>/Divide'
         *  Sum: '<S78>/Subtract'
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
            /* InitializeConditions for IfAction SubSystem: '<S72>/Hold Control' incorporates:
             *  ActionPort: '<S75>/Action Port'
             */
            /* InitializeConditions for SwitchCase: '<S72>/Switch Case' incorporates:
             *  Delay: '<S79>/start_vel'
             *  Delay: '<S79>/start_wp'
             */
            FMS_DW.icLoad = 1U;
            FMS_DW.icLoad_c = 1U;

            /* End of InitializeConditions for SubSystem: '<S72>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S72>/Hold Control' incorporates:
           *  ActionPort: '<S75>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Sum: '<S87>/Sum of Elements' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S87>/Math Function'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          rtb_MathFunction1 = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Math: '<S87>/Math Function1' incorporates:
           *  Sum: '<S87>/Sum of Elements'
           *
           * About '<S87>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_MathFunction1 < 0.0F) {
            rtb_Subtract3_idx_1 = -sqrtf(fabsf(rtb_MathFunction1));
          } else {
            rtb_Subtract3_idx_1 = sqrtf(rtb_MathFunction1);
          }

          /* End of Math: '<S87>/Math Function1' */

          /* Switch: '<S87>/Switch' incorporates:
           *  Constant: '<S87>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S87>/Product'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          if (rtb_Subtract3_idx_1 > 0.0F) {
            /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
            rtb_Switch_l[0] = FMS_U.INS_Out.vn;
            rtb_Switch_l[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
            rtb_Switch_l[2] = rtb_Subtract3_idx_1;
          } else {
            rtb_Switch_l[0] = 0.0F;
            rtb_Switch_l[1] = 0.0F;
            rtb_Switch_l[2] = 1.0F;
          }

          /* End of Switch: '<S87>/Switch' */

          /* Delay: '<S79>/start_vel' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          if (FMS_DW.icLoad != 0) {
            /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
            FMS_DW.start_vel_DSTATE[0] = FMS_U.INS_Out.vn;
            FMS_DW.start_vel_DSTATE[1] = FMS_U.INS_Out.ve;

            /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          }

          /* Sum: '<S92>/Sum of Elements' incorporates:
           *  Delay: '<S79>/start_vel'
           *  Math: '<S92>/Math Function'
           */
          rtb_MathFunction1 = FMS_DW.start_vel_DSTATE[0] *
            FMS_DW.start_vel_DSTATE[0] + FMS_DW.start_vel_DSTATE[1] *
            FMS_DW.start_vel_DSTATE[1];

          /* Math: '<S92>/Math Function1' incorporates:
           *  Sum: '<S92>/Sum of Elements'
           *
           * About '<S92>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_MathFunction1 < 0.0F) {
            rtb_Subtract3_idx_1 = -sqrtf(fabsf(rtb_MathFunction1));
          } else {
            rtb_Subtract3_idx_1 = sqrtf(rtb_MathFunction1);
          }

          /* End of Math: '<S92>/Math Function1' */

          /* Switch: '<S92>/Switch' incorporates:
           *  Constant: '<S92>/Constant'
           *  Delay: '<S79>/start_vel'
           *  Product: '<S92>/Product'
           */
          if (rtb_Subtract3_idx_1 > 0.0F) {
            rtb_MathFunction_aq[0] = FMS_DW.start_vel_DSTATE[0];
            rtb_MathFunction_aq[1] = FMS_DW.start_vel_DSTATE[1];
            rtb_MathFunction_aq[2] = rtb_Subtract3_idx_1;
          } else {
            rtb_MathFunction_aq[0] = 0.0F;
            rtb_MathFunction_aq[1] = 0.0F;
            rtb_MathFunction_aq[2] = 1.0F;
          }

          /* End of Switch: '<S92>/Switch' */

          /* Product: '<S87>/Divide' */
          rtb_Divide_f[0] = rtb_Switch_l[0] / rtb_Switch_l[2];
          rtb_Divide_f[1] = rtb_Switch_l[1] / rtb_Switch_l[2];

          /* Sum: '<S90>/Sum of Elements' incorporates:
           *  Math: '<S90>/Math Function'
           *  SignalConversion: '<S90>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_MathFunction1 = rtb_Divide_f[1] * rtb_Divide_f[1] + rtb_Divide_f[0]
            * rtb_Divide_f[0];

          /* Math: '<S90>/Math Function1' incorporates:
           *  Sum: '<S90>/Sum of Elements'
           *
           * About '<S90>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_MathFunction1 < 0.0F) {
            rtb_Subtract3_idx_1 = -sqrtf(fabsf(rtb_MathFunction1));
          } else {
            rtb_Subtract3_idx_1 = sqrtf(rtb_MathFunction1);
          }

          /* End of Math: '<S90>/Math Function1' */

          /* Switch: '<S90>/Switch' incorporates:
           *  Constant: '<S90>/Constant'
           *  Product: '<S90>/Product'
           */
          if (rtb_Subtract3_idx_1 > 0.0F) {
            rtb_Switch_l[0] = rtb_Divide_f[1];
            rtb_Switch_l[1] = rtb_Divide_f[0];
            rtb_Switch_l[2] = rtb_Subtract3_idx_1;
          } else {
            rtb_Switch_l[0] = 0.0F;
            rtb_Switch_l[1] = 0.0F;
            rtb_Switch_l[2] = 1.0F;
          }

          /* End of Switch: '<S90>/Switch' */

          /* Delay: '<S79>/start_wp' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          if (FMS_DW.icLoad_c != 0) {
            /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
            FMS_DW.start_wp_DSTATE[0] = FMS_U.INS_Out.x_R;
            FMS_DW.start_wp_DSTATE[1] = FMS_U.INS_Out.y_R;

            /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          }

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* MATLAB Function: '<S77>/SearchL1RefWP' incorporates:
           *  Delay: '<S79>/start_wp'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          rtb_Divide_f[0] = FMS_DW.start_wp_DSTATE[0] - FMS_U.INS_Out.x_R;
          rtb_Divide_f[1] = FMS_DW.start_wp_DSTATE[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Product: '<S92>/Divide' */
          rtb_Sqrt = rtb_MathFunction_aq[0] / rtb_MathFunction_aq[2];

          /* MATLAB Function: '<S77>/SearchL1RefWP' */
          rtb_Subtract3_idx_0 = rtb_Sqrt * rtb_Divide_f[0];
          rtb_Sign1_n_idx_0 = rtb_Sqrt;

          /* Product: '<S92>/Divide' */
          rtb_Sqrt = rtb_MathFunction_aq[1] / rtb_MathFunction_aq[2];

          /* MATLAB Function: '<S77>/SearchL1RefWP' incorporates:
           *  Constant: '<S75>/L1'
           *  Delay: '<S79>/start_wp'
           */
          rtb_Subtract3_idx_0 += rtb_Sqrt * rtb_Divide_f[1];
          B = 2.0F * rtb_Subtract3_idx_0;
          rtb_Subtract3_idx_0 = 0.0F;
          rtb_Subtract3_idx_1 = 0.0F;
          D = B * B - ((rtb_Divide_f[0] * rtb_Divide_f[0] + rtb_Divide_f[1] *
                        rtb_Divide_f[1]) - FMS_PARAM.L1 * FMS_PARAM.L1) * 4.0F;
          rtb_Add3 = -1.0F;
          if (D > 0.0F) {
            rtb_Subtract3_idx_0 = sqrtf(D);
            rtb_Add3 = fmaxf((-B + rtb_Subtract3_idx_0) / 2.0F, (-B -
              rtb_Subtract3_idx_0) / 2.0F);
            rtb_Subtract3_idx_0 = rtb_Add3 * rtb_Sign1_n_idx_0 +
              FMS_DW.start_wp_DSTATE[0];
            rtb_Subtract3_idx_1 = rtb_Add3 * rtb_Sqrt + FMS_DW.start_wp_DSTATE[1];
          } else {
            if (D == 0.0F) {
              rtb_Add3 = -B / 2.0F;
              rtb_Subtract3_idx_0 = rtb_Add3 * rtb_Sign1_n_idx_0 +
                FMS_DW.start_wp_DSTATE[0];
              rtb_Subtract3_idx_1 = rtb_Add3 * rtb_Sqrt +
                FMS_DW.start_wp_DSTATE[1];
            }
          }

          /* RelationalOperator: '<S80>/Compare' incorporates:
           *  Constant: '<S80>/Constant'
           *  MATLAB Function: '<S77>/SearchL1RefWP'
           */
          rtb_Compare_i = (rtb_Add3 > 0.0F);

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* MATLAB Function: '<S77>/OutRegionRefWP' incorporates:
           *  Delay: '<S79>/start_wp'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          rtb_Add3 = (FMS_U.INS_Out.x_R - FMS_DW.start_wp_DSTATE[0]) *
            rtb_Sign1_n_idx_0 + (FMS_U.INS_Out.y_R - FMS_DW.start_wp_DSTATE[1]) *
            rtb_Sqrt;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          rtb_MathFunction1 = 1.29246971E-26F;

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_Saturation_l = fabsf((rtb_Add3 * rtb_Sign1_n_idx_0 +
            FMS_DW.start_wp_DSTATE[0]) - FMS_U.INS_Out.x_R);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          if (rtb_Saturation_l > 1.29246971E-26F) {
            B = 1.0F;
            rtb_MathFunction1 = rtb_Saturation_l;
          } else {
            rtb_Rem_k = rtb_Saturation_l / 1.29246971E-26F;
            B = rtb_Rem_k * rtb_Rem_k;
          }

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          rtb_Saturation_l = fabsf((rtb_Add3 * rtb_Sqrt +
            FMS_DW.start_wp_DSTATE[1]) - FMS_U.INS_Out.y_R);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          if (rtb_Saturation_l > rtb_MathFunction1) {
            rtb_Rem_k = rtb_MathFunction1 / rtb_Saturation_l;
            B = B * rtb_Rem_k * rtb_Rem_k + 1.0F;
            rtb_MathFunction1 = rtb_Saturation_l;
          } else {
            rtb_Rem_k = rtb_Saturation_l / rtb_MathFunction1;
            B += rtb_Rem_k * rtb_Rem_k;
          }

          B = rtb_MathFunction1 * sqrtf(B);
          rtb_Add3 += B * 0.577350259F;

          /* Switch: '<S77>/Switch' incorporates:
           *  Delay: '<S79>/start_wp'
           *  MATLAB Function: '<S77>/OutRegionRefWP'
           */
          if (!rtb_Compare_i) {
            rtb_Subtract3_idx_0 = rtb_Add3 * rtb_Sign1_n_idx_0 +
              FMS_DW.start_wp_DSTATE[0];
            rtb_Subtract3_idx_1 = rtb_Add3 * rtb_Sqrt + FMS_DW.start_wp_DSTATE[1];
          }

          /* End of Switch: '<S77>/Switch' */

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Sum: '<S78>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          rtb_Saturation_l = rtb_Subtract3_idx_0 - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Math: '<S88>/Math Function' */
          rtb_Divide_f[0] = rtb_Saturation_l * rtb_Saturation_l;
          rtb_Subtract3_idx_0 = rtb_Saturation_l;

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Sum: '<S78>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          rtb_Saturation_l = rtb_Subtract3_idx_1 - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Math: '<S88>/Math Function' incorporates:
           *  Math: '<S86>/Square'
           */
          rtb_MathFunction1 = rtb_Saturation_l * rtb_Saturation_l;

          /* Sum: '<S88>/Sum of Elements' incorporates:
           *  Math: '<S88>/Math Function'
           */
          rtb_Sign1_n_idx_0 = rtb_MathFunction1 + rtb_Divide_f[0];

          /* Math: '<S88>/Math Function1' incorporates:
           *  Sum: '<S88>/Sum of Elements'
           *
           * About '<S88>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Sign1_n_idx_0 < 0.0F) {
            rtb_Subtract3_idx_1 = -sqrtf(fabsf(rtb_Sign1_n_idx_0));
          } else {
            rtb_Subtract3_idx_1 = sqrtf(rtb_Sign1_n_idx_0);
          }

          /* End of Math: '<S88>/Math Function1' */

          /* Switch: '<S88>/Switch' incorporates:
           *  Constant: '<S88>/Constant'
           *  Product: '<S88>/Product'
           */
          if (rtb_Subtract3_idx_1 > 0.0F) {
            rtb_MathFunction_aq[0] = rtb_Subtract3_idx_0;
            rtb_MathFunction_aq[1] = rtb_Saturation_l;
            rtb_MathFunction_aq[2] = rtb_Subtract3_idx_1;
          } else {
            rtb_MathFunction_aq[0] = 0.0F;
            rtb_MathFunction_aq[1] = 0.0F;
            rtb_MathFunction_aq[2] = 1.0F;
          }

          /* End of Switch: '<S88>/Switch' */

          /* Product: '<S88>/Divide' */
          rtb_Divide_f[0] = rtb_MathFunction_aq[0] / rtb_MathFunction_aq[2];
          rtb_Divide_f[1] = rtb_MathFunction_aq[1] / rtb_MathFunction_aq[2];

          /* Sum: '<S91>/Sum of Elements' incorporates:
           *  Math: '<S91>/Math Function'
           *  SignalConversion: '<S91>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Sign1_n_idx_0 = rtb_Divide_f[1] * rtb_Divide_f[1] + rtb_Divide_f[0]
            * rtb_Divide_f[0];

          /* Math: '<S91>/Math Function1' incorporates:
           *  Sum: '<S91>/Sum of Elements'
           *
           * About '<S91>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Sign1_n_idx_0 < 0.0F) {
            rtb_Subtract3_idx_1 = -sqrtf(fabsf(rtb_Sign1_n_idx_0));
          } else {
            rtb_Subtract3_idx_1 = sqrtf(rtb_Sign1_n_idx_0);
          }

          /* End of Math: '<S91>/Math Function1' */

          /* Switch: '<S91>/Switch' incorporates:
           *  Constant: '<S91>/Constant'
           *  Product: '<S91>/Product'
           */
          if (rtb_Subtract3_idx_1 > 0.0F) {
            rtb_MathFunction_aq[0] = rtb_Divide_f[1];
            rtb_MathFunction_aq[1] = rtb_Divide_f[0];
            rtb_MathFunction_aq[2] = rtb_Subtract3_idx_1;
          } else {
            rtb_MathFunction_aq[0] = 0.0F;
            rtb_MathFunction_aq[1] = 0.0F;
            rtb_MathFunction_aq[2] = 1.0F;
          }

          /* End of Switch: '<S91>/Switch' */

          /* Product: '<S91>/Divide' */
          rtb_Divide_f[0] = rtb_MathFunction_aq[0] / rtb_MathFunction_aq[2];

          /* Product: '<S90>/Divide' */
          rtb_Divide_fw[0] = rtb_Switch_l[0] / rtb_Switch_l[2];
          rtb_Subtract3_idx_0 *= rtb_Subtract3_idx_0;

          /* Product: '<S91>/Divide' incorporates:
           *  Math: '<S86>/Square'
           */
          rtb_Divide_f[1] = rtb_MathFunction_aq[1] / rtb_MathFunction_aq[2];

          /* Product: '<S90>/Divide' */
          rtb_Divide_fw[1] = rtb_Switch_l[1] / rtb_Switch_l[2];

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Sqrt: '<S85>/Sqrt' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S85>/Square'
           *  SignalConversion: '<S16>/Signal Copy1'
           *  Sum: '<S85>/Sum of Elements'
           */
          rtb_Add3 = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
                           FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Sum: '<S89>/Subtract' incorporates:
           *  Product: '<S89>/Multiply'
           *  Product: '<S89>/Multiply1'
           */
          rtb_Subtract3_idx_1 = rtb_Divide_f[0] * rtb_Divide_fw[1] -
            rtb_Divide_f[1] * rtb_Divide_fw[0];

          /* Signum: '<S84>/Sign1' */
          if (rtb_Subtract3_idx_1 < 0.0F) {
            rtb_Subtract3_idx_1 = -1.0F;
          } else {
            if (rtb_Subtract3_idx_1 > 0.0F) {
              rtb_Subtract3_idx_1 = 1.0F;
            }
          }

          /* End of Signum: '<S84>/Sign1' */

          /* Switch: '<S84>/Switch2' incorporates:
           *  Constant: '<S84>/Constant4'
           */
          if (rtb_Subtract3_idx_1 == 0.0F) {
            rtb_Subtract3_idx_1 = 1.0F;
          }

          /* End of Switch: '<S84>/Switch2' */

          /* DotProduct: '<S84>/Dot Product' */
          rtb_Sqrt = rtb_Divide_fw[0] * rtb_Divide_f[0] + rtb_Divide_fw[1] *
            rtb_Divide_f[1];

          /* Trigonometry: '<S84>/Acos' incorporates:
           *  DotProduct: '<S84>/Dot Product'
           */
          if (rtb_Sqrt > 1.0F) {
            rtb_Sqrt = 1.0F;
          } else {
            if (rtb_Sqrt < -1.0F) {
              rtb_Sqrt = -1.0F;
            }
          }

          /* Product: '<S84>/Multiply' incorporates:
           *  Trigonometry: '<S84>/Acos'
           */
          rtb_Subtract3_idx_1 *= acosf(rtb_Sqrt);

          /* Saturate: '<S83>/Saturation' */
          if (rtb_Subtract3_idx_1 > 1.57079637F) {
            rtb_Subtract3_idx_1 = 1.57079637F;
          } else {
            if (rtb_Subtract3_idx_1 < -1.57079637F) {
              rtb_Subtract3_idx_1 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S83>/Saturation' */

          /* Product: '<S83>/Divide' incorporates:
           *  Constant: '<S75>/L1'
           *  Constant: '<S83>/Constant'
           *  Gain: '<S83>/Gain'
           *  Math: '<S83>/Square'
           *  MinMax: '<S83>/Max'
           *  MinMax: '<S83>/Min'
           *  Product: '<S83>/Multiply1'
           *  Sqrt: '<S85>/Sqrt'
           *  Sqrt: '<S86>/Sqrt'
           *  Sum: '<S86>/Sum of Elements'
           *  Trigonometry: '<S83>/Sin'
           */
          FMS_B.Merge_p = arm_sin_f32(rtb_Subtract3_idx_1) * (rtb_Add3 *
            rtb_Add3 * 2.0F) / fminf(FMS_PARAM.L1, fmaxf(sqrtf(rtb_MathFunction1
            + rtb_Subtract3_idx_0), 0.5F));

          /* Update for Delay: '<S79>/start_vel' */
          FMS_DW.icLoad = 0U;

          /* Update for Delay: '<S79>/start_wp' */
          FMS_DW.icLoad_c = 0U;

          /* End of Outputs for SubSystem: '<S72>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S72>/Brake Control' incorporates:
           *  ActionPort: '<S74>/Action Port'
           */
          /* SignalConversion: '<S74>/OutportBuffer_InsertedFor_ay_cmd_mPs2_at_inport_0' incorporates:
           *  Constant: '<S74>/Brake Speed'
           */
          FMS_B.Merge_p = 0.0F;

          /* End of Outputs for SubSystem: '<S72>/Brake Control' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S72>/Move Control' incorporates:
           *  ActionPort: '<S76>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* DeadZone: '<S93>/Dead Zone' incorporates:
           *  Inport: '<Root>/Pilot_Cmd'
           *  SignalConversion: '<S16>/Signal Copy2'
           */
          if (FMS_U.Pilot_Cmd.stick_roll > FMS_PARAM.ROLL_DZ) {
            rtb_MathFunction1 = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            rtb_MathFunction1 = 0.0F;
          } else {
            rtb_MathFunction1 = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
          }

          /* End of DeadZone: '<S93>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Gain: '<S76>/Gain6' incorporates:
           *  Gain: '<S93>/Gain'
           */
          FMS_B.Merge_p = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * rtb_MathFunction1 *
            FMS_PARAM.ACC_Y_LIM;

          /* End of Outputs for SubSystem: '<S72>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S72>/Switch Case' */

        /* SwitchCase: '<S58>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem_ba;
        FMS_DW.SwitchCase_ActiveSubsystem_ba = -1;
        switch (rtb_state_a) {
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
            /* SystemReset for IfAction SubSystem: '<S58>/Hold Control' incorporates:
             *  ActionPort: '<S61>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S58>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl_l);

            /* End of SystemReset for SubSystem: '<S58>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S58>/Hold Control' incorporates:
           *  ActionPort: '<S61>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge, &FMS_DW.HoldControl_l);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S58>/Hold Control' */
          break;

         case 1:
          /* Outputs for IfAction SubSystem: '<S58>/Brake Control' incorporates:
           *  ActionPort: '<S60>/Action Port'
           */
          FMS_BrakeControl(&FMS_B.Merge);

          /* End of Outputs for SubSystem: '<S58>/Brake Control' */
          break;

         case 2:
          /* Outputs for IfAction SubSystem: '<S58>/Move Control' incorporates:
           *  ActionPort: '<S62>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_MoveControl(FMS_U.Pilot_Cmd.stick_pitch, &FMS_B.Merge);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
          /* End of Outputs for SubSystem: '<S58>/Move Control' */
          break;
        }

        /* End of SwitchCase: '<S58>/Switch Case' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  BusAssignment: '<S28>/Bus Assignment'
         *  Constant: '<S28>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S28>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_b;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_o;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_m;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* DeadZone: '<S69>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
          rtb_MathFunction1 = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
          rtb_MathFunction1 = 0.0F;
        } else {
          rtb_MathFunction1 = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
        }

        /* End of DeadZone: '<S69>/Dead Zone' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* BusAssignment: '<S28>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Gain: '<S56>/Gain1'
         *  Gain: '<S69>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.psi_rate_cmd = 1.0F / (1.0F - FMS_PARAM.YAW_DZ) *
          rtb_MathFunction1 * FMS_PARAM.YAW_RATE_LIM;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Gain: '<S54>/Gain1' incorporates:
         *  Bias: '<S54>/Bias'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        rtb_Subtract3_idx_0 = (FMS_U.Pilot_Cmd.stick_throttle + 1.0F) * 0.5F;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Saturate: '<S54>/Saturation' incorporates:
         *  Gain: '<S54>/Gain1'
         */
        if (rtb_Subtract3_idx_0 > 1.0F) {
          rtb_Subtract3_idx_0 = 1.0F;
        } else {
          if (rtb_Subtract3_idx_0 < 0.0F) {
            rtb_Subtract3_idx_0 = 0.0F;
          }
        }

        /* End of Saturate: '<S54>/Saturation' */

        /* BusAssignment: '<S28>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Gain: '<S54>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_AIRSPD_MAX * rtb_Subtract3_idx_0;

        /* Saturate: '<S72>/Saturation1' */
        if (FMS_B.Merge_p > FMS_PARAM.ACC_Y_LIM) {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.ACC_Y_LIM;
        } else if (FMS_B.Merge_p < -FMS_PARAM.ACC_Y_LIM) {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.ACC_Y_LIM;
        } else {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = FMS_B.Merge_p;
        }

        /* End of Saturate: '<S72>/Saturation1' */

        /* Saturate: '<S58>/Saturation1' */
        if (FMS_B.Merge > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (FMS_B.Merge < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S28>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_B.Merge;
        }

        /* End of Saturate: '<S58>/Saturation1' */
        /* End of Outputs for SubSystem: '<S21>/Position' */
        break;

       case 4:
        /* Outputs for IfAction SubSystem: '<S21>/Unknown' incorporates:
         *  ActionPort: '<S30>/Action Port'
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
      /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
      /* Saturate: '<S140>/Saturation' incorporates:
       *  Constant: '<S140>/Constant4'
       *  Inport: '<Root>/Pilot_Cmd'
       *  SignalConversion: '<S16>/Signal Copy2'
       *  Sum: '<S140>/Sum'
       */
      if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
        rtb_MathFunction1 = 2.0F;
      } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
        rtb_MathFunction1 = 0.0F;
      } else {
        rtb_MathFunction1 = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
      }

      /* End of Saturate: '<S140>/Saturation' */
      /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

      /* DataTypeConversion: '<S139>/Data Type Conversion' incorporates:
       *  Constant: '<S140>/Constant5'
       *  Gain: '<S140>/Gain4'
       *  Sum: '<S140>/Add'
       */
      rtb_DataTypeConversion = (uint16_T)fmodf(floorf(500.0F * rtb_MathFunction1
        + 1000.0F), 65536.0F);

      /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
      /* DataTypeConversion: '<S139>/Data Type Conversion1' incorporates:
       *  Bias: '<S139>/Bias1'
       *  Gain: '<S139>/Gain1'
       *  Inport: '<Root>/Pilot_Cmd'
       *  SignalConversion: '<S16>/Signal Copy2'
       */
      rtb_MathFunction1 = fmodf(floorf(-500.0F * FMS_U.Pilot_Cmd.stick_roll +
        1500.0F), 65536.0F);

      /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
      rtb_DataTypeConversion1_l = (uint16_T)(rtb_MathFunction1 < 0.0F ? (int32_T)
        (uint16_T)-(int16_T)(uint16_T)-rtb_MathFunction1 : (int32_T)(uint16_T)
        rtb_MathFunction1);

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
      FMS_Y.FMS_Out.actuator_cmd[0] = rtb_DataTypeConversion;
      FMS_Y.FMS_Out.actuator_cmd[1] = rtb_DataTypeConversion;
      FMS_Y.FMS_Out.actuator_cmd[2] = rtb_DataTypeConversion1_l;
      FMS_Y.FMS_Out.actuator_cmd[3] = rtb_DataTypeConversion1_l;

      /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
      /* DataTypeConversion: '<S139>/Data Type Conversion2' incorporates:
       *  Bias: '<S139>/Bias2'
       *  Gain: '<S139>/Gain2'
       *  Inport: '<Root>/Pilot_Cmd'
       *  SignalConversion: '<S16>/Signal Copy2'
       */
      rtb_MathFunction1 = fmodf(floorf(500.0F * FMS_U.Pilot_Cmd.stick_pitch +
        1500.0F), 65536.0F);

      /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

      /* BusAssignment: '<S23>/Bus Assignment' incorporates:
       *  BusAssignment: '<S18>/Bus Assignment'
       *  DataTypeConversion: '<S139>/Data Type Conversion2'
       *  Outport: '<Root>/FMS_Out'
       */
      FMS_Y.FMS_Out.actuator_cmd[4] = (uint16_T)(rtb_MathFunction1 < 0.0F ?
        (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_MathFunction1 : (int32_T)
        (uint16_T)rtb_MathFunction1);

      /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
      /* DataTypeConversion: '<S139>/Data Type Conversion3' incorporates:
       *  Bias: '<S139>/Bias3'
       *  Gain: '<S139>/Gain3'
       *  Inport: '<Root>/Pilot_Cmd'
       *  SignalConversion: '<S16>/Signal Copy2'
       */
      rtb_MathFunction1 = fmodf(floorf(500.0F * FMS_U.Pilot_Cmd.stick_yaw +
        1500.0F), 65536.0F);

      /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

      /* BusAssignment: '<S23>/Bus Assignment' incorporates:
       *  BusAssignment: '<S18>/Bus Assignment'
       *  DataTypeConversion: '<S139>/Data Type Conversion3'
       *  Outport: '<Root>/FMS_Out'
       */
      FMS_Y.FMS_Out.actuator_cmd[5] = (uint16_T)(rtb_MathFunction1 < 0.0F ?
        (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_MathFunction1 : (int32_T)
        (uint16_T)rtb_MathFunction1);
      for (i = 0; i < 10; i++) {
        FMS_Y.FMS_Out.actuator_cmd[i + 6] = 0U;
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
   *  DiscreteIntegrator: '<S244>/Discrete-Time Integrator'
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

  /* Update for DiscreteIntegrator: '<S244>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S244>/Constant'
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

  /* Start for IfAction SubSystem: '<S24>/Return' */
  /* Start for SwitchCase: '<S205>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_k = -1;

  /* Start for SwitchCase: '<S195>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_g = -1;

  /* End of Start for SubSystem: '<S24>/Return' */
  /* End of Start for SubSystem: '<S17>/SubMode' */

  /* Start for IfAction SubSystem: '<S17>/Auto' */
  /* Start for SwitchCase: '<S22>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_i = -1;

  /* End of Start for SubSystem: '<S17>/Auto' */

  /* Start for IfAction SubSystem: '<S17>/Assist' */
  /* Start for SwitchCase: '<S21>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_f = -1;

  /* Start for IfAction SubSystem: '<S21>/Altitude' */
  /* Start for SwitchCase: '<S37>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_m = -1;

  /* End of Start for SubSystem: '<S21>/Altitude' */

  /* Start for IfAction SubSystem: '<S21>/Position' */
  /* Start for SwitchCase: '<S72>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_l = -1;

  /* Start for SwitchCase: '<S58>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem_ba = -1;

  /* End of Start for SubSystem: '<S21>/Position' */
  /* End of Start for SubSystem: '<S17>/Assist' */
  /* End of Start for SubSystem: '<S15>/Arm' */
  /* End of Start for SubSystem: '<Root>/FMS Commander' */
  FMS_PrevZCX.Mission_SubSystem_Reset_ZCE = POS_ZCSIG;

  /* SystemInitialize for Chart: '<Root>/SafeMode' */
  FMS_DW.is_active_c3_FMS = 0U;
  FMS_DW.is_c3_FMS = FMS_IN_NO_ACTIVE_CHILD_o;

  /* SystemInitialize for Chart: '<Root>/FMS State Machine' */
  initialize_msg_local_queues_for();
  FMS_DW.sfEvent = -1;
  FMS_DW.is_active_Combo_Stick = 0U;
  FMS_DW.is_Combo_Stick = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_active_Command_Listener = 0U;
  FMS_DW.is_Command_Listener = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_active_Vehicle = 0U;
  FMS_DW.is_Vehicle = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_Arm = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_Assist = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_Auto = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_Mission = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_Manual = FMS_IN_NO_ACTIVE_CHILD_o;
  FMS_DW.is_SubMode = FMS_IN_NO_ACTIVE_CHILD_o;
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
  /* SystemInitialize for IfAction SubSystem: '<S15>/Arm' */
  /* SystemInitialize for IfAction SubSystem: '<S17>/SubMode' */
  /* SystemInitialize for IfAction SubSystem: '<S24>/Return' */
  /* InitializeConditions for Delay: '<S191>/Delay' */
  FMS_DW.icLoad_o = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S232>/Discrete-Time Integrator' */
  FMS_DW.l1_heading = 0.0F;

  /* InitializeConditions for Delay: '<S171>/Delay' */
  FMS_DW.icLoad_cg = 1U;

  /* InitializeConditions for Delay: '<S172>/Delay' */
  FMS_DW.icLoad_j = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S175>/Integrator1' */
  FMS_DW.Integrator1_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S175>/Integrator' */
  FMS_DW.Integrator_DSTATE = 0.0F;

  /* SystemInitialize for Chart: '<S206>/Motion State' */
  FMS_DW.temporalCounter_i1_j = 0U;
  FMS_DW.is_active_c2_FMS = 0U;
  FMS_DW.is_c2_FMS = FMS_IN_NO_ACTIVE_CHILD_o;

  /* SystemInitialize for IfAction SubSystem: '<S205>/Hold Control' */
  /* InitializeConditions for Delay: '<S208>/Delay' */
  FMS_DW.icLoad_i = 1U;

  /* End of SystemInitialize for SubSystem: '<S205>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S205>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S215>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_p[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S215>/Integrator' */
  FMS_DW.Integrator_DSTATE_p[0] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S205>/Move Control' */

  /* SystemInitialize for Merge: '<S205>/Merge' */
  FMS_B.Merge_m[0] = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<S205>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S215>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_p[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S215>/Integrator' */
  FMS_DW.Integrator_DSTATE_p[1] = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S205>/Move Control' */

  /* SystemInitialize for Merge: '<S205>/Merge' */
  FMS_B.Merge_m[1] = 0.0F;

  /* SystemInitialize for Chart: '<S196>/Motion Status' */
  FMS_DW.temporalCounter_i1_a = 0U;
  FMS_DW.is_active_c1_FMS = 0U;
  FMS_DW.is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD_o;

  /* SystemInitialize for IfAction SubSystem: '<S195>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl);

  /* End of SystemInitialize for SubSystem: '<S195>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S195>/Move Control' */
  /* InitializeConditions for DiscreteIntegrator: '<S202>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_n = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S202>/Integrator' */
  FMS_DW.Integrator_DSTATE_l = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S195>/Move Control' */

  /* SystemInitialize for Merge: '<S195>/Merge' */
  FMS_B.Merge_mu = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S24>/Return' */

  /* SystemInitialize for IfAction SubSystem: '<S24>/Hold' */
  /* InitializeConditions for Delay: '<S151>/start_vel' */
  FMS_DW.icLoad_n = 1U;

  /* InitializeConditions for Delay: '<S151>/start_wp' */
  FMS_DW.icLoad_m = 1U;

  /* InitializeConditions for Delay: '<S146>/Delay' */
  FMS_DW.icLoad_b = 1U;

  /* End of SystemInitialize for SubSystem: '<S24>/Hold' */
  /* End of SystemInitialize for SubSystem: '<S17>/SubMode' */

  /* SystemInitialize for IfAction SubSystem: '<S17>/Auto' */
  /* SystemInitialize for IfAction SubSystem: '<S22>/Mission' */
  /* InitializeConditions for UnitDelay: '<S115>/Delay Input1'
   *
   * Block description for '<S115>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_pe = 0U;

  /* End of SystemInitialize for SubSystem: '<S22>/Mission' */
  /* End of SystemInitialize for SubSystem: '<S17>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S17>/Assist' */
  /* SystemInitialize for IfAction SubSystem: '<S21>/Altitude' */
  /* SystemInitialize for Chart: '<S38>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_b);

  /* SystemInitialize for IfAction SubSystem: '<S37>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_k2);

  /* End of SystemInitialize for SubSystem: '<S37>/Hold Control' */

  /* SystemInitialize for Merge: '<S37>/Merge' */
  FMS_B.Merge_l = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S21>/Altitude' */

  /* SystemInitialize for IfAction SubSystem: '<S21>/Position' */
  /* SystemInitialize for Chart: '<S59>/Motion Status' */
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus_j);

  /* SystemInitialize for Chart: '<S73>/Motion State' */
  FMS_DW.temporalCounter_i1_i = 0U;
  FMS_DW.is_active_c16_FMS = 0U;
  FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_o;

  /* SystemInitialize for IfAction SubSystem: '<S72>/Hold Control' */
  /* InitializeConditions for Delay: '<S79>/start_vel' */
  FMS_DW.icLoad = 1U;

  /* InitializeConditions for Delay: '<S79>/start_wp' */
  FMS_DW.icLoad_c = 1U;

  /* End of SystemInitialize for SubSystem: '<S72>/Hold Control' */

  /* SystemInitialize for IfAction SubSystem: '<S58>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl_l);

  /* End of SystemInitialize for SubSystem: '<S58>/Hold Control' */

  /* SystemInitialize for Merge: '<S58>/Merge' */
  FMS_B.Merge = 0.0F;

  /* SystemInitialize for Merge: '<S72>/Merge' */
  FMS_B.Merge_p = 0.0F;

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
