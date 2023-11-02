/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.975
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Nov  2 15:47:35 2023
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
struct_9l8r30AuvaBTupxphpyOQF CONTROL_PARAM = {
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
  0.5F,
  300.0F,
  300.0F,
  200.0F,
  500.0F,
  500.0F,
  350.0F,
  1800.0F,
  1800.0F,
  1400.0F,
  0.5F,
  0.5F,
  0.5F,
  60.0F,
  60.0F,
  100.0F
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
                                        *   '<S97>/Saturation'
                                        *   '<S68>/Saturation'
                                        *   '<S68>/Saturation1'
                                        *   '<S106>/kd'
                                        *   '<S106>/Saturation'
                                        *   '<S107>/ki'
                                        *   '<S107>/Discrete-Time Integrator'
                                        *   '<S108>/kp'
                                        *   '<S120>/kd'
                                        *   '<S120>/Saturation'
                                        *   '<S121>/Constant'
                                        *   '<S121>/ki'
                                        *   '<S121>/Discrete-Time Integrator'
                                        *   '<S122>/kp'
                                        *   '<S71>/Constant3'
                                        *   '<S71>/Constant4'
                                        *   '<S71>/Constant5'
                                        *   '<S71>/Constant6'
                                        *   '<S71>/Constant7'
                                        *   '<S71>/Constant8'
                                        *   '<S90>/Constant1'
                                        *   '<S90>/Constant2'
                                        *   '<S77>/Constant3'
                                        *   '<S77>/Constant4'
                                        *   '<S77>/Constant5'
                                        *   '<S77>/Constant6'
                                        *   '<S77>/Constant7'
                                        *   '<S77>/Constant8'
                                        *   '<S78>/Constant'
                                        *   '<S78>/Constant1'
                                        *   '<S78>/Constant2'
                                        *   '<S79>/gain1'
                                        *   '<S79>/gain2'
                                        *   '<S79>/gain3'
                                        *   '<S79>/Saturation'
                                        *   '<S80>/gain1'
                                        *   '<S80>/gain2'
                                        *   '<S80>/gain3'
                                        *   '<S80>/Discrete-Time Integrator'
                                        *   '<S81>/gain1'
                                        *   '<S81>/gain2'
                                        *   '<S81>/gain3'
                                        */

struct_biZzOMrg0u3lxrb7POOubF CONTROL_EXPORT = {
  2U,

  { 65, 68, 82, 67, 32, 67, 111, 110, 116, 114, 111, 108, 108, 101, 114, 32, 118,
    49, 46, 48, 46, 48, 0 }
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
  real32_T rtb_u_output[3];
  real32_T rtb_Saturation_i;
  uint16_T rtb_VariantMergeForOutportactua[16];
  real32_T rtb_DiscreteTimeIntegrator_h;
  real32_T rtb_VectorConcatenate[9];
  real32_T rtb_Integrator1_a;
  real32_T rtb_Integrator13;
  real32_T rtb_Integrator12;
  real32_T rtb_Gain_f;
  real32_T rtb_Gain_hb0;
  real32_T rtb_Add3_c;
  real32_T rtb_a;
  int32_T i;
  real32_T rtb_VectorConcatenate_0[3];
  real32_T rtb_att_error_B_rad_idx_0;
  real32_T rtb_att_error_B_rad_idx_1;
  real32_T rtb_Multiply2_f_idx_0;
  real32_T rtb_Multiply2_f_idx_1;
  real32_T rtb_Saturation1_idx_1;
  real32_T rtb_Saturation1_idx_0;
  real32_T rtb_rate_error_B_radPs_idx_2;
  real32_T rtb_adrc_z1_idx_0;
  real32_T rtb_adrc_z1_idx_1;
  real32_T rtb_adrc_z1_idx_2;
  real32_T rtb_Z1_dot_idx_0;
  real32_T rtb_Z1_dot_idx_1;
  real32_T rtb_Z1_dot_idx_2;
  real32_T rtb_Multiply_cj_idx_0;
  real32_T rtb_Multiply_cj_idx_1;
  real32_T rtb_Multiply_cj_idx_2;
  real32_T rtb_uv_error_C_mPs_idx_0;
  real32_T rtb_uv_error_C_mPs_idx_1;
  real32_T rtb_Gain_idx_0;
  real32_T rtb_Gain_idx_1;

  /* Trigonometry: '<S104>/Trigonometric Function1' incorporates:
   *  Gain: '<S103>/Gain'
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S104>/Trigonometric Function3'
   */
  rtb_uv_error_C_mPs_idx_0 = arm_cos_f32(-Controller_U.INS_Out.psi);
  rtb_VectorConcatenate[0] = rtb_uv_error_C_mPs_idx_0;

  /* Trigonometry: '<S104>/Trigonometric Function' incorporates:
   *  Gain: '<S103>/Gain'
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S104>/Trigonometric Function2'
   */
  rtb_uv_error_C_mPs_idx_1 = arm_sin_f32(-Controller_U.INS_Out.psi);
  rtb_VectorConcatenate[1] = rtb_uv_error_C_mPs_idx_1;

  /* SignalConversion: '<S104>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S104>/Constant3'
   */
  rtb_VectorConcatenate[2] = 0.0F;

  /* Gain: '<S104>/Gain' */
  rtb_VectorConcatenate[3] = -rtb_uv_error_C_mPs_idx_1;

  /* Trigonometry: '<S104>/Trigonometric Function3' */
  rtb_VectorConcatenate[4] = rtb_uv_error_C_mPs_idx_0;

  /* SignalConversion: '<S104>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S104>/Constant4'
   */
  rtb_VectorConcatenate[5] = 0.0F;

  /* SignalConversion: '<S104>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate[6] = Controller_ConstB.VectorConcatenate3[0];
  rtb_VectorConcatenate[7] = Controller_ConstB.VectorConcatenate3[1];
  rtb_VectorConcatenate[8] = Controller_ConstB.VectorConcatenate3[2];

  /* Product: '<S101>/Multiply' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  SignalConversion: '<S101>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_0[i] = rtb_VectorConcatenate[i + 3] *
      Controller_U.INS_Out.ve + rtb_VectorConcatenate[i] *
      Controller_U.INS_Out.vn;
  }

  /* End of Product: '<S101>/Multiply' */

  /* Sum: '<S98>/Sum' incorporates:
   *  DiscreteIntegrator: '<S102>/Integrator1'
   */
  rtb_uv_error_C_mPs_idx_0 = Controller_DW.Integrator1_DSTATE[0] -
    rtb_VectorConcatenate_0[0];
  rtb_uv_error_C_mPs_idx_1 = Controller_DW.Integrator1_DSTATE[1] -
    rtb_VectorConcatenate_0[1];

  /* DiscreteIntegrator: '<S107>/Discrete-Time Integrator' incorporates:
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

  /* DiscreteIntegrator: '<S109>/Discrete-Time Integrator1' incorporates:
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

  /* Gain: '<S109>/Gain' incorporates:
   *  DiscreteIntegrator: '<S109>/Discrete-Time Integrator1'
   *  Sum: '<S109>/Sum5'
   */
  rtb_Gain_idx_0 = (rtb_uv_error_C_mPs_idx_0 -
                    Controller_DW.DiscreteTimeIntegrator1_DSTATE[0]) *
    62.831852F;
  rtb_Gain_idx_1 = (rtb_uv_error_C_mPs_idx_1 -
                    Controller_DW.DiscreteTimeIntegrator1_DSTATE[1]) *
    62.831852F;

  /* Switch: '<S109>/Switch' incorporates:
   *  Gain: '<S109>/Gain1'
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_U.FMS_Out.reset > 0) {
    rtb_att_error_B_rad_idx_0 = 0.0F;
    rtb_att_error_B_rad_idx_1 = 0.0F;
  } else {
    rtb_att_error_B_rad_idx_0 = rtb_Gain_idx_0;
    rtb_att_error_B_rad_idx_1 = rtb_Gain_idx_1;
  }

  /* End of Switch: '<S109>/Switch' */

  /* Product: '<S106>/Multiply' incorporates:
   *  Constant: '<S106>/kd'
   */
  rtb_Multiply2_f_idx_0 = CONTROL_PARAM.VEL_XY_D * rtb_att_error_B_rad_idx_0;

  /* Saturate: '<S106>/Saturation' */
  if (rtb_Multiply2_f_idx_0 > CONTROL_PARAM.VEL_XY_D_MAX) {
    rtb_Multiply2_f_idx_0 = CONTROL_PARAM.VEL_XY_D_MAX;
  } else {
    if (rtb_Multiply2_f_idx_0 < CONTROL_PARAM.VEL_XY_D_MIN) {
      rtb_Multiply2_f_idx_0 = CONTROL_PARAM.VEL_XY_D_MIN;
    }
  }

  /* Product: '<S106>/Multiply' incorporates:
   *  Constant: '<S106>/kd'
   */
  rtb_att_error_B_rad_idx_0 = rtb_Multiply2_f_idx_0;
  rtb_Multiply2_f_idx_0 = CONTROL_PARAM.VEL_XY_D * rtb_att_error_B_rad_idx_1;

  /* Saturate: '<S106>/Saturation' */
  if (rtb_Multiply2_f_idx_0 > CONTROL_PARAM.VEL_XY_D_MAX) {
    rtb_Multiply2_f_idx_0 = CONTROL_PARAM.VEL_XY_D_MAX;
  } else {
    if (rtb_Multiply2_f_idx_0 < CONTROL_PARAM.VEL_XY_D_MIN) {
      rtb_Multiply2_f_idx_0 = CONTROL_PARAM.VEL_XY_D_MIN;
    }
  }

  /* Switch: '<S100>/Switch' incorporates:
   *  Constant: '<S108>/kp'
   *  Constant: '<S110>/Constant'
   *  Constant: '<S112>/Constant'
   *  Constant: '<S113>/Constant'
   *  DiscreteIntegrator: '<S107>/Discrete-Time Integrator'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S108>/Multiply'
   *  Product: '<S111>/Multiply2'
   *  Product: '<S111>/Multiply3'
   *  RelationalOperator: '<S110>/Compare'
   *  RelationalOperator: '<S112>/Compare'
   *  RelationalOperator: '<S113>/Compare'
   *  S-Function (sfix_bitop): '<S111>/cmd_ax valid'
   *  S-Function (sfix_bitop): '<S111>/cmd_ay valid'
   *  S-Function (sfix_bitop): '<S111>/cmd_u valid'
   *  S-Function (sfix_bitop): '<S111>/cmd_v valid'
   *  Sum: '<S111>/Sum1'
   *  Sum: '<S99>/Add'
   */
  if (Controller_U.FMS_Out.ctrl_mode == 6) {
    rtb_att_error_B_rad_idx_0 = ((Controller_U.FMS_Out.cmd_mask & 64) > 0 ?
      (CONTROL_PARAM.VEL_XY_P * rtb_uv_error_C_mPs_idx_0 +
       Controller_DW.DiscreteTimeIntegrator_DSTATE[0]) +
      rtb_att_error_B_rad_idx_0 : 0.0F) + ((Controller_U.FMS_Out.cmd_mask & 512)
      > 0 ? Controller_U.FMS_Out.ax_cmd : 0.0F);
    rtb_att_error_B_rad_idx_1 = ((Controller_U.FMS_Out.cmd_mask & 128) > 0 ?
      (CONTROL_PARAM.VEL_XY_P * rtb_uv_error_C_mPs_idx_1 +
       Controller_DW.DiscreteTimeIntegrator_DSTATE[1]) + rtb_Multiply2_f_idx_0 :
      0.0F) + ((Controller_U.FMS_Out.cmd_mask & 1024) > 0 ?
               Controller_U.FMS_Out.ay_cmd : 0.0F);
  } else {
    rtb_att_error_B_rad_idx_0 += CONTROL_PARAM.VEL_XY_P *
      rtb_uv_error_C_mPs_idx_0 + Controller_DW.DiscreteTimeIntegrator_DSTATE[0];
    rtb_att_error_B_rad_idx_1 = (CONTROL_PARAM.VEL_XY_P *
      rtb_uv_error_C_mPs_idx_1 + Controller_DW.DiscreteTimeIntegrator_DSTATE[1])
      + rtb_Multiply2_f_idx_0;
  }

  /* End of Switch: '<S100>/Switch' */

  /* Trigonometry: '<S97>/Atan' incorporates:
   *  Constant: '<S97>/g'
   *  Gain: '<S97>/Gain1'
   *  Gain: '<S97>/gain'
   *  Product: '<S97>/Divide'
   */
  rtb_Multiply2_f_idx_0 = atanf(1.1F * rtb_att_error_B_rad_idx_1 / 9.8055F);
  rtb_att_error_B_rad_idx_1 = atanf(1.1F * -rtb_att_error_B_rad_idx_0 / 9.8055F);

  /* Switch: '<S88>/Switch' incorporates:
   *  Constant: '<S95>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  Logic: '<S88>/Logical Operator'
   *  RelationalOperator: '<S94>/Compare'
   *  RelationalOperator: '<S95>/Compare'
   *  Saturate: '<S97>/Saturation'
   *  Switch: '<S88>/Switch1'
   */
  if ((Controller_U.FMS_Out.ctrl_mode == 3) || (Controller_U.FMS_Out.ctrl_mode ==
       4)) {
    rtb_att_error_B_rad_idx_0 = Controller_U.FMS_Out.phi_cmd;
    rtb_att_error_B_rad_idx_1 = Controller_U.FMS_Out.theta_cmd;
  } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
    /* Switch: '<S96>/Switch' incorporates:
     *  S-Function (sfix_bitop): '<S96>/cmd_phi valid'
     *  S-Function (sfix_bitop): '<S96>/cmd_theta valid'
     *  Saturate: '<S97>/Saturation'
     *  Switch: '<S88>/Switch1'
     */
    if ((Controller_U.FMS_Out.cmd_mask & 8) > 0) {
      rtb_att_error_B_rad_idx_0 = Controller_U.FMS_Out.phi_cmd;
    } else if (rtb_Multiply2_f_idx_0 > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      /* Saturate: '<S97>/Saturation' */
      rtb_att_error_B_rad_idx_0 = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    } else if (rtb_Multiply2_f_idx_0 < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      /* Saturate: '<S97>/Saturation' */
      rtb_att_error_B_rad_idx_0 = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    } else {
      rtb_att_error_B_rad_idx_0 = rtb_Multiply2_f_idx_0;
    }

    if ((Controller_U.FMS_Out.cmd_mask & 16) > 0) {
      rtb_att_error_B_rad_idx_1 = Controller_U.FMS_Out.theta_cmd;
    } else if (rtb_att_error_B_rad_idx_1 > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      /* Saturate: '<S97>/Saturation' */
      rtb_att_error_B_rad_idx_1 = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_att_error_B_rad_idx_1 < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S97>/Saturation' */
        rtb_att_error_B_rad_idx_1 = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
      }
    }

    /* End of Switch: '<S96>/Switch' */
  } else {
    if (rtb_Multiply2_f_idx_0 > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      /* Saturate: '<S97>/Saturation' incorporates:
       *  Switch: '<S88>/Switch1'
       */
      rtb_att_error_B_rad_idx_0 = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    } else if (rtb_Multiply2_f_idx_0 < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      /* Saturate: '<S97>/Saturation' incorporates:
       *  Switch: '<S88>/Switch1'
       */
      rtb_att_error_B_rad_idx_0 = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    } else {
      /* Switch: '<S88>/Switch1' incorporates:
       *  Saturate: '<S97>/Saturation'
       */
      rtb_att_error_B_rad_idx_0 = rtb_Multiply2_f_idx_0;
    }

    /* Saturate: '<S97>/Saturation' */
    if (rtb_att_error_B_rad_idx_1 > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      /* Switch: '<S88>/Switch1' */
      rtb_att_error_B_rad_idx_1 = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_att_error_B_rad_idx_1 < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
        /* Switch: '<S88>/Switch1' */
        rtb_att_error_B_rad_idx_1 = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
      }
    }
  }

  /* End of Switch: '<S88>/Switch' */

  /* Sum: '<S89>/Sum' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Multiply2_f_idx_0 = rtb_att_error_B_rad_idx_0 - Controller_U.INS_Out.phi;

  /* Product: '<S92>/Divide1' incorporates:
   *  Abs: '<S92>/Abs'
   *  Constant: '<S92>/const2'
   */
  rtb_a = fabsf(rtb_Multiply2_f_idx_0) / 0.002F;

  /* Product: '<S92>/Divide' incorporates:
   *  Constant: '<S90>/Constant1'
   *  Constant: '<S92>/const1'
   *  Math: '<S92>/Square'
   *  SignalConversion: '<S92>/TmpSignal ConversionAtSquareInport1'
   */
  rtb_Multiply2_f_idx_1 = 9.5993F / (CONTROL_PARAM.ROLL_P * CONTROL_PARAM.ROLL_P);

  /* Signum: '<S92>/Sign' */
  if (rtb_Multiply2_f_idx_0 < 0.0F) {
    rtb_Integrator1_a = -1.0F;
  } else if (rtb_Multiply2_f_idx_0 > 0.0F) {
    rtb_Integrator1_a = 1.0F;
  } else {
    rtb_Integrator1_a = rtb_Multiply2_f_idx_0;
  }

  /* Switch: '<S92>/Switch' incorporates:
   *  Constant: '<S90>/Constant1'
   *  Gain: '<S92>/Gain1'
   *  Gain: '<S92>/Gain2'
   *  Logic: '<S92>/Logical Operator'
   *  Product: '<S92>/Multiply'
   *  Product: '<S92>/Multiply1'
   *  Product: '<S92>/Multiply2'
   *  Product: '<S92>/Multiply3'
   *  RelationalOperator: '<S92>/Relational Operator'
   *  RelationalOperator: '<S92>/Relational Operator2'
   *  SignalConversion: '<S92>/TmpSignal ConversionAtSquareInport1'
   *  Sqrt: '<S92>/Sqrt'
   *  Sum: '<S92>/Subtract'
   */
  if ((rtb_Multiply2_f_idx_0 <= rtb_Multiply2_f_idx_1) && (rtb_Multiply2_f_idx_0
       >= -rtb_Multiply2_f_idx_1)) {
    rtb_Integrator1_a = rtb_Multiply2_f_idx_0 * CONTROL_PARAM.ROLL_P;
  } else {
    rtb_Integrator1_a *= sqrtf((rtb_Integrator1_a * rtb_Multiply2_f_idx_0 - 0.5F
      * rtb_Multiply2_f_idx_1) * Controller_ConstB.Gain);
  }

  /* Gain: '<S92>/Gain3' */
  rtb_Multiply2_f_idx_1 = -rtb_a;

  /* Switch: '<S93>/Switch' incorporates:
   *  Gain: '<S92>/Gain3'
   *  RelationalOperator: '<S93>/UpperRelop'
   */
  if (rtb_Integrator1_a >= -rtb_a) {
    rtb_Multiply2_f_idx_1 = rtb_Integrator1_a;
  }

  /* Switch: '<S93>/Switch2' incorporates:
   *  RelationalOperator: '<S93>/LowerRelop1'
   */
  if (rtb_Integrator1_a <= rtb_a) {
    rtb_a = rtb_Multiply2_f_idx_1;
  }

  /* Saturate: '<S68>/Saturation1' */
  if (rtb_a > CONTROL_PARAM.P_Q_CMD_LIM) {
    rtb_a = CONTROL_PARAM.P_Q_CMD_LIM;
  } else {
    if (rtb_a < -CONTROL_PARAM.P_Q_CMD_LIM) {
      rtb_a = -CONTROL_PARAM.P_Q_CMD_LIM;
    }
  }

  /* Product: '<S92>/Divide1' */
  rtb_Saturation1_idx_0 = rtb_a;

  /* Sum: '<S89>/Sum' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Multiply2_f_idx_0 = rtb_att_error_B_rad_idx_1 - Controller_U.INS_Out.theta;

  /* Product: '<S92>/Divide1' incorporates:
   *  Abs: '<S92>/Abs'
   *  Constant: '<S92>/const2'
   */
  rtb_a = fabsf(rtb_Multiply2_f_idx_0) / 0.002F;

  /* Product: '<S92>/Divide' incorporates:
   *  Constant: '<S90>/Constant2'
   *  Constant: '<S92>/const1'
   *  Math: '<S92>/Square'
   *  SignalConversion: '<S92>/TmpSignal ConversionAtSquareInport1'
   */
  rtb_Multiply2_f_idx_1 = 9.5993F / (CONTROL_PARAM.PITCH_P *
    CONTROL_PARAM.PITCH_P);

  /* Signum: '<S92>/Sign' */
  if (rtb_Multiply2_f_idx_0 < 0.0F) {
    rtb_Integrator1_a = -1.0F;
  } else if (rtb_Multiply2_f_idx_0 > 0.0F) {
    rtb_Integrator1_a = 1.0F;
  } else {
    rtb_Integrator1_a = rtb_Multiply2_f_idx_0;
  }

  /* Switch: '<S92>/Switch' incorporates:
   *  Constant: '<S90>/Constant2'
   *  Gain: '<S92>/Gain1'
   *  Gain: '<S92>/Gain2'
   *  Logic: '<S92>/Logical Operator'
   *  Product: '<S92>/Multiply'
   *  Product: '<S92>/Multiply1'
   *  Product: '<S92>/Multiply2'
   *  Product: '<S92>/Multiply3'
   *  RelationalOperator: '<S92>/Relational Operator'
   *  RelationalOperator: '<S92>/Relational Operator2'
   *  SignalConversion: '<S92>/TmpSignal ConversionAtSquareInport1'
   *  Sqrt: '<S92>/Sqrt'
   *  Sum: '<S92>/Subtract'
   */
  if ((rtb_Multiply2_f_idx_0 <= rtb_Multiply2_f_idx_1) && (rtb_Multiply2_f_idx_0
       >= -rtb_Multiply2_f_idx_1)) {
    rtb_Integrator1_a = rtb_Multiply2_f_idx_0 * CONTROL_PARAM.PITCH_P;
  } else {
    rtb_Integrator1_a *= sqrtf((rtb_Integrator1_a * rtb_Multiply2_f_idx_0 - 0.5F
      * rtb_Multiply2_f_idx_1) * Controller_ConstB.Gain);
  }

  /* Gain: '<S92>/Gain3' */
  rtb_Multiply2_f_idx_1 = -rtb_a;

  /* Switch: '<S93>/Switch' incorporates:
   *  Gain: '<S92>/Gain3'
   *  RelationalOperator: '<S93>/UpperRelop'
   */
  if (rtb_Integrator1_a >= -rtb_a) {
    rtb_Multiply2_f_idx_1 = rtb_Integrator1_a;
  }

  /* Switch: '<S93>/Switch2' incorporates:
   *  RelationalOperator: '<S93>/LowerRelop1'
   */
  if (rtb_Integrator1_a <= rtb_a) {
    rtb_a = rtb_Multiply2_f_idx_1;
  }

  /* Saturate: '<S68>/Saturation1' */
  if (rtb_a > CONTROL_PARAM.P_Q_CMD_LIM) {
    rtb_a = CONTROL_PARAM.P_Q_CMD_LIM;
  } else {
    if (rtb_a < -CONTROL_PARAM.P_Q_CMD_LIM) {
      rtb_a = -CONTROL_PARAM.P_Q_CMD_LIM;
    }
  }

  /* Saturate: '<S68>/Saturation' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_U.FMS_Out.psi_rate_cmd > CONTROL_PARAM.R_CMD_LIM) {
    rtb_Integrator1_a = CONTROL_PARAM.R_CMD_LIM;
  } else if (Controller_U.FMS_Out.psi_rate_cmd < -CONTROL_PARAM.R_CMD_LIM) {
    rtb_Integrator1_a = -CONTROL_PARAM.R_CMD_LIM;
  } else {
    rtb_Integrator1_a = Controller_U.FMS_Out.psi_rate_cmd;
  }

  /* End of Saturate: '<S68>/Saturation' */

  /* Trigonometry: '<S83>/Sin' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_DiscreteTimeIntegrator_h = arm_sin_f32(Controller_U.INS_Out.phi);

  /* Trigonometry: '<S83>/Cos1' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Integrator13 = arm_cos_f32(Controller_U.INS_Out.theta);

  /* Product: '<S83>/Multiply3' */
  rtb_Multiply2_f_idx_1 = rtb_DiscreteTimeIntegrator_h * rtb_Integrator13 *
    rtb_Integrator1_a;

  /* Trigonometry: '<S83>/Cos' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Integrator12 = arm_cos_f32(Controller_U.INS_Out.phi);

  /* Product: '<S83>/Multiply1' */
  rtb_rate_error_B_radPs_idx_2 = rtb_Integrator12 * rtb_a;

  /* Product: '<S83>/Multiply4' */
  rtb_DiscreteTimeIntegrator_h *= rtb_a;

  /* Switch: '<S69>/Switch' incorporates:
   *  Constant: '<S84>/Constant'
   *  Constant: '<S85>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  RelationalOperator: '<S84>/Compare'
   *  RelationalOperator: '<S85>/Compare'
   *  Switch: '<S69>/Switch1'
   */
  if (Controller_U.FMS_Out.ctrl_mode == 2) {
    rtb_Multiply2_f_idx_0 = Controller_U.FMS_Out.p_cmd;
    rtb_Multiply2_f_idx_1 = Controller_U.FMS_Out.q_cmd;
    rtb_DiscreteTimeIntegrator_h = Controller_U.FMS_Out.r_cmd;
  } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
    /* Switch: '<S86>/Switch' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S83>/Multiply'
     *  Product: '<S83>/Multiply1'
     *  Product: '<S83>/Multiply5'
     *  S-Function (sfix_bitop): '<S86>/cmd_p valid'
     *  S-Function (sfix_bitop): '<S86>/cmd_q valid'
     *  S-Function (sfix_bitop): '<S86>/cmd_r valid'
     *  Sum: '<S83>/Add'
     *  Sum: '<S83>/Add1'
     *  Sum: '<S83>/Add2'
     *  Switch: '<S69>/Switch1'
     *  Trigonometry: '<S83>/Sin1'
     */
    if ((Controller_U.FMS_Out.cmd_mask & 1) > 0) {
      rtb_Multiply2_f_idx_0 = Controller_U.FMS_Out.p_cmd;
    } else {
      rtb_Multiply2_f_idx_0 = rtb_Saturation1_idx_0 - arm_sin_f32
        (Controller_U.INS_Out.theta) * rtb_Integrator1_a;
    }

    if ((Controller_U.FMS_Out.cmd_mask & 2) > 0) {
      rtb_Multiply2_f_idx_1 = Controller_U.FMS_Out.q_cmd;
    } else {
      rtb_Multiply2_f_idx_1 += rtb_rate_error_B_radPs_idx_2;
    }

    if ((Controller_U.FMS_Out.cmd_mask & 4) > 0) {
      rtb_DiscreteTimeIntegrator_h = Controller_U.FMS_Out.r_cmd;
    } else {
      rtb_DiscreteTimeIntegrator_h = rtb_Integrator12 * rtb_Integrator13 *
        rtb_Integrator1_a - rtb_DiscreteTimeIntegrator_h;
    }

    /* End of Switch: '<S86>/Switch' */
  } else {
    /* Switch: '<S69>/Switch1' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S83>/Multiply'
     *  Product: '<S83>/Multiply3'
     *  Product: '<S83>/Multiply5'
     *  Sum: '<S83>/Add'
     *  Sum: '<S83>/Add1'
     *  Sum: '<S83>/Add2'
     *  Trigonometry: '<S83>/Sin1'
     */
    rtb_Multiply2_f_idx_0 = rtb_Saturation1_idx_0 - arm_sin_f32
      (Controller_U.INS_Out.theta) * rtb_Integrator1_a;
    rtb_Multiply2_f_idx_1 += rtb_rate_error_B_radPs_idx_2;
    rtb_DiscreteTimeIntegrator_h = rtb_Integrator12 * rtb_Integrator13 *
      rtb_Integrator1_a - rtb_DiscreteTimeIntegrator_h;
  }

  /* End of Switch: '<S69>/Switch' */

  /* Sum: '<S72>/Sum' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Integrator13 = rtb_Multiply2_f_idx_0 - Controller_U.INS_Out.p;
  rtb_Integrator12 = rtb_Multiply2_f_idx_1 - Controller_U.INS_Out.q;
  rtb_rate_error_B_radPs_idx_2 = rtb_DiscreteTimeIntegrator_h -
    Controller_U.INS_Out.r;

  /* DiscreteIntegrator: '<S76>/Discrete-Time Integrator5' */
  if (Controller_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] = rtb_Integrator13;
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] = rtb_Integrator12;
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] =
      rtb_rate_error_B_radPs_idx_2;
  }

  /* DiscreteIntegrator: '<S80>/Discrete-Time Integrator' incorporates:
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

  /* DiscreteIntegrator: '<S82>/Discrete-Time Integrator1' incorporates:
   *  DiscreteIntegrator: '<S76>/Discrete-Time Integrator5'
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

  /* Gain: '<S82>/Gain' incorporates:
   *  DiscreteIntegrator: '<S76>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S82>/Discrete-Time Integrator1'
   *  Sum: '<S82>/Sum5'
   */
  rtb_Multiply2_f_idx_0 = (Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] -
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[0]) * 188.49556F;
  rtb_Multiply2_f_idx_1 = (Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] -
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[1]) * 188.49556F;
  rtb_DiscreteTimeIntegrator_h = (Controller_DW.DiscreteTimeIntegrator5_DSTATE[2]
    - Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[2]) * 188.49556F;

  /* Switch: '<S82>/Switch' incorporates:
   *  Gain: '<S82>/Gain1'
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_U.FMS_Out.reset > 0) {
    rtb_adrc_z1_idx_0 = 0.0F;
    rtb_adrc_z1_idx_1 = 0.0F;
    rtb_adrc_z1_idx_2 = 0.0F;
  } else {
    rtb_adrc_z1_idx_0 = rtb_Multiply2_f_idx_0;
    rtb_adrc_z1_idx_1 = rtb_Multiply2_f_idx_1;
    rtb_adrc_z1_idx_2 = rtb_DiscreteTimeIntegrator_h;
  }

  /* End of Switch: '<S82>/Switch' */

  /* Product: '<S79>/Multiply' incorporates:
   *  Constant: '<S79>/gain1'
   */
  rtb_Integrator1_a = CONTROL_PARAM.ROLL_RATE_D * rtb_adrc_z1_idx_0;

  /* Saturate: '<S79>/Saturation' */
  if (rtb_Integrator1_a > CONTROL_PARAM.RATE_D_MAX) {
    rtb_Integrator1_a = CONTROL_PARAM.RATE_D_MAX;
  } else {
    if (rtb_Integrator1_a < CONTROL_PARAM.RATE_D_MIN) {
      rtb_Integrator1_a = CONTROL_PARAM.RATE_D_MIN;
    }
  }

  /* Product: '<S79>/Multiply' incorporates:
   *  Constant: '<S79>/gain2'
   */
  rtb_adrc_z1_idx_0 = rtb_Integrator1_a;
  rtb_Integrator1_a = CONTROL_PARAM.PITCH_RATE_D * rtb_adrc_z1_idx_1;

  /* Saturate: '<S79>/Saturation' */
  if (rtb_Integrator1_a > CONTROL_PARAM.RATE_D_MAX) {
    rtb_Integrator1_a = CONTROL_PARAM.RATE_D_MAX;
  } else {
    if (rtb_Integrator1_a < CONTROL_PARAM.RATE_D_MIN) {
      rtb_Integrator1_a = CONTROL_PARAM.RATE_D_MIN;
    }
  }

  /* Product: '<S79>/Multiply' incorporates:
   *  Constant: '<S79>/gain3'
   */
  rtb_adrc_z1_idx_1 = rtb_Integrator1_a;
  rtb_Integrator1_a = CONTROL_PARAM.YAW_RATE_D * rtb_adrc_z1_idx_2;

  /* Saturate: '<S79>/Saturation' */
  if (rtb_Integrator1_a > CONTROL_PARAM.RATE_D_MAX) {
    rtb_Integrator1_a = CONTROL_PARAM.RATE_D_MAX;
  } else {
    if (rtb_Integrator1_a < CONTROL_PARAM.RATE_D_MIN) {
      rtb_Integrator1_a = CONTROL_PARAM.RATE_D_MIN;
    }
  }

  /* DiscreteIntegrator: '<S78>/Integrator1 1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.Integrator11_PrevResetState != 0)) {
    Controller_DW.Integrator11_DSTATE = 0.0F;
  }

  if (Controller_DW.Integrator11_DSTATE >= 60.0F) {
    Controller_DW.Integrator11_DSTATE = 60.0F;
  } else {
    if (Controller_DW.Integrator11_DSTATE <= -60.0F) {
      Controller_DW.Integrator11_DSTATE = -60.0F;
    }
  }

  /* DiscreteIntegrator: '<S78>/Integrator1 2' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.Integrator12_PrevResetState != 0)) {
    Controller_DW.Integrator12_DSTATE = 0.0F;
  }

  if (Controller_DW.Integrator12_DSTATE >= 60.0F) {
    Controller_DW.Integrator12_DSTATE = 60.0F;
  } else {
    if (Controller_DW.Integrator12_DSTATE <= -60.0F) {
      Controller_DW.Integrator12_DSTATE = -60.0F;
    }
  }

  /* DiscreteIntegrator: '<S78>/Integrator1 3' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.Integrator13_PrevResetState != 0)) {
    Controller_DW.Integrator13_DSTATE = 0.0F;
  }

  if (Controller_DW.Integrator13_DSTATE >= 100.0F) {
    Controller_DW.Integrator13_DSTATE = 100.0F;
  } else {
    if (Controller_DW.Integrator13_DSTATE <= -100.0F) {
      Controller_DW.Integrator13_DSTATE = -100.0F;
    }
  }

  /* Sum: '<S67>/Sum' incorporates:
   *  Constant: '<S71>/Constant3'
   *  Constant: '<S71>/Constant4'
   *  Constant: '<S71>/Constant5'
   *  Constant: '<S71>/Constant6'
   *  Constant: '<S71>/Constant7'
   *  Constant: '<S71>/Constant8'
   *  Constant: '<S81>/gain1'
   *  Constant: '<S81>/gain2'
   *  Constant: '<S81>/gain3'
   *  DiscreteIntegrator: '<S76>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S78>/Integrator1 1'
   *  DiscreteIntegrator: '<S78>/Integrator1 2'
   *  DiscreteIntegrator: '<S78>/Integrator1 3'
   *  DiscreteIntegrator: '<S80>/Discrete-Time Integrator'
   *  Product: '<S71>/Multiply1'
   *  Product: '<S71>/Multiply2'
   *  Product: '<S81>/Multiply'
   *  Sum: '<S74>/Add'
   */
  rtb_u_output[0] = ((CONTROL_PARAM.ROLL_RATE_P *
                      Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] +
                      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0]) +
                     rtb_adrc_z1_idx_0) - 1.0F / CONTROL_PARAM.LADRC_ROLL_B0 *
    Controller_DW.Integrator11_DSTATE * CONTROL_PARAM.LADRC_ROLL_GAMMA;
  rtb_u_output[1] = ((CONTROL_PARAM.PITCH_RATE_P *
                      Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] +
                      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1]) +
                     rtb_adrc_z1_idx_1) - 1.0F / CONTROL_PARAM.LADRC_PITCH_B0 *
    Controller_DW.Integrator12_DSTATE * CONTROL_PARAM.LADRC_PITCH_GAMMA;
  rtb_u_output[2] = ((CONTROL_PARAM.YAW_RATE_P *
                      Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] +
                      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2]) +
                     rtb_Integrator1_a) - 1.0F / CONTROL_PARAM.LADRC_YAW_B0 *
    Controller_DW.Integrator13_DSTATE * CONTROL_PARAM.LADRC_YAW_GAMMA;

  /* Gain: '<S116>/Gain' incorporates:
   *  DiscreteIntegrator: '<S118>/Integrator1'
   *  Inport: '<Root>/INS_Out'
   *  Sum: '<S116>/Sum1'
   */
  rtb_Gain_f = -(Controller_DW.Integrator1_DSTATE_p - Controller_U.INS_Out.vd);

  /* DiscreteIntegrator: '<S121>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S121>/Constant'
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

  /* DiscreteIntegrator: '<S123>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_k != 0) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_h = rtb_Gain_f;
  }

  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_Prev_iy != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_h = rtb_Gain_f;
  }

  /* Gain: '<S123>/Gain' incorporates:
   *  DiscreteIntegrator: '<S123>/Discrete-Time Integrator1'
   *  Sum: '<S123>/Sum5'
   */
  rtb_Gain_hb0 = (rtb_Gain_f - Controller_DW.DiscreteTimeIntegrator1_DSTAT_h) *
    62.831852F;

  /* Switch: '<S123>/Switch' incorporates:
   *  Gain: '<S123>/Gain1'
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_U.FMS_Out.reset > 0) {
    rtb_Integrator1_a = 0.0F;
  } else {
    rtb_Integrator1_a = rtb_Gain_hb0;
  }

  /* End of Switch: '<S123>/Switch' */

  /* Product: '<S120>/Multiply' incorporates:
   *  Constant: '<S120>/kd'
   */
  rtb_Add3_c = CONTROL_PARAM.VEL_Z_D * rtb_Integrator1_a;

  /* Saturate: '<S120>/Saturation' */
  if (rtb_Add3_c > CONTROL_PARAM.VEL_Z_D_MAX) {
    rtb_Add3_c = CONTROL_PARAM.VEL_Z_D_MAX;
  } else {
    if (rtb_Add3_c < CONTROL_PARAM.VEL_Z_D_MIN) {
      rtb_Add3_c = CONTROL_PARAM.VEL_Z_D_MIN;
    }
  }

  /* End of Saturate: '<S120>/Saturation' */

  /* Sum: '<S117>/Add' incorporates:
   *  Constant: '<S122>/kp'
   *  DiscreteIntegrator: '<S121>/Discrete-Time Integrator'
   *  Product: '<S122>/Multiply'
   */
  rtb_Integrator1_a = (CONTROL_PARAM.VEL_Z_P * rtb_Gain_f +
                       Controller_DW.DiscreteTimeIntegrator_DSTATE_m) +
    rtb_Add3_c;

  /* Product: '<S115>/Multiply' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S115>/Cos'
   *  Trigonometry: '<S115>/Cos1'
   */
  rtb_Add3_c = arm_cos_f32(Controller_U.INS_Out.phi) * arm_cos_f32
    (Controller_U.INS_Out.theta);

  /* Saturate: '<S115>/Saturation1' */
  if (rtb_Add3_c > 1.0F) {
    rtb_att_error_B_rad_idx_1 = 1.0F;
  } else if (rtb_Add3_c < 0.5F) {
    rtb_att_error_B_rad_idx_1 = 0.5F;
  } else {
    rtb_att_error_B_rad_idx_1 = rtb_Add3_c;
  }

  /* End of Saturate: '<S115>/Saturation1' */

  /* Gain: '<S115>/Gain' */
  rtb_Add3_c *= 2.0F;

  /* Saturate: '<S115>/Saturation' */
  if (rtb_Add3_c > 1.0F) {
    rtb_Add3_c = 1.0F;
  } else {
    if (rtb_Add3_c < 0.0F) {
      rtb_Add3_c = 0.0F;
    }
  }

  /* End of Saturate: '<S115>/Saturation' */

  /* Product: '<S115>/Multiply1' incorporates:
   *  Constant: '<S115>/Constant'
   *  Product: '<S115>/Divide'
   */
  rtb_Add3_c *= 1.0F / rtb_att_error_B_rad_idx_1 * rtb_Integrator1_a;

  /* Saturate: '<S114>/Saturation' */
  if (rtb_Add3_c > 0.35F) {
    rtb_Saturation_i = 0.35F;
  } else if (rtb_Add3_c < -0.35F) {
    rtb_Saturation_i = -0.35F;
  } else {
    rtb_Saturation_i = rtb_Add3_c;
  }

  /* End of Saturate: '<S114>/Saturation' */

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
      if (rtb_u_output[0] > 1.0F) {
        tmp_b = 1.0F;
      } else if (rtb_u_output[0] < -1.0F) {
        tmp_b = -1.0F;
      } else {
        tmp_b = rtb_u_output[0];
      }

      if (rtb_u_output[1] > 1.0F) {
        tmp_k = 1.0F;
      } else if (rtb_u_output[1] < -1.0F) {
        tmp_k = -1.0F;
      } else {
        tmp_k = rtb_u_output[1];
      }

      if (rtb_u_output[2] > 1.0F) {
        tmp_i = 1.0F;
      } else if (rtb_u_output[2] < -1.0F) {
        tmp_i = -1.0F;
      } else {
        tmp_i = rtb_u_output[2];
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
                              tmp_b))), 65536.0F);
        u0_k = (uint16_T)((uint32_T)(u0_b < 0.0F ? (int32_T)(uint16_T)-(int16_T)
          (uint16_T)-u0_b : (int32_T)(uint16_T)u0_b) + rtb_throttle_cmd);
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
      if (rtb_u_output[0] > 1.0F) {
        tmp_n = 1.0F;
      } else if (rtb_u_output[0] < -1.0F) {
        tmp_n = -1.0F;
      } else {
        tmp_n = rtb_u_output[0];
      }

      if (rtb_u_output[1] > 1.0F) {
        tmp_d = 1.0F;
      } else if (rtb_u_output[1] < -1.0F) {
        tmp_d = -1.0F;
      } else {
        tmp_d = rtb_u_output[1];
      }

      if (rtb_u_output[2] > 1.0F) {
        tmp_a = 1.0F;
      } else if (rtb_u_output[2] < -1.0F) {
        tmp_a = -1.0F;
      } else {
        tmp_a = rtb_u_output[2];
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
                              tmp_n))), 65536.0F);
        u0_d = (uint16_T)((uint32_T)(u0_n < 0.0F ? (int32_T)(uint16_T)-(int16_T)
          (uint16_T)-u0_n : (int32_T)(uint16_T)u0_n) + rtb_throttle_cmd_b);
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
      if (rtb_u_output[0] > 1.0F) {
        tmp_i = 1.0F;
      } else if (rtb_u_output[0] < -1.0F) {
        tmp_i = -1.0F;
      } else {
        tmp_i = rtb_u_output[0];
      }

      if (rtb_u_output[1] > 1.0F) {
        tmp_o = 1.0F;
      } else if (rtb_u_output[1] < -1.0F) {
        tmp_o = -1.0F;
      } else {
        tmp_o = rtb_u_output[1];
      }

      if (rtb_u_output[2] > 1.0F) {
        tmp_d = 1.0F;
      } else if (rtb_u_output[2] < -1.0F) {
        tmp_d = -1.0F;
      } else {
        tmp_d = rtb_u_output[2];
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
                              tmp_i))), 65536.0F);
        u0_o = (uint16_T)((uint32_T)(u0_i < 0.0F ? (int32_T)(uint16_T)-(int16_T)
          (uint16_T)-u0_i : (int32_T)(uint16_T)u0_i) + rtb_throttle_cmd_k);
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
      if (rtb_u_output[0] > 1.0F) {
        tmp_j = 1.0F;
      } else if (rtb_u_output[0] < -1.0F) {
        tmp_j = -1.0F;
      } else {
        tmp_j = rtb_u_output[0];
      }

      if (rtb_u_output[1] > 1.0F) {
        tmp_e = 1.0F;
      } else if (rtb_u_output[1] < -1.0F) {
        tmp_e = -1.0F;
      } else {
        tmp_e = rtb_u_output[1];
      }

      if (rtb_u_output[2] > 1.0F) {
        tmp_g = 1.0F;
      } else if (rtb_u_output[2] < -1.0F) {
        tmp_g = -1.0F;
      } else {
        tmp_g = rtb_u_output[2];
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
                              tmp_j))), 65536.0F);
        u0_e = (uint16_T)((uint32_T)(u0_j < 0.0F ? (int32_T)(uint16_T)-(int16_T)
          (uint16_T)-u0_j : (int32_T)(uint16_T)u0_j) + rtb_throttle_cmd_d);
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
      if (rtb_u_output[0] > 1.0F) {
        tmp_i = 1.0F;
      } else if (rtb_u_output[0] < -1.0F) {
        tmp_i = -1.0F;
      } else {
        tmp_i = rtb_u_output[0];
      }

      if (rtb_u_output[1] > 1.0F) {
        tmp_d = 1.0F;
      } else if (rtb_u_output[1] < -1.0F) {
        tmp_d = -1.0F;
      } else {
        tmp_d = rtb_u_output[1];
      }

      if (rtb_u_output[2] > 1.0F) {
        tmp_j = 1.0F;
      } else if (rtb_u_output[2] < -1.0F) {
        tmp_j = -1.0F;
      } else {
        tmp_j = rtb_u_output[2];
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
                              tmp_i))), 65536.0F);
        u0_d = (uint16_T)((uint32_T)(u0_i < 0.0F ? (int32_T)(uint16_T)-(int16_T)
          (uint16_T)-u0_i : (int32_T)(uint16_T)u0_i) + rtb_throttle_cmd_m);
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
      if (rtb_u_output[0] > 1.0F) {
        tmp_l = 1.0F;
      } else if (rtb_u_output[0] < -1.0F) {
        tmp_l = -1.0F;
      } else {
        tmp_l = rtb_u_output[0];
      }

      if (rtb_u_output[1] > 1.0F) {
        tmp_m = 1.0F;
      } else if (rtb_u_output[1] < -1.0F) {
        tmp_m = -1.0F;
      } else {
        tmp_m = rtb_u_output[1];
      }

      if (rtb_u_output[2] > 1.0F) {
        tmp_c = 1.0F;
      } else if (rtb_u_output[2] < -1.0F) {
        tmp_c = -1.0F;
      } else {
        tmp_c = rtb_u_output[2];
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
                              tmp_l))), 65536.0F);
        u0_m = (uint16_T)((uint32_T)(u0_l < 0.0F ? (int32_T)(uint16_T)-(int16_T)
          (uint16_T)-u0_l : (int32_T)(uint16_T)u0_l) + rtb_throttle_cmd_n);
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
      if (rtb_u_output[0] > 1.0F) {
        tmp_m = 1.0F;
      } else if (rtb_u_output[0] < -1.0F) {
        tmp_m = -1.0F;
      } else {
        tmp_m = rtb_u_output[0];
      }

      if (rtb_u_output[1] > 1.0F) {
        tmp_n = 1.0F;
      } else if (rtb_u_output[1] < -1.0F) {
        tmp_n = -1.0F;
      } else {
        tmp_n = rtb_u_output[1];
      }

      if (rtb_u_output[2] > 1.0F) {
        tmp_al = 1.0F;
      } else if (rtb_u_output[2] < -1.0F) {
        tmp_al = -1.0F;
      } else {
        tmp_al = rtb_u_output[2];
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
      if (rtb_u_output[0] > 1.0F) {
        tmp_e = 1.0F;
      } else if (rtb_u_output[0] < -1.0F) {
        tmp_e = -1.0F;
      } else {
        tmp_e = rtb_u_output[0];
      }

      if (rtb_u_output[1] > 1.0F) {
        tmp_o = 1.0F;
      } else if (rtb_u_output[1] < -1.0F) {
        tmp_o = -1.0F;
      } else {
        tmp_o = rtb_u_output[1];
      }

      if (rtb_u_output[2] > 1.0F) {
        tmp_h = 1.0F;
      } else if (rtb_u_output[2] < -1.0F) {
        tmp_h = -1.0F;
      } else {
        tmp_h = rtb_u_output[2];
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
                              tmp_e))), 65536.0F);
        u0_o = (uint16_T)((uint32_T)(u0_e < 0.0F ? (int32_T)(uint16_T)-(int16_T)
          (uint16_T)-u0_e : (int32_T)(uint16_T)u0_e) + rtb_throttle_cmd_c);
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

  /* DiscreteIntegrator: '<S77>/Integrator1 ' incorporates:
   *  Inport: '<Root>/FMS_Out'
   *  Inport: '<Root>/INS_Out'
   */
  if (Controller_DW.Integrator1_IC_LOADING != 0) {
    Controller_DW.Integrator1_DSTATE_a[0] = Controller_U.INS_Out.p;
    Controller_DW.Integrator1_DSTATE_a[1] = Controller_U.INS_Out.q;
    Controller_DW.Integrator1_DSTATE_a[2] = Controller_U.INS_Out.r;
  }

  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.Integrator1_PrevResetState != 0)) {
    Controller_DW.Integrator1_DSTATE_a[0] = Controller_U.INS_Out.p;
    Controller_DW.Integrator1_DSTATE_a[1] = Controller_U.INS_Out.q;
    Controller_DW.Integrator1_DSTATE_a[2] = Controller_U.INS_Out.r;
  }

  /* Sum: '<S73>/Sum2' incorporates:
   *  DiscreteIntegrator: '<S77>/Integrator1 '
   *  Inport: '<Root>/INS_Out'
   */
  rtb_adrc_z1_idx_0 = Controller_DW.Integrator1_DSTATE_a[0] -
    Controller_U.INS_Out.p;
  rtb_adrc_z1_idx_1 = Controller_DW.Integrator1_DSTATE_a[1] -
    Controller_U.INS_Out.q;
  rtb_adrc_z1_idx_2 = Controller_DW.Integrator1_DSTATE_a[2] -
    Controller_U.INS_Out.r;

  /* Sum: '<S77>/Sum1' incorporates:
   *  Constant: '<S77>/Constant3'
   *  Constant: '<S77>/Constant4'
   *  Constant: '<S77>/Constant5'
   *  Constant: '<S77>/Constant6'
   *  Constant: '<S77>/Constant7'
   *  Constant: '<S77>/Constant8'
   *  DiscreteIntegrator: '<S78>/Integrator1 1'
   *  DiscreteIntegrator: '<S78>/Integrator1 2'
   *  DiscreteIntegrator: '<S78>/Integrator1 3'
   *  Product: '<S77>/Multiply1'
   *  Product: '<S77>/Multiply2'
   */
  rtb_Z1_dot_idx_0 = (CONTROL_PARAM.LADRC_ROLL_B0 * rtb_u_output[0] -
                      CONTROL_PARAM.LADRC_ROLL_BETA1 * rtb_adrc_z1_idx_0) +
    Controller_DW.Integrator11_DSTATE;
  rtb_Z1_dot_idx_1 = (CONTROL_PARAM.LADRC_PITCH_B0 * rtb_u_output[1] -
                      CONTROL_PARAM.LADRC_PITCH_BETA1 * rtb_adrc_z1_idx_1) +
    Controller_DW.Integrator12_DSTATE;
  rtb_Z1_dot_idx_2 = (CONTROL_PARAM.LADRC_YAW_B0 * rtb_u_output[2] -
                      CONTROL_PARAM.LADRC_YAW_BETA1 * rtb_adrc_z1_idx_2) +
    Controller_DW.Integrator13_DSTATE;

  /* Product: '<S78>/Multiply' incorporates:
   *  Constant: '<S78>/Constant'
   *  Constant: '<S78>/Constant1'
   *  Gain: '<S78>/Gain'
   */
  rtb_adrc_z1_idx_0 = -(rtb_adrc_z1_idx_0 * CONTROL_PARAM.LADRC_ROLL_BETA2);
  rtb_adrc_z1_idx_1 = -(rtb_adrc_z1_idx_1 * CONTROL_PARAM.LADRC_PITCH_BETA2);

  /* Product: '<S80>/Multiply' incorporates:
   *  Constant: '<S80>/gain1'
   *  Constant: '<S80>/gain2'
   *  Constant: '<S80>/gain3'
   *  DiscreteIntegrator: '<S76>/Discrete-Time Integrator5'
   */
  rtb_Multiply_cj_idx_0 = CONTROL_PARAM.ROLL_RATE_I *
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[0];
  rtb_Multiply_cj_idx_1 = CONTROL_PARAM.PITCH_RATE_I *
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1];
  rtb_Multiply_cj_idx_2 = CONTROL_PARAM.YAW_RATE_I *
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[2];

  /* Product: '<S105>/Multiply1' incorporates:
   *  Constant: '<S105>/const1'
   *  DiscreteIntegrator: '<S102>/Integrator'
   */
  rtb_att_error_B_rad_idx_0 = Controller_DW.Integrator_DSTATE[0] * 0.05F;
  rtb_att_error_B_rad_idx_1 = Controller_DW.Integrator_DSTATE[1] * 0.05F;

  /* Sum: '<S105>/Add' incorporates:
   *  DiscreteIntegrator: '<S102>/Integrator1'
   *  Inport: '<Root>/FMS_Out'
   *  Sum: '<S102>/Subtract'
   */
  rtb_Saturation1_idx_0 = (Controller_DW.Integrator1_DSTATE[0] -
    Controller_U.FMS_Out.u_cmd) + rtb_att_error_B_rad_idx_0;
  rtb_Saturation1_idx_1 = (Controller_DW.Integrator1_DSTATE[1] -
    Controller_U.FMS_Out.v_cmd) + rtb_att_error_B_rad_idx_1;

  /* Signum: '<S105>/Sign' */
  if (rtb_Saturation1_idx_0 < 0.0F) {
    rtb_Integrator1_a = -1.0F;
  } else if (rtb_Saturation1_idx_0 > 0.0F) {
    rtb_Integrator1_a = 1.0F;
  } else {
    rtb_Integrator1_a = rtb_Saturation1_idx_0;
  }

  /* Sum: '<S105>/Add2' incorporates:
   *  Abs: '<S105>/Abs'
   *  Gain: '<S105>/Gain'
   *  Gain: '<S105>/Gain1'
   *  Product: '<S105>/Multiply2'
   *  Product: '<S105>/Multiply3'
   *  Signum: '<S105>/Sign'
   *  Sqrt: '<S105>/Sqrt'
   *  Sum: '<S105>/Add1'
   *  Sum: '<S105>/Subtract'
   */
  rtb_Integrator1_a = (sqrtf((8.0F * fabsf(rtb_Saturation1_idx_0) +
    Controller_ConstB.d) * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
    rtb_Integrator1_a + rtb_att_error_B_rad_idx_0;

  /* Sum: '<S105>/Add3' incorporates:
   *  Signum: '<S105>/Sign'
   */
  rtb_Add3_c = rtb_Saturation1_idx_0 + Controller_ConstB.d;

  /* Sum: '<S105>/Subtract1' incorporates:
   *  Signum: '<S105>/Sign'
   */
  rtb_a = rtb_Saturation1_idx_0 - Controller_ConstB.d;

  /* Signum: '<S105>/Sign1' */
  if (rtb_Add3_c < 0.0F) {
    rtb_Add3_c = -1.0F;
  } else {
    if (rtb_Add3_c > 0.0F) {
      rtb_Add3_c = 1.0F;
    }
  }

  /* Signum: '<S105>/Sign2' */
  if (rtb_a < 0.0F) {
    rtb_a = -1.0F;
  } else {
    if (rtb_a > 0.0F) {
      rtb_a = 1.0F;
    }
  }

  /* Sum: '<S105>/Add2' incorporates:
   *  Gain: '<S105>/Gain2'
   *  Product: '<S105>/Multiply4'
   *  Signum: '<S105>/Sign'
   *  Sum: '<S105>/Add4'
   *  Sum: '<S105>/Add5'
   *  Sum: '<S105>/Subtract2'
   */
  rtb_Saturation1_idx_0 = ((rtb_Saturation1_idx_0 - rtb_Integrator1_a) +
    rtb_att_error_B_rad_idx_0) * ((rtb_Add3_c - rtb_a) * 0.5F) +
    rtb_Integrator1_a;

  /* Signum: '<S105>/Sign' */
  if (rtb_Saturation1_idx_1 < 0.0F) {
    rtb_Integrator1_a = -1.0F;
  } else if (rtb_Saturation1_idx_1 > 0.0F) {
    rtb_Integrator1_a = 1.0F;
  } else {
    rtb_Integrator1_a = rtb_Saturation1_idx_1;
  }

  /* Sum: '<S105>/Add2' incorporates:
   *  Abs: '<S105>/Abs'
   *  Gain: '<S105>/Gain'
   *  Gain: '<S105>/Gain1'
   *  Product: '<S105>/Multiply2'
   *  Product: '<S105>/Multiply3'
   *  Signum: '<S105>/Sign'
   *  Sqrt: '<S105>/Sqrt'
   *  Sum: '<S105>/Add1'
   *  Sum: '<S105>/Subtract'
   */
  rtb_Integrator1_a = (sqrtf((8.0F * fabsf(rtb_Saturation1_idx_1) +
    Controller_ConstB.d) * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
    rtb_Integrator1_a + rtb_att_error_B_rad_idx_1;

  /* Sum: '<S105>/Add3' incorporates:
   *  Signum: '<S105>/Sign'
   */
  rtb_Add3_c = rtb_Saturation1_idx_1 + Controller_ConstB.d;

  /* Sum: '<S105>/Subtract1' incorporates:
   *  Signum: '<S105>/Sign'
   */
  rtb_a = rtb_Saturation1_idx_1 - Controller_ConstB.d;

  /* Signum: '<S105>/Sign1' */
  if (rtb_Add3_c < 0.0F) {
    rtb_Add3_c = -1.0F;
  } else {
    if (rtb_Add3_c > 0.0F) {
      rtb_Add3_c = 1.0F;
    }
  }

  /* Signum: '<S105>/Sign2' */
  if (rtb_a < 0.0F) {
    rtb_a = -1.0F;
  } else {
    if (rtb_a > 0.0F) {
      rtb_a = 1.0F;
    }
  }

  /* Sum: '<S105>/Add5' incorporates:
   *  Gain: '<S105>/Gain2'
   *  Product: '<S105>/Multiply4'
   *  Signum: '<S105>/Sign'
   *  Sum: '<S105>/Add2'
   *  Sum: '<S105>/Add4'
   *  Sum: '<S105>/Subtract2'
   */
  rtb_Integrator1_a += ((rtb_Saturation1_idx_1 - rtb_Integrator1_a) +
                        rtb_att_error_B_rad_idx_1) * ((rtb_Add3_c - rtb_a) *
    0.5F);

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

  /* Product: '<S119>/Multiply1' incorporates:
   *  Constant: '<S119>/const1'
   *  DiscreteIntegrator: '<S118>/Integrator'
   */
  rtb_Add3_c = Controller_DW.Integrator_DSTATE_p * 0.05F;

  /* Sum: '<S119>/Add' incorporates:
   *  DiscreteIntegrator: '<S118>/Integrator1'
   *  Inport: '<Root>/FMS_Out'
   *  Sum: '<S118>/Subtract'
   */
  rtb_att_error_B_rad_idx_1 = (Controller_DW.Integrator1_DSTATE_p -
    Controller_U.FMS_Out.w_cmd) + rtb_Add3_c;

  /* Signum: '<S119>/Sign' */
  if (rtb_att_error_B_rad_idx_1 < 0.0F) {
    rtb_a = -1.0F;
  } else if (rtb_att_error_B_rad_idx_1 > 0.0F) {
    rtb_a = 1.0F;
  } else {
    rtb_a = rtb_att_error_B_rad_idx_1;
  }

  /* End of Signum: '<S119>/Sign' */

  /* Sum: '<S119>/Add2' incorporates:
   *  Abs: '<S119>/Abs'
   *  Gain: '<S119>/Gain'
   *  Gain: '<S119>/Gain1'
   *  Product: '<S119>/Multiply2'
   *  Product: '<S119>/Multiply3'
   *  Sqrt: '<S119>/Sqrt'
   *  Sum: '<S119>/Add1'
   *  Sum: '<S119>/Subtract'
   */
  rtb_a = (sqrtf((8.0F * fabsf(rtb_att_error_B_rad_idx_1) +
                  Controller_ConstB.d_n) * Controller_ConstB.d_n) -
           Controller_ConstB.d_n) * 0.5F * rtb_a + rtb_Add3_c;

  /* Sum: '<S119>/Add4' */
  rtb_att_error_B_rad_idx_0 = (rtb_att_error_B_rad_idx_1 - rtb_a) + rtb_Add3_c;

  /* Sum: '<S119>/Add3' */
  rtb_Add3_c = rtb_att_error_B_rad_idx_1 + Controller_ConstB.d_n;

  /* Sum: '<S119>/Subtract1' */
  rtb_att_error_B_rad_idx_1 -= Controller_ConstB.d_n;

  /* Signum: '<S119>/Sign1' */
  if (rtb_Add3_c < 0.0F) {
    rtb_Add3_c = -1.0F;
  } else {
    if (rtb_Add3_c > 0.0F) {
      rtb_Add3_c = 1.0F;
    }
  }

  /* End of Signum: '<S119>/Sign1' */

  /* Signum: '<S119>/Sign2' */
  if (rtb_att_error_B_rad_idx_1 < 0.0F) {
    rtb_att_error_B_rad_idx_1 = -1.0F;
  } else {
    if (rtb_att_error_B_rad_idx_1 > 0.0F) {
      rtb_att_error_B_rad_idx_1 = 1.0F;
    }
  }

  /* End of Signum: '<S119>/Sign2' */

  /* Sum: '<S119>/Add5' incorporates:
   *  Gain: '<S119>/Gain2'
   *  Product: '<S119>/Multiply4'
   *  Sum: '<S119>/Subtract2'
   */
  rtb_a += (rtb_Add3_c - rtb_att_error_B_rad_idx_1) * 0.5F *
    rtb_att_error_B_rad_idx_0;

  /* Update for DiscreteIntegrator: '<S107>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S109>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;

  /* Update for DiscreteIntegrator: '<S102>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S102>/Integrator'
   */
  Controller_DW.Integrator1_DSTATE[0] += 0.002F *
    Controller_DW.Integrator_DSTATE[0];

  /* Update for DiscreteIntegrator: '<S107>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S107>/ki'
   *  Product: '<S107>/Multiply'
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

  /* Update for DiscreteIntegrator: '<S109>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] += 0.002F * rtb_Gain_idx_0;

  /* Update for DiscreteIntegrator: '<S102>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S102>/Integrator'
   */
  Controller_DW.Integrator1_DSTATE[1] += 0.002F *
    Controller_DW.Integrator_DSTATE[1];

  /* Update for DiscreteIntegrator: '<S107>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S107>/ki'
   *  Product: '<S107>/Multiply'
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

  /* Update for DiscreteIntegrator: '<S109>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] += 0.002F * rtb_Gain_idx_1;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S76>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;

  /* Update for DiscreteIntegrator: '<S80>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator_PrevRe_g = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S82>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_l = 0U;

  /* Update for DiscreteIntegrator: '<S76>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S76>/Gain'
   *  Sum: '<S76>/Sum5'
   */
  Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] += (rtb_Integrator13 -
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 188.49556F * 0.002F;

  /* Update for DiscreteIntegrator: '<S80>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] += 0.002F *
    rtb_Multiply_cj_idx_0;
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

  /* Update for DiscreteIntegrator: '<S82>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[0] += 0.002F *
    rtb_Multiply2_f_idx_0;

  /* Update for DiscreteIntegrator: '<S76>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S76>/Gain'
   *  Sum: '<S76>/Sum5'
   */
  Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] += (rtb_Integrator12 -
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 188.49556F * 0.002F;

  /* Update for DiscreteIntegrator: '<S80>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] += 0.002F *
    rtb_Multiply_cj_idx_1;
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

  /* Update for DiscreteIntegrator: '<S82>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[1] += 0.002F *
    rtb_Multiply2_f_idx_1;

  /* Update for DiscreteIntegrator: '<S76>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S76>/Gain'
   *  Sum: '<S76>/Sum5'
   */
  Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] +=
    (rtb_rate_error_B_radPs_idx_2 -
     Controller_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 188.49556F * 0.002F;

  /* Update for DiscreteIntegrator: '<S80>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] += 0.002F *
    rtb_Multiply_cj_idx_2;
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

  /* Update for DiscreteIntegrator: '<S82>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[2] += 0.002F *
    rtb_DiscreteTimeIntegrator_h;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_i = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S78>/Integrator1 1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.Integrator11_DSTATE += 0.002F * rtb_adrc_z1_idx_0;
  if (Controller_DW.Integrator11_DSTATE >= 60.0F) {
    Controller_DW.Integrator11_DSTATE = 60.0F;
  } else {
    if (Controller_DW.Integrator11_DSTATE <= -60.0F) {
      Controller_DW.Integrator11_DSTATE = -60.0F;
    }
  }

  Controller_DW.Integrator11_PrevResetState = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* End of Update for DiscreteIntegrator: '<S78>/Integrator1 1' */

  /* Update for DiscreteIntegrator: '<S78>/Integrator1 2' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.Integrator12_DSTATE += 0.002F * rtb_adrc_z1_idx_1;
  if (Controller_DW.Integrator12_DSTATE >= 60.0F) {
    Controller_DW.Integrator12_DSTATE = 60.0F;
  } else {
    if (Controller_DW.Integrator12_DSTATE <= -60.0F) {
      Controller_DW.Integrator12_DSTATE = -60.0F;
    }
  }

  Controller_DW.Integrator12_PrevResetState = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* End of Update for DiscreteIntegrator: '<S78>/Integrator1 2' */

  /* Update for DiscreteIntegrator: '<S78>/Integrator1 3' incorporates:
   *  Constant: '<S78>/Constant2'
   *  Gain: '<S78>/Gain'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S78>/Multiply'
   */
  Controller_DW.Integrator13_DSTATE += -(rtb_adrc_z1_idx_2 *
    CONTROL_PARAM.LADRC_YAW_BETA2) * 0.002F;
  if (Controller_DW.Integrator13_DSTATE >= 100.0F) {
    Controller_DW.Integrator13_DSTATE = 100.0F;
  } else {
    if (Controller_DW.Integrator13_DSTATE <= -100.0F) {
      Controller_DW.Integrator13_DSTATE = -100.0F;
    }
  }

  Controller_DW.Integrator13_PrevResetState = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* End of Update for DiscreteIntegrator: '<S78>/Integrator1 3' */

  /* Update for DiscreteIntegrator: '<S118>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S118>/Integrator'
   */
  Controller_DW.Integrator1_DSTATE_p += 0.002F *
    Controller_DW.Integrator_DSTATE_p;

  /* Update for DiscreteIntegrator: '<S121>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S121>/ki'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S121>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_m += CONTROL_PARAM.VEL_Z_I *
    rtb_Gain_f * 0.002F;
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

  /* End of Update for DiscreteIntegrator: '<S121>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S123>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_k = 0U;
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_h += 0.002F * rtb_Gain_hb0;
  Controller_DW.DiscreteTimeIntegrator1_Prev_iy = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S77>/Integrator1 ' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.Integrator1_IC_LOADING = 0U;
  Controller_DW.Integrator1_DSTATE_a[0] += 0.002F * rtb_Z1_dot_idx_0;
  Controller_DW.Integrator1_DSTATE_a[1] += 0.002F * rtb_Z1_dot_idx_1;
  Controller_DW.Integrator1_DSTATE_a[2] += 0.002F * rtb_Z1_dot_idx_2;
  Controller_DW.Integrator1_PrevResetState = (int8_T)(Controller_U.FMS_Out.reset
    > 0);

  /* Signum: '<S105>/Sign3' incorporates:
   *  Product: '<S105>/Divide'
   *  Sum: '<S105>/Add6'
   */
  rtb_Add3_c = rtb_Saturation1_idx_0 + Controller_ConstB.d;

  /* Signum: '<S105>/Sign4' incorporates:
   *  Product: '<S105>/Divide'
   *  Sum: '<S105>/Subtract3'
   */
  rtb_uv_error_C_mPs_idx_0 = rtb_Saturation1_idx_0 - Controller_ConstB.d;

  /* Signum: '<S105>/Sign5' incorporates:
   *  Product: '<S105>/Divide'
   */
  if (rtb_Saturation1_idx_0 < 0.0F) {
    rtb_uv_error_C_mPs_idx_1 = -1.0F;
  } else if (rtb_Saturation1_idx_0 > 0.0F) {
    rtb_uv_error_C_mPs_idx_1 = 1.0F;
  } else {
    rtb_uv_error_C_mPs_idx_1 = rtb_Saturation1_idx_0;
  }

  /* Signum: '<S105>/Sign3' */
  if (rtb_Add3_c < 0.0F) {
    rtb_Add3_c = -1.0F;
  } else {
    if (rtb_Add3_c > 0.0F) {
      rtb_Add3_c = 1.0F;
    }
  }

  /* Signum: '<S105>/Sign4' */
  if (rtb_uv_error_C_mPs_idx_0 < 0.0F) {
    rtb_uv_error_C_mPs_idx_0 = -1.0F;
  } else {
    if (rtb_uv_error_C_mPs_idx_0 > 0.0F) {
      rtb_uv_error_C_mPs_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S105>/Sign6' incorporates:
   *  Product: '<S105>/Divide'
   */
  if (rtb_Saturation1_idx_0 < 0.0F) {
    rtb_Gain_idx_0 = -1.0F;
  } else if (rtb_Saturation1_idx_0 > 0.0F) {
    rtb_Gain_idx_0 = 1.0F;
  } else {
    rtb_Gain_idx_0 = rtb_Saturation1_idx_0;
  }

  /* Update for DiscreteIntegrator: '<S102>/Integrator' incorporates:
   *  Constant: '<S105>/const'
   *  Gain: '<S105>/Gain3'
   *  Product: '<S105>/Divide'
   *  Product: '<S105>/Multiply5'
   *  Product: '<S105>/Multiply6'
   *  Sum: '<S105>/Subtract4'
   *  Sum: '<S105>/Subtract5'
   *  Sum: '<S105>/Subtract6'
   */
  Controller_DW.Integrator_DSTATE[0] += ((rtb_Saturation1_idx_0 /
    Controller_ConstB.d - rtb_uv_error_C_mPs_idx_1) * Controller_ConstB.Gain4 *
    ((rtb_Add3_c - rtb_uv_error_C_mPs_idx_0) * 0.5F) - rtb_Gain_idx_0 * 58.836F)
    * 0.002F;

  /* Signum: '<S105>/Sign3' incorporates:
   *  Sum: '<S105>/Add6'
   */
  rtb_Add3_c = rtb_Integrator1_a + Controller_ConstB.d;

  /* Signum: '<S105>/Sign4' incorporates:
   *  Sum: '<S105>/Subtract3'
   */
  rtb_uv_error_C_mPs_idx_0 = rtb_Integrator1_a - Controller_ConstB.d;

  /* Signum: '<S105>/Sign5' */
  if (rtb_Integrator1_a < 0.0F) {
    rtb_uv_error_C_mPs_idx_1 = -1.0F;
  } else if (rtb_Integrator1_a > 0.0F) {
    rtb_uv_error_C_mPs_idx_1 = 1.0F;
  } else {
    rtb_uv_error_C_mPs_idx_1 = rtb_Integrator1_a;
  }

  /* Signum: '<S105>/Sign3' */
  if (rtb_Add3_c < 0.0F) {
    rtb_Add3_c = -1.0F;
  } else {
    if (rtb_Add3_c > 0.0F) {
      rtb_Add3_c = 1.0F;
    }
  }

  /* Signum: '<S105>/Sign4' */
  if (rtb_uv_error_C_mPs_idx_0 < 0.0F) {
    rtb_uv_error_C_mPs_idx_0 = -1.0F;
  } else {
    if (rtb_uv_error_C_mPs_idx_0 > 0.0F) {
      rtb_uv_error_C_mPs_idx_0 = 1.0F;
    }
  }

  /* Signum: '<S105>/Sign6' */
  if (rtb_Integrator1_a < 0.0F) {
    rtb_Gain_idx_0 = -1.0F;
  } else if (rtb_Integrator1_a > 0.0F) {
    rtb_Gain_idx_0 = 1.0F;
  } else {
    rtb_Gain_idx_0 = rtb_Integrator1_a;
  }

  /* Update for DiscreteIntegrator: '<S102>/Integrator' incorporates:
   *  Constant: '<S105>/const'
   *  Gain: '<S105>/Gain3'
   *  Product: '<S105>/Divide'
   *  Product: '<S105>/Multiply5'
   *  Product: '<S105>/Multiply6'
   *  Sum: '<S105>/Subtract4'
   *  Sum: '<S105>/Subtract5'
   *  Sum: '<S105>/Subtract6'
   */
  Controller_DW.Integrator_DSTATE[1] += ((rtb_Integrator1_a /
    Controller_ConstB.d - rtb_uv_error_C_mPs_idx_1) * Controller_ConstB.Gain4 *
    ((rtb_Add3_c - rtb_uv_error_C_mPs_idx_0) * 0.5F) - rtb_Gain_idx_0 * 58.836F)
    * 0.002F;

  /* Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S3>/Constant'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_n += CONTROL_EXPORT.period;

  /* Signum: '<S119>/Sign6' incorporates:
   *  Signum: '<S119>/Sign5'
   */
  if (rtb_a < 0.0F) {
    rtb_uv_error_C_mPs_idx_1 = -1.0F;

    /* Signum: '<S119>/Sign5' */
    rtb_Gain_idx_0 = -1.0F;
  } else if (rtb_a > 0.0F) {
    rtb_uv_error_C_mPs_idx_1 = 1.0F;

    /* Signum: '<S119>/Sign5' */
    rtb_Gain_idx_0 = 1.0F;
  } else {
    rtb_uv_error_C_mPs_idx_1 = rtb_a;

    /* Signum: '<S119>/Sign5' */
    rtb_Gain_idx_0 = rtb_a;
  }

  /* End of Signum: '<S119>/Sign6' */

  /* Sum: '<S119>/Add6' */
  rtb_Add3_c = rtb_a + Controller_ConstB.d_n;

  /* Sum: '<S119>/Subtract3' */
  rtb_uv_error_C_mPs_idx_0 = rtb_a - Controller_ConstB.d_n;

  /* Signum: '<S119>/Sign3' */
  if (rtb_Add3_c < 0.0F) {
    rtb_Add3_c = -1.0F;
  } else {
    if (rtb_Add3_c > 0.0F) {
      rtb_Add3_c = 1.0F;
    }
  }

  /* End of Signum: '<S119>/Sign3' */

  /* Signum: '<S119>/Sign4' */
  if (rtb_uv_error_C_mPs_idx_0 < 0.0F) {
    rtb_uv_error_C_mPs_idx_0 = -1.0F;
  } else {
    if (rtb_uv_error_C_mPs_idx_0 > 0.0F) {
      rtb_uv_error_C_mPs_idx_0 = 1.0F;
    }
  }

  /* End of Signum: '<S119>/Sign4' */

  /* Update for DiscreteIntegrator: '<S118>/Integrator' incorporates:
   *  Constant: '<S119>/const'
   *  Gain: '<S119>/Gain3'
   *  Product: '<S119>/Divide'
   *  Product: '<S119>/Multiply5'
   *  Product: '<S119>/Multiply6'
   *  Sum: '<S119>/Subtract4'
   *  Sum: '<S119>/Subtract5'
   *  Sum: '<S119>/Subtract6'
   */
  Controller_DW.Integrator_DSTATE_p += ((rtb_a / Controller_ConstB.d_n -
    rtb_Gain_idx_0) * Controller_ConstB.Gain4_k * ((rtb_Add3_c -
    rtb_uv_error_C_mPs_idx_0) * 0.5F) - rtb_uv_error_C_mPs_idx_1 * 78.448F) *
    0.002F;
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

  /* Start for Constant: '<S121>/Constant' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_m = CONTROL_PARAM.VEL_Z_I_MIN;

  /* InitializeConditions for DiscreteIntegrator: '<S107>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S107>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S109>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S76>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S80>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S80>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S82>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_l = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_i = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S78>/Integrator1 1' */
  Controller_DW.Integrator11_PrevResetState = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S78>/Integrator1 2' */
  Controller_DW.Integrator12_PrevResetState = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S78>/Integrator1 3' */
  Controller_DW.Integrator13_PrevResetState = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S121>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S121>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S123>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_k = 1U;
  Controller_DW.DiscreteTimeIntegrator1_Prev_iy = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S77>/Integrator1 ' */
  Controller_DW.Integrator1_IC_LOADING = 1U;
  Controller_DW.Integrator1_PrevResetState = 0;
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
