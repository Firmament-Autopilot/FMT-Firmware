/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.903
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Oct 12 14:06:21 2022
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
struct_Ae52N6uY2eO0jd5TMQiCYB CONTROL_PARAM = {
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
  3.14159274F
} ;                                    /* Variable: CONTROL_PARAM
                                        * Referenced by:
                                        *   '<S37>/Saturation'
                                        *   '<S13>/Saturation'
                                        *   '<S13>/Saturation1'
                                        *   '<S46>/kd'
                                        *   '<S46>/Saturation'
                                        *   '<S47>/ki'
                                        *   '<S47>/Discrete-Time Integrator'
                                        *   '<S48>/kp'
                                        *   '<S65>/kd'
                                        *   '<S65>/Saturation'
                                        *   '<S66>/ki'
                                        *   '<S66>/Discrete-Time Integrator'
                                        *   '<S67>/kp'
                                        *   '<S30>/Constant1'
                                        *   '<S30>/Constant2'
                                        *   '<S19>/gain1'
                                        *   '<S19>/gain2'
                                        *   '<S19>/gain3'
                                        *   '<S19>/Saturation'
                                        *   '<S20>/gain1'
                                        *   '<S20>/gain2'
                                        *   '<S20>/gain3'
                                        *   '<S20>/Discrete-Time Integrator'
                                        *   '<S21>/gain1'
                                        *   '<S21>/gain2'
                                        *   '<S21>/gain3'
                                        */

struct_biZzOMrg0u3lxrb7POOubF CONTROL_EXPORT = {
  2U,

  { 66, 97, 115, 101, 32, 67, 111, 110, 116, 114, 111, 108, 108, 101, 114, 32,
    118, 48, 46, 50, 46, 52, 0 }
} ;                                    /* Variable: CONTROL_EXPORT
                                        * Referenced by: '<S4>/Constant'
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
  real32_T rtb_Gain_f;
  real32_T rtb_Gain;
  real32_T rtb_Saturation_m;
  real32_T rtb_Multiply4_b;
  real32_T rtb_Add;
  int32_T rtb_DiscreteTimeIntegrator;
  real32_T rtb_VectorConcatenate[9];
  real32_T rtb_a;
  real32_T rtb_Add3;
  uint16_T rtb_throttle_cmd;
  real32_T rtb_VectorConcatenate_0[3];
  int32_T i;
  real32_T rtb_Subtract3_i_idx_0;
  real32_T rtb_Subtract3_i_idx_1;
  real32_T rtb_a_n_idx_0;
  real32_T rtb_a_n_idx_1;
  real32_T rtb_DiscreteTimeIntegrator1_b_i;
  real32_T rtb_DiscreteTimeIntegrator1_b_0;
  real32_T rtb_Saturation_idx_1;
  real32_T rtb_rate_error_B_radPs_idx_0;
  real32_T rtb_rate_error_B_radPs_idx_2;
  real32_T rtb_Saturation_d_idx_0;
  real32_T rtb_Saturation_d_idx_1;
  real32_T rtb_Saturation_d_idx_2;
  real32_T rtb_uv_error_C_mPs_idx_1;
  real32_T rtb_Gain_j_idx_0;
  real32_T rtb_Gain_j_idx_1;
  uint16_T u0;

  /* Gain: '<S61>/Gain' incorporates:
   *  DiscreteIntegrator: '<S63>/Integrator1'
   *  Inport: '<Root>/INS_Out'
   *  Sum: '<S61>/Sum1'
   */
  rtb_Gain_f = -(Controller_DW.Integrator1_DSTATE - Controller_U.INS_Out.vd);

  /* DiscreteIntegrator: '<S66>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator_PrevRese != 0)) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE = Controller_ConstB.Constant;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE >= CONTROL_PARAM.VEL_Z_I_MAX)
    {
      Controller_DW.DiscreteTimeIntegrator_DSTATE = CONTROL_PARAM.VEL_Z_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE <=
          CONTROL_PARAM.VEL_Z_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE = CONTROL_PARAM.VEL_Z_I_MIN;
      }
    }
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE >= CONTROL_PARAM.VEL_Z_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE = CONTROL_PARAM.VEL_Z_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE <= CONTROL_PARAM.VEL_Z_I_MIN)
    {
      Controller_DW.DiscreteTimeIntegrator_DSTATE = CONTROL_PARAM.VEL_Z_I_MIN;
    }
  }

  /* DiscreteIntegrator: '<S68>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevRes != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTATE = 0.0F;
  }

  /* Gain: '<S68>/Gain' incorporates:
   *  DiscreteIntegrator: '<S68>/Discrete-Time Integrator1'
   *  Sum: '<S68>/Sum5'
   */
  rtb_Gain = (rtb_Gain_f - Controller_DW.DiscreteTimeIntegrator1_DSTATE) *
    62.831852F;

  /* Switch: '<S68>/Switch' incorporates:
   *  Gain: '<S68>/Gain1'
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_U.FMS_Out.reset > 0) {
    rtb_a_n_idx_0 = 0.0F;
  } else {
    rtb_a_n_idx_0 = rtb_Gain;
  }

  /* End of Switch: '<S68>/Switch' */

  /* Product: '<S65>/Multiply' incorporates:
   *  Constant: '<S65>/kd'
   */
  rtb_Saturation_m = CONTROL_PARAM.VEL_Z_D * rtb_a_n_idx_0;

  /* Saturate: '<S65>/Saturation' */
  if (rtb_Saturation_m > CONTROL_PARAM.VEL_Z_D_MAX) {
    rtb_Saturation_m = CONTROL_PARAM.VEL_Z_D_MAX;
  } else {
    if (rtb_Saturation_m < CONTROL_PARAM.VEL_Z_D_MIN) {
      rtb_Saturation_m = CONTROL_PARAM.VEL_Z_D_MIN;
    }
  }

  /* End of Saturate: '<S65>/Saturation' */

  /* Sum: '<S62>/Add' incorporates:
   *  Constant: '<S67>/kp'
   *  DiscreteIntegrator: '<S66>/Discrete-Time Integrator'
   *  Product: '<S67>/Multiply'
   */
  rtb_Add = (CONTROL_PARAM.VEL_Z_P * rtb_Gain_f +
             Controller_DW.DiscreteTimeIntegrator_DSTATE) + rtb_Saturation_m;

  /* Trigonometry: '<S60>/Cos1' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S23>/Cos1'
   */
  rtb_DiscreteTimeIntegrator1_b_0 = arm_cos_f32(Controller_U.INS_Out.theta);

  /* Trigonometry: '<S60>/Cos' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S23>/Cos'
   */
  rtb_rate_error_B_radPs_idx_0 = arm_cos_f32(Controller_U.INS_Out.phi);

  /* Product: '<S60>/Multiply' incorporates:
   *  Trigonometry: '<S60>/Cos'
   *  Trigonometry: '<S60>/Cos1'
   */
  rtb_Saturation_m = rtb_rate_error_B_radPs_idx_0 *
    rtb_DiscreteTimeIntegrator1_b_0;

  /* Saturate: '<S60>/Saturation1' */
  if (rtb_Saturation_m > 1.0F) {
    rtb_Multiply4_b = 1.0F;
  } else if (rtb_Saturation_m < 0.5F) {
    rtb_Multiply4_b = 0.5F;
  } else {
    rtb_Multiply4_b = rtb_Saturation_m;
  }

  /* End of Saturate: '<S60>/Saturation1' */

  /* Gain: '<S60>/Gain' */
  rtb_Saturation_m *= 2.0F;

  /* Saturate: '<S60>/Saturation' */
  if (rtb_Saturation_m > 1.0F) {
    rtb_Saturation_m = 1.0F;
  } else {
    if (rtb_Saturation_m < 0.0F) {
      rtb_Saturation_m = 0.0F;
    }
  }

  /* End of Saturate: '<S60>/Saturation' */

  /* Product: '<S60>/Multiply1' incorporates:
   *  Constant: '<S60>/Constant'
   *  Product: '<S60>/Divide'
   */
  rtb_Saturation_m *= 1.0F / rtb_Multiply4_b * rtb_Add;

  /* Saturate: '<S59>/Saturation' */
  if (rtb_Saturation_m > 0.35F) {
    rtb_Saturation_m = 0.35F;
  } else {
    if (rtb_Saturation_m < -0.35F) {
      rtb_Saturation_m = -0.35F;
    }
  }

  /* End of Saturate: '<S59>/Saturation' */

  /* Sum: '<S55>/Sum' incorporates:
   *  Constant: '<S55>/hover_throttle'
   */
  rtb_Saturation_m += 0.5F;

  /* Sum: '<S55>/Sum1' incorporates:
   *  Constant: '<S55>/Constant1'
   *  Gain: '<S55>/Gain1'
   */
  rtb_DiscreteTimeIntegrator = (int32_T)((uint32_T)fmodf(floorf(1000.0F *
    rtb_Saturation_m), 4.2949673E+9F) + 1000U);

  /* Trigonometry: '<S44>/Trigonometric Function1' incorporates:
   *  Gain: '<S43>/Gain'
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S44>/Trigonometric Function3'
   */
  rtb_Add = arm_cos_f32(-Controller_U.INS_Out.psi);
  rtb_VectorConcatenate[0] = rtb_Add;

  /* Trigonometry: '<S44>/Trigonometric Function' incorporates:
   *  Gain: '<S43>/Gain'
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S44>/Trigonometric Function2'
   */
  rtb_uv_error_C_mPs_idx_1 = arm_sin_f32(-Controller_U.INS_Out.psi);
  rtb_VectorConcatenate[1] = rtb_uv_error_C_mPs_idx_1;

  /* SignalConversion: '<S44>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S44>/Constant3'
   */
  rtb_VectorConcatenate[2] = 0.0F;

  /* Gain: '<S44>/Gain' */
  rtb_VectorConcatenate[3] = -rtb_uv_error_C_mPs_idx_1;

  /* Trigonometry: '<S44>/Trigonometric Function3' */
  rtb_VectorConcatenate[4] = rtb_Add;

  /* SignalConversion: '<S44>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S44>/Constant4'
   */
  rtb_VectorConcatenate[5] = 0.0F;

  /* SignalConversion: '<S44>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate[6] = Controller_ConstB.VectorConcatenate3[0];
  rtb_VectorConcatenate[7] = Controller_ConstB.VectorConcatenate3[1];
  rtb_VectorConcatenate[8] = Controller_ConstB.VectorConcatenate3[2];

  /* Product: '<S41>/Multiply' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  SignalConversion: '<S41>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_0[i] = rtb_VectorConcatenate[i + 3] *
      Controller_U.INS_Out.ve + rtb_VectorConcatenate[i] *
      Controller_U.INS_Out.vn;
  }

  /* End of Product: '<S41>/Multiply' */

  /* Sum: '<S38>/Sum' incorporates:
   *  DiscreteIntegrator: '<S42>/Integrator1'
   */
  rtb_Add = Controller_DW.Integrator1_DSTATE_g[0] - rtb_VectorConcatenate_0[0];
  rtb_uv_error_C_mPs_idx_1 = Controller_DW.Integrator1_DSTATE_g[1] -
    rtb_VectorConcatenate_0[1];

  /* DiscreteIntegrator: '<S47>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator_PrevRe_e != 0)) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
      Controller_ConstB.Constant_g;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] >=
        CONTROL_PARAM.VEL_XY_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
        CONTROL_PARAM.VEL_XY_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] <=
          CONTROL_PARAM.VEL_XY_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
          CONTROL_PARAM.VEL_XY_I_MIN;
      }
    }

    Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
      Controller_ConstB.Constant_g;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] >=
        CONTROL_PARAM.VEL_XY_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
        CONTROL_PARAM.VEL_XY_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] <=
          CONTROL_PARAM.VEL_XY_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
          CONTROL_PARAM.VEL_XY_I_MIN;
      }
    }
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] >=
      CONTROL_PARAM.VEL_XY_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
      CONTROL_PARAM.VEL_XY_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] <=
        CONTROL_PARAM.VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
        CONTROL_PARAM.VEL_XY_I_MIN;
    }
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] >=
      CONTROL_PARAM.VEL_XY_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
      CONTROL_PARAM.VEL_XY_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] <=
        CONTROL_PARAM.VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
        CONTROL_PARAM.VEL_XY_I_MIN;
    }
  }

  /* DiscreteIntegrator: '<S49>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevR_a != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[0] = 0.0F;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[1] = 0.0F;
  }

  /* Gain: '<S49>/Gain' incorporates:
   *  DiscreteIntegrator: '<S49>/Discrete-Time Integrator1'
   *  Sum: '<S49>/Sum5'
   */
  rtb_Gain_j_idx_0 = (rtb_Add - Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[0])
    * 62.831852F;
  rtb_Gain_j_idx_1 = (rtb_uv_error_C_mPs_idx_1 -
                      Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[1]) *
    62.831852F;

  /* Switch: '<S49>/Switch' incorporates:
   *  Gain: '<S49>/Gain1'
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_U.FMS_Out.reset > 0) {
    rtb_a_n_idx_0 = 0.0F;
    rtb_a_n_idx_1 = 0.0F;
  } else {
    rtb_a_n_idx_0 = rtb_Gain_j_idx_0;
    rtb_a_n_idx_1 = rtb_Gain_j_idx_1;
  }

  /* End of Switch: '<S49>/Switch' */

  /* Product: '<S46>/Multiply' incorporates:
   *  Constant: '<S46>/kd'
   */
  rtb_Saturation_m = CONTROL_PARAM.VEL_XY_D * rtb_a_n_idx_0;

  /* Saturate: '<S46>/Saturation' */
  if (rtb_Saturation_m > CONTROL_PARAM.VEL_XY_D_MAX) {
    rtb_Saturation_m = CONTROL_PARAM.VEL_XY_D_MAX;
  } else {
    if (rtb_Saturation_m < CONTROL_PARAM.VEL_XY_D_MIN) {
      rtb_Saturation_m = CONTROL_PARAM.VEL_XY_D_MIN;
    }
  }

  /* Product: '<S46>/Multiply' incorporates:
   *  Constant: '<S46>/kd'
   */
  rtb_a_n_idx_0 = rtb_Saturation_m;
  rtb_Saturation_m = CONTROL_PARAM.VEL_XY_D * rtb_a_n_idx_1;

  /* Saturate: '<S46>/Saturation' */
  if (rtb_Saturation_m > CONTROL_PARAM.VEL_XY_D_MAX) {
    rtb_Saturation_m = CONTROL_PARAM.VEL_XY_D_MAX;
  } else {
    if (rtb_Saturation_m < CONTROL_PARAM.VEL_XY_D_MIN) {
      rtb_Saturation_m = CONTROL_PARAM.VEL_XY_D_MIN;
    }
  }

  /* Switch: '<S40>/Switch' incorporates:
   *  Constant: '<S48>/kp'
   *  Constant: '<S50>/Constant'
   *  Constant: '<S52>/Constant'
   *  Constant: '<S53>/Constant'
   *  DiscreteIntegrator: '<S47>/Discrete-Time Integrator'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S48>/Multiply'
   *  Product: '<S51>/Multiply2'
   *  Product: '<S51>/Multiply3'
   *  RelationalOperator: '<S50>/Compare'
   *  RelationalOperator: '<S52>/Compare'
   *  RelationalOperator: '<S53>/Compare'
   *  S-Function (sfix_bitop): '<S51>/cmd_ax valid'
   *  S-Function (sfix_bitop): '<S51>/cmd_ay valid'
   *  S-Function (sfix_bitop): '<S51>/cmd_u valid'
   *  S-Function (sfix_bitop): '<S51>/cmd_v valid'
   *  Sum: '<S39>/Add'
   *  Sum: '<S51>/Sum1'
   */
  if (Controller_U.FMS_Out.ctrl_mode == 6) {
    rtb_a_n_idx_0 = ((Controller_U.FMS_Out.cmd_mask & 64) > 0 ?
                     (CONTROL_PARAM.VEL_XY_P * rtb_Add +
                      Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0]) +
                     rtb_a_n_idx_0 : 0.0F) + ((Controller_U.FMS_Out.cmd_mask &
      512) > 0 ? Controller_U.FMS_Out.ax_cmd : 0.0F);
    rtb_a_n_idx_1 = ((Controller_U.FMS_Out.cmd_mask & 128) > 0 ?
                     (CONTROL_PARAM.VEL_XY_P * rtb_uv_error_C_mPs_idx_1 +
                      Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1]) +
                     rtb_Saturation_m : 0.0F) + ((Controller_U.FMS_Out.cmd_mask
      & 1024) > 0 ? Controller_U.FMS_Out.ay_cmd : 0.0F);
  } else {
    rtb_a_n_idx_0 += CONTROL_PARAM.VEL_XY_P * rtb_Add +
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0];
    rtb_a_n_idx_1 = (CONTROL_PARAM.VEL_XY_P * rtb_uv_error_C_mPs_idx_1 +
                     Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1]) +
      rtb_Saturation_m;
  }

  /* End of Switch: '<S40>/Switch' */

  /* Trigonometry: '<S37>/Atan' incorporates:
   *  Constant: '<S37>/g'
   *  Gain: '<S37>/Gain1'
   *  Gain: '<S37>/gain'
   *  Product: '<S37>/Divide'
   */
  rtb_Saturation_m = atanf(1.1F * rtb_a_n_idx_1 / 9.8055F);
  rtb_a_n_idx_1 = atanf(1.1F * -rtb_a_n_idx_0 / 9.8055F);

  /* Switch: '<S28>/Switch' incorporates:
   *  Constant: '<S35>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  Logic: '<S28>/Logical Operator'
   *  RelationalOperator: '<S34>/Compare'
   *  RelationalOperator: '<S35>/Compare'
   *  Saturate: '<S37>/Saturation'
   *  Switch: '<S28>/Switch1'
   */
  if ((Controller_U.FMS_Out.ctrl_mode == 3) || (Controller_U.FMS_Out.ctrl_mode ==
       4)) {
    rtb_a_n_idx_0 = Controller_U.FMS_Out.phi_cmd;
    rtb_a_n_idx_1 = Controller_U.FMS_Out.theta_cmd;
  } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
    /* Switch: '<S36>/Switch' incorporates:
     *  S-Function (sfix_bitop): '<S36>/cmd_phi valid'
     *  S-Function (sfix_bitop): '<S36>/cmd_theta valid'
     *  Saturate: '<S37>/Saturation'
     *  Switch: '<S28>/Switch1'
     */
    if ((Controller_U.FMS_Out.cmd_mask & 8) > 0) {
      rtb_a_n_idx_0 = Controller_U.FMS_Out.phi_cmd;
    } else if (rtb_Saturation_m > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      /* Saturate: '<S37>/Saturation' */
      rtb_a_n_idx_0 = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    } else if (rtb_Saturation_m < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      /* Saturate: '<S37>/Saturation' */
      rtb_a_n_idx_0 = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    } else {
      rtb_a_n_idx_0 = rtb_Saturation_m;
    }

    if ((Controller_U.FMS_Out.cmd_mask & 16) > 0) {
      rtb_a_n_idx_1 = Controller_U.FMS_Out.theta_cmd;
    } else if (rtb_a_n_idx_1 > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      /* Saturate: '<S37>/Saturation' */
      rtb_a_n_idx_1 = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_a_n_idx_1 < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S37>/Saturation' */
        rtb_a_n_idx_1 = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
      }
    }

    /* End of Switch: '<S36>/Switch' */
  } else {
    if (rtb_Saturation_m > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      /* Saturate: '<S37>/Saturation' incorporates:
       *  Switch: '<S28>/Switch1'
       */
      rtb_a_n_idx_0 = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    } else if (rtb_Saturation_m < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      /* Saturate: '<S37>/Saturation' incorporates:
       *  Switch: '<S28>/Switch1'
       */
      rtb_a_n_idx_0 = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    } else {
      /* Switch: '<S28>/Switch1' incorporates:
       *  Saturate: '<S37>/Saturation'
       */
      rtb_a_n_idx_0 = rtb_Saturation_m;
    }

    /* Saturate: '<S37>/Saturation' */
    if (rtb_a_n_idx_1 > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      /* Switch: '<S28>/Switch1' */
      rtb_a_n_idx_1 = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_a_n_idx_1 < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
        /* Switch: '<S28>/Switch1' */
        rtb_a_n_idx_1 = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
      }
    }
  }

  /* End of Switch: '<S28>/Switch' */

  /* Sum: '<S29>/Sum' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Saturation_m = rtb_a_n_idx_0 - Controller_U.INS_Out.phi;

  /* Product: '<S32>/Divide1' incorporates:
   *  Abs: '<S32>/Abs'
   *  Constant: '<S32>/const2'
   */
  rtb_DiscreteTimeIntegrator1_b_i = fabsf(rtb_Saturation_m) / 0.002F;

  /* Product: '<S32>/Divide' incorporates:
   *  Constant: '<S30>/Constant1'
   *  Constant: '<S32>/const1'
   *  Math: '<S32>/Square'
   *  SignalConversion: '<S32>/TmpSignal ConversionAtSquareInport1'
   */
  rtb_a = 9.5993F / (CONTROL_PARAM.ROLL_P * CONTROL_PARAM.ROLL_P);

  /* Signum: '<S32>/Sign' */
  if (rtb_Saturation_m < 0.0F) {
    rtb_Multiply4_b = -1.0F;
  } else if (rtb_Saturation_m > 0.0F) {
    rtb_Multiply4_b = 1.0F;
  } else {
    rtb_Multiply4_b = rtb_Saturation_m;
  }

  /* Switch: '<S32>/Switch' incorporates:
   *  Constant: '<S30>/Constant1'
   *  Gain: '<S32>/Gain1'
   *  Gain: '<S32>/Gain2'
   *  Logic: '<S32>/Logical Operator'
   *  Product: '<S32>/Multiply'
   *  Product: '<S32>/Multiply1'
   *  Product: '<S32>/Multiply2'
   *  Product: '<S32>/Multiply3'
   *  RelationalOperator: '<S32>/Relational Operator'
   *  RelationalOperator: '<S32>/Relational Operator2'
   *  SignalConversion: '<S32>/TmpSignal ConversionAtSquareInport1'
   *  Sqrt: '<S32>/Sqrt'
   *  Sum: '<S32>/Subtract'
   */
  if ((rtb_Saturation_m <= rtb_a) && (rtb_Saturation_m >= -rtb_a)) {
    rtb_Multiply4_b = rtb_Saturation_m * CONTROL_PARAM.ROLL_P;
  } else {
    rtb_Multiply4_b *= sqrtf((rtb_Multiply4_b * rtb_Saturation_m - 0.5F * rtb_a)
      * Controller_ConstB.Gain);
  }

  /* Gain: '<S32>/Gain3' */
  rtb_a = -rtb_DiscreteTimeIntegrator1_b_i;

  /* Switch: '<S33>/Switch' incorporates:
   *  Gain: '<S32>/Gain3'
   *  RelationalOperator: '<S33>/UpperRelop'
   */
  if (rtb_Multiply4_b >= -rtb_DiscreteTimeIntegrator1_b_i) {
    rtb_a = rtb_Multiply4_b;
  }

  /* Switch: '<S33>/Switch2' incorporates:
   *  RelationalOperator: '<S33>/LowerRelop1'
   */
  if (rtb_Multiply4_b <= rtb_DiscreteTimeIntegrator1_b_i) {
    rtb_DiscreteTimeIntegrator1_b_i = rtb_a;
  }

  /* Saturate: '<S13>/Saturation1' */
  if (rtb_DiscreteTimeIntegrator1_b_i > CONTROL_PARAM.P_Q_CMD_LIM) {
    rtb_DiscreteTimeIntegrator1_b_i = CONTROL_PARAM.P_Q_CMD_LIM;
  } else {
    if (rtb_DiscreteTimeIntegrator1_b_i < -CONTROL_PARAM.P_Q_CMD_LIM) {
      rtb_DiscreteTimeIntegrator1_b_i = -CONTROL_PARAM.P_Q_CMD_LIM;
    }
  }

  /* Product: '<S32>/Divide1' */
  rtb_a_n_idx_0 = rtb_DiscreteTimeIntegrator1_b_i;

  /* Sum: '<S29>/Sum' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Saturation_m = rtb_a_n_idx_1 - Controller_U.INS_Out.theta;

  /* Product: '<S32>/Divide1' incorporates:
   *  Abs: '<S32>/Abs'
   *  Constant: '<S32>/const2'
   */
  rtb_DiscreteTimeIntegrator1_b_i = fabsf(rtb_Saturation_m) / 0.002F;

  /* Product: '<S32>/Divide' incorporates:
   *  Constant: '<S30>/Constant2'
   *  Constant: '<S32>/const1'
   *  Math: '<S32>/Square'
   *  SignalConversion: '<S32>/TmpSignal ConversionAtSquareInport1'
   */
  rtb_a = 9.5993F / (CONTROL_PARAM.PITCH_P * CONTROL_PARAM.PITCH_P);

  /* Signum: '<S32>/Sign' */
  if (rtb_Saturation_m < 0.0F) {
    rtb_Multiply4_b = -1.0F;
  } else if (rtb_Saturation_m > 0.0F) {
    rtb_Multiply4_b = 1.0F;
  } else {
    rtb_Multiply4_b = rtb_Saturation_m;
  }

  /* Switch: '<S32>/Switch' incorporates:
   *  Constant: '<S30>/Constant2'
   *  Gain: '<S32>/Gain1'
   *  Gain: '<S32>/Gain2'
   *  Logic: '<S32>/Logical Operator'
   *  Product: '<S32>/Multiply'
   *  Product: '<S32>/Multiply1'
   *  Product: '<S32>/Multiply2'
   *  Product: '<S32>/Multiply3'
   *  RelationalOperator: '<S32>/Relational Operator'
   *  RelationalOperator: '<S32>/Relational Operator2'
   *  SignalConversion: '<S32>/TmpSignal ConversionAtSquareInport1'
   *  Sqrt: '<S32>/Sqrt'
   *  Sum: '<S32>/Subtract'
   */
  if ((rtb_Saturation_m <= rtb_a) && (rtb_Saturation_m >= -rtb_a)) {
    rtb_Multiply4_b = rtb_Saturation_m * CONTROL_PARAM.PITCH_P;
  } else {
    rtb_Multiply4_b *= sqrtf((rtb_Multiply4_b * rtb_Saturation_m - 0.5F * rtb_a)
      * Controller_ConstB.Gain);
  }

  /* Gain: '<S32>/Gain3' */
  rtb_a = -rtb_DiscreteTimeIntegrator1_b_i;

  /* Switch: '<S33>/Switch' incorporates:
   *  Gain: '<S32>/Gain3'
   *  RelationalOperator: '<S33>/UpperRelop'
   */
  if (rtb_Multiply4_b >= -rtb_DiscreteTimeIntegrator1_b_i) {
    rtb_a = rtb_Multiply4_b;
  }

  /* Switch: '<S33>/Switch2' incorporates:
   *  RelationalOperator: '<S33>/LowerRelop1'
   */
  if (rtb_Multiply4_b <= rtb_DiscreteTimeIntegrator1_b_i) {
    rtb_DiscreteTimeIntegrator1_b_i = rtb_a;
  }

  /* Saturate: '<S13>/Saturation1' */
  if (rtb_DiscreteTimeIntegrator1_b_i > CONTROL_PARAM.P_Q_CMD_LIM) {
    rtb_DiscreteTimeIntegrator1_b_i = CONTROL_PARAM.P_Q_CMD_LIM;
  } else {
    if (rtb_DiscreteTimeIntegrator1_b_i < -CONTROL_PARAM.P_Q_CMD_LIM) {
      rtb_DiscreteTimeIntegrator1_b_i = -CONTROL_PARAM.P_Q_CMD_LIM;
    }
  }

  /* Saturate: '<S13>/Saturation' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_U.FMS_Out.psi_rate_cmd > CONTROL_PARAM.R_CMD_LIM) {
    rtb_Saturation_m = CONTROL_PARAM.R_CMD_LIM;
  } else if (Controller_U.FMS_Out.psi_rate_cmd < -CONTROL_PARAM.R_CMD_LIM) {
    rtb_Saturation_m = -CONTROL_PARAM.R_CMD_LIM;
  } else {
    rtb_Saturation_m = Controller_U.FMS_Out.psi_rate_cmd;
  }

  /* End of Saturate: '<S13>/Saturation' */

  /* Trigonometry: '<S23>/Sin' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Multiply4_b = arm_sin_f32(Controller_U.INS_Out.phi);

  /* Product: '<S23>/Multiply3' */
  rtb_a_n_idx_1 = rtb_Multiply4_b * rtb_DiscreteTimeIntegrator1_b_0 *
    rtb_Saturation_m;

  /* Product: '<S23>/Multiply1' */
  rtb_rate_error_B_radPs_idx_2 = rtb_rate_error_B_radPs_idx_0 *
    rtb_DiscreteTimeIntegrator1_b_i;

  /* Product: '<S23>/Multiply4' */
  rtb_Multiply4_b *= rtb_DiscreteTimeIntegrator1_b_i;

  /* Switch: '<S14>/Switch' incorporates:
   *  Constant: '<S24>/Constant'
   *  Constant: '<S25>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  RelationalOperator: '<S24>/Compare'
   *  RelationalOperator: '<S25>/Compare'
   *  Switch: '<S14>/Switch1'
   */
  if (Controller_U.FMS_Out.ctrl_mode == 2) {
    rtb_DiscreteTimeIntegrator1_b_i = Controller_U.FMS_Out.p_cmd;
    rtb_a_n_idx_1 = Controller_U.FMS_Out.q_cmd;
    rtb_DiscreteTimeIntegrator1_b_0 = Controller_U.FMS_Out.r_cmd;
  } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
    /* Switch: '<S26>/Switch' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S23>/Multiply'
     *  Product: '<S23>/Multiply1'
     *  Product: '<S23>/Multiply5'
     *  S-Function (sfix_bitop): '<S26>/cmd_p valid'
     *  S-Function (sfix_bitop): '<S26>/cmd_q valid'
     *  S-Function (sfix_bitop): '<S26>/cmd_r valid'
     *  Sum: '<S23>/Add'
     *  Sum: '<S23>/Add1'
     *  Sum: '<S23>/Add2'
     *  Switch: '<S14>/Switch1'
     *  Trigonometry: '<S23>/Sin1'
     */
    if ((Controller_U.FMS_Out.cmd_mask & 1) > 0) {
      rtb_DiscreteTimeIntegrator1_b_i = Controller_U.FMS_Out.p_cmd;
    } else {
      rtb_DiscreteTimeIntegrator1_b_i = rtb_a_n_idx_0 - arm_sin_f32
        (Controller_U.INS_Out.theta) * rtb_Saturation_m;
    }

    if ((Controller_U.FMS_Out.cmd_mask & 2) > 0) {
      rtb_a_n_idx_1 = Controller_U.FMS_Out.q_cmd;
    } else {
      rtb_a_n_idx_1 += rtb_rate_error_B_radPs_idx_2;
    }

    if ((Controller_U.FMS_Out.cmd_mask & 4) > 0) {
      rtb_DiscreteTimeIntegrator1_b_0 = Controller_U.FMS_Out.r_cmd;
    } else {
      rtb_DiscreteTimeIntegrator1_b_0 = rtb_rate_error_B_radPs_idx_0 *
        rtb_DiscreteTimeIntegrator1_b_0 * rtb_Saturation_m - rtb_Multiply4_b;
    }

    /* End of Switch: '<S26>/Switch' */
  } else {
    /* Switch: '<S14>/Switch1' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S23>/Multiply'
     *  Product: '<S23>/Multiply3'
     *  Product: '<S23>/Multiply5'
     *  Sum: '<S23>/Add'
     *  Sum: '<S23>/Add1'
     *  Sum: '<S23>/Add2'
     *  Trigonometry: '<S23>/Sin1'
     */
    rtb_DiscreteTimeIntegrator1_b_i = rtb_a_n_idx_0 - arm_sin_f32
      (Controller_U.INS_Out.theta) * rtb_Saturation_m;
    rtb_a_n_idx_1 += rtb_rate_error_B_radPs_idx_2;
    rtb_DiscreteTimeIntegrator1_b_0 = rtb_rate_error_B_radPs_idx_0 *
      rtb_DiscreteTimeIntegrator1_b_0 * rtb_Saturation_m - rtb_Multiply4_b;
  }

  /* End of Switch: '<S14>/Switch' */

  /* Sum: '<S15>/Sum' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_rate_error_B_radPs_idx_0 = rtb_DiscreteTimeIntegrator1_b_i -
    Controller_U.INS_Out.p;
  rtb_Multiply4_b = rtb_a_n_idx_1 - Controller_U.INS_Out.q;
  rtb_rate_error_B_radPs_idx_2 = rtb_DiscreteTimeIntegrator1_b_0 -
    Controller_U.INS_Out.r;

  /* DiscreteIntegrator: '<S18>/Discrete-Time Integrator5' */
  if (Controller_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] =
      rtb_rate_error_B_radPs_idx_0;
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] = rtb_Multiply4_b;
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] =
      rtb_rate_error_B_radPs_idx_2;
  }

  /* DiscreteIntegrator: '<S20>/Discrete-Time Integrator' incorporates:
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

  /* DiscreteIntegrator: '<S22>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevR_i != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[0] = 0.0F;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[1] = 0.0F;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[2] = 0.0F;
  }

  /* Gain: '<S22>/Gain' incorporates:
   *  DiscreteIntegrator: '<S18>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S22>/Discrete-Time Integrator1'
   *  Sum: '<S22>/Sum5'
   */
  rtb_DiscreteTimeIntegrator1_b_i =
    (Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] -
     Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[0]) * 188.49556F;
  rtb_a_n_idx_1 = (Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] -
                   Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[1]) *
    188.49556F;
  rtb_DiscreteTimeIntegrator1_b_0 =
    (Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] -
     Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[2]) * 188.49556F;

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S3>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S19>/Multiply'
   *  RelationalOperator: '<S3>/Compare'
   */
  if (Controller_U.FMS_Out.status == 3) {
    /* Switch: '<S22>/Switch' incorporates:
     *  Gain: '<S22>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_Saturation_d_idx_0 = 0.0F;
      rtb_Saturation_d_idx_1 = 0.0F;
      rtb_Saturation_d_idx_2 = 0.0F;
    } else {
      rtb_Saturation_d_idx_0 = rtb_DiscreteTimeIntegrator1_b_i;
      rtb_Saturation_d_idx_1 = rtb_a_n_idx_1;
      rtb_Saturation_d_idx_2 = rtb_DiscreteTimeIntegrator1_b_0;
    }

    /* End of Switch: '<S22>/Switch' */

    /* Product: '<S19>/Multiply' incorporates:
     *  Constant: '<S19>/gain1'
     */
    rtb_a_n_idx_0 = CONTROL_PARAM.ROLL_RATE_D * rtb_Saturation_d_idx_0;

    /* Saturate: '<S19>/Saturation' */
    if (rtb_a_n_idx_0 > CONTROL_PARAM.RATE_D_MAX) {
      rtb_a_n_idx_0 = CONTROL_PARAM.RATE_D_MAX;
    } else {
      if (rtb_a_n_idx_0 < CONTROL_PARAM.RATE_D_MIN) {
        rtb_a_n_idx_0 = CONTROL_PARAM.RATE_D_MIN;
      }
    }

    rtb_Saturation_d_idx_0 = rtb_a_n_idx_0;

    /* Product: '<S19>/Multiply' incorporates:
     *  Constant: '<S19>/gain2'
     */
    rtb_a_n_idx_0 = CONTROL_PARAM.PITCH_RATE_D * rtb_Saturation_d_idx_1;

    /* Saturate: '<S19>/Saturation' */
    if (rtb_a_n_idx_0 > CONTROL_PARAM.RATE_D_MAX) {
      rtb_a_n_idx_0 = CONTROL_PARAM.RATE_D_MAX;
    } else {
      if (rtb_a_n_idx_0 < CONTROL_PARAM.RATE_D_MIN) {
        rtb_a_n_idx_0 = CONTROL_PARAM.RATE_D_MIN;
      }
    }

    rtb_Saturation_d_idx_1 = rtb_a_n_idx_0;

    /* Product: '<S19>/Multiply' incorporates:
     *  Constant: '<S19>/gain3'
     */
    rtb_a_n_idx_0 = CONTROL_PARAM.YAW_RATE_D * rtb_Saturation_d_idx_2;

    /* Saturate: '<S19>/Saturation' */
    if (rtb_a_n_idx_0 > CONTROL_PARAM.RATE_D_MAX) {
      rtb_a_n_idx_0 = CONTROL_PARAM.RATE_D_MAX;
    } else {
      if (rtb_a_n_idx_0 < CONTROL_PARAM.RATE_D_MIN) {
        rtb_a_n_idx_0 = CONTROL_PARAM.RATE_D_MIN;
      }
    }

    /* Switch: '<S54>/Switch' incorporates:
     *  Constant: '<S57>/Constant'
     *  Logic: '<S54>/Logical Operator'
     *  RelationalOperator: '<S56>/Compare'
     *  RelationalOperator: '<S57>/Compare'
     *  Switch: '<S54>/Switch1'
     */
    if ((Controller_U.FMS_Out.ctrl_mode == 1) || (Controller_U.FMS_Out.ctrl_mode
         == 2) || (Controller_U.FMS_Out.ctrl_mode == 3)) {
      rtb_throttle_cmd = Controller_U.FMS_Out.throttle_cmd;
    } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
      /* Switch: '<S58>/Switch' incorporates:
       *  DataTypeConversion: '<S55>/Data Type Conversion'
       *  S-Function (sfix_bitop): '<S58>/cmd_throttle valid'
       *  Switch: '<S54>/Switch1'
       */
      if ((Controller_U.FMS_Out.cmd_mask & 4096) > 0) {
        rtb_throttle_cmd = Controller_U.FMS_Out.throttle_cmd;
      } else {
        rtb_throttle_cmd = (uint16_T)rtb_DiscreteTimeIntegrator;
      }

      /* End of Switch: '<S58>/Switch' */
    } else {
      /* Switch: '<S54>/Switch1' incorporates:
       *  DataTypeConversion: '<S55>/Data Type Conversion'
       */
      rtb_throttle_cmd = (uint16_T)rtb_DiscreteTimeIntegrator;
    }

    /* End of Switch: '<S54>/Switch' */

    /* Saturate: '<S6>/Saturation1' incorporates:
     *  Constant: '<S21>/gain1'
     *  Constant: '<S21>/gain2'
     *  Constant: '<S21>/gain3'
     *  DiscreteIntegrator: '<S18>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S20>/Discrete-Time Integrator'
     *  Product: '<S21>/Multiply'
     *  Sum: '<S16>/Add'
     */
    rtb_Saturation_m = (CONTROL_PARAM.ROLL_RATE_P *
                        Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] +
                        Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0]) +
      rtb_Saturation_d_idx_0;
    if (rtb_Saturation_m > 1.0F) {
      rtb_Saturation_m = 1.0F;
    } else {
      if (rtb_Saturation_m < -1.0F) {
        rtb_Saturation_m = -1.0F;
      }
    }

    rtb_Add3 = (CONTROL_PARAM.PITCH_RATE_P *
                Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] +
                Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1]) +
      rtb_Saturation_d_idx_1;
    if (rtb_Add3 > 1.0F) {
      rtb_Add3 = 1.0F;
    } else {
      if (rtb_Add3 < -1.0F) {
        rtb_Add3 = -1.0F;
      }
    }

    rtb_Saturation_d_idx_1 = (CONTROL_PARAM.YAW_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2]) + rtb_a_n_idx_0;
    if (rtb_Saturation_d_idx_1 > 1.0F) {
      rtb_Saturation_d_idx_1 = 1.0F;
    } else {
      if (rtb_Saturation_d_idx_1 < -1.0F) {
        rtb_Saturation_d_idx_1 = -1.0F;
      }
    }

    /* End of Saturate: '<S6>/Saturation1' */
    for (i = 0; i < 4; i++) {
      /* Saturate: '<S6>/Saturation' incorporates:
       *  Constant: '<S6>/X_Frame_Effective_Matrix'
       *  Gain: '<S6>/Gain'
       *  Product: '<S6>/Multiply'
       *  Sum: '<S6>/Add'
       */
      rtb_a_n_idx_0 = fmodf(floorf(1000.0F *
        (Controller_ConstP.X_Frame_Effective_Matrix_Value[i + 8] *
         rtb_Saturation_d_idx_1 +
         (Controller_ConstP.X_Frame_Effective_Matrix_Value[i + 4] * rtb_Add3 +
          Controller_ConstP.X_Frame_Effective_Matrix_Value[i] * rtb_Saturation_m))),
                            65536.0F);
      u0 = (uint16_T)((uint32_T)(rtb_a_n_idx_0 < 0.0F ? (int32_T)(uint16_T)
        -(int16_T)(uint16_T)-rtb_a_n_idx_0 : (int32_T)(uint16_T)rtb_a_n_idx_0) +
                      rtb_throttle_cmd);
      if (u0 > 1900) {
        /* Outport: '<Root>/Control_Out' incorporates:
         *  Reshape: '<S6>/Reshape'
         */
        Controller_Y.Control_Out.actuator_cmd[i] = 1900U;
      } else if (u0 < 1100) {
        /* Outport: '<Root>/Control_Out' incorporates:
         *  Reshape: '<S6>/Reshape'
         */
        Controller_Y.Control_Out.actuator_cmd[i] = 1100U;
      } else {
        /* Outport: '<Root>/Control_Out' incorporates:
         *  Reshape: '<S6>/Reshape'
         */
        Controller_Y.Control_Out.actuator_cmd[i] = u0;
      }

      /* End of Saturate: '<S6>/Saturation' */
    }

    /* Reshape: '<S6>/Reshape' */
    for (i = 0; i < 12; i++) {
      /* Outport: '<Root>/Control_Out' incorporates:
       *  Constant: '<S6>/Constant'
       */
      Controller_Y.Control_Out.actuator_cmd[i + 4] = 0U;
    }
  } else {
    /* Outport: '<Root>/Control_Out' */
    for (rtb_DiscreteTimeIntegrator = 0; rtb_DiscreteTimeIntegrator < 16;
         rtb_DiscreteTimeIntegrator++) {
      Controller_Y.Control_Out.actuator_cmd[rtb_DiscreteTimeIntegrator] =
        Controller_U.FMS_Out.actuator_cmd[rtb_DiscreteTimeIntegrator];
    }
  }

  /* End of Switch: '<S1>/Switch' */

  /* Product: '<S20>/Multiply' incorporates:
   *  Constant: '<S20>/gain1'
   *  Constant: '<S20>/gain2'
   *  Constant: '<S20>/gain3'
   *  DiscreteIntegrator: '<S18>/Discrete-Time Integrator5'
   */
  rtb_Saturation_d_idx_0 = CONTROL_PARAM.ROLL_RATE_I *
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[0];
  rtb_Saturation_d_idx_1 = CONTROL_PARAM.PITCH_RATE_I *
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1];
  rtb_Saturation_d_idx_2 = CONTROL_PARAM.YAW_RATE_I *
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[2];

  /* Product: '<S45>/Multiply1' incorporates:
   *  Constant: '<S45>/const1'
   *  DiscreteIntegrator: '<S42>/Integrator'
   */
  rtb_a_n_idx_0 = Controller_DW.Integrator_DSTATE[0] * 0.05F;
  rtb_Saturation_idx_1 = Controller_DW.Integrator_DSTATE[1] * 0.05F;

  /* Sum: '<S45>/Add' incorporates:
   *  DiscreteIntegrator: '<S42>/Integrator1'
   *  Inport: '<Root>/FMS_Out'
   *  Sum: '<S42>/Subtract'
   */
  rtb_Subtract3_i_idx_0 = (Controller_DW.Integrator1_DSTATE_g[0] -
    Controller_U.FMS_Out.u_cmd) + rtb_a_n_idx_0;
  rtb_Subtract3_i_idx_1 = (Controller_DW.Integrator1_DSTATE_g[1] -
    Controller_U.FMS_Out.v_cmd) + rtb_Saturation_idx_1;

  /* Signum: '<S45>/Sign' */
  if (rtb_Subtract3_i_idx_0 < 0.0F) {
    rtb_Saturation_m = -1.0F;
  } else if (rtb_Subtract3_i_idx_0 > 0.0F) {
    rtb_Saturation_m = 1.0F;
  } else {
    rtb_Saturation_m = rtb_Subtract3_i_idx_0;
  }

  /* Sum: '<S45>/Add2' incorporates:
   *  Abs: '<S45>/Abs'
   *  Gain: '<S45>/Gain'
   *  Gain: '<S45>/Gain1'
   *  Product: '<S45>/Multiply2'
   *  Product: '<S45>/Multiply3'
   *  Signum: '<S45>/Sign'
   *  Sqrt: '<S45>/Sqrt'
   *  Sum: '<S45>/Add1'
   *  Sum: '<S45>/Subtract'
   */
  rtb_Saturation_m = (sqrtf((8.0F * fabsf(rtb_Subtract3_i_idx_0) +
    Controller_ConstB.d) * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
    rtb_Saturation_m + rtb_a_n_idx_0;

  /* Sum: '<S45>/Add3' incorporates:
   *  Signum: '<S45>/Sign'
   */
  rtb_Add3 = rtb_Subtract3_i_idx_0 + Controller_ConstB.d;

  /* Sum: '<S45>/Subtract1' incorporates:
   *  Signum: '<S45>/Sign'
   */
  rtb_a = rtb_Subtract3_i_idx_0 - Controller_ConstB.d;

  /* Signum: '<S45>/Sign1' */
  if (rtb_Add3 < 0.0F) {
    rtb_Add3 = -1.0F;
  } else {
    if (rtb_Add3 > 0.0F) {
      rtb_Add3 = 1.0F;
    }
  }

  /* Signum: '<S45>/Sign2' */
  if (rtb_a < 0.0F) {
    rtb_a = -1.0F;
  } else {
    if (rtb_a > 0.0F) {
      rtb_a = 1.0F;
    }
  }

  /* Sum: '<S45>/Add2' incorporates:
   *  Gain: '<S45>/Gain2'
   *  Product: '<S45>/Multiply4'
   *  Signum: '<S45>/Sign'
   *  Sum: '<S45>/Add4'
   *  Sum: '<S45>/Add5'
   *  Sum: '<S45>/Subtract2'
   */
  rtb_a_n_idx_0 = ((rtb_Subtract3_i_idx_0 - rtb_Saturation_m) + rtb_a_n_idx_0) *
    ((rtb_Add3 - rtb_a) * 0.5F) + rtb_Saturation_m;

  /* Signum: '<S45>/Sign' */
  if (rtb_Subtract3_i_idx_1 < 0.0F) {
    rtb_Saturation_m = -1.0F;
  } else if (rtb_Subtract3_i_idx_1 > 0.0F) {
    rtb_Saturation_m = 1.0F;
  } else {
    rtb_Saturation_m = rtb_Subtract3_i_idx_1;
  }

  /* Sum: '<S45>/Add2' incorporates:
   *  Abs: '<S45>/Abs'
   *  Gain: '<S45>/Gain'
   *  Gain: '<S45>/Gain1'
   *  Product: '<S45>/Multiply2'
   *  Product: '<S45>/Multiply3'
   *  Signum: '<S45>/Sign'
   *  Sqrt: '<S45>/Sqrt'
   *  Sum: '<S45>/Add1'
   *  Sum: '<S45>/Subtract'
   */
  rtb_Saturation_m = (sqrtf((8.0F * fabsf(rtb_Subtract3_i_idx_1) +
    Controller_ConstB.d) * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
    rtb_Saturation_m + rtb_Saturation_idx_1;

  /* Sum: '<S45>/Add3' incorporates:
   *  Signum: '<S45>/Sign'
   */
  rtb_Add3 = rtb_Subtract3_i_idx_1 + Controller_ConstB.d;

  /* Sum: '<S45>/Subtract1' incorporates:
   *  Signum: '<S45>/Sign'
   */
  rtb_a = rtb_Subtract3_i_idx_1 - Controller_ConstB.d;

  /* Signum: '<S45>/Sign1' */
  if (rtb_Add3 < 0.0F) {
    rtb_Add3 = -1.0F;
  } else {
    if (rtb_Add3 > 0.0F) {
      rtb_Add3 = 1.0F;
    }
  }

  /* Signum: '<S45>/Sign2' */
  if (rtb_a < 0.0F) {
    rtb_a = -1.0F;
  } else {
    if (rtb_a > 0.0F) {
      rtb_a = 1.0F;
    }
  }

  /* Sum: '<S45>/Add5' incorporates:
   *  Gain: '<S45>/Gain2'
   *  Product: '<S45>/Multiply4'
   *  Signum: '<S45>/Sign'
   *  Sum: '<S45>/Add2'
   *  Sum: '<S45>/Add4'
   *  Sum: '<S45>/Subtract2'
   */
  rtb_Saturation_m += ((rtb_Subtract3_i_idx_1 - rtb_Saturation_m) +
                       rtb_Saturation_idx_1) * ((rtb_Add3 - rtb_a) * 0.5F);

  /* Outport: '<Root>/Control_Out' incorporates:
   *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
   */
  Controller_Y.Control_Out.timestamp =
    Controller_DW.DiscreteTimeIntegrator_DSTATE_n;

  /* Product: '<S64>/Multiply1' incorporates:
   *  Constant: '<S64>/const1'
   *  DiscreteIntegrator: '<S63>/Integrator'
   */
  rtb_Add3 = Controller_DW.Integrator_DSTATE_p * 0.05F;

  /* Sum: '<S64>/Add' incorporates:
   *  DiscreteIntegrator: '<S63>/Integrator1'
   *  Inport: '<Root>/FMS_Out'
   *  Sum: '<S63>/Subtract'
   */
  rtb_Saturation_idx_1 = (Controller_DW.Integrator1_DSTATE -
    Controller_U.FMS_Out.w_cmd) + rtb_Add3;

  /* Signum: '<S64>/Sign' */
  if (rtb_Saturation_idx_1 < 0.0F) {
    rtb_a = -1.0F;
  } else if (rtb_Saturation_idx_1 > 0.0F) {
    rtb_a = 1.0F;
  } else {
    rtb_a = rtb_Saturation_idx_1;
  }

  /* End of Signum: '<S64>/Sign' */

  /* Sum: '<S64>/Add2' incorporates:
   *  Abs: '<S64>/Abs'
   *  Gain: '<S64>/Gain'
   *  Gain: '<S64>/Gain1'
   *  Product: '<S64>/Multiply2'
   *  Product: '<S64>/Multiply3'
   *  Sqrt: '<S64>/Sqrt'
   *  Sum: '<S64>/Add1'
   *  Sum: '<S64>/Subtract'
   */
  rtb_a = (sqrtf((8.0F * fabsf(rtb_Saturation_idx_1) + Controller_ConstB.d_n) *
                 Controller_ConstB.d_n) - Controller_ConstB.d_n) * 0.5F * rtb_a
    + rtb_Add3;

  /* Sum: '<S64>/Add4' */
  rtb_Subtract3_i_idx_1 = (rtb_Saturation_idx_1 - rtb_a) + rtb_Add3;

  /* Sum: '<S64>/Add3' */
  rtb_Add3 = rtb_Saturation_idx_1 + Controller_ConstB.d_n;

  /* Sum: '<S64>/Subtract1' */
  rtb_Saturation_idx_1 -= Controller_ConstB.d_n;

  /* Signum: '<S64>/Sign1' */
  if (rtb_Add3 < 0.0F) {
    rtb_Add3 = -1.0F;
  } else {
    if (rtb_Add3 > 0.0F) {
      rtb_Add3 = 1.0F;
    }
  }

  /* End of Signum: '<S64>/Sign1' */

  /* Signum: '<S64>/Sign2' */
  if (rtb_Saturation_idx_1 < 0.0F) {
    rtb_Saturation_idx_1 = -1.0F;
  } else {
    if (rtb_Saturation_idx_1 > 0.0F) {
      rtb_Saturation_idx_1 = 1.0F;
    }
  }

  /* End of Signum: '<S64>/Sign2' */

  /* Sum: '<S64>/Add5' incorporates:
   *  Gain: '<S64>/Gain2'
   *  Product: '<S64>/Multiply4'
   *  Sum: '<S64>/Subtract2'
   */
  rtb_a += (rtb_Add3 - rtb_Saturation_idx_1) * 0.5F * rtb_Subtract3_i_idx_1;

  /* Update for DiscreteIntegrator: '<S63>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S63>/Integrator'
   */
  Controller_DW.Integrator1_DSTATE += 0.002F * Controller_DW.Integrator_DSTATE_p;

  /* Update for DiscreteIntegrator: '<S66>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S66>/ki'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S66>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE += CONTROL_PARAM.VEL_Z_I *
    rtb_Gain_f * 0.002F;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE >= CONTROL_PARAM.VEL_Z_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE = CONTROL_PARAM.VEL_Z_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE <= CONTROL_PARAM.VEL_Z_I_MIN)
    {
      Controller_DW.DiscreteTimeIntegrator_DSTATE = CONTROL_PARAM.VEL_Z_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* End of Update for DiscreteIntegrator: '<S66>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S68>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_DSTATE += 0.002F * rtb_Gain;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S47>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator_PrevRe_e = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S42>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S42>/Integrator'
   */
  Controller_DW.Integrator1_DSTATE_g[0] += 0.002F *
    Controller_DW.Integrator_DSTATE[0];

  /* Update for DiscreteIntegrator: '<S47>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S47>/ki'
   *  Product: '<S47>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] += CONTROL_PARAM.VEL_XY_I *
    rtb_Add * 0.002F;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] >=
      CONTROL_PARAM.VEL_XY_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
      CONTROL_PARAM.VEL_XY_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] <=
        CONTROL_PARAM.VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
        CONTROL_PARAM.VEL_XY_I_MIN;
    }
  }

  /* Update for DiscreteIntegrator: '<S49>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[0] += 0.002F * rtb_Gain_j_idx_0;

  /* Update for DiscreteIntegrator: '<S42>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S42>/Integrator'
   */
  Controller_DW.Integrator1_DSTATE_g[1] += 0.002F *
    Controller_DW.Integrator_DSTATE[1];

  /* Update for DiscreteIntegrator: '<S47>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S47>/ki'
   *  Product: '<S47>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] += CONTROL_PARAM.VEL_XY_I *
    rtb_uv_error_C_mPs_idx_1 * 0.002F;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] >=
      CONTROL_PARAM.VEL_XY_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
      CONTROL_PARAM.VEL_XY_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] <=
        CONTROL_PARAM.VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
        CONTROL_PARAM.VEL_XY_I_MIN;
    }
  }

  /* Update for DiscreteIntegrator: '<S49>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[1] += 0.002F * rtb_Gain_j_idx_1;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_a = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;

  /* Update for DiscreteIntegrator: '<S20>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator_PrevRe_g = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S18>/Gain'
   *  Sum: '<S18>/Sum5'
   */
  Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] +=
    (rtb_rate_error_B_radPs_idx_0 -
     Controller_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 188.49556F * 0.002F;

  /* Update for DiscreteIntegrator: '<S20>/Discrete-Time Integrator' */
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

  /* Update for DiscreteIntegrator: '<S22>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[0] += 0.002F *
    rtb_DiscreteTimeIntegrator1_b_i;

  /* Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S18>/Gain'
   *  Sum: '<S18>/Sum5'
   */
  Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] += (rtb_Multiply4_b -
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 188.49556F * 0.002F;

  /* Update for DiscreteIntegrator: '<S20>/Discrete-Time Integrator' */
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

  /* Update for DiscreteIntegrator: '<S22>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[1] += 0.002F * rtb_a_n_idx_1;

  /* Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S18>/Gain'
   *  Sum: '<S18>/Sum5'
   */
  Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] +=
    (rtb_rate_error_B_radPs_idx_2 -
     Controller_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 188.49556F * 0.002F;

  /* Update for DiscreteIntegrator: '<S20>/Discrete-Time Integrator' */
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

  /* Update for DiscreteIntegrator: '<S22>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[2] += 0.002F *
    rtb_DiscreteTimeIntegrator1_b_0;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_i = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Signum: '<S45>/Sign3' incorporates:
   *  Product: '<S45>/Divide'
   *  Sum: '<S45>/Add6'
   */
  rtb_Add3 = rtb_a_n_idx_0 + Controller_ConstB.d;

  /* Signum: '<S45>/Sign4' incorporates:
   *  Product: '<S45>/Divide'
   *  Sum: '<S45>/Subtract3'
   */
  rtb_Gain_f = rtb_a_n_idx_0 - Controller_ConstB.d;

  /* Signum: '<S45>/Sign5' incorporates:
   *  Product: '<S45>/Divide'
   */
  if (rtb_a_n_idx_0 < 0.0F) {
    rtb_Gain = -1.0F;
  } else if (rtb_a_n_idx_0 > 0.0F) {
    rtb_Gain = 1.0F;
  } else {
    rtb_Gain = rtb_a_n_idx_0;
  }

  /* Signum: '<S45>/Sign3' */
  if (rtb_Add3 < 0.0F) {
    rtb_Add3 = -1.0F;
  } else {
    if (rtb_Add3 > 0.0F) {
      rtb_Add3 = 1.0F;
    }
  }

  /* Signum: '<S45>/Sign4' */
  if (rtb_Gain_f < 0.0F) {
    rtb_Gain_f = -1.0F;
  } else {
    if (rtb_Gain_f > 0.0F) {
      rtb_Gain_f = 1.0F;
    }
  }

  /* Signum: '<S45>/Sign6' incorporates:
   *  Product: '<S45>/Divide'
   */
  if (rtb_a_n_idx_0 < 0.0F) {
    rtb_Add = -1.0F;
  } else if (rtb_a_n_idx_0 > 0.0F) {
    rtb_Add = 1.0F;
  } else {
    rtb_Add = rtb_a_n_idx_0;
  }

  /* Update for DiscreteIntegrator: '<S42>/Integrator' incorporates:
   *  Constant: '<S45>/const'
   *  Gain: '<S45>/Gain3'
   *  Product: '<S45>/Divide'
   *  Product: '<S45>/Multiply5'
   *  Product: '<S45>/Multiply6'
   *  Sum: '<S45>/Subtract4'
   *  Sum: '<S45>/Subtract5'
   *  Sum: '<S45>/Subtract6'
   */
  Controller_DW.Integrator_DSTATE[0] += ((rtb_a_n_idx_0 / Controller_ConstB.d -
    rtb_Gain) * Controller_ConstB.Gain4 * ((rtb_Add3 - rtb_Gain_f) * 0.5F) -
    rtb_Add * 58.836F) * 0.002F;

  /* Signum: '<S45>/Sign3' incorporates:
   *  Sum: '<S45>/Add6'
   */
  rtb_Add3 = rtb_Saturation_m + Controller_ConstB.d;

  /* Signum: '<S45>/Sign4' incorporates:
   *  Sum: '<S45>/Subtract3'
   */
  rtb_Gain_f = rtb_Saturation_m - Controller_ConstB.d;

  /* Signum: '<S45>/Sign5' */
  if (rtb_Saturation_m < 0.0F) {
    rtb_Gain = -1.0F;
  } else if (rtb_Saturation_m > 0.0F) {
    rtb_Gain = 1.0F;
  } else {
    rtb_Gain = rtb_Saturation_m;
  }

  /* Signum: '<S45>/Sign3' */
  if (rtb_Add3 < 0.0F) {
    rtb_Add3 = -1.0F;
  } else {
    if (rtb_Add3 > 0.0F) {
      rtb_Add3 = 1.0F;
    }
  }

  /* Signum: '<S45>/Sign4' */
  if (rtb_Gain_f < 0.0F) {
    rtb_Gain_f = -1.0F;
  } else {
    if (rtb_Gain_f > 0.0F) {
      rtb_Gain_f = 1.0F;
    }
  }

  /* Signum: '<S45>/Sign6' */
  if (rtb_Saturation_m < 0.0F) {
    rtb_Add = -1.0F;
  } else if (rtb_Saturation_m > 0.0F) {
    rtb_Add = 1.0F;
  } else {
    rtb_Add = rtb_Saturation_m;
  }

  /* Update for DiscreteIntegrator: '<S42>/Integrator' incorporates:
   *  Constant: '<S45>/const'
   *  Gain: '<S45>/Gain3'
   *  Product: '<S45>/Divide'
   *  Product: '<S45>/Multiply5'
   *  Product: '<S45>/Multiply6'
   *  Sum: '<S45>/Subtract4'
   *  Sum: '<S45>/Subtract5'
   *  Sum: '<S45>/Subtract6'
   */
  Controller_DW.Integrator_DSTATE[1] += ((rtb_Saturation_m / Controller_ConstB.d
    - rtb_Gain) * Controller_ConstB.Gain4 * ((rtb_Add3 - rtb_Gain_f) * 0.5F) -
    rtb_Add * 58.836F) * 0.002F;

  /* Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S4>/Constant'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_n += CONTROL_EXPORT.period;

  /* Signum: '<S64>/Sign6' incorporates:
   *  Signum: '<S64>/Sign5'
   */
  if (rtb_a < 0.0F) {
    rtb_Gain = -1.0F;

    /* Signum: '<S64>/Sign5' */
    rtb_Add = -1.0F;
  } else if (rtb_a > 0.0F) {
    rtb_Gain = 1.0F;

    /* Signum: '<S64>/Sign5' */
    rtb_Add = 1.0F;
  } else {
    rtb_Gain = rtb_a;

    /* Signum: '<S64>/Sign5' */
    rtb_Add = rtb_a;
  }

  /* End of Signum: '<S64>/Sign6' */

  /* Sum: '<S64>/Add6' */
  rtb_Add3 = rtb_a + Controller_ConstB.d_n;

  /* Sum: '<S64>/Subtract3' */
  rtb_Gain_f = rtb_a - Controller_ConstB.d_n;

  /* Signum: '<S64>/Sign3' */
  if (rtb_Add3 < 0.0F) {
    rtb_Add3 = -1.0F;
  } else {
    if (rtb_Add3 > 0.0F) {
      rtb_Add3 = 1.0F;
    }
  }

  /* End of Signum: '<S64>/Sign3' */

  /* Signum: '<S64>/Sign4' */
  if (rtb_Gain_f < 0.0F) {
    rtb_Gain_f = -1.0F;
  } else {
    if (rtb_Gain_f > 0.0F) {
      rtb_Gain_f = 1.0F;
    }
  }

  /* End of Signum: '<S64>/Sign4' */

  /* Update for DiscreteIntegrator: '<S63>/Integrator' incorporates:
   *  Constant: '<S64>/const'
   *  Gain: '<S64>/Gain3'
   *  Product: '<S64>/Divide'
   *  Product: '<S64>/Multiply5'
   *  Product: '<S64>/Multiply6'
   *  Sum: '<S64>/Subtract4'
   *  Sum: '<S64>/Subtract5'
   *  Sum: '<S64>/Subtract6'
   */
  Controller_DW.Integrator_DSTATE_p += ((rtb_a / Controller_ConstB.d_n - rtb_Add)
    * Controller_ConstB.Gain4_k * ((rtb_Add3 - rtb_Gain_f) * 0.5F) - rtb_Gain *
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

  /* InitializeConditions for DiscreteIntegrator: '<S66>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE = Controller_ConstB.Constant;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE >= CONTROL_PARAM.VEL_Z_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE = CONTROL_PARAM.VEL_Z_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE <= CONTROL_PARAM.VEL_Z_I_MIN)
    {
      Controller_DW.DiscreteTimeIntegrator_DSTATE = CONTROL_PARAM.VEL_Z_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRese = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S66>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S68>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S47>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
    Controller_ConstB.Constant_g;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] >=
      CONTROL_PARAM.VEL_XY_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
      CONTROL_PARAM.VEL_XY_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] <=
        CONTROL_PARAM.VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
        CONTROL_PARAM.VEL_XY_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
    Controller_ConstB.Constant_g;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] >=
      CONTROL_PARAM.VEL_XY_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
      CONTROL_PARAM.VEL_XY_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] <=
        CONTROL_PARAM.VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
        CONTROL_PARAM.VEL_XY_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRe_e = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S47>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S49>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_PrevR_a = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S18>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S20>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S20>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S22>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_PrevR_i = 0;
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
