/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.724
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Sep 15 11:14:44 2025
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
                                        *   '<S148>/hover_throttle'
                                        *   '<S51>/FF'
                                        *   '<S70>/P_control'
                                        *   '<S71>/P_control'
                                        *   '<S72>/Kv'
                                        *   '<S129>/Saturation'
                                        *   '<S167>/Bias1'
                                        *   '<S167>/Bias2'
                                        *   '<S167>/Bias3'
                                        *   '<S167>/Bias4'
                                        *   '<S167>/Saturation1'
                                        *   '<S168>/Constant'
                                        *   '<S168>/Constant1'
                                        *   '<S168>/Saturation'
                                        *   '<S183>/Bias1'
                                        *   '<S183>/Bias2'
                                        *   '<S183>/Bias3'
                                        *   '<S183>/Bias4'
                                        *   '<S183>/Saturation1'
                                        *   '<S184>/Constant'
                                        *   '<S184>/Constant1'
                                        *   '<S184>/Saturation'
                                        *   '<S55>/trim_speed'
                                        *   '<S56>/trim_speed'
                                        *   '<S60>/Saturation'
                                        *   '<S78>/Gain'
                                        *   '<S79>/ '
                                        *   '<S79>/Gain3'
                                        *   '<S81>/Gain'
                                        *   '<S82>/Gain'
                                        *   '<S103>/Saturation'
                                        *   '<S103>/Saturation1'
                                        *   '<S103>/Saturation2'
                                        *   '<S139>/kd'
                                        *   '<S139>/Saturation'
                                        *   '<S140>/ki'
                                        *   '<S140>/Discrete-Time Integrator'
                                        *   '<S141>/kp'
                                        *   '<S155>/kd'
                                        *   '<S155>/Saturation'
                                        *   '<S156>/Constant'
                                        *   '<S156>/ki'
                                        *   '<S156>/Discrete-Time Integrator'
                                        *   '<S157>/kp'
                                        *   '<S172>/Constant1'
                                        *   '<S172>/Constant12'
                                        *   '<S172>/Constant2'
                                        *   '<S172>/Constant7'
                                        *   '<S181>/Bias'
                                        *   '<S181>/Bias1'
                                        *   '<S181>/Bias2'
                                        *   '<S181>/Bias3'
                                        *   '<S182>/Bias'
                                        *   '<S182>/Bias1'
                                        *   '<S182>/Bias2'
                                        *   '<S182>/Bias3'
                                        *   '<S187>/Constant1'
                                        *   '<S187>/Constant11'
                                        *   '<S187>/Constant12'
                                        *   '<S187>/Constant2'
                                        *   '<S187>/Constant7'
                                        *   '<S187>/Constant8'
                                        *   '<S193>/Bias'
                                        *   '<S193>/Bias1'
                                        *   '<S193>/Bias2'
                                        *   '<S193>/Bias3'
                                        *   '<S194>/Bias'
                                        *   '<S194>/Bias1'
                                        *   '<S194>/Bias2'
                                        *   '<S194>/Bias3'
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
                                        *   '<S105>/Gain'
                                        *   '<S105>/Gain1'
                                        *   '<S122>/Constant1'
                                        *   '<S122>/Constant2'
                                        *   '<S110>/gain1'
                                        *   '<S110>/gain2'
                                        *   '<S110>/gain3'
                                        *   '<S110>/Saturation'
                                        *   '<S111>/gain1'
                                        *   '<S111>/gain2'
                                        *   '<S111>/gain3'
                                        *   '<S111>/Discrete-Time Integrator'
                                        *   '<S112>/gain1'
                                        *   '<S112>/gain2'
                                        *   '<S112>/gain3'
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
 *    '<S168>/R_Remix'
 *    '<S184>/R_Remix'
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
  boolean_T rtb_Compare_m;
  real32_T rtb_Saturation1;
  boolean_T rtb_Compare_b;
  real32_T rtb_DiscreteTimeIntegrator1_a;
  real32_T rtb_Subtract3_g;
  real32_T rtb_VdotPg;
  real32_T rtb_Add3_e;
  real32_T rtb_a_k;
  boolean_T rtb_LogicalOperator_h;
  real32_T rtb_Ldot_err;
  real32_T rtb_Gain_c4;
  real32_T rtb_Saturation1_n;
  real32_T rtb_Add4_l;
  real32_T rtb_Square_m;
  real32_T rtb_MatrixConcatenate1[9];
  real32_T rtb_Multiply_ni[3];
  int32_T i;
  real32_T rtb_MatrixConcatenate1_0[3];
  int32_T rtb_MultiportSwitch_idx_0;
  int32_T rtb_MultiportSwitch_idx_1;
  real32_T rtb_TmpSignalConversionAtMult_0;
  real32_T rtb_TmpSignalConversionAtMult_1;
  real32_T rtb_TmpSignalConversionAtMult_2;
  real32_T rtb_Gain_hl_idx_2;
  real32_T rtb_Divide_aq_idx_0;
  real32_T rtb_Divide_aq_idx_3;
  real32_T rtb_Divide_aq_idx_1;
  real32_T rtb_Divide_aq_idx_2;
  real32_T rtb_Saturation_idx_0;
  real32_T rtb_MatrixConcatenate1_tmp;
  uint32_T tmp;

  /* RelationalOperator: '<S162>/Compare' incorporates:
   *  Constant: '<S162>/Constant'
   *  Inport: '<Root>/FMS_Out'
   */
  rtb_Compare = (Controller_U.FMS_Out.ext_state != 2);

  /* MultiPortSwitch: '<S6>/Multiport Switch' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S6>/Constant2'
   *  Constant: '<S6>/Constant6'
   *  Inport: '<Root>/FMS_Out'
   */
  switch (Controller_U.FMS_Out.ext_state) {
   case 0:
    rtb_MultiportSwitch_idx_0 = 0;
    rtb_MultiportSwitch_idx_1 = 1;
    break;

   case 1:
    rtb_MultiportSwitch_idx_0 = 0;
    rtb_MultiportSwitch_idx_1 = 1;
    break;

   case 2:
    rtb_MultiportSwitch_idx_0 = 1;
    rtb_MultiportSwitch_idx_1 = 0;
    break;

   case 3:
    rtb_MultiportSwitch_idx_0 = 0;
    rtb_MultiportSwitch_idx_1 = 1;
    break;

   default:
    rtb_MultiportSwitch_idx_0 = 0;
    rtb_MultiportSwitch_idx_1 = 1;
    break;
  }

  /* End of MultiPortSwitch: '<S6>/Multiport Switch' */

  /* DiscreteIntegrator: '<S160>/Discrete-Time Integrator5' */
  if (Controller_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    Controller_DW.DiscreteTimeIntegrator5_DSTATE = (real32_T)
      rtb_MultiportSwitch_idx_1;
  }

  /* DiscreteIntegrator: '<S159>/Discrete-Time Integrator5' */
  if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_o != 0) {
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_k = (real32_T)
      rtb_MultiportSwitch_idx_0;
  }

  /* RelationalOperator: '<S161>/Compare' incorporates:
   *  Constant: '<S161>/Constant'
   *  Inport: '<Root>/FMS_Out'
   */
  rtb_Compare_m = (Controller_U.FMS_Out.ext_state != 0);

  /* Outputs for Enabled SubSystem: '<S2>/FW_Controller' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  if (rtb_Compare_m) {
    if (!Controller_DW.FW_Controller_MODE) {
      /* InitializeConditions for DiscreteIntegrator: '<S87>/Discrete-Time Integrator5' */
      Controller_DW.DiscreteTimeIntegrator5_IC_LO_i = 1U;

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

    /* Relay: '<S11>/Relay' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    if (Controller_U.INS_Out.airspeed >= 10.0F) {
      Controller_DW.Relay_Mode = true;
    } else {
      if (Controller_U.INS_Out.airspeed <= 6.0F) {
        Controller_DW.Relay_Mode = false;
      }
    }

    /* SignalConversion: '<S74>/TmpSignal ConversionAtMultiplyInport2' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_TmpSignalConversionAtMult_0 = Controller_U.INS_Out.vn;
    rtb_TmpSignalConversionAtMult_1 = Controller_U.INS_Out.ve;
    rtb_TmpSignalConversionAtMult_2 = Controller_U.INS_Out.vd;

    /* S-Function (sfix_bitop): '<S11>/vel_valid' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  S-Function (sfix_bitop): '<S73>/Bitwise AND'
     *  S-Function (sfix_bitop): '<S74>/Bitwise AND'
     *  S-Function (sfix_bitop): '<S75>/Bitwise AND'
     */
    tmp = Controller_U.INS_Out.flag & 16U;

    /* Switch: '<S11>/Switch' incorporates:
     *  Constant: '<S86>/Constant'
     *  Inport: '<Root>/INS_Out'
     *  Logic: '<S11>/Logical Operator'
     *  Logic: '<S11>/Logical Operator1'
     *  Math: '<S11>/Square2'
     *  Math: '<S11>/Square3'
     *  Product: '<S11>/Multiply'
     *  RelationalOperator: '<S86>/Compare'
     *  Relay: '<S11>/Relay'
     *  S-Function (sfix_bitop): '<S11>/airspeed_valid'
     *  S-Function (sfix_bitop): '<S11>/vel_valid'
     *  Sqrt: '<S11>/Sqrt'
     *  Sum: '<S11>/Add'
     */
    if ((Controller_DW.Relay_Mode && ((Controller_U.INS_Out.flag & 512U) != 0U))
        || (tmp == 0U)) {
      rtb_Divide_aq_idx_0 = Controller_U.INS_Out.airspeed;
    } else {
      /* Sqrt: '<S94>/Sqrt' incorporates:
       *  Math: '<S94>/Square'
       *  Sum: '<S94>/Sum of Elements'
       */
      rtb_Square_m = sqrtf(((Controller_U.INS_Out.quat[0] *
        Controller_U.INS_Out.quat[0] + Controller_U.INS_Out.quat[1] *
        Controller_U.INS_Out.quat[1]) + Controller_U.INS_Out.quat[2] *
                            Controller_U.INS_Out.quat[2]) +
                           Controller_U.INS_Out.quat[3] *
                           Controller_U.INS_Out.quat[3]);

      /* Product: '<S90>/Divide' */
      rtb_Divide_aq_idx_0 = Controller_U.INS_Out.quat[0] / rtb_Square_m;
      rtb_Divide_aq_idx_1 = Controller_U.INS_Out.quat[1] / rtb_Square_m;
      rtb_Divide_aq_idx_2 = Controller_U.INS_Out.quat[2] / rtb_Square_m;
      rtb_Divide_aq_idx_3 = Controller_U.INS_Out.quat[3] / rtb_Square_m;

      /* Math: '<S93>/Square' incorporates:
       *  Math: '<S91>/Square'
       *  Math: '<S92>/Square'
       */
      rtb_Square_m = rtb_Divide_aq_idx_0 * rtb_Divide_aq_idx_0;

      /* Math: '<S93>/Square2' incorporates:
       *  Math: '<S91>/Square2'
       *  Math: '<S92>/Square2'
       */
      rtb_MatrixConcatenate1_tmp = rtb_Divide_aq_idx_2 * rtb_Divide_aq_idx_2;

      /* Math: '<S93>/Square1' incorporates:
       *  Math: '<S91>/Square1'
       *  Math: '<S92>/Square1'
       */
      rtb_Subtract3_g = rtb_Divide_aq_idx_1 * rtb_Divide_aq_idx_1;

      /* Math: '<S93>/Square3' incorporates:
       *  Math: '<S91>/Square3'
       *  Math: '<S92>/Square3'
       */
      rtb_Saturation1 = rtb_Divide_aq_idx_3 * rtb_Divide_aq_idx_3;

      /* Sum: '<S93>/Subtract' incorporates:
       *  Math: '<S93>/Square'
       *  Math: '<S93>/Square1'
       *  Math: '<S93>/Square2'
       *  Math: '<S93>/Square3'
       *  Sum: '<S93>/Add'
       *  Sum: '<S93>/Add1'
       */
      rtb_MatrixConcatenate1[8] = (rtb_Square_m + rtb_Saturation1) -
        (rtb_Subtract3_g + rtb_MatrixConcatenate1_tmp);

      /* Product: '<S93>/Multiply2' incorporates:
       *  Product: '<S92>/Multiply2'
       */
      rtb_VdotPg = rtb_Divide_aq_idx_2 * rtb_Divide_aq_idx_3;

      /* Product: '<S93>/Multiply3' incorporates:
       *  Product: '<S92>/Multiply3'
       */
      rtb_Ldot_err = rtb_Divide_aq_idx_0 * rtb_Divide_aq_idx_1;

      /* Gain: '<S93>/Gain1' incorporates:
       *  Product: '<S93>/Multiply2'
       *  Product: '<S93>/Multiply3'
       *  Sum: '<S93>/Add2'
       */
      rtb_MatrixConcatenate1[7] = (rtb_VdotPg + rtb_Ldot_err) * 2.0F;

      /* Product: '<S93>/Multiply' incorporates:
       *  Product: '<S91>/Multiply2'
       */
      rtb_Gain_c4 = rtb_Divide_aq_idx_1 * rtb_Divide_aq_idx_3;

      /* Product: '<S93>/Multiply1' incorporates:
       *  Product: '<S91>/Multiply3'
       */
      rtb_DiscreteTimeIntegrator1_a = rtb_Divide_aq_idx_0 * rtb_Divide_aq_idx_2;

      /* Gain: '<S93>/Gain' incorporates:
       *  Product: '<S93>/Multiply'
       *  Product: '<S93>/Multiply1'
       *  Sum: '<S93>/Subtract2'
       */
      rtb_MatrixConcatenate1[6] = (rtb_Gain_c4 - rtb_DiscreteTimeIntegrator1_a) *
        2.0F;

      /* Gain: '<S92>/Gain1' incorporates:
       *  Sum: '<S92>/Subtract1'
       */
      rtb_MatrixConcatenate1[5] = (rtb_VdotPg - rtb_Ldot_err) * 2.0F;

      /* Sum: '<S92>/Subtract' incorporates:
       *  Sum: '<S92>/Add'
       *  Sum: '<S92>/Add1'
       */
      rtb_MatrixConcatenate1[4] = (rtb_Square_m + rtb_MatrixConcatenate1_tmp) -
        (rtb_Subtract3_g + rtb_Saturation1);

      /* Product: '<S92>/Multiply' incorporates:
       *  Product: '<S91>/Multiply'
       */
      rtb_VdotPg = rtb_Divide_aq_idx_1 * rtb_Divide_aq_idx_2;

      /* Product: '<S92>/Multiply1' incorporates:
       *  Product: '<S91>/Multiply1'
       */
      rtb_Ldot_err = rtb_Divide_aq_idx_0 * rtb_Divide_aq_idx_3;

      /* Gain: '<S92>/Gain' incorporates:
       *  Product: '<S92>/Multiply'
       *  Product: '<S92>/Multiply1'
       *  Sum: '<S92>/Add3'
       */
      rtb_MatrixConcatenate1[3] = (rtb_VdotPg + rtb_Ldot_err) * 2.0F;

      /* Gain: '<S91>/Gain1' incorporates:
       *  Sum: '<S91>/Add2'
       */
      rtb_MatrixConcatenate1[2] = (rtb_Gain_c4 + rtb_DiscreteTimeIntegrator1_a) *
        2.0F;

      /* Gain: '<S91>/Gain' incorporates:
       *  Sum: '<S91>/Subtract1'
       */
      rtb_MatrixConcatenate1[1] = (rtb_VdotPg - rtb_Ldot_err) * 2.0F;

      /* Sum: '<S91>/Subtract' incorporates:
       *  Sum: '<S91>/Add'
       *  Sum: '<S91>/Add1'
       */
      rtb_MatrixConcatenate1[0] = (rtb_Square_m + rtb_Subtract3_g) -
        (rtb_MatrixConcatenate1_tmp + rtb_Saturation1);

      /* Product: '<S88>/Multiply' */
      for (i = 0; i < 3; i++) {
        rtb_MatrixConcatenate1_0[i] = rtb_MatrixConcatenate1[i + 6] *
          rtb_TmpSignalConversionAtMult_2 + (rtb_MatrixConcatenate1[i + 3] *
          rtb_TmpSignalConversionAtMult_1 + rtb_MatrixConcatenate1[i] *
          rtb_TmpSignalConversionAtMult_0);
      }

      /* End of Product: '<S88>/Multiply' */

      /* Signum: '<S88>/Sign' */
      if (rtb_MatrixConcatenate1_0[0] < 0.0F) {
        rtb_Square_m = -1.0F;
      } else if (rtb_MatrixConcatenate1_0[0] > 0.0F) {
        rtb_Square_m = 1.0F;
      } else {
        rtb_Square_m = rtb_MatrixConcatenate1_0[0];
      }

      /* End of Signum: '<S88>/Sign' */
      rtb_Divide_aq_idx_0 = sqrtf(Controller_U.INS_Out.vn *
        Controller_U.INS_Out.vn + Controller_U.INS_Out.ve *
        Controller_U.INS_Out.ve) * rtb_Square_m;
    }

    /* End of Switch: '<S11>/Switch' */

    /* Saturate: '<S11>/Saturation1' */
    if (rtb_Divide_aq_idx_0 > 100.0F) {
      rtb_Saturation1 = 100.0F;
    } else if (rtb_Divide_aq_idx_0 < 0.1F) {
      rtb_Saturation1 = 0.1F;
    } else {
      rtb_Saturation1 = rtb_Divide_aq_idx_0;
    }

    /* End of Saturate: '<S11>/Saturation1' */

    /* DiscreteIntegrator: '<S87>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_i != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j = rtb_Saturation1;
    }

    /* Switch: '<S61>/Switch' incorporates:
     *  Inport: '<Root>/FMS_Out'
     *  Logic: '<S61>/Logical Operator'
     *  RelationalOperator: '<S66>/Compare'
     */
    if ((Controller_U.FMS_Out.ctrl_mode == 3) || (Controller_U.FMS_Out.ctrl_mode
         == 4)) {
      rtb_Divide_aq_idx_0 = Controller_U.FMS_Out.phi_cmd;
    } else {
      /* Trigonometry: '<S48>/Atan' incorporates:
       *  Gain: '<S48>/g_force'
       */
      rtb_Divide_aq_idx_0 = atanf(0.101936802F * Controller_U.FMS_Out.ay_cmd);

      /* Saturate: '<S48>/Saturation' */
      if (rtb_Divide_aq_idx_0 > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_Divide_aq_idx_0 = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_Divide_aq_idx_0 < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
          rtb_Divide_aq_idx_0 = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
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
      rtb_Square_m = arm_cos_f32(-Controller_U.INS_Out.psi);
      rtb_MatrixConcatenate1[4] = rtb_Square_m;

      /* Trigonometry: '<S77>/Trigonometric Function2' incorporates:
       *  Gain: '<S76>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S77>/Trigonometric Function'
       */
      rtb_MatrixConcatenate1_tmp = arm_sin_f32(-Controller_U.INS_Out.psi);

      /* Gain: '<S77>/Gain' incorporates:
       *  Trigonometry: '<S77>/Trigonometric Function2'
       */
      rtb_MatrixConcatenate1[3] = -rtb_MatrixConcatenate1_tmp;

      /* SignalConversion: '<S77>/ConcatBufferAtVector Concatenate1In3' incorporates:
       *  Constant: '<S77>/Constant3'
       */
      rtb_MatrixConcatenate1[2] = 0.0F;

      /* Trigonometry: '<S77>/Trigonometric Function' */
      rtb_MatrixConcatenate1[1] = rtb_MatrixConcatenate1_tmp;

      /* Trigonometry: '<S77>/Trigonometric Function1' */
      rtb_MatrixConcatenate1[0] = rtb_Square_m;

      /* Product: '<S74>/Multiply' */
      for (i = 0; i < 3; i++) {
        rtb_Multiply_ni[i] = rtb_MatrixConcatenate1[i + 6] *
          rtb_TmpSignalConversionAtMult_2 + (rtb_MatrixConcatenate1[i + 3] *
          rtb_TmpSignalConversionAtMult_1 + rtb_MatrixConcatenate1[i] *
          rtb_TmpSignalConversionAtMult_0);
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
      rtb_Square_m = sqrtf(Controller_U.INS_Out.vn * Controller_U.INS_Out.vn +
                           Controller_U.INS_Out.ve * Controller_U.INS_Out.ve);

      /* Saturate: '<S73>/Saturation' incorporates:
       *  Sqrt: '<S73>/Sqrt'
       */
      if (rtb_Square_m > 100.0F) {
        rtb_Square_m = 100.0F;
      } else {
        if (rtb_Square_m < 8.0F) {
          rtb_Square_m = 8.0F;
        }
      }

      /* End of Saturate: '<S73>/Saturation' */

      /* DeadZone: '<S73>/Dead Zone' incorporates:
       *  Inport: '<Root>/INS_Out'
       */
      if (Controller_U.INS_Out.vd > 0.1F) {
        rtb_a_k = Controller_U.INS_Out.vd - 0.1F;
      } else if (Controller_U.INS_Out.vd >= -0.1F) {
        rtb_a_k = 0.0F;
      } else {
        rtb_a_k = Controller_U.INS_Out.vd - -0.1F;
      }

      /* End of DeadZone: '<S73>/Dead Zone' */
      rtb_Subtract3_g = atanf(1.0F / rtb_Square_m * -rtb_a_k);
    } else {
      rtb_Subtract3_g = Controller_U.INS_Out.theta;
    }

    /* End of Switch: '<S73>/Switch' */

    /* Product: '<S73>/Multiply1' */
    rtb_Subtract3_g *= rtb_DiscreteTimeIntegrator1_a;

    /* Saturate: '<S73>/Saturation1' */
    if (rtb_Subtract3_g > 0.785398185F) {
      rtb_Subtract3_g = 0.785398185F;
    } else {
      if (rtb_Subtract3_g < -0.785398185F) {
        rtb_Subtract3_g = -0.785398185F;
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
    rtb_VdotPg = 0.101936802F * Controller_DW.DiscreteTimeIntegrator5_DSTAT_f;

    /* Switch: '<S75>/Switch' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Math: '<S75>/Square'
     *  Math: '<S75>/Square1'
     *  Sqrt: '<S75>/Sqrt'
     *  Sum: '<S75>/Add'
     */
    if (tmp > 0U) {
      rtb_a_k = sqrtf(Controller_U.INS_Out.vn * Controller_U.INS_Out.vn +
                      Controller_U.INS_Out.ve * Controller_U.INS_Out.ve);
    } else {
      rtb_a_k = Controller_U.INS_Out.airspeed;
    }

    /* End of Switch: '<S75>/Switch' */

    /* Saturate: '<S75>/Saturation1' */
    if (rtb_a_k > 100.0F) {
      rtb_a_k = 100.0F;
    } else {
      if (rtb_a_k < 8.0F) {
        rtb_a_k = 8.0F;
      }
    }

    /* End of Saturate: '<S75>/Saturation1' */

    /* Product: '<S75>/Multiply1' incorporates:
     *  Gain: '<S75>/Gain'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S75>/Divide'
     *  Trigonometry: '<S75>/Asin'
     */
    rtb_DiscreteTimeIntegrator1_a *= atanf(-Controller_U.FMS_Out.w_cmd / rtb_a_k);

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
    rtb_DiscreteTimeIntegrator1_a -= rtb_Subtract3_g;

    /* Sum: '<S72>/Sum' incorporates:
     *  DiscreteIntegrator: '<S87>/Discrete-Time Integrator5'
     *  Gain: '<S72>/Gain'
     *  Gain: '<S72>/Kv'
     *  Inport: '<Root>/FMS_Out'
     *  Sum: '<S72>/Minus'
     */
    rtb_Add3_e = (Controller_U.FMS_Out.u_cmd -
                  Controller_DW.DiscreteTimeIntegrator5_DSTAT_j) *
      CONTROL_PARAM.FW_TECS_VEL_P * 0.101936802F - rtb_VdotPg;

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
      rtb_Saturation1_n = Controller_U.FMS_Out.theta_cmd;
    } else if (rtb_Compare_b) {
      /* Switch: '<S49>/Switch' incorporates:
       *  Constant: '<S49>/Constant'
       */
      rtb_Saturation1_n = 0.0F;
    } else {
      if (rtb_LogicalOperator_h) {
        /* Switch: '<S80>/Switch' incorporates:
         *  Gain: '<S80>/Gain1'
         *  Switch: '<S49>/Switch'
         */
        rtb_TmpSignalConversionAtMult_0 = 0.0F;
      } else {
        /* Switch: '<S80>/Switch' incorporates:
         *  Switch: '<S49>/Switch'
         */
        rtb_TmpSignalConversionAtMult_0 = rtb_Gain_c4;
      }

      /* Gain: '<S78>/Gain' incorporates:
       *  Switch: '<S49>/Switch'
       */
      rtb_TmpSignalConversionAtMult_0 *= CONTROL_PARAM.FW_TECS_PITCH_D;

      /* Saturate: '<S70>/Saturation1' incorporates:
       *  Switch: '<S49>/Switch'
       */
      if (rtb_TmpSignalConversionAtMult_0 > 0.3F) {
        rtb_TmpSignalConversionAtMult_0 = 0.3F;
      } else {
        if (rtb_TmpSignalConversionAtMult_0 < -0.3F) {
          rtb_TmpSignalConversionAtMult_0 = -0.3F;
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
      rtb_Saturation1_n = ((2.0F - CONTROL_PARAM.FW_TECS_RATIO) *
                           rtb_Subtract3_g - CONTROL_PARAM.FW_TECS_RATIO *
                           rtb_VdotPg) * CONTROL_PARAM.FW_TECS_PITCH_F +
        ((CONTROL_PARAM.FW_TECS_PITCH_P * rtb_Ldot_err + Controller_DW._DSTATE)
         + rtb_TmpSignalConversionAtMult_0);
    }

    /* End of Switch: '<S61>/Switch1' */

    /* Saturate: '<S62>/Saturation' */
    if (rtb_Divide_aq_idx_0 > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_TmpSignalConversionAtMult_0 = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else if (rtb_Divide_aq_idx_0 < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_TmpSignalConversionAtMult_0 = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      rtb_TmpSignalConversionAtMult_0 = rtb_Divide_aq_idx_0;
    }

    /* Reshape: '<S52>/Reshape' incorporates:
     *  Constant: '<S63>/Constant1'
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S63>/Multiply'
     *  Sum: '<S62>/Sum'
     */
    Controller_B.Reshape[0] = (rtb_TmpSignalConversionAtMult_0 -
      Controller_U.INS_Out.phi) * CONTROL_PARAM.FW_ROLL_P;

    /* Bias: '<S62>/Pitch Offset' */
    rtb_Square_m = rtb_Saturation1_n + CONTROL_PARAM.FW_PITCH_OFFSET;

    /* Saturate: '<S62>/Saturation' */
    if (rtb_Square_m > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Square_m = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_Square_m < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_Square_m = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      }
    }

    /* Reshape: '<S52>/Reshape' incorporates:
     *  Constant: '<S63>/Constant2'
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S63>/Multiply'
     *  Sum: '<S62>/Sum'
     */
    Controller_B.Reshape[1] = (rtb_Square_m - Controller_U.INS_Out.theta) *
      CONTROL_PARAM.FW_PITCH_P;

    /* Product: '<S65>/Divide' incorporates:
     *  Constant: '<S65>/Constant'
     *  DiscreteIntegrator: '<S87>/Discrete-Time Integrator5'
     */
    rtb_Square_m = 9.81F / Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;

    /* Saturate: '<S65>/Saturation' */
    if (rtb_Square_m > 1.0F) {
      rtb_Square_m = 1.0F;
    } else {
      if (rtb_Square_m < 0.2F) {
        rtb_Square_m = 0.2F;
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
    rtb_Square_m = tanf(rtb_Divide_aq_idx_0) * arm_cos_f32(rtb_Saturation1_n) *
      rtb_Square_m + Controller_U.FMS_Out.psi_rate_cmd;

    /* Saturate: '<S60>/Saturation' */
    if (rtb_Square_m > CONTROL_PARAM.FW_YAW_RATE_LIM) {
      /* Reshape: '<S52>/Reshape' */
      Controller_B.Reshape[2] = CONTROL_PARAM.FW_YAW_RATE_LIM;
    } else if (rtb_Square_m < -CONTROL_PARAM.FW_YAW_RATE_LIM) {
      /* Reshape: '<S52>/Reshape' */
      Controller_B.Reshape[2] = -CONTROL_PARAM.FW_YAW_RATE_LIM;
    } else {
      /* Reshape: '<S52>/Reshape' */
      Controller_B.Reshape[2] = rtb_Square_m;
    }

    /* End of Saturate: '<S60>/Saturation' */

    /* Sum: '<S53>/Add' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S53>/Multiply'
     *  Trigonometry: '<S53>/Sin1'
     */
    rtb_Divide_aq_idx_1 = Controller_B.Reshape[0] - arm_sin_f32
      (Controller_U.INS_Out.theta) * Controller_B.Reshape[2];

    /* Trigonometry: '<S53>/Sin' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_TmpSignalConversionAtMult_0 = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S53>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_TmpSignalConversionAtMult_1 = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Trigonometry: '<S53>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Square_m = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Sum: '<S53>/Add1' incorporates:
     *  Product: '<S53>/Multiply1'
     *  Product: '<S53>/Multiply3'
     *  Trigonometry: '<S53>/Cos'
     *  Trigonometry: '<S53>/Cos1'
     *  Trigonometry: '<S53>/Sin'
     */
    rtb_Divide_aq_idx_2 = rtb_TmpSignalConversionAtMult_0 *
      rtb_TmpSignalConversionAtMult_1 * Controller_B.Reshape[2] + rtb_Square_m *
      Controller_B.Reshape[1];

    /* Sum: '<S53>/Add2' incorporates:
     *  Product: '<S53>/Multiply4'
     *  Product: '<S53>/Multiply5'
     *  Trigonometry: '<S53>/Cos'
     *  Trigonometry: '<S53>/Cos1'
     *  Trigonometry: '<S53>/Sin'
     */
    rtb_Divide_aq_idx_3 = rtb_Square_m * rtb_TmpSignalConversionAtMult_1 *
      Controller_B.Reshape[2] - rtb_TmpSignalConversionAtMult_0 *
      Controller_B.Reshape[1];

    /* Sum: '<S51>/Minus2' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_TmpSignalConversionAtMult_0 = rtb_Divide_aq_idx_1 -
      Controller_U.INS_Out.p;
    rtb_TmpSignalConversionAtMult_1 = rtb_Divide_aq_idx_2 -
      Controller_U.INS_Out.q;
    rtb_TmpSignalConversionAtMult_2 = rtb_Divide_aq_idx_3 -
      Controller_U.INS_Out.r;

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
    rtb_Saturation1_n = (rtb_DiscreteTimeIntegrator1_a -
                         Controller_DW.DiscreteTimeIntegrator1_DSTA_nm) *
      188.49556F;

    /* Switch: '<S12>/Switch' incorporates:
     *  Constant: '<S12>/Constant2'
     *  Constant: '<S50>/Constant'
     *  Constant: '<S95>/Constant'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S95>/Compare'
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
       *  DiscreteIntegrator: '<S87>/Discrete-Time Integrator5'
       *  Math: '<S55>/Square'
       *  Math: '<S55>/Square1'
       */
      rtb_a_k = CONTROL_PARAM.FW_AIRSPEED_TRIM * CONTROL_PARAM.FW_AIRSPEED_TRIM /
        (Controller_DW.DiscreteTimeIntegrator5_DSTAT_j *
         Controller_DW.DiscreteTimeIntegrator5_DSTAT_j);

      /* Saturate: '<S55>/Saturation' */
      if (rtb_a_k > 1.0F) {
        rtb_a_k = 1.0F;
      } else {
        if (rtb_a_k < 0.0F) {
          rtb_a_k = 0.0F;
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
      rtb_Square_m = (CONTROL_PARAM.FW_ROLL_RATE_P *
                      rtb_TmpSignalConversionAtMult_0 +
                      Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0]) *
        rtb_a_k;
      rtb_Divide_aq_idx_0 = (CONTROL_PARAM.FW_PITCH_RATE_P *
        rtb_TmpSignalConversionAtMult_1 +
        Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1]) * rtb_a_k;
      rtb_MatrixConcatenate1_tmp = (CONTROL_PARAM.FW_YAW_RATE_P *
        rtb_TmpSignalConversionAtMult_2 +
        Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2]) * rtb_a_k;

      /* Product: '<S56>/Divide' incorporates:
       *  Constant: '<S56>/trim_speed'
       *  DiscreteIntegrator: '<S87>/Discrete-Time Integrator5'
       */
      rtb_a_k = CONTROL_PARAM.FW_AIRSPEED_TRIM /
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;

      /* Saturate: '<S56>/Saturation' */
      if (rtb_a_k > 1.0F) {
        rtb_a_k = 1.0F;
      } else {
        if (rtb_a_k < 0.0F) {
          rtb_a_k = 0.0F;
        }
      }

      /* End of Saturate: '<S56>/Saturation' */

      /* Product: '<S51>/Multiply1' incorporates:
       *  Gain: '<S51>/FF'
       */
      rtb_Add3_e = CONTROL_PARAM.FW_FF * rtb_Divide_aq_idx_1 * rtb_a_k;

      /* Saturate: '<S51>/FF_limit' */
      if (rtb_Add3_e > 0.3F) {
        rtb_Add3_e = 0.3F;
      } else {
        if (rtb_Add3_e < -0.3F) {
          rtb_Add3_e = -0.3F;
        }
      }

      /* Saturate: '<S51>/PI_limit' */
      if (rtb_Square_m > 1.0F) {
        rtb_Square_m = 1.0F;
      } else {
        if (rtb_Square_m < -1.0F) {
          rtb_Square_m = -1.0F;
        }
      }

      /* Sum: '<S51>/Add' */
      rtb_Divide_aq_idx_1 = rtb_Add3_e + rtb_Square_m;

      /* Product: '<S51>/Multiply1' incorporates:
       *  Gain: '<S51>/FF'
       */
      rtb_Square_m = CONTROL_PARAM.FW_FF * rtb_Divide_aq_idx_2 * rtb_a_k;

      /* Saturate: '<S51>/FF_limit' */
      if (rtb_Square_m > 0.3F) {
        rtb_Square_m = 0.3F;
      } else {
        if (rtb_Square_m < -0.3F) {
          rtb_Square_m = -0.3F;
        }
      }

      /* Saturate: '<S51>/PI_limit' */
      if (rtb_Divide_aq_idx_0 > 1.0F) {
        rtb_Divide_aq_idx_0 = 1.0F;
      } else {
        if (rtb_Divide_aq_idx_0 < -1.0F) {
          rtb_Divide_aq_idx_0 = -1.0F;
        }
      }

      /* Sum: '<S51>/Add' */
      rtb_Divide_aq_idx_2 = rtb_Square_m + rtb_Divide_aq_idx_0;

      /* Product: '<S51>/Multiply1' incorporates:
       *  Gain: '<S51>/FF'
       */
      rtb_Square_m = CONTROL_PARAM.FW_FF * rtb_Divide_aq_idx_3 * rtb_a_k;

      /* Saturate: '<S51>/FF_limit' */
      if (rtb_Square_m > 0.3F) {
        rtb_Square_m = 0.3F;
      } else {
        if (rtb_Square_m < -0.3F) {
          rtb_Square_m = -0.3F;
        }
      }

      /* Saturate: '<S51>/PI_limit' */
      if (rtb_MatrixConcatenate1_tmp > 1.0F) {
        rtb_MatrixConcatenate1_tmp = 1.0F;
      } else {
        if (rtb_MatrixConcatenate1_tmp < -1.0F) {
          rtb_MatrixConcatenate1_tmp = -1.0F;
        }
      }

      /* Sum: '<S51>/Add' */
      rtb_Divide_aq_idx_3 = rtb_Square_m + rtb_MatrixConcatenate1_tmp;

      /* Switch: '<S50>/Switch' incorporates:
       *  Bias: '<S50>/Bias'
       *  Constant: '<S85>/Constant'
       *  Gain: '<S50>/Gain'
       *  RelationalOperator: '<S85>/Compare'
       *  Switch: '<S83>/Switch'
       */
      if (Controller_U.FMS_Out.ctrl_mode <= 3) {
        rtb_a_k = 0.000999987125F * (real32_T)Controller_U.FMS_Out.throttle_cmd
          + -1.0F;
      } else {
        if (Controller_U.FMS_Out.reset > 0) {
          /* Switch: '<S83>/Switch' incorporates:
           *  Gain: '<S83>/Gain1'
           */
          rtb_a_k = 0.0F;
        } else {
          /* Switch: '<S83>/Switch' */
          rtb_a_k = rtb_Saturation1_n;
        }

        /* Gain: '<S81>/Gain' */
        rtb_a_k *= CONTROL_PARAM.FW_TECS_THOR_D;

        /* Saturate: '<S71>/Saturation1' */
        if (rtb_a_k > 0.3F) {
          rtb_a_k = 0.3F;
        } else {
          if (rtb_a_k < -0.3F) {
            rtb_a_k = -0.3F;
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
        rtb_a_k = ((CONTROL_PARAM.FW_TECS_THOR_P * rtb_DiscreteTimeIntegrator1_a
                    + Controller_DW._DSTATE_d) + rtb_a_k) + (rtb_Subtract3_g +
          rtb_VdotPg) * CONTROL_PARAM.FW_TECS_THOR_FF;

        /* Saturate: '<S50>/Saturation' */
        if (rtb_a_k > 1.0F) {
          rtb_a_k = 1.0F;
        } else {
          if (rtb_a_k < -1.0F) {
            rtb_a_k = -1.0F;
          }
        }

        /* End of Saturate: '<S50>/Saturation' */
      }

      /* End of Switch: '<S50>/Switch' */

      /* Saturate: '<S10>/Saturation1' */
      if (rtb_Divide_aq_idx_1 > 1.0F) {
        Controller_B.Switch[0] = 1.0F;
      } else if (rtb_Divide_aq_idx_1 < -1.0F) {
        Controller_B.Switch[0] = -1.0F;
      } else {
        Controller_B.Switch[0] = rtb_Divide_aq_idx_1;
      }

      if (rtb_Divide_aq_idx_2 > 1.0F) {
        Controller_B.Switch[1] = 1.0F;
      } else if (rtb_Divide_aq_idx_2 < -1.0F) {
        Controller_B.Switch[1] = -1.0F;
      } else {
        Controller_B.Switch[1] = rtb_Divide_aq_idx_2;
      }

      if (rtb_Divide_aq_idx_3 > 1.0F) {
        Controller_B.Switch[2] = 1.0F;
      } else if (rtb_Divide_aq_idx_3 < -1.0F) {
        Controller_B.Switch[2] = -1.0F;
      } else {
        Controller_B.Switch[2] = rtb_Divide_aq_idx_3;
      }

      /* End of Saturate: '<S10>/Saturation1' */

      /* Saturate: '<S50>/Saturation2' */
      if (rtb_a_k > 1.0F) {
        Controller_B.Switch[3] = 1.0F;
      } else {
        Controller_B.Switch[3] = rtb_a_k;
      }

      Controller_B.Switch[4] = 0.0F;
      Controller_B.Switch[5] = 0.0F;
    }

    /* End of Switch: '<S12>/Switch' */

    /* Product: '<S4>/Multiply' incorporates:
     *  DiscreteIntegrator: '<S159>/Discrete-Time Integrator5'
     */
    Controller_B.Multiply_c[0] = Controller_B.Switch[0] *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_k;
    Controller_B.Multiply_c[1] = Controller_B.Switch[1] *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_k;
    Controller_B.Multiply_c[2] = Controller_B.Switch[2] *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_k;

    /* Update for DiscreteIntegrator: '<S87>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S87>/Gain'
     *  Sum: '<S87>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_i = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_j += (rtb_Saturation1 -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j) * 62.831852F * 0.002F;

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
      CONTROL_PARAM.FW_ROLL_RATE_I * rtb_TmpSignalConversionAtMult_0 * 0.002F;
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
      CONTROL_PARAM.FW_PITCH_RATE_I * rtb_TmpSignalConversionAtMult_1 * 0.002F;
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
      CONTROL_PARAM.FW_YAW_RATE_I * rtb_TmpSignalConversionAtMult_2 * 0.002F;
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
    Controller_DW.DiscreteTimeIntegrator1_DSTA_nm += 0.002F * rtb_Saturation1_n;
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
      /* InitializeConditions for DiscreteIntegrator: '<S117>/Integrator1' */
      Controller_DW.Integrator1_DSTATE[0] = 0.0F;
      Controller_DW.Integrator1_DSTATE[1] = 0.0F;
      Controller_DW.Integrator1_DSTATE[2] = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S135>/Integrator1' */
      Controller_DW.Integrator1_DSTATE_e[0] = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S140>/Discrete-Time Integrator' */
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
        Controller_ConstB.Constant;
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] >=
          CONTROL_PARAM.MC_VEL_XY_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
          CONTROL_PARAM.MC_VEL_XY_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] <=
            CONTROL_PARAM.MC_VEL_XY_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
            CONTROL_PARAM.MC_VEL_XY_I_MIN;
        }
      }

      /* InitializeConditions for DiscreteIntegrator: '<S135>/Integrator1' */
      Controller_DW.Integrator1_DSTATE_e[1] = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S140>/Discrete-Time Integrator' */
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
        Controller_ConstB.Constant;
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] >=
          CONTROL_PARAM.MC_VEL_XY_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
          CONTROL_PARAM.MC_VEL_XY_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] <=
            CONTROL_PARAM.MC_VEL_XY_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
            CONTROL_PARAM.MC_VEL_XY_I_MIN;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_PrevRese = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S142>/Discrete-Time Integrator1' */
      Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S117>/Integrator' */
      Controller_DW.Integrator_DSTATE[0] = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S111>/Discrete-Time Integrator' */
      Controller_DW.DiscreteTimeIntegrator_DSTATE_b[0] =
        Controller_ConstB.Constant_a[0];
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_b[0] >=
          CONTROL_PARAM.MC_RATE_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_b[0] =
          CONTROL_PARAM.MC_RATE_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_b[0] <=
            CONTROL_PARAM.MC_RATE_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_b[0] =
            CONTROL_PARAM.MC_RATE_I_MIN;
        }
      }

      /* InitializeConditions for DiscreteIntegrator: '<S117>/Integrator' */
      Controller_DW.Integrator_DSTATE[1] = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S111>/Discrete-Time Integrator' */
      Controller_DW.DiscreteTimeIntegrator_DSTATE_b[1] =
        Controller_ConstB.Constant_a[1];
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_b[1] >=
          CONTROL_PARAM.MC_RATE_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_b[1] =
          CONTROL_PARAM.MC_RATE_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_b[1] <=
            CONTROL_PARAM.MC_RATE_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_b[1] =
            CONTROL_PARAM.MC_RATE_I_MIN;
        }
      }

      /* InitializeConditions for DiscreteIntegrator: '<S117>/Integrator' */
      Controller_DW.Integrator_DSTATE[2] = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S111>/Discrete-Time Integrator' */
      Controller_DW.DiscreteTimeIntegrator_DSTATE_b[2] =
        Controller_ConstB.Constant_a[2];
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_b[2] >=
          CONTROL_PARAM.MC_RATE_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_b[2] =
          CONTROL_PARAM.MC_RATE_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_b[2] <=
            CONTROL_PARAM.MC_RATE_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_b[2] =
            CONTROL_PARAM.MC_RATE_I_MIN;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_PrevRe_d = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S108>/Discrete-Time Integrator5' */
      Controller_DW.DiscreteTimeIntegrator5_IC_LO_c = 1U;

      /* InitializeConditions for DiscreteIntegrator: '<S113>/Discrete-Time Integrator1' */
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevR_k = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S135>/Integrator' */
      Controller_DW.Integrator_DSTATE_l[0] = 0.0F;
      Controller_DW.Integrator_DSTATE_l[1] = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S153>/Integrator1' */
      Controller_DW.Integrator1_DSTATE_eq = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S156>/Discrete-Time Integrator' */
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

      /* End of InitializeConditions for DiscreteIntegrator: '<S156>/Discrete-Time Integrator' */

      /* InitializeConditions for DiscreteIntegrator: '<S158>/Discrete-Time Integrator1' */
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 1U;
      Controller_DW.DiscreteTimeIntegrator1_Prev_ks = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S153>/Integrator' */
      Controller_DW.Integrator_DSTATE_j = 0.0F;
      Controller_DW.MC_Controller_MODE = true;
    }

    /* Trigonometry: '<S137>/Trigonometric Function1' incorporates:
     *  Gain: '<S136>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1[0] = arm_cos_f32(-Controller_U.INS_Out.psi);

    /* Trigonometry: '<S137>/Trigonometric Function' incorporates:
     *  Gain: '<S136>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1[1] = arm_sin_f32(-Controller_U.INS_Out.psi);

    /* SignalConversion: '<S137>/ConcatBufferAtVector Concatenate1In3' incorporates:
     *  Constant: '<S137>/Constant3'
     */
    rtb_MatrixConcatenate1[2] = 0.0F;

    /* Gain: '<S137>/Gain' incorporates:
     *  Gain: '<S136>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S137>/Trigonometric Function2'
     */
    rtb_MatrixConcatenate1[3] = -arm_sin_f32(-Controller_U.INS_Out.psi);

    /* Trigonometry: '<S137>/Trigonometric Function3' incorporates:
     *  Gain: '<S136>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1[4] = arm_cos_f32(-Controller_U.INS_Out.psi);

    /* SignalConversion: '<S137>/ConcatBufferAtVector Concatenate2In3' incorporates:
     *  Constant: '<S137>/Constant4'
     */
    rtb_MatrixConcatenate1[5] = 0.0F;

    /* SignalConversion: '<S137>/ConcatBufferAtVector ConcatenateIn3' */
    rtb_MatrixConcatenate1[6] = Controller_ConstB.VectorConcatenate3[0];
    rtb_MatrixConcatenate1[7] = Controller_ConstB.VectorConcatenate3[1];
    rtb_MatrixConcatenate1[8] = Controller_ConstB.VectorConcatenate3[2];

    /* Product: '<S134>/Multiply' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  SignalConversion: '<S134>/TmpSignal ConversionAtMultiplyInport2'
     */
    for (i = 0; i < 3; i++) {
      rtb_MatrixConcatenate1_0[i] = rtb_MatrixConcatenate1[i + 3] *
        Controller_U.INS_Out.ve + rtb_MatrixConcatenate1[i] *
        Controller_U.INS_Out.vn;
    }

    /* End of Product: '<S134>/Multiply' */

    /* Sum: '<S131>/Sum' incorporates:
     *  DiscreteIntegrator: '<S135>/Integrator1'
     */
    rtb_TmpSignalConversionAtMult_2 = Controller_DW.Integrator1_DSTATE_e[0] -
      rtb_MatrixConcatenate1_0[0];
    rtb_Saturation1 = Controller_DW.Integrator1_DSTATE_e[1] -
      rtb_MatrixConcatenate1_0[1];

    /* Logic: '<S99>/Logical Operator' incorporates:
     *  Constant: '<S130>/Constant'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S130>/Compare'
     */
    rtb_Compare_b = ((Controller_U.FMS_Out.reset != 0) ||
                     (Controller_U.FMS_Out.ext_state != 0));

    /* DiscreteIntegrator: '<S140>/Discrete-Time Integrator' */
    if (rtb_Compare_b || (Controller_DW.DiscreteTimeIntegrator_PrevRese != 0)) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
        Controller_ConstB.Constant;
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] >=
          CONTROL_PARAM.MC_VEL_XY_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
          CONTROL_PARAM.MC_VEL_XY_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] <=
            CONTROL_PARAM.MC_VEL_XY_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
            CONTROL_PARAM.MC_VEL_XY_I_MIN;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
        Controller_ConstB.Constant;
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] >=
          CONTROL_PARAM.MC_VEL_XY_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
          CONTROL_PARAM.MC_VEL_XY_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] <=
            CONTROL_PARAM.MC_VEL_XY_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
            CONTROL_PARAM.MC_VEL_XY_I_MIN;
        }
      }
    }

    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] >=
        CONTROL_PARAM.MC_VEL_XY_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
        CONTROL_PARAM.MC_VEL_XY_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] <=
          CONTROL_PARAM.MC_VEL_XY_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
          CONTROL_PARAM.MC_VEL_XY_I_MIN;
      }
    }

    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] >=
        CONTROL_PARAM.MC_VEL_XY_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
        CONTROL_PARAM.MC_VEL_XY_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] <=
          CONTROL_PARAM.MC_VEL_XY_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
          CONTROL_PARAM.MC_VEL_XY_I_MIN;
      }
    }

    /* DiscreteIntegrator: '<S142>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] =
        rtb_TmpSignalConversionAtMult_2;
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] = rtb_Saturation1;
    }

    if (rtb_Compare_b || (Controller_DW.DiscreteTimeIntegrator1_PrevRes != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] =
        rtb_TmpSignalConversionAtMult_2;
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] = rtb_Saturation1;
    }

    /* Gain: '<S142>/Gain' incorporates:
     *  DiscreteIntegrator: '<S142>/Discrete-Time Integrator1'
     *  Sum: '<S142>/Sum5'
     */
    rtb_VdotPg = (rtb_TmpSignalConversionAtMult_2 -
                  Controller_DW.DiscreteTimeIntegrator1_DSTATE[0]) * 62.831852F;
    rtb_Ldot_err = (rtb_Saturation1 -
                    Controller_DW.DiscreteTimeIntegrator1_DSTATE[1]) *
      62.831852F;

    /* Switch: '<S142>/Switch' incorporates:
     *  Gain: '<S142>/Gain1'
     */
    if (rtb_Compare_b) {
      rtb_Saturation1_n = 0.0F;
      rtb_Subtract3_g = 0.0F;
    } else {
      rtb_Saturation1_n = rtb_VdotPg;
      rtb_Subtract3_g = rtb_Ldot_err;
    }

    /* End of Switch: '<S142>/Switch' */

    /* Product: '<S139>/Multiply' incorporates:
     *  Constant: '<S139>/kd'
     */
    rtb_TmpSignalConversionAtMult_0 = CONTROL_PARAM.MC_VEL_XY_D *
      rtb_Saturation1_n;

    /* Saturate: '<S139>/Saturation' */
    if (rtb_TmpSignalConversionAtMult_0 > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
      rtb_TmpSignalConversionAtMult_0 = CONTROL_PARAM.MC_VEL_XY_D_MAX;
    } else {
      if (rtb_TmpSignalConversionAtMult_0 < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
        rtb_TmpSignalConversionAtMult_0 = CONTROL_PARAM.MC_VEL_XY_D_MIN;
      }
    }

    /* Product: '<S139>/Multiply' incorporates:
     *  Constant: '<S139>/kd'
     */
    rtb_Saturation1_n = rtb_TmpSignalConversionAtMult_0;
    rtb_TmpSignalConversionAtMult_0 = CONTROL_PARAM.MC_VEL_XY_D *
      rtb_Subtract3_g;

    /* Saturate: '<S139>/Saturation' */
    if (rtb_TmpSignalConversionAtMult_0 > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
      rtb_TmpSignalConversionAtMult_0 = CONTROL_PARAM.MC_VEL_XY_D_MAX;
    } else {
      if (rtb_TmpSignalConversionAtMult_0 < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
        rtb_TmpSignalConversionAtMult_0 = CONTROL_PARAM.MC_VEL_XY_D_MIN;
      }
    }

    /* Switch: '<S133>/Switch' incorporates:
     *  Constant: '<S141>/kp'
     *  Constant: '<S143>/Constant'
     *  Constant: '<S145>/Constant'
     *  Constant: '<S146>/Constant'
     *  DiscreteIntegrator: '<S140>/Discrete-Time Integrator'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S141>/Multiply'
     *  Product: '<S144>/Multiply2'
     *  Product: '<S144>/Multiply3'
     *  RelationalOperator: '<S143>/Compare'
     *  RelationalOperator: '<S145>/Compare'
     *  RelationalOperator: '<S146>/Compare'
     *  S-Function (sfix_bitop): '<S144>/cmd_ax valid'
     *  S-Function (sfix_bitop): '<S144>/cmd_ay valid'
     *  S-Function (sfix_bitop): '<S144>/cmd_u valid'
     *  S-Function (sfix_bitop): '<S144>/cmd_v valid'
     *  Sum: '<S132>/Add'
     *  Sum: '<S144>/Sum1'
     */
    if (Controller_U.FMS_Out.ctrl_mode == 6) {
      rtb_Saturation1_n = ((Controller_U.FMS_Out.cmd_mask & 64) > 0 ?
                           (CONTROL_PARAM.MC_VEL_XY_P *
                            rtb_TmpSignalConversionAtMult_2 +
                            Controller_DW.DiscreteTimeIntegrator_DSTATE[0]) +
                           rtb_Saturation1_n : 0.0F) +
        ((Controller_U.FMS_Out.cmd_mask & 512) > 0 ? Controller_U.FMS_Out.ax_cmd
         : 0.0F);
      rtb_Subtract3_g = ((Controller_U.FMS_Out.cmd_mask & 128) > 0 ?
                         (CONTROL_PARAM.MC_VEL_XY_P * rtb_Saturation1 +
                          Controller_DW.DiscreteTimeIntegrator_DSTATE[1]) +
                         rtb_TmpSignalConversionAtMult_0 : 0.0F) +
        ((Controller_U.FMS_Out.cmd_mask & 1024) > 0 ?
         Controller_U.FMS_Out.ay_cmd : 0.0F);
    } else {
      rtb_Saturation1_n += CONTROL_PARAM.MC_VEL_XY_P *
        rtb_TmpSignalConversionAtMult_2 +
        Controller_DW.DiscreteTimeIntegrator_DSTATE[0];
      rtb_Subtract3_g = (CONTROL_PARAM.MC_VEL_XY_P * rtb_Saturation1 +
                         Controller_DW.DiscreteTimeIntegrator_DSTATE[1]) +
        rtb_TmpSignalConversionAtMult_0;
    }

    /* End of Switch: '<S133>/Switch' */

    /* Trigonometry: '<S129>/Atan' incorporates:
     *  Constant: '<S129>/g'
     *  Gain: '<S129>/Gain1'
     *  Gain: '<S129>/gain'
     *  Product: '<S129>/Divide'
     */
    rtb_Square_m = atanf(1.1F * rtb_Subtract3_g / 9.8055F);
    rtb_Subtract3_g = atanf(1.1F * -rtb_Saturation1_n / 9.8055F);

    /* Switch: '<S103>/Switch' incorporates:
     *  Constant: '<S116>/Constant'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S116>/Compare'
     */
    if (Controller_U.FMS_Out.ext_state == 0) {
      /* Switch: '<S120>/Switch' incorporates:
       *  Constant: '<S127>/Constant'
       *  Logic: '<S120>/Logical Operator'
       *  RelationalOperator: '<S126>/Compare'
       *  RelationalOperator: '<S127>/Compare'
       *  Saturate: '<S129>/Saturation'
       *  Switch: '<S120>/Switch1'
       */
      if ((Controller_U.FMS_Out.ctrl_mode == 3) ||
          (Controller_U.FMS_Out.ctrl_mode == 4)) {
        rtb_Saturation1_n = Controller_U.FMS_Out.phi_cmd;
        rtb_Subtract3_g = Controller_U.FMS_Out.theta_cmd;
      } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
        /* Switch: '<S128>/Switch' incorporates:
         *  S-Function (sfix_bitop): '<S128>/cmd_phi valid'
         *  S-Function (sfix_bitop): '<S128>/cmd_theta valid'
         *  Saturate: '<S129>/Saturation'
         *  Switch: '<S120>/Switch1'
         */
        if ((Controller_U.FMS_Out.cmd_mask & 8) > 0) {
          rtb_Saturation1_n = Controller_U.FMS_Out.phi_cmd;
        } else if (rtb_Square_m > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Saturate: '<S129>/Saturation' */
          rtb_Saturation1_n = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        } else if (rtb_Square_m < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Saturate: '<S129>/Saturation' */
          rtb_Saturation1_n = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        } else {
          rtb_Saturation1_n = rtb_Square_m;
        }

        if ((Controller_U.FMS_Out.cmd_mask & 16) > 0) {
          rtb_Subtract3_g = Controller_U.FMS_Out.theta_cmd;
        } else if (rtb_Subtract3_g > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Saturate: '<S129>/Saturation' */
          rtb_Subtract3_g = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        } else {
          if (rtb_Subtract3_g < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
            /* Saturate: '<S129>/Saturation' */
            rtb_Subtract3_g = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
          }
        }

        /* End of Switch: '<S128>/Switch' */
      } else {
        if (rtb_Square_m > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Saturate: '<S129>/Saturation' incorporates:
           *  Switch: '<S120>/Switch1'
           */
          rtb_Saturation1_n = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        } else if (rtb_Square_m < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Saturate: '<S129>/Saturation' incorporates:
           *  Switch: '<S120>/Switch1'
           */
          rtb_Saturation1_n = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        } else {
          /* Switch: '<S120>/Switch1' incorporates:
           *  Saturate: '<S129>/Saturation'
           */
          rtb_Saturation1_n = rtb_Square_m;
        }

        /* Saturate: '<S129>/Saturation' */
        if (rtb_Subtract3_g > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Switch: '<S120>/Switch1' */
          rtb_Subtract3_g = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        } else {
          if (rtb_Subtract3_g < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
            /* Switch: '<S120>/Switch1' */
            rtb_Subtract3_g = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
          }
        }
      }

      /* End of Switch: '<S120>/Switch' */

      /* Sum: '<S121>/Sum' incorporates:
       *  Inport: '<Root>/INS_Out'
       */
      rtb_TmpSignalConversionAtMult_0 = rtb_Saturation1_n -
        Controller_U.INS_Out.phi;

      /* Product: '<S124>/Divide1' incorporates:
       *  Abs: '<S124>/Abs'
       *  Constant: '<S124>/const2'
       */
      rtb_a_k = fabsf(rtb_TmpSignalConversionAtMult_0) / 0.002F;

      /* Gain: '<S124>/Gain3' */
      rtb_DiscreteTimeIntegrator1_a = -rtb_a_k;

      /* Product: '<S124>/Divide' incorporates:
       *  Constant: '<S122>/Constant1'
       *  Constant: '<S124>/const1'
       *  Math: '<S124>/Square'
       *  SignalConversion: '<S124>/TmpSignal ConversionAtSquareInport1'
       */
      rtb_TmpSignalConversionAtMult_1 = 9.5993F / (CONTROL_PARAM.MC_ROLL_P *
        CONTROL_PARAM.MC_ROLL_P);

      /* Signum: '<S124>/Sign' */
      if (rtb_TmpSignalConversionAtMult_0 < 0.0F) {
        rtb_Square_m = -1.0F;
      } else if (rtb_TmpSignalConversionAtMult_0 > 0.0F) {
        rtb_Square_m = 1.0F;
      } else {
        rtb_Square_m = rtb_TmpSignalConversionAtMult_0;
      }

      /* Switch: '<S124>/Switch' incorporates:
       *  Constant: '<S122>/Constant1'
       *  Gain: '<S124>/Gain1'
       *  Gain: '<S124>/Gain2'
       *  Logic: '<S124>/Logical Operator'
       *  Product: '<S124>/Multiply'
       *  Product: '<S124>/Multiply1'
       *  Product: '<S124>/Multiply2'
       *  Product: '<S124>/Multiply3'
       *  RelationalOperator: '<S124>/Relational Operator'
       *  RelationalOperator: '<S124>/Relational Operator2'
       *  SignalConversion: '<S124>/TmpSignal ConversionAtSquareInport1'
       *  Sqrt: '<S124>/Sqrt'
       *  Sum: '<S124>/Subtract'
       */
      if ((rtb_TmpSignalConversionAtMult_0 <= rtb_TmpSignalConversionAtMult_1) &&
          (rtb_TmpSignalConversionAtMult_0 >= -rtb_TmpSignalConversionAtMult_1))
      {
        rtb_TmpSignalConversionAtMult_0 *= CONTROL_PARAM.MC_ROLL_P;
      } else {
        rtb_TmpSignalConversionAtMult_0 = sqrtf((rtb_Square_m *
          rtb_TmpSignalConversionAtMult_0 - 0.5F *
          rtb_TmpSignalConversionAtMult_1) * Controller_ConstB.Gain) *
          rtb_Square_m;
      }

      /* Switch: '<S125>/Switch' incorporates:
       *  Gain: '<S124>/Gain3'
       *  RelationalOperator: '<S125>/UpperRelop'
       */
      if (rtb_TmpSignalConversionAtMult_0 >= -rtb_a_k) {
        rtb_DiscreteTimeIntegrator1_a = rtb_TmpSignalConversionAtMult_0;
      }

      /* Switch: '<S125>/Switch2' incorporates:
       *  RelationalOperator: '<S125>/LowerRelop1'
       */
      if (rtb_TmpSignalConversionAtMult_0 > rtb_a_k) {
        rtb_Multiply_ni[0] = rtb_a_k;
      } else {
        rtb_Multiply_ni[0] = rtb_DiscreteTimeIntegrator1_a;
      }

      /* Sum: '<S121>/Sum' incorporates:
       *  Inport: '<Root>/INS_Out'
       */
      rtb_TmpSignalConversionAtMult_0 = rtb_Subtract3_g -
        Controller_U.INS_Out.theta;

      /* Product: '<S124>/Divide1' incorporates:
       *  Abs: '<S124>/Abs'
       *  Constant: '<S124>/const2'
       */
      rtb_a_k = fabsf(rtb_TmpSignalConversionAtMult_0) / 0.002F;

      /* Gain: '<S124>/Gain3' */
      rtb_DiscreteTimeIntegrator1_a = -rtb_a_k;

      /* Product: '<S124>/Divide' incorporates:
       *  Constant: '<S122>/Constant2'
       *  Constant: '<S124>/const1'
       *  Math: '<S124>/Square'
       *  SignalConversion: '<S124>/TmpSignal ConversionAtSquareInport1'
       */
      rtb_TmpSignalConversionAtMult_1 = 9.5993F / (CONTROL_PARAM.MC_PITCH_P *
        CONTROL_PARAM.MC_PITCH_P);

      /* Signum: '<S124>/Sign' */
      if (rtb_TmpSignalConversionAtMult_0 < 0.0F) {
        rtb_Square_m = -1.0F;
      } else if (rtb_TmpSignalConversionAtMult_0 > 0.0F) {
        rtb_Square_m = 1.0F;
      } else {
        rtb_Square_m = rtb_TmpSignalConversionAtMult_0;
      }

      /* Switch: '<S124>/Switch' incorporates:
       *  Constant: '<S122>/Constant2'
       *  Gain: '<S124>/Gain1'
       *  Gain: '<S124>/Gain2'
       *  Logic: '<S124>/Logical Operator'
       *  Product: '<S124>/Multiply'
       *  Product: '<S124>/Multiply1'
       *  Product: '<S124>/Multiply2'
       *  Product: '<S124>/Multiply3'
       *  RelationalOperator: '<S124>/Relational Operator'
       *  RelationalOperator: '<S124>/Relational Operator2'
       *  SignalConversion: '<S124>/TmpSignal ConversionAtSquareInport1'
       *  Sqrt: '<S124>/Sqrt'
       *  Sum: '<S124>/Subtract'
       */
      if ((rtb_TmpSignalConversionAtMult_0 <= rtb_TmpSignalConversionAtMult_1) &&
          (rtb_TmpSignalConversionAtMult_0 >= -rtb_TmpSignalConversionAtMult_1))
      {
        rtb_TmpSignalConversionAtMult_0 *= CONTROL_PARAM.MC_PITCH_P;
      } else {
        rtb_TmpSignalConversionAtMult_0 = sqrtf((rtb_Square_m *
          rtb_TmpSignalConversionAtMult_0 - 0.5F *
          rtb_TmpSignalConversionAtMult_1) * Controller_ConstB.Gain) *
          rtb_Square_m;
      }

      /* Switch: '<S125>/Switch' incorporates:
       *  Gain: '<S124>/Gain3'
       *  RelationalOperator: '<S125>/UpperRelop'
       */
      if (rtb_TmpSignalConversionAtMult_0 >= -rtb_a_k) {
        rtb_DiscreteTimeIntegrator1_a = rtb_TmpSignalConversionAtMult_0;
      }

      /* Switch: '<S125>/Switch2' incorporates:
       *  RelationalOperator: '<S125>/LowerRelop1'
       */
      if (rtb_TmpSignalConversionAtMult_0 > rtb_a_k) {
        rtb_Multiply_ni[1] = rtb_a_k;
      } else {
        rtb_Multiply_ni[1] = rtb_DiscreteTimeIntegrator1_a;
      }

      rtb_Multiply_ni[2] = Controller_U.FMS_Out.psi_rate_cmd;
    } else {
      rtb_Multiply_ni[0] = Controller_B.Reshape[0];
      rtb_Multiply_ni[1] = Controller_B.Reshape[1];
      rtb_Multiply_ni[2] = Controller_B.Reshape[2];
    }

    /* End of Switch: '<S103>/Switch' */

    /* Sum: '<S117>/Subtract' incorporates:
     *  DiscreteIntegrator: '<S117>/Integrator1'
     */
    Controller_B.Multiply[0] = Controller_DW.Integrator1_DSTATE[0] -
      rtb_Multiply_ni[0];

    /* Product: '<S118>/Multiply1' incorporates:
     *  Constant: '<S118>/const1'
     *  DiscreteIntegrator: '<S117>/Integrator'
     */
    rtb_Square_m = Controller_DW.Integrator_DSTATE[0] * 0.0025F;

    /* Sum: '<S118>/Add' */
    Controller_B.Multiply[0] += rtb_Square_m;

    /* Signum: '<S118>/Sign' */
    if (Controller_B.Multiply[0] < 0.0F) {
      rtb_a_k = -1.0F;
    } else if (Controller_B.Multiply[0] > 0.0F) {
      rtb_a_k = 1.0F;
    } else {
      rtb_a_k = Controller_B.Multiply[0];
    }

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
    rtb_Gain_c4 = (sqrtf((8.0F * fabsf(Controller_B.Multiply[0]) +
                          Controller_ConstB.d) * Controller_ConstB.d) -
                   Controller_ConstB.d) * 0.5F * rtb_a_k + rtb_Square_m;

    /* Sum: '<S118>/Add4' */
    rtb_Square_m += Controller_B.Multiply[0] - rtb_Gain_c4;

    /* Sum: '<S118>/Add3' */
    rtb_Add3_e = Controller_B.Multiply[0] + Controller_ConstB.d;

    /* Sum: '<S118>/Subtract1' */
    Controller_B.Multiply[0] -= Controller_ConstB.d;

    /* Signum: '<S118>/Sign1' */
    if (rtb_Add3_e < 0.0F) {
      rtb_Add3_e = -1.0F;
    } else {
      if (rtb_Add3_e > 0.0F) {
        rtb_Add3_e = 1.0F;
      }
    }

    /* Signum: '<S118>/Sign2' incorporates:
     *  Sum: '<S118>/Add5'
     */
    if (Controller_B.Multiply[0] < 0.0F) {
      rtb_a_k = -1.0F;
    } else if (Controller_B.Multiply[0] > 0.0F) {
      rtb_a_k = 1.0F;
    } else {
      rtb_a_k = Controller_B.Multiply[0];
    }

    /* Sum: '<S118>/Add2' incorporates:
     *  Gain: '<S118>/Gain2'
     *  Product: '<S118>/Multiply4'
     *  Sum: '<S118>/Add5'
     *  Sum: '<S118>/Subtract2'
     */
    rtb_TmpSignalConversionAtMult_0 = (rtb_Add3_e - rtb_a_k) * 0.5F *
      rtb_Square_m + rtb_Gain_c4;

    /* Sum: '<S117>/Subtract' incorporates:
     *  DiscreteIntegrator: '<S117>/Integrator1'
     */
    Controller_B.Multiply[1] = Controller_DW.Integrator1_DSTATE[1] -
      rtb_Multiply_ni[1];

    /* Product: '<S118>/Multiply1' incorporates:
     *  Constant: '<S118>/const1'
     *  DiscreteIntegrator: '<S117>/Integrator'
     */
    rtb_Square_m = Controller_DW.Integrator_DSTATE[1] * 0.0025F;

    /* Sum: '<S118>/Add' */
    Controller_B.Multiply[1] += rtb_Square_m;

    /* Signum: '<S118>/Sign' */
    if (Controller_B.Multiply[1] < 0.0F) {
      rtb_a_k = -1.0F;
    } else if (Controller_B.Multiply[1] > 0.0F) {
      rtb_a_k = 1.0F;
    } else {
      rtb_a_k = Controller_B.Multiply[1];
    }

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
    rtb_Gain_c4 = (sqrtf((8.0F * fabsf(Controller_B.Multiply[1]) +
                          Controller_ConstB.d) * Controller_ConstB.d) -
                   Controller_ConstB.d) * 0.5F * rtb_a_k + rtb_Square_m;

    /* Sum: '<S118>/Add4' */
    rtb_Square_m += Controller_B.Multiply[1] - rtb_Gain_c4;

    /* Sum: '<S118>/Add3' */
    rtb_Add3_e = Controller_B.Multiply[1] + Controller_ConstB.d;

    /* Sum: '<S118>/Subtract1' */
    Controller_B.Multiply[1] -= Controller_ConstB.d;

    /* Signum: '<S118>/Sign1' */
    if (rtb_Add3_e < 0.0F) {
      rtb_Add3_e = -1.0F;
    } else {
      if (rtb_Add3_e > 0.0F) {
        rtb_Add3_e = 1.0F;
      }
    }

    /* Signum: '<S118>/Sign2' incorporates:
     *  Sum: '<S118>/Add5'
     */
    if (Controller_B.Multiply[1] < 0.0F) {
      rtb_a_k = -1.0F;
    } else if (Controller_B.Multiply[1] > 0.0F) {
      rtb_a_k = 1.0F;
    } else {
      rtb_a_k = Controller_B.Multiply[1];
    }

    /* Sum: '<S118>/Add2' incorporates:
     *  Gain: '<S118>/Gain2'
     *  Product: '<S118>/Multiply4'
     *  Sum: '<S118>/Add5'
     *  Sum: '<S118>/Subtract2'
     */
    rtb_TmpSignalConversionAtMult_1 = (rtb_Add3_e - rtb_a_k) * 0.5F *
      rtb_Square_m + rtb_Gain_c4;

    /* Sum: '<S117>/Subtract' incorporates:
     *  DiscreteIntegrator: '<S117>/Integrator1'
     */
    Controller_B.Multiply[2] = Controller_DW.Integrator1_DSTATE[2] -
      rtb_Multiply_ni[2];

    /* Product: '<S118>/Multiply1' incorporates:
     *  Constant: '<S118>/const1'
     *  DiscreteIntegrator: '<S117>/Integrator'
     */
    rtb_Square_m = Controller_DW.Integrator_DSTATE[2] * 0.0025F;

    /* Sum: '<S118>/Add' */
    Controller_B.Multiply[2] += rtb_Square_m;

    /* Signum: '<S118>/Sign' */
    if (Controller_B.Multiply[2] < 0.0F) {
      rtb_a_k = -1.0F;
    } else if (Controller_B.Multiply[2] > 0.0F) {
      rtb_a_k = 1.0F;
    } else {
      rtb_a_k = Controller_B.Multiply[2];
    }

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
    rtb_Gain_c4 = (sqrtf((8.0F * fabsf(Controller_B.Multiply[2]) +
                          Controller_ConstB.d) * Controller_ConstB.d) -
                   Controller_ConstB.d) * 0.5F * rtb_a_k + rtb_Square_m;

    /* Sum: '<S118>/Add4' */
    rtb_Square_m += Controller_B.Multiply[2] - rtb_Gain_c4;

    /* Sum: '<S118>/Add3' */
    rtb_Add3_e = Controller_B.Multiply[2] + Controller_ConstB.d;

    /* Sum: '<S118>/Subtract1' */
    Controller_B.Multiply[2] -= Controller_ConstB.d;

    /* Signum: '<S118>/Sign1' */
    if (rtb_Add3_e < 0.0F) {
      rtb_Add3_e = -1.0F;
    } else {
      if (rtb_Add3_e > 0.0F) {
        rtb_Add3_e = 1.0F;
      }
    }

    /* Signum: '<S118>/Sign2' incorporates:
     *  Sum: '<S118>/Add5'
     */
    if (Controller_B.Multiply[2] < 0.0F) {
      rtb_a_k = -1.0F;
    } else if (Controller_B.Multiply[2] > 0.0F) {
      rtb_a_k = 1.0F;
    } else {
      rtb_a_k = Controller_B.Multiply[2];
    }

    /* Sum: '<S118>/Add5' incorporates:
     *  Gain: '<S118>/Gain2'
     *  Product: '<S118>/Multiply4'
     *  Sum: '<S118>/Subtract2'
     */
    rtb_Gain_c4 += (rtb_Add3_e - rtb_a_k) * 0.5F * rtb_Square_m;

    /* DiscreteIntegrator: '<S111>/Discrete-Time Integrator' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator_PrevRe_d != 0)) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_b[0] =
        Controller_ConstB.Constant_a[0];
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_b[0] >=
          CONTROL_PARAM.MC_RATE_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_b[0] =
          CONTROL_PARAM.MC_RATE_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_b[0] <=
            CONTROL_PARAM.MC_RATE_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_b[0] =
            CONTROL_PARAM.MC_RATE_I_MIN;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_DSTATE_b[1] =
        Controller_ConstB.Constant_a[1];
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_b[1] >=
          CONTROL_PARAM.MC_RATE_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_b[1] =
          CONTROL_PARAM.MC_RATE_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_b[1] <=
            CONTROL_PARAM.MC_RATE_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_b[1] =
            CONTROL_PARAM.MC_RATE_I_MIN;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_DSTATE_b[2] =
        Controller_ConstB.Constant_a[2];
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_b[2] >=
          CONTROL_PARAM.MC_RATE_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_b[2] =
          CONTROL_PARAM.MC_RATE_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_b[2] <=
            CONTROL_PARAM.MC_RATE_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_b[2] =
            CONTROL_PARAM.MC_RATE_I_MIN;
        }
      }
    }

    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_b[0] >=
        CONTROL_PARAM.MC_RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_b[0] =
        CONTROL_PARAM.MC_RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_b[0] <=
          CONTROL_PARAM.MC_RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_b[0] =
          CONTROL_PARAM.MC_RATE_I_MIN;
      }
    }

    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_b[1] >=
        CONTROL_PARAM.MC_RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_b[1] =
        CONTROL_PARAM.MC_RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_b[1] <=
          CONTROL_PARAM.MC_RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_b[1] =
          CONTROL_PARAM.MC_RATE_I_MIN;
      }
    }

    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_b[2] >=
        CONTROL_PARAM.MC_RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_b[2] =
        CONTROL_PARAM.MC_RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_b[2] <=
          CONTROL_PARAM.MC_RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_b[2] =
          CONTROL_PARAM.MC_RATE_I_MIN;
      }
    }

    /* Sum: '<S114>/Add' incorporates:
     *  DiscreteIntegrator: '<S117>/Integrator1'
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S114>/Multiply'
     *  Trigonometry: '<S114>/Sin1'
     */
    rtb_Saturation1_n = Controller_DW.Integrator1_DSTATE[0] - arm_sin_f32
      (Controller_U.INS_Out.theta) * Controller_DW.Integrator1_DSTATE[2];

    /* Saturate: '<S103>/Saturation1' */
    if (rtb_Saturation1_n > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_Saturation1_n = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_Saturation1_n < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_Saturation1_n = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    /* End of Saturate: '<S103>/Saturation1' */

    /* Trigonometry: '<S114>/Sin' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_a_k = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S114>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Add3_e = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Trigonometry: '<S114>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_DiscreteTimeIntegrator1_a = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Sum: '<S114>/Add1' incorporates:
     *  DiscreteIntegrator: '<S117>/Integrator1'
     *  Product: '<S114>/Multiply1'
     *  Product: '<S114>/Multiply3'
     *  Trigonometry: '<S114>/Cos'
     *  Trigonometry: '<S114>/Cos1'
     *  Trigonometry: '<S114>/Sin'
     */
    rtb_Subtract3_g = rtb_a_k * rtb_Add3_e * Controller_DW.Integrator1_DSTATE[2]
      + rtb_DiscreteTimeIntegrator1_a * Controller_DW.Integrator1_DSTATE[1];

    /* Saturate: '<S103>/Saturation2' */
    if (rtb_Subtract3_g > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_Subtract3_g = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_Subtract3_g < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_Subtract3_g = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    /* End of Saturate: '<S103>/Saturation2' */

    /* Sum: '<S114>/Add2' incorporates:
     *  DiscreteIntegrator: '<S117>/Integrator1'
     *  Product: '<S114>/Multiply4'
     *  Product: '<S114>/Multiply5'
     *  Trigonometry: '<S114>/Cos'
     *  Trigonometry: '<S114>/Cos1'
     *  Trigonometry: '<S114>/Sin'
     */
    rtb_DiscreteTimeIntegrator1_a = rtb_DiscreteTimeIntegrator1_a * rtb_Add3_e *
      Controller_DW.Integrator1_DSTATE[2] - rtb_a_k *
      Controller_DW.Integrator1_DSTATE[1];

    /* Saturate: '<S103>/Saturation' */
    if (rtb_DiscreteTimeIntegrator1_a > CONTROL_PARAM.MC_R_CMD_LIM) {
      rtb_DiscreteTimeIntegrator1_a = CONTROL_PARAM.MC_R_CMD_LIM;
    } else {
      if (rtb_DiscreteTimeIntegrator1_a < -CONTROL_PARAM.MC_R_CMD_LIM) {
        rtb_DiscreteTimeIntegrator1_a = -CONTROL_PARAM.MC_R_CMD_LIM;
      }
    }

    /* End of Saturate: '<S103>/Saturation' */

    /* Sum: '<S104>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Square_m = rtb_Saturation1_n - Controller_U.INS_Out.p;

    /* Saturate: '<S104>/Saturation' */
    if (rtb_Square_m > 3.14159274F) {
      rtb_Square_m = 3.14159274F;
    } else {
      if (rtb_Square_m < -3.14159274F) {
        rtb_Square_m = -3.14159274F;
      }
    }

    /* Sum: '<S104>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_aq_idx_0 = rtb_Subtract3_g - Controller_U.INS_Out.q;

    /* Saturate: '<S104>/Saturation' */
    if (rtb_Divide_aq_idx_0 > 3.14159274F) {
      rtb_Divide_aq_idx_0 = 3.14159274F;
    } else {
      if (rtb_Divide_aq_idx_0 < -3.14159274F) {
        rtb_Divide_aq_idx_0 = -3.14159274F;
      }
    }

    /* Sum: '<S104>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1_tmp = rtb_DiscreteTimeIntegrator1_a -
      Controller_U.INS_Out.r;

    /* Saturate: '<S104>/Saturation' */
    if (rtb_MatrixConcatenate1_tmp > 3.14159274F) {
      rtb_MatrixConcatenate1_tmp = 3.14159274F;
    } else {
      if (rtb_MatrixConcatenate1_tmp < -3.14159274F) {
        rtb_MatrixConcatenate1_tmp = -3.14159274F;
      }
    }

    /* DiscreteIntegrator: '<S108>/Discrete-Time Integrator5' incorporates:
     *  Saturate: '<S104>/Saturation'
     */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_c != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0] = rtb_Square_m;
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1] = rtb_Divide_aq_idx_0;
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2] =
        rtb_MatrixConcatenate1_tmp;
    }

    /* DiscreteIntegrator: '<S113>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S108>/Discrete-Time Integrator5'
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

    /* Gain: '<S113>/Gain' incorporates:
     *  DiscreteIntegrator: '<S108>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S113>/Discrete-Time Integrator1'
     *  Sum: '<S113>/Sum5'
     */
    rtb_Divide_aq_idx_1 = (Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0] -
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[0]) * 188.49556F;
    rtb_Divide_aq_idx_2 = (Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1] -
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[1]) * 188.49556F;
    rtb_Divide_aq_idx_3 = (Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2] -
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[2]) * 188.49556F;

    /* Switch: '<S113>/Switch' incorporates:
     *  Gain: '<S113>/Gain1'
     *  Inport: '<Root>/FMS_Out'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_Add3_e = 0.0F;
      rtb_a_k = 0.0F;
      rtb_Gain_hl_idx_2 = 0.0F;
    } else {
      rtb_Add3_e = rtb_Divide_aq_idx_1;
      rtb_a_k = rtb_Divide_aq_idx_2;
      rtb_Gain_hl_idx_2 = rtb_Divide_aq_idx_3;
    }

    /* End of Switch: '<S113>/Switch' */

    /* Product: '<S110>/Multiply' incorporates:
     *  Constant: '<S110>/gain1'
     */
    rtb_Saturation_idx_0 = CONTROL_PARAM.MC_ROLL_RATE_D * rtb_Add3_e;

    /* Saturate: '<S110>/Saturation' */
    if (rtb_Saturation_idx_0 > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Saturation_idx_0 = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Saturation_idx_0 < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Saturation_idx_0 = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    /* Product: '<S110>/Multiply' incorporates:
     *  Constant: '<S110>/gain2'
     */
    rtb_Add3_e = rtb_Saturation_idx_0;
    rtb_Saturation_idx_0 = CONTROL_PARAM.MC_PITCH_RATE_D * rtb_a_k;

    /* Saturate: '<S110>/Saturation' */
    if (rtb_Saturation_idx_0 > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Saturation_idx_0 = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Saturation_idx_0 < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Saturation_idx_0 = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    /* Product: '<S110>/Multiply' incorporates:
     *  Constant: '<S110>/gain3'
     */
    rtb_a_k = rtb_Saturation_idx_0;
    rtb_Saturation_idx_0 = CONTROL_PARAM.MC_YAW_RATE_D * rtb_Gain_hl_idx_2;

    /* Saturate: '<S110>/Saturation' */
    if (rtb_Saturation_idx_0 > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Saturation_idx_0 = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Saturation_idx_0 < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Saturation_idx_0 = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    /* Sum: '<S106>/Add' incorporates:
     *  Constant: '<S112>/gain1'
     *  Constant: '<S112>/gain2'
     *  Constant: '<S112>/gain3'
     *  DiscreteIntegrator: '<S108>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S111>/Discrete-Time Integrator'
     *  Product: '<S112>/Multiply'
     */
    Controller_B.Multiply[0] = (CONTROL_PARAM.MC_ROLL_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE_b[0]) + rtb_Add3_e;
    Controller_B.Multiply[1] = (CONTROL_PARAM.MC_PITCH_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE_b[1]) + rtb_a_k;
    Controller_B.Multiply[2] = (CONTROL_PARAM.MC_YAW_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE_b[2]) + rtb_Saturation_idx_0;

    /* DeadZone: '<S109>/Dead Zone' */
    if (rtb_Saturation1_n > 0.1F) {
      rtb_Saturation1_n -= 0.1F;
    } else if (rtb_Saturation1_n >= -0.1F) {
      rtb_Saturation1_n = 0.0F;
    } else {
      rtb_Saturation1_n -= -0.1F;
    }

    /* Sum: '<S102>/Sum' incorporates:
     *  Gain: '<S105>/Gain'
     *  Gain: '<S109>/Gain'
     */
    Controller_B.Multiply[0] += 1.11111116F * rtb_Saturation1_n *
      CONTROL_PARAM.MC_ROLL_RATE_FF;

    /* Product: '<S5>/Multiply' incorporates:
     *  DiscreteIntegrator: '<S160>/Discrete-Time Integrator5'
     */
    Controller_B.Multiply[0] *= Controller_DW.DiscreteTimeIntegrator5_DSTATE;

    /* DeadZone: '<S109>/Dead Zone' */
    if (rtb_Subtract3_g > 0.1F) {
      rtb_Subtract3_g -= 0.1F;
    } else if (rtb_Subtract3_g >= -0.1F) {
      rtb_Subtract3_g = 0.0F;
    } else {
      rtb_Subtract3_g -= -0.1F;
    }

    /* Sum: '<S102>/Sum' incorporates:
     *  Gain: '<S105>/Gain'
     *  Gain: '<S109>/Gain'
     */
    Controller_B.Multiply[1] += 1.11111116F * rtb_Subtract3_g *
      CONTROL_PARAM.MC_ROLL_RATE_FF;

    /* Product: '<S5>/Multiply' incorporates:
     *  DiscreteIntegrator: '<S160>/Discrete-Time Integrator5'
     */
    Controller_B.Multiply[1] *= Controller_DW.DiscreteTimeIntegrator5_DSTATE;

    /* DeadZone: '<S109>/Dead Zone' */
    if (rtb_DiscreteTimeIntegrator1_a > 0.1F) {
      rtb_DiscreteTimeIntegrator1_a -= 0.1F;
    } else if (rtb_DiscreteTimeIntegrator1_a >= -0.1F) {
      rtb_DiscreteTimeIntegrator1_a = 0.0F;
    } else {
      rtb_DiscreteTimeIntegrator1_a -= -0.1F;
    }

    /* Sum: '<S102>/Sum' incorporates:
     *  Gain: '<S105>/Gain1'
     *  Gain: '<S109>/Gain'
     */
    Controller_B.Multiply[2] += 1.11111116F * rtb_DiscreteTimeIntegrator1_a *
      CONTROL_PARAM.MC_PITCH_RATE_FF;

    /* Product: '<S5>/Multiply' incorporates:
     *  DiscreteIntegrator: '<S160>/Discrete-Time Integrator5'
     */
    Controller_B.Multiply[2] *= Controller_DW.DiscreteTimeIntegrator5_DSTATE;

    /* Product: '<S138>/Multiply1' incorporates:
     *  Constant: '<S138>/const1'
     *  DiscreteIntegrator: '<S135>/Integrator'
     */
    rtb_Saturation1_n = Controller_DW.Integrator_DSTATE_l[0] * 0.1F;
    rtb_Subtract3_g = Controller_DW.Integrator_DSTATE_l[1] * 0.1F;

    /* Sum: '<S138>/Add' incorporates:
     *  DiscreteIntegrator: '<S135>/Integrator1'
     *  Inport: '<Root>/FMS_Out'
     *  Sum: '<S135>/Subtract'
     */
    rtb_Saturation_idx_0 = (Controller_DW.Integrator1_DSTATE_e[0] -
      Controller_U.FMS_Out.u_cmd) + rtb_Saturation1_n;
    rtb_Gain_hl_idx_2 = (Controller_DW.Integrator1_DSTATE_e[1] -
                         Controller_U.FMS_Out.v_cmd) + rtb_Subtract3_g;

    /* Signum: '<S138>/Sign' */
    if (rtb_Saturation_idx_0 < 0.0F) {
      rtb_DiscreteTimeIntegrator1_a = -1.0F;
    } else if (rtb_Saturation_idx_0 > 0.0F) {
      rtb_DiscreteTimeIntegrator1_a = 1.0F;
    } else {
      rtb_DiscreteTimeIntegrator1_a = rtb_Saturation_idx_0;
    }

    /* Sum: '<S138>/Add2' incorporates:
     *  Abs: '<S138>/Abs'
     *  Gain: '<S138>/Gain'
     *  Gain: '<S138>/Gain1'
     *  Product: '<S138>/Multiply2'
     *  Product: '<S138>/Multiply3'
     *  Signum: '<S138>/Sign'
     *  Sqrt: '<S138>/Sqrt'
     *  Sum: '<S138>/Add1'
     *  Sum: '<S138>/Subtract'
     */
    rtb_DiscreteTimeIntegrator1_a = (sqrtf((8.0F * fabsf(rtb_Saturation_idx_0) +
      Controller_ConstB.d_f) * Controller_ConstB.d_f) - Controller_ConstB.d_f) *
      0.5F * rtb_DiscreteTimeIntegrator1_a + rtb_Saturation1_n;

    /* Sum: '<S138>/Add3' incorporates:
     *  Signum: '<S138>/Sign'
     */
    rtb_Add3_e = rtb_Saturation_idx_0 + Controller_ConstB.d_f;

    /* Sum: '<S138>/Subtract1' incorporates:
     *  Signum: '<S138>/Sign'
     */
    rtb_a_k = rtb_Saturation_idx_0 - Controller_ConstB.d_f;

    /* Signum: '<S138>/Sign1' */
    if (rtb_Add3_e < 0.0F) {
      rtb_Add3_e = -1.0F;
    } else {
      if (rtb_Add3_e > 0.0F) {
        rtb_Add3_e = 1.0F;
      }
    }

    /* Signum: '<S138>/Sign2' */
    if (rtb_a_k < 0.0F) {
      rtb_a_k = -1.0F;
    } else {
      if (rtb_a_k > 0.0F) {
        rtb_a_k = 1.0F;
      }
    }

    /* Sum: '<S138>/Add2' incorporates:
     *  Gain: '<S138>/Gain2'
     *  Product: '<S138>/Multiply4'
     *  Signum: '<S138>/Sign'
     *  Sum: '<S138>/Add4'
     *  Sum: '<S138>/Add5'
     *  Sum: '<S138>/Subtract2'
     */
    rtb_Saturation1_n = ((rtb_Saturation_idx_0 - rtb_DiscreteTimeIntegrator1_a)
                         + rtb_Saturation1_n) * ((rtb_Add3_e - rtb_a_k) * 0.5F)
      + rtb_DiscreteTimeIntegrator1_a;

    /* Signum: '<S138>/Sign' */
    if (rtb_Gain_hl_idx_2 < 0.0F) {
      rtb_DiscreteTimeIntegrator1_a = -1.0F;
    } else if (rtb_Gain_hl_idx_2 > 0.0F) {
      rtb_DiscreteTimeIntegrator1_a = 1.0F;
    } else {
      rtb_DiscreteTimeIntegrator1_a = rtb_Gain_hl_idx_2;
    }

    /* Sum: '<S138>/Add2' incorporates:
     *  Abs: '<S138>/Abs'
     *  Gain: '<S138>/Gain'
     *  Gain: '<S138>/Gain1'
     *  Product: '<S138>/Multiply2'
     *  Product: '<S138>/Multiply3'
     *  Signum: '<S138>/Sign'
     *  Sqrt: '<S138>/Sqrt'
     *  Sum: '<S138>/Add1'
     *  Sum: '<S138>/Subtract'
     */
    rtb_DiscreteTimeIntegrator1_a = (sqrtf((8.0F * fabsf(rtb_Gain_hl_idx_2) +
      Controller_ConstB.d_f) * Controller_ConstB.d_f) - Controller_ConstB.d_f) *
      0.5F * rtb_DiscreteTimeIntegrator1_a + rtb_Subtract3_g;

    /* Sum: '<S138>/Add3' incorporates:
     *  Signum: '<S138>/Sign'
     */
    rtb_Add3_e = rtb_Gain_hl_idx_2 + Controller_ConstB.d_f;

    /* Sum: '<S138>/Subtract1' incorporates:
     *  Signum: '<S138>/Sign'
     */
    rtb_a_k = rtb_Gain_hl_idx_2 - Controller_ConstB.d_f;

    /* Signum: '<S138>/Sign1' */
    if (rtb_Add3_e < 0.0F) {
      rtb_Add3_e = -1.0F;
    } else {
      if (rtb_Add3_e > 0.0F) {
        rtb_Add3_e = 1.0F;
      }
    }

    /* Signum: '<S138>/Sign2' */
    if (rtb_a_k < 0.0F) {
      rtb_a_k = -1.0F;
    } else {
      if (rtb_a_k > 0.0F) {
        rtb_a_k = 1.0F;
      }
    }

    /* Sum: '<S138>/Add5' incorporates:
     *  Gain: '<S138>/Gain2'
     *  Product: '<S138>/Multiply4'
     *  Signum: '<S138>/Sign'
     *  Sum: '<S138>/Add2'
     *  Sum: '<S138>/Add4'
     *  Sum: '<S138>/Subtract2'
     */
    rtb_DiscreteTimeIntegrator1_a += ((rtb_Gain_hl_idx_2 -
      rtb_DiscreteTimeIntegrator1_a) + rtb_Subtract3_g) * ((rtb_Add3_e - rtb_a_k)
      * 0.5F);

    /* Gain: '<S151>/Gain' incorporates:
     *  DiscreteIntegrator: '<S153>/Integrator1'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S151>/Sum1'
     */
    rtb_Gain_hl_idx_2 = -(Controller_DW.Integrator1_DSTATE_eq -
                          Controller_U.INS_Out.vd);

    /* Constant: '<S156>/Constant' */
    Controller_B.Constant = CONTROL_PARAM.MC_VEL_Z_I_MIN;

    /* DiscreteIntegrator: '<S156>/Discrete-Time Integrator' incorporates:
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

    /* DiscreteIntegrator: '<S158>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_d != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i = rtb_Gain_hl_idx_2;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_Prev_ks != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i = rtb_Gain_hl_idx_2;
    }

    /* Gain: '<S158>/Gain' incorporates:
     *  DiscreteIntegrator: '<S158>/Discrete-Time Integrator1'
     *  Sum: '<S158>/Sum5'
     */
    rtb_Saturation_idx_0 = (rtb_Gain_hl_idx_2 -
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i) * 62.831852F;

    /* Switch: '<S147>/Switch' incorporates:
     *  Bias: '<S147>/Bias'
     *  Constant: '<S149>/Constant'
     *  Gain: '<S147>/Gain'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S149>/Compare'
     */
    if (Controller_U.FMS_Out.ctrl_mode <= 3) {
      rtb_Subtract3_g = 0.000999987125F * (real32_T)
        Controller_U.FMS_Out.throttle_cmd + -1.0F;
    } else {
      /* Product: '<S150>/Multiply' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S150>/Cos'
       *  Trigonometry: '<S150>/Cos1'
       */
      rtb_a_k = arm_cos_f32(Controller_U.INS_Out.phi) * arm_cos_f32
        (Controller_U.INS_Out.theta);

      /* Gain: '<S150>/Gain' */
      rtb_Add3_e = 2.0F * rtb_a_k;

      /* Saturate: '<S150>/Saturation1' */
      if (rtb_a_k > 1.0F) {
        rtb_a_k = 1.0F;
      } else {
        if (rtb_a_k < 0.5F) {
          rtb_a_k = 0.5F;
        }
      }

      /* End of Saturate: '<S150>/Saturation1' */

      /* Product: '<S150>/Divide' incorporates:
       *  Constant: '<S150>/Constant'
       */
      rtb_Subtract3_g = 1.0F / rtb_a_k;

      /* Switch: '<S158>/Switch' incorporates:
       *  Gain: '<S158>/Gain1'
       */
      if (Controller_U.FMS_Out.reset > 0) {
        rtb_a_k = 0.0F;
      } else {
        rtb_a_k = rtb_Saturation_idx_0;
      }

      /* End of Switch: '<S158>/Switch' */

      /* Product: '<S155>/Multiply' incorporates:
       *  Constant: '<S155>/kd'
       */
      rtb_a_k *= CONTROL_PARAM.MC_VEL_Z_D;

      /* Saturate: '<S155>/Saturation' */
      if (rtb_a_k > CONTROL_PARAM.MC_VEL_Z_D_MAX) {
        rtb_a_k = CONTROL_PARAM.MC_VEL_Z_D_MAX;
      } else {
        if (rtb_a_k < CONTROL_PARAM.MC_VEL_Z_D_MIN) {
          rtb_a_k = CONTROL_PARAM.MC_VEL_Z_D_MIN;
        }
      }

      /* End of Saturate: '<S155>/Saturation' */

      /* Saturate: '<S150>/Saturation' */
      if (rtb_Add3_e > 1.0F) {
        rtb_Add3_e = 1.0F;
      } else {
        if (rtb_Add3_e < 0.0F) {
          rtb_Add3_e = 0.0F;
        }
      }

      /* End of Saturate: '<S150>/Saturation' */

      /* Sum: '<S148>/Sum' incorporates:
       *  Constant: '<S148>/hover_throttle'
       *  Constant: '<S157>/kp'
       *  DiscreteIntegrator: '<S156>/Discrete-Time Integrator'
       *  Product: '<S150>/Multiply1'
       *  Product: '<S157>/Multiply'
       *  Sum: '<S152>/Add'
       */
      rtb_Subtract3_g = ((CONTROL_PARAM.MC_VEL_Z_P * rtb_Gain_hl_idx_2 +
                          Controller_DW.DiscreteTimeIntegrator_DSTATE_l) +
                         rtb_a_k) * rtb_Subtract3_g * rtb_Add3_e +
        CONTROL_PARAM.MC_HOVER_THRO;

      /* Saturate: '<S148>/Saturation' */
      if (rtb_Subtract3_g > 0.8F) {
        rtb_Subtract3_g = 0.8F;
      } else {
        if (rtb_Subtract3_g < 0.2F) {
          rtb_Subtract3_g = 0.2F;
        }
      }

      /* End of Saturate: '<S148>/Saturation' */
    }

    /* End of Switch: '<S147>/Switch' */

    /* Product: '<S5>/Multiply1' incorporates:
     *  Constant: '<S147>/Constant'
     *  DiscreteIntegrator: '<S160>/Discrete-Time Integrator5'
     */
    Controller_B.Multiply1[0] = 0.0F;
    Controller_B.Multiply1[1] = 0.0F;
    Controller_B.Multiply1[2] = Controller_DW.DiscreteTimeIntegrator5_DSTATE *
      rtb_Subtract3_g;

    /* Product: '<S154>/Multiply1' incorporates:
     *  Constant: '<S154>/const1'
     *  DiscreteIntegrator: '<S153>/Integrator'
     */
    rtb_Add3_e = Controller_DW.Integrator_DSTATE_j * 0.05F;

    /* Sum: '<S154>/Add' incorporates:
     *  DiscreteIntegrator: '<S153>/Integrator1'
     *  Inport: '<Root>/FMS_Out'
     *  Sum: '<S153>/Subtract'
     */
    rtb_Subtract3_g = (Controller_DW.Integrator1_DSTATE_eq -
                       Controller_U.FMS_Out.w_cmd) + rtb_Add3_e;

    /* Signum: '<S154>/Sign' */
    if (rtb_Subtract3_g < 0.0F) {
      rtb_a_k = -1.0F;
    } else if (rtb_Subtract3_g > 0.0F) {
      rtb_a_k = 1.0F;
    } else {
      rtb_a_k = rtb_Subtract3_g;
    }

    /* End of Signum: '<S154>/Sign' */

    /* Sum: '<S154>/Add2' incorporates:
     *  Abs: '<S154>/Abs'
     *  Gain: '<S154>/Gain'
     *  Gain: '<S154>/Gain1'
     *  Product: '<S154>/Multiply2'
     *  Product: '<S154>/Multiply3'
     *  Sqrt: '<S154>/Sqrt'
     *  Sum: '<S154>/Add1'
     *  Sum: '<S154>/Subtract'
     */
    rtb_a_k = (sqrtf((8.0F * fabsf(rtb_Subtract3_g) + Controller_ConstB.d_i) *
                     Controller_ConstB.d_i) - Controller_ConstB.d_i) * 0.5F *
      rtb_a_k + rtb_Add3_e;

    /* Sum: '<S154>/Add4' */
    rtb_Add4_l = (rtb_Subtract3_g - rtb_a_k) + rtb_Add3_e;

    /* Sum: '<S154>/Add3' */
    rtb_Add3_e = rtb_Subtract3_g + Controller_ConstB.d_i;

    /* Sum: '<S154>/Subtract1' */
    rtb_Subtract3_g -= Controller_ConstB.d_i;

    /* Signum: '<S154>/Sign1' */
    if (rtb_Add3_e < 0.0F) {
      rtb_Add3_e = -1.0F;
    } else {
      if (rtb_Add3_e > 0.0F) {
        rtb_Add3_e = 1.0F;
      }
    }

    /* End of Signum: '<S154>/Sign1' */

    /* Signum: '<S154>/Sign2' */
    if (rtb_Subtract3_g < 0.0F) {
      rtb_Subtract3_g = -1.0F;
    } else {
      if (rtb_Subtract3_g > 0.0F) {
        rtb_Subtract3_g = 1.0F;
      }
    }

    /* End of Signum: '<S154>/Sign2' */

    /* Sum: '<S154>/Add5' incorporates:
     *  Gain: '<S154>/Gain2'
     *  Product: '<S154>/Multiply4'
     *  Sum: '<S154>/Subtract2'
     */
    rtb_a_k += (rtb_Add3_e - rtb_Subtract3_g) * 0.5F * rtb_Add4_l;

    /* Update for DiscreteIntegrator: '<S117>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S117>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE[0] += 0.002F *
      Controller_DW.Integrator_DSTATE[0];
    Controller_DW.Integrator1_DSTATE[1] += 0.002F *
      Controller_DW.Integrator_DSTATE[1];
    Controller_DW.Integrator1_DSTATE[2] += 0.002F *
      Controller_DW.Integrator_DSTATE[2];

    /* Update for DiscreteIntegrator: '<S140>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)rtb_Compare_b;

    /* Update for DiscreteIntegrator: '<S142>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;

    /* Update for DiscreteIntegrator: '<S135>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S135>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_e[0] += 0.002F *
      Controller_DW.Integrator_DSTATE_l[0];

    /* Update for DiscreteIntegrator: '<S140>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S140>/ki'
     *  Product: '<S140>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] += CONTROL_PARAM.MC_VEL_XY_I *
      rtb_TmpSignalConversionAtMult_2 * 0.002F;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] >=
        CONTROL_PARAM.MC_VEL_XY_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
        CONTROL_PARAM.MC_VEL_XY_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] <=
          CONTROL_PARAM.MC_VEL_XY_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
          CONTROL_PARAM.MC_VEL_XY_I_MIN;
      }
    }

    /* Update for DiscreteIntegrator: '<S142>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] += 0.002F * rtb_VdotPg;

    /* Update for DiscreteIntegrator: '<S135>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S135>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_e[1] += 0.002F *
      Controller_DW.Integrator_DSTATE_l[1];

    /* Update for DiscreteIntegrator: '<S140>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S140>/ki'
     *  Product: '<S140>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE[1] += CONTROL_PARAM.MC_VEL_XY_I *
      rtb_Saturation1 * 0.002F;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] >=
        CONTROL_PARAM.MC_VEL_XY_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
        CONTROL_PARAM.MC_VEL_XY_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] <=
          CONTROL_PARAM.MC_VEL_XY_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
          CONTROL_PARAM.MC_VEL_XY_I_MIN;
      }
    }

    /* Update for DiscreteIntegrator: '<S142>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] += 0.002F * rtb_Ldot_err;
    Controller_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)rtb_Compare_b;

    /* Update for DiscreteIntegrator: '<S111>/Discrete-Time Integrator' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.DiscreteTimeIntegrator_PrevRe_d = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S108>/Discrete-Time Integrator5' */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_c = 0U;

    /* Update for DiscreteIntegrator: '<S113>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 0U;

    /* Signum: '<S118>/Sign3' incorporates:
     *  Product: '<S118>/Divide'
     *  Sum: '<S118>/Add6'
     */
    rtb_Add3_e = rtb_TmpSignalConversionAtMult_0 + Controller_ConstB.d;

    /* Signum: '<S118>/Sign4' incorporates:
     *  Product: '<S118>/Divide'
     *  Sum: '<S118>/Subtract3'
     */
    rtb_Subtract3_g = rtb_TmpSignalConversionAtMult_0 - Controller_ConstB.d;

    /* Signum: '<S118>/Sign5' incorporates:
     *  Product: '<S118>/Divide'
     */
    if (rtb_TmpSignalConversionAtMult_0 < 0.0F) {
      rtb_TmpSignalConversionAtMult_2 = -1.0F;
    } else if (rtb_TmpSignalConversionAtMult_0 > 0.0F) {
      rtb_TmpSignalConversionAtMult_2 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_2 = rtb_TmpSignalConversionAtMult_0;
    }

    /* Signum: '<S118>/Sign3' */
    if (rtb_Add3_e < 0.0F) {
      rtb_Add3_e = -1.0F;
    } else {
      if (rtb_Add3_e > 0.0F) {
        rtb_Add3_e = 1.0F;
      }
    }

    /* Signum: '<S118>/Sign4' */
    if (rtb_Subtract3_g < 0.0F) {
      rtb_Subtract3_g = -1.0F;
    } else {
      if (rtb_Subtract3_g > 0.0F) {
        rtb_Subtract3_g = 1.0F;
      }
    }

    /* Signum: '<S118>/Sign6' incorporates:
     *  Product: '<S118>/Divide'
     */
    if (rtb_TmpSignalConversionAtMult_0 < 0.0F) {
      rtb_Saturation1 = -1.0F;
    } else if (rtb_TmpSignalConversionAtMult_0 > 0.0F) {
      rtb_Saturation1 = 1.0F;
    } else {
      rtb_Saturation1 = rtb_TmpSignalConversionAtMult_0;
    }

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
    Controller_DW.Integrator_DSTATE[0] += ((rtb_TmpSignalConversionAtMult_0 /
      Controller_ConstB.d - rtb_TmpSignalConversionAtMult_2) *
      Controller_ConstB.Gain4 * ((rtb_Add3_e - rtb_Subtract3_g) * 0.5F) -
      rtb_Saturation1 * 94.2477798F) * 0.002F;

    /* Update for DiscreteIntegrator: '<S111>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S111>/gain1'
     *  DiscreteIntegrator: '<S108>/Discrete-Time Integrator5'
     *  Product: '<S111>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_b[0] +=
      CONTROL_PARAM.MC_ROLL_RATE_I *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0] * 0.002F;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_b[0] >=
        CONTROL_PARAM.MC_RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_b[0] =
        CONTROL_PARAM.MC_RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_b[0] <=
          CONTROL_PARAM.MC_RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_b[0] =
          CONTROL_PARAM.MC_RATE_I_MIN;
      }
    }

    /* Update for DiscreteIntegrator: '<S108>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S108>/Gain'
     *  Saturate: '<S104>/Saturation'
     *  Sum: '<S108>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0] += (rtb_Square_m -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S113>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[0] += 0.002F *
      rtb_Divide_aq_idx_1;

    /* Signum: '<S118>/Sign3' incorporates:
     *  Product: '<S118>/Divide'
     *  Sum: '<S118>/Add6'
     */
    rtb_Add3_e = rtb_TmpSignalConversionAtMult_1 + Controller_ConstB.d;

    /* Signum: '<S118>/Sign4' incorporates:
     *  Product: '<S118>/Divide'
     *  Sum: '<S118>/Subtract3'
     */
    rtb_Subtract3_g = rtb_TmpSignalConversionAtMult_1 - Controller_ConstB.d;

    /* Signum: '<S118>/Sign5' incorporates:
     *  Product: '<S118>/Divide'
     */
    if (rtb_TmpSignalConversionAtMult_1 < 0.0F) {
      rtb_TmpSignalConversionAtMult_2 = -1.0F;
    } else if (rtb_TmpSignalConversionAtMult_1 > 0.0F) {
      rtb_TmpSignalConversionAtMult_2 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_2 = rtb_TmpSignalConversionAtMult_1;
    }

    /* Signum: '<S118>/Sign3' */
    if (rtb_Add3_e < 0.0F) {
      rtb_Add3_e = -1.0F;
    } else {
      if (rtb_Add3_e > 0.0F) {
        rtb_Add3_e = 1.0F;
      }
    }

    /* Signum: '<S118>/Sign4' */
    if (rtb_Subtract3_g < 0.0F) {
      rtb_Subtract3_g = -1.0F;
    } else {
      if (rtb_Subtract3_g > 0.0F) {
        rtb_Subtract3_g = 1.0F;
      }
    }

    /* Signum: '<S118>/Sign6' incorporates:
     *  Product: '<S118>/Divide'
     */
    if (rtb_TmpSignalConversionAtMult_1 < 0.0F) {
      rtb_Saturation1 = -1.0F;
    } else if (rtb_TmpSignalConversionAtMult_1 > 0.0F) {
      rtb_Saturation1 = 1.0F;
    } else {
      rtb_Saturation1 = rtb_TmpSignalConversionAtMult_1;
    }

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
    Controller_DW.Integrator_DSTATE[1] += ((rtb_TmpSignalConversionAtMult_1 /
      Controller_ConstB.d - rtb_TmpSignalConversionAtMult_2) *
      Controller_ConstB.Gain4 * ((rtb_Add3_e - rtb_Subtract3_g) * 0.5F) -
      rtb_Saturation1 * 94.2477798F) * 0.002F;

    /* Update for DiscreteIntegrator: '<S111>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S111>/gain2'
     *  DiscreteIntegrator: '<S108>/Discrete-Time Integrator5'
     *  Product: '<S111>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_b[1] +=
      CONTROL_PARAM.MC_PITCH_RATE_I *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1] * 0.002F;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_b[1] >=
        CONTROL_PARAM.MC_RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_b[1] =
        CONTROL_PARAM.MC_RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_b[1] <=
          CONTROL_PARAM.MC_RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_b[1] =
          CONTROL_PARAM.MC_RATE_I_MIN;
      }
    }

    /* Update for DiscreteIntegrator: '<S108>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S108>/Gain'
     *  Saturate: '<S104>/Saturation'
     *  Sum: '<S108>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1] += (rtb_Divide_aq_idx_0 -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S113>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[1] += 0.002F *
      rtb_Divide_aq_idx_2;

    /* Signum: '<S118>/Sign3' incorporates:
     *  Sum: '<S118>/Add6'
     */
    rtb_Add3_e = rtb_Gain_c4 + Controller_ConstB.d;

    /* Signum: '<S118>/Sign4' incorporates:
     *  Sum: '<S118>/Subtract3'
     */
    rtb_Subtract3_g = rtb_Gain_c4 - Controller_ConstB.d;

    /* Signum: '<S118>/Sign5' */
    if (rtb_Gain_c4 < 0.0F) {
      rtb_TmpSignalConversionAtMult_2 = -1.0F;
    } else if (rtb_Gain_c4 > 0.0F) {
      rtb_TmpSignalConversionAtMult_2 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_2 = rtb_Gain_c4;
    }

    /* Signum: '<S118>/Sign3' */
    if (rtb_Add3_e < 0.0F) {
      rtb_Add3_e = -1.0F;
    } else {
      if (rtb_Add3_e > 0.0F) {
        rtb_Add3_e = 1.0F;
      }
    }

    /* Signum: '<S118>/Sign4' */
    if (rtb_Subtract3_g < 0.0F) {
      rtb_Subtract3_g = -1.0F;
    } else {
      if (rtb_Subtract3_g > 0.0F) {
        rtb_Subtract3_g = 1.0F;
      }
    }

    /* Signum: '<S118>/Sign6' */
    if (rtb_Gain_c4 < 0.0F) {
      rtb_Saturation1 = -1.0F;
    } else if (rtb_Gain_c4 > 0.0F) {
      rtb_Saturation1 = 1.0F;
    } else {
      rtb_Saturation1 = rtb_Gain_c4;
    }

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
    Controller_DW.Integrator_DSTATE[2] += ((rtb_Gain_c4 / Controller_ConstB.d -
      rtb_TmpSignalConversionAtMult_2) * Controller_ConstB.Gain4 * ((rtb_Add3_e
      - rtb_Subtract3_g) * 0.5F) - rtb_Saturation1 * 94.2477798F) * 0.002F;

    /* Update for DiscreteIntegrator: '<S111>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S111>/gain3'
     *  DiscreteIntegrator: '<S108>/Discrete-Time Integrator5'
     *  Product: '<S111>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_b[2] +=
      CONTROL_PARAM.MC_YAW_RATE_I *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2] * 0.002F;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_b[2] >=
        CONTROL_PARAM.MC_RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_b[2] =
        CONTROL_PARAM.MC_RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_b[2] <=
          CONTROL_PARAM.MC_RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_b[2] =
          CONTROL_PARAM.MC_RATE_I_MIN;
      }
    }

    /* Update for DiscreteIntegrator: '<S108>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S108>/Gain'
     *  Saturate: '<S104>/Saturation'
     *  Sum: '<S108>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2] +=
      (rtb_MatrixConcatenate1_tmp -
       Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S113>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[2] += 0.002F *
      rtb_Divide_aq_idx_3;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_k = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Signum: '<S138>/Sign3' incorporates:
     *  Product: '<S138>/Divide'
     *  Sum: '<S138>/Add6'
     */
    rtb_Add3_e = rtb_Saturation1_n + Controller_ConstB.d_f;

    /* Signum: '<S138>/Sign4' incorporates:
     *  Product: '<S138>/Divide'
     *  Sum: '<S138>/Subtract3'
     */
    rtb_Subtract3_g = rtb_Saturation1_n - Controller_ConstB.d_f;

    /* Signum: '<S138>/Sign5' incorporates:
     *  Product: '<S138>/Divide'
     */
    if (rtb_Saturation1_n < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else if (rtb_Saturation1_n > 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_0 = rtb_Saturation1_n;
    }

    /* Signum: '<S138>/Sign3' */
    if (rtb_Add3_e < 0.0F) {
      rtb_Add3_e = -1.0F;
    } else {
      if (rtb_Add3_e > 0.0F) {
        rtb_Add3_e = 1.0F;
      }
    }

    /* Signum: '<S138>/Sign4' */
    if (rtb_Subtract3_g < 0.0F) {
      rtb_Subtract3_g = -1.0F;
    } else {
      if (rtb_Subtract3_g > 0.0F) {
        rtb_Subtract3_g = 1.0F;
      }
    }

    /* Signum: '<S138>/Sign6' incorporates:
     *  Product: '<S138>/Divide'
     */
    if (rtb_Saturation1_n < 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = -1.0F;
    } else if (rtb_Saturation1_n > 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_1 = rtb_Saturation1_n;
    }

    /* Update for DiscreteIntegrator: '<S135>/Integrator' incorporates:
     *  Constant: '<S138>/const'
     *  Gain: '<S138>/Gain3'
     *  Product: '<S138>/Divide'
     *  Product: '<S138>/Multiply5'
     *  Product: '<S138>/Multiply6'
     *  Sum: '<S138>/Subtract4'
     *  Sum: '<S138>/Subtract5'
     *  Sum: '<S138>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE_l[0] += ((rtb_Saturation1_n /
      Controller_ConstB.d_f - rtb_TmpSignalConversionAtMult_0) *
      Controller_ConstB.Gain4_b * ((rtb_Add3_e - rtb_Subtract3_g) * 0.5F) -
      rtb_TmpSignalConversionAtMult_1 * 78.448F) * 0.002F;

    /* Signum: '<S138>/Sign3' incorporates:
     *  Sum: '<S138>/Add6'
     */
    rtb_Add3_e = rtb_DiscreteTimeIntegrator1_a + Controller_ConstB.d_f;

    /* Signum: '<S138>/Sign4' incorporates:
     *  Sum: '<S138>/Subtract3'
     */
    rtb_Subtract3_g = rtb_DiscreteTimeIntegrator1_a - Controller_ConstB.d_f;

    /* Signum: '<S138>/Sign5' */
    if (rtb_DiscreteTimeIntegrator1_a < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else if (rtb_DiscreteTimeIntegrator1_a > 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_0 = rtb_DiscreteTimeIntegrator1_a;
    }

    /* Signum: '<S138>/Sign3' */
    if (rtb_Add3_e < 0.0F) {
      rtb_Add3_e = -1.0F;
    } else {
      if (rtb_Add3_e > 0.0F) {
        rtb_Add3_e = 1.0F;
      }
    }

    /* Signum: '<S138>/Sign4' */
    if (rtb_Subtract3_g < 0.0F) {
      rtb_Subtract3_g = -1.0F;
    } else {
      if (rtb_Subtract3_g > 0.0F) {
        rtb_Subtract3_g = 1.0F;
      }
    }

    /* Signum: '<S138>/Sign6' */
    if (rtb_DiscreteTimeIntegrator1_a < 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = -1.0F;
    } else if (rtb_DiscreteTimeIntegrator1_a > 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_1 = rtb_DiscreteTimeIntegrator1_a;
    }

    /* Update for DiscreteIntegrator: '<S135>/Integrator' incorporates:
     *  Constant: '<S138>/const'
     *  Gain: '<S138>/Gain3'
     *  Product: '<S138>/Divide'
     *  Product: '<S138>/Multiply5'
     *  Product: '<S138>/Multiply6'
     *  Sum: '<S138>/Subtract4'
     *  Sum: '<S138>/Subtract5'
     *  Sum: '<S138>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE_l[1] += ((rtb_DiscreteTimeIntegrator1_a /
      Controller_ConstB.d_f - rtb_TmpSignalConversionAtMult_0) *
      Controller_ConstB.Gain4_b * ((rtb_Add3_e - rtb_Subtract3_g) * 0.5F) -
      rtb_TmpSignalConversionAtMult_1 * 78.448F) * 0.002F;

    /* Update for DiscreteIntegrator: '<S153>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S153>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_eq += 0.002F *
      Controller_DW.Integrator_DSTATE_j;

    /* Update for DiscreteIntegrator: '<S156>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S156>/ki'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S156>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_l += CONTROL_PARAM.MC_VEL_Z_I *
      rtb_Gain_hl_idx_2 * 0.002F;
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

    /* End of Update for DiscreteIntegrator: '<S156>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S158>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_i += 0.002F *
      rtb_Saturation_idx_0;
    Controller_DW.DiscreteTimeIntegrator1_Prev_ks = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Signum: '<S154>/Sign6' incorporates:
     *  Signum: '<S154>/Sign5'
     */
    if (rtb_a_k < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;

      /* Signum: '<S154>/Sign5' */
      rtb_TmpSignalConversionAtMult_1 = -1.0F;
    } else if (rtb_a_k > 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = 1.0F;

      /* Signum: '<S154>/Sign5' */
      rtb_TmpSignalConversionAtMult_1 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_0 = rtb_a_k;

      /* Signum: '<S154>/Sign5' */
      rtb_TmpSignalConversionAtMult_1 = rtb_a_k;
    }

    /* End of Signum: '<S154>/Sign6' */

    /* Sum: '<S154>/Add6' */
    rtb_Add3_e = rtb_a_k + Controller_ConstB.d_i;

    /* Sum: '<S154>/Subtract3' */
    rtb_Subtract3_g = rtb_a_k - Controller_ConstB.d_i;

    /* Signum: '<S154>/Sign3' */
    if (rtb_Add3_e < 0.0F) {
      rtb_Add3_e = -1.0F;
    } else {
      if (rtb_Add3_e > 0.0F) {
        rtb_Add3_e = 1.0F;
      }
    }

    /* End of Signum: '<S154>/Sign3' */

    /* Signum: '<S154>/Sign4' */
    if (rtb_Subtract3_g < 0.0F) {
      rtb_Subtract3_g = -1.0F;
    } else {
      if (rtb_Subtract3_g > 0.0F) {
        rtb_Subtract3_g = 1.0F;
      }
    }

    /* End of Signum: '<S154>/Sign4' */

    /* Update for DiscreteIntegrator: '<S153>/Integrator' incorporates:
     *  Constant: '<S154>/const'
     *  Gain: '<S154>/Gain3'
     *  Product: '<S154>/Divide'
     *  Product: '<S154>/Multiply5'
     *  Product: '<S154>/Multiply6'
     *  Sum: '<S154>/Subtract4'
     *  Sum: '<S154>/Subtract5'
     *  Sum: '<S154>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE_j += ((rtb_a_k / Controller_ConstB.d_i -
      rtb_TmpSignalConversionAtMult_1) * Controller_ConstB.Gain4_p *
      ((rtb_Add3_e - rtb_Subtract3_g) * 0.5F) - rtb_TmpSignalConversionAtMult_0 *
      78.448F) * 0.002F;
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

  /* Outputs for Atomic SubSystem: '<S8>/VTOL_Control_Allocation' */
#if AIRFRAME == 1

  /* Output and update for atomic system: '<S164>/VTOL1' */
  {
    real32_T rtb_Saturation3;
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

    /* Saturate: '<S181>/Saturation' incorporates:
     *  Bias: '<S181>/Bias'
     *  Bias: '<S181>/Bias1'
     *  Bias: '<S181>/Bias2'
     *  Bias: '<S181>/Bias3'
     *  Constant: '<S181>/Constant'
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

    /* End of Saturate: '<S181>/Saturation' */

    /* Saturate: '<S168>/Saturation1' */
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

    /* End of Saturate: '<S168>/Saturation1' */

    /* Gain: '<S168>/Gain1' incorporates:
     *  Bias: '<S168>/Bias'
     *  Constant: '<S168>/Constant'
     */
    rtb_Gain1_l = ((real32_T)CONTROL_PARAM.MC_OUT_MAX + -1000.0F) * 0.001F;

    /* Saturate: '<S168>/Saturation2' */
    if (rtb_Multiply3[2] > 1.0F) {
      rtb_Saturation3 = 1.0F;
    } else if (rtb_Multiply3[2] < 0.0F) {
      rtb_Saturation3 = 0.0F;
    } else {
      rtb_Saturation3 = rtb_Multiply3[2];
    }

    /* End of Saturate: '<S168>/Saturation2' */
    for (i_p = 0; i_p < 4; i_p++) {
      /* Product: '<S168>/Multiply' */
      rtb_Switch_gr_idx_1_p = Controller_ConstB.VTOL1.pq_column[i_p + 4] *
        rtb_Saturation1_l_idx_1_p + Controller_ConstB.VTOL1.pq_column[i_p] *
        rtb_Saturation1_l_idx_0_p;

      /* Sum: '<S168>/Sum' */
      rtb_Sum_e[i_p] = rtb_Switch_gr_idx_1_p + rtb_Saturation3;

      /* Product: '<S168>/Multiply' */
      rtb_floating_yaw[i_p] = rtb_Switch_gr_idx_1_p;
    }

    /* Gain: '<S168>/Gain2' incorporates:
     *  Bias: '<S168>/Bias1'
     *  Constant: '<S168>/Constant1'
     */
    rtb_Saturation1_l_idx_0_p = ((real32_T)CONTROL_PARAM.MC_OUT_MIN + -1000.0F) *
      0.001F;

    /* MinMax: '<S168>/Max' */
    rtb_Switch_gr_idx_1_p = fmaxf(fmaxf(fmaxf(rtb_Sum_e[0], rtb_Sum_e[1]),
      rtb_Sum_e[2]), rtb_Sum_e[3]);

    /* MinMax: '<S168>/Max1' */
    rtb_Saturation1_l_idx_1_p = fminf(fminf(fminf(rtb_Sum_e[0], rtb_Sum_e[1]),
      rtb_Sum_e[2]), rtb_Sum_e[3]);

    /* Switch: '<S175>/Switch' incorporates:
     *  Logic: '<S175>/Logical Operator'
     *  MinMax: '<S168>/Max'
     *  MinMax: '<S168>/Max1'
     *  RelationalOperator: '<S175>/Relational Operator'
     *  RelationalOperator: '<S175>/Relational Operator1'
     */
    if ((rtb_Switch_gr_idx_1_p > rtb_Gain1_l) || (rtb_Saturation1_l_idx_1_p <
         rtb_Saturation1_l_idx_0_p)) {
      /* Sum: '<S175>/Subtract1' */
      rtb_Switch_gr_idx_0_p = rtb_Gain1_l - rtb_Saturation1_l_idx_0_p;

      /* Sum: '<S175>/Subtract' */
      rtb_Subtract_h = rtb_Switch_gr_idx_1_p - rtb_Saturation1_l_idx_1_p;

      /* Switch: '<S175>/Switch1' incorporates:
       *  Constant: '<S175>/Constant3'
       *  Gain: '<S175>/Gain'
       *  Product: '<S175>/Divide'
       *  RelationalOperator: '<S175>/Relational Operator2'
       *  Sum: '<S175>/Add'
       *  Sum: '<S175>/Subtract2'
       *  Sum: '<S175>/Subtract3'
       */
      if (rtb_Subtract_h > rtb_Switch_gr_idx_0_p) {
        rtb_Switch_gr_idx_0_p /= rtb_Subtract_h;
        rtb_Switch_gr_idx_1_p = ((rtb_Gain1_l - rtb_Switch_gr_idx_1_p) +
          (rtb_Saturation1_l_idx_0_p - rtb_Saturation1_l_idx_1_p)) * 0.5F;
      } else {
        rtb_Switch_gr_idx_0_p = 1.0F;

        /* Switch: '<S175>/Switch2' incorporates:
         *  Constant: '<S175>/Constant3'
         *  RelationalOperator: '<S175>/Relational Operator3'
         *  Sum: '<S175>/Subtract4'
         *  Sum: '<S175>/Subtract5'
         */
        if (rtb_Switch_gr_idx_1_p > rtb_Gain1_l) {
          rtb_Switch_gr_idx_1_p = rtb_Gain1_l - rtb_Switch_gr_idx_1_p;
        } else {
          rtb_Switch_gr_idx_1_p = rtb_Saturation1_l_idx_0_p -
            rtb_Saturation1_l_idx_1_p;
        }

        /* End of Switch: '<S175>/Switch2' */
      }

      /* End of Switch: '<S175>/Switch1' */
    } else {
      rtb_Switch_gr_idx_0_p = 1.0F;
      rtb_Switch_gr_idx_1_p = 0.0F;
    }

    /* End of Switch: '<S175>/Switch' */

    /* Sum: '<S168>/Sum1' */
    rtb_Saturation3 += rtb_Switch_gr_idx_1_p;

    /* Saturate: '<S168>/Saturation3' */
    if (rtb_Saturation3 > 1.0F) {
      rtb_Saturation3 = 1.0F;
    } else {
      if (rtb_Saturation3 < 0.0F) {
        rtb_Saturation3 = 0.0F;
      }
    }

    /* End of Saturate: '<S168>/Saturation3' */

    /* Sum: '<S168>/Sum2' incorporates:
     *  Product: '<S168>/Multiply1'
     */
    rtb_Switch_gr_idx_1_p = rtb_floating_yaw[0] * rtb_Switch_gr_idx_0_p +
      rtb_Saturation3;

    /* Saturate: '<S168>/Saturation4' */
    if (rtb_Switch_gr_idx_1_p > 1.0F) {
      rtb_Switch_gr_idx_1_p = 1.0F;
    } else {
      if (rtb_Switch_gr_idx_1_p < 0.0F) {
        rtb_Switch_gr_idx_1_p = 0.0F;
      }
    }

    /* Sum: '<S168>/Sum3' incorporates:
     *  Product: '<S168>/Multiply2'
     */
    rtb_Sum_e[0] = Controller_ConstB.VTOL1.r_column[0] *
      rtb_Saturation1_l_idx_2_p + rtb_Switch_gr_idx_1_p;

    /* Product: '<S168>/Multiply1' */
    rtb_floating_yaw[0] = rtb_Switch_gr_idx_1_p;

    /* Sum: '<S168>/Sum2' incorporates:
     *  Product: '<S168>/Multiply1'
     */
    rtb_Switch_gr_idx_1_p = rtb_floating_yaw[1] * rtb_Switch_gr_idx_0_p +
      rtb_Saturation3;

    /* Saturate: '<S168>/Saturation4' */
    if (rtb_Switch_gr_idx_1_p > 1.0F) {
      rtb_Switch_gr_idx_1_p = 1.0F;
    } else {
      if (rtb_Switch_gr_idx_1_p < 0.0F) {
        rtb_Switch_gr_idx_1_p = 0.0F;
      }
    }

    /* Sum: '<S168>/Sum3' incorporates:
     *  Product: '<S168>/Multiply2'
     */
    rtb_Sum_e[1] = Controller_ConstB.VTOL1.r_column[1] *
      rtb_Saturation1_l_idx_2_p + rtb_Switch_gr_idx_1_p;

    /* Product: '<S168>/Multiply1' */
    rtb_floating_yaw[1] = rtb_Switch_gr_idx_1_p;

    /* Sum: '<S168>/Sum2' incorporates:
     *  Product: '<S168>/Multiply1'
     */
    rtb_Switch_gr_idx_1_p = rtb_floating_yaw[2] * rtb_Switch_gr_idx_0_p +
      rtb_Saturation3;

    /* Saturate: '<S168>/Saturation4' */
    if (rtb_Switch_gr_idx_1_p > 1.0F) {
      rtb_Switch_gr_idx_1_p = 1.0F;
    } else {
      if (rtb_Switch_gr_idx_1_p < 0.0F) {
        rtb_Switch_gr_idx_1_p = 0.0F;
      }
    }

    /* Sum: '<S168>/Sum3' incorporates:
     *  Product: '<S168>/Multiply2'
     */
    rtb_Sum_e[2] = Controller_ConstB.VTOL1.r_column[2] *
      rtb_Saturation1_l_idx_2_p + rtb_Switch_gr_idx_1_p;

    /* Product: '<S168>/Multiply1' */
    rtb_floating_yaw[2] = rtb_Switch_gr_idx_1_p;

    /* Sum: '<S168>/Sum2' incorporates:
     *  Product: '<S168>/Multiply1'
     */
    rtb_Switch_gr_idx_1_p = rtb_floating_yaw[3] * rtb_Switch_gr_idx_0_p +
      rtb_Saturation3;

    /* Saturate: '<S168>/Saturation4' */
    if (rtb_Switch_gr_idx_1_p > 1.0F) {
      rtb_Switch_gr_idx_1_p = 1.0F;
    } else {
      if (rtb_Switch_gr_idx_1_p < 0.0F) {
        rtb_Switch_gr_idx_1_p = 0.0F;
      }
    }

    /* Sum: '<S168>/Sum3' incorporates:
     *  Product: '<S168>/Multiply2'
     */
    rtb_Sum_e[3] = Controller_ConstB.VTOL1.r_column[3] *
      rtb_Saturation1_l_idx_2_p + rtb_Switch_gr_idx_1_p;

    /* Product: '<S168>/Multiply1' */
    rtb_floating_yaw[3] = rtb_Switch_gr_idx_1_p;

    /* MATLAB Function: '<S168>/R_Remix' */
    Controller_R_Remix(rtb_Sum_e, rtb_Gain1_l, rtb_Saturation1_l_idx_0_p,
                       rtb_floating_yaw);

    /* MultiPortSwitch: '<S171>/Multiport Switch' incorporates:
     *  Constant: '<S172>/Constant1'
     *  Constant: '<S172>/Constant12'
     *  Constant: '<S172>/Constant2'
     *  Constant: '<S172>/Constant7'
     *  DataTypeConversion: '<S181>/Data Type Conversion'
     *  DataTypeConversion: '<S182>/Data Type Conversion'
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
        /* Saturate: '<S182>/Saturation' incorporates:
         *  Constant: '<S182>/Standby'
         *  Reshape: '<S182>/Reshape'
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

      /* Saturate: '<S182>/Saturation' incorporates:
       *  Bias: '<S182>/Bias'
       *  Constant: '<S182>/Constant'
       *  DataTypeConversion: '<S182>/Data Type Conversion'
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

      /* Saturate: '<S182>/Saturation' incorporates:
       *  Bias: '<S182>/Bias1'
       *  Constant: '<S182>/Constant'
       *  DataTypeConversion: '<S182>/Data Type Conversion'
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

      /* Saturate: '<S182>/Saturation' incorporates:
       *  Bias: '<S182>/Bias2'
       *  Constant: '<S182>/Constant'
       *  DataTypeConversion: '<S182>/Data Type Conversion'
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

      /* Saturate: '<S182>/Saturation' incorporates:
       *  Bias: '<S182>/Bias3'
       *  Constant: '<S182>/Constant'
       *  DataTypeConversion: '<S182>/Data Type Conversion'
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

      /* SignalConversion: '<S172>/ConcatBufferAtVector Concatenate2In3' incorporates:
       *  Constant: '<S172>/Constant11'
       *  Constant: '<S172>/Constant12'
       */
      rtb_MatrixConcatenate[10] = 0.0F;

      /* SignalConversion: '<S172>/ConcatBufferAtVector Concatenate2In2' incorporates:
       *  Constant: '<S172>/Constant10'
       */
      rtb_MatrixConcatenate[9] = 0.0F;

      /* SignalConversion: '<S172>/ConcatBufferAtVector Concatenate2In1' incorporates:
       *  Constant: '<S172>/Constant9'
       */
      rtb_MatrixConcatenate[8] = 0.0F;

      /* SignalConversion: '<S172>/ConcatBufferAtVector Concatenate1In4' incorporates:
       *  Constant: '<S172>/Constant8'
       */
      rtb_MatrixConcatenate[7] = 0.0F;
      rtb_MatrixConcatenate[6] = CONTROL_PARAM.FW_PITCH_EFFC *
        CONTROL_PARAM.FW_ELEVATOR_DIR;

      /* SignalConversion: '<S172>/ConcatBufferAtVector Concatenate1In2' incorporates:
       *  Constant: '<S172>/Constant6'
       *  Constant: '<S172>/Constant7'
       */
      rtb_MatrixConcatenate[5] = 0.0F;

      /* SignalConversion: '<S172>/ConcatBufferAtVector Concatenate1In1' incorporates:
       *  Constant: '<S172>/Constant5'
       */
      rtb_MatrixConcatenate[4] = 0.0F;

      /* SignalConversion: '<S172>/ConcatBufferAtVector ConcatenateIn4' incorporates:
       *  Constant: '<S172>/Constant4'
       */
      rtb_MatrixConcatenate[3] = 0.0F;

      /* SignalConversion: '<S172>/ConcatBufferAtVector ConcatenateIn3' incorporates:
       *  Constant: '<S172>/Constant3'
       */
      rtb_MatrixConcatenate[2] = 0.0F;
      rtb_MatrixConcatenate[1] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON2_DIR;
      rtb_MatrixConcatenate[0] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON1_DIR;

      /* Saturate: '<S167>/Saturation5' incorporates:
       *  Constant: '<S172>/Constant1'
       *  Constant: '<S172>/Constant2'
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
        rtb_Saturation3 = 1.0F;
      } else if (rtb_Multiply[2] < -1.0F) {
        rtb_Saturation3 = -1.0F;
      } else {
        rtb_Saturation3 = rtb_Multiply[2];
      }

      /* End of Saturate: '<S167>/Saturation5' */
      for (i_p = 0; i_p < 4; i_p++) {
        /* Bias: '<S167>/Bias' incorporates:
         *  Gain: '<S167>/Gain1'
         *  Product: '<S167>/Multiply1'
         */
        rtb_Saturation5_o[i_p] = 500.0F * (rtb_MatrixConcatenate[i_p + 8] *
          rtb_Saturation3 + (rtb_MatrixConcatenate[i_p + 4] * rtb_Gain1_l +
                             rtb_MatrixConcatenate[i_p] *
                             rtb_Saturation1_l_idx_2_p)) + 1500.0F;

        /* Sum: '<S168>/Sum4' */
        rtb_Saturation1_l_idx_0_p = rtb_Sum_e[i_p] + rtb_floating_yaw[i_p];

        /* Saturate: '<S168>/Saturation5' */
        if (rtb_Saturation1_l_idx_0_p > 1.0F) {
          rtb_Saturation1_l_idx_0_p = 1.0F;
        } else {
          if (rtb_Saturation1_l_idx_0_p < 0.0F) {
            rtb_Saturation1_l_idx_0_p = 0.0F;
          }
        }

        /* End of Saturate: '<S168>/Saturation5' */

        /* DataTypeConversion: '<S168>/Data Type Conversion' incorporates:
         *  Constant: '<S168>/Constant2'
         *  Gain: '<S168>/Gain3'
         *  Sum: '<S168>/Sum5'
         */
        u0_p = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          rtb_Saturation1_l_idx_0_p), 4.2949673E+9F) + 1000U);

        /* Saturate: '<S168>/Saturation' */
        if (u0_p > CONTROL_PARAM.MC_OUT_MAX) {
          rtb_VariantMergeForOutportactua[i_p] = CONTROL_PARAM.MC_OUT_MAX;
        } else if (u0_p < CONTROL_PARAM.MC_OUT_MIN) {
          rtb_VariantMergeForOutportactua[i_p] = CONTROL_PARAM.MC_OUT_MIN;
        } else {
          rtb_VariantMergeForOutportactua[i_p] = u0_p;
        }

        /* End of Saturate: '<S168>/Saturation' */
      }

      /* Saturate: '<S167>/Saturation' */
      if (rtb_Multiply1[0] > 1.0F) {
        rtb_Saturation1_l_idx_2_p = 1.0F;
      } else if (rtb_Multiply1[0] < 0.0F) {
        rtb_Saturation1_l_idx_2_p = 0.0F;
      } else {
        rtb_Saturation1_l_idx_2_p = rtb_Multiply1[0];
      }

      /* End of Saturate: '<S167>/Saturation' */

      /* DataTypeConversion: '<S174>/Data Type Conversion' incorporates:
       *  Constant: '<S174>/Constant1'
       *  Gain: '<S174>/Gain1'
       *  Sum: '<S174>/Sum1'
       */
      u0_p = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
        rtb_Saturation1_l_idx_2_p), 4.2949673E+9F) + 1000U);

      /* Saturate: '<S167>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[4] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[4] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[4] = u0_p;
      }

      /* DataTypeConversion: '<S167>/Data Type Conversion' incorporates:
       *  Bias: '<S167>/Bias1'
       */
      rtb_Saturation1_l_idx_2_p = fmodf(floorf(rtb_Saturation5_o[0] +
        CONTROL_PARAM.SERVO1_BIAS), 65536.0F);
      u0_p = (uint16_T)(rtb_Saturation1_l_idx_2_p < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_l_idx_2_p :
                        (int32_T)(uint16_T)rtb_Saturation1_l_idx_2_p);

      /* Saturate: '<S167>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[5] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[5] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[5] = u0_p;
      }

      /* DataTypeConversion: '<S167>/Data Type Conversion1' incorporates:
       *  Bias: '<S167>/Bias2'
       */
      rtb_Saturation1_l_idx_2_p = fmodf(floorf(rtb_Saturation5_o[1] +
        CONTROL_PARAM.SERVO2_BIAS), 65536.0F);
      u0_p = (uint16_T)(rtb_Saturation1_l_idx_2_p < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_l_idx_2_p :
                        (int32_T)(uint16_T)rtb_Saturation1_l_idx_2_p);

      /* Saturate: '<S167>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[6] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[6] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[6] = u0_p;
      }

      /* DataTypeConversion: '<S167>/Data Type Conversion2' incorporates:
       *  Bias: '<S167>/Bias3'
       */
      rtb_Saturation1_l_idx_2_p = fmodf(floorf(rtb_Saturation5_o[2] +
        CONTROL_PARAM.SERVO3_BIAS), 65536.0F);
      u0_p = (uint16_T)(rtb_Saturation1_l_idx_2_p < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_l_idx_2_p :
                        (int32_T)(uint16_T)rtb_Saturation1_l_idx_2_p);

      /* Saturate: '<S167>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[7] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[7] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[7] = u0_p;
      }

      /* DataTypeConversion: '<S167>/Data Type Conversion3' incorporates:
       *  Bias: '<S167>/Bias4'
       */
      rtb_Saturation1_l_idx_2_p = fmodf(floorf(rtb_Saturation5_o[3] +
        CONTROL_PARAM.SERVO4_BIAS), 65536.0F);
      u0_p = (uint16_T)(rtb_Saturation1_l_idx_2_p < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_l_idx_2_p :
                        (int32_T)(uint16_T)rtb_Saturation1_l_idx_2_p);

      /* Saturate: '<S167>/Saturation1' */
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

    /* End of MultiPortSwitch: '<S171>/Multiport Switch' */
  }

#elif AIRFRAME == 2

  /* Output and update for atomic system: '<S164>/VTOL2' */
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

    /* Saturate: '<S193>/Saturation' incorporates:
     *  Bias: '<S193>/Bias'
     *  Bias: '<S193>/Bias1'
     *  Bias: '<S193>/Bias2'
     *  Bias: '<S193>/Bias3'
     *  Constant: '<S193>/Constant'
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

    /* End of Saturate: '<S193>/Saturation' */

    /* Saturate: '<S184>/Saturation1' */
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

    /* End of Saturate: '<S184>/Saturation1' */

    /* Gain: '<S184>/Gain1' incorporates:
     *  Bias: '<S184>/Bias'
     *  Constant: '<S184>/Constant'
     */
    rtb_Gain1_lm = ((real32_T)CONTROL_PARAM.MC_OUT_MAX + -1000.0F) * 0.001F;

    /* Saturate: '<S184>/Saturation2' */
    if (rtb_Multiply3[2] > 1.0F) {
      rtb_Saturation3_c = 1.0F;
    } else if (rtb_Multiply3[2] < 0.0F) {
      rtb_Saturation3_c = 0.0F;
    } else {
      rtb_Saturation3_c = rtb_Multiply3[2];
    }

    /* End of Saturate: '<S184>/Saturation2' */
    for (i_o = 0; i_o < 4; i_o++) {
      /* Product: '<S184>/Multiply' */
      rtb_Switch_ge_idx_1_o = Controller_ConstB.VTOL2.pq_column[i_o + 4] *
        rtb_Saturation1_p_idx_1_o + Controller_ConstB.VTOL2.pq_column[i_o] *
        rtb_Saturation1_p_idx_0_o;

      /* Sum: '<S184>/Sum' */
      rtb_Sum_m[i_o] = rtb_Switch_ge_idx_1_o + rtb_Saturation3_c;

      /* Product: '<S184>/Multiply' */
      rtb_floating_yaw_n[i_o] = rtb_Switch_ge_idx_1_o;
    }

    /* Gain: '<S184>/Gain2' incorporates:
     *  Bias: '<S184>/Bias1'
     *  Constant: '<S184>/Constant1'
     */
    rtb_Saturation1_p_idx_0_o = ((real32_T)CONTROL_PARAM.MC_OUT_MIN + -1000.0F) *
      0.001F;

    /* MinMax: '<S184>/Max' */
    rtb_Switch_ge_idx_1_o = fmaxf(fmaxf(fmaxf(rtb_Sum_m[0], rtb_Sum_m[1]),
      rtb_Sum_m[2]), rtb_Sum_m[3]);

    /* MinMax: '<S184>/Max1' */
    rtb_Saturation1_p_idx_1_o = fminf(fminf(fminf(rtb_Sum_m[0], rtb_Sum_m[1]),
      rtb_Sum_m[2]), rtb_Sum_m[3]);

    /* Switch: '<S190>/Switch' incorporates:
     *  Logic: '<S190>/Logical Operator'
     *  MinMax: '<S184>/Max'
     *  MinMax: '<S184>/Max1'
     *  RelationalOperator: '<S190>/Relational Operator'
     *  RelationalOperator: '<S190>/Relational Operator1'
     */
    if ((rtb_Switch_ge_idx_1_o > rtb_Gain1_lm) || (rtb_Saturation1_p_idx_1_o <
         rtb_Saturation1_p_idx_0_o)) {
      /* Sum: '<S190>/Subtract1' */
      rtb_Switch_ge_idx_0_o = rtb_Gain1_lm - rtb_Saturation1_p_idx_0_o;

      /* Sum: '<S190>/Subtract' */
      rtb_Subtract_g = rtb_Switch_ge_idx_1_o - rtb_Saturation1_p_idx_1_o;

      /* Switch: '<S190>/Switch1' incorporates:
       *  Constant: '<S190>/Constant3'
       *  Gain: '<S190>/Gain'
       *  Product: '<S190>/Divide'
       *  RelationalOperator: '<S190>/Relational Operator2'
       *  Sum: '<S190>/Add'
       *  Sum: '<S190>/Subtract2'
       *  Sum: '<S190>/Subtract3'
       */
      if (rtb_Subtract_g > rtb_Switch_ge_idx_0_o) {
        rtb_Switch_ge_idx_0_o /= rtb_Subtract_g;
        rtb_Switch_ge_idx_1_o = ((rtb_Gain1_lm - rtb_Switch_ge_idx_1_o) +
          (rtb_Saturation1_p_idx_0_o - rtb_Saturation1_p_idx_1_o)) * 0.5F;
      } else {
        rtb_Switch_ge_idx_0_o = 1.0F;

        /* Switch: '<S190>/Switch2' incorporates:
         *  Constant: '<S190>/Constant3'
         *  RelationalOperator: '<S190>/Relational Operator3'
         *  Sum: '<S190>/Subtract4'
         *  Sum: '<S190>/Subtract5'
         */
        if (rtb_Switch_ge_idx_1_o > rtb_Gain1_lm) {
          rtb_Switch_ge_idx_1_o = rtb_Gain1_lm - rtb_Switch_ge_idx_1_o;
        } else {
          rtb_Switch_ge_idx_1_o = rtb_Saturation1_p_idx_0_o -
            rtb_Saturation1_p_idx_1_o;
        }

        /* End of Switch: '<S190>/Switch2' */
      }

      /* End of Switch: '<S190>/Switch1' */
    } else {
      rtb_Switch_ge_idx_0_o = 1.0F;
      rtb_Switch_ge_idx_1_o = 0.0F;
    }

    /* End of Switch: '<S190>/Switch' */

    /* Sum: '<S184>/Sum1' */
    rtb_Saturation3_c += rtb_Switch_ge_idx_1_o;

    /* Saturate: '<S184>/Saturation3' */
    if (rtb_Saturation3_c > 1.0F) {
      rtb_Saturation3_c = 1.0F;
    } else {
      if (rtb_Saturation3_c < 0.0F) {
        rtb_Saturation3_c = 0.0F;
      }
    }

    /* End of Saturate: '<S184>/Saturation3' */

    /* Sum: '<S184>/Sum2' incorporates:
     *  Product: '<S184>/Multiply1'
     */
    rtb_Switch_ge_idx_1_o = rtb_floating_yaw_n[0] * rtb_Switch_ge_idx_0_o +
      rtb_Saturation3_c;

    /* Saturate: '<S184>/Saturation4' */
    if (rtb_Switch_ge_idx_1_o > 1.0F) {
      rtb_Switch_ge_idx_1_o = 1.0F;
    } else {
      if (rtb_Switch_ge_idx_1_o < 0.0F) {
        rtb_Switch_ge_idx_1_o = 0.0F;
      }
    }

    /* Sum: '<S184>/Sum3' incorporates:
     *  Product: '<S184>/Multiply2'
     */
    rtb_Sum_m[0] = Controller_ConstB.VTOL2.r_column[0] *
      rtb_Saturation1_p_idx_2_o + rtb_Switch_ge_idx_1_o;

    /* Product: '<S184>/Multiply1' */
    rtb_floating_yaw_n[0] = rtb_Switch_ge_idx_1_o;

    /* Sum: '<S184>/Sum2' incorporates:
     *  Product: '<S184>/Multiply1'
     */
    rtb_Switch_ge_idx_1_o = rtb_floating_yaw_n[1] * rtb_Switch_ge_idx_0_o +
      rtb_Saturation3_c;

    /* Saturate: '<S184>/Saturation4' */
    if (rtb_Switch_ge_idx_1_o > 1.0F) {
      rtb_Switch_ge_idx_1_o = 1.0F;
    } else {
      if (rtb_Switch_ge_idx_1_o < 0.0F) {
        rtb_Switch_ge_idx_1_o = 0.0F;
      }
    }

    /* Sum: '<S184>/Sum3' incorporates:
     *  Product: '<S184>/Multiply2'
     */
    rtb_Sum_m[1] = Controller_ConstB.VTOL2.r_column[1] *
      rtb_Saturation1_p_idx_2_o + rtb_Switch_ge_idx_1_o;

    /* Product: '<S184>/Multiply1' */
    rtb_floating_yaw_n[1] = rtb_Switch_ge_idx_1_o;

    /* Sum: '<S184>/Sum2' incorporates:
     *  Product: '<S184>/Multiply1'
     */
    rtb_Switch_ge_idx_1_o = rtb_floating_yaw_n[2] * rtb_Switch_ge_idx_0_o +
      rtb_Saturation3_c;

    /* Saturate: '<S184>/Saturation4' */
    if (rtb_Switch_ge_idx_1_o > 1.0F) {
      rtb_Switch_ge_idx_1_o = 1.0F;
    } else {
      if (rtb_Switch_ge_idx_1_o < 0.0F) {
        rtb_Switch_ge_idx_1_o = 0.0F;
      }
    }

    /* Sum: '<S184>/Sum3' incorporates:
     *  Product: '<S184>/Multiply2'
     */
    rtb_Sum_m[2] = Controller_ConstB.VTOL2.r_column[2] *
      rtb_Saturation1_p_idx_2_o + rtb_Switch_ge_idx_1_o;

    /* Product: '<S184>/Multiply1' */
    rtb_floating_yaw_n[2] = rtb_Switch_ge_idx_1_o;

    /* Sum: '<S184>/Sum2' incorporates:
     *  Product: '<S184>/Multiply1'
     */
    rtb_Switch_ge_idx_1_o = rtb_floating_yaw_n[3] * rtb_Switch_ge_idx_0_o +
      rtb_Saturation3_c;

    /* Saturate: '<S184>/Saturation4' */
    if (rtb_Switch_ge_idx_1_o > 1.0F) {
      rtb_Switch_ge_idx_1_o = 1.0F;
    } else {
      if (rtb_Switch_ge_idx_1_o < 0.0F) {
        rtb_Switch_ge_idx_1_o = 0.0F;
      }
    }

    /* Sum: '<S184>/Sum3' incorporates:
     *  Product: '<S184>/Multiply2'
     */
    rtb_Sum_m[3] = Controller_ConstB.VTOL2.r_column[3] *
      rtb_Saturation1_p_idx_2_o + rtb_Switch_ge_idx_1_o;

    /* Product: '<S184>/Multiply1' */
    rtb_floating_yaw_n[3] = rtb_Switch_ge_idx_1_o;

    /* MATLAB Function: '<S184>/R_Remix' */
    Controller_R_Remix(rtb_Sum_m, rtb_Gain1_lm, rtb_Saturation1_p_idx_0_o,
                       rtb_floating_yaw_n);

    /* MultiPortSwitch: '<S186>/Multiport Switch' incorporates:
     *  Constant: '<S187>/Constant1'
     *  Constant: '<S187>/Constant11'
     *  Constant: '<S187>/Constant12'
     *  Constant: '<S187>/Constant2'
     *  Constant: '<S187>/Constant7'
     *  Constant: '<S187>/Constant8'
     *  DataTypeConversion: '<S193>/Data Type Conversion'
     *  DataTypeConversion: '<S194>/Data Type Conversion'
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
        /* Saturate: '<S194>/Saturation' incorporates:
         *  Constant: '<S194>/Disarm'
         *  Reshape: '<S194>/Reshape'
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

      /* Saturate: '<S194>/Saturation' incorporates:
       *  Bias: '<S194>/Bias'
       *  Constant: '<S194>/Constant'
       *  DataTypeConversion: '<S194>/Data Type Conversion'
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

      /* Saturate: '<S194>/Saturation' incorporates:
       *  Bias: '<S194>/Bias1'
       *  Constant: '<S194>/Constant'
       *  DataTypeConversion: '<S194>/Data Type Conversion'
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

      /* Saturate: '<S194>/Saturation' incorporates:
       *  Bias: '<S194>/Bias2'
       *  Constant: '<S194>/Constant'
       *  DataTypeConversion: '<S194>/Data Type Conversion'
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

      /* Saturate: '<S194>/Saturation' incorporates:
       *  Bias: '<S194>/Bias3'
       *  Constant: '<S194>/Constant'
       *  DataTypeConversion: '<S194>/Data Type Conversion'
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

      /* SignalConversion: '<S187>/ConcatBufferAtVector Concatenate2In2' incorporates:
       *  Constant: '<S187>/Constant10'
       *  Constant: '<S187>/Constant11'
       *  Constant: '<S187>/Constant12'
       */
      rtb_MatrixConcatenate_g[9] = 0.0F;

      /* SignalConversion: '<S187>/ConcatBufferAtVector Concatenate2In1' incorporates:
       *  Constant: '<S187>/Constant9'
       */
      rtb_MatrixConcatenate_g[8] = 0.0F;
      rtb_MatrixConcatenate_g[7] = -CONTROL_PARAM.FW_PITCH_EFFC *
        CONTROL_PARAM.FW_TAIL2_DIR;
      rtb_MatrixConcatenate_g[6] = CONTROL_PARAM.FW_PITCH_EFFC *
        CONTROL_PARAM.FW_TAIL1_DIR;

      /* SignalConversion: '<S187>/ConcatBufferAtVector Concatenate1In2' incorporates:
       *  Constant: '<S187>/Constant6'
       *  Constant: '<S187>/Constant7'
       *  Constant: '<S187>/Constant8'
       */
      rtb_MatrixConcatenate_g[5] = 0.0F;

      /* SignalConversion: '<S187>/ConcatBufferAtVector Concatenate1In1' incorporates:
       *  Constant: '<S187>/Constant5'
       */
      rtb_MatrixConcatenate_g[4] = 0.0F;

      /* SignalConversion: '<S187>/ConcatBufferAtVector ConcatenateIn4' incorporates:
       *  Constant: '<S187>/Constant4'
       */
      rtb_MatrixConcatenate_g[3] = 0.0F;

      /* SignalConversion: '<S187>/ConcatBufferAtVector ConcatenateIn3' incorporates:
       *  Constant: '<S187>/Constant3'
       */
      rtb_MatrixConcatenate_g[2] = 0.0F;
      rtb_MatrixConcatenate_g[1] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON2_DIR;
      rtb_MatrixConcatenate_g[0] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON1_DIR;

      /* Saturate: '<S183>/Saturation5' incorporates:
       *  Constant: '<S187>/Constant1'
       *  Constant: '<S187>/Constant2'
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

      /* End of Saturate: '<S183>/Saturation5' */
      for (i_o = 0; i_o < 4; i_o++) {
        /* Bias: '<S183>/Bias' incorporates:
         *  Gain: '<S183>/Gain1'
         *  Product: '<S183>/Multiply1'
         */
        rtb_Saturation5_m[i_o] = 500.0F * (rtb_MatrixConcatenate_g[i_o + 8] *
          rtb_Saturation3_c + (rtb_MatrixConcatenate_g[i_o + 4] * rtb_Gain1_lm +
          rtb_MatrixConcatenate_g[i_o] * rtb_Saturation1_p_idx_2_o)) + 1500.0F;

        /* Sum: '<S184>/Sum4' */
        rtb_Saturation1_p_idx_0_o = rtb_Sum_m[i_o] + rtb_floating_yaw_n[i_o];

        /* Saturate: '<S184>/Saturation5' */
        if (rtb_Saturation1_p_idx_0_o > 1.0F) {
          rtb_Saturation1_p_idx_0_o = 1.0F;
        } else {
          if (rtb_Saturation1_p_idx_0_o < 0.0F) {
            rtb_Saturation1_p_idx_0_o = 0.0F;
          }
        }

        /* End of Saturate: '<S184>/Saturation5' */

        /* DataTypeConversion: '<S184>/Data Type Conversion' incorporates:
         *  Constant: '<S184>/Constant2'
         *  Gain: '<S184>/Gain3'
         *  Sum: '<S184>/Sum5'
         */
        u0_o = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          rtb_Saturation1_p_idx_0_o), 4.2949673E+9F) + 1000U);

        /* Saturate: '<S184>/Saturation' */
        if (u0_o > CONTROL_PARAM.MC_OUT_MAX) {
          rtb_VariantMergeForOutportactua[i_o] = CONTROL_PARAM.MC_OUT_MAX;
        } else if (u0_o < CONTROL_PARAM.MC_OUT_MIN) {
          rtb_VariantMergeForOutportactua[i_o] = CONTROL_PARAM.MC_OUT_MIN;
        } else {
          rtb_VariantMergeForOutportactua[i_o] = u0_o;
        }

        /* End of Saturate: '<S184>/Saturation' */
      }

      /* Saturate: '<S183>/Saturation4' */
      if (rtb_Multiply1[0] > 1.0F) {
        rtb_Saturation1_p_idx_2_o = 1.0F;
      } else if (rtb_Multiply1[0] < 0.0F) {
        rtb_Saturation1_p_idx_2_o = 0.0F;
      } else {
        rtb_Saturation1_p_idx_2_o = rtb_Multiply1[0];
      }

      /* End of Saturate: '<S183>/Saturation4' */

      /* DataTypeConversion: '<S189>/Data Type Conversion' incorporates:
       *  Constant: '<S189>/Constant1'
       *  Gain: '<S189>/Gain1'
       *  Sum: '<S189>/Sum1'
       */
      u0_o = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
        rtb_Saturation1_p_idx_2_o), 4.2949673E+9F) + 1000U);

      /* Saturate: '<S183>/Saturation1' */
      if (u0_o > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[4] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_o < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[4] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[4] = u0_o;
      }

      /* DataTypeConversion: '<S183>/Data Type Conversion' incorporates:
       *  Bias: '<S183>/Bias1'
       */
      rtb_Saturation1_p_idx_2_o = fmodf(floorf(rtb_Saturation5_m[0] +
        CONTROL_PARAM.SERVO1_BIAS), 65536.0F);
      u0_o = (uint16_T)(rtb_Saturation1_p_idx_2_o < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_p_idx_2_o :
                        (int32_T)(uint16_T)rtb_Saturation1_p_idx_2_o);

      /* Saturate: '<S183>/Saturation1' */
      if (u0_o > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[5] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_o < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[5] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[5] = u0_o;
      }

      /* DataTypeConversion: '<S183>/Data Type Conversion1' incorporates:
       *  Bias: '<S183>/Bias2'
       */
      rtb_Saturation1_p_idx_2_o = fmodf(floorf(rtb_Saturation5_m[1] +
        CONTROL_PARAM.SERVO2_BIAS), 65536.0F);
      u0_o = (uint16_T)(rtb_Saturation1_p_idx_2_o < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_p_idx_2_o :
                        (int32_T)(uint16_T)rtb_Saturation1_p_idx_2_o);

      /* Saturate: '<S183>/Saturation1' */
      if (u0_o > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[6] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_o < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[6] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[6] = u0_o;
      }

      /* DataTypeConversion: '<S183>/Data Type Conversion2' incorporates:
       *  Bias: '<S183>/Bias3'
       */
      rtb_Saturation1_p_idx_2_o = fmodf(floorf(rtb_Saturation5_m[2] +
        CONTROL_PARAM.SERVO3_BIAS), 65536.0F);
      u0_o = (uint16_T)(rtb_Saturation1_p_idx_2_o < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_p_idx_2_o :
                        (int32_T)(uint16_T)rtb_Saturation1_p_idx_2_o);

      /* Saturate: '<S183>/Saturation1' */
      if (u0_o > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[7] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_o < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[7] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[7] = u0_o;
      }

      /* DataTypeConversion: '<S183>/Data Type Conversion3' incorporates:
       *  Bias: '<S183>/Bias4'
       */
      rtb_Saturation1_p_idx_2_o = fmodf(floorf(rtb_Saturation5_m[3] +
        CONTROL_PARAM.SERVO4_BIAS), 65536.0F);
      u0_o = (uint16_T)(rtb_Saturation1_p_idx_2_o < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_p_idx_2_o :
                        (int32_T)(uint16_T)rtb_Saturation1_p_idx_2_o);

      /* Saturate: '<S183>/Saturation1' */
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

    /* End of MultiPortSwitch: '<S186>/Multiport Switch' */
  }

#endif

  /* End of Outputs for SubSystem: '<S8>/VTOL_Control_Allocation' */

  /* Outport: '<Root>/Control_Out' incorporates:
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   *  Reshape: '<S163>/Reshape'
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

  /* Update for DiscreteIntegrator: '<S160>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S160>/Gain'
   *  Sum: '<S160>/Sum5'
   */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;
  Controller_DW.DiscreteTimeIntegrator5_DSTATE += ((real32_T)
    rtb_MultiportSwitch_idx_1 - Controller_DW.DiscreteTimeIntegrator5_DSTATE) *
    6.28318548F * 0.002F;

  /* Update for DiscreteIntegrator: '<S159>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S159>/Gain'
   *  Sum: '<S159>/Sum5'
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
  /* Start for Constant: '<S156>/Constant' */
  Controller_B.Constant = CONTROL_PARAM.MC_VEL_Z_I_MIN;

  /* End of Start for SubSystem: '<S2>/MC_Controller' */

  /* InitializeConditions for DiscreteIntegrator: '<S160>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S159>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_o = 1U;

  /* SystemInitialize for Enabled SubSystem: '<S2>/FW_Controller' */
  /* InitializeConditions for DiscreteIntegrator: '<S87>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_i = 1U;

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
  /* InitializeConditions for DiscreteIntegrator: '<S117>/Integrator1' */
  Controller_DW.Integrator1_DSTATE[0] = 0.0F;
  Controller_DW.Integrator1_DSTATE[1] = 0.0F;
  Controller_DW.Integrator1_DSTATE[2] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S135>/Integrator1' */
  Controller_DW.Integrator1_DSTATE_e[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S140>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = Controller_ConstB.Constant;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] >=
      CONTROL_PARAM.MC_VEL_XY_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
      CONTROL_PARAM.MC_VEL_XY_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] <=
        CONTROL_PARAM.MC_VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
        CONTROL_PARAM.MC_VEL_XY_I_MIN;
    }
  }

  /* InitializeConditions for DiscreteIntegrator: '<S135>/Integrator1' */
  Controller_DW.Integrator1_DSTATE_e[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S140>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = Controller_ConstB.Constant;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] >=
      CONTROL_PARAM.MC_VEL_XY_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
      CONTROL_PARAM.MC_VEL_XY_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] <=
        CONTROL_PARAM.MC_VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
        CONTROL_PARAM.MC_VEL_XY_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRese = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S142>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S117>/Integrator' */
  Controller_DW.Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S111>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_b[0] =
    Controller_ConstB.Constant_a[0];
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_b[0] >=
      CONTROL_PARAM.MC_RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_b[0] =
      CONTROL_PARAM.MC_RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_b[0] <=
        CONTROL_PARAM.MC_RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_b[0] =
        CONTROL_PARAM.MC_RATE_I_MIN;
    }
  }

  /* InitializeConditions for DiscreteIntegrator: '<S117>/Integrator' */
  Controller_DW.Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S111>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_b[1] =
    Controller_ConstB.Constant_a[1];
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_b[1] >=
      CONTROL_PARAM.MC_RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_b[1] =
      CONTROL_PARAM.MC_RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_b[1] <=
        CONTROL_PARAM.MC_RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_b[1] =
        CONTROL_PARAM.MC_RATE_I_MIN;
    }
  }

  /* InitializeConditions for DiscreteIntegrator: '<S117>/Integrator' */
  Controller_DW.Integrator_DSTATE[2] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S111>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_b[2] =
    Controller_ConstB.Constant_a[2];
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_b[2] >=
      CONTROL_PARAM.MC_RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_b[2] =
      CONTROL_PARAM.MC_RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_b[2] <=
        CONTROL_PARAM.MC_RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_b[2] =
        CONTROL_PARAM.MC_RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRe_d = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S108>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_c = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S113>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_k = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S135>/Integrator' */
  Controller_DW.Integrator_DSTATE_l[0] = 0.0F;
  Controller_DW.Integrator_DSTATE_l[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S153>/Integrator1' */
  Controller_DW.Integrator1_DSTATE_eq = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S156>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S156>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S158>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 1U;
  Controller_DW.DiscreteTimeIntegrator1_Prev_ks = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S153>/Integrator' */
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
