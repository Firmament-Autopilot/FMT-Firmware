/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.824
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Sep 30 15:14:14 2025
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
struct_PwkgbKxZIDCjZ9tSDIOmy CONTROL_PARAM = {
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
                                        *   '<S14>/Saturation'
                                        *   '<S15>/balabnce_ratio2'
                                        *   '<S15>/balance_ratio'
                                        *   '<S15>/pitch_ff'
                                        *   '<S15>/thorttle_ff'
                                        *   '<S15>/ucmd2pitch'
                                        *   '<S15>/ucmd2thor'
                                        *   '<S15>/wcmd2pitch'
                                        *   '<S15>/wcmd2thor'
                                        *   '<S130>/hover_throttle'
                                        *   '<S17>/FF'
                                        *   '<S38>/P_control'
                                        *   '<S39>/Gain'
                                        *   '<S39>/Gain1'
                                        *   '<S39>/P_control'
                                        *   '<S40>/Kv'
                                        *   '<S110>/Saturation'
                                        *   '<S146>/Bias1'
                                        *   '<S146>/Bias2'
                                        *   '<S146>/Bias3'
                                        *   '<S146>/Bias4'
                                        *   '<S146>/Saturation1'
                                        *   '<S147>/Constant'
                                        *   '<S147>/Constant1'
                                        *   '<S147>/Saturation'
                                        *   '<S162>/Bias1'
                                        *   '<S162>/Bias2'
                                        *   '<S162>/Bias3'
                                        *   '<S162>/Bias4'
                                        *   '<S162>/Saturation1'
                                        *   '<S163>/Constant'
                                        *   '<S163>/Constant1'
                                        *   '<S163>/Saturation'
                                        *   '<S21>/trim_speed'
                                        *   '<S22>/trim_speed'
                                        *   '<S26>/Saturation'
                                        *   '<S55>/Gain'
                                        *   '<S56>/ '
                                        *   '<S56>/Gain3'
                                        *   '<S78>/Saturation'
                                        *   '<S78>/Saturation1'
                                        *   '<S78>/Saturation2'
                                        *   '<S121>/kd'
                                        *   '<S121>/Saturation'
                                        *   '<S122>/ki'
                                        *   '<S122>/Discrete-Time Integrator'
                                        *   '<S123>/kp'
                                        *   '<S138>/kd'
                                        *   '<S138>/Saturation'
                                        *   '<S139>/Constant'
                                        *   '<S139>/ki'
                                        *   '<S139>/Discrete-Time Integrator'
                                        *   '<S140>/kp'
                                        *   '<S151>/Constant1'
                                        *   '<S151>/Constant12'
                                        *   '<S151>/Constant2'
                                        *   '<S151>/Constant7'
                                        *   '<S160>/Bias'
                                        *   '<S160>/Bias1'
                                        *   '<S160>/Bias2'
                                        *   '<S160>/Bias3'
                                        *   '<S161>/Bias'
                                        *   '<S161>/Bias1'
                                        *   '<S161>/Bias2'
                                        *   '<S161>/Bias3'
                                        *   '<S166>/Constant1'
                                        *   '<S166>/Constant11'
                                        *   '<S166>/Constant12'
                                        *   '<S166>/Constant2'
                                        *   '<S166>/Constant7'
                                        *   '<S166>/Constant8'
                                        *   '<S172>/Bias'
                                        *   '<S172>/Bias1'
                                        *   '<S172>/Bias2'
                                        *   '<S172>/Bias3'
                                        *   '<S173>/Bias'
                                        *   '<S173>/Bias1'
                                        *   '<S173>/Bias2'
                                        *   '<S173>/Bias3'
                                        *   '<S23>/gain1'
                                        *   '<S23>/gain2'
                                        *   '<S23>/gain3'
                                        *   '<S23>/Discrete-Time Integrator'
                                        *   '<S24>/gain1'
                                        *   '<S24>/gain2'
                                        *   '<S24>/gain3'
                                        *   '<S28>/Pitch Offset'
                                        *   '<S28>/Saturation'
                                        *   '<S29>/Constant1'
                                        *   '<S29>/Constant2'
                                        *   '<S91>/Gain'
                                        *   '<S91>/Gain1'
                                        *   '<S103>/Constant1'
                                        *   '<S103>/Constant2'
                                        *   '<S96>/gain1'
                                        *   '<S96>/gain2'
                                        *   '<S96>/gain3'
                                        *   '<S96>/Saturation'
                                        *   '<S97>/gain1'
                                        *   '<S97>/gain2'
                                        *   '<S97>/gain3'
                                        *   '<S97>/Discrete-Time Integrator'
                                        *   '<S98>/gain1'
                                        *   '<S98>/gain2'
                                        *   '<S98>/gain3'
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
 *    '<S147>/R_Remix'
 *    '<S163>/R_Remix'
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
  real32_T rtb_TmpSignalConversionAtMultip[3];
  real32_T rtb_Saturation1;
  real32_T rtb_DiscreteTimeIntegrator1_n4;
  boolean_T rtb_Compare;
  real32_T rtb_Gain_az;
  real32_T rtb_VdotPg;
  real32_T rtb_Saturation_e;
  real32_T rtb_fw_rate_err_B[3];
  boolean_T rtb_Compare_i;
  real32_T rtb_Sign5_f;
  real32_T rtb_MatrixConcatenate1[9];
  real32_T rtb_Multiply_ni[3];
  real32_T rtb_Sum;
  real32_T rtb_Add_k;
  real32_T rtb_Add1_j4;
  real32_T rtb_Add2_h;
  int32_T i;
  real32_T rtb_MatrixConcatenate1_0[3];
  int32_T rtb_MultiportSwitch_idx_0;
  int32_T rtb_MultiportSwitch_idx_1;
  real32_T rtb_Divide_m_idx_0;
  real32_T rtb_Divide_m_idx_1;
  real32_T rtb_Divide_m_idx_2;
  real32_T rtb_Divide_m_idx_3;
  real32_T u;
  uint32_T tmp;

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

  /* DiscreteIntegrator: '<S9>/Discrete-Time Integrator5' */
  if (Controller_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    Controller_DW.DiscreteTimeIntegrator5_DSTATE = (real32_T)
      rtb_MultiportSwitch_idx_1;
  }

  /* Relay: '<S2>/Relay' incorporates:
   *  DiscreteIntegrator: '<S9>/Discrete-Time Integrator5'
   */
  if (Controller_DW.DiscreteTimeIntegrator5_DSTATE >= 0.3F) {
    Controller_DW.Relay_Mode = true;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator5_DSTATE <= 0.1F) {
      Controller_DW.Relay_Mode = false;
    }
  }

  /* DiscreteIntegrator: '<S8>/Discrete-Time Integrator5' */
  if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_o != 0) {
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_k = (real32_T)
      rtb_MultiportSwitch_idx_0;
  }

  /* Relay: '<S2>/Relay1' incorporates:
   *  DiscreteIntegrator: '<S8>/Discrete-Time Integrator5'
   */
  if (Controller_DW.DiscreteTimeIntegrator5_DSTAT_k >= 0.3F) {
    Controller_DW.Relay1_Mode = true;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator5_DSTAT_k <= 0.1F) {
      Controller_DW.Relay1_Mode = false;
    }
  }

  /* Outputs for Enabled SubSystem: '<S2>/FW_Controller' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  if (Controller_DW.Relay1_Mode) {
    if (!Controller_DW.FW_Controller_MODE) {
      /* InitializeConditions for DiscreteIntegrator: '<S64>/Discrete-Time Integrator5' */
      Controller_DW.DiscreteTimeIntegrator5_IC_LO_i = 1U;

      /* InitializeConditions for DiscreteIntegrator: '<S34>/Integrator1' */
      Controller_DW.Integrator1_DSTATE_c = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S36>/Integrator1' */
      Controller_DW.Integrator1_DSTATE_j = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S23>/Discrete-Time Integrator' */
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

      /* End of InitializeConditions for DiscreteIntegrator: '<S23>/Discrete-Time Integrator' */

      /* InitializeConditions for DiscreteIntegrator: '<S39>/ ' */
      Controller_DW._DSTATE = 0.25F;

      /* InitializeConditions for DiscreteIntegrator: '<S60>/Discrete-Time Integrator1' */
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_n = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevR_d = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S59>/Discrete-Time Integrator1' */
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_h = 1U;
      Controller_DW.DiscreteTimeIntegrator1_Prev_dx = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S56>/ ' */
      Controller_DW._DSTATE_h = Controller_ConstB.Zero1;
      if (Controller_DW._DSTATE_h >= CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
        Controller_DW._DSTATE_h = CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
      } else {
        if (Controller_DW._DSTATE_h <= -CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
          Controller_DW._DSTATE_h = -CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
        }
      }

      Controller_DW._PrevResetState = 0;

      /* End of InitializeConditions for DiscreteIntegrator: '<S56>/ ' */

      /* InitializeConditions for DiscreteIntegrator: '<S57>/Discrete-Time Integrator1' */
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_f = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevR_b = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S36>/Integrator' */
      Controller_DW.Integrator_DSTATE_d = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S34>/Integrator' */
      Controller_DW.Integrator_DSTATE_n = 0.0F;
      Controller_DW.FW_Controller_MODE = true;
    }

    /* SignalConversion: '<S43>/TmpSignal ConversionAtMultiplyInport2' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_TmpSignalConversionAtMultip[0] = Controller_U.INS_Out.vn;
    rtb_TmpSignalConversionAtMultip[1] = Controller_U.INS_Out.ve;
    rtb_TmpSignalConversionAtMultip[2] = Controller_U.INS_Out.vd;

    /* Switch: '<S12>/Switch' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  S-Function (sfix_bitop): '<S12>/airspeed_valid'
     */
    if ((Controller_U.INS_Out.flag & 512U) > 0U) {
      rtb_Divide_m_idx_2 = Controller_U.INS_Out.airspeed;
    } else {
      /* Sqrt: '<S71>/Sqrt' incorporates:
       *  Math: '<S71>/Square'
       *  Sum: '<S71>/Sum of Elements'
       */
      rtb_Saturation1 = sqrtf(((Controller_U.INS_Out.quat[0] *
        Controller_U.INS_Out.quat[0] + Controller_U.INS_Out.quat[1] *
        Controller_U.INS_Out.quat[1]) + Controller_U.INS_Out.quat[2] *
        Controller_U.INS_Out.quat[2]) + Controller_U.INS_Out.quat[3] *
        Controller_U.INS_Out.quat[3]);

      /* Product: '<S67>/Divide' incorporates:
       *  Sqrt: '<S71>/Sqrt'
       */
      rtb_Divide_m_idx_0 = Controller_U.INS_Out.quat[0] / rtb_Saturation1;
      rtb_Divide_m_idx_1 = Controller_U.INS_Out.quat[1] / rtb_Saturation1;
      rtb_Divide_m_idx_2 = Controller_U.INS_Out.quat[2] / rtb_Saturation1;
      rtb_Divide_m_idx_3 = Controller_U.INS_Out.quat[3] / rtb_Saturation1;

      /* Math: '<S70>/Square' incorporates:
       *  Math: '<S68>/Square'
       *  Math: '<S69>/Square'
       */
      rtb_Gain_az = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_0;

      /* Math: '<S70>/Square2' incorporates:
       *  Math: '<S68>/Square2'
       *  Math: '<S69>/Square2'
       */
      rtb_Saturation_e = rtb_Divide_m_idx_2 * rtb_Divide_m_idx_2;

      /* Math: '<S70>/Square1' incorporates:
       *  Math: '<S68>/Square1'
       *  Math: '<S69>/Square1'
       */
      rtb_Saturation1 = rtb_Divide_m_idx_1 * rtb_Divide_m_idx_1;

      /* Math: '<S70>/Square3' incorporates:
       *  Math: '<S68>/Square3'
       *  Math: '<S69>/Square3'
       */
      rtb_Add_k = rtb_Divide_m_idx_3 * rtb_Divide_m_idx_3;

      /* Sum: '<S70>/Subtract' incorporates:
       *  Math: '<S70>/Square'
       *  Math: '<S70>/Square1'
       *  Math: '<S70>/Square2'
       *  Math: '<S70>/Square3'
       *  Sum: '<S70>/Add'
       *  Sum: '<S70>/Add1'
       */
      rtb_MatrixConcatenate1[8] = (rtb_Gain_az + rtb_Add_k) - (rtb_Saturation1 +
        rtb_Saturation_e);

      /* Product: '<S70>/Multiply2' incorporates:
       *  Product: '<S69>/Multiply2'
       */
      rtb_Add1_j4 = rtb_Divide_m_idx_2 * rtb_Divide_m_idx_3;

      /* Product: '<S70>/Multiply3' incorporates:
       *  Product: '<S69>/Multiply3'
       */
      rtb_Add2_h = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_1;

      /* Gain: '<S70>/Gain1' incorporates:
       *  Product: '<S70>/Multiply2'
       *  Product: '<S70>/Multiply3'
       *  Sum: '<S70>/Add2'
       */
      rtb_MatrixConcatenate1[7] = (rtb_Add1_j4 + rtb_Add2_h) * 2.0F;

      /* Product: '<S70>/Multiply' incorporates:
       *  Product: '<S68>/Multiply2'
       */
      rtb_DiscreteTimeIntegrator1_n4 = rtb_Divide_m_idx_1 * rtb_Divide_m_idx_3;

      /* Product: '<S70>/Multiply1' incorporates:
       *  Product: '<S68>/Multiply3'
       */
      rtb_VdotPg = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_2;

      /* Gain: '<S70>/Gain' incorporates:
       *  Product: '<S70>/Multiply'
       *  Product: '<S70>/Multiply1'
       *  Sum: '<S70>/Subtract2'
       */
      rtb_MatrixConcatenate1[6] = (rtb_DiscreteTimeIntegrator1_n4 - rtb_VdotPg) *
        2.0F;

      /* Gain: '<S69>/Gain1' incorporates:
       *  Sum: '<S69>/Subtract1'
       */
      rtb_MatrixConcatenate1[5] = (rtb_Add1_j4 - rtb_Add2_h) * 2.0F;

      /* Sum: '<S69>/Subtract' incorporates:
       *  Sum: '<S69>/Add'
       *  Sum: '<S69>/Add1'
       */
      rtb_MatrixConcatenate1[4] = (rtb_Gain_az + rtb_Saturation_e) -
        (rtb_Saturation1 + rtb_Add_k);

      /* Product: '<S69>/Multiply' incorporates:
       *  Product: '<S68>/Multiply'
       */
      rtb_Add1_j4 = rtb_Divide_m_idx_1 * rtb_Divide_m_idx_2;

      /* Product: '<S69>/Multiply1' incorporates:
       *  Product: '<S68>/Multiply1'
       */
      rtb_Add2_h = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_3;

      /* Gain: '<S69>/Gain' incorporates:
       *  Product: '<S69>/Multiply'
       *  Product: '<S69>/Multiply1'
       *  Sum: '<S69>/Add3'
       */
      rtb_MatrixConcatenate1[3] = (rtb_Add1_j4 + rtb_Add2_h) * 2.0F;

      /* Gain: '<S68>/Gain1' incorporates:
       *  Sum: '<S68>/Add2'
       */
      rtb_MatrixConcatenate1[2] = (rtb_DiscreteTimeIntegrator1_n4 + rtb_VdotPg) *
        2.0F;

      /* Gain: '<S68>/Gain' incorporates:
       *  Sum: '<S68>/Subtract1'
       */
      rtb_MatrixConcatenate1[1] = (rtb_Add1_j4 - rtb_Add2_h) * 2.0F;

      /* Sum: '<S68>/Subtract' incorporates:
       *  Sum: '<S68>/Add'
       *  Sum: '<S68>/Add1'
       */
      rtb_MatrixConcatenate1[0] = (rtb_Gain_az + rtb_Saturation1) -
        (rtb_Saturation_e + rtb_Add_k);

      /* Product: '<S65>/Multiply' */
      for (i = 0; i < 3; i++) {
        rtb_MatrixConcatenate1_0[i] = rtb_MatrixConcatenate1[i + 6] *
          rtb_TmpSignalConversionAtMultip[2] + (rtb_MatrixConcatenate1[i + 3] *
          rtb_TmpSignalConversionAtMultip[1] + rtb_MatrixConcatenate1[i] *
          rtb_TmpSignalConversionAtMultip[0]);
      }

      /* End of Product: '<S65>/Multiply' */
      rtb_Divide_m_idx_2 = rtb_MatrixConcatenate1_0[0];
    }

    /* End of Switch: '<S12>/Switch' */

    /* Saturate: '<S12>/Saturation1' */
    if (rtb_Divide_m_idx_2 > 100.0F) {
      rtb_Saturation1 = 100.0F;
    } else if (rtb_Divide_m_idx_2 < 0.1F) {
      rtb_Saturation1 = 0.1F;
    } else {
      rtb_Saturation1 = rtb_Divide_m_idx_2;
    }

    /* End of Saturate: '<S12>/Saturation1' */

    /* DiscreteIntegrator: '<S64>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_i != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j = rtb_Saturation1;
    }

    /* Switch: '<S27>/Switch' incorporates:
     *  Inport: '<Root>/FMS_Out'
     *  Logic: '<S27>/Logical Operator'
     *  RelationalOperator: '<S32>/Compare'
     */
    if ((Controller_U.FMS_Out.ctrl_mode == 3) || (Controller_U.FMS_Out.ctrl_mode
         == 4)) {
      rtb_Divide_m_idx_2 = Controller_U.FMS_Out.phi_cmd;
    } else {
      /* Trigonometry: '<S14>/Atan' incorporates:
       *  DiscreteIntegrator: '<S34>/Integrator1'
       *  Gain: '<S14>/g_force'
       */
      rtb_Divide_m_idx_2 = atanf(0.101936802F *
        Controller_DW.Integrator1_DSTATE_c);

      /* Saturate: '<S14>/Saturation' */
      if (rtb_Divide_m_idx_2 > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_Divide_m_idx_2 = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_Divide_m_idx_2 < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
          rtb_Divide_m_idx_2 = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
        }
      }

      /* End of Saturate: '<S14>/Saturation' */
    }

    /* End of Switch: '<S27>/Switch' */

    /* Switch: '<S27>/Switch1' incorporates:
     *  Constant: '<S33>/Constant'
     *  DiscreteIntegrator: '<S36>/Integrator1'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S33>/Compare'
     */
    if (Controller_U.FMS_Out.ctrl_mode == 3) {
      rtb_Divide_m_idx_1 = Controller_U.FMS_Out.theta_cmd;
    } else {
      rtb_Divide_m_idx_1 = Controller_DW.Integrator1_DSTATE_j;
    }

    /* End of Switch: '<S27>/Switch1' */

    /* Saturate: '<S28>/Saturation' */
    if (rtb_Divide_m_idx_2 > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Divide_m_idx_0 = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else if (rtb_Divide_m_idx_2 < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Divide_m_idx_0 = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      rtb_Divide_m_idx_0 = rtb_Divide_m_idx_2;
    }

    /* Reshape: '<S18>/Reshape' incorporates:
     *  Constant: '<S29>/Constant1'
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S29>/Multiply'
     *  Sum: '<S28>/Sum'
     */
    Controller_B.Reshape[0] = (rtb_Divide_m_idx_0 - Controller_U.INS_Out.phi) *
      CONTROL_PARAM.FW_ROLL_P;

    /* Bias: '<S28>/Pitch Offset' */
    rtb_Divide_m_idx_0 = rtb_Divide_m_idx_1 + CONTROL_PARAM.FW_PITCH_OFFSET;

    /* Saturate: '<S28>/Saturation' */
    if (rtb_Divide_m_idx_0 > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Divide_m_idx_0 = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_Divide_m_idx_0 < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_Divide_m_idx_0 = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      }
    }

    /* Reshape: '<S18>/Reshape' incorporates:
     *  Constant: '<S29>/Constant2'
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S29>/Multiply'
     *  Sum: '<S28>/Sum'
     */
    Controller_B.Reshape[1] = (rtb_Divide_m_idx_0 - Controller_U.INS_Out.theta) *
      CONTROL_PARAM.FW_PITCH_P;

    /* Product: '<S31>/Divide' incorporates:
     *  Constant: '<S31>/Constant'
     *  DiscreteIntegrator: '<S64>/Discrete-Time Integrator5'
     */
    rtb_Divide_m_idx_0 = 9.81F / Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;

    /* Saturate: '<S31>/Saturation' */
    if (rtb_Divide_m_idx_0 > 1.0F) {
      rtb_Divide_m_idx_0 = 1.0F;
    } else {
      if (rtb_Divide_m_idx_0 < 0.2F) {
        rtb_Divide_m_idx_0 = 0.2F;
      }
    }

    /* End of Saturate: '<S31>/Saturation' */

    /* Sum: '<S26>/Sum' incorporates:
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S31>/Multiply'
     *  Product: '<S31>/Multiply1'
     *  Trigonometry: '<S31>/Cos'
     *  Trigonometry: '<S31>/Tan'
     */
    rtb_Divide_m_idx_0 = tanf(rtb_Divide_m_idx_2) * arm_cos_f32
      (rtb_Divide_m_idx_1) * rtb_Divide_m_idx_0 +
      Controller_U.FMS_Out.psi_rate_cmd;

    /* Saturate: '<S26>/Saturation' */
    if (rtb_Divide_m_idx_0 > CONTROL_PARAM.FW_YAWRATE_LIM) {
      /* Reshape: '<S18>/Reshape' */
      Controller_B.Reshape[2] = CONTROL_PARAM.FW_YAWRATE_LIM;
    } else if (rtb_Divide_m_idx_0 < -CONTROL_PARAM.FW_YAWRATE_LIM) {
      /* Reshape: '<S18>/Reshape' */
      Controller_B.Reshape[2] = -CONTROL_PARAM.FW_YAWRATE_LIM;
    } else {
      /* Reshape: '<S18>/Reshape' */
      Controller_B.Reshape[2] = rtb_Divide_m_idx_0;
    }

    /* End of Saturate: '<S26>/Saturation' */

    /* Sum: '<S19>/Add' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S19>/Multiply'
     *  Trigonometry: '<S19>/Sin1'
     */
    rtb_Add_k = Controller_B.Reshape[0] - arm_sin_f32(Controller_U.INS_Out.theta)
      * Controller_B.Reshape[2];

    /* Trigonometry: '<S19>/Sin' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_m_idx_0 = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S19>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_m_idx_1 = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Trigonometry: '<S19>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Add2_h = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Sum: '<S19>/Add1' incorporates:
     *  Product: '<S19>/Multiply1'
     *  Product: '<S19>/Multiply3'
     *  Trigonometry: '<S19>/Cos'
     *  Trigonometry: '<S19>/Cos1'
     *  Trigonometry: '<S19>/Sin'
     */
    rtb_Add1_j4 = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_1 *
      Controller_B.Reshape[2] + rtb_Add2_h * Controller_B.Reshape[1];

    /* Sum: '<S19>/Add2' incorporates:
     *  Product: '<S19>/Multiply4'
     *  Product: '<S19>/Multiply5'
     *  Trigonometry: '<S19>/Cos'
     *  Trigonometry: '<S19>/Cos1'
     *  Trigonometry: '<S19>/Sin'
     */
    rtb_Add2_h = rtb_Add2_h * rtb_Divide_m_idx_1 * Controller_B.Reshape[2] -
      rtb_Divide_m_idx_0 * Controller_B.Reshape[1];

    /* Sum: '<S17>/Minus2' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_fw_rate_err_B[0] = rtb_Add_k - Controller_U.INS_Out.p;
    rtb_fw_rate_err_B[1] = rtb_Add1_j4 - Controller_U.INS_Out.q;
    rtb_fw_rate_err_B[2] = rtb_Add2_h - Controller_U.INS_Out.r;

    /* DiscreteIntegrator: '<S23>/Discrete-Time Integrator' incorporates:
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

    /* RelationalOperator: '<S58>/Compare' incorporates:
     *  Constant: '<S58>/Constant'
     *  Inport: '<Root>/FMS_Out'
     */
    rtb_Compare = (Controller_U.FMS_Out.ext_state == 1);

    /* S-Function (sfix_bitop): '<S43>/Bitwise AND' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  S-Function (sfix_bitop): '<S44>/Bitwise AND'
     */
    tmp = Controller_U.INS_Out.flag & 16U;

    /* Switch: '<S43>/Switch' incorporates:
     *  Constant: '<S44>/Constant'
     *  Inport: '<Root>/INS_Out'
     *  S-Function (sfix_bitop): '<S43>/Bitwise AND'
     *  Switch: '<S44>/Switch'
     */
    if (tmp > 0U) {
      /* Sqrt: '<S51>/Sqrt' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Math: '<S51>/Square'
       *  Sum: '<S51>/Sum of Elements'
       */
      rtb_Gain_az = sqrtf(((Controller_U.INS_Out.quat[0] *
                            Controller_U.INS_Out.quat[0] +
                            Controller_U.INS_Out.quat[1] *
                            Controller_U.INS_Out.quat[1]) +
                           Controller_U.INS_Out.quat[2] *
                           Controller_U.INS_Out.quat[2]) +
                          Controller_U.INS_Out.quat[3] *
                          Controller_U.INS_Out.quat[3]);

      /* Product: '<S47>/Divide' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Sqrt: '<S51>/Sqrt'
       */
      rtb_Divide_m_idx_0 = Controller_U.INS_Out.quat[0] / rtb_Gain_az;
      rtb_Divide_m_idx_1 = Controller_U.INS_Out.quat[1] / rtb_Gain_az;
      rtb_Divide_m_idx_2 = Controller_U.INS_Out.quat[2] / rtb_Gain_az;
      rtb_Divide_m_idx_3 = Controller_U.INS_Out.quat[3] / rtb_Gain_az;

      /* Sum: '<S50>/Subtract' incorporates:
       *  Math: '<S50>/Square'
       *  Math: '<S50>/Square1'
       *  Math: '<S50>/Square2'
       *  Math: '<S50>/Square3'
       *  Sum: '<S50>/Add'
       *  Sum: '<S50>/Add1'
       */
      rtb_MatrixConcatenate1[8] = (rtb_Divide_m_idx_0 * rtb_Divide_m_idx_0 +
        rtb_Divide_m_idx_3 * rtb_Divide_m_idx_3) - (rtb_Divide_m_idx_1 *
        rtb_Divide_m_idx_1 + rtb_Divide_m_idx_2 * rtb_Divide_m_idx_2);

      /* Gain: '<S50>/Gain1' incorporates:
       *  Product: '<S50>/Multiply2'
       *  Product: '<S50>/Multiply3'
       *  Sum: '<S50>/Add2'
       */
      rtb_MatrixConcatenate1[7] = (rtb_Divide_m_idx_2 * rtb_Divide_m_idx_3 +
        rtb_Divide_m_idx_0 * rtb_Divide_m_idx_1) * 2.0F;

      /* Gain: '<S50>/Gain' incorporates:
       *  Product: '<S50>/Multiply'
       *  Product: '<S50>/Multiply1'
       *  Sum: '<S50>/Subtract2'
       */
      rtb_MatrixConcatenate1[6] = (rtb_Divide_m_idx_1 * rtb_Divide_m_idx_3 -
        rtb_Divide_m_idx_0 * rtb_Divide_m_idx_2) * 2.0F;

      /* Gain: '<S49>/Gain1' incorporates:
       *  Product: '<S49>/Multiply2'
       *  Product: '<S49>/Multiply3'
       *  Sum: '<S49>/Subtract1'
       */
      rtb_MatrixConcatenate1[5] = (rtb_Divide_m_idx_2 * rtb_Divide_m_idx_3 -
        rtb_Divide_m_idx_0 * rtb_Divide_m_idx_1) * 2.0F;

      /* Sum: '<S49>/Subtract' incorporates:
       *  Math: '<S49>/Square'
       *  Math: '<S49>/Square1'
       *  Math: '<S49>/Square2'
       *  Math: '<S49>/Square3'
       *  Sum: '<S49>/Add'
       *  Sum: '<S49>/Add1'
       */
      rtb_MatrixConcatenate1[4] = (rtb_Divide_m_idx_0 * rtb_Divide_m_idx_0 +
        rtb_Divide_m_idx_2 * rtb_Divide_m_idx_2) - (rtb_Divide_m_idx_1 *
        rtb_Divide_m_idx_1 + rtb_Divide_m_idx_3 * rtb_Divide_m_idx_3);

      /* Gain: '<S49>/Gain' incorporates:
       *  Product: '<S49>/Multiply'
       *  Product: '<S49>/Multiply1'
       *  Sum: '<S49>/Add3'
       */
      rtb_MatrixConcatenate1[3] = (rtb_Divide_m_idx_1 * rtb_Divide_m_idx_2 +
        rtb_Divide_m_idx_0 * rtb_Divide_m_idx_3) * 2.0F;

      /* Gain: '<S48>/Gain1' incorporates:
       *  Product: '<S48>/Multiply2'
       *  Product: '<S48>/Multiply3'
       *  Sum: '<S48>/Add2'
       */
      rtb_MatrixConcatenate1[2] = (rtb_Divide_m_idx_1 * rtb_Divide_m_idx_3 +
        rtb_Divide_m_idx_0 * rtb_Divide_m_idx_2) * 2.0F;

      /* Gain: '<S48>/Gain' incorporates:
       *  Product: '<S48>/Multiply'
       *  Product: '<S48>/Multiply1'
       *  Sum: '<S48>/Subtract1'
       */
      rtb_MatrixConcatenate1[1] = (rtb_Divide_m_idx_1 * rtb_Divide_m_idx_2 -
        rtb_Divide_m_idx_0 * rtb_Divide_m_idx_3) * 2.0F;

      /* Sum: '<S48>/Subtract' incorporates:
       *  Math: '<S48>/Square'
       *  Math: '<S48>/Square1'
       *  Math: '<S48>/Square2'
       *  Math: '<S48>/Square3'
       *  Sum: '<S48>/Add'
       *  Sum: '<S48>/Add1'
       */
      rtb_MatrixConcatenate1[0] = (rtb_Divide_m_idx_0 * rtb_Divide_m_idx_0 +
        rtb_Divide_m_idx_1 * rtb_Divide_m_idx_1) - (rtb_Divide_m_idx_2 *
        rtb_Divide_m_idx_2 + rtb_Divide_m_idx_3 * rtb_Divide_m_idx_3);

      /* Product: '<S43>/Multiply' */
      for (i = 0; i < 3; i++) {
        rtb_MatrixConcatenate1_0[i] = rtb_MatrixConcatenate1[i + 6] *
          rtb_TmpSignalConversionAtMultip[2] + (rtb_MatrixConcatenate1[i + 3] *
          rtb_TmpSignalConversionAtMultip[1] + rtb_MatrixConcatenate1[i] *
          rtb_TmpSignalConversionAtMultip[0]);
      }

      /* End of Product: '<S43>/Multiply' */
      rtb_Divide_m_idx_2 = rtb_MatrixConcatenate1_0[0];

      /* SignalConversion: '<S53>/ConcatBufferAtVector ConcatenateIn3' */
      rtb_MatrixConcatenate1[6] = Controller_ConstB.VectorConcatenate3_g[0];
      rtb_MatrixConcatenate1[7] = Controller_ConstB.VectorConcatenate3_g[1];
      rtb_MatrixConcatenate1[8] = Controller_ConstB.VectorConcatenate3_g[2];

      /* SignalConversion: '<S53>/ConcatBufferAtVector Concatenate2In3' incorporates:
       *  Constant: '<S53>/Constant4'
       */
      rtb_MatrixConcatenate1[5] = 0.0F;

      /* Trigonometry: '<S53>/Trigonometric Function3' incorporates:
       *  Gain: '<S52>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S53>/Trigonometric Function1'
       */
      rtb_Gain_az = arm_cos_f32(-Controller_U.INS_Out.psi);
      rtb_MatrixConcatenate1[4] = rtb_Gain_az;

      /* Trigonometry: '<S53>/Trigonometric Function2' incorporates:
       *  Gain: '<S52>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S53>/Trigonometric Function'
       */
      rtb_Saturation_e = arm_sin_f32(-Controller_U.INS_Out.psi);

      /* Gain: '<S53>/Gain' incorporates:
       *  Trigonometry: '<S53>/Trigonometric Function2'
       */
      rtb_MatrixConcatenate1[3] = -rtb_Saturation_e;

      /* SignalConversion: '<S53>/ConcatBufferAtVector Concatenate1In3' incorporates:
       *  Constant: '<S53>/Constant3'
       */
      rtb_MatrixConcatenate1[2] = 0.0F;

      /* Trigonometry: '<S53>/Trigonometric Function' */
      rtb_MatrixConcatenate1[1] = rtb_Saturation_e;

      /* Trigonometry: '<S53>/Trigonometric Function1' */
      rtb_MatrixConcatenate1[0] = rtb_Gain_az;

      /* Product: '<S44>/Multiply' */
      for (i = 0; i < 3; i++) {
        rtb_Multiply_ni[i] = rtb_MatrixConcatenate1[i + 6] *
          rtb_TmpSignalConversionAtMultip[2] + (rtb_MatrixConcatenate1[i + 3] *
          rtb_TmpSignalConversionAtMultip[1] + rtb_MatrixConcatenate1[i] *
          rtb_TmpSignalConversionAtMultip[0]);
      }

      /* End of Product: '<S44>/Multiply' */

      /* DeadZone: '<S44>/Dead Zone' */
      if (rtb_Multiply_ni[0] > 1.0F) {
        rtb_DiscreteTimeIntegrator1_n4 = rtb_Multiply_ni[0] - 1.0F;
      } else if (rtb_Multiply_ni[0] >= -1.0F) {
        rtb_DiscreteTimeIntegrator1_n4 = 0.0F;
      } else {
        rtb_DiscreteTimeIntegrator1_n4 = rtb_Multiply_ni[0] - -1.0F;
      }

      /* End of DeadZone: '<S44>/Dead Zone' */

      /* Signum: '<S44>/Sign' */
      if (rtb_DiscreteTimeIntegrator1_n4 < 0.0F) {
        rtb_DiscreteTimeIntegrator1_n4 = -1.0F;
      } else {
        if (rtb_DiscreteTimeIntegrator1_n4 > 0.0F) {
          rtb_DiscreteTimeIntegrator1_n4 = 1.0F;
        }
      }

      /* End of Signum: '<S44>/Sign' */
    } else {
      rtb_Divide_m_idx_2 = Controller_U.INS_Out.airspeed;
      rtb_DiscreteTimeIntegrator1_n4 = 1.0F;
    }

    /* End of Switch: '<S43>/Switch' */

    /* Saturate: '<S43>/Saturation' */
    if (rtb_Divide_m_idx_2 > 100.0F) {
      rtb_Divide_m_idx_2 = 100.0F;
    } else {
      if (rtb_Divide_m_idx_2 < 8.0F) {
        rtb_Divide_m_idx_2 = 8.0F;
      }
    }

    /* End of Saturate: '<S43>/Saturation' */

    /* Product: '<S45>/Multiply1' incorporates:
     *  Gain: '<S45>/Gain'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S45>/Divide'
     *  Trigonometry: '<S45>/Asin'
     */
    rtb_Divide_m_idx_0 = atanf(-Controller_U.FMS_Out.w_cmd / rtb_Divide_m_idx_2)
      * rtb_DiscreteTimeIntegrator1_n4;

    /* DeadZone: '<S42>/Dead Zone' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    if (Controller_U.INS_Out.vd > 0.1F) {
      rtb_Divide_m_idx_1 = Controller_U.INS_Out.vd - 0.1F;
    } else if (Controller_U.INS_Out.vd >= -0.1F) {
      rtb_Divide_m_idx_1 = 0.0F;
    } else {
      rtb_Divide_m_idx_1 = Controller_U.INS_Out.vd - -0.1F;
    }

    /* End of DeadZone: '<S42>/Dead Zone' */

    /* Product: '<S42>/Multiply1' incorporates:
     *  Gain: '<S42>/Gain'
     *  Product: '<S42>/Divide'
     *  Trigonometry: '<S42>/Asin'
     */
    rtb_DiscreteTimeIntegrator1_n4 *= atanf(1.0F / rtb_Divide_m_idx_2 *
      -rtb_Divide_m_idx_1);

    /* Saturate: '<S42>/Saturation1' */
    if (rtb_DiscreteTimeIntegrator1_n4 > 0.785398185F) {
      rtb_DiscreteTimeIntegrator1_n4 = 0.785398185F;
    } else {
      if (rtb_DiscreteTimeIntegrator1_n4 < -0.785398185F) {
        rtb_DiscreteTimeIntegrator1_n4 = -0.785398185F;
      }
    }

    /* End of Saturate: '<S42>/Saturation1' */

    /* Saturate: '<S45>/Saturation2' */
    if (rtb_Divide_m_idx_0 > 0.785398185F) {
      rtb_Divide_m_idx_0 = 0.785398185F;
    } else {
      if (rtb_Divide_m_idx_0 < -0.785398185F) {
        rtb_Divide_m_idx_0 = -0.785398185F;
      }
    }

    /* End of Saturate: '<S45>/Saturation2' */

    /* Sum: '<S37>/Sum' */
    rtb_Divide_m_idx_1 = rtb_Divide_m_idx_0 - rtb_DiscreteTimeIntegrator1_n4;

    /* DiscreteIntegrator: '<S60>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S64>/Discrete-Time Integrator5'
     */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_n != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_h =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;
    }

    if (Controller_DW.DiscreteTimeIntegrator1_PrevR_d != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_h =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;
    }

    /* Gain: '<S60>/Gain' incorporates:
     *  DiscreteIntegrator: '<S60>/Discrete-Time Integrator1'
     *  DiscreteIntegrator: '<S64>/Discrete-Time Integrator5'
     *  Sum: '<S60>/Sum5'
     */
    rtb_Gain_az = (Controller_DW.DiscreteTimeIntegrator5_DSTAT_j -
                   Controller_DW.DiscreteTimeIntegrator1_DSTAT_h) * 12.566371F;

    /* Gain: '<S40>/Gain1' */
    rtb_VdotPg = 0.101936802F * rtb_Gain_az;

    /* Sum: '<S40>/Sum' incorporates:
     *  DiscreteIntegrator: '<S64>/Discrete-Time Integrator5'
     *  Gain: '<S40>/Gain'
     *  Gain: '<S40>/Kv'
     *  Inport: '<Root>/FMS_Out'
     *  Sum: '<S40>/Minus'
     */
    rtb_Divide_m_idx_2 = (Controller_U.FMS_Out.u_cmd -
                          Controller_DW.DiscreteTimeIntegrator5_DSTAT_j) *
      CONTROL_PARAM.FW_TECS_VEL_P * 0.101936802F - rtb_VdotPg;

    /* Sum: '<S15>/Add' incorporates:
     *  Gain: '<S15>/ucmd2thor'
     *  Gain: '<S15>/wcmd2thor'
     */
    rtb_Saturation_e = CONTROL_PARAM.FW_TECS_W2T * rtb_Divide_m_idx_1 +
      CONTROL_PARAM.FW_TECS_U2T * rtb_Divide_m_idx_2;

    /* Saturate: '<S15>/Saturation' */
    if (rtb_Saturation_e > 0.5F) {
      rtb_Saturation_e = 0.5F;
    } else {
      if (rtb_Saturation_e < -0.5F) {
        rtb_Saturation_e = -0.5F;
      }
    }

    /* End of Saturate: '<S15>/Saturation' */

    /* DiscreteIntegrator: '<S59>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_h != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm = rtb_Saturation_e;
    }

    if (rtb_Compare || (Controller_DW.DiscreteTimeIntegrator1_Prev_dx != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm = rtb_Saturation_e;
    }

    /* Gain: '<S59>/Gain' incorporates:
     *  DiscreteIntegrator: '<S59>/Discrete-Time Integrator1'
     *  Sum: '<S59>/Sum5'
     */
    rtb_Divide_m_idx_3 = (rtb_Saturation_e -
                          Controller_DW.DiscreteTimeIntegrator1_DSTA_nm) *
      188.49556F;

    /* Switch: '<S11>/Switch' incorporates:
     *  Constant: '<S11>/Constant2'
     *  Constant: '<S16>/Constant'
     *  Constant: '<S63>/Constant'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S63>/Compare'
     *  Saturate: '<S16>/Saturation2'
     */
    if (Controller_U.FMS_Out.ctrl_mode == 1) {
      Controller_B.Switch[0] = Controller_U.FMS_Out.p_cmd;
      Controller_B.Switch[1] = Controller_U.FMS_Out.q_cmd;
      Controller_B.Switch[2] = Controller_U.FMS_Out.r_cmd;
      Controller_B.Switch[3] = Controller_U.FMS_Out.u_cmd;
      Controller_B.Switch[4] = 0.0F;
      Controller_B.Switch[5] = 0.0F;
    } else {
      /* Product: '<S21>/Divide' incorporates:
       *  Constant: '<S21>/trim_speed'
       *  DiscreteIntegrator: '<S64>/Discrete-Time Integrator5'
       *  Math: '<S21>/Square'
       *  Math: '<S21>/Square1'
       */
      rtb_Sum = CONTROL_PARAM.FW_AIRSPEED_TRIM * CONTROL_PARAM.FW_AIRSPEED_TRIM /
        (Controller_DW.DiscreteTimeIntegrator5_DSTAT_j *
         Controller_DW.DiscreteTimeIntegrator5_DSTAT_j);

      /* Saturate: '<S21>/Saturation' */
      if (rtb_Sum > 1.0F) {
        rtb_Sum = 1.0F;
      } else {
        if (rtb_Sum < 0.0F) {
          rtb_Sum = 0.0F;
        }
      }

      /* End of Saturate: '<S21>/Saturation' */

      /* Product: '<S17>/Multiply' incorporates:
       *  Constant: '<S24>/gain1'
       *  DiscreteIntegrator: '<S23>/Discrete-Time Integrator'
       *  Product: '<S24>/Multiply'
       *  Sum: '<S20>/Add1'
       */
      rtb_Divide_m_idx_0 = (CONTROL_PARAM.FW_ROLL_RATE_P * rtb_fw_rate_err_B[0]
                            + Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0]) *
        rtb_Sum;

      /* Saturate: '<S17>/PI_limit' */
      if (rtb_Divide_m_idx_0 > 1.0F) {
        rtb_TmpSignalConversionAtMultip[0] = 1.0F;
      } else if (rtb_Divide_m_idx_0 < -1.0F) {
        rtb_TmpSignalConversionAtMultip[0] = -1.0F;
      } else {
        rtb_TmpSignalConversionAtMultip[0] = rtb_Divide_m_idx_0;
      }

      /* Product: '<S17>/Multiply' incorporates:
       *  Constant: '<S24>/gain2'
       *  DiscreteIntegrator: '<S23>/Discrete-Time Integrator'
       *  Product: '<S24>/Multiply'
       *  Sum: '<S20>/Add1'
       */
      rtb_Divide_m_idx_0 = (CONTROL_PARAM.FW_PITCH_RATE_P * rtb_fw_rate_err_B[1]
                            + Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1]) *
        rtb_Sum;

      /* Saturate: '<S17>/PI_limit' */
      if (rtb_Divide_m_idx_0 > 1.0F) {
        rtb_TmpSignalConversionAtMultip[1] = 1.0F;
      } else if (rtb_Divide_m_idx_0 < -1.0F) {
        rtb_TmpSignalConversionAtMultip[1] = -1.0F;
      } else {
        rtb_TmpSignalConversionAtMultip[1] = rtb_Divide_m_idx_0;
      }

      /* Product: '<S17>/Multiply' incorporates:
       *  Constant: '<S24>/gain3'
       *  DiscreteIntegrator: '<S23>/Discrete-Time Integrator'
       *  Product: '<S24>/Multiply'
       *  Sum: '<S20>/Add1'
       */
      rtb_Divide_m_idx_0 = (CONTROL_PARAM.FW_YAW_RATE_P * rtb_fw_rate_err_B[2] +
                            Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2]) *
        rtb_Sum;

      /* Saturate: '<S17>/PI_limit' */
      if (rtb_Divide_m_idx_0 > 1.0F) {
        rtb_TmpSignalConversionAtMultip[2] = 1.0F;
      } else if (rtb_Divide_m_idx_0 < -1.0F) {
        rtb_TmpSignalConversionAtMultip[2] = -1.0F;
      } else {
        rtb_TmpSignalConversionAtMultip[2] = rtb_Divide_m_idx_0;
      }

      /* Product: '<S22>/Divide' incorporates:
       *  Constant: '<S22>/trim_speed'
       *  DiscreteIntegrator: '<S64>/Discrete-Time Integrator5'
       */
      rtb_Sum = CONTROL_PARAM.FW_AIRSPEED_TRIM /
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;

      /* Saturate: '<S22>/Saturation' */
      if (rtb_Sum > 1.0F) {
        rtb_Sum = 1.0F;
      } else {
        if (rtb_Sum < 0.0F) {
          rtb_Sum = 0.0F;
        }
      }

      /* End of Saturate: '<S22>/Saturation' */

      /* Product: '<S17>/Multiply1' incorporates:
       *  Gain: '<S17>/FF'
       */
      rtb_Divide_m_idx_0 = CONTROL_PARAM.FW_FF * rtb_Add_k * rtb_Sum;
      rtb_Add_k = CONTROL_PARAM.FW_FF * rtb_Add1_j4 * rtb_Sum;
      rtb_Add1_j4 = CONTROL_PARAM.FW_FF * rtb_Add2_h * rtb_Sum;

      /* Switch: '<S16>/Switch' incorporates:
       *  Bias: '<S16>/Bias'
       *  Constant: '<S62>/Constant'
       *  Gain: '<S16>/Gain'
       *  RelationalOperator: '<S62>/Compare'
       *  Switch: '<S39>/Switch'
       */
      if (Controller_U.FMS_Out.ctrl_mode <= 3) {
        rtb_Sum = 0.000999987125F * (real32_T)Controller_U.FMS_Out.throttle_cmd
          + -1.0F;
      } else {
        if (rtb_Compare) {
          /* Switch: '<S39>/Switch' incorporates:
           *  Constant: '<S39>/Constant'
           */
          rtb_Sum = 0.0F;
        } else {
          /* Gain: '<S39>/Gain1' incorporates:
           *  Switch: '<S39>/Switch'
           *  Switch: '<S59>/Switch'
           */
          rtb_Add2_h = CONTROL_PARAM.FW_TECS_THOR_D * rtb_Divide_m_idx_3;

          /* Saturate: '<S39>/Saturation1' incorporates:
           *  Switch: '<S39>/Switch'
           */
          if (rtb_Add2_h > 0.3F) {
            rtb_Add2_h = 0.3F;
          } else {
            if (rtb_Add2_h < -0.3F) {
              rtb_Add2_h = -0.3F;
            }
          }

          /* End of Saturate: '<S39>/Saturation1' */

          /* Switch: '<S39>/Switch' incorporates:
           *  Gain: '<S15>/thorttle_ff'
           *  Gain: '<S39>/P_control'
           *  Sum: '<S15>/Add1'
           *  Sum: '<S39>/Add4'
           */
          rtb_Sum = (CONTROL_PARAM.FW_TECS_THOR_P * rtb_Saturation_e +
                     rtb_Add2_h) + (rtb_DiscreteTimeIntegrator1_n4 + rtb_VdotPg)
            * CONTROL_PARAM.FW_TECS_THOR_FF;
        }

        /* Sum: '<S39>/Sum' incorporates:
         *  DiscreteIntegrator: '<S39>/ '
         */
        rtb_Sum += Controller_DW._DSTATE;

        /* Saturate: '<S16>/Saturation' */
        if (rtb_Sum > 1.0F) {
          rtb_Sum = 1.0F;
        } else {
          if (rtb_Sum < -1.0F) {
            rtb_Sum = -1.0F;
          }
        }

        /* End of Saturate: '<S16>/Saturation' */
      }

      /* End of Switch: '<S16>/Switch' */

      /* Saturate: '<S17>/FF_limit' */
      if (rtb_Divide_m_idx_0 > 0.3F) {
        rtb_Divide_m_idx_0 = 0.3F;
      } else {
        if (rtb_Divide_m_idx_0 < -0.3F) {
          rtb_Divide_m_idx_0 = -0.3F;
        }
      }

      /* Saturate: '<S17>/Saturation1' incorporates:
       *  Sum: '<S17>/Add'
       */
      rtb_Divide_m_idx_0 += rtb_TmpSignalConversionAtMultip[0];
      if (rtb_Divide_m_idx_0 > 1.0F) {
        Controller_B.Switch[0] = 1.0F;
      } else if (rtb_Divide_m_idx_0 < -1.0F) {
        Controller_B.Switch[0] = -1.0F;
      } else {
        Controller_B.Switch[0] = rtb_Divide_m_idx_0;
      }

      /* Saturate: '<S17>/FF_limit' */
      if (rtb_Add_k > 0.3F) {
        rtb_Add_k = 0.3F;
      } else {
        if (rtb_Add_k < -0.3F) {
          rtb_Add_k = -0.3F;
        }
      }

      /* Saturate: '<S17>/Saturation1' incorporates:
       *  Sum: '<S17>/Add'
       */
      rtb_Divide_m_idx_0 = rtb_Add_k + rtb_TmpSignalConversionAtMultip[1];
      if (rtb_Divide_m_idx_0 > 1.0F) {
        Controller_B.Switch[1] = 1.0F;
      } else if (rtb_Divide_m_idx_0 < -1.0F) {
        Controller_B.Switch[1] = -1.0F;
      } else {
        Controller_B.Switch[1] = rtb_Divide_m_idx_0;
      }

      /* Saturate: '<S17>/FF_limit' */
      if (rtb_Add1_j4 > 0.3F) {
        rtb_Add1_j4 = 0.3F;
      } else {
        if (rtb_Add1_j4 < -0.3F) {
          rtb_Add1_j4 = -0.3F;
        }
      }

      /* Saturate: '<S17>/Saturation1' incorporates:
       *  Sum: '<S17>/Add'
       */
      rtb_Divide_m_idx_0 = rtb_Add1_j4 + rtb_TmpSignalConversionAtMultip[2];
      if (rtb_Divide_m_idx_0 > 1.0F) {
        Controller_B.Switch[2] = 1.0F;
      } else if (rtb_Divide_m_idx_0 < -1.0F) {
        Controller_B.Switch[2] = -1.0F;
      } else {
        Controller_B.Switch[2] = rtb_Divide_m_idx_0;
      }

      /* Saturate: '<S16>/Saturation2' */
      if (rtb_Sum > 1.0F) {
        Controller_B.Switch[3] = 1.0F;
      } else {
        Controller_B.Switch[3] = rtb_Sum;
      }

      Controller_B.Switch[4] = 0.0F;
      Controller_B.Switch[5] = 0.0F;
    }

    /* End of Switch: '<S11>/Switch' */

    /* Product: '<S5>/Multiply' */
    Controller_B.Multiply_c[0] = Controller_B.Switch[0] *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_k;
    Controller_B.Multiply_c[1] = Controller_B.Switch[1] *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_k;
    Controller_B.Multiply_c[2] = Controller_B.Switch[2] *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_k;

    /* Sum: '<S15>/Minus1' incorporates:
     *  Gain: '<S15>/ucmd2pitch'
     *  Gain: '<S15>/wcmd2pitch'
     */
    rtb_Add_k = CONTROL_PARAM.FW_TECS_W2P * rtb_Divide_m_idx_1 -
      CONTROL_PARAM.FW_TECS_U2P * rtb_Divide_m_idx_2;

    /* RelationalOperator: '<S54>/Compare' incorporates:
     *  Constant: '<S54>/Constant'
     *  Inport: '<Root>/FMS_Out'
     */
    rtb_Compare_i = (Controller_U.FMS_Out.ext_state == 1);

    /* DiscreteIntegrator: '<S56>/ ' */
    if (rtb_Compare_i || (Controller_DW._PrevResetState != 0)) {
      Controller_DW._DSTATE_h = Controller_ConstB.Zero1;
      if (Controller_DW._DSTATE_h >= CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
        Controller_DW._DSTATE_h = CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
      } else {
        if (Controller_DW._DSTATE_h <= -CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
          Controller_DW._DSTATE_h = -CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
        }
      }
    }

    if (Controller_DW._DSTATE_h >= CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
      Controller_DW._DSTATE_h = CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
    } else {
      if (Controller_DW._DSTATE_h <= -CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
        Controller_DW._DSTATE_h = -CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
      }
    }

    /* DiscreteIntegrator: '<S57>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_f != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_e = rtb_Add_k;
    }

    if (rtb_Compare_i || (Controller_DW.DiscreteTimeIntegrator1_PrevR_b != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_e = rtb_Add_k;
    }

    /* Gain: '<S57>/Gain' incorporates:
     *  DiscreteIntegrator: '<S57>/Discrete-Time Integrator1'
     *  Sum: '<S57>/Sum5'
     */
    rtb_Add1_j4 = (rtb_Add_k - Controller_DW.DiscreteTimeIntegrator1_DSTAT_e) *
      62.831852F;

    /* Switch: '<S38>/Switch' incorporates:
     *  Constant: '<S38>/Constant'
     *  DiscreteIntegrator: '<S56>/ '
     *  Gain: '<S15>/balabnce_ratio2'
     *  Gain: '<S15>/balance_ratio'
     *  Gain: '<S15>/pitch_ff'
     *  Gain: '<S38>/P_control'
     *  Sum: '<S15>/Minus'
     *  Sum: '<S38>/Add'
     */
    if (rtb_Compare_i) {
      rtb_Divide_m_idx_1 = 0.0F;
    } else {
      /* Gain: '<S55>/Gain' incorporates:
       *  Switch: '<S57>/Switch'
       */
      rtb_Divide_m_idx_0 = CONTROL_PARAM.FW_TECS_PITCH_D * rtb_Add1_j4;

      /* Saturate: '<S38>/Saturation1' */
      if (rtb_Divide_m_idx_0 > 0.3F) {
        rtb_Divide_m_idx_0 = 0.3F;
      } else {
        if (rtb_Divide_m_idx_0 < -0.3F) {
          rtb_Divide_m_idx_0 = -0.3F;
        }
      }

      /* End of Saturate: '<S38>/Saturation1' */
      rtb_Divide_m_idx_1 = ((2.0F - CONTROL_PARAM.FW_TECS_RATIO) *
                            rtb_DiscreteTimeIntegrator1_n4 -
                            CONTROL_PARAM.FW_TECS_RATIO * rtb_VdotPg) *
        CONTROL_PARAM.FW_TECS_PITCH_F + ((CONTROL_PARAM.FW_TECS_PITCH_P *
        rtb_Add_k + Controller_DW._DSTATE_h) + rtb_Divide_m_idx_0);
    }

    /* End of Switch: '<S38>/Switch' */

    /* Sum: '<S36>/Subtract' incorporates:
     *  DiscreteIntegrator: '<S36>/Integrator1'
     */
    rtb_Divide_m_idx_0 = Controller_DW.Integrator1_DSTATE_j - rtb_Divide_m_idx_1;

    /* Product: '<S41>/Multiply1' incorporates:
     *  Constant: '<S41>/const1'
     *  DiscreteIntegrator: '<S36>/Integrator'
     */
    rtb_Divide_m_idx_1 = Controller_DW.Integrator_DSTATE_d * 0.04F;

    /* Sum: '<S41>/Add' */
    rtb_Add2_h = rtb_Divide_m_idx_0 + rtb_Divide_m_idx_1;

    /* Signum: '<S41>/Sign' */
    if (rtb_Add2_h < 0.0F) {
      rtb_Divide_m_idx_0 = -1.0F;
    } else if (rtb_Add2_h > 0.0F) {
      rtb_Divide_m_idx_0 = 1.0F;
    } else {
      rtb_Divide_m_idx_0 = rtb_Add2_h;
    }

    /* End of Signum: '<S41>/Sign' */

    /* Sum: '<S41>/Add2' incorporates:
     *  Abs: '<S41>/Abs'
     *  Gain: '<S41>/Gain'
     *  Gain: '<S41>/Gain1'
     *  Product: '<S41>/Multiply2'
     *  Product: '<S41>/Multiply3'
     *  Sqrt: '<S41>/Sqrt'
     *  Sum: '<S41>/Add1'
     *  Sum: '<S41>/Subtract'
     */
    rtb_DiscreteTimeIntegrator1_n4 = (sqrtf((8.0F * fabsf(rtb_Add2_h) +
      Controller_ConstB.d_f) * Controller_ConstB.d_f) - Controller_ConstB.d_f) *
      0.5F * rtb_Divide_m_idx_0 + rtb_Divide_m_idx_1;

    /* Sum: '<S41>/Add4' */
    rtb_Divide_m_idx_0 = (rtb_Add2_h - rtb_DiscreteTimeIntegrator1_n4) +
      rtb_Divide_m_idx_1;

    /* Sum: '<S41>/Add3' */
    rtb_Divide_m_idx_2 = rtb_Add2_h + Controller_ConstB.d_f;

    /* Sum: '<S41>/Subtract1' */
    rtb_Add2_h -= Controller_ConstB.d_f;

    /* Signum: '<S41>/Sign1' */
    if (rtb_Divide_m_idx_2 < 0.0F) {
      rtb_Divide_m_idx_2 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_2 > 0.0F) {
        rtb_Divide_m_idx_2 = 1.0F;
      }
    }

    /* End of Signum: '<S41>/Sign1' */

    /* Signum: '<S41>/Sign2' */
    if (rtb_Add2_h < 0.0F) {
      rtb_Add2_h = -1.0F;
    } else {
      if (rtb_Add2_h > 0.0F) {
        rtb_Add2_h = 1.0F;
      }
    }

    /* End of Signum: '<S41>/Sign2' */

    /* Sum: '<S41>/Add5' incorporates:
     *  Gain: '<S41>/Gain2'
     *  Product: '<S41>/Multiply4'
     *  Sum: '<S41>/Subtract2'
     */
    rtb_DiscreteTimeIntegrator1_n4 += (rtb_Divide_m_idx_2 - rtb_Add2_h) * 0.5F *
      rtb_Divide_m_idx_0;

    /* Sum: '<S41>/Subtract3' */
    rtb_Divide_m_idx_2 = rtb_DiscreteTimeIntegrator1_n4 - Controller_ConstB.d_f;

    /* Sum: '<S41>/Add6' */
    rtb_Divide_m_idx_0 = rtb_DiscreteTimeIntegrator1_n4 + Controller_ConstB.d_f;

    /* Product: '<S41>/Divide' */
    rtb_Sum = rtb_DiscreteTimeIntegrator1_n4 / Controller_ConstB.d_f;

    /* Signum: '<S41>/Sign5' incorporates:
     *  Signum: '<S41>/Sign6'
     */
    if (rtb_DiscreteTimeIntegrator1_n4 < 0.0F) {
      rtb_Sign5_f = -1.0F;

      /* Signum: '<S41>/Sign6' */
      rtb_VdotPg = -1.0F;
    } else if (rtb_DiscreteTimeIntegrator1_n4 > 0.0F) {
      rtb_Sign5_f = 1.0F;

      /* Signum: '<S41>/Sign6' */
      rtb_VdotPg = 1.0F;
    } else {
      rtb_Sign5_f = rtb_DiscreteTimeIntegrator1_n4;

      /* Signum: '<S41>/Sign6' */
      rtb_VdotPg = rtb_DiscreteTimeIntegrator1_n4;
    }

    /* End of Signum: '<S41>/Sign5' */

    /* Product: '<S35>/Multiply1' incorporates:
     *  Constant: '<S35>/const1'
     *  DiscreteIntegrator: '<S34>/Integrator'
     */
    rtb_Divide_m_idx_1 = Controller_DW.Integrator_DSTATE_n * 0.05F;

    /* Sum: '<S35>/Add' incorporates:
     *  DiscreteIntegrator: '<S34>/Integrator1'
     *  Inport: '<Root>/FMS_Out'
     *  Sum: '<S34>/Subtract'
     */
    rtb_DiscreteTimeIntegrator1_n4 = (Controller_DW.Integrator1_DSTATE_c -
      Controller_U.FMS_Out.ay_cmd) + rtb_Divide_m_idx_1;

    /* Signum: '<S35>/Sign' */
    if (rtb_DiscreteTimeIntegrator1_n4 < 0.0F) {
      rtb_Add2_h = -1.0F;
    } else if (rtb_DiscreteTimeIntegrator1_n4 > 0.0F) {
      rtb_Add2_h = 1.0F;
    } else {
      rtb_Add2_h = rtb_DiscreteTimeIntegrator1_n4;
    }

    /* End of Signum: '<S35>/Sign' */

    /* Sum: '<S35>/Add2' incorporates:
     *  Abs: '<S35>/Abs'
     *  Gain: '<S35>/Gain'
     *  Gain: '<S35>/Gain1'
     *  Product: '<S35>/Multiply2'
     *  Product: '<S35>/Multiply3'
     *  Sqrt: '<S35>/Sqrt'
     *  Sum: '<S35>/Add1'
     *  Sum: '<S35>/Subtract'
     */
    rtb_Add2_h = (sqrtf((8.0F * fabsf(rtb_DiscreteTimeIntegrator1_n4) +
                         Controller_ConstB.d_ih) * Controller_ConstB.d_ih) -
                  Controller_ConstB.d_ih) * 0.5F * rtb_Add2_h +
      rtb_Divide_m_idx_1;

    /* Sum: '<S35>/Add4' */
    rtb_Divide_m_idx_1 += rtb_DiscreteTimeIntegrator1_n4 - rtb_Add2_h;

    /* Sum: '<S35>/Add3' */
    u = rtb_DiscreteTimeIntegrator1_n4 + Controller_ConstB.d_ih;

    /* Sum: '<S35>/Subtract1' */
    rtb_DiscreteTimeIntegrator1_n4 -= Controller_ConstB.d_ih;

    /* Signum: '<S35>/Sign1' */
    if (u < 0.0F) {
      u = -1.0F;
    } else {
      if (u > 0.0F) {
        u = 1.0F;
      }
    }

    /* End of Signum: '<S35>/Sign1' */

    /* Signum: '<S35>/Sign2' */
    if (rtb_DiscreteTimeIntegrator1_n4 < 0.0F) {
      rtb_DiscreteTimeIntegrator1_n4 = -1.0F;
    } else {
      if (rtb_DiscreteTimeIntegrator1_n4 > 0.0F) {
        rtb_DiscreteTimeIntegrator1_n4 = 1.0F;
      }
    }

    /* End of Signum: '<S35>/Sign2' */

    /* Sum: '<S35>/Add5' incorporates:
     *  Gain: '<S35>/Gain2'
     *  Product: '<S35>/Multiply4'
     *  Sum: '<S35>/Subtract2'
     */
    rtb_Add2_h += (u - rtb_DiscreteTimeIntegrator1_n4) * 0.5F *
      rtb_Divide_m_idx_1;

    /* Update for DiscreteIntegrator: '<S64>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S64>/Gain'
     *  Sum: '<S64>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_i = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_j += (rtb_Saturation1 -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j) * 62.831852F * 0.002F;

    /* Update for DiscreteIntegrator: '<S34>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S34>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_c += 0.002F *
      Controller_DW.Integrator_DSTATE_n;

    /* Update for DiscreteIntegrator: '<S36>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S36>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_j += 0.002F *
      Controller_DW.Integrator_DSTATE_d;

    /* Update for DiscreteIntegrator: '<S23>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S23>/gain1'
     *  Constant: '<S23>/gain2'
     *  Constant: '<S23>/gain3'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S23>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0] +=
      CONTROL_PARAM.FW_ROLL_RATE_I * rtb_fw_rate_err_B[0] * 0.002F;
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
      CONTROL_PARAM.FW_PITCH_RATE_I * rtb_fw_rate_err_B[1] * 0.002F;
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
      CONTROL_PARAM.FW_YAW_RATE_I * rtb_fw_rate_err_B[2] * 0.002F;
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

    /* End of Update for DiscreteIntegrator: '<S23>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S39>/ ' incorporates:
     *  Gain: '<S39>/Gain'
     */
    Controller_DW._DSTATE += CONTROL_PARAM.FW_TECS_THOR_I * rtb_Saturation_e *
      0.002F;
    if (Controller_DW._DSTATE >= 1.0F) {
      Controller_DW._DSTATE = 1.0F;
    } else {
      if (Controller_DW._DSTATE <= 0.0F) {
        Controller_DW._DSTATE = 0.0F;
      }
    }

    /* End of Update for DiscreteIntegrator: '<S39>/ ' */

    /* Update for DiscreteIntegrator: '<S60>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_n = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_h += 0.002F * rtb_Gain_az;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_d = 0;

    /* Update for DiscreteIntegrator: '<S59>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_h = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTA_nm += 0.002F * rtb_Divide_m_idx_3;
    Controller_DW.DiscreteTimeIntegrator1_Prev_dx = (int8_T)rtb_Compare;

    /* Update for DiscreteIntegrator: '<S56>/ ' incorporates:
     *  Gain: '<S56>/Gain3'
     */
    Controller_DW._DSTATE_h += CONTROL_PARAM.FW_TECS_PITCH_I * rtb_Add_k *
      0.002F;
    if (Controller_DW._DSTATE_h >= CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
      Controller_DW._DSTATE_h = CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
    } else {
      if (Controller_DW._DSTATE_h <= -CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
        Controller_DW._DSTATE_h = -CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
      }
    }

    Controller_DW._PrevResetState = (int8_T)rtb_Compare_i;

    /* End of Update for DiscreteIntegrator: '<S56>/ ' */

    /* Update for DiscreteIntegrator: '<S57>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_f = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_e += 0.002F * rtb_Add1_j4;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_b = (int8_T)rtb_Compare_i;

    /* Signum: '<S41>/Sign3' */
    if (rtb_Divide_m_idx_0 < 0.0F) {
      rtb_Divide_m_idx_0 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_0 > 0.0F) {
        rtb_Divide_m_idx_0 = 1.0F;
      }
    }

    /* End of Signum: '<S41>/Sign3' */

    /* Signum: '<S41>/Sign4' */
    if (rtb_Divide_m_idx_2 < 0.0F) {
      rtb_Divide_m_idx_2 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_2 > 0.0F) {
        rtb_Divide_m_idx_2 = 1.0F;
      }
    }

    /* End of Signum: '<S41>/Sign4' */

    /* Update for DiscreteIntegrator: '<S36>/Integrator' incorporates:
     *  Constant: '<S41>/const'
     *  Gain: '<S41>/Gain3'
     *  Product: '<S41>/Multiply5'
     *  Product: '<S41>/Multiply6'
     *  Sum: '<S41>/Subtract4'
     *  Sum: '<S41>/Subtract5'
     *  Sum: '<S41>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE_d += ((rtb_Sum - rtb_Sign5_f) *
      Controller_ConstB.Gain4_n * ((rtb_Divide_m_idx_0 - rtb_Divide_m_idx_2) *
      0.5F) - rtb_VdotPg * 12.566371F) * 0.002F;

    /* Signum: '<S35>/Sign6' incorporates:
     *  Signum: '<S35>/Sign5'
     */
    if (rtb_Add2_h < 0.0F) {
      rtb_VdotPg = -1.0F;

      /* Signum: '<S35>/Sign5' */
      rtb_Divide_m_idx_1 = -1.0F;
    } else if (rtb_Add2_h > 0.0F) {
      rtb_VdotPg = 1.0F;

      /* Signum: '<S35>/Sign5' */
      rtb_Divide_m_idx_1 = 1.0F;
    } else {
      rtb_VdotPg = rtb_Add2_h;

      /* Signum: '<S35>/Sign5' */
      rtb_Divide_m_idx_1 = rtb_Add2_h;
    }

    /* End of Signum: '<S35>/Sign6' */

    /* Sum: '<S35>/Add6' */
    rtb_Divide_m_idx_2 = rtb_Add2_h + Controller_ConstB.d_ih;

    /* Sum: '<S35>/Subtract3' */
    rtb_Divide_m_idx_0 = rtb_Add2_h - Controller_ConstB.d_ih;

    /* Signum: '<S35>/Sign3' */
    if (rtb_Divide_m_idx_2 < 0.0F) {
      rtb_Divide_m_idx_2 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_2 > 0.0F) {
        rtb_Divide_m_idx_2 = 1.0F;
      }
    }

    /* End of Signum: '<S35>/Sign3' */

    /* Signum: '<S35>/Sign4' */
    if (rtb_Divide_m_idx_0 < 0.0F) {
      rtb_Divide_m_idx_0 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_0 > 0.0F) {
        rtb_Divide_m_idx_0 = 1.0F;
      }
    }

    /* End of Signum: '<S35>/Sign4' */

    /* Update for DiscreteIntegrator: '<S34>/Integrator' incorporates:
     *  Constant: '<S35>/const'
     *  Gain: '<S35>/Gain3'
     *  Product: '<S35>/Divide'
     *  Product: '<S35>/Multiply5'
     *  Product: '<S35>/Multiply6'
     *  Sum: '<S35>/Subtract4'
     *  Sum: '<S35>/Subtract5'
     *  Sum: '<S35>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE_n += ((rtb_Add2_h / Controller_ConstB.d_ih -
      rtb_Divide_m_idx_1) * Controller_ConstB.Gain4_g * ((rtb_Divide_m_idx_2 -
      rtb_Divide_m_idx_0) * 0.5F) - rtb_VdotPg * 58.836F) * 0.002F;
  } else {
    if (Controller_DW.FW_Controller_MODE) {
      Controller_DW.FW_Controller_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S2>/FW_Controller' */

  /* Outputs for Enabled SubSystem: '<S2>/MC_Controller' incorporates:
   *  EnablePort: '<S6>/Enable'
   */
  /* Relay: '<S2>/Relay' incorporates:
   *  Constant: '<S139>/Constant'
   *  Product: '<S105>/Divide1'
   *  Product: '<S121>/Multiply'
   *  Product: '<S96>/Multiply'
   *  Signum: '<S105>/Sign'
   */
  if (Controller_DW.Relay_Mode) {
    if (!Controller_DW.MC_Controller_MODE) {
      /* InitializeConditions for DiscreteIntegrator: '<S97>/Discrete-Time Integrator' */
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

      /* End of InitializeConditions for DiscreteIntegrator: '<S97>/Discrete-Time Integrator' */

      /* InitializeConditions for DiscreteIntegrator: '<S122>/Discrete-Time Integrator' */
      Controller_DW.DiscreteTimeIntegrator_PrevRe_p = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S124>/Discrete-Time Integrator1' */
      Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S94>/Discrete-Time Integrator5' */
      Controller_DW.DiscreteTimeIntegrator5_IC_LO_c = 1U;

      /* InitializeConditions for DiscreteIntegrator: '<S99>/Discrete-Time Integrator1' */
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevR_k = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S117>/Integrator1' */
      Controller_DW.Integrator1_DSTATE[0] = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S122>/Discrete-Time Integrator' */
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

      /* InitializeConditions for DiscreteIntegrator: '<S117>/Integrator' */
      Controller_DW.Integrator_DSTATE[0] = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S117>/Integrator1' */
      Controller_DW.Integrator1_DSTATE[1] = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S122>/Discrete-Time Integrator' */
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

      /* InitializeConditions for DiscreteIntegrator: '<S117>/Integrator' */
      Controller_DW.Integrator_DSTATE[1] = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S136>/Integrator1' */
      Controller_DW.Integrator1_DSTATE_e = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S139>/Discrete-Time Integrator' */
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

      /* End of InitializeConditions for DiscreteIntegrator: '<S139>/Discrete-Time Integrator' */

      /* InitializeConditions for DiscreteIntegrator: '<S141>/Discrete-Time Integrator1' */
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 1U;
      Controller_DW.DiscreteTimeIntegrator1_Prev_ks = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S136>/Integrator' */
      Controller_DW.Integrator_DSTATE_j = 0.0F;
      Controller_DW.MC_Controller_MODE = true;
    }

    /* Sqrt: '<S89>/Sqrt' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Math: '<S89>/Square'
     *  Sum: '<S89>/Sum of Elements'
     */
    rtb_Add2_h = sqrtf(((Controller_U.INS_Out.quat[0] *
                         Controller_U.INS_Out.quat[0] +
                         Controller_U.INS_Out.quat[1] *
                         Controller_U.INS_Out.quat[1]) +
                        Controller_U.INS_Out.quat[2] *
                        Controller_U.INS_Out.quat[2]) +
                       Controller_U.INS_Out.quat[3] * Controller_U.INS_Out.quat
                       [3]);

    /* Product: '<S85>/Divide' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Sqrt: '<S89>/Sqrt'
     */
    rtb_Divide_m_idx_0 = Controller_U.INS_Out.quat[0] / rtb_Add2_h;
    rtb_Divide_m_idx_1 = Controller_U.INS_Out.quat[1] / rtb_Add2_h;
    rtb_Divide_m_idx_2 = Controller_U.INS_Out.quat[2] / rtb_Add2_h;
    rtb_Divide_m_idx_3 = Controller_U.INS_Out.quat[3] / rtb_Add2_h;

    /* Sum: '<S86>/Subtract' incorporates:
     *  Math: '<S86>/Square'
     *  Math: '<S86>/Square1'
     *  Math: '<S86>/Square2'
     *  Math: '<S86>/Square3'
     *  Sum: '<S86>/Add'
     *  Sum: '<S86>/Add1'
     */
    rtb_MatrixConcatenate1[0] = (rtb_Divide_m_idx_0 * rtb_Divide_m_idx_0 +
      rtb_Divide_m_idx_1 * rtb_Divide_m_idx_1) - (rtb_Divide_m_idx_2 *
      rtb_Divide_m_idx_2 + rtb_Divide_m_idx_3 * rtb_Divide_m_idx_3);

    /* Gain: '<S86>/Gain' incorporates:
     *  Product: '<S86>/Multiply'
     *  Product: '<S86>/Multiply1'
     *  Sum: '<S86>/Subtract1'
     */
    rtb_MatrixConcatenate1[1] = (rtb_Divide_m_idx_1 * rtb_Divide_m_idx_2 -
      rtb_Divide_m_idx_0 * rtb_Divide_m_idx_3) * 2.0F;

    /* Gain: '<S86>/Gain1' incorporates:
     *  Product: '<S86>/Multiply2'
     *  Product: '<S86>/Multiply3'
     *  Sum: '<S86>/Add2'
     */
    rtb_MatrixConcatenate1[2] = (rtb_Divide_m_idx_1 * rtb_Divide_m_idx_3 +
      rtb_Divide_m_idx_0 * rtb_Divide_m_idx_2) * 2.0F;

    /* Gain: '<S87>/Gain' incorporates:
     *  Product: '<S87>/Multiply'
     *  Product: '<S87>/Multiply1'
     *  Sum: '<S87>/Add3'
     */
    rtb_MatrixConcatenate1[3] = (rtb_Divide_m_idx_1 * rtb_Divide_m_idx_2 +
      rtb_Divide_m_idx_0 * rtb_Divide_m_idx_3) * 2.0F;

    /* Sum: '<S87>/Subtract' incorporates:
     *  Math: '<S87>/Square'
     *  Math: '<S87>/Square1'
     *  Math: '<S87>/Square2'
     *  Math: '<S87>/Square3'
     *  Sum: '<S87>/Add'
     *  Sum: '<S87>/Add1'
     */
    rtb_MatrixConcatenate1[4] = (rtb_Divide_m_idx_0 * rtb_Divide_m_idx_0 +
      rtb_Divide_m_idx_2 * rtb_Divide_m_idx_2) - (rtb_Divide_m_idx_1 *
      rtb_Divide_m_idx_1 + rtb_Divide_m_idx_3 * rtb_Divide_m_idx_3);

    /* Gain: '<S87>/Gain1' incorporates:
     *  Product: '<S87>/Multiply2'
     *  Product: '<S87>/Multiply3'
     *  Sum: '<S87>/Subtract1'
     */
    rtb_MatrixConcatenate1[5] = (rtb_Divide_m_idx_2 * rtb_Divide_m_idx_3 -
      rtb_Divide_m_idx_0 * rtb_Divide_m_idx_1) * 2.0F;

    /* Gain: '<S88>/Gain' incorporates:
     *  Product: '<S88>/Multiply'
     *  Product: '<S88>/Multiply1'
     *  Sum: '<S88>/Subtract2'
     */
    rtb_MatrixConcatenate1[6] = (rtb_Divide_m_idx_1 * rtb_Divide_m_idx_3 -
      rtb_Divide_m_idx_0 * rtb_Divide_m_idx_2) * 2.0F;

    /* Gain: '<S88>/Gain1' incorporates:
     *  Product: '<S88>/Multiply2'
     *  Product: '<S88>/Multiply3'
     *  Sum: '<S88>/Add2'
     */
    rtb_MatrixConcatenate1[7] = (rtb_Divide_m_idx_2 * rtb_Divide_m_idx_3 +
      rtb_Divide_m_idx_0 * rtb_Divide_m_idx_1) * 2.0F;

    /* Sum: '<S88>/Subtract' incorporates:
     *  Math: '<S88>/Square'
     *  Math: '<S88>/Square1'
     *  Math: '<S88>/Square2'
     *  Math: '<S88>/Square3'
     *  Sum: '<S88>/Add'
     *  Sum: '<S88>/Add1'
     */
    rtb_MatrixConcatenate1[8] = (rtb_Divide_m_idx_0 * rtb_Divide_m_idx_0 +
      rtb_Divide_m_idx_3 * rtb_Divide_m_idx_3) - (rtb_Divide_m_idx_1 *
      rtb_Divide_m_idx_1 + rtb_Divide_m_idx_2 * rtb_Divide_m_idx_2);

    /* Product: '<S82>/Multiply' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  SignalConversion: '<S82>/TmpSignal ConversionAtMultiplyInport2'
     */
    for (i = 0; i < 3; i++) {
      rtb_TmpSignalConversionAtMultip[i] = rtb_MatrixConcatenate1[i + 6] *
        Controller_U.INS_Out.vd + (rtb_MatrixConcatenate1[i + 3] *
        Controller_U.INS_Out.ve + rtb_MatrixConcatenate1[i] *
        Controller_U.INS_Out.vn);
    }

    /* End of Product: '<S82>/Multiply' */

    /* DiscreteIntegrator: '<S97>/Discrete-Time Integrator' incorporates:
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

    /* RelationalOperator: '<S116>/Compare' incorporates:
     *  Constant: '<S116>/Constant'
     *  Inport: '<Root>/FMS_Out'
     */
    rtb_Compare = (Controller_U.FMS_Out.mode >= 5);

    /* Trigonometry: '<S119>/Trigonometric Function1' incorporates:
     *  Gain: '<S118>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1[0] = arm_cos_f32(-Controller_U.INS_Out.psi);

    /* Trigonometry: '<S119>/Trigonometric Function' incorporates:
     *  Gain: '<S118>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1[1] = arm_sin_f32(-Controller_U.INS_Out.psi);

    /* SignalConversion: '<S119>/ConcatBufferAtVector Concatenate1In3' incorporates:
     *  Constant: '<S119>/Constant3'
     */
    rtb_MatrixConcatenate1[2] = 0.0F;

    /* Gain: '<S119>/Gain' incorporates:
     *  Gain: '<S118>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S119>/Trigonometric Function2'
     */
    rtb_MatrixConcatenate1[3] = -arm_sin_f32(-Controller_U.INS_Out.psi);

    /* Trigonometry: '<S119>/Trigonometric Function3' incorporates:
     *  Gain: '<S118>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1[4] = arm_cos_f32(-Controller_U.INS_Out.psi);

    /* SignalConversion: '<S119>/ConcatBufferAtVector Concatenate2In3' incorporates:
     *  Constant: '<S119>/Constant4'
     */
    rtb_MatrixConcatenate1[5] = 0.0F;

    /* SignalConversion: '<S119>/ConcatBufferAtVector ConcatenateIn3' */
    rtb_MatrixConcatenate1[6] = Controller_ConstB.VectorConcatenate3[0];
    rtb_MatrixConcatenate1[7] = Controller_ConstB.VectorConcatenate3[1];
    rtb_MatrixConcatenate1[8] = Controller_ConstB.VectorConcatenate3[2];

    /* Product: '<S115>/Multiply' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  SignalConversion: '<S115>/TmpSignal ConversionAtMultiplyInport2'
     */
    for (i = 0; i < 3; i++) {
      rtb_fw_rate_err_B[i] = rtb_MatrixConcatenate1[i + 3] *
        Controller_U.INS_Out.ve + rtb_MatrixConcatenate1[i] *
        Controller_U.INS_Out.vn;
    }

    /* End of Product: '<S115>/Multiply' */

    /* Product: '<S112>/Multiply' incorporates:
     *  DataTypeConversion: '<S112>/Data Type Conversion'
     *  DiscreteIntegrator: '<S117>/Integrator1'
     *  Sum: '<S112>/Sum'
     */
    rtb_Saturation1 = (Controller_DW.Integrator1_DSTATE[0] - rtb_fw_rate_err_B[0])
      * (real32_T)rtb_Compare;
    rtb_Gain_az = (Controller_DW.Integrator1_DSTATE[1] - rtb_fw_rate_err_B[1]) *
      (real32_T)rtb_Compare;

    /* Logic: '<S75>/Logical Operator' incorporates:
     *  Constant: '<S111>/Constant'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S111>/Compare'
     */
    rtb_Compare_i = ((Controller_U.FMS_Out.reset != 0) ||
                     (Controller_U.FMS_Out.ext_state != 0));

    /* DiscreteIntegrator: '<S122>/Discrete-Time Integrator' */
    if (rtb_Compare_i || (Controller_DW.DiscreteTimeIntegrator_PrevRe_p != 0)) {
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

    /* DiscreteIntegrator: '<S124>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] = rtb_Saturation1;
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] = rtb_Gain_az;
    }

    if (rtb_Compare_i || (Controller_DW.DiscreteTimeIntegrator1_PrevRes != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] = rtb_Saturation1;
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] = rtb_Gain_az;
    }

    /* Gain: '<S124>/Gain' incorporates:
     *  DiscreteIntegrator: '<S124>/Discrete-Time Integrator1'
     *  Sum: '<S124>/Sum5'
     */
    rtb_Saturation_e = (rtb_Saturation1 -
                        Controller_DW.DiscreteTimeIntegrator1_DSTATE[0]) *
      62.831852F;
    rtb_Divide_m_idx_3 = (rtb_Gain_az -
                          Controller_DW.DiscreteTimeIntegrator1_DSTATE[1]) *
      62.831852F;

    /* Switch: '<S124>/Switch' incorporates:
     *  Gain: '<S124>/Gain1'
     */
    if (rtb_Compare_i) {
      rtb_VdotPg = 0.0F;
      rtb_Add2_h = 0.0F;
    } else {
      rtb_VdotPg = rtb_Saturation_e;
      rtb_Add2_h = rtb_Divide_m_idx_3;
    }

    /* End of Switch: '<S124>/Switch' */

    /* Product: '<S121>/Multiply' incorporates:
     *  Constant: '<S121>/kd'
     */
    rtb_Add1_j4 = CONTROL_PARAM.MC_VEL_XY_D * rtb_VdotPg;

    /* Saturate: '<S121>/Saturation' */
    if (rtb_Add1_j4 > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
      rtb_Add1_j4 = CONTROL_PARAM.MC_VEL_XY_D_MAX;
    } else {
      if (rtb_Add1_j4 < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
        rtb_Add1_j4 = CONTROL_PARAM.MC_VEL_XY_D_MIN;
      }
    }

    rtb_VdotPg = rtb_Add1_j4;

    /* Product: '<S121>/Multiply' incorporates:
     *  Constant: '<S121>/kd'
     */
    rtb_Add1_j4 = CONTROL_PARAM.MC_VEL_XY_D * rtb_Add2_h;

    /* Saturate: '<S121>/Saturation' */
    if (rtb_Add1_j4 > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
      rtb_Add1_j4 = CONTROL_PARAM.MC_VEL_XY_D_MAX;
    } else {
      if (rtb_Add1_j4 < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
        rtb_Add1_j4 = CONTROL_PARAM.MC_VEL_XY_D_MIN;
      }
    }

    /* Switch: '<S114>/Switch' incorporates:
     *  Constant: '<S123>/kp'
     *  Constant: '<S125>/Constant'
     *  Constant: '<S127>/Constant'
     *  Constant: '<S128>/Constant'
     *  DiscreteIntegrator: '<S122>/Discrete-Time Integrator'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S123>/Multiply'
     *  Product: '<S126>/Multiply2'
     *  Product: '<S126>/Multiply3'
     *  RelationalOperator: '<S125>/Compare'
     *  RelationalOperator: '<S127>/Compare'
     *  RelationalOperator: '<S128>/Compare'
     *  S-Function (sfix_bitop): '<S126>/cmd_ax valid'
     *  S-Function (sfix_bitop): '<S126>/cmd_ay valid'
     *  S-Function (sfix_bitop): '<S126>/cmd_u valid'
     *  S-Function (sfix_bitop): '<S126>/cmd_v valid'
     *  Sum: '<S113>/Add'
     *  Sum: '<S126>/Sum1'
     */
    if (Controller_U.FMS_Out.ctrl_mode == 6) {
      rtb_VdotPg = ((Controller_U.FMS_Out.cmd_mask & 64) > 0 ?
                    (CONTROL_PARAM.MC_VEL_XY_P * rtb_Saturation1 +
                     Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0]) +
                    rtb_VdotPg : 0.0F) + ((Controller_U.FMS_Out.cmd_mask & 512) >
        0 ? Controller_U.FMS_Out.ax_cmd : 0.0F);
      rtb_Add2_h = ((Controller_U.FMS_Out.cmd_mask & 128) > 0 ?
                    (CONTROL_PARAM.MC_VEL_XY_P * rtb_Gain_az +
                     Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1]) +
                    rtb_Add1_j4 : 0.0F) + ((Controller_U.FMS_Out.cmd_mask & 1024)
        > 0 ? Controller_U.FMS_Out.ay_cmd : 0.0F);
    } else {
      rtb_VdotPg += CONTROL_PARAM.MC_VEL_XY_P * rtb_Saturation1 +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0];
      rtb_Add2_h = (CONTROL_PARAM.MC_VEL_XY_P * rtb_Gain_az +
                    Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1]) +
        rtb_Add1_j4;
    }

    /* End of Switch: '<S114>/Switch' */

    /* Trigonometry: '<S110>/Atan' incorporates:
     *  Constant: '<S110>/g'
     *  Gain: '<S110>/Gain1'
     *  Gain: '<S110>/gain'
     *  Product: '<S110>/Divide'
     */
    rtb_Divide_m_idx_0 = atanf(1.1F * rtb_Add2_h / 9.8055F);
    rtb_Add2_h = atanf(1.1F * -rtb_VdotPg / 9.8055F);

    /* Switch: '<S101>/Switch' incorporates:
     *  Constant: '<S108>/Constant'
     *  Inport: '<Root>/FMS_Out'
     *  Logic: '<S101>/Logical Operator'
     *  RelationalOperator: '<S107>/Compare'
     *  RelationalOperator: '<S108>/Compare'
     *  Saturate: '<S110>/Saturation'
     *  Switch: '<S101>/Switch1'
     */
    if ((Controller_U.FMS_Out.ctrl_mode == 3) || (Controller_U.FMS_Out.ctrl_mode
         == 4)) {
      rtb_VdotPg = Controller_U.FMS_Out.phi_cmd;
      rtb_Add2_h = Controller_U.FMS_Out.theta_cmd;
    } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
      /* Switch: '<S109>/Switch' incorporates:
       *  S-Function (sfix_bitop): '<S109>/cmd_phi valid'
       *  S-Function (sfix_bitop): '<S109>/cmd_theta valid'
       *  Saturate: '<S110>/Saturation'
       *  Switch: '<S101>/Switch1'
       */
      if ((Controller_U.FMS_Out.cmd_mask & 8) > 0) {
        rtb_VdotPg = Controller_U.FMS_Out.phi_cmd;
      } else if (rtb_Divide_m_idx_0 > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S110>/Saturation' */
        rtb_VdotPg = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else if (rtb_Divide_m_idx_0 < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S110>/Saturation' */
        rtb_VdotPg = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        rtb_VdotPg = rtb_Divide_m_idx_0;
      }

      if ((Controller_U.FMS_Out.cmd_mask & 16) > 0) {
        rtb_Add2_h = Controller_U.FMS_Out.theta_cmd;
      } else if (rtb_Add2_h > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S110>/Saturation' */
        rtb_Add2_h = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_Add2_h < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Saturate: '<S110>/Saturation' */
          rtb_Add2_h = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        }
      }

      /* End of Switch: '<S109>/Switch' */
    } else {
      if (rtb_Divide_m_idx_0 > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S110>/Saturation' incorporates:
         *  Switch: '<S101>/Switch1'
         */
        rtb_VdotPg = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else if (rtb_Divide_m_idx_0 < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S110>/Saturation' incorporates:
         *  Switch: '<S101>/Switch1'
         */
        rtb_VdotPg = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        /* Switch: '<S101>/Switch1' incorporates:
         *  Saturate: '<S110>/Saturation'
         */
        rtb_VdotPg = rtb_Divide_m_idx_0;
      }

      /* Saturate: '<S110>/Saturation' */
      if (rtb_Add2_h > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Switch: '<S101>/Switch1' */
        rtb_Add2_h = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_Add2_h < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Switch: '<S101>/Switch1' */
          rtb_Add2_h = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        }
      }
    }

    /* End of Switch: '<S101>/Switch' */

    /* Sum: '<S102>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Add1_j4 = rtb_VdotPg - Controller_U.INS_Out.phi;

    /* Product: '<S105>/Divide1' incorporates:
     *  Abs: '<S105>/Abs'
     *  Constant: '<S105>/const2'
     */
    rtb_DiscreteTimeIntegrator1_n4 = fabsf(rtb_Add1_j4) / 0.002F;

    /* Product: '<S105>/Divide' incorporates:
     *  Constant: '<S103>/Constant1'
     *  Constant: '<S105>/const1'
     *  Math: '<S105>/Square'
     *  SignalConversion: '<S105>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_Add_k = 9.5993F / (CONTROL_PARAM.MC_ROLL_P * CONTROL_PARAM.MC_ROLL_P);

    /* Signum: '<S105>/Sign' */
    if (rtb_Add1_j4 < 0.0F) {
      rtb_Sum = -1.0F;
    } else if (rtb_Add1_j4 > 0.0F) {
      rtb_Sum = 1.0F;
    } else {
      rtb_Sum = rtb_Add1_j4;
    }

    /* Switch: '<S105>/Switch' incorporates:
     *  Constant: '<S103>/Constant1'
     *  Gain: '<S105>/Gain1'
     *  Gain: '<S105>/Gain2'
     *  Logic: '<S105>/Logical Operator'
     *  Product: '<S105>/Multiply'
     *  Product: '<S105>/Multiply1'
     *  Product: '<S105>/Multiply2'
     *  Product: '<S105>/Multiply3'
     *  RelationalOperator: '<S105>/Relational Operator'
     *  RelationalOperator: '<S105>/Relational Operator2'
     *  SignalConversion: '<S105>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S105>/Sqrt'
     *  Sum: '<S105>/Subtract'
     */
    if ((rtb_Add1_j4 <= rtb_Add_k) && (rtb_Add1_j4 >= -rtb_Add_k)) {
      rtb_Sum = rtb_Add1_j4 * CONTROL_PARAM.MC_ROLL_P;
    } else {
      rtb_Sum *= sqrtf((rtb_Sum * rtb_Add1_j4 - 0.5F * rtb_Add_k) *
                       Controller_ConstB.Gain);
    }

    /* Product: '<S105>/Divide' incorporates:
     *  Gain: '<S105>/Gain3'
     */
    rtb_Divide_m_idx_0 = -rtb_DiscreteTimeIntegrator1_n4;

    /* Switch: '<S106>/Switch' incorporates:
     *  Gain: '<S105>/Gain3'
     *  RelationalOperator: '<S106>/UpperRelop'
     */
    if (rtb_Sum >= -rtb_DiscreteTimeIntegrator1_n4) {
      /* Product: '<S105>/Divide' */
      rtb_Divide_m_idx_0 = rtb_Sum;
    }

    rtb_VdotPg = rtb_DiscreteTimeIntegrator1_n4;
    rtb_Divide_m_idx_1 = rtb_Sum;

    /* Sum: '<S102>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S105>/Divide1'
     *  Signum: '<S105>/Sign'
     */
    rtb_Add1_j4 = rtb_Add2_h - Controller_U.INS_Out.theta;

    /* Product: '<S105>/Divide1' incorporates:
     *  Abs: '<S105>/Abs'
     *  Constant: '<S105>/const2'
     */
    rtb_DiscreteTimeIntegrator1_n4 = fabsf(rtb_Add1_j4) / 0.002F;

    /* Product: '<S105>/Divide' incorporates:
     *  Constant: '<S103>/Constant2'
     *  Constant: '<S105>/const1'
     *  Math: '<S105>/Square'
     *  SignalConversion: '<S105>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_Add_k = 9.5993F / (CONTROL_PARAM.MC_PITCH_P * CONTROL_PARAM.MC_PITCH_P);

    /* Signum: '<S105>/Sign' */
    if (rtb_Add1_j4 < 0.0F) {
      rtb_Sum = -1.0F;
    } else if (rtb_Add1_j4 > 0.0F) {
      rtb_Sum = 1.0F;
    } else {
      rtb_Sum = rtb_Add1_j4;
    }

    /* Switch: '<S105>/Switch' incorporates:
     *  Constant: '<S103>/Constant2'
     *  Gain: '<S105>/Gain1'
     *  Gain: '<S105>/Gain2'
     *  Logic: '<S105>/Logical Operator'
     *  Product: '<S105>/Multiply'
     *  Product: '<S105>/Multiply1'
     *  Product: '<S105>/Multiply2'
     *  Product: '<S105>/Multiply3'
     *  RelationalOperator: '<S105>/Relational Operator'
     *  RelationalOperator: '<S105>/Relational Operator2'
     *  SignalConversion: '<S105>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S105>/Sqrt'
     *  Sum: '<S105>/Subtract'
     */
    if ((rtb_Add1_j4 <= rtb_Add_k) && (rtb_Add1_j4 >= -rtb_Add_k)) {
      rtb_Sum = rtb_Add1_j4 * CONTROL_PARAM.MC_PITCH_P;
    } else {
      rtb_Sum *= sqrtf((rtb_Sum * rtb_Add1_j4 - 0.5F * rtb_Add_k) *
                       Controller_ConstB.Gain);
    }

    /* Gain: '<S105>/Gain3' */
    rtb_Add_k = -rtb_DiscreteTimeIntegrator1_n4;

    /* Switch: '<S106>/Switch' incorporates:
     *  Gain: '<S105>/Gain3'
     *  RelationalOperator: '<S106>/UpperRelop'
     */
    if (rtb_Sum >= -rtb_DiscreteTimeIntegrator1_n4) {
      rtb_Add_k = rtb_Sum;
    }

    /* MultiPortSwitch: '<S78>/Multiport Switch' incorporates:
     *  Constant: '<S80>/Constant3'
     *  Constant: '<S83>/Constant3'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S80>/Multiply1'
     *  Product: '<S80>/Multiply2'
     *  Product: '<S83>/Multiply1'
     *  Product: '<S83>/Multiply2'
     *  Sum: '<S80>/Sum'
     *  Sum: '<S80>/Sum1'
     *  Sum: '<S83>/Sum'
     *  Sum: '<S83>/Sum1'
     */
    switch (Controller_U.FMS_Out.ext_state) {
     case 1:
      /* Saturate: '<S83>/Saturation3' */
      if (rtb_TmpSignalConversionAtMultip[0] > 8.0F) {
        rtb_Add1_j4 = 8.0F;
      } else if (rtb_TmpSignalConversionAtMultip[0] < 2.0F) {
        rtb_Add1_j4 = 2.0F;
      } else {
        rtb_Add1_j4 = rtb_TmpSignalConversionAtMultip[0];
      }

      /* End of Saturate: '<S83>/Saturation3' */

      /* Product: '<S83>/Multiply' incorporates:
       *  Constant: '<S83>/Constant1'
       *  Sum: '<S83>/Subtract1'
       */
      rtb_Add_k = (rtb_Add1_j4 - 2.0F) * Controller_ConstB.Divide_k;

      /* Switch: '<S106>/Switch2' incorporates:
       *  RelationalOperator: '<S106>/LowerRelop1'
       */
      if (rtb_Divide_m_idx_1 > rtb_VdotPg) {
        rtb_Divide_m_idx_0 = rtb_VdotPg;
      }

      Controller_B.Multiply[0] = (1.0F - rtb_Add_k) * rtb_Divide_m_idx_0 +
        rtb_Add_k * Controller_B.Reshape[0];
      Controller_B.Multiply[1] = Controller_B.Reshape[1];
      Controller_B.Multiply[2] = (1.0F - rtb_Add_k) *
        Controller_U.FMS_Out.psi_rate_cmd + rtb_Add_k * Controller_B.Reshape[2];
      break;

     case 3:
      /* Saturate: '<S80>/Saturation3' */
      if (rtb_TmpSignalConversionAtMultip[0] > 8.0F) {
        rtb_Add1_j4 = 8.0F;
      } else if (rtb_TmpSignalConversionAtMultip[0] < 2.0F) {
        rtb_Add1_j4 = 2.0F;
      } else {
        rtb_Add1_j4 = rtb_TmpSignalConversionAtMultip[0];
      }

      /* End of Saturate: '<S80>/Saturation3' */

      /* Product: '<S80>/Multiply' incorporates:
       *  Constant: '<S80>/Constant1'
       *  Sum: '<S80>/Subtract1'
       */
      rtb_Add1_j4 = (rtb_Add1_j4 - 2.0F) * Controller_ConstB.Divide;

      /* Switch: '<S106>/Switch2' incorporates:
       *  RelationalOperator: '<S106>/LowerRelop1'
       */
      if (rtb_Divide_m_idx_1 > rtb_VdotPg) {
        rtb_Divide_m_idx_0 = rtb_VdotPg;
      }

      Controller_B.Multiply[0] = (1.0F - rtb_Add1_j4) * rtb_Divide_m_idx_0 +
        rtb_Add1_j4 * Controller_B.Reshape[0];

      /* Switch: '<S106>/Switch2' incorporates:
       *  Constant: '<S80>/Constant3'
       *  Product: '<S80>/Multiply1'
       *  Product: '<S80>/Multiply2'
       *  RelationalOperator: '<S106>/LowerRelop1'
       *  Sum: '<S80>/Sum'
       *  Sum: '<S80>/Sum1'
       */
      if (rtb_Sum > rtb_DiscreteTimeIntegrator1_n4) {
        rtb_Add_k = rtb_DiscreteTimeIntegrator1_n4;
      }

      Controller_B.Multiply[1] = (1.0F - rtb_Add1_j4) * rtb_Add_k + rtb_Add1_j4 *
        Controller_B.Reshape[1];
      Controller_B.Multiply[2] = (1.0F - rtb_Add1_j4) *
        Controller_U.FMS_Out.psi_rate_cmd + rtb_Add1_j4 * Controller_B.Reshape[2];
      break;

     case 2:
      Controller_B.Multiply[0] = Controller_B.Reshape[0];
      Controller_B.Multiply[1] = Controller_B.Reshape[1];
      Controller_B.Multiply[2] = Controller_B.Reshape[2];
      break;

     case 4:
      Controller_B.Multiply[0] = Controller_B.Reshape[0];
      Controller_B.Multiply[1] = Controller_B.Reshape[1];
      Controller_B.Multiply[2] = Controller_B.Reshape[2];
      break;

     default:
      /* Switch: '<S106>/Switch2' incorporates:
       *  RelationalOperator: '<S106>/LowerRelop1'
       */
      if (rtb_Divide_m_idx_1 > rtb_VdotPg) {
        Controller_B.Multiply[0] = rtb_VdotPg;
      } else {
        Controller_B.Multiply[0] = rtb_Divide_m_idx_0;
      }

      if (rtb_Sum > rtb_DiscreteTimeIntegrator1_n4) {
        Controller_B.Multiply[1] = rtb_DiscreteTimeIntegrator1_n4;
      } else {
        Controller_B.Multiply[1] = rtb_Add_k;
      }

      Controller_B.Multiply[2] = Controller_U.FMS_Out.psi_rate_cmd;
      break;
    }

    /* End of MultiPortSwitch: '<S78>/Multiport Switch' */

    /* Trigonometry: '<S81>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    u = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Trigonometry: '<S81>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Add2_h = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S81>/Sin' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_DiscreteTimeIntegrator1_n4 = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Sum: '<S81>/Add2' incorporates:
     *  Product: '<S81>/Multiply4'
     *  Product: '<S81>/Multiply5'
     *  Trigonometry: '<S81>/Cos'
     *  Trigonometry: '<S81>/Cos1'
     *  Trigonometry: '<S81>/Sin'
     */
    rtb_Divide_m_idx_1 = rtb_Add2_h * u * Controller_B.Multiply[2] -
      rtb_DiscreteTimeIntegrator1_n4 * Controller_B.Multiply[1];

    /* Saturate: '<S78>/Saturation' */
    if (rtb_Divide_m_idx_1 > CONTROL_PARAM.MC_R_CMD_LIM) {
      rtb_Divide_m_idx_1 = CONTROL_PARAM.MC_R_CMD_LIM;
    } else {
      if (rtb_Divide_m_idx_1 < -CONTROL_PARAM.MC_R_CMD_LIM) {
        rtb_Divide_m_idx_1 = -CONTROL_PARAM.MC_R_CMD_LIM;
      }
    }

    /* End of Saturate: '<S78>/Saturation' */

    /* Sum: '<S81>/Add' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S81>/Multiply'
     *  Trigonometry: '<S81>/Sin1'
     */
    rtb_Divide_m_idx_2 = Controller_B.Multiply[0] - arm_sin_f32
      (Controller_U.INS_Out.theta) * Controller_B.Multiply[2];

    /* Saturate: '<S78>/Saturation1' */
    if (rtb_Divide_m_idx_2 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_Divide_m_idx_2 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_Divide_m_idx_2 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_Divide_m_idx_2 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    /* End of Saturate: '<S78>/Saturation1' */

    /* Sum: '<S81>/Add1' incorporates:
     *  Product: '<S81>/Multiply1'
     *  Product: '<S81>/Multiply3'
     *  Trigonometry: '<S81>/Cos'
     *  Trigonometry: '<S81>/Cos1'
     *  Trigonometry: '<S81>/Sin'
     */
    rtb_DiscreteTimeIntegrator1_n4 = rtb_DiscreteTimeIntegrator1_n4 * u *
      Controller_B.Multiply[2] + rtb_Add2_h * Controller_B.Multiply[1];

    /* Saturate: '<S78>/Saturation2' */
    if (rtb_DiscreteTimeIntegrator1_n4 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_DiscreteTimeIntegrator1_n4 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_DiscreteTimeIntegrator1_n4 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_DiscreteTimeIntegrator1_n4 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    /* End of Saturate: '<S78>/Saturation2' */

    /* Sum: '<S90>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_m_idx_0 = rtb_Divide_m_idx_2 - Controller_U.INS_Out.p;

    /* Saturate: '<S90>/Saturation' */
    if (rtb_Divide_m_idx_0 > 3.14159274F) {
      rtb_Divide_m_idx_0 = 3.14159274F;
    } else {
      if (rtb_Divide_m_idx_0 < -3.14159274F) {
        rtb_Divide_m_idx_0 = -3.14159274F;
      }
    }

    /* Sum: '<S90>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Add_k = rtb_DiscreteTimeIntegrator1_n4 - Controller_U.INS_Out.q;

    /* Saturate: '<S90>/Saturation' */
    if (rtb_Add_k > 3.14159274F) {
      rtb_Add_k = 3.14159274F;
    } else {
      if (rtb_Add_k < -3.14159274F) {
        rtb_Add_k = -3.14159274F;
      }
    }

    /* Sum: '<S90>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Add1_j4 = rtb_Divide_m_idx_1 - Controller_U.INS_Out.r;

    /* Saturate: '<S90>/Saturation' */
    if (rtb_Add1_j4 > 3.14159274F) {
      rtb_Add1_j4 = 3.14159274F;
    } else {
      if (rtb_Add1_j4 < -3.14159274F) {
        rtb_Add1_j4 = -3.14159274F;
      }
    }

    /* DiscreteIntegrator: '<S94>/Discrete-Time Integrator5' incorporates:
     *  Saturate: '<S90>/Saturation'
     */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_c != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0] = rtb_Divide_m_idx_0;
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1] = rtb_Add_k;
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2] = rtb_Add1_j4;
    }

    /* DiscreteIntegrator: '<S99>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S94>/Discrete-Time Integrator5'
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

    /* Gain: '<S99>/Gain' incorporates:
     *  DiscreteIntegrator: '<S94>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S99>/Discrete-Time Integrator1'
     *  Sum: '<S99>/Sum5'
     */
    rtb_Multiply_ni[0] = (Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0] -
                          Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[0]) *
      188.49556F;
    rtb_Multiply_ni[1] = (Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1] -
                          Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[1]) *
      188.49556F;
    rtb_Multiply_ni[2] = (Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2] -
                          Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[2]) *
      188.49556F;

    /* Switch: '<S99>/Switch' incorporates:
     *  Gain: '<S99>/Gain1'
     *  Inport: '<Root>/FMS_Out'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_Add2_h = 0.0F;
      rtb_VdotPg = 0.0F;
      rtb_Sum = 0.0F;
    } else {
      rtb_Add2_h = rtb_Multiply_ni[0];
      rtb_VdotPg = rtb_Multiply_ni[1];
      rtb_Sum = rtb_Multiply_ni[2];
    }

    /* End of Switch: '<S99>/Switch' */

    /* Product: '<S96>/Multiply' incorporates:
     *  Constant: '<S96>/gain1'
     */
    rtb_Sign5_f = CONTROL_PARAM.MC_ROLL_RATE_D * rtb_Add2_h;

    /* Saturate: '<S96>/Saturation' */
    if (rtb_Sign5_f > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Sign5_f = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Sign5_f < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Sign5_f = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    rtb_Add2_h = rtb_Sign5_f;

    /* Product: '<S96>/Multiply' incorporates:
     *  Constant: '<S96>/gain2'
     */
    rtb_Sign5_f = CONTROL_PARAM.MC_PITCH_RATE_D * rtb_VdotPg;

    /* Saturate: '<S96>/Saturation' */
    if (rtb_Sign5_f > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Sign5_f = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Sign5_f < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Sign5_f = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    rtb_VdotPg = rtb_Sign5_f;

    /* Product: '<S96>/Multiply' incorporates:
     *  Constant: '<S96>/gain3'
     */
    rtb_Sign5_f = CONTROL_PARAM.MC_YAW_RATE_D * rtb_Sum;

    /* Saturate: '<S96>/Saturation' */
    if (rtb_Sign5_f > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Sign5_f = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Sign5_f < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Sign5_f = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    /* Sum: '<S92>/Add' incorporates:
     *  Constant: '<S98>/gain1'
     *  Constant: '<S98>/gain2'
     *  Constant: '<S98>/gain3'
     *  DiscreteIntegrator: '<S94>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S97>/Discrete-Time Integrator'
     *  Product: '<S98>/Multiply'
     */
    Controller_B.Multiply[0] = (CONTROL_PARAM.MC_ROLL_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0]) + rtb_Add2_h;
    Controller_B.Multiply[1] = (CONTROL_PARAM.MC_PITCH_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1]) + rtb_VdotPg;
    Controller_B.Multiply[2] = (CONTROL_PARAM.MC_YAW_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[2]) + rtb_Sign5_f;

    /* DeadZone: '<S95>/Dead Zone' */
    if (rtb_Divide_m_idx_2 > 0.1F) {
      rtb_Divide_m_idx_2 -= 0.1F;
    } else if (rtb_Divide_m_idx_2 >= -0.1F) {
      rtb_Divide_m_idx_2 = 0.0F;
    } else {
      rtb_Divide_m_idx_2 -= -0.1F;
    }

    /* Sum: '<S79>/Sum' incorporates:
     *  Gain: '<S91>/Gain'
     *  Gain: '<S95>/Gain'
     */
    Controller_B.Multiply[0] += 1.11111116F * rtb_Divide_m_idx_2 *
      CONTROL_PARAM.MC_ROLL_RATE_FF;

    /* Product: '<S6>/Multiply' incorporates:
     *  DiscreteIntegrator: '<S9>/Discrete-Time Integrator5'
     */
    Controller_B.Multiply[0] *= Controller_DW.DiscreteTimeIntegrator5_DSTATE;

    /* DeadZone: '<S95>/Dead Zone' */
    if (rtb_DiscreteTimeIntegrator1_n4 > 0.1F) {
      rtb_DiscreteTimeIntegrator1_n4 -= 0.1F;
    } else if (rtb_DiscreteTimeIntegrator1_n4 >= -0.1F) {
      rtb_DiscreteTimeIntegrator1_n4 = 0.0F;
    } else {
      rtb_DiscreteTimeIntegrator1_n4 -= -0.1F;
    }

    /* Sum: '<S79>/Sum' incorporates:
     *  Gain: '<S91>/Gain'
     *  Gain: '<S95>/Gain'
     */
    Controller_B.Multiply[1] += 1.11111116F * rtb_DiscreteTimeIntegrator1_n4 *
      CONTROL_PARAM.MC_ROLL_RATE_FF;

    /* Product: '<S6>/Multiply' incorporates:
     *  DiscreteIntegrator: '<S9>/Discrete-Time Integrator5'
     */
    Controller_B.Multiply[1] *= Controller_DW.DiscreteTimeIntegrator5_DSTATE;

    /* DeadZone: '<S95>/Dead Zone' */
    if (rtb_Divide_m_idx_1 > 0.1F) {
      rtb_Divide_m_idx_1 -= 0.1F;
    } else if (rtb_Divide_m_idx_1 >= -0.1F) {
      rtb_Divide_m_idx_1 = 0.0F;
    } else {
      rtb_Divide_m_idx_1 -= -0.1F;
    }

    /* Sum: '<S79>/Sum' incorporates:
     *  Gain: '<S91>/Gain1'
     *  Gain: '<S95>/Gain'
     */
    Controller_B.Multiply[2] += 1.11111116F * rtb_Divide_m_idx_1 *
      CONTROL_PARAM.MC_PITCH_RATE_FF;

    /* Product: '<S6>/Multiply' incorporates:
     *  DiscreteIntegrator: '<S9>/Discrete-Time Integrator5'
     */
    Controller_B.Multiply[2] *= Controller_DW.DiscreteTimeIntegrator5_DSTATE;

    /* Product: '<S120>/Multiply1' incorporates:
     *  Constant: '<S120>/const1'
     *  DiscreteIntegrator: '<S117>/Integrator'
     */
    rtb_VdotPg = Controller_DW.Integrator_DSTATE[0] * 0.05F;
    rtb_Add2_h = Controller_DW.Integrator_DSTATE[1] * 0.05F;

    /* Switch: '<S112>/Switch' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    if (rtb_Compare) {
      rtb_Divide_m_idx_2 = Controller_U.FMS_Out.u_cmd;
    } else {
      rtb_Divide_m_idx_2 = rtb_fw_rate_err_B[0];
    }

    /* Sum: '<S120>/Add' incorporates:
     *  DiscreteIntegrator: '<S117>/Integrator1'
     *  Sum: '<S117>/Subtract'
     */
    rtb_Divide_m_idx_1 = (Controller_DW.Integrator1_DSTATE[0] -
                          rtb_Divide_m_idx_2) + rtb_VdotPg;

    /* Switch: '<S112>/Switch' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    if (rtb_Compare) {
      rtb_Divide_m_idx_2 = Controller_U.FMS_Out.v_cmd;
    } else {
      rtb_Divide_m_idx_2 = rtb_fw_rate_err_B[1];
    }

    /* Sum: '<S120>/Add' incorporates:
     *  DiscreteIntegrator: '<S117>/Integrator1'
     *  Sum: '<S117>/Subtract'
     */
    rtb_Sign5_f = (Controller_DW.Integrator1_DSTATE[1] - rtb_Divide_m_idx_2) +
      rtb_Add2_h;

    /* Signum: '<S120>/Sign' */
    if (rtb_Divide_m_idx_1 < 0.0F) {
      rtb_Divide_m_idx_2 = -1.0F;
    } else if (rtb_Divide_m_idx_1 > 0.0F) {
      rtb_Divide_m_idx_2 = 1.0F;
    } else {
      rtb_Divide_m_idx_2 = rtb_Divide_m_idx_1;
    }

    /* Sum: '<S120>/Add2' incorporates:
     *  Abs: '<S120>/Abs'
     *  Gain: '<S120>/Gain'
     *  Gain: '<S120>/Gain1'
     *  Product: '<S120>/Multiply2'
     *  Product: '<S120>/Multiply3'
     *  Signum: '<S120>/Sign'
     *  Sqrt: '<S120>/Sqrt'
     *  Sum: '<S120>/Add1'
     *  Sum: '<S120>/Subtract'
     */
    rtb_DiscreteTimeIntegrator1_n4 = (sqrtf((8.0F * fabsf(rtb_Divide_m_idx_1) +
      Controller_ConstB.d) * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
      rtb_Divide_m_idx_2 + rtb_VdotPg;

    /* Sum: '<S120>/Add3' incorporates:
     *  Signum: '<S120>/Sign'
     */
    rtb_Divide_m_idx_2 = rtb_Divide_m_idx_1 + Controller_ConstB.d;

    /* Sum: '<S120>/Subtract1' incorporates:
     *  Signum: '<S120>/Sign'
     */
    rtb_Sum = rtb_Divide_m_idx_1 - Controller_ConstB.d;

    /* Signum: '<S120>/Sign1' */
    if (rtb_Divide_m_idx_2 < 0.0F) {
      rtb_Divide_m_idx_2 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_2 > 0.0F) {
        rtb_Divide_m_idx_2 = 1.0F;
      }
    }

    /* Signum: '<S120>/Sign2' */
    if (rtb_Sum < 0.0F) {
      rtb_Sum = -1.0F;
    } else {
      if (rtb_Sum > 0.0F) {
        rtb_Sum = 1.0F;
      }
    }

    /* Sum: '<S120>/Add2' incorporates:
     *  Gain: '<S120>/Gain2'
     *  Product: '<S120>/Multiply4'
     *  Signum: '<S120>/Sign'
     *  Sum: '<S120>/Add4'
     *  Sum: '<S120>/Add5'
     *  Sum: '<S120>/Subtract2'
     */
    rtb_VdotPg = ((rtb_Divide_m_idx_1 - rtb_DiscreteTimeIntegrator1_n4) +
                  rtb_VdotPg) * ((rtb_Divide_m_idx_2 - rtb_Sum) * 0.5F) +
      rtb_DiscreteTimeIntegrator1_n4;

    /* Signum: '<S120>/Sign' */
    if (rtb_Sign5_f < 0.0F) {
      rtb_Divide_m_idx_1 = -1.0F;
    } else if (rtb_Sign5_f > 0.0F) {
      rtb_Divide_m_idx_1 = 1.0F;
    } else {
      rtb_Divide_m_idx_1 = rtb_Sign5_f;
    }

    /* Sum: '<S120>/Add2' incorporates:
     *  Abs: '<S120>/Abs'
     *  Gain: '<S120>/Gain'
     *  Gain: '<S120>/Gain1'
     *  Product: '<S120>/Multiply2'
     *  Product: '<S120>/Multiply3'
     *  Signum: '<S120>/Sign'
     *  Sqrt: '<S120>/Sqrt'
     *  Sum: '<S120>/Add1'
     *  Sum: '<S120>/Subtract'
     */
    rtb_DiscreteTimeIntegrator1_n4 = (sqrtf((8.0F * fabsf(rtb_Sign5_f) +
      Controller_ConstB.d) * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
      rtb_Divide_m_idx_1 + rtb_Add2_h;

    /* Sum: '<S120>/Add3' incorporates:
     *  Signum: '<S120>/Sign'
     */
    rtb_Divide_m_idx_2 = rtb_Sign5_f + Controller_ConstB.d;

    /* Sum: '<S120>/Subtract1' incorporates:
     *  Signum: '<S120>/Sign'
     */
    rtb_Sum = rtb_Sign5_f - Controller_ConstB.d;

    /* Signum: '<S120>/Sign1' */
    if (rtb_Divide_m_idx_2 < 0.0F) {
      rtb_Divide_m_idx_2 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_2 > 0.0F) {
        rtb_Divide_m_idx_2 = 1.0F;
      }
    }

    /* Signum: '<S120>/Sign2' */
    if (rtb_Sum < 0.0F) {
      rtb_Sum = -1.0F;
    } else {
      if (rtb_Sum > 0.0F) {
        rtb_Sum = 1.0F;
      }
    }

    /* Sum: '<S120>/Add5' incorporates:
     *  Gain: '<S120>/Gain2'
     *  Product: '<S120>/Multiply4'
     *  Signum: '<S120>/Sign'
     *  Sum: '<S120>/Add2'
     *  Sum: '<S120>/Add4'
     *  Sum: '<S120>/Subtract2'
     */
    rtb_DiscreteTimeIntegrator1_n4 += ((rtb_Sign5_f -
      rtb_DiscreteTimeIntegrator1_n4) + rtb_Add2_h) * ((rtb_Divide_m_idx_2 -
      rtb_Sum) * 0.5F);

    /* RelationalOperator: '<S135>/Compare' incorporates:
     *  Constant: '<S135>/Constant'
     *  Inport: '<Root>/FMS_Out'
     */
    rtb_Compare = (Controller_U.FMS_Out.mode >= 4);

    /* Product: '<S133>/Multiply' incorporates:
     *  DataTypeConversion: '<S133>/Data Type Conversion'
     *  DiscreteIntegrator: '<S136>/Integrator1'
     *  Gain: '<S133>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S133>/Sum1'
     */
    rtb_Sum = -(Controller_DW.Integrator1_DSTATE_e - Controller_U.INS_Out.vd) *
      (real32_T)rtb_Compare;
    Controller_B.Constant = CONTROL_PARAM.MC_VEL_Z_I_MIN;

    /* DiscreteIntegrator: '<S139>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S139>/Constant'
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

    /* DiscreteIntegrator: '<S141>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_d != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i = rtb_Sum;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_Prev_ks != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i = rtb_Sum;
    }

    /* Gain: '<S141>/Gain' incorporates:
     *  DiscreteIntegrator: '<S141>/Discrete-Time Integrator1'
     *  Sum: '<S141>/Sum5'
     */
    rtb_Sign5_f = (rtb_Sum - Controller_DW.DiscreteTimeIntegrator1_DSTAT_i) *
      62.831852F;

    /* Switch: '<S129>/Switch' incorporates:
     *  Bias: '<S129>/Bias'
     *  Constant: '<S131>/Constant'
     *  Gain: '<S129>/Gain'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S131>/Compare'
     */
    if (Controller_U.FMS_Out.ctrl_mode <= 3) {
      rtb_Divide_m_idx_1 = 0.000999987125F * (real32_T)
        Controller_U.FMS_Out.throttle_cmd + -1.0F;
    } else {
      /* Product: '<S132>/Multiply' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S132>/Cos'
       *  Trigonometry: '<S132>/Cos1'
       */
      rtb_Divide_m_idx_1 = arm_cos_f32(Controller_U.INS_Out.phi) * arm_cos_f32
        (Controller_U.INS_Out.theta);

      /* Gain: '<S132>/Gain' */
      rtb_Add2_h = 2.0F * rtb_Divide_m_idx_1;

      /* Saturate: '<S132>/Saturation1' */
      if (rtb_Divide_m_idx_1 > 1.0F) {
        rtb_Divide_m_idx_1 = 1.0F;
      } else {
        if (rtb_Divide_m_idx_1 < 0.5F) {
          rtb_Divide_m_idx_1 = 0.5F;
        }
      }

      /* End of Saturate: '<S132>/Saturation1' */

      /* Product: '<S132>/Divide' incorporates:
       *  Constant: '<S132>/Constant'
       */
      rtb_Divide_m_idx_2 = 1.0F / rtb_Divide_m_idx_1;

      /* Switch: '<S141>/Switch' incorporates:
       *  Gain: '<S141>/Gain1'
       */
      if (Controller_U.FMS_Out.reset > 0) {
        rtb_Divide_m_idx_1 = 0.0F;
      } else {
        rtb_Divide_m_idx_1 = rtb_Sign5_f;
      }

      /* End of Switch: '<S141>/Switch' */

      /* Product: '<S138>/Multiply' incorporates:
       *  Constant: '<S138>/kd'
       */
      rtb_Divide_m_idx_1 *= CONTROL_PARAM.MC_VEL_Z_D;

      /* Saturate: '<S138>/Saturation' */
      if (rtb_Divide_m_idx_1 > CONTROL_PARAM.MC_VEL_Z_D_MAX) {
        rtb_Divide_m_idx_1 = CONTROL_PARAM.MC_VEL_Z_D_MAX;
      } else {
        if (rtb_Divide_m_idx_1 < CONTROL_PARAM.MC_VEL_Z_D_MIN) {
          rtb_Divide_m_idx_1 = CONTROL_PARAM.MC_VEL_Z_D_MIN;
        }
      }

      /* End of Saturate: '<S138>/Saturation' */

      /* Saturate: '<S132>/Saturation' */
      if (rtb_Add2_h > 1.0F) {
        rtb_Add2_h = 1.0F;
      } else {
        if (rtb_Add2_h < 0.0F) {
          rtb_Add2_h = 0.0F;
        }
      }

      /* End of Saturate: '<S132>/Saturation' */

      /* Sum: '<S130>/Sum' incorporates:
       *  Constant: '<S130>/hover_throttle'
       *  Constant: '<S140>/kp'
       *  DiscreteIntegrator: '<S139>/Discrete-Time Integrator'
       *  Product: '<S132>/Multiply1'
       *  Product: '<S140>/Multiply'
       *  Sum: '<S134>/Add'
       */
      rtb_Divide_m_idx_1 = ((CONTROL_PARAM.MC_VEL_Z_P * rtb_Sum +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_l) + rtb_Divide_m_idx_1) *
        rtb_Divide_m_idx_2 * rtb_Add2_h + CONTROL_PARAM.MC_HOVER_THRO;

      /* Saturate: '<S130>/Saturation' */
      if (rtb_Divide_m_idx_1 > 0.85F) {
        rtb_Divide_m_idx_1 = 0.85F;
      } else {
        if (rtb_Divide_m_idx_1 < 0.25F) {
          rtb_Divide_m_idx_1 = 0.25F;
        }
      }

      /* End of Saturate: '<S130>/Saturation' */
    }

    /* End of Switch: '<S129>/Switch' */

    /* Product: '<S6>/Multiply1' incorporates:
     *  Constant: '<S129>/Constant'
     *  DiscreteIntegrator: '<S9>/Discrete-Time Integrator5'
     */
    Controller_B.Multiply1[0] = 0.0F;
    Controller_B.Multiply1[1] = 0.0F;
    Controller_B.Multiply1[2] = Controller_DW.DiscreteTimeIntegrator5_DSTATE *
      rtb_Divide_m_idx_1;

    /* Product: '<S137>/Multiply1' incorporates:
     *  Constant: '<S137>/const1'
     *  DiscreteIntegrator: '<S136>/Integrator'
     */
    rtb_Divide_m_idx_1 = Controller_DW.Integrator_DSTATE_j * 0.05F;

    /* Switch: '<S133>/Switch' incorporates:
     *  Inport: '<Root>/FMS_Out'
     *  Inport: '<Root>/INS_Out'
     */
    if (rtb_Compare) {
      rtb_Divide_m_idx_2 = Controller_U.FMS_Out.w_cmd;
    } else {
      rtb_Divide_m_idx_2 = Controller_U.INS_Out.vd;
    }

    /* End of Switch: '<S133>/Switch' */

    /* Sum: '<S137>/Add' incorporates:
     *  DiscreteIntegrator: '<S136>/Integrator1'
     *  Sum: '<S136>/Subtract'
     */
    u = (Controller_DW.Integrator1_DSTATE_e - rtb_Divide_m_idx_2) +
      rtb_Divide_m_idx_1;

    /* Signum: '<S137>/Sign' */
    if (u < 0.0F) {
      rtb_Add2_h = -1.0F;
    } else if (u > 0.0F) {
      rtb_Add2_h = 1.0F;
    } else {
      rtb_Add2_h = u;
    }

    /* End of Signum: '<S137>/Sign' */

    /* Sum: '<S137>/Add2' incorporates:
     *  Abs: '<S137>/Abs'
     *  Gain: '<S137>/Gain'
     *  Gain: '<S137>/Gain1'
     *  Product: '<S137>/Multiply2'
     *  Product: '<S137>/Multiply3'
     *  Sqrt: '<S137>/Sqrt'
     *  Sum: '<S137>/Add1'
     *  Sum: '<S137>/Subtract'
     */
    rtb_Add2_h = (sqrtf((8.0F * fabsf(u) + Controller_ConstB.d_i) *
                        Controller_ConstB.d_i) - Controller_ConstB.d_i) * 0.5F *
      rtb_Add2_h + rtb_Divide_m_idx_1;

    /* Sum: '<S137>/Add4' */
    rtb_Divide_m_idx_1 += u - rtb_Add2_h;

    /* Sum: '<S137>/Add3' */
    rtb_Divide_m_idx_2 = u + Controller_ConstB.d_i;

    /* Sum: '<S137>/Subtract1' */
    u -= Controller_ConstB.d_i;

    /* Signum: '<S137>/Sign1' */
    if (rtb_Divide_m_idx_2 < 0.0F) {
      rtb_Divide_m_idx_2 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_2 > 0.0F) {
        rtb_Divide_m_idx_2 = 1.0F;
      }
    }

    /* End of Signum: '<S137>/Sign1' */

    /* Signum: '<S137>/Sign2' */
    if (u < 0.0F) {
      u = -1.0F;
    } else {
      if (u > 0.0F) {
        u = 1.0F;
      }
    }

    /* End of Signum: '<S137>/Sign2' */

    /* Sum: '<S137>/Add5' incorporates:
     *  Gain: '<S137>/Gain2'
     *  Product: '<S137>/Multiply4'
     *  Sum: '<S137>/Subtract2'
     */
    rtb_Add2_h += (rtb_Divide_m_idx_2 - u) * 0.5F * rtb_Divide_m_idx_1;

    /* Update for DiscreteIntegrator: '<S97>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S97>/gain1'
     *  Constant: '<S97>/gain2'
     *  Constant: '<S97>/gain3'
     *  DiscreteIntegrator: '<S94>/Discrete-Time Integrator5'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S97>/Multiply'
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

    /* End of Update for DiscreteIntegrator: '<S97>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S122>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_PrevRe_p = (int8_T)rtb_Compare_i;

    /* Update for DiscreteIntegrator: '<S124>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;

    /* Update for DiscreteIntegrator: '<S117>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S117>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE[0] += 0.002F *
      Controller_DW.Integrator_DSTATE[0];

    /* Update for DiscreteIntegrator: '<S122>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S122>/ki'
     *  Product: '<S122>/Multiply'
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

    /* Update for DiscreteIntegrator: '<S124>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] += 0.002F * rtb_Saturation_e;

    /* Update for DiscreteIntegrator: '<S117>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S117>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE[1] += 0.002F *
      Controller_DW.Integrator_DSTATE[1];

    /* Update for DiscreteIntegrator: '<S122>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S122>/ki'
     *  Product: '<S122>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1] +=
      CONTROL_PARAM.MC_VEL_XY_I * rtb_Gain_az * 0.002F;
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

    /* Update for DiscreteIntegrator: '<S124>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] += 0.002F *
      rtb_Divide_m_idx_3;
    Controller_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)rtb_Compare_i;

    /* Update for DiscreteIntegrator: '<S94>/Discrete-Time Integrator5' */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_c = 0U;

    /* Update for DiscreteIntegrator: '<S99>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 0U;

    /* Update for DiscreteIntegrator: '<S94>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S94>/Gain'
     *  Saturate: '<S90>/Saturation'
     *  Sum: '<S94>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0] += (rtb_Divide_m_idx_0 -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S99>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[0] += 0.002F *
      rtb_Multiply_ni[0];

    /* Update for DiscreteIntegrator: '<S94>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S94>/Gain'
     *  Saturate: '<S90>/Saturation'
     *  Sum: '<S94>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1] += (rtb_Add_k -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S99>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[1] += 0.002F *
      rtb_Multiply_ni[1];

    /* Update for DiscreteIntegrator: '<S94>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S94>/Gain'
     *  Saturate: '<S90>/Saturation'
     *  Sum: '<S94>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2] += (rtb_Add1_j4 -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S99>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[2] += 0.002F *
      rtb_Multiply_ni[2];
    Controller_DW.DiscreteTimeIntegrator1_PrevR_k = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Signum: '<S120>/Sign3' incorporates:
     *  Product: '<S120>/Divide'
     *  Sum: '<S120>/Add6'
     */
    rtb_Divide_m_idx_2 = rtb_VdotPg + Controller_ConstB.d;

    /* Signum: '<S120>/Sign4' incorporates:
     *  Product: '<S120>/Divide'
     *  Sum: '<S120>/Subtract3'
     */
    rtb_Divide_m_idx_0 = rtb_VdotPg - Controller_ConstB.d;

    /* Signum: '<S120>/Sign5' incorporates:
     *  Product: '<S120>/Divide'
     */
    if (rtb_VdotPg < 0.0F) {
      rtb_Divide_m_idx_1 = -1.0F;
    } else if (rtb_VdotPg > 0.0F) {
      rtb_Divide_m_idx_1 = 1.0F;
    } else {
      rtb_Divide_m_idx_1 = rtb_VdotPg;
    }

    /* Signum: '<S120>/Sign3' */
    if (rtb_Divide_m_idx_2 < 0.0F) {
      rtb_Divide_m_idx_2 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_2 > 0.0F) {
        rtb_Divide_m_idx_2 = 1.0F;
      }
    }

    /* Signum: '<S120>/Sign4' */
    if (rtb_Divide_m_idx_0 < 0.0F) {
      rtb_Divide_m_idx_0 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_0 > 0.0F) {
        rtb_Divide_m_idx_0 = 1.0F;
      }
    }

    /* Signum: '<S120>/Sign6' incorporates:
     *  Product: '<S120>/Divide'
     */
    if (rtb_VdotPg < 0.0F) {
      rtb_Saturation1 = -1.0F;
    } else if (rtb_VdotPg > 0.0F) {
      rtb_Saturation1 = 1.0F;
    } else {
      rtb_Saturation1 = rtb_VdotPg;
    }

    /* Update for DiscreteIntegrator: '<S117>/Integrator' incorporates:
     *  Constant: '<S120>/const'
     *  Gain: '<S120>/Gain3'
     *  Product: '<S120>/Divide'
     *  Product: '<S120>/Multiply5'
     *  Product: '<S120>/Multiply6'
     *  Sum: '<S120>/Subtract4'
     *  Sum: '<S120>/Subtract5'
     *  Sum: '<S120>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE[0] += ((rtb_VdotPg / Controller_ConstB.d -
      rtb_Divide_m_idx_1) * Controller_ConstB.Gain4 * ((rtb_Divide_m_idx_2 -
      rtb_Divide_m_idx_0) * 0.5F) - rtb_Saturation1 * 58.836F) * 0.002F;

    /* Signum: '<S120>/Sign3' incorporates:
     *  Sum: '<S120>/Add6'
     */
    rtb_Divide_m_idx_2 = rtb_DiscreteTimeIntegrator1_n4 + Controller_ConstB.d;

    /* Signum: '<S120>/Sign4' incorporates:
     *  Sum: '<S120>/Subtract3'
     */
    rtb_Divide_m_idx_0 = rtb_DiscreteTimeIntegrator1_n4 - Controller_ConstB.d;

    /* Signum: '<S120>/Sign5' */
    if (rtb_DiscreteTimeIntegrator1_n4 < 0.0F) {
      rtb_Divide_m_idx_1 = -1.0F;
    } else if (rtb_DiscreteTimeIntegrator1_n4 > 0.0F) {
      rtb_Divide_m_idx_1 = 1.0F;
    } else {
      rtb_Divide_m_idx_1 = rtb_DiscreteTimeIntegrator1_n4;
    }

    /* Signum: '<S120>/Sign3' */
    if (rtb_Divide_m_idx_2 < 0.0F) {
      rtb_Divide_m_idx_2 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_2 > 0.0F) {
        rtb_Divide_m_idx_2 = 1.0F;
      }
    }

    /* Signum: '<S120>/Sign4' */
    if (rtb_Divide_m_idx_0 < 0.0F) {
      rtb_Divide_m_idx_0 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_0 > 0.0F) {
        rtb_Divide_m_idx_0 = 1.0F;
      }
    }

    /* Signum: '<S120>/Sign6' */
    if (rtb_DiscreteTimeIntegrator1_n4 < 0.0F) {
      rtb_Saturation1 = -1.0F;
    } else if (rtb_DiscreteTimeIntegrator1_n4 > 0.0F) {
      rtb_Saturation1 = 1.0F;
    } else {
      rtb_Saturation1 = rtb_DiscreteTimeIntegrator1_n4;
    }

    /* Update for DiscreteIntegrator: '<S117>/Integrator' incorporates:
     *  Constant: '<S120>/const'
     *  Gain: '<S120>/Gain3'
     *  Product: '<S120>/Divide'
     *  Product: '<S120>/Multiply5'
     *  Product: '<S120>/Multiply6'
     *  Sum: '<S120>/Subtract4'
     *  Sum: '<S120>/Subtract5'
     *  Sum: '<S120>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE[1] += ((rtb_DiscreteTimeIntegrator1_n4 /
      Controller_ConstB.d - rtb_Divide_m_idx_1) * Controller_ConstB.Gain4 *
      ((rtb_Divide_m_idx_2 - rtb_Divide_m_idx_0) * 0.5F) - rtb_Saturation1 *
      58.836F) * 0.002F;

    /* Update for DiscreteIntegrator: '<S136>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S136>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_e += 0.002F *
      Controller_DW.Integrator_DSTATE_j;

    /* Update for DiscreteIntegrator: '<S139>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S139>/ki'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S139>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_l += CONTROL_PARAM.MC_VEL_Z_I *
      rtb_Sum * 0.002F;
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

    /* End of Update for DiscreteIntegrator: '<S139>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S141>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_i += 0.002F * rtb_Sign5_f;
    Controller_DW.DiscreteTimeIntegrator1_Prev_ks = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Signum: '<S137>/Sign6' incorporates:
     *  Signum: '<S137>/Sign5'
     */
    if (rtb_Add2_h < 0.0F) {
      rtb_VdotPg = -1.0F;

      /* Signum: '<S137>/Sign5' */
      rtb_Divide_m_idx_1 = -1.0F;
    } else if (rtb_Add2_h > 0.0F) {
      rtb_VdotPg = 1.0F;

      /* Signum: '<S137>/Sign5' */
      rtb_Divide_m_idx_1 = 1.0F;
    } else {
      rtb_VdotPg = rtb_Add2_h;

      /* Signum: '<S137>/Sign5' */
      rtb_Divide_m_idx_1 = rtb_Add2_h;
    }

    /* End of Signum: '<S137>/Sign6' */

    /* Sum: '<S137>/Add6' */
    rtb_Divide_m_idx_2 = rtb_Add2_h + Controller_ConstB.d_i;

    /* Sum: '<S137>/Subtract3' */
    rtb_Divide_m_idx_0 = rtb_Add2_h - Controller_ConstB.d_i;

    /* Signum: '<S137>/Sign3' */
    if (rtb_Divide_m_idx_2 < 0.0F) {
      rtb_Divide_m_idx_2 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_2 > 0.0F) {
        rtb_Divide_m_idx_2 = 1.0F;
      }
    }

    /* End of Signum: '<S137>/Sign3' */

    /* Signum: '<S137>/Sign4' */
    if (rtb_Divide_m_idx_0 < 0.0F) {
      rtb_Divide_m_idx_0 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_0 > 0.0F) {
        rtb_Divide_m_idx_0 = 1.0F;
      }
    }

    /* End of Signum: '<S137>/Sign4' */

    /* Update for DiscreteIntegrator: '<S136>/Integrator' incorporates:
     *  Constant: '<S137>/const'
     *  Gain: '<S137>/Gain3'
     *  Product: '<S137>/Divide'
     *  Product: '<S137>/Multiply5'
     *  Product: '<S137>/Multiply6'
     *  Sum: '<S137>/Subtract4'
     *  Sum: '<S137>/Subtract5'
     *  Sum: '<S137>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE_j += ((rtb_Add2_h / Controller_ConstB.d_i -
      rtb_Divide_m_idx_1) * Controller_ConstB.Gain4_p * ((rtb_Divide_m_idx_2 -
      rtb_Divide_m_idx_0) * 0.5F) - rtb_VdotPg * 78.448F) * 0.002F;
  } else {
    if (Controller_DW.MC_Controller_MODE) {
      Controller_DW.MC_Controller_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S2>/MC_Controller' */

  /* Product: '<S2>/Multiply2' incorporates:
   *  Relay: '<S2>/Relay'
   */
  rtb_Multiply2[0] = (real32_T)Controller_DW.Relay_Mode * Controller_B.Multiply
    [0];

  /* Product: '<S2>/Multiply3' incorporates:
   *  Relay: '<S2>/Relay'
   */
  rtb_Multiply3[0] = (real32_T)Controller_DW.Relay_Mode *
    Controller_B.Multiply1[0];

  /* Product: '<S2>/Multiply' incorporates:
   *  Relay: '<S2>/Relay1'
   */
  rtb_Multiply[0] = (real32_T)Controller_DW.Relay1_Mode *
    Controller_B.Multiply_c[0];

  /* Product: '<S2>/Multiply1' incorporates:
   *  Relay: '<S2>/Relay1'
   */
  rtb_Multiply1[0] = (real32_T)Controller_DW.Relay1_Mode * Controller_B.Switch[3];

  /* Product: '<S2>/Multiply2' incorporates:
   *  Relay: '<S2>/Relay'
   */
  rtb_Multiply2[1] = (real32_T)Controller_DW.Relay_Mode * Controller_B.Multiply
    [1];

  /* Product: '<S2>/Multiply3' incorporates:
   *  Relay: '<S2>/Relay'
   */
  rtb_Multiply3[1] = (real32_T)Controller_DW.Relay_Mode *
    Controller_B.Multiply1[1];

  /* Product: '<S2>/Multiply' incorporates:
   *  Relay: '<S2>/Relay1'
   */
  rtb_Multiply[1] = (real32_T)Controller_DW.Relay1_Mode *
    Controller_B.Multiply_c[1];

  /* Product: '<S2>/Multiply1' incorporates:
   *  Relay: '<S2>/Relay1'
   */
  rtb_Multiply1[1] = (real32_T)Controller_DW.Relay1_Mode * Controller_B.Switch[4];

  /* Product: '<S2>/Multiply2' incorporates:
   *  Relay: '<S2>/Relay'
   */
  rtb_Multiply2[2] = (real32_T)Controller_DW.Relay_Mode * Controller_B.Multiply
    [2];

  /* Product: '<S2>/Multiply3' incorporates:
   *  Relay: '<S2>/Relay'
   */
  rtb_Multiply3[2] = (real32_T)Controller_DW.Relay_Mode *
    Controller_B.Multiply1[2];

  /* Product: '<S2>/Multiply' incorporates:
   *  Relay: '<S2>/Relay1'
   */
  rtb_Multiply[2] = (real32_T)Controller_DW.Relay1_Mode *
    Controller_B.Multiply_c[2];

  /* Product: '<S2>/Multiply1' incorporates:
   *  Relay: '<S2>/Relay1'
   */
  rtb_Multiply1[2] = (real32_T)Controller_DW.Relay1_Mode * Controller_B.Switch[5];

  /* Outputs for Atomic SubSystem: '<S7>/VTOL_Control_Allocation' */
#if AIRFRAME == 1

  /* Output and update for atomic system: '<S143>/VTOL1' */
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

    /* Saturate: '<S160>/Saturation' incorporates:
     *  Bias: '<S160>/Bias'
     *  Bias: '<S160>/Bias1'
     *  Bias: '<S160>/Bias2'
     *  Bias: '<S160>/Bias3'
     *  Constant: '<S160>/Constant'
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

    /* End of Saturate: '<S160>/Saturation' */

    /* Saturate: '<S147>/Saturation1' */
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

    /* End of Saturate: '<S147>/Saturation1' */

    /* Gain: '<S147>/Gain1' incorporates:
     *  Bias: '<S147>/Bias'
     *  Constant: '<S147>/Constant'
     */
    rtb_Gain1_l = ((real32_T)CONTROL_PARAM.MC_OUT_MAX + -1000.0F) * 0.001F;

    /* Saturate: '<S147>/Saturation2' */
    if (rtb_Multiply3[2] > 1.0F) {
      rtb_Saturation3_j = 1.0F;
    } else if (rtb_Multiply3[2] < 0.0F) {
      rtb_Saturation3_j = 0.0F;
    } else {
      rtb_Saturation3_j = rtb_Multiply3[2];
    }

    /* End of Saturate: '<S147>/Saturation2' */
    for (i_p = 0; i_p < 4; i_p++) {
      /* Product: '<S147>/Multiply' */
      rtb_Switch_gr_idx_1_p = Controller_ConstB.VTOL1.pq_column[i_p + 4] *
        rtb_Saturation1_l_idx_1_p + Controller_ConstB.VTOL1.pq_column[i_p] *
        rtb_Saturation1_l_idx_0_p;

      /* Sum: '<S147>/Sum' */
      rtb_Sum_e[i_p] = rtb_Switch_gr_idx_1_p + rtb_Saturation3_j;

      /* Product: '<S147>/Multiply' */
      rtb_floating_yaw[i_p] = rtb_Switch_gr_idx_1_p;
    }

    /* Gain: '<S147>/Gain2' incorporates:
     *  Bias: '<S147>/Bias1'
     *  Constant: '<S147>/Constant1'
     */
    rtb_Saturation1_l_idx_0_p = ((real32_T)CONTROL_PARAM.MC_OUT_MIN + -1000.0F) *
      0.001F;

    /* MinMax: '<S147>/Max' */
    rtb_Switch_gr_idx_1_p = fmaxf(fmaxf(fmaxf(rtb_Sum_e[0], rtb_Sum_e[1]),
      rtb_Sum_e[2]), rtb_Sum_e[3]);

    /* MinMax: '<S147>/Max1' */
    rtb_Saturation1_l_idx_1_p = fminf(fminf(fminf(rtb_Sum_e[0], rtb_Sum_e[1]),
      rtb_Sum_e[2]), rtb_Sum_e[3]);

    /* Switch: '<S154>/Switch' incorporates:
     *  Logic: '<S154>/Logical Operator'
     *  MinMax: '<S147>/Max'
     *  MinMax: '<S147>/Max1'
     *  RelationalOperator: '<S154>/Relational Operator'
     *  RelationalOperator: '<S154>/Relational Operator1'
     */
    if ((rtb_Switch_gr_idx_1_p > rtb_Gain1_l) || (rtb_Saturation1_l_idx_1_p <
         rtb_Saturation1_l_idx_0_p)) {
      /* Sum: '<S154>/Subtract1' */
      rtb_Switch_gr_idx_0_p = rtb_Gain1_l - rtb_Saturation1_l_idx_0_p;

      /* Sum: '<S154>/Subtract' */
      rtb_Subtract_h = rtb_Switch_gr_idx_1_p - rtb_Saturation1_l_idx_1_p;

      /* Switch: '<S154>/Switch1' incorporates:
       *  Constant: '<S154>/Constant3'
       *  Gain: '<S154>/Gain'
       *  Product: '<S154>/Divide'
       *  RelationalOperator: '<S154>/Relational Operator2'
       *  Sum: '<S154>/Add'
       *  Sum: '<S154>/Subtract2'
       *  Sum: '<S154>/Subtract3'
       */
      if (rtb_Subtract_h > rtb_Switch_gr_idx_0_p) {
        rtb_Switch_gr_idx_0_p /= rtb_Subtract_h;
        rtb_Switch_gr_idx_1_p = ((rtb_Gain1_l - rtb_Switch_gr_idx_1_p) +
          (rtb_Saturation1_l_idx_0_p - rtb_Saturation1_l_idx_1_p)) * 0.5F;
      } else {
        rtb_Switch_gr_idx_0_p = 1.0F;

        /* Switch: '<S154>/Switch2' incorporates:
         *  Constant: '<S154>/Constant3'
         *  RelationalOperator: '<S154>/Relational Operator3'
         *  Sum: '<S154>/Subtract4'
         *  Sum: '<S154>/Subtract5'
         */
        if (rtb_Switch_gr_idx_1_p > rtb_Gain1_l) {
          rtb_Switch_gr_idx_1_p = rtb_Gain1_l - rtb_Switch_gr_idx_1_p;
        } else {
          rtb_Switch_gr_idx_1_p = rtb_Saturation1_l_idx_0_p -
            rtb_Saturation1_l_idx_1_p;
        }

        /* End of Switch: '<S154>/Switch2' */
      }

      /* End of Switch: '<S154>/Switch1' */
    } else {
      rtb_Switch_gr_idx_0_p = 1.0F;
      rtb_Switch_gr_idx_1_p = 0.0F;
    }

    /* End of Switch: '<S154>/Switch' */

    /* Sum: '<S147>/Sum1' */
    rtb_Saturation3_j += rtb_Switch_gr_idx_1_p;

    /* Saturate: '<S147>/Saturation3' */
    if (rtb_Saturation3_j > 1.0F) {
      rtb_Saturation3_j = 1.0F;
    } else {
      if (rtb_Saturation3_j < 0.0F) {
        rtb_Saturation3_j = 0.0F;
      }
    }

    /* End of Saturate: '<S147>/Saturation3' */

    /* Sum: '<S147>/Sum2' incorporates:
     *  Product: '<S147>/Multiply1'
     */
    rtb_Switch_gr_idx_1_p = rtb_floating_yaw[0] * rtb_Switch_gr_idx_0_p +
      rtb_Saturation3_j;

    /* Saturate: '<S147>/Saturation4' */
    if (rtb_Switch_gr_idx_1_p > 1.0F) {
      rtb_Switch_gr_idx_1_p = 1.0F;
    } else {
      if (rtb_Switch_gr_idx_1_p < 0.0F) {
        rtb_Switch_gr_idx_1_p = 0.0F;
      }
    }

    /* Sum: '<S147>/Sum3' incorporates:
     *  Product: '<S147>/Multiply2'
     */
    rtb_Sum_e[0] = Controller_ConstB.VTOL1.r_column[0] *
      rtb_Saturation1_l_idx_2_p + rtb_Switch_gr_idx_1_p;

    /* Product: '<S147>/Multiply1' */
    rtb_floating_yaw[0] = rtb_Switch_gr_idx_1_p;

    /* Sum: '<S147>/Sum2' incorporates:
     *  Product: '<S147>/Multiply1'
     */
    rtb_Switch_gr_idx_1_p = rtb_floating_yaw[1] * rtb_Switch_gr_idx_0_p +
      rtb_Saturation3_j;

    /* Saturate: '<S147>/Saturation4' */
    if (rtb_Switch_gr_idx_1_p > 1.0F) {
      rtb_Switch_gr_idx_1_p = 1.0F;
    } else {
      if (rtb_Switch_gr_idx_1_p < 0.0F) {
        rtb_Switch_gr_idx_1_p = 0.0F;
      }
    }

    /* Sum: '<S147>/Sum3' incorporates:
     *  Product: '<S147>/Multiply2'
     */
    rtb_Sum_e[1] = Controller_ConstB.VTOL1.r_column[1] *
      rtb_Saturation1_l_idx_2_p + rtb_Switch_gr_idx_1_p;

    /* Product: '<S147>/Multiply1' */
    rtb_floating_yaw[1] = rtb_Switch_gr_idx_1_p;

    /* Sum: '<S147>/Sum2' incorporates:
     *  Product: '<S147>/Multiply1'
     */
    rtb_Switch_gr_idx_1_p = rtb_floating_yaw[2] * rtb_Switch_gr_idx_0_p +
      rtb_Saturation3_j;

    /* Saturate: '<S147>/Saturation4' */
    if (rtb_Switch_gr_idx_1_p > 1.0F) {
      rtb_Switch_gr_idx_1_p = 1.0F;
    } else {
      if (rtb_Switch_gr_idx_1_p < 0.0F) {
        rtb_Switch_gr_idx_1_p = 0.0F;
      }
    }

    /* Sum: '<S147>/Sum3' incorporates:
     *  Product: '<S147>/Multiply2'
     */
    rtb_Sum_e[2] = Controller_ConstB.VTOL1.r_column[2] *
      rtb_Saturation1_l_idx_2_p + rtb_Switch_gr_idx_1_p;

    /* Product: '<S147>/Multiply1' */
    rtb_floating_yaw[2] = rtb_Switch_gr_idx_1_p;

    /* Sum: '<S147>/Sum2' incorporates:
     *  Product: '<S147>/Multiply1'
     */
    rtb_Switch_gr_idx_1_p = rtb_floating_yaw[3] * rtb_Switch_gr_idx_0_p +
      rtb_Saturation3_j;

    /* Saturate: '<S147>/Saturation4' */
    if (rtb_Switch_gr_idx_1_p > 1.0F) {
      rtb_Switch_gr_idx_1_p = 1.0F;
    } else {
      if (rtb_Switch_gr_idx_1_p < 0.0F) {
        rtb_Switch_gr_idx_1_p = 0.0F;
      }
    }

    /* Sum: '<S147>/Sum3' incorporates:
     *  Product: '<S147>/Multiply2'
     */
    rtb_Sum_e[3] = Controller_ConstB.VTOL1.r_column[3] *
      rtb_Saturation1_l_idx_2_p + rtb_Switch_gr_idx_1_p;

    /* Product: '<S147>/Multiply1' */
    rtb_floating_yaw[3] = rtb_Switch_gr_idx_1_p;

    /* MATLAB Function: '<S147>/R_Remix' */
    Controller_R_Remix(rtb_Sum_e, rtb_Gain1_l, rtb_Saturation1_l_idx_0_p,
                       rtb_floating_yaw);

    /* MultiPortSwitch: '<S150>/Multiport Switch' incorporates:
     *  Constant: '<S151>/Constant1'
     *  Constant: '<S151>/Constant12'
     *  Constant: '<S151>/Constant2'
     *  Constant: '<S151>/Constant7'
     *  DataTypeConversion: '<S160>/Data Type Conversion'
     *  DataTypeConversion: '<S161>/Data Type Conversion'
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
        /* Saturate: '<S161>/Saturation' incorporates:
         *  Constant: '<S161>/Standby'
         *  Reshape: '<S161>/Reshape'
         */
        if (Controller_ConstP.pooled32[i_p] > 2000.0F) {
          rtb_Saturation1_l_idx_2_p = 2000.0F;
        } else if (Controller_ConstP.pooled32[i_p] < 1000.0F) {
          rtb_Saturation1_l_idx_2_p = 1000.0F;
        } else {
          rtb_Saturation1_l_idx_2_p = Controller_ConstP.pooled32[i_p];
        }

        rtb_VariantMergeForOutportactua[i_p] = (uint16_T)fmodf(floorf
          (rtb_Saturation1_l_idx_2_p), 65536.0F);
      }

      /* Saturate: '<S161>/Saturation' incorporates:
       *  Bias: '<S161>/Bias'
       *  Constant: '<S161>/Constant'
       *  DataTypeConversion: '<S161>/Data Type Conversion'
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

      /* Saturate: '<S161>/Saturation' incorporates:
       *  Bias: '<S161>/Bias1'
       *  Constant: '<S161>/Constant'
       *  DataTypeConversion: '<S161>/Data Type Conversion'
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

      /* Saturate: '<S161>/Saturation' incorporates:
       *  Bias: '<S161>/Bias2'
       *  Constant: '<S161>/Constant'
       *  DataTypeConversion: '<S161>/Data Type Conversion'
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

      /* Saturate: '<S161>/Saturation' incorporates:
       *  Bias: '<S161>/Bias3'
       *  Constant: '<S161>/Constant'
       *  DataTypeConversion: '<S161>/Data Type Conversion'
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

      /* SignalConversion: '<S151>/ConcatBufferAtVector Concatenate2In3' incorporates:
       *  Constant: '<S151>/Constant11'
       *  Constant: '<S151>/Constant12'
       */
      rtb_MatrixConcatenate[10] = 0.0F;

      /* SignalConversion: '<S151>/ConcatBufferAtVector Concatenate2In2' incorporates:
       *  Constant: '<S151>/Constant10'
       */
      rtb_MatrixConcatenate[9] = 0.0F;

      /* SignalConversion: '<S151>/ConcatBufferAtVector Concatenate2In1' incorporates:
       *  Constant: '<S151>/Constant9'
       */
      rtb_MatrixConcatenate[8] = 0.0F;

      /* SignalConversion: '<S151>/ConcatBufferAtVector Concatenate1In4' incorporates:
       *  Constant: '<S151>/Constant8'
       */
      rtb_MatrixConcatenate[7] = 0.0F;
      rtb_MatrixConcatenate[6] = CONTROL_PARAM.FW_PITCH_EFFC *
        CONTROL_PARAM.FW_ELEVATOR_DIR;

      /* SignalConversion: '<S151>/ConcatBufferAtVector Concatenate1In2' incorporates:
       *  Constant: '<S151>/Constant6'
       *  Constant: '<S151>/Constant7'
       */
      rtb_MatrixConcatenate[5] = 0.0F;

      /* SignalConversion: '<S151>/ConcatBufferAtVector Concatenate1In1' incorporates:
       *  Constant: '<S151>/Constant5'
       */
      rtb_MatrixConcatenate[4] = 0.0F;

      /* SignalConversion: '<S151>/ConcatBufferAtVector ConcatenateIn4' incorporates:
       *  Constant: '<S151>/Constant4'
       */
      rtb_MatrixConcatenate[3] = 0.0F;

      /* SignalConversion: '<S151>/ConcatBufferAtVector ConcatenateIn3' incorporates:
       *  Constant: '<S151>/Constant3'
       */
      rtb_MatrixConcatenate[2] = 0.0F;
      rtb_MatrixConcatenate[1] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON2_DIR;
      rtb_MatrixConcatenate[0] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON1_DIR;

      /* Saturate: '<S146>/Saturation5' incorporates:
       *  Constant: '<S151>/Constant1'
       *  Constant: '<S151>/Constant2'
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

      /* End of Saturate: '<S146>/Saturation5' */
      for (i_p = 0; i_p < 4; i_p++) {
        /* Bias: '<S146>/Bias' incorporates:
         *  Gain: '<S146>/Gain1'
         *  Product: '<S146>/Multiply1'
         */
        rtb_Saturation5_o[i_p] = 500.0F * (rtb_MatrixConcatenate[i_p + 8] *
          rtb_Saturation3_j + (rtb_MatrixConcatenate[i_p + 4] * rtb_Gain1_l +
          rtb_MatrixConcatenate[i_p] * rtb_Saturation1_l_idx_2_p)) + 1500.0F;

        /* Sum: '<S147>/Sum4' */
        rtb_Saturation1_l_idx_0_p = rtb_Sum_e[i_p] + rtb_floating_yaw[i_p];

        /* Saturate: '<S147>/Saturation5' */
        if (rtb_Saturation1_l_idx_0_p > 1.0F) {
          rtb_Saturation1_l_idx_0_p = 1.0F;
        } else {
          if (rtb_Saturation1_l_idx_0_p < 0.0F) {
            rtb_Saturation1_l_idx_0_p = 0.0F;
          }
        }

        /* End of Saturate: '<S147>/Saturation5' */

        /* DataTypeConversion: '<S147>/Data Type Conversion' incorporates:
         *  Constant: '<S147>/Constant2'
         *  Gain: '<S147>/Gain3'
         *  Sum: '<S147>/Sum5'
         */
        u0_p = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          rtb_Saturation1_l_idx_0_p), 4.2949673E+9F) + 1000U);

        /* Saturate: '<S147>/Saturation' */
        if (u0_p > CONTROL_PARAM.MC_OUT_MAX) {
          rtb_VariantMergeForOutportactua[i_p] = CONTROL_PARAM.MC_OUT_MAX;
        } else if (u0_p < CONTROL_PARAM.MC_OUT_MIN) {
          rtb_VariantMergeForOutportactua[i_p] = CONTROL_PARAM.MC_OUT_MIN;
        } else {
          rtb_VariantMergeForOutportactua[i_p] = u0_p;
        }

        /* End of Saturate: '<S147>/Saturation' */
      }

      /* Saturate: '<S146>/Saturation' */
      if (rtb_Multiply1[0] > 1.0F) {
        rtb_Saturation1_l_idx_2_p = 1.0F;
      } else if (rtb_Multiply1[0] < 0.0F) {
        rtb_Saturation1_l_idx_2_p = 0.0F;
      } else {
        rtb_Saturation1_l_idx_2_p = rtb_Multiply1[0];
      }

      /* End of Saturate: '<S146>/Saturation' */

      /* DataTypeConversion: '<S153>/Data Type Conversion' incorporates:
       *  Constant: '<S153>/Constant1'
       *  Gain: '<S153>/Gain1'
       *  Sum: '<S153>/Sum1'
       */
      u0_p = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
        rtb_Saturation1_l_idx_2_p), 4.2949673E+9F) + 1000U);

      /* Saturate: '<S146>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[4] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[4] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[4] = u0_p;
      }

      /* DataTypeConversion: '<S146>/Data Type Conversion' incorporates:
       *  Bias: '<S146>/Bias1'
       */
      rtb_Saturation1_l_idx_2_p = fmodf(floorf(rtb_Saturation5_o[0] +
        CONTROL_PARAM.SERVO1_BIAS), 65536.0F);
      u0_p = (uint16_T)(rtb_Saturation1_l_idx_2_p < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_l_idx_2_p :
                        (int32_T)(uint16_T)rtb_Saturation1_l_idx_2_p);

      /* Saturate: '<S146>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[5] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[5] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[5] = u0_p;
      }

      /* DataTypeConversion: '<S146>/Data Type Conversion1' incorporates:
       *  Bias: '<S146>/Bias2'
       */
      rtb_Saturation1_l_idx_2_p = fmodf(floorf(rtb_Saturation5_o[1] +
        CONTROL_PARAM.SERVO2_BIAS), 65536.0F);
      u0_p = (uint16_T)(rtb_Saturation1_l_idx_2_p < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_l_idx_2_p :
                        (int32_T)(uint16_T)rtb_Saturation1_l_idx_2_p);

      /* Saturate: '<S146>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[6] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[6] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[6] = u0_p;
      }

      /* DataTypeConversion: '<S146>/Data Type Conversion2' incorporates:
       *  Bias: '<S146>/Bias3'
       */
      rtb_Saturation1_l_idx_2_p = fmodf(floorf(rtb_Saturation5_o[2] +
        CONTROL_PARAM.SERVO3_BIAS), 65536.0F);
      u0_p = (uint16_T)(rtb_Saturation1_l_idx_2_p < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_l_idx_2_p :
                        (int32_T)(uint16_T)rtb_Saturation1_l_idx_2_p);

      /* Saturate: '<S146>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[7] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[7] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[7] = u0_p;
      }

      /* DataTypeConversion: '<S146>/Data Type Conversion3' incorporates:
       *  Bias: '<S146>/Bias4'
       */
      rtb_Saturation1_l_idx_2_p = fmodf(floorf(rtb_Saturation5_o[3] +
        CONTROL_PARAM.SERVO4_BIAS), 65536.0F);
      u0_p = (uint16_T)(rtb_Saturation1_l_idx_2_p < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_l_idx_2_p :
                        (int32_T)(uint16_T)rtb_Saturation1_l_idx_2_p);

      /* Saturate: '<S146>/Saturation1' */
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

    /* End of MultiPortSwitch: '<S150>/Multiport Switch' */
  }

#elif AIRFRAME == 2

  /* Output and update for atomic system: '<S143>/VTOL2' */
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

    /* Saturate: '<S172>/Saturation' incorporates:
     *  Bias: '<S172>/Bias'
     *  Bias: '<S172>/Bias1'
     *  Bias: '<S172>/Bias2'
     *  Bias: '<S172>/Bias3'
     *  Constant: '<S172>/Constant'
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

    /* End of Saturate: '<S172>/Saturation' */

    /* Saturate: '<S163>/Saturation1' */
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

    /* End of Saturate: '<S163>/Saturation1' */

    /* Gain: '<S163>/Gain1' incorporates:
     *  Bias: '<S163>/Bias'
     *  Constant: '<S163>/Constant'
     */
    rtb_Gain1_lm = ((real32_T)CONTROL_PARAM.MC_OUT_MAX + -1000.0F) * 0.001F;

    /* Saturate: '<S163>/Saturation2' */
    if (rtb_Multiply3[2] > 1.0F) {
      rtb_Saturation3_c = 1.0F;
    } else if (rtb_Multiply3[2] < 0.0F) {
      rtb_Saturation3_c = 0.0F;
    } else {
      rtb_Saturation3_c = rtb_Multiply3[2];
    }

    /* End of Saturate: '<S163>/Saturation2' */
    for (i_o = 0; i_o < 4; i_o++) {
      /* Product: '<S163>/Multiply' */
      rtb_Switch_ge_idx_1_o = Controller_ConstB.VTOL2.pq_column[i_o + 4] *
        rtb_Saturation1_p_idx_1_o + Controller_ConstB.VTOL2.pq_column[i_o] *
        rtb_Saturation1_p_idx_0_o;

      /* Sum: '<S163>/Sum' */
      rtb_Sum_m[i_o] = rtb_Switch_ge_idx_1_o + rtb_Saturation3_c;

      /* Product: '<S163>/Multiply' */
      rtb_floating_yaw_n[i_o] = rtb_Switch_ge_idx_1_o;
    }

    /* Gain: '<S163>/Gain2' incorporates:
     *  Bias: '<S163>/Bias1'
     *  Constant: '<S163>/Constant1'
     */
    rtb_Saturation1_p_idx_0_o = ((real32_T)CONTROL_PARAM.MC_OUT_MIN + -1000.0F) *
      0.001F;

    /* MinMax: '<S163>/Max' */
    rtb_Switch_ge_idx_1_o = fmaxf(fmaxf(fmaxf(rtb_Sum_m[0], rtb_Sum_m[1]),
      rtb_Sum_m[2]), rtb_Sum_m[3]);

    /* MinMax: '<S163>/Max1' */
    rtb_Saturation1_p_idx_1_o = fminf(fminf(fminf(rtb_Sum_m[0], rtb_Sum_m[1]),
      rtb_Sum_m[2]), rtb_Sum_m[3]);

    /* Switch: '<S169>/Switch' incorporates:
     *  Logic: '<S169>/Logical Operator'
     *  MinMax: '<S163>/Max'
     *  MinMax: '<S163>/Max1'
     *  RelationalOperator: '<S169>/Relational Operator'
     *  RelationalOperator: '<S169>/Relational Operator1'
     */
    if ((rtb_Switch_ge_idx_1_o > rtb_Gain1_lm) || (rtb_Saturation1_p_idx_1_o <
         rtb_Saturation1_p_idx_0_o)) {
      /* Sum: '<S169>/Subtract1' */
      rtb_Switch_ge_idx_0_o = rtb_Gain1_lm - rtb_Saturation1_p_idx_0_o;

      /* Sum: '<S169>/Subtract' */
      rtb_Subtract_g = rtb_Switch_ge_idx_1_o - rtb_Saturation1_p_idx_1_o;

      /* Switch: '<S169>/Switch1' incorporates:
       *  Constant: '<S169>/Constant3'
       *  Gain: '<S169>/Gain'
       *  Product: '<S169>/Divide'
       *  RelationalOperator: '<S169>/Relational Operator2'
       *  Sum: '<S169>/Add'
       *  Sum: '<S169>/Subtract2'
       *  Sum: '<S169>/Subtract3'
       */
      if (rtb_Subtract_g > rtb_Switch_ge_idx_0_o) {
        rtb_Switch_ge_idx_0_o /= rtb_Subtract_g;
        rtb_Switch_ge_idx_1_o = ((rtb_Gain1_lm - rtb_Switch_ge_idx_1_o) +
          (rtb_Saturation1_p_idx_0_o - rtb_Saturation1_p_idx_1_o)) * 0.5F;
      } else {
        rtb_Switch_ge_idx_0_o = 1.0F;

        /* Switch: '<S169>/Switch2' incorporates:
         *  Constant: '<S169>/Constant3'
         *  RelationalOperator: '<S169>/Relational Operator3'
         *  Sum: '<S169>/Subtract4'
         *  Sum: '<S169>/Subtract5'
         */
        if (rtb_Switch_ge_idx_1_o > rtb_Gain1_lm) {
          rtb_Switch_ge_idx_1_o = rtb_Gain1_lm - rtb_Switch_ge_idx_1_o;
        } else {
          rtb_Switch_ge_idx_1_o = rtb_Saturation1_p_idx_0_o -
            rtb_Saturation1_p_idx_1_o;
        }

        /* End of Switch: '<S169>/Switch2' */
      }

      /* End of Switch: '<S169>/Switch1' */
    } else {
      rtb_Switch_ge_idx_0_o = 1.0F;
      rtb_Switch_ge_idx_1_o = 0.0F;
    }

    /* End of Switch: '<S169>/Switch' */

    /* Sum: '<S163>/Sum1' */
    rtb_Saturation3_c += rtb_Switch_ge_idx_1_o;

    /* Saturate: '<S163>/Saturation3' */
    if (rtb_Saturation3_c > 1.0F) {
      rtb_Saturation3_c = 1.0F;
    } else {
      if (rtb_Saturation3_c < 0.0F) {
        rtb_Saturation3_c = 0.0F;
      }
    }

    /* End of Saturate: '<S163>/Saturation3' */

    /* Sum: '<S163>/Sum2' incorporates:
     *  Product: '<S163>/Multiply1'
     */
    rtb_Switch_ge_idx_1_o = rtb_floating_yaw_n[0] * rtb_Switch_ge_idx_0_o +
      rtb_Saturation3_c;

    /* Saturate: '<S163>/Saturation4' */
    if (rtb_Switch_ge_idx_1_o > 1.0F) {
      rtb_Switch_ge_idx_1_o = 1.0F;
    } else {
      if (rtb_Switch_ge_idx_1_o < 0.0F) {
        rtb_Switch_ge_idx_1_o = 0.0F;
      }
    }

    /* Sum: '<S163>/Sum3' incorporates:
     *  Product: '<S163>/Multiply2'
     */
    rtb_Sum_m[0] = Controller_ConstB.VTOL2.r_column[0] *
      rtb_Saturation1_p_idx_2_o + rtb_Switch_ge_idx_1_o;

    /* Product: '<S163>/Multiply1' */
    rtb_floating_yaw_n[0] = rtb_Switch_ge_idx_1_o;

    /* Sum: '<S163>/Sum2' incorporates:
     *  Product: '<S163>/Multiply1'
     */
    rtb_Switch_ge_idx_1_o = rtb_floating_yaw_n[1] * rtb_Switch_ge_idx_0_o +
      rtb_Saturation3_c;

    /* Saturate: '<S163>/Saturation4' */
    if (rtb_Switch_ge_idx_1_o > 1.0F) {
      rtb_Switch_ge_idx_1_o = 1.0F;
    } else {
      if (rtb_Switch_ge_idx_1_o < 0.0F) {
        rtb_Switch_ge_idx_1_o = 0.0F;
      }
    }

    /* Sum: '<S163>/Sum3' incorporates:
     *  Product: '<S163>/Multiply2'
     */
    rtb_Sum_m[1] = Controller_ConstB.VTOL2.r_column[1] *
      rtb_Saturation1_p_idx_2_o + rtb_Switch_ge_idx_1_o;

    /* Product: '<S163>/Multiply1' */
    rtb_floating_yaw_n[1] = rtb_Switch_ge_idx_1_o;

    /* Sum: '<S163>/Sum2' incorporates:
     *  Product: '<S163>/Multiply1'
     */
    rtb_Switch_ge_idx_1_o = rtb_floating_yaw_n[2] * rtb_Switch_ge_idx_0_o +
      rtb_Saturation3_c;

    /* Saturate: '<S163>/Saturation4' */
    if (rtb_Switch_ge_idx_1_o > 1.0F) {
      rtb_Switch_ge_idx_1_o = 1.0F;
    } else {
      if (rtb_Switch_ge_idx_1_o < 0.0F) {
        rtb_Switch_ge_idx_1_o = 0.0F;
      }
    }

    /* Sum: '<S163>/Sum3' incorporates:
     *  Product: '<S163>/Multiply2'
     */
    rtb_Sum_m[2] = Controller_ConstB.VTOL2.r_column[2] *
      rtb_Saturation1_p_idx_2_o + rtb_Switch_ge_idx_1_o;

    /* Product: '<S163>/Multiply1' */
    rtb_floating_yaw_n[2] = rtb_Switch_ge_idx_1_o;

    /* Sum: '<S163>/Sum2' incorporates:
     *  Product: '<S163>/Multiply1'
     */
    rtb_Switch_ge_idx_1_o = rtb_floating_yaw_n[3] * rtb_Switch_ge_idx_0_o +
      rtb_Saturation3_c;

    /* Saturate: '<S163>/Saturation4' */
    if (rtb_Switch_ge_idx_1_o > 1.0F) {
      rtb_Switch_ge_idx_1_o = 1.0F;
    } else {
      if (rtb_Switch_ge_idx_1_o < 0.0F) {
        rtb_Switch_ge_idx_1_o = 0.0F;
      }
    }

    /* Sum: '<S163>/Sum3' incorporates:
     *  Product: '<S163>/Multiply2'
     */
    rtb_Sum_m[3] = Controller_ConstB.VTOL2.r_column[3] *
      rtb_Saturation1_p_idx_2_o + rtb_Switch_ge_idx_1_o;

    /* Product: '<S163>/Multiply1' */
    rtb_floating_yaw_n[3] = rtb_Switch_ge_idx_1_o;

    /* MATLAB Function: '<S163>/R_Remix' */
    Controller_R_Remix(rtb_Sum_m, rtb_Gain1_lm, rtb_Saturation1_p_idx_0_o,
                       rtb_floating_yaw_n);

    /* MultiPortSwitch: '<S165>/Multiport Switch' incorporates:
     *  Constant: '<S166>/Constant1'
     *  Constant: '<S166>/Constant11'
     *  Constant: '<S166>/Constant12'
     *  Constant: '<S166>/Constant2'
     *  Constant: '<S166>/Constant7'
     *  Constant: '<S166>/Constant8'
     *  DataTypeConversion: '<S172>/Data Type Conversion'
     *  DataTypeConversion: '<S173>/Data Type Conversion'
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
        /* Saturate: '<S173>/Saturation' incorporates:
         *  Constant: '<S173>/Disarm'
         *  Reshape: '<S173>/Reshape'
         */
        if (Controller_ConstP.pooled32[i_o] > 2000.0F) {
          rtb_Saturation1_p_idx_2_o = 2000.0F;
        } else if (Controller_ConstP.pooled32[i_o] < 1000.0F) {
          rtb_Saturation1_p_idx_2_o = 1000.0F;
        } else {
          rtb_Saturation1_p_idx_2_o = Controller_ConstP.pooled32[i_o];
        }

        rtb_VariantMergeForOutportactua[i_o] = (uint16_T)fmodf(floorf
          (rtb_Saturation1_p_idx_2_o), 65536.0F);
      }

      /* Saturate: '<S173>/Saturation' incorporates:
       *  Bias: '<S173>/Bias'
       *  Constant: '<S173>/Constant'
       *  DataTypeConversion: '<S173>/Data Type Conversion'
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

      /* Saturate: '<S173>/Saturation' incorporates:
       *  Bias: '<S173>/Bias1'
       *  Constant: '<S173>/Constant'
       *  DataTypeConversion: '<S173>/Data Type Conversion'
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

      /* Saturate: '<S173>/Saturation' incorporates:
       *  Bias: '<S173>/Bias2'
       *  Constant: '<S173>/Constant'
       *  DataTypeConversion: '<S173>/Data Type Conversion'
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

      /* Saturate: '<S173>/Saturation' incorporates:
       *  Bias: '<S173>/Bias3'
       *  Constant: '<S173>/Constant'
       *  DataTypeConversion: '<S173>/Data Type Conversion'
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

      /* SignalConversion: '<S166>/ConcatBufferAtVector Concatenate2In2' incorporates:
       *  Constant: '<S166>/Constant10'
       *  Constant: '<S166>/Constant11'
       *  Constant: '<S166>/Constant12'
       */
      rtb_MatrixConcatenate_g[9] = 0.0F;

      /* SignalConversion: '<S166>/ConcatBufferAtVector Concatenate2In1' incorporates:
       *  Constant: '<S166>/Constant9'
       */
      rtb_MatrixConcatenate_g[8] = 0.0F;
      rtb_MatrixConcatenate_g[7] = -CONTROL_PARAM.FW_PITCH_EFFC *
        CONTROL_PARAM.FW_TAIL2_DIR;
      rtb_MatrixConcatenate_g[6] = CONTROL_PARAM.FW_PITCH_EFFC *
        CONTROL_PARAM.FW_TAIL1_DIR;

      /* SignalConversion: '<S166>/ConcatBufferAtVector Concatenate1In2' incorporates:
       *  Constant: '<S166>/Constant6'
       *  Constant: '<S166>/Constant7'
       *  Constant: '<S166>/Constant8'
       */
      rtb_MatrixConcatenate_g[5] = 0.0F;

      /* SignalConversion: '<S166>/ConcatBufferAtVector Concatenate1In1' incorporates:
       *  Constant: '<S166>/Constant5'
       */
      rtb_MatrixConcatenate_g[4] = 0.0F;

      /* SignalConversion: '<S166>/ConcatBufferAtVector ConcatenateIn4' incorporates:
       *  Constant: '<S166>/Constant4'
       */
      rtb_MatrixConcatenate_g[3] = 0.0F;

      /* SignalConversion: '<S166>/ConcatBufferAtVector ConcatenateIn3' incorporates:
       *  Constant: '<S166>/Constant3'
       */
      rtb_MatrixConcatenate_g[2] = 0.0F;
      rtb_MatrixConcatenate_g[1] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON2_DIR;
      rtb_MatrixConcatenate_g[0] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON1_DIR;

      /* Saturate: '<S162>/Saturation5' incorporates:
       *  Constant: '<S166>/Constant1'
       *  Constant: '<S166>/Constant2'
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

      /* End of Saturate: '<S162>/Saturation5' */
      for (i_o = 0; i_o < 4; i_o++) {
        /* Bias: '<S162>/Bias' incorporates:
         *  Gain: '<S162>/Gain1'
         *  Product: '<S162>/Multiply1'
         */
        rtb_Saturation5_m[i_o] = 500.0F * (rtb_MatrixConcatenate_g[i_o + 8] *
          rtb_Saturation3_c + (rtb_MatrixConcatenate_g[i_o + 4] * rtb_Gain1_lm +
          rtb_MatrixConcatenate_g[i_o] * rtb_Saturation1_p_idx_2_o)) + 1500.0F;

        /* Sum: '<S163>/Sum4' */
        rtb_Saturation1_p_idx_0_o = rtb_Sum_m[i_o] + rtb_floating_yaw_n[i_o];

        /* Saturate: '<S163>/Saturation5' */
        if (rtb_Saturation1_p_idx_0_o > 1.0F) {
          rtb_Saturation1_p_idx_0_o = 1.0F;
        } else {
          if (rtb_Saturation1_p_idx_0_o < 0.0F) {
            rtb_Saturation1_p_idx_0_o = 0.0F;
          }
        }

        /* End of Saturate: '<S163>/Saturation5' */

        /* DataTypeConversion: '<S163>/Data Type Conversion' incorporates:
         *  Constant: '<S163>/Constant2'
         *  Gain: '<S163>/Gain3'
         *  Sum: '<S163>/Sum5'
         */
        u0_o = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          rtb_Saturation1_p_idx_0_o), 4.2949673E+9F) + 1000U);

        /* Saturate: '<S163>/Saturation' */
        if (u0_o > CONTROL_PARAM.MC_OUT_MAX) {
          rtb_VariantMergeForOutportactua[i_o] = CONTROL_PARAM.MC_OUT_MAX;
        } else if (u0_o < CONTROL_PARAM.MC_OUT_MIN) {
          rtb_VariantMergeForOutportactua[i_o] = CONTROL_PARAM.MC_OUT_MIN;
        } else {
          rtb_VariantMergeForOutportactua[i_o] = u0_o;
        }

        /* End of Saturate: '<S163>/Saturation' */
      }

      /* Saturate: '<S162>/Saturation4' */
      if (rtb_Multiply1[0] > 1.0F) {
        rtb_Saturation1_p_idx_2_o = 1.0F;
      } else if (rtb_Multiply1[0] < 0.0F) {
        rtb_Saturation1_p_idx_2_o = 0.0F;
      } else {
        rtb_Saturation1_p_idx_2_o = rtb_Multiply1[0];
      }

      /* End of Saturate: '<S162>/Saturation4' */

      /* DataTypeConversion: '<S168>/Data Type Conversion' incorporates:
       *  Constant: '<S168>/Constant1'
       *  Gain: '<S168>/Gain1'
       *  Sum: '<S168>/Sum1'
       */
      u0_o = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
        rtb_Saturation1_p_idx_2_o), 4.2949673E+9F) + 1000U);

      /* Saturate: '<S162>/Saturation1' */
      if (u0_o > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[4] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_o < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[4] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[4] = u0_o;
      }

      /* DataTypeConversion: '<S162>/Data Type Conversion' incorporates:
       *  Bias: '<S162>/Bias1'
       */
      rtb_Saturation1_p_idx_2_o = fmodf(floorf(rtb_Saturation5_m[0] +
        CONTROL_PARAM.SERVO1_BIAS), 65536.0F);
      u0_o = (uint16_T)(rtb_Saturation1_p_idx_2_o < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_p_idx_2_o :
                        (int32_T)(uint16_T)rtb_Saturation1_p_idx_2_o);

      /* Saturate: '<S162>/Saturation1' */
      if (u0_o > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[5] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_o < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[5] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[5] = u0_o;
      }

      /* DataTypeConversion: '<S162>/Data Type Conversion1' incorporates:
       *  Bias: '<S162>/Bias2'
       */
      rtb_Saturation1_p_idx_2_o = fmodf(floorf(rtb_Saturation5_m[1] +
        CONTROL_PARAM.SERVO2_BIAS), 65536.0F);
      u0_o = (uint16_T)(rtb_Saturation1_p_idx_2_o < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_p_idx_2_o :
                        (int32_T)(uint16_T)rtb_Saturation1_p_idx_2_o);

      /* Saturate: '<S162>/Saturation1' */
      if (u0_o > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[6] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_o < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[6] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[6] = u0_o;
      }

      /* DataTypeConversion: '<S162>/Data Type Conversion2' incorporates:
       *  Bias: '<S162>/Bias3'
       */
      rtb_Saturation1_p_idx_2_o = fmodf(floorf(rtb_Saturation5_m[2] +
        CONTROL_PARAM.SERVO3_BIAS), 65536.0F);
      u0_o = (uint16_T)(rtb_Saturation1_p_idx_2_o < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_p_idx_2_o :
                        (int32_T)(uint16_T)rtb_Saturation1_p_idx_2_o);

      /* Saturate: '<S162>/Saturation1' */
      if (u0_o > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[7] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_o < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[7] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[7] = u0_o;
      }

      /* DataTypeConversion: '<S162>/Data Type Conversion3' incorporates:
       *  Bias: '<S162>/Bias4'
       */
      rtb_Saturation1_p_idx_2_o = fmodf(floorf(rtb_Saturation5_m[3] +
        CONTROL_PARAM.SERVO4_BIAS), 65536.0F);
      u0_o = (uint16_T)(rtb_Saturation1_p_idx_2_o < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_p_idx_2_o :
                        (int32_T)(uint16_T)rtb_Saturation1_p_idx_2_o);

      /* Saturate: '<S162>/Saturation1' */
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

    /* End of MultiPortSwitch: '<S165>/Multiport Switch' */
  }

#endif

  /* End of Outputs for SubSystem: '<S7>/VTOL_Control_Allocation' */

  /* Outport: '<Root>/Control_Out' incorporates:
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   *  Reshape: '<S142>/Reshape'
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

  /* Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S9>/Gain'
   *  Sum: '<S9>/Sum5'
   */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;
  Controller_DW.DiscreteTimeIntegrator5_DSTATE += ((real32_T)
    rtb_MultiportSwitch_idx_1 - Controller_DW.DiscreteTimeIntegrator5_DSTATE) *
    3.14159274F * 0.002F;

  /* Update for DiscreteIntegrator: '<S8>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S8>/Gain'
   *  Sum: '<S8>/Sum5'
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
  /* Start for Constant: '<S139>/Constant' */
  Controller_B.Constant = CONTROL_PARAM.MC_VEL_Z_I_MIN;

  /* End of Start for SubSystem: '<S2>/MC_Controller' */

  /* InitializeConditions for DiscreteIntegrator: '<S9>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S8>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_o = 1U;

  /* SystemInitialize for Enabled SubSystem: '<S2>/FW_Controller' */
  /* InitializeConditions for DiscreteIntegrator: '<S64>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_i = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S34>/Integrator1' */
  Controller_DW.Integrator1_DSTATE_c = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S36>/Integrator1' */
  Controller_DW.Integrator1_DSTATE_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S23>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S23>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S39>/ ' */
  Controller_DW._DSTATE = 0.25F;

  /* InitializeConditions for DiscreteIntegrator: '<S60>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_n = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_d = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S59>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_h = 1U;
  Controller_DW.DiscreteTimeIntegrator1_Prev_dx = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S56>/ ' */
  Controller_DW._DSTATE_h = Controller_ConstB.Zero1;
  if (Controller_DW._DSTATE_h >= CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
    Controller_DW._DSTATE_h = CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
  } else {
    if (Controller_DW._DSTATE_h <= -CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
      Controller_DW._DSTATE_h = -CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
    }
  }

  Controller_DW._PrevResetState = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S56>/ ' */

  /* InitializeConditions for DiscreteIntegrator: '<S57>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_f = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_b = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S36>/Integrator' */
  Controller_DW.Integrator_DSTATE_d = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S34>/Integrator' */
  Controller_DW.Integrator_DSTATE_n = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S2>/FW_Controller' */

  /* SystemInitialize for Enabled SubSystem: '<S2>/MC_Controller' */
  /* InitializeConditions for DiscreteIntegrator: '<S97>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S97>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S122>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_PrevRe_p = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S124>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S94>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_c = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S99>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_k = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S117>/Integrator1' */
  Controller_DW.Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S122>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S117>/Integrator' */
  Controller_DW.Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S117>/Integrator1' */
  Controller_DW.Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S122>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S117>/Integrator' */
  Controller_DW.Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S136>/Integrator1' */
  Controller_DW.Integrator1_DSTATE_e = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S139>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S139>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S141>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 1U;
  Controller_DW.DiscreteTimeIntegrator1_Prev_ks = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S136>/Integrator' */
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
