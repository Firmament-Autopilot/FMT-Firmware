/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.785
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Sep 22 10:29:21 2025
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
                                        *   '<S50>/Saturation'
                                        *   '<S51>/balabnce_ratio2'
                                        *   '<S51>/balance_ratio'
                                        *   '<S51>/pitch_ff'
                                        *   '<S51>/thorttle_ff'
                                        *   '<S51>/ucmd2pitch'
                                        *   '<S51>/ucmd2thor'
                                        *   '<S51>/wcmd2pitch'
                                        *   '<S51>/wcmd2thor'
                                        *   '<S157>/hover_throttle'
                                        *   '<S53>/FF'
                                        *   '<S74>/P_control'
                                        *   '<S75>/P_control'
                                        *   '<S76>/Kv'
                                        *   '<S137>/Saturation'
                                        *   '<S175>/Bias1'
                                        *   '<S175>/Bias2'
                                        *   '<S175>/Bias3'
                                        *   '<S175>/Bias4'
                                        *   '<S175>/Saturation1'
                                        *   '<S176>/Constant'
                                        *   '<S176>/Constant1'
                                        *   '<S176>/Saturation'
                                        *   '<S191>/Bias1'
                                        *   '<S191>/Bias2'
                                        *   '<S191>/Bias3'
                                        *   '<S191>/Bias4'
                                        *   '<S191>/Saturation1'
                                        *   '<S192>/Constant'
                                        *   '<S192>/Constant1'
                                        *   '<S192>/Saturation'
                                        *   '<S57>/trim_speed'
                                        *   '<S58>/trim_speed'
                                        *   '<S62>/Saturation'
                                        *   '<S82>/Gain'
                                        *   '<S83>/ '
                                        *   '<S83>/Gain3'
                                        *   '<S85>/Gain'
                                        *   '<S86>/Gain'
                                        *   '<S105>/Saturation'
                                        *   '<S105>/Saturation1'
                                        *   '<S105>/Saturation2'
                                        *   '<S148>/kd'
                                        *   '<S148>/Saturation'
                                        *   '<S149>/ki'
                                        *   '<S149>/Discrete-Time Integrator'
                                        *   '<S150>/kp'
                                        *   '<S165>/kd'
                                        *   '<S165>/Saturation'
                                        *   '<S166>/Constant'
                                        *   '<S166>/ki'
                                        *   '<S166>/Discrete-Time Integrator'
                                        *   '<S167>/kp'
                                        *   '<S180>/Constant1'
                                        *   '<S180>/Constant12'
                                        *   '<S180>/Constant2'
                                        *   '<S180>/Constant7'
                                        *   '<S189>/Bias'
                                        *   '<S189>/Bias1'
                                        *   '<S189>/Bias2'
                                        *   '<S189>/Bias3'
                                        *   '<S190>/Bias'
                                        *   '<S190>/Bias1'
                                        *   '<S190>/Bias2'
                                        *   '<S190>/Bias3'
                                        *   '<S195>/Constant1'
                                        *   '<S195>/Constant11'
                                        *   '<S195>/Constant12'
                                        *   '<S195>/Constant2'
                                        *   '<S195>/Constant7'
                                        *   '<S195>/Constant8'
                                        *   '<S201>/Bias'
                                        *   '<S201>/Bias1'
                                        *   '<S201>/Bias2'
                                        *   '<S201>/Bias3'
                                        *   '<S202>/Bias'
                                        *   '<S202>/Bias1'
                                        *   '<S202>/Bias2'
                                        *   '<S202>/Bias3'
                                        *   '<S59>/gain1'
                                        *   '<S59>/gain2'
                                        *   '<S59>/gain3'
                                        *   '<S59>/Discrete-Time Integrator'
                                        *   '<S60>/gain1'
                                        *   '<S60>/gain2'
                                        *   '<S60>/gain3'
                                        *   '<S64>/Pitch Offset'
                                        *   '<S64>/Saturation'
                                        *   '<S65>/Constant1'
                                        *   '<S65>/Constant2'
                                        *   '<S118>/Gain'
                                        *   '<S118>/Gain1'
                                        *   '<S130>/Constant1'
                                        *   '<S130>/Constant2'
                                        *   '<S123>/gain1'
                                        *   '<S123>/gain2'
                                        *   '<S123>/gain3'
                                        *   '<S123>/Saturation'
                                        *   '<S124>/gain1'
                                        *   '<S124>/gain2'
                                        *   '<S124>/gain3'
                                        *   '<S124>/Discrete-Time Integrator'
                                        *   '<S125>/gain1'
                                        *   '<S125>/gain2'
                                        *   '<S125>/gain3'
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
 *    '<S176>/R_Remix'
 *    '<S192>/R_Remix'
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
  real32_T rtb_TmpSignalConversionAtMultip[3];
  real32_T rtb_DiscreteTimeIntegrator1_a;
  real32_T rtb_Saturation1;
  boolean_T rtb_Compare_b;
  real32_T rtb_Integrator1_m;
  real32_T rtb_Subtract3_g;
  real32_T rtb_VdotPg;
  real32_T rtb_Subtract1_jj;
  real32_T rtb_a_k;
  boolean_T rtb_LogicalOperator_h;
  real32_T rtb_Ldot_err;
  real32_T rtb_Gain_c4;
  real32_T rtb_Add4_l;
  real32_T rtb_MatrixConcatenate1[9];
  real32_T rtb_Multiply_ni[3];
  real32_T rtb_Add_k;
  real32_T rtb_Add1_j4;
  int32_T i;
  int32_T rtb_MultiportSwitch_idx_0;
  int32_T rtb_MultiportSwitch_idx_1;
  real32_T rtb_Gain_hl_idx_2;
  real32_T rtb_Divide_m_idx_0;
  real32_T rtb_Divide_m_idx_1;
  real32_T rtb_Divide_m_idx_2;
  real32_T rtb_Divide_m_idx_3;
  real32_T rtb_Subtract1_ha_idx_1;
  uint32_T tmp;

  /* RelationalOperator: '<S170>/Compare' incorporates:
   *  Constant: '<S170>/Constant'
   *  Inport: '<Root>/FMS_Out'
   */
  rtb_Compare = (Controller_U.FMS_Out.ext_state != 2);

  /* MultiPortSwitch: '<S4>/Multiport Switch' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S4>/Constant1'
   *  Constant: '<S4>/Constant2'
   *  Constant: '<S4>/Constant3'
   *  Constant: '<S4>/Constant4'
   *  Constant: '<S4>/Constant6'
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

  /* End of MultiPortSwitch: '<S4>/Multiport Switch' */

  /* DiscreteIntegrator: '<S10>/Discrete-Time Integrator5' */
  if (Controller_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    Controller_DW.DiscreteTimeIntegrator5_DSTATE = (real32_T)
      rtb_MultiportSwitch_idx_1;
  }

  /* DiscreteIntegrator: '<S9>/Discrete-Time Integrator5' */
  if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_o != 0) {
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_k = (real32_T)
      rtb_MultiportSwitch_idx_0;
  }

  /* RelationalOperator: '<S169>/Compare' incorporates:
   *  Constant: '<S169>/Constant'
   *  Inport: '<Root>/FMS_Out'
   */
  rtb_Compare_m = (Controller_U.FMS_Out.ext_state != 0);

  /* Outputs for Enabled SubSystem: '<S2>/FW_Controller' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  if (rtb_Compare_m) {
    if (!Controller_DW.FW_Controller_MODE) {
      /* InitializeConditions for DiscreteIntegrator: '<S91>/Discrete-Time Integrator5' */
      Controller_DW.DiscreteTimeIntegrator5_IC_LO_i = 1U;

      /* InitializeConditions for DiscreteIntegrator: '<S70>/Integrator1' */
      Controller_DW.Integrator1_DSTATE_c = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S88>/Discrete-Time Integrator5' */
      Controller_DW.DiscreteTimeIntegrator5_IC_LO_n = 1U;

      /* InitializeConditions for DiscreteIntegrator: '<S83>/ ' */
      Controller_DW._DSTATE = Controller_ConstB.Zero1;
      if (Controller_DW._DSTATE >= CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
        Controller_DW._DSTATE = CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
      } else {
        if (Controller_DW._DSTATE <= -CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
          Controller_DW._DSTATE = -CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
        }
      }

      Controller_DW._PrevResetState = 0;

      /* End of InitializeConditions for DiscreteIntegrator: '<S83>/ ' */

      /* InitializeConditions for DiscreteIntegrator: '<S84>/Discrete-Time Integrator1' */
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_f = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevR_b = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S59>/Discrete-Time Integrator' */
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

      /* End of InitializeConditions for DiscreteIntegrator: '<S59>/Discrete-Time Integrator' */

      /* InitializeConditions for DiscreteIntegrator: '<S86>/ ' */
      Controller_DW._DSTATE_d = Controller_ConstB.Zero;
      if (Controller_DW._DSTATE_d >= 1.0F) {
        Controller_DW._DSTATE_d = 1.0F;
      } else {
        if (Controller_DW._DSTATE_d <= 0.0F) {
          Controller_DW._DSTATE_d = 0.0F;
        }
      }

      Controller_DW._PrevResetState_e = 0;

      /* End of InitializeConditions for DiscreteIntegrator: '<S86>/ ' */

      /* InitializeConditions for DiscreteIntegrator: '<S87>/Discrete-Time Integrator1' */
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_h = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevR_d = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S70>/Integrator' */
      Controller_DW.Integrator_DSTATE_n = 0.0F;
      Controller_DW.FW_Controller_MODE = true;
    }

    /* SignalConversion: '<S78>/TmpSignal ConversionAtMultiplyInport2' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_TmpSignalConversionAtMultip[0] = Controller_U.INS_Out.vn;
    rtb_TmpSignalConversionAtMultip[1] = Controller_U.INS_Out.ve;
    rtb_TmpSignalConversionAtMultip[2] = Controller_U.INS_Out.vd;

    /* Switch: '<S14>/Switch' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  S-Function (sfix_bitop): '<S14>/airspeed_valid'
     */
    if ((Controller_U.INS_Out.flag & 512U) > 0U) {
      rtb_DiscreteTimeIntegrator1_a = Controller_U.INS_Out.airspeed;
    } else {
      /* Sqrt: '<S98>/Sqrt' incorporates:
       *  Math: '<S98>/Square'
       *  Sum: '<S98>/Sum of Elements'
       */
      rtb_Add_k = sqrtf(((Controller_U.INS_Out.quat[0] *
                          Controller_U.INS_Out.quat[0] +
                          Controller_U.INS_Out.quat[1] *
                          Controller_U.INS_Out.quat[1]) +
                         Controller_U.INS_Out.quat[2] *
                         Controller_U.INS_Out.quat[2]) +
                        Controller_U.INS_Out.quat[3] *
                        Controller_U.INS_Out.quat[3]);

      /* Product: '<S94>/Divide' incorporates:
       *  Sqrt: '<S98>/Sqrt'
       */
      rtb_Divide_m_idx_0 = Controller_U.INS_Out.quat[0] / rtb_Add_k;
      rtb_Divide_m_idx_1 = Controller_U.INS_Out.quat[1] / rtb_Add_k;
      rtb_Divide_m_idx_2 = Controller_U.INS_Out.quat[2] / rtb_Add_k;
      rtb_Divide_m_idx_3 = Controller_U.INS_Out.quat[3] / rtb_Add_k;

      /* Math: '<S97>/Square' incorporates:
       *  Math: '<S95>/Square'
       *  Math: '<S96>/Square'
       */
      rtb_Add_k = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_0;

      /* Math: '<S97>/Square2' incorporates:
       *  Math: '<S95>/Square2'
       *  Math: '<S96>/Square2'
       */
      rtb_Add1_j4 = rtb_Divide_m_idx_2 * rtb_Divide_m_idx_2;

      /* Math: '<S97>/Square1' incorporates:
       *  Math: '<S95>/Square1'
       *  Math: '<S96>/Square1'
       */
      rtb_Subtract3_g = rtb_Divide_m_idx_1 * rtb_Divide_m_idx_1;

      /* Math: '<S97>/Square3' incorporates:
       *  Math: '<S95>/Square3'
       *  Math: '<S96>/Square3'
       */
      rtb_Saturation1 = rtb_Divide_m_idx_3 * rtb_Divide_m_idx_3;

      /* Sum: '<S97>/Subtract' incorporates:
       *  Math: '<S97>/Square'
       *  Math: '<S97>/Square1'
       *  Math: '<S97>/Square2'
       *  Math: '<S97>/Square3'
       *  Sum: '<S97>/Add'
       *  Sum: '<S97>/Add1'
       */
      rtb_MatrixConcatenate1[8] = (rtb_Add_k + rtb_Saturation1) -
        (rtb_Subtract3_g + rtb_Add1_j4);

      /* Product: '<S97>/Multiply2' incorporates:
       *  Product: '<S96>/Multiply2'
       */
      rtb_Ldot_err = rtb_Divide_m_idx_2 * rtb_Divide_m_idx_3;

      /* Product: '<S97>/Multiply3' incorporates:
       *  Product: '<S96>/Multiply3'
       */
      rtb_Gain_c4 = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_1;

      /* Gain: '<S97>/Gain1' incorporates:
       *  Product: '<S97>/Multiply2'
       *  Product: '<S97>/Multiply3'
       *  Sum: '<S97>/Add2'
       */
      rtb_MatrixConcatenate1[7] = (rtb_Ldot_err + rtb_Gain_c4) * 2.0F;

      /* Product: '<S97>/Multiply' incorporates:
       *  Product: '<S95>/Multiply2'
       */
      rtb_VdotPg = rtb_Divide_m_idx_1 * rtb_Divide_m_idx_3;

      /* Product: '<S97>/Multiply1' incorporates:
       *  Product: '<S95>/Multiply3'
       */
      rtb_Integrator1_m = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_2;

      /* Gain: '<S97>/Gain' incorporates:
       *  Product: '<S97>/Multiply'
       *  Product: '<S97>/Multiply1'
       *  Sum: '<S97>/Subtract2'
       */
      rtb_MatrixConcatenate1[6] = (rtb_VdotPg - rtb_Integrator1_m) * 2.0F;

      /* Gain: '<S96>/Gain1' incorporates:
       *  Sum: '<S96>/Subtract1'
       */
      rtb_MatrixConcatenate1[5] = (rtb_Ldot_err - rtb_Gain_c4) * 2.0F;

      /* Sum: '<S96>/Subtract' incorporates:
       *  Sum: '<S96>/Add'
       *  Sum: '<S96>/Add1'
       */
      rtb_MatrixConcatenate1[4] = (rtb_Add_k + rtb_Add1_j4) - (rtb_Subtract3_g +
        rtb_Saturation1);

      /* Product: '<S96>/Multiply' incorporates:
       *  Product: '<S95>/Multiply'
       */
      rtb_Ldot_err = rtb_Divide_m_idx_1 * rtb_Divide_m_idx_2;

      /* Product: '<S96>/Multiply1' incorporates:
       *  Product: '<S95>/Multiply1'
       */
      rtb_Gain_c4 = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_3;

      /* Gain: '<S96>/Gain' incorporates:
       *  Product: '<S96>/Multiply'
       *  Product: '<S96>/Multiply1'
       *  Sum: '<S96>/Add3'
       */
      rtb_MatrixConcatenate1[3] = (rtb_Ldot_err + rtb_Gain_c4) * 2.0F;

      /* Gain: '<S95>/Gain1' incorporates:
       *  Sum: '<S95>/Add2'
       */
      rtb_MatrixConcatenate1[2] = (rtb_VdotPg + rtb_Integrator1_m) * 2.0F;

      /* Gain: '<S95>/Gain' incorporates:
       *  Sum: '<S95>/Subtract1'
       */
      rtb_MatrixConcatenate1[1] = (rtb_Ldot_err - rtb_Gain_c4) * 2.0F;

      /* Sum: '<S95>/Subtract' incorporates:
       *  Sum: '<S95>/Add'
       *  Sum: '<S95>/Add1'
       */
      rtb_MatrixConcatenate1[0] = (rtb_Add_k + rtb_Subtract3_g) - (rtb_Add1_j4 +
        rtb_Saturation1);

      /* Product: '<S92>/Multiply' */
      for (i = 0; i < 3; i++) {
        rtb_Multiply_ni[i] = rtb_MatrixConcatenate1[i + 6] *
          rtb_TmpSignalConversionAtMultip[2] + (rtb_MatrixConcatenate1[i + 3] *
          rtb_TmpSignalConversionAtMultip[1] + rtb_MatrixConcatenate1[i] *
          rtb_TmpSignalConversionAtMultip[0]);
      }

      /* End of Product: '<S92>/Multiply' */
      rtb_DiscreteTimeIntegrator1_a = rtb_Multiply_ni[0];
    }

    /* End of Switch: '<S14>/Switch' */

    /* Saturate: '<S14>/Saturation1' */
    if (rtb_DiscreteTimeIntegrator1_a > 100.0F) {
      rtb_Saturation1 = 100.0F;
    } else if (rtb_DiscreteTimeIntegrator1_a < 0.1F) {
      rtb_Saturation1 = 0.1F;
    } else {
      rtb_Saturation1 = rtb_DiscreteTimeIntegrator1_a;
    }

    /* End of Saturate: '<S14>/Saturation1' */

    /* DiscreteIntegrator: '<S91>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_i != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j = rtb_Saturation1;
    }

    /* Switch: '<S63>/Switch' incorporates:
     *  Inport: '<Root>/FMS_Out'
     *  Logic: '<S63>/Logical Operator'
     *  RelationalOperator: '<S68>/Compare'
     */
    if ((Controller_U.FMS_Out.ctrl_mode == 3) || (Controller_U.FMS_Out.ctrl_mode
         == 4)) {
      rtb_DiscreteTimeIntegrator1_a = Controller_U.FMS_Out.phi_cmd;
    } else {
      /* Trigonometry: '<S50>/Atan' incorporates:
       *  DiscreteIntegrator: '<S70>/Integrator1'
       *  Gain: '<S50>/g_force'
       */
      rtb_DiscreteTimeIntegrator1_a = atanf(0.101936802F *
        Controller_DW.Integrator1_DSTATE_c);

      /* Saturate: '<S50>/Saturation' */
      if (rtb_DiscreteTimeIntegrator1_a > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_DiscreteTimeIntegrator1_a = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_DiscreteTimeIntegrator1_a < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM)
        {
          rtb_DiscreteTimeIntegrator1_a = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
        }
      }

      /* End of Saturate: '<S50>/Saturation' */
    }

    /* End of Switch: '<S63>/Switch' */

    /* RelationalOperator: '<S72>/Compare' incorporates:
     *  Constant: '<S72>/Constant'
     *  Inport: '<Root>/FMS_Out'
     */
    rtb_Compare_b = (Controller_U.FMS_Out.ext_state == 1);

    /* S-Function (sfix_bitop): '<S78>/Bitwise AND' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  S-Function (sfix_bitop): '<S77>/Bitwise AND'
     *  S-Function (sfix_bitop): '<S79>/Bitwise AND'
     */
    tmp = Controller_U.INS_Out.flag & 16U;

    /* Switch: '<S78>/Switch' incorporates:
     *  Constant: '<S78>/Constant'
     *  S-Function (sfix_bitop): '<S78>/Bitwise AND'
     */
    if (tmp > 0U) {
      /* SignalConversion: '<S81>/ConcatBufferAtVector ConcatenateIn3' */
      rtb_MatrixConcatenate1[6] = Controller_ConstB.VectorConcatenate3_g[0];
      rtb_MatrixConcatenate1[7] = Controller_ConstB.VectorConcatenate3_g[1];
      rtb_MatrixConcatenate1[8] = Controller_ConstB.VectorConcatenate3_g[2];

      /* SignalConversion: '<S81>/ConcatBufferAtVector Concatenate2In3' incorporates:
       *  Constant: '<S81>/Constant4'
       */
      rtb_MatrixConcatenate1[5] = 0.0F;

      /* Trigonometry: '<S81>/Trigonometric Function3' incorporates:
       *  Gain: '<S80>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S81>/Trigonometric Function1'
       */
      rtb_Add_k = arm_cos_f32(-Controller_U.INS_Out.psi);
      rtb_MatrixConcatenate1[4] = rtb_Add_k;

      /* Trigonometry: '<S81>/Trigonometric Function2' incorporates:
       *  Gain: '<S80>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S81>/Trigonometric Function'
       */
      rtb_Add1_j4 = arm_sin_f32(-Controller_U.INS_Out.psi);

      /* Gain: '<S81>/Gain' incorporates:
       *  Trigonometry: '<S81>/Trigonometric Function2'
       */
      rtb_MatrixConcatenate1[3] = -rtb_Add1_j4;

      /* SignalConversion: '<S81>/ConcatBufferAtVector Concatenate1In3' incorporates:
       *  Constant: '<S81>/Constant3'
       */
      rtb_MatrixConcatenate1[2] = 0.0F;

      /* Trigonometry: '<S81>/Trigonometric Function' */
      rtb_MatrixConcatenate1[1] = rtb_Add1_j4;

      /* Trigonometry: '<S81>/Trigonometric Function1' */
      rtb_MatrixConcatenate1[0] = rtb_Add_k;

      /* Product: '<S78>/Multiply' */
      for (i = 0; i < 3; i++) {
        rtb_Multiply_ni[i] = rtb_MatrixConcatenate1[i + 6] *
          rtb_TmpSignalConversionAtMultip[2] + (rtb_MatrixConcatenate1[i + 3] *
          rtb_TmpSignalConversionAtMultip[1] + rtb_MatrixConcatenate1[i] *
          rtb_TmpSignalConversionAtMultip[0]);
      }

      /* End of Product: '<S78>/Multiply' */

      /* DeadZone: '<S78>/Dead Zone' */
      if (rtb_Multiply_ni[0] > 1.0F) {
        rtb_Integrator1_m = rtb_Multiply_ni[0] - 1.0F;
      } else if (rtb_Multiply_ni[0] >= -1.0F) {
        rtb_Integrator1_m = 0.0F;
      } else {
        rtb_Integrator1_m = rtb_Multiply_ni[0] - -1.0F;
      }

      /* End of DeadZone: '<S78>/Dead Zone' */

      /* Signum: '<S78>/Sign' */
      if (rtb_Integrator1_m < 0.0F) {
        rtb_Integrator1_m = -1.0F;
      } else {
        if (rtb_Integrator1_m > 0.0F) {
          rtb_Integrator1_m = 1.0F;
        }
      }

      /* End of Signum: '<S78>/Sign' */
    } else {
      rtb_Integrator1_m = 1.0F;
    }

    /* End of Switch: '<S78>/Switch' */

    /* Switch: '<S77>/Switch' incorporates:
     *  Gain: '<S77>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S77>/Divide'
     *  Trigonometry: '<S77>/Asin'
     */
    if (tmp > 1U) {
      /* Sqrt: '<S77>/Sqrt' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Math: '<S77>/Square'
       *  Math: '<S77>/Square1'
       *  Sum: '<S77>/Add'
       */
      rtb_Divide_m_idx_0 = sqrtf(Controller_U.INS_Out.vn *
        Controller_U.INS_Out.vn + Controller_U.INS_Out.ve *
        Controller_U.INS_Out.ve);

      /* Saturate: '<S77>/Saturation' incorporates:
       *  Sqrt: '<S77>/Sqrt'
       */
      if (rtb_Divide_m_idx_0 > 100.0F) {
        rtb_Divide_m_idx_0 = 100.0F;
      } else {
        if (rtb_Divide_m_idx_0 < 8.0F) {
          rtb_Divide_m_idx_0 = 8.0F;
        }
      }

      /* End of Saturate: '<S77>/Saturation' */

      /* DeadZone: '<S77>/Dead Zone' incorporates:
       *  Inport: '<Root>/INS_Out'
       */
      if (Controller_U.INS_Out.vd > 0.1F) {
        rtb_a_k = Controller_U.INS_Out.vd - 0.1F;
      } else if (Controller_U.INS_Out.vd >= -0.1F) {
        rtb_a_k = 0.0F;
      } else {
        rtb_a_k = Controller_U.INS_Out.vd - -0.1F;
      }

      /* End of DeadZone: '<S77>/Dead Zone' */
      rtb_Subtract3_g = atanf(1.0F / rtb_Divide_m_idx_0 * -rtb_a_k);
    } else {
      rtb_Subtract3_g = Controller_U.INS_Out.theta;
    }

    /* End of Switch: '<S77>/Switch' */

    /* Product: '<S77>/Multiply1' */
    rtb_Subtract3_g *= rtb_Integrator1_m;

    /* Saturate: '<S77>/Saturation1' */
    if (rtb_Subtract3_g > 0.785398185F) {
      rtb_Subtract3_g = 0.785398185F;
    } else {
      if (rtb_Subtract3_g < -0.785398185F) {
        rtb_Subtract3_g = -0.785398185F;
      }
    }

    /* End of Saturate: '<S77>/Saturation1' */

    /* DiscreteIntegrator: '<S88>/Discrete-Time Integrator5' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_n != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_f = Controller_U.INS_Out.ax;
    }

    /* Gain: '<S76>/Gain1' incorporates:
     *  DiscreteIntegrator: '<S88>/Discrete-Time Integrator5'
     */
    rtb_VdotPg = 0.101936802F * Controller_DW.DiscreteTimeIntegrator5_DSTAT_f;

    /* Switch: '<S79>/Switch' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Math: '<S79>/Square'
     *  Math: '<S79>/Square1'
     *  Sqrt: '<S79>/Sqrt'
     *  Sum: '<S79>/Add'
     */
    if (tmp > 0U) {
      rtb_a_k = sqrtf(Controller_U.INS_Out.vn * Controller_U.INS_Out.vn +
                      Controller_U.INS_Out.ve * Controller_U.INS_Out.ve);
    } else {
      rtb_a_k = Controller_U.INS_Out.airspeed;
    }

    /* End of Switch: '<S79>/Switch' */

    /* Saturate: '<S79>/Saturation1' */
    if (rtb_a_k > 100.0F) {
      rtb_a_k = 100.0F;
    } else {
      if (rtb_a_k < 8.0F) {
        rtb_a_k = 8.0F;
      }
    }

    /* End of Saturate: '<S79>/Saturation1' */

    /* Product: '<S79>/Multiply1' incorporates:
     *  Gain: '<S79>/Gain'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S79>/Divide'
     *  Trigonometry: '<S79>/Asin'
     */
    rtb_Integrator1_m *= atanf(-Controller_U.FMS_Out.w_cmd / rtb_a_k);

    /* Saturate: '<S79>/Saturation2' */
    if (rtb_Integrator1_m > 0.785398185F) {
      rtb_Integrator1_m = 0.785398185F;
    } else {
      if (rtb_Integrator1_m < -0.785398185F) {
        rtb_Integrator1_m = -0.785398185F;
      }
    }

    /* End of Saturate: '<S79>/Saturation2' */

    /* Sum: '<S73>/Sum' */
    rtb_Integrator1_m -= rtb_Subtract3_g;

    /* Sum: '<S76>/Sum' incorporates:
     *  DiscreteIntegrator: '<S91>/Discrete-Time Integrator5'
     *  Gain: '<S76>/Gain'
     *  Gain: '<S76>/Kv'
     *  Inport: '<Root>/FMS_Out'
     *  Sum: '<S76>/Minus'
     */
    rtb_Subtract1_jj = (Controller_U.FMS_Out.u_cmd -
                        Controller_DW.DiscreteTimeIntegrator5_DSTAT_j) *
      CONTROL_PARAM.FW_TECS_VEL_P * 0.101936802F - rtb_VdotPg;

    /* Sum: '<S51>/Minus1' incorporates:
     *  Gain: '<S51>/ucmd2pitch'
     *  Gain: '<S51>/wcmd2pitch'
     */
    rtb_Ldot_err = CONTROL_PARAM.FW_TECS_W2P * rtb_Integrator1_m -
      CONTROL_PARAM.FW_TECS_U2P * rtb_Subtract1_jj;

    /* Logic: '<S51>/Logical Operator' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    rtb_LogicalOperator_h = ((Controller_U.FMS_Out.reset != 0) || rtb_Compare_b);

    /* DiscreteIntegrator: '<S83>/ ' */
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

    /* DiscreteIntegrator: '<S84>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_f != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_e = rtb_Ldot_err;
    }

    if (rtb_LogicalOperator_h || (Controller_DW.DiscreteTimeIntegrator1_PrevR_b
         != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_e = rtb_Ldot_err;
    }

    /* Gain: '<S84>/Gain' incorporates:
     *  DiscreteIntegrator: '<S84>/Discrete-Time Integrator1'
     *  Sum: '<S84>/Sum5'
     */
    rtb_Gain_c4 = (rtb_Ldot_err - Controller_DW.DiscreteTimeIntegrator1_DSTAT_e)
      * 62.831852F;

    /* Switch: '<S63>/Switch1' incorporates:
     *  Constant: '<S69>/Constant'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S69>/Compare'
     *  Switch: '<S51>/Switch'
     *  Switch: '<S84>/Switch'
     */
    if (Controller_U.FMS_Out.ctrl_mode == 3) {
      rtb_Divide_m_idx_1 = Controller_U.FMS_Out.theta_cmd;
    } else if (rtb_Compare_b) {
      /* Switch: '<S51>/Switch' incorporates:
       *  Constant: '<S51>/Constant'
       */
      rtb_Divide_m_idx_1 = 0.0F;
    } else {
      if (rtb_LogicalOperator_h) {
        /* Switch: '<S84>/Switch' incorporates:
         *  Gain: '<S84>/Gain1'
         *  Switch: '<S51>/Switch'
         */
        rtb_Divide_m_idx_0 = 0.0F;
      } else {
        /* Switch: '<S84>/Switch' incorporates:
         *  Switch: '<S51>/Switch'
         */
        rtb_Divide_m_idx_0 = rtb_Gain_c4;
      }

      /* Gain: '<S82>/Gain' incorporates:
       *  Switch: '<S51>/Switch'
       */
      rtb_Divide_m_idx_0 *= CONTROL_PARAM.FW_TECS_PITCH_D;

      /* Saturate: '<S74>/Saturation1' incorporates:
       *  Switch: '<S51>/Switch'
       */
      if (rtb_Divide_m_idx_0 > 0.3F) {
        rtb_Divide_m_idx_0 = 0.3F;
      } else {
        if (rtb_Divide_m_idx_0 < -0.3F) {
          rtb_Divide_m_idx_0 = -0.3F;
        }
      }

      /* End of Saturate: '<S74>/Saturation1' */

      /* Switch: '<S51>/Switch' incorporates:
       *  DiscreteIntegrator: '<S83>/ '
       *  Gain: '<S51>/balabnce_ratio2'
       *  Gain: '<S51>/balance_ratio'
       *  Gain: '<S51>/pitch_ff'
       *  Gain: '<S74>/P_control'
       *  Sum: '<S51>/Add3'
       *  Sum: '<S51>/Minus'
       *  Sum: '<S74>/Add'
       */
      rtb_Divide_m_idx_1 = ((2.0F - CONTROL_PARAM.FW_TECS_RATIO) *
                            rtb_Subtract3_g - CONTROL_PARAM.FW_TECS_RATIO *
                            rtb_VdotPg) * CONTROL_PARAM.FW_TECS_PITCH_F +
        ((CONTROL_PARAM.FW_TECS_PITCH_P * rtb_Ldot_err + Controller_DW._DSTATE)
         + rtb_Divide_m_idx_0);
    }

    /* End of Switch: '<S63>/Switch1' */

    /* Saturate: '<S64>/Saturation' */
    if (rtb_DiscreteTimeIntegrator1_a > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Divide_m_idx_0 = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else if (rtb_DiscreteTimeIntegrator1_a <
               -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Divide_m_idx_0 = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      rtb_Divide_m_idx_0 = rtb_DiscreteTimeIntegrator1_a;
    }

    /* Reshape: '<S54>/Reshape' incorporates:
     *  Constant: '<S65>/Constant1'
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S65>/Multiply'
     *  Sum: '<S64>/Sum'
     */
    Controller_B.Reshape[0] = (rtb_Divide_m_idx_0 - Controller_U.INS_Out.phi) *
      CONTROL_PARAM.FW_ROLL_P;

    /* Bias: '<S64>/Pitch Offset' */
    rtb_Divide_m_idx_0 = rtb_Divide_m_idx_1 + CONTROL_PARAM.FW_PITCH_OFFSET;

    /* Saturate: '<S64>/Saturation' */
    if (rtb_Divide_m_idx_0 > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Divide_m_idx_0 = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_Divide_m_idx_0 < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_Divide_m_idx_0 = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      }
    }

    /* Reshape: '<S54>/Reshape' incorporates:
     *  Constant: '<S65>/Constant2'
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S65>/Multiply'
     *  Sum: '<S64>/Sum'
     */
    Controller_B.Reshape[1] = (rtb_Divide_m_idx_0 - Controller_U.INS_Out.theta) *
      CONTROL_PARAM.FW_PITCH_P;

    /* Product: '<S67>/Divide' incorporates:
     *  Constant: '<S67>/Constant'
     *  DiscreteIntegrator: '<S91>/Discrete-Time Integrator5'
     */
    rtb_Divide_m_idx_0 = 9.81F / Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;

    /* Saturate: '<S67>/Saturation' */
    if (rtb_Divide_m_idx_0 > 1.0F) {
      rtb_Divide_m_idx_0 = 1.0F;
    } else {
      if (rtb_Divide_m_idx_0 < 0.2F) {
        rtb_Divide_m_idx_0 = 0.2F;
      }
    }

    /* End of Saturate: '<S67>/Saturation' */

    /* Sum: '<S62>/Sum' incorporates:
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S67>/Multiply'
     *  Product: '<S67>/Multiply1'
     *  Trigonometry: '<S67>/Cos'
     *  Trigonometry: '<S67>/Tan'
     */
    rtb_Divide_m_idx_0 = tanf(rtb_DiscreteTimeIntegrator1_a) * arm_cos_f32
      (rtb_Divide_m_idx_1) * rtb_Divide_m_idx_0 +
      Controller_U.FMS_Out.psi_rate_cmd;

    /* Saturate: '<S62>/Saturation' */
    if (rtb_Divide_m_idx_0 > CONTROL_PARAM.FW_YAW_RATE_LIM) {
      /* Reshape: '<S54>/Reshape' */
      Controller_B.Reshape[2] = CONTROL_PARAM.FW_YAW_RATE_LIM;
    } else if (rtb_Divide_m_idx_0 < -CONTROL_PARAM.FW_YAW_RATE_LIM) {
      /* Reshape: '<S54>/Reshape' */
      Controller_B.Reshape[2] = -CONTROL_PARAM.FW_YAW_RATE_LIM;
    } else {
      /* Reshape: '<S54>/Reshape' */
      Controller_B.Reshape[2] = rtb_Divide_m_idx_0;
    }

    /* End of Saturate: '<S62>/Saturation' */

    /* Sum: '<S55>/Add' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S55>/Multiply'
     *  Trigonometry: '<S55>/Sin1'
     */
    rtb_Add_k = Controller_B.Reshape[0] - arm_sin_f32(Controller_U.INS_Out.theta)
      * Controller_B.Reshape[2];

    /* Trigonometry: '<S55>/Sin' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_m_idx_0 = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S55>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_m_idx_1 = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Trigonometry: '<S55>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_m_idx_2 = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Sum: '<S55>/Add1' incorporates:
     *  Product: '<S55>/Multiply1'
     *  Product: '<S55>/Multiply3'
     *  Trigonometry: '<S55>/Cos'
     *  Trigonometry: '<S55>/Cos1'
     *  Trigonometry: '<S55>/Sin'
     */
    rtb_Add1_j4 = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_1 *
      Controller_B.Reshape[2] + rtb_Divide_m_idx_2 * Controller_B.Reshape[1];

    /* Sum: '<S55>/Add2' incorporates:
     *  Product: '<S55>/Multiply4'
     *  Product: '<S55>/Multiply5'
     *  Trigonometry: '<S55>/Cos'
     *  Trigonometry: '<S55>/Cos1'
     *  Trigonometry: '<S55>/Sin'
     */
    rtb_Divide_m_idx_3 = rtb_Divide_m_idx_2 * rtb_Divide_m_idx_1 *
      Controller_B.Reshape[2] - rtb_Divide_m_idx_0 * Controller_B.Reshape[1];

    /* Sum: '<S53>/Minus2' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_TmpSignalConversionAtMultip[0] = rtb_Add_k - Controller_U.INS_Out.p;
    rtb_TmpSignalConversionAtMultip[1] = rtb_Add1_j4 - Controller_U.INS_Out.q;
    rtb_TmpSignalConversionAtMultip[2] = rtb_Divide_m_idx_3 -
      Controller_U.INS_Out.r;

    /* DiscreteIntegrator: '<S59>/Discrete-Time Integrator' incorporates:
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

    /* Sum: '<S51>/Add' incorporates:
     *  Gain: '<S51>/ucmd2thor'
     *  Gain: '<S51>/wcmd2thor'
     */
    rtb_Integrator1_m = CONTROL_PARAM.FW_TECS_W2T * rtb_Integrator1_m +
      CONTROL_PARAM.FW_TECS_U2T * rtb_Subtract1_jj;

    /* DiscreteIntegrator: '<S86>/ ' incorporates:
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

    /* DiscreteIntegrator: '<S87>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_h != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm = rtb_Integrator1_m;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_d != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm = rtb_Integrator1_m;
    }

    /* Gain: '<S87>/Gain' incorporates:
     *  DiscreteIntegrator: '<S87>/Discrete-Time Integrator1'
     *  Sum: '<S87>/Sum5'
     */
    rtb_DiscreteTimeIntegrator1_a = (rtb_Integrator1_m -
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm) * 188.49556F;

    /* Switch: '<S13>/Switch' incorporates:
     *  Constant: '<S13>/Constant2'
     *  Constant: '<S52>/Constant'
     *  Constant: '<S90>/Constant'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S90>/Compare'
     *  Saturate: '<S52>/Saturation2'
     */
    if (Controller_U.FMS_Out.ctrl_mode == 1) {
      Controller_B.Switch[0] = Controller_U.FMS_Out.p_cmd;
      Controller_B.Switch[1] = Controller_U.FMS_Out.q_cmd;
      Controller_B.Switch[2] = Controller_U.FMS_Out.r_cmd;
      Controller_B.Switch[3] = Controller_U.FMS_Out.u_cmd;
      Controller_B.Switch[4] = 0.0F;
      Controller_B.Switch[5] = 0.0F;
    } else {
      /* Product: '<S57>/Divide' incorporates:
       *  Constant: '<S57>/trim_speed'
       *  DiscreteIntegrator: '<S91>/Discrete-Time Integrator5'
       *  Math: '<S57>/Square'
       *  Math: '<S57>/Square1'
       */
      rtb_a_k = CONTROL_PARAM.FW_AIRSPEED_TRIM * CONTROL_PARAM.FW_AIRSPEED_TRIM /
        (Controller_DW.DiscreteTimeIntegrator5_DSTAT_j *
         Controller_DW.DiscreteTimeIntegrator5_DSTAT_j);

      /* Saturate: '<S57>/Saturation' */
      if (rtb_a_k > 1.0F) {
        rtb_a_k = 1.0F;
      } else {
        if (rtb_a_k < 0.0F) {
          rtb_a_k = 0.0F;
        }
      }

      /* End of Saturate: '<S57>/Saturation' */

      /* Product: '<S53>/Multiply' incorporates:
       *  Constant: '<S60>/gain1'
       *  Constant: '<S60>/gain2'
       *  Constant: '<S60>/gain3'
       *  DiscreteIntegrator: '<S59>/Discrete-Time Integrator'
       *  Product: '<S60>/Multiply'
       *  Sum: '<S56>/Add1'
       */
      rtb_Divide_m_idx_0 = (CONTROL_PARAM.FW_ROLL_RATE_P *
                            rtb_TmpSignalConversionAtMultip[0] +
                            Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0]) *
        rtb_a_k;
      rtb_Divide_m_idx_1 = (CONTROL_PARAM.FW_PITCH_RATE_P *
                            rtb_TmpSignalConversionAtMultip[1] +
                            Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1]) *
        rtb_a_k;
      rtb_Divide_m_idx_2 = (CONTROL_PARAM.FW_YAW_RATE_P *
                            rtb_TmpSignalConversionAtMultip[2] +
                            Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2]) *
        rtb_a_k;

      /* Product: '<S58>/Divide' incorporates:
       *  Constant: '<S58>/trim_speed'
       *  DiscreteIntegrator: '<S91>/Discrete-Time Integrator5'
       */
      rtb_a_k = CONTROL_PARAM.FW_AIRSPEED_TRIM /
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;

      /* Saturate: '<S58>/Saturation' */
      if (rtb_a_k > 1.0F) {
        rtb_a_k = 1.0F;
      } else {
        if (rtb_a_k < 0.0F) {
          rtb_a_k = 0.0F;
        }
      }

      /* End of Saturate: '<S58>/Saturation' */

      /* Product: '<S53>/Multiply1' incorporates:
       *  Gain: '<S53>/FF'
       */
      rtb_Subtract1_jj = CONTROL_PARAM.FW_FF * rtb_Add_k * rtb_a_k;

      /* Saturate: '<S53>/FF_limit' */
      if (rtb_Subtract1_jj > 0.3F) {
        rtb_Subtract1_jj = 0.3F;
      } else {
        if (rtb_Subtract1_jj < -0.3F) {
          rtb_Subtract1_jj = -0.3F;
        }
      }

      /* Saturate: '<S53>/PI_limit' */
      if (rtb_Divide_m_idx_0 > 1.0F) {
        rtb_Divide_m_idx_0 = 1.0F;
      } else {
        if (rtb_Divide_m_idx_0 < -1.0F) {
          rtb_Divide_m_idx_0 = -1.0F;
        }
      }

      /* Sum: '<S53>/Add' */
      rtb_Add_k = rtb_Subtract1_jj + rtb_Divide_m_idx_0;

      /* Product: '<S53>/Multiply1' incorporates:
       *  Gain: '<S53>/FF'
       */
      rtb_Divide_m_idx_0 = CONTROL_PARAM.FW_FF * rtb_Add1_j4 * rtb_a_k;

      /* Saturate: '<S53>/FF_limit' */
      if (rtb_Divide_m_idx_0 > 0.3F) {
        rtb_Divide_m_idx_0 = 0.3F;
      } else {
        if (rtb_Divide_m_idx_0 < -0.3F) {
          rtb_Divide_m_idx_0 = -0.3F;
        }
      }

      /* Saturate: '<S53>/PI_limit' */
      if (rtb_Divide_m_idx_1 > 1.0F) {
        rtb_Divide_m_idx_1 = 1.0F;
      } else {
        if (rtb_Divide_m_idx_1 < -1.0F) {
          rtb_Divide_m_idx_1 = -1.0F;
        }
      }

      /* Sum: '<S53>/Add' */
      rtb_Add1_j4 = rtb_Divide_m_idx_0 + rtb_Divide_m_idx_1;

      /* Product: '<S53>/Multiply1' incorporates:
       *  Gain: '<S53>/FF'
       */
      rtb_Divide_m_idx_0 = CONTROL_PARAM.FW_FF * rtb_Divide_m_idx_3 * rtb_a_k;

      /* Saturate: '<S53>/FF_limit' */
      if (rtb_Divide_m_idx_0 > 0.3F) {
        rtb_Divide_m_idx_0 = 0.3F;
      } else {
        if (rtb_Divide_m_idx_0 < -0.3F) {
          rtb_Divide_m_idx_0 = -0.3F;
        }
      }

      /* Saturate: '<S53>/PI_limit' */
      if (rtb_Divide_m_idx_2 > 1.0F) {
        rtb_Divide_m_idx_2 = 1.0F;
      } else {
        if (rtb_Divide_m_idx_2 < -1.0F) {
          rtb_Divide_m_idx_2 = -1.0F;
        }
      }

      /* Sum: '<S53>/Add' */
      rtb_Divide_m_idx_3 = rtb_Divide_m_idx_0 + rtb_Divide_m_idx_2;

      /* Switch: '<S52>/Switch' incorporates:
       *  Bias: '<S52>/Bias'
       *  Constant: '<S89>/Constant'
       *  Gain: '<S52>/Gain'
       *  RelationalOperator: '<S89>/Compare'
       *  Switch: '<S87>/Switch'
       */
      if (Controller_U.FMS_Out.ctrl_mode <= 3) {
        rtb_a_k = 0.000999987125F * (real32_T)Controller_U.FMS_Out.throttle_cmd
          + -1.0F;
      } else {
        if (Controller_U.FMS_Out.reset > 0) {
          /* Switch: '<S87>/Switch' incorporates:
           *  Gain: '<S87>/Gain1'
           */
          rtb_a_k = 0.0F;
        } else {
          /* Switch: '<S87>/Switch' */
          rtb_a_k = rtb_DiscreteTimeIntegrator1_a;
        }

        /* Gain: '<S85>/Gain' */
        rtb_a_k *= CONTROL_PARAM.FW_TECS_THOR_D;

        /* Saturate: '<S75>/Saturation1' */
        if (rtb_a_k > 0.3F) {
          rtb_a_k = 0.3F;
        } else {
          if (rtb_a_k < -0.3F) {
            rtb_a_k = -0.3F;
          }
        }

        /* End of Saturate: '<S75>/Saturation1' */

        /* Sum: '<S51>/Add2' incorporates:
         *  DiscreteIntegrator: '<S86>/ '
         *  Gain: '<S51>/thorttle_ff'
         *  Gain: '<S75>/P_control'
         *  Sum: '<S51>/Add1'
         *  Sum: '<S75>/Add4'
         */
        rtb_a_k = ((CONTROL_PARAM.FW_TECS_THOR_P * rtb_Integrator1_m +
                    Controller_DW._DSTATE_d) + rtb_a_k) + (rtb_Subtract3_g +
          rtb_VdotPg) * CONTROL_PARAM.FW_TECS_THOR_FF;

        /* Saturate: '<S52>/Saturation' */
        if (rtb_a_k > 1.0F) {
          rtb_a_k = 1.0F;
        } else {
          if (rtb_a_k < -1.0F) {
            rtb_a_k = -1.0F;
          }
        }

        /* End of Saturate: '<S52>/Saturation' */
      }

      /* End of Switch: '<S52>/Switch' */

      /* Saturate: '<S53>/Saturation1' */
      if (rtb_Add_k > 1.0F) {
        Controller_B.Switch[0] = 1.0F;
      } else if (rtb_Add_k < -1.0F) {
        Controller_B.Switch[0] = -1.0F;
      } else {
        Controller_B.Switch[0] = rtb_Add_k;
      }

      if (rtb_Add1_j4 > 1.0F) {
        Controller_B.Switch[1] = 1.0F;
      } else if (rtb_Add1_j4 < -1.0F) {
        Controller_B.Switch[1] = -1.0F;
      } else {
        Controller_B.Switch[1] = rtb_Add1_j4;
      }

      if (rtb_Divide_m_idx_3 > 1.0F) {
        Controller_B.Switch[2] = 1.0F;
      } else if (rtb_Divide_m_idx_3 < -1.0F) {
        Controller_B.Switch[2] = -1.0F;
      } else {
        Controller_B.Switch[2] = rtb_Divide_m_idx_3;
      }

      /* End of Saturate: '<S53>/Saturation1' */

      /* Saturate: '<S52>/Saturation2' */
      if (rtb_a_k > 1.0F) {
        Controller_B.Switch[3] = 1.0F;
      } else {
        Controller_B.Switch[3] = rtb_a_k;
      }

      Controller_B.Switch[4] = 0.0F;
      Controller_B.Switch[5] = 0.0F;
    }

    /* End of Switch: '<S13>/Switch' */

    /* Product: '<S5>/Multiply' incorporates:
     *  DiscreteIntegrator: '<S9>/Discrete-Time Integrator5'
     */
    Controller_B.Multiply_c[0] = Controller_B.Switch[0] *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_k;
    Controller_B.Multiply_c[1] = Controller_B.Switch[1] *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_k;
    Controller_B.Multiply_c[2] = Controller_B.Switch[2] *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_k;

    /* Product: '<S71>/Multiply1' incorporates:
     *  Constant: '<S71>/const1'
     *  DiscreteIntegrator: '<S70>/Integrator'
     */
    rtb_Divide_m_idx_2 = Controller_DW.Integrator_DSTATE_n * 0.05F;

    /* Sum: '<S71>/Add' incorporates:
     *  DiscreteIntegrator: '<S70>/Integrator1'
     *  Inport: '<Root>/FMS_Out'
     *  Sum: '<S70>/Subtract'
     */
    rtb_Divide_m_idx_0 = (Controller_DW.Integrator1_DSTATE_c -
                          Controller_U.FMS_Out.ay_cmd) + rtb_Divide_m_idx_2;

    /* Signum: '<S71>/Sign' */
    if (rtb_Divide_m_idx_0 < 0.0F) {
      rtb_Divide_m_idx_1 = -1.0F;
    } else if (rtb_Divide_m_idx_0 > 0.0F) {
      rtb_Divide_m_idx_1 = 1.0F;
    } else {
      rtb_Divide_m_idx_1 = rtb_Divide_m_idx_0;
    }

    /* End of Signum: '<S71>/Sign' */

    /* Sum: '<S71>/Add2' incorporates:
     *  Abs: '<S71>/Abs'
     *  Gain: '<S71>/Gain'
     *  Gain: '<S71>/Gain1'
     *  Product: '<S71>/Multiply2'
     *  Product: '<S71>/Multiply3'
     *  Sqrt: '<S71>/Sqrt'
     *  Sum: '<S71>/Add1'
     *  Sum: '<S71>/Subtract'
     */
    rtb_Divide_m_idx_1 = (sqrtf((8.0F * fabsf(rtb_Divide_m_idx_0) +
      Controller_ConstB.d_ih) * Controller_ConstB.d_ih) - Controller_ConstB.d_ih)
      * 0.5F * rtb_Divide_m_idx_1 + rtb_Divide_m_idx_2;

    /* Sum: '<S71>/Add4' */
    rtb_Divide_m_idx_2 += rtb_Divide_m_idx_0 - rtb_Divide_m_idx_1;

    /* Sum: '<S71>/Add3' */
    rtb_Subtract3_g = rtb_Divide_m_idx_0 + Controller_ConstB.d_ih;

    /* Sum: '<S71>/Subtract1' */
    rtb_Divide_m_idx_0 -= Controller_ConstB.d_ih;

    /* Signum: '<S71>/Sign1' */
    if (rtb_Subtract3_g < 0.0F) {
      rtb_Subtract3_g = -1.0F;
    } else {
      if (rtb_Subtract3_g > 0.0F) {
        rtb_Subtract3_g = 1.0F;
      }
    }

    /* End of Signum: '<S71>/Sign1' */

    /* Signum: '<S71>/Sign2' */
    if (rtb_Divide_m_idx_0 < 0.0F) {
      rtb_Divide_m_idx_0 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_0 > 0.0F) {
        rtb_Divide_m_idx_0 = 1.0F;
      }
    }

    /* End of Signum: '<S71>/Sign2' */

    /* Sum: '<S71>/Add5' incorporates:
     *  Gain: '<S71>/Gain2'
     *  Product: '<S71>/Multiply4'
     *  Sum: '<S71>/Subtract2'
     */
    rtb_Divide_m_idx_1 += (rtb_Subtract3_g - rtb_Divide_m_idx_0) * 0.5F *
      rtb_Divide_m_idx_2;

    /* Update for DiscreteIntegrator: '<S91>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S91>/Gain'
     *  Sum: '<S91>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_i = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_j += (rtb_Saturation1 -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j) * 62.831852F * 0.002F;

    /* Update for DiscreteIntegrator: '<S70>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S70>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_c += 0.002F *
      Controller_DW.Integrator_DSTATE_n;

    /* Update for DiscreteIntegrator: '<S88>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S88>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S88>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_n = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_f += (Controller_U.INS_Out.ax -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_f) * 31.415926F * 0.002F;

    /* Update for DiscreteIntegrator: '<S83>/ ' incorporates:
     *  Gain: '<S83>/Gain3'
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

    /* End of Update for DiscreteIntegrator: '<S83>/ ' */

    /* Update for DiscreteIntegrator: '<S84>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_f = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_e += 0.002F * rtb_Gain_c4;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_b = (int8_T)
      rtb_LogicalOperator_h;

    /* Update for DiscreteIntegrator: '<S59>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S59>/gain1'
     *  Constant: '<S59>/gain2'
     *  Constant: '<S59>/gain3'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S59>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0] +=
      CONTROL_PARAM.FW_ROLL_RATE_I * rtb_TmpSignalConversionAtMultip[0] * 0.002F;
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
      CONTROL_PARAM.FW_PITCH_RATE_I * rtb_TmpSignalConversionAtMultip[1] *
      0.002F;
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
      CONTROL_PARAM.FW_YAW_RATE_I * rtb_TmpSignalConversionAtMultip[2] * 0.002F;
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

    /* End of Update for DiscreteIntegrator: '<S59>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S86>/ ' incorporates:
     *  Gain: '<S86>/Gain'
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW._DSTATE_d += CONTROL_PARAM.FW_TECS_THOR_I * rtb_Integrator1_m *
      0.002F;
    if (Controller_DW._DSTATE_d >= 1.0F) {
      Controller_DW._DSTATE_d = 1.0F;
    } else {
      if (Controller_DW._DSTATE_d <= 0.0F) {
        Controller_DW._DSTATE_d = 0.0F;
      }
    }

    Controller_DW._PrevResetState_e = (int8_T)(Controller_U.FMS_Out.reset > 0);

    /* End of Update for DiscreteIntegrator: '<S86>/ ' */

    /* Update for DiscreteIntegrator: '<S87>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_h = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTA_nm += 0.002F *
      rtb_DiscreteTimeIntegrator1_a;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_d = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Signum: '<S71>/Sign6' incorporates:
     *  Signum: '<S71>/Sign5'
     */
    if (rtb_Divide_m_idx_1 < 0.0F) {
      rtb_Divide_m_idx_2 = -1.0F;

      /* Signum: '<S71>/Sign5' */
      rtb_Add_k = -1.0F;
    } else if (rtb_Divide_m_idx_1 > 0.0F) {
      rtb_Divide_m_idx_2 = 1.0F;

      /* Signum: '<S71>/Sign5' */
      rtb_Add_k = 1.0F;
    } else {
      rtb_Divide_m_idx_2 = rtb_Divide_m_idx_1;

      /* Signum: '<S71>/Sign5' */
      rtb_Add_k = rtb_Divide_m_idx_1;
    }

    /* End of Signum: '<S71>/Sign6' */

    /* Sum: '<S71>/Add6' */
    rtb_Subtract3_g = rtb_Divide_m_idx_1 + Controller_ConstB.d_ih;

    /* Sum: '<S71>/Subtract3' */
    rtb_Divide_m_idx_0 = rtb_Divide_m_idx_1 - Controller_ConstB.d_ih;

    /* Signum: '<S71>/Sign3' */
    if (rtb_Subtract3_g < 0.0F) {
      rtb_Subtract3_g = -1.0F;
    } else {
      if (rtb_Subtract3_g > 0.0F) {
        rtb_Subtract3_g = 1.0F;
      }
    }

    /* End of Signum: '<S71>/Sign3' */

    /* Signum: '<S71>/Sign4' */
    if (rtb_Divide_m_idx_0 < 0.0F) {
      rtb_Divide_m_idx_0 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_0 > 0.0F) {
        rtb_Divide_m_idx_0 = 1.0F;
      }
    }

    /* End of Signum: '<S71>/Sign4' */

    /* Update for DiscreteIntegrator: '<S70>/Integrator' incorporates:
     *  Constant: '<S71>/const'
     *  Gain: '<S71>/Gain3'
     *  Product: '<S71>/Divide'
     *  Product: '<S71>/Multiply5'
     *  Product: '<S71>/Multiply6'
     *  Sum: '<S71>/Subtract4'
     *  Sum: '<S71>/Subtract5'
     *  Sum: '<S71>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE_n += ((rtb_Divide_m_idx_1 /
      Controller_ConstB.d_ih - rtb_Add_k) * Controller_ConstB.Gain4_g *
      ((rtb_Subtract3_g - rtb_Divide_m_idx_0) * 0.5F) - rtb_Divide_m_idx_2 *
      58.836F) * 0.002F;
  } else {
    if (Controller_DW.FW_Controller_MODE) {
      Controller_DW.FW_Controller_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S2>/FW_Controller' */

  /* Outputs for Enabled SubSystem: '<S2>/MC_Controller' incorporates:
   *  EnablePort: '<S6>/Enable'
   */
  if (rtb_Compare) {
    if (!Controller_DW.MC_Controller_MODE) {
      /* InitializeConditions for DiscreteIntegrator: '<S124>/Discrete-Time Integrator' */
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

      /* End of InitializeConditions for DiscreteIntegrator: '<S124>/Discrete-Time Integrator' */

      /* InitializeConditions for DiscreteIntegrator: '<S149>/Discrete-Time Integrator' */
      Controller_DW.DiscreteTimeIntegrator_PrevRe_p = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S151>/Discrete-Time Integrator1' */
      Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S121>/Discrete-Time Integrator5' */
      Controller_DW.DiscreteTimeIntegrator5_IC_LO_c = 1U;

      /* InitializeConditions for DiscreteIntegrator: '<S126>/Discrete-Time Integrator1' */
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevR_k = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S144>/Integrator1' */
      Controller_DW.Integrator1_DSTATE[0] = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S149>/Discrete-Time Integrator' */
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

      /* InitializeConditions for DiscreteIntegrator: '<S144>/Integrator' */
      Controller_DW.Integrator_DSTATE[0] = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S144>/Integrator1' */
      Controller_DW.Integrator1_DSTATE[1] = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S149>/Discrete-Time Integrator' */
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

      /* InitializeConditions for DiscreteIntegrator: '<S144>/Integrator' */
      Controller_DW.Integrator_DSTATE[1] = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S163>/Integrator1' */
      Controller_DW.Integrator1_DSTATE_e = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S166>/Discrete-Time Integrator' */
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

      /* End of InitializeConditions for DiscreteIntegrator: '<S166>/Discrete-Time Integrator' */

      /* InitializeConditions for DiscreteIntegrator: '<S168>/Discrete-Time Integrator1' */
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 1U;
      Controller_DW.DiscreteTimeIntegrator1_Prev_ks = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S163>/Integrator' */
      Controller_DW.Integrator_DSTATE_j = 0.0F;
      Controller_DW.MC_Controller_MODE = true;
    }

    /* Sqrt: '<S116>/Sqrt' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Math: '<S116>/Square'
     *  Sum: '<S116>/Sum of Elements'
     */
    rtb_a_k = sqrtf(((Controller_U.INS_Out.quat[0] * Controller_U.INS_Out.quat[0]
                      + Controller_U.INS_Out.quat[1] *
                      Controller_U.INS_Out.quat[1]) + Controller_U.INS_Out.quat
                     [2] * Controller_U.INS_Out.quat[2]) +
                    Controller_U.INS_Out.quat[3] * Controller_U.INS_Out.quat[3]);

    /* Product: '<S112>/Divide' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Sqrt: '<S116>/Sqrt'
     */
    rtb_Divide_m_idx_0 = Controller_U.INS_Out.quat[0] / rtb_a_k;
    rtb_Divide_m_idx_1 = Controller_U.INS_Out.quat[1] / rtb_a_k;
    rtb_Divide_m_idx_2 = Controller_U.INS_Out.quat[2] / rtb_a_k;
    rtb_Divide_m_idx_3 = Controller_U.INS_Out.quat[3] / rtb_a_k;

    /* Sum: '<S113>/Subtract' incorporates:
     *  Math: '<S113>/Square'
     *  Math: '<S113>/Square1'
     *  Math: '<S113>/Square2'
     *  Math: '<S113>/Square3'
     *  Sum: '<S113>/Add'
     *  Sum: '<S113>/Add1'
     */
    rtb_MatrixConcatenate1[0] = (rtb_Divide_m_idx_0 * rtb_Divide_m_idx_0 +
      rtb_Divide_m_idx_1 * rtb_Divide_m_idx_1) - (rtb_Divide_m_idx_2 *
      rtb_Divide_m_idx_2 + rtb_Divide_m_idx_3 * rtb_Divide_m_idx_3);

    /* Gain: '<S113>/Gain' incorporates:
     *  Product: '<S113>/Multiply'
     *  Product: '<S113>/Multiply1'
     *  Sum: '<S113>/Subtract1'
     */
    rtb_MatrixConcatenate1[1] = (rtb_Divide_m_idx_1 * rtb_Divide_m_idx_2 -
      rtb_Divide_m_idx_0 * rtb_Divide_m_idx_3) * 2.0F;

    /* Gain: '<S113>/Gain1' incorporates:
     *  Product: '<S113>/Multiply2'
     *  Product: '<S113>/Multiply3'
     *  Sum: '<S113>/Add2'
     */
    rtb_MatrixConcatenate1[2] = (rtb_Divide_m_idx_1 * rtb_Divide_m_idx_3 +
      rtb_Divide_m_idx_0 * rtb_Divide_m_idx_2) * 2.0F;

    /* Gain: '<S114>/Gain' incorporates:
     *  Product: '<S114>/Multiply'
     *  Product: '<S114>/Multiply1'
     *  Sum: '<S114>/Add3'
     */
    rtb_MatrixConcatenate1[3] = (rtb_Divide_m_idx_1 * rtb_Divide_m_idx_2 +
      rtb_Divide_m_idx_0 * rtb_Divide_m_idx_3) * 2.0F;

    /* Sum: '<S114>/Subtract' incorporates:
     *  Math: '<S114>/Square'
     *  Math: '<S114>/Square1'
     *  Math: '<S114>/Square2'
     *  Math: '<S114>/Square3'
     *  Sum: '<S114>/Add'
     *  Sum: '<S114>/Add1'
     */
    rtb_MatrixConcatenate1[4] = (rtb_Divide_m_idx_0 * rtb_Divide_m_idx_0 +
      rtb_Divide_m_idx_2 * rtb_Divide_m_idx_2) - (rtb_Divide_m_idx_1 *
      rtb_Divide_m_idx_1 + rtb_Divide_m_idx_3 * rtb_Divide_m_idx_3);

    /* Gain: '<S114>/Gain1' incorporates:
     *  Product: '<S114>/Multiply2'
     *  Product: '<S114>/Multiply3'
     *  Sum: '<S114>/Subtract1'
     */
    rtb_MatrixConcatenate1[5] = (rtb_Divide_m_idx_2 * rtb_Divide_m_idx_3 -
      rtb_Divide_m_idx_0 * rtb_Divide_m_idx_1) * 2.0F;

    /* Gain: '<S115>/Gain' incorporates:
     *  Product: '<S115>/Multiply'
     *  Product: '<S115>/Multiply1'
     *  Sum: '<S115>/Subtract2'
     */
    rtb_MatrixConcatenate1[6] = (rtb_Divide_m_idx_1 * rtb_Divide_m_idx_3 -
      rtb_Divide_m_idx_0 * rtb_Divide_m_idx_2) * 2.0F;

    /* Gain: '<S115>/Gain1' incorporates:
     *  Product: '<S115>/Multiply2'
     *  Product: '<S115>/Multiply3'
     *  Sum: '<S115>/Add2'
     */
    rtb_MatrixConcatenate1[7] = (rtb_Divide_m_idx_2 * rtb_Divide_m_idx_3 +
      rtb_Divide_m_idx_0 * rtb_Divide_m_idx_1) * 2.0F;

    /* Sum: '<S115>/Subtract' incorporates:
     *  Math: '<S115>/Square'
     *  Math: '<S115>/Square1'
     *  Math: '<S115>/Square2'
     *  Math: '<S115>/Square3'
     *  Sum: '<S115>/Add'
     *  Sum: '<S115>/Add1'
     */
    rtb_MatrixConcatenate1[8] = (rtb_Divide_m_idx_0 * rtb_Divide_m_idx_0 +
      rtb_Divide_m_idx_3 * rtb_Divide_m_idx_3) - (rtb_Divide_m_idx_1 *
      rtb_Divide_m_idx_1 + rtb_Divide_m_idx_2 * rtb_Divide_m_idx_2);

    /* Product: '<S109>/Multiply' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  SignalConversion: '<S109>/TmpSignal ConversionAtMultiplyInport2'
     */
    for (i = 0; i < 3; i++) {
      rtb_Multiply_ni[i] = rtb_MatrixConcatenate1[i + 6] *
        Controller_U.INS_Out.vd + (rtb_MatrixConcatenate1[i + 3] *
        Controller_U.INS_Out.ve + rtb_MatrixConcatenate1[i] *
        Controller_U.INS_Out.vn);
    }

    /* End of Product: '<S109>/Multiply' */

    /* DiscreteIntegrator: '<S124>/Discrete-Time Integrator' incorporates:
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

    /* RelationalOperator: '<S143>/Compare' incorporates:
     *  Constant: '<S143>/Constant'
     *  Inport: '<Root>/FMS_Out'
     */
    rtb_Compare_b = (Controller_U.FMS_Out.mode >= 5);

    /* Trigonometry: '<S146>/Trigonometric Function1' incorporates:
     *  Gain: '<S145>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1[0] = arm_cos_f32(-Controller_U.INS_Out.psi);

    /* Trigonometry: '<S146>/Trigonometric Function' incorporates:
     *  Gain: '<S145>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1[1] = arm_sin_f32(-Controller_U.INS_Out.psi);

    /* SignalConversion: '<S146>/ConcatBufferAtVector Concatenate1In3' incorporates:
     *  Constant: '<S146>/Constant3'
     */
    rtb_MatrixConcatenate1[2] = 0.0F;

    /* Gain: '<S146>/Gain' incorporates:
     *  Gain: '<S145>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S146>/Trigonometric Function2'
     */
    rtb_MatrixConcatenate1[3] = -arm_sin_f32(-Controller_U.INS_Out.psi);

    /* Trigonometry: '<S146>/Trigonometric Function3' incorporates:
     *  Gain: '<S145>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1[4] = arm_cos_f32(-Controller_U.INS_Out.psi);

    /* SignalConversion: '<S146>/ConcatBufferAtVector Concatenate2In3' incorporates:
     *  Constant: '<S146>/Constant4'
     */
    rtb_MatrixConcatenate1[5] = 0.0F;

    /* SignalConversion: '<S146>/ConcatBufferAtVector ConcatenateIn3' */
    rtb_MatrixConcatenate1[6] = Controller_ConstB.VectorConcatenate3[0];
    rtb_MatrixConcatenate1[7] = Controller_ConstB.VectorConcatenate3[1];
    rtb_MatrixConcatenate1[8] = Controller_ConstB.VectorConcatenate3[2];

    /* Product: '<S142>/Multiply' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  SignalConversion: '<S142>/TmpSignal ConversionAtMultiplyInport2'
     */
    for (i = 0; i < 3; i++) {
      rtb_TmpSignalConversionAtMultip[i] = rtb_MatrixConcatenate1[i + 3] *
        Controller_U.INS_Out.ve + rtb_MatrixConcatenate1[i] *
        Controller_U.INS_Out.vn;
    }

    /* End of Product: '<S142>/Multiply' */

    /* Product: '<S139>/Multiply' incorporates:
     *  DataTypeConversion: '<S139>/Data Type Conversion'
     *  DiscreteIntegrator: '<S144>/Integrator1'
     *  Sum: '<S139>/Sum'
     */
    rtb_Saturation1 = (Controller_DW.Integrator1_DSTATE[0] -
                       rtb_TmpSignalConversionAtMultip[0]) * (real32_T)
      rtb_Compare_b;
    rtb_Ldot_err = (Controller_DW.Integrator1_DSTATE[1] -
                    rtb_TmpSignalConversionAtMultip[1]) * (real32_T)
      rtb_Compare_b;

    /* Logic: '<S102>/Logical Operator' incorporates:
     *  Constant: '<S138>/Constant'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S138>/Compare'
     */
    rtb_LogicalOperator_h = ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_U.FMS_Out.ext_state != 0));

    /* DiscreteIntegrator: '<S149>/Discrete-Time Integrator' */
    if (rtb_LogicalOperator_h || (Controller_DW.DiscreteTimeIntegrator_PrevRe_p
         != 0)) {
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

    /* DiscreteIntegrator: '<S151>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] = rtb_Saturation1;
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] = rtb_Ldot_err;
    }

    if (rtb_LogicalOperator_h || (Controller_DW.DiscreteTimeIntegrator1_PrevRes
         != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] = rtb_Saturation1;
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] = rtb_Ldot_err;
    }

    /* Gain: '<S151>/Gain' incorporates:
     *  DiscreteIntegrator: '<S151>/Discrete-Time Integrator1'
     *  Sum: '<S151>/Sum5'
     */
    rtb_Gain_c4 = (rtb_Saturation1 -
                   Controller_DW.DiscreteTimeIntegrator1_DSTATE[0]) * 62.831852F;
    rtb_VdotPg = (rtb_Ldot_err - Controller_DW.DiscreteTimeIntegrator1_DSTATE[1])
      * 62.831852F;

    /* Switch: '<S151>/Switch' incorporates:
     *  Gain: '<S151>/Gain1'
     */
    if (rtb_LogicalOperator_h) {
      rtb_DiscreteTimeIntegrator1_a = 0.0F;
      rtb_a_k = 0.0F;
    } else {
      rtb_DiscreteTimeIntegrator1_a = rtb_Gain_c4;
      rtb_a_k = rtb_VdotPg;
    }

    /* End of Switch: '<S151>/Switch' */

    /* Product: '<S148>/Multiply' incorporates:
     *  Constant: '<S148>/kd'
     */
    rtb_Divide_m_idx_2 = CONTROL_PARAM.MC_VEL_XY_D *
      rtb_DiscreteTimeIntegrator1_a;

    /* Saturate: '<S148>/Saturation' */
    if (rtb_Divide_m_idx_2 > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
      rtb_Divide_m_idx_2 = CONTROL_PARAM.MC_VEL_XY_D_MAX;
    } else {
      if (rtb_Divide_m_idx_2 < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
        rtb_Divide_m_idx_2 = CONTROL_PARAM.MC_VEL_XY_D_MIN;
      }
    }

    /* Product: '<S148>/Multiply' incorporates:
     *  Constant: '<S148>/kd'
     */
    rtb_DiscreteTimeIntegrator1_a = rtb_Divide_m_idx_2;
    rtb_Divide_m_idx_2 = CONTROL_PARAM.MC_VEL_XY_D * rtb_a_k;

    /* Saturate: '<S148>/Saturation' */
    if (rtb_Divide_m_idx_2 > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
      rtb_Divide_m_idx_2 = CONTROL_PARAM.MC_VEL_XY_D_MAX;
    } else {
      if (rtb_Divide_m_idx_2 < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
        rtb_Divide_m_idx_2 = CONTROL_PARAM.MC_VEL_XY_D_MIN;
      }
    }

    /* Switch: '<S141>/Switch' incorporates:
     *  Constant: '<S150>/kp'
     *  Constant: '<S152>/Constant'
     *  Constant: '<S154>/Constant'
     *  Constant: '<S155>/Constant'
     *  DiscreteIntegrator: '<S149>/Discrete-Time Integrator'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S150>/Multiply'
     *  Product: '<S153>/Multiply2'
     *  Product: '<S153>/Multiply3'
     *  RelationalOperator: '<S152>/Compare'
     *  RelationalOperator: '<S154>/Compare'
     *  RelationalOperator: '<S155>/Compare'
     *  S-Function (sfix_bitop): '<S153>/cmd_ax valid'
     *  S-Function (sfix_bitop): '<S153>/cmd_ay valid'
     *  S-Function (sfix_bitop): '<S153>/cmd_u valid'
     *  S-Function (sfix_bitop): '<S153>/cmd_v valid'
     *  Sum: '<S140>/Add'
     *  Sum: '<S153>/Sum1'
     */
    if (Controller_U.FMS_Out.ctrl_mode == 6) {
      rtb_DiscreteTimeIntegrator1_a = ((Controller_U.FMS_Out.cmd_mask & 64) > 0 ?
        (CONTROL_PARAM.MC_VEL_XY_P * rtb_Saturation1 +
         Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0]) +
        rtb_DiscreteTimeIntegrator1_a : 0.0F) + ((Controller_U.FMS_Out.cmd_mask
        & 512) > 0 ? Controller_U.FMS_Out.ax_cmd : 0.0F);
      rtb_a_k = ((Controller_U.FMS_Out.cmd_mask & 128) > 0 ?
                 (CONTROL_PARAM.MC_VEL_XY_P * rtb_Ldot_err +
                  Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1]) +
                 rtb_Divide_m_idx_2 : 0.0F) + ((Controller_U.FMS_Out.cmd_mask &
        1024) > 0 ? Controller_U.FMS_Out.ay_cmd : 0.0F);
    } else {
      rtb_DiscreteTimeIntegrator1_a += CONTROL_PARAM.MC_VEL_XY_P *
        rtb_Saturation1 + Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0];
      rtb_a_k = (CONTROL_PARAM.MC_VEL_XY_P * rtb_Ldot_err +
                 Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1]) +
        rtb_Divide_m_idx_2;
    }

    /* End of Switch: '<S141>/Switch' */

    /* Trigonometry: '<S137>/Atan' incorporates:
     *  Constant: '<S137>/g'
     *  Gain: '<S137>/Gain1'
     *  Gain: '<S137>/gain'
     *  Product: '<S137>/Divide'
     */
    rtb_Divide_m_idx_0 = atanf(1.1F * rtb_a_k / 9.8055F);
    rtb_a_k = atanf(1.1F * -rtb_DiscreteTimeIntegrator1_a / 9.8055F);

    /* Switch: '<S128>/Switch' incorporates:
     *  Constant: '<S135>/Constant'
     *  Inport: '<Root>/FMS_Out'
     *  Logic: '<S128>/Logical Operator'
     *  RelationalOperator: '<S134>/Compare'
     *  RelationalOperator: '<S135>/Compare'
     *  Saturate: '<S137>/Saturation'
     *  Switch: '<S128>/Switch1'
     */
    if ((Controller_U.FMS_Out.ctrl_mode == 3) || (Controller_U.FMS_Out.ctrl_mode
         == 4)) {
      rtb_DiscreteTimeIntegrator1_a = Controller_U.FMS_Out.phi_cmd;
      rtb_a_k = Controller_U.FMS_Out.theta_cmd;
    } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
      /* Switch: '<S136>/Switch' incorporates:
       *  S-Function (sfix_bitop): '<S136>/cmd_phi valid'
       *  S-Function (sfix_bitop): '<S136>/cmd_theta valid'
       *  Saturate: '<S137>/Saturation'
       *  Switch: '<S128>/Switch1'
       */
      if ((Controller_U.FMS_Out.cmd_mask & 8) > 0) {
        rtb_DiscreteTimeIntegrator1_a = Controller_U.FMS_Out.phi_cmd;
      } else if (rtb_Divide_m_idx_0 > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S137>/Saturation' */
        rtb_DiscreteTimeIntegrator1_a = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else if (rtb_Divide_m_idx_0 < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S137>/Saturation' */
        rtb_DiscreteTimeIntegrator1_a = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        rtb_DiscreteTimeIntegrator1_a = rtb_Divide_m_idx_0;
      }

      if ((Controller_U.FMS_Out.cmd_mask & 16) > 0) {
        rtb_a_k = Controller_U.FMS_Out.theta_cmd;
      } else if (rtb_a_k > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S137>/Saturation' */
        rtb_a_k = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_a_k < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Saturate: '<S137>/Saturation' */
          rtb_a_k = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        }
      }

      /* End of Switch: '<S136>/Switch' */
    } else {
      if (rtb_Divide_m_idx_0 > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S137>/Saturation' incorporates:
         *  Switch: '<S128>/Switch1'
         */
        rtb_DiscreteTimeIntegrator1_a = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else if (rtb_Divide_m_idx_0 < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S137>/Saturation' incorporates:
         *  Switch: '<S128>/Switch1'
         */
        rtb_DiscreteTimeIntegrator1_a = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        /* Switch: '<S128>/Switch1' incorporates:
         *  Saturate: '<S137>/Saturation'
         */
        rtb_DiscreteTimeIntegrator1_a = rtb_Divide_m_idx_0;
      }

      /* Saturate: '<S137>/Saturation' */
      if (rtb_a_k > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Switch: '<S128>/Switch1' */
        rtb_a_k = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_a_k < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Switch: '<S128>/Switch1' */
          rtb_a_k = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        }
      }
    }

    /* End of Switch: '<S128>/Switch' */

    /* Sum: '<S129>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_m_idx_2 = rtb_DiscreteTimeIntegrator1_a -
      Controller_U.INS_Out.phi;

    /* Product: '<S132>/Divide1' incorporates:
     *  Abs: '<S132>/Abs'
     *  Constant: '<S132>/const2'
     */
    rtb_Integrator1_m = fabsf(rtb_Divide_m_idx_2) / 0.002F;

    /* Product: '<S132>/Divide' incorporates:
     *  Constant: '<S130>/Constant1'
     *  Constant: '<S132>/const1'
     *  Math: '<S132>/Square'
     *  SignalConversion: '<S132>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_Divide_m_idx_1 = 9.5993F / (CONTROL_PARAM.MC_ROLL_P *
      CONTROL_PARAM.MC_ROLL_P);

    /* Signum: '<S132>/Sign' */
    if (rtb_Divide_m_idx_2 < 0.0F) {
      rtb_Gain_hl_idx_2 = -1.0F;
    } else if (rtb_Divide_m_idx_2 > 0.0F) {
      rtb_Gain_hl_idx_2 = 1.0F;
    } else {
      rtb_Gain_hl_idx_2 = rtb_Divide_m_idx_2;
    }

    /* Switch: '<S132>/Switch' incorporates:
     *  Constant: '<S130>/Constant1'
     *  Gain: '<S132>/Gain1'
     *  Gain: '<S132>/Gain2'
     *  Logic: '<S132>/Logical Operator'
     *  Product: '<S132>/Multiply'
     *  Product: '<S132>/Multiply1'
     *  Product: '<S132>/Multiply2'
     *  Product: '<S132>/Multiply3'
     *  RelationalOperator: '<S132>/Relational Operator'
     *  RelationalOperator: '<S132>/Relational Operator2'
     *  SignalConversion: '<S132>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S132>/Sqrt'
     *  Sum: '<S132>/Subtract'
     */
    if ((rtb_Divide_m_idx_2 <= rtb_Divide_m_idx_1) && (rtb_Divide_m_idx_2 >=
         -rtb_Divide_m_idx_1)) {
      rtb_Gain_hl_idx_2 = rtb_Divide_m_idx_2 * CONTROL_PARAM.MC_ROLL_P;
    } else {
      rtb_Gain_hl_idx_2 *= sqrtf((rtb_Gain_hl_idx_2 * rtb_Divide_m_idx_2 - 0.5F *
        rtb_Divide_m_idx_1) * Controller_ConstB.Gain);
    }

    /* Product: '<S132>/Divide' incorporates:
     *  Gain: '<S132>/Gain3'
     */
    rtb_Divide_m_idx_0 = -rtb_Integrator1_m;

    /* Switch: '<S133>/Switch' incorporates:
     *  Gain: '<S132>/Gain3'
     *  RelationalOperator: '<S133>/UpperRelop'
     */
    if (rtb_Gain_hl_idx_2 >= -rtb_Integrator1_m) {
      /* Product: '<S132>/Divide' */
      rtb_Divide_m_idx_0 = rtb_Gain_hl_idx_2;
    }

    /* Product: '<S132>/Divide1' */
    rtb_DiscreteTimeIntegrator1_a = rtb_Integrator1_m;

    /* Signum: '<S132>/Sign' */
    rtb_Subtract1_jj = rtb_Gain_hl_idx_2;

    /* Sum: '<S129>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_m_idx_2 = rtb_a_k - Controller_U.INS_Out.theta;

    /* Product: '<S132>/Divide1' incorporates:
     *  Abs: '<S132>/Abs'
     *  Constant: '<S132>/const2'
     */
    rtb_Integrator1_m = fabsf(rtb_Divide_m_idx_2) / 0.002F;

    /* Product: '<S132>/Divide' incorporates:
     *  Constant: '<S130>/Constant2'
     *  Constant: '<S132>/const1'
     *  Math: '<S132>/Square'
     *  SignalConversion: '<S132>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_Divide_m_idx_1 = 9.5993F / (CONTROL_PARAM.MC_PITCH_P *
      CONTROL_PARAM.MC_PITCH_P);

    /* Signum: '<S132>/Sign' */
    if (rtb_Divide_m_idx_2 < 0.0F) {
      rtb_Gain_hl_idx_2 = -1.0F;
    } else if (rtb_Divide_m_idx_2 > 0.0F) {
      rtb_Gain_hl_idx_2 = 1.0F;
    } else {
      rtb_Gain_hl_idx_2 = rtb_Divide_m_idx_2;
    }

    /* Switch: '<S132>/Switch' incorporates:
     *  Constant: '<S130>/Constant2'
     *  Gain: '<S132>/Gain1'
     *  Gain: '<S132>/Gain2'
     *  Logic: '<S132>/Logical Operator'
     *  Product: '<S132>/Multiply'
     *  Product: '<S132>/Multiply1'
     *  Product: '<S132>/Multiply2'
     *  Product: '<S132>/Multiply3'
     *  RelationalOperator: '<S132>/Relational Operator'
     *  RelationalOperator: '<S132>/Relational Operator2'
     *  SignalConversion: '<S132>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S132>/Sqrt'
     *  Sum: '<S132>/Subtract'
     */
    if ((rtb_Divide_m_idx_2 <= rtb_Divide_m_idx_1) && (rtb_Divide_m_idx_2 >=
         -rtb_Divide_m_idx_1)) {
      rtb_Gain_hl_idx_2 = rtb_Divide_m_idx_2 * CONTROL_PARAM.MC_PITCH_P;
    } else {
      rtb_Gain_hl_idx_2 *= sqrtf((rtb_Gain_hl_idx_2 * rtb_Divide_m_idx_2 - 0.5F *
        rtb_Divide_m_idx_1) * Controller_ConstB.Gain);
    }

    /* Gain: '<S132>/Gain3' */
    rtb_Divide_m_idx_1 = -rtb_Integrator1_m;

    /* Switch: '<S133>/Switch' incorporates:
     *  Gain: '<S132>/Gain3'
     *  RelationalOperator: '<S133>/UpperRelop'
     */
    if (rtb_Gain_hl_idx_2 >= -rtb_Integrator1_m) {
      rtb_Divide_m_idx_1 = rtb_Gain_hl_idx_2;
    }

    /* MultiPortSwitch: '<S105>/Multiport Switch' incorporates:
     *  Constant: '<S107>/Constant3'
     *  Constant: '<S110>/Constant3'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S107>/Multiply1'
     *  Product: '<S107>/Multiply2'
     *  Product: '<S110>/Multiply1'
     *  Product: '<S110>/Multiply2'
     *  Sum: '<S107>/Sum'
     *  Sum: '<S107>/Sum1'
     *  Sum: '<S110>/Sum'
     *  Sum: '<S110>/Sum1'
     */
    switch (Controller_U.FMS_Out.ext_state) {
     case 1:
      /* Saturate: '<S110>/Saturation3' */
      if (rtb_Multiply_ni[0] > 8.0F) {
        rtb_Divide_m_idx_2 = 8.0F;
      } else if (rtb_Multiply_ni[0] < 2.0F) {
        rtb_Divide_m_idx_2 = 2.0F;
      } else {
        rtb_Divide_m_idx_2 = rtb_Multiply_ni[0];
      }

      /* End of Saturate: '<S110>/Saturation3' */

      /* Product: '<S110>/Multiply' incorporates:
       *  Constant: '<S110>/Constant1'
       *  Sum: '<S110>/Subtract1'
       */
      rtb_Divide_m_idx_1 = (rtb_Divide_m_idx_2 - 2.0F) *
        Controller_ConstB.Divide_k;

      /* Switch: '<S133>/Switch2' incorporates:
       *  RelationalOperator: '<S133>/LowerRelop1'
       */
      if (rtb_Subtract1_jj > rtb_DiscreteTimeIntegrator1_a) {
        rtb_Divide_m_idx_0 = rtb_DiscreteTimeIntegrator1_a;
      }

      Controller_B.Multiply[0] = (1.0F - rtb_Divide_m_idx_1) *
        rtb_Divide_m_idx_0 + rtb_Divide_m_idx_1 * Controller_B.Reshape[0];
      Controller_B.Multiply[1] = Controller_B.Reshape[1];
      Controller_B.Multiply[2] = (1.0F - rtb_Divide_m_idx_1) *
        Controller_U.FMS_Out.psi_rate_cmd + rtb_Divide_m_idx_1 *
        Controller_B.Reshape[2];
      break;

     case 3:
      /* Saturate: '<S107>/Saturation3' */
      if (rtb_Multiply_ni[0] > 8.0F) {
        rtb_Divide_m_idx_2 = 8.0F;
      } else if (rtb_Multiply_ni[0] < 2.0F) {
        rtb_Divide_m_idx_2 = 2.0F;
      } else {
        rtb_Divide_m_idx_2 = rtb_Multiply_ni[0];
      }

      /* End of Saturate: '<S107>/Saturation3' */

      /* Product: '<S107>/Multiply' incorporates:
       *  Constant: '<S107>/Constant1'
       *  Sum: '<S107>/Subtract1'
       */
      rtb_Divide_m_idx_2 = (rtb_Divide_m_idx_2 - 2.0F) *
        Controller_ConstB.Divide;

      /* Switch: '<S133>/Switch2' incorporates:
       *  RelationalOperator: '<S133>/LowerRelop1'
       */
      if (rtb_Subtract1_jj > rtb_DiscreteTimeIntegrator1_a) {
        rtb_Divide_m_idx_0 = rtb_DiscreteTimeIntegrator1_a;
      }

      Controller_B.Multiply[0] = (1.0F - rtb_Divide_m_idx_2) *
        rtb_Divide_m_idx_0 + rtb_Divide_m_idx_2 * Controller_B.Reshape[0];

      /* Switch: '<S133>/Switch2' incorporates:
       *  Constant: '<S107>/Constant3'
       *  Product: '<S107>/Multiply1'
       *  Product: '<S107>/Multiply2'
       *  RelationalOperator: '<S133>/LowerRelop1'
       *  Sum: '<S107>/Sum'
       *  Sum: '<S107>/Sum1'
       */
      if (rtb_Gain_hl_idx_2 > rtb_Integrator1_m) {
        rtb_Divide_m_idx_1 = rtb_Integrator1_m;
      }

      Controller_B.Multiply[1] = (1.0F - rtb_Divide_m_idx_2) *
        rtb_Divide_m_idx_1 + rtb_Divide_m_idx_2 * Controller_B.Reshape[1];
      Controller_B.Multiply[2] = (1.0F - rtb_Divide_m_idx_2) *
        Controller_U.FMS_Out.psi_rate_cmd + rtb_Divide_m_idx_2 *
        Controller_B.Reshape[2];
      break;

     case 4:
      Controller_B.Multiply[0] = Controller_B.Reshape[0];
      Controller_B.Multiply[1] = Controller_B.Reshape[1];
      Controller_B.Multiply[2] = Controller_B.Reshape[2];
      break;

     default:
      /* Switch: '<S133>/Switch2' incorporates:
       *  RelationalOperator: '<S133>/LowerRelop1'
       */
      if (rtb_Subtract1_jj > rtb_DiscreteTimeIntegrator1_a) {
        Controller_B.Multiply[0] = rtb_DiscreteTimeIntegrator1_a;
      } else {
        Controller_B.Multiply[0] = rtb_Divide_m_idx_0;
      }

      if (rtb_Gain_hl_idx_2 > rtb_Integrator1_m) {
        Controller_B.Multiply[1] = rtb_Integrator1_m;
      } else {
        Controller_B.Multiply[1] = rtb_Divide_m_idx_1;
      }

      Controller_B.Multiply[2] = Controller_U.FMS_Out.psi_rate_cmd;
      break;
    }

    /* End of MultiPortSwitch: '<S105>/Multiport Switch' */

    /* Trigonometry: '<S108>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Subtract1_jj = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Trigonometry: '<S108>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_a_k = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S108>/Sin' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Integrator1_m = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Sum: '<S108>/Add2' incorporates:
     *  Product: '<S108>/Multiply4'
     *  Product: '<S108>/Multiply5'
     *  Trigonometry: '<S108>/Cos'
     *  Trigonometry: '<S108>/Cos1'
     *  Trigonometry: '<S108>/Sin'
     */
    rtb_Subtract3_g = rtb_a_k * rtb_Subtract1_jj * Controller_B.Multiply[2] -
      rtb_Integrator1_m * Controller_B.Multiply[1];

    /* Saturate: '<S105>/Saturation' */
    if (rtb_Subtract3_g > CONTROL_PARAM.MC_R_CMD_LIM) {
      rtb_Subtract3_g = CONTROL_PARAM.MC_R_CMD_LIM;
    } else {
      if (rtb_Subtract3_g < -CONTROL_PARAM.MC_R_CMD_LIM) {
        rtb_Subtract3_g = -CONTROL_PARAM.MC_R_CMD_LIM;
      }
    }

    /* End of Saturate: '<S105>/Saturation' */

    /* Sum: '<S108>/Add' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S108>/Multiply'
     *  Trigonometry: '<S108>/Sin1'
     */
    rtb_DiscreteTimeIntegrator1_a = Controller_B.Multiply[0] - arm_sin_f32
      (Controller_U.INS_Out.theta) * Controller_B.Multiply[2];

    /* Saturate: '<S105>/Saturation1' */
    if (rtb_DiscreteTimeIntegrator1_a > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_DiscreteTimeIntegrator1_a = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_DiscreteTimeIntegrator1_a < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_DiscreteTimeIntegrator1_a = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    /* End of Saturate: '<S105>/Saturation1' */

    /* Sum: '<S108>/Add1' incorporates:
     *  Product: '<S108>/Multiply1'
     *  Product: '<S108>/Multiply3'
     *  Trigonometry: '<S108>/Cos'
     *  Trigonometry: '<S108>/Cos1'
     *  Trigonometry: '<S108>/Sin'
     */
    rtb_Integrator1_m = rtb_Integrator1_m * rtb_Subtract1_jj *
      Controller_B.Multiply[2] + rtb_a_k * Controller_B.Multiply[1];

    /* Saturate: '<S105>/Saturation2' */
    if (rtb_Integrator1_m > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_Integrator1_m = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_Integrator1_m < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_Integrator1_m = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    /* End of Saturate: '<S105>/Saturation2' */

    /* Sum: '<S117>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_m_idx_0 = rtb_DiscreteTimeIntegrator1_a - Controller_U.INS_Out.p;

    /* Saturate: '<S117>/Saturation' */
    if (rtb_Divide_m_idx_0 > 3.14159274F) {
      rtb_Divide_m_idx_0 = 3.14159274F;
    } else {
      if (rtb_Divide_m_idx_0 < -3.14159274F) {
        rtb_Divide_m_idx_0 = -3.14159274F;
      }
    }

    /* Sum: '<S117>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_m_idx_1 = rtb_Integrator1_m - Controller_U.INS_Out.q;

    /* Saturate: '<S117>/Saturation' */
    if (rtb_Divide_m_idx_1 > 3.14159274F) {
      rtb_Divide_m_idx_1 = 3.14159274F;
    } else {
      if (rtb_Divide_m_idx_1 < -3.14159274F) {
        rtb_Divide_m_idx_1 = -3.14159274F;
      }
    }

    /* Sum: '<S117>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_m_idx_2 = rtb_Subtract3_g - Controller_U.INS_Out.r;

    /* Saturate: '<S117>/Saturation' */
    if (rtb_Divide_m_idx_2 > 3.14159274F) {
      rtb_Divide_m_idx_2 = 3.14159274F;
    } else {
      if (rtb_Divide_m_idx_2 < -3.14159274F) {
        rtb_Divide_m_idx_2 = -3.14159274F;
      }
    }

    /* DiscreteIntegrator: '<S121>/Discrete-Time Integrator5' incorporates:
     *  Saturate: '<S117>/Saturation'
     */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_c != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0] = rtb_Divide_m_idx_0;
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1] = rtb_Divide_m_idx_1;
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2] = rtb_Divide_m_idx_2;
    }

    /* DiscreteIntegrator: '<S126>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S121>/Discrete-Time Integrator5'
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

    /* Gain: '<S126>/Gain' incorporates:
     *  DiscreteIntegrator: '<S121>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S126>/Discrete-Time Integrator1'
     *  Sum: '<S126>/Sum5'
     */
    rtb_Add_k = (Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0] -
                 Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[0]) * 188.49556F;
    rtb_Add1_j4 = (Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1] -
                   Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[1]) *
      188.49556F;
    rtb_Divide_m_idx_3 = (Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2] -
                          Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[2]) *
      188.49556F;

    /* Switch: '<S126>/Switch' incorporates:
     *  Gain: '<S126>/Gain1'
     *  Inport: '<Root>/FMS_Out'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_Subtract1_jj = 0.0F;
      rtb_a_k = 0.0F;
      rtb_Gain_hl_idx_2 = 0.0F;
    } else {
      rtb_Subtract1_jj = rtb_Add_k;
      rtb_a_k = rtb_Add1_j4;
      rtb_Gain_hl_idx_2 = rtb_Divide_m_idx_3;
    }

    /* End of Switch: '<S126>/Switch' */

    /* Product: '<S123>/Multiply' incorporates:
     *  Constant: '<S123>/gain1'
     */
    rtb_Subtract1_ha_idx_1 = CONTROL_PARAM.MC_ROLL_RATE_D * rtb_Subtract1_jj;

    /* Saturate: '<S123>/Saturation' */
    if (rtb_Subtract1_ha_idx_1 > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Subtract1_ha_idx_1 = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Subtract1_ha_idx_1 < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Subtract1_ha_idx_1 = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    /* Product: '<S123>/Multiply' incorporates:
     *  Constant: '<S123>/gain2'
     */
    rtb_Subtract1_jj = rtb_Subtract1_ha_idx_1;
    rtb_Subtract1_ha_idx_1 = CONTROL_PARAM.MC_PITCH_RATE_D * rtb_a_k;

    /* Saturate: '<S123>/Saturation' */
    if (rtb_Subtract1_ha_idx_1 > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Subtract1_ha_idx_1 = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Subtract1_ha_idx_1 < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Subtract1_ha_idx_1 = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    /* Product: '<S123>/Multiply' incorporates:
     *  Constant: '<S123>/gain3'
     */
    rtb_a_k = rtb_Subtract1_ha_idx_1;
    rtb_Subtract1_ha_idx_1 = CONTROL_PARAM.MC_YAW_RATE_D * rtb_Gain_hl_idx_2;

    /* Saturate: '<S123>/Saturation' */
    if (rtb_Subtract1_ha_idx_1 > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Subtract1_ha_idx_1 = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Subtract1_ha_idx_1 < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Subtract1_ha_idx_1 = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    /* Sum: '<S119>/Add' incorporates:
     *  Constant: '<S125>/gain1'
     *  Constant: '<S125>/gain2'
     *  Constant: '<S125>/gain3'
     *  DiscreteIntegrator: '<S121>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S124>/Discrete-Time Integrator'
     *  Product: '<S125>/Multiply'
     */
    Controller_B.Multiply[0] = (CONTROL_PARAM.MC_ROLL_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0]) + rtb_Subtract1_jj;
    Controller_B.Multiply[1] = (CONTROL_PARAM.MC_PITCH_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1]) + rtb_a_k;
    Controller_B.Multiply[2] = (CONTROL_PARAM.MC_YAW_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[2]) + rtb_Subtract1_ha_idx_1;

    /* DeadZone: '<S122>/Dead Zone' */
    if (rtb_DiscreteTimeIntegrator1_a > 0.1F) {
      rtb_DiscreteTimeIntegrator1_a -= 0.1F;
    } else if (rtb_DiscreteTimeIntegrator1_a >= -0.1F) {
      rtb_DiscreteTimeIntegrator1_a = 0.0F;
    } else {
      rtb_DiscreteTimeIntegrator1_a -= -0.1F;
    }

    /* Sum: '<S106>/Sum' incorporates:
     *  Gain: '<S118>/Gain'
     *  Gain: '<S122>/Gain'
     */
    Controller_B.Multiply[0] += 1.11111116F * rtb_DiscreteTimeIntegrator1_a *
      CONTROL_PARAM.MC_ROLL_RATE_FF;

    /* Product: '<S6>/Multiply' incorporates:
     *  DiscreteIntegrator: '<S10>/Discrete-Time Integrator5'
     */
    Controller_B.Multiply[0] *= Controller_DW.DiscreteTimeIntegrator5_DSTATE;

    /* DeadZone: '<S122>/Dead Zone' */
    if (rtb_Integrator1_m > 0.1F) {
      rtb_Integrator1_m -= 0.1F;
    } else if (rtb_Integrator1_m >= -0.1F) {
      rtb_Integrator1_m = 0.0F;
    } else {
      rtb_Integrator1_m -= -0.1F;
    }

    /* Sum: '<S106>/Sum' incorporates:
     *  Gain: '<S118>/Gain'
     *  Gain: '<S122>/Gain'
     */
    Controller_B.Multiply[1] += 1.11111116F * rtb_Integrator1_m *
      CONTROL_PARAM.MC_ROLL_RATE_FF;

    /* Product: '<S6>/Multiply' incorporates:
     *  DiscreteIntegrator: '<S10>/Discrete-Time Integrator5'
     */
    Controller_B.Multiply[1] *= Controller_DW.DiscreteTimeIntegrator5_DSTATE;

    /* DeadZone: '<S122>/Dead Zone' */
    if (rtb_Subtract3_g > 0.1F) {
      rtb_Subtract3_g -= 0.1F;
    } else if (rtb_Subtract3_g >= -0.1F) {
      rtb_Subtract3_g = 0.0F;
    } else {
      rtb_Subtract3_g -= -0.1F;
    }

    /* Sum: '<S106>/Sum' incorporates:
     *  Gain: '<S118>/Gain1'
     *  Gain: '<S122>/Gain'
     */
    Controller_B.Multiply[2] += 1.11111116F * rtb_Subtract3_g *
      CONTROL_PARAM.MC_PITCH_RATE_FF;

    /* Product: '<S6>/Multiply' incorporates:
     *  DiscreteIntegrator: '<S10>/Discrete-Time Integrator5'
     */
    Controller_B.Multiply[2] *= Controller_DW.DiscreteTimeIntegrator5_DSTATE;

    /* Product: '<S147>/Multiply1' incorporates:
     *  Constant: '<S147>/const1'
     *  DiscreteIntegrator: '<S144>/Integrator'
     */
    rtb_DiscreteTimeIntegrator1_a = Controller_DW.Integrator_DSTATE[0] * 0.05F;
    rtb_a_k = Controller_DW.Integrator_DSTATE[1] * 0.05F;

    /* Switch: '<S139>/Switch' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    if (rtb_Compare_b) {
      rtb_Add4_l = Controller_U.FMS_Out.u_cmd;
    } else {
      rtb_Add4_l = rtb_TmpSignalConversionAtMultip[0];
    }

    /* Sum: '<S147>/Add' incorporates:
     *  DiscreteIntegrator: '<S144>/Integrator1'
     *  Sum: '<S144>/Subtract'
     */
    rtb_Subtract1_jj = (Controller_DW.Integrator1_DSTATE[0] - rtb_Add4_l) +
      rtb_DiscreteTimeIntegrator1_a;

    /* Switch: '<S139>/Switch' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    if (rtb_Compare_b) {
      rtb_Add4_l = Controller_U.FMS_Out.v_cmd;
    } else {
      rtb_Add4_l = rtb_TmpSignalConversionAtMultip[1];
    }

    /* Sum: '<S147>/Add' incorporates:
     *  DiscreteIntegrator: '<S144>/Integrator1'
     *  Sum: '<S144>/Subtract'
     */
    rtb_Subtract1_ha_idx_1 = (Controller_DW.Integrator1_DSTATE[1] - rtb_Add4_l)
      + rtb_a_k;

    /* Signum: '<S147>/Sign' */
    if (rtb_Subtract1_jj < 0.0F) {
      rtb_Subtract3_g = -1.0F;
    } else if (rtb_Subtract1_jj > 0.0F) {
      rtb_Subtract3_g = 1.0F;
    } else {
      rtb_Subtract3_g = rtb_Subtract1_jj;
    }

    /* Sum: '<S147>/Add2' incorporates:
     *  Abs: '<S147>/Abs'
     *  Gain: '<S147>/Gain'
     *  Gain: '<S147>/Gain1'
     *  Product: '<S147>/Multiply2'
     *  Product: '<S147>/Multiply3'
     *  Signum: '<S147>/Sign'
     *  Sqrt: '<S147>/Sqrt'
     *  Sum: '<S147>/Add1'
     *  Sum: '<S147>/Subtract'
     */
    rtb_Integrator1_m = (sqrtf((8.0F * fabsf(rtb_Subtract1_jj) +
      Controller_ConstB.d) * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
      rtb_Subtract3_g + rtb_DiscreteTimeIntegrator1_a;

    /* Sum: '<S147>/Add3' incorporates:
     *  Signum: '<S147>/Sign'
     */
    rtb_Subtract3_g = rtb_Subtract1_jj + Controller_ConstB.d;

    /* Sum: '<S147>/Subtract1' incorporates:
     *  Signum: '<S147>/Sign'
     */
    rtb_Gain_hl_idx_2 = rtb_Subtract1_jj - Controller_ConstB.d;

    /* Signum: '<S147>/Sign1' */
    if (rtb_Subtract3_g < 0.0F) {
      rtb_Subtract3_g = -1.0F;
    } else {
      if (rtb_Subtract3_g > 0.0F) {
        rtb_Subtract3_g = 1.0F;
      }
    }

    /* Signum: '<S147>/Sign2' */
    if (rtb_Gain_hl_idx_2 < 0.0F) {
      rtb_Gain_hl_idx_2 = -1.0F;
    } else {
      if (rtb_Gain_hl_idx_2 > 0.0F) {
        rtb_Gain_hl_idx_2 = 1.0F;
      }
    }

    /* Sum: '<S147>/Add2' incorporates:
     *  Gain: '<S147>/Gain2'
     *  Product: '<S147>/Multiply4'
     *  Signum: '<S147>/Sign'
     *  Sum: '<S147>/Add4'
     *  Sum: '<S147>/Add5'
     *  Sum: '<S147>/Subtract2'
     */
    rtb_DiscreteTimeIntegrator1_a = ((rtb_Subtract1_jj - rtb_Integrator1_m) +
      rtb_DiscreteTimeIntegrator1_a) * ((rtb_Subtract3_g - rtb_Gain_hl_idx_2) *
      0.5F) + rtb_Integrator1_m;

    /* Signum: '<S147>/Sign' */
    if (rtb_Subtract1_ha_idx_1 < 0.0F) {
      rtb_Subtract3_g = -1.0F;
    } else if (rtb_Subtract1_ha_idx_1 > 0.0F) {
      rtb_Subtract3_g = 1.0F;
    } else {
      rtb_Subtract3_g = rtb_Subtract1_ha_idx_1;
    }

    /* Sum: '<S147>/Add2' incorporates:
     *  Abs: '<S147>/Abs'
     *  Gain: '<S147>/Gain'
     *  Gain: '<S147>/Gain1'
     *  Product: '<S147>/Multiply2'
     *  Product: '<S147>/Multiply3'
     *  Signum: '<S147>/Sign'
     *  Sqrt: '<S147>/Sqrt'
     *  Sum: '<S147>/Add1'
     *  Sum: '<S147>/Subtract'
     */
    rtb_Integrator1_m = (sqrtf((8.0F * fabsf(rtb_Subtract1_ha_idx_1) +
      Controller_ConstB.d) * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
      rtb_Subtract3_g + rtb_a_k;

    /* Sum: '<S147>/Add3' incorporates:
     *  Signum: '<S147>/Sign'
     */
    rtb_Subtract3_g = rtb_Subtract1_ha_idx_1 + Controller_ConstB.d;

    /* Sum: '<S147>/Subtract1' incorporates:
     *  Signum: '<S147>/Sign'
     */
    rtb_Gain_hl_idx_2 = rtb_Subtract1_ha_idx_1 - Controller_ConstB.d;

    /* Signum: '<S147>/Sign1' */
    if (rtb_Subtract3_g < 0.0F) {
      rtb_Subtract3_g = -1.0F;
    } else {
      if (rtb_Subtract3_g > 0.0F) {
        rtb_Subtract3_g = 1.0F;
      }
    }

    /* Signum: '<S147>/Sign2' */
    if (rtb_Gain_hl_idx_2 < 0.0F) {
      rtb_Gain_hl_idx_2 = -1.0F;
    } else {
      if (rtb_Gain_hl_idx_2 > 0.0F) {
        rtb_Gain_hl_idx_2 = 1.0F;
      }
    }

    /* Sum: '<S147>/Add5' incorporates:
     *  Gain: '<S147>/Gain2'
     *  Product: '<S147>/Multiply4'
     *  Signum: '<S147>/Sign'
     *  Sum: '<S147>/Add2'
     *  Sum: '<S147>/Add4'
     *  Sum: '<S147>/Subtract2'
     */
    rtb_Integrator1_m += ((rtb_Subtract1_ha_idx_1 - rtb_Integrator1_m) + rtb_a_k)
      * ((rtb_Subtract3_g - rtb_Gain_hl_idx_2) * 0.5F);

    /* RelationalOperator: '<S162>/Compare' incorporates:
     *  Constant: '<S162>/Constant'
     *  Inport: '<Root>/FMS_Out'
     */
    rtb_Compare_b = (Controller_U.FMS_Out.mode >= 4);

    /* Product: '<S160>/Multiply' incorporates:
     *  DataTypeConversion: '<S160>/Data Type Conversion'
     *  DiscreteIntegrator: '<S163>/Integrator1'
     *  Gain: '<S160>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S160>/Sum1'
     */
    rtb_Gain_hl_idx_2 = -(Controller_DW.Integrator1_DSTATE_e -
                          Controller_U.INS_Out.vd) * (real32_T)rtb_Compare_b;

    /* Constant: '<S166>/Constant' */
    Controller_B.Constant = CONTROL_PARAM.MC_VEL_Z_I_MIN;

    /* DiscreteIntegrator: '<S166>/Discrete-Time Integrator' incorporates:
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

    /* DiscreteIntegrator: '<S168>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_d != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i = rtb_Gain_hl_idx_2;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_Prev_ks != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i = rtb_Gain_hl_idx_2;
    }

    /* Gain: '<S168>/Gain' incorporates:
     *  DiscreteIntegrator: '<S168>/Discrete-Time Integrator1'
     *  Sum: '<S168>/Sum5'
     */
    rtb_Subtract1_ha_idx_1 = (rtb_Gain_hl_idx_2 -
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i) * 62.831852F;

    /* Switch: '<S156>/Switch' incorporates:
     *  Bias: '<S156>/Bias'
     *  Constant: '<S158>/Constant'
     *  Gain: '<S156>/Gain'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S158>/Compare'
     */
    if (Controller_U.FMS_Out.ctrl_mode <= 3) {
      rtb_Subtract3_g = 0.000999987125F * (real32_T)
        Controller_U.FMS_Out.throttle_cmd + -1.0F;
    } else {
      /* Product: '<S159>/Multiply' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S159>/Cos'
       *  Trigonometry: '<S159>/Cos1'
       */
      rtb_a_k = arm_cos_f32(Controller_U.INS_Out.phi) * arm_cos_f32
        (Controller_U.INS_Out.theta);

      /* Gain: '<S159>/Gain' */
      rtb_Subtract1_jj = 2.0F * rtb_a_k;

      /* Saturate: '<S159>/Saturation1' */
      if (rtb_a_k > 1.0F) {
        rtb_a_k = 1.0F;
      } else {
        if (rtb_a_k < 0.5F) {
          rtb_a_k = 0.5F;
        }
      }

      /* End of Saturate: '<S159>/Saturation1' */

      /* Product: '<S159>/Divide' incorporates:
       *  Constant: '<S159>/Constant'
       */
      rtb_Subtract3_g = 1.0F / rtb_a_k;

      /* Switch: '<S168>/Switch' incorporates:
       *  Gain: '<S168>/Gain1'
       */
      if (Controller_U.FMS_Out.reset > 0) {
        rtb_a_k = 0.0F;
      } else {
        rtb_a_k = rtb_Subtract1_ha_idx_1;
      }

      /* End of Switch: '<S168>/Switch' */

      /* Product: '<S165>/Multiply' incorporates:
       *  Constant: '<S165>/kd'
       */
      rtb_a_k *= CONTROL_PARAM.MC_VEL_Z_D;

      /* Saturate: '<S165>/Saturation' */
      if (rtb_a_k > CONTROL_PARAM.MC_VEL_Z_D_MAX) {
        rtb_a_k = CONTROL_PARAM.MC_VEL_Z_D_MAX;
      } else {
        if (rtb_a_k < CONTROL_PARAM.MC_VEL_Z_D_MIN) {
          rtb_a_k = CONTROL_PARAM.MC_VEL_Z_D_MIN;
        }
      }

      /* End of Saturate: '<S165>/Saturation' */

      /* Saturate: '<S159>/Saturation' */
      if (rtb_Subtract1_jj > 1.0F) {
        rtb_Subtract1_jj = 1.0F;
      } else {
        if (rtb_Subtract1_jj < 0.0F) {
          rtb_Subtract1_jj = 0.0F;
        }
      }

      /* End of Saturate: '<S159>/Saturation' */

      /* Sum: '<S157>/Sum' incorporates:
       *  Constant: '<S157>/hover_throttle'
       *  Constant: '<S167>/kp'
       *  DiscreteIntegrator: '<S166>/Discrete-Time Integrator'
       *  Product: '<S159>/Multiply1'
       *  Product: '<S167>/Multiply'
       *  Sum: '<S161>/Add'
       */
      rtb_Subtract3_g = ((CONTROL_PARAM.MC_VEL_Z_P * rtb_Gain_hl_idx_2 +
                          Controller_DW.DiscreteTimeIntegrator_DSTATE_l) +
                         rtb_a_k) * rtb_Subtract3_g * rtb_Subtract1_jj +
        CONTROL_PARAM.MC_HOVER_THRO;

      /* Saturate: '<S157>/Saturation' */
      if (rtb_Subtract3_g > 0.85F) {
        rtb_Subtract3_g = 0.85F;
      } else {
        if (rtb_Subtract3_g < 0.3F) {
          rtb_Subtract3_g = 0.3F;
        }
      }

      /* End of Saturate: '<S157>/Saturation' */
    }

    /* End of Switch: '<S156>/Switch' */

    /* Product: '<S6>/Multiply1' incorporates:
     *  Constant: '<S156>/Constant'
     *  DiscreteIntegrator: '<S10>/Discrete-Time Integrator5'
     */
    Controller_B.Multiply1[0] = 0.0F;
    Controller_B.Multiply1[1] = 0.0F;
    Controller_B.Multiply1[2] = Controller_DW.DiscreteTimeIntegrator5_DSTATE *
      rtb_Subtract3_g;

    /* Product: '<S164>/Multiply1' incorporates:
     *  Constant: '<S164>/const1'
     *  DiscreteIntegrator: '<S163>/Integrator'
     */
    rtb_Subtract3_g = Controller_DW.Integrator_DSTATE_j * 0.05F;

    /* Switch: '<S160>/Switch' incorporates:
     *  Inport: '<Root>/FMS_Out'
     *  Inport: '<Root>/INS_Out'
     */
    if (rtb_Compare_b) {
      rtb_Add4_l = Controller_U.FMS_Out.w_cmd;
    } else {
      rtb_Add4_l = Controller_U.INS_Out.vd;
    }

    /* End of Switch: '<S160>/Switch' */

    /* Sum: '<S164>/Add' incorporates:
     *  DiscreteIntegrator: '<S163>/Integrator1'
     *  Sum: '<S163>/Subtract'
     */
    rtb_Subtract1_jj = (Controller_DW.Integrator1_DSTATE_e - rtb_Add4_l) +
      rtb_Subtract3_g;

    /* Signum: '<S164>/Sign' */
    if (rtb_Subtract1_jj < 0.0F) {
      rtb_a_k = -1.0F;
    } else if (rtb_Subtract1_jj > 0.0F) {
      rtb_a_k = 1.0F;
    } else {
      rtb_a_k = rtb_Subtract1_jj;
    }

    /* End of Signum: '<S164>/Sign' */

    /* Sum: '<S164>/Add2' incorporates:
     *  Abs: '<S164>/Abs'
     *  Gain: '<S164>/Gain'
     *  Gain: '<S164>/Gain1'
     *  Product: '<S164>/Multiply2'
     *  Product: '<S164>/Multiply3'
     *  Sqrt: '<S164>/Sqrt'
     *  Sum: '<S164>/Add1'
     *  Sum: '<S164>/Subtract'
     */
    rtb_a_k = (sqrtf((8.0F * fabsf(rtb_Subtract1_jj) + Controller_ConstB.d_i) *
                     Controller_ConstB.d_i) - Controller_ConstB.d_i) * 0.5F *
      rtb_a_k + rtb_Subtract3_g;

    /* Sum: '<S164>/Add4' */
    rtb_Add4_l = (rtb_Subtract1_jj - rtb_a_k) + rtb_Subtract3_g;

    /* Sum: '<S164>/Add3' */
    rtb_Subtract3_g = rtb_Subtract1_jj + Controller_ConstB.d_i;

    /* Sum: '<S164>/Subtract1' */
    rtb_Subtract1_jj -= Controller_ConstB.d_i;

    /* Signum: '<S164>/Sign1' */
    if (rtb_Subtract3_g < 0.0F) {
      rtb_Subtract3_g = -1.0F;
    } else {
      if (rtb_Subtract3_g > 0.0F) {
        rtb_Subtract3_g = 1.0F;
      }
    }

    /* End of Signum: '<S164>/Sign1' */

    /* Signum: '<S164>/Sign2' */
    if (rtb_Subtract1_jj < 0.0F) {
      rtb_Subtract1_jj = -1.0F;
    } else {
      if (rtb_Subtract1_jj > 0.0F) {
        rtb_Subtract1_jj = 1.0F;
      }
    }

    /* End of Signum: '<S164>/Sign2' */

    /* Sum: '<S164>/Add5' incorporates:
     *  Gain: '<S164>/Gain2'
     *  Product: '<S164>/Multiply4'
     *  Sum: '<S164>/Subtract2'
     */
    rtb_a_k += (rtb_Subtract3_g - rtb_Subtract1_jj) * 0.5F * rtb_Add4_l;

    /* Update for DiscreteIntegrator: '<S124>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S124>/gain1'
     *  Constant: '<S124>/gain2'
     *  Constant: '<S124>/gain3'
     *  DiscreteIntegrator: '<S121>/Discrete-Time Integrator5'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S124>/Multiply'
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

    /* End of Update for DiscreteIntegrator: '<S124>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S149>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_PrevRe_p = (int8_T)
      rtb_LogicalOperator_h;

    /* Update for DiscreteIntegrator: '<S151>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;

    /* Update for DiscreteIntegrator: '<S144>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S144>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE[0] += 0.002F *
      Controller_DW.Integrator_DSTATE[0];

    /* Update for DiscreteIntegrator: '<S149>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S149>/ki'
     *  Product: '<S149>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0] +=
      CONTROL_PARAM.MC_VEL_XY_I * rtb_Saturation1 * 0.002F;
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

    /* Update for DiscreteIntegrator: '<S151>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] += 0.002F * rtb_Gain_c4;

    /* Update for DiscreteIntegrator: '<S144>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S144>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE[1] += 0.002F *
      Controller_DW.Integrator_DSTATE[1];

    /* Update for DiscreteIntegrator: '<S149>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S149>/ki'
     *  Product: '<S149>/Multiply'
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

    /* Update for DiscreteIntegrator: '<S151>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] += 0.002F * rtb_VdotPg;
    Controller_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
      rtb_LogicalOperator_h;

    /* Update for DiscreteIntegrator: '<S121>/Discrete-Time Integrator5' */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_c = 0U;

    /* Update for DiscreteIntegrator: '<S126>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 0U;

    /* Update for DiscreteIntegrator: '<S121>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S121>/Gain'
     *  Saturate: '<S117>/Saturation'
     *  Sum: '<S121>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0] += (rtb_Divide_m_idx_0 -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S126>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[0] += 0.002F * rtb_Add_k;

    /* Update for DiscreteIntegrator: '<S121>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S121>/Gain'
     *  Saturate: '<S117>/Saturation'
     *  Sum: '<S121>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1] += (rtb_Divide_m_idx_1 -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S126>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[1] += 0.002F * rtb_Add1_j4;

    /* Update for DiscreteIntegrator: '<S121>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S121>/Gain'
     *  Saturate: '<S117>/Saturation'
     *  Sum: '<S121>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2] += (rtb_Divide_m_idx_2 -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S126>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[2] += 0.002F *
      rtb_Divide_m_idx_3;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_k = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Signum: '<S147>/Sign3' incorporates:
     *  Product: '<S147>/Divide'
     *  Sum: '<S147>/Add6'
     */
    rtb_Subtract3_g = rtb_DiscreteTimeIntegrator1_a + Controller_ConstB.d;

    /* Signum: '<S147>/Sign4' incorporates:
     *  Product: '<S147>/Divide'
     *  Sum: '<S147>/Subtract3'
     */
    rtb_Divide_m_idx_0 = rtb_DiscreteTimeIntegrator1_a - Controller_ConstB.d;

    /* Signum: '<S147>/Sign5' incorporates:
     *  Product: '<S147>/Divide'
     */
    if (rtb_DiscreteTimeIntegrator1_a < 0.0F) {
      rtb_Divide_m_idx_1 = -1.0F;
    } else if (rtb_DiscreteTimeIntegrator1_a > 0.0F) {
      rtb_Divide_m_idx_1 = 1.0F;
    } else {
      rtb_Divide_m_idx_1 = rtb_DiscreteTimeIntegrator1_a;
    }

    /* Signum: '<S147>/Sign3' */
    if (rtb_Subtract3_g < 0.0F) {
      rtb_Subtract3_g = -1.0F;
    } else {
      if (rtb_Subtract3_g > 0.0F) {
        rtb_Subtract3_g = 1.0F;
      }
    }

    /* Signum: '<S147>/Sign4' */
    if (rtb_Divide_m_idx_0 < 0.0F) {
      rtb_Divide_m_idx_0 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_0 > 0.0F) {
        rtb_Divide_m_idx_0 = 1.0F;
      }
    }

    /* Signum: '<S147>/Sign6' incorporates:
     *  Product: '<S147>/Divide'
     */
    if (rtb_DiscreteTimeIntegrator1_a < 0.0F) {
      rtb_Divide_m_idx_2 = -1.0F;
    } else if (rtb_DiscreteTimeIntegrator1_a > 0.0F) {
      rtb_Divide_m_idx_2 = 1.0F;
    } else {
      rtb_Divide_m_idx_2 = rtb_DiscreteTimeIntegrator1_a;
    }

    /* Update for DiscreteIntegrator: '<S144>/Integrator' incorporates:
     *  Constant: '<S147>/const'
     *  Gain: '<S147>/Gain3'
     *  Product: '<S147>/Divide'
     *  Product: '<S147>/Multiply5'
     *  Product: '<S147>/Multiply6'
     *  Sum: '<S147>/Subtract4'
     *  Sum: '<S147>/Subtract5'
     *  Sum: '<S147>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE[0] += ((rtb_DiscreteTimeIntegrator1_a /
      Controller_ConstB.d - rtb_Divide_m_idx_1) * Controller_ConstB.Gain4 *
      ((rtb_Subtract3_g - rtb_Divide_m_idx_0) * 0.5F) - rtb_Divide_m_idx_2 *
      58.836F) * 0.002F;

    /* Signum: '<S147>/Sign3' incorporates:
     *  Sum: '<S147>/Add6'
     */
    rtb_Subtract3_g = rtb_Integrator1_m + Controller_ConstB.d;

    /* Signum: '<S147>/Sign4' incorporates:
     *  Sum: '<S147>/Subtract3'
     */
    rtb_Divide_m_idx_0 = rtb_Integrator1_m - Controller_ConstB.d;

    /* Signum: '<S147>/Sign5' */
    if (rtb_Integrator1_m < 0.0F) {
      rtb_Divide_m_idx_1 = -1.0F;
    } else if (rtb_Integrator1_m > 0.0F) {
      rtb_Divide_m_idx_1 = 1.0F;
    } else {
      rtb_Divide_m_idx_1 = rtb_Integrator1_m;
    }

    /* Signum: '<S147>/Sign3' */
    if (rtb_Subtract3_g < 0.0F) {
      rtb_Subtract3_g = -1.0F;
    } else {
      if (rtb_Subtract3_g > 0.0F) {
        rtb_Subtract3_g = 1.0F;
      }
    }

    /* Signum: '<S147>/Sign4' */
    if (rtb_Divide_m_idx_0 < 0.0F) {
      rtb_Divide_m_idx_0 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_0 > 0.0F) {
        rtb_Divide_m_idx_0 = 1.0F;
      }
    }

    /* Signum: '<S147>/Sign6' */
    if (rtb_Integrator1_m < 0.0F) {
      rtb_Divide_m_idx_2 = -1.0F;
    } else if (rtb_Integrator1_m > 0.0F) {
      rtb_Divide_m_idx_2 = 1.0F;
    } else {
      rtb_Divide_m_idx_2 = rtb_Integrator1_m;
    }

    /* Update for DiscreteIntegrator: '<S144>/Integrator' incorporates:
     *  Constant: '<S147>/const'
     *  Gain: '<S147>/Gain3'
     *  Product: '<S147>/Divide'
     *  Product: '<S147>/Multiply5'
     *  Product: '<S147>/Multiply6'
     *  Sum: '<S147>/Subtract4'
     *  Sum: '<S147>/Subtract5'
     *  Sum: '<S147>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE[1] += ((rtb_Integrator1_m /
      Controller_ConstB.d - rtb_Divide_m_idx_1) * Controller_ConstB.Gain4 *
      ((rtb_Subtract3_g - rtb_Divide_m_idx_0) * 0.5F) - rtb_Divide_m_idx_2 *
      58.836F) * 0.002F;

    /* Update for DiscreteIntegrator: '<S163>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S163>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_e += 0.002F *
      Controller_DW.Integrator_DSTATE_j;

    /* Update for DiscreteIntegrator: '<S166>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S166>/ki'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S166>/Multiply'
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

    /* End of Update for DiscreteIntegrator: '<S166>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S168>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_i += 0.002F *
      rtb_Subtract1_ha_idx_1;
    Controller_DW.DiscreteTimeIntegrator1_Prev_ks = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Signum: '<S164>/Sign6' incorporates:
     *  Signum: '<S164>/Sign5'
     */
    if (rtb_a_k < 0.0F) {
      rtb_Divide_m_idx_2 = -1.0F;

      /* Signum: '<S164>/Sign5' */
      rtb_Add_k = -1.0F;
    } else if (rtb_a_k > 0.0F) {
      rtb_Divide_m_idx_2 = 1.0F;

      /* Signum: '<S164>/Sign5' */
      rtb_Add_k = 1.0F;
    } else {
      rtb_Divide_m_idx_2 = rtb_a_k;

      /* Signum: '<S164>/Sign5' */
      rtb_Add_k = rtb_a_k;
    }

    /* End of Signum: '<S164>/Sign6' */

    /* Sum: '<S164>/Add6' */
    rtb_Subtract3_g = rtb_a_k + Controller_ConstB.d_i;

    /* Sum: '<S164>/Subtract3' */
    rtb_Divide_m_idx_0 = rtb_a_k - Controller_ConstB.d_i;

    /* Signum: '<S164>/Sign3' */
    if (rtb_Subtract3_g < 0.0F) {
      rtb_Subtract3_g = -1.0F;
    } else {
      if (rtb_Subtract3_g > 0.0F) {
        rtb_Subtract3_g = 1.0F;
      }
    }

    /* End of Signum: '<S164>/Sign3' */

    /* Signum: '<S164>/Sign4' */
    if (rtb_Divide_m_idx_0 < 0.0F) {
      rtb_Divide_m_idx_0 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_0 > 0.0F) {
        rtb_Divide_m_idx_0 = 1.0F;
      }
    }

    /* End of Signum: '<S164>/Sign4' */

    /* Update for DiscreteIntegrator: '<S163>/Integrator' incorporates:
     *  Constant: '<S164>/const'
     *  Gain: '<S164>/Gain3'
     *  Product: '<S164>/Divide'
     *  Product: '<S164>/Multiply5'
     *  Product: '<S164>/Multiply6'
     *  Sum: '<S164>/Subtract4'
     *  Sum: '<S164>/Subtract5'
     *  Sum: '<S164>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE_j += ((rtb_a_k / Controller_ConstB.d_i -
      rtb_Add_k) * Controller_ConstB.Gain4_p * ((rtb_Subtract3_g -
      rtb_Divide_m_idx_0) * 0.5F) - rtb_Divide_m_idx_2 * 78.448F) * 0.002F;
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

  /* Output and update for atomic system: '<S172>/VTOL1' */
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

    /* Saturate: '<S189>/Saturation' incorporates:
     *  Bias: '<S189>/Bias'
     *  Bias: '<S189>/Bias1'
     *  Bias: '<S189>/Bias2'
     *  Bias: '<S189>/Bias3'
     *  Constant: '<S189>/Constant'
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

    /* End of Saturate: '<S189>/Saturation' */

    /* Saturate: '<S176>/Saturation1' */
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

    /* End of Saturate: '<S176>/Saturation1' */

    /* Gain: '<S176>/Gain1' incorporates:
     *  Bias: '<S176>/Bias'
     *  Constant: '<S176>/Constant'
     */
    rtb_Gain1_l = ((real32_T)CONTROL_PARAM.MC_OUT_MAX + -1000.0F) * 0.001F;

    /* Saturate: '<S176>/Saturation2' */
    if (rtb_Multiply3[2] > 1.0F) {
      rtb_Saturation3_j = 1.0F;
    } else if (rtb_Multiply3[2] < 0.0F) {
      rtb_Saturation3_j = 0.0F;
    } else {
      rtb_Saturation3_j = rtb_Multiply3[2];
    }

    /* End of Saturate: '<S176>/Saturation2' */
    for (i_p = 0; i_p < 4; i_p++) {
      /* Product: '<S176>/Multiply' */
      rtb_Switch_gr_idx_1_p = Controller_ConstB.VTOL1.pq_column[i_p + 4] *
        rtb_Saturation1_l_idx_1_p + Controller_ConstB.VTOL1.pq_column[i_p] *
        rtb_Saturation1_l_idx_0_p;

      /* Sum: '<S176>/Sum' */
      rtb_Sum_e[i_p] = rtb_Switch_gr_idx_1_p + rtb_Saturation3_j;

      /* Product: '<S176>/Multiply' */
      rtb_floating_yaw[i_p] = rtb_Switch_gr_idx_1_p;
    }

    /* Gain: '<S176>/Gain2' incorporates:
     *  Bias: '<S176>/Bias1'
     *  Constant: '<S176>/Constant1'
     */
    rtb_Saturation1_l_idx_0_p = ((real32_T)CONTROL_PARAM.MC_OUT_MIN + -1000.0F) *
      0.001F;

    /* MinMax: '<S176>/Max' */
    rtb_Switch_gr_idx_1_p = fmaxf(fmaxf(fmaxf(rtb_Sum_e[0], rtb_Sum_e[1]),
      rtb_Sum_e[2]), rtb_Sum_e[3]);

    /* MinMax: '<S176>/Max1' */
    rtb_Saturation1_l_idx_1_p = fminf(fminf(fminf(rtb_Sum_e[0], rtb_Sum_e[1]),
      rtb_Sum_e[2]), rtb_Sum_e[3]);

    /* Switch: '<S183>/Switch' incorporates:
     *  Logic: '<S183>/Logical Operator'
     *  MinMax: '<S176>/Max'
     *  MinMax: '<S176>/Max1'
     *  RelationalOperator: '<S183>/Relational Operator'
     *  RelationalOperator: '<S183>/Relational Operator1'
     */
    if ((rtb_Switch_gr_idx_1_p > rtb_Gain1_l) || (rtb_Saturation1_l_idx_1_p <
         rtb_Saturation1_l_idx_0_p)) {
      /* Sum: '<S183>/Subtract1' */
      rtb_Switch_gr_idx_0_p = rtb_Gain1_l - rtb_Saturation1_l_idx_0_p;

      /* Sum: '<S183>/Subtract' */
      rtb_Subtract_h = rtb_Switch_gr_idx_1_p - rtb_Saturation1_l_idx_1_p;

      /* Switch: '<S183>/Switch1' incorporates:
       *  Constant: '<S183>/Constant3'
       *  Gain: '<S183>/Gain'
       *  Product: '<S183>/Divide'
       *  RelationalOperator: '<S183>/Relational Operator2'
       *  Sum: '<S183>/Add'
       *  Sum: '<S183>/Subtract2'
       *  Sum: '<S183>/Subtract3'
       */
      if (rtb_Subtract_h > rtb_Switch_gr_idx_0_p) {
        rtb_Switch_gr_idx_0_p /= rtb_Subtract_h;
        rtb_Switch_gr_idx_1_p = ((rtb_Gain1_l - rtb_Switch_gr_idx_1_p) +
          (rtb_Saturation1_l_idx_0_p - rtb_Saturation1_l_idx_1_p)) * 0.5F;
      } else {
        rtb_Switch_gr_idx_0_p = 1.0F;

        /* Switch: '<S183>/Switch2' incorporates:
         *  Constant: '<S183>/Constant3'
         *  RelationalOperator: '<S183>/Relational Operator3'
         *  Sum: '<S183>/Subtract4'
         *  Sum: '<S183>/Subtract5'
         */
        if (rtb_Switch_gr_idx_1_p > rtb_Gain1_l) {
          rtb_Switch_gr_idx_1_p = rtb_Gain1_l - rtb_Switch_gr_idx_1_p;
        } else {
          rtb_Switch_gr_idx_1_p = rtb_Saturation1_l_idx_0_p -
            rtb_Saturation1_l_idx_1_p;
        }

        /* End of Switch: '<S183>/Switch2' */
      }

      /* End of Switch: '<S183>/Switch1' */
    } else {
      rtb_Switch_gr_idx_0_p = 1.0F;
      rtb_Switch_gr_idx_1_p = 0.0F;
    }

    /* End of Switch: '<S183>/Switch' */

    /* Sum: '<S176>/Sum1' */
    rtb_Saturation3_j += rtb_Switch_gr_idx_1_p;

    /* Saturate: '<S176>/Saturation3' */
    if (rtb_Saturation3_j > 1.0F) {
      rtb_Saturation3_j = 1.0F;
    } else {
      if (rtb_Saturation3_j < 0.0F) {
        rtb_Saturation3_j = 0.0F;
      }
    }

    /* End of Saturate: '<S176>/Saturation3' */

    /* Sum: '<S176>/Sum2' incorporates:
     *  Product: '<S176>/Multiply1'
     */
    rtb_Switch_gr_idx_1_p = rtb_floating_yaw[0] * rtb_Switch_gr_idx_0_p +
      rtb_Saturation3_j;

    /* Saturate: '<S176>/Saturation4' */
    if (rtb_Switch_gr_idx_1_p > 1.0F) {
      rtb_Switch_gr_idx_1_p = 1.0F;
    } else {
      if (rtb_Switch_gr_idx_1_p < 0.0F) {
        rtb_Switch_gr_idx_1_p = 0.0F;
      }
    }

    /* Sum: '<S176>/Sum3' incorporates:
     *  Product: '<S176>/Multiply2'
     */
    rtb_Sum_e[0] = Controller_ConstB.VTOL1.r_column[0] *
      rtb_Saturation1_l_idx_2_p + rtb_Switch_gr_idx_1_p;

    /* Product: '<S176>/Multiply1' */
    rtb_floating_yaw[0] = rtb_Switch_gr_idx_1_p;

    /* Sum: '<S176>/Sum2' incorporates:
     *  Product: '<S176>/Multiply1'
     */
    rtb_Switch_gr_idx_1_p = rtb_floating_yaw[1] * rtb_Switch_gr_idx_0_p +
      rtb_Saturation3_j;

    /* Saturate: '<S176>/Saturation4' */
    if (rtb_Switch_gr_idx_1_p > 1.0F) {
      rtb_Switch_gr_idx_1_p = 1.0F;
    } else {
      if (rtb_Switch_gr_idx_1_p < 0.0F) {
        rtb_Switch_gr_idx_1_p = 0.0F;
      }
    }

    /* Sum: '<S176>/Sum3' incorporates:
     *  Product: '<S176>/Multiply2'
     */
    rtb_Sum_e[1] = Controller_ConstB.VTOL1.r_column[1] *
      rtb_Saturation1_l_idx_2_p + rtb_Switch_gr_idx_1_p;

    /* Product: '<S176>/Multiply1' */
    rtb_floating_yaw[1] = rtb_Switch_gr_idx_1_p;

    /* Sum: '<S176>/Sum2' incorporates:
     *  Product: '<S176>/Multiply1'
     */
    rtb_Switch_gr_idx_1_p = rtb_floating_yaw[2] * rtb_Switch_gr_idx_0_p +
      rtb_Saturation3_j;

    /* Saturate: '<S176>/Saturation4' */
    if (rtb_Switch_gr_idx_1_p > 1.0F) {
      rtb_Switch_gr_idx_1_p = 1.0F;
    } else {
      if (rtb_Switch_gr_idx_1_p < 0.0F) {
        rtb_Switch_gr_idx_1_p = 0.0F;
      }
    }

    /* Sum: '<S176>/Sum3' incorporates:
     *  Product: '<S176>/Multiply2'
     */
    rtb_Sum_e[2] = Controller_ConstB.VTOL1.r_column[2] *
      rtb_Saturation1_l_idx_2_p + rtb_Switch_gr_idx_1_p;

    /* Product: '<S176>/Multiply1' */
    rtb_floating_yaw[2] = rtb_Switch_gr_idx_1_p;

    /* Sum: '<S176>/Sum2' incorporates:
     *  Product: '<S176>/Multiply1'
     */
    rtb_Switch_gr_idx_1_p = rtb_floating_yaw[3] * rtb_Switch_gr_idx_0_p +
      rtb_Saturation3_j;

    /* Saturate: '<S176>/Saturation4' */
    if (rtb_Switch_gr_idx_1_p > 1.0F) {
      rtb_Switch_gr_idx_1_p = 1.0F;
    } else {
      if (rtb_Switch_gr_idx_1_p < 0.0F) {
        rtb_Switch_gr_idx_1_p = 0.0F;
      }
    }

    /* Sum: '<S176>/Sum3' incorporates:
     *  Product: '<S176>/Multiply2'
     */
    rtb_Sum_e[3] = Controller_ConstB.VTOL1.r_column[3] *
      rtb_Saturation1_l_idx_2_p + rtb_Switch_gr_idx_1_p;

    /* Product: '<S176>/Multiply1' */
    rtb_floating_yaw[3] = rtb_Switch_gr_idx_1_p;

    /* MATLAB Function: '<S176>/R_Remix' */
    Controller_R_Remix(rtb_Sum_e, rtb_Gain1_l, rtb_Saturation1_l_idx_0_p,
                       rtb_floating_yaw);

    /* MultiPortSwitch: '<S179>/Multiport Switch' incorporates:
     *  Constant: '<S180>/Constant1'
     *  Constant: '<S180>/Constant12'
     *  Constant: '<S180>/Constant2'
     *  Constant: '<S180>/Constant7'
     *  DataTypeConversion: '<S189>/Data Type Conversion'
     *  DataTypeConversion: '<S190>/Data Type Conversion'
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
        /* Saturate: '<S190>/Saturation' incorporates:
         *  Constant: '<S190>/Standby'
         *  Reshape: '<S190>/Reshape'
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

      /* Saturate: '<S190>/Saturation' incorporates:
       *  Bias: '<S190>/Bias'
       *  Constant: '<S190>/Constant'
       *  DataTypeConversion: '<S190>/Data Type Conversion'
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

      /* Saturate: '<S190>/Saturation' incorporates:
       *  Bias: '<S190>/Bias1'
       *  Constant: '<S190>/Constant'
       *  DataTypeConversion: '<S190>/Data Type Conversion'
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

      /* Saturate: '<S190>/Saturation' incorporates:
       *  Bias: '<S190>/Bias2'
       *  Constant: '<S190>/Constant'
       *  DataTypeConversion: '<S190>/Data Type Conversion'
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

      /* Saturate: '<S190>/Saturation' incorporates:
       *  Bias: '<S190>/Bias3'
       *  Constant: '<S190>/Constant'
       *  DataTypeConversion: '<S190>/Data Type Conversion'
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

      /* SignalConversion: '<S180>/ConcatBufferAtVector Concatenate2In3' incorporates:
       *  Constant: '<S180>/Constant11'
       *  Constant: '<S180>/Constant12'
       */
      rtb_MatrixConcatenate[10] = 0.0F;

      /* SignalConversion: '<S180>/ConcatBufferAtVector Concatenate2In2' incorporates:
       *  Constant: '<S180>/Constant10'
       */
      rtb_MatrixConcatenate[9] = 0.0F;

      /* SignalConversion: '<S180>/ConcatBufferAtVector Concatenate2In1' incorporates:
       *  Constant: '<S180>/Constant9'
       */
      rtb_MatrixConcatenate[8] = 0.0F;

      /* SignalConversion: '<S180>/ConcatBufferAtVector Concatenate1In4' incorporates:
       *  Constant: '<S180>/Constant8'
       */
      rtb_MatrixConcatenate[7] = 0.0F;
      rtb_MatrixConcatenate[6] = CONTROL_PARAM.FW_PITCH_EFFC *
        CONTROL_PARAM.FW_ELEVATOR_DIR;

      /* SignalConversion: '<S180>/ConcatBufferAtVector Concatenate1In2' incorporates:
       *  Constant: '<S180>/Constant6'
       *  Constant: '<S180>/Constant7'
       */
      rtb_MatrixConcatenate[5] = 0.0F;

      /* SignalConversion: '<S180>/ConcatBufferAtVector Concatenate1In1' incorporates:
       *  Constant: '<S180>/Constant5'
       */
      rtb_MatrixConcatenate[4] = 0.0F;

      /* SignalConversion: '<S180>/ConcatBufferAtVector ConcatenateIn4' incorporates:
       *  Constant: '<S180>/Constant4'
       */
      rtb_MatrixConcatenate[3] = 0.0F;

      /* SignalConversion: '<S180>/ConcatBufferAtVector ConcatenateIn3' incorporates:
       *  Constant: '<S180>/Constant3'
       */
      rtb_MatrixConcatenate[2] = 0.0F;
      rtb_MatrixConcatenate[1] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON2_DIR;
      rtb_MatrixConcatenate[0] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON1_DIR;

      /* Saturate: '<S175>/Saturation5' incorporates:
       *  Constant: '<S180>/Constant1'
       *  Constant: '<S180>/Constant2'
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

      /* End of Saturate: '<S175>/Saturation5' */
      for (i_p = 0; i_p < 4; i_p++) {
        /* Bias: '<S175>/Bias' incorporates:
         *  Gain: '<S175>/Gain1'
         *  Product: '<S175>/Multiply1'
         */
        rtb_Saturation5_o[i_p] = 500.0F * (rtb_MatrixConcatenate[i_p + 8] *
          rtb_Saturation3_j + (rtb_MatrixConcatenate[i_p + 4] * rtb_Gain1_l +
          rtb_MatrixConcatenate[i_p] * rtb_Saturation1_l_idx_2_p)) + 1500.0F;

        /* Sum: '<S176>/Sum4' */
        rtb_Saturation1_l_idx_0_p = rtb_Sum_e[i_p] + rtb_floating_yaw[i_p];

        /* Saturate: '<S176>/Saturation5' */
        if (rtb_Saturation1_l_idx_0_p > 1.0F) {
          rtb_Saturation1_l_idx_0_p = 1.0F;
        } else {
          if (rtb_Saturation1_l_idx_0_p < 0.0F) {
            rtb_Saturation1_l_idx_0_p = 0.0F;
          }
        }

        /* End of Saturate: '<S176>/Saturation5' */

        /* DataTypeConversion: '<S176>/Data Type Conversion' incorporates:
         *  Constant: '<S176>/Constant2'
         *  Gain: '<S176>/Gain3'
         *  Sum: '<S176>/Sum5'
         */
        u0_p = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          rtb_Saturation1_l_idx_0_p), 4.2949673E+9F) + 1000U);

        /* Saturate: '<S176>/Saturation' */
        if (u0_p > CONTROL_PARAM.MC_OUT_MAX) {
          rtb_VariantMergeForOutportactua[i_p] = CONTROL_PARAM.MC_OUT_MAX;
        } else if (u0_p < CONTROL_PARAM.MC_OUT_MIN) {
          rtb_VariantMergeForOutportactua[i_p] = CONTROL_PARAM.MC_OUT_MIN;
        } else {
          rtb_VariantMergeForOutportactua[i_p] = u0_p;
        }

        /* End of Saturate: '<S176>/Saturation' */
      }

      /* Saturate: '<S175>/Saturation' */
      if (rtb_Multiply1[0] > 1.0F) {
        rtb_Saturation1_l_idx_2_p = 1.0F;
      } else if (rtb_Multiply1[0] < 0.0F) {
        rtb_Saturation1_l_idx_2_p = 0.0F;
      } else {
        rtb_Saturation1_l_idx_2_p = rtb_Multiply1[0];
      }

      /* End of Saturate: '<S175>/Saturation' */

      /* DataTypeConversion: '<S182>/Data Type Conversion' incorporates:
       *  Constant: '<S182>/Constant1'
       *  Gain: '<S182>/Gain1'
       *  Sum: '<S182>/Sum1'
       */
      u0_p = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
        rtb_Saturation1_l_idx_2_p), 4.2949673E+9F) + 1000U);

      /* Saturate: '<S175>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[4] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[4] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[4] = u0_p;
      }

      /* DataTypeConversion: '<S175>/Data Type Conversion' incorporates:
       *  Bias: '<S175>/Bias1'
       */
      rtb_Saturation1_l_idx_2_p = fmodf(floorf(rtb_Saturation5_o[0] +
        CONTROL_PARAM.SERVO1_BIAS), 65536.0F);
      u0_p = (uint16_T)(rtb_Saturation1_l_idx_2_p < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_l_idx_2_p :
                        (int32_T)(uint16_T)rtb_Saturation1_l_idx_2_p);

      /* Saturate: '<S175>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[5] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[5] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[5] = u0_p;
      }

      /* DataTypeConversion: '<S175>/Data Type Conversion1' incorporates:
       *  Bias: '<S175>/Bias2'
       */
      rtb_Saturation1_l_idx_2_p = fmodf(floorf(rtb_Saturation5_o[1] +
        CONTROL_PARAM.SERVO2_BIAS), 65536.0F);
      u0_p = (uint16_T)(rtb_Saturation1_l_idx_2_p < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_l_idx_2_p :
                        (int32_T)(uint16_T)rtb_Saturation1_l_idx_2_p);

      /* Saturate: '<S175>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[6] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[6] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[6] = u0_p;
      }

      /* DataTypeConversion: '<S175>/Data Type Conversion2' incorporates:
       *  Bias: '<S175>/Bias3'
       */
      rtb_Saturation1_l_idx_2_p = fmodf(floorf(rtb_Saturation5_o[2] +
        CONTROL_PARAM.SERVO3_BIAS), 65536.0F);
      u0_p = (uint16_T)(rtb_Saturation1_l_idx_2_p < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_l_idx_2_p :
                        (int32_T)(uint16_T)rtb_Saturation1_l_idx_2_p);

      /* Saturate: '<S175>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[7] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[7] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[7] = u0_p;
      }

      /* DataTypeConversion: '<S175>/Data Type Conversion3' incorporates:
       *  Bias: '<S175>/Bias4'
       */
      rtb_Saturation1_l_idx_2_p = fmodf(floorf(rtb_Saturation5_o[3] +
        CONTROL_PARAM.SERVO4_BIAS), 65536.0F);
      u0_p = (uint16_T)(rtb_Saturation1_l_idx_2_p < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_l_idx_2_p :
                        (int32_T)(uint16_T)rtb_Saturation1_l_idx_2_p);

      /* Saturate: '<S175>/Saturation1' */
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

    /* End of MultiPortSwitch: '<S179>/Multiport Switch' */
  }

#elif AIRFRAME == 2

  /* Output and update for atomic system: '<S172>/VTOL2' */
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

    /* Saturate: '<S201>/Saturation' incorporates:
     *  Bias: '<S201>/Bias'
     *  Bias: '<S201>/Bias1'
     *  Bias: '<S201>/Bias2'
     *  Bias: '<S201>/Bias3'
     *  Constant: '<S201>/Constant'
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

    /* End of Saturate: '<S201>/Saturation' */

    /* Saturate: '<S192>/Saturation1' */
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

    /* End of Saturate: '<S192>/Saturation1' */

    /* Gain: '<S192>/Gain1' incorporates:
     *  Bias: '<S192>/Bias'
     *  Constant: '<S192>/Constant'
     */
    rtb_Gain1_lm = ((real32_T)CONTROL_PARAM.MC_OUT_MAX + -1000.0F) * 0.001F;

    /* Saturate: '<S192>/Saturation2' */
    if (rtb_Multiply3[2] > 1.0F) {
      rtb_Saturation3_c = 1.0F;
    } else if (rtb_Multiply3[2] < 0.0F) {
      rtb_Saturation3_c = 0.0F;
    } else {
      rtb_Saturation3_c = rtb_Multiply3[2];
    }

    /* End of Saturate: '<S192>/Saturation2' */
    for (i_o = 0; i_o < 4; i_o++) {
      /* Product: '<S192>/Multiply' */
      rtb_Switch_ge_idx_1_o = Controller_ConstB.VTOL2.pq_column[i_o + 4] *
        rtb_Saturation1_p_idx_1_o + Controller_ConstB.VTOL2.pq_column[i_o] *
        rtb_Saturation1_p_idx_0_o;

      /* Sum: '<S192>/Sum' */
      rtb_Sum_m[i_o] = rtb_Switch_ge_idx_1_o + rtb_Saturation3_c;

      /* Product: '<S192>/Multiply' */
      rtb_floating_yaw_n[i_o] = rtb_Switch_ge_idx_1_o;
    }

    /* Gain: '<S192>/Gain2' incorporates:
     *  Bias: '<S192>/Bias1'
     *  Constant: '<S192>/Constant1'
     */
    rtb_Saturation1_p_idx_0_o = ((real32_T)CONTROL_PARAM.MC_OUT_MIN + -1000.0F) *
      0.001F;

    /* MinMax: '<S192>/Max' */
    rtb_Switch_ge_idx_1_o = fmaxf(fmaxf(fmaxf(rtb_Sum_m[0], rtb_Sum_m[1]),
      rtb_Sum_m[2]), rtb_Sum_m[3]);

    /* MinMax: '<S192>/Max1' */
    rtb_Saturation1_p_idx_1_o = fminf(fminf(fminf(rtb_Sum_m[0], rtb_Sum_m[1]),
      rtb_Sum_m[2]), rtb_Sum_m[3]);

    /* Switch: '<S198>/Switch' incorporates:
     *  Logic: '<S198>/Logical Operator'
     *  MinMax: '<S192>/Max'
     *  MinMax: '<S192>/Max1'
     *  RelationalOperator: '<S198>/Relational Operator'
     *  RelationalOperator: '<S198>/Relational Operator1'
     */
    if ((rtb_Switch_ge_idx_1_o > rtb_Gain1_lm) || (rtb_Saturation1_p_idx_1_o <
         rtb_Saturation1_p_idx_0_o)) {
      /* Sum: '<S198>/Subtract1' */
      rtb_Switch_ge_idx_0_o = rtb_Gain1_lm - rtb_Saturation1_p_idx_0_o;

      /* Sum: '<S198>/Subtract' */
      rtb_Subtract_g = rtb_Switch_ge_idx_1_o - rtb_Saturation1_p_idx_1_o;

      /* Switch: '<S198>/Switch1' incorporates:
       *  Constant: '<S198>/Constant3'
       *  Gain: '<S198>/Gain'
       *  Product: '<S198>/Divide'
       *  RelationalOperator: '<S198>/Relational Operator2'
       *  Sum: '<S198>/Add'
       *  Sum: '<S198>/Subtract2'
       *  Sum: '<S198>/Subtract3'
       */
      if (rtb_Subtract_g > rtb_Switch_ge_idx_0_o) {
        rtb_Switch_ge_idx_0_o /= rtb_Subtract_g;
        rtb_Switch_ge_idx_1_o = ((rtb_Gain1_lm - rtb_Switch_ge_idx_1_o) +
          (rtb_Saturation1_p_idx_0_o - rtb_Saturation1_p_idx_1_o)) * 0.5F;
      } else {
        rtb_Switch_ge_idx_0_o = 1.0F;

        /* Switch: '<S198>/Switch2' incorporates:
         *  Constant: '<S198>/Constant3'
         *  RelationalOperator: '<S198>/Relational Operator3'
         *  Sum: '<S198>/Subtract4'
         *  Sum: '<S198>/Subtract5'
         */
        if (rtb_Switch_ge_idx_1_o > rtb_Gain1_lm) {
          rtb_Switch_ge_idx_1_o = rtb_Gain1_lm - rtb_Switch_ge_idx_1_o;
        } else {
          rtb_Switch_ge_idx_1_o = rtb_Saturation1_p_idx_0_o -
            rtb_Saturation1_p_idx_1_o;
        }

        /* End of Switch: '<S198>/Switch2' */
      }

      /* End of Switch: '<S198>/Switch1' */
    } else {
      rtb_Switch_ge_idx_0_o = 1.0F;
      rtb_Switch_ge_idx_1_o = 0.0F;
    }

    /* End of Switch: '<S198>/Switch' */

    /* Sum: '<S192>/Sum1' */
    rtb_Saturation3_c += rtb_Switch_ge_idx_1_o;

    /* Saturate: '<S192>/Saturation3' */
    if (rtb_Saturation3_c > 1.0F) {
      rtb_Saturation3_c = 1.0F;
    } else {
      if (rtb_Saturation3_c < 0.0F) {
        rtb_Saturation3_c = 0.0F;
      }
    }

    /* End of Saturate: '<S192>/Saturation3' */

    /* Sum: '<S192>/Sum2' incorporates:
     *  Product: '<S192>/Multiply1'
     */
    rtb_Switch_ge_idx_1_o = rtb_floating_yaw_n[0] * rtb_Switch_ge_idx_0_o +
      rtb_Saturation3_c;

    /* Saturate: '<S192>/Saturation4' */
    if (rtb_Switch_ge_idx_1_o > 1.0F) {
      rtb_Switch_ge_idx_1_o = 1.0F;
    } else {
      if (rtb_Switch_ge_idx_1_o < 0.0F) {
        rtb_Switch_ge_idx_1_o = 0.0F;
      }
    }

    /* Sum: '<S192>/Sum3' incorporates:
     *  Product: '<S192>/Multiply2'
     */
    rtb_Sum_m[0] = Controller_ConstB.VTOL2.r_column[0] *
      rtb_Saturation1_p_idx_2_o + rtb_Switch_ge_idx_1_o;

    /* Product: '<S192>/Multiply1' */
    rtb_floating_yaw_n[0] = rtb_Switch_ge_idx_1_o;

    /* Sum: '<S192>/Sum2' incorporates:
     *  Product: '<S192>/Multiply1'
     */
    rtb_Switch_ge_idx_1_o = rtb_floating_yaw_n[1] * rtb_Switch_ge_idx_0_o +
      rtb_Saturation3_c;

    /* Saturate: '<S192>/Saturation4' */
    if (rtb_Switch_ge_idx_1_o > 1.0F) {
      rtb_Switch_ge_idx_1_o = 1.0F;
    } else {
      if (rtb_Switch_ge_idx_1_o < 0.0F) {
        rtb_Switch_ge_idx_1_o = 0.0F;
      }
    }

    /* Sum: '<S192>/Sum3' incorporates:
     *  Product: '<S192>/Multiply2'
     */
    rtb_Sum_m[1] = Controller_ConstB.VTOL2.r_column[1] *
      rtb_Saturation1_p_idx_2_o + rtb_Switch_ge_idx_1_o;

    /* Product: '<S192>/Multiply1' */
    rtb_floating_yaw_n[1] = rtb_Switch_ge_idx_1_o;

    /* Sum: '<S192>/Sum2' incorporates:
     *  Product: '<S192>/Multiply1'
     */
    rtb_Switch_ge_idx_1_o = rtb_floating_yaw_n[2] * rtb_Switch_ge_idx_0_o +
      rtb_Saturation3_c;

    /* Saturate: '<S192>/Saturation4' */
    if (rtb_Switch_ge_idx_1_o > 1.0F) {
      rtb_Switch_ge_idx_1_o = 1.0F;
    } else {
      if (rtb_Switch_ge_idx_1_o < 0.0F) {
        rtb_Switch_ge_idx_1_o = 0.0F;
      }
    }

    /* Sum: '<S192>/Sum3' incorporates:
     *  Product: '<S192>/Multiply2'
     */
    rtb_Sum_m[2] = Controller_ConstB.VTOL2.r_column[2] *
      rtb_Saturation1_p_idx_2_o + rtb_Switch_ge_idx_1_o;

    /* Product: '<S192>/Multiply1' */
    rtb_floating_yaw_n[2] = rtb_Switch_ge_idx_1_o;

    /* Sum: '<S192>/Sum2' incorporates:
     *  Product: '<S192>/Multiply1'
     */
    rtb_Switch_ge_idx_1_o = rtb_floating_yaw_n[3] * rtb_Switch_ge_idx_0_o +
      rtb_Saturation3_c;

    /* Saturate: '<S192>/Saturation4' */
    if (rtb_Switch_ge_idx_1_o > 1.0F) {
      rtb_Switch_ge_idx_1_o = 1.0F;
    } else {
      if (rtb_Switch_ge_idx_1_o < 0.0F) {
        rtb_Switch_ge_idx_1_o = 0.0F;
      }
    }

    /* Sum: '<S192>/Sum3' incorporates:
     *  Product: '<S192>/Multiply2'
     */
    rtb_Sum_m[3] = Controller_ConstB.VTOL2.r_column[3] *
      rtb_Saturation1_p_idx_2_o + rtb_Switch_ge_idx_1_o;

    /* Product: '<S192>/Multiply1' */
    rtb_floating_yaw_n[3] = rtb_Switch_ge_idx_1_o;

    /* MATLAB Function: '<S192>/R_Remix' */
    Controller_R_Remix(rtb_Sum_m, rtb_Gain1_lm, rtb_Saturation1_p_idx_0_o,
                       rtb_floating_yaw_n);

    /* MultiPortSwitch: '<S194>/Multiport Switch' incorporates:
     *  Constant: '<S195>/Constant1'
     *  Constant: '<S195>/Constant11'
     *  Constant: '<S195>/Constant12'
     *  Constant: '<S195>/Constant2'
     *  Constant: '<S195>/Constant7'
     *  Constant: '<S195>/Constant8'
     *  DataTypeConversion: '<S201>/Data Type Conversion'
     *  DataTypeConversion: '<S202>/Data Type Conversion'
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
        /* Saturate: '<S202>/Saturation' incorporates:
         *  Constant: '<S202>/Disarm'
         *  Reshape: '<S202>/Reshape'
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

      /* Saturate: '<S202>/Saturation' incorporates:
       *  Bias: '<S202>/Bias'
       *  Constant: '<S202>/Constant'
       *  DataTypeConversion: '<S202>/Data Type Conversion'
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

      /* Saturate: '<S202>/Saturation' incorporates:
       *  Bias: '<S202>/Bias1'
       *  Constant: '<S202>/Constant'
       *  DataTypeConversion: '<S202>/Data Type Conversion'
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

      /* Saturate: '<S202>/Saturation' incorporates:
       *  Bias: '<S202>/Bias2'
       *  Constant: '<S202>/Constant'
       *  DataTypeConversion: '<S202>/Data Type Conversion'
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

      /* Saturate: '<S202>/Saturation' incorporates:
       *  Bias: '<S202>/Bias3'
       *  Constant: '<S202>/Constant'
       *  DataTypeConversion: '<S202>/Data Type Conversion'
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

      /* SignalConversion: '<S195>/ConcatBufferAtVector Concatenate2In2' incorporates:
       *  Constant: '<S195>/Constant10'
       *  Constant: '<S195>/Constant11'
       *  Constant: '<S195>/Constant12'
       */
      rtb_MatrixConcatenate_g[9] = 0.0F;

      /* SignalConversion: '<S195>/ConcatBufferAtVector Concatenate2In1' incorporates:
       *  Constant: '<S195>/Constant9'
       */
      rtb_MatrixConcatenate_g[8] = 0.0F;
      rtb_MatrixConcatenate_g[7] = -CONTROL_PARAM.FW_PITCH_EFFC *
        CONTROL_PARAM.FW_TAIL2_DIR;
      rtb_MatrixConcatenate_g[6] = CONTROL_PARAM.FW_PITCH_EFFC *
        CONTROL_PARAM.FW_TAIL1_DIR;

      /* SignalConversion: '<S195>/ConcatBufferAtVector Concatenate1In2' incorporates:
       *  Constant: '<S195>/Constant6'
       *  Constant: '<S195>/Constant7'
       *  Constant: '<S195>/Constant8'
       */
      rtb_MatrixConcatenate_g[5] = 0.0F;

      /* SignalConversion: '<S195>/ConcatBufferAtVector Concatenate1In1' incorporates:
       *  Constant: '<S195>/Constant5'
       */
      rtb_MatrixConcatenate_g[4] = 0.0F;

      /* SignalConversion: '<S195>/ConcatBufferAtVector ConcatenateIn4' incorporates:
       *  Constant: '<S195>/Constant4'
       */
      rtb_MatrixConcatenate_g[3] = 0.0F;

      /* SignalConversion: '<S195>/ConcatBufferAtVector ConcatenateIn3' incorporates:
       *  Constant: '<S195>/Constant3'
       */
      rtb_MatrixConcatenate_g[2] = 0.0F;
      rtb_MatrixConcatenate_g[1] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON2_DIR;
      rtb_MatrixConcatenate_g[0] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON1_DIR;

      /* Saturate: '<S191>/Saturation5' incorporates:
       *  Constant: '<S195>/Constant1'
       *  Constant: '<S195>/Constant2'
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

      /* End of Saturate: '<S191>/Saturation5' */
      for (i_o = 0; i_o < 4; i_o++) {
        /* Bias: '<S191>/Bias' incorporates:
         *  Gain: '<S191>/Gain1'
         *  Product: '<S191>/Multiply1'
         */
        rtb_Saturation5_m[i_o] = 500.0F * (rtb_MatrixConcatenate_g[i_o + 8] *
          rtb_Saturation3_c + (rtb_MatrixConcatenate_g[i_o + 4] * rtb_Gain1_lm +
          rtb_MatrixConcatenate_g[i_o] * rtb_Saturation1_p_idx_2_o)) + 1500.0F;

        /* Sum: '<S192>/Sum4' */
        rtb_Saturation1_p_idx_0_o = rtb_Sum_m[i_o] + rtb_floating_yaw_n[i_o];

        /* Saturate: '<S192>/Saturation5' */
        if (rtb_Saturation1_p_idx_0_o > 1.0F) {
          rtb_Saturation1_p_idx_0_o = 1.0F;
        } else {
          if (rtb_Saturation1_p_idx_0_o < 0.0F) {
            rtb_Saturation1_p_idx_0_o = 0.0F;
          }
        }

        /* End of Saturate: '<S192>/Saturation5' */

        /* DataTypeConversion: '<S192>/Data Type Conversion' incorporates:
         *  Constant: '<S192>/Constant2'
         *  Gain: '<S192>/Gain3'
         *  Sum: '<S192>/Sum5'
         */
        u0_o = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          rtb_Saturation1_p_idx_0_o), 4.2949673E+9F) + 1000U);

        /* Saturate: '<S192>/Saturation' */
        if (u0_o > CONTROL_PARAM.MC_OUT_MAX) {
          rtb_VariantMergeForOutportactua[i_o] = CONTROL_PARAM.MC_OUT_MAX;
        } else if (u0_o < CONTROL_PARAM.MC_OUT_MIN) {
          rtb_VariantMergeForOutportactua[i_o] = CONTROL_PARAM.MC_OUT_MIN;
        } else {
          rtb_VariantMergeForOutportactua[i_o] = u0_o;
        }

        /* End of Saturate: '<S192>/Saturation' */
      }

      /* Saturate: '<S191>/Saturation4' */
      if (rtb_Multiply1[0] > 1.0F) {
        rtb_Saturation1_p_idx_2_o = 1.0F;
      } else if (rtb_Multiply1[0] < 0.0F) {
        rtb_Saturation1_p_idx_2_o = 0.0F;
      } else {
        rtb_Saturation1_p_idx_2_o = rtb_Multiply1[0];
      }

      /* End of Saturate: '<S191>/Saturation4' */

      /* DataTypeConversion: '<S197>/Data Type Conversion' incorporates:
       *  Constant: '<S197>/Constant1'
       *  Gain: '<S197>/Gain1'
       *  Sum: '<S197>/Sum1'
       */
      u0_o = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
        rtb_Saturation1_p_idx_2_o), 4.2949673E+9F) + 1000U);

      /* Saturate: '<S191>/Saturation1' */
      if (u0_o > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[4] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_o < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[4] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[4] = u0_o;
      }

      /* DataTypeConversion: '<S191>/Data Type Conversion' incorporates:
       *  Bias: '<S191>/Bias1'
       */
      rtb_Saturation1_p_idx_2_o = fmodf(floorf(rtb_Saturation5_m[0] +
        CONTROL_PARAM.SERVO1_BIAS), 65536.0F);
      u0_o = (uint16_T)(rtb_Saturation1_p_idx_2_o < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_p_idx_2_o :
                        (int32_T)(uint16_T)rtb_Saturation1_p_idx_2_o);

      /* Saturate: '<S191>/Saturation1' */
      if (u0_o > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[5] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_o < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[5] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[5] = u0_o;
      }

      /* DataTypeConversion: '<S191>/Data Type Conversion1' incorporates:
       *  Bias: '<S191>/Bias2'
       */
      rtb_Saturation1_p_idx_2_o = fmodf(floorf(rtb_Saturation5_m[1] +
        CONTROL_PARAM.SERVO2_BIAS), 65536.0F);
      u0_o = (uint16_T)(rtb_Saturation1_p_idx_2_o < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_p_idx_2_o :
                        (int32_T)(uint16_T)rtb_Saturation1_p_idx_2_o);

      /* Saturate: '<S191>/Saturation1' */
      if (u0_o > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[6] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_o < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[6] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[6] = u0_o;
      }

      /* DataTypeConversion: '<S191>/Data Type Conversion2' incorporates:
       *  Bias: '<S191>/Bias3'
       */
      rtb_Saturation1_p_idx_2_o = fmodf(floorf(rtb_Saturation5_m[2] +
        CONTROL_PARAM.SERVO3_BIAS), 65536.0F);
      u0_o = (uint16_T)(rtb_Saturation1_p_idx_2_o < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_p_idx_2_o :
                        (int32_T)(uint16_T)rtb_Saturation1_p_idx_2_o);

      /* Saturate: '<S191>/Saturation1' */
      if (u0_o > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[7] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_o < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[7] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[7] = u0_o;
      }

      /* DataTypeConversion: '<S191>/Data Type Conversion3' incorporates:
       *  Bias: '<S191>/Bias4'
       */
      rtb_Saturation1_p_idx_2_o = fmodf(floorf(rtb_Saturation5_m[3] +
        CONTROL_PARAM.SERVO4_BIAS), 65536.0F);
      u0_o = (uint16_T)(rtb_Saturation1_p_idx_2_o < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_p_idx_2_o :
                        (int32_T)(uint16_T)rtb_Saturation1_p_idx_2_o);

      /* Saturate: '<S191>/Saturation1' */
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

    /* End of MultiPortSwitch: '<S194>/Multiport Switch' */
  }

#endif

  /* End of Outputs for SubSystem: '<S8>/VTOL_Control_Allocation' */

  /* Outport: '<Root>/Control_Out' incorporates:
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   *  Reshape: '<S171>/Reshape'
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

  /* Update for DiscreteIntegrator: '<S10>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S10>/Gain'
   *  Sum: '<S10>/Sum5'
   */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;
  Controller_DW.DiscreteTimeIntegrator5_DSTATE += ((real32_T)
    rtb_MultiportSwitch_idx_1 - Controller_DW.DiscreteTimeIntegrator5_DSTATE) *
    6.28318548F * 0.002F;

  /* Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S9>/Gain'
   *  Sum: '<S9>/Sum5'
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
  /* Start for Constant: '<S166>/Constant' */
  Controller_B.Constant = CONTROL_PARAM.MC_VEL_Z_I_MIN;

  /* End of Start for SubSystem: '<S2>/MC_Controller' */

  /* InitializeConditions for DiscreteIntegrator: '<S10>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S9>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_o = 1U;

  /* SystemInitialize for Enabled SubSystem: '<S2>/FW_Controller' */
  /* InitializeConditions for DiscreteIntegrator: '<S91>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_i = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S70>/Integrator1' */
  Controller_DW.Integrator1_DSTATE_c = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S88>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_n = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S83>/ ' */
  Controller_DW._DSTATE = Controller_ConstB.Zero1;
  if (Controller_DW._DSTATE >= CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
    Controller_DW._DSTATE = CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
  } else {
    if (Controller_DW._DSTATE <= -CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
      Controller_DW._DSTATE = -CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
    }
  }

  Controller_DW._PrevResetState = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S83>/ ' */

  /* InitializeConditions for DiscreteIntegrator: '<S84>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_f = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_b = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S59>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S59>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S86>/ ' */
  Controller_DW._DSTATE_d = Controller_ConstB.Zero;
  if (Controller_DW._DSTATE_d >= 1.0F) {
    Controller_DW._DSTATE_d = 1.0F;
  } else {
    if (Controller_DW._DSTATE_d <= 0.0F) {
      Controller_DW._DSTATE_d = 0.0F;
    }
  }

  Controller_DW._PrevResetState_e = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S86>/ ' */

  /* InitializeConditions for DiscreteIntegrator: '<S87>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_h = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_d = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S70>/Integrator' */
  Controller_DW.Integrator_DSTATE_n = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S2>/FW_Controller' */

  /* SystemInitialize for Enabled SubSystem: '<S2>/MC_Controller' */
  /* InitializeConditions for DiscreteIntegrator: '<S124>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S124>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S149>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_PrevRe_p = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S151>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S121>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_c = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S126>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_k = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S144>/Integrator1' */
  Controller_DW.Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S149>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S144>/Integrator' */
  Controller_DW.Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S144>/Integrator1' */
  Controller_DW.Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S149>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S144>/Integrator' */
  Controller_DW.Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S163>/Integrator1' */
  Controller_DW.Integrator1_DSTATE_e = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S166>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S166>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S168>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 1U;
  Controller_DW.DiscreteTimeIntegrator1_Prev_ks = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S163>/Integrator' */
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
