/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.840
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Jul 31 15:22:50 2021
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
  0.075F,
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
                                        *   '<S34>/Saturation'
                                        *   '<S13>/Saturation'
                                        *   '<S13>/Saturation1'
                                        *   '<S42>/kd'
                                        *   '<S42>/Saturation'
                                        *   '<S43>/ki'
                                        *   '<S43>/Discrete-Time Integrator'
                                        *   '<S44>/kp'
                                        *   '<S55>/kd'
                                        *   '<S55>/Saturation'
                                        *   '<S56>/ki'
                                        *   '<S56>/Discrete-Time Integrator'
                                        *   '<S57>/kp'
                                        *   '<S29>/Constant1'
                                        *   '<S29>/Constant2'
                                        *   '<S18>/gain1'
                                        *   '<S18>/gain2'
                                        *   '<S18>/gain3'
                                        *   '<S18>/Saturation'
                                        *   '<S19>/gain1'
                                        *   '<S19>/gain2'
                                        *   '<S19>/gain3'
                                        *   '<S19>/Discrete-Time Integrator'
                                        *   '<S20>/gain1'
                                        *   '<S20>/gain2'
                                        *   '<S20>/gain3'
                                        */

struct_biZzOMrg0u3lxrb7POOubF CONTROL_EXPORT = {
  2U,

  { 66, 97, 115, 101, 32, 67, 111, 110, 116, 114, 111, 108, 108, 101, 114, 32,
    118, 48, 46, 49, 46, 49, 0 }
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
  real32_T rtb_Gain;
  real32_T rtb_Gain_am;
  real32_T rtb_VectorConcatenate[9];
  real32_T rtb_Add3;
  real32_T rtb_Subtract3_i;
  real32_T rtb_Sign5_f;
  real32_T rtb_Add4_i;
  real32_T rtb_Saturation_m;
  real32_T rtb_Cos;
  real32_T rtb_Cos1;
  real32_T rtb_Multiply4_my;
  real32_T rtb_Multiply3_c;
  uint32_T rtb_throttle_cmd;
  int32_T i;
  real32_T rtb_VectorConcatenate_0[3];
  real32_T rtb_Saturation_o;
  real32_T rtb_DiscreteTimeIntegrator1_b_i;
  real32_T rtb_Atan_idx_0;
  real32_T rtb_Atan_idx_1;
  real32_T rtb_Saturation1_i_idx_0;
  real32_T rtb_Saturation1_i_idx_1;
  real32_T rtb_uv_error_C_mPs_idx_0;
  real32_T rtb_uv_error_C_mPs_idx_1;
  real32_T rtb_Gain_j_idx_0;
  real32_T rtb_Gain_j_idx_1;
  real32_T rtb_Saturation_d_idx_1;
  real32_T rtb_Saturation_d_idx_2;
  uint16_T u0;

  /* Gain: '<S51>/Gain' incorporates:
   *  DiscreteIntegrator: '<S53>/Integrator1'
   *  Inport: '<Root>/INS_Out'
   *  Sum: '<S51>/Sum1'
   */
  rtb_Gain = -(Controller_DW.Integrator1_DSTATE - Controller_U.INS_Out.vd);

  /* DiscreteIntegrator: '<S56>/Discrete-Time Integrator' incorporates:
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

  /* DiscreteIntegrator: '<S58>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevRes != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTATE = 0.0F;
  }

  /* Gain: '<S58>/Gain' incorporates:
   *  DiscreteIntegrator: '<S58>/Discrete-Time Integrator1'
   *  Sum: '<S58>/Sum5'
   */
  rtb_Gain_am = (rtb_Gain - Controller_DW.DiscreteTimeIntegrator1_DSTATE) *
    62.831852F;

  /* Trigonometry: '<S40>/Trigonometric Function1' incorporates:
   *  Gain: '<S39>/Gain'
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S40>/Trigonometric Function3'
   */
  rtb_uv_error_C_mPs_idx_0 = arm_cos_f32(-Controller_U.INS_Out.psi);
  rtb_VectorConcatenate[0] = rtb_uv_error_C_mPs_idx_0;

  /* Trigonometry: '<S40>/Trigonometric Function' incorporates:
   *  Gain: '<S39>/Gain'
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S40>/Trigonometric Function2'
   */
  rtb_uv_error_C_mPs_idx_1 = arm_sin_f32(-Controller_U.INS_Out.psi);
  rtb_VectorConcatenate[1] = rtb_uv_error_C_mPs_idx_1;

  /* SignalConversion: '<S40>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S40>/Constant3'
   */
  rtb_VectorConcatenate[2] = 0.0F;

  /* Gain: '<S40>/Gain' */
  rtb_VectorConcatenate[3] = -rtb_uv_error_C_mPs_idx_1;

  /* Trigonometry: '<S40>/Trigonometric Function3' */
  rtb_VectorConcatenate[4] = rtb_uv_error_C_mPs_idx_0;

  /* SignalConversion: '<S40>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S40>/Constant4'
   */
  rtb_VectorConcatenate[5] = 0.0F;

  /* SignalConversion: '<S40>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate[6] = Controller_ConstB.VectorConcatenate3[0];
  rtb_VectorConcatenate[7] = Controller_ConstB.VectorConcatenate3[1];
  rtb_VectorConcatenate[8] = Controller_ConstB.VectorConcatenate3[2];

  /* Product: '<S37>/Multiply' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  SignalConversion: '<S37>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_0[i] = rtb_VectorConcatenate[i + 3] *
      Controller_U.INS_Out.ve + rtb_VectorConcatenate[i] *
      Controller_U.INS_Out.vn;
  }

  /* End of Product: '<S37>/Multiply' */

  /* Sum: '<S35>/Sum' incorporates:
   *  DiscreteIntegrator: '<S38>/Integrator1'
   */
  rtb_uv_error_C_mPs_idx_0 = Controller_DW.Integrator1_DSTATE_g[0] -
    rtb_VectorConcatenate_0[0];
  rtb_uv_error_C_mPs_idx_1 = Controller_DW.Integrator1_DSTATE_g[1] -
    rtb_VectorConcatenate_0[1];

  /* DiscreteIntegrator: '<S43>/Discrete-Time Integrator' incorporates:
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

  /* DiscreteIntegrator: '<S45>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevR_a != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[0] = 0.0F;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[1] = 0.0F;
  }

  /* Gain: '<S45>/Gain' incorporates:
   *  DiscreteIntegrator: '<S45>/Discrete-Time Integrator1'
   *  Sum: '<S45>/Sum5'
   */
  rtb_Gain_j_idx_0 = (rtb_uv_error_C_mPs_idx_0 -
                      Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[0]) *
    62.831852F;
  rtb_Gain_j_idx_1 = (rtb_uv_error_C_mPs_idx_1 -
                      Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[1]) *
    62.831852F;

  /* Switch: '<S14>/Switch' incorporates:
   *  Constant: '<S25>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  Inport: '<Root>/INS_Out'
   *  Product: '<S22>/Multiply'
   *  Product: '<S22>/Multiply1'
   *  Product: '<S22>/Multiply5'
   *  Product: '<S31>/Divide1'
   *  RelationalOperator: '<S25>/Compare'
   *  Saturate: '<S13>/Saturation'
   *  Sum: '<S22>/Add'
   *  Sum: '<S22>/Add1'
   *  Sum: '<S22>/Add2'
   *  Trigonometry: '<S22>/Sin1'
   */
  if (Controller_U.FMS_Out.mode == 5) {
    rtb_DiscreteTimeIntegrator1_b_i = Controller_U.FMS_Out.p_cmd;
    rtb_Multiply3_c = Controller_U.FMS_Out.q_cmd;
    rtb_Saturation_m = Controller_U.FMS_Out.r_cmd;
  } else {
    if (Controller_DW.Integrator1_DSTATE_d > CONTROL_PARAM.R_CMD_LIM) {
      /* Saturate: '<S13>/Saturation' */
      rtb_Saturation_m = CONTROL_PARAM.R_CMD_LIM;
    } else if (Controller_DW.Integrator1_DSTATE_d < -CONTROL_PARAM.R_CMD_LIM) {
      /* Saturate: '<S13>/Saturation' */
      rtb_Saturation_m = -CONTROL_PARAM.R_CMD_LIM;
    } else {
      /* Saturate: '<S13>/Saturation' */
      rtb_Saturation_m = Controller_DW.Integrator1_DSTATE_d;
    }

    /* Switch: '<S27>/Switch' incorporates:
     *  Constant: '<S33>/Constant'
     *  RelationalOperator: '<S33>/Compare'
     *  Saturate: '<S13>/Saturation'
     *  Switch: '<S45>/Switch'
     *  Trigonometry: '<S34>/Atan'
     */
    if (Controller_U.FMS_Out.mode >= 3) {
      rtb_Atan_idx_0 = Controller_U.FMS_Out.phi_cmd;
      rtb_Atan_idx_1 = Controller_U.FMS_Out.theta_cmd;
    } else {
      if (Controller_U.FMS_Out.reset > 0) {
        /* Switch: '<S45>/Switch' incorporates:
         *  Gain: '<S45>/Gain1'
         */
        rtb_Atan_idx_0 = 0.0F;
        rtb_Atan_idx_1 = 0.0F;
      } else {
        /* Switch: '<S45>/Switch' */
        rtb_Atan_idx_0 = rtb_Gain_j_idx_0;
        rtb_Atan_idx_1 = rtb_Gain_j_idx_1;
      }

      /* Product: '<S42>/Multiply' incorporates:
       *  Constant: '<S42>/kd'
       */
      rtb_DiscreteTimeIntegrator1_b_i = CONTROL_PARAM.VEL_XY_D * rtb_Atan_idx_0;

      /* Saturate: '<S42>/Saturation' */
      if (rtb_DiscreteTimeIntegrator1_b_i > CONTROL_PARAM.VEL_XY_D_MAX) {
        rtb_DiscreteTimeIntegrator1_b_i = CONTROL_PARAM.VEL_XY_D_MAX;
      } else {
        if (rtb_DiscreteTimeIntegrator1_b_i < CONTROL_PARAM.VEL_XY_D_MIN) {
          rtb_DiscreteTimeIntegrator1_b_i = CONTROL_PARAM.VEL_XY_D_MIN;
        }
      }

      /* Gain: '<S34>/Gain1' incorporates:
       *  Constant: '<S44>/kp'
       *  DiscreteIntegrator: '<S43>/Discrete-Time Integrator'
       *  Product: '<S42>/Multiply'
       *  Product: '<S44>/Multiply'
       *  Sum: '<S36>/Add'
       */
      rtb_Saturation_d_idx_2 = (CONTROL_PARAM.VEL_XY_P *
        rtb_uv_error_C_mPs_idx_0 +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0]) +
        rtb_DiscreteTimeIntegrator1_b_i;

      /* Product: '<S42>/Multiply' incorporates:
       *  Constant: '<S42>/kd'
       */
      rtb_DiscreteTimeIntegrator1_b_i = CONTROL_PARAM.VEL_XY_D * rtb_Atan_idx_1;

      /* Saturate: '<S42>/Saturation' */
      if (rtb_DiscreteTimeIntegrator1_b_i > CONTROL_PARAM.VEL_XY_D_MAX) {
        rtb_DiscreteTimeIntegrator1_b_i = CONTROL_PARAM.VEL_XY_D_MAX;
      } else {
        if (rtb_DiscreteTimeIntegrator1_b_i < CONTROL_PARAM.VEL_XY_D_MIN) {
          rtb_DiscreteTimeIntegrator1_b_i = CONTROL_PARAM.VEL_XY_D_MIN;
        }
      }

      /* Sum: '<S36>/Add' incorporates:
       *  Constant: '<S44>/kp'
       *  DiscreteIntegrator: '<S43>/Discrete-Time Integrator'
       *  Product: '<S44>/Multiply'
       */
      rtb_DiscreteTimeIntegrator1_b_i += CONTROL_PARAM.VEL_XY_P *
        rtb_uv_error_C_mPs_idx_1 +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1];

      /* Trigonometry: '<S34>/Atan' incorporates:
       *  Constant: '<S34>/g'
       *  Gain: '<S34>/gain'
       *  Product: '<S34>/Divide'
       */
      rtb_Atan_idx_1 = atanf(1.1F * rtb_DiscreteTimeIntegrator1_b_i / 9.8055F);

      /* Saturate: '<S34>/Saturation' */
      if (rtb_Atan_idx_1 > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
        rtb_Atan_idx_1 = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_Atan_idx_1 < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
          rtb_Atan_idx_1 = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
        }
      }

      rtb_Atan_idx_0 = rtb_Atan_idx_1;

      /* Trigonometry: '<S34>/Atan' incorporates:
       *  Constant: '<S34>/g'
       *  Gain: '<S34>/Gain1'
       *  Gain: '<S34>/gain'
       *  Product: '<S34>/Divide'
       */
      rtb_Atan_idx_1 = atanf(1.1F * -rtb_Saturation_d_idx_2 / 9.8055F);

      /* Saturate: '<S34>/Saturation' */
      if (rtb_Atan_idx_1 > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
        rtb_Atan_idx_1 = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_Atan_idx_1 < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
          rtb_Atan_idx_1 = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
        }
      }
    }

    /* End of Switch: '<S27>/Switch' */

    /* Sum: '<S28>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_DiscreteTimeIntegrator1_b_i = rtb_Atan_idx_0 - Controller_U.INS_Out.phi;

    /* Product: '<S31>/Divide1' incorporates:
     *  Abs: '<S31>/Abs'
     *  Constant: '<S31>/const2'
     */
    rtb_Saturation_d_idx_1 = fabsf(rtb_DiscreteTimeIntegrator1_b_i) / 0.002F;

    /* Gain: '<S31>/Gain3' */
    rtb_Saturation_d_idx_2 = -rtb_Saturation_d_idx_1;

    /* Product: '<S31>/Divide' incorporates:
     *  Constant: '<S29>/Constant1'
     *  Constant: '<S31>/const1'
     *  Math: '<S31>/Square'
     *  SignalConversion: '<S31>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_Multiply3_c = 9.5993F / (CONTROL_PARAM.ROLL_P * CONTROL_PARAM.ROLL_P);

    /* Signum: '<S31>/Sign' */
    if (rtb_DiscreteTimeIntegrator1_b_i < 0.0F) {
      rtb_Cos = -1.0F;
    } else if (rtb_DiscreteTimeIntegrator1_b_i > 0.0F) {
      rtb_Cos = 1.0F;
    } else {
      rtb_Cos = rtb_DiscreteTimeIntegrator1_b_i;
    }

    /* Switch: '<S31>/Switch' incorporates:
     *  Constant: '<S29>/Constant1'
     *  Gain: '<S31>/Gain1'
     *  Gain: '<S31>/Gain2'
     *  Logic: '<S31>/Logical Operator'
     *  Product: '<S31>/Multiply'
     *  Product: '<S31>/Multiply1'
     *  Product: '<S31>/Multiply2'
     *  Product: '<S31>/Multiply3'
     *  RelationalOperator: '<S31>/Relational Operator'
     *  RelationalOperator: '<S31>/Relational Operator2'
     *  SignalConversion: '<S31>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S31>/Sqrt'
     *  Sum: '<S31>/Subtract'
     */
    if ((rtb_DiscreteTimeIntegrator1_b_i <= rtb_Multiply3_c) &&
        (rtb_DiscreteTimeIntegrator1_b_i >= -rtb_Multiply3_c)) {
      rtb_DiscreteTimeIntegrator1_b_i *= CONTROL_PARAM.ROLL_P;
    } else {
      rtb_DiscreteTimeIntegrator1_b_i = sqrtf((rtb_Cos *
        rtb_DiscreteTimeIntegrator1_b_i - 0.5F * rtb_Multiply3_c) *
        Controller_ConstB.Gain) * rtb_Cos;
    }

    /* Switch: '<S32>/Switch' incorporates:
     *  Gain: '<S31>/Gain3'
     *  RelationalOperator: '<S32>/UpperRelop'
     */
    if (rtb_DiscreteTimeIntegrator1_b_i >= -rtb_Saturation_d_idx_1) {
      rtb_Saturation_d_idx_2 = rtb_DiscreteTimeIntegrator1_b_i;
    }

    /* Switch: '<S32>/Switch2' incorporates:
     *  RelationalOperator: '<S32>/LowerRelop1'
     */
    if (rtb_DiscreteTimeIntegrator1_b_i <= rtb_Saturation_d_idx_1) {
      rtb_Saturation_d_idx_1 = rtb_Saturation_d_idx_2;
    }

    /* Saturate: '<S13>/Saturation1' */
    if (rtb_Saturation_d_idx_1 > CONTROL_PARAM.P_Q_CMD_LIM) {
      rtb_Saturation_d_idx_1 = CONTROL_PARAM.P_Q_CMD_LIM;
    } else {
      if (rtb_Saturation_d_idx_1 < -CONTROL_PARAM.P_Q_CMD_LIM) {
        rtb_Saturation_d_idx_1 = -CONTROL_PARAM.P_Q_CMD_LIM;
      }
    }

    rtb_Saturation1_i_idx_0 = rtb_Saturation_d_idx_1;

    /* Sum: '<S28>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S31>/Divide1'
     */
    rtb_DiscreteTimeIntegrator1_b_i = rtb_Atan_idx_1 -
      Controller_U.INS_Out.theta;

    /* Product: '<S31>/Divide1' incorporates:
     *  Abs: '<S31>/Abs'
     *  Constant: '<S31>/const2'
     */
    rtb_Saturation_d_idx_1 = fabsf(rtb_DiscreteTimeIntegrator1_b_i) / 0.002F;

    /* Gain: '<S31>/Gain3' */
    rtb_Saturation_d_idx_2 = -rtb_Saturation_d_idx_1;

    /* Product: '<S31>/Divide' incorporates:
     *  Constant: '<S29>/Constant2'
     *  Constant: '<S31>/const1'
     *  Math: '<S31>/Square'
     *  SignalConversion: '<S31>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_Multiply3_c = 9.5993F / (CONTROL_PARAM.PITCH_P * CONTROL_PARAM.PITCH_P);

    /* Signum: '<S31>/Sign' */
    if (rtb_DiscreteTimeIntegrator1_b_i < 0.0F) {
      rtb_Cos = -1.0F;
    } else if (rtb_DiscreteTimeIntegrator1_b_i > 0.0F) {
      rtb_Cos = 1.0F;
    } else {
      rtb_Cos = rtb_DiscreteTimeIntegrator1_b_i;
    }

    /* Switch: '<S31>/Switch' incorporates:
     *  Constant: '<S29>/Constant2'
     *  Gain: '<S31>/Gain1'
     *  Gain: '<S31>/Gain2'
     *  Logic: '<S31>/Logical Operator'
     *  Product: '<S31>/Multiply'
     *  Product: '<S31>/Multiply1'
     *  Product: '<S31>/Multiply2'
     *  Product: '<S31>/Multiply3'
     *  RelationalOperator: '<S31>/Relational Operator'
     *  RelationalOperator: '<S31>/Relational Operator2'
     *  SignalConversion: '<S31>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S31>/Sqrt'
     *  Sum: '<S31>/Subtract'
     */
    if ((rtb_DiscreteTimeIntegrator1_b_i <= rtb_Multiply3_c) &&
        (rtb_DiscreteTimeIntegrator1_b_i >= -rtb_Multiply3_c)) {
      rtb_DiscreteTimeIntegrator1_b_i *= CONTROL_PARAM.PITCH_P;
    } else {
      rtb_DiscreteTimeIntegrator1_b_i = sqrtf((rtb_Cos *
        rtb_DiscreteTimeIntegrator1_b_i - 0.5F * rtb_Multiply3_c) *
        Controller_ConstB.Gain) * rtb_Cos;
    }

    /* Switch: '<S32>/Switch' incorporates:
     *  Gain: '<S31>/Gain3'
     *  RelationalOperator: '<S32>/UpperRelop'
     */
    if (rtb_DiscreteTimeIntegrator1_b_i >= -rtb_Saturation_d_idx_1) {
      rtb_Saturation_d_idx_2 = rtb_DiscreteTimeIntegrator1_b_i;
    }

    /* Switch: '<S32>/Switch2' incorporates:
     *  RelationalOperator: '<S32>/LowerRelop1'
     */
    if (rtb_DiscreteTimeIntegrator1_b_i <= rtb_Saturation_d_idx_1) {
      rtb_Saturation_d_idx_1 = rtb_Saturation_d_idx_2;
    }

    /* Saturate: '<S13>/Saturation1' */
    if (rtb_Saturation_d_idx_1 > CONTROL_PARAM.P_Q_CMD_LIM) {
      rtb_Saturation_d_idx_1 = CONTROL_PARAM.P_Q_CMD_LIM;
    } else {
      if (rtb_Saturation_d_idx_1 < -CONTROL_PARAM.P_Q_CMD_LIM) {
        rtb_Saturation_d_idx_1 = -CONTROL_PARAM.P_Q_CMD_LIM;
      }
    }

    /* Trigonometry: '<S22>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Cos = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S22>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Cos1 = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Trigonometry: '<S22>/Sin' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Multiply4_my = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Product: '<S22>/Multiply3' */
    rtb_Multiply3_c = rtb_Multiply4_my * rtb_Cos1 * rtb_Saturation_m;

    /* Product: '<S22>/Multiply4' */
    rtb_Multiply4_my *= rtb_Saturation_d_idx_1;
    rtb_DiscreteTimeIntegrator1_b_i = rtb_Saturation1_i_idx_0 - arm_sin_f32
      (Controller_U.INS_Out.theta) * rtb_Saturation_m;
    rtb_Multiply3_c += rtb_Cos * rtb_Saturation_d_idx_1;
    rtb_Saturation_m = rtb_Cos * rtb_Cos1 * rtb_Saturation_m - rtb_Multiply4_my;
  }

  /* End of Switch: '<S14>/Switch' */

  /* Sum: '<S15>/Sum' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Cos = rtb_DiscreteTimeIntegrator1_b_i - Controller_U.INS_Out.p;
  rtb_Cos1 = rtb_Multiply3_c - Controller_U.INS_Out.q;
  rtb_Multiply4_my = rtb_Saturation_m - Controller_U.INS_Out.r;

  /* DiscreteIntegrator: '<S19>/Discrete-Time Integrator' incorporates:
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

  /* DiscreteIntegrator: '<S21>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevR_i != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[0] = 0.0F;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[1] = 0.0F;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[2] = 0.0F;
  }

  /* Gain: '<S21>/Gain' incorporates:
   *  DiscreteIntegrator: '<S21>/Discrete-Time Integrator1'
   *  Sum: '<S21>/Sum5'
   */
  rtb_DiscreteTimeIntegrator1_b_i = (rtb_Cos -
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[0]) * 188.49556F;
  rtb_Multiply3_c = (rtb_Cos1 - Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[1])
    * 188.49556F;
  rtb_Saturation_m = (rtb_Multiply4_my -
                      Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[2]) *
    188.49556F;

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S3>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S18>/Multiply'
   *  RelationalOperator: '<S3>/Compare'
   */
  if (Controller_U.FMS_Out.state == 2) {
    /* Switch: '<S21>/Switch' incorporates:
     *  Gain: '<S21>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_Saturation1_i_idx_0 = 0.0F;
      rtb_Saturation_d_idx_1 = 0.0F;
      rtb_Saturation_d_idx_2 = 0.0F;
    } else {
      rtb_Saturation1_i_idx_0 = rtb_DiscreteTimeIntegrator1_b_i;
      rtb_Saturation_d_idx_1 = rtb_Multiply3_c;
      rtb_Saturation_d_idx_2 = rtb_Saturation_m;
    }

    /* End of Switch: '<S21>/Switch' */

    /* Product: '<S18>/Multiply' incorporates:
     *  Constant: '<S18>/gain1'
     */
    rtb_Saturation_o = CONTROL_PARAM.ROLL_RATE_D * rtb_Saturation1_i_idx_0;

    /* Saturate: '<S18>/Saturation' */
    if (rtb_Saturation_o > CONTROL_PARAM.RATE_D_MAX) {
      rtb_Saturation_o = CONTROL_PARAM.RATE_D_MAX;
    } else {
      if (rtb_Saturation_o < CONTROL_PARAM.RATE_D_MIN) {
        rtb_Saturation_o = CONTROL_PARAM.RATE_D_MIN;
      }
    }

    rtb_Saturation1_i_idx_0 = rtb_Saturation_o;

    /* Product: '<S18>/Multiply' incorporates:
     *  Constant: '<S18>/gain2'
     */
    rtb_Saturation_o = CONTROL_PARAM.PITCH_RATE_D * rtb_Saturation_d_idx_1;

    /* Saturate: '<S18>/Saturation' */
    if (rtb_Saturation_o > CONTROL_PARAM.RATE_D_MAX) {
      rtb_Saturation_o = CONTROL_PARAM.RATE_D_MAX;
    } else {
      if (rtb_Saturation_o < CONTROL_PARAM.RATE_D_MIN) {
        rtb_Saturation_o = CONTROL_PARAM.RATE_D_MIN;
      }
    }

    rtb_Saturation_d_idx_1 = rtb_Saturation_o;

    /* Product: '<S18>/Multiply' incorporates:
     *  Constant: '<S18>/gain3'
     */
    rtb_Saturation_o = CONTROL_PARAM.YAW_RATE_D * rtb_Saturation_d_idx_2;

    /* Saturate: '<S18>/Saturation' */
    if (rtb_Saturation_o > CONTROL_PARAM.RATE_D_MAX) {
      rtb_Saturation_o = CONTROL_PARAM.RATE_D_MAX;
    } else {
      if (rtb_Saturation_o < CONTROL_PARAM.RATE_D_MIN) {
        rtb_Saturation_o = CONTROL_PARAM.RATE_D_MIN;
      }
    }

    /* Switch: '<S46>/Switch' incorporates:
     *  Constant: '<S47>/Constant1'
     *  Constant: '<S48>/Constant'
     *  Gain: '<S47>/Gain1'
     *  RelationalOperator: '<S48>/Compare'
     *  Sum: '<S47>/Sum1'
     */
    if (Controller_U.FMS_Out.mode >= 4) {
      rtb_throttle_cmd = Controller_U.FMS_Out.throttle_cmd;
    } else {
      /* Product: '<S50>/Multiply' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S50>/Cos'
       *  Trigonometry: '<S50>/Cos1'
       */
      rtb_Saturation_d_idx_2 = arm_cos_f32(Controller_U.INS_Out.phi) *
        arm_cos_f32(Controller_U.INS_Out.theta);

      /* Gain: '<S50>/Gain' */
      rtb_Atan_idx_1 = 2.0F * rtb_Saturation_d_idx_2;

      /* Saturate: '<S50>/Saturation1' */
      if (rtb_Saturation_d_idx_2 > 1.0F) {
        rtb_Saturation_d_idx_2 = 1.0F;
      } else {
        if (rtb_Saturation_d_idx_2 < 0.5F) {
          rtb_Saturation_d_idx_2 = 0.5F;
        }
      }

      /* End of Saturate: '<S50>/Saturation1' */

      /* Product: '<S50>/Divide' incorporates:
       *  Constant: '<S50>/Constant'
       */
      rtb_Atan_idx_0 = 1.0F / rtb_Saturation_d_idx_2;

      /* Switch: '<S58>/Switch' incorporates:
       *  Gain: '<S58>/Gain1'
       */
      if (Controller_U.FMS_Out.reset > 0) {
        rtb_Saturation_d_idx_2 = 0.0F;
      } else {
        rtb_Saturation_d_idx_2 = rtb_Gain_am;
      }

      /* End of Switch: '<S58>/Switch' */

      /* Product: '<S55>/Multiply' incorporates:
       *  Constant: '<S55>/kd'
       */
      rtb_Saturation_d_idx_2 *= CONTROL_PARAM.VEL_Z_D;

      /* Saturate: '<S55>/Saturation' */
      if (rtb_Saturation_d_idx_2 > CONTROL_PARAM.VEL_Z_D_MAX) {
        rtb_Saturation_d_idx_2 = CONTROL_PARAM.VEL_Z_D_MAX;
      } else {
        if (rtb_Saturation_d_idx_2 < CONTROL_PARAM.VEL_Z_D_MIN) {
          rtb_Saturation_d_idx_2 = CONTROL_PARAM.VEL_Z_D_MIN;
        }
      }

      /* End of Saturate: '<S55>/Saturation' */

      /* Saturate: '<S50>/Saturation' */
      if (rtb_Atan_idx_1 > 1.0F) {
        rtb_Atan_idx_1 = 1.0F;
      } else {
        if (rtb_Atan_idx_1 < 0.0F) {
          rtb_Atan_idx_1 = 0.0F;
        }
      }

      /* End of Saturate: '<S50>/Saturation' */

      /* Product: '<S50>/Multiply1' incorporates:
       *  Constant: '<S57>/kp'
       *  DiscreteIntegrator: '<S56>/Discrete-Time Integrator'
       *  Product: '<S57>/Multiply'
       *  Sum: '<S52>/Add'
       */
      rtb_Saturation_d_idx_2 = ((CONTROL_PARAM.VEL_Z_P * rtb_Gain +
        Controller_DW.DiscreteTimeIntegrator_DSTATE) + rtb_Saturation_d_idx_2) *
        rtb_Atan_idx_0 * rtb_Atan_idx_1;

      /* Saturate: '<S49>/Saturation' */
      if (rtb_Saturation_d_idx_2 > 0.35F) {
        rtb_Saturation_d_idx_2 = 0.35F;
      } else {
        if (rtb_Saturation_d_idx_2 < -0.35F) {
          rtb_Saturation_d_idx_2 = -0.35F;
        }
      }

      /* End of Saturate: '<S49>/Saturation' */

      /* Sum: '<S47>/Sum' incorporates:
       *  Constant: '<S47>/hover_throttle'
       */
      rtb_Saturation_d_idx_2 += 0.5F;
      rtb_throttle_cmd = (uint32_T)fmodf(floorf(1000.0F * rtb_Saturation_d_idx_2),
        4.2949673E+9F) + 1000U;
    }

    /* End of Switch: '<S46>/Switch' */

    /* Saturate: '<S6>/Saturation1' incorporates:
     *  Constant: '<S20>/gain1'
     *  Constant: '<S20>/gain2'
     *  Constant: '<S20>/gain3'
     *  DiscreteIntegrator: '<S19>/Discrete-Time Integrator'
     *  Product: '<S20>/Multiply'
     *  Sum: '<S16>/Add'
     */
    rtb_Atan_idx_1 = (CONTROL_PARAM.ROLL_RATE_P * rtb_Cos +
                      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0]) +
      rtb_Saturation1_i_idx_0;
    if (rtb_Atan_idx_1 > 1.0F) {
      rtb_Atan_idx_1 = 1.0F;
    } else {
      if (rtb_Atan_idx_1 < -1.0F) {
        rtb_Atan_idx_1 = -1.0F;
      }
    }

    rtb_Saturation1_i_idx_0 = (CONTROL_PARAM.PITCH_RATE_P * rtb_Cos1 +
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1]) + rtb_Saturation_d_idx_1;
    if (rtb_Saturation1_i_idx_0 > 1.0F) {
      rtb_Saturation1_i_idx_0 = 1.0F;
    } else {
      if (rtb_Saturation1_i_idx_0 < -1.0F) {
        rtb_Saturation1_i_idx_0 = -1.0F;
      }
    }

    rtb_Saturation_o += CONTROL_PARAM.YAW_RATE_P * rtb_Multiply4_my +
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2];
    if (rtb_Saturation_o > 1.0F) {
      rtb_Saturation_o = 1.0F;
    } else {
      if (rtb_Saturation_o < -1.0F) {
        rtb_Saturation_o = -1.0F;
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
      rtb_Saturation_d_idx_2 = fmodf(floorf(1000.0F *
        (Controller_ConstP.X_Frame_Effective_Matrix_Value[i + 8] *
         rtb_Saturation_o + (Controller_ConstP.X_Frame_Effective_Matrix_Value[i
        + 4] * rtb_Saturation1_i_idx_0 +
        Controller_ConstP.X_Frame_Effective_Matrix_Value[i] * rtb_Atan_idx_1))),
        65536.0F);
      u0 = (uint16_T)((uint32_T)(rtb_Saturation_d_idx_2 < 0.0F ? (int32_T)
        (uint16_T)-(int16_T)(uint16_T)-rtb_Saturation_d_idx_2 : (int32_T)
        (uint16_T)rtb_Saturation_d_idx_2) + (uint16_T)rtb_throttle_cmd);
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
    for (i = 0; i < 16; i++) {
      Controller_Y.Control_Out.actuator_cmd[i] =
        Controller_U.FMS_Out.actuator_cmd[i];
    }
  }

  /* End of Switch: '<S1>/Switch' */

  /* Product: '<S41>/Multiply1' incorporates:
   *  Constant: '<S41>/const1'
   *  DiscreteIntegrator: '<S38>/Integrator'
   */
  rtb_Atan_idx_0 = Controller_DW.Integrator_DSTATE[0] * 0.05F;
  rtb_Atan_idx_1 = Controller_DW.Integrator_DSTATE[1] * 0.05F;

  /* Sum: '<S41>/Add' incorporates:
   *  DiscreteIntegrator: '<S38>/Integrator1'
   *  Inport: '<Root>/FMS_Out'
   *  Sum: '<S38>/Subtract'
   */
  rtb_Saturation1_i_idx_0 = (Controller_DW.Integrator1_DSTATE_g[0] -
    Controller_U.FMS_Out.u_cmd) + rtb_Atan_idx_0;
  rtb_Saturation1_i_idx_1 = (Controller_DW.Integrator1_DSTATE_g[1] -
    Controller_U.FMS_Out.v_cmd) + rtb_Atan_idx_1;

  /* Signum: '<S41>/Sign' */
  if (rtb_Saturation1_i_idx_0 < 0.0F) {
    rtb_Saturation_d_idx_2 = -1.0F;
  } else if (rtb_Saturation1_i_idx_0 > 0.0F) {
    rtb_Saturation_d_idx_2 = 1.0F;
  } else {
    rtb_Saturation_d_idx_2 = rtb_Saturation1_i_idx_0;
  }

  /* Sum: '<S41>/Add2' incorporates:
   *  Abs: '<S41>/Abs'
   *  Gain: '<S41>/Gain'
   *  Gain: '<S41>/Gain1'
   *  Product: '<S41>/Multiply2'
   *  Product: '<S41>/Multiply3'
   *  Signum: '<S41>/Sign'
   *  Sqrt: '<S41>/Sqrt'
   *  Sum: '<S41>/Add1'
   *  Sum: '<S41>/Subtract'
   */
  rtb_Saturation_d_idx_2 = (sqrtf((8.0F * fabsf(rtb_Saturation1_i_idx_0) +
    Controller_ConstB.d) * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
    rtb_Saturation_d_idx_2 + rtb_Atan_idx_0;

  /* Sum: '<S41>/Add3' incorporates:
   *  Signum: '<S41>/Sign'
   */
  rtb_Saturation_o = rtb_Saturation1_i_idx_0 + Controller_ConstB.d;

  /* Sum: '<S41>/Subtract1' incorporates:
   *  Signum: '<S41>/Sign'
   */
  rtb_Saturation_d_idx_1 = rtb_Saturation1_i_idx_0 - Controller_ConstB.d;

  /* Signum: '<S41>/Sign1' */
  if (rtb_Saturation_o < 0.0F) {
    rtb_Saturation_o = -1.0F;
  } else {
    if (rtb_Saturation_o > 0.0F) {
      rtb_Saturation_o = 1.0F;
    }
  }

  /* Signum: '<S41>/Sign2' */
  if (rtb_Saturation_d_idx_1 < 0.0F) {
    rtb_Saturation_d_idx_1 = -1.0F;
  } else {
    if (rtb_Saturation_d_idx_1 > 0.0F) {
      rtb_Saturation_d_idx_1 = 1.0F;
    }
  }

  /* Sum: '<S41>/Add2' incorporates:
   *  Gain: '<S41>/Gain2'
   *  Product: '<S41>/Multiply4'
   *  Signum: '<S41>/Sign'
   *  Sum: '<S41>/Add4'
   *  Sum: '<S41>/Add5'
   *  Sum: '<S41>/Subtract2'
   */
  rtb_Saturation1_i_idx_0 = ((rtb_Saturation1_i_idx_0 - rtb_Saturation_d_idx_2)
    + rtb_Atan_idx_0) * ((rtb_Saturation_o - rtb_Saturation_d_idx_1) * 0.5F) +
    rtb_Saturation_d_idx_2;

  /* Signum: '<S41>/Sign' */
  if (rtb_Saturation1_i_idx_1 < 0.0F) {
    rtb_Saturation_d_idx_2 = -1.0F;
  } else if (rtb_Saturation1_i_idx_1 > 0.0F) {
    rtb_Saturation_d_idx_2 = 1.0F;
  } else {
    rtb_Saturation_d_idx_2 = rtb_Saturation1_i_idx_1;
  }

  /* Sum: '<S41>/Add2' incorporates:
   *  Abs: '<S41>/Abs'
   *  Gain: '<S41>/Gain'
   *  Gain: '<S41>/Gain1'
   *  Product: '<S41>/Multiply2'
   *  Product: '<S41>/Multiply3'
   *  Signum: '<S41>/Sign'
   *  Sqrt: '<S41>/Sqrt'
   *  Sum: '<S41>/Add1'
   *  Sum: '<S41>/Subtract'
   */
  rtb_Saturation_d_idx_2 = (sqrtf((8.0F * fabsf(rtb_Saturation1_i_idx_1) +
    Controller_ConstB.d) * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
    rtb_Saturation_d_idx_2 + rtb_Atan_idx_1;

  /* Sum: '<S41>/Add3' incorporates:
   *  Signum: '<S41>/Sign'
   */
  rtb_Saturation_o = rtb_Saturation1_i_idx_1 + Controller_ConstB.d;

  /* Sum: '<S41>/Subtract1' incorporates:
   *  Signum: '<S41>/Sign'
   */
  rtb_Saturation_d_idx_1 = rtb_Saturation1_i_idx_1 - Controller_ConstB.d;

  /* Signum: '<S41>/Sign1' */
  if (rtb_Saturation_o < 0.0F) {
    rtb_Saturation_o = -1.0F;
  } else {
    if (rtb_Saturation_o > 0.0F) {
      rtb_Saturation_o = 1.0F;
    }
  }

  /* Signum: '<S41>/Sign2' */
  if (rtb_Saturation_d_idx_1 < 0.0F) {
    rtb_Saturation_d_idx_1 = -1.0F;
  } else {
    if (rtb_Saturation_d_idx_1 > 0.0F) {
      rtb_Saturation_d_idx_1 = 1.0F;
    }
  }

  /* Sum: '<S41>/Add5' incorporates:
   *  Gain: '<S41>/Gain2'
   *  Product: '<S41>/Multiply4'
   *  Signum: '<S41>/Sign'
   *  Sum: '<S41>/Add2'
   *  Sum: '<S41>/Add4'
   *  Sum: '<S41>/Subtract2'
   */
  rtb_Saturation_d_idx_2 += ((rtb_Saturation1_i_idx_1 - rtb_Saturation_d_idx_2)
    + rtb_Atan_idx_1) * ((rtb_Saturation_o - rtb_Saturation_d_idx_1) * 0.5F);

  /* Outport: '<Root>/Control_Out' incorporates:
   *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
   */
  Controller_Y.Control_Out.timestamp =
    Controller_DW.DiscreteTimeIntegrator_DSTATE_n;

  /* Product: '<S24>/Multiply1' incorporates:
   *  Constant: '<S24>/const1'
   *  DiscreteIntegrator: '<S23>/Integrator'
   */
  rtb_Add3 = Controller_DW.Integrator_DSTATE_k * 0.02F;

  /* Sum: '<S24>/Add' incorporates:
   *  DiscreteIntegrator: '<S23>/Integrator1'
   *  Inport: '<Root>/FMS_Out'
   *  Sum: '<S23>/Subtract'
   */
  rtb_Saturation_d_idx_1 = (Controller_DW.Integrator1_DSTATE_d -
    Controller_U.FMS_Out.psi_rate_cmd) + rtb_Add3;

  /* Signum: '<S24>/Sign' */
  if (rtb_Saturation_d_idx_1 < 0.0F) {
    rtb_Saturation_o = -1.0F;
  } else if (rtb_Saturation_d_idx_1 > 0.0F) {
    rtb_Saturation_o = 1.0F;
  } else {
    rtb_Saturation_o = rtb_Saturation_d_idx_1;
  }

  /* End of Signum: '<S24>/Sign' */

  /* Sum: '<S24>/Add2' incorporates:
   *  Abs: '<S24>/Abs'
   *  Gain: '<S24>/Gain'
   *  Gain: '<S24>/Gain1'
   *  Product: '<S24>/Multiply2'
   *  Product: '<S24>/Multiply3'
   *  Sqrt: '<S24>/Sqrt'
   *  Sum: '<S24>/Add1'
   *  Sum: '<S24>/Subtract'
   */
  rtb_Subtract3_i = (sqrtf((8.0F * fabsf(rtb_Saturation_d_idx_1) +
    Controller_ConstB.d_j) * Controller_ConstB.d_j) - Controller_ConstB.d_j) *
    0.5F * rtb_Saturation_o + rtb_Add3;

  /* Sum: '<S24>/Add4' */
  rtb_Atan_idx_1 = (rtb_Saturation_d_idx_1 - rtb_Subtract3_i) + rtb_Add3;

  /* Sum: '<S24>/Add3' */
  rtb_Saturation_o = rtb_Saturation_d_idx_1 + Controller_ConstB.d_j;

  /* Sum: '<S24>/Subtract1' */
  rtb_Saturation_d_idx_1 -= Controller_ConstB.d_j;

  /* Signum: '<S24>/Sign1' */
  if (rtb_Saturation_o < 0.0F) {
    rtb_Saturation_o = -1.0F;
  } else {
    if (rtb_Saturation_o > 0.0F) {
      rtb_Saturation_o = 1.0F;
    }
  }

  /* End of Signum: '<S24>/Sign1' */

  /* Signum: '<S24>/Sign2' */
  if (rtb_Saturation_d_idx_1 < 0.0F) {
    rtb_Saturation_d_idx_1 = -1.0F;
  } else {
    if (rtb_Saturation_d_idx_1 > 0.0F) {
      rtb_Saturation_d_idx_1 = 1.0F;
    }
  }

  /* End of Signum: '<S24>/Sign2' */

  /* Sum: '<S24>/Add5' incorporates:
   *  Gain: '<S24>/Gain2'
   *  Product: '<S24>/Multiply4'
   *  Sum: '<S24>/Subtract2'
   */
  rtb_Subtract3_i += (rtb_Saturation_o - rtb_Saturation_d_idx_1) * 0.5F *
    rtb_Atan_idx_1;

  /* Sum: '<S24>/Subtract3' */
  rtb_Saturation_o = rtb_Subtract3_i - Controller_ConstB.d_j;

  /* Sum: '<S24>/Add6' */
  rtb_Atan_idx_1 = rtb_Subtract3_i + Controller_ConstB.d_j;

  /* Product: '<S24>/Divide' */
  rtb_Saturation1_i_idx_1 = rtb_Subtract3_i / Controller_ConstB.d_j;

  /* Signum: '<S24>/Sign5' incorporates:
   *  Signum: '<S24>/Sign6'
   */
  if (rtb_Subtract3_i < 0.0F) {
    rtb_Sign5_f = -1.0F;

    /* Signum: '<S24>/Sign6' */
    rtb_Atan_idx_0 = -1.0F;
  } else if (rtb_Subtract3_i > 0.0F) {
    rtb_Sign5_f = 1.0F;

    /* Signum: '<S24>/Sign6' */
    rtb_Atan_idx_0 = 1.0F;
  } else {
    rtb_Sign5_f = rtb_Subtract3_i;

    /* Signum: '<S24>/Sign6' */
    rtb_Atan_idx_0 = rtb_Subtract3_i;
  }

  /* End of Signum: '<S24>/Sign5' */

  /* Product: '<S54>/Multiply1' incorporates:
   *  Constant: '<S54>/const1'
   *  DiscreteIntegrator: '<S53>/Integrator'
   */
  rtb_Add3 = Controller_DW.Integrator_DSTATE_p * 0.05F;

  /* Sum: '<S54>/Add' incorporates:
   *  DiscreteIntegrator: '<S53>/Integrator1'
   *  Inport: '<Root>/FMS_Out'
   *  Sum: '<S53>/Subtract'
   */
  rtb_Subtract3_i = (Controller_DW.Integrator1_DSTATE -
                     Controller_U.FMS_Out.w_cmd) + rtb_Add3;

  /* Signum: '<S54>/Sign' */
  if (rtb_Subtract3_i < 0.0F) {
    rtb_Saturation_d_idx_1 = -1.0F;
  } else if (rtb_Subtract3_i > 0.0F) {
    rtb_Saturation_d_idx_1 = 1.0F;
  } else {
    rtb_Saturation_d_idx_1 = rtb_Subtract3_i;
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
  rtb_Saturation_d_idx_1 = (sqrtf((8.0F * fabsf(rtb_Subtract3_i) +
    Controller_ConstB.d_n) * Controller_ConstB.d_n) - Controller_ConstB.d_n) *
    0.5F * rtb_Saturation_d_idx_1 + rtb_Add3;

  /* Sum: '<S54>/Add4' */
  rtb_Add4_i = (rtb_Subtract3_i - rtb_Saturation_d_idx_1) + rtb_Add3;

  /* Sum: '<S54>/Add3' */
  rtb_Add3 = rtb_Subtract3_i + Controller_ConstB.d_n;

  /* Sum: '<S54>/Subtract1' */
  rtb_Subtract3_i -= Controller_ConstB.d_n;

  /* Signum: '<S54>/Sign1' */
  if (rtb_Add3 < 0.0F) {
    rtb_Add3 = -1.0F;
  } else {
    if (rtb_Add3 > 0.0F) {
      rtb_Add3 = 1.0F;
    }
  }

  /* End of Signum: '<S54>/Sign1' */

  /* Signum: '<S54>/Sign2' */
  if (rtb_Subtract3_i < 0.0F) {
    rtb_Subtract3_i = -1.0F;
  } else {
    if (rtb_Subtract3_i > 0.0F) {
      rtb_Subtract3_i = 1.0F;
    }
  }

  /* End of Signum: '<S54>/Sign2' */

  /* Sum: '<S54>/Add5' incorporates:
   *  Gain: '<S54>/Gain2'
   *  Product: '<S54>/Multiply4'
   *  Sum: '<S54>/Subtract2'
   */
  rtb_Saturation_d_idx_1 += (rtb_Add3 - rtb_Subtract3_i) * 0.5F * rtb_Add4_i;

  /* Update for DiscreteIntegrator: '<S53>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S53>/Integrator'
   */
  Controller_DW.Integrator1_DSTATE += 0.002F * Controller_DW.Integrator_DSTATE_p;

  /* Update for DiscreteIntegrator: '<S56>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S56>/ki'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S56>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE += CONTROL_PARAM.VEL_Z_I *
    rtb_Gain * 0.002F;
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

  /* End of Update for DiscreteIntegrator: '<S56>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S58>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_DSTATE += 0.002F * rtb_Gain_am;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S43>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator_PrevRe_e = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S38>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S38>/Integrator'
   */
  Controller_DW.Integrator1_DSTATE_g[0] += 0.002F *
    Controller_DW.Integrator_DSTATE[0];

  /* Update for DiscreteIntegrator: '<S43>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S43>/ki'
   *  Product: '<S43>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] += CONTROL_PARAM.VEL_XY_I *
    rtb_uv_error_C_mPs_idx_0 * 0.002F;
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

  /* Update for DiscreteIntegrator: '<S45>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[0] += 0.002F * rtb_Gain_j_idx_0;

  /* Update for DiscreteIntegrator: '<S38>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S38>/Integrator'
   */
  Controller_DW.Integrator1_DSTATE_g[1] += 0.002F *
    Controller_DW.Integrator_DSTATE[1];

  /* Update for DiscreteIntegrator: '<S43>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S43>/ki'
   *  Product: '<S43>/Multiply'
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

  /* Update for DiscreteIntegrator: '<S45>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[1] += 0.002F * rtb_Gain_j_idx_1;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_a = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S23>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S23>/Integrator'
   */
  Controller_DW.Integrator1_DSTATE_d += 0.002F *
    Controller_DW.Integrator_DSTATE_k;

  /* Update for DiscreteIntegrator: '<S19>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S19>/gain1'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S19>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_PrevRe_g = (int8_T)
    (Controller_U.FMS_Out.reset > 0);
  Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] += CONTROL_PARAM.ROLL_RATE_I *
    rtb_Cos * 0.002F;
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

  /* Update for DiscreteIntegrator: '<S21>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[0] += 0.002F *
    rtb_DiscreteTimeIntegrator1_b_i;

  /* Update for DiscreteIntegrator: '<S19>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S19>/gain2'
   *  Product: '<S19>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] += CONTROL_PARAM.PITCH_RATE_I
    * rtb_Cos1 * 0.002F;
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

  /* Update for DiscreteIntegrator: '<S21>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[1] += 0.002F * rtb_Multiply3_c;

  /* Update for DiscreteIntegrator: '<S19>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S19>/gain3'
   *  Product: '<S19>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] += CONTROL_PARAM.YAW_RATE_I *
    rtb_Multiply4_my * 0.002F;
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

  /* Update for DiscreteIntegrator: '<S21>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[2] += 0.002F * rtb_Saturation_m;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_i = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Signum: '<S41>/Sign3' incorporates:
   *  Product: '<S41>/Divide'
   *  Sum: '<S41>/Add6'
   */
  rtb_Add3 = rtb_Saturation1_i_idx_0 + Controller_ConstB.d;

  /* Signum: '<S41>/Sign4' incorporates:
   *  Product: '<S41>/Divide'
   *  Sum: '<S41>/Subtract3'
   */
  rtb_Gain = rtb_Saturation1_i_idx_0 - Controller_ConstB.d;

  /* Signum: '<S41>/Sign5' incorporates:
   *  Product: '<S41>/Divide'
   */
  if (rtb_Saturation1_i_idx_0 < 0.0F) {
    rtb_Gain_am = -1.0F;
  } else if (rtb_Saturation1_i_idx_0 > 0.0F) {
    rtb_Gain_am = 1.0F;
  } else {
    rtb_Gain_am = rtb_Saturation1_i_idx_0;
  }

  /* Signum: '<S41>/Sign3' */
  if (rtb_Add3 < 0.0F) {
    rtb_Add3 = -1.0F;
  } else {
    if (rtb_Add3 > 0.0F) {
      rtb_Add3 = 1.0F;
    }
  }

  /* Signum: '<S41>/Sign4' */
  if (rtb_Gain < 0.0F) {
    rtb_Gain = -1.0F;
  } else {
    if (rtb_Gain > 0.0F) {
      rtb_Gain = 1.0F;
    }
  }

  /* Signum: '<S41>/Sign6' incorporates:
   *  Product: '<S41>/Divide'
   */
  if (rtb_Saturation1_i_idx_0 < 0.0F) {
    rtb_uv_error_C_mPs_idx_0 = -1.0F;
  } else if (rtb_Saturation1_i_idx_0 > 0.0F) {
    rtb_uv_error_C_mPs_idx_0 = 1.0F;
  } else {
    rtb_uv_error_C_mPs_idx_0 = rtb_Saturation1_i_idx_0;
  }

  /* Update for DiscreteIntegrator: '<S38>/Integrator' incorporates:
   *  Constant: '<S41>/const'
   *  Gain: '<S41>/Gain3'
   *  Product: '<S41>/Divide'
   *  Product: '<S41>/Multiply5'
   *  Product: '<S41>/Multiply6'
   *  Sum: '<S41>/Subtract4'
   *  Sum: '<S41>/Subtract5'
   *  Sum: '<S41>/Subtract6'
   */
  Controller_DW.Integrator_DSTATE[0] += ((rtb_Saturation1_i_idx_0 /
    Controller_ConstB.d - rtb_Gain_am) * Controller_ConstB.Gain4 * ((rtb_Add3 -
    rtb_Gain) * 0.5F) - rtb_uv_error_C_mPs_idx_0 * 58.836F) * 0.002F;

  /* Signum: '<S41>/Sign3' incorporates:
   *  Sum: '<S41>/Add6'
   */
  rtb_Add3 = rtb_Saturation_d_idx_2 + Controller_ConstB.d;

  /* Signum: '<S41>/Sign4' incorporates:
   *  Sum: '<S41>/Subtract3'
   */
  rtb_Gain = rtb_Saturation_d_idx_2 - Controller_ConstB.d;

  /* Signum: '<S41>/Sign5' */
  if (rtb_Saturation_d_idx_2 < 0.0F) {
    rtb_Gain_am = -1.0F;
  } else if (rtb_Saturation_d_idx_2 > 0.0F) {
    rtb_Gain_am = 1.0F;
  } else {
    rtb_Gain_am = rtb_Saturation_d_idx_2;
  }

  /* Signum: '<S41>/Sign3' */
  if (rtb_Add3 < 0.0F) {
    rtb_Add3 = -1.0F;
  } else {
    if (rtb_Add3 > 0.0F) {
      rtb_Add3 = 1.0F;
    }
  }

  /* Signum: '<S41>/Sign4' */
  if (rtb_Gain < 0.0F) {
    rtb_Gain = -1.0F;
  } else {
    if (rtb_Gain > 0.0F) {
      rtb_Gain = 1.0F;
    }
  }

  /* Signum: '<S41>/Sign6' */
  if (rtb_Saturation_d_idx_2 < 0.0F) {
    rtb_uv_error_C_mPs_idx_0 = -1.0F;
  } else if (rtb_Saturation_d_idx_2 > 0.0F) {
    rtb_uv_error_C_mPs_idx_0 = 1.0F;
  } else {
    rtb_uv_error_C_mPs_idx_0 = rtb_Saturation_d_idx_2;
  }

  /* Update for DiscreteIntegrator: '<S38>/Integrator' incorporates:
   *  Constant: '<S41>/const'
   *  Gain: '<S41>/Gain3'
   *  Product: '<S41>/Divide'
   *  Product: '<S41>/Multiply5'
   *  Product: '<S41>/Multiply6'
   *  Sum: '<S41>/Subtract4'
   *  Sum: '<S41>/Subtract5'
   *  Sum: '<S41>/Subtract6'
   */
  Controller_DW.Integrator_DSTATE[1] += ((rtb_Saturation_d_idx_2 /
    Controller_ConstB.d - rtb_Gain_am) * Controller_ConstB.Gain4 * ((rtb_Add3 -
    rtb_Gain) * 0.5F) - rtb_uv_error_C_mPs_idx_0 * 58.836F) * 0.002F;

  /* Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S4>/Constant'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_n += CONTROL_EXPORT.period;

  /* Signum: '<S24>/Sign3' */
  if (rtb_Atan_idx_1 < 0.0F) {
    rtb_Atan_idx_1 = -1.0F;
  } else {
    if (rtb_Atan_idx_1 > 0.0F) {
      rtb_Atan_idx_1 = 1.0F;
    }
  }

  /* End of Signum: '<S24>/Sign3' */

  /* Signum: '<S24>/Sign4' */
  if (rtb_Saturation_o < 0.0F) {
    rtb_Saturation_o = -1.0F;
  } else {
    if (rtb_Saturation_o > 0.0F) {
      rtb_Saturation_o = 1.0F;
    }
  }

  /* End of Signum: '<S24>/Sign4' */

  /* Update for DiscreteIntegrator: '<S23>/Integrator' incorporates:
   *  Constant: '<S24>/const'
   *  Gain: '<S24>/Gain3'
   *  Product: '<S24>/Multiply5'
   *  Product: '<S24>/Multiply6'
   *  Sum: '<S24>/Subtract4'
   *  Sum: '<S24>/Subtract5'
   *  Sum: '<S24>/Subtract6'
   */
  Controller_DW.Integrator_DSTATE_k += ((rtb_Saturation1_i_idx_1 - rtb_Sign5_f) *
    Controller_ConstB.Gain4_o * ((rtb_Atan_idx_1 - rtb_Saturation_o) * 0.5F) -
    rtb_Atan_idx_0 * 15.707963F) * 0.002F;

  /* Signum: '<S54>/Sign6' incorporates:
   *  Signum: '<S54>/Sign5'
   */
  if (rtb_Saturation_d_idx_1 < 0.0F) {
    rtb_Atan_idx_0 = -1.0F;

    /* Signum: '<S54>/Sign5' */
    rtb_Gain = -1.0F;
  } else if (rtb_Saturation_d_idx_1 > 0.0F) {
    rtb_Atan_idx_0 = 1.0F;

    /* Signum: '<S54>/Sign5' */
    rtb_Gain = 1.0F;
  } else {
    rtb_Atan_idx_0 = rtb_Saturation_d_idx_1;

    /* Signum: '<S54>/Sign5' */
    rtb_Gain = rtb_Saturation_d_idx_1;
  }

  /* End of Signum: '<S54>/Sign6' */

  /* Sum: '<S54>/Add6' */
  rtb_Saturation_o = rtb_Saturation_d_idx_1 + Controller_ConstB.d_n;

  /* Sum: '<S54>/Subtract3' */
  rtb_Atan_idx_1 = rtb_Saturation_d_idx_1 - Controller_ConstB.d_n;

  /* Signum: '<S54>/Sign3' */
  if (rtb_Saturation_o < 0.0F) {
    rtb_Saturation_o = -1.0F;
  } else {
    if (rtb_Saturation_o > 0.0F) {
      rtb_Saturation_o = 1.0F;
    }
  }

  /* End of Signum: '<S54>/Sign3' */

  /* Signum: '<S54>/Sign4' */
  if (rtb_Atan_idx_1 < 0.0F) {
    rtb_Atan_idx_1 = -1.0F;
  } else {
    if (rtb_Atan_idx_1 > 0.0F) {
      rtb_Atan_idx_1 = 1.0F;
    }
  }

  /* End of Signum: '<S54>/Sign4' */

  /* Update for DiscreteIntegrator: '<S53>/Integrator' incorporates:
   *  Constant: '<S54>/const'
   *  Gain: '<S54>/Gain3'
   *  Product: '<S54>/Divide'
   *  Product: '<S54>/Multiply5'
   *  Product: '<S54>/Multiply6'
   *  Sum: '<S54>/Subtract4'
   *  Sum: '<S54>/Subtract5'
   *  Sum: '<S54>/Subtract6'
   */
  Controller_DW.Integrator_DSTATE_p += ((rtb_Saturation_d_idx_1 /
    Controller_ConstB.d_n - rtb_Gain) * Controller_ConstB.Gain4_k *
    ((rtb_Saturation_o - rtb_Atan_idx_1) * 0.5F) - rtb_Atan_idx_0 * 78.448F) *
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

  /* InitializeConditions for DiscreteIntegrator: '<S56>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S56>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S58>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S43>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S43>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S45>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_PrevR_a = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S19>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S19>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S21>/Discrete-Time Integrator1' */
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
