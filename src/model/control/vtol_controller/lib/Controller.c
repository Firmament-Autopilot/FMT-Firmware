/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.758
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Sep 17 08:38:28 2025
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
struct_bbisFpyguPkQQvdqSWKvqB CONTROL_PARAM = {
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
  5.0F,
  5.0F,
  0.52359879F,
  0.15F,
  0.2F,
  0.6F,
  0.15F,
  0.15F,
  0.2F,
  0.006F,
  0.009F,
  0.02F,
  0.0F,
  0.0F,
  -0.3F,
  0.3F,
  -0.3F,
  0.3F,
  1.04719758F,
  0.785398185F,
  0.5F,
  2000U,
  1000U,
  5.0F,
  5.0F,
  0.785398185F,
  0.1F,
  0.15F,
  0.15F,
  0.1F,
  0.1F,
  0.2F,
  -0.4F,
  0.4F,
  1.04719758F,
  0.52359879F,
  0.52359879F,
  17.0F,
  0.2F,
  1.0F,
  1.0F,
  1.0F,
  0.0F,
  0.5F,
  0.2F,
  0.25F,
  0.2F,
  1.0F,
  0.15F,
  0.3F,
  0.2F,
  0.0F,
  0.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.5F,
  0.2F,
  0.0F,
  0.0F,
  2000U,
  1000U,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F
} ;                                    /* Variable: CONTROL_PARAM
                                        * Referenced by:
                                        *   '<S48>/Saturation'
                                        *   '<S49>/balabnce_ratio2'
                                        *   '<S49>/balance_ratio'
                                        *   '<S49>/pitch_ff'
                                        *   '<S49>/thorttle_ff'
                                        *   '<S49>/ucmd2pitch'
                                        *   '<S49>/ucmd2thor'
                                        *   '<S49>/wcmd2pitch'
                                        *   '<S49>/wcmd2thor'
                                        *   '<S140>/hover_throttle'
                                        *   '<S51>/FF'
                                        *   '<S70>/P_control'
                                        *   '<S71>/P_control'
                                        *   '<S72>/Kv'
                                        *   '<S121>/Saturation'
                                        *   '<S168>/Bias1'
                                        *   '<S168>/Bias2'
                                        *   '<S168>/Bias3'
                                        *   '<S168>/Bias4'
                                        *   '<S168>/Saturation1'
                                        *   '<S169>/Constant'
                                        *   '<S169>/Constant1'
                                        *   '<S169>/Saturation'
                                        *   '<S184>/Bias1'
                                        *   '<S184>/Bias2'
                                        *   '<S184>/Bias3'
                                        *   '<S184>/Bias4'
                                        *   '<S184>/Saturation1'
                                        *   '<S185>/Constant'
                                        *   '<S185>/Constant1'
                                        *   '<S185>/Saturation'
                                        *   '<S55>/trim_speed'
                                        *   '<S56>/trim_speed'
                                        *   '<S60>/Saturation'
                                        *   '<S78>/Gain'
                                        *   '<S79>/ '
                                        *   '<S79>/Gain3'
                                        *   '<S81>/Gain'
                                        *   '<S82>/Gain'
                                        *   '<S93>/Saturation'
                                        *   '<S93>/Saturation1'
                                        *   '<S93>/Saturation2'
                                        *   '<S131>/kd'
                                        *   '<S131>/Saturation'
                                        *   '<S132>/ki'
                                        *   '<S132>/Discrete-Time Integrator'
                                        *   '<S133>/kp'
                                        *   '<S147>/kd'
                                        *   '<S147>/Saturation'
                                        *   '<S148>/Constant'
                                        *   '<S148>/ki'
                                        *   '<S148>/Discrete-Time Integrator'
                                        *   '<S149>/kp'
                                        *   '<S173>/Constant1'
                                        *   '<S173>/Constant12'
                                        *   '<S173>/Constant2'
                                        *   '<S173>/Constant7'
                                        *   '<S182>/Bias'
                                        *   '<S182>/Bias1'
                                        *   '<S182>/Bias2'
                                        *   '<S182>/Bias3'
                                        *   '<S183>/Bias'
                                        *   '<S183>/Bias1'
                                        *   '<S183>/Bias2'
                                        *   '<S183>/Bias3'
                                        *   '<S188>/Constant1'
                                        *   '<S188>/Constant11'
                                        *   '<S188>/Constant12'
                                        *   '<S188>/Constant2'
                                        *   '<S188>/Constant7'
                                        *   '<S188>/Constant8'
                                        *   '<S194>/Bias'
                                        *   '<S194>/Bias1'
                                        *   '<S194>/Bias2'
                                        *   '<S194>/Bias3'
                                        *   '<S195>/Bias'
                                        *   '<S195>/Bias1'
                                        *   '<S195>/Bias2'
                                        *   '<S195>/Bias3'
                                        *   '<S57>/gain1'
                                        *   '<S57>/gain2'
                                        *   '<S57>/gain3'
                                        *   '<S57>/Discrete-Time Integrator'
                                        *   '<S58>/gain1'
                                        *   '<S58>/gain2'
                                        *   '<S58>/gain3'
                                        *   '<S62>/Pitch Offset'
                                        *   '<S62>/Saturation'
                                        *   '<S63>/Constant1'
                                        *   '<S63>/Constant2'
                                        *   '<S102>/Gain'
                                        *   '<S102>/Gain1'
                                        *   '<S114>/Constant1'
                                        *   '<S114>/Constant2'
                                        *   '<S107>/gain1'
                                        *   '<S107>/gain2'
                                        *   '<S107>/gain3'
                                        *   '<S107>/Saturation'
                                        *   '<S108>/gain1'
                                        *   '<S108>/gain2'
                                        *   '<S108>/gain3'
                                        *   '<S108>/Discrete-Time Integrator'
                                        *   '<S109>/gain1'
                                        *   '<S109>/gain2'
                                        *   '<S109>/gain3'
                                        */

struct_biZzOMrg0u3lxrb7POOubF CONTROL_EXPORT = {
  2U,

  { 86, 84, 79, 76, 32, 67, 111, 110, 116, 114, 111, 108, 108, 101, 114, 32, 118,
    48, 46, 48, 46, 49, 0 }
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
 *    '<S169>/R_Remix'
 *    '<S185>/R_Remix'
 */
#if (AIRFRAME == 1) || (AIRFRAME == 2)

void Controller_R_Remix(const real32_T rtu_motor_out[4], real32_T rtu_up_lim,
  real32_T rtu_lo_lim, real32_T rty_floating_yaw[4])
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
      if ((max_index == 3) || (max_index == 4)) {
        b_min = -b_min;
      }
    } else {
      if ((min_index == 3) || (min_index == 4)) {
        b_min = -b_min;
      }
    }

    rty_floating_yaw[0] = b_min;
    rty_floating_yaw[1] = b_min;
    rty_floating_yaw[2] = -b_min;
    rty_floating_yaw[3] = -b_min;
  } else {
    rty_floating_yaw[0] = 0.0F;
    rty_floating_yaw[1] = 0.0F;
    rty_floating_yaw[2] = 0.0F;
    rty_floating_yaw[3] = 0.0F;
  }
}

#endif

/* Model step function */
void Controller_step(void)
{
  /* local block i/o variables */
  real32_T rtb_Multiply2[3];
  real32_T rtb_Multiply3[3];
  real32_T rtb_Multiply[3];
  real32_T rtb_Multiply1[3];
  uint16_T rtb_VariantMergeForOutportactua[9];
  boolean_T rtb_Compare;
  real32_T rtb_Sum5_lp;
  boolean_T rtb_Compare_m;
  boolean_T rtb_Compare_b;
  real32_T rtb_DiscreteTimeIntegrator1_a;
  real32_T rtb_Add3_e;
  boolean_T rtb_LogicalOperator_h;
  real32_T rtb_Ldot_err;
  real32_T rtb_Gain_c4;
  real32_T rtb_Integrator1_m;
  real32_T rtb_Cos1;
  real32_T rtb_Gain_ow;
  real32_T rtb_Add4_l;
  real32_T rtb_Square_j;
  real32_T rtb_MatrixConcatenate1[9];
  real32_T rtb_Multiply_ni[3];
  real32_T rtb_thor;
  real32_T rtb_Add1_j4;
  real32_T rtb_Add2_h;
  int32_T i;
  real32_T rtb_MatrixConcatenate1_0[3];
  int32_T rtb_MultiportSwitch_idx_0;
  int32_T rtb_MultiportSwitch_idx_1;
  real32_T rtb_Add_o_idx_1;
  real32_T rtb_Add_o_idx_2;
  real32_T rtb_Divide_m_idx_0;
  real32_T rtb_Divide_m_idx_3;
  real32_T rtb_Divide_m_idx_1;
  real32_T rtb_Divide_m_idx_2;
  uint32_T tmp;

  /* RelationalOperator: '<S154>/Compare' incorporates:
   *  Constant: '<S154>/Constant'
   *  Inport: '<Root>/FMS_Out'
   */
  rtb_Compare = (Controller_U.FMS_Out.ext_state != 2);

  /* Relay: '<S8>/Relay' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  if (Controller_U.INS_Out.airspeed >= 10.0F) {
    Controller_DW.Relay_Mode = true;
  } else {
    if (Controller_U.INS_Out.airspeed <= 8.0F) {
      Controller_DW.Relay_Mode = false;
    }
  }

  /* Outputs for Enabled SubSystem: '<S2>/FW_Controller' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  /* S-Function (sfix_bitop): '<S8>/vel_valid' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  S-Function (sfix_bitop): '<S73>/Bitwise AND'
   *  S-Function (sfix_bitop): '<S74>/Bitwise AND'
   *  S-Function (sfix_bitop): '<S75>/Bitwise AND'
   */
  tmp = Controller_U.INS_Out.flag & 16U;

  /* End of Outputs for SubSystem: '<S2>/FW_Controller' */

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S155>/Constant'
   *  Inport: '<Root>/INS_Out'
   *  Logic: '<S8>/Logical Operator'
   *  Logic: '<S8>/Logical Operator1'
   *  RelationalOperator: '<S155>/Compare'
   *  Relay: '<S8>/Relay'
   *  S-Function (sfix_bitop): '<S8>/airspeed_valid'
   *  S-Function (sfix_bitop): '<S8>/vel_valid'
   */
  if ((Controller_DW.Relay_Mode && ((Controller_U.INS_Out.flag & 512U) != 0U)) ||
      (tmp == 0U)) {
    rtb_Sum5_lp = Controller_U.INS_Out.airspeed;
  } else {
    /* Sqrt: '<S163>/Sqrt' incorporates:
     *  Math: '<S163>/Square'
     *  Sum: '<S163>/Sum of Elements'
     */
    rtb_Square_j = sqrtf(((Controller_U.INS_Out.quat[0] *
      Controller_U.INS_Out.quat[0] + Controller_U.INS_Out.quat[1] *
      Controller_U.INS_Out.quat[1]) + Controller_U.INS_Out.quat[2] *
                          Controller_U.INS_Out.quat[2]) +
                         Controller_U.INS_Out.quat[3] *
                         Controller_U.INS_Out.quat[3]);

    /* Product: '<S159>/Divide' */
    rtb_Divide_m_idx_0 = Controller_U.INS_Out.quat[0] / rtb_Square_j;
    rtb_Divide_m_idx_1 = Controller_U.INS_Out.quat[1] / rtb_Square_j;
    rtb_Divide_m_idx_2 = Controller_U.INS_Out.quat[2] / rtb_Square_j;
    rtb_Divide_m_idx_3 = Controller_U.INS_Out.quat[3] / rtb_Square_j;

    /* Math: '<S162>/Square' incorporates:
     *  Math: '<S160>/Square'
     *  Math: '<S161>/Square'
     */
    rtb_Square_j = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_0;

    /* Math: '<S162>/Square2' incorporates:
     *  Math: '<S160>/Square2'
     *  Math: '<S161>/Square2'
     */
    rtb_Cos1 = rtb_Divide_m_idx_2 * rtb_Divide_m_idx_2;

    /* Math: '<S162>/Square1' incorporates:
     *  Math: '<S160>/Square1'
     *  Math: '<S161>/Square1'
     */
    rtb_Ldot_err = rtb_Divide_m_idx_1 * rtb_Divide_m_idx_1;

    /* Math: '<S162>/Square3' incorporates:
     *  Math: '<S160>/Square3'
     *  Math: '<S161>/Square3'
     */
    rtb_Gain_c4 = rtb_Divide_m_idx_3 * rtb_Divide_m_idx_3;

    /* Sum: '<S162>/Subtract' incorporates:
     *  Math: '<S162>/Square'
     *  Math: '<S162>/Square1'
     *  Math: '<S162>/Square2'
     *  Math: '<S162>/Square3'
     *  Sum: '<S162>/Add'
     *  Sum: '<S162>/Add1'
     */
    rtb_MatrixConcatenate1[8] = (rtb_Square_j + rtb_Gain_c4) - (rtb_Ldot_err +
      rtb_Cos1);

    /* Product: '<S162>/Multiply2' incorporates:
     *  Product: '<S161>/Multiply2'
     */
    rtb_Add1_j4 = rtb_Divide_m_idx_2 * rtb_Divide_m_idx_3;

    /* Product: '<S162>/Multiply3' incorporates:
     *  Product: '<S161>/Multiply3'
     */
    rtb_DiscreteTimeIntegrator1_a = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_1;

    /* Gain: '<S162>/Gain1' incorporates:
     *  Product: '<S162>/Multiply2'
     *  Product: '<S162>/Multiply3'
     *  Sum: '<S162>/Add2'
     */
    rtb_MatrixConcatenate1[7] = (rtb_Add1_j4 + rtb_DiscreteTimeIntegrator1_a) *
      2.0F;

    /* Product: '<S162>/Multiply' incorporates:
     *  Product: '<S160>/Multiply2'
     */
    rtb_Integrator1_m = rtb_Divide_m_idx_1 * rtb_Divide_m_idx_3;

    /* Product: '<S162>/Multiply1' incorporates:
     *  Product: '<S160>/Multiply3'
     */
    rtb_Add2_h = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_2;

    /* Gain: '<S162>/Gain' incorporates:
     *  Product: '<S162>/Multiply'
     *  Product: '<S162>/Multiply1'
     *  Sum: '<S162>/Subtract2'
     */
    rtb_MatrixConcatenate1[6] = (rtb_Integrator1_m - rtb_Add2_h) * 2.0F;

    /* Gain: '<S161>/Gain1' incorporates:
     *  Sum: '<S161>/Subtract1'
     */
    rtb_MatrixConcatenate1[5] = (rtb_Add1_j4 - rtb_DiscreteTimeIntegrator1_a) *
      2.0F;

    /* Sum: '<S161>/Subtract' incorporates:
     *  Sum: '<S161>/Add'
     *  Sum: '<S161>/Add1'
     */
    rtb_MatrixConcatenate1[4] = (rtb_Square_j + rtb_Cos1) - (rtb_Ldot_err +
      rtb_Gain_c4);

    /* Product: '<S161>/Multiply' incorporates:
     *  Product: '<S160>/Multiply'
     */
    rtb_Add1_j4 = rtb_Divide_m_idx_1 * rtb_Divide_m_idx_2;

    /* Product: '<S161>/Multiply1' incorporates:
     *  Product: '<S160>/Multiply1'
     */
    rtb_DiscreteTimeIntegrator1_a = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_3;

    /* Gain: '<S161>/Gain' incorporates:
     *  Product: '<S161>/Multiply'
     *  Product: '<S161>/Multiply1'
     *  Sum: '<S161>/Add3'
     */
    rtb_MatrixConcatenate1[3] = (rtb_Add1_j4 + rtb_DiscreteTimeIntegrator1_a) *
      2.0F;

    /* Gain: '<S160>/Gain1' incorporates:
     *  Sum: '<S160>/Add2'
     */
    rtb_MatrixConcatenate1[2] = (rtb_Integrator1_m + rtb_Add2_h) * 2.0F;

    /* Gain: '<S160>/Gain' incorporates:
     *  Sum: '<S160>/Subtract1'
     */
    rtb_MatrixConcatenate1[1] = (rtb_Add1_j4 - rtb_DiscreteTimeIntegrator1_a) *
      2.0F;

    /* Sum: '<S160>/Subtract' incorporates:
     *  Sum: '<S160>/Add'
     *  Sum: '<S160>/Add1'
     */
    rtb_MatrixConcatenate1[0] = (rtb_Square_j + rtb_Ldot_err) - (rtb_Cos1 +
      rtb_Gain_c4);

    /* Product: '<S157>/Multiply' incorporates:
     *  SignalConversion: '<S157>/TmpSignal ConversionAtMultiplyInport2'
     */
    for (i = 0; i < 3; i++) {
      rtb_MatrixConcatenate1_0[i] = rtb_MatrixConcatenate1[i + 6] *
        Controller_U.INS_Out.vd + (rtb_MatrixConcatenate1[i + 3] *
        Controller_U.INS_Out.ve + rtb_MatrixConcatenate1[i] *
        Controller_U.INS_Out.vn);
    }

    /* End of Product: '<S157>/Multiply' */
    rtb_Sum5_lp = rtb_MatrixConcatenate1_0[0];
  }

  /* End of Switch: '<S8>/Switch' */

  /* Saturate: '<S8>/Saturation1' */
  if (rtb_Sum5_lp > 100.0F) {
    rtb_Divide_m_idx_0 = 100.0F;
  } else if (rtb_Sum5_lp < 0.1F) {
    rtb_Divide_m_idx_0 = 0.1F;
  } else {
    rtb_Divide_m_idx_0 = rtb_Sum5_lp;
  }

  /* End of Saturate: '<S8>/Saturation1' */

  /* DiscreteIntegrator: '<S156>/Discrete-Time Integrator5' */
  if (Controller_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    Controller_DW.DiscreteTimeIntegrator5_DSTATE = rtb_Divide_m_idx_0;
  }

  /* MultiPortSwitch: '<S6>/Multiport Switch' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S6>/Constant2'
   *  Constant: '<S6>/Constant3'
   *  Constant: '<S6>/Constant4'
   *  Constant: '<S6>/Constant6'
   *  Inport: '<Root>/FMS_Out'
   */
  switch (Controller_U.FMS_Out.ext_state) {
   case 0:
    rtb_MultiportSwitch_idx_0 = 0;
    rtb_MultiportSwitch_idx_1 = 1;
    break;

   case 1:
    rtb_MultiportSwitch_idx_0 = 1;
    rtb_MultiportSwitch_idx_1 = 1;
    break;

   case 2:
    rtb_MultiportSwitch_idx_0 = 1;
    rtb_MultiportSwitch_idx_1 = 0;
    break;

   case 3:
    rtb_MultiportSwitch_idx_0 = 1;
    rtb_MultiportSwitch_idx_1 = 1;
    break;

   default:
    rtb_MultiportSwitch_idx_0 = 1;
    rtb_MultiportSwitch_idx_1 = 1;
    break;
  }

  /* End of MultiPortSwitch: '<S6>/Multiport Switch' */

  /* DiscreteIntegrator: '<S152>/Discrete-Time Integrator5' */
  if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_c != 0) {
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_i = (real32_T)
      rtb_MultiportSwitch_idx_1;
  }

  /* DiscreteIntegrator: '<S151>/Discrete-Time Integrator5' */
  if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_o != 0) {
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_k = (real32_T)
      rtb_MultiportSwitch_idx_0;
  }

  /* RelationalOperator: '<S153>/Compare' incorporates:
   *  Constant: '<S153>/Constant'
   *  Inport: '<Root>/FMS_Out'
   */
  rtb_Compare_m = (Controller_U.FMS_Out.ext_state != 0);

  /* Outputs for Enabled SubSystem: '<S2>/FW_Controller' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  if (rtb_Compare_m) {
    if (!Controller_DW.FW_Controller_MODE) {
      /* InitializeConditions for DiscreteIntegrator: '<S84>/Discrete-Time Integrator5' */
      Controller_DW.DiscreteTimeIntegrator5_IC_LO_n = 1U;

      /* InitializeConditions for DiscreteIntegrator: '<S79>/ ' */
      Controller_DW._DSTATE = Controller_ConstB.Zero1;
      if (Controller_DW._DSTATE >= CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
        Controller_DW._DSTATE = CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
      } else {
        if (Controller_DW._DSTATE <= -CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
          Controller_DW._DSTATE = -CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
        }
      }

      Controller_DW._PrevResetState = 0;

      /* End of InitializeConditions for DiscreteIntegrator: '<S79>/ ' */

      /* InitializeConditions for DiscreteIntegrator: '<S80>/Discrete-Time Integrator1' */
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_f = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevR_b = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S57>/Discrete-Time Integrator' */
      Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0] =
        Controller_ConstB.Constant_c[0];
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0] >=
          CONTROL_PARAM.FW_RATE_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0] =
          CONTROL_PARAM.FW_RATE_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0] <=
            CONTROL_PARAM.FW_RATE_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0] =
            CONTROL_PARAM.FW_RATE_I_MIN;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1] =
        Controller_ConstB.Constant_c[1];
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1] >=
          CONTROL_PARAM.FW_RATE_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1] =
          CONTROL_PARAM.FW_RATE_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1] <=
            CONTROL_PARAM.FW_RATE_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1] =
            CONTROL_PARAM.FW_RATE_I_MIN;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2] =
        Controller_ConstB.Constant_c[2];
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2] >=
          CONTROL_PARAM.FW_RATE_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2] =
          CONTROL_PARAM.FW_RATE_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2] <=
            CONTROL_PARAM.FW_RATE_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2] =
            CONTROL_PARAM.FW_RATE_I_MIN;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_PrevRe_e = 0;

      /* End of InitializeConditions for DiscreteIntegrator: '<S57>/Discrete-Time Integrator' */

      /* InitializeConditions for DiscreteIntegrator: '<S82>/ ' */
      Controller_DW._DSTATE_d = Controller_ConstB.Zero;
      if (Controller_DW._DSTATE_d >= 1.0F) {
        Controller_DW._DSTATE_d = 1.0F;
      } else {
        if (Controller_DW._DSTATE_d <= 0.0F) {
          Controller_DW._DSTATE_d = 0.0F;
        }
      }

      Controller_DW._PrevResetState_e = 0;

      /* End of InitializeConditions for DiscreteIntegrator: '<S82>/ ' */

      /* InitializeConditions for DiscreteIntegrator: '<S83>/Discrete-Time Integrator1' */
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_h = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevR_d = 0;
      Controller_DW.FW_Controller_MODE = true;
    }

    /* Switch: '<S61>/Switch' incorporates:
     *  Inport: '<Root>/FMS_Out'
     *  Logic: '<S61>/Logical Operator'
     *  RelationalOperator: '<S66>/Compare'
     */
    if ((Controller_U.FMS_Out.ctrl_mode == 3) || (Controller_U.FMS_Out.ctrl_mode
         == 4)) {
      rtb_Integrator1_m = Controller_U.FMS_Out.phi_cmd;
    } else {
      /* Trigonometry: '<S48>/Atan' incorporates:
       *  Gain: '<S48>/g_force'
       */
      rtb_Integrator1_m = atanf(0.101936802F * Controller_U.FMS_Out.ay_cmd);

      /* Saturate: '<S48>/Saturation' */
      if (rtb_Integrator1_m > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_Integrator1_m = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_Integrator1_m < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
          rtb_Integrator1_m = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
        }
      }

      /* End of Saturate: '<S48>/Saturation' */
    }

    /* End of Switch: '<S61>/Switch' */

    /* RelationalOperator: '<S68>/Compare' incorporates:
     *  Constant: '<S68>/Constant'
     *  Inport: '<Root>/FMS_Out'
     */
    rtb_Compare_b = (Controller_U.FMS_Out.ext_state == 1);

    /* Switch: '<S74>/Switch' incorporates:
     *  Constant: '<S74>/Constant'
     */
    if (tmp > 0U) {
      /* SignalConversion: '<S77>/ConcatBufferAtVector ConcatenateIn3' */
      rtb_MatrixConcatenate1[6] = Controller_ConstB.VectorConcatenate3_g[0];
      rtb_MatrixConcatenate1[7] = Controller_ConstB.VectorConcatenate3_g[1];
      rtb_MatrixConcatenate1[8] = Controller_ConstB.VectorConcatenate3_g[2];

      /* SignalConversion: '<S77>/ConcatBufferAtVector Concatenate2In3' incorporates:
       *  Constant: '<S77>/Constant4'
       */
      rtb_MatrixConcatenate1[5] = 0.0F;

      /* Trigonometry: '<S77>/Trigonometric Function3' incorporates:
       *  Gain: '<S76>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S77>/Trigonometric Function1'
       */
      rtb_Square_j = arm_cos_f32(-Controller_U.INS_Out.psi);
      rtb_MatrixConcatenate1[4] = rtb_Square_j;

      /* Trigonometry: '<S77>/Trigonometric Function2' incorporates:
       *  Gain: '<S76>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S77>/Trigonometric Function'
       */
      rtb_Cos1 = arm_sin_f32(-Controller_U.INS_Out.psi);

      /* Gain: '<S77>/Gain' incorporates:
       *  Trigonometry: '<S77>/Trigonometric Function2'
       */
      rtb_MatrixConcatenate1[3] = -rtb_Cos1;

      /* SignalConversion: '<S77>/ConcatBufferAtVector Concatenate1In3' incorporates:
       *  Constant: '<S77>/Constant3'
       */
      rtb_MatrixConcatenate1[2] = 0.0F;

      /* Trigonometry: '<S77>/Trigonometric Function' */
      rtb_MatrixConcatenate1[1] = rtb_Cos1;

      /* Trigonometry: '<S77>/Trigonometric Function1' */
      rtb_MatrixConcatenate1[0] = rtb_Square_j;

      /* Product: '<S74>/Multiply' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  SignalConversion: '<S74>/TmpSignal ConversionAtMultiplyInport2'
       */
      for (i = 0; i < 3; i++) {
        rtb_Multiply_ni[i] = rtb_MatrixConcatenate1[i + 6] *
          Controller_U.INS_Out.vd + (rtb_MatrixConcatenate1[i + 3] *
          Controller_U.INS_Out.ve + rtb_MatrixConcatenate1[i] *
          Controller_U.INS_Out.vn);
      }

      /* End of Product: '<S74>/Multiply' */

      /* DeadZone: '<S74>/Dead Zone' */
      if (rtb_Multiply_ni[0] > 1.0F) {
        rtb_DiscreteTimeIntegrator1_a = rtb_Multiply_ni[0] - 1.0F;
      } else if (rtb_Multiply_ni[0] >= -1.0F) {
        rtb_DiscreteTimeIntegrator1_a = 0.0F;
      } else {
        rtb_DiscreteTimeIntegrator1_a = rtb_Multiply_ni[0] - -1.0F;
      }

      /* End of DeadZone: '<S74>/Dead Zone' */

      /* Signum: '<S74>/Sign' */
      if (rtb_DiscreteTimeIntegrator1_a < 0.0F) {
        rtb_DiscreteTimeIntegrator1_a = -1.0F;
      } else {
        if (rtb_DiscreteTimeIntegrator1_a > 0.0F) {
          rtb_DiscreteTimeIntegrator1_a = 1.0F;
        }
      }

      /* End of Signum: '<S74>/Sign' */
    } else {
      rtb_DiscreteTimeIntegrator1_a = 1.0F;
    }

    /* End of Switch: '<S74>/Switch' */

    /* Switch: '<S73>/Switch' incorporates:
     *  Gain: '<S73>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S73>/Divide'
     *  Trigonometry: '<S73>/Asin'
     */
    if (tmp > 1U) {
      /* Sqrt: '<S73>/Sqrt' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Math: '<S73>/Square'
       *  Math: '<S73>/Square1'
       *  Sum: '<S73>/Add'
       */
      rtb_Square_j = sqrtf(Controller_U.INS_Out.vn * Controller_U.INS_Out.vn +
                           Controller_U.INS_Out.ve * Controller_U.INS_Out.ve);

      /* Saturate: '<S73>/Saturation' incorporates:
       *  Sqrt: '<S73>/Sqrt'
       */
      if (rtb_Square_j > 100.0F) {
        rtb_Square_j = 100.0F;
      } else {
        if (rtb_Square_j < 8.0F) {
          rtb_Square_j = 8.0F;
        }
      }

      /* End of Saturate: '<S73>/Saturation' */

      /* DeadZone: '<S73>/Dead Zone' incorporates:
       *  Inport: '<Root>/INS_Out'
       */
      if (Controller_U.INS_Out.vd > 0.1F) {
        rtb_Add3_e = Controller_U.INS_Out.vd - 0.1F;
      } else if (Controller_U.INS_Out.vd >= -0.1F) {
        rtb_Add3_e = 0.0F;
      } else {
        rtb_Add3_e = Controller_U.INS_Out.vd - -0.1F;
      }

      /* End of DeadZone: '<S73>/Dead Zone' */
      rtb_Divide_m_idx_2 = atanf(1.0F / rtb_Square_j * -rtb_Add3_e);
    } else {
      rtb_Divide_m_idx_2 = Controller_U.INS_Out.theta;
    }

    /* End of Switch: '<S73>/Switch' */

    /* Product: '<S73>/Multiply1' */
    rtb_Divide_m_idx_2 *= rtb_DiscreteTimeIntegrator1_a;

    /* Saturate: '<S73>/Saturation1' */
    if (rtb_Divide_m_idx_2 > 0.785398185F) {
      rtb_Divide_m_idx_2 = 0.785398185F;
    } else {
      if (rtb_Divide_m_idx_2 < -0.785398185F) {
        rtb_Divide_m_idx_2 = -0.785398185F;
      }
    }

    /* End of Saturate: '<S73>/Saturation1' */

    /* DiscreteIntegrator: '<S84>/Discrete-Time Integrator5' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_n != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_f = Controller_U.INS_Out.ax;
    }

    /* Gain: '<S72>/Gain1' incorporates:
     *  DiscreteIntegrator: '<S84>/Discrete-Time Integrator5'
     */
    rtb_Divide_m_idx_3 = 0.101936802F *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_f;

    /* Switch: '<S75>/Switch' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Math: '<S75>/Square'
     *  Math: '<S75>/Square1'
     *  Sqrt: '<S75>/Sqrt'
     *  Sum: '<S75>/Add'
     */
    if (tmp > 0U) {
      rtb_Sum5_lp = sqrtf(Controller_U.INS_Out.vn * Controller_U.INS_Out.vn +
                          Controller_U.INS_Out.ve * Controller_U.INS_Out.ve);
    } else {
      rtb_Sum5_lp = Controller_U.INS_Out.airspeed;
    }

    /* End of Switch: '<S75>/Switch' */

    /* Saturate: '<S75>/Saturation1' */
    if (rtb_Sum5_lp > 100.0F) {
      rtb_Sum5_lp = 100.0F;
    } else {
      if (rtb_Sum5_lp < 8.0F) {
        rtb_Sum5_lp = 8.0F;
      }
    }

    /* End of Saturate: '<S75>/Saturation1' */

    /* Product: '<S75>/Multiply1' incorporates:
     *  Gain: '<S75>/Gain'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S75>/Divide'
     *  Trigonometry: '<S75>/Asin'
     */
    rtb_DiscreteTimeIntegrator1_a *= atanf(-Controller_U.FMS_Out.w_cmd /
      rtb_Sum5_lp);

    /* Saturate: '<S75>/Saturation2' */
    if (rtb_DiscreteTimeIntegrator1_a > 0.785398185F) {
      rtb_DiscreteTimeIntegrator1_a = 0.785398185F;
    } else {
      if (rtb_DiscreteTimeIntegrator1_a < -0.785398185F) {
        rtb_DiscreteTimeIntegrator1_a = -0.785398185F;
      }
    }

    /* End of Saturate: '<S75>/Saturation2' */

    /* Sum: '<S69>/Sum' */
    rtb_DiscreteTimeIntegrator1_a -= rtb_Divide_m_idx_2;

    /* Sum: '<S72>/Sum' incorporates:
     *  DiscreteIntegrator: '<S156>/Discrete-Time Integrator5'
     *  Gain: '<S72>/Gain'
     *  Gain: '<S72>/Kv'
     *  Inport: '<Root>/FMS_Out'
     *  Sum: '<S72>/Minus'
     */
    rtb_Add3_e = (Controller_U.FMS_Out.u_cmd -
                  Controller_DW.DiscreteTimeIntegrator5_DSTATE) *
      CONTROL_PARAM.FW_TECS_VEL_P * 0.101936802F - rtb_Divide_m_idx_3;

    /* Sum: '<S49>/Minus1' incorporates:
     *  Gain: '<S49>/ucmd2pitch'
     *  Gain: '<S49>/wcmd2pitch'
     */
    rtb_Ldot_err = CONTROL_PARAM.FW_TECS_W2P * rtb_DiscreteTimeIntegrator1_a -
      CONTROL_PARAM.FW_TECS_U2P * rtb_Add3_e;

    /* Logic: '<S49>/Logical Operator' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    rtb_LogicalOperator_h = ((Controller_U.FMS_Out.reset != 0) || rtb_Compare_b);

    /* DiscreteIntegrator: '<S79>/ ' */
    if (rtb_LogicalOperator_h || (Controller_DW._PrevResetState != 0)) {
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

    /* DiscreteIntegrator: '<S80>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_f != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_e = rtb_Ldot_err;
    }

    if (rtb_LogicalOperator_h || (Controller_DW.DiscreteTimeIntegrator1_PrevR_b
         != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_e = rtb_Ldot_err;
    }

    /* Gain: '<S80>/Gain' incorporates:
     *  DiscreteIntegrator: '<S80>/Discrete-Time Integrator1'
     *  Sum: '<S80>/Sum5'
     */
    rtb_Gain_c4 = (rtb_Ldot_err - Controller_DW.DiscreteTimeIntegrator1_DSTAT_e)
      * 62.831852F;

    /* Switch: '<S61>/Switch1' incorporates:
     *  Constant: '<S67>/Constant'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S67>/Compare'
     *  Switch: '<S49>/Switch'
     *  Switch: '<S80>/Switch'
     */
    if (Controller_U.FMS_Out.ctrl_mode == 3) {
      rtb_Cos1 = Controller_U.FMS_Out.theta_cmd;
    } else if (rtb_Compare_b) {
      /* Switch: '<S49>/Switch' incorporates:
       *  Constant: '<S49>/Constant'
       */
      rtb_Cos1 = 0.0F;
    } else {
      if (rtb_LogicalOperator_h) {
        /* Switch: '<S80>/Switch' incorporates:
         *  Gain: '<S80>/Gain1'
         *  Switch: '<S49>/Switch'
         */
        rtb_Square_j = 0.0F;
      } else {
        /* Switch: '<S80>/Switch' incorporates:
         *  Switch: '<S49>/Switch'
         */
        rtb_Square_j = rtb_Gain_c4;
      }

      /* Gain: '<S78>/Gain' incorporates:
       *  Switch: '<S49>/Switch'
       */
      rtb_Square_j *= CONTROL_PARAM.FW_TECS_PITCH_D;

      /* Saturate: '<S70>/Saturation1' incorporates:
       *  Switch: '<S49>/Switch'
       */
      if (rtb_Square_j > 0.3F) {
        rtb_Square_j = 0.3F;
      } else {
        if (rtb_Square_j < -0.3F) {
          rtb_Square_j = -0.3F;
        }
      }

      /* End of Saturate: '<S70>/Saturation1' */

      /* Switch: '<S49>/Switch' incorporates:
       *  DiscreteIntegrator: '<S79>/ '
       *  Gain: '<S49>/balabnce_ratio2'
       *  Gain: '<S49>/balance_ratio'
       *  Gain: '<S49>/pitch_ff'
       *  Gain: '<S70>/P_control'
       *  Sum: '<S49>/Add3'
       *  Sum: '<S49>/Minus'
       *  Sum: '<S70>/Add'
       */
      rtb_Cos1 = ((2.0F - CONTROL_PARAM.FW_TECS_RATIO) * rtb_Divide_m_idx_2 -
                  CONTROL_PARAM.FW_TECS_RATIO * rtb_Divide_m_idx_3) *
        CONTROL_PARAM.FW_TECS_PITCH_F + ((CONTROL_PARAM.FW_TECS_PITCH_P *
        rtb_Ldot_err + Controller_DW._DSTATE) + rtb_Square_j);
    }

    /* End of Switch: '<S61>/Switch1' */

    /* Saturate: '<S62>/Saturation' */
    if (rtb_Integrator1_m > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Square_j = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else if (rtb_Integrator1_m < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Square_j = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      rtb_Square_j = rtb_Integrator1_m;
    }

    /* Reshape: '<S52>/Reshape' incorporates:
     *  Constant: '<S63>/Constant1'
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S63>/Multiply'
     *  Sum: '<S62>/Sum'
     */
    Controller_B.Reshape[0] = (rtb_Square_j - Controller_U.INS_Out.phi) *
      CONTROL_PARAM.FW_ROLL_P;

    /* Bias: '<S62>/Pitch Offset' */
    rtb_Square_j = rtb_Cos1 + CONTROL_PARAM.FW_PITCH_OFFSET;

    /* Saturate: '<S62>/Saturation' */
    if (rtb_Square_j > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Square_j = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_Square_j < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_Square_j = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      }
    }

    /* Reshape: '<S52>/Reshape' incorporates:
     *  Constant: '<S63>/Constant2'
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S63>/Multiply'
     *  Sum: '<S62>/Sum'
     */
    Controller_B.Reshape[1] = (rtb_Square_j - Controller_U.INS_Out.theta) *
      CONTROL_PARAM.FW_PITCH_P;

    /* Product: '<S65>/Divide' incorporates:
     *  Constant: '<S65>/Constant'
     *  DiscreteIntegrator: '<S156>/Discrete-Time Integrator5'
     */
    rtb_Square_j = 9.81F / Controller_DW.DiscreteTimeIntegrator5_DSTATE;

    /* Saturate: '<S65>/Saturation' */
    if (rtb_Square_j > 1.0F) {
      rtb_Square_j = 1.0F;
    } else {
      if (rtb_Square_j < 0.2F) {
        rtb_Square_j = 0.2F;
      }
    }

    /* End of Saturate: '<S65>/Saturation' */

    /* Sum: '<S60>/Sum' incorporates:
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S65>/Multiply'
     *  Product: '<S65>/Multiply1'
     *  Trigonometry: '<S65>/Cos'
     *  Trigonometry: '<S65>/Tan'
     */
    rtb_Square_j = tanf(rtb_Integrator1_m) * arm_cos_f32(rtb_Cos1) *
      rtb_Square_j + Controller_U.FMS_Out.psi_rate_cmd;

    /* Saturate: '<S60>/Saturation' */
    if (rtb_Square_j > CONTROL_PARAM.FW_YAW_RATE_LIM) {
      /* Reshape: '<S52>/Reshape' */
      Controller_B.Reshape[2] = CONTROL_PARAM.FW_YAW_RATE_LIM;
    } else if (rtb_Square_j < -CONTROL_PARAM.FW_YAW_RATE_LIM) {
      /* Reshape: '<S52>/Reshape' */
      Controller_B.Reshape[2] = -CONTROL_PARAM.FW_YAW_RATE_LIM;
    } else {
      /* Reshape: '<S52>/Reshape' */
      Controller_B.Reshape[2] = rtb_Square_j;
    }

    /* End of Saturate: '<S60>/Saturation' */

    /* Sum: '<S53>/Add' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S53>/Multiply'
     *  Trigonometry: '<S53>/Sin1'
     */
    rtb_Integrator1_m = Controller_B.Reshape[0] - arm_sin_f32
      (Controller_U.INS_Out.theta) * Controller_B.Reshape[2];

    /* Trigonometry: '<S53>/Sin' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Square_j = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S53>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Cos1 = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Trigonometry: '<S53>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_m_idx_1 = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Sum: '<S53>/Add1' incorporates:
     *  Product: '<S53>/Multiply1'
     *  Product: '<S53>/Multiply3'
     *  Trigonometry: '<S53>/Cos'
     *  Trigonometry: '<S53>/Cos1'
     *  Trigonometry: '<S53>/Sin'
     */
    rtb_Add1_j4 = rtb_Square_j * rtb_Cos1 * Controller_B.Reshape[2] +
      rtb_Divide_m_idx_1 * Controller_B.Reshape[1];

    /* Sum: '<S53>/Add2' incorporates:
     *  Product: '<S53>/Multiply4'
     *  Product: '<S53>/Multiply5'
     *  Trigonometry: '<S53>/Cos'
     *  Trigonometry: '<S53>/Cos1'
     *  Trigonometry: '<S53>/Sin'
     */
    rtb_Add2_h = rtb_Divide_m_idx_1 * rtb_Cos1 * Controller_B.Reshape[2] -
      rtb_Square_j * Controller_B.Reshape[1];

    /* Sum: '<S51>/Minus2' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Multiply_ni[0] = rtb_Integrator1_m - Controller_U.INS_Out.p;
    rtb_Multiply_ni[1] = rtb_Add1_j4 - Controller_U.INS_Out.q;
    rtb_Multiply_ni[2] = rtb_Add2_h - Controller_U.INS_Out.r;

    /* DiscreteIntegrator: '<S57>/Discrete-Time Integrator' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator_PrevRe_e != 0)) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0] =
        Controller_ConstB.Constant_c[0];
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0] >=
          CONTROL_PARAM.FW_RATE_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0] =
          CONTROL_PARAM.FW_RATE_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0] <=
            CONTROL_PARAM.FW_RATE_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0] =
            CONTROL_PARAM.FW_RATE_I_MIN;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1] =
        Controller_ConstB.Constant_c[1];
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1] >=
          CONTROL_PARAM.FW_RATE_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1] =
          CONTROL_PARAM.FW_RATE_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1] <=
            CONTROL_PARAM.FW_RATE_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1] =
            CONTROL_PARAM.FW_RATE_I_MIN;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2] =
        Controller_ConstB.Constant_c[2];
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2] >=
          CONTROL_PARAM.FW_RATE_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2] =
          CONTROL_PARAM.FW_RATE_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2] <=
            CONTROL_PARAM.FW_RATE_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2] =
            CONTROL_PARAM.FW_RATE_I_MIN;
        }
      }
    }

    if (Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0] >=
        CONTROL_PARAM.FW_RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0] =
        CONTROL_PARAM.FW_RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0] <=
          CONTROL_PARAM.FW_RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0] =
          CONTROL_PARAM.FW_RATE_I_MIN;
      }
    }

    if (Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1] >=
        CONTROL_PARAM.FW_RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1] =
        CONTROL_PARAM.FW_RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1] <=
          CONTROL_PARAM.FW_RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1] =
          CONTROL_PARAM.FW_RATE_I_MIN;
      }
    }

    if (Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2] >=
        CONTROL_PARAM.FW_RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2] =
        CONTROL_PARAM.FW_RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2] <=
          CONTROL_PARAM.FW_RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2] =
          CONTROL_PARAM.FW_RATE_I_MIN;
      }
    }

    /* Sum: '<S49>/Add' incorporates:
     *  Gain: '<S49>/ucmd2thor'
     *  Gain: '<S49>/wcmd2thor'
     */
    rtb_DiscreteTimeIntegrator1_a = CONTROL_PARAM.FW_TECS_W2T *
      rtb_DiscreteTimeIntegrator1_a + CONTROL_PARAM.FW_TECS_U2T * rtb_Add3_e;

    /* DiscreteIntegrator: '<S82>/ ' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    if ((Controller_U.FMS_Out.reset != 0) || (Controller_DW._PrevResetState_e !=
         0)) {
      Controller_DW._DSTATE_d = Controller_ConstB.Zero;
      if (Controller_DW._DSTATE_d >= 1.0F) {
        Controller_DW._DSTATE_d = 1.0F;
      } else {
        if (Controller_DW._DSTATE_d <= 0.0F) {
          Controller_DW._DSTATE_d = 0.0F;
        }
      }
    }

    if (Controller_DW._DSTATE_d >= 1.0F) {
      Controller_DW._DSTATE_d = 1.0F;
    } else {
      if (Controller_DW._DSTATE_d <= 0.0F) {
        Controller_DW._DSTATE_d = 0.0F;
      }
    }

    /* DiscreteIntegrator: '<S83>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_h != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm =
        rtb_DiscreteTimeIntegrator1_a;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_d != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm =
        rtb_DiscreteTimeIntegrator1_a;
    }

    /* Gain: '<S83>/Gain' incorporates:
     *  DiscreteIntegrator: '<S83>/Discrete-Time Integrator1'
     *  Sum: '<S83>/Sum5'
     */
    rtb_Gain_ow = (rtb_DiscreteTimeIntegrator1_a -
                   Controller_DW.DiscreteTimeIntegrator1_DSTA_nm) * 188.49556F;

    /* Switch: '<S12>/Switch' incorporates:
     *  Constant: '<S12>/Constant2'
     *  Constant: '<S50>/Constant'
     *  Constant: '<S86>/Constant'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S86>/Compare'
     *  Saturate: '<S50>/Saturation2'
     */
    if (Controller_U.FMS_Out.ctrl_mode == 1) {
      Controller_B.Switch[0] = Controller_U.FMS_Out.p_cmd;
      Controller_B.Switch[1] = Controller_U.FMS_Out.q_cmd;
      Controller_B.Switch[2] = Controller_U.FMS_Out.r_cmd;
      Controller_B.Switch[3] = Controller_U.FMS_Out.u_cmd;
      Controller_B.Switch[4] = 0.0F;
      Controller_B.Switch[5] = 0.0F;
    } else {
      /* Product: '<S55>/Divide' incorporates:
       *  Constant: '<S55>/trim_speed'
       *  DiscreteIntegrator: '<S156>/Discrete-Time Integrator5'
       *  Math: '<S55>/Square'
       *  Math: '<S55>/Square1'
       */
      rtb_thor = CONTROL_PARAM.FW_AIRSPEED_TRIM * CONTROL_PARAM.FW_AIRSPEED_TRIM
        / (Controller_DW.DiscreteTimeIntegrator5_DSTATE *
           Controller_DW.DiscreteTimeIntegrator5_DSTATE);

      /* Saturate: '<S55>/Saturation' */
      if (rtb_thor > 1.0F) {
        rtb_thor = 1.0F;
      } else {
        if (rtb_thor < 0.0F) {
          rtb_thor = 0.0F;
        }
      }

      /* End of Saturate: '<S55>/Saturation' */

      /* Product: '<S51>/Multiply' incorporates:
       *  Constant: '<S58>/gain1'
       *  Constant: '<S58>/gain2'
       *  Constant: '<S58>/gain3'
       *  DiscreteIntegrator: '<S57>/Discrete-Time Integrator'
       *  Product: '<S58>/Multiply'
       *  Sum: '<S54>/Add1'
       */
      rtb_Square_j = (CONTROL_PARAM.FW_ROLL_RATE_P * rtb_Multiply_ni[0] +
                      Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0]) *
        rtb_thor;
      rtb_Cos1 = (CONTROL_PARAM.FW_PITCH_RATE_P * rtb_Multiply_ni[1] +
                  Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1]) * rtb_thor;
      rtb_Divide_m_idx_1 = (CONTROL_PARAM.FW_YAW_RATE_P * rtb_Multiply_ni[2] +
                            Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2]) *
        rtb_thor;

      /* Product: '<S56>/Divide' incorporates:
       *  Constant: '<S56>/trim_speed'
       *  DiscreteIntegrator: '<S156>/Discrete-Time Integrator5'
       */
      rtb_thor = CONTROL_PARAM.FW_AIRSPEED_TRIM /
        Controller_DW.DiscreteTimeIntegrator5_DSTATE;

      /* Saturate: '<S56>/Saturation' */
      if (rtb_thor > 1.0F) {
        rtb_thor = 1.0F;
      } else {
        if (rtb_thor < 0.0F) {
          rtb_thor = 0.0F;
        }
      }

      /* End of Saturate: '<S56>/Saturation' */

      /* Product: '<S51>/Multiply1' incorporates:
       *  Gain: '<S51>/FF'
       */
      rtb_Sum5_lp = CONTROL_PARAM.FW_FF * rtb_Integrator1_m * rtb_thor;

      /* Saturate: '<S51>/FF_limit' */
      if (rtb_Sum5_lp > 0.3F) {
        rtb_Sum5_lp = 0.3F;
      } else {
        if (rtb_Sum5_lp < -0.3F) {
          rtb_Sum5_lp = -0.3F;
        }
      }

      /* Saturate: '<S51>/PI_limit' */
      if (rtb_Square_j > 1.0F) {
        rtb_Square_j = 1.0F;
      } else {
        if (rtb_Square_j < -1.0F) {
          rtb_Square_j = -1.0F;
        }
      }

      /* Sum: '<S51>/Add' */
      rtb_Sum5_lp += rtb_Square_j;

      /* Product: '<S51>/Multiply1' incorporates:
       *  Gain: '<S51>/FF'
       */
      rtb_Square_j = CONTROL_PARAM.FW_FF * rtb_Add1_j4 * rtb_thor;

      /* Saturate: '<S51>/FF_limit' */
      if (rtb_Square_j > 0.3F) {
        rtb_Square_j = 0.3F;
      } else {
        if (rtb_Square_j < -0.3F) {
          rtb_Square_j = -0.3F;
        }
      }

      /* Saturate: '<S51>/PI_limit' */
      if (rtb_Cos1 > 1.0F) {
        rtb_Cos1 = 1.0F;
      } else {
        if (rtb_Cos1 < -1.0F) {
          rtb_Cos1 = -1.0F;
        }
      }

      /* Sum: '<S51>/Add' */
      rtb_Add_o_idx_1 = rtb_Square_j + rtb_Cos1;

      /* Product: '<S51>/Multiply1' incorporates:
       *  Gain: '<S51>/FF'
       */
      rtb_Square_j = CONTROL_PARAM.FW_FF * rtb_Add2_h * rtb_thor;

      /* Saturate: '<S51>/FF_limit' */
      if (rtb_Square_j > 0.3F) {
        rtb_Square_j = 0.3F;
      } else {
        if (rtb_Square_j < -0.3F) {
          rtb_Square_j = -0.3F;
        }
      }

      /* Saturate: '<S51>/PI_limit' */
      if (rtb_Divide_m_idx_1 > 1.0F) {
        rtb_Divide_m_idx_1 = 1.0F;
      } else {
        if (rtb_Divide_m_idx_1 < -1.0F) {
          rtb_Divide_m_idx_1 = -1.0F;
        }
      }

      /* Sum: '<S51>/Add' */
      rtb_Add_o_idx_2 = rtb_Square_j + rtb_Divide_m_idx_1;

      /* Switch: '<S50>/Switch' incorporates:
       *  Bias: '<S50>/Bias'
       *  Constant: '<S85>/Constant'
       *  Gain: '<S50>/Gain'
       *  RelationalOperator: '<S85>/Compare'
       *  Switch: '<S83>/Switch'
       */
      if (Controller_U.FMS_Out.ctrl_mode <= 3) {
        rtb_thor = 0.000999987125F * (real32_T)Controller_U.FMS_Out.throttle_cmd
          + -1.0F;
      } else {
        if (Controller_U.FMS_Out.reset > 0) {
          /* Switch: '<S83>/Switch' incorporates:
           *  Gain: '<S83>/Gain1'
           */
          rtb_Add3_e = 0.0F;
        } else {
          /* Switch: '<S83>/Switch' */
          rtb_Add3_e = rtb_Gain_ow;
        }

        /* Gain: '<S81>/Gain' */
        rtb_thor = CONTROL_PARAM.FW_TECS_THOR_D * rtb_Add3_e;

        /* Saturate: '<S71>/Saturation1' */
        if (rtb_thor > 0.3F) {
          rtb_thor = 0.3F;
        } else {
          if (rtb_thor < -0.3F) {
            rtb_thor = -0.3F;
          }
        }

        /* End of Saturate: '<S71>/Saturation1' */

        /* Sum: '<S49>/Add2' incorporates:
         *  DiscreteIntegrator: '<S82>/ '
         *  Gain: '<S49>/thorttle_ff'
         *  Gain: '<S71>/P_control'
         *  Sum: '<S49>/Add1'
         *  Sum: '<S71>/Add4'
         */
        rtb_thor = ((CONTROL_PARAM.FW_TECS_THOR_P *
                     rtb_DiscreteTimeIntegrator1_a + Controller_DW._DSTATE_d) +
                    rtb_thor) + (rtb_Divide_m_idx_2 + rtb_Divide_m_idx_3) *
          CONTROL_PARAM.FW_TECS_THOR_FF;

        /* Saturate: '<S50>/Saturation' */
        if (rtb_thor > 1.0F) {
          rtb_thor = 1.0F;
        } else {
          if (rtb_thor < -1.0F) {
            rtb_thor = -1.0F;
          }
        }

        /* End of Saturate: '<S50>/Saturation' */
      }

      /* End of Switch: '<S50>/Switch' */

      /* Saturate: '<S51>/Saturation1' */
      if (rtb_Sum5_lp > 1.0F) {
        Controller_B.Switch[0] = 1.0F;
      } else if (rtb_Sum5_lp < -1.0F) {
        Controller_B.Switch[0] = -1.0F;
      } else {
        Controller_B.Switch[0] = rtb_Sum5_lp;
      }

      if (rtb_Add_o_idx_1 > 1.0F) {
        Controller_B.Switch[1] = 1.0F;
      } else if (rtb_Add_o_idx_1 < -1.0F) {
        Controller_B.Switch[1] = -1.0F;
      } else {
        Controller_B.Switch[1] = rtb_Add_o_idx_1;
      }

      if (rtb_Add_o_idx_2 > 1.0F) {
        Controller_B.Switch[2] = 1.0F;
      } else if (rtb_Add_o_idx_2 < -1.0F) {
        Controller_B.Switch[2] = -1.0F;
      } else {
        Controller_B.Switch[2] = rtb_Add_o_idx_2;
      }

      /* End of Saturate: '<S51>/Saturation1' */

      /* Saturate: '<S50>/Saturation2' */
      if (rtb_thor > 1.0F) {
        Controller_B.Switch[3] = 1.0F;
      } else {
        Controller_B.Switch[3] = rtb_thor;
      }

      Controller_B.Switch[4] = 0.0F;
      Controller_B.Switch[5] = 0.0F;
    }

    /* End of Switch: '<S12>/Switch' */

    /* Product: '<S4>/Multiply' incorporates:
     *  DiscreteIntegrator: '<S151>/Discrete-Time Integrator5'
     */
    Controller_B.Multiply_c[0] = Controller_B.Switch[0] *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_k;
    Controller_B.Multiply_c[1] = Controller_B.Switch[1] *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_k;
    Controller_B.Multiply_c[2] = Controller_B.Switch[2] *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_k;

    /* Update for DiscreteIntegrator: '<S84>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S84>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S84>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_n = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_f += (Controller_U.INS_Out.ax -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_f) * 31.415926F * 0.002F;

    /* Update for DiscreteIntegrator: '<S79>/ ' incorporates:
     *  Gain: '<S79>/Gain3'
     */
    Controller_DW._DSTATE += CONTROL_PARAM.FW_TECS_PITCH_I * rtb_Ldot_err *
      0.002F;
    if (Controller_DW._DSTATE >= CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
      Controller_DW._DSTATE = CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
    } else {
      if (Controller_DW._DSTATE <= -CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
        Controller_DW._DSTATE = -CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
      }
    }

    Controller_DW._PrevResetState = (int8_T)rtb_LogicalOperator_h;

    /* End of Update for DiscreteIntegrator: '<S79>/ ' */

    /* Update for DiscreteIntegrator: '<S80>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_f = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_e += 0.002F * rtb_Gain_c4;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_b = (int8_T)
      rtb_LogicalOperator_h;

    /* Update for DiscreteIntegrator: '<S57>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S57>/gain1'
     *  Constant: '<S57>/gain2'
     *  Constant: '<S57>/gain3'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S57>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0] +=
      CONTROL_PARAM.FW_ROLL_RATE_I * rtb_Multiply_ni[0] * 0.002F;
    if (Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0] >=
        CONTROL_PARAM.FW_RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0] =
        CONTROL_PARAM.FW_RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0] <=
          CONTROL_PARAM.FW_RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0] =
          CONTROL_PARAM.FW_RATE_I_MIN;
      }
    }

    Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1] +=
      CONTROL_PARAM.FW_PITCH_RATE_I * rtb_Multiply_ni[1] * 0.002F;
    if (Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1] >=
        CONTROL_PARAM.FW_RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1] =
        CONTROL_PARAM.FW_RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1] <=
          CONTROL_PARAM.FW_RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1] =
          CONTROL_PARAM.FW_RATE_I_MIN;
      }
    }

    Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2] +=
      CONTROL_PARAM.FW_YAW_RATE_I * rtb_Multiply_ni[2] * 0.002F;
    if (Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2] >=
        CONTROL_PARAM.FW_RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2] =
        CONTROL_PARAM.FW_RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2] <=
          CONTROL_PARAM.FW_RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2] =
          CONTROL_PARAM.FW_RATE_I_MIN;
      }
    }

    Controller_DW.DiscreteTimeIntegrator_PrevRe_e = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* End of Update for DiscreteIntegrator: '<S57>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S82>/ ' incorporates:
     *  Gain: '<S82>/Gain'
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW._DSTATE_d += CONTROL_PARAM.FW_TECS_THOR_I *
      rtb_DiscreteTimeIntegrator1_a * 0.002F;
    if (Controller_DW._DSTATE_d >= 1.0F) {
      Controller_DW._DSTATE_d = 1.0F;
    } else {
      if (Controller_DW._DSTATE_d <= 0.0F) {
        Controller_DW._DSTATE_d = 0.0F;
      }
    }

    Controller_DW._PrevResetState_e = (int8_T)(Controller_U.FMS_Out.reset > 0);

    /* End of Update for DiscreteIntegrator: '<S82>/ ' */

    /* Update for DiscreteIntegrator: '<S83>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_h = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTA_nm += 0.002F * rtb_Gain_ow;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_d = (int8_T)
      (Controller_U.FMS_Out.reset > 0);
  } else {
    if (Controller_DW.FW_Controller_MODE) {
      Controller_DW.FW_Controller_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S2>/FW_Controller' */

  /* Outputs for Enabled SubSystem: '<S2>/MC_Controller' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  if (rtb_Compare) {
    if (!Controller_DW.MC_Controller_MODE) {
      /* InitializeConditions for DiscreteIntegrator: '<S108>/Discrete-Time Integrator' */
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
        Controller_ConstB.Constant[0];
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

      Controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
        Controller_ConstB.Constant[1];
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

      Controller_DW.DiscreteTimeIntegrator_DSTATE[2] =
        Controller_ConstB.Constant[2];
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

      Controller_DW.DiscreteTimeIntegrator_PrevRese = 0;

      /* End of InitializeConditions for DiscreteIntegrator: '<S108>/Discrete-Time Integrator' */

      /* InitializeConditions for DiscreteIntegrator: '<S132>/Discrete-Time Integrator' */
      Controller_DW.DiscreteTimeIntegrator_PrevRe_p = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S134>/Discrete-Time Integrator1' */
      Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S105>/Discrete-Time Integrator5' */
      Controller_DW.DiscreteTimeIntegrator5_IC_L_ck = 1U;

      /* InitializeConditions for DiscreteIntegrator: '<S110>/Discrete-Time Integrator1' */
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevR_k = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S127>/Integrator1' */
      Controller_DW.Integrator1_DSTATE[0] = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S132>/Discrete-Time Integrator' */
      Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0] =
        Controller_ConstB.Constant_e;
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0] >=
          CONTROL_PARAM.MC_VEL_XY_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0] =
          CONTROL_PARAM.MC_VEL_XY_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0] <=
            CONTROL_PARAM.MC_VEL_XY_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0] =
            CONTROL_PARAM.MC_VEL_XY_I_MIN;
        }
      }

      /* InitializeConditions for DiscreteIntegrator: '<S127>/Integrator' */
      Controller_DW.Integrator_DSTATE[0] = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S127>/Integrator1' */
      Controller_DW.Integrator1_DSTATE[1] = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S132>/Discrete-Time Integrator' */
      Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1] =
        Controller_ConstB.Constant_e;
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1] >=
          CONTROL_PARAM.MC_VEL_XY_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1] =
          CONTROL_PARAM.MC_VEL_XY_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1] <=
            CONTROL_PARAM.MC_VEL_XY_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1] =
            CONTROL_PARAM.MC_VEL_XY_I_MIN;
        }
      }

      /* InitializeConditions for DiscreteIntegrator: '<S127>/Integrator' */
      Controller_DW.Integrator_DSTATE[1] = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S145>/Integrator1' */
      Controller_DW.Integrator1_DSTATE_e = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S148>/Discrete-Time Integrator' */
      Controller_DW.DiscreteTimeIntegrator_DSTATE_l = Controller_B.Constant;
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_l >=
          CONTROL_PARAM.MC_VEL_Z_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_l =
          CONTROL_PARAM.MC_VEL_Z_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_l <=
            CONTROL_PARAM.MC_VEL_Z_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_l =
            CONTROL_PARAM.MC_VEL_Z_I_MIN;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_PrevRe_f = 0;

      /* End of InitializeConditions for DiscreteIntegrator: '<S148>/Discrete-Time Integrator' */

      /* InitializeConditions for DiscreteIntegrator: '<S150>/Discrete-Time Integrator1' */
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 1U;
      Controller_DW.DiscreteTimeIntegrator1_Prev_ks = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S145>/Integrator' */
      Controller_DW.Integrator_DSTATE_j = 0.0F;
      Controller_DW.MC_Controller_MODE = true;
    }

    /* DiscreteIntegrator: '<S108>/Discrete-Time Integrator' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator_PrevRese != 0)) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
        Controller_ConstB.Constant[0];
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

      Controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
        Controller_ConstB.Constant[1];
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

      Controller_DW.DiscreteTimeIntegrator_DSTATE[2] =
        Controller_ConstB.Constant[2];
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
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
        CONTROL_PARAM.MC_RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] <=
          CONTROL_PARAM.MC_RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
          CONTROL_PARAM.MC_RATE_I_MIN;
      }
    }

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

    /* Trigonometry: '<S129>/Trigonometric Function1' incorporates:
     *  Gain: '<S128>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1[0] = arm_cos_f32(-Controller_U.INS_Out.psi);

    /* Trigonometry: '<S129>/Trigonometric Function' incorporates:
     *  Gain: '<S128>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1[1] = arm_sin_f32(-Controller_U.INS_Out.psi);

    /* SignalConversion: '<S129>/ConcatBufferAtVector Concatenate1In3' incorporates:
     *  Constant: '<S129>/Constant3'
     */
    rtb_MatrixConcatenate1[2] = 0.0F;

    /* Gain: '<S129>/Gain' incorporates:
     *  Gain: '<S128>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S129>/Trigonometric Function2'
     */
    rtb_MatrixConcatenate1[3] = -arm_sin_f32(-Controller_U.INS_Out.psi);

    /* Trigonometry: '<S129>/Trigonometric Function3' incorporates:
     *  Gain: '<S128>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1[4] = arm_cos_f32(-Controller_U.INS_Out.psi);

    /* SignalConversion: '<S129>/ConcatBufferAtVector Concatenate2In3' incorporates:
     *  Constant: '<S129>/Constant4'
     */
    rtb_MatrixConcatenate1[5] = 0.0F;

    /* SignalConversion: '<S129>/ConcatBufferAtVector ConcatenateIn3' */
    rtb_MatrixConcatenate1[6] = Controller_ConstB.VectorConcatenate3[0];
    rtb_MatrixConcatenate1[7] = Controller_ConstB.VectorConcatenate3[1];
    rtb_MatrixConcatenate1[8] = Controller_ConstB.VectorConcatenate3[2];

    /* Product: '<S126>/Multiply' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  SignalConversion: '<S126>/TmpSignal ConversionAtMultiplyInport2'
     */
    for (i = 0; i < 3; i++) {
      rtb_MatrixConcatenate1_0[i] = rtb_MatrixConcatenate1[i + 3] *
        Controller_U.INS_Out.ve + rtb_MatrixConcatenate1[i] *
        Controller_U.INS_Out.vn;
    }

    /* End of Product: '<S126>/Multiply' */

    /* Sum: '<S123>/Sum' incorporates:
     *  DiscreteIntegrator: '<S127>/Integrator1'
     */
    rtb_Divide_m_idx_3 = Controller_DW.Integrator1_DSTATE[0] -
      rtb_MatrixConcatenate1_0[0];
    rtb_Ldot_err = Controller_DW.Integrator1_DSTATE[1] -
      rtb_MatrixConcatenate1_0[1];

    /* Logic: '<S90>/Logical Operator' incorporates:
     *  Constant: '<S122>/Constant'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S122>/Compare'
     */
    rtb_Compare_b = ((Controller_U.FMS_Out.reset != 0) ||
                     (Controller_U.FMS_Out.ext_state != 0));

    /* DiscreteIntegrator: '<S132>/Discrete-Time Integrator' */
    if (rtb_Compare_b || (Controller_DW.DiscreteTimeIntegrator_PrevRe_p != 0)) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0] =
        Controller_ConstB.Constant_e;
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0] >=
          CONTROL_PARAM.MC_VEL_XY_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0] =
          CONTROL_PARAM.MC_VEL_XY_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0] <=
            CONTROL_PARAM.MC_VEL_XY_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0] =
            CONTROL_PARAM.MC_VEL_XY_I_MIN;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1] =
        Controller_ConstB.Constant_e;
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1] >=
          CONTROL_PARAM.MC_VEL_XY_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1] =
          CONTROL_PARAM.MC_VEL_XY_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1] <=
            CONTROL_PARAM.MC_VEL_XY_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1] =
            CONTROL_PARAM.MC_VEL_XY_I_MIN;
        }
      }
    }

    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0] >=
        CONTROL_PARAM.MC_VEL_XY_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0] =
        CONTROL_PARAM.MC_VEL_XY_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0] <=
          CONTROL_PARAM.MC_VEL_XY_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0] =
          CONTROL_PARAM.MC_VEL_XY_I_MIN;
      }
    }

    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1] >=
        CONTROL_PARAM.MC_VEL_XY_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1] =
        CONTROL_PARAM.MC_VEL_XY_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1] <=
          CONTROL_PARAM.MC_VEL_XY_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1] =
          CONTROL_PARAM.MC_VEL_XY_I_MIN;
      }
    }

    /* DiscreteIntegrator: '<S134>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] = rtb_Divide_m_idx_3;
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] = rtb_Ldot_err;
    }

    if (rtb_Compare_b || (Controller_DW.DiscreteTimeIntegrator1_PrevRes != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] = rtb_Divide_m_idx_3;
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] = rtb_Ldot_err;
    }

    /* Gain: '<S134>/Gain' incorporates:
     *  DiscreteIntegrator: '<S134>/Discrete-Time Integrator1'
     *  Sum: '<S134>/Sum5'
     */
    rtb_Gain_c4 = (rtb_Divide_m_idx_3 -
                   Controller_DW.DiscreteTimeIntegrator1_DSTATE[0]) * 62.831852F;
    rtb_Add1_j4 = (rtb_Ldot_err - Controller_DW.DiscreteTimeIntegrator1_DSTATE[1])
      * 62.831852F;

    /* Switch: '<S134>/Switch' incorporates:
     *  Gain: '<S134>/Gain1'
     */
    if (rtb_Compare_b) {
      rtb_Integrator1_m = 0.0F;
      rtb_Sum5_lp = 0.0F;
    } else {
      rtb_Integrator1_m = rtb_Gain_c4;
      rtb_Sum5_lp = rtb_Add1_j4;
    }

    /* End of Switch: '<S134>/Switch' */

    /* Product: '<S131>/Multiply' incorporates:
     *  Constant: '<S131>/kd'
     */
    rtb_Add_o_idx_1 = CONTROL_PARAM.MC_VEL_XY_D * rtb_Integrator1_m;

    /* Saturate: '<S131>/Saturation' */
    if (rtb_Add_o_idx_1 > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
      rtb_Add_o_idx_1 = CONTROL_PARAM.MC_VEL_XY_D_MAX;
    } else {
      if (rtb_Add_o_idx_1 < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
        rtb_Add_o_idx_1 = CONTROL_PARAM.MC_VEL_XY_D_MIN;
      }
    }

    /* Product: '<S131>/Multiply' incorporates:
     *  Constant: '<S131>/kd'
     */
    rtb_Integrator1_m = rtb_Add_o_idx_1;
    rtb_Add_o_idx_1 = CONTROL_PARAM.MC_VEL_XY_D * rtb_Sum5_lp;

    /* Saturate: '<S131>/Saturation' */
    if (rtb_Add_o_idx_1 > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
      rtb_Add_o_idx_1 = CONTROL_PARAM.MC_VEL_XY_D_MAX;
    } else {
      if (rtb_Add_o_idx_1 < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
        rtb_Add_o_idx_1 = CONTROL_PARAM.MC_VEL_XY_D_MIN;
      }
    }

    /* Switch: '<S125>/Switch' incorporates:
     *  Constant: '<S133>/kp'
     *  Constant: '<S135>/Constant'
     *  Constant: '<S137>/Constant'
     *  Constant: '<S138>/Constant'
     *  DiscreteIntegrator: '<S132>/Discrete-Time Integrator'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S133>/Multiply'
     *  Product: '<S136>/Multiply2'
     *  Product: '<S136>/Multiply3'
     *  RelationalOperator: '<S135>/Compare'
     *  RelationalOperator: '<S137>/Compare'
     *  RelationalOperator: '<S138>/Compare'
     *  S-Function (sfix_bitop): '<S136>/cmd_ax valid'
     *  S-Function (sfix_bitop): '<S136>/cmd_ay valid'
     *  S-Function (sfix_bitop): '<S136>/cmd_u valid'
     *  S-Function (sfix_bitop): '<S136>/cmd_v valid'
     *  Sum: '<S124>/Add'
     *  Sum: '<S136>/Sum1'
     */
    if (Controller_U.FMS_Out.ctrl_mode == 6) {
      rtb_Integrator1_m = ((Controller_U.FMS_Out.cmd_mask & 64) > 0 ?
                           (CONTROL_PARAM.MC_VEL_XY_P * rtb_Divide_m_idx_3 +
                            Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0]) +
                           rtb_Integrator1_m : 0.0F) +
        ((Controller_U.FMS_Out.cmd_mask & 512) > 0 ? Controller_U.FMS_Out.ax_cmd
         : 0.0F);
      rtb_Sum5_lp = ((Controller_U.FMS_Out.cmd_mask & 128) > 0 ?
                     (CONTROL_PARAM.MC_VEL_XY_P * rtb_Ldot_err +
                      Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1]) +
                     rtb_Add_o_idx_1 : 0.0F) + ((Controller_U.FMS_Out.cmd_mask &
        1024) > 0 ? Controller_U.FMS_Out.ay_cmd : 0.0F);
    } else {
      rtb_Integrator1_m += CONTROL_PARAM.MC_VEL_XY_P * rtb_Divide_m_idx_3 +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0];
      rtb_Sum5_lp = (CONTROL_PARAM.MC_VEL_XY_P * rtb_Ldot_err +
                     Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1]) +
        rtb_Add_o_idx_1;
    }

    /* End of Switch: '<S125>/Switch' */

    /* Trigonometry: '<S121>/Atan' incorporates:
     *  Constant: '<S121>/g'
     *  Gain: '<S121>/Gain1'
     *  Gain: '<S121>/gain'
     *  Product: '<S121>/Divide'
     */
    rtb_Square_j = atanf(1.1F * rtb_Sum5_lp / 9.8055F);
    rtb_Sum5_lp = atanf(1.1F * -rtb_Integrator1_m / 9.8055F);

    /* Switch: '<S112>/Switch' incorporates:
     *  Constant: '<S119>/Constant'
     *  Inport: '<Root>/FMS_Out'
     *  Logic: '<S112>/Logical Operator'
     *  RelationalOperator: '<S118>/Compare'
     *  RelationalOperator: '<S119>/Compare'
     *  Saturate: '<S121>/Saturation'
     *  Switch: '<S112>/Switch1'
     */
    if ((Controller_U.FMS_Out.ctrl_mode == 3) || (Controller_U.FMS_Out.ctrl_mode
         == 4)) {
      rtb_Integrator1_m = Controller_U.FMS_Out.phi_cmd;
      rtb_Sum5_lp = Controller_U.FMS_Out.theta_cmd;
    } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
      /* Switch: '<S120>/Switch' incorporates:
       *  S-Function (sfix_bitop): '<S120>/cmd_phi valid'
       *  S-Function (sfix_bitop): '<S120>/cmd_theta valid'
       *  Saturate: '<S121>/Saturation'
       *  Switch: '<S112>/Switch1'
       */
      if ((Controller_U.FMS_Out.cmd_mask & 8) > 0) {
        rtb_Integrator1_m = Controller_U.FMS_Out.phi_cmd;
      } else if (rtb_Square_j > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S121>/Saturation' */
        rtb_Integrator1_m = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else if (rtb_Square_j < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S121>/Saturation' */
        rtb_Integrator1_m = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        rtb_Integrator1_m = rtb_Square_j;
      }

      if ((Controller_U.FMS_Out.cmd_mask & 16) > 0) {
        rtb_Sum5_lp = Controller_U.FMS_Out.theta_cmd;
      } else if (rtb_Sum5_lp > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S121>/Saturation' */
        rtb_Sum5_lp = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_Sum5_lp < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Saturate: '<S121>/Saturation' */
          rtb_Sum5_lp = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        }
      }

      /* End of Switch: '<S120>/Switch' */
    } else {
      if (rtb_Square_j > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S121>/Saturation' incorporates:
         *  Switch: '<S112>/Switch1'
         */
        rtb_Integrator1_m = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else if (rtb_Square_j < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S121>/Saturation' incorporates:
         *  Switch: '<S112>/Switch1'
         */
        rtb_Integrator1_m = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        /* Switch: '<S112>/Switch1' incorporates:
         *  Saturate: '<S121>/Saturation'
         */
        rtb_Integrator1_m = rtb_Square_j;
      }

      /* Saturate: '<S121>/Saturation' */
      if (rtb_Sum5_lp > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Switch: '<S112>/Switch1' */
        rtb_Sum5_lp = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_Sum5_lp < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Switch: '<S112>/Switch1' */
          rtb_Sum5_lp = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        }
      }
    }

    /* End of Switch: '<S112>/Switch' */

    /* Sum: '<S113>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Add_o_idx_1 = rtb_Integrator1_m - Controller_U.INS_Out.phi;

    /* Product: '<S116>/Divide1' incorporates:
     *  Abs: '<S116>/Abs'
     *  Constant: '<S116>/const2'
     */
    rtb_DiscreteTimeIntegrator1_a = fabsf(rtb_Add_o_idx_1) / 0.002F;

    /* Product: '<S116>/Divide' incorporates:
     *  Constant: '<S114>/Constant1'
     *  Constant: '<S116>/const1'
     *  Math: '<S116>/Square'
     *  SignalConversion: '<S116>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_Cos1 = 9.5993F / (CONTROL_PARAM.MC_ROLL_P * CONTROL_PARAM.MC_ROLL_P);

    /* Signum: '<S116>/Sign' */
    if (rtb_Add_o_idx_1 < 0.0F) {
      rtb_Divide_m_idx_1 = -1.0F;
    } else if (rtb_Add_o_idx_1 > 0.0F) {
      rtb_Divide_m_idx_1 = 1.0F;
    } else {
      rtb_Divide_m_idx_1 = rtb_Add_o_idx_1;
    }

    /* Switch: '<S116>/Switch' incorporates:
     *  Constant: '<S114>/Constant1'
     *  Gain: '<S116>/Gain1'
     *  Gain: '<S116>/Gain2'
     *  Logic: '<S116>/Logical Operator'
     *  Product: '<S116>/Multiply'
     *  Product: '<S116>/Multiply1'
     *  Product: '<S116>/Multiply2'
     *  Product: '<S116>/Multiply3'
     *  RelationalOperator: '<S116>/Relational Operator'
     *  RelationalOperator: '<S116>/Relational Operator2'
     *  SignalConversion: '<S116>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S116>/Sqrt'
     *  Sum: '<S116>/Subtract'
     */
    if ((rtb_Add_o_idx_1 <= rtb_Cos1) && (rtb_Add_o_idx_1 >= -rtb_Cos1)) {
      rtb_Divide_m_idx_1 = rtb_Add_o_idx_1 * CONTROL_PARAM.MC_ROLL_P;
    } else {
      rtb_Divide_m_idx_1 *= sqrtf((rtb_Divide_m_idx_1 * rtb_Add_o_idx_1 - 0.5F *
        rtb_Cos1) * Controller_ConstB.Gain);
    }

    /* Product: '<S116>/Divide' incorporates:
     *  Gain: '<S116>/Gain3'
     */
    rtb_Square_j = -rtb_DiscreteTimeIntegrator1_a;

    /* Switch: '<S117>/Switch' incorporates:
     *  Gain: '<S116>/Gain3'
     *  RelationalOperator: '<S117>/UpperRelop'
     */
    if (rtb_Divide_m_idx_1 >= -rtb_DiscreteTimeIntegrator1_a) {
      /* Product: '<S116>/Divide' */
      rtb_Square_j = rtb_Divide_m_idx_1;
    }

    /* Product: '<S116>/Divide1' */
    rtb_Integrator1_m = rtb_DiscreteTimeIntegrator1_a;

    /* Signum: '<S116>/Sign' */
    rtb_Divide_m_idx_2 = rtb_Divide_m_idx_1;

    /* Sum: '<S113>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Add_o_idx_1 = rtb_Sum5_lp - Controller_U.INS_Out.theta;

    /* Product: '<S116>/Divide1' incorporates:
     *  Abs: '<S116>/Abs'
     *  Constant: '<S116>/const2'
     */
    rtb_DiscreteTimeIntegrator1_a = fabsf(rtb_Add_o_idx_1) / 0.002F;

    /* Product: '<S116>/Divide' incorporates:
     *  Constant: '<S114>/Constant2'
     *  Constant: '<S116>/const1'
     *  Math: '<S116>/Square'
     *  SignalConversion: '<S116>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_Cos1 = 9.5993F / (CONTROL_PARAM.MC_PITCH_P * CONTROL_PARAM.MC_PITCH_P);

    /* Signum: '<S116>/Sign' */
    if (rtb_Add_o_idx_1 < 0.0F) {
      rtb_Divide_m_idx_1 = -1.0F;
    } else if (rtb_Add_o_idx_1 > 0.0F) {
      rtb_Divide_m_idx_1 = 1.0F;
    } else {
      rtb_Divide_m_idx_1 = rtb_Add_o_idx_1;
    }

    /* Switch: '<S116>/Switch' incorporates:
     *  Constant: '<S114>/Constant2'
     *  Gain: '<S116>/Gain1'
     *  Gain: '<S116>/Gain2'
     *  Logic: '<S116>/Logical Operator'
     *  Product: '<S116>/Multiply'
     *  Product: '<S116>/Multiply1'
     *  Product: '<S116>/Multiply2'
     *  Product: '<S116>/Multiply3'
     *  RelationalOperator: '<S116>/Relational Operator'
     *  RelationalOperator: '<S116>/Relational Operator2'
     *  SignalConversion: '<S116>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S116>/Sqrt'
     *  Sum: '<S116>/Subtract'
     */
    if ((rtb_Add_o_idx_1 <= rtb_Cos1) && (rtb_Add_o_idx_1 >= -rtb_Cos1)) {
      rtb_Divide_m_idx_1 = rtb_Add_o_idx_1 * CONTROL_PARAM.MC_PITCH_P;
    } else {
      rtb_Divide_m_idx_1 *= sqrtf((rtb_Divide_m_idx_1 * rtb_Add_o_idx_1 - 0.5F *
        rtb_Cos1) * Controller_ConstB.Gain);
    }

    /* Gain: '<S116>/Gain3' */
    rtb_Cos1 = -rtb_DiscreteTimeIntegrator1_a;

    /* Switch: '<S117>/Switch' incorporates:
     *  Gain: '<S116>/Gain3'
     *  RelationalOperator: '<S117>/UpperRelop'
     */
    if (rtb_Divide_m_idx_1 >= -rtb_DiscreteTimeIntegrator1_a) {
      rtb_Cos1 = rtb_Divide_m_idx_1;
    }

    /* MultiPortSwitch: '<S93>/Multiport Switch' incorporates:
     *  Constant: '<S95>/Constant3'
     *  Constant: '<S98>/Constant3'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S95>/Multiply1'
     *  Product: '<S95>/Multiply2'
     *  Product: '<S98>/Multiply1'
     *  Product: '<S98>/Multiply2'
     *  Sum: '<S95>/Sum'
     *  Sum: '<S95>/Sum1'
     *  Sum: '<S98>/Sum'
     *  Sum: '<S98>/Sum1'
     */
    switch (Controller_U.FMS_Out.ext_state) {
     case 1:
      /* Saturate: '<S98>/Saturation3' */
      if (Controller_DW.DiscreteTimeIntegrator5_DSTATE > 7.0F) {
        rtb_Add3_e = 7.0F;
      } else if (Controller_DW.DiscreteTimeIntegrator5_DSTATE < 1.0F) {
        rtb_Add3_e = 1.0F;
      } else {
        rtb_Add3_e = Controller_DW.DiscreteTimeIntegrator5_DSTATE;
      }

      /* End of Saturate: '<S98>/Saturation3' */

      /* Product: '<S98>/Multiply' incorporates:
       *  Constant: '<S98>/Constant1'
       *  Sum: '<S98>/Subtract1'
       */
      rtb_Cos1 = (rtb_Add3_e - 1.0F) * Controller_ConstB.Divide_k;

      /* Switch: '<S117>/Switch2' incorporates:
       *  RelationalOperator: '<S117>/LowerRelop1'
       */
      if (rtb_Divide_m_idx_2 > rtb_Integrator1_m) {
        rtb_Square_j = rtb_Integrator1_m;
      }

      Controller_B.Multiply[0] = (1.0F - rtb_Cos1) * rtb_Square_j + rtb_Cos1 *
        Controller_B.Reshape[0];
      Controller_B.Multiply[1] = Controller_B.Reshape[1];
      Controller_B.Multiply[2] = (1.0F - rtb_Cos1) *
        Controller_U.FMS_Out.psi_rate_cmd + rtb_Cos1 * Controller_B.Reshape[2];
      break;

     case 3:
      /* Saturate: '<S95>/Saturation3' */
      if (Controller_DW.DiscreteTimeIntegrator5_DSTATE > 8.0F) {
        rtb_Add3_e = 8.0F;
      } else if (Controller_DW.DiscreteTimeIntegrator5_DSTATE < 2.0F) {
        rtb_Add3_e = 2.0F;
      } else {
        rtb_Add3_e = Controller_DW.DiscreteTimeIntegrator5_DSTATE;
      }

      /* End of Saturate: '<S95>/Saturation3' */

      /* Product: '<S95>/Multiply' incorporates:
       *  Constant: '<S95>/Constant1'
       *  Sum: '<S95>/Subtract1'
       */
      rtb_Add2_h = (rtb_Add3_e - 2.0F) * Controller_ConstB.Divide;

      /* Switch: '<S117>/Switch2' incorporates:
       *  RelationalOperator: '<S117>/LowerRelop1'
       */
      if (rtb_Divide_m_idx_2 > rtb_Integrator1_m) {
        rtb_Square_j = rtb_Integrator1_m;
      }

      Controller_B.Multiply[0] = (1.0F - rtb_Add2_h) * rtb_Square_j + rtb_Add2_h
        * Controller_B.Reshape[0];

      /* Switch: '<S117>/Switch2' incorporates:
       *  Constant: '<S95>/Constant3'
       *  Product: '<S95>/Multiply1'
       *  Product: '<S95>/Multiply2'
       *  RelationalOperator: '<S117>/LowerRelop1'
       *  Sum: '<S95>/Sum'
       *  Sum: '<S95>/Sum1'
       */
      if (rtb_Divide_m_idx_1 > rtb_DiscreteTimeIntegrator1_a) {
        rtb_Cos1 = rtb_DiscreteTimeIntegrator1_a;
      }

      Controller_B.Multiply[1] = (1.0F - rtb_Add2_h) * rtb_Cos1 + rtb_Add2_h *
        Controller_B.Reshape[1];
      Controller_B.Multiply[2] = (1.0F - rtb_Add2_h) *
        Controller_U.FMS_Out.psi_rate_cmd + rtb_Add2_h * Controller_B.Reshape[2];
      break;

     case 4:
      Controller_B.Multiply[0] = Controller_B.Reshape[0];
      Controller_B.Multiply[1] = Controller_B.Reshape[1];
      Controller_B.Multiply[2] = Controller_B.Reshape[2];
      break;

     default:
      /* Switch: '<S117>/Switch2' incorporates:
       *  RelationalOperator: '<S117>/LowerRelop1'
       */
      if (rtb_Divide_m_idx_2 > rtb_Integrator1_m) {
        Controller_B.Multiply[0] = rtb_Integrator1_m;
      } else {
        Controller_B.Multiply[0] = rtb_Square_j;
      }

      if (rtb_Divide_m_idx_1 > rtb_DiscreteTimeIntegrator1_a) {
        Controller_B.Multiply[1] = rtb_DiscreteTimeIntegrator1_a;
      } else {
        Controller_B.Multiply[1] = rtb_Cos1;
      }

      Controller_B.Multiply[2] = Controller_U.FMS_Out.psi_rate_cmd;
      break;
    }

    /* End of MultiPortSwitch: '<S93>/Multiport Switch' */

    /* Trigonometry: '<S96>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Sum5_lp = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Trigonometry: '<S96>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Add3_e = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S96>/Sin' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_DiscreteTimeIntegrator1_a = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Sum: '<S96>/Add2' incorporates:
     *  Product: '<S96>/Multiply4'
     *  Product: '<S96>/Multiply5'
     *  Trigonometry: '<S96>/Cos'
     *  Trigonometry: '<S96>/Cos1'
     *  Trigonometry: '<S96>/Sin'
     */
    rtb_Divide_m_idx_2 = rtb_Add3_e * rtb_Sum5_lp * Controller_B.Multiply[2] -
      rtb_DiscreteTimeIntegrator1_a * Controller_B.Multiply[1];

    /* Saturate: '<S93>/Saturation' */
    if (rtb_Divide_m_idx_2 > CONTROL_PARAM.MC_R_CMD_LIM) {
      rtb_Divide_m_idx_2 = CONTROL_PARAM.MC_R_CMD_LIM;
    } else {
      if (rtb_Divide_m_idx_2 < -CONTROL_PARAM.MC_R_CMD_LIM) {
        rtb_Divide_m_idx_2 = -CONTROL_PARAM.MC_R_CMD_LIM;
      }
    }

    /* End of Saturate: '<S93>/Saturation' */

    /* Sum: '<S96>/Add' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S96>/Multiply'
     *  Trigonometry: '<S96>/Sin1'
     */
    rtb_Integrator1_m = Controller_B.Multiply[0] - arm_sin_f32
      (Controller_U.INS_Out.theta) * Controller_B.Multiply[2];

    /* Saturate: '<S93>/Saturation1' */
    if (rtb_Integrator1_m > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_Integrator1_m = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_Integrator1_m < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_Integrator1_m = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    /* End of Saturate: '<S93>/Saturation1' */

    /* Sum: '<S96>/Add1' incorporates:
     *  Product: '<S96>/Multiply1'
     *  Product: '<S96>/Multiply3'
     *  Trigonometry: '<S96>/Cos'
     *  Trigonometry: '<S96>/Cos1'
     *  Trigonometry: '<S96>/Sin'
     */
    rtb_DiscreteTimeIntegrator1_a = rtb_DiscreteTimeIntegrator1_a * rtb_Sum5_lp *
      Controller_B.Multiply[2] + rtb_Add3_e * Controller_B.Multiply[1];

    /* Saturate: '<S93>/Saturation2' */
    if (rtb_DiscreteTimeIntegrator1_a > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_DiscreteTimeIntegrator1_a = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_DiscreteTimeIntegrator1_a < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_DiscreteTimeIntegrator1_a = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    /* End of Saturate: '<S93>/Saturation2' */

    /* Sum: '<S101>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Square_j = rtb_Integrator1_m - Controller_U.INS_Out.p;

    /* Saturate: '<S101>/Saturation' */
    if (rtb_Square_j > 3.14159274F) {
      rtb_Square_j = 3.14159274F;
    } else {
      if (rtb_Square_j < -3.14159274F) {
        rtb_Square_j = -3.14159274F;
      }
    }

    /* Sum: '<S101>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Cos1 = rtb_DiscreteTimeIntegrator1_a - Controller_U.INS_Out.q;

    /* Saturate: '<S101>/Saturation' */
    if (rtb_Cos1 > 3.14159274F) {
      rtb_Cos1 = 3.14159274F;
    } else {
      if (rtb_Cos1 < -3.14159274F) {
        rtb_Cos1 = -3.14159274F;
      }
    }

    /* Sum: '<S101>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_m_idx_1 = rtb_Divide_m_idx_2 - Controller_U.INS_Out.r;

    /* Saturate: '<S101>/Saturation' */
    if (rtb_Divide_m_idx_1 > 3.14159274F) {
      rtb_Divide_m_idx_1 = 3.14159274F;
    } else {
      if (rtb_Divide_m_idx_1 < -3.14159274F) {
        rtb_Divide_m_idx_1 = -3.14159274F;
      }
    }

    /* DiscreteIntegrator: '<S105>/Discrete-Time Integrator5' incorporates:
     *  Saturate: '<S101>/Saturation'
     */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_L_ck != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0] = rtb_Square_j;
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1] = rtb_Cos1;
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2] = rtb_Divide_m_idx_1;
    }

    /* DiscreteIntegrator: '<S110>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S105>/Discrete-Time Integrator5'
     *  Inport: '<Root>/FMS_Out'
     */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_j != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[0] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0];
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[1] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1];
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[2] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2];
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_k != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[0] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0];
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[1] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1];
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[2] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2];
    }

    /* Gain: '<S110>/Gain' incorporates:
     *  DiscreteIntegrator: '<S105>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S110>/Discrete-Time Integrator1'
     *  Sum: '<S110>/Sum5'
     */
    rtb_Add2_h = (Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0] -
                  Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[0]) * 188.49556F;
    rtb_Gain_ow = (Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1] -
                   Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[1]) *
      188.49556F;
    rtb_thor = (Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2] -
                Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[2]) * 188.49556F;

    /* Switch: '<S110>/Switch' incorporates:
     *  Gain: '<S110>/Gain1'
     *  Inport: '<Root>/FMS_Out'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_Sum5_lp = 0.0F;
      rtb_Add_o_idx_1 = 0.0F;
      rtb_Add_o_idx_2 = 0.0F;
    } else {
      rtb_Sum5_lp = rtb_Add2_h;
      rtb_Add_o_idx_1 = rtb_Gain_ow;
      rtb_Add_o_idx_2 = rtb_thor;
    }

    /* End of Switch: '<S110>/Switch' */

    /* Product: '<S107>/Multiply' incorporates:
     *  Constant: '<S107>/gain1'
     */
    rtb_Add3_e = CONTROL_PARAM.MC_ROLL_RATE_D * rtb_Sum5_lp;

    /* Saturate: '<S107>/Saturation' */
    if (rtb_Add3_e > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Add3_e = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Add3_e < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Add3_e = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    /* Product: '<S107>/Multiply' incorporates:
     *  Constant: '<S107>/gain2'
     */
    rtb_Sum5_lp = rtb_Add3_e;
    rtb_Add3_e = CONTROL_PARAM.MC_PITCH_RATE_D * rtb_Add_o_idx_1;

    /* Saturate: '<S107>/Saturation' */
    if (rtb_Add3_e > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Add3_e = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Add3_e < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Add3_e = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    /* Product: '<S107>/Multiply' incorporates:
     *  Constant: '<S107>/gain3'
     */
    rtb_Add_o_idx_1 = rtb_Add3_e;
    rtb_Add3_e = CONTROL_PARAM.MC_YAW_RATE_D * rtb_Add_o_idx_2;

    /* Saturate: '<S107>/Saturation' */
    if (rtb_Add3_e > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Add3_e = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Add3_e < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Add3_e = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    /* Sum: '<S103>/Add' incorporates:
     *  Constant: '<S109>/gain1'
     *  Constant: '<S109>/gain2'
     *  Constant: '<S109>/gain3'
     *  DiscreteIntegrator: '<S105>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S108>/Discrete-Time Integrator'
     *  Product: '<S109>/Multiply'
     */
    Controller_B.Multiply[0] = (CONTROL_PARAM.MC_ROLL_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0]) + rtb_Sum5_lp;
    Controller_B.Multiply[1] = (CONTROL_PARAM.MC_PITCH_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1]) + rtb_Add_o_idx_1;
    Controller_B.Multiply[2] = (CONTROL_PARAM.MC_YAW_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[2]) + rtb_Add3_e;

    /* DeadZone: '<S106>/Dead Zone' */
    if (rtb_Integrator1_m > 0.1F) {
      rtb_Integrator1_m -= 0.1F;
    } else if (rtb_Integrator1_m >= -0.1F) {
      rtb_Integrator1_m = 0.0F;
    } else {
      rtb_Integrator1_m -= -0.1F;
    }

    /* Sum: '<S94>/Sum' incorporates:
     *  Gain: '<S102>/Gain'
     *  Gain: '<S106>/Gain'
     */
    Controller_B.Multiply[0] += 1.11111116F * rtb_Integrator1_m *
      CONTROL_PARAM.MC_ROLL_RATE_FF;

    /* Product: '<S5>/Multiply' incorporates:
     *  DiscreteIntegrator: '<S152>/Discrete-Time Integrator5'
     */
    Controller_B.Multiply[0] *= Controller_DW.DiscreteTimeIntegrator5_DSTAT_i;

    /* DeadZone: '<S106>/Dead Zone' */
    if (rtb_DiscreteTimeIntegrator1_a > 0.1F) {
      rtb_DiscreteTimeIntegrator1_a -= 0.1F;
    } else if (rtb_DiscreteTimeIntegrator1_a >= -0.1F) {
      rtb_DiscreteTimeIntegrator1_a = 0.0F;
    } else {
      rtb_DiscreteTimeIntegrator1_a -= -0.1F;
    }

    /* Sum: '<S94>/Sum' incorporates:
     *  Gain: '<S102>/Gain'
     *  Gain: '<S106>/Gain'
     */
    Controller_B.Multiply[1] += 1.11111116F * rtb_DiscreteTimeIntegrator1_a *
      CONTROL_PARAM.MC_ROLL_RATE_FF;

    /* Product: '<S5>/Multiply' incorporates:
     *  DiscreteIntegrator: '<S152>/Discrete-Time Integrator5'
     */
    Controller_B.Multiply[1] *= Controller_DW.DiscreteTimeIntegrator5_DSTAT_i;

    /* DeadZone: '<S106>/Dead Zone' */
    if (rtb_Divide_m_idx_2 > 0.1F) {
      rtb_Divide_m_idx_2 -= 0.1F;
    } else if (rtb_Divide_m_idx_2 >= -0.1F) {
      rtb_Divide_m_idx_2 = 0.0F;
    } else {
      rtb_Divide_m_idx_2 -= -0.1F;
    }

    /* Sum: '<S94>/Sum' incorporates:
     *  Gain: '<S102>/Gain1'
     *  Gain: '<S106>/Gain'
     */
    Controller_B.Multiply[2] += 1.11111116F * rtb_Divide_m_idx_2 *
      CONTROL_PARAM.MC_PITCH_RATE_FF;

    /* Product: '<S5>/Multiply' incorporates:
     *  DiscreteIntegrator: '<S152>/Discrete-Time Integrator5'
     */
    Controller_B.Multiply[2] *= Controller_DW.DiscreteTimeIntegrator5_DSTAT_i;

    /* Product: '<S130>/Multiply1' incorporates:
     *  Constant: '<S130>/const1'
     *  DiscreteIntegrator: '<S127>/Integrator'
     */
    rtb_Divide_m_idx_2 = Controller_DW.Integrator_DSTATE[0] * 0.05F;
    rtb_Add_o_idx_2 = Controller_DW.Integrator_DSTATE[1] * 0.05F;

    /* Sum: '<S130>/Add' incorporates:
     *  DiscreteIntegrator: '<S127>/Integrator1'
     *  Inport: '<Root>/FMS_Out'
     *  Sum: '<S127>/Subtract'
     */
    rtb_Integrator1_m = (Controller_DW.Integrator1_DSTATE[0] -
                         Controller_U.FMS_Out.u_cmd) + rtb_Divide_m_idx_2;
    rtb_Sum5_lp = (Controller_DW.Integrator1_DSTATE[1] -
                   Controller_U.FMS_Out.v_cmd) + rtb_Add_o_idx_2;

    /* Signum: '<S130>/Sign' */
    if (rtb_Integrator1_m < 0.0F) {
      rtb_DiscreteTimeIntegrator1_a = -1.0F;
    } else if (rtb_Integrator1_m > 0.0F) {
      rtb_DiscreteTimeIntegrator1_a = 1.0F;
    } else {
      rtb_DiscreteTimeIntegrator1_a = rtb_Integrator1_m;
    }

    /* Sum: '<S130>/Add2' incorporates:
     *  Abs: '<S130>/Abs'
     *  Gain: '<S130>/Gain'
     *  Gain: '<S130>/Gain1'
     *  Product: '<S130>/Multiply2'
     *  Product: '<S130>/Multiply3'
     *  Signum: '<S130>/Sign'
     *  Sqrt: '<S130>/Sqrt'
     *  Sum: '<S130>/Add1'
     *  Sum: '<S130>/Subtract'
     */
    rtb_DiscreteTimeIntegrator1_a = (sqrtf((8.0F * fabsf(rtb_Integrator1_m) +
      Controller_ConstB.d) * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
      rtb_DiscreteTimeIntegrator1_a + rtb_Divide_m_idx_2;

    /* Sum: '<S130>/Add3' incorporates:
     *  Signum: '<S130>/Sign'
     */
    rtb_Add3_e = rtb_Integrator1_m + Controller_ConstB.d;

    /* Sum: '<S130>/Subtract1' incorporates:
     *  Signum: '<S130>/Sign'
     */
    rtb_Add_o_idx_1 = rtb_Integrator1_m - Controller_ConstB.d;

    /* Signum: '<S130>/Sign1' */
    if (rtb_Add3_e < 0.0F) {
      rtb_Add3_e = -1.0F;
    } else {
      if (rtb_Add3_e > 0.0F) {
        rtb_Add3_e = 1.0F;
      }
    }

    /* Signum: '<S130>/Sign2' */
    if (rtb_Add_o_idx_1 < 0.0F) {
      rtb_Add_o_idx_1 = -1.0F;
    } else {
      if (rtb_Add_o_idx_1 > 0.0F) {
        rtb_Add_o_idx_1 = 1.0F;
      }
    }

    /* Sum: '<S130>/Add2' incorporates:
     *  Gain: '<S130>/Gain2'
     *  Product: '<S130>/Multiply4'
     *  Signum: '<S130>/Sign'
     *  Sum: '<S130>/Add4'
     *  Sum: '<S130>/Add5'
     *  Sum: '<S130>/Subtract2'
     */
    rtb_Integrator1_m = ((rtb_Integrator1_m - rtb_DiscreteTimeIntegrator1_a) +
                         rtb_Divide_m_idx_2) * ((rtb_Add3_e - rtb_Add_o_idx_1) *
      0.5F) + rtb_DiscreteTimeIntegrator1_a;

    /* Signum: '<S130>/Sign' */
    if (rtb_Sum5_lp < 0.0F) {
      rtb_Divide_m_idx_2 = -1.0F;
    } else if (rtb_Sum5_lp > 0.0F) {
      rtb_Divide_m_idx_2 = 1.0F;
    } else {
      rtb_Divide_m_idx_2 = rtb_Sum5_lp;
    }

    /* Sum: '<S130>/Add2' incorporates:
     *  Abs: '<S130>/Abs'
     *  Gain: '<S130>/Gain'
     *  Gain: '<S130>/Gain1'
     *  Product: '<S130>/Multiply2'
     *  Product: '<S130>/Multiply3'
     *  Signum: '<S130>/Sign'
     *  Sqrt: '<S130>/Sqrt'
     *  Sum: '<S130>/Add1'
     *  Sum: '<S130>/Subtract'
     */
    rtb_DiscreteTimeIntegrator1_a = (sqrtf((8.0F * fabsf(rtb_Sum5_lp) +
      Controller_ConstB.d) * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
      rtb_Divide_m_idx_2 + rtb_Add_o_idx_2;

    /* Sum: '<S130>/Add3' incorporates:
     *  Signum: '<S130>/Sign'
     */
    rtb_Add3_e = rtb_Sum5_lp + Controller_ConstB.d;

    /* Sum: '<S130>/Subtract1' incorporates:
     *  Signum: '<S130>/Sign'
     */
    rtb_Add_o_idx_1 = rtb_Sum5_lp - Controller_ConstB.d;

    /* Signum: '<S130>/Sign1' */
    if (rtb_Add3_e < 0.0F) {
      rtb_Add3_e = -1.0F;
    } else {
      if (rtb_Add3_e > 0.0F) {
        rtb_Add3_e = 1.0F;
      }
    }

    /* Signum: '<S130>/Sign2' */
    if (rtb_Add_o_idx_1 < 0.0F) {
      rtb_Add_o_idx_1 = -1.0F;
    } else {
      if (rtb_Add_o_idx_1 > 0.0F) {
        rtb_Add_o_idx_1 = 1.0F;
      }
    }

    /* Sum: '<S130>/Add5' incorporates:
     *  Gain: '<S130>/Gain2'
     *  Product: '<S130>/Multiply4'
     *  Signum: '<S130>/Sign'
     *  Sum: '<S130>/Add2'
     *  Sum: '<S130>/Add4'
     *  Sum: '<S130>/Subtract2'
     */
    rtb_DiscreteTimeIntegrator1_a += ((rtb_Sum5_lp -
      rtb_DiscreteTimeIntegrator1_a) + rtb_Add_o_idx_2) * ((rtb_Add3_e -
      rtb_Add_o_idx_1) * 0.5F);

    /* Gain: '<S143>/Gain' incorporates:
     *  DiscreteIntegrator: '<S145>/Integrator1'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S143>/Sum1'
     */
    rtb_Add_o_idx_1 = -(Controller_DW.Integrator1_DSTATE_e -
                        Controller_U.INS_Out.vd);

    /* Constant: '<S148>/Constant' */
    Controller_B.Constant = CONTROL_PARAM.MC_VEL_Z_I_MIN;

    /* DiscreteIntegrator: '<S148>/Discrete-Time Integrator' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator_PrevRe_f != 0)) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_l = Controller_B.Constant;
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_l >=
          CONTROL_PARAM.MC_VEL_Z_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_l =
          CONTROL_PARAM.MC_VEL_Z_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_l <=
            CONTROL_PARAM.MC_VEL_Z_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_l =
            CONTROL_PARAM.MC_VEL_Z_I_MIN;
        }
      }
    }

    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_l >=
        CONTROL_PARAM.MC_VEL_Z_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_l =
        CONTROL_PARAM.MC_VEL_Z_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_l <=
          CONTROL_PARAM.MC_VEL_Z_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_l =
          CONTROL_PARAM.MC_VEL_Z_I_MIN;
      }
    }

    /* DiscreteIntegrator: '<S150>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_d != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i = rtb_Add_o_idx_1;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_Prev_ks != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i = rtb_Add_o_idx_1;
    }

    /* Gain: '<S150>/Gain' incorporates:
     *  DiscreteIntegrator: '<S150>/Discrete-Time Integrator1'
     *  Sum: '<S150>/Sum5'
     */
    rtb_Add_o_idx_2 = (rtb_Add_o_idx_1 -
                       Controller_DW.DiscreteTimeIntegrator1_DSTAT_i) *
      62.831852F;

    /* Switch: '<S139>/Switch' incorporates:
     *  Bias: '<S139>/Bias'
     *  Constant: '<S141>/Constant'
     *  Gain: '<S139>/Gain'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S141>/Compare'
     */
    if (Controller_U.FMS_Out.ctrl_mode <= 3) {
      rtb_Divide_m_idx_2 = 0.000999987125F * (real32_T)
        Controller_U.FMS_Out.throttle_cmd + -1.0F;
    } else {
      /* Product: '<S142>/Multiply' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S142>/Cos'
       *  Trigonometry: '<S142>/Cos1'
       */
      rtb_Add3_e = arm_cos_f32(Controller_U.INS_Out.phi) * arm_cos_f32
        (Controller_U.INS_Out.theta);

      /* Gain: '<S142>/Gain' */
      rtb_Sum5_lp = 2.0F * rtb_Add3_e;

      /* Saturate: '<S142>/Saturation1' */
      if (rtb_Add3_e > 1.0F) {
        rtb_Add3_e = 1.0F;
      } else {
        if (rtb_Add3_e < 0.5F) {
          rtb_Add3_e = 0.5F;
        }
      }

      /* End of Saturate: '<S142>/Saturation1' */

      /* Product: '<S142>/Divide' incorporates:
       *  Constant: '<S142>/Constant'
       */
      rtb_Divide_m_idx_2 = 1.0F / rtb_Add3_e;

      /* Switch: '<S150>/Switch' incorporates:
       *  Gain: '<S150>/Gain1'
       */
      if (Controller_U.FMS_Out.reset > 0) {
        rtb_Add3_e = 0.0F;
      } else {
        rtb_Add3_e = rtb_Add_o_idx_2;
      }

      /* End of Switch: '<S150>/Switch' */

      /* Product: '<S147>/Multiply' incorporates:
       *  Constant: '<S147>/kd'
       */
      rtb_Add3_e *= CONTROL_PARAM.MC_VEL_Z_D;

      /* Saturate: '<S147>/Saturation' */
      if (rtb_Add3_e > CONTROL_PARAM.MC_VEL_Z_D_MAX) {
        rtb_Add3_e = CONTROL_PARAM.MC_VEL_Z_D_MAX;
      } else {
        if (rtb_Add3_e < CONTROL_PARAM.MC_VEL_Z_D_MIN) {
          rtb_Add3_e = CONTROL_PARAM.MC_VEL_Z_D_MIN;
        }
      }

      /* End of Saturate: '<S147>/Saturation' */

      /* Saturate: '<S142>/Saturation' */
      if (rtb_Sum5_lp > 1.0F) {
        rtb_Sum5_lp = 1.0F;
      } else {
        if (rtb_Sum5_lp < 0.0F) {
          rtb_Sum5_lp = 0.0F;
        }
      }

      /* End of Saturate: '<S142>/Saturation' */

      /* Sum: '<S140>/Sum' incorporates:
       *  Constant: '<S140>/hover_throttle'
       *  Constant: '<S149>/kp'
       *  DiscreteIntegrator: '<S148>/Discrete-Time Integrator'
       *  Product: '<S142>/Multiply1'
       *  Product: '<S149>/Multiply'
       *  Sum: '<S144>/Add'
       */
      rtb_Divide_m_idx_2 = ((CONTROL_PARAM.MC_VEL_Z_P * rtb_Add_o_idx_1 +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_l) + rtb_Add3_e) *
        rtb_Divide_m_idx_2 * rtb_Sum5_lp + CONTROL_PARAM.MC_HOVER_THRO;

      /* Saturate: '<S140>/Saturation' */
      if (rtb_Divide_m_idx_2 > 0.85F) {
        rtb_Divide_m_idx_2 = 0.85F;
      } else {
        if (rtb_Divide_m_idx_2 < 0.25F) {
          rtb_Divide_m_idx_2 = 0.25F;
        }
      }

      /* End of Saturate: '<S140>/Saturation' */
    }

    /* End of Switch: '<S139>/Switch' */

    /* Product: '<S5>/Multiply1' incorporates:
     *  Constant: '<S139>/Constant'
     *  DiscreteIntegrator: '<S152>/Discrete-Time Integrator5'
     */
    Controller_B.Multiply1[0] = 0.0F;
    Controller_B.Multiply1[1] = 0.0F;
    Controller_B.Multiply1[2] = Controller_DW.DiscreteTimeIntegrator5_DSTAT_i *
      rtb_Divide_m_idx_2;

    /* Product: '<S146>/Multiply1' incorporates:
     *  Constant: '<S146>/const1'
     *  DiscreteIntegrator: '<S145>/Integrator'
     */
    rtb_Add3_e = Controller_DW.Integrator_DSTATE_j * 0.05F;

    /* Sum: '<S146>/Add' incorporates:
     *  DiscreteIntegrator: '<S145>/Integrator1'
     *  Inport: '<Root>/FMS_Out'
     *  Sum: '<S145>/Subtract'
     */
    rtb_Divide_m_idx_2 = (Controller_DW.Integrator1_DSTATE_e -
                          Controller_U.FMS_Out.w_cmd) + rtb_Add3_e;

    /* Signum: '<S146>/Sign' */
    if (rtb_Divide_m_idx_2 < 0.0F) {
      rtb_Sum5_lp = -1.0F;
    } else if (rtb_Divide_m_idx_2 > 0.0F) {
      rtb_Sum5_lp = 1.0F;
    } else {
      rtb_Sum5_lp = rtb_Divide_m_idx_2;
    }

    /* End of Signum: '<S146>/Sign' */

    /* Sum: '<S146>/Add2' incorporates:
     *  Abs: '<S146>/Abs'
     *  Gain: '<S146>/Gain'
     *  Gain: '<S146>/Gain1'
     *  Product: '<S146>/Multiply2'
     *  Product: '<S146>/Multiply3'
     *  Sqrt: '<S146>/Sqrt'
     *  Sum: '<S146>/Add1'
     *  Sum: '<S146>/Subtract'
     */
    rtb_Sum5_lp = (sqrtf((8.0F * fabsf(rtb_Divide_m_idx_2) +
                          Controller_ConstB.d_i) * Controller_ConstB.d_i) -
                   Controller_ConstB.d_i) * 0.5F * rtb_Sum5_lp + rtb_Add3_e;

    /* Sum: '<S146>/Add4' */
    rtb_Add4_l = (rtb_Divide_m_idx_2 - rtb_Sum5_lp) + rtb_Add3_e;

    /* Sum: '<S146>/Add3' */
    rtb_Add3_e = rtb_Divide_m_idx_2 + Controller_ConstB.d_i;

    /* Sum: '<S146>/Subtract1' */
    rtb_Divide_m_idx_2 -= Controller_ConstB.d_i;

    /* Signum: '<S146>/Sign1' */
    if (rtb_Add3_e < 0.0F) {
      rtb_Add3_e = -1.0F;
    } else {
      if (rtb_Add3_e > 0.0F) {
        rtb_Add3_e = 1.0F;
      }
    }

    /* End of Signum: '<S146>/Sign1' */

    /* Signum: '<S146>/Sign2' */
    if (rtb_Divide_m_idx_2 < 0.0F) {
      rtb_Divide_m_idx_2 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_2 > 0.0F) {
        rtb_Divide_m_idx_2 = 1.0F;
      }
    }

    /* End of Signum: '<S146>/Sign2' */

    /* Sum: '<S146>/Add5' incorporates:
     *  Gain: '<S146>/Gain2'
     *  Product: '<S146>/Multiply4'
     *  Sum: '<S146>/Subtract2'
     */
    rtb_Sum5_lp += (rtb_Add3_e - rtb_Divide_m_idx_2) * 0.5F * rtb_Add4_l;

    /* Update for DiscreteIntegrator: '<S108>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S108>/gain1'
     *  Constant: '<S108>/gain2'
     *  Constant: '<S108>/gain3'
     *  DiscreteIntegrator: '<S105>/Discrete-Time Integrator5'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S108>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] +=
      CONTROL_PARAM.MC_ROLL_RATE_I *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0] * 0.002F;
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

    Controller_DW.DiscreteTimeIntegrator_DSTATE[1] +=
      CONTROL_PARAM.MC_PITCH_RATE_I *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1] * 0.002F;
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

    Controller_DW.DiscreteTimeIntegrator_DSTATE[2] +=
      CONTROL_PARAM.MC_YAW_RATE_I *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2] * 0.002F;
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

    Controller_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* End of Update for DiscreteIntegrator: '<S108>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S132>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_PrevRe_p = (int8_T)rtb_Compare_b;

    /* Update for DiscreteIntegrator: '<S134>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;

    /* Update for DiscreteIntegrator: '<S127>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S127>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE[0] += 0.002F *
      Controller_DW.Integrator_DSTATE[0];

    /* Update for DiscreteIntegrator: '<S132>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S132>/ki'
     *  Product: '<S132>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0] +=
      CONTROL_PARAM.MC_VEL_XY_I * rtb_Divide_m_idx_3 * 0.002F;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0] >=
        CONTROL_PARAM.MC_VEL_XY_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0] =
        CONTROL_PARAM.MC_VEL_XY_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0] <=
          CONTROL_PARAM.MC_VEL_XY_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0] =
          CONTROL_PARAM.MC_VEL_XY_I_MIN;
      }
    }

    /* Update for DiscreteIntegrator: '<S134>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] += 0.002F * rtb_Gain_c4;

    /* Update for DiscreteIntegrator: '<S127>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S127>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE[1] += 0.002F *
      Controller_DW.Integrator_DSTATE[1];

    /* Update for DiscreteIntegrator: '<S132>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S132>/ki'
     *  Product: '<S132>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1] +=
      CONTROL_PARAM.MC_VEL_XY_I * rtb_Ldot_err * 0.002F;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1] >=
        CONTROL_PARAM.MC_VEL_XY_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1] =
        CONTROL_PARAM.MC_VEL_XY_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1] <=
          CONTROL_PARAM.MC_VEL_XY_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1] =
          CONTROL_PARAM.MC_VEL_XY_I_MIN;
      }
    }

    /* Update for DiscreteIntegrator: '<S134>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] += 0.002F * rtb_Add1_j4;
    Controller_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)rtb_Compare_b;

    /* Update for DiscreteIntegrator: '<S105>/Discrete-Time Integrator5' */
    Controller_DW.DiscreteTimeIntegrator5_IC_L_ck = 0U;

    /* Update for DiscreteIntegrator: '<S110>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 0U;

    /* Update for DiscreteIntegrator: '<S105>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S105>/Gain'
     *  Saturate: '<S101>/Saturation'
     *  Sum: '<S105>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0] += (rtb_Square_j -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S110>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[0] += 0.002F * rtb_Add2_h;

    /* Update for DiscreteIntegrator: '<S105>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S105>/Gain'
     *  Saturate: '<S101>/Saturation'
     *  Sum: '<S105>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1] += (rtb_Cos1 -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S110>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[1] += 0.002F * rtb_Gain_ow;

    /* Update for DiscreteIntegrator: '<S105>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S105>/Gain'
     *  Saturate: '<S101>/Saturation'
     *  Sum: '<S105>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2] += (rtb_Divide_m_idx_1 -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S110>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[2] += 0.002F * rtb_thor;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_k = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Signum: '<S130>/Sign3' incorporates:
     *  Product: '<S130>/Divide'
     *  Sum: '<S130>/Add6'
     */
    rtb_Add3_e = rtb_Integrator1_m + Controller_ConstB.d;

    /* Signum: '<S130>/Sign4' incorporates:
     *  Product: '<S130>/Divide'
     *  Sum: '<S130>/Subtract3'
     */
    rtb_Square_j = rtb_Integrator1_m - Controller_ConstB.d;

    /* Signum: '<S130>/Sign5' incorporates:
     *  Product: '<S130>/Divide'
     */
    if (rtb_Integrator1_m < 0.0F) {
      rtb_Cos1 = -1.0F;
    } else if (rtb_Integrator1_m > 0.0F) {
      rtb_Cos1 = 1.0F;
    } else {
      rtb_Cos1 = rtb_Integrator1_m;
    }

    /* Signum: '<S130>/Sign3' */
    if (rtb_Add3_e < 0.0F) {
      rtb_Add3_e = -1.0F;
    } else {
      if (rtb_Add3_e > 0.0F) {
        rtb_Add3_e = 1.0F;
      }
    }

    /* Signum: '<S130>/Sign4' */
    if (rtb_Square_j < 0.0F) {
      rtb_Square_j = -1.0F;
    } else {
      if (rtb_Square_j > 0.0F) {
        rtb_Square_j = 1.0F;
      }
    }

    /* Signum: '<S130>/Sign6' incorporates:
     *  Product: '<S130>/Divide'
     */
    if (rtb_Integrator1_m < 0.0F) {
      rtb_Divide_m_idx_1 = -1.0F;
    } else if (rtb_Integrator1_m > 0.0F) {
      rtb_Divide_m_idx_1 = 1.0F;
    } else {
      rtb_Divide_m_idx_1 = rtb_Integrator1_m;
    }

    /* Update for DiscreteIntegrator: '<S127>/Integrator' incorporates:
     *  Constant: '<S130>/const'
     *  Gain: '<S130>/Gain3'
     *  Product: '<S130>/Divide'
     *  Product: '<S130>/Multiply5'
     *  Product: '<S130>/Multiply6'
     *  Sum: '<S130>/Subtract4'
     *  Sum: '<S130>/Subtract5'
     *  Sum: '<S130>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE[0] += ((rtb_Integrator1_m /
      Controller_ConstB.d - rtb_Cos1) * Controller_ConstB.Gain4 * ((rtb_Add3_e -
      rtb_Square_j) * 0.5F) - rtb_Divide_m_idx_1 * 58.836F) * 0.002F;

    /* Signum: '<S130>/Sign3' incorporates:
     *  Sum: '<S130>/Add6'
     */
    rtb_Add3_e = rtb_DiscreteTimeIntegrator1_a + Controller_ConstB.d;

    /* Signum: '<S130>/Sign4' incorporates:
     *  Sum: '<S130>/Subtract3'
     */
    rtb_Square_j = rtb_DiscreteTimeIntegrator1_a - Controller_ConstB.d;

    /* Signum: '<S130>/Sign5' */
    if (rtb_DiscreteTimeIntegrator1_a < 0.0F) {
      rtb_Cos1 = -1.0F;
    } else if (rtb_DiscreteTimeIntegrator1_a > 0.0F) {
      rtb_Cos1 = 1.0F;
    } else {
      rtb_Cos1 = rtb_DiscreteTimeIntegrator1_a;
    }

    /* Signum: '<S130>/Sign3' */
    if (rtb_Add3_e < 0.0F) {
      rtb_Add3_e = -1.0F;
    } else {
      if (rtb_Add3_e > 0.0F) {
        rtb_Add3_e = 1.0F;
      }
    }

    /* Signum: '<S130>/Sign4' */
    if (rtb_Square_j < 0.0F) {
      rtb_Square_j = -1.0F;
    } else {
      if (rtb_Square_j > 0.0F) {
        rtb_Square_j = 1.0F;
      }
    }

    /* Signum: '<S130>/Sign6' */
    if (rtb_DiscreteTimeIntegrator1_a < 0.0F) {
      rtb_Divide_m_idx_1 = -1.0F;
    } else if (rtb_DiscreteTimeIntegrator1_a > 0.0F) {
      rtb_Divide_m_idx_1 = 1.0F;
    } else {
      rtb_Divide_m_idx_1 = rtb_DiscreteTimeIntegrator1_a;
    }

    /* Update for DiscreteIntegrator: '<S127>/Integrator' incorporates:
     *  Constant: '<S130>/const'
     *  Gain: '<S130>/Gain3'
     *  Product: '<S130>/Divide'
     *  Product: '<S130>/Multiply5'
     *  Product: '<S130>/Multiply6'
     *  Sum: '<S130>/Subtract4'
     *  Sum: '<S130>/Subtract5'
     *  Sum: '<S130>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE[1] += ((rtb_DiscreteTimeIntegrator1_a /
      Controller_ConstB.d - rtb_Cos1) * Controller_ConstB.Gain4 * ((rtb_Add3_e -
      rtb_Square_j) * 0.5F) - rtb_Divide_m_idx_1 * 58.836F) * 0.002F;

    /* Update for DiscreteIntegrator: '<S145>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S145>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_e += 0.002F *
      Controller_DW.Integrator_DSTATE_j;

    /* Update for DiscreteIntegrator: '<S148>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S148>/ki'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S148>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_l += CONTROL_PARAM.MC_VEL_Z_I *
      rtb_Add_o_idx_1 * 0.002F;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_l >=
        CONTROL_PARAM.MC_VEL_Z_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_l =
        CONTROL_PARAM.MC_VEL_Z_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_l <=
          CONTROL_PARAM.MC_VEL_Z_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_l =
          CONTROL_PARAM.MC_VEL_Z_I_MIN;
      }
    }

    Controller_DW.DiscreteTimeIntegrator_PrevRe_f = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* End of Update for DiscreteIntegrator: '<S148>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S150>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_i += 0.002F * rtb_Add_o_idx_2;
    Controller_DW.DiscreteTimeIntegrator1_Prev_ks = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Signum: '<S146>/Sign6' incorporates:
     *  Signum: '<S146>/Sign5'
     */
    if (rtb_Sum5_lp < 0.0F) {
      rtb_Cos1 = -1.0F;

      /* Signum: '<S146>/Sign5' */
      rtb_Divide_m_idx_1 = -1.0F;
    } else if (rtb_Sum5_lp > 0.0F) {
      rtb_Cos1 = 1.0F;

      /* Signum: '<S146>/Sign5' */
      rtb_Divide_m_idx_1 = 1.0F;
    } else {
      rtb_Cos1 = rtb_Sum5_lp;

      /* Signum: '<S146>/Sign5' */
      rtb_Divide_m_idx_1 = rtb_Sum5_lp;
    }

    /* End of Signum: '<S146>/Sign6' */

    /* Sum: '<S146>/Add6' */
    rtb_Add3_e = rtb_Sum5_lp + Controller_ConstB.d_i;

    /* Sum: '<S146>/Subtract3' */
    rtb_Square_j = rtb_Sum5_lp - Controller_ConstB.d_i;

    /* Signum: '<S146>/Sign3' */
    if (rtb_Add3_e < 0.0F) {
      rtb_Add3_e = -1.0F;
    } else {
      if (rtb_Add3_e > 0.0F) {
        rtb_Add3_e = 1.0F;
      }
    }

    /* End of Signum: '<S146>/Sign3' */

    /* Signum: '<S146>/Sign4' */
    if (rtb_Square_j < 0.0F) {
      rtb_Square_j = -1.0F;
    } else {
      if (rtb_Square_j > 0.0F) {
        rtb_Square_j = 1.0F;
      }
    }

    /* End of Signum: '<S146>/Sign4' */

    /* Update for DiscreteIntegrator: '<S145>/Integrator' incorporates:
     *  Constant: '<S146>/const'
     *  Gain: '<S146>/Gain3'
     *  Product: '<S146>/Divide'
     *  Product: '<S146>/Multiply5'
     *  Product: '<S146>/Multiply6'
     *  Sum: '<S146>/Subtract4'
     *  Sum: '<S146>/Subtract5'
     *  Sum: '<S146>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE_j += ((rtb_Sum5_lp / Controller_ConstB.d_i -
      rtb_Divide_m_idx_1) * Controller_ConstB.Gain4_p * ((rtb_Add3_e -
      rtb_Square_j) * 0.5F) - rtb_Cos1 * 78.448F) * 0.002F;
  } else {
    if (Controller_DW.MC_Controller_MODE) {
      Controller_DW.MC_Controller_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S2>/MC_Controller' */

  /* Product: '<S2>/Multiply2' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion1'
   */
  rtb_Multiply2[0] = (real32_T)rtb_Compare * Controller_B.Multiply[0];

  /* Product: '<S2>/Multiply3' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion1'
   */
  rtb_Multiply3[0] = (real32_T)rtb_Compare * Controller_B.Multiply1[0];

  /* Product: '<S2>/Multiply' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   */
  rtb_Multiply[0] = (real32_T)rtb_Compare_m * Controller_B.Multiply_c[0];

  /* Product: '<S2>/Multiply1' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   */
  rtb_Multiply1[0] = (real32_T)rtb_Compare_m * Controller_B.Switch[3];

  /* Product: '<S2>/Multiply2' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion1'
   */
  rtb_Multiply2[1] = (real32_T)rtb_Compare * Controller_B.Multiply[1];

  /* Product: '<S2>/Multiply3' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion1'
   */
  rtb_Multiply3[1] = (real32_T)rtb_Compare * Controller_B.Multiply1[1];

  /* Product: '<S2>/Multiply' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   */
  rtb_Multiply[1] = (real32_T)rtb_Compare_m * Controller_B.Multiply_c[1];

  /* Product: '<S2>/Multiply1' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   */
  rtb_Multiply1[1] = (real32_T)rtb_Compare_m * Controller_B.Switch[4];

  /* Product: '<S2>/Multiply2' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion1'
   */
  rtb_Multiply2[2] = (real32_T)rtb_Compare * Controller_B.Multiply[2];

  /* Product: '<S2>/Multiply3' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion1'
   */
  rtb_Multiply3[2] = (real32_T)rtb_Compare * Controller_B.Multiply1[2];

  /* Product: '<S2>/Multiply' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   */
  rtb_Multiply[2] = (real32_T)rtb_Compare_m * Controller_B.Multiply_c[2];

  /* Product: '<S2>/Multiply1' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   */
  rtb_Multiply1[2] = (real32_T)rtb_Compare_m * Controller_B.Switch[5];

  /* Outputs for Atomic SubSystem: '<S9>/VTOL_Control_Allocation' */
#if AIRFRAME == 1

  /* Output and update for atomic system: '<S165>/VTOL1' */
  {
    real32_T rtb_Saturation3_j;
    real32_T rtb_MatrixConcatenate[12];
    real32_T rtb_Saturation5_o[4];
    real32_T rtb_floating_yaw[4];
    real32_T rtb_Subtract_h;
    real32_T rtb_Saturation_fa[9];
    real32_T rtb_Sum_e[4];
    real32_T rtb_Gain1_l;
    int32_T i_p;
    real32_T rtb_Switch_gr_idx_0_p;
    real32_T rtb_Switch_gr_idx_1_p;
    real32_T rtb_Saturation1_l_idx_0_p;
    real32_T rtb_Saturation1_l_idx_1_p;
    real32_T rtb_Saturation1_l_idx_2_p;
    uint16_T u0_p;

    /* Saturate: '<S182>/Saturation' incorporates:
     *  Bias: '<S182>/Bias'
     *  Bias: '<S182>/Bias1'
     *  Bias: '<S182>/Bias2'
     *  Bias: '<S182>/Bias3'
     *  Constant: '<S182>/Constant'
     */
    for (i_p = 0; i_p < 5; i_p++) {
      rtb_Saturation_fa[i_p] = 1000.0F;
    }

    if (1500.0F + CONTROL_PARAM.SERVO1_BIAS > 2000.0F) {
      rtb_Saturation_fa[5] = 2000.0F;
    } else if (1500.0F + CONTROL_PARAM.SERVO1_BIAS < 1000.0F) {
      rtb_Saturation_fa[5] = 1000.0F;
    } else {
      rtb_Saturation_fa[5] = 1500.0F + CONTROL_PARAM.SERVO1_BIAS;
    }

    if (1500.0F + CONTROL_PARAM.SERVO2_BIAS > 2000.0F) {
      rtb_Saturation_fa[6] = 2000.0F;
    } else if (1500.0F + CONTROL_PARAM.SERVO2_BIAS < 1000.0F) {
      rtb_Saturation_fa[6] = 1000.0F;
    } else {
      rtb_Saturation_fa[6] = 1500.0F + CONTROL_PARAM.SERVO2_BIAS;
    }

    if (1500.0F + CONTROL_PARAM.SERVO3_BIAS > 2000.0F) {
      rtb_Saturation_fa[7] = 2000.0F;
    } else if (1500.0F + CONTROL_PARAM.SERVO3_BIAS < 1000.0F) {
      rtb_Saturation_fa[7] = 1000.0F;
    } else {
      rtb_Saturation_fa[7] = 1500.0F + CONTROL_PARAM.SERVO3_BIAS;
    }

    if (1500.0F + CONTROL_PARAM.SERVO4_BIAS > 2000.0F) {
      rtb_Saturation_fa[8] = 2000.0F;
    } else if (1500.0F + CONTROL_PARAM.SERVO4_BIAS < 1000.0F) {
      rtb_Saturation_fa[8] = 1000.0F;
    } else {
      rtb_Saturation_fa[8] = 1500.0F + CONTROL_PARAM.SERVO4_BIAS;
    }

    /* End of Saturate: '<S182>/Saturation' */

    /* Saturate: '<S169>/Saturation1' */
    if (rtb_Multiply2[0] > 1.0F) {
      rtb_Saturation1_l_idx_0_p = 1.0F;
    } else if (rtb_Multiply2[0] < -1.0F) {
      rtb_Saturation1_l_idx_0_p = -1.0F;
    } else {
      rtb_Saturation1_l_idx_0_p = rtb_Multiply2[0];
    }

    if (rtb_Multiply2[1] > 1.0F) {
      rtb_Saturation1_l_idx_1_p = 1.0F;
    } else if (rtb_Multiply2[1] < -1.0F) {
      rtb_Saturation1_l_idx_1_p = -1.0F;
    } else {
      rtb_Saturation1_l_idx_1_p = rtb_Multiply2[1];
    }

    if (rtb_Multiply2[2] > 1.0F) {
      rtb_Saturation1_l_idx_2_p = 1.0F;
    } else if (rtb_Multiply2[2] < -1.0F) {
      rtb_Saturation1_l_idx_2_p = -1.0F;
    } else {
      rtb_Saturation1_l_idx_2_p = rtb_Multiply2[2];
    }

    /* End of Saturate: '<S169>/Saturation1' */

    /* Gain: '<S169>/Gain1' incorporates:
     *  Bias: '<S169>/Bias'
     *  Constant: '<S169>/Constant'
     */
    rtb_Gain1_l = ((real32_T)CONTROL_PARAM.MC_OUT_MAX + -1000.0F) * 0.001F;

    /* Saturate: '<S169>/Saturation2' */
    if (rtb_Multiply3[2] > 1.0F) {
      rtb_Saturation3_j = 1.0F;
    } else if (rtb_Multiply3[2] < 0.0F) {
      rtb_Saturation3_j = 0.0F;
    } else {
      rtb_Saturation3_j = rtb_Multiply3[2];
    }

    /* End of Saturate: '<S169>/Saturation2' */
    for (i_p = 0; i_p < 4; i_p++) {
      /* Product: '<S169>/Multiply' */
      rtb_Switch_gr_idx_1_p = Controller_ConstB.VTOL1.pq_column[i_p + 4] *
        rtb_Saturation1_l_idx_1_p + Controller_ConstB.VTOL1.pq_column[i_p] *
        rtb_Saturation1_l_idx_0_p;

      /* Sum: '<S169>/Sum' */
      rtb_Sum_e[i_p] = rtb_Switch_gr_idx_1_p + rtb_Saturation3_j;

      /* Product: '<S169>/Multiply' */
      rtb_floating_yaw[i_p] = rtb_Switch_gr_idx_1_p;
    }

    /* Gain: '<S169>/Gain2' incorporates:
     *  Bias: '<S169>/Bias1'
     *  Constant: '<S169>/Constant1'
     */
    rtb_Saturation1_l_idx_0_p = ((real32_T)CONTROL_PARAM.MC_OUT_MIN + -1000.0F) *
      0.001F;

    /* MinMax: '<S169>/Max' */
    rtb_Switch_gr_idx_1_p = fmaxf(fmaxf(fmaxf(rtb_Sum_e[0], rtb_Sum_e[1]),
      rtb_Sum_e[2]), rtb_Sum_e[3]);

    /* MinMax: '<S169>/Max1' */
    rtb_Saturation1_l_idx_1_p = fminf(fminf(fminf(rtb_Sum_e[0], rtb_Sum_e[1]),
      rtb_Sum_e[2]), rtb_Sum_e[3]);

    /* Switch: '<S176>/Switch' incorporates:
     *  Logic: '<S176>/Logical Operator'
     *  MinMax: '<S169>/Max'
     *  MinMax: '<S169>/Max1'
     *  RelationalOperator: '<S176>/Relational Operator'
     *  RelationalOperator: '<S176>/Relational Operator1'
     */
    if ((rtb_Switch_gr_idx_1_p > rtb_Gain1_l) || (rtb_Saturation1_l_idx_1_p <
         rtb_Saturation1_l_idx_0_p)) {
      /* Sum: '<S176>/Subtract1' */
      rtb_Switch_gr_idx_0_p = rtb_Gain1_l - rtb_Saturation1_l_idx_0_p;

      /* Sum: '<S176>/Subtract' */
      rtb_Subtract_h = rtb_Switch_gr_idx_1_p - rtb_Saturation1_l_idx_1_p;

      /* Switch: '<S176>/Switch1' incorporates:
       *  Constant: '<S176>/Constant3'
       *  Gain: '<S176>/Gain'
       *  Product: '<S176>/Divide'
       *  RelationalOperator: '<S176>/Relational Operator2'
       *  Sum: '<S176>/Add'
       *  Sum: '<S176>/Subtract2'
       *  Sum: '<S176>/Subtract3'
       */
      if (rtb_Subtract_h > rtb_Switch_gr_idx_0_p) {
        rtb_Switch_gr_idx_0_p /= rtb_Subtract_h;
        rtb_Switch_gr_idx_1_p = ((rtb_Gain1_l - rtb_Switch_gr_idx_1_p) +
          (rtb_Saturation1_l_idx_0_p - rtb_Saturation1_l_idx_1_p)) * 0.5F;
      } else {
        rtb_Switch_gr_idx_0_p = 1.0F;

        /* Switch: '<S176>/Switch2' incorporates:
         *  Constant: '<S176>/Constant3'
         *  RelationalOperator: '<S176>/Relational Operator3'
         *  Sum: '<S176>/Subtract4'
         *  Sum: '<S176>/Subtract5'
         */
        if (rtb_Switch_gr_idx_1_p > rtb_Gain1_l) {
          rtb_Switch_gr_idx_1_p = rtb_Gain1_l - rtb_Switch_gr_idx_1_p;
        } else {
          rtb_Switch_gr_idx_1_p = rtb_Saturation1_l_idx_0_p -
            rtb_Saturation1_l_idx_1_p;
        }

        /* End of Switch: '<S176>/Switch2' */
      }

      /* End of Switch: '<S176>/Switch1' */
    } else {
      rtb_Switch_gr_idx_0_p = 1.0F;
      rtb_Switch_gr_idx_1_p = 0.0F;
    }

    /* End of Switch: '<S176>/Switch' */

    /* Sum: '<S169>/Sum1' */
    rtb_Saturation3_j += rtb_Switch_gr_idx_1_p;

    /* Saturate: '<S169>/Saturation3' */
    if (rtb_Saturation3_j > 1.0F) {
      rtb_Saturation3_j = 1.0F;
    } else {
      if (rtb_Saturation3_j < 0.0F) {
        rtb_Saturation3_j = 0.0F;
      }
    }

    /* End of Saturate: '<S169>/Saturation3' */

    /* Sum: '<S169>/Sum2' incorporates:
     *  Product: '<S169>/Multiply1'
     */
    rtb_Switch_gr_idx_1_p = rtb_floating_yaw[0] * rtb_Switch_gr_idx_0_p +
      rtb_Saturation3_j;

    /* Saturate: '<S169>/Saturation4' */
    if (rtb_Switch_gr_idx_1_p > 1.0F) {
      rtb_Switch_gr_idx_1_p = 1.0F;
    } else {
      if (rtb_Switch_gr_idx_1_p < 0.0F) {
        rtb_Switch_gr_idx_1_p = 0.0F;
      }
    }

    /* Sum: '<S169>/Sum3' incorporates:
     *  Product: '<S169>/Multiply2'
     */
    rtb_Sum_e[0] = Controller_ConstB.VTOL1.r_column[0] *
      rtb_Saturation1_l_idx_2_p + rtb_Switch_gr_idx_1_p;

    /* Product: '<S169>/Multiply1' */
    rtb_floating_yaw[0] = rtb_Switch_gr_idx_1_p;

    /* Sum: '<S169>/Sum2' incorporates:
     *  Product: '<S169>/Multiply1'
     */
    rtb_Switch_gr_idx_1_p = rtb_floating_yaw[1] * rtb_Switch_gr_idx_0_p +
      rtb_Saturation3_j;

    /* Saturate: '<S169>/Saturation4' */
    if (rtb_Switch_gr_idx_1_p > 1.0F) {
      rtb_Switch_gr_idx_1_p = 1.0F;
    } else {
      if (rtb_Switch_gr_idx_1_p < 0.0F) {
        rtb_Switch_gr_idx_1_p = 0.0F;
      }
    }

    /* Sum: '<S169>/Sum3' incorporates:
     *  Product: '<S169>/Multiply2'
     */
    rtb_Sum_e[1] = Controller_ConstB.VTOL1.r_column[1] *
      rtb_Saturation1_l_idx_2_p + rtb_Switch_gr_idx_1_p;

    /* Product: '<S169>/Multiply1' */
    rtb_floating_yaw[1] = rtb_Switch_gr_idx_1_p;

    /* Sum: '<S169>/Sum2' incorporates:
     *  Product: '<S169>/Multiply1'
     */
    rtb_Switch_gr_idx_1_p = rtb_floating_yaw[2] * rtb_Switch_gr_idx_0_p +
      rtb_Saturation3_j;

    /* Saturate: '<S169>/Saturation4' */
    if (rtb_Switch_gr_idx_1_p > 1.0F) {
      rtb_Switch_gr_idx_1_p = 1.0F;
    } else {
      if (rtb_Switch_gr_idx_1_p < 0.0F) {
        rtb_Switch_gr_idx_1_p = 0.0F;
      }
    }

    /* Sum: '<S169>/Sum3' incorporates:
     *  Product: '<S169>/Multiply2'
     */
    rtb_Sum_e[2] = Controller_ConstB.VTOL1.r_column[2] *
      rtb_Saturation1_l_idx_2_p + rtb_Switch_gr_idx_1_p;

    /* Product: '<S169>/Multiply1' */
    rtb_floating_yaw[2] = rtb_Switch_gr_idx_1_p;

    /* Sum: '<S169>/Sum2' incorporates:
     *  Product: '<S169>/Multiply1'
     */
    rtb_Switch_gr_idx_1_p = rtb_floating_yaw[3] * rtb_Switch_gr_idx_0_p +
      rtb_Saturation3_j;

    /* Saturate: '<S169>/Saturation4' */
    if (rtb_Switch_gr_idx_1_p > 1.0F) {
      rtb_Switch_gr_idx_1_p = 1.0F;
    } else {
      if (rtb_Switch_gr_idx_1_p < 0.0F) {
        rtb_Switch_gr_idx_1_p = 0.0F;
      }
    }

    /* Sum: '<S169>/Sum3' incorporates:
     *  Product: '<S169>/Multiply2'
     */
    rtb_Sum_e[3] = Controller_ConstB.VTOL1.r_column[3] *
      rtb_Saturation1_l_idx_2_p + rtb_Switch_gr_idx_1_p;

    /* Product: '<S169>/Multiply1' */
    rtb_floating_yaw[3] = rtb_Switch_gr_idx_1_p;

    /* MATLAB Function: '<S169>/R_Remix' */
    Controller_R_Remix(rtb_Sum_e, rtb_Gain1_l, rtb_Saturation1_l_idx_0_p,
                       rtb_floating_yaw);

    /* MultiPortSwitch: '<S172>/Multiport Switch' incorporates:
     *  Constant: '<S173>/Constant1'
     *  Constant: '<S173>/Constant12'
     *  Constant: '<S173>/Constant2'
     *  Constant: '<S173>/Constant7'
     *  DataTypeConversion: '<S182>/Data Type Conversion'
     *  DataTypeConversion: '<S183>/Data Type Conversion'
     *  Inport: '<Root>/FMS_Out'
     */
    switch (Controller_U.FMS_Out.status) {
     case 1:
      for (i_p = 0; i_p < 9; i_p++) {
        rtb_VariantMergeForOutportactua[i_p] = (uint16_T)fmodf(floorf
          (rtb_Saturation_fa[i_p]), 65536.0F);
      }
      break;

     case 2:
      for (i_p = 0; i_p < 5; i_p++) {
        /* Saturate: '<S183>/Saturation' incorporates:
         *  Constant: '<S183>/Standby'
         *  Reshape: '<S183>/Reshape'
         */
        if (Controller_ConstP.pooled29[i_p] > 2000.0F) {
          rtb_Saturation1_l_idx_2_p = 2000.0F;
        } else if (Controller_ConstP.pooled29[i_p] < 1000.0F) {
          rtb_Saturation1_l_idx_2_p = 1000.0F;
        } else {
          rtb_Saturation1_l_idx_2_p = Controller_ConstP.pooled29[i_p];
        }

        rtb_VariantMergeForOutportactua[i_p] = (uint16_T)fmodf(floorf
          (rtb_Saturation1_l_idx_2_p), 65536.0F);
      }

      /* Saturate: '<S183>/Saturation' incorporates:
       *  Bias: '<S183>/Bias'
       *  Constant: '<S183>/Constant'
       *  DataTypeConversion: '<S183>/Data Type Conversion'
       */
      if (1500.0F + CONTROL_PARAM.SERVO1_BIAS > 2000.0F) {
        rtb_Saturation1_l_idx_2_p = 2000.0F;
      } else if (1500.0F + CONTROL_PARAM.SERVO1_BIAS < 1000.0F) {
        rtb_Saturation1_l_idx_2_p = 1000.0F;
      } else {
        rtb_Saturation1_l_idx_2_p = 1500.0F + CONTROL_PARAM.SERVO1_BIAS;
      }

      rtb_VariantMergeForOutportactua[5] = (uint16_T)fmodf(floorf
        (rtb_Saturation1_l_idx_2_p), 65536.0F);

      /* Saturate: '<S183>/Saturation' incorporates:
       *  Bias: '<S183>/Bias1'
       *  Constant: '<S183>/Constant'
       *  DataTypeConversion: '<S183>/Data Type Conversion'
       */
      if (1500.0F + CONTROL_PARAM.SERVO2_BIAS > 2000.0F) {
        rtb_Saturation1_l_idx_2_p = 2000.0F;
      } else if (1500.0F + CONTROL_PARAM.SERVO2_BIAS < 1000.0F) {
        rtb_Saturation1_l_idx_2_p = 1000.0F;
      } else {
        rtb_Saturation1_l_idx_2_p = 1500.0F + CONTROL_PARAM.SERVO2_BIAS;
      }

      rtb_VariantMergeForOutportactua[6] = (uint16_T)fmodf(floorf
        (rtb_Saturation1_l_idx_2_p), 65536.0F);

      /* Saturate: '<S183>/Saturation' incorporates:
       *  Bias: '<S183>/Bias2'
       *  Constant: '<S183>/Constant'
       *  DataTypeConversion: '<S183>/Data Type Conversion'
       */
      if (1500.0F + CONTROL_PARAM.SERVO3_BIAS > 2000.0F) {
        rtb_Saturation1_l_idx_2_p = 2000.0F;
      } else if (1500.0F + CONTROL_PARAM.SERVO3_BIAS < 1000.0F) {
        rtb_Saturation1_l_idx_2_p = 1000.0F;
      } else {
        rtb_Saturation1_l_idx_2_p = 1500.0F + CONTROL_PARAM.SERVO3_BIAS;
      }

      rtb_VariantMergeForOutportactua[7] = (uint16_T)fmodf(floorf
        (rtb_Saturation1_l_idx_2_p), 65536.0F);

      /* Saturate: '<S183>/Saturation' incorporates:
       *  Bias: '<S183>/Bias3'
       *  Constant: '<S183>/Constant'
       *  DataTypeConversion: '<S183>/Data Type Conversion'
       */
      if (1500.0F + CONTROL_PARAM.SERVO4_BIAS > 2000.0F) {
        rtb_Saturation1_l_idx_2_p = 2000.0F;
      } else if (1500.0F + CONTROL_PARAM.SERVO4_BIAS < 1000.0F) {
        rtb_Saturation1_l_idx_2_p = 1000.0F;
      } else {
        rtb_Saturation1_l_idx_2_p = 1500.0F + CONTROL_PARAM.SERVO4_BIAS;
      }

      rtb_VariantMergeForOutportactua[8] = (uint16_T)fmodf(floorf
        (rtb_Saturation1_l_idx_2_p), 65536.0F);
      break;

     case 3:
      rtb_MatrixConcatenate[11] = CONTROL_PARAM.FW_YAW_EFFC *
        CONTROL_PARAM.FW_RUDDER_DIR;

      /* SignalConversion: '<S173>/ConcatBufferAtVector Concatenate2In3' incorporates:
       *  Constant: '<S173>/Constant11'
       *  Constant: '<S173>/Constant12'
       */
      rtb_MatrixConcatenate[10] = 0.0F;

      /* SignalConversion: '<S173>/ConcatBufferAtVector Concatenate2In2' incorporates:
       *  Constant: '<S173>/Constant10'
       */
      rtb_MatrixConcatenate[9] = 0.0F;

      /* SignalConversion: '<S173>/ConcatBufferAtVector Concatenate2In1' incorporates:
       *  Constant: '<S173>/Constant9'
       */
      rtb_MatrixConcatenate[8] = 0.0F;

      /* SignalConversion: '<S173>/ConcatBufferAtVector Concatenate1In4' incorporates:
       *  Constant: '<S173>/Constant8'
       */
      rtb_MatrixConcatenate[7] = 0.0F;
      rtb_MatrixConcatenate[6] = CONTROL_PARAM.FW_PITCH_EFFC *
        CONTROL_PARAM.FW_ELEVATOR_DIR;

      /* SignalConversion: '<S173>/ConcatBufferAtVector Concatenate1In2' incorporates:
       *  Constant: '<S173>/Constant6'
       *  Constant: '<S173>/Constant7'
       */
      rtb_MatrixConcatenate[5] = 0.0F;

      /* SignalConversion: '<S173>/ConcatBufferAtVector Concatenate1In1' incorporates:
       *  Constant: '<S173>/Constant5'
       */
      rtb_MatrixConcatenate[4] = 0.0F;

      /* SignalConversion: '<S173>/ConcatBufferAtVector ConcatenateIn4' incorporates:
       *  Constant: '<S173>/Constant4'
       */
      rtb_MatrixConcatenate[3] = 0.0F;

      /* SignalConversion: '<S173>/ConcatBufferAtVector ConcatenateIn3' incorporates:
       *  Constant: '<S173>/Constant3'
       */
      rtb_MatrixConcatenate[2] = 0.0F;
      rtb_MatrixConcatenate[1] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON2_DIR;
      rtb_MatrixConcatenate[0] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON1_DIR;

      /* Saturate: '<S168>/Saturation5' incorporates:
       *  Constant: '<S173>/Constant1'
       *  Constant: '<S173>/Constant2'
       */
      if (rtb_Multiply[0] > 1.0F) {
        rtb_Saturation1_l_idx_2_p = 1.0F;
      } else if (rtb_Multiply[0] < -1.0F) {
        rtb_Saturation1_l_idx_2_p = -1.0F;
      } else {
        rtb_Saturation1_l_idx_2_p = rtb_Multiply[0];
      }

      if (rtb_Multiply[1] > 1.0F) {
        rtb_Gain1_l = 1.0F;
      } else if (rtb_Multiply[1] < -1.0F) {
        rtb_Gain1_l = -1.0F;
      } else {
        rtb_Gain1_l = rtb_Multiply[1];
      }

      if (rtb_Multiply[2] > 1.0F) {
        rtb_Saturation3_j = 1.0F;
      } else if (rtb_Multiply[2] < -1.0F) {
        rtb_Saturation3_j = -1.0F;
      } else {
        rtb_Saturation3_j = rtb_Multiply[2];
      }

      /* End of Saturate: '<S168>/Saturation5' */
      for (i_p = 0; i_p < 4; i_p++) {
        /* Bias: '<S168>/Bias' incorporates:
         *  Gain: '<S168>/Gain1'
         *  Product: '<S168>/Multiply1'
         */
        rtb_Saturation5_o[i_p] = 500.0F * (rtb_MatrixConcatenate[i_p + 8] *
          rtb_Saturation3_j + (rtb_MatrixConcatenate[i_p + 4] * rtb_Gain1_l +
          rtb_MatrixConcatenate[i_p] * rtb_Saturation1_l_idx_2_p)) + 1500.0F;

        /* Sum: '<S169>/Sum4' */
        rtb_Saturation1_l_idx_0_p = rtb_Sum_e[i_p] + rtb_floating_yaw[i_p];

        /* Saturate: '<S169>/Saturation5' */
        if (rtb_Saturation1_l_idx_0_p > 1.0F) {
          rtb_Saturation1_l_idx_0_p = 1.0F;
        } else {
          if (rtb_Saturation1_l_idx_0_p < 0.0F) {
            rtb_Saturation1_l_idx_0_p = 0.0F;
          }
        }

        /* End of Saturate: '<S169>/Saturation5' */

        /* DataTypeConversion: '<S169>/Data Type Conversion' incorporates:
         *  Constant: '<S169>/Constant2'
         *  Gain: '<S169>/Gain3'
         *  Sum: '<S169>/Sum5'
         */
        u0_p = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          rtb_Saturation1_l_idx_0_p), 4.2949673E+9F) + 1000U);

        /* Saturate: '<S169>/Saturation' */
        if (u0_p > CONTROL_PARAM.MC_OUT_MAX) {
          rtb_VariantMergeForOutportactua[i_p] = CONTROL_PARAM.MC_OUT_MAX;
        } else if (u0_p < CONTROL_PARAM.MC_OUT_MIN) {
          rtb_VariantMergeForOutportactua[i_p] = CONTROL_PARAM.MC_OUT_MIN;
        } else {
          rtb_VariantMergeForOutportactua[i_p] = u0_p;
        }

        /* End of Saturate: '<S169>/Saturation' */
      }

      /* Saturate: '<S168>/Saturation' */
      if (rtb_Multiply1[0] > 1.0F) {
        rtb_Saturation1_l_idx_2_p = 1.0F;
      } else if (rtb_Multiply1[0] < 0.0F) {
        rtb_Saturation1_l_idx_2_p = 0.0F;
      } else {
        rtb_Saturation1_l_idx_2_p = rtb_Multiply1[0];
      }

      /* End of Saturate: '<S168>/Saturation' */

      /* DataTypeConversion: '<S175>/Data Type Conversion' incorporates:
       *  Constant: '<S175>/Constant1'
       *  Gain: '<S175>/Gain1'
       *  Sum: '<S175>/Sum1'
       */
      u0_p = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
        rtb_Saturation1_l_idx_2_p), 4.2949673E+9F) + 1000U);

      /* Saturate: '<S168>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[4] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[4] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[4] = u0_p;
      }

      /* DataTypeConversion: '<S168>/Data Type Conversion' incorporates:
       *  Bias: '<S168>/Bias1'
       */
      rtb_Saturation1_l_idx_2_p = fmodf(floorf(rtb_Saturation5_o[0] +
        CONTROL_PARAM.SERVO1_BIAS), 65536.0F);
      u0_p = (uint16_T)(rtb_Saturation1_l_idx_2_p < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_l_idx_2_p :
                        (int32_T)(uint16_T)rtb_Saturation1_l_idx_2_p);

      /* Saturate: '<S168>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[5] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[5] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[5] = u0_p;
      }

      /* DataTypeConversion: '<S168>/Data Type Conversion1' incorporates:
       *  Bias: '<S168>/Bias2'
       */
      rtb_Saturation1_l_idx_2_p = fmodf(floorf(rtb_Saturation5_o[1] +
        CONTROL_PARAM.SERVO2_BIAS), 65536.0F);
      u0_p = (uint16_T)(rtb_Saturation1_l_idx_2_p < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_l_idx_2_p :
                        (int32_T)(uint16_T)rtb_Saturation1_l_idx_2_p);

      /* Saturate: '<S168>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[6] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[6] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[6] = u0_p;
      }

      /* DataTypeConversion: '<S168>/Data Type Conversion2' incorporates:
       *  Bias: '<S168>/Bias3'
       */
      rtb_Saturation1_l_idx_2_p = fmodf(floorf(rtb_Saturation5_o[2] +
        CONTROL_PARAM.SERVO3_BIAS), 65536.0F);
      u0_p = (uint16_T)(rtb_Saturation1_l_idx_2_p < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_l_idx_2_p :
                        (int32_T)(uint16_T)rtb_Saturation1_l_idx_2_p);

      /* Saturate: '<S168>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[7] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[7] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[7] = u0_p;
      }

      /* DataTypeConversion: '<S168>/Data Type Conversion3' incorporates:
       *  Bias: '<S168>/Bias4'
       */
      rtb_Saturation1_l_idx_2_p = fmodf(floorf(rtb_Saturation5_o[3] +
        CONTROL_PARAM.SERVO4_BIAS), 65536.0F);
      u0_p = (uint16_T)(rtb_Saturation1_l_idx_2_p < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_l_idx_2_p :
                        (int32_T)(uint16_T)rtb_Saturation1_l_idx_2_p);

      /* Saturate: '<S168>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[8] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[8] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[8] = u0_p;
      }
      break;

     default:
      for (i_p = 0; i_p < 9; i_p++) {
        rtb_VariantMergeForOutportactua[i_p] = (uint16_T)fmodf(floorf
          (rtb_Saturation_fa[i_p]), 65536.0F);
      }
      break;
    }

    /* End of MultiPortSwitch: '<S172>/Multiport Switch' */
  }

#elif AIRFRAME == 2

  /* Output and update for atomic system: '<S165>/VTOL2' */
  {
    real32_T rtb_Saturation3_c;
    real32_T rtb_MatrixConcatenate_g[12];
    real32_T rtb_Saturation5_m[4];
    real32_T rtb_floating_yaw_n[4];
    real32_T rtb_Subtract_g;
    real32_T rtb_Saturation_k[9];
    real32_T rtb_Sum_m[4];
    real32_T rtb_Gain1_lm;
    int32_T i_o;
    real32_T rtb_Switch_ge_idx_0_o;
    real32_T rtb_Switch_ge_idx_1_o;
    real32_T rtb_Saturation1_p_idx_0_o;
    real32_T rtb_Saturation1_p_idx_1_o;
    real32_T rtb_Saturation1_p_idx_2_o;
    uint16_T u0_o;

    /* Saturate: '<S194>/Saturation' incorporates:
     *  Bias: '<S194>/Bias'
     *  Bias: '<S194>/Bias1'
     *  Bias: '<S194>/Bias2'
     *  Bias: '<S194>/Bias3'
     *  Constant: '<S194>/Constant'
     */
    for (i_o = 0; i_o < 5; i_o++) {
      rtb_Saturation_k[i_o] = 1000.0F;
    }

    if (1500.0F + CONTROL_PARAM.SERVO1_BIAS > 2000.0F) {
      rtb_Saturation_k[5] = 2000.0F;
    } else if (1500.0F + CONTROL_PARAM.SERVO1_BIAS < 1000.0F) {
      rtb_Saturation_k[5] = 1000.0F;
    } else {
      rtb_Saturation_k[5] = 1500.0F + CONTROL_PARAM.SERVO1_BIAS;
    }

    if (1500.0F + CONTROL_PARAM.SERVO2_BIAS > 2000.0F) {
      rtb_Saturation_k[6] = 2000.0F;
    } else if (1500.0F + CONTROL_PARAM.SERVO2_BIAS < 1000.0F) {
      rtb_Saturation_k[6] = 1000.0F;
    } else {
      rtb_Saturation_k[6] = 1500.0F + CONTROL_PARAM.SERVO2_BIAS;
    }

    if (1500.0F + CONTROL_PARAM.SERVO3_BIAS > 2000.0F) {
      rtb_Saturation_k[7] = 2000.0F;
    } else if (1500.0F + CONTROL_PARAM.SERVO3_BIAS < 1000.0F) {
      rtb_Saturation_k[7] = 1000.0F;
    } else {
      rtb_Saturation_k[7] = 1500.0F + CONTROL_PARAM.SERVO3_BIAS;
    }

    if (1500.0F + CONTROL_PARAM.SERVO4_BIAS > 2000.0F) {
      rtb_Saturation_k[8] = 2000.0F;
    } else if (1500.0F + CONTROL_PARAM.SERVO4_BIAS < 1000.0F) {
      rtb_Saturation_k[8] = 1000.0F;
    } else {
      rtb_Saturation_k[8] = 1500.0F + CONTROL_PARAM.SERVO4_BIAS;
    }

    /* End of Saturate: '<S194>/Saturation' */

    /* Saturate: '<S185>/Saturation1' */
    if (rtb_Multiply2[0] > 1.0F) {
      rtb_Saturation1_p_idx_0_o = 1.0F;
    } else if (rtb_Multiply2[0] < -1.0F) {
      rtb_Saturation1_p_idx_0_o = -1.0F;
    } else {
      rtb_Saturation1_p_idx_0_o = rtb_Multiply2[0];
    }

    if (rtb_Multiply2[1] > 1.0F) {
      rtb_Saturation1_p_idx_1_o = 1.0F;
    } else if (rtb_Multiply2[1] < -1.0F) {
      rtb_Saturation1_p_idx_1_o = -1.0F;
    } else {
      rtb_Saturation1_p_idx_1_o = rtb_Multiply2[1];
    }

    if (rtb_Multiply2[2] > 1.0F) {
      rtb_Saturation1_p_idx_2_o = 1.0F;
    } else if (rtb_Multiply2[2] < -1.0F) {
      rtb_Saturation1_p_idx_2_o = -1.0F;
    } else {
      rtb_Saturation1_p_idx_2_o = rtb_Multiply2[2];
    }

    /* End of Saturate: '<S185>/Saturation1' */

    /* Gain: '<S185>/Gain1' incorporates:
     *  Bias: '<S185>/Bias'
     *  Constant: '<S185>/Constant'
     */
    rtb_Gain1_lm = ((real32_T)CONTROL_PARAM.MC_OUT_MAX + -1000.0F) * 0.001F;

    /* Saturate: '<S185>/Saturation2' */
    if (rtb_Multiply3[2] > 1.0F) {
      rtb_Saturation3_c = 1.0F;
    } else if (rtb_Multiply3[2] < 0.0F) {
      rtb_Saturation3_c = 0.0F;
    } else {
      rtb_Saturation3_c = rtb_Multiply3[2];
    }

    /* End of Saturate: '<S185>/Saturation2' */
    for (i_o = 0; i_o < 4; i_o++) {
      /* Product: '<S185>/Multiply' */
      rtb_Switch_ge_idx_1_o = Controller_ConstB.VTOL2.pq_column[i_o + 4] *
        rtb_Saturation1_p_idx_1_o + Controller_ConstB.VTOL2.pq_column[i_o] *
        rtb_Saturation1_p_idx_0_o;

      /* Sum: '<S185>/Sum' */
      rtb_Sum_m[i_o] = rtb_Switch_ge_idx_1_o + rtb_Saturation3_c;

      /* Product: '<S185>/Multiply' */
      rtb_floating_yaw_n[i_o] = rtb_Switch_ge_idx_1_o;
    }

    /* Gain: '<S185>/Gain2' incorporates:
     *  Bias: '<S185>/Bias1'
     *  Constant: '<S185>/Constant1'
     */
    rtb_Saturation1_p_idx_0_o = ((real32_T)CONTROL_PARAM.MC_OUT_MIN + -1000.0F) *
      0.001F;

    /* MinMax: '<S185>/Max' */
    rtb_Switch_ge_idx_1_o = fmaxf(fmaxf(fmaxf(rtb_Sum_m[0], rtb_Sum_m[1]),
      rtb_Sum_m[2]), rtb_Sum_m[3]);

    /* MinMax: '<S185>/Max1' */
    rtb_Saturation1_p_idx_1_o = fminf(fminf(fminf(rtb_Sum_m[0], rtb_Sum_m[1]),
      rtb_Sum_m[2]), rtb_Sum_m[3]);

    /* Switch: '<S191>/Switch' incorporates:
     *  Logic: '<S191>/Logical Operator'
     *  MinMax: '<S185>/Max'
     *  MinMax: '<S185>/Max1'
     *  RelationalOperator: '<S191>/Relational Operator'
     *  RelationalOperator: '<S191>/Relational Operator1'
     */
    if ((rtb_Switch_ge_idx_1_o > rtb_Gain1_lm) || (rtb_Saturation1_p_idx_1_o <
         rtb_Saturation1_p_idx_0_o)) {
      /* Sum: '<S191>/Subtract1' */
      rtb_Switch_ge_idx_0_o = rtb_Gain1_lm - rtb_Saturation1_p_idx_0_o;

      /* Sum: '<S191>/Subtract' */
      rtb_Subtract_g = rtb_Switch_ge_idx_1_o - rtb_Saturation1_p_idx_1_o;

      /* Switch: '<S191>/Switch1' incorporates:
       *  Constant: '<S191>/Constant3'
       *  Gain: '<S191>/Gain'
       *  Product: '<S191>/Divide'
       *  RelationalOperator: '<S191>/Relational Operator2'
       *  Sum: '<S191>/Add'
       *  Sum: '<S191>/Subtract2'
       *  Sum: '<S191>/Subtract3'
       */
      if (rtb_Subtract_g > rtb_Switch_ge_idx_0_o) {
        rtb_Switch_ge_idx_0_o /= rtb_Subtract_g;
        rtb_Switch_ge_idx_1_o = ((rtb_Gain1_lm - rtb_Switch_ge_idx_1_o) +
          (rtb_Saturation1_p_idx_0_o - rtb_Saturation1_p_idx_1_o)) * 0.5F;
      } else {
        rtb_Switch_ge_idx_0_o = 1.0F;

        /* Switch: '<S191>/Switch2' incorporates:
         *  Constant: '<S191>/Constant3'
         *  RelationalOperator: '<S191>/Relational Operator3'
         *  Sum: '<S191>/Subtract4'
         *  Sum: '<S191>/Subtract5'
         */
        if (rtb_Switch_ge_idx_1_o > rtb_Gain1_lm) {
          rtb_Switch_ge_idx_1_o = rtb_Gain1_lm - rtb_Switch_ge_idx_1_o;
        } else {
          rtb_Switch_ge_idx_1_o = rtb_Saturation1_p_idx_0_o -
            rtb_Saturation1_p_idx_1_o;
        }

        /* End of Switch: '<S191>/Switch2' */
      }

      /* End of Switch: '<S191>/Switch1' */
    } else {
      rtb_Switch_ge_idx_0_o = 1.0F;
      rtb_Switch_ge_idx_1_o = 0.0F;
    }

    /* End of Switch: '<S191>/Switch' */

    /* Sum: '<S185>/Sum1' */
    rtb_Saturation3_c += rtb_Switch_ge_idx_1_o;

    /* Saturate: '<S185>/Saturation3' */
    if (rtb_Saturation3_c > 1.0F) {
      rtb_Saturation3_c = 1.0F;
    } else {
      if (rtb_Saturation3_c < 0.0F) {
        rtb_Saturation3_c = 0.0F;
      }
    }

    /* End of Saturate: '<S185>/Saturation3' */

    /* Sum: '<S185>/Sum2' incorporates:
     *  Product: '<S185>/Multiply1'
     */
    rtb_Switch_ge_idx_1_o = rtb_floating_yaw_n[0] * rtb_Switch_ge_idx_0_o +
      rtb_Saturation3_c;

    /* Saturate: '<S185>/Saturation4' */
    if (rtb_Switch_ge_idx_1_o > 1.0F) {
      rtb_Switch_ge_idx_1_o = 1.0F;
    } else {
      if (rtb_Switch_ge_idx_1_o < 0.0F) {
        rtb_Switch_ge_idx_1_o = 0.0F;
      }
    }

    /* Sum: '<S185>/Sum3' incorporates:
     *  Product: '<S185>/Multiply2'
     */
    rtb_Sum_m[0] = Controller_ConstB.VTOL2.r_column[0] *
      rtb_Saturation1_p_idx_2_o + rtb_Switch_ge_idx_1_o;

    /* Product: '<S185>/Multiply1' */
    rtb_floating_yaw_n[0] = rtb_Switch_ge_idx_1_o;

    /* Sum: '<S185>/Sum2' incorporates:
     *  Product: '<S185>/Multiply1'
     */
    rtb_Switch_ge_idx_1_o = rtb_floating_yaw_n[1] * rtb_Switch_ge_idx_0_o +
      rtb_Saturation3_c;

    /* Saturate: '<S185>/Saturation4' */
    if (rtb_Switch_ge_idx_1_o > 1.0F) {
      rtb_Switch_ge_idx_1_o = 1.0F;
    } else {
      if (rtb_Switch_ge_idx_1_o < 0.0F) {
        rtb_Switch_ge_idx_1_o = 0.0F;
      }
    }

    /* Sum: '<S185>/Sum3' incorporates:
     *  Product: '<S185>/Multiply2'
     */
    rtb_Sum_m[1] = Controller_ConstB.VTOL2.r_column[1] *
      rtb_Saturation1_p_idx_2_o + rtb_Switch_ge_idx_1_o;

    /* Product: '<S185>/Multiply1' */
    rtb_floating_yaw_n[1] = rtb_Switch_ge_idx_1_o;

    /* Sum: '<S185>/Sum2' incorporates:
     *  Product: '<S185>/Multiply1'
     */
    rtb_Switch_ge_idx_1_o = rtb_floating_yaw_n[2] * rtb_Switch_ge_idx_0_o +
      rtb_Saturation3_c;

    /* Saturate: '<S185>/Saturation4' */
    if (rtb_Switch_ge_idx_1_o > 1.0F) {
      rtb_Switch_ge_idx_1_o = 1.0F;
    } else {
      if (rtb_Switch_ge_idx_1_o < 0.0F) {
        rtb_Switch_ge_idx_1_o = 0.0F;
      }
    }

    /* Sum: '<S185>/Sum3' incorporates:
     *  Product: '<S185>/Multiply2'
     */
    rtb_Sum_m[2] = Controller_ConstB.VTOL2.r_column[2] *
      rtb_Saturation1_p_idx_2_o + rtb_Switch_ge_idx_1_o;

    /* Product: '<S185>/Multiply1' */
    rtb_floating_yaw_n[2] = rtb_Switch_ge_idx_1_o;

    /* Sum: '<S185>/Sum2' incorporates:
     *  Product: '<S185>/Multiply1'
     */
    rtb_Switch_ge_idx_1_o = rtb_floating_yaw_n[3] * rtb_Switch_ge_idx_0_o +
      rtb_Saturation3_c;

    /* Saturate: '<S185>/Saturation4' */
    if (rtb_Switch_ge_idx_1_o > 1.0F) {
      rtb_Switch_ge_idx_1_o = 1.0F;
    } else {
      if (rtb_Switch_ge_idx_1_o < 0.0F) {
        rtb_Switch_ge_idx_1_o = 0.0F;
      }
    }

    /* Sum: '<S185>/Sum3' incorporates:
     *  Product: '<S185>/Multiply2'
     */
    rtb_Sum_m[3] = Controller_ConstB.VTOL2.r_column[3] *
      rtb_Saturation1_p_idx_2_o + rtb_Switch_ge_idx_1_o;

    /* Product: '<S185>/Multiply1' */
    rtb_floating_yaw_n[3] = rtb_Switch_ge_idx_1_o;

    /* MATLAB Function: '<S185>/R_Remix' */
    Controller_R_Remix(rtb_Sum_m, rtb_Gain1_lm, rtb_Saturation1_p_idx_0_o,
                       rtb_floating_yaw_n);

    /* MultiPortSwitch: '<S187>/Multiport Switch' incorporates:
     *  Constant: '<S188>/Constant1'
     *  Constant: '<S188>/Constant11'
     *  Constant: '<S188>/Constant12'
     *  Constant: '<S188>/Constant2'
     *  Constant: '<S188>/Constant7'
     *  Constant: '<S188>/Constant8'
     *  DataTypeConversion: '<S194>/Data Type Conversion'
     *  DataTypeConversion: '<S195>/Data Type Conversion'
     *  Inport: '<Root>/FMS_Out'
     */
    switch (Controller_U.FMS_Out.status) {
     case 1:
      for (i_o = 0; i_o < 9; i_o++) {
        rtb_VariantMergeForOutportactua[i_o] = (uint16_T)fmodf(floorf
          (rtb_Saturation_k[i_o]), 65536.0F);
      }
      break;

     case 2:
      for (i_o = 0; i_o < 5; i_o++) {
        /* Saturate: '<S195>/Saturation' incorporates:
         *  Constant: '<S195>/Disarm'
         *  Reshape: '<S195>/Reshape'
         */
        if (Controller_ConstP.pooled29[i_o] > 2000.0F) {
          rtb_Saturation1_p_idx_2_o = 2000.0F;
        } else if (Controller_ConstP.pooled29[i_o] < 1000.0F) {
          rtb_Saturation1_p_idx_2_o = 1000.0F;
        } else {
          rtb_Saturation1_p_idx_2_o = Controller_ConstP.pooled29[i_o];
        }

        rtb_VariantMergeForOutportactua[i_o] = (uint16_T)fmodf(floorf
          (rtb_Saturation1_p_idx_2_o), 65536.0F);
      }

      /* Saturate: '<S195>/Saturation' incorporates:
       *  Bias: '<S195>/Bias'
       *  Constant: '<S195>/Constant'
       *  DataTypeConversion: '<S195>/Data Type Conversion'
       */
      if (1500.0F + CONTROL_PARAM.SERVO1_BIAS > 2000.0F) {
        rtb_Saturation1_p_idx_2_o = 2000.0F;
      } else if (1500.0F + CONTROL_PARAM.SERVO1_BIAS < 1000.0F) {
        rtb_Saturation1_p_idx_2_o = 1000.0F;
      } else {
        rtb_Saturation1_p_idx_2_o = 1500.0F + CONTROL_PARAM.SERVO1_BIAS;
      }

      rtb_VariantMergeForOutportactua[5] = (uint16_T)fmodf(floorf
        (rtb_Saturation1_p_idx_2_o), 65536.0F);

      /* Saturate: '<S195>/Saturation' incorporates:
       *  Bias: '<S195>/Bias1'
       *  Constant: '<S195>/Constant'
       *  DataTypeConversion: '<S195>/Data Type Conversion'
       */
      if (1500.0F + CONTROL_PARAM.SERVO2_BIAS > 2000.0F) {
        rtb_Saturation1_p_idx_2_o = 2000.0F;
      } else if (1500.0F + CONTROL_PARAM.SERVO2_BIAS < 1000.0F) {
        rtb_Saturation1_p_idx_2_o = 1000.0F;
      } else {
        rtb_Saturation1_p_idx_2_o = 1500.0F + CONTROL_PARAM.SERVO2_BIAS;
      }

      rtb_VariantMergeForOutportactua[6] = (uint16_T)fmodf(floorf
        (rtb_Saturation1_p_idx_2_o), 65536.0F);

      /* Saturate: '<S195>/Saturation' incorporates:
       *  Bias: '<S195>/Bias2'
       *  Constant: '<S195>/Constant'
       *  DataTypeConversion: '<S195>/Data Type Conversion'
       */
      if (1500.0F + CONTROL_PARAM.SERVO3_BIAS > 2000.0F) {
        rtb_Saturation1_p_idx_2_o = 2000.0F;
      } else if (1500.0F + CONTROL_PARAM.SERVO3_BIAS < 1000.0F) {
        rtb_Saturation1_p_idx_2_o = 1000.0F;
      } else {
        rtb_Saturation1_p_idx_2_o = 1500.0F + CONTROL_PARAM.SERVO3_BIAS;
      }

      rtb_VariantMergeForOutportactua[7] = (uint16_T)fmodf(floorf
        (rtb_Saturation1_p_idx_2_o), 65536.0F);

      /* Saturate: '<S195>/Saturation' incorporates:
       *  Bias: '<S195>/Bias3'
       *  Constant: '<S195>/Constant'
       *  DataTypeConversion: '<S195>/Data Type Conversion'
       */
      if (1500.0F + CONTROL_PARAM.SERVO4_BIAS > 2000.0F) {
        rtb_Saturation1_p_idx_2_o = 2000.0F;
      } else if (1500.0F + CONTROL_PARAM.SERVO4_BIAS < 1000.0F) {
        rtb_Saturation1_p_idx_2_o = 1000.0F;
      } else {
        rtb_Saturation1_p_idx_2_o = 1500.0F + CONTROL_PARAM.SERVO4_BIAS;
      }

      rtb_VariantMergeForOutportactua[8] = (uint16_T)fmodf(floorf
        (rtb_Saturation1_p_idx_2_o), 65536.0F);
      break;

     case 3:
      rtb_MatrixConcatenate_g[11] = CONTROL_PARAM.FW_YAW_EFFC *
        CONTROL_PARAM.FW_TAIL2_DIR;
      rtb_MatrixConcatenate_g[10] = CONTROL_PARAM.FW_YAW_EFFC *
        CONTROL_PARAM.FW_TAIL1_DIR;

      /* SignalConversion: '<S188>/ConcatBufferAtVector Concatenate2In2' incorporates:
       *  Constant: '<S188>/Constant10'
       *  Constant: '<S188>/Constant11'
       *  Constant: '<S188>/Constant12'
       */
      rtb_MatrixConcatenate_g[9] = 0.0F;

      /* SignalConversion: '<S188>/ConcatBufferAtVector Concatenate2In1' incorporates:
       *  Constant: '<S188>/Constant9'
       */
      rtb_MatrixConcatenate_g[8] = 0.0F;
      rtb_MatrixConcatenate_g[7] = -CONTROL_PARAM.FW_PITCH_EFFC *
        CONTROL_PARAM.FW_TAIL2_DIR;
      rtb_MatrixConcatenate_g[6] = CONTROL_PARAM.FW_PITCH_EFFC *
        CONTROL_PARAM.FW_TAIL1_DIR;

      /* SignalConversion: '<S188>/ConcatBufferAtVector Concatenate1In2' incorporates:
       *  Constant: '<S188>/Constant6'
       *  Constant: '<S188>/Constant7'
       *  Constant: '<S188>/Constant8'
       */
      rtb_MatrixConcatenate_g[5] = 0.0F;

      /* SignalConversion: '<S188>/ConcatBufferAtVector Concatenate1In1' incorporates:
       *  Constant: '<S188>/Constant5'
       */
      rtb_MatrixConcatenate_g[4] = 0.0F;

      /* SignalConversion: '<S188>/ConcatBufferAtVector ConcatenateIn4' incorporates:
       *  Constant: '<S188>/Constant4'
       */
      rtb_MatrixConcatenate_g[3] = 0.0F;

      /* SignalConversion: '<S188>/ConcatBufferAtVector ConcatenateIn3' incorporates:
       *  Constant: '<S188>/Constant3'
       */
      rtb_MatrixConcatenate_g[2] = 0.0F;
      rtb_MatrixConcatenate_g[1] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON2_DIR;
      rtb_MatrixConcatenate_g[0] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON1_DIR;

      /* Saturate: '<S184>/Saturation5' incorporates:
       *  Constant: '<S188>/Constant1'
       *  Constant: '<S188>/Constant2'
       */
      if (rtb_Multiply[0] > 1.0F) {
        rtb_Saturation1_p_idx_2_o = 1.0F;
      } else if (rtb_Multiply[0] < -1.0F) {
        rtb_Saturation1_p_idx_2_o = -1.0F;
      } else {
        rtb_Saturation1_p_idx_2_o = rtb_Multiply[0];
      }

      if (rtb_Multiply[1] > 1.0F) {
        rtb_Gain1_lm = 1.0F;
      } else if (rtb_Multiply[1] < -1.0F) {
        rtb_Gain1_lm = -1.0F;
      } else {
        rtb_Gain1_lm = rtb_Multiply[1];
      }

      if (rtb_Multiply[2] > 1.0F) {
        rtb_Saturation3_c = 1.0F;
      } else if (rtb_Multiply[2] < -1.0F) {
        rtb_Saturation3_c = -1.0F;
      } else {
        rtb_Saturation3_c = rtb_Multiply[2];
      }

      /* End of Saturate: '<S184>/Saturation5' */
      for (i_o = 0; i_o < 4; i_o++) {
        /* Bias: '<S184>/Bias' incorporates:
         *  Gain: '<S184>/Gain1'
         *  Product: '<S184>/Multiply1'
         */
        rtb_Saturation5_m[i_o] = 500.0F * (rtb_MatrixConcatenate_g[i_o + 8] *
          rtb_Saturation3_c + (rtb_MatrixConcatenate_g[i_o + 4] * rtb_Gain1_lm +
          rtb_MatrixConcatenate_g[i_o] * rtb_Saturation1_p_idx_2_o)) + 1500.0F;

        /* Sum: '<S185>/Sum4' */
        rtb_Saturation1_p_idx_0_o = rtb_Sum_m[i_o] + rtb_floating_yaw_n[i_o];

        /* Saturate: '<S185>/Saturation5' */
        if (rtb_Saturation1_p_idx_0_o > 1.0F) {
          rtb_Saturation1_p_idx_0_o = 1.0F;
        } else {
          if (rtb_Saturation1_p_idx_0_o < 0.0F) {
            rtb_Saturation1_p_idx_0_o = 0.0F;
          }
        }

        /* End of Saturate: '<S185>/Saturation5' */

        /* DataTypeConversion: '<S185>/Data Type Conversion' incorporates:
         *  Constant: '<S185>/Constant2'
         *  Gain: '<S185>/Gain3'
         *  Sum: '<S185>/Sum5'
         */
        u0_o = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          rtb_Saturation1_p_idx_0_o), 4.2949673E+9F) + 1000U);

        /* Saturate: '<S185>/Saturation' */
        if (u0_o > CONTROL_PARAM.MC_OUT_MAX) {
          rtb_VariantMergeForOutportactua[i_o] = CONTROL_PARAM.MC_OUT_MAX;
        } else if (u0_o < CONTROL_PARAM.MC_OUT_MIN) {
          rtb_VariantMergeForOutportactua[i_o] = CONTROL_PARAM.MC_OUT_MIN;
        } else {
          rtb_VariantMergeForOutportactua[i_o] = u0_o;
        }

        /* End of Saturate: '<S185>/Saturation' */
      }

      /* Saturate: '<S184>/Saturation4' */
      if (rtb_Multiply1[0] > 1.0F) {
        rtb_Saturation1_p_idx_2_o = 1.0F;
      } else if (rtb_Multiply1[0] < 0.0F) {
        rtb_Saturation1_p_idx_2_o = 0.0F;
      } else {
        rtb_Saturation1_p_idx_2_o = rtb_Multiply1[0];
      }

      /* End of Saturate: '<S184>/Saturation4' */

      /* DataTypeConversion: '<S190>/Data Type Conversion' incorporates:
       *  Constant: '<S190>/Constant1'
       *  Gain: '<S190>/Gain1'
       *  Sum: '<S190>/Sum1'
       */
      u0_o = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
        rtb_Saturation1_p_idx_2_o), 4.2949673E+9F) + 1000U);

      /* Saturate: '<S184>/Saturation1' */
      if (u0_o > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[4] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_o < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[4] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[4] = u0_o;
      }

      /* DataTypeConversion: '<S184>/Data Type Conversion' incorporates:
       *  Bias: '<S184>/Bias1'
       */
      rtb_Saturation1_p_idx_2_o = fmodf(floorf(rtb_Saturation5_m[0] +
        CONTROL_PARAM.SERVO1_BIAS), 65536.0F);
      u0_o = (uint16_T)(rtb_Saturation1_p_idx_2_o < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_p_idx_2_o :
                        (int32_T)(uint16_T)rtb_Saturation1_p_idx_2_o);

      /* Saturate: '<S184>/Saturation1' */
      if (u0_o > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[5] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_o < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[5] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[5] = u0_o;
      }

      /* DataTypeConversion: '<S184>/Data Type Conversion1' incorporates:
       *  Bias: '<S184>/Bias2'
       */
      rtb_Saturation1_p_idx_2_o = fmodf(floorf(rtb_Saturation5_m[1] +
        CONTROL_PARAM.SERVO2_BIAS), 65536.0F);
      u0_o = (uint16_T)(rtb_Saturation1_p_idx_2_o < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_p_idx_2_o :
                        (int32_T)(uint16_T)rtb_Saturation1_p_idx_2_o);

      /* Saturate: '<S184>/Saturation1' */
      if (u0_o > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[6] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_o < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[6] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[6] = u0_o;
      }

      /* DataTypeConversion: '<S184>/Data Type Conversion2' incorporates:
       *  Bias: '<S184>/Bias3'
       */
      rtb_Saturation1_p_idx_2_o = fmodf(floorf(rtb_Saturation5_m[2] +
        CONTROL_PARAM.SERVO3_BIAS), 65536.0F);
      u0_o = (uint16_T)(rtb_Saturation1_p_idx_2_o < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_p_idx_2_o :
                        (int32_T)(uint16_T)rtb_Saturation1_p_idx_2_o);

      /* Saturate: '<S184>/Saturation1' */
      if (u0_o > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[7] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_o < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[7] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[7] = u0_o;
      }

      /* DataTypeConversion: '<S184>/Data Type Conversion3' incorporates:
       *  Bias: '<S184>/Bias4'
       */
      rtb_Saturation1_p_idx_2_o = fmodf(floorf(rtb_Saturation5_m[3] +
        CONTROL_PARAM.SERVO4_BIAS), 65536.0F);
      u0_o = (uint16_T)(rtb_Saturation1_p_idx_2_o < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_p_idx_2_o :
                        (int32_T)(uint16_T)rtb_Saturation1_p_idx_2_o);

      /* Saturate: '<S184>/Saturation1' */
      if (u0_o > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[8] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_o < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[8] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[8] = u0_o;
      }
      break;

     default:
      for (i_o = 0; i_o < 9; i_o++) {
        rtb_VariantMergeForOutportactua[i_o] = (uint16_T)fmodf(floorf
          (rtb_Saturation_k[i_o]), 65536.0F);
      }
      break;
    }

    /* End of MultiPortSwitch: '<S187>/Multiport Switch' */
  }

#endif

  /* End of Outputs for SubSystem: '<S9>/VTOL_Control_Allocation' */

  /* Outport: '<Root>/Control_Out' incorporates:
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   *  Reshape: '<S164>/Reshape'
   */
  Controller_Y.Control_Out.timestamp =
    Controller_DW.DiscreteTimeIntegrator_DSTATE_n;
  for (i = 0; i < 9; i++) {
    Controller_Y.Control_Out.actuator_cmd[i] = rtb_VariantMergeForOutportactua[i];
  }

  for (i = 0; i < 7; i++) {
    Controller_Y.Control_Out.actuator_cmd[i + 9] = 0U;
  }

  /* End of Outport: '<Root>/Control_Out' */

  /* Update for DiscreteIntegrator: '<S156>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S156>/Gain'
   *  Sum: '<S156>/Sum5'
   */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;
  Controller_DW.DiscreteTimeIntegrator5_DSTATE += (rtb_Divide_m_idx_0 -
    Controller_DW.DiscreteTimeIntegrator5_DSTATE) * 62.831852F * 0.002F;

  /* Update for DiscreteIntegrator: '<S152>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S152>/Gain'
   *  Sum: '<S152>/Sum5'
   */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_c = 0U;
  Controller_DW.DiscreteTimeIntegrator5_DSTAT_i += ((real32_T)
    rtb_MultiportSwitch_idx_1 - Controller_DW.DiscreteTimeIntegrator5_DSTAT_i) *
    6.28318548F * 0.002F;

  /* Update for DiscreteIntegrator: '<S151>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S151>/Gain'
   *  Sum: '<S151>/Sum5'
   */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_o = 0U;
  Controller_DW.DiscreteTimeIntegrator5_DSTAT_k += ((real32_T)
    rtb_MultiportSwitch_idx_0 - Controller_DW.DiscreteTimeIntegrator5_DSTAT_k) *
    6.28318548F * 0.002F;

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

  /* states (dwork) */
  (void) memset((void *)&Controller_DW, 0,
                sizeof(DW_Controller_T));

  /* external inputs */
  (void)memset(&Controller_U, 0, sizeof(ExtU_Controller_T));

  /* external outputs */
  Controller_Y.Control_Out = Controller_rtZControl_Out_Bus;

  /* Start for Enabled SubSystem: '<S2>/MC_Controller' */
  /* Start for Constant: '<S148>/Constant' */
  Controller_B.Constant = CONTROL_PARAM.MC_VEL_Z_I_MIN;

  /* End of Start for SubSystem: '<S2>/MC_Controller' */

  /* InitializeConditions for DiscreteIntegrator: '<S156>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S152>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_c = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S151>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_o = 1U;

  /* SystemInitialize for Enabled SubSystem: '<S2>/FW_Controller' */
  /* InitializeConditions for DiscreteIntegrator: '<S84>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_n = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S79>/ ' */
  Controller_DW._DSTATE = Controller_ConstB.Zero1;
  if (Controller_DW._DSTATE >= CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
    Controller_DW._DSTATE = CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
  } else {
    if (Controller_DW._DSTATE <= -CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
      Controller_DW._DSTATE = -CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
    }
  }

  Controller_DW._PrevResetState = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S79>/ ' */

  /* InitializeConditions for DiscreteIntegrator: '<S80>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_f = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_b = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S57>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0] =
    Controller_ConstB.Constant_c[0];
  if (Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0] >=
      CONTROL_PARAM.FW_RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0] =
      CONTROL_PARAM.FW_RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0] <=
        CONTROL_PARAM.FW_RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0] =
        CONTROL_PARAM.FW_RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1] =
    Controller_ConstB.Constant_c[1];
  if (Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1] >=
      CONTROL_PARAM.FW_RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1] =
      CONTROL_PARAM.FW_RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1] <=
        CONTROL_PARAM.FW_RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1] =
        CONTROL_PARAM.FW_RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2] =
    Controller_ConstB.Constant_c[2];
  if (Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2] >=
      CONTROL_PARAM.FW_RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2] =
      CONTROL_PARAM.FW_RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2] <=
        CONTROL_PARAM.FW_RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2] =
        CONTROL_PARAM.FW_RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRe_e = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S57>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S82>/ ' */
  Controller_DW._DSTATE_d = Controller_ConstB.Zero;
  if (Controller_DW._DSTATE_d >= 1.0F) {
    Controller_DW._DSTATE_d = 1.0F;
  } else {
    if (Controller_DW._DSTATE_d <= 0.0F) {
      Controller_DW._DSTATE_d = 0.0F;
    }
  }

  Controller_DW._PrevResetState_e = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S82>/ ' */

  /* InitializeConditions for DiscreteIntegrator: '<S83>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_h = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_d = 0;

  /* End of SystemInitialize for SubSystem: '<S2>/FW_Controller' */

  /* SystemInitialize for Enabled SubSystem: '<S2>/MC_Controller' */
  /* InitializeConditions for DiscreteIntegrator: '<S108>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S108>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S132>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_PrevRe_p = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S134>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S105>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_L_ck = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S110>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_k = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S127>/Integrator1' */
  Controller_DW.Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S132>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0] =
    Controller_ConstB.Constant_e;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0] >=
      CONTROL_PARAM.MC_VEL_XY_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0] =
      CONTROL_PARAM.MC_VEL_XY_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0] <=
        CONTROL_PARAM.MC_VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0] =
        CONTROL_PARAM.MC_VEL_XY_I_MIN;
    }
  }

  /* InitializeConditions for DiscreteIntegrator: '<S127>/Integrator' */
  Controller_DW.Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S127>/Integrator1' */
  Controller_DW.Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S132>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1] =
    Controller_ConstB.Constant_e;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1] >=
      CONTROL_PARAM.MC_VEL_XY_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1] =
      CONTROL_PARAM.MC_VEL_XY_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1] <=
        CONTROL_PARAM.MC_VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1] =
        CONTROL_PARAM.MC_VEL_XY_I_MIN;
    }
  }

  /* InitializeConditions for DiscreteIntegrator: '<S127>/Integrator' */
  Controller_DW.Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S145>/Integrator1' */
  Controller_DW.Integrator1_DSTATE_e = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S148>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_l = Controller_B.Constant;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_l >=
      CONTROL_PARAM.MC_VEL_Z_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_l = CONTROL_PARAM.MC_VEL_Z_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_l <=
        CONTROL_PARAM.MC_VEL_Z_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_l =
        CONTROL_PARAM.MC_VEL_Z_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRe_f = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S148>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S150>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 1U;
  Controller_DW.DiscreteTimeIntegrator1_Prev_ks = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S145>/Integrator' */
  Controller_DW.Integrator_DSTATE_j = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S2>/MC_Controller' */
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
