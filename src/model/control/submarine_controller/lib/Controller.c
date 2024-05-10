/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.1000
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri May 10 12:15:37 2024
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
struct_ggPnHVpLLXFM79yHB3eR4D CONTROL_PARAM = {
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
  0.52359879F,
  0.1F,
  0.1F,
  0.003F,
  2.0F,
  2.0F,
  0.0F,
  -0.1F,
  0.1F,
  -0.1F,
  0.1F,
  1.57079637F,
  1.04719758F
} ;                                    /* Variable: CONTROL_PARAM
                                        * Referenced by:
                                        *   '<S8>/Saturation'
                                        *   '<S8>/Saturation1'
                                        *   '<S8>/Saturation2'
                                        *   '<S19>/Constant2'
                                        *   '<S36>/kd'
                                        *   '<S36>/Saturation'
                                        *   '<S37>/ki'
                                        *   '<S37>/Discrete-Time Integrator'
                                        *   '<S38>/kp'
                                        *   '<S42>/kd'
                                        *   '<S42>/Saturation'
                                        *   '<S43>/Constant'
                                        *   '<S43>/ki'
                                        *   '<S43>/Discrete-Time Integrator'
                                        *   '<S44>/kp'
                                        *   '<S14>/q_kd'
                                        *   '<S14>/r_kd'
                                        *   '<S14>/Saturation'
                                        *   '<S15>/q_ki'
                                        *   '<S15>/r_ki'
                                        *   '<S15>/Discrete-Time Integrator'
                                        *   '<S16>/q_kp'
                                        *   '<S16>/r_kp'
                                        */

struct_3c1tBoNX9Tmevk4CbFSC3G CONTROL_EXPORT = {
  2U,

  { 83, 117, 98, 109, 97, 114, 105, 110, 101, 32, 67, 111, 110, 116, 114, 111,
    108, 108, 101, 114, 32, 118, 48, 46, 48, 46, 49, 0 }
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
  real32_T rtb_theta_error_B_rad;
  real32_T rtb_Divide1;
  real32_T rtb_linear_dist;
  real32_T rtb_DiscreteTimeIntegrator1_d;
  real32_T rtb_MatrixConcatenate1[9];
  real32_T rtb_Add_la;
  real32_T rtb_Add_e;
  real32_T rtb_Sign;
  int32_T i;
  real32_T rtb_MatrixConcatenate1_0[3];
  real32_T rtb_Divide_idx_0;
  real32_T rtb_Divide_idx_1;
  real32_T rtb_Divide_idx_2;
  real32_T rtb_Saturation_o_idx_0;
  real32_T rtb_Saturation_o_idx_1;
  real32_T rtb_MatrixConcatenate1_tmp;
  real32_T rtb_MatrixConcatenate1_tmp_0;
  real32_T rtb_MatrixConcatenate1_tmp_1;
  real32_T rtb_MatrixConcatenate1_tmp_2;

  /* Saturate: '<S8>/Saturation' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_U.FMS_Out.theta_cmd > CONTROL_PARAM.PITCH_CMD_LIM) {
    rtb_Add_e = CONTROL_PARAM.PITCH_CMD_LIM;
  } else if (Controller_U.FMS_Out.theta_cmd < -CONTROL_PARAM.PITCH_CMD_LIM) {
    rtb_Add_e = -CONTROL_PARAM.PITCH_CMD_LIM;
  } else {
    rtb_Add_e = Controller_U.FMS_Out.theta_cmd;
  }

  /* End of Saturate: '<S8>/Saturation' */

  /* Sum: '<S18>/Sum' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_theta_error_B_rad = rtb_Add_e - Controller_U.INS_Out.theta;

  /* Product: '<S21>/Divide1' incorporates:
   *  Abs: '<S21>/Abs'
   *  Constant: '<S21>/const2'
   */
  rtb_Divide1 = fabsf(rtb_theta_error_B_rad) / 0.002F;

  /* Product: '<S21>/Divide' incorporates:
   *  Constant: '<S19>/Constant2'
   *  Constant: '<S21>/const1'
   *  Math: '<S21>/Square'
   */
  rtb_linear_dist = 9.5993F / (CONTROL_PARAM.PITCH_P * CONTROL_PARAM.PITCH_P);

  /* Switch: '<S21>/Switch' incorporates:
   *  Constant: '<S19>/Constant2'
   *  Gain: '<S21>/Gain1'
   *  Gain: '<S21>/Gain2'
   *  Logic: '<S21>/Logical Operator'
   *  Product: '<S21>/Multiply'
   *  Product: '<S21>/Multiply1'
   *  Product: '<S21>/Multiply2'
   *  Product: '<S21>/Multiply3'
   *  RelationalOperator: '<S21>/Relational Operator'
   *  RelationalOperator: '<S21>/Relational Operator2'
   *  Signum: '<S21>/Sign'
   *  Sqrt: '<S21>/Sqrt'
   *  Sum: '<S21>/Subtract'
   */
  if ((rtb_theta_error_B_rad <= rtb_linear_dist) && (rtb_theta_error_B_rad >=
       -rtb_linear_dist)) {
    rtb_theta_error_B_rad *= CONTROL_PARAM.PITCH_P;
  } else {
    if (rtb_theta_error_B_rad < 0.0F) {
      /* Signum: '<S21>/Sign' */
      rtb_Sign = -1.0F;
    } else if (rtb_theta_error_B_rad > 0.0F) {
      /* Signum: '<S21>/Sign' */
      rtb_Sign = 1.0F;
    } else {
      /* Signum: '<S21>/Sign' */
      rtb_Sign = rtb_theta_error_B_rad;
    }

    rtb_theta_error_B_rad = sqrtf((rtb_Sign * rtb_theta_error_B_rad - 0.5F *
      rtb_linear_dist) * Controller_ConstB.Gain) * rtb_Sign;
  }

  /* End of Switch: '<S21>/Switch' */

  /* Switch: '<S22>/Switch2' incorporates:
   *  Gain: '<S21>/Gain3'
   *  RelationalOperator: '<S22>/LowerRelop1'
   *  RelationalOperator: '<S22>/UpperRelop'
   *  Switch: '<S22>/Switch'
   */
  if (rtb_theta_error_B_rad > rtb_Divide1) {
    rtb_theta_error_B_rad = rtb_Divide1;
  } else {
    if (rtb_theta_error_B_rad < -rtb_Divide1) {
      /* Switch: '<S22>/Switch' incorporates:
       *  Gain: '<S21>/Gain3'
       */
      rtb_theta_error_B_rad = -rtb_Divide1;
    }
  }

  /* End of Switch: '<S22>/Switch2' */

  /* Saturate: '<S8>/Saturation2' */
  if (rtb_theta_error_B_rad > CONTROL_PARAM.Q_CMD_LIM) {
    rtb_theta_error_B_rad = CONTROL_PARAM.Q_CMD_LIM;
  } else {
    if (rtb_theta_error_B_rad < -CONTROL_PARAM.Q_CMD_LIM) {
      rtb_theta_error_B_rad = -CONTROL_PARAM.Q_CMD_LIM;
    }
  }

  /* End of Saturate: '<S8>/Saturation2' */

  /* Sum: '<S10>/Sum' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Divide1 = rtb_theta_error_B_rad - Controller_U.INS_Out.q;

  /* Saturate: '<S8>/Saturation1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_U.FMS_Out.r_cmd > CONTROL_PARAM.R_CMD_LIM) {
    rtb_Add_e = CONTROL_PARAM.R_CMD_LIM;
  } else if (Controller_U.FMS_Out.r_cmd < -CONTROL_PARAM.R_CMD_LIM) {
    rtb_Add_e = -CONTROL_PARAM.R_CMD_LIM;
  } else {
    rtb_Add_e = Controller_U.FMS_Out.r_cmd;
  }

  /* End of Saturate: '<S8>/Saturation1' */

  /* Signum: '<S8>/Sign' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_U.FMS_Out.u_cmd < 0.0F) {
    rtb_theta_error_B_rad = -1.0F;
  } else if (Controller_U.FMS_Out.u_cmd > 0.0F) {
    rtb_theta_error_B_rad = 1.0F;
  } else {
    rtb_theta_error_B_rad = Controller_U.FMS_Out.u_cmd;
  }

  /* End of Signum: '<S8>/Sign' */

  /* Sum: '<S10>/Sum' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Product: '<S8>/Multiply'
   */
  rtb_theta_error_B_rad = rtb_Add_e * rtb_theta_error_B_rad -
    Controller_U.INS_Out.r;

  /* DiscreteIntegrator: '<S13>/Discrete-Time Integrator5' */
  if (Controller_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] = rtb_Divide1;
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] = rtb_theta_error_B_rad;
  }

  /* DiscreteIntegrator: '<S15>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator_PrevRese != 0)) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = Controller_ConstB.Constant;
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

    Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = Controller_ConstB.Constant;
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

  /* DiscreteIntegrator: '<S17>/Discrete-Time Integrator1' incorporates:
   *  DiscreteIntegrator: '<S13>/Discrete-Time Integrator5'
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] =
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[0];
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] =
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[1];
  }

  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevRes != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] =
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[0];
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] =
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[1];
  }

  /* Gain: '<S17>/Gain' incorporates:
   *  DiscreteIntegrator: '<S13>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S17>/Discrete-Time Integrator1'
   *  Sum: '<S17>/Sum5'
   */
  rtb_linear_dist = (Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] -
                     Controller_DW.DiscreteTimeIntegrator1_DSTATE[0]) *
    62.831852F;
  rtb_Sign = (Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] -
              Controller_DW.DiscreteTimeIntegrator1_DSTATE[1]) * 62.831852F;

  /* Sqrt: '<S35>/Sqrt' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Math: '<S35>/Square'
   *  Sum: '<S35>/Sum of Elements'
   */
  rtb_DiscreteTimeIntegrator1_d = sqrtf(((Controller_U.INS_Out.quat[0] *
    Controller_U.INS_Out.quat[0] + Controller_U.INS_Out.quat[1] *
    Controller_U.INS_Out.quat[1]) + Controller_U.INS_Out.quat[2] *
    Controller_U.INS_Out.quat[2]) + Controller_U.INS_Out.quat[3] *
    Controller_U.INS_Out.quat[3]);

  /* Product: '<S31>/Divide' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Divide_idx_0 = Controller_U.INS_Out.quat[0] /
    rtb_DiscreteTimeIntegrator1_d;
  rtb_Divide_idx_1 = Controller_U.INS_Out.quat[1] /
    rtb_DiscreteTimeIntegrator1_d;
  rtb_Divide_idx_2 = Controller_U.INS_Out.quat[2] /
    rtb_DiscreteTimeIntegrator1_d;
  rtb_DiscreteTimeIntegrator1_d = Controller_U.INS_Out.quat[3] /
    rtb_DiscreteTimeIntegrator1_d;

  /* Math: '<S32>/Square' incorporates:
   *  Math: '<S33>/Square'
   *  Math: '<S34>/Square'
   */
  rtb_Add_la = rtb_Divide_idx_0 * rtb_Divide_idx_0;

  /* Math: '<S32>/Square2' incorporates:
   *  Math: '<S33>/Square2'
   *  Math: '<S34>/Square2'
   */
  rtb_Add_e = rtb_Divide_idx_2 * rtb_Divide_idx_2;

  /* Math: '<S32>/Square1' incorporates:
   *  Math: '<S33>/Square1'
   *  Math: '<S34>/Square1'
   */
  rtb_MatrixConcatenate1_tmp_0 = rtb_Divide_idx_1 * rtb_Divide_idx_1;

  /* Math: '<S32>/Square3' incorporates:
   *  Math: '<S33>/Square3'
   *  Math: '<S34>/Square3'
   */
  rtb_Saturation_o_idx_0 = rtb_DiscreteTimeIntegrator1_d *
    rtb_DiscreteTimeIntegrator1_d;

  /* Sum: '<S32>/Subtract' incorporates:
   *  Math: '<S32>/Square'
   *  Math: '<S32>/Square1'
   *  Math: '<S32>/Square2'
   *  Math: '<S32>/Square3'
   *  Sum: '<S32>/Add'
   *  Sum: '<S32>/Add1'
   */
  rtb_MatrixConcatenate1[0] = (rtb_Add_la + rtb_MatrixConcatenate1_tmp_0) -
    (rtb_Add_e + rtb_Saturation_o_idx_0);

  /* Product: '<S32>/Multiply' incorporates:
   *  Product: '<S33>/Multiply'
   */
  rtb_Saturation_o_idx_1 = rtb_Divide_idx_1 * rtb_Divide_idx_2;

  /* Product: '<S32>/Multiply1' incorporates:
   *  Product: '<S33>/Multiply1'
   */
  rtb_MatrixConcatenate1_tmp = rtb_Divide_idx_0 * rtb_DiscreteTimeIntegrator1_d;

  /* Gain: '<S32>/Gain' incorporates:
   *  Product: '<S32>/Multiply'
   *  Product: '<S32>/Multiply1'
   *  Sum: '<S32>/Subtract1'
   */
  rtb_MatrixConcatenate1[1] = (rtb_Saturation_o_idx_1 -
    rtb_MatrixConcatenate1_tmp) * 2.0F;

  /* Product: '<S32>/Multiply2' incorporates:
   *  Product: '<S34>/Multiply'
   */
  rtb_MatrixConcatenate1_tmp_1 = rtb_Divide_idx_1 *
    rtb_DiscreteTimeIntegrator1_d;

  /* Product: '<S32>/Multiply3' incorporates:
   *  Product: '<S34>/Multiply1'
   */
  rtb_MatrixConcatenate1_tmp_2 = rtb_Divide_idx_0 * rtb_Divide_idx_2;

  /* Gain: '<S32>/Gain1' incorporates:
   *  Product: '<S32>/Multiply2'
   *  Product: '<S32>/Multiply3'
   *  Sum: '<S32>/Add2'
   */
  rtb_MatrixConcatenate1[2] = (rtb_MatrixConcatenate1_tmp_1 +
    rtb_MatrixConcatenate1_tmp_2) * 2.0F;

  /* Gain: '<S33>/Gain' incorporates:
   *  Sum: '<S33>/Add3'
   */
  rtb_MatrixConcatenate1[3] = (rtb_Saturation_o_idx_1 +
    rtb_MatrixConcatenate1_tmp) * 2.0F;

  /* Sum: '<S33>/Subtract' incorporates:
   *  Sum: '<S33>/Add'
   *  Sum: '<S33>/Add1'
   */
  rtb_MatrixConcatenate1[4] = (rtb_Add_la + rtb_Add_e) -
    (rtb_MatrixConcatenate1_tmp_0 + rtb_Saturation_o_idx_0);

  /* Product: '<S33>/Multiply2' incorporates:
   *  Product: '<S34>/Multiply2'
   */
  rtb_Saturation_o_idx_1 = rtb_Divide_idx_2 * rtb_DiscreteTimeIntegrator1_d;

  /* Product: '<S33>/Multiply3' incorporates:
   *  Product: '<S34>/Multiply3'
   */
  rtb_MatrixConcatenate1_tmp = rtb_Divide_idx_0 * rtb_Divide_idx_1;

  /* Gain: '<S33>/Gain1' incorporates:
   *  Product: '<S33>/Multiply2'
   *  Product: '<S33>/Multiply3'
   *  Sum: '<S33>/Subtract1'
   */
  rtb_MatrixConcatenate1[5] = (rtb_Saturation_o_idx_1 -
    rtb_MatrixConcatenate1_tmp) * 2.0F;

  /* Gain: '<S34>/Gain' incorporates:
   *  Sum: '<S34>/Subtract2'
   */
  rtb_MatrixConcatenate1[6] = (rtb_MatrixConcatenate1_tmp_1 -
    rtb_MatrixConcatenate1_tmp_2) * 2.0F;

  /* Gain: '<S34>/Gain1' incorporates:
   *  Sum: '<S34>/Add2'
   */
  rtb_MatrixConcatenate1[7] = (rtb_Saturation_o_idx_1 +
    rtb_MatrixConcatenate1_tmp) * 2.0F;

  /* Sum: '<S34>/Subtract' incorporates:
   *  Sum: '<S34>/Add'
   *  Sum: '<S34>/Add1'
   */
  rtb_MatrixConcatenate1[8] = (rtb_Add_la + rtb_Saturation_o_idx_0) -
    (rtb_MatrixConcatenate1_tmp_0 + rtb_Add_e);

  /* Product: '<S29>/Multiply' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  SignalConversion: '<S29>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_MatrixConcatenate1_0[i] = rtb_MatrixConcatenate1[i + 6] *
      Controller_U.INS_Out.vd + (rtb_MatrixConcatenate1[i + 3] *
      Controller_U.INS_Out.ve + rtb_MatrixConcatenate1[i] *
      Controller_U.INS_Out.vn);
  }

  /* End of Product: '<S29>/Multiply' */

  /* Sum: '<S27>/Sum' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  rtb_Divide_idx_0 = Controller_U.FMS_Out.u_cmd - rtb_MatrixConcatenate1_0[0];

  /* DiscreteIntegrator: '<S37>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator_PrevRe_e != 0)) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m = Controller_ConstB.Constant_g;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m >=
        CONTROL_PARAM.VEL_X_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m = CONTROL_PARAM.VEL_X_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m <=
          CONTROL_PARAM.VEL_X_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_m =
          CONTROL_PARAM.VEL_X_I_MIN;
      }
    }
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m >= CONTROL_PARAM.VEL_X_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m = CONTROL_PARAM.VEL_X_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m <=
        CONTROL_PARAM.VEL_X_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m = CONTROL_PARAM.VEL_X_I_MIN;
    }
  }

  /* DiscreteIntegrator: '<S39>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_b != 0) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_m = rtb_Divide_idx_0;
  }

  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevR_a != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_m = rtb_Divide_idx_0;
  }

  /* Gain: '<S39>/Gain' incorporates:
   *  DiscreteIntegrator: '<S39>/Discrete-Time Integrator1'
   *  Sum: '<S39>/Sum5'
   */
  rtb_Divide_idx_1 = (rtb_Divide_idx_0 -
                      Controller_DW.DiscreteTimeIntegrator1_DSTAT_m) *
    62.831852F;

  /* Sum: '<S40>/Sum1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Divide_idx_2 = Controller_U.FMS_Out.w_cmd - Controller_U.INS_Out.vd;

  /* DiscreteIntegrator: '<S43>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S43>/Constant'
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator_PrevRe_m != 0)) {
    Controller_DW.DiscreteTimeIntegrator_DSTAT_mf = CONTROL_PARAM.VEL_Z_I_MIN;
    if (Controller_DW.DiscreteTimeIntegrator_DSTAT_mf >=
        CONTROL_PARAM.VEL_Z_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_mf = CONTROL_PARAM.VEL_Z_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_mf <=
          CONTROL_PARAM.VEL_Z_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_mf =
          CONTROL_PARAM.VEL_Z_I_MIN;
      }
    }
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTAT_mf >= CONTROL_PARAM.VEL_Z_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTAT_mf = CONTROL_PARAM.VEL_Z_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTAT_mf <=
        CONTROL_PARAM.VEL_Z_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_mf = CONTROL_PARAM.VEL_Z_I_MIN;
    }
  }

  /* DiscreteIntegrator: '<S45>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_k != 0) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_h = rtb_Divide_idx_2;
  }

  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevR_i != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_h = rtb_Divide_idx_2;
  }

  /* Gain: '<S45>/Gain' incorporates:
   *  DiscreteIntegrator: '<S45>/Discrete-Time Integrator1'
   *  Sum: '<S45>/Sum5'
   */
  rtb_DiscreteTimeIntegrator1_d = (rtb_Divide_idx_2 -
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_h) * 62.831852F;

  /* Outputs for Atomic SubSystem: '<S5>/Submarine_1' */
  /* MultiPortSwitch: '<S24>/Multiport Switch' incorporates:
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S14>/Multiply'
   */
  switch (Controller_U.FMS_Out.status) {
   case 1:
    /* Outport: '<Root>/Control_Out' */
    Controller_Y.Control_Out.actuator_cmd[0] = 1500U;
    Controller_Y.Control_Out.actuator_cmd[1] = 1500U;
    Controller_Y.Control_Out.actuator_cmd[2] = 1500U;
    Controller_Y.Control_Out.actuator_cmd[3] = 1500U;
    break;

   case 2:
    /* Outport: '<Root>/Control_Out' */
    Controller_Y.Control_Out.actuator_cmd[0] = 1500U;
    Controller_Y.Control_Out.actuator_cmd[1] = 1500U;
    Controller_Y.Control_Out.actuator_cmd[2] = 1500U;
    Controller_Y.Control_Out.actuator_cmd[3] = 1500U;
    break;

   case 3:
    /* Switch: '<S45>/Switch' incorporates:
     *  Gain: '<S45>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_Add_e = 0.0F;
    } else {
      rtb_Add_e = rtb_DiscreteTimeIntegrator1_d;
    }

    /* End of Switch: '<S45>/Switch' */

    /* Product: '<S42>/Multiply' incorporates:
     *  Constant: '<S42>/kd'
     */
    rtb_Add_la = CONTROL_PARAM.VEL_Z_D * rtb_Add_e;

    /* Saturate: '<S42>/Saturation' */
    if (rtb_Add_la > CONTROL_PARAM.VEL_Z_D_MAX) {
      rtb_Add_la = CONTROL_PARAM.VEL_Z_D_MAX;
    } else {
      if (rtb_Add_la < CONTROL_PARAM.VEL_Z_D_MIN) {
        rtb_Add_la = CONTROL_PARAM.VEL_Z_D_MIN;
      }
    }

    /* End of Saturate: '<S42>/Saturation' */

    /* Sum: '<S41>/Add' incorporates:
     *  Constant: '<S44>/kp'
     *  DiscreteIntegrator: '<S43>/Discrete-Time Integrator'
     *  Product: '<S44>/Multiply'
     */
    rtb_Add_la += CONTROL_PARAM.VEL_Z_P * rtb_Divide_idx_2 +
      Controller_DW.DiscreteTimeIntegrator_DSTAT_mf;

    /* Switch: '<S39>/Switch' incorporates:
     *  Gain: '<S39>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_Add_e = 0.0F;
    } else {
      rtb_Add_e = rtb_Divide_idx_1;
    }

    /* End of Switch: '<S39>/Switch' */

    /* Product: '<S36>/Multiply' incorporates:
     *  Constant: '<S36>/kd'
     */
    rtb_Add_e *= CONTROL_PARAM.VEL_X_D;

    /* Saturate: '<S36>/Saturation' */
    if (rtb_Add_e > CONTROL_PARAM.VEL_X_D_MAX) {
      rtb_Add_e = CONTROL_PARAM.VEL_X_D_MAX;
    } else {
      if (rtb_Add_e < CONTROL_PARAM.VEL_X_D_MIN) {
        rtb_Add_e = CONTROL_PARAM.VEL_X_D_MIN;
      }
    }

    /* End of Saturate: '<S36>/Saturation' */

    /* Sum: '<S28>/Add' incorporates:
     *  Constant: '<S38>/kp'
     *  DiscreteIntegrator: '<S37>/Discrete-Time Integrator'
     *  Product: '<S38>/Multiply'
     */
    rtb_Add_e += CONTROL_PARAM.VEL_X_P * rtb_Divide_idx_0 +
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m;

    /* Switch: '<S17>/Switch' incorporates:
     *  Gain: '<S17>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_Saturation_o_idx_0 = 0.0F;
      rtb_Saturation_o_idx_1 = 0.0F;
    } else {
      rtb_Saturation_o_idx_0 = rtb_linear_dist;
      rtb_Saturation_o_idx_1 = rtb_Sign;
    }

    /* End of Switch: '<S17>/Switch' */

    /* Product: '<S14>/Multiply' incorporates:
     *  Constant: '<S14>/q_kd'
     */
    rtb_MatrixConcatenate1_tmp_0 = CONTROL_PARAM.PITCH_RATE_D *
      rtb_Saturation_o_idx_0;

    /* Saturate: '<S14>/Saturation' */
    if (rtb_MatrixConcatenate1_tmp_0 > CONTROL_PARAM.RATE_D_MAX) {
      rtb_MatrixConcatenate1_tmp_0 = CONTROL_PARAM.RATE_D_MAX;
    } else {
      if (rtb_MatrixConcatenate1_tmp_0 < CONTROL_PARAM.RATE_D_MIN) {
        rtb_MatrixConcatenate1_tmp_0 = CONTROL_PARAM.RATE_D_MIN;
      }
    }

    rtb_Saturation_o_idx_0 = rtb_MatrixConcatenate1_tmp_0;

    /* Product: '<S14>/Multiply' incorporates:
     *  Constant: '<S14>/r_kd'
     */
    rtb_MatrixConcatenate1_tmp_0 = CONTROL_PARAM.YAW_RATE_D *
      rtb_Saturation_o_idx_1;

    /* Saturate: '<S14>/Saturation' */
    if (rtb_MatrixConcatenate1_tmp_0 > CONTROL_PARAM.RATE_D_MAX) {
      rtb_MatrixConcatenate1_tmp_0 = CONTROL_PARAM.RATE_D_MAX;
    } else {
      if (rtb_MatrixConcatenate1_tmp_0 < CONTROL_PARAM.RATE_D_MIN) {
        rtb_MatrixConcatenate1_tmp_0 = CONTROL_PARAM.RATE_D_MIN;
      }
    }

    /* Sum: '<S11>/Add' incorporates:
     *  Constant: '<S16>/q_kp'
     *  Constant: '<S16>/r_kp'
     *  DiscreteIntegrator: '<S13>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S15>/Discrete-Time Integrator'
     *  Product: '<S16>/Multiply'
     */
    rtb_Saturation_o_idx_0 += CONTROL_PARAM.PITCH_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0];
    rtb_MatrixConcatenate1_tmp_0 += CONTROL_PARAM.YAW_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1];

    /* Saturate: '<S23>/Saturation' */
    if (rtb_Add_e > 1.0F) {
      rtb_Add_e = 1.0F;
    } else {
      if (rtb_Add_e < -1.0F) {
        rtb_Add_e = -1.0F;
      }
    }

    /* Gain: '<S23>/Gain' */
    rtb_Add_e = fmodf(floorf(500.0F * rtb_Add_e), 65536.0F);

    /* Outport: '<Root>/Control_Out' incorporates:
     *  Bias: '<S23>/Bias'
     *  Gain: '<S23>/Gain'
     */
    Controller_Y.Control_Out.actuator_cmd[0] = (uint16_T)((rtb_Add_e < 0.0F ?
      (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_Add_e : (int32_T)(uint16_T)
      rtb_Add_e) + 1500U);

    /* Saturate: '<S23>/Saturation1' */
    if (rtb_MatrixConcatenate1_tmp_0 > 1.0F) {
      rtb_MatrixConcatenate1_tmp_0 = 1.0F;
    } else {
      if (rtb_MatrixConcatenate1_tmp_0 < -1.0F) {
        rtb_MatrixConcatenate1_tmp_0 = -1.0F;
      }
    }

    /* Gain: '<S23>/Gain2' */
    rtb_Add_e = fmodf(floorf(250.0F * rtb_MatrixConcatenate1_tmp_0), 65536.0F);

    /* Outport: '<Root>/Control_Out' incorporates:
     *  Bias: '<S23>/Bias2'
     *  Gain: '<S23>/Gain2'
     */
    Controller_Y.Control_Out.actuator_cmd[1] = (uint16_T)((rtb_Add_e < 0.0F ?
      (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_Add_e : (int32_T)(uint16_T)
      rtb_Add_e) + 1500U);

    /* Saturate: '<S23>/Saturation' */
    if (rtb_Add_la > 1.0F) {
      rtb_Add_la = 1.0F;
    } else {
      if (rtb_Add_la < -1.0F) {
        rtb_Add_la = -1.0F;
      }
    }

    /* Gain: '<S23>/Gain3' */
    rtb_Add_e = fmodf(floorf(500.0F * rtb_Add_la), 65536.0F);

    /* Outport: '<Root>/Control_Out' incorporates:
     *  Bias: '<S23>/Bias3'
     *  Gain: '<S23>/Gain3'
     */
    Controller_Y.Control_Out.actuator_cmd[2] = (uint16_T)((rtb_Add_e < 0.0F ?
      (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_Add_e : (int32_T)(uint16_T)
      rtb_Add_e) + 1500U);

    /* Saturate: '<S23>/Saturation1' */
    if (rtb_Saturation_o_idx_0 > 1.0F) {
      rtb_Saturation_o_idx_0 = 1.0F;
    } else {
      if (rtb_Saturation_o_idx_0 < -1.0F) {
        rtb_Saturation_o_idx_0 = -1.0F;
      }
    }

    /* Gain: '<S23>/Gain1' */
    rtb_Add_e = fmodf(floorf(500.0F * rtb_Saturation_o_idx_0), 65536.0F);

    /* Outport: '<Root>/Control_Out' incorporates:
     *  Bias: '<S23>/Bias1'
     *  Gain: '<S23>/Gain1'
     */
    Controller_Y.Control_Out.actuator_cmd[3] = (uint16_T)((rtb_Add_e < 0.0F ?
      (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_Add_e : (int32_T)(uint16_T)
      rtb_Add_e) + 1500U);
    break;

   default:
    /* Outport: '<Root>/Control_Out' */
    Controller_Y.Control_Out.actuator_cmd[0] = 1500U;
    Controller_Y.Control_Out.actuator_cmd[1] = 1500U;
    Controller_Y.Control_Out.actuator_cmd[2] = 1500U;
    Controller_Y.Control_Out.actuator_cmd[3] = 1500U;
    break;
  }

  /* End of MultiPortSwitch: '<S24>/Multiport Switch' */
  /* End of Outputs for SubSystem: '<S5>/Submarine_1' */

  /* Product: '<S15>/Multiply' incorporates:
   *  Constant: '<S15>/q_ki'
   *  Constant: '<S15>/r_ki'
   *  DiscreteIntegrator: '<S13>/Discrete-Time Integrator5'
   */
  rtb_Saturation_o_idx_0 = CONTROL_PARAM.PITCH_RATE_I *
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[0];
  rtb_Saturation_o_idx_1 = CONTROL_PARAM.YAW_RATE_I *
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1];

  /* Outport: '<Root>/Control_Out' incorporates:
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   */
  Controller_Y.Control_Out.timestamp =
    Controller_DW.DiscreteTimeIntegrator_DSTATE_n;
  for (i = 0; i < 12; i++) {
    Controller_Y.Control_Out.actuator_cmd[i + 4] = 0U;
  }

  /* Update for DiscreteIntegrator: '<S13>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;

  /* Update for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S17>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;

  /* Update for DiscreteIntegrator: '<S13>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S13>/Gain'
   *  Sum: '<S13>/Sum5'
   */
  Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] += (rtb_Divide1 -
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 188.49556F * 0.002F;

  /* Update for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE[0] += 0.002F *
    rtb_Saturation_o_idx_0;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] >= CONTROL_PARAM.RATE_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = CONTROL_PARAM.RATE_I_MIN;
    }
  }

  /* Update for DiscreteIntegrator: '<S17>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] += 0.002F * rtb_linear_dist;

  /* Update for DiscreteIntegrator: '<S13>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S13>/Gain'
   *  Sum: '<S13>/Sum5'
   */
  Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] += (rtb_theta_error_B_rad -
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 188.49556F * 0.002F;

  /* Update for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE[1] += 0.002F *
    rtb_Saturation_o_idx_1;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] >= CONTROL_PARAM.RATE_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = CONTROL_PARAM.RATE_I_MIN;
    }
  }

  /* Update for DiscreteIntegrator: '<S17>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] += 0.002F * rtb_Sign;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S37>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S37>/ki'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S37>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_m += CONTROL_PARAM.VEL_X_I *
    rtb_Divide_idx_0 * 0.002F;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m >= CONTROL_PARAM.VEL_X_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m = CONTROL_PARAM.VEL_X_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m <=
        CONTROL_PARAM.VEL_X_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m = CONTROL_PARAM.VEL_X_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRe_e = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* End of Update for DiscreteIntegrator: '<S37>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S39>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_b = 0U;
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_m += 0.002F * rtb_Divide_idx_1;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_a = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S43>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S43>/ki'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S43>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTAT_mf += CONTROL_PARAM.VEL_Z_I *
    rtb_Divide_idx_2 * 0.002F;
  if (Controller_DW.DiscreteTimeIntegrator_DSTAT_mf >= CONTROL_PARAM.VEL_Z_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTAT_mf = CONTROL_PARAM.VEL_Z_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTAT_mf <=
        CONTROL_PARAM.VEL_Z_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_mf = CONTROL_PARAM.VEL_Z_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRe_m = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* End of Update for DiscreteIntegrator: '<S43>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S45>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_k = 0U;
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_h += 0.002F *
    rtb_DiscreteTimeIntegrator1_d;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_i = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

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

  /* states (dwork) */
  (void) memset((void *)&Controller_DW, 0,
                sizeof(DW_Controller_T));

  /* external inputs */
  (void)memset(&Controller_U, 0, sizeof(ExtU_Controller_T));

  /* external outputs */
  Controller_Y.Control_Out = Controller_rtZControl_Out_Bus;

  /* Start for Constant: '<S43>/Constant' */
  Controller_DW.DiscreteTimeIntegrator_DSTAT_mf = CONTROL_PARAM.VEL_Z_I_MIN;

  /* InitializeConditions for DiscreteIntegrator: '<S13>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = Controller_ConstB.Constant;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] >= CONTROL_PARAM.RATE_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = CONTROL_PARAM.RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = Controller_ConstB.Constant;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] >= CONTROL_PARAM.RATE_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = CONTROL_PARAM.RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRese = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S17>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S37>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_m = Controller_ConstB.Constant_g;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m >= CONTROL_PARAM.VEL_X_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m = CONTROL_PARAM.VEL_X_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m <=
        CONTROL_PARAM.VEL_X_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m = CONTROL_PARAM.VEL_X_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRe_e = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S37>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S39>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_b = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_a = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S43>/Discrete-Time Integrator' */
  if (Controller_DW.DiscreteTimeIntegrator_DSTAT_mf >= CONTROL_PARAM.VEL_Z_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTAT_mf = CONTROL_PARAM.VEL_Z_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTAT_mf <=
        CONTROL_PARAM.VEL_Z_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_mf = CONTROL_PARAM.VEL_Z_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRe_m = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S43>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S45>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_k = 1U;
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
