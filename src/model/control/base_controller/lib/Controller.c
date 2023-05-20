/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.940
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat May 20 10:48:40 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Controller.h"
#include "Controller_private.h"

const Control_Out_Bus Controller_rtZControl_Out_Bus = {
  0U,                                  /* timestamp */

  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
  /* actuator_cmd */
} ;                                    /* Control_Out_Bus ground */

/* Exported block parameters */
struct_2EnWz3ceFwjQa7SDRNn3C CONTROL_PARAM = {
  1.4F,
  0.2F,
  0.2F,
  0.6F,
  0.1F,
  0.0F,
  -1.0F,
  1.0F,
  -1.0F,
  1.0F,
  -0.15F,
  0.15F,
  -0.1F,
  0.1F,
  5.0F,
  5.0F,
  0.52359879F,
  0.1F,
  0.1F,
  0.15F,
  0.1F,
  0.1F,
  0.2F,
  0.003F,
  0.003F,
  0.001F,
  -0.1F,
  0.1F,
  -0.1F,
  0.1F,
  1.57079637F,
  3.14159274F,
  0.5F
} ;                                    /* Variable: CONTROL_PARAM
                                        * Referenced by:
                                        *   '<S12>/hover_throttle'
                                        *   '<S18>/hover_throttle'
                                        *   '<S24>/hover_throttle'
                                        *   '<S57>/Saturation'
                                        *   '<S33>/Saturation'
                                        *   '<S33>/Saturation1'
                                        *   '<S66>/kd'
                                        *   '<S66>/Saturation'
                                        *   '<S67>/ki'
                                        *   '<S67>/Discrete-Time Integrator'
                                        *   '<S68>/kp'
                                        *   '<S80>/kd'
                                        *   '<S80>/Saturation'
                                        *   '<S81>/ki'
                                        *   '<S81>/Discrete-Time Integrator'
                                        *   '<S82>/kp'
                                        *   '<S50>/Constant1'
                                        *   '<S50>/Constant2'
                                        *   '<S39>/gain1'
                                        *   '<S39>/gain2'
                                        *   '<S39>/gain3'
                                        *   '<S39>/Saturation'
                                        *   '<S40>/gain1'
                                        *   '<S40>/gain2'
                                        *   '<S40>/gain3'
                                        *   '<S40>/Discrete-Time Integrator'
                                        *   '<S41>/gain1'
                                        *   '<S41>/gain2'
                                        *   '<S41>/gain3'
                                        */

struct_biZzOMrg0u3lxrb7POOubF CONTROL_EXPORT = {
  2U,

  { 66, 97, 115, 101, 32, 67, 111, 110, 116, 114, 111, 108, 108, 101, 114, 32,
    118, 48, 46, 50, 46, 52, 0 }
} ;                                    /* Variable: CONTROL_EXPORT
                                        * Referenced by: '<S3>/Constant'
                                        */

/* Block states (default storage) */
DW_Controller_T Controller_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Controller_T Controller_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Controller_T Controller_Y;

/* Real-time model */
RT_MODEL_Controller_T Controller_M_;
RT_MODEL_Controller_T *const Controller_M = &Controller_M_;

/* Model step function */
void Controller_step(void)
{
  /* local block i/o variables */
  real32_T rtb_Add_g[3];
  real32_T rtb_Saturation_i;
  uint16_T rtb_VariantMergeForOutportactua[16];
  real32_T rtb_a_n;
  real32_T rtb_VectorConcatenate[9];
  real32_T rtb_DiscreteTimeIntegrator1_j;
  real32_T rtb_Add3;
  real32_T rtb_Gain_am;
  real32_T rtb_Multiply_ha;
  int32_T i;
  real32_T rtb_VectorConcatenate_0[3];
  real32_T rtb_a;
  real32_T rtb_att_error_B_rad_idx_0;
  real32_T rtb_att_error_B_rad_idx_1;
  real32_T rtb_DiscreteTimeIntegrator5_idx;
  real32_T rtb_DiscreteTimeIntegrator5_i_0;
  real32_T rtb_Saturation1_idx_1;
  real32_T rtb_Saturation1_idx_0;
  real32_T rtb_rate_error_B_radPs_idx_0;
  real32_T rtb_rate_error_B_radPs_idx_1;
  real32_T rtb_rate_error_B_radPs_idx_2;
  real32_T rtb_Saturation_d_idx_0;
  real32_T rtb_Saturation_d_idx_1;
  real32_T rtb_Saturation_d_idx_2;
  real32_T rtb_a_idx_0;
  real32_T rtb_a_idx_1;
  real32_T rtb_Gain_idx_0;
  real32_T rtb_Gain_idx_1;

  /* Trigonometry: '<S64>/Trigonometric Function1' incorporates:
   *  Gain: '<S63>/Gain'
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S64>/Trigonometric Function3'
   */
  rtb_a_idx_0 = arm_cos_f32(-Controller_U.INS_Out.psi);
  rtb_VectorConcatenate[0] = rtb_a_idx_0;

  /* Trigonometry: '<S64>/Trigonometric Function' incorporates:
   *  Gain: '<S63>/Gain'
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S64>/Trigonometric Function2'
   */
  rtb_a_idx_1 = arm_sin_f32(-Controller_U.INS_Out.psi);
  rtb_VectorConcatenate[1] = rtb_a_idx_1;

  /* SignalConversion: '<S64>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S64>/Constant3'
   */
  rtb_VectorConcatenate[2] = 0.0F;

  /* Gain: '<S64>/Gain' */
  rtb_VectorConcatenate[3] = -rtb_a_idx_1;

  /* Trigonometry: '<S64>/Trigonometric Function3' */
  rtb_VectorConcatenate[4] = rtb_a_idx_0;

  /* SignalConversion: '<S64>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S64>/Constant4'
   */
  rtb_VectorConcatenate[5] = 0.0F;

  /* SignalConversion: '<S64>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate[6] = Controller_ConstB.VectorConcatenate3[0];
  rtb_VectorConcatenate[7] = Controller_ConstB.VectorConcatenate3[1];
  rtb_VectorConcatenate[8] = Controller_ConstB.VectorConcatenate3[2];

  /* Product: '<S61>/Multiply' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  SignalConversion: '<S61>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_0[i] = rtb_VectorConcatenate[i + 3] *
      Controller_U.INS_Out.ve + rtb_VectorConcatenate[i] *
      Controller_U.INS_Out.vn;
  }

  /* End of Product: '<S61>/Multiply' */

  /* Sum: '<S58>/Sum' incorporates:
   *  DiscreteIntegrator: '<S62>/Integrator1'
   */
  rtb_a_idx_0 = Controller_DW.Integrator1_DSTATE[0] - rtb_VectorConcatenate_0[0];
  rtb_a_idx_1 = Controller_DW.Integrator1_DSTATE[1] - rtb_VectorConcatenate_0[1];

  /* DiscreteIntegrator: '<S67>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator_PrevRese != 0)) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = Controller_ConstB.Constant;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] >=
        CONTROL_PARAM.VEL_XY_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
        CONTROL_PARAM.VEL_XY_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] <=
          CONTROL_PARAM.VEL_XY_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
          CONTROL_PARAM.VEL_XY_I_MIN;
      }
    }

    Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = Controller_ConstB.Constant;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] >=
        CONTROL_PARAM.VEL_XY_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
        CONTROL_PARAM.VEL_XY_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] <=
          CONTROL_PARAM.VEL_XY_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
          CONTROL_PARAM.VEL_XY_I_MIN;
      }
    }
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] >=
      CONTROL_PARAM.VEL_XY_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = CONTROL_PARAM.VEL_XY_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] <=
        CONTROL_PARAM.VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
        CONTROL_PARAM.VEL_XY_I_MIN;
    }
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] >=
      CONTROL_PARAM.VEL_XY_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = CONTROL_PARAM.VEL_XY_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] <=
        CONTROL_PARAM.VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
        CONTROL_PARAM.VEL_XY_I_MIN;
    }
  }

  /* DiscreteIntegrator: '<S69>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevRes != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] = 0.0F;
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] = 0.0F;
  }

  /* Gain: '<S69>/Gain' incorporates:
   *  DiscreteIntegrator: '<S69>/Discrete-Time Integrator1'
   *  Sum: '<S69>/Sum5'
   */
  rtb_Gain_idx_0 = (rtb_a_idx_0 - Controller_DW.DiscreteTimeIntegrator1_DSTATE[0])
    * 62.831852F;
  rtb_Gain_idx_1 = (rtb_a_idx_1 - Controller_DW.DiscreteTimeIntegrator1_DSTATE[1])
    * 62.831852F;

  /* Switch: '<S69>/Switch' incorporates:
   *  Gain: '<S69>/Gain1'
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_U.FMS_Out.reset > 0) {
    rtb_att_error_B_rad_idx_0 = 0.0F;
    rtb_att_error_B_rad_idx_1 = 0.0F;
  } else {
    rtb_att_error_B_rad_idx_0 = rtb_Gain_idx_0;
    rtb_att_error_B_rad_idx_1 = rtb_Gain_idx_1;
  }

  /* End of Switch: '<S69>/Switch' */

  /* Product: '<S66>/Multiply' incorporates:
   *  Constant: '<S66>/kd'
   */
  rtb_a_n = CONTROL_PARAM.VEL_XY_D * rtb_att_error_B_rad_idx_0;

  /* Saturate: '<S66>/Saturation' */
  if (rtb_a_n > CONTROL_PARAM.VEL_XY_D_MAX) {
    rtb_a_n = CONTROL_PARAM.VEL_XY_D_MAX;
  } else {
    if (rtb_a_n < CONTROL_PARAM.VEL_XY_D_MIN) {
      rtb_a_n = CONTROL_PARAM.VEL_XY_D_MIN;
    }
  }

  /* Product: '<S66>/Multiply' incorporates:
   *  Constant: '<S66>/kd'
   */
  rtb_att_error_B_rad_idx_0 = rtb_a_n;
  rtb_a_n = CONTROL_PARAM.VEL_XY_D * rtb_att_error_B_rad_idx_1;

  /* Saturate: '<S66>/Saturation' */
  if (rtb_a_n > CONTROL_PARAM.VEL_XY_D_MAX) {
    rtb_a_n = CONTROL_PARAM.VEL_XY_D_MAX;
  } else {
    if (rtb_a_n < CONTROL_PARAM.VEL_XY_D_MIN) {
      rtb_a_n = CONTROL_PARAM.VEL_XY_D_MIN;
    }
  }

  /* Switch: '<S60>/Switch' incorporates:
   *  Constant: '<S68>/kp'
   *  Constant: '<S70>/Constant'
   *  Constant: '<S72>/Constant'
   *  Constant: '<S73>/Constant'
   *  DiscreteIntegrator: '<S67>/Discrete-Time Integrator'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S68>/Multiply'
   *  Product: '<S71>/Multiply2'
   *  Product: '<S71>/Multiply3'
   *  RelationalOperator: '<S70>/Compare'
   *  RelationalOperator: '<S72>/Compare'
   *  RelationalOperator: '<S73>/Compare'
   *  S-Function (sfix_bitop): '<S71>/cmd_ax valid'
   *  S-Function (sfix_bitop): '<S71>/cmd_ay valid'
   *  S-Function (sfix_bitop): '<S71>/cmd_u valid'
   *  S-Function (sfix_bitop): '<S71>/cmd_v valid'
   *  Sum: '<S59>/Add'
   *  Sum: '<S71>/Sum1'
   */
  if (Controller_U.FMS_Out.ctrl_mode == 6) {
    rtb_att_error_B_rad_idx_0 = ((Controller_U.FMS_Out.cmd_mask & 64) > 0 ?
      (CONTROL_PARAM.VEL_XY_P * rtb_a_idx_0 +
       Controller_DW.DiscreteTimeIntegrator_DSTATE[0]) +
      rtb_att_error_B_rad_idx_0 : 0.0F) + ((Controller_U.FMS_Out.cmd_mask & 512)
      > 0 ? Controller_U.FMS_Out.ax_cmd : 0.0F);
    rtb_att_error_B_rad_idx_1 = ((Controller_U.FMS_Out.cmd_mask & 128) > 0 ?
      (CONTROL_PARAM.VEL_XY_P * rtb_a_idx_1 +
       Controller_DW.DiscreteTimeIntegrator_DSTATE[1]) + rtb_a_n : 0.0F) +
      ((Controller_U.FMS_Out.cmd_mask & 1024) > 0 ? Controller_U.FMS_Out.ay_cmd :
       0.0F);
  } else {
    rtb_att_error_B_rad_idx_0 += CONTROL_PARAM.VEL_XY_P * rtb_a_idx_0 +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0];
    rtb_att_error_B_rad_idx_1 = (CONTROL_PARAM.VEL_XY_P * rtb_a_idx_1 +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1]) + rtb_a_n;
  }

  /* End of Switch: '<S60>/Switch' */

  /* Trigonometry: '<S57>/Atan' incorporates:
   *  Constant: '<S57>/g'
   *  Gain: '<S57>/Gain1'
   *  Gain: '<S57>/gain'
   *  Product: '<S57>/Divide'
   */
  rtb_a_n = atanf(1.1F * rtb_att_error_B_rad_idx_1 / 9.8055F);
  rtb_att_error_B_rad_idx_1 = atanf(1.1F * -rtb_att_error_B_rad_idx_0 / 9.8055F);

  /* Switch: '<S48>/Switch' incorporates:
   *  Constant: '<S55>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  Logic: '<S48>/Logical Operator'
   *  RelationalOperator: '<S54>/Compare'
   *  RelationalOperator: '<S55>/Compare'
   *  Saturate: '<S57>/Saturation'
   *  Switch: '<S48>/Switch1'
   */
  if ((Controller_U.FMS_Out.ctrl_mode == 3) || (Controller_U.FMS_Out.ctrl_mode ==
       4)) {
    rtb_att_error_B_rad_idx_0 = Controller_U.FMS_Out.phi_cmd;
    rtb_att_error_B_rad_idx_1 = Controller_U.FMS_Out.theta_cmd;
  } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
    /* Switch: '<S56>/Switch' incorporates:
     *  S-Function (sfix_bitop): '<S56>/cmd_phi valid'
     *  S-Function (sfix_bitop): '<S56>/cmd_theta valid'
     *  Saturate: '<S57>/Saturation'
     *  Switch: '<S48>/Switch1'
     */
    if ((Controller_U.FMS_Out.cmd_mask & 8) > 0) {
      rtb_att_error_B_rad_idx_0 = Controller_U.FMS_Out.phi_cmd;
    } else if (rtb_a_n > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      /* Saturate: '<S57>/Saturation' */
      rtb_att_error_B_rad_idx_0 = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    } else if (rtb_a_n < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      /* Saturate: '<S57>/Saturation' */
      rtb_att_error_B_rad_idx_0 = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    } else {
      rtb_att_error_B_rad_idx_0 = rtb_a_n;
    }

    if ((Controller_U.FMS_Out.cmd_mask & 16) > 0) {
      rtb_att_error_B_rad_idx_1 = Controller_U.FMS_Out.theta_cmd;
    } else if (rtb_att_error_B_rad_idx_1 > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      /* Saturate: '<S57>/Saturation' */
      rtb_att_error_B_rad_idx_1 = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_att_error_B_rad_idx_1 < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S57>/Saturation' */
        rtb_att_error_B_rad_idx_1 = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
      }
    }

    /* End of Switch: '<S56>/Switch' */
  } else {
    if (rtb_a_n > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      /* Saturate: '<S57>/Saturation' incorporates:
       *  Switch: '<S48>/Switch1'
       */
      rtb_att_error_B_rad_idx_0 = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    } else if (rtb_a_n < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      /* Saturate: '<S57>/Saturation' incorporates:
       *  Switch: '<S48>/Switch1'
       */
      rtb_att_error_B_rad_idx_0 = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    } else {
      /* Switch: '<S48>/Switch1' incorporates:
       *  Saturate: '<S57>/Saturation'
       */
      rtb_att_error_B_rad_idx_0 = rtb_a_n;
    }

    /* Saturate: '<S57>/Saturation' */
    if (rtb_att_error_B_rad_idx_1 > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      /* Switch: '<S48>/Switch1' */
      rtb_att_error_B_rad_idx_1 = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_att_error_B_rad_idx_1 < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
        /* Switch: '<S48>/Switch1' */
        rtb_att_error_B_rad_idx_1 = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
      }
    }
  }

  /* End of Switch: '<S48>/Switch' */

  /* Sum: '<S49>/Sum' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_a_n = rtb_att_error_B_rad_idx_0 - Controller_U.INS_Out.phi;

  /* Product: '<S52>/Divide1' incorporates:
   *  Abs: '<S52>/Abs'
   *  Constant: '<S52>/const2'
   */
  rtb_Multiply_ha = fabsf(rtb_a_n) / 0.002F;

  /* Product: '<S52>/Divide' incorporates:
   *  Constant: '<S50>/Constant1'
   *  Constant: '<S52>/const1'
   *  Math: '<S52>/Square'
   *  SignalConversion: '<S52>/TmpSignal ConversionAtSquareInport1'
   */
  rtb_Add3 = 9.5993F / (CONTROL_PARAM.ROLL_P * CONTROL_PARAM.ROLL_P);

  /* Signum: '<S52>/Sign' */
  if (rtb_a_n < 0.0F) {
    rtb_DiscreteTimeIntegrator5_idx = -1.0F;
  } else if (rtb_a_n > 0.0F) {
    rtb_DiscreteTimeIntegrator5_idx = 1.0F;
  } else {
    rtb_DiscreteTimeIntegrator5_idx = rtb_a_n;
  }

  /* Switch: '<S52>/Switch' incorporates:
   *  Constant: '<S50>/Constant1'
   *  Gain: '<S52>/Gain1'
   *  Gain: '<S52>/Gain2'
   *  Logic: '<S52>/Logical Operator'
   *  Product: '<S52>/Multiply'
   *  Product: '<S52>/Multiply1'
   *  Product: '<S52>/Multiply2'
   *  Product: '<S52>/Multiply3'
   *  RelationalOperator: '<S52>/Relational Operator'
   *  RelationalOperator: '<S52>/Relational Operator2'
   *  SignalConversion: '<S52>/TmpSignal ConversionAtSquareInport1'
   *  Sqrt: '<S52>/Sqrt'
   *  Sum: '<S52>/Subtract'
   */
  if ((rtb_a_n <= rtb_Add3) && (rtb_a_n >= -rtb_Add3)) {
    rtb_DiscreteTimeIntegrator5_idx = rtb_a_n * CONTROL_PARAM.ROLL_P;
  } else {
    rtb_DiscreteTimeIntegrator5_idx *= sqrtf((rtb_DiscreteTimeIntegrator5_idx *
      rtb_a_n - 0.5F * rtb_Add3) * Controller_ConstB.Gain);
  }

  /* Gain: '<S52>/Gain3' */
  rtb_Add3 = -rtb_Multiply_ha;

  /* Switch: '<S53>/Switch' incorporates:
   *  Gain: '<S52>/Gain3'
   *  RelationalOperator: '<S53>/UpperRelop'
   */
  if (rtb_DiscreteTimeIntegrator5_idx >= -rtb_Multiply_ha) {
    rtb_Add3 = rtb_DiscreteTimeIntegrator5_idx;
  }

  /* Switch: '<S53>/Switch2' incorporates:
   *  RelationalOperator: '<S53>/LowerRelop1'
   */
  if (rtb_DiscreteTimeIntegrator5_idx <= rtb_Multiply_ha) {
    rtb_Multiply_ha = rtb_Add3;
  }

  /* Saturate: '<S33>/Saturation1' */
  if (rtb_Multiply_ha > CONTROL_PARAM.P_Q_CMD_LIM) {
    rtb_Multiply_ha = CONTROL_PARAM.P_Q_CMD_LIM;
  } else {
    if (rtb_Multiply_ha < -CONTROL_PARAM.P_Q_CMD_LIM) {
      rtb_Multiply_ha = -CONTROL_PARAM.P_Q_CMD_LIM;
    }
  }

  /* Product: '<S52>/Divide1' */
  rtb_Saturation1_idx_0 = rtb_Multiply_ha;

  /* Sum: '<S49>/Sum' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_a_n = rtb_att_error_B_rad_idx_1 - Controller_U.INS_Out.theta;

  /* Product: '<S52>/Divide1' incorporates:
   *  Abs: '<S52>/Abs'
   *  Constant: '<S52>/const2'
   */
  rtb_Multiply_ha = fabsf(rtb_a_n) / 0.002F;

  /* Product: '<S52>/Divide' incorporates:
   *  Constant: '<S50>/Constant2'
   *  Constant: '<S52>/const1'
   *  Math: '<S52>/Square'
   *  SignalConversion: '<S52>/TmpSignal ConversionAtSquareInport1'
   */
  rtb_Add3 = 9.5993F / (CONTROL_PARAM.PITCH_P * CONTROL_PARAM.PITCH_P);

  /* Signum: '<S52>/Sign' */
  if (rtb_a_n < 0.0F) {
    rtb_DiscreteTimeIntegrator5_idx = -1.0F;
  } else if (rtb_a_n > 0.0F) {
    rtb_DiscreteTimeIntegrator5_idx = 1.0F;
  } else {
    rtb_DiscreteTimeIntegrator5_idx = rtb_a_n;
  }

  /* Switch: '<S52>/Switch' incorporates:
   *  Constant: '<S50>/Constant2'
   *  Gain: '<S52>/Gain1'
   *  Gain: '<S52>/Gain2'
   *  Logic: '<S52>/Logical Operator'
   *  Product: '<S52>/Multiply'
   *  Product: '<S52>/Multiply1'
   *  Product: '<S52>/Multiply2'
   *  Product: '<S52>/Multiply3'
   *  RelationalOperator: '<S52>/Relational Operator'
   *  RelationalOperator: '<S52>/Relational Operator2'
   *  SignalConversion: '<S52>/TmpSignal ConversionAtSquareInport1'
   *  Sqrt: '<S52>/Sqrt'
   *  Sum: '<S52>/Subtract'
   */
  if ((rtb_a_n <= rtb_Add3) && (rtb_a_n >= -rtb_Add3)) {
    rtb_DiscreteTimeIntegrator5_idx = rtb_a_n * CONTROL_PARAM.PITCH_P;
  } else {
    rtb_DiscreteTimeIntegrator5_idx *= sqrtf((rtb_DiscreteTimeIntegrator5_idx *
      rtb_a_n - 0.5F * rtb_Add3) * Controller_ConstB.Gain);
  }

  /* Gain: '<S52>/Gain3' */
  rtb_Add3 = -rtb_Multiply_ha;

  /* Switch: '<S53>/Switch' incorporates:
   *  Gain: '<S52>/Gain3'
   *  RelationalOperator: '<S53>/UpperRelop'
   */
  if (rtb_DiscreteTimeIntegrator5_idx >= -rtb_Multiply_ha) {
    rtb_Add3 = rtb_DiscreteTimeIntegrator5_idx;
  }

  /* Switch: '<S53>/Switch2' incorporates:
   *  RelationalOperator: '<S53>/LowerRelop1'
   */
  if (rtb_DiscreteTimeIntegrator5_idx <= rtb_Multiply_ha) {
    rtb_Multiply_ha = rtb_Add3;
  }

  /* Saturate: '<S33>/Saturation1' */
  if (rtb_Multiply_ha > CONTROL_PARAM.P_Q_CMD_LIM) {
    rtb_Multiply_ha = CONTROL_PARAM.P_Q_CMD_LIM;
  } else {
    if (rtb_Multiply_ha < -CONTROL_PARAM.P_Q_CMD_LIM) {
      rtb_Multiply_ha = -CONTROL_PARAM.P_Q_CMD_LIM;
    }
  }

  /* Saturate: '<S33>/Saturation' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_U.FMS_Out.psi_rate_cmd > CONTROL_PARAM.R_CMD_LIM) {
    rtb_DiscreteTimeIntegrator1_j = CONTROL_PARAM.R_CMD_LIM;
  } else if (Controller_U.FMS_Out.psi_rate_cmd < -CONTROL_PARAM.R_CMD_LIM) {
    rtb_DiscreteTimeIntegrator1_j = -CONTROL_PARAM.R_CMD_LIM;
  } else {
    rtb_DiscreteTimeIntegrator1_j = Controller_U.FMS_Out.psi_rate_cmd;
  }

  /* End of Saturate: '<S33>/Saturation' */

  /* Trigonometry: '<S43>/Sin' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_a_n = arm_sin_f32(Controller_U.INS_Out.phi);

  /* Trigonometry: '<S43>/Cos1' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_att_error_B_rad_idx_0 = arm_cos_f32(Controller_U.INS_Out.theta);

  /* Product: '<S43>/Multiply3' */
  rtb_DiscreteTimeIntegrator5_idx = rtb_a_n * rtb_att_error_B_rad_idx_0 *
    rtb_DiscreteTimeIntegrator1_j;

  /* Trigonometry: '<S43>/Cos' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Add3 = arm_cos_f32(Controller_U.INS_Out.phi);

  /* Product: '<S43>/Multiply1' */
  rtb_DiscreteTimeIntegrator5_i_0 = rtb_Add3 * rtb_Multiply_ha;

  /* Product: '<S43>/Multiply4' */
  rtb_a_n *= rtb_Multiply_ha;

  /* Switch: '<S34>/Switch' incorporates:
   *  Constant: '<S44>/Constant'
   *  Constant: '<S45>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  RelationalOperator: '<S44>/Compare'
   *  RelationalOperator: '<S45>/Compare'
   *  Switch: '<S34>/Switch1'
   */
  if (Controller_U.FMS_Out.ctrl_mode == 2) {
    rtb_att_error_B_rad_idx_1 = Controller_U.FMS_Out.p_cmd;
    rtb_DiscreteTimeIntegrator5_idx = Controller_U.FMS_Out.q_cmd;
    rtb_DiscreteTimeIntegrator5_i_0 = Controller_U.FMS_Out.r_cmd;
  } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
    /* Switch: '<S46>/Switch' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S43>/Multiply'
     *  Product: '<S43>/Multiply1'
     *  Product: '<S43>/Multiply5'
     *  S-Function (sfix_bitop): '<S46>/cmd_p valid'
     *  S-Function (sfix_bitop): '<S46>/cmd_q valid'
     *  S-Function (sfix_bitop): '<S46>/cmd_r valid'
     *  Sum: '<S43>/Add'
     *  Sum: '<S43>/Add1'
     *  Sum: '<S43>/Add2'
     *  Switch: '<S34>/Switch1'
     *  Trigonometry: '<S43>/Sin1'
     */
    if ((Controller_U.FMS_Out.cmd_mask & 1) > 0) {
      rtb_att_error_B_rad_idx_1 = Controller_U.FMS_Out.p_cmd;
    } else {
      rtb_att_error_B_rad_idx_1 = rtb_Saturation1_idx_0 - arm_sin_f32
        (Controller_U.INS_Out.theta) * rtb_DiscreteTimeIntegrator1_j;
    }

    if ((Controller_U.FMS_Out.cmd_mask & 2) > 0) {
      rtb_DiscreteTimeIntegrator5_idx = Controller_U.FMS_Out.q_cmd;
    } else {
      rtb_DiscreteTimeIntegrator5_idx += rtb_DiscreteTimeIntegrator5_i_0;
    }

    if ((Controller_U.FMS_Out.cmd_mask & 4) > 0) {
      rtb_DiscreteTimeIntegrator5_i_0 = Controller_U.FMS_Out.r_cmd;
    } else {
      rtb_DiscreteTimeIntegrator5_i_0 = rtb_Add3 * rtb_att_error_B_rad_idx_0 *
        rtb_DiscreteTimeIntegrator1_j - rtb_a_n;
    }

    /* End of Switch: '<S46>/Switch' */
  } else {
    /* Switch: '<S34>/Switch1' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S43>/Multiply'
     *  Product: '<S43>/Multiply3'
     *  Product: '<S43>/Multiply5'
     *  Sum: '<S43>/Add'
     *  Sum: '<S43>/Add1'
     *  Sum: '<S43>/Add2'
     *  Trigonometry: '<S43>/Sin1'
     */
    rtb_att_error_B_rad_idx_1 = rtb_Saturation1_idx_0 - arm_sin_f32
      (Controller_U.INS_Out.theta) * rtb_DiscreteTimeIntegrator1_j;
    rtb_DiscreteTimeIntegrator5_idx += rtb_DiscreteTimeIntegrator5_i_0;
    rtb_DiscreteTimeIntegrator5_i_0 = rtb_Add3 * rtb_att_error_B_rad_idx_0 *
      rtb_DiscreteTimeIntegrator1_j - rtb_a_n;
  }

  /* End of Switch: '<S34>/Switch' */

  /* Sum: '<S35>/Sum' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_rate_error_B_radPs_idx_0 = rtb_att_error_B_rad_idx_1 -
    Controller_U.INS_Out.p;
  rtb_rate_error_B_radPs_idx_1 = rtb_DiscreteTimeIntegrator5_idx -
    Controller_U.INS_Out.q;
  rtb_rate_error_B_radPs_idx_2 = rtb_DiscreteTimeIntegrator5_i_0 -
    Controller_U.INS_Out.r;

  /* DiscreteIntegrator: '<S38>/Discrete-Time Integrator5' */
  if (Controller_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] =
      rtb_rate_error_B_radPs_idx_0;
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] =
      rtb_rate_error_B_radPs_idx_1;
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] =
      rtb_rate_error_B_radPs_idx_2;
  }

  /* DiscreteIntegrator: '<S40>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator_PrevRe_g != 0)) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] =
      Controller_ConstB.Constant_n[0];
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] >=
        CONTROL_PARAM.RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] =
        CONTROL_PARAM.RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] <=
          CONTROL_PARAM.RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] =
          CONTROL_PARAM.RATE_I_MIN;
      }
    }

    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] =
      Controller_ConstB.Constant_n[1];
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] >=
        CONTROL_PARAM.RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] =
        CONTROL_PARAM.RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] <=
          CONTROL_PARAM.RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] =
          CONTROL_PARAM.RATE_I_MIN;
      }
    }

    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] =
      Controller_ConstB.Constant_n[2];
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] >=
        CONTROL_PARAM.RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] =
        CONTROL_PARAM.RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] <=
          CONTROL_PARAM.RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] =
          CONTROL_PARAM.RATE_I_MIN;
      }
    }
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] >=
      CONTROL_PARAM.RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] =
        CONTROL_PARAM.RATE_I_MIN;
    }
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] >=
      CONTROL_PARAM.RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] =
        CONTROL_PARAM.RATE_I_MIN;
    }
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] >=
      CONTROL_PARAM.RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] =
        CONTROL_PARAM.RATE_I_MIN;
    }
  }

  /* DiscreteIntegrator: '<S42>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevR_i != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[0] = 0.0F;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[1] = 0.0F;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[2] = 0.0F;
  }

  /* Gain: '<S42>/Gain' incorporates:
   *  DiscreteIntegrator: '<S38>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S42>/Discrete-Time Integrator1'
   *  Sum: '<S42>/Sum5'
   */
  rtb_att_error_B_rad_idx_1 = (Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] -
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[0]) * 188.49556F;
  rtb_DiscreteTimeIntegrator5_idx =
    (Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] -
     Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[1]) * 188.49556F;
  rtb_DiscreteTimeIntegrator5_i_0 =
    (Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] -
     Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[2]) * 188.49556F;

  /* Switch: '<S42>/Switch' incorporates:
   *  Gain: '<S42>/Gain1'
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_U.FMS_Out.reset > 0) {
    rtb_Saturation_d_idx_0 = 0.0F;
    rtb_Saturation_d_idx_1 = 0.0F;
    rtb_Saturation_d_idx_2 = 0.0F;
  } else {
    rtb_Saturation_d_idx_0 = rtb_att_error_B_rad_idx_1;
    rtb_Saturation_d_idx_1 = rtb_DiscreteTimeIntegrator5_idx;
    rtb_Saturation_d_idx_2 = rtb_DiscreteTimeIntegrator5_i_0;
  }

  /* End of Switch: '<S42>/Switch' */

  /* Product: '<S39>/Multiply' incorporates:
   *  Constant: '<S39>/gain1'
   */
  rtb_a_n = CONTROL_PARAM.ROLL_RATE_D * rtb_Saturation_d_idx_0;

  /* Saturate: '<S39>/Saturation' */
  if (rtb_a_n > CONTROL_PARAM.RATE_D_MAX) {
    rtb_a_n = CONTROL_PARAM.RATE_D_MAX;
  } else {
    if (rtb_a_n < CONTROL_PARAM.RATE_D_MIN) {
      rtb_a_n = CONTROL_PARAM.RATE_D_MIN;
    }
  }

  /* Product: '<S39>/Multiply' incorporates:
   *  Constant: '<S39>/gain2'
   */
  rtb_Saturation_d_idx_0 = rtb_a_n;
  rtb_a_n = CONTROL_PARAM.PITCH_RATE_D * rtb_Saturation_d_idx_1;

  /* Saturate: '<S39>/Saturation' */
  if (rtb_a_n > CONTROL_PARAM.RATE_D_MAX) {
    rtb_a_n = CONTROL_PARAM.RATE_D_MAX;
  } else {
    if (rtb_a_n < CONTROL_PARAM.RATE_D_MIN) {
      rtb_a_n = CONTROL_PARAM.RATE_D_MIN;
    }
  }

  /* Product: '<S39>/Multiply' incorporates:
   *  Constant: '<S39>/gain3'
   */
  rtb_Saturation_d_idx_1 = rtb_a_n;
  rtb_a_n = CONTROL_PARAM.YAW_RATE_D * rtb_Saturation_d_idx_2;

  /* Saturate: '<S39>/Saturation' */
  if (rtb_a_n > CONTROL_PARAM.RATE_D_MAX) {
    rtb_a_n = CONTROL_PARAM.RATE_D_MAX;
  } else {
    if (rtb_a_n < CONTROL_PARAM.RATE_D_MIN) {
      rtb_a_n = CONTROL_PARAM.RATE_D_MIN;
    }
  }

  /* Sum: '<S36>/Add' incorporates:
   *  Constant: '<S41>/gain1'
   *  Constant: '<S41>/gain2'
   *  Constant: '<S41>/gain3'
   *  DiscreteIntegrator: '<S38>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S40>/Discrete-Time Integrator'
   *  Product: '<S41>/Multiply'
   */
  rtb_Add_g[0] = (CONTROL_PARAM.ROLL_RATE_P *
                  Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] +
                  Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0]) +
    rtb_Saturation_d_idx_0;
  rtb_Add_g[1] = (CONTROL_PARAM.PITCH_RATE_P *
                  Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] +
                  Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1]) +
    rtb_Saturation_d_idx_1;
  rtb_Add_g[2] = (CONTROL_PARAM.YAW_RATE_P *
                  Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] +
                  Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2]) + rtb_a_n;

  /* Gain: '<S76>/Gain' incorporates:
   *  DiscreteIntegrator: '<S78>/Integrator1'
   *  Inport: '<Root>/INS_Out'
   *  Sum: '<S76>/Sum1'
   */
  rtb_Add3 = -(Controller_DW.Integrator1_DSTATE_p - Controller_U.INS_Out.vd);

  /* DiscreteIntegrator: '<S81>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator_PrevRe_m != 0)) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m = Controller_ConstB.Constant_b;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m >=
        CONTROL_PARAM.VEL_Z_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m = CONTROL_PARAM.VEL_Z_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m <=
          CONTROL_PARAM.VEL_Z_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_m =
          CONTROL_PARAM.VEL_Z_I_MIN;
      }
    }
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m >= CONTROL_PARAM.VEL_Z_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m = CONTROL_PARAM.VEL_Z_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m <=
        CONTROL_PARAM.VEL_Z_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m = CONTROL_PARAM.VEL_Z_I_MIN;
    }
  }

  /* DiscreteIntegrator: '<S83>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_Prev_iy != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_h = 0.0F;
  }

  /* Gain: '<S83>/Gain' incorporates:
   *  DiscreteIntegrator: '<S83>/Discrete-Time Integrator1'
   *  Sum: '<S83>/Sum5'
   */
  rtb_Gain_am = (rtb_Add3 - Controller_DW.DiscreteTimeIntegrator1_DSTAT_h) *
    62.831852F;

  /* Switch: '<S83>/Switch' incorporates:
   *  Gain: '<S83>/Gain1'
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_U.FMS_Out.reset > 0) {
    rtb_a_n = 0.0F;
  } else {
    rtb_a_n = rtb_Gain_am;
  }

  /* End of Switch: '<S83>/Switch' */

  /* Product: '<S80>/Multiply' incorporates:
   *  Constant: '<S80>/kd'
   */
  rtb_a_n *= CONTROL_PARAM.VEL_Z_D;

  /* Saturate: '<S80>/Saturation' */
  if (rtb_a_n > CONTROL_PARAM.VEL_Z_D_MAX) {
    rtb_a_n = CONTROL_PARAM.VEL_Z_D_MAX;
  } else {
    if (rtb_a_n < CONTROL_PARAM.VEL_Z_D_MIN) {
      rtb_a_n = CONTROL_PARAM.VEL_Z_D_MIN;
    }
  }

  /* End of Saturate: '<S80>/Saturation' */

  /* Sum: '<S77>/Add' incorporates:
   *  Constant: '<S82>/kp'
   *  DiscreteIntegrator: '<S81>/Discrete-Time Integrator'
   *  Product: '<S82>/Multiply'
   */
  rtb_DiscreteTimeIntegrator1_j = (CONTROL_PARAM.VEL_Z_P * rtb_Add3 +
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m) + rtb_a_n;

  /* Product: '<S75>/Multiply' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S75>/Cos'
   *  Trigonometry: '<S75>/Cos1'
   */
  rtb_a_n = arm_cos_f32(Controller_U.INS_Out.phi) * arm_cos_f32
    (Controller_U.INS_Out.theta);

  /* Saturate: '<S75>/Saturation1' */
  if (rtb_a_n > 1.0F) {
    rtb_Saturation1_idx_0 = 1.0F;
  } else if (rtb_a_n < 0.5F) {
    rtb_Saturation1_idx_0 = 0.5F;
  } else {
    rtb_Saturation1_idx_0 = rtb_a_n;
  }

  /* End of Saturate: '<S75>/Saturation1' */

  /* Gain: '<S75>/Gain' */
  rtb_a_n *= 2.0F;

  /* Saturate: '<S75>/Saturation' */
  if (rtb_a_n > 1.0F) {
    rtb_a_n = 1.0F;
  } else {
    if (rtb_a_n < 0.0F) {
      rtb_a_n = 0.0F;
    }
  }

  /* End of Saturate: '<S75>/Saturation' */

  /* Product: '<S75>/Multiply1' incorporates:
   *  Constant: '<S75>/Constant'
   *  Product: '<S75>/Divide'
   */
  rtb_a_n *= 1.0F / rtb_Saturation1_idx_0 * rtb_DiscreteTimeIntegrator1_j;

  /* Saturate: '<S74>/Saturation' */
  if (rtb_a_n > 0.35F) {
    rtb_Saturation_i = 0.35F;
  } else if (rtb_a_n < -0.35F) {
    rtb_Saturation_i = -0.35F;
  } else {
    rtb_Saturation_i = rtb_a_n;
  }

  /* End of Saturate: '<S74>/Saturation' */

  /* Outputs for Atomic SubSystem: '<S2>/Control_Allocation' */
#if AIRFRAME == 3

  /* Output and update for atomic system: '<S4>/Coxial_Quadcopter_x' */
  {
    uint16_T rtb_throttle_cmd;
    uint16_T rtb_MultiportSwitch[8];
    int32_T i_n;
    real32_T tmp_n;
    real32_T tmp_d;
    real32_T tmp_a;
    real32_T u0_n;
    uint16_T u0_d;

    /* MultiPortSwitch: '<S11>/Multiport Switch' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    switch (Controller_U.FMS_Out.status) {
     case 1:
      for (i_n = 0; i_n < 8; i_n++) {
        rtb_MultiportSwitch[i_n] = 1000U;
      }
      break;

     case 2:
      for (i_n = 0; i_n < 8; i_n++) {
        rtb_MultiportSwitch[i_n] = 1150U;
      }
      break;

     case 3:
      /* Switch: '<S10>/Switch' incorporates:
       *  Constant: '<S14>/Constant'
       *  Logic: '<S10>/Logical Operator'
       *  RelationalOperator: '<S13>/Compare'
       *  RelationalOperator: '<S14>/Compare'
       *  Saturate: '<S7>/Saturation2'
       *  Switch: '<S10>/Switch1'
       */
      if ((Controller_U.FMS_Out.ctrl_mode == 1) ||
          (Controller_U.FMS_Out.ctrl_mode == 2) ||
          (Controller_U.FMS_Out.ctrl_mode == 3)) {
        rtb_throttle_cmd = Controller_U.FMS_Out.throttle_cmd;
      } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
        /* Switch: '<S15>/Switch' incorporates:
         *  Constant: '<S12>/Constant1'
         *  DataTypeConversion: '<S12>/Data Type Conversion'
         *  Gain: '<S12>/Gain1'
         *  S-Function (sfix_bitop): '<S15>/cmd_throttle valid'
         *  Saturate: '<S7>/Saturation2'
         *  Sum: '<S12>/Sum1'
         *  Switch: '<S10>/Switch1'
         */
        if ((Controller_U.FMS_Out.cmd_mask & 4096) > 0) {
          rtb_throttle_cmd = Controller_U.FMS_Out.throttle_cmd;
        } else {
          if (rtb_Saturation_i > 1.0F) {
            /* Saturate: '<S7>/Saturation2' */
            u0_n = 1.0F;
          } else if (rtb_Saturation_i < -1.0F) {
            /* Saturate: '<S7>/Saturation2' */
            u0_n = -1.0F;
          } else {
            /* Saturate: '<S7>/Saturation2' */
            u0_n = rtb_Saturation_i;
          }

          /* Sum: '<S12>/Sum' incorporates:
           *  Constant: '<S12>/hover_throttle'
           *  Saturate: '<S7>/Saturation2'
           */
          u0_n += CONTROL_PARAM.HOVER_THRO;

          /* Saturate: '<S12>/Saturation' */
          if (u0_n > 1.0F) {
            u0_n = 1.0F;
          } else {
            if (u0_n < 0.0F) {
              u0_n = 0.0F;
            }
          }

          rtb_throttle_cmd = (uint16_T)((uint32_T)fmodf(floorf(1000.0F * u0_n),
            4.2949673E+9F) + 1000U);
        }

        /* End of Switch: '<S15>/Switch' */
      } else {
        if (rtb_Saturation_i > 1.0F) {
          /* Saturate: '<S7>/Saturation2' */
          u0_n = 1.0F;
        } else if (rtb_Saturation_i < -1.0F) {
          /* Saturate: '<S7>/Saturation2' */
          u0_n = -1.0F;
        } else {
          /* Saturate: '<S7>/Saturation2' */
          u0_n = rtb_Saturation_i;
        }

        /* Sum: '<S12>/Sum' incorporates:
         *  Constant: '<S12>/hover_throttle'
         *  Saturate: '<S7>/Saturation2'
         */
        u0_n += CONTROL_PARAM.HOVER_THRO;

        /* Saturate: '<S12>/Saturation' */
        if (u0_n > 1.0F) {
          u0_n = 1.0F;
        } else {
          if (u0_n < 0.0F) {
            u0_n = 0.0F;
          }
        }

        /* Switch: '<S10>/Switch1' incorporates:
         *  Constant: '<S12>/Constant1'
         *  DataTypeConversion: '<S12>/Data Type Conversion'
         *  Gain: '<S12>/Gain1'
         *  Sum: '<S12>/Sum1'
         */
        rtb_throttle_cmd = (uint16_T)((uint32_T)fmodf(floorf(1000.0F * u0_n),
          4.2949673E+9F) + 1000U);
      }

      /* End of Switch: '<S10>/Switch' */

      /* Saturate: '<S7>/Saturation1' */
      if (rtb_Add_g[0] > 1.0F) {
        tmp_n = 1.0F;
      } else if (rtb_Add_g[0] < -1.0F) {
        tmp_n = -1.0F;
      } else {
        tmp_n = rtb_Add_g[0];
      }

      if (rtb_Add_g[1] > 1.0F) {
        tmp_d = 1.0F;
      } else if (rtb_Add_g[1] < -1.0F) {
        tmp_d = -1.0F;
      } else {
        tmp_d = rtb_Add_g[1];
      }

      if (rtb_Add_g[2] > 1.0F) {
        tmp_a = 1.0F;
      } else if (rtb_Add_g[2] < -1.0F) {
        tmp_a = -1.0F;
      } else {
        tmp_a = rtb_Add_g[2];
      }

      /* End of Saturate: '<S7>/Saturation1' */

      /* Product: '<S7>/Multiply' */
      for (i_n = 0; i_n < 8; i_n++) {
        /* Saturate: '<S7>/Saturation' incorporates:
         *  Constant: '<S7>/Effective_Matrix'
         *  Gain: '<S7>/Gain'
         *  Sum: '<S7>/Add'
         */
        u0_n = fmodf(floorf(1000.0F *
                            (Controller_ConstP.Effective_Matrix_Value[i_n + 16] *
                             tmp_a +
                             (Controller_ConstP.Effective_Matrix_Value[i_n + 8] *
                              tmp_d +
                              Controller_ConstP.Effective_Matrix_Value[i_n] *
                              tmp_n))), 65536.0F);
        u0_d = (uint16_T)((uint32_T)(u0_n < 0.0F ? (int32_T)(uint16_T)-(int16_T)
          (uint16_T)-u0_n : (int32_T)(uint16_T)u0_n) + rtb_throttle_cmd);
        if (u0_d > 1900) {
          rtb_MultiportSwitch[i_n] = 1900U;
        } else if (u0_d < 1100) {
          rtb_MultiportSwitch[i_n] = 1100U;
        } else {
          rtb_MultiportSwitch[i_n] = u0_d;
        }

        /* End of Saturate: '<S7>/Saturation' */
      }

      /* End of Product: '<S7>/Multiply' */
      break;

     default:
      for (i_n = 0; i_n < 8; i_n++) {
        rtb_MultiportSwitch[i_n] = 1000U;
      }
      break;
    }

    /* End of MultiPortSwitch: '<S11>/Multiport Switch' */

    /* Reshape: '<S11>/Reshape' */
    for (i_n = 0; i_n < 8; i_n++) {
      rtb_VariantMergeForOutportactua[i_n] = rtb_MultiportSwitch[i_n];
      rtb_VariantMergeForOutportactua[i_n + 8] = 0U;
    }

    /* End of Reshape: '<S11>/Reshape' */
  }

#elif AIRFRAME == 2

  /* Output and update for atomic system: '<S4>/Quadcopter_+' */
  {
    uint16_T rtb_throttle_cmd_o;
    uint16_T rtb_MultiportSwitch_o[4];
    int32_T i_m;
    real32_T tmp_m;
    real32_T tmp_n;
    real32_T tmp_al;
    real32_T u0_m;
    uint16_T u0_n;

    /* MultiPortSwitch: '<S17>/Multiport Switch' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    switch (Controller_U.FMS_Out.status) {
     case 1:
      rtb_MultiportSwitch_o[0] = 1000U;
      rtb_MultiportSwitch_o[1] = 1000U;
      rtb_MultiportSwitch_o[2] = 1000U;
      rtb_MultiportSwitch_o[3] = 1000U;
      break;

     case 2:
      rtb_MultiportSwitch_o[0] = 1150U;
      rtb_MultiportSwitch_o[1] = 1150U;
      rtb_MultiportSwitch_o[2] = 1150U;
      rtb_MultiportSwitch_o[3] = 1150U;
      break;

     case 3:
      /* Switch: '<S16>/Switch' incorporates:
       *  Constant: '<S20>/Constant'
       *  Logic: '<S16>/Logical Operator'
       *  RelationalOperator: '<S19>/Compare'
       *  RelationalOperator: '<S20>/Compare'
       *  Saturate: '<S8>/Saturation2'
       *  Switch: '<S16>/Switch1'
       */
      if ((Controller_U.FMS_Out.ctrl_mode == 1) ||
          (Controller_U.FMS_Out.ctrl_mode == 2) ||
          (Controller_U.FMS_Out.ctrl_mode == 3)) {
        rtb_throttle_cmd_o = Controller_U.FMS_Out.throttle_cmd;
      } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
        /* Switch: '<S21>/Switch' incorporates:
         *  Constant: '<S18>/Constant1'
         *  DataTypeConversion: '<S18>/Data Type Conversion'
         *  Gain: '<S18>/Gain1'
         *  S-Function (sfix_bitop): '<S21>/cmd_throttle valid'
         *  Saturate: '<S8>/Saturation2'
         *  Sum: '<S18>/Sum1'
         *  Switch: '<S16>/Switch1'
         */
        if ((Controller_U.FMS_Out.cmd_mask & 4096) > 0) {
          rtb_throttle_cmd_o = Controller_U.FMS_Out.throttle_cmd;
        } else {
          if (rtb_Saturation_i > 1.0F) {
            /* Saturate: '<S8>/Saturation2' */
            u0_m = 1.0F;
          } else if (rtb_Saturation_i < -1.0F) {
            /* Saturate: '<S8>/Saturation2' */
            u0_m = -1.0F;
          } else {
            /* Saturate: '<S8>/Saturation2' */
            u0_m = rtb_Saturation_i;
          }

          /* Sum: '<S18>/Sum' incorporates:
           *  Constant: '<S18>/hover_throttle'
           *  Saturate: '<S8>/Saturation2'
           */
          u0_m += CONTROL_PARAM.HOVER_THRO;

          /* Saturate: '<S18>/Saturation' */
          if (u0_m > 1.0F) {
            u0_m = 1.0F;
          } else {
            if (u0_m < 0.0F) {
              u0_m = 0.0F;
            }
          }

          rtb_throttle_cmd_o = (uint16_T)((uint32_T)fmodf(floorf(1000.0F * u0_m),
            4.2949673E+9F) + 1000U);
        }

        /* End of Switch: '<S21>/Switch' */
      } else {
        if (rtb_Saturation_i > 1.0F) {
          /* Saturate: '<S8>/Saturation2' */
          u0_m = 1.0F;
        } else if (rtb_Saturation_i < -1.0F) {
          /* Saturate: '<S8>/Saturation2' */
          u0_m = -1.0F;
        } else {
          /* Saturate: '<S8>/Saturation2' */
          u0_m = rtb_Saturation_i;
        }

        /* Sum: '<S18>/Sum' incorporates:
         *  Constant: '<S18>/hover_throttle'
         *  Saturate: '<S8>/Saturation2'
         */
        u0_m += CONTROL_PARAM.HOVER_THRO;

        /* Saturate: '<S18>/Saturation' */
        if (u0_m > 1.0F) {
          u0_m = 1.0F;
        } else {
          if (u0_m < 0.0F) {
            u0_m = 0.0F;
          }
        }

        /* Switch: '<S16>/Switch1' incorporates:
         *  Constant: '<S18>/Constant1'
         *  DataTypeConversion: '<S18>/Data Type Conversion'
         *  Gain: '<S18>/Gain1'
         *  Sum: '<S18>/Sum1'
         */
        rtb_throttle_cmd_o = (uint16_T)((uint32_T)fmodf(floorf(1000.0F * u0_m),
          4.2949673E+9F) + 1000U);
      }

      /* End of Switch: '<S16>/Switch' */

      /* Saturate: '<S8>/Saturation1' */
      if (rtb_Add_g[0] > 1.0F) {
        tmp_m = 1.0F;
      } else if (rtb_Add_g[0] < -1.0F) {
        tmp_m = -1.0F;
      } else {
        tmp_m = rtb_Add_g[0];
      }

      if (rtb_Add_g[1] > 1.0F) {
        tmp_n = 1.0F;
      } else if (rtb_Add_g[1] < -1.0F) {
        tmp_n = -1.0F;
      } else {
        tmp_n = rtb_Add_g[1];
      }

      if (rtb_Add_g[2] > 1.0F) {
        tmp_al = 1.0F;
      } else if (rtb_Add_g[2] < -1.0F) {
        tmp_al = -1.0F;
      } else {
        tmp_al = rtb_Add_g[2];
      }

      /* End of Saturate: '<S8>/Saturation1' */

      /* Product: '<S8>/Multiply' */
      for (i_m = 0; i_m < 4; i_m++) {
        /* Saturate: '<S8>/Saturation' incorporates:
         *  Constant: '<S8>/Effective_Matrix'
         *  Gain: '<S8>/Gain'
         *  Sum: '<S8>/Add'
         */
        u0_m = fmodf(floorf(1000.0F *
                            (Controller_ConstP.Effective_Matrix_Value_f[i_m + 8]
                             * tmp_al +
                             (Controller_ConstP.Effective_Matrix_Value_f[i_m + 4]
                              * tmp_n +
                              Controller_ConstP.Effective_Matrix_Value_f[i_m] *
                              tmp_m))), 65536.0F);
        u0_n = (uint16_T)((uint32_T)(u0_m < 0.0F ? (int32_T)(uint16_T)-(int16_T)
          (uint16_T)-u0_m : (int32_T)(uint16_T)u0_m) + rtb_throttle_cmd_o);
        if (u0_n > 1900) {
          rtb_MultiportSwitch_o[i_m] = 1900U;
        } else if (u0_n < 1100) {
          rtb_MultiportSwitch_o[i_m] = 1100U;
        } else {
          rtb_MultiportSwitch_o[i_m] = u0_n;
        }

        /* End of Saturate: '<S8>/Saturation' */
      }

      /* End of Product: '<S8>/Multiply' */
      break;

     default:
      rtb_MultiportSwitch_o[0] = 1000U;
      rtb_MultiportSwitch_o[1] = 1000U;
      rtb_MultiportSwitch_o[2] = 1000U;
      rtb_MultiportSwitch_o[3] = 1000U;
      break;
    }

    /* End of MultiPortSwitch: '<S17>/Multiport Switch' */

    /* Reshape: '<S17>/Reshape' */
    rtb_VariantMergeForOutportactua[0] = rtb_MultiportSwitch_o[0];
    rtb_VariantMergeForOutportactua[1] = rtb_MultiportSwitch_o[1];
    rtb_VariantMergeForOutportactua[2] = rtb_MultiportSwitch_o[2];
    rtb_VariantMergeForOutportactua[3] = rtb_MultiportSwitch_o[3];
    for (i_m = 0; i_m < 12; i_m++) {
      rtb_VariantMergeForOutportactua[i_m + 4] = 0U;
    }

    /* End of Reshape: '<S17>/Reshape' */
  }

#elif AIRFRAME == 1

  /* Output and update for atomic system: '<S4>/Quadcopter_x' */
  {
    uint16_T rtb_throttle_cmd_c;
    uint16_T rtb_MultiportSwitch_i[4];
    int32_T i_e;
    real32_T tmp_e;
    real32_T tmp_o;
    real32_T tmp_h;
    real32_T u0_e;
    uint16_T u0_o;

    /* MultiPortSwitch: '<S23>/Multiport Switch' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    switch (Controller_U.FMS_Out.status) {
     case 1:
      rtb_MultiportSwitch_i[0] = 1000U;
      rtb_MultiportSwitch_i[1] = 1000U;
      rtb_MultiportSwitch_i[2] = 1000U;
      rtb_MultiportSwitch_i[3] = 1000U;
      break;

     case 2:
      rtb_MultiportSwitch_i[0] = 1150U;
      rtb_MultiportSwitch_i[1] = 1150U;
      rtb_MultiportSwitch_i[2] = 1150U;
      rtb_MultiportSwitch_i[3] = 1150U;
      break;

     case 3:
      /* Switch: '<S22>/Switch' incorporates:
       *  Constant: '<S26>/Constant'
       *  Logic: '<S22>/Logical Operator'
       *  RelationalOperator: '<S25>/Compare'
       *  RelationalOperator: '<S26>/Compare'
       *  Saturate: '<S9>/Saturation2'
       *  Switch: '<S22>/Switch1'
       */
      if ((Controller_U.FMS_Out.ctrl_mode == 1) ||
          (Controller_U.FMS_Out.ctrl_mode == 2) ||
          (Controller_U.FMS_Out.ctrl_mode == 3)) {
        rtb_throttle_cmd_c = Controller_U.FMS_Out.throttle_cmd;
      } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
        /* Switch: '<S27>/Switch' incorporates:
         *  Constant: '<S24>/Constant1'
         *  DataTypeConversion: '<S24>/Data Type Conversion'
         *  Gain: '<S24>/Gain1'
         *  S-Function (sfix_bitop): '<S27>/cmd_throttle valid'
         *  Saturate: '<S9>/Saturation2'
         *  Sum: '<S24>/Sum1'
         *  Switch: '<S22>/Switch1'
         */
        if ((Controller_U.FMS_Out.cmd_mask & 4096) > 0) {
          rtb_throttle_cmd_c = Controller_U.FMS_Out.throttle_cmd;
        } else {
          if (rtb_Saturation_i > 1.0F) {
            /* Saturate: '<S9>/Saturation2' */
            u0_e = 1.0F;
          } else if (rtb_Saturation_i < -1.0F) {
            /* Saturate: '<S9>/Saturation2' */
            u0_e = -1.0F;
          } else {
            /* Saturate: '<S9>/Saturation2' */
            u0_e = rtb_Saturation_i;
          }

          /* Sum: '<S24>/Sum' incorporates:
           *  Constant: '<S24>/hover_throttle'
           *  Saturate: '<S9>/Saturation2'
           */
          u0_e += CONTROL_PARAM.HOVER_THRO;

          /* Saturate: '<S24>/Saturation' */
          if (u0_e > 1.0F) {
            u0_e = 1.0F;
          } else {
            if (u0_e < 0.0F) {
              u0_e = 0.0F;
            }
          }

          rtb_throttle_cmd_c = (uint16_T)((uint32_T)fmodf(floorf(1000.0F * u0_e),
            4.2949673E+9F) + 1000U);
        }

        /* End of Switch: '<S27>/Switch' */
      } else {
        if (rtb_Saturation_i > 1.0F) {
          /* Saturate: '<S9>/Saturation2' */
          u0_e = 1.0F;
        } else if (rtb_Saturation_i < -1.0F) {
          /* Saturate: '<S9>/Saturation2' */
          u0_e = -1.0F;
        } else {
          /* Saturate: '<S9>/Saturation2' */
          u0_e = rtb_Saturation_i;
        }

        /* Sum: '<S24>/Sum' incorporates:
         *  Constant: '<S24>/hover_throttle'
         *  Saturate: '<S9>/Saturation2'
         */
        u0_e += CONTROL_PARAM.HOVER_THRO;

        /* Saturate: '<S24>/Saturation' */
        if (u0_e > 1.0F) {
          u0_e = 1.0F;
        } else {
          if (u0_e < 0.0F) {
            u0_e = 0.0F;
          }
        }

        /* Switch: '<S22>/Switch1' incorporates:
         *  Constant: '<S24>/Constant1'
         *  DataTypeConversion: '<S24>/Data Type Conversion'
         *  Gain: '<S24>/Gain1'
         *  Sum: '<S24>/Sum1'
         */
        rtb_throttle_cmd_c = (uint16_T)((uint32_T)fmodf(floorf(1000.0F * u0_e),
          4.2949673E+9F) + 1000U);
      }

      /* End of Switch: '<S22>/Switch' */

      /* Saturate: '<S9>/Saturation1' */
      if (rtb_Add_g[0] > 1.0F) {
        tmp_e = 1.0F;
      } else if (rtb_Add_g[0] < -1.0F) {
        tmp_e = -1.0F;
      } else {
        tmp_e = rtb_Add_g[0];
      }

      if (rtb_Add_g[1] > 1.0F) {
        tmp_o = 1.0F;
      } else if (rtb_Add_g[1] < -1.0F) {
        tmp_o = -1.0F;
      } else {
        tmp_o = rtb_Add_g[1];
      }

      if (rtb_Add_g[2] > 1.0F) {
        tmp_h = 1.0F;
      } else if (rtb_Add_g[2] < -1.0F) {
        tmp_h = -1.0F;
      } else {
        tmp_h = rtb_Add_g[2];
      }

      /* End of Saturate: '<S9>/Saturation1' */

      /* Product: '<S9>/Multiply' */
      for (i_e = 0; i_e < 4; i_e++) {
        /* Saturate: '<S9>/Saturation' incorporates:
         *  Constant: '<S9>/Effective_Matrix'
         *  Gain: '<S9>/Gain'
         *  Sum: '<S9>/Add'
         */
        u0_e = fmodf(floorf(1000.0F *
                            (Controller_ConstP.Effective_Matrix_Value_h[i_e + 8]
                             * tmp_h +
                             (Controller_ConstP.Effective_Matrix_Value_h[i_e + 4]
                              * tmp_o +
                              Controller_ConstP.Effective_Matrix_Value_h[i_e] *
                              tmp_e))), 65536.0F);
        u0_o = (uint16_T)((uint32_T)(u0_e < 0.0F ? (int32_T)(uint16_T)-(int16_T)
          (uint16_T)-u0_e : (int32_T)(uint16_T)u0_e) + rtb_throttle_cmd_c);
        if (u0_o > 1900) {
          rtb_MultiportSwitch_i[i_e] = 1900U;
        } else if (u0_o < 1100) {
          rtb_MultiportSwitch_i[i_e] = 1100U;
        } else {
          rtb_MultiportSwitch_i[i_e] = u0_o;
        }

        /* End of Saturate: '<S9>/Saturation' */
      }

      /* End of Product: '<S9>/Multiply' */
      break;

     default:
      rtb_MultiportSwitch_i[0] = 1000U;
      rtb_MultiportSwitch_i[1] = 1000U;
      rtb_MultiportSwitch_i[2] = 1000U;
      rtb_MultiportSwitch_i[3] = 1000U;
      break;
    }

    /* End of MultiPortSwitch: '<S23>/Multiport Switch' */

    /* Reshape: '<S23>/Reshape' */
    rtb_VariantMergeForOutportactua[0] = rtb_MultiportSwitch_i[0];
    rtb_VariantMergeForOutportactua[1] = rtb_MultiportSwitch_i[1];
    rtb_VariantMergeForOutportactua[2] = rtb_MultiportSwitch_i[2];
    rtb_VariantMergeForOutportactua[3] = rtb_MultiportSwitch_i[3];
    for (i_e = 0; i_e < 12; i_e++) {
      rtb_VariantMergeForOutportactua[i_e + 4] = 0U;
    }

    /* End of Reshape: '<S23>/Reshape' */
  }

#endif

  /* End of Outputs for SubSystem: '<S2>/Control_Allocation' */

  /* Product: '<S40>/Multiply' incorporates:
   *  Constant: '<S40>/gain1'
   *  Constant: '<S40>/gain2'
   *  Constant: '<S40>/gain3'
   *  DiscreteIntegrator: '<S38>/Discrete-Time Integrator5'
   */
  rtb_Saturation_d_idx_0 = CONTROL_PARAM.ROLL_RATE_I *
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[0];
  rtb_Saturation_d_idx_1 = CONTROL_PARAM.PITCH_RATE_I *
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1];
  rtb_Saturation_d_idx_2 = CONTROL_PARAM.YAW_RATE_I *
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[2];

  /* Product: '<S67>/Multiply' incorporates:
   *  Constant: '<S67>/ki'
   */
  rtb_att_error_B_rad_idx_0 = CONTROL_PARAM.VEL_XY_I * rtb_a_idx_0;

  /* Product: '<S65>/Multiply1' incorporates:
   *  Constant: '<S65>/const1'
   *  DiscreteIntegrator: '<S62>/Integrator'
   */
  rtb_a_idx_0 = Controller_DW.Integrator_DSTATE[0] * 0.05F;
  rtb_a_n = Controller_DW.Integrator_DSTATE[1] * 0.05F;

  /* Sum: '<S65>/Add' incorporates:
   *  DiscreteIntegrator: '<S62>/Integrator1'
   *  Inport: '<Root>/FMS_Out'
   *  Sum: '<S62>/Subtract'
   */
  rtb_Saturation1_idx_0 = (Controller_DW.Integrator1_DSTATE[0] -
    Controller_U.FMS_Out.u_cmd) + rtb_a_idx_0;
  rtb_Saturation1_idx_1 = (Controller_DW.Integrator1_DSTATE[1] -
    Controller_U.FMS_Out.v_cmd) + rtb_a_n;

  /* Signum: '<S65>/Sign' */
  if (rtb_Saturation1_idx_0 < 0.0F) {
    rtb_DiscreteTimeIntegrator1_j = -1.0F;
  } else if (rtb_Saturation1_idx_0 > 0.0F) {
    rtb_DiscreteTimeIntegrator1_j = 1.0F;
  } else {
    rtb_DiscreteTimeIntegrator1_j = rtb_Saturation1_idx_0;
  }

  /* Sum: '<S65>/Add2' incorporates:
   *  Abs: '<S65>/Abs'
   *  Gain: '<S65>/Gain'
   *  Gain: '<S65>/Gain1'
   *  Product: '<S65>/Multiply2'
   *  Product: '<S65>/Multiply3'
   *  Signum: '<S65>/Sign'
   *  Sqrt: '<S65>/Sqrt'
   *  Sum: '<S65>/Add1'
   *  Sum: '<S65>/Subtract'
   */
  rtb_a = (sqrtf((8.0F * fabsf(rtb_Saturation1_idx_0) + Controller_ConstB.d) *
                 Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
    rtb_DiscreteTimeIntegrator1_j + rtb_a_idx_0;

  /* Sum: '<S65>/Add3' incorporates:
   *  Signum: '<S65>/Sign'
   */
  rtb_DiscreteTimeIntegrator1_j = rtb_Saturation1_idx_0 + Controller_ConstB.d;

  /* Sum: '<S65>/Subtract1' incorporates:
   *  Signum: '<S65>/Sign'
   */
  rtb_Multiply_ha = rtb_Saturation1_idx_0 - Controller_ConstB.d;

  /* Signum: '<S65>/Sign1' */
  if (rtb_DiscreteTimeIntegrator1_j < 0.0F) {
    rtb_DiscreteTimeIntegrator1_j = -1.0F;
  } else {
    if (rtb_DiscreteTimeIntegrator1_j > 0.0F) {
      rtb_DiscreteTimeIntegrator1_j = 1.0F;
    }
  }

  /* Signum: '<S65>/Sign2' */
  if (rtb_Multiply_ha < 0.0F) {
    rtb_Multiply_ha = -1.0F;
  } else {
    if (rtb_Multiply_ha > 0.0F) {
      rtb_Multiply_ha = 1.0F;
    }
  }

  /* Sum: '<S65>/Add2' incorporates:
   *  Gain: '<S65>/Gain2'
   *  Product: '<S65>/Multiply4'
   *  Signum: '<S65>/Sign'
   *  Sum: '<S65>/Add4'
   *  Sum: '<S65>/Add5'
   *  Sum: '<S65>/Subtract2'
   */
  rtb_a_idx_0 = ((rtb_Saturation1_idx_0 - rtb_a) + rtb_a_idx_0) *
    ((rtb_DiscreteTimeIntegrator1_j - rtb_Multiply_ha) * 0.5F) + rtb_a;

  /* Signum: '<S65>/Sign' */
  if (rtb_Saturation1_idx_1 < 0.0F) {
    rtb_DiscreteTimeIntegrator1_j = -1.0F;
  } else if (rtb_Saturation1_idx_1 > 0.0F) {
    rtb_DiscreteTimeIntegrator1_j = 1.0F;
  } else {
    rtb_DiscreteTimeIntegrator1_j = rtb_Saturation1_idx_1;
  }

  /* Sum: '<S65>/Add2' incorporates:
   *  Abs: '<S65>/Abs'
   *  Gain: '<S65>/Gain'
   *  Gain: '<S65>/Gain1'
   *  Product: '<S65>/Multiply2'
   *  Product: '<S65>/Multiply3'
   *  Signum: '<S65>/Sign'
   *  Sqrt: '<S65>/Sqrt'
   *  Sum: '<S65>/Add1'
   *  Sum: '<S65>/Subtract'
   */
  rtb_a = (sqrtf((8.0F * fabsf(rtb_Saturation1_idx_1) + Controller_ConstB.d) *
                 Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
    rtb_DiscreteTimeIntegrator1_j + rtb_a_n;

  /* Sum: '<S65>/Add3' incorporates:
   *  Signum: '<S65>/Sign'
   */
  rtb_DiscreteTimeIntegrator1_j = rtb_Saturation1_idx_1 + Controller_ConstB.d;

  /* Sum: '<S65>/Subtract1' incorporates:
   *  Signum: '<S65>/Sign'
   */
  rtb_Multiply_ha = rtb_Saturation1_idx_1 - Controller_ConstB.d;

  /* Signum: '<S65>/Sign1' */
  if (rtb_DiscreteTimeIntegrator1_j < 0.0F) {
    rtb_DiscreteTimeIntegrator1_j = -1.0F;
  } else {
    if (rtb_DiscreteTimeIntegrator1_j > 0.0F) {
      rtb_DiscreteTimeIntegrator1_j = 1.0F;
    }
  }

  /* Signum: '<S65>/Sign2' */
  if (rtb_Multiply_ha < 0.0F) {
    rtb_Multiply_ha = -1.0F;
  } else {
    if (rtb_Multiply_ha > 0.0F) {
      rtb_Multiply_ha = 1.0F;
    }
  }

  /* Sum: '<S65>/Add5' incorporates:
   *  Gain: '<S65>/Gain2'
   *  Product: '<S65>/Multiply4'
   *  Signum: '<S65>/Sign'
   *  Sum: '<S65>/Add2'
   *  Sum: '<S65>/Add4'
   *  Sum: '<S65>/Subtract2'
   */
  rtb_a += ((rtb_Saturation1_idx_1 - rtb_a) + rtb_a_n) *
    ((rtb_DiscreteTimeIntegrator1_j - rtb_Multiply_ha) * 0.5F);

  /* Outport: '<Root>/Control_Out' incorporates:
   *  BusAssignment: '<S1>/Bus Assignment'
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   */
  Controller_Y.Control_Out.timestamp =
    Controller_DW.DiscreteTimeIntegrator_DSTATE_n;
  for (i = 0; i < 16; i++) {
    Controller_Y.Control_Out.actuator_cmd[i] = rtb_VariantMergeForOutportactua[i];
  }

  /* End of Outport: '<Root>/Control_Out' */

  /* Product: '<S81>/Multiply' incorporates:
   *  Constant: '<S81>/ki'
   */
  rtb_Multiply_ha = CONTROL_PARAM.VEL_Z_I * rtb_Add3;

  /* Product: '<S79>/Multiply1' incorporates:
   *  Constant: '<S79>/const1'
   *  DiscreteIntegrator: '<S78>/Integrator'
   */
  rtb_Add3 = Controller_DW.Integrator_DSTATE_p * 0.05F;

  /* Sum: '<S79>/Add' incorporates:
   *  DiscreteIntegrator: '<S78>/Integrator1'
   *  Inport: '<Root>/FMS_Out'
   *  Sum: '<S78>/Subtract'
   */
  rtb_Saturation1_idx_0 = (Controller_DW.Integrator1_DSTATE_p -
    Controller_U.FMS_Out.w_cmd) + rtb_Add3;

  /* Signum: '<S79>/Sign' */
  if (rtb_Saturation1_idx_0 < 0.0F) {
    rtb_a_n = -1.0F;
  } else if (rtb_Saturation1_idx_0 > 0.0F) {
    rtb_a_n = 1.0F;
  } else {
    rtb_a_n = rtb_Saturation1_idx_0;
  }

  /* End of Signum: '<S79>/Sign' */

  /* Sum: '<S79>/Add2' incorporates:
   *  Abs: '<S79>/Abs'
   *  Gain: '<S79>/Gain'
   *  Gain: '<S79>/Gain1'
   *  Product: '<S79>/Multiply2'
   *  Product: '<S79>/Multiply3'
   *  Sqrt: '<S79>/Sqrt'
   *  Sum: '<S79>/Add1'
   *  Sum: '<S79>/Subtract'
   */
  rtb_a_n = (sqrtf((8.0F * fabsf(rtb_Saturation1_idx_0) + Controller_ConstB.d_n)
                   * Controller_ConstB.d_n) - Controller_ConstB.d_n) * 0.5F *
    rtb_a_n + rtb_Add3;

  /* Sum: '<S79>/Add4' */
  rtb_Add3 += rtb_Saturation1_idx_0 - rtb_a_n;

  /* Sum: '<S79>/Add3' */
  rtb_DiscreteTimeIntegrator1_j = rtb_Saturation1_idx_0 + Controller_ConstB.d_n;

  /* Sum: '<S79>/Subtract1' */
  rtb_Saturation1_idx_0 -= Controller_ConstB.d_n;

  /* Signum: '<S79>/Sign1' */
  if (rtb_DiscreteTimeIntegrator1_j < 0.0F) {
    rtb_DiscreteTimeIntegrator1_j = -1.0F;
  } else {
    if (rtb_DiscreteTimeIntegrator1_j > 0.0F) {
      rtb_DiscreteTimeIntegrator1_j = 1.0F;
    }
  }

  /* End of Signum: '<S79>/Sign1' */

  /* Signum: '<S79>/Sign2' */
  if (rtb_Saturation1_idx_0 < 0.0F) {
    rtb_Saturation1_idx_0 = -1.0F;
  } else {
    if (rtb_Saturation1_idx_0 > 0.0F) {
      rtb_Saturation1_idx_0 = 1.0F;
    }
  }

  /* End of Signum: '<S79>/Sign2' */

  /* Sum: '<S79>/Add5' incorporates:
   *  Gain: '<S79>/Gain2'
   *  Product: '<S79>/Multiply4'
   *  Sum: '<S79>/Subtract2'
   */
  rtb_a_n += (rtb_DiscreteTimeIntegrator1_j - rtb_Saturation1_idx_0) * 0.5F *
    rtb_Add3;

  /* Update for DiscreteIntegrator: '<S67>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S62>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S62>/Integrator'
   */
  Controller_DW.Integrator1_DSTATE[0] += 0.002F *
    Controller_DW.Integrator_DSTATE[0];

  /* Update for DiscreteIntegrator: '<S67>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE[0] += 0.002F *
    rtb_att_error_B_rad_idx_0;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] >=
      CONTROL_PARAM.VEL_XY_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = CONTROL_PARAM.VEL_XY_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] <=
        CONTROL_PARAM.VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
        CONTROL_PARAM.VEL_XY_I_MIN;
    }
  }

  /* Update for DiscreteIntegrator: '<S69>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] += 0.002F * rtb_Gain_idx_0;

  /* Update for DiscreteIntegrator: '<S62>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S62>/Integrator'
   */
  Controller_DW.Integrator1_DSTATE[1] += 0.002F *
    Controller_DW.Integrator_DSTATE[1];

  /* Update for DiscreteIntegrator: '<S67>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S67>/ki'
   *  Product: '<S67>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE[1] += CONTROL_PARAM.VEL_XY_I *
    rtb_a_idx_1 * 0.002F;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] >=
      CONTROL_PARAM.VEL_XY_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = CONTROL_PARAM.VEL_XY_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] <=
        CONTROL_PARAM.VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
        CONTROL_PARAM.VEL_XY_I_MIN;
    }
  }

  /* Update for DiscreteIntegrator: '<S69>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] += 0.002F * rtb_Gain_idx_1;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S38>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;

  /* Update for DiscreteIntegrator: '<S40>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator_PrevRe_g = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S38>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S38>/Gain'
   *  Sum: '<S38>/Sum5'
   */
  Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] +=
    (rtb_rate_error_B_radPs_idx_0 -
     Controller_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 188.49556F * 0.002F;

  /* Update for DiscreteIntegrator: '<S40>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] += 0.002F *
    rtb_Saturation_d_idx_0;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] >=
      CONTROL_PARAM.RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] =
        CONTROL_PARAM.RATE_I_MIN;
    }
  }

  /* Update for DiscreteIntegrator: '<S42>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[0] += 0.002F *
    rtb_att_error_B_rad_idx_1;

  /* Update for DiscreteIntegrator: '<S38>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S38>/Gain'
   *  Sum: '<S38>/Sum5'
   */
  Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] +=
    (rtb_rate_error_B_radPs_idx_1 -
     Controller_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 188.49556F * 0.002F;

  /* Update for DiscreteIntegrator: '<S40>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] += 0.002F *
    rtb_Saturation_d_idx_1;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] >=
      CONTROL_PARAM.RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] =
        CONTROL_PARAM.RATE_I_MIN;
    }
  }

  /* Update for DiscreteIntegrator: '<S42>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[1] += 0.002F *
    rtb_DiscreteTimeIntegrator5_idx;

  /* Update for DiscreteIntegrator: '<S38>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S38>/Gain'
   *  Sum: '<S38>/Sum5'
   */
  Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] +=
    (rtb_rate_error_B_radPs_idx_2 -
     Controller_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 188.49556F * 0.002F;

  /* Update for DiscreteIntegrator: '<S40>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] += 0.002F *
    rtb_Saturation_d_idx_2;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] >=
      CONTROL_PARAM.RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] =
        CONTROL_PARAM.RATE_I_MIN;
    }
  }

  /* Update for DiscreteIntegrator: '<S42>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[2] += 0.002F *
    rtb_DiscreteTimeIntegrator5_i_0;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_i = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S78>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S78>/Integrator'
   */
  Controller_DW.Integrator1_DSTATE_p += 0.002F *
    Controller_DW.Integrator_DSTATE_p;

  /* Update for DiscreteIntegrator: '<S81>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_m += 0.002F * rtb_Multiply_ha;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m >= CONTROL_PARAM.VEL_Z_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m = CONTROL_PARAM.VEL_Z_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m <=
        CONTROL_PARAM.VEL_Z_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m = CONTROL_PARAM.VEL_Z_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRe_m = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* End of Update for DiscreteIntegrator: '<S81>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S83>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_h += 0.002F * rtb_Gain_am;
  Controller_DW.DiscreteTimeIntegrator1_Prev_iy = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Signum: '<S65>/Sign3' incorporates:
   *  Product: '<S65>/Divide'
   *  Sum: '<S65>/Add6'
   */
  rtb_DiscreteTimeIntegrator1_j = rtb_a_idx_0 + Controller_ConstB.d;

  /* Signum: '<S65>/Sign4' incorporates:
   *  Product: '<S65>/Divide'
   *  Sum: '<S65>/Subtract3'
   */
  rtb_a_idx_1 = rtb_a_idx_0 - Controller_ConstB.d;

  /* Signum: '<S65>/Sign5' incorporates:
   *  Product: '<S65>/Divide'
   */
  if (rtb_a_idx_0 < 0.0F) {
    rtb_Gain_idx_0 = -1.0F;
  } else if (rtb_a_idx_0 > 0.0F) {
    rtb_Gain_idx_0 = 1.0F;
  } else {
    rtb_Gain_idx_0 = rtb_a_idx_0;
  }

  /* Signum: '<S65>/Sign3' */
  if (rtb_DiscreteTimeIntegrator1_j < 0.0F) {
    rtb_DiscreteTimeIntegrator1_j = -1.0F;
  } else {
    if (rtb_DiscreteTimeIntegrator1_j > 0.0F) {
      rtb_DiscreteTimeIntegrator1_j = 1.0F;
    }
  }

  /* Signum: '<S65>/Sign4' */
  if (rtb_a_idx_1 < 0.0F) {
    rtb_a_idx_1 = -1.0F;
  } else {
    if (rtb_a_idx_1 > 0.0F) {
      rtb_a_idx_1 = 1.0F;
    }
  }

  /* Signum: '<S65>/Sign6' incorporates:
   *  Product: '<S65>/Divide'
   */
  if (rtb_a_idx_0 < 0.0F) {
    rtb_Gain_idx_1 = -1.0F;
  } else if (rtb_a_idx_0 > 0.0F) {
    rtb_Gain_idx_1 = 1.0F;
  } else {
    rtb_Gain_idx_1 = rtb_a_idx_0;
  }

  /* Update for DiscreteIntegrator: '<S62>/Integrator' incorporates:
   *  Constant: '<S65>/const'
   *  Gain: '<S65>/Gain3'
   *  Product: '<S65>/Divide'
   *  Product: '<S65>/Multiply5'
   *  Product: '<S65>/Multiply6'
   *  Sum: '<S65>/Subtract4'
   *  Sum: '<S65>/Subtract5'
   *  Sum: '<S65>/Subtract6'
   */
  Controller_DW.Integrator_DSTATE[0] += ((rtb_a_idx_0 / Controller_ConstB.d -
    rtb_Gain_idx_0) * Controller_ConstB.Gain4 * ((rtb_DiscreteTimeIntegrator1_j
    - rtb_a_idx_1) * 0.5F) - rtb_Gain_idx_1 * 58.836F) * 0.002F;

  /* Signum: '<S65>/Sign3' incorporates:
   *  Sum: '<S65>/Add6'
   */
  rtb_DiscreteTimeIntegrator1_j = rtb_a + Controller_ConstB.d;

  /* Signum: '<S65>/Sign4' incorporates:
   *  Sum: '<S65>/Subtract3'
   */
  rtb_a_idx_1 = rtb_a - Controller_ConstB.d;

  /* Signum: '<S65>/Sign5' */
  if (rtb_a < 0.0F) {
    rtb_a_idx_0 = -1.0F;
  } else if (rtb_a > 0.0F) {
    rtb_a_idx_0 = 1.0F;
  } else {
    rtb_a_idx_0 = rtb_a;
  }

  /* Signum: '<S65>/Sign3' */
  if (rtb_DiscreteTimeIntegrator1_j < 0.0F) {
    rtb_DiscreteTimeIntegrator1_j = -1.0F;
  } else {
    if (rtb_DiscreteTimeIntegrator1_j > 0.0F) {
      rtb_DiscreteTimeIntegrator1_j = 1.0F;
    }
  }

  /* Signum: '<S65>/Sign4' */
  if (rtb_a_idx_1 < 0.0F) {
    rtb_a_idx_1 = -1.0F;
  } else {
    if (rtb_a_idx_1 > 0.0F) {
      rtb_a_idx_1 = 1.0F;
    }
  }

  /* Signum: '<S65>/Sign6' */
  if (rtb_a < 0.0F) {
    rtb_Gain_idx_0 = -1.0F;
  } else if (rtb_a > 0.0F) {
    rtb_Gain_idx_0 = 1.0F;
  } else {
    rtb_Gain_idx_0 = rtb_a;
  }

  /* Update for DiscreteIntegrator: '<S62>/Integrator' incorporates:
   *  Constant: '<S65>/const'
   *  Gain: '<S65>/Gain3'
   *  Product: '<S65>/Divide'
   *  Product: '<S65>/Multiply5'
   *  Product: '<S65>/Multiply6'
   *  Sum: '<S65>/Subtract4'
   *  Sum: '<S65>/Subtract5'
   *  Sum: '<S65>/Subtract6'
   */
  Controller_DW.Integrator_DSTATE[1] += ((rtb_a / Controller_ConstB.d -
    rtb_a_idx_0) * Controller_ConstB.Gain4 * ((rtb_DiscreteTimeIntegrator1_j -
    rtb_a_idx_1) * 0.5F) - rtb_Gain_idx_0 * 58.836F) * 0.002F;

  /* Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S3>/Constant'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_n += CONTROL_EXPORT.period;

  /* Signum: '<S79>/Sign6' incorporates:
   *  Signum: '<S79>/Sign5'
   */
  if (rtb_a_n < 0.0F) {
    rtb_a_idx_0 = -1.0F;

    /* Signum: '<S79>/Sign5' */
    rtb_Gain_idx_0 = -1.0F;
  } else if (rtb_a_n > 0.0F) {
    rtb_a_idx_0 = 1.0F;

    /* Signum: '<S79>/Sign5' */
    rtb_Gain_idx_0 = 1.0F;
  } else {
    rtb_a_idx_0 = rtb_a_n;

    /* Signum: '<S79>/Sign5' */
    rtb_Gain_idx_0 = rtb_a_n;
  }

  /* End of Signum: '<S79>/Sign6' */

  /* Sum: '<S79>/Add6' */
  rtb_DiscreteTimeIntegrator1_j = rtb_a_n + Controller_ConstB.d_n;

  /* Sum: '<S79>/Subtract3' */
  rtb_a_idx_1 = rtb_a_n - Controller_ConstB.d_n;

  /* Signum: '<S79>/Sign3' */
  if (rtb_DiscreteTimeIntegrator1_j < 0.0F) {
    rtb_DiscreteTimeIntegrator1_j = -1.0F;
  } else {
    if (rtb_DiscreteTimeIntegrator1_j > 0.0F) {
      rtb_DiscreteTimeIntegrator1_j = 1.0F;
    }
  }

  /* End of Signum: '<S79>/Sign3' */

  /* Signum: '<S79>/Sign4' */
  if (rtb_a_idx_1 < 0.0F) {
    rtb_a_idx_1 = -1.0F;
  } else {
    if (rtb_a_idx_1 > 0.0F) {
      rtb_a_idx_1 = 1.0F;
    }
  }

  /* End of Signum: '<S79>/Sign4' */

  /* Update for DiscreteIntegrator: '<S78>/Integrator' incorporates:
   *  Constant: '<S79>/const'
   *  Gain: '<S79>/Gain3'
   *  Product: '<S79>/Divide'
   *  Product: '<S79>/Multiply5'
   *  Product: '<S79>/Multiply6'
   *  Sum: '<S79>/Subtract4'
   *  Sum: '<S79>/Subtract5'
   *  Sum: '<S79>/Subtract6'
   */
  Controller_DW.Integrator_DSTATE_p += ((rtb_a_n / Controller_ConstB.d_n -
    rtb_Gain_idx_0) * Controller_ConstB.Gain4_k *
    ((rtb_DiscreteTimeIntegrator1_j - rtb_a_idx_1) * 0.5F) - rtb_a_idx_0 *
    78.448F) * 0.002F;
}

/* Model initialize function */
void Controller_init(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Controller_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&Controller_DW, 0,
                sizeof(DW_Controller_T));

  /* external inputs */
  (void)memset(&Controller_U, 0, sizeof(ExtU_Controller_T));

  /* external outputs */
  Controller_Y.Control_Out = Controller_rtZControl_Out_Bus;

  /* InitializeConditions for DiscreteIntegrator: '<S67>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = Controller_ConstB.Constant;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] >=
      CONTROL_PARAM.VEL_XY_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = CONTROL_PARAM.VEL_XY_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] <=
        CONTROL_PARAM.VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
        CONTROL_PARAM.VEL_XY_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = Controller_ConstB.Constant;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] >=
      CONTROL_PARAM.VEL_XY_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = CONTROL_PARAM.VEL_XY_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] <=
        CONTROL_PARAM.VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
        CONTROL_PARAM.VEL_XY_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRese = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S67>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S69>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S38>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S40>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] =
    Controller_ConstB.Constant_n[0];
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] >=
      CONTROL_PARAM.RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] =
        CONTROL_PARAM.RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] =
    Controller_ConstB.Constant_n[1];
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] >=
      CONTROL_PARAM.RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] =
        CONTROL_PARAM.RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] =
    Controller_ConstB.Constant_n[2];
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] >=
      CONTROL_PARAM.RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] =
        CONTROL_PARAM.RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRe_g = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S40>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S42>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_PrevR_i = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S81>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_m = Controller_ConstB.Constant_b;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m >= CONTROL_PARAM.VEL_Z_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m = CONTROL_PARAM.VEL_Z_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m <=
        CONTROL_PARAM.VEL_Z_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m = CONTROL_PARAM.VEL_Z_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRe_m = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S81>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S83>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_Prev_iy = 0;
}

/* Model terminate function */
void Controller_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
