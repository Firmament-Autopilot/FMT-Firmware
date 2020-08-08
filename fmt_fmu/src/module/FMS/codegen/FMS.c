/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.597
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Aug  5 16:39:49 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S57>/Motion_State' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<S71>/Z_Motion_State' */
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

/* Named constants for Chart: '<S71>/XY_Motion_State' */
#define FMS_IN_Brake_hi                ((uint8_T)1U)
#define FMS_IN_Hold_n                  ((uint8_T)2U)
#define FMS_IN_Move_j                  ((uint8_T)3U)

/* Named constants for Chart: '<S98>/Arm_Event' */
#define FMS_IN_Idle                    ((uint8_T)1U)
#define FMS_IN_arm_event               ((uint8_T)2U)
#define FMS_IN_ready                   ((uint8_T)3U)

/* Named constants for Chart: '<S98>/Disarm_Event' */
#define FMS_IN_Disarm                  ((uint8_T)1U)
#define FMS_IN_Idle_o                  ((uint8_T)2U)
#define FMS_IN_On_Ground               ((uint8_T)3U)

/* Named constants for Chart: '<S3>/State_Logic' */
#define FMS_IN_Arm                     ((uint8_T)1U)
#define FMS_IN_Disarm_a                ((uint8_T)2U)
#define FMS_IN_Standby                 ((uint8_T)3U)

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
  1.0F,
  5.0F,
  2.5F,
  1.0F,
  1.04719758F,
  0.52359879F
} ;                                    /* Variable: FMS_PARAM
                                        * Referenced by:
                                        *   '<S93>/Constant'
                                        *   '<S93>/Dead Zone'
                                        *   '<S94>/Constant'
                                        *   '<S94>/Dead Zone'
                                        *   '<S95>/Constant'
                                        *   '<S95>/Dead Zone'
                                        *   '<S96>/Constant'
                                        *   '<S96>/Dead Zone'
                                        *   '<S10>/Gain'
                                        *   '<S10>/Gain1'
                                        *   '<S11>/Saturation1'
                                        *   '<S12>/Saturation'
                                        *   '<S41>/Gain1'
                                        *   '<S41>/Gain2'
                                        *   '<S42>/Saturation1'
                                        *   '<S57>/Saturation1'
                                        *   '<S15>/Gain2'
                                        *   '<S16>/Gain1'
                                        *   '<S46>/Gain2'
                                        *   '<S47>/Gain1'
                                        *   '<S61>/Gain2'
                                        *   '<S62>/Gain1'
                                        *   '<S72>/Saturation'
                                        *   '<S72>/Saturation1'
                                        *   '<S31>/Gain4'
                                        *   '<S32>/Gain6'
                                        *   '<S79>/Gain2'
                                        *   '<S79>/Gain4'
                                        *   '<S80>/Gain1'
                                        *   '<S80>/Gain5'
                                        *   '<S80>/Gain6'
                                        */

struct_4XfCoaAMTej5uH3d8u88xB FMS_EXPORT = {
  8U
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by: '<S103>/Constant'
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
 *    '<S57>/Motion_State'
 *    '<S11>/Motion_State'
 *    '<S42>/Motion_State'
 */
void FMS_Motion_State_Init(DW_Motion_State_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c5_FMS = 0U;
  localDW->is_c5_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * System reset for atomic system:
 *    '<S57>/Motion_State'
 *    '<S11>/Motion_State'
 *    '<S42>/Motion_State'
 */
void FMS_Motion_State_Reset(DW_Motion_State_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c5_FMS = 0U;
  localDW->is_c5_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * Output and update for atomic system:
 *    '<S57>/Motion_State'
 *    '<S11>/Motion_State'
 *    '<S42>/Motion_State'
 */
void FMS_Motion_State(boolean_T rtu_move_cmd, real32_T rtu_heading_rate, real_T *
                      rty_state, DW_Motion_State_FMS_T *localDW)
{
  /* Chart: '<S57>/Motion_State' */
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

  /* End of Chart: '<S57>/Motion_State' */
}

/*
 * System initialize for atomic system:
 *    '<S71>/Z_Motion_State'
 *    '<S25>/Z_Motion_State'
 */
void FMS_Z_Motion_State_Init(DW_Z_Motion_State_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c8_FMS = 0U;
  localDW->is_c8_FMS = FMS_IN_NO_ACTIVE_CHILD_e;
}

/*
 * System reset for atomic system:
 *    '<S71>/Z_Motion_State'
 *    '<S25>/Z_Motion_State'
 */
void FMS_Z_Motion_State_Reset(DW_Z_Motion_State_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c8_FMS = 0U;
  localDW->is_c8_FMS = FMS_IN_NO_ACTIVE_CHILD_e;
}

/*
 * Output and update for atomic system:
 *    '<S71>/Z_Motion_State'
 *    '<S25>/Z_Motion_State'
 */
void FMS_Z_Motion_State(boolean_T rtu_move_cmd, real32_T rtu_speed, real_T
  *rty_state, DW_Z_Motion_State_FMS_T *localDW)
{
  /* Chart: '<S71>/Z_Motion_State' */
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

  /* End of Chart: '<S71>/Z_Motion_State' */
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
  real32_T rtb_TrigoFcn;
  real32_T rtb_stick_roll_raw;
  real32_T rtb_stick_pitch_raw;
  real32_T rtb_MatrixConcatenate3[9];
  real32_T rtb_TrigoFcn1;
  real32_T rtb_MatrixConcatenate3_p[3];
  boolean_T rtb_LogicalOperator1;
  uint16_T rtb_Multiply_ox[16];
  uint8_T rtb_Compare;
  int8_T rtPrevAction;
  int32_T rtb_state_b1;
  real32_T rtb_Add_c;
  real_T rtb_state_e;
  boolean_T rtb_Compare_f;
  boolean_T rtb_Compare_o;
  real32_T rtb_Add_a;
  real32_T rtb_Add_k;
  int32_T i;
  real32_T rtb_Product_idx_0;
  real32_T rtb_Product_idx_1;
  real32_T rtb_Product_idx_2;
  real32_T rtb_MatrixConcatenate3_tmp;
  real32_T rtb_MatrixConcatenate3_tmp_0;
  real32_T rtb_MatrixConcatenate3_tmp_1;
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

  /* DeadZone: '<S94>/Dead Zone' */
  if (rtb_stick_throttle_raw > FMS_PARAM.StickDeadZone) {
    rtb_TrigoFcn = rtb_stick_throttle_raw - FMS_PARAM.StickDeadZone;
  } else if (rtb_stick_throttle_raw >= -FMS_PARAM.StickDeadZone) {
    rtb_TrigoFcn = 0.0F;
  } else {
    rtb_TrigoFcn = rtb_stick_throttle_raw - (-FMS_PARAM.StickDeadZone);
  }

  /* End of DeadZone: '<S94>/Dead Zone' */

  /* Signum: '<S94>/Sign' */
  if (rtb_TrigoFcn < 0.0F) {
    rtb_Add_a = -1.0F;
  } else if (rtb_TrigoFcn > 0.0F) {
    rtb_Add_a = 1.0F;
  } else {
    rtb_Add_a = rtb_TrigoFcn;
  }

  /* End of Signum: '<S94>/Sign' */

  /* Sum: '<S94>/Add' incorporates:
   *  Constant: '<S94>/Constant'
   *  Product: '<S94>/Multiply'
   */
  rtb_Add_c = rtb_Add_a * FMS_PARAM.StickDeadZone + rtb_TrigoFcn;

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

  /* DeadZone: '<S95>/Dead Zone' */
  if (rtb_stick_roll_raw > FMS_PARAM.StickDeadZone) {
    rtb_TrigoFcn = rtb_stick_roll_raw - FMS_PARAM.StickDeadZone;
  } else if (rtb_stick_roll_raw >= -FMS_PARAM.StickDeadZone) {
    rtb_TrigoFcn = 0.0F;
  } else {
    rtb_TrigoFcn = rtb_stick_roll_raw - (-FMS_PARAM.StickDeadZone);
  }

  /* End of DeadZone: '<S95>/Dead Zone' */

  /* Signum: '<S95>/Sign' */
  if (rtb_TrigoFcn < 0.0F) {
    rtb_Add_a = -1.0F;
  } else if (rtb_TrigoFcn > 0.0F) {
    rtb_Add_a = 1.0F;
  } else {
    rtb_Add_a = rtb_TrigoFcn;
  }

  /* End of Signum: '<S95>/Sign' */

  /* Sum: '<S95>/Add' incorporates:
   *  Constant: '<S95>/Constant'
   *  Product: '<S95>/Multiply'
   */
  rtb_Add_k = rtb_Add_a * FMS_PARAM.StickDeadZone + rtb_TrigoFcn;

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

  /* DeadZone: '<S96>/Dead Zone' */
  if (rtb_stick_pitch_raw > FMS_PARAM.StickDeadZone) {
    rtb_TrigoFcn = rtb_stick_pitch_raw - FMS_PARAM.StickDeadZone;
  } else if (rtb_stick_pitch_raw >= -FMS_PARAM.StickDeadZone) {
    rtb_TrigoFcn = 0.0F;
  } else {
    rtb_TrigoFcn = rtb_stick_pitch_raw - (-FMS_PARAM.StickDeadZone);
  }

  /* End of DeadZone: '<S96>/Dead Zone' */

  /* Signum: '<S96>/Sign' */
  if (rtb_TrigoFcn < 0.0F) {
    rtb_Add_a = -1.0F;
  } else if (rtb_TrigoFcn > 0.0F) {
    rtb_Add_a = 1.0F;
  } else {
    rtb_Add_a = rtb_TrigoFcn;
  }

  /* End of Signum: '<S96>/Sign' */

  /* Sum: '<S96>/Add' incorporates:
   *  Constant: '<S96>/Constant'
   *  Product: '<S96>/Multiply'
   */
  rtb_Add_a = rtb_Add_a * FMS_PARAM.StickDeadZone + rtb_TrigoFcn;

  /* Chart: '<S98>/Arm_Event' */
  if (FMS_DW.is_active_c3_FMS == 0U) {
    FMS_DW.is_active_c3_FMS = 1U;
    FMS_DW.is_c3_FMS = FMS_IN_Idle;
    FMS_B.arm_event = 0.0;
  } else {
    switch (FMS_DW.is_c3_FMS) {
     case FMS_IN_Idle:
      FMS_B.arm_event = 0.0;
      if ((rtb_Add_c < -0.8) && (rtb_Add_k < -0.8) && (rtb_Add_a < -0.8)) {
        FMS_DW.is_c3_FMS = FMS_IN_ready;
      }
      break;

     case FMS_IN_arm_event:
      FMS_DW.is_c3_FMS = FMS_IN_Idle;
      FMS_B.arm_event = 0.0;
      break;

     default:
      if ((fabsf(rtb_Add_k) < 0.15) && (fabsf(rtb_Add_a) < 0.15)) {
        FMS_DW.is_c3_FMS = FMS_IN_arm_event;
        FMS_B.arm_event = 1.0;
      }
      break;
    }
  }

  /* End of Chart: '<S98>/Arm_Event' */

  /* Product: '<S109>/Product' incorporates:
   *  Inport: '<Root>/INS_Output'
   */
  rtb_Product_idx_0 = FMS_U.INS_Output.quat[0] * FMS_U.INS_Output.quat[0];
  rtb_Product_idx_1 = FMS_U.INS_Output.quat[1] * FMS_U.INS_Output.quat[1];
  rtb_Product_idx_2 = FMS_U.INS_Output.quat[2] * FMS_U.INS_Output.quat[2];
  rtb_TrigoFcn = FMS_U.INS_Output.quat[3] * FMS_U.INS_Output.quat[3];

  /* Sum: '<S109>/Add' */
  rtb_MatrixConcatenate3[0] = ((rtb_Product_idx_0 + rtb_Product_idx_1) -
    rtb_Product_idx_2) - rtb_TrigoFcn;

  /* Product: '<S109>/Product1' incorporates:
   *  Inport: '<Root>/INS_Output'
   *  Product: '<S109>/Product5'
   */
  rtb_TrigoFcn1 = FMS_U.INS_Output.quat[1] * FMS_U.INS_Output.quat[2];

  /* Product: '<S109>/Product2' incorporates:
   *  Inport: '<Root>/INS_Output'
   *  Product: '<S109>/Product6'
   */
  rtb_MatrixConcatenate3_tmp = FMS_U.INS_Output.quat[0] * FMS_U.INS_Output.quat
    [3];

  /* Gain: '<S109>/Gain' incorporates:
   *  Product: '<S109>/Product1'
   *  Product: '<S109>/Product2'
   *  Sum: '<S109>/Add1'
   */
  rtb_MatrixConcatenate3[1] = (rtb_TrigoFcn1 + rtb_MatrixConcatenate3_tmp) *
    2.0F;

  /* Product: '<S109>/Product3' incorporates:
   *  Inport: '<Root>/INS_Output'
   *  Product: '<S109>/Product9'
   */
  rtb_MatrixConcatenate3_tmp_0 = FMS_U.INS_Output.quat[1] *
    FMS_U.INS_Output.quat[3];

  /* Product: '<S109>/Product4' incorporates:
   *  Inport: '<Root>/INS_Output'
   *  Product: '<S109>/Product10'
   */
  rtb_MatrixConcatenate3_tmp_1 = FMS_U.INS_Output.quat[0] *
    FMS_U.INS_Output.quat[2];

  /* Gain: '<S109>/Gain1' incorporates:
   *  Product: '<S109>/Product3'
   *  Product: '<S109>/Product4'
   *  Sum: '<S109>/Add2'
   */
  rtb_MatrixConcatenate3[2] = (rtb_MatrixConcatenate3_tmp_0 -
    rtb_MatrixConcatenate3_tmp_1) * 2.0F;

  /* Gain: '<S109>/Gain2' incorporates:
   *  Sum: '<S109>/Add3'
   */
  rtb_MatrixConcatenate3[3] = (rtb_TrigoFcn1 - rtb_MatrixConcatenate3_tmp) *
    2.0F;

  /* Sum: '<S109>/Add5' incorporates:
   *  Sum: '<S109>/Add8'
   */
  rtb_TrigoFcn1 = rtb_Product_idx_0 - rtb_Product_idx_1;
  rtb_MatrixConcatenate3[4] = (rtb_TrigoFcn1 + rtb_Product_idx_2) - rtb_TrigoFcn;

  /* Product: '<S109>/Product7' incorporates:
   *  Inport: '<Root>/INS_Output'
   *  Product: '<S109>/Product12'
   */
  rtb_MatrixConcatenate3_tmp = FMS_U.INS_Output.quat[2] * FMS_U.INS_Output.quat
    [3];

  /* Product: '<S109>/Product8' incorporates:
   *  Inport: '<Root>/INS_Output'
   *  Product: '<S109>/Product11'
   */
  rtb_Product_idx_0 = FMS_U.INS_Output.quat[0] * FMS_U.INS_Output.quat[1];

  /* Gain: '<S109>/Gain3' incorporates:
   *  Product: '<S109>/Product7'
   *  Product: '<S109>/Product8'
   *  Sum: '<S109>/Add4'
   */
  rtb_MatrixConcatenate3[5] = (rtb_MatrixConcatenate3_tmp + rtb_Product_idx_0) *
    2.0F;

  /* Gain: '<S109>/Gain4' incorporates:
   *  Sum: '<S109>/Add6'
   */
  rtb_MatrixConcatenate3[6] = (rtb_MatrixConcatenate3_tmp_0 +
    rtb_MatrixConcatenate3_tmp_1) * 2.0F;

  /* Gain: '<S109>/Gain5' incorporates:
   *  Sum: '<S109>/Add7'
   */
  rtb_MatrixConcatenate3[7] = (rtb_MatrixConcatenate3_tmp - rtb_Product_idx_0) *
    2.0F;

  /* Sum: '<S109>/Add8' */
  rtb_MatrixConcatenate3[8] = (rtb_TrigoFcn1 - rtb_Product_idx_2) + rtb_TrigoFcn;

  /* Product: '<S106>/Multiply' incorporates:
   *  Inport: '<Root>/INS_Output'
   *  SignalConversion: '<S106>/ConcatBufferAtMatrix Concatenate3In1'
   *  SignalConversion: '<S106>/ConcatBufferAtMatrix Concatenate3In2'
   *  SignalConversion: '<S106>/ConcatBufferAtMatrix Concatenate3In3'
   */
  for (i = 0; i < 3; i++) {
    rtb_MatrixConcatenate3_p[i] = rtb_MatrixConcatenate3[i + 6] *
      FMS_U.INS_Output.az + (rtb_MatrixConcatenate3[i + 3] * FMS_U.INS_Output.ay
      + rtb_MatrixConcatenate3[i] * FMS_U.INS_Output.ax);
  }

  /* End of Product: '<S106>/Multiply' */

  /* Logic: '<S106>/Logical Operator1' incorporates:
   *  Constant: '<S107>/Constant'
   *  Constant: '<S108>/Lower Limit'
   *  Constant: '<S108>/Upper Limit'
   *  Inport: '<Root>/Control_Out'
   *  Logic: '<S108>/AND'
   *  Product: '<S106>/Divide'
   *  RelationalOperator: '<S107>/Compare'
   *  RelationalOperator: '<S108>/Lower Test'
   *  RelationalOperator: '<S108>/Upper Test'
   *  Sum: '<S106>/Sum of Elements'
   */
  rtb_LogicalOperator1 = ((-10.806F <= rtb_MatrixConcatenate3_p[2]) &&
    (rtb_MatrixConcatenate3_p[2] <= -8.806F) && ((int32_T)((uint32_T)(uint16_T)
    ((((uint32_T)FMS_U.Control_Out.actuator_cmd[0] +
       FMS_U.Control_Out.actuator_cmd[1]) + FMS_U.Control_Out.actuator_cmd[2]) +
     FMS_U.Control_Out.actuator_cmd[3]) >> 2) < 1200));

  /* Chart: '<S98>/Disarm_Event' incorporates:
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

  /* End of Chart: '<S98>/Disarm_Event' */

  /* Chart: '<S3>/State_Logic' */
  if (FMS_DW.temporalCounter_i1 < 8191U) {
    FMS_DW.temporalCounter_i1++;
  }

  if (FMS_DW.is_active_c4_FMS == 0U) {
    FMS_DW.is_active_c4_FMS = 1U;
    FMS_DW.is_Arm_Logic = FMS_IN_Disarm_a;
    FMS_DW.Delay_DSTATE_pi = 0U;
    FMS_B.PWM_Cmd = 1000U;
  } else {
    guard1 = false;
    switch (FMS_DW.is_Arm_Logic) {
     case FMS_IN_Arm:
      FMS_DW.Delay_DSTATE_pi = 2U;
      if ((FMS_B.disarm_event == 1.0) && FMS_ConstB.Disarm_Allowed_Logical_Oper)
      {
        FMS_DW.is_Arm_Logic = FMS_IN_Disarm_a;
        FMS_DW.Delay_DSTATE_pi = 0U;
        FMS_B.PWM_Cmd = 1000U;
      }
      break;

     case FMS_IN_Disarm_a:
      FMS_DW.Delay_DSTATE_pi = 0U;
      FMS_B.PWM_Cmd = 1000U;
      if ((FMS_B.arm_event == 1.0) && FMS_ConstB.Arm_Allowed_Logical_Operato) {
        FMS_DW.is_Arm_Logic = FMS_IN_Standby;
        FMS_DW.temporalCounter_i1 = 0U;
        FMS_DW.Delay_DSTATE_pi = 1U;
        FMS_B.PWM_Cmd = 1200U;
      }
      break;

     default:
      FMS_DW.Delay_DSTATE_pi = 1U;
      FMS_B.PWM_Cmd = 1200U;
      if (FMS_DW.temporalCounter_i1 >= 7500U) {
        guard1 = true;
      } else if (rtb_Add_c > 0.6) {
        FMS_DW.is_Arm_Logic = FMS_IN_Arm;
        FMS_DW.Delay_DSTATE_pi = 2U;
      } else {
        if (FMS_B.arm_event == 1.0) {
          guard1 = true;
        }
      }
      break;
    }

    if (guard1) {
      FMS_DW.is_Arm_Logic = FMS_IN_Disarm_a;
      FMS_DW.Delay_DSTATE_pi = 0U;
      FMS_B.PWM_Cmd = 1000U;
    }
  }

  /* End of Chart: '<S3>/State_Logic' */

  /* Product: '<S102>/Multiply' */
  for (i = 0; i < 16; i++) {
    rtb_Multiply_ox[i] = FMS_B.PWM_Cmd;
  }

  /* End of Product: '<S102>/Multiply' */

  /* RelationalOperator: '<S100>/Compare' incorporates:
   *  Constant: '<S100>/Constant'
   */
  rtb_Compare = (uint8_T)(FMS_DW.Delay_DSTATE_pi < 2);

  /* Saturate: '<S2>/Saturation' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   */
  if (FMS_U.Pilot_Cmd.ls_lr > 1.0F) {
    rtb_TrigoFcn1 = 1.0F;
  } else if (FMS_U.Pilot_Cmd.ls_lr < -1.0F) {
    rtb_TrigoFcn1 = -1.0F;
  } else {
    rtb_TrigoFcn1 = FMS_U.Pilot_Cmd.ls_lr;
  }

  /* End of Saturate: '<S2>/Saturation' */

  /* DeadZone: '<S93>/Dead Zone' */
  if (rtb_TrigoFcn1 > FMS_PARAM.StickDeadZone) {
    rtb_TrigoFcn1 -= FMS_PARAM.StickDeadZone;
  } else if (rtb_TrigoFcn1 >= -FMS_PARAM.StickDeadZone) {
    rtb_TrigoFcn1 = 0.0F;
  } else {
    rtb_TrigoFcn1 -= -FMS_PARAM.StickDeadZone;
  }

  /* End of DeadZone: '<S93>/Dead Zone' */

  /* Signum: '<S93>/Sign' */
  if (rtb_TrigoFcn1 < 0.0F) {
    rtb_Product_idx_2 = -1.0F;
  } else if (rtb_TrigoFcn1 > 0.0F) {
    rtb_Product_idx_2 = 1.0F;
  } else {
    rtb_Product_idx_2 = rtb_TrigoFcn1;
  }

  /* End of Signum: '<S93>/Sign' */

  /* Sum: '<S93>/Add' incorporates:
   *  Constant: '<S93>/Constant'
   *  Product: '<S93>/Multiply'
   */
  rtb_Product_idx_2 = rtb_Product_idx_2 * FMS_PARAM.StickDeadZone +
    rtb_TrigoFcn1;

  /* Trigonometry: '<S97>/TrigoFcn1' incorporates:
   *  Inport: '<Root>/INS_Output'
   */
  rtb_TrigoFcn1 = arm_cos_f32(FMS_U.INS_Output.psi);

  /* SignalConversion: '<S97>/ConcatBufferAtVecConcentateIn1' */
  rtb_MatrixConcatenate3[0] = rtb_TrigoFcn1;

  /* Trigonometry: '<S97>/TrigoFcn' incorporates:
   *  Inport: '<Root>/INS_Output'
   */
  rtb_TrigoFcn = arm_sin_f32(FMS_U.INS_Output.psi);

  /* Gain: '<S97>/Gain' */
  rtb_MatrixConcatenate3[1] = -rtb_TrigoFcn;

  /* SignalConversion: '<S97>/ConcatBufferAtVecConcentateIn3' incorporates:
   *  Constant: '<S97>/Constant1'
   */
  rtb_MatrixConcatenate3[2] = 0.0F;

  /* SignalConversion: '<S97>/ConcatBufferAtVecConcentate2In1' */
  rtb_MatrixConcatenate3[3] = rtb_TrigoFcn;

  /* SignalConversion: '<S97>/ConcatBufferAtVecConcentate2In2' */
  rtb_MatrixConcatenate3[4] = rtb_TrigoFcn1;

  /* SignalConversion: '<S97>/ConcatBufferAtVecConcentate2In3' incorporates:
   *  Constant: '<S97>/Constant1'
   */
  rtb_MatrixConcatenate3[5] = 0.0F;

  /* SignalConversion: '<S97>/ConcatBufferAtVecConcentate1In3' */
  rtb_MatrixConcatenate3[6] = FMS_ConstB.VecConcentate3[0];
  rtb_MatrixConcatenate3[7] = FMS_ConstB.VecConcentate3[1];
  rtb_MatrixConcatenate3[8] = FMS_ConstB.VecConcentate3[2];

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

   default:
    FMS_DW.SwitchCase_ActiveSubsystem = 3;
    break;
  }

  switch (FMS_DW.SwitchCase_ActiveSubsystem) {
   case 0:
    if (FMS_DW.SwitchCase_ActiveSubsystem != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S1>/Position_Mode' incorporates:
       *  ActionPort: '<S7>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S1>/Switch Case' incorporates:
       *  Delay: '<S68>/Delay'
       *  Delay: '<S87>/Delay'
       *  Delay: '<S88>/Delay'
       *  UnitDelay: '<S60>/Delay Input1'
       *  UnitDelay: '<S85>/Delay Input1'
       *  UnitDelay: '<S86>/Delay Input1'
       *
       * Block description for '<S60>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S85>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S86>/Delay Input1':
       *
       *  Store in Global RAM
       */
      FMS_DW.DelayInput1_DSTATE_i = false;
      FMS_DW.icLoad_f = 1U;
      FMS_DW.DelayInput1_DSTATE_pv = false;
      FMS_DW.icLoad_a = 1U;
      FMS_DW.DelayInput1_DSTATE_c = false;
      FMS_DW.icLoad_o = 1U;

      /* End of InitializeConditions for SubSystem: '<S1>/Position_Mode' */

      /* SystemReset for IfAction SubSystem: '<S1>/Position_Mode' incorporates:
       *  ActionPort: '<S7>/Action Port'
       */
      /* SystemReset for SwitchCase: '<S1>/Switch Case' incorporates:
       *  Chart: '<S57>/Motion_State'
       *  Chart: '<S71>/XY_Motion_State'
       *  Chart: '<S71>/Z_Motion_State'
       */
      FMS_DW.temporalCounter_i1_b = 0U;
      FMS_DW.is_active_c7_FMS = 0U;
      FMS_DW.is_c7_FMS = FMS_IN_NO_ACTIVE_CHILD_h;
      FMS_Z_Motion_State_Reset(&FMS_DW.sf_Z_Motion_State);
      FMS_Motion_State_Reset(&FMS_DW.sf_Motion_State);

      /* End of SystemReset for SubSystem: '<S1>/Position_Mode' */
    }

    /* Outputs for IfAction SubSystem: '<S1>/Position_Mode' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    /* Logic: '<S74>/Logical Operator' incorporates:
     *  Constant: '<S91>/Constant'
     *  RelationalOperator: '<S91>/Compare'
     */
    rtb_LogicalOperator1 = ((rtb_Add_a != 0.0F) || (rtb_Add_k != 0.0F));

    /* Chart: '<S71>/XY_Motion_State' incorporates:
     *  Inport: '<Root>/INS_Output'
     *  Math: '<S73>/Math Function'
     *  Math: '<S73>/Math Function1'
     *  Sqrt: '<S73>/Sqrt'
     *  Sum: '<S73>/Add'
     */
    if (FMS_DW.temporalCounter_i1_b < 511U) {
      FMS_DW.temporalCounter_i1_b++;
    }

    if (FMS_DW.is_active_c7_FMS == 0U) {
      FMS_DW.is_active_c7_FMS = 1U;
      FMS_DW.is_c7_FMS = FMS_IN_Move_j;
      rtb_state_b1 = 0;
    } else {
      switch (FMS_DW.is_c7_FMS) {
       case FMS_IN_Brake_hi:
        rtb_state_b1 = 1;
        if ((sqrtf(FMS_U.INS_Output.vn * FMS_U.INS_Output.vn +
                   FMS_U.INS_Output.ve * FMS_U.INS_Output.ve) <= 0.2) ||
            (FMS_DW.temporalCounter_i1_b >= 313U)) {
          FMS_DW.is_c7_FMS = FMS_IN_Hold_n;
          rtb_state_b1 = 2;
        } else {
          if (rtb_LogicalOperator1) {
            FMS_DW.is_c7_FMS = FMS_IN_Move_j;
            rtb_state_b1 = 0;
          }
        }
        break;

       case FMS_IN_Hold_n:
        rtb_state_b1 = 2;
        if (rtb_LogicalOperator1) {
          FMS_DW.is_c7_FMS = FMS_IN_Move_j;
          rtb_state_b1 = 0;
        }
        break;

       default:
        rtb_state_b1 = 0;
        if (!rtb_LogicalOperator1) {
          FMS_DW.is_c7_FMS = FMS_IN_Brake_hi;
          FMS_DW.temporalCounter_i1_b = 0U;
          rtb_state_b1 = 1;
        }
        break;
      }
    }

    /* End of Chart: '<S71>/XY_Motion_State' */

    /* RelationalOperator: '<S83>/Compare' incorporates:
     *  Constant: '<S83>/Constant'
     */
    rtb_LogicalOperator1 = (rtb_state_b1 == 2);

    /* Delay: '<S87>/Delay' incorporates:
     *  Inport: '<Root>/INS_Output'
     *  SignalConversion: '<S87>/TmpSignal ConversionAtDelayInport2'
     */
    if (FMS_DW.icLoad_f != 0) {
      FMS_DW.Delay_DSTATE_pp[0] = FMS_U.INS_Output.x_R;
      FMS_DW.Delay_DSTATE_pp[1] = FMS_U.INS_Output.y_R;
    }

    /* End of Delay: '<S87>/Delay' */

    /* Switch: '<S87>/Switch1' incorporates:
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S85>/FixPt Relational Operator'
     *  SignalConversion: '<S87>/TmpSignal ConversionAtDelayInport2'
     *  UnitDelay: '<S85>/Delay Input1'
     *
     * Block description for '<S85>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if ((int32_T)rtb_LogicalOperator1 > (int32_T)FMS_DW.DelayInput1_DSTATE_i) {
      FMS_DW.Delay_DSTATE_pp[0] = FMS_U.INS_Output.x_R;
      FMS_DW.Delay_DSTATE_pp[1] = FMS_U.INS_Output.y_R;
    }

    /* End of Switch: '<S87>/Switch1' */

    /* Chart: '<S71>/Z_Motion_State' incorporates:
     *  Constant: '<S92>/Constant'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S92>/Compare'
     */
    FMS_Z_Motion_State(rtb_Add_c != 0.0F, FMS_U.INS_Output.vd, &rtb_state_e,
                       &FMS_DW.sf_Z_Motion_State);

    /* RelationalOperator: '<S84>/Compare' incorporates:
     *  Constant: '<S84>/Constant'
     */
    rtb_Compare_f = (rtb_state_e == 2.0);

    /* Delay: '<S88>/Delay' incorporates:
     *  Gain: '<S82>/Gain'
     *  Inport: '<Root>/INS_Output'
     */
    if (FMS_DW.icLoad_a != 0) {
      FMS_DW.Delay_DSTATE_n = -FMS_U.INS_Output.h_R;
    }

    /* End of Delay: '<S88>/Delay' */

    /* Switch: '<S88>/Switch1' incorporates:
     *  Gain: '<S82>/Gain'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S86>/FixPt Relational Operator'
     *  UnitDelay: '<S86>/Delay Input1'
     *
     * Block description for '<S86>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if ((int32_T)rtb_Compare_f > (int32_T)FMS_DW.DelayInput1_DSTATE_pv) {
      FMS_DW.Delay_DSTATE_n = -FMS_U.INS_Output.h_R;
    }

    /* End of Switch: '<S88>/Switch1' */

    /* Sum: '<S81>/Sum' incorporates:
     *  Gain: '<S82>/Gain'
     *  Inport: '<Root>/INS_Output'
     */
    rtb_stick_roll_raw = FMS_DW.Delay_DSTATE_pp[0] - FMS_U.INS_Output.x_R;
    rtb_stick_pitch_raw = FMS_DW.Delay_DSTATE_pp[1] - FMS_U.INS_Output.y_R;
    rtb_stick_throttle_raw = FMS_DW.Delay_DSTATE_n - (-FMS_U.INS_Output.h_R);

    /* Product: '<S81>/Multiply' */
    for (i = 0; i < 3; i++) {
      rtb_MatrixConcatenate3_p[i] = rtb_MatrixConcatenate3[i + 6] *
        rtb_stick_throttle_raw + (rtb_MatrixConcatenate3[i + 3] *
        rtb_stick_pitch_raw + rtb_MatrixConcatenate3[i] * rtb_stick_roll_raw);
    }

    /* End of Product: '<S81>/Multiply' */

    /* Switch: '<S72>/Switch' incorporates:
     *  Constant: '<S77>/Constant'
     *  Constant: '<S89>/Constant'
     *  Gain: '<S79>/Gain2'
     *  RelationalOperator: '<S77>/Compare'
     *  RelationalOperator: '<S89>/Compare'
     *  Switch: '<S80>/Switch1'
     */
    if (rtb_state_b1 == 2) {
      rtb_stick_roll_raw = FMS_PARAM.XY_P * rtb_MatrixConcatenate3_p[0];
      rtb_Add_k = FMS_PARAM.XY_P * rtb_MatrixConcatenate3_p[1];
    } else if (rtb_state_b1 == 1) {
      /* Switch: '<S80>/Switch1' */
      rtb_stick_roll_raw = 0.0F;
      rtb_Add_k = 0.0F;
    } else {
      /* Switch: '<S80>/Switch1' incorporates:
       *  Gain: '<S80>/Gain1'
       *  Gain: '<S80>/Gain5'
       */
      rtb_stick_roll_raw = FMS_PARAM.VEL_XY_LIM * rtb_Add_a;
      rtb_Add_k *= FMS_PARAM.VEL_XY_LIM;
    }

    /* End of Switch: '<S72>/Switch' */

    /* Outport: '<Root>/FMS_Output' incorporates:
     *  Saturate: '<S72>/Saturation'
     */
    FMS_Y.FMS_Output.u_cmd = rtb_stick_roll_raw;

    /* Saturate: '<S72>/Saturation' */
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
     *  Saturate: '<S72>/Saturation'
     */
    FMS_Y.FMS_Output.v_cmd = rtb_Add_k;

    /* Saturate: '<S72>/Saturation' */
    if (rtb_Add_k > FMS_PARAM.VEL_XY_LIM) {
      /* Outport: '<Root>/FMS_Output' */
      FMS_Y.FMS_Output.v_cmd = FMS_PARAM.VEL_XY_LIM;
    } else {
      if (rtb_Add_k < -FMS_PARAM.VEL_XY_LIM) {
        /* Outport: '<Root>/FMS_Output' */
        FMS_Y.FMS_Output.v_cmd = -FMS_PARAM.VEL_XY_LIM;
      }
    }

    /* Switch: '<S72>/Switch1' incorporates:
     *  Constant: '<S78>/Constant'
     *  Constant: '<S90>/Constant'
     *  Gain: '<S79>/Gain4'
     *  RelationalOperator: '<S78>/Compare'
     *  RelationalOperator: '<S90>/Compare'
     *  Switch: '<S80>/Switch2'
     */
    if (rtb_state_e == 2.0) {
      rtb_Add_c = FMS_PARAM.Z_P * rtb_MatrixConcatenate3_p[2];
    } else if (rtb_state_e == 1.0) {
      /* Switch: '<S80>/Switch2' incorporates:
       *  Constant: '<S80>/Constant1'
       */
      rtb_Add_c = 0.0F;
    } else {
      /* Switch: '<S80>/Switch2' incorporates:
       *  Gain: '<S80>/Gain6'
       */
      rtb_Add_c *= -FMS_PARAM.VEL_Z_LIM;
    }

    /* End of Switch: '<S72>/Switch1' */

    /* Saturate: '<S72>/Saturation1' */
    if (rtb_Add_c > FMS_PARAM.VEL_Z_LIM) {
      /* Outport: '<Root>/FMS_Output' */
      FMS_Y.FMS_Output.w_cmd = FMS_PARAM.VEL_Z_LIM;
    } else if (rtb_Add_c < -FMS_PARAM.VEL_Z_LIM) {
      /* Outport: '<Root>/FMS_Output' */
      FMS_Y.FMS_Output.w_cmd = -FMS_PARAM.VEL_Z_LIM;
    } else {
      /* Outport: '<Root>/FMS_Output' */
      FMS_Y.FMS_Output.w_cmd = rtb_Add_c;
    }

    /* End of Saturate: '<S72>/Saturation1' */

    /* Chart: '<S57>/Motion_State' incorporates:
     *  Abs: '<S65>/Abs'
     *  Constant: '<S70>/Constant'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S70>/Compare'
     */
    FMS_Motion_State(rtb_Product_idx_2 != 0.0F, fabsf(FMS_U.INS_Output.r),
                     &rtb_state_e, &FMS_DW.sf_Motion_State);

    /* RelationalOperator: '<S59>/Compare' incorporates:
     *  Constant: '<S59>/Constant'
     */
    rtb_Compare_o = (rtb_state_e == 2.0);

    /* Delay: '<S68>/Delay' incorporates:
     *  Inport: '<Root>/INS_Output'
     */
    if (FMS_DW.icLoad_o != 0) {
      FMS_DW.Delay_DSTATE_c = FMS_U.INS_Output.psi;
    }

    /* End of Delay: '<S68>/Delay' */

    /* Switch: '<S68>/Switch1' incorporates:
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S60>/FixPt Relational Operator'
     *  UnitDelay: '<S60>/Delay Input1'
     *
     * Block description for '<S60>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if ((int32_T)rtb_Compare_o > (int32_T)FMS_DW.DelayInput1_DSTATE_c) {
      FMS_DW.Delay_DSTATE_c = FMS_U.INS_Output.psi;
    }

    /* End of Switch: '<S68>/Switch1' */

    /* Switch: '<S57>/Switch' incorporates:
     *  Constant: '<S69>/Constant'
     *  Gain: '<S61>/Gain2'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S69>/Compare'
     *  Sum: '<S66>/Sum'
     *  Switch: '<S62>/Switch1'
     */
    if (rtb_Compare_o) {
      rtb_Add_c = (FMS_DW.Delay_DSTATE_c - FMS_U.INS_Output.psi) *
        FMS_PARAM.YAW_P;
    } else if (rtb_state_e == 1.0) {
      /* Switch: '<S62>/Switch1' incorporates:
       *  Constant: '<S62>/Constant'
       */
      rtb_Add_c = 0.0F;
    } else {
      /* Switch: '<S62>/Switch1' incorporates:
       *  Gain: '<S62>/Gain1'
       */
      rtb_Add_c = FMS_PARAM.YAW_RATE_LIM * rtb_Product_idx_2;
    }

    /* End of Switch: '<S57>/Switch' */

    /* Saturate: '<S57>/Saturation1' */
    if (rtb_Add_c > FMS_PARAM.YAW_RATE_LIM) {
      /* Outport: '<Root>/FMS_Output' */
      FMS_Y.FMS_Output.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
    } else if (rtb_Add_c < -FMS_PARAM.YAW_RATE_LIM) {
      /* Outport: '<Root>/FMS_Output' */
      FMS_Y.FMS_Output.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
    } else {
      /* Outport: '<Root>/FMS_Output' */
      FMS_Y.FMS_Output.psi_rate_cmd = rtb_Add_c;
    }

    /* End of Saturate: '<S57>/Saturation1' */

    /* Outport: '<Root>/FMS_Output' incorporates:
     *  BusAssignment: '<S3>/Bus Assignment'
     *  BusAssignment: '<S7>/Bus Assignment'
     *  Constant: '<S7>/Constant'
     *  DiscreteIntegrator: '<S103>/Discrete-Time Integrator'
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

    /* Update for UnitDelay: '<S85>/Delay Input1'
     *
     * Block description for '<S85>/Delay Input1':
     *
     *  Store in Global RAM
     */
    FMS_DW.DelayInput1_DSTATE_i = rtb_LogicalOperator1;

    /* Update for Delay: '<S87>/Delay' */
    FMS_DW.icLoad_f = 0U;

    /* Update for UnitDelay: '<S86>/Delay Input1'
     *
     * Block description for '<S86>/Delay Input1':
     *
     *  Store in Global RAM
     */
    FMS_DW.DelayInput1_DSTATE_pv = rtb_Compare_f;

    /* Update for Delay: '<S88>/Delay' */
    FMS_DW.icLoad_a = 0U;

    /* Update for UnitDelay: '<S60>/Delay Input1'
     *
     * Block description for '<S60>/Delay Input1':
     *
     *  Store in Global RAM
     */
    FMS_DW.DelayInput1_DSTATE_c = rtb_Compare_o;

    /* Update for Delay: '<S68>/Delay' */
    FMS_DW.icLoad_o = 0U;

    /* End of Outputs for SubSystem: '<S1>/Position_Mode' */
    break;

   case 1:
    if (FMS_DW.SwitchCase_ActiveSubsystem != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S1>/Altitude_Hold_Mode' incorporates:
       *  ActionPort: '<S4>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S1>/Switch Case' incorporates:
       *  Delay: '<S22>/Delay'
       *  Delay: '<S37>/Delay'
       *  UnitDelay: '<S14>/Delay Input1'
       *  UnitDelay: '<S36>/Delay Input1'
       *
       * Block description for '<S14>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S36>/Delay Input1':
       *
       *  Store in Global RAM
       */
      FMS_DW.DelayInput1_DSTATE_a = false;
      FMS_DW.icLoad_d = 1U;
      FMS_DW.DelayInput1_DSTATE_p = false;
      FMS_DW.icLoad_i = 1U;

      /* End of InitializeConditions for SubSystem: '<S1>/Altitude_Hold_Mode' */

      /* SystemReset for IfAction SubSystem: '<S1>/Altitude_Hold_Mode' incorporates:
       *  ActionPort: '<S4>/Action Port'
       */
      /* SystemReset for SwitchCase: '<S1>/Switch Case' incorporates:
       *  Chart: '<S11>/Motion_State'
       *  Chart: '<S25>/Z_Motion_State'
       */
      FMS_Z_Motion_State_Reset(&FMS_DW.sf_Z_Motion_State_l);
      FMS_Motion_State_Reset(&FMS_DW.sf_Motion_State_c);

      /* End of SystemReset for SubSystem: '<S1>/Altitude_Hold_Mode' */
    }

    /* Outputs for IfAction SubSystem: '<S1>/Altitude_Hold_Mode' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* Chart: '<S25>/Z_Motion_State' incorporates:
     *  Constant: '<S39>/Constant'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S39>/Compare'
     */
    FMS_Z_Motion_State(rtb_Add_c != 0.0F, FMS_U.INS_Output.vd, &rtb_state_e,
                       &FMS_DW.sf_Z_Motion_State_l);

    /* RelationalOperator: '<S35>/Compare' incorporates:
     *  Constant: '<S35>/Constant'
     */
    rtb_LogicalOperator1 = (rtb_state_e == 2.0);

    /* Delay: '<S37>/Delay' incorporates:
     *  Gain: '<S34>/Gain'
     *  Inport: '<Root>/INS_Output'
     */
    if (FMS_DW.icLoad_d != 0) {
      FMS_DW.Delay_DSTATE_e = -FMS_U.INS_Output.h_R;
    }

    /* End of Delay: '<S37>/Delay' */

    /* Switch: '<S37>/Switch1' incorporates:
     *  Gain: '<S34>/Gain'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S36>/FixPt Relational Operator'
     *  UnitDelay: '<S36>/Delay Input1'
     *
     * Block description for '<S36>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if ((int32_T)rtb_LogicalOperator1 > (int32_T)FMS_DW.DelayInput1_DSTATE_a) {
      FMS_DW.Delay_DSTATE_e = -FMS_U.INS_Output.h_R;
    }

    /* End of Switch: '<S37>/Switch1' */

    /* Switch: '<S26>/Switch1' incorporates:
     *  Constant: '<S30>/Constant'
     *  Constant: '<S38>/Constant'
     *  Gain: '<S31>/Gain4'
     *  Gain: '<S34>/Gain'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S30>/Compare'
     *  RelationalOperator: '<S38>/Compare'
     *  Sum: '<S33>/Sum'
     *  Switch: '<S32>/Switch2'
     */
    if (rtb_state_e == 2.0) {
      rtb_Add_c = (FMS_DW.Delay_DSTATE_e - (-FMS_U.INS_Output.h_R)) *
        FMS_PARAM.Z_P;
    } else if (rtb_state_e == 1.0) {
      /* Switch: '<S32>/Switch2' incorporates:
       *  Constant: '<S32>/Constant1'
       */
      rtb_Add_c = 0.0F;
    } else {
      /* Switch: '<S32>/Switch2' incorporates:
       *  Gain: '<S32>/Gain6'
       */
      rtb_Add_c *= -FMS_PARAM.VEL_Z_LIM;
    }

    /* End of Switch: '<S26>/Switch1' */

    /* Saturate: '<S12>/Saturation' */
    if (rtb_Add_c > FMS_PARAM.VEL_Z_LIM) {
      /* Outport: '<Root>/FMS_Output' */
      FMS_Y.FMS_Output.w_cmd = FMS_PARAM.VEL_Z_LIM;
    } else if (rtb_Add_c < -FMS_PARAM.VEL_Z_LIM) {
      /* Outport: '<Root>/FMS_Output' */
      FMS_Y.FMS_Output.w_cmd = -FMS_PARAM.VEL_Z_LIM;
    } else {
      /* Outport: '<Root>/FMS_Output' */
      FMS_Y.FMS_Output.w_cmd = rtb_Add_c;
    }

    /* End of Saturate: '<S12>/Saturation' */

    /* Chart: '<S11>/Motion_State' incorporates:
     *  Abs: '<S19>/Abs'
     *  Constant: '<S24>/Constant'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S24>/Compare'
     */
    FMS_Motion_State(rtb_Product_idx_2 != 0.0F, fabsf(FMS_U.INS_Output.r),
                     &rtb_state_e, &FMS_DW.sf_Motion_State_c);

    /* RelationalOperator: '<S13>/Compare' incorporates:
     *  Constant: '<S13>/Constant'
     */
    rtb_Compare_f = (rtb_state_e == 2.0);

    /* Delay: '<S22>/Delay' incorporates:
     *  Inport: '<Root>/INS_Output'
     */
    if (FMS_DW.icLoad_i != 0) {
      FMS_DW.Delay_DSTATE_p = FMS_U.INS_Output.psi;
    }

    /* End of Delay: '<S22>/Delay' */

    /* Switch: '<S22>/Switch1' incorporates:
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S14>/FixPt Relational Operator'
     *  UnitDelay: '<S14>/Delay Input1'
     *
     * Block description for '<S14>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if ((int32_T)rtb_Compare_f > (int32_T)FMS_DW.DelayInput1_DSTATE_p) {
      FMS_DW.Delay_DSTATE_p = FMS_U.INS_Output.psi;
    }

    /* End of Switch: '<S22>/Switch1' */

    /* Switch: '<S11>/Switch' incorporates:
     *  Constant: '<S23>/Constant'
     *  Gain: '<S15>/Gain2'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S23>/Compare'
     *  Sum: '<S20>/Sum'
     *  Switch: '<S16>/Switch1'
     */
    if (rtb_Compare_f) {
      rtb_Add_c = (FMS_DW.Delay_DSTATE_p - FMS_U.INS_Output.psi) *
        FMS_PARAM.YAW_P;
    } else if (rtb_state_e == 1.0) {
      /* Switch: '<S16>/Switch1' incorporates:
       *  Constant: '<S16>/Constant'
       */
      rtb_Add_c = 0.0F;
    } else {
      /* Switch: '<S16>/Switch1' incorporates:
       *  Gain: '<S16>/Gain1'
       */
      rtb_Add_c = FMS_PARAM.YAW_RATE_LIM * rtb_Product_idx_2;
    }

    /* End of Switch: '<S11>/Switch' */

    /* Saturate: '<S11>/Saturation1' */
    if (rtb_Add_c > FMS_PARAM.YAW_RATE_LIM) {
      /* Outport: '<Root>/FMS_Output' */
      FMS_Y.FMS_Output.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
    } else if (rtb_Add_c < -FMS_PARAM.YAW_RATE_LIM) {
      /* Outport: '<Root>/FMS_Output' */
      FMS_Y.FMS_Output.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
    } else {
      /* Outport: '<Root>/FMS_Output' */
      FMS_Y.FMS_Output.psi_rate_cmd = rtb_Add_c;
    }

    /* End of Saturate: '<S11>/Saturation1' */

    /* Outport: '<Root>/FMS_Output' incorporates:
     *  BusAssignment: '<S3>/Bus Assignment'
     *  BusAssignment: '<S4>/Bus Assignment'
     *  Constant: '<S4>/Constant'
     *  DiscreteIntegrator: '<S103>/Discrete-Time Integrator'
     *  Gain: '<S10>/Gain'
     *  Gain: '<S10>/Gain1'
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

    /* Update for UnitDelay: '<S36>/Delay Input1'
     *
     * Block description for '<S36>/Delay Input1':
     *
     *  Store in Global RAM
     */
    FMS_DW.DelayInput1_DSTATE_a = rtb_LogicalOperator1;

    /* Update for Delay: '<S37>/Delay' */
    FMS_DW.icLoad_d = 0U;

    /* Update for UnitDelay: '<S14>/Delay Input1'
     *
     * Block description for '<S14>/Delay Input1':
     *
     *  Store in Global RAM
     */
    FMS_DW.DelayInput1_DSTATE_p = rtb_Compare_f;

    /* Update for Delay: '<S22>/Delay' */
    FMS_DW.icLoad_i = 0U;

    /* End of Outputs for SubSystem: '<S1>/Altitude_Hold_Mode' */
    break;

   case 2:
    if (FMS_DW.SwitchCase_ActiveSubsystem != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S1>/Manual_Mode' incorporates:
       *  ActionPort: '<S5>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S1>/Switch Case' incorporates:
       *  Delay: '<S53>/Delay'
       *  UnitDelay: '<S45>/Delay Input1'
       *
       * Block description for '<S45>/Delay Input1':
       *
       *  Store in Global RAM
       */
      FMS_DW.DelayInput1_DSTATE = false;
      FMS_DW.icLoad = 1U;

      /* End of InitializeConditions for SubSystem: '<S1>/Manual_Mode' */

      /* SystemReset for IfAction SubSystem: '<S1>/Manual_Mode' incorporates:
       *  ActionPort: '<S5>/Action Port'
       */
      /* SystemReset for SwitchCase: '<S1>/Switch Case' incorporates:
       *  Chart: '<S42>/Motion_State'
       */
      FMS_Motion_State_Reset(&FMS_DW.sf_Motion_State_j);

      /* End of SystemReset for SubSystem: '<S1>/Manual_Mode' */
    }

    /* Outputs for IfAction SubSystem: '<S1>/Manual_Mode' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* Chart: '<S42>/Motion_State' incorporates:
     *  Abs: '<S50>/Abs'
     *  Constant: '<S55>/Constant'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S55>/Compare'
     */
    FMS_Motion_State(rtb_Product_idx_2 != 0.0F, fabsf(FMS_U.INS_Output.r),
                     &rtb_state_e, &FMS_DW.sf_Motion_State_j);

    /* RelationalOperator: '<S44>/Compare' incorporates:
     *  Constant: '<S44>/Constant'
     */
    rtb_LogicalOperator1 = (rtb_state_e == 2.0);

    /* RelationalOperator: '<S45>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S45>/Delay Input1'
     *
     * Block description for '<S45>/Delay Input1':
     *
     *  Store in Global RAM
     */
    FMS_DW.DelayInput1_DSTATE = ((int32_T)rtb_LogicalOperator1 > (int32_T)
      FMS_DW.DelayInput1_DSTATE);

    /* Delay: '<S53>/Delay' incorporates:
     *  Inport: '<Root>/INS_Output'
     */
    if (FMS_DW.icLoad != 0) {
      FMS_DW.Delay_DSTATE = FMS_U.INS_Output.psi;
    }

    /* End of Delay: '<S53>/Delay' */

    /* Switch: '<S53>/Switch1' incorporates:
     *  Inport: '<Root>/INS_Output'
     *  UnitDelay: '<S45>/Delay Input1'
     *
     * Block description for '<S45>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if (FMS_DW.DelayInput1_DSTATE) {
      FMS_DW.Delay_DSTATE = FMS_U.INS_Output.psi;
    }

    /* End of Switch: '<S53>/Switch1' */

    /* Switch: '<S42>/Switch' incorporates:
     *  Constant: '<S54>/Constant'
     *  Gain: '<S46>/Gain2'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S54>/Compare'
     *  Sum: '<S51>/Sum'
     *  Switch: '<S47>/Switch1'
     */
    if (rtb_LogicalOperator1) {
      rtb_Add_c = (FMS_DW.Delay_DSTATE - FMS_U.INS_Output.psi) * FMS_PARAM.YAW_P;
    } else if (rtb_state_e == 1.0) {
      /* Switch: '<S47>/Switch1' incorporates:
       *  Constant: '<S47>/Constant'
       */
      rtb_Add_c = 0.0F;
    } else {
      /* Switch: '<S47>/Switch1' incorporates:
       *  Gain: '<S47>/Gain1'
       */
      rtb_Add_c = FMS_PARAM.YAW_RATE_LIM * rtb_Product_idx_2;
    }

    /* End of Switch: '<S42>/Switch' */

    /* Saturate: '<S42>/Saturation1' */
    if (rtb_Add_c > FMS_PARAM.YAW_RATE_LIM) {
      /* Outport: '<Root>/FMS_Output' */
      FMS_Y.FMS_Output.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
    } else if (rtb_Add_c < -FMS_PARAM.YAW_RATE_LIM) {
      /* Outport: '<Root>/FMS_Output' */
      FMS_Y.FMS_Output.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
    } else {
      /* Outport: '<Root>/FMS_Output' */
      FMS_Y.FMS_Output.psi_rate_cmd = rtb_Add_c;
    }

    /* End of Saturate: '<S42>/Saturation1' */

    /* Outport: '<Root>/FMS_Output' incorporates:
     *  BusAssignment: '<S3>/Bus Assignment'
     *  BusAssignment: '<S5>/Bus Assignment'
     *  Constant: '<S43>/Constant'
     *  Constant: '<S43>/Constant1'
     *  Constant: '<S5>/Constant'
     *  DiscreteIntegrator: '<S103>/Discrete-Time Integrator'
     *  Gain: '<S41>/Gain1'
     *  Gain: '<S41>/Gain2'
     *  Gain: '<S43>/Gain'
     *  SignalConversion: '<S3>/TmpHiddenBufferAtBus AssignmentInport1'
     *  Sum: '<S43>/Add'
     *  Sum: '<S43>/Sum'
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

    /* Update for UnitDelay: '<S45>/Delay Input1'
     *
     * Block description for '<S45>/Delay Input1':
     *
     *  Store in Global RAM
     */
    FMS_DW.DelayInput1_DSTATE = rtb_LogicalOperator1;

    /* Update for Delay: '<S53>/Delay' */
    FMS_DW.icLoad = 0U;

    /* End of Outputs for SubSystem: '<S1>/Manual_Mode' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S1>/Unknown_Mode' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Outport: '<Root>/FMS_Output' incorporates:
     *  BusAssignment: '<S3>/Bus Assignment'
     *  BusAssignment: '<S8>/Bus Assignment'
     *  Constant: '<S8>/Constant1'
     *  Constant: '<S8>/Constant2'
     *  DiscreteIntegrator: '<S103>/Discrete-Time Integrator'
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

  /* Update for DiscreteIntegrator: '<S103>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S103>/Constant'
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

  /* SystemInitialize for Chart: '<S98>/Arm_Event' */
  FMS_DW.is_active_c3_FMS = 0U;
  FMS_DW.is_c3_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for Chart: '<S98>/Disarm_Event' */
  FMS_DW.temporalCounter_i1_a = 0U;
  FMS_DW.is_active_c10_FMS = 0U;
  FMS_DW.is_c10_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for Chart: '<S3>/State_Logic' */
  FMS_DW.is_Arm_Logic = FMS_IN_NO_ACTIVE_CHILD_h;
  FMS_DW.temporalCounter_i1 = 0U;
  FMS_DW.is_active_c4_FMS = 0U;

  /* SystemInitialize for IfAction SubSystem: '<S1>/Position_Mode' */
  /* InitializeConditions for UnitDelay: '<S85>/Delay Input1'
   *
   * Block description for '<S85>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_i = false;

  /* InitializeConditions for Delay: '<S87>/Delay' */
  FMS_DW.icLoad_f = 1U;

  /* InitializeConditions for UnitDelay: '<S86>/Delay Input1'
   *
   * Block description for '<S86>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_pv = false;

  /* InitializeConditions for Delay: '<S88>/Delay' */
  FMS_DW.icLoad_a = 1U;

  /* InitializeConditions for UnitDelay: '<S60>/Delay Input1'
   *
   * Block description for '<S60>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_c = false;

  /* InitializeConditions for Delay: '<S68>/Delay' */
  FMS_DW.icLoad_o = 1U;

  /* SystemInitialize for Chart: '<S71>/XY_Motion_State' */
  FMS_DW.temporalCounter_i1_b = 0U;
  FMS_DW.is_active_c7_FMS = 0U;
  FMS_DW.is_c7_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for Chart: '<S71>/Z_Motion_State' */
  FMS_Z_Motion_State_Init(&FMS_DW.sf_Z_Motion_State);

  /* SystemInitialize for Chart: '<S57>/Motion_State' */
  FMS_Motion_State_Init(&FMS_DW.sf_Motion_State);

  /* End of SystemInitialize for SubSystem: '<S1>/Position_Mode' */

  /* SystemInitialize for IfAction SubSystem: '<S1>/Altitude_Hold_Mode' */
  /* InitializeConditions for UnitDelay: '<S36>/Delay Input1'
   *
   * Block description for '<S36>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_a = false;

  /* InitializeConditions for Delay: '<S37>/Delay' */
  FMS_DW.icLoad_d = 1U;

  /* InitializeConditions for UnitDelay: '<S14>/Delay Input1'
   *
   * Block description for '<S14>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_p = false;

  /* InitializeConditions for Delay: '<S22>/Delay' */
  FMS_DW.icLoad_i = 1U;

  /* SystemInitialize for Chart: '<S25>/Z_Motion_State' */
  FMS_Z_Motion_State_Init(&FMS_DW.sf_Z_Motion_State_l);

  /* SystemInitialize for Chart: '<S11>/Motion_State' */
  FMS_Motion_State_Init(&FMS_DW.sf_Motion_State_c);

  /* End of SystemInitialize for SubSystem: '<S1>/Altitude_Hold_Mode' */

  /* SystemInitialize for IfAction SubSystem: '<S1>/Manual_Mode' */
  /* InitializeConditions for UnitDelay: '<S45>/Delay Input1'
   *
   * Block description for '<S45>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE = false;

  /* InitializeConditions for Delay: '<S53>/Delay' */
  FMS_DW.icLoad = 1U;

  /* SystemInitialize for Chart: '<S42>/Motion_State' */
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
