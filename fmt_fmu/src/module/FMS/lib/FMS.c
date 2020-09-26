/*
 * File: FMS.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.933
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Sep 24 15:07:43 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Named constants for Chart: '<S1>/Control_Mode' */
#define FMS_IN_Acro                    ((uint8_T)1U)
#define FMS_IN_Altitude_Hold           ((uint8_T)2U)
#define FMS_IN_Manual                  ((uint8_T)3U)
#define FMS_IN_Mission                 ((uint8_T)4U)
#define FMS_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define FMS_IN_Position                ((uint8_T)5U)
#define FMS_IN_Unknow                  ((uint8_T)6U)

/* Named constants for Chart: '<S20>/Motion_State' */
#define FMS_IN_Brake                   ((uint8_T)1U)
#define FMS_IN_Hold                    ((uint8_T)2U)
#define FMS_IN_Move                    ((uint8_T)3U)

/* Named constants for Chart: '<S2>/State_Management' */
#define FMS_IN_Arm                     ((uint8_T)1U)
#define FMS_IN_Disarm                  ((uint8_T)2U)
#define FMS_IN_Motor_Test              ((uint8_T)3U)
#define FMS_IN_Standby                 ((uint8_T)4U)

/* Named constants for Chart: '<S87>/Arm_Event' */
#define FMS_IN_Idle                    ((uint8_T)1U)
#define FMS_IN_arm_event               ((uint8_T)2U)
#define FMS_IN_ready                   ((uint8_T)3U)

/* Named constants for Chart: '<S87>/Disarm_Event' */
#define FMS_IN_Disarm_d                ((uint8_T)1U)
#define FMS_IN_Idle_b                  ((uint8_T)2U)
#define FMS_IN_On_Ground               ((uint8_T)3U)

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
struct_5vUBwe4VfGkNikzOx8lYKF FMS_PARAM = {
  0.15F,
  0.15F,
  0.1F,
  0.1F,
  0.95F,
  1.0F,
  5.0F,
  2.5F,
  2.5F,
  1.04719758F,
  0.52359879F
} ;                                    /* Variable: FMS_PARAM
                                        * Referenced by:
                                        *   '<S12>/Gain'
                                        *   '<S12>/Gain1'
                                        *   '<S98>/Constant'
                                        *   '<S98>/Dead Zone'
                                        *   '<S99>/Constant'
                                        *   '<S99>/Dead Zone'
                                        *   '<S100>/Constant'
                                        *   '<S100>/Dead Zone'
                                        *   '<S101>/Constant'
                                        *   '<S101>/Dead Zone'
                                        *   '<S21>/Saturation'
                                        *   '<S46>/Saturation'
                                        *   '<S46>/Saturation1'
                                        *   '<S28>/Gain2'
                                        *   '<S29>/Gain1'
                                        *   '<S65>/Gain1'
                                        *   '<S65>/Gain5'
                                        *   '<S65>/Gain6'
                                        *   '<S66>/Gain1'
                                        *   '<S66>/Gain2'
                                        *   '<S66>/Gain4'
                                        *   '<S35>/Dead Zone'
                                        *   '<S35>/Gain'
                                        *   '<S69>/Dead Zone'
                                        *   '<S69>/Gain'
                                        *   '<S70>/Dead Zone'
                                        *   '<S70>/Gain'
                                        *   '<S71>/Dead Zone'
                                        *   '<S71>/Gain'
                                        */

struct_i7E80ZuatMf603HOn7rPOE FMS_EXPORT = {
  4U,

  { 66, 97, 115, 101, 32, 70, 77, 83, 0 }
} ;                                    /* Variable: FMS_EXPORT
                                        * Referenced by: '<S80>/Constant'
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

/* Model step function */
void FMS_step(void)
{
  real32_T rtb_MatrixConcatenate3[9];
  real32_T rtb_Subtract1;
  real32_T rtb_MatrixConcatenate3_d[3];
  boolean_T rtb_LogicalOperator1;
  real32_T rtb_stick_pitch_raw;
  real32_T rtb_stick_throttle_raw;
  boolean_T rtb_Compare_nv;
  boolean_T rtb_FixPtRelationalOperator;
  boolean_T rtb_Compare_cv;
  real32_T rtb_M_z[9];
  real32_T rtb_stick_yaw_raw;
  uint8_T rtb_State;
  uint32_T rtb_BusAssignment_timestamp;
  real32_T rtb_Add_b0;
  int32_T rtb_state_a;
  boolean_T rtb_LogicalOperator1_i;
  int32_T rtb_state;
  int32_T rtb_state_p;
  boolean_T rtb_LogicalOperator2;
  real32_T rtb_Subtract3_a;
  real32_T rtb_Divide_n;
  real32_T rtb_Sign5_i;
  real32_T rtb_Add4_k;
  real32_T rtb_Divide_h;
  real32_T rtb_Sign5_k;
  int32_T i;
  real32_T rtb_Product_idx_0;
  real32_T rtb_Product_idx_1;
  real32_T rtb_Product_idx_2;
  real32_T rtb_Product_idx_3;
  real32_T y;
  real32_T y_0;
  uint16_T tmp;
  real32_T rtb_a_idx_0;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;

  /* Outputs for Atomic SubSystem: '<Root>/Input_Process' */
  /* Product: '<S97>/Product' incorporates:
   *  Inport: '<Root>/INS_Output'
   */
  rtb_Product_idx_0 = FMS_U.INS_Output.quat[0] * FMS_U.INS_Output.quat[0];
  rtb_Product_idx_1 = FMS_U.INS_Output.quat[1] * FMS_U.INS_Output.quat[1];
  rtb_Product_idx_2 = FMS_U.INS_Output.quat[2] * FMS_U.INS_Output.quat[2];
  rtb_Product_idx_3 = FMS_U.INS_Output.quat[3] * FMS_U.INS_Output.quat[3];

  /* Sum: '<S97>/Add' */
  rtb_MatrixConcatenate3[0] = ((rtb_Product_idx_0 + rtb_Product_idx_1) -
    rtb_Product_idx_2) - rtb_Product_idx_3;

  /* Sum: '<S97>/Add5' incorporates:
   *  Sum: '<S97>/Add8'
   */
  rtb_Product_idx_0 -= rtb_Product_idx_1;
  rtb_MatrixConcatenate3[4] = (rtb_Product_idx_0 + rtb_Product_idx_2) -
    rtb_Product_idx_3;

  /* Sum: '<S97>/Add8' */
  rtb_MatrixConcatenate3[8] = (rtb_Product_idx_0 - rtb_Product_idx_2) +
    rtb_Product_idx_3;

  /* Product: '<S97>/Product1' incorporates:
   *  Inport: '<Root>/INS_Output'
   *  Product: '<S97>/Product5'
   */
  rtb_Product_idx_0 = FMS_U.INS_Output.quat[1] * FMS_U.INS_Output.quat[2];

  /* Product: '<S97>/Product2' incorporates:
   *  Inport: '<Root>/INS_Output'
   *  Product: '<S97>/Product6'
   */
  rtb_Product_idx_2 = FMS_U.INS_Output.quat[0] * FMS_U.INS_Output.quat[3];

  /* Gain: '<S97>/Gain' incorporates:
   *  Product: '<S97>/Product1'
   *  Product: '<S97>/Product2'
   *  Sum: '<S97>/Add1'
   */
  rtb_MatrixConcatenate3[1] = (rtb_Product_idx_0 + rtb_Product_idx_2) * 2.0F;

  /* Product: '<S97>/Product3' incorporates:
   *  Inport: '<Root>/INS_Output'
   *  Product: '<S97>/Product9'
   */
  rtb_Product_idx_3 = FMS_U.INS_Output.quat[1] * FMS_U.INS_Output.quat[3];

  /* Product: '<S97>/Product4' incorporates:
   *  Inport: '<Root>/INS_Output'
   *  Product: '<S97>/Product10'
   */
  rtb_Product_idx_1 = FMS_U.INS_Output.quat[0] * FMS_U.INS_Output.quat[2];

  /* Gain: '<S97>/Gain1' incorporates:
   *  Product: '<S97>/Product3'
   *  Product: '<S97>/Product4'
   *  Sum: '<S97>/Add2'
   */
  rtb_MatrixConcatenate3[2] = (rtb_Product_idx_3 - rtb_Product_idx_1) * 2.0F;

  /* Gain: '<S97>/Gain2' incorporates:
   *  Sum: '<S97>/Add3'
   */
  rtb_MatrixConcatenate3[3] = (rtb_Product_idx_0 - rtb_Product_idx_2) * 2.0F;

  /* Product: '<S97>/Product7' incorporates:
   *  Inport: '<Root>/INS_Output'
   *  Product: '<S97>/Product12'
   */
  rtb_Product_idx_0 = FMS_U.INS_Output.quat[2] * FMS_U.INS_Output.quat[3];

  /* Product: '<S97>/Product8' incorporates:
   *  Inport: '<Root>/INS_Output'
   *  Product: '<S97>/Product11'
   */
  rtb_Product_idx_2 = FMS_U.INS_Output.quat[0] * FMS_U.INS_Output.quat[1];

  /* Gain: '<S97>/Gain3' incorporates:
   *  Product: '<S97>/Product7'
   *  Product: '<S97>/Product8'
   *  Sum: '<S97>/Add4'
   */
  rtb_MatrixConcatenate3[5] = (rtb_Product_idx_0 + rtb_Product_idx_2) * 2.0F;

  /* Gain: '<S97>/Gain4' incorporates:
   *  Sum: '<S97>/Add6'
   */
  rtb_MatrixConcatenate3[6] = (rtb_Product_idx_3 + rtb_Product_idx_1) * 2.0F;

  /* Gain: '<S97>/Gain5' incorporates:
   *  Sum: '<S97>/Add7'
   */
  rtb_MatrixConcatenate3[7] = (rtb_Product_idx_0 - rtb_Product_idx_2) * 2.0F;

  /* Logic: '<S83>/Logical Operator1' incorporates:
   *  Constant: '<S93>/Constant'
   *  Constant: '<S94>/Lower Limit'
   *  Constant: '<S94>/Upper Limit'
   *  DiscreteIntegrator: '<S95>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S96>/Discrete-Time Integrator5'
   *  Logic: '<S94>/AND'
   *  RelationalOperator: '<S93>/Compare'
   *  RelationalOperator: '<S94>/Lower Test'
   *  RelationalOperator: '<S94>/Upper Test'
   */
  rtb_LogicalOperator1 = ((-10.806F <= FMS_DW.DiscreteTimeIntegrator5_DSTATE) &&
    (FMS_DW.DiscreteTimeIntegrator5_DSTATE <= -8.806F) &&
    (FMS_DW.DiscreteTimeIntegrator5_DSTAT_e < 1200.0F));

  /* Saturate: '<S84>/Saturation2' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   */
  if (FMS_U.Pilot_Cmd.rs_lr > 1.0F) {
    rtb_Product_idx_1 = 1.0F;
  } else if (FMS_U.Pilot_Cmd.rs_lr < -1.0F) {
    rtb_Product_idx_1 = -1.0F;
  } else {
    rtb_Product_idx_1 = FMS_U.Pilot_Cmd.rs_lr;
  }

  /* End of Saturate: '<S84>/Saturation2' */

  /* Saturate: '<S84>/Saturation3' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   */
  if (FMS_U.Pilot_Cmd.rs_ud > 1.0F) {
    rtb_stick_pitch_raw = 1.0F;
  } else if (FMS_U.Pilot_Cmd.rs_ud < -1.0F) {
    rtb_stick_pitch_raw = -1.0F;
  } else {
    rtb_stick_pitch_raw = FMS_U.Pilot_Cmd.rs_ud;
  }

  /* End of Saturate: '<S84>/Saturation3' */

  /* Saturate: '<S84>/Saturation1' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   */
  if (FMS_U.Pilot_Cmd.ls_ud > 1.0F) {
    rtb_stick_throttle_raw = 1.0F;
  } else if (FMS_U.Pilot_Cmd.ls_ud < -1.0F) {
    rtb_stick_throttle_raw = -1.0F;
  } else {
    rtb_stick_throttle_raw = FMS_U.Pilot_Cmd.ls_ud;
  }

  /* End of Saturate: '<S84>/Saturation1' */

  /* Chart: '<S87>/Arm_Event' */
  if (FMS_DW.is_active_c5_FMS == 0U) {
    FMS_DW.is_active_c5_FMS = 1U;
    FMS_DW.is_c5_FMS = FMS_IN_Idle;
    FMS_B.arm_event = 0.0;
  } else {
    switch (FMS_DW.is_c5_FMS) {
     case FMS_IN_Idle:
      FMS_B.arm_event = 0.0;
      if ((rtb_stick_throttle_raw < -0.8) && (rtb_Product_idx_1 < -0.8) &&
          (rtb_stick_pitch_raw < -0.8)) {
        FMS_DW.is_c5_FMS = FMS_IN_ready;
      }
      break;

     case FMS_IN_arm_event:
      FMS_DW.is_c5_FMS = FMS_IN_Idle;
      FMS_B.arm_event = 0.0;
      break;

     default:
      if ((fabsf(rtb_Product_idx_1) < 0.15) && (fabsf(rtb_stick_pitch_raw) <
           0.15)) {
        FMS_DW.is_c5_FMS = FMS_IN_arm_event;
        FMS_B.arm_event = 1.0;
      }
      break;
    }
  }

  /* End of Chart: '<S87>/Arm_Event' */

  /* Chart: '<S87>/Disarm_Event' incorporates:
   *  Delay: '<Root>/Delay'
   */
  if (FMS_DW.temporalCounter_i1 < 511U) {
    FMS_DW.temporalCounter_i1++;
  }

  if (FMS_DW.is_active_c12_FMS == 0U) {
    FMS_DW.is_active_c12_FMS = 1U;
    FMS_DW.is_c12_FMS = FMS_IN_Idle_b;
    FMS_B.disarm_event = 0.0;
  } else {
    switch (FMS_DW.is_c12_FMS) {
     case FMS_IN_Disarm_d:
      FMS_DW.is_c12_FMS = FMS_IN_Idle_b;
      FMS_B.disarm_event = 0.0;
      break;

     case FMS_IN_Idle_b:
      FMS_B.disarm_event = 0.0;
      if (rtb_LogicalOperator1 && (FMS_Y.FMS_Output.state == 2)) {
        FMS_DW.is_c12_FMS = FMS_IN_On_Ground;
        FMS_DW.temporalCounter_i1 = 0U;
      }
      break;

     default:
      if (!rtb_LogicalOperator1) {
        FMS_DW.is_c12_FMS = FMS_IN_Idle_b;
        FMS_B.disarm_event = 0.0;
      } else {
        if (FMS_DW.temporalCounter_i1 >= 375U) {
          FMS_DW.is_c12_FMS = FMS_IN_Disarm_d;
          FMS_B.disarm_event = 1.0;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S87>/Disarm_Event' */

  /* Logic: '<S87>/Logical Operator' */
  rtb_LogicalOperator1 = (FMS_B.arm_event != 0.0);

  /* DeadZone: '<S99>/Dead Zone' */
  if (rtb_stick_throttle_raw > FMS_PARAM.THROTTLE_DZ) {
    rtb_Subtract1 = rtb_stick_throttle_raw - FMS_PARAM.THROTTLE_DZ;
  } else if (rtb_stick_throttle_raw >= -FMS_PARAM.THROTTLE_DZ) {
    rtb_Subtract1 = 0.0F;
  } else {
    rtb_Subtract1 = rtb_stick_throttle_raw - (-FMS_PARAM.THROTTLE_DZ);
  }

  /* End of DeadZone: '<S99>/Dead Zone' */

  /* Signum: '<S99>/Sign' */
  if (rtb_Subtract1 < 0.0F) {
    rtb_Add_b0 = -1.0F;
  } else if (rtb_Subtract1 > 0.0F) {
    rtb_Add_b0 = 1.0F;
  } else {
    rtb_Add_b0 = rtb_Subtract1;
  }

  /* End of Signum: '<S99>/Sign' */

  /* Sum: '<S99>/Add' incorporates:
   *  Constant: '<S99>/Constant'
   *  Product: '<S99>/Multiply'
   */
  rtb_Product_idx_3 = rtb_Add_b0 * FMS_PARAM.THROTTLE_DZ + rtb_Subtract1;

  /* DeadZone: '<S101>/Dead Zone' */
  if (rtb_stick_pitch_raw > FMS_PARAM.PITCH_DZ) {
    rtb_Subtract1 = rtb_stick_pitch_raw - FMS_PARAM.PITCH_DZ;
  } else if (rtb_stick_pitch_raw >= -FMS_PARAM.PITCH_DZ) {
    rtb_Subtract1 = 0.0F;
  } else {
    rtb_Subtract1 = rtb_stick_pitch_raw - (-FMS_PARAM.PITCH_DZ);
  }

  /* End of DeadZone: '<S101>/Dead Zone' */

  /* Signum: '<S101>/Sign' */
  if (rtb_Subtract1 < 0.0F) {
    rtb_Add_b0 = -1.0F;
  } else if (rtb_Subtract1 > 0.0F) {
    rtb_Add_b0 = 1.0F;
  } else {
    rtb_Add_b0 = rtb_Subtract1;
  }

  /* End of Signum: '<S101>/Sign' */

  /* Sum: '<S101>/Add' incorporates:
   *  Constant: '<S101>/Constant'
   *  Product: '<S101>/Multiply'
   */
  rtb_Product_idx_0 = rtb_Add_b0 * FMS_PARAM.PITCH_DZ + rtb_Subtract1;

  /* DeadZone: '<S100>/Dead Zone' */
  if (rtb_Product_idx_1 > FMS_PARAM.ROLL_DZ) {
    rtb_Subtract1 = rtb_Product_idx_1 - FMS_PARAM.ROLL_DZ;
  } else if (rtb_Product_idx_1 >= -FMS_PARAM.ROLL_DZ) {
    rtb_Subtract1 = 0.0F;
  } else {
    rtb_Subtract1 = rtb_Product_idx_1 - (-FMS_PARAM.ROLL_DZ);
  }

  /* End of DeadZone: '<S100>/Dead Zone' */

  /* Signum: '<S100>/Sign' */
  if (rtb_Subtract1 < 0.0F) {
    rtb_Add_b0 = -1.0F;
  } else if (rtb_Subtract1 > 0.0F) {
    rtb_Add_b0 = 1.0F;
  } else {
    rtb_Add_b0 = rtb_Subtract1;
  }

  /* End of Signum: '<S100>/Sign' */

  /* Sum: '<S100>/Add' incorporates:
   *  Constant: '<S100>/Constant'
   *  Product: '<S100>/Multiply'
   */
  rtb_Product_idx_2 = rtb_Add_b0 * FMS_PARAM.ROLL_DZ + rtb_Subtract1;

  /* RelationalOperator: '<S88>/Compare' incorporates:
   *  Constant: '<S88>/Constant'
   *  Inport: '<Root>/Pilot_Cmd'
   */
  rtb_Compare_nv = (FMS_U.Pilot_Cmd.cmd_1 == 1000U);

  /* RelationalOperator: '<S89>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S89>/Delay Input1'
   *
   * Block description for '<S89>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_FixPtRelationalOperator = ((int32_T)rtb_Compare_nv > (int32_T)
    FMS_DW.DelayInput1_DSTATE);

  /* RelationalOperator: '<S92>/Compare' incorporates:
   *  Constant: '<S92>/Constant'
   *  Inport: '<Root>/Pilot_Cmd'
   */
  rtb_Compare_cv = (FMS_U.Pilot_Cmd.cmd_2 == 2000U);

  /* Trigonometry: '<S82>/TrigoFcn' incorporates:
   *  Inport: '<Root>/INS_Output'
   */
  rtb_Subtract1 = arm_sin_f32(FMS_U.INS_Output.psi);

  /* SignalConversion: '<S82>/ConcatBufferAtVecConcentate2In1' */
  rtb_M_z[3] = rtb_Subtract1;

  /* Gain: '<S82>/Gain' */
  rtb_M_z[1] = -rtb_Subtract1;

  /* Trigonometry: '<S82>/TrigoFcn1' incorporates:
   *  Inport: '<Root>/INS_Output'
   */
  rtb_Subtract1 = arm_cos_f32(FMS_U.INS_Output.psi);

  /* SignalConversion: '<S82>/ConcatBufferAtVecConcentate2In2' */
  rtb_M_z[4] = rtb_Subtract1;

  /* SignalConversion: '<S82>/ConcatBufferAtVecConcentateIn1' */
  rtb_M_z[0] = rtb_Subtract1;

  /* SignalConversion: '<S82>/ConcatBufferAtVecConcentate2In3' incorporates:
   *  Constant: '<S82>/Constant1'
   */
  rtb_M_z[5] = 0.0F;

  /* SignalConversion: '<S82>/ConcatBufferAtVecConcentate3In1' incorporates:
   *  Constant: '<S82>/Constant1'
   */
  rtb_M_z[6] = 0.0F;

  /* SignalConversion: '<S82>/ConcatBufferAtVecConcentate3In2' incorporates:
   *  Constant: '<S82>/Constant1'
   */
  rtb_M_z[7] = 0.0F;

  /* SignalConversion: '<S82>/ConcatBufferAtVecConcentateIn3' incorporates:
   *  Constant: '<S82>/Constant1'
   */
  rtb_M_z[2] = 0.0F;

  /* Constant: '<S82>/Constant' */
  rtb_M_z[8] = 1.0F;

  /* Saturate: '<S84>/Saturation' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   */
  if (FMS_U.Pilot_Cmd.ls_lr > 1.0F) {
    rtb_stick_yaw_raw = 1.0F;
  } else if (FMS_U.Pilot_Cmd.ls_lr < -1.0F) {
    rtb_stick_yaw_raw = -1.0F;
  } else {
    rtb_stick_yaw_raw = FMS_U.Pilot_Cmd.ls_lr;
  }

  /* End of Saturate: '<S84>/Saturation' */

  /* DeadZone: '<S98>/Dead Zone' */
  if (rtb_stick_yaw_raw > FMS_PARAM.YAW_DZ) {
    rtb_Subtract1 = rtb_stick_yaw_raw - FMS_PARAM.YAW_DZ;
  } else if (rtb_stick_yaw_raw >= -FMS_PARAM.YAW_DZ) {
    rtb_Subtract1 = 0.0F;
  } else {
    rtb_Subtract1 = rtb_stick_yaw_raw - (-FMS_PARAM.YAW_DZ);
  }

  /* End of DeadZone: '<S98>/Dead Zone' */

  /* Signum: '<S98>/Sign' */
  if (rtb_Subtract1 < 0.0F) {
    rtb_Add_b0 = -1.0F;
  } else if (rtb_Subtract1 > 0.0F) {
    rtb_Add_b0 = 1.0F;
  } else {
    rtb_Add_b0 = rtb_Subtract1;
  }

  /* End of Signum: '<S98>/Sign' */

  /* Sum: '<S98>/Add' incorporates:
   *  Constant: '<S98>/Constant'
   *  Product: '<S98>/Multiply'
   */
  rtb_Add_b0 = rtb_Add_b0 * FMS_PARAM.YAW_DZ + rtb_Subtract1;

  /* Product: '<S83>/Multiply' incorporates:
   *  Inport: '<Root>/INS_Output'
   *  SignalConversion: '<S83>/ConcatBufferAtMatrix Concatenate3In1'
   *  SignalConversion: '<S83>/ConcatBufferAtMatrix Concatenate3In2'
   *  SignalConversion: '<S83>/ConcatBufferAtMatrix Concatenate3In3'
   */
  for (i = 0; i < 3; i++) {
    rtb_MatrixConcatenate3_d[i] = rtb_MatrixConcatenate3[i + 6] *
      FMS_U.INS_Output.az + (rtb_MatrixConcatenate3[i + 3] * FMS_U.INS_Output.ay
      + rtb_MatrixConcatenate3[i] * FMS_U.INS_Output.ax);
  }

  /* End of Product: '<S83>/Multiply' */

  /* Update for DiscreteIntegrator: '<S95>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S95>/Gain2'
   *  Sum: '<S95>/Sum9'
   */
  FMS_DW.DiscreteTimeIntegrator5_DSTATE += (rtb_MatrixConcatenate3_d[2] -
    FMS_DW.DiscreteTimeIntegrator5_DSTATE) * 2.0F * 0.004F;

  /* Update for DiscreteIntegrator: '<S96>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S96>/Gain2'
   *  Inport: '<Root>/Control_Out'
   *  Product: '<S83>/Divide'
   *  Sum: '<S83>/Sum of Elements'
   *  Sum: '<S96>/Sum9'
   */
  FMS_DW.DiscreteTimeIntegrator5_DSTAT_e += ((real32_T)(int32_T)((uint32_T)
    (uint16_T)((((uint32_T)FMS_U.Control_Out.actuator_cmd[0] +
                 FMS_U.Control_Out.actuator_cmd[1]) +
                FMS_U.Control_Out.actuator_cmd[2]) +
               FMS_U.Control_Out.actuator_cmd[3]) >> 2) -
    FMS_DW.DiscreteTimeIntegrator5_DSTAT_e) * 10.0F * 0.004F;

  /* Update for UnitDelay: '<S89>/Delay Input1'
   *
   * Block description for '<S89>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE = rtb_Compare_nv;

  /* End of Outputs for SubSystem: '<Root>/Input_Process' */

  /* Outputs for Atomic SubSystem: '<Root>/FMS_State' */
  /* Chart: '<S2>/State_Management' incorporates:
   *  Logic: '<S87>/Logical Operator1'
   */
  if (FMS_DW.temporalCounter_i1_g < 8191U) {
    FMS_DW.temporalCounter_i1_g++;
  }

  if (FMS_DW.is_active_c4_FMS == 0U) {
    FMS_DW.is_active_c4_FMS = 1U;
    FMS_DW.is_c4_FMS = FMS_IN_Disarm;
    rtb_State = 0U;
    FMS_B.PWM_Cmd = 1000U;
  } else {
    guard1 = false;
    switch (FMS_DW.is_c4_FMS) {
     case FMS_IN_Arm:
      rtb_State = 2U;

      /* Outputs for Atomic SubSystem: '<Root>/Input_Process' */
      if ((FMS_B.disarm_event != 0.0) || rtb_FixPtRelationalOperator) {
        FMS_DW.is_c4_FMS = FMS_IN_Disarm;
        rtb_State = 0U;
        FMS_B.PWM_Cmd = 1000U;
      }

      /* End of Outputs for SubSystem: '<Root>/Input_Process' */
      break;

     case FMS_IN_Disarm:
      rtb_State = 0U;
      if (rtb_Compare_cv && rtb_LogicalOperator1) {
        FMS_DW.is_c4_FMS = FMS_IN_Motor_Test;
        rtb_State = 1U;
      } else {
        if (rtb_LogicalOperator1) {
          FMS_DW.is_c4_FMS = FMS_IN_Standby;
          FMS_DW.temporalCounter_i1_g = 0U;
          rtb_State = 1U;
          FMS_B.PWM_Cmd = 1150U;
        }
      }
      break;

     case FMS_IN_Motor_Test:
      rtb_State = 1U;
      if ((!rtb_Compare_cv) || rtb_LogicalOperator1) {
        FMS_DW.is_c4_FMS = FMS_IN_Disarm;
        rtb_State = 0U;
        FMS_B.PWM_Cmd = 1000U;
      } else {
        rtb_Subtract1 = roundf((rtb_stick_throttle_raw + 1.0F) * 500.0F);
        if (rtb_Subtract1 < 65536.0F) {
          tmp = (uint16_T)rtb_Subtract1;
        } else {
          tmp = MAX_uint16_T;
        }

        rtb_BusAssignment_timestamp = 1000U + tmp;
        if (rtb_BusAssignment_timestamp > 65535U) {
          rtb_BusAssignment_timestamp = 65535U;
        }

        FMS_B.PWM_Cmd = (uint16_T)rtb_BusAssignment_timestamp;
      }
      break;

     default:
      rtb_State = 1U;
      if (FMS_DW.temporalCounter_i1_g >= 7500U) {
        guard1 = true;
      } else if (rtb_stick_throttle_raw > -0.25F) {
        FMS_DW.is_c4_FMS = FMS_IN_Arm;
        rtb_State = 2U;
      } else {
        if (rtb_LogicalOperator1 || rtb_FixPtRelationalOperator) {
          guard1 = true;
        }
      }
      break;
    }

    if (guard1) {
      FMS_DW.is_c4_FMS = FMS_IN_Disarm;
      rtb_State = 0U;
      FMS_B.PWM_Cmd = 1000U;
    }
  }

  /* End of Chart: '<S2>/State_Management' */

  /* BusAssignment: '<S2>/Bus Assignment' incorporates:
   *  DiscreteIntegrator: '<S80>/Discrete-Time Integrator'
   */
  rtb_BusAssignment_timestamp = FMS_DW.DiscreteTimeIntegrator_DSTATE;

  /* Update for DiscreteIntegrator: '<S80>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S80>/Constant'
   */
  FMS_DW.DiscreteTimeIntegrator_DSTATE += FMS_EXPORT.period;

  /* End of Outputs for SubSystem: '<Root>/FMS_State' */

  /* Outputs for Atomic SubSystem: '<Root>/Control_Mode' */
  /* Chart: '<S1>/Control_Mode' incorporates:
   *  Inport: '<Root>/Pilot_Cmd'
   *  SignalConversion: '<S84>/TmpSignal ConversionAtSignal Copy4Inport1'
   */
  if (FMS_DW.is_active_c1_FMS == 0U) {
    FMS_DW.is_active_c1_FMS = 1U;

    /* Outputs for Atomic SubSystem: '<Root>/Input_Process' */
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

    /* End of Outputs for SubSystem: '<Root>/Input_Process' */
  } else {
    guard1 = false;
    guard2 = false;
    guard3 = false;
    guard4 = false;
    switch (FMS_DW.is_c1_FMS) {
     case FMS_IN_Acro:
      FMS_B.control_mode = FMS_DW.local_mode;

      /* Outputs for Atomic SubSystem: '<Root>/Input_Process' */
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

      /* End of Outputs for SubSystem: '<Root>/Input_Process' */
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
          /* Outputs for Atomic SubSystem: '<Root>/Input_Process' */
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

          /* End of Outputs for SubSystem: '<Root>/Input_Process' */
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
          /* Outputs for Atomic SubSystem: '<Root>/Input_Process' */
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

          /* End of Outputs for SubSystem: '<Root>/Input_Process' */
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
        } else {
          /* Outputs for Atomic SubSystem: '<Root>/Input_Process' */
          if (FMS_U.Pilot_Cmd.mode == 1U) {
            FMS_DW.is_c1_FMS = FMS_IN_Mission;
            FMS_DW.local_mode = 1U;
          } else {
            FMS_DW.is_c1_FMS = FMS_IN_Unknow;
            FMS_DW.local_mode = 0U;
          }

          /* End of Outputs for SubSystem: '<Root>/Input_Process' */
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
          /* Outputs for Atomic SubSystem: '<Root>/Input_Process' */
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

          /* End of Outputs for SubSystem: '<Root>/Input_Process' */
        }
      } else {
        guard4 = true;
      }
      break;

     default:
      FMS_B.control_mode = FMS_DW.local_mode;

      /* Outputs for Atomic SubSystem: '<Root>/Input_Process' */
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

      /* End of Outputs for SubSystem: '<Root>/Input_Process' */
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

  /* End of Chart: '<S1>/Control_Mode' */

  /* SwitchCase: '<S1>/Mode_Switch_Case' */
  switch ((int32_T)FMS_B.control_mode) {
   case 2:
    /* Outputs for IfAction SubSystem: '<S1>/Position_Mode' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* BusAssignment: '<S9>/Bus Assignment' incorporates:
     *  BusAssignment: '<S2>/Bus Assignment'
     *  Constant: '<S77>/Constant'
     *  Constant: '<S9>/position_mode'
     *  Delay: '<Root>/Delay'
     *  DiscreteIntegrator: '<S30>/Integrator1'
     *  DiscreteIntegrator: '<S67>/Integrator1'
     *  Product: '<S79>/Multiply'
     *  RelationalOperator: '<S77>/Compare'
     *  SignalConversion: '<S2>/TmpHiddenBufferAtBus AssignmentInport1'
     */
    FMS_Y.FMS_Output.timestamp = rtb_BusAssignment_timestamp;

    /* Outputs for Atomic SubSystem: '<Root>/FMS_State' */
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

    /* End of Outputs for SubSystem: '<Root>/FMS_State' */
    for (i = 0; i < 16; i++) {
      /* Outputs for Atomic SubSystem: '<Root>/FMS_State' */
      FMS_Y.FMS_Output.actuator_cmd[i] = FMS_B.PWM_Cmd;

      /* End of Outputs for SubSystem: '<Root>/FMS_State' */
    }

    /* Outputs for Atomic SubSystem: '<Root>/FMS_State' */
    FMS_Y.FMS_Output.state = rtb_State;
    FMS_Y.FMS_Output.mode = 0U;
    FMS_Y.FMS_Output.reset = (uint8_T)(rtb_State < 2);
    FMS_Y.FMS_Output.reserved = 0U;

    /* End of Outputs for SubSystem: '<Root>/FMS_State' */
    FMS_Y.FMS_Output.mode = 2U;
    FMS_Y.FMS_Output.u_cmd = FMS_DW.Integrator1_DSTATE[0];
    FMS_Y.FMS_Output.v_cmd = FMS_DW.Integrator1_DSTATE[1];
    FMS_Y.FMS_Output.w_cmd = FMS_DW.Integrator1_DSTATE[2];
    FMS_Y.FMS_Output.psi_rate_cmd = FMS_DW.Integrator1_DSTATE_p;

    /* End of BusAssignment: '<S9>/Bus Assignment' */
    /* End of Outputs for SubSystem: '<S1>/Position_Mode' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S1>/Altitude_Hold_Mode' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* BusAssignment: '<S5>/Bus Assignment' incorporates:
     *  BusAssignment: '<S2>/Bus Assignment'
     *  Constant: '<S5>/alt_hold_mode'
     *  Constant: '<S77>/Constant'
     *  Delay: '<Root>/Delay'
     *  DiscreteIntegrator: '<S16>/Integrator1'
     *  DiscreteIntegrator: '<S17>/Integrator1'
     *  DiscreteIntegrator: '<S30>/Integrator1'
     *  DiscreteIntegrator: '<S67>/Integrator1'
     *  Product: '<S79>/Multiply'
     *  RelationalOperator: '<S77>/Compare'
     *  SignalConversion: '<S2>/TmpHiddenBufferAtBus AssignmentInport1'
     */
    FMS_Y.FMS_Output.timestamp = rtb_BusAssignment_timestamp;

    /* Outputs for Atomic SubSystem: '<Root>/FMS_State' */
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

    /* End of Outputs for SubSystem: '<Root>/FMS_State' */
    for (i = 0; i < 16; i++) {
      /* Outputs for Atomic SubSystem: '<Root>/FMS_State' */
      FMS_Y.FMS_Output.actuator_cmd[i] = FMS_B.PWM_Cmd;

      /* End of Outputs for SubSystem: '<Root>/FMS_State' */
    }

    /* Outputs for Atomic SubSystem: '<Root>/FMS_State' */
    FMS_Y.FMS_Output.state = rtb_State;
    FMS_Y.FMS_Output.mode = 0U;
    FMS_Y.FMS_Output.reset = (uint8_T)(rtb_State < 2);
    FMS_Y.FMS_Output.reserved = 0U;

    /* End of Outputs for SubSystem: '<Root>/FMS_State' */
    FMS_Y.FMS_Output.mode = 3U;
    FMS_Y.FMS_Output.phi_cmd = FMS_DW.Integrator1_DSTATE_e;
    FMS_Y.FMS_Output.theta_cmd = FMS_DW.Integrator1_DSTATE_g;
    FMS_Y.FMS_Output.w_cmd = FMS_DW.Integrator1_DSTATE[2];
    FMS_Y.FMS_Output.psi_rate_cmd = FMS_DW.Integrator1_DSTATE_p;

    /* End of BusAssignment: '<S5>/Bus Assignment' */
    /* End of Outputs for SubSystem: '<S1>/Altitude_Hold_Mode' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S1>/Manual_Mode' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* BusAssignment: '<S8>/Bus Assignment' incorporates:
     *  BusAssignment: '<S2>/Bus Assignment'
     *  Constant: '<S14>/Constant'
     *  Constant: '<S14>/Constant1'
     *  Constant: '<S77>/Constant'
     *  Constant: '<S8>/manual_mode'
     *  Delay: '<Root>/Delay'
     *  DiscreteIntegrator: '<S16>/Integrator1'
     *  DiscreteIntegrator: '<S17>/Integrator1'
     *  DiscreteIntegrator: '<S30>/Integrator1'
     *  Gain: '<S14>/Gain'
     *  Product: '<S79>/Multiply'
     *  RelationalOperator: '<S77>/Compare'
     *  SignalConversion: '<S2>/TmpHiddenBufferAtBus AssignmentInport1'
     *  Sum: '<S14>/Add'
     *  Sum: '<S14>/Sum'
     */
    FMS_Y.FMS_Output.timestamp = rtb_BusAssignment_timestamp;

    /* Outputs for Atomic SubSystem: '<Root>/FMS_State' */
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

    /* End of Outputs for SubSystem: '<Root>/FMS_State' */
    for (i = 0; i < 16; i++) {
      /* Outputs for Atomic SubSystem: '<Root>/FMS_State' */
      FMS_Y.FMS_Output.actuator_cmd[i] = FMS_B.PWM_Cmd;

      /* End of Outputs for SubSystem: '<Root>/FMS_State' */
    }

    /* Outputs for Atomic SubSystem: '<Root>/FMS_State' */
    FMS_Y.FMS_Output.state = rtb_State;
    FMS_Y.FMS_Output.mode = 0U;
    FMS_Y.FMS_Output.reset = (uint8_T)(rtb_State < 2);
    FMS_Y.FMS_Output.reserved = 0U;

    /* End of Outputs for SubSystem: '<Root>/FMS_State' */
    FMS_Y.FMS_Output.mode = 4U;
    FMS_Y.FMS_Output.throttle_cmd = (uint32_T)fmodf(floorf
      ((rtb_stick_throttle_raw + 1.0F) * 500.0F), 4.2949673E+9F) + 1000U;
    FMS_Y.FMS_Output.phi_cmd = FMS_DW.Integrator1_DSTATE_e;
    FMS_Y.FMS_Output.theta_cmd = FMS_DW.Integrator1_DSTATE_g;
    FMS_Y.FMS_Output.psi_rate_cmd = FMS_DW.Integrator1_DSTATE_p;

    /* End of BusAssignment: '<S8>/Bus Assignment' */
    /* End of Outputs for SubSystem: '<S1>/Manual_Mode' */
    break;

   case 5:
    /* Outputs for IfAction SubSystem: '<S1>/Acro_Mode' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* BusAssignment: '<S4>/Bus Assignment' incorporates:
     *  BusAssignment: '<S2>/Bus Assignment'
     *  Constant: '<S14>/Constant'
     *  Constant: '<S14>/Constant1'
     *  Constant: '<S4>/Constant'
     *  Constant: '<S77>/Constant'
     *  Delay: '<Root>/Delay'
     *  Gain: '<S11>/Gain'
     *  Gain: '<S11>/Gain1'
     *  Gain: '<S11>/Gain2'
     *  Gain: '<S14>/Gain'
     *  Product: '<S79>/Multiply'
     *  RelationalOperator: '<S77>/Compare'
     *  SignalConversion: '<S2>/TmpHiddenBufferAtBus AssignmentInport1'
     *  Sum: '<S14>/Add'
     *  Sum: '<S14>/Sum'
     */
    FMS_Y.FMS_Output.timestamp = rtb_BusAssignment_timestamp;

    /* Outputs for Atomic SubSystem: '<Root>/FMS_State' */
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

    /* End of Outputs for SubSystem: '<Root>/FMS_State' */
    for (i = 0; i < 16; i++) {
      /* Outputs for Atomic SubSystem: '<Root>/FMS_State' */
      FMS_Y.FMS_Output.actuator_cmd[i] = FMS_B.PWM_Cmd;

      /* End of Outputs for SubSystem: '<Root>/FMS_State' */
    }

    /* Outputs for Atomic SubSystem: '<Root>/FMS_State' */
    FMS_Y.FMS_Output.state = rtb_State;
    FMS_Y.FMS_Output.mode = 0U;
    FMS_Y.FMS_Output.reset = (uint8_T)(rtb_State < 2);
    FMS_Y.FMS_Output.reserved = 0U;

    /* End of Outputs for SubSystem: '<Root>/FMS_State' */
    FMS_Y.FMS_Output.mode = 5U;
    FMS_Y.FMS_Output.throttle_cmd = (uint32_T)fmodf(floorf
      ((rtb_stick_throttle_raw + 1.0F) * 500.0F), 4.2949673E+9F) + 1000U;
    FMS_Y.FMS_Output.p_cmd = 1.04719758F * rtb_Product_idx_1;
    FMS_Y.FMS_Output.q_cmd = -1.04719758F * rtb_stick_pitch_raw;
    FMS_Y.FMS_Output.r_cmd = 1.04719758F * rtb_stick_yaw_raw;

    /* End of BusAssignment: '<S4>/Bus Assignment' */
    /* End of Outputs for SubSystem: '<S1>/Acro_Mode' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S1>/Unknown_Mode' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    /* BusAssignment: '<S10>/Bus Assignment' incorporates:
     *  BusAssignment: '<S2>/Bus Assignment'
     *  Constant: '<S10>/Constant1'
     *  Constant: '<S10>/Constant2'
     *  Constant: '<S77>/Constant'
     *  Delay: '<Root>/Delay'
     *  Product: '<S79>/Multiply'
     *  RelationalOperator: '<S77>/Compare'
     *  SignalConversion: '<S2>/TmpHiddenBufferAtBus AssignmentInport1'
     */
    FMS_Y.FMS_Output.timestamp = rtb_BusAssignment_timestamp;

    /* Outputs for Atomic SubSystem: '<Root>/FMS_State' */
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

    /* End of Outputs for SubSystem: '<Root>/FMS_State' */
    for (i = 0; i < 16; i++) {
      /* Outputs for Atomic SubSystem: '<Root>/FMS_State' */
      FMS_Y.FMS_Output.actuator_cmd[i] = FMS_B.PWM_Cmd;

      /* End of Outputs for SubSystem: '<Root>/FMS_State' */
    }

    /* Outputs for Atomic SubSystem: '<Root>/FMS_State' */
    FMS_Y.FMS_Output.state = rtb_State;
    FMS_Y.FMS_Output.mode = 0U;
    FMS_Y.FMS_Output.reset = (uint8_T)(rtb_State < 2);
    FMS_Y.FMS_Output.reserved = 0U;

    /* End of Outputs for SubSystem: '<Root>/FMS_State' */
    FMS_Y.FMS_Output.mode = 0U;
    FMS_Y.FMS_Output.reset = 1U;

    /* End of BusAssignment: '<S10>/Bus Assignment' */
    /* End of Outputs for SubSystem: '<S1>/Unknown_Mode' */
    break;
  }

  /* End of SwitchCase: '<S1>/Mode_Switch_Case' */

  /* RelationalOperator: '<S26>/Compare' incorporates:
   *  Constant: '<S26>/Constant'
   */
  rtb_LogicalOperator1 = (rtb_Add_b0 != 0.0F);

  /* Chart: '<S20>/Motion_State' incorporates:
   *  Abs: '<S24>/Abs'
   *  Inport: '<Root>/INS_Output'
   */
  if (FMS_DW.temporalCounter_i1_gq < 255U) {
    FMS_DW.temporalCounter_i1_gq++;
  }

  if (FMS_DW.is_active_c3_FMS == 0U) {
    FMS_DW.is_active_c3_FMS = 1U;
    FMS_DW.is_c3_FMS = FMS_IN_Move;
    rtb_state_p = 0;
  } else {
    switch (FMS_DW.is_c3_FMS) {
     case FMS_IN_Brake:
      rtb_state_p = 1;
      if ((fabsf(FMS_U.INS_Output.r) <= 0.1) || (FMS_DW.temporalCounter_i1_gq >=
           250U)) {
        FMS_DW.is_c3_FMS = FMS_IN_Hold;
        rtb_state_p = 2;
      } else {
        if (rtb_LogicalOperator1) {
          FMS_DW.is_c3_FMS = FMS_IN_Move;
          rtb_state_p = 0;
        }
      }
      break;

     case FMS_IN_Hold:
      rtb_state_p = 2;
      if (rtb_LogicalOperator1) {
        FMS_DW.is_c3_FMS = FMS_IN_Move;
        rtb_state_p = 0;
      }
      break;

     default:
      rtb_state_p = 0;
      if (!rtb_LogicalOperator1) {
        FMS_DW.is_c3_FMS = FMS_IN_Brake;
        FMS_DW.temporalCounter_i1_gq = 0U;
        rtb_state_p = 1;
      }
      break;
    }
  }

  /* End of Chart: '<S20>/Motion_State' */

  /* Logic: '<S49>/Logical Operator' incorporates:
   *  Constant: '<S52>/Constant'
   *  RelationalOperator: '<S52>/Compare'
   */
  rtb_LogicalOperator1 = ((rtb_Product_idx_0 != 0.0F) || (rtb_Product_idx_2 !=
    0.0F));

  /* Chart: '<S47>/XY_Motion_SM' incorporates:
   *  Inport: '<Root>/INS_Output'
   *  Math: '<S48>/Math Function'
   *  Math: '<S48>/Math Function1'
   *  Sqrt: '<S48>/Sqrt'
   *  Sum: '<S48>/Add'
   */
  if (FMS_DW.temporalCounter_i1_cu < 1023U) {
    FMS_DW.temporalCounter_i1_cu++;
  }

  if (FMS_DW.is_active_c13_FMS == 0U) {
    FMS_DW.is_active_c13_FMS = 1U;
    FMS_DW.is_c13_FMS = FMS_IN_Move;
    rtb_state_a = 0;
  } else {
    switch (FMS_DW.is_c13_FMS) {
     case FMS_IN_Brake:
      rtb_state_a = 1;
      if ((sqrtf(FMS_U.INS_Output.vn * FMS_U.INS_Output.vn + FMS_U.INS_Output.ve
                 * FMS_U.INS_Output.ve) <= 0.2) || (FMS_DW.temporalCounter_i1_cu
           >= 625U)) {
        FMS_DW.is_c13_FMS = FMS_IN_Hold;
        rtb_state_a = 2;
      } else {
        if (rtb_LogicalOperator1) {
          FMS_DW.is_c13_FMS = FMS_IN_Move;
          rtb_state_a = 0;
        }
      }
      break;

     case FMS_IN_Hold:
      rtb_state_a = 2;
      if (rtb_LogicalOperator1) {
        FMS_DW.is_c13_FMS = FMS_IN_Move;
        rtb_state_a = 0;
      }
      break;

     default:
      rtb_state_a = 0;
      if (!rtb_LogicalOperator1) {
        FMS_DW.is_c13_FMS = FMS_IN_Brake;
        FMS_DW.temporalCounter_i1_cu = 0U;
        rtb_state_a = 1;
      }
      break;
    }
  }

  /* End of Chart: '<S47>/XY_Motion_SM' */

  /* Outputs for Atomic SubSystem: '<Root>/FMS_State' */
  /* RelationalOperator: '<S54>/Compare' incorporates:
   *  BusAssignment: '<S2>/Bus Assignment'
   *  Constant: '<S54>/Constant'
   */
  rtb_LogicalOperator1 = (rtb_State == 2);

  /* End of Outputs for SubSystem: '<Root>/FMS_State' */

  /* RelationalOperator: '<S60>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S60>/Delay Input1'
   *
   * Block description for '<S60>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_Compare_cv = ((int32_T)rtb_LogicalOperator1 > (int32_T)
                    FMS_DW.DelayInput1_DSTATE_m);

  /* RelationalOperator: '<S53>/Compare' incorporates:
   *  Constant: '<S53>/Constant'
   */
  rtb_Compare_nv = (rtb_Product_idx_3 != 0.0F);

  /* Chart: '<S47>/Z_Motion_SM' incorporates:
   *  Abs: '<S48>/Abs'
   *  Inport: '<Root>/INS_Output'
   */
  if (FMS_DW.temporalCounter_i1_c < 511U) {
    FMS_DW.temporalCounter_i1_c++;
  }

  if (FMS_DW.is_active_c10_FMS == 0U) {
    FMS_DW.is_active_c10_FMS = 1U;
    FMS_DW.is_c10_FMS = FMS_IN_Move;
    rtb_state = 0;
  } else {
    switch (FMS_DW.is_c10_FMS) {
     case FMS_IN_Brake:
      rtb_state = 1;
      if ((fabsf(FMS_U.INS_Output.vd) <= 0.2) || (FMS_DW.temporalCounter_i1_c >=
           375U)) {
        FMS_DW.is_c10_FMS = FMS_IN_Hold;
        rtb_state = 2;
      } else {
        if (rtb_Compare_nv) {
          FMS_DW.is_c10_FMS = FMS_IN_Move;
          rtb_state = 0;
        }
      }
      break;

     case FMS_IN_Hold:
      rtb_state = 2;
      if (rtb_Compare_nv) {
        FMS_DW.is_c10_FMS = FMS_IN_Move;
        rtb_state = 0;
      }
      break;

     default:
      rtb_state = 0;
      if (!rtb_Compare_nv) {
        FMS_DW.is_c10_FMS = FMS_IN_Brake;
        FMS_DW.temporalCounter_i1_c = 0U;
        rtb_state = 1;
      }
      break;
    }
  }

  /* End of Chart: '<S47>/Z_Motion_SM' */

  /* RelationalOperator: '<S55>/Compare' incorporates:
   *  Constant: '<S55>/Constant'
   */
  rtb_Compare_nv = (rtb_state_a == 2);
  rtb_FixPtRelationalOperator = (rtb_state == 2);

  /* UnitDelay: '<S59>/Delay Input1'
   *
   * Block description for '<S59>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_LogicalOperator1_i = FMS_DW.DelayInput1_DSTATE_n;

  /* Logic: '<S45>/Logical Operator1' incorporates:
   *  Constant: '<S56>/Constant'
   *  Constant: '<S57>/Constant'
   *  RelationalOperator: '<S56>/Compare'
   *  RelationalOperator: '<S57>/Compare'
   *  UnitDelay: '<S59>/Delay Input1'
   *
   * Block description for '<S59>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_n = ((FMS_B.control_mode == 1U) ||
    (FMS_B.control_mode == 2U));

  /* RelationalOperator: '<S59>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S59>/Delay Input1'
   *
   * Block description for '<S59>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_LogicalOperator1_i = ((int32_T)FMS_DW.DelayInput1_DSTATE_n > (int32_T)
    rtb_LogicalOperator1_i);

  /* Logic: '<S45>/Logical Operator2' incorporates:
   *  Logic: '<S45>/Logical Operator'
   *  RelationalOperator: '<S61>/FixPt Relational Operator'
   *  UnitDelay: '<S61>/Delay Input1'
   *
   * Block description for '<S61>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_LogicalOperator1_i = (((int32_T)rtb_Compare_nv > (int32_T)
    FMS_DW.DelayInput1_DSTATE_i[0]) || rtb_Compare_cv || rtb_LogicalOperator1_i);

  /* Delay: '<S74>/Delay' incorporates:
   *  Inport: '<Root>/INS_Output'
   *  SignalConversion: '<S74>/TmpSignal ConversionAtDelayInport2'
   */
  if (FMS_DW.icLoad != 0) {
    FMS_DW.Delay_DSTATE_g[0] = FMS_U.INS_Output.x_R;
    FMS_DW.Delay_DSTATE_g[1] = FMS_U.INS_Output.y_R;
  }

  /* End of Delay: '<S74>/Delay' */

  /* Switch: '<S74>/Switch1' incorporates:
   *  Inport: '<Root>/INS_Output'
   *  SignalConversion: '<S74>/TmpSignal ConversionAtDelayInport2'
   */
  if (rtb_LogicalOperator1_i) {
    FMS_DW.Delay_DSTATE_g[0] = FMS_U.INS_Output.x_R;
    FMS_DW.Delay_DSTATE_g[1] = FMS_U.INS_Output.y_R;
  }

  /* End of Switch: '<S74>/Switch1' */

  /* UnitDelay: '<S62>/Delay Input1'
   *
   * Block description for '<S62>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_LogicalOperator1_i = FMS_DW.DelayInput1_DSTATE_p;

  /* Logic: '<S45>/Logical Operator4' incorporates:
   *  Constant: '<S58>/Constant'
   *  RelationalOperator: '<S58>/Compare'
   *  UnitDelay: '<S59>/Delay Input1'
   *  UnitDelay: '<S62>/Delay Input1'
   *
   * Block description for '<S59>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S62>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_p = (FMS_DW.DelayInput1_DSTATE_n ||
    (FMS_B.control_mode == 3U));

  /* RelationalOperator: '<S62>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S62>/Delay Input1'
   *
   * Block description for '<S62>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_LogicalOperator1_i = ((int32_T)FMS_DW.DelayInput1_DSTATE_p > (int32_T)
    rtb_LogicalOperator1_i);

  /* Logic: '<S45>/Logical Operator3' incorporates:
   *  Logic: '<S45>/Logical Operator'
   *  RelationalOperator: '<S61>/FixPt Relational Operator'
   *  UnitDelay: '<S61>/Delay Input1'
   *
   * Block description for '<S61>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_LogicalOperator1_i = (((int32_T)rtb_FixPtRelationalOperator > (int32_T)
    FMS_DW.DelayInput1_DSTATE_i[1]) || rtb_Compare_cv || rtb_LogicalOperator1_i);

  /* Delay: '<S75>/Delay' incorporates:
   *  Gain: '<S73>/Gain'
   *  Inport: '<Root>/INS_Output'
   */
  if (FMS_DW.icLoad_a != 0) {
    FMS_DW.Delay_DSTATE_f = -FMS_U.INS_Output.h_R;
  }

  /* End of Delay: '<S75>/Delay' */

  /* Switch: '<S75>/Switch1' incorporates:
   *  Gain: '<S73>/Gain'
   *  Inport: '<Root>/INS_Output'
   */
  if (rtb_LogicalOperator1_i) {
    FMS_DW.Delay_DSTATE_f = -FMS_U.INS_Output.h_R;
  }

  /* End of Switch: '<S75>/Switch1' */

  /* Sum: '<S72>/Sum' incorporates:
   *  Gain: '<S73>/Gain'
   *  Inport: '<Root>/INS_Output'
   */
  rtb_Product_idx_1 = FMS_DW.Delay_DSTATE_g[0] - FMS_U.INS_Output.x_R;
  rtb_Subtract1 = FMS_DW.Delay_DSTATE_g[1] - FMS_U.INS_Output.y_R;
  rtb_stick_pitch_raw = FMS_DW.Delay_DSTATE_f - (-FMS_U.INS_Output.h_R);

  /* Product: '<S72>/Multiply' */
  for (i = 0; i < 3; i++) {
    rtb_MatrixConcatenate3_d[i] = rtb_M_z[i + 6] * rtb_stick_pitch_raw +
      (rtb_M_z[i + 3] * rtb_Subtract1 + rtb_M_z[i] * rtb_Product_idx_1);
  }

  /* End of Product: '<S72>/Multiply' */

  /* Switch: '<S46>/Switch' incorporates:
   *  Constant: '<S63>/Constant'
   *  Constant: '<S68>/Constant'
   *  DeadZone: '<S69>/Dead Zone'
   *  Gain: '<S66>/Gain1'
   *  Gain: '<S66>/Gain2'
   *  RelationalOperator: '<S63>/Compare'
   *  RelationalOperator: '<S68>/Compare'
   *  Switch: '<S65>/Switch1'
   */
  if (rtb_state_a == 2) {
    rtb_Product_idx_1 = FMS_PARAM.XY_P * rtb_MatrixConcatenate3_d[0];
    rtb_Subtract1 = FMS_PARAM.XY_P * rtb_MatrixConcatenate3_d[1];
  } else if (rtb_state_a == 1) {
    /* Switch: '<S65>/Switch1' */
    rtb_Product_idx_1 = 0.0F;
    rtb_Subtract1 = 0.0F;
  } else {
    if (rtb_Product_idx_0 > FMS_PARAM.PITCH_DZ) {
      /* DeadZone: '<S69>/Dead Zone' incorporates:
       *  Switch: '<S65>/Switch1'
       */
      rtb_Product_idx_1 = rtb_Product_idx_0 - FMS_PARAM.PITCH_DZ;
    } else if (rtb_Product_idx_0 >= -FMS_PARAM.PITCH_DZ) {
      /* DeadZone: '<S69>/Dead Zone' incorporates:
       *  Switch: '<S65>/Switch1'
       */
      rtb_Product_idx_1 = 0.0F;
    } else {
      /* DeadZone: '<S69>/Dead Zone' incorporates:
       *  Switch: '<S65>/Switch1'
       */
      rtb_Product_idx_1 = rtb_Product_idx_0 - (-FMS_PARAM.PITCH_DZ);
    }

    /* Switch: '<S65>/Switch1' incorporates:
     *  DeadZone: '<S69>/Dead Zone'
     *  Gain: '<S65>/Gain1'
     *  Gain: '<S69>/Gain'
     */
    rtb_Product_idx_1 = 1.0F / (1.0F - FMS_PARAM.PITCH_DZ) * rtb_Product_idx_1 *
      FMS_PARAM.VEL_XY_LIM;

    /* DeadZone: '<S70>/Dead Zone' incorporates:
     *  Switch: '<S65>/Switch1'
     */
    if (rtb_Product_idx_2 > FMS_PARAM.ROLL_DZ) {
      rtb_Subtract1 = rtb_Product_idx_2 - FMS_PARAM.ROLL_DZ;
    } else if (rtb_Product_idx_2 >= -FMS_PARAM.ROLL_DZ) {
      rtb_Subtract1 = 0.0F;
    } else {
      rtb_Subtract1 = rtb_Product_idx_2 - (-FMS_PARAM.ROLL_DZ);
    }

    /* End of DeadZone: '<S70>/Dead Zone' */

    /* Switch: '<S65>/Switch1' incorporates:
     *  Gain: '<S65>/Gain5'
     *  Gain: '<S70>/Gain'
     */
    rtb_Subtract1 = 1.0F / (1.0F - FMS_PARAM.ROLL_DZ) * rtb_Subtract1 *
      FMS_PARAM.VEL_XY_LIM;
  }

  /* End of Switch: '<S46>/Switch' */

  /* Saturate: '<S46>/Saturation' */
  rtb_stick_throttle_raw = rtb_Product_idx_1;
  if (rtb_Product_idx_1 > FMS_PARAM.VEL_XY_LIM) {
    rtb_stick_throttle_raw = FMS_PARAM.VEL_XY_LIM;
  } else {
    if (rtb_Product_idx_1 < -FMS_PARAM.VEL_XY_LIM) {
      rtb_stick_throttle_raw = -FMS_PARAM.VEL_XY_LIM;
    }
  }

  rtb_Product_idx_1 = rtb_stick_throttle_raw;
  rtb_stick_throttle_raw = rtb_Subtract1;
  if (rtb_Subtract1 > FMS_PARAM.VEL_XY_LIM) {
    rtb_stick_throttle_raw = FMS_PARAM.VEL_XY_LIM;
  } else {
    if (rtb_Subtract1 < -FMS_PARAM.VEL_XY_LIM) {
      rtb_stick_throttle_raw = -FMS_PARAM.VEL_XY_LIM;
    }
  }

  /* End of Saturate: '<S46>/Saturation' */

  /* Switch: '<S46>/Switch1' incorporates:
   *  Constant: '<S64>/Constant'
   *  DeadZone: '<S71>/Dead Zone'
   *  Gain: '<S66>/Gain4'
   *  RelationalOperator: '<S64>/Compare'
   *  Switch: '<S65>/Switch2'
   */
  if (rtb_state == 2) {
    rtb_Subtract1 = FMS_PARAM.Z_P * rtb_MatrixConcatenate3_d[2];
  } else if (rtb_state > 0) {
    /* Switch: '<S65>/Switch2' incorporates:
     *  Constant: '<S65>/brake_speed1'
     */
    rtb_Subtract1 = 0.0F;
  } else {
    if (rtb_Product_idx_3 > FMS_PARAM.THROTTLE_DZ) {
      /* DeadZone: '<S71>/Dead Zone' incorporates:
       *  Switch: '<S65>/Switch2'
       */
      rtb_Product_idx_3 -= FMS_PARAM.THROTTLE_DZ;
    } else if (rtb_Product_idx_3 >= -FMS_PARAM.THROTTLE_DZ) {
      /* DeadZone: '<S71>/Dead Zone' incorporates:
       *  Switch: '<S65>/Switch2'
       */
      rtb_Product_idx_3 = 0.0F;
    } else {
      /* DeadZone: '<S71>/Dead Zone' incorporates:
       *  Switch: '<S65>/Switch2'
       */
      rtb_Product_idx_3 -= -FMS_PARAM.THROTTLE_DZ;
    }

    /* Switch: '<S65>/Switch2' incorporates:
     *  DeadZone: '<S71>/Dead Zone'
     *  Gain: '<S65>/Gain6'
     *  Gain: '<S71>/Gain'
     */
    rtb_Subtract1 = 1.0F / (1.0F - FMS_PARAM.THROTTLE_DZ) * rtb_Product_idx_3 *
      -FMS_PARAM.VEL_Z_LIM;
  }

  /* End of Switch: '<S46>/Switch1' */

  /* Saturate: '<S46>/Saturation1' */
  if (rtb_Subtract1 > FMS_PARAM.VEL_Z_LIM) {
    rtb_Subtract1 = FMS_PARAM.VEL_Z_LIM;
  } else {
    if (rtb_Subtract1 < -FMS_PARAM.VEL_Z_LIM) {
      rtb_Subtract1 = -FMS_PARAM.VEL_Z_LIM;
    }
  }

  /* End of Saturate: '<S46>/Saturation1' */

  /* Product: '<S76>/Multiply1' incorporates:
   *  Constant: '<S76>/const1'
   *  DiscreteIntegrator: '<S67>/Integrator'
   */
  rtb_MatrixConcatenate3_d[0] = FMS_DW.Integrator_DSTATE[0] * 0.05F;
  rtb_MatrixConcatenate3_d[1] = FMS_DW.Integrator_DSTATE[1] * 0.05F;
  rtb_MatrixConcatenate3_d[2] = FMS_DW.Integrator_DSTATE[2] * 0.05F;

  /* Sum: '<S76>/Add' incorporates:
   *  DiscreteIntegrator: '<S67>/Integrator1'
   *  Sum: '<S67>/Subtract'
   */
  rtb_stick_pitch_raw = (FMS_DW.Integrator1_DSTATE[0] - rtb_Product_idx_1) +
    rtb_MatrixConcatenate3_d[0];
  rtb_stick_throttle_raw = (FMS_DW.Integrator1_DSTATE[1] -
    rtb_stick_throttle_raw) + rtb_MatrixConcatenate3_d[1];
  rtb_Subtract1 = (FMS_DW.Integrator1_DSTATE[2] - rtb_Subtract1) +
    rtb_MatrixConcatenate3_d[2];

  /* Signum: '<S76>/Sign' */
  if (rtb_stick_pitch_raw < 0.0F) {
    rtb_Product_idx_3 = -1.0F;
  } else if (rtb_stick_pitch_raw > 0.0F) {
    rtb_Product_idx_3 = 1.0F;
  } else {
    rtb_Product_idx_3 = rtb_stick_pitch_raw;
  }

  /* Sum: '<S76>/Add2' incorporates:
   *  Abs: '<S76>/Abs'
   *  Gain: '<S76>/Gain'
   *  Gain: '<S76>/Gain1'
   *  Product: '<S76>/Multiply2'
   *  Product: '<S76>/Multiply3'
   *  Signum: '<S76>/Sign'
   *  Sqrt: '<S76>/Sqrt'
   *  Sum: '<S76>/Add1'
   *  Sum: '<S76>/Subtract'
   */
  rtb_Product_idx_3 = (sqrtf((8.0F * fabsf(rtb_stick_pitch_raw) + FMS_ConstB.d) *
    FMS_ConstB.d) - FMS_ConstB.d) * 0.5F * rtb_Product_idx_3 +
    rtb_MatrixConcatenate3_d[0];

  /* Sum: '<S76>/Add3' incorporates:
   *  Signum: '<S76>/Sign'
   */
  rtb_Product_idx_1 = rtb_stick_pitch_raw + FMS_ConstB.d;

  /* Sum: '<S76>/Subtract1' incorporates:
   *  Signum: '<S76>/Sign'
   */
  rtb_stick_yaw_raw = rtb_stick_pitch_raw - FMS_ConstB.d;

  /* Signum: '<S76>/Sign1' */
  if (rtb_Product_idx_1 < 0.0F) {
    rtb_Product_idx_1 = -1.0F;
  } else {
    if (rtb_Product_idx_1 > 0.0F) {
      rtb_Product_idx_1 = 1.0F;
    }
  }

  /* Signum: '<S76>/Sign2' */
  if (rtb_stick_yaw_raw < 0.0F) {
    rtb_stick_yaw_raw = -1.0F;
  } else {
    if (rtb_stick_yaw_raw > 0.0F) {
      rtb_stick_yaw_raw = 1.0F;
    }
  }

  /* Sum: '<S76>/Add2' incorporates:
   *  Gain: '<S76>/Gain2'
   *  Product: '<S76>/Multiply4'
   *  Signum: '<S76>/Sign'
   *  Sum: '<S76>/Add4'
   *  Sum: '<S76>/Add5'
   *  Sum: '<S76>/Subtract2'
   */
  rtb_stick_pitch_raw = ((rtb_stick_pitch_raw - rtb_Product_idx_3) +
    rtb_MatrixConcatenate3_d[0]) * ((rtb_Product_idx_1 - rtb_stick_yaw_raw) *
    0.5F) + rtb_Product_idx_3;

  /* Signum: '<S76>/Sign' */
  if (rtb_stick_throttle_raw < 0.0F) {
    rtb_Product_idx_3 = -1.0F;
  } else if (rtb_stick_throttle_raw > 0.0F) {
    rtb_Product_idx_3 = 1.0F;
  } else {
    rtb_Product_idx_3 = rtb_stick_throttle_raw;
  }

  /* Sum: '<S76>/Add2' incorporates:
   *  Abs: '<S76>/Abs'
   *  Gain: '<S76>/Gain'
   *  Gain: '<S76>/Gain1'
   *  Product: '<S76>/Multiply2'
   *  Product: '<S76>/Multiply3'
   *  Signum: '<S76>/Sign'
   *  Sqrt: '<S76>/Sqrt'
   *  Sum: '<S76>/Add1'
   *  Sum: '<S76>/Subtract'
   */
  rtb_Product_idx_3 = (sqrtf((8.0F * fabsf(rtb_stick_throttle_raw) +
    FMS_ConstB.d) * FMS_ConstB.d) - FMS_ConstB.d) * 0.5F * rtb_Product_idx_3 +
    rtb_MatrixConcatenate3_d[1];

  /* Sum: '<S76>/Add3' incorporates:
   *  Signum: '<S76>/Sign'
   */
  rtb_Product_idx_1 = rtb_stick_throttle_raw + FMS_ConstB.d;

  /* Sum: '<S76>/Subtract1' incorporates:
   *  Signum: '<S76>/Sign'
   */
  rtb_stick_yaw_raw = rtb_stick_throttle_raw - FMS_ConstB.d;

  /* Signum: '<S76>/Sign1' */
  if (rtb_Product_idx_1 < 0.0F) {
    rtb_Product_idx_1 = -1.0F;
  } else {
    if (rtb_Product_idx_1 > 0.0F) {
      rtb_Product_idx_1 = 1.0F;
    }
  }

  /* Signum: '<S76>/Sign2' */
  if (rtb_stick_yaw_raw < 0.0F) {
    rtb_stick_yaw_raw = -1.0F;
  } else {
    if (rtb_stick_yaw_raw > 0.0F) {
      rtb_stick_yaw_raw = 1.0F;
    }
  }

  /* Sum: '<S76>/Add2' incorporates:
   *  Gain: '<S76>/Gain2'
   *  Product: '<S76>/Multiply4'
   *  Signum: '<S76>/Sign'
   *  Sum: '<S76>/Add4'
   *  Sum: '<S76>/Add5'
   *  Sum: '<S76>/Subtract2'
   */
  rtb_stick_throttle_raw = ((rtb_stick_throttle_raw - rtb_Product_idx_3) +
    rtb_MatrixConcatenate3_d[1]) * ((rtb_Product_idx_1 - rtb_stick_yaw_raw) *
    0.5F) + rtb_Product_idx_3;

  /* Signum: '<S76>/Sign' */
  if (rtb_Subtract1 < 0.0F) {
    rtb_Product_idx_3 = -1.0F;
  } else if (rtb_Subtract1 > 0.0F) {
    rtb_Product_idx_3 = 1.0F;
  } else {
    rtb_Product_idx_3 = rtb_Subtract1;
  }

  /* Sum: '<S76>/Add2' incorporates:
   *  Abs: '<S76>/Abs'
   *  Gain: '<S76>/Gain'
   *  Gain: '<S76>/Gain1'
   *  Product: '<S76>/Multiply2'
   *  Product: '<S76>/Multiply3'
   *  Signum: '<S76>/Sign'
   *  Sqrt: '<S76>/Sqrt'
   *  Sum: '<S76>/Add1'
   *  Sum: '<S76>/Subtract'
   */
  rtb_Product_idx_3 = (sqrtf((8.0F * fabsf(rtb_Subtract1) + FMS_ConstB.d) *
    FMS_ConstB.d) - FMS_ConstB.d) * 0.5F * rtb_Product_idx_3 +
    rtb_MatrixConcatenate3_d[2];

  /* Sum: '<S76>/Add3' incorporates:
   *  Signum: '<S76>/Sign'
   */
  rtb_Product_idx_1 = rtb_Subtract1 + FMS_ConstB.d;

  /* Sum: '<S76>/Subtract1' incorporates:
   *  Signum: '<S76>/Sign'
   */
  rtb_stick_yaw_raw = rtb_Subtract1 - FMS_ConstB.d;

  /* Signum: '<S76>/Sign1' */
  if (rtb_Product_idx_1 < 0.0F) {
    rtb_Product_idx_1 = -1.0F;
  } else {
    if (rtb_Product_idx_1 > 0.0F) {
      rtb_Product_idx_1 = 1.0F;
    }
  }

  /* Signum: '<S76>/Sign2' */
  if (rtb_stick_yaw_raw < 0.0F) {
    rtb_stick_yaw_raw = -1.0F;
  } else {
    if (rtb_stick_yaw_raw > 0.0F) {
      rtb_stick_yaw_raw = 1.0F;
    }
  }

  /* Sum: '<S76>/Add5' incorporates:
   *  Gain: '<S76>/Gain2'
   *  Product: '<S76>/Multiply4'
   *  Signum: '<S76>/Sign'
   *  Sum: '<S76>/Add2'
   *  Sum: '<S76>/Add4'
   *  Sum: '<S76>/Subtract2'
   */
  rtb_Product_idx_3 += ((rtb_Subtract1 - rtb_Product_idx_3) +
                        rtb_MatrixConcatenate3_d[2]) * ((rtb_Product_idx_1 -
    rtb_stick_yaw_raw) * 0.5F);

  /* RelationalOperator: '<S40>/Compare' incorporates:
   *  Constant: '<S40>/Constant'
   */
  rtb_Compare_cv = (rtb_state_p == 2);

  /* Outputs for Atomic SubSystem: '<Root>/FMS_State' */
  /* RelationalOperator: '<S39>/Compare' incorporates:
   *  BusAssignment: '<S2>/Bus Assignment'
   *  Constant: '<S39>/Constant'
   */
  rtb_LogicalOperator1_i = (rtb_State == 2);

  /* End of Outputs for SubSystem: '<Root>/FMS_State' */

  /* Logic: '<S22>/Logical Operator2' incorporates:
   *  Constant: '<S37>/Constant'
   *  Constant: '<S38>/Constant'
   *  RelationalOperator: '<S37>/Compare'
   *  RelationalOperator: '<S38>/Compare'
   */
  rtb_LogicalOperator2 = ((FMS_B.control_mode >= 1U) || (FMS_B.control_mode <=
    4U));

  /* Delay: '<S33>/Delay' incorporates:
   *  Inport: '<Root>/INS_Output'
   */
  if (FMS_DW.icLoad_k != 0) {
    FMS_DW.Delay_DSTATE_l = FMS_U.INS_Output.psi;
  }

  /* End of Delay: '<S33>/Delay' */

  /* Switch: '<S33>/Switch1' incorporates:
   *  Inport: '<Root>/INS_Output'
   *  Logic: '<S22>/Logical Operator1'
   *  RelationalOperator: '<S41>/FixPt Relational Operator'
   *  RelationalOperator: '<S42>/FixPt Relational Operator'
   *  RelationalOperator: '<S43>/FixPt Relational Operator'
   *  UnitDelay: '<S41>/Delay Input1'
   *  UnitDelay: '<S42>/Delay Input1'
   *  UnitDelay: '<S43>/Delay Input1'
   *
   * Block description for '<S41>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S42>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S43>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (((int32_T)rtb_Compare_cv > (int32_T)FMS_DW.DelayInput1_DSTATE_g) ||
      ((int32_T)rtb_LogicalOperator1_i > (int32_T)FMS_DW.DelayInput1_DSTATE_c) ||
      ((int32_T)rtb_LogicalOperator2 > (int32_T)FMS_DW.DelayInput1_DSTATE_pc)) {
    FMS_DW.Delay_DSTATE_l = FMS_U.INS_Output.psi;
  }

  /* End of Switch: '<S33>/Switch1' */

  /* Switch: '<S21>/Switch' incorporates:
   *  Constant: '<S27>/Constant'
   *  Constant: '<S34>/Constant'
   *  DeadZone: '<S35>/Dead Zone'
   *  Gain: '<S28>/Gain2'
   *  Inport: '<Root>/INS_Output'
   *  RelationalOperator: '<S27>/Compare'
   *  RelationalOperator: '<S34>/Compare'
   *  Sum: '<S31>/Sum'
   *  Switch: '<S29>/Switch1'
   */
  if (rtb_state_p == 2) {
    rtb_Subtract1 = (FMS_DW.Delay_DSTATE_l - FMS_U.INS_Output.psi) *
      FMS_PARAM.YAW_P;
  } else if (rtb_state_p == 1) {
    /* Switch: '<S29>/Switch1' incorporates:
     *  Constant: '<S29>/Constant'
     */
    rtb_Subtract1 = 0.0F;
  } else {
    if (rtb_Add_b0 > FMS_PARAM.YAW_DZ) {
      /* DeadZone: '<S35>/Dead Zone' incorporates:
       *  Switch: '<S29>/Switch1'
       */
      rtb_Add_b0 -= FMS_PARAM.YAW_DZ;
    } else if (rtb_Add_b0 >= -FMS_PARAM.YAW_DZ) {
      /* DeadZone: '<S35>/Dead Zone' incorporates:
       *  Switch: '<S29>/Switch1'
       */
      rtb_Add_b0 = 0.0F;
    } else {
      /* DeadZone: '<S35>/Dead Zone' incorporates:
       *  Switch: '<S29>/Switch1'
       */
      rtb_Add_b0 -= -FMS_PARAM.YAW_DZ;
    }

    /* Switch: '<S29>/Switch1' incorporates:
     *  DeadZone: '<S35>/Dead Zone'
     *  Gain: '<S29>/Gain1'
     *  Gain: '<S35>/Gain'
     */
    rtb_Subtract1 = 1.0F / (1.0F - FMS_PARAM.YAW_DZ) * rtb_Add_b0 *
      FMS_PARAM.YAW_RATE_LIM;
  }

  /* End of Switch: '<S21>/Switch' */

  /* Saturate: '<S21>/Saturation' */
  if (rtb_Subtract1 > FMS_PARAM.YAW_RATE_LIM) {
    rtb_Subtract1 = FMS_PARAM.YAW_RATE_LIM;
  } else {
    if (rtb_Subtract1 < -FMS_PARAM.YAW_RATE_LIM) {
      rtb_Subtract1 = -FMS_PARAM.YAW_RATE_LIM;
    }
  }

  /* End of Saturate: '<S21>/Saturation' */

  /* Sum: '<S30>/Subtract' incorporates:
   *  DiscreteIntegrator: '<S30>/Integrator1'
   */
  rtb_Product_idx_1 = FMS_DW.Integrator1_DSTATE_p - rtb_Subtract1;

  /* Product: '<S36>/Multiply1' incorporates:
   *  Constant: '<S36>/const1'
   *  DiscreteIntegrator: '<S30>/Integrator'
   */
  rtb_Subtract1 = FMS_DW.Integrator_DSTATE_m * 0.04F;

  /* Sum: '<S36>/Add' */
  rtb_Add_b0 = rtb_Product_idx_1 + rtb_Subtract1;

  /* Signum: '<S36>/Sign' */
  if (rtb_Add_b0 < 0.0F) {
    rtb_Product_idx_1 = -1.0F;
  } else if (rtb_Add_b0 > 0.0F) {
    rtb_Product_idx_1 = 1.0F;
  } else {
    rtb_Product_idx_1 = rtb_Add_b0;
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
  rtb_Subtract3_a = (sqrtf((8.0F * fabsf(rtb_Add_b0) + FMS_ConstB.d_l) *
    FMS_ConstB.d_l) - FMS_ConstB.d_l) * 0.5F * rtb_Product_idx_1 + rtb_Subtract1;

  /* Sum: '<S36>/Add4' */
  rtb_Subtract1 += rtb_Add_b0 - rtb_Subtract3_a;

  /* Sum: '<S36>/Add3' */
  rtb_Product_idx_1 = rtb_Add_b0 + FMS_ConstB.d_l;

  /* Sum: '<S36>/Subtract1' */
  rtb_Add_b0 -= FMS_ConstB.d_l;

  /* Signum: '<S36>/Sign1' */
  if (rtb_Product_idx_1 < 0.0F) {
    rtb_Product_idx_1 = -1.0F;
  } else {
    if (rtb_Product_idx_1 > 0.0F) {
      rtb_Product_idx_1 = 1.0F;
    }
  }

  /* End of Signum: '<S36>/Sign1' */

  /* Signum: '<S36>/Sign2' */
  if (rtb_Add_b0 < 0.0F) {
    rtb_Add_b0 = -1.0F;
  } else {
    if (rtb_Add_b0 > 0.0F) {
      rtb_Add_b0 = 1.0F;
    }
  }

  /* End of Signum: '<S36>/Sign2' */

  /* Sum: '<S36>/Add5' incorporates:
   *  Gain: '<S36>/Gain2'
   *  Product: '<S36>/Multiply4'
   *  Sum: '<S36>/Subtract2'
   */
  rtb_Subtract3_a += (rtb_Product_idx_1 - rtb_Add_b0) * 0.5F * rtb_Subtract1;

  /* Sum: '<S36>/Subtract3' */
  rtb_Product_idx_1 = rtb_Subtract3_a - FMS_ConstB.d_l;

  /* Sum: '<S36>/Add6' */
  rtb_stick_yaw_raw = rtb_Subtract3_a + FMS_ConstB.d_l;

  /* Product: '<S36>/Divide' */
  rtb_Divide_n = rtb_Subtract3_a / FMS_ConstB.d_l;

  /* Signum: '<S36>/Sign5' incorporates:
   *  Signum: '<S36>/Sign6'
   */
  if (rtb_Subtract3_a < 0.0F) {
    rtb_Sign5_i = -1.0F;

    /* Signum: '<S36>/Sign6' */
    y = -1.0F;
  } else if (rtb_Subtract3_a > 0.0F) {
    rtb_Sign5_i = 1.0F;

    /* Signum: '<S36>/Sign6' */
    y = 1.0F;
  } else {
    rtb_Sign5_i = rtb_Subtract3_a;

    /* Signum: '<S36>/Sign6' */
    y = rtb_Subtract3_a;
  }

  /* End of Signum: '<S36>/Sign5' */

  /* Product: '<S18>/Multiply1' incorporates:
   *  Constant: '<S18>/const1'
   *  DiscreteIntegrator: '<S16>/Integrator'
   */
  rtb_Subtract3_a = FMS_DW.Integrator_DSTATE_c * 0.04F;

  /* Sum: '<S18>/Add' incorporates:
   *  DiscreteIntegrator: '<S16>/Integrator1'
   *  Gain: '<S12>/Gain'
   *  Sum: '<S16>/Subtract'
   */
  rtb_Subtract1 = (FMS_DW.Integrator1_DSTATE_e - FMS_PARAM.ROLL_PITCH_LIM *
                   rtb_Product_idx_2) + rtb_Subtract3_a;

  /* Signum: '<S18>/Sign' */
  if (rtb_Subtract1 < 0.0F) {
    rtb_Add_b0 = -1.0F;
  } else if (rtb_Subtract1 > 0.0F) {
    rtb_Add_b0 = 1.0F;
  } else {
    rtb_Add_b0 = rtb_Subtract1;
  }

  /* End of Signum: '<S18>/Sign' */

  /* Sum: '<S18>/Add2' incorporates:
   *  Abs: '<S18>/Abs'
   *  Gain: '<S18>/Gain'
   *  Gain: '<S18>/Gain1'
   *  Product: '<S18>/Multiply2'
   *  Product: '<S18>/Multiply3'
   *  Sqrt: '<S18>/Sqrt'
   *  Sum: '<S18>/Add1'
   *  Sum: '<S18>/Subtract'
   */
  rtb_Add_b0 = (sqrtf((8.0F * fabsf(rtb_Subtract1) + FMS_ConstB.d_e) *
                      FMS_ConstB.d_e) - FMS_ConstB.d_e) * 0.5F * rtb_Add_b0 +
    rtb_Subtract3_a;

  /* Sum: '<S18>/Add4' */
  rtb_Add4_k = (rtb_Subtract1 - rtb_Add_b0) + rtb_Subtract3_a;

  /* Sum: '<S18>/Add3' */
  rtb_Product_idx_2 = rtb_Subtract1 + FMS_ConstB.d_e;

  /* Sum: '<S18>/Subtract1' */
  rtb_Subtract1 -= FMS_ConstB.d_e;

  /* Signum: '<S18>/Sign1' */
  if (rtb_Product_idx_2 < 0.0F) {
    rtb_Product_idx_2 = -1.0F;
  } else {
    if (rtb_Product_idx_2 > 0.0F) {
      rtb_Product_idx_2 = 1.0F;
    }
  }

  /* End of Signum: '<S18>/Sign1' */

  /* Signum: '<S18>/Sign2' */
  if (rtb_Subtract1 < 0.0F) {
    rtb_Subtract1 = -1.0F;
  } else {
    if (rtb_Subtract1 > 0.0F) {
      rtb_Subtract1 = 1.0F;
    }
  }

  /* End of Signum: '<S18>/Sign2' */

  /* Sum: '<S18>/Add5' incorporates:
   *  Gain: '<S18>/Gain2'
   *  Product: '<S18>/Multiply4'
   *  Sum: '<S18>/Subtract2'
   */
  rtb_Add_b0 += (rtb_Product_idx_2 - rtb_Subtract1) * 0.5F * rtb_Add4_k;

  /* Sum: '<S18>/Subtract3' */
  rtb_Product_idx_2 = rtb_Add_b0 - FMS_ConstB.d_e;

  /* Sum: '<S18>/Add6' */
  rtb_Add4_k = rtb_Add_b0 + FMS_ConstB.d_e;

  /* Product: '<S18>/Divide' */
  rtb_Divide_h = rtb_Add_b0 / FMS_ConstB.d_e;

  /* Signum: '<S18>/Sign5' incorporates:
   *  Signum: '<S18>/Sign6'
   */
  if (rtb_Add_b0 < 0.0F) {
    rtb_Sign5_k = -1.0F;

    /* Signum: '<S18>/Sign6' */
    y_0 = -1.0F;
  } else if (rtb_Add_b0 > 0.0F) {
    rtb_Sign5_k = 1.0F;

    /* Signum: '<S18>/Sign6' */
    y_0 = 1.0F;
  } else {
    rtb_Sign5_k = rtb_Add_b0;

    /* Signum: '<S18>/Sign6' */
    y_0 = rtb_Add_b0;
  }

  /* End of Signum: '<S18>/Sign5' */

  /* Product: '<S19>/Multiply1' incorporates:
   *  Constant: '<S19>/const1'
   *  DiscreteIntegrator: '<S17>/Integrator'
   */
  rtb_Subtract3_a = FMS_DW.Integrator_DSTATE_h * 0.04F;

  /* Sum: '<S19>/Add' incorporates:
   *  DiscreteIntegrator: '<S17>/Integrator1'
   *  Gain: '<S12>/Gain1'
   *  Sum: '<S17>/Subtract'
   */
  rtb_Subtract1 = (FMS_DW.Integrator1_DSTATE_g - -FMS_PARAM.ROLL_PITCH_LIM *
                   rtb_Product_idx_0) + rtb_Subtract3_a;

  /* Signum: '<S19>/Sign' */
  if (rtb_Subtract1 < 0.0F) {
    rtb_Add_b0 = -1.0F;
  } else if (rtb_Subtract1 > 0.0F) {
    rtb_Add_b0 = 1.0F;
  } else {
    rtb_Add_b0 = rtb_Subtract1;
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
  rtb_Add_b0 = (sqrtf((8.0F * fabsf(rtb_Subtract1) + FMS_ConstB.d_a) *
                      FMS_ConstB.d_a) - FMS_ConstB.d_a) * 0.5F * rtb_Add_b0 +
    rtb_Subtract3_a;

  /* Sum: '<S19>/Add4' */
  rtb_Subtract3_a += rtb_Subtract1 - rtb_Add_b0;

  /* Sum: '<S19>/Add3' */
  rtb_Product_idx_0 = rtb_Subtract1 + FMS_ConstB.d_a;

  /* Sum: '<S19>/Subtract1' */
  rtb_Subtract1 -= FMS_ConstB.d_a;

  /* Signum: '<S19>/Sign1' */
  if (rtb_Product_idx_0 < 0.0F) {
    rtb_Product_idx_0 = -1.0F;
  } else {
    if (rtb_Product_idx_0 > 0.0F) {
      rtb_Product_idx_0 = 1.0F;
    }
  }

  /* End of Signum: '<S19>/Sign1' */

  /* Signum: '<S19>/Sign2' */
  if (rtb_Subtract1 < 0.0F) {
    rtb_Subtract1 = -1.0F;
  } else {
    if (rtb_Subtract1 > 0.0F) {
      rtb_Subtract1 = 1.0F;
    }
  }

  /* End of Signum: '<S19>/Sign2' */

  /* Sum: '<S19>/Add5' incorporates:
   *  Gain: '<S19>/Gain2'
   *  Product: '<S19>/Multiply4'
   *  Sum: '<S19>/Subtract2'
   */
  rtb_Add_b0 += (rtb_Product_idx_0 - rtb_Subtract1) * 0.5F * rtb_Subtract3_a;

  /* Update for DiscreteIntegrator: '<S67>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S67>/Integrator'
   */
  FMS_DW.Integrator1_DSTATE[0] += 0.004F * FMS_DW.Integrator_DSTATE[0];
  FMS_DW.Integrator1_DSTATE[1] += 0.004F * FMS_DW.Integrator_DSTATE[1];
  FMS_DW.Integrator1_DSTATE[2] += 0.004F * FMS_DW.Integrator_DSTATE[2];

  /* Update for DiscreteIntegrator: '<S30>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S30>/Integrator'
   */
  FMS_DW.Integrator1_DSTATE_p += 0.004F * FMS_DW.Integrator_DSTATE_m;

  /* Update for DiscreteIntegrator: '<S17>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S17>/Integrator'
   */
  FMS_DW.Integrator1_DSTATE_g += 0.004F * FMS_DW.Integrator_DSTATE_h;

  /* Update for DiscreteIntegrator: '<S16>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S16>/Integrator'
   */
  FMS_DW.Integrator1_DSTATE_e += 0.004F * FMS_DW.Integrator_DSTATE_c;

  /* Update for UnitDelay: '<S60>/Delay Input1'
   *
   * Block description for '<S60>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_m = rtb_LogicalOperator1;

  /* Update for UnitDelay: '<S61>/Delay Input1'
   *
   * Block description for '<S61>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_i[0] = rtb_Compare_nv;
  FMS_DW.DelayInput1_DSTATE_i[1] = rtb_FixPtRelationalOperator;

  /* Update for Delay: '<S74>/Delay' */
  FMS_DW.icLoad = 0U;

  /* Update for Delay: '<S75>/Delay' */
  FMS_DW.icLoad_a = 0U;

  /* Signum: '<S76>/Sign3' incorporates:
   *  Product: '<S76>/Divide'
   *  Sum: '<S76>/Add6'
   */
  rtb_Product_idx_0 = rtb_stick_pitch_raw + FMS_ConstB.d;

  /* Signum: '<S76>/Sign4' incorporates:
   *  Product: '<S76>/Divide'
   *  Sum: '<S76>/Subtract3'
   */
  rtb_Subtract1 = rtb_stick_pitch_raw - FMS_ConstB.d;

  /* Signum: '<S76>/Sign5' incorporates:
   *  Product: '<S76>/Divide'
   */
  if (rtb_stick_pitch_raw < 0.0F) {
    rtb_Subtract3_a = -1.0F;
  } else if (rtb_stick_pitch_raw > 0.0F) {
    rtb_Subtract3_a = 1.0F;
  } else {
    rtb_Subtract3_a = rtb_stick_pitch_raw;
  }

  /* Signum: '<S76>/Sign3' */
  if (rtb_Product_idx_0 < 0.0F) {
    rtb_Product_idx_0 = -1.0F;
  } else {
    if (rtb_Product_idx_0 > 0.0F) {
      rtb_Product_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S76>/Sign4' */
  if (rtb_Subtract1 < 0.0F) {
    rtb_Subtract1 = -1.0F;
  } else {
    if (rtb_Subtract1 > 0.0F) {
      rtb_Subtract1 = 1.0F;
    }
  }

  /* Signum: '<S76>/Sign6' incorporates:
   *  Product: '<S76>/Divide'
   */
  if (rtb_stick_pitch_raw < 0.0F) {
    rtb_a_idx_0 = -1.0F;
  } else if (rtb_stick_pitch_raw > 0.0F) {
    rtb_a_idx_0 = 1.0F;
  } else {
    rtb_a_idx_0 = rtb_stick_pitch_raw;
  }

  /* Update for DiscreteIntegrator: '<S67>/Integrator' incorporates:
   *  Constant: '<S76>/const'
   *  Gain: '<S76>/Gain3'
   *  Product: '<S76>/Divide'
   *  Product: '<S76>/Multiply5'
   *  Product: '<S76>/Multiply6'
   *  Sum: '<S76>/Subtract4'
   *  Sum: '<S76>/Subtract5'
   *  Sum: '<S76>/Subtract6'
   */
  FMS_DW.Integrator_DSTATE[0] += ((rtb_stick_pitch_raw / FMS_ConstB.d -
    rtb_Subtract3_a) * FMS_ConstB.Gain4 * ((rtb_Product_idx_0 - rtb_Subtract1) *
    0.5F) - rtb_a_idx_0 * 39.224F) * 0.004F;

  /* Signum: '<S76>/Sign3' incorporates:
   *  Product: '<S76>/Divide'
   *  Sum: '<S76>/Add6'
   */
  rtb_Product_idx_0 = rtb_stick_throttle_raw + FMS_ConstB.d;

  /* Signum: '<S76>/Sign4' incorporates:
   *  Product: '<S76>/Divide'
   *  Sum: '<S76>/Subtract3'
   */
  rtb_Subtract1 = rtb_stick_throttle_raw - FMS_ConstB.d;

  /* Signum: '<S76>/Sign5' incorporates:
   *  Product: '<S76>/Divide'
   */
  if (rtb_stick_throttle_raw < 0.0F) {
    rtb_stick_pitch_raw = -1.0F;
  } else if (rtb_stick_throttle_raw > 0.0F) {
    rtb_stick_pitch_raw = 1.0F;
  } else {
    rtb_stick_pitch_raw = rtb_stick_throttle_raw;
  }

  /* Signum: '<S76>/Sign3' */
  if (rtb_Product_idx_0 < 0.0F) {
    rtb_Product_idx_0 = -1.0F;
  } else {
    if (rtb_Product_idx_0 > 0.0F) {
      rtb_Product_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S76>/Sign4' */
  if (rtb_Subtract1 < 0.0F) {
    rtb_Subtract1 = -1.0F;
  } else {
    if (rtb_Subtract1 > 0.0F) {
      rtb_Subtract1 = 1.0F;
    }
  }

  /* Signum: '<S76>/Sign6' incorporates:
   *  Product: '<S76>/Divide'
   */
  if (rtb_stick_throttle_raw < 0.0F) {
    rtb_Subtract3_a = -1.0F;
  } else if (rtb_stick_throttle_raw > 0.0F) {
    rtb_Subtract3_a = 1.0F;
  } else {
    rtb_Subtract3_a = rtb_stick_throttle_raw;
  }

  /* Update for DiscreteIntegrator: '<S67>/Integrator' incorporates:
   *  Constant: '<S76>/const'
   *  Gain: '<S76>/Gain3'
   *  Product: '<S76>/Divide'
   *  Product: '<S76>/Multiply5'
   *  Product: '<S76>/Multiply6'
   *  Sum: '<S76>/Subtract4'
   *  Sum: '<S76>/Subtract5'
   *  Sum: '<S76>/Subtract6'
   */
  FMS_DW.Integrator_DSTATE[1] += ((rtb_stick_throttle_raw / FMS_ConstB.d -
    rtb_stick_pitch_raw) * FMS_ConstB.Gain4 * ((rtb_Product_idx_0 -
    rtb_Subtract1) * 0.5F) - rtb_Subtract3_a * 39.224F) * 0.004F;

  /* Signum: '<S76>/Sign3' incorporates:
   *  Sum: '<S76>/Add6'
   */
  rtb_Product_idx_0 = rtb_Product_idx_3 + FMS_ConstB.d;

  /* Signum: '<S76>/Sign4' incorporates:
   *  Sum: '<S76>/Subtract3'
   */
  rtb_Subtract1 = rtb_Product_idx_3 - FMS_ConstB.d;

  /* Signum: '<S76>/Sign5' */
  if (rtb_Product_idx_3 < 0.0F) {
    rtb_stick_pitch_raw = -1.0F;
  } else if (rtb_Product_idx_3 > 0.0F) {
    rtb_stick_pitch_raw = 1.0F;
  } else {
    rtb_stick_pitch_raw = rtb_Product_idx_3;
  }

  /* Signum: '<S76>/Sign3' */
  if (rtb_Product_idx_0 < 0.0F) {
    rtb_Product_idx_0 = -1.0F;
  } else {
    if (rtb_Product_idx_0 > 0.0F) {
      rtb_Product_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S76>/Sign4' */
  if (rtb_Subtract1 < 0.0F) {
    rtb_Subtract1 = -1.0F;
  } else {
    if (rtb_Subtract1 > 0.0F) {
      rtb_Subtract1 = 1.0F;
    }
  }

  /* Signum: '<S76>/Sign6' */
  if (rtb_Product_idx_3 < 0.0F) {
    rtb_stick_throttle_raw = -1.0F;
  } else if (rtb_Product_idx_3 > 0.0F) {
    rtb_stick_throttle_raw = 1.0F;
  } else {
    rtb_stick_throttle_raw = rtb_Product_idx_3;
  }

  /* Update for DiscreteIntegrator: '<S67>/Integrator' incorporates:
   *  Constant: '<S76>/const'
   *  Gain: '<S76>/Gain3'
   *  Product: '<S76>/Divide'
   *  Product: '<S76>/Multiply5'
   *  Product: '<S76>/Multiply6'
   *  Sum: '<S76>/Subtract4'
   *  Sum: '<S76>/Subtract5'
   *  Sum: '<S76>/Subtract6'
   */
  FMS_DW.Integrator_DSTATE[2] += ((rtb_Product_idx_3 / FMS_ConstB.d -
    rtb_stick_pitch_raw) * FMS_ConstB.Gain4 * ((rtb_Product_idx_0 -
    rtb_Subtract1) * 0.5F) - rtb_stick_throttle_raw * 39.224F) * 0.004F;

  /* Update for UnitDelay: '<S43>/Delay Input1'
   *
   * Block description for '<S43>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_g = rtb_Compare_cv;

  /* Update for UnitDelay: '<S42>/Delay Input1'
   *
   * Block description for '<S42>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_c = rtb_LogicalOperator1_i;

  /* Update for UnitDelay: '<S41>/Delay Input1'
   *
   * Block description for '<S41>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FMS_DW.DelayInput1_DSTATE_pc = rtb_LogicalOperator2;

  /* Update for Delay: '<S33>/Delay' */
  FMS_DW.icLoad_k = 0U;

  /* Signum: '<S36>/Sign3' */
  if (rtb_stick_yaw_raw < 0.0F) {
    rtb_stick_yaw_raw = -1.0F;
  } else {
    if (rtb_stick_yaw_raw > 0.0F) {
      rtb_stick_yaw_raw = 1.0F;
    }
  }

  /* End of Signum: '<S36>/Sign3' */

  /* Signum: '<S36>/Sign4' */
  if (rtb_Product_idx_1 < 0.0F) {
    rtb_Product_idx_1 = -1.0F;
  } else {
    if (rtb_Product_idx_1 > 0.0F) {
      rtb_Product_idx_1 = 1.0F;
    }
  }

  /* End of Signum: '<S36>/Sign4' */

  /* Update for DiscreteIntegrator: '<S30>/Integrator' incorporates:
   *  Constant: '<S36>/const'
   *  Gain: '<S36>/Gain3'
   *  Product: '<S36>/Multiply5'
   *  Product: '<S36>/Multiply6'
   *  Sum: '<S36>/Subtract4'
   *  Sum: '<S36>/Subtract5'
   *  Sum: '<S36>/Subtract6'
   */
  FMS_DW.Integrator_DSTATE_m += ((rtb_Divide_n - rtb_Sign5_i) *
    FMS_ConstB.Gain4_c * ((rtb_stick_yaw_raw - rtb_Product_idx_1) * 0.5F) - y *
    6.28318548F) * 0.004F;

  /* Signum: '<S18>/Sign3' */
  if (rtb_Add4_k < 0.0F) {
    rtb_Add4_k = -1.0F;
  } else {
    if (rtb_Add4_k > 0.0F) {
      rtb_Add4_k = 1.0F;
    }
  }

  /* End of Signum: '<S18>/Sign3' */

  /* Signum: '<S18>/Sign4' */
  if (rtb_Product_idx_2 < 0.0F) {
    rtb_Product_idx_2 = -1.0F;
  } else {
    if (rtb_Product_idx_2 > 0.0F) {
      rtb_Product_idx_2 = 1.0F;
    }
  }

  /* End of Signum: '<S18>/Sign4' */

  /* Update for DiscreteIntegrator: '<S16>/Integrator' incorporates:
   *  Constant: '<S18>/const'
   *  Gain: '<S18>/Gain3'
   *  Product: '<S18>/Multiply5'
   *  Product: '<S18>/Multiply6'
   *  Sum: '<S18>/Subtract4'
   *  Sum: '<S18>/Subtract5'
   *  Sum: '<S18>/Subtract6'
   */
  FMS_DW.Integrator_DSTATE_c += ((rtb_Divide_h - rtb_Sign5_k) *
    FMS_ConstB.Gain4_f * ((rtb_Add4_k - rtb_Product_idx_2) * 0.5F) - y_0 *
    12.566371F) * 0.004F;

  /* Signum: '<S19>/Sign6' incorporates:
   *  Signum: '<S19>/Sign5'
   */
  if (rtb_Add_b0 < 0.0F) {
    y = -1.0F;

    /* Signum: '<S19>/Sign5' */
    y_0 = -1.0F;
  } else if (rtb_Add_b0 > 0.0F) {
    y = 1.0F;

    /* Signum: '<S19>/Sign5' */
    y_0 = 1.0F;
  } else {
    y = rtb_Add_b0;

    /* Signum: '<S19>/Sign5' */
    y_0 = rtb_Add_b0;
  }

  /* End of Signum: '<S19>/Sign6' */

  /* Sum: '<S19>/Add6' */
  rtb_Product_idx_1 = rtb_Add_b0 + FMS_ConstB.d_a;

  /* Sum: '<S19>/Subtract3' */
  rtb_stick_yaw_raw = rtb_Add_b0 - FMS_ConstB.d_a;

  /* Signum: '<S19>/Sign3' */
  if (rtb_Product_idx_1 < 0.0F) {
    rtb_Product_idx_1 = -1.0F;
  } else {
    if (rtb_Product_idx_1 > 0.0F) {
      rtb_Product_idx_1 = 1.0F;
    }
  }

  /* End of Signum: '<S19>/Sign3' */

  /* Signum: '<S19>/Sign4' */
  if (rtb_stick_yaw_raw < 0.0F) {
    rtb_stick_yaw_raw = -1.0F;
  } else {
    if (rtb_stick_yaw_raw > 0.0F) {
      rtb_stick_yaw_raw = 1.0F;
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
  FMS_DW.Integrator_DSTATE_h += ((rtb_Add_b0 / FMS_ConstB.d_a - y_0) *
    FMS_ConstB.Gain4_b * ((rtb_Product_idx_1 - rtb_stick_yaw_raw) * 0.5F) - y *
    12.566371F) * 0.004F;

  /* End of Outputs for SubSystem: '<Root>/Control_Mode' */
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

  /* SystemInitialize for Atomic SubSystem: '<Root>/Input_Process' */
  /* SystemInitialize for Chart: '<S87>/Arm_Event' */
  FMS_DW.is_active_c5_FMS = 0U;
  FMS_DW.is_c5_FMS = FMS_IN_NO_ACTIVE_CHILD;

  /* SystemInitialize for Chart: '<S87>/Disarm_Event' */
  FMS_DW.temporalCounter_i1 = 0U;
  FMS_DW.is_active_c12_FMS = 0U;
  FMS_DW.is_c12_FMS = FMS_IN_NO_ACTIVE_CHILD;

  /* End of SystemInitialize for SubSystem: '<Root>/Input_Process' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/FMS_State' */
  /* SystemInitialize for Chart: '<S2>/State_Management' */
  FMS_DW.temporalCounter_i1_g = 0U;
  FMS_DW.is_active_c4_FMS = 0U;
  FMS_DW.is_c4_FMS = FMS_IN_NO_ACTIVE_CHILD;

  /* End of SystemInitialize for SubSystem: '<Root>/FMS_State' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Control_Mode' */
  /* InitializeConditions for Delay: '<S74>/Delay' */
  FMS_DW.icLoad = 1U;

  /* InitializeConditions for Delay: '<S75>/Delay' */
  FMS_DW.icLoad_a = 1U;

  /* InitializeConditions for Delay: '<S33>/Delay' */
  FMS_DW.icLoad_k = 1U;

  /* SystemInitialize for Chart: '<S1>/Control_Mode' */
  FMS_DW.is_active_c1_FMS = 0U;
  FMS_DW.is_c1_FMS = FMS_IN_NO_ACTIVE_CHILD;

  /* SystemInitialize for Chart: '<S20>/Motion_State' */
  FMS_DW.temporalCounter_i1_gq = 0U;
  FMS_DW.is_active_c3_FMS = 0U;
  FMS_DW.is_c3_FMS = FMS_IN_NO_ACTIVE_CHILD;

  /* SystemInitialize for Chart: '<S47>/XY_Motion_SM' */
  FMS_DW.temporalCounter_i1_cu = 0U;
  FMS_DW.is_active_c13_FMS = 0U;
  FMS_DW.is_c13_FMS = FMS_IN_NO_ACTIVE_CHILD;

  /* SystemInitialize for Chart: '<S47>/Z_Motion_SM' */
  FMS_DW.temporalCounter_i1_c = 0U;
  FMS_DW.is_active_c10_FMS = 0U;
  FMS_DW.is_c10_FMS = FMS_IN_NO_ACTIVE_CHILD;

  /* End of SystemInitialize for SubSystem: '<Root>/Control_Mode' */
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
