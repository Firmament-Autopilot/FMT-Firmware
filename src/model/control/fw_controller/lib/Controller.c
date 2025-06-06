/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.1110
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Jun  6 13:51:52 2025
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
struct_cGQ7mab9VSTQmeIosgrbRH CONTROL_PARAM = {
  7.0F,
  7.0F,
  1.04719758F,
  0.1F,
  0.2F,
  0.15F,
  0.1F,
  0.1F,
  0.2F,
  -0.1F,
  0.1F,
  1.57079637F,
  3.14159274F,
  15.0F,
  0.2F,
  0.3F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  0.0F,
  0.5F,
  0.1F,
  0.1F,
  0.4F,
  0.1F,
  0.2F,
  0.2F,
  0.1F,
  0.0F,
  0.0F,
  1.0F,
  1.0F,
  1.0F,
  2.0F,
  0.2F,
  0.1F,
  0.1F
} ;                                    /* Variable: CONTROL_PARAM
                                        * Referenced by:
                                        *   '<S7>/Saturation'
                                        *   '<S8>/Gain'
                                        *   '<S8>/Gain1'
                                        *   '<S8>/balabnce_ratio2'
                                        *   '<S8>/balance_ratio'
                                        *   '<S8>/pitch_ff'
                                        *   '<S8>/thorttle_ff'
                                        *   '<S8>/ucmd2pitch'
                                        *   '<S8>/ucmd2thor'
                                        *   '<S8>/wcmd2pitch'
                                        *   '<S8>/wcmd2thor'
                                        *   '<S10>/FF'
                                        *   '<S10>/FF_limit'
                                        *   '<S10>/PI_limit'
                                        *   '<S37>/P_control'
                                        *   '<S38>/P_control'
                                        *   '<S14>/trim_speed'
                                        *   '<S15>/trim_speed'
                                        *   '<S28>/Constant1'
                                        *   '<S28>/Constant12'
                                        *   '<S28>/Constant2'
                                        *   '<S28>/Constant7'
                                        *   '<S41>/Gain'
                                        *   '<S42>/ '
                                        *   '<S42>/Gain3'
                                        *   '<S44>/Gain'
                                        *   '<S45>/ '
                                        *   '<S45>/Gain'
                                        *   '<S16>/gain1'
                                        *   '<S16>/gain2'
                                        *   '<S16>/gain3'
                                        *   '<S16>/Discrete-Time Integrator'
                                        *   '<S17>/gain1'
                                        *   '<S17>/gain2'
                                        *   '<S17>/gain3'
                                        *   '<S21>/Pitch Offset'
                                        *   '<S21>/Saturation'
                                        *   '<S22>/Constant1'
                                        *   '<S22>/Constant2'
                                        */

struct_ny3PY9hontv4J5WqwlFzJB CONTROL_EXPORT = {
  2U,

  { 70, 87, 32, 67, 111, 110, 116, 114, 111, 108, 108, 101, 114, 32, 118, 49, 46,
    48, 46, 48, 0 }
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
  real32_T rtb_DiscreteTimeIntegrator1_l;
  real32_T rtb_Saturation;
  real32_T rtb_Abs;
  real32_T rtb_Minus;
  real32_T rtb_Atan1;
  real32_T rtb_VdotPg;
  real32_T rtb_VdotPg_err;
  real32_T rtb_MatrixConcatenate1[9];
  real32_T rtb_Multiply_g[3];
  real32_T rtb_Cos1;
  real32_T rtb_Sum_p;
  real32_T rtb_Cos;
  real32_T rtb_MatrixConcatenate[12];
  uint16_T rtb_throttle_cmd;
  real32_T rtb_Saturation_l;
  real32_T rtb_Add_a;
  uint16_T rtb_MultiportSwitch[6];
  int32_T i;
  real32_T rtb_Multiply_d_idx_1;
  real32_T rtb_Divide_k_idx_0;
  real32_T rtb_Divide_k_idx_1;
  real32_T rtb_Divide_k_idx_2;
  real32_T rtb_MatrixConcatenate1_tmp;
  real32_T rtb_MatrixConcatenate1_tmp_0;

  /* Switch: '<S4>/Switch' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Math: '<S4>/Square'
   *  Math: '<S4>/Square1'
   *  S-Function (sfix_bitop): '<S4>/Bitwise AND'
   *  Sqrt: '<S4>/Sqrt'
   *  Sum: '<S4>/Add'
   */
  if ((Controller_U.INS_Out.flag & 512U) > 0U) {
    rtb_DiscreteTimeIntegrator1_l = Controller_U.INS_Out.airspeed;
  } else {
    rtb_DiscreteTimeIntegrator1_l = sqrtf(Controller_U.INS_Out.vn *
      Controller_U.INS_Out.vn + Controller_U.INS_Out.ve *
      Controller_U.INS_Out.ve);
  }

  /* End of Switch: '<S4>/Switch' */

  /* Saturate: '<S4>/Saturation' */
  if (rtb_DiscreteTimeIntegrator1_l > 100.0F) {
    rtb_Saturation = 100.0F;
  } else if (rtb_DiscreteTimeIntegrator1_l < 0.1F) {
    rtb_Saturation = 0.1F;
  } else {
    rtb_Saturation = rtb_DiscreteTimeIntegrator1_l;
  }

  /* End of Saturate: '<S4>/Saturation' */

  /* DiscreteIntegrator: '<S9>/Discrete-Time Integrator5' */
  if (Controller_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    Controller_DW.DiscreteTimeIntegrator5_DSTATE = rtb_Saturation;
  }

  /* Trigonometry: '<S7>/Atan' incorporates:
   *  Gain: '<S7>/g_force'
   *  Inport: '<Root>/FMS_Out'
   *  Sum: '<S7>/Minus'
   */
  rtb_DiscreteTimeIntegrator1_l = atanf(0.101936802F *
    Controller_U.FMS_Out.ay_cmd);

  /* Saturate: '<S7>/Saturation' */
  if (rtb_DiscreteTimeIntegrator1_l > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
    rtb_DiscreteTimeIntegrator1_l = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
  } else {
    if (rtb_DiscreteTimeIntegrator1_l < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      rtb_DiscreteTimeIntegrator1_l = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    }
  }

  /* End of Saturate: '<S7>/Saturation' */

  /* Switch: '<S20>/Switch' incorporates:
   *  Inport: '<Root>/FMS_Out'
   *  Logic: '<S20>/Logical Operator'
   *  RelationalOperator: '<S25>/Compare'
   */
  if ((Controller_U.FMS_Out.ctrl_mode == 3) || (Controller_U.FMS_Out.ctrl_mode ==
       4)) {
    rtb_Cos1 = Controller_U.FMS_Out.phi_cmd;
  } else {
    rtb_Cos1 = rtb_DiscreteTimeIntegrator1_l;
  }

  /* End of Switch: '<S20>/Switch' */

  /* Switch: '<S36>/Switch' incorporates:
   *  Constant: '<S40>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  RelationalOperator: '<S40>/Compare'
   */
  if (Controller_U.FMS_Out.ctrl_mode == 4) {
    rtb_DiscreteTimeIntegrator1_l = Controller_U.FMS_Out.phi_cmd;
  }

  /* End of Switch: '<S36>/Switch' */

  /* Abs: '<S8>/Abs' */
  rtb_Abs = fabsf(rtb_DiscreteTimeIntegrator1_l);

  /* Sqrt: '<S35>/Sqrt' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Math: '<S35>/Square'
   *  Math: '<S35>/Square1'
   *  Sum: '<S35>/Add'
   */
  rtb_DiscreteTimeIntegrator1_l = sqrtf(Controller_U.INS_Out.vn *
    Controller_U.INS_Out.vn + Controller_U.INS_Out.ve * Controller_U.INS_Out.ve);

  /* Saturate: '<S35>/Saturation' incorporates:
   *  Sqrt: '<S35>/Sqrt'
   */
  if (rtb_DiscreteTimeIntegrator1_l > 100.0F) {
    rtb_DiscreteTimeIntegrator1_l = 100.0F;
  } else {
    if (rtb_DiscreteTimeIntegrator1_l < 8.0F) {
      rtb_DiscreteTimeIntegrator1_l = 8.0F;
    }
  }

  /* End of Saturate: '<S35>/Saturation' */

  /* DeadZone: '<S35>/Dead Zone1' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  if (Controller_U.INS_Out.vd > 0.1F) {
    rtb_Saturation_l = Controller_U.INS_Out.vd - 0.1F;
  } else if (Controller_U.INS_Out.vd >= -0.1F) {
    rtb_Saturation_l = 0.0F;
  } else {
    rtb_Saturation_l = Controller_U.INS_Out.vd - -0.1F;
  }

  /* End of DeadZone: '<S35>/Dead Zone1' */

  /* Trigonometry: '<S35>/Atan1' incorporates:
   *  Gain: '<S35>/Gain2'
   *  Product: '<S35>/Divide1'
   */
  rtb_Atan1 = atanf(1.0F / rtb_DiscreteTimeIntegrator1_l * -rtb_Saturation_l);

  /* Gain: '<S39>/Gain1' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_VdotPg = 0.101936802F * Controller_U.INS_Out.ax;

  /* Sum: '<S35>/Minus' incorporates:
   *  Gain: '<S35>/Gain'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S35>/Divide'
   *  Trigonometry: '<S35>/Atan'
   */
  rtb_Minus = atanf(-Controller_U.FMS_Out.w_cmd / rtb_DiscreteTimeIntegrator1_l)
    - rtb_Atan1;

  /* Sqrt: '<S54>/Sqrt' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Math: '<S54>/Square'
   *  Sum: '<S54>/Sum of Elements'
   */
  rtb_DiscreteTimeIntegrator1_l = sqrtf(((Controller_U.INS_Out.quat[0] *
    Controller_U.INS_Out.quat[0] + Controller_U.INS_Out.quat[1] *
    Controller_U.INS_Out.quat[1]) + Controller_U.INS_Out.quat[2] *
    Controller_U.INS_Out.quat[2]) + Controller_U.INS_Out.quat[3] *
    Controller_U.INS_Out.quat[3]);

  /* Product: '<S50>/Divide' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Divide_k_idx_0 = Controller_U.INS_Out.quat[0] /
    rtb_DiscreteTimeIntegrator1_l;
  rtb_Divide_k_idx_1 = Controller_U.INS_Out.quat[1] /
    rtb_DiscreteTimeIntegrator1_l;
  rtb_Divide_k_idx_2 = Controller_U.INS_Out.quat[2] /
    rtb_DiscreteTimeIntegrator1_l;
  rtb_DiscreteTimeIntegrator1_l = Controller_U.INS_Out.quat[3] /
    rtb_DiscreteTimeIntegrator1_l;

  /* Math: '<S51>/Square' incorporates:
   *  Math: '<S52>/Square'
   *  Math: '<S53>/Square'
   */
  rtb_Add_a = rtb_Divide_k_idx_0 * rtb_Divide_k_idx_0;

  /* Math: '<S51>/Square2' incorporates:
   *  Math: '<S52>/Square2'
   *  Math: '<S53>/Square2'
   */
  rtb_VdotPg_err = rtb_Divide_k_idx_2 * rtb_Divide_k_idx_2;

  /* Math: '<S51>/Square1' incorporates:
   *  Math: '<S52>/Square1'
   *  Math: '<S53>/Square1'
   */
  rtb_Multiply_d_idx_1 = rtb_Divide_k_idx_1 * rtb_Divide_k_idx_1;

  /* Math: '<S51>/Square3' incorporates:
   *  Math: '<S52>/Square3'
   *  Math: '<S53>/Square3'
   */
  rtb_Sum_p = rtb_DiscreteTimeIntegrator1_l * rtb_DiscreteTimeIntegrator1_l;

  /* Sum: '<S51>/Subtract' incorporates:
   *  Math: '<S51>/Square'
   *  Math: '<S51>/Square1'
   *  Math: '<S51>/Square2'
   *  Math: '<S51>/Square3'
   *  Sum: '<S51>/Add'
   *  Sum: '<S51>/Add1'
   */
  rtb_MatrixConcatenate1[0] = (rtb_Add_a + rtb_Multiply_d_idx_1) -
    (rtb_VdotPg_err + rtb_Sum_p);

  /* Product: '<S51>/Multiply' incorporates:
   *  Product: '<S52>/Multiply'
   */
  rtb_Cos = rtb_Divide_k_idx_1 * rtb_Divide_k_idx_2;

  /* Product: '<S51>/Multiply1' incorporates:
   *  Product: '<S52>/Multiply1'
   */
  rtb_Saturation_l = rtb_Divide_k_idx_0 * rtb_DiscreteTimeIntegrator1_l;

  /* Gain: '<S51>/Gain' incorporates:
   *  Product: '<S51>/Multiply'
   *  Product: '<S51>/Multiply1'
   *  Sum: '<S51>/Subtract1'
   */
  rtb_MatrixConcatenate1[1] = (rtb_Cos - rtb_Saturation_l) * 2.0F;

  /* Product: '<S51>/Multiply2' incorporates:
   *  Product: '<S53>/Multiply'
   */
  rtb_MatrixConcatenate1_tmp = rtb_Divide_k_idx_1 *
    rtb_DiscreteTimeIntegrator1_l;

  /* Product: '<S51>/Multiply3' incorporates:
   *  Product: '<S53>/Multiply1'
   */
  rtb_MatrixConcatenate1_tmp_0 = rtb_Divide_k_idx_0 * rtb_Divide_k_idx_2;

  /* Gain: '<S51>/Gain1' incorporates:
   *  Product: '<S51>/Multiply2'
   *  Product: '<S51>/Multiply3'
   *  Sum: '<S51>/Add2'
   */
  rtb_MatrixConcatenate1[2] = (rtb_MatrixConcatenate1_tmp +
    rtb_MatrixConcatenate1_tmp_0) * 2.0F;

  /* Gain: '<S52>/Gain' incorporates:
   *  Sum: '<S52>/Add3'
   */
  rtb_MatrixConcatenate1[3] = (rtb_Cos + rtb_Saturation_l) * 2.0F;

  /* Sum: '<S52>/Subtract' incorporates:
   *  Sum: '<S52>/Add'
   *  Sum: '<S52>/Add1'
   */
  rtb_MatrixConcatenate1[4] = (rtb_Add_a + rtb_VdotPg_err) -
    (rtb_Multiply_d_idx_1 + rtb_Sum_p);

  /* Product: '<S52>/Multiply2' incorporates:
   *  Product: '<S53>/Multiply2'
   */
  rtb_Cos = rtb_Divide_k_idx_2 * rtb_DiscreteTimeIntegrator1_l;

  /* Product: '<S52>/Multiply3' incorporates:
   *  Product: '<S53>/Multiply3'
   */
  rtb_Saturation_l = rtb_Divide_k_idx_0 * rtb_Divide_k_idx_1;

  /* Gain: '<S52>/Gain1' incorporates:
   *  Product: '<S52>/Multiply2'
   *  Product: '<S52>/Multiply3'
   *  Sum: '<S52>/Subtract1'
   */
  rtb_MatrixConcatenate1[5] = (rtb_Cos - rtb_Saturation_l) * 2.0F;

  /* Gain: '<S53>/Gain' incorporates:
   *  Sum: '<S53>/Subtract2'
   */
  rtb_MatrixConcatenate1[6] = (rtb_MatrixConcatenate1_tmp -
    rtb_MatrixConcatenate1_tmp_0) * 2.0F;

  /* Gain: '<S53>/Gain1' incorporates:
   *  Sum: '<S53>/Add2'
   */
  rtb_MatrixConcatenate1[7] = (rtb_Cos + rtb_Saturation_l) * 2.0F;

  /* Sum: '<S53>/Subtract' incorporates:
   *  Sum: '<S53>/Add'
   *  Sum: '<S53>/Add1'
   */
  rtb_MatrixConcatenate1[8] = (rtb_Add_a + rtb_Sum_p) - (rtb_Multiply_d_idx_1 +
    rtb_VdotPg_err);

  /* Product: '<S47>/Multiply' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  SignalConversion: '<S47>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_Multiply_g[i] = rtb_MatrixConcatenate1[i + 6] * Controller_U.INS_Out.vd
      + (rtb_MatrixConcatenate1[i + 3] * Controller_U.INS_Out.ve +
         rtb_MatrixConcatenate1[i] * Controller_U.INS_Out.vn);
  }

  /* End of Product: '<S47>/Multiply' */

  /* Switch: '<S47>/Switch' incorporates:
   *  Constant: '<S48>/Constant'
   *  DiscreteIntegrator: '<S9>/Discrete-Time Integrator5'
   *  RelationalOperator: '<S48>/Compare'
   */
  if (rtb_Multiply_g[0] >= 3.0F) {
    rtb_Divide_k_idx_0 = Controller_DW.DiscreteTimeIntegrator5_DSTATE;
  } else {
    rtb_Divide_k_idx_0 = rtb_Multiply_g[0];
  }

  /* End of Switch: '<S47>/Switch' */

  /* Sum: '<S39>/Sum' incorporates:
   *  Gain: '<S39>/Gain'
   *  Inport: '<Root>/FMS_Out'
   *  Sum: '<S39>/Minus'
   */
  rtb_VdotPg_err = (Controller_U.FMS_Out.u_cmd - rtb_Divide_k_idx_0) *
    0.101936802F - rtb_VdotPg;

  /* Sum: '<S8>/Minus1' incorporates:
   *  Gain: '<S8>/ucmd2pitch'
   *  Gain: '<S8>/wcmd2pitch'
   */
  rtb_Divide_k_idx_0 = CONTROL_PARAM.FW_TECS_W2P * rtb_Minus -
    CONTROL_PARAM.FW_TECS_U2P * rtb_VdotPg_err;

  /* DiscreteIntegrator: '<S42>/ ' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) || (Controller_DW._PrevResetState != 0))
  {
    Controller_DW._DSTATE = Controller_ConstB.Zero1;
    if (Controller_DW._DSTATE >= CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
      Controller_DW._DSTATE = CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
    } else {
      if (Controller_DW._DSTATE <= -CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
        Controller_DW._DSTATE = -CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
      }
    }
  }

  if (Controller_DW._DSTATE >= CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
    Controller_DW._DSTATE = CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
  } else {
    if (Controller_DW._DSTATE <= -CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
      Controller_DW._DSTATE = -CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
    }
  }

  /* DiscreteIntegrator: '<S43>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
    Controller_DW.DiscreteTimeIntegrator1_DSTATE = rtb_Divide_k_idx_0;
  }

  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevRes != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTATE = rtb_Divide_k_idx_0;
  }

  /* Gain: '<S43>/Gain' incorporates:
   *  DiscreteIntegrator: '<S43>/Discrete-Time Integrator1'
   *  Sum: '<S43>/Sum5'
   */
  rtb_Divide_k_idx_1 = (rtb_Divide_k_idx_0 -
                        Controller_DW.DiscreteTimeIntegrator1_DSTATE) *
    62.831852F;

  /* Switch: '<S20>/Switch1' incorporates:
   *  Constant: '<S26>/Constant'
   *  DiscreteIntegrator: '<S42>/ '
   *  Gain: '<S37>/P_control'
   *  Gain: '<S8>/Gain'
   *  Gain: '<S8>/balabnce_ratio2'
   *  Gain: '<S8>/balance_ratio'
   *  Gain: '<S8>/pitch_ff'
   *  Inport: '<Root>/FMS_Out'
   *  RelationalOperator: '<S26>/Compare'
   *  Sum: '<S37>/Add'
   *  Sum: '<S8>/Add3'
   *  Sum: '<S8>/Minus'
   *  Sum: '<S8>/Sum'
   *  Switch: '<S43>/Switch'
   */
  if (Controller_U.FMS_Out.ctrl_mode == 3) {
    rtb_DiscreteTimeIntegrator1_l = Controller_U.FMS_Out.theta_cmd;
  } else {
    if (Controller_U.FMS_Out.reset > 0) {
      /* Switch: '<S43>/Switch' incorporates:
       *  Gain: '<S43>/Gain1'
       */
      rtb_Saturation_l = 0.0F;
    } else {
      /* Switch: '<S43>/Switch' */
      rtb_Saturation_l = rtb_Divide_k_idx_1;
    }

    /* Gain: '<S41>/Gain' */
    rtb_Divide_k_idx_2 = CONTROL_PARAM.FW_TECS_PITCH_D * rtb_Saturation_l;

    /* Saturate: '<S37>/Saturation1' */
    if (rtb_Divide_k_idx_2 > 0.3F) {
      rtb_Divide_k_idx_2 = 0.3F;
    } else {
      if (rtb_Divide_k_idx_2 < -0.3F) {
        rtb_Divide_k_idx_2 = -0.3F;
      }
    }

    /* End of Saturate: '<S37>/Saturation1' */
    rtb_DiscreteTimeIntegrator1_l = (((2.0F - CONTROL_PARAM.FW_TECS_RATIO) *
      rtb_Atan1 - CONTROL_PARAM.FW_TECS_RATIO * rtb_VdotPg) *
      CONTROL_PARAM.FW_TECS_PITCH_F + ((CONTROL_PARAM.FW_TECS_PITCH_P *
      rtb_Divide_k_idx_0 + Controller_DW._DSTATE) + rtb_Divide_k_idx_2)) +
      CONTROL_PARAM.FW_TECS_R2P * rtb_Abs;
  }

  /* End of Switch: '<S20>/Switch1' */

  /* Bias: '<S21>/Pitch Offset' */
  rtb_DiscreteTimeIntegrator1_l += CONTROL_PARAM.FW_PITCH_OFFSET;

  /* Saturate: '<S21>/Saturation' */
  if (rtb_DiscreteTimeIntegrator1_l > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
    rtb_DiscreteTimeIntegrator1_l = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
  } else {
    if (rtb_DiscreteTimeIntegrator1_l < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      rtb_DiscreteTimeIntegrator1_l = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    }
  }

  /* Product: '<S22>/Multiply' incorporates:
   *  Constant: '<S22>/Constant2'
   *  Inport: '<Root>/INS_Out'
   *  Sum: '<S21>/Sum'
   */
  rtb_Multiply_d_idx_1 = (rtb_DiscreteTimeIntegrator1_l -
    Controller_U.INS_Out.theta) * CONTROL_PARAM.PITCH_P;

  /* Product: '<S24>/Divide' incorporates:
   *  Constant: '<S24>/Constant'
   *  DiscreteIntegrator: '<S9>/Discrete-Time Integrator5'
   */
  rtb_DiscreteTimeIntegrator1_l = 9.81F /
    Controller_DW.DiscreteTimeIntegrator5_DSTATE;

  /* Saturate: '<S24>/Saturation' */
  if (rtb_DiscreteTimeIntegrator1_l > 1.0F) {
    rtb_DiscreteTimeIntegrator1_l = 1.0F;
  } else {
    if (rtb_DiscreteTimeIntegrator1_l < 0.0F) {
      rtb_DiscreteTimeIntegrator1_l = 0.0F;
    }
  }

  /* End of Saturate: '<S24>/Saturation' */

  /* Sum: '<S19>/Sum' incorporates:
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S24>/Multiply'
   *  Product: '<S24>/Multiply1'
   *  Trigonometry: '<S24>/Cos'
   *  Trigonometry: '<S24>/Tan'
   */
  rtb_Sum_p = tanf(Controller_U.FMS_Out.phi_cmd) * arm_cos_f32
    (Controller_U.FMS_Out.theta_cmd) * rtb_DiscreteTimeIntegrator1_l +
    Controller_U.FMS_Out.psi_rate_cmd;

  /* Saturate: '<S21>/Saturation' */
  if (rtb_Cos1 > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
    rtb_Cos1 = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
  } else {
    if (rtb_Cos1 < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      rtb_Cos1 = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    }
  }

  /* Sum: '<S12>/Add' incorporates:
   *  Constant: '<S22>/Constant1'
   *  Inport: '<Root>/INS_Out'
   *  Product: '<S12>/Multiply'
   *  Product: '<S22>/Multiply'
   *  Sum: '<S21>/Sum'
   *  Trigonometry: '<S12>/Sin1'
   */
  rtb_Add_a = (rtb_Cos1 - Controller_U.INS_Out.phi) * CONTROL_PARAM.ROLL_P -
    arm_sin_f32(Controller_U.INS_Out.theta) * rtb_Sum_p;

  /* Trigonometry: '<S12>/Sin' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_DiscreteTimeIntegrator1_l = arm_sin_f32(Controller_U.INS_Out.phi);

  /* Trigonometry: '<S12>/Cos1' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Cos1 = arm_cos_f32(Controller_U.INS_Out.theta);

  /* Trigonometry: '<S12>/Cos' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Cos = arm_cos_f32(Controller_U.INS_Out.phi);

  /* Sum: '<S12>/Add1' incorporates:
   *  Product: '<S12>/Multiply1'
   *  Product: '<S12>/Multiply3'
   */
  rtb_Divide_k_idx_2 = rtb_DiscreteTimeIntegrator1_l * rtb_Cos1 * rtb_Sum_p +
    rtb_Cos * rtb_Multiply_d_idx_1;

  /* Product: '<S12>/Multiply4' */
  rtb_DiscreteTimeIntegrator1_l *= rtb_Multiply_d_idx_1;

  /* Sum: '<S12>/Add2' incorporates:
   *  Product: '<S12>/Multiply5'
   */
  rtb_Cos1 = rtb_Cos * rtb_Cos1 * rtb_Sum_p - rtb_DiscreteTimeIntegrator1_l;

  /* Sum: '<S10>/Minus2' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Multiply_g[0] = rtb_Add_a - Controller_U.INS_Out.p;
  rtb_Multiply_g[1] = rtb_Divide_k_idx_2 - Controller_U.INS_Out.q;
  rtb_Multiply_g[2] = rtb_Cos1 - Controller_U.INS_Out.r;

  /* DiscreteIntegrator: '<S16>/Discrete-Time Integrator' incorporates:
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

  /* Sum: '<S8>/Add' incorporates:
   *  Gain: '<S8>/ucmd2thor'
   *  Gain: '<S8>/wcmd2thor'
   */
  rtb_Minus = CONTROL_PARAM.FW_TECS_W2T * rtb_Minus + CONTROL_PARAM.FW_TECS_U2T *
    rtb_VdotPg_err;

  /* DiscreteIntegrator: '<S45>/ ' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) || (Controller_DW._PrevResetState_k != 0))
  {
    Controller_DW._DSTATE_m = Controller_ConstB.Zero;
    if (Controller_DW._DSTATE_m >= CONTROL_PARAM.FW_CRUISE_THRO) {
      Controller_DW._DSTATE_m = CONTROL_PARAM.FW_CRUISE_THRO;
    } else {
      if (Controller_DW._DSTATE_m <= -CONTROL_PARAM.FW_CRUISE_THRO) {
        Controller_DW._DSTATE_m = -CONTROL_PARAM.FW_CRUISE_THRO;
      }
    }
  }

  if (Controller_DW._DSTATE_m >= CONTROL_PARAM.FW_CRUISE_THRO) {
    Controller_DW._DSTATE_m = CONTROL_PARAM.FW_CRUISE_THRO;
  } else {
    if (Controller_DW._DSTATE_m <= -CONTROL_PARAM.FW_CRUISE_THRO) {
      Controller_DW._DSTATE_m = -CONTROL_PARAM.FW_CRUISE_THRO;
    }
  }

  /* DiscreteIntegrator: '<S46>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_o != 0) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_b = rtb_Minus;
  }

  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevR_m != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_b = rtb_Minus;
  }

  /* Gain: '<S46>/Gain' incorporates:
   *  DiscreteIntegrator: '<S46>/Discrete-Time Integrator1'
   *  Sum: '<S46>/Sum5'
   */
  rtb_VdotPg_err = (rtb_Minus - Controller_DW.DiscreteTimeIntegrator1_DSTAT_b) *
    188.49556F;

  /* Outputs for Atomic SubSystem: '<S6>/Fixwing' */
  /* MultiPortSwitch: '<S31>/Multiport Switch' incorporates:
   *  Constant: '<S31>/Disarm'
   *  Constant: '<S31>/Standby'
   *  Inport: '<Root>/FMS_Out'
   */
  switch (Controller_U.FMS_Out.status) {
   case 1:
    for (i = 0; i < 6; i++) {
      rtb_MultiportSwitch[i] = Controller_ConstP.Disarm_Value[i];
    }
    break;

   case 2:
    for (i = 0; i < 6; i++) {
      rtb_MultiportSwitch[i] = Controller_ConstP.Standby_Value[i];
    }
    break;

   case 3:
    /* Switch: '<S30>/Switch' incorporates:
     *  Constant: '<S28>/Constant1'
     *  Constant: '<S28>/Constant12'
     *  Constant: '<S28>/Constant2'
     *  Constant: '<S28>/Constant7'
     *  Constant: '<S34>/Constant'
     *  RelationalOperator: '<S34>/Compare'
     */
    if (Controller_U.FMS_Out.ctrl_mode == 1) {
      for (i = 0; i < 6; i++) {
        rtb_MultiportSwitch[i] = Controller_U.FMS_Out.actuator_cmd[i];
      }
    } else {
      /* Product: '<S14>/Divide' incorporates:
       *  Constant: '<S14>/trim_speed'
       *  DiscreteIntegrator: '<S9>/Discrete-Time Integrator5'
       *  Math: '<S14>/Square'
       *  Math: '<S14>/Square1'
       */
      rtb_Cos = CONTROL_PARAM.FW_AIRSPEED_TRIM * CONTROL_PARAM.FW_AIRSPEED_TRIM /
        (Controller_DW.DiscreteTimeIntegrator5_DSTATE *
         Controller_DW.DiscreteTimeIntegrator5_DSTATE);

      /* Saturate: '<S14>/Saturation' */
      if (rtb_Cos > 1.0F) {
        rtb_Cos = 1.0F;
      } else {
        if (rtb_Cos < 0.0F) {
          rtb_Cos = 0.0F;
        }
      }

      /* End of Saturate: '<S14>/Saturation' */

      /* Product: '<S10>/Multiply' incorporates:
       *  Constant: '<S17>/gain1'
       *  Constant: '<S17>/gain2'
       *  Constant: '<S17>/gain3'
       *  DiscreteIntegrator: '<S16>/Discrete-Time Integrator'
       *  Product: '<S17>/Multiply'
       *  Sum: '<S13>/Add1'
       */
      rtb_DiscreteTimeIntegrator1_l = (CONTROL_PARAM.ROLL_RATE_P *
        rtb_Multiply_g[0] + Controller_DW.DiscreteTimeIntegrator_DSTATE[0]) *
        rtb_Cos;
      rtb_Multiply_d_idx_1 = (CONTROL_PARAM.PITCH_RATE_P * rtb_Multiply_g[1] +
        Controller_DW.DiscreteTimeIntegrator_DSTATE[1]) * rtb_Cos;
      rtb_Sum_p = (CONTROL_PARAM.YAW_RATE_P * rtb_Multiply_g[2] +
                   Controller_DW.DiscreteTimeIntegrator_DSTATE[2]) * rtb_Cos;

      /* Product: '<S15>/Divide' incorporates:
       *  Constant: '<S15>/trim_speed'
       *  DiscreteIntegrator: '<S9>/Discrete-Time Integrator5'
       */
      rtb_Cos = CONTROL_PARAM.FW_AIRSPEED_TRIM /
        Controller_DW.DiscreteTimeIntegrator5_DSTATE;

      /* Saturate: '<S15>/Saturation' */
      if (rtb_Cos > 1.0F) {
        rtb_Cos = 1.0F;
      } else {
        if (rtb_Cos < 0.0F) {
          rtb_Cos = 0.0F;
        }
      }

      /* End of Saturate: '<S15>/Saturation' */
      rtb_MatrixConcatenate[11] = CONTROL_PARAM.FW_YAW_EFFC;

      /* SignalConversion: '<S28>/ConcatBufferAtVector Concatenate2In3' incorporates:
       *  Constant: '<S28>/Constant11'
       *  Constant: '<S28>/Constant12'
       */
      rtb_MatrixConcatenate[10] = 0.0F;

      /* SignalConversion: '<S28>/ConcatBufferAtVector Concatenate2In2' incorporates:
       *  Constant: '<S28>/Constant10'
       */
      rtb_MatrixConcatenate[9] = 0.0F;

      /* SignalConversion: '<S28>/ConcatBufferAtVector Concatenate2In1' incorporates:
       *  Constant: '<S28>/Constant9'
       */
      rtb_MatrixConcatenate[8] = 0.0F;

      /* SignalConversion: '<S28>/ConcatBufferAtVector Concatenate1In4' incorporates:
       *  Constant: '<S28>/Constant8'
       */
      rtb_MatrixConcatenate[7] = 0.0F;
      rtb_MatrixConcatenate[6] = CONTROL_PARAM.FW_PITCH_EFFC;

      /* SignalConversion: '<S28>/ConcatBufferAtVector Concatenate1In2' incorporates:
       *  Constant: '<S28>/Constant6'
       *  Constant: '<S28>/Constant7'
       */
      rtb_MatrixConcatenate[5] = 0.0F;

      /* SignalConversion: '<S28>/ConcatBufferAtVector Concatenate1In1' incorporates:
       *  Constant: '<S28>/Constant5'
       */
      rtb_MatrixConcatenate[4] = 0.0F;

      /* SignalConversion: '<S28>/ConcatBufferAtVector ConcatenateIn4' incorporates:
       *  Constant: '<S28>/Constant4'
       */
      rtb_MatrixConcatenate[3] = 0.0F;

      /* SignalConversion: '<S28>/ConcatBufferAtVector ConcatenateIn3' incorporates:
       *  Constant: '<S28>/Constant3'
       */
      rtb_MatrixConcatenate[2] = 0.0F;
      rtb_MatrixConcatenate[1] = CONTROL_PARAM.FW_ROLL_EFFC;
      rtb_MatrixConcatenate[0] = CONTROL_PARAM.FW_ROLL_EFFC;

      /* Switch: '<S29>/Switch' incorporates:
       *  Constant: '<S28>/Constant1'
       *  Constant: '<S28>/Constant2'
       *  Constant: '<S32>/Constant1'
       *  DataTypeConversion: '<S32>/Data Type Conversion'
       *  Gain: '<S32>/Gain1'
       *  Logic: '<S29>/Logical Operator'
       *  RelationalOperator: '<S33>/Compare'
       *  Sum: '<S32>/Sum1'
       *  Switch: '<S46>/Switch'
       */
      if ((Controller_U.FMS_Out.ctrl_mode == 1) ||
          (Controller_U.FMS_Out.ctrl_mode == 2) ||
          (Controller_U.FMS_Out.ctrl_mode == 3)) {
        rtb_throttle_cmd = Controller_U.FMS_Out.throttle_cmd;
      } else {
        if (Controller_U.FMS_Out.reset > 0) {
          /* Switch: '<S46>/Switch' incorporates:
           *  Gain: '<S46>/Gain1'
           */
          rtb_Saturation_l = 0.0F;
        } else {
          /* Switch: '<S46>/Switch' */
          rtb_Saturation_l = rtb_VdotPg_err;
        }

        /* Gain: '<S44>/Gain' */
        rtb_Saturation_l *= CONTROL_PARAM.FW_TECS_THOR_D;

        /* Saturate: '<S38>/Saturation1' */
        if (rtb_Saturation_l > 0.3F) {
          rtb_Saturation_l = 0.3F;
        } else {
          if (rtb_Saturation_l < -0.3F) {
            rtb_Saturation_l = -0.3F;
          }
        }

        /* End of Saturate: '<S38>/Saturation1' */

        /* Sum: '<S8>/Sum1' incorporates:
         *  DiscreteIntegrator: '<S45>/ '
         *  Gain: '<S38>/P_control'
         *  Gain: '<S8>/Gain1'
         *  Gain: '<S8>/thorttle_ff'
         *  Sum: '<S38>/Add4'
         *  Sum: '<S8>/Add1'
         *  Sum: '<S8>/Add2'
         */
        rtb_Abs = (((CONTROL_PARAM.FW_TECS_THOR_P * rtb_Minus +
                     Controller_DW._DSTATE_m) + rtb_Saturation_l) + (rtb_Atan1 +
                    rtb_VdotPg) * CONTROL_PARAM.FW_TECS_THOR_FF) +
          CONTROL_PARAM.FW_TECS_R2T * rtb_Abs;

        /* Saturate: '<S27>/Saturation5' */
        if (rtb_Abs > 1.0F) {
          rtb_Abs = 1.0F;
        } else {
          if (rtb_Abs < -1.0F) {
            rtb_Abs = -1.0F;
          }
        }

        /* End of Saturate: '<S27>/Saturation5' */

        /* Saturate: '<S32>/Saturation' incorporates:
         *  Constant: '<S32>/cruise_throttle'
         *  Sum: '<S32>/Sum'
         */
        if (rtb_Abs + 0.5F > 1.0F) {
          rtb_Abs = 1.0F;
        } else if (rtb_Abs + 0.5F < 0.0F) {
          rtb_Abs = 0.0F;
        } else {
          rtb_Abs += 0.5F;
        }

        /* End of Saturate: '<S32>/Saturation' */
        rtb_throttle_cmd = (uint16_T)((uint32_T)fmodf(floorf(1000.0F * rtb_Abs),
          4.2949673E+9F) + 1000U);
      }

      /* End of Switch: '<S29>/Switch' */

      /* Product: '<S10>/Multiply1' incorporates:
       *  Gain: '<S10>/FF'
       */
      rtb_Abs = CONTROL_PARAM.FW_FF * rtb_Add_a * rtb_Cos;
      rtb_Atan1 = CONTROL_PARAM.FW_FF * rtb_Divide_k_idx_2 * rtb_Cos;
      rtb_VdotPg = CONTROL_PARAM.FW_FF * rtb_Cos1 * rtb_Cos;

      /* Saturate: '<S10>/FF_limit' */
      if (rtb_Abs > CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_Abs = CONTROL_PARAM.FW_FF_LIMIT;
      } else {
        if (rtb_Abs < -CONTROL_PARAM.FW_FF_LIMIT) {
          rtb_Abs = -CONTROL_PARAM.FW_FF_LIMIT;
        }
      }

      /* Saturate: '<S10>/PI_limit' */
      if (rtb_DiscreteTimeIntegrator1_l > CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_DiscreteTimeIntegrator1_l = CONTROL_PARAM.FW_PI_LIMIT;
      } else {
        if (rtb_DiscreteTimeIntegrator1_l < -CONTROL_PARAM.FW_PI_LIMIT) {
          rtb_DiscreteTimeIntegrator1_l = -CONTROL_PARAM.FW_PI_LIMIT;
        }
      }

      /* Saturate: '<S27>/Saturation4' incorporates:
       *  Sum: '<S10>/Add'
       */
      rtb_DiscreteTimeIntegrator1_l += rtb_Abs;
      if (rtb_DiscreteTimeIntegrator1_l > 1.0F) {
        rtb_DiscreteTimeIntegrator1_l = 1.0F;
      } else {
        if (rtb_DiscreteTimeIntegrator1_l < -1.0F) {
          rtb_DiscreteTimeIntegrator1_l = -1.0F;
        }
      }

      /* Saturate: '<S10>/FF_limit' */
      if (rtb_Atan1 > CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_Atan1 = CONTROL_PARAM.FW_FF_LIMIT;
      } else {
        if (rtb_Atan1 < -CONTROL_PARAM.FW_FF_LIMIT) {
          rtb_Atan1 = -CONTROL_PARAM.FW_FF_LIMIT;
        }
      }

      /* Saturate: '<S10>/PI_limit' */
      if (rtb_Multiply_d_idx_1 > CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_Multiply_d_idx_1 = CONTROL_PARAM.FW_PI_LIMIT;
      } else {
        if (rtb_Multiply_d_idx_1 < -CONTROL_PARAM.FW_PI_LIMIT) {
          rtb_Multiply_d_idx_1 = -CONTROL_PARAM.FW_PI_LIMIT;
        }
      }

      /* Saturate: '<S27>/Saturation4' incorporates:
       *  Sum: '<S10>/Add'
       */
      rtb_Multiply_d_idx_1 += rtb_Atan1;
      if (rtb_Multiply_d_idx_1 > 1.0F) {
        rtb_Multiply_d_idx_1 = 1.0F;
      } else {
        if (rtb_Multiply_d_idx_1 < -1.0F) {
          rtb_Multiply_d_idx_1 = -1.0F;
        }
      }

      /* Saturate: '<S10>/FF_limit' */
      if (rtb_VdotPg > CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_VdotPg = CONTROL_PARAM.FW_FF_LIMIT;
      } else {
        if (rtb_VdotPg < -CONTROL_PARAM.FW_FF_LIMIT) {
          rtb_VdotPg = -CONTROL_PARAM.FW_FF_LIMIT;
        }
      }

      /* Saturate: '<S10>/PI_limit' */
      if (rtb_Sum_p > CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_Sum_p = CONTROL_PARAM.FW_PI_LIMIT;
      } else {
        if (rtb_Sum_p < -CONTROL_PARAM.FW_PI_LIMIT) {
          rtb_Sum_p = -CONTROL_PARAM.FW_PI_LIMIT;
        }
      }

      /* Saturate: '<S27>/Saturation4' incorporates:
       *  Sum: '<S10>/Add'
       */
      rtb_Sum_p += rtb_VdotPg;
      if (rtb_Sum_p > 1.0F) {
        rtb_Sum_p = 1.0F;
      } else {
        if (rtb_Sum_p < -1.0F) {
          rtb_Sum_p = -1.0F;
        }
      }

      rtb_MultiportSwitch[0] = rtb_throttle_cmd;
      rtb_MultiportSwitch[1] = rtb_throttle_cmd;

      /* Product: '<S27>/Multiply1' incorporates:
       *  Saturate: '<S27>/Saturation3'
       */
      for (i = 0; i < 4; i++) {
        /* Saturate: '<S27>/Saturation3' incorporates:
         *  Bias: '<S27>/Bias'
         *  Gain: '<S27>/Gain1'
         */
        rtb_Abs = 500.0F * (rtb_MatrixConcatenate[i + 8] * rtb_Sum_p +
                            (rtb_MatrixConcatenate[i + 4] * rtb_Multiply_d_idx_1
                             + rtb_MatrixConcatenate[i] *
                             rtb_DiscreteTimeIntegrator1_l)) + 1500.0F;
        if (rtb_Abs > 2000.0F) {
          rtb_Abs = 2000.0F;
        } else {
          if (rtb_Abs < 1000.0F) {
            rtb_Abs = 1000.0F;
          }
        }

        rtb_MultiportSwitch[i + 2] = (uint16_T)fmodf(floorf(rtb_Abs), 65536.0F);
      }

      /* End of Product: '<S27>/Multiply1' */
    }

    /* End of Switch: '<S30>/Switch' */
    break;

   default:
    for (i = 0; i < 6; i++) {
      rtb_MultiportSwitch[i] = Controller_ConstP.Disarm_Value[i];
    }
    break;
  }

  /* End of MultiPortSwitch: '<S31>/Multiport Switch' */
  /* End of Outputs for SubSystem: '<S6>/Fixwing' */

  /* Outport: '<Root>/Control_Out' incorporates:
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   *  Reshape: '<S31>/Reshape'
   */
  Controller_Y.Control_Out.timestamp =
    Controller_DW.DiscreteTimeIntegrator_DSTATE_n;
  for (i = 0; i < 6; i++) {
    /* Outputs for Atomic SubSystem: '<S6>/Fixwing' */
    Controller_Y.Control_Out.actuator_cmd[i] = rtb_MultiportSwitch[i];

    /* End of Outputs for SubSystem: '<S6>/Fixwing' */
  }

  for (i = 0; i < 10; i++) {
    Controller_Y.Control_Out.actuator_cmd[i + 6] = 0U;
  }

  /* End of Outport: '<Root>/Control_Out' */

  /* Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S9>/Gain'
   *  Sum: '<S9>/Sum5'
   */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;
  Controller_DW.DiscreteTimeIntegrator5_DSTATE += (rtb_Saturation -
    Controller_DW.DiscreteTimeIntegrator5_DSTATE) * 125.663704F * 0.002F;

  /* Update for DiscreteIntegrator: '<S42>/ ' incorporates:
   *  Gain: '<S42>/Gain3'
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW._DSTATE += CONTROL_PARAM.FW_TECS_PITCH_I * rtb_Divide_k_idx_0 *
    0.002F;
  if (Controller_DW._DSTATE >= CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
    Controller_DW._DSTATE = CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
  } else {
    if (Controller_DW._DSTATE <= -CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
      Controller_DW._DSTATE = -CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
    }
  }

  Controller_DW._PrevResetState = (int8_T)(Controller_U.FMS_Out.reset > 0);

  /* End of Update for DiscreteIntegrator: '<S42>/ ' */

  /* Update for DiscreteIntegrator: '<S43>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;
  Controller_DW.DiscreteTimeIntegrator1_DSTATE += 0.002F * rtb_Divide_k_idx_1;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S16>/gain1'
   *  Constant: '<S16>/gain2'
   *  Constant: '<S16>/gain3'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S16>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE[0] += CONTROL_PARAM.ROLL_RATE_I *
    rtb_Multiply_g[0] * 0.002F;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] >= CONTROL_PARAM.RATE_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = CONTROL_PARAM.RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_DSTATE[1] += CONTROL_PARAM.PITCH_RATE_I *
    rtb_Multiply_g[1] * 0.002F;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] >= CONTROL_PARAM.RATE_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = CONTROL_PARAM.RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_DSTATE[2] += CONTROL_PARAM.YAW_RATE_I *
    rtb_Multiply_g[2] * 0.002F;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[2] >= CONTROL_PARAM.RATE_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[2] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[2] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[2] = CONTROL_PARAM.RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* End of Update for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S45>/ ' incorporates:
   *  Gain: '<S45>/Gain'
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW._DSTATE_m += CONTROL_PARAM.FW_TECS_THOR_I * rtb_Minus * 0.002F;
  if (Controller_DW._DSTATE_m >= CONTROL_PARAM.FW_CRUISE_THRO) {
    Controller_DW._DSTATE_m = CONTROL_PARAM.FW_CRUISE_THRO;
  } else {
    if (Controller_DW._DSTATE_m <= -CONTROL_PARAM.FW_CRUISE_THRO) {
      Controller_DW._DSTATE_m = -CONTROL_PARAM.FW_CRUISE_THRO;
    }
  }

  Controller_DW._PrevResetState_k = (int8_T)(Controller_U.FMS_Out.reset > 0);

  /* End of Update for DiscreteIntegrator: '<S45>/ ' */

  /* Update for DiscreteIntegrator: '<S46>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_o = 0U;
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_b += 0.002F * rtb_VdotPg_err;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_m = (int8_T)
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

  /* InitializeConditions for DiscreteIntegrator: '<S9>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S42>/ ' */
  Controller_DW._DSTATE = Controller_ConstB.Zero1;
  if (Controller_DW._DSTATE >= CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
    Controller_DW._DSTATE = CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
  } else {
    if (Controller_DW._DSTATE <= -CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
      Controller_DW._DSTATE = -CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
    }
  }

  Controller_DW._PrevResetState = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S42>/ ' */

  /* InitializeConditions for DiscreteIntegrator: '<S43>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S45>/ ' */
  Controller_DW._DSTATE_m = Controller_ConstB.Zero;
  if (Controller_DW._DSTATE_m >= CONTROL_PARAM.FW_CRUISE_THRO) {
    Controller_DW._DSTATE_m = CONTROL_PARAM.FW_CRUISE_THRO;
  } else {
    if (Controller_DW._DSTATE_m <= -CONTROL_PARAM.FW_CRUISE_THRO) {
      Controller_DW._DSTATE_m = -CONTROL_PARAM.FW_CRUISE_THRO;
    }
  }

  Controller_DW._PrevResetState_k = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S45>/ ' */

  /* InitializeConditions for DiscreteIntegrator: '<S46>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_o = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_m = 0;
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
