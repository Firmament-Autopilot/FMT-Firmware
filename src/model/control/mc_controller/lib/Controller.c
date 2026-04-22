/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.999
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Apr 21 13:30:16 2026
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

/* Exported block signals */
real32_T att_cmd_B_rad[2];             /* '<S86>/Switch' */
real32_T att_est_B_rad[2];             /* '<S89>/Signal Copy' */
real32_T rate_cmd_B_radPs[3];          /* '<S70>/Switch' */
real32_T rate_est_B_radPs[3];          /* '<S74>/Signal Copy' */
real32_T w_cmd_C_mPs;                  /* '<S119>/Integrator1' */
real32_T w_est_C_mPs;                  /* '<S116>/Signal Copy1' */

/* Exported block parameters */
struct_oqmoiGpNYV6eEvDoym9FPF CONTROL_PARAM = {
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
  0.0F,
  0.0F,
  -0.1F,
  0.1F,
  -0.1F,
  0.1F,
  1.57079637F,
  3.14159274F,
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
                                        *   '<S95>/Saturation'
                                        *   '<S69>/Saturation'
                                        *   '<S69>/Saturation1'
                                        *   '<S105>/kd'
                                        *   '<S105>/Saturation'
                                        *   '<S106>/ki'
                                        *   '<S106>/Discrete-Time Integrator'
                                        *   '<S107>/kp'
                                        *   '<S122>/kd'
                                        *   '<S122>/Saturation'
                                        *   '<S123>/Constant'
                                        *   '<S123>/ki'
                                        *   '<S123>/Discrete-Time Integrator'
                                        *   '<S124>/kp'
                                        *   '<S72>/Gain'
                                        *   '<S72>/Gain1'
                                        *   '<S88>/Constant1'
                                        *   '<S88>/Constant2'
                                        *   '<S77>/gain1'
                                        *   '<S77>/gain2'
                                        *   '<S77>/gain3'
                                        *   '<S77>/Saturation'
                                        *   '<S78>/gain1'
                                        *   '<S78>/gain2'
                                        *   '<S78>/gain3'
                                        *   '<S78>/Discrete-Time Integrator'
                                        *   '<S79>/gain1'
                                        *   '<S79>/gain2'
                                        *   '<S79>/gain3'
                                        */

struct_ny3PY9hontv4J5WqwlFzJB CONTROL_EXPORT = {
  2U,

  { 77, 67, 32, 67, 111, 110, 116, 114, 111, 108, 108, 101, 114, 32, 118, 49, 46,
    48, 46, 48, 0 }
} ;                                    /* Variable: CONTROL_EXPORT
                                        * Referenced by: '<S3>/Constant'
                                        */

/* Block signals (default storage) */
B_Controller_T Controller_B;

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
  real32_T rtb_Sum[3];
  uint16_T rtb_VariantMergeForOutportactua[16];
  real32_T rtb_Add3;
  real32_T rtb_DiscreteTimeIntegrator1_j;
  real32_T rtb_DiscreteTimeIntegrator_b[3];
  real32_T rtb_VectorConcatenate[9];
  int32_T i;
  real32_T rtb_Sign1_f_idx_0;
  real32_T rtb_att_error_B_rad_idx_0;
  real32_T rtb_DiscreteTimeIntegrator_i_id;
  real32_T rtb_att_error_B_rad_idx_1;
  real32_T rtb_DiscreteTimeIntegrator_i__0;
  real32_T rtb_Switch_l_idx_0;
  real32_T rtb_Gain_idx_0;
  real32_T rtb_Switch_l_idx_0_0;
  real32_T rtb_Switch_l_idx_0_1;

  /* Outputs for Enabled SubSystem: '<S5>/Velocity_Controller' incorporates:
   *  EnablePort: '<S65>/Enable'
   */
  /* RelationalOperator: '<S64>/Compare' incorporates:
   *  Constant: '<S64>/Constant'
   *  DiscreteIntegrator: '<S101>/Integrator1'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S105>/Multiply'
   *  Sum: '<S104>/Subtract1'
   *  Sum: '<S96>/Sum'
   */
  if (Controller_U.FMS_Out.ctrl_mode >= 5) {
    if (!Controller_DW.Velocity_Controller_MODE) {
      /* InitializeConditions for DiscreteIntegrator: '<S101>/Integrator1' */
      Controller_DW.Integrator1_IC_LOADING_e = 1U;

      /* InitializeConditions for DiscreteIntegrator: '<S101>/Integrator' */
      Controller_DW.Integrator_DSTATE_o[0] = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S106>/Discrete-Time Integrator' */
      Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[0] =
        Controller_ConstB.Constant_g;
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[0] >=
          CONTROL_PARAM.VEL_XY_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[0] =
          CONTROL_PARAM.VEL_XY_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[0] <=
            CONTROL_PARAM.VEL_XY_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[0] =
            CONTROL_PARAM.VEL_XY_I_MIN;
        }
      }

      /* InitializeConditions for DiscreteIntegrator: '<S101>/Integrator' */
      Controller_DW.Integrator_DSTATE_o[1] = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S106>/Discrete-Time Integrator' */
      Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[1] =
        Controller_ConstB.Constant_g;
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[1] >=
          CONTROL_PARAM.VEL_XY_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[1] =
          CONTROL_PARAM.VEL_XY_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[1] <=
            CONTROL_PARAM.VEL_XY_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[1] =
            CONTROL_PARAM.VEL_XY_I_MIN;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_PrevRe_e = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S108>/Discrete-Time Integrator1' */
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_b = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevR_a = 0;
      Controller_DW.Velocity_Controller_MODE = true;
    }

    /* Trigonometry: '<S103>/Trigonometric Function1' incorporates:
     *  Gain: '<S102>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S103>/Trigonometric Function3'
     */
    rtb_Add3 = arm_cos_f32(-Controller_U.INS_Out.psi);
    rtb_VectorConcatenate[0] = rtb_Add3;

    /* Trigonometry: '<S103>/Trigonometric Function' incorporates:
     *  Gain: '<S102>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S103>/Trigonometric Function2'
     */
    rtb_Gain_idx_0 = arm_sin_f32(-Controller_U.INS_Out.psi);
    rtb_VectorConcatenate[1] = rtb_Gain_idx_0;

    /* SignalConversion: '<S103>/ConcatBufferAtVector Concatenate1In3' incorporates:
     *  Constant: '<S103>/Constant3'
     */
    rtb_VectorConcatenate[2] = 0.0F;

    /* Gain: '<S103>/Gain' */
    rtb_VectorConcatenate[3] = -rtb_Gain_idx_0;

    /* Trigonometry: '<S103>/Trigonometric Function3' */
    rtb_VectorConcatenate[4] = rtb_Add3;

    /* SignalConversion: '<S103>/ConcatBufferAtVector Concatenate2In3' incorporates:
     *  Constant: '<S103>/Constant4'
     */
    rtb_VectorConcatenate[5] = 0.0F;

    /* SignalConversion: '<S103>/ConcatBufferAtVector ConcatenateIn3' */
    rtb_VectorConcatenate[6] = Controller_ConstB.VectorConcatenate3[0];
    rtb_VectorConcatenate[7] = Controller_ConstB.VectorConcatenate3[1];
    rtb_VectorConcatenate[8] = Controller_ConstB.VectorConcatenate3[2];

    /* Product: '<S99>/Multiply' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  SignalConversion: '<S99>/TmpSignal ConversionAtMultiplyInport2'
     */
    for (i = 0; i < 3; i++) {
      rtb_DiscreteTimeIntegrator_b[i] = rtb_VectorConcatenate[i + 3] *
        Controller_U.INS_Out.ve + rtb_VectorConcatenate[i] *
        Controller_U.INS_Out.vn;
    }

    /* End of Product: '<S99>/Multiply' */

    /* DiscreteIntegrator: '<S101>/Integrator1' */
    if (Controller_DW.Integrator1_IC_LOADING_e != 0) {
      /* Switch: '<S96>/Switch' incorporates:
       *  Constant: '<S100>/Constant'
       *  Inport: '<Root>/INS_Out'
       *  RelationalOperator: '<S100>/Compare'
       *  S-Function (sfix_bitop): '<S96>/vel_valid'
       */
      if ((Controller_U.INS_Out.flag & 16U) == 0U) {
        Controller_DW.Integrator1_DSTATE_g[0] = Controller_U.FMS_Out.u_cmd;
        Controller_DW.Integrator1_DSTATE_g[1] = Controller_U.FMS_Out.v_cmd;
      } else {
        Controller_DW.Integrator1_DSTATE_g[0] = rtb_DiscreteTimeIntegrator_b[0];
        Controller_DW.Integrator1_DSTATE_g[1] = rtb_DiscreteTimeIntegrator_b[1];
      }

      /* End of Switch: '<S96>/Switch' */
    }

    /* Product: '<S104>/Multiply1' incorporates:
     *  Constant: '<S104>/const1'
     *  DiscreteIntegrator: '<S101>/Integrator'
     */
    rtb_att_error_B_rad_idx_0 = Controller_DW.Integrator_DSTATE_o[0] * 0.05F;
    rtb_att_error_B_rad_idx_1 = Controller_DW.Integrator_DSTATE_o[1] * 0.05F;

    /* Sum: '<S104>/Add' incorporates:
     *  DiscreteIntegrator: '<S101>/Integrator1'
     *  Sum: '<S101>/Subtract'
     */
    rtb_DiscreteTimeIntegrator_i_id = (Controller_DW.Integrator1_DSTATE_g[0] -
      Controller_U.FMS_Out.u_cmd) + rtb_att_error_B_rad_idx_0;
    rtb_DiscreteTimeIntegrator_i__0 = (Controller_DW.Integrator1_DSTATE_g[1] -
      Controller_U.FMS_Out.v_cmd) + rtb_att_error_B_rad_idx_1;

    /* Signum: '<S104>/Sign' */
    if (rtb_DiscreteTimeIntegrator_i_id < 0.0F) {
      rtb_Add3 = -1.0F;
    } else if (rtb_DiscreteTimeIntegrator_i_id > 0.0F) {
      rtb_Add3 = 1.0F;
    } else {
      rtb_Add3 = rtb_DiscreteTimeIntegrator_i_id;
    }

    /* Sum: '<S104>/Add2' incorporates:
     *  Abs: '<S104>/Abs'
     *  Gain: '<S104>/Gain'
     *  Gain: '<S104>/Gain1'
     *  Product: '<S104>/Multiply2'
     *  Product: '<S104>/Multiply3'
     *  Signum: '<S104>/Sign'
     *  Sqrt: '<S104>/Sqrt'
     *  Sum: '<S104>/Add1'
     *  Sum: '<S104>/Subtract'
     */
    rtb_DiscreteTimeIntegrator1_j = (sqrtf((8.0F * fabsf
      (rtb_DiscreteTimeIntegrator_i_id) + Controller_ConstB.d_e) *
      Controller_ConstB.d_e) - Controller_ConstB.d_e) * 0.5F * rtb_Add3 +
      rtb_att_error_B_rad_idx_0;

    /* Sum: '<S104>/Add3' incorporates:
     *  Signum: '<S104>/Sign'
     */
    rtb_Add3 = rtb_DiscreteTimeIntegrator_i_id + Controller_ConstB.d_e;

    /* Sum: '<S104>/Subtract1' incorporates:
     *  Signum: '<S104>/Sign'
     */
    rtb_Gain_idx_0 = rtb_DiscreteTimeIntegrator_i_id - Controller_ConstB.d_e;

    /* Signum: '<S104>/Sign1' */
    if (rtb_Add3 < 0.0F) {
      rtb_Add3 = -1.0F;
    } else {
      if (rtb_Add3 > 0.0F) {
        rtb_Add3 = 1.0F;
      }
    }

    /* Signum: '<S104>/Sign2' */
    if (rtb_Gain_idx_0 < 0.0F) {
      rtb_Gain_idx_0 = -1.0F;
    } else {
      if (rtb_Gain_idx_0 > 0.0F) {
        rtb_Gain_idx_0 = 1.0F;
      }
    }

    /* Sum: '<S104>/Add2' incorporates:
     *  Gain: '<S104>/Gain2'
     *  Product: '<S104>/Multiply4'
     *  Signum: '<S104>/Sign'
     *  Sum: '<S104>/Add4'
     *  Sum: '<S104>/Add5'
     *  Sum: '<S104>/Subtract2'
     */
    rtb_Switch_l_idx_0 = ((rtb_DiscreteTimeIntegrator_i_id -
      rtb_DiscreteTimeIntegrator1_j) + rtb_att_error_B_rad_idx_0) * ((rtb_Add3 -
      rtb_Gain_idx_0) * 0.5F) + rtb_DiscreteTimeIntegrator1_j;
    rtb_DiscreteTimeIntegrator_i_id = Controller_DW.Integrator1_DSTATE_g[0] -
      rtb_DiscreteTimeIntegrator_b[0];

    /* Signum: '<S104>/Sign' incorporates:
     *  DiscreteIntegrator: '<S101>/Integrator1'
     *  Sum: '<S104>/Subtract1'
     *  Sum: '<S96>/Sum'
     */
    if (rtb_DiscreteTimeIntegrator_i__0 < 0.0F) {
      rtb_Add3 = -1.0F;
    } else if (rtb_DiscreteTimeIntegrator_i__0 > 0.0F) {
      rtb_Add3 = 1.0F;
    } else {
      rtb_Add3 = rtb_DiscreteTimeIntegrator_i__0;
    }

    /* Sum: '<S104>/Add2' incorporates:
     *  Abs: '<S104>/Abs'
     *  Gain: '<S104>/Gain'
     *  Gain: '<S104>/Gain1'
     *  Product: '<S104>/Multiply2'
     *  Product: '<S104>/Multiply3'
     *  Signum: '<S104>/Sign'
     *  Sqrt: '<S104>/Sqrt'
     *  Sum: '<S104>/Add1'
     *  Sum: '<S104>/Subtract'
     */
    rtb_DiscreteTimeIntegrator1_j = (sqrtf((8.0F * fabsf
      (rtb_DiscreteTimeIntegrator_i__0) + Controller_ConstB.d_e) *
      Controller_ConstB.d_e) - Controller_ConstB.d_e) * 0.5F * rtb_Add3 +
      rtb_att_error_B_rad_idx_1;

    /* Sum: '<S104>/Add3' incorporates:
     *  Signum: '<S104>/Sign'
     */
    rtb_Add3 = rtb_DiscreteTimeIntegrator_i__0 + Controller_ConstB.d_e;

    /* Sum: '<S104>/Subtract1' incorporates:
     *  Signum: '<S104>/Sign'
     */
    rtb_Gain_idx_0 = rtb_DiscreteTimeIntegrator_i__0 - Controller_ConstB.d_e;

    /* Signum: '<S104>/Sign1' */
    if (rtb_Add3 < 0.0F) {
      rtb_Add3 = -1.0F;
    } else {
      if (rtb_Add3 > 0.0F) {
        rtb_Add3 = 1.0F;
      }
    }

    /* Signum: '<S104>/Sign2' */
    if (rtb_Gain_idx_0 < 0.0F) {
      rtb_Gain_idx_0 = -1.0F;
    } else {
      if (rtb_Gain_idx_0 > 0.0F) {
        rtb_Gain_idx_0 = 1.0F;
      }
    }

    /* Sum: '<S104>/Add5' incorporates:
     *  Gain: '<S104>/Gain2'
     *  Product: '<S104>/Multiply4'
     *  Signum: '<S104>/Sign'
     *  Sum: '<S104>/Add2'
     *  Sum: '<S104>/Add4'
     *  Sum: '<S104>/Subtract2'
     */
    rtb_DiscreteTimeIntegrator1_j += ((rtb_DiscreteTimeIntegrator_i__0 -
      rtb_DiscreteTimeIntegrator1_j) + rtb_att_error_B_rad_idx_1) * ((rtb_Add3 -
      rtb_Gain_idx_0) * 0.5F);

    /* Sum: '<S96>/Sum' incorporates:
     *  DiscreteIntegrator: '<S101>/Integrator1'
     */
    rtb_Gain_idx_0 = Controller_DW.Integrator1_DSTATE_g[1] -
      rtb_DiscreteTimeIntegrator_b[1];

    /* DiscreteIntegrator: '<S106>/Discrete-Time Integrator' */
    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator_PrevRe_e != 0)) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[0] =
        Controller_ConstB.Constant_g;
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[0] >=
          CONTROL_PARAM.VEL_XY_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[0] =
          CONTROL_PARAM.VEL_XY_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[0] <=
            CONTROL_PARAM.VEL_XY_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[0] =
            CONTROL_PARAM.VEL_XY_I_MIN;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[1] =
        Controller_ConstB.Constant_g;
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[1] >=
          CONTROL_PARAM.VEL_XY_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[1] =
          CONTROL_PARAM.VEL_XY_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[1] <=
            CONTROL_PARAM.VEL_XY_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[1] =
            CONTROL_PARAM.VEL_XY_I_MIN;
        }
      }
    }

    if (Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[0] >=
        CONTROL_PARAM.VEL_XY_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[0] =
        CONTROL_PARAM.VEL_XY_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[0] <=
          CONTROL_PARAM.VEL_XY_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[0] =
          CONTROL_PARAM.VEL_XY_I_MIN;
      }
    }

    if (Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[1] >=
        CONTROL_PARAM.VEL_XY_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[1] =
        CONTROL_PARAM.VEL_XY_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[1] <=
          CONTROL_PARAM.VEL_XY_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[1] =
          CONTROL_PARAM.VEL_XY_I_MIN;
      }
    }

    /* DiscreteIntegrator: '<S108>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_b != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[0] =
        rtb_DiscreteTimeIntegrator_i_id;
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[1] = rtb_Gain_idx_0;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_a != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[0] =
        rtb_DiscreteTimeIntegrator_i_id;
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[1] = rtb_Gain_idx_0;
    }

    /* Gain: '<S108>/Gain' incorporates:
     *  DiscreteIntegrator: '<S108>/Discrete-Time Integrator1'
     *  Sum: '<S108>/Sum5'
     */
    rtb_Sign1_f_idx_0 = (rtb_DiscreteTimeIntegrator_i_id -
                         Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[0]) *
      62.831852F;
    rtb_DiscreteTimeIntegrator_i__0 = (rtb_Gain_idx_0 -
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[1]) * 62.831852F;

    /* Switch: '<S108>/Switch' incorporates:
     *  Gain: '<S108>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_att_error_B_rad_idx_0 = 0.0F;
      rtb_att_error_B_rad_idx_1 = 0.0F;
    } else {
      rtb_att_error_B_rad_idx_0 = rtb_Sign1_f_idx_0;
      rtb_att_error_B_rad_idx_1 = rtb_DiscreteTimeIntegrator_i__0;
    }

    /* End of Switch: '<S108>/Switch' */

    /* Product: '<S105>/Multiply' incorporates:
     *  Constant: '<S105>/kd'
     */
    rtb_Add3 = CONTROL_PARAM.VEL_XY_D * rtb_att_error_B_rad_idx_0;

    /* Saturate: '<S105>/Saturation' */
    if (rtb_Add3 > CONTROL_PARAM.VEL_XY_D_MAX) {
      rtb_Add3 = CONTROL_PARAM.VEL_XY_D_MAX;
    } else {
      if (rtb_Add3 < CONTROL_PARAM.VEL_XY_D_MIN) {
        rtb_Add3 = CONTROL_PARAM.VEL_XY_D_MIN;
      }
    }

    rtb_att_error_B_rad_idx_0 = rtb_Add3;

    /* Product: '<S105>/Multiply' incorporates:
     *  Constant: '<S105>/kd'
     */
    rtb_Add3 = CONTROL_PARAM.VEL_XY_D * rtb_att_error_B_rad_idx_1;

    /* Saturate: '<S105>/Saturation' */
    if (rtb_Add3 > CONTROL_PARAM.VEL_XY_D_MAX) {
      rtb_Add3 = CONTROL_PARAM.VEL_XY_D_MAX;
    } else {
      if (rtb_Add3 < CONTROL_PARAM.VEL_XY_D_MIN) {
        rtb_Add3 = CONTROL_PARAM.VEL_XY_D_MIN;
      }
    }

    /* Switch: '<S98>/Switch' incorporates:
     *  Constant: '<S107>/kp'
     *  Constant: '<S109>/Constant'
     *  Constant: '<S111>/Constant'
     *  Constant: '<S112>/Constant'
     *  DiscreteIntegrator: '<S106>/Discrete-Time Integrator'
     *  Product: '<S107>/Multiply'
     *  Product: '<S110>/Multiply2'
     *  Product: '<S110>/Multiply3'
     *  RelationalOperator: '<S109>/Compare'
     *  RelationalOperator: '<S111>/Compare'
     *  RelationalOperator: '<S112>/Compare'
     *  S-Function (sfix_bitop): '<S110>/cmd_ax valid'
     *  S-Function (sfix_bitop): '<S110>/cmd_ay valid'
     *  S-Function (sfix_bitop): '<S110>/cmd_u valid'
     *  S-Function (sfix_bitop): '<S110>/cmd_v valid'
     *  Sum: '<S110>/Sum1'
     *  Sum: '<S97>/Add'
     */
    if (Controller_U.FMS_Out.ctrl_mode == 6) {
      rtb_att_error_B_rad_idx_0 = ((Controller_U.FMS_Out.cmd_mask & 64) > 0 ?
        (CONTROL_PARAM.VEL_XY_P * rtb_DiscreteTimeIntegrator_i_id +
         Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[0]) +
        rtb_att_error_B_rad_idx_0 : 0.0F) + ((Controller_U.FMS_Out.cmd_mask &
        512) > 0 ? Controller_U.FMS_Out.ax_cmd : 0.0F);
      rtb_att_error_B_rad_idx_1 = ((Controller_U.FMS_Out.cmd_mask & 128) > 0 ?
        (CONTROL_PARAM.VEL_XY_P * rtb_Gain_idx_0 +
         Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[1]) + rtb_Add3 : 0.0F) +
        ((Controller_U.FMS_Out.cmd_mask & 1024) > 0 ?
         Controller_U.FMS_Out.ay_cmd : 0.0F);
    } else {
      rtb_att_error_B_rad_idx_0 += CONTROL_PARAM.VEL_XY_P *
        rtb_DiscreteTimeIntegrator_i_id +
        Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[0];
      rtb_att_error_B_rad_idx_1 = (CONTROL_PARAM.VEL_XY_P * rtb_Gain_idx_0 +
        Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[1]) + rtb_Add3;
    }

    /* End of Switch: '<S98>/Switch' */

    /* Update for DiscreteIntegrator: '<S101>/Integrator1' */
    Controller_DW.Integrator1_IC_LOADING_e = 0U;

    /* Update for DiscreteIntegrator: '<S106>/Discrete-Time Integrator' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.DiscreteTimeIntegrator_PrevRe_e = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S108>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_b = 0U;

    /* Trigonometry: '<S95>/Atan' incorporates:
     *  Constant: '<S95>/g'
     *  Gain: '<S95>/gain'
     *  Product: '<S95>/Divide'
     */
    rtb_Add3 = atanf(1.1F * rtb_att_error_B_rad_idx_1 / 9.8055F);

    /* Saturate: '<S95>/Saturation' */
    if (rtb_Add3 > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      Controller_B.Saturation_c[0] = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    } else if (rtb_Add3 < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      Controller_B.Saturation_c[0] = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    } else {
      Controller_B.Saturation_c[0] = rtb_Add3;
    }

    /* Update for DiscreteIntegrator: '<S101>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S101>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_g[0] += 0.002F *
      Controller_DW.Integrator_DSTATE_o[0];

    /* Signum: '<S104>/Sign3' incorporates:
     *  Product: '<S104>/Divide'
     *  Sum: '<S104>/Add6'
     */
    rtb_Add3 = rtb_Switch_l_idx_0 + Controller_ConstB.d_e;

    /* Signum: '<S104>/Sign4' incorporates:
     *  Product: '<S104>/Divide'
     *  Sum: '<S104>/Subtract3'
     */
    rtb_att_error_B_rad_idx_1 = rtb_Switch_l_idx_0 - Controller_ConstB.d_e;

    /* Signum: '<S104>/Sign5' incorporates:
     *  Product: '<S104>/Divide'
     */
    if (rtb_Switch_l_idx_0 < 0.0F) {
      rtb_Switch_l_idx_0_0 = -1.0F;
    } else if (rtb_Switch_l_idx_0 > 0.0F) {
      rtb_Switch_l_idx_0_0 = 1.0F;
    } else {
      rtb_Switch_l_idx_0_0 = rtb_Switch_l_idx_0;
    }

    /* Signum: '<S104>/Sign3' */
    if (rtb_Add3 < 0.0F) {
      rtb_Add3 = -1.0F;
    } else {
      if (rtb_Add3 > 0.0F) {
        rtb_Add3 = 1.0F;
      }
    }

    /* Signum: '<S104>/Sign4' */
    if (rtb_att_error_B_rad_idx_1 < 0.0F) {
      rtb_att_error_B_rad_idx_1 = -1.0F;
    } else {
      if (rtb_att_error_B_rad_idx_1 > 0.0F) {
        rtb_att_error_B_rad_idx_1 = 1.0F;
      }
    }

    /* Signum: '<S104>/Sign6' incorporates:
     *  Product: '<S104>/Divide'
     */
    if (rtb_Switch_l_idx_0 < 0.0F) {
      rtb_Switch_l_idx_0_1 = -1.0F;
    } else if (rtb_Switch_l_idx_0 > 0.0F) {
      rtb_Switch_l_idx_0_1 = 1.0F;
    } else {
      rtb_Switch_l_idx_0_1 = rtb_Switch_l_idx_0;
    }

    /* Update for DiscreteIntegrator: '<S101>/Integrator' incorporates:
     *  Constant: '<S104>/const'
     *  Gain: '<S104>/Gain3'
     *  Product: '<S104>/Divide'
     *  Product: '<S104>/Multiply5'
     *  Product: '<S104>/Multiply6'
     *  Sum: '<S104>/Subtract4'
     *  Sum: '<S104>/Subtract5'
     *  Sum: '<S104>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE_o[0] += ((rtb_Switch_l_idx_0 /
      Controller_ConstB.d_e - rtb_Switch_l_idx_0_0) * Controller_ConstB.Gain4_d *
      ((rtb_Add3 - rtb_att_error_B_rad_idx_1) * 0.5F) - rtb_Switch_l_idx_0_1 *
      58.836F) * 0.002F;

    /* Update for DiscreteIntegrator: '<S106>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S106>/ki'
     *  Product: '<S106>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[0] += CONTROL_PARAM.VEL_XY_I *
      rtb_DiscreteTimeIntegrator_i_id * 0.002F;
    if (Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[0] >=
        CONTROL_PARAM.VEL_XY_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[0] =
        CONTROL_PARAM.VEL_XY_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[0] <=
          CONTROL_PARAM.VEL_XY_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[0] =
          CONTROL_PARAM.VEL_XY_I_MIN;
      }
    }

    /* Update for DiscreteIntegrator: '<S108>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[0] += 0.002F *
      rtb_Sign1_f_idx_0;

    /* Trigonometry: '<S95>/Atan' incorporates:
     *  Constant: '<S95>/g'
     *  Gain: '<S95>/Gain1'
     *  Gain: '<S95>/gain'
     *  Product: '<S95>/Divide'
     */
    rtb_Add3 = atanf(1.1F * -rtb_att_error_B_rad_idx_0 / 9.8055F);

    /* Saturate: '<S95>/Saturation' */
    if (rtb_Add3 > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      Controller_B.Saturation_c[1] = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    } else if (rtb_Add3 < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      Controller_B.Saturation_c[1] = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    } else {
      Controller_B.Saturation_c[1] = rtb_Add3;
    }

    /* Update for DiscreteIntegrator: '<S101>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S101>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_g[1] += 0.002F *
      Controller_DW.Integrator_DSTATE_o[1];

    /* Signum: '<S104>/Sign3' incorporates:
     *  Sum: '<S104>/Add6'
     */
    rtb_Add3 = rtb_DiscreteTimeIntegrator1_j + Controller_ConstB.d_e;

    /* Signum: '<S104>/Sign4' incorporates:
     *  Sum: '<S104>/Subtract3'
     */
    rtb_att_error_B_rad_idx_1 = rtb_DiscreteTimeIntegrator1_j -
      Controller_ConstB.d_e;

    /* Signum: '<S104>/Sign5' */
    if (rtb_DiscreteTimeIntegrator1_j < 0.0F) {
      rtb_DiscreteTimeIntegrator_i_id = -1.0F;
    } else if (rtb_DiscreteTimeIntegrator1_j > 0.0F) {
      rtb_DiscreteTimeIntegrator_i_id = 1.0F;
    } else {
      rtb_DiscreteTimeIntegrator_i_id = rtb_DiscreteTimeIntegrator1_j;
    }

    /* Signum: '<S104>/Sign3' */
    if (rtb_Add3 < 0.0F) {
      rtb_Add3 = -1.0F;
    } else {
      if (rtb_Add3 > 0.0F) {
        rtb_Add3 = 1.0F;
      }
    }

    /* Signum: '<S104>/Sign4' */
    if (rtb_att_error_B_rad_idx_1 < 0.0F) {
      rtb_att_error_B_rad_idx_1 = -1.0F;
    } else {
      if (rtb_att_error_B_rad_idx_1 > 0.0F) {
        rtb_att_error_B_rad_idx_1 = 1.0F;
      }
    }

    /* Signum: '<S104>/Sign6' */
    if (rtb_DiscreteTimeIntegrator1_j < 0.0F) {
      rtb_att_error_B_rad_idx_0 = -1.0F;
    } else if (rtb_DiscreteTimeIntegrator1_j > 0.0F) {
      rtb_att_error_B_rad_idx_0 = 1.0F;
    } else {
      rtb_att_error_B_rad_idx_0 = rtb_DiscreteTimeIntegrator1_j;
    }

    /* Update for DiscreteIntegrator: '<S101>/Integrator' incorporates:
     *  Constant: '<S104>/const'
     *  Gain: '<S104>/Gain3'
     *  Product: '<S104>/Divide'
     *  Product: '<S104>/Multiply5'
     *  Product: '<S104>/Multiply6'
     *  Sum: '<S104>/Subtract4'
     *  Sum: '<S104>/Subtract5'
     *  Sum: '<S104>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE_o[1] += ((rtb_DiscreteTimeIntegrator1_j /
      Controller_ConstB.d_e - rtb_DiscreteTimeIntegrator_i_id) *
      Controller_ConstB.Gain4_d * ((rtb_Add3 - rtb_att_error_B_rad_idx_1) * 0.5F)
      - rtb_att_error_B_rad_idx_0 * 58.836F) * 0.002F;

    /* Update for DiscreteIntegrator: '<S106>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S106>/ki'
     *  Product: '<S106>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[1] += CONTROL_PARAM.VEL_XY_I *
      rtb_Gain_idx_0 * 0.002F;
    if (Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[1] >=
        CONTROL_PARAM.VEL_XY_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[1] =
        CONTROL_PARAM.VEL_XY_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[1] <=
          CONTROL_PARAM.VEL_XY_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[1] =
          CONTROL_PARAM.VEL_XY_I_MIN;
      }
    }

    /* Update for DiscreteIntegrator: '<S108>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[1] += 0.002F *
      rtb_DiscreteTimeIntegrator_i__0;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_a = (int8_T)
      (Controller_U.FMS_Out.reset > 0);
  } else {
    if (Controller_DW.Velocity_Controller_MODE) {
      Controller_DW.Velocity_Controller_MODE = false;
    }
  }

  /* End of RelationalOperator: '<S64>/Compare' */
  /* End of Outputs for SubSystem: '<S5>/Velocity_Controller' */

  /* Switch: '<S86>/Switch' incorporates:
   *  Constant: '<S93>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  Logic: '<S86>/Logical Operator'
   *  RelationalOperator: '<S92>/Compare'
   *  RelationalOperator: '<S93>/Compare'
   *  Switch: '<S86>/Switch1'
   */
  if ((Controller_U.FMS_Out.ctrl_mode == 3) || (Controller_U.FMS_Out.ctrl_mode ==
       4)) {
    att_cmd_B_rad[0] = Controller_U.FMS_Out.phi_cmd;
    att_cmd_B_rad[1] = Controller_U.FMS_Out.theta_cmd;
  } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
    /* Switch: '<S94>/Switch' incorporates:
     *  S-Function (sfix_bitop): '<S94>/cmd_phi valid'
     *  S-Function (sfix_bitop): '<S94>/cmd_theta valid'
     *  Switch: '<S86>/Switch1'
     */
    if ((Controller_U.FMS_Out.cmd_mask & 8) > 0) {
      att_cmd_B_rad[0] = Controller_U.FMS_Out.phi_cmd;
    } else {
      att_cmd_B_rad[0] = Controller_B.Saturation_c[0];
    }

    if ((Controller_U.FMS_Out.cmd_mask & 16) > 0) {
      att_cmd_B_rad[1] = Controller_U.FMS_Out.theta_cmd;
    } else {
      att_cmd_B_rad[1] = Controller_B.Saturation_c[1];
    }

    /* End of Switch: '<S94>/Switch' */
  } else {
    /* Switch: '<S86>/Switch1' */
    att_cmd_B_rad[0] = Controller_B.Saturation_c[0];
    att_cmd_B_rad[1] = Controller_B.Saturation_c[1];
  }

  /* End of Switch: '<S86>/Switch' */

  /* SignalConversion: '<S89>/Signal Copy' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  att_est_B_rad[0] = Controller_U.INS_Out.phi;
  att_est_B_rad[1] = Controller_U.INS_Out.theta;

  /* Sum: '<S87>/Sum' */
  rtb_Add3 = att_cmd_B_rad[0] - att_est_B_rad[0];

  /* Product: '<S90>/Divide1' incorporates:
   *  Abs: '<S90>/Abs'
   *  Constant: '<S90>/const2'
   */
  rtb_Gain_idx_0 = fabsf(rtb_Add3) / 0.002F;

  /* Product: '<S90>/Divide' incorporates:
   *  Constant: '<S88>/Constant1'
   *  Constant: '<S90>/const1'
   *  Math: '<S90>/Square'
   *  SignalConversion: '<S90>/TmpSignal ConversionAtSquareInport1'
   */
  rtb_att_error_B_rad_idx_1 = 9.5993F / (CONTROL_PARAM.ROLL_P *
    CONTROL_PARAM.ROLL_P);

  /* Signum: '<S90>/Sign' */
  if (rtb_Add3 < 0.0F) {
    rtb_DiscreteTimeIntegrator1_j = -1.0F;
  } else if (rtb_Add3 > 0.0F) {
    rtb_DiscreteTimeIntegrator1_j = 1.0F;
  } else {
    rtb_DiscreteTimeIntegrator1_j = rtb_Add3;
  }

  /* Switch: '<S90>/Switch' incorporates:
   *  Constant: '<S88>/Constant1'
   *  Gain: '<S90>/Gain1'
   *  Gain: '<S90>/Gain2'
   *  Logic: '<S90>/Logical Operator'
   *  Product: '<S90>/Multiply'
   *  Product: '<S90>/Multiply1'
   *  Product: '<S90>/Multiply2'
   *  Product: '<S90>/Multiply3'
   *  RelationalOperator: '<S90>/Relational Operator'
   *  RelationalOperator: '<S90>/Relational Operator2'
   *  SignalConversion: '<S90>/TmpSignal ConversionAtSquareInport1'
   *  Sqrt: '<S90>/Sqrt'
   *  Sum: '<S90>/Subtract'
   */
  if ((rtb_Add3 <= rtb_att_error_B_rad_idx_1) && (rtb_Add3 >=
       -rtb_att_error_B_rad_idx_1)) {
    rtb_DiscreteTimeIntegrator1_j = rtb_Add3 * CONTROL_PARAM.ROLL_P;
  } else {
    rtb_DiscreteTimeIntegrator1_j *= sqrtf((rtb_DiscreteTimeIntegrator1_j *
      rtb_Add3 - 0.5F * rtb_att_error_B_rad_idx_1) * Controller_ConstB.Gain);
  }

  /* Gain: '<S90>/Gain3' */
  rtb_att_error_B_rad_idx_1 = -rtb_Gain_idx_0;

  /* Switch: '<S91>/Switch' incorporates:
   *  Gain: '<S90>/Gain3'
   *  RelationalOperator: '<S91>/UpperRelop'
   */
  if (rtb_DiscreteTimeIntegrator1_j >= -rtb_Gain_idx_0) {
    rtb_att_error_B_rad_idx_1 = rtb_DiscreteTimeIntegrator1_j;
  }

  /* Switch: '<S91>/Switch2' incorporates:
   *  RelationalOperator: '<S91>/LowerRelop1'
   */
  if (rtb_DiscreteTimeIntegrator1_j <= rtb_Gain_idx_0) {
    rtb_Gain_idx_0 = rtb_att_error_B_rad_idx_1;
  }

  /* Saturate: '<S69>/Saturation1' */
  if (rtb_Gain_idx_0 > CONTROL_PARAM.P_Q_CMD_LIM) {
    rtb_Gain_idx_0 = CONTROL_PARAM.P_Q_CMD_LIM;
  } else {
    if (rtb_Gain_idx_0 < -CONTROL_PARAM.P_Q_CMD_LIM) {
      rtb_Gain_idx_0 = -CONTROL_PARAM.P_Q_CMD_LIM;
    }
  }

  /* Product: '<S90>/Divide1' */
  rtb_DiscreteTimeIntegrator_i_id = rtb_Gain_idx_0;

  /* Sum: '<S87>/Sum' */
  rtb_Add3 = att_cmd_B_rad[1] - att_est_B_rad[1];

  /* Product: '<S90>/Divide1' incorporates:
   *  Abs: '<S90>/Abs'
   *  Constant: '<S90>/const2'
   */
  rtb_Gain_idx_0 = fabsf(rtb_Add3) / 0.002F;

  /* Product: '<S90>/Divide' incorporates:
   *  Constant: '<S88>/Constant2'
   *  Constant: '<S90>/const1'
   *  Math: '<S90>/Square'
   *  SignalConversion: '<S90>/TmpSignal ConversionAtSquareInport1'
   */
  rtb_att_error_B_rad_idx_1 = 9.5993F / (CONTROL_PARAM.PITCH_P *
    CONTROL_PARAM.PITCH_P);

  /* Signum: '<S90>/Sign' */
  if (rtb_Add3 < 0.0F) {
    rtb_DiscreteTimeIntegrator1_j = -1.0F;
  } else if (rtb_Add3 > 0.0F) {
    rtb_DiscreteTimeIntegrator1_j = 1.0F;
  } else {
    rtb_DiscreteTimeIntegrator1_j = rtb_Add3;
  }

  /* Switch: '<S90>/Switch' incorporates:
   *  Constant: '<S88>/Constant2'
   *  Gain: '<S90>/Gain1'
   *  Gain: '<S90>/Gain2'
   *  Logic: '<S90>/Logical Operator'
   *  Product: '<S90>/Multiply'
   *  Product: '<S90>/Multiply1'
   *  Product: '<S90>/Multiply2'
   *  Product: '<S90>/Multiply3'
   *  RelationalOperator: '<S90>/Relational Operator'
   *  RelationalOperator: '<S90>/Relational Operator2'
   *  SignalConversion: '<S90>/TmpSignal ConversionAtSquareInport1'
   *  Sqrt: '<S90>/Sqrt'
   *  Sum: '<S90>/Subtract'
   */
  if ((rtb_Add3 <= rtb_att_error_B_rad_idx_1) && (rtb_Add3 >=
       -rtb_att_error_B_rad_idx_1)) {
    rtb_DiscreteTimeIntegrator1_j = rtb_Add3 * CONTROL_PARAM.PITCH_P;
  } else {
    rtb_DiscreteTimeIntegrator1_j *= sqrtf((rtb_DiscreteTimeIntegrator1_j *
      rtb_Add3 - 0.5F * rtb_att_error_B_rad_idx_1) * Controller_ConstB.Gain);
  }

  /* Gain: '<S90>/Gain3' */
  rtb_att_error_B_rad_idx_1 = -rtb_Gain_idx_0;

  /* Switch: '<S91>/Switch' incorporates:
   *  Gain: '<S90>/Gain3'
   *  RelationalOperator: '<S91>/UpperRelop'
   */
  if (rtb_DiscreteTimeIntegrator1_j >= -rtb_Gain_idx_0) {
    rtb_att_error_B_rad_idx_1 = rtb_DiscreteTimeIntegrator1_j;
  }

  /* Switch: '<S91>/Switch2' incorporates:
   *  RelationalOperator: '<S91>/LowerRelop1'
   */
  if (rtb_DiscreteTimeIntegrator1_j <= rtb_Gain_idx_0) {
    rtb_Gain_idx_0 = rtb_att_error_B_rad_idx_1;
  }

  /* Saturate: '<S69>/Saturation1' */
  if (rtb_Gain_idx_0 > CONTROL_PARAM.P_Q_CMD_LIM) {
    rtb_Gain_idx_0 = CONTROL_PARAM.P_Q_CMD_LIM;
  } else {
    if (rtb_Gain_idx_0 < -CONTROL_PARAM.P_Q_CMD_LIM) {
      rtb_Gain_idx_0 = -CONTROL_PARAM.P_Q_CMD_LIM;
    }
  }

  /* Saturate: '<S69>/Saturation' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_U.FMS_Out.psi_rate_cmd > CONTROL_PARAM.R_CMD_LIM) {
    rtb_Add3 = CONTROL_PARAM.R_CMD_LIM;
  } else if (Controller_U.FMS_Out.psi_rate_cmd < -CONTROL_PARAM.R_CMD_LIM) {
    rtb_Add3 = -CONTROL_PARAM.R_CMD_LIM;
  } else {
    rtb_Add3 = Controller_U.FMS_Out.psi_rate_cmd;
  }

  /* End of Saturate: '<S69>/Saturation' */

  /* Trigonometry: '<S81>/Sin' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_att_error_B_rad_idx_0 = arm_sin_f32(Controller_U.INS_Out.phi);

  /* Trigonometry: '<S81>/Cos1' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_DiscreteTimeIntegrator1_j = arm_cos_f32(Controller_U.INS_Out.theta);

  /* Product: '<S81>/Multiply3' */
  rtb_att_error_B_rad_idx_1 = rtb_att_error_B_rad_idx_0 *
    rtb_DiscreteTimeIntegrator1_j * rtb_Add3;

  /* Trigonometry: '<S81>/Cos' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Switch_l_idx_0 = arm_cos_f32(Controller_U.INS_Out.phi);

  /* Product: '<S81>/Multiply1' */
  rtb_DiscreteTimeIntegrator_i__0 = rtb_Switch_l_idx_0 * rtb_Gain_idx_0;

  /* Product: '<S81>/Multiply4' */
  rtb_att_error_B_rad_idx_0 *= rtb_Gain_idx_0;

  /* Switch: '<S70>/Switch' incorporates:
   *  Constant: '<S82>/Constant'
   *  Constant: '<S83>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  RelationalOperator: '<S82>/Compare'
   *  RelationalOperator: '<S83>/Compare'
   *  Switch: '<S70>/Switch1'
   */
  if (Controller_U.FMS_Out.ctrl_mode == 2) {
    rate_cmd_B_radPs[0] = Controller_U.FMS_Out.p_cmd;
    rate_cmd_B_radPs[1] = Controller_U.FMS_Out.q_cmd;
    rate_cmd_B_radPs[2] = Controller_U.FMS_Out.r_cmd;
  } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
    /* Switch: '<S84>/Switch' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S81>/Multiply'
     *  Product: '<S81>/Multiply1'
     *  Product: '<S81>/Multiply5'
     *  S-Function (sfix_bitop): '<S84>/cmd_p valid'
     *  S-Function (sfix_bitop): '<S84>/cmd_q valid'
     *  S-Function (sfix_bitop): '<S84>/cmd_r valid'
     *  Sum: '<S81>/Add'
     *  Sum: '<S81>/Add1'
     *  Sum: '<S81>/Add2'
     *  Switch: '<S70>/Switch1'
     *  Trigonometry: '<S81>/Sin1'
     */
    if ((Controller_U.FMS_Out.cmd_mask & 1) > 0) {
      rate_cmd_B_radPs[0] = Controller_U.FMS_Out.p_cmd;
    } else {
      rate_cmd_B_radPs[0] = rtb_DiscreteTimeIntegrator_i_id - arm_sin_f32
        (Controller_U.INS_Out.theta) * rtb_Add3;
    }

    if ((Controller_U.FMS_Out.cmd_mask & 2) > 0) {
      rate_cmd_B_radPs[1] = Controller_U.FMS_Out.q_cmd;
    } else {
      rate_cmd_B_radPs[1] = rtb_att_error_B_rad_idx_1 +
        rtb_DiscreteTimeIntegrator_i__0;
    }

    if ((Controller_U.FMS_Out.cmd_mask & 4) > 0) {
      rate_cmd_B_radPs[2] = Controller_U.FMS_Out.r_cmd;
    } else {
      rate_cmd_B_radPs[2] = rtb_Switch_l_idx_0 * rtb_DiscreteTimeIntegrator1_j *
        rtb_Add3 - rtb_att_error_B_rad_idx_0;
    }

    /* End of Switch: '<S84>/Switch' */
  } else {
    /* Switch: '<S70>/Switch1' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S81>/Multiply'
     *  Product: '<S81>/Multiply3'
     *  Product: '<S81>/Multiply5'
     *  Sum: '<S81>/Add'
     *  Sum: '<S81>/Add1'
     *  Sum: '<S81>/Add2'
     *  Trigonometry: '<S81>/Sin1'
     */
    rate_cmd_B_radPs[0] = rtb_DiscreteTimeIntegrator_i_id - arm_sin_f32
      (Controller_U.INS_Out.theta) * rtb_Add3;
    rate_cmd_B_radPs[1] = rtb_DiscreteTimeIntegrator_i__0 +
      rtb_att_error_B_rad_idx_1;
    rate_cmd_B_radPs[2] = rtb_Switch_l_idx_0 * rtb_DiscreteTimeIntegrator1_j *
      rtb_Add3 - rtb_att_error_B_rad_idx_0;
  }

  /* End of Switch: '<S70>/Switch' */

  /* SignalConversion: '<S74>/Signal Copy' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rate_est_B_radPs[0] = Controller_U.INS_Out.p;
  rate_est_B_radPs[1] = Controller_U.INS_Out.q;
  rate_est_B_radPs[2] = Controller_U.INS_Out.r;

  /* Sum: '<S71>/Sum' */
  rtb_DiscreteTimeIntegrator_b[0] = rate_cmd_B_radPs[0] - rate_est_B_radPs[0];
  rtb_DiscreteTimeIntegrator_b[1] = rate_cmd_B_radPs[1] - rate_est_B_radPs[1];
  rtb_DiscreteTimeIntegrator_b[2] = rate_cmd_B_radPs[2] - rate_est_B_radPs[2];

  /* DiscreteIntegrator: '<S75>/Discrete-Time Integrator5' */
  if (Controller_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] =
      rtb_DiscreteTimeIntegrator_b[0];
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] =
      rtb_DiscreteTimeIntegrator_b[1];
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] =
      rtb_DiscreteTimeIntegrator_b[2];
  }

  /* DiscreteIntegrator: '<S78>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator_PrevRese != 0)) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = Controller_ConstB.Constant
      [0];
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] >=
        CONTROL_PARAM.RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = CONTROL_PARAM.RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] <=
          CONTROL_PARAM.RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
          CONTROL_PARAM.RATE_I_MIN;
      }
    }

    Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = Controller_ConstB.Constant
      [1];
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] >=
        CONTROL_PARAM.RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = CONTROL_PARAM.RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] <=
          CONTROL_PARAM.RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
          CONTROL_PARAM.RATE_I_MIN;
      }
    }

    Controller_DW.DiscreteTimeIntegrator_DSTATE[2] = Controller_ConstB.Constant
      [2];
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[2] >=
        CONTROL_PARAM.RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[2] = CONTROL_PARAM.RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE[2] <=
          CONTROL_PARAM.RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE[2] =
          CONTROL_PARAM.RATE_I_MIN;
      }
    }
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] >= CONTROL_PARAM.RATE_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = CONTROL_PARAM.RATE_I_MIN;
    }
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] >= CONTROL_PARAM.RATE_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = CONTROL_PARAM.RATE_I_MIN;
    }
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[2] >= CONTROL_PARAM.RATE_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[2] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[2] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[2] = CONTROL_PARAM.RATE_I_MIN;
    }
  }

  /* DiscreteIntegrator: '<S80>/Discrete-Time Integrator1' incorporates:
   *  DiscreteIntegrator: '<S75>/Discrete-Time Integrator5'
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] =
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[0];
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] =
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[1];
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[2] =
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[2];
  }

  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevRes != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] =
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[0];
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] =
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[1];
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[2] =
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[2];
  }

  /* Gain: '<S80>/Gain' incorporates:
   *  DiscreteIntegrator: '<S75>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S80>/Discrete-Time Integrator1'
   *  Sum: '<S80>/Sum5'
   */
  rtb_Gain_idx_0 = (Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] -
                    Controller_DW.DiscreteTimeIntegrator1_DSTATE[0]) *
    188.49556F;
  rtb_DiscreteTimeIntegrator_i_id =
    (Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] -
     Controller_DW.DiscreteTimeIntegrator1_DSTATE[1]) * 188.49556F;
  rtb_DiscreteTimeIntegrator1_j = (Controller_DW.DiscreteTimeIntegrator5_DSTATE
    [2] - Controller_DW.DiscreteTimeIntegrator1_DSTATE[2]) * 188.49556F;

  /* Switch: '<S80>/Switch' incorporates:
   *  Gain: '<S80>/Gain1'
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_U.FMS_Out.reset > 0) {
    rtb_att_error_B_rad_idx_1 = 0.0F;
    rtb_att_error_B_rad_idx_0 = 0.0F;
    rtb_Add3 = 0.0F;
  } else {
    rtb_att_error_B_rad_idx_1 = rtb_Gain_idx_0;
    rtb_att_error_B_rad_idx_0 = rtb_DiscreteTimeIntegrator_i_id;
    rtb_Add3 = rtb_DiscreteTimeIntegrator1_j;
  }

  /* End of Switch: '<S80>/Switch' */

  /* Product: '<S77>/Multiply' incorporates:
   *  Constant: '<S77>/gain1'
   */
  rtb_Switch_l_idx_0 = CONTROL_PARAM.ROLL_RATE_D * rtb_att_error_B_rad_idx_1;

  /* Saturate: '<S77>/Saturation' */
  if (rtb_Switch_l_idx_0 > CONTROL_PARAM.RATE_D_MAX) {
    rtb_Switch_l_idx_0 = CONTROL_PARAM.RATE_D_MAX;
  } else {
    if (rtb_Switch_l_idx_0 < CONTROL_PARAM.RATE_D_MIN) {
      rtb_Switch_l_idx_0 = CONTROL_PARAM.RATE_D_MIN;
    }
  }

  /* Product: '<S77>/Multiply' incorporates:
   *  Constant: '<S77>/gain2'
   */
  rtb_att_error_B_rad_idx_1 = rtb_Switch_l_idx_0;
  rtb_Switch_l_idx_0 = CONTROL_PARAM.PITCH_RATE_D * rtb_att_error_B_rad_idx_0;

  /* Saturate: '<S77>/Saturation' */
  if (rtb_Switch_l_idx_0 > CONTROL_PARAM.RATE_D_MAX) {
    rtb_Switch_l_idx_0 = CONTROL_PARAM.RATE_D_MAX;
  } else {
    if (rtb_Switch_l_idx_0 < CONTROL_PARAM.RATE_D_MIN) {
      rtb_Switch_l_idx_0 = CONTROL_PARAM.RATE_D_MIN;
    }
  }

  /* Product: '<S77>/Multiply' incorporates:
   *  Constant: '<S77>/gain3'
   */
  rtb_att_error_B_rad_idx_0 = rtb_Switch_l_idx_0;
  rtb_Switch_l_idx_0 = CONTROL_PARAM.YAW_RATE_D * rtb_Add3;

  /* Saturate: '<S77>/Saturation' */
  if (rtb_Switch_l_idx_0 > CONTROL_PARAM.RATE_D_MAX) {
    rtb_Switch_l_idx_0 = CONTROL_PARAM.RATE_D_MAX;
  } else {
    if (rtb_Switch_l_idx_0 < CONTROL_PARAM.RATE_D_MIN) {
      rtb_Switch_l_idx_0 = CONTROL_PARAM.RATE_D_MIN;
    }
  }

  /* DeadZone: '<S76>/Dead Zone' */
  if (rate_cmd_B_radPs[0] > 0.1F) {
    rtb_Add3 = rate_cmd_B_radPs[0] - 0.1F;
  } else if (rate_cmd_B_radPs[0] >= -0.1F) {
    rtb_Add3 = 0.0F;
  } else {
    rtb_Add3 = rate_cmd_B_radPs[0] - -0.1F;
  }

  /* Sum: '<S68>/Sum' incorporates:
   *  Constant: '<S79>/gain1'
   *  DiscreteIntegrator: '<S75>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S78>/Discrete-Time Integrator'
   *  Gain: '<S72>/Gain'
   *  Gain: '<S76>/Gain'
   *  Product: '<S79>/Multiply'
   *  Sum: '<S73>/Add'
   */
  rtb_Sum[0] = ((CONTROL_PARAM.ROLL_RATE_P *
                 Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] +
                 Controller_DW.DiscreteTimeIntegrator_DSTATE[0]) +
                rtb_att_error_B_rad_idx_1) + 1.11111116F * rtb_Add3 *
    CONTROL_PARAM.ROLL_RATE_FF;

  /* DeadZone: '<S76>/Dead Zone' */
  if (rate_cmd_B_radPs[1] > 0.1F) {
    rtb_Add3 = rate_cmd_B_radPs[1] - 0.1F;
  } else if (rate_cmd_B_radPs[1] >= -0.1F) {
    rtb_Add3 = 0.0F;
  } else {
    rtb_Add3 = rate_cmd_B_radPs[1] - -0.1F;
  }

  /* Sum: '<S68>/Sum' incorporates:
   *  Constant: '<S79>/gain2'
   *  DiscreteIntegrator: '<S75>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S78>/Discrete-Time Integrator'
   *  Gain: '<S72>/Gain'
   *  Gain: '<S76>/Gain'
   *  Product: '<S79>/Multiply'
   *  Sum: '<S73>/Add'
   */
  rtb_Sum[1] = ((CONTROL_PARAM.PITCH_RATE_P *
                 Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] +
                 Controller_DW.DiscreteTimeIntegrator_DSTATE[1]) +
                rtb_att_error_B_rad_idx_0) + 1.11111116F * rtb_Add3 *
    CONTROL_PARAM.ROLL_RATE_FF;

  /* DeadZone: '<S76>/Dead Zone' */
  if (rate_cmd_B_radPs[2] > 0.1F) {
    rtb_Add3 = rate_cmd_B_radPs[2] - 0.1F;
  } else if (rate_cmd_B_radPs[2] >= -0.1F) {
    rtb_Add3 = 0.0F;
  } else {
    rtb_Add3 = rate_cmd_B_radPs[2] - -0.1F;
  }

  /* Sum: '<S68>/Sum' incorporates:
   *  Constant: '<S79>/gain3'
   *  DiscreteIntegrator: '<S75>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S78>/Discrete-Time Integrator'
   *  Gain: '<S72>/Gain1'
   *  Gain: '<S76>/Gain'
   *  Product: '<S79>/Multiply'
   *  Sum: '<S73>/Add'
   */
  rtb_Sum[2] = ((CONTROL_PARAM.YAW_RATE_P *
                 Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] +
                 Controller_DW.DiscreteTimeIntegrator_DSTATE[2]) +
                rtb_Switch_l_idx_0) + 1.11111116F * rtb_Add3 *
    CONTROL_PARAM.PITCH_RATE_FF;

  /* Outputs for Enabled SubSystem: '<S6>/Veloxity_Z_Controller' incorporates:
   *  EnablePort: '<S114>/Enable'
   */
  /* RelationalOperator: '<S113>/Compare' incorporates:
   *  Constant: '<S113>/Constant'
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_U.FMS_Out.ctrl_mode >= 4) {
    if (!Controller_DW.Veloxity_Z_Controller_MODE) {
      /* InitializeConditions for DiscreteIntegrator: '<S119>/Integrator1' */
      Controller_DW.Integrator1_IC_LOADING = 1U;

      /* InitializeConditions for DiscreteIntegrator: '<S123>/Discrete-Time Integrator' */
      Controller_DW.DiscreteTimeIntegrator_IC_LOADI = 1U;
      Controller_DW.DiscreteTimeIntegrator_PrevRe_m = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S125>/Discrete-Time Integrator1' */
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_k = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevR_i = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S119>/Integrator' */
      Controller_DW.Integrator_DSTATE = 0.0F;
      Controller_DW.Veloxity_Z_Controller_MODE = true;
    }

    /* Product: '<S115>/Multiply' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S115>/Cos'
     *  Trigonometry: '<S115>/Cos1'
     */
    rtb_att_error_B_rad_idx_1 = arm_cos_f32(Controller_U.INS_Out.phi) *
      arm_cos_f32(Controller_U.INS_Out.theta);

    /* Saturate: '<S115>/Saturation1' */
    if (rtb_att_error_B_rad_idx_1 > 1.0F) {
      rtb_Switch_l_idx_0 = 1.0F;
    } else if (rtb_att_error_B_rad_idx_1 < 0.5F) {
      rtb_Switch_l_idx_0 = 0.5F;
    } else {
      rtb_Switch_l_idx_0 = rtb_att_error_B_rad_idx_1;
    }

    /* End of Saturate: '<S115>/Saturation1' */

    /* DiscreteIntegrator: '<S119>/Integrator1' */
    if (Controller_DW.Integrator1_IC_LOADING != 0) {
      /* Switch: '<S116>/Switch' incorporates:
       *  Constant: '<S118>/Constant'
       *  Inport: '<Root>/INS_Out'
       *  RelationalOperator: '<S118>/Compare'
       *  S-Function (sfix_bitop): '<S116>/vel_valid'
       */
      if ((Controller_U.INS_Out.flag & 16U) == 0U) {
        Controller_DW.Integrator1_DSTATE = Controller_U.FMS_Out.w_cmd;
      } else {
        Controller_DW.Integrator1_DSTATE = Controller_U.INS_Out.vd;
      }

      /* End of Switch: '<S116>/Switch' */
    }

    w_cmd_C_mPs = Controller_DW.Integrator1_DSTATE;

    /* End of DiscreteIntegrator: '<S119>/Integrator1' */

    /* SignalConversion: '<S116>/Signal Copy1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    w_est_C_mPs = Controller_U.INS_Out.vd;

    /* Gain: '<S116>/Gain' incorporates:
     *  Sum: '<S116>/Sum1'
     */
    rtb_DiscreteTimeIntegrator_i__0 = -(w_cmd_C_mPs - w_est_C_mPs);

    /* Switch: '<S123>/Switch' incorporates:
     *  Constant: '<S121>/Constant'
     *  Constant: '<S123>/Constant'
     *  Constant: '<S123>/Constant1'
     *  Delay: '<S6>/Delay'
     *  RelationalOperator: '<S121>/Compare'
     */
    if (Controller_DW.Delay_DSTATE < 3) {
      rtb_Add3 = CONTROL_PARAM.VEL_Z_I_MIN;
    } else {
      rtb_Add3 = 0.0F;
    }

    /* End of Switch: '<S123>/Switch' */

    /* DiscreteIntegrator: '<S123>/Discrete-Time Integrator' */
    if (Controller_DW.DiscreteTimeIntegrator_IC_LOADI != 0) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m = rtb_Add3;
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m >=
          CONTROL_PARAM.VEL_Z_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_m =
          CONTROL_PARAM.VEL_Z_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m <=
            CONTROL_PARAM.VEL_Z_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_m =
            CONTROL_PARAM.VEL_Z_I_MIN;
        }
      }
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator_PrevRe_m != 0)) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m = rtb_Add3;
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m >=
          CONTROL_PARAM.VEL_Z_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_m =
          CONTROL_PARAM.VEL_Z_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m <=
            CONTROL_PARAM.VEL_Z_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_m =
            CONTROL_PARAM.VEL_Z_I_MIN;
        }
      }
    }

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

    /* DiscreteIntegrator: '<S125>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_k != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_h =
        rtb_DiscreteTimeIntegrator_i__0;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_i != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_h =
        rtb_DiscreteTimeIntegrator_i__0;
    }

    /* Gain: '<S125>/Gain' incorporates:
     *  DiscreteIntegrator: '<S125>/Discrete-Time Integrator1'
     *  Sum: '<S125>/Sum5'
     */
    rtb_Sign1_f_idx_0 = (rtb_DiscreteTimeIntegrator_i__0 -
                         Controller_DW.DiscreteTimeIntegrator1_DSTAT_h) *
      62.831852F;

    /* Switch: '<S125>/Switch' incorporates:
     *  Gain: '<S125>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_Add3 = 0.0F;
    } else {
      rtb_Add3 = rtb_Sign1_f_idx_0;
    }

    /* End of Switch: '<S125>/Switch' */

    /* Product: '<S122>/Multiply' incorporates:
     *  Constant: '<S122>/kd'
     */
    rtb_Add3 *= CONTROL_PARAM.VEL_Z_D;

    /* Saturate: '<S122>/Saturation' */
    if (rtb_Add3 > CONTROL_PARAM.VEL_Z_D_MAX) {
      rtb_Add3 = CONTROL_PARAM.VEL_Z_D_MAX;
    } else {
      if (rtb_Add3 < CONTROL_PARAM.VEL_Z_D_MIN) {
        rtb_Add3 = CONTROL_PARAM.VEL_Z_D_MIN;
      }
    }

    /* End of Saturate: '<S122>/Saturation' */

    /* Gain: '<S115>/Gain' */
    rtb_att_error_B_rad_idx_1 *= 2.0F;

    /* Saturate: '<S115>/Saturation' */
    if (rtb_att_error_B_rad_idx_1 > 1.0F) {
      rtb_att_error_B_rad_idx_1 = 1.0F;
    } else {
      if (rtb_att_error_B_rad_idx_1 < 0.0F) {
        rtb_att_error_B_rad_idx_1 = 0.0F;
      }
    }

    /* End of Saturate: '<S115>/Saturation' */

    /* Product: '<S115>/Multiply1' incorporates:
     *  Constant: '<S115>/Constant'
     *  Constant: '<S124>/kp'
     *  DiscreteIntegrator: '<S123>/Discrete-Time Integrator'
     *  Product: '<S115>/Divide'
     *  Product: '<S124>/Multiply'
     *  Sum: '<S117>/Add'
     */
    rtb_att_error_B_rad_idx_1 *= ((CONTROL_PARAM.VEL_Z_P *
      rtb_DiscreteTimeIntegrator_i__0 +
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m) + rtb_Add3) * (1.0F /
      rtb_Switch_l_idx_0);

    /* Saturate: '<S114>/Saturation' */
    if (rtb_att_error_B_rad_idx_1 > 0.35F) {
      Controller_B.Saturation = 0.35F;
    } else if (rtb_att_error_B_rad_idx_1 < -0.35F) {
      Controller_B.Saturation = -0.35F;
    } else {
      Controller_B.Saturation = rtb_att_error_B_rad_idx_1;
    }

    /* End of Saturate: '<S114>/Saturation' */

    /* Product: '<S120>/Multiply1' incorporates:
     *  Constant: '<S120>/const1'
     *  DiscreteIntegrator: '<S119>/Integrator'
     */
    rtb_Add3 = Controller_DW.Integrator_DSTATE * 0.05F;

    /* Sum: '<S120>/Add' incorporates:
     *  Sum: '<S119>/Subtract'
     */
    rtb_att_error_B_rad_idx_1 = (w_cmd_C_mPs - Controller_U.FMS_Out.w_cmd) +
      rtb_Add3;

    /* Signum: '<S120>/Sign' */
    if (rtb_att_error_B_rad_idx_1 < 0.0F) {
      rtb_att_error_B_rad_idx_0 = -1.0F;
    } else if (rtb_att_error_B_rad_idx_1 > 0.0F) {
      rtb_att_error_B_rad_idx_0 = 1.0F;
    } else {
      rtb_att_error_B_rad_idx_0 = rtb_att_error_B_rad_idx_1;
    }

    /* End of Signum: '<S120>/Sign' */

    /* Sum: '<S120>/Add2' incorporates:
     *  Abs: '<S120>/Abs'
     *  Gain: '<S120>/Gain'
     *  Gain: '<S120>/Gain1'
     *  Product: '<S120>/Multiply2'
     *  Product: '<S120>/Multiply3'
     *  Sqrt: '<S120>/Sqrt'
     *  Sum: '<S120>/Add1'
     *  Sum: '<S120>/Subtract'
     */
    rtb_att_error_B_rad_idx_0 = (sqrtf((8.0F * fabsf(rtb_att_error_B_rad_idx_1)
      + Controller_ConstB.d) * Controller_ConstB.d) - Controller_ConstB.d) *
      0.5F * rtb_att_error_B_rad_idx_0 + rtb_Add3;

    /* Sum: '<S120>/Add4' */
    rtb_Switch_l_idx_0 = (rtb_att_error_B_rad_idx_1 - rtb_att_error_B_rad_idx_0)
      + rtb_Add3;

    /* Sum: '<S120>/Add3' */
    rtb_Add3 = rtb_att_error_B_rad_idx_1 + Controller_ConstB.d;

    /* Sum: '<S120>/Subtract1' */
    rtb_att_error_B_rad_idx_1 -= Controller_ConstB.d;

    /* Signum: '<S120>/Sign1' */
    if (rtb_Add3 < 0.0F) {
      rtb_Add3 = -1.0F;
    } else {
      if (rtb_Add3 > 0.0F) {
        rtb_Add3 = 1.0F;
      }
    }

    /* End of Signum: '<S120>/Sign1' */

    /* Signum: '<S120>/Sign2' */
    if (rtb_att_error_B_rad_idx_1 < 0.0F) {
      rtb_att_error_B_rad_idx_1 = -1.0F;
    } else {
      if (rtb_att_error_B_rad_idx_1 > 0.0F) {
        rtb_att_error_B_rad_idx_1 = 1.0F;
      }
    }

    /* End of Signum: '<S120>/Sign2' */

    /* Sum: '<S120>/Add5' incorporates:
     *  Gain: '<S120>/Gain2'
     *  Product: '<S120>/Multiply4'
     *  Sum: '<S120>/Subtract2'
     */
    rtb_att_error_B_rad_idx_0 += (rtb_Add3 - rtb_att_error_B_rad_idx_1) * 0.5F *
      rtb_Switch_l_idx_0;

    /* Update for DiscreteIntegrator: '<S119>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S119>/Integrator'
     */
    Controller_DW.Integrator1_IC_LOADING = 0U;
    Controller_DW.Integrator1_DSTATE += 0.002F * Controller_DW.Integrator_DSTATE;

    /* Update for DiscreteIntegrator: '<S123>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S123>/ki'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S123>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_IC_LOADI = 0U;
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m += CONTROL_PARAM.VEL_Z_I *
      rtb_DiscreteTimeIntegrator_i__0 * 0.002F;
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

    Controller_DW.DiscreteTimeIntegrator_PrevRe_m = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* End of Update for DiscreteIntegrator: '<S123>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S125>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_k = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_h += 0.002F * rtb_Sign1_f_idx_0;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_i = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Signum: '<S120>/Sign6' incorporates:
     *  Signum: '<S120>/Sign5'
     */
    if (rtb_att_error_B_rad_idx_0 < 0.0F) {
      rtb_Switch_l_idx_0 = -1.0F;

      /* Signum: '<S120>/Sign5' */
      rtb_DiscreteTimeIntegrator_i__0 = -1.0F;
    } else if (rtb_att_error_B_rad_idx_0 > 0.0F) {
      rtb_Switch_l_idx_0 = 1.0F;

      /* Signum: '<S120>/Sign5' */
      rtb_DiscreteTimeIntegrator_i__0 = 1.0F;
    } else {
      rtb_Switch_l_idx_0 = rtb_att_error_B_rad_idx_0;

      /* Signum: '<S120>/Sign5' */
      rtb_DiscreteTimeIntegrator_i__0 = rtb_att_error_B_rad_idx_0;
    }

    /* End of Signum: '<S120>/Sign6' */

    /* Sum: '<S120>/Add6' */
    rtb_Add3 = rtb_att_error_B_rad_idx_0 + Controller_ConstB.d;

    /* Sum: '<S120>/Subtract3' */
    rtb_att_error_B_rad_idx_1 = rtb_att_error_B_rad_idx_0 - Controller_ConstB.d;

    /* Signum: '<S120>/Sign3' */
    if (rtb_Add3 < 0.0F) {
      rtb_Add3 = -1.0F;
    } else {
      if (rtb_Add3 > 0.0F) {
        rtb_Add3 = 1.0F;
      }
    }

    /* End of Signum: '<S120>/Sign3' */

    /* Signum: '<S120>/Sign4' */
    if (rtb_att_error_B_rad_idx_1 < 0.0F) {
      rtb_att_error_B_rad_idx_1 = -1.0F;
    } else {
      if (rtb_att_error_B_rad_idx_1 > 0.0F) {
        rtb_att_error_B_rad_idx_1 = 1.0F;
      }
    }

    /* End of Signum: '<S120>/Sign4' */

    /* Update for DiscreteIntegrator: '<S119>/Integrator' incorporates:
     *  Constant: '<S120>/const'
     *  Gain: '<S120>/Gain3'
     *  Product: '<S120>/Divide'
     *  Product: '<S120>/Multiply5'
     *  Product: '<S120>/Multiply6'
     *  Sum: '<S120>/Subtract4'
     *  Sum: '<S120>/Subtract5'
     *  Sum: '<S120>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE += ((rtb_att_error_B_rad_idx_0 /
      Controller_ConstB.d - rtb_DiscreteTimeIntegrator_i__0) *
      Controller_ConstB.Gain4 * ((rtb_Add3 - rtb_att_error_B_rad_idx_1) * 0.5F)
      - rtb_Switch_l_idx_0 * 78.448F) * 0.002F;
  } else {
    if (Controller_DW.Veloxity_Z_Controller_MODE) {
      Controller_DW.Veloxity_Z_Controller_MODE = false;
    }
  }

  /* End of RelationalOperator: '<S113>/Compare' */
  /* End of Outputs for SubSystem: '<S6>/Veloxity_Z_Controller' */

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
          if (Controller_B.Saturation > 1.0F) {
            /* Saturate: '<S7>/Saturation2' */
            u0_b = 1.0F;
          } else if (Controller_B.Saturation < -1.0F) {
            /* Saturate: '<S7>/Saturation2' */
            u0_b = -1.0F;
          } else {
            /* Saturate: '<S7>/Saturation2' */
            u0_b = Controller_B.Saturation;
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
        if (Controller_B.Saturation > 1.0F) {
          /* Saturate: '<S7>/Saturation2' */
          u0_b = 1.0F;
        } else if (Controller_B.Saturation < -1.0F) {
          /* Saturate: '<S7>/Saturation2' */
          u0_b = -1.0F;
        } else {
          /* Saturate: '<S7>/Saturation2' */
          u0_b = Controller_B.Saturation;
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
      if (rtb_Sum[0] > 1.0F) {
        tmp_b = 1.0F;
      } else if (rtb_Sum[0] < -1.0F) {
        tmp_b = -1.0F;
      } else {
        tmp_b = rtb_Sum[0];
      }

      if (rtb_Sum[1] > 1.0F) {
        tmp_k = 1.0F;
      } else if (rtb_Sum[1] < -1.0F) {
        tmp_k = -1.0F;
      } else {
        tmp_k = rtb_Sum[1];
      }

      if (rtb_Sum[2] > 1.0F) {
        tmp_i = 1.0F;
      } else if (rtb_Sum[2] < -1.0F) {
        tmp_i = -1.0F;
      } else {
        tmp_i = rtb_Sum[2];
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
          if (Controller_B.Saturation > 1.0F) {
            /* Saturate: '<S8>/Saturation2' */
            u0_n = 1.0F;
          } else if (Controller_B.Saturation < -1.0F) {
            /* Saturate: '<S8>/Saturation2' */
            u0_n = -1.0F;
          } else {
            /* Saturate: '<S8>/Saturation2' */
            u0_n = Controller_B.Saturation;
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
        if (Controller_B.Saturation > 1.0F) {
          /* Saturate: '<S8>/Saturation2' */
          u0_n = 1.0F;
        } else if (Controller_B.Saturation < -1.0F) {
          /* Saturate: '<S8>/Saturation2' */
          u0_n = -1.0F;
        } else {
          /* Saturate: '<S8>/Saturation2' */
          u0_n = Controller_B.Saturation;
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
      if (rtb_Sum[0] > 1.0F) {
        tmp_n = 1.0F;
      } else if (rtb_Sum[0] < -1.0F) {
        tmp_n = -1.0F;
      } else {
        tmp_n = rtb_Sum[0];
      }

      if (rtb_Sum[1] > 1.0F) {
        tmp_d = 1.0F;
      } else if (rtb_Sum[1] < -1.0F) {
        tmp_d = -1.0F;
      } else {
        tmp_d = rtb_Sum[1];
      }

      if (rtb_Sum[2] > 1.0F) {
        tmp_a = 1.0F;
      } else if (rtb_Sum[2] < -1.0F) {
        tmp_a = -1.0F;
      } else {
        tmp_a = rtb_Sum[2];
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
          if (Controller_B.Saturation > 1.0F) {
            /* Saturate: '<S9>/Saturation2' */
            u0_i = 1.0F;
          } else if (Controller_B.Saturation < -1.0F) {
            /* Saturate: '<S9>/Saturation2' */
            u0_i = -1.0F;
          } else {
            /* Saturate: '<S9>/Saturation2' */
            u0_i = Controller_B.Saturation;
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
        if (Controller_B.Saturation > 1.0F) {
          /* Saturate: '<S9>/Saturation2' */
          u0_i = 1.0F;
        } else if (Controller_B.Saturation < -1.0F) {
          /* Saturate: '<S9>/Saturation2' */
          u0_i = -1.0F;
        } else {
          /* Saturate: '<S9>/Saturation2' */
          u0_i = Controller_B.Saturation;
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
      if (rtb_Sum[0] > 1.0F) {
        tmp_i = 1.0F;
      } else if (rtb_Sum[0] < -1.0F) {
        tmp_i = -1.0F;
      } else {
        tmp_i = rtb_Sum[0];
      }

      if (rtb_Sum[1] > 1.0F) {
        tmp_o = 1.0F;
      } else if (rtb_Sum[1] < -1.0F) {
        tmp_o = -1.0F;
      } else {
        tmp_o = rtb_Sum[1];
      }

      if (rtb_Sum[2] > 1.0F) {
        tmp_d = 1.0F;
      } else if (rtb_Sum[2] < -1.0F) {
        tmp_d = -1.0F;
      } else {
        tmp_d = rtb_Sum[2];
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
          if (Controller_B.Saturation > 1.0F) {
            /* Saturate: '<S10>/Saturation2' */
            u0_j = 1.0F;
          } else if (Controller_B.Saturation < -1.0F) {
            /* Saturate: '<S10>/Saturation2' */
            u0_j = -1.0F;
          } else {
            /* Saturate: '<S10>/Saturation2' */
            u0_j = Controller_B.Saturation;
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
        if (Controller_B.Saturation > 1.0F) {
          /* Saturate: '<S10>/Saturation2' */
          u0_j = 1.0F;
        } else if (Controller_B.Saturation < -1.0F) {
          /* Saturate: '<S10>/Saturation2' */
          u0_j = -1.0F;
        } else {
          /* Saturate: '<S10>/Saturation2' */
          u0_j = Controller_B.Saturation;
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
      if (rtb_Sum[0] > 1.0F) {
        tmp_j = 1.0F;
      } else if (rtb_Sum[0] < -1.0F) {
        tmp_j = -1.0F;
      } else {
        tmp_j = rtb_Sum[0];
      }

      if (rtb_Sum[1] > 1.0F) {
        tmp_e = 1.0F;
      } else if (rtb_Sum[1] < -1.0F) {
        tmp_e = -1.0F;
      } else {
        tmp_e = rtb_Sum[1];
      }

      if (rtb_Sum[2] > 1.0F) {
        tmp_g = 1.0F;
      } else if (rtb_Sum[2] < -1.0F) {
        tmp_g = -1.0F;
      } else {
        tmp_g = rtb_Sum[2];
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
          if (Controller_B.Saturation > 1.0F) {
            /* Saturate: '<S11>/Saturation2' */
            u0_i = 1.0F;
          } else if (Controller_B.Saturation < -1.0F) {
            /* Saturate: '<S11>/Saturation2' */
            u0_i = -1.0F;
          } else {
            /* Saturate: '<S11>/Saturation2' */
            u0_i = Controller_B.Saturation;
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
        if (Controller_B.Saturation > 1.0F) {
          /* Saturate: '<S11>/Saturation2' */
          u0_i = 1.0F;
        } else if (Controller_B.Saturation < -1.0F) {
          /* Saturate: '<S11>/Saturation2' */
          u0_i = -1.0F;
        } else {
          /* Saturate: '<S11>/Saturation2' */
          u0_i = Controller_B.Saturation;
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
      if (rtb_Sum[0] > 1.0F) {
        tmp_i = 1.0F;
      } else if (rtb_Sum[0] < -1.0F) {
        tmp_i = -1.0F;
      } else {
        tmp_i = rtb_Sum[0];
      }

      if (rtb_Sum[1] > 1.0F) {
        tmp_d = 1.0F;
      } else if (rtb_Sum[1] < -1.0F) {
        tmp_d = -1.0F;
      } else {
        tmp_d = rtb_Sum[1];
      }

      if (rtb_Sum[2] > 1.0F) {
        tmp_j = 1.0F;
      } else if (rtb_Sum[2] < -1.0F) {
        tmp_j = -1.0F;
      } else {
        tmp_j = rtb_Sum[2];
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
          if (Controller_B.Saturation > 1.0F) {
            /* Saturate: '<S12>/Saturation2' */
            u0_l = 1.0F;
          } else if (Controller_B.Saturation < -1.0F) {
            /* Saturate: '<S12>/Saturation2' */
            u0_l = -1.0F;
          } else {
            /* Saturate: '<S12>/Saturation2' */
            u0_l = Controller_B.Saturation;
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
        if (Controller_B.Saturation > 1.0F) {
          /* Saturate: '<S12>/Saturation2' */
          u0_l = 1.0F;
        } else if (Controller_B.Saturation < -1.0F) {
          /* Saturate: '<S12>/Saturation2' */
          u0_l = -1.0F;
        } else {
          /* Saturate: '<S12>/Saturation2' */
          u0_l = Controller_B.Saturation;
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
      if (rtb_Sum[0] > 1.0F) {
        tmp_l = 1.0F;
      } else if (rtb_Sum[0] < -1.0F) {
        tmp_l = -1.0F;
      } else {
        tmp_l = rtb_Sum[0];
      }

      if (rtb_Sum[1] > 1.0F) {
        tmp_m = 1.0F;
      } else if (rtb_Sum[1] < -1.0F) {
        tmp_m = -1.0F;
      } else {
        tmp_m = rtb_Sum[1];
      }

      if (rtb_Sum[2] > 1.0F) {
        tmp_c = 1.0F;
      } else if (rtb_Sum[2] < -1.0F) {
        tmp_c = -1.0F;
      } else {
        tmp_c = rtb_Sum[2];
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
          if (Controller_B.Saturation > 1.0F) {
            /* Saturate: '<S13>/Saturation2' */
            u0_m = 1.0F;
          } else if (Controller_B.Saturation < -1.0F) {
            /* Saturate: '<S13>/Saturation2' */
            u0_m = -1.0F;
          } else {
            /* Saturate: '<S13>/Saturation2' */
            u0_m = Controller_B.Saturation;
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
        if (Controller_B.Saturation > 1.0F) {
          /* Saturate: '<S13>/Saturation2' */
          u0_m = 1.0F;
        } else if (Controller_B.Saturation < -1.0F) {
          /* Saturate: '<S13>/Saturation2' */
          u0_m = -1.0F;
        } else {
          /* Saturate: '<S13>/Saturation2' */
          u0_m = Controller_B.Saturation;
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
      if (rtb_Sum[0] > 1.0F) {
        tmp_m = 1.0F;
      } else if (rtb_Sum[0] < -1.0F) {
        tmp_m = -1.0F;
      } else {
        tmp_m = rtb_Sum[0];
      }

      if (rtb_Sum[1] > 1.0F) {
        tmp_n = 1.0F;
      } else if (rtb_Sum[1] < -1.0F) {
        tmp_n = -1.0F;
      } else {
        tmp_n = rtb_Sum[1];
      }

      if (rtb_Sum[2] > 1.0F) {
        tmp_al = 1.0F;
      } else if (rtb_Sum[2] < -1.0F) {
        tmp_al = -1.0F;
      } else {
        tmp_al = rtb_Sum[2];
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
          if (Controller_B.Saturation > 1.0F) {
            /* Saturate: '<S14>/Saturation2' */
            u0_e = 1.0F;
          } else if (Controller_B.Saturation < -1.0F) {
            /* Saturate: '<S14>/Saturation2' */
            u0_e = -1.0F;
          } else {
            /* Saturate: '<S14>/Saturation2' */
            u0_e = Controller_B.Saturation;
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
        if (Controller_B.Saturation > 1.0F) {
          /* Saturate: '<S14>/Saturation2' */
          u0_e = 1.0F;
        } else if (Controller_B.Saturation < -1.0F) {
          /* Saturate: '<S14>/Saturation2' */
          u0_e = -1.0F;
        } else {
          /* Saturate: '<S14>/Saturation2' */
          u0_e = Controller_B.Saturation;
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
      if (rtb_Sum[0] > 1.0F) {
        tmp_e = 1.0F;
      } else if (rtb_Sum[0] < -1.0F) {
        tmp_e = -1.0F;
      } else {
        tmp_e = rtb_Sum[0];
      }

      if (rtb_Sum[1] > 1.0F) {
        tmp_o = 1.0F;
      } else if (rtb_Sum[1] < -1.0F) {
        tmp_o = -1.0F;
      } else {
        tmp_o = rtb_Sum[1];
      }

      if (rtb_Sum[2] > 1.0F) {
        tmp_h = 1.0F;
      } else if (rtb_Sum[2] < -1.0F) {
        tmp_h = -1.0F;
      } else {
        tmp_h = rtb_Sum[2];
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

  /* Product: '<S78>/Multiply' incorporates:
   *  Constant: '<S78>/gain1'
   *  Constant: '<S78>/gain2'
   *  Constant: '<S78>/gain3'
   *  DiscreteIntegrator: '<S75>/Discrete-Time Integrator5'
   */
  rtb_Add3 = CONTROL_PARAM.ROLL_RATE_I *
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[0];
  rtb_att_error_B_rad_idx_1 = CONTROL_PARAM.PITCH_RATE_I *
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1];
  rtb_att_error_B_rad_idx_0 = CONTROL_PARAM.YAW_RATE_I *
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[2];

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

  /* Update for DiscreteIntegrator: '<S75>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;

  /* Update for DiscreteIntegrator: '<S78>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S80>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;

  /* Update for DiscreteIntegrator: '<S75>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S75>/Gain'
   *  Sum: '<S75>/Sum5'
   */
  Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] +=
    (rtb_DiscreteTimeIntegrator_b[0] -
     Controller_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 188.49556F * 0.002F;

  /* Update for DiscreteIntegrator: '<S78>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE[0] += 0.002F * rtb_Add3;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] >= CONTROL_PARAM.RATE_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = CONTROL_PARAM.RATE_I_MIN;
    }
  }

  /* Update for DiscreteIntegrator: '<S80>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] += 0.002F * rtb_Gain_idx_0;

  /* Update for DiscreteIntegrator: '<S75>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S75>/Gain'
   *  Sum: '<S75>/Sum5'
   */
  Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] +=
    (rtb_DiscreteTimeIntegrator_b[1] -
     Controller_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 188.49556F * 0.002F;

  /* Update for DiscreteIntegrator: '<S78>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE[1] += 0.002F *
    rtb_att_error_B_rad_idx_1;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] >= CONTROL_PARAM.RATE_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = CONTROL_PARAM.RATE_I_MIN;
    }
  }

  /* Update for DiscreteIntegrator: '<S80>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] += 0.002F *
    rtb_DiscreteTimeIntegrator_i_id;

  /* Update for DiscreteIntegrator: '<S75>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S75>/Gain'
   *  Sum: '<S75>/Sum5'
   */
  Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] +=
    (rtb_DiscreteTimeIntegrator_b[2] -
     Controller_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 188.49556F * 0.002F;

  /* Update for DiscreteIntegrator: '<S78>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE[2] += 0.002F *
    rtb_att_error_B_rad_idx_0;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[2] >= CONTROL_PARAM.RATE_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[2] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[2] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[2] = CONTROL_PARAM.RATE_I_MIN;
    }
  }

  /* Update for DiscreteIntegrator: '<S80>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_DSTATE[2] += 0.002F *
    rtb_DiscreteTimeIntegrator1_j;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for Delay: '<S6>/Delay' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.Delay_DSTATE = Controller_U.FMS_Out.status;

  /* Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S3>/Constant'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_n += CONTROL_EXPORT.period;
}

/* Model initialize function */
void Controller_init(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Controller_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &Controller_B), 0,
                sizeof(B_Controller_T));

  /* exported global signals */
  att_cmd_B_rad[0] = 0.0F;
  att_cmd_B_rad[1] = 0.0F;
  att_est_B_rad[0] = 0.0F;
  att_est_B_rad[1] = 0.0F;
  rate_cmd_B_radPs[0] = 0.0F;
  rate_cmd_B_radPs[1] = 0.0F;
  rate_cmd_B_radPs[2] = 0.0F;
  rate_est_B_radPs[0] = 0.0F;
  rate_est_B_radPs[1] = 0.0F;
  rate_est_B_radPs[2] = 0.0F;
  w_cmd_C_mPs = 0.0F;
  w_est_C_mPs = 0.0F;

  /* states (dwork) */
  (void) memset((void *)&Controller_DW, 0,
                sizeof(DW_Controller_T));

  /* external inputs */
  (void)memset(&Controller_U, 0, sizeof(ExtU_Controller_T));

  /* external outputs */
  Controller_Y.Control_Out = Controller_rtZControl_Out_Bus;

  /* InitializeConditions for DiscreteIntegrator: '<S75>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S78>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = Controller_ConstB.Constant[0];
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] >= CONTROL_PARAM.RATE_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = CONTROL_PARAM.RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = Controller_ConstB.Constant[1];
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] >= CONTROL_PARAM.RATE_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = CONTROL_PARAM.RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_DSTATE[2] = Controller_ConstB.Constant[2];
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[2] >= CONTROL_PARAM.RATE_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[2] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[2] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[2] = CONTROL_PARAM.RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRese = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S78>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S80>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* InitializeConditions for Delay: '<S6>/Delay' */
  Controller_DW.Delay_DSTATE = 1U;

  /* SystemInitialize for Enabled SubSystem: '<S5>/Velocity_Controller' */
  /* InitializeConditions for DiscreteIntegrator: '<S101>/Integrator1' */
  Controller_DW.Integrator1_IC_LOADING_e = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S101>/Integrator' */
  Controller_DW.Integrator_DSTATE_o[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S106>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[0] =
    Controller_ConstB.Constant_g;
  if (Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[0] >=
      CONTROL_PARAM.VEL_XY_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[0] =
      CONTROL_PARAM.VEL_XY_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[0] <=
        CONTROL_PARAM.VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[0] =
        CONTROL_PARAM.VEL_XY_I_MIN;
    }
  }

  /* InitializeConditions for DiscreteIntegrator: '<S101>/Integrator' */
  Controller_DW.Integrator_DSTATE_o[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S106>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[1] =
    Controller_ConstB.Constant_g;
  if (Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[1] >=
      CONTROL_PARAM.VEL_XY_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[1] =
      CONTROL_PARAM.VEL_XY_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[1] <=
        CONTROL_PARAM.VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_mi[1] =
        CONTROL_PARAM.VEL_XY_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRe_e = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S108>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_b = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_a = 0;

  /* End of SystemInitialize for SubSystem: '<S5>/Velocity_Controller' */

  /* SystemInitialize for Enabled SubSystem: '<S6>/Veloxity_Z_Controller' */
  /* InitializeConditions for DiscreteIntegrator: '<S119>/Integrator1' */
  Controller_DW.Integrator1_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S123>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_IC_LOADI = 1U;
  Controller_DW.DiscreteTimeIntegrator_PrevRe_m = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S125>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_k = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_i = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S119>/Integrator' */
  Controller_DW.Integrator_DSTATE = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S6>/Veloxity_Z_Controller' */
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
