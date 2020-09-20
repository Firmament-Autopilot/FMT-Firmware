/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.718
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sun Sep 20 09:13:05 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S80>/Motion_State' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)

/* Named constants for Chart: '<S99>/Z_Motion_State' */
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

/* Named constants for Chart: '<S99>/XY_Motion_State' */
#define FMS_IN_Brake_hi                ((uint8_T)1U)
#define FMS_IN_Hold_n                  ((uint8_T)2U)
#define FMS_IN_Move_j                  ((uint8_T)3U)

/* Named constants for Chart: '<S135>/Arm_Event' */
#define FMS_IN_Idle                    ((uint8_T)1U)
#define FMS_IN_arm_event               ((uint8_T)2U)
#define FMS_IN_ready                   ((uint8_T)3U)

/* Named constants for Chart: '<S135>/Disarm_Event' */
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
  1.0F,
  5.0F,
  2.5F,
  2.5F,
  1.04719806F,
  0.523599F
} ;                                    /* Variable: FMS_PARAM
                                        * Referenced by:
                                        *   '<S126>/Constant'
                                        *   '<S126>/Dead Zone'
                                        *   '<S127>/Constant'
                                        *   '<S127>/Dead Zone'
                                        *   '<S128>/Constant'
                                        *   '<S128>/Dead Zone'
                                        *   '<S129>/Constant'
                                        *   '<S129>/Dead Zone'
                                        *   '<S14>/Gain'
                                        *   '<S14>/Gain1'
                                        *   '<S15>/Saturation1'
                                        *   '<S16>/Saturation'
                                        *   '<S57>/Gain1'
                                        *   '<S57>/Gain2'
                                        *   '<S58>/Saturation1'
                                        *   '<S80>/Saturation1'
                                        *   '<S25>/Gain2'
                                        *   '<S26>/Gain1'
                                        *   '<S68>/Gain2'
                                        *   '<S69>/Gain1'
                                        *   '<S86>/Gain2'
                                        *   '<S87>/Gain1'
                                        *   '<S100>/Saturation'
                                        *   '<S100>/Saturation1'
                                        *   '<S35>/Dead Zone'
                                        *   '<S35>/Gain'
                                        *   '<S44>/Gain4'
                                        *   '<S45>/Gain6'
                                        *   '<S77>/Dead Zone'
                                        *   '<S77>/Gain'
                                        *   '<S96>/Dead Zone'
                                        *   '<S96>/Gain'
                                        *   '<S107>/Gain2'
                                        *   '<S107>/Gain4'
                                        *   '<S108>/Gain1'
                                        *   '<S108>/Gain5'
                                        *   '<S108>/Gain6'
                                        *   '<S53>/Dead Zone'
                                        *   '<S53>/Gain'
                                        *   '<S120>/Dead Zone'
                                        *   '<S120>/Gain'
                                        *   '<S121>/Dead Zone'
                                        *   '<S121>/Gain'
                                        *   '<S122>/Dead Zone'
                                        *   '<S122>/Gain'
                                        */

struct_i7E80ZuatMf603HOn7rPOE FMS_EXPORT = {
  4U,

  { 66, 97, 115, 101, 32, 70, 77, 83, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by: '<S140>/Constant'
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
 *    '<S80>/Motion_State'
 *    '<S15>/Motion_State'
 *    '<S58>/Motion_State'
 */
void FMS_Motion_State_Init(DW_Motion_State_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c11_FMS = 0U;
  localDW->is_c11_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * System reset for atomic system:
 *    '<S80>/Motion_State'
 *    '<S15>/Motion_State'
 *    '<S58>/Motion_State'
 */
void FMS_Motion_State_Reset(DW_Motion_State_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c11_FMS = 0U;
  localDW->is_c11_FMS = FMS_IN_NO_ACTIVE_CHILD;
}

/*
 * Output and update for atomic system:
 *    '<S80>/Motion_State'
 *    '<S15>/Motion_State'
 *    '<S58>/Motion_State'
 */
void FMS_Motion_State(boolean_T rtu_move_cmd, real32_T rtu_heading_rate, real_T *
                      rty_state, DW_Motion_State_FMS_T *localDW)
{
  /* Chart: '<S80>/Motion_State' */
  if (localDW->temporalCounter_i1 < 255U) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->is_active_c11_FMS == 0U) {
    localDW->is_active_c11_FMS = 1U;
    localDW->is_c11_FMS = FMS_IN_Move;
    *rty_state = 0.0;
  } else {
    switch (localDW->is_c11_FMS) {
     case FMS_IN_Brake:
      *rty_state = 1.0;
      if ((rtu_heading_rate <= 0.1) || (localDW->temporalCounter_i1 >= 250U)) {
        localDW->is_c11_FMS = FMS_IN_Hold;
        *rty_state = 2.0;
      } else {
        if (rtu_move_cmd) {
          localDW->is_c11_FMS = FMS_IN_Move;
          *rty_state = 0.0;
        }
      }
      break;

     case FMS_IN_Hold:
      *rty_state = 2.0;
      if (rtu_move_cmd) {
        localDW->is_c11_FMS = FMS_IN_Move;
        *rty_state = 0.0;
      }
      break;

     default:
      *rty_state = 0.0;
      if (!rtu_move_cmd) {
        localDW->is_c11_FMS = FMS_IN_Brake;
        localDW->temporalCounter_i1 = 0U;
        *rty_state = 1.0;
      }
      break;
    }
  }

  /* End of Chart: '<S80>/Motion_State' */
}

/*
 * System initialize for atomic system:
 *    '<S99>/Z_Motion_State'
 *    '<S38>/Z_Motion_State'
 */
void FMS_Z_Motion_State_Init(DW_Z_Motion_State_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c8_FMS = 0U;
  localDW->is_c8_FMS = FMS_IN_NO_ACTIVE_CHILD_e;
}

/*
 * System reset for atomic system:
 *    '<S99>/Z_Motion_State'
 *    '<S38>/Z_Motion_State'
 */
void FMS_Z_Motion_State_Reset(DW_Z_Motion_State_FMS_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c8_FMS = 0U;
  localDW->is_c8_FMS = FMS_IN_NO_ACTIVE_CHILD_e;
}

/*
 * Output and update for atomic system:
 *    '<S99>/Z_Motion_State'
 *    '<S38>/Z_Motion_State'
 */
void FMS_Z_Motion_State(boolean_T rtu_move_cmd, real32_T rtu_speed, real_T
  *rty_state, DW_Z_Motion_State_FMS_T *localDW)
{
  /* Chart: '<S99>/Z_Motion_State' */
  if (localDW->temporalCounter_i1 < 511U) {
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
      if ((fabsf(rtu_speed) <= 0.2) || (localDW->temporalCounter_i1 >= 375U)) {
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

  /* End of Chart: '<S99>/Z_Motion_State' */
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
  real32_T rtb_Multiply_a[3];
  real_T rtb_state_mp;
  boolean_T rtb_Compare_if;
  boolean_T rtb_Compare_px;
  real32_T rtb_Subtract3_f;
  real32_T rtb_Add4_i;
  real32_T rtb_Divide_la;
  real32_T rtb_Sign5_m;
  real32_T rtb_Divide_d;
  real32_T rtb_Sign5_dz;
  real32_T rtb_Add_d;
  real32_T rtb_Add_m;
  int32_T i;
  int32_T i_0;
  real32_T rtb_Product_idx_0;
  real32_T rtb_Product_idx_1;
  real32_T rtb_Product_idx_2;
  uint32_T tmp;
  real32_T y;
  real32_T u;
  real32_T u_0;
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

  /* DeadZone: '<S128>/Dead Zone' */
  if (rtb_stick_roll_raw > FMS_PARAM.StickDeadZone) {
    rtb_TrigoFcn = rtb_stick_roll_raw - FMS_PARAM.StickDeadZone;
  } else if (rtb_stick_roll_raw >= -FMS_PARAM.StickDeadZone) {
    rtb_TrigoFcn = 0.0F;
  } else {
    rtb_TrigoFcn = rtb_stick_roll_raw - (-FMS_PARAM.StickDeadZone);
  }

  /* End of DeadZone: '<S128>/Dead Zone' */

  /* Signum: '<S128>/Sign' */
  if (rtb_TrigoFcn < 0.0F) {
    rtb_Product_idx_0 = -1.0F;
  } else if (rtb_TrigoFcn > 0.0F) {
    rtb_Product_idx_0 = 1.0F;
  } else {
    rtb_Product_idx_0 = rtb_TrigoFcn;
  }

  /* End of Signum: '<S128>/Sign' */

  /* Sum: '<S128>/Add' incorporates:
   *  Constant: '<S128>/Constant'
   *  Product: '<S128>/Multiply'
   */
  rtb_Add_m = rtb_Product_idx_0 * FMS_PARAM.StickDeadZone + rtb_TrigoFcn;

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

  /* DeadZone: '<S129>/Dead Zone' */
  if (rtb_stick_pitch_raw > FMS_PARAM.StickDeadZone) {
    rtb_TrigoFcn = rtb_stick_pitch_raw - FMS_PARAM.StickDeadZone;
  } else if (rtb_stick_pitch_raw >= -FMS_PARAM.StickDeadZone) {
    rtb_TrigoFcn = 0.0F;
  } else {
    rtb_TrigoFcn = rtb_stick_pitch_raw - (-FMS_PARAM.StickDeadZone);
  }

  /* End of DeadZone: '<S129>/Dead Zone' */

  /* Signum: '<S129>/Sign' */
  if (rtb_TrigoFcn < 0.0F) {
    rtb_Product_idx_0 = -1.0F;
  } else if (rtb_TrigoFcn > 0.0F) {
    rtb_Product_idx_0 = 1.0F;
  } else {
    rtb_Product_idx_0 = rtb_TrigoFcn;
  }

  /* End of Signum: '<S129>/Sign' */

  /* Sum: '<S129>/Add' incorporates:
   *  Constant: '<S129>/Constant'
   *  Product: '<S129>/Multiply'
   */
  rtb_Add_d = rtb_Product_idx_0 * FMS_PARAM.StickDeadZone + rtb_TrigoFcn;

  /* Chart: '<S135>/Arm_Event' */
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

  /* End of Chart: '<S135>/Arm_Event' */

  /* Logic: '<S143>/Logical Operator1' incorporates:
   *  Constant: '<S144>/Constant'
   *  Constant: '<S145>/Lower Limit'
   *  Constant: '<S145>/Upper Limit'
   *  DiscreteIntegrator: '<S146>/Discrete-Time Integrator5'
   *  Inport: '<Root>/Control_Out'
   *  Logic: '<S145>/AND'
   *  Product: '<S143>/Divide'
   *  RelationalOperator: '<S144>/Compare'
   *  RelationalOperator: '<S145>/Lower Test'
   *  RelationalOperator: '<S145>/Upper Test'
   *  Sum: '<S143>/Sum of Elements'
   */
  rtb_LogicalOperator1 = ((-10.806F <= FMS_DW.DiscreteTimeIntegrator5_DSTATE) &&
    (FMS_DW.DiscreteTimeIntegrator5_DSTATE <= -8.806F) && ((int32_T)((uint32_T)
    (uint16_T)((((uint32_T)FMS_U.Control_Out.actuator_cmd[0] +
                 FMS_U.Control_Out.actuator_cmd[1]) +
                FMS_U.Control_Out.actuator_cmd[2]) +
               FMS_U.Control_Out.actuator_cmd[3]) >> 2) < 1200));

  /* Chart: '<S135>/Disarm_Event' incorporates:
   *  Delay: '<S3>/Delay'
   */
  if (FMS_DW.temporalCounter_i1_a < 511U) {
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
        if (FMS_DW.temporalCounter_i1_a >= 375U) {
          FMS_DW.is_c10_FMS = FMS_IN_Disarm;
          FMS_B.disarm_event = 1.0;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S135>/Disarm_Event' */

  /* RelationalOperator: '<S132>/Compare' incorporates:
   *  Constant: '<S132>/Constant'
   *  Inport: '<Root>/Pilot_Cmd'
   */
  rtb_LogicalOperator1 = (FMS_U.Pilot_Cmd.cmd_1 == 1000U);

  /* RelationalOperator: '<S134>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S134>/Delay Input1'
   *
   * Block description for '<S134>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_FixPtRelationalOperator = ((int32_T)rtb_LogicalOperator1 > (int32_T)
    FMS_DW.DelayInput1_DSTATE);

  /* RelationalOperator: '<S133>/Compare' incorporates:
   *  Constant: '<S133>/Constant'
   *  Inport: '<Root>/Pilot_Cmd'
   */
  rtb_Compare_nq = (FMS_U.Pilot_Cmd.cmd_2 == 2000U);

  /* Chart: '<S3>/State_Logic' */
  if (FMS_DW.temporalCounter_i1 < 8191U) {
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
          FMS_B.PWM_Cmd = 1150U;
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
      if (FMS_DW.temporalCounter_i1 >= 7500U) {
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

  /* Product: '<S139>/Multiply' */
  for (i = 0; i < 16; i++) {
    rtb_Multiply_ox[i] = FMS_B.PWM_Cmd;
  }

  /* End of Product: '<S139>/Multiply' */

  /* Product: '<S147>/Product' incorporates:
   *  Inport: '<Root>/INS_Output'
   */
  rtb_Product_idx_0 = FMS_U.INS_Output.quat[0] * FMS_U.INS_Output.quat[0];
  rtb_Product_idx_1 = FMS_U.INS_Output.quat[1] * FMS_U.INS_Output.quat[1];
  rtb_Product_idx_2 = FMS_U.INS_Output.quat[2] * FMS_U.INS_Output.quat[2];
  rtb_TrigoFcn = FMS_U.INS_Output.quat[3] * FMS_U.INS_Output.quat[3];

  /* Sum: '<S147>/Add' */
  rtb_MatrixConcatenate3[0] = ((rtb_Product_idx_0 + rtb_Product_idx_1) -
    rtb_Product_idx_2) - rtb_TrigoFcn;

  /* Sum: '<S147>/Add5' incorporates:
   *  Sum: '<S147>/Add8'
   */
  rtb_Product_idx_0 -= rtb_Product_idx_1;
  rtb_MatrixConcatenate3[4] = (rtb_Product_idx_0 + rtb_Product_idx_2) -
    rtb_TrigoFcn;

  /* Sum: '<S147>/Add8' */
  rtb_MatrixConcatenate3[8] = (rtb_Product_idx_0 - rtb_Product_idx_2) +
    rtb_TrigoFcn;

  /* Product: '<S147>/Product1' incorporates:
   *  Inport: '<Root>/INS_Output'
   *  Product: '<S147>/Product5'
   */
  rtb_Product_idx_0 = FMS_U.INS_Output.quat[1] * FMS_U.INS_Output.quat[2];

  /* Product: '<S147>/Product2' incorporates:
   *  Inport: '<Root>/INS_Output'
   *  Product: '<S147>/Product6'
   */
  rtb_Product_idx_2 = FMS_U.INS_Output.quat[0] * FMS_U.INS_Output.quat[3];

  /* Gain: '<S147>/Gain' incorporates:
   *  Product: '<S147>/Product1'
   *  Product: '<S147>/Product2'
   *  Sum: '<S147>/Add1'
   */
  rtb_MatrixConcatenate3[1] = (rtb_Product_idx_0 + rtb_Product_idx_2) * 2.0F;

  /* Product: '<S147>/Product3' incorporates:
   *  Inport: '<Root>/INS_Output'
   *  Product: '<S147>/Product9'
   */
  rtb_TrigoFcn = FMS_U.INS_Output.quat[1] * FMS_U.INS_Output.quat[3];

  /* Product: '<S147>/Product4' incorporates:
   *  Inport: '<Root>/INS_Output'
   *  Product: '<S147>/Product10'
   */
  rtb_Product_idx_1 = FMS_U.INS_Output.quat[0] * FMS_U.INS_Output.quat[2];

  /* Gain: '<S147>/Gain1' incorporates:
   *  Product: '<S147>/Product3'
   *  Product: '<S147>/Product4'
   *  Sum: '<S147>/Add2'
   */
  rtb_MatrixConcatenate3[2] = (rtb_TrigoFcn - rtb_Product_idx_1) * 2.0F;

  /* Gain: '<S147>/Gain2' incorporates:
   *  Sum: '<S147>/Add3'
   */
  rtb_MatrixConcatenate3[3] = (rtb_Product_idx_0 - rtb_Product_idx_2) * 2.0F;

  /* Product: '<S147>/Product7' incorporates:
   *  Inport: '<Root>/INS_Output'
   *  Product: '<S147>/Product12'
   */
  rtb_Product_idx_0 = FMS_U.INS_Output.quat[2] * FMS_U.INS_Output.quat[3];

  /* Product: '<S147>/Product8' incorporates:
   *  Inport: '<Root>/INS_Output'
   *  Product: '<S147>/Product11'
   */
  rtb_Product_idx_2 = FMS_U.INS_Output.quat[0] * FMS_U.INS_Output.quat[1];

  /* Gain: '<S147>/Gain3' incorporates:
   *  Product: '<S147>/Product7'
   *  Product: '<S147>/Product8'
   *  Sum: '<S147>/Add4'
   */
  rtb_MatrixConcatenate3[5] = (rtb_Product_idx_0 + rtb_Product_idx_2) * 2.0F;

  /* Gain: '<S147>/Gain4' incorporates:
   *  Sum: '<S147>/Add6'
   */
  rtb_MatrixConcatenate3[6] = (rtb_TrigoFcn + rtb_Product_idx_1) * 2.0F;

  /* Gain: '<S147>/Gain5' incorporates:
   *  Sum: '<S147>/Add7'
   */
  rtb_MatrixConcatenate3[7] = (rtb_Product_idx_0 - rtb_Product_idx_2) * 2.0F;

  /* RelationalOperator: '<S137>/Compare' incorporates:
   *  Constant: '<S137>/Constant'
   */
  rtb_Compare = (uint8_T)(FMS_DW.Delay_DSTATE_pi < 2);

  /* DeadZone: '<S127>/Dead Zone' */
  if (rtb_stick_throttle_raw > FMS_PARAM.StickDeadZone) {
    rtb_Product_idx_1 = rtb_stick_throttle_raw - FMS_PARAM.StickDeadZone;
  } else if (rtb_stick_throttle_raw >= -FMS_PARAM.StickDeadZone) {
    rtb_Product_idx_1 = 0.0F;
  } else {
    rtb_Product_idx_1 = rtb_stick_throttle_raw - (-FMS_PARAM.StickDeadZone);
  }

  /* End of DeadZone: '<S127>/Dead Zone' */

  /* Signum: '<S127>/Sign' */
  if (rtb_Product_idx_1 < 0.0F) {
    rtb_Product_idx_0 = -1.0F;
  } else if (rtb_Product_idx_1 > 0.0F) {
    rtb_Product_idx_0 = 1.0F;
  } else {
    rtb_Product_idx_0 = rtb_Product_idx_1;
  }

  /* End of Signum: '<S127>/Sign' */

  /* Sum: '<S127>/Add' incorporates:
   *  Constant: '<S127>/Constant'
   *  Product: '<S127>/Multiply'
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

  /* DeadZone: '<S126>/Dead Zone' */
  if (rtb_stick_yaw_raw > FMS_PARAM.StickDeadZone) {
    rtb_Product_idx_1 = rtb_stick_yaw_raw - FMS_PARAM.StickDeadZone;
  } else if (rtb_stick_yaw_raw >= -FMS_PARAM.StickDeadZone) {
    rtb_Product_idx_1 = 0.0F;
  } else {
    rtb_Product_idx_1 = rtb_stick_yaw_raw - (-FMS_PARAM.StickDeadZone);
  }

  /* End of DeadZone: '<S126>/Dead Zone' */

  /* Signum: '<S126>/Sign' */
  if (rtb_Product_idx_1 < 0.0F) {
    rtb_Product_idx_0 = -1.0F;
  } else if (rtb_Product_idx_1 > 0.0F) {
    rtb_Product_idx_0 = 1.0F;
  } else {
    rtb_Product_idx_0 = rtb_Product_idx_1;
  }

  /* End of Signum: '<S126>/Sign' */

  /* Sum: '<S126>/Add' incorporates:
   *  Constant: '<S126>/Constant'
   *  Product: '<S126>/Multiply'
   */
  rtb_Product_idx_0 = rtb_Product_idx_0 * FMS_PARAM.StickDeadZone +
    rtb_Product_idx_1;

  /* Trigonometry: '<S131>/TrigoFcn1' incorporates:
   *  Inport: '<Root>/INS_Output'
   */
  rtb_Product_idx_1 = arm_cos_f32(FMS_U.INS_Output.psi);

  /* SignalConversion: '<S131>/ConcatBufferAtVecConcentateIn1' */
  rtb_M_z[0] = rtb_Product_idx_1;

  /* Trigonometry: '<S131>/TrigoFcn' incorporates:
   *  Inport: '<Root>/INS_Output'
   */
  rtb_TrigoFcn = arm_sin_f32(FMS_U.INS_Output.psi);

  /* Gain: '<S131>/Gain' */
  rtb_M_z[1] = -rtb_TrigoFcn;

  /* SignalConversion: '<S131>/ConcatBufferAtVecConcentateIn3' incorporates:
   *  Constant: '<S131>/Constant1'
   */
  rtb_M_z[2] = 0.0F;

  /* SignalConversion: '<S131>/ConcatBufferAtVecConcentate2In1' */
  rtb_M_z[3] = rtb_TrigoFcn;

  /* SignalConversion: '<S131>/ConcatBufferAtVecConcentate2In2' */
  rtb_M_z[4] = rtb_Product_idx_1;

  /* SignalConversion: '<S131>/ConcatBufferAtVecConcentate2In3' incorporates:
   *  Constant: '<S131>/Constant1'
   */
  rtb_M_z[5] = 0.0F;

  /* SignalConversion: '<S131>/ConcatBufferAtVecConcentate1In3' */
  rtb_M_z[6] = FMS_ConstB.VecConcentate3[0];
  rtb_M_z[7] = FMS_ConstB.VecConcentate3[1];
  rtb_M_z[8] = FMS_ConstB.VecConcentate3[2];

  /* SwitchCase: '<S1>/Switch Case' incorporates:
   *  Saturate: '<S100>/Saturation'
   */
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
       *  Delay: '<S116>/Delay'
       *  Delay: '<S117>/Delay'
       *  Delay: '<S94>/Delay'
       *  DiscreteIntegrator: '<S109>/Integrator'
       *  DiscreteIntegrator: '<S109>/Integrator1'
       *  DiscreteIntegrator: '<S89>/Integrator'
       *  DiscreteIntegrator: '<S89>/Integrator1'
       *  UnitDelay: '<S114>/Delay Input1'
       *  UnitDelay: '<S115>/Delay Input1'
       *  UnitDelay: '<S84>/Delay Input1'
       *  UnitDelay: '<S85>/Delay Input1'
       *
       * Block description for '<S114>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S115>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S84>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S85>/Delay Input1':
       *
       *  Store in Global RAM
       */
      FMS_DW.Integrator1_DSTATE_c1 = 0.0F;
      FMS_DW.DelayInput1_DSTATE_iu = false;
      FMS_DW.icLoad_f = 1U;
      FMS_DW.DelayInput1_DSTATE_pv = false;
      FMS_DW.icLoad_a = 1U;
      FMS_DW.Integrator1_DSTATE_c[0] = 0.0F;
      FMS_DW.Integrator_DSTATE_f[0] = 0.0F;
      FMS_DW.Integrator1_DSTATE_c[1] = 0.0F;
      FMS_DW.Integrator_DSTATE_f[1] = 0.0F;
      FMS_DW.Integrator1_DSTATE_c[2] = 0.0F;
      FMS_DW.Integrator_DSTATE_f[2] = 0.0F;
      FMS_DW.DelayInput1_DSTATE_h = false;
      FMS_DW.DelayInput1_DSTATE_o = false;
      FMS_DW.icLoad_o = 1U;
      FMS_DW.Integrator_DSTATE_m = 0.0F;

      /* End of InitializeConditions for SubSystem: '<S1>/Position_Mode' */

      /* SystemReset for IfAction SubSystem: '<S1>/Position_Mode' incorporates:
       *  ActionPort: '<S8>/Action Port'
       */
      /* SystemReset for SwitchCase: '<S1>/Switch Case' incorporates:
       *  Chart: '<S80>/Motion_State'
       *  Chart: '<S99>/XY_Motion_State'
       *  Chart: '<S99>/Z_Motion_State'
       */
      FMS_Motion_State_Reset(&FMS_DW.sf_Motion_State);
      FMS_DW.temporalCounter_i1_b = 0U;
      FMS_DW.is_active_c7_FMS = 0U;
      FMS_DW.is_c7_FMS = FMS_IN_NO_ACTIVE_CHILD_h;
      FMS_Z_Motion_State_Reset(&FMS_DW.sf_Z_Motion_State);

      /* End of SystemReset for SubSystem: '<S1>/Position_Mode' */
    }

    /* Outputs for IfAction SubSystem: '<S1>/Position_Mode' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Outport: '<Root>/FMS_Output' incorporates:
     *  BusAssignment: '<S3>/Bus Assignment'
     *  BusAssignment: '<S8>/Bus Assignment'
     *  Constant: '<S8>/Constant'
     *  DiscreteIntegrator: '<S109>/Integrator1'
     *  DiscreteIntegrator: '<S140>/Discrete-Time Integrator'
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
    FMS_Y.FMS_Output.u_cmd = FMS_DW.Integrator1_DSTATE_c[0];
    FMS_Y.FMS_Output.v_cmd = FMS_DW.Integrator1_DSTATE_c[1];
    FMS_Y.FMS_Output.w_cmd = FMS_DW.Integrator1_DSTATE_c[2];

    /* Saturate: '<S80>/Saturation1' */
    if (FMS_DW.Integrator1_DSTATE_c1 > FMS_PARAM.YAW_RATE_LIM) {
      /* Outport: '<Root>/FMS_Output' incorporates:
       *  BusAssignment: '<S8>/Bus Assignment'
       */
      FMS_Y.FMS_Output.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
    } else if (FMS_DW.Integrator1_DSTATE_c1 < -FMS_PARAM.YAW_RATE_LIM) {
      /* Outport: '<Root>/FMS_Output' incorporates:
       *  BusAssignment: '<S8>/Bus Assignment'
       */
      FMS_Y.FMS_Output.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
    } else {
      /* Outport: '<Root>/FMS_Output' incorporates:
       *  BusAssignment: '<S8>/Bus Assignment'
       */
      FMS_Y.FMS_Output.psi_rate_cmd = FMS_DW.Integrator1_DSTATE_c1;
    }

    /* End of Saturate: '<S80>/Saturation1' */

    /* Chart: '<S80>/Motion_State' incorporates:
     *  Abs: '<S91>/Abs'
     *  Constant: '<S98>/Constant'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S98>/Compare'
     */
    FMS_Motion_State(rtb_Product_idx_0 != 0.0F, fabsf(FMS_U.INS_Output.r),
                     &rtb_state_mp, &FMS_DW.sf_Motion_State);

    /* Logic: '<S102>/Logical Operator' incorporates:
     *  Constant: '<S124>/Constant'
     *  RelationalOperator: '<S124>/Compare'
     */
    rtb_FixPtRelationalOperator = ((rtb_Add_d != 0.0F) || (rtb_Add_m != 0.0F));

    /* Chart: '<S99>/XY_Motion_State' incorporates:
     *  Inport: '<Root>/INS_Output'
     *  Math: '<S101>/Math Function'
     *  Math: '<S101>/Math Function1'
     *  Sqrt: '<S101>/Sqrt'
     *  Sum: '<S101>/Add'
     */
    if (FMS_DW.temporalCounter_i1_b < 1023U) {
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
            (FMS_DW.temporalCounter_i1_b >= 625U)) {
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

    /* End of Chart: '<S99>/XY_Motion_State' */

    /* RelationalOperator: '<S112>/Compare' incorporates:
     *  Constant: '<S112>/Constant'
     */
    rtb_FixPtRelationalOperator = (i == 2);

    /* Delay: '<S116>/Delay' incorporates:
     *  Inport: '<Root>/INS_Output'
     *  SignalConversion: '<S116>/TmpSignal ConversionAtDelayInport2'
     */
    if (FMS_DW.icLoad_f != 0) {
      FMS_DW.Delay_DSTATE_pp[0] = FMS_U.INS_Output.x_R;
      FMS_DW.Delay_DSTATE_pp[1] = FMS_U.INS_Output.y_R;
    }

    /* End of Delay: '<S116>/Delay' */

    /* Switch: '<S116>/Switch1' incorporates:
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S114>/FixPt Relational Operator'
     *  SignalConversion: '<S116>/TmpSignal ConversionAtDelayInport2'
     *  UnitDelay: '<S114>/Delay Input1'
     *
     * Block description for '<S114>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if ((int32_T)rtb_FixPtRelationalOperator > (int32_T)
        FMS_DW.DelayInput1_DSTATE_iu) {
      FMS_DW.Delay_DSTATE_pp[0] = FMS_U.INS_Output.x_R;
      FMS_DW.Delay_DSTATE_pp[1] = FMS_U.INS_Output.y_R;
    }

    /* End of Switch: '<S116>/Switch1' */

    /* Chart: '<S99>/Z_Motion_State' incorporates:
     *  Constant: '<S125>/Constant'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S125>/Compare'
     */
    FMS_Z_Motion_State(rtb_Product_idx_2 != 0.0F, FMS_U.INS_Output.vd,
                       &rtb_state_a, &FMS_DW.sf_Z_Motion_State);

    /* RelationalOperator: '<S113>/Compare' incorporates:
     *  Constant: '<S113>/Constant'
     */
    rtb_Compare_nq = (rtb_state_a == 2.0);

    /* Delay: '<S117>/Delay' incorporates:
     *  Gain: '<S111>/Gain'
     *  Inport: '<Root>/INS_Output'
     */
    if (FMS_DW.icLoad_a != 0) {
      FMS_DW.Delay_DSTATE_n = -FMS_U.INS_Output.h_R;
    }

    /* End of Delay: '<S117>/Delay' */

    /* Switch: '<S117>/Switch1' incorporates:
     *  Gain: '<S111>/Gain'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S115>/FixPt Relational Operator'
     *  UnitDelay: '<S115>/Delay Input1'
     *
     * Block description for '<S115>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if ((int32_T)rtb_Compare_nq > (int32_T)FMS_DW.DelayInput1_DSTATE_pv) {
      FMS_DW.Delay_DSTATE_n = -FMS_U.INS_Output.h_R;
    }

    /* End of Switch: '<S117>/Switch1' */

    /* Sum: '<S110>/Sum' incorporates:
     *  Gain: '<S111>/Gain'
     *  Inport: '<Root>/INS_Output'
     */
    rtb_stick_roll_raw = FMS_DW.Delay_DSTATE_pp[0] - FMS_U.INS_Output.x_R;
    rtb_stick_pitch_raw = FMS_DW.Delay_DSTATE_pp[1] - FMS_U.INS_Output.y_R;
    rtb_stick_throttle_raw = FMS_DW.Delay_DSTATE_n - (-FMS_U.INS_Output.h_R);

    /* Product: '<S110>/Multiply' */
    for (i_0 = 0; i_0 < 3; i_0++) {
      rtb_Multiply_a[i_0] = rtb_M_z[i_0 + 6] * rtb_stick_throttle_raw +
        (rtb_M_z[i_0 + 3] * rtb_stick_pitch_raw + rtb_M_z[i_0] *
         rtb_stick_roll_raw);
    }

    /* End of Product: '<S110>/Multiply' */

    /* Switch: '<S100>/Switch' incorporates:
     *  Constant: '<S105>/Constant'
     *  Constant: '<S118>/Constant'
     *  DeadZone: '<S120>/Dead Zone'
     *  Gain: '<S107>/Gain2'
     *  RelationalOperator: '<S105>/Compare'
     *  RelationalOperator: '<S118>/Compare'
     *  Switch: '<S108>/Switch1'
     */
    if (i == 2) {
      rtb_stick_roll_raw = FMS_PARAM.XY_P * rtb_Multiply_a[0];
      rtb_Add_m = FMS_PARAM.XY_P * rtb_Multiply_a[1];
    } else if (i == 1) {
      /* Switch: '<S108>/Switch1' */
      rtb_stick_roll_raw = 0.0F;
      rtb_Add_m = 0.0F;
    } else {
      if (rtb_Add_d > FMS_PARAM.StickDeadZone) {
        /* DeadZone: '<S120>/Dead Zone' incorporates:
         *  Switch: '<S108>/Switch1'
         */
        rtb_Add_d -= FMS_PARAM.StickDeadZone;
      } else if (rtb_Add_d >= -FMS_PARAM.StickDeadZone) {
        /* DeadZone: '<S120>/Dead Zone' incorporates:
         *  Switch: '<S108>/Switch1'
         */
        rtb_Add_d = 0.0F;
      } else {
        /* DeadZone: '<S120>/Dead Zone' incorporates:
         *  Switch: '<S108>/Switch1'
         */
        rtb_Add_d -= -FMS_PARAM.StickDeadZone;
      }

      /* Gain: '<S120>/Gain' incorporates:
       *  DeadZone: '<S120>/Dead Zone'
       *  Gain: '<S121>/Gain'
       *  Switch: '<S108>/Switch1'
       */
      rtb_stick_pitch_raw = 1.0F / (1.0F - FMS_PARAM.StickDeadZone);

      /* Switch: '<S108>/Switch1' incorporates:
       *  Gain: '<S108>/Gain1'
       *  Gain: '<S120>/Gain'
       */
      rtb_stick_roll_raw = rtb_stick_pitch_raw * rtb_Add_d *
        FMS_PARAM.VEL_XY_LIM;

      /* DeadZone: '<S121>/Dead Zone' incorporates:
       *  Switch: '<S108>/Switch1'
       */
      if (rtb_Add_m > FMS_PARAM.StickDeadZone) {
        rtb_Add_m -= FMS_PARAM.StickDeadZone;
      } else if (rtb_Add_m >= -FMS_PARAM.StickDeadZone) {
        rtb_Add_m = 0.0F;
      } else {
        rtb_Add_m -= -FMS_PARAM.StickDeadZone;
      }

      /* End of DeadZone: '<S121>/Dead Zone' */

      /* Switch: '<S108>/Switch1' incorporates:
       *  Gain: '<S108>/Gain5'
       *  Gain: '<S121>/Gain'
       */
      rtb_Add_m = rtb_stick_pitch_raw * rtb_Add_m * FMS_PARAM.VEL_XY_LIM;
    }

    /* End of Switch: '<S100>/Switch' */
    rtb_Add_d = rtb_stick_roll_raw;

    /* Saturate: '<S100>/Saturation' */
    if (rtb_stick_roll_raw > FMS_PARAM.VEL_XY_LIM) {
      rtb_Add_d = FMS_PARAM.VEL_XY_LIM;
    } else {
      if (rtb_stick_roll_raw < -FMS_PARAM.VEL_XY_LIM) {
        rtb_Add_d = -FMS_PARAM.VEL_XY_LIM;
      }
    }

    rtb_stick_roll_raw = rtb_Add_d;
    rtb_Add_d = rtb_Add_m;

    /* Saturate: '<S100>/Saturation' */
    if (rtb_Add_m > FMS_PARAM.VEL_XY_LIM) {
      rtb_Add_d = FMS_PARAM.VEL_XY_LIM;
    } else {
      if (rtb_Add_m < -FMS_PARAM.VEL_XY_LIM) {
        rtb_Add_d = -FMS_PARAM.VEL_XY_LIM;
      }
    }

    /* Switch: '<S100>/Switch1' incorporates:
     *  Constant: '<S106>/Constant'
     *  Constant: '<S119>/Constant'
     *  DeadZone: '<S122>/Dead Zone'
     *  Gain: '<S107>/Gain4'
     *  RelationalOperator: '<S106>/Compare'
     *  RelationalOperator: '<S119>/Compare'
     *  Switch: '<S108>/Switch2'
     */
    if (rtb_state_a == 2.0) {
      rtb_Add_m = FMS_PARAM.Z_P * rtb_Multiply_a[2];
    } else if (rtb_state_a == 1.0) {
      /* Switch: '<S108>/Switch2' incorporates:
       *  Constant: '<S108>/Constant1'
       */
      rtb_Add_m = 0.0F;
    } else {
      if (rtb_Product_idx_2 > FMS_PARAM.StickDeadZone) {
        /* DeadZone: '<S122>/Dead Zone' incorporates:
         *  Switch: '<S108>/Switch2'
         */
        rtb_Product_idx_2 -= FMS_PARAM.StickDeadZone;
      } else if (rtb_Product_idx_2 >= -FMS_PARAM.StickDeadZone) {
        /* DeadZone: '<S122>/Dead Zone' incorporates:
         *  Switch: '<S108>/Switch2'
         */
        rtb_Product_idx_2 = 0.0F;
      } else {
        /* DeadZone: '<S122>/Dead Zone' incorporates:
         *  Switch: '<S108>/Switch2'
         */
        rtb_Product_idx_2 -= -FMS_PARAM.StickDeadZone;
      }

      /* Switch: '<S108>/Switch2' incorporates:
       *  DeadZone: '<S122>/Dead Zone'
       *  Gain: '<S108>/Gain6'
       *  Gain: '<S122>/Gain'
       */
      rtb_Add_m = 1.0F / (1.0F - FMS_PARAM.StickDeadZone) * rtb_Product_idx_2 *
        -FMS_PARAM.VEL_Z_LIM;
    }

    /* End of Switch: '<S100>/Switch1' */

    /* Saturate: '<S100>/Saturation1' */
    if (rtb_Add_m > FMS_PARAM.VEL_Z_LIM) {
      rtb_Add_m = FMS_PARAM.VEL_Z_LIM;
    } else {
      if (rtb_Add_m < -FMS_PARAM.VEL_Z_LIM) {
        rtb_Add_m = -FMS_PARAM.VEL_Z_LIM;
      }
    }

    /* End of Saturate: '<S100>/Saturation1' */

    /* Product: '<S123>/Multiply1' incorporates:
     *  Constant: '<S123>/const1'
     *  DiscreteIntegrator: '<S109>/Integrator'
     */
    rtb_Multiply_a[0] = FMS_DW.Integrator_DSTATE_f[0] * 0.05F;
    rtb_Multiply_a[1] = FMS_DW.Integrator_DSTATE_f[1] * 0.05F;
    rtb_Multiply_a[2] = FMS_DW.Integrator_DSTATE_f[2] * 0.05F;

    /* Sum: '<S123>/Add' incorporates:
     *  DiscreteIntegrator: '<S109>/Integrator1'
     *  Sum: '<S109>/Subtract'
     */
    rtb_stick_pitch_raw = (FMS_DW.Integrator1_DSTATE_c[0] - rtb_stick_roll_raw)
      + rtb_Multiply_a[0];
    rtb_Add_d = (FMS_DW.Integrator1_DSTATE_c[1] - rtb_Add_d) + rtb_Multiply_a[1];
    rtb_Product_idx_2 = (FMS_DW.Integrator1_DSTATE_c[2] - rtb_Add_m) +
      rtb_Multiply_a[2];

    /* Signum: '<S123>/Sign' */
    if (rtb_stick_pitch_raw < 0.0F) {
      rtb_stick_roll_raw = -1.0F;
    } else if (rtb_stick_pitch_raw > 0.0F) {
      rtb_stick_roll_raw = 1.0F;
    } else {
      rtb_stick_roll_raw = rtb_stick_pitch_raw;
    }

    /* Sum: '<S123>/Add2' incorporates:
     *  Abs: '<S123>/Abs'
     *  Gain: '<S123>/Gain'
     *  Gain: '<S123>/Gain1'
     *  Product: '<S123>/Multiply2'
     *  Product: '<S123>/Multiply3'
     *  Signum: '<S123>/Sign'
     *  Sqrt: '<S123>/Sqrt'
     *  Sum: '<S123>/Add1'
     *  Sum: '<S123>/Subtract'
     */
    rtb_stick_roll_raw = (sqrtf((8.0F * fabsf(rtb_stick_pitch_raw) +
      FMS_ConstB.d_az) * FMS_ConstB.d_az) - FMS_ConstB.d_az) * 0.5F *
      rtb_stick_roll_raw + rtb_Multiply_a[0];

    /* Sum: '<S123>/Add3' incorporates:
     *  Signum: '<S123>/Sign'
     */
    rtb_Add_m = rtb_stick_pitch_raw + FMS_ConstB.d_az;

    /* Sum: '<S123>/Subtract1' incorporates:
     *  Signum: '<S123>/Sign'
     */
    rtb_stick_throttle_raw = rtb_stick_pitch_raw - FMS_ConstB.d_az;

    /* Signum: '<S123>/Sign1' */
    if (rtb_Add_m < 0.0F) {
      rtb_Add_m = -1.0F;
    } else {
      if (rtb_Add_m > 0.0F) {
        rtb_Add_m = 1.0F;
      }
    }

    /* Signum: '<S123>/Sign2' */
    if (rtb_stick_throttle_raw < 0.0F) {
      rtb_stick_throttle_raw = -1.0F;
    } else {
      if (rtb_stick_throttle_raw > 0.0F) {
        rtb_stick_throttle_raw = 1.0F;
      }
    }

    /* Sum: '<S123>/Add2' incorporates:
     *  Gain: '<S123>/Gain2'
     *  Product: '<S123>/Multiply4'
     *  Signum: '<S123>/Sign'
     *  Sum: '<S123>/Add4'
     *  Sum: '<S123>/Add5'
     *  Sum: '<S123>/Subtract2'
     */
    rtb_stick_pitch_raw = ((rtb_stick_pitch_raw - rtb_stick_roll_raw) +
      rtb_Multiply_a[0]) * ((rtb_Add_m - rtb_stick_throttle_raw) * 0.5F) +
      rtb_stick_roll_raw;

    /* Signum: '<S123>/Sign' */
    if (rtb_Add_d < 0.0F) {
      rtb_stick_roll_raw = -1.0F;
    } else if (rtb_Add_d > 0.0F) {
      rtb_stick_roll_raw = 1.0F;
    } else {
      rtb_stick_roll_raw = rtb_Add_d;
    }

    /* Sum: '<S123>/Add2' incorporates:
     *  Abs: '<S123>/Abs'
     *  Gain: '<S123>/Gain'
     *  Gain: '<S123>/Gain1'
     *  Product: '<S123>/Multiply2'
     *  Product: '<S123>/Multiply3'
     *  Signum: '<S123>/Sign'
     *  Sqrt: '<S123>/Sqrt'
     *  Sum: '<S123>/Add1'
     *  Sum: '<S123>/Subtract'
     */
    rtb_stick_roll_raw = (sqrtf((8.0F * fabsf(rtb_Add_d) + FMS_ConstB.d_az) *
      FMS_ConstB.d_az) - FMS_ConstB.d_az) * 0.5F * rtb_stick_roll_raw +
      rtb_Multiply_a[1];

    /* Sum: '<S123>/Add3' incorporates:
     *  Signum: '<S123>/Sign'
     */
    rtb_Add_m = rtb_Add_d + FMS_ConstB.d_az;

    /* Sum: '<S123>/Subtract1' incorporates:
     *  Signum: '<S123>/Sign'
     */
    rtb_stick_throttle_raw = rtb_Add_d - FMS_ConstB.d_az;

    /* Signum: '<S123>/Sign1' */
    if (rtb_Add_m < 0.0F) {
      rtb_Add_m = -1.0F;
    } else {
      if (rtb_Add_m > 0.0F) {
        rtb_Add_m = 1.0F;
      }
    }

    /* Signum: '<S123>/Sign2' */
    if (rtb_stick_throttle_raw < 0.0F) {
      rtb_stick_throttle_raw = -1.0F;
    } else {
      if (rtb_stick_throttle_raw > 0.0F) {
        rtb_stick_throttle_raw = 1.0F;
      }
    }

    /* Sum: '<S123>/Add2' incorporates:
     *  Gain: '<S123>/Gain2'
     *  Product: '<S123>/Multiply4'
     *  Signum: '<S123>/Sign'
     *  Sum: '<S123>/Add4'
     *  Sum: '<S123>/Add5'
     *  Sum: '<S123>/Subtract2'
     */
    rtb_Add_d = ((rtb_Add_d - rtb_stick_roll_raw) + rtb_Multiply_a[1]) *
      ((rtb_Add_m - rtb_stick_throttle_raw) * 0.5F) + rtb_stick_roll_raw;

    /* Signum: '<S123>/Sign' */
    if (rtb_Product_idx_2 < 0.0F) {
      rtb_stick_roll_raw = -1.0F;
    } else if (rtb_Product_idx_2 > 0.0F) {
      rtb_stick_roll_raw = 1.0F;
    } else {
      rtb_stick_roll_raw = rtb_Product_idx_2;
    }

    /* Sum: '<S123>/Add2' incorporates:
     *  Abs: '<S123>/Abs'
     *  Gain: '<S123>/Gain'
     *  Gain: '<S123>/Gain1'
     *  Product: '<S123>/Multiply2'
     *  Product: '<S123>/Multiply3'
     *  Signum: '<S123>/Sign'
     *  Sqrt: '<S123>/Sqrt'
     *  Sum: '<S123>/Add1'
     *  Sum: '<S123>/Subtract'
     */
    rtb_stick_roll_raw = (sqrtf((8.0F * fabsf(rtb_Product_idx_2) +
      FMS_ConstB.d_az) * FMS_ConstB.d_az) - FMS_ConstB.d_az) * 0.5F *
      rtb_stick_roll_raw + rtb_Multiply_a[2];

    /* Sum: '<S123>/Add3' incorporates:
     *  Signum: '<S123>/Sign'
     */
    rtb_Add_m = rtb_Product_idx_2 + FMS_ConstB.d_az;

    /* Sum: '<S123>/Subtract1' incorporates:
     *  Signum: '<S123>/Sign'
     */
    rtb_stick_throttle_raw = rtb_Product_idx_2 - FMS_ConstB.d_az;

    /* Signum: '<S123>/Sign1' */
    if (rtb_Add_m < 0.0F) {
      rtb_Add_m = -1.0F;
    } else {
      if (rtb_Add_m > 0.0F) {
        rtb_Add_m = 1.0F;
      }
    }

    /* Signum: '<S123>/Sign2' */
    if (rtb_stick_throttle_raw < 0.0F) {
      rtb_stick_throttle_raw = -1.0F;
    } else {
      if (rtb_stick_throttle_raw > 0.0F) {
        rtb_stick_throttle_raw = 1.0F;
      }
    }

    /* Sum: '<S123>/Add5' incorporates:
     *  Gain: '<S123>/Gain2'
     *  Product: '<S123>/Multiply4'
     *  Signum: '<S123>/Sign'
     *  Sum: '<S123>/Add2'
     *  Sum: '<S123>/Add4'
     *  Sum: '<S123>/Subtract2'
     */
    rtb_stick_roll_raw += ((rtb_Product_idx_2 - rtb_stick_roll_raw) +
      rtb_Multiply_a[2]) * ((rtb_Add_m - rtb_stick_throttle_raw) * 0.5F);

    /* RelationalOperator: '<S82>/Compare' incorporates:
     *  Constant: '<S82>/Constant'
     */
    rtb_Compare_if = (rtb_state_mp == 2.0);

    /* RelationalOperator: '<S83>/Compare' incorporates:
     *  BusAssignment: '<S3>/Bus Assignment'
     *  Constant: '<S83>/Constant'
     */
    rtb_Compare_px = (FMS_DW.Delay_DSTATE_pi == 2);

    /* Delay: '<S94>/Delay' incorporates:
     *  Inport: '<Root>/INS_Output'
     */
    if (FMS_DW.icLoad_o != 0) {
      FMS_DW.Delay_DSTATE_k = FMS_U.INS_Output.psi;
    }

    /* End of Delay: '<S94>/Delay' */

    /* Switch: '<S94>/Switch1' incorporates:
     *  Inport: '<Root>/INS_Output'
     *  Logic: '<S80>/Logical Operator'
     *  RelationalOperator: '<S84>/FixPt Relational Operator'
     *  RelationalOperator: '<S85>/FixPt Relational Operator'
     *  UnitDelay: '<S84>/Delay Input1'
     *  UnitDelay: '<S85>/Delay Input1'
     *
     * Block description for '<S84>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S85>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if (((int32_T)rtb_Compare_px > (int32_T)FMS_DW.DelayInput1_DSTATE_o) ||
        ((int32_T)rtb_Compare_if > (int32_T)FMS_DW.DelayInput1_DSTATE_h)) {
      FMS_DW.Delay_DSTATE_k = FMS_U.INS_Output.psi;
    }

    /* End of Switch: '<S94>/Switch1' */

    /* Switch: '<S80>/Switch' incorporates:
     *  Constant: '<S95>/Constant'
     *  DeadZone: '<S96>/Dead Zone'
     *  Gain: '<S86>/Gain2'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S95>/Compare'
     *  Sum: '<S92>/Sum'
     *  Switch: '<S87>/Switch1'
     */
    if (rtb_Compare_if) {
      rtb_Add_m = (FMS_DW.Delay_DSTATE_k - FMS_U.INS_Output.psi) *
        FMS_PARAM.YAW_P;
    } else if (rtb_state_mp == 1.0) {
      /* Switch: '<S87>/Switch1' incorporates:
       *  Constant: '<S87>/Constant'
       */
      rtb_Add_m = 0.0F;
    } else {
      if (rtb_Product_idx_0 > FMS_PARAM.StickDeadZone) {
        /* DeadZone: '<S96>/Dead Zone' incorporates:
         *  Switch: '<S87>/Switch1'
         */
        rtb_Product_idx_0 -= FMS_PARAM.StickDeadZone;
      } else if (rtb_Product_idx_0 >= -FMS_PARAM.StickDeadZone) {
        /* DeadZone: '<S96>/Dead Zone' incorporates:
         *  Switch: '<S87>/Switch1'
         */
        rtb_Product_idx_0 = 0.0F;
      } else {
        /* DeadZone: '<S96>/Dead Zone' incorporates:
         *  Switch: '<S87>/Switch1'
         */
        rtb_Product_idx_0 -= -FMS_PARAM.StickDeadZone;
      }

      /* Switch: '<S87>/Switch1' incorporates:
       *  DeadZone: '<S96>/Dead Zone'
       *  Gain: '<S87>/Gain1'
       *  Gain: '<S96>/Gain'
       */
      rtb_Add_m = 1.0F / (1.0F - FMS_PARAM.StickDeadZone) * rtb_Product_idx_0 *
        FMS_PARAM.YAW_RATE_LIM;
    }

    /* End of Switch: '<S80>/Switch' */

    /* Sum: '<S89>/Subtract' incorporates:
     *  DiscreteIntegrator: '<S89>/Integrator1'
     */
    rtb_Product_idx_0 = FMS_DW.Integrator1_DSTATE_c1 - rtb_Add_m;

    /* Product: '<S97>/Multiply1' incorporates:
     *  Constant: '<S97>/const1'
     *  DiscreteIntegrator: '<S89>/Integrator'
     */
    rtb_Add_m = FMS_DW.Integrator_DSTATE_m * 0.04F;

    /* Sum: '<S97>/Add' */
    rtb_Product_idx_0 += rtb_Add_m;

    /* Signum: '<S97>/Sign' */
    if (rtb_Product_idx_0 < 0.0F) {
      rtb_Product_idx_2 = -1.0F;
    } else if (rtb_Product_idx_0 > 0.0F) {
      rtb_Product_idx_2 = 1.0F;
    } else {
      rtb_Product_idx_2 = rtb_Product_idx_0;
    }

    /* End of Signum: '<S97>/Sign' */

    /* Sum: '<S97>/Add2' incorporates:
     *  Abs: '<S97>/Abs'
     *  Gain: '<S97>/Gain'
     *  Gain: '<S97>/Gain1'
     *  Product: '<S97>/Multiply2'
     *  Product: '<S97>/Multiply3'
     *  Sqrt: '<S97>/Sqrt'
     *  Sum: '<S97>/Add1'
     *  Sum: '<S97>/Subtract'
     */
    rtb_Product_idx_2 = (sqrtf((8.0F * fabsf(rtb_Product_idx_0) + FMS_ConstB.d_h)
      * FMS_ConstB.d_h) - FMS_ConstB.d_h) * 0.5F * rtb_Product_idx_2 + rtb_Add_m;

    /* Sum: '<S97>/Add4' */
    rtb_stick_throttle_raw = (rtb_Product_idx_0 - rtb_Product_idx_2) + rtb_Add_m;

    /* Sum: '<S97>/Add3' */
    rtb_Add_m = rtb_Product_idx_0 + FMS_ConstB.d_h;

    /* Sum: '<S97>/Subtract1' */
    rtb_Product_idx_0 -= FMS_ConstB.d_h;

    /* Signum: '<S97>/Sign1' */
    if (rtb_Add_m < 0.0F) {
      rtb_Add_m = -1.0F;
    } else {
      if (rtb_Add_m > 0.0F) {
        rtb_Add_m = 1.0F;
      }
    }

    /* End of Signum: '<S97>/Sign1' */

    /* Signum: '<S97>/Sign2' */
    if (rtb_Product_idx_0 < 0.0F) {
      rtb_Product_idx_0 = -1.0F;
    } else {
      if (rtb_Product_idx_0 > 0.0F) {
        rtb_Product_idx_0 = 1.0F;
      }
    }

    /* End of Signum: '<S97>/Sign2' */

    /* Sum: '<S97>/Add5' incorporates:
     *  Gain: '<S97>/Gain2'
     *  Product: '<S97>/Multiply4'
     *  Sum: '<S97>/Subtract2'
     */
    rtb_Product_idx_2 += (rtb_Add_m - rtb_Product_idx_0) * 0.5F *
      rtb_stick_throttle_raw;

    /* Update for DiscreteIntegrator: '<S89>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S89>/Integrator'
     */
    FMS_DW.Integrator1_DSTATE_c1 += 0.004F * FMS_DW.Integrator_DSTATE_m;

    /* Update for UnitDelay: '<S114>/Delay Input1'
     *
     * Block description for '<S114>/Delay Input1':
     *
     *  Store in Global RAM
     */
    FMS_DW.DelayInput1_DSTATE_iu = rtb_FixPtRelationalOperator;

    /* Update for Delay: '<S116>/Delay' */
    FMS_DW.icLoad_f = 0U;

    /* Update for UnitDelay: '<S115>/Delay Input1'
     *
     * Block description for '<S115>/Delay Input1':
     *
     *  Store in Global RAM
     */
    FMS_DW.DelayInput1_DSTATE_pv = rtb_Compare_nq;

    /* Update for Delay: '<S117>/Delay' */
    FMS_DW.icLoad_a = 0U;

    /* Update for DiscreteIntegrator: '<S109>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S109>/Integrator'
     */
    FMS_DW.Integrator1_DSTATE_c[0] += 0.004F * FMS_DW.Integrator_DSTATE_f[0];

    /* Signum: '<S123>/Sign3' incorporates:
     *  Product: '<S123>/Divide'
     *  Sum: '<S123>/Add6'
     */
    rtb_Add_m = rtb_stick_pitch_raw + FMS_ConstB.d_az;

    /* Signum: '<S123>/Sign4' incorporates:
     *  Product: '<S123>/Divide'
     *  Sum: '<S123>/Subtract3'
     */
    rtb_Product_idx_0 = rtb_stick_pitch_raw - FMS_ConstB.d_az;

    /* Signum: '<S123>/Sign5' incorporates:
     *  Product: '<S123>/Divide'
     */
    if (rtb_stick_pitch_raw < 0.0F) {
      rtb_stick_throttle_raw = -1.0F;
    } else if (rtb_stick_pitch_raw > 0.0F) {
      rtb_stick_throttle_raw = 1.0F;
    } else {
      rtb_stick_throttle_raw = rtb_stick_pitch_raw;
    }

    /* Signum: '<S123>/Sign3' */
    if (rtb_Add_m < 0.0F) {
      rtb_Add_m = -1.0F;
    } else {
      if (rtb_Add_m > 0.0F) {
        rtb_Add_m = 1.0F;
      }
    }

    /* Signum: '<S123>/Sign4' */
    if (rtb_Product_idx_0 < 0.0F) {
      rtb_Product_idx_0 = -1.0F;
    } else {
      if (rtb_Product_idx_0 > 0.0F) {
        rtb_Product_idx_0 = 1.0F;
      }
    }

    /* Signum: '<S123>/Sign6' incorporates:
     *  Product: '<S123>/Divide'
     */
    if (rtb_stick_pitch_raw < 0.0F) {
      rtb_TrigoFcn = -1.0F;
    } else if (rtb_stick_pitch_raw > 0.0F) {
      rtb_TrigoFcn = 1.0F;
    } else {
      rtb_TrigoFcn = rtb_stick_pitch_raw;
    }

    /* Update for DiscreteIntegrator: '<S109>/Integrator' incorporates:
     *  Constant: '<S123>/const'
     *  Gain: '<S123>/Gain3'
     *  Product: '<S123>/Divide'
     *  Product: '<S123>/Multiply5'
     *  Product: '<S123>/Multiply6'
     *  Sum: '<S123>/Subtract4'
     *  Sum: '<S123>/Subtract5'
     *  Sum: '<S123>/Subtract6'
     */
    FMS_DW.Integrator_DSTATE_f[0] += ((rtb_stick_pitch_raw / FMS_ConstB.d_az -
      rtb_stick_throttle_raw) * FMS_ConstB.Gain4_o * ((rtb_Add_m -
      rtb_Product_idx_0) * 0.5F) - rtb_TrigoFcn * 39.224F) * 0.004F;

    /* Update for DiscreteIntegrator: '<S109>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S109>/Integrator'
     */
    FMS_DW.Integrator1_DSTATE_c[1] += 0.004F * FMS_DW.Integrator_DSTATE_f[1];

    /* Signum: '<S123>/Sign3' incorporates:
     *  Product: '<S123>/Divide'
     *  Sum: '<S123>/Add6'
     */
    rtb_Add_m = rtb_Add_d + FMS_ConstB.d_az;

    /* Signum: '<S123>/Sign4' incorporates:
     *  Product: '<S123>/Divide'
     *  Sum: '<S123>/Subtract3'
     */
    rtb_Product_idx_0 = rtb_Add_d - FMS_ConstB.d_az;

    /* Signum: '<S123>/Sign5' incorporates:
     *  Product: '<S123>/Divide'
     */
    if (rtb_Add_d < 0.0F) {
      rtb_stick_pitch_raw = -1.0F;
    } else if (rtb_Add_d > 0.0F) {
      rtb_stick_pitch_raw = 1.0F;
    } else {
      rtb_stick_pitch_raw = rtb_Add_d;
    }

    /* Signum: '<S123>/Sign3' */
    if (rtb_Add_m < 0.0F) {
      rtb_Add_m = -1.0F;
    } else {
      if (rtb_Add_m > 0.0F) {
        rtb_Add_m = 1.0F;
      }
    }

    /* Signum: '<S123>/Sign4' */
    if (rtb_Product_idx_0 < 0.0F) {
      rtb_Product_idx_0 = -1.0F;
    } else {
      if (rtb_Product_idx_0 > 0.0F) {
        rtb_Product_idx_0 = 1.0F;
      }
    }

    /* Signum: '<S123>/Sign6' incorporates:
     *  Product: '<S123>/Divide'
     */
    if (rtb_Add_d < 0.0F) {
      rtb_stick_throttle_raw = -1.0F;
    } else if (rtb_Add_d > 0.0F) {
      rtb_stick_throttle_raw = 1.0F;
    } else {
      rtb_stick_throttle_raw = rtb_Add_d;
    }

    /* Update for DiscreteIntegrator: '<S109>/Integrator' incorporates:
     *  Constant: '<S123>/const'
     *  Gain: '<S123>/Gain3'
     *  Product: '<S123>/Divide'
     *  Product: '<S123>/Multiply5'
     *  Product: '<S123>/Multiply6'
     *  Sum: '<S123>/Subtract4'
     *  Sum: '<S123>/Subtract5'
     *  Sum: '<S123>/Subtract6'
     */
    FMS_DW.Integrator_DSTATE_f[1] += ((rtb_Add_d / FMS_ConstB.d_az -
      rtb_stick_pitch_raw) * FMS_ConstB.Gain4_o * ((rtb_Add_m -
      rtb_Product_idx_0) * 0.5F) - rtb_stick_throttle_raw * 39.224F) * 0.004F;

    /* Update for DiscreteIntegrator: '<S109>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S109>/Integrator'
     */
    FMS_DW.Integrator1_DSTATE_c[2] += 0.004F * FMS_DW.Integrator_DSTATE_f[2];

    /* Signum: '<S123>/Sign3' incorporates:
     *  Sum: '<S123>/Add6'
     */
    rtb_Add_m = rtb_stick_roll_raw + FMS_ConstB.d_az;

    /* Signum: '<S123>/Sign4' incorporates:
     *  Sum: '<S123>/Subtract3'
     */
    rtb_Product_idx_0 = rtb_stick_roll_raw - FMS_ConstB.d_az;

    /* Signum: '<S123>/Sign5' */
    if (rtb_stick_roll_raw < 0.0F) {
      rtb_stick_pitch_raw = -1.0F;
    } else if (rtb_stick_roll_raw > 0.0F) {
      rtb_stick_pitch_raw = 1.0F;
    } else {
      rtb_stick_pitch_raw = rtb_stick_roll_raw;
    }

    /* Signum: '<S123>/Sign3' */
    if (rtb_Add_m < 0.0F) {
      rtb_Add_m = -1.0F;
    } else {
      if (rtb_Add_m > 0.0F) {
        rtb_Add_m = 1.0F;
      }
    }

    /* Signum: '<S123>/Sign4' */
    if (rtb_Product_idx_0 < 0.0F) {
      rtb_Product_idx_0 = -1.0F;
    } else {
      if (rtb_Product_idx_0 > 0.0F) {
        rtb_Product_idx_0 = 1.0F;
      }
    }

    /* Signum: '<S123>/Sign6' */
    if (rtb_stick_roll_raw < 0.0F) {
      rtb_Add_d = -1.0F;
    } else if (rtb_stick_roll_raw > 0.0F) {
      rtb_Add_d = 1.0F;
    } else {
      rtb_Add_d = rtb_stick_roll_raw;
    }

    /* Update for DiscreteIntegrator: '<S109>/Integrator' incorporates:
     *  Constant: '<S123>/const'
     *  Gain: '<S123>/Gain3'
     *  Product: '<S123>/Divide'
     *  Product: '<S123>/Multiply5'
     *  Product: '<S123>/Multiply6'
     *  Sum: '<S123>/Subtract4'
     *  Sum: '<S123>/Subtract5'
     *  Sum: '<S123>/Subtract6'
     */
    FMS_DW.Integrator_DSTATE_f[2] += ((rtb_stick_roll_raw / FMS_ConstB.d_az -
      rtb_stick_pitch_raw) * FMS_ConstB.Gain4_o * ((rtb_Add_m -
      rtb_Product_idx_0) * 0.5F) - rtb_Add_d * 39.224F) * 0.004F;

    /* Update for UnitDelay: '<S84>/Delay Input1'
     *
     * Block description for '<S84>/Delay Input1':
     *
     *  Store in Global RAM
     */
    FMS_DW.DelayInput1_DSTATE_h = rtb_Compare_if;

    /* Update for UnitDelay: '<S85>/Delay Input1'
     *
     * Block description for '<S85>/Delay Input1':
     *
     *  Store in Global RAM
     */
    FMS_DW.DelayInput1_DSTATE_o = rtb_Compare_px;

    /* Update for Delay: '<S94>/Delay' */
    FMS_DW.icLoad_o = 0U;

    /* Signum: '<S97>/Sign6' incorporates:
     *  Signum: '<S97>/Sign5'
     */
    if (rtb_Product_idx_2 < 0.0F) {
      rtb_Add_d = -1.0F;

      /* Signum: '<S97>/Sign5' */
      rtb_Add4_i = -1.0F;
    } else if (rtb_Product_idx_2 > 0.0F) {
      rtb_Add_d = 1.0F;

      /* Signum: '<S97>/Sign5' */
      rtb_Add4_i = 1.0F;
    } else {
      rtb_Add_d = rtb_Product_idx_2;

      /* Signum: '<S97>/Sign5' */
      rtb_Add4_i = rtb_Product_idx_2;
    }

    /* End of Signum: '<S97>/Sign6' */

    /* Sum: '<S97>/Add6' */
    rtb_Add_m = rtb_Product_idx_2 + FMS_ConstB.d_h;

    /* Sum: '<S97>/Subtract3' */
    rtb_Product_idx_0 = rtb_Product_idx_2 - FMS_ConstB.d_h;

    /* Signum: '<S97>/Sign3' */
    if (rtb_Add_m < 0.0F) {
      rtb_Add_m = -1.0F;
    } else {
      if (rtb_Add_m > 0.0F) {
        rtb_Add_m = 1.0F;
      }
    }

    /* End of Signum: '<S97>/Sign3' */

    /* Signum: '<S97>/Sign4' */
    if (rtb_Product_idx_0 < 0.0F) {
      rtb_Product_idx_0 = -1.0F;
    } else {
      if (rtb_Product_idx_0 > 0.0F) {
        rtb_Product_idx_0 = 1.0F;
      }
    }

    /* End of Signum: '<S97>/Sign4' */

    /* Update for DiscreteIntegrator: '<S89>/Integrator' incorporates:
     *  Constant: '<S97>/const'
     *  Gain: '<S97>/Gain3'
     *  Product: '<S97>/Divide'
     *  Product: '<S97>/Multiply5'
     *  Product: '<S97>/Multiply6'
     *  Sum: '<S97>/Subtract4'
     *  Sum: '<S97>/Subtract5'
     *  Sum: '<S97>/Subtract6'
     */
    FMS_DW.Integrator_DSTATE_m += ((rtb_Product_idx_2 / FMS_ConstB.d_h -
      rtb_Add4_i) * FMS_ConstB.Gain4_ea * ((rtb_Add_m - rtb_Product_idx_0) *
      0.5F) - rtb_Add_d * 6.28318548F) * 0.004F;

    /* End of Outputs for SubSystem: '<S1>/Position_Mode' */
    break;

   case 1:
    if (FMS_DW.SwitchCase_ActiveSubsystem != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S1>/Altitude_Hold_Mode' incorporates:
       *  ActionPort: '<S5>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S1>/Switch Case' incorporates:
       *  Delay: '<S33>/Delay'
       *  Delay: '<S51>/Delay'
       *  DiscreteIntegrator: '<S17>/Integrator'
       *  DiscreteIntegrator: '<S17>/Integrator1'
       *  DiscreteIntegrator: '<S18>/Integrator'
       *  DiscreteIntegrator: '<S18>/Integrator1'
       *  DiscreteIntegrator: '<S28>/Integrator'
       *  DiscreteIntegrator: '<S28>/Integrator1'
       *  DiscreteIntegrator: '<S46>/Integrator'
       *  DiscreteIntegrator: '<S46>/Integrator1'
       *  UnitDelay: '<S23>/Delay Input1'
       *  UnitDelay: '<S24>/Delay Input1'
       *  UnitDelay: '<S50>/Delay Input1'
       *
       * Block description for '<S23>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S24>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S50>/Delay Input1':
       *
       *  Store in Global RAM
       */
      FMS_DW.Integrator1_DSTATE_f = 0.0F;
      FMS_DW.Integrator1_DSTATE_a = 0.0F;
      FMS_DW.Integrator1_DSTATE_p = 0.0F;
      FMS_DW.Integrator1_DSTATE_d = 0.0F;
      FMS_DW.DelayInput1_DSTATE_p = false;
      FMS_DW.DelayInput1_DSTATE_j = false;
      FMS_DW.icLoad_i = 1U;
      FMS_DW.Integrator_DSTATE_o = 0.0F;
      FMS_DW.DelayInput1_DSTATE_a = false;
      FMS_DW.icLoad_d = 1U;
      FMS_DW.Integrator_DSTATE_g = 0.0F;
      FMS_DW.Integrator_DSTATE_b = 0.0F;
      FMS_DW.Integrator_DSTATE_gx = 0.0F;

      /* End of InitializeConditions for SubSystem: '<S1>/Altitude_Hold_Mode' */

      /* SystemReset for IfAction SubSystem: '<S1>/Altitude_Hold_Mode' incorporates:
       *  ActionPort: '<S5>/Action Port'
       */
      /* SystemReset for SwitchCase: '<S1>/Switch Case' incorporates:
       *  Chart: '<S15>/Motion_State'
       *  Chart: '<S38>/Z_Motion_State'
       */
      FMS_Motion_State_Reset(&FMS_DW.sf_Motion_State_c);
      FMS_Z_Motion_State_Reset(&FMS_DW.sf_Z_Motion_State_l);

      /* End of SystemReset for SubSystem: '<S1>/Altitude_Hold_Mode' */
    }

    /* Outputs for IfAction SubSystem: '<S1>/Altitude_Hold_Mode' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* Outport: '<Root>/FMS_Output' incorporates:
     *  BusAssignment: '<S3>/Bus Assignment'
     *  BusAssignment: '<S5>/Bus Assignment'
     *  Constant: '<S5>/Constant'
     *  DiscreteIntegrator: '<S140>/Discrete-Time Integrator'
     *  DiscreteIntegrator: '<S17>/Integrator1'
     *  DiscreteIntegrator: '<S18>/Integrator1'
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
    FMS_Y.FMS_Output.phi_cmd = FMS_DW.Integrator1_DSTATE_f;
    FMS_Y.FMS_Output.theta_cmd = FMS_DW.Integrator1_DSTATE_a;

    /* Saturate: '<S16>/Saturation' */
    if (FMS_DW.Integrator1_DSTATE_p > FMS_PARAM.VEL_Z_LIM) {
      /* Outport: '<Root>/FMS_Output' incorporates:
       *  BusAssignment: '<S5>/Bus Assignment'
       */
      FMS_Y.FMS_Output.w_cmd = FMS_PARAM.VEL_Z_LIM;
    } else if (FMS_DW.Integrator1_DSTATE_p < -FMS_PARAM.VEL_Z_LIM) {
      /* Outport: '<Root>/FMS_Output' incorporates:
       *  BusAssignment: '<S5>/Bus Assignment'
       */
      FMS_Y.FMS_Output.w_cmd = -FMS_PARAM.VEL_Z_LIM;
    } else {
      /* Outport: '<Root>/FMS_Output' incorporates:
       *  BusAssignment: '<S5>/Bus Assignment'
       */
      FMS_Y.FMS_Output.w_cmd = FMS_DW.Integrator1_DSTATE_p;
    }

    /* End of Saturate: '<S16>/Saturation' */

    /* Saturate: '<S15>/Saturation1' */
    if (FMS_DW.Integrator1_DSTATE_d > FMS_PARAM.YAW_RATE_LIM) {
      /* Outport: '<Root>/FMS_Output' incorporates:
       *  BusAssignment: '<S5>/Bus Assignment'
       */
      FMS_Y.FMS_Output.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
    } else if (FMS_DW.Integrator1_DSTATE_d < -FMS_PARAM.YAW_RATE_LIM) {
      /* Outport: '<Root>/FMS_Output' incorporates:
       *  BusAssignment: '<S5>/Bus Assignment'
       */
      FMS_Y.FMS_Output.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
    } else {
      /* Outport: '<Root>/FMS_Output' incorporates:
       *  BusAssignment: '<S5>/Bus Assignment'
       */
      FMS_Y.FMS_Output.psi_rate_cmd = FMS_DW.Integrator1_DSTATE_d;
    }

    /* End of Saturate: '<S15>/Saturation1' */

    /* Chart: '<S15>/Motion_State' incorporates:
     *  Abs: '<S30>/Abs'
     *  Constant: '<S37>/Constant'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S37>/Compare'
     */
    FMS_Motion_State(rtb_Product_idx_0 != 0.0F, fabsf(FMS_U.INS_Output.r),
                     &rtb_state_mp, &FMS_DW.sf_Motion_State_c);

    /* RelationalOperator: '<S21>/Compare' incorporates:
     *  Constant: '<S21>/Constant'
     */
    rtb_FixPtRelationalOperator = (rtb_state_mp == 2.0);

    /* RelationalOperator: '<S22>/Compare' incorporates:
     *  BusAssignment: '<S3>/Bus Assignment'
     *  Constant: '<S22>/Constant'
     */
    rtb_Compare_nq = (FMS_DW.Delay_DSTATE_pi == 2);

    /* Delay: '<S33>/Delay' incorporates:
     *  Inport: '<Root>/INS_Output'
     */
    if (FMS_DW.icLoad_i != 0) {
      FMS_DW.Delay_DSTATE_p = FMS_U.INS_Output.psi;
    }

    /* End of Delay: '<S33>/Delay' */

    /* Switch: '<S33>/Switch1' incorporates:
     *  Inport: '<Root>/INS_Output'
     *  Logic: '<S15>/Logical Operator'
     *  RelationalOperator: '<S23>/FixPt Relational Operator'
     *  RelationalOperator: '<S24>/FixPt Relational Operator'
     *  UnitDelay: '<S23>/Delay Input1'
     *  UnitDelay: '<S24>/Delay Input1'
     *
     * Block description for '<S23>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S24>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if (((int32_T)rtb_Compare_nq > (int32_T)FMS_DW.DelayInput1_DSTATE_j) ||
        ((int32_T)rtb_FixPtRelationalOperator > (int32_T)
         FMS_DW.DelayInput1_DSTATE_p)) {
      FMS_DW.Delay_DSTATE_p = FMS_U.INS_Output.psi;
    }

    /* End of Switch: '<S33>/Switch1' */

    /* Switch: '<S15>/Switch' incorporates:
     *  Constant: '<S34>/Constant'
     *  DeadZone: '<S35>/Dead Zone'
     *  Gain: '<S25>/Gain2'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S34>/Compare'
     *  Sum: '<S31>/Sum'
     *  Switch: '<S26>/Switch1'
     */
    if (rtb_FixPtRelationalOperator) {
      rtb_stick_throttle_raw = (FMS_DW.Delay_DSTATE_p - FMS_U.INS_Output.psi) *
        FMS_PARAM.YAW_P;
    } else if (rtb_state_mp == 1.0) {
      /* Switch: '<S26>/Switch1' incorporates:
       *  Constant: '<S26>/Constant'
       */
      rtb_stick_throttle_raw = 0.0F;
    } else {
      if (rtb_Product_idx_0 > FMS_PARAM.StickDeadZone) {
        /* DeadZone: '<S35>/Dead Zone' incorporates:
         *  Switch: '<S26>/Switch1'
         */
        rtb_Product_idx_0 -= FMS_PARAM.StickDeadZone;
      } else if (rtb_Product_idx_0 >= -FMS_PARAM.StickDeadZone) {
        /* DeadZone: '<S35>/Dead Zone' incorporates:
         *  Switch: '<S26>/Switch1'
         */
        rtb_Product_idx_0 = 0.0F;
      } else {
        /* DeadZone: '<S35>/Dead Zone' incorporates:
         *  Switch: '<S26>/Switch1'
         */
        rtb_Product_idx_0 -= -FMS_PARAM.StickDeadZone;
      }

      /* Switch: '<S26>/Switch1' incorporates:
       *  DeadZone: '<S35>/Dead Zone'
       *  Gain: '<S26>/Gain1'
       *  Gain: '<S35>/Gain'
       */
      rtb_stick_throttle_raw = 1.0F / (1.0F - FMS_PARAM.StickDeadZone) *
        rtb_Product_idx_0 * FMS_PARAM.YAW_RATE_LIM;
    }

    /* End of Switch: '<S15>/Switch' */

    /* Sum: '<S28>/Subtract' incorporates:
     *  DiscreteIntegrator: '<S28>/Integrator1'
     */
    rtb_Add_m = FMS_DW.Integrator1_DSTATE_d - rtb_stick_throttle_raw;

    /* Product: '<S36>/Multiply1' incorporates:
     *  Constant: '<S36>/const1'
     *  DiscreteIntegrator: '<S28>/Integrator'
     */
    rtb_stick_throttle_raw = FMS_DW.Integrator_DSTATE_o * 0.04F;

    /* Sum: '<S36>/Add' */
    rtb_TrigoFcn = rtb_Add_m + rtb_stick_throttle_raw;

    /* Signum: '<S36>/Sign' */
    if (rtb_TrigoFcn < 0.0F) {
      rtb_Add_m = -1.0F;
    } else if (rtb_TrigoFcn > 0.0F) {
      rtb_Add_m = 1.0F;
    } else {
      rtb_Add_m = rtb_TrigoFcn;
    }

    /* End of Signum: '<S36>/Sign' */

    /* Sum: '<S36>/Add2' incorporates:
     *  Abs: '<S36>/Abs'
     *  Gain: '<S36>/Gain'
     *  Gain: '<S36>/Gain1'
     *  Product: '<S36>/Multiply2'
     *  Product: '<S36>/Multiply3'
     *  Sqrt: '<S36>/Sqrt'
     *  Sum: '<S36>/Add1'
     *  Sum: '<S36>/Subtract'
     */
    rtb_Subtract3_f = (sqrtf((8.0F * fabsf(rtb_TrigoFcn) + FMS_ConstB.d_j) *
      FMS_ConstB.d_j) - FMS_ConstB.d_j) * 0.5F * rtb_Add_m +
      rtb_stick_throttle_raw;

    /* Sum: '<S36>/Add4' */
    rtb_Product_idx_0 = (rtb_TrigoFcn - rtb_Subtract3_f) +
      rtb_stick_throttle_raw;

    /* Sum: '<S36>/Add3' */
    rtb_Add_m = rtb_TrigoFcn + FMS_ConstB.d_j;

    /* Sum: '<S36>/Subtract1' */
    rtb_TrigoFcn -= FMS_ConstB.d_j;

    /* Signum: '<S36>/Sign1' */
    if (rtb_Add_m < 0.0F) {
      rtb_Add_m = -1.0F;
    } else {
      if (rtb_Add_m > 0.0F) {
        rtb_Add_m = 1.0F;
      }
    }

    /* End of Signum: '<S36>/Sign1' */

    /* Signum: '<S36>/Sign2' */
    if (rtb_TrigoFcn < 0.0F) {
      rtb_TrigoFcn = -1.0F;
    } else {
      if (rtb_TrigoFcn > 0.0F) {
        rtb_TrigoFcn = 1.0F;
      }
    }

    /* End of Signum: '<S36>/Sign2' */

    /* Sum: '<S36>/Add5' incorporates:
     *  Gain: '<S36>/Gain2'
     *  Product: '<S36>/Multiply4'
     *  Sum: '<S36>/Subtract2'
     */
    rtb_Subtract3_f += (rtb_Add_m - rtb_TrigoFcn) * 0.5F * rtb_Product_idx_0;

    /* Sum: '<S36>/Subtract3' */
    rtb_Add_m = rtb_Subtract3_f - FMS_ConstB.d_j;

    /* Sum: '<S36>/Add6' */
    rtb_Product_idx_0 = rtb_Subtract3_f + FMS_ConstB.d_j;

    /* Product: '<S36>/Divide' */
    rtb_Product_idx_1 = rtb_Subtract3_f / FMS_ConstB.d_j;

    /* Signum: '<S36>/Sign5' incorporates:
     *  Signum: '<S36>/Sign6'
     */
    if (rtb_Subtract3_f < 0.0F) {
      rtb_stick_yaw_raw = -1.0F;

      /* Signum: '<S36>/Sign6' */
      rtb_Add_d = -1.0F;
    } else if (rtb_Subtract3_f > 0.0F) {
      rtb_stick_yaw_raw = 1.0F;

      /* Signum: '<S36>/Sign6' */
      rtb_Add_d = 1.0F;
    } else {
      rtb_stick_yaw_raw = rtb_Subtract3_f;

      /* Signum: '<S36>/Sign6' */
      rtb_Add_d = rtb_Subtract3_f;
    }

    /* End of Signum: '<S36>/Sign5' */

    /* Chart: '<S38>/Z_Motion_State' incorporates:
     *  Constant: '<S55>/Constant'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S55>/Compare'
     */
    FMS_Z_Motion_State(rtb_Product_idx_2 != 0.0F, FMS_U.INS_Output.vd,
                       &rtb_state_mp, &FMS_DW.sf_Z_Motion_State_l);

    /* RelationalOperator: '<S49>/Compare' incorporates:
     *  Constant: '<S49>/Constant'
     */
    rtb_Compare_if = (rtb_state_mp == 2.0);

    /* Delay: '<S51>/Delay' incorporates:
     *  Gain: '<S48>/Gain'
     *  Inport: '<Root>/INS_Output'
     */
    if (FMS_DW.icLoad_d != 0) {
      FMS_DW.Delay_DSTATE_e = -FMS_U.INS_Output.h_R;
    }

    /* End of Delay: '<S51>/Delay' */

    /* Switch: '<S51>/Switch1' incorporates:
     *  Gain: '<S48>/Gain'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S50>/FixPt Relational Operator'
     *  UnitDelay: '<S50>/Delay Input1'
     *
     * Block description for '<S50>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if ((int32_T)rtb_Compare_if > (int32_T)FMS_DW.DelayInput1_DSTATE_a) {
      FMS_DW.Delay_DSTATE_e = -FMS_U.INS_Output.h_R;
    }

    /* End of Switch: '<S51>/Switch1' */

    /* Switch: '<S39>/Switch1' incorporates:
     *  Constant: '<S43>/Constant'
     *  Constant: '<S52>/Constant'
     *  DeadZone: '<S53>/Dead Zone'
     *  Gain: '<S44>/Gain4'
     *  Gain: '<S48>/Gain'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S43>/Compare'
     *  RelationalOperator: '<S52>/Compare'
     *  Sum: '<S47>/Sum'
     *  Switch: '<S45>/Switch2'
     */
    if (rtb_state_mp == 2.0) {
      rtb_Subtract3_f = (FMS_DW.Delay_DSTATE_e - (-FMS_U.INS_Output.h_R)) *
        FMS_PARAM.Z_P;
    } else if (rtb_state_mp == 1.0) {
      /* Switch: '<S45>/Switch2' incorporates:
       *  Constant: '<S45>/Constant1'
       */
      rtb_Subtract3_f = 0.0F;
    } else {
      if (rtb_Product_idx_2 > FMS_PARAM.StickDeadZone) {
        /* DeadZone: '<S53>/Dead Zone' incorporates:
         *  Switch: '<S45>/Switch2'
         */
        rtb_Product_idx_2 -= FMS_PARAM.StickDeadZone;
      } else if (rtb_Product_idx_2 >= -FMS_PARAM.StickDeadZone) {
        /* DeadZone: '<S53>/Dead Zone' incorporates:
         *  Switch: '<S45>/Switch2'
         */
        rtb_Product_idx_2 = 0.0F;
      } else {
        /* DeadZone: '<S53>/Dead Zone' incorporates:
         *  Switch: '<S45>/Switch2'
         */
        rtb_Product_idx_2 -= -FMS_PARAM.StickDeadZone;
      }

      /* Switch: '<S45>/Switch2' incorporates:
       *  DeadZone: '<S53>/Dead Zone'
       *  Gain: '<S45>/Gain6'
       *  Gain: '<S53>/Gain'
       */
      rtb_Subtract3_f = 1.0F / (1.0F - FMS_PARAM.StickDeadZone) *
        rtb_Product_idx_2 * -FMS_PARAM.VEL_Z_LIM;
    }

    /* End of Switch: '<S39>/Switch1' */

    /* Sum: '<S46>/Subtract' incorporates:
     *  DiscreteIntegrator: '<S46>/Integrator1'
     */
    rtb_Product_idx_2 = FMS_DW.Integrator1_DSTATE_p - rtb_Subtract3_f;

    /* Product: '<S54>/Multiply1' incorporates:
     *  Constant: '<S54>/const1'
     *  DiscreteIntegrator: '<S46>/Integrator'
     */
    rtb_Subtract3_f = FMS_DW.Integrator_DSTATE_g * 0.05F;

    /* Sum: '<S54>/Add' */
    rtb_stick_throttle_raw = rtb_Product_idx_2 + rtb_Subtract3_f;

    /* Signum: '<S54>/Sign' */
    if (rtb_stick_throttle_raw < 0.0F) {
      rtb_TrigoFcn = -1.0F;
    } else if (rtb_stick_throttle_raw > 0.0F) {
      rtb_TrigoFcn = 1.0F;
    } else {
      rtb_TrigoFcn = rtb_stick_throttle_raw;
    }

    /* End of Signum: '<S54>/Sign' */

    /* Sum: '<S54>/Add2' incorporates:
     *  Abs: '<S54>/Abs'
     *  Gain: '<S54>/Gain'
     *  Gain: '<S54>/Gain1'
     *  Product: '<S54>/Multiply2'
     *  Product: '<S54>/Multiply3'
     *  Sqrt: '<S54>/Sqrt'
     *  Sum: '<S54>/Add1'
     *  Sum: '<S54>/Subtract'
     */
    rtb_TrigoFcn = (sqrtf((8.0F * fabsf(rtb_stick_throttle_raw) + FMS_ConstB.d_a)
                          * FMS_ConstB.d_a) - FMS_ConstB.d_a) * 0.5F *
      rtb_TrigoFcn + rtb_Subtract3_f;

    /* Sum: '<S54>/Add4' */
    rtb_Add4_i = (rtb_stick_throttle_raw - rtb_TrigoFcn) + rtb_Subtract3_f;

    /* Sum: '<S54>/Add3' */
    rtb_Product_idx_2 = rtb_stick_throttle_raw + FMS_ConstB.d_a;

    /* Sum: '<S54>/Subtract1' */
    rtb_stick_throttle_raw -= FMS_ConstB.d_a;

    /* Signum: '<S54>/Sign1' */
    if (rtb_Product_idx_2 < 0.0F) {
      rtb_Product_idx_2 = -1.0F;
    } else {
      if (rtb_Product_idx_2 > 0.0F) {
        rtb_Product_idx_2 = 1.0F;
      }
    }

    /* End of Signum: '<S54>/Sign1' */

    /* Signum: '<S54>/Sign2' */
    if (rtb_stick_throttle_raw < 0.0F) {
      rtb_stick_throttle_raw = -1.0F;
    } else {
      if (rtb_stick_throttle_raw > 0.0F) {
        rtb_stick_throttle_raw = 1.0F;
      }
    }

    /* End of Signum: '<S54>/Sign2' */

    /* Sum: '<S54>/Add5' incorporates:
     *  Gain: '<S54>/Gain2'
     *  Product: '<S54>/Multiply4'
     *  Sum: '<S54>/Subtract2'
     */
    rtb_TrigoFcn += (rtb_Product_idx_2 - rtb_stick_throttle_raw) * 0.5F *
      rtb_Add4_i;

    /* Sum: '<S54>/Subtract3' */
    rtb_Product_idx_2 = rtb_TrigoFcn - FMS_ConstB.d_a;

    /* Sum: '<S54>/Add6' */
    u = rtb_TrigoFcn + FMS_ConstB.d_a;

    /* Product: '<S54>/Divide' */
    rtb_Divide_la = rtb_TrigoFcn / FMS_ConstB.d_a;

    /* Signum: '<S54>/Sign5' incorporates:
     *  Signum: '<S54>/Sign6'
     */
    if (rtb_TrigoFcn < 0.0F) {
      rtb_Sign5_m = -1.0F;

      /* Signum: '<S54>/Sign6' */
      rtb_Add4_i = -1.0F;
    } else if (rtb_TrigoFcn > 0.0F) {
      rtb_Sign5_m = 1.0F;

      /* Signum: '<S54>/Sign6' */
      rtb_Add4_i = 1.0F;
    } else {
      rtb_Sign5_m = rtb_TrigoFcn;

      /* Signum: '<S54>/Sign6' */
      rtb_Add4_i = rtb_TrigoFcn;
    }

    /* End of Signum: '<S54>/Sign5' */

    /* Product: '<S20>/Multiply1' incorporates:
     *  Constant: '<S20>/const1'
     *  DiscreteIntegrator: '<S18>/Integrator'
     */
    rtb_Subtract3_f = FMS_DW.Integrator_DSTATE_b * 0.04F;

    /* Sum: '<S20>/Add' incorporates:
     *  DiscreteIntegrator: '<S18>/Integrator1'
     *  Gain: '<S14>/Gain1'
     *  Sum: '<S18>/Subtract'
     */
    rtb_stick_throttle_raw = (FMS_DW.Integrator1_DSTATE_a -
      -FMS_PARAM.ROLL_PITCH_LIM * rtb_stick_pitch_raw) + rtb_Subtract3_f;

    /* Signum: '<S20>/Sign' */
    if (rtb_stick_throttle_raw < 0.0F) {
      rtb_TrigoFcn = -1.0F;
    } else if (rtb_stick_throttle_raw > 0.0F) {
      rtb_TrigoFcn = 1.0F;
    } else {
      rtb_TrigoFcn = rtb_stick_throttle_raw;
    }

    /* End of Signum: '<S20>/Sign' */

    /* Sum: '<S20>/Add2' incorporates:
     *  Abs: '<S20>/Abs'
     *  Gain: '<S20>/Gain'
     *  Gain: '<S20>/Gain1'
     *  Product: '<S20>/Multiply2'
     *  Product: '<S20>/Multiply3'
     *  Sqrt: '<S20>/Sqrt'
     *  Sum: '<S20>/Add1'
     *  Sum: '<S20>/Subtract'
     */
    rtb_TrigoFcn = (sqrtf((8.0F * fabsf(rtb_stick_throttle_raw) +
      FMS_ConstB.d_av) * FMS_ConstB.d_av) - FMS_ConstB.d_av) * 0.5F *
      rtb_TrigoFcn + rtb_Subtract3_f;

    /* Sum: '<S20>/Add4' */
    rtb_Subtract3_f += rtb_stick_throttle_raw - rtb_TrigoFcn;

    /* Sum: '<S20>/Add3' */
    rtb_stick_pitch_raw = rtb_stick_throttle_raw + FMS_ConstB.d_av;

    /* Sum: '<S20>/Subtract1' */
    rtb_stick_throttle_raw -= FMS_ConstB.d_av;

    /* Signum: '<S20>/Sign1' */
    if (rtb_stick_pitch_raw < 0.0F) {
      rtb_stick_pitch_raw = -1.0F;
    } else {
      if (rtb_stick_pitch_raw > 0.0F) {
        rtb_stick_pitch_raw = 1.0F;
      }
    }

    /* End of Signum: '<S20>/Sign1' */

    /* Signum: '<S20>/Sign2' */
    if (rtb_stick_throttle_raw < 0.0F) {
      rtb_stick_throttle_raw = -1.0F;
    } else {
      if (rtb_stick_throttle_raw > 0.0F) {
        rtb_stick_throttle_raw = 1.0F;
      }
    }

    /* End of Signum: '<S20>/Sign2' */

    /* Sum: '<S20>/Add5' incorporates:
     *  Gain: '<S20>/Gain2'
     *  Product: '<S20>/Multiply4'
     *  Sum: '<S20>/Subtract2'
     */
    rtb_TrigoFcn += (rtb_stick_pitch_raw - rtb_stick_throttle_raw) * 0.5F *
      rtb_Subtract3_f;

    /* Sum: '<S20>/Subtract3' */
    rtb_stick_pitch_raw = rtb_TrigoFcn - FMS_ConstB.d_av;

    /* Sum: '<S20>/Add6' */
    u_0 = rtb_TrigoFcn + FMS_ConstB.d_av;

    /* Product: '<S20>/Divide' */
    rtb_Divide_d = rtb_TrigoFcn / FMS_ConstB.d_av;

    /* Signum: '<S20>/Sign5' incorporates:
     *  Signum: '<S20>/Sign6'
     */
    if (rtb_TrigoFcn < 0.0F) {
      rtb_Sign5_dz = -1.0F;

      /* Signum: '<S20>/Sign6' */
      y = -1.0F;
    } else if (rtb_TrigoFcn > 0.0F) {
      rtb_Sign5_dz = 1.0F;

      /* Signum: '<S20>/Sign6' */
      y = 1.0F;
    } else {
      rtb_Sign5_dz = rtb_TrigoFcn;

      /* Signum: '<S20>/Sign6' */
      y = rtb_TrigoFcn;
    }

    /* End of Signum: '<S20>/Sign5' */

    /* Product: '<S19>/Multiply1' incorporates:
     *  Constant: '<S19>/const1'
     *  DiscreteIntegrator: '<S17>/Integrator'
     */
    rtb_Subtract3_f = FMS_DW.Integrator_DSTATE_gx * 0.04F;

    /* Sum: '<S19>/Add' incorporates:
     *  DiscreteIntegrator: '<S17>/Integrator1'
     *  Gain: '<S14>/Gain'
     *  Sum: '<S17>/Subtract'
     */
    rtb_stick_throttle_raw = (FMS_DW.Integrator1_DSTATE_f -
      FMS_PARAM.ROLL_PITCH_LIM * rtb_stick_roll_raw) + rtb_Subtract3_f;

    /* Signum: '<S19>/Sign' */
    if (rtb_stick_throttle_raw < 0.0F) {
      rtb_TrigoFcn = -1.0F;
    } else if (rtb_stick_throttle_raw > 0.0F) {
      rtb_TrigoFcn = 1.0F;
    } else {
      rtb_TrigoFcn = rtb_stick_throttle_raw;
    }

    /* End of Signum: '<S19>/Sign' */

    /* Sum: '<S19>/Add2' incorporates:
     *  Abs: '<S19>/Abs'
     *  Gain: '<S19>/Gain'
     *  Gain: '<S19>/Gain1'
     *  Product: '<S19>/Multiply2'
     *  Product: '<S19>/Multiply3'
     *  Sqrt: '<S19>/Sqrt'
     *  Sum: '<S19>/Add1'
     *  Sum: '<S19>/Subtract'
     */
    rtb_TrigoFcn = (sqrtf((8.0F * fabsf(rtb_stick_throttle_raw) + FMS_ConstB.d_f)
                          * FMS_ConstB.d_f) - FMS_ConstB.d_f) * 0.5F *
      rtb_TrigoFcn + rtb_Subtract3_f;

    /* Sum: '<S19>/Add4' */
    rtb_stick_roll_raw = (rtb_stick_throttle_raw - rtb_TrigoFcn) +
      rtb_Subtract3_f;

    /* Sum: '<S19>/Add3' */
    rtb_Subtract3_f = rtb_stick_throttle_raw + FMS_ConstB.d_f;

    /* Sum: '<S19>/Subtract1' */
    rtb_stick_throttle_raw -= FMS_ConstB.d_f;

    /* Signum: '<S19>/Sign1' */
    if (rtb_Subtract3_f < 0.0F) {
      rtb_Subtract3_f = -1.0F;
    } else {
      if (rtb_Subtract3_f > 0.0F) {
        rtb_Subtract3_f = 1.0F;
      }
    }

    /* End of Signum: '<S19>/Sign1' */

    /* Signum: '<S19>/Sign2' */
    if (rtb_stick_throttle_raw < 0.0F) {
      rtb_stick_throttle_raw = -1.0F;
    } else {
      if (rtb_stick_throttle_raw > 0.0F) {
        rtb_stick_throttle_raw = 1.0F;
      }
    }

    /* End of Signum: '<S19>/Sign2' */

    /* Sum: '<S19>/Add5' incorporates:
     *  Gain: '<S19>/Gain2'
     *  Product: '<S19>/Multiply4'
     *  Sum: '<S19>/Subtract2'
     */
    rtb_TrigoFcn += (rtb_Subtract3_f - rtb_stick_throttle_raw) * 0.5F *
      rtb_stick_roll_raw;

    /* Update for DiscreteIntegrator: '<S17>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S17>/Integrator'
     */
    FMS_DW.Integrator1_DSTATE_f += 0.004F * FMS_DW.Integrator_DSTATE_gx;

    /* Update for DiscreteIntegrator: '<S18>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S18>/Integrator'
     */
    FMS_DW.Integrator1_DSTATE_a += 0.004F * FMS_DW.Integrator_DSTATE_b;

    /* Update for DiscreteIntegrator: '<S46>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S46>/Integrator'
     */
    FMS_DW.Integrator1_DSTATE_p += 0.004F * FMS_DW.Integrator_DSTATE_g;

    /* Update for DiscreteIntegrator: '<S28>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S28>/Integrator'
     */
    FMS_DW.Integrator1_DSTATE_d += 0.004F * FMS_DW.Integrator_DSTATE_o;

    /* Update for UnitDelay: '<S23>/Delay Input1'
     *
     * Block description for '<S23>/Delay Input1':
     *
     *  Store in Global RAM
     */
    FMS_DW.DelayInput1_DSTATE_p = rtb_FixPtRelationalOperator;

    /* Update for UnitDelay: '<S24>/Delay Input1'
     *
     * Block description for '<S24>/Delay Input1':
     *
     *  Store in Global RAM
     */
    FMS_DW.DelayInput1_DSTATE_j = rtb_Compare_nq;

    /* Update for Delay: '<S33>/Delay' */
    FMS_DW.icLoad_i = 0U;

    /* Signum: '<S36>/Sign3' */
    if (rtb_Product_idx_0 < 0.0F) {
      rtb_Product_idx_0 = -1.0F;
    } else {
      if (rtb_Product_idx_0 > 0.0F) {
        rtb_Product_idx_0 = 1.0F;
      }
    }

    /* End of Signum: '<S36>/Sign3' */

    /* Signum: '<S36>/Sign4' */
    if (rtb_Add_m < 0.0F) {
      rtb_Add_m = -1.0F;
    } else {
      if (rtb_Add_m > 0.0F) {
        rtb_Add_m = 1.0F;
      }
    }

    /* End of Signum: '<S36>/Sign4' */

    /* Update for DiscreteIntegrator: '<S28>/Integrator' incorporates:
     *  Constant: '<S36>/const'
     *  Gain: '<S36>/Gain3'
     *  Product: '<S36>/Multiply5'
     *  Product: '<S36>/Multiply6'
     *  Sum: '<S36>/Subtract4'
     *  Sum: '<S36>/Subtract5'
     *  Sum: '<S36>/Subtract6'
     */
    FMS_DW.Integrator_DSTATE_o += ((rtb_Product_idx_1 - rtb_stick_yaw_raw) *
      FMS_ConstB.Gain4_d * ((rtb_Product_idx_0 - rtb_Add_m) * 0.5F) - rtb_Add_d *
      6.28318548F) * 0.004F;

    /* Update for UnitDelay: '<S50>/Delay Input1'
     *
     * Block description for '<S50>/Delay Input1':
     *
     *  Store in Global RAM
     */
    FMS_DW.DelayInput1_DSTATE_a = rtb_Compare_if;

    /* Update for Delay: '<S51>/Delay' */
    FMS_DW.icLoad_d = 0U;

    /* Signum: '<S54>/Sign3' */
    if (u < 0.0F) {
      u = -1.0F;
    } else {
      if (u > 0.0F) {
        u = 1.0F;
      }
    }

    /* End of Signum: '<S54>/Sign3' */

    /* Signum: '<S54>/Sign4' */
    if (rtb_Product_idx_2 < 0.0F) {
      rtb_Product_idx_2 = -1.0F;
    } else {
      if (rtb_Product_idx_2 > 0.0F) {
        rtb_Product_idx_2 = 1.0F;
      }
    }

    /* End of Signum: '<S54>/Sign4' */

    /* Update for DiscreteIntegrator: '<S46>/Integrator' incorporates:
     *  Constant: '<S54>/const'
     *  Gain: '<S54>/Gain3'
     *  Product: '<S54>/Multiply5'
     *  Product: '<S54>/Multiply6'
     *  Sum: '<S54>/Subtract4'
     *  Sum: '<S54>/Subtract5'
     *  Sum: '<S54>/Subtract6'
     */
    FMS_DW.Integrator_DSTATE_g += ((rtb_Divide_la - rtb_Sign5_m) *
      FMS_ConstB.Gain4_m * ((u - rtb_Product_idx_2) * 0.5F) - rtb_Add4_i *
      39.224F) * 0.004F;

    /* Signum: '<S20>/Sign3' */
    if (u_0 < 0.0F) {
      u_0 = -1.0F;
    } else {
      if (u_0 > 0.0F) {
        u_0 = 1.0F;
      }
    }

    /* End of Signum: '<S20>/Sign3' */

    /* Signum: '<S20>/Sign4' */
    if (rtb_stick_pitch_raw < 0.0F) {
      rtb_stick_pitch_raw = -1.0F;
    } else {
      if (rtb_stick_pitch_raw > 0.0F) {
        rtb_stick_pitch_raw = 1.0F;
      }
    }

    /* End of Signum: '<S20>/Sign4' */

    /* Update for DiscreteIntegrator: '<S18>/Integrator' incorporates:
     *  Constant: '<S20>/const'
     *  Gain: '<S20>/Gain3'
     *  Product: '<S20>/Multiply5'
     *  Product: '<S20>/Multiply6'
     *  Sum: '<S20>/Subtract4'
     *  Sum: '<S20>/Subtract5'
     *  Sum: '<S20>/Subtract6'
     */
    FMS_DW.Integrator_DSTATE_b += ((rtb_Divide_d - rtb_Sign5_dz) *
      FMS_ConstB.Gain4_a * ((u_0 - rtb_stick_pitch_raw) * 0.5F) - y * 12.566371F)
      * 0.004F;

    /* Signum: '<S19>/Sign6' incorporates:
     *  Signum: '<S19>/Sign5'
     */
    if (rtb_TrigoFcn < 0.0F) {
      rtb_Add_d = -1.0F;

      /* Signum: '<S19>/Sign5' */
      rtb_Add4_i = -1.0F;
    } else if (rtb_TrigoFcn > 0.0F) {
      rtb_Add_d = 1.0F;

      /* Signum: '<S19>/Sign5' */
      rtb_Add4_i = 1.0F;
    } else {
      rtb_Add_d = rtb_TrigoFcn;

      /* Signum: '<S19>/Sign5' */
      rtb_Add4_i = rtb_TrigoFcn;
    }

    /* End of Signum: '<S19>/Sign6' */

    /* Sum: '<S19>/Add6' */
    rtb_Add_m = rtb_TrigoFcn + FMS_ConstB.d_f;

    /* Sum: '<S19>/Subtract3' */
    rtb_Product_idx_0 = rtb_TrigoFcn - FMS_ConstB.d_f;

    /* Signum: '<S19>/Sign3' */
    if (rtb_Add_m < 0.0F) {
      rtb_Add_m = -1.0F;
    } else {
      if (rtb_Add_m > 0.0F) {
        rtb_Add_m = 1.0F;
      }
    }

    /* End of Signum: '<S19>/Sign3' */

    /* Signum: '<S19>/Sign4' */
    if (rtb_Product_idx_0 < 0.0F) {
      rtb_Product_idx_0 = -1.0F;
    } else {
      if (rtb_Product_idx_0 > 0.0F) {
        rtb_Product_idx_0 = 1.0F;
      }
    }

    /* End of Signum: '<S19>/Sign4' */

    /* Update for DiscreteIntegrator: '<S17>/Integrator' incorporates:
     *  Constant: '<S19>/const'
     *  Gain: '<S19>/Gain3'
     *  Product: '<S19>/Divide'
     *  Product: '<S19>/Multiply5'
     *  Product: '<S19>/Multiply6'
     *  Sum: '<S19>/Subtract4'
     *  Sum: '<S19>/Subtract5'
     *  Sum: '<S19>/Subtract6'
     */
    FMS_DW.Integrator_DSTATE_gx += ((rtb_TrigoFcn / FMS_ConstB.d_f - rtb_Add4_i)
      * FMS_ConstB.Gain4_e * ((rtb_Add_m - rtb_Product_idx_0) * 0.5F) -
      rtb_Add_d * 12.566371F) * 0.004F;

    /* End of Outputs for SubSystem: '<S1>/Altitude_Hold_Mode' */
    break;

   case 2:
    if (FMS_DW.SwitchCase_ActiveSubsystem != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S1>/Manual_Mode' incorporates:
       *  ActionPort: '<S6>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S1>/Switch Case' incorporates:
       *  Delay: '<S75>/Delay'
       *  DiscreteIntegrator: '<S60>/Integrator'
       *  DiscreteIntegrator: '<S60>/Integrator1'
       *  DiscreteIntegrator: '<S61>/Integrator'
       *  DiscreteIntegrator: '<S61>/Integrator1'
       *  UnitDelay: '<S66>/Delay Input1'
       *  UnitDelay: '<S67>/Delay Input1'
       *
       * Block description for '<S66>/Delay Input1':
       *
       *  Store in Global RAM
       *
       * Block description for '<S67>/Delay Input1':
       *
       *  Store in Global RAM
       */
      FMS_DW.Integrator1_DSTATE = 0.0F;
      FMS_DW.Integrator1_DSTATE_n = 0.0F;
      FMS_DW.DelayInput1_DSTATE_l = false;
      FMS_DW.DelayInput1_DSTATE_i = false;
      FMS_DW.icLoad = 1U;
      FMS_DW.Integrator_DSTATE = 0.0F;
      FMS_DW.Integrator_DSTATE_d = 0.0F;

      /* End of InitializeConditions for SubSystem: '<S1>/Manual_Mode' */

      /* SystemReset for IfAction SubSystem: '<S1>/Manual_Mode' incorporates:
       *  ActionPort: '<S6>/Action Port'
       */
      /* SystemReset for SwitchCase: '<S1>/Switch Case' incorporates:
       *  Chart: '<S58>/Motion_State'
       */
      FMS_Motion_State_Reset(&FMS_DW.sf_Motion_State_j);

      /* End of SystemReset for SubSystem: '<S1>/Manual_Mode' */
    }

    /* Outputs for IfAction SubSystem: '<S1>/Manual_Mode' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    /* Chart: '<S58>/Motion_State' incorporates:
     *  Abs: '<S72>/Abs'
     *  Constant: '<S78>/Constant'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S78>/Compare'
     */
    FMS_Motion_State(rtb_Product_idx_0 != 0.0F, fabsf(FMS_U.INS_Output.r),
                     &rtb_state_mp, &FMS_DW.sf_Motion_State_j);

    /* RelationalOperator: '<S64>/Compare' incorporates:
     *  Constant: '<S64>/Constant'
     */
    rtb_FixPtRelationalOperator = (rtb_state_mp == 2.0);

    /* RelationalOperator: '<S65>/Compare' incorporates:
     *  BusAssignment: '<S3>/Bus Assignment'
     *  Constant: '<S65>/Constant'
     */
    rtb_Compare_nq = (FMS_DW.Delay_DSTATE_pi == 2);

    /* Delay: '<S75>/Delay' incorporates:
     *  Inport: '<Root>/INS_Output'
     */
    if (FMS_DW.icLoad != 0) {
      FMS_DW.Delay_DSTATE = FMS_U.INS_Output.psi;
    }

    /* End of Delay: '<S75>/Delay' */

    /* Switch: '<S75>/Switch1' incorporates:
     *  Inport: '<Root>/INS_Output'
     *  Logic: '<S58>/Logical Operator'
     *  RelationalOperator: '<S66>/FixPt Relational Operator'
     *  RelationalOperator: '<S67>/FixPt Relational Operator'
     *  UnitDelay: '<S66>/Delay Input1'
     *  UnitDelay: '<S67>/Delay Input1'
     *
     * Block description for '<S66>/Delay Input1':
     *
     *  Store in Global RAM
     *
     * Block description for '<S67>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if (((int32_T)rtb_Compare_nq > (int32_T)FMS_DW.DelayInput1_DSTATE_l) ||
        ((int32_T)rtb_FixPtRelationalOperator > (int32_T)
         FMS_DW.DelayInput1_DSTATE_i)) {
      FMS_DW.Delay_DSTATE = FMS_U.INS_Output.psi;
    }

    /* End of Switch: '<S75>/Switch1' */

    /* Switch: '<S58>/Switch' incorporates:
     *  Constant: '<S76>/Constant'
     *  DeadZone: '<S77>/Dead Zone'
     *  Gain: '<S68>/Gain2'
     *  Inport: '<Root>/INS_Output'
     *  RelationalOperator: '<S76>/Compare'
     *  Sum: '<S73>/Sum'
     *  Switch: '<S69>/Switch1'
     */
    if (rtb_FixPtRelationalOperator) {
      rtb_TrigoFcn = (FMS_DW.Delay_DSTATE - FMS_U.INS_Output.psi) *
        FMS_PARAM.YAW_P;
    } else if (rtb_state_mp == 1.0) {
      /* Switch: '<S69>/Switch1' incorporates:
       *  Constant: '<S69>/Constant'
       */
      rtb_TrigoFcn = 0.0F;
    } else {
      if (rtb_Product_idx_0 > FMS_PARAM.StickDeadZone) {
        /* DeadZone: '<S77>/Dead Zone' incorporates:
         *  Switch: '<S69>/Switch1'
         */
        rtb_Product_idx_0 -= FMS_PARAM.StickDeadZone;
      } else if (rtb_Product_idx_0 >= -FMS_PARAM.StickDeadZone) {
        /* DeadZone: '<S77>/Dead Zone' incorporates:
         *  Switch: '<S69>/Switch1'
         */
        rtb_Product_idx_0 = 0.0F;
      } else {
        /* DeadZone: '<S77>/Dead Zone' incorporates:
         *  Switch: '<S69>/Switch1'
         */
        rtb_Product_idx_0 -= -FMS_PARAM.StickDeadZone;
      }

      /* Switch: '<S69>/Switch1' incorporates:
       *  DeadZone: '<S77>/Dead Zone'
       *  Gain: '<S69>/Gain1'
       *  Gain: '<S77>/Gain'
       */
      rtb_TrigoFcn = 1.0F / (1.0F - FMS_PARAM.StickDeadZone) * rtb_Product_idx_0
        * FMS_PARAM.YAW_RATE_LIM;
    }

    /* End of Switch: '<S58>/Switch' */

    /* Saturate: '<S58>/Saturation1' */
    if (rtb_TrigoFcn > FMS_PARAM.YAW_RATE_LIM) {
      /* Outport: '<Root>/FMS_Output' */
      FMS_Y.FMS_Output.psi_rate_cmd = FMS_PARAM.YAW_RATE_LIM;
    } else if (rtb_TrigoFcn < -FMS_PARAM.YAW_RATE_LIM) {
      /* Outport: '<Root>/FMS_Output' */
      FMS_Y.FMS_Output.psi_rate_cmd = -FMS_PARAM.YAW_RATE_LIM;
    } else {
      /* Outport: '<Root>/FMS_Output' */
      FMS_Y.FMS_Output.psi_rate_cmd = rtb_TrigoFcn;
    }

    /* End of Saturate: '<S58>/Saturation1' */

    /* Outport: '<Root>/FMS_Output' incorporates:
     *  BusAssignment: '<S3>/Bus Assignment'
     *  BusAssignment: '<S6>/Bus Assignment'
     *  Constant: '<S59>/Constant'
     *  Constant: '<S59>/Constant1'
     *  Constant: '<S6>/Constant'
     *  DiscreteIntegrator: '<S140>/Discrete-Time Integrator'
     *  DiscreteIntegrator: '<S60>/Integrator1'
     *  DiscreteIntegrator: '<S61>/Integrator1'
     *  Gain: '<S59>/Gain'
     *  SignalConversion: '<S3>/TmpHiddenBufferAtBus AssignmentInport1'
     *  Sum: '<S59>/Add'
     *  Sum: '<S59>/Sum'
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
    FMS_Y.FMS_Output.phi_cmd = FMS_DW.Integrator1_DSTATE;
    FMS_Y.FMS_Output.theta_cmd = FMS_DW.Integrator1_DSTATE_n;

    /* Product: '<S63>/Multiply1' incorporates:
     *  Constant: '<S63>/const1'
     *  DiscreteIntegrator: '<S61>/Integrator'
     */
    rtb_TrigoFcn = FMS_DW.Integrator_DSTATE * 0.04F;

    /* Sum: '<S63>/Add' incorporates:
     *  DiscreteIntegrator: '<S61>/Integrator1'
     *  Gain: '<S57>/Gain1'
     *  Sum: '<S61>/Subtract'
     */
    rtb_stick_pitch_raw = (FMS_DW.Integrator1_DSTATE_n -
      -FMS_PARAM.ROLL_PITCH_LIM * rtb_stick_pitch_raw) + rtb_TrigoFcn;

    /* Signum: '<S63>/Sign' */
    if (rtb_stick_pitch_raw < 0.0F) {
      rtb_stick_yaw_raw = -1.0F;
    } else if (rtb_stick_pitch_raw > 0.0F) {
      rtb_stick_yaw_raw = 1.0F;
    } else {
      rtb_stick_yaw_raw = rtb_stick_pitch_raw;
    }

    /* End of Signum: '<S63>/Sign' */

    /* Sum: '<S63>/Add2' incorporates:
     *  Abs: '<S63>/Abs'
     *  Gain: '<S63>/Gain'
     *  Gain: '<S63>/Gain1'
     *  Product: '<S63>/Multiply2'
     *  Product: '<S63>/Multiply3'
     *  Sqrt: '<S63>/Sqrt'
     *  Sum: '<S63>/Add1'
     *  Sum: '<S63>/Subtract'
     */
    rtb_Product_idx_2 = (sqrtf((8.0F * fabsf(rtb_stick_pitch_raw) + FMS_ConstB.d)
      * FMS_ConstB.d) - FMS_ConstB.d) * 0.5F * rtb_stick_yaw_raw + rtb_TrigoFcn;

    /* Sum: '<S63>/Add4' */
    rtb_Product_idx_0 = (rtb_stick_pitch_raw - rtb_Product_idx_2) + rtb_TrigoFcn;

    /* Sum: '<S63>/Add3' */
    rtb_Add_m = rtb_stick_pitch_raw + FMS_ConstB.d;

    /* Sum: '<S63>/Subtract1' */
    rtb_stick_pitch_raw -= FMS_ConstB.d;

    /* Signum: '<S63>/Sign1' */
    if (rtb_Add_m < 0.0F) {
      rtb_Add_m = -1.0F;
    } else {
      if (rtb_Add_m > 0.0F) {
        rtb_Add_m = 1.0F;
      }
    }

    /* End of Signum: '<S63>/Sign1' */

    /* Signum: '<S63>/Sign2' */
    if (rtb_stick_pitch_raw < 0.0F) {
      rtb_stick_pitch_raw = -1.0F;
    } else {
      if (rtb_stick_pitch_raw > 0.0F) {
        rtb_stick_pitch_raw = 1.0F;
      }
    }

    /* End of Signum: '<S63>/Sign2' */

    /* Sum: '<S63>/Add5' incorporates:
     *  Gain: '<S63>/Gain2'
     *  Product: '<S63>/Multiply4'
     *  Sum: '<S63>/Subtract2'
     */
    rtb_Product_idx_2 += (rtb_Add_m - rtb_stick_pitch_raw) * 0.5F *
      rtb_Product_idx_0;

    /* Sum: '<S63>/Subtract3' */
    rtb_Add_m = rtb_Product_idx_2 - FMS_ConstB.d;

    /* Sum: '<S63>/Add6' */
    rtb_Product_idx_0 = rtb_Product_idx_2 + FMS_ConstB.d;

    /* Product: '<S63>/Divide' */
    rtb_stick_throttle_raw = rtb_Product_idx_2 / FMS_ConstB.d;

    /* Signum: '<S63>/Sign5' incorporates:
     *  Signum: '<S63>/Sign6'
     */
    if (rtb_Product_idx_2 < 0.0F) {
      rtb_Product_idx_1 = -1.0F;

      /* Signum: '<S63>/Sign6' */
      rtb_Add_d = -1.0F;
    } else if (rtb_Product_idx_2 > 0.0F) {
      rtb_Product_idx_1 = 1.0F;

      /* Signum: '<S63>/Sign6' */
      rtb_Add_d = 1.0F;
    } else {
      rtb_Product_idx_1 = rtb_Product_idx_2;

      /* Signum: '<S63>/Sign6' */
      rtb_Add_d = rtb_Product_idx_2;
    }

    /* End of Signum: '<S63>/Sign5' */

    /* Product: '<S62>/Multiply1' incorporates:
     *  Constant: '<S62>/const1'
     *  DiscreteIntegrator: '<S60>/Integrator'
     */
    rtb_Product_idx_2 = FMS_DW.Integrator_DSTATE_d * 0.04F;

    /* Sum: '<S62>/Add' incorporates:
     *  DiscreteIntegrator: '<S60>/Integrator1'
     *  Gain: '<S57>/Gain2'
     *  Sum: '<S60>/Subtract'
     */
    rtb_stick_pitch_raw = (FMS_DW.Integrator1_DSTATE - FMS_PARAM.ROLL_PITCH_LIM *
      rtb_stick_roll_raw) + rtb_Product_idx_2;

    /* Signum: '<S62>/Sign' */
    if (rtb_stick_pitch_raw < 0.0F) {
      rtb_stick_yaw_raw = -1.0F;
    } else if (rtb_stick_pitch_raw > 0.0F) {
      rtb_stick_yaw_raw = 1.0F;
    } else {
      rtb_stick_yaw_raw = rtb_stick_pitch_raw;
    }

    /* End of Signum: '<S62>/Sign' */

    /* Sum: '<S62>/Add2' incorporates:
     *  Abs: '<S62>/Abs'
     *  Gain: '<S62>/Gain'
     *  Gain: '<S62>/Gain1'
     *  Product: '<S62>/Multiply2'
     *  Product: '<S62>/Multiply3'
     *  Sqrt: '<S62>/Sqrt'
     *  Sum: '<S62>/Add1'
     *  Sum: '<S62>/Subtract'
     */
    rtb_TrigoFcn = (sqrtf((8.0F * fabsf(rtb_stick_pitch_raw) + FMS_ConstB.d_i) *
                          FMS_ConstB.d_i) - FMS_ConstB.d_i) * 0.5F *
      rtb_stick_yaw_raw + rtb_Product_idx_2;

    /* Sum: '<S62>/Add4' */
    rtb_stick_roll_raw = (rtb_stick_pitch_raw - rtb_TrigoFcn) +
      rtb_Product_idx_2;

    /* Sum: '<S62>/Add3' */
    rtb_Product_idx_2 = rtb_stick_pitch_raw + FMS_ConstB.d_i;

    /* Sum: '<S62>/Subtract1' */
    rtb_stick_pitch_raw -= FMS_ConstB.d_i;

    /* Signum: '<S62>/Sign1' */
    if (rtb_Product_idx_2 < 0.0F) {
      rtb_Product_idx_2 = -1.0F;
    } else {
      if (rtb_Product_idx_2 > 0.0F) {
        rtb_Product_idx_2 = 1.0F;
      }
    }

    /* End of Signum: '<S62>/Sign1' */

    /* Signum: '<S62>/Sign2' */
    if (rtb_stick_pitch_raw < 0.0F) {
      rtb_stick_pitch_raw = -1.0F;
    } else {
      if (rtb_stick_pitch_raw > 0.0F) {
        rtb_stick_pitch_raw = 1.0F;
      }
    }

    /* End of Signum: '<S62>/Sign2' */

    /* Sum: '<S62>/Add5' incorporates:
     *  Gain: '<S62>/Gain2'
     *  Product: '<S62>/Multiply4'
     *  Sum: '<S62>/Subtract2'
     */
    rtb_TrigoFcn += (rtb_Product_idx_2 - rtb_stick_pitch_raw) * 0.5F *
      rtb_stick_roll_raw;

    /* Update for DiscreteIntegrator: '<S60>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S60>/Integrator'
     */
    FMS_DW.Integrator1_DSTATE += 0.004F * FMS_DW.Integrator_DSTATE_d;

    /* Update for DiscreteIntegrator: '<S61>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S61>/Integrator'
     */
    FMS_DW.Integrator1_DSTATE_n += 0.004F * FMS_DW.Integrator_DSTATE;

    /* Update for UnitDelay: '<S67>/Delay Input1'
     *
     * Block description for '<S67>/Delay Input1':
     *
     *  Store in Global RAM
     */
    FMS_DW.DelayInput1_DSTATE_l = rtb_Compare_nq;

    /* Update for UnitDelay: '<S66>/Delay Input1'
     *
     * Block description for '<S66>/Delay Input1':
     *
     *  Store in Global RAM
     */
    FMS_DW.DelayInput1_DSTATE_i = rtb_FixPtRelationalOperator;

    /* Update for Delay: '<S75>/Delay' */
    FMS_DW.icLoad = 0U;

    /* Signum: '<S63>/Sign3' */
    if (rtb_Product_idx_0 < 0.0F) {
      rtb_Product_idx_0 = -1.0F;
    } else {
      if (rtb_Product_idx_0 > 0.0F) {
        rtb_Product_idx_0 = 1.0F;
      }
    }

    /* End of Signum: '<S63>/Sign3' */

    /* Signum: '<S63>/Sign4' */
    if (rtb_Add_m < 0.0F) {
      rtb_Add_m = -1.0F;
    } else {
      if (rtb_Add_m > 0.0F) {
        rtb_Add_m = 1.0F;
      }
    }

    /* End of Signum: '<S63>/Sign4' */

    /* Update for DiscreteIntegrator: '<S61>/Integrator' incorporates:
     *  Constant: '<S63>/const'
     *  Gain: '<S63>/Gain3'
     *  Product: '<S63>/Multiply5'
     *  Product: '<S63>/Multiply6'
     *  Sum: '<S63>/Subtract4'
     *  Sum: '<S63>/Subtract5'
     *  Sum: '<S63>/Subtract6'
     */
    FMS_DW.Integrator_DSTATE += ((rtb_stick_throttle_raw - rtb_Product_idx_1) *
      FMS_ConstB.Gain4 * ((rtb_Product_idx_0 - rtb_Add_m) * 0.5F) - rtb_Add_d *
      12.566371F) * 0.004F;

    /* Signum: '<S62>/Sign6' incorporates:
     *  Signum: '<S62>/Sign5'
     */
    if (rtb_TrigoFcn < 0.0F) {
      rtb_Add_d = -1.0F;

      /* Signum: '<S62>/Sign5' */
      rtb_Add4_i = -1.0F;
    } else if (rtb_TrigoFcn > 0.0F) {
      rtb_Add_d = 1.0F;

      /* Signum: '<S62>/Sign5' */
      rtb_Add4_i = 1.0F;
    } else {
      rtb_Add_d = rtb_TrigoFcn;

      /* Signum: '<S62>/Sign5' */
      rtb_Add4_i = rtb_TrigoFcn;
    }

    /* End of Signum: '<S62>/Sign6' */

    /* Sum: '<S62>/Add6' */
    rtb_Add_m = rtb_TrigoFcn + FMS_ConstB.d_i;

    /* Sum: '<S62>/Subtract3' */
    rtb_Product_idx_0 = rtb_TrigoFcn - FMS_ConstB.d_i;

    /* Signum: '<S62>/Sign3' */
    if (rtb_Add_m < 0.0F) {
      rtb_Add_m = -1.0F;
    } else {
      if (rtb_Add_m > 0.0F) {
        rtb_Add_m = 1.0F;
      }
    }

    /* End of Signum: '<S62>/Sign3' */

    /* Signum: '<S62>/Sign4' */
    if (rtb_Product_idx_0 < 0.0F) {
      rtb_Product_idx_0 = -1.0F;
    } else {
      if (rtb_Product_idx_0 > 0.0F) {
        rtb_Product_idx_0 = 1.0F;
      }
    }

    /* End of Signum: '<S62>/Sign4' */

    /* Update for DiscreteIntegrator: '<S60>/Integrator' incorporates:
     *  Constant: '<S62>/const'
     *  Gain: '<S62>/Gain3'
     *  Product: '<S62>/Divide'
     *  Product: '<S62>/Multiply5'
     *  Product: '<S62>/Multiply6'
     *  Sum: '<S62>/Subtract4'
     *  Sum: '<S62>/Subtract5'
     *  Sum: '<S62>/Subtract6'
     */
    FMS_DW.Integrator_DSTATE_d += ((rtb_TrigoFcn / FMS_ConstB.d_i - rtb_Add4_i) *
      FMS_ConstB.Gain4_f * ((rtb_Add_m - rtb_Product_idx_0) * 0.5F) - rtb_Add_d *
      12.566371F) * 0.004F;

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
     *  DiscreteIntegrator: '<S140>/Discrete-Time Integrator'
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
     *  DiscreteIntegrator: '<S140>/Discrete-Time Integrator'
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

  /* Product: '<S143>/Multiply' incorporates:
   *  Inport: '<Root>/INS_Output'
   *  SignalConversion: '<S143>/ConcatBufferAtMatrix Concatenate3In1'
   *  SignalConversion: '<S143>/ConcatBufferAtMatrix Concatenate3In2'
   *  SignalConversion: '<S143>/ConcatBufferAtMatrix Concatenate3In3'
   */
  for (i_0 = 0; i_0 < 3; i_0++) {
    rtb_Multiply_a[i_0] = rtb_MatrixConcatenate3[i_0 + 6] * FMS_U.INS_Output.az
      + (rtb_MatrixConcatenate3[i_0 + 3] * FMS_U.INS_Output.ay +
         rtb_MatrixConcatenate3[i_0] * FMS_U.INS_Output.ax);
  }

  /* End of Product: '<S143>/Multiply' */

  /* Update for DiscreteIntegrator: '<S146>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S146>/Gain2'
   *  Sum: '<S146>/Sum9'
   */
  FMS_DW.DiscreteTimeIntegrator5_DSTATE += (rtb_Multiply_a[2] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE) * 10.0F * 0.004F;

  /* Update for UnitDelay: '<S134>/Delay Input1'
   *
   * Block description for '<S134>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE = rtb_LogicalOperator1;

  /* Update for DiscreteIntegrator: '<S140>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S140>/Constant'
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

  /* SystemInitialize for Chart: '<S135>/Arm_Event' */
  FMS_DW.is_active_c3_FMS = 0U;
  FMS_DW.is_c3_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for Chart: '<S135>/Disarm_Event' */
  FMS_DW.temporalCounter_i1_a = 0U;
  FMS_DW.is_active_c10_FMS = 0U;
  FMS_DW.is_c10_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for Chart: '<S3>/State_Logic' */
  FMS_DW.temporalCounter_i1 = 0U;
  FMS_DW.is_active_c4_FMS = 0U;
  FMS_DW.is_c4_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for IfAction SubSystem: '<S1>/Position_Mode' */
  /* InitializeConditions for DiscreteIntegrator: '<S89>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_c1 = 0.0F;

  /* InitializeConditions for UnitDelay: '<S114>/Delay Input1'
   *
   * Block description for '<S114>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_iu = false;

  /* InitializeConditions for Delay: '<S116>/Delay' */
  FMS_DW.icLoad_f = 1U;

  /* InitializeConditions for UnitDelay: '<S115>/Delay Input1'
   *
   * Block description for '<S115>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_pv = false;

  /* InitializeConditions for Delay: '<S117>/Delay' */
  FMS_DW.icLoad_a = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S109>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_c[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S109>/Integrator' */
  FMS_DW.Integrator_DSTATE_f[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S109>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_c[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S109>/Integrator' */
  FMS_DW.Integrator_DSTATE_f[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S109>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_c[2] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S109>/Integrator' */
  FMS_DW.Integrator_DSTATE_f[2] = 0.0F;

  /* InitializeConditions for UnitDelay: '<S84>/Delay Input1'
   *
   * Block description for '<S84>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_h = false;

  /* InitializeConditions for UnitDelay: '<S85>/Delay Input1'
   *
   * Block description for '<S85>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_o = false;

  /* InitializeConditions for Delay: '<S94>/Delay' */
  FMS_DW.icLoad_o = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S89>/Integrator' */
  FMS_DW.Integrator_DSTATE_m = 0.0F;

  /* SystemInitialize for Chart: '<S80>/Motion_State' */
  FMS_Motion_State_Init(&FMS_DW.sf_Motion_State);

  /* SystemInitialize for Chart: '<S99>/XY_Motion_State' */
  FMS_DW.temporalCounter_i1_b = 0U;
  FMS_DW.is_active_c7_FMS = 0U;
  FMS_DW.is_c7_FMS = FMS_IN_NO_ACTIVE_CHILD_h;

  /* SystemInitialize for Chart: '<S99>/Z_Motion_State' */
  FMS_Z_Motion_State_Init(&FMS_DW.sf_Z_Motion_State);

  /* End of SystemInitialize for SubSystem: '<S1>/Position_Mode' */

  /* SystemInitialize for IfAction SubSystem: '<S1>/Altitude_Hold_Mode' */
  /* InitializeConditions for DiscreteIntegrator: '<S17>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_f = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S18>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_a = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S46>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_p = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S28>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_d = 0.0F;

  /* InitializeConditions for UnitDelay: '<S23>/Delay Input1'
   *
   * Block description for '<S23>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_p = false;

  /* InitializeConditions for UnitDelay: '<S24>/Delay Input1'
   *
   * Block description for '<S24>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_j = false;

  /* InitializeConditions for Delay: '<S33>/Delay' */
  FMS_DW.icLoad_i = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S28>/Integrator' */
  FMS_DW.Integrator_DSTATE_o = 0.0F;

  /* InitializeConditions for UnitDelay: '<S50>/Delay Input1'
   *
   * Block description for '<S50>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_a = false;

  /* InitializeConditions for Delay: '<S51>/Delay' */
  FMS_DW.icLoad_d = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S46>/Integrator' */
  FMS_DW.Integrator_DSTATE_g = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S18>/Integrator' */
  FMS_DW.Integrator_DSTATE_b = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S17>/Integrator' */
  FMS_DW.Integrator_DSTATE_gx = 0.0F;

  /* SystemInitialize for Chart: '<S15>/Motion_State' */
  FMS_Motion_State_Init(&FMS_DW.sf_Motion_State_c);

  /* SystemInitialize for Chart: '<S38>/Z_Motion_State' */
  FMS_Z_Motion_State_Init(&FMS_DW.sf_Z_Motion_State_l);

  /* End of SystemInitialize for SubSystem: '<S1>/Altitude_Hold_Mode' */

  /* SystemInitialize for IfAction SubSystem: '<S1>/Manual_Mode' */
  /* InitializeConditions for DiscreteIntegrator: '<S60>/Integrator1' */
  FMS_DW.Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S61>/Integrator1' */
  FMS_DW.Integrator1_DSTATE_n = 0.0F;

  /* InitializeConditions for UnitDelay: '<S67>/Delay Input1'
   *
   * Block description for '<S67>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_l = false;

  /* InitializeConditions for UnitDelay: '<S66>/Delay Input1'
   *
   * Block description for '<S66>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_i = false;

  /* InitializeConditions for Delay: '<S75>/Delay' */
  FMS_DW.icLoad = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S61>/Integrator' */
  FMS_DW.Integrator_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S60>/Integrator' */
  FMS_DW.Integrator_DSTATE_d = 0.0F;

  /* SystemInitialize for Chart: '<S58>/Motion_State' */
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
