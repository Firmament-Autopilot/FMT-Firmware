/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.622
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Aug 27 22:55:18 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S61>/Motion_State' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<S77>/Z_Motion_State' */
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

/* Named constants for Chart: '<S77>/XY_Motion_State' */
#define FMS_IN_Brake_hi                ((uint8_T)1U)
#define FMS_IN_Hold_n                  ((uint8_T)2U)
#define FMS_IN_Move_j                  ((uint8_T)3U)

/* Named constants for Chart: '<S106>/Arm_Event' */
#define FMS_IN_Idle                    ((uint8_T)1U)
#define FMS_IN_arm_event               ((uint8_T)2U)
#define FMS_IN_ready                   ((uint8_T)3U)

/* Named constants for Chart: '<S106>/Disarm_Event' */
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
  1.0F,
  1.2F,
  5.0F,
  2.5F,
  1.0F,
  1.04719758F,
  0.52359879F
} ;                                    /* Variable: FMS_PARAM
                                        * Referenced by:
                                        *   '<S100>/Constant'
                                        *   '<S100>/Dead Zone'
                                        *   '<S101>/Constant'
                                        *   '<S101>/Dead Zone'
                                        *   '<S102>/Constant'
                                        *   '<S102>/Dead Zone'
                                        *   '<S103>/Constant'
                                        *   '<S103>/Dead Zone'
                                        *   '<S10>/Gain'
                                        *   '<S10>/Gain1'
                                        *   '<S11>/Saturation1'
                                        *   '<S12>/Saturation'
                                        *   '<S43>/Gain1'
                                        *   '<S43>/Gain2'
                                        *   '<S44>/Saturation1'
                                        *   '<S61>/Saturation1'
                                        *   '<S17>/Gain2'
                                        *   '<S18>/Gain1'
                                        *   '<S50>/Gain2'
                                        *   '<S51>/Gain1'
                                        *   '<S67>/Gain2'
                                        *   '<S68>/Gain1'
                                        *   '<S78>/Saturation'
                                        *   '<S78>/Saturation1'
                                        *   '<S33>/Gain4'
                                        *   '<S34>/Gain6'
                                        *   '<S85>/Gain2'
                                        *   '<S85>/Gain4'
                                        *   '<S86>/Gain1'
                                        *   '<S86>/Gain5'
                                        *   '<S86>/Gain6'
                                        */

struct_4XfCoaAMTej5uH3d8u88xB FMS_EXPORT = {
  8U
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by: '<S111>/Constant'
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
 *    '<S61>/Motion_State'
 *    '<S11>/Motion_State'
 *    '<S44>/Motion_State'
 */
void FMS_Motion_State_Init(DW_Motion_State_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c5_FMS = 0U;
  localDW->is_c5_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * System reset for atomic system:
 *    '<S61>/Motion_State'
 *    '<S11>/Motion_State'
 *    '<S44>/Motion_State'
 */
void FMS_Motion_State_Reset(DW_Motion_State_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c5_FMS = 0U;
  localDW->is_c5_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * Output and update for atomic system:
 *    '<S61>/Motion_State'
 *    '<S11>/Motion_State'
 *    '<S44>/Motion_State'
 */
void FMS_Motion_State(boolean_T rtu_move_cmd, real32_T rtu_heading_rate, real_T *
                      rty_state, DW_Motion_State_FMS_T *localDW)
{
  /* Chart: '<S61>/Motion_State' */
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

  /* End of Chart: '<S61>/Motion_State' */
}

/*
 * System initialize for atomic system:
 *    '<S77>/Z_Motion_State'
 *    '<S27>/Z_Motion_State'
 */
void FMS_Z_Motion_State_Init(DW_Z_Motion_State_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c8_FMS = 0U;
  localDW->is_c8_FMS = FMS_IN_NO_ACTIVE_CHILD_e;
}

/*
 * System reset for atomic system:
 *    '<S77>/Z_Motion_State'
 *    '<S27>/Z_Motion_State'
 */
void FMS_Z_Motion_State_Reset(DW_Z_Motion_State_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c8_FMS = 0U;
  localDW->is_c8_FMS = FMS_IN_NO_ACTIVE_CHILD_e;
}

/*
 * Output and update for atomic system:
 *    '<S77>/Z_Motion_State'
 *    '<S27>/Z_Motion_State'
 */
void FMS_Z_Motion_State(boolean_T rtu_move_cmd, real32_T rtu_speed, real_T
  *rty_state, DW_Z_Motion_State_FMS_T *localDW)
{
  /* Chart: '<S77>/Z_Motion_State' */
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

  /* End of Chart: '<S77>/Z_Motion_State' */
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
  boolean_T rtb_LogicalOperator1;
  boolean_T rtb_FixPtRelationalOperator;
  uint16_T rtb_Multiply_ox[16];
  real32_T rtb_MatrixConcatenate3[9];
  uint8_T rtb_Compare;
  real32_T rtb_M_z[9];
  int8_T rtPrevAction;
  real32_T rtb_Add_c;
  real_T rtb_state_a;
  boolean_T rtb_Compare_ko;
  boolean_T rtb_Compare_oi;
  boolean_T rtb_Compare_pu;
  real32_T rtb_Multiply_a[3];
  real32_T rtb_Add_a;
  real32_T rtb_Add_k;
  int32_T i;
  int32_T i_0;
  real32_T rtb_Product_idx_0;
  real32_T rtb_Product_idx_1;
  real32_T rtb_Product_idx_3;
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

  /* DeadZone: '<S101>/Dead Zone' */
  if (rtb_stick_throttle_raw > FMS_PARAM.StickDeadZone) {
    rtb_TrigoFcn = rtb_stick_throttle_raw - FMS_PARAM.StickDeadZone;
  } else if (rtb_stick_throttle_raw >= -FMS_PARAM.StickDeadZone) {
    rtb_TrigoFcn = 0.0F;
  } else {
    rtb_TrigoFcn = rtb_stick_throttle_raw - (-FMS_PARAM.StickDeadZone);
  }

  /* End of DeadZone: '<S101>/Dead Zone' */

  /* Signum: '<S101>/Sign' */
  if (rtb_TrigoFcn < 0.0F) {
    rtb_Add_a = -1.0F;
  } else if (rtb_TrigoFcn > 0.0F) {
    rtb_Add_a = 1.0F;
  } else {
    rtb_Add_a = rtb_TrigoFcn;
  }

  /* End of Signum: '<S101>/Sign' */

  /* Sum: '<S101>/Add' incorporates:
   *  Constant: '<S101>/Constant'
   *  Product: '<S101>/Multiply'
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

  /* DeadZone: '<S102>/Dead Zone' */
  if (rtb_stick_roll_raw > FMS_PARAM.StickDeadZone) {
    rtb_TrigoFcn = rtb_stick_roll_raw - FMS_PARAM.StickDeadZone;
  } else if (rtb_stick_roll_raw >= -FMS_PARAM.StickDeadZone) {
    rtb_TrigoFcn = 0.0F;
  } else {
    rtb_TrigoFcn = rtb_stick_roll_raw - (-FMS_PARAM.StickDeadZone);
  }

  /* End of DeadZone: '<S102>/Dead Zone' */

  /* Signum: '<S102>/Sign' */
  if (rtb_TrigoFcn < 0.0F) {
    rtb_Add_a = -1.0F;
  } else if (rtb_TrigoFcn > 0.0F) {
    rtb_Add_a = 1.0F;
  } else {
    rtb_Add_a = rtb_TrigoFcn;
  }

  /* End of Signum: '<S102>/Sign' */

  /* Sum: '<S102>/Add' incorporates:
   *  Constant: '<S102>/Constant'
   *  Product: '<S102>/Multiply'
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

  /* DeadZone: '<S103>/Dead Zone' */
  if (rtb_stick_pitch_raw > FMS_PARAM.StickDeadZone) {
    rtb_TrigoFcn = rtb_stick_pitch_raw - FMS_PARAM.StickDeadZone;
  } else if (rtb_stick_pitch_raw >= -FMS_PARAM.StickDeadZone) {
    rtb_TrigoFcn = 0.0F;
  } else {
    rtb_TrigoFcn = rtb_stick_pitch_raw - (-FMS_PARAM.StickDeadZone);
  }

  /* End of DeadZone: '<S103>/Dead Zone' */

  /* Signum: '<S103>/Sign' */
  if (rtb_TrigoFcn < 0.0F) {
    rtb_Add_a = -1.0F;
  } else if (rtb_TrigoFcn > 0.0F) {
    rtb_Add_a = 1.0F;
  } else {
    rtb_Add_a = rtb_TrigoFcn;
  }

  /* End of Signum: '<S103>/Sign' */

  /* Sum: '<S103>/Add' incorporates:
   *  Constant: '<S103>/Constant'
   *  Product: '<S103>/Multiply'
   */
  rtb_Add_a = rtb_Add_a * FMS_PARAM.StickDeadZone + rtb_TrigoFcn;

  /* Chart: '<S106>/Arm_Event' */
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

  /* End of Chart: '<S106>/Arm_Event' */

  /* Logic: '<S114>/Logical Operator1' incorporates:
   *  Constant: '<S115>/Constant'
   *  Constant: '<S116>/Lower Limit'
   *  Constant: '<S116>/Upper Limit'
   *  DiscreteIntegrator: '<S117>/Discrete-Time Integrator5'
   *  Inport: '<Root>/Control_Out'
   *  Logic: '<S116>/AND'
   *  Product: '<S114>/Divide'
   *  RelationalOperator: '<S115>/Compare'
   *  RelationalOperator: '<S116>/Lower Test'
   *  RelationalOperator: '<S116>/Upper Test'
   *  Sum: '<S114>/Sum of Elements'
   */
  rtb_LogicalOperator1 = ((-10.806F <= FMS_DW.DiscreteTimeIntegrator5_DSTATE) &&
    (FMS_DW.DiscreteTimeIntegrator5_DSTATE <= -8.806F) && ((int32_T)((uint32_T)
    (uint16_T)((((uint32_T)FMS_U.Control_Out.actuator_cmd[0] +
                 FMS_U.Control_Out.actuator_cmd[1]) +
                FMS_U.Control_Out.actuator_cmd[2]) +
               FMS_U.Control_Out.actuator_cmd[3]) >> 2) < 1200));

  /* Chart: '<S106>/Disarm_Event' incorporates:
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

  /* End of Chart: '<S106>/Disarm_Event' */

  /* RelationalOperator: '<S99>/Compare' incorporates:
   *  Constant: '<S99>/Constant'
   *  Inport: '<Root>/Pilot_Cmd'
   */
  rtb_LogicalOperator1 = (FMS_U.Pilot_Cmd.cmd_1 == 1000U);

  /* RelationalOperator: '<S104>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S104>/Delay Input1'
   *
   * Block description for '<S104>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_FixPtRelationalOperator = ((int32_T)rtb_LogicalOperator1 > (int32_T)
    FMS_DW.DelayInput1_DSTATE);

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
      if (((FMS_B.disarm_event == 1.0) && FMS_ConstB.Disarm_Allowed_Logical_Oper)
          || rtb_FixPtRelationalOperator) {
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
      } else if (rtb_Add_c > 0.1) {
        FMS_DW.is_Arm_Logic = FMS_IN_Arm;
        FMS_DW.Delay_DSTATE_pi = 2U;
      } else {
        if ((FMS_B.arm_event == 1.0) || rtb_FixPtRelationalOperator) {
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

  /* Product: '<S110>/Multiply' */
  for (i = 0; i < 16; i++) {
    rtb_Multiply_ox[i] = FMS_B.PWM_Cmd;
  }

  /* End of Product: '<S110>/Multiply' */

  /* Product: '<S118>/Product' incorporates:
   *  Inport: '<Root>/INS_Output'
   */
  rtb_Product_idx_0 = FMS_U.INS_Output.quat[0] * FMS_U.INS_Output.quat[0];
  rtb_Product_idx_1 = FMS_U.INS_Output.quat[1] * FMS_U.INS_Output.quat[1];
  rtb_TrigoFcn = FMS_U.INS_Output.quat[2] * FMS_U.INS_Output.quat[2];
  rtb_Product_idx_3 = FMS_U.INS_Output.quat[3] * FMS_U.INS_Output.quat[3];

  /* Sum: '<S118>/Add' */
  rtb_MatrixConcatenate3[0] = ((rtb_Product_idx_0 + rtb_Product_idx_1) -
    rtb_TrigoFcn) - rtb_Product_idx_3;

  /* Sum: '<S118>/Add5' incorporates:
   *  Sum: '<S118>/Add8'
   */
  rtb_Product_idx_0 -= rtb_Product_idx_1;
  rtb_MatrixConcatenate3[4] = (rtb_Product_idx_0 + rtb_TrigoFcn) -
    rtb_Product_idx_3;

  /* Sum: '<S118>/Add8' */
  rtb_MatrixConcatenate3[8] = (rtb_Product_idx_0 - rtb_TrigoFcn) +
    rtb_Product_idx_3;

  /* Product: '<S118>/Product1' incorporates:
   *  Inport: '<Root>/INS_Output'
   *  Product: '<S118>/Product5'
   */
  rtb_Product_idx_0 = FMS_U.INS_Output.quat[1] * FMS_U.INS_Output.quat[2];

  /* Product: '<S118>/Product2' incorporates:
   *  Inport: '<Root>/INS_Output'
   *  Product: '<S118>/Product6'
   */
  rtb_TrigoFcn = FMS_U.INS_Output.quat[0] * FMS_U.INS_Output.quat[3];

  /* Gain: '<S118>/Gain' incorporates:
   *  Product: '<S118>/Product1'
   *  Product: '<S118>/Product2'
   *  Sum: '<S118>/Add1'
   */
  rtb_MatrixConcatenate3[1] = (rtb_Product_idx_0 + rtb_TrigoFcn) * 2.0F;

  /* Product: '<S118>/Product3' incorporates:
   *  Inport: '<Root>/INS_Output'
   *  Product: '<S118>/Product9'
   */
  rtb_Product_idx_3 = FMS_U.INS_Output.quat[1] * FMS_U.INS_Output.quat[3];

  /* Product: '<S118>/Product4' incorporates:
   *  Inport: '<Root>/INS_Output'
   *  Product: '<S118>/Product10'
   */
  rtb_Product_idx_1 = FMS_U.INS_Output.quat[0] * FMS_U.INS_Output.quat[2];

  /* Gain: '<S118>/Gain1' incorporates:
   *  Product: '<S118>/Product3'
   *  Product: '<S118>/Product4'
   *  Sum: '<S118>/Add2'
   */
  rtb_MatrixConcatenate3[2] = (rtb_Product_idx_3 - rtb_Product_idx_1) * 2.0F;

  /* Gain: '<S118>/Gain2' incorporates:
   *  Sum: '<S118>/Add3'
   */
  rtb_MatrixConcatenate3[3] = (rtb_Product_idx_0 - rtb_TrigoFcn) * 2.0F;

  /* Product: '<S118>/Product7' incorporates:
   *  Inport: '<Root>/INS_Output'
   *  Product: '<S118>/Product12'
   */
  rtb_Product_idx_0 = FMS_U.INS_Output.quat[2] * FMS_U.INS_Output.quat[3];

  /* Product: '<S118>/Product8' incorporates:
   *  Inport: '<Root>/INS_Output'
   *  Product: '<S118>/Product11'
   */
  rtb_TrigoFcn = FMS_U.INS_Output.quat[0] * FMS_U.INS_Output.quat[1];

  /* Gain: '<S118>/Gain3' incorporates:
   *  Product: '<S118>/Product7'
   *  Product: '<S118>/Product8'
   *  Sum: '<S118>/Add4'
   */
  rtb_MatrixConcatenate3[5] = (rtb_Product_idx_0 + rtb_TrigoFcn) * 2.0F;

  /* Gain: '<S118>/Gain4' incorporates:
   *  Sum: '<S118>/Add6'
   */
  rtb_MatrixConcatenate3[6] = (rtb_Product_idx_3 + rtb_Product_idx_1) * 2.0F;

  /* Gain: '<S118>/Gain5' incorporates:
   *  Sum: '<S118>/Add7'
   */
  rtb_MatrixConcatenate3[7] = (rtb_Product_idx_0 - rtb_TrigoFcn) * 2.0F;

  /* RelationalOperator: '<S108>/Compare' incorporates:
   *  Constant: '<S108>/Constant'
   */
  rtb_Compare = (uint8_T)(FMS_DW.Delay_DSTATE_pi < 2);

  /* Saturate: '<S2>/Saturation' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   */
  if (FMS_U.Pilot_Cmd.ls_lr > 1.0F) {
    rtb_Product_idx_3 = 1.0F;
  } else if (FMS_U.Pilot_Cmd.ls_lr < -1.0F) {
    rtb_Product_idx_3 = -1.0F;
  } else {
    rtb_Product_idx_3 = FMS_U.Pilot_Cmd.ls_lr;
  }

  /* End of Saturate: '<S2>/Saturation' */

  /* DeadZone: '<S100>/Dead Zone' */
  if (rtb_Product_idx_3 > FMS_PARAM.StickDeadZone) {
    rtb_Product_idx_3 -= FMS_PARAM.StickDeadZone;
  } else if (rtb_Product_idx_3 >= -FMS_PARAM.StickDeadZone) {
    rtb_Product_idx_3 = 0.0F;
  } else {
    rtb_Product_idx_3 -= -FMS_PARAM.StickDeadZone;
  }

  /* End of DeadZone: '<S100>/Dead Zone' */

  /* Signum: '<S100>/Sign' */
  if (rtb_Product_idx_3 < 0.0F) {
    rtb_Product_idx_0 = -1.0F;
  } else if (rtb_Product_idx_3 > 0.0F) {
    rtb_Product_idx_0 = 1.0F;
  } else {
    rtb_Product_idx_0 = rtb_Product_idx_3;
  }

  /* End of Signum: '<S100>/Sign' */

  /* Sum: '<S100>/Add' incorporates:
   *  Constant: '<S100>/Constant'
   *  Product: '<S100>/Multiply'
   */
  rtb_Product_idx_0 = rtb_Product_idx_0 * FMS_PARAM.StickDeadZone +
    rtb_Product_idx_3;

  /* Trigonometry: '<S105>/TrigoFcn1' incorporates:
   *  Inport: '<Root>/INS_Output'
   */
  rtb_Product_idx_3 = arm_cos_f32(FMS_U.INS_Output.psi);

  /* SignalConversion: '<S105>/ConcatBufferAtVecConcentateIn1' */
  rtb_M_z[0] = rtb_Product_idx_3;

  /* Trigonometry: '<S105>/TrigoFcn' incorporates:
   *  Inport: '<Root>/INS_Output'
   */
  rtb_TrigoFcn = arm_sin_f32(FMS_U.INS_Output.psi);

  /* Gain: '<S105>/Gain' */
  rtb_M_z[1] = -rtb_TrigoFcn;

  /* SignalConversion: '<S105>/ConcatBufferAtVecConcentateIn3' incorporates:
   *  Constant: '<S105>/Constant1'
   */
  rtb_M_z[2] = 0.0F;

  /* SignalConversion: '<S105>/ConcatBufferAtVecConcentate2In1' */
  rtb_M_z[3] = rtb_TrigoFcn;

  /* SignalConversion: '<S105>/ConcatBufferAtVecConcentate2In2' */
  rtb_M_z[4] = rtb_Product_idx_3;

  /* SignalConversion: '<S105>/ConcatBufferAtVecConcentate2In3' incorporates:
   *  Constant: '<S105>/Constant1'
   */
  rtb_M_z[5] = 0.0F;

  /* SignalConversion: '<S105>/ConcatBufferAtVecConcentate1In3' */
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
       *  Delay: '<S74>/Delay'
       *  Delay: '<S93>/Delay'
       *  Delay: '<S94>/Delay'
       *  UnitDelay: '<S65>/Delay Input1'
       *  UnitDelay: '<S66>/Delay Input1'
       *  UnitDelay: '<S91>/Delay Input1'
       *  UnitDelay: '<S92>/Delay Input1'
       *
       * Block description for '<S65>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S66>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S91>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S92>/Delay Input1':
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
       *  ActionPort: '<S7>/Action Port'
       */
      /* SystemReset for SwitchCase: '<S1>/Switch Case' incorporates:
       *  Chart: '<S61>/Motion_State'
       *  Chart: '<S77>/XY_Motion_State'
       *  Chart: '<S77>/Z_Motion_State'
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
    /* Logic: '<S80>/Logical Operator' incorporates:
     *  Constant: '<S97>/Constant'
     *  RelationalOperator: '<S97>/Compare'
     */
    rtb_FixPtRelationalOperator = ((rtb_Add_a != 0.0F) || (rtb_Add_k != 0.0F));

    /* Chart: '<S77>/XY_Motion_State' incorporates:
     *  Inport: '<Root>/INS_Output'
     *  Math: '<S79>/Math Function'
     *  Math: '<S79>/Math Function1'
     *  Sqrt: '<S79>/Sqrt'
     *  Sum: '<S79>/Add'
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

    /* End of Chart: '<S77>/XY_Motion_State' */

    /* RelationalOperator: '<S89>/Compare' incorporates:
     *  Constant: '<S89>/Constant'
     */
    rtb_FixPtRelationalOperator = (i == 2);

    /* Delay: '<S93>/Delay' incorporates:
     *  Inport: '<Root>/INS_Output'
     *  SignalConversion: '<S93>/TmpSignal ConversionAtDelayInport2'
     */
    if (FMS_DW.icLoad_f != 0) {
      FMS_DW.Delay_DSTATE_pp[0] = FMS_U.INS_Output.x_R;
      FMS_DW.Delay_DSTATE_pp[1] = FMS_U.INS_Output.y_R;
    }

    /* End of Delay: '<S93>/Delay' */

    /* Switch: '<S93>/Switch1' incorporates:
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S91>/FixPt Relational Operator'
     *  SignalConversion: '<S93>/TmpSignal ConversionAtDelayInport2'
     *  UnitDelay: '<S91>/Delay Input1'
     *
     * Block description for '<S91>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if ((int32_T)rtb_FixPtRelationalOperator > (int32_T)
        FMS_DW.DelayInput1_DSTATE_iu) {
      FMS_DW.Delay_DSTATE_pp[0] = FMS_U.INS_Output.x_R;
      FMS_DW.Delay_DSTATE_pp[1] = FMS_U.INS_Output.y_R;
    }

    /* End of Switch: '<S93>/Switch1' */

    /* Chart: '<S77>/Z_Motion_State' incorporates:
     *  Constant: '<S98>/Constant'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S98>/Compare'
     */
    FMS_Z_Motion_State(rtb_Add_c != 0.0F, FMS_U.INS_Output.vd, &rtb_state_a,
                       &FMS_DW.sf_Z_Motion_State);

    /* RelationalOperator: '<S90>/Compare' incorporates:
     *  Constant: '<S90>/Constant'
     */
    rtb_Compare_ko = (rtb_state_a == 2.0);

    /* Delay: '<S94>/Delay' incorporates:
     *  Gain: '<S88>/Gain'
     *  Inport: '<Root>/INS_Output'
     */
    if (FMS_DW.icLoad_a != 0) {
      FMS_DW.Delay_DSTATE_n = -FMS_U.INS_Output.h_R;
    }

    /* End of Delay: '<S94>/Delay' */

    /* Switch: '<S94>/Switch1' incorporates:
     *  Gain: '<S88>/Gain'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S92>/FixPt Relational Operator'
     *  UnitDelay: '<S92>/Delay Input1'
     *
     * Block description for '<S92>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if ((int32_T)rtb_Compare_ko > (int32_T)FMS_DW.DelayInput1_DSTATE_pv) {
      FMS_DW.Delay_DSTATE_n = -FMS_U.INS_Output.h_R;
    }

    /* End of Switch: '<S94>/Switch1' */

    /* Sum: '<S87>/Sum' incorporates:
     *  Gain: '<S88>/Gain'
     *  Inport: '<Root>/INS_Output'
     */
    rtb_stick_roll_raw = FMS_DW.Delay_DSTATE_pp[0] - FMS_U.INS_Output.x_R;
    rtb_stick_pitch_raw = FMS_DW.Delay_DSTATE_pp[1] - FMS_U.INS_Output.y_R;
    rtb_stick_throttle_raw = FMS_DW.Delay_DSTATE_n - (-FMS_U.INS_Output.h_R);

    /* Product: '<S87>/Multiply' */
    for (i_0 = 0; i_0 < 3; i_0++) {
      rtb_Multiply_a[i_0] = rtb_M_z[i_0 + 6] * rtb_stick_throttle_raw +
        (rtb_M_z[i_0 + 3] * rtb_stick_pitch_raw + rtb_M_z[i_0] *
         rtb_stick_roll_raw);
    }

    /* End of Product: '<S87>/Multiply' */

    /* Switch: '<S78>/Switch' incorporates:
     *  Constant: '<S83>/Constant'
     *  Constant: '<S95>/Constant'
     *  Gain: '<S85>/Gain2'
     *  RelationalOperator: '<S83>/Compare'
     *  RelationalOperator: '<S95>/Compare'
     *  Switch: '<S86>/Switch1'
     */
    if (i == 2) {
      rtb_stick_roll_raw = FMS_PARAM.XY_P * rtb_Multiply_a[0];
      rtb_Add_k = FMS_PARAM.XY_P * rtb_Multiply_a[1];
    } else if (i == 1) {
      /* Switch: '<S86>/Switch1' */
      rtb_stick_roll_raw = 0.0F;
      rtb_Add_k = 0.0F;
    } else {
      /* Switch: '<S86>/Switch1' incorporates:
       *  Gain: '<S86>/Gain1'
       *  Gain: '<S86>/Gain5'
       */
      rtb_stick_roll_raw = FMS_PARAM.VEL_XY_LIM * rtb_Add_a;
      rtb_Add_k *= FMS_PARAM.VEL_XY_LIM;
    }

    /* End of Switch: '<S78>/Switch' */

    /* Outport: '<Root>/FMS_Output' incorporates:
     *  Saturate: '<S78>/Saturation'
     */
    FMS_Y.FMS_Output.u_cmd = rtb_stick_roll_raw;

    /* Saturate: '<S78>/Saturation' */
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
     *  Saturate: '<S78>/Saturation'
     */
    FMS_Y.FMS_Output.v_cmd = rtb_Add_k;

    /* Saturate: '<S78>/Saturation' */
    if (rtb_Add_k > FMS_PARAM.VEL_XY_LIM) {
      /* Outport: '<Root>/FMS_Output' */
      FMS_Y.FMS_Output.v_cmd = FMS_PARAM.VEL_XY_LIM;
    } else {
      if (rtb_Add_k < -FMS_PARAM.VEL_XY_LIM) {
        /* Outport: '<Root>/FMS_Output' */
        FMS_Y.FMS_Output.v_cmd = -FMS_PARAM.VEL_XY_LIM;
      }
    }

    /* Switch: '<S78>/Switch1' incorporates:
     *  Constant: '<S84>/Constant'
     *  Constant: '<S96>/Constant'
     *  Gain: '<S85>/Gain4'
     *  RelationalOperator: '<S84>/Compare'
     *  RelationalOperator: '<S96>/Compare'
     *  Switch: '<S86>/Switch2'
     */
    if (rtb_state_a == 2.0) {
      rtb_Add_c = FMS_PARAM.Z_P * rtb_Multiply_a[2];
    } else if (rtb_state_a == 1.0) {
      /* Switch: '<S86>/Switch2' incorporates:
       *  Constant: '<S86>/Constant1'
       */
      rtb_Add_c = 0.0F;
    } else {
      /* Switch: '<S86>/Switch2' incorporates:
       *  Gain: '<S86>/Gain6'
       */
      rtb_Add_c *= -FMS_PARAM.VEL_Z_LIM;
    }

    /* End of Switch: '<S78>/Switch1' */

    /* Saturate: '<S78>/Saturation1' */
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

    /* End of Saturate: '<S78>/Saturation1' */

    /* Chart: '<S61>/Motion_State' incorporates:
     *  Abs: '<S71>/Abs'
     *  Constant: '<S76>/Constant'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S76>/Compare'
     */
    FMS_Motion_State(rtb_Product_idx_0 != 0.0F, fabsf(FMS_U.INS_Output.r),
                     &rtb_state_a, &FMS_DW.sf_Motion_State);

    /* RelationalOperator: '<S63>/Compare' incorporates:
     *  Constant: '<S63>/Constant'
     */
    rtb_Compare_oi = (rtb_state_a == 2.0);

    /* RelationalOperator: '<S64>/Compare' incorporates:
     *  BusAssignment: '<S3>/Bus Assignment'
     *  Constant: '<S64>/Constant'
     */
    rtb_Compare_pu = (FMS_DW.Delay_DSTATE_pi == 2);

    /* Delay: '<S74>/Delay' incorporates:
     *  Inport: '<Root>/INS_Output'
     */
    if (FMS_DW.icLoad_o != 0) {
      FMS_DW.Delay_DSTATE_c = FMS_U.INS_Output.psi;
    }

    /* End of Delay: '<S74>/Delay' */

    /* Switch: '<S74>/Switch1' incorporates:
     *  Inport: '<Root>/INS_Output'
     *  Logic: '<S61>/Logical Operator'
     *  RelationalOperator: '<S65>/FixPt Relational Operator'
     *  RelationalOperator: '<S66>/FixPt Relational Operator'
     *  UnitDelay: '<S65>/Delay Input1'
     *  UnitDelay: '<S66>/Delay Input1'
     *
     * Block description for '<S65>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S66>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if (((int32_T)rtb_Compare_pu > (int32_T)FMS_DW.DelayInput1_DSTATE_n) ||
        ((int32_T)rtb_Compare_oi > (int32_T)FMS_DW.DelayInput1_DSTATE_c)) {
      FMS_DW.Delay_DSTATE_c = FMS_U.INS_Output.psi;
    }

    /* End of Switch: '<S74>/Switch1' */

    /* Switch: '<S61>/Switch' incorporates:
     *  Constant: '<S75>/Constant'
     *  Gain: '<S67>/Gain2'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S75>/Compare'
     *  Sum: '<S72>/Sum'
     *  Switch: '<S68>/Switch1'
     */
    if (rtb_Compare_oi) {
      rtb_Add_c = (FMS_DW.Delay_DSTATE_c - FMS_U.INS_Output.psi) *
        FMS_PARAM.YAW_P;
    } else if (rtb_state_a == 1.0) {
      /* Switch: '<S68>/Switch1' incorporates:
       *  Constant: '<S68>/Constant'
       */
      rtb_Add_c = 0.0F;
    } else {
      /* Switch: '<S68>/Switch1' incorporates:
       *  Gain: '<S68>/Gain1'
       */
      rtb_Add_c = FMS_PARAM.YAW_RATE_LIM * rtb_Product_idx_0;
    }

    /* End of Switch: '<S61>/Switch' */

    /* Saturate: '<S61>/Saturation1' */
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

    /* End of Saturate: '<S61>/Saturation1' */

    /* Outport: '<Root>/FMS_Output' incorporates:
     *  BusAssignment: '<S3>/Bus Assignment'
     *  BusAssignment: '<S7>/Bus Assignment'
     *  Constant: '<S7>/Constant'
     *  DiscreteIntegrator: '<S111>/Discrete-Time Integrator'
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

    /* Update for UnitDelay: '<S91>/Delay Input1'
     *
     * Block description for '<S91>/Delay Input1':
     *
     *  Store in Global RAM
     */
    FMS_DW.DelayInput1_DSTATE_iu = rtb_FixPtRelationalOperator;

    /* Update for Delay: '<S93>/Delay' */
    FMS_DW.icLoad_f = 0U;

    /* Update for UnitDelay: '<S92>/Delay Input1'
     *
     * Block description for '<S92>/Delay Input1':
     *
     *  Store in Global RAM
     */
    FMS_DW.DelayInput1_DSTATE_pv = rtb_Compare_ko;

    /* Update for Delay: '<S94>/Delay' */
    FMS_DW.icLoad_a = 0U;

    /* Update for UnitDelay: '<S66>/Delay Input1'
     *
     * Block description for '<S66>/Delay Input1':
     *
     *  Store in Global RAM
     */
    FMS_DW.DelayInput1_DSTATE_n = rtb_Compare_pu;

    /* Update for UnitDelay: '<S65>/Delay Input1'
     *
     * Block description for '<S65>/Delay Input1':
     *
     *  Store in Global RAM
     */
    FMS_DW.DelayInput1_DSTATE_c = rtb_Compare_oi;

    /* Update for Delay: '<S74>/Delay' */
    FMS_DW.icLoad_o = 0U;

    /* End of Outputs for SubSystem: '<S1>/Position_Mode' */
    break;

   case 1:
    if (FMS_DW.SwitchCase_ActiveSubsystem != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S1>/Altitude_Hold_Mode' incorporates:
       *  ActionPort: '<S4>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S1>/Switch Case' incorporates:
       *  Delay: '<S24>/Delay'
       *  Delay: '<S39>/Delay'
       *  UnitDelay: '<S15>/Delay Input1'
       *  UnitDelay: '<S16>/Delay Input1'
       *  UnitDelay: '<S38>/Delay Input1'
       *
       * Block description for '<S15>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S16>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S38>/Delay Input1':
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
       *  ActionPort: '<S4>/Action Port'
       */
      /* SystemReset for SwitchCase: '<S1>/Switch Case' incorporates:
       *  Chart: '<S11>/Motion_State'
       *  Chart: '<S27>/Z_Motion_State'
       */
      FMS_Z_Motion_State_Reset(&FMS_DW.sf_Z_Motion_State_l);
      FMS_Motion_State_Reset(&FMS_DW.sf_Motion_State_c);

      /* End of SystemReset for SubSystem: '<S1>/Altitude_Hold_Mode' */
    }

    /* Outputs for IfAction SubSystem: '<S1>/Altitude_Hold_Mode' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* Chart: '<S27>/Z_Motion_State' incorporates:
     *  Constant: '<S41>/Constant'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S41>/Compare'
     */
    FMS_Z_Motion_State(rtb_Add_c != 0.0F, FMS_U.INS_Output.vd, &rtb_state_a,
                       &FMS_DW.sf_Z_Motion_State_l);

    /* RelationalOperator: '<S37>/Compare' incorporates:
     *  Constant: '<S37>/Constant'
     */
    rtb_FixPtRelationalOperator = (rtb_state_a == 2.0);

    /* Delay: '<S39>/Delay' incorporates:
     *  Gain: '<S36>/Gain'
     *  Inport: '<Root>/INS_Output'
     */
    if (FMS_DW.icLoad_d != 0) {
      FMS_DW.Delay_DSTATE_e = -FMS_U.INS_Output.h_R;
    }

    /* End of Delay: '<S39>/Delay' */

    /* Switch: '<S39>/Switch1' incorporates:
     *  Gain: '<S36>/Gain'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S38>/FixPt Relational Operator'
     *  UnitDelay: '<S38>/Delay Input1'
     *
     * Block description for '<S38>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if ((int32_T)rtb_FixPtRelationalOperator > (int32_T)
        FMS_DW.DelayInput1_DSTATE_a) {
      FMS_DW.Delay_DSTATE_e = -FMS_U.INS_Output.h_R;
    }

    /* End of Switch: '<S39>/Switch1' */

    /* Switch: '<S28>/Switch1' incorporates:
     *  Constant: '<S32>/Constant'
     *  Constant: '<S40>/Constant'
     *  Gain: '<S33>/Gain4'
     *  Gain: '<S36>/Gain'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S32>/Compare'
     *  RelationalOperator: '<S40>/Compare'
     *  Sum: '<S35>/Sum'
     *  Switch: '<S34>/Switch2'
     */
    if (rtb_state_a == 2.0) {
      rtb_Add_c = (FMS_DW.Delay_DSTATE_e - (-FMS_U.INS_Output.h_R)) *
        FMS_PARAM.Z_P;
    } else if (rtb_state_a == 1.0) {
      /* Switch: '<S34>/Switch2' incorporates:
       *  Constant: '<S34>/Constant1'
       */
      rtb_Add_c = 0.0F;
    } else {
      /* Switch: '<S34>/Switch2' incorporates:
       *  Gain: '<S34>/Gain6'
       */
      rtb_Add_c *= -FMS_PARAM.VEL_Z_LIM;
    }

    /* End of Switch: '<S28>/Switch1' */

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
     *  Abs: '<S21>/Abs'
     *  Constant: '<S26>/Constant'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S26>/Compare'
     */
    FMS_Motion_State(rtb_Product_idx_0 != 0.0F, fabsf(FMS_U.INS_Output.r),
                     &rtb_state_a, &FMS_DW.sf_Motion_State_c);

    /* RelationalOperator: '<S13>/Compare' incorporates:
     *  Constant: '<S13>/Constant'
     */
    rtb_Compare_ko = (rtb_state_a == 2.0);

    /* RelationalOperator: '<S14>/Compare' incorporates:
     *  BusAssignment: '<S3>/Bus Assignment'
     *  Constant: '<S14>/Constant'
     */
    rtb_Compare_oi = (FMS_DW.Delay_DSTATE_pi == 2);

    /* Delay: '<S24>/Delay' incorporates:
     *  Inport: '<Root>/INS_Output'
     */
    if (FMS_DW.icLoad_i != 0) {
      FMS_DW.Delay_DSTATE_p = FMS_U.INS_Output.psi;
    }

    /* End of Delay: '<S24>/Delay' */

    /* Switch: '<S24>/Switch1' incorporates:
     *  Inport: '<Root>/INS_Output'
     *  Logic: '<S11>/Logical Operator'
     *  RelationalOperator: '<S15>/FixPt Relational Operator'
     *  RelationalOperator: '<S16>/FixPt Relational Operator'
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
    if (((int32_T)rtb_Compare_oi > (int32_T)FMS_DW.DelayInput1_DSTATE_j) ||
        ((int32_T)rtb_Compare_ko > (int32_T)FMS_DW.DelayInput1_DSTATE_p)) {
      FMS_DW.Delay_DSTATE_p = FMS_U.INS_Output.psi;
    }

    /* End of Switch: '<S24>/Switch1' */

    /* Switch: '<S11>/Switch' incorporates:
     *  Constant: '<S25>/Constant'
     *  Gain: '<S17>/Gain2'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S25>/Compare'
     *  Sum: '<S22>/Sum'
     *  Switch: '<S18>/Switch1'
     */
    if (rtb_Compare_ko) {
      rtb_Add_c = (FMS_DW.Delay_DSTATE_p - FMS_U.INS_Output.psi) *
        FMS_PARAM.YAW_P;
    } else if (rtb_state_a == 1.0) {
      /* Switch: '<S18>/Switch1' incorporates:
       *  Constant: '<S18>/Constant'
       */
      rtb_Add_c = 0.0F;
    } else {
      /* Switch: '<S18>/Switch1' incorporates:
       *  Gain: '<S18>/Gain1'
       */
      rtb_Add_c = FMS_PARAM.YAW_RATE_LIM * rtb_Product_idx_0;
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
     *  DiscreteIntegrator: '<S111>/Discrete-Time Integrator'
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

    /* Update for UnitDelay: '<S38>/Delay Input1'
     *
     * Block description for '<S38>/Delay Input1':
     *
     *  Store in Global RAM
     */
    FMS_DW.DelayInput1_DSTATE_a = rtb_FixPtRelationalOperator;

    /* Update for Delay: '<S39>/Delay' */
    FMS_DW.icLoad_d = 0U;

    /* Update for UnitDelay: '<S16>/Delay Input1'
     *
     * Block description for '<S16>/Delay Input1':
     *
     *  Store in Global RAM
     */
    FMS_DW.DelayInput1_DSTATE_j = rtb_Compare_oi;

    /* Update for UnitDelay: '<S15>/Delay Input1'
     *
     * Block description for '<S15>/Delay Input1':
     *
     *  Store in Global RAM
     */
    FMS_DW.DelayInput1_DSTATE_p = rtb_Compare_ko;

    /* Update for Delay: '<S24>/Delay' */
    FMS_DW.icLoad_i = 0U;

    /* End of Outputs for SubSystem: '<S1>/Altitude_Hold_Mode' */
    break;

   case 2:
    if (FMS_DW.SwitchCase_ActiveSubsystem != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S1>/Manual_Mode' incorporates:
       *  ActionPort: '<S5>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S1>/Switch Case' incorporates:
       *  Delay: '<S57>/Delay'
       *  UnitDelay: '<S48>/Delay Input1'
       *  UnitDelay: '<S49>/Delay Input1'
       *
       * Block description for '<S48>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S49>/Delay Input1':
       *
       *  Store in Global RAM
       */
      FMS_DW.DelayInput1_DSTATE_l = false;
      FMS_DW.DelayInput1_DSTATE_i = false;
      FMS_DW.icLoad = 1U;

      /* End of InitializeConditions for SubSystem: '<S1>/Manual_Mode' */

      /* SystemReset for IfAction SubSystem: '<S1>/Manual_Mode' incorporates:
       *  ActionPort: '<S5>/Action Port'
       */
      /* SystemReset for SwitchCase: '<S1>/Switch Case' incorporates:
       *  Chart: '<S44>/Motion_State'
       */
      FMS_Motion_State_Reset(&FMS_DW.sf_Motion_State_j);

      /* End of SystemReset for SubSystem: '<S1>/Manual_Mode' */
    }

    /* Outputs for IfAction SubSystem: '<S1>/Manual_Mode' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* Chart: '<S44>/Motion_State' incorporates:
     *  Abs: '<S54>/Abs'
     *  Constant: '<S59>/Constant'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S59>/Compare'
     */
    FMS_Motion_State(rtb_Product_idx_0 != 0.0F, fabsf(FMS_U.INS_Output.r),
                     &rtb_state_a, &FMS_DW.sf_Motion_State_j);

    /* RelationalOperator: '<S46>/Compare' incorporates:
     *  Constant: '<S46>/Constant'
     */
    rtb_FixPtRelationalOperator = (rtb_state_a == 2.0);

    /* RelationalOperator: '<S47>/Compare' incorporates:
     *  BusAssignment: '<S3>/Bus Assignment'
     *  Constant: '<S47>/Constant'
     */
    rtb_Compare_ko = (FMS_DW.Delay_DSTATE_pi == 2);

    /* Delay: '<S57>/Delay' incorporates:
     *  Inport: '<Root>/INS_Output'
     */
    if (FMS_DW.icLoad != 0) {
      FMS_DW.Delay_DSTATE = FMS_U.INS_Output.psi;
    }

    /* End of Delay: '<S57>/Delay' */

    /* Switch: '<S57>/Switch1' incorporates:
     *  Inport: '<Root>/INS_Output'
     *  Logic: '<S44>/Logical Operator'
     *  RelationalOperator: '<S48>/FixPt Relational Operator'
     *  RelationalOperator: '<S49>/FixPt Relational Operator'
     *  UnitDelay: '<S48>/Delay Input1'
     *  UnitDelay: '<S49>/Delay Input1'
     *
     * Block description for '<S48>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S49>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if (((int32_T)rtb_Compare_ko > (int32_T)FMS_DW.DelayInput1_DSTATE_l) ||
        ((int32_T)rtb_FixPtRelationalOperator > (int32_T)
         FMS_DW.DelayInput1_DSTATE_i)) {
      FMS_DW.Delay_DSTATE = FMS_U.INS_Output.psi;
    }

    /* End of Switch: '<S57>/Switch1' */

    /* Switch: '<S44>/Switch' incorporates:
     *  Constant: '<S58>/Constant'
     *  Gain: '<S50>/Gain2'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S58>/Compare'
     *  Sum: '<S55>/Sum'
     *  Switch: '<S51>/Switch1'
     */
    if (rtb_FixPtRelationalOperator) {
      rtb_Add_c = (FMS_DW.Delay_DSTATE - FMS_U.INS_Output.psi) * FMS_PARAM.YAW_P;
    } else if (rtb_state_a == 1.0) {
      /* Switch: '<S51>/Switch1' incorporates:
       *  Constant: '<S51>/Constant'
       */
      rtb_Add_c = 0.0F;
    } else {
      /* Switch: '<S51>/Switch1' incorporates:
       *  Gain: '<S51>/Gain1'
       */
      rtb_Add_c = FMS_PARAM.YAW_RATE_LIM * rtb_Product_idx_0;
    }

    /* End of Switch: '<S44>/Switch' */

    /* Saturate: '<S44>/Saturation1' */
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

    /* End of Saturate: '<S44>/Saturation1' */

    /* Outport: '<Root>/FMS_Output' incorporates:
     *  BusAssignment: '<S3>/Bus Assignment'
     *  BusAssignment: '<S5>/Bus Assignment'
     *  Constant: '<S45>/Constant'
     *  Constant: '<S45>/Constant1'
     *  Constant: '<S5>/Constant'
     *  DiscreteIntegrator: '<S111>/Discrete-Time Integrator'
     *  Gain: '<S43>/Gain1'
     *  Gain: '<S43>/Gain2'
     *  Gain: '<S45>/Gain'
     *  SignalConversion: '<S3>/TmpHiddenBufferAtBus AssignmentInport1'
     *  Sum: '<S45>/Add'
     *  Sum: '<S45>/Sum'
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

    /* Update for UnitDelay: '<S49>/Delay Input1'
     *
     * Block description for '<S49>/Delay Input1':
     *
     *  Store in Global RAM
     */
    FMS_DW.DelayInput1_DSTATE_l = rtb_Compare_ko;

    /* Update for UnitDelay: '<S48>/Delay Input1'
     *
     * Block description for '<S48>/Delay Input1':
     *
     *  Store in Global RAM
     */
    FMS_DW.DelayInput1_DSTATE_i = rtb_FixPtRelationalOperator;

    /* Update for Delay: '<S57>/Delay' */
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
     *  DiscreteIntegrator: '<S111>/Discrete-Time Integrator'
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

  /* Product: '<S114>/Multiply' incorporates:
   *  Inport: '<Root>/INS_Output'
   *  SignalConversion: '<S114>/ConcatBufferAtMatrix Concatenate3In1'
   *  SignalConversion: '<S114>/ConcatBufferAtMatrix Concatenate3In2'
   *  SignalConversion: '<S114>/ConcatBufferAtMatrix Concatenate3In3'
   */
  for (i_0 = 0; i_0 < 3; i_0++) {
    rtb_Multiply_a[i_0] = rtb_MatrixConcatenate3[i_0 + 6] * FMS_U.INS_Output.az
      + (rtb_MatrixConcatenate3[i_0 + 3] * FMS_U.INS_Output.ay +
         rtb_MatrixConcatenate3[i_0] * FMS_U.INS_Output.ax);
  }

  /* End of Product: '<S114>/Multiply' */

  /* Update for DiscreteIntegrator: '<S117>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S117>/Gain2'
   *  Sum: '<S117>/Sum9'
   */
  FMS_DW.DiscreteTimeIntegrator5_DSTATE += (rtb_Multiply_a[2] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE) * 2.0F * 0.008F;

  /* Update for UnitDelay: '<S104>/Delay Input1'
   *
   * Block description for '<S104>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE = rtb_LogicalOperator1;

  /* Update for DiscreteIntegrator: '<S111>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S111>/Constant'
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

  /* SystemInitialize for Chart: '<S106>/Arm_Event' */
  FMS_DW.is_active_c3_FMS = 0U;
  FMS_DW.is_c3_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for Chart: '<S106>/Disarm_Event' */
  FMS_DW.temporalCounter_i1_a = 0U;
  FMS_DW.is_active_c10_FMS = 0U;
  FMS_DW.is_c10_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for Chart: '<S3>/State_Logic' */
  FMS_DW.is_Arm_Logic = FMS_IN_NO_ACTIVE_CHILD_h;
  FMS_DW.temporalCounter_i1 = 0U;
  FMS_DW.is_active_c4_FMS = 0U;

  /* SystemInitialize for IfAction SubSystem: '<S1>/Position_Mode' */
  /* InitializeConditions for UnitDelay: '<S91>/Delay Input1'
   *
   * Block description for '<S91>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_iu = false;

  /* InitializeConditions for Delay: '<S93>/Delay' */
  FMS_DW.icLoad_f = 1U;

  /* InitializeConditions for UnitDelay: '<S92>/Delay Input1'
   *
   * Block description for '<S92>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_pv = false;

  /* InitializeConditions for Delay: '<S94>/Delay' */
  FMS_DW.icLoad_a = 1U;

  /* InitializeConditions for UnitDelay: '<S66>/Delay Input1'
   *
   * Block description for '<S66>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_n = false;

  /* InitializeConditions for UnitDelay: '<S65>/Delay Input1'
   *
   * Block description for '<S65>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_c = false;

  /* InitializeConditions for Delay: '<S74>/Delay' */
  FMS_DW.icLoad_o = 1U;

  /* SystemInitialize for Chart: '<S77>/XY_Motion_State' */
  FMS_DW.temporalCounter_i1_b = 0U;
  FMS_DW.is_active_c7_FMS = 0U;
  FMS_DW.is_c7_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for Chart: '<S77>/Z_Motion_State' */
  FMS_Z_Motion_State_Init(&FMS_DW.sf_Z_Motion_State);

  /* SystemInitialize for Chart: '<S61>/Motion_State' */
  FMS_Motion_State_Init(&FMS_DW.sf_Motion_State);

  /* End of SystemInitialize for SubSystem: '<S1>/Position_Mode' */

  /* SystemInitialize for IfAction SubSystem: '<S1>/Altitude_Hold_Mode' */
  /* InitializeConditions for UnitDelay: '<S38>/Delay Input1'
   *
   * Block description for '<S38>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_a = false;

  /* InitializeConditions for Delay: '<S39>/Delay' */
  FMS_DW.icLoad_d = 1U;

  /* InitializeConditions for UnitDelay: '<S16>/Delay Input1'
   *
   * Block description for '<S16>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_j = false;

  /* InitializeConditions for UnitDelay: '<S15>/Delay Input1'
   *
   * Block description for '<S15>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_p = false;

  /* InitializeConditions for Delay: '<S24>/Delay' */
  FMS_DW.icLoad_i = 1U;

  /* SystemInitialize for Chart: '<S27>/Z_Motion_State' */
  FMS_Z_Motion_State_Init(&FMS_DW.sf_Z_Motion_State_l);

  /* SystemInitialize for Chart: '<S11>/Motion_State' */
  FMS_Motion_State_Init(&FMS_DW.sf_Motion_State_c);

  /* End of SystemInitialize for SubSystem: '<S1>/Altitude_Hold_Mode' */

  /* SystemInitialize for IfAction SubSystem: '<S1>/Manual_Mode' */
  /* InitializeConditions for UnitDelay: '<S49>/Delay Input1'
   *
   * Block description for '<S49>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_l = false;

  /* InitializeConditions for UnitDelay: '<S48>/Delay Input1'
   *
   * Block description for '<S48>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_i = false;

  /* InitializeConditions for Delay: '<S57>/Delay' */
  FMS_DW.icLoad = 1U;

  /* SystemInitialize for Chart: '<S44>/Motion_State' */
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
