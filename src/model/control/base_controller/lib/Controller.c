/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.885
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Aug  6 09:32:05 2022
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
                                        *   '<S33>/Saturation'
                                        *   '<S13>/Saturation'
                                        *   '<S13>/Saturation1'
                                        *   '<S41>/kd'
                                        *   '<S41>/Saturation'
                                        *   '<S42>/ki'
                                        *   '<S42>/Discrete-Time Integrator'
                                        *   '<S43>/kp'
                                        *   '<S54>/kd'
                                        *   '<S54>/Saturation'
                                        *   '<S55>/ki'
                                        *   '<S55>/Discrete-Time Integrator'
                                        *   '<S56>/kp'
                                        *   '<S28>/Constant1'
                                        *   '<S28>/Constant2'
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
    118, 48, 46, 50, 46, 51, 0 }
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
  real32_T rtb_Subtract3_i;
  real32_T rtb_a_n;
  real32_T rtb_Saturation_m;
  real32_T rtb_Cos;
  real32_T rtb_Cos1;
  real32_T rtb_Multiply4_b;
  real32_T rtb_Multiply3_c;
  uint32_T rtb_throttle_cmd;
  real32_T rtb_Saturation_nc;
  int32_T i;
  real32_T rtb_VectorConcatenate_0[3];
  real32_T rtb_DiscreteTimeIntegrator1_b_i;
  real32_T rtb_Atan_idx_0;
  real32_T rtb_Atan_idx_1;
  real32_T rtb_Saturation_d_idx_0;
  real32_T rtb_Saturation_d_idx_1;
  real32_T rtb_Saturation_d_idx_2;
  real32_T rtb_Saturation1_i_idx_0;
  real32_T rtb_Saturation1_i_idx_1;
  real32_T rtb_uv_error_C_mPs_idx_0;
  real32_T rtb_uv_error_C_mPs_idx_1;
  real32_T rtb_Gain_j_idx_0;
  real32_T rtb_Gain_j_idx_1;
  uint16_T u0;

  /* Gain: '<S50>/Gain' incorporates:
   *  DiscreteIntegrator: '<S52>/Integrator1'
   *  Inport: '<Root>/INS_Out'
   *  Sum: '<S50>/Sum1'
   */
  rtb_Gain = -(Controller_DW.Integrator1_DSTATE - Controller_U.INS_Out.vd);

  /* DiscreteIntegrator: '<S55>/Discrete-Time Integrator' incorporates:
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

  /* DiscreteIntegrator: '<S57>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevRes != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTATE = 0.0F;
  }

  /* Gain: '<S57>/Gain' incorporates:
   *  DiscreteIntegrator: '<S57>/Discrete-Time Integrator1'
   *  Sum: '<S57>/Sum5'
   */
  rtb_Gain_am = (rtb_Gain - Controller_DW.DiscreteTimeIntegrator1_DSTATE) *
    62.831852F;

  /* Trigonometry: '<S39>/Trigonometric Function1' incorporates:
   *  Gain: '<S38>/Gain'
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S39>/Trigonometric Function3'
   */
  rtb_uv_error_C_mPs_idx_0 = arm_cos_f32(-Controller_U.INS_Out.psi);
  rtb_VectorConcatenate[0] = rtb_uv_error_C_mPs_idx_0;

  /* Trigonometry: '<S39>/Trigonometric Function' incorporates:
   *  Gain: '<S38>/Gain'
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S39>/Trigonometric Function2'
   */
  rtb_uv_error_C_mPs_idx_1 = arm_sin_f32(-Controller_U.INS_Out.psi);
  rtb_VectorConcatenate[1] = rtb_uv_error_C_mPs_idx_1;

  /* SignalConversion: '<S39>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S39>/Constant3'
   */
  rtb_VectorConcatenate[2] = 0.0F;

  /* Gain: '<S39>/Gain' */
  rtb_VectorConcatenate[3] = -rtb_uv_error_C_mPs_idx_1;

  /* Trigonometry: '<S39>/Trigonometric Function3' */
  rtb_VectorConcatenate[4] = rtb_uv_error_C_mPs_idx_0;

  /* SignalConversion: '<S39>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S39>/Constant4'
   */
  rtb_VectorConcatenate[5] = 0.0F;

  /* SignalConversion: '<S39>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate[6] = Controller_ConstB.VectorConcatenate3[0];
  rtb_VectorConcatenate[7] = Controller_ConstB.VectorConcatenate3[1];
  rtb_VectorConcatenate[8] = Controller_ConstB.VectorConcatenate3[2];

  /* Product: '<S36>/Multiply' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  SignalConversion: '<S36>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_0[i] = rtb_VectorConcatenate[i + 3] *
      Controller_U.INS_Out.ve + rtb_VectorConcatenate[i] *
      Controller_U.INS_Out.vn;
  }

  /* End of Product: '<S36>/Multiply' */

  /* Sum: '<S34>/Sum' incorporates:
   *  DiscreteIntegrator: '<S37>/Integrator1'
   */
  rtb_uv_error_C_mPs_idx_0 = Controller_DW.Integrator1_DSTATE_g[0] -
    rtb_VectorConcatenate_0[0];
  rtb_uv_error_C_mPs_idx_1 = Controller_DW.Integrator1_DSTATE_g[1] -
    rtb_VectorConcatenate_0[1];

  /* DiscreteIntegrator: '<S42>/Discrete-Time Integrator' incorporates:
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

  /* DiscreteIntegrator: '<S44>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevR_a != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[0] = 0.0F;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[1] = 0.0F;
  }

  /* Gain: '<S44>/Gain' incorporates:
   *  DiscreteIntegrator: '<S44>/Discrete-Time Integrator1'
   *  Sum: '<S44>/Sum5'
   */
  rtb_Gain_j_idx_0 = (rtb_uv_error_C_mPs_idx_0 -
                      Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[0]) *
    62.831852F;
  rtb_Gain_j_idx_1 = (rtb_uv_error_C_mPs_idx_1 -
                      Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[1]) *
    62.831852F;

  /* Switch: '<S14>/Switch' incorporates:
   *  Constant: '<S24>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  Inport: '<Root>/INS_Out'
   *  Product: '<S23>/Multiply'
   *  Product: '<S23>/Multiply1'
   *  Product: '<S23>/Multiply5'
   *  Product: '<S30>/Divide1'
   *  RelationalOperator: '<S24>/Compare'
   *  Saturate: '<S13>/Saturation'
   *  Sum: '<S23>/Add'
   *  Sum: '<S23>/Add1'
   *  Sum: '<S23>/Add2'
   *  Trigonometry: '<S23>/Sin1'
   */
  if (Controller_U.FMS_Out.ctrl_mode == 2) {
    rtb_DiscreteTimeIntegrator1_b_i = Controller_U.FMS_Out.p_cmd;
    rtb_Multiply3_c = Controller_U.FMS_Out.q_cmd;
    rtb_Saturation_m = Controller_U.FMS_Out.r_cmd;
  } else {
    if (Controller_U.FMS_Out.psi_rate_cmd > CONTROL_PARAM.R_CMD_LIM) {
      /* Saturate: '<S13>/Saturation' */
      rtb_Saturation_m = CONTROL_PARAM.R_CMD_LIM;
    } else if (Controller_U.FMS_Out.psi_rate_cmd < -CONTROL_PARAM.R_CMD_LIM) {
      /* Saturate: '<S13>/Saturation' */
      rtb_Saturation_m = -CONTROL_PARAM.R_CMD_LIM;
    } else {
      /* Saturate: '<S13>/Saturation' */
      rtb_Saturation_m = Controller_U.FMS_Out.psi_rate_cmd;
    }

    /* Switch: '<S26>/Switch' incorporates:
     *  Logic: '<S26>/Logical Operator'
     *  RelationalOperator: '<S32>/Compare'
     *  Saturate: '<S13>/Saturation'
     *  Switch: '<S44>/Switch'
     *  Trigonometry: '<S33>/Atan'
     */
    if ((Controller_U.FMS_Out.ctrl_mode == 3) || (Controller_U.FMS_Out.ctrl_mode
         == 4)) {
      rtb_Atan_idx_0 = Controller_U.FMS_Out.phi_cmd;
      rtb_Atan_idx_1 = Controller_U.FMS_Out.theta_cmd;
    } else {
      if (Controller_U.FMS_Out.reset > 0) {
        /* Switch: '<S44>/Switch' incorporates:
         *  Gain: '<S44>/Gain1'
         */
        rtb_Atan_idx_0 = 0.0F;
        rtb_Atan_idx_1 = 0.0F;
      } else {
        /* Switch: '<S44>/Switch' */
        rtb_Atan_idx_0 = rtb_Gain_j_idx_0;
        rtb_Atan_idx_1 = rtb_Gain_j_idx_1;
      }

      /* Product: '<S41>/Multiply' incorporates:
       *  Constant: '<S41>/kd'
       */
      rtb_DiscreteTimeIntegrator1_b_i = CONTROL_PARAM.VEL_XY_D * rtb_Atan_idx_0;

      /* Saturate: '<S41>/Saturation' */
      if (rtb_DiscreteTimeIntegrator1_b_i > CONTROL_PARAM.VEL_XY_D_MAX) {
        rtb_DiscreteTimeIntegrator1_b_i = CONTROL_PARAM.VEL_XY_D_MAX;
      } else {
        if (rtb_DiscreteTimeIntegrator1_b_i < CONTROL_PARAM.VEL_XY_D_MIN) {
          rtb_DiscreteTimeIntegrator1_b_i = CONTROL_PARAM.VEL_XY_D_MIN;
        }
      }

      /* Gain: '<S33>/Gain1' incorporates:
       *  Constant: '<S43>/kp'
       *  DiscreteIntegrator: '<S42>/Discrete-Time Integrator'
       *  Product: '<S41>/Multiply'
       *  Product: '<S43>/Multiply'
       *  Sum: '<S35>/Add'
       */
      rtb_Saturation_nc = (CONTROL_PARAM.VEL_XY_P * rtb_uv_error_C_mPs_idx_0 +
                           Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0]) +
        rtb_DiscreteTimeIntegrator1_b_i;

      /* Product: '<S41>/Multiply' incorporates:
       *  Constant: '<S41>/kd'
       */
      rtb_DiscreteTimeIntegrator1_b_i = CONTROL_PARAM.VEL_XY_D * rtb_Atan_idx_1;

      /* Saturate: '<S41>/Saturation' */
      if (rtb_DiscreteTimeIntegrator1_b_i > CONTROL_PARAM.VEL_XY_D_MAX) {
        rtb_DiscreteTimeIntegrator1_b_i = CONTROL_PARAM.VEL_XY_D_MAX;
      } else {
        if (rtb_DiscreteTimeIntegrator1_b_i < CONTROL_PARAM.VEL_XY_D_MIN) {
          rtb_DiscreteTimeIntegrator1_b_i = CONTROL_PARAM.VEL_XY_D_MIN;
        }
      }

      /* Sum: '<S35>/Add' incorporates:
       *  Constant: '<S43>/kp'
       *  DiscreteIntegrator: '<S42>/Discrete-Time Integrator'
       *  Product: '<S43>/Multiply'
       */
      rtb_DiscreteTimeIntegrator1_b_i += CONTROL_PARAM.VEL_XY_P *
        rtb_uv_error_C_mPs_idx_1 +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1];

      /* Trigonometry: '<S33>/Atan' incorporates:
       *  Constant: '<S33>/g'
       *  Gain: '<S33>/gain'
       *  Product: '<S33>/Divide'
       */
      rtb_Atan_idx_1 = atanf(1.1F * rtb_DiscreteTimeIntegrator1_b_i / 9.8055F);

      /* Saturate: '<S33>/Saturation' */
      if (rtb_Atan_idx_1 > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
        rtb_Atan_idx_1 = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_Atan_idx_1 < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
          rtb_Atan_idx_1 = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
        }
      }

      rtb_Atan_idx_0 = rtb_Atan_idx_1;

      /* Trigonometry: '<S33>/Atan' incorporates:
       *  Constant: '<S33>/g'
       *  Gain: '<S33>/Gain1'
       *  Gain: '<S33>/gain'
       *  Product: '<S33>/Divide'
       */
      rtb_Atan_idx_1 = atanf(1.1F * -rtb_Saturation_nc / 9.8055F);

      /* Saturate: '<S33>/Saturation' */
      if (rtb_Atan_idx_1 > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
        rtb_Atan_idx_1 = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_Atan_idx_1 < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
          rtb_Atan_idx_1 = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
        }
      }
    }

    /* End of Switch: '<S26>/Switch' */

    /* Sum: '<S27>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_DiscreteTimeIntegrator1_b_i = rtb_Atan_idx_0 - Controller_U.INS_Out.phi;

    /* Product: '<S30>/Divide1' incorporates:
     *  Abs: '<S30>/Abs'
     *  Constant: '<S30>/const2'
     */
    rtb_a_n = fabsf(rtb_DiscreteTimeIntegrator1_b_i) / 0.002F;

    /* Gain: '<S30>/Gain3' */
    rtb_Saturation_nc = -rtb_a_n;

    /* Product: '<S30>/Divide' incorporates:
     *  Constant: '<S28>/Constant1'
     *  Constant: '<S30>/const1'
     *  Math: '<S30>/Square'
     *  SignalConversion: '<S30>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_Multiply3_c = 9.5993F / (CONTROL_PARAM.ROLL_P * CONTROL_PARAM.ROLL_P);

    /* Signum: '<S30>/Sign' */
    if (rtb_DiscreteTimeIntegrator1_b_i < 0.0F) {
      rtb_Cos = -1.0F;
    } else if (rtb_DiscreteTimeIntegrator1_b_i > 0.0F) {
      rtb_Cos = 1.0F;
    } else {
      rtb_Cos = rtb_DiscreteTimeIntegrator1_b_i;
    }

    /* Switch: '<S30>/Switch' incorporates:
     *  Constant: '<S28>/Constant1'
     *  Gain: '<S30>/Gain1'
     *  Gain: '<S30>/Gain2'
     *  Logic: '<S30>/Logical Operator'
     *  Product: '<S30>/Multiply'
     *  Product: '<S30>/Multiply1'
     *  Product: '<S30>/Multiply2'
     *  Product: '<S30>/Multiply3'
     *  RelationalOperator: '<S30>/Relational Operator'
     *  RelationalOperator: '<S30>/Relational Operator2'
     *  SignalConversion: '<S30>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S30>/Sqrt'
     *  Sum: '<S30>/Subtract'
     */
    if ((rtb_DiscreteTimeIntegrator1_b_i <= rtb_Multiply3_c) &&
        (rtb_DiscreteTimeIntegrator1_b_i >= -rtb_Multiply3_c)) {
      rtb_DiscreteTimeIntegrator1_b_i *= CONTROL_PARAM.ROLL_P;
    } else {
      rtb_DiscreteTimeIntegrator1_b_i = sqrtf((rtb_Cos *
        rtb_DiscreteTimeIntegrator1_b_i - 0.5F * rtb_Multiply3_c) *
        Controller_ConstB.Gain) * rtb_Cos;
    }

    /* Switch: '<S31>/Switch' incorporates:
     *  Gain: '<S30>/Gain3'
     *  RelationalOperator: '<S31>/UpperRelop'
     */
    if (rtb_DiscreteTimeIntegrator1_b_i >= -rtb_a_n) {
      rtb_Saturation_nc = rtb_DiscreteTimeIntegrator1_b_i;
    }

    /* Switch: '<S31>/Switch2' incorporates:
     *  RelationalOperator: '<S31>/LowerRelop1'
     */
    if (rtb_DiscreteTimeIntegrator1_b_i <= rtb_a_n) {
      rtb_a_n = rtb_Saturation_nc;
    }

    /* Saturate: '<S13>/Saturation1' */
    if (rtb_a_n > CONTROL_PARAM.P_Q_CMD_LIM) {
      rtb_a_n = CONTROL_PARAM.P_Q_CMD_LIM;
    } else {
      if (rtb_a_n < -CONTROL_PARAM.P_Q_CMD_LIM) {
        rtb_a_n = -CONTROL_PARAM.P_Q_CMD_LIM;
      }
    }

    rtb_Saturation1_i_idx_0 = rtb_a_n;

    /* Sum: '<S27>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S30>/Divide1'
     */
    rtb_DiscreteTimeIntegrator1_b_i = rtb_Atan_idx_1 -
      Controller_U.INS_Out.theta;

    /* Product: '<S30>/Divide1' incorporates:
     *  Abs: '<S30>/Abs'
     *  Constant: '<S30>/const2'
     */
    rtb_a_n = fabsf(rtb_DiscreteTimeIntegrator1_b_i) / 0.002F;

    /* Gain: '<S30>/Gain3' */
    rtb_Saturation_nc = -rtb_a_n;

    /* Product: '<S30>/Divide' incorporates:
     *  Constant: '<S28>/Constant2'
     *  Constant: '<S30>/const1'
     *  Math: '<S30>/Square'
     *  SignalConversion: '<S30>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_Multiply3_c = 9.5993F / (CONTROL_PARAM.PITCH_P * CONTROL_PARAM.PITCH_P);

    /* Signum: '<S30>/Sign' */
    if (rtb_DiscreteTimeIntegrator1_b_i < 0.0F) {
      rtb_Cos = -1.0F;
    } else if (rtb_DiscreteTimeIntegrator1_b_i > 0.0F) {
      rtb_Cos = 1.0F;
    } else {
      rtb_Cos = rtb_DiscreteTimeIntegrator1_b_i;
    }

    /* Switch: '<S30>/Switch' incorporates:
     *  Constant: '<S28>/Constant2'
     *  Gain: '<S30>/Gain1'
     *  Gain: '<S30>/Gain2'
     *  Logic: '<S30>/Logical Operator'
     *  Product: '<S30>/Multiply'
     *  Product: '<S30>/Multiply1'
     *  Product: '<S30>/Multiply2'
     *  Product: '<S30>/Multiply3'
     *  RelationalOperator: '<S30>/Relational Operator'
     *  RelationalOperator: '<S30>/Relational Operator2'
     *  SignalConversion: '<S30>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S30>/Sqrt'
     *  Sum: '<S30>/Subtract'
     */
    if ((rtb_DiscreteTimeIntegrator1_b_i <= rtb_Multiply3_c) &&
        (rtb_DiscreteTimeIntegrator1_b_i >= -rtb_Multiply3_c)) {
      rtb_DiscreteTimeIntegrator1_b_i *= CONTROL_PARAM.PITCH_P;
    } else {
      rtb_DiscreteTimeIntegrator1_b_i = sqrtf((rtb_Cos *
        rtb_DiscreteTimeIntegrator1_b_i - 0.5F * rtb_Multiply3_c) *
        Controller_ConstB.Gain) * rtb_Cos;
    }

    /* Switch: '<S31>/Switch' incorporates:
     *  Gain: '<S30>/Gain3'
     *  RelationalOperator: '<S31>/UpperRelop'
     */
    if (rtb_DiscreteTimeIntegrator1_b_i >= -rtb_a_n) {
      rtb_Saturation_nc = rtb_DiscreteTimeIntegrator1_b_i;
    }

    /* Switch: '<S31>/Switch2' incorporates:
     *  RelationalOperator: '<S31>/LowerRelop1'
     */
    if (rtb_DiscreteTimeIntegrator1_b_i <= rtb_a_n) {
      rtb_a_n = rtb_Saturation_nc;
    }

    /* Saturate: '<S13>/Saturation1' */
    if (rtb_a_n > CONTROL_PARAM.P_Q_CMD_LIM) {
      rtb_a_n = CONTROL_PARAM.P_Q_CMD_LIM;
    } else {
      if (rtb_a_n < -CONTROL_PARAM.P_Q_CMD_LIM) {
        rtb_a_n = -CONTROL_PARAM.P_Q_CMD_LIM;
      }
    }

    /* Trigonometry: '<S23>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Cos = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S23>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Cos1 = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Trigonometry: '<S23>/Sin' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Multiply4_b = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Product: '<S23>/Multiply3' */
    rtb_Multiply3_c = rtb_Multiply4_b * rtb_Cos1 * rtb_Saturation_m;

    /* Product: '<S23>/Multiply4' */
    rtb_Multiply4_b *= rtb_a_n;
    rtb_DiscreteTimeIntegrator1_b_i = rtb_Saturation1_i_idx_0 - arm_sin_f32
      (Controller_U.INS_Out.theta) * rtb_Saturation_m;
    rtb_Multiply3_c += rtb_Cos * rtb_a_n;
    rtb_Saturation_m = rtb_Cos * rtb_Cos1 * rtb_Saturation_m - rtb_Multiply4_b;
  }

  /* End of Switch: '<S14>/Switch' */

  /* Sum: '<S15>/Sum' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Cos = rtb_DiscreteTimeIntegrator1_b_i - Controller_U.INS_Out.p;
  rtb_Cos1 = rtb_Multiply3_c - Controller_U.INS_Out.q;
  rtb_Multiply4_b = rtb_Saturation_m - Controller_U.INS_Out.r;

  /* DiscreteIntegrator: '<S18>/Discrete-Time Integrator5' */
  if (Controller_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] = rtb_Cos;
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] = rtb_Cos1;
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] = rtb_Multiply4_b;
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
  rtb_Multiply3_c = (Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] -
                     Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[1]) *
    188.49556F;
  rtb_Saturation_m = (Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] -
                      Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[2]) *
    188.49556F;

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
      rtb_Saturation_d_idx_1 = rtb_Multiply3_c;
      rtb_Saturation_d_idx_2 = rtb_Saturation_m;
    }

    /* End of Switch: '<S22>/Switch' */

    /* Product: '<S19>/Multiply' incorporates:
     *  Constant: '<S19>/gain1'
     */
    rtb_Subtract3_i = CONTROL_PARAM.ROLL_RATE_D * rtb_Saturation_d_idx_0;

    /* Saturate: '<S19>/Saturation' */
    if (rtb_Subtract3_i > CONTROL_PARAM.RATE_D_MAX) {
      rtb_Subtract3_i = CONTROL_PARAM.RATE_D_MAX;
    } else {
      if (rtb_Subtract3_i < CONTROL_PARAM.RATE_D_MIN) {
        rtb_Subtract3_i = CONTROL_PARAM.RATE_D_MIN;
      }
    }

    rtb_Saturation_d_idx_0 = rtb_Subtract3_i;

    /* Product: '<S19>/Multiply' incorporates:
     *  Constant: '<S19>/gain2'
     */
    rtb_Subtract3_i = CONTROL_PARAM.PITCH_RATE_D * rtb_Saturation_d_idx_1;

    /* Saturate: '<S19>/Saturation' */
    if (rtb_Subtract3_i > CONTROL_PARAM.RATE_D_MAX) {
      rtb_Subtract3_i = CONTROL_PARAM.RATE_D_MAX;
    } else {
      if (rtb_Subtract3_i < CONTROL_PARAM.RATE_D_MIN) {
        rtb_Subtract3_i = CONTROL_PARAM.RATE_D_MIN;
      }
    }

    rtb_Saturation_d_idx_1 = rtb_Subtract3_i;

    /* Product: '<S19>/Multiply' incorporates:
     *  Constant: '<S19>/gain3'
     */
    rtb_Subtract3_i = CONTROL_PARAM.YAW_RATE_D * rtb_Saturation_d_idx_2;

    /* Saturate: '<S19>/Saturation' */
    if (rtb_Subtract3_i > CONTROL_PARAM.RATE_D_MAX) {
      rtb_Subtract3_i = CONTROL_PARAM.RATE_D_MAX;
    } else {
      if (rtb_Subtract3_i < CONTROL_PARAM.RATE_D_MIN) {
        rtb_Subtract3_i = CONTROL_PARAM.RATE_D_MIN;
      }
    }

    /* Switch: '<S45>/Switch' incorporates:
     *  Constant: '<S46>/Constant1'
     *  Gain: '<S46>/Gain1'
     *  Logic: '<S45>/Logical Operator'
     *  RelationalOperator: '<S47>/Compare'
     *  Sum: '<S46>/Sum1'
     */
    if ((Controller_U.FMS_Out.ctrl_mode == 1) || (Controller_U.FMS_Out.ctrl_mode
         == 2) || (Controller_U.FMS_Out.ctrl_mode == 3)) {
      rtb_throttle_cmd = Controller_U.FMS_Out.throttle_cmd;
    } else {
      /* Product: '<S49>/Multiply' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S49>/Cos'
       *  Trigonometry: '<S49>/Cos1'
       */
      rtb_Saturation_nc = arm_cos_f32(Controller_U.INS_Out.phi) * arm_cos_f32
        (Controller_U.INS_Out.theta);

      /* Gain: '<S49>/Gain' */
      rtb_a_n = 2.0F * rtb_Saturation_nc;

      /* Saturate: '<S49>/Saturation1' */
      if (rtb_Saturation_nc > 1.0F) {
        rtb_Saturation_nc = 1.0F;
      } else {
        if (rtb_Saturation_nc < 0.5F) {
          rtb_Saturation_nc = 0.5F;
        }
      }

      /* End of Saturate: '<S49>/Saturation1' */

      /* Product: '<S49>/Divide' incorporates:
       *  Constant: '<S49>/Constant'
       */
      rtb_Saturation1_i_idx_0 = 1.0F / rtb_Saturation_nc;

      /* Switch: '<S57>/Switch' incorporates:
       *  Gain: '<S57>/Gain1'
       */
      if (Controller_U.FMS_Out.reset > 0) {
        rtb_Saturation_nc = 0.0F;
      } else {
        rtb_Saturation_nc = rtb_Gain_am;
      }

      /* End of Switch: '<S57>/Switch' */

      /* Product: '<S54>/Multiply' incorporates:
       *  Constant: '<S54>/kd'
       */
      rtb_Saturation_nc *= CONTROL_PARAM.VEL_Z_D;

      /* Saturate: '<S54>/Saturation' */
      if (rtb_Saturation_nc > CONTROL_PARAM.VEL_Z_D_MAX) {
        rtb_Saturation_nc = CONTROL_PARAM.VEL_Z_D_MAX;
      } else {
        if (rtb_Saturation_nc < CONTROL_PARAM.VEL_Z_D_MIN) {
          rtb_Saturation_nc = CONTROL_PARAM.VEL_Z_D_MIN;
        }
      }

      /* End of Saturate: '<S54>/Saturation' */

      /* Saturate: '<S49>/Saturation' */
      if (rtb_a_n > 1.0F) {
        rtb_a_n = 1.0F;
      } else {
        if (rtb_a_n < 0.0F) {
          rtb_a_n = 0.0F;
        }
      }

      /* End of Saturate: '<S49>/Saturation' */

      /* Product: '<S49>/Multiply1' incorporates:
       *  Constant: '<S56>/kp'
       *  DiscreteIntegrator: '<S55>/Discrete-Time Integrator'
       *  Product: '<S56>/Multiply'
       *  Sum: '<S51>/Add'
       */
      rtb_Saturation_nc = ((CONTROL_PARAM.VEL_Z_P * rtb_Gain +
                            Controller_DW.DiscreteTimeIntegrator_DSTATE) +
                           rtb_Saturation_nc) * rtb_Saturation1_i_idx_0 *
        rtb_a_n;

      /* Saturate: '<S48>/Saturation' */
      if (rtb_Saturation_nc > 0.35F) {
        rtb_Saturation_nc = 0.35F;
      } else {
        if (rtb_Saturation_nc < -0.35F) {
          rtb_Saturation_nc = -0.35F;
        }
      }

      /* End of Saturate: '<S48>/Saturation' */

      /* Sum: '<S46>/Sum' incorporates:
       *  Constant: '<S46>/hover_throttle'
       */
      rtb_Saturation_nc += 0.5F;
      rtb_throttle_cmd = (uint32_T)fmodf(floorf(1000.0F * rtb_Saturation_nc),
        4.2949673E+9F) + 1000U;
    }

    /* End of Switch: '<S45>/Switch' */

    /* Saturate: '<S6>/Saturation1' incorporates:
     *  Constant: '<S21>/gain1'
     *  Constant: '<S21>/gain2'
     *  Constant: '<S21>/gain3'
     *  DiscreteIntegrator: '<S18>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S20>/Discrete-Time Integrator'
     *  Product: '<S21>/Multiply'
     *  Sum: '<S16>/Add'
     */
    rtb_a_n = (CONTROL_PARAM.ROLL_RATE_P *
               Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] +
               Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0]) +
      rtb_Saturation_d_idx_0;
    if (rtb_a_n > 1.0F) {
      rtb_a_n = 1.0F;
    } else {
      if (rtb_a_n < -1.0F) {
        rtb_a_n = -1.0F;
      }
    }

    rtb_Saturation_d_idx_0 = (CONTROL_PARAM.PITCH_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1]) + rtb_Saturation_d_idx_1;
    if (rtb_Saturation_d_idx_0 > 1.0F) {
      rtb_Saturation_d_idx_0 = 1.0F;
    } else {
      if (rtb_Saturation_d_idx_0 < -1.0F) {
        rtb_Saturation_d_idx_0 = -1.0F;
      }
    }

    rtb_Saturation_d_idx_1 = (CONTROL_PARAM.YAW_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2]) + rtb_Subtract3_i;
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
      rtb_Saturation_nc = fmodf(floorf(1000.0F *
        (Controller_ConstP.X_Frame_Effective_Matrix_Value[i + 8] *
         rtb_Saturation_d_idx_1 +
         (Controller_ConstP.X_Frame_Effective_Matrix_Value[i + 4] *
          rtb_Saturation_d_idx_0 +
          Controller_ConstP.X_Frame_Effective_Matrix_Value[i] * rtb_a_n))),
        65536.0F);
      u0 = (uint16_T)((uint32_T)(rtb_Saturation_nc < 0.0F ? (int32_T)(uint16_T)
        -(int16_T)(uint16_T)-rtb_Saturation_nc : (int32_T)(uint16_T)
        rtb_Saturation_nc) + (uint16_T)rtb_throttle_cmd);
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

  /* Product: '<S40>/Multiply1' incorporates:
   *  Constant: '<S40>/const1'
   *  DiscreteIntegrator: '<S37>/Integrator'
   */
  rtb_Atan_idx_0 = Controller_DW.Integrator_DSTATE[0] * 0.05F;
  rtb_Atan_idx_1 = Controller_DW.Integrator_DSTATE[1] * 0.05F;

  /* Sum: '<S40>/Add' incorporates:
   *  DiscreteIntegrator: '<S37>/Integrator1'
   *  Inport: '<Root>/FMS_Out'
   *  Sum: '<S37>/Subtract'
   */
  rtb_Saturation1_i_idx_0 = (Controller_DW.Integrator1_DSTATE_g[0] -
    Controller_U.FMS_Out.u_cmd) + rtb_Atan_idx_0;
  rtb_Saturation1_i_idx_1 = (Controller_DW.Integrator1_DSTATE_g[1] -
    Controller_U.FMS_Out.v_cmd) + rtb_Atan_idx_1;

  /* Signum: '<S40>/Sign' */
  if (rtb_Saturation1_i_idx_0 < 0.0F) {
    rtb_Saturation_nc = -1.0F;
  } else if (rtb_Saturation1_i_idx_0 > 0.0F) {
    rtb_Saturation_nc = 1.0F;
  } else {
    rtb_Saturation_nc = rtb_Saturation1_i_idx_0;
  }

  /* Sum: '<S40>/Add2' incorporates:
   *  Abs: '<S40>/Abs'
   *  Gain: '<S40>/Gain'
   *  Gain: '<S40>/Gain1'
   *  Product: '<S40>/Multiply2'
   *  Product: '<S40>/Multiply3'
   *  Signum: '<S40>/Sign'
   *  Sqrt: '<S40>/Sqrt'
   *  Sum: '<S40>/Add1'
   *  Sum: '<S40>/Subtract'
   */
  rtb_Saturation_nc = (sqrtf((8.0F * fabsf(rtb_Saturation1_i_idx_0) +
    Controller_ConstB.d) * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
    rtb_Saturation_nc + rtb_Atan_idx_0;

  /* Sum: '<S40>/Add3' incorporates:
   *  Signum: '<S40>/Sign'
   */
  rtb_Subtract3_i = rtb_Saturation1_i_idx_0 + Controller_ConstB.d;

  /* Sum: '<S40>/Subtract1' incorporates:
   *  Signum: '<S40>/Sign'
   */
  rtb_a_n = rtb_Saturation1_i_idx_0 - Controller_ConstB.d;

  /* Signum: '<S40>/Sign1' */
  if (rtb_Subtract3_i < 0.0F) {
    rtb_Subtract3_i = -1.0F;
  } else {
    if (rtb_Subtract3_i > 0.0F) {
      rtb_Subtract3_i = 1.0F;
    }
  }

  /* Signum: '<S40>/Sign2' */
  if (rtb_a_n < 0.0F) {
    rtb_a_n = -1.0F;
  } else {
    if (rtb_a_n > 0.0F) {
      rtb_a_n = 1.0F;
    }
  }

  /* Sum: '<S40>/Add2' incorporates:
   *  Gain: '<S40>/Gain2'
   *  Product: '<S40>/Multiply4'
   *  Signum: '<S40>/Sign'
   *  Sum: '<S40>/Add4'
   *  Sum: '<S40>/Add5'
   *  Sum: '<S40>/Subtract2'
   */
  rtb_Saturation1_i_idx_0 = ((rtb_Saturation1_i_idx_0 - rtb_Saturation_nc) +
    rtb_Atan_idx_0) * ((rtb_Subtract3_i - rtb_a_n) * 0.5F) + rtb_Saturation_nc;

  /* Signum: '<S40>/Sign' */
  if (rtb_Saturation1_i_idx_1 < 0.0F) {
    rtb_Saturation_nc = -1.0F;
  } else if (rtb_Saturation1_i_idx_1 > 0.0F) {
    rtb_Saturation_nc = 1.0F;
  } else {
    rtb_Saturation_nc = rtb_Saturation1_i_idx_1;
  }

  /* Sum: '<S40>/Add2' incorporates:
   *  Abs: '<S40>/Abs'
   *  Gain: '<S40>/Gain'
   *  Gain: '<S40>/Gain1'
   *  Product: '<S40>/Multiply2'
   *  Product: '<S40>/Multiply3'
   *  Signum: '<S40>/Sign'
   *  Sqrt: '<S40>/Sqrt'
   *  Sum: '<S40>/Add1'
   *  Sum: '<S40>/Subtract'
   */
  rtb_Saturation_nc = (sqrtf((8.0F * fabsf(rtb_Saturation1_i_idx_1) +
    Controller_ConstB.d) * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
    rtb_Saturation_nc + rtb_Atan_idx_1;

  /* Sum: '<S40>/Add3' incorporates:
   *  Signum: '<S40>/Sign'
   */
  rtb_Subtract3_i = rtb_Saturation1_i_idx_1 + Controller_ConstB.d;

  /* Sum: '<S40>/Subtract1' incorporates:
   *  Signum: '<S40>/Sign'
   */
  rtb_a_n = rtb_Saturation1_i_idx_1 - Controller_ConstB.d;

  /* Signum: '<S40>/Sign1' */
  if (rtb_Subtract3_i < 0.0F) {
    rtb_Subtract3_i = -1.0F;
  } else {
    if (rtb_Subtract3_i > 0.0F) {
      rtb_Subtract3_i = 1.0F;
    }
  }

  /* Signum: '<S40>/Sign2' */
  if (rtb_a_n < 0.0F) {
    rtb_a_n = -1.0F;
  } else {
    if (rtb_a_n > 0.0F) {
      rtb_a_n = 1.0F;
    }
  }

  /* Sum: '<S40>/Add5' incorporates:
   *  Gain: '<S40>/Gain2'
   *  Product: '<S40>/Multiply4'
   *  Signum: '<S40>/Sign'
   *  Sum: '<S40>/Add2'
   *  Sum: '<S40>/Add4'
   *  Sum: '<S40>/Subtract2'
   */
  rtb_Saturation_nc += ((rtb_Saturation1_i_idx_1 - rtb_Saturation_nc) +
                        rtb_Atan_idx_1) * ((rtb_Subtract3_i - rtb_a_n) * 0.5F);

  /* Outport: '<Root>/Control_Out' incorporates:
   *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
   */
  Controller_Y.Control_Out.timestamp =
    Controller_DW.DiscreteTimeIntegrator_DSTATE_n;

  /* Product: '<S53>/Multiply1' incorporates:
   *  Constant: '<S53>/const1'
   *  DiscreteIntegrator: '<S52>/Integrator'
   */
  rtb_Subtract3_i = Controller_DW.Integrator_DSTATE_p * 0.05F;

  /* Sum: '<S53>/Add' incorporates:
   *  DiscreteIntegrator: '<S52>/Integrator1'
   *  Inport: '<Root>/FMS_Out'
   *  Sum: '<S52>/Subtract'
   */
  rtb_Atan_idx_1 = (Controller_DW.Integrator1_DSTATE -
                    Controller_U.FMS_Out.w_cmd) + rtb_Subtract3_i;

  /* Signum: '<S53>/Sign' */
  if (rtb_Atan_idx_1 < 0.0F) {
    rtb_a_n = -1.0F;
  } else if (rtb_Atan_idx_1 > 0.0F) {
    rtb_a_n = 1.0F;
  } else {
    rtb_a_n = rtb_Atan_idx_1;
  }

  /* End of Signum: '<S53>/Sign' */

  /* Sum: '<S53>/Add2' incorporates:
   *  Abs: '<S53>/Abs'
   *  Gain: '<S53>/Gain'
   *  Gain: '<S53>/Gain1'
   *  Product: '<S53>/Multiply2'
   *  Product: '<S53>/Multiply3'
   *  Sqrt: '<S53>/Sqrt'
   *  Sum: '<S53>/Add1'
   *  Sum: '<S53>/Subtract'
   */
  rtb_a_n = (sqrtf((8.0F * fabsf(rtb_Atan_idx_1) + Controller_ConstB.d_n) *
                   Controller_ConstB.d_n) - Controller_ConstB.d_n) * 0.5F *
    rtb_a_n + rtb_Subtract3_i;

  /* Sum: '<S53>/Add4' */
  rtb_Atan_idx_0 = (rtb_Atan_idx_1 - rtb_a_n) + rtb_Subtract3_i;

  /* Sum: '<S53>/Add3' */
  rtb_Subtract3_i = rtb_Atan_idx_1 + Controller_ConstB.d_n;

  /* Sum: '<S53>/Subtract1' */
  rtb_Atan_idx_1 -= Controller_ConstB.d_n;

  /* Signum: '<S53>/Sign1' */
  if (rtb_Subtract3_i < 0.0F) {
    rtb_Subtract3_i = -1.0F;
  } else {
    if (rtb_Subtract3_i > 0.0F) {
      rtb_Subtract3_i = 1.0F;
    }
  }

  /* End of Signum: '<S53>/Sign1' */

  /* Signum: '<S53>/Sign2' */
  if (rtb_Atan_idx_1 < 0.0F) {
    rtb_Atan_idx_1 = -1.0F;
  } else {
    if (rtb_Atan_idx_1 > 0.0F) {
      rtb_Atan_idx_1 = 1.0F;
    }
  }

  /* End of Signum: '<S53>/Sign2' */

  /* Sum: '<S53>/Add5' incorporates:
   *  Gain: '<S53>/Gain2'
   *  Product: '<S53>/Multiply4'
   *  Sum: '<S53>/Subtract2'
   */
  rtb_a_n += (rtb_Subtract3_i - rtb_Atan_idx_1) * 0.5F * rtb_Atan_idx_0;

  /* Update for DiscreteIntegrator: '<S52>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S52>/Integrator'
   */
  Controller_DW.Integrator1_DSTATE += 0.002F * Controller_DW.Integrator_DSTATE_p;

  /* Update for DiscreteIntegrator: '<S55>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S55>/ki'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S55>/Multiply'
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

  /* End of Update for DiscreteIntegrator: '<S55>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S57>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_DSTATE += 0.002F * rtb_Gain_am;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S42>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator_PrevRe_e = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S37>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S37>/Integrator'
   */
  Controller_DW.Integrator1_DSTATE_g[0] += 0.002F *
    Controller_DW.Integrator_DSTATE[0];

  /* Update for DiscreteIntegrator: '<S42>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S42>/ki'
   *  Product: '<S42>/Multiply'
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

  /* Update for DiscreteIntegrator: '<S44>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[0] += 0.002F * rtb_Gain_j_idx_0;

  /* Update for DiscreteIntegrator: '<S37>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S37>/Integrator'
   */
  Controller_DW.Integrator1_DSTATE_g[1] += 0.002F *
    Controller_DW.Integrator_DSTATE[1];

  /* Update for DiscreteIntegrator: '<S42>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S42>/ki'
   *  Product: '<S42>/Multiply'
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

  /* Update for DiscreteIntegrator: '<S44>/Discrete-Time Integrator1' incorporates:
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
  Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] += (rtb_Cos -
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
  Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] += (rtb_Cos1 -
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
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[1] += 0.002F * rtb_Multiply3_c;

  /* Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S18>/Gain'
   *  Sum: '<S18>/Sum5'
   */
  Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] += (rtb_Multiply4_b -
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
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[2] += 0.002F * rtb_Saturation_m;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_i = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Signum: '<S40>/Sign3' incorporates:
   *  Product: '<S40>/Divide'
   *  Sum: '<S40>/Add6'
   */
  rtb_Subtract3_i = rtb_Saturation1_i_idx_0 + Controller_ConstB.d;

  /* Signum: '<S40>/Sign4' incorporates:
   *  Product: '<S40>/Divide'
   *  Sum: '<S40>/Subtract3'
   */
  rtb_Gain = rtb_Saturation1_i_idx_0 - Controller_ConstB.d;

  /* Signum: '<S40>/Sign5' incorporates:
   *  Product: '<S40>/Divide'
   */
  if (rtb_Saturation1_i_idx_0 < 0.0F) {
    rtb_Gain_am = -1.0F;
  } else if (rtb_Saturation1_i_idx_0 > 0.0F) {
    rtb_Gain_am = 1.0F;
  } else {
    rtb_Gain_am = rtb_Saturation1_i_idx_0;
  }

  /* Signum: '<S40>/Sign3' */
  if (rtb_Subtract3_i < 0.0F) {
    rtb_Subtract3_i = -1.0F;
  } else {
    if (rtb_Subtract3_i > 0.0F) {
      rtb_Subtract3_i = 1.0F;
    }
  }

  /* Signum: '<S40>/Sign4' */
  if (rtb_Gain < 0.0F) {
    rtb_Gain = -1.0F;
  } else {
    if (rtb_Gain > 0.0F) {
      rtb_Gain = 1.0F;
    }
  }

  /* Signum: '<S40>/Sign6' incorporates:
   *  Product: '<S40>/Divide'
   */
  if (rtb_Saturation1_i_idx_0 < 0.0F) {
    rtb_uv_error_C_mPs_idx_0 = -1.0F;
  } else if (rtb_Saturation1_i_idx_0 > 0.0F) {
    rtb_uv_error_C_mPs_idx_0 = 1.0F;
  } else {
    rtb_uv_error_C_mPs_idx_0 = rtb_Saturation1_i_idx_0;
  }

  /* Update for DiscreteIntegrator: '<S37>/Integrator' incorporates:
   *  Constant: '<S40>/const'
   *  Gain: '<S40>/Gain3'
   *  Product: '<S40>/Divide'
   *  Product: '<S40>/Multiply5'
   *  Product: '<S40>/Multiply6'
   *  Sum: '<S40>/Subtract4'
   *  Sum: '<S40>/Subtract5'
   *  Sum: '<S40>/Subtract6'
   */
  Controller_DW.Integrator_DSTATE[0] += ((rtb_Saturation1_i_idx_0 /
    Controller_ConstB.d - rtb_Gain_am) * Controller_ConstB.Gain4 *
    ((rtb_Subtract3_i - rtb_Gain) * 0.5F) - rtb_uv_error_C_mPs_idx_0 * 58.836F) *
    0.002F;

  /* Signum: '<S40>/Sign3' incorporates:
   *  Sum: '<S40>/Add6'
   */
  rtb_Subtract3_i = rtb_Saturation_nc + Controller_ConstB.d;

  /* Signum: '<S40>/Sign4' incorporates:
   *  Sum: '<S40>/Subtract3'
   */
  rtb_Gain = rtb_Saturation_nc - Controller_ConstB.d;

  /* Signum: '<S40>/Sign5' */
  if (rtb_Saturation_nc < 0.0F) {
    rtb_Gain_am = -1.0F;
  } else if (rtb_Saturation_nc > 0.0F) {
    rtb_Gain_am = 1.0F;
  } else {
    rtb_Gain_am = rtb_Saturation_nc;
  }

  /* Signum: '<S40>/Sign3' */
  if (rtb_Subtract3_i < 0.0F) {
    rtb_Subtract3_i = -1.0F;
  } else {
    if (rtb_Subtract3_i > 0.0F) {
      rtb_Subtract3_i = 1.0F;
    }
  }

  /* Signum: '<S40>/Sign4' */
  if (rtb_Gain < 0.0F) {
    rtb_Gain = -1.0F;
  } else {
    if (rtb_Gain > 0.0F) {
      rtb_Gain = 1.0F;
    }
  }

  /* Signum: '<S40>/Sign6' */
  if (rtb_Saturation_nc < 0.0F) {
    rtb_uv_error_C_mPs_idx_0 = -1.0F;
  } else if (rtb_Saturation_nc > 0.0F) {
    rtb_uv_error_C_mPs_idx_0 = 1.0F;
  } else {
    rtb_uv_error_C_mPs_idx_0 = rtb_Saturation_nc;
  }

  /* Update for DiscreteIntegrator: '<S37>/Integrator' incorporates:
   *  Constant: '<S40>/const'
   *  Gain: '<S40>/Gain3'
   *  Product: '<S40>/Divide'
   *  Product: '<S40>/Multiply5'
   *  Product: '<S40>/Multiply6'
   *  Sum: '<S40>/Subtract4'
   *  Sum: '<S40>/Subtract5'
   *  Sum: '<S40>/Subtract6'
   */
  Controller_DW.Integrator_DSTATE[1] += ((rtb_Saturation_nc /
    Controller_ConstB.d - rtb_Gain_am) * Controller_ConstB.Gain4 *
    ((rtb_Subtract3_i - rtb_Gain) * 0.5F) - rtb_uv_error_C_mPs_idx_0 * 58.836F) *
    0.002F;

  /* Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S4>/Constant'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_n += CONTROL_EXPORT.period;

  /* Signum: '<S53>/Sign6' incorporates:
   *  Signum: '<S53>/Sign5'
   */
  if (rtb_a_n < 0.0F) {
    rtb_Gain_am = -1.0F;

    /* Signum: '<S53>/Sign5' */
    rtb_uv_error_C_mPs_idx_0 = -1.0F;
  } else if (rtb_a_n > 0.0F) {
    rtb_Gain_am = 1.0F;

    /* Signum: '<S53>/Sign5' */
    rtb_uv_error_C_mPs_idx_0 = 1.0F;
  } else {
    rtb_Gain_am = rtb_a_n;

    /* Signum: '<S53>/Sign5' */
    rtb_uv_error_C_mPs_idx_0 = rtb_a_n;
  }

  /* End of Signum: '<S53>/Sign6' */

  /* Sum: '<S53>/Add6' */
  rtb_Subtract3_i = rtb_a_n + Controller_ConstB.d_n;

  /* Sum: '<S53>/Subtract3' */
  rtb_Gain = rtb_a_n - Controller_ConstB.d_n;

  /* Signum: '<S53>/Sign3' */
  if (rtb_Subtract3_i < 0.0F) {
    rtb_Subtract3_i = -1.0F;
  } else {
    if (rtb_Subtract3_i > 0.0F) {
      rtb_Subtract3_i = 1.0F;
    }
  }

  /* End of Signum: '<S53>/Sign3' */

  /* Signum: '<S53>/Sign4' */
  if (rtb_Gain < 0.0F) {
    rtb_Gain = -1.0F;
  } else {
    if (rtb_Gain > 0.0F) {
      rtb_Gain = 1.0F;
    }
  }

  /* End of Signum: '<S53>/Sign4' */

  /* Update for DiscreteIntegrator: '<S52>/Integrator' incorporates:
   *  Constant: '<S53>/const'
   *  Gain: '<S53>/Gain3'
   *  Product: '<S53>/Divide'
   *  Product: '<S53>/Multiply5'
   *  Product: '<S53>/Multiply6'
   *  Sum: '<S53>/Subtract4'
   *  Sum: '<S53>/Subtract5'
   *  Sum: '<S53>/Subtract6'
   */
  Controller_DW.Integrator_DSTATE_p += ((rtb_a_n / Controller_ConstB.d_n -
    rtb_uv_error_C_mPs_idx_0) * Controller_ConstB.Gain4_k * ((rtb_Subtract3_i -
    rtb_Gain) * 0.5F) - rtb_Gain_am * 78.448F) * 0.002F;
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

  /* InitializeConditions for DiscreteIntegrator: '<S55>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S55>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S57>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S42>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S42>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S44>/Discrete-Time Integrator1' */
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
