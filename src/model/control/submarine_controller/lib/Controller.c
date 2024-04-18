/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.992
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Apr 17 16:02:33 2024
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
struct_Q9EVXjrqeRICCMmugN4tVD CONTROL_PARAM = {
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
  -0.1F,
  0.1F,
  -0.1F,
  0.1F,
  1.57079637F
} ;                                    /* Variable: CONTROL_PARAM
                                        * Referenced by:
                                        *   '<S7>/Saturation'
                                        *   '<S8>/Saturation'
                                        *   '<S19>/Constant2'
                                        *   '<S38>/kd'
                                        *   '<S38>/Saturation'
                                        *   '<S39>/ki'
                                        *   '<S39>/Discrete-Time Integrator'
                                        *   '<S40>/kp'
                                        *   '<S46>/kd'
                                        *   '<S46>/Saturation'
                                        *   '<S47>/Constant'
                                        *   '<S47>/ki'
                                        *   '<S47>/Discrete-Time Integrator'
                                        *   '<S48>/kp'
                                        *   '<S14>/kd'
                                        *   '<S14>/Saturation'
                                        *   '<S15>/ki'
                                        *   '<S15>/Discrete-Time Integrator'
                                        *   '<S16>/kp'
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
  real32_T rtb_Add3_j;
  real32_T rtb_Divide;
  real32_T rtb_Sign5;
  real32_T rtb_Add_la;
  real32_T rtb_Saturation1;
  real32_T rtb_Sign_d;
  int32_T i;
  real32_T rtb_MatrixConcatenate1_0[3];
  real32_T rtb_Saturation_idx_0;
  real32_T rtb_Divide_b_idx_2;
  real32_T u;
  real32_T rtb_MatrixConcatenate1_tmp;
  real32_T rtb_MatrixConcatenate1_tmp_0;

  /* Saturate: '<S8>/Saturation' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_U.FMS_Out.theta_cmd > CONTROL_PARAM.PITCH_CMD_LIM) {
    rtb_MatrixConcatenate1_tmp = CONTROL_PARAM.PITCH_CMD_LIM;
  } else if (Controller_U.FMS_Out.theta_cmd < -CONTROL_PARAM.PITCH_CMD_LIM) {
    rtb_MatrixConcatenate1_tmp = -CONTROL_PARAM.PITCH_CMD_LIM;
  } else {
    rtb_MatrixConcatenate1_tmp = Controller_U.FMS_Out.theta_cmd;
  }

  /* End of Saturate: '<S8>/Saturation' */

  /* Sum: '<S18>/Sum' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_theta_error_B_rad = rtb_MatrixConcatenate1_tmp -
    Controller_U.INS_Out.theta;

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
      rtb_Sign_d = -1.0F;
    } else if (rtb_theta_error_B_rad > 0.0F) {
      /* Signum: '<S21>/Sign' */
      rtb_Sign_d = 1.0F;
    } else {
      /* Signum: '<S21>/Sign' */
      rtb_Sign_d = rtb_theta_error_B_rad;
    }

    rtb_theta_error_B_rad = sqrtf((rtb_Sign_d * rtb_theta_error_B_rad - 0.5F *
      rtb_linear_dist) * Controller_ConstB.Gain) * rtb_Sign_d;
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

  /* Saturate: '<S7>/Saturation' */
  if (rtb_theta_error_B_rad > CONTROL_PARAM.Q_CMD_LIM) {
    rtb_theta_error_B_rad = CONTROL_PARAM.Q_CMD_LIM;
  } else {
    if (rtb_theta_error_B_rad < -CONTROL_PARAM.Q_CMD_LIM) {
      rtb_theta_error_B_rad = -CONTROL_PARAM.Q_CMD_LIM;
    }
  }

  /* End of Saturate: '<S7>/Saturation' */

  /* Sum: '<S10>/Sum' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Divide1 = rtb_theta_error_B_rad - Controller_U.INS_Out.q;

  /* DiscreteIntegrator: '<S13>/Discrete-Time Integrator5' */
  if (Controller_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    Controller_DW.DiscreteTimeIntegrator5_DSTATE = rtb_Divide1;
  }

  /* DiscreteIntegrator: '<S15>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator_PrevRese != 0)) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE = Controller_ConstB.Constant;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE >= CONTROL_PARAM.RATE_I_MAX)
    {
      Controller_DW.DiscreteTimeIntegrator_DSTATE = CONTROL_PARAM.RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE <=
          CONTROL_PARAM.RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE = CONTROL_PARAM.RATE_I_MIN;
      }
    }
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE >= CONTROL_PARAM.RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE <= CONTROL_PARAM.RATE_I_MIN)
    {
      Controller_DW.DiscreteTimeIntegrator_DSTATE = CONTROL_PARAM.RATE_I_MIN;
    }
  }

  /* DiscreteIntegrator: '<S17>/Discrete-Time Integrator1' incorporates:
   *  DiscreteIntegrator: '<S13>/Discrete-Time Integrator5'
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
    Controller_DW.DiscreteTimeIntegrator1_DSTATE =
      Controller_DW.DiscreteTimeIntegrator5_DSTATE;
  }

  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevRes != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTATE =
      Controller_DW.DiscreteTimeIntegrator5_DSTATE;
  }

  /* Gain: '<S17>/Gain' incorporates:
   *  DiscreteIntegrator: '<S13>/Discrete-Time Integrator5'
   *  DiscreteIntegrator: '<S17>/Discrete-Time Integrator1'
   *  Sum: '<S17>/Sum5'
   */
  rtb_theta_error_B_rad = (Controller_DW.DiscreteTimeIntegrator5_DSTATE -
    Controller_DW.DiscreteTimeIntegrator1_DSTATE) * 62.831852F;

  /* Sqrt: '<S36>/Sqrt' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Math: '<S36>/Square'
   *  Sum: '<S36>/Sum of Elements'
   */
  rtb_DiscreteTimeIntegrator1_d = sqrtf(((Controller_U.INS_Out.quat[0] *
    Controller_U.INS_Out.quat[0] + Controller_U.INS_Out.quat[1] *
    Controller_U.INS_Out.quat[1]) + Controller_U.INS_Out.quat[2] *
    Controller_U.INS_Out.quat[2]) + Controller_U.INS_Out.quat[3] *
    Controller_U.INS_Out.quat[3]);

  /* Product: '<S32>/Divide' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_linear_dist = Controller_U.INS_Out.quat[0] / rtb_DiscreteTimeIntegrator1_d;
  rtb_Sign_d = Controller_U.INS_Out.quat[1] / rtb_DiscreteTimeIntegrator1_d;
  rtb_Divide_b_idx_2 = Controller_U.INS_Out.quat[2] /
    rtb_DiscreteTimeIntegrator1_d;
  rtb_DiscreteTimeIntegrator1_d = Controller_U.INS_Out.quat[3] /
    rtb_DiscreteTimeIntegrator1_d;

  /* Math: '<S33>/Square' incorporates:
   *  Math: '<S34>/Square'
   *  Math: '<S35>/Square'
   */
  rtb_MatrixConcatenate1_tmp = rtb_linear_dist * rtb_linear_dist;

  /* Math: '<S33>/Square2' incorporates:
   *  Math: '<S34>/Square2'
   *  Math: '<S35>/Square2'
   */
  rtb_Add_la = rtb_Divide_b_idx_2 * rtb_Divide_b_idx_2;

  /* Math: '<S33>/Square1' incorporates:
   *  Math: '<S34>/Square1'
   *  Math: '<S35>/Square1'
   */
  rtb_Saturation1 = rtb_Sign_d * rtb_Sign_d;

  /* Math: '<S33>/Square3' incorporates:
   *  Math: '<S34>/Square3'
   *  Math: '<S35>/Square3'
   */
  rtb_Saturation_idx_0 = rtb_DiscreteTimeIntegrator1_d *
    rtb_DiscreteTimeIntegrator1_d;

  /* Sum: '<S33>/Subtract' incorporates:
   *  Math: '<S33>/Square'
   *  Math: '<S33>/Square1'
   *  Math: '<S33>/Square2'
   *  Math: '<S33>/Square3'
   *  Sum: '<S33>/Add'
   *  Sum: '<S33>/Add1'
   */
  rtb_MatrixConcatenate1[0] = (rtb_MatrixConcatenate1_tmp + rtb_Saturation1) -
    (rtb_Add_la + rtb_Saturation_idx_0);

  /* Product: '<S33>/Multiply' incorporates:
   *  Product: '<S34>/Multiply'
   */
  rtb_Divide = rtb_Sign_d * rtb_Divide_b_idx_2;

  /* Product: '<S33>/Multiply1' incorporates:
   *  Product: '<S34>/Multiply1'
   */
  rtb_Sign5 = rtb_linear_dist * rtb_DiscreteTimeIntegrator1_d;

  /* Gain: '<S33>/Gain' incorporates:
   *  Product: '<S33>/Multiply'
   *  Product: '<S33>/Multiply1'
   *  Sum: '<S33>/Subtract1'
   */
  rtb_MatrixConcatenate1[1] = (rtb_Divide - rtb_Sign5) * 2.0F;

  /* Product: '<S33>/Multiply2' incorporates:
   *  Product: '<S35>/Multiply'
   */
  rtb_MatrixConcatenate1_tmp_0 = rtb_Sign_d * rtb_DiscreteTimeIntegrator1_d;

  /* Product: '<S33>/Multiply3' incorporates:
   *  Product: '<S35>/Multiply1'
   */
  rtb_Add3_j = rtb_linear_dist * rtb_Divide_b_idx_2;

  /* Gain: '<S33>/Gain1' incorporates:
   *  Product: '<S33>/Multiply2'
   *  Product: '<S33>/Multiply3'
   *  Sum: '<S33>/Add2'
   */
  rtb_MatrixConcatenate1[2] = (rtb_MatrixConcatenate1_tmp_0 + rtb_Add3_j) * 2.0F;

  /* Gain: '<S34>/Gain' incorporates:
   *  Sum: '<S34>/Add3'
   */
  rtb_MatrixConcatenate1[3] = (rtb_Divide + rtb_Sign5) * 2.0F;

  /* Sum: '<S34>/Subtract' incorporates:
   *  Sum: '<S34>/Add'
   *  Sum: '<S34>/Add1'
   */
  rtb_MatrixConcatenate1[4] = (rtb_MatrixConcatenate1_tmp + rtb_Add_la) -
    (rtb_Saturation1 + rtb_Saturation_idx_0);

  /* Product: '<S34>/Multiply2' incorporates:
   *  Product: '<S35>/Multiply2'
   */
  rtb_Divide = rtb_Divide_b_idx_2 * rtb_DiscreteTimeIntegrator1_d;

  /* Product: '<S34>/Multiply3' incorporates:
   *  Product: '<S35>/Multiply3'
   */
  rtb_Sign5 = rtb_linear_dist * rtb_Sign_d;

  /* Gain: '<S34>/Gain1' incorporates:
   *  Product: '<S34>/Multiply2'
   *  Product: '<S34>/Multiply3'
   *  Sum: '<S34>/Subtract1'
   */
  rtb_MatrixConcatenate1[5] = (rtb_Divide - rtb_Sign5) * 2.0F;

  /* Gain: '<S35>/Gain' incorporates:
   *  Sum: '<S35>/Subtract2'
   */
  rtb_MatrixConcatenate1[6] = (rtb_MatrixConcatenate1_tmp_0 - rtb_Add3_j) * 2.0F;

  /* Gain: '<S35>/Gain1' incorporates:
   *  Sum: '<S35>/Add2'
   */
  rtb_MatrixConcatenate1[7] = (rtb_Divide + rtb_Sign5) * 2.0F;

  /* Sum: '<S35>/Subtract' incorporates:
   *  Sum: '<S35>/Add'
   *  Sum: '<S35>/Add1'
   */
  rtb_MatrixConcatenate1[8] = (rtb_MatrixConcatenate1_tmp + rtb_Saturation_idx_0)
    - (rtb_Saturation1 + rtb_Add_la);

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
   *  DiscreteIntegrator: '<S30>/Integrator1'
   */
  rtb_linear_dist = Controller_DW.Integrator1_DSTATE - rtb_MatrixConcatenate1_0
    [0];

  /* DiscreteIntegrator: '<S39>/Discrete-Time Integrator' incorporates:
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

  /* DiscreteIntegrator: '<S41>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_b != 0) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_m = rtb_linear_dist;
  }

  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevR_a != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_m = rtb_linear_dist;
  }

  /* Gain: '<S41>/Gain' incorporates:
   *  DiscreteIntegrator: '<S41>/Discrete-Time Integrator1'
   *  Sum: '<S41>/Sum5'
   */
  rtb_Sign_d = (rtb_linear_dist - Controller_DW.DiscreteTimeIntegrator1_DSTAT_m)
    * 62.831852F;

  /* Sum: '<S42>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S44>/Integrator1'
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Divide_b_idx_2 = Controller_DW.Integrator1_DSTATE_p -
    Controller_U.INS_Out.vd;

  /* DiscreteIntegrator: '<S47>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S47>/Constant'
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

  /* DiscreteIntegrator: '<S49>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_k != 0) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_h = rtb_Divide_b_idx_2;
  }

  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevR_i != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_h = rtb_Divide_b_idx_2;
  }

  /* Gain: '<S49>/Gain' incorporates:
   *  DiscreteIntegrator: '<S49>/Discrete-Time Integrator1'
   *  Sum: '<S49>/Sum5'
   */
  rtb_DiscreteTimeIntegrator1_d = (rtb_Divide_b_idx_2 -
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_h) * 62.831852F;

  /* Outputs for Atomic SubSystem: '<S5>/Submarine_1' */
  /* MultiPortSwitch: '<S24>/Multiport Switch' incorporates:
   *  Inport: '<Root>/FMS_Out'
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
    /* Switch: '<S49>/Switch' incorporates:
     *  Gain: '<S49>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_MatrixConcatenate1_tmp = 0.0F;
    } else {
      rtb_MatrixConcatenate1_tmp = rtb_DiscreteTimeIntegrator1_d;
    }

    /* End of Switch: '<S49>/Switch' */

    /* Product: '<S46>/Multiply' incorporates:
     *  Constant: '<S46>/kd'
     */
    rtb_Add_la = CONTROL_PARAM.VEL_Z_D * rtb_MatrixConcatenate1_tmp;

    /* Saturate: '<S46>/Saturation' */
    if (rtb_Add_la > CONTROL_PARAM.VEL_Z_D_MAX) {
      rtb_Add_la = CONTROL_PARAM.VEL_Z_D_MAX;
    } else {
      if (rtb_Add_la < CONTROL_PARAM.VEL_Z_D_MIN) {
        rtb_Add_la = CONTROL_PARAM.VEL_Z_D_MIN;
      }
    }

    /* End of Saturate: '<S46>/Saturation' */

    /* Sum: '<S43>/Add' incorporates:
     *  Constant: '<S48>/kp'
     *  DiscreteIntegrator: '<S47>/Discrete-Time Integrator'
     *  Product: '<S48>/Multiply'
     */
    rtb_Add_la += CONTROL_PARAM.VEL_Z_P * rtb_Divide_b_idx_2 +
      Controller_DW.DiscreteTimeIntegrator_DSTAT_mf;

    /* Switch: '<S41>/Switch' incorporates:
     *  Gain: '<S41>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_MatrixConcatenate1_tmp = 0.0F;
    } else {
      rtb_MatrixConcatenate1_tmp = rtb_Sign_d;
    }

    /* End of Switch: '<S41>/Switch' */

    /* Product: '<S38>/Multiply' incorporates:
     *  Constant: '<S38>/kd'
     */
    rtb_Saturation1 = CONTROL_PARAM.VEL_X_D * rtb_MatrixConcatenate1_tmp;

    /* Saturate: '<S38>/Saturation' */
    if (rtb_Saturation1 > CONTROL_PARAM.VEL_X_D_MAX) {
      rtb_Saturation1 = CONTROL_PARAM.VEL_X_D_MAX;
    } else {
      if (rtb_Saturation1 < CONTROL_PARAM.VEL_X_D_MIN) {
        rtb_Saturation1 = CONTROL_PARAM.VEL_X_D_MIN;
      }
    }

    /* End of Saturate: '<S38>/Saturation' */

    /* Sum: '<S28>/Add' incorporates:
     *  Constant: '<S40>/kp'
     *  DiscreteIntegrator: '<S39>/Discrete-Time Integrator'
     *  Product: '<S40>/Multiply'
     */
    rtb_Saturation1 += CONTROL_PARAM.VEL_X_P * rtb_linear_dist +
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m;

    /* Saturate: '<S23>/Saturation' */
    if (rtb_Saturation1 > 1.0F) {
      rtb_Saturation_idx_0 = 1.0F;
    } else if (rtb_Saturation1 < -1.0F) {
      rtb_Saturation_idx_0 = -1.0F;
    } else {
      rtb_Saturation_idx_0 = rtb_Saturation1;
    }

    /* Switch: '<S17>/Switch' incorporates:
     *  Gain: '<S17>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_MatrixConcatenate1_tmp = 0.0F;
    } else {
      rtb_MatrixConcatenate1_tmp = rtb_theta_error_B_rad;
    }

    /* End of Switch: '<S17>/Switch' */

    /* Product: '<S14>/Multiply' incorporates:
     *  Constant: '<S14>/kd'
     */
    rtb_Saturation1 = CONTROL_PARAM.PITCH_RATE_I * rtb_MatrixConcatenate1_tmp;

    /* Saturate: '<S14>/Saturation' */
    if (rtb_Saturation1 > CONTROL_PARAM.RATE_D_MAX) {
      rtb_Saturation1 = CONTROL_PARAM.RATE_D_MAX;
    } else {
      if (rtb_Saturation1 < CONTROL_PARAM.RATE_D_MIN) {
        rtb_Saturation1 = CONTROL_PARAM.RATE_D_MIN;
      }
    }

    /* End of Saturate: '<S14>/Saturation' */

    /* Sum: '<S11>/Add' incorporates:
     *  Constant: '<S16>/kp'
     *  DiscreteIntegrator: '<S13>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S15>/Discrete-Time Integrator'
     *  Product: '<S16>/Multiply'
     */
    rtb_Saturation1 += CONTROL_PARAM.PITCH_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTATE +
      Controller_DW.DiscreteTimeIntegrator_DSTATE;

    /* Saturate: '<S23>/Saturation1' */
    if (rtb_Saturation1 > 1.0F) {
      rtb_Saturation1 = 1.0F;
    } else {
      if (rtb_Saturation1 < -1.0F) {
        rtb_Saturation1 = -1.0F;
      }
    }

    /* End of Saturate: '<S23>/Saturation1' */

    /* Gain: '<S23>/Gain' */
    rtb_MatrixConcatenate1_tmp = fmodf(floorf(500.0F * rtb_Saturation_idx_0),
      65536.0F);

    /* Outport: '<Root>/Control_Out' incorporates:
     *  Bias: '<S23>/Bias'
     *  Gain: '<S23>/Gain'
     */
    Controller_Y.Control_Out.actuator_cmd[0] = (uint16_T)
      ((rtb_MatrixConcatenate1_tmp < 0.0F ? (int32_T)(uint16_T)-(int16_T)
        (uint16_T)-rtb_MatrixConcatenate1_tmp : (int32_T)(uint16_T)
        rtb_MatrixConcatenate1_tmp) + 1500U);

    /* Saturate: '<S23>/Saturation' */
    if (Controller_U.FMS_Out.ay_cmd > 1.0F) {
      rtb_MatrixConcatenate1_tmp = 1.0F;
    } else if (Controller_U.FMS_Out.ay_cmd < -1.0F) {
      rtb_MatrixConcatenate1_tmp = -1.0F;
    } else {
      rtb_MatrixConcatenate1_tmp = Controller_U.FMS_Out.ay_cmd;
    }

    /* Gain: '<S23>/Gain2' */
    rtb_MatrixConcatenate1_tmp = fmodf(floorf(250.0F *
      rtb_MatrixConcatenate1_tmp), 65536.0F);

    /* Outport: '<Root>/Control_Out' incorporates:
     *  Bias: '<S23>/Bias2'
     *  Gain: '<S23>/Gain2'
     */
    Controller_Y.Control_Out.actuator_cmd[1] = (uint16_T)
      ((rtb_MatrixConcatenate1_tmp < 0.0F ? (int32_T)(uint16_T)-(int16_T)
        (uint16_T)-rtb_MatrixConcatenate1_tmp : (int32_T)(uint16_T)
        rtb_MatrixConcatenate1_tmp) + 1500U);

    /* Saturate: '<S23>/Saturation' */
    if (rtb_Add_la > 1.0F) {
      rtb_Add_la = 1.0F;
    } else {
      if (rtb_Add_la < -1.0F) {
        rtb_Add_la = -1.0F;
      }
    }

    /* Gain: '<S23>/Gain3' */
    rtb_MatrixConcatenate1_tmp = fmodf(floorf(500.0F * rtb_Add_la), 65536.0F);

    /* Outport: '<Root>/Control_Out' incorporates:
     *  Bias: '<S23>/Bias3'
     *  Gain: '<S23>/Gain3'
     */
    Controller_Y.Control_Out.actuator_cmd[2] = (uint16_T)
      ((rtb_MatrixConcatenate1_tmp < 0.0F ? (int32_T)(uint16_T)-(int16_T)
        (uint16_T)-rtb_MatrixConcatenate1_tmp : (int32_T)(uint16_T)
        rtb_MatrixConcatenate1_tmp) + 1500U);

    /* Gain: '<S23>/Gain1' */
    rtb_MatrixConcatenate1_tmp = fmodf(floorf(500.0F * rtb_Saturation1),
      65536.0F);

    /* Outport: '<Root>/Control_Out' incorporates:
     *  Bias: '<S23>/Bias1'
     *  Gain: '<S23>/Gain1'
     */
    Controller_Y.Control_Out.actuator_cmd[3] = (uint16_T)
      ((rtb_MatrixConcatenate1_tmp < 0.0F ? (int32_T)(uint16_T)-(int16_T)
        (uint16_T)-rtb_MatrixConcatenate1_tmp : (int32_T)(uint16_T)
        rtb_MatrixConcatenate1_tmp) + 1500U);
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

  /* Outport: '<Root>/Control_Out' incorporates:
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   */
  Controller_Y.Control_Out.timestamp =
    Controller_DW.DiscreteTimeIntegrator_DSTATE_n;
  for (i = 0; i < 12; i++) {
    Controller_Y.Control_Out.actuator_cmd[i + 4] = 0U;
  }

  /* Product: '<S45>/Multiply1' incorporates:
   *  Constant: '<S45>/const1'
   *  DiscreteIntegrator: '<S44>/Integrator'
   */
  rtb_Add3_j = Controller_DW.Integrator_DSTATE * 0.05F;

  /* Sum: '<S45>/Add' incorporates:
   *  DiscreteIntegrator: '<S44>/Integrator1'
   *  Inport: '<Root>/FMS_Out'
   *  Sum: '<S44>/Subtract'
   */
  rtb_Add_la = (Controller_DW.Integrator1_DSTATE_p - Controller_U.FMS_Out.w_cmd)
    + rtb_Add3_j;

  /* Signum: '<S45>/Sign' */
  if (rtb_Add_la < 0.0F) {
    rtb_Saturation_idx_0 = -1.0F;
  } else if (rtb_Add_la > 0.0F) {
    rtb_Saturation_idx_0 = 1.0F;
  } else {
    rtb_Saturation_idx_0 = rtb_Add_la;
  }

  /* End of Signum: '<S45>/Sign' */

  /* Sum: '<S45>/Add2' incorporates:
   *  Abs: '<S45>/Abs'
   *  Gain: '<S45>/Gain'
   *  Gain: '<S45>/Gain1'
   *  Product: '<S45>/Multiply2'
   *  Product: '<S45>/Multiply3'
   *  Sqrt: '<S45>/Sqrt'
   *  Sum: '<S45>/Add1'
   *  Sum: '<S45>/Subtract'
   */
  rtb_Saturation_idx_0 = (sqrtf((8.0F * fabsf(rtb_Add_la) + Controller_ConstB.d)
    * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F * rtb_Saturation_idx_0
    + rtb_Add3_j;

  /* Sum: '<S45>/Add4' */
  rtb_Saturation1 = (rtb_Add_la - rtb_Saturation_idx_0) + rtb_Add3_j;

  /* Sum: '<S45>/Add3' */
  rtb_MatrixConcatenate1_tmp = rtb_Add_la + Controller_ConstB.d;

  /* Sum: '<S45>/Subtract1' */
  rtb_Add_la -= Controller_ConstB.d;

  /* Signum: '<S45>/Sign1' */
  if (rtb_MatrixConcatenate1_tmp < 0.0F) {
    rtb_MatrixConcatenate1_tmp = -1.0F;
  } else {
    if (rtb_MatrixConcatenate1_tmp > 0.0F) {
      rtb_MatrixConcatenate1_tmp = 1.0F;
    }
  }

  /* End of Signum: '<S45>/Sign1' */

  /* Signum: '<S45>/Sign2' */
  if (rtb_Add_la < 0.0F) {
    rtb_Add_la = -1.0F;
  } else {
    if (rtb_Add_la > 0.0F) {
      rtb_Add_la = 1.0F;
    }
  }

  /* End of Signum: '<S45>/Sign2' */

  /* Sum: '<S45>/Add5' incorporates:
   *  Gain: '<S45>/Gain2'
   *  Product: '<S45>/Multiply4'
   *  Sum: '<S45>/Subtract2'
   */
  rtb_Saturation_idx_0 += (rtb_MatrixConcatenate1_tmp - rtb_Add_la) * 0.5F *
    rtb_Saturation1;

  /* Sum: '<S45>/Subtract3' */
  rtb_MatrixConcatenate1_tmp = rtb_Saturation_idx_0 - Controller_ConstB.d;

  /* Sum: '<S45>/Add6' */
  rtb_Saturation1 = rtb_Saturation_idx_0 + Controller_ConstB.d;

  /* Product: '<S45>/Divide' */
  rtb_Divide = rtb_Saturation_idx_0 / Controller_ConstB.d;

  /* Signum: '<S45>/Sign5' incorporates:
   *  Signum: '<S45>/Sign6'
   */
  if (rtb_Saturation_idx_0 < 0.0F) {
    rtb_Sign5 = -1.0F;
    rtb_MatrixConcatenate1_tmp_0 = -1.0F;
  } else if (rtb_Saturation_idx_0 > 0.0F) {
    rtb_Sign5 = 1.0F;
    rtb_MatrixConcatenate1_tmp_0 = 1.0F;
  } else {
    rtb_Sign5 = rtb_Saturation_idx_0;
    rtb_MatrixConcatenate1_tmp_0 = rtb_Saturation_idx_0;
  }

  /* End of Signum: '<S45>/Sign5' */

  /* Product: '<S37>/Multiply1' incorporates:
   *  Constant: '<S37>/const1'
   *  DiscreteIntegrator: '<S30>/Integrator'
   */
  rtb_Add3_j = Controller_DW.Integrator_DSTATE_o * 0.05F;

  /* Sum: '<S37>/Add' incorporates:
   *  DiscreteIntegrator: '<S30>/Integrator1'
   *  Inport: '<Root>/FMS_Out'
   *  Sum: '<S30>/Subtract'
   */
  rtb_Saturation_idx_0 = (Controller_DW.Integrator1_DSTATE -
    Controller_U.FMS_Out.u_cmd) + rtb_Add3_j;

  /* Signum: '<S37>/Sign' */
  if (rtb_Saturation_idx_0 < 0.0F) {
    rtb_Add_la = -1.0F;
  } else if (rtb_Saturation_idx_0 > 0.0F) {
    rtb_Add_la = 1.0F;
  } else {
    rtb_Add_la = rtb_Saturation_idx_0;
  }

  /* End of Signum: '<S37>/Sign' */

  /* Sum: '<S37>/Add2' incorporates:
   *  Abs: '<S37>/Abs'
   *  Gain: '<S37>/Gain'
   *  Gain: '<S37>/Gain1'
   *  Product: '<S37>/Multiply2'
   *  Product: '<S37>/Multiply3'
   *  Sqrt: '<S37>/Sqrt'
   *  Sum: '<S37>/Add1'
   *  Sum: '<S37>/Subtract'
   */
  rtb_Add_la = (sqrtf((8.0F * fabsf(rtb_Saturation_idx_0) +
                       Controller_ConstB.d_e) * Controller_ConstB.d_e) -
                Controller_ConstB.d_e) * 0.5F * rtb_Add_la + rtb_Add3_j;

  /* Sum: '<S37>/Add4' */
  rtb_Add3_j += rtb_Saturation_idx_0 - rtb_Add_la;

  /* Sum: '<S37>/Add3' */
  u = rtb_Saturation_idx_0 + Controller_ConstB.d_e;

  /* Sum: '<S37>/Subtract1' */
  rtb_Saturation_idx_0 -= Controller_ConstB.d_e;

  /* Signum: '<S37>/Sign1' */
  if (u < 0.0F) {
    u = -1.0F;
  } else {
    if (u > 0.0F) {
      u = 1.0F;
    }
  }

  /* End of Signum: '<S37>/Sign1' */

  /* Signum: '<S37>/Sign2' */
  if (rtb_Saturation_idx_0 < 0.0F) {
    rtb_Saturation_idx_0 = -1.0F;
  } else {
    if (rtb_Saturation_idx_0 > 0.0F) {
      rtb_Saturation_idx_0 = 1.0F;
    }
  }

  /* End of Signum: '<S37>/Sign2' */

  /* Sum: '<S37>/Add5' incorporates:
   *  Gain: '<S37>/Gain2'
   *  Product: '<S37>/Multiply4'
   *  Sum: '<S37>/Subtract2'
   */
  rtb_Add_la += (u - rtb_Saturation_idx_0) * 0.5F * rtb_Add3_j;

  /* Product: '<S15>/Multiply' incorporates:
   *  Constant: '<S15>/ki'
   *  DiscreteIntegrator: '<S13>/Discrete-Time Integrator5'
   */
  rtb_Saturation_idx_0 = CONTROL_PARAM.PITCH_RATE_I *
    Controller_DW.DiscreteTimeIntegrator5_DSTATE;

  /* Update for DiscreteIntegrator: '<S13>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S13>/Gain'
   *  Sum: '<S13>/Sum5'
   */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;
  Controller_DW.DiscreteTimeIntegrator5_DSTATE += (rtb_Divide1 -
    Controller_DW.DiscreteTimeIntegrator5_DSTATE) * 188.49556F * 0.002F;

  /* Update for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE += 0.002F * rtb_Saturation_idx_0;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE >= CONTROL_PARAM.RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE <= CONTROL_PARAM.RATE_I_MIN)
    {
      Controller_DW.DiscreteTimeIntegrator_DSTATE = CONTROL_PARAM.RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* End of Update for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S17>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;
  Controller_DW.DiscreteTimeIntegrator1_DSTATE += 0.002F * rtb_theta_error_B_rad;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S30>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S30>/Integrator'
   */
  Controller_DW.Integrator1_DSTATE += 0.002F * Controller_DW.Integrator_DSTATE_o;

  /* Update for DiscreteIntegrator: '<S39>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S39>/ki'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S39>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_m += CONTROL_PARAM.VEL_X_I *
    rtb_linear_dist * 0.002F;
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

  /* End of Update for DiscreteIntegrator: '<S39>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S41>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_b = 0U;
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_m += 0.002F * rtb_Sign_d;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_a = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S44>/Integrator1' incorporates:
   *  DiscreteIntegrator: '<S44>/Integrator'
   */
  Controller_DW.Integrator1_DSTATE_p += 0.002F * Controller_DW.Integrator_DSTATE;

  /* Update for DiscreteIntegrator: '<S47>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S47>/ki'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S47>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTAT_mf += CONTROL_PARAM.VEL_Z_I *
    rtb_Divide_b_idx_2 * 0.002F;
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

  /* End of Update for DiscreteIntegrator: '<S47>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S49>/Discrete-Time Integrator1' incorporates:
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

  /* Signum: '<S45>/Sign3' */
  if (rtb_Saturation1 < 0.0F) {
    rtb_Saturation1 = -1.0F;
  } else {
    if (rtb_Saturation1 > 0.0F) {
      rtb_Saturation1 = 1.0F;
    }
  }

  /* End of Signum: '<S45>/Sign3' */

  /* Signum: '<S45>/Sign4' */
  if (rtb_MatrixConcatenate1_tmp < 0.0F) {
    rtb_MatrixConcatenate1_tmp = -1.0F;
  } else {
    if (rtb_MatrixConcatenate1_tmp > 0.0F) {
      rtb_MatrixConcatenate1_tmp = 1.0F;
    }
  }

  /* End of Signum: '<S45>/Sign4' */

  /* Update for DiscreteIntegrator: '<S44>/Integrator' incorporates:
   *  Constant: '<S45>/const'
   *  Gain: '<S45>/Gain3'
   *  Product: '<S45>/Multiply5'
   *  Product: '<S45>/Multiply6'
   *  Sum: '<S45>/Subtract4'
   *  Sum: '<S45>/Subtract5'
   *  Sum: '<S45>/Subtract6'
   */
  Controller_DW.Integrator_DSTATE += ((rtb_Divide - rtb_Sign5) *
    Controller_ConstB.Gain4 * ((rtb_Saturation1 - rtb_MatrixConcatenate1_tmp) *
    0.5F) - rtb_MatrixConcatenate1_tmp_0 * 78.448F) * 0.002F;

  /* Sum: '<S37>/Add6' */
  rtb_MatrixConcatenate1_tmp = rtb_Add_la + Controller_ConstB.d_e;

  /* Sum: '<S37>/Subtract3' */
  rtb_Saturation1 = rtb_Add_la - Controller_ConstB.d_e;

  /* Signum: '<S37>/Sign5' */
  if (rtb_Add_la < 0.0F) {
    rtb_Saturation_idx_0 = -1.0F;
  } else if (rtb_Add_la > 0.0F) {
    rtb_Saturation_idx_0 = 1.0F;
  } else {
    rtb_Saturation_idx_0 = rtb_Add_la;
  }

  /* End of Signum: '<S37>/Sign5' */

  /* Signum: '<S37>/Sign3' */
  if (rtb_MatrixConcatenate1_tmp < 0.0F) {
    rtb_MatrixConcatenate1_tmp = -1.0F;
  } else {
    if (rtb_MatrixConcatenate1_tmp > 0.0F) {
      rtb_MatrixConcatenate1_tmp = 1.0F;
    }
  }

  /* End of Signum: '<S37>/Sign3' */

  /* Signum: '<S37>/Sign4' */
  if (rtb_Saturation1 < 0.0F) {
    rtb_Saturation1 = -1.0F;
  } else {
    if (rtb_Saturation1 > 0.0F) {
      rtb_Saturation1 = 1.0F;
    }
  }

  /* End of Signum: '<S37>/Sign4' */

  /* Signum: '<S37>/Sign6' */
  if (rtb_Add_la < 0.0F) {
    rtb_Divide1 = -1.0F;
  } else if (rtb_Add_la > 0.0F) {
    rtb_Divide1 = 1.0F;
  } else {
    rtb_Divide1 = rtb_Add_la;
  }

  /* End of Signum: '<S37>/Sign6' */

  /* Update for DiscreteIntegrator: '<S30>/Integrator' incorporates:
   *  Constant: '<S37>/const'
   *  Gain: '<S37>/Gain3'
   *  Product: '<S37>/Divide'
   *  Product: '<S37>/Multiply5'
   *  Product: '<S37>/Multiply6'
   *  Sum: '<S37>/Subtract4'
   *  Sum: '<S37>/Subtract5'
   *  Sum: '<S37>/Subtract6'
   */
  Controller_DW.Integrator_DSTATE_o += ((rtb_Add_la / Controller_ConstB.d_e -
    rtb_Saturation_idx_0) * Controller_ConstB.Gain4_d *
    ((rtb_MatrixConcatenate1_tmp - rtb_Saturation1) * 0.5F) - rtb_Divide1 *
    58.836F) * 0.002F;
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

  /* Start for Constant: '<S47>/Constant' */
  Controller_DW.DiscreteTimeIntegrator_DSTAT_mf = CONTROL_PARAM.VEL_Z_I_MIN;

  /* InitializeConditions for DiscreteIntegrator: '<S13>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE = Controller_ConstB.Constant;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE >= CONTROL_PARAM.RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE <= CONTROL_PARAM.RATE_I_MIN)
    {
      Controller_DW.DiscreteTimeIntegrator_DSTATE = CONTROL_PARAM.RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRese = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S17>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S39>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S39>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S41>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_b = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_a = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S47>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S47>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S49>/Discrete-Time Integrator1' */
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
