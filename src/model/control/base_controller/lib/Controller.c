/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.934
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat May 20 09:53:37 2023
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
                                        *   '<S25>/hover_throttle'
                                        *   '<S58>/Saturation'
                                        *   '<S34>/Saturation'
                                        *   '<S34>/Saturation1'
                                        *   '<S67>/kd'
                                        *   '<S67>/Saturation'
                                        *   '<S68>/ki'
                                        *   '<S68>/Discrete-Time Integrator'
                                        *   '<S69>/kp'
                                        *   '<S86>/kd'
                                        *   '<S86>/Saturation'
                                        *   '<S87>/ki'
                                        *   '<S87>/Discrete-Time Integrator'
                                        *   '<S88>/kp'
                                        *   '<S51>/Constant1'
                                        *   '<S51>/Constant2'
                                        *   '<S40>/gain1'
                                        *   '<S40>/gain2'
                                        *   '<S40>/gain3'
                                        *   '<S40>/Saturation'
                                        *   '<S41>/gain1'
                                        *   '<S41>/gain2'
                                        *   '<S41>/gain3'
                                        *   '<S41>/Discrete-Time Integrator'
                                        *   '<S42>/gain1'
                                        *   '<S42>/gain2'
                                        *   '<S42>/gain3'
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
  uint16_T rtb_MultiportSwitch[4];
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
  real32_T rtb_Switch_bt_idx_0;
  real32_T rtb_Switch_bt_idx_1;
  real32_T rtb_Switch_bt_idx_2;
  real32_T rtb_uv_error_C_mPs_idx_1;
  real32_T rtb_Gain_j_idx_0;
  real32_T rtb_Gain_j_idx_1;
  uint16_T u0;

  /* Gain: '<S82>/Gain' incorporates:
   *  DiscreteIntegrator: '<S84>/Integrator1'
   *  Inport: '<Root>/INS_Out'
   *  Sum: '<S82>/Sum1'
   */
  rtb_Gain_f = -(Controller_DW.Integrator1_DSTATE - Controller_U.INS_Out.vd);

  /* DiscreteIntegrator: '<S87>/Discrete-Time Integrator' incorporates:
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

  /* DiscreteIntegrator: '<S89>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevRes != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTATE = 0.0F;
  }

  /* Gain: '<S89>/Gain' incorporates:
   *  DiscreteIntegrator: '<S89>/Discrete-Time Integrator1'
   *  Sum: '<S89>/Sum5'
   */
  rtb_Gain = (rtb_Gain_f - Controller_DW.DiscreteTimeIntegrator1_DSTATE) *
    62.831852F;

  /* Switch: '<S89>/Switch' incorporates:
   *  Gain: '<S89>/Gain1'
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_U.FMS_Out.reset > 0) {
    rtb_Add3 = 0.0F;
  } else {
    rtb_Add3 = rtb_Gain;
  }

  /* End of Switch: '<S89>/Switch' */

  /* Product: '<S86>/Multiply' incorporates:
   *  Constant: '<S86>/kd'
   */
  rtb_Saturation_m = CONTROL_PARAM.VEL_Z_D * rtb_Add3;

  /* Saturate: '<S86>/Saturation' */
  if (rtb_Saturation_m > CONTROL_PARAM.VEL_Z_D_MAX) {
    rtb_Saturation_m = CONTROL_PARAM.VEL_Z_D_MAX;
  } else {
    if (rtb_Saturation_m < CONTROL_PARAM.VEL_Z_D_MIN) {
      rtb_Saturation_m = CONTROL_PARAM.VEL_Z_D_MIN;
    }
  }

  /* End of Saturate: '<S86>/Saturation' */

  /* Sum: '<S83>/Add' incorporates:
   *  Constant: '<S88>/kp'
   *  DiscreteIntegrator: '<S87>/Discrete-Time Integrator'
   *  Product: '<S88>/Multiply'
   */
  rtb_Add = (CONTROL_PARAM.VEL_Z_P * rtb_Gain_f +
             Controller_DW.DiscreteTimeIntegrator_DSTATE) + rtb_Saturation_m;

  /* Trigonometry: '<S81>/Cos1' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S44>/Cos1'
   */
  rtb_DiscreteTimeIntegrator1_b_0 = arm_cos_f32(Controller_U.INS_Out.theta);

  /* Trigonometry: '<S81>/Cos' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S44>/Cos'
   */
  rtb_rate_error_B_radPs_idx_0 = arm_cos_f32(Controller_U.INS_Out.phi);

  /* Product: '<S81>/Multiply' incorporates:
   *  Trigonometry: '<S81>/Cos'
   *  Trigonometry: '<S81>/Cos1'
   */
  rtb_Saturation_m = rtb_rate_error_B_radPs_idx_0 *
    rtb_DiscreteTimeIntegrator1_b_0;

  /* Saturate: '<S81>/Saturation1' */
  if (rtb_Saturation_m > 1.0F) {
    rtb_Multiply4_b = 1.0F;
  } else if (rtb_Saturation_m < 0.5F) {
    rtb_Multiply4_b = 0.5F;
  } else {
    rtb_Multiply4_b = rtb_Saturation_m;
  }

  /* End of Saturate: '<S81>/Saturation1' */

  /* Gain: '<S81>/Gain' */
  rtb_Saturation_m *= 2.0F;

  /* Saturate: '<S81>/Saturation' */
  if (rtb_Saturation_m > 1.0F) {
    rtb_Saturation_m = 1.0F;
  } else {
    if (rtb_Saturation_m < 0.0F) {
      rtb_Saturation_m = 0.0F;
    }
  }

  /* End of Saturate: '<S81>/Saturation' */

  /* Product: '<S81>/Multiply1' incorporates:
   *  Constant: '<S81>/Constant'
   *  Product: '<S81>/Divide'
   */
  rtb_Saturation_m *= 1.0F / rtb_Multiply4_b * rtb_Add;

  /* Saturate: '<S80>/Saturation' */
  if (rtb_Saturation_m > 0.35F) {
    rtb_Saturation_m = 0.35F;
  } else {
    if (rtb_Saturation_m < -0.35F) {
      rtb_Saturation_m = -0.35F;
    }
  }

  /* End of Saturate: '<S80>/Saturation' */

  /* Sum: '<S25>/Sum' incorporates:
   *  Constant: '<S25>/hover_throttle'
   */
  rtb_Saturation_m += CONTROL_PARAM.HOVER_THRO;

  /* Saturate: '<S25>/Saturation' */
  if (rtb_Saturation_m > 1.0F) {
    rtb_Saturation_m = 1.0F;
  } else {
    if (rtb_Saturation_m < 0.0F) {
      rtb_Saturation_m = 0.0F;
    }
  }

  /* End of Saturate: '<S25>/Saturation' */

  /* Sum: '<S25>/Sum1' incorporates:
   *  Constant: '<S25>/Constant1'
   *  Gain: '<S25>/Gain1'
   */
  rtb_DiscreteTimeIntegrator = (int32_T)((uint32_T)fmodf(floorf(1000.0F *
    rtb_Saturation_m), 4.2949673E+9F) + 1000U);

  /* Trigonometry: '<S65>/Trigonometric Function1' incorporates:
   *  Gain: '<S64>/Gain'
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S65>/Trigonometric Function3'
   */
  rtb_Add = arm_cos_f32(-Controller_U.INS_Out.psi);
  rtb_VectorConcatenate[0] = rtb_Add;

  /* Trigonometry: '<S65>/Trigonometric Function' incorporates:
   *  Gain: '<S64>/Gain'
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S65>/Trigonometric Function2'
   */
  rtb_uv_error_C_mPs_idx_1 = arm_sin_f32(-Controller_U.INS_Out.psi);
  rtb_VectorConcatenate[1] = rtb_uv_error_C_mPs_idx_1;

  /* SignalConversion: '<S65>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S65>/Constant3'
   */
  rtb_VectorConcatenate[2] = 0.0F;

  /* Gain: '<S65>/Gain' */
  rtb_VectorConcatenate[3] = -rtb_uv_error_C_mPs_idx_1;

  /* Trigonometry: '<S65>/Trigonometric Function3' */
  rtb_VectorConcatenate[4] = rtb_Add;

  /* SignalConversion: '<S65>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S65>/Constant4'
   */
  rtb_VectorConcatenate[5] = 0.0F;

  /* SignalConversion: '<S65>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate[6] = Controller_ConstB.VectorConcatenate3[0];
  rtb_VectorConcatenate[7] = Controller_ConstB.VectorConcatenate3[1];
  rtb_VectorConcatenate[8] = Controller_ConstB.VectorConcatenate3[2];

  /* Product: '<S62>/Multiply' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  SignalConversion: '<S62>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_0[i] = rtb_VectorConcatenate[i + 3] *
      Controller_U.INS_Out.ve + rtb_VectorConcatenate[i] *
      Controller_U.INS_Out.vn;
  }

  /* End of Product: '<S62>/Multiply' */

  /* Sum: '<S59>/Sum' incorporates:
   *  DiscreteIntegrator: '<S63>/Integrator1'
   */
  rtb_Add = Controller_DW.Integrator1_DSTATE_g[0] - rtb_VectorConcatenate_0[0];
  rtb_uv_error_C_mPs_idx_1 = Controller_DW.Integrator1_DSTATE_g[1] -
    rtb_VectorConcatenate_0[1];

  /* DiscreteIntegrator: '<S68>/Discrete-Time Integrator' incorporates:
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

  /* DiscreteIntegrator: '<S70>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevR_a != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[0] = 0.0F;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[1] = 0.0F;
  }

  /* Gain: '<S70>/Gain' incorporates:
   *  DiscreteIntegrator: '<S70>/Discrete-Time Integrator1'
   *  Sum: '<S70>/Sum5'
   */
  rtb_Gain_j_idx_0 = (rtb_Add - Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[0])
    * 62.831852F;
  rtb_Gain_j_idx_1 = (rtb_uv_error_C_mPs_idx_1 -
                      Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[1]) *
    62.831852F;

  /* Switch: '<S70>/Switch' incorporates:
   *  Gain: '<S70>/Gain1'
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_U.FMS_Out.reset > 0) {
    rtb_a_n_idx_0 = 0.0F;
    rtb_a_n_idx_1 = 0.0F;
  } else {
    rtb_a_n_idx_0 = rtb_Gain_j_idx_0;
    rtb_a_n_idx_1 = rtb_Gain_j_idx_1;
  }

  /* End of Switch: '<S70>/Switch' */

  /* Product: '<S67>/Multiply' incorporates:
   *  Constant: '<S67>/kd'
   */
  rtb_Saturation_m = CONTROL_PARAM.VEL_XY_D * rtb_a_n_idx_0;

  /* Saturate: '<S67>/Saturation' */
  if (rtb_Saturation_m > CONTROL_PARAM.VEL_XY_D_MAX) {
    rtb_Saturation_m = CONTROL_PARAM.VEL_XY_D_MAX;
  } else {
    if (rtb_Saturation_m < CONTROL_PARAM.VEL_XY_D_MIN) {
      rtb_Saturation_m = CONTROL_PARAM.VEL_XY_D_MIN;
    }
  }

  /* Product: '<S67>/Multiply' incorporates:
   *  Constant: '<S67>/kd'
   */
  rtb_a_n_idx_0 = rtb_Saturation_m;
  rtb_Saturation_m = CONTROL_PARAM.VEL_XY_D * rtb_a_n_idx_1;

  /* Saturate: '<S67>/Saturation' */
  if (rtb_Saturation_m > CONTROL_PARAM.VEL_XY_D_MAX) {
    rtb_Saturation_m = CONTROL_PARAM.VEL_XY_D_MAX;
  } else {
    if (rtb_Saturation_m < CONTROL_PARAM.VEL_XY_D_MIN) {
      rtb_Saturation_m = CONTROL_PARAM.VEL_XY_D_MIN;
    }
  }

  /* Switch: '<S61>/Switch' incorporates:
   *  Constant: '<S69>/kp'
   *  Constant: '<S71>/Constant'
   *  Constant: '<S73>/Constant'
   *  Constant: '<S74>/Constant'
   *  DiscreteIntegrator: '<S68>/Discrete-Time Integrator'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S69>/Multiply'
   *  Product: '<S72>/Multiply2'
   *  Product: '<S72>/Multiply3'
   *  RelationalOperator: '<S71>/Compare'
   *  RelationalOperator: '<S73>/Compare'
   *  RelationalOperator: '<S74>/Compare'
   *  S-Function (sfix_bitop): '<S72>/cmd_ax valid'
   *  S-Function (sfix_bitop): '<S72>/cmd_ay valid'
   *  S-Function (sfix_bitop): '<S72>/cmd_u valid'
   *  S-Function (sfix_bitop): '<S72>/cmd_v valid'
   *  Sum: '<S60>/Add'
   *  Sum: '<S72>/Sum1'
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

  /* End of Switch: '<S61>/Switch' */

  /* Trigonometry: '<S58>/Atan' incorporates:
   *  Constant: '<S58>/g'
   *  Gain: '<S58>/Gain1'
   *  Gain: '<S58>/gain'
   *  Product: '<S58>/Divide'
   */
  rtb_Saturation_m = atanf(1.1F * rtb_a_n_idx_1 / 9.8055F);
  rtb_a_n_idx_1 = atanf(1.1F * -rtb_a_n_idx_0 / 9.8055F);

  /* Switch: '<S49>/Switch' incorporates:
   *  Constant: '<S56>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  Logic: '<S49>/Logical Operator'
   *  RelationalOperator: '<S55>/Compare'
   *  RelationalOperator: '<S56>/Compare'
   *  Saturate: '<S58>/Saturation'
   *  Switch: '<S49>/Switch1'
   */
  if ((Controller_U.FMS_Out.ctrl_mode == 3) || (Controller_U.FMS_Out.ctrl_mode ==
       4)) {
    rtb_a_n_idx_0 = Controller_U.FMS_Out.phi_cmd;
    rtb_a_n_idx_1 = Controller_U.FMS_Out.theta_cmd;
  } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
    /* Switch: '<S57>/Switch' incorporates:
     *  S-Function (sfix_bitop): '<S57>/cmd_phi valid'
     *  S-Function (sfix_bitop): '<S57>/cmd_theta valid'
     *  Saturate: '<S58>/Saturation'
     *  Switch: '<S49>/Switch1'
     */
    if ((Controller_U.FMS_Out.cmd_mask & 8) > 0) {
      rtb_a_n_idx_0 = Controller_U.FMS_Out.phi_cmd;
    } else if (rtb_Saturation_m > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      /* Saturate: '<S58>/Saturation' */
      rtb_a_n_idx_0 = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    } else if (rtb_Saturation_m < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      /* Saturate: '<S58>/Saturation' */
      rtb_a_n_idx_0 = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    } else {
      rtb_a_n_idx_0 = rtb_Saturation_m;
    }

    if ((Controller_U.FMS_Out.cmd_mask & 16) > 0) {
      rtb_a_n_idx_1 = Controller_U.FMS_Out.theta_cmd;
    } else if (rtb_a_n_idx_1 > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      /* Saturate: '<S58>/Saturation' */
      rtb_a_n_idx_1 = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_a_n_idx_1 < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S58>/Saturation' */
        rtb_a_n_idx_1 = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
      }
    }

    /* End of Switch: '<S57>/Switch' */
  } else {
    if (rtb_Saturation_m > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      /* Saturate: '<S58>/Saturation' incorporates:
       *  Switch: '<S49>/Switch1'
       */
      rtb_a_n_idx_0 = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    } else if (rtb_Saturation_m < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      /* Saturate: '<S58>/Saturation' incorporates:
       *  Switch: '<S49>/Switch1'
       */
      rtb_a_n_idx_0 = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    } else {
      /* Switch: '<S49>/Switch1' incorporates:
       *  Saturate: '<S58>/Saturation'
       */
      rtb_a_n_idx_0 = rtb_Saturation_m;
    }

    /* Saturate: '<S58>/Saturation' */
    if (rtb_a_n_idx_1 > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      /* Switch: '<S49>/Switch1' */
      rtb_a_n_idx_1 = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_a_n_idx_1 < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
        /* Switch: '<S49>/Switch1' */
        rtb_a_n_idx_1 = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
      }
    }
  }

  /* End of Switch: '<S49>/Switch' */

  /* Sum: '<S50>/Sum' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Saturation_m = rtb_a_n_idx_0 - Controller_U.INS_Out.phi;

  /* Product: '<S53>/Divide1' incorporates:
   *  Abs: '<S53>/Abs'
   *  Constant: '<S53>/const2'
   */
  rtb_DiscreteTimeIntegrator1_b_i = fabsf(rtb_Saturation_m) / 0.002F;

  /* Product: '<S53>/Divide' incorporates:
   *  Constant: '<S51>/Constant1'
   *  Constant: '<S53>/const1'
   *  Math: '<S53>/Square'
   *  SignalConversion: '<S53>/TmpSignal ConversionAtSquareInport1'
   */
  rtb_a = 9.5993F / (CONTROL_PARAM.ROLL_P * CONTROL_PARAM.ROLL_P);

  /* Signum: '<S53>/Sign' */
  if (rtb_Saturation_m < 0.0F) {
    rtb_Multiply4_b = -1.0F;
  } else if (rtb_Saturation_m > 0.0F) {
    rtb_Multiply4_b = 1.0F;
  } else {
    rtb_Multiply4_b = rtb_Saturation_m;
  }

  /* Switch: '<S53>/Switch' incorporates:
   *  Constant: '<S51>/Constant1'
   *  Gain: '<S53>/Gain1'
   *  Gain: '<S53>/Gain2'
   *  Logic: '<S53>/Logical Operator'
   *  Product: '<S53>/Multiply'
   *  Product: '<S53>/Multiply1'
   *  Product: '<S53>/Multiply2'
   *  Product: '<S53>/Multiply3'
   *  RelationalOperator: '<S53>/Relational Operator'
   *  RelationalOperator: '<S53>/Relational Operator2'
   *  SignalConversion: '<S53>/TmpSignal ConversionAtSquareInport1'
   *  Sqrt: '<S53>/Sqrt'
   *  Sum: '<S53>/Subtract'
   */
  if ((rtb_Saturation_m <= rtb_a) && (rtb_Saturation_m >= -rtb_a)) {
    rtb_Multiply4_b = rtb_Saturation_m * CONTROL_PARAM.ROLL_P;
  } else {
    rtb_Multiply4_b *= sqrtf((rtb_Multiply4_b * rtb_Saturation_m - 0.5F * rtb_a)
      * Controller_ConstB.Gain);
  }

  /* Gain: '<S53>/Gain3' */
  rtb_a = -rtb_DiscreteTimeIntegrator1_b_i;

  /* Switch: '<S54>/Switch' incorporates:
   *  Gain: '<S53>/Gain3'
   *  RelationalOperator: '<S54>/UpperRelop'
   */
  if (rtb_Multiply4_b >= -rtb_DiscreteTimeIntegrator1_b_i) {
    rtb_a = rtb_Multiply4_b;
  }

  /* Switch: '<S54>/Switch2' incorporates:
   *  RelationalOperator: '<S54>/LowerRelop1'
   */
  if (rtb_Multiply4_b <= rtb_DiscreteTimeIntegrator1_b_i) {
    rtb_DiscreteTimeIntegrator1_b_i = rtb_a;
  }

  /* Saturate: '<S34>/Saturation1' */
  if (rtb_DiscreteTimeIntegrator1_b_i > CONTROL_PARAM.P_Q_CMD_LIM) {
    rtb_DiscreteTimeIntegrator1_b_i = CONTROL_PARAM.P_Q_CMD_LIM;
  } else {
    if (rtb_DiscreteTimeIntegrator1_b_i < -CONTROL_PARAM.P_Q_CMD_LIM) {
      rtb_DiscreteTimeIntegrator1_b_i = -CONTROL_PARAM.P_Q_CMD_LIM;
    }
  }

  /* Product: '<S53>/Divide1' */
  rtb_a_n_idx_0 = rtb_DiscreteTimeIntegrator1_b_i;

  /* Sum: '<S50>/Sum' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Saturation_m = rtb_a_n_idx_1 - Controller_U.INS_Out.theta;

  /* Product: '<S53>/Divide1' incorporates:
   *  Abs: '<S53>/Abs'
   *  Constant: '<S53>/const2'
   */
  rtb_DiscreteTimeIntegrator1_b_i = fabsf(rtb_Saturation_m) / 0.002F;

  /* Product: '<S53>/Divide' incorporates:
   *  Constant: '<S51>/Constant2'
   *  Constant: '<S53>/const1'
   *  Math: '<S53>/Square'
   *  SignalConversion: '<S53>/TmpSignal ConversionAtSquareInport1'
   */
  rtb_a = 9.5993F / (CONTROL_PARAM.PITCH_P * CONTROL_PARAM.PITCH_P);

  /* Signum: '<S53>/Sign' */
  if (rtb_Saturation_m < 0.0F) {
    rtb_Multiply4_b = -1.0F;
  } else if (rtb_Saturation_m > 0.0F) {
    rtb_Multiply4_b = 1.0F;
  } else {
    rtb_Multiply4_b = rtb_Saturation_m;
  }

  /* Switch: '<S53>/Switch' incorporates:
   *  Constant: '<S51>/Constant2'
   *  Gain: '<S53>/Gain1'
   *  Gain: '<S53>/Gain2'
   *  Logic: '<S53>/Logical Operator'
   *  Product: '<S53>/Multiply'
   *  Product: '<S53>/Multiply1'
   *  Product: '<S53>/Multiply2'
   *  Product: '<S53>/Multiply3'
   *  RelationalOperator: '<S53>/Relational Operator'
   *  RelationalOperator: '<S53>/Relational Operator2'
   *  SignalConversion: '<S53>/TmpSignal ConversionAtSquareInport1'
   *  Sqrt: '<S53>/Sqrt'
   *  Sum: '<S53>/Subtract'
   */
  if ((rtb_Saturation_m <= rtb_a) && (rtb_Saturation_m >= -rtb_a)) {
    rtb_Multiply4_b = rtb_Saturation_m * CONTROL_PARAM.PITCH_P;
  } else {
    rtb_Multiply4_b *= sqrtf((rtb_Multiply4_b * rtb_Saturation_m - 0.5F * rtb_a)
      * Controller_ConstB.Gain);
  }

  /* Gain: '<S53>/Gain3' */
  rtb_a = -rtb_DiscreteTimeIntegrator1_b_i;

  /* Switch: '<S54>/Switch' incorporates:
   *  Gain: '<S53>/Gain3'
   *  RelationalOperator: '<S54>/UpperRelop'
   */
  if (rtb_Multiply4_b >= -rtb_DiscreteTimeIntegrator1_b_i) {
    rtb_a = rtb_Multiply4_b;
  }

  /* Switch: '<S54>/Switch2' incorporates:
   *  RelationalOperator: '<S54>/LowerRelop1'
   */
  if (rtb_Multiply4_b <= rtb_DiscreteTimeIntegrator1_b_i) {
    rtb_DiscreteTimeIntegrator1_b_i = rtb_a;
  }

  /* Saturate: '<S34>/Saturation1' */
  if (rtb_DiscreteTimeIntegrator1_b_i > CONTROL_PARAM.P_Q_CMD_LIM) {
    rtb_DiscreteTimeIntegrator1_b_i = CONTROL_PARAM.P_Q_CMD_LIM;
  } else {
    if (rtb_DiscreteTimeIntegrator1_b_i < -CONTROL_PARAM.P_Q_CMD_LIM) {
      rtb_DiscreteTimeIntegrator1_b_i = -CONTROL_PARAM.P_Q_CMD_LIM;
    }
  }

  /* Saturate: '<S34>/Saturation' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_U.FMS_Out.psi_rate_cmd > CONTROL_PARAM.R_CMD_LIM) {
    rtb_Saturation_m = CONTROL_PARAM.R_CMD_LIM;
  } else if (Controller_U.FMS_Out.psi_rate_cmd < -CONTROL_PARAM.R_CMD_LIM) {
    rtb_Saturation_m = -CONTROL_PARAM.R_CMD_LIM;
  } else {
    rtb_Saturation_m = Controller_U.FMS_Out.psi_rate_cmd;
  }

  /* End of Saturate: '<S34>/Saturation' */

  /* Trigonometry: '<S44>/Sin' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Multiply4_b = arm_sin_f32(Controller_U.INS_Out.phi);

  /* Product: '<S44>/Multiply3' */
  rtb_a_n_idx_1 = rtb_Multiply4_b * rtb_DiscreteTimeIntegrator1_b_0 *
    rtb_Saturation_m;

  /* Product: '<S44>/Multiply1' */
  rtb_rate_error_B_radPs_idx_2 = rtb_rate_error_B_radPs_idx_0 *
    rtb_DiscreteTimeIntegrator1_b_i;

  /* Product: '<S44>/Multiply4' */
  rtb_Multiply4_b *= rtb_DiscreteTimeIntegrator1_b_i;

  /* Switch: '<S35>/Switch' incorporates:
   *  Constant: '<S45>/Constant'
   *  Constant: '<S46>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  RelationalOperator: '<S45>/Compare'
   *  RelationalOperator: '<S46>/Compare'
   *  Switch: '<S35>/Switch1'
   */
  if (Controller_U.FMS_Out.ctrl_mode == 2) {
    rtb_DiscreteTimeIntegrator1_b_i = Controller_U.FMS_Out.p_cmd;
    rtb_a_n_idx_1 = Controller_U.FMS_Out.q_cmd;
    rtb_DiscreteTimeIntegrator1_b_0 = Controller_U.FMS_Out.r_cmd;
  } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
    /* Switch: '<S47>/Switch' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S44>/Multiply'
     *  Product: '<S44>/Multiply1'
     *  Product: '<S44>/Multiply5'
     *  S-Function (sfix_bitop): '<S47>/cmd_p valid'
     *  S-Function (sfix_bitop): '<S47>/cmd_q valid'
     *  S-Function (sfix_bitop): '<S47>/cmd_r valid'
     *  Sum: '<S44>/Add'
     *  Sum: '<S44>/Add1'
     *  Sum: '<S44>/Add2'
     *  Switch: '<S35>/Switch1'
     *  Trigonometry: '<S44>/Sin1'
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

    /* End of Switch: '<S47>/Switch' */
  } else {
    /* Switch: '<S35>/Switch1' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S44>/Multiply'
     *  Product: '<S44>/Multiply3'
     *  Product: '<S44>/Multiply5'
     *  Sum: '<S44>/Add'
     *  Sum: '<S44>/Add1'
     *  Sum: '<S44>/Add2'
     *  Trigonometry: '<S44>/Sin1'
     */
    rtb_DiscreteTimeIntegrator1_b_i = rtb_a_n_idx_0 - arm_sin_f32
      (Controller_U.INS_Out.theta) * rtb_Saturation_m;
    rtb_a_n_idx_1 += rtb_rate_error_B_radPs_idx_2;
    rtb_DiscreteTimeIntegrator1_b_0 = rtb_rate_error_B_radPs_idx_0 *
      rtb_DiscreteTimeIntegrator1_b_0 * rtb_Saturation_m - rtb_Multiply4_b;
  }

  /* End of Switch: '<S35>/Switch' */

  /* Sum: '<S36>/Sum' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_rate_error_B_radPs_idx_0 = rtb_DiscreteTimeIntegrator1_b_i -
    Controller_U.INS_Out.p;
  rtb_Multiply4_b = rtb_a_n_idx_1 - Controller_U.INS_Out.q;
  rtb_rate_error_B_radPs_idx_2 = rtb_DiscreteTimeIntegrator1_b_0 -
    Controller_U.INS_Out.r;

  /* DiscreteIntegrator: '<S39>/Discrete-Time Integrator5' */
  if (Controller_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] =
      rtb_rate_error_B_radPs_idx_0;
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] = rtb_Multiply4_b;
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] =
      rtb_rate_error_B_radPs_idx_2;
  }

  /* DiscreteIntegrator: '<S41>/Discrete-Time Integrator' incorporates:
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

  /* DiscreteIntegrator: '<S43>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevR_i != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[0] = 0.0F;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[1] = 0.0F;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[2] = 0.0F;
  }

  /* Gain: '<S43>/Gain' incorporates:
   *  DiscreteIntegrator: '<S39>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S43>/Discrete-Time Integrator1'
   *  Sum: '<S43>/Sum5'
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

  /* MultiPortSwitch: '<S24>/Multiport Switch' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  switch (Controller_U.FMS_Out.status) {
   case 1:
    rtb_MultiportSwitch[0] = 1000U;
    rtb_MultiportSwitch[1] = 1000U;
    rtb_MultiportSwitch[2] = 1000U;
    rtb_MultiportSwitch[3] = 1000U;
    break;

   case 2:
    rtb_MultiportSwitch[0] = 1150U;
    rtb_MultiportSwitch[1] = 1150U;
    rtb_MultiportSwitch[2] = 1150U;
    rtb_MultiportSwitch[3] = 1150U;
    break;

   case 3:
    /* Switch: '<S43>/Switch' incorporates:
     *  Gain: '<S43>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_Switch_bt_idx_0 = 0.0F;
      rtb_Switch_bt_idx_1 = 0.0F;
      rtb_Switch_bt_idx_2 = 0.0F;
    } else {
      rtb_Switch_bt_idx_0 = rtb_DiscreteTimeIntegrator1_b_i;
      rtb_Switch_bt_idx_1 = rtb_a_n_idx_1;
      rtb_Switch_bt_idx_2 = rtb_DiscreteTimeIntegrator1_b_0;
    }

    /* End of Switch: '<S43>/Switch' */

    /* Switch: '<S23>/Switch' incorporates:
     *  Constant: '<S27>/Constant'
     *  Logic: '<S23>/Logical Operator'
     *  RelationalOperator: '<S26>/Compare'
     *  RelationalOperator: '<S27>/Compare'
     *  Switch: '<S23>/Switch1'
     */
    if ((Controller_U.FMS_Out.ctrl_mode == 1) || (Controller_U.FMS_Out.ctrl_mode
         == 2) || (Controller_U.FMS_Out.ctrl_mode == 3)) {
      rtb_throttle_cmd = Controller_U.FMS_Out.throttle_cmd;
    } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
      /* Switch: '<S28>/Switch' incorporates:
       *  DataTypeConversion: '<S25>/Data Type Conversion'
       *  S-Function (sfix_bitop): '<S28>/cmd_throttle valid'
       *  Switch: '<S23>/Switch1'
       */
      if ((Controller_U.FMS_Out.cmd_mask & 4096) > 0) {
        rtb_throttle_cmd = Controller_U.FMS_Out.throttle_cmd;
      } else {
        rtb_throttle_cmd = (uint16_T)rtb_DiscreteTimeIntegrator;
      }

      /* End of Switch: '<S28>/Switch' */
    } else {
      /* Switch: '<S23>/Switch1' incorporates:
       *  DataTypeConversion: '<S25>/Data Type Conversion'
       */
      rtb_throttle_cmd = (uint16_T)rtb_DiscreteTimeIntegrator;
    }

    /* End of Switch: '<S23>/Switch' */

    /* Saturate: '<S40>/Saturation' incorporates:
     *  Constant: '<S40>/gain1'
     *  Product: '<S40>/Multiply'
     */
    rtb_Saturation_m = CONTROL_PARAM.ROLL_RATE_D * rtb_Switch_bt_idx_0;
    if (rtb_Saturation_m > CONTROL_PARAM.RATE_D_MAX) {
      rtb_Saturation_m = CONTROL_PARAM.RATE_D_MAX;
    } else {
      if (rtb_Saturation_m < CONTROL_PARAM.RATE_D_MIN) {
        rtb_Saturation_m = CONTROL_PARAM.RATE_D_MIN;
      }
    }

    /* Saturate: '<S10>/Saturation1' incorporates:
     *  Constant: '<S42>/gain1'
     *  DiscreteIntegrator: '<S39>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S41>/Discrete-Time Integrator'
     *  Product: '<S42>/Multiply'
     *  Sum: '<S37>/Add'
     */
    rtb_Saturation_m += CONTROL_PARAM.ROLL_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0];
    if (rtb_Saturation_m > 1.0F) {
      rtb_Saturation_m = 1.0F;
    } else {
      if (rtb_Saturation_m < -1.0F) {
        rtb_Saturation_m = -1.0F;
      }
    }

    /* Saturate: '<S40>/Saturation' incorporates:
     *  Constant: '<S40>/gain2'
     *  Product: '<S40>/Multiply'
     */
    rtb_a_n_idx_0 = CONTROL_PARAM.PITCH_RATE_D * rtb_Switch_bt_idx_1;
    if (rtb_a_n_idx_0 > CONTROL_PARAM.RATE_D_MAX) {
      rtb_a_n_idx_0 = CONTROL_PARAM.RATE_D_MAX;
    } else {
      if (rtb_a_n_idx_0 < CONTROL_PARAM.RATE_D_MIN) {
        rtb_a_n_idx_0 = CONTROL_PARAM.RATE_D_MIN;
      }
    }

    /* Saturate: '<S10>/Saturation1' incorporates:
     *  Constant: '<S42>/gain2'
     *  DiscreteIntegrator: '<S39>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S41>/Discrete-Time Integrator'
     *  Product: '<S42>/Multiply'
     *  Sum: '<S37>/Add'
     */
    rtb_a_n_idx_0 += CONTROL_PARAM.PITCH_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1];
    if (rtb_a_n_idx_0 > 1.0F) {
      rtb_a_n_idx_0 = 1.0F;
    } else {
      if (rtb_a_n_idx_0 < -1.0F) {
        rtb_a_n_idx_0 = -1.0F;
      }
    }

    /* Saturate: '<S40>/Saturation' incorporates:
     *  Constant: '<S40>/gain3'
     *  Product: '<S40>/Multiply'
     */
    rtb_Switch_bt_idx_2 *= CONTROL_PARAM.YAW_RATE_D;
    if (rtb_Switch_bt_idx_2 > CONTROL_PARAM.RATE_D_MAX) {
      rtb_Switch_bt_idx_2 = CONTROL_PARAM.RATE_D_MAX;
    } else {
      if (rtb_Switch_bt_idx_2 < CONTROL_PARAM.RATE_D_MIN) {
        rtb_Switch_bt_idx_2 = CONTROL_PARAM.RATE_D_MIN;
      }
    }

    /* Saturate: '<S10>/Saturation1' incorporates:
     *  Constant: '<S42>/gain3'
     *  DiscreteIntegrator: '<S39>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S41>/Discrete-Time Integrator'
     *  Product: '<S42>/Multiply'
     *  Sum: '<S37>/Add'
     */
    rtb_Switch_bt_idx_2 += CONTROL_PARAM.YAW_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2];
    if (rtb_Switch_bt_idx_2 > 1.0F) {
      rtb_Switch_bt_idx_2 = 1.0F;
    } else {
      if (rtb_Switch_bt_idx_2 < -1.0F) {
        rtb_Switch_bt_idx_2 = -1.0F;
      }
    }

    /* Product: '<S10>/Multiply' */
    for (i = 0; i < 4; i++) {
      /* Saturate: '<S10>/Saturation' incorporates:
       *  Constant: '<S10>/Effective_Matrix'
       *  Gain: '<S10>/Gain'
       *  Sum: '<S10>/Add'
       */
      rtb_Add3 = fmodf(floorf(1000.0F *
        (Controller_ConstP.Effective_Matrix_Value[i + 8] * rtb_Switch_bt_idx_2 +
         (Controller_ConstP.Effective_Matrix_Value[i + 4] * rtb_a_n_idx_0 +
          Controller_ConstP.Effective_Matrix_Value[i] * rtb_Saturation_m))),
                       65536.0F);
      u0 = (uint16_T)((uint32_T)(rtb_Add3 < 0.0F ? (int32_T)(uint16_T)-(int16_T)
        (uint16_T)-rtb_Add3 : (int32_T)(uint16_T)rtb_Add3) + rtb_throttle_cmd);
      if (u0 > 1900) {
        rtb_MultiportSwitch[i] = 1900U;
      } else if (u0 < 1100) {
        rtb_MultiportSwitch[i] = 1100U;
      } else {
        rtb_MultiportSwitch[i] = u0;
      }

      /* End of Saturate: '<S10>/Saturation' */
    }

    /* End of Product: '<S10>/Multiply' */
    break;

   default:
    rtb_MultiportSwitch[0] = 1000U;
    rtb_MultiportSwitch[1] = 1000U;
    rtb_MultiportSwitch[2] = 1000U;
    rtb_MultiportSwitch[3] = 1000U;
    break;
  }

  /* End of MultiPortSwitch: '<S24>/Multiport Switch' */

  /* Product: '<S41>/Multiply' incorporates:
   *  Constant: '<S41>/gain1'
   *  Constant: '<S41>/gain2'
   *  Constant: '<S41>/gain3'
   *  DiscreteIntegrator: '<S39>/Discrete-Time Integrator5'
   */
  rtb_Switch_bt_idx_0 = CONTROL_PARAM.ROLL_RATE_I *
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[0];
  rtb_Switch_bt_idx_1 = CONTROL_PARAM.PITCH_RATE_I *
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1];
  rtb_Switch_bt_idx_2 = CONTROL_PARAM.YAW_RATE_I *
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[2];

  /* Product: '<S66>/Multiply1' incorporates:
   *  Constant: '<S66>/const1'
   *  DiscreteIntegrator: '<S63>/Integrator'
   */
  rtb_a_n_idx_0 = Controller_DW.Integrator_DSTATE[0] * 0.05F;
  rtb_Saturation_idx_1 = Controller_DW.Integrator_DSTATE[1] * 0.05F;

  /* Sum: '<S66>/Add' incorporates:
   *  DiscreteIntegrator: '<S63>/Integrator1'
   *  Inport: '<Root>/FMS_Out'
   *  Sum: '<S63>/Subtract'
   */
  rtb_Subtract3_i_idx_0 = (Controller_DW.Integrator1_DSTATE_g[0] -
    Controller_U.FMS_Out.u_cmd) + rtb_a_n_idx_0;
  rtb_Subtract3_i_idx_1 = (Controller_DW.Integrator1_DSTATE_g[1] -
    Controller_U.FMS_Out.v_cmd) + rtb_Saturation_idx_1;

  /* Signum: '<S66>/Sign' */
  if (rtb_Subtract3_i_idx_0 < 0.0F) {
    rtb_Saturation_m = -1.0F;
  } else if (rtb_Subtract3_i_idx_0 > 0.0F) {
    rtb_Saturation_m = 1.0F;
  } else {
    rtb_Saturation_m = rtb_Subtract3_i_idx_0;
  }

  /* Sum: '<S66>/Add2' incorporates:
   *  Abs: '<S66>/Abs'
   *  Gain: '<S66>/Gain'
   *  Gain: '<S66>/Gain1'
   *  Product: '<S66>/Multiply2'
   *  Product: '<S66>/Multiply3'
   *  Signum: '<S66>/Sign'
   *  Sqrt: '<S66>/Sqrt'
   *  Sum: '<S66>/Add1'
   *  Sum: '<S66>/Subtract'
   */
  rtb_Saturation_m = (sqrtf((8.0F * fabsf(rtb_Subtract3_i_idx_0) +
    Controller_ConstB.d) * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
    rtb_Saturation_m + rtb_a_n_idx_0;

  /* Sum: '<S66>/Add3' incorporates:
   *  Signum: '<S66>/Sign'
   */
  rtb_Add3 = rtb_Subtract3_i_idx_0 + Controller_ConstB.d;

  /* Sum: '<S66>/Subtract1' incorporates:
   *  Signum: '<S66>/Sign'
   */
  rtb_a = rtb_Subtract3_i_idx_0 - Controller_ConstB.d;

  /* Signum: '<S66>/Sign1' */
  if (rtb_Add3 < 0.0F) {
    rtb_Add3 = -1.0F;
  } else {
    if (rtb_Add3 > 0.0F) {
      rtb_Add3 = 1.0F;
    }
  }

  /* Signum: '<S66>/Sign2' */
  if (rtb_a < 0.0F) {
    rtb_a = -1.0F;
  } else {
    if (rtb_a > 0.0F) {
      rtb_a = 1.0F;
    }
  }

  /* Sum: '<S66>/Add2' incorporates:
   *  Gain: '<S66>/Gain2'
   *  Product: '<S66>/Multiply4'
   *  Signum: '<S66>/Sign'
   *  Sum: '<S66>/Add4'
   *  Sum: '<S66>/Add5'
   *  Sum: '<S66>/Subtract2'
   */
  rtb_a_n_idx_0 = ((rtb_Subtract3_i_idx_0 - rtb_Saturation_m) + rtb_a_n_idx_0) *
    ((rtb_Add3 - rtb_a) * 0.5F) + rtb_Saturation_m;

  /* Signum: '<S66>/Sign' */
  if (rtb_Subtract3_i_idx_1 < 0.0F) {
    rtb_Saturation_m = -1.0F;
  } else if (rtb_Subtract3_i_idx_1 > 0.0F) {
    rtb_Saturation_m = 1.0F;
  } else {
    rtb_Saturation_m = rtb_Subtract3_i_idx_1;
  }

  /* Sum: '<S66>/Add2' incorporates:
   *  Abs: '<S66>/Abs'
   *  Gain: '<S66>/Gain'
   *  Gain: '<S66>/Gain1'
   *  Product: '<S66>/Multiply2'
   *  Product: '<S66>/Multiply3'
   *  Signum: '<S66>/Sign'
   *  Sqrt: '<S66>/Sqrt'
   *  Sum: '<S66>/Add1'
   *  Sum: '<S66>/Subtract'
   */
  rtb_Saturation_m = (sqrtf((8.0F * fabsf(rtb_Subtract3_i_idx_1) +
    Controller_ConstB.d) * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
    rtb_Saturation_m + rtb_Saturation_idx_1;

  /* Sum: '<S66>/Add3' incorporates:
   *  Signum: '<S66>/Sign'
   */
  rtb_Add3 = rtb_Subtract3_i_idx_1 + Controller_ConstB.d;

  /* Sum: '<S66>/Subtract1' incorporates:
   *  Signum: '<S66>/Sign'
   */
  rtb_a = rtb_Subtract3_i_idx_1 - Controller_ConstB.d;

  /* Signum: '<S66>/Sign1' */
  if (rtb_Add3 < 0.0F) {
    rtb_Add3 = -1.0F;
  } else {
    if (rtb_Add3 > 0.0F) {
      rtb_Add3 = 1.0F;
    }
  }

  /* Signum: '<S66>/Sign2' */
  if (rtb_a < 0.0F) {
    rtb_a = -1.0F;
  } else {
    if (rtb_a > 0.0F) {
      rtb_a = 1.0F;
    }
  }

  /* Sum: '<S66>/Add5' incorporates:
   *  Gain: '<S66>/Gain2'
   *  Product: '<S66>/Multiply4'
   *  Signum: '<S66>/Sign'
   *  Sum: '<S66>/Add2'
   *  Sum: '<S66>/Add4'
   *  Sum: '<S66>/Subtract2'
   */
  rtb_Saturation_m += ((rtb_Subtract3_i_idx_1 - rtb_Saturation_m) +
                       rtb_Saturation_idx_1) * ((rtb_Add3 - rtb_a) * 0.5F);

  /* Outport: '<Root>/Control_Out' incorporates:
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   *  Reshape: '<S24>/Reshape'
   */
  Controller_Y.Control_Out.timestamp =
    Controller_DW.DiscreteTimeIntegrator_DSTATE_n;
  Controller_Y.Control_Out.actuator_cmd[0] = rtb_MultiportSwitch[0];
  Controller_Y.Control_Out.actuator_cmd[1] = rtb_MultiportSwitch[1];
  Controller_Y.Control_Out.actuator_cmd[2] = rtb_MultiportSwitch[2];
  Controller_Y.Control_Out.actuator_cmd[3] = rtb_MultiportSwitch[3];
  for (rtb_DiscreteTimeIntegrator = 0; rtb_DiscreteTimeIntegrator < 12;
       rtb_DiscreteTimeIntegrator++) {
    Controller_Y.Control_Out.actuator_cmd[rtb_DiscreteTimeIntegrator + 4] = 0U;
  }

  /* End of Outport: '<Root>/Control_Out' */

  /* Product: '<S85>/Multiply1' incorporates:
   *  Constant: '<S85>/const1'
   *  DiscreteIntegrator: '<S84>/Integrator'
   */
  rtb_Add3 = Controller_DW.Integrator_DSTATE_p * 0.05F;

  /* Sum: '<S85>/Add' incorporates:
   *  DiscreteIntegrator: '<S84>/Integrator1'
   *  Inport: '<Root>/FMS_Out'
   *  Sum: '<S84>/Subtract'
   */
  rtb_Saturation_idx_1 = (Controller_DW.Integrator1_DSTATE -
    Controller_U.FMS_Out.w_cmd) + rtb_Add3;

  /* Signum: '<S85>/Sign' */
  if (rtb_Saturation_idx_1 < 0.0F) {
    rtb_a = -1.0F;
  } else if (rtb_Saturation_idx_1 > 0.0F) {
    rtb_a = 1.0F;
  } else {
    rtb_a = rtb_Saturation_idx_1;
  }

  /* End of Signum: '<S85>/Sign' */

  /* Sum: '<S85>/Add2' incorporates:
   *  Abs: '<S85>/Abs'
   *  Gain: '<S85>/Gain'
   *  Gain: '<S85>/Gain1'
   *  Product: '<S85>/Multiply2'
   *  Product: '<S85>/Multiply3'
   *  Sqrt: '<S85>/Sqrt'
   *  Sum: '<S85>/Add1'
   *  Sum: '<S85>/Subtract'
   */
  rtb_a = (sqrtf((8.0F * fabsf(rtb_Saturation_idx_1) + Controller_ConstB.d_n) *
                 Controller_ConstB.d_n) - Controller_ConstB.d_n) * 0.5F * rtb_a
    + rtb_Add3;

  /* Sum: '<S85>/Add4' */
  rtb_Subtract3_i_idx_1 = (rtb_Saturation_idx_1 - rtb_a) + rtb_Add3;

  /* Sum: '<S85>/Add3' */
  rtb_Add3 = rtb_Saturation_idx_1 + Controller_ConstB.d_n;

  /* Sum: '<S85>/Subtract1' */
  rtb_Saturation_idx_1 -= Controller_ConstB.d_n;

  /* Signum: '<S85>/Sign1' */
  if (rtb_Add3 < 0.0F) {
    rtb_Add3 = -1.0F;
  } else {
    if (rtb_Add3 > 0.0F) {
      rtb_Add3 = 1.0F;
    }
  }

  /* End of Signum: '<S85>/Sign1' */

  /* Signum: '<S85>/Sign2' */
  if (rtb_Saturation_idx_1 < 0.0F) {
    rtb_Saturation_idx_1 = -1.0F;
  } else {
    if (rtb_Saturation_idx_1 > 0.0F) {
      rtb_Saturation_idx_1 = 1.0F;
    }
  }

  /* End of Signum: '<S85>/Sign2' */

  /* Sum: '<S85>/Add5' incorporates:
   *  Gain: '<S85>/Gain2'
   *  Product: '<S85>/Multiply4'
   *  Sum: '<S85>/Subtract2'
   */
  rtb_a += (rtb_Add3 - rtb_Saturation_idx_1) * 0.5F * rtb_Subtract3_i_idx_1;

  /* Update for DiscreteIntegrator: '<S84>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S84>/Integrator'
   */
  Controller_DW.Integrator1_DSTATE += 0.002F * Controller_DW.Integrator_DSTATE_p;

  /* Update for DiscreteIntegrator: '<S87>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S87>/ki'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S87>/Multiply'
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

  /* End of Update for DiscreteIntegrator: '<S87>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S89>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_DSTATE += 0.002F * rtb_Gain;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S68>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator_PrevRe_e = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S63>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S63>/Integrator'
   */
  Controller_DW.Integrator1_DSTATE_g[0] += 0.002F *
    Controller_DW.Integrator_DSTATE[0];

  /* Update for DiscreteIntegrator: '<S68>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S68>/ki'
   *  Product: '<S68>/Multiply'
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

  /* Update for DiscreteIntegrator: '<S70>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[0] += 0.002F * rtb_Gain_j_idx_0;

  /* Update for DiscreteIntegrator: '<S63>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S63>/Integrator'
   */
  Controller_DW.Integrator1_DSTATE_g[1] += 0.002F *
    Controller_DW.Integrator_DSTATE[1];

  /* Update for DiscreteIntegrator: '<S68>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S68>/ki'
   *  Product: '<S68>/Multiply'
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

  /* Update for DiscreteIntegrator: '<S70>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[1] += 0.002F * rtb_Gain_j_idx_1;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_a = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S39>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;

  /* Update for DiscreteIntegrator: '<S41>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator_PrevRe_g = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S39>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S39>/Gain'
   *  Sum: '<S39>/Sum5'
   */
  Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] +=
    (rtb_rate_error_B_radPs_idx_0 -
     Controller_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 188.49556F * 0.002F;

  /* Update for DiscreteIntegrator: '<S41>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] += 0.002F *
    rtb_Switch_bt_idx_0;
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

  /* Update for DiscreteIntegrator: '<S43>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[0] += 0.002F *
    rtb_DiscreteTimeIntegrator1_b_i;

  /* Update for DiscreteIntegrator: '<S39>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S39>/Gain'
   *  Sum: '<S39>/Sum5'
   */
  Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] += (rtb_Multiply4_b -
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 188.49556F * 0.002F;

  /* Update for DiscreteIntegrator: '<S41>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] += 0.002F *
    rtb_Switch_bt_idx_1;
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

  /* Update for DiscreteIntegrator: '<S43>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[1] += 0.002F * rtb_a_n_idx_1;

  /* Update for DiscreteIntegrator: '<S39>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S39>/Gain'
   *  Sum: '<S39>/Sum5'
   */
  Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] +=
    (rtb_rate_error_B_radPs_idx_2 -
     Controller_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 188.49556F * 0.002F;

  /* Update for DiscreteIntegrator: '<S41>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] += 0.002F *
    rtb_Switch_bt_idx_2;
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

  /* Update for DiscreteIntegrator: '<S43>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[2] += 0.002F *
    rtb_DiscreteTimeIntegrator1_b_0;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_i = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Signum: '<S66>/Sign3' incorporates:
   *  Product: '<S66>/Divide'
   *  Sum: '<S66>/Add6'
   */
  rtb_Add3 = rtb_a_n_idx_0 + Controller_ConstB.d;

  /* Signum: '<S66>/Sign4' incorporates:
   *  Product: '<S66>/Divide'
   *  Sum: '<S66>/Subtract3'
   */
  rtb_Gain_f = rtb_a_n_idx_0 - Controller_ConstB.d;

  /* Signum: '<S66>/Sign5' incorporates:
   *  Product: '<S66>/Divide'
   */
  if (rtb_a_n_idx_0 < 0.0F) {
    rtb_Gain = -1.0F;
  } else if (rtb_a_n_idx_0 > 0.0F) {
    rtb_Gain = 1.0F;
  } else {
    rtb_Gain = rtb_a_n_idx_0;
  }

  /* Signum: '<S66>/Sign3' */
  if (rtb_Add3 < 0.0F) {
    rtb_Add3 = -1.0F;
  } else {
    if (rtb_Add3 > 0.0F) {
      rtb_Add3 = 1.0F;
    }
  }

  /* Signum: '<S66>/Sign4' */
  if (rtb_Gain_f < 0.0F) {
    rtb_Gain_f = -1.0F;
  } else {
    if (rtb_Gain_f > 0.0F) {
      rtb_Gain_f = 1.0F;
    }
  }

  /* Signum: '<S66>/Sign6' incorporates:
   *  Product: '<S66>/Divide'
   */
  if (rtb_a_n_idx_0 < 0.0F) {
    rtb_Add = -1.0F;
  } else if (rtb_a_n_idx_0 > 0.0F) {
    rtb_Add = 1.0F;
  } else {
    rtb_Add = rtb_a_n_idx_0;
  }

  /* Update for DiscreteIntegrator: '<S63>/Integrator' incorporates:
   *  Constant: '<S66>/const'
   *  Gain: '<S66>/Gain3'
   *  Product: '<S66>/Divide'
   *  Product: '<S66>/Multiply5'
   *  Product: '<S66>/Multiply6'
   *  Sum: '<S66>/Subtract4'
   *  Sum: '<S66>/Subtract5'
   *  Sum: '<S66>/Subtract6'
   */
  Controller_DW.Integrator_DSTATE[0] += ((rtb_a_n_idx_0 / Controller_ConstB.d -
    rtb_Gain) * Controller_ConstB.Gain4 * ((rtb_Add3 - rtb_Gain_f) * 0.5F) -
    rtb_Add * 58.836F) * 0.002F;

  /* Signum: '<S66>/Sign3' incorporates:
   *  Sum: '<S66>/Add6'
   */
  rtb_Add3 = rtb_Saturation_m + Controller_ConstB.d;

  /* Signum: '<S66>/Sign4' incorporates:
   *  Sum: '<S66>/Subtract3'
   */
  rtb_Gain_f = rtb_Saturation_m - Controller_ConstB.d;

  /* Signum: '<S66>/Sign5' */
  if (rtb_Saturation_m < 0.0F) {
    rtb_Gain = -1.0F;
  } else if (rtb_Saturation_m > 0.0F) {
    rtb_Gain = 1.0F;
  } else {
    rtb_Gain = rtb_Saturation_m;
  }

  /* Signum: '<S66>/Sign3' */
  if (rtb_Add3 < 0.0F) {
    rtb_Add3 = -1.0F;
  } else {
    if (rtb_Add3 > 0.0F) {
      rtb_Add3 = 1.0F;
    }
  }

  /* Signum: '<S66>/Sign4' */
  if (rtb_Gain_f < 0.0F) {
    rtb_Gain_f = -1.0F;
  } else {
    if (rtb_Gain_f > 0.0F) {
      rtb_Gain_f = 1.0F;
    }
  }

  /* Signum: '<S66>/Sign6' */
  if (rtb_Saturation_m < 0.0F) {
    rtb_Add = -1.0F;
  } else if (rtb_Saturation_m > 0.0F) {
    rtb_Add = 1.0F;
  } else {
    rtb_Add = rtb_Saturation_m;
  }

  /* Update for DiscreteIntegrator: '<S63>/Integrator' incorporates:
   *  Constant: '<S66>/const'
   *  Gain: '<S66>/Gain3'
   *  Product: '<S66>/Divide'
   *  Product: '<S66>/Multiply5'
   *  Product: '<S66>/Multiply6'
   *  Sum: '<S66>/Subtract4'
   *  Sum: '<S66>/Subtract5'
   *  Sum: '<S66>/Subtract6'
   */
  Controller_DW.Integrator_DSTATE[1] += ((rtb_Saturation_m / Controller_ConstB.d
    - rtb_Gain) * Controller_ConstB.Gain4 * ((rtb_Add3 - rtb_Gain_f) * 0.5F) -
    rtb_Add * 58.836F) * 0.002F;

  /* Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S3>/Constant'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_n += CONTROL_EXPORT.period;

  /* Signum: '<S85>/Sign6' incorporates:
   *  Signum: '<S85>/Sign5'
   */
  if (rtb_a < 0.0F) {
    rtb_Gain = -1.0F;

    /* Signum: '<S85>/Sign5' */
    rtb_Add = -1.0F;
  } else if (rtb_a > 0.0F) {
    rtb_Gain = 1.0F;

    /* Signum: '<S85>/Sign5' */
    rtb_Add = 1.0F;
  } else {
    rtb_Gain = rtb_a;

    /* Signum: '<S85>/Sign5' */
    rtb_Add = rtb_a;
  }

  /* End of Signum: '<S85>/Sign6' */

  /* Sum: '<S85>/Add6' */
  rtb_Add3 = rtb_a + Controller_ConstB.d_n;

  /* Sum: '<S85>/Subtract3' */
  rtb_Gain_f = rtb_a - Controller_ConstB.d_n;

  /* Signum: '<S85>/Sign3' */
  if (rtb_Add3 < 0.0F) {
    rtb_Add3 = -1.0F;
  } else {
    if (rtb_Add3 > 0.0F) {
      rtb_Add3 = 1.0F;
    }
  }

  /* End of Signum: '<S85>/Sign3' */

  /* Signum: '<S85>/Sign4' */
  if (rtb_Gain_f < 0.0F) {
    rtb_Gain_f = -1.0F;
  } else {
    if (rtb_Gain_f > 0.0F) {
      rtb_Gain_f = 1.0F;
    }
  }

  /* End of Signum: '<S85>/Sign4' */

  /* Update for DiscreteIntegrator: '<S84>/Integrator' incorporates:
   *  Constant: '<S85>/const'
   *  Gain: '<S85>/Gain3'
   *  Product: '<S85>/Divide'
   *  Product: '<S85>/Multiply5'
   *  Product: '<S85>/Multiply6'
   *  Sum: '<S85>/Subtract4'
   *  Sum: '<S85>/Subtract5'
   *  Sum: '<S85>/Subtract6'
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

  /* InitializeConditions for DiscreteIntegrator: '<S87>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S87>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S89>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S68>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S68>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S70>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_PrevR_a = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S39>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S41>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S41>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S43>/Discrete-Time Integrator1' */
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
