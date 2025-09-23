/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.799
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Sep 23 16:31:22 2025
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
                                        *   '<S167>/hover_throttle'
                                        *   '<S53>/FF'
                                        *   '<S75>/P_control'
                                        *   '<S76>/P_control'
                                        *   '<S77>/Kv'
                                        *   '<S147>/Saturation'
                                        *   '<S183>/Bias1'
                                        *   '<S183>/Bias2'
                                        *   '<S183>/Bias3'
                                        *   '<S183>/Bias4'
                                        *   '<S183>/Saturation1'
                                        *   '<S184>/Constant'
                                        *   '<S184>/Constant1'
                                        *   '<S184>/Saturation'
                                        *   '<S199>/Bias1'
                                        *   '<S199>/Bias2'
                                        *   '<S199>/Bias3'
                                        *   '<S199>/Bias4'
                                        *   '<S199>/Saturation1'
                                        *   '<S200>/Constant'
                                        *   '<S200>/Constant1'
                                        *   '<S200>/Saturation'
                                        *   '<S57>/trim_speed'
                                        *   '<S58>/trim_speed'
                                        *   '<S62>/Saturation'
                                        *   '<S91>/Gain'
                                        *   '<S92>/ '
                                        *   '<S92>/Gain3'
                                        *   '<S94>/Gain'
                                        *   '<S95>/Gain'
                                        *   '<S115>/Saturation'
                                        *   '<S115>/Saturation1'
                                        *   '<S115>/Saturation2'
                                        *   '<S158>/kd'
                                        *   '<S158>/Saturation'
                                        *   '<S159>/ki'
                                        *   '<S159>/Discrete-Time Integrator'
                                        *   '<S160>/kp'
                                        *   '<S175>/kd'
                                        *   '<S175>/Saturation'
                                        *   '<S176>/Constant'
                                        *   '<S176>/ki'
                                        *   '<S176>/Discrete-Time Integrator'
                                        *   '<S177>/kp'
                                        *   '<S188>/Constant1'
                                        *   '<S188>/Constant12'
                                        *   '<S188>/Constant2'
                                        *   '<S188>/Constant7'
                                        *   '<S197>/Bias'
                                        *   '<S197>/Bias1'
                                        *   '<S197>/Bias2'
                                        *   '<S197>/Bias3'
                                        *   '<S198>/Bias'
                                        *   '<S198>/Bias1'
                                        *   '<S198>/Bias2'
                                        *   '<S198>/Bias3'
                                        *   '<S203>/Constant1'
                                        *   '<S203>/Constant11'
                                        *   '<S203>/Constant12'
                                        *   '<S203>/Constant2'
                                        *   '<S203>/Constant7'
                                        *   '<S203>/Constant8'
                                        *   '<S209>/Bias'
                                        *   '<S209>/Bias1'
                                        *   '<S209>/Bias2'
                                        *   '<S209>/Bias3'
                                        *   '<S210>/Bias'
                                        *   '<S210>/Bias1'
                                        *   '<S210>/Bias2'
                                        *   '<S210>/Bias3'
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
                                        *   '<S128>/Gain'
                                        *   '<S128>/Gain1'
                                        *   '<S140>/Constant1'
                                        *   '<S140>/Constant2'
                                        *   '<S133>/gain1'
                                        *   '<S133>/gain2'
                                        *   '<S133>/gain3'
                                        *   '<S133>/Saturation'
                                        *   '<S134>/gain1'
                                        *   '<S134>/gain2'
                                        *   '<S134>/gain3'
                                        *   '<S134>/Discrete-Time Integrator'
                                        *   '<S135>/gain1'
                                        *   '<S135>/gain2'
                                        *   '<S135>/gain3'
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
 *    '<S184>/R_Remix'
 *    '<S200>/R_Remix'
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
  boolean_T rtb_Compare_f;
  real32_T rtb_DiscreteTimeIntegrator1_n4;
  real32_T rtb_Gain_az;
  real32_T rtb_VdotPg;
  real32_T rtb_Gain_ow;
  real32_T rtb_fw_rate_err_B[3];
  boolean_T rtb_LogicalOperator_h;
  real32_T rtb_Sign5_f;
  real32_T rtb_MatrixConcatenate1[9];
  real32_T rtb_Multiply_ni[3];
  real32_T rtb_thor;
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

  /* DiscreteIntegrator: '<S10>/Discrete-Time Integrator5' */
  if (Controller_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    Controller_DW.DiscreteTimeIntegrator5_DSTATE = (real32_T)
      rtb_MultiportSwitch_idx_1;
  }

  /* Relay: '<S2>/Relay' incorporates:
   *  DiscreteIntegrator: '<S10>/Discrete-Time Integrator5'
   */
  if (Controller_DW.DiscreteTimeIntegrator5_DSTATE >= 0.3F) {
    Controller_DW.Relay_Mode = true;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator5_DSTATE <= 0.1F) {
      Controller_DW.Relay_Mode = false;
    }
  }

  /* DiscreteIntegrator: '<S9>/Discrete-Time Integrator5' */
  if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_o != 0) {
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_k = (real32_T)
      rtb_MultiportSwitch_idx_0;
  }

  /* Relay: '<S2>/Relay1' incorporates:
   *  DiscreteIntegrator: '<S9>/Discrete-Time Integrator5'
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
      /* InitializeConditions for DiscreteIntegrator: '<S101>/Discrete-Time Integrator5' */
      Controller_DW.DiscreteTimeIntegrator5_IC_LO_i = 1U;

      /* InitializeConditions for DiscreteIntegrator: '<S70>/Integrator1' */
      Controller_DW.Integrator1_DSTATE_c = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S73>/Integrator1' */
      Controller_DW.Integrator1_DSTATE_j = 0.0F;

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

      /* InitializeConditions for DiscreteIntegrator: '<S97>/Discrete-Time Integrator1' */
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_n = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevR_d = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S95>/ ' */
      Controller_DW._DSTATE = Controller_ConstB.Zero;
      if (Controller_DW._DSTATE >= 1.0F) {
        Controller_DW._DSTATE = 1.0F;
      } else {
        if (Controller_DW._DSTATE <= 0.0F) {
          Controller_DW._DSTATE = 0.0F;
        }
      }

      Controller_DW._PrevResetState = 0;

      /* End of InitializeConditions for DiscreteIntegrator: '<S95>/ ' */

      /* InitializeConditions for DiscreteIntegrator: '<S96>/Discrete-Time Integrator1' */
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_h = 1U;
      Controller_DW.DiscreteTimeIntegrator1_Prev_dx = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S92>/ ' */
      Controller_DW._DSTATE_h = Controller_ConstB.Zero1;
      if (Controller_DW._DSTATE_h >= CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
        Controller_DW._DSTATE_h = CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
      } else {
        if (Controller_DW._DSTATE_h <= -CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
          Controller_DW._DSTATE_h = -CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
        }
      }

      Controller_DW._PrevResetState_b = 0;

      /* End of InitializeConditions for DiscreteIntegrator: '<S92>/ ' */

      /* InitializeConditions for DiscreteIntegrator: '<S93>/Discrete-Time Integrator1' */
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_f = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevR_b = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S73>/Integrator' */
      Controller_DW.Integrator_DSTATE_d = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S70>/Integrator' */
      Controller_DW.Integrator_DSTATE_n = 0.0F;
      Controller_DW.FW_Controller_MODE = true;
    }

    /* SignalConversion: '<S80>/TmpSignal ConversionAtMultiplyInport2' incorporates:
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
      rtb_Divide_m_idx_2 = Controller_U.INS_Out.airspeed;
    } else {
      /* Sqrt: '<S108>/Sqrt' incorporates:
       *  Math: '<S108>/Square'
       *  Sum: '<S108>/Sum of Elements'
       */
      rtb_Saturation1 = sqrtf(((Controller_U.INS_Out.quat[0] *
        Controller_U.INS_Out.quat[0] + Controller_U.INS_Out.quat[1] *
        Controller_U.INS_Out.quat[1]) + Controller_U.INS_Out.quat[2] *
        Controller_U.INS_Out.quat[2]) + Controller_U.INS_Out.quat[3] *
        Controller_U.INS_Out.quat[3]);

      /* Product: '<S104>/Divide' incorporates:
       *  Sqrt: '<S108>/Sqrt'
       */
      rtb_Divide_m_idx_0 = Controller_U.INS_Out.quat[0] / rtb_Saturation1;
      rtb_Divide_m_idx_1 = Controller_U.INS_Out.quat[1] / rtb_Saturation1;
      rtb_Divide_m_idx_2 = Controller_U.INS_Out.quat[2] / rtb_Saturation1;
      rtb_Divide_m_idx_3 = Controller_U.INS_Out.quat[3] / rtb_Saturation1;

      /* Math: '<S107>/Square' incorporates:
       *  Math: '<S105>/Square'
       *  Math: '<S106>/Square'
       */
      rtb_thor = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_0;

      /* Math: '<S107>/Square2' incorporates:
       *  Math: '<S105>/Square2'
       *  Math: '<S106>/Square2'
       */
      rtb_Gain_az = rtb_Divide_m_idx_2 * rtb_Divide_m_idx_2;

      /* Math: '<S107>/Square1' incorporates:
       *  Math: '<S105>/Square1'
       *  Math: '<S106>/Square1'
       */
      rtb_Saturation1 = rtb_Divide_m_idx_1 * rtb_Divide_m_idx_1;

      /* Math: '<S107>/Square3' incorporates:
       *  Math: '<S105>/Square3'
       *  Math: '<S106>/Square3'
       */
      rtb_Add_k = rtb_Divide_m_idx_3 * rtb_Divide_m_idx_3;

      /* Sum: '<S107>/Subtract' incorporates:
       *  Math: '<S107>/Square'
       *  Math: '<S107>/Square1'
       *  Math: '<S107>/Square2'
       *  Math: '<S107>/Square3'
       *  Sum: '<S107>/Add'
       *  Sum: '<S107>/Add1'
       */
      rtb_MatrixConcatenate1[8] = (rtb_thor + rtb_Add_k) - (rtb_Saturation1 +
        rtb_Gain_az);

      /* Product: '<S107>/Multiply2' incorporates:
       *  Product: '<S106>/Multiply2'
       */
      rtb_Add1_j4 = rtb_Divide_m_idx_2 * rtb_Divide_m_idx_3;

      /* Product: '<S107>/Multiply3' incorporates:
       *  Product: '<S106>/Multiply3'
       */
      rtb_Gain_ow = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_1;

      /* Gain: '<S107>/Gain1' incorporates:
       *  Product: '<S107>/Multiply2'
       *  Product: '<S107>/Multiply3'
       *  Sum: '<S107>/Add2'
       */
      rtb_MatrixConcatenate1[7] = (rtb_Add1_j4 + rtb_Gain_ow) * 2.0F;

      /* Product: '<S107>/Multiply' incorporates:
       *  Product: '<S105>/Multiply2'
       */
      rtb_Add2_h = rtb_Divide_m_idx_1 * rtb_Divide_m_idx_3;

      /* Product: '<S107>/Multiply1' incorporates:
       *  Product: '<S105>/Multiply3'
       */
      rtb_DiscreteTimeIntegrator1_n4 = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_2;

      /* Gain: '<S107>/Gain' incorporates:
       *  Product: '<S107>/Multiply'
       *  Product: '<S107>/Multiply1'
       *  Sum: '<S107>/Subtract2'
       */
      rtb_MatrixConcatenate1[6] = (rtb_Add2_h - rtb_DiscreteTimeIntegrator1_n4) *
        2.0F;

      /* Gain: '<S106>/Gain1' incorporates:
       *  Sum: '<S106>/Subtract1'
       */
      rtb_MatrixConcatenate1[5] = (rtb_Add1_j4 - rtb_Gain_ow) * 2.0F;

      /* Sum: '<S106>/Subtract' incorporates:
       *  Sum: '<S106>/Add'
       *  Sum: '<S106>/Add1'
       */
      rtb_MatrixConcatenate1[4] = (rtb_thor + rtb_Gain_az) - (rtb_Saturation1 +
        rtb_Add_k);

      /* Product: '<S106>/Multiply' incorporates:
       *  Product: '<S105>/Multiply'
       */
      rtb_Add1_j4 = rtb_Divide_m_idx_1 * rtb_Divide_m_idx_2;

      /* Product: '<S106>/Multiply1' incorporates:
       *  Product: '<S105>/Multiply1'
       */
      rtb_Gain_ow = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_3;

      /* Gain: '<S106>/Gain' incorporates:
       *  Product: '<S106>/Multiply'
       *  Product: '<S106>/Multiply1'
       *  Sum: '<S106>/Add3'
       */
      rtb_MatrixConcatenate1[3] = (rtb_Add1_j4 + rtb_Gain_ow) * 2.0F;

      /* Gain: '<S105>/Gain1' incorporates:
       *  Sum: '<S105>/Add2'
       */
      rtb_MatrixConcatenate1[2] = (rtb_Add2_h + rtb_DiscreteTimeIntegrator1_n4) *
        2.0F;

      /* Gain: '<S105>/Gain' incorporates:
       *  Sum: '<S105>/Subtract1'
       */
      rtb_MatrixConcatenate1[1] = (rtb_Add1_j4 - rtb_Gain_ow) * 2.0F;

      /* Sum: '<S105>/Subtract' incorporates:
       *  Sum: '<S105>/Add'
       *  Sum: '<S105>/Add1'
       */
      rtb_MatrixConcatenate1[0] = (rtb_thor + rtb_Saturation1) - (rtb_Gain_az +
        rtb_Add_k);

      /* Product: '<S102>/Multiply' */
      for (i = 0; i < 3; i++) {
        rtb_MatrixConcatenate1_0[i] = rtb_MatrixConcatenate1[i + 6] *
          rtb_TmpSignalConversionAtMultip[2] + (rtb_MatrixConcatenate1[i + 3] *
          rtb_TmpSignalConversionAtMultip[1] + rtb_MatrixConcatenate1[i] *
          rtb_TmpSignalConversionAtMultip[0]);
      }

      /* End of Product: '<S102>/Multiply' */
      rtb_Divide_m_idx_2 = rtb_MatrixConcatenate1_0[0];
    }

    /* End of Switch: '<S14>/Switch' */

    /* Saturate: '<S14>/Saturation1' */
    if (rtb_Divide_m_idx_2 > 100.0F) {
      rtb_Saturation1 = 100.0F;
    } else if (rtb_Divide_m_idx_2 < 0.1F) {
      rtb_Saturation1 = 0.1F;
    } else {
      rtb_Saturation1 = rtb_Divide_m_idx_2;
    }

    /* End of Saturate: '<S14>/Saturation1' */

    /* DiscreteIntegrator: '<S101>/Discrete-Time Integrator5' */
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
      rtb_Divide_m_idx_2 = Controller_U.FMS_Out.phi_cmd;
    } else {
      /* Trigonometry: '<S50>/Atan' incorporates:
       *  DiscreteIntegrator: '<S70>/Integrator1'
       *  Gain: '<S50>/g_force'
       */
      rtb_Divide_m_idx_2 = atanf(0.101936802F *
        Controller_DW.Integrator1_DSTATE_c);

      /* Saturate: '<S50>/Saturation' */
      if (rtb_Divide_m_idx_2 > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_Divide_m_idx_2 = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_Divide_m_idx_2 < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
          rtb_Divide_m_idx_2 = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
        }
      }

      /* End of Saturate: '<S50>/Saturation' */
    }

    /* End of Switch: '<S63>/Switch' */

    /* Switch: '<S63>/Switch1' incorporates:
     *  Constant: '<S69>/Constant'
     *  DiscreteIntegrator: '<S73>/Integrator1'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S69>/Compare'
     */
    if (Controller_U.FMS_Out.ctrl_mode == 3) {
      rtb_Divide_m_idx_0 = Controller_U.FMS_Out.theta_cmd;
    } else {
      rtb_Divide_m_idx_0 = Controller_DW.Integrator1_DSTATE_j;
    }

    /* End of Switch: '<S63>/Switch1' */

    /* Saturate: '<S64>/Saturation' */
    if (rtb_Divide_m_idx_2 > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Divide_m_idx_1 = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else if (rtb_Divide_m_idx_2 < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Divide_m_idx_1 = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      rtb_Divide_m_idx_1 = rtb_Divide_m_idx_2;
    }

    /* Reshape: '<S54>/Reshape' incorporates:
     *  Constant: '<S65>/Constant1'
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S65>/Multiply'
     *  Sum: '<S64>/Sum'
     */
    Controller_B.Reshape[0] = (rtb_Divide_m_idx_1 - Controller_U.INS_Out.phi) *
      CONTROL_PARAM.FW_ROLL_P;

    /* Bias: '<S64>/Pitch Offset' */
    rtb_Divide_m_idx_1 = rtb_Divide_m_idx_0 + CONTROL_PARAM.FW_PITCH_OFFSET;

    /* Saturate: '<S64>/Saturation' */
    if (rtb_Divide_m_idx_1 > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Divide_m_idx_1 = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_Divide_m_idx_1 < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_Divide_m_idx_1 = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      }
    }

    /* Reshape: '<S54>/Reshape' incorporates:
     *  Constant: '<S65>/Constant2'
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S65>/Multiply'
     *  Sum: '<S64>/Sum'
     */
    Controller_B.Reshape[1] = (rtb_Divide_m_idx_1 - Controller_U.INS_Out.theta) *
      CONTROL_PARAM.FW_PITCH_P;

    /* Product: '<S67>/Divide' incorporates:
     *  Constant: '<S67>/Constant'
     *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator5'
     */
    rtb_Divide_m_idx_1 = 9.81F / Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;

    /* Saturate: '<S67>/Saturation' */
    if (rtb_Divide_m_idx_1 > 1.0F) {
      rtb_Divide_m_idx_1 = 1.0F;
    } else {
      if (rtb_Divide_m_idx_1 < 0.2F) {
        rtb_Divide_m_idx_1 = 0.2F;
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
    rtb_Divide_m_idx_1 = tanf(rtb_Divide_m_idx_2) * arm_cos_f32
      (rtb_Divide_m_idx_0) * rtb_Divide_m_idx_1 +
      Controller_U.FMS_Out.psi_rate_cmd;

    /* Saturate: '<S62>/Saturation' */
    if (rtb_Divide_m_idx_1 > CONTROL_PARAM.FW_YAW_RATE_LIM) {
      /* Reshape: '<S54>/Reshape' */
      Controller_B.Reshape[2] = CONTROL_PARAM.FW_YAW_RATE_LIM;
    } else if (rtb_Divide_m_idx_1 < -CONTROL_PARAM.FW_YAW_RATE_LIM) {
      /* Reshape: '<S54>/Reshape' */
      Controller_B.Reshape[2] = -CONTROL_PARAM.FW_YAW_RATE_LIM;
    } else {
      /* Reshape: '<S54>/Reshape' */
      Controller_B.Reshape[2] = rtb_Divide_m_idx_1;
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
    rtb_thor = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Sum: '<S55>/Add1' incorporates:
     *  Product: '<S55>/Multiply1'
     *  Product: '<S55>/Multiply3'
     *  Trigonometry: '<S55>/Cos'
     *  Trigonometry: '<S55>/Cos1'
     *  Trigonometry: '<S55>/Sin'
     */
    rtb_Add1_j4 = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_1 *
      Controller_B.Reshape[2] + rtb_thor * Controller_B.Reshape[1];

    /* Sum: '<S55>/Add2' incorporates:
     *  Product: '<S55>/Multiply4'
     *  Product: '<S55>/Multiply5'
     *  Trigonometry: '<S55>/Cos'
     *  Trigonometry: '<S55>/Cos1'
     *  Trigonometry: '<S55>/Sin'
     */
    rtb_Add2_h = rtb_thor * rtb_Divide_m_idx_1 * Controller_B.Reshape[2] -
      rtb_Divide_m_idx_0 * Controller_B.Reshape[1];

    /* Sum: '<S53>/Minus2' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_fw_rate_err_B[0] = rtb_Add_k - Controller_U.INS_Out.p;
    rtb_fw_rate_err_B[1] = rtb_Add1_j4 - Controller_U.INS_Out.q;
    rtb_fw_rate_err_B[2] = rtb_Add2_h - Controller_U.INS_Out.r;

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

    /* S-Function (sfix_bitop): '<S80>/Bitwise AND' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  S-Function (sfix_bitop): '<S81>/Bitwise AND'
     */
    tmp = Controller_U.INS_Out.flag & 16U;

    /* Switch: '<S80>/Switch' incorporates:
     *  Constant: '<S81>/Constant'
     *  Inport: '<Root>/INS_Out'
     *  S-Function (sfix_bitop): '<S80>/Bitwise AND'
     *  Switch: '<S81>/Switch'
     */
    if (tmp > 0U) {
      /* Sqrt: '<S88>/Sqrt' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Math: '<S88>/Square'
       *  Sum: '<S88>/Sum of Elements'
       */
      rtb_thor = sqrtf(((Controller_U.INS_Out.quat[0] *
                         Controller_U.INS_Out.quat[0] +
                         Controller_U.INS_Out.quat[1] *
                         Controller_U.INS_Out.quat[1]) +
                        Controller_U.INS_Out.quat[2] *
                        Controller_U.INS_Out.quat[2]) +
                       Controller_U.INS_Out.quat[3] * Controller_U.INS_Out.quat
                       [3]);

      /* Product: '<S84>/Divide' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Sqrt: '<S88>/Sqrt'
       */
      rtb_Divide_m_idx_0 = Controller_U.INS_Out.quat[0] / rtb_thor;
      rtb_Divide_m_idx_1 = Controller_U.INS_Out.quat[1] / rtb_thor;
      rtb_Divide_m_idx_2 = Controller_U.INS_Out.quat[2] / rtb_thor;
      rtb_Divide_m_idx_3 = Controller_U.INS_Out.quat[3] / rtb_thor;

      /* Sum: '<S87>/Subtract' incorporates:
       *  Math: '<S87>/Square'
       *  Math: '<S87>/Square1'
       *  Math: '<S87>/Square2'
       *  Math: '<S87>/Square3'
       *  Sum: '<S87>/Add'
       *  Sum: '<S87>/Add1'
       */
      rtb_MatrixConcatenate1[8] = (rtb_Divide_m_idx_0 * rtb_Divide_m_idx_0 +
        rtb_Divide_m_idx_3 * rtb_Divide_m_idx_3) - (rtb_Divide_m_idx_1 *
        rtb_Divide_m_idx_1 + rtb_Divide_m_idx_2 * rtb_Divide_m_idx_2);

      /* Gain: '<S87>/Gain1' incorporates:
       *  Product: '<S87>/Multiply2'
       *  Product: '<S87>/Multiply3'
       *  Sum: '<S87>/Add2'
       */
      rtb_MatrixConcatenate1[7] = (rtb_Divide_m_idx_2 * rtb_Divide_m_idx_3 +
        rtb_Divide_m_idx_0 * rtb_Divide_m_idx_1) * 2.0F;

      /* Gain: '<S87>/Gain' incorporates:
       *  Product: '<S87>/Multiply'
       *  Product: '<S87>/Multiply1'
       *  Sum: '<S87>/Subtract2'
       */
      rtb_MatrixConcatenate1[6] = (rtb_Divide_m_idx_1 * rtb_Divide_m_idx_3 -
        rtb_Divide_m_idx_0 * rtb_Divide_m_idx_2) * 2.0F;

      /* Gain: '<S86>/Gain1' incorporates:
       *  Product: '<S86>/Multiply2'
       *  Product: '<S86>/Multiply3'
       *  Sum: '<S86>/Subtract1'
       */
      rtb_MatrixConcatenate1[5] = (rtb_Divide_m_idx_2 * rtb_Divide_m_idx_3 -
        rtb_Divide_m_idx_0 * rtb_Divide_m_idx_1) * 2.0F;

      /* Sum: '<S86>/Subtract' incorporates:
       *  Math: '<S86>/Square'
       *  Math: '<S86>/Square1'
       *  Math: '<S86>/Square2'
       *  Math: '<S86>/Square3'
       *  Sum: '<S86>/Add'
       *  Sum: '<S86>/Add1'
       */
      rtb_MatrixConcatenate1[4] = (rtb_Divide_m_idx_0 * rtb_Divide_m_idx_0 +
        rtb_Divide_m_idx_2 * rtb_Divide_m_idx_2) - (rtb_Divide_m_idx_1 *
        rtb_Divide_m_idx_1 + rtb_Divide_m_idx_3 * rtb_Divide_m_idx_3);

      /* Gain: '<S86>/Gain' incorporates:
       *  Product: '<S86>/Multiply'
       *  Product: '<S86>/Multiply1'
       *  Sum: '<S86>/Add3'
       */
      rtb_MatrixConcatenate1[3] = (rtb_Divide_m_idx_1 * rtb_Divide_m_idx_2 +
        rtb_Divide_m_idx_0 * rtb_Divide_m_idx_3) * 2.0F;

      /* Gain: '<S85>/Gain1' incorporates:
       *  Product: '<S85>/Multiply2'
       *  Product: '<S85>/Multiply3'
       *  Sum: '<S85>/Add2'
       */
      rtb_MatrixConcatenate1[2] = (rtb_Divide_m_idx_1 * rtb_Divide_m_idx_3 +
        rtb_Divide_m_idx_0 * rtb_Divide_m_idx_2) * 2.0F;

      /* Gain: '<S85>/Gain' incorporates:
       *  Product: '<S85>/Multiply'
       *  Product: '<S85>/Multiply1'
       *  Sum: '<S85>/Subtract1'
       */
      rtb_MatrixConcatenate1[1] = (rtb_Divide_m_idx_1 * rtb_Divide_m_idx_2 -
        rtb_Divide_m_idx_0 * rtb_Divide_m_idx_3) * 2.0F;

      /* Sum: '<S85>/Subtract' incorporates:
       *  Math: '<S85>/Square'
       *  Math: '<S85>/Square1'
       *  Math: '<S85>/Square2'
       *  Math: '<S85>/Square3'
       *  Sum: '<S85>/Add'
       *  Sum: '<S85>/Add1'
       */
      rtb_MatrixConcatenate1[0] = (rtb_Divide_m_idx_0 * rtb_Divide_m_idx_0 +
        rtb_Divide_m_idx_1 * rtb_Divide_m_idx_1) - (rtb_Divide_m_idx_2 *
        rtb_Divide_m_idx_2 + rtb_Divide_m_idx_3 * rtb_Divide_m_idx_3);

      /* Product: '<S80>/Multiply' */
      for (i = 0; i < 3; i++) {
        rtb_MatrixConcatenate1_0[i] = rtb_MatrixConcatenate1[i + 6] *
          rtb_TmpSignalConversionAtMultip[2] + (rtb_MatrixConcatenate1[i + 3] *
          rtb_TmpSignalConversionAtMultip[1] + rtb_MatrixConcatenate1[i] *
          rtb_TmpSignalConversionAtMultip[0]);
      }

      /* End of Product: '<S80>/Multiply' */
      rtb_Divide_m_idx_2 = rtb_MatrixConcatenate1_0[0];

      /* SignalConversion: '<S90>/ConcatBufferAtVector ConcatenateIn3' */
      rtb_MatrixConcatenate1[6] = Controller_ConstB.VectorConcatenate3_g[0];
      rtb_MatrixConcatenate1[7] = Controller_ConstB.VectorConcatenate3_g[1];
      rtb_MatrixConcatenate1[8] = Controller_ConstB.VectorConcatenate3_g[2];

      /* SignalConversion: '<S90>/ConcatBufferAtVector Concatenate2In3' incorporates:
       *  Constant: '<S90>/Constant4'
       */
      rtb_MatrixConcatenate1[5] = 0.0F;

      /* Trigonometry: '<S90>/Trigonometric Function3' incorporates:
       *  Gain: '<S89>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S90>/Trigonometric Function1'
       */
      rtb_thor = arm_cos_f32(-Controller_U.INS_Out.psi);
      rtb_MatrixConcatenate1[4] = rtb_thor;

      /* Trigonometry: '<S90>/Trigonometric Function2' incorporates:
       *  Gain: '<S89>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S90>/Trigonometric Function'
       */
      rtb_Gain_az = arm_sin_f32(-Controller_U.INS_Out.psi);

      /* Gain: '<S90>/Gain' incorporates:
       *  Trigonometry: '<S90>/Trigonometric Function2'
       */
      rtb_MatrixConcatenate1[3] = -rtb_Gain_az;

      /* SignalConversion: '<S90>/ConcatBufferAtVector Concatenate1In3' incorporates:
       *  Constant: '<S90>/Constant3'
       */
      rtb_MatrixConcatenate1[2] = 0.0F;

      /* Trigonometry: '<S90>/Trigonometric Function' */
      rtb_MatrixConcatenate1[1] = rtb_Gain_az;

      /* Trigonometry: '<S90>/Trigonometric Function1' */
      rtb_MatrixConcatenate1[0] = rtb_thor;

      /* Product: '<S81>/Multiply' */
      for (i = 0; i < 3; i++) {
        rtb_Multiply_ni[i] = rtb_MatrixConcatenate1[i + 6] *
          rtb_TmpSignalConversionAtMultip[2] + (rtb_MatrixConcatenate1[i + 3] *
          rtb_TmpSignalConversionAtMultip[1] + rtb_MatrixConcatenate1[i] *
          rtb_TmpSignalConversionAtMultip[0]);
      }

      /* End of Product: '<S81>/Multiply' */

      /* DeadZone: '<S81>/Dead Zone' */
      if (rtb_Multiply_ni[0] > 1.0F) {
        rtb_DiscreteTimeIntegrator1_n4 = rtb_Multiply_ni[0] - 1.0F;
      } else if (rtb_Multiply_ni[0] >= -1.0F) {
        rtb_DiscreteTimeIntegrator1_n4 = 0.0F;
      } else {
        rtb_DiscreteTimeIntegrator1_n4 = rtb_Multiply_ni[0] - -1.0F;
      }

      /* End of DeadZone: '<S81>/Dead Zone' */

      /* Signum: '<S81>/Sign' */
      if (rtb_DiscreteTimeIntegrator1_n4 < 0.0F) {
        rtb_DiscreteTimeIntegrator1_n4 = -1.0F;
      } else {
        if (rtb_DiscreteTimeIntegrator1_n4 > 0.0F) {
          rtb_DiscreteTimeIntegrator1_n4 = 1.0F;
        }
      }

      /* End of Signum: '<S81>/Sign' */
    } else {
      rtb_Divide_m_idx_2 = Controller_U.INS_Out.airspeed;
      rtb_DiscreteTimeIntegrator1_n4 = 1.0F;
    }

    /* End of Switch: '<S80>/Switch' */

    /* Saturate: '<S80>/Saturation' */
    if (rtb_Divide_m_idx_2 > 100.0F) {
      rtb_Divide_m_idx_2 = 100.0F;
    } else {
      if (rtb_Divide_m_idx_2 < 8.0F) {
        rtb_Divide_m_idx_2 = 8.0F;
      }
    }

    /* End of Saturate: '<S80>/Saturation' */

    /* Product: '<S82>/Multiply1' incorporates:
     *  Gain: '<S82>/Gain'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S82>/Divide'
     *  Trigonometry: '<S82>/Asin'
     */
    rtb_Divide_m_idx_1 = atanf(-Controller_U.FMS_Out.w_cmd / rtb_Divide_m_idx_2)
      * rtb_DiscreteTimeIntegrator1_n4;

    /* DeadZone: '<S79>/Dead Zone' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    if (Controller_U.INS_Out.vd > 0.1F) {
      rtb_thor = Controller_U.INS_Out.vd - 0.1F;
    } else if (Controller_U.INS_Out.vd >= -0.1F) {
      rtb_thor = 0.0F;
    } else {
      rtb_thor = Controller_U.INS_Out.vd - -0.1F;
    }

    /* End of DeadZone: '<S79>/Dead Zone' */

    /* Product: '<S79>/Multiply1' incorporates:
     *  Gain: '<S79>/Gain'
     *  Product: '<S79>/Divide'
     *  Trigonometry: '<S79>/Asin'
     */
    rtb_DiscreteTimeIntegrator1_n4 *= atanf(1.0F / rtb_Divide_m_idx_2 *
      -rtb_thor);

    /* Saturate: '<S79>/Saturation1' */
    if (rtb_DiscreteTimeIntegrator1_n4 > 0.785398185F) {
      rtb_DiscreteTimeIntegrator1_n4 = 0.785398185F;
    } else {
      if (rtb_DiscreteTimeIntegrator1_n4 < -0.785398185F) {
        rtb_DiscreteTimeIntegrator1_n4 = -0.785398185F;
      }
    }

    /* End of Saturate: '<S79>/Saturation1' */

    /* Saturate: '<S82>/Saturation2' */
    if (rtb_Divide_m_idx_1 > 0.785398185F) {
      rtb_Divide_m_idx_1 = 0.785398185F;
    } else {
      if (rtb_Divide_m_idx_1 < -0.785398185F) {
        rtb_Divide_m_idx_1 = -0.785398185F;
      }
    }

    /* End of Saturate: '<S82>/Saturation2' */

    /* Sum: '<S74>/Sum' */
    rtb_Divide_m_idx_0 = rtb_Divide_m_idx_1 - rtb_DiscreteTimeIntegrator1_n4;

    /* DiscreteIntegrator: '<S97>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator5'
     */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_n != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_h =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;
    }

    if (Controller_DW.DiscreteTimeIntegrator1_PrevR_d != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_h =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;
    }

    /* Gain: '<S97>/Gain' incorporates:
     *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S97>/Discrete-Time Integrator1'
     *  Sum: '<S97>/Sum5'
     */
    rtb_Gain_az = (Controller_DW.DiscreteTimeIntegrator5_DSTAT_j -
                   Controller_DW.DiscreteTimeIntegrator1_DSTAT_h) * 12.566371F;

    /* Gain: '<S77>/Gain1' */
    rtb_VdotPg = 0.101936802F * rtb_Gain_az;

    /* Sum: '<S77>/Sum' incorporates:
     *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator5'
     *  Gain: '<S77>/Gain'
     *  Gain: '<S77>/Kv'
     *  Inport: '<Root>/FMS_Out'
     *  Sum: '<S77>/Minus'
     */
    rtb_Divide_m_idx_2 = (Controller_U.FMS_Out.u_cmd -
                          Controller_DW.DiscreteTimeIntegrator5_DSTAT_j) *
      CONTROL_PARAM.FW_TECS_VEL_P * 0.101936802F - rtb_VdotPg;

    /* Sum: '<S51>/Add' incorporates:
     *  Gain: '<S51>/ucmd2thor'
     *  Gain: '<S51>/wcmd2thor'
     */
    rtb_Divide_m_idx_3 = CONTROL_PARAM.FW_TECS_W2T * rtb_Divide_m_idx_0 +
      CONTROL_PARAM.FW_TECS_U2T * rtb_Divide_m_idx_2;

    /* DiscreteIntegrator: '<S95>/ ' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    if ((Controller_U.FMS_Out.reset != 0) || (Controller_DW._PrevResetState != 0))
    {
      Controller_DW._DSTATE = Controller_ConstB.Zero;
      if (Controller_DW._DSTATE >= 1.0F) {
        Controller_DW._DSTATE = 1.0F;
      } else {
        if (Controller_DW._DSTATE <= 0.0F) {
          Controller_DW._DSTATE = 0.0F;
        }
      }
    }

    if (Controller_DW._DSTATE >= 1.0F) {
      Controller_DW._DSTATE = 1.0F;
    } else {
      if (Controller_DW._DSTATE <= 0.0F) {
        Controller_DW._DSTATE = 0.0F;
      }
    }

    /* DiscreteIntegrator: '<S96>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_h != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm = rtb_Divide_m_idx_3;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_Prev_dx != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm = rtb_Divide_m_idx_3;
    }

    /* Gain: '<S96>/Gain' incorporates:
     *  DiscreteIntegrator: '<S96>/Discrete-Time Integrator1'
     *  Sum: '<S96>/Sum5'
     */
    rtb_Gain_ow = (rtb_Divide_m_idx_3 -
                   Controller_DW.DiscreteTimeIntegrator1_DSTA_nm) * 188.49556F;

    /* Switch: '<S13>/Switch' incorporates:
     *  Constant: '<S100>/Constant'
     *  Constant: '<S13>/Constant2'
     *  Constant: '<S52>/Constant'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S100>/Compare'
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
       *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator5'
       *  Math: '<S57>/Square'
       *  Math: '<S57>/Square1'
       */
      rtb_thor = CONTROL_PARAM.FW_AIRSPEED_TRIM * CONTROL_PARAM.FW_AIRSPEED_TRIM
        / (Controller_DW.DiscreteTimeIntegrator5_DSTAT_j *
           Controller_DW.DiscreteTimeIntegrator5_DSTAT_j);

      /* Saturate: '<S57>/Saturation' */
      if (rtb_thor > 1.0F) {
        rtb_thor = 1.0F;
      } else {
        if (rtb_thor < 0.0F) {
          rtb_thor = 0.0F;
        }
      }

      /* End of Saturate: '<S57>/Saturation' */

      /* Product: '<S53>/Multiply' incorporates:
       *  Constant: '<S60>/gain1'
       *  DiscreteIntegrator: '<S59>/Discrete-Time Integrator'
       *  Product: '<S60>/Multiply'
       *  Sum: '<S56>/Add1'
       */
      rtb_Divide_m_idx_1 = (CONTROL_PARAM.FW_ROLL_RATE_P * rtb_fw_rate_err_B[0]
                            + Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0]) *
        rtb_thor;

      /* Saturate: '<S53>/PI_limit' */
      if (rtb_Divide_m_idx_1 > 1.0F) {
        rtb_TmpSignalConversionAtMultip[0] = 1.0F;
      } else if (rtb_Divide_m_idx_1 < -1.0F) {
        rtb_TmpSignalConversionAtMultip[0] = -1.0F;
      } else {
        rtb_TmpSignalConversionAtMultip[0] = rtb_Divide_m_idx_1;
      }

      /* Product: '<S53>/Multiply' incorporates:
       *  Constant: '<S60>/gain2'
       *  DiscreteIntegrator: '<S59>/Discrete-Time Integrator'
       *  Product: '<S60>/Multiply'
       *  Sum: '<S56>/Add1'
       */
      rtb_Divide_m_idx_1 = (CONTROL_PARAM.FW_PITCH_RATE_P * rtb_fw_rate_err_B[1]
                            + Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1]) *
        rtb_thor;

      /* Saturate: '<S53>/PI_limit' */
      if (rtb_Divide_m_idx_1 > 1.0F) {
        rtb_TmpSignalConversionAtMultip[1] = 1.0F;
      } else if (rtb_Divide_m_idx_1 < -1.0F) {
        rtb_TmpSignalConversionAtMultip[1] = -1.0F;
      } else {
        rtb_TmpSignalConversionAtMultip[1] = rtb_Divide_m_idx_1;
      }

      /* Product: '<S53>/Multiply' incorporates:
       *  Constant: '<S60>/gain3'
       *  DiscreteIntegrator: '<S59>/Discrete-Time Integrator'
       *  Product: '<S60>/Multiply'
       *  Sum: '<S56>/Add1'
       */
      rtb_Divide_m_idx_1 = (CONTROL_PARAM.FW_YAW_RATE_P * rtb_fw_rate_err_B[2] +
                            Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2]) *
        rtb_thor;

      /* Saturate: '<S53>/PI_limit' */
      if (rtb_Divide_m_idx_1 > 1.0F) {
        rtb_TmpSignalConversionAtMultip[2] = 1.0F;
      } else if (rtb_Divide_m_idx_1 < -1.0F) {
        rtb_TmpSignalConversionAtMultip[2] = -1.0F;
      } else {
        rtb_TmpSignalConversionAtMultip[2] = rtb_Divide_m_idx_1;
      }

      /* Product: '<S58>/Divide' incorporates:
       *  Constant: '<S58>/trim_speed'
       *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator5'
       */
      rtb_thor = CONTROL_PARAM.FW_AIRSPEED_TRIM /
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;

      /* Saturate: '<S58>/Saturation' */
      if (rtb_thor > 1.0F) {
        rtb_thor = 1.0F;
      } else {
        if (rtb_thor < 0.0F) {
          rtb_thor = 0.0F;
        }
      }

      /* End of Saturate: '<S58>/Saturation' */

      /* Product: '<S53>/Multiply1' incorporates:
       *  Gain: '<S53>/FF'
       */
      rtb_Divide_m_idx_1 = CONTROL_PARAM.FW_FF * rtb_Add_k * rtb_thor;
      rtb_Add_k = CONTROL_PARAM.FW_FF * rtb_Add1_j4 * rtb_thor;
      rtb_Add1_j4 = CONTROL_PARAM.FW_FF * rtb_Add2_h * rtb_thor;

      /* Switch: '<S52>/Switch' incorporates:
       *  Bias: '<S52>/Bias'
       *  Constant: '<S99>/Constant'
       *  Gain: '<S52>/Gain'
       *  RelationalOperator: '<S99>/Compare'
       *  Switch: '<S96>/Switch'
       */
      if (Controller_U.FMS_Out.ctrl_mode <= 3) {
        rtb_thor = 0.000999987125F * (real32_T)Controller_U.FMS_Out.throttle_cmd
          + -1.0F;
      } else {
        if (Controller_U.FMS_Out.reset > 0) {
          /* Switch: '<S96>/Switch' incorporates:
           *  Gain: '<S96>/Gain1'
           */
          rtb_thor = 0.0F;
        } else {
          /* Switch: '<S96>/Switch' */
          rtb_thor = rtb_Gain_ow;
        }

        /* Gain: '<S94>/Gain' */
        rtb_thor *= CONTROL_PARAM.FW_TECS_THOR_D;

        /* Saturate: '<S76>/Saturation1' */
        if (rtb_thor > 0.3F) {
          rtb_thor = 0.3F;
        } else {
          if (rtb_thor < -0.3F) {
            rtb_thor = -0.3F;
          }
        }

        /* End of Saturate: '<S76>/Saturation1' */

        /* Sum: '<S51>/Add2' incorporates:
         *  DiscreteIntegrator: '<S95>/ '
         *  Gain: '<S51>/thorttle_ff'
         *  Gain: '<S76>/P_control'
         *  Sum: '<S51>/Add1'
         *  Sum: '<S76>/Add4'
         */
        rtb_thor = ((CONTROL_PARAM.FW_TECS_THOR_P * rtb_Divide_m_idx_3 +
                     Controller_DW._DSTATE) + rtb_thor) +
          (rtb_DiscreteTimeIntegrator1_n4 + rtb_VdotPg) *
          CONTROL_PARAM.FW_TECS_THOR_FF;

        /* Saturate: '<S52>/Saturation' */
        if (rtb_thor > 1.0F) {
          rtb_thor = 1.0F;
        } else {
          if (rtb_thor < -1.0F) {
            rtb_thor = -1.0F;
          }
        }

        /* End of Saturate: '<S52>/Saturation' */
      }

      /* End of Switch: '<S52>/Switch' */

      /* Saturate: '<S53>/FF_limit' */
      if (rtb_Divide_m_idx_1 > 0.3F) {
        rtb_Divide_m_idx_1 = 0.3F;
      } else {
        if (rtb_Divide_m_idx_1 < -0.3F) {
          rtb_Divide_m_idx_1 = -0.3F;
        }
      }

      /* Saturate: '<S53>/Saturation1' incorporates:
       *  Sum: '<S53>/Add'
       */
      rtb_Divide_m_idx_1 += rtb_TmpSignalConversionAtMultip[0];
      if (rtb_Divide_m_idx_1 > 1.0F) {
        Controller_B.Switch[0] = 1.0F;
      } else if (rtb_Divide_m_idx_1 < -1.0F) {
        Controller_B.Switch[0] = -1.0F;
      } else {
        Controller_B.Switch[0] = rtb_Divide_m_idx_1;
      }

      /* Saturate: '<S53>/FF_limit' */
      if (rtb_Add_k > 0.3F) {
        rtb_Add_k = 0.3F;
      } else {
        if (rtb_Add_k < -0.3F) {
          rtb_Add_k = -0.3F;
        }
      }

      /* Saturate: '<S53>/Saturation1' incorporates:
       *  Sum: '<S53>/Add'
       */
      rtb_Divide_m_idx_1 = rtb_Add_k + rtb_TmpSignalConversionAtMultip[1];
      if (rtb_Divide_m_idx_1 > 1.0F) {
        Controller_B.Switch[1] = 1.0F;
      } else if (rtb_Divide_m_idx_1 < -1.0F) {
        Controller_B.Switch[1] = -1.0F;
      } else {
        Controller_B.Switch[1] = rtb_Divide_m_idx_1;
      }

      /* Saturate: '<S53>/FF_limit' */
      if (rtb_Add1_j4 > 0.3F) {
        rtb_Add1_j4 = 0.3F;
      } else {
        if (rtb_Add1_j4 < -0.3F) {
          rtb_Add1_j4 = -0.3F;
        }
      }

      /* Saturate: '<S53>/Saturation1' incorporates:
       *  Sum: '<S53>/Add'
       */
      rtb_Divide_m_idx_1 = rtb_Add1_j4 + rtb_TmpSignalConversionAtMultip[2];
      if (rtb_Divide_m_idx_1 > 1.0F) {
        Controller_B.Switch[2] = 1.0F;
      } else if (rtb_Divide_m_idx_1 < -1.0F) {
        Controller_B.Switch[2] = -1.0F;
      } else {
        Controller_B.Switch[2] = rtb_Divide_m_idx_1;
      }

      /* Saturate: '<S52>/Saturation2' */
      if (rtb_thor > 1.0F) {
        Controller_B.Switch[3] = 1.0F;
      } else {
        Controller_B.Switch[3] = rtb_thor;
      }

      Controller_B.Switch[4] = 0.0F;
      Controller_B.Switch[5] = 0.0F;
    }

    /* End of Switch: '<S13>/Switch' */

    /* Product: '<S5>/Multiply' */
    Controller_B.Multiply_c[0] = Controller_B.Switch[0] *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_k;
    Controller_B.Multiply_c[1] = Controller_B.Switch[1] *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_k;
    Controller_B.Multiply_c[2] = Controller_B.Switch[2] *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_k;

    /* Sum: '<S51>/Minus1' incorporates:
     *  Gain: '<S51>/ucmd2pitch'
     *  Gain: '<S51>/wcmd2pitch'
     */
    rtb_Add_k = CONTROL_PARAM.FW_TECS_W2P * rtb_Divide_m_idx_0 -
      CONTROL_PARAM.FW_TECS_U2P * rtb_Divide_m_idx_2;

    /* RelationalOperator: '<S72>/Compare' incorporates:
     *  Constant: '<S72>/Constant'
     *  Inport: '<Root>/FMS_Out'
     */
    rtb_Compare_f = (Controller_U.FMS_Out.ext_state == 1);

    /* Logic: '<S51>/Logical Operator' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    rtb_LogicalOperator_h = ((Controller_U.FMS_Out.reset != 0) || rtb_Compare_f);

    /* DiscreteIntegrator: '<S92>/ ' */
    if (rtb_LogicalOperator_h || (Controller_DW._PrevResetState_b != 0)) {
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

    /* DiscreteIntegrator: '<S93>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_f != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_e = rtb_Add_k;
    }

    if (rtb_LogicalOperator_h || (Controller_DW.DiscreteTimeIntegrator1_PrevR_b
         != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_e = rtb_Add_k;
    }

    /* Gain: '<S93>/Gain' incorporates:
     *  DiscreteIntegrator: '<S93>/Discrete-Time Integrator1'
     *  Sum: '<S93>/Sum5'
     */
    rtb_Add1_j4 = (rtb_Add_k - Controller_DW.DiscreteTimeIntegrator1_DSTAT_e) *
      62.831852F;

    /* Switch: '<S51>/Switch' incorporates:
     *  Constant: '<S51>/Constant'
     *  DiscreteIntegrator: '<S92>/ '
     *  Gain: '<S51>/balabnce_ratio2'
     *  Gain: '<S51>/balance_ratio'
     *  Gain: '<S51>/pitch_ff'
     *  Gain: '<S75>/P_control'
     *  Sum: '<S51>/Add3'
     *  Sum: '<S51>/Minus'
     *  Sum: '<S75>/Add'
     *  Switch: '<S93>/Switch'
     */
    if (rtb_Compare_f) {
      rtb_Divide_m_idx_0 = 0.0F;
    } else {
      if (rtb_LogicalOperator_h) {
        /* Switch: '<S93>/Switch' incorporates:
         *  Gain: '<S93>/Gain1'
         */
        rtb_Divide_m_idx_0 = 0.0F;
      } else {
        /* Switch: '<S93>/Switch' */
        rtb_Divide_m_idx_0 = rtb_Add1_j4;
      }

      /* Gain: '<S91>/Gain' */
      rtb_Divide_m_idx_0 *= CONTROL_PARAM.FW_TECS_PITCH_D;

      /* Saturate: '<S75>/Saturation1' */
      if (rtb_Divide_m_idx_0 > 0.3F) {
        rtb_Divide_m_idx_0 = 0.3F;
      } else {
        if (rtb_Divide_m_idx_0 < -0.3F) {
          rtb_Divide_m_idx_0 = -0.3F;
        }
      }

      /* End of Saturate: '<S75>/Saturation1' */
      rtb_Divide_m_idx_0 = ((2.0F - CONTROL_PARAM.FW_TECS_RATIO) *
                            rtb_DiscreteTimeIntegrator1_n4 -
                            CONTROL_PARAM.FW_TECS_RATIO * rtb_VdotPg) *
        CONTROL_PARAM.FW_TECS_PITCH_F + ((CONTROL_PARAM.FW_TECS_PITCH_P *
        rtb_Add_k + Controller_DW._DSTATE_h) + rtb_Divide_m_idx_0);
    }

    /* End of Switch: '<S51>/Switch' */

    /* Sum: '<S73>/Subtract' incorporates:
     *  DiscreteIntegrator: '<S73>/Integrator1'
     */
    rtb_Divide_m_idx_1 = Controller_DW.Integrator1_DSTATE_j - rtb_Divide_m_idx_0;

    /* Product: '<S78>/Multiply1' incorporates:
     *  Constant: '<S78>/const1'
     *  DiscreteIntegrator: '<S73>/Integrator'
     */
    rtb_Divide_m_idx_0 = Controller_DW.Integrator_DSTATE_d * 0.04F;

    /* Sum: '<S78>/Add' */
    rtb_thor = rtb_Divide_m_idx_1 + rtb_Divide_m_idx_0;

    /* Signum: '<S78>/Sign' */
    if (rtb_thor < 0.0F) {
      rtb_Divide_m_idx_1 = -1.0F;
    } else if (rtb_thor > 0.0F) {
      rtb_Divide_m_idx_1 = 1.0F;
    } else {
      rtb_Divide_m_idx_1 = rtb_thor;
    }

    /* End of Signum: '<S78>/Sign' */

    /* Sum: '<S78>/Add2' incorporates:
     *  Abs: '<S78>/Abs'
     *  Gain: '<S78>/Gain'
     *  Gain: '<S78>/Gain1'
     *  Product: '<S78>/Multiply2'
     *  Product: '<S78>/Multiply3'
     *  Sqrt: '<S78>/Sqrt'
     *  Sum: '<S78>/Add1'
     *  Sum: '<S78>/Subtract'
     */
    rtb_Add2_h = (sqrtf((8.0F * fabsf(rtb_thor) + Controller_ConstB.d_f) *
                        Controller_ConstB.d_f) - Controller_ConstB.d_f) * 0.5F *
      rtb_Divide_m_idx_1 + rtb_Divide_m_idx_0;

    /* Sum: '<S78>/Add4' */
    rtb_Divide_m_idx_0 += rtb_thor - rtb_Add2_h;

    /* Sum: '<S78>/Add3' */
    rtb_Divide_m_idx_2 = rtb_thor + Controller_ConstB.d_f;

    /* Sum: '<S78>/Subtract1' */
    rtb_thor -= Controller_ConstB.d_f;

    /* Signum: '<S78>/Sign1' */
    if (rtb_Divide_m_idx_2 < 0.0F) {
      rtb_Divide_m_idx_2 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_2 > 0.0F) {
        rtb_Divide_m_idx_2 = 1.0F;
      }
    }

    /* End of Signum: '<S78>/Sign1' */

    /* Signum: '<S78>/Sign2' */
    if (rtb_thor < 0.0F) {
      rtb_thor = -1.0F;
    } else {
      if (rtb_thor > 0.0F) {
        rtb_thor = 1.0F;
      }
    }

    /* End of Signum: '<S78>/Sign2' */

    /* Sum: '<S78>/Add5' incorporates:
     *  Gain: '<S78>/Gain2'
     *  Product: '<S78>/Multiply4'
     *  Sum: '<S78>/Subtract2'
     */
    rtb_Add2_h += (rtb_Divide_m_idx_2 - rtb_thor) * 0.5F * rtb_Divide_m_idx_0;

    /* Sum: '<S78>/Subtract3' */
    rtb_Divide_m_idx_2 = rtb_Add2_h - Controller_ConstB.d_f;

    /* Sum: '<S78>/Add6' */
    rtb_Divide_m_idx_1 = rtb_Add2_h + Controller_ConstB.d_f;

    /* Product: '<S78>/Divide' */
    rtb_VdotPg = rtb_Add2_h / Controller_ConstB.d_f;

    /* Signum: '<S78>/Sign5' incorporates:
     *  Signum: '<S78>/Sign6'
     */
    if (rtb_Add2_h < 0.0F) {
      rtb_Sign5_f = -1.0F;

      /* Signum: '<S78>/Sign6' */
      rtb_DiscreteTimeIntegrator1_n4 = -1.0F;
    } else if (rtb_Add2_h > 0.0F) {
      rtb_Sign5_f = 1.0F;

      /* Signum: '<S78>/Sign6' */
      rtb_DiscreteTimeIntegrator1_n4 = 1.0F;
    } else {
      rtb_Sign5_f = rtb_Add2_h;

      /* Signum: '<S78>/Sign6' */
      rtb_DiscreteTimeIntegrator1_n4 = rtb_Add2_h;
    }

    /* End of Signum: '<S78>/Sign5' */

    /* Product: '<S71>/Multiply1' incorporates:
     *  Constant: '<S71>/const1'
     *  DiscreteIntegrator: '<S70>/Integrator'
     */
    rtb_Divide_m_idx_0 = Controller_DW.Integrator_DSTATE_n * 0.05F;

    /* Sum: '<S71>/Add' incorporates:
     *  DiscreteIntegrator: '<S70>/Integrator1'
     *  Inport: '<Root>/FMS_Out'
     *  Sum: '<S70>/Subtract'
     */
    rtb_Add2_h = (Controller_DW.Integrator1_DSTATE_c -
                  Controller_U.FMS_Out.ay_cmd) + rtb_Divide_m_idx_0;

    /* Signum: '<S71>/Sign' */
    if (rtb_Add2_h < 0.0F) {
      rtb_thor = -1.0F;
    } else if (rtb_Add2_h > 0.0F) {
      rtb_thor = 1.0F;
    } else {
      rtb_thor = rtb_Add2_h;
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
    rtb_thor = (sqrtf((8.0F * fabsf(rtb_Add2_h) + Controller_ConstB.d_ih) *
                      Controller_ConstB.d_ih) - Controller_ConstB.d_ih) * 0.5F *
      rtb_thor + rtb_Divide_m_idx_0;

    /* Sum: '<S71>/Add4' */
    rtb_Divide_m_idx_0 += rtb_Add2_h - rtb_thor;

    /* Sum: '<S71>/Add3' */
    u = rtb_Add2_h + Controller_ConstB.d_ih;

    /* Sum: '<S71>/Subtract1' */
    rtb_Add2_h -= Controller_ConstB.d_ih;

    /* Signum: '<S71>/Sign1' */
    if (u < 0.0F) {
      u = -1.0F;
    } else {
      if (u > 0.0F) {
        u = 1.0F;
      }
    }

    /* End of Signum: '<S71>/Sign1' */

    /* Signum: '<S71>/Sign2' */
    if (rtb_Add2_h < 0.0F) {
      rtb_Add2_h = -1.0F;
    } else {
      if (rtb_Add2_h > 0.0F) {
        rtb_Add2_h = 1.0F;
      }
    }

    /* End of Signum: '<S71>/Sign2' */

    /* Sum: '<S71>/Add5' incorporates:
     *  Gain: '<S71>/Gain2'
     *  Product: '<S71>/Multiply4'
     *  Sum: '<S71>/Subtract2'
     */
    rtb_thor += (u - rtb_Add2_h) * 0.5F * rtb_Divide_m_idx_0;

    /* Update for DiscreteIntegrator: '<S101>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S101>/Gain'
     *  Sum: '<S101>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_i = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_j += (rtb_Saturation1 -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j) * 62.831852F * 0.002F;

    /* Update for DiscreteIntegrator: '<S70>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S70>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_c += 0.002F *
      Controller_DW.Integrator_DSTATE_n;

    /* Update for DiscreteIntegrator: '<S73>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S73>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_j += 0.002F *
      Controller_DW.Integrator_DSTATE_d;

    /* Update for DiscreteIntegrator: '<S59>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S59>/gain1'
     *  Constant: '<S59>/gain2'
     *  Constant: '<S59>/gain3'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S59>/Multiply'
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

    /* End of Update for DiscreteIntegrator: '<S59>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S97>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_n = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_h += 0.002F * rtb_Gain_az;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_d = 0;

    /* Update for DiscreteIntegrator: '<S95>/ ' incorporates:
     *  Gain: '<S95>/Gain'
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW._DSTATE += CONTROL_PARAM.FW_TECS_THOR_I * rtb_Divide_m_idx_3 *
      0.002F;
    if (Controller_DW._DSTATE >= 1.0F) {
      Controller_DW._DSTATE = 1.0F;
    } else {
      if (Controller_DW._DSTATE <= 0.0F) {
        Controller_DW._DSTATE = 0.0F;
      }
    }

    Controller_DW._PrevResetState = (int8_T)(Controller_U.FMS_Out.reset > 0);

    /* End of Update for DiscreteIntegrator: '<S95>/ ' */

    /* Update for DiscreteIntegrator: '<S96>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_h = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTA_nm += 0.002F * rtb_Gain_ow;
    Controller_DW.DiscreteTimeIntegrator1_Prev_dx = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S92>/ ' incorporates:
     *  Gain: '<S92>/Gain3'
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

    Controller_DW._PrevResetState_b = (int8_T)rtb_LogicalOperator_h;

    /* End of Update for DiscreteIntegrator: '<S92>/ ' */

    /* Update for DiscreteIntegrator: '<S93>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_f = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_e += 0.002F * rtb_Add1_j4;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_b = (int8_T)
      rtb_LogicalOperator_h;

    /* Signum: '<S78>/Sign3' */
    if (rtb_Divide_m_idx_1 < 0.0F) {
      rtb_Divide_m_idx_1 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_1 > 0.0F) {
        rtb_Divide_m_idx_1 = 1.0F;
      }
    }

    /* End of Signum: '<S78>/Sign3' */

    /* Signum: '<S78>/Sign4' */
    if (rtb_Divide_m_idx_2 < 0.0F) {
      rtb_Divide_m_idx_2 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_2 > 0.0F) {
        rtb_Divide_m_idx_2 = 1.0F;
      }
    }

    /* End of Signum: '<S78>/Sign4' */

    /* Update for DiscreteIntegrator: '<S73>/Integrator' incorporates:
     *  Constant: '<S78>/const'
     *  Gain: '<S78>/Gain3'
     *  Product: '<S78>/Multiply5'
     *  Product: '<S78>/Multiply6'
     *  Sum: '<S78>/Subtract4'
     *  Sum: '<S78>/Subtract5'
     *  Sum: '<S78>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE_d += ((rtb_VdotPg - rtb_Sign5_f) *
      Controller_ConstB.Gain4_n * ((rtb_Divide_m_idx_1 - rtb_Divide_m_idx_2) *
      0.5F) - rtb_DiscreteTimeIntegrator1_n4 * 12.566371F) * 0.002F;

    /* Signum: '<S71>/Sign6' incorporates:
     *  Signum: '<S71>/Sign5'
     */
    if (rtb_thor < 0.0F) {
      rtb_DiscreteTimeIntegrator1_n4 = -1.0F;

      /* Signum: '<S71>/Sign5' */
      rtb_Divide_m_idx_0 = -1.0F;
    } else if (rtb_thor > 0.0F) {
      rtb_DiscreteTimeIntegrator1_n4 = 1.0F;

      /* Signum: '<S71>/Sign5' */
      rtb_Divide_m_idx_0 = 1.0F;
    } else {
      rtb_DiscreteTimeIntegrator1_n4 = rtb_thor;

      /* Signum: '<S71>/Sign5' */
      rtb_Divide_m_idx_0 = rtb_thor;
    }

    /* End of Signum: '<S71>/Sign6' */

    /* Sum: '<S71>/Add6' */
    rtb_Divide_m_idx_2 = rtb_thor + Controller_ConstB.d_ih;

    /* Sum: '<S71>/Subtract3' */
    rtb_Divide_m_idx_1 = rtb_thor - Controller_ConstB.d_ih;

    /* Signum: '<S71>/Sign3' */
    if (rtb_Divide_m_idx_2 < 0.0F) {
      rtb_Divide_m_idx_2 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_2 > 0.0F) {
        rtb_Divide_m_idx_2 = 1.0F;
      }
    }

    /* End of Signum: '<S71>/Sign3' */

    /* Signum: '<S71>/Sign4' */
    if (rtb_Divide_m_idx_1 < 0.0F) {
      rtb_Divide_m_idx_1 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_1 > 0.0F) {
        rtb_Divide_m_idx_1 = 1.0F;
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
    Controller_DW.Integrator_DSTATE_n += ((rtb_thor / Controller_ConstB.d_ih -
      rtb_Divide_m_idx_0) * Controller_ConstB.Gain4_g * ((rtb_Divide_m_idx_2 -
      rtb_Divide_m_idx_1) * 0.5F) - rtb_DiscreteTimeIntegrator1_n4 * 58.836F) *
      0.002F;
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
   *  Constant: '<S176>/Constant'
   *  Product: '<S133>/Multiply'
   *  Product: '<S142>/Divide1'
   *  Product: '<S158>/Multiply'
   *  Signum: '<S142>/Sign'
   */
  if (Controller_DW.Relay_Mode) {
    if (!Controller_DW.MC_Controller_MODE) {
      /* InitializeConditions for DiscreteIntegrator: '<S134>/Discrete-Time Integrator' */
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

      /* End of InitializeConditions for DiscreteIntegrator: '<S134>/Discrete-Time Integrator' */

      /* InitializeConditions for DiscreteIntegrator: '<S159>/Discrete-Time Integrator' */
      Controller_DW.DiscreteTimeIntegrator_PrevRe_p = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S161>/Discrete-Time Integrator1' */
      Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S131>/Discrete-Time Integrator5' */
      Controller_DW.DiscreteTimeIntegrator5_IC_LO_c = 1U;

      /* InitializeConditions for DiscreteIntegrator: '<S136>/Discrete-Time Integrator1' */
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevR_k = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S154>/Integrator1' */
      Controller_DW.Integrator1_DSTATE[0] = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S159>/Discrete-Time Integrator' */
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

      /* InitializeConditions for DiscreteIntegrator: '<S154>/Integrator' */
      Controller_DW.Integrator_DSTATE[0] = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S154>/Integrator1' */
      Controller_DW.Integrator1_DSTATE[1] = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S159>/Discrete-Time Integrator' */
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

      /* InitializeConditions for DiscreteIntegrator: '<S154>/Integrator' */
      Controller_DW.Integrator_DSTATE[1] = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S173>/Integrator1' */
      Controller_DW.Integrator1_DSTATE_e = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S176>/Discrete-Time Integrator' */
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

      /* End of InitializeConditions for DiscreteIntegrator: '<S176>/Discrete-Time Integrator' */

      /* InitializeConditions for DiscreteIntegrator: '<S178>/Discrete-Time Integrator1' */
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 1U;
      Controller_DW.DiscreteTimeIntegrator1_Prev_ks = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S173>/Integrator' */
      Controller_DW.Integrator_DSTATE_j = 0.0F;
      Controller_DW.MC_Controller_MODE = true;
    }

    /* Sqrt: '<S126>/Sqrt' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Math: '<S126>/Square'
     *  Sum: '<S126>/Sum of Elements'
     */
    rtb_thor = sqrtf(((Controller_U.INS_Out.quat[0] * Controller_U.INS_Out.quat
                       [0] + Controller_U.INS_Out.quat[1] *
                       Controller_U.INS_Out.quat[1]) +
                      Controller_U.INS_Out.quat[2] * Controller_U.INS_Out.quat[2])
                     + Controller_U.INS_Out.quat[3] * Controller_U.INS_Out.quat
                     [3]);

    /* Product: '<S122>/Divide' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Sqrt: '<S126>/Sqrt'
     */
    rtb_Divide_m_idx_0 = Controller_U.INS_Out.quat[0] / rtb_thor;
    rtb_Divide_m_idx_1 = Controller_U.INS_Out.quat[1] / rtb_thor;
    rtb_Divide_m_idx_2 = Controller_U.INS_Out.quat[2] / rtb_thor;
    rtb_Divide_m_idx_3 = Controller_U.INS_Out.quat[3] / rtb_thor;

    /* Sum: '<S123>/Subtract' incorporates:
     *  Math: '<S123>/Square'
     *  Math: '<S123>/Square1'
     *  Math: '<S123>/Square2'
     *  Math: '<S123>/Square3'
     *  Sum: '<S123>/Add'
     *  Sum: '<S123>/Add1'
     */
    rtb_MatrixConcatenate1[0] = (rtb_Divide_m_idx_0 * rtb_Divide_m_idx_0 +
      rtb_Divide_m_idx_1 * rtb_Divide_m_idx_1) - (rtb_Divide_m_idx_2 *
      rtb_Divide_m_idx_2 + rtb_Divide_m_idx_3 * rtb_Divide_m_idx_3);

    /* Gain: '<S123>/Gain' incorporates:
     *  Product: '<S123>/Multiply'
     *  Product: '<S123>/Multiply1'
     *  Sum: '<S123>/Subtract1'
     */
    rtb_MatrixConcatenate1[1] = (rtb_Divide_m_idx_1 * rtb_Divide_m_idx_2 -
      rtb_Divide_m_idx_0 * rtb_Divide_m_idx_3) * 2.0F;

    /* Gain: '<S123>/Gain1' incorporates:
     *  Product: '<S123>/Multiply2'
     *  Product: '<S123>/Multiply3'
     *  Sum: '<S123>/Add2'
     */
    rtb_MatrixConcatenate1[2] = (rtb_Divide_m_idx_1 * rtb_Divide_m_idx_3 +
      rtb_Divide_m_idx_0 * rtb_Divide_m_idx_2) * 2.0F;

    /* Gain: '<S124>/Gain' incorporates:
     *  Product: '<S124>/Multiply'
     *  Product: '<S124>/Multiply1'
     *  Sum: '<S124>/Add3'
     */
    rtb_MatrixConcatenate1[3] = (rtb_Divide_m_idx_1 * rtb_Divide_m_idx_2 +
      rtb_Divide_m_idx_0 * rtb_Divide_m_idx_3) * 2.0F;

    /* Sum: '<S124>/Subtract' incorporates:
     *  Math: '<S124>/Square'
     *  Math: '<S124>/Square1'
     *  Math: '<S124>/Square2'
     *  Math: '<S124>/Square3'
     *  Sum: '<S124>/Add'
     *  Sum: '<S124>/Add1'
     */
    rtb_MatrixConcatenate1[4] = (rtb_Divide_m_idx_0 * rtb_Divide_m_idx_0 +
      rtb_Divide_m_idx_2 * rtb_Divide_m_idx_2) - (rtb_Divide_m_idx_1 *
      rtb_Divide_m_idx_1 + rtb_Divide_m_idx_3 * rtb_Divide_m_idx_3);

    /* Gain: '<S124>/Gain1' incorporates:
     *  Product: '<S124>/Multiply2'
     *  Product: '<S124>/Multiply3'
     *  Sum: '<S124>/Subtract1'
     */
    rtb_MatrixConcatenate1[5] = (rtb_Divide_m_idx_2 * rtb_Divide_m_idx_3 -
      rtb_Divide_m_idx_0 * rtb_Divide_m_idx_1) * 2.0F;

    /* Gain: '<S125>/Gain' incorporates:
     *  Product: '<S125>/Multiply'
     *  Product: '<S125>/Multiply1'
     *  Sum: '<S125>/Subtract2'
     */
    rtb_MatrixConcatenate1[6] = (rtb_Divide_m_idx_1 * rtb_Divide_m_idx_3 -
      rtb_Divide_m_idx_0 * rtb_Divide_m_idx_2) * 2.0F;

    /* Gain: '<S125>/Gain1' incorporates:
     *  Product: '<S125>/Multiply2'
     *  Product: '<S125>/Multiply3'
     *  Sum: '<S125>/Add2'
     */
    rtb_MatrixConcatenate1[7] = (rtb_Divide_m_idx_2 * rtb_Divide_m_idx_3 +
      rtb_Divide_m_idx_0 * rtb_Divide_m_idx_1) * 2.0F;

    /* Sum: '<S125>/Subtract' incorporates:
     *  Math: '<S125>/Square'
     *  Math: '<S125>/Square1'
     *  Math: '<S125>/Square2'
     *  Math: '<S125>/Square3'
     *  Sum: '<S125>/Add'
     *  Sum: '<S125>/Add1'
     */
    rtb_MatrixConcatenate1[8] = (rtb_Divide_m_idx_0 * rtb_Divide_m_idx_0 +
      rtb_Divide_m_idx_3 * rtb_Divide_m_idx_3) - (rtb_Divide_m_idx_1 *
      rtb_Divide_m_idx_1 + rtb_Divide_m_idx_2 * rtb_Divide_m_idx_2);

    /* Product: '<S119>/Multiply' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  SignalConversion: '<S119>/TmpSignal ConversionAtMultiplyInport2'
     */
    for (i = 0; i < 3; i++) {
      rtb_TmpSignalConversionAtMultip[i] = rtb_MatrixConcatenate1[i + 6] *
        Controller_U.INS_Out.vd + (rtb_MatrixConcatenate1[i + 3] *
        Controller_U.INS_Out.ve + rtb_MatrixConcatenate1[i] *
        Controller_U.INS_Out.vn);
    }

    /* End of Product: '<S119>/Multiply' */

    /* DiscreteIntegrator: '<S134>/Discrete-Time Integrator' incorporates:
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

    /* RelationalOperator: '<S153>/Compare' incorporates:
     *  Constant: '<S153>/Constant'
     *  Inport: '<Root>/FMS_Out'
     */
    rtb_Compare_f = (Controller_U.FMS_Out.mode >= 5);

    /* Trigonometry: '<S156>/Trigonometric Function1' incorporates:
     *  Gain: '<S155>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1[0] = arm_cos_f32(-Controller_U.INS_Out.psi);

    /* Trigonometry: '<S156>/Trigonometric Function' incorporates:
     *  Gain: '<S155>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1[1] = arm_sin_f32(-Controller_U.INS_Out.psi);

    /* SignalConversion: '<S156>/ConcatBufferAtVector Concatenate1In3' incorporates:
     *  Constant: '<S156>/Constant3'
     */
    rtb_MatrixConcatenate1[2] = 0.0F;

    /* Gain: '<S156>/Gain' incorporates:
     *  Gain: '<S155>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S156>/Trigonometric Function2'
     */
    rtb_MatrixConcatenate1[3] = -arm_sin_f32(-Controller_U.INS_Out.psi);

    /* Trigonometry: '<S156>/Trigonometric Function3' incorporates:
     *  Gain: '<S155>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1[4] = arm_cos_f32(-Controller_U.INS_Out.psi);

    /* SignalConversion: '<S156>/ConcatBufferAtVector Concatenate2In3' incorporates:
     *  Constant: '<S156>/Constant4'
     */
    rtb_MatrixConcatenate1[5] = 0.0F;

    /* SignalConversion: '<S156>/ConcatBufferAtVector ConcatenateIn3' */
    rtb_MatrixConcatenate1[6] = Controller_ConstB.VectorConcatenate3[0];
    rtb_MatrixConcatenate1[7] = Controller_ConstB.VectorConcatenate3[1];
    rtb_MatrixConcatenate1[8] = Controller_ConstB.VectorConcatenate3[2];

    /* Product: '<S152>/Multiply' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  SignalConversion: '<S152>/TmpSignal ConversionAtMultiplyInport2'
     */
    for (i = 0; i < 3; i++) {
      rtb_fw_rate_err_B[i] = rtb_MatrixConcatenate1[i + 3] *
        Controller_U.INS_Out.ve + rtb_MatrixConcatenate1[i] *
        Controller_U.INS_Out.vn;
    }

    /* End of Product: '<S152>/Multiply' */

    /* Product: '<S149>/Multiply' incorporates:
     *  DataTypeConversion: '<S149>/Data Type Conversion'
     *  DiscreteIntegrator: '<S154>/Integrator1'
     *  Sum: '<S149>/Sum'
     */
    rtb_Saturation1 = (Controller_DW.Integrator1_DSTATE[0] - rtb_fw_rate_err_B[0])
      * (real32_T)rtb_Compare_f;
    rtb_Gain_az = (Controller_DW.Integrator1_DSTATE[1] - rtb_fw_rate_err_B[1]) *
      (real32_T)rtb_Compare_f;

    /* Logic: '<S112>/Logical Operator' incorporates:
     *  Constant: '<S148>/Constant'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S148>/Compare'
     */
    rtb_LogicalOperator_h = ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_U.FMS_Out.ext_state != 0));

    /* DiscreteIntegrator: '<S159>/Discrete-Time Integrator' */
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

    /* DiscreteIntegrator: '<S161>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] = rtb_Saturation1;
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] = rtb_Gain_az;
    }

    if (rtb_LogicalOperator_h || (Controller_DW.DiscreteTimeIntegrator1_PrevRes
         != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] = rtb_Saturation1;
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] = rtb_Gain_az;
    }

    /* Gain: '<S161>/Gain' incorporates:
     *  DiscreteIntegrator: '<S161>/Discrete-Time Integrator1'
     *  Sum: '<S161>/Sum5'
     */
    rtb_Divide_m_idx_3 = (rtb_Saturation1 -
                          Controller_DW.DiscreteTimeIntegrator1_DSTATE[0]) *
      62.831852F;
    rtb_Gain_ow = (rtb_Gain_az - Controller_DW.DiscreteTimeIntegrator1_DSTATE[1])
      * 62.831852F;

    /* Switch: '<S161>/Switch' incorporates:
     *  Gain: '<S161>/Gain1'
     */
    if (rtb_LogicalOperator_h) {
      rtb_DiscreteTimeIntegrator1_n4 = 0.0F;
      rtb_thor = 0.0F;
    } else {
      rtb_DiscreteTimeIntegrator1_n4 = rtb_Divide_m_idx_3;
      rtb_thor = rtb_Gain_ow;
    }

    /* End of Switch: '<S161>/Switch' */

    /* Product: '<S158>/Multiply' incorporates:
     *  Constant: '<S158>/kd'
     */
    rtb_Add1_j4 = CONTROL_PARAM.MC_VEL_XY_D * rtb_DiscreteTimeIntegrator1_n4;

    /* Saturate: '<S158>/Saturation' */
    if (rtb_Add1_j4 > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
      rtb_Add1_j4 = CONTROL_PARAM.MC_VEL_XY_D_MAX;
    } else {
      if (rtb_Add1_j4 < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
        rtb_Add1_j4 = CONTROL_PARAM.MC_VEL_XY_D_MIN;
      }
    }

    rtb_DiscreteTimeIntegrator1_n4 = rtb_Add1_j4;

    /* Product: '<S158>/Multiply' incorporates:
     *  Constant: '<S158>/kd'
     */
    rtb_Add1_j4 = CONTROL_PARAM.MC_VEL_XY_D * rtb_thor;

    /* Saturate: '<S158>/Saturation' */
    if (rtb_Add1_j4 > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
      rtb_Add1_j4 = CONTROL_PARAM.MC_VEL_XY_D_MAX;
    } else {
      if (rtb_Add1_j4 < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
        rtb_Add1_j4 = CONTROL_PARAM.MC_VEL_XY_D_MIN;
      }
    }

    /* Switch: '<S151>/Switch' incorporates:
     *  Constant: '<S160>/kp'
     *  Constant: '<S162>/Constant'
     *  Constant: '<S164>/Constant'
     *  Constant: '<S165>/Constant'
     *  DiscreteIntegrator: '<S159>/Discrete-Time Integrator'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S160>/Multiply'
     *  Product: '<S163>/Multiply2'
     *  Product: '<S163>/Multiply3'
     *  RelationalOperator: '<S162>/Compare'
     *  RelationalOperator: '<S164>/Compare'
     *  RelationalOperator: '<S165>/Compare'
     *  S-Function (sfix_bitop): '<S163>/cmd_ax valid'
     *  S-Function (sfix_bitop): '<S163>/cmd_ay valid'
     *  S-Function (sfix_bitop): '<S163>/cmd_u valid'
     *  S-Function (sfix_bitop): '<S163>/cmd_v valid'
     *  Sum: '<S150>/Add'
     *  Sum: '<S163>/Sum1'
     */
    if (Controller_U.FMS_Out.ctrl_mode == 6) {
      rtb_DiscreteTimeIntegrator1_n4 = ((Controller_U.FMS_Out.cmd_mask & 64) > 0
        ? (CONTROL_PARAM.MC_VEL_XY_P * rtb_Saturation1 +
           Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0]) +
        rtb_DiscreteTimeIntegrator1_n4 : 0.0F) + ((Controller_U.FMS_Out.cmd_mask
        & 512) > 0 ? Controller_U.FMS_Out.ax_cmd : 0.0F);
      rtb_thor = ((Controller_U.FMS_Out.cmd_mask & 128) > 0 ?
                  (CONTROL_PARAM.MC_VEL_XY_P * rtb_Gain_az +
                   Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1]) +
                  rtb_Add1_j4 : 0.0F) + ((Controller_U.FMS_Out.cmd_mask & 1024) >
        0 ? Controller_U.FMS_Out.ay_cmd : 0.0F);
    } else {
      rtb_DiscreteTimeIntegrator1_n4 += CONTROL_PARAM.MC_VEL_XY_P *
        rtb_Saturation1 + Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0];
      rtb_thor = (CONTROL_PARAM.MC_VEL_XY_P * rtb_Gain_az +
                  Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1]) +
        rtb_Add1_j4;
    }

    /* End of Switch: '<S151>/Switch' */

    /* Trigonometry: '<S147>/Atan' incorporates:
     *  Constant: '<S147>/g'
     *  Gain: '<S147>/Gain1'
     *  Gain: '<S147>/gain'
     *  Product: '<S147>/Divide'
     */
    rtb_Divide_m_idx_1 = atanf(1.1F * rtb_thor / 9.8055F);
    rtb_thor = atanf(1.1F * -rtb_DiscreteTimeIntegrator1_n4 / 9.8055F);

    /* Switch: '<S138>/Switch' incorporates:
     *  Constant: '<S145>/Constant'
     *  Inport: '<Root>/FMS_Out'
     *  Logic: '<S138>/Logical Operator'
     *  RelationalOperator: '<S144>/Compare'
     *  RelationalOperator: '<S145>/Compare'
     *  Saturate: '<S147>/Saturation'
     *  Switch: '<S138>/Switch1'
     */
    if ((Controller_U.FMS_Out.ctrl_mode == 3) || (Controller_U.FMS_Out.ctrl_mode
         == 4)) {
      rtb_DiscreteTimeIntegrator1_n4 = Controller_U.FMS_Out.phi_cmd;
      rtb_thor = Controller_U.FMS_Out.theta_cmd;
    } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
      /* Switch: '<S146>/Switch' incorporates:
       *  S-Function (sfix_bitop): '<S146>/cmd_phi valid'
       *  S-Function (sfix_bitop): '<S146>/cmd_theta valid'
       *  Saturate: '<S147>/Saturation'
       *  Switch: '<S138>/Switch1'
       */
      if ((Controller_U.FMS_Out.cmd_mask & 8) > 0) {
        rtb_DiscreteTimeIntegrator1_n4 = Controller_U.FMS_Out.phi_cmd;
      } else if (rtb_Divide_m_idx_1 > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S147>/Saturation' */
        rtb_DiscreteTimeIntegrator1_n4 = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else if (rtb_Divide_m_idx_1 < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S147>/Saturation' */
        rtb_DiscreteTimeIntegrator1_n4 = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        rtb_DiscreteTimeIntegrator1_n4 = rtb_Divide_m_idx_1;
      }

      if ((Controller_U.FMS_Out.cmd_mask & 16) > 0) {
        rtb_thor = Controller_U.FMS_Out.theta_cmd;
      } else if (rtb_thor > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S147>/Saturation' */
        rtb_thor = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_thor < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Saturate: '<S147>/Saturation' */
          rtb_thor = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        }
      }

      /* End of Switch: '<S146>/Switch' */
    } else {
      if (rtb_Divide_m_idx_1 > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S147>/Saturation' incorporates:
         *  Switch: '<S138>/Switch1'
         */
        rtb_DiscreteTimeIntegrator1_n4 = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else if (rtb_Divide_m_idx_1 < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S147>/Saturation' incorporates:
         *  Switch: '<S138>/Switch1'
         */
        rtb_DiscreteTimeIntegrator1_n4 = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        /* Switch: '<S138>/Switch1' incorporates:
         *  Saturate: '<S147>/Saturation'
         */
        rtb_DiscreteTimeIntegrator1_n4 = rtb_Divide_m_idx_1;
      }

      /* Saturate: '<S147>/Saturation' */
      if (rtb_thor > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Switch: '<S138>/Switch1' */
        rtb_thor = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_thor < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Switch: '<S138>/Switch1' */
          rtb_thor = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        }
      }
    }

    /* End of Switch: '<S138>/Switch' */

    /* Sum: '<S139>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Add1_j4 = rtb_DiscreteTimeIntegrator1_n4 - Controller_U.INS_Out.phi;

    /* Product: '<S142>/Divide1' incorporates:
     *  Abs: '<S142>/Abs'
     *  Constant: '<S142>/const2'
     */
    rtb_Add2_h = fabsf(rtb_Add1_j4) / 0.002F;

    /* Product: '<S142>/Divide' incorporates:
     *  Constant: '<S140>/Constant1'
     *  Constant: '<S142>/const1'
     *  Math: '<S142>/Square'
     *  SignalConversion: '<S142>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_Add_k = 9.5993F / (CONTROL_PARAM.MC_ROLL_P * CONTROL_PARAM.MC_ROLL_P);

    /* Signum: '<S142>/Sign' */
    if (rtb_Add1_j4 < 0.0F) {
      rtb_VdotPg = -1.0F;
    } else if (rtb_Add1_j4 > 0.0F) {
      rtb_VdotPg = 1.0F;
    } else {
      rtb_VdotPg = rtb_Add1_j4;
    }

    /* Switch: '<S142>/Switch' incorporates:
     *  Constant: '<S140>/Constant1'
     *  Gain: '<S142>/Gain1'
     *  Gain: '<S142>/Gain2'
     *  Logic: '<S142>/Logical Operator'
     *  Product: '<S142>/Multiply'
     *  Product: '<S142>/Multiply1'
     *  Product: '<S142>/Multiply2'
     *  Product: '<S142>/Multiply3'
     *  RelationalOperator: '<S142>/Relational Operator'
     *  RelationalOperator: '<S142>/Relational Operator2'
     *  SignalConversion: '<S142>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S142>/Sqrt'
     *  Sum: '<S142>/Subtract'
     */
    if ((rtb_Add1_j4 <= rtb_Add_k) && (rtb_Add1_j4 >= -rtb_Add_k)) {
      rtb_VdotPg = rtb_Add1_j4 * CONTROL_PARAM.MC_ROLL_P;
    } else {
      rtb_VdotPg *= sqrtf((rtb_VdotPg * rtb_Add1_j4 - 0.5F * rtb_Add_k) *
                          Controller_ConstB.Gain);
    }

    /* Product: '<S142>/Divide' incorporates:
     *  Gain: '<S142>/Gain3'
     */
    rtb_Divide_m_idx_1 = -rtb_Add2_h;

    /* Switch: '<S143>/Switch' incorporates:
     *  Gain: '<S142>/Gain3'
     *  RelationalOperator: '<S143>/UpperRelop'
     */
    if (rtb_VdotPg >= -rtb_Add2_h) {
      /* Product: '<S142>/Divide' */
      rtb_Divide_m_idx_1 = rtb_VdotPg;
    }

    rtb_DiscreteTimeIntegrator1_n4 = rtb_Add2_h;
    rtb_Divide_m_idx_0 = rtb_VdotPg;

    /* Sum: '<S139>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S142>/Divide1'
     *  Signum: '<S142>/Sign'
     */
    rtb_Add1_j4 = rtb_thor - Controller_U.INS_Out.theta;

    /* Product: '<S142>/Divide1' incorporates:
     *  Abs: '<S142>/Abs'
     *  Constant: '<S142>/const2'
     */
    rtb_Add2_h = fabsf(rtb_Add1_j4) / 0.002F;

    /* Product: '<S142>/Divide' incorporates:
     *  Constant: '<S140>/Constant2'
     *  Constant: '<S142>/const1'
     *  Math: '<S142>/Square'
     *  SignalConversion: '<S142>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_Add_k = 9.5993F / (CONTROL_PARAM.MC_PITCH_P * CONTROL_PARAM.MC_PITCH_P);

    /* Signum: '<S142>/Sign' */
    if (rtb_Add1_j4 < 0.0F) {
      rtb_VdotPg = -1.0F;
    } else if (rtb_Add1_j4 > 0.0F) {
      rtb_VdotPg = 1.0F;
    } else {
      rtb_VdotPg = rtb_Add1_j4;
    }

    /* Switch: '<S142>/Switch' incorporates:
     *  Constant: '<S140>/Constant2'
     *  Gain: '<S142>/Gain1'
     *  Gain: '<S142>/Gain2'
     *  Logic: '<S142>/Logical Operator'
     *  Product: '<S142>/Multiply'
     *  Product: '<S142>/Multiply1'
     *  Product: '<S142>/Multiply2'
     *  Product: '<S142>/Multiply3'
     *  RelationalOperator: '<S142>/Relational Operator'
     *  RelationalOperator: '<S142>/Relational Operator2'
     *  SignalConversion: '<S142>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S142>/Sqrt'
     *  Sum: '<S142>/Subtract'
     */
    if ((rtb_Add1_j4 <= rtb_Add_k) && (rtb_Add1_j4 >= -rtb_Add_k)) {
      rtb_VdotPg = rtb_Add1_j4 * CONTROL_PARAM.MC_PITCH_P;
    } else {
      rtb_VdotPg *= sqrtf((rtb_VdotPg * rtb_Add1_j4 - 0.5F * rtb_Add_k) *
                          Controller_ConstB.Gain);
    }

    /* Gain: '<S142>/Gain3' */
    rtb_Add_k = -rtb_Add2_h;

    /* Switch: '<S143>/Switch' incorporates:
     *  Gain: '<S142>/Gain3'
     *  RelationalOperator: '<S143>/UpperRelop'
     */
    if (rtb_VdotPg >= -rtb_Add2_h) {
      rtb_Add_k = rtb_VdotPg;
    }

    /* MultiPortSwitch: '<S115>/Multiport Switch' incorporates:
     *  Constant: '<S117>/Constant3'
     *  Constant: '<S120>/Constant3'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S117>/Multiply1'
     *  Product: '<S117>/Multiply2'
     *  Product: '<S120>/Multiply1'
     *  Product: '<S120>/Multiply2'
     *  Sum: '<S117>/Sum'
     *  Sum: '<S117>/Sum1'
     *  Sum: '<S120>/Sum'
     *  Sum: '<S120>/Sum1'
     */
    switch (Controller_U.FMS_Out.ext_state) {
     case 1:
      /* Saturate: '<S120>/Saturation3' */
      if (rtb_TmpSignalConversionAtMultip[0] > 8.0F) {
        rtb_Add1_j4 = 8.0F;
      } else if (rtb_TmpSignalConversionAtMultip[0] < 2.0F) {
        rtb_Add1_j4 = 2.0F;
      } else {
        rtb_Add1_j4 = rtb_TmpSignalConversionAtMultip[0];
      }

      /* End of Saturate: '<S120>/Saturation3' */

      /* Product: '<S120>/Multiply' incorporates:
       *  Constant: '<S120>/Constant1'
       *  Sum: '<S120>/Subtract1'
       */
      rtb_Add_k = (rtb_Add1_j4 - 2.0F) * Controller_ConstB.Divide_k;

      /* Switch: '<S143>/Switch2' incorporates:
       *  RelationalOperator: '<S143>/LowerRelop1'
       */
      if (rtb_Divide_m_idx_0 > rtb_DiscreteTimeIntegrator1_n4) {
        rtb_Divide_m_idx_1 = rtb_DiscreteTimeIntegrator1_n4;
      }

      Controller_B.Multiply[0] = (1.0F - rtb_Add_k) * rtb_Divide_m_idx_1 +
        rtb_Add_k * Controller_B.Reshape[0];
      Controller_B.Multiply[1] = Controller_B.Reshape[1];
      Controller_B.Multiply[2] = (1.0F - rtb_Add_k) *
        Controller_U.FMS_Out.psi_rate_cmd + rtb_Add_k * Controller_B.Reshape[2];
      break;

     case 3:
      /* Saturate: '<S117>/Saturation3' */
      if (rtb_TmpSignalConversionAtMultip[0] > 8.0F) {
        rtb_Add1_j4 = 8.0F;
      } else if (rtb_TmpSignalConversionAtMultip[0] < 2.0F) {
        rtb_Add1_j4 = 2.0F;
      } else {
        rtb_Add1_j4 = rtb_TmpSignalConversionAtMultip[0];
      }

      /* End of Saturate: '<S117>/Saturation3' */

      /* Product: '<S117>/Multiply' incorporates:
       *  Constant: '<S117>/Constant1'
       *  Sum: '<S117>/Subtract1'
       */
      rtb_Add1_j4 = (rtb_Add1_j4 - 2.0F) * Controller_ConstB.Divide;

      /* Switch: '<S143>/Switch2' incorporates:
       *  RelationalOperator: '<S143>/LowerRelop1'
       */
      if (rtb_Divide_m_idx_0 > rtb_DiscreteTimeIntegrator1_n4) {
        rtb_Divide_m_idx_1 = rtb_DiscreteTimeIntegrator1_n4;
      }

      Controller_B.Multiply[0] = (1.0F - rtb_Add1_j4) * rtb_Divide_m_idx_1 +
        rtb_Add1_j4 * Controller_B.Reshape[0];

      /* Switch: '<S143>/Switch2' incorporates:
       *  Constant: '<S117>/Constant3'
       *  Product: '<S117>/Multiply1'
       *  Product: '<S117>/Multiply2'
       *  RelationalOperator: '<S143>/LowerRelop1'
       *  Sum: '<S117>/Sum'
       *  Sum: '<S117>/Sum1'
       */
      if (rtb_VdotPg > rtb_Add2_h) {
        rtb_Add_k = rtb_Add2_h;
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
      /* Switch: '<S143>/Switch2' incorporates:
       *  RelationalOperator: '<S143>/LowerRelop1'
       */
      if (rtb_Divide_m_idx_0 > rtb_DiscreteTimeIntegrator1_n4) {
        Controller_B.Multiply[0] = rtb_DiscreteTimeIntegrator1_n4;
      } else {
        Controller_B.Multiply[0] = rtb_Divide_m_idx_1;
      }

      if (rtb_VdotPg > rtb_Add2_h) {
        Controller_B.Multiply[1] = rtb_Add2_h;
      } else {
        Controller_B.Multiply[1] = rtb_Add_k;
      }

      Controller_B.Multiply[2] = Controller_U.FMS_Out.psi_rate_cmd;
      break;
    }

    /* End of MultiPortSwitch: '<S115>/Multiport Switch' */

    /* Trigonometry: '<S118>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    u = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Trigonometry: '<S118>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_thor = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S118>/Sin' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Add2_h = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Sum: '<S118>/Add2' incorporates:
     *  Product: '<S118>/Multiply4'
     *  Product: '<S118>/Multiply5'
     *  Trigonometry: '<S118>/Cos'
     *  Trigonometry: '<S118>/Cos1'
     *  Trigonometry: '<S118>/Sin'
     */
    rtb_Divide_m_idx_0 = rtb_thor * u * Controller_B.Multiply[2] - rtb_Add2_h *
      Controller_B.Multiply[1];

    /* Saturate: '<S115>/Saturation' */
    if (rtb_Divide_m_idx_0 > CONTROL_PARAM.MC_R_CMD_LIM) {
      rtb_Divide_m_idx_0 = CONTROL_PARAM.MC_R_CMD_LIM;
    } else {
      if (rtb_Divide_m_idx_0 < -CONTROL_PARAM.MC_R_CMD_LIM) {
        rtb_Divide_m_idx_0 = -CONTROL_PARAM.MC_R_CMD_LIM;
      }
    }

    /* End of Saturate: '<S115>/Saturation' */

    /* Sum: '<S118>/Add' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S118>/Multiply'
     *  Trigonometry: '<S118>/Sin1'
     */
    rtb_Divide_m_idx_2 = Controller_B.Multiply[0] - arm_sin_f32
      (Controller_U.INS_Out.theta) * Controller_B.Multiply[2];

    /* Saturate: '<S115>/Saturation1' */
    if (rtb_Divide_m_idx_2 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_Divide_m_idx_2 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_Divide_m_idx_2 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_Divide_m_idx_2 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    /* End of Saturate: '<S115>/Saturation1' */

    /* Sum: '<S118>/Add1' incorporates:
     *  Product: '<S118>/Multiply1'
     *  Product: '<S118>/Multiply3'
     *  Trigonometry: '<S118>/Cos'
     *  Trigonometry: '<S118>/Cos1'
     *  Trigonometry: '<S118>/Sin'
     */
    rtb_Add2_h = rtb_Add2_h * u * Controller_B.Multiply[2] + rtb_thor *
      Controller_B.Multiply[1];

    /* Saturate: '<S115>/Saturation2' */
    if (rtb_Add2_h > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_Add2_h = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_Add2_h < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_Add2_h = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    /* End of Saturate: '<S115>/Saturation2' */

    /* Sum: '<S127>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_m_idx_1 = rtb_Divide_m_idx_2 - Controller_U.INS_Out.p;

    /* Saturate: '<S127>/Saturation' */
    if (rtb_Divide_m_idx_1 > 3.14159274F) {
      rtb_Divide_m_idx_1 = 3.14159274F;
    } else {
      if (rtb_Divide_m_idx_1 < -3.14159274F) {
        rtb_Divide_m_idx_1 = -3.14159274F;
      }
    }

    /* Sum: '<S127>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Add_k = rtb_Add2_h - Controller_U.INS_Out.q;

    /* Saturate: '<S127>/Saturation' */
    if (rtb_Add_k > 3.14159274F) {
      rtb_Add_k = 3.14159274F;
    } else {
      if (rtb_Add_k < -3.14159274F) {
        rtb_Add_k = -3.14159274F;
      }
    }

    /* Sum: '<S127>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Add1_j4 = rtb_Divide_m_idx_0 - Controller_U.INS_Out.r;

    /* Saturate: '<S127>/Saturation' */
    if (rtb_Add1_j4 > 3.14159274F) {
      rtb_Add1_j4 = 3.14159274F;
    } else {
      if (rtb_Add1_j4 < -3.14159274F) {
        rtb_Add1_j4 = -3.14159274F;
      }
    }

    /* DiscreteIntegrator: '<S131>/Discrete-Time Integrator5' incorporates:
     *  Saturate: '<S127>/Saturation'
     */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_c != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0] = rtb_Divide_m_idx_1;
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1] = rtb_Add_k;
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2] = rtb_Add1_j4;
    }

    /* DiscreteIntegrator: '<S136>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S131>/Discrete-Time Integrator5'
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

    /* Gain: '<S136>/Gain' incorporates:
     *  DiscreteIntegrator: '<S131>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S136>/Discrete-Time Integrator1'
     *  Sum: '<S136>/Sum5'
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

    /* Switch: '<S136>/Switch' incorporates:
     *  Gain: '<S136>/Gain1'
     *  Inport: '<Root>/FMS_Out'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_thor = 0.0F;
      rtb_DiscreteTimeIntegrator1_n4 = 0.0F;
      rtb_VdotPg = 0.0F;
    } else {
      rtb_thor = rtb_Multiply_ni[0];
      rtb_DiscreteTimeIntegrator1_n4 = rtb_Multiply_ni[1];
      rtb_VdotPg = rtb_Multiply_ni[2];
    }

    /* End of Switch: '<S136>/Switch' */

    /* Product: '<S133>/Multiply' incorporates:
     *  Constant: '<S133>/gain1'
     */
    rtb_Sign5_f = CONTROL_PARAM.MC_ROLL_RATE_D * rtb_thor;

    /* Saturate: '<S133>/Saturation' */
    if (rtb_Sign5_f > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Sign5_f = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Sign5_f < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Sign5_f = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    rtb_thor = rtb_Sign5_f;

    /* Product: '<S133>/Multiply' incorporates:
     *  Constant: '<S133>/gain2'
     */
    rtb_Sign5_f = CONTROL_PARAM.MC_PITCH_RATE_D * rtb_DiscreteTimeIntegrator1_n4;

    /* Saturate: '<S133>/Saturation' */
    if (rtb_Sign5_f > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Sign5_f = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Sign5_f < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Sign5_f = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    rtb_DiscreteTimeIntegrator1_n4 = rtb_Sign5_f;

    /* Product: '<S133>/Multiply' incorporates:
     *  Constant: '<S133>/gain3'
     */
    rtb_Sign5_f = CONTROL_PARAM.MC_YAW_RATE_D * rtb_VdotPg;

    /* Saturate: '<S133>/Saturation' */
    if (rtb_Sign5_f > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Sign5_f = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Sign5_f < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Sign5_f = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    /* Sum: '<S129>/Add' incorporates:
     *  Constant: '<S135>/gain1'
     *  Constant: '<S135>/gain2'
     *  Constant: '<S135>/gain3'
     *  DiscreteIntegrator: '<S131>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S134>/Discrete-Time Integrator'
     *  Product: '<S135>/Multiply'
     */
    Controller_B.Multiply[0] = (CONTROL_PARAM.MC_ROLL_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0]) + rtb_thor;
    Controller_B.Multiply[1] = (CONTROL_PARAM.MC_PITCH_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1]) +
      rtb_DiscreteTimeIntegrator1_n4;
    Controller_B.Multiply[2] = (CONTROL_PARAM.MC_YAW_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[2]) + rtb_Sign5_f;

    /* DeadZone: '<S132>/Dead Zone' */
    if (rtb_Divide_m_idx_2 > 0.1F) {
      rtb_Divide_m_idx_2 -= 0.1F;
    } else if (rtb_Divide_m_idx_2 >= -0.1F) {
      rtb_Divide_m_idx_2 = 0.0F;
    } else {
      rtb_Divide_m_idx_2 -= -0.1F;
    }

    /* Sum: '<S116>/Sum' incorporates:
     *  Gain: '<S128>/Gain'
     *  Gain: '<S132>/Gain'
     */
    Controller_B.Multiply[0] += 1.11111116F * rtb_Divide_m_idx_2 *
      CONTROL_PARAM.MC_ROLL_RATE_FF;

    /* Product: '<S6>/Multiply' incorporates:
     *  DiscreteIntegrator: '<S10>/Discrete-Time Integrator5'
     */
    Controller_B.Multiply[0] *= Controller_DW.DiscreteTimeIntegrator5_DSTATE;

    /* DeadZone: '<S132>/Dead Zone' */
    if (rtb_Add2_h > 0.1F) {
      rtb_Add2_h -= 0.1F;
    } else if (rtb_Add2_h >= -0.1F) {
      rtb_Add2_h = 0.0F;
    } else {
      rtb_Add2_h -= -0.1F;
    }

    /* Sum: '<S116>/Sum' incorporates:
     *  Gain: '<S128>/Gain'
     *  Gain: '<S132>/Gain'
     */
    Controller_B.Multiply[1] += 1.11111116F * rtb_Add2_h *
      CONTROL_PARAM.MC_ROLL_RATE_FF;

    /* Product: '<S6>/Multiply' incorporates:
     *  DiscreteIntegrator: '<S10>/Discrete-Time Integrator5'
     */
    Controller_B.Multiply[1] *= Controller_DW.DiscreteTimeIntegrator5_DSTATE;

    /* DeadZone: '<S132>/Dead Zone' */
    if (rtb_Divide_m_idx_0 > 0.1F) {
      rtb_Divide_m_idx_0 -= 0.1F;
    } else if (rtb_Divide_m_idx_0 >= -0.1F) {
      rtb_Divide_m_idx_0 = 0.0F;
    } else {
      rtb_Divide_m_idx_0 -= -0.1F;
    }

    /* Sum: '<S116>/Sum' incorporates:
     *  Gain: '<S128>/Gain1'
     *  Gain: '<S132>/Gain'
     */
    Controller_B.Multiply[2] += 1.11111116F * rtb_Divide_m_idx_0 *
      CONTROL_PARAM.MC_PITCH_RATE_FF;

    /* Product: '<S6>/Multiply' incorporates:
     *  DiscreteIntegrator: '<S10>/Discrete-Time Integrator5'
     */
    Controller_B.Multiply[2] *= Controller_DW.DiscreteTimeIntegrator5_DSTATE;

    /* Product: '<S157>/Multiply1' incorporates:
     *  Constant: '<S157>/const1'
     *  DiscreteIntegrator: '<S154>/Integrator'
     */
    rtb_DiscreteTimeIntegrator1_n4 = Controller_DW.Integrator_DSTATE[0] * 0.05F;
    rtb_thor = Controller_DW.Integrator_DSTATE[1] * 0.05F;

    /* Switch: '<S149>/Switch' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    if (rtb_Compare_f) {
      rtb_Divide_m_idx_2 = Controller_U.FMS_Out.u_cmd;
    } else {
      rtb_Divide_m_idx_2 = rtb_fw_rate_err_B[0];
    }

    /* Sum: '<S157>/Add' incorporates:
     *  DiscreteIntegrator: '<S154>/Integrator1'
     *  Sum: '<S154>/Subtract'
     */
    rtb_Divide_m_idx_0 = (Controller_DW.Integrator1_DSTATE[0] -
                          rtb_Divide_m_idx_2) + rtb_DiscreteTimeIntegrator1_n4;

    /* Switch: '<S149>/Switch' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    if (rtb_Compare_f) {
      rtb_Divide_m_idx_2 = Controller_U.FMS_Out.v_cmd;
    } else {
      rtb_Divide_m_idx_2 = rtb_fw_rate_err_B[1];
    }

    /* Sum: '<S157>/Add' incorporates:
     *  DiscreteIntegrator: '<S154>/Integrator1'
     *  Sum: '<S154>/Subtract'
     */
    rtb_Sign5_f = (Controller_DW.Integrator1_DSTATE[1] - rtb_Divide_m_idx_2) +
      rtb_thor;

    /* Signum: '<S157>/Sign' */
    if (rtb_Divide_m_idx_0 < 0.0F) {
      rtb_Divide_m_idx_2 = -1.0F;
    } else if (rtb_Divide_m_idx_0 > 0.0F) {
      rtb_Divide_m_idx_2 = 1.0F;
    } else {
      rtb_Divide_m_idx_2 = rtb_Divide_m_idx_0;
    }

    /* Sum: '<S157>/Add2' incorporates:
     *  Abs: '<S157>/Abs'
     *  Gain: '<S157>/Gain'
     *  Gain: '<S157>/Gain1'
     *  Product: '<S157>/Multiply2'
     *  Product: '<S157>/Multiply3'
     *  Signum: '<S157>/Sign'
     *  Sqrt: '<S157>/Sqrt'
     *  Sum: '<S157>/Add1'
     *  Sum: '<S157>/Subtract'
     */
    rtb_Add2_h = (sqrtf((8.0F * fabsf(rtb_Divide_m_idx_0) + Controller_ConstB.d)
                        * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
      rtb_Divide_m_idx_2 + rtb_DiscreteTimeIntegrator1_n4;

    /* Sum: '<S157>/Add3' incorporates:
     *  Signum: '<S157>/Sign'
     */
    rtb_Divide_m_idx_2 = rtb_Divide_m_idx_0 + Controller_ConstB.d;

    /* Sum: '<S157>/Subtract1' incorporates:
     *  Signum: '<S157>/Sign'
     */
    rtb_VdotPg = rtb_Divide_m_idx_0 - Controller_ConstB.d;

    /* Signum: '<S157>/Sign1' */
    if (rtb_Divide_m_idx_2 < 0.0F) {
      rtb_Divide_m_idx_2 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_2 > 0.0F) {
        rtb_Divide_m_idx_2 = 1.0F;
      }
    }

    /* Signum: '<S157>/Sign2' */
    if (rtb_VdotPg < 0.0F) {
      rtb_VdotPg = -1.0F;
    } else {
      if (rtb_VdotPg > 0.0F) {
        rtb_VdotPg = 1.0F;
      }
    }

    /* Sum: '<S157>/Add2' incorporates:
     *  Gain: '<S157>/Gain2'
     *  Product: '<S157>/Multiply4'
     *  Signum: '<S157>/Sign'
     *  Sum: '<S157>/Add4'
     *  Sum: '<S157>/Add5'
     *  Sum: '<S157>/Subtract2'
     */
    rtb_DiscreteTimeIntegrator1_n4 = ((rtb_Divide_m_idx_0 - rtb_Add2_h) +
      rtb_DiscreteTimeIntegrator1_n4) * ((rtb_Divide_m_idx_2 - rtb_VdotPg) *
      0.5F) + rtb_Add2_h;

    /* Signum: '<S157>/Sign' */
    if (rtb_Sign5_f < 0.0F) {
      rtb_Divide_m_idx_0 = -1.0F;
    } else if (rtb_Sign5_f > 0.0F) {
      rtb_Divide_m_idx_0 = 1.0F;
    } else {
      rtb_Divide_m_idx_0 = rtb_Sign5_f;
    }

    /* Sum: '<S157>/Add2' incorporates:
     *  Abs: '<S157>/Abs'
     *  Gain: '<S157>/Gain'
     *  Gain: '<S157>/Gain1'
     *  Product: '<S157>/Multiply2'
     *  Product: '<S157>/Multiply3'
     *  Signum: '<S157>/Sign'
     *  Sqrt: '<S157>/Sqrt'
     *  Sum: '<S157>/Add1'
     *  Sum: '<S157>/Subtract'
     */
    rtb_Add2_h = (sqrtf((8.0F * fabsf(rtb_Sign5_f) + Controller_ConstB.d) *
                        Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
      rtb_Divide_m_idx_0 + rtb_thor;

    /* Sum: '<S157>/Add3' incorporates:
     *  Signum: '<S157>/Sign'
     */
    rtb_Divide_m_idx_2 = rtb_Sign5_f + Controller_ConstB.d;

    /* Sum: '<S157>/Subtract1' incorporates:
     *  Signum: '<S157>/Sign'
     */
    rtb_VdotPg = rtb_Sign5_f - Controller_ConstB.d;

    /* Signum: '<S157>/Sign1' */
    if (rtb_Divide_m_idx_2 < 0.0F) {
      rtb_Divide_m_idx_2 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_2 > 0.0F) {
        rtb_Divide_m_idx_2 = 1.0F;
      }
    }

    /* Signum: '<S157>/Sign2' */
    if (rtb_VdotPg < 0.0F) {
      rtb_VdotPg = -1.0F;
    } else {
      if (rtb_VdotPg > 0.0F) {
        rtb_VdotPg = 1.0F;
      }
    }

    /* Sum: '<S157>/Add5' incorporates:
     *  Gain: '<S157>/Gain2'
     *  Product: '<S157>/Multiply4'
     *  Signum: '<S157>/Sign'
     *  Sum: '<S157>/Add2'
     *  Sum: '<S157>/Add4'
     *  Sum: '<S157>/Subtract2'
     */
    rtb_Add2_h += ((rtb_Sign5_f - rtb_Add2_h) + rtb_thor) * ((rtb_Divide_m_idx_2
      - rtb_VdotPg) * 0.5F);

    /* RelationalOperator: '<S172>/Compare' incorporates:
     *  Constant: '<S172>/Constant'
     *  Inport: '<Root>/FMS_Out'
     */
    rtb_Compare_f = (Controller_U.FMS_Out.mode >= 4);

    /* Product: '<S170>/Multiply' incorporates:
     *  DataTypeConversion: '<S170>/Data Type Conversion'
     *  DiscreteIntegrator: '<S173>/Integrator1'
     *  Gain: '<S170>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S170>/Sum1'
     */
    rtb_VdotPg = -(Controller_DW.Integrator1_DSTATE_e - Controller_U.INS_Out.vd)
      * (real32_T)rtb_Compare_f;
    Controller_B.Constant = CONTROL_PARAM.MC_VEL_Z_I_MIN;

    /* DiscreteIntegrator: '<S176>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S176>/Constant'
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

    /* DiscreteIntegrator: '<S178>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_d != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i = rtb_VdotPg;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_Prev_ks != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i = rtb_VdotPg;
    }

    /* Gain: '<S178>/Gain' incorporates:
     *  DiscreteIntegrator: '<S178>/Discrete-Time Integrator1'
     *  Sum: '<S178>/Sum5'
     */
    rtb_Sign5_f = (rtb_VdotPg - Controller_DW.DiscreteTimeIntegrator1_DSTAT_i) *
      62.831852F;

    /* Switch: '<S166>/Switch' incorporates:
     *  Bias: '<S166>/Bias'
     *  Constant: '<S168>/Constant'
     *  Gain: '<S166>/Gain'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S168>/Compare'
     */
    if (Controller_U.FMS_Out.ctrl_mode <= 3) {
      rtb_Divide_m_idx_0 = 0.000999987125F * (real32_T)
        Controller_U.FMS_Out.throttle_cmd + -1.0F;
    } else {
      /* Product: '<S169>/Multiply' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S169>/Cos'
       *  Trigonometry: '<S169>/Cos1'
       */
      rtb_thor = arm_cos_f32(Controller_U.INS_Out.phi) * arm_cos_f32
        (Controller_U.INS_Out.theta);

      /* Gain: '<S169>/Gain' */
      rtb_Divide_m_idx_0 = 2.0F * rtb_thor;

      /* Saturate: '<S169>/Saturation1' */
      if (rtb_thor > 1.0F) {
        rtb_thor = 1.0F;
      } else {
        if (rtb_thor < 0.5F) {
          rtb_thor = 0.5F;
        }
      }

      /* End of Saturate: '<S169>/Saturation1' */

      /* Product: '<S169>/Divide' incorporates:
       *  Constant: '<S169>/Constant'
       */
      rtb_Divide_m_idx_2 = 1.0F / rtb_thor;

      /* Switch: '<S178>/Switch' incorporates:
       *  Gain: '<S178>/Gain1'
       */
      if (Controller_U.FMS_Out.reset > 0) {
        rtb_thor = 0.0F;
      } else {
        rtb_thor = rtb_Sign5_f;
      }

      /* End of Switch: '<S178>/Switch' */

      /* Product: '<S175>/Multiply' incorporates:
       *  Constant: '<S175>/kd'
       */
      rtb_thor *= CONTROL_PARAM.MC_VEL_Z_D;

      /* Saturate: '<S175>/Saturation' */
      if (rtb_thor > CONTROL_PARAM.MC_VEL_Z_D_MAX) {
        rtb_thor = CONTROL_PARAM.MC_VEL_Z_D_MAX;
      } else {
        if (rtb_thor < CONTROL_PARAM.MC_VEL_Z_D_MIN) {
          rtb_thor = CONTROL_PARAM.MC_VEL_Z_D_MIN;
        }
      }

      /* End of Saturate: '<S175>/Saturation' */

      /* Saturate: '<S169>/Saturation' */
      if (rtb_Divide_m_idx_0 > 1.0F) {
        rtb_Divide_m_idx_0 = 1.0F;
      } else {
        if (rtb_Divide_m_idx_0 < 0.0F) {
          rtb_Divide_m_idx_0 = 0.0F;
        }
      }

      /* End of Saturate: '<S169>/Saturation' */

      /* Sum: '<S167>/Sum' incorporates:
       *  Constant: '<S167>/hover_throttle'
       *  Constant: '<S177>/kp'
       *  DiscreteIntegrator: '<S176>/Discrete-Time Integrator'
       *  Product: '<S169>/Multiply1'
       *  Product: '<S177>/Multiply'
       *  Sum: '<S171>/Add'
       */
      rtb_Divide_m_idx_0 = ((CONTROL_PARAM.MC_VEL_Z_P * rtb_VdotPg +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_l) + rtb_thor) *
        rtb_Divide_m_idx_2 * rtb_Divide_m_idx_0 + CONTROL_PARAM.MC_HOVER_THRO;

      /* Saturate: '<S167>/Saturation' */
      if (rtb_Divide_m_idx_0 > 0.85F) {
        rtb_Divide_m_idx_0 = 0.85F;
      } else {
        if (rtb_Divide_m_idx_0 < 0.3F) {
          rtb_Divide_m_idx_0 = 0.3F;
        }
      }

      /* End of Saturate: '<S167>/Saturation' */
    }

    /* End of Switch: '<S166>/Switch' */

    /* Product: '<S6>/Multiply1' incorporates:
     *  Constant: '<S166>/Constant'
     *  DiscreteIntegrator: '<S10>/Discrete-Time Integrator5'
     */
    Controller_B.Multiply1[0] = 0.0F;
    Controller_B.Multiply1[1] = 0.0F;
    Controller_B.Multiply1[2] = Controller_DW.DiscreteTimeIntegrator5_DSTATE *
      rtb_Divide_m_idx_0;

    /* Product: '<S174>/Multiply1' incorporates:
     *  Constant: '<S174>/const1'
     *  DiscreteIntegrator: '<S173>/Integrator'
     */
    rtb_Divide_m_idx_0 = Controller_DW.Integrator_DSTATE_j * 0.05F;

    /* Switch: '<S170>/Switch' incorporates:
     *  Inport: '<Root>/FMS_Out'
     *  Inport: '<Root>/INS_Out'
     */
    if (rtb_Compare_f) {
      rtb_Divide_m_idx_2 = Controller_U.FMS_Out.w_cmd;
    } else {
      rtb_Divide_m_idx_2 = Controller_U.INS_Out.vd;
    }

    /* End of Switch: '<S170>/Switch' */

    /* Sum: '<S174>/Add' incorporates:
     *  DiscreteIntegrator: '<S173>/Integrator1'
     *  Sum: '<S173>/Subtract'
     */
    u = (Controller_DW.Integrator1_DSTATE_e - rtb_Divide_m_idx_2) +
      rtb_Divide_m_idx_0;

    /* Signum: '<S174>/Sign' */
    if (u < 0.0F) {
      rtb_thor = -1.0F;
    } else if (u > 0.0F) {
      rtb_thor = 1.0F;
    } else {
      rtb_thor = u;
    }

    /* End of Signum: '<S174>/Sign' */

    /* Sum: '<S174>/Add2' incorporates:
     *  Abs: '<S174>/Abs'
     *  Gain: '<S174>/Gain'
     *  Gain: '<S174>/Gain1'
     *  Product: '<S174>/Multiply2'
     *  Product: '<S174>/Multiply3'
     *  Sqrt: '<S174>/Sqrt'
     *  Sum: '<S174>/Add1'
     *  Sum: '<S174>/Subtract'
     */
    rtb_thor = (sqrtf((8.0F * fabsf(u) + Controller_ConstB.d_i) *
                      Controller_ConstB.d_i) - Controller_ConstB.d_i) * 0.5F *
      rtb_thor + rtb_Divide_m_idx_0;

    /* Sum: '<S174>/Add4' */
    rtb_Divide_m_idx_0 += u - rtb_thor;

    /* Sum: '<S174>/Add3' */
    rtb_Divide_m_idx_2 = u + Controller_ConstB.d_i;

    /* Sum: '<S174>/Subtract1' */
    u -= Controller_ConstB.d_i;

    /* Signum: '<S174>/Sign1' */
    if (rtb_Divide_m_idx_2 < 0.0F) {
      rtb_Divide_m_idx_2 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_2 > 0.0F) {
        rtb_Divide_m_idx_2 = 1.0F;
      }
    }

    /* End of Signum: '<S174>/Sign1' */

    /* Signum: '<S174>/Sign2' */
    if (u < 0.0F) {
      u = -1.0F;
    } else {
      if (u > 0.0F) {
        u = 1.0F;
      }
    }

    /* End of Signum: '<S174>/Sign2' */

    /* Sum: '<S174>/Add5' incorporates:
     *  Gain: '<S174>/Gain2'
     *  Product: '<S174>/Multiply4'
     *  Sum: '<S174>/Subtract2'
     */
    rtb_thor += (rtb_Divide_m_idx_2 - u) * 0.5F * rtb_Divide_m_idx_0;

    /* Update for DiscreteIntegrator: '<S134>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S134>/gain1'
     *  Constant: '<S134>/gain2'
     *  Constant: '<S134>/gain3'
     *  DiscreteIntegrator: '<S131>/Discrete-Time Integrator5'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S134>/Multiply'
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

    /* End of Update for DiscreteIntegrator: '<S134>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S159>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_PrevRe_p = (int8_T)
      rtb_LogicalOperator_h;

    /* Update for DiscreteIntegrator: '<S161>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;

    /* Update for DiscreteIntegrator: '<S154>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S154>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE[0] += 0.002F *
      Controller_DW.Integrator_DSTATE[0];

    /* Update for DiscreteIntegrator: '<S159>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S159>/ki'
     *  Product: '<S159>/Multiply'
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

    /* Update for DiscreteIntegrator: '<S161>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] += 0.002F *
      rtb_Divide_m_idx_3;

    /* Update for DiscreteIntegrator: '<S154>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S154>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE[1] += 0.002F *
      Controller_DW.Integrator_DSTATE[1];

    /* Update for DiscreteIntegrator: '<S159>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S159>/ki'
     *  Product: '<S159>/Multiply'
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

    /* Update for DiscreteIntegrator: '<S161>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] += 0.002F * rtb_Gain_ow;
    Controller_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
      rtb_LogicalOperator_h;

    /* Update for DiscreteIntegrator: '<S131>/Discrete-Time Integrator5' */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_c = 0U;

    /* Update for DiscreteIntegrator: '<S136>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 0U;

    /* Update for DiscreteIntegrator: '<S131>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S131>/Gain'
     *  Saturate: '<S127>/Saturation'
     *  Sum: '<S131>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0] += (rtb_Divide_m_idx_1 -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S136>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[0] += 0.002F *
      rtb_Multiply_ni[0];

    /* Update for DiscreteIntegrator: '<S131>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S131>/Gain'
     *  Saturate: '<S127>/Saturation'
     *  Sum: '<S131>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1] += (rtb_Add_k -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S136>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[1] += 0.002F *
      rtb_Multiply_ni[1];

    /* Update for DiscreteIntegrator: '<S131>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S131>/Gain'
     *  Saturate: '<S127>/Saturation'
     *  Sum: '<S131>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2] += (rtb_Add1_j4 -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S136>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[2] += 0.002F *
      rtb_Multiply_ni[2];
    Controller_DW.DiscreteTimeIntegrator1_PrevR_k = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Signum: '<S157>/Sign3' incorporates:
     *  Product: '<S157>/Divide'
     *  Sum: '<S157>/Add6'
     */
    rtb_Divide_m_idx_2 = rtb_DiscreteTimeIntegrator1_n4 + Controller_ConstB.d;

    /* Signum: '<S157>/Sign4' incorporates:
     *  Product: '<S157>/Divide'
     *  Sum: '<S157>/Subtract3'
     */
    rtb_Divide_m_idx_1 = rtb_DiscreteTimeIntegrator1_n4 - Controller_ConstB.d;

    /* Signum: '<S157>/Sign5' incorporates:
     *  Product: '<S157>/Divide'
     */
    if (rtb_DiscreteTimeIntegrator1_n4 < 0.0F) {
      rtb_Divide_m_idx_0 = -1.0F;
    } else if (rtb_DiscreteTimeIntegrator1_n4 > 0.0F) {
      rtb_Divide_m_idx_0 = 1.0F;
    } else {
      rtb_Divide_m_idx_0 = rtb_DiscreteTimeIntegrator1_n4;
    }

    /* Signum: '<S157>/Sign3' */
    if (rtb_Divide_m_idx_2 < 0.0F) {
      rtb_Divide_m_idx_2 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_2 > 0.0F) {
        rtb_Divide_m_idx_2 = 1.0F;
      }
    }

    /* Signum: '<S157>/Sign4' */
    if (rtb_Divide_m_idx_1 < 0.0F) {
      rtb_Divide_m_idx_1 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_1 > 0.0F) {
        rtb_Divide_m_idx_1 = 1.0F;
      }
    }

    /* Signum: '<S157>/Sign6' incorporates:
     *  Product: '<S157>/Divide'
     */
    if (rtb_DiscreteTimeIntegrator1_n4 < 0.0F) {
      rtb_Saturation1 = -1.0F;
    } else if (rtb_DiscreteTimeIntegrator1_n4 > 0.0F) {
      rtb_Saturation1 = 1.0F;
    } else {
      rtb_Saturation1 = rtb_DiscreteTimeIntegrator1_n4;
    }

    /* Update for DiscreteIntegrator: '<S154>/Integrator' incorporates:
     *  Constant: '<S157>/const'
     *  Gain: '<S157>/Gain3'
     *  Product: '<S157>/Divide'
     *  Product: '<S157>/Multiply5'
     *  Product: '<S157>/Multiply6'
     *  Sum: '<S157>/Subtract4'
     *  Sum: '<S157>/Subtract5'
     *  Sum: '<S157>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE[0] += ((rtb_DiscreteTimeIntegrator1_n4 /
      Controller_ConstB.d - rtb_Divide_m_idx_0) * Controller_ConstB.Gain4 *
      ((rtb_Divide_m_idx_2 - rtb_Divide_m_idx_1) * 0.5F) - rtb_Saturation1 *
      58.836F) * 0.002F;

    /* Signum: '<S157>/Sign3' incorporates:
     *  Sum: '<S157>/Add6'
     */
    rtb_Divide_m_idx_2 = rtb_Add2_h + Controller_ConstB.d;

    /* Signum: '<S157>/Sign4' incorporates:
     *  Sum: '<S157>/Subtract3'
     */
    rtb_Divide_m_idx_1 = rtb_Add2_h - Controller_ConstB.d;

    /* Signum: '<S157>/Sign5' */
    if (rtb_Add2_h < 0.0F) {
      rtb_Divide_m_idx_0 = -1.0F;
    } else if (rtb_Add2_h > 0.0F) {
      rtb_Divide_m_idx_0 = 1.0F;
    } else {
      rtb_Divide_m_idx_0 = rtb_Add2_h;
    }

    /* Signum: '<S157>/Sign3' */
    if (rtb_Divide_m_idx_2 < 0.0F) {
      rtb_Divide_m_idx_2 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_2 > 0.0F) {
        rtb_Divide_m_idx_2 = 1.0F;
      }
    }

    /* Signum: '<S157>/Sign4' */
    if (rtb_Divide_m_idx_1 < 0.0F) {
      rtb_Divide_m_idx_1 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_1 > 0.0F) {
        rtb_Divide_m_idx_1 = 1.0F;
      }
    }

    /* Signum: '<S157>/Sign6' */
    if (rtb_Add2_h < 0.0F) {
      rtb_Saturation1 = -1.0F;
    } else if (rtb_Add2_h > 0.0F) {
      rtb_Saturation1 = 1.0F;
    } else {
      rtb_Saturation1 = rtb_Add2_h;
    }

    /* Update for DiscreteIntegrator: '<S154>/Integrator' incorporates:
     *  Constant: '<S157>/const'
     *  Gain: '<S157>/Gain3'
     *  Product: '<S157>/Divide'
     *  Product: '<S157>/Multiply5'
     *  Product: '<S157>/Multiply6'
     *  Sum: '<S157>/Subtract4'
     *  Sum: '<S157>/Subtract5'
     *  Sum: '<S157>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE[1] += ((rtb_Add2_h / Controller_ConstB.d -
      rtb_Divide_m_idx_0) * Controller_ConstB.Gain4 * ((rtb_Divide_m_idx_2 -
      rtb_Divide_m_idx_1) * 0.5F) - rtb_Saturation1 * 58.836F) * 0.002F;

    /* Update for DiscreteIntegrator: '<S173>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S173>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_e += 0.002F *
      Controller_DW.Integrator_DSTATE_j;

    /* Update for DiscreteIntegrator: '<S176>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S176>/ki'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S176>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_l += CONTROL_PARAM.MC_VEL_Z_I *
      rtb_VdotPg * 0.002F;
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

    /* End of Update for DiscreteIntegrator: '<S176>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S178>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_i += 0.002F * rtb_Sign5_f;
    Controller_DW.DiscreteTimeIntegrator1_Prev_ks = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Signum: '<S174>/Sign6' incorporates:
     *  Signum: '<S174>/Sign5'
     */
    if (rtb_thor < 0.0F) {
      rtb_DiscreteTimeIntegrator1_n4 = -1.0F;

      /* Signum: '<S174>/Sign5' */
      rtb_Divide_m_idx_0 = -1.0F;
    } else if (rtb_thor > 0.0F) {
      rtb_DiscreteTimeIntegrator1_n4 = 1.0F;

      /* Signum: '<S174>/Sign5' */
      rtb_Divide_m_idx_0 = 1.0F;
    } else {
      rtb_DiscreteTimeIntegrator1_n4 = rtb_thor;

      /* Signum: '<S174>/Sign5' */
      rtb_Divide_m_idx_0 = rtb_thor;
    }

    /* End of Signum: '<S174>/Sign6' */

    /* Sum: '<S174>/Add6' */
    rtb_Divide_m_idx_2 = rtb_thor + Controller_ConstB.d_i;

    /* Sum: '<S174>/Subtract3' */
    rtb_Divide_m_idx_1 = rtb_thor - Controller_ConstB.d_i;

    /* Signum: '<S174>/Sign3' */
    if (rtb_Divide_m_idx_2 < 0.0F) {
      rtb_Divide_m_idx_2 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_2 > 0.0F) {
        rtb_Divide_m_idx_2 = 1.0F;
      }
    }

    /* End of Signum: '<S174>/Sign3' */

    /* Signum: '<S174>/Sign4' */
    if (rtb_Divide_m_idx_1 < 0.0F) {
      rtb_Divide_m_idx_1 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_1 > 0.0F) {
        rtb_Divide_m_idx_1 = 1.0F;
      }
    }

    /* End of Signum: '<S174>/Sign4' */

    /* Update for DiscreteIntegrator: '<S173>/Integrator' incorporates:
     *  Constant: '<S174>/const'
     *  Gain: '<S174>/Gain3'
     *  Product: '<S174>/Divide'
     *  Product: '<S174>/Multiply5'
     *  Product: '<S174>/Multiply6'
     *  Sum: '<S174>/Subtract4'
     *  Sum: '<S174>/Subtract5'
     *  Sum: '<S174>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE_j += ((rtb_thor / Controller_ConstB.d_i -
      rtb_Divide_m_idx_0) * Controller_ConstB.Gain4_p * ((rtb_Divide_m_idx_2 -
      rtb_Divide_m_idx_1) * 0.5F) - rtb_DiscreteTimeIntegrator1_n4 * 78.448F) *
      0.002F;
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

  /* Outputs for Atomic SubSystem: '<S8>/VTOL_Control_Allocation' */
#if AIRFRAME == 1

  /* Output and update for atomic system: '<S180>/VTOL1' */
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

    /* Saturate: '<S197>/Saturation' incorporates:
     *  Bias: '<S197>/Bias'
     *  Bias: '<S197>/Bias1'
     *  Bias: '<S197>/Bias2'
     *  Bias: '<S197>/Bias3'
     *  Constant: '<S197>/Constant'
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

    /* End of Saturate: '<S197>/Saturation' */

    /* Saturate: '<S184>/Saturation1' */
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

    /* End of Saturate: '<S184>/Saturation1' */

    /* Gain: '<S184>/Gain1' incorporates:
     *  Bias: '<S184>/Bias'
     *  Constant: '<S184>/Constant'
     */
    rtb_Gain1_l = ((real32_T)CONTROL_PARAM.MC_OUT_MAX + -1000.0F) * 0.001F;

    /* Saturate: '<S184>/Saturation2' */
    if (rtb_Multiply3[2] > 1.0F) {
      rtb_Saturation3_j = 1.0F;
    } else if (rtb_Multiply3[2] < 0.0F) {
      rtb_Saturation3_j = 0.0F;
    } else {
      rtb_Saturation3_j = rtb_Multiply3[2];
    }

    /* End of Saturate: '<S184>/Saturation2' */
    for (i_p = 0; i_p < 4; i_p++) {
      /* Product: '<S184>/Multiply' */
      rtb_Switch_gr_idx_1_p = Controller_ConstB.VTOL1.pq_column[i_p + 4] *
        rtb_Saturation1_l_idx_1_p + Controller_ConstB.VTOL1.pq_column[i_p] *
        rtb_Saturation1_l_idx_0_p;

      /* Sum: '<S184>/Sum' */
      rtb_Sum_e[i_p] = rtb_Switch_gr_idx_1_p + rtb_Saturation3_j;

      /* Product: '<S184>/Multiply' */
      rtb_floating_yaw[i_p] = rtb_Switch_gr_idx_1_p;
    }

    /* Gain: '<S184>/Gain2' incorporates:
     *  Bias: '<S184>/Bias1'
     *  Constant: '<S184>/Constant1'
     */
    rtb_Saturation1_l_idx_0_p = ((real32_T)CONTROL_PARAM.MC_OUT_MIN + -1000.0F) *
      0.001F;

    /* MinMax: '<S184>/Max' */
    rtb_Switch_gr_idx_1_p = fmaxf(fmaxf(fmaxf(rtb_Sum_e[0], rtb_Sum_e[1]),
      rtb_Sum_e[2]), rtb_Sum_e[3]);

    /* MinMax: '<S184>/Max1' */
    rtb_Saturation1_l_idx_1_p = fminf(fminf(fminf(rtb_Sum_e[0], rtb_Sum_e[1]),
      rtb_Sum_e[2]), rtb_Sum_e[3]);

    /* Switch: '<S191>/Switch' incorporates:
     *  Logic: '<S191>/Logical Operator'
     *  MinMax: '<S184>/Max'
     *  MinMax: '<S184>/Max1'
     *  RelationalOperator: '<S191>/Relational Operator'
     *  RelationalOperator: '<S191>/Relational Operator1'
     */
    if ((rtb_Switch_gr_idx_1_p > rtb_Gain1_l) || (rtb_Saturation1_l_idx_1_p <
         rtb_Saturation1_l_idx_0_p)) {
      /* Sum: '<S191>/Subtract1' */
      rtb_Switch_gr_idx_0_p = rtb_Gain1_l - rtb_Saturation1_l_idx_0_p;

      /* Sum: '<S191>/Subtract' */
      rtb_Subtract_h = rtb_Switch_gr_idx_1_p - rtb_Saturation1_l_idx_1_p;

      /* Switch: '<S191>/Switch1' incorporates:
       *  Constant: '<S191>/Constant3'
       *  Gain: '<S191>/Gain'
       *  Product: '<S191>/Divide'
       *  RelationalOperator: '<S191>/Relational Operator2'
       *  Sum: '<S191>/Add'
       *  Sum: '<S191>/Subtract2'
       *  Sum: '<S191>/Subtract3'
       */
      if (rtb_Subtract_h > rtb_Switch_gr_idx_0_p) {
        rtb_Switch_gr_idx_0_p /= rtb_Subtract_h;
        rtb_Switch_gr_idx_1_p = ((rtb_Gain1_l - rtb_Switch_gr_idx_1_p) +
          (rtb_Saturation1_l_idx_0_p - rtb_Saturation1_l_idx_1_p)) * 0.5F;
      } else {
        rtb_Switch_gr_idx_0_p = 1.0F;

        /* Switch: '<S191>/Switch2' incorporates:
         *  Constant: '<S191>/Constant3'
         *  RelationalOperator: '<S191>/Relational Operator3'
         *  Sum: '<S191>/Subtract4'
         *  Sum: '<S191>/Subtract5'
         */
        if (rtb_Switch_gr_idx_1_p > rtb_Gain1_l) {
          rtb_Switch_gr_idx_1_p = rtb_Gain1_l - rtb_Switch_gr_idx_1_p;
        } else {
          rtb_Switch_gr_idx_1_p = rtb_Saturation1_l_idx_0_p -
            rtb_Saturation1_l_idx_1_p;
        }

        /* End of Switch: '<S191>/Switch2' */
      }

      /* End of Switch: '<S191>/Switch1' */
    } else {
      rtb_Switch_gr_idx_0_p = 1.0F;
      rtb_Switch_gr_idx_1_p = 0.0F;
    }

    /* End of Switch: '<S191>/Switch' */

    /* Sum: '<S184>/Sum1' */
    rtb_Saturation3_j += rtb_Switch_gr_idx_1_p;

    /* Saturate: '<S184>/Saturation3' */
    if (rtb_Saturation3_j > 1.0F) {
      rtb_Saturation3_j = 1.0F;
    } else {
      if (rtb_Saturation3_j < 0.0F) {
        rtb_Saturation3_j = 0.0F;
      }
    }

    /* End of Saturate: '<S184>/Saturation3' */

    /* Sum: '<S184>/Sum2' incorporates:
     *  Product: '<S184>/Multiply1'
     */
    rtb_Switch_gr_idx_1_p = rtb_floating_yaw[0] * rtb_Switch_gr_idx_0_p +
      rtb_Saturation3_j;

    /* Saturate: '<S184>/Saturation4' */
    if (rtb_Switch_gr_idx_1_p > 1.0F) {
      rtb_Switch_gr_idx_1_p = 1.0F;
    } else {
      if (rtb_Switch_gr_idx_1_p < 0.0F) {
        rtb_Switch_gr_idx_1_p = 0.0F;
      }
    }

    /* Sum: '<S184>/Sum3' incorporates:
     *  Product: '<S184>/Multiply2'
     */
    rtb_Sum_e[0] = Controller_ConstB.VTOL1.r_column[0] *
      rtb_Saturation1_l_idx_2_p + rtb_Switch_gr_idx_1_p;

    /* Product: '<S184>/Multiply1' */
    rtb_floating_yaw[0] = rtb_Switch_gr_idx_1_p;

    /* Sum: '<S184>/Sum2' incorporates:
     *  Product: '<S184>/Multiply1'
     */
    rtb_Switch_gr_idx_1_p = rtb_floating_yaw[1] * rtb_Switch_gr_idx_0_p +
      rtb_Saturation3_j;

    /* Saturate: '<S184>/Saturation4' */
    if (rtb_Switch_gr_idx_1_p > 1.0F) {
      rtb_Switch_gr_idx_1_p = 1.0F;
    } else {
      if (rtb_Switch_gr_idx_1_p < 0.0F) {
        rtb_Switch_gr_idx_1_p = 0.0F;
      }
    }

    /* Sum: '<S184>/Sum3' incorporates:
     *  Product: '<S184>/Multiply2'
     */
    rtb_Sum_e[1] = Controller_ConstB.VTOL1.r_column[1] *
      rtb_Saturation1_l_idx_2_p + rtb_Switch_gr_idx_1_p;

    /* Product: '<S184>/Multiply1' */
    rtb_floating_yaw[1] = rtb_Switch_gr_idx_1_p;

    /* Sum: '<S184>/Sum2' incorporates:
     *  Product: '<S184>/Multiply1'
     */
    rtb_Switch_gr_idx_1_p = rtb_floating_yaw[2] * rtb_Switch_gr_idx_0_p +
      rtb_Saturation3_j;

    /* Saturate: '<S184>/Saturation4' */
    if (rtb_Switch_gr_idx_1_p > 1.0F) {
      rtb_Switch_gr_idx_1_p = 1.0F;
    } else {
      if (rtb_Switch_gr_idx_1_p < 0.0F) {
        rtb_Switch_gr_idx_1_p = 0.0F;
      }
    }

    /* Sum: '<S184>/Sum3' incorporates:
     *  Product: '<S184>/Multiply2'
     */
    rtb_Sum_e[2] = Controller_ConstB.VTOL1.r_column[2] *
      rtb_Saturation1_l_idx_2_p + rtb_Switch_gr_idx_1_p;

    /* Product: '<S184>/Multiply1' */
    rtb_floating_yaw[2] = rtb_Switch_gr_idx_1_p;

    /* Sum: '<S184>/Sum2' incorporates:
     *  Product: '<S184>/Multiply1'
     */
    rtb_Switch_gr_idx_1_p = rtb_floating_yaw[3] * rtb_Switch_gr_idx_0_p +
      rtb_Saturation3_j;

    /* Saturate: '<S184>/Saturation4' */
    if (rtb_Switch_gr_idx_1_p > 1.0F) {
      rtb_Switch_gr_idx_1_p = 1.0F;
    } else {
      if (rtb_Switch_gr_idx_1_p < 0.0F) {
        rtb_Switch_gr_idx_1_p = 0.0F;
      }
    }

    /* Sum: '<S184>/Sum3' incorporates:
     *  Product: '<S184>/Multiply2'
     */
    rtb_Sum_e[3] = Controller_ConstB.VTOL1.r_column[3] *
      rtb_Saturation1_l_idx_2_p + rtb_Switch_gr_idx_1_p;

    /* Product: '<S184>/Multiply1' */
    rtb_floating_yaw[3] = rtb_Switch_gr_idx_1_p;

    /* MATLAB Function: '<S184>/R_Remix' */
    Controller_R_Remix(rtb_Sum_e, rtb_Gain1_l, rtb_Saturation1_l_idx_0_p,
                       rtb_floating_yaw);

    /* MultiPortSwitch: '<S187>/Multiport Switch' incorporates:
     *  Constant: '<S188>/Constant1'
     *  Constant: '<S188>/Constant12'
     *  Constant: '<S188>/Constant2'
     *  Constant: '<S188>/Constant7'
     *  DataTypeConversion: '<S197>/Data Type Conversion'
     *  DataTypeConversion: '<S198>/Data Type Conversion'
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
        /* Saturate: '<S198>/Saturation' incorporates:
         *  Constant: '<S198>/Standby'
         *  Reshape: '<S198>/Reshape'
         */
        if (Controller_ConstP.pooled31[i_p] > 2000.0F) {
          rtb_Saturation1_l_idx_2_p = 2000.0F;
        } else if (Controller_ConstP.pooled31[i_p] < 1000.0F) {
          rtb_Saturation1_l_idx_2_p = 1000.0F;
        } else {
          rtb_Saturation1_l_idx_2_p = Controller_ConstP.pooled31[i_p];
        }

        rtb_VariantMergeForOutportactua[i_p] = (uint16_T)fmodf(floorf
          (rtb_Saturation1_l_idx_2_p), 65536.0F);
      }

      /* Saturate: '<S198>/Saturation' incorporates:
       *  Bias: '<S198>/Bias'
       *  Constant: '<S198>/Constant'
       *  DataTypeConversion: '<S198>/Data Type Conversion'
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

      /* Saturate: '<S198>/Saturation' incorporates:
       *  Bias: '<S198>/Bias1'
       *  Constant: '<S198>/Constant'
       *  DataTypeConversion: '<S198>/Data Type Conversion'
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

      /* Saturate: '<S198>/Saturation' incorporates:
       *  Bias: '<S198>/Bias2'
       *  Constant: '<S198>/Constant'
       *  DataTypeConversion: '<S198>/Data Type Conversion'
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

      /* Saturate: '<S198>/Saturation' incorporates:
       *  Bias: '<S198>/Bias3'
       *  Constant: '<S198>/Constant'
       *  DataTypeConversion: '<S198>/Data Type Conversion'
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

      /* SignalConversion: '<S188>/ConcatBufferAtVector Concatenate2In3' incorporates:
       *  Constant: '<S188>/Constant11'
       *  Constant: '<S188>/Constant12'
       */
      rtb_MatrixConcatenate[10] = 0.0F;

      /* SignalConversion: '<S188>/ConcatBufferAtVector Concatenate2In2' incorporates:
       *  Constant: '<S188>/Constant10'
       */
      rtb_MatrixConcatenate[9] = 0.0F;

      /* SignalConversion: '<S188>/ConcatBufferAtVector Concatenate2In1' incorporates:
       *  Constant: '<S188>/Constant9'
       */
      rtb_MatrixConcatenate[8] = 0.0F;

      /* SignalConversion: '<S188>/ConcatBufferAtVector Concatenate1In4' incorporates:
       *  Constant: '<S188>/Constant8'
       */
      rtb_MatrixConcatenate[7] = 0.0F;
      rtb_MatrixConcatenate[6] = CONTROL_PARAM.FW_PITCH_EFFC *
        CONTROL_PARAM.FW_ELEVATOR_DIR;

      /* SignalConversion: '<S188>/ConcatBufferAtVector Concatenate1In2' incorporates:
       *  Constant: '<S188>/Constant6'
       *  Constant: '<S188>/Constant7'
       */
      rtb_MatrixConcatenate[5] = 0.0F;

      /* SignalConversion: '<S188>/ConcatBufferAtVector Concatenate1In1' incorporates:
       *  Constant: '<S188>/Constant5'
       */
      rtb_MatrixConcatenate[4] = 0.0F;

      /* SignalConversion: '<S188>/ConcatBufferAtVector ConcatenateIn4' incorporates:
       *  Constant: '<S188>/Constant4'
       */
      rtb_MatrixConcatenate[3] = 0.0F;

      /* SignalConversion: '<S188>/ConcatBufferAtVector ConcatenateIn3' incorporates:
       *  Constant: '<S188>/Constant3'
       */
      rtb_MatrixConcatenate[2] = 0.0F;
      rtb_MatrixConcatenate[1] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON2_DIR;
      rtb_MatrixConcatenate[0] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON1_DIR;

      /* Saturate: '<S183>/Saturation5' incorporates:
       *  Constant: '<S188>/Constant1'
       *  Constant: '<S188>/Constant2'
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

      /* End of Saturate: '<S183>/Saturation5' */
      for (i_p = 0; i_p < 4; i_p++) {
        /* Bias: '<S183>/Bias' incorporates:
         *  Gain: '<S183>/Gain1'
         *  Product: '<S183>/Multiply1'
         */
        rtb_Saturation5_o[i_p] = 500.0F * (rtb_MatrixConcatenate[i_p + 8] *
          rtb_Saturation3_j + (rtb_MatrixConcatenate[i_p + 4] * rtb_Gain1_l +
          rtb_MatrixConcatenate[i_p] * rtb_Saturation1_l_idx_2_p)) + 1500.0F;

        /* Sum: '<S184>/Sum4' */
        rtb_Saturation1_l_idx_0_p = rtb_Sum_e[i_p] + rtb_floating_yaw[i_p];

        /* Saturate: '<S184>/Saturation5' */
        if (rtb_Saturation1_l_idx_0_p > 1.0F) {
          rtb_Saturation1_l_idx_0_p = 1.0F;
        } else {
          if (rtb_Saturation1_l_idx_0_p < 0.0F) {
            rtb_Saturation1_l_idx_0_p = 0.0F;
          }
        }

        /* End of Saturate: '<S184>/Saturation5' */

        /* DataTypeConversion: '<S184>/Data Type Conversion' incorporates:
         *  Constant: '<S184>/Constant2'
         *  Gain: '<S184>/Gain3'
         *  Sum: '<S184>/Sum5'
         */
        u0_p = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          rtb_Saturation1_l_idx_0_p), 4.2949673E+9F) + 1000U);

        /* Saturate: '<S184>/Saturation' */
        if (u0_p > CONTROL_PARAM.MC_OUT_MAX) {
          rtb_VariantMergeForOutportactua[i_p] = CONTROL_PARAM.MC_OUT_MAX;
        } else if (u0_p < CONTROL_PARAM.MC_OUT_MIN) {
          rtb_VariantMergeForOutportactua[i_p] = CONTROL_PARAM.MC_OUT_MIN;
        } else {
          rtb_VariantMergeForOutportactua[i_p] = u0_p;
        }

        /* End of Saturate: '<S184>/Saturation' */
      }

      /* Saturate: '<S183>/Saturation' */
      if (rtb_Multiply1[0] > 1.0F) {
        rtb_Saturation1_l_idx_2_p = 1.0F;
      } else if (rtb_Multiply1[0] < 0.0F) {
        rtb_Saturation1_l_idx_2_p = 0.0F;
      } else {
        rtb_Saturation1_l_idx_2_p = rtb_Multiply1[0];
      }

      /* End of Saturate: '<S183>/Saturation' */

      /* DataTypeConversion: '<S190>/Data Type Conversion' incorporates:
       *  Constant: '<S190>/Constant1'
       *  Gain: '<S190>/Gain1'
       *  Sum: '<S190>/Sum1'
       */
      u0_p = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
        rtb_Saturation1_l_idx_2_p), 4.2949673E+9F) + 1000U);

      /* Saturate: '<S183>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[4] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[4] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[4] = u0_p;
      }

      /* DataTypeConversion: '<S183>/Data Type Conversion' incorporates:
       *  Bias: '<S183>/Bias1'
       */
      rtb_Saturation1_l_idx_2_p = fmodf(floorf(rtb_Saturation5_o[0] +
        CONTROL_PARAM.SERVO1_BIAS), 65536.0F);
      u0_p = (uint16_T)(rtb_Saturation1_l_idx_2_p < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_l_idx_2_p :
                        (int32_T)(uint16_T)rtb_Saturation1_l_idx_2_p);

      /* Saturate: '<S183>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[5] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[5] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[5] = u0_p;
      }

      /* DataTypeConversion: '<S183>/Data Type Conversion1' incorporates:
       *  Bias: '<S183>/Bias2'
       */
      rtb_Saturation1_l_idx_2_p = fmodf(floorf(rtb_Saturation5_o[1] +
        CONTROL_PARAM.SERVO2_BIAS), 65536.0F);
      u0_p = (uint16_T)(rtb_Saturation1_l_idx_2_p < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_l_idx_2_p :
                        (int32_T)(uint16_T)rtb_Saturation1_l_idx_2_p);

      /* Saturate: '<S183>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[6] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[6] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[6] = u0_p;
      }

      /* DataTypeConversion: '<S183>/Data Type Conversion2' incorporates:
       *  Bias: '<S183>/Bias3'
       */
      rtb_Saturation1_l_idx_2_p = fmodf(floorf(rtb_Saturation5_o[2] +
        CONTROL_PARAM.SERVO3_BIAS), 65536.0F);
      u0_p = (uint16_T)(rtb_Saturation1_l_idx_2_p < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_l_idx_2_p :
                        (int32_T)(uint16_T)rtb_Saturation1_l_idx_2_p);

      /* Saturate: '<S183>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[7] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[7] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[7] = u0_p;
      }

      /* DataTypeConversion: '<S183>/Data Type Conversion3' incorporates:
       *  Bias: '<S183>/Bias4'
       */
      rtb_Saturation1_l_idx_2_p = fmodf(floorf(rtb_Saturation5_o[3] +
        CONTROL_PARAM.SERVO4_BIAS), 65536.0F);
      u0_p = (uint16_T)(rtb_Saturation1_l_idx_2_p < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_l_idx_2_p :
                        (int32_T)(uint16_T)rtb_Saturation1_l_idx_2_p);

      /* Saturate: '<S183>/Saturation1' */
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

    /* End of MultiPortSwitch: '<S187>/Multiport Switch' */
  }

#elif AIRFRAME == 2

  /* Output and update for atomic system: '<S180>/VTOL2' */
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

    /* Saturate: '<S209>/Saturation' incorporates:
     *  Bias: '<S209>/Bias'
     *  Bias: '<S209>/Bias1'
     *  Bias: '<S209>/Bias2'
     *  Bias: '<S209>/Bias3'
     *  Constant: '<S209>/Constant'
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

    /* End of Saturate: '<S209>/Saturation' */

    /* Saturate: '<S200>/Saturation1' */
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

    /* End of Saturate: '<S200>/Saturation1' */

    /* Gain: '<S200>/Gain1' incorporates:
     *  Bias: '<S200>/Bias'
     *  Constant: '<S200>/Constant'
     */
    rtb_Gain1_lm = ((real32_T)CONTROL_PARAM.MC_OUT_MAX + -1000.0F) * 0.001F;

    /* Saturate: '<S200>/Saturation2' */
    if (rtb_Multiply3[2] > 1.0F) {
      rtb_Saturation3_c = 1.0F;
    } else if (rtb_Multiply3[2] < 0.0F) {
      rtb_Saturation3_c = 0.0F;
    } else {
      rtb_Saturation3_c = rtb_Multiply3[2];
    }

    /* End of Saturate: '<S200>/Saturation2' */
    for (i_o = 0; i_o < 4; i_o++) {
      /* Product: '<S200>/Multiply' */
      rtb_Switch_ge_idx_1_o = Controller_ConstB.VTOL2.pq_column[i_o + 4] *
        rtb_Saturation1_p_idx_1_o + Controller_ConstB.VTOL2.pq_column[i_o] *
        rtb_Saturation1_p_idx_0_o;

      /* Sum: '<S200>/Sum' */
      rtb_Sum_m[i_o] = rtb_Switch_ge_idx_1_o + rtb_Saturation3_c;

      /* Product: '<S200>/Multiply' */
      rtb_floating_yaw_n[i_o] = rtb_Switch_ge_idx_1_o;
    }

    /* Gain: '<S200>/Gain2' incorporates:
     *  Bias: '<S200>/Bias1'
     *  Constant: '<S200>/Constant1'
     */
    rtb_Saturation1_p_idx_0_o = ((real32_T)CONTROL_PARAM.MC_OUT_MIN + -1000.0F) *
      0.001F;

    /* MinMax: '<S200>/Max' */
    rtb_Switch_ge_idx_1_o = fmaxf(fmaxf(fmaxf(rtb_Sum_m[0], rtb_Sum_m[1]),
      rtb_Sum_m[2]), rtb_Sum_m[3]);

    /* MinMax: '<S200>/Max1' */
    rtb_Saturation1_p_idx_1_o = fminf(fminf(fminf(rtb_Sum_m[0], rtb_Sum_m[1]),
      rtb_Sum_m[2]), rtb_Sum_m[3]);

    /* Switch: '<S206>/Switch' incorporates:
     *  Logic: '<S206>/Logical Operator'
     *  MinMax: '<S200>/Max'
     *  MinMax: '<S200>/Max1'
     *  RelationalOperator: '<S206>/Relational Operator'
     *  RelationalOperator: '<S206>/Relational Operator1'
     */
    if ((rtb_Switch_ge_idx_1_o > rtb_Gain1_lm) || (rtb_Saturation1_p_idx_1_o <
         rtb_Saturation1_p_idx_0_o)) {
      /* Sum: '<S206>/Subtract1' */
      rtb_Switch_ge_idx_0_o = rtb_Gain1_lm - rtb_Saturation1_p_idx_0_o;

      /* Sum: '<S206>/Subtract' */
      rtb_Subtract_g = rtb_Switch_ge_idx_1_o - rtb_Saturation1_p_idx_1_o;

      /* Switch: '<S206>/Switch1' incorporates:
       *  Constant: '<S206>/Constant3'
       *  Gain: '<S206>/Gain'
       *  Product: '<S206>/Divide'
       *  RelationalOperator: '<S206>/Relational Operator2'
       *  Sum: '<S206>/Add'
       *  Sum: '<S206>/Subtract2'
       *  Sum: '<S206>/Subtract3'
       */
      if (rtb_Subtract_g > rtb_Switch_ge_idx_0_o) {
        rtb_Switch_ge_idx_0_o /= rtb_Subtract_g;
        rtb_Switch_ge_idx_1_o = ((rtb_Gain1_lm - rtb_Switch_ge_idx_1_o) +
          (rtb_Saturation1_p_idx_0_o - rtb_Saturation1_p_idx_1_o)) * 0.5F;
      } else {
        rtb_Switch_ge_idx_0_o = 1.0F;

        /* Switch: '<S206>/Switch2' incorporates:
         *  Constant: '<S206>/Constant3'
         *  RelationalOperator: '<S206>/Relational Operator3'
         *  Sum: '<S206>/Subtract4'
         *  Sum: '<S206>/Subtract5'
         */
        if (rtb_Switch_ge_idx_1_o > rtb_Gain1_lm) {
          rtb_Switch_ge_idx_1_o = rtb_Gain1_lm - rtb_Switch_ge_idx_1_o;
        } else {
          rtb_Switch_ge_idx_1_o = rtb_Saturation1_p_idx_0_o -
            rtb_Saturation1_p_idx_1_o;
        }

        /* End of Switch: '<S206>/Switch2' */
      }

      /* End of Switch: '<S206>/Switch1' */
    } else {
      rtb_Switch_ge_idx_0_o = 1.0F;
      rtb_Switch_ge_idx_1_o = 0.0F;
    }

    /* End of Switch: '<S206>/Switch' */

    /* Sum: '<S200>/Sum1' */
    rtb_Saturation3_c += rtb_Switch_ge_idx_1_o;

    /* Saturate: '<S200>/Saturation3' */
    if (rtb_Saturation3_c > 1.0F) {
      rtb_Saturation3_c = 1.0F;
    } else {
      if (rtb_Saturation3_c < 0.0F) {
        rtb_Saturation3_c = 0.0F;
      }
    }

    /* End of Saturate: '<S200>/Saturation3' */

    /* Sum: '<S200>/Sum2' incorporates:
     *  Product: '<S200>/Multiply1'
     */
    rtb_Switch_ge_idx_1_o = rtb_floating_yaw_n[0] * rtb_Switch_ge_idx_0_o +
      rtb_Saturation3_c;

    /* Saturate: '<S200>/Saturation4' */
    if (rtb_Switch_ge_idx_1_o > 1.0F) {
      rtb_Switch_ge_idx_1_o = 1.0F;
    } else {
      if (rtb_Switch_ge_idx_1_o < 0.0F) {
        rtb_Switch_ge_idx_1_o = 0.0F;
      }
    }

    /* Sum: '<S200>/Sum3' incorporates:
     *  Product: '<S200>/Multiply2'
     */
    rtb_Sum_m[0] = Controller_ConstB.VTOL2.r_column[0] *
      rtb_Saturation1_p_idx_2_o + rtb_Switch_ge_idx_1_o;

    /* Product: '<S200>/Multiply1' */
    rtb_floating_yaw_n[0] = rtb_Switch_ge_idx_1_o;

    /* Sum: '<S200>/Sum2' incorporates:
     *  Product: '<S200>/Multiply1'
     */
    rtb_Switch_ge_idx_1_o = rtb_floating_yaw_n[1] * rtb_Switch_ge_idx_0_o +
      rtb_Saturation3_c;

    /* Saturate: '<S200>/Saturation4' */
    if (rtb_Switch_ge_idx_1_o > 1.0F) {
      rtb_Switch_ge_idx_1_o = 1.0F;
    } else {
      if (rtb_Switch_ge_idx_1_o < 0.0F) {
        rtb_Switch_ge_idx_1_o = 0.0F;
      }
    }

    /* Sum: '<S200>/Sum3' incorporates:
     *  Product: '<S200>/Multiply2'
     */
    rtb_Sum_m[1] = Controller_ConstB.VTOL2.r_column[1] *
      rtb_Saturation1_p_idx_2_o + rtb_Switch_ge_idx_1_o;

    /* Product: '<S200>/Multiply1' */
    rtb_floating_yaw_n[1] = rtb_Switch_ge_idx_1_o;

    /* Sum: '<S200>/Sum2' incorporates:
     *  Product: '<S200>/Multiply1'
     */
    rtb_Switch_ge_idx_1_o = rtb_floating_yaw_n[2] * rtb_Switch_ge_idx_0_o +
      rtb_Saturation3_c;

    /* Saturate: '<S200>/Saturation4' */
    if (rtb_Switch_ge_idx_1_o > 1.0F) {
      rtb_Switch_ge_idx_1_o = 1.0F;
    } else {
      if (rtb_Switch_ge_idx_1_o < 0.0F) {
        rtb_Switch_ge_idx_1_o = 0.0F;
      }
    }

    /* Sum: '<S200>/Sum3' incorporates:
     *  Product: '<S200>/Multiply2'
     */
    rtb_Sum_m[2] = Controller_ConstB.VTOL2.r_column[2] *
      rtb_Saturation1_p_idx_2_o + rtb_Switch_ge_idx_1_o;

    /* Product: '<S200>/Multiply1' */
    rtb_floating_yaw_n[2] = rtb_Switch_ge_idx_1_o;

    /* Sum: '<S200>/Sum2' incorporates:
     *  Product: '<S200>/Multiply1'
     */
    rtb_Switch_ge_idx_1_o = rtb_floating_yaw_n[3] * rtb_Switch_ge_idx_0_o +
      rtb_Saturation3_c;

    /* Saturate: '<S200>/Saturation4' */
    if (rtb_Switch_ge_idx_1_o > 1.0F) {
      rtb_Switch_ge_idx_1_o = 1.0F;
    } else {
      if (rtb_Switch_ge_idx_1_o < 0.0F) {
        rtb_Switch_ge_idx_1_o = 0.0F;
      }
    }

    /* Sum: '<S200>/Sum3' incorporates:
     *  Product: '<S200>/Multiply2'
     */
    rtb_Sum_m[3] = Controller_ConstB.VTOL2.r_column[3] *
      rtb_Saturation1_p_idx_2_o + rtb_Switch_ge_idx_1_o;

    /* Product: '<S200>/Multiply1' */
    rtb_floating_yaw_n[3] = rtb_Switch_ge_idx_1_o;

    /* MATLAB Function: '<S200>/R_Remix' */
    Controller_R_Remix(rtb_Sum_m, rtb_Gain1_lm, rtb_Saturation1_p_idx_0_o,
                       rtb_floating_yaw_n);

    /* MultiPortSwitch: '<S202>/Multiport Switch' incorporates:
     *  Constant: '<S203>/Constant1'
     *  Constant: '<S203>/Constant11'
     *  Constant: '<S203>/Constant12'
     *  Constant: '<S203>/Constant2'
     *  Constant: '<S203>/Constant7'
     *  Constant: '<S203>/Constant8'
     *  DataTypeConversion: '<S209>/Data Type Conversion'
     *  DataTypeConversion: '<S210>/Data Type Conversion'
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
        /* Saturate: '<S210>/Saturation' incorporates:
         *  Constant: '<S210>/Disarm'
         *  Reshape: '<S210>/Reshape'
         */
        if (Controller_ConstP.pooled31[i_o] > 2000.0F) {
          rtb_Saturation1_p_idx_2_o = 2000.0F;
        } else if (Controller_ConstP.pooled31[i_o] < 1000.0F) {
          rtb_Saturation1_p_idx_2_o = 1000.0F;
        } else {
          rtb_Saturation1_p_idx_2_o = Controller_ConstP.pooled31[i_o];
        }

        rtb_VariantMergeForOutportactua[i_o] = (uint16_T)fmodf(floorf
          (rtb_Saturation1_p_idx_2_o), 65536.0F);
      }

      /* Saturate: '<S210>/Saturation' incorporates:
       *  Bias: '<S210>/Bias'
       *  Constant: '<S210>/Constant'
       *  DataTypeConversion: '<S210>/Data Type Conversion'
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

      /* Saturate: '<S210>/Saturation' incorporates:
       *  Bias: '<S210>/Bias1'
       *  Constant: '<S210>/Constant'
       *  DataTypeConversion: '<S210>/Data Type Conversion'
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

      /* Saturate: '<S210>/Saturation' incorporates:
       *  Bias: '<S210>/Bias2'
       *  Constant: '<S210>/Constant'
       *  DataTypeConversion: '<S210>/Data Type Conversion'
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

      /* Saturate: '<S210>/Saturation' incorporates:
       *  Bias: '<S210>/Bias3'
       *  Constant: '<S210>/Constant'
       *  DataTypeConversion: '<S210>/Data Type Conversion'
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

      /* SignalConversion: '<S203>/ConcatBufferAtVector Concatenate2In2' incorporates:
       *  Constant: '<S203>/Constant10'
       *  Constant: '<S203>/Constant11'
       *  Constant: '<S203>/Constant12'
       */
      rtb_MatrixConcatenate_g[9] = 0.0F;

      /* SignalConversion: '<S203>/ConcatBufferAtVector Concatenate2In1' incorporates:
       *  Constant: '<S203>/Constant9'
       */
      rtb_MatrixConcatenate_g[8] = 0.0F;
      rtb_MatrixConcatenate_g[7] = -CONTROL_PARAM.FW_PITCH_EFFC *
        CONTROL_PARAM.FW_TAIL2_DIR;
      rtb_MatrixConcatenate_g[6] = CONTROL_PARAM.FW_PITCH_EFFC *
        CONTROL_PARAM.FW_TAIL1_DIR;

      /* SignalConversion: '<S203>/ConcatBufferAtVector Concatenate1In2' incorporates:
       *  Constant: '<S203>/Constant6'
       *  Constant: '<S203>/Constant7'
       *  Constant: '<S203>/Constant8'
       */
      rtb_MatrixConcatenate_g[5] = 0.0F;

      /* SignalConversion: '<S203>/ConcatBufferAtVector Concatenate1In1' incorporates:
       *  Constant: '<S203>/Constant5'
       */
      rtb_MatrixConcatenate_g[4] = 0.0F;

      /* SignalConversion: '<S203>/ConcatBufferAtVector ConcatenateIn4' incorporates:
       *  Constant: '<S203>/Constant4'
       */
      rtb_MatrixConcatenate_g[3] = 0.0F;

      /* SignalConversion: '<S203>/ConcatBufferAtVector ConcatenateIn3' incorporates:
       *  Constant: '<S203>/Constant3'
       */
      rtb_MatrixConcatenate_g[2] = 0.0F;
      rtb_MatrixConcatenate_g[1] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON2_DIR;
      rtb_MatrixConcatenate_g[0] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON1_DIR;

      /* Saturate: '<S199>/Saturation5' incorporates:
       *  Constant: '<S203>/Constant1'
       *  Constant: '<S203>/Constant2'
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

      /* End of Saturate: '<S199>/Saturation5' */
      for (i_o = 0; i_o < 4; i_o++) {
        /* Bias: '<S199>/Bias' incorporates:
         *  Gain: '<S199>/Gain1'
         *  Product: '<S199>/Multiply1'
         */
        rtb_Saturation5_m[i_o] = 500.0F * (rtb_MatrixConcatenate_g[i_o + 8] *
          rtb_Saturation3_c + (rtb_MatrixConcatenate_g[i_o + 4] * rtb_Gain1_lm +
          rtb_MatrixConcatenate_g[i_o] * rtb_Saturation1_p_idx_2_o)) + 1500.0F;

        /* Sum: '<S200>/Sum4' */
        rtb_Saturation1_p_idx_0_o = rtb_Sum_m[i_o] + rtb_floating_yaw_n[i_o];

        /* Saturate: '<S200>/Saturation5' */
        if (rtb_Saturation1_p_idx_0_o > 1.0F) {
          rtb_Saturation1_p_idx_0_o = 1.0F;
        } else {
          if (rtb_Saturation1_p_idx_0_o < 0.0F) {
            rtb_Saturation1_p_idx_0_o = 0.0F;
          }
        }

        /* End of Saturate: '<S200>/Saturation5' */

        /* DataTypeConversion: '<S200>/Data Type Conversion' incorporates:
         *  Constant: '<S200>/Constant2'
         *  Gain: '<S200>/Gain3'
         *  Sum: '<S200>/Sum5'
         */
        u0_o = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          rtb_Saturation1_p_idx_0_o), 4.2949673E+9F) + 1000U);

        /* Saturate: '<S200>/Saturation' */
        if (u0_o > CONTROL_PARAM.MC_OUT_MAX) {
          rtb_VariantMergeForOutportactua[i_o] = CONTROL_PARAM.MC_OUT_MAX;
        } else if (u0_o < CONTROL_PARAM.MC_OUT_MIN) {
          rtb_VariantMergeForOutportactua[i_o] = CONTROL_PARAM.MC_OUT_MIN;
        } else {
          rtb_VariantMergeForOutportactua[i_o] = u0_o;
        }

        /* End of Saturate: '<S200>/Saturation' */
      }

      /* Saturate: '<S199>/Saturation4' */
      if (rtb_Multiply1[0] > 1.0F) {
        rtb_Saturation1_p_idx_2_o = 1.0F;
      } else if (rtb_Multiply1[0] < 0.0F) {
        rtb_Saturation1_p_idx_2_o = 0.0F;
      } else {
        rtb_Saturation1_p_idx_2_o = rtb_Multiply1[0];
      }

      /* End of Saturate: '<S199>/Saturation4' */

      /* DataTypeConversion: '<S205>/Data Type Conversion' incorporates:
       *  Constant: '<S205>/Constant1'
       *  Gain: '<S205>/Gain1'
       *  Sum: '<S205>/Sum1'
       */
      u0_o = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
        rtb_Saturation1_p_idx_2_o), 4.2949673E+9F) + 1000U);

      /* Saturate: '<S199>/Saturation1' */
      if (u0_o > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[4] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_o < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[4] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[4] = u0_o;
      }

      /* DataTypeConversion: '<S199>/Data Type Conversion' incorporates:
       *  Bias: '<S199>/Bias1'
       */
      rtb_Saturation1_p_idx_2_o = fmodf(floorf(rtb_Saturation5_m[0] +
        CONTROL_PARAM.SERVO1_BIAS), 65536.0F);
      u0_o = (uint16_T)(rtb_Saturation1_p_idx_2_o < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_p_idx_2_o :
                        (int32_T)(uint16_T)rtb_Saturation1_p_idx_2_o);

      /* Saturate: '<S199>/Saturation1' */
      if (u0_o > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[5] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_o < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[5] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[5] = u0_o;
      }

      /* DataTypeConversion: '<S199>/Data Type Conversion1' incorporates:
       *  Bias: '<S199>/Bias2'
       */
      rtb_Saturation1_p_idx_2_o = fmodf(floorf(rtb_Saturation5_m[1] +
        CONTROL_PARAM.SERVO2_BIAS), 65536.0F);
      u0_o = (uint16_T)(rtb_Saturation1_p_idx_2_o < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_p_idx_2_o :
                        (int32_T)(uint16_T)rtb_Saturation1_p_idx_2_o);

      /* Saturate: '<S199>/Saturation1' */
      if (u0_o > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[6] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_o < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[6] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[6] = u0_o;
      }

      /* DataTypeConversion: '<S199>/Data Type Conversion2' incorporates:
       *  Bias: '<S199>/Bias3'
       */
      rtb_Saturation1_p_idx_2_o = fmodf(floorf(rtb_Saturation5_m[2] +
        CONTROL_PARAM.SERVO3_BIAS), 65536.0F);
      u0_o = (uint16_T)(rtb_Saturation1_p_idx_2_o < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_p_idx_2_o :
                        (int32_T)(uint16_T)rtb_Saturation1_p_idx_2_o);

      /* Saturate: '<S199>/Saturation1' */
      if (u0_o > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[7] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_o < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[7] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[7] = u0_o;
      }

      /* DataTypeConversion: '<S199>/Data Type Conversion3' incorporates:
       *  Bias: '<S199>/Bias4'
       */
      rtb_Saturation1_p_idx_2_o = fmodf(floorf(rtb_Saturation5_m[3] +
        CONTROL_PARAM.SERVO4_BIAS), 65536.0F);
      u0_o = (uint16_T)(rtb_Saturation1_p_idx_2_o < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_p_idx_2_o :
                        (int32_T)(uint16_T)rtb_Saturation1_p_idx_2_o);

      /* Saturate: '<S199>/Saturation1' */
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

    /* End of MultiPortSwitch: '<S202>/Multiport Switch' */
  }

#endif

  /* End of Outputs for SubSystem: '<S8>/VTOL_Control_Allocation' */

  /* Outport: '<Root>/Control_Out' incorporates:
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   *  Reshape: '<S179>/Reshape'
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
    3.14159274F * 0.002F;

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
  /* Start for Constant: '<S176>/Constant' */
  Controller_B.Constant = CONTROL_PARAM.MC_VEL_Z_I_MIN;

  /* End of Start for SubSystem: '<S2>/MC_Controller' */

  /* InitializeConditions for DiscreteIntegrator: '<S10>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S9>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_o = 1U;

  /* SystemInitialize for Enabled SubSystem: '<S2>/FW_Controller' */
  /* InitializeConditions for DiscreteIntegrator: '<S101>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_i = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S70>/Integrator1' */
  Controller_DW.Integrator1_DSTATE_c = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S73>/Integrator1' */
  Controller_DW.Integrator1_DSTATE_j = 0.0F;

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

  /* InitializeConditions for DiscreteIntegrator: '<S97>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_n = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_d = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S95>/ ' */
  Controller_DW._DSTATE = Controller_ConstB.Zero;
  if (Controller_DW._DSTATE >= 1.0F) {
    Controller_DW._DSTATE = 1.0F;
  } else {
    if (Controller_DW._DSTATE <= 0.0F) {
      Controller_DW._DSTATE = 0.0F;
    }
  }

  Controller_DW._PrevResetState = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S95>/ ' */

  /* InitializeConditions for DiscreteIntegrator: '<S96>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_h = 1U;
  Controller_DW.DiscreteTimeIntegrator1_Prev_dx = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S92>/ ' */
  Controller_DW._DSTATE_h = Controller_ConstB.Zero1;
  if (Controller_DW._DSTATE_h >= CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
    Controller_DW._DSTATE_h = CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
  } else {
    if (Controller_DW._DSTATE_h <= -CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
      Controller_DW._DSTATE_h = -CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
    }
  }

  Controller_DW._PrevResetState_b = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S92>/ ' */

  /* InitializeConditions for DiscreteIntegrator: '<S93>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_f = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_b = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S73>/Integrator' */
  Controller_DW.Integrator_DSTATE_d = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S70>/Integrator' */
  Controller_DW.Integrator_DSTATE_n = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S2>/FW_Controller' */

  /* SystemInitialize for Enabled SubSystem: '<S2>/MC_Controller' */
  /* InitializeConditions for DiscreteIntegrator: '<S134>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S134>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S159>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_PrevRe_p = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S161>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S131>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_c = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S136>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_k = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S154>/Integrator1' */
  Controller_DW.Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S159>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S154>/Integrator' */
  Controller_DW.Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S154>/Integrator1' */
  Controller_DW.Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S159>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S154>/Integrator' */
  Controller_DW.Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S173>/Integrator1' */
  Controller_DW.Integrator1_DSTATE_e = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S176>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S176>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S178>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 1U;
  Controller_DW.DiscreteTimeIntegrator1_Prev_ks = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S173>/Integrator' */
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
