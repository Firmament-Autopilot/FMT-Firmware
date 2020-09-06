/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.669
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sun Sep  6 09:55:56 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S65>/Motion_State' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<S81>/Z_Motion_State' */
#define FMS_IN_Brake_h                 ((uint8_T)1U)
#define FMS_IN_Hold_p                  ((uint8_T)2U)
#define FMS_IN_Move_k                  ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD_e       ((uint8_T)0U)

/* Named constants for Chart: '<S1>/Mode_Logic' */
#define FMS_IN_Acro                    ((uint8_T)1U)
#define FMS_IN_Altitude_Hold           ((uint8_T)2U)
#define FMS_IN_Manual                  ((uint8_T)3U)
#define FMS_IN_Mission                 ((uint8_T)4U)
#define FMS_IN_NO_ACTIVE_CHILD_h       ((uint8_T)0U)
#define FMS_IN_Position                ((uint8_T)5U)
#define FMS_IN_Unknow                  ((uint8_T)6U)

/* Named constants for Chart: '<S81>/XY_Motion_State' */
#define FMS_IN_Brake_hi                ((uint8_T)1U)
#define FMS_IN_Hold_n                  ((uint8_T)2U)
#define FMS_IN_Move_j                  ((uint8_T)3U)

/* Named constants for Chart: '<S112>/Arm_Event' */
#define FMS_IN_Idle                    ((uint8_T)1U)
#define FMS_IN_arm_event               ((uint8_T)2U)
#define FMS_IN_ready                   ((uint8_T)3U)

/* Named constants for Chart: '<S112>/Disarm_Event' */
#define FMS_IN_Disarm                  ((uint8_T)1U)
#define FMS_IN_Idle_o                  ((uint8_T)2U)
#define FMS_IN_On_Ground               ((uint8_T)3U)

/* Named constants for Chart: '<S3>/State_Logic' */
#define FMS_IN_Arm                     ((uint8_T)1U)
#define FMS_IN_Disarm_a                ((uint8_T)2U)
#define FMS_IN_Motor_Test              ((uint8_T)3U)
#define FMS_IN_Standby                 ((uint8_T)4U)

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
  0U,                                  /* throttle_cmd */

  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
  ,                                    /* actuator_cmd */
  0U,                                  /* state */
  0U,                                  /* mode */
  0U,                                  /* reset */
  0U                                   /* reserved */
} ;                                    /* FMS_Out_Bus ground */

/* Exported block parameters */
struct_QTHD3FieMDlB4oEKy11VyG FMS_PARAM = {
  0.1F,
  0.95F,
  1.2F,
  5.0F,
  2.5F,
  1.0F,
  1.04719758F,
  0.52359879F
} ;                                    /* Variable: FMS_PARAM
                                        * Referenced by:
                                        *   '<S103>/Constant'
                                        *   '<S103>/Dead Zone'
                                        *   '<S104>/Constant'
                                        *   '<S104>/Dead Zone'
                                        *   '<S105>/Constant'
                                        *   '<S105>/Dead Zone'
                                        *   '<S106>/Constant'
                                        *   '<S106>/Dead Zone'
                                        *   '<S14>/Gain'
                                        *   '<S14>/Gain1'
                                        *   '<S15>/Saturation1'
                                        *   '<S16>/Saturation'
                                        *   '<S47>/Gain1'
                                        *   '<S47>/Gain2'
                                        *   '<S48>/Saturation1'
                                        *   '<S65>/Saturation1'
                                        *   '<S21>/Gain2'
                                        *   '<S22>/Gain1'
                                        *   '<S54>/Gain2'
                                        *   '<S55>/Gain1'
                                        *   '<S71>/Gain2'
                                        *   '<S72>/Gain1'
                                        *   '<S82>/Saturation'
                                        *   '<S82>/Saturation1'
                                        *   '<S37>/Gain4'
                                        *   '<S38>/Gain6'
                                        *   '<S89>/Gain2'
                                        *   '<S89>/Gain4'
                                        *   '<S90>/Gain1'
                                        *   '<S90>/Gain5'
                                        *   '<S90>/Gain6'
                                        */

struct_4XfCoaAMTej5uH3d8u88xB FMS_EXPORT = {
  8U
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by: '<S117>/Constant'
                                        */

/* Block signals (default storage) */
B_FMS_T FMS_B;

/* Block states (default storage) */
DW_FMS_T FMS_DW;

/* External inputs (root inport signals with default storage) */
ExtU_FMS_T FMS_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_FMS_T FMS_Y;

/* Real-time model */
RT_MODEL_FMS_T FMS_M_;
RT_MODEL_FMS_T *const FMS_M = &FMS_M_;

/* Forward declaration for local functions */
static void FMS_Unknow(void);

/*
 * System initialize for atomic system:
 *    '<S65>/Motion_State'
 *    '<S15>/Motion_State'
 *    '<S48>/Motion_State'
 */
void FMS_Motion_State_Init(DW_Motion_State_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c5_FMS = 0U;
  localDW->is_c5_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * System reset for atomic system:
 *    '<S65>/Motion_State'
 *    '<S15>/Motion_State'
 *    '<S48>/Motion_State'
 */
void FMS_Motion_State_Reset(DW_Motion_State_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c5_FMS = 0U;
  localDW->is_c5_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * Output and update for atomic system:
 *    '<S65>/Motion_State'
 *    '<S15>/Motion_State'
 *    '<S48>/Motion_State'
 */
void FMS_Motion_State(boolean_T rtu_move_cmd, real32_T rtu_heading_rate, real_T *
                      rty_state, DW_Motion_State_FMS_T *localDW)
{
  /* Chart: '<S65>/Motion_State' */
  if (localDW->temporalCounter_i1 < 127U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->is_active_c5_FMS == 0U) {
    localDW->is_active_c5_FMS = 1U;
    localDW->is_c5_FMS = FMS_IN_Move;
    *rty_state = 0.0;
  } else {
    switch (localDW->is_c5_FMS) {
     case FMS_IN_Brake:
      *rty_state = 1.0;
      if ((rtu_heading_rate <= 0.1) || (localDW->temporalCounter_i1 >= 125U)) {
        localDW->is_c5_FMS = FMS_IN_Hold;
        *rty_state = 2.0;
      } else {
        if (rtu_move_cmd) {
          localDW->is_c5_FMS = FMS_IN_Move;
          *rty_state = 0.0;
        }
      }
      break;

     case FMS_IN_Hold:
      *rty_state = 2.0;
      if (rtu_move_cmd) {
        localDW->is_c5_FMS = FMS_IN_Move;
        *rty_state = 0.0;
      }
      break;

     default:
      *rty_state = 0.0;
      if (!rtu_move_cmd) {
        localDW->is_c5_FMS = FMS_IN_Brake;
        localDW->temporalCounter_i1 = 0U;
        *rty_state = 1.0;
      }
      break;
    }
  }

  /* End of Chart: '<S65>/Motion_State' */
}

/*
 * System initialize for atomic system:
 *    '<S81>/Z_Motion_State'
 *    '<S31>/Z_Motion_State'
 */
void FMS_Z_Motion_State_Init(DW_Z_Motion_State_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c8_FMS = 0U;
  localDW->is_c8_FMS = FMS_IN_NO_ACTIVE_CHILD_e;
}

/*
 * System reset for atomic system:
 *    '<S81>/Z_Motion_State'
 *    '<S31>/Z_Motion_State'
 */
void FMS_Z_Motion_State_Reset(DW_Z_Motion_State_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c8_FMS = 0U;
  localDW->is_c8_FMS = FMS_IN_NO_ACTIVE_CHILD_e;
}

/*
 * Output and update for atomic system:
 *    '<S81>/Z_Motion_State'
 *    '<S31>/Z_Motion_State'
 */
void FMS_Z_Motion_State(boolean_T rtu_move_cmd, real32_T rtu_speed, real_T
  *rty_state, DW_Z_Motion_State_FMS_T *localDW)
{
  /* Chart: '<S81>/Z_Motion_State' */
  if (localDW->temporalCounter_i1 < 255U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->is_active_c8_FMS == 0U) {
    localDW->is_active_c8_FMS = 1U;
    localDW->is_c8_FMS = FMS_IN_Move_k;
    *rty_state = 0.0;
  } else {
    switch (localDW->is_c8_FMS) {
     case FMS_IN_Brake_h:
      *rty_state = 1.0;
      if ((fabsf(rtu_speed) <= 0.2) || (localDW->temporalCounter_i1 >= 188U)) {
        localDW->is_c8_FMS = FMS_IN_Hold_p;
        *rty_state = 2.0;
      } else {
        if (rtu_move_cmd) {
          localDW->is_c8_FMS = FMS_IN_Move_k;
          *rty_state = 0.0;
        }
      }
      break;

     case FMS_IN_Hold_p:
      *rty_state = 2.0;
      if (rtu_move_cmd) {
        localDW->is_c8_FMS = FMS_IN_Move_k;
        *rty_state = 0.0;
      }
      break;

     default:
      *rty_state = 0.0;
      if (!rtu_move_cmd) {
        localDW->is_c8_FMS = FMS_IN_Brake_h;
        localDW->temporalCounter_i1 = 0U;
        *rty_state = 1.0;
      }
      break;
    }
  }

  /* End of Chart: '<S81>/Z_Motion_State' */
}

/* Function for Chart: '<S1>/Mode_Logic' */
static void FMS_Unknow(void)
{
  FMS_B.control_mode = FMS_DW.local_mode;

  /* Inport: '<Root>/Pilot_Cmd' */
  switch (FMS_U.Pilot_Cmd.mode) {
   case 5U:
    FMS_DW.is_c1_FMS = FMS_IN_Acro;
    FMS_DW.local_mode = 5U;
    break;

   case 4U:
    FMS_DW.is_c1_FMS = FMS_IN_Manual;
    FMS_DW.local_mode = 4U;
    break;

   case 3U:
    FMS_DW.is_c1_FMS = FMS_IN_Altitude_Hold;
    FMS_DW.local_mode = 3U;
    break;

   case 2U:
    FMS_DW.is_c1_FMS = FMS_IN_Position;
    FMS_DW.local_mode = 2U;
    break;

   case 1U:
    FMS_DW.is_c1_FMS = FMS_IN_Mission;
    FMS_DW.local_mode = 1U;
    break;

   default:
    FMS_DW.is_c1_FMS = FMS_IN_Unknow;
    FMS_DW.local_mode = 0U;
    break;
  }

  /* End of Inport: '<Root>/Pilot_Cmd' */
}

/* Model step function */
void FMS_step(void)
{
  real32_T rtb_stick_throttle_raw;
  real32_T rtb_stick_roll_raw;
  real32_T rtb_TrigoFcn;
  real32_T rtb_stick_pitch_raw;
  boolean_T rtb_LogicalOperator1;
  boolean_T rtb_FixPtRelationalOperator;
  boolean_T rtb_Compare_nq;
  uint16_T rtb_Multiply_ox[16];
  real32_T rtb_MatrixConcatenate3[9];
  uint8_T rtb_Compare;
  real32_T rtb_stick_yaw_raw;
  real32_T rtb_M_z[9];
  int8_T rtPrevAction;
  real_T rtb_state_a;
  boolean_T rtb_Compare_je;
  boolean_T rtb_Compare_ff;
  real32_T rtb_Multiply_a[3];
  real32_T rtb_Add_d;
  real32_T rtb_Add_m;
  int32_T i;
  int32_T i_0;
  real32_T rtb_Product_idx_0;
  real32_T rtb_Product_idx_1;
  real32_T rtb_Product_idx_2;
  uint32_T tmp;
  uint16_T tmp_0;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;

  /* Saturate: '<S2>/Saturation1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   */
  if (FMS_U.Pilot_Cmd.ls_ud > 1.0F) {
    rtb_stick_throttle_raw = 1.0F;
  } else if (FMS_U.Pilot_Cmd.ls_ud < -1.0F) {
    rtb_stick_throttle_raw = -1.0F;
  } else {
    rtb_stick_throttle_raw = FMS_U.Pilot_Cmd.ls_ud;
  }

  /* End of Saturate: '<S2>/Saturation1' */

  /* Chart: '<S1>/Mode_Logic' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   */
  if (FMS_DW.is_active_c1_FMS == 0U) {
    FMS_DW.is_active_c1_FMS = 1U;
    switch (FMS_U.Pilot_Cmd.mode) {
     case 5U:
      FMS_DW.is_c1_FMS = FMS_IN_Acro;
      FMS_DW.local_mode = 5U;
      break;

     case 4U:
      FMS_DW.is_c1_FMS = FMS_IN_Manual;
      FMS_DW.local_mode = 4U;
      break;

     case 3U:
      FMS_DW.is_c1_FMS = FMS_IN_Altitude_Hold;
      FMS_DW.local_mode = 3U;
      break;

     case 2U:
      FMS_DW.is_c1_FMS = FMS_IN_Position;
      FMS_DW.local_mode = 2U;
      break;

     case 1U:
      FMS_DW.is_c1_FMS = FMS_IN_Mission;
      FMS_DW.local_mode = 1U;
      break;

     default:
      FMS_DW.is_c1_FMS = FMS_IN_Unknow;
      FMS_DW.local_mode = 0U;
      break;
    }
  } else {
    guard1 = false;
    guard2 = false;
    guard3 = false;
    guard4 = false;
    switch (FMS_DW.is_c1_FMS) {
     case FMS_IN_Acro:
      FMS_B.control_mode = FMS_DW.local_mode;
      switch (FMS_U.Pilot_Cmd.mode) {
       case 5U:
        FMS_DW.is_c1_FMS = FMS_IN_Acro;
        FMS_DW.local_mode = 5U;
        break;

       case 4U:
        FMS_DW.is_c1_FMS = FMS_IN_Manual;
        FMS_DW.local_mode = 4U;
        break;

       case 3U:
        FMS_DW.is_c1_FMS = FMS_IN_Altitude_Hold;
        FMS_DW.local_mode = 3U;
        break;

       case 2U:
        FMS_DW.is_c1_FMS = FMS_IN_Position;
        FMS_DW.local_mode = 2U;
        break;

       case 1U:
        FMS_DW.is_c1_FMS = FMS_IN_Mission;
        FMS_DW.local_mode = 1U;
        break;

       default:
        FMS_DW.is_c1_FMS = FMS_IN_Unknow;
        FMS_DW.local_mode = 0U;
        break;
      }
      break;

     case FMS_IN_Altitude_Hold:
      if ((FMS_U.INS_Output.flag & 128U) != 0U) {
        FMS_B.control_mode = FMS_DW.local_mode;
        if (FMS_U.Pilot_Cmd.mode == 5U) {
          FMS_DW.is_c1_FMS = FMS_IN_Acro;
          FMS_DW.local_mode = 5U;
        } else if (FMS_U.Pilot_Cmd.mode == 4U) {
          guard1 = true;
        } else {
          switch (FMS_U.Pilot_Cmd.mode) {
           case 3U:
            FMS_DW.is_c1_FMS = FMS_IN_Altitude_Hold;
            FMS_DW.local_mode = 3U;
            break;

           case 2U:
            FMS_DW.is_c1_FMS = FMS_IN_Position;
            FMS_DW.local_mode = 2U;
            break;

           case 1U:
            FMS_DW.is_c1_FMS = FMS_IN_Mission;
            FMS_DW.local_mode = 1U;
            break;

           default:
            FMS_DW.is_c1_FMS = FMS_IN_Unknow;
            FMS_DW.local_mode = 0U;
            break;
          }
        }
      } else {
        guard1 = true;
      }
      break;

     case FMS_IN_Manual:
      if ((FMS_U.INS_Output.flag & 4U) != 0U) {
        FMS_B.control_mode = FMS_DW.local_mode;
        if (FMS_U.Pilot_Cmd.mode == 5U) {
          guard2 = true;
        } else {
          switch (FMS_U.Pilot_Cmd.mode) {
           case 4U:
            FMS_DW.is_c1_FMS = FMS_IN_Manual;
            FMS_DW.local_mode = 4U;
            break;

           case 3U:
            FMS_DW.is_c1_FMS = FMS_IN_Altitude_Hold;
            FMS_DW.local_mode = 3U;
            break;

           case 2U:
            FMS_DW.is_c1_FMS = FMS_IN_Position;
            FMS_DW.local_mode = 2U;
            break;

           case 1U:
            FMS_DW.is_c1_FMS = FMS_IN_Mission;
            FMS_DW.local_mode = 1U;
            break;

           default:
            FMS_DW.is_c1_FMS = FMS_IN_Unknow;
            FMS_DW.local_mode = 0U;
            break;
          }
        }
      } else {
        guard2 = true;
      }
      break;

     case FMS_IN_Mission:
      if (((FMS_U.INS_Output.flag & 8U) != 0U) && ((FMS_U.INS_Output.flag & 32U)
           != 0U)) {
        FMS_B.control_mode = FMS_DW.local_mode;
        if (FMS_U.Pilot_Cmd.mode == 5U) {
          FMS_DW.is_c1_FMS = FMS_IN_Acro;
          FMS_DW.local_mode = 5U;
        } else if (FMS_U.Pilot_Cmd.mode == 4U) {
          FMS_DW.is_c1_FMS = FMS_IN_Manual;
          FMS_DW.local_mode = 4U;
        } else if (FMS_U.Pilot_Cmd.mode == 3U) {
          FMS_DW.is_c1_FMS = FMS_IN_Altitude_Hold;
          FMS_DW.local_mode = 3U;
        } else if (FMS_U.Pilot_Cmd.mode == 2U) {
          guard3 = true;
        } else if (FMS_U.Pilot_Cmd.mode == 1U) {
          FMS_DW.is_c1_FMS = FMS_IN_Mission;
          FMS_DW.local_mode = 1U;
        } else {
          FMS_DW.is_c1_FMS = FMS_IN_Unknow;
          FMS_DW.local_mode = 0U;
        }
      } else {
        guard3 = true;
      }
      break;

     case FMS_IN_Position:
      if (((FMS_U.INS_Output.flag & 8U) != 0U) && ((FMS_U.INS_Output.flag & 64U)
           != 0U) && ((FMS_U.INS_Output.flag & 128U) != 0U)) {
        FMS_B.control_mode = FMS_DW.local_mode;
        if (FMS_U.Pilot_Cmd.mode == 5U) {
          FMS_DW.is_c1_FMS = FMS_IN_Acro;
          FMS_DW.local_mode = 5U;
        } else if (FMS_U.Pilot_Cmd.mode == 4U) {
          FMS_DW.is_c1_FMS = FMS_IN_Manual;
          FMS_DW.local_mode = 4U;
        } else if (FMS_U.Pilot_Cmd.mode == 3U) {
          guard4 = true;
        } else {
          switch (FMS_U.Pilot_Cmd.mode) {
           case 2U:
            FMS_DW.is_c1_FMS = FMS_IN_Position;
            FMS_DW.local_mode = 2U;
            break;

           case 1U:
            FMS_DW.is_c1_FMS = FMS_IN_Mission;
            FMS_DW.local_mode = 1U;
            break;

           default:
            FMS_DW.is_c1_FMS = FMS_IN_Unknow;
            FMS_DW.local_mode = 0U;
            break;
          }
        }
      } else {
        guard4 = true;
      }
      break;

     default:
      FMS_Unknow();
      break;
    }

    if (guard4) {
      FMS_DW.is_c1_FMS = FMS_IN_Altitude_Hold;
      FMS_DW.local_mode = 3U;
    }

    if (guard3) {
      FMS_DW.is_c1_FMS = FMS_IN_Position;
      FMS_DW.local_mode = 2U;
    }

    if (guard2) {
      FMS_DW.is_c1_FMS = FMS_IN_Acro;
      FMS_DW.local_mode = 5U;
    }

    if (guard1) {
      FMS_DW.is_c1_FMS = FMS_IN_Manual;
      FMS_DW.local_mode = 4U;
    }
  }

  /* End of Chart: '<S1>/Mode_Logic' */

  /* Saturate: '<S2>/Saturation2' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   */
  if (FMS_U.Pilot_Cmd.rs_lr > 1.0F) {
    rtb_stick_roll_raw = 1.0F;
  } else if (FMS_U.Pilot_Cmd.rs_lr < -1.0F) {
    rtb_stick_roll_raw = -1.0F;
  } else {
    rtb_stick_roll_raw = FMS_U.Pilot_Cmd.rs_lr;
  }

  /* End of Saturate: '<S2>/Saturation2' */

  /* DeadZone: '<S105>/Dead Zone' */
  if (rtb_stick_roll_raw > FMS_PARAM.StickDeadZone) {
    rtb_TrigoFcn = rtb_stick_roll_raw - FMS_PARAM.StickDeadZone;
  } else if (rtb_stick_roll_raw >= -FMS_PARAM.StickDeadZone) {
    rtb_TrigoFcn = 0.0F;
  } else {
    rtb_TrigoFcn = rtb_stick_roll_raw - (-FMS_PARAM.StickDeadZone);
  }

  /* End of DeadZone: '<S105>/Dead Zone' */

  /* Signum: '<S105>/Sign' */
  if (rtb_TrigoFcn < 0.0F) {
    rtb_Add_d = -1.0F;
  } else if (rtb_TrigoFcn > 0.0F) {
    rtb_Add_d = 1.0F;
  } else {
    rtb_Add_d = rtb_TrigoFcn;
  }

  /* End of Signum: '<S105>/Sign' */

  /* Sum: '<S105>/Add' incorporates:
   *  Constant: '<S105>/Constant'
   *  Product: '<S105>/Multiply'
   */
  rtb_Add_m = rtb_Add_d * FMS_PARAM.StickDeadZone + rtb_TrigoFcn;

  /* Saturate: '<S2>/Saturation3' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   */
  if (FMS_U.Pilot_Cmd.rs_ud > 1.0F) {
    rtb_stick_pitch_raw = 1.0F;
  } else if (FMS_U.Pilot_Cmd.rs_ud < -1.0F) {
    rtb_stick_pitch_raw = -1.0F;
  } else {
    rtb_stick_pitch_raw = FMS_U.Pilot_Cmd.rs_ud;
  }

  /* End of Saturate: '<S2>/Saturation3' */

  /* DeadZone: '<S106>/Dead Zone' */
  if (rtb_stick_pitch_raw > FMS_PARAM.StickDeadZone) {
    rtb_TrigoFcn = rtb_stick_pitch_raw - FMS_PARAM.StickDeadZone;
  } else if (rtb_stick_pitch_raw >= -FMS_PARAM.StickDeadZone) {
    rtb_TrigoFcn = 0.0F;
  } else {
    rtb_TrigoFcn = rtb_stick_pitch_raw - (-FMS_PARAM.StickDeadZone);
  }

  /* End of DeadZone: '<S106>/Dead Zone' */

  /* Signum: '<S106>/Sign' */
  if (rtb_TrigoFcn < 0.0F) {
    rtb_Add_d = -1.0F;
  } else if (rtb_TrigoFcn > 0.0F) {
    rtb_Add_d = 1.0F;
  } else {
    rtb_Add_d = rtb_TrigoFcn;
  }

  /* End of Signum: '<S106>/Sign' */

  /* Sum: '<S106>/Add' incorporates:
   *  Constant: '<S106>/Constant'
   *  Product: '<S106>/Multiply'
   */
  rtb_Add_d = rtb_Add_d * FMS_PARAM.StickDeadZone + rtb_TrigoFcn;

  /* Chart: '<S112>/Arm_Event' */
  if (FMS_DW.is_active_c3_FMS == 0U) {
    FMS_DW.is_active_c3_FMS = 1U;
    FMS_DW.is_c3_FMS = FMS_IN_Idle;
    FMS_B.arm_event = 0.0;
  } else {
    switch (FMS_DW.is_c3_FMS) {
     case FMS_IN_Idle:
      FMS_B.arm_event = 0.0;
      if ((rtb_stick_throttle_raw < -0.8) && (rtb_Add_m < -0.8) && (rtb_Add_d <
           -0.8)) {
        FMS_DW.is_c3_FMS = FMS_IN_ready;
      }
      break;

     case FMS_IN_arm_event:
      FMS_DW.is_c3_FMS = FMS_IN_Idle;
      FMS_B.arm_event = 0.0;
      break;

     default:
      if ((fabsf(rtb_Add_m) < 0.15) && (fabsf(rtb_Add_d) < 0.15)) {
        FMS_DW.is_c3_FMS = FMS_IN_arm_event;
        FMS_B.arm_event = 1.0;
      }
      break;
    }
  }

  /* End of Chart: '<S112>/Arm_Event' */

  /* Logic: '<S120>/Logical Operator1' incorporates:
   *  Constant: '<S121>/Constant'
   *  Constant: '<S122>/Lower Limit'
   *  Constant: '<S122>/Upper Limit'
   *  DiscreteIntegrator: '<S123>/Discrete-Time Integrator5'
   *  Inport: '<Root>/Control_Out'
   *  Logic: '<S122>/AND'
   *  Product: '<S120>/Divide'
   *  RelationalOperator: '<S121>/Compare'
   *  RelationalOperator: '<S122>/Lower Test'
   *  RelationalOperator: '<S122>/Upper Test'
   *  Sum: '<S120>/Sum of Elements'
   */
  rtb_LogicalOperator1 = ((-10.806F <= FMS_DW.DiscreteTimeIntegrator5_DSTATE) &&
    (FMS_DW.DiscreteTimeIntegrator5_DSTATE <= -8.806F) && ((int32_T)((uint32_T)
    (uint16_T)((((uint32_T)FMS_U.Control_Out.actuator_cmd[0] +
                 FMS_U.Control_Out.actuator_cmd[1]) +
                FMS_U.Control_Out.actuator_cmd[2]) +
               FMS_U.Control_Out.actuator_cmd[3]) >> 2) < 1200));

  /* Chart: '<S112>/Disarm_Event' incorporates:
   *  Delay: '<S3>/Delay'
   */
  if (FMS_DW.temporalCounter_i1_a < 255U) {
    FMS_DW.temporalCounter_i1_a++;
  }

  if (FMS_DW.is_active_c10_FMS == 0U) {
    FMS_DW.is_active_c10_FMS = 1U;
    FMS_DW.is_c10_FMS = FMS_IN_Idle_o;
    FMS_B.disarm_event = 0.0;
  } else {
    switch (FMS_DW.is_c10_FMS) {
     case FMS_IN_Disarm:
      FMS_DW.is_c10_FMS = FMS_IN_Idle_o;
      FMS_B.disarm_event = 0.0;
      break;

     case FMS_IN_Idle_o:
      FMS_B.disarm_event = 0.0;
      if (rtb_LogicalOperator1 && (FMS_DW.Delay_DSTATE_pi == 2)) {
        FMS_DW.is_c10_FMS = FMS_IN_On_Ground;
        FMS_DW.temporalCounter_i1_a = 0U;
      }
      break;

     default:
      if (!rtb_LogicalOperator1) {
        FMS_DW.is_c10_FMS = FMS_IN_Idle_o;
        FMS_B.disarm_event = 0.0;
      } else {
        if (FMS_DW.temporalCounter_i1_a >= 188U) {
          FMS_DW.is_c10_FMS = FMS_IN_Disarm;
          FMS_B.disarm_event = 1.0;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S112>/Disarm_Event' */

  /* RelationalOperator: '<S109>/Compare' incorporates:
   *  Constant: '<S109>/Constant'
   *  Inport: '<Root>/Pilot_Cmd'
   */
  rtb_LogicalOperator1 = (FMS_U.Pilot_Cmd.cmd_1 == 1000U);

  /* RelationalOperator: '<S111>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S111>/Delay Input1'
   *
   * Block description for '<S111>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_FixPtRelationalOperator = ((int32_T)rtb_LogicalOperator1 > (int32_T)
    FMS_DW.DelayInput1_DSTATE);

  /* RelationalOperator: '<S110>/Compare' incorporates:
   *  Constant: '<S110>/Constant'
   *  Inport: '<Root>/Pilot_Cmd'
   */
  rtb_Compare_nq = (FMS_U.Pilot_Cmd.cmd_2 == 2000U);

  /* Chart: '<S3>/State_Logic' */
  if (FMS_DW.temporalCounter_i1 < 4095U) {
    FMS_DW.temporalCounter_i1++;
  }

  if (FMS_DW.is_active_c4_FMS == 0U) {
    FMS_DW.is_active_c4_FMS = 1U;
    FMS_DW.is_c4_FMS = FMS_IN_Disarm_a;
    FMS_DW.Delay_DSTATE_pi = 0U;
    FMS_B.PWM_Cmd = 1000U;
  } else {
    guard1 = false;
    switch (FMS_DW.is_c4_FMS) {
     case FMS_IN_Arm:
      FMS_DW.Delay_DSTATE_pi = 2U;
      if (((FMS_B.disarm_event == 1.0) && FMS_ConstB.Disarm_Allowed_Logical_Oper)
          || rtb_FixPtRelationalOperator) {
        FMS_DW.is_c4_FMS = FMS_IN_Disarm_a;
        FMS_DW.Delay_DSTATE_pi = 0U;
        FMS_B.PWM_Cmd = 1000U;
      }
      break;

     case FMS_IN_Disarm_a:
      FMS_DW.Delay_DSTATE_pi = 0U;
      if (rtb_Compare_nq && (FMS_B.arm_event == 1.0)) {
        FMS_DW.is_c4_FMS = FMS_IN_Motor_Test;
        FMS_DW.Delay_DSTATE_pi = 1U;
      } else {
        if ((FMS_B.arm_event == 1.0) && FMS_ConstB.Arm_Allowed_Logical_Operato)
        {
          FMS_DW.is_c4_FMS = FMS_IN_Standby;
          FMS_DW.temporalCounter_i1 = 0U;
          FMS_DW.Delay_DSTATE_pi = 1U;
          FMS_B.PWM_Cmd = 1100U;
        }
      }
      break;

     case FMS_IN_Motor_Test:
      FMS_DW.Delay_DSTATE_pi = 1U;
      if ((!rtb_Compare_nq) || (FMS_B.arm_event == 1.0)) {
        FMS_DW.is_c4_FMS = FMS_IN_Disarm_a;
        FMS_DW.Delay_DSTATE_pi = 0U;
        FMS_B.PWM_Cmd = 1000U;
      } else {
        rtb_Product_idx_0 = roundf((rtb_stick_throttle_raw + 1.0F) * 500.0F);
        if (rtb_Product_idx_0 < 65536.0F) {
          tmp_0 = (uint16_T)rtb_Product_idx_0;
        } else {
          tmp_0 = MAX_uint16_T;
        }

        tmp = 1000U + tmp_0;
        if (tmp > 65535U) {
          tmp = 65535U;
        }

        FMS_B.PWM_Cmd = (uint16_T)tmp;
      }
      break;

     default:
      FMS_DW.Delay_DSTATE_pi = 1U;
      if (FMS_DW.temporalCounter_i1 >= 3750U) {
        guard1 = true;
      } else if (rtb_stick_throttle_raw > -0.25F) {
        FMS_DW.is_c4_FMS = FMS_IN_Arm;
        FMS_DW.Delay_DSTATE_pi = 2U;
      } else {
        if ((FMS_B.arm_event == 1.0) || rtb_FixPtRelationalOperator) {
          guard1 = true;
        }
      }
      break;
    }

    if (guard1) {
      FMS_DW.is_c4_FMS = FMS_IN_Disarm_a;
      FMS_DW.Delay_DSTATE_pi = 0U;
      FMS_B.PWM_Cmd = 1000U;
    }
  }

  /* End of Chart: '<S3>/State_Logic' */

  /* Product: '<S116>/Multiply' */
  for (i = 0; i < 16; i++) {
    rtb_Multiply_ox[i] = FMS_B.PWM_Cmd;
  }

  /* End of Product: '<S116>/Multiply' */

  /* Product: '<S124>/Product' incorporates:
   *  Inport: '<Root>/INS_Output'
   */
  rtb_Product_idx_0 = FMS_U.INS_Output.quat[0] * FMS_U.INS_Output.quat[0];
  rtb_Product_idx_1 = FMS_U.INS_Output.quat[1] * FMS_U.INS_Output.quat[1];
  rtb_Product_idx_2 = FMS_U.INS_Output.quat[2] * FMS_U.INS_Output.quat[2];
  rtb_TrigoFcn = FMS_U.INS_Output.quat[3] * FMS_U.INS_Output.quat[3];

  /* Sum: '<S124>/Add' */
  rtb_MatrixConcatenate3[0] = ((rtb_Product_idx_0 + rtb_Product_idx_1) -
    rtb_Product_idx_2) - rtb_TrigoFcn;

  /* Sum: '<S124>/Add5' incorporates:
   *  Sum: '<S124>/Add8'
   */
  rtb_Product_idx_0 -= rtb_Product_idx_1;
  rtb_MatrixConcatenate3[4] = (rtb_Product_idx_0 + rtb_Product_idx_2) -
    rtb_TrigoFcn;

  /* Sum: '<S124>/Add8' */
  rtb_MatrixConcatenate3[8] = (rtb_Product_idx_0 - rtb_Product_idx_2) +
    rtb_TrigoFcn;

  /* Product: '<S124>/Product1' incorporates:
   *  Inport: '<Root>/INS_Output'
   *  Product: '<S124>/Product5'
   */
  rtb_Product_idx_0 = FMS_U.INS_Output.quat[1] * FMS_U.INS_Output.quat[2];

  /* Product: '<S124>/Product2' incorporates:
   *  Inport: '<Root>/INS_Output'
   *  Product: '<S124>/Product6'
   */
  rtb_Product_idx_2 = FMS_U.INS_Output.quat[0] * FMS_U.INS_Output.quat[3];

  /* Gain: '<S124>/Gain' incorporates:
   *  Product: '<S124>/Product1'
   *  Product: '<S124>/Product2'
   *  Sum: '<S124>/Add1'
   */
  rtb_MatrixConcatenate3[1] = (rtb_Product_idx_0 + rtb_Product_idx_2) * 2.0F;

  /* Product: '<S124>/Product3' incorporates:
   *  Inport: '<Root>/INS_Output'
   *  Product: '<S124>/Product9'
   */
  rtb_TrigoFcn = FMS_U.INS_Output.quat[1] * FMS_U.INS_Output.quat[3];

  /* Product: '<S124>/Product4' incorporates:
   *  Inport: '<Root>/INS_Output'
   *  Product: '<S124>/Product10'
   */
  rtb_Product_idx_1 = FMS_U.INS_Output.quat[0] * FMS_U.INS_Output.quat[2];

  /* Gain: '<S124>/Gain1' incorporates:
   *  Product: '<S124>/Product3'
   *  Product: '<S124>/Product4'
   *  Sum: '<S124>/Add2'
   */
  rtb_MatrixConcatenate3[2] = (rtb_TrigoFcn - rtb_Product_idx_1) * 2.0F;

  /* Gain: '<S124>/Gain2' incorporates:
   *  Sum: '<S124>/Add3'
   */
  rtb_MatrixConcatenate3[3] = (rtb_Product_idx_0 - rtb_Product_idx_2) * 2.0F;

  /* Product: '<S124>/Product7' incorporates:
   *  Inport: '<Root>/INS_Output'
   *  Product: '<S124>/Product12'
   */
  rtb_Product_idx_0 = FMS_U.INS_Output.quat[2] * FMS_U.INS_Output.quat[3];

  /* Product: '<S124>/Product8' incorporates:
   *  Inport: '<Root>/INS_Output'
   *  Product: '<S124>/Product11'
   */
  rtb_Product_idx_2 = FMS_U.INS_Output.quat[0] * FMS_U.INS_Output.quat[1];

  /* Gain: '<S124>/Gain3' incorporates:
   *  Product: '<S124>/Product7'
   *  Product: '<S124>/Product8'
   *  Sum: '<S124>/Add4'
   */
  rtb_MatrixConcatenate3[5] = (rtb_Product_idx_0 + rtb_Product_idx_2) * 2.0F;

  /* Gain: '<S124>/Gain4' incorporates:
   *  Sum: '<S124>/Add6'
   */
  rtb_MatrixConcatenate3[6] = (rtb_TrigoFcn + rtb_Product_idx_1) * 2.0F;

  /* Gain: '<S124>/Gain5' incorporates:
   *  Sum: '<S124>/Add7'
   */
  rtb_MatrixConcatenate3[7] = (rtb_Product_idx_0 - rtb_Product_idx_2) * 2.0F;

  /* RelationalOperator: '<S114>/Compare' incorporates:
   *  Constant: '<S114>/Constant'
   */
  rtb_Compare = (uint8_T)(FMS_DW.Delay_DSTATE_pi < 2);

  /* DeadZone: '<S104>/Dead Zone' */
  if (rtb_stick_throttle_raw > FMS_PARAM.StickDeadZone) {
    rtb_Product_idx_1 = rtb_stick_throttle_raw - FMS_PARAM.StickDeadZone;
  } else if (rtb_stick_throttle_raw >= -FMS_PARAM.StickDeadZone) {
    rtb_Product_idx_1 = 0.0F;
  } else {
    rtb_Product_idx_1 = rtb_stick_throttle_raw - (-FMS_PARAM.StickDeadZone);
  }

  /* End of DeadZone: '<S104>/Dead Zone' */

  /* Signum: '<S104>/Sign' */
  if (rtb_Product_idx_1 < 0.0F) {
    rtb_Product_idx_0 = -1.0F;
  } else if (rtb_Product_idx_1 > 0.0F) {
    rtb_Product_idx_0 = 1.0F;
  } else {
    rtb_Product_idx_0 = rtb_Product_idx_1;
  }

  /* End of Signum: '<S104>/Sign' */

  /* Sum: '<S104>/Add' incorporates:
   *  Constant: '<S104>/Constant'
   *  Product: '<S104>/Multiply'
   */
  rtb_Product_idx_2 = rtb_Product_idx_0 * FMS_PARAM.StickDeadZone +
    rtb_Product_idx_1;

  /* Saturate: '<S2>/Saturation' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   */
  if (FMS_U.Pilot_Cmd.ls_lr > 1.0F) {
    rtb_stick_yaw_raw = 1.0F;
  } else if (FMS_U.Pilot_Cmd.ls_lr < -1.0F) {
    rtb_stick_yaw_raw = -1.0F;
  } else {
    rtb_stick_yaw_raw = FMS_U.Pilot_Cmd.ls_lr;
  }

  /* End of Saturate: '<S2>/Saturation' */

  /* DeadZone: '<S103>/Dead Zone' */
  if (rtb_stick_yaw_raw > FMS_PARAM.StickDeadZone) {
    rtb_Product_idx_1 = rtb_stick_yaw_raw - FMS_PARAM.StickDeadZone;
  } else if (rtb_stick_yaw_raw >= -FMS_PARAM.StickDeadZone) {
    rtb_Product_idx_1 = 0.0F;
  } else {
    rtb_Product_idx_1 = rtb_stick_yaw_raw - (-FMS_PARAM.StickDeadZone);
  }

  /* End of DeadZone: '<S103>/Dead Zone' */

  /* Signum: '<S103>/Sign' */
  if (rtb_Product_idx_1 < 0.0F) {
    rtb_Product_idx_0 = -1.0F;
  } else if (rtb_Product_idx_1 > 0.0F) {
    rtb_Product_idx_0 = 1.0F;
  } else {
    rtb_Product_idx_0 = rtb_Product_idx_1;
  }

  /* End of Signum: '<S103>/Sign' */

  /* Sum: '<S103>/Add' incorporates:
   *  Constant: '<S103>/Constant'
   *  Product: '<S103>/Multiply'
   */
  rtb_Product_idx_0 = rtb_Product_idx_0 * FMS_PARAM.StickDeadZone +
    rtb_Product_idx_1;

  /* Trigonometry: '<S108>/TrigoFcn1' incorporates:
   *  Inport: '<Root>/INS_Output'
   */
  rtb_Product_idx_1 = arm_cos_f32(FMS_U.INS_Output.psi);

  /* SignalConversion: '<S108>/ConcatBufferAtVecConcentateIn1' */
  rtb_M_z[0] = rtb_Product_idx_1;

  /* Trigonometry: '<S108>/TrigoFcn' incorporates:
   *  Inport: '<Root>/INS_Output'
   */
  rtb_TrigoFcn = arm_sin_f32(FMS_U.INS_Output.psi);

  /* Gain: '<S108>/Gain' */
  rtb_M_z[1] = -rtb_TrigoFcn;

  /* SignalConversion: '<S108>/ConcatBufferAtVecConcentateIn3' incorporates:
   *  Constant: '<S108>/Constant1'
   */
  rtb_M_z[2] = 0.0F;

  /* SignalConversion: '<S108>/ConcatBufferAtVecConcentate2In1' */
  rtb_M_z[3] = rtb_TrigoFcn;

  /* SignalConversion: '<S108>/ConcatBufferAtVecConcentate2In2' */
  rtb_M_z[4] = rtb_Product_idx_1;

  /* SignalConversion: '<S108>/ConcatBufferAtVecConcentate2In3' incorporates:
   *  Constant: '<S108>/Constant1'
   */
  rtb_M_z[5] = 0.0F;

  /* SignalConversion: '<S108>/ConcatBufferAtVecConcentate1In3' */
  rtb_M_z[6] = FMS_ConstB.VecConcentate3[0];
  rtb_M_z[7] = FMS_ConstB.VecConcentate3[1];
  rtb_M_z[8] = FMS_ConstB.VecConcentate3[2];

  /* SwitchCase: '<S1>/Switch Case' */
  rtPrevAction = FMS_DW.SwitchCase_ActiveSubsystem;
  switch ((int32_T)FMS_B.control_mode) {
   case 2:
    FMS_DW.SwitchCase_ActiveSubsystem = 0;
    break;

   case 3:
    FMS_DW.SwitchCase_ActiveSubsystem = 1;
    break;

   case 4:
    FMS_DW.SwitchCase_ActiveSubsystem = 2;
    break;

   case 5:
    FMS_DW.SwitchCase_ActiveSubsystem = 3;
    break;

   default:
    FMS_DW.SwitchCase_ActiveSubsystem = 4;
    break;
  }

  switch (FMS_DW.SwitchCase_ActiveSubsystem) {
   case 0:
    if (FMS_DW.SwitchCase_ActiveSubsystem != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S1>/Position_Mode' incorporates:
       *  ActionPort: '<S8>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S1>/Switch Case' incorporates:
       *  Delay: '<S78>/Delay'
       *  Delay: '<S97>/Delay'
       *  Delay: '<S98>/Delay'
       *  UnitDelay: '<S69>/Delay Input1'
       *  UnitDelay: '<S70>/Delay Input1'
       *  UnitDelay: '<S95>/Delay Input1'
       *  UnitDelay: '<S96>/Delay Input1'
       *
       * Block description for '<S69>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S70>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S95>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S96>/Delay Input1':
       *
       *  Store in Global RAM
       */
      FMS_DW.DelayInput1_DSTATE_iu = false;
      FMS_DW.icLoad_f = 1U;
      FMS_DW.DelayInput1_DSTATE_pv = false;
      FMS_DW.icLoad_a = 1U;
      FMS_DW.DelayInput1_DSTATE_n = false;
      FMS_DW.DelayInput1_DSTATE_c = false;
      FMS_DW.icLoad_o = 1U;

      /* End of InitializeConditions for SubSystem: '<S1>/Position_Mode' */

      /* SystemReset for IfAction SubSystem: '<S1>/Position_Mode' incorporates:
       *  ActionPort: '<S8>/Action Port'
       */
      /* SystemReset for SwitchCase: '<S1>/Switch Case' incorporates:
       *  Chart: '<S65>/Motion_State'
       *  Chart: '<S81>/XY_Motion_State'
       *  Chart: '<S81>/Z_Motion_State'
       */
      FMS_DW.temporalCounter_i1_b = 0U;
      FMS_DW.is_active_c7_FMS = 0U;
      FMS_DW.is_c7_FMS = FMS_IN_NO_ACTIVE_CHILD_h;
      FMS_Z_Motion_State_Reset(&FMS_DW.sf_Z_Motion_State);
      FMS_Motion_State_Reset(&FMS_DW.sf_Motion_State);

      /* End of SystemReset for SubSystem: '<S1>/Position_Mode' */
    }

    /* Outputs for IfAction SubSystem: '<S1>/Position_Mode' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Logic: '<S84>/Logical Operator' incorporates:
     *  Constant: '<S101>/Constant'
     *  RelationalOperator: '<S101>/Compare'
     */
    rtb_FixPtRelationalOperator = ((rtb_Add_d != 0.0F) || (rtb_Add_m != 0.0F));

    /* Chart: '<S81>/XY_Motion_State' incorporates:
     *  Inport: '<Root>/INS_Output'
     *  Math: '<S83>/Math Function'
     *  Math: '<S83>/Math Function1'
     *  Sqrt: '<S83>/Sqrt'
     *  Sum: '<S83>/Add'
     */
    if (FMS_DW.temporalCounter_i1_b < 511U) {
      FMS_DW.temporalCounter_i1_b++;
    }

    if (FMS_DW.is_active_c7_FMS == 0U) {
      FMS_DW.is_active_c7_FMS = 1U;
      FMS_DW.is_c7_FMS = FMS_IN_Move_j;
      i = 0;
    } else {
      switch (FMS_DW.is_c7_FMS) {
       case FMS_IN_Brake_hi:
        i = 1;
        if ((sqrtf(FMS_U.INS_Output.vn * FMS_U.INS_Output.vn +
                   FMS_U.INS_Output.ve * FMS_U.INS_Output.ve) <= 0.2) ||
            (FMS_DW.temporalCounter_i1_b >= 313U)) {
          FMS_DW.is_c7_FMS = FMS_IN_Hold_n;
          i = 2;
        } else {
          if (rtb_FixPtRelationalOperator) {
            FMS_DW.is_c7_FMS = FMS_IN_Move_j;
            i = 0;
          }
        }
        break;

       case FMS_IN_Hold_n:
        i = 2;
        if (rtb_FixPtRelationalOperator) {
          FMS_DW.is_c7_FMS = FMS_IN_Move_j;
          i = 0;
        }
        break;

       default:
        i = 0;
        if (!rtb_FixPtRelationalOperator) {
          FMS_DW.is_c7_FMS = FMS_IN_Brake_hi;
          FMS_DW.temporalCounter_i1_b = 0U;
          i = 1;
        }
        break;
      }
    }

    /* End of Chart: '<S81>/XY_Motion_State' */

    /* RelationalOperator: '<S93>/Compare' incorporates:
     *  Constant: '<S93>/Constant'
     */
    rtb_FixPtRelationalOperator = (i == 2);

    /* Delay: '<S97>/Delay' incorporates:
     *  Inport: '<Root>/INS_Output'
     *  SignalConversion: '<S97>/TmpSignal ConversionAtDelayInport2'
     */
    if (FMS_DW.icLoad_f != 0) {
      FMS_DW.Delay_DSTATE_pp[0] = FMS_U.INS_Output.x_R;
      FMS_DW.Delay_DSTATE_pp[1] = FMS_U.INS_Output.y_R;
    }

    /* End of Delay: '<S97>/Delay' */

    /* Switch: '<S97>/Switch1' incorporates:
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S95>/FixPt Relational Operator'
     *  SignalConversion: '<S97>/TmpSignal ConversionAtDelayInport2'
     *  UnitDelay: '<S95>/Delay Input1'
     *
     * Block description for '<S95>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if ((int32_T)rtb_FixPtRelationalOperator > (int32_T)
        FMS_DW.DelayInput1_DSTATE_iu) {
      FMS_DW.Delay_DSTATE_pp[0] = FMS_U.INS_Output.x_R;
      FMS_DW.Delay_DSTATE_pp[1] = FMS_U.INS_Output.y_R;
    }

    /* End of Switch: '<S97>/Switch1' */

    /* Chart: '<S81>/Z_Motion_State' incorporates:
     *  Constant: '<S102>/Constant'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S102>/Compare'
     */
    FMS_Z_Motion_State(rtb_Product_idx_2 != 0.0F, FMS_U.INS_Output.vd,
                       &rtb_state_a, &FMS_DW.sf_Z_Motion_State);

    /* RelationalOperator: '<S94>/Compare' incorporates:
     *  Constant: '<S94>/Constant'
     */
    rtb_Compare_nq = (rtb_state_a == 2.0);

    /* Delay: '<S98>/Delay' incorporates:
     *  Gain: '<S92>/Gain'
     *  Inport: '<Root>/INS_Output'
     */
    if (FMS_DW.icLoad_a != 0) {
      FMS_DW.Delay_DSTATE_n = -FMS_U.INS_Output.h_R;
    }

    /* End of Delay: '<S98>/Delay' */

    /* Switch: '<S98>/Switch1' incorporates:
     *  Gain: '<S92>/Gain'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S96>/FixPt Relational Operator'
     *  UnitDelay: '<S96>/Delay Input1'
     *
     * Block description for '<S96>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if ((int32_T)rtb_Compare_nq > (int32_T)FMS_DW.DelayInput1_DSTATE_pv) {
      FMS_DW.Delay_DSTATE_n = -FMS_U.INS_Output.h_R;
    }

    /* End of Switch: '<S98>/Switch1' */

    /* Sum: '<S91>/Sum' incorporates:
     *  Gain: '<S92>/Gain'
     *  Inport: '<Root>/INS_Output'
     */
    rtb_stick_roll_raw = FMS_DW.Delay_DSTATE_pp[0] - FMS_U.INS_Output.x_R;
    rtb_stick_pitch_raw = FMS_DW.Delay_DSTATE_pp[1] - FMS_U.INS_Output.y_R;
    rtb_stick_throttle_raw = FMS_DW.Delay_DSTATE_n - (-FMS_U.INS_Output.h_R);

    /* Product: '<S91>/Multiply' */
    for (i_0 = 0; i_0 < 3; i_0++) {
      rtb_Multiply_a[i_0] = rtb_M_z[i_0 + 6] * rtb_stick_throttle_raw +
        (rtb_M_z[i_0 + 3] * rtb_stick_pitch_raw + rtb_M_z[i_0] *
         rtb_stick_roll_raw);
    }

    /* End of Product: '<S91>/Multiply' */

    /* Switch: '<S82>/Switch' incorporates:
     *  Constant: '<S87>/Constant'
     *  Constant: '<S99>/Constant'
     *  Gain: '<S89>/Gain2'
     *  RelationalOperator: '<S87>/Compare'
     *  RelationalOperator: '<S99>/Compare'
     *  Switch: '<S90>/Switch1'
     */
    if (i == 2) {
      rtb_stick_roll_raw = FMS_PARAM.XY_P * rtb_Multiply_a[0];
      rtb_Add_m = FMS_PARAM.XY_P * rtb_Multiply_a[1];
    } else if (i == 1) {
      /* Switch: '<S90>/Switch1' */
      rtb_stick_roll_raw = 0.0F;
      rtb_Add_m = 0.0F;
    } else {
      /* Switch: '<S90>/Switch1' incorporates:
       *  Gain: '<S90>/Gain1'
       *  Gain: '<S90>/Gain5'
       */
      rtb_stick_roll_raw = FMS_PARAM.VEL_XY_LIM * rtb_Add_d;
      rtb_Add_m *= FMS_PARAM.VEL_XY_LIM;
    }

    /* End of Switch: '<S82>/Switch' */

    /* Outport: '<Root>/FMS_Output' incorporates:
     *  Saturate: '<S82>/Saturation'
     */
    FMS_Y.FMS_Output.u_cmd = rtb_stick_roll_raw;

    /* Saturate: '<S82>/Saturation' */
    if (rtb_stick_roll_raw > FMS_PARAM.VEL_XY_LIM) {
      /* Outport: '<Root>/FMS_Output' */
      FMS_Y.FMS_Output.u_cmd = FMS_PARAM.VEL_XY_LIM;
    } else {
      if (rtb_stick_roll_raw < -FMS_PARAM.VEL_XY_LIM) {
        /* Outport: '<Root>/FMS_Output' */
        FMS_Y.FMS_Output.u_cmd = -FMS_PARAM.VEL_XY_LIM;
      }
    }

    /* Outport: '<Root>/FMS_Output' incorporates:
     *  Saturate: '<S82>/Saturation'
     */
    FMS_Y.FMS_Output.v_cmd = rtb_Add_m;

    /* Saturate: '<S82>/Saturation' */
    if (rtb_Add_m > FMS_PARAM.VEL_XY_LIM) {
      /* Outport: '<Root>/FMS_Output' */
      FMS_Y.FMS_Output.v_cmd = FMS_PARAM.VEL_XY_LIM;
    } else {
      if (rtb_Add_m < -FMS_PARAM.VEL_XY_LIM) {
        /* Outport: '<Root>/FMS_Output' */
        FMS_Y.FMS_Output.v_cmd = -FMS_PARAM.VEL_XY_LIM;
      }
    }

    /* Switch: '<S82>/Switch1' incorporates:
     *  Constant: '<S100>/Constant'
     *  Constant: '<S88>/Constant'
     *  Gain: '<S89>/Gain4'
     *  RelationalOperator: '<S100>/Compare'
     *  RelationalOperator: '<S88>/Compare'
     *  Switch: '<S90>/Switch2'
     */
    if (rtb_state_a == 2.0) {
      rtb_Add_m = FMS_PARAM.Z_P * rtb_Multiply_a[2];
    } else if (rtb_state_a == 1.0) {
      /* Switch: '<S90>/Switch2' incorporates:
       *  Constant: '<S90>/Constant1'
       */
      rtb_Add_m = 0.0F;
    } else {
      /* Switch: '<S90>/Switch2' incorporates:
       *  Gain: '<S90>/Gain6'
       */
      rtb_Add_m = -FMS_PARAM.VEL_Z_LIM * rtb_Product_idx_2;
    }

    /* End of Switch: '<S82>/Switch1' */

    /* Saturate: '<S82>/Saturation1' */
    if (rtb_Add_m > FMS_PARAM.VEL_Z_LIM) {
      /* Outport: '<Root>/FMS_Output' */
      FMS_Y.FMS_Output.w_cmd = FMS_PARAM.VEL_Z_LIM;
    } else if (rtb_Add_m < -FMS_PARAM.VEL_Z_LIM) {
      /* Outport: '<Root>/FMS_Output' */
      FMS_Y.FMS_Output.w_cmd = -FMS_PARAM.VEL_Z_LIM;
    } else {
      /* Outport: '<Root>/FMS_Output' */
      FMS_Y.FMS_Output.w_cmd = rtb_Add_m;
    }

    /* End of Saturate: '<S82>/Saturation1' */

    /* Chart: '<S65>/Motion_State' incorporates:
     *  Abs: '<S75>/Abs'
     *  Constant: '<S80>/Constant'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S80>/Compare'
     */
    FMS_Motion_State(rtb_Product_idx_0 != 0.0F, fabsf(FMS_U.INS_Output.r),
                     &rtb_state_a, &FMS_DW.sf_Motion_State);

    /* RelationalOperator: '<S67>/Compare' incorporates:
     *  Constant: '<S67>/Constant'
     */
    rtb_Compare_je = (rtb_state_a == 2.0);

    /* RelationalOperator: '<S68>/Compare' incorporates:
     *  BusAssignment: '<S3>/Bus Assignment'
     *  Constant: '<S68>/Constant'
     */
    rtb_Compare_ff = (FMS_DW.Delay_DSTATE_pi == 2);

    /* Delay: '<S78>/Delay' incorporates:
     *  Inport: '<Root>/INS_Output'
     */
    if (FMS_DW.icLoad_o != 0) {
      FMS_DW.Delay_DSTATE_c = FMS_U.INS_Output.psi;
    }

    /* End of Delay: '<S78>/Delay' */

    /* Switch: '<S78>/Switch1' incorporates:
     *  Inport: '<Root>/INS_Output'
     *  Logic: '<S65>/Logical Operator'
     *  RelationalOperator: '<S69>/FixPt Relational Operator'
     *  RelationalOperator: '<S70>/FixPt Relational Operator'
     *  UnitDelay: '<S69>/Delay Input1'
     *  UnitDelay: '<S70>/Delay Input1'
     *
     * Block description for '<S69>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S70>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if (((int32_T)rtb_Compare_ff > (int32_T)FMS_DW.DelayInput1_DSTATE_n) ||
        ((int32_T)rtb_Compare_je > (int32_T)FMS_DW.DelayInput1_DSTATE_c)) {
      FMS_DW.Delay_DSTATE_c = FMS_U.INS_Output.psi;
    }

    /* End of Switch: '<S78>/Switch1' */

    /* Switch: '<S65>/Switch' incorporates:
     *  Constant: '<S79>/Constant'
     *  Gain: '<S71>/Gain2'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S79>/Compare'
     *  Sum: '<S76>/Sum'
     *  Switch: '<S72>/Switch1'
     */
    if (rtb_Compare_je) {
      rtb_Add_m = (FMS_DW.Delay_DSTATE_c - FMS_U.INS_Output.psi) *
        FMS_PARAM.YAW_P;
    } else if (rtb_state_a == 1.0) {
      /* Switch: '<S72>/Switch1' incorporates:
       *  Constant: '<S72>/Constant'
       */
      rtb_Add_m = 0.0F;
    } else {
      /* Switch: '<S72>/Switch1' incorporates:
       *  Gain: '<S72>/Gain1'
       */
      rtb_Add_m = FMS_PARAM.YAW_RATE_LIM * rtb_Product_idx_0;
    }

    /* End of Switch: '<S65>/Switch' */

    /* Saturate: '<S65>/Saturation1' */
    if (rtb_Add_m > FMS_PARAM.YAW_RATE_LIM) {
      /* Outport: '<Root>/FMS_Output' */
      FMS_Y.FMS_Output.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
    } else if (rtb_Add_m < -FMS_PARAM.YAW_RATE_LIM) {
      /* Outport: '<Root>/FMS_Output' */
      FMS_Y.FMS_Output.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
    } else {
      /* Outport: '<Root>/FMS_Output' */
      FMS_Y.FMS_Output.psi_rate_cmd = rtb_Add_m;
    }

    /* End of Saturate: '<S65>/Saturation1' */

    /* Outport: '<Root>/FMS_Output' incorporates:
     *  BusAssignment: '<S3>/Bus Assignment'
     *  BusAssignment: '<S8>/Bus Assignment'
     *  Constant: '<S8>/Constant'
     *  DiscreteIntegrator: '<S117>/Discrete-Time Integrator'
     *  SignalConversion: '<S3>/TmpHiddenBufferAtBus AssignmentInport1'
     */
    FMS_Y.FMS_Output.timestamp = FMS_DW.DiscreteTimeIntegrator_DSTATE;
    FMS_Y.FMS_Output.p_cmd = 0.0F;
    FMS_Y.FMS_Output.q_cmd = 0.0F;
    FMS_Y.FMS_Output.r_cmd = 0.0F;
    FMS_Y.FMS_Output.phi_cmd = 0.0F;
    FMS_Y.FMS_Output.theta_cmd = 0.0F;
    FMS_Y.FMS_Output.throttle_cmd = 0U;
    for (i = 0; i < 16; i++) {
      FMS_Y.FMS_Output.actuator_cmd[i] = rtb_Multiply_ox[i];
    }

    FMS_Y.FMS_Output.state = FMS_DW.Delay_DSTATE_pi;
    FMS_Y.FMS_Output.reset = rtb_Compare;
    FMS_Y.FMS_Output.reserved = 0U;
    FMS_Y.FMS_Output.mode = 2U;

    /* Update for UnitDelay: '<S95>/Delay Input1'
     *
     * Block description for '<S95>/Delay Input1':
     *
     *  Store in Global RAM
     */
    FMS_DW.DelayInput1_DSTATE_iu = rtb_FixPtRelationalOperator;

    /* Update for Delay: '<S97>/Delay' */
    FMS_DW.icLoad_f = 0U;

    /* Update for UnitDelay: '<S96>/Delay Input1'
     *
     * Block description for '<S96>/Delay Input1':
     *
     *  Store in Global RAM
     */
    FMS_DW.DelayInput1_DSTATE_pv = rtb_Compare_nq;

    /* Update for Delay: '<S98>/Delay' */
    FMS_DW.icLoad_a = 0U;

    /* Update for UnitDelay: '<S70>/Delay Input1'
     *
     * Block description for '<S70>/Delay Input1':
     *
     *  Store in Global RAM
     */
    FMS_DW.DelayInput1_DSTATE_n = rtb_Compare_ff;

    /* Update for UnitDelay: '<S69>/Delay Input1'
     *
     * Block description for '<S69>/Delay Input1':
     *
     *  Store in Global RAM
     */
    FMS_DW.DelayInput1_DSTATE_c = rtb_Compare_je;

    /* Update for Delay: '<S78>/Delay' */
    FMS_DW.icLoad_o = 0U;

    /* End of Outputs for SubSystem: '<S1>/Position_Mode' */
    break;

   case 1:
    if (FMS_DW.SwitchCase_ActiveSubsystem != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S1>/Altitude_Hold_Mode' incorporates:
       *  ActionPort: '<S5>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S1>/Switch Case' incorporates:
       *  Delay: '<S28>/Delay'
       *  Delay: '<S43>/Delay'
       *  UnitDelay: '<S19>/Delay Input1'
       *  UnitDelay: '<S20>/Delay Input1'
       *  UnitDelay: '<S42>/Delay Input1'
       *
       * Block description for '<S19>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S20>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S42>/Delay Input1':
       *
       *  Store in Global RAM
       */
      FMS_DW.DelayInput1_DSTATE_a = false;
      FMS_DW.icLoad_d = 1U;
      FMS_DW.DelayInput1_DSTATE_j = false;
      FMS_DW.DelayInput1_DSTATE_p = false;
      FMS_DW.icLoad_i = 1U;

      /* End of InitializeConditions for SubSystem: '<S1>/Altitude_Hold_Mode' */

      /* SystemReset for IfAction SubSystem: '<S1>/Altitude_Hold_Mode' incorporates:
       *  ActionPort: '<S5>/Action Port'
       */
      /* SystemReset for SwitchCase: '<S1>/Switch Case' incorporates:
       *  Chart: '<S15>/Motion_State'
       *  Chart: '<S31>/Z_Motion_State'
       */
      FMS_Z_Motion_State_Reset(&FMS_DW.sf_Z_Motion_State_l);
      FMS_Motion_State_Reset(&FMS_DW.sf_Motion_State_c);

      /* End of SystemReset for SubSystem: '<S1>/Altitude_Hold_Mode' */
    }

    /* Outputs for IfAction SubSystem: '<S1>/Altitude_Hold_Mode' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* Chart: '<S31>/Z_Motion_State' incorporates:
     *  Constant: '<S45>/Constant'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S45>/Compare'
     */
    FMS_Z_Motion_State(rtb_Product_idx_2 != 0.0F, FMS_U.INS_Output.vd,
                       &rtb_state_a, &FMS_DW.sf_Z_Motion_State_l);

    /* RelationalOperator: '<S41>/Compare' incorporates:
     *  Constant: '<S41>/Constant'
     */
    rtb_FixPtRelationalOperator = (rtb_state_a == 2.0);

    /* Delay: '<S43>/Delay' incorporates:
     *  Gain: '<S40>/Gain'
     *  Inport: '<Root>/INS_Output'
     */
    if (FMS_DW.icLoad_d != 0) {
      FMS_DW.Delay_DSTATE_e = -FMS_U.INS_Output.h_R;
    }

    /* End of Delay: '<S43>/Delay' */

    /* Switch: '<S43>/Switch1' incorporates:
     *  Gain: '<S40>/Gain'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S42>/FixPt Relational Operator'
     *  UnitDelay: '<S42>/Delay Input1'
     *
     * Block description for '<S42>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if ((int32_T)rtb_FixPtRelationalOperator > (int32_T)
        FMS_DW.DelayInput1_DSTATE_a) {
      FMS_DW.Delay_DSTATE_e = -FMS_U.INS_Output.h_R;
    }

    /* End of Switch: '<S43>/Switch1' */

    /* Switch: '<S32>/Switch1' incorporates:
     *  Constant: '<S36>/Constant'
     *  Constant: '<S44>/Constant'
     *  Gain: '<S37>/Gain4'
     *  Gain: '<S40>/Gain'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S36>/Compare'
     *  RelationalOperator: '<S44>/Compare'
     *  Sum: '<S39>/Sum'
     *  Switch: '<S38>/Switch2'
     */
    if (rtb_state_a == 2.0) {
      rtb_Add_m = (FMS_DW.Delay_DSTATE_e - (-FMS_U.INS_Output.h_R)) *
        FMS_PARAM.Z_P;
    } else if (rtb_state_a == 1.0) {
      /* Switch: '<S38>/Switch2' incorporates:
       *  Constant: '<S38>/Constant1'
       */
      rtb_Add_m = 0.0F;
    } else {
      /* Switch: '<S38>/Switch2' incorporates:
       *  Gain: '<S38>/Gain6'
       */
      rtb_Add_m = -FMS_PARAM.VEL_Z_LIM * rtb_Product_idx_2;
    }

    /* End of Switch: '<S32>/Switch1' */

    /* Saturate: '<S16>/Saturation' */
    if (rtb_Add_m > FMS_PARAM.VEL_Z_LIM) {
      /* Outport: '<Root>/FMS_Output' */
      FMS_Y.FMS_Output.w_cmd = FMS_PARAM.VEL_Z_LIM;
    } else if (rtb_Add_m < -FMS_PARAM.VEL_Z_LIM) {
      /* Outport: '<Root>/FMS_Output' */
      FMS_Y.FMS_Output.w_cmd = -FMS_PARAM.VEL_Z_LIM;
    } else {
      /* Outport: '<Root>/FMS_Output' */
      FMS_Y.FMS_Output.w_cmd = rtb_Add_m;
    }

    /* End of Saturate: '<S16>/Saturation' */

    /* Chart: '<S15>/Motion_State' incorporates:
     *  Abs: '<S25>/Abs'
     *  Constant: '<S30>/Constant'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S30>/Compare'
     */
    FMS_Motion_State(rtb_Product_idx_0 != 0.0F, fabsf(FMS_U.INS_Output.r),
                     &rtb_state_a, &FMS_DW.sf_Motion_State_c);

    /* RelationalOperator: '<S17>/Compare' incorporates:
     *  Constant: '<S17>/Constant'
     */
    rtb_Compare_nq = (rtb_state_a == 2.0);

    /* RelationalOperator: '<S18>/Compare' incorporates:
     *  BusAssignment: '<S3>/Bus Assignment'
     *  Constant: '<S18>/Constant'
     */
    rtb_Compare_je = (FMS_DW.Delay_DSTATE_pi == 2);

    /* Delay: '<S28>/Delay' incorporates:
     *  Inport: '<Root>/INS_Output'
     */
    if (FMS_DW.icLoad_i != 0) {
      FMS_DW.Delay_DSTATE_p = FMS_U.INS_Output.psi;
    }

    /* End of Delay: '<S28>/Delay' */

    /* Switch: '<S28>/Switch1' incorporates:
     *  Inport: '<Root>/INS_Output'
     *  Logic: '<S15>/Logical Operator'
     *  RelationalOperator: '<S19>/FixPt Relational Operator'
     *  RelationalOperator: '<S20>/FixPt Relational Operator'
     *  UnitDelay: '<S19>/Delay Input1'
     *  UnitDelay: '<S20>/Delay Input1'
     *
     * Block description for '<S19>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S20>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if (((int32_T)rtb_Compare_je > (int32_T)FMS_DW.DelayInput1_DSTATE_j) ||
        ((int32_T)rtb_Compare_nq > (int32_T)FMS_DW.DelayInput1_DSTATE_p)) {
      FMS_DW.Delay_DSTATE_p = FMS_U.INS_Output.psi;
    }

    /* End of Switch: '<S28>/Switch1' */

    /* Switch: '<S15>/Switch' incorporates:
     *  Constant: '<S29>/Constant'
     *  Gain: '<S21>/Gain2'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S29>/Compare'
     *  Sum: '<S26>/Sum'
     *  Switch: '<S22>/Switch1'
     */
    if (rtb_Compare_nq) {
      rtb_Add_m = (FMS_DW.Delay_DSTATE_p - FMS_U.INS_Output.psi) *
        FMS_PARAM.YAW_P;
    } else if (rtb_state_a == 1.0) {
      /* Switch: '<S22>/Switch1' incorporates:
       *  Constant: '<S22>/Constant'
       */
      rtb_Add_m = 0.0F;
    } else {
      /* Switch: '<S22>/Switch1' incorporates:
       *  Gain: '<S22>/Gain1'
       */
      rtb_Add_m = FMS_PARAM.YAW_RATE_LIM * rtb_Product_idx_0;
    }

    /* End of Switch: '<S15>/Switch' */

    /* Saturate: '<S15>/Saturation1' */
    if (rtb_Add_m > FMS_PARAM.YAW_RATE_LIM) {
      /* Outport: '<Root>/FMS_Output' */
      FMS_Y.FMS_Output.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
    } else if (rtb_Add_m < -FMS_PARAM.YAW_RATE_LIM) {
      /* Outport: '<Root>/FMS_Output' */
      FMS_Y.FMS_Output.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
    } else {
      /* Outport: '<Root>/FMS_Output' */
      FMS_Y.FMS_Output.psi_rate_cmd = rtb_Add_m;
    }

    /* End of Saturate: '<S15>/Saturation1' */

    /* Outport: '<Root>/FMS_Output' incorporates:
     *  BusAssignment: '<S3>/Bus Assignment'
     *  BusAssignment: '<S5>/Bus Assignment'
     *  Constant: '<S5>/Constant'
     *  DiscreteIntegrator: '<S117>/Discrete-Time Integrator'
     *  Gain: '<S14>/Gain'
     *  Gain: '<S14>/Gain1'
     *  SignalConversion: '<S3>/TmpHiddenBufferAtBus AssignmentInport1'
     */
    FMS_Y.FMS_Output.timestamp = FMS_DW.DiscreteTimeIntegrator_DSTATE;
    FMS_Y.FMS_Output.p_cmd = 0.0F;
    FMS_Y.FMS_Output.q_cmd = 0.0F;
    FMS_Y.FMS_Output.r_cmd = 0.0F;
    FMS_Y.FMS_Output.u_cmd = 0.0F;
    FMS_Y.FMS_Output.v_cmd = 0.0F;
    FMS_Y.FMS_Output.throttle_cmd = 0U;
    for (i = 0; i < 16; i++) {
      FMS_Y.FMS_Output.actuator_cmd[i] = rtb_Multiply_ox[i];
    }

    FMS_Y.FMS_Output.state = FMS_DW.Delay_DSTATE_pi;
    FMS_Y.FMS_Output.reset = rtb_Compare;
    FMS_Y.FMS_Output.reserved = 0U;
    FMS_Y.FMS_Output.mode = 3U;
    FMS_Y.FMS_Output.phi_cmd = FMS_PARAM.ROLL_PITCH_LIM * rtb_stick_roll_raw;
    FMS_Y.FMS_Output.theta_cmd = -FMS_PARAM.ROLL_PITCH_LIM * rtb_stick_pitch_raw;

    /* Update for UnitDelay: '<S42>/Delay Input1'
     *
     * Block description for '<S42>/Delay Input1':
     *
     *  Store in Global RAM
     */
    FMS_DW.DelayInput1_DSTATE_a = rtb_FixPtRelationalOperator;

    /* Update for Delay: '<S43>/Delay' */
    FMS_DW.icLoad_d = 0U;

    /* Update for UnitDelay: '<S20>/Delay Input1'
     *
     * Block description for '<S20>/Delay Input1':
     *
     *  Store in Global RAM
     */
    FMS_DW.DelayInput1_DSTATE_j = rtb_Compare_je;

    /* Update for UnitDelay: '<S19>/Delay Input1'
     *
     * Block description for '<S19>/Delay Input1':
     *
     *  Store in Global RAM
     */
    FMS_DW.DelayInput1_DSTATE_p = rtb_Compare_nq;

    /* Update for Delay: '<S28>/Delay' */
    FMS_DW.icLoad_i = 0U;

    /* End of Outputs for SubSystem: '<S1>/Altitude_Hold_Mode' */
    break;

   case 2:
    if (FMS_DW.SwitchCase_ActiveSubsystem != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S1>/Manual_Mode' incorporates:
       *  ActionPort: '<S6>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S1>/Switch Case' incorporates:
       *  Delay: '<S61>/Delay'
       *  UnitDelay: '<S52>/Delay Input1'
       *  UnitDelay: '<S53>/Delay Input1'
       *
       * Block description for '<S52>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S53>/Delay Input1':
       *
       *  Store in Global RAM
       */
      FMS_DW.DelayInput1_DSTATE_l = false;
      FMS_DW.DelayInput1_DSTATE_i = false;
      FMS_DW.icLoad = 1U;

      /* End of InitializeConditions for SubSystem: '<S1>/Manual_Mode' */

      /* SystemReset for IfAction SubSystem: '<S1>/Manual_Mode' incorporates:
       *  ActionPort: '<S6>/Action Port'
       */
      /* SystemReset for SwitchCase: '<S1>/Switch Case' incorporates:
       *  Chart: '<S48>/Motion_State'
       */
      FMS_Motion_State_Reset(&FMS_DW.sf_Motion_State_j);

      /* End of SystemReset for SubSystem: '<S1>/Manual_Mode' */
    }

    /* Outputs for IfAction SubSystem: '<S1>/Manual_Mode' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    /* Chart: '<S48>/Motion_State' incorporates:
     *  Abs: '<S58>/Abs'
     *  Constant: '<S63>/Constant'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S63>/Compare'
     */
    FMS_Motion_State(rtb_Product_idx_0 != 0.0F, fabsf(FMS_U.INS_Output.r),
                     &rtb_state_a, &FMS_DW.sf_Motion_State_j);

    /* RelationalOperator: '<S50>/Compare' incorporates:
     *  Constant: '<S50>/Constant'
     */
    rtb_FixPtRelationalOperator = (rtb_state_a == 2.0);

    /* RelationalOperator: '<S51>/Compare' incorporates:
     *  BusAssignment: '<S3>/Bus Assignment'
     *  Constant: '<S51>/Constant'
     */
    rtb_Compare_nq = (FMS_DW.Delay_DSTATE_pi == 2);

    /* Delay: '<S61>/Delay' incorporates:
     *  Inport: '<Root>/INS_Output'
     */
    if (FMS_DW.icLoad != 0) {
      FMS_DW.Delay_DSTATE = FMS_U.INS_Output.psi;
    }

    /* End of Delay: '<S61>/Delay' */

    /* Switch: '<S61>/Switch1' incorporates:
     *  Inport: '<Root>/INS_Output'
     *  Logic: '<S48>/Logical Operator'
     *  RelationalOperator: '<S52>/FixPt Relational Operator'
     *  RelationalOperator: '<S53>/FixPt Relational Operator'
     *  UnitDelay: '<S52>/Delay Input1'
     *  UnitDelay: '<S53>/Delay Input1'
     *
     * Block description for '<S52>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S53>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if (((int32_T)rtb_Compare_nq > (int32_T)FMS_DW.DelayInput1_DSTATE_l) ||
        ((int32_T)rtb_FixPtRelationalOperator > (int32_T)
         FMS_DW.DelayInput1_DSTATE_i)) {
      FMS_DW.Delay_DSTATE = FMS_U.INS_Output.psi;
    }

    /* End of Switch: '<S61>/Switch1' */

    /* Switch: '<S48>/Switch' incorporates:
     *  Constant: '<S62>/Constant'
     *  Gain: '<S54>/Gain2'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S62>/Compare'
     *  Sum: '<S59>/Sum'
     *  Switch: '<S55>/Switch1'
     */
    if (rtb_FixPtRelationalOperator) {
      rtb_Add_m = (FMS_DW.Delay_DSTATE - FMS_U.INS_Output.psi) * FMS_PARAM.YAW_P;
    } else if (rtb_state_a == 1.0) {
      /* Switch: '<S55>/Switch1' incorporates:
       *  Constant: '<S55>/Constant'
       */
      rtb_Add_m = 0.0F;
    } else {
      /* Switch: '<S55>/Switch1' incorporates:
       *  Gain: '<S55>/Gain1'
       */
      rtb_Add_m = FMS_PARAM.YAW_RATE_LIM * rtb_Product_idx_0;
    }

    /* End of Switch: '<S48>/Switch' */

    /* Saturate: '<S48>/Saturation1' */
    if (rtb_Add_m > FMS_PARAM.YAW_RATE_LIM) {
      /* Outport: '<Root>/FMS_Output' */
      FMS_Y.FMS_Output.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
    } else if (rtb_Add_m < -FMS_PARAM.YAW_RATE_LIM) {
      /* Outport: '<Root>/FMS_Output' */
      FMS_Y.FMS_Output.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
    } else {
      /* Outport: '<Root>/FMS_Output' */
      FMS_Y.FMS_Output.psi_rate_cmd = rtb_Add_m;
    }

    /* End of Saturate: '<S48>/Saturation1' */

    /* Outport: '<Root>/FMS_Output' incorporates:
     *  BusAssignment: '<S3>/Bus Assignment'
     *  BusAssignment: '<S6>/Bus Assignment'
     *  Constant: '<S49>/Constant'
     *  Constant: '<S49>/Constant1'
     *  Constant: '<S6>/Constant'
     *  DiscreteIntegrator: '<S117>/Discrete-Time Integrator'
     *  Gain: '<S47>/Gain1'
     *  Gain: '<S47>/Gain2'
     *  Gain: '<S49>/Gain'
     *  SignalConversion: '<S3>/TmpHiddenBufferAtBus AssignmentInport1'
     *  Sum: '<S49>/Add'
     *  Sum: '<S49>/Sum'
     */
    FMS_Y.FMS_Output.timestamp = FMS_DW.DiscreteTimeIntegrator_DSTATE;
    FMS_Y.FMS_Output.p_cmd = 0.0F;
    FMS_Y.FMS_Output.q_cmd = 0.0F;
    FMS_Y.FMS_Output.r_cmd = 0.0F;
    FMS_Y.FMS_Output.u_cmd = 0.0F;
    FMS_Y.FMS_Output.v_cmd = 0.0F;
    FMS_Y.FMS_Output.w_cmd = 0.0F;
    for (i = 0; i < 16; i++) {
      FMS_Y.FMS_Output.actuator_cmd[i] = rtb_Multiply_ox[i];
    }

    FMS_Y.FMS_Output.state = FMS_DW.Delay_DSTATE_pi;
    FMS_Y.FMS_Output.reset = rtb_Compare;
    FMS_Y.FMS_Output.reserved = 0U;
    FMS_Y.FMS_Output.mode = 4U;
    FMS_Y.FMS_Output.throttle_cmd = (uint32_T)fmodf(floorf
      ((rtb_stick_throttle_raw + 1.0F) * 500.0F), 4.2949673E+9F) + 1000U;
    FMS_Y.FMS_Output.phi_cmd = FMS_PARAM.ROLL_PITCH_LIM * rtb_stick_roll_raw;
    FMS_Y.FMS_Output.theta_cmd = -FMS_PARAM.ROLL_PITCH_LIM * rtb_stick_pitch_raw;

    /* Update for UnitDelay: '<S53>/Delay Input1'
     *
     * Block description for '<S53>/Delay Input1':
     *
     *  Store in Global RAM
     */
    FMS_DW.DelayInput1_DSTATE_l = rtb_Compare_nq;

    /* Update for UnitDelay: '<S52>/Delay Input1'
     *
     * Block description for '<S52>/Delay Input1':
     *
     *  Store in Global RAM
     */
    FMS_DW.DelayInput1_DSTATE_i = rtb_FixPtRelationalOperator;

    /* Update for Delay: '<S61>/Delay' */
    FMS_DW.icLoad = 0U;

    /* End of Outputs for SubSystem: '<S1>/Manual_Mode' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S1>/Acro_Mode' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* Outport: '<Root>/FMS_Output' incorporates:
     *  BusAssignment: '<S3>/Bus Assignment'
     *  BusAssignment: '<S4>/Bus Assignment'
     *  Constant: '<S12>/Constant'
     *  Constant: '<S12>/Constant1'
     *  Constant: '<S4>/Constant'
     *  DiscreteIntegrator: '<S117>/Discrete-Time Integrator'
     *  Gain: '<S11>/Gain'
     *  Gain: '<S11>/Gain1'
     *  Gain: '<S11>/Gain2'
     *  Gain: '<S12>/Gain'
     *  SignalConversion: '<S3>/TmpHiddenBufferAtBus AssignmentInport1'
     *  Sum: '<S12>/Add'
     *  Sum: '<S12>/Sum'
     */
    FMS_Y.FMS_Output.timestamp = FMS_DW.DiscreteTimeIntegrator_DSTATE;
    FMS_Y.FMS_Output.phi_cmd = 0.0F;
    FMS_Y.FMS_Output.theta_cmd = 0.0F;
    FMS_Y.FMS_Output.psi_rate_cmd = 0.0F;
    FMS_Y.FMS_Output.u_cmd = 0.0F;
    FMS_Y.FMS_Output.v_cmd = 0.0F;
    FMS_Y.FMS_Output.w_cmd = 0.0F;
    for (i = 0; i < 16; i++) {
      FMS_Y.FMS_Output.actuator_cmd[i] = rtb_Multiply_ox[i];
    }

    FMS_Y.FMS_Output.state = FMS_DW.Delay_DSTATE_pi;
    FMS_Y.FMS_Output.reset = rtb_Compare;
    FMS_Y.FMS_Output.reserved = 0U;
    FMS_Y.FMS_Output.mode = 5U;
    FMS_Y.FMS_Output.throttle_cmd = (uint32_T)fmodf(floorf
      ((rtb_stick_throttle_raw + 1.0F) * 500.0F), 4.2949673E+9F) + 1000U;
    FMS_Y.FMS_Output.p_cmd = 1.04719758F * rtb_stick_roll_raw;
    FMS_Y.FMS_Output.q_cmd = -1.04719758F * rtb_stick_pitch_raw;
    FMS_Y.FMS_Output.r_cmd = 1.04719758F * rtb_stick_yaw_raw;

    /* End of Outputs for SubSystem: '<S1>/Acro_Mode' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S1>/Unknown_Mode' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* Outport: '<Root>/FMS_Output' incorporates:
     *  BusAssignment: '<S3>/Bus Assignment'
     *  BusAssignment: '<S9>/Bus Assignment'
     *  Constant: '<S9>/Constant1'
     *  Constant: '<S9>/Constant2'
     *  DiscreteIntegrator: '<S117>/Discrete-Time Integrator'
     *  SignalConversion: '<S3>/TmpHiddenBufferAtBus AssignmentInport1'
     */
    FMS_Y.FMS_Output.timestamp = FMS_DW.DiscreteTimeIntegrator_DSTATE;
    FMS_Y.FMS_Output.p_cmd = 0.0F;
    FMS_Y.FMS_Output.q_cmd = 0.0F;
    FMS_Y.FMS_Output.r_cmd = 0.0F;
    FMS_Y.FMS_Output.phi_cmd = 0.0F;
    FMS_Y.FMS_Output.theta_cmd = 0.0F;
    FMS_Y.FMS_Output.psi_rate_cmd = 0.0F;
    FMS_Y.FMS_Output.u_cmd = 0.0F;
    FMS_Y.FMS_Output.v_cmd = 0.0F;
    FMS_Y.FMS_Output.w_cmd = 0.0F;
    FMS_Y.FMS_Output.throttle_cmd = 0U;
    for (i = 0; i < 16; i++) {
      FMS_Y.FMS_Output.actuator_cmd[i] = rtb_Multiply_ox[i];
    }

    FMS_Y.FMS_Output.state = FMS_DW.Delay_DSTATE_pi;
    FMS_Y.FMS_Output.reserved = 0U;
    FMS_Y.FMS_Output.mode = 0U;
    FMS_Y.FMS_Output.reset = 1U;

    /* End of Outputs for SubSystem: '<S1>/Unknown_Mode' */
    break;
  }

  /* End of SwitchCase: '<S1>/Switch Case' */

  /* Product: '<S120>/Multiply' incorporates:
   *  Inport: '<Root>/INS_Output'
   *  SignalConversion: '<S120>/ConcatBufferAtMatrix Concatenate3In1'
   *  SignalConversion: '<S120>/ConcatBufferAtMatrix Concatenate3In2'
   *  SignalConversion: '<S120>/ConcatBufferAtMatrix Concatenate3In3'
   */
  for (i_0 = 0; i_0 < 3; i_0++) {
    rtb_Multiply_a[i_0] = rtb_MatrixConcatenate3[i_0 + 6] * FMS_U.INS_Output.az
      + (rtb_MatrixConcatenate3[i_0 + 3] * FMS_U.INS_Output.ay +
         rtb_MatrixConcatenate3[i_0] * FMS_U.INS_Output.ax);
  }

  /* End of Product: '<S120>/Multiply' */

  /* Update for DiscreteIntegrator: '<S123>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S123>/Gain2'
   *  Sum: '<S123>/Sum9'
   */
  FMS_DW.DiscreteTimeIntegrator5_DSTATE += (rtb_Multiply_a[2] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE) * 10.0F * 0.008F;

  /* Update for UnitDelay: '<S111>/Delay Input1'
   *
   * Block description for '<S111>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE = rtb_LogicalOperator1;

  /* Update for DiscreteIntegrator: '<S117>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S117>/Constant'
   */
  FMS_DW.DiscreteTimeIntegrator_DSTATE += FMS_EXPORT.period;
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

  /* states (dwork) */
  (void) memset((void *)&FMS_DW, 0,
                sizeof(DW_FMS_T));

  /* external inputs */
  (void)memset(&FMS_U, 0, sizeof(ExtU_FMS_T));

  /* external outputs */
  FMS_Y.FMS_Output = FMS_rtZFMS_Out_Bus;

  /* Start for SwitchCase: '<S1>/Switch Case' */
  FMS_DW.SwitchCase_ActiveSubsystem = -1;

  /* SystemInitialize for Chart: '<S1>/Mode_Logic' */
  FMS_DW.is_active_c1_FMS = 0U;
  FMS_DW.is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for Chart: '<S112>/Arm_Event' */
  FMS_DW.is_active_c3_FMS = 0U;
  FMS_DW.is_c3_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for Chart: '<S112>/Disarm_Event' */
  FMS_DW.temporalCounter_i1_a = 0U;
  FMS_DW.is_active_c10_FMS = 0U;
  FMS_DW.is_c10_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for Chart: '<S3>/State_Logic' */
  FMS_DW.temporalCounter_i1 = 0U;
  FMS_DW.is_active_c4_FMS = 0U;
  FMS_DW.is_c4_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for IfAction SubSystem: '<S1>/Position_Mode' */
  /* InitializeConditions for UnitDelay: '<S95>/Delay Input1'
   *
   * Block description for '<S95>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_iu = false;

  /* InitializeConditions for Delay: '<S97>/Delay' */
  FMS_DW.icLoad_f = 1U;

  /* InitializeConditions for UnitDelay: '<S96>/Delay Input1'
   *
   * Block description for '<S96>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_pv = false;

  /* InitializeConditions for Delay: '<S98>/Delay' */
  FMS_DW.icLoad_a = 1U;

  /* InitializeConditions for UnitDelay: '<S70>/Delay Input1'
   *
   * Block description for '<S70>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_n = false;

  /* InitializeConditions for UnitDelay: '<S69>/Delay Input1'
   *
   * Block description for '<S69>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_c = false;

  /* InitializeConditions for Delay: '<S78>/Delay' */
  FMS_DW.icLoad_o = 1U;

  /* SystemInitialize for Chart: '<S81>/XY_Motion_State' */
  FMS_DW.temporalCounter_i1_b = 0U;
  FMS_DW.is_active_c7_FMS = 0U;
  FMS_DW.is_c7_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for Chart: '<S81>/Z_Motion_State' */
  FMS_Z_Motion_State_Init(&FMS_DW.sf_Z_Motion_State);

  /* SystemInitialize for Chart: '<S65>/Motion_State' */
  FMS_Motion_State_Init(&FMS_DW.sf_Motion_State);

  /* End of SystemInitialize for SubSystem: '<S1>/Position_Mode' */

  /* SystemInitialize for IfAction SubSystem: '<S1>/Altitude_Hold_Mode' */
  /* InitializeConditions for UnitDelay: '<S42>/Delay Input1'
   *
   * Block description for '<S42>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_a = false;

  /* InitializeConditions for Delay: '<S43>/Delay' */
  FMS_DW.icLoad_d = 1U;

  /* InitializeConditions for UnitDelay: '<S20>/Delay Input1'
   *
   * Block description for '<S20>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_j = false;

  /* InitializeConditions for UnitDelay: '<S19>/Delay Input1'
   *
   * Block description for '<S19>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_p = false;

  /* InitializeConditions for Delay: '<S28>/Delay' */
  FMS_DW.icLoad_i = 1U;

  /* SystemInitialize for Chart: '<S31>/Z_Motion_State' */
  FMS_Z_Motion_State_Init(&FMS_DW.sf_Z_Motion_State_l);

  /* SystemInitialize for Chart: '<S15>/Motion_State' */
  FMS_Motion_State_Init(&FMS_DW.sf_Motion_State_c);

  /* End of SystemInitialize for SubSystem: '<S1>/Altitude_Hold_Mode' */

  /* SystemInitialize for IfAction SubSystem: '<S1>/Manual_Mode' */
  /* InitializeConditions for UnitDelay: '<S53>/Delay Input1'
   *
   * Block description for '<S53>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_l = false;

  /* InitializeConditions for UnitDelay: '<S52>/Delay Input1'
   *
   * Block description for '<S52>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_i = false;

  /* InitializeConditions for Delay: '<S61>/Delay' */
  FMS_DW.icLoad = 1U;

  /* SystemInitialize for Chart: '<S48>/Motion_State' */
  FMS_Motion_State_Init(&FMS_DW.sf_Motion_State_j);

  /* End of SystemInitialize for SubSystem: '<S1>/Manual_Mode' */
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
