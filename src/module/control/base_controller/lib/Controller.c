/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.850
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Aug  6 23:08:47 2021
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
                                        *   '<S35>/Saturation'
                                        *   '<S13>/Saturation'
                                        *   '<S13>/Saturation1'
                                        *   '<S43>/kd'
                                        *   '<S43>/Saturation'
                                        *   '<S44>/ki'
                                        *   '<S44>/Discrete-Time Integrator'
                                        *   '<S45>/kp'
                                        *   '<S56>/kd'
                                        *   '<S56>/Saturation'
                                        *   '<S57>/ki'
                                        *   '<S57>/Discrete-Time Integrator'
                                        *   '<S58>/kp'
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
    118, 48, 46, 49, 46, 48, 0 }
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
  real32_T rtb_a_n;
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
  real32_T rtb_Saturation_nc;
  int32_T i;
  real32_T rtb_VectorConcatenate_0[3];
  real32_T rtb_Saturation_jz;
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

  /* Gain: '<S52>/Gain' incorporates:
   *  DiscreteIntegrator: '<S54>/Integrator1'
   *  Inport: '<Root>/INS_Out'
   *  Sum: '<S52>/Sum1'
   */
  rtb_Gain = -(Controller_DW.Integrator1_DSTATE - Controller_U.INS_Out.vd);

  /* DiscreteIntegrator: '<S57>/Discrete-Time Integrator' incorporates:
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

  /* DiscreteIntegrator: '<S59>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevRes != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTATE = 0.0F;
  }

  /* Gain: '<S59>/Gain' incorporates:
   *  DiscreteIntegrator: '<S59>/Discrete-Time Integrator1'
   *  Sum: '<S59>/Sum5'
   */
  rtb_Gain_am = (rtb_Gain - Controller_DW.DiscreteTimeIntegrator1_DSTATE) *
    62.831852F;

  /* Trigonometry: '<S41>/Trigonometric Function1' incorporates:
   *  Gain: '<S40>/Gain'
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S41>/Trigonometric Function3'
   */
  rtb_uv_error_C_mPs_idx_0 = arm_cos_f32(-Controller_U.INS_Out.psi);
  rtb_VectorConcatenate[0] = rtb_uv_error_C_mPs_idx_0;

  /* Trigonometry: '<S41>/Trigonometric Function' incorporates:
   *  Gain: '<S40>/Gain'
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S41>/Trigonometric Function2'
   */
  rtb_uv_error_C_mPs_idx_1 = arm_sin_f32(-Controller_U.INS_Out.psi);
  rtb_VectorConcatenate[1] = rtb_uv_error_C_mPs_idx_1;

  /* SignalConversion: '<S41>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S41>/Constant3'
   */
  rtb_VectorConcatenate[2] = 0.0F;

  /* Gain: '<S41>/Gain' */
  rtb_VectorConcatenate[3] = -rtb_uv_error_C_mPs_idx_1;

  /* Trigonometry: '<S41>/Trigonometric Function3' */
  rtb_VectorConcatenate[4] = rtb_uv_error_C_mPs_idx_0;

  /* SignalConversion: '<S41>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S41>/Constant4'
   */
  rtb_VectorConcatenate[5] = 0.0F;

  /* SignalConversion: '<S41>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate[6] = Controller_ConstB.VectorConcatenate3[0];
  rtb_VectorConcatenate[7] = Controller_ConstB.VectorConcatenate3[1];
  rtb_VectorConcatenate[8] = Controller_ConstB.VectorConcatenate3[2];

  /* Product: '<S38>/Multiply' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  SignalConversion: '<S38>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_0[i] = rtb_VectorConcatenate[i + 3] *
      Controller_U.INS_Out.ve + rtb_VectorConcatenate[i] *
      Controller_U.INS_Out.vn;
  }

  /* End of Product: '<S38>/Multiply' */

  /* Sum: '<S36>/Sum' incorporates:
   *  DiscreteIntegrator: '<S39>/Integrator1'
   */
  rtb_uv_error_C_mPs_idx_0 = Controller_DW.Integrator1_DSTATE_g[0] -
    rtb_VectorConcatenate_0[0];
  rtb_uv_error_C_mPs_idx_1 = Controller_DW.Integrator1_DSTATE_g[1] -
    rtb_VectorConcatenate_0[1];

  /* DiscreteIntegrator: '<S44>/Discrete-Time Integrator' incorporates:
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

  /* DiscreteIntegrator: '<S46>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevR_a != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[0] = 0.0F;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[1] = 0.0F;
  }

  /* Gain: '<S46>/Gain' incorporates:
   *  DiscreteIntegrator: '<S46>/Discrete-Time Integrator1'
   *  Sum: '<S46>/Sum5'
   */
  rtb_Gain_j_idx_0 = (rtb_uv_error_C_mPs_idx_0 -
                      Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[0]) *
    62.831852F;
  rtb_Gain_j_idx_1 = (rtb_uv_error_C_mPs_idx_1 -
                      Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[1]) *
    62.831852F;

  /* Switch: '<S14>/Switch' incorporates:
   *  Constant: '<S26>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  Inport: '<Root>/INS_Out'
   *  Product: '<S23>/Multiply'
   *  Product: '<S23>/Multiply1'
   *  Product: '<S23>/Multiply5'
   *  Product: '<S32>/Divide1'
   *  RelationalOperator: '<S26>/Compare'
   *  Saturate: '<S13>/Saturation'
   *  Sum: '<S23>/Add'
   *  Sum: '<S23>/Add1'
   *  Sum: '<S23>/Add2'
   *  Trigonometry: '<S23>/Sin1'
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

    /* Switch: '<S28>/Switch' incorporates:
     *  Constant: '<S34>/Constant'
     *  RelationalOperator: '<S34>/Compare'
     *  Saturate: '<S13>/Saturation'
     *  Switch: '<S46>/Switch'
     *  Trigonometry: '<S35>/Atan'
     */
    if (Controller_U.FMS_Out.mode >= 3) {
      rtb_Atan_idx_0 = Controller_U.FMS_Out.phi_cmd;
      rtb_Atan_idx_1 = Controller_U.FMS_Out.theta_cmd;
    } else {
      if (Controller_U.FMS_Out.reset > 0) {
        /* Switch: '<S46>/Switch' incorporates:
         *  Gain: '<S46>/Gain1'
         */
        rtb_Atan_idx_0 = 0.0F;
        rtb_Atan_idx_1 = 0.0F;
      } else {
        /* Switch: '<S46>/Switch' */
        rtb_Atan_idx_0 = rtb_Gain_j_idx_0;
        rtb_Atan_idx_1 = rtb_Gain_j_idx_1;
      }

      /* Product: '<S43>/Multiply' incorporates:
       *  Constant: '<S43>/kd'
       */
      rtb_DiscreteTimeIntegrator1_b_i = CONTROL_PARAM.VEL_XY_D * rtb_Atan_idx_0;

      /* Saturate: '<S43>/Saturation' */
      if (rtb_DiscreteTimeIntegrator1_b_i > CONTROL_PARAM.VEL_XY_D_MAX) {
        rtb_DiscreteTimeIntegrator1_b_i = CONTROL_PARAM.VEL_XY_D_MAX;
      } else {
        if (rtb_DiscreteTimeIntegrator1_b_i < CONTROL_PARAM.VEL_XY_D_MIN) {
          rtb_DiscreteTimeIntegrator1_b_i = CONTROL_PARAM.VEL_XY_D_MIN;
        }
      }

      /* Gain: '<S35>/Gain1' incorporates:
       *  Constant: '<S45>/kp'
       *  DiscreteIntegrator: '<S44>/Discrete-Time Integrator'
       *  Product: '<S43>/Multiply'
       *  Product: '<S45>/Multiply'
       *  Sum: '<S37>/Add'
       */
      rtb_Saturation_nc = (CONTROL_PARAM.VEL_XY_P * rtb_uv_error_C_mPs_idx_0 +
                           Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0]) +
        rtb_DiscreteTimeIntegrator1_b_i;

      /* Product: '<S43>/Multiply' incorporates:
       *  Constant: '<S43>/kd'
       */
      rtb_DiscreteTimeIntegrator1_b_i = CONTROL_PARAM.VEL_XY_D * rtb_Atan_idx_1;

      /* Saturate: '<S43>/Saturation' */
      if (rtb_DiscreteTimeIntegrator1_b_i > CONTROL_PARAM.VEL_XY_D_MAX) {
        rtb_DiscreteTimeIntegrator1_b_i = CONTROL_PARAM.VEL_XY_D_MAX;
      } else {
        if (rtb_DiscreteTimeIntegrator1_b_i < CONTROL_PARAM.VEL_XY_D_MIN) {
          rtb_DiscreteTimeIntegrator1_b_i = CONTROL_PARAM.VEL_XY_D_MIN;
        }
      }

      /* Sum: '<S37>/Add' incorporates:
       *  Constant: '<S45>/kp'
       *  DiscreteIntegrator: '<S44>/Discrete-Time Integrator'
       *  Product: '<S45>/Multiply'
       */
      rtb_DiscreteTimeIntegrator1_b_i += CONTROL_PARAM.VEL_XY_P *
        rtb_uv_error_C_mPs_idx_1 +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1];

      /* Trigonometry: '<S35>/Atan' incorporates:
       *  Constant: '<S35>/g'
       *  Gain: '<S35>/gain'
       *  Product: '<S35>/Divide'
       */
      rtb_Atan_idx_1 = atanf(1.1F * rtb_DiscreteTimeIntegrator1_b_i / 9.8055F);

      /* Saturate: '<S35>/Saturation' */
      if (rtb_Atan_idx_1 > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
        rtb_Atan_idx_1 = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_Atan_idx_1 < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
          rtb_Atan_idx_1 = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
        }
      }

      rtb_Atan_idx_0 = rtb_Atan_idx_1;

      /* Trigonometry: '<S35>/Atan' incorporates:
       *  Constant: '<S35>/g'
       *  Gain: '<S35>/Gain1'
       *  Gain: '<S35>/gain'
       *  Product: '<S35>/Divide'
       */
      rtb_Atan_idx_1 = atanf(1.1F * -rtb_Saturation_nc / 9.8055F);

      /* Saturate: '<S35>/Saturation' */
      if (rtb_Atan_idx_1 > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
        rtb_Atan_idx_1 = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_Atan_idx_1 < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
          rtb_Atan_idx_1 = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
        }
      }
    }

    /* End of Switch: '<S28>/Switch' */

    /* Sum: '<S29>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_DiscreteTimeIntegrator1_b_i = rtb_Atan_idx_0 - Controller_U.INS_Out.phi;

    /* Product: '<S32>/Divide1' incorporates:
     *  Abs: '<S32>/Abs'
     *  Constant: '<S32>/const2'
     */
    rtb_a_n = fabsf(rtb_DiscreteTimeIntegrator1_b_i) / 0.002F;

    /* Gain: '<S32>/Gain3' */
    rtb_Saturation_nc = -rtb_a_n;

    /* Product: '<S32>/Divide' incorporates:
     *  Constant: '<S30>/Constant1'
     *  Constant: '<S32>/const1'
     *  Math: '<S32>/Square'
     *  SignalConversion: '<S32>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_Multiply3_c = 9.5993F / (CONTROL_PARAM.ROLL_P * CONTROL_PARAM.ROLL_P);

    /* Signum: '<S32>/Sign' */
    if (rtb_DiscreteTimeIntegrator1_b_i < 0.0F) {
      rtb_Cos = -1.0F;
    } else if (rtb_DiscreteTimeIntegrator1_b_i > 0.0F) {
      rtb_Cos = 1.0F;
    } else {
      rtb_Cos = rtb_DiscreteTimeIntegrator1_b_i;
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
    if ((rtb_DiscreteTimeIntegrator1_b_i <= rtb_Multiply3_c) &&
        (rtb_DiscreteTimeIntegrator1_b_i >= -rtb_Multiply3_c)) {
      rtb_DiscreteTimeIntegrator1_b_i *= CONTROL_PARAM.ROLL_P;
    } else {
      rtb_DiscreteTimeIntegrator1_b_i = sqrtf((rtb_Cos *
        rtb_DiscreteTimeIntegrator1_b_i - 0.5F * rtb_Multiply3_c) *
        Controller_ConstB.Gain) * rtb_Cos;
    }

    /* Switch: '<S33>/Switch' incorporates:
     *  Gain: '<S32>/Gain3'
     *  RelationalOperator: '<S33>/UpperRelop'
     */
    if (rtb_DiscreteTimeIntegrator1_b_i >= -rtb_a_n) {
      rtb_Saturation_nc = rtb_DiscreteTimeIntegrator1_b_i;
    }

    /* Switch: '<S33>/Switch2' incorporates:
     *  RelationalOperator: '<S33>/LowerRelop1'
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

    /* Sum: '<S29>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S32>/Divide1'
     */
    rtb_DiscreteTimeIntegrator1_b_i = rtb_Atan_idx_1 -
      Controller_U.INS_Out.theta;

    /* Product: '<S32>/Divide1' incorporates:
     *  Abs: '<S32>/Abs'
     *  Constant: '<S32>/const2'
     */
    rtb_a_n = fabsf(rtb_DiscreteTimeIntegrator1_b_i) / 0.002F;

    /* Gain: '<S32>/Gain3' */
    rtb_Saturation_nc = -rtb_a_n;

    /* Product: '<S32>/Divide' incorporates:
     *  Constant: '<S30>/Constant2'
     *  Constant: '<S32>/const1'
     *  Math: '<S32>/Square'
     *  SignalConversion: '<S32>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_Multiply3_c = 9.5993F / (CONTROL_PARAM.PITCH_P * CONTROL_PARAM.PITCH_P);

    /* Signum: '<S32>/Sign' */
    if (rtb_DiscreteTimeIntegrator1_b_i < 0.0F) {
      rtb_Cos = -1.0F;
    } else if (rtb_DiscreteTimeIntegrator1_b_i > 0.0F) {
      rtb_Cos = 1.0F;
    } else {
      rtb_Cos = rtb_DiscreteTimeIntegrator1_b_i;
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
    if ((rtb_DiscreteTimeIntegrator1_b_i <= rtb_Multiply3_c) &&
        (rtb_DiscreteTimeIntegrator1_b_i >= -rtb_Multiply3_c)) {
      rtb_DiscreteTimeIntegrator1_b_i *= CONTROL_PARAM.PITCH_P;
    } else {
      rtb_DiscreteTimeIntegrator1_b_i = sqrtf((rtb_Cos *
        rtb_DiscreteTimeIntegrator1_b_i - 0.5F * rtb_Multiply3_c) *
        Controller_ConstB.Gain) * rtb_Cos;
    }

    /* Switch: '<S33>/Switch' incorporates:
     *  Gain: '<S32>/Gain3'
     *  RelationalOperator: '<S33>/UpperRelop'
     */
    if (rtb_DiscreteTimeIntegrator1_b_i >= -rtb_a_n) {
      rtb_Saturation_nc = rtb_DiscreteTimeIntegrator1_b_i;
    }

    /* Switch: '<S33>/Switch2' incorporates:
     *  RelationalOperator: '<S33>/LowerRelop1'
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
    rtb_Multiply4_my = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Product: '<S23>/Multiply3' */
    rtb_Multiply3_c = rtb_Multiply4_my * rtb_Cos1 * rtb_Saturation_m;

    /* Product: '<S23>/Multiply4' */
    rtb_Multiply4_my *= rtb_a_n;
    rtb_DiscreteTimeIntegrator1_b_i = rtb_Saturation1_i_idx_0 - arm_sin_f32
      (Controller_U.INS_Out.theta) * rtb_Saturation_m;
    rtb_Multiply3_c += rtb_Cos * rtb_a_n;
    rtb_Saturation_m = rtb_Cos * rtb_Cos1 * rtb_Saturation_m - rtb_Multiply4_my;
  }

  /* End of Switch: '<S14>/Switch' */

  /* Sum: '<S15>/Sum' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Cos = rtb_DiscreteTimeIntegrator1_b_i - Controller_U.INS_Out.p;
  rtb_Cos1 = rtb_Multiply3_c - Controller_U.INS_Out.q;
  rtb_Multiply4_my = rtb_Saturation_m - Controller_U.INS_Out.r;

  /* DiscreteIntegrator: '<S18>/Discrete-Time Integrator5' */
  if (Controller_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] = rtb_Cos;
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] = rtb_Cos1;
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] = rtb_Multiply4_my;
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
  if (Controller_U.FMS_Out.state == 2) {
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
    rtb_Saturation_jz = CONTROL_PARAM.ROLL_RATE_D * rtb_Saturation_d_idx_0;

    /* Saturate: '<S19>/Saturation' */
    if (rtb_Saturation_jz > CONTROL_PARAM.RATE_D_MAX) {
      rtb_Saturation_jz = CONTROL_PARAM.RATE_D_MAX;
    } else {
      if (rtb_Saturation_jz < CONTROL_PARAM.RATE_D_MIN) {
        rtb_Saturation_jz = CONTROL_PARAM.RATE_D_MIN;
      }
    }

    rtb_Saturation_d_idx_0 = rtb_Saturation_jz;

    /* Product: '<S19>/Multiply' incorporates:
     *  Constant: '<S19>/gain2'
     */
    rtb_Saturation_jz = CONTROL_PARAM.PITCH_RATE_D * rtb_Saturation_d_idx_1;

    /* Saturate: '<S19>/Saturation' */
    if (rtb_Saturation_jz > CONTROL_PARAM.RATE_D_MAX) {
      rtb_Saturation_jz = CONTROL_PARAM.RATE_D_MAX;
    } else {
      if (rtb_Saturation_jz < CONTROL_PARAM.RATE_D_MIN) {
        rtb_Saturation_jz = CONTROL_PARAM.RATE_D_MIN;
      }
    }

    rtb_Saturation_d_idx_1 = rtb_Saturation_jz;

    /* Product: '<S19>/Multiply' incorporates:
     *  Constant: '<S19>/gain3'
     */
    rtb_Saturation_jz = CONTROL_PARAM.YAW_RATE_D * rtb_Saturation_d_idx_2;

    /* Saturate: '<S19>/Saturation' */
    if (rtb_Saturation_jz > CONTROL_PARAM.RATE_D_MAX) {
      rtb_Saturation_jz = CONTROL_PARAM.RATE_D_MAX;
    } else {
      if (rtb_Saturation_jz < CONTROL_PARAM.RATE_D_MIN) {
        rtb_Saturation_jz = CONTROL_PARAM.RATE_D_MIN;
      }
    }

    /* Switch: '<S47>/Switch' incorporates:
     *  Constant: '<S48>/Constant1'
     *  Constant: '<S49>/Constant'
     *  Gain: '<S48>/Gain1'
     *  RelationalOperator: '<S49>/Compare'
     *  Sum: '<S48>/Sum1'
     */
    if (Controller_U.FMS_Out.mode >= 4) {
      rtb_throttle_cmd = Controller_U.FMS_Out.throttle_cmd;
    } else {
      /* Product: '<S51>/Multiply' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S51>/Cos'
       *  Trigonometry: '<S51>/Cos1'
       */
      rtb_Saturation_nc = arm_cos_f32(Controller_U.INS_Out.phi) * arm_cos_f32
        (Controller_U.INS_Out.theta);

      /* Gain: '<S51>/Gain' */
      rtb_Saturation_d_idx_2 = 2.0F * rtb_Saturation_nc;

      /* Saturate: '<S51>/Saturation1' */
      if (rtb_Saturation_nc > 1.0F) {
        rtb_Saturation_nc = 1.0F;
      } else {
        if (rtb_Saturation_nc < 0.5F) {
          rtb_Saturation_nc = 0.5F;
        }
      }

      /* End of Saturate: '<S51>/Saturation1' */

      /* Product: '<S51>/Divide' incorporates:
       *  Constant: '<S51>/Constant'
       */
      rtb_Saturation1_i_idx_0 = 1.0F / rtb_Saturation_nc;

      /* Switch: '<S59>/Switch' incorporates:
       *  Gain: '<S59>/Gain1'
       */
      if (Controller_U.FMS_Out.reset > 0) {
        rtb_Saturation_nc = 0.0F;
      } else {
        rtb_Saturation_nc = rtb_Gain_am;
      }

      /* End of Switch: '<S59>/Switch' */

      /* Product: '<S56>/Multiply' incorporates:
       *  Constant: '<S56>/kd'
       */
      rtb_Saturation_nc *= CONTROL_PARAM.VEL_Z_D;

      /* Saturate: '<S56>/Saturation' */
      if (rtb_Saturation_nc > CONTROL_PARAM.VEL_Z_D_MAX) {
        rtb_Saturation_nc = CONTROL_PARAM.VEL_Z_D_MAX;
      } else {
        if (rtb_Saturation_nc < CONTROL_PARAM.VEL_Z_D_MIN) {
          rtb_Saturation_nc = CONTROL_PARAM.VEL_Z_D_MIN;
        }
      }

      /* End of Saturate: '<S56>/Saturation' */

      /* Saturate: '<S51>/Saturation' */
      if (rtb_Saturation_d_idx_2 > 1.0F) {
        rtb_Saturation_d_idx_2 = 1.0F;
      } else {
        if (rtb_Saturation_d_idx_2 < 0.0F) {
          rtb_Saturation_d_idx_2 = 0.0F;
        }
      }

      /* End of Saturate: '<S51>/Saturation' */

      /* Product: '<S51>/Multiply1' incorporates:
       *  Constant: '<S58>/kp'
       *  DiscreteIntegrator: '<S57>/Discrete-Time Integrator'
       *  Product: '<S58>/Multiply'
       *  Sum: '<S53>/Add'
       */
      rtb_Saturation_nc = ((CONTROL_PARAM.VEL_Z_P * rtb_Gain +
                            Controller_DW.DiscreteTimeIntegrator_DSTATE) +
                           rtb_Saturation_nc) * rtb_Saturation1_i_idx_0 *
        rtb_Saturation_d_idx_2;

      /* Saturate: '<S50>/Saturation' */
      if (rtb_Saturation_nc > 0.35F) {
        rtb_Saturation_nc = 0.35F;
      } else {
        if (rtb_Saturation_nc < -0.35F) {
          rtb_Saturation_nc = -0.35F;
        }
      }

      /* End of Saturate: '<S50>/Saturation' */

      /* Sum: '<S48>/Sum' incorporates:
       *  Constant: '<S48>/hover_throttle'
       */
      rtb_Saturation_nc += 0.5F;
      rtb_throttle_cmd = (uint32_T)fmodf(floorf(1000.0F * rtb_Saturation_nc),
        4.2949673E+9F) + 1000U;
    }

    /* End of Switch: '<S47>/Switch' */

    /* Saturate: '<S6>/Saturation1' incorporates:
     *  Constant: '<S21>/gain1'
     *  Constant: '<S21>/gain2'
     *  Constant: '<S21>/gain3'
     *  DiscreteIntegrator: '<S18>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S20>/Discrete-Time Integrator'
     *  Product: '<S21>/Multiply'
     *  Sum: '<S16>/Add'
     */
    rtb_Saturation_d_idx_2 = (CONTROL_PARAM.ROLL_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0]) + rtb_Saturation_d_idx_0;
    if (rtb_Saturation_d_idx_2 > 1.0F) {
      rtb_Saturation_d_idx_2 = 1.0F;
    } else {
      if (rtb_Saturation_d_idx_2 < -1.0F) {
        rtb_Saturation_d_idx_2 = -1.0F;
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
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2]) + rtb_Saturation_jz;
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
          Controller_ConstP.X_Frame_Effective_Matrix_Value[i] *
          rtb_Saturation_d_idx_2))), 65536.0F);
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

  /* Product: '<S42>/Multiply1' incorporates:
   *  Constant: '<S42>/const1'
   *  DiscreteIntegrator: '<S39>/Integrator'
   */
  rtb_Atan_idx_0 = Controller_DW.Integrator_DSTATE[0] * 0.05F;
  rtb_Atan_idx_1 = Controller_DW.Integrator_DSTATE[1] * 0.05F;

  /* Sum: '<S42>/Add' incorporates:
   *  DiscreteIntegrator: '<S39>/Integrator1'
   *  Inport: '<Root>/FMS_Out'
   *  Sum: '<S39>/Subtract'
   */
  rtb_Saturation1_i_idx_0 = (Controller_DW.Integrator1_DSTATE_g[0] -
    Controller_U.FMS_Out.u_cmd) + rtb_Atan_idx_0;
  rtb_Saturation1_i_idx_1 = (Controller_DW.Integrator1_DSTATE_g[1] -
    Controller_U.FMS_Out.v_cmd) + rtb_Atan_idx_1;

  /* Signum: '<S42>/Sign' */
  if (rtb_Saturation1_i_idx_0 < 0.0F) {
    rtb_Saturation_nc = -1.0F;
  } else if (rtb_Saturation1_i_idx_0 > 0.0F) {
    rtb_Saturation_nc = 1.0F;
  } else {
    rtb_Saturation_nc = rtb_Saturation1_i_idx_0;
  }

  /* Sum: '<S42>/Add2' incorporates:
   *  Abs: '<S42>/Abs'
   *  Gain: '<S42>/Gain'
   *  Gain: '<S42>/Gain1'
   *  Product: '<S42>/Multiply2'
   *  Product: '<S42>/Multiply3'
   *  Signum: '<S42>/Sign'
   *  Sqrt: '<S42>/Sqrt'
   *  Sum: '<S42>/Add1'
   *  Sum: '<S42>/Subtract'
   */
  rtb_Saturation_nc = (sqrtf((8.0F * fabsf(rtb_Saturation1_i_idx_0) +
    Controller_ConstB.d) * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
    rtb_Saturation_nc + rtb_Atan_idx_0;

  /* Sum: '<S42>/Add3' incorporates:
   *  Signum: '<S42>/Sign'
   */
  rtb_Saturation_jz = rtb_Saturation1_i_idx_0 + Controller_ConstB.d;

  /* Sum: '<S42>/Subtract1' incorporates:
   *  Signum: '<S42>/Sign'
   */
  rtb_a_n = rtb_Saturation1_i_idx_0 - Controller_ConstB.d;

  /* Signum: '<S42>/Sign1' */
  if (rtb_Saturation_jz < 0.0F) {
    rtb_Saturation_jz = -1.0F;
  } else {
    if (rtb_Saturation_jz > 0.0F) {
      rtb_Saturation_jz = 1.0F;
    }
  }

  /* Signum: '<S42>/Sign2' */
  if (rtb_a_n < 0.0F) {
    rtb_a_n = -1.0F;
  } else {
    if (rtb_a_n > 0.0F) {
      rtb_a_n = 1.0F;
    }
  }

  /* Sum: '<S42>/Add2' incorporates:
   *  Gain: '<S42>/Gain2'
   *  Product: '<S42>/Multiply4'
   *  Signum: '<S42>/Sign'
   *  Sum: '<S42>/Add4'
   *  Sum: '<S42>/Add5'
   *  Sum: '<S42>/Subtract2'
   */
  rtb_Saturation1_i_idx_0 = ((rtb_Saturation1_i_idx_0 - rtb_Saturation_nc) +
    rtb_Atan_idx_0) * ((rtb_Saturation_jz - rtb_a_n) * 0.5F) + rtb_Saturation_nc;

  /* Signum: '<S42>/Sign' */
  if (rtb_Saturation1_i_idx_1 < 0.0F) {
    rtb_Saturation_nc = -1.0F;
  } else if (rtb_Saturation1_i_idx_1 > 0.0F) {
    rtb_Saturation_nc = 1.0F;
  } else {
    rtb_Saturation_nc = rtb_Saturation1_i_idx_1;
  }

  /* Sum: '<S42>/Add2' incorporates:
   *  Abs: '<S42>/Abs'
   *  Gain: '<S42>/Gain'
   *  Gain: '<S42>/Gain1'
   *  Product: '<S42>/Multiply2'
   *  Product: '<S42>/Multiply3'
   *  Signum: '<S42>/Sign'
   *  Sqrt: '<S42>/Sqrt'
   *  Sum: '<S42>/Add1'
   *  Sum: '<S42>/Subtract'
   */
  rtb_Saturation_nc = (sqrtf((8.0F * fabsf(rtb_Saturation1_i_idx_1) +
    Controller_ConstB.d) * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
    rtb_Saturation_nc + rtb_Atan_idx_1;

  /* Sum: '<S42>/Add3' incorporates:
   *  Signum: '<S42>/Sign'
   */
  rtb_Saturation_jz = rtb_Saturation1_i_idx_1 + Controller_ConstB.d;

  /* Sum: '<S42>/Subtract1' incorporates:
   *  Signum: '<S42>/Sign'
   */
  rtb_a_n = rtb_Saturation1_i_idx_1 - Controller_ConstB.d;

  /* Signum: '<S42>/Sign1' */
  if (rtb_Saturation_jz < 0.0F) {
    rtb_Saturation_jz = -1.0F;
  } else {
    if (rtb_Saturation_jz > 0.0F) {
      rtb_Saturation_jz = 1.0F;
    }
  }

  /* Signum: '<S42>/Sign2' */
  if (rtb_a_n < 0.0F) {
    rtb_a_n = -1.0F;
  } else {
    if (rtb_a_n > 0.0F) {
      rtb_a_n = 1.0F;
    }
  }

  /* Sum: '<S42>/Add5' incorporates:
   *  Gain: '<S42>/Gain2'
   *  Product: '<S42>/Multiply4'
   *  Signum: '<S42>/Sign'
   *  Sum: '<S42>/Add2'
   *  Sum: '<S42>/Add4'
   *  Sum: '<S42>/Subtract2'
   */
  rtb_Saturation_nc += ((rtb_Saturation1_i_idx_1 - rtb_Saturation_nc) +
                        rtb_Atan_idx_1) * ((rtb_Saturation_jz - rtb_a_n) * 0.5F);

  /* Outport: '<Root>/Control_Out' incorporates:
   *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
   */
  Controller_Y.Control_Out.timestamp =
    Controller_DW.DiscreteTimeIntegrator_DSTATE_n;

  /* Product: '<S25>/Multiply1' incorporates:
   *  Constant: '<S25>/const1'
   *  DiscreteIntegrator: '<S24>/Integrator'
   */
  rtb_Add3 = Controller_DW.Integrator_DSTATE_k * 0.02F;

  /* Sum: '<S25>/Add' incorporates:
   *  DiscreteIntegrator: '<S24>/Integrator1'
   *  Inport: '<Root>/FMS_Out'
   *  Sum: '<S24>/Subtract'
   */
  rtb_a_n = (Controller_DW.Integrator1_DSTATE_d -
             Controller_U.FMS_Out.psi_rate_cmd) + rtb_Add3;

  /* Signum: '<S25>/Sign' */
  if (rtb_a_n < 0.0F) {
    rtb_Saturation_jz = -1.0F;
  } else if (rtb_a_n > 0.0F) {
    rtb_Saturation_jz = 1.0F;
  } else {
    rtb_Saturation_jz = rtb_a_n;
  }

  /* End of Signum: '<S25>/Sign' */

  /* Sum: '<S25>/Add2' incorporates:
   *  Abs: '<S25>/Abs'
   *  Gain: '<S25>/Gain'
   *  Gain: '<S25>/Gain1'
   *  Product: '<S25>/Multiply2'
   *  Product: '<S25>/Multiply3'
   *  Sqrt: '<S25>/Sqrt'
   *  Sum: '<S25>/Add1'
   *  Sum: '<S25>/Subtract'
   */
  rtb_Subtract3_i = (sqrtf((8.0F * fabsf(rtb_a_n) + Controller_ConstB.d_j) *
    Controller_ConstB.d_j) - Controller_ConstB.d_j) * 0.5F * rtb_Saturation_jz +
    rtb_Add3;

  /* Sum: '<S25>/Add4' */
  rtb_Atan_idx_1 = (rtb_a_n - rtb_Subtract3_i) + rtb_Add3;

  /* Sum: '<S25>/Add3' */
  rtb_Saturation_jz = rtb_a_n + Controller_ConstB.d_j;

  /* Sum: '<S25>/Subtract1' */
  rtb_a_n -= Controller_ConstB.d_j;

  /* Signum: '<S25>/Sign1' */
  if (rtb_Saturation_jz < 0.0F) {
    rtb_Saturation_jz = -1.0F;
  } else {
    if (rtb_Saturation_jz > 0.0F) {
      rtb_Saturation_jz = 1.0F;
    }
  }

  /* End of Signum: '<S25>/Sign1' */

  /* Signum: '<S25>/Sign2' */
  if (rtb_a_n < 0.0F) {
    rtb_a_n = -1.0F;
  } else {
    if (rtb_a_n > 0.0F) {
      rtb_a_n = 1.0F;
    }
  }

  /* End of Signum: '<S25>/Sign2' */

  /* Sum: '<S25>/Add5' incorporates:
   *  Gain: '<S25>/Gain2'
   *  Product: '<S25>/Multiply4'
   *  Sum: '<S25>/Subtract2'
   */
  rtb_Subtract3_i += (rtb_Saturation_jz - rtb_a_n) * 0.5F * rtb_Atan_idx_1;

  /* Sum: '<S25>/Subtract3' */
  rtb_Saturation_jz = rtb_Subtract3_i - Controller_ConstB.d_j;

  /* Sum: '<S25>/Add6' */
  rtb_Atan_idx_1 = rtb_Subtract3_i + Controller_ConstB.d_j;

  /* Product: '<S25>/Divide' */
  rtb_Saturation1_i_idx_1 = rtb_Subtract3_i / Controller_ConstB.d_j;

  /* Signum: '<S25>/Sign5' incorporates:
   *  Signum: '<S25>/Sign6'
   */
  if (rtb_Subtract3_i < 0.0F) {
    rtb_Sign5_f = -1.0F;

    /* Signum: '<S25>/Sign6' */
    rtb_Atan_idx_0 = -1.0F;
  } else if (rtb_Subtract3_i > 0.0F) {
    rtb_Sign5_f = 1.0F;

    /* Signum: '<S25>/Sign6' */
    rtb_Atan_idx_0 = 1.0F;
  } else {
    rtb_Sign5_f = rtb_Subtract3_i;

    /* Signum: '<S25>/Sign6' */
    rtb_Atan_idx_0 = rtb_Subtract3_i;
  }

  /* End of Signum: '<S25>/Sign5' */

  /* Product: '<S55>/Multiply1' incorporates:
   *  Constant: '<S55>/const1'
   *  DiscreteIntegrator: '<S54>/Integrator'
   */
  rtb_Add3 = Controller_DW.Integrator_DSTATE_p * 0.05F;

  /* Sum: '<S55>/Add' incorporates:
   *  DiscreteIntegrator: '<S54>/Integrator1'
   *  Inport: '<Root>/FMS_Out'
   *  Sum: '<S54>/Subtract'
   */
  rtb_Subtract3_i = (Controller_DW.Integrator1_DSTATE -
                     Controller_U.FMS_Out.w_cmd) + rtb_Add3;

  /* Signum: '<S55>/Sign' */
  if (rtb_Subtract3_i < 0.0F) {
    rtb_a_n = -1.0F;
  } else if (rtb_Subtract3_i > 0.0F) {
    rtb_a_n = 1.0F;
  } else {
    rtb_a_n = rtb_Subtract3_i;
  }

  /* End of Signum: '<S55>/Sign' */

  /* Sum: '<S55>/Add2' incorporates:
   *  Abs: '<S55>/Abs'
   *  Gain: '<S55>/Gain'
   *  Gain: '<S55>/Gain1'
   *  Product: '<S55>/Multiply2'
   *  Product: '<S55>/Multiply3'
   *  Sqrt: '<S55>/Sqrt'
   *  Sum: '<S55>/Add1'
   *  Sum: '<S55>/Subtract'
   */
  rtb_a_n = (sqrtf((8.0F * fabsf(rtb_Subtract3_i) + Controller_ConstB.d_n) *
                   Controller_ConstB.d_n) - Controller_ConstB.d_n) * 0.5F *
    rtb_a_n + rtb_Add3;

  /* Sum: '<S55>/Add4' */
  rtb_Add4_i = (rtb_Subtract3_i - rtb_a_n) + rtb_Add3;

  /* Sum: '<S55>/Add3' */
  rtb_Add3 = rtb_Subtract3_i + Controller_ConstB.d_n;

  /* Sum: '<S55>/Subtract1' */
  rtb_Subtract3_i -= Controller_ConstB.d_n;

  /* Signum: '<S55>/Sign1' */
  if (rtb_Add3 < 0.0F) {
    rtb_Add3 = -1.0F;
  } else {
    if (rtb_Add3 > 0.0F) {
      rtb_Add3 = 1.0F;
    }
  }

  /* End of Signum: '<S55>/Sign1' */

  /* Signum: '<S55>/Sign2' */
  if (rtb_Subtract3_i < 0.0F) {
    rtb_Subtract3_i = -1.0F;
  } else {
    if (rtb_Subtract3_i > 0.0F) {
      rtb_Subtract3_i = 1.0F;
    }
  }

  /* End of Signum: '<S55>/Sign2' */

  /* Sum: '<S55>/Add5' incorporates:
   *  Gain: '<S55>/Gain2'
   *  Product: '<S55>/Multiply4'
   *  Sum: '<S55>/Subtract2'
   */
  rtb_a_n += (rtb_Add3 - rtb_Subtract3_i) * 0.5F * rtb_Add4_i;

  /* Update for DiscreteIntegrator: '<S54>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S54>/Integrator'
   */
  Controller_DW.Integrator1_DSTATE += 0.002F * Controller_DW.Integrator_DSTATE_p;

  /* Update for DiscreteIntegrator: '<S57>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S57>/ki'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S57>/Multiply'
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

  /* End of Update for DiscreteIntegrator: '<S57>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S59>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_DSTATE += 0.002F * rtb_Gain_am;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S44>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator_PrevRe_e = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S39>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S39>/Integrator'
   */
  Controller_DW.Integrator1_DSTATE_g[0] += 0.002F *
    Controller_DW.Integrator_DSTATE[0];

  /* Update for DiscreteIntegrator: '<S44>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S44>/ki'
   *  Product: '<S44>/Multiply'
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

  /* Update for DiscreteIntegrator: '<S46>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[0] += 0.002F * rtb_Gain_j_idx_0;

  /* Update for DiscreteIntegrator: '<S39>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S39>/Integrator'
   */
  Controller_DW.Integrator1_DSTATE_g[1] += 0.002F *
    Controller_DW.Integrator_DSTATE[1];

  /* Update for DiscreteIntegrator: '<S44>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S44>/ki'
   *  Product: '<S44>/Multiply'
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

  /* Update for DiscreteIntegrator: '<S46>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[1] += 0.002F * rtb_Gain_j_idx_1;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_a = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S24>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S24>/Integrator'
   */
  Controller_DW.Integrator1_DSTATE_d += 0.002F *
    Controller_DW.Integrator_DSTATE_k;

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
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 314.159271F * 0.002F;

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
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 314.159271F * 0.002F;

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
  Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] += (rtb_Multiply4_my -
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 314.159271F * 0.002F;

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

  /* Signum: '<S42>/Sign3' incorporates:
   *  Product: '<S42>/Divide'
   *  Sum: '<S42>/Add6'
   */
  rtb_Add3 = rtb_Saturation1_i_idx_0 + Controller_ConstB.d;

  /* Signum: '<S42>/Sign4' incorporates:
   *  Product: '<S42>/Divide'
   *  Sum: '<S42>/Subtract3'
   */
  rtb_Gain = rtb_Saturation1_i_idx_0 - Controller_ConstB.d;

  /* Signum: '<S42>/Sign5' incorporates:
   *  Product: '<S42>/Divide'
   */
  if (rtb_Saturation1_i_idx_0 < 0.0F) {
    rtb_Gain_am = -1.0F;
  } else if (rtb_Saturation1_i_idx_0 > 0.0F) {
    rtb_Gain_am = 1.0F;
  } else {
    rtb_Gain_am = rtb_Saturation1_i_idx_0;
  }

  /* Signum: '<S42>/Sign3' */
  if (rtb_Add3 < 0.0F) {
    rtb_Add3 = -1.0F;
  } else {
    if (rtb_Add3 > 0.0F) {
      rtb_Add3 = 1.0F;
    }
  }

  /* Signum: '<S42>/Sign4' */
  if (rtb_Gain < 0.0F) {
    rtb_Gain = -1.0F;
  } else {
    if (rtb_Gain > 0.0F) {
      rtb_Gain = 1.0F;
    }
  }

  /* Signum: '<S42>/Sign6' incorporates:
   *  Product: '<S42>/Divide'
   */
  if (rtb_Saturation1_i_idx_0 < 0.0F) {
    rtb_uv_error_C_mPs_idx_0 = -1.0F;
  } else if (rtb_Saturation1_i_idx_0 > 0.0F) {
    rtb_uv_error_C_mPs_idx_0 = 1.0F;
  } else {
    rtb_uv_error_C_mPs_idx_0 = rtb_Saturation1_i_idx_0;
  }

  /* Update for DiscreteIntegrator: '<S39>/Integrator' incorporates:
   *  Constant: '<S42>/const'
   *  Gain: '<S42>/Gain3'
   *  Product: '<S42>/Divide'
   *  Product: '<S42>/Multiply5'
   *  Product: '<S42>/Multiply6'
   *  Sum: '<S42>/Subtract4'
   *  Sum: '<S42>/Subtract5'
   *  Sum: '<S42>/Subtract6'
   */
  Controller_DW.Integrator_DSTATE[0] += ((rtb_Saturation1_i_idx_0 /
    Controller_ConstB.d - rtb_Gain_am) * Controller_ConstB.Gain4 * ((rtb_Add3 -
    rtb_Gain) * 0.5F) - rtb_uv_error_C_mPs_idx_0 * 58.836F) * 0.002F;

  /* Signum: '<S42>/Sign3' incorporates:
   *  Sum: '<S42>/Add6'
   */
  rtb_Add3 = rtb_Saturation_nc + Controller_ConstB.d;

  /* Signum: '<S42>/Sign4' incorporates:
   *  Sum: '<S42>/Subtract3'
   */
  rtb_Gain = rtb_Saturation_nc - Controller_ConstB.d;

  /* Signum: '<S42>/Sign5' */
  if (rtb_Saturation_nc < 0.0F) {
    rtb_Gain_am = -1.0F;
  } else if (rtb_Saturation_nc > 0.0F) {
    rtb_Gain_am = 1.0F;
  } else {
    rtb_Gain_am = rtb_Saturation_nc;
  }

  /* Signum: '<S42>/Sign3' */
  if (rtb_Add3 < 0.0F) {
    rtb_Add3 = -1.0F;
  } else {
    if (rtb_Add3 > 0.0F) {
      rtb_Add3 = 1.0F;
    }
  }

  /* Signum: '<S42>/Sign4' */
  if (rtb_Gain < 0.0F) {
    rtb_Gain = -1.0F;
  } else {
    if (rtb_Gain > 0.0F) {
      rtb_Gain = 1.0F;
    }
  }

  /* Signum: '<S42>/Sign6' */
  if (rtb_Saturation_nc < 0.0F) {
    rtb_uv_error_C_mPs_idx_0 = -1.0F;
  } else if (rtb_Saturation_nc > 0.0F) {
    rtb_uv_error_C_mPs_idx_0 = 1.0F;
  } else {
    rtb_uv_error_C_mPs_idx_0 = rtb_Saturation_nc;
  }

  /* Update for DiscreteIntegrator: '<S39>/Integrator' incorporates:
   *  Constant: '<S42>/const'
   *  Gain: '<S42>/Gain3'
   *  Product: '<S42>/Divide'
   *  Product: '<S42>/Multiply5'
   *  Product: '<S42>/Multiply6'
   *  Sum: '<S42>/Subtract4'
   *  Sum: '<S42>/Subtract5'
   *  Sum: '<S42>/Subtract6'
   */
  Controller_DW.Integrator_DSTATE[1] += ((rtb_Saturation_nc /
    Controller_ConstB.d - rtb_Gain_am) * Controller_ConstB.Gain4 * ((rtb_Add3 -
    rtb_Gain) * 0.5F) - rtb_uv_error_C_mPs_idx_0 * 58.836F) * 0.002F;

  /* Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S4>/Constant'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_n += CONTROL_EXPORT.period;

  /* Signum: '<S25>/Sign3' */
  if (rtb_Atan_idx_1 < 0.0F) {
    rtb_Atan_idx_1 = -1.0F;
  } else {
    if (rtb_Atan_idx_1 > 0.0F) {
      rtb_Atan_idx_1 = 1.0F;
    }
  }

  /* End of Signum: '<S25>/Sign3' */

  /* Signum: '<S25>/Sign4' */
  if (rtb_Saturation_jz < 0.0F) {
    rtb_Saturation_jz = -1.0F;
  } else {
    if (rtb_Saturation_jz > 0.0F) {
      rtb_Saturation_jz = 1.0F;
    }
  }

  /* End of Signum: '<S25>/Sign4' */

  /* Update for DiscreteIntegrator: '<S24>/Integrator' incorporates:
   *  Constant: '<S25>/const'
   *  Gain: '<S25>/Gain3'
   *  Product: '<S25>/Multiply5'
   *  Product: '<S25>/Multiply6'
   *  Sum: '<S25>/Subtract4'
   *  Sum: '<S25>/Subtract5'
   *  Sum: '<S25>/Subtract6'
   */
  Controller_DW.Integrator_DSTATE_k += ((rtb_Saturation1_i_idx_1 - rtb_Sign5_f) *
    Controller_ConstB.Gain4_o * ((rtb_Atan_idx_1 - rtb_Saturation_jz) * 0.5F) -
    rtb_Atan_idx_0 * 15.707963F) * 0.002F;

  /* Signum: '<S55>/Sign6' incorporates:
   *  Signum: '<S55>/Sign5'
   */
  if (rtb_a_n < 0.0F) {
    rtb_Atan_idx_0 = -1.0F;

    /* Signum: '<S55>/Sign5' */
    rtb_Gain = -1.0F;
  } else if (rtb_a_n > 0.0F) {
    rtb_Atan_idx_0 = 1.0F;

    /* Signum: '<S55>/Sign5' */
    rtb_Gain = 1.0F;
  } else {
    rtb_Atan_idx_0 = rtb_a_n;

    /* Signum: '<S55>/Sign5' */
    rtb_Gain = rtb_a_n;
  }

  /* End of Signum: '<S55>/Sign6' */

  /* Sum: '<S55>/Add6' */
  rtb_Saturation_jz = rtb_a_n + Controller_ConstB.d_n;

  /* Sum: '<S55>/Subtract3' */
  rtb_Atan_idx_1 = rtb_a_n - Controller_ConstB.d_n;

  /* Signum: '<S55>/Sign3' */
  if (rtb_Saturation_jz < 0.0F) {
    rtb_Saturation_jz = -1.0F;
  } else {
    if (rtb_Saturation_jz > 0.0F) {
      rtb_Saturation_jz = 1.0F;
    }
  }

  /* End of Signum: '<S55>/Sign3' */

  /* Signum: '<S55>/Sign4' */
  if (rtb_Atan_idx_1 < 0.0F) {
    rtb_Atan_idx_1 = -1.0F;
  } else {
    if (rtb_Atan_idx_1 > 0.0F) {
      rtb_Atan_idx_1 = 1.0F;
    }
  }

  /* End of Signum: '<S55>/Sign4' */

  /* Update for DiscreteIntegrator: '<S54>/Integrator' incorporates:
   *  Constant: '<S55>/const'
   *  Gain: '<S55>/Gain3'
   *  Product: '<S55>/Divide'
   *  Product: '<S55>/Multiply5'
   *  Product: '<S55>/Multiply6'
   *  Sum: '<S55>/Subtract4'
   *  Sum: '<S55>/Subtract5'
   *  Sum: '<S55>/Subtract6'
   */
  Controller_DW.Integrator_DSTATE_p += ((rtb_a_n / Controller_ConstB.d_n -
    rtb_Gain) * Controller_ConstB.Gain4_k * ((rtb_Saturation_jz - rtb_Atan_idx_1)
    * 0.5F) - rtb_Atan_idx_0 * 78.448F) * 0.002F;
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

  /* InitializeConditions for DiscreteIntegrator: '<S57>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S57>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S59>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S44>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S44>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S46>/Discrete-Time Integrator1' */
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
