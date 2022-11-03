/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1968
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Oct 14 08:47:05 2022
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

/* Named constants for Chart: '<S73>/Motion State' */
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
  0U                                   /* reserved */
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
                                        *   '<S210>/Constant'
                                        *   '<S19>/Constant6'
                                        *   '<S20>/Constant6'
                                        *   '<S143>/Constant4'
                                        *   '<S144>/Constant4'
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
                                        *   '<S164>/Gain'
                                        *   '<S164>/Saturation1'
                                        *   '<S186>/Gain'
                                        *   '<S186>/Saturation1'
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
                                        *   '<S169>/L1'
                                        *   '<S169>/Saturation1'
                                        *   '<S191>/L1'
                                        *   '<S191>/Saturation1'
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
                                        *   '<S43>/Dead Zone'
                                        *   '<S43>/Gain'
                                        *   '<S64>/Dead Zone'
                                        *   '<S64>/Gain'
                                        *   '<S93>/Dead Zone'
                                        *   '<S93>/Gain'
                                        */

struct_i6HyuFQRjfkj8sSCv2bg5D FMS_EXPORT = {
  4U,

  { 70, 87, 32, 70, 77, 83, 32, 118, 48, 46, 48, 46, 50, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by:
                                        *   '<S5>/Constant1'
                                        *   '<S208>/Constant'
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
 *    '<S193>/NearbyRefWP'
 *    '<S171>/NearbyRefWP'
 *    '<S124>/NearbyRefWP'
 */
void FMS_NearbyRefWP(const real32_T rtu_P2[2], real32_T rtu_P3, real32_T
                     rtu_P3_i, real32_T rtu_L1, real32_T rty_P[2], real32_T
                     *rty_d)
{
  real32_T P3P2_idx_0;
  real32_T P3P2_idx_1;

  /* SignalConversion: '<S197>/TmpSignal ConversionAt SFunction Inport2' */
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
 *    '<S193>/OutRegionRegWP'
 *    '<S171>/OutRegionRegWP'
 *    '<S124>/OutRegionRegWP'
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

  /* SignalConversion: '<S198>/TmpSignal ConversionAt SFunction Inport3' */
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
    /* SignalConversion: '<S198>/TmpSignal ConversionAt SFunction Inport3' */
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
 *    '<S193>/SearchL1RefWP'
 *    '<S171>/SearchL1RefWP'
 *    '<S124>/SearchL1RefWP'
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

  /* SignalConversion: '<S199>/TmpSignal ConversionAt SFunction Inport3' */
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
 * System initialize for action system:
 *    '<S37>/Hold Control'
 *    '<S58>/Hold Control'
 */
void FMS_HoldControl_Init(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S40>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * System reset for action system:
 *    '<S37>/Hold Control'
 *    '<S58>/Hold Control'
 */
void FMS_HoldControl_Reset(DW_HoldControl_FMS_T *localDW)
{
  /* InitializeConditions for Delay: '<S40>/Delay' */
  localDW->icLoad = 1U;
}

/*
 * Output and update for action system:
 *    '<S37>/Hold Control'
 *    '<S58>/Hold Control'
 */
void FMS_HoldControl(real32_T rtu_FMS_In, real32_T *rty_w_cmd_mPs,
                     DW_HoldControl_FMS_T *localDW)
{
  /* Delay: '<S40>/Delay' incorporates:
   *  Gain: '<S42>/Gain'
   */
  if (localDW->icLoad != 0) {
    localDW->Delay_DSTATE = -rtu_FMS_In;
  }

  /* Gain: '<S40>/Gain2' incorporates:
   *  Delay: '<S40>/Delay'
   *  Gain: '<S42>/Gain'
   *  Sum: '<S40>/Sum'
   */
  *rty_w_cmd_mPs = (localDW->Delay_DSTATE - (-rtu_FMS_In)) * FMS_PARAM.Z_P;

  /* Update for Delay: '<S40>/Delay' */
  localDW->icLoad = 0U;
}

/*
 * Output and update for action system:
 *    '<S37>/Brake Control'
 *    '<S58>/Brake Control'
 */
void FMS_BrakeControl(real32_T *rty_psi_rate_cmd_radPs)
{
  /* SignalConversion: '<S39>/OutportBuffer_InsertedFor_psi_rate_cmd_radPs_at_inport_0' incorporates:
   *  Constant: '<S39>/Brake Speed'
   */
  *rty_psi_rate_cmd_radPs = 0.0F;
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

  /* Gain: '<S212>/deg2rad' */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtu_llo[0];

  /* Trigonometry: '<S213>/Sin' */
  rtb_Sum2_m = sin(rtb_Sum_e_idx_0);

  /* Math: '<S213>/Square1' */
  rtb_Sum2_m *= rtb_Sum2_m;

  /* Product: '<S213>/Multiply1' incorporates:
   *  Product: '<S213>/Multiply'
   */
  rtb_Gain_lq = localC->ff * rtb_Sum2_m;

  /* Product: '<S213>/Divide' incorporates:
   *  Constant: '<S213>/Constant'
   *  Constant: '<S213>/R'
   *  Sqrt: '<S213>/Sqrt'
   *  Sum: '<S213>/Sum1'
   */
  rtb_Sum2_m = 6.378137E+6 / sqrt(1.0 - rtb_Gain_lq);

  /* Product: '<S213>/Product3' incorporates:
   *  Constant: '<S213>/Constant1'
   *  Product: '<S213>/Multiply1'
   *  Sum: '<S213>/Sum2'
   */
  rtb_Gain_lq = 1.0 / (1.0 - rtb_Gain_lq) * localC->Sum4 * rtb_Sum2_m;

  /* Product: '<S213>/Multiply2' incorporates:
   *  Trigonometry: '<S213>/Cos'
   */
  rtb_Sum2_m *= cos(rtb_Sum_e_idx_0);

  /* Sum: '<S212>/Sum' */
  rtb_Sum_e_idx_0 = rtu_lla[0] - rtu_llo[0];

  /* Abs: '<S217>/Abs' incorporates:
   *  Abs: '<S220>/Abs1'
   *  Switch: '<S217>/Switch1'
   */
  rtb_Sum_d = fabs(rtb_Sum_e_idx_0);

  /* Switch: '<S217>/Switch1' incorporates:
   *  Abs: '<S217>/Abs'
   *  Bias: '<S217>/Bias2'
   *  Bias: '<S217>/Bias3'
   *  Constant: '<S214>/Constant'
   *  Constant: '<S214>/Constant1'
   *  Constant: '<S219>/Constant'
   *  Gain: '<S217>/Gain1'
   *  Product: '<S217>/Multiply'
   *  RelationalOperator: '<S219>/Compare'
   *  Switch: '<S214>/Switch'
   */
  if (rtb_Sum_d > 90.0) {
    /* Switch: '<S220>/Switch1' incorporates:
     *  Bias: '<S220>/Bias2'
     *  Bias: '<S220>/Bias3'
     *  Constant: '<S220>/Constant'
     *  Constant: '<S221>/Constant'
     *  Math: '<S220>/Math Function'
     *  RelationalOperator: '<S221>/Compare'
     */
    if (rtb_Sum_d > 180.0) {
      rtb_Sum_e_idx_0 = rt_modd(rtb_Sum_e_idx_0 + 180.0, 360.0) + -180.0;
    }

    /* End of Switch: '<S220>/Switch1' */

    /* Signum: '<S217>/Sign' */
    if (rtb_Sum_e_idx_0 < 0.0) {
      rtb_Sum_e_idx_0 = -1.0;
    } else {
      if (rtb_Sum_e_idx_0 > 0.0) {
        rtb_Sum_e_idx_0 = 1.0;
      }
    }

    /* End of Signum: '<S217>/Sign' */
    rtb_Sum_e_idx_0 *= -(rtb_Sum_d + -90.0) + 90.0;
    rtb_Compare_d_0 = 180;
  } else {
    rtb_Compare_d_0 = 0;
  }

  /* Sum: '<S214>/Sum' incorporates:
   *  Sum: '<S212>/Sum'
   */
  rtb_Sum_d = (rtu_lla[1] - rtu_llo[1]) + (real_T)rtb_Compare_d_0;

  /* Product: '<S212>/Multiply' incorporates:
   *  Gain: '<S212>/deg2rad1'
   */
  rtb_Sum_e_idx_0 = 0.017453292519943295 * rtb_Sum_e_idx_0 * rtb_Gain_lq;

  /* Switch: '<S216>/Switch1' incorporates:
   *  Abs: '<S216>/Abs1'
   *  Bias: '<S216>/Bias2'
   *  Bias: '<S216>/Bias3'
   *  Constant: '<S216>/Constant'
   *  Constant: '<S218>/Constant'
   *  Math: '<S216>/Math Function'
   *  RelationalOperator: '<S218>/Compare'
   */
  if (fabs(rtb_Sum_d) > 180.0) {
    rtb_Sum_d = rt_modd(rtb_Sum_d + 180.0, 360.0) + -180.0;
  }

  /* End of Switch: '<S216>/Switch1' */

  /* Product: '<S212>/Multiply' incorporates:
   *  Gain: '<S212>/deg2rad1'
   */
  rtb_Sum_d = 0.017453292519943295 * rtb_Sum_d * rtb_Sum2_m;

  /* Gain: '<S212>/deg2rad2' */
  rtb_Sum2_m = 0.017453292519943295 * rtu_psio;

  /* Trigonometry: '<S215>/SinCos' */
  rtb_Sum3 = sin(rtb_Sum2_m);
  rtb_Gain_lq = cos(rtb_Sum2_m);

  /* Sum: '<S215>/Sum2' incorporates:
   *  Product: '<S215>/Multiply1'
   *  Product: '<S215>/Multiply2'
   */
  rtb_Sum2_m = rtb_Sum_e_idx_0 * rtb_Gain_lq + rtb_Sum_d * rtb_Sum3;

  /* Product: '<S215>/Multiply3' */
  rtb_Sum3 *= rtb_Sum_e_idx_0;

  /* Product: '<S215>/Multiply4' */
  rtb_Gain_lq *= rtb_Sum_d;

  /* Sum: '<S215>/Sum3' */
  rtb_Sum3 = rtb_Gain_lq - rtb_Sum3;

  /* DataTypeConversion: '<S209>/Data Type Conversion' incorporates:
   *  Gain: '<S212>/Gain'
   *  Sum: '<S212>/Sum1'
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
  /* RelationalOperator: '<S222>/Compare' incorporates:
   *  Abs: '<S211>/Abs'
   *  Constant: '<S222>/Constant'
   *  MinMax: '<S211>/Max'
   *  Sum: '<S211>/Sum'
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
        tmp[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R - FMS_DW.home[0];
        tmp[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R - FMS_DW.home[1];

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
        FMS_B.Cmd_In.sp_waypoint[0] = FMS_DW.home[0];
        FMS_B.Cmd_In.sp_waypoint[1] = FMS_DW.home[1];
        FMS_B.Cmd_In.sp_waypoint[2] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
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
                                     FMS_DW.home[2]);
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
                    FMS_B.Cmd_In.sp_waypoint[0] = FMS_DW.home[0];
                    FMS_B.Cmd_In.sp_waypoint[1] = FMS_DW.home[1];
                    FMS_B.Cmd_In.sp_waypoint[2] =
                      FMS_B.BusConversion_InsertedFor_FMSSt.y_R;
                    FMS_B.state = VehicleState_Return;
                  } else if (FMS_DW.nav_cmd == (int32_T)NAV_Cmd_Waypoint) {
                    FMS_DW.is_Mission = FMS_IN_Waypoint;
                    lla_tmp = FMS_B.wp_index - 1;

                    /* Inport: '<Root>/Mission_Data' */
                    FMS_B.lla[0] = (real_T)FMS_U.Mission_Data.x[lla_tmp] *
                      1.0E-7;
                    FMS_B.lla[1] = (real_T)FMS_U.Mission_Data.y[lla_tmp] *
                      1.0E-7;
                    FMS_B.lla[2] = -(FMS_U.Mission_Data.z[lla_tmp] +
                                     FMS_DW.home[2]);
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
                    FMS_B.state = VehicleState_Hold;
                  }
                  break;

                 case FMS_IN_Return_h:
                  tmp[0] = FMS_B.BusConversion_InsertedFor_FMSSt.x_R -
                    FMS_DW.home[0];
                  tmp[1] = FMS_B.BusConversion_InsertedFor_FMSSt.y_R -
                    FMS_DW.home[1];

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
      /* Reshape: '<S210>/Reshape' incorporates:
       *  Constant: '<S210>/Constant'
       */
      FMS_B.Reshape[0] = FMS_B.xy_R[0];
      FMS_B.Reshape[1] = FMS_B.xy_R[1];
      FMS_B.Reshape[2] = FMS_PARAM.TAKEOFF_H;

      /* End of Outputs for SubSystem: '<S3>/Vehicle.PrepTakeoff' */
      FMS_B.Cmd_In.sp_waypoint[0] = FMS_B.Reshape[0];
      FMS_B.Cmd_In.sp_waypoint[1] = FMS_B.Reshape[1];
      FMS_B.Cmd_In.sp_waypoint[2] = FMS_B.Reshape[2];
      FMS_B.Cmd_In.sp_waypoint[2] += FMS_DW.home[2];
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
      guard4 = false;
      if (FMS_B.target_mode == PilotMode_Mission) {
        if ((FMS_U.Mission_Data.valid_items > 0) &&
            (FMS_U.Mission_Data.command[FMS_B.wp_index - 1] == (int32_T)
             NAV_Cmd_Takeoff)) {
          FMS_DW.prep_mission_takeoff = 1.0;
          FMS_DW.condWasTrueAtLastTimeStep_2 = (FMS_DW.prep_mission_takeoff ==
            1.0);
          FMS_DW.prep_takeoff = 0.0;
          FMS_DW.condWasTrueAtLastTimeStep_1_d = (FMS_DW.prep_takeoff == 1.0);
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
  boolean_T rtb_Compare_ay;
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
  rtb_Saturation_bu = (real32_T)FMS_DW.DiscreteTimeIntegrator1_DSTATE +
    (real32_T)FMS_EXPORT.period;
  if (rtb_Saturation_bu < 4.2949673E+9F) {
    FMS_DW.DiscreteTimeIntegrator1_DSTATE = (uint32_T)rtb_Saturation_bu;
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
   *  Constant: '<Root>/Constant'
   *  Inport: '<Root>/Mission_Data'
   */
  FMS_DW.chartAbsoluteTimeCounter++;
  FMS_DW.durationLastReferenceTick_1 = FMS_DW.chartAbsoluteTimeCounter;
  FMS_DW.condWasTrueAtLastTimeStep_1 = false;
  rtb_Compare_ay = (FMS_DW.prep_takeoff == 1.0);
  if ((!rtb_Compare_ay) || (!FMS_DW.condWasTrueAtLastTimeStep_1_d)) {
    FMS_DW.durationLastReferenceTick_1_j = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_1_d = rtb_Compare_ay;
  rtb_Compare_ay = (FMS_DW.prep_mission_takeoff == 1.0);
  if ((!rtb_Compare_ay) || (!FMS_DW.condWasTrueAtLastTimeStep_2)) {
    FMS_DW.durationLastReferenceTick_2 = FMS_DW.chartAbsoluteTimeCounter;
  }

  FMS_DW.condWasTrueAtLastTimeStep_2 = rtb_Compare_ay;
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
  /* SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1' */
  rtb_Switch_fz[0] = FMS_B.Cmd_In.sp_waypoint[0];
  rtb_Switch_a[0] = FMS_B.Cmd_In.cur_waypoint[0];
  rtb_Switch_fz[1] = FMS_B.Cmd_In.sp_waypoint[1];
  rtb_Switch_a[1] = FMS_B.Cmd_In.cur_waypoint[1];
  rtb_Switch_fz[2] = FMS_B.Cmd_In.sp_waypoint[2];
  rtb_Switch_a[2] = FMS_B.Cmd_In.cur_waypoint[2];

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
      rtb_Saturation_bu = fmodf(floorf(FMS_PARAM.DISARM_OUT[i]), 65536.0F);
      FMS_Y.FMS_Out.actuator_cmd[i] = (uint16_T)(rtb_Saturation_bu < 0.0F ?
        (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_Saturation_bu : (int32_T)
        (uint16_T)rtb_Saturation_bu);
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
      rtb_Saturation_bu = fmodf(floorf(FMS_PARAM.STANDBY_OUT[i]), 65536.0F);
      FMS_Y.FMS_Out.actuator_cmd[i] = (uint16_T)(rtb_Saturation_bu < 0.0F ?
        (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_Saturation_bu : (int32_T)
        (uint16_T)rtb_Saturation_bu);
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
      /* SwitchCase: '<S24>/Switch Case' */
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
        /* Outputs for IfAction SubSystem: '<S24>/Takeoff' incorporates:
         *  ActionPort: '<S144>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* SignalConversion: '<S202>/TmpSignal ConversionAtSquareInport1' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_Divide_h[0] = FMS_U.INS_Out.vn;
        rtb_Divide_h[1] = FMS_U.INS_Out.ve;

        /* Sum: '<S203>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S203>/Math Function'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  Sum: '<S202>/Sum of Elements'
         */
        rtb_Saturation_bu = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Math: '<S203>/Math Function1' incorporates:
         *  Sum: '<S203>/Sum of Elements'
         *
         * About '<S203>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_bu < 0.0F) {
          rtb_Saturation_fu = -sqrtf(fabsf(rtb_Saturation_bu));
        } else {
          rtb_Saturation_fu = sqrtf(rtb_Saturation_bu);
        }

        /* End of Math: '<S203>/Math Function1' */

        /* Switch: '<S203>/Switch' incorporates:
         *  Constant: '<S203>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S203>/Product'
         *  SignalConversion: '<S16>/Signal Copy1'
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

        /* End of Switch: '<S203>/Switch' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* MATLAB Function: '<S193>/NearbyRefWP' incorporates:
         *  Constant: '<S191>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_Switch_fz[0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                        FMS_PARAM.L1, rtb_Divide_h, &rtb_Saturation1_bl);

        /* MATLAB Function: '<S193>/SearchL1RefWP' incorporates:
         *  Constant: '<S191>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        FMS_SearchL1RefWP(&rtb_Switch_a[0], &rtb_Switch_fz[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_P_k,
                          &rtb_Saturation_fu);

        /* MATLAB Function: '<S193>/OutRegionRegWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        FMS_OutRegionRegWP(&rtb_Switch_a[0], &rtb_Switch_fz[0],
                           FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, rtb_P_ia);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Switch: '<S193>/Switch1' incorporates:
         *  Constant: '<S196>/Constant'
         *  RelationalOperator: '<S196>/Compare'
         */
        if (rtb_Saturation1_bl > 0.0F) {
          rtb_P_k[0] = rtb_Divide_h[0];
          rtb_P_k[1] = rtb_Divide_h[1];
        } else {
          /* RelationalOperator: '<S195>/Compare' incorporates:
           *  Constant: '<S195>/Constant'
           */
          rtb_Compare_ay = (rtb_Saturation_fu >= 0.0F);

          /* Switch: '<S193>/Switch' */
          if (!rtb_Compare_ay) {
            rtb_P_k[0] = rtb_P_ia[0];
            rtb_P_k[1] = rtb_P_ia[1];
          }

          /* End of Switch: '<S193>/Switch' */
        }

        /* End of Switch: '<S193>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S194>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_Divide_h[0] = rtb_P_k[0] - FMS_U.INS_Out.x_R;
        rtb_Divide_h[1] = rtb_P_k[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Sum: '<S204>/Sum of Elements' incorporates:
         *  Math: '<S204>/Math Function'
         */
        rtb_Saturation_fu = rtb_Divide_h[0] * rtb_Divide_h[0] + rtb_Divide_h[1] *
          rtb_Divide_h[1];

        /* Math: '<S204>/Math Function1' incorporates:
         *  Sum: '<S204>/Sum of Elements'
         *
         * About '<S204>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_fu < 0.0F) {
          rtb_Saturation_fu = -sqrtf(fabsf(rtb_Saturation_fu));
        } else {
          rtb_Saturation_fu = sqrtf(rtb_Saturation_fu);
        }

        /* End of Math: '<S204>/Math Function1' */

        /* Switch: '<S204>/Switch' incorporates:
         *  Constant: '<S204>/Constant'
         *  Product: '<S204>/Product'
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

        /* End of Switch: '<S204>/Switch' */

        /* Product: '<S203>/Divide' */
        rtb_Divide_h[0] = rtb_Switch_b_idx_0 / rtb_Switch_b_idx_2;
        rtb_Divide_h[1] = rtb_Switch_b_idx_1 / rtb_Switch_b_idx_2;

        /* Sum: '<S206>/Sum of Elements' incorporates:
         *  Math: '<S206>/Math Function'
         *  SignalConversion: '<S206>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Saturation_fu = rtb_Divide_h[1] * rtb_Divide_h[1] + rtb_Divide_h[0] *
          rtb_Divide_h[0];

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
          rtb_Switch_b_idx_0 = rtb_Divide_h[1];
          rtb_Switch_b_idx_1 = rtb_Divide_h[0];
          rtb_Switch_b_idx_2 = rtb_Saturation_fu;
        } else {
          rtb_Switch_b_idx_0 = 0.0F;
          rtb_Switch_b_idx_1 = 0.0F;
          rtb_Switch_b_idx_2 = 1.0F;
        }

        /* End of Switch: '<S206>/Switch' */

        /* Product: '<S204>/Divide' */
        rtb_Divide_h[0] = rtb_Switch_fz[0] / rtb_Switch_fz[2];
        rtb_Divide_h[1] = rtb_Switch_fz[1] / rtb_Switch_fz[2];

        /* Sum: '<S207>/Sum of Elements' incorporates:
         *  Math: '<S207>/Math Function'
         *  SignalConversion: '<S207>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Saturation_fu = rtb_Divide_h[1] * rtb_Divide_h[1] + rtb_Divide_h[0] *
          rtb_Divide_h[0];

        /* Math: '<S207>/Math Function1' incorporates:
         *  Sum: '<S207>/Sum of Elements'
         *
         * About '<S207>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_fu < 0.0F) {
          rtb_Saturation_fu = -sqrtf(fabsf(rtb_Saturation_fu));
        } else {
          rtb_Saturation_fu = sqrtf(rtb_Saturation_fu);
        }

        /* End of Math: '<S207>/Math Function1' */

        /* Switch: '<S207>/Switch' incorporates:
         *  Constant: '<S207>/Constant'
         *  Product: '<S207>/Product'
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

        /* End of Switch: '<S207>/Switch' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S188>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Saturation_fu = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
        rtb_Saturation1_bl = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Product: '<S207>/Divide' */
        rtb_Divide_h[0] = rtb_Switch_fz[0] / rtb_Switch_fz[2];

        /* Product: '<S206>/Divide' */
        rtb_P_k[0] = rtb_Switch_b_idx_0 / rtb_Switch_b_idx_2;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S188>/Sum1' incorporates:
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_b_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_B.Cmd_In.cur_waypoint[0];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Product: '<S207>/Divide' */
        rtb_Divide_h[1] = rtb_Switch_fz[1] / rtb_Switch_fz[2];

        /* Product: '<S206>/Divide' */
        rtb_P_k[1] = rtb_Switch_b_idx_1 / rtb_Switch_b_idx_2;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S188>/Sum1' incorporates:
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_b_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Product: '<S188>/Divide' incorporates:
         *  Math: '<S189>/Square'
         *  Math: '<S190>/Square'
         *  Sqrt: '<S189>/Sqrt'
         *  Sqrt: '<S190>/Sqrt'
         *  Sum: '<S188>/Sum'
         *  Sum: '<S188>/Sum1'
         *  Sum: '<S189>/Sum of Elements'
         *  Sum: '<S190>/Sum of Elements'
         */
        rtb_Switch_b_idx_0 = sqrtf(rtb_Saturation1_bl * rtb_Saturation1_bl +
          rtb_Saturation_fu * rtb_Saturation_fu) / sqrtf(rtb_Switch_b_idx_0 *
          rtb_Switch_b_idx_0 + rtb_Switch_b_idx_1 * rtb_Switch_b_idx_1);

        /* Saturate: '<S188>/Saturation' */
        if (rtb_Switch_b_idx_0 > 1.0F) {
          rtb_Switch_b_idx_0 = 1.0F;
        } else {
          if (rtb_Switch_b_idx_0 < 0.0F) {
            rtb_Switch_b_idx_0 = 0.0F;
          }
        }

        /* End of Saturate: '<S188>/Saturation' */

        /* Sum: '<S205>/Subtract' incorporates:
         *  Product: '<S205>/Multiply'
         *  Product: '<S205>/Multiply1'
         */
        rtb_Saturation_fu = rtb_Divide_h[0] * rtb_P_k[1] - rtb_Divide_h[1] *
          rtb_P_k[0];

        /* Signum: '<S201>/Sign1' */
        if (rtb_Saturation_fu < 0.0F) {
          rtb_Saturation_fu = -1.0F;
        } else {
          if (rtb_Saturation_fu > 0.0F) {
            rtb_Saturation_fu = 1.0F;
          }
        }

        /* End of Signum: '<S201>/Sign1' */

        /* Switch: '<S201>/Switch2' incorporates:
         *  Constant: '<S201>/Constant4'
         */
        if (rtb_Saturation_fu == 0.0F) {
          rtb_Saturation_fu = 1.0F;
        }

        /* End of Switch: '<S201>/Switch2' */

        /* DotProduct: '<S201>/Dot Product' */
        rtb_Switch_b_idx_1 = rtb_P_k[0] * rtb_Divide_h[0] + rtb_P_k[1] *
          rtb_Divide_h[1];

        /* Trigonometry: '<S201>/Acos' incorporates:
         *  DotProduct: '<S201>/Dot Product'
         */
        if (rtb_Switch_b_idx_1 > 1.0F) {
          rtb_Switch_b_idx_1 = 1.0F;
        } else {
          if (rtb_Switch_b_idx_1 < -1.0F) {
            rtb_Switch_b_idx_1 = -1.0F;
          }
        }

        /* Product: '<S201>/Multiply' incorporates:
         *  Trigonometry: '<S201>/Acos'
         */
        rtb_Saturation_fu *= acosf(rtb_Switch_b_idx_1);

        /* Saturate: '<S200>/Saturation' */
        if (rtb_Saturation_fu > 1.57079637F) {
          rtb_Saturation_fu = 1.57079637F;
        } else {
          if (rtb_Saturation_fu < -1.57079637F) {
            rtb_Saturation_fu = -1.57079637F;
          }
        }

        /* End of Saturate: '<S200>/Saturation' */

        /* Sqrt: '<S202>/Sqrt' */
        rtb_Saturation1_bl = sqrtf(rtb_Saturation_bu);

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S144>/Bus Assignment'
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S144>/Constant'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S144>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S144>/Constant4'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_k;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_ok;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_k;
        FMS_Y.FMS_Out.u_cmd = FMS_PARAM.CRUISE_SPEED;

        /* Product: '<S200>/Divide' incorporates:
         *  Constant: '<S191>/L1'
         *  Gain: '<S200>/Gain'
         *  Math: '<S200>/Square'
         *  Product: '<S200>/Multiply1'
         *  Trigonometry: '<S200>/Sin'
         */
        rtb_Saturation_bu = rtb_Saturation1_bl * rtb_Saturation1_bl * 2.0F *
          arm_sin_f32(rtb_Saturation_fu) / FMS_PARAM.L1;

        /* Saturate: '<S191>/Saturation1' */
        if (rtb_Saturation_bu > FMS_PARAM.ACC_Y_LIM) {
          /* BusAssignment: '<S144>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.ACC_Y_LIM;
        } else if (rtb_Saturation_bu < -FMS_PARAM.ACC_Y_LIM) {
          /* BusAssignment: '<S144>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.ACC_Y_LIM;
        } else {
          /* BusAssignment: '<S144>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = rtb_Saturation_bu;
        }

        /* End of Saturate: '<S191>/Saturation1' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Gain: '<S186>/Gain' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S188>/Multiply'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S186>/Sum2'
         *  Sum: '<S188>/Add'
         *  Sum: '<S188>/Subtract'
         */
        rtb_Saturation_bu = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
          FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Switch_b_idx_0 +
          FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Saturate: '<S186>/Saturation1' */
        if (rtb_Saturation_bu > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S144>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (rtb_Saturation_bu < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S144>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S144>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = rtb_Saturation_bu;
        }

        /* End of Saturate: '<S186>/Saturation1' */
        /* End of Outputs for SubSystem: '<S24>/Takeoff' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S24>/Land' incorporates:
         *  ActionPort: '<S142>/Action Port'
         */
        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S142>/Bus Assignment1'
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S142>/Constant1'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S142>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S142>/Constant'
         *  Constant: '<S142>/Constant4'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_c;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_h;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_ml;
        FMS_Y.FMS_Out.psi_rate_cmd = 0.0F;
        FMS_Y.FMS_Out.u_cmd = 0.0F;
        FMS_Y.FMS_Out.v_cmd = 0.0F;
        FMS_Y.FMS_Out.w_cmd = 0.5F;

        /* End of Outputs for SubSystem: '<S24>/Land' */
        break;

       case 2:
        /* Outputs for IfAction SubSystem: '<S24>/Return' incorporates:
         *  ActionPort: '<S143>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Math: '<S181>/Math Function' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_Divide_h[0] = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn;
        rtb_Divide_h[1] = FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* Sum: '<S181>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S181>/Math Function'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_Saturation_bu = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Math: '<S181>/Math Function1' incorporates:
         *  Sum: '<S181>/Sum of Elements'
         *
         * About '<S181>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_bu < 0.0F) {
          rtb_Saturation_bu = -sqrtf(fabsf(rtb_Saturation_bu));
        } else {
          rtb_Saturation_bu = sqrtf(rtb_Saturation_bu);
        }

        /* End of Math: '<S181>/Math Function1' */

        /* Switch: '<S181>/Switch' incorporates:
         *  Constant: '<S181>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S181>/Product'
         *  SignalConversion: '<S16>/Signal Copy1'
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

        /* End of Switch: '<S181>/Switch' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* MATLAB Function: '<S171>/NearbyRefWP' incorporates:
         *  Constant: '<S169>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_Switch_fz[0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                        FMS_PARAM.L1, rtb_Divide_h, &rtb_Saturation_fu);

        /* MATLAB Function: '<S171>/SearchL1RefWP' incorporates:
         *  Constant: '<S169>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        FMS_SearchL1RefWP(&rtb_Switch_a[0], &rtb_Switch_fz[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_P_k,
                          &rtb_Saturation_bu);

        /* MATLAB Function: '<S171>/OutRegionRegWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        FMS_OutRegionRegWP(&rtb_Switch_a[0], &rtb_Switch_fz[0],
                           FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, rtb_P_ia);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Switch: '<S171>/Switch1' incorporates:
         *  Constant: '<S174>/Constant'
         *  RelationalOperator: '<S174>/Compare'
         */
        if (rtb_Saturation_fu > 0.0F) {
          rtb_P_k[0] = rtb_Divide_h[0];
          rtb_P_k[1] = rtb_Divide_h[1];
        } else {
          /* RelationalOperator: '<S173>/Compare' incorporates:
           *  Constant: '<S173>/Constant'
           */
          rtb_Compare_ay = (rtb_Saturation_bu >= 0.0F);

          /* Switch: '<S171>/Switch' */
          if (!rtb_Compare_ay) {
            rtb_P_k[0] = rtb_P_ia[0];
            rtb_P_k[1] = rtb_P_ia[1];
          }

          /* End of Switch: '<S171>/Switch' */
        }

        /* End of Switch: '<S171>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S172>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_Divide_h[0] = rtb_P_k[0] - FMS_U.INS_Out.x_R;
        rtb_Divide_h[1] = rtb_P_k[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Sum: '<S182>/Sum of Elements' incorporates:
         *  Math: '<S182>/Math Function'
         */
        rtb_Saturation_bu = rtb_Divide_h[0] * rtb_Divide_h[0] + rtb_Divide_h[1] *
          rtb_Divide_h[1];

        /* Math: '<S182>/Math Function1' incorporates:
         *  Sum: '<S182>/Sum of Elements'
         *
         * About '<S182>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_bu < 0.0F) {
          rtb_Saturation_bu = -sqrtf(fabsf(rtb_Saturation_bu));
        } else {
          rtb_Saturation_bu = sqrtf(rtb_Saturation_bu);
        }

        /* End of Math: '<S182>/Math Function1' */

        /* Switch: '<S182>/Switch' incorporates:
         *  Constant: '<S182>/Constant'
         *  Product: '<S182>/Product'
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

        /* End of Switch: '<S182>/Switch' */

        /* Product: '<S181>/Divide' */
        rtb_Divide_h[0] = rtb_Switch_b_idx_0 / rtb_Switch_b_idx_2;
        rtb_Divide_h[1] = rtb_Switch_b_idx_1 / rtb_Switch_b_idx_2;

        /* Sum: '<S184>/Sum of Elements' incorporates:
         *  Math: '<S184>/Math Function'
         *  SignalConversion: '<S184>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Saturation_bu = rtb_Divide_h[1] * rtb_Divide_h[1] + rtb_Divide_h[0] *
          rtb_Divide_h[0];

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
          rtb_Switch_b_idx_0 = rtb_Divide_h[1];
          rtb_Switch_b_idx_1 = rtb_Divide_h[0];
          rtb_Switch_b_idx_2 = rtb_Saturation_bu;
        } else {
          rtb_Switch_b_idx_0 = 0.0F;
          rtb_Switch_b_idx_1 = 0.0F;
          rtb_Switch_b_idx_2 = 1.0F;
        }

        /* End of Switch: '<S184>/Switch' */

        /* Product: '<S182>/Divide' */
        rtb_Divide_h[0] = rtb_Switch_fz[0] / rtb_Switch_fz[2];
        rtb_Divide_h[1] = rtb_Switch_fz[1] / rtb_Switch_fz[2];

        /* Sum: '<S185>/Sum of Elements' incorporates:
         *  Math: '<S185>/Math Function'
         *  SignalConversion: '<S185>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Saturation_bu = rtb_Divide_h[1] * rtb_Divide_h[1] + rtb_Divide_h[0] *
          rtb_Divide_h[0];

        /* Math: '<S185>/Math Function1' incorporates:
         *  Sum: '<S185>/Sum of Elements'
         *
         * About '<S185>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_bu < 0.0F) {
          rtb_Saturation_bu = -sqrtf(fabsf(rtb_Saturation_bu));
        } else {
          rtb_Saturation_bu = sqrtf(rtb_Saturation_bu);
        }

        /* End of Math: '<S185>/Math Function1' */

        /* Switch: '<S185>/Switch' incorporates:
         *  Constant: '<S185>/Constant'
         *  Product: '<S185>/Product'
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

        /* End of Switch: '<S185>/Switch' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S166>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Saturation_bu = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
        rtb_Saturation_fu = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Product: '<S185>/Divide' */
        rtb_Divide_h[0] = rtb_Switch_fz[0] / rtb_Switch_fz[2];

        /* Product: '<S184>/Divide' */
        rtb_P_k[0] = rtb_Switch_b_idx_0 / rtb_Switch_b_idx_2;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S166>/Sum1' incorporates:
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_b_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_B.Cmd_In.cur_waypoint[0];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Product: '<S185>/Divide' */
        rtb_Divide_h[1] = rtb_Switch_fz[1] / rtb_Switch_fz[2];

        /* Product: '<S184>/Divide' */
        rtb_P_k[1] = rtb_Switch_b_idx_1 / rtb_Switch_b_idx_2;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S166>/Sum1' incorporates:
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_b_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Product: '<S166>/Divide' incorporates:
         *  Math: '<S167>/Square'
         *  Math: '<S168>/Square'
         *  Sqrt: '<S167>/Sqrt'
         *  Sqrt: '<S168>/Sqrt'
         *  Sum: '<S166>/Sum'
         *  Sum: '<S166>/Sum1'
         *  Sum: '<S167>/Sum of Elements'
         *  Sum: '<S168>/Sum of Elements'
         */
        rtb_Switch_b_idx_0 = sqrtf(rtb_Saturation_fu * rtb_Saturation_fu +
          rtb_Saturation_bu * rtb_Saturation_bu) / sqrtf(rtb_Switch_b_idx_0 *
          rtb_Switch_b_idx_0 + rtb_Switch_b_idx_1 * rtb_Switch_b_idx_1);

        /* Saturate: '<S166>/Saturation' */
        if (rtb_Switch_b_idx_0 > 1.0F) {
          rtb_Switch_b_idx_0 = 1.0F;
        } else {
          if (rtb_Switch_b_idx_0 < 0.0F) {
            rtb_Switch_b_idx_0 = 0.0F;
          }
        }

        /* End of Saturate: '<S166>/Saturation' */

        /* Sum: '<S183>/Subtract' incorporates:
         *  Product: '<S183>/Multiply'
         *  Product: '<S183>/Multiply1'
         */
        rtb_Saturation_bu = rtb_Divide_h[0] * rtb_P_k[1] - rtb_Divide_h[1] *
          rtb_P_k[0];

        /* Signum: '<S179>/Sign1' */
        if (rtb_Saturation_bu < 0.0F) {
          rtb_Saturation_bu = -1.0F;
        } else {
          if (rtb_Saturation_bu > 0.0F) {
            rtb_Saturation_bu = 1.0F;
          }
        }

        /* End of Signum: '<S179>/Sign1' */

        /* Switch: '<S179>/Switch2' incorporates:
         *  Constant: '<S179>/Constant4'
         */
        if (rtb_Saturation_bu == 0.0F) {
          rtb_Saturation_bu = 1.0F;
        }

        /* End of Switch: '<S179>/Switch2' */

        /* DotProduct: '<S179>/Dot Product' */
        rtb_Switch_b_idx_1 = rtb_P_k[0] * rtb_Divide_h[0] + rtb_P_k[1] *
          rtb_Divide_h[1];

        /* Trigonometry: '<S179>/Acos' incorporates:
         *  DotProduct: '<S179>/Dot Product'
         */
        if (rtb_Switch_b_idx_1 > 1.0F) {
          rtb_Switch_b_idx_1 = 1.0F;
        } else {
          if (rtb_Switch_b_idx_1 < -1.0F) {
            rtb_Switch_b_idx_1 = -1.0F;
          }
        }

        /* Product: '<S179>/Multiply' incorporates:
         *  Trigonometry: '<S179>/Acos'
         */
        rtb_Saturation_bu *= acosf(rtb_Switch_b_idx_1);

        /* Saturate: '<S178>/Saturation' */
        if (rtb_Saturation_bu > 1.57079637F) {
          rtb_Saturation_bu = 1.57079637F;
        } else {
          if (rtb_Saturation_bu < -1.57079637F) {
            rtb_Saturation_bu = -1.57079637F;
          }
        }

        /* End of Saturate: '<S178>/Saturation' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sqrt: '<S180>/Sqrt' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S180>/Square'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  Sum: '<S180>/Sum of Elements'
         */
        rtb_Saturation_fu = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Outport: '<Root>/FMS_Out' incorporates:
         *  BusAssignment: '<S143>/Bus Assignment1'
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S143>/Constant2'
         */
        FMS_Y.FMS_Out = FMS_rtZFMS_Out_Bus;

        /* BusAssignment: '<S143>/Bus Assignment1' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Constant: '<S143>/Constant4'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.status = FMS_ConstB.DataTypeConversion_o;
        FMS_Y.FMS_Out.state = FMS_ConstB.DataTypeConversion1_m;
        FMS_Y.FMS_Out.ctrl_mode = FMS_ConstB.DataTypeConversion2_p;
        FMS_Y.FMS_Out.u_cmd = FMS_PARAM.CRUISE_SPEED;

        /* Product: '<S178>/Divide' incorporates:
         *  Constant: '<S169>/L1'
         *  Gain: '<S178>/Gain'
         *  Math: '<S178>/Square'
         *  Product: '<S178>/Multiply1'
         *  Trigonometry: '<S178>/Sin'
         */
        rtb_Saturation_bu = rtb_Saturation_fu * rtb_Saturation_fu * 2.0F *
          arm_sin_f32(rtb_Saturation_bu) / FMS_PARAM.L1;

        /* Saturate: '<S169>/Saturation1' */
        if (rtb_Saturation_bu > FMS_PARAM.ACC_Y_LIM) {
          /* BusAssignment: '<S143>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.ACC_Y_LIM;
        } else if (rtb_Saturation_bu < -FMS_PARAM.ACC_Y_LIM) {
          /* BusAssignment: '<S143>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = -FMS_PARAM.ACC_Y_LIM;
        } else {
          /* BusAssignment: '<S143>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = rtb_Saturation_bu;
        }

        /* End of Saturate: '<S169>/Saturation1' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Gain: '<S164>/Gain' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S166>/Multiply'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         *  Sum: '<S164>/Sum2'
         *  Sum: '<S166>/Add'
         *  Sum: '<S166>/Subtract'
         */
        rtb_Saturation_bu = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
          FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Switch_b_idx_0 +
          FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Saturate: '<S164>/Saturation1' */
        if (rtb_Saturation_bu > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S143>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (rtb_Saturation_bu < -FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S143>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = -FMS_PARAM.VEL_Z_LIM;
        } else {
          /* BusAssignment: '<S143>/Bus Assignment1' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = rtb_Saturation_bu;
        }

        /* End of Saturate: '<S164>/Saturation1' */
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
           */
          FMS_DW.icLoad_n = 1U;
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
        rtb_Saturation_bu = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Math: '<S158>/Math Function1' incorporates:
         *  Sum: '<S158>/Sum of Elements'
         *
         * About '<S158>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_bu < 0.0F) {
          rtb_Saturation_bu = -sqrtf(fabsf(rtb_Saturation_bu));
        } else {
          rtb_Saturation_bu = sqrtf(rtb_Saturation_bu);
        }

        /* End of Math: '<S158>/Math Function1' */

        /* Switch: '<S158>/Switch' incorporates:
         *  Constant: '<S158>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S158>/Product'
         *  SignalConversion: '<S16>/Signal Copy1'
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
        rtb_Saturation_bu = FMS_DW.start_vel_DSTATE_g[0] *
          FMS_DW.start_vel_DSTATE_g[0] + FMS_DW.start_vel_DSTATE_g[1] *
          FMS_DW.start_vel_DSTATE_g[1];

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
         *  Delay: '<S151>/start_vel'
         *  Product: '<S163>/Product'
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

        /* End of Switch: '<S163>/Switch' */

        /* Product: '<S158>/Divide' */
        rtb_Divide_h[0] = rtb_Switch_fz[0] / rtb_Switch_fz[2];
        rtb_Divide_h[1] = rtb_Switch_fz[1] / rtb_Switch_fz[2];

        /* Sum: '<S161>/Sum of Elements' incorporates:
         *  Math: '<S161>/Math Function'
         *  SignalConversion: '<S161>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Saturation_bu = rtb_Divide_h[1] * rtb_Divide_h[1] + rtb_Divide_h[0] *
          rtb_Divide_h[0];

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
          rtb_Switch_fz[0] = rtb_Divide_h[1];
          rtb_Switch_fz[1] = rtb_Divide_h[0];
          rtb_Switch_fz[2] = rtb_Saturation_bu;
        } else {
          rtb_Switch_fz[0] = 0.0F;
          rtb_Switch_fz[1] = 0.0F;
          rtb_Switch_fz[2] = 1.0F;
        }

        /* End of Switch: '<S161>/Switch' */

        /* MinMax: '<S149>/Max' incorporates:
         *  Constant: '<S147>/L1'
         *  Constant: '<S147>/R'
         *  Gain: '<S149>/Gain'
         */
        rtb_Saturation_fu = fmaxf(FMS_PARAM.LOITER_R, 0.5F * FMS_PARAM.L1);

        /* MATLAB Function: '<S149>/SearchL1RefWP' incorporates:
         *  Constant: '<S147>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
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

        /* End of MATLAB Function: '<S149>/SearchL1RefWP' */
        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* RelationalOperator: '<S152>/Compare' incorporates:
         *  Constant: '<S152>/Constant'
         */
        rtb_Compare_ay = (i > 0);

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* MATLAB Function: '<S149>/OutRegionRegWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_b_idx_0 = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_P_ia[0] = rtb_Switch_b_idx_0 * rtb_Switch_b_idx_0;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        rtb_Switch_b_idx_0 = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_P_ia[1] = rtb_Switch_b_idx_0 * rtb_Switch_b_idx_0;

        /* Switch: '<S149>/Switch' incorporates:
         *  Constant: '<S147>/L1'
         *  Inport: '<Root>/INS_Out'
         *  MATLAB Function: '<S149>/OutRegionRegWP'
         *  Product: '<S163>/Divide'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        if (rtb_Compare_ay) {
          rtb_Saturation_bu = rtb_P_k[0];
        } else if (rtb_P_ia[0] + rtb_P_ia[1] > rtb_Saturation_fu *
                   rtb_Saturation_fu) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* MATLAB Function: '<S149>/OutRegionRegWP' incorporates:
           *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
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
        /* Sum: '<S150>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_Switch_b_idx_1 = rtb_Saturation_bu - FMS_U.INS_Out.x_R;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Switch: '<S149>/Switch' incorporates:
         *  Constant: '<S147>/L1'
         *  Inport: '<Root>/INS_Out'
         *  MATLAB Function: '<S149>/OutRegionRegWP'
         *  Product: '<S163>/Divide'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        if (rtb_Compare_ay) {
          rtb_Saturation_bu = rtb_P_k[1];
        } else if (rtb_P_ia[0] + rtb_P_ia[1] > rtb_Saturation_fu *
                   rtb_Saturation_fu) {
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* MATLAB Function: '<S149>/OutRegionRegWP' incorporates:
           *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
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
        /* Sum: '<S150>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_Switch_b_idx_0 = rtb_Saturation_bu - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Sum: '<S159>/Sum of Elements' incorporates:
         *  Math: '<S159>/Math Function'
         */
        rtb_Saturation_bu = rtb_Switch_b_idx_1 * rtb_Switch_b_idx_1 +
          rtb_Switch_b_idx_0 * rtb_Switch_b_idx_0;

        /* Math: '<S159>/Math Function1' incorporates:
         *  Sum: '<S159>/Sum of Elements'
         *
         * About '<S159>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_bu < 0.0F) {
          rtb_Saturation_bu = -sqrtf(fabsf(rtb_Saturation_bu));
        } else {
          rtb_Saturation_bu = sqrtf(rtb_Saturation_bu);
        }

        /* End of Math: '<S159>/Math Function1' */

        /* Switch: '<S159>/Switch' incorporates:
         *  Constant: '<S159>/Constant'
         *  Product: '<S159>/Product'
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

        /* End of Switch: '<S159>/Switch' */

        /* Product: '<S159>/Divide' */
        rtb_Divide_h[0] = rtb_Switch_a[0] / rtb_Switch_a[2];
        rtb_Divide_h[1] = rtb_Switch_a[1] / rtb_Switch_a[2];

        /* Sum: '<S162>/Sum of Elements' incorporates:
         *  Math: '<S162>/Math Function'
         *  SignalConversion: '<S162>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Saturation_bu = rtb_Divide_h[1] * rtb_Divide_h[1] + rtb_Divide_h[0] *
          rtb_Divide_h[0];

        /* Math: '<S162>/Math Function1' incorporates:
         *  Sum: '<S162>/Sum of Elements'
         *
         * About '<S162>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_bu < 0.0F) {
          rtb_Saturation_bu = -sqrtf(fabsf(rtb_Saturation_bu));
        } else {
          rtb_Saturation_bu = sqrtf(rtb_Saturation_bu);
        }

        /* End of Math: '<S162>/Math Function1' */

        /* Switch: '<S162>/Switch' incorporates:
         *  Constant: '<S162>/Constant'
         *  Product: '<S162>/Product'
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

        /* End of Switch: '<S162>/Switch' */

        /* Product: '<S162>/Divide' */
        rtb_Divide_h[0] = rtb_Switch_a[0] / rtb_Switch_a[2];

        /* Product: '<S161>/Divide' */
        rtb_P_k[0] = rtb_Switch_fz[0] / rtb_Switch_fz[2];

        /* Product: '<S162>/Divide' */
        rtb_Divide_h[1] = rtb_Switch_a[1] / rtb_Switch_a[2];

        /* Product: '<S161>/Divide' */
        rtb_P_k[1] = rtb_Switch_fz[1] / rtb_Switch_fz[2];

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sqrt: '<S157>/Sqrt' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S157>/Square'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  Sum: '<S157>/Sum of Elements'
         */
        rtb_Saturation_bu = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Math: '<S155>/Square' */
        rtb_Switch_b_idx_0 = rtb_Saturation_bu * rtb_Saturation_bu;

        /* Sum: '<S160>/Subtract' incorporates:
         *  Product: '<S160>/Multiply'
         *  Product: '<S160>/Multiply1'
         */
        rtb_Saturation_bu = rtb_Divide_h[0] * rtb_P_k[1] - rtb_Divide_h[1] *
          rtb_P_k[0];

        /* Signum: '<S156>/Sign1' */
        if (rtb_Saturation_bu < 0.0F) {
          rtb_Saturation_bu = -1.0F;
        } else {
          if (rtb_Saturation_bu > 0.0F) {
            rtb_Saturation_bu = 1.0F;
          }
        }

        /* End of Signum: '<S156>/Sign1' */

        /* Switch: '<S156>/Switch2' incorporates:
         *  Constant: '<S156>/Constant4'
         */
        if (rtb_Saturation_bu == 0.0F) {
          rtb_Saturation_bu = 1.0F;
        }

        /* End of Switch: '<S156>/Switch2' */

        /* DotProduct: '<S156>/Dot Product' */
        rtb_Switch_b_idx_1 = rtb_P_k[0] * rtb_Divide_h[0] + rtb_P_k[1] *
          rtb_Divide_h[1];

        /* Trigonometry: '<S156>/Acos' incorporates:
         *  DotProduct: '<S156>/Dot Product'
         */
        if (rtb_Switch_b_idx_1 > 1.0F) {
          rtb_Switch_b_idx_1 = 1.0F;
        } else {
          if (rtb_Switch_b_idx_1 < -1.0F) {
            rtb_Switch_b_idx_1 = -1.0F;
          }
        }

        /* Product: '<S156>/Multiply' incorporates:
         *  Trigonometry: '<S156>/Acos'
         */
        rtb_Saturation_bu *= acosf(rtb_Switch_b_idx_1);

        /* Saturate: '<S155>/Saturation' */
        if (rtb_Saturation_bu > 1.57079637F) {
          rtb_Saturation_bu = 1.57079637F;
        } else {
          if (rtb_Saturation_bu < -1.57079637F) {
            rtb_Saturation_bu = -1.57079637F;
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
         *  Product: '<S155>/Multiply1'
         *  Trigonometry: '<S155>/Sin'
         */
        rtb_Saturation_bu = 2.0F * rtb_Switch_b_idx_0 * arm_sin_f32
          (rtb_Saturation_bu) / FMS_PARAM.L1;

        /* Saturate: '<S150>/Saturation' */
        if (rtb_Saturation_bu > 9.81F) {
          /* BusAssignment: '<S141>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = 9.81F;
        } else if (rtb_Saturation_bu < -9.81F) {
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
          FMS_Y.FMS_Out.ay_cmd = rtb_Saturation_bu;
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
        rtb_Divide_h[0] = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn;
        rtb_Divide_h[1] = FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* Sum: '<S134>/Sum of Elements' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Math: '<S134>/Math Function'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_Saturation_bu = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Math: '<S134>/Math Function1' incorporates:
         *  Sum: '<S134>/Sum of Elements'
         *
         * About '<S134>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_bu < 0.0F) {
          rtb_Saturation_bu = -sqrtf(fabsf(rtb_Saturation_bu));
        } else {
          rtb_Saturation_bu = sqrtf(rtb_Saturation_bu);
        }

        /* End of Math: '<S134>/Math Function1' */

        /* Switch: '<S134>/Switch' incorporates:
         *  Constant: '<S134>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S134>/Product'
         *  SignalConversion: '<S16>/Signal Copy1'
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

        /* End of Switch: '<S134>/Switch' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* MATLAB Function: '<S124>/NearbyRefWP' incorporates:
         *  Constant: '<S122>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        FMS_NearbyRefWP(&rtb_Switch_fz[0], FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R,
                        FMS_PARAM.L1, rtb_Divide_h, &rtb_Saturation_fu);

        /* MATLAB Function: '<S124>/SearchL1RefWP' incorporates:
         *  Constant: '<S122>/L1'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        FMS_SearchL1RefWP(&rtb_Switch_a[0], &rtb_Switch_fz[0], FMS_U.INS_Out.x_R,
                          FMS_U.INS_Out.y_R, FMS_PARAM.L1, rtb_P_k,
                          &rtb_Saturation_bu);

        /* MATLAB Function: '<S124>/OutRegionRegWP' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        FMS_OutRegionRegWP(&rtb_Switch_a[0], &rtb_Switch_fz[0],
                           FMS_U.INS_Out.x_R, FMS_U.INS_Out.y_R, rtb_P_ia);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Switch: '<S124>/Switch1' incorporates:
         *  Constant: '<S127>/Constant'
         *  RelationalOperator: '<S127>/Compare'
         */
        if (rtb_Saturation_fu > 0.0F) {
          rtb_P_k[0] = rtb_Divide_h[0];
          rtb_P_k[1] = rtb_Divide_h[1];
        } else {
          /* RelationalOperator: '<S126>/Compare' incorporates:
           *  Constant: '<S126>/Constant'
           */
          rtb_Compare_ay = (rtb_Saturation_bu >= 0.0F);

          /* Switch: '<S124>/Switch' */
          if (!rtb_Compare_ay) {
            rtb_P_k[0] = rtb_P_ia[0];
            rtb_P_k[1] = rtb_P_ia[1];
          }

          /* End of Switch: '<S124>/Switch' */
        }

        /* End of Switch: '<S124>/Switch1' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S125>/Subtract' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         */
        rtb_Divide_h[0] = rtb_P_k[0] - FMS_U.INS_Out.x_R;
        rtb_Divide_h[1] = rtb_P_k[1] - FMS_U.INS_Out.y_R;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Sum: '<S135>/Sum of Elements' incorporates:
         *  Math: '<S135>/Math Function'
         */
        rtb_Saturation_bu = rtb_Divide_h[0] * rtb_Divide_h[0] + rtb_Divide_h[1] *
          rtb_Divide_h[1];

        /* Math: '<S135>/Math Function1' incorporates:
         *  Sum: '<S135>/Sum of Elements'
         *
         * About '<S135>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_bu < 0.0F) {
          rtb_Saturation_bu = -sqrtf(fabsf(rtb_Saturation_bu));
        } else {
          rtb_Saturation_bu = sqrtf(rtb_Saturation_bu);
        }

        /* End of Math: '<S135>/Math Function1' */

        /* Switch: '<S135>/Switch' incorporates:
         *  Constant: '<S135>/Constant'
         *  Product: '<S135>/Product'
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

        /* End of Switch: '<S135>/Switch' */

        /* Product: '<S134>/Divide' */
        rtb_Divide_h[0] = rtb_Switch_b_idx_0 / rtb_Switch_b_idx_2;
        rtb_Divide_h[1] = rtb_Switch_b_idx_1 / rtb_Switch_b_idx_2;

        /* Sum: '<S137>/Sum of Elements' incorporates:
         *  Math: '<S137>/Math Function'
         *  SignalConversion: '<S137>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Saturation_bu = rtb_Divide_h[1] * rtb_Divide_h[1] + rtb_Divide_h[0] *
          rtb_Divide_h[0];

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
          rtb_Switch_b_idx_0 = rtb_Divide_h[1];
          rtb_Switch_b_idx_1 = rtb_Divide_h[0];
          rtb_Switch_b_idx_2 = rtb_Saturation_bu;
        } else {
          rtb_Switch_b_idx_0 = 0.0F;
          rtb_Switch_b_idx_1 = 0.0F;
          rtb_Switch_b_idx_2 = 1.0F;
        }

        /* End of Switch: '<S137>/Switch' */

        /* Product: '<S135>/Divide' */
        rtb_Divide_h[0] = rtb_Switch_fz[0] / rtb_Switch_fz[2];
        rtb_Divide_h[1] = rtb_Switch_fz[1] / rtb_Switch_fz[2];

        /* Sum: '<S138>/Sum of Elements' incorporates:
         *  Math: '<S138>/Math Function'
         *  SignalConversion: '<S138>/TmpSignal ConversionAtMath FunctionInport1'
         */
        rtb_Saturation_bu = rtb_Divide_h[1] * rtb_Divide_h[1] + rtb_Divide_h[0] *
          rtb_Divide_h[0];

        /* Math: '<S138>/Math Function1' incorporates:
         *  Sum: '<S138>/Sum of Elements'
         *
         * About '<S138>/Math Function1':
         *  Operator: sqrt
         */
        if (rtb_Saturation_bu < 0.0F) {
          rtb_Saturation_bu = -sqrtf(fabsf(rtb_Saturation_bu));
        } else {
          rtb_Saturation_bu = sqrtf(rtb_Saturation_bu);
        }

        /* End of Math: '<S138>/Math Function1' */

        /* Switch: '<S138>/Switch' incorporates:
         *  Constant: '<S138>/Constant'
         *  Product: '<S138>/Product'
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

        /* End of Switch: '<S138>/Switch' */

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S119>/Sum' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Saturation_bu = FMS_U.INS_Out.x_R - FMS_B.Cmd_In.cur_waypoint[0];
        rtb_Saturation_fu = FMS_U.INS_Out.y_R - FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Product: '<S138>/Divide' */
        rtb_Divide_h[0] = rtb_Switch_fz[0] / rtb_Switch_fz[2];

        /* Product: '<S137>/Divide' */
        rtb_P_k[0] = rtb_Switch_b_idx_0 / rtb_Switch_b_idx_2;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S119>/Sum1' incorporates:
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_b_idx_0 = FMS_B.Cmd_In.sp_waypoint[0] -
          FMS_B.Cmd_In.cur_waypoint[0];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Product: '<S138>/Divide' */
        rtb_Divide_h[1] = rtb_Switch_fz[1] / rtb_Switch_fz[2];

        /* Product: '<S137>/Divide' */
        rtb_P_k[1] = rtb_Switch_b_idx_1 / rtb_Switch_b_idx_2;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Sum: '<S119>/Sum1' incorporates:
         *  SignalConversion: '<S16>/TmpSignal ConversionAtSignal Copy3Inport1'
         */
        rtb_Switch_b_idx_1 = FMS_B.Cmd_In.sp_waypoint[1] -
          FMS_B.Cmd_In.cur_waypoint[1];

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Product: '<S119>/Divide' incorporates:
         *  Math: '<S120>/Square'
         *  Math: '<S121>/Square'
         *  Sqrt: '<S120>/Sqrt'
         *  Sqrt: '<S121>/Sqrt'
         *  Sum: '<S119>/Sum'
         *  Sum: '<S119>/Sum1'
         *  Sum: '<S120>/Sum of Elements'
         *  Sum: '<S121>/Sum of Elements'
         */
        rtb_Switch_b_idx_0 = sqrtf(rtb_Saturation_fu * rtb_Saturation_fu +
          rtb_Saturation_bu * rtb_Saturation_bu) / sqrtf(rtb_Switch_b_idx_0 *
          rtb_Switch_b_idx_0 + rtb_Switch_b_idx_1 * rtb_Switch_b_idx_1);

        /* Saturate: '<S119>/Saturation' */
        if (rtb_Switch_b_idx_0 > 1.0F) {
          rtb_Switch_b_idx_0 = 1.0F;
        } else {
          if (rtb_Switch_b_idx_0 < 0.0F) {
            rtb_Switch_b_idx_0 = 0.0F;
          }
        }

        /* End of Saturate: '<S119>/Saturation' */

        /* Sum: '<S136>/Subtract' incorporates:
         *  Product: '<S136>/Multiply'
         *  Product: '<S136>/Multiply1'
         */
        rtb_Saturation_bu = rtb_Divide_h[0] * rtb_P_k[1] - rtb_Divide_h[1] *
          rtb_P_k[0];

        /* Signum: '<S132>/Sign1' */
        if (rtb_Saturation_bu < 0.0F) {
          rtb_Saturation_bu = -1.0F;
        } else {
          if (rtb_Saturation_bu > 0.0F) {
            rtb_Saturation_bu = 1.0F;
          }
        }

        /* End of Signum: '<S132>/Sign1' */

        /* Switch: '<S132>/Switch2' incorporates:
         *  Constant: '<S132>/Constant4'
         */
        if (rtb_Saturation_bu == 0.0F) {
          rtb_Saturation_bu = 1.0F;
        }

        /* End of Switch: '<S132>/Switch2' */

        /* DotProduct: '<S132>/Dot Product' */
        rtb_Switch_b_idx_1 = rtb_P_k[0] * rtb_Divide_h[0] + rtb_P_k[1] *
          rtb_Divide_h[1];

        /* Trigonometry: '<S132>/Acos' incorporates:
         *  DotProduct: '<S132>/Dot Product'
         */
        if (rtb_Switch_b_idx_1 > 1.0F) {
          rtb_Switch_b_idx_1 = 1.0F;
        } else {
          if (rtb_Switch_b_idx_1 < -1.0F) {
            rtb_Switch_b_idx_1 = -1.0F;
          }
        }

        /* Product: '<S132>/Multiply' incorporates:
         *  Trigonometry: '<S132>/Acos'
         */
        rtb_Saturation_bu *= acosf(rtb_Switch_b_idx_1);

        /* Saturate: '<S131>/Saturation' */
        if (rtb_Saturation_bu > 1.57079637F) {
          rtb_Saturation_bu = 1.57079637F;
        } else {
          if (rtb_Saturation_bu < -1.57079637F) {
            rtb_Saturation_bu = -1.57079637F;
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
        rtb_Saturation_fu = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
          FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

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
         *  Trigonometry: '<S131>/Sin'
         */
        rtb_Saturation_bu = rtb_Saturation_fu * rtb_Saturation_fu * 2.0F *
          arm_sin_f32(rtb_Saturation_bu) / FMS_PARAM.L1;

        /* Saturate: '<S122>/Saturation1' */
        if (rtb_Saturation_bu > FMS_PARAM.ACC_Y_LIM) {
          /* BusAssignment: '<S116>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.ay_cmd = FMS_PARAM.ACC_Y_LIM;
        } else if (rtb_Saturation_bu < -FMS_PARAM.ACC_Y_LIM) {
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
          FMS_Y.FMS_Out.ay_cmd = rtb_Saturation_bu;
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
        rtb_Saturation_bu = (FMS_U.INS_Out.h_R - ((FMS_B.Cmd_In.sp_waypoint[2] -
          FMS_B.Cmd_In.cur_waypoint[2]) * rtb_Switch_b_idx_0 +
          FMS_B.Cmd_In.cur_waypoint[2])) * FMS_PARAM.Z_P;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Saturate: '<S117>/Saturation1' */
        if (rtb_Saturation_bu > FMS_PARAM.VEL_Z_LIM) {
          /* BusAssignment: '<S116>/Bus Assignment' incorporates:
           *  BusAssignment: '<S18>/Bus Assignment'
           *  Outport: '<Root>/FMS_Out'
           */
          FMS_Y.FMS_Out.w_cmd = FMS_PARAM.VEL_Z_LIM;
        } else if (rtb_Saturation_bu < -FMS_PARAM.VEL_Z_LIM) {
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
          FMS_Y.FMS_Out.w_cmd = rtb_Saturation_bu;
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
          rtb_Saturation_bu = 2.0F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
          rtb_Saturation_bu = 0.0F;
        } else {
          rtb_Saturation_bu = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
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
        FMS_Y.FMS_Out.throttle_cmd = (uint16_T)((uint16_T)fmodf(floorf(500.0F *
          rtb_Saturation_bu), 65536.0F) + 1000U);

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
          rtb_Saturation_bu = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_Saturation_bu = 0.0F;
        } else {
          rtb_Saturation_bu = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
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
          rtb_Saturation_bu * FMS_PARAM.ROLL_LIM;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* DeadZone: '<S104>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_pitch > FMS_PARAM.PITCH_DZ) {
          rtb_Saturation_bu = FMS_U.Pilot_Cmd.stick_pitch - FMS_PARAM.PITCH_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_pitch >= -FMS_PARAM.PITCH_DZ) {
          rtb_Saturation_bu = 0.0F;
        } else {
          rtb_Saturation_bu = FMS_U.Pilot_Cmd.stick_pitch - (-FMS_PARAM.PITCH_DZ);
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
          rtb_Saturation_bu * -FMS_PARAM.PITCH_LIM;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* DeadZone: '<S109>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
          rtb_Saturation_bu = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
          rtb_Saturation_bu = 0.0F;
        } else {
          rtb_Saturation_bu = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
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
          rtb_Saturation_bu * FMS_PARAM.YAW_RATE_LIM;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Saturate: '<S102>/Saturation' incorporates:
         *  Constant: '<S102>/Constant4'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         *  Sum: '<S102>/Sum'
         */
        if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F > 2.0F) {
          rtb_Saturation_bu = 2.0F;
        } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
          rtb_Saturation_bu = 0.0F;
        } else {
          rtb_Saturation_bu = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
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
        FMS_Y.FMS_Out.throttle_cmd = (uint16_T)((uint16_T)fmodf(floorf(500.0F *
          rtb_Saturation_bu), 65536.0F) + 1000U);

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
          FMS_MotionStatus_Reset(&FMS_DW.sf_MotionStatus);

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
                         fabsf(FMS_U.INS_Out.vd), &rtb_state_g,
                         &FMS_DW.sf_MotionStatus);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* SwitchCase: '<S37>/Switch Case' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  SignalConversion: '<S16>/Signal Copy2'
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
            /* SystemReset for IfAction SubSystem: '<S37>/Hold Control' incorporates:
             *  ActionPort: '<S40>/Action Port'
             */
            /* SystemReset for SwitchCase: '<S37>/Switch Case' */
            FMS_HoldControl_Reset(&FMS_DW.HoldControl);

            /* End of SystemReset for SubSystem: '<S37>/Hold Control' */
          }

          /* Outputs for IfAction SubSystem: '<S37>/Hold Control' incorporates:
           *  ActionPort: '<S40>/Action Port'
           */
          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          FMS_HoldControl(FMS_U.INS_Out.h_R, &FMS_B.Merge_l, &FMS_DW.HoldControl);

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
          rtb_Saturation_bu = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
          rtb_Saturation_bu = 0.0F;
        } else {
          rtb_Saturation_bu = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
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
          rtb_Saturation_bu * FMS_PARAM.ROLL_LIM;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* DeadZone: '<S51>/Dead Zone' incorporates:
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        if (FMS_U.Pilot_Cmd.stick_yaw > FMS_PARAM.YAW_DZ) {
          rtb_Saturation_bu = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
          rtb_Saturation_bu = 0.0F;
        } else {
          rtb_Saturation_bu = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
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
          rtb_Saturation_bu * FMS_PARAM.YAW_RATE_LIM;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Gain: '<S33>/Gain1' incorporates:
         *  Bias: '<S33>/Bias'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        rtb_Saturation_bu = (FMS_U.Pilot_Cmd.stick_throttle + 1.0F) * 0.5F;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Saturate: '<S33>/Saturation' incorporates:
         *  Gain: '<S33>/Gain1'
         */
        if (rtb_Saturation_bu > 1.0F) {
          rtb_Saturation_bu = 1.0F;
        } else {
          if (rtb_Saturation_bu < 0.0F) {
            rtb_Saturation_bu = 0.0F;
          }
        }

        /* End of Saturate: '<S33>/Saturation' */

        /* BusAssignment: '<S27>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Gain: '<S33>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_AIRSPD_MAX * rtb_Saturation_bu;

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
          FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_p;

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
         *  Trigonometry: '<S99>/Trigonometric Function3'
         */
        rtb_Saturation_bu = arm_cos_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_VectorConcatenate[0] = rtb_Saturation_bu;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Trigonometry: '<S99>/Trigonometric Function' incorporates:
         *  Gain: '<S98>/Gain'
         *  Inport: '<Root>/INS_Out'
         *  SignalConversion: '<S16>/Signal Copy1'
         *  Trigonometry: '<S99>/Trigonometric Function2'
         */
        rtb_Switch_b_idx_0 = arm_sin_f32(-FMS_U.INS_Out.psi);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
        rtb_VectorConcatenate[1] = rtb_Switch_b_idx_0;

        /* SignalConversion: '<S99>/ConcatBufferAtVector Concatenate1In3' incorporates:
         *  Constant: '<S99>/Constant3'
         */
        rtb_VectorConcatenate[2] = 0.0F;

        /* Gain: '<S99>/Gain' */
        rtb_VectorConcatenate[3] = -rtb_Switch_b_idx_0;

        /* Trigonometry: '<S99>/Trigonometric Function3' */
        rtb_VectorConcatenate[4] = rtb_Saturation_bu;

        /* SignalConversion: '<S99>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S99>/Constant4'
         */
        rtb_VectorConcatenate[5] = 0.0F;

        /* SignalConversion: '<S99>/ConcatBufferAtVector ConcatenateIn3' */
        rtb_VectorConcatenate[6] = FMS_ConstB.VectorConcatenate3[0];
        rtb_VectorConcatenate[7] = FMS_ConstB.VectorConcatenate3[1];
        rtb_VectorConcatenate[8] = FMS_ConstB.VectorConcatenate3[2];

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
                         fabsf(FMS_U.INS_Out.vd), &rtb_state_g,
                         &FMS_DW.sf_MotionStatus_j);

        /* RelationalOperator: '<S96>/Compare' incorporates:
         *  Abs: '<S73>/Abs1'
         *  Constant: '<S96>/Constant'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        rtb_Compare_ay = (fabsf(FMS_U.Pilot_Cmd.stick_roll) > FMS_PARAM.ROLL_DZ);

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Chart: '<S73>/Motion State' incorporates:
         *  Abs: '<S73>/Abs'
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

            /* Product: '<S73>/Multiply' incorporates:
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

            /* End of Product: '<S73>/Multiply' */
            if ((fabsf(rtb_VectorConcatenate_0[1]) <= 0.2) ||
                (FMS_DW.temporalCounter_i1_i >= 625U)) {
              FMS_DW.is_c16_FMS = FMS_IN_Hold_l;
              rtb_state = MotionState_Hold;
            } else {
              if (rtb_Compare_ay) {
                FMS_DW.is_c16_FMS = FMS_IN_Move_h;
                rtb_state = MotionState_Move;
              }
            }
            break;

           case FMS_IN_Hold_l:
            rtb_state = MotionState_Hold;
            if (rtb_Compare_ay) {
              FMS_DW.is_c16_FMS = FMS_IN_Move_h;
              rtb_state = MotionState_Move;
            }
            break;

           default:
            rtb_state = MotionState_Move;
            if (!rtb_Compare_ay) {
              FMS_DW.is_c16_FMS = FMS_IN_Brake_d;
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
         *  Switch: '<S77>/Switch'
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
          rtb_Saturation_bu = FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Math: '<S87>/Math Function1' incorporates:
           *  Sum: '<S87>/Sum of Elements'
           *
           * About '<S87>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_bu < 0.0F) {
            rtb_Switch_b_idx_0 = -sqrtf(fabsf(rtb_Saturation_bu));
          } else {
            rtb_Switch_b_idx_0 = sqrtf(rtb_Saturation_bu);
          }

          /* End of Math: '<S87>/Math Function1' */

          /* Switch: '<S87>/Switch' incorporates:
           *  Constant: '<S87>/Constant'
           *  Inport: '<Root>/INS_Out'
           *  Product: '<S87>/Product'
           *  SignalConversion: '<S16>/Signal Copy1'
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
          rtb_Saturation_bu = FMS_DW.start_vel_DSTATE[0] *
            FMS_DW.start_vel_DSTATE[0] + FMS_DW.start_vel_DSTATE[1] *
            FMS_DW.start_vel_DSTATE[1];

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
           *  Delay: '<S79>/start_vel'
           *  Product: '<S92>/Product'
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

          /* End of Switch: '<S92>/Switch' */

          /* Product: '<S87>/Divide' */
          rtb_Divide_h[0] = rtb_Switch_fz[0] / rtb_Switch_fz[2];
          rtb_Divide_h[1] = rtb_Switch_fz[1] / rtb_Switch_fz[2];

          /* Sum: '<S90>/Sum of Elements' incorporates:
           *  Math: '<S90>/Math Function'
           *  SignalConversion: '<S90>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Saturation_bu = rtb_Divide_h[1] * rtb_Divide_h[1] + rtb_Divide_h[0]
            * rtb_Divide_h[0];

          /* Math: '<S90>/Math Function1' incorporates:
           *  Sum: '<S90>/Sum of Elements'
           *
           * About '<S90>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_bu < 0.0F) {
            rtb_Switch_b_idx_0 = -sqrtf(fabsf(rtb_Saturation_bu));
          } else {
            rtb_Switch_b_idx_0 = sqrtf(rtb_Saturation_bu);
          }

          /* End of Math: '<S90>/Math Function1' */

          /* Switch: '<S90>/Switch' incorporates:
           *  Constant: '<S90>/Constant'
           *  Product: '<S90>/Product'
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
          rtb_Divide_h[0] = FMS_DW.start_wp_DSTATE[0] - FMS_U.INS_Out.x_R;
          rtb_Divide_h[1] = FMS_DW.start_wp_DSTATE[1] - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Product: '<S92>/Divide' */
          rtb_Switch_b_idx_0 = rtb_Switch_a[0] / rtb_Switch_a[2];

          /* MATLAB Function: '<S77>/SearchL1RefWP' */
          rtb_Saturation_bu = rtb_Switch_b_idx_0 * rtb_Divide_h[0];
          rtb_Switch_b_idx_1 = rtb_Switch_b_idx_0;

          /* Product: '<S92>/Divide' */
          rtb_Switch_b_idx_0 = rtb_Switch_a[1] / rtb_Switch_a[2];

          /* MATLAB Function: '<S77>/SearchL1RefWP' incorporates:
           *  Constant: '<S75>/L1'
           *  Delay: '<S79>/start_wp'
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

          /* RelationalOperator: '<S80>/Compare' incorporates:
           *  Constant: '<S80>/Constant'
           *  MATLAB Function: '<S77>/SearchL1RefWP'
           */
          rtb_Compare_ay = (rtb_Saturation_bu > 0.0F);

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* MATLAB Function: '<S77>/OutRegionRefWP' incorporates:
           *  Delay: '<S79>/start_wp'
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
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

          /* Switch: '<S77>/Switch' incorporates:
           *  Delay: '<S79>/start_wp'
           *  MATLAB Function: '<S77>/OutRegionRefWP'
           */
          if (rtb_Compare_ay) {
            rtb_Saturation_bu = rtb_P_k[0];
          } else {
            rtb_Saturation_bu = rtb_Switch_b_idx_2 * rtb_Switch_b_idx_1 +
              FMS_DW.start_wp_DSTATE[0];
          }

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Sum: '<S78>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          rtb_Switch_b_idx_1 = rtb_Saturation_bu - FMS_U.INS_Out.x_R;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Math: '<S88>/Math Function' */
          rtb_Divide_h[0] = rtb_Switch_b_idx_1 * rtb_Switch_b_idx_1;
          rtb_P_k[0] = rtb_Switch_b_idx_1;

          /* Switch: '<S77>/Switch' incorporates:
           *  Delay: '<S79>/start_wp'
           *  MATLAB Function: '<S77>/OutRegionRefWP'
           *  Sum: '<S78>/Subtract'
           */
          if (rtb_Compare_ay) {
            rtb_Saturation_bu = rtb_P_k[1];
          } else {
            rtb_Saturation_bu = rtb_Switch_b_idx_2 * rtb_Switch_b_idx_0 +
              FMS_DW.start_wp_DSTATE[1];
          }

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Sum: '<S78>/Subtract' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  SignalConversion: '<S16>/Signal Copy1'
           */
          rtb_Switch_b_idx_1 = rtb_Saturation_bu - FMS_U.INS_Out.y_R;

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Math: '<S88>/Math Function' incorporates:
           *  Math: '<S86>/Square'
           */
          rtb_Saturation_bu = rtb_Switch_b_idx_1 * rtb_Switch_b_idx_1;

          /* Sum: '<S88>/Sum of Elements' incorporates:
           *  Math: '<S88>/Math Function'
           */
          rtb_Saturation_fu = rtb_Saturation_bu + rtb_Divide_h[0];

          /* Math: '<S88>/Math Function1' incorporates:
           *  Sum: '<S88>/Sum of Elements'
           *
           * About '<S88>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_fu < 0.0F) {
            rtb_Switch_b_idx_0 = -sqrtf(fabsf(rtb_Saturation_fu));
          } else {
            rtb_Switch_b_idx_0 = sqrtf(rtb_Saturation_fu);
          }

          /* End of Math: '<S88>/Math Function1' */

          /* Switch: '<S88>/Switch' incorporates:
           *  Constant: '<S88>/Constant'
           *  Product: '<S88>/Product'
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

          /* End of Switch: '<S88>/Switch' */

          /* Product: '<S88>/Divide' */
          rtb_Divide_h[0] = rtb_Switch_a[0] / rtb_Switch_a[2];
          rtb_Divide_h[1] = rtb_Switch_a[1] / rtb_Switch_a[2];

          /* Sum: '<S91>/Sum of Elements' incorporates:
           *  Math: '<S91>/Math Function'
           *  SignalConversion: '<S91>/TmpSignal ConversionAtMath FunctionInport1'
           */
          rtb_Saturation_fu = rtb_Divide_h[1] * rtb_Divide_h[1] + rtb_Divide_h[0]
            * rtb_Divide_h[0];

          /* Math: '<S91>/Math Function1' incorporates:
           *  Sum: '<S91>/Sum of Elements'
           *
           * About '<S91>/Math Function1':
           *  Operator: sqrt
           */
          if (rtb_Saturation_fu < 0.0F) {
            rtb_Switch_b_idx_0 = -sqrtf(fabsf(rtb_Saturation_fu));
          } else {
            rtb_Switch_b_idx_0 = sqrtf(rtb_Saturation_fu);
          }

          /* End of Math: '<S91>/Math Function1' */

          /* Switch: '<S91>/Switch' incorporates:
           *  Constant: '<S91>/Constant'
           *  Product: '<S91>/Product'
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

          /* End of Switch: '<S91>/Switch' */

          /* Product: '<S91>/Divide' */
          rtb_Divide_h[0] = rtb_Switch_a[0] / rtb_Switch_a[2];

          /* Product: '<S90>/Divide' */
          rtb_P_ia[0] = rtb_Switch_fz[0] / rtb_Switch_fz[2];
          rtb_P_k[0] *= rtb_P_k[0];

          /* Product: '<S91>/Divide' incorporates:
           *  Math: '<S86>/Square'
           */
          rtb_Divide_h[1] = rtb_Switch_a[1] / rtb_Switch_a[2];

          /* Product: '<S90>/Divide' */
          rtb_P_ia[1] = rtb_Switch_fz[1] / rtb_Switch_fz[2];

          /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
          /* Sqrt: '<S85>/Sqrt' incorporates:
           *  Inport: '<Root>/INS_Out'
           *  Math: '<S85>/Square'
           *  SignalConversion: '<S16>/Signal Copy1'
           *  Sum: '<S85>/Sum of Elements'
           */
          rtb_Switch_b_idx_0 = sqrtf(FMS_U.INS_Out.vn * FMS_U.INS_Out.vn +
            FMS_U.INS_Out.ve * FMS_U.INS_Out.ve);

          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Gain: '<S83>/Gain' incorporates:
           *  Math: '<S83>/Square'
           */
          rtb_Switch_b_idx_1 = rtb_Switch_b_idx_0 * rtb_Switch_b_idx_0 * 2.0F;

          /* Sum: '<S89>/Subtract' incorporates:
           *  Product: '<S89>/Multiply'
           *  Product: '<S89>/Multiply1'
           */
          rtb_Switch_b_idx_0 = rtb_Divide_h[0] * rtb_P_ia[1] - rtb_Divide_h[1] *
            rtb_P_ia[0];

          /* Signum: '<S84>/Sign1' */
          if (rtb_Switch_b_idx_0 < 0.0F) {
            rtb_Switch_b_idx_0 = -1.0F;
          } else {
            if (rtb_Switch_b_idx_0 > 0.0F) {
              rtb_Switch_b_idx_0 = 1.0F;
            }
          }

          /* End of Signum: '<S84>/Sign1' */

          /* Switch: '<S84>/Switch2' incorporates:
           *  Constant: '<S84>/Constant4'
           */
          if (rtb_Switch_b_idx_0 == 0.0F) {
            rtb_Switch_b_idx_0 = 1.0F;
          }

          /* End of Switch: '<S84>/Switch2' */

          /* DotProduct: '<S84>/Dot Product' */
          rtb_Switch_b_idx_2 = rtb_P_ia[0] * rtb_Divide_h[0] + rtb_P_ia[1] *
            rtb_Divide_h[1];

          /* Trigonometry: '<S84>/Acos' incorporates:
           *  DotProduct: '<S84>/Dot Product'
           */
          if (rtb_Switch_b_idx_2 > 1.0F) {
            rtb_Switch_b_idx_2 = 1.0F;
          } else {
            if (rtb_Switch_b_idx_2 < -1.0F) {
              rtb_Switch_b_idx_2 = -1.0F;
            }
          }

          /* Product: '<S84>/Multiply' incorporates:
           *  Trigonometry: '<S84>/Acos'
           */
          rtb_Switch_b_idx_0 *= acosf(rtb_Switch_b_idx_2);

          /* Saturate: '<S83>/Saturation' */
          if (rtb_Switch_b_idx_0 > 1.57079637F) {
            rtb_Switch_b_idx_0 = 1.57079637F;
          } else {
            if (rtb_Switch_b_idx_0 < -1.57079637F) {
              rtb_Switch_b_idx_0 = -1.57079637F;
            }
          }

          /* End of Saturate: '<S83>/Saturation' */

          /* Product: '<S83>/Divide' incorporates:
           *  Constant: '<S75>/L1'
           *  Constant: '<S83>/Constant'
           *  MinMax: '<S83>/Max'
           *  MinMax: '<S83>/Min'
           *  Product: '<S83>/Multiply1'
           *  Sqrt: '<S86>/Sqrt'
           *  Sum: '<S86>/Sum of Elements'
           *  Trigonometry: '<S83>/Sin'
           */
          FMS_B.Merge_p = arm_sin_f32(rtb_Switch_b_idx_0) * rtb_Switch_b_idx_1 /
            fminf(FMS_PARAM.L1, fmaxf(sqrtf(rtb_Saturation_bu + rtb_P_k[0]),
                   0.5F));

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
            rtb_Saturation_bu = FMS_U.Pilot_Cmd.stick_roll - FMS_PARAM.ROLL_DZ;
          } else if (FMS_U.Pilot_Cmd.stick_roll >= -FMS_PARAM.ROLL_DZ) {
            rtb_Saturation_bu = 0.0F;
          } else {
            rtb_Saturation_bu = FMS_U.Pilot_Cmd.stick_roll - (-FMS_PARAM.ROLL_DZ);
          }

          /* End of DeadZone: '<S93>/Dead Zone' */
          /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

          /* Gain: '<S76>/Gain6' incorporates:
           *  Gain: '<S93>/Gain'
           */
          FMS_B.Merge_p = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * rtb_Saturation_bu *
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
          rtb_Saturation_bu = FMS_U.Pilot_Cmd.stick_yaw - FMS_PARAM.YAW_DZ;
        } else if (FMS_U.Pilot_Cmd.stick_yaw >= -FMS_PARAM.YAW_DZ) {
          rtb_Saturation_bu = 0.0F;
        } else {
          rtb_Saturation_bu = FMS_U.Pilot_Cmd.stick_yaw - (-FMS_PARAM.YAW_DZ);
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
          rtb_Saturation_bu * FMS_PARAM.YAW_RATE_LIM;

        /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
        /* Gain: '<S54>/Gain1' incorporates:
         *  Bias: '<S54>/Bias'
         *  Inport: '<Root>/Pilot_Cmd'
         *  SignalConversion: '<S16>/Signal Copy2'
         */
        rtb_Saturation_bu = (FMS_U.Pilot_Cmd.stick_throttle + 1.0F) * 0.5F;

        /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

        /* Saturate: '<S54>/Saturation' incorporates:
         *  Gain: '<S54>/Gain1'
         */
        if (rtb_Saturation_bu > 1.0F) {
          rtb_Saturation_bu = 1.0F;
        } else {
          if (rtb_Saturation_bu < 0.0F) {
            rtb_Saturation_bu = 0.0F;
          }
        }

        /* End of Saturate: '<S54>/Saturation' */

        /* BusAssignment: '<S28>/Bus Assignment' incorporates:
         *  BusAssignment: '<S18>/Bus Assignment'
         *  Gain: '<S54>/Gain'
         *  Outport: '<Root>/FMS_Out'
         */
        FMS_Y.FMS_Out.u_cmd = FMS_PARAM.FW_AIRSPD_MAX * rtb_Saturation_bu;

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
        rtb_Saturation_bu = 2.0F;
      } else if (FMS_U.Pilot_Cmd.stick_throttle + 1.0F < 0.0F) {
        rtb_Saturation_bu = 0.0F;
      } else {
        rtb_Saturation_bu = FMS_U.Pilot_Cmd.stick_throttle + 1.0F;
      }

      /* End of Saturate: '<S140>/Saturation' */
      /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

      /* DataTypeConversion: '<S139>/Data Type Conversion' incorporates:
       *  Constant: '<S140>/Constant5'
       *  Gain: '<S140>/Gain4'
       *  Sum: '<S140>/Add'
       */
      rtb_DataTypeConversion = (uint16_T)fmodf(floorf(500.0F * rtb_Saturation_bu
        + 1000.0F), 65536.0F);

      /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
      /* DataTypeConversion: '<S139>/Data Type Conversion1' incorporates:
       *  Bias: '<S139>/Bias1'
       *  Gain: '<S139>/Gain1'
       *  Inport: '<Root>/Pilot_Cmd'
       *  SignalConversion: '<S16>/Signal Copy2'
       */
      rtb_Saturation_bu = fmodf(floorf(-500.0F * FMS_U.Pilot_Cmd.stick_roll +
        1500.0F), 65536.0F);

      /* End of Outputs for SubSystem: '<S2>/FMS_Input' */
      rtb_DataTypeConversion1_l = (uint16_T)(rtb_Saturation_bu < 0.0F ? (int32_T)
        (uint16_T)-(int16_T)(uint16_T)-rtb_Saturation_bu : (int32_T)(uint16_T)
        rtb_Saturation_bu);

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
      rtb_Saturation_bu = fmodf(floorf(500.0F * FMS_U.Pilot_Cmd.stick_pitch +
        1500.0F), 65536.0F);

      /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

      /* BusAssignment: '<S23>/Bus Assignment' incorporates:
       *  BusAssignment: '<S18>/Bus Assignment'
       *  DataTypeConversion: '<S139>/Data Type Conversion2'
       *  Outport: '<Root>/FMS_Out'
       */
      FMS_Y.FMS_Out.actuator_cmd[4] = (uint16_T)(rtb_Saturation_bu < 0.0F ?
        (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_Saturation_bu : (int32_T)
        (uint16_T)rtb_Saturation_bu);

      /* Outputs for Atomic SubSystem: '<S2>/FMS_Input' */
      /* DataTypeConversion: '<S139>/Data Type Conversion3' incorporates:
       *  Bias: '<S139>/Bias3'
       *  Gain: '<S139>/Gain3'
       *  Inport: '<Root>/Pilot_Cmd'
       *  SignalConversion: '<S16>/Signal Copy2'
       */
      rtb_Saturation_bu = fmodf(floorf(500.0F * FMS_U.Pilot_Cmd.stick_yaw +
        1500.0F), 65536.0F);

      /* End of Outputs for SubSystem: '<S2>/FMS_Input' */

      /* BusAssignment: '<S23>/Bus Assignment' incorporates:
       *  BusAssignment: '<S18>/Bus Assignment'
       *  DataTypeConversion: '<S139>/Data Type Conversion3'
       *  Outport: '<Root>/FMS_Out'
       */
      FMS_Y.FMS_Out.actuator_cmd[5] = (uint16_T)(rtb_Saturation_bu < 0.0F ?
        (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_Saturation_bu : (int32_T)
        (uint16_T)rtb_Saturation_bu);
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
   *  DiscreteIntegrator: '<S208>/Discrete-Time Integrator'
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

  /* Update for DiscreteIntegrator: '<S208>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S208>/Constant'
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
  /* SystemInitialize for IfAction SubSystem: '<S15>/Arm' */
  /* SystemInitialize for IfAction SubSystem: '<S17>/SubMode' */
  /* SystemInitialize for IfAction SubSystem: '<S24>/Hold' */
  /* InitializeConditions for Delay: '<S151>/start_vel' */
  FMS_DW.icLoad_n = 1U;

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
  FMS_MotionStatus_Init(&FMS_DW.sf_MotionStatus);

  /* SystemInitialize for IfAction SubSystem: '<S37>/Hold Control' */
  FMS_HoldControl_Init(&FMS_DW.HoldControl);

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
  FMS_DW.is_c16_FMS = FMS_IN_NO_ACTIVE_CHILD_p;

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
