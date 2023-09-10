/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.968
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sun Sep 10 08:50:03 2023
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
  0.05F,
  0.5F,
  0.12F,
  0.0F,
  -1.0F,
  1.0F,
  -1.0F,
  1.0F,
  -0.2F,
  0.2F,
  -0.1F,
  0.1F,
  7.0F,
  7.0F,
  0.523599F,
  0.03F,
  0.03F,
  0.12F,
  0.05F,
  0.05F,
  0.1F,
  0.0008F,
  0.0008F,
  0.0005F,
  -0.1F,
  0.1F,
  -0.1F,
  0.1F,
  1.57079601F,
  3.14159298F,
  0.5F
} ;                                    /* Variable: CONTROL_PARAM
                                        * Referenced by:
                                        *   '<S17>/hover_throttle'
                                        *   '<S23>/hover_throttle'
                                        *   '<S29>/hover_throttle'
                                        *   '<S35>/hover_throttle'
                                        *   '<S41>/hover_throttle'
                                        *   '<S47>/hover_throttle'
                                        *   '<S53>/hover_throttle'
                                        *   '<S59>/hover_throttle'
                                        *   '<S92>/Saturation'
                                        *   '<S68>/Saturation'
                                        *   '<S68>/Saturation1'
                                        *   '<S101>/kd'
                                        *   '<S101>/Saturation'
                                        *   '<S102>/ki'
                                        *   '<S102>/Discrete-Time Integrator'
                                        *   '<S103>/kp'
                                        *   '<S115>/kd'
                                        *   '<S115>/Saturation'
                                        *   '<S116>/Constant'
                                        *   '<S116>/ki'
                                        *   '<S116>/Discrete-Time Integrator'
                                        *   '<S117>/kp'
                                        *   '<S85>/Constant1'
                                        *   '<S85>/Constant2'
                                        *   '<S74>/gain1'
                                        *   '<S74>/gain2'
                                        *   '<S74>/gain3'
                                        *   '<S74>/Saturation'
                                        *   '<S75>/gain1'
                                        *   '<S75>/gain2'
                                        *   '<S75>/gain3'
                                        *   '<S75>/Discrete-Time Integrator'
                                        *   '<S76>/gain1'
                                        *   '<S76>/gain2'
                                        *   '<S76>/gain3'
                                        */

struct_biZzOMrg0u3lxrb7POOubF CONTROL_EXPORT = {
  2U,

  { 66, 97, 115, 101, 32, 67, 111, 110, 116, 114, 111, 108, 108, 101, 114, 32,
    118, 49, 46, 48, 46, 48, 0 }
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
  real32_T rtb_Add3;
  real32_T rtb_VectorConcatenate[9];
  real32_T rtb_Subtract3_i;
  real32_T rtb_DiscreteTimeIntegrator1_j;
  real32_T rtb_DiscreteTimeIntegrator_h;
  real32_T rtb_Gain_fl;
  real32_T rtb_Gain_g2;
  real32_T rtb_Add_i;
  int32_T i;
  real32_T rtb_VectorConcatenate_0[3];
  real32_T rtb_Add3_j_idx_0;
  real32_T rtb_Add3_j_idx_1;
  real32_T rtb_Multiply_l_idx_0;
  real32_T rtb_Multiply_l_idx_1;
  real32_T rtb_Saturation_idx_0;
  real32_T rtb_Saturation_idx_1;
  real32_T rtb_rate_error_B_radPs_idx_1;
  real32_T rtb_rate_error_B_radPs_idx_2;
  real32_T rtb_Saturation_d_idx_0;
  real32_T rtb_Saturation_d_idx_1;
  real32_T rtb_Saturation_d_idx_2;
  real32_T rtb_uv_error_C_mPs_idx_0;
  real32_T rtb_uv_error_C_mPs_idx_1;
  real32_T rtb_Gain_idx_0;
  real32_T rtb_Gain_idx_1;

  /* Trigonometry: '<S99>/Trigonometric Function1' incorporates:
   *  Gain: '<S98>/Gain'
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S99>/Trigonometric Function3'
   */
  rtb_uv_error_C_mPs_idx_0 = arm_cos_f32(-Controller_U.INS_Out.psi);
  rtb_VectorConcatenate[0] = rtb_uv_error_C_mPs_idx_0;

  /* Trigonometry: '<S99>/Trigonometric Function' incorporates:
   *  Gain: '<S98>/Gain'
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S99>/Trigonometric Function2'
   */
  rtb_uv_error_C_mPs_idx_1 = arm_sin_f32(-Controller_U.INS_Out.psi);
  rtb_VectorConcatenate[1] = rtb_uv_error_C_mPs_idx_1;

  /* SignalConversion: '<S99>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S99>/Constant3'
   */
  rtb_VectorConcatenate[2] = 0.0F;

  /* Gain: '<S99>/Gain' */
  rtb_VectorConcatenate[3] = -rtb_uv_error_C_mPs_idx_1;

  /* Trigonometry: '<S99>/Trigonometric Function3' */
  rtb_VectorConcatenate[4] = rtb_uv_error_C_mPs_idx_0;

  /* SignalConversion: '<S99>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S99>/Constant4'
   */
  rtb_VectorConcatenate[5] = 0.0F;

  /* SignalConversion: '<S99>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate[6] = Controller_ConstB.VectorConcatenate3[0];
  rtb_VectorConcatenate[7] = Controller_ConstB.VectorConcatenate3[1];
  rtb_VectorConcatenate[8] = Controller_ConstB.VectorConcatenate3[2];

  /* Product: '<S96>/Multiply' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  SignalConversion: '<S96>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_0[i] = rtb_VectorConcatenate[i + 3] *
      Controller_U.INS_Out.ve + rtb_VectorConcatenate[i] *
      Controller_U.INS_Out.vn;
  }

  /* End of Product: '<S96>/Multiply' */

  /* Sum: '<S93>/Sum' incorporates:
   *  DiscreteIntegrator: '<S97>/Integrator1'
   */
  rtb_uv_error_C_mPs_idx_0 = Controller_DW.Integrator1_DSTATE[0] -
    rtb_VectorConcatenate_0[0];
  rtb_uv_error_C_mPs_idx_1 = Controller_DW.Integrator1_DSTATE[1] -
    rtb_VectorConcatenate_0[1];

  /* DiscreteIntegrator: '<S102>/Discrete-Time Integrator' incorporates:
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

  /* DiscreteIntegrator: '<S104>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] = rtb_uv_error_C_mPs_idx_0;
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] = rtb_uv_error_C_mPs_idx_1;
  }

  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevRes != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] = rtb_uv_error_C_mPs_idx_0;
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] = rtb_uv_error_C_mPs_idx_1;
  }

  /* Gain: '<S104>/Gain' incorporates:
   *  DiscreteIntegrator: '<S104>/Discrete-Time Integrator1'
   *  Sum: '<S104>/Sum5'
   */
  rtb_Gain_idx_0 = (rtb_uv_error_C_mPs_idx_0 -
                    Controller_DW.DiscreteTimeIntegrator1_DSTATE[0]) *
    62.831852F;
  rtb_Gain_idx_1 = (rtb_uv_error_C_mPs_idx_1 -
                    Controller_DW.DiscreteTimeIntegrator1_DSTATE[1]) *
    62.831852F;

  /* Switch: '<S104>/Switch' incorporates:
   *  Gain: '<S104>/Gain1'
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_U.FMS_Out.reset > 0) {
    rtb_Add3_j_idx_0 = 0.0F;
    rtb_Add3_j_idx_1 = 0.0F;
  } else {
    rtb_Add3_j_idx_0 = rtb_Gain_idx_0;
    rtb_Add3_j_idx_1 = rtb_Gain_idx_1;
  }

  /* End of Switch: '<S104>/Switch' */

  /* Product: '<S101>/Multiply' incorporates:
   *  Constant: '<S101>/kd'
   */
  rtb_Multiply_l_idx_0 = CONTROL_PARAM.VEL_XY_D * rtb_Add3_j_idx_0;

  /* Saturate: '<S101>/Saturation' */
  if (rtb_Multiply_l_idx_0 > CONTROL_PARAM.VEL_XY_D_MAX) {
    rtb_Multiply_l_idx_0 = CONTROL_PARAM.VEL_XY_D_MAX;
  } else {
    if (rtb_Multiply_l_idx_0 < CONTROL_PARAM.VEL_XY_D_MIN) {
      rtb_Multiply_l_idx_0 = CONTROL_PARAM.VEL_XY_D_MIN;
    }
  }

  /* Product: '<S101>/Multiply' incorporates:
   *  Constant: '<S101>/kd'
   */
  rtb_Add3_j_idx_0 = rtb_Multiply_l_idx_0;
  rtb_Multiply_l_idx_0 = CONTROL_PARAM.VEL_XY_D * rtb_Add3_j_idx_1;

  /* Saturate: '<S101>/Saturation' */
  if (rtb_Multiply_l_idx_0 > CONTROL_PARAM.VEL_XY_D_MAX) {
    rtb_Multiply_l_idx_0 = CONTROL_PARAM.VEL_XY_D_MAX;
  } else {
    if (rtb_Multiply_l_idx_0 < CONTROL_PARAM.VEL_XY_D_MIN) {
      rtb_Multiply_l_idx_0 = CONTROL_PARAM.VEL_XY_D_MIN;
    }
  }

  /* Switch: '<S95>/Switch' incorporates:
   *  Constant: '<S103>/kp'
   *  Constant: '<S105>/Constant'
   *  Constant: '<S107>/Constant'
   *  Constant: '<S108>/Constant'
   *  DiscreteIntegrator: '<S102>/Discrete-Time Integrator'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S103>/Multiply'
   *  Product: '<S106>/Multiply2'
   *  Product: '<S106>/Multiply3'
   *  RelationalOperator: '<S105>/Compare'
   *  RelationalOperator: '<S107>/Compare'
   *  RelationalOperator: '<S108>/Compare'
   *  S-Function (sfix_bitop): '<S106>/cmd_ax valid'
   *  S-Function (sfix_bitop): '<S106>/cmd_ay valid'
   *  S-Function (sfix_bitop): '<S106>/cmd_u valid'
   *  S-Function (sfix_bitop): '<S106>/cmd_v valid'
   *  Sum: '<S106>/Sum1'
   *  Sum: '<S94>/Add'
   */
  if (Controller_U.FMS_Out.ctrl_mode == 6) {
    rtb_Add3_j_idx_0 = ((Controller_U.FMS_Out.cmd_mask & 64) > 0 ?
                        (CONTROL_PARAM.VEL_XY_P * rtb_uv_error_C_mPs_idx_0 +
                         Controller_DW.DiscreteTimeIntegrator_DSTATE[0]) +
                        rtb_Add3_j_idx_0 : 0.0F) +
      ((Controller_U.FMS_Out.cmd_mask & 512) > 0 ? Controller_U.FMS_Out.ax_cmd :
       0.0F);
    rtb_Add3_j_idx_1 = ((Controller_U.FMS_Out.cmd_mask & 128) > 0 ?
                        (CONTROL_PARAM.VEL_XY_P * rtb_uv_error_C_mPs_idx_1 +
                         Controller_DW.DiscreteTimeIntegrator_DSTATE[1]) +
                        rtb_Multiply_l_idx_0 : 0.0F) +
      ((Controller_U.FMS_Out.cmd_mask & 1024) > 0 ? Controller_U.FMS_Out.ay_cmd :
       0.0F);
  } else {
    rtb_Add3_j_idx_0 += CONTROL_PARAM.VEL_XY_P * rtb_uv_error_C_mPs_idx_0 +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0];
    rtb_Add3_j_idx_1 = (CONTROL_PARAM.VEL_XY_P * rtb_uv_error_C_mPs_idx_1 +
                        Controller_DW.DiscreteTimeIntegrator_DSTATE[1]) +
      rtb_Multiply_l_idx_0;
  }

  /* End of Switch: '<S95>/Switch' */

  /* Trigonometry: '<S92>/Atan' incorporates:
   *  Constant: '<S92>/g'
   *  Gain: '<S92>/Gain1'
   *  Gain: '<S92>/gain'
   *  Product: '<S92>/Divide'
   */
  rtb_Add_i = atanf(1.1F * rtb_Add3_j_idx_1 / 9.8055F);
  rtb_Add3_j_idx_1 = atanf(1.1F * -rtb_Add3_j_idx_0 / 9.8055F);

  /* Switch: '<S83>/Switch' incorporates:
   *  Constant: '<S90>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  Logic: '<S83>/Logical Operator'
   *  RelationalOperator: '<S89>/Compare'
   *  RelationalOperator: '<S90>/Compare'
   *  Saturate: '<S92>/Saturation'
   *  Switch: '<S83>/Switch1'
   */
  if ((Controller_U.FMS_Out.ctrl_mode == 3) || (Controller_U.FMS_Out.ctrl_mode ==
       4)) {
    rtb_Add3_j_idx_0 = Controller_U.FMS_Out.phi_cmd;
    rtb_Add3_j_idx_1 = Controller_U.FMS_Out.theta_cmd;
  } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
    /* Switch: '<S91>/Switch' incorporates:
     *  S-Function (sfix_bitop): '<S91>/cmd_phi valid'
     *  S-Function (sfix_bitop): '<S91>/cmd_theta valid'
     *  Saturate: '<S92>/Saturation'
     *  Switch: '<S83>/Switch1'
     */
    if ((Controller_U.FMS_Out.cmd_mask & 8) > 0) {
      rtb_Add3_j_idx_0 = Controller_U.FMS_Out.phi_cmd;
    } else if (rtb_Add_i > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      /* Saturate: '<S92>/Saturation' */
      rtb_Add3_j_idx_0 = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    } else if (rtb_Add_i < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      /* Saturate: '<S92>/Saturation' */
      rtb_Add3_j_idx_0 = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    } else {
      rtb_Add3_j_idx_0 = rtb_Add_i;
    }

    if ((Controller_U.FMS_Out.cmd_mask & 16) > 0) {
      rtb_Add3_j_idx_1 = Controller_U.FMS_Out.theta_cmd;
    } else if (rtb_Add3_j_idx_1 > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      /* Saturate: '<S92>/Saturation' */
      rtb_Add3_j_idx_1 = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_Add3_j_idx_1 < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S92>/Saturation' */
        rtb_Add3_j_idx_1 = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
      }
    }

    /* End of Switch: '<S91>/Switch' */
  } else {
    if (rtb_Add_i > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      /* Saturate: '<S92>/Saturation' incorporates:
       *  Switch: '<S83>/Switch1'
       */
      rtb_Add3_j_idx_0 = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    } else if (rtb_Add_i < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      /* Saturate: '<S92>/Saturation' incorporates:
       *  Switch: '<S83>/Switch1'
       */
      rtb_Add3_j_idx_0 = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    } else {
      /* Switch: '<S83>/Switch1' incorporates:
       *  Saturate: '<S92>/Saturation'
       */
      rtb_Add3_j_idx_0 = rtb_Add_i;
    }

    /* Saturate: '<S92>/Saturation' */
    if (rtb_Add3_j_idx_1 > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      /* Switch: '<S83>/Switch1' */
      rtb_Add3_j_idx_1 = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_Add3_j_idx_1 < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
        /* Switch: '<S83>/Switch1' */
        rtb_Add3_j_idx_1 = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
      }
    }
  }

  /* End of Switch: '<S83>/Switch' */

  /* Sum: '<S84>/Sum' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Multiply_l_idx_0 = rtb_Add3_j_idx_0 - Controller_U.INS_Out.phi;

  /* Product: '<S87>/Divide1' incorporates:
   *  Abs: '<S87>/Abs'
   *  Constant: '<S87>/const2'
   */
  rtb_Add_i = fabsf(rtb_Multiply_l_idx_0) / 0.002F;

  /* Product: '<S87>/Divide' incorporates:
   *  Constant: '<S85>/Constant1'
   *  Constant: '<S87>/const1'
   *  Math: '<S87>/Square'
   *  SignalConversion: '<S87>/TmpSignal ConversionAtSquareInport1'
   */
  rtb_Multiply_l_idx_1 = 9.5993F / (CONTROL_PARAM.ROLL_P * CONTROL_PARAM.ROLL_P);

  /* Signum: '<S87>/Sign' */
  if (rtb_Multiply_l_idx_0 < 0.0F) {
    rtb_Subtract3_i = -1.0F;
  } else if (rtb_Multiply_l_idx_0 > 0.0F) {
    rtb_Subtract3_i = 1.0F;
  } else {
    rtb_Subtract3_i = rtb_Multiply_l_idx_0;
  }

  /* Switch: '<S87>/Switch' incorporates:
   *  Constant: '<S85>/Constant1'
   *  Gain: '<S87>/Gain1'
   *  Gain: '<S87>/Gain2'
   *  Logic: '<S87>/Logical Operator'
   *  Product: '<S87>/Multiply'
   *  Product: '<S87>/Multiply1'
   *  Product: '<S87>/Multiply2'
   *  Product: '<S87>/Multiply3'
   *  RelationalOperator: '<S87>/Relational Operator'
   *  RelationalOperator: '<S87>/Relational Operator2'
   *  SignalConversion: '<S87>/TmpSignal ConversionAtSquareInport1'
   *  Sqrt: '<S87>/Sqrt'
   *  Sum: '<S87>/Subtract'
   */
  if ((rtb_Multiply_l_idx_0 <= rtb_Multiply_l_idx_1) && (rtb_Multiply_l_idx_0 >=
       -rtb_Multiply_l_idx_1)) {
    rtb_Subtract3_i = rtb_Multiply_l_idx_0 * CONTROL_PARAM.ROLL_P;
  } else {
    rtb_Subtract3_i *= sqrtf((rtb_Subtract3_i * rtb_Multiply_l_idx_0 - 0.5F *
      rtb_Multiply_l_idx_1) * Controller_ConstB.Gain);
  }

  /* Gain: '<S87>/Gain3' */
  rtb_Multiply_l_idx_1 = -rtb_Add_i;

  /* Switch: '<S88>/Switch' incorporates:
   *  Gain: '<S87>/Gain3'
   *  RelationalOperator: '<S88>/UpperRelop'
   */
  if (rtb_Subtract3_i >= -rtb_Add_i) {
    rtb_Multiply_l_idx_1 = rtb_Subtract3_i;
  }

  /* Switch: '<S88>/Switch2' incorporates:
   *  RelationalOperator: '<S88>/LowerRelop1'
   */
  if (rtb_Subtract3_i <= rtb_Add_i) {
    rtb_Add_i = rtb_Multiply_l_idx_1;
  }

  /* Saturate: '<S68>/Saturation1' */
  if (rtb_Add_i > CONTROL_PARAM.P_Q_CMD_LIM) {
    rtb_Add_i = CONTROL_PARAM.P_Q_CMD_LIM;
  } else {
    if (rtb_Add_i < -CONTROL_PARAM.P_Q_CMD_LIM) {
      rtb_Add_i = -CONTROL_PARAM.P_Q_CMD_LIM;
    }
  }

  /* Product: '<S87>/Divide1' */
  rtb_Add3_j_idx_0 = rtb_Add_i;

  /* Sum: '<S84>/Sum' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Multiply_l_idx_0 = rtb_Add3_j_idx_1 - Controller_U.INS_Out.theta;

  /* Product: '<S87>/Divide1' incorporates:
   *  Abs: '<S87>/Abs'
   *  Constant: '<S87>/const2'
   */
  rtb_Add_i = fabsf(rtb_Multiply_l_idx_0) / 0.002F;

  /* Product: '<S87>/Divide' incorporates:
   *  Constant: '<S85>/Constant2'
   *  Constant: '<S87>/const1'
   *  Math: '<S87>/Square'
   *  SignalConversion: '<S87>/TmpSignal ConversionAtSquareInport1'
   */
  rtb_Multiply_l_idx_1 = 9.5993F / (CONTROL_PARAM.PITCH_P *
    CONTROL_PARAM.PITCH_P);

  /* Signum: '<S87>/Sign' */
  if (rtb_Multiply_l_idx_0 < 0.0F) {
    rtb_Subtract3_i = -1.0F;
  } else if (rtb_Multiply_l_idx_0 > 0.0F) {
    rtb_Subtract3_i = 1.0F;
  } else {
    rtb_Subtract3_i = rtb_Multiply_l_idx_0;
  }

  /* Switch: '<S87>/Switch' incorporates:
   *  Constant: '<S85>/Constant2'
   *  Gain: '<S87>/Gain1'
   *  Gain: '<S87>/Gain2'
   *  Logic: '<S87>/Logical Operator'
   *  Product: '<S87>/Multiply'
   *  Product: '<S87>/Multiply1'
   *  Product: '<S87>/Multiply2'
   *  Product: '<S87>/Multiply3'
   *  RelationalOperator: '<S87>/Relational Operator'
   *  RelationalOperator: '<S87>/Relational Operator2'
   *  SignalConversion: '<S87>/TmpSignal ConversionAtSquareInport1'
   *  Sqrt: '<S87>/Sqrt'
   *  Sum: '<S87>/Subtract'
   */
  if ((rtb_Multiply_l_idx_0 <= rtb_Multiply_l_idx_1) && (rtb_Multiply_l_idx_0 >=
       -rtb_Multiply_l_idx_1)) {
    rtb_Subtract3_i = rtb_Multiply_l_idx_0 * CONTROL_PARAM.PITCH_P;
  } else {
    rtb_Subtract3_i *= sqrtf((rtb_Subtract3_i * rtb_Multiply_l_idx_0 - 0.5F *
      rtb_Multiply_l_idx_1) * Controller_ConstB.Gain);
  }

  /* Gain: '<S87>/Gain3' */
  rtb_Multiply_l_idx_1 = -rtb_Add_i;

  /* Switch: '<S88>/Switch' incorporates:
   *  Gain: '<S87>/Gain3'
   *  RelationalOperator: '<S88>/UpperRelop'
   */
  if (rtb_Subtract3_i >= -rtb_Add_i) {
    rtb_Multiply_l_idx_1 = rtb_Subtract3_i;
  }

  /* Switch: '<S88>/Switch2' incorporates:
   *  RelationalOperator: '<S88>/LowerRelop1'
   */
  if (rtb_Subtract3_i <= rtb_Add_i) {
    rtb_Add_i = rtb_Multiply_l_idx_1;
  }

  /* Saturate: '<S68>/Saturation1' */
  if (rtb_Add_i > CONTROL_PARAM.P_Q_CMD_LIM) {
    rtb_Add_i = CONTROL_PARAM.P_Q_CMD_LIM;
  } else {
    if (rtb_Add_i < -CONTROL_PARAM.P_Q_CMD_LIM) {
      rtb_Add_i = -CONTROL_PARAM.P_Q_CMD_LIM;
    }
  }

  /* Saturate: '<S68>/Saturation' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_U.FMS_Out.psi_rate_cmd > CONTROL_PARAM.R_CMD_LIM) {
    rtb_Subtract3_i = CONTROL_PARAM.R_CMD_LIM;
  } else if (Controller_U.FMS_Out.psi_rate_cmd < -CONTROL_PARAM.R_CMD_LIM) {
    rtb_Subtract3_i = -CONTROL_PARAM.R_CMD_LIM;
  } else {
    rtb_Subtract3_i = Controller_U.FMS_Out.psi_rate_cmd;
  }

  /* End of Saturate: '<S68>/Saturation' */

  /* Trigonometry: '<S78>/Sin' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Add3 = arm_sin_f32(Controller_U.INS_Out.phi);

  /* Trigonometry: '<S78>/Cos1' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_DiscreteTimeIntegrator1_j = arm_cos_f32(Controller_U.INS_Out.theta);

  /* Product: '<S78>/Multiply3' */
  rtb_Multiply_l_idx_1 = rtb_Add3 * rtb_DiscreteTimeIntegrator1_j *
    rtb_Subtract3_i;

  /* Trigonometry: '<S78>/Cos' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_DiscreteTimeIntegrator_h = arm_cos_f32(Controller_U.INS_Out.phi);

  /* Product: '<S78>/Multiply1' */
  rtb_rate_error_B_radPs_idx_1 = rtb_DiscreteTimeIntegrator_h * rtb_Add_i;

  /* Product: '<S78>/Multiply4' */
  rtb_Add3 *= rtb_Add_i;

  /* Switch: '<S69>/Switch' incorporates:
   *  Constant: '<S79>/Constant'
   *  Constant: '<S80>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  RelationalOperator: '<S79>/Compare'
   *  RelationalOperator: '<S80>/Compare'
   *  Switch: '<S69>/Switch1'
   */
  if (Controller_U.FMS_Out.ctrl_mode == 2) {
    rtb_Multiply_l_idx_0 = Controller_U.FMS_Out.p_cmd;
    rtb_Multiply_l_idx_1 = Controller_U.FMS_Out.q_cmd;
    rtb_DiscreteTimeIntegrator1_j = Controller_U.FMS_Out.r_cmd;
  } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
    /* Switch: '<S81>/Switch' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S78>/Multiply'
     *  Product: '<S78>/Multiply1'
     *  Product: '<S78>/Multiply5'
     *  S-Function (sfix_bitop): '<S81>/cmd_p valid'
     *  S-Function (sfix_bitop): '<S81>/cmd_q valid'
     *  S-Function (sfix_bitop): '<S81>/cmd_r valid'
     *  Sum: '<S78>/Add'
     *  Sum: '<S78>/Add1'
     *  Sum: '<S78>/Add2'
     *  Switch: '<S69>/Switch1'
     *  Trigonometry: '<S78>/Sin1'
     */
    if ((Controller_U.FMS_Out.cmd_mask & 1) > 0) {
      rtb_Multiply_l_idx_0 = Controller_U.FMS_Out.p_cmd;
    } else {
      rtb_Multiply_l_idx_0 = rtb_Add3_j_idx_0 - arm_sin_f32
        (Controller_U.INS_Out.theta) * rtb_Subtract3_i;
    }

    if ((Controller_U.FMS_Out.cmd_mask & 2) > 0) {
      rtb_Multiply_l_idx_1 = Controller_U.FMS_Out.q_cmd;
    } else {
      rtb_Multiply_l_idx_1 += rtb_rate_error_B_radPs_idx_1;
    }

    if ((Controller_U.FMS_Out.cmd_mask & 4) > 0) {
      rtb_DiscreteTimeIntegrator1_j = Controller_U.FMS_Out.r_cmd;
    } else {
      rtb_DiscreteTimeIntegrator1_j = rtb_DiscreteTimeIntegrator_h *
        rtb_DiscreteTimeIntegrator1_j * rtb_Subtract3_i - rtb_Add3;
    }

    /* End of Switch: '<S81>/Switch' */
  } else {
    /* Switch: '<S69>/Switch1' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S78>/Multiply'
     *  Product: '<S78>/Multiply3'
     *  Product: '<S78>/Multiply5'
     *  Sum: '<S78>/Add'
     *  Sum: '<S78>/Add1'
     *  Sum: '<S78>/Add2'
     *  Trigonometry: '<S78>/Sin1'
     */
    rtb_Multiply_l_idx_0 = rtb_Add3_j_idx_0 - arm_sin_f32
      (Controller_U.INS_Out.theta) * rtb_Subtract3_i;
    rtb_Multiply_l_idx_1 += rtb_rate_error_B_radPs_idx_1;
    rtb_DiscreteTimeIntegrator1_j = rtb_DiscreteTimeIntegrator_h *
      rtb_DiscreteTimeIntegrator1_j * rtb_Subtract3_i - rtb_Add3;
  }

  /* End of Switch: '<S69>/Switch' */

  /* Sum: '<S70>/Sum' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_DiscreteTimeIntegrator_h = rtb_Multiply_l_idx_0 - Controller_U.INS_Out.p;
  rtb_rate_error_B_radPs_idx_1 = rtb_Multiply_l_idx_1 - Controller_U.INS_Out.q;
  rtb_rate_error_B_radPs_idx_2 = rtb_DiscreteTimeIntegrator1_j -
    Controller_U.INS_Out.r;

  /* DiscreteIntegrator: '<S73>/Discrete-Time Integrator5' */
  if (Controller_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] =
      rtb_DiscreteTimeIntegrator_h;
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] =
      rtb_rate_error_B_radPs_idx_1;
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] =
      rtb_rate_error_B_radPs_idx_2;
  }

  /* DiscreteIntegrator: '<S75>/Discrete-Time Integrator' incorporates:
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

  /* DiscreteIntegrator: '<S77>/Discrete-Time Integrator1' incorporates:
   *  DiscreteIntegrator: '<S73>/Discrete-Time Integrator5'
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_l != 0) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[0] =
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[0];
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[1] =
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[1];
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[2] =
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[2];
  }

  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevR_i != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[0] =
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[0];
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[1] =
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[1];
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[2] =
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[2];
  }

  /* Gain: '<S77>/Gain' incorporates:
   *  DiscreteIntegrator: '<S73>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S77>/Discrete-Time Integrator1'
   *  Sum: '<S77>/Sum5'
   */
  rtb_Multiply_l_idx_0 = (Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] -
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[0]) * 188.49556F;
  rtb_Multiply_l_idx_1 = (Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] -
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[1]) * 188.49556F;
  rtb_DiscreteTimeIntegrator1_j = (Controller_DW.DiscreteTimeIntegrator5_DSTATE
    [2] - Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[2]) * 188.49556F;

  /* Switch: '<S77>/Switch' incorporates:
   *  Gain: '<S77>/Gain1'
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_U.FMS_Out.reset > 0) {
    rtb_Saturation_d_idx_0 = 0.0F;
    rtb_Saturation_d_idx_1 = 0.0F;
    rtb_Saturation_d_idx_2 = 0.0F;
  } else {
    rtb_Saturation_d_idx_0 = rtb_Multiply_l_idx_0;
    rtb_Saturation_d_idx_1 = rtb_Multiply_l_idx_1;
    rtb_Saturation_d_idx_2 = rtb_DiscreteTimeIntegrator1_j;
  }

  /* End of Switch: '<S77>/Switch' */

  /* Product: '<S74>/Multiply' incorporates:
   *  Constant: '<S74>/gain1'
   */
  rtb_Add_i = CONTROL_PARAM.ROLL_RATE_D * rtb_Saturation_d_idx_0;

  /* Saturate: '<S74>/Saturation' */
  if (rtb_Add_i > CONTROL_PARAM.RATE_D_MAX) {
    rtb_Add_i = CONTROL_PARAM.RATE_D_MAX;
  } else {
    if (rtb_Add_i < CONTROL_PARAM.RATE_D_MIN) {
      rtb_Add_i = CONTROL_PARAM.RATE_D_MIN;
    }
  }

  /* Product: '<S74>/Multiply' incorporates:
   *  Constant: '<S74>/gain2'
   */
  rtb_Saturation_d_idx_0 = rtb_Add_i;
  rtb_Add_i = CONTROL_PARAM.PITCH_RATE_D * rtb_Saturation_d_idx_1;

  /* Saturate: '<S74>/Saturation' */
  if (rtb_Add_i > CONTROL_PARAM.RATE_D_MAX) {
    rtb_Add_i = CONTROL_PARAM.RATE_D_MAX;
  } else {
    if (rtb_Add_i < CONTROL_PARAM.RATE_D_MIN) {
      rtb_Add_i = CONTROL_PARAM.RATE_D_MIN;
    }
  }

  /* Product: '<S74>/Multiply' incorporates:
   *  Constant: '<S74>/gain3'
   */
  rtb_Saturation_d_idx_1 = rtb_Add_i;
  rtb_Add_i = CONTROL_PARAM.YAW_RATE_D * rtb_Saturation_d_idx_2;

  /* Saturate: '<S74>/Saturation' */
  if (rtb_Add_i > CONTROL_PARAM.RATE_D_MAX) {
    rtb_Add_i = CONTROL_PARAM.RATE_D_MAX;
  } else {
    if (rtb_Add_i < CONTROL_PARAM.RATE_D_MIN) {
      rtb_Add_i = CONTROL_PARAM.RATE_D_MIN;
    }
  }

  /* Sum: '<S71>/Add' incorporates:
   *  Constant: '<S76>/gain1'
   *  Constant: '<S76>/gain2'
   *  Constant: '<S76>/gain3'
   *  DiscreteIntegrator: '<S73>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S75>/Discrete-Time Integrator'
   *  Product: '<S76>/Multiply'
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
                  Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2]) + rtb_Add_i;

  /* Gain: '<S111>/Gain' incorporates:
   *  DiscreteIntegrator: '<S113>/Integrator1'
   *  Inport: '<Root>/INS_Out'
   *  Sum: '<S111>/Sum1'
   */
  rtb_Gain_fl = -(Controller_DW.Integrator1_DSTATE_p - Controller_U.INS_Out.vd);

  /* DiscreteIntegrator: '<S116>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S116>/Constant'
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator_PrevRe_m != 0)) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m = CONTROL_PARAM.VEL_Z_I_MIN;
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

  /* DiscreteIntegrator: '<S118>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_k != 0) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_h = rtb_Gain_fl;
  }

  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_Prev_iy != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_h = rtb_Gain_fl;
  }

  /* Gain: '<S118>/Gain' incorporates:
   *  DiscreteIntegrator: '<S118>/Discrete-Time Integrator1'
   *  Sum: '<S118>/Sum5'
   */
  rtb_Gain_g2 = (rtb_Gain_fl - Controller_DW.DiscreteTimeIntegrator1_DSTAT_h) *
    62.831852F;

  /* Switch: '<S118>/Switch' incorporates:
   *  Gain: '<S118>/Gain1'
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_U.FMS_Out.reset > 0) {
    rtb_Add_i = 0.0F;
  } else {
    rtb_Add_i = rtb_Gain_g2;
  }

  /* End of Switch: '<S118>/Switch' */

  /* Product: '<S115>/Multiply' incorporates:
   *  Constant: '<S115>/kd'
   */
  rtb_Subtract3_i = CONTROL_PARAM.VEL_Z_D * rtb_Add_i;

  /* Saturate: '<S115>/Saturation' */
  if (rtb_Subtract3_i > CONTROL_PARAM.VEL_Z_D_MAX) {
    rtb_Subtract3_i = CONTROL_PARAM.VEL_Z_D_MAX;
  } else {
    if (rtb_Subtract3_i < CONTROL_PARAM.VEL_Z_D_MIN) {
      rtb_Subtract3_i = CONTROL_PARAM.VEL_Z_D_MIN;
    }
  }

  /* End of Saturate: '<S115>/Saturation' */

  /* Sum: '<S112>/Add' incorporates:
   *  Constant: '<S117>/kp'
   *  DiscreteIntegrator: '<S116>/Discrete-Time Integrator'
   *  Product: '<S117>/Multiply'
   */
  rtb_Add_i = (CONTROL_PARAM.VEL_Z_P * rtb_Gain_fl +
               Controller_DW.DiscreteTimeIntegrator_DSTATE_m) + rtb_Subtract3_i;

  /* Product: '<S110>/Multiply' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S110>/Cos'
   *  Trigonometry: '<S110>/Cos1'
   */
  rtb_Subtract3_i = arm_cos_f32(Controller_U.INS_Out.phi) * arm_cos_f32
    (Controller_U.INS_Out.theta);

  /* Saturate: '<S110>/Saturation1' */
  if (rtb_Subtract3_i > 1.0F) {
    rtb_Add3 = 1.0F;
  } else if (rtb_Subtract3_i < 0.5F) {
    rtb_Add3 = 0.5F;
  } else {
    rtb_Add3 = rtb_Subtract3_i;
  }

  /* End of Saturate: '<S110>/Saturation1' */

  /* Gain: '<S110>/Gain' */
  rtb_Subtract3_i *= 2.0F;

  /* Saturate: '<S110>/Saturation' */
  if (rtb_Subtract3_i > 1.0F) {
    rtb_Subtract3_i = 1.0F;
  } else {
    if (rtb_Subtract3_i < 0.0F) {
      rtb_Subtract3_i = 0.0F;
    }
  }

  /* End of Saturate: '<S110>/Saturation' */

  /* Product: '<S110>/Multiply1' incorporates:
   *  Constant: '<S110>/Constant'
   *  Product: '<S110>/Divide'
   */
  rtb_Subtract3_i *= 1.0F / rtb_Add3 * rtb_Add_i;

  /* Saturate: '<S109>/Saturation' */
  if (rtb_Subtract3_i > 0.35F) {
    rtb_Saturation_i = 0.35F;
  } else if (rtb_Subtract3_i < -0.35F) {
    rtb_Saturation_i = -0.35F;
  } else {
    rtb_Saturation_i = rtb_Subtract3_i;
  }

  /* End of Saturate: '<S109>/Saturation' */

  /* Outputs for Atomic SubSystem: '<S2>/Control_Allocation' */
#if AIRFRAME == 6

  /* Output and update for atomic system: '<S4>/Coxial_Hexacopter_x' */
  {
    uint16_T rtb_throttle_cmd;
    uint16_T rtb_MultiportSwitch[12];
    int32_T i_b;
    real32_T tmp_b;
    real32_T tmp_k;
    real32_T tmp_i;
    real32_T u0_b;
    uint16_T u0_k;

    /* MultiPortSwitch: '<S16>/Multiport Switch' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    switch (Controller_U.FMS_Out.status) {
     case 1:
      for (i_b = 0; i_b < 12; i_b++) {
        rtb_MultiportSwitch[i_b] = 1000U;
      }
      break;

     case 2:
      for (i_b = 0; i_b < 12; i_b++) {
        rtb_MultiportSwitch[i_b] = 1150U;
      }
      break;

     case 3:
      /* Switch: '<S15>/Switch' incorporates:
       *  Constant: '<S19>/Constant'
       *  Logic: '<S15>/Logical Operator'
       *  RelationalOperator: '<S18>/Compare'
       *  RelationalOperator: '<S19>/Compare'
       *  Saturate: '<S7>/Saturation2'
       *  Switch: '<S15>/Switch1'
       */
      if ((Controller_U.FMS_Out.ctrl_mode == 1) ||
          (Controller_U.FMS_Out.ctrl_mode == 2) ||
          (Controller_U.FMS_Out.ctrl_mode == 3)) {
        rtb_throttle_cmd = Controller_U.FMS_Out.throttle_cmd;
      } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
        /* Switch: '<S20>/Switch' incorporates:
         *  Constant: '<S17>/Constant1'
         *  DataTypeConversion: '<S17>/Data Type Conversion'
         *  Gain: '<S17>/Gain1'
         *  S-Function (sfix_bitop): '<S20>/cmd_throttle valid'
         *  Saturate: '<S7>/Saturation2'
         *  Sum: '<S17>/Sum1'
         *  Switch: '<S15>/Switch1'
         */
        if ((Controller_U.FMS_Out.cmd_mask & 4096) > 0) {
          rtb_throttle_cmd = Controller_U.FMS_Out.throttle_cmd;
        } else {
          if (rtb_Saturation_i > 1.0F) {
            /* Saturate: '<S7>/Saturation2' */
            u0_b = 1.0F;
          } else if (rtb_Saturation_i < -1.0F) {
            /* Saturate: '<S7>/Saturation2' */
            u0_b = -1.0F;
          } else {
            /* Saturate: '<S7>/Saturation2' */
            u0_b = rtb_Saturation_i;
          }

          /* Sum: '<S17>/Sum' incorporates:
           *  Constant: '<S17>/hover_throttle'
           *  Saturate: '<S7>/Saturation2'
           */
          u0_b += CONTROL_PARAM.HOVER_THRO;

          /* Saturate: '<S17>/Saturation' */
          if (u0_b > 1.0F) {
            u0_b = 1.0F;
          } else {
            if (u0_b < 0.0F) {
              u0_b = 0.0F;
            }
          }

          rtb_throttle_cmd = (uint16_T)((uint32_T)fmodf(floorf(1000.0F * u0_b),
            4.2949673E+9F) + 1000U);
        }

        /* End of Switch: '<S20>/Switch' */
      } else {
        if (rtb_Saturation_i > 1.0F) {
          /* Saturate: '<S7>/Saturation2' */
          u0_b = 1.0F;
        } else if (rtb_Saturation_i < -1.0F) {
          /* Saturate: '<S7>/Saturation2' */
          u0_b = -1.0F;
        } else {
          /* Saturate: '<S7>/Saturation2' */
          u0_b = rtb_Saturation_i;
        }

        /* Sum: '<S17>/Sum' incorporates:
         *  Constant: '<S17>/hover_throttle'
         *  Saturate: '<S7>/Saturation2'
         */
        u0_b += CONTROL_PARAM.HOVER_THRO;

        /* Saturate: '<S17>/Saturation' */
        if (u0_b > 1.0F) {
          u0_b = 1.0F;
        } else {
          if (u0_b < 0.0F) {
            u0_b = 0.0F;
          }
        }

        /* Switch: '<S15>/Switch1' incorporates:
         *  Constant: '<S17>/Constant1'
         *  DataTypeConversion: '<S17>/Data Type Conversion'
         *  Gain: '<S17>/Gain1'
         *  Sum: '<S17>/Sum1'
         */
        rtb_throttle_cmd = (uint16_T)((uint32_T)fmodf(floorf(1000.0F * u0_b),
          4.2949673E+9F) + 1000U);
      }

      /* End of Switch: '<S15>/Switch' */

      /* Saturate: '<S7>/Saturation1' */
      if (rtb_Add_g[0] > 1.0F) {
        tmp_b = 1.0F;
      } else if (rtb_Add_g[0] < -1.0F) {
        tmp_b = -1.0F;
      } else {
        tmp_b = rtb_Add_g[0];
      }

      if (rtb_Add_g[1] > 1.0F) {
        tmp_k = 1.0F;
      } else if (rtb_Add_g[1] < -1.0F) {
        tmp_k = -1.0F;
      } else {
        tmp_k = rtb_Add_g[1];
      }

      if (rtb_Add_g[2] > 1.0F) {
        tmp_i = 1.0F;
      } else if (rtb_Add_g[2] < -1.0F) {
        tmp_i = -1.0F;
      } else {
        tmp_i = rtb_Add_g[2];
      }

      /* End of Saturate: '<S7>/Saturation1' */

      /* Product: '<S7>/Multiply' */
      for (i_b = 0; i_b < 12; i_b++) {
        /* Saturate: '<S7>/Saturation' incorporates:
         *  Constant: '<S7>/Effective_Matrix'
         *  Gain: '<S7>/Gain'
         *  Sum: '<S7>/Add'
         */
        u0_b = fmodf(floorf(1000.0F *
                            (Controller_ConstP.Effective_Matrix_Value[i_b + 24] *
                             tmp_i +
                             (Controller_ConstP.Effective_Matrix_Value[i_b + 12]
                              * tmp_k +
                              Controller_ConstP.Effective_Matrix_Value[i_b] *
                              tmp_b)) + (real32_T)rtb_throttle_cmd), 65536.0F);
        u0_k = (uint16_T)(u0_b < 0.0F ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
                          -u0_b : (int32_T)(uint16_T)u0_b);
        if (u0_k > 1900) {
          rtb_MultiportSwitch[i_b] = 1900U;
        } else if (u0_k < 1100) {
          rtb_MultiportSwitch[i_b] = 1100U;
        } else {
          rtb_MultiportSwitch[i_b] = u0_k;
        }

        /* End of Saturate: '<S7>/Saturation' */
      }

      /* End of Product: '<S7>/Multiply' */
      break;

     default:
      for (i_b = 0; i_b < 12; i_b++) {
        rtb_MultiportSwitch[i_b] = 1000U;
      }
      break;
    }

    /* End of MultiPortSwitch: '<S16>/Multiport Switch' */

    /* Reshape: '<S16>/Reshape' */
    for (i_b = 0; i_b < 12; i_b++) {
      rtb_VariantMergeForOutportactua[i_b] = rtb_MultiportSwitch[i_b];
    }

    rtb_VariantMergeForOutportactua[12] = 0U;
    rtb_VariantMergeForOutportactua[13] = 0U;
    rtb_VariantMergeForOutportactua[14] = 0U;
    rtb_VariantMergeForOutportactua[15] = 0U;

    /* End of Reshape: '<S16>/Reshape' */
  }

#elif AIRFRAME == 3

  /* Output and update for atomic system: '<S4>/Coxial_Quadcopter_x' */
  {
    uint16_T rtb_throttle_cmd_b;
    uint16_T rtb_MultiportSwitch_i[8];
    int32_T i_n;
    real32_T tmp_n;
    real32_T tmp_d;
    real32_T tmp_a;
    real32_T u0_n;
    uint16_T u0_d;

    /* MultiPortSwitch: '<S22>/Multiport Switch' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    switch (Controller_U.FMS_Out.status) {
     case 1:
      for (i_n = 0; i_n < 8; i_n++) {
        rtb_MultiportSwitch_i[i_n] = 1000U;
      }
      break;

     case 2:
      for (i_n = 0; i_n < 8; i_n++) {
        rtb_MultiportSwitch_i[i_n] = 1150U;
      }
      break;

     case 3:
      /* Switch: '<S21>/Switch' incorporates:
       *  Constant: '<S25>/Constant'
       *  Logic: '<S21>/Logical Operator'
       *  RelationalOperator: '<S24>/Compare'
       *  RelationalOperator: '<S25>/Compare'
       *  Saturate: '<S8>/Saturation2'
       *  Switch: '<S21>/Switch1'
       */
      if ((Controller_U.FMS_Out.ctrl_mode == 1) ||
          (Controller_U.FMS_Out.ctrl_mode == 2) ||
          (Controller_U.FMS_Out.ctrl_mode == 3)) {
        rtb_throttle_cmd_b = Controller_U.FMS_Out.throttle_cmd;
      } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
        /* Switch: '<S26>/Switch' incorporates:
         *  Constant: '<S23>/Constant1'
         *  DataTypeConversion: '<S23>/Data Type Conversion'
         *  Gain: '<S23>/Gain1'
         *  S-Function (sfix_bitop): '<S26>/cmd_throttle valid'
         *  Saturate: '<S8>/Saturation2'
         *  Sum: '<S23>/Sum1'
         *  Switch: '<S21>/Switch1'
         */
        if ((Controller_U.FMS_Out.cmd_mask & 4096) > 0) {
          rtb_throttle_cmd_b = Controller_U.FMS_Out.throttle_cmd;
        } else {
          if (rtb_Saturation_i > 1.0F) {
            /* Saturate: '<S8>/Saturation2' */
            u0_n = 1.0F;
          } else if (rtb_Saturation_i < -1.0F) {
            /* Saturate: '<S8>/Saturation2' */
            u0_n = -1.0F;
          } else {
            /* Saturate: '<S8>/Saturation2' */
            u0_n = rtb_Saturation_i;
          }

          /* Sum: '<S23>/Sum' incorporates:
           *  Constant: '<S23>/hover_throttle'
           *  Saturate: '<S8>/Saturation2'
           */
          u0_n += CONTROL_PARAM.HOVER_THRO;

          /* Saturate: '<S23>/Saturation' */
          if (u0_n > 1.0F) {
            u0_n = 1.0F;
          } else {
            if (u0_n < 0.0F) {
              u0_n = 0.0F;
            }
          }

          rtb_throttle_cmd_b = (uint16_T)((uint32_T)fmodf(floorf(1000.0F * u0_n),
            4.2949673E+9F) + 1000U);
        }

        /* End of Switch: '<S26>/Switch' */
      } else {
        if (rtb_Saturation_i > 1.0F) {
          /* Saturate: '<S8>/Saturation2' */
          u0_n = 1.0F;
        } else if (rtb_Saturation_i < -1.0F) {
          /* Saturate: '<S8>/Saturation2' */
          u0_n = -1.0F;
        } else {
          /* Saturate: '<S8>/Saturation2' */
          u0_n = rtb_Saturation_i;
        }

        /* Sum: '<S23>/Sum' incorporates:
         *  Constant: '<S23>/hover_throttle'
         *  Saturate: '<S8>/Saturation2'
         */
        u0_n += CONTROL_PARAM.HOVER_THRO;

        /* Saturate: '<S23>/Saturation' */
        if (u0_n > 1.0F) {
          u0_n = 1.0F;
        } else {
          if (u0_n < 0.0F) {
            u0_n = 0.0F;
          }
        }

        /* Switch: '<S21>/Switch1' incorporates:
         *  Constant: '<S23>/Constant1'
         *  DataTypeConversion: '<S23>/Data Type Conversion'
         *  Gain: '<S23>/Gain1'
         *  Sum: '<S23>/Sum1'
         */
        rtb_throttle_cmd_b = (uint16_T)((uint32_T)fmodf(floorf(1000.0F * u0_n),
          4.2949673E+9F) + 1000U);
      }

      /* End of Switch: '<S21>/Switch' */

      /* Saturate: '<S8>/Saturation1' */
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

      /* End of Saturate: '<S8>/Saturation1' */

      /* Product: '<S8>/Multiply' */
      for (i_n = 0; i_n < 8; i_n++) {
        /* Saturate: '<S8>/Saturation' incorporates:
         *  Constant: '<S8>/Effective_Matrix'
         *  Gain: '<S8>/Gain'
         *  Sum: '<S8>/Add'
         */
        u0_n = fmodf(floorf(1000.0F *
                            (Controller_ConstP.Effective_Matrix_Value_j[i_n + 16]
                             * tmp_a +
                             (Controller_ConstP.Effective_Matrix_Value_j[i_n + 8]
                              * tmp_d +
                              Controller_ConstP.Effective_Matrix_Value_j[i_n] *
                              tmp_n)) + (real32_T)rtb_throttle_cmd_b), 65536.0F);
        u0_d = (uint16_T)(u0_n < 0.0F ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
                          -u0_n : (int32_T)(uint16_T)u0_n);
        if (u0_d > 1900) {
          rtb_MultiportSwitch_i[i_n] = 1900U;
        } else if (u0_d < 1100) {
          rtb_MultiportSwitch_i[i_n] = 1100U;
        } else {
          rtb_MultiportSwitch_i[i_n] = u0_d;
        }

        /* End of Saturate: '<S8>/Saturation' */
      }

      /* End of Product: '<S8>/Multiply' */
      break;

     default:
      for (i_n = 0; i_n < 8; i_n++) {
        rtb_MultiportSwitch_i[i_n] = 1000U;
      }
      break;
    }

    /* End of MultiPortSwitch: '<S22>/Multiport Switch' */

    /* Reshape: '<S22>/Reshape' */
    for (i_n = 0; i_n < 8; i_n++) {
      rtb_VariantMergeForOutportactua[i_n] = rtb_MultiportSwitch_i[i_n];
      rtb_VariantMergeForOutportactua[i_n + 8] = 0U;
    }

    /* End of Reshape: '<S22>/Reshape' */
  }

#elif AIRFRAME == 5

  /* Output and update for atomic system: '<S4>/Hexacopter_+' */
  {
    uint16_T rtb_throttle_cmd_k;
    uint16_T rtb_MultiportSwitch_h[6];
    int32_T i_i;
    real32_T tmp_i;
    real32_T tmp_o;
    real32_T tmp_d;
    real32_T u0_i;
    uint16_T u0_o;

    /* MultiPortSwitch: '<S28>/Multiport Switch' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    switch (Controller_U.FMS_Out.status) {
     case 1:
      for (i_i = 0; i_i < 6; i_i++) {
        rtb_MultiportSwitch_h[i_i] = 1000U;
      }
      break;

     case 2:
      for (i_i = 0; i_i < 6; i_i++) {
        rtb_MultiportSwitch_h[i_i] = 1150U;
      }
      break;

     case 3:
      /* Switch: '<S27>/Switch' incorporates:
       *  Constant: '<S31>/Constant'
       *  Logic: '<S27>/Logical Operator'
       *  RelationalOperator: '<S30>/Compare'
       *  RelationalOperator: '<S31>/Compare'
       *  Saturate: '<S9>/Saturation2'
       *  Switch: '<S27>/Switch1'
       */
      if ((Controller_U.FMS_Out.ctrl_mode == 1) ||
          (Controller_U.FMS_Out.ctrl_mode == 2) ||
          (Controller_U.FMS_Out.ctrl_mode == 3)) {
        rtb_throttle_cmd_k = Controller_U.FMS_Out.throttle_cmd;
      } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
        /* Switch: '<S32>/Switch' incorporates:
         *  Constant: '<S29>/Constant1'
         *  DataTypeConversion: '<S29>/Data Type Conversion'
         *  Gain: '<S29>/Gain1'
         *  S-Function (sfix_bitop): '<S32>/cmd_throttle valid'
         *  Saturate: '<S9>/Saturation2'
         *  Sum: '<S29>/Sum1'
         *  Switch: '<S27>/Switch1'
         */
        if ((Controller_U.FMS_Out.cmd_mask & 4096) > 0) {
          rtb_throttle_cmd_k = Controller_U.FMS_Out.throttle_cmd;
        } else {
          if (rtb_Saturation_i > 1.0F) {
            /* Saturate: '<S9>/Saturation2' */
            u0_i = 1.0F;
          } else if (rtb_Saturation_i < -1.0F) {
            /* Saturate: '<S9>/Saturation2' */
            u0_i = -1.0F;
          } else {
            /* Saturate: '<S9>/Saturation2' */
            u0_i = rtb_Saturation_i;
          }

          /* Sum: '<S29>/Sum' incorporates:
           *  Constant: '<S29>/hover_throttle'
           *  Saturate: '<S9>/Saturation2'
           */
          u0_i += CONTROL_PARAM.HOVER_THRO;

          /* Saturate: '<S29>/Saturation' */
          if (u0_i > 1.0F) {
            u0_i = 1.0F;
          } else {
            if (u0_i < 0.0F) {
              u0_i = 0.0F;
            }
          }

          rtb_throttle_cmd_k = (uint16_T)((uint32_T)fmodf(floorf(1000.0F * u0_i),
            4.2949673E+9F) + 1000U);
        }

        /* End of Switch: '<S32>/Switch' */
      } else {
        if (rtb_Saturation_i > 1.0F) {
          /* Saturate: '<S9>/Saturation2' */
          u0_i = 1.0F;
        } else if (rtb_Saturation_i < -1.0F) {
          /* Saturate: '<S9>/Saturation2' */
          u0_i = -1.0F;
        } else {
          /* Saturate: '<S9>/Saturation2' */
          u0_i = rtb_Saturation_i;
        }

        /* Sum: '<S29>/Sum' incorporates:
         *  Constant: '<S29>/hover_throttle'
         *  Saturate: '<S9>/Saturation2'
         */
        u0_i += CONTROL_PARAM.HOVER_THRO;

        /* Saturate: '<S29>/Saturation' */
        if (u0_i > 1.0F) {
          u0_i = 1.0F;
        } else {
          if (u0_i < 0.0F) {
            u0_i = 0.0F;
          }
        }

        /* Switch: '<S27>/Switch1' incorporates:
         *  Constant: '<S29>/Constant1'
         *  DataTypeConversion: '<S29>/Data Type Conversion'
         *  Gain: '<S29>/Gain1'
         *  Sum: '<S29>/Sum1'
         */
        rtb_throttle_cmd_k = (uint16_T)((uint32_T)fmodf(floorf(1000.0F * u0_i),
          4.2949673E+9F) + 1000U);
      }

      /* End of Switch: '<S27>/Switch' */

      /* Saturate: '<S9>/Saturation1' */
      if (rtb_Add_g[0] > 1.0F) {
        tmp_i = 1.0F;
      } else if (rtb_Add_g[0] < -1.0F) {
        tmp_i = -1.0F;
      } else {
        tmp_i = rtb_Add_g[0];
      }

      if (rtb_Add_g[1] > 1.0F) {
        tmp_o = 1.0F;
      } else if (rtb_Add_g[1] < -1.0F) {
        tmp_o = -1.0F;
      } else {
        tmp_o = rtb_Add_g[1];
      }

      if (rtb_Add_g[2] > 1.0F) {
        tmp_d = 1.0F;
      } else if (rtb_Add_g[2] < -1.0F) {
        tmp_d = -1.0F;
      } else {
        tmp_d = rtb_Add_g[2];
      }

      /* End of Saturate: '<S9>/Saturation1' */

      /* Product: '<S9>/Multiply' */
      for (i_i = 0; i_i < 6; i_i++) {
        /* Saturate: '<S9>/Saturation' incorporates:
         *  Constant: '<S9>/Effective_Matrix'
         *  Gain: '<S9>/Gain'
         *  Sum: '<S9>/Add'
         */
        u0_i = fmodf(floorf(1000.0F *
                            (Controller_ConstP.Effective_Matrix_Value_je[i_i +
                             12] * tmp_d +
                             (Controller_ConstP.Effective_Matrix_Value_je[i_i +
                              6] * tmp_o +
                              Controller_ConstP.Effective_Matrix_Value_je[i_i] *
                              tmp_i)) + (real32_T)rtb_throttle_cmd_k), 65536.0F);
        u0_o = (uint16_T)(u0_i < 0.0F ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
                          -u0_i : (int32_T)(uint16_T)u0_i);
        if (u0_o > 1900) {
          rtb_MultiportSwitch_h[i_i] = 1900U;
        } else if (u0_o < 1100) {
          rtb_MultiportSwitch_h[i_i] = 1100U;
        } else {
          rtb_MultiportSwitch_h[i_i] = u0_o;
        }

        /* End of Saturate: '<S9>/Saturation' */
      }

      /* End of Product: '<S9>/Multiply' */
      break;

     default:
      for (i_i = 0; i_i < 6; i_i++) {
        rtb_MultiportSwitch_h[i_i] = 1000U;
      }
      break;
    }

    /* End of MultiPortSwitch: '<S28>/Multiport Switch' */

    /* Reshape: '<S28>/Reshape' */
    for (i_i = 0; i_i < 6; i_i++) {
      rtb_VariantMergeForOutportactua[i_i] = rtb_MultiportSwitch_h[i_i];
    }

    for (i_i = 0; i_i < 10; i_i++) {
      rtb_VariantMergeForOutportactua[i_i + 6] = 0U;
    }

    /* End of Reshape: '<S28>/Reshape' */
  }

#elif AIRFRAME == 4

  /* Output and update for atomic system: '<S4>/Hexacopter_x' */
  {
    uint16_T rtb_throttle_cmd_d;
    uint16_T rtb_MultiportSwitch_k[6];
    int32_T i_j;
    real32_T tmp_j;
    real32_T tmp_e;
    real32_T tmp_g;
    real32_T u0_j;
    uint16_T u0_e;

    /* MultiPortSwitch: '<S34>/Multiport Switch' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    switch (Controller_U.FMS_Out.status) {
     case 1:
      for (i_j = 0; i_j < 6; i_j++) {
        rtb_MultiportSwitch_k[i_j] = 1000U;
      }
      break;

     case 2:
      for (i_j = 0; i_j < 6; i_j++) {
        rtb_MultiportSwitch_k[i_j] = 1150U;
      }
      break;

     case 3:
      /* Switch: '<S33>/Switch' incorporates:
       *  Constant: '<S37>/Constant'
       *  Logic: '<S33>/Logical Operator'
       *  RelationalOperator: '<S36>/Compare'
       *  RelationalOperator: '<S37>/Compare'
       *  Saturate: '<S10>/Saturation2'
       *  Switch: '<S33>/Switch1'
       */
      if ((Controller_U.FMS_Out.ctrl_mode == 1) ||
          (Controller_U.FMS_Out.ctrl_mode == 2) ||
          (Controller_U.FMS_Out.ctrl_mode == 3)) {
        rtb_throttle_cmd_d = Controller_U.FMS_Out.throttle_cmd;
      } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
        /* Switch: '<S38>/Switch' incorporates:
         *  Constant: '<S35>/Constant1'
         *  DataTypeConversion: '<S35>/Data Type Conversion'
         *  Gain: '<S35>/Gain1'
         *  S-Function (sfix_bitop): '<S38>/cmd_throttle valid'
         *  Saturate: '<S10>/Saturation2'
         *  Sum: '<S35>/Sum1'
         *  Switch: '<S33>/Switch1'
         */
        if ((Controller_U.FMS_Out.cmd_mask & 4096) > 0) {
          rtb_throttle_cmd_d = Controller_U.FMS_Out.throttle_cmd;
        } else {
          if (rtb_Saturation_i > 1.0F) {
            /* Saturate: '<S10>/Saturation2' */
            u0_j = 1.0F;
          } else if (rtb_Saturation_i < -1.0F) {
            /* Saturate: '<S10>/Saturation2' */
            u0_j = -1.0F;
          } else {
            /* Saturate: '<S10>/Saturation2' */
            u0_j = rtb_Saturation_i;
          }

          /* Sum: '<S35>/Sum' incorporates:
           *  Constant: '<S35>/hover_throttle'
           *  Saturate: '<S10>/Saturation2'
           */
          u0_j += CONTROL_PARAM.HOVER_THRO;

          /* Saturate: '<S35>/Saturation' */
          if (u0_j > 1.0F) {
            u0_j = 1.0F;
          } else {
            if (u0_j < 0.0F) {
              u0_j = 0.0F;
            }
          }

          rtb_throttle_cmd_d = (uint16_T)((uint32_T)fmodf(floorf(1000.0F * u0_j),
            4.2949673E+9F) + 1000U);
        }

        /* End of Switch: '<S38>/Switch' */
      } else {
        if (rtb_Saturation_i > 1.0F) {
          /* Saturate: '<S10>/Saturation2' */
          u0_j = 1.0F;
        } else if (rtb_Saturation_i < -1.0F) {
          /* Saturate: '<S10>/Saturation2' */
          u0_j = -1.0F;
        } else {
          /* Saturate: '<S10>/Saturation2' */
          u0_j = rtb_Saturation_i;
        }

        /* Sum: '<S35>/Sum' incorporates:
         *  Constant: '<S35>/hover_throttle'
         *  Saturate: '<S10>/Saturation2'
         */
        u0_j += CONTROL_PARAM.HOVER_THRO;

        /* Saturate: '<S35>/Saturation' */
        if (u0_j > 1.0F) {
          u0_j = 1.0F;
        } else {
          if (u0_j < 0.0F) {
            u0_j = 0.0F;
          }
        }

        /* Switch: '<S33>/Switch1' incorporates:
         *  Constant: '<S35>/Constant1'
         *  DataTypeConversion: '<S35>/Data Type Conversion'
         *  Gain: '<S35>/Gain1'
         *  Sum: '<S35>/Sum1'
         */
        rtb_throttle_cmd_d = (uint16_T)((uint32_T)fmodf(floorf(1000.0F * u0_j),
          4.2949673E+9F) + 1000U);
      }

      /* End of Switch: '<S33>/Switch' */

      /* Saturate: '<S10>/Saturation1' */
      if (rtb_Add_g[0] > 1.0F) {
        tmp_j = 1.0F;
      } else if (rtb_Add_g[0] < -1.0F) {
        tmp_j = -1.0F;
      } else {
        tmp_j = rtb_Add_g[0];
      }

      if (rtb_Add_g[1] > 1.0F) {
        tmp_e = 1.0F;
      } else if (rtb_Add_g[1] < -1.0F) {
        tmp_e = -1.0F;
      } else {
        tmp_e = rtb_Add_g[1];
      }

      if (rtb_Add_g[2] > 1.0F) {
        tmp_g = 1.0F;
      } else if (rtb_Add_g[2] < -1.0F) {
        tmp_g = -1.0F;
      } else {
        tmp_g = rtb_Add_g[2];
      }

      /* End of Saturate: '<S10>/Saturation1' */

      /* Product: '<S10>/Multiply' */
      for (i_j = 0; i_j < 6; i_j++) {
        /* Saturate: '<S10>/Saturation' incorporates:
         *  Constant: '<S10>/Effective_Matrix'
         *  Gain: '<S10>/Gain'
         *  Sum: '<S10>/Add'
         */
        u0_j = fmodf(floorf(1000.0F *
                            (Controller_ConstP.Effective_Matrix_Value_f[i_j + 12]
                             * tmp_g +
                             (Controller_ConstP.Effective_Matrix_Value_f[i_j + 6]
                              * tmp_e +
                              Controller_ConstP.Effective_Matrix_Value_f[i_j] *
                              tmp_j)) + (real32_T)rtb_throttle_cmd_d), 65536.0F);
        u0_e = (uint16_T)(u0_j < 0.0F ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
                          -u0_j : (int32_T)(uint16_T)u0_j);
        if (u0_e > 1900) {
          rtb_MultiportSwitch_k[i_j] = 1900U;
        } else if (u0_e < 1100) {
          rtb_MultiportSwitch_k[i_j] = 1100U;
        } else {
          rtb_MultiportSwitch_k[i_j] = u0_e;
        }

        /* End of Saturate: '<S10>/Saturation' */
      }

      /* End of Product: '<S10>/Multiply' */
      break;

     default:
      for (i_j = 0; i_j < 6; i_j++) {
        rtb_MultiportSwitch_k[i_j] = 1000U;
      }
      break;
    }

    /* End of MultiPortSwitch: '<S34>/Multiport Switch' */

    /* Reshape: '<S34>/Reshape' */
    for (i_j = 0; i_j < 6; i_j++) {
      rtb_VariantMergeForOutportactua[i_j] = rtb_MultiportSwitch_k[i_j];
    }

    for (i_j = 0; i_j < 10; i_j++) {
      rtb_VariantMergeForOutportactua[i_j + 6] = 0U;
    }

    /* End of Reshape: '<S34>/Reshape' */
  }

#elif AIRFRAME == 8

  /* Output and update for atomic system: '<S4>/Octocopter_+' */
  {
    uint16_T rtb_throttle_cmd_m;
    uint16_T rtb_MultiportSwitch_d[8];
    int32_T i_i;
    real32_T tmp_i;
    real32_T tmp_d;
    real32_T tmp_j;
    real32_T u0_i;
    uint16_T u0_d;

    /* MultiPortSwitch: '<S40>/Multiport Switch' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    switch (Controller_U.FMS_Out.status) {
     case 1:
      for (i_i = 0; i_i < 8; i_i++) {
        rtb_MultiportSwitch_d[i_i] = 1000U;
      }
      break;

     case 2:
      for (i_i = 0; i_i < 8; i_i++) {
        rtb_MultiportSwitch_d[i_i] = 1150U;
      }
      break;

     case 3:
      /* Switch: '<S39>/Switch' incorporates:
       *  Constant: '<S43>/Constant'
       *  Logic: '<S39>/Logical Operator'
       *  RelationalOperator: '<S42>/Compare'
       *  RelationalOperator: '<S43>/Compare'
       *  Saturate: '<S11>/Saturation2'
       *  Switch: '<S39>/Switch1'
       */
      if ((Controller_U.FMS_Out.ctrl_mode == 1) ||
          (Controller_U.FMS_Out.ctrl_mode == 2) ||
          (Controller_U.FMS_Out.ctrl_mode == 3)) {
        rtb_throttle_cmd_m = Controller_U.FMS_Out.throttle_cmd;
      } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
        /* Switch: '<S44>/Switch' incorporates:
         *  Constant: '<S41>/Constant1'
         *  DataTypeConversion: '<S41>/Data Type Conversion'
         *  Gain: '<S41>/Gain1'
         *  S-Function (sfix_bitop): '<S44>/cmd_throttle valid'
         *  Saturate: '<S11>/Saturation2'
         *  Sum: '<S41>/Sum1'
         *  Switch: '<S39>/Switch1'
         */
        if ((Controller_U.FMS_Out.cmd_mask & 4096) > 0) {
          rtb_throttle_cmd_m = Controller_U.FMS_Out.throttle_cmd;
        } else {
          if (rtb_Saturation_i > 1.0F) {
            /* Saturate: '<S11>/Saturation2' */
            u0_i = 1.0F;
          } else if (rtb_Saturation_i < -1.0F) {
            /* Saturate: '<S11>/Saturation2' */
            u0_i = -1.0F;
          } else {
            /* Saturate: '<S11>/Saturation2' */
            u0_i = rtb_Saturation_i;
          }

          /* Sum: '<S41>/Sum' incorporates:
           *  Constant: '<S41>/hover_throttle'
           *  Saturate: '<S11>/Saturation2'
           */
          u0_i += CONTROL_PARAM.HOVER_THRO;

          /* Saturate: '<S41>/Saturation' */
          if (u0_i > 1.0F) {
            u0_i = 1.0F;
          } else {
            if (u0_i < 0.0F) {
              u0_i = 0.0F;
            }
          }

          rtb_throttle_cmd_m = (uint16_T)((uint32_T)fmodf(floorf(1000.0F * u0_i),
            4.2949673E+9F) + 1000U);
        }

        /* End of Switch: '<S44>/Switch' */
      } else {
        if (rtb_Saturation_i > 1.0F) {
          /* Saturate: '<S11>/Saturation2' */
          u0_i = 1.0F;
        } else if (rtb_Saturation_i < -1.0F) {
          /* Saturate: '<S11>/Saturation2' */
          u0_i = -1.0F;
        } else {
          /* Saturate: '<S11>/Saturation2' */
          u0_i = rtb_Saturation_i;
        }

        /* Sum: '<S41>/Sum' incorporates:
         *  Constant: '<S41>/hover_throttle'
         *  Saturate: '<S11>/Saturation2'
         */
        u0_i += CONTROL_PARAM.HOVER_THRO;

        /* Saturate: '<S41>/Saturation' */
        if (u0_i > 1.0F) {
          u0_i = 1.0F;
        } else {
          if (u0_i < 0.0F) {
            u0_i = 0.0F;
          }
        }

        /* Switch: '<S39>/Switch1' incorporates:
         *  Constant: '<S41>/Constant1'
         *  DataTypeConversion: '<S41>/Data Type Conversion'
         *  Gain: '<S41>/Gain1'
         *  Sum: '<S41>/Sum1'
         */
        rtb_throttle_cmd_m = (uint16_T)((uint32_T)fmodf(floorf(1000.0F * u0_i),
          4.2949673E+9F) + 1000U);
      }

      /* End of Switch: '<S39>/Switch' */

      /* Saturate: '<S11>/Saturation1' */
      if (rtb_Add_g[0] > 1.0F) {
        tmp_i = 1.0F;
      } else if (rtb_Add_g[0] < -1.0F) {
        tmp_i = -1.0F;
      } else {
        tmp_i = rtb_Add_g[0];
      }

      if (rtb_Add_g[1] > 1.0F) {
        tmp_d = 1.0F;
      } else if (rtb_Add_g[1] < -1.0F) {
        tmp_d = -1.0F;
      } else {
        tmp_d = rtb_Add_g[1];
      }

      if (rtb_Add_g[2] > 1.0F) {
        tmp_j = 1.0F;
      } else if (rtb_Add_g[2] < -1.0F) {
        tmp_j = -1.0F;
      } else {
        tmp_j = rtb_Add_g[2];
      }

      /* End of Saturate: '<S11>/Saturation1' */

      /* Product: '<S11>/Multiply' */
      for (i_i = 0; i_i < 8; i_i++) {
        /* Saturate: '<S11>/Saturation' incorporates:
         *  Constant: '<S11>/Effective_Matrix'
         *  Gain: '<S11>/Gain'
         *  Sum: '<S11>/Add'
         */
        u0_i = fmodf(floorf(1000.0F *
                            (Controller_ConstP.Effective_Matrix_Value_m[i_i + 16]
                             * tmp_j +
                             (Controller_ConstP.Effective_Matrix_Value_m[i_i + 8]
                              * tmp_d +
                              Controller_ConstP.Effective_Matrix_Value_m[i_i] *
                              tmp_i)) + (real32_T)rtb_throttle_cmd_m), 65536.0F);
        u0_d = (uint16_T)(u0_i < 0.0F ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
                          -u0_i : (int32_T)(uint16_T)u0_i);
        if (u0_d > 1900) {
          rtb_MultiportSwitch_d[i_i] = 1900U;
        } else if (u0_d < 1100) {
          rtb_MultiportSwitch_d[i_i] = 1100U;
        } else {
          rtb_MultiportSwitch_d[i_i] = u0_d;
        }

        /* End of Saturate: '<S11>/Saturation' */
      }

      /* End of Product: '<S11>/Multiply' */
      break;

     default:
      for (i_i = 0; i_i < 8; i_i++) {
        rtb_MultiportSwitch_d[i_i] = 1000U;
      }
      break;
    }

    /* End of MultiPortSwitch: '<S40>/Multiport Switch' */

    /* Reshape: '<S40>/Reshape' */
    for (i_i = 0; i_i < 8; i_i++) {
      rtb_VariantMergeForOutportactua[i_i] = rtb_MultiportSwitch_d[i_i];
      rtb_VariantMergeForOutportactua[i_i + 8] = 0U;
    }

    /* End of Reshape: '<S40>/Reshape' */
  }

#elif AIRFRAME == 7

  /* Output and update for atomic system: '<S4>/Octocopter_x' */
  {
    uint16_T rtb_throttle_cmd_n;
    uint16_T rtb_MultiportSwitch_hv[8];
    int32_T i_l;
    real32_T tmp_l;
    real32_T tmp_m;
    real32_T tmp_c;
    real32_T u0_l;
    uint16_T u0_m;

    /* MultiPortSwitch: '<S46>/Multiport Switch' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    switch (Controller_U.FMS_Out.status) {
     case 1:
      for (i_l = 0; i_l < 8; i_l++) {
        rtb_MultiportSwitch_hv[i_l] = 1000U;
      }
      break;

     case 2:
      for (i_l = 0; i_l < 8; i_l++) {
        rtb_MultiportSwitch_hv[i_l] = 1150U;
      }
      break;

     case 3:
      /* Switch: '<S45>/Switch' incorporates:
       *  Constant: '<S49>/Constant'
       *  Logic: '<S45>/Logical Operator'
       *  RelationalOperator: '<S48>/Compare'
       *  RelationalOperator: '<S49>/Compare'
       *  Saturate: '<S12>/Saturation2'
       *  Switch: '<S45>/Switch1'
       */
      if ((Controller_U.FMS_Out.ctrl_mode == 1) ||
          (Controller_U.FMS_Out.ctrl_mode == 2) ||
          (Controller_U.FMS_Out.ctrl_mode == 3)) {
        rtb_throttle_cmd_n = Controller_U.FMS_Out.throttle_cmd;
      } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
        /* Switch: '<S50>/Switch' incorporates:
         *  Constant: '<S47>/Constant1'
         *  DataTypeConversion: '<S47>/Data Type Conversion'
         *  Gain: '<S47>/Gain1'
         *  S-Function (sfix_bitop): '<S50>/cmd_throttle valid'
         *  Saturate: '<S12>/Saturation2'
         *  Sum: '<S47>/Sum1'
         *  Switch: '<S45>/Switch1'
         */
        if ((Controller_U.FMS_Out.cmd_mask & 4096) > 0) {
          rtb_throttle_cmd_n = Controller_U.FMS_Out.throttle_cmd;
        } else {
          if (rtb_Saturation_i > 1.0F) {
            /* Saturate: '<S12>/Saturation2' */
            u0_l = 1.0F;
          } else if (rtb_Saturation_i < -1.0F) {
            /* Saturate: '<S12>/Saturation2' */
            u0_l = -1.0F;
          } else {
            /* Saturate: '<S12>/Saturation2' */
            u0_l = rtb_Saturation_i;
          }

          /* Sum: '<S47>/Sum' incorporates:
           *  Constant: '<S47>/hover_throttle'
           *  Saturate: '<S12>/Saturation2'
           */
          u0_l += CONTROL_PARAM.HOVER_THRO;

          /* Saturate: '<S47>/Saturation' */
          if (u0_l > 1.0F) {
            u0_l = 1.0F;
          } else {
            if (u0_l < 0.0F) {
              u0_l = 0.0F;
            }
          }

          rtb_throttle_cmd_n = (uint16_T)((uint32_T)fmodf(floorf(1000.0F * u0_l),
            4.2949673E+9F) + 1000U);
        }

        /* End of Switch: '<S50>/Switch' */
      } else {
        if (rtb_Saturation_i > 1.0F) {
          /* Saturate: '<S12>/Saturation2' */
          u0_l = 1.0F;
        } else if (rtb_Saturation_i < -1.0F) {
          /* Saturate: '<S12>/Saturation2' */
          u0_l = -1.0F;
        } else {
          /* Saturate: '<S12>/Saturation2' */
          u0_l = rtb_Saturation_i;
        }

        /* Sum: '<S47>/Sum' incorporates:
         *  Constant: '<S47>/hover_throttle'
         *  Saturate: '<S12>/Saturation2'
         */
        u0_l += CONTROL_PARAM.HOVER_THRO;

        /* Saturate: '<S47>/Saturation' */
        if (u0_l > 1.0F) {
          u0_l = 1.0F;
        } else {
          if (u0_l < 0.0F) {
            u0_l = 0.0F;
          }
        }

        /* Switch: '<S45>/Switch1' incorporates:
         *  Constant: '<S47>/Constant1'
         *  DataTypeConversion: '<S47>/Data Type Conversion'
         *  Gain: '<S47>/Gain1'
         *  Sum: '<S47>/Sum1'
         */
        rtb_throttle_cmd_n = (uint16_T)((uint32_T)fmodf(floorf(1000.0F * u0_l),
          4.2949673E+9F) + 1000U);
      }

      /* End of Switch: '<S45>/Switch' */

      /* Saturate: '<S12>/Saturation1' */
      if (rtb_Add_g[0] > 1.0F) {
        tmp_l = 1.0F;
      } else if (rtb_Add_g[0] < -1.0F) {
        tmp_l = -1.0F;
      } else {
        tmp_l = rtb_Add_g[0];
      }

      if (rtb_Add_g[1] > 1.0F) {
        tmp_m = 1.0F;
      } else if (rtb_Add_g[1] < -1.0F) {
        tmp_m = -1.0F;
      } else {
        tmp_m = rtb_Add_g[1];
      }

      if (rtb_Add_g[2] > 1.0F) {
        tmp_c = 1.0F;
      } else if (rtb_Add_g[2] < -1.0F) {
        tmp_c = -1.0F;
      } else {
        tmp_c = rtb_Add_g[2];
      }

      /* End of Saturate: '<S12>/Saturation1' */

      /* Product: '<S12>/Multiply' */
      for (i_l = 0; i_l < 8; i_l++) {
        /* Saturate: '<S12>/Saturation' incorporates:
         *  Constant: '<S12>/Effective_Matrix'
         *  Gain: '<S12>/Gain'
         *  Sum: '<S12>/Add'
         */
        u0_l = fmodf(floorf(1000.0F *
                            (Controller_ConstP.Effective_Matrix_Value_k[i_l + 16]
                             * tmp_c +
                             (Controller_ConstP.Effective_Matrix_Value_k[i_l + 8]
                              * tmp_m +
                              Controller_ConstP.Effective_Matrix_Value_k[i_l] *
                              tmp_l)) + (real32_T)rtb_throttle_cmd_n), 65536.0F);
        u0_m = (uint16_T)(u0_l < 0.0F ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
                          -u0_l : (int32_T)(uint16_T)u0_l);
        if (u0_m > 1900) {
          rtb_MultiportSwitch_hv[i_l] = 1900U;
        } else if (u0_m < 1100) {
          rtb_MultiportSwitch_hv[i_l] = 1100U;
        } else {
          rtb_MultiportSwitch_hv[i_l] = u0_m;
        }

        /* End of Saturate: '<S12>/Saturation' */
      }

      /* End of Product: '<S12>/Multiply' */
      break;

     default:
      for (i_l = 0; i_l < 8; i_l++) {
        rtb_MultiportSwitch_hv[i_l] = 1000U;
      }
      break;
    }

    /* End of MultiPortSwitch: '<S46>/Multiport Switch' */

    /* Reshape: '<S46>/Reshape' */
    for (i_l = 0; i_l < 8; i_l++) {
      rtb_VariantMergeForOutportactua[i_l] = rtb_MultiportSwitch_hv[i_l];
      rtb_VariantMergeForOutportactua[i_l + 8] = 0U;
    }

    /* End of Reshape: '<S46>/Reshape' */
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

    /* MultiPortSwitch: '<S52>/Multiport Switch' incorporates:
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
      /* Switch: '<S51>/Switch' incorporates:
       *  Constant: '<S55>/Constant'
       *  Logic: '<S51>/Logical Operator'
       *  RelationalOperator: '<S54>/Compare'
       *  RelationalOperator: '<S55>/Compare'
       *  Saturate: '<S13>/Saturation2'
       *  Switch: '<S51>/Switch1'
       */
      if ((Controller_U.FMS_Out.ctrl_mode == 1) ||
          (Controller_U.FMS_Out.ctrl_mode == 2) ||
          (Controller_U.FMS_Out.ctrl_mode == 3)) {
        rtb_throttle_cmd_o = Controller_U.FMS_Out.throttle_cmd;
      } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
        /* Switch: '<S56>/Switch' incorporates:
         *  Constant: '<S53>/Constant1'
         *  DataTypeConversion: '<S53>/Data Type Conversion'
         *  Gain: '<S53>/Gain1'
         *  S-Function (sfix_bitop): '<S56>/cmd_throttle valid'
         *  Saturate: '<S13>/Saturation2'
         *  Sum: '<S53>/Sum1'
         *  Switch: '<S51>/Switch1'
         */
        if ((Controller_U.FMS_Out.cmd_mask & 4096) > 0) {
          rtb_throttle_cmd_o = Controller_U.FMS_Out.throttle_cmd;
        } else {
          if (rtb_Saturation_i > 1.0F) {
            /* Saturate: '<S13>/Saturation2' */
            u0_m = 1.0F;
          } else if (rtb_Saturation_i < -1.0F) {
            /* Saturate: '<S13>/Saturation2' */
            u0_m = -1.0F;
          } else {
            /* Saturate: '<S13>/Saturation2' */
            u0_m = rtb_Saturation_i;
          }

          /* Sum: '<S53>/Sum' incorporates:
           *  Constant: '<S53>/hover_throttle'
           *  Saturate: '<S13>/Saturation2'
           */
          u0_m += CONTROL_PARAM.HOVER_THRO;

          /* Saturate: '<S53>/Saturation' */
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

        /* End of Switch: '<S56>/Switch' */
      } else {
        if (rtb_Saturation_i > 1.0F) {
          /* Saturate: '<S13>/Saturation2' */
          u0_m = 1.0F;
        } else if (rtb_Saturation_i < -1.0F) {
          /* Saturate: '<S13>/Saturation2' */
          u0_m = -1.0F;
        } else {
          /* Saturate: '<S13>/Saturation2' */
          u0_m = rtb_Saturation_i;
        }

        /* Sum: '<S53>/Sum' incorporates:
         *  Constant: '<S53>/hover_throttle'
         *  Saturate: '<S13>/Saturation2'
         */
        u0_m += CONTROL_PARAM.HOVER_THRO;

        /* Saturate: '<S53>/Saturation' */
        if (u0_m > 1.0F) {
          u0_m = 1.0F;
        } else {
          if (u0_m < 0.0F) {
            u0_m = 0.0F;
          }
        }

        /* Switch: '<S51>/Switch1' incorporates:
         *  Constant: '<S53>/Constant1'
         *  DataTypeConversion: '<S53>/Data Type Conversion'
         *  Gain: '<S53>/Gain1'
         *  Sum: '<S53>/Sum1'
         */
        rtb_throttle_cmd_o = (uint16_T)((uint32_T)fmodf(floorf(1000.0F * u0_m),
          4.2949673E+9F) + 1000U);
      }

      /* End of Switch: '<S51>/Switch' */

      /* Saturate: '<S13>/Saturation1' */
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

      /* End of Saturate: '<S13>/Saturation1' */

      /* Product: '<S13>/Multiply' */
      for (i_m = 0; i_m < 4; i_m++) {
        /* Saturate: '<S13>/Saturation' incorporates:
         *  Constant: '<S13>/Effective_Matrix'
         *  Gain: '<S13>/Gain'
         *  Sum: '<S13>/Add'
         */
        u0_m = fmodf(floorf(1000.0F *
                            (Controller_ConstP.Effective_Matrix_Value_fr[i_m + 8]
                             * tmp_al +
                             (Controller_ConstP.Effective_Matrix_Value_fr[i_m +
                              4] * tmp_n +
                              Controller_ConstP.Effective_Matrix_Value_fr[i_m] *
                              tmp_m)) + (real32_T)rtb_throttle_cmd_o), 65536.0F);
        u0_n = (uint16_T)(u0_m < 0.0F ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
                          -u0_m : (int32_T)(uint16_T)u0_m);
        if (u0_n > 1900) {
          rtb_MultiportSwitch_o[i_m] = 1900U;
        } else if (u0_n < 1100) {
          rtb_MultiportSwitch_o[i_m] = 1100U;
        } else {
          rtb_MultiportSwitch_o[i_m] = u0_n;
        }

        /* End of Saturate: '<S13>/Saturation' */
      }

      /* End of Product: '<S13>/Multiply' */
      break;

     default:
      rtb_MultiportSwitch_o[0] = 1000U;
      rtb_MultiportSwitch_o[1] = 1000U;
      rtb_MultiportSwitch_o[2] = 1000U;
      rtb_MultiportSwitch_o[3] = 1000U;
      break;
    }

    /* End of MultiPortSwitch: '<S52>/Multiport Switch' */

    /* Reshape: '<S52>/Reshape' */
    rtb_VariantMergeForOutportactua[0] = rtb_MultiportSwitch_o[0];
    rtb_VariantMergeForOutportactua[1] = rtb_MultiportSwitch_o[1];
    rtb_VariantMergeForOutportactua[2] = rtb_MultiportSwitch_o[2];
    rtb_VariantMergeForOutportactua[3] = rtb_MultiportSwitch_o[3];
    for (i_m = 0; i_m < 12; i_m++) {
      rtb_VariantMergeForOutportactua[i_m + 4] = 0U;
    }

    /* End of Reshape: '<S52>/Reshape' */
  }

#elif AIRFRAME == 1

  /* Output and update for atomic system: '<S4>/Quadcopter_x' */
  {
    uint16_T rtb_throttle_cmd_c;
    uint16_T rtb_MultiportSwitch_is[4];
    int32_T i_e;
    real32_T tmp_e;
    real32_T tmp_o;
    real32_T tmp_h;
    real32_T u0_e;
    uint16_T u0_o;

    /* MultiPortSwitch: '<S58>/Multiport Switch' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    switch (Controller_U.FMS_Out.status) {
     case 1:
      rtb_MultiportSwitch_is[0] = 1000U;
      rtb_MultiportSwitch_is[1] = 1000U;
      rtb_MultiportSwitch_is[2] = 1000U;
      rtb_MultiportSwitch_is[3] = 1000U;
      break;

     case 2:
      rtb_MultiportSwitch_is[0] = 1150U;
      rtb_MultiportSwitch_is[1] = 1150U;
      rtb_MultiportSwitch_is[2] = 1150U;
      rtb_MultiportSwitch_is[3] = 1150U;
      break;

     case 3:
      /* Switch: '<S57>/Switch' incorporates:
       *  Constant: '<S61>/Constant'
       *  Logic: '<S57>/Logical Operator'
       *  RelationalOperator: '<S60>/Compare'
       *  RelationalOperator: '<S61>/Compare'
       *  Saturate: '<S14>/Saturation2'
       *  Switch: '<S57>/Switch1'
       */
      if ((Controller_U.FMS_Out.ctrl_mode == 1) ||
          (Controller_U.FMS_Out.ctrl_mode == 2) ||
          (Controller_U.FMS_Out.ctrl_mode == 3)) {
        rtb_throttle_cmd_c = Controller_U.FMS_Out.throttle_cmd;
      } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
        /* Switch: '<S62>/Switch' incorporates:
         *  Constant: '<S59>/Constant1'
         *  DataTypeConversion: '<S59>/Data Type Conversion'
         *  Gain: '<S59>/Gain1'
         *  S-Function (sfix_bitop): '<S62>/cmd_throttle valid'
         *  Saturate: '<S14>/Saturation2'
         *  Sum: '<S59>/Sum1'
         *  Switch: '<S57>/Switch1'
         */
        if ((Controller_U.FMS_Out.cmd_mask & 4096) > 0) {
          rtb_throttle_cmd_c = Controller_U.FMS_Out.throttle_cmd;
        } else {
          if (rtb_Saturation_i > 1.0F) {
            /* Saturate: '<S14>/Saturation2' */
            u0_e = 1.0F;
          } else if (rtb_Saturation_i < -1.0F) {
            /* Saturate: '<S14>/Saturation2' */
            u0_e = -1.0F;
          } else {
            /* Saturate: '<S14>/Saturation2' */
            u0_e = rtb_Saturation_i;
          }

          /* Sum: '<S59>/Sum' incorporates:
           *  Constant: '<S59>/hover_throttle'
           *  Saturate: '<S14>/Saturation2'
           */
          u0_e += CONTROL_PARAM.HOVER_THRO;

          /* Saturate: '<S59>/Saturation' */
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

        /* End of Switch: '<S62>/Switch' */
      } else {
        if (rtb_Saturation_i > 1.0F) {
          /* Saturate: '<S14>/Saturation2' */
          u0_e = 1.0F;
        } else if (rtb_Saturation_i < -1.0F) {
          /* Saturate: '<S14>/Saturation2' */
          u0_e = -1.0F;
        } else {
          /* Saturate: '<S14>/Saturation2' */
          u0_e = rtb_Saturation_i;
        }

        /* Sum: '<S59>/Sum' incorporates:
         *  Constant: '<S59>/hover_throttle'
         *  Saturate: '<S14>/Saturation2'
         */
        u0_e += CONTROL_PARAM.HOVER_THRO;

        /* Saturate: '<S59>/Saturation' */
        if (u0_e > 1.0F) {
          u0_e = 1.0F;
        } else {
          if (u0_e < 0.0F) {
            u0_e = 0.0F;
          }
        }

        /* Switch: '<S57>/Switch1' incorporates:
         *  Constant: '<S59>/Constant1'
         *  DataTypeConversion: '<S59>/Data Type Conversion'
         *  Gain: '<S59>/Gain1'
         *  Sum: '<S59>/Sum1'
         */
        rtb_throttle_cmd_c = (uint16_T)((uint32_T)fmodf(floorf(1000.0F * u0_e),
          4.2949673E+9F) + 1000U);
      }

      /* End of Switch: '<S57>/Switch' */

      /* Saturate: '<S14>/Saturation1' */
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

      /* End of Saturate: '<S14>/Saturation1' */

      /* Product: '<S14>/Multiply' */
      for (i_e = 0; i_e < 4; i_e++) {
        /* Saturate: '<S14>/Saturation' incorporates:
         *  Constant: '<S14>/Effective_Matrix'
         *  Gain: '<S14>/Gain'
         *  Sum: '<S14>/Add'
         */
        u0_e = fmodf(floorf(1000.0F *
                            (Controller_ConstP.Effective_Matrix_Value_h[i_e + 8]
                             * tmp_h +
                             (Controller_ConstP.Effective_Matrix_Value_h[i_e + 4]
                              * tmp_o +
                              Controller_ConstP.Effective_Matrix_Value_h[i_e] *
                              tmp_e)) + (real32_T)rtb_throttle_cmd_c), 65536.0F);
        u0_o = (uint16_T)(u0_e < 0.0F ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
                          -u0_e : (int32_T)(uint16_T)u0_e);
        if (u0_o > 1900) {
          rtb_MultiportSwitch_is[i_e] = 1900U;
        } else if (u0_o < 1100) {
          rtb_MultiportSwitch_is[i_e] = 1100U;
        } else {
          rtb_MultiportSwitch_is[i_e] = u0_o;
        }

        /* End of Saturate: '<S14>/Saturation' */
      }

      /* End of Product: '<S14>/Multiply' */
      break;

     default:
      rtb_MultiportSwitch_is[0] = 1000U;
      rtb_MultiportSwitch_is[1] = 1000U;
      rtb_MultiportSwitch_is[2] = 1000U;
      rtb_MultiportSwitch_is[3] = 1000U;
      break;
    }

    /* End of MultiPortSwitch: '<S58>/Multiport Switch' */

    /* Reshape: '<S58>/Reshape' */
    rtb_VariantMergeForOutportactua[0] = rtb_MultiportSwitch_is[0];
    rtb_VariantMergeForOutportactua[1] = rtb_MultiportSwitch_is[1];
    rtb_VariantMergeForOutportactua[2] = rtb_MultiportSwitch_is[2];
    rtb_VariantMergeForOutportactua[3] = rtb_MultiportSwitch_is[3];
    for (i_e = 0; i_e < 12; i_e++) {
      rtb_VariantMergeForOutportactua[i_e + 4] = 0U;
    }

    /* End of Reshape: '<S58>/Reshape' */
  }

#endif

  /* End of Outputs for SubSystem: '<S2>/Control_Allocation' */

  /* Product: '<S75>/Multiply' incorporates:
   *  Constant: '<S75>/gain1'
   *  Constant: '<S75>/gain2'
   *  Constant: '<S75>/gain3'
   *  DiscreteIntegrator: '<S73>/Discrete-Time Integrator5'
   */
  rtb_Saturation_d_idx_0 = CONTROL_PARAM.ROLL_RATE_I *
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[0];
  rtb_Saturation_d_idx_1 = CONTROL_PARAM.PITCH_RATE_I *
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1];
  rtb_Saturation_d_idx_2 = CONTROL_PARAM.YAW_RATE_I *
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[2];

  /* Product: '<S100>/Multiply1' incorporates:
   *  Constant: '<S100>/const1'
   *  DiscreteIntegrator: '<S97>/Integrator'
   */
  rtb_Add3_j_idx_0 = Controller_DW.Integrator_DSTATE[0] * 0.05F;
  rtb_Add3_j_idx_1 = Controller_DW.Integrator_DSTATE[1] * 0.05F;

  /* Sum: '<S100>/Add' incorporates:
   *  DiscreteIntegrator: '<S97>/Integrator1'
   *  Inport: '<Root>/FMS_Out'
   *  Sum: '<S97>/Subtract'
   */
  rtb_Saturation_idx_0 = (Controller_DW.Integrator1_DSTATE[0] -
    Controller_U.FMS_Out.u_cmd) + rtb_Add3_j_idx_0;
  rtb_Saturation_idx_1 = (Controller_DW.Integrator1_DSTATE[1] -
    Controller_U.FMS_Out.v_cmd) + rtb_Add3_j_idx_1;

  /* Signum: '<S100>/Sign' */
  if (rtb_Saturation_idx_0 < 0.0F) {
    rtb_Add_i = -1.0F;
  } else if (rtb_Saturation_idx_0 > 0.0F) {
    rtb_Add_i = 1.0F;
  } else {
    rtb_Add_i = rtb_Saturation_idx_0;
  }

  /* Sum: '<S100>/Add2' incorporates:
   *  Abs: '<S100>/Abs'
   *  Gain: '<S100>/Gain'
   *  Gain: '<S100>/Gain1'
   *  Product: '<S100>/Multiply2'
   *  Product: '<S100>/Multiply3'
   *  Signum: '<S100>/Sign'
   *  Sqrt: '<S100>/Sqrt'
   *  Sum: '<S100>/Add1'
   *  Sum: '<S100>/Subtract'
   */
  rtb_Add_i = (sqrtf((8.0F * fabsf(rtb_Saturation_idx_0) + Controller_ConstB.d) *
                     Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
    rtb_Add_i + rtb_Add3_j_idx_0;

  /* Sum: '<S100>/Add3' incorporates:
   *  Signum: '<S100>/Sign'
   */
  rtb_Add3 = rtb_Saturation_idx_0 + Controller_ConstB.d;

  /* Sum: '<S100>/Subtract1' incorporates:
   *  Signum: '<S100>/Sign'
   */
  rtb_Subtract3_i = rtb_Saturation_idx_0 - Controller_ConstB.d;

  /* Signum: '<S100>/Sign1' */
  if (rtb_Add3 < 0.0F) {
    rtb_Add3 = -1.0F;
  } else {
    if (rtb_Add3 > 0.0F) {
      rtb_Add3 = 1.0F;
    }
  }

  /* Signum: '<S100>/Sign2' */
  if (rtb_Subtract3_i < 0.0F) {
    rtb_Subtract3_i = -1.0F;
  } else {
    if (rtb_Subtract3_i > 0.0F) {
      rtb_Subtract3_i = 1.0F;
    }
  }

  /* Sum: '<S100>/Add2' incorporates:
   *  Gain: '<S100>/Gain2'
   *  Product: '<S100>/Multiply4'
   *  Signum: '<S100>/Sign'
   *  Sum: '<S100>/Add4'
   *  Sum: '<S100>/Add5'
   *  Sum: '<S100>/Subtract2'
   */
  rtb_Add3_j_idx_0 = ((rtb_Saturation_idx_0 - rtb_Add_i) + rtb_Add3_j_idx_0) *
    ((rtb_Add3 - rtb_Subtract3_i) * 0.5F) + rtb_Add_i;

  /* Signum: '<S100>/Sign' */
  if (rtb_Saturation_idx_1 < 0.0F) {
    rtb_Add_i = -1.0F;
  } else if (rtb_Saturation_idx_1 > 0.0F) {
    rtb_Add_i = 1.0F;
  } else {
    rtb_Add_i = rtb_Saturation_idx_1;
  }

  /* Sum: '<S100>/Add2' incorporates:
   *  Abs: '<S100>/Abs'
   *  Gain: '<S100>/Gain'
   *  Gain: '<S100>/Gain1'
   *  Product: '<S100>/Multiply2'
   *  Product: '<S100>/Multiply3'
   *  Signum: '<S100>/Sign'
   *  Sqrt: '<S100>/Sqrt'
   *  Sum: '<S100>/Add1'
   *  Sum: '<S100>/Subtract'
   */
  rtb_Add_i = (sqrtf((8.0F * fabsf(rtb_Saturation_idx_1) + Controller_ConstB.d) *
                     Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
    rtb_Add_i + rtb_Add3_j_idx_1;

  /* Sum: '<S100>/Add3' incorporates:
   *  Signum: '<S100>/Sign'
   */
  rtb_Add3 = rtb_Saturation_idx_1 + Controller_ConstB.d;

  /* Sum: '<S100>/Subtract1' incorporates:
   *  Signum: '<S100>/Sign'
   */
  rtb_Subtract3_i = rtb_Saturation_idx_1 - Controller_ConstB.d;

  /* Signum: '<S100>/Sign1' */
  if (rtb_Add3 < 0.0F) {
    rtb_Add3 = -1.0F;
  } else {
    if (rtb_Add3 > 0.0F) {
      rtb_Add3 = 1.0F;
    }
  }

  /* Signum: '<S100>/Sign2' */
  if (rtb_Subtract3_i < 0.0F) {
    rtb_Subtract3_i = -1.0F;
  } else {
    if (rtb_Subtract3_i > 0.0F) {
      rtb_Subtract3_i = 1.0F;
    }
  }

  /* Sum: '<S100>/Add5' incorporates:
   *  Gain: '<S100>/Gain2'
   *  Product: '<S100>/Multiply4'
   *  Signum: '<S100>/Sign'
   *  Sum: '<S100>/Add2'
   *  Sum: '<S100>/Add4'
   *  Sum: '<S100>/Subtract2'
   */
  rtb_Add_i += ((rtb_Saturation_idx_1 - rtb_Add_i) + rtb_Add3_j_idx_1) *
    ((rtb_Add3 - rtb_Subtract3_i) * 0.5F);

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

  /* Product: '<S114>/Multiply1' incorporates:
   *  Constant: '<S114>/const1'
   *  DiscreteIntegrator: '<S113>/Integrator'
   */
  rtb_Add3 = Controller_DW.Integrator_DSTATE_p * 0.05F;

  /* Sum: '<S114>/Add' incorporates:
   *  DiscreteIntegrator: '<S113>/Integrator1'
   *  Inport: '<Root>/FMS_Out'
   *  Sum: '<S113>/Subtract'
   */
  rtb_Subtract3_i = (Controller_DW.Integrator1_DSTATE_p -
                     Controller_U.FMS_Out.w_cmd) + rtb_Add3;

  /* Signum: '<S114>/Sign' */
  if (rtb_Subtract3_i < 0.0F) {
    rtb_Add3_j_idx_1 = -1.0F;
  } else if (rtb_Subtract3_i > 0.0F) {
    rtb_Add3_j_idx_1 = 1.0F;
  } else {
    rtb_Add3_j_idx_1 = rtb_Subtract3_i;
  }

  /* End of Signum: '<S114>/Sign' */

  /* Sum: '<S114>/Add2' incorporates:
   *  Abs: '<S114>/Abs'
   *  Gain: '<S114>/Gain'
   *  Gain: '<S114>/Gain1'
   *  Product: '<S114>/Multiply2'
   *  Product: '<S114>/Multiply3'
   *  Sqrt: '<S114>/Sqrt'
   *  Sum: '<S114>/Add1'
   *  Sum: '<S114>/Subtract'
   */
  rtb_Add3_j_idx_1 = (sqrtf((8.0F * fabsf(rtb_Subtract3_i) +
    Controller_ConstB.d_n) * Controller_ConstB.d_n) - Controller_ConstB.d_n) *
    0.5F * rtb_Add3_j_idx_1 + rtb_Add3;

  /* Sum: '<S114>/Add4' */
  rtb_Saturation_idx_1 = (rtb_Subtract3_i - rtb_Add3_j_idx_1) + rtb_Add3;

  /* Sum: '<S114>/Add3' */
  rtb_Add3 = rtb_Subtract3_i + Controller_ConstB.d_n;

  /* Sum: '<S114>/Subtract1' */
  rtb_Subtract3_i -= Controller_ConstB.d_n;

  /* Signum: '<S114>/Sign1' */
  if (rtb_Add3 < 0.0F) {
    rtb_Add3 = -1.0F;
  } else {
    if (rtb_Add3 > 0.0F) {
      rtb_Add3 = 1.0F;
    }
  }

  /* End of Signum: '<S114>/Sign1' */

  /* Signum: '<S114>/Sign2' */
  if (rtb_Subtract3_i < 0.0F) {
    rtb_Subtract3_i = -1.0F;
  } else {
    if (rtb_Subtract3_i > 0.0F) {
      rtb_Subtract3_i = 1.0F;
    }
  }

  /* End of Signum: '<S114>/Sign2' */

  /* Sum: '<S114>/Add5' incorporates:
   *  Gain: '<S114>/Gain2'
   *  Product: '<S114>/Multiply4'
   *  Sum: '<S114>/Subtract2'
   */
  rtb_Add3_j_idx_1 += (rtb_Add3 - rtb_Subtract3_i) * 0.5F * rtb_Saturation_idx_1;

  /* Update for DiscreteIntegrator: '<S102>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S104>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;

  /* Update for DiscreteIntegrator: '<S97>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S97>/Integrator'
   */
  Controller_DW.Integrator1_DSTATE[0] += 0.002F *
    Controller_DW.Integrator_DSTATE[0];

  /* Update for DiscreteIntegrator: '<S102>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S102>/ki'
   *  Product: '<S102>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE[0] += CONTROL_PARAM.VEL_XY_I *
    rtb_uv_error_C_mPs_idx_0 * 0.002F;
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

  /* Update for DiscreteIntegrator: '<S104>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] += 0.002F * rtb_Gain_idx_0;

  /* Update for DiscreteIntegrator: '<S97>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S97>/Integrator'
   */
  Controller_DW.Integrator1_DSTATE[1] += 0.002F *
    Controller_DW.Integrator_DSTATE[1];

  /* Update for DiscreteIntegrator: '<S102>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S102>/ki'
   *  Product: '<S102>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE[1] += CONTROL_PARAM.VEL_XY_I *
    rtb_uv_error_C_mPs_idx_1 * 0.002F;
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

  /* Update for DiscreteIntegrator: '<S104>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] += 0.002F * rtb_Gain_idx_1;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S73>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;

  /* Update for DiscreteIntegrator: '<S75>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator_PrevRe_g = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S77>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_l = 0U;

  /* Update for DiscreteIntegrator: '<S73>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S73>/Gain'
   *  Sum: '<S73>/Sum5'
   */
  Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] +=
    (rtb_DiscreteTimeIntegrator_h -
     Controller_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 188.49556F * 0.002F;

  /* Update for DiscreteIntegrator: '<S75>/Discrete-Time Integrator' */
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

  /* Update for DiscreteIntegrator: '<S77>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[0] += 0.002F *
    rtb_Multiply_l_idx_0;

  /* Update for DiscreteIntegrator: '<S73>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S73>/Gain'
   *  Sum: '<S73>/Sum5'
   */
  Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] +=
    (rtb_rate_error_B_radPs_idx_1 -
     Controller_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 188.49556F * 0.002F;

  /* Update for DiscreteIntegrator: '<S75>/Discrete-Time Integrator' */
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

  /* Update for DiscreteIntegrator: '<S77>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[1] += 0.002F *
    rtb_Multiply_l_idx_1;

  /* Update for DiscreteIntegrator: '<S73>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S73>/Gain'
   *  Sum: '<S73>/Sum5'
   */
  Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] +=
    (rtb_rate_error_B_radPs_idx_2 -
     Controller_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 188.49556F * 0.002F;

  /* Update for DiscreteIntegrator: '<S75>/Discrete-Time Integrator' */
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

  /* Update for DiscreteIntegrator: '<S77>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[2] += 0.002F *
    rtb_DiscreteTimeIntegrator1_j;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_i = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S113>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S113>/Integrator'
   */
  Controller_DW.Integrator1_DSTATE_p += 0.002F *
    Controller_DW.Integrator_DSTATE_p;

  /* Update for DiscreteIntegrator: '<S116>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S116>/ki'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S116>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_m += CONTROL_PARAM.VEL_Z_I *
    rtb_Gain_fl * 0.002F;
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

  /* End of Update for DiscreteIntegrator: '<S116>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S118>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_k = 0U;
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_h += 0.002F * rtb_Gain_g2;
  Controller_DW.DiscreteTimeIntegrator1_Prev_iy = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Signum: '<S100>/Sign3' incorporates:
   *  Product: '<S100>/Divide'
   *  Sum: '<S100>/Add6'
   */
  rtb_Add3 = rtb_Add3_j_idx_0 + Controller_ConstB.d;

  /* Signum: '<S100>/Sign4' incorporates:
   *  Product: '<S100>/Divide'
   *  Sum: '<S100>/Subtract3'
   */
  rtb_uv_error_C_mPs_idx_0 = rtb_Add3_j_idx_0 - Controller_ConstB.d;

  /* Signum: '<S100>/Sign5' incorporates:
   *  Product: '<S100>/Divide'
   */
  if (rtb_Add3_j_idx_0 < 0.0F) {
    rtb_uv_error_C_mPs_idx_1 = -1.0F;
  } else if (rtb_Add3_j_idx_0 > 0.0F) {
    rtb_uv_error_C_mPs_idx_1 = 1.0F;
  } else {
    rtb_uv_error_C_mPs_idx_1 = rtb_Add3_j_idx_0;
  }

  /* Signum: '<S100>/Sign3' */
  if (rtb_Add3 < 0.0F) {
    rtb_Add3 = -1.0F;
  } else {
    if (rtb_Add3 > 0.0F) {
      rtb_Add3 = 1.0F;
    }
  }

  /* Signum: '<S100>/Sign4' */
  if (rtb_uv_error_C_mPs_idx_0 < 0.0F) {
    rtb_uv_error_C_mPs_idx_0 = -1.0F;
  } else {
    if (rtb_uv_error_C_mPs_idx_0 > 0.0F) {
      rtb_uv_error_C_mPs_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S100>/Sign6' incorporates:
   *  Product: '<S100>/Divide'
   */
  if (rtb_Add3_j_idx_0 < 0.0F) {
    rtb_Gain_idx_0 = -1.0F;
  } else if (rtb_Add3_j_idx_0 > 0.0F) {
    rtb_Gain_idx_0 = 1.0F;
  } else {
    rtb_Gain_idx_0 = rtb_Add3_j_idx_0;
  }

  /* Update for DiscreteIntegrator: '<S97>/Integrator' incorporates:
   *  Constant: '<S100>/const'
   *  Gain: '<S100>/Gain3'
   *  Product: '<S100>/Divide'
   *  Product: '<S100>/Multiply5'
   *  Product: '<S100>/Multiply6'
   *  Sum: '<S100>/Subtract4'
   *  Sum: '<S100>/Subtract5'
   *  Sum: '<S100>/Subtract6'
   */
  Controller_DW.Integrator_DSTATE[0] += ((rtb_Add3_j_idx_0 / Controller_ConstB.d
    - rtb_uv_error_C_mPs_idx_1) * Controller_ConstB.Gain4 * ((rtb_Add3 -
    rtb_uv_error_C_mPs_idx_0) * 0.5F) - rtb_Gain_idx_0 * 58.836F) * 0.002F;

  /* Signum: '<S100>/Sign3' incorporates:
   *  Sum: '<S100>/Add6'
   */
  rtb_Add3 = rtb_Add_i + Controller_ConstB.d;

  /* Signum: '<S100>/Sign4' incorporates:
   *  Sum: '<S100>/Subtract3'
   */
  rtb_uv_error_C_mPs_idx_0 = rtb_Add_i - Controller_ConstB.d;

  /* Signum: '<S100>/Sign5' */
  if (rtb_Add_i < 0.0F) {
    rtb_uv_error_C_mPs_idx_1 = -1.0F;
  } else if (rtb_Add_i > 0.0F) {
    rtb_uv_error_C_mPs_idx_1 = 1.0F;
  } else {
    rtb_uv_error_C_mPs_idx_1 = rtb_Add_i;
  }

  /* Signum: '<S100>/Sign3' */
  if (rtb_Add3 < 0.0F) {
    rtb_Add3 = -1.0F;
  } else {
    if (rtb_Add3 > 0.0F) {
      rtb_Add3 = 1.0F;
    }
  }

  /* Signum: '<S100>/Sign4' */
  if (rtb_uv_error_C_mPs_idx_0 < 0.0F) {
    rtb_uv_error_C_mPs_idx_0 = -1.0F;
  } else {
    if (rtb_uv_error_C_mPs_idx_0 > 0.0F) {
      rtb_uv_error_C_mPs_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S100>/Sign6' */
  if (rtb_Add_i < 0.0F) {
    rtb_Gain_idx_0 = -1.0F;
  } else if (rtb_Add_i > 0.0F) {
    rtb_Gain_idx_0 = 1.0F;
  } else {
    rtb_Gain_idx_0 = rtb_Add_i;
  }

  /* Update for DiscreteIntegrator: '<S97>/Integrator' incorporates:
   *  Constant: '<S100>/const'
   *  Gain: '<S100>/Gain3'
   *  Product: '<S100>/Divide'
   *  Product: '<S100>/Multiply5'
   *  Product: '<S100>/Multiply6'
   *  Sum: '<S100>/Subtract4'
   *  Sum: '<S100>/Subtract5'
   *  Sum: '<S100>/Subtract6'
   */
  Controller_DW.Integrator_DSTATE[1] += ((rtb_Add_i / Controller_ConstB.d -
    rtb_uv_error_C_mPs_idx_1) * Controller_ConstB.Gain4 * ((rtb_Add3 -
    rtb_uv_error_C_mPs_idx_0) * 0.5F) - rtb_Gain_idx_0 * 58.836F) * 0.002F;

  /* Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S3>/Constant'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_n += CONTROL_EXPORT.period;

  /* Signum: '<S114>/Sign6' incorporates:
   *  Signum: '<S114>/Sign5'
   */
  if (rtb_Add3_j_idx_1 < 0.0F) {
    rtb_uv_error_C_mPs_idx_1 = -1.0F;

    /* Signum: '<S114>/Sign5' */
    rtb_Gain_idx_0 = -1.0F;
  } else if (rtb_Add3_j_idx_1 > 0.0F) {
    rtb_uv_error_C_mPs_idx_1 = 1.0F;

    /* Signum: '<S114>/Sign5' */
    rtb_Gain_idx_0 = 1.0F;
  } else {
    rtb_uv_error_C_mPs_idx_1 = rtb_Add3_j_idx_1;

    /* Signum: '<S114>/Sign5' */
    rtb_Gain_idx_0 = rtb_Add3_j_idx_1;
  }

  /* End of Signum: '<S114>/Sign6' */

  /* Sum: '<S114>/Add6' */
  rtb_Add3 = rtb_Add3_j_idx_1 + Controller_ConstB.d_n;

  /* Sum: '<S114>/Subtract3' */
  rtb_uv_error_C_mPs_idx_0 = rtb_Add3_j_idx_1 - Controller_ConstB.d_n;

  /* Signum: '<S114>/Sign3' */
  if (rtb_Add3 < 0.0F) {
    rtb_Add3 = -1.0F;
  } else {
    if (rtb_Add3 > 0.0F) {
      rtb_Add3 = 1.0F;
    }
  }

  /* End of Signum: '<S114>/Sign3' */

  /* Signum: '<S114>/Sign4' */
  if (rtb_uv_error_C_mPs_idx_0 < 0.0F) {
    rtb_uv_error_C_mPs_idx_0 = -1.0F;
  } else {
    if (rtb_uv_error_C_mPs_idx_0 > 0.0F) {
      rtb_uv_error_C_mPs_idx_0 = 1.0F;
    }
  }

  /* End of Signum: '<S114>/Sign4' */

  /* Update for DiscreteIntegrator: '<S113>/Integrator' incorporates:
   *  Constant: '<S114>/const'
   *  Gain: '<S114>/Gain3'
   *  Product: '<S114>/Divide'
   *  Product: '<S114>/Multiply5'
   *  Product: '<S114>/Multiply6'
   *  Sum: '<S114>/Subtract4'
   *  Sum: '<S114>/Subtract5'
   *  Sum: '<S114>/Subtract6'
   */
  Controller_DW.Integrator_DSTATE_p += ((rtb_Add3_j_idx_1 /
    Controller_ConstB.d_n - rtb_Gain_idx_0) * Controller_ConstB.Gain4_k *
    ((rtb_Add3 - rtb_uv_error_C_mPs_idx_0) * 0.5F) - rtb_uv_error_C_mPs_idx_1 *
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

  /* Start for Constant: '<S116>/Constant' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_m = CONTROL_PARAM.VEL_Z_I_MIN;

  /* InitializeConditions for DiscreteIntegrator: '<S102>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S102>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S104>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S73>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S75>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S75>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S77>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_l = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_i = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S116>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S116>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S118>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_k = 1U;
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
