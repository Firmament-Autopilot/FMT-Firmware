/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.1044
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Sep 14 16:51:41 2026
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
real32_T att_cmd_B_rad[2];             /* '<S78>/Switch' */
real32_T att_est_B_rad[2];             /* '<S81>/Signal Copy' */
real32_T rate_cmd_B_radPs[3];          /* '<S62>/Switch' */
real32_T rate_est_B_radPs[3];          /* '<S66>/Signal Copy' */
real32_T w_cmd_C_mPs;                  /* '<S117>/Integrator1' */
real32_T w_est_C_mPs;                  /* '<S114>/Signal Copy1' */

/* Exported block parameters */
struct_YUVwBtBTzwKJDzRziwWpiH CONTROL_PARAM = {
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
  0.52359879F,
  0.15F,
  0.15F,
  0.3F,
  0.15F,
  0.15F,
  0.3F,
  0.005F,
  0.005F,
  0.002F,
  0.03F,
  0.03F,
  0.05F,
  -0.2F,
  0.2F,
  -0.2F,
  0.2F,
  1.57079637F,
  3.14159274F,
  0.5F
} ;                                    /* Variable: CONTROL_PARAM
                                        * Referenced by:
                                        *   '<S109>/hover_throttle'
                                        *   '<S87>/Saturation'
                                        *   '<S61>/Saturation'
                                        *   '<S61>/Saturation1'
                                        *   '<S99>/kd'
                                        *   '<S99>/Saturation'
                                        *   '<S100>/ki'
                                        *   '<S100>/Discrete-Time Integrator'
                                        *   '<S101>/kp'
                                        *   '<S120>/kd'
                                        *   '<S120>/Saturation'
                                        *   '<S121>/Constant'
                                        *   '<S121>/ki'
                                        *   '<S121>/Discrete-Time Integrator'
                                        *   '<S122>/kp'
                                        *   '<S64>/Gain'
                                        *   '<S64>/Gain1'
                                        *   '<S64>/Gain2'
                                        *   '<S80>/Constant1'
                                        *   '<S80>/Constant2'
                                        *   '<S69>/gain1'
                                        *   '<S69>/gain2'
                                        *   '<S69>/gain3'
                                        *   '<S69>/Saturation'
                                        *   '<S70>/gain1'
                                        *   '<S70>/gain2'
                                        *   '<S70>/gain3'
                                        *   '<S70>/Discrete-Time Integrator'
                                        *   '<S71>/gain1'
                                        *   '<S71>/gain2'
                                        *   '<S71>/gain3'
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

/*
 * Output and update for atomic system:
 *    '<S21>/R_Remix'
 *    '<S36>/R_Remix'
 *    '<S41>/R_Remix'
 */
#if (AIRFRAME == 3) || (AIRFRAME == 7) || (AIRFRAME == 8)

void Controller_R_Remix(real32_T rtu_up_lim, real32_T rtu_lo_lim, const real32_T
  rtu_r_column[8], const real32_T rtu_motor_out[8], real32_T rty_floating_yaw[8])
{
  real32_T b_min;
  real32_T b_max;
  int32_T min_index;
  int32_T max_index;
  int32_T i;
  b_min = 100.0F;
  b_max = -100.0F;
  min_index = 0;
  max_index = 0;
  for (i = 0; i < 8; i++) {
    if (rtu_motor_out[i] < b_min) {
      b_min = rtu_motor_out[i];
      min_index = i + 1;
    }

    if (rtu_motor_out[i] > b_max) {
      b_max = rtu_motor_out[i];
      max_index = i + 1;
    }
  }

  if ((b_max > rtu_up_lim) || (b_min < rtu_lo_lim)) {
    b_min = rtu_lo_lim - b_min;
    if (b_max - rtu_up_lim > b_min) {
      b_min = rtu_up_lim - b_max;
      min_index = max_index;
    }

    b_max = rtu_r_column[min_index - 1];
    if (b_max < 0.0F) {
      b_max = -1.0F;
    } else {
      if (b_max > 0.0F) {
        b_max = 1.0F;
      }
    }

    b_min *= b_max;
  } else {
    b_min = 0.0F;
  }

  for (min_index = 0; min_index < 8; min_index++) {
    rty_floating_yaw[min_index] = rtu_r_column[min_index];
    if (rty_floating_yaw[min_index] < 0.0F) {
      rty_floating_yaw[min_index] = -1.0F;
    } else {
      if (rty_floating_yaw[min_index] > 0.0F) {
        rty_floating_yaw[min_index] = 1.0F;
      }
    }

    rty_floating_yaw[min_index] *= b_min;
  }
}

#endif

/*
 * Output and update for atomic system:
 *    '<S26>/R_Remix'
 *    '<S31>/R_Remix'
 */
#if (AIRFRAME == 4) || (AIRFRAME == 5)

void Controller_R_Remix_h(real32_T rtu_up_lim, real32_T rtu_lo_lim, const
  real32_T rtu_r_column[6], const real32_T rtu_motor_out[6], real32_T
  rty_floating_yaw[6])
{
  real32_T b_min;
  real32_T b_max;
  int32_T min_index;
  int32_T max_index;
  int32_T i;
  b_min = 100.0F;
  b_max = -100.0F;
  min_index = 0;
  max_index = 0;
  for (i = 0; i < 6; i++) {
    if (rtu_motor_out[i] < b_min) {
      b_min = rtu_motor_out[i];
      min_index = i + 1;
    }

    if (rtu_motor_out[i] > b_max) {
      b_max = rtu_motor_out[i];
      max_index = i + 1;
    }
  }

  if ((b_max > rtu_up_lim) || (b_min < rtu_lo_lim)) {
    b_min = rtu_lo_lim - b_min;
    if (b_max - rtu_up_lim > b_min) {
      b_min = rtu_up_lim - b_max;
      min_index = max_index;
    }

    b_max = rtu_r_column[min_index - 1];
    if (b_max < 0.0F) {
      b_max = -1.0F;
    } else {
      if (b_max > 0.0F) {
        b_max = 1.0F;
      }
    }

    b_min *= b_max;
  } else {
    b_min = 0.0F;
  }

  for (min_index = 0; min_index < 6; min_index++) {
    rty_floating_yaw[min_index] = rtu_r_column[min_index];
    if (rty_floating_yaw[min_index] < 0.0F) {
      rty_floating_yaw[min_index] = -1.0F;
    } else {
      if (rty_floating_yaw[min_index] > 0.0F) {
        rty_floating_yaw[min_index] = 1.0F;
      }
    }

    rty_floating_yaw[min_index] *= b_min;
  }
}

#endif

/*
 * Output and update for atomic system:
 *    '<S46>/R_Remix'
 *    '<S51>/R_Remix'
 */
#if (AIRFRAME == 1) || (AIRFRAME == 2)

void Controller_R_Remix_k(real32_T rtu_up_lim, real32_T rtu_lo_lim, const
  real32_T rtu_r_column[4], const real32_T rtu_motor_out[4], real32_T
  rty_floating_yaw[4])
{
  real32_T b_min;
  real32_T b_max;
  int32_T min_index;
  int32_T max_index;
  b_min = 100.0F;
  b_max = -100.0F;
  min_index = 0;
  max_index = 0;
  if (rtu_motor_out[0] < 100.0F) {
    b_min = rtu_motor_out[0];
    min_index = 1;
  }

  if (rtu_motor_out[0] > -100.0F) {
    b_max = rtu_motor_out[0];
    max_index = 1;
  }

  if (rtu_motor_out[1] < b_min) {
    b_min = rtu_motor_out[1];
    min_index = 2;
  }

  if (rtu_motor_out[1] > b_max) {
    b_max = rtu_motor_out[1];
    max_index = 2;
  }

  if (rtu_motor_out[2] < b_min) {
    b_min = rtu_motor_out[2];
    min_index = 3;
  }

  if (rtu_motor_out[2] > b_max) {
    b_max = rtu_motor_out[2];
    max_index = 3;
  }

  if (rtu_motor_out[3] < b_min) {
    b_min = rtu_motor_out[3];
    min_index = 4;
  }

  if (rtu_motor_out[3] > b_max) {
    b_max = rtu_motor_out[3];
    max_index = 4;
  }

  if ((b_max > rtu_up_lim) || (b_min < rtu_lo_lim)) {
    b_min = rtu_lo_lim - b_min;
    if (b_max - rtu_up_lim > b_min) {
      b_min = rtu_up_lim - b_max;
      min_index = max_index;
    }

    b_max = rtu_r_column[min_index - 1];
    if (b_max < 0.0F) {
      b_max = -1.0F;
    } else {
      if (b_max > 0.0F) {
        b_max = 1.0F;
      }
    }

    b_min *= b_max;
  } else {
    b_min = 0.0F;
  }

  rty_floating_yaw[0] = rtu_r_column[0];
  if (rty_floating_yaw[0] < 0.0F) {
    rty_floating_yaw[0] = -1.0F;
  } else {
    if (rty_floating_yaw[0] > 0.0F) {
      rty_floating_yaw[0] = 1.0F;
    }
  }

  rty_floating_yaw[0] *= b_min;
  rty_floating_yaw[1] = rtu_r_column[1];
  if (rty_floating_yaw[1] < 0.0F) {
    rty_floating_yaw[1] = -1.0F;
  } else {
    if (rty_floating_yaw[1] > 0.0F) {
      rty_floating_yaw[1] = 1.0F;
    }
  }

  rty_floating_yaw[1] *= b_min;
  rty_floating_yaw[2] = rtu_r_column[2];
  if (rty_floating_yaw[2] < 0.0F) {
    rty_floating_yaw[2] = -1.0F;
  } else {
    if (rty_floating_yaw[2] > 0.0F) {
      rty_floating_yaw[2] = 1.0F;
    }
  }

  rty_floating_yaw[2] *= b_min;
  rty_floating_yaw[3] = rtu_r_column[3];
  if (rty_floating_yaw[3] < 0.0F) {
    rty_floating_yaw[3] = -1.0F;
  } else {
    if (rty_floating_yaw[3] > 0.0F) {
      rty_floating_yaw[3] = 1.0F;
    }
  }

  rty_floating_yaw[3] *= b_min;
}

#endif

/* Model step function */
void Controller_step(void)
{
  /* local block i/o variables */
  real32_T rtb_Sum[3];
  real32_T rtb_Switch;
  uint16_T rtb_VariantMergeForOutportactua[16];
  real32_T rtb_Add3;
  real32_T rtb_DiscreteTimeIntegrator1_a;
  real32_T rtb_DiscreteTimeIntegrator1[3];
  real32_T rtb_VectorConcatenate[9];
  int32_T i;
  real32_T rtb_Switch_mh_idx_0;
  real32_T rtb_Switch_mh_idx_1;
  real32_T rtb_att_error_B_rad_idx_0;
  real32_T rtb_att_error_B_rad_idx_1;
  real32_T rtb_Sign1_f_idx_0;
  real32_T rtb_Gain_j_idx_0;
  real32_T rtb_Gain_j_idx_1;
  real32_T rtb_Gain_idx_0;
  real32_T rtb_DiscreteTimeIntegrator_i_id;
  real32_T rtb_DiscreteTimeIntegrator_i__0;

  /* Outputs for Enabled SubSystem: '<S5>/Velocity_Controller' incorporates:
   *  EnablePort: '<S57>/Enable'
   */
  /* RelationalOperator: '<S56>/Compare' incorporates:
   *  Constant: '<S56>/Constant'
   *  DiscreteIntegrator: '<S95>/Integrator1'
   *  Gain: '<S87>/gain'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S99>/Multiply'
   *  Signum: '<S98>/Sign1'
   *  Sum: '<S89>/Sum'
   */
  if (Controller_U.FMS_Out.ctrl_mode >= 5) {
    if (!Controller_DW.Velocity_Controller_MODE) {
      /* InitializeConditions for DiscreteIntegrator: '<S95>/Integrator1' */
      Controller_DW.Integrator1_IC_LOADING_e = 1U;

      /* InitializeConditions for DiscreteIntegrator: '<S95>/Integrator' */
      Controller_DW.Integrator_DSTATE_o[0] = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S100>/Discrete-Time Integrator' */
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
        Controller_ConstB.Constant_g;
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] >=
          CONTROL_PARAM.MC_VEL_XY_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
          CONTROL_PARAM.MC_VEL_XY_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] <=
            CONTROL_PARAM.MC_VEL_XY_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
            CONTROL_PARAM.MC_VEL_XY_I_MIN;
        }
      }

      /* InitializeConditions for DiscreteIntegrator: '<S95>/Integrator' */
      Controller_DW.Integrator_DSTATE_o[1] = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S100>/Discrete-Time Integrator' */
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
        Controller_ConstB.Constant_g;
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] >=
          CONTROL_PARAM.MC_VEL_XY_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
          CONTROL_PARAM.MC_VEL_XY_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] <=
            CONTROL_PARAM.MC_VEL_XY_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
            CONTROL_PARAM.MC_VEL_XY_I_MIN;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_PrevRe_e = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S102>/Discrete-Time Integrator1' */
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_b = 1U;
      Controller_DW.DiscreteTimeIntegrator1_Prev_a4 = 0;
      Controller_DW.Velocity_Controller_MODE = true;
    }

    /* Trigonometry: '<S97>/Trigonometric Function1' incorporates:
     *  Gain: '<S96>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S97>/Trigonometric Function3'
     */
    rtb_Add3 = arm_cos_f32(-Controller_U.INS_Out.psi);
    rtb_VectorConcatenate[0] = rtb_Add3;

    /* Trigonometry: '<S97>/Trigonometric Function' incorporates:
     *  Gain: '<S96>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S97>/Trigonometric Function2'
     */
    rtb_Gain_idx_0 = arm_sin_f32(-Controller_U.INS_Out.psi);
    rtb_VectorConcatenate[1] = rtb_Gain_idx_0;

    /* SignalConversion: '<S97>/ConcatBufferAtVector Concatenate1In3' incorporates:
     *  Constant: '<S97>/Constant3'
     */
    rtb_VectorConcatenate[2] = 0.0F;

    /* Gain: '<S97>/Gain' */
    rtb_VectorConcatenate[3] = -rtb_Gain_idx_0;

    /* Trigonometry: '<S97>/Trigonometric Function3' */
    rtb_VectorConcatenate[4] = rtb_Add3;

    /* SignalConversion: '<S97>/ConcatBufferAtVector Concatenate2In3' incorporates:
     *  Constant: '<S97>/Constant4'
     */
    rtb_VectorConcatenate[5] = 0.0F;

    /* SignalConversion: '<S97>/ConcatBufferAtVector ConcatenateIn3' */
    rtb_VectorConcatenate[6] = Controller_ConstB.VectorConcatenate3[0];
    rtb_VectorConcatenate[7] = Controller_ConstB.VectorConcatenate3[1];
    rtb_VectorConcatenate[8] = Controller_ConstB.VectorConcatenate3[2];

    /* Product: '<S93>/Multiply' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  SignalConversion: '<S93>/TmpSignal ConversionAtMultiplyInport2'
     */
    for (i = 0; i < 3; i++) {
      rtb_DiscreteTimeIntegrator1[i] = rtb_VectorConcatenate[i + 3] *
        Controller_U.INS_Out.ve + rtb_VectorConcatenate[i] *
        Controller_U.INS_Out.vn;
    }

    /* End of Product: '<S93>/Multiply' */

    /* DiscreteIntegrator: '<S95>/Integrator1' */
    if (Controller_DW.Integrator1_IC_LOADING_e != 0) {
      /* Switch: '<S89>/Switch' incorporates:
       *  Constant: '<S94>/Constant'
       *  Inport: '<Root>/INS_Out'
       *  RelationalOperator: '<S94>/Compare'
       *  S-Function (sfix_bitop): '<S89>/vel_valid'
       */
      if ((Controller_U.INS_Out.flag & 16U) == 0U) {
        Controller_DW.Integrator1_DSTATE_g[0] = Controller_U.FMS_Out.u_cmd;
        Controller_DW.Integrator1_DSTATE_g[1] = Controller_U.FMS_Out.v_cmd;
      } else {
        Controller_DW.Integrator1_DSTATE_g[0] = rtb_DiscreteTimeIntegrator1[0];
        Controller_DW.Integrator1_DSTATE_g[1] = rtb_DiscreteTimeIntegrator1[1];
      }

      /* End of Switch: '<S89>/Switch' */
    }

    /* Product: '<S98>/Multiply1' incorporates:
     *  Constant: '<S98>/const1'
     *  DiscreteIntegrator: '<S95>/Integrator'
     */
    rtb_Switch_mh_idx_0 = Controller_DW.Integrator_DSTATE_o[0] * 0.05F;
    rtb_Switch_mh_idx_1 = Controller_DW.Integrator_DSTATE_o[1] * 0.05F;

    /* Sum: '<S98>/Add' incorporates:
     *  DiscreteIntegrator: '<S95>/Integrator1'
     *  Sum: '<S95>/Subtract'
     */
    rtb_att_error_B_rad_idx_0 = (Controller_DW.Integrator1_DSTATE_g[0] -
      Controller_U.FMS_Out.u_cmd) + rtb_Switch_mh_idx_0;
    rtb_att_error_B_rad_idx_1 = (Controller_DW.Integrator1_DSTATE_g[1] -
      Controller_U.FMS_Out.v_cmd) + rtb_Switch_mh_idx_1;

    /* Signum: '<S98>/Sign' */
    if (rtb_att_error_B_rad_idx_0 < 0.0F) {
      rtb_Add3 = -1.0F;
    } else if (rtb_att_error_B_rad_idx_0 > 0.0F) {
      rtb_Add3 = 1.0F;
    } else {
      rtb_Add3 = rtb_att_error_B_rad_idx_0;
    }

    /* Sum: '<S98>/Add2' incorporates:
     *  Abs: '<S98>/Abs'
     *  Gain: '<S98>/Gain'
     *  Gain: '<S98>/Gain1'
     *  Product: '<S98>/Multiply2'
     *  Product: '<S98>/Multiply3'
     *  Signum: '<S98>/Sign'
     *  Sqrt: '<S98>/Sqrt'
     *  Sum: '<S98>/Add1'
     *  Sum: '<S98>/Subtract'
     */
    rtb_Gain_idx_0 = (sqrtf((8.0F * fabsf(rtb_att_error_B_rad_idx_0) +
      Controller_ConstB.d_e) * Controller_ConstB.d_e) - Controller_ConstB.d_e) *
      0.5F * rtb_Add3 + rtb_Switch_mh_idx_0;

    /* Sum: '<S98>/Add3' incorporates:
     *  Signum: '<S98>/Sign'
     */
    rtb_Add3 = rtb_att_error_B_rad_idx_0 + Controller_ConstB.d_e;

    /* Sum: '<S98>/Subtract1' incorporates:
     *  Signum: '<S98>/Sign'
     */
    rtb_DiscreteTimeIntegrator1_a = rtb_att_error_B_rad_idx_0 -
      Controller_ConstB.d_e;

    /* Signum: '<S98>/Sign1' */
    if (rtb_Add3 < 0.0F) {
      rtb_Add3 = -1.0F;
    } else {
      if (rtb_Add3 > 0.0F) {
        rtb_Add3 = 1.0F;
      }
    }

    /* Signum: '<S98>/Sign2' */
    if (rtb_DiscreteTimeIntegrator1_a < 0.0F) {
      rtb_DiscreteTimeIntegrator1_a = -1.0F;
    } else {
      if (rtb_DiscreteTimeIntegrator1_a > 0.0F) {
        rtb_DiscreteTimeIntegrator1_a = 1.0F;
      }
    }

    /* Sum: '<S98>/Add2' incorporates:
     *  Gain: '<S98>/Gain2'
     *  Product: '<S98>/Multiply4'
     *  Signum: '<S98>/Sign'
     *  Sum: '<S98>/Add4'
     *  Sum: '<S98>/Add5'
     *  Sum: '<S98>/Subtract2'
     */
    rtb_Switch_mh_idx_0 = ((rtb_att_error_B_rad_idx_0 - rtb_Gain_idx_0) +
      rtb_Switch_mh_idx_0) * ((rtb_Add3 - rtb_DiscreteTimeIntegrator1_a) * 0.5F)
      + rtb_Gain_idx_0;
    rtb_Sign1_f_idx_0 = Controller_DW.Integrator1_DSTATE_g[0] -
      rtb_DiscreteTimeIntegrator1[0];

    /* Signum: '<S98>/Sign' incorporates:
     *  DiscreteIntegrator: '<S95>/Integrator1'
     *  Signum: '<S98>/Sign1'
     *  Sum: '<S89>/Sum'
     */
    if (rtb_att_error_B_rad_idx_1 < 0.0F) {
      rtb_Add3 = -1.0F;
    } else if (rtb_att_error_B_rad_idx_1 > 0.0F) {
      rtb_Add3 = 1.0F;
    } else {
      rtb_Add3 = rtb_att_error_B_rad_idx_1;
    }

    /* Sum: '<S98>/Add2' incorporates:
     *  Abs: '<S98>/Abs'
     *  Gain: '<S98>/Gain'
     *  Gain: '<S98>/Gain1'
     *  Product: '<S98>/Multiply2'
     *  Product: '<S98>/Multiply3'
     *  Signum: '<S98>/Sign'
     *  Sqrt: '<S98>/Sqrt'
     *  Sum: '<S98>/Add1'
     *  Sum: '<S98>/Subtract'
     */
    rtb_Gain_idx_0 = (sqrtf((8.0F * fabsf(rtb_att_error_B_rad_idx_1) +
      Controller_ConstB.d_e) * Controller_ConstB.d_e) - Controller_ConstB.d_e) *
      0.5F * rtb_Add3 + rtb_Switch_mh_idx_1;

    /* Sum: '<S98>/Add3' incorporates:
     *  Signum: '<S98>/Sign'
     */
    rtb_Add3 = rtb_att_error_B_rad_idx_1 + Controller_ConstB.d_e;

    /* Sum: '<S98>/Subtract1' incorporates:
     *  Signum: '<S98>/Sign'
     */
    rtb_DiscreteTimeIntegrator1_a = rtb_att_error_B_rad_idx_1 -
      Controller_ConstB.d_e;

    /* Signum: '<S98>/Sign1' */
    if (rtb_Add3 < 0.0F) {
      rtb_Add3 = -1.0F;
    } else {
      if (rtb_Add3 > 0.0F) {
        rtb_Add3 = 1.0F;
      }
    }

    /* Signum: '<S98>/Sign2' */
    if (rtb_DiscreteTimeIntegrator1_a < 0.0F) {
      rtb_DiscreteTimeIntegrator1_a = -1.0F;
    } else {
      if (rtb_DiscreteTimeIntegrator1_a > 0.0F) {
        rtb_DiscreteTimeIntegrator1_a = 1.0F;
      }
    }

    /* Sum: '<S98>/Add5' incorporates:
     *  Gain: '<S98>/Gain2'
     *  Product: '<S98>/Multiply4'
     *  Signum: '<S98>/Sign'
     *  Sum: '<S98>/Add2'
     *  Sum: '<S98>/Add4'
     *  Sum: '<S98>/Subtract2'
     */
    rtb_Gain_idx_0 += ((rtb_att_error_B_rad_idx_1 - rtb_Gain_idx_0) +
                       rtb_Switch_mh_idx_1) * ((rtb_Add3 -
      rtb_DiscreteTimeIntegrator1_a) * 0.5F);

    /* Sum: '<S89>/Sum' incorporates:
     *  DiscreteIntegrator: '<S95>/Integrator1'
     */
    rtb_Switch_mh_idx_1 = Controller_DW.Integrator1_DSTATE_g[1] -
      rtb_DiscreteTimeIntegrator1[1];

    /* DiscreteIntegrator: '<S100>/Discrete-Time Integrator' */
    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator_PrevRe_e != 0)) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
        Controller_ConstB.Constant_g;
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] >=
          CONTROL_PARAM.MC_VEL_XY_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
          CONTROL_PARAM.MC_VEL_XY_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] <=
            CONTROL_PARAM.MC_VEL_XY_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
            CONTROL_PARAM.MC_VEL_XY_I_MIN;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
        Controller_ConstB.Constant_g;
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] >=
          CONTROL_PARAM.MC_VEL_XY_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
          CONTROL_PARAM.MC_VEL_XY_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] <=
            CONTROL_PARAM.MC_VEL_XY_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
            CONTROL_PARAM.MC_VEL_XY_I_MIN;
        }
      }
    }

    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] >=
        CONTROL_PARAM.MC_VEL_XY_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
        CONTROL_PARAM.MC_VEL_XY_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] <=
          CONTROL_PARAM.MC_VEL_XY_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
          CONTROL_PARAM.MC_VEL_XY_I_MIN;
      }
    }

    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] >=
        CONTROL_PARAM.MC_VEL_XY_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
        CONTROL_PARAM.MC_VEL_XY_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] <=
          CONTROL_PARAM.MC_VEL_XY_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
          CONTROL_PARAM.MC_VEL_XY_I_MIN;
      }
    }

    /* DiscreteIntegrator: '<S102>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_b != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[0] = rtb_Sign1_f_idx_0;
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[1] = rtb_Switch_mh_idx_1;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_Prev_a4 != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[0] = rtb_Sign1_f_idx_0;
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[1] = rtb_Switch_mh_idx_1;
    }

    /* Gain: '<S102>/Gain' incorporates:
     *  DiscreteIntegrator: '<S102>/Discrete-Time Integrator1'
     *  Sum: '<S102>/Sum5'
     */
    rtb_Gain_j_idx_0 = (rtb_Sign1_f_idx_0 -
                        Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[0]) *
      62.831852F;
    rtb_Gain_j_idx_1 = (rtb_Switch_mh_idx_1 -
                        Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[1]) *
      62.831852F;

    /* Switch: '<S102>/Switch' incorporates:
     *  Gain: '<S102>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_att_error_B_rad_idx_0 = 0.0F;
      rtb_att_error_B_rad_idx_1 = 0.0F;
    } else {
      rtb_att_error_B_rad_idx_0 = rtb_Gain_j_idx_0;
      rtb_att_error_B_rad_idx_1 = rtb_Gain_j_idx_1;
    }

    /* End of Switch: '<S102>/Switch' */

    /* Product: '<S99>/Multiply' incorporates:
     *  Constant: '<S99>/kd'
     */
    rtb_DiscreteTimeIntegrator1_a = CONTROL_PARAM.MC_VEL_XY_D *
      rtb_att_error_B_rad_idx_0;

    /* Saturate: '<S99>/Saturation' */
    if (rtb_DiscreteTimeIntegrator1_a > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
      rtb_DiscreteTimeIntegrator1_a = CONTROL_PARAM.MC_VEL_XY_D_MAX;
    } else {
      if (rtb_DiscreteTimeIntegrator1_a < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
        rtb_DiscreteTimeIntegrator1_a = CONTROL_PARAM.MC_VEL_XY_D_MIN;
      }
    }

    rtb_att_error_B_rad_idx_0 = rtb_DiscreteTimeIntegrator1_a;

    /* Product: '<S99>/Multiply' incorporates:
     *  Constant: '<S99>/kd'
     */
    rtb_DiscreteTimeIntegrator1_a = CONTROL_PARAM.MC_VEL_XY_D *
      rtb_att_error_B_rad_idx_1;

    /* Saturate: '<S99>/Saturation' */
    if (rtb_DiscreteTimeIntegrator1_a > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
      rtb_DiscreteTimeIntegrator1_a = CONTROL_PARAM.MC_VEL_XY_D_MAX;
    } else {
      if (rtb_DiscreteTimeIntegrator1_a < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
        rtb_DiscreteTimeIntegrator1_a = CONTROL_PARAM.MC_VEL_XY_D_MIN;
      }
    }

    /* Switch: '<S91>/Switch' incorporates:
     *  Constant: '<S101>/kp'
     *  Constant: '<S103>/Constant'
     *  Constant: '<S105>/Constant'
     *  Constant: '<S106>/Constant'
     *  DiscreteIntegrator: '<S100>/Discrete-Time Integrator'
     *  Product: '<S101>/Multiply'
     *  Product: '<S104>/Multiply2'
     *  Product: '<S104>/Multiply3'
     *  RelationalOperator: '<S103>/Compare'
     *  RelationalOperator: '<S105>/Compare'
     *  RelationalOperator: '<S106>/Compare'
     *  S-Function (sfix_bitop): '<S104>/cmd_ax valid'
     *  S-Function (sfix_bitop): '<S104>/cmd_ay valid'
     *  S-Function (sfix_bitop): '<S104>/cmd_u valid'
     *  S-Function (sfix_bitop): '<S104>/cmd_v valid'
     *  Sum: '<S104>/Sum1'
     *  Sum: '<S90>/Add'
     */
    if (Controller_U.FMS_Out.ctrl_mode == 6) {
      rtb_att_error_B_rad_idx_0 = ((Controller_U.FMS_Out.cmd_mask & 64) > 0 ?
        (CONTROL_PARAM.MC_VEL_XY_P * rtb_Sign1_f_idx_0 +
         Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0]) +
        rtb_att_error_B_rad_idx_0 : 0.0F) + ((Controller_U.FMS_Out.cmd_mask &
        512) > 0 ? Controller_U.FMS_Out.ax_cmd : 0.0F);
      rtb_att_error_B_rad_idx_1 = ((Controller_U.FMS_Out.cmd_mask & 128) > 0 ?
        (CONTROL_PARAM.MC_VEL_XY_P * rtb_Switch_mh_idx_1 +
         Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1]) +
        rtb_DiscreteTimeIntegrator1_a : 0.0F) + ((Controller_U.FMS_Out.cmd_mask
        & 1024) > 0 ? Controller_U.FMS_Out.ay_cmd : 0.0F);
    } else {
      rtb_att_error_B_rad_idx_0 += CONTROL_PARAM.MC_VEL_XY_P * rtb_Sign1_f_idx_0
        + Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0];
      rtb_att_error_B_rad_idx_1 = (CONTROL_PARAM.MC_VEL_XY_P *
        rtb_Switch_mh_idx_1 + Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1])
        + rtb_DiscreteTimeIntegrator1_a;
    }

    /* End of Switch: '<S91>/Switch' */
    rtb_att_error_B_rad_idx_0 *= 1.1F;

    /* Gain: '<S87>/gain' */
    rtb_DiscreteTimeIntegrator1_a = 1.1F * rtb_att_error_B_rad_idx_1;

    /* Update for DiscreteIntegrator: '<S95>/Integrator1' */
    Controller_DW.Integrator1_IC_LOADING_e = 0U;

    /* Update for DiscreteIntegrator: '<S100>/Discrete-Time Integrator' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.DiscreteTimeIntegrator_PrevRe_e = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S102>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_b = 0U;

    /* Trigonometry: '<S87>/Atan' incorporates:
     *  Product: '<S87>/Divide'
     */
    rtb_Add3 = atanf(rtb_DiscreteTimeIntegrator1_a / 9.8055F);

    /* Saturate: '<S87>/Saturation' */
    if (rtb_Add3 > CONTROL_PARAM.MC_ROLL_PITCH_LIM) {
      Controller_B.Saturation_c[0] = CONTROL_PARAM.MC_ROLL_PITCH_LIM;
    } else if (rtb_Add3 < -CONTROL_PARAM.MC_ROLL_PITCH_LIM) {
      Controller_B.Saturation_c[0] = -CONTROL_PARAM.MC_ROLL_PITCH_LIM;
    } else {
      Controller_B.Saturation_c[0] = rtb_Add3;
    }

    /* Update for DiscreteIntegrator: '<S95>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S95>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_g[0] += 0.002F *
      Controller_DW.Integrator_DSTATE_o[0];

    /* Signum: '<S98>/Sign3' incorporates:
     *  Product: '<S98>/Divide'
     *  Sum: '<S98>/Add6'
     */
    rtb_Add3 = rtb_Switch_mh_idx_0 + Controller_ConstB.d_e;

    /* Signum: '<S98>/Sign4' incorporates:
     *  Product: '<S98>/Divide'
     *  Sum: '<S98>/Subtract3'
     */
    rtb_att_error_B_rad_idx_1 = rtb_Switch_mh_idx_0 - Controller_ConstB.d_e;

    /* Signum: '<S98>/Sign5' incorporates:
     *  Product: '<S98>/Divide'
     */
    if (rtb_Switch_mh_idx_0 < 0.0F) {
      rtb_DiscreteTimeIntegrator_i_id = -1.0F;
    } else if (rtb_Switch_mh_idx_0 > 0.0F) {
      rtb_DiscreteTimeIntegrator_i_id = 1.0F;
    } else {
      rtb_DiscreteTimeIntegrator_i_id = rtb_Switch_mh_idx_0;
    }

    /* Signum: '<S98>/Sign3' */
    if (rtb_Add3 < 0.0F) {
      rtb_Add3 = -1.0F;
    } else {
      if (rtb_Add3 > 0.0F) {
        rtb_Add3 = 1.0F;
      }
    }

    /* Signum: '<S98>/Sign4' */
    if (rtb_att_error_B_rad_idx_1 < 0.0F) {
      rtb_att_error_B_rad_idx_1 = -1.0F;
    } else {
      if (rtb_att_error_B_rad_idx_1 > 0.0F) {
        rtb_att_error_B_rad_idx_1 = 1.0F;
      }
    }

    /* Signum: '<S98>/Sign6' incorporates:
     *  Product: '<S98>/Divide'
     */
    if (rtb_Switch_mh_idx_0 < 0.0F) {
      rtb_DiscreteTimeIntegrator_i__0 = -1.0F;
    } else if (rtb_Switch_mh_idx_0 > 0.0F) {
      rtb_DiscreteTimeIntegrator_i__0 = 1.0F;
    } else {
      rtb_DiscreteTimeIntegrator_i__0 = rtb_Switch_mh_idx_0;
    }

    /* Update for DiscreteIntegrator: '<S95>/Integrator' incorporates:
     *  Constant: '<S98>/const'
     *  Gain: '<S98>/Gain3'
     *  Product: '<S98>/Divide'
     *  Product: '<S98>/Multiply5'
     *  Product: '<S98>/Multiply6'
     *  Sum: '<S98>/Subtract4'
     *  Sum: '<S98>/Subtract5'
     *  Sum: '<S98>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE_o[0] += ((rtb_Switch_mh_idx_0 /
      Controller_ConstB.d_e - rtb_DiscreteTimeIntegrator_i_id) *
      Controller_ConstB.Gain4_d * ((rtb_Add3 - rtb_att_error_B_rad_idx_1) * 0.5F)
      - rtb_DiscreteTimeIntegrator_i__0 * 58.836F) * 0.002F;

    /* Update for DiscreteIntegrator: '<S100>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S100>/ki'
     *  Product: '<S100>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] +=
      CONTROL_PARAM.MC_VEL_XY_I * rtb_Sign1_f_idx_0 * 0.002F;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] >=
        CONTROL_PARAM.MC_VEL_XY_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
        CONTROL_PARAM.MC_VEL_XY_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] <=
          CONTROL_PARAM.MC_VEL_XY_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
          CONTROL_PARAM.MC_VEL_XY_I_MIN;
      }
    }

    /* Update for DiscreteIntegrator: '<S102>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[0] += 0.002F *
      rtb_Gain_j_idx_0;

    /* Trigonometry: '<S87>/Atan' incorporates:
     *  Gain: '<S87>/Gain1'
     *  Math: '<S92>/Square'
     *  Product: '<S87>/Divide'
     *  Sqrt: '<S92>/Sqrt'
     *  Sum: '<S92>/Sum of Elements'
     */
    rtb_Add3 = atanf(-rtb_att_error_B_rad_idx_0 / sqrtf
                     (rtb_DiscreteTimeIntegrator1_a *
                      rtb_DiscreteTimeIntegrator1_a + 96.1478271F));

    /* Saturate: '<S87>/Saturation' */
    if (rtb_Add3 > CONTROL_PARAM.MC_ROLL_PITCH_LIM) {
      Controller_B.Saturation_c[1] = CONTROL_PARAM.MC_ROLL_PITCH_LIM;
    } else if (rtb_Add3 < -CONTROL_PARAM.MC_ROLL_PITCH_LIM) {
      Controller_B.Saturation_c[1] = -CONTROL_PARAM.MC_ROLL_PITCH_LIM;
    } else {
      Controller_B.Saturation_c[1] = rtb_Add3;
    }

    /* Update for DiscreteIntegrator: '<S95>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S95>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_g[1] += 0.002F *
      Controller_DW.Integrator_DSTATE_o[1];

    /* Signum: '<S98>/Sign3' incorporates:
     *  Sum: '<S98>/Add6'
     */
    rtb_Add3 = rtb_Gain_idx_0 + Controller_ConstB.d_e;

    /* Signum: '<S98>/Sign4' incorporates:
     *  Sum: '<S98>/Subtract3'
     */
    rtb_att_error_B_rad_idx_1 = rtb_Gain_idx_0 - Controller_ConstB.d_e;

    /* Signum: '<S98>/Sign5' */
    if (rtb_Gain_idx_0 < 0.0F) {
      rtb_Switch_mh_idx_0 = -1.0F;
    } else if (rtb_Gain_idx_0 > 0.0F) {
      rtb_Switch_mh_idx_0 = 1.0F;
    } else {
      rtb_Switch_mh_idx_0 = rtb_Gain_idx_0;
    }

    /* Signum: '<S98>/Sign3' */
    if (rtb_Add3 < 0.0F) {
      rtb_Add3 = -1.0F;
    } else {
      if (rtb_Add3 > 0.0F) {
        rtb_Add3 = 1.0F;
      }
    }

    /* Signum: '<S98>/Sign4' */
    if (rtb_att_error_B_rad_idx_1 < 0.0F) {
      rtb_att_error_B_rad_idx_1 = -1.0F;
    } else {
      if (rtb_att_error_B_rad_idx_1 > 0.0F) {
        rtb_att_error_B_rad_idx_1 = 1.0F;
      }
    }

    /* Signum: '<S98>/Sign6' */
    if (rtb_Gain_idx_0 < 0.0F) {
      rtb_DiscreteTimeIntegrator1_a = -1.0F;
    } else if (rtb_Gain_idx_0 > 0.0F) {
      rtb_DiscreteTimeIntegrator1_a = 1.0F;
    } else {
      rtb_DiscreteTimeIntegrator1_a = rtb_Gain_idx_0;
    }

    /* Update for DiscreteIntegrator: '<S95>/Integrator' incorporates:
     *  Constant: '<S98>/const'
     *  Gain: '<S98>/Gain3'
     *  Product: '<S98>/Divide'
     *  Product: '<S98>/Multiply5'
     *  Product: '<S98>/Multiply6'
     *  Sum: '<S98>/Subtract4'
     *  Sum: '<S98>/Subtract5'
     *  Sum: '<S98>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE_o[1] += ((rtb_Gain_idx_0 /
      Controller_ConstB.d_e - rtb_Switch_mh_idx_0) * Controller_ConstB.Gain4_d *
      ((rtb_Add3 - rtb_att_error_B_rad_idx_1) * 0.5F) -
      rtb_DiscreteTimeIntegrator1_a * 58.836F) * 0.002F;

    /* Update for DiscreteIntegrator: '<S100>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S100>/ki'
     *  Product: '<S100>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] +=
      CONTROL_PARAM.MC_VEL_XY_I * rtb_Switch_mh_idx_1 * 0.002F;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] >=
        CONTROL_PARAM.MC_VEL_XY_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
        CONTROL_PARAM.MC_VEL_XY_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] <=
          CONTROL_PARAM.MC_VEL_XY_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
          CONTROL_PARAM.MC_VEL_XY_I_MIN;
      }
    }

    /* Update for DiscreteIntegrator: '<S102>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_m[1] += 0.002F *
      rtb_Gain_j_idx_1;
    Controller_DW.DiscreteTimeIntegrator1_Prev_a4 = (int8_T)
      (Controller_U.FMS_Out.reset > 0);
  } else {
    if (Controller_DW.Velocity_Controller_MODE) {
      Controller_DW.Velocity_Controller_MODE = false;
    }
  }

  /* End of RelationalOperator: '<S56>/Compare' */
  /* End of Outputs for SubSystem: '<S5>/Velocity_Controller' */

  /* Switch: '<S78>/Switch' incorporates:
   *  Constant: '<S85>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  Logic: '<S78>/Logical Operator'
   *  RelationalOperator: '<S84>/Compare'
   *  RelationalOperator: '<S85>/Compare'
   *  Switch: '<S78>/Switch1'
   */
  if ((Controller_U.FMS_Out.ctrl_mode == 3) || (Controller_U.FMS_Out.ctrl_mode ==
       4)) {
    att_cmd_B_rad[0] = Controller_U.FMS_Out.phi_cmd;
    att_cmd_B_rad[1] = Controller_U.FMS_Out.theta_cmd;
  } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
    /* Switch: '<S86>/Switch' incorporates:
     *  S-Function (sfix_bitop): '<S86>/cmd_phi valid'
     *  S-Function (sfix_bitop): '<S86>/cmd_theta valid'
     *  Switch: '<S78>/Switch1'
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

    /* End of Switch: '<S86>/Switch' */
  } else {
    /* Switch: '<S78>/Switch1' */
    att_cmd_B_rad[0] = Controller_B.Saturation_c[0];
    att_cmd_B_rad[1] = Controller_B.Saturation_c[1];
  }

  /* End of Switch: '<S78>/Switch' */

  /* SignalConversion: '<S81>/Signal Copy' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  att_est_B_rad[0] = Controller_U.INS_Out.phi;
  att_est_B_rad[1] = Controller_U.INS_Out.theta;

  /* Sum: '<S79>/Sum' */
  rtb_DiscreteTimeIntegrator1_a = att_cmd_B_rad[0] - att_est_B_rad[0];

  /* Product: '<S82>/Divide1' incorporates:
   *  Abs: '<S82>/Abs'
   *  Constant: '<S82>/const2'
   */
  rtb_Gain_idx_0 = fabsf(rtb_DiscreteTimeIntegrator1_a) / 0.002F;

  /* Product: '<S82>/Divide' incorporates:
   *  Constant: '<S80>/Constant1'
   *  Constant: '<S82>/const1'
   *  Math: '<S82>/Square'
   *  SignalConversion: '<S82>/TmpSignal ConversionAtSquareInport1'
   */
  rtb_Add3 = 9.5993F / (CONTROL_PARAM.MC_ROLL_P * CONTROL_PARAM.MC_ROLL_P);

  /* Signum: '<S82>/Sign' */
  if (rtb_DiscreteTimeIntegrator1_a < 0.0F) {
    rtb_att_error_B_rad_idx_1 = -1.0F;
  } else if (rtb_DiscreteTimeIntegrator1_a > 0.0F) {
    rtb_att_error_B_rad_idx_1 = 1.0F;
  } else {
    rtb_att_error_B_rad_idx_1 = rtb_DiscreteTimeIntegrator1_a;
  }

  /* Switch: '<S82>/Switch' incorporates:
   *  Constant: '<S80>/Constant1'
   *  Gain: '<S82>/Gain1'
   *  Gain: '<S82>/Gain2'
   *  Logic: '<S82>/Logical Operator'
   *  Product: '<S82>/Multiply'
   *  Product: '<S82>/Multiply1'
   *  Product: '<S82>/Multiply2'
   *  Product: '<S82>/Multiply3'
   *  RelationalOperator: '<S82>/Relational Operator'
   *  RelationalOperator: '<S82>/Relational Operator2'
   *  SignalConversion: '<S82>/TmpSignal ConversionAtSquareInport1'
   *  Sqrt: '<S82>/Sqrt'
   *  Sum: '<S82>/Subtract'
   */
  if ((rtb_DiscreteTimeIntegrator1_a <= rtb_Add3) &&
      (rtb_DiscreteTimeIntegrator1_a >= -rtb_Add3)) {
    rtb_att_error_B_rad_idx_1 = rtb_DiscreteTimeIntegrator1_a *
      CONTROL_PARAM.MC_ROLL_P;
  } else {
    rtb_att_error_B_rad_idx_1 *= sqrtf((rtb_att_error_B_rad_idx_1 *
      rtb_DiscreteTimeIntegrator1_a - 0.5F * rtb_Add3) * Controller_ConstB.Gain);
  }

  /* Gain: '<S82>/Gain3' */
  rtb_Add3 = -rtb_Gain_idx_0;

  /* Switch: '<S83>/Switch' incorporates:
   *  Gain: '<S82>/Gain3'
   *  RelationalOperator: '<S83>/UpperRelop'
   */
  if (rtb_att_error_B_rad_idx_1 >= -rtb_Gain_idx_0) {
    rtb_Add3 = rtb_att_error_B_rad_idx_1;
  }

  /* Switch: '<S83>/Switch2' incorporates:
   *  RelationalOperator: '<S83>/LowerRelop1'
   */
  if (rtb_att_error_B_rad_idx_1 <= rtb_Gain_idx_0) {
    rtb_Gain_idx_0 = rtb_Add3;
  }

  /* Saturate: '<S61>/Saturation1' */
  if (rtb_Gain_idx_0 > CONTROL_PARAM.MC_RATE_XY_LIM) {
    rtb_Gain_idx_0 = CONTROL_PARAM.MC_RATE_XY_LIM;
  } else {
    if (rtb_Gain_idx_0 < -CONTROL_PARAM.MC_RATE_XY_LIM) {
      rtb_Gain_idx_0 = -CONTROL_PARAM.MC_RATE_XY_LIM;
    }
  }

  /* Product: '<S82>/Divide1' */
  rtb_Switch_mh_idx_0 = rtb_Gain_idx_0;

  /* Sum: '<S79>/Sum' */
  rtb_DiscreteTimeIntegrator1_a = att_cmd_B_rad[1] - att_est_B_rad[1];

  /* Product: '<S82>/Divide1' incorporates:
   *  Abs: '<S82>/Abs'
   *  Constant: '<S82>/const2'
   */
  rtb_Gain_idx_0 = fabsf(rtb_DiscreteTimeIntegrator1_a) / 0.002F;

  /* Product: '<S82>/Divide' incorporates:
   *  Constant: '<S80>/Constant2'
   *  Constant: '<S82>/const1'
   *  Math: '<S82>/Square'
   *  SignalConversion: '<S82>/TmpSignal ConversionAtSquareInport1'
   */
  rtb_Add3 = 9.5993F / (CONTROL_PARAM.MC_PITCH_P * CONTROL_PARAM.MC_PITCH_P);

  /* Signum: '<S82>/Sign' */
  if (rtb_DiscreteTimeIntegrator1_a < 0.0F) {
    rtb_att_error_B_rad_idx_1 = -1.0F;
  } else if (rtb_DiscreteTimeIntegrator1_a > 0.0F) {
    rtb_att_error_B_rad_idx_1 = 1.0F;
  } else {
    rtb_att_error_B_rad_idx_1 = rtb_DiscreteTimeIntegrator1_a;
  }

  /* Switch: '<S82>/Switch' incorporates:
   *  Constant: '<S80>/Constant2'
   *  Gain: '<S82>/Gain1'
   *  Gain: '<S82>/Gain2'
   *  Logic: '<S82>/Logical Operator'
   *  Product: '<S82>/Multiply'
   *  Product: '<S82>/Multiply1'
   *  Product: '<S82>/Multiply2'
   *  Product: '<S82>/Multiply3'
   *  RelationalOperator: '<S82>/Relational Operator'
   *  RelationalOperator: '<S82>/Relational Operator2'
   *  SignalConversion: '<S82>/TmpSignal ConversionAtSquareInport1'
   *  Sqrt: '<S82>/Sqrt'
   *  Sum: '<S82>/Subtract'
   */
  if ((rtb_DiscreteTimeIntegrator1_a <= rtb_Add3) &&
      (rtb_DiscreteTimeIntegrator1_a >= -rtb_Add3)) {
    rtb_att_error_B_rad_idx_1 = rtb_DiscreteTimeIntegrator1_a *
      CONTROL_PARAM.MC_PITCH_P;
  } else {
    rtb_att_error_B_rad_idx_1 *= sqrtf((rtb_att_error_B_rad_idx_1 *
      rtb_DiscreteTimeIntegrator1_a - 0.5F * rtb_Add3) * Controller_ConstB.Gain);
  }

  /* Gain: '<S82>/Gain3' */
  rtb_Add3 = -rtb_Gain_idx_0;

  /* Switch: '<S83>/Switch' incorporates:
   *  Gain: '<S82>/Gain3'
   *  RelationalOperator: '<S83>/UpperRelop'
   */
  if (rtb_att_error_B_rad_idx_1 >= -rtb_Gain_idx_0) {
    rtb_Add3 = rtb_att_error_B_rad_idx_1;
  }

  /* Switch: '<S83>/Switch2' incorporates:
   *  RelationalOperator: '<S83>/LowerRelop1'
   */
  if (rtb_att_error_B_rad_idx_1 <= rtb_Gain_idx_0) {
    rtb_Gain_idx_0 = rtb_Add3;
  }

  /* Saturate: '<S61>/Saturation1' */
  if (rtb_Gain_idx_0 > CONTROL_PARAM.MC_RATE_XY_LIM) {
    rtb_Gain_idx_0 = CONTROL_PARAM.MC_RATE_XY_LIM;
  } else {
    if (rtb_Gain_idx_0 < -CONTROL_PARAM.MC_RATE_XY_LIM) {
      rtb_Gain_idx_0 = -CONTROL_PARAM.MC_RATE_XY_LIM;
    }
  }

  /* Saturate: '<S61>/Saturation' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_U.FMS_Out.psi_rate_cmd > CONTROL_PARAM.MC_RATE_Z_LIM) {
    rtb_Add3 = CONTROL_PARAM.MC_RATE_Z_LIM;
  } else if (Controller_U.FMS_Out.psi_rate_cmd < -CONTROL_PARAM.MC_RATE_Z_LIM) {
    rtb_Add3 = -CONTROL_PARAM.MC_RATE_Z_LIM;
  } else {
    rtb_Add3 = Controller_U.FMS_Out.psi_rate_cmd;
  }

  /* End of Saturate: '<S61>/Saturation' */

  /* Trigonometry: '<S73>/Sin' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_att_error_B_rad_idx_0 = arm_sin_f32(Controller_U.INS_Out.phi);

  /* Trigonometry: '<S73>/Cos1' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_DiscreteTimeIntegrator1_a = arm_cos_f32(Controller_U.INS_Out.theta);

  /* Product: '<S73>/Multiply3' */
  rtb_att_error_B_rad_idx_1 = rtb_att_error_B_rad_idx_0 *
    rtb_DiscreteTimeIntegrator1_a * rtb_Add3;

  /* Trigonometry: '<S73>/Cos' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Sign1_f_idx_0 = arm_cos_f32(Controller_U.INS_Out.phi);

  /* Product: '<S73>/Multiply1' */
  rtb_Switch_mh_idx_1 = rtb_Sign1_f_idx_0 * rtb_Gain_idx_0;

  /* Product: '<S73>/Multiply4' */
  rtb_att_error_B_rad_idx_0 *= rtb_Gain_idx_0;

  /* Switch: '<S62>/Switch' incorporates:
   *  Constant: '<S74>/Constant'
   *  Constant: '<S75>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  RelationalOperator: '<S74>/Compare'
   *  RelationalOperator: '<S75>/Compare'
   *  Switch: '<S62>/Switch1'
   */
  if (Controller_U.FMS_Out.ctrl_mode == 2) {
    rate_cmd_B_radPs[0] = Controller_U.FMS_Out.p_cmd;
    rate_cmd_B_radPs[1] = Controller_U.FMS_Out.q_cmd;
    rate_cmd_B_radPs[2] = Controller_U.FMS_Out.r_cmd;
  } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
    /* Switch: '<S76>/Switch' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S73>/Multiply'
     *  Product: '<S73>/Multiply1'
     *  Product: '<S73>/Multiply5'
     *  S-Function (sfix_bitop): '<S76>/cmd_p valid'
     *  S-Function (sfix_bitop): '<S76>/cmd_q valid'
     *  S-Function (sfix_bitop): '<S76>/cmd_r valid'
     *  Sum: '<S73>/Add'
     *  Sum: '<S73>/Add1'
     *  Sum: '<S73>/Add2'
     *  Switch: '<S62>/Switch1'
     *  Trigonometry: '<S73>/Sin1'
     */
    if ((Controller_U.FMS_Out.cmd_mask & 1) > 0) {
      rate_cmd_B_radPs[0] = Controller_U.FMS_Out.p_cmd;
    } else {
      rate_cmd_B_radPs[0] = rtb_Switch_mh_idx_0 - arm_sin_f32
        (Controller_U.INS_Out.theta) * rtb_Add3;
    }

    if ((Controller_U.FMS_Out.cmd_mask & 2) > 0) {
      rate_cmd_B_radPs[1] = Controller_U.FMS_Out.q_cmd;
    } else {
      rate_cmd_B_radPs[1] = rtb_att_error_B_rad_idx_1 + rtb_Switch_mh_idx_1;
    }

    if ((Controller_U.FMS_Out.cmd_mask & 4) > 0) {
      rate_cmd_B_radPs[2] = Controller_U.FMS_Out.r_cmd;
    } else {
      rate_cmd_B_radPs[2] = rtb_Sign1_f_idx_0 * rtb_DiscreteTimeIntegrator1_a *
        rtb_Add3 - rtb_att_error_B_rad_idx_0;
    }

    /* End of Switch: '<S76>/Switch' */
  } else {
    /* Switch: '<S62>/Switch1' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S73>/Multiply'
     *  Product: '<S73>/Multiply3'
     *  Product: '<S73>/Multiply5'
     *  Sum: '<S73>/Add'
     *  Sum: '<S73>/Add1'
     *  Sum: '<S73>/Add2'
     *  Trigonometry: '<S73>/Sin1'
     */
    rate_cmd_B_radPs[0] = rtb_Switch_mh_idx_0 - arm_sin_f32
      (Controller_U.INS_Out.theta) * rtb_Add3;
    rate_cmd_B_radPs[1] = rtb_Switch_mh_idx_1 + rtb_att_error_B_rad_idx_1;
    rate_cmd_B_radPs[2] = rtb_Sign1_f_idx_0 * rtb_DiscreteTimeIntegrator1_a *
      rtb_Add3 - rtb_att_error_B_rad_idx_0;
  }

  /* End of Switch: '<S62>/Switch' */

  /* SignalConversion: '<S66>/Signal Copy' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rate_est_B_radPs[0] = Controller_U.INS_Out.p;
  rate_est_B_radPs[1] = Controller_U.INS_Out.q;
  rate_est_B_radPs[2] = Controller_U.INS_Out.r;

  /* Sum: '<S63>/Sum' */
  rtb_DiscreteTimeIntegrator1[0] = rate_cmd_B_radPs[0] - rate_est_B_radPs[0];
  rtb_DiscreteTimeIntegrator1[1] = rate_cmd_B_radPs[1] - rate_est_B_radPs[1];
  rtb_DiscreteTimeIntegrator1[2] = rate_cmd_B_radPs[2] - rate_est_B_radPs[2];

  /* DiscreteIntegrator: '<S67>/Discrete-Time Integrator5' */
  if (Controller_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] =
      rtb_DiscreteTimeIntegrator1[0];
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] =
      rtb_DiscreteTimeIntegrator1[1];
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] =
      rtb_DiscreteTimeIntegrator1[2];
  }

  /* DiscreteIntegrator: '<S70>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator_PrevRese != 0)) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = Controller_ConstB.Constant
      [0];
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] >=
        CONTROL_PARAM.MC_RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
        CONTROL_PARAM.MC_RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] <=
          CONTROL_PARAM.MC_RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
          CONTROL_PARAM.MC_RATE_I_MIN;
      }
    }

    Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = Controller_ConstB.Constant
      [1];
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] >=
        CONTROL_PARAM.MC_RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
        CONTROL_PARAM.MC_RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] <=
          CONTROL_PARAM.MC_RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
          CONTROL_PARAM.MC_RATE_I_MIN;
      }
    }

    Controller_DW.DiscreteTimeIntegrator_DSTATE[2] = Controller_ConstB.Constant
      [2];
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[2] >=
        CONTROL_PARAM.MC_RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[2] =
        CONTROL_PARAM.MC_RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE[2] <=
          CONTROL_PARAM.MC_RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE[2] =
          CONTROL_PARAM.MC_RATE_I_MIN;
      }
    }
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] >=
      CONTROL_PARAM.MC_RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = CONTROL_PARAM.MC_RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] <=
        CONTROL_PARAM.MC_RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
        CONTROL_PARAM.MC_RATE_I_MIN;
    }
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] >=
      CONTROL_PARAM.MC_RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = CONTROL_PARAM.MC_RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] <=
        CONTROL_PARAM.MC_RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
        CONTROL_PARAM.MC_RATE_I_MIN;
    }
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[2] >=
      CONTROL_PARAM.MC_RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[2] = CONTROL_PARAM.MC_RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[2] <=
        CONTROL_PARAM.MC_RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[2] =
        CONTROL_PARAM.MC_RATE_I_MIN;
    }
  }

  /* DiscreteIntegrator: '<S72>/Discrete-Time Integrator1' incorporates:
   *  DiscreteIntegrator: '<S67>/Discrete-Time Integrator5'
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

  /* Gain: '<S72>/Gain' incorporates:
   *  DiscreteIntegrator: '<S67>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S72>/Discrete-Time Integrator1'
   *  Sum: '<S72>/Sum5'
   */
  rtb_Gain_idx_0 = (Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] -
                    Controller_DW.DiscreteTimeIntegrator1_DSTATE[0]) *
    188.49556F;
  rtb_Switch_mh_idx_0 = (Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] -
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[1]) * 188.49556F;
  rtb_DiscreteTimeIntegrator1_a = (Controller_DW.DiscreteTimeIntegrator5_DSTATE
    [2] - Controller_DW.DiscreteTimeIntegrator1_DSTATE[2]) * 188.49556F;

  /* Switch: '<S72>/Switch' incorporates:
   *  Gain: '<S72>/Gain1'
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_U.FMS_Out.reset > 0) {
    rtb_att_error_B_rad_idx_1 = 0.0F;
    rtb_att_error_B_rad_idx_0 = 0.0F;
    rtb_Add3 = 0.0F;
  } else {
    rtb_att_error_B_rad_idx_1 = rtb_Gain_idx_0;
    rtb_att_error_B_rad_idx_0 = rtb_Switch_mh_idx_0;
    rtb_Add3 = rtb_DiscreteTimeIntegrator1_a;
  }

  /* End of Switch: '<S72>/Switch' */

  /* Product: '<S69>/Multiply' incorporates:
   *  Constant: '<S69>/gain1'
   */
  rtb_Sign1_f_idx_0 = CONTROL_PARAM.MC_ROLLRATE_D * rtb_att_error_B_rad_idx_1;

  /* Saturate: '<S69>/Saturation' */
  if (rtb_Sign1_f_idx_0 > CONTROL_PARAM.MC_RATE_D_MAX) {
    rtb_Sign1_f_idx_0 = CONTROL_PARAM.MC_RATE_D_MAX;
  } else {
    if (rtb_Sign1_f_idx_0 < CONTROL_PARAM.MC_RATE_D_MIN) {
      rtb_Sign1_f_idx_0 = CONTROL_PARAM.MC_RATE_D_MIN;
    }
  }

  /* Product: '<S69>/Multiply' incorporates:
   *  Constant: '<S69>/gain2'
   */
  rtb_att_error_B_rad_idx_1 = rtb_Sign1_f_idx_0;
  rtb_Sign1_f_idx_0 = CONTROL_PARAM.MC_PITCHRATE_D * rtb_att_error_B_rad_idx_0;

  /* Saturate: '<S69>/Saturation' */
  if (rtb_Sign1_f_idx_0 > CONTROL_PARAM.MC_RATE_D_MAX) {
    rtb_Sign1_f_idx_0 = CONTROL_PARAM.MC_RATE_D_MAX;
  } else {
    if (rtb_Sign1_f_idx_0 < CONTROL_PARAM.MC_RATE_D_MIN) {
      rtb_Sign1_f_idx_0 = CONTROL_PARAM.MC_RATE_D_MIN;
    }
  }

  /* Product: '<S69>/Multiply' incorporates:
   *  Constant: '<S69>/gain3'
   */
  rtb_att_error_B_rad_idx_0 = rtb_Sign1_f_idx_0;
  rtb_Sign1_f_idx_0 = CONTROL_PARAM.MC_YAWRATE_D * rtb_Add3;

  /* Saturate: '<S69>/Saturation' */
  if (rtb_Sign1_f_idx_0 > CONTROL_PARAM.MC_RATE_D_MAX) {
    rtb_Sign1_f_idx_0 = CONTROL_PARAM.MC_RATE_D_MAX;
  } else {
    if (rtb_Sign1_f_idx_0 < CONTROL_PARAM.MC_RATE_D_MIN) {
      rtb_Sign1_f_idx_0 = CONTROL_PARAM.MC_RATE_D_MIN;
    }
  }

  /* DeadZone: '<S68>/Dead Zone' */
  if (rate_cmd_B_radPs[0] > 0.1F) {
    rtb_Add3 = rate_cmd_B_radPs[0] - 0.1F;
  } else if (rate_cmd_B_radPs[0] >= -0.1F) {
    rtb_Add3 = 0.0F;
  } else {
    rtb_Add3 = rate_cmd_B_radPs[0] - -0.1F;
  }

  /* Sum: '<S60>/Sum' incorporates:
   *  Constant: '<S71>/gain1'
   *  DiscreteIntegrator: '<S67>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S70>/Discrete-Time Integrator'
   *  Gain: '<S64>/Gain'
   *  Gain: '<S68>/Gain'
   *  Product: '<S71>/Multiply'
   *  Sum: '<S65>/Add'
   */
  rtb_Sum[0] = ((CONTROL_PARAM.MC_ROLLRATE_P *
                 Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] +
                 Controller_DW.DiscreteTimeIntegrator_DSTATE[0]) +
                rtb_att_error_B_rad_idx_1) + 1.11111116F * rtb_Add3 *
    CONTROL_PARAM.MC_ROLLRATE_FF;

  /* DeadZone: '<S68>/Dead Zone' */
  if (rate_cmd_B_radPs[1] > 0.1F) {
    rtb_Add3 = rate_cmd_B_radPs[1] - 0.1F;
  } else if (rate_cmd_B_radPs[1] >= -0.1F) {
    rtb_Add3 = 0.0F;
  } else {
    rtb_Add3 = rate_cmd_B_radPs[1] - -0.1F;
  }

  /* Sum: '<S60>/Sum' incorporates:
   *  Constant: '<S71>/gain2'
   *  DiscreteIntegrator: '<S67>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S70>/Discrete-Time Integrator'
   *  Gain: '<S64>/Gain1'
   *  Gain: '<S68>/Gain'
   *  Product: '<S71>/Multiply'
   *  Sum: '<S65>/Add'
   */
  rtb_Sum[1] = ((CONTROL_PARAM.MC_PITCHRATE_P *
                 Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] +
                 Controller_DW.DiscreteTimeIntegrator_DSTATE[1]) +
                rtb_att_error_B_rad_idx_0) + 1.11111116F * rtb_Add3 *
    CONTROL_PARAM.MC_PITCHRATE_FF;

  /* DeadZone: '<S68>/Dead Zone' */
  if (rate_cmd_B_radPs[2] > 0.1F) {
    rtb_Add3 = rate_cmd_B_radPs[2] - 0.1F;
  } else if (rate_cmd_B_radPs[2] >= -0.1F) {
    rtb_Add3 = 0.0F;
  } else {
    rtb_Add3 = rate_cmd_B_radPs[2] - -0.1F;
  }

  /* Sum: '<S60>/Sum' incorporates:
   *  Constant: '<S71>/gain3'
   *  DiscreteIntegrator: '<S67>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S70>/Discrete-Time Integrator'
   *  Gain: '<S64>/Gain2'
   *  Gain: '<S68>/Gain'
   *  Product: '<S71>/Multiply'
   *  Sum: '<S65>/Add'
   */
  rtb_Sum[2] = ((CONTROL_PARAM.MC_YAWRATE_P *
                 Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] +
                 Controller_DW.DiscreteTimeIntegrator_DSTATE[2]) +
                rtb_Sign1_f_idx_0) + 1.11111116F * rtb_Add3 *
    CONTROL_PARAM.MC_YAWRATE_FF;

  /* Outputs for Enabled SubSystem: '<S6>/Veloxity_Z_Controller' incorporates:
   *  EnablePort: '<S109>/Enable'
   */
  /* RelationalOperator: '<S107>/Compare' incorporates:
   *  Constant: '<S107>/Constant'
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_U.FMS_Out.ctrl_mode >= 4) {
    if (!Controller_DW.Veloxity_Z_Controller_MODE) {
      /* InitializeConditions for DiscreteIntegrator: '<S117>/Integrator1' */
      Controller_DW.Integrator1_IC_LOADING = 1U;

      /* InitializeConditions for DiscreteIntegrator: '<S121>/Discrete-Time Integrator' */
      Controller_DW.DiscreteTimeIntegrator_IC_LOADI = 1U;
      Controller_DW.DiscreteTimeIntegrator_PrevRe_d = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S123>/Discrete-Time Integrator1' */
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_f = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevR_a = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S117>/Integrator' */
      Controller_DW.Integrator_DSTATE = 0.0F;
      Controller_DW.Veloxity_Z_Controller_MODE = true;
    }

    /* Product: '<S113>/Multiply' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S113>/Cos'
     *  Trigonometry: '<S113>/Cos1'
     */
    rtb_att_error_B_rad_idx_1 = arm_cos_f32(Controller_U.INS_Out.phi) *
      arm_cos_f32(Controller_U.INS_Out.theta);

    /* Saturate: '<S113>/Saturation1' */
    if (rtb_att_error_B_rad_idx_1 > 1.0F) {
      rtb_Sign1_f_idx_0 = 1.0F;
    } else if (rtb_att_error_B_rad_idx_1 < 0.5F) {
      rtb_Sign1_f_idx_0 = 0.5F;
    } else {
      rtb_Sign1_f_idx_0 = rtb_att_error_B_rad_idx_1;
    }

    /* End of Saturate: '<S113>/Saturation1' */

    /* DiscreteIntegrator: '<S117>/Integrator1' */
    if (Controller_DW.Integrator1_IC_LOADING != 0) {
      /* Switch: '<S114>/Switch' incorporates:
       *  Constant: '<S116>/Constant'
       *  Inport: '<Root>/INS_Out'
       *  RelationalOperator: '<S116>/Compare'
       *  S-Function (sfix_bitop): '<S114>/vel_valid'
       */
      if ((Controller_U.INS_Out.flag & 16U) == 0U) {
        Controller_DW.Integrator1_DSTATE = Controller_U.FMS_Out.w_cmd;
      } else {
        Controller_DW.Integrator1_DSTATE = Controller_U.INS_Out.vd;
      }

      /* End of Switch: '<S114>/Switch' */
    }

    w_cmd_C_mPs = Controller_DW.Integrator1_DSTATE;

    /* End of DiscreteIntegrator: '<S117>/Integrator1' */

    /* SignalConversion: '<S114>/Signal Copy1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    w_est_C_mPs = Controller_U.INS_Out.vd;

    /* Gain: '<S114>/Gain' incorporates:
     *  Sum: '<S114>/Sum1'
     */
    rtb_Switch_mh_idx_1 = -(w_cmd_C_mPs - w_est_C_mPs);

    /* Switch: '<S121>/Switch' incorporates:
     *  Constant: '<S119>/Constant'
     *  Constant: '<S121>/Constant'
     *  Constant: '<S121>/Constant1'
     *  Delay: '<S6>/Delay'
     *  RelationalOperator: '<S119>/Compare'
     */
    if (Controller_DW.Delay_DSTATE < 3) {
      rtb_Add3 = CONTROL_PARAM.MC_VEL_Z_I_MIN;
    } else {
      rtb_Add3 = 0.0F;
    }

    /* End of Switch: '<S121>/Switch' */

    /* DiscreteIntegrator: '<S121>/Discrete-Time Integrator' */
    if (Controller_DW.DiscreteTimeIntegrator_IC_LOADI != 0) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_f = rtb_Add3;
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_f >=
          CONTROL_PARAM.MC_VEL_Z_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_f =
          CONTROL_PARAM.MC_VEL_Z_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_f <=
            CONTROL_PARAM.MC_VEL_Z_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_f =
            CONTROL_PARAM.MC_VEL_Z_I_MIN;
        }
      }
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator_PrevRe_d != 0)) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_f = rtb_Add3;
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_f >=
          CONTROL_PARAM.MC_VEL_Z_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_f =
          CONTROL_PARAM.MC_VEL_Z_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_f <=
            CONTROL_PARAM.MC_VEL_Z_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_f =
            CONTROL_PARAM.MC_VEL_Z_I_MIN;
        }
      }
    }

    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_f >=
        CONTROL_PARAM.MC_VEL_Z_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_f =
        CONTROL_PARAM.MC_VEL_Z_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_f <=
          CONTROL_PARAM.MC_VEL_Z_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_f =
          CONTROL_PARAM.MC_VEL_Z_I_MIN;
      }
    }

    /* DiscreteIntegrator: '<S123>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_f != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_a = rtb_Switch_mh_idx_1;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_a != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_a = rtb_Switch_mh_idx_1;
    }

    /* Gain: '<S123>/Gain' incorporates:
     *  DiscreteIntegrator: '<S123>/Discrete-Time Integrator1'
     *  Sum: '<S123>/Sum5'
     */
    rtb_Gain_j_idx_1 = (rtb_Switch_mh_idx_1 -
                        Controller_DW.DiscreteTimeIntegrator1_DSTAT_a) *
      62.831852F;

    /* Switch: '<S123>/Switch' incorporates:
     *  Gain: '<S123>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_Add3 = 0.0F;
    } else {
      rtb_Add3 = rtb_Gain_j_idx_1;
    }

    /* End of Switch: '<S123>/Switch' */

    /* Product: '<S120>/Multiply' incorporates:
     *  Constant: '<S120>/kd'
     */
    rtb_Add3 *= CONTROL_PARAM.MC_VEL_Z_D;

    /* Saturate: '<S120>/Saturation' */
    if (rtb_Add3 > CONTROL_PARAM.MC_VEL_Z_D_MAX) {
      rtb_Add3 = CONTROL_PARAM.MC_VEL_Z_D_MAX;
    } else {
      if (rtb_Add3 < CONTROL_PARAM.MC_VEL_Z_D_MIN) {
        rtb_Add3 = CONTROL_PARAM.MC_VEL_Z_D_MIN;
      }
    }

    /* End of Saturate: '<S120>/Saturation' */

    /* Gain: '<S113>/Gain' */
    rtb_att_error_B_rad_idx_1 *= 2.0F;

    /* Saturate: '<S113>/Saturation' */
    if (rtb_att_error_B_rad_idx_1 > 1.0F) {
      rtb_att_error_B_rad_idx_1 = 1.0F;
    } else {
      if (rtb_att_error_B_rad_idx_1 < 0.0F) {
        rtb_att_error_B_rad_idx_1 = 0.0F;
      }
    }

    /* End of Saturate: '<S113>/Saturation' */

    /* Sum: '<S109>/Sum' incorporates:
     *  Constant: '<S109>/hover_throttle'
     *  Constant: '<S113>/Constant'
     *  Constant: '<S122>/kp'
     *  DiscreteIntegrator: '<S121>/Discrete-Time Integrator'
     *  Product: '<S113>/Divide'
     *  Product: '<S113>/Multiply1'
     *  Product: '<S122>/Multiply'
     *  Sum: '<S115>/Add'
     */
    Controller_B.Saturation = ((CONTROL_PARAM.MC_VEL_Z_P * rtb_Switch_mh_idx_1 +
      Controller_DW.DiscreteTimeIntegrator_DSTATE_f) + rtb_Add3) * (1.0F /
      rtb_Sign1_f_idx_0) * rtb_att_error_B_rad_idx_1 +
      CONTROL_PARAM.MC_HOVER_THRO;

    /* Saturate: '<S109>/Saturation' */
    if (Controller_B.Saturation > 0.8F) {
      /* Sum: '<S109>/Sum' */
      Controller_B.Saturation = 0.8F;
    } else {
      if (Controller_B.Saturation < 0.2F) {
        /* Sum: '<S109>/Sum' */
        Controller_B.Saturation = 0.2F;
      }
    }

    /* End of Saturate: '<S109>/Saturation' */

    /* Product: '<S118>/Multiply1' incorporates:
     *  Constant: '<S118>/const1'
     *  DiscreteIntegrator: '<S117>/Integrator'
     */
    rtb_Add3 = Controller_DW.Integrator_DSTATE * 0.05F;

    /* Sum: '<S118>/Add' incorporates:
     *  Sum: '<S117>/Subtract'
     */
    rtb_att_error_B_rad_idx_1 = (w_cmd_C_mPs - Controller_U.FMS_Out.w_cmd) +
      rtb_Add3;

    /* Signum: '<S118>/Sign' */
    if (rtb_att_error_B_rad_idx_1 < 0.0F) {
      rtb_att_error_B_rad_idx_0 = -1.0F;
    } else if (rtb_att_error_B_rad_idx_1 > 0.0F) {
      rtb_att_error_B_rad_idx_0 = 1.0F;
    } else {
      rtb_att_error_B_rad_idx_0 = rtb_att_error_B_rad_idx_1;
    }

    /* End of Signum: '<S118>/Sign' */

    /* Sum: '<S118>/Add2' incorporates:
     *  Abs: '<S118>/Abs'
     *  Gain: '<S118>/Gain'
     *  Gain: '<S118>/Gain1'
     *  Product: '<S118>/Multiply2'
     *  Product: '<S118>/Multiply3'
     *  Sqrt: '<S118>/Sqrt'
     *  Sum: '<S118>/Add1'
     *  Sum: '<S118>/Subtract'
     */
    rtb_att_error_B_rad_idx_0 = (sqrtf((8.0F * fabsf(rtb_att_error_B_rad_idx_1)
      + Controller_ConstB.d) * Controller_ConstB.d) - Controller_ConstB.d) *
      0.5F * rtb_att_error_B_rad_idx_0 + rtb_Add3;

    /* Sum: '<S118>/Add4' */
    rtb_Sign1_f_idx_0 = (rtb_att_error_B_rad_idx_1 - rtb_att_error_B_rad_idx_0)
      + rtb_Add3;

    /* Sum: '<S118>/Add3' */
    rtb_Add3 = rtb_att_error_B_rad_idx_1 + Controller_ConstB.d;

    /* Sum: '<S118>/Subtract1' */
    rtb_att_error_B_rad_idx_1 -= Controller_ConstB.d;

    /* Signum: '<S118>/Sign1' */
    if (rtb_Add3 < 0.0F) {
      rtb_Add3 = -1.0F;
    } else {
      if (rtb_Add3 > 0.0F) {
        rtb_Add3 = 1.0F;
      }
    }

    /* End of Signum: '<S118>/Sign1' */

    /* Signum: '<S118>/Sign2' */
    if (rtb_att_error_B_rad_idx_1 < 0.0F) {
      rtb_att_error_B_rad_idx_1 = -1.0F;
    } else {
      if (rtb_att_error_B_rad_idx_1 > 0.0F) {
        rtb_att_error_B_rad_idx_1 = 1.0F;
      }
    }

    /* End of Signum: '<S118>/Sign2' */

    /* Sum: '<S118>/Add5' incorporates:
     *  Gain: '<S118>/Gain2'
     *  Product: '<S118>/Multiply4'
     *  Sum: '<S118>/Subtract2'
     */
    rtb_att_error_B_rad_idx_0 += (rtb_Add3 - rtb_att_error_B_rad_idx_1) * 0.5F *
      rtb_Sign1_f_idx_0;

    /* Update for DiscreteIntegrator: '<S117>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S117>/Integrator'
     */
    Controller_DW.Integrator1_IC_LOADING = 0U;
    Controller_DW.Integrator1_DSTATE += 0.002F * Controller_DW.Integrator_DSTATE;

    /* Update for DiscreteIntegrator: '<S121>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S121>/ki'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S121>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_IC_LOADI = 0U;
    Controller_DW.DiscreteTimeIntegrator_DSTATE_f += CONTROL_PARAM.MC_VEL_Z_I *
      rtb_Switch_mh_idx_1 * 0.002F;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_f >=
        CONTROL_PARAM.MC_VEL_Z_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_f =
        CONTROL_PARAM.MC_VEL_Z_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_f <=
          CONTROL_PARAM.MC_VEL_Z_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_f =
          CONTROL_PARAM.MC_VEL_Z_I_MIN;
      }
    }

    Controller_DW.DiscreteTimeIntegrator_PrevRe_d = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* End of Update for DiscreteIntegrator: '<S121>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S123>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_f = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_a += 0.002F * rtb_Gain_j_idx_1;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_a = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Signum: '<S118>/Sign6' incorporates:
     *  Signum: '<S118>/Sign5'
     */
    if (rtb_att_error_B_rad_idx_0 < 0.0F) {
      rtb_Sign1_f_idx_0 = -1.0F;

      /* Signum: '<S118>/Sign5' */
      rtb_Switch_mh_idx_1 = -1.0F;
    } else if (rtb_att_error_B_rad_idx_0 > 0.0F) {
      rtb_Sign1_f_idx_0 = 1.0F;

      /* Signum: '<S118>/Sign5' */
      rtb_Switch_mh_idx_1 = 1.0F;
    } else {
      rtb_Sign1_f_idx_0 = rtb_att_error_B_rad_idx_0;

      /* Signum: '<S118>/Sign5' */
      rtb_Switch_mh_idx_1 = rtb_att_error_B_rad_idx_0;
    }

    /* End of Signum: '<S118>/Sign6' */

    /* Sum: '<S118>/Add6' */
    rtb_Add3 = rtb_att_error_B_rad_idx_0 + Controller_ConstB.d;

    /* Sum: '<S118>/Subtract3' */
    rtb_att_error_B_rad_idx_1 = rtb_att_error_B_rad_idx_0 - Controller_ConstB.d;

    /* Signum: '<S118>/Sign3' */
    if (rtb_Add3 < 0.0F) {
      rtb_Add3 = -1.0F;
    } else {
      if (rtb_Add3 > 0.0F) {
        rtb_Add3 = 1.0F;
      }
    }

    /* End of Signum: '<S118>/Sign3' */

    /* Signum: '<S118>/Sign4' */
    if (rtb_att_error_B_rad_idx_1 < 0.0F) {
      rtb_att_error_B_rad_idx_1 = -1.0F;
    } else {
      if (rtb_att_error_B_rad_idx_1 > 0.0F) {
        rtb_att_error_B_rad_idx_1 = 1.0F;
      }
    }

    /* End of Signum: '<S118>/Sign4' */

    /* Update for DiscreteIntegrator: '<S117>/Integrator' incorporates:
     *  Constant: '<S118>/const'
     *  Gain: '<S118>/Gain3'
     *  Product: '<S118>/Divide'
     *  Product: '<S118>/Multiply5'
     *  Product: '<S118>/Multiply6'
     *  Sum: '<S118>/Subtract4'
     *  Sum: '<S118>/Subtract5'
     *  Sum: '<S118>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE += ((rtb_att_error_B_rad_idx_0 /
      Controller_ConstB.d - rtb_Switch_mh_idx_1) * Controller_ConstB.Gain4 *
      ((rtb_Add3 - rtb_att_error_B_rad_idx_1) * 0.5F) - rtb_Sign1_f_idx_0 *
      78.448F) * 0.002F;
  } else {
    if (Controller_DW.Veloxity_Z_Controller_MODE) {
      Controller_DW.Veloxity_Z_Controller_MODE = false;
    }
  }

  /* End of RelationalOperator: '<S107>/Compare' */
  /* End of Outputs for SubSystem: '<S6>/Veloxity_Z_Controller' */

  /* Switch: '<S108>/Switch' incorporates:
   *  Bias: '<S108>/Bias'
   *  Constant: '<S110>/Constant'
   *  Constant: '<S111>/Constant'
   *  Gain: '<S108>/Gain'
   *  Inport: '<Root>/FMS_Out'
   *  RelationalOperator: '<S110>/Compare'
   *  RelationalOperator: '<S111>/Compare'
   *  Switch: '<S108>/Switch1'
   */
  if (Controller_U.FMS_Out.ctrl_mode <= 3) {
    rtb_Switch = 0.000999987125F * (real32_T)Controller_U.FMS_Out.throttle_cmd +
      -1.0F;
  } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
    /* Switch: '<S112>/Switch' incorporates:
     *  Bias: '<S112>/Bias'
     *  Gain: '<S112>/Gain'
     *  S-Function (sfix_bitop): '<S112>/cmd_throttle valid'
     *  Switch: '<S108>/Switch1'
     */
    if ((Controller_U.FMS_Out.cmd_mask & 4096) > 0) {
      rtb_Switch = 0.000999987125F * (real32_T)Controller_U.FMS_Out.throttle_cmd
        + -1.0F;
    } else {
      rtb_Switch = Controller_B.Saturation;
    }

    /* End of Switch: '<S112>/Switch' */
  } else {
    /* Switch: '<S108>/Switch1' */
    rtb_Switch = Controller_B.Saturation;
  }

  /* End of Switch: '<S108>/Switch' */

  /* Outputs for Atomic SubSystem: '<S2>/Control_Allocation' */
#if AIRFRAME == 6

  /* Output and update for atomic system: '<S4>/Coxial_Hexacopter_x' */
  {
    real32_T b_max_b;
    int32_T min_index_b;
    int32_T max_index_b;
    real32_T rtb_Saturation2;
    real32_T rtb_Multiply2_l[12];
    real32_T rtb_Saturation4[12];
    uint16_T rtb_MultiportSwitch[12];
    int32_T k_b;
    real32_T rtb_Saturation1_p_idx_2_b;
    real32_T rtb_Saturation1_p_idx_0_b;
    real32_T rtb_Saturation1_p_idx_1_b;
    real32_T rtb_Multiply2_l;

    /* Saturate: '<S7>/Saturation1' */
    if (rtb_Sum[0] > 1.0F) {
      rtb_Saturation1_p_idx_0_b = 1.0F;
    } else if (rtb_Sum[0] < -1.0F) {
      rtb_Saturation1_p_idx_0_b = -1.0F;
    } else {
      rtb_Saturation1_p_idx_0_b = rtb_Sum[0];
    }

    if (rtb_Sum[1] > 1.0F) {
      rtb_Saturation1_p_idx_1_b = 1.0F;
    } else if (rtb_Sum[1] < -1.0F) {
      rtb_Saturation1_p_idx_1_b = -1.0F;
    } else {
      rtb_Saturation1_p_idx_1_b = rtb_Sum[1];
    }

    if (rtb_Sum[2] > 1.0F) {
      rtb_Saturation1_p_idx_2_b = 1.0F;
    } else if (rtb_Sum[2] < -1.0F) {
      rtb_Saturation1_p_idx_2_b = -1.0F;
    } else {
      rtb_Saturation1_p_idx_2_b = rtb_Sum[2];
    }

    /* End of Saturate: '<S7>/Saturation1' */

    /* Saturate: '<S7>/Saturation2' */
    if (rtb_Switch > 1.0F) {
      rtb_Saturation2 = 1.0F;
    } else if (rtb_Switch < 0.0F) {
      rtb_Saturation2 = 0.0F;
    } else {
      rtb_Saturation2 = rtb_Switch;
    }

    /* End of Saturate: '<S7>/Saturation2' */
    for (k_b = 0; k_b < 12; k_b++) {
      /* Product: '<S15>/Multiply' */
      rtb_Multiply2_l = Controller_ConstB.Coxial_Hexacopter_x.pq_column[k_b + 12]
        * rtb_Saturation1_p_idx_1_b +
        Controller_ConstB.Coxial_Hexacopter_x.pq_column[k_b] *
        rtb_Saturation1_p_idx_0_b;

      /* Sum: '<S15>/Sum' */
      rtb_Saturation4[k_b] = rtb_Multiply2_l + rtb_Saturation2;

      /* Product: '<S15>/Multiply' */
      rtb_Multiply2_l[k_b] = rtb_Multiply2_l;
    }

    /* MinMax: '<S15>/Max' */
    rtb_Multiply2_l = rtb_Saturation4[0];

    /* MinMax: '<S15>/Max1' */
    rtb_Saturation1_p_idx_1_b = rtb_Saturation4[0];
    for (k_b = 0; k_b < 11; k_b++) {
      /* MinMax: '<S15>/Max' incorporates:
       *  MinMax: '<S15>/Max1'
       */
      rtb_Saturation1_p_idx_0_b = rtb_Saturation4[k_b + 1];
      rtb_Multiply2_l = fmaxf(rtb_Multiply2_l, rtb_Saturation1_p_idx_0_b);

      /* MinMax: '<S15>/Max1' */
      rtb_Saturation1_p_idx_1_b = fminf(rtb_Saturation1_p_idx_1_b,
        rtb_Saturation1_p_idx_0_b);
    }

    /* Switch: '<S18>/Switch' incorporates:
     *  Constant: '<S15>/Constant'
     *  Constant: '<S15>/Constant1'
     *  Constant: '<S18>/Constant2'
     *  Logic: '<S18>/Logical Operator'
     *  MinMax: '<S15>/Max'
     *  MinMax: '<S15>/Max1'
     *  RelationalOperator: '<S18>/Relational Operator'
     *  RelationalOperator: '<S18>/Relational Operator1'
     */
    if ((rtb_Multiply2_l > 0.9F) || (rtb_Saturation1_p_idx_1_b < 0.1F)) {
      /* Switch: '<S18>/Switch1' incorporates:
       *  Gain: '<S18>/Gain'
       *  RelationalOperator: '<S18>/Relational Operator2'
       *  RelationalOperator: '<S18>/Relational Operator3'
       *  Sum: '<S18>/Add'
       *  Sum: '<S18>/Subtract'
       *  Sum: '<S18>/Subtract2'
       *  Sum: '<S18>/Subtract3'
       *  Switch: '<S18>/Switch2'
       */
      if (rtb_Multiply2_l - rtb_Saturation1_p_idx_1_b >
          Controller_ConstB.Coxial_Hexacopter_x.Subtract1) {
        rtb_Saturation1_p_idx_0_b = ((0.9F - rtb_Multiply2_l) + (0.1F -
          rtb_Saturation1_p_idx_1_b)) * 0.5F;
      } else if (rtb_Multiply2_l > 0.9F) {
        /* Switch: '<S18>/Switch2' incorporates:
         *  Sum: '<S18>/Subtract4'
         */
        rtb_Saturation1_p_idx_0_b = 0.9F - rtb_Multiply2_l;
      } else {
        /* Switch: '<S18>/Switch2' incorporates:
         *  Sum: '<S18>/Subtract5'
         */
        rtb_Saturation1_p_idx_0_b = 0.1F - rtb_Saturation1_p_idx_1_b;
      }

      /* End of Switch: '<S18>/Switch1' */
    } else {
      rtb_Saturation1_p_idx_0_b = 0.0F;
    }

    /* End of Switch: '<S18>/Switch' */

    /* Saturate: '<S18>/Saturation' */
    if (rtb_Saturation1_p_idx_0_b > 0.2F) {
      rtb_Saturation1_p_idx_0_b = 0.2F;
    } else {
      if (rtb_Saturation1_p_idx_0_b < -0.2F) {
        rtb_Saturation1_p_idx_0_b = -0.2F;
      }
    }

    /* End of Saturate: '<S18>/Saturation' */

    /* Sum: '<S18>/Add3' incorporates:
     *  Sum: '<S15>/Sum1'
     */
    b_max_b = rtb_Saturation1_p_idx_0_b + rtb_Saturation2;

    /* MinMax: '<S18>/Min' incorporates:
     *  Constant: '<S15>/Constant'
     *  Constant: '<S15>/Constant1'
     *  MinMax: '<S15>/Max'
     *  MinMax: '<S15>/Max1'
     *  Product: '<S18>/Divide'
     *  Product: '<S18>/Divide1'
     *  Sum: '<S18>/Add1'
     *  Sum: '<S18>/Add2'
     *  Sum: '<S18>/Add3'
     *  Sum: '<S18>/Subtract6'
     *  Sum: '<S18>/Subtract7'
     *  Sum: '<S18>/Subtract8'
     *  Sum: '<S18>/Subtract9'
     */
    rtb_Saturation2 = fminf((0.9F - b_max_b) / ((rtb_Multiply2_l +
      rtb_Saturation1_p_idx_0_b) - b_max_b), 1.0F / (b_max_b -
      (rtb_Saturation1_p_idx_1_b + rtb_Saturation1_p_idx_0_b)) * (b_max_b - 0.1F));

    /* Saturate: '<S18>/Saturation1' */
    if (rtb_Saturation2 > 1.0F) {
      rtb_Saturation2 = 1.0F;
    } else {
      if (rtb_Saturation2 < 0.5F) {
        rtb_Saturation2 = 0.5F;
      }
    }

    /* End of Saturate: '<S18>/Saturation1' */

    /* Sum: '<S15>/Sum1' */
    rtb_Saturation1_p_idx_0_b = b_max_b;

    /* Saturate: '<S15>/Saturation3' */
    if (b_max_b > 1.0F) {
      rtb_Saturation1_p_idx_0_b = 1.0F;
    } else {
      if (b_max_b < 0.0F) {
        rtb_Saturation1_p_idx_0_b = 0.0F;
      }
    }

    /* End of Saturate: '<S15>/Saturation3' */

    /* MATLAB Function: '<S16>/R_Remix' */
    rtb_Saturation1_p_idx_1_b = 100.0F;
    b_max_b = -100.0F;
    min_index_b = 0;
    max_index_b = 0;
    for (k_b = 0; k_b < 12; k_b++) {
      /* Saturate: '<S15>/Saturation4' incorporates:
       *  Product: '<S15>/Multiply1'
       *  Product: '<S16>/Multiply2'
       *  Sum: '<S15>/Sum2'
       */
      rtb_Multiply2_l = rtb_Multiply2_l[k_b] * rtb_Saturation2 +
        rtb_Saturation1_p_idx_0_b;
      if (rtb_Multiply2_l > 1.0F) {
        rtb_Multiply2_l = 1.0F;
      } else {
        if (rtb_Multiply2_l < 0.0F) {
          rtb_Multiply2_l = 0.0F;
        }
      }

      /* End of Saturate: '<S15>/Saturation4' */

      /* Sum: '<S16>/Sum3' incorporates:
       *  Product: '<S16>/Multiply2'
       */
      rtb_Multiply2_l += Controller_ConstB.Coxial_Hexacopter_x.r_column[k_b] *
        rtb_Saturation1_p_idx_2_b;

      /* MATLAB Function: '<S16>/R_Remix' */
      if (rtb_Multiply2_l < rtb_Saturation1_p_idx_1_b) {
        rtb_Saturation1_p_idx_1_b = rtb_Multiply2_l;
        min_index_b = k_b + 1;
      }

      if (rtb_Multiply2_l > b_max_b) {
        b_max_b = rtb_Multiply2_l;
        max_index_b = k_b + 1;
      }

      /* Sum: '<S16>/Sum3' incorporates:
       *  Product: '<S16>/Multiply2'
       */
      rtb_Multiply2_l[k_b] = rtb_Multiply2_l;
    }

    /* MATLAB Function: '<S16>/R_Remix' incorporates:
     *  Constant: '<S16>/Constant'
     *  Constant: '<S16>/Constant1'
     */
    if ((b_max_b > 0.9F) || (rtb_Saturation1_p_idx_1_b < 0.1F)) {
      if (b_max_b - 0.9F > 0.1F - rtb_Saturation1_p_idx_1_b) {
        rtb_Saturation1_p_idx_2_b = 0.9F - b_max_b;
        min_index_b = max_index_b;
      } else {
        rtb_Saturation1_p_idx_2_b = 0.1F - rtb_Saturation1_p_idx_1_b;
      }

      rtb_Saturation1_p_idx_0_b =
        Controller_ConstB.Coxial_Hexacopter_x.r_column[min_index_b - 1];
      if (rtb_Saturation1_p_idx_0_b < 0.0F) {
        rtb_Saturation1_p_idx_0_b = -1.0F;
      } else {
        if (rtb_Saturation1_p_idx_0_b > 0.0F) {
          rtb_Saturation1_p_idx_0_b = 1.0F;
        }
      }

      rtb_Saturation1_p_idx_2_b *= rtb_Saturation1_p_idx_0_b;
    } else {
      rtb_Saturation1_p_idx_2_b = 0.0F;
    }

    for (k_b = 0; k_b < 12; k_b++) {
      if (Controller_ConstB.Coxial_Hexacopter_x.r_column[k_b] < 0.0F) {
        rtb_Saturation1_p_idx_0_b = -1.0F;
      } else if (Controller_ConstB.Coxial_Hexacopter_x.r_column[k_b] > 0.0F) {
        rtb_Saturation1_p_idx_0_b = 1.0F;
      } else {
        rtb_Saturation1_p_idx_0_b =
          Controller_ConstB.Coxial_Hexacopter_x.r_column[k_b];
      }

      rtb_Saturation4[k_b] = rtb_Saturation1_p_idx_2_b *
        rtb_Saturation1_p_idx_0_b;
    }

    /* MultiPortSwitch: '<S17>/Multiport Switch' incorporates:
     *  Constant: '<S17>/Constant2'
     *  DataTypeConversion: '<S17>/Data Type Conversion'
     *  Gain: '<S17>/Gain3'
     *  Inport: '<Root>/FMS_Out'
     *  Sum: '<S17>/Sum5'
     */
    switch (Controller_U.FMS_Out.status) {
     case 1:
      for (k_b = 0; k_b < 12; k_b++) {
        rtb_MultiportSwitch[k_b] = 1000U;
      }
      break;

     case 2:
      for (k_b = 0; k_b < 12; k_b++) {
        rtb_MultiportSwitch[k_b] = 1150U;
      }
      break;

     case 3:
      for (k_b = 0; k_b < 12; k_b++) {
        /* Sum: '<S16>/Sum4' */
        rtb_Multiply2_l = rtb_Saturation4[k_b] + rtb_Multiply2_l[k_b];

        /* Saturate: '<S17>/Saturation5' */
        if (rtb_Multiply2_l > 1.0F) {
          rtb_Multiply2_l = 1.0F;
        } else {
          if (rtb_Multiply2_l < 0.0F) {
            rtb_Multiply2_l = 0.0F;
          }
        }

        /* End of Saturate: '<S17>/Saturation5' */
        rtb_MultiportSwitch[k_b] = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          rtb_Multiply2_l), 4.2949673E+9F) + 1000U);
      }
      break;

     default:
      for (k_b = 0; k_b < 12; k_b++) {
        rtb_MultiportSwitch[k_b] = 1000U;
      }
      break;
    }

    /* End of MultiPortSwitch: '<S17>/Multiport Switch' */

    /* Reshape: '<S17>/Reshape' */
    for (k_b = 0; k_b < 12; k_b++) {
      rtb_VariantMergeForOutportactua[k_b] = rtb_MultiportSwitch[k_b];
    }

    rtb_VariantMergeForOutportactua[12] = 0U;
    rtb_VariantMergeForOutportactua[13] = 0U;
    rtb_VariantMergeForOutportactua[14] = 0U;
    rtb_VariantMergeForOutportactua[15] = 0U;

    /* End of Reshape: '<S17>/Reshape' */
  }

#elif AIRFRAME == 3

  /* Output and update for atomic system: '<S4>/Coxial_Quadcopter_x' */
  {
    real32_T rtb_Saturation2_j;
    real32_T rtb_floating_yaw_f[8];
    real32_T rtb_Multiply2_h[8];
    uint16_T rtb_MultiportSwitch_m[8];
    int32_T i_n;
    real32_T rtb_Saturation1_pz_idx_2_n;
    real32_T rtb_Saturation1_pz_idx_0_n;
    real32_T rtb_Saturation1_pz_idx_1_n;
    real32_T rtb_Multiply2_h;

    /* Saturate: '<S8>/Saturation1' */
    if (rtb_Sum[0] > 1.0F) {
      rtb_Saturation1_pz_idx_0_n = 1.0F;
    } else if (rtb_Sum[0] < -1.0F) {
      rtb_Saturation1_pz_idx_0_n = -1.0F;
    } else {
      rtb_Saturation1_pz_idx_0_n = rtb_Sum[0];
    }

    if (rtb_Sum[1] > 1.0F) {
      rtb_Saturation1_pz_idx_1_n = 1.0F;
    } else if (rtb_Sum[1] < -1.0F) {
      rtb_Saturation1_pz_idx_1_n = -1.0F;
    } else {
      rtb_Saturation1_pz_idx_1_n = rtb_Sum[1];
    }

    if (rtb_Sum[2] > 1.0F) {
      rtb_Saturation1_pz_idx_2_n = 1.0F;
    } else if (rtb_Sum[2] < -1.0F) {
      rtb_Saturation1_pz_idx_2_n = -1.0F;
    } else {
      rtb_Saturation1_pz_idx_2_n = rtb_Sum[2];
    }

    /* End of Saturate: '<S8>/Saturation1' */

    /* Saturate: '<S8>/Saturation2' */
    if (rtb_Switch > 1.0F) {
      rtb_Saturation2_j = 1.0F;
    } else if (rtb_Switch < 0.0F) {
      rtb_Saturation2_j = 0.0F;
    } else {
      rtb_Saturation2_j = rtb_Switch;
    }

    /* End of Saturate: '<S8>/Saturation2' */
    for (i_n = 0; i_n < 8; i_n++) {
      /* Product: '<S20>/Multiply' */
      rtb_Multiply2_h = Controller_ConstB.Coxial_Quadcopter_x.pq_column[i_n + 8]
        * rtb_Saturation1_pz_idx_1_n +
        Controller_ConstB.Coxial_Quadcopter_x.pq_column[i_n] *
        rtb_Saturation1_pz_idx_0_n;

      /* Sum: '<S20>/Sum' */
      rtb_floating_yaw_f[i_n] = rtb_Multiply2_h + rtb_Saturation2_j;

      /* Product: '<S20>/Multiply' */
      rtb_Multiply2_h[i_n] = rtb_Multiply2_h;
    }

    /* MinMax: '<S20>/Max' */
    rtb_Saturation1_pz_idx_1_n = rtb_floating_yaw_f[0];

    /* MinMax: '<S20>/Max1' */
    rtb_Multiply2_h = rtb_floating_yaw_f[0];
    for (i_n = 0; i_n < 7; i_n++) {
      /* MinMax: '<S20>/Max' incorporates:
       *  MinMax: '<S20>/Max1'
       */
      rtb_Saturation1_pz_idx_0_n = rtb_floating_yaw_f[i_n + 1];
      rtb_Saturation1_pz_idx_1_n = fmaxf(rtb_Saturation1_pz_idx_1_n,
        rtb_Saturation1_pz_idx_0_n);

      /* MinMax: '<S20>/Max1' */
      rtb_Multiply2_h = fminf(rtb_Multiply2_h, rtb_Saturation1_pz_idx_0_n);
    }

    /* Switch: '<S23>/Switch' incorporates:
     *  Constant: '<S20>/Constant'
     *  Constant: '<S20>/Constant1'
     *  Constant: '<S23>/Constant2'
     *  Logic: '<S23>/Logical Operator'
     *  MinMax: '<S20>/Max'
     *  MinMax: '<S20>/Max1'
     *  RelationalOperator: '<S23>/Relational Operator'
     *  RelationalOperator: '<S23>/Relational Operator1'
     */
    if ((rtb_Saturation1_pz_idx_1_n > 0.9F) || (rtb_Multiply2_h < 0.1F)) {
      /* Switch: '<S23>/Switch1' incorporates:
       *  Gain: '<S23>/Gain'
       *  RelationalOperator: '<S23>/Relational Operator2'
       *  RelationalOperator: '<S23>/Relational Operator3'
       *  Sum: '<S23>/Add'
       *  Sum: '<S23>/Subtract'
       *  Sum: '<S23>/Subtract2'
       *  Sum: '<S23>/Subtract3'
       *  Switch: '<S23>/Switch2'
       */
      if (rtb_Saturation1_pz_idx_1_n - rtb_Multiply2_h >
          Controller_ConstB.Coxial_Quadcopter_x.Subtract1) {
        rtb_Saturation1_pz_idx_0_n = ((0.9F - rtb_Saturation1_pz_idx_1_n) +
          (0.1F - rtb_Multiply2_h)) * 0.5F;
      } else if (rtb_Saturation1_pz_idx_1_n > 0.9F) {
        /* Switch: '<S23>/Switch2' incorporates:
         *  Sum: '<S23>/Subtract4'
         */
        rtb_Saturation1_pz_idx_0_n = 0.9F - rtb_Saturation1_pz_idx_1_n;
      } else {
        /* Switch: '<S23>/Switch2' incorporates:
         *  Sum: '<S23>/Subtract5'
         */
        rtb_Saturation1_pz_idx_0_n = 0.1F - rtb_Multiply2_h;
      }

      /* End of Switch: '<S23>/Switch1' */
    } else {
      rtb_Saturation1_pz_idx_0_n = 0.0F;
    }

    /* End of Switch: '<S23>/Switch' */

    /* Saturate: '<S23>/Saturation' */
    if (rtb_Saturation1_pz_idx_0_n > 0.2F) {
      rtb_Saturation1_pz_idx_0_n = 0.2F;
    } else {
      if (rtb_Saturation1_pz_idx_0_n < -0.2F) {
        rtb_Saturation1_pz_idx_0_n = -0.2F;
      }
    }

    /* End of Saturate: '<S23>/Saturation' */

    /* Sum: '<S23>/Add3' incorporates:
     *  Sum: '<S20>/Sum1'
     */
    rtb_Saturation2_j += rtb_Saturation1_pz_idx_0_n;

    /* MinMax: '<S23>/Min' incorporates:
     *  Constant: '<S20>/Constant'
     *  Constant: '<S20>/Constant1'
     *  MinMax: '<S20>/Max'
     *  MinMax: '<S20>/Max1'
     *  Product: '<S23>/Divide'
     *  Product: '<S23>/Divide1'
     *  Sum: '<S23>/Add1'
     *  Sum: '<S23>/Add2'
     *  Sum: '<S23>/Add3'
     *  Sum: '<S23>/Subtract6'
     *  Sum: '<S23>/Subtract7'
     *  Sum: '<S23>/Subtract8'
     *  Sum: '<S23>/Subtract9'
     */
    rtb_Saturation1_pz_idx_1_n = fminf((0.9F - rtb_Saturation2_j) /
      ((rtb_Saturation1_pz_idx_1_n + rtb_Saturation1_pz_idx_0_n) -
       rtb_Saturation2_j), 1.0F / (rtb_Saturation2_j - (rtb_Multiply2_h +
      rtb_Saturation1_pz_idx_0_n)) * (rtb_Saturation2_j - 0.1F));

    /* Saturate: '<S23>/Saturation1' */
    if (rtb_Saturation1_pz_idx_1_n > 1.0F) {
      rtb_Saturation1_pz_idx_1_n = 1.0F;
    } else {
      if (rtb_Saturation1_pz_idx_1_n < 0.5F) {
        rtb_Saturation1_pz_idx_1_n = 0.5F;
      }
    }

    /* End of Saturate: '<S23>/Saturation1' */

    /* Sum: '<S20>/Sum1' */
    rtb_Saturation1_pz_idx_0_n = rtb_Saturation2_j;

    /* Saturate: '<S20>/Saturation3' */
    if (rtb_Saturation2_j > 1.0F) {
      rtb_Saturation1_pz_idx_0_n = 1.0F;
    } else {
      if (rtb_Saturation2_j < 0.0F) {
        rtb_Saturation1_pz_idx_0_n = 0.0F;
      }
    }

    /* End of Saturate: '<S20>/Saturation3' */
    for (i_n = 0; i_n < 8; i_n++) {
      /* Sum: '<S20>/Sum2' incorporates:
       *  Product: '<S20>/Multiply1'
       */
      rtb_Saturation2_j = rtb_Multiply2_h[i_n] * rtb_Saturation1_pz_idx_1_n +
        rtb_Saturation1_pz_idx_0_n;

      /* Saturate: '<S20>/Saturation4' */
      if (rtb_Saturation2_j > 1.0F) {
        rtb_Saturation2_j = 1.0F;
      } else {
        if (rtb_Saturation2_j < 0.0F) {
          rtb_Saturation2_j = 0.0F;
        }
      }

      rtb_floating_yaw_f[i_n] = rtb_Saturation2_j;

      /* End of Saturate: '<S20>/Saturation4' */

      /* Sum: '<S21>/Sum3' incorporates:
       *  Product: '<S21>/Multiply2'
       */
      rtb_Multiply2_h[i_n] = Controller_ConstB.Coxial_Quadcopter_x.r_column[i_n]
        * rtb_Saturation1_pz_idx_2_n + rtb_Saturation2_j;
    }

    /* MATLAB Function: '<S21>/R_Remix' incorporates:
     *  Constant: '<S21>/Constant'
     *  Constant: '<S21>/Constant1'
     */
    Controller_R_Remix(0.9F, 0.1F,
                       Controller_ConstB.Coxial_Quadcopter_x.r_column,
                       rtb_Multiply2_h, rtb_floating_yaw_f);

    /* MultiPortSwitch: '<S22>/Multiport Switch' incorporates:
     *  Constant: '<S22>/Constant2'
     *  DataTypeConversion: '<S22>/Data Type Conversion'
     *  Gain: '<S22>/Gain3'
     *  Inport: '<Root>/FMS_Out'
     *  Sum: '<S22>/Sum5'
     */
    switch (Controller_U.FMS_Out.status) {
     case 1:
      for (i_n = 0; i_n < 8; i_n++) {
        rtb_MultiportSwitch_m[i_n] = 1000U;
      }
      break;

     case 2:
      for (i_n = 0; i_n < 8; i_n++) {
        rtb_MultiportSwitch_m[i_n] = 1150U;
      }
      break;

     case 3:
      for (i_n = 0; i_n < 8; i_n++) {
        /* Sum: '<S21>/Sum4' */
        rtb_Saturation2_j = rtb_floating_yaw_f[i_n] + rtb_Multiply2_h[i_n];

        /* Saturate: '<S22>/Saturation5' */
        if (rtb_Saturation2_j > 1.0F) {
          rtb_Saturation2_j = 1.0F;
        } else {
          if (rtb_Saturation2_j < 0.0F) {
            rtb_Saturation2_j = 0.0F;
          }
        }

        /* End of Saturate: '<S22>/Saturation5' */
        rtb_MultiportSwitch_m[i_n] = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          rtb_Saturation2_j), 4.2949673E+9F) + 1000U);
      }
      break;

     default:
      for (i_n = 0; i_n < 8; i_n++) {
        rtb_MultiportSwitch_m[i_n] = 1000U;
      }
      break;
    }

    /* End of MultiPortSwitch: '<S22>/Multiport Switch' */

    /* Reshape: '<S22>/Reshape' */
    for (i_n = 0; i_n < 8; i_n++) {
      rtb_VariantMergeForOutportactua[i_n] = rtb_MultiportSwitch_m[i_n];
      rtb_VariantMergeForOutportactua[i_n + 8] = 0U;
    }

    /* End of Reshape: '<S22>/Reshape' */
  }

#elif AIRFRAME == 5

  /* Output and update for atomic system: '<S4>/Hexacopter_+' */
  {
    real32_T rtb_new_throttle;
    real32_T rtb_Divide1_k;
    real32_T rtb_floating_yaw_i[6];
    real32_T rtb_Multiply2_a4[6];
    uint16_T rtb_MultiportSwitch_k[6];
    int32_T i_i;
    real32_T rtb_Saturation1_e_idx_2_i;
    real32_T rtb_Saturation1_e_idx_0_i;
    real32_T rtb_Saturation1_e_idx_1_i;
    real32_T u0_tmp_i;

    /* Saturate: '<S9>/Saturation2' */
    if (rtb_Switch > 1.0F) {
      rtb_new_throttle = 1.0F;
    } else if (rtb_Switch < 0.0F) {
      rtb_new_throttle = 0.0F;
    } else {
      rtb_new_throttle = rtb_Switch;
    }

    /* End of Saturate: '<S9>/Saturation2' */

    /* Saturate: '<S9>/Saturation1' */
    if (rtb_Sum[0] > 1.0F) {
      rtb_Saturation1_e_idx_0_i = 1.0F;
    } else if (rtb_Sum[0] < -1.0F) {
      rtb_Saturation1_e_idx_0_i = -1.0F;
    } else {
      rtb_Saturation1_e_idx_0_i = rtb_Sum[0];
    }

    if (rtb_Sum[1] > 1.0F) {
      rtb_Saturation1_e_idx_1_i = 1.0F;
    } else if (rtb_Sum[1] < -1.0F) {
      rtb_Saturation1_e_idx_1_i = -1.0F;
    } else {
      rtb_Saturation1_e_idx_1_i = rtb_Sum[1];
    }

    if (rtb_Sum[2] > 1.0F) {
      rtb_Saturation1_e_idx_2_i = 1.0F;
    } else if (rtb_Sum[2] < -1.0F) {
      rtb_Saturation1_e_idx_2_i = -1.0F;
    } else {
      rtb_Saturation1_e_idx_2_i = rtb_Sum[2];
    }

    /* End of Saturate: '<S9>/Saturation1' */
    for (i_i = 0; i_i < 6; i_i++) {
      /* Product: '<S25>/Multiply' */
      rtb_Divide1_k = Controller_ConstB.Hexacopter_.pq_column[i_i + 6] *
        rtb_Saturation1_e_idx_1_i + Controller_ConstB.Hexacopter_.pq_column[i_i]
        * rtb_Saturation1_e_idx_0_i;

      /* Sum: '<S25>/Sum' */
      rtb_floating_yaw_i[i_i] = rtb_Divide1_k + rtb_new_throttle;

      /* Product: '<S25>/Multiply' */
      rtb_Multiply2_a4[i_i] = rtb_Divide1_k;
    }

    /* MinMax: '<S25>/Max' */
    rtb_Saturation1_e_idx_0_i = rtb_floating_yaw_i[0];

    /* MinMax: '<S25>/Max1' */
    rtb_Saturation1_e_idx_1_i = rtb_floating_yaw_i[0];
    for (i_i = 0; i_i < 5; i_i++) {
      /* MinMax: '<S25>/Max' incorporates:
       *  MinMax: '<S25>/Max1'
       */
      rtb_Divide1_k = rtb_floating_yaw_i[i_i + 1];
      rtb_Saturation1_e_idx_0_i = fmaxf(rtb_Saturation1_e_idx_0_i, rtb_Divide1_k);

      /* MinMax: '<S25>/Max1' */
      rtb_Saturation1_e_idx_1_i = fminf(rtb_Saturation1_e_idx_1_i, rtb_Divide1_k);
    }

    /* Switch: '<S28>/Switch' incorporates:
     *  Constant: '<S25>/Constant'
     *  Constant: '<S25>/Constant1'
     *  Constant: '<S28>/Constant2'
     *  Logic: '<S28>/Logical Operator'
     *  MinMax: '<S25>/Max'
     *  MinMax: '<S25>/Max1'
     *  RelationalOperator: '<S28>/Relational Operator'
     *  RelationalOperator: '<S28>/Relational Operator1'
     */
    if ((rtb_Saturation1_e_idx_0_i > 0.9F) || (rtb_Saturation1_e_idx_1_i < 0.1F))
    {
      /* Switch: '<S28>/Switch1' incorporates:
       *  Gain: '<S28>/Gain'
       *  RelationalOperator: '<S28>/Relational Operator2'
       *  RelationalOperator: '<S28>/Relational Operator3'
       *  Sum: '<S28>/Add'
       *  Sum: '<S28>/Subtract'
       *  Sum: '<S28>/Subtract2'
       *  Sum: '<S28>/Subtract3'
       *  Switch: '<S28>/Switch2'
       */
      if (rtb_Saturation1_e_idx_0_i - rtb_Saturation1_e_idx_1_i >
          Controller_ConstB.Hexacopter_.Subtract1) {
        rtb_Divide1_k = ((0.9F - rtb_Saturation1_e_idx_0_i) + (0.1F -
          rtb_Saturation1_e_idx_1_i)) * 0.5F;
      } else if (rtb_Saturation1_e_idx_0_i > 0.9F) {
        /* Switch: '<S28>/Switch2' incorporates:
         *  Sum: '<S28>/Subtract4'
         */
        rtb_Divide1_k = 0.9F - rtb_Saturation1_e_idx_0_i;
      } else {
        /* Switch: '<S28>/Switch2' incorporates:
         *  Sum: '<S28>/Subtract5'
         */
        rtb_Divide1_k = 0.1F - rtb_Saturation1_e_idx_1_i;
      }

      /* End of Switch: '<S28>/Switch1' */
    } else {
      rtb_Divide1_k = 0.0F;
    }

    /* End of Switch: '<S28>/Switch' */

    /* Saturate: '<S28>/Saturation' */
    if (rtb_Divide1_k > 0.2F) {
      rtb_Divide1_k = 0.2F;
    } else {
      if (rtb_Divide1_k < -0.2F) {
        rtb_Divide1_k = -0.2F;
      }
    }

    /* End of Saturate: '<S28>/Saturation' */

    /* Sum: '<S25>/Sum1' incorporates:
     *  Sum: '<S28>/Add3'
     */
    u0_tmp_i = rtb_Divide1_k + rtb_new_throttle;

    /* Saturate: '<S25>/Saturation3' incorporates:
     *  Sum: '<S25>/Sum1'
     */
    if (u0_tmp_i > 1.0F) {
      rtb_new_throttle = 1.0F;
    } else if (u0_tmp_i < 0.0F) {
      rtb_new_throttle = 0.0F;
    } else {
      rtb_new_throttle = u0_tmp_i;
    }

    /* End of Saturate: '<S25>/Saturation3' */

    /* MinMax: '<S28>/Min' incorporates:
     *  Constant: '<S25>/Constant'
     *  Constant: '<S25>/Constant1'
     *  MinMax: '<S25>/Max'
     *  MinMax: '<S25>/Max1'
     *  Product: '<S28>/Divide'
     *  Product: '<S28>/Divide1'
     *  Sum: '<S28>/Add1'
     *  Sum: '<S28>/Add2'
     *  Sum: '<S28>/Subtract6'
     *  Sum: '<S28>/Subtract7'
     *  Sum: '<S28>/Subtract8'
     *  Sum: '<S28>/Subtract9'
     */
    rtb_Saturation1_e_idx_0_i = fminf((0.9F - u0_tmp_i) /
      ((rtb_Saturation1_e_idx_0_i + rtb_Divide1_k) - u0_tmp_i), 1.0F / (u0_tmp_i
      - (rtb_Saturation1_e_idx_1_i + rtb_Divide1_k)) * (u0_tmp_i - 0.1F));

    /* Saturate: '<S28>/Saturation1' */
    if (rtb_Saturation1_e_idx_0_i > 1.0F) {
      rtb_Saturation1_e_idx_0_i = 1.0F;
    } else {
      if (rtb_Saturation1_e_idx_0_i < 0.5F) {
        rtb_Saturation1_e_idx_0_i = 0.5F;
      }
    }

    /* End of Saturate: '<S28>/Saturation1' */
    for (i_i = 0; i_i < 6; i_i++) {
      /* Sum: '<S25>/Sum2' incorporates:
       *  Product: '<S25>/Multiply1'
       */
      rtb_Saturation1_e_idx_1_i = rtb_Multiply2_a4[i_i] *
        rtb_Saturation1_e_idx_0_i + rtb_new_throttle;

      /* Saturate: '<S25>/Saturation4' */
      if (rtb_Saturation1_e_idx_1_i > 1.0F) {
        rtb_Saturation1_e_idx_1_i = 1.0F;
      } else {
        if (rtb_Saturation1_e_idx_1_i < 0.0F) {
          rtb_Saturation1_e_idx_1_i = 0.0F;
        }
      }

      rtb_floating_yaw_i[i_i] = rtb_Saturation1_e_idx_1_i;

      /* End of Saturate: '<S25>/Saturation4' */

      /* Sum: '<S26>/Sum3' incorporates:
       *  Product: '<S26>/Multiply2'
       */
      rtb_Multiply2_a4[i_i] = Controller_ConstB.Hexacopter_.r_column[i_i] *
        rtb_Saturation1_e_idx_2_i + rtb_Saturation1_e_idx_1_i;
    }

    /* MATLAB Function: '<S26>/R_Remix' incorporates:
     *  Constant: '<S26>/Constant'
     *  Constant: '<S26>/Constant1'
     */
    Controller_R_Remix_h(0.9F, 0.1F, Controller_ConstB.Hexacopter_.r_column,
                         rtb_Multiply2_a4, rtb_floating_yaw_i);

    /* MultiPortSwitch: '<S27>/Multiport Switch' incorporates:
     *  Constant: '<S27>/Constant2'
     *  DataTypeConversion: '<S27>/Data Type Conversion'
     *  Gain: '<S27>/Gain3'
     *  Inport: '<Root>/FMS_Out'
     *  Sum: '<S27>/Sum5'
     */
    switch (Controller_U.FMS_Out.status) {
     case 1:
      for (i_i = 0; i_i < 6; i_i++) {
        rtb_MultiportSwitch_k[i_i] = 1000U;
      }
      break;

     case 2:
      for (i_i = 0; i_i < 6; i_i++) {
        rtb_MultiportSwitch_k[i_i] = 1150U;
      }
      break;

     case 3:
      for (i_i = 0; i_i < 6; i_i++) {
        /* Sum: '<S26>/Sum4' */
        rtb_Saturation1_e_idx_1_i = rtb_floating_yaw_i[i_i] +
          rtb_Multiply2_a4[i_i];

        /* Saturate: '<S27>/Saturation5' */
        if (rtb_Saturation1_e_idx_1_i > 1.0F) {
          rtb_Saturation1_e_idx_1_i = 1.0F;
        } else {
          if (rtb_Saturation1_e_idx_1_i < 0.0F) {
            rtb_Saturation1_e_idx_1_i = 0.0F;
          }
        }

        /* End of Saturate: '<S27>/Saturation5' */
        rtb_MultiportSwitch_k[i_i] = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          rtb_Saturation1_e_idx_1_i), 4.2949673E+9F) + 1000U);
      }
      break;

     default:
      for (i_i = 0; i_i < 6; i_i++) {
        rtb_MultiportSwitch_k[i_i] = 1000U;
      }
      break;
    }

    /* End of MultiPortSwitch: '<S27>/Multiport Switch' */

    /* Reshape: '<S27>/Reshape' */
    for (i_i = 0; i_i < 6; i_i++) {
      rtb_VariantMergeForOutportactua[i_i] = rtb_MultiportSwitch_k[i_i];
    }

    for (i_i = 0; i_i < 10; i_i++) {
      rtb_VariantMergeForOutportactua[i_i + 6] = 0U;
    }

    /* End of Reshape: '<S27>/Reshape' */
  }

#elif AIRFRAME == 4

  /* Output and update for atomic system: '<S4>/Hexacopter_x' */
  {
    real32_T rtb_new_throttle_j;
    real32_T rtb_Divide1_c;
    real32_T rtb_floating_yaw_o[6];
    real32_T rtb_Multiply2_c[6];
    uint16_T rtb_MultiportSwitch_o[6];
    int32_T i_j;
    real32_T rtb_Saturation1_n_idx_2_j;
    real32_T rtb_Saturation1_n_idx_0_j;
    real32_T rtb_Saturation1_n_idx_1_j;
    real32_T u0_tmp_j;

    /* Saturate: '<S10>/Saturation2' */
    if (rtb_Switch > 1.0F) {
      rtb_new_throttle_j = 1.0F;
    } else if (rtb_Switch < 0.0F) {
      rtb_new_throttle_j = 0.0F;
    } else {
      rtb_new_throttle_j = rtb_Switch;
    }

    /* End of Saturate: '<S10>/Saturation2' */

    /* Saturate: '<S10>/Saturation1' */
    if (rtb_Sum[0] > 1.0F) {
      rtb_Saturation1_n_idx_0_j = 1.0F;
    } else if (rtb_Sum[0] < -1.0F) {
      rtb_Saturation1_n_idx_0_j = -1.0F;
    } else {
      rtb_Saturation1_n_idx_0_j = rtb_Sum[0];
    }

    if (rtb_Sum[1] > 1.0F) {
      rtb_Saturation1_n_idx_1_j = 1.0F;
    } else if (rtb_Sum[1] < -1.0F) {
      rtb_Saturation1_n_idx_1_j = -1.0F;
    } else {
      rtb_Saturation1_n_idx_1_j = rtb_Sum[1];
    }

    if (rtb_Sum[2] > 1.0F) {
      rtb_Saturation1_n_idx_2_j = 1.0F;
    } else if (rtb_Sum[2] < -1.0F) {
      rtb_Saturation1_n_idx_2_j = -1.0F;
    } else {
      rtb_Saturation1_n_idx_2_j = rtb_Sum[2];
    }

    /* End of Saturate: '<S10>/Saturation1' */
    for (i_j = 0; i_j < 6; i_j++) {
      /* Product: '<S30>/Multiply' */
      rtb_Divide1_c = Controller_ConstB.Hexacopter_x.pq_column[i_j + 6] *
        rtb_Saturation1_n_idx_1_j + Controller_ConstB.Hexacopter_x.pq_column[i_j]
        * rtb_Saturation1_n_idx_0_j;

      /* Sum: '<S30>/Sum' */
      rtb_floating_yaw_o[i_j] = rtb_Divide1_c + rtb_new_throttle_j;

      /* Product: '<S30>/Multiply' */
      rtb_Multiply2_c[i_j] = rtb_Divide1_c;
    }

    /* MinMax: '<S30>/Max' */
    rtb_Saturation1_n_idx_0_j = rtb_floating_yaw_o[0];

    /* MinMax: '<S30>/Max1' */
    rtb_Saturation1_n_idx_1_j = rtb_floating_yaw_o[0];
    for (i_j = 0; i_j < 5; i_j++) {
      /* MinMax: '<S30>/Max' incorporates:
       *  MinMax: '<S30>/Max1'
       */
      rtb_Divide1_c = rtb_floating_yaw_o[i_j + 1];
      rtb_Saturation1_n_idx_0_j = fmaxf(rtb_Saturation1_n_idx_0_j, rtb_Divide1_c);

      /* MinMax: '<S30>/Max1' */
      rtb_Saturation1_n_idx_1_j = fminf(rtb_Saturation1_n_idx_1_j, rtb_Divide1_c);
    }

    /* Switch: '<S33>/Switch' incorporates:
     *  Constant: '<S30>/Constant'
     *  Constant: '<S30>/Constant1'
     *  Constant: '<S33>/Constant2'
     *  Logic: '<S33>/Logical Operator'
     *  MinMax: '<S30>/Max'
     *  MinMax: '<S30>/Max1'
     *  RelationalOperator: '<S33>/Relational Operator'
     *  RelationalOperator: '<S33>/Relational Operator1'
     */
    if ((rtb_Saturation1_n_idx_0_j > 0.9F) || (rtb_Saturation1_n_idx_1_j < 0.1F))
    {
      /* Switch: '<S33>/Switch1' incorporates:
       *  Gain: '<S33>/Gain'
       *  RelationalOperator: '<S33>/Relational Operator2'
       *  RelationalOperator: '<S33>/Relational Operator3'
       *  Sum: '<S33>/Add'
       *  Sum: '<S33>/Subtract'
       *  Sum: '<S33>/Subtract2'
       *  Sum: '<S33>/Subtract3'
       *  Switch: '<S33>/Switch2'
       */
      if (rtb_Saturation1_n_idx_0_j - rtb_Saturation1_n_idx_1_j >
          Controller_ConstB.Hexacopter_x.Subtract1) {
        rtb_Divide1_c = ((0.9F - rtb_Saturation1_n_idx_0_j) + (0.1F -
          rtb_Saturation1_n_idx_1_j)) * 0.5F;
      } else if (rtb_Saturation1_n_idx_0_j > 0.9F) {
        /* Switch: '<S33>/Switch2' incorporates:
         *  Sum: '<S33>/Subtract4'
         */
        rtb_Divide1_c = 0.9F - rtb_Saturation1_n_idx_0_j;
      } else {
        /* Switch: '<S33>/Switch2' incorporates:
         *  Sum: '<S33>/Subtract5'
         */
        rtb_Divide1_c = 0.1F - rtb_Saturation1_n_idx_1_j;
      }

      /* End of Switch: '<S33>/Switch1' */
    } else {
      rtb_Divide1_c = 0.0F;
    }

    /* End of Switch: '<S33>/Switch' */

    /* Saturate: '<S33>/Saturation' */
    if (rtb_Divide1_c > 0.2F) {
      rtb_Divide1_c = 0.2F;
    } else {
      if (rtb_Divide1_c < -0.2F) {
        rtb_Divide1_c = -0.2F;
      }
    }

    /* End of Saturate: '<S33>/Saturation' */

    /* Sum: '<S30>/Sum1' incorporates:
     *  Sum: '<S33>/Add3'
     */
    u0_tmp_j = rtb_Divide1_c + rtb_new_throttle_j;

    /* Saturate: '<S30>/Saturation3' incorporates:
     *  Sum: '<S30>/Sum1'
     */
    if (u0_tmp_j > 1.0F) {
      rtb_new_throttle_j = 1.0F;
    } else if (u0_tmp_j < 0.0F) {
      rtb_new_throttle_j = 0.0F;
    } else {
      rtb_new_throttle_j = u0_tmp_j;
    }

    /* End of Saturate: '<S30>/Saturation3' */

    /* MinMax: '<S33>/Min' incorporates:
     *  Constant: '<S30>/Constant'
     *  Constant: '<S30>/Constant1'
     *  MinMax: '<S30>/Max'
     *  MinMax: '<S30>/Max1'
     *  Product: '<S33>/Divide'
     *  Product: '<S33>/Divide1'
     *  Sum: '<S33>/Add1'
     *  Sum: '<S33>/Add2'
     *  Sum: '<S33>/Subtract6'
     *  Sum: '<S33>/Subtract7'
     *  Sum: '<S33>/Subtract8'
     *  Sum: '<S33>/Subtract9'
     */
    rtb_Saturation1_n_idx_0_j = fminf((0.9F - u0_tmp_j) /
      ((rtb_Saturation1_n_idx_0_j + rtb_Divide1_c) - u0_tmp_j), 1.0F / (u0_tmp_j
      - (rtb_Saturation1_n_idx_1_j + rtb_Divide1_c)) * (u0_tmp_j - 0.1F));

    /* Saturate: '<S33>/Saturation1' */
    if (rtb_Saturation1_n_idx_0_j > 1.0F) {
      rtb_Saturation1_n_idx_0_j = 1.0F;
    } else {
      if (rtb_Saturation1_n_idx_0_j < 0.5F) {
        rtb_Saturation1_n_idx_0_j = 0.5F;
      }
    }

    /* End of Saturate: '<S33>/Saturation1' */
    for (i_j = 0; i_j < 6; i_j++) {
      /* Sum: '<S30>/Sum2' incorporates:
       *  Product: '<S30>/Multiply1'
       */
      rtb_Saturation1_n_idx_1_j = rtb_Multiply2_c[i_j] *
        rtb_Saturation1_n_idx_0_j + rtb_new_throttle_j;

      /* Saturate: '<S30>/Saturation4' */
      if (rtb_Saturation1_n_idx_1_j > 1.0F) {
        rtb_Saturation1_n_idx_1_j = 1.0F;
      } else {
        if (rtb_Saturation1_n_idx_1_j < 0.0F) {
          rtb_Saturation1_n_idx_1_j = 0.0F;
        }
      }

      rtb_floating_yaw_o[i_j] = rtb_Saturation1_n_idx_1_j;

      /* End of Saturate: '<S30>/Saturation4' */

      /* Sum: '<S31>/Sum3' incorporates:
       *  Product: '<S31>/Multiply2'
       */
      rtb_Multiply2_c[i_j] = Controller_ConstB.Hexacopter_x.r_column[i_j] *
        rtb_Saturation1_n_idx_2_j + rtb_Saturation1_n_idx_1_j;
    }

    /* MATLAB Function: '<S31>/R_Remix' incorporates:
     *  Constant: '<S31>/Constant'
     *  Constant: '<S31>/Constant1'
     */
    Controller_R_Remix_h(0.9F, 0.1F, Controller_ConstB.Hexacopter_x.r_column,
                         rtb_Multiply2_c, rtb_floating_yaw_o);

    /* MultiPortSwitch: '<S32>/Multiport Switch' incorporates:
     *  Constant: '<S32>/Constant2'
     *  DataTypeConversion: '<S32>/Data Type Conversion'
     *  Gain: '<S32>/Gain3'
     *  Inport: '<Root>/FMS_Out'
     *  Sum: '<S32>/Sum5'
     */
    switch (Controller_U.FMS_Out.status) {
     case 1:
      for (i_j = 0; i_j < 6; i_j++) {
        rtb_MultiportSwitch_o[i_j] = 1000U;
      }
      break;

     case 2:
      for (i_j = 0; i_j < 6; i_j++) {
        rtb_MultiportSwitch_o[i_j] = 1150U;
      }
      break;

     case 3:
      for (i_j = 0; i_j < 6; i_j++) {
        /* Sum: '<S31>/Sum4' */
        rtb_Saturation1_n_idx_1_j = rtb_floating_yaw_o[i_j] +
          rtb_Multiply2_c[i_j];

        /* Saturate: '<S32>/Saturation5' */
        if (rtb_Saturation1_n_idx_1_j > 1.0F) {
          rtb_Saturation1_n_idx_1_j = 1.0F;
        } else {
          if (rtb_Saturation1_n_idx_1_j < 0.0F) {
            rtb_Saturation1_n_idx_1_j = 0.0F;
          }
        }

        /* End of Saturate: '<S32>/Saturation5' */
        rtb_MultiportSwitch_o[i_j] = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          rtb_Saturation1_n_idx_1_j), 4.2949673E+9F) + 1000U);
      }
      break;

     default:
      for (i_j = 0; i_j < 6; i_j++) {
        rtb_MultiportSwitch_o[i_j] = 1000U;
      }
      break;
    }

    /* End of MultiPortSwitch: '<S32>/Multiport Switch' */

    /* Reshape: '<S32>/Reshape' */
    for (i_j = 0; i_j < 6; i_j++) {
      rtb_VariantMergeForOutportactua[i_j] = rtb_MultiportSwitch_o[i_j];
    }

    for (i_j = 0; i_j < 10; i_j++) {
      rtb_VariantMergeForOutportactua[i_j + 6] = 0U;
    }

    /* End of Reshape: '<S32>/Reshape' */
  }

#elif AIRFRAME == 8

  /* Output and update for atomic system: '<S4>/Octocopter_+' */
  {
    real32_T rtb_Saturation2_g;
    real32_T rtb_floating_yaw_m[8];
    real32_T rtb_Multiply2_d[8];
    uint16_T rtb_MultiportSwitch_b[8];
    int32_T i_i;
    real32_T rtb_Saturation1_h_idx_2_i;
    real32_T rtb_Saturation1_h_idx_0_i;
    real32_T rtb_Saturation1_h_idx_1_i;
    real32_T rtb_Multiply2_d;

    /* Saturate: '<S11>/Saturation1' */
    if (rtb_Sum[0] > 1.0F) {
      rtb_Saturation1_h_idx_0_i = 1.0F;
    } else if (rtb_Sum[0] < -1.0F) {
      rtb_Saturation1_h_idx_0_i = -1.0F;
    } else {
      rtb_Saturation1_h_idx_0_i = rtb_Sum[0];
    }

    if (rtb_Sum[1] > 1.0F) {
      rtb_Saturation1_h_idx_1_i = 1.0F;
    } else if (rtb_Sum[1] < -1.0F) {
      rtb_Saturation1_h_idx_1_i = -1.0F;
    } else {
      rtb_Saturation1_h_idx_1_i = rtb_Sum[1];
    }

    if (rtb_Sum[2] > 1.0F) {
      rtb_Saturation1_h_idx_2_i = 1.0F;
    } else if (rtb_Sum[2] < -1.0F) {
      rtb_Saturation1_h_idx_2_i = -1.0F;
    } else {
      rtb_Saturation1_h_idx_2_i = rtb_Sum[2];
    }

    /* End of Saturate: '<S11>/Saturation1' */

    /* Saturate: '<S11>/Saturation2' */
    if (rtb_Switch > 1.0F) {
      rtb_Saturation2_g = 1.0F;
    } else if (rtb_Switch < 0.0F) {
      rtb_Saturation2_g = 0.0F;
    } else {
      rtb_Saturation2_g = rtb_Switch;
    }

    /* End of Saturate: '<S11>/Saturation2' */
    for (i_i = 0; i_i < 8; i_i++) {
      /* Product: '<S35>/Multiply' */
      rtb_Multiply2_d = Controller_ConstB.Octocopter_.pq_column[i_i + 8] *
        rtb_Saturation1_h_idx_1_i + Controller_ConstB.Octocopter_.pq_column[i_i]
        * rtb_Saturation1_h_idx_0_i;

      /* Sum: '<S35>/Sum' */
      rtb_floating_yaw_m[i_i] = rtb_Multiply2_d + rtb_Saturation2_g;

      /* Product: '<S35>/Multiply' */
      rtb_Multiply2_d[i_i] = rtb_Multiply2_d;
    }

    /* MinMax: '<S35>/Max' */
    rtb_Saturation1_h_idx_1_i = rtb_floating_yaw_m[0];

    /* MinMax: '<S35>/Max1' */
    rtb_Multiply2_d = rtb_floating_yaw_m[0];
    for (i_i = 0; i_i < 7; i_i++) {
      /* MinMax: '<S35>/Max' incorporates:
       *  MinMax: '<S35>/Max1'
       */
      rtb_Saturation1_h_idx_0_i = rtb_floating_yaw_m[i_i + 1];
      rtb_Saturation1_h_idx_1_i = fmaxf(rtb_Saturation1_h_idx_1_i,
        rtb_Saturation1_h_idx_0_i);

      /* MinMax: '<S35>/Max1' */
      rtb_Multiply2_d = fminf(rtb_Multiply2_d, rtb_Saturation1_h_idx_0_i);
    }

    /* Switch: '<S38>/Switch' incorporates:
     *  Constant: '<S35>/Constant'
     *  Constant: '<S35>/Constant1'
     *  Constant: '<S38>/Constant2'
     *  Logic: '<S38>/Logical Operator'
     *  MinMax: '<S35>/Max'
     *  MinMax: '<S35>/Max1'
     *  RelationalOperator: '<S38>/Relational Operator'
     *  RelationalOperator: '<S38>/Relational Operator1'
     */
    if ((rtb_Saturation1_h_idx_1_i > 0.9F) || (rtb_Multiply2_d < 0.1F)) {
      /* Switch: '<S38>/Switch1' incorporates:
       *  Gain: '<S38>/Gain'
       *  RelationalOperator: '<S38>/Relational Operator2'
       *  RelationalOperator: '<S38>/Relational Operator3'
       *  Sum: '<S38>/Add'
       *  Sum: '<S38>/Subtract'
       *  Sum: '<S38>/Subtract2'
       *  Sum: '<S38>/Subtract3'
       *  Switch: '<S38>/Switch2'
       */
      if (rtb_Saturation1_h_idx_1_i - rtb_Multiply2_d >
          Controller_ConstB.Octocopter_.Subtract1) {
        rtb_Saturation1_h_idx_0_i = ((0.9F - rtb_Saturation1_h_idx_1_i) + (0.1F
          - rtb_Multiply2_d)) * 0.5F;
      } else if (rtb_Saturation1_h_idx_1_i > 0.9F) {
        /* Switch: '<S38>/Switch2' incorporates:
         *  Sum: '<S38>/Subtract4'
         */
        rtb_Saturation1_h_idx_0_i = 0.9F - rtb_Saturation1_h_idx_1_i;
      } else {
        /* Switch: '<S38>/Switch2' incorporates:
         *  Sum: '<S38>/Subtract5'
         */
        rtb_Saturation1_h_idx_0_i = 0.1F - rtb_Multiply2_d;
      }

      /* End of Switch: '<S38>/Switch1' */
    } else {
      rtb_Saturation1_h_idx_0_i = 0.0F;
    }

    /* End of Switch: '<S38>/Switch' */

    /* Saturate: '<S38>/Saturation' */
    if (rtb_Saturation1_h_idx_0_i > 0.2F) {
      rtb_Saturation1_h_idx_0_i = 0.2F;
    } else {
      if (rtb_Saturation1_h_idx_0_i < -0.2F) {
        rtb_Saturation1_h_idx_0_i = -0.2F;
      }
    }

    /* End of Saturate: '<S38>/Saturation' */

    /* Sum: '<S38>/Add3' incorporates:
     *  Sum: '<S35>/Sum1'
     */
    rtb_Saturation2_g += rtb_Saturation1_h_idx_0_i;

    /* MinMax: '<S38>/Min' incorporates:
     *  Constant: '<S35>/Constant'
     *  Constant: '<S35>/Constant1'
     *  MinMax: '<S35>/Max'
     *  MinMax: '<S35>/Max1'
     *  Product: '<S38>/Divide'
     *  Product: '<S38>/Divide1'
     *  Sum: '<S38>/Add1'
     *  Sum: '<S38>/Add2'
     *  Sum: '<S38>/Add3'
     *  Sum: '<S38>/Subtract6'
     *  Sum: '<S38>/Subtract7'
     *  Sum: '<S38>/Subtract8'
     *  Sum: '<S38>/Subtract9'
     */
    rtb_Saturation1_h_idx_1_i = fminf((0.9F - rtb_Saturation2_g) /
      ((rtb_Saturation1_h_idx_1_i + rtb_Saturation1_h_idx_0_i) -
       rtb_Saturation2_g), 1.0F / (rtb_Saturation2_g - (rtb_Multiply2_d +
      rtb_Saturation1_h_idx_0_i)) * (rtb_Saturation2_g - 0.1F));

    /* Saturate: '<S38>/Saturation1' */
    if (rtb_Saturation1_h_idx_1_i > 1.0F) {
      rtb_Saturation1_h_idx_1_i = 1.0F;
    } else {
      if (rtb_Saturation1_h_idx_1_i < 0.5F) {
        rtb_Saturation1_h_idx_1_i = 0.5F;
      }
    }

    /* End of Saturate: '<S38>/Saturation1' */

    /* Sum: '<S35>/Sum1' */
    rtb_Saturation1_h_idx_0_i = rtb_Saturation2_g;

    /* Saturate: '<S35>/Saturation3' */
    if (rtb_Saturation2_g > 1.0F) {
      rtb_Saturation1_h_idx_0_i = 1.0F;
    } else {
      if (rtb_Saturation2_g < 0.0F) {
        rtb_Saturation1_h_idx_0_i = 0.0F;
      }
    }

    /* End of Saturate: '<S35>/Saturation3' */
    for (i_i = 0; i_i < 8; i_i++) {
      /* Sum: '<S35>/Sum2' incorporates:
       *  Product: '<S35>/Multiply1'
       */
      rtb_Saturation2_g = rtb_Multiply2_d[i_i] * rtb_Saturation1_h_idx_1_i +
        rtb_Saturation1_h_idx_0_i;

      /* Saturate: '<S35>/Saturation4' */
      if (rtb_Saturation2_g > 1.0F) {
        rtb_Saturation2_g = 1.0F;
      } else {
        if (rtb_Saturation2_g < 0.0F) {
          rtb_Saturation2_g = 0.0F;
        }
      }

      rtb_floating_yaw_m[i_i] = rtb_Saturation2_g;

      /* End of Saturate: '<S35>/Saturation4' */

      /* Sum: '<S36>/Sum3' incorporates:
       *  Product: '<S36>/Multiply2'
       */
      rtb_Multiply2_d[i_i] = Controller_ConstB.Octocopter_.r_column[i_i] *
        rtb_Saturation1_h_idx_2_i + rtb_Saturation2_g;
    }

    /* MATLAB Function: '<S36>/R_Remix' incorporates:
     *  Constant: '<S36>/Constant'
     *  Constant: '<S36>/Constant1'
     */
    Controller_R_Remix(0.9F, 0.1F, Controller_ConstB.Octocopter_.r_column,
                       rtb_Multiply2_d, rtb_floating_yaw_m);

    /* MultiPortSwitch: '<S37>/Multiport Switch' incorporates:
     *  Constant: '<S37>/Constant2'
     *  DataTypeConversion: '<S37>/Data Type Conversion'
     *  Gain: '<S37>/Gain3'
     *  Inport: '<Root>/FMS_Out'
     *  Sum: '<S37>/Sum5'
     */
    switch (Controller_U.FMS_Out.status) {
     case 1:
      for (i_i = 0; i_i < 8; i_i++) {
        rtb_MultiportSwitch_b[i_i] = 1000U;
      }
      break;

     case 2:
      for (i_i = 0; i_i < 8; i_i++) {
        rtb_MultiportSwitch_b[i_i] = 1150U;
      }
      break;

     case 3:
      for (i_i = 0; i_i < 8; i_i++) {
        /* Sum: '<S36>/Sum4' */
        rtb_Saturation2_g = rtb_floating_yaw_m[i_i] + rtb_Multiply2_d[i_i];

        /* Saturate: '<S37>/Saturation5' */
        if (rtb_Saturation2_g > 1.0F) {
          rtb_Saturation2_g = 1.0F;
        } else {
          if (rtb_Saturation2_g < 0.0F) {
            rtb_Saturation2_g = 0.0F;
          }
        }

        /* End of Saturate: '<S37>/Saturation5' */
        rtb_MultiportSwitch_b[i_i] = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          rtb_Saturation2_g), 4.2949673E+9F) + 1000U);
      }
      break;

     default:
      for (i_i = 0; i_i < 8; i_i++) {
        rtb_MultiportSwitch_b[i_i] = 1000U;
      }
      break;
    }

    /* End of MultiPortSwitch: '<S37>/Multiport Switch' */

    /* Reshape: '<S37>/Reshape' */
    for (i_i = 0; i_i < 8; i_i++) {
      rtb_VariantMergeForOutportactua[i_i] = rtb_MultiportSwitch_b[i_i];
      rtb_VariantMergeForOutportactua[i_i + 8] = 0U;
    }

    /* End of Reshape: '<S37>/Reshape' */
  }

#elif AIRFRAME == 7

  /* Output and update for atomic system: '<S4>/Octocopter_x' */
  {
    real32_T rtb_Saturation2_i;
    real32_T rtb_floating_yaw_h[8];
    real32_T rtb_Multiply2_m[8];
    uint16_T rtb_MultiportSwitch_p[8];
    int32_T i_l;
    real32_T rtb_Saturation1_ps_idx_2_l;
    real32_T rtb_Saturation1_ps_idx_0_l;
    real32_T rtb_Saturation1_ps_idx_1_l;
    real32_T rtb_Multiply2_m;

    /* Saturate: '<S12>/Saturation1' */
    if (rtb_Sum[0] > 1.0F) {
      rtb_Saturation1_ps_idx_0_l = 1.0F;
    } else if (rtb_Sum[0] < -1.0F) {
      rtb_Saturation1_ps_idx_0_l = -1.0F;
    } else {
      rtb_Saturation1_ps_idx_0_l = rtb_Sum[0];
    }

    if (rtb_Sum[1] > 1.0F) {
      rtb_Saturation1_ps_idx_1_l = 1.0F;
    } else if (rtb_Sum[1] < -1.0F) {
      rtb_Saturation1_ps_idx_1_l = -1.0F;
    } else {
      rtb_Saturation1_ps_idx_1_l = rtb_Sum[1];
    }

    if (rtb_Sum[2] > 1.0F) {
      rtb_Saturation1_ps_idx_2_l = 1.0F;
    } else if (rtb_Sum[2] < -1.0F) {
      rtb_Saturation1_ps_idx_2_l = -1.0F;
    } else {
      rtb_Saturation1_ps_idx_2_l = rtb_Sum[2];
    }

    /* End of Saturate: '<S12>/Saturation1' */

    /* Saturate: '<S12>/Saturation2' */
    if (rtb_Switch > 1.0F) {
      rtb_Saturation2_i = 1.0F;
    } else if (rtb_Switch < 0.0F) {
      rtb_Saturation2_i = 0.0F;
    } else {
      rtb_Saturation2_i = rtb_Switch;
    }

    /* End of Saturate: '<S12>/Saturation2' */
    for (i_l = 0; i_l < 8; i_l++) {
      /* Product: '<S40>/Multiply' */
      rtb_Multiply2_m = Controller_ConstB.Octocopter_x.pq_column[i_l + 8] *
        rtb_Saturation1_ps_idx_1_l +
        Controller_ConstB.Octocopter_x.pq_column[i_l] *
        rtb_Saturation1_ps_idx_0_l;

      /* Sum: '<S40>/Sum' */
      rtb_floating_yaw_h[i_l] = rtb_Multiply2_m + rtb_Saturation2_i;

      /* Product: '<S40>/Multiply' */
      rtb_Multiply2_m[i_l] = rtb_Multiply2_m;
    }

    /* MinMax: '<S40>/Max' */
    rtb_Saturation1_ps_idx_1_l = rtb_floating_yaw_h[0];

    /* MinMax: '<S40>/Max1' */
    rtb_Multiply2_m = rtb_floating_yaw_h[0];
    for (i_l = 0; i_l < 7; i_l++) {
      /* MinMax: '<S40>/Max' incorporates:
       *  MinMax: '<S40>/Max1'
       */
      rtb_Saturation1_ps_idx_0_l = rtb_floating_yaw_h[i_l + 1];
      rtb_Saturation1_ps_idx_1_l = fmaxf(rtb_Saturation1_ps_idx_1_l,
        rtb_Saturation1_ps_idx_0_l);

      /* MinMax: '<S40>/Max1' */
      rtb_Multiply2_m = fminf(rtb_Multiply2_m, rtb_Saturation1_ps_idx_0_l);
    }

    /* Switch: '<S43>/Switch' incorporates:
     *  Constant: '<S40>/Constant'
     *  Constant: '<S40>/Constant1'
     *  Constant: '<S43>/Constant2'
     *  Logic: '<S43>/Logical Operator'
     *  MinMax: '<S40>/Max'
     *  MinMax: '<S40>/Max1'
     *  RelationalOperator: '<S43>/Relational Operator'
     *  RelationalOperator: '<S43>/Relational Operator1'
     */
    if ((rtb_Saturation1_ps_idx_1_l > 0.9F) || (rtb_Multiply2_m < 0.1F)) {
      /* Switch: '<S43>/Switch1' incorporates:
       *  Gain: '<S43>/Gain'
       *  RelationalOperator: '<S43>/Relational Operator2'
       *  RelationalOperator: '<S43>/Relational Operator3'
       *  Sum: '<S43>/Add'
       *  Sum: '<S43>/Subtract'
       *  Sum: '<S43>/Subtract2'
       *  Sum: '<S43>/Subtract3'
       *  Switch: '<S43>/Switch2'
       */
      if (rtb_Saturation1_ps_idx_1_l - rtb_Multiply2_m >
          Controller_ConstB.Octocopter_x.Subtract1) {
        rtb_Saturation1_ps_idx_0_l = ((0.9F - rtb_Saturation1_ps_idx_1_l) +
          (0.1F - rtb_Multiply2_m)) * 0.5F;
      } else if (rtb_Saturation1_ps_idx_1_l > 0.9F) {
        /* Switch: '<S43>/Switch2' incorporates:
         *  Sum: '<S43>/Subtract4'
         */
        rtb_Saturation1_ps_idx_0_l = 0.9F - rtb_Saturation1_ps_idx_1_l;
      } else {
        /* Switch: '<S43>/Switch2' incorporates:
         *  Sum: '<S43>/Subtract5'
         */
        rtb_Saturation1_ps_idx_0_l = 0.1F - rtb_Multiply2_m;
      }

      /* End of Switch: '<S43>/Switch1' */
    } else {
      rtb_Saturation1_ps_idx_0_l = 0.0F;
    }

    /* End of Switch: '<S43>/Switch' */

    /* Saturate: '<S43>/Saturation' */
    if (rtb_Saturation1_ps_idx_0_l > 0.2F) {
      rtb_Saturation1_ps_idx_0_l = 0.2F;
    } else {
      if (rtb_Saturation1_ps_idx_0_l < -0.2F) {
        rtb_Saturation1_ps_idx_0_l = -0.2F;
      }
    }

    /* End of Saturate: '<S43>/Saturation' */

    /* Sum: '<S43>/Add3' incorporates:
     *  Sum: '<S40>/Sum1'
     */
    rtb_Saturation2_i += rtb_Saturation1_ps_idx_0_l;

    /* MinMax: '<S43>/Min' incorporates:
     *  Constant: '<S40>/Constant'
     *  Constant: '<S40>/Constant1'
     *  MinMax: '<S40>/Max'
     *  MinMax: '<S40>/Max1'
     *  Product: '<S43>/Divide'
     *  Product: '<S43>/Divide1'
     *  Sum: '<S43>/Add1'
     *  Sum: '<S43>/Add2'
     *  Sum: '<S43>/Add3'
     *  Sum: '<S43>/Subtract6'
     *  Sum: '<S43>/Subtract7'
     *  Sum: '<S43>/Subtract8'
     *  Sum: '<S43>/Subtract9'
     */
    rtb_Saturation1_ps_idx_1_l = fminf((0.9F - rtb_Saturation2_i) /
      ((rtb_Saturation1_ps_idx_1_l + rtb_Saturation1_ps_idx_0_l) -
       rtb_Saturation2_i), 1.0F / (rtb_Saturation2_i - (rtb_Multiply2_m +
      rtb_Saturation1_ps_idx_0_l)) * (rtb_Saturation2_i - 0.1F));

    /* Saturate: '<S43>/Saturation1' */
    if (rtb_Saturation1_ps_idx_1_l > 1.0F) {
      rtb_Saturation1_ps_idx_1_l = 1.0F;
    } else {
      if (rtb_Saturation1_ps_idx_1_l < 0.5F) {
        rtb_Saturation1_ps_idx_1_l = 0.5F;
      }
    }

    /* End of Saturate: '<S43>/Saturation1' */

    /* Sum: '<S40>/Sum1' */
    rtb_Saturation1_ps_idx_0_l = rtb_Saturation2_i;

    /* Saturate: '<S40>/Saturation3' */
    if (rtb_Saturation2_i > 1.0F) {
      rtb_Saturation1_ps_idx_0_l = 1.0F;
    } else {
      if (rtb_Saturation2_i < 0.0F) {
        rtb_Saturation1_ps_idx_0_l = 0.0F;
      }
    }

    /* End of Saturate: '<S40>/Saturation3' */
    for (i_l = 0; i_l < 8; i_l++) {
      /* Sum: '<S40>/Sum2' incorporates:
       *  Product: '<S40>/Multiply1'
       */
      rtb_Saturation2_i = rtb_Multiply2_m[i_l] * rtb_Saturation1_ps_idx_1_l +
        rtb_Saturation1_ps_idx_0_l;

      /* Saturate: '<S40>/Saturation4' */
      if (rtb_Saturation2_i > 1.0F) {
        rtb_Saturation2_i = 1.0F;
      } else {
        if (rtb_Saturation2_i < 0.0F) {
          rtb_Saturation2_i = 0.0F;
        }
      }

      rtb_floating_yaw_h[i_l] = rtb_Saturation2_i;

      /* End of Saturate: '<S40>/Saturation4' */

      /* Sum: '<S41>/Sum3' incorporates:
       *  Product: '<S41>/Multiply2'
       */
      rtb_Multiply2_m[i_l] = Controller_ConstB.Octocopter_x.r_column[i_l] *
        rtb_Saturation1_ps_idx_2_l + rtb_Saturation2_i;
    }

    /* MATLAB Function: '<S41>/R_Remix' incorporates:
     *  Constant: '<S41>/Constant'
     *  Constant: '<S41>/Constant1'
     */
    Controller_R_Remix(0.9F, 0.1F, Controller_ConstB.Octocopter_x.r_column,
                       rtb_Multiply2_m, rtb_floating_yaw_h);

    /* MultiPortSwitch: '<S42>/Multiport Switch' incorporates:
     *  Constant: '<S42>/Constant2'
     *  DataTypeConversion: '<S42>/Data Type Conversion'
     *  Gain: '<S42>/Gain3'
     *  Inport: '<Root>/FMS_Out'
     *  Sum: '<S42>/Sum5'
     */
    switch (Controller_U.FMS_Out.status) {
     case 1:
      for (i_l = 0; i_l < 8; i_l++) {
        rtb_MultiportSwitch_p[i_l] = 1000U;
      }
      break;

     case 2:
      for (i_l = 0; i_l < 8; i_l++) {
        rtb_MultiportSwitch_p[i_l] = 1150U;
      }
      break;

     case 3:
      for (i_l = 0; i_l < 8; i_l++) {
        /* Sum: '<S41>/Sum4' */
        rtb_Saturation2_i = rtb_floating_yaw_h[i_l] + rtb_Multiply2_m[i_l];

        /* Saturate: '<S42>/Saturation5' */
        if (rtb_Saturation2_i > 1.0F) {
          rtb_Saturation2_i = 1.0F;
        } else {
          if (rtb_Saturation2_i < 0.0F) {
            rtb_Saturation2_i = 0.0F;
          }
        }

        /* End of Saturate: '<S42>/Saturation5' */
        rtb_MultiportSwitch_p[i_l] = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          rtb_Saturation2_i), 4.2949673E+9F) + 1000U);
      }
      break;

     default:
      for (i_l = 0; i_l < 8; i_l++) {
        rtb_MultiportSwitch_p[i_l] = 1000U;
      }
      break;
    }

    /* End of MultiPortSwitch: '<S42>/Multiport Switch' */

    /* Reshape: '<S42>/Reshape' */
    for (i_l = 0; i_l < 8; i_l++) {
      rtb_VariantMergeForOutportactua[i_l] = rtb_MultiportSwitch_p[i_l];
      rtb_VariantMergeForOutportactua[i_l + 8] = 0U;
    }

    /* End of Reshape: '<S42>/Reshape' */
  }

#elif AIRFRAME == 2

  /* Output and update for atomic system: '<S4>/Quadcopter_+' */
  {
    real32_T rtb_new_throttle_p;
    real32_T rtb_Divide1_f;
    real32_T rtb_floating_yaw_fy[4];
    real32_T rtb_Multiply2_j[4];
    int32_T i_m;
    real32_T rtb_Saturation1_au_idx_0_m;
    real32_T rtb_Saturation1_au_idx_1_m;
    real32_T rtb_Saturation1_au_idx_2_m;
    real32_T u0_tmp_m;

    /* Saturate: '<S13>/Saturation2' */
    if (rtb_Switch > 1.0F) {
      rtb_new_throttle_p = 1.0F;
    } else if (rtb_Switch < 0.0F) {
      rtb_new_throttle_p = 0.0F;
    } else {
      rtb_new_throttle_p = rtb_Switch;
    }

    /* End of Saturate: '<S13>/Saturation2' */

    /* Saturate: '<S13>/Saturation1' */
    if (rtb_Sum[0] > 1.0F) {
      rtb_Saturation1_au_idx_0_m = 1.0F;
    } else if (rtb_Sum[0] < -1.0F) {
      rtb_Saturation1_au_idx_0_m = -1.0F;
    } else {
      rtb_Saturation1_au_idx_0_m = rtb_Sum[0];
    }

    if (rtb_Sum[1] > 1.0F) {
      rtb_Saturation1_au_idx_1_m = 1.0F;
    } else if (rtb_Sum[1] < -1.0F) {
      rtb_Saturation1_au_idx_1_m = -1.0F;
    } else {
      rtb_Saturation1_au_idx_1_m = rtb_Sum[1];
    }

    if (rtb_Sum[2] > 1.0F) {
      rtb_Saturation1_au_idx_2_m = 1.0F;
    } else if (rtb_Sum[2] < -1.0F) {
      rtb_Saturation1_au_idx_2_m = -1.0F;
    } else {
      rtb_Saturation1_au_idx_2_m = rtb_Sum[2];
    }

    /* End of Saturate: '<S13>/Saturation1' */
    for (i_m = 0; i_m < 4; i_m++) {
      /* Product: '<S45>/Multiply' */
      rtb_Divide1_f = Controller_ConstB.Quadcopter_.pq_column[i_m + 4] *
        rtb_Saturation1_au_idx_1_m + Controller_ConstB.Quadcopter_.pq_column[i_m]
        * rtb_Saturation1_au_idx_0_m;

      /* Sum: '<S45>/Sum' */
      rtb_floating_yaw_fy[i_m] = rtb_Divide1_f + rtb_new_throttle_p;

      /* Product: '<S45>/Multiply' */
      rtb_Multiply2_j[i_m] = rtb_Divide1_f;
    }

    /* MinMax: '<S45>/Max' */
    rtb_Saturation1_au_idx_0_m = fmaxf(fmaxf(fmaxf(rtb_floating_yaw_fy[0],
      rtb_floating_yaw_fy[1]), rtb_floating_yaw_fy[2]), rtb_floating_yaw_fy[3]);

    /* MinMax: '<S45>/Max1' */
    rtb_Saturation1_au_idx_1_m = fminf(fminf(fminf(rtb_floating_yaw_fy[0],
      rtb_floating_yaw_fy[1]), rtb_floating_yaw_fy[2]), rtb_floating_yaw_fy[3]);

    /* Switch: '<S48>/Switch' incorporates:
     *  Constant: '<S45>/Constant'
     *  Constant: '<S45>/Constant1'
     *  Constant: '<S48>/Constant2'
     *  Logic: '<S48>/Logical Operator'
     *  MinMax: '<S45>/Max'
     *  MinMax: '<S45>/Max1'
     *  RelationalOperator: '<S48>/Relational Operator'
     *  RelationalOperator: '<S48>/Relational Operator1'
     */
    if ((rtb_Saturation1_au_idx_0_m > 0.9F) || (rtb_Saturation1_au_idx_1_m <
         0.1F)) {
      /* Switch: '<S48>/Switch1' incorporates:
       *  Gain: '<S48>/Gain'
       *  RelationalOperator: '<S48>/Relational Operator2'
       *  RelationalOperator: '<S48>/Relational Operator3'
       *  Sum: '<S48>/Add'
       *  Sum: '<S48>/Subtract'
       *  Sum: '<S48>/Subtract2'
       *  Sum: '<S48>/Subtract3'
       *  Switch: '<S48>/Switch2'
       */
      if (rtb_Saturation1_au_idx_0_m - rtb_Saturation1_au_idx_1_m >
          Controller_ConstB.Quadcopter_.Subtract1) {
        rtb_Divide1_f = ((0.9F - rtb_Saturation1_au_idx_0_m) + (0.1F -
          rtb_Saturation1_au_idx_1_m)) * 0.5F;
      } else if (rtb_Saturation1_au_idx_0_m > 0.9F) {
        /* Switch: '<S48>/Switch2' incorporates:
         *  Sum: '<S48>/Subtract4'
         */
        rtb_Divide1_f = 0.9F - rtb_Saturation1_au_idx_0_m;
      } else {
        /* Switch: '<S48>/Switch2' incorporates:
         *  Sum: '<S48>/Subtract5'
         */
        rtb_Divide1_f = 0.1F - rtb_Saturation1_au_idx_1_m;
      }

      /* End of Switch: '<S48>/Switch1' */
    } else {
      rtb_Divide1_f = 0.0F;
    }

    /* End of Switch: '<S48>/Switch' */

    /* Saturate: '<S48>/Saturation' */
    if (rtb_Divide1_f > 0.2F) {
      rtb_Divide1_f = 0.2F;
    } else {
      if (rtb_Divide1_f < -0.2F) {
        rtb_Divide1_f = -0.2F;
      }
    }

    /* End of Saturate: '<S48>/Saturation' */

    /* Sum: '<S45>/Sum1' incorporates:
     *  Sum: '<S48>/Add3'
     */
    u0_tmp_m = rtb_Divide1_f + rtb_new_throttle_p;

    /* Saturate: '<S45>/Saturation3' incorporates:
     *  Sum: '<S45>/Sum1'
     */
    if (u0_tmp_m > 1.0F) {
      rtb_new_throttle_p = 1.0F;
    } else if (u0_tmp_m < 0.0F) {
      rtb_new_throttle_p = 0.0F;
    } else {
      rtb_new_throttle_p = u0_tmp_m;
    }

    /* End of Saturate: '<S45>/Saturation3' */

    /* MinMax: '<S48>/Min' incorporates:
     *  Constant: '<S45>/Constant'
     *  Constant: '<S45>/Constant1'
     *  MinMax: '<S45>/Max'
     *  MinMax: '<S45>/Max1'
     *  Product: '<S48>/Divide'
     *  Product: '<S48>/Divide1'
     *  Sum: '<S48>/Add1'
     *  Sum: '<S48>/Add2'
     *  Sum: '<S48>/Subtract6'
     *  Sum: '<S48>/Subtract7'
     *  Sum: '<S48>/Subtract8'
     *  Sum: '<S48>/Subtract9'
     */
    rtb_Saturation1_au_idx_1_m = fminf((0.9F - u0_tmp_m) /
      ((rtb_Saturation1_au_idx_0_m + rtb_Divide1_f) - u0_tmp_m), 1.0F /
      (u0_tmp_m - (rtb_Saturation1_au_idx_1_m + rtb_Divide1_f)) * (u0_tmp_m -
      0.1F));

    /* Saturate: '<S48>/Saturation1' */
    if (rtb_Saturation1_au_idx_1_m > 1.0F) {
      rtb_Saturation1_au_idx_1_m = 1.0F;
    } else {
      if (rtb_Saturation1_au_idx_1_m < 0.5F) {
        rtb_Saturation1_au_idx_1_m = 0.5F;
      }
    }

    /* End of Saturate: '<S48>/Saturation1' */

    /* Sum: '<S45>/Sum2' incorporates:
     *  Product: '<S45>/Multiply1'
     */
    rtb_Saturation1_au_idx_0_m = rtb_Multiply2_j[0] * rtb_Saturation1_au_idx_1_m
      + rtb_new_throttle_p;

    /* Saturate: '<S45>/Saturation4' */
    if (rtb_Saturation1_au_idx_0_m > 1.0F) {
      rtb_Saturation1_au_idx_0_m = 1.0F;
    } else {
      if (rtb_Saturation1_au_idx_0_m < 0.0F) {
        rtb_Saturation1_au_idx_0_m = 0.0F;
      }
    }

    /* Sum: '<S46>/Sum3' incorporates:
     *  Product: '<S46>/Multiply2'
     */
    rtb_Multiply2_j[0] = Controller_ConstB.Quadcopter_.r_column[0] *
      rtb_Saturation1_au_idx_2_m + rtb_Saturation1_au_idx_0_m;

    /* Saturate: '<S45>/Saturation4' */
    rtb_floating_yaw_fy[0] = rtb_Saturation1_au_idx_0_m;

    /* Sum: '<S45>/Sum2' incorporates:
     *  Product: '<S45>/Multiply1'
     */
    rtb_Saturation1_au_idx_0_m = rtb_Multiply2_j[1] * rtb_Saturation1_au_idx_1_m
      + rtb_new_throttle_p;

    /* Saturate: '<S45>/Saturation4' */
    if (rtb_Saturation1_au_idx_0_m > 1.0F) {
      rtb_Saturation1_au_idx_0_m = 1.0F;
    } else {
      if (rtb_Saturation1_au_idx_0_m < 0.0F) {
        rtb_Saturation1_au_idx_0_m = 0.0F;
      }
    }

    /* Sum: '<S46>/Sum3' incorporates:
     *  Product: '<S46>/Multiply2'
     */
    rtb_Multiply2_j[1] = Controller_ConstB.Quadcopter_.r_column[1] *
      rtb_Saturation1_au_idx_2_m + rtb_Saturation1_au_idx_0_m;

    /* Saturate: '<S45>/Saturation4' */
    rtb_floating_yaw_fy[1] = rtb_Saturation1_au_idx_0_m;

    /* Sum: '<S45>/Sum2' incorporates:
     *  Product: '<S45>/Multiply1'
     */
    rtb_Saturation1_au_idx_0_m = rtb_Multiply2_j[2] * rtb_Saturation1_au_idx_1_m
      + rtb_new_throttle_p;

    /* Saturate: '<S45>/Saturation4' */
    if (rtb_Saturation1_au_idx_0_m > 1.0F) {
      rtb_Saturation1_au_idx_0_m = 1.0F;
    } else {
      if (rtb_Saturation1_au_idx_0_m < 0.0F) {
        rtb_Saturation1_au_idx_0_m = 0.0F;
      }
    }

    /* Sum: '<S46>/Sum3' incorporates:
     *  Product: '<S46>/Multiply2'
     */
    rtb_Multiply2_j[2] = Controller_ConstB.Quadcopter_.r_column[2] *
      rtb_Saturation1_au_idx_2_m + rtb_Saturation1_au_idx_0_m;

    /* Saturate: '<S45>/Saturation4' */
    rtb_floating_yaw_fy[2] = rtb_Saturation1_au_idx_0_m;

    /* Sum: '<S45>/Sum2' incorporates:
     *  Product: '<S45>/Multiply1'
     */
    rtb_Saturation1_au_idx_0_m = rtb_Multiply2_j[3] * rtb_Saturation1_au_idx_1_m
      + rtb_new_throttle_p;

    /* Saturate: '<S45>/Saturation4' */
    if (rtb_Saturation1_au_idx_0_m > 1.0F) {
      rtb_Saturation1_au_idx_0_m = 1.0F;
    } else {
      if (rtb_Saturation1_au_idx_0_m < 0.0F) {
        rtb_Saturation1_au_idx_0_m = 0.0F;
      }
    }

    /* Sum: '<S46>/Sum3' incorporates:
     *  Product: '<S46>/Multiply2'
     */
    rtb_Saturation1_au_idx_2_m = Controller_ConstB.Quadcopter_.r_column[3] *
      rtb_Saturation1_au_idx_2_m + rtb_Saturation1_au_idx_0_m;
    rtb_Multiply2_j[3] = rtb_Saturation1_au_idx_2_m;

    /* Saturate: '<S45>/Saturation4' */
    rtb_floating_yaw_fy[3] = rtb_Saturation1_au_idx_0_m;

    /* MATLAB Function: '<S46>/R_Remix' incorporates:
     *  Constant: '<S46>/Constant'
     *  Constant: '<S46>/Constant1'
     */
    Controller_R_Remix_k(0.9F, 0.1F, Controller_ConstB.Quadcopter_.r_column,
                         rtb_Multiply2_j, rtb_floating_yaw_fy);

    /* MultiPortSwitch: '<S47>/Multiport Switch' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    switch (Controller_U.FMS_Out.status) {
     case 1:
      /* Reshape: '<S47>/Reshape' */
      rtb_VariantMergeForOutportactua[0] = 1000U;
      rtb_VariantMergeForOutportactua[1] = 1000U;
      rtb_VariantMergeForOutportactua[2] = 1000U;
      rtb_VariantMergeForOutportactua[3] = 1000U;
      break;

     case 2:
      /* Reshape: '<S47>/Reshape' */
      rtb_VariantMergeForOutportactua[0] = 1150U;
      rtb_VariantMergeForOutportactua[1] = 1150U;
      rtb_VariantMergeForOutportactua[2] = 1150U;
      rtb_VariantMergeForOutportactua[3] = 1150U;
      break;

     case 3:
      /* Sum: '<S46>/Sum4' */
      rtb_Saturation1_au_idx_0_m = rtb_floating_yaw_fy[0] + rtb_Multiply2_j[0];

      /* Saturate: '<S47>/Saturation5' */
      if (rtb_Saturation1_au_idx_0_m > 1.0F) {
        rtb_Saturation1_au_idx_0_m = 1.0F;
      } else {
        if (rtb_Saturation1_au_idx_0_m < 0.0F) {
          rtb_Saturation1_au_idx_0_m = 0.0F;
        }
      }

      /* Reshape: '<S47>/Reshape' incorporates:
       *  Constant: '<S47>/Constant2'
       *  DataTypeConversion: '<S47>/Data Type Conversion'
       *  Gain: '<S47>/Gain3'
       *  Sum: '<S47>/Sum5'
       */
      rtb_VariantMergeForOutportactua[0] = (uint16_T)((uint32_T)fmodf(floorf
        (1000.0F * rtb_Saturation1_au_idx_0_m), 4.2949673E+9F) + 1000U);

      /* Sum: '<S46>/Sum4' */
      rtb_Saturation1_au_idx_0_m = rtb_floating_yaw_fy[1] + rtb_Multiply2_j[1];

      /* Saturate: '<S47>/Saturation5' */
      if (rtb_Saturation1_au_idx_0_m > 1.0F) {
        rtb_Saturation1_au_idx_0_m = 1.0F;
      } else {
        if (rtb_Saturation1_au_idx_0_m < 0.0F) {
          rtb_Saturation1_au_idx_0_m = 0.0F;
        }
      }

      /* Reshape: '<S47>/Reshape' incorporates:
       *  Constant: '<S47>/Constant2'
       *  DataTypeConversion: '<S47>/Data Type Conversion'
       *  Gain: '<S47>/Gain3'
       *  Sum: '<S47>/Sum5'
       */
      rtb_VariantMergeForOutportactua[1] = (uint16_T)((uint32_T)fmodf(floorf
        (1000.0F * rtb_Saturation1_au_idx_0_m), 4.2949673E+9F) + 1000U);

      /* Sum: '<S46>/Sum4' */
      rtb_Saturation1_au_idx_0_m = rtb_floating_yaw_fy[2] + rtb_Multiply2_j[2];

      /* Saturate: '<S47>/Saturation5' */
      if (rtb_Saturation1_au_idx_0_m > 1.0F) {
        rtb_Saturation1_au_idx_0_m = 1.0F;
      } else {
        if (rtb_Saturation1_au_idx_0_m < 0.0F) {
          rtb_Saturation1_au_idx_0_m = 0.0F;
        }
      }

      /* Reshape: '<S47>/Reshape' incorporates:
       *  Constant: '<S47>/Constant2'
       *  DataTypeConversion: '<S47>/Data Type Conversion'
       *  Gain: '<S47>/Gain3'
       *  Sum: '<S47>/Sum5'
       */
      rtb_VariantMergeForOutportactua[2] = (uint16_T)((uint32_T)fmodf(floorf
        (1000.0F * rtb_Saturation1_au_idx_0_m), 4.2949673E+9F) + 1000U);

      /* Sum: '<S46>/Sum4' */
      rtb_Saturation1_au_idx_0_m = rtb_Saturation1_au_idx_2_m +
        rtb_floating_yaw_fy[3];

      /* Saturate: '<S47>/Saturation5' */
      if (rtb_Saturation1_au_idx_0_m > 1.0F) {
        rtb_Saturation1_au_idx_0_m = 1.0F;
      } else {
        if (rtb_Saturation1_au_idx_0_m < 0.0F) {
          rtb_Saturation1_au_idx_0_m = 0.0F;
        }
      }

      /* Reshape: '<S47>/Reshape' incorporates:
       *  Constant: '<S47>/Constant2'
       *  DataTypeConversion: '<S47>/Data Type Conversion'
       *  Gain: '<S47>/Gain3'
       *  Sum: '<S47>/Sum5'
       */
      rtb_VariantMergeForOutportactua[3] = (uint16_T)((uint32_T)fmodf(floorf
        (1000.0F * rtb_Saturation1_au_idx_0_m), 4.2949673E+9F) + 1000U);
      break;

     default:
      /* Reshape: '<S47>/Reshape' */
      rtb_VariantMergeForOutportactua[0] = 1000U;
      rtb_VariantMergeForOutportactua[1] = 1000U;
      rtb_VariantMergeForOutportactua[2] = 1000U;
      rtb_VariantMergeForOutportactua[3] = 1000U;
      break;
    }

    /* End of MultiPortSwitch: '<S47>/Multiport Switch' */

    /* Reshape: '<S47>/Reshape' */
    for (i_m = 0; i_m < 12; i_m++) {
      rtb_VariantMergeForOutportactua[i_m + 4] = 0U;
    }
  }

#elif AIRFRAME == 1

  /* Output and update for atomic system: '<S4>/Quadcopter_x' */
  {
    real32_T rtb_new_throttle_e;
    real32_T rtb_Divide1_n;
    real32_T rtb_floating_yaw_e[4];
    real32_T rtb_Multiply2_ju[4];
    int32_T i_e;
    real32_T rtb_Saturation1_m_idx_0_e;
    real32_T rtb_Saturation1_m_idx_1_e;
    real32_T rtb_Saturation1_m_idx_2_e;
    real32_T u0_tmp_e;

    /* Saturate: '<S14>/Saturation2' */
    if (rtb_Switch > 1.0F) {
      rtb_new_throttle_e = 1.0F;
    } else if (rtb_Switch < 0.0F) {
      rtb_new_throttle_e = 0.0F;
    } else {
      rtb_new_throttle_e = rtb_Switch;
    }

    /* End of Saturate: '<S14>/Saturation2' */

    /* Saturate: '<S14>/Saturation1' */
    if (rtb_Sum[0] > 1.0F) {
      rtb_Saturation1_m_idx_0_e = 1.0F;
    } else if (rtb_Sum[0] < -1.0F) {
      rtb_Saturation1_m_idx_0_e = -1.0F;
    } else {
      rtb_Saturation1_m_idx_0_e = rtb_Sum[0];
    }

    if (rtb_Sum[1] > 1.0F) {
      rtb_Saturation1_m_idx_1_e = 1.0F;
    } else if (rtb_Sum[1] < -1.0F) {
      rtb_Saturation1_m_idx_1_e = -1.0F;
    } else {
      rtb_Saturation1_m_idx_1_e = rtb_Sum[1];
    }

    if (rtb_Sum[2] > 1.0F) {
      rtb_Saturation1_m_idx_2_e = 1.0F;
    } else if (rtb_Sum[2] < -1.0F) {
      rtb_Saturation1_m_idx_2_e = -1.0F;
    } else {
      rtb_Saturation1_m_idx_2_e = rtb_Sum[2];
    }

    /* End of Saturate: '<S14>/Saturation1' */
    for (i_e = 0; i_e < 4; i_e++) {
      /* Product: '<S50>/Multiply' */
      rtb_Divide1_n = Controller_ConstB.Quadcopter_x.pq_column[i_e + 4] *
        rtb_Saturation1_m_idx_1_e + Controller_ConstB.Quadcopter_x.pq_column[i_e]
        * rtb_Saturation1_m_idx_0_e;

      /* Sum: '<S50>/Sum' */
      rtb_floating_yaw_e[i_e] = rtb_Divide1_n + rtb_new_throttle_e;

      /* Product: '<S50>/Multiply' */
      rtb_Multiply2_ju[i_e] = rtb_Divide1_n;
    }

    /* MinMax: '<S50>/Max' */
    rtb_Saturation1_m_idx_0_e = fmaxf(fmaxf(fmaxf(rtb_floating_yaw_e[0],
      rtb_floating_yaw_e[1]), rtb_floating_yaw_e[2]), rtb_floating_yaw_e[3]);

    /* MinMax: '<S50>/Max1' */
    rtb_Saturation1_m_idx_1_e = fminf(fminf(fminf(rtb_floating_yaw_e[0],
      rtb_floating_yaw_e[1]), rtb_floating_yaw_e[2]), rtb_floating_yaw_e[3]);

    /* Switch: '<S53>/Switch' incorporates:
     *  Constant: '<S50>/Constant'
     *  Constant: '<S50>/Constant1'
     *  Constant: '<S53>/Constant2'
     *  Logic: '<S53>/Logical Operator'
     *  MinMax: '<S50>/Max'
     *  MinMax: '<S50>/Max1'
     *  RelationalOperator: '<S53>/Relational Operator'
     *  RelationalOperator: '<S53>/Relational Operator1'
     */
    if ((rtb_Saturation1_m_idx_0_e > 0.9F) || (rtb_Saturation1_m_idx_1_e < 0.1F))
    {
      /* Switch: '<S53>/Switch1' incorporates:
       *  Gain: '<S53>/Gain'
       *  RelationalOperator: '<S53>/Relational Operator2'
       *  RelationalOperator: '<S53>/Relational Operator3'
       *  Sum: '<S53>/Add'
       *  Sum: '<S53>/Subtract'
       *  Sum: '<S53>/Subtract2'
       *  Sum: '<S53>/Subtract3'
       *  Switch: '<S53>/Switch2'
       */
      if (rtb_Saturation1_m_idx_0_e - rtb_Saturation1_m_idx_1_e >
          Controller_ConstB.Quadcopter_x.Subtract1) {
        rtb_Divide1_n = ((0.9F - rtb_Saturation1_m_idx_0_e) + (0.1F -
          rtb_Saturation1_m_idx_1_e)) * 0.5F;
      } else if (rtb_Saturation1_m_idx_0_e > 0.9F) {
        /* Switch: '<S53>/Switch2' incorporates:
         *  Sum: '<S53>/Subtract4'
         */
        rtb_Divide1_n = 0.9F - rtb_Saturation1_m_idx_0_e;
      } else {
        /* Switch: '<S53>/Switch2' incorporates:
         *  Sum: '<S53>/Subtract5'
         */
        rtb_Divide1_n = 0.1F - rtb_Saturation1_m_idx_1_e;
      }

      /* End of Switch: '<S53>/Switch1' */
    } else {
      rtb_Divide1_n = 0.0F;
    }

    /* End of Switch: '<S53>/Switch' */

    /* Saturate: '<S53>/Saturation' */
    if (rtb_Divide1_n > 0.2F) {
      rtb_Divide1_n = 0.2F;
    } else {
      if (rtb_Divide1_n < -0.2F) {
        rtb_Divide1_n = -0.2F;
      }
    }

    /* End of Saturate: '<S53>/Saturation' */

    /* Sum: '<S50>/Sum1' incorporates:
     *  Sum: '<S53>/Add3'
     */
    u0_tmp_e = rtb_Divide1_n + rtb_new_throttle_e;

    /* Saturate: '<S50>/Saturation3' incorporates:
     *  Sum: '<S50>/Sum1'
     */
    if (u0_tmp_e > 1.0F) {
      rtb_new_throttle_e = 1.0F;
    } else if (u0_tmp_e < 0.0F) {
      rtb_new_throttle_e = 0.0F;
    } else {
      rtb_new_throttle_e = u0_tmp_e;
    }

    /* End of Saturate: '<S50>/Saturation3' */

    /* MinMax: '<S53>/Min' incorporates:
     *  Constant: '<S50>/Constant'
     *  Constant: '<S50>/Constant1'
     *  MinMax: '<S50>/Max'
     *  MinMax: '<S50>/Max1'
     *  Product: '<S53>/Divide'
     *  Product: '<S53>/Divide1'
     *  Sum: '<S53>/Add1'
     *  Sum: '<S53>/Add2'
     *  Sum: '<S53>/Subtract6'
     *  Sum: '<S53>/Subtract7'
     *  Sum: '<S53>/Subtract8'
     *  Sum: '<S53>/Subtract9'
     */
    rtb_Saturation1_m_idx_1_e = fminf((0.9F - u0_tmp_e) /
      ((rtb_Saturation1_m_idx_0_e + rtb_Divide1_n) - u0_tmp_e), 1.0F / (u0_tmp_e
      - (rtb_Saturation1_m_idx_1_e + rtb_Divide1_n)) * (u0_tmp_e - 0.1F));

    /* Saturate: '<S53>/Saturation1' */
    if (rtb_Saturation1_m_idx_1_e > 1.0F) {
      rtb_Saturation1_m_idx_1_e = 1.0F;
    } else {
      if (rtb_Saturation1_m_idx_1_e < 0.5F) {
        rtb_Saturation1_m_idx_1_e = 0.5F;
      }
    }

    /* End of Saturate: '<S53>/Saturation1' */

    /* Sum: '<S50>/Sum2' incorporates:
     *  Product: '<S50>/Multiply1'
     */
    rtb_Saturation1_m_idx_0_e = rtb_Multiply2_ju[0] * rtb_Saturation1_m_idx_1_e
      + rtb_new_throttle_e;

    /* Saturate: '<S50>/Saturation4' */
    if (rtb_Saturation1_m_idx_0_e > 1.0F) {
      rtb_Saturation1_m_idx_0_e = 1.0F;
    } else {
      if (rtb_Saturation1_m_idx_0_e < 0.0F) {
        rtb_Saturation1_m_idx_0_e = 0.0F;
      }
    }

    /* Sum: '<S51>/Sum3' incorporates:
     *  Product: '<S51>/Multiply2'
     */
    rtb_Multiply2_ju[0] = Controller_ConstB.Quadcopter_x.r_column[0] *
      rtb_Saturation1_m_idx_2_e + rtb_Saturation1_m_idx_0_e;

    /* Saturate: '<S50>/Saturation4' */
    rtb_floating_yaw_e[0] = rtb_Saturation1_m_idx_0_e;

    /* Sum: '<S50>/Sum2' incorporates:
     *  Product: '<S50>/Multiply1'
     */
    rtb_Saturation1_m_idx_0_e = rtb_Multiply2_ju[1] * rtb_Saturation1_m_idx_1_e
      + rtb_new_throttle_e;

    /* Saturate: '<S50>/Saturation4' */
    if (rtb_Saturation1_m_idx_0_e > 1.0F) {
      rtb_Saturation1_m_idx_0_e = 1.0F;
    } else {
      if (rtb_Saturation1_m_idx_0_e < 0.0F) {
        rtb_Saturation1_m_idx_0_e = 0.0F;
      }
    }

    /* Sum: '<S51>/Sum3' incorporates:
     *  Product: '<S51>/Multiply2'
     */
    rtb_Multiply2_ju[1] = Controller_ConstB.Quadcopter_x.r_column[1] *
      rtb_Saturation1_m_idx_2_e + rtb_Saturation1_m_idx_0_e;

    /* Saturate: '<S50>/Saturation4' */
    rtb_floating_yaw_e[1] = rtb_Saturation1_m_idx_0_e;

    /* Sum: '<S50>/Sum2' incorporates:
     *  Product: '<S50>/Multiply1'
     */
    rtb_Saturation1_m_idx_0_e = rtb_Multiply2_ju[2] * rtb_Saturation1_m_idx_1_e
      + rtb_new_throttle_e;

    /* Saturate: '<S50>/Saturation4' */
    if (rtb_Saturation1_m_idx_0_e > 1.0F) {
      rtb_Saturation1_m_idx_0_e = 1.0F;
    } else {
      if (rtb_Saturation1_m_idx_0_e < 0.0F) {
        rtb_Saturation1_m_idx_0_e = 0.0F;
      }
    }

    /* Sum: '<S51>/Sum3' incorporates:
     *  Product: '<S51>/Multiply2'
     */
    rtb_Multiply2_ju[2] = Controller_ConstB.Quadcopter_x.r_column[2] *
      rtb_Saturation1_m_idx_2_e + rtb_Saturation1_m_idx_0_e;

    /* Saturate: '<S50>/Saturation4' */
    rtb_floating_yaw_e[2] = rtb_Saturation1_m_idx_0_e;

    /* Sum: '<S50>/Sum2' incorporates:
     *  Product: '<S50>/Multiply1'
     */
    rtb_Saturation1_m_idx_0_e = rtb_Multiply2_ju[3] * rtb_Saturation1_m_idx_1_e
      + rtb_new_throttle_e;

    /* Saturate: '<S50>/Saturation4' */
    if (rtb_Saturation1_m_idx_0_e > 1.0F) {
      rtb_Saturation1_m_idx_0_e = 1.0F;
    } else {
      if (rtb_Saturation1_m_idx_0_e < 0.0F) {
        rtb_Saturation1_m_idx_0_e = 0.0F;
      }
    }

    /* Sum: '<S51>/Sum3' incorporates:
     *  Product: '<S51>/Multiply2'
     */
    rtb_Saturation1_m_idx_2_e = Controller_ConstB.Quadcopter_x.r_column[3] *
      rtb_Saturation1_m_idx_2_e + rtb_Saturation1_m_idx_0_e;
    rtb_Multiply2_ju[3] = rtb_Saturation1_m_idx_2_e;

    /* Saturate: '<S50>/Saturation4' */
    rtb_floating_yaw_e[3] = rtb_Saturation1_m_idx_0_e;

    /* MATLAB Function: '<S51>/R_Remix' incorporates:
     *  Constant: '<S51>/Constant'
     *  Constant: '<S51>/Constant1'
     */
    Controller_R_Remix_k(0.9F, 0.1F, Controller_ConstB.Quadcopter_x.r_column,
                         rtb_Multiply2_ju, rtb_floating_yaw_e);

    /* MultiPortSwitch: '<S52>/Multiport Switch' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    switch (Controller_U.FMS_Out.status) {
     case 1:
      /* Reshape: '<S52>/Reshape' */
      rtb_VariantMergeForOutportactua[0] = 1000U;
      rtb_VariantMergeForOutportactua[1] = 1000U;
      rtb_VariantMergeForOutportactua[2] = 1000U;
      rtb_VariantMergeForOutportactua[3] = 1000U;
      break;

     case 2:
      /* Reshape: '<S52>/Reshape' */
      rtb_VariantMergeForOutportactua[0] = 1150U;
      rtb_VariantMergeForOutportactua[1] = 1150U;
      rtb_VariantMergeForOutportactua[2] = 1150U;
      rtb_VariantMergeForOutportactua[3] = 1150U;
      break;

     case 3:
      /* Sum: '<S51>/Sum4' */
      rtb_Saturation1_m_idx_0_e = rtb_floating_yaw_e[0] + rtb_Multiply2_ju[0];

      /* Saturate: '<S52>/Saturation5' */
      if (rtb_Saturation1_m_idx_0_e > 1.0F) {
        rtb_Saturation1_m_idx_0_e = 1.0F;
      } else {
        if (rtb_Saturation1_m_idx_0_e < 0.0F) {
          rtb_Saturation1_m_idx_0_e = 0.0F;
        }
      }

      /* Reshape: '<S52>/Reshape' incorporates:
       *  Constant: '<S52>/Constant2'
       *  DataTypeConversion: '<S52>/Data Type Conversion'
       *  Gain: '<S52>/Gain3'
       *  Sum: '<S52>/Sum5'
       */
      rtb_VariantMergeForOutportactua[0] = (uint16_T)((uint32_T)fmodf(floorf
        (1000.0F * rtb_Saturation1_m_idx_0_e), 4.2949673E+9F) + 1000U);

      /* Sum: '<S51>/Sum4' */
      rtb_Saturation1_m_idx_0_e = rtb_floating_yaw_e[1] + rtb_Multiply2_ju[1];

      /* Saturate: '<S52>/Saturation5' */
      if (rtb_Saturation1_m_idx_0_e > 1.0F) {
        rtb_Saturation1_m_idx_0_e = 1.0F;
      } else {
        if (rtb_Saturation1_m_idx_0_e < 0.0F) {
          rtb_Saturation1_m_idx_0_e = 0.0F;
        }
      }

      /* Reshape: '<S52>/Reshape' incorporates:
       *  Constant: '<S52>/Constant2'
       *  DataTypeConversion: '<S52>/Data Type Conversion'
       *  Gain: '<S52>/Gain3'
       *  Sum: '<S52>/Sum5'
       */
      rtb_VariantMergeForOutportactua[1] = (uint16_T)((uint32_T)fmodf(floorf
        (1000.0F * rtb_Saturation1_m_idx_0_e), 4.2949673E+9F) + 1000U);

      /* Sum: '<S51>/Sum4' */
      rtb_Saturation1_m_idx_0_e = rtb_floating_yaw_e[2] + rtb_Multiply2_ju[2];

      /* Saturate: '<S52>/Saturation5' */
      if (rtb_Saturation1_m_idx_0_e > 1.0F) {
        rtb_Saturation1_m_idx_0_e = 1.0F;
      } else {
        if (rtb_Saturation1_m_idx_0_e < 0.0F) {
          rtb_Saturation1_m_idx_0_e = 0.0F;
        }
      }

      /* Reshape: '<S52>/Reshape' incorporates:
       *  Constant: '<S52>/Constant2'
       *  DataTypeConversion: '<S52>/Data Type Conversion'
       *  Gain: '<S52>/Gain3'
       *  Sum: '<S52>/Sum5'
       */
      rtb_VariantMergeForOutportactua[2] = (uint16_T)((uint32_T)fmodf(floorf
        (1000.0F * rtb_Saturation1_m_idx_0_e), 4.2949673E+9F) + 1000U);

      /* Sum: '<S51>/Sum4' */
      rtb_Saturation1_m_idx_0_e = rtb_Saturation1_m_idx_2_e +
        rtb_floating_yaw_e[3];

      /* Saturate: '<S52>/Saturation5' */
      if (rtb_Saturation1_m_idx_0_e > 1.0F) {
        rtb_Saturation1_m_idx_0_e = 1.0F;
      } else {
        if (rtb_Saturation1_m_idx_0_e < 0.0F) {
          rtb_Saturation1_m_idx_0_e = 0.0F;
        }
      }

      /* Reshape: '<S52>/Reshape' incorporates:
       *  Constant: '<S52>/Constant2'
       *  DataTypeConversion: '<S52>/Data Type Conversion'
       *  Gain: '<S52>/Gain3'
       *  Sum: '<S52>/Sum5'
       */
      rtb_VariantMergeForOutportactua[3] = (uint16_T)((uint32_T)fmodf(floorf
        (1000.0F * rtb_Saturation1_m_idx_0_e), 4.2949673E+9F) + 1000U);
      break;

     default:
      /* Reshape: '<S52>/Reshape' */
      rtb_VariantMergeForOutportactua[0] = 1000U;
      rtb_VariantMergeForOutportactua[1] = 1000U;
      rtb_VariantMergeForOutportactua[2] = 1000U;
      rtb_VariantMergeForOutportactua[3] = 1000U;
      break;
    }

    /* End of MultiPortSwitch: '<S52>/Multiport Switch' */

    /* Reshape: '<S52>/Reshape' */
    for (i_e = 0; i_e < 12; i_e++) {
      rtb_VariantMergeForOutportactua[i_e + 4] = 0U;
    }
  }

#endif

  /* End of Outputs for SubSystem: '<S2>/Control_Allocation' */

  /* Product: '<S70>/Multiply' incorporates:
   *  Constant: '<S70>/gain1'
   *  Constant: '<S70>/gain2'
   *  Constant: '<S70>/gain3'
   *  DiscreteIntegrator: '<S67>/Discrete-Time Integrator5'
   */
  rtb_Add3 = CONTROL_PARAM.MC_ROLLRATE_I *
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[0];
  rtb_att_error_B_rad_idx_1 = CONTROL_PARAM.MC_PITCHRATE_I *
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1];
  rtb_att_error_B_rad_idx_0 = CONTROL_PARAM.MC_YAWRATE_I *
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

  /* Update for DiscreteIntegrator: '<S67>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;

  /* Update for DiscreteIntegrator: '<S70>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S72>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;

  /* Update for DiscreteIntegrator: '<S67>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S67>/Gain'
   *  Sum: '<S67>/Sum5'
   */
  Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] +=
    (rtb_DiscreteTimeIntegrator1[0] -
     Controller_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 188.49556F * 0.002F;

  /* Update for DiscreteIntegrator: '<S70>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE[0] += 0.002F * rtb_Add3;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] >=
      CONTROL_PARAM.MC_RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = CONTROL_PARAM.MC_RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] <=
        CONTROL_PARAM.MC_RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
        CONTROL_PARAM.MC_RATE_I_MIN;
    }
  }

  /* Update for DiscreteIntegrator: '<S72>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] += 0.002F * rtb_Gain_idx_0;

  /* Update for DiscreteIntegrator: '<S67>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S67>/Gain'
   *  Sum: '<S67>/Sum5'
   */
  Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] +=
    (rtb_DiscreteTimeIntegrator1[1] -
     Controller_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 188.49556F * 0.002F;

  /* Update for DiscreteIntegrator: '<S70>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE[1] += 0.002F *
    rtb_att_error_B_rad_idx_1;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] >=
      CONTROL_PARAM.MC_RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = CONTROL_PARAM.MC_RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] <=
        CONTROL_PARAM.MC_RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
        CONTROL_PARAM.MC_RATE_I_MIN;
    }
  }

  /* Update for DiscreteIntegrator: '<S72>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] += 0.002F *
    rtb_Switch_mh_idx_0;

  /* Update for DiscreteIntegrator: '<S67>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S67>/Gain'
   *  Sum: '<S67>/Sum5'
   */
  Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] +=
    (rtb_DiscreteTimeIntegrator1[2] -
     Controller_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 188.49556F * 0.002F;

  /* Update for DiscreteIntegrator: '<S70>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE[2] += 0.002F *
    rtb_att_error_B_rad_idx_0;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[2] >=
      CONTROL_PARAM.MC_RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[2] = CONTROL_PARAM.MC_RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[2] <=
        CONTROL_PARAM.MC_RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[2] =
        CONTROL_PARAM.MC_RATE_I_MIN;
    }
  }

  /* Update for DiscreteIntegrator: '<S72>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_DSTATE[2] += 0.002F *
    rtb_DiscreteTimeIntegrator1_a;
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

  /* InitializeConditions for DiscreteIntegrator: '<S67>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S70>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = Controller_ConstB.Constant[0];
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] >=
      CONTROL_PARAM.MC_RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = CONTROL_PARAM.MC_RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] <=
        CONTROL_PARAM.MC_RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
        CONTROL_PARAM.MC_RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = Controller_ConstB.Constant[1];
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] >=
      CONTROL_PARAM.MC_RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = CONTROL_PARAM.MC_RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] <=
        CONTROL_PARAM.MC_RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
        CONTROL_PARAM.MC_RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_DSTATE[2] = Controller_ConstB.Constant[2];
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[2] >=
      CONTROL_PARAM.MC_RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[2] = CONTROL_PARAM.MC_RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[2] <=
        CONTROL_PARAM.MC_RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[2] =
        CONTROL_PARAM.MC_RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRese = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S70>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S72>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* InitializeConditions for Delay: '<S6>/Delay' */
  Controller_DW.Delay_DSTATE = 1U;

  /* SystemInitialize for Enabled SubSystem: '<S5>/Velocity_Controller' */
  /* InitializeConditions for DiscreteIntegrator: '<S95>/Integrator1' */
  Controller_DW.Integrator1_IC_LOADING_e = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S95>/Integrator' */
  Controller_DW.Integrator_DSTATE_o[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S100>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
    Controller_ConstB.Constant_g;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] >=
      CONTROL_PARAM.MC_VEL_XY_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
      CONTROL_PARAM.MC_VEL_XY_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] <=
        CONTROL_PARAM.MC_VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
        CONTROL_PARAM.MC_VEL_XY_I_MIN;
    }
  }

  /* InitializeConditions for DiscreteIntegrator: '<S95>/Integrator' */
  Controller_DW.Integrator_DSTATE_o[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S100>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
    Controller_ConstB.Constant_g;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] >=
      CONTROL_PARAM.MC_VEL_XY_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
      CONTROL_PARAM.MC_VEL_XY_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] <=
        CONTROL_PARAM.MC_VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
        CONTROL_PARAM.MC_VEL_XY_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRe_e = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S102>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_b = 1U;
  Controller_DW.DiscreteTimeIntegrator1_Prev_a4 = 0;

  /* End of SystemInitialize for SubSystem: '<S5>/Velocity_Controller' */

  /* SystemInitialize for Enabled SubSystem: '<S6>/Veloxity_Z_Controller' */
  /* InitializeConditions for DiscreteIntegrator: '<S117>/Integrator1' */
  Controller_DW.Integrator1_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S121>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_IC_LOADI = 1U;
  Controller_DW.DiscreteTimeIntegrator_PrevRe_d = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S123>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_f = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_a = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S117>/Integrator' */
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
