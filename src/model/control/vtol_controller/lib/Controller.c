/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.864
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Sep 14 14:57:33 2026
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
struct_AGLUWHQ2VVXz72aZazl5HE CONTROL_PARAM = {
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
  0.523599F,
  0.24F,
  0.24F,
  0.6F,
  0.15F,
  0.15F,
  0.2F,
  0.006F,
  0.009F,
  0.02F,
  0.0F,
  0.0F,
  -0.2F,
  0.2F,
  -0.2F,
  0.2F,
  1.57079601F,
  1.04719806F,
  0.55F,
  1950U,
  1050U,
  7.0F,
  7.0F,
  0.785398F,
  0.1F,
  0.2F,
  0.2F,
  0.1F,
  0.1F,
  0.2F,
  -0.3F,
  0.3F,
  1.04719806F,
  0.523599F,
  17.0F,
  0.2F,
  1.0F,
  1.0F,
  1.0F,
  0.0F,
  0.1F,
  0.1F,
  0.15F,
  0.5F,
  0.1F,
  0.25F,
  0.2F,
  0.0F,
  0.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  2.0F,
  0.2F,
  0.0F,
  0.0F,
  2000U,
  1000U,
  -1.0F,
  -1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  40.0F,
  10.0F,
  0.0F,
  30.0F
} ;                                    /* Variable: CONTROL_PARAM
                                        * Referenced by:
                                        *   '<S14>/Saturation'
                                        *   '<S15>/Gain'
                                        *   '<S15>/Gain1'
                                        *   '<S15>/Gain2'
                                        *   '<S15>/Gain3'
                                        *   '<S15>/Gain4'
                                        *   '<S15>/Gain5'
                                        *   '<S15>/Gain6'
                                        *   '<S15>/Gain7'
                                        *   '<S15>/pitch_ff'
                                        *   '<S15>/thorttle_ff'
                                        *   '<S134>/hover_throttle'
                                        *   '<S17>/FF'
                                        *   '<S40>/P_control'
                                        *   '<S41>/Gain'
                                        *   '<S41>/Gain1'
                                        *   '<S41>/P_control'
                                        *   '<S42>/Kv'
                                        *   '<S113>/Saturation'
                                        *   '<S151>/Bias1'
                                        *   '<S151>/Bias2'
                                        *   '<S151>/Bias3'
                                        *   '<S151>/Bias4'
                                        *   '<S151>/Saturation1'
                                        *   '<S152>/Constant'
                                        *   '<S152>/Constant1'
                                        *   '<S152>/Saturation'
                                        *   '<S161>/Bias1'
                                        *   '<S161>/Bias2'
                                        *   '<S161>/Bias3'
                                        *   '<S161>/Bias4'
                                        *   '<S161>/Saturation1'
                                        *   '<S162>/Constant'
                                        *   '<S162>/Constant1'
                                        *   '<S162>/Saturation'
                                        *   '<S21>/trim_speed'
                                        *   '<S22>/trim_speed'
                                        *   '<S28>/Saturation'
                                        *   '<S57>/Gain'
                                        *   '<S58>/ '
                                        *   '<S58>/Gain3'
                                        *   '<S81>/Saturation'
                                        *   '<S81>/Saturation1'
                                        *   '<S81>/Saturation2'
                                        *   '<S124>/kd'
                                        *   '<S124>/Saturation'
                                        *   '<S125>/ki'
                                        *   '<S125>/Discrete-Time Integrator'
                                        *   '<S126>/kp'
                                        *   '<S143>/kd'
                                        *   '<S143>/Saturation'
                                        *   '<S144>/Constant'
                                        *   '<S144>/ki'
                                        *   '<S144>/Discrete-Time Integrator'
                                        *   '<S145>/kp'
                                        *   '<S154>/Constant1'
                                        *   '<S154>/Constant12'
                                        *   '<S154>/Constant2'
                                        *   '<S154>/Constant7'
                                        *   '<S159>/Bias'
                                        *   '<S159>/Bias1'
                                        *   '<S159>/Bias2'
                                        *   '<S159>/Bias3'
                                        *   '<S160>/Bias'
                                        *   '<S160>/Bias1'
                                        *   '<S160>/Bias2'
                                        *   '<S160>/Bias3'
                                        *   '<S164>/Constant1'
                                        *   '<S164>/Constant11'
                                        *   '<S164>/Constant12'
                                        *   '<S164>/Constant2'
                                        *   '<S164>/Constant7'
                                        *   '<S164>/Constant8'
                                        *   '<S170>/Bias'
                                        *   '<S170>/Bias1'
                                        *   '<S170>/Bias2'
                                        *   '<S170>/Bias3'
                                        *   '<S171>/Bias'
                                        *   '<S171>/Bias1'
                                        *   '<S171>/Bias2'
                                        *   '<S171>/Bias3'
                                        *   '<S23>/gain1'
                                        *   '<S23>/gain2'
                                        *   '<S23>/gain3'
                                        *   '<S23>/Discrete-Time Integrator'
                                        *   '<S24>/gain1'
                                        *   '<S24>/gain2'
                                        *   '<S24>/gain3'
                                        *   '<S30>/Pitch Offset'
                                        *   '<S30>/Saturation'
                                        *   '<S31>/Constant1'
                                        *   '<S31>/Constant2'
                                        *   '<S94>/Gain'
                                        *   '<S94>/Gain1'
                                        *   '<S106>/Constant1'
                                        *   '<S106>/Constant2'
                                        *   '<S99>/gain1'
                                        *   '<S99>/gain2'
                                        *   '<S99>/gain3'
                                        *   '<S99>/Saturation'
                                        *   '<S100>/gain1'
                                        *   '<S100>/gain2'
                                        *   '<S100>/gain3'
                                        *   '<S100>/Discrete-Time Integrator'
                                        *   '<S101>/gain1'
                                        *   '<S101>/gain2'
                                        *   '<S101>/gain3'
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
 *    '<S152>/R_Remix'
 *    '<S162>/R_Remix'
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
  real32_T rtb_a;
  real32_T rtb_Saturation1;
  real32_T rtb_Saturation_g;
  real32_T rtb_Saturation_bx;
  boolean_T rtb_Compare_hi;
  real32_T rtb_Saturation2;
  real32_T rtb_VdotPg_sp;
  real32_T rtb_Gain_n4;
  real32_T rtb_fw_rate_err_B[3];
  boolean_T rtb_Compare_gi;
  real32_T rtb_Sign5_f;
  real32_T rtb_VectorConcatenate_i[9];
  real32_T rtb_MatrixConcatenate1[9];
  real32_T rtb_Multiply_ni[3];
  real32_T rtb_Sum;
  real32_T rtb_Add_k;
  real32_T rtb_Add1_j4;
  real32_T rtb_Add2_h;
  int32_T i;
  real32_T rtb_MatrixConcatenate1_0[3];
  real32_T rtb_MultiportSwitch_idx_0;
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
   *  Constant: '<S4>/Constant5'
   *  Constant: '<S4>/Constant6'
   *  Constant: '<S4>/Constant7'
   *  Constant: '<S4>/Constant8'
   *  Constant: '<S4>/Constant9'
   *  Inport: '<Root>/FMS_Out'
   */
  switch (Controller_U.FMS_Out.ext_state) {
   case 0:
    rtb_MultiportSwitch_idx_0 = 0.0F;
    rtb_MultiportSwitch_idx_1 = 1;
    break;

   case 1:
    rtb_MultiportSwitch_idx_0 = 0.5F;
    rtb_MultiportSwitch_idx_1 = 1;
    break;

   case 2:
    rtb_MultiportSwitch_idx_0 = 1.0F;
    rtb_MultiportSwitch_idx_1 = 0;
    break;

   case 3:
    rtb_MultiportSwitch_idx_0 = 1.0F;
    rtb_MultiportSwitch_idx_1 = 1;
    break;

   default:
    rtb_MultiportSwitch_idx_0 = 0.5F;
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
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_k = rtb_MultiportSwitch_idx_0;
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
      /* InitializeConditions for DiscreteIntegrator: '<S66>/Discrete-Time Integrator5' */
      Controller_DW.DiscreteTimeIntegrator5_IC_LO_i = 1U;

      /* InitializeConditions for DiscreteIntegrator: '<S26>/Discrete-Time Integrator5' */
      Controller_DW.DiscreteTimeIntegrator5_IC_LO_h = 1U;

      /* InitializeConditions for DiscreteIntegrator: '<S36>/Integrator1' */
      Controller_DW.Integrator1_DSTATE_c = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S38>/Integrator1' */
      Controller_DW.Integrator1_DSTATE_j = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S25>/Discrete-Time Integrator5' */
      Controller_DW.DiscreteTimeIntegrator5_IC_L_hl = 1U;

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

      /* InitializeConditions for DiscreteIntegrator: '<S41>/ ' */
      Controller_DW._DSTATE = 0.05F;

      /* InitializeConditions for DiscreteIntegrator: '<S62>/Discrete-Time Integrator1' */
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_n = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevR_d = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S61>/Discrete-Time Integrator1' */
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_h = 1U;
      Controller_DW.DiscreteTimeIntegrator1_Prev_dx = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S58>/ ' */
      Controller_DW._DSTATE_h = Controller_ConstB.Zero1;
      if (Controller_DW._DSTATE_h >= CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
        Controller_DW._DSTATE_h = CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
      } else {
        if (Controller_DW._DSTATE_h <= -CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
          Controller_DW._DSTATE_h = -CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
        }
      }

      Controller_DW._PrevResetState = 0;

      /* End of InitializeConditions for DiscreteIntegrator: '<S58>/ ' */

      /* InitializeConditions for DiscreteIntegrator: '<S59>/Discrete-Time Integrator1' */
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_f = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevR_b = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S38>/Integrator' */
      Controller_DW.Integrator_DSTATE_d = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S36>/Integrator' */
      Controller_DW.Integrator_DSTATE_n = 0.0F;
      Controller_DW.FW_Controller_MODE = true;
    }

    /* SignalConversion: '<S45>/TmpSignal ConversionAtMultiplyInport2' incorporates:
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
      rtb_a = Controller_U.INS_Out.airspeed;
    } else {
      /* Sqrt: '<S73>/Sqrt' incorporates:
       *  Math: '<S73>/Square'
       *  Sum: '<S73>/Sum of Elements'
       */
      rtb_Saturation1 = sqrtf(((Controller_U.INS_Out.quat[0] *
        Controller_U.INS_Out.quat[0] + Controller_U.INS_Out.quat[1] *
        Controller_U.INS_Out.quat[1]) + Controller_U.INS_Out.quat[2] *
        Controller_U.INS_Out.quat[2]) + Controller_U.INS_Out.quat[3] *
        Controller_U.INS_Out.quat[3]);

      /* Product: '<S69>/Divide' incorporates:
       *  Sqrt: '<S73>/Sqrt'
       */
      rtb_Divide_m_idx_0 = Controller_U.INS_Out.quat[0] / rtb_Saturation1;
      rtb_Divide_m_idx_1 = Controller_U.INS_Out.quat[1] / rtb_Saturation1;
      rtb_Divide_m_idx_2 = Controller_U.INS_Out.quat[2] / rtb_Saturation1;
      rtb_Divide_m_idx_3 = Controller_U.INS_Out.quat[3] / rtb_Saturation1;

      /* Math: '<S72>/Square' incorporates:
       *  Math: '<S70>/Square'
       *  Math: '<S71>/Square'
       */
      rtb_Saturation2 = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_0;

      /* Math: '<S72>/Square2' incorporates:
       *  Math: '<S70>/Square2'
       *  Math: '<S71>/Square2'
       */
      rtb_Gain_n4 = rtb_Divide_m_idx_2 * rtb_Divide_m_idx_2;

      /* Math: '<S72>/Square1' incorporates:
       *  Math: '<S70>/Square1'
       *  Math: '<S71>/Square1'
       */
      rtb_Saturation1 = rtb_Divide_m_idx_1 * rtb_Divide_m_idx_1;

      /* Math: '<S72>/Square3' incorporates:
       *  Math: '<S70>/Square3'
       *  Math: '<S71>/Square3'
       */
      rtb_Saturation_g = rtb_Divide_m_idx_3 * rtb_Divide_m_idx_3;

      /* Sum: '<S72>/Subtract' incorporates:
       *  Math: '<S72>/Square'
       *  Math: '<S72>/Square1'
       *  Math: '<S72>/Square2'
       *  Math: '<S72>/Square3'
       *  Sum: '<S72>/Add'
       *  Sum: '<S72>/Add1'
       */
      rtb_MatrixConcatenate1[8] = (rtb_Saturation2 + rtb_Saturation_g) -
        (rtb_Saturation1 + rtb_Gain_n4);

      /* Product: '<S72>/Multiply2' incorporates:
       *  Product: '<S71>/Multiply2'
       */
      rtb_Saturation_bx = rtb_Divide_m_idx_2 * rtb_Divide_m_idx_3;

      /* Product: '<S72>/Multiply3' incorporates:
       *  Product: '<S71>/Multiply3'
       */
      rtb_Add1_j4 = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_1;

      /* Gain: '<S72>/Gain1' incorporates:
       *  Product: '<S72>/Multiply2'
       *  Product: '<S72>/Multiply3'
       *  Sum: '<S72>/Add2'
       */
      rtb_MatrixConcatenate1[7] = (rtb_Saturation_bx + rtb_Add1_j4) * 2.0F;

      /* Product: '<S72>/Multiply' incorporates:
       *  Product: '<S70>/Multiply2'
       */
      rtb_Add_k = rtb_Divide_m_idx_1 * rtb_Divide_m_idx_3;

      /* Product: '<S72>/Multiply1' incorporates:
       *  Product: '<S70>/Multiply3'
       */
      rtb_Add2_h = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_2;

      /* Gain: '<S72>/Gain' incorporates:
       *  Product: '<S72>/Multiply'
       *  Product: '<S72>/Multiply1'
       *  Sum: '<S72>/Subtract2'
       */
      rtb_MatrixConcatenate1[6] = (rtb_Add_k - rtb_Add2_h) * 2.0F;

      /* Gain: '<S71>/Gain1' incorporates:
       *  Sum: '<S71>/Subtract1'
       */
      rtb_MatrixConcatenate1[5] = (rtb_Saturation_bx - rtb_Add1_j4) * 2.0F;

      /* Sum: '<S71>/Subtract' incorporates:
       *  Sum: '<S71>/Add'
       *  Sum: '<S71>/Add1'
       */
      rtb_MatrixConcatenate1[4] = (rtb_Saturation2 + rtb_Gain_n4) -
        (rtb_Saturation1 + rtb_Saturation_g);

      /* Product: '<S71>/Multiply' incorporates:
       *  Product: '<S70>/Multiply'
       */
      rtb_Saturation_bx = rtb_Divide_m_idx_1 * rtb_Divide_m_idx_2;

      /* Product: '<S71>/Multiply1' incorporates:
       *  Product: '<S70>/Multiply1'
       */
      rtb_Add1_j4 = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_3;

      /* Gain: '<S71>/Gain' incorporates:
       *  Product: '<S71>/Multiply'
       *  Product: '<S71>/Multiply1'
       *  Sum: '<S71>/Add3'
       */
      rtb_MatrixConcatenate1[3] = (rtb_Saturation_bx + rtb_Add1_j4) * 2.0F;

      /* Gain: '<S70>/Gain1' incorporates:
       *  Sum: '<S70>/Add2'
       */
      rtb_MatrixConcatenate1[2] = (rtb_Add_k + rtb_Add2_h) * 2.0F;

      /* Gain: '<S70>/Gain' incorporates:
       *  Sum: '<S70>/Subtract1'
       */
      rtb_MatrixConcatenate1[1] = (rtb_Saturation_bx - rtb_Add1_j4) * 2.0F;

      /* Sum: '<S70>/Subtract' incorporates:
       *  Sum: '<S70>/Add'
       *  Sum: '<S70>/Add1'
       */
      rtb_MatrixConcatenate1[0] = (rtb_Saturation2 + rtb_Saturation1) -
        (rtb_Gain_n4 + rtb_Saturation_g);

      /* Product: '<S67>/Multiply' */
      for (i = 0; i < 3; i++) {
        rtb_MatrixConcatenate1_0[i] = rtb_MatrixConcatenate1[i + 6] *
          rtb_TmpSignalConversionAtMultip[2] + (rtb_MatrixConcatenate1[i + 3] *
          rtb_TmpSignalConversionAtMultip[1] + rtb_MatrixConcatenate1[i] *
          rtb_TmpSignalConversionAtMultip[0]);
      }

      /* End of Product: '<S67>/Multiply' */
      rtb_a = rtb_MatrixConcatenate1_0[0];
    }

    /* End of Switch: '<S12>/Switch' */

    /* Saturate: '<S12>/Saturation1' */
    if (rtb_a > 100.0F) {
      rtb_Saturation1 = 100.0F;
    } else if (rtb_a < 0.1F) {
      rtb_Saturation1 = 0.1F;
    } else {
      rtb_Saturation1 = rtb_a;
    }

    /* End of Saturate: '<S12>/Saturation1' */

    /* DiscreteIntegrator: '<S66>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_i != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j = rtb_Saturation1;
    }

    /* Product: '<S22>/Divide' incorporates:
     *  Constant: '<S22>/trim_speed'
     *  DiscreteIntegrator: '<S66>/Discrete-Time Integrator5'
     */
    rtb_Saturation_g = CONTROL_PARAM.FW_AIRSPEED_TRIM /
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;

    /* Saturate: '<S22>/Saturation' */
    if (rtb_Saturation_g > 1.0F) {
      rtb_Saturation_g = 1.0F;
    } else {
      if (rtb_Saturation_g < 0.0F) {
        rtb_Saturation_g = 0.0F;
      }
    }

    /* End of Saturate: '<S22>/Saturation' */

    /* DiscreteIntegrator: '<S26>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_h != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_n = rtb_Saturation_g;
    }

    /* Switch: '<S29>/Switch' incorporates:
     *  Inport: '<Root>/FMS_Out'
     *  Logic: '<S29>/Logical Operator'
     *  RelationalOperator: '<S34>/Compare'
     */
    if ((Controller_U.FMS_Out.ctrl_mode == 3) || (Controller_U.FMS_Out.ctrl_mode
         == 4)) {
      rtb_a = Controller_U.FMS_Out.phi_cmd;
    } else {
      /* Trigonometry: '<S14>/Atan' incorporates:
       *  DiscreteIntegrator: '<S36>/Integrator1'
       *  Gain: '<S14>/g_force'
       */
      rtb_a = atanf(0.101936802F * Controller_DW.Integrator1_DSTATE_c);

      /* Saturate: '<S14>/Saturation' */
      if (rtb_a > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_a = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_a < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
          rtb_a = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
        }
      }

      /* End of Saturate: '<S14>/Saturation' */
    }

    /* End of Switch: '<S29>/Switch' */

    /* Switch: '<S29>/Switch1' incorporates:
     *  Constant: '<S35>/Constant'
     *  DiscreteIntegrator: '<S38>/Integrator1'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S35>/Compare'
     */
    if (Controller_U.FMS_Out.ctrl_mode == 3) {
      rtb_Divide_m_idx_1 = Controller_U.FMS_Out.theta_cmd;
    } else {
      rtb_Divide_m_idx_1 = Controller_DW.Integrator1_DSTATE_j;
    }

    /* End of Switch: '<S29>/Switch1' */

    /* Saturate: '<S30>/Saturation' */
    if (rtb_a > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Saturation_bx = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else if (rtb_a < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Saturation_bx = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      rtb_Saturation_bx = rtb_a;
    }

    /* Reshape: '<S18>/Reshape' incorporates:
     *  Constant: '<S31>/Constant1'
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S31>/Multiply'
     *  Sum: '<S30>/Sum'
     */
    Controller_B.Reshape[0] = (rtb_Saturation_bx - Controller_U.INS_Out.phi) *
      CONTROL_PARAM.FW_ROLL_P;

    /* Bias: '<S30>/Pitch Offset' */
    rtb_Add_k = rtb_Divide_m_idx_1 + CONTROL_PARAM.FW_PITCH_OFFSET;

    /* Saturate: '<S30>/Saturation' */
    if (rtb_Add_k > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Add_k = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_Add_k < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_Add_k = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      }
    }

    /* Reshape: '<S18>/Reshape' incorporates:
     *  Constant: '<S31>/Constant2'
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S31>/Multiply'
     *  Sum: '<S30>/Sum'
     */
    Controller_B.Reshape[1] = (rtb_Add_k - Controller_U.INS_Out.theta) *
      CONTROL_PARAM.FW_PITCH_P;

    /* Product: '<S33>/Divide' incorporates:
     *  Constant: '<S33>/Constant'
     *  DiscreteIntegrator: '<S66>/Discrete-Time Integrator5'
     */
    rtb_Add_k = 9.81F / Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;

    /* Saturate: '<S33>/Saturation' */
    if (rtb_Add_k > 1.0F) {
      rtb_Add_k = 1.0F;
    } else {
      if (rtb_Add_k < 0.2F) {
        rtb_Add_k = 0.2F;
      }
    }

    /* End of Saturate: '<S33>/Saturation' */

    /* Sum: '<S28>/Sum' incorporates:
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S33>/Multiply'
     *  Product: '<S33>/Multiply1'
     *  Trigonometry: '<S33>/Cos'
     *  Trigonometry: '<S33>/Tan'
     */
    rtb_Add_k = tanf(rtb_a) * arm_cos_f32(rtb_Divide_m_idx_1) * rtb_Add_k +
      Controller_U.FMS_Out.psi_rate_cmd;

    /* Saturate: '<S28>/Saturation' */
    if (rtb_Add_k > CONTROL_PARAM.FW_R_CMD_LIM) {
      /* Reshape: '<S18>/Reshape' */
      Controller_B.Reshape[2] = CONTROL_PARAM.FW_R_CMD_LIM;
    } else if (rtb_Add_k < -CONTROL_PARAM.FW_R_CMD_LIM) {
      /* Reshape: '<S18>/Reshape' */
      Controller_B.Reshape[2] = -CONTROL_PARAM.FW_R_CMD_LIM;
    } else {
      /* Reshape: '<S18>/Reshape' */
      Controller_B.Reshape[2] = rtb_Add_k;
    }

    /* End of Saturate: '<S28>/Saturation' */

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
    rtb_Saturation_bx = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S19>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Add2_h = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Trigonometry: '<S19>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_m_idx_0 = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Sum: '<S19>/Add1' incorporates:
     *  Product: '<S19>/Multiply1'
     *  Product: '<S19>/Multiply3'
     *  Trigonometry: '<S19>/Cos'
     *  Trigonometry: '<S19>/Cos1'
     *  Trigonometry: '<S19>/Sin'
     */
    rtb_Add1_j4 = rtb_Saturation_bx * rtb_Add2_h * Controller_B.Reshape[2] +
      rtb_Divide_m_idx_0 * Controller_B.Reshape[1];

    /* Sum: '<S19>/Add2' incorporates:
     *  Product: '<S19>/Multiply4'
     *  Product: '<S19>/Multiply5'
     *  Trigonometry: '<S19>/Cos'
     *  Trigonometry: '<S19>/Cos1'
     *  Trigonometry: '<S19>/Sin'
     */
    rtb_Add2_h = rtb_Divide_m_idx_0 * rtb_Add2_h * Controller_B.Reshape[2] -
      rtb_Saturation_bx * Controller_B.Reshape[1];

    /* Product: '<S21>/Divide' incorporates:
     *  Constant: '<S21>/trim_speed'
     *  DiscreteIntegrator: '<S66>/Discrete-Time Integrator5'
     *  Math: '<S21>/Square'
     *  Math: '<S21>/Square1'
     */
    rtb_Saturation_bx = CONTROL_PARAM.FW_AIRSPEED_TRIM *
      CONTROL_PARAM.FW_AIRSPEED_TRIM /
      (Controller_DW.DiscreteTimeIntegrator5_DSTAT_j *
       Controller_DW.DiscreteTimeIntegrator5_DSTAT_j);

    /* Saturate: '<S21>/Saturation' */
    if (rtb_Saturation_bx > 1.0F) {
      rtb_Saturation_bx = 1.0F;
    } else {
      if (rtb_Saturation_bx < 0.0F) {
        rtb_Saturation_bx = 0.0F;
      }
    }

    /* End of Saturate: '<S21>/Saturation' */

    /* DiscreteIntegrator: '<S25>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_L_hl != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_o = rtb_Saturation_bx;
    }

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

    /* RelationalOperator: '<S60>/Compare' incorporates:
     *  Constant: '<S60>/Constant'
     *  Inport: '<Root>/FMS_Out'
     */
    rtb_Compare_hi = (Controller_U.FMS_Out.ext_state == 1);

    /* S-Function (sfix_bitop): '<S45>/Bitwise AND' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  S-Function (sfix_bitop): '<S46>/Bitwise AND'
     */
    tmp = Controller_U.INS_Out.flag & 16U;

    /* Switch: '<S45>/Switch' incorporates:
     *  Constant: '<S46>/Constant'
     *  Inport: '<Root>/INS_Out'
     *  S-Function (sfix_bitop): '<S45>/Bitwise AND'
     *  Switch: '<S46>/Switch'
     */
    if (tmp > 0U) {
      /* Sqrt: '<S53>/Sqrt' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Math: '<S53>/Square'
       *  Sum: '<S53>/Sum of Elements'
       */
      rtb_Saturation2 = sqrtf(((Controller_U.INS_Out.quat[0] *
        Controller_U.INS_Out.quat[0] + Controller_U.INS_Out.quat[1] *
        Controller_U.INS_Out.quat[1]) + Controller_U.INS_Out.quat[2] *
        Controller_U.INS_Out.quat[2]) + Controller_U.INS_Out.quat[3] *
        Controller_U.INS_Out.quat[3]);

      /* Product: '<S49>/Divide' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Sqrt: '<S53>/Sqrt'
       */
      rtb_Divide_m_idx_0 = Controller_U.INS_Out.quat[0] / rtb_Saturation2;
      rtb_Divide_m_idx_1 = Controller_U.INS_Out.quat[1] / rtb_Saturation2;
      rtb_Divide_m_idx_2 = Controller_U.INS_Out.quat[2] / rtb_Saturation2;
      rtb_Divide_m_idx_3 = Controller_U.INS_Out.quat[3] / rtb_Saturation2;

      /* Sum: '<S52>/Subtract' incorporates:
       *  Math: '<S52>/Square'
       *  Math: '<S52>/Square1'
       *  Math: '<S52>/Square2'
       *  Math: '<S52>/Square3'
       *  Sum: '<S52>/Add'
       *  Sum: '<S52>/Add1'
       */
      rtb_MatrixConcatenate1[8] = (rtb_Divide_m_idx_0 * rtb_Divide_m_idx_0 +
        rtb_Divide_m_idx_3 * rtb_Divide_m_idx_3) - (rtb_Divide_m_idx_1 *
        rtb_Divide_m_idx_1 + rtb_Divide_m_idx_2 * rtb_Divide_m_idx_2);

      /* Gain: '<S52>/Gain1' incorporates:
       *  Product: '<S52>/Multiply2'
       *  Product: '<S52>/Multiply3'
       *  Sum: '<S52>/Add2'
       */
      rtb_MatrixConcatenate1[7] = (rtb_Divide_m_idx_2 * rtb_Divide_m_idx_3 +
        rtb_Divide_m_idx_0 * rtb_Divide_m_idx_1) * 2.0F;

      /* Gain: '<S52>/Gain' incorporates:
       *  Product: '<S52>/Multiply'
       *  Product: '<S52>/Multiply1'
       *  Sum: '<S52>/Subtract2'
       */
      rtb_MatrixConcatenate1[6] = (rtb_Divide_m_idx_1 * rtb_Divide_m_idx_3 -
        rtb_Divide_m_idx_0 * rtb_Divide_m_idx_2) * 2.0F;

      /* Gain: '<S51>/Gain1' incorporates:
       *  Product: '<S51>/Multiply2'
       *  Product: '<S51>/Multiply3'
       *  Sum: '<S51>/Subtract1'
       */
      rtb_MatrixConcatenate1[5] = (rtb_Divide_m_idx_2 * rtb_Divide_m_idx_3 -
        rtb_Divide_m_idx_0 * rtb_Divide_m_idx_1) * 2.0F;

      /* Sum: '<S51>/Subtract' incorporates:
       *  Math: '<S51>/Square'
       *  Math: '<S51>/Square1'
       *  Math: '<S51>/Square2'
       *  Math: '<S51>/Square3'
       *  Sum: '<S51>/Add'
       *  Sum: '<S51>/Add1'
       */
      rtb_MatrixConcatenate1[4] = (rtb_Divide_m_idx_0 * rtb_Divide_m_idx_0 +
        rtb_Divide_m_idx_2 * rtb_Divide_m_idx_2) - (rtb_Divide_m_idx_1 *
        rtb_Divide_m_idx_1 + rtb_Divide_m_idx_3 * rtb_Divide_m_idx_3);

      /* Gain: '<S51>/Gain' incorporates:
       *  Product: '<S51>/Multiply'
       *  Product: '<S51>/Multiply1'
       *  Sum: '<S51>/Add3'
       */
      rtb_MatrixConcatenate1[3] = (rtb_Divide_m_idx_1 * rtb_Divide_m_idx_2 +
        rtb_Divide_m_idx_0 * rtb_Divide_m_idx_3) * 2.0F;

      /* Gain: '<S50>/Gain1' incorporates:
       *  Product: '<S50>/Multiply2'
       *  Product: '<S50>/Multiply3'
       *  Sum: '<S50>/Add2'
       */
      rtb_MatrixConcatenate1[2] = (rtb_Divide_m_idx_1 * rtb_Divide_m_idx_3 +
        rtb_Divide_m_idx_0 * rtb_Divide_m_idx_2) * 2.0F;

      /* Gain: '<S50>/Gain' incorporates:
       *  Product: '<S50>/Multiply'
       *  Product: '<S50>/Multiply1'
       *  Sum: '<S50>/Subtract1'
       */
      rtb_MatrixConcatenate1[1] = (rtb_Divide_m_idx_1 * rtb_Divide_m_idx_2 -
        rtb_Divide_m_idx_0 * rtb_Divide_m_idx_3) * 2.0F;

      /* Sum: '<S50>/Subtract' incorporates:
       *  Math: '<S50>/Square'
       *  Math: '<S50>/Square1'
       *  Math: '<S50>/Square2'
       *  Math: '<S50>/Square3'
       *  Sum: '<S50>/Add'
       *  Sum: '<S50>/Add1'
       */
      rtb_MatrixConcatenate1[0] = (rtb_Divide_m_idx_0 * rtb_Divide_m_idx_0 +
        rtb_Divide_m_idx_1 * rtb_Divide_m_idx_1) - (rtb_Divide_m_idx_2 *
        rtb_Divide_m_idx_2 + rtb_Divide_m_idx_3 * rtb_Divide_m_idx_3);

      /* Product: '<S45>/Multiply' */
      for (i = 0; i < 3; i++) {
        rtb_MatrixConcatenate1_0[i] = rtb_MatrixConcatenate1[i + 6] *
          rtb_TmpSignalConversionAtMultip[2] + (rtb_MatrixConcatenate1[i + 3] *
          rtb_TmpSignalConversionAtMultip[1] + rtb_MatrixConcatenate1[i] *
          rtb_TmpSignalConversionAtMultip[0]);
      }

      /* End of Product: '<S45>/Multiply' */
      rtb_Divide_m_idx_1 = rtb_MatrixConcatenate1_0[0];

      /* SignalConversion: '<S55>/ConcatBufferAtVector ConcatenateIn3' */
      rtb_MatrixConcatenate1[6] = Controller_ConstB.VectorConcatenate3_g[0];
      rtb_MatrixConcatenate1[7] = Controller_ConstB.VectorConcatenate3_g[1];
      rtb_MatrixConcatenate1[8] = Controller_ConstB.VectorConcatenate3_g[2];

      /* SignalConversion: '<S55>/ConcatBufferAtVector Concatenate2In3' incorporates:
       *  Constant: '<S55>/Constant4'
       */
      rtb_MatrixConcatenate1[5] = 0.0F;

      /* Trigonometry: '<S55>/Trigonometric Function3' incorporates:
       *  Gain: '<S54>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S55>/Trigonometric Function1'
       */
      rtb_Saturation2 = arm_cos_f32(-Controller_U.INS_Out.psi);
      rtb_MatrixConcatenate1[4] = rtb_Saturation2;

      /* Trigonometry: '<S55>/Trigonometric Function2' incorporates:
       *  Gain: '<S54>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S55>/Trigonometric Function'
       */
      rtb_Gain_n4 = arm_sin_f32(-Controller_U.INS_Out.psi);

      /* Gain: '<S55>/Gain' incorporates:
       *  Trigonometry: '<S55>/Trigonometric Function2'
       */
      rtb_MatrixConcatenate1[3] = -rtb_Gain_n4;

      /* SignalConversion: '<S55>/ConcatBufferAtVector Concatenate1In3' incorporates:
       *  Constant: '<S55>/Constant3'
       */
      rtb_MatrixConcatenate1[2] = 0.0F;

      /* Trigonometry: '<S55>/Trigonometric Function' */
      rtb_MatrixConcatenate1[1] = rtb_Gain_n4;

      /* Trigonometry: '<S55>/Trigonometric Function1' */
      rtb_MatrixConcatenate1[0] = rtb_Saturation2;

      /* Product: '<S46>/Multiply' */
      for (i = 0; i < 3; i++) {
        rtb_Multiply_ni[i] = rtb_MatrixConcatenate1[i + 6] *
          rtb_TmpSignalConversionAtMultip[2] + (rtb_MatrixConcatenate1[i + 3] *
          rtb_TmpSignalConversionAtMultip[1] + rtb_MatrixConcatenate1[i] *
          rtb_TmpSignalConversionAtMultip[0]);
      }

      /* End of Product: '<S46>/Multiply' */

      /* DeadZone: '<S46>/Dead Zone' */
      if (rtb_Multiply_ni[0] > 1.0F) {
        rtb_a = rtb_Multiply_ni[0] - 1.0F;
      } else if (rtb_Multiply_ni[0] >= -1.0F) {
        rtb_a = 0.0F;
      } else {
        rtb_a = rtb_Multiply_ni[0] - -1.0F;
      }

      /* End of DeadZone: '<S46>/Dead Zone' */

      /* Signum: '<S46>/Sign' */
      if (rtb_a < 0.0F) {
        rtb_a = -1.0F;
      } else {
        if (rtb_a > 0.0F) {
          rtb_a = 1.0F;
        }
      }

      /* End of Signum: '<S46>/Sign' */
    } else {
      rtb_Divide_m_idx_1 = Controller_U.INS_Out.airspeed;
      rtb_a = 1.0F;
    }

    /* End of Switch: '<S45>/Switch' */

    /* Saturate: '<S45>/Saturation' */
    if (rtb_Divide_m_idx_1 > 100.0F) {
      rtb_Divide_m_idx_1 = 100.0F;
    } else {
      if (rtb_Divide_m_idx_1 < 8.0F) {
        rtb_Divide_m_idx_1 = 8.0F;
      }
    }

    /* End of Saturate: '<S45>/Saturation' */

    /* Product: '<S47>/Multiply1' incorporates:
     *  Gain: '<S47>/Gain'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S47>/Divide'
     *  Trigonometry: '<S47>/Asin'
     */
    rtb_Saturation2 = atanf(-Controller_U.FMS_Out.w_cmd / rtb_Divide_m_idx_1) *
      rtb_a;

    /* Saturate: '<S47>/Saturation2' */
    if (rtb_Saturation2 > 0.785398185F) {
      rtb_Saturation2 = 0.785398185F;
    } else {
      if (rtb_Saturation2 < -0.785398185F) {
        rtb_Saturation2 = -0.785398185F;
      }
    }

    /* End of Saturate: '<S47>/Saturation2' */

    /* DeadZone: '<S44>/Dead Zone' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    if (Controller_U.INS_Out.vd > 0.1F) {
      rtb_Divide_m_idx_0 = Controller_U.INS_Out.vd - 0.1F;
    } else if (Controller_U.INS_Out.vd >= -0.1F) {
      rtb_Divide_m_idx_0 = 0.0F;
    } else {
      rtb_Divide_m_idx_0 = Controller_U.INS_Out.vd - -0.1F;
    }

    /* End of DeadZone: '<S44>/Dead Zone' */

    /* Product: '<S44>/Multiply1' incorporates:
     *  Gain: '<S44>/Gain'
     *  Product: '<S44>/Divide'
     *  Trigonometry: '<S44>/Asin'
     */
    rtb_a *= atanf(1.0F / rtb_Divide_m_idx_1 * -rtb_Divide_m_idx_0);

    /* Saturate: '<S44>/Saturation1' */
    if (rtb_a > 0.785398185F) {
      rtb_a = 0.785398185F;
    } else {
      if (rtb_a < -0.785398185F) {
        rtb_a = -0.785398185F;
      }
    }

    /* End of Saturate: '<S44>/Saturation1' */

    /* Sum: '<S39>/Sum' */
    rtb_a = rtb_Saturation2 - rtb_a;

    /* Gain: '<S42>/Gain' incorporates:
     *  DiscreteIntegrator: '<S66>/Discrete-Time Integrator5'
     *  Gain: '<S42>/Kv'
     *  Inport: '<Root>/FMS_Out'
     *  Sum: '<S42>/Minus'
     */
    rtb_VdotPg_sp = (Controller_U.FMS_Out.u_cmd -
                     Controller_DW.DiscreteTimeIntegrator5_DSTAT_j) *
      CONTROL_PARAM.FW_TECS_VEL_P * 0.101936802F;

    /* DiscreteIntegrator: '<S62>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S66>/Discrete-Time Integrator5'
     */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_n != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_h =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;
    }

    if (Controller_DW.DiscreteTimeIntegrator1_PrevR_d != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_h =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;
    }

    /* Gain: '<S62>/Gain' incorporates:
     *  DiscreteIntegrator: '<S62>/Discrete-Time Integrator1'
     *  DiscreteIntegrator: '<S66>/Discrete-Time Integrator5'
     *  Sum: '<S62>/Sum5'
     */
    rtb_Divide_m_idx_1 = (Controller_DW.DiscreteTimeIntegrator5_DSTAT_j -
                          Controller_DW.DiscreteTimeIntegrator1_DSTAT_h) *
      8.88442421F;

    /* Sum: '<S42>/Sum' incorporates:
     *  Gain: '<S42>/Gain1'
     */
    rtb_Divide_m_idx_0 = rtb_VdotPg_sp - 0.101936802F * rtb_Divide_m_idx_1;

    /* Sum: '<S15>/Add' incorporates:
     *  Gain: '<S15>/Gain'
     *  Gain: '<S15>/Gain1'
     */
    rtb_Divide_m_idx_2 = CONTROL_PARAM.FW_TECS_W2T * rtb_a +
      CONTROL_PARAM.FW_TECS_U2T * rtb_Divide_m_idx_0;

    /* Saturate: '<S15>/Saturation' */
    if (rtb_Divide_m_idx_2 > 0.5F) {
      rtb_Divide_m_idx_2 = 0.5F;
    } else {
      if (rtb_Divide_m_idx_2 < -0.5F) {
        rtb_Divide_m_idx_2 = -0.5F;
      }
    }

    /* End of Saturate: '<S15>/Saturation' */

    /* DiscreteIntegrator: '<S61>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_h != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_n = rtb_Divide_m_idx_2;
    }

    if (rtb_Compare_hi || (Controller_DW.DiscreteTimeIntegrator1_Prev_dx != 0))
    {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_n = rtb_Divide_m_idx_2;
    }

    /* Gain: '<S61>/Gain' incorporates:
     *  DiscreteIntegrator: '<S61>/Discrete-Time Integrator1'
     *  Sum: '<S61>/Sum5'
     */
    rtb_Gain_n4 = (rtb_Divide_m_idx_2 -
                   Controller_DW.DiscreteTimeIntegrator1_DSTAT_n) * 188.49556F;

    /* Switch: '<S11>/Switch' incorporates:
     *  Constant: '<S11>/Constant2'
     *  Constant: '<S16>/Constant'
     *  Constant: '<S64>/Constant'
     *  Constant: '<S65>/Constant'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S64>/Compare'
     *  RelationalOperator: '<S65>/Compare'
     *  Saturate: '<S16>/Saturation2'
     *  Switch: '<S16>/Switch'
     *  Switch: '<S41>/Switch'
     */
    if (Controller_U.FMS_Out.ctrl_mode == 1) {
      Controller_B.Switch[0] = Controller_U.FMS_Out.p_cmd;
      Controller_B.Switch[1] = Controller_U.FMS_Out.q_cmd;
      Controller_B.Switch[2] = Controller_U.FMS_Out.r_cmd;
      Controller_B.Switch[3] = Controller_U.FMS_Out.u_cmd;
      Controller_B.Switch[4] = 0.0F;
      Controller_B.Switch[5] = 0.0F;
    } else {
      if (Controller_U.FMS_Out.ctrl_mode <= 3) {
        /* Switch: '<S16>/Switch' incorporates:
         *  Bias: '<S16>/Bias'
         *  Gain: '<S16>/Gain'
         */
        rtb_Sum = 0.000999987125F * (real32_T)Controller_U.FMS_Out.throttle_cmd
          + -1.0F;
      } else {
        if (rtb_Compare_hi) {
          /* Switch: '<S41>/Switch' incorporates:
           *  Constant: '<S41>/Constant'
           *  Switch: '<S16>/Switch'
           */
          rtb_Sum = 0.0F;
        } else {
          /* Gain: '<S41>/Gain1' incorporates:
           *  Switch: '<S16>/Switch'
           *  Switch: '<S41>/Switch'
           *  Switch: '<S61>/Switch'
           */
          rtb_Divide_m_idx_3 = CONTROL_PARAM.FW_TECS_THOR_D * rtb_Gain_n4;

          /* Saturate: '<S41>/Saturation1' incorporates:
           *  Switch: '<S16>/Switch'
           *  Switch: '<S41>/Switch'
           */
          if (rtb_Divide_m_idx_3 > 0.3F) {
            rtb_Divide_m_idx_3 = 0.3F;
          } else {
            if (rtb_Divide_m_idx_3 < -0.3F) {
              rtb_Divide_m_idx_3 = -0.3F;
            }
          }

          /* End of Saturate: '<S41>/Saturation1' */

          /* Switch: '<S41>/Switch' incorporates:
           *  Gain: '<S15>/Gain2'
           *  Gain: '<S15>/Gain3'
           *  Gain: '<S15>/thorttle_ff'
           *  Gain: '<S41>/P_control'
           *  Sum: '<S15>/Add1'
           *  Sum: '<S41>/Add4'
           *  Switch: '<S16>/Switch'
           */
          rtb_Sum = (CONTROL_PARAM.FW_TECS_W2T * rtb_Saturation2 +
                     CONTROL_PARAM.FW_TECS_U2T * rtb_VdotPg_sp) *
            CONTROL_PARAM.FW_TECS_THOR_FF + (CONTROL_PARAM.FW_TECS_THOR_P *
            rtb_Divide_m_idx_2 + rtb_Divide_m_idx_3);
        }

        /* Sum: '<S41>/Sum' incorporates:
         *  DiscreteIntegrator: '<S41>/ '
         *  Switch: '<S16>/Switch'
         */
        rtb_Sum += Controller_DW._DSTATE;

        /* Saturate: '<S16>/Saturation' incorporates:
         *  Switch: '<S16>/Switch'
         */
        if (rtb_Sum > 1.0F) {
          rtb_Sum = 1.0F;
        } else {
          if (rtb_Sum < -1.0F) {
            rtb_Sum = -1.0F;
          }
        }

        /* End of Saturate: '<S16>/Saturation' */
      }

      /* Product: '<S17>/Multiply1' incorporates:
       *  DiscreteIntegrator: '<S26>/Discrete-Time Integrator5'
       *  Gain: '<S17>/FF'
       *  Switch: '<S16>/Switch'
       *  Switch: '<S41>/Switch'
       */
      rtb_Add_k = CONTROL_PARAM.FW_FF * rtb_Add_k *
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_n;

      /* Product: '<S17>/Multiply' incorporates:
       *  Constant: '<S24>/gain1'
       *  DiscreteIntegrator: '<S23>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S25>/Discrete-Time Integrator5'
       *  Product: '<S24>/Multiply'
       *  Sum: '<S20>/Add1'
       */
      rtb_Divide_m_idx_3 = (CONTROL_PARAM.FW_ROLL_RATE_P * rtb_fw_rate_err_B[0]
                            + Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0]) *
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_o;

      /* Saturate: '<S17>/FF_limit' */
      if (rtb_Add_k > 0.3F) {
        rtb_Add_k = 0.3F;
      } else {
        if (rtb_Add_k < -0.3F) {
          rtb_Add_k = -0.3F;
        }
      }

      /* Saturate: '<S17>/PI_limit' */
      if (rtb_Divide_m_idx_3 > 1.0F) {
        rtb_Divide_m_idx_3 = 1.0F;
      } else {
        if (rtb_Divide_m_idx_3 < -1.0F) {
          rtb_Divide_m_idx_3 = -1.0F;
        }
      }

      /* Sum: '<S17>/Add' */
      rtb_Add_k += rtb_Divide_m_idx_3;

      /* Saturate: '<S17>/Saturation1' */
      if (rtb_Add_k > 1.0F) {
        Controller_B.Switch[0] = 1.0F;
      } else if (rtb_Add_k < -1.0F) {
        Controller_B.Switch[0] = -1.0F;
      } else {
        Controller_B.Switch[0] = rtb_Add_k;
      }

      /* Product: '<S17>/Multiply1' incorporates:
       *  DiscreteIntegrator: '<S26>/Discrete-Time Integrator5'
       *  Gain: '<S17>/FF'
       */
      rtb_Add_k = CONTROL_PARAM.FW_FF * rtb_Add1_j4 *
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_n;

      /* Product: '<S17>/Multiply' incorporates:
       *  Constant: '<S24>/gain2'
       *  DiscreteIntegrator: '<S23>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S25>/Discrete-Time Integrator5'
       *  Product: '<S24>/Multiply'
       *  Sum: '<S20>/Add1'
       */
      rtb_Divide_m_idx_3 = (CONTROL_PARAM.FW_PITCH_RATE_P * rtb_fw_rate_err_B[1]
                            + Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1]) *
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_o;

      /* Saturate: '<S17>/FF_limit' */
      if (rtb_Add_k > 0.3F) {
        rtb_Add_k = 0.3F;
      } else {
        if (rtb_Add_k < -0.3F) {
          rtb_Add_k = -0.3F;
        }
      }

      /* Saturate: '<S17>/PI_limit' */
      if (rtb_Divide_m_idx_3 > 1.0F) {
        rtb_Divide_m_idx_3 = 1.0F;
      } else {
        if (rtb_Divide_m_idx_3 < -1.0F) {
          rtb_Divide_m_idx_3 = -1.0F;
        }
      }

      /* Sum: '<S17>/Add' */
      rtb_Add_k += rtb_Divide_m_idx_3;

      /* Saturate: '<S17>/Saturation1' */
      if (rtb_Add_k > 1.0F) {
        Controller_B.Switch[1] = 1.0F;
      } else if (rtb_Add_k < -1.0F) {
        Controller_B.Switch[1] = -1.0F;
      } else {
        Controller_B.Switch[1] = rtb_Add_k;
      }

      /* Product: '<S17>/Multiply1' incorporates:
       *  DiscreteIntegrator: '<S26>/Discrete-Time Integrator5'
       *  Gain: '<S17>/FF'
       */
      rtb_Add_k = CONTROL_PARAM.FW_FF * rtb_Add2_h *
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_n;

      /* Product: '<S17>/Multiply' incorporates:
       *  Constant: '<S24>/gain3'
       *  DiscreteIntegrator: '<S23>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S25>/Discrete-Time Integrator5'
       *  Product: '<S24>/Multiply'
       *  Sum: '<S20>/Add1'
       */
      rtb_Divide_m_idx_3 = (CONTROL_PARAM.FW_YAW_RATE_P * rtb_fw_rate_err_B[2] +
                            Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2]) *
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_o;

      /* Saturate: '<S17>/FF_limit' */
      if (rtb_Add_k > 0.3F) {
        rtb_Add_k = 0.3F;
      } else {
        if (rtb_Add_k < -0.3F) {
          rtb_Add_k = -0.3F;
        }
      }

      /* Saturate: '<S17>/PI_limit' */
      if (rtb_Divide_m_idx_3 > 1.0F) {
        rtb_Divide_m_idx_3 = 1.0F;
      } else {
        if (rtb_Divide_m_idx_3 < -1.0F) {
          rtb_Divide_m_idx_3 = -1.0F;
        }
      }

      /* Sum: '<S17>/Add' */
      rtb_Add_k += rtb_Divide_m_idx_3;

      /* Saturate: '<S17>/Saturation1' */
      if (rtb_Add_k > 1.0F) {
        Controller_B.Switch[2] = 1.0F;
      } else if (rtb_Add_k < -1.0F) {
        Controller_B.Switch[2] = -1.0F;
      } else {
        Controller_B.Switch[2] = rtb_Add_k;
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
     *  Gain: '<S15>/Gain6'
     *  Gain: '<S15>/Gain7'
     */
    rtb_Add_k = CONTROL_PARAM.FW_TECS_W2P * rtb_a - CONTROL_PARAM.FW_TECS_U2P *
      rtb_Divide_m_idx_0;

    /* RelationalOperator: '<S56>/Compare' incorporates:
     *  Constant: '<S56>/Constant'
     *  Inport: '<Root>/FMS_Out'
     */
    rtb_Compare_gi = (Controller_U.FMS_Out.ext_state == 1);

    /* DiscreteIntegrator: '<S58>/ ' */
    if (rtb_Compare_gi || (Controller_DW._PrevResetState != 0)) {
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

    /* DiscreteIntegrator: '<S59>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_f != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_e = rtb_Add_k;
    }

    if (rtb_Compare_gi || (Controller_DW.DiscreteTimeIntegrator1_PrevR_b != 0))
    {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_e = rtb_Add_k;
    }

    /* Gain: '<S59>/Gain' incorporates:
     *  DiscreteIntegrator: '<S59>/Discrete-Time Integrator1'
     *  Sum: '<S59>/Sum5'
     */
    rtb_Divide_m_idx_3 = (rtb_Add_k -
                          Controller_DW.DiscreteTimeIntegrator1_DSTAT_e) *
      62.831852F;

    /* Switch: '<S40>/Switch' incorporates:
     *  Constant: '<S40>/Constant'
     *  DiscreteIntegrator: '<S58>/ '
     *  Gain: '<S15>/Gain4'
     *  Gain: '<S15>/Gain5'
     *  Gain: '<S15>/pitch_ff'
     *  Gain: '<S40>/P_control'
     *  Sum: '<S15>/Minus'
     *  Sum: '<S40>/Add'
     */
    if (rtb_Compare_gi) {
      rtb_Divide_m_idx_0 = 0.0F;
    } else {
      /* Gain: '<S57>/Gain' incorporates:
       *  Switch: '<S59>/Switch'
       */
      rtb_Add1_j4 = CONTROL_PARAM.FW_TECS_PITCH_D * rtb_Divide_m_idx_3;

      /* Saturate: '<S40>/Saturation1' */
      if (rtb_Add1_j4 > 0.3F) {
        rtb_Add1_j4 = 0.3F;
      } else {
        if (rtb_Add1_j4 < -0.3F) {
          rtb_Add1_j4 = -0.3F;
        }
      }

      /* End of Saturate: '<S40>/Saturation1' */
      rtb_Divide_m_idx_0 = ((CONTROL_PARAM.FW_TECS_PITCH_P * rtb_Add_k +
        Controller_DW._DSTATE_h) + rtb_Add1_j4) + (CONTROL_PARAM.FW_TECS_W2P *
        rtb_Saturation2 - CONTROL_PARAM.FW_TECS_U2P * rtb_VdotPg_sp) *
        CONTROL_PARAM.FW_TECS_PITCH_F;
    }

    /* End of Switch: '<S40>/Switch' */

    /* Sum: '<S38>/Subtract' incorporates:
     *  DiscreteIntegrator: '<S38>/Integrator1'
     */
    rtb_Add1_j4 = Controller_DW.Integrator1_DSTATE_j - rtb_Divide_m_idx_0;

    /* Product: '<S43>/Multiply1' incorporates:
     *  Constant: '<S43>/const1'
     *  DiscreteIntegrator: '<S38>/Integrator'
     */
    rtb_Divide_m_idx_0 = Controller_DW.Integrator_DSTATE_d * 0.04F;

    /* Sum: '<S43>/Add' */
    rtb_Saturation2 = rtb_Add1_j4 + rtb_Divide_m_idx_0;

    /* Signum: '<S43>/Sign' */
    if (rtb_Saturation2 < 0.0F) {
      rtb_Add1_j4 = -1.0F;
    } else if (rtb_Saturation2 > 0.0F) {
      rtb_Add1_j4 = 1.0F;
    } else {
      rtb_Add1_j4 = rtb_Saturation2;
    }

    /* End of Signum: '<S43>/Sign' */

    /* Sum: '<S43>/Add2' incorporates:
     *  Abs: '<S43>/Abs'
     *  Gain: '<S43>/Gain'
     *  Gain: '<S43>/Gain1'
     *  Product: '<S43>/Multiply2'
     *  Product: '<S43>/Multiply3'
     *  Sqrt: '<S43>/Sqrt'
     *  Sum: '<S43>/Add1'
     *  Sum: '<S43>/Subtract'
     */
    rtb_a = (sqrtf((8.0F * fabsf(rtb_Saturation2) + Controller_ConstB.d_f) *
                   Controller_ConstB.d_f) - Controller_ConstB.d_f) * 0.5F *
      rtb_Add1_j4 + rtb_Divide_m_idx_0;

    /* Sum: '<S43>/Add4' */
    rtb_Add2_h = (rtb_Saturation2 - rtb_a) + rtb_Divide_m_idx_0;

    /* Sum: '<S43>/Add3' */
    rtb_Add1_j4 = rtb_Saturation2 + Controller_ConstB.d_f;

    /* Sum: '<S43>/Subtract1' */
    rtb_Saturation2 -= Controller_ConstB.d_f;

    /* Signum: '<S43>/Sign1' */
    if (rtb_Add1_j4 < 0.0F) {
      rtb_Add1_j4 = -1.0F;
    } else {
      if (rtb_Add1_j4 > 0.0F) {
        rtb_Add1_j4 = 1.0F;
      }
    }

    /* End of Signum: '<S43>/Sign1' */

    /* Signum: '<S43>/Sign2' */
    if (rtb_Saturation2 < 0.0F) {
      rtb_Saturation2 = -1.0F;
    } else {
      if (rtb_Saturation2 > 0.0F) {
        rtb_Saturation2 = 1.0F;
      }
    }

    /* End of Signum: '<S43>/Sign2' */

    /* Sum: '<S43>/Add5' incorporates:
     *  Gain: '<S43>/Gain2'
     *  Product: '<S43>/Multiply4'
     *  Sum: '<S43>/Subtract2'
     */
    rtb_a += (rtb_Add1_j4 - rtb_Saturation2) * 0.5F * rtb_Add2_h;

    /* Sum: '<S43>/Subtract3' */
    rtb_Add1_j4 = rtb_a - Controller_ConstB.d_f;

    /* Sum: '<S43>/Add6' */
    rtb_Add2_h = rtb_a + Controller_ConstB.d_f;

    /* Product: '<S43>/Divide' */
    rtb_Sum = rtb_a / Controller_ConstB.d_f;

    /* Signum: '<S43>/Sign5' incorporates:
     *  Signum: '<S43>/Sign6'
     */
    if (rtb_a < 0.0F) {
      rtb_Sign5_f = -1.0F;

      /* Signum: '<S43>/Sign6' */
      rtb_VdotPg_sp = -1.0F;
    } else if (rtb_a > 0.0F) {
      rtb_Sign5_f = 1.0F;

      /* Signum: '<S43>/Sign6' */
      rtb_VdotPg_sp = 1.0F;
    } else {
      rtb_Sign5_f = rtb_a;

      /* Signum: '<S43>/Sign6' */
      rtb_VdotPg_sp = rtb_a;
    }

    /* End of Signum: '<S43>/Sign5' */

    /* Product: '<S37>/Multiply1' incorporates:
     *  Constant: '<S37>/const1'
     *  DiscreteIntegrator: '<S36>/Integrator'
     */
    rtb_Divide_m_idx_0 = Controller_DW.Integrator_DSTATE_n * 0.05F;

    /* Sum: '<S37>/Add' incorporates:
     *  DiscreteIntegrator: '<S36>/Integrator1'
     *  Inport: '<Root>/FMS_Out'
     *  Sum: '<S36>/Subtract'
     */
    rtb_a = (Controller_DW.Integrator1_DSTATE_c - Controller_U.FMS_Out.ay_cmd) +
      rtb_Divide_m_idx_0;

    /* Signum: '<S37>/Sign' */
    if (rtb_a < 0.0F) {
      rtb_Saturation2 = -1.0F;
    } else if (rtb_a > 0.0F) {
      rtb_Saturation2 = 1.0F;
    } else {
      rtb_Saturation2 = rtb_a;
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
    rtb_Saturation2 = (sqrtf((8.0F * fabsf(rtb_a) + Controller_ConstB.d_i) *
      Controller_ConstB.d_i) - Controller_ConstB.d_i) * 0.5F * rtb_Saturation2 +
      rtb_Divide_m_idx_0;

    /* Sum: '<S37>/Add4' */
    rtb_Divide_m_idx_0 += rtb_a - rtb_Saturation2;

    /* Sum: '<S37>/Add3' */
    u = rtb_a + Controller_ConstB.d_i;

    /* Sum: '<S37>/Subtract1' */
    rtb_a -= Controller_ConstB.d_i;

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
    if (rtb_a < 0.0F) {
      rtb_a = -1.0F;
    } else {
      if (rtb_a > 0.0F) {
        rtb_a = 1.0F;
      }
    }

    /* End of Signum: '<S37>/Sign2' */

    /* Sum: '<S37>/Add5' incorporates:
     *  Gain: '<S37>/Gain2'
     *  Product: '<S37>/Multiply4'
     *  Sum: '<S37>/Subtract2'
     */
    rtb_Saturation2 += (u - rtb_a) * 0.5F * rtb_Divide_m_idx_0;

    /* Update for DiscreteIntegrator: '<S66>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S66>/Gain'
     *  Sum: '<S66>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_i = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_j += (rtb_Saturation1 -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j) * 62.831852F * 0.002F;

    /* Update for DiscreteIntegrator: '<S26>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S26>/Gain'
     *  Sum: '<S26>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_h = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_n += (rtb_Saturation_g -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_n) * 31.415926F * 0.002F;

    /* Update for DiscreteIntegrator: '<S36>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S36>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_c += 0.002F *
      Controller_DW.Integrator_DSTATE_n;

    /* Update for DiscreteIntegrator: '<S38>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S38>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_j += 0.002F *
      Controller_DW.Integrator_DSTATE_d;

    /* Update for DiscreteIntegrator: '<S25>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S25>/Gain'
     *  Sum: '<S25>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_L_hl = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_o += (rtb_Saturation_bx -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_o) * 31.415926F * 0.002F;

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

    /* Update for DiscreteIntegrator: '<S41>/ ' incorporates:
     *  Gain: '<S41>/Gain'
     */
    Controller_DW._DSTATE += CONTROL_PARAM.FW_TECS_THOR_I * rtb_Divide_m_idx_2 *
      0.002F;
    if (Controller_DW._DSTATE >= 1.0F) {
      Controller_DW._DSTATE = 1.0F;
    } else {
      if (Controller_DW._DSTATE <= 0.0F) {
        Controller_DW._DSTATE = 0.0F;
      }
    }

    /* End of Update for DiscreteIntegrator: '<S41>/ ' */

    /* Update for DiscreteIntegrator: '<S62>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_n = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_h += 0.002F * rtb_Divide_m_idx_1;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_d = 0;

    /* Update for DiscreteIntegrator: '<S61>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_h = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n += 0.002F * rtb_Gain_n4;
    Controller_DW.DiscreteTimeIntegrator1_Prev_dx = (int8_T)rtb_Compare_hi;

    /* Update for DiscreteIntegrator: '<S58>/ ' incorporates:
     *  Gain: '<S58>/Gain3'
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

    Controller_DW._PrevResetState = (int8_T)rtb_Compare_gi;

    /* End of Update for DiscreteIntegrator: '<S58>/ ' */

    /* Update for DiscreteIntegrator: '<S59>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_f = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_e += 0.002F * rtb_Divide_m_idx_3;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_b = (int8_T)rtb_Compare_gi;

    /* Signum: '<S43>/Sign3' */
    if (rtb_Add2_h < 0.0F) {
      rtb_Add2_h = -1.0F;
    } else {
      if (rtb_Add2_h > 0.0F) {
        rtb_Add2_h = 1.0F;
      }
    }

    /* End of Signum: '<S43>/Sign3' */

    /* Signum: '<S43>/Sign4' */
    if (rtb_Add1_j4 < 0.0F) {
      rtb_Add1_j4 = -1.0F;
    } else {
      if (rtb_Add1_j4 > 0.0F) {
        rtb_Add1_j4 = 1.0F;
      }
    }

    /* End of Signum: '<S43>/Sign4' */

    /* Update for DiscreteIntegrator: '<S38>/Integrator' incorporates:
     *  Constant: '<S43>/const'
     *  Gain: '<S43>/Gain3'
     *  Product: '<S43>/Multiply5'
     *  Product: '<S43>/Multiply6'
     *  Sum: '<S43>/Subtract4'
     *  Sum: '<S43>/Subtract5'
     *  Sum: '<S43>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE_d += ((rtb_Sum - rtb_Sign5_f) *
      Controller_ConstB.Gain4_n * ((rtb_Add2_h - rtb_Add1_j4) * 0.5F) -
      rtb_VdotPg_sp * 12.566371F) * 0.002F;

    /* Signum: '<S37>/Sign6' incorporates:
     *  Signum: '<S37>/Sign5'
     */
    if (rtb_Saturation2 < 0.0F) {
      rtb_VdotPg_sp = -1.0F;

      /* Signum: '<S37>/Sign5' */
      rtb_Saturation_g = -1.0F;
    } else if (rtb_Saturation2 > 0.0F) {
      rtb_VdotPg_sp = 1.0F;

      /* Signum: '<S37>/Sign5' */
      rtb_Saturation_g = 1.0F;
    } else {
      rtb_VdotPg_sp = rtb_Saturation2;

      /* Signum: '<S37>/Sign5' */
      rtb_Saturation_g = rtb_Saturation2;
    }

    /* End of Signum: '<S37>/Sign6' */

    /* Sum: '<S37>/Add6' */
    rtb_Add1_j4 = rtb_Saturation2 + Controller_ConstB.d_i;

    /* Sum: '<S37>/Subtract3' */
    rtb_Add2_h = rtb_Saturation2 - Controller_ConstB.d_i;

    /* Signum: '<S37>/Sign3' */
    if (rtb_Add1_j4 < 0.0F) {
      rtb_Add1_j4 = -1.0F;
    } else {
      if (rtb_Add1_j4 > 0.0F) {
        rtb_Add1_j4 = 1.0F;
      }
    }

    /* End of Signum: '<S37>/Sign3' */

    /* Signum: '<S37>/Sign4' */
    if (rtb_Add2_h < 0.0F) {
      rtb_Add2_h = -1.0F;
    } else {
      if (rtb_Add2_h > 0.0F) {
        rtb_Add2_h = 1.0F;
      }
    }

    /* End of Signum: '<S37>/Sign4' */

    /* Update for DiscreteIntegrator: '<S36>/Integrator' incorporates:
     *  Constant: '<S37>/const'
     *  Gain: '<S37>/Gain3'
     *  Product: '<S37>/Divide'
     *  Product: '<S37>/Multiply5'
     *  Product: '<S37>/Multiply6'
     *  Sum: '<S37>/Subtract4'
     *  Sum: '<S37>/Subtract5'
     *  Sum: '<S37>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE_n += ((rtb_Saturation2 /
      Controller_ConstB.d_i - rtb_Saturation_g) * Controller_ConstB.Gain4_g *
      ((rtb_Add1_j4 - rtb_Add2_h) * 0.5F) - rtb_VdotPg_sp * 58.836F) * 0.002F;
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
   *  Constant: '<S132>/Constant'
   *  Constant: '<S77>/Constant'
   *  DiscreteIntegrator: '<S120>/Integrator1'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S108>/Divide1'
   *  Product: '<S124>/Multiply'
   *  Product: '<S99>/Multiply'
   *  RelationalOperator: '<S132>/Compare'
   *  RelationalOperator: '<S77>/Compare'
   *  Signum: '<S108>/Sign'
   *  Sum: '<S115>/Sum'
   *  Sum: '<S123>/Add4'
   */
  if (Controller_DW.Relay_Mode) {
    if (!Controller_DW.MC_Controller_MODE) {
      /* InitializeConditions for DiscreteIntegrator: '<S100>/Discrete-Time Integrator' */
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

      /* End of InitializeConditions for DiscreteIntegrator: '<S100>/Discrete-Time Integrator' */

      /* InitializeConditions for DiscreteIntegrator: '<S97>/Discrete-Time Integrator5' */
      Controller_DW.DiscreteTimeIntegrator5_IC_LO_c = 1U;

      /* InitializeConditions for DiscreteIntegrator: '<S102>/Discrete-Time Integrator1' */
      Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

      /* InitializeConditions for Delay: '<S75>/Delay' */
      Controller_DW.Delay_DSTATE = 1U;
      Controller_DW.MC_Controller_MODE = true;
    }

    /* Sqrt: '<S92>/Sqrt' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Math: '<S92>/Square'
     *  Sum: '<S92>/Sum of Elements'
     */
    rtb_Saturation2 = sqrtf(((Controller_U.INS_Out.quat[0] *
      Controller_U.INS_Out.quat[0] + Controller_U.INS_Out.quat[1] *
      Controller_U.INS_Out.quat[1]) + Controller_U.INS_Out.quat[2] *
      Controller_U.INS_Out.quat[2]) + Controller_U.INS_Out.quat[3] *
      Controller_U.INS_Out.quat[3]);

    /* Product: '<S88>/Divide' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Sqrt: '<S92>/Sqrt'
     */
    rtb_Divide_m_idx_0 = Controller_U.INS_Out.quat[0] / rtb_Saturation2;
    rtb_Divide_m_idx_1 = Controller_U.INS_Out.quat[1] / rtb_Saturation2;
    rtb_Divide_m_idx_2 = Controller_U.INS_Out.quat[2] / rtb_Saturation2;
    rtb_Divide_m_idx_3 = Controller_U.INS_Out.quat[3] / rtb_Saturation2;

    /* Sum: '<S89>/Subtract' incorporates:
     *  Math: '<S89>/Square'
     *  Math: '<S89>/Square1'
     *  Math: '<S89>/Square2'
     *  Math: '<S89>/Square3'
     *  Sum: '<S89>/Add'
     *  Sum: '<S89>/Add1'
     */
    rtb_VectorConcatenate_i[0] = (rtb_Divide_m_idx_0 * rtb_Divide_m_idx_0 +
      rtb_Divide_m_idx_1 * rtb_Divide_m_idx_1) - (rtb_Divide_m_idx_2 *
      rtb_Divide_m_idx_2 + rtb_Divide_m_idx_3 * rtb_Divide_m_idx_3);

    /* Gain: '<S89>/Gain' incorporates:
     *  Product: '<S89>/Multiply'
     *  Product: '<S89>/Multiply1'
     *  Sum: '<S89>/Subtract1'
     */
    rtb_VectorConcatenate_i[1] = (rtb_Divide_m_idx_1 * rtb_Divide_m_idx_2 -
      rtb_Divide_m_idx_0 * rtb_Divide_m_idx_3) * 2.0F;

    /* Gain: '<S89>/Gain1' incorporates:
     *  Product: '<S89>/Multiply2'
     *  Product: '<S89>/Multiply3'
     *  Sum: '<S89>/Add2'
     */
    rtb_VectorConcatenate_i[2] = (rtb_Divide_m_idx_1 * rtb_Divide_m_idx_3 +
      rtb_Divide_m_idx_0 * rtb_Divide_m_idx_2) * 2.0F;

    /* Gain: '<S90>/Gain' incorporates:
     *  Product: '<S90>/Multiply'
     *  Product: '<S90>/Multiply1'
     *  Sum: '<S90>/Add3'
     */
    rtb_VectorConcatenate_i[3] = (rtb_Divide_m_idx_1 * rtb_Divide_m_idx_2 +
      rtb_Divide_m_idx_0 * rtb_Divide_m_idx_3) * 2.0F;

    /* Sum: '<S90>/Subtract' incorporates:
     *  Math: '<S90>/Square'
     *  Math: '<S90>/Square1'
     *  Math: '<S90>/Square2'
     *  Math: '<S90>/Square3'
     *  Sum: '<S90>/Add'
     *  Sum: '<S90>/Add1'
     */
    rtb_VectorConcatenate_i[4] = (rtb_Divide_m_idx_0 * rtb_Divide_m_idx_0 +
      rtb_Divide_m_idx_2 * rtb_Divide_m_idx_2) - (rtb_Divide_m_idx_1 *
      rtb_Divide_m_idx_1 + rtb_Divide_m_idx_3 * rtb_Divide_m_idx_3);

    /* Gain: '<S90>/Gain1' incorporates:
     *  Product: '<S90>/Multiply2'
     *  Product: '<S90>/Multiply3'
     *  Sum: '<S90>/Subtract1'
     */
    rtb_VectorConcatenate_i[5] = (rtb_Divide_m_idx_2 * rtb_Divide_m_idx_3 -
      rtb_Divide_m_idx_0 * rtb_Divide_m_idx_1) * 2.0F;

    /* Gain: '<S91>/Gain' incorporates:
     *  Product: '<S91>/Multiply'
     *  Product: '<S91>/Multiply1'
     *  Sum: '<S91>/Subtract2'
     */
    rtb_VectorConcatenate_i[6] = (rtb_Divide_m_idx_1 * rtb_Divide_m_idx_3 -
      rtb_Divide_m_idx_0 * rtb_Divide_m_idx_2) * 2.0F;

    /* Gain: '<S91>/Gain1' incorporates:
     *  Product: '<S91>/Multiply2'
     *  Product: '<S91>/Multiply3'
     *  Sum: '<S91>/Add2'
     */
    rtb_VectorConcatenate_i[7] = (rtb_Divide_m_idx_2 * rtb_Divide_m_idx_3 +
      rtb_Divide_m_idx_0 * rtb_Divide_m_idx_1) * 2.0F;

    /* Sum: '<S91>/Subtract' incorporates:
     *  Math: '<S91>/Square'
     *  Math: '<S91>/Square1'
     *  Math: '<S91>/Square2'
     *  Math: '<S91>/Square3'
     *  Sum: '<S91>/Add'
     *  Sum: '<S91>/Add1'
     */
    rtb_VectorConcatenate_i[8] = (rtb_Divide_m_idx_0 * rtb_Divide_m_idx_0 +
      rtb_Divide_m_idx_3 * rtb_Divide_m_idx_3) - (rtb_Divide_m_idx_1 *
      rtb_Divide_m_idx_1 + rtb_Divide_m_idx_2 * rtb_Divide_m_idx_2);

    /* Product: '<S85>/Multiply' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  SignalConversion: '<S85>/TmpSignal ConversionAtMultiplyInport2'
     */
    for (i = 0; i < 3; i++) {
      rtb_fw_rate_err_B[i] = rtb_VectorConcatenate_i[i + 6] *
        Controller_U.INS_Out.vd + (rtb_VectorConcatenate_i[i + 3] *
        Controller_U.INS_Out.ve + rtb_VectorConcatenate_i[i] *
        Controller_U.INS_Out.vn);
    }

    /* End of Product: '<S85>/Multiply' */

    /* DiscreteIntegrator: '<S100>/Discrete-Time Integrator' incorporates:
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

    /* Outputs for Enabled SubSystem: '<S74>/Velocity_Controller' incorporates:
     *  EnablePort: '<S78>/Enable'
     */
    if (Controller_U.FMS_Out.ctrl_mode >= 5) {
      if (!Controller_DW.Velocity_Controller_MODE) {
        /* InitializeConditions for DiscreteIntegrator: '<S120>/Integrator1' */
        Controller_DW.Integrator1_IC_LOADING = 1U;

        /* InitializeConditions for DiscreteIntegrator: '<S120>/Integrator' */
        Controller_DW.Integrator_DSTATE_o[0] = 0.0F;

        /* InitializeConditions for DiscreteIntegrator: '<S125>/Discrete-Time Integrator' */
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

        /* InitializeConditions for DiscreteIntegrator: '<S120>/Integrator' */
        Controller_DW.Integrator_DSTATE_o[1] = 0.0F;

        /* InitializeConditions for DiscreteIntegrator: '<S125>/Discrete-Time Integrator' */
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

        Controller_DW.DiscreteTimeIntegrator_PrevRe_p = 0;

        /* InitializeConditions for DiscreteIntegrator: '<S127>/Discrete-Time Integrator1' */
        Controller_DW.DiscreteTimeIntegrator1_IC_LO_m = 1U;
        Controller_DW.DiscreteTimeIntegrator1_PrevR_a = 0;
        Controller_DW.Velocity_Controller_MODE = true;
      }

      /* Trigonometry: '<S122>/Trigonometric Function1' incorporates:
       *  Gain: '<S121>/Gain'
       *  Inport: '<Root>/INS_Out'
       */
      rtb_VectorConcatenate_i[0] = arm_cos_f32(-Controller_U.INS_Out.psi);

      /* Trigonometry: '<S122>/Trigonometric Function' incorporates:
       *  Gain: '<S121>/Gain'
       *  Inport: '<Root>/INS_Out'
       */
      rtb_VectorConcatenate_i[1] = arm_sin_f32(-Controller_U.INS_Out.psi);

      /* SignalConversion: '<S122>/ConcatBufferAtVector Concatenate1In3' incorporates:
       *  Constant: '<S122>/Constant3'
       */
      rtb_VectorConcatenate_i[2] = 0.0F;

      /* Gain: '<S122>/Gain' incorporates:
       *  Gain: '<S121>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S122>/Trigonometric Function2'
       */
      rtb_VectorConcatenate_i[3] = -arm_sin_f32(-Controller_U.INS_Out.psi);

      /* Trigonometry: '<S122>/Trigonometric Function3' incorporates:
       *  Gain: '<S121>/Gain'
       *  Inport: '<Root>/INS_Out'
       */
      rtb_VectorConcatenate_i[4] = arm_cos_f32(-Controller_U.INS_Out.psi);

      /* SignalConversion: '<S122>/ConcatBufferAtVector Concatenate2In3' incorporates:
       *  Constant: '<S122>/Constant4'
       */
      rtb_VectorConcatenate_i[5] = 0.0F;

      /* SignalConversion: '<S122>/ConcatBufferAtVector ConcatenateIn3' */
      rtb_VectorConcatenate_i[6] = Controller_ConstB.VectorConcatenate3[0];
      rtb_VectorConcatenate_i[7] = Controller_ConstB.VectorConcatenate3[1];
      rtb_VectorConcatenate_i[8] = Controller_ConstB.VectorConcatenate3[2];

      /* Product: '<S118>/Multiply' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  SignalConversion: '<S118>/TmpSignal ConversionAtMultiplyInport2'
       */
      for (i = 0; i < 3; i++) {
        rtb_TmpSignalConversionAtMultip[i] = rtb_VectorConcatenate_i[i + 3] *
          Controller_U.INS_Out.ve + rtb_VectorConcatenate_i[i] *
          Controller_U.INS_Out.vn;
      }

      /* End of Product: '<S118>/Multiply' */

      /* DiscreteIntegrator: '<S120>/Integrator1' */
      if (Controller_DW.Integrator1_IC_LOADING != 0) {
        /* Switch: '<S115>/Switch' incorporates:
         *  Constant: '<S119>/Constant'
         *  Inport: '<Root>/INS_Out'
         *  RelationalOperator: '<S119>/Compare'
         *  S-Function (sfix_bitop): '<S115>/vel_valid'
         */
        if ((Controller_U.INS_Out.flag & 16U) == 0U) {
          Controller_DW.Integrator1_DSTATE_p[0] = Controller_U.FMS_Out.u_cmd;
          Controller_DW.Integrator1_DSTATE_p[1] = Controller_U.FMS_Out.v_cmd;
        } else {
          Controller_DW.Integrator1_DSTATE_p[0] =
            rtb_TmpSignalConversionAtMultip[0];
          Controller_DW.Integrator1_DSTATE_p[1] =
            rtb_TmpSignalConversionAtMultip[1];
        }

        /* End of Switch: '<S115>/Switch' */
      }

      /* Product: '<S123>/Multiply1' incorporates:
       *  Constant: '<S123>/const1'
       *  DiscreteIntegrator: '<S120>/Integrator'
       */
      rtb_Saturation1 = Controller_DW.Integrator_DSTATE_o[0] * 0.05F;
      rtb_Divide_m_idx_0 = Controller_DW.Integrator_DSTATE_o[1] * 0.05F;

      /* Sum: '<S123>/Add' incorporates:
       *  DiscreteIntegrator: '<S120>/Integrator1'
       *  Sum: '<S120>/Subtract'
       */
      rtb_Saturation2 = (Controller_DW.Integrator1_DSTATE_p[0] -
                         Controller_U.FMS_Out.u_cmd) + rtb_Saturation1;
      rtb_Add_k = (Controller_DW.Integrator1_DSTATE_p[1] -
                   Controller_U.FMS_Out.v_cmd) + rtb_Divide_m_idx_0;

      /* Signum: '<S123>/Sign' */
      if (rtb_Saturation2 < 0.0F) {
        rtb_Saturation_g = -1.0F;
      } else if (rtb_Saturation2 > 0.0F) {
        rtb_Saturation_g = 1.0F;
      } else {
        rtb_Saturation_g = rtb_Saturation2;
      }

      /* Sum: '<S123>/Add2' incorporates:
       *  Abs: '<S123>/Abs'
       *  Gain: '<S123>/Gain'
       *  Gain: '<S123>/Gain1'
       *  Product: '<S123>/Multiply2'
       *  Product: '<S123>/Multiply3'
       *  Signum: '<S123>/Sign'
       *  Sqrt: '<S123>/Sqrt'
       *  Sum: '<S123>/Add1'
       *  Sum: '<S123>/Subtract'
       */
      rtb_Saturation_g = (sqrtf((8.0F * fabsf(rtb_Saturation2) +
        Controller_ConstB.d_j) * Controller_ConstB.d_j) - Controller_ConstB.d_j)
        * 0.5F * rtb_Saturation_g + rtb_Saturation1;

      /* Sum: '<S123>/Add3' incorporates:
       *  Signum: '<S123>/Sign'
       */
      rtb_Add1_j4 = rtb_Saturation2 + Controller_ConstB.d_j;

      /* Sum: '<S123>/Subtract1' incorporates:
       *  Signum: '<S123>/Sign'
       */
      rtb_Add2_h = rtb_Saturation2 - Controller_ConstB.d_j;

      /* Signum: '<S123>/Sign1' */
      if (rtb_Add1_j4 < 0.0F) {
        rtb_Add1_j4 = -1.0F;
      } else {
        if (rtb_Add1_j4 > 0.0F) {
          rtb_Add1_j4 = 1.0F;
        }
      }

      /* Signum: '<S123>/Sign2' */
      if (rtb_Add2_h < 0.0F) {
        rtb_Add2_h = -1.0F;
      } else {
        if (rtb_Add2_h > 0.0F) {
          rtb_Add2_h = 1.0F;
        }
      }

      /* Sum: '<S123>/Add2' incorporates:
       *  Gain: '<S123>/Gain2'
       *  Product: '<S123>/Multiply4'
       *  Signum: '<S123>/Sign'
       *  Sum: '<S123>/Add4'
       *  Sum: '<S123>/Add5'
       *  Sum: '<S123>/Subtract2'
       */
      rtb_Saturation_bx = ((rtb_Saturation2 - rtb_Saturation_g) +
                           rtb_Saturation1) * ((rtb_Add1_j4 - rtb_Add2_h) * 0.5F)
        + rtb_Saturation_g;
      rtb_Saturation1 = Controller_DW.Integrator1_DSTATE_p[0] -
        rtb_TmpSignalConversionAtMultip[0];

      /* Signum: '<S123>/Sign' incorporates:
       *  DiscreteIntegrator: '<S120>/Integrator1'
       *  Sum: '<S115>/Sum'
       *  Sum: '<S123>/Add4'
       */
      if (rtb_Add_k < 0.0F) {
        rtb_Saturation_g = -1.0F;
      } else if (rtb_Add_k > 0.0F) {
        rtb_Saturation_g = 1.0F;
      } else {
        rtb_Saturation_g = rtb_Add_k;
      }

      /* Sum: '<S123>/Add2' incorporates:
       *  Abs: '<S123>/Abs'
       *  Gain: '<S123>/Gain'
       *  Gain: '<S123>/Gain1'
       *  Product: '<S123>/Multiply2'
       *  Product: '<S123>/Multiply3'
       *  Signum: '<S123>/Sign'
       *  Sqrt: '<S123>/Sqrt'
       *  Sum: '<S123>/Add1'
       *  Sum: '<S123>/Subtract'
       */
      rtb_Saturation_g = (sqrtf((8.0F * fabsf(rtb_Add_k) + Controller_ConstB.d_j)
        * Controller_ConstB.d_j) - Controller_ConstB.d_j) * 0.5F *
        rtb_Saturation_g + rtb_Divide_m_idx_0;

      /* Sum: '<S123>/Add3' incorporates:
       *  Signum: '<S123>/Sign'
       */
      rtb_Add1_j4 = rtb_Add_k + Controller_ConstB.d_j;

      /* Sum: '<S123>/Subtract1' incorporates:
       *  Signum: '<S123>/Sign'
       */
      rtb_Add2_h = rtb_Add_k - Controller_ConstB.d_j;

      /* Signum: '<S123>/Sign1' */
      if (rtb_Add1_j4 < 0.0F) {
        rtb_Add1_j4 = -1.0F;
      } else {
        if (rtb_Add1_j4 > 0.0F) {
          rtb_Add1_j4 = 1.0F;
        }
      }

      /* Signum: '<S123>/Sign2' */
      if (rtb_Add2_h < 0.0F) {
        rtb_Add2_h = -1.0F;
      } else {
        if (rtb_Add2_h > 0.0F) {
          rtb_Add2_h = 1.0F;
        }
      }

      /* Sum: '<S123>/Add5' incorporates:
       *  Gain: '<S123>/Gain2'
       *  Product: '<S123>/Multiply4'
       *  Signum: '<S123>/Sign'
       *  Sum: '<S123>/Add2'
       *  Sum: '<S123>/Add4'
       *  Sum: '<S123>/Subtract2'
       */
      rtb_Saturation_g += ((rtb_Add_k - rtb_Saturation_g) + rtb_Divide_m_idx_0) *
        ((rtb_Add1_j4 - rtb_Add2_h) * 0.5F);

      /* Sum: '<S115>/Sum' incorporates:
       *  DiscreteIntegrator: '<S120>/Integrator1'
       */
      rtb_Divide_m_idx_0 = Controller_DW.Integrator1_DSTATE_p[1] -
        rtb_TmpSignalConversionAtMultip[1];

      /* Logic: '<S78>/Logical Operator' incorporates:
       *  Constant: '<S114>/Constant'
       *  RelationalOperator: '<S114>/Compare'
       */
      rtb_Compare_hi = ((Controller_U.FMS_Out.reset != 0) ||
                        (Controller_U.FMS_Out.ext_state != 0));

      /* DiscreteIntegrator: '<S125>/Discrete-Time Integrator' */
      if (rtb_Compare_hi || (Controller_DW.DiscreteTimeIntegrator_PrevRe_p != 0))
      {
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

      /* DiscreteIntegrator: '<S127>/Discrete-Time Integrator1' */
      if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_m != 0) {
        Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[0] = rtb_Saturation1;
        Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[1] = rtb_Divide_m_idx_0;
      }

      if (rtb_Compare_hi || (Controller_DW.DiscreteTimeIntegrator1_PrevR_a != 0))
      {
        Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[0] = rtb_Saturation1;
        Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[1] = rtb_Divide_m_idx_0;
      }

      /* Gain: '<S127>/Gain' incorporates:
       *  DiscreteIntegrator: '<S127>/Discrete-Time Integrator1'
       *  Sum: '<S127>/Sum5'
       */
      rtb_Divide_m_idx_2 = (rtb_Saturation1 -
                            Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[0]) *
        62.831852F;
      rtb_Divide_m_idx_1 = (rtb_Divide_m_idx_0 -
                            Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[1]) *
        62.831852F;

      /* Switch: '<S127>/Switch' incorporates:
       *  Gain: '<S127>/Gain1'
       */
      if (rtb_Compare_hi) {
        rtb_Saturation2 = 0.0F;
        rtb_Add_k = 0.0F;
      } else {
        rtb_Saturation2 = rtb_Divide_m_idx_2;
        rtb_Add_k = rtb_Divide_m_idx_1;
      }

      /* End of Switch: '<S127>/Switch' */

      /* Product: '<S124>/Multiply' incorporates:
       *  Constant: '<S124>/kd'
       */
      rtb_Add2_h = CONTROL_PARAM.MC_VEL_XY_D * rtb_Saturation2;

      /* Saturate: '<S124>/Saturation' */
      if (rtb_Add2_h > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
        rtb_Add2_h = CONTROL_PARAM.MC_VEL_XY_D_MAX;
      } else {
        if (rtb_Add2_h < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
          rtb_Add2_h = CONTROL_PARAM.MC_VEL_XY_D_MIN;
        }
      }

      rtb_Saturation2 = rtb_Add2_h;

      /* Product: '<S124>/Multiply' incorporates:
       *  Constant: '<S124>/kd'
       */
      rtb_Add2_h = CONTROL_PARAM.MC_VEL_XY_D * rtb_Add_k;

      /* Saturate: '<S124>/Saturation' */
      if (rtb_Add2_h > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
        rtb_Add2_h = CONTROL_PARAM.MC_VEL_XY_D_MAX;
      } else {
        if (rtb_Add2_h < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
          rtb_Add2_h = CONTROL_PARAM.MC_VEL_XY_D_MIN;
        }
      }

      /* Switch: '<S117>/Switch' incorporates:
       *  Constant: '<S126>/kp'
       *  Constant: '<S128>/Constant'
       *  Constant: '<S130>/Constant'
       *  Constant: '<S131>/Constant'
       *  DiscreteIntegrator: '<S125>/Discrete-Time Integrator'
       *  Product: '<S126>/Multiply'
       *  Product: '<S129>/Multiply2'
       *  Product: '<S129>/Multiply3'
       *  RelationalOperator: '<S128>/Compare'
       *  RelationalOperator: '<S130>/Compare'
       *  RelationalOperator: '<S131>/Compare'
       *  S-Function (sfix_bitop): '<S129>/cmd_ax valid'
       *  S-Function (sfix_bitop): '<S129>/cmd_ay valid'
       *  S-Function (sfix_bitop): '<S129>/cmd_u valid'
       *  S-Function (sfix_bitop): '<S129>/cmd_v valid'
       *  Sum: '<S116>/Add'
       *  Sum: '<S129>/Sum1'
       */
      if (Controller_U.FMS_Out.ctrl_mode == 6) {
        rtb_Saturation2 = ((Controller_U.FMS_Out.cmd_mask & 64) > 0 ?
                           (CONTROL_PARAM.MC_VEL_XY_P * rtb_Saturation1 +
                            Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0]) +
                           rtb_Saturation2 : 0.0F) +
          ((Controller_U.FMS_Out.cmd_mask & 512) > 0 ?
           Controller_U.FMS_Out.ax_cmd : 0.0F);
        rtb_Add_k = ((Controller_U.FMS_Out.cmd_mask & 128) > 0 ?
                     (CONTROL_PARAM.MC_VEL_XY_P * rtb_Divide_m_idx_0 +
                      Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1]) +
                     rtb_Add2_h : 0.0F) + ((Controller_U.FMS_Out.cmd_mask & 1024)
          > 0 ? Controller_U.FMS_Out.ay_cmd : 0.0F);
      } else {
        rtb_Saturation2 += CONTROL_PARAM.MC_VEL_XY_P * rtb_Saturation1 +
          Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0];
        rtb_Add_k = (CONTROL_PARAM.MC_VEL_XY_P * rtb_Divide_m_idx_0 +
                     Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1]) +
          rtb_Add2_h;
      }

      /* End of Switch: '<S117>/Switch' */

      /* Update for DiscreteIntegrator: '<S120>/Integrator1' */
      Controller_DW.Integrator1_IC_LOADING = 0U;

      /* Update for DiscreteIntegrator: '<S125>/Discrete-Time Integrator' */
      Controller_DW.DiscreteTimeIntegrator_PrevRe_p = (int8_T)rtb_Compare_hi;

      /* Update for DiscreteIntegrator: '<S127>/Discrete-Time Integrator1' */
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_m = 0U;

      /* Trigonometry: '<S113>/Atan' incorporates:
       *  Constant: '<S113>/g'
       *  Gain: '<S113>/gain'
       *  Product: '<S113>/Divide'
       */
      rtb_Add_k = atanf(1.1F * rtb_Add_k / 9.8055F);

      /* Saturate: '<S113>/Saturation' */
      if (rtb_Add_k > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        Controller_B.Saturation_h[0] = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else if (rtb_Add_k < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        Controller_B.Saturation_h[0] = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        Controller_B.Saturation_h[0] = rtb_Add_k;
      }

      /* Update for DiscreteIntegrator: '<S120>/Integrator1' incorporates:
       *  DiscreteIntegrator: '<S120>/Integrator'
       */
      Controller_DW.Integrator1_DSTATE_p[0] += 0.002F *
        Controller_DW.Integrator_DSTATE_o[0];

      /* Signum: '<S123>/Sign3' incorporates:
       *  Product: '<S123>/Divide'
       *  Sum: '<S123>/Add6'
       */
      rtb_Add1_j4 = rtb_Saturation_bx + Controller_ConstB.d_j;

      /* Signum: '<S123>/Sign4' incorporates:
       *  Product: '<S123>/Divide'
       *  Sum: '<S123>/Subtract3'
       */
      rtb_Add2_h = rtb_Saturation_bx - Controller_ConstB.d_j;

      /* Signum: '<S123>/Sign5' incorporates:
       *  Product: '<S123>/Divide'
       */
      if (rtb_Saturation_bx < 0.0F) {
        rtb_Add_k = -1.0F;
      } else if (rtb_Saturation_bx > 0.0F) {
        rtb_Add_k = 1.0F;
      } else {
        rtb_Add_k = rtb_Saturation_bx;
      }

      /* Signum: '<S123>/Sign3' */
      if (rtb_Add1_j4 < 0.0F) {
        rtb_Add1_j4 = -1.0F;
      } else {
        if (rtb_Add1_j4 > 0.0F) {
          rtb_Add1_j4 = 1.0F;
        }
      }

      /* Signum: '<S123>/Sign4' */
      if (rtb_Add2_h < 0.0F) {
        rtb_Add2_h = -1.0F;
      } else {
        if (rtb_Add2_h > 0.0F) {
          rtb_Add2_h = 1.0F;
        }
      }

      /* Signum: '<S123>/Sign6' incorporates:
       *  Product: '<S123>/Divide'
       */
      if (rtb_Saturation_bx < 0.0F) {
        rtb_Gain_n4 = -1.0F;
      } else if (rtb_Saturation_bx > 0.0F) {
        rtb_Gain_n4 = 1.0F;
      } else {
        rtb_Gain_n4 = rtb_Saturation_bx;
      }

      /* Update for DiscreteIntegrator: '<S120>/Integrator' incorporates:
       *  Constant: '<S123>/const'
       *  Gain: '<S123>/Gain3'
       *  Product: '<S123>/Divide'
       *  Product: '<S123>/Multiply5'
       *  Product: '<S123>/Multiply6'
       *  Sum: '<S123>/Subtract4'
       *  Sum: '<S123>/Subtract5'
       *  Sum: '<S123>/Subtract6'
       */
      Controller_DW.Integrator_DSTATE_o[0] += ((rtb_Saturation_bx /
        Controller_ConstB.d_j - rtb_Add_k) * Controller_ConstB.Gain4_l *
        ((rtb_Add1_j4 - rtb_Add2_h) * 0.5F) - rtb_Gain_n4 * 58.836F) * 0.002F;

      /* Update for DiscreteIntegrator: '<S125>/Discrete-Time Integrator' incorporates:
       *  Constant: '<S125>/ki'
       *  Product: '<S125>/Multiply'
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

      /* Update for DiscreteIntegrator: '<S127>/Discrete-Time Integrator1' */
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[0] += 0.002F *
        rtb_Divide_m_idx_2;

      /* Trigonometry: '<S113>/Atan' incorporates:
       *  Constant: '<S113>/g'
       *  Gain: '<S113>/Gain1'
       *  Gain: '<S113>/gain'
       *  Product: '<S113>/Divide'
       */
      rtb_Add_k = atanf(1.1F * -rtb_Saturation2 / 9.8055F);

      /* Saturate: '<S113>/Saturation' */
      if (rtb_Add_k > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        Controller_B.Saturation_h[1] = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else if (rtb_Add_k < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        Controller_B.Saturation_h[1] = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        Controller_B.Saturation_h[1] = rtb_Add_k;
      }

      /* Update for DiscreteIntegrator: '<S120>/Integrator1' incorporates:
       *  DiscreteIntegrator: '<S120>/Integrator'
       */
      Controller_DW.Integrator1_DSTATE_p[1] += 0.002F *
        Controller_DW.Integrator_DSTATE_o[1];

      /* Signum: '<S123>/Sign3' incorporates:
       *  Sum: '<S123>/Add6'
       */
      rtb_Add1_j4 = rtb_Saturation_g + Controller_ConstB.d_j;

      /* Signum: '<S123>/Sign4' incorporates:
       *  Sum: '<S123>/Subtract3'
       */
      rtb_Add2_h = rtb_Saturation_g - Controller_ConstB.d_j;

      /* Signum: '<S123>/Sign5' */
      if (rtb_Saturation_g < 0.0F) {
        rtb_Saturation1 = -1.0F;
      } else if (rtb_Saturation_g > 0.0F) {
        rtb_Saturation1 = 1.0F;
      } else {
        rtb_Saturation1 = rtb_Saturation_g;
      }

      /* Signum: '<S123>/Sign3' */
      if (rtb_Add1_j4 < 0.0F) {
        rtb_Add1_j4 = -1.0F;
      } else {
        if (rtb_Add1_j4 > 0.0F) {
          rtb_Add1_j4 = 1.0F;
        }
      }

      /* Signum: '<S123>/Sign4' */
      if (rtb_Add2_h < 0.0F) {
        rtb_Add2_h = -1.0F;
      } else {
        if (rtb_Add2_h > 0.0F) {
          rtb_Add2_h = 1.0F;
        }
      }

      /* Signum: '<S123>/Sign6' */
      if (rtb_Saturation_g < 0.0F) {
        rtb_Saturation_bx = -1.0F;
      } else if (rtb_Saturation_g > 0.0F) {
        rtb_Saturation_bx = 1.0F;
      } else {
        rtb_Saturation_bx = rtb_Saturation_g;
      }

      /* Update for DiscreteIntegrator: '<S120>/Integrator' incorporates:
       *  Constant: '<S123>/const'
       *  Gain: '<S123>/Gain3'
       *  Product: '<S123>/Divide'
       *  Product: '<S123>/Multiply5'
       *  Product: '<S123>/Multiply6'
       *  Sum: '<S123>/Subtract4'
       *  Sum: '<S123>/Subtract5'
       *  Sum: '<S123>/Subtract6'
       */
      Controller_DW.Integrator_DSTATE_o[1] += ((rtb_Saturation_g /
        Controller_ConstB.d_j - rtb_Saturation1) * Controller_ConstB.Gain4_l *
        ((rtb_Add1_j4 - rtb_Add2_h) * 0.5F) - rtb_Saturation_bx * 58.836F) *
        0.002F;

      /* Update for DiscreteIntegrator: '<S125>/Discrete-Time Integrator' incorporates:
       *  Constant: '<S125>/ki'
       *  Product: '<S125>/Multiply'
       */
      Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1] +=
        CONTROL_PARAM.MC_VEL_XY_I * rtb_Divide_m_idx_0 * 0.002F;
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

      /* Update for DiscreteIntegrator: '<S127>/Discrete-Time Integrator1' */
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[1] += 0.002F *
        rtb_Divide_m_idx_1;
      Controller_DW.DiscreteTimeIntegrator1_PrevR_a = (int8_T)rtb_Compare_hi;
    } else {
      if (Controller_DW.Velocity_Controller_MODE) {
        Controller_DW.Velocity_Controller_MODE = false;
      }
    }

    /* End of Outputs for SubSystem: '<S74>/Velocity_Controller' */

    /* Switch: '<S104>/Switch' incorporates:
     *  Constant: '<S111>/Constant'
     *  Constant: '<S77>/Constant'
     *  DiscreteIntegrator: '<S120>/Integrator1'
     *  Inport: '<Root>/FMS_Out'
     *  Logic: '<S104>/Logical Operator'
     *  Product: '<S124>/Multiply'
     *  RelationalOperator: '<S110>/Compare'
     *  RelationalOperator: '<S111>/Compare'
     *  RelationalOperator: '<S77>/Compare'
     *  Sum: '<S115>/Sum'
     *  Sum: '<S123>/Add4'
     *  Switch: '<S104>/Switch1'
     */
    if ((Controller_U.FMS_Out.ctrl_mode == 3) || (Controller_U.FMS_Out.ctrl_mode
         == 4)) {
      rtb_Saturation2 = Controller_U.FMS_Out.phi_cmd;
      rtb_Add_k = Controller_U.FMS_Out.theta_cmd;
    } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
      /* Switch: '<S112>/Switch' incorporates:
       *  S-Function (sfix_bitop): '<S112>/cmd_phi valid'
       *  S-Function (sfix_bitop): '<S112>/cmd_theta valid'
       *  Switch: '<S104>/Switch1'
       */
      if ((Controller_U.FMS_Out.cmd_mask & 8) > 0) {
        rtb_Saturation2 = Controller_U.FMS_Out.phi_cmd;
      } else {
        rtb_Saturation2 = Controller_B.Saturation_h[0];
      }

      if ((Controller_U.FMS_Out.cmd_mask & 16) > 0) {
        rtb_Add_k = Controller_U.FMS_Out.theta_cmd;
      } else {
        rtb_Add_k = Controller_B.Saturation_h[1];
      }

      /* End of Switch: '<S112>/Switch' */
    } else {
      /* Switch: '<S104>/Switch1' */
      rtb_Saturation2 = Controller_B.Saturation_h[0];
      rtb_Add_k = Controller_B.Saturation_h[1];
    }

    /* End of Switch: '<S104>/Switch' */

    /* Sum: '<S105>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Add2_h = rtb_Saturation2 - Controller_U.INS_Out.phi;

    /* Product: '<S108>/Divide1' incorporates:
     *  Abs: '<S108>/Abs'
     *  Constant: '<S108>/const2'
     */
    rtb_Divide_m_idx_0 = fabsf(rtb_Add2_h) / 0.002F;

    /* Product: '<S108>/Divide' incorporates:
     *  Constant: '<S106>/Constant1'
     *  Constant: '<S108>/const1'
     *  Math: '<S108>/Square'
     *  SignalConversion: '<S108>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_Saturation_g = 9.5993F / (CONTROL_PARAM.MC_ROLL_P *
      CONTROL_PARAM.MC_ROLL_P);

    /* Signum: '<S108>/Sign' */
    if (rtb_Add2_h < 0.0F) {
      rtb_Saturation2 = -1.0F;
    } else if (rtb_Add2_h > 0.0F) {
      rtb_Saturation2 = 1.0F;
    } else {
      rtb_Saturation2 = rtb_Add2_h;
    }

    /* Switch: '<S108>/Switch' incorporates:
     *  Constant: '<S106>/Constant1'
     *  Gain: '<S108>/Gain1'
     *  Gain: '<S108>/Gain2'
     *  Logic: '<S108>/Logical Operator'
     *  Product: '<S108>/Multiply'
     *  Product: '<S108>/Multiply1'
     *  Product: '<S108>/Multiply2'
     *  Product: '<S108>/Multiply3'
     *  RelationalOperator: '<S108>/Relational Operator'
     *  RelationalOperator: '<S108>/Relational Operator2'
     *  SignalConversion: '<S108>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S108>/Sqrt'
     *  Sum: '<S108>/Subtract'
     */
    if ((rtb_Add2_h <= rtb_Saturation_g) && (rtb_Add2_h >= -rtb_Saturation_g)) {
      rtb_Saturation2 = rtb_Add2_h * CONTROL_PARAM.MC_ROLL_P;
    } else {
      rtb_Saturation2 *= sqrtf((rtb_Saturation2 * rtb_Add2_h - 0.5F *
        rtb_Saturation_g) * Controller_ConstB.Gain);
    }

    /* Product: '<S108>/Divide' incorporates:
     *  Gain: '<S108>/Gain3'
     */
    rtb_Saturation_bx = -rtb_Divide_m_idx_0;

    /* Switch: '<S109>/Switch' incorporates:
     *  Gain: '<S108>/Gain3'
     *  RelationalOperator: '<S109>/UpperRelop'
     */
    if (rtb_Saturation2 >= -rtb_Divide_m_idx_0) {
      /* Product: '<S108>/Divide' */
      rtb_Saturation_bx = rtb_Saturation2;
    }

    rtb_Saturation1 = rtb_Divide_m_idx_0;
    rtb_Add1_j4 = rtb_Saturation2;

    /* Sum: '<S105>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S108>/Divide1'
     *  Signum: '<S108>/Sign'
     */
    rtb_Add2_h = rtb_Add_k - Controller_U.INS_Out.theta;

    /* Product: '<S108>/Divide1' incorporates:
     *  Abs: '<S108>/Abs'
     *  Constant: '<S108>/const2'
     */
    rtb_Divide_m_idx_0 = fabsf(rtb_Add2_h) / 0.002F;

    /* Product: '<S108>/Divide' incorporates:
     *  Constant: '<S106>/Constant2'
     *  Constant: '<S108>/const1'
     *  Math: '<S108>/Square'
     *  SignalConversion: '<S108>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_Saturation_g = 9.5993F / (CONTROL_PARAM.MC_PITCH_P *
      CONTROL_PARAM.MC_PITCH_P);

    /* Signum: '<S108>/Sign' */
    if (rtb_Add2_h < 0.0F) {
      rtb_Saturation2 = -1.0F;
    } else if (rtb_Add2_h > 0.0F) {
      rtb_Saturation2 = 1.0F;
    } else {
      rtb_Saturation2 = rtb_Add2_h;
    }

    /* Switch: '<S108>/Switch' incorporates:
     *  Constant: '<S106>/Constant2'
     *  Gain: '<S108>/Gain1'
     *  Gain: '<S108>/Gain2'
     *  Logic: '<S108>/Logical Operator'
     *  Product: '<S108>/Multiply'
     *  Product: '<S108>/Multiply1'
     *  Product: '<S108>/Multiply2'
     *  Product: '<S108>/Multiply3'
     *  RelationalOperator: '<S108>/Relational Operator'
     *  RelationalOperator: '<S108>/Relational Operator2'
     *  SignalConversion: '<S108>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S108>/Sqrt'
     *  Sum: '<S108>/Subtract'
     */
    if ((rtb_Add2_h <= rtb_Saturation_g) && (rtb_Add2_h >= -rtb_Saturation_g)) {
      rtb_Saturation2 = rtb_Add2_h * CONTROL_PARAM.MC_PITCH_P;
    } else {
      rtb_Saturation2 *= sqrtf((rtb_Saturation2 * rtb_Add2_h - 0.5F *
        rtb_Saturation_g) * Controller_ConstB.Gain);
    }

    /* Gain: '<S108>/Gain3' */
    rtb_Saturation_g = -rtb_Divide_m_idx_0;

    /* Switch: '<S109>/Switch' incorporates:
     *  Gain: '<S108>/Gain3'
     *  RelationalOperator: '<S109>/UpperRelop'
     */
    if (rtb_Saturation2 >= -rtb_Divide_m_idx_0) {
      rtb_Saturation_g = rtb_Saturation2;
    }

    /* MultiPortSwitch: '<S81>/Multiport Switch' incorporates:
     *  Constant: '<S83>/Constant3'
     *  Constant: '<S86>/Constant3'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S83>/Multiply1'
     *  Product: '<S83>/Multiply2'
     *  Product: '<S86>/Multiply1'
     *  Product: '<S86>/Multiply2'
     *  Sum: '<S83>/Sum'
     *  Sum: '<S83>/Sum1'
     *  Sum: '<S86>/Sum'
     *  Sum: '<S86>/Sum1'
     */
    switch (Controller_U.FMS_Out.ext_state) {
     case 1:
      /* Saturate: '<S86>/Saturation3' */
      if (rtb_fw_rate_err_B[0] > 8.0F) {
        rtb_Add_k = 8.0F;
      } else if (rtb_fw_rate_err_B[0] < 2.0F) {
        rtb_Add_k = 2.0F;
      } else {
        rtb_Add_k = rtb_fw_rate_err_B[0];
      }

      /* End of Saturate: '<S86>/Saturation3' */

      /* Product: '<S86>/Multiply' incorporates:
       *  Constant: '<S86>/Constant1'
       *  Sum: '<S86>/Subtract1'
       */
      rtb_Saturation_g = (rtb_Add_k - 2.0F) * Controller_ConstB.Divide_k;

      /* Switch: '<S109>/Switch2' incorporates:
       *  RelationalOperator: '<S109>/LowerRelop1'
       */
      if (rtb_Add1_j4 > rtb_Saturation1) {
        rtb_Saturation_bx = rtb_Saturation1;
      }

      Controller_B.Multiply[0] = (1.0F - rtb_Saturation_g) * rtb_Saturation_bx +
        rtb_Saturation_g * Controller_B.Reshape[0];
      Controller_B.Multiply[1] = Controller_B.Reshape[1];
      Controller_B.Multiply[2] = (1.0F - rtb_Saturation_g) *
        Controller_U.FMS_Out.psi_rate_cmd + rtb_Saturation_g *
        Controller_B.Reshape[2];
      break;

     case 3:
      /* Saturate: '<S83>/Saturation3' */
      if (rtb_fw_rate_err_B[0] > 8.0F) {
        rtb_Add_k = 8.0F;
      } else if (rtb_fw_rate_err_B[0] < 2.0F) {
        rtb_Add_k = 2.0F;
      } else {
        rtb_Add_k = rtb_fw_rate_err_B[0];
      }

      /* End of Saturate: '<S83>/Saturation3' */

      /* Product: '<S83>/Multiply' incorporates:
       *  Constant: '<S83>/Constant1'
       *  Sum: '<S83>/Subtract1'
       */
      rtb_Add_k = (rtb_Add_k - 2.0F) * Controller_ConstB.Divide;

      /* Switch: '<S109>/Switch2' incorporates:
       *  RelationalOperator: '<S109>/LowerRelop1'
       */
      if (rtb_Add1_j4 > rtb_Saturation1) {
        rtb_Saturation_bx = rtb_Saturation1;
      }

      Controller_B.Multiply[0] = (1.0F - rtb_Add_k) * rtb_Saturation_bx +
        rtb_Add_k * Controller_B.Reshape[0];

      /* Switch: '<S109>/Switch2' incorporates:
       *  Constant: '<S83>/Constant3'
       *  Product: '<S83>/Multiply1'
       *  Product: '<S83>/Multiply2'
       *  RelationalOperator: '<S109>/LowerRelop1'
       *  Sum: '<S83>/Sum'
       *  Sum: '<S83>/Sum1'
       */
      if (rtb_Saturation2 > rtb_Divide_m_idx_0) {
        rtb_Saturation_g = rtb_Divide_m_idx_0;
      }

      Controller_B.Multiply[1] = (1.0F - rtb_Add_k) * rtb_Saturation_g +
        rtb_Add_k * Controller_B.Reshape[1];
      Controller_B.Multiply[2] = (1.0F - rtb_Add_k) *
        Controller_U.FMS_Out.psi_rate_cmd + rtb_Add_k * Controller_B.Reshape[2];
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
      /* Switch: '<S109>/Switch2' incorporates:
       *  RelationalOperator: '<S109>/LowerRelop1'
       */
      if (rtb_Add1_j4 > rtb_Saturation1) {
        Controller_B.Multiply[0] = rtb_Saturation1;
      } else {
        Controller_B.Multiply[0] = rtb_Saturation_bx;
      }

      if (rtb_Saturation2 > rtb_Divide_m_idx_0) {
        Controller_B.Multiply[1] = rtb_Divide_m_idx_0;
      } else {
        Controller_B.Multiply[1] = rtb_Saturation_g;
      }

      Controller_B.Multiply[2] = Controller_U.FMS_Out.psi_rate_cmd;
      break;
    }

    /* End of MultiPortSwitch: '<S81>/Multiport Switch' */

    /* Trigonometry: '<S84>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Saturation1 = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Trigonometry: '<S84>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Saturation2 = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S84>/Sin' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_m_idx_1 = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Sum: '<S84>/Add2' incorporates:
     *  Product: '<S84>/Multiply4'
     *  Product: '<S84>/Multiply5'
     *  Trigonometry: '<S84>/Cos'
     *  Trigonometry: '<S84>/Cos1'
     *  Trigonometry: '<S84>/Sin'
     */
    rtb_Divide_m_idx_0 = rtb_Saturation2 * rtb_Saturation1 *
      Controller_B.Multiply[2] - rtb_Divide_m_idx_1 * Controller_B.Multiply[1];

    /* Saturate: '<S81>/Saturation' */
    if (rtb_Divide_m_idx_0 > CONTROL_PARAM.MC_R_CMD_LIM) {
      rtb_Divide_m_idx_0 = CONTROL_PARAM.MC_R_CMD_LIM;
    } else {
      if (rtb_Divide_m_idx_0 < -CONTROL_PARAM.MC_R_CMD_LIM) {
        rtb_Divide_m_idx_0 = -CONTROL_PARAM.MC_R_CMD_LIM;
      }
    }

    /* End of Saturate: '<S81>/Saturation' */

    /* Sum: '<S84>/Add' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S84>/Multiply'
     *  Trigonometry: '<S84>/Sin1'
     */
    rtb_Saturation_g = Controller_B.Multiply[0] - arm_sin_f32
      (Controller_U.INS_Out.theta) * Controller_B.Multiply[2];

    /* Saturate: '<S81>/Saturation1' */
    if (rtb_Saturation_g > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_Saturation_g = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_Saturation_g < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_Saturation_g = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    /* End of Saturate: '<S81>/Saturation1' */

    /* Sum: '<S84>/Add1' incorporates:
     *  Product: '<S84>/Multiply1'
     *  Product: '<S84>/Multiply3'
     *  Trigonometry: '<S84>/Cos'
     *  Trigonometry: '<S84>/Cos1'
     *  Trigonometry: '<S84>/Sin'
     */
    rtb_Divide_m_idx_1 = rtb_Divide_m_idx_1 * rtb_Saturation1 *
      Controller_B.Multiply[2] + rtb_Saturation2 * Controller_B.Multiply[1];

    /* Saturate: '<S81>/Saturation2' */
    if (rtb_Divide_m_idx_1 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_Divide_m_idx_1 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_Divide_m_idx_1 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_Divide_m_idx_1 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    /* End of Saturate: '<S81>/Saturation2' */

    /* Sum: '<S93>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Add_k = rtb_Saturation_g - Controller_U.INS_Out.p;

    /* Saturate: '<S93>/Saturation' */
    if (rtb_Add_k > 3.14159274F) {
      rtb_Add_k = 3.14159274F;
    } else {
      if (rtb_Add_k < -3.14159274F) {
        rtb_Add_k = -3.14159274F;
      }
    }

    /* Sum: '<S93>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_m_idx_3 = rtb_Divide_m_idx_1 - Controller_U.INS_Out.q;

    /* Saturate: '<S93>/Saturation' */
    if (rtb_Divide_m_idx_3 > 3.14159274F) {
      rtb_Divide_m_idx_3 = 3.14159274F;
    } else {
      if (rtb_Divide_m_idx_3 < -3.14159274F) {
        rtb_Divide_m_idx_3 = -3.14159274F;
      }
    }

    /* Sum: '<S93>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Saturation1 = rtb_Divide_m_idx_0 - Controller_U.INS_Out.r;

    /* Saturate: '<S93>/Saturation' */
    if (rtb_Saturation1 > 3.14159274F) {
      rtb_Saturation1 = 3.14159274F;
    } else {
      if (rtb_Saturation1 < -3.14159274F) {
        rtb_Saturation1 = -3.14159274F;
      }
    }

    /* DiscreteIntegrator: '<S97>/Discrete-Time Integrator5' incorporates:
     *  Saturate: '<S93>/Saturation'
     */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_c != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0] = rtb_Add_k;
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1] = rtb_Divide_m_idx_3;
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2] = rtb_Saturation1;
    }

    /* DiscreteIntegrator: '<S102>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S97>/Discrete-Time Integrator5'
     *  Inport: '<Root>/FMS_Out'
     */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0];
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1];
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[2] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2];
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevRes != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0];
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1];
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[2] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2];
    }

    /* Gain: '<S102>/Gain' incorporates:
     *  DiscreteIntegrator: '<S102>/Discrete-Time Integrator1'
     *  DiscreteIntegrator: '<S97>/Discrete-Time Integrator5'
     *  Sum: '<S102>/Sum5'
     */
    rtb_TmpSignalConversionAtMultip[0] =
      (Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0] -
       Controller_DW.DiscreteTimeIntegrator1_DSTATE[0]) * 188.49556F;
    rtb_TmpSignalConversionAtMultip[1] =
      (Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1] -
       Controller_DW.DiscreteTimeIntegrator1_DSTATE[1]) * 188.49556F;
    rtb_TmpSignalConversionAtMultip[2] =
      (Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2] -
       Controller_DW.DiscreteTimeIntegrator1_DSTATE[2]) * 188.49556F;

    /* Switch: '<S102>/Switch' incorporates:
     *  Gain: '<S102>/Gain1'
     *  Inport: '<Root>/FMS_Out'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_Multiply_ni[0] = 0.0F;
      rtb_Multiply_ni[1] = 0.0F;
      rtb_Multiply_ni[2] = 0.0F;
    } else {
      rtb_Multiply_ni[0] = rtb_TmpSignalConversionAtMultip[0];
      rtb_Multiply_ni[1] = rtb_TmpSignalConversionAtMultip[1];
      rtb_Multiply_ni[2] = rtb_TmpSignalConversionAtMultip[2];
    }

    /* End of Switch: '<S102>/Switch' */

    /* Product: '<S99>/Multiply' incorporates:
     *  Constant: '<S99>/gain1'
     */
    rtb_Saturation_bx = CONTROL_PARAM.MC_ROLL_RATE_D * rtb_Multiply_ni[0];

    /* Saturate: '<S99>/Saturation' */
    if (rtb_Saturation_bx > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Saturation_bx = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Saturation_bx < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Saturation_bx = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    rtb_Multiply_ni[0] = rtb_Saturation_bx;

    /* Product: '<S99>/Multiply' incorporates:
     *  Constant: '<S99>/gain2'
     */
    rtb_Saturation_bx = CONTROL_PARAM.MC_PITCH_RATE_D * rtb_Multiply_ni[1];

    /* Saturate: '<S99>/Saturation' */
    if (rtb_Saturation_bx > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Saturation_bx = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Saturation_bx < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Saturation_bx = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    rtb_Multiply_ni[1] = rtb_Saturation_bx;

    /* Product: '<S99>/Multiply' incorporates:
     *  Constant: '<S99>/gain3'
     */
    rtb_Saturation_bx = CONTROL_PARAM.MC_YAW_RATE_D * rtb_Multiply_ni[2];

    /* Saturate: '<S99>/Saturation' */
    if (rtb_Saturation_bx > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Saturation_bx = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Saturation_bx < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Saturation_bx = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    /* Sum: '<S95>/Add' incorporates:
     *  Constant: '<S101>/gain1'
     *  Constant: '<S101>/gain2'
     *  Constant: '<S101>/gain3'
     *  DiscreteIntegrator: '<S100>/Discrete-Time Integrator'
     *  DiscreteIntegrator: '<S97>/Discrete-Time Integrator5'
     *  Product: '<S101>/Multiply'
     */
    Controller_B.Multiply[0] = (CONTROL_PARAM.MC_ROLL_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0]) + rtb_Multiply_ni[0];
    Controller_B.Multiply[1] = (CONTROL_PARAM.MC_PITCH_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1]) + rtb_Multiply_ni[1];
    Controller_B.Multiply[2] = (CONTROL_PARAM.MC_YAW_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[2]) + rtb_Saturation_bx;

    /* DeadZone: '<S98>/Dead Zone' */
    if (rtb_Saturation_g > 0.1F) {
      rtb_Saturation_g -= 0.1F;
    } else if (rtb_Saturation_g >= -0.1F) {
      rtb_Saturation_g = 0.0F;
    } else {
      rtb_Saturation_g -= -0.1F;
    }

    /* Sum: '<S82>/Sum' incorporates:
     *  Gain: '<S94>/Gain'
     *  Gain: '<S98>/Gain'
     */
    Controller_B.Multiply[0] += 1.11111116F * rtb_Saturation_g *
      CONTROL_PARAM.MC_ROLL_RATE_FF;

    /* Product: '<S6>/Multiply' incorporates:
     *  DiscreteIntegrator: '<S9>/Discrete-Time Integrator5'
     */
    Controller_B.Multiply[0] *= Controller_DW.DiscreteTimeIntegrator5_DSTATE;

    /* DeadZone: '<S98>/Dead Zone' */
    if (rtb_Divide_m_idx_1 > 0.1F) {
      rtb_Divide_m_idx_1 -= 0.1F;
    } else if (rtb_Divide_m_idx_1 >= -0.1F) {
      rtb_Divide_m_idx_1 = 0.0F;
    } else {
      rtb_Divide_m_idx_1 -= -0.1F;
    }

    /* Sum: '<S82>/Sum' incorporates:
     *  Gain: '<S94>/Gain'
     *  Gain: '<S98>/Gain'
     */
    Controller_B.Multiply[1] += 1.11111116F * rtb_Divide_m_idx_1 *
      CONTROL_PARAM.MC_ROLL_RATE_FF;

    /* Product: '<S6>/Multiply' incorporates:
     *  DiscreteIntegrator: '<S9>/Discrete-Time Integrator5'
     */
    Controller_B.Multiply[1] *= Controller_DW.DiscreteTimeIntegrator5_DSTATE;

    /* DeadZone: '<S98>/Dead Zone' */
    if (rtb_Divide_m_idx_0 > 0.1F) {
      rtb_Divide_m_idx_0 -= 0.1F;
    } else if (rtb_Divide_m_idx_0 >= -0.1F) {
      rtb_Divide_m_idx_0 = 0.0F;
    } else {
      rtb_Divide_m_idx_0 -= -0.1F;
    }

    /* Sum: '<S82>/Sum' incorporates:
     *  Gain: '<S94>/Gain1'
     *  Gain: '<S98>/Gain'
     */
    Controller_B.Multiply[2] += 1.11111116F * rtb_Divide_m_idx_0 *
      CONTROL_PARAM.MC_PITCH_RATE_FF;

    /* Product: '<S6>/Multiply' incorporates:
     *  DiscreteIntegrator: '<S9>/Discrete-Time Integrator5'
     */
    Controller_B.Multiply[2] *= Controller_DW.DiscreteTimeIntegrator5_DSTATE;

    /* Outputs for Enabled SubSystem: '<S75>/Veloxity_Z_Controller' incorporates:
     *  EnablePort: '<S134>/Enable'
     */
    if (Controller_U.FMS_Out.ctrl_mode >= 4) {
      if (!Controller_DW.Veloxity_Z_Controller_MODE) {
        /* InitializeConditions for DiscreteIntegrator: '<S140>/Integrator1' */
        Controller_DW.Integrator1_DSTATE = 0.0F;

        /* InitializeConditions for DiscreteIntegrator: '<S144>/Discrete-Time Integrator' */
        Controller_DW.DiscreteTimeIntegrator_IC_LOADI = 1U;
        Controller_DW.DiscreteTimeIntegrator_PrevRe_f = 0;

        /* InitializeConditions for DiscreteIntegrator: '<S146>/Discrete-Time Integrator1' */
        Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 1U;
        Controller_DW.DiscreteTimeIntegrator1_PrevR_k = 0;

        /* InitializeConditions for DiscreteIntegrator: '<S140>/Integrator' */
        Controller_DW.Integrator_DSTATE = 0.0F;
        Controller_DW.Veloxity_Z_Controller_MODE = true;
      }

      /* Product: '<S136>/Multiply' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S136>/Cos'
       *  Trigonometry: '<S136>/Cos1'
       */
      rtb_Saturation_g = arm_cos_f32(Controller_U.INS_Out.phi) * arm_cos_f32
        (Controller_U.INS_Out.theta);

      /* Saturate: '<S136>/Saturation1' */
      if (rtb_Saturation_g > 1.0F) {
        rtb_VdotPg_sp = 1.0F;
      } else if (rtb_Saturation_g < 0.5F) {
        rtb_VdotPg_sp = 0.5F;
      } else {
        rtb_VdotPg_sp = rtb_Saturation_g;
      }

      /* End of Saturate: '<S136>/Saturation1' */

      /* RelationalOperator: '<S139>/Compare' incorporates:
       *  Constant: '<S139>/Constant'
       */
      rtb_Compare_hi = (Controller_U.FMS_Out.mode >= 4);

      /* Product: '<S137>/Multiply' incorporates:
       *  DataTypeConversion: '<S137>/Data Type Conversion'
       *  DiscreteIntegrator: '<S140>/Integrator1'
       *  Gain: '<S137>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  Sum: '<S137>/Sum1'
       */
      rtb_Saturation_bx = -(Controller_DW.Integrator1_DSTATE -
                            Controller_U.INS_Out.vd) * (real32_T)rtb_Compare_hi;

      /* Switch: '<S144>/Switch' incorporates:
       *  Constant: '<S142>/Constant'
       *  Constant: '<S144>/Constant'
       *  Constant: '<S144>/Constant1'
       *  Delay: '<S75>/Delay'
       *  RelationalOperator: '<S142>/Compare'
       */
      if (Controller_DW.Delay_DSTATE < 3) {
        rtb_Add1_j4 = CONTROL_PARAM.MC_VEL_Z_I_MIN;
      } else {
        rtb_Add1_j4 = 0.0F;
      }

      /* End of Switch: '<S144>/Switch' */

      /* DiscreteIntegrator: '<S144>/Discrete-Time Integrator' */
      if (Controller_DW.DiscreteTimeIntegrator_IC_LOADI != 0) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_l = rtb_Add1_j4;
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

      if ((Controller_U.FMS_Out.reset != 0) ||
          (Controller_DW.DiscreteTimeIntegrator_PrevRe_f != 0)) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_l = rtb_Add1_j4;
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

      /* DiscreteIntegrator: '<S146>/Discrete-Time Integrator1' */
      if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_d != 0) {
        Controller_DW.DiscreteTimeIntegrator1_DSTAT_i = rtb_Saturation_bx;
      }

      if ((Controller_U.FMS_Out.reset != 0) ||
          (Controller_DW.DiscreteTimeIntegrator1_PrevR_k != 0)) {
        Controller_DW.DiscreteTimeIntegrator1_DSTAT_i = rtb_Saturation_bx;
      }

      /* Gain: '<S146>/Gain' incorporates:
       *  DiscreteIntegrator: '<S146>/Discrete-Time Integrator1'
       *  Sum: '<S146>/Sum5'
       */
      rtb_Add2_h = (rtb_Saturation_bx -
                    Controller_DW.DiscreteTimeIntegrator1_DSTAT_i) * 62.831852F;

      /* Switch: '<S146>/Switch' incorporates:
       *  Gain: '<S146>/Gain1'
       */
      if (Controller_U.FMS_Out.reset > 0) {
        rtb_Divide_m_idx_0 = 0.0F;
      } else {
        rtb_Divide_m_idx_0 = rtb_Add2_h;
      }

      /* End of Switch: '<S146>/Switch' */

      /* Product: '<S143>/Multiply' incorporates:
       *  Constant: '<S143>/kd'
       */
      rtb_Saturation2 = CONTROL_PARAM.MC_VEL_Z_D * rtb_Divide_m_idx_0;

      /* Saturate: '<S143>/Saturation' */
      if (rtb_Saturation2 > CONTROL_PARAM.MC_VEL_Z_D_MAX) {
        rtb_Saturation2 = CONTROL_PARAM.MC_VEL_Z_D_MAX;
      } else {
        if (rtb_Saturation2 < CONTROL_PARAM.MC_VEL_Z_D_MIN) {
          rtb_Saturation2 = CONTROL_PARAM.MC_VEL_Z_D_MIN;
        }
      }

      /* End of Saturate: '<S143>/Saturation' */

      /* Gain: '<S136>/Gain' */
      rtb_Saturation_g *= 2.0F;

      /* Saturate: '<S136>/Saturation' */
      if (rtb_Saturation_g > 1.0F) {
        rtb_Saturation_g = 1.0F;
      } else {
        if (rtb_Saturation_g < 0.0F) {
          rtb_Saturation_g = 0.0F;
        }
      }

      /* End of Saturate: '<S136>/Saturation' */

      /* Sum: '<S134>/Sum' incorporates:
       *  Constant: '<S134>/hover_throttle'
       *  Constant: '<S136>/Constant'
       *  Constant: '<S145>/kp'
       *  DiscreteIntegrator: '<S144>/Discrete-Time Integrator'
       *  Product: '<S136>/Divide'
       *  Product: '<S136>/Multiply1'
       *  Product: '<S145>/Multiply'
       *  Sum: '<S138>/Add'
       */
      Controller_B.Saturation = ((CONTROL_PARAM.MC_VEL_Z_P * rtb_Saturation_bx +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_l) + rtb_Saturation2) *
        (1.0F / rtb_VdotPg_sp) * rtb_Saturation_g + CONTROL_PARAM.MC_HOVER_THRO;

      /* Saturate: '<S134>/Saturation' */
      if (Controller_B.Saturation > 0.85F) {
        /* Sum: '<S134>/Sum' */
        Controller_B.Saturation = 0.85F;
      } else {
        if (Controller_B.Saturation < 0.25F) {
          /* Sum: '<S134>/Sum' */
          Controller_B.Saturation = 0.25F;
        }
      }

      /* End of Saturate: '<S134>/Saturation' */

      /* Product: '<S141>/Multiply1' incorporates:
       *  Constant: '<S141>/const1'
       *  DiscreteIntegrator: '<S140>/Integrator'
       */
      rtb_Saturation_g = Controller_DW.Integrator_DSTATE * 0.05F;

      /* Switch: '<S137>/Switch' incorporates:
       *  Inport: '<Root>/INS_Out'
       */
      if (rtb_Compare_hi) {
        rtb_Add1_j4 = Controller_U.FMS_Out.w_cmd;
      } else {
        rtb_Add1_j4 = Controller_U.INS_Out.vd;
      }

      /* End of Switch: '<S137>/Switch' */

      /* Sum: '<S141>/Add' incorporates:
       *  DiscreteIntegrator: '<S140>/Integrator1'
       *  Sum: '<S140>/Subtract'
       */
      rtb_Saturation2 = (Controller_DW.Integrator1_DSTATE - rtb_Add1_j4) +
        rtb_Saturation_g;

      /* Signum: '<S141>/Sign' */
      if (rtb_Saturation2 < 0.0F) {
        rtb_Add1_j4 = -1.0F;
      } else if (rtb_Saturation2 > 0.0F) {
        rtb_Add1_j4 = 1.0F;
      } else {
        rtb_Add1_j4 = rtb_Saturation2;
      }

      /* End of Signum: '<S141>/Sign' */

      /* Sum: '<S141>/Add2' incorporates:
       *  Abs: '<S141>/Abs'
       *  Gain: '<S141>/Gain'
       *  Gain: '<S141>/Gain1'
       *  Product: '<S141>/Multiply2'
       *  Product: '<S141>/Multiply3'
       *  Sqrt: '<S141>/Sqrt'
       *  Sum: '<S141>/Add1'
       *  Sum: '<S141>/Subtract'
       */
      rtb_a = (sqrtf((8.0F * fabsf(rtb_Saturation2) + Controller_ConstB.d) *
                     Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
        rtb_Add1_j4 + rtb_Saturation_g;

      /* Sum: '<S141>/Add4' */
      rtb_Saturation_g += rtb_Saturation2 - rtb_a;

      /* Sum: '<S141>/Add3' */
      rtb_Add1_j4 = rtb_Saturation2 + Controller_ConstB.d;

      /* Sum: '<S141>/Subtract1' */
      rtb_Saturation2 -= Controller_ConstB.d;

      /* Signum: '<S141>/Sign1' */
      if (rtb_Add1_j4 < 0.0F) {
        rtb_Add1_j4 = -1.0F;
      } else {
        if (rtb_Add1_j4 > 0.0F) {
          rtb_Add1_j4 = 1.0F;
        }
      }

      /* End of Signum: '<S141>/Sign1' */

      /* Signum: '<S141>/Sign2' */
      if (rtb_Saturation2 < 0.0F) {
        rtb_Saturation2 = -1.0F;
      } else {
        if (rtb_Saturation2 > 0.0F) {
          rtb_Saturation2 = 1.0F;
        }
      }

      /* End of Signum: '<S141>/Sign2' */

      /* Sum: '<S141>/Add5' incorporates:
       *  Gain: '<S141>/Gain2'
       *  Product: '<S141>/Multiply4'
       *  Sum: '<S141>/Subtract2'
       */
      rtb_a += (rtb_Add1_j4 - rtb_Saturation2) * 0.5F * rtb_Saturation_g;

      /* Update for DiscreteIntegrator: '<S140>/Integrator1' incorporates:
       *  DiscreteIntegrator: '<S140>/Integrator'
       */
      Controller_DW.Integrator1_DSTATE += 0.002F *
        Controller_DW.Integrator_DSTATE;

      /* Update for DiscreteIntegrator: '<S144>/Discrete-Time Integrator' incorporates:
       *  Constant: '<S144>/ki'
       *  Inport: '<Root>/FMS_Out'
       *  Product: '<S144>/Multiply'
       */
      Controller_DW.DiscreteTimeIntegrator_IC_LOADI = 0U;
      Controller_DW.DiscreteTimeIntegrator_DSTATE_l += CONTROL_PARAM.MC_VEL_Z_I *
        rtb_Saturation_bx * 0.002F;
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

      /* End of Update for DiscreteIntegrator: '<S144>/Discrete-Time Integrator' */

      /* Update for DiscreteIntegrator: '<S146>/Discrete-Time Integrator1' incorporates:
       *  Inport: '<Root>/FMS_Out'
       */
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 0U;
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i += 0.002F * rtb_Add2_h;
      Controller_DW.DiscreteTimeIntegrator1_PrevR_k = (int8_T)
        (Controller_U.FMS_Out.reset > 0);

      /* Signum: '<S141>/Sign6' incorporates:
       *  Signum: '<S141>/Sign5'
       */
      if (rtb_a < 0.0F) {
        rtb_VdotPg_sp = -1.0F;

        /* Signum: '<S141>/Sign5' */
        rtb_Saturation_g = -1.0F;
      } else if (rtb_a > 0.0F) {
        rtb_VdotPg_sp = 1.0F;

        /* Signum: '<S141>/Sign5' */
        rtb_Saturation_g = 1.0F;
      } else {
        rtb_VdotPg_sp = rtb_a;

        /* Signum: '<S141>/Sign5' */
        rtb_Saturation_g = rtb_a;
      }

      /* End of Signum: '<S141>/Sign6' */

      /* Sum: '<S141>/Add6' */
      rtb_Add1_j4 = rtb_a + Controller_ConstB.d;

      /* Sum: '<S141>/Subtract3' */
      rtb_Add2_h = rtb_a - Controller_ConstB.d;

      /* Signum: '<S141>/Sign3' */
      if (rtb_Add1_j4 < 0.0F) {
        rtb_Add1_j4 = -1.0F;
      } else {
        if (rtb_Add1_j4 > 0.0F) {
          rtb_Add1_j4 = 1.0F;
        }
      }

      /* End of Signum: '<S141>/Sign3' */

      /* Signum: '<S141>/Sign4' */
      if (rtb_Add2_h < 0.0F) {
        rtb_Add2_h = -1.0F;
      } else {
        if (rtb_Add2_h > 0.0F) {
          rtb_Add2_h = 1.0F;
        }
      }

      /* End of Signum: '<S141>/Sign4' */

      /* Update for DiscreteIntegrator: '<S140>/Integrator' incorporates:
       *  Constant: '<S141>/const'
       *  Gain: '<S141>/Gain3'
       *  Product: '<S141>/Divide'
       *  Product: '<S141>/Multiply5'
       *  Product: '<S141>/Multiply6'
       *  Sum: '<S141>/Subtract4'
       *  Sum: '<S141>/Subtract5'
       *  Sum: '<S141>/Subtract6'
       */
      Controller_DW.Integrator_DSTATE += ((rtb_a / Controller_ConstB.d -
        rtb_Saturation_g) * Controller_ConstB.Gain4 * ((rtb_Add1_j4 - rtb_Add2_h)
        * 0.5F) - rtb_VdotPg_sp * 78.448F) * 0.002F;
    } else {
      if (Controller_DW.Veloxity_Z_Controller_MODE) {
        Controller_DW.Veloxity_Z_Controller_MODE = false;
      }
    }

    /* End of Outputs for SubSystem: '<S75>/Veloxity_Z_Controller' */

    /* Product: '<S6>/Multiply1' incorporates:
     *  Constant: '<S132>/Constant'
     *  Constant: '<S133>/Constant'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S132>/Compare'
     */
    Controller_B.Multiply1[0] = 0.0F;
    Controller_B.Multiply1[1] = 0.0F;

    /* Switch: '<S133>/Switch' incorporates:
     *  Bias: '<S133>/Bias'
     *  Constant: '<S135>/Constant'
     *  Gain: '<S133>/Gain'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S135>/Compare'
     */
    if (Controller_U.FMS_Out.ctrl_mode <= 3) {
      rtb_Divide_m_idx_0 = 0.000999987125F * (real32_T)
        Controller_U.FMS_Out.throttle_cmd + -1.0F;
    } else {
      rtb_Divide_m_idx_0 = Controller_B.Saturation;
    }

    /* End of Switch: '<S133>/Switch' */

    /* Product: '<S6>/Multiply1' incorporates:
     *  DiscreteIntegrator: '<S9>/Discrete-Time Integrator5'
     */
    Controller_B.Multiply1[2] = Controller_DW.DiscreteTimeIntegrator5_DSTATE *
      rtb_Divide_m_idx_0;

    /* Update for DiscreteIntegrator: '<S100>/Discrete-Time Integrator' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S97>/Discrete-Time Integrator5' */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_c = 0U;

    /* Update for DiscreteIntegrator: '<S102>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;

    /* Update for DiscreteIntegrator: '<S100>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S100>/gain1'
     *  DiscreteIntegrator: '<S97>/Discrete-Time Integrator5'
     *  Product: '<S100>/Multiply'
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

    /* Update for DiscreteIntegrator: '<S97>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S97>/Gain'
     *  Saturate: '<S93>/Saturation'
     *  Sum: '<S97>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0] += (rtb_Add_k -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S102>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] += 0.002F *
      rtb_TmpSignalConversionAtMultip[0];

    /* Update for DiscreteIntegrator: '<S100>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S100>/gain2'
     *  DiscreteIntegrator: '<S97>/Discrete-Time Integrator5'
     *  Product: '<S100>/Multiply'
     */
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

    /* Update for DiscreteIntegrator: '<S97>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S97>/Gain'
     *  Saturate: '<S93>/Saturation'
     *  Sum: '<S97>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1] += (rtb_Divide_m_idx_3 -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S102>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] += 0.002F *
      rtb_TmpSignalConversionAtMultip[1];

    /* Update for DiscreteIntegrator: '<S100>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S100>/gain3'
     *  DiscreteIntegrator: '<S97>/Discrete-Time Integrator5'
     *  Product: '<S100>/Multiply'
     */
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

    /* Update for DiscreteIntegrator: '<S97>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S97>/Gain'
     *  Saturate: '<S93>/Saturation'
     *  Sum: '<S97>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2] += (rtb_Saturation1 -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S102>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[2] += 0.002F *
      rtb_TmpSignalConversionAtMultip[2];
    Controller_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for Delay: '<S75>/Delay' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.Delay_DSTATE = Controller_U.FMS_Out.status;
  } else {
    if (Controller_DW.MC_Controller_MODE) {
      /* Disable for Enabled SubSystem: '<S74>/Velocity_Controller' */
      if (Controller_DW.Velocity_Controller_MODE) {
        Controller_DW.Velocity_Controller_MODE = false;
      }

      /* End of Disable for SubSystem: '<S74>/Velocity_Controller' */

      /* Disable for Enabled SubSystem: '<S75>/Veloxity_Z_Controller' */
      if (Controller_DW.Veloxity_Z_Controller_MODE) {
        Controller_DW.Veloxity_Z_Controller_MODE = false;
      }

      /* End of Disable for SubSystem: '<S75>/Veloxity_Z_Controller' */
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

  /* Output and update for atomic system: '<S148>/VTOL1' */
  {
    real32_T rtb_Divide1;
    real32_T rtb_Saturation_ff;
    real32_T rtb_Saturation1_m;
    real32_T rtb_MatrixConcatenate[12];
    real32_T rtb_Saturation5_o[4];
    real32_T rtb_floating_yaw[4];
    real32_T rtb_Saturation_f[9];
    real32_T rtb_Sum_e[4];
    real32_T rtb_Gain1_lx;
    int32_T i_p;
    real32_T rtb_Saturation1_l_idx_0_p;
    real32_T rtb_Saturation1_l_idx_1_p;
    real32_T rtb_Saturation1_l_idx_2_p;
    uint16_T u0_p;
    real32_T u0_tmp_p;

    /* Saturate: '<S159>/Saturation' incorporates:
     *  Bias: '<S159>/Bias'
     *  Bias: '<S159>/Bias1'
     *  Bias: '<S159>/Bias2'
     *  Bias: '<S159>/Bias3'
     *  Constant: '<S159>/Constant'
     */
    for (i_p = 0; i_p < 5; i_p++) {
      rtb_Saturation_f[i_p] = 1000.0F;
    }

    if (1500.0F + CONTROL_PARAM.SERVO1_BIAS > 2000.0F) {
      rtb_Saturation_f[5] = 2000.0F;
    } else if (1500.0F + CONTROL_PARAM.SERVO1_BIAS < 1000.0F) {
      rtb_Saturation_f[5] = 1000.0F;
    } else {
      rtb_Saturation_f[5] = 1500.0F + CONTROL_PARAM.SERVO1_BIAS;
    }

    if (1500.0F + CONTROL_PARAM.SERVO2_BIAS > 2000.0F) {
      rtb_Saturation_f[6] = 2000.0F;
    } else if (1500.0F + CONTROL_PARAM.SERVO2_BIAS < 1000.0F) {
      rtb_Saturation_f[6] = 1000.0F;
    } else {
      rtb_Saturation_f[6] = 1500.0F + CONTROL_PARAM.SERVO2_BIAS;
    }

    if (1500.0F + CONTROL_PARAM.SERVO3_BIAS > 2000.0F) {
      rtb_Saturation_f[7] = 2000.0F;
    } else if (1500.0F + CONTROL_PARAM.SERVO3_BIAS < 1000.0F) {
      rtb_Saturation_f[7] = 1000.0F;
    } else {
      rtb_Saturation_f[7] = 1500.0F + CONTROL_PARAM.SERVO3_BIAS;
    }

    if (1500.0F + CONTROL_PARAM.SERVO4_BIAS > 2000.0F) {
      rtb_Saturation_f[8] = 2000.0F;
    } else if (1500.0F + CONTROL_PARAM.SERVO4_BIAS < 1000.0F) {
      rtb_Saturation_f[8] = 1000.0F;
    } else {
      rtb_Saturation_f[8] = 1500.0F + CONTROL_PARAM.SERVO4_BIAS;
    }

    /* End of Saturate: '<S159>/Saturation' */

    /* Saturate: '<S152>/Saturation1' */
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

    /* End of Saturate: '<S152>/Saturation1' */

    /* Saturate: '<S152>/Saturation2' */
    if (rtb_Multiply3[2] > 1.0F) {
      rtb_Divide1 = 1.0F;
    } else if (rtb_Multiply3[2] < 0.0F) {
      rtb_Divide1 = 0.0F;
    } else {
      rtb_Divide1 = rtb_Multiply3[2];
    }

    /* End of Saturate: '<S152>/Saturation2' */

    /* Gain: '<S152>/Gain1' incorporates:
     *  Bias: '<S152>/Bias'
     *  Constant: '<S152>/Constant'
     */
    rtb_Gain1_lx = ((real32_T)CONTROL_PARAM.MC_OUT_MAX + -1000.0F) * 0.001F;
    for (i_p = 0; i_p < 4; i_p++) {
      /* Product: '<S152>/Multiply' */
      rtb_Saturation1_m = Controller_ConstB.VTOL1.pq_column[i_p + 4] *
        rtb_Saturation1_l_idx_1_p + Controller_ConstB.VTOL1.pq_column[i_p] *
        rtb_Saturation1_l_idx_0_p;

      /* Sum: '<S152>/Sum' */
      rtb_Sum_e[i_p] = rtb_Saturation1_m + rtb_Divide1;

      /* Product: '<S152>/Multiply' */
      rtb_floating_yaw[i_p] = rtb_Saturation1_m;
    }

    /* Gain: '<S152>/Gain2' incorporates:
     *  Bias: '<S152>/Bias1'
     *  Constant: '<S152>/Constant1'
     */
    rtb_Saturation1_l_idx_0_p = ((real32_T)CONTROL_PARAM.MC_OUT_MIN + -1000.0F) *
      0.001F;

    /* MinMax: '<S152>/Max' */
    rtb_Saturation1_l_idx_1_p = fmaxf(fmaxf(fmaxf(rtb_Sum_e[0], rtb_Sum_e[1]),
      rtb_Sum_e[2]), rtb_Sum_e[3]);

    /* MinMax: '<S152>/Max1' */
    rtb_Saturation1_m = fminf(fminf(fminf(rtb_Sum_e[0], rtb_Sum_e[1]),
      rtb_Sum_e[2]), rtb_Sum_e[3]);

    /* Switch: '<S157>/Switch' incorporates:
     *  Constant: '<S157>/Constant2'
     *  Logic: '<S157>/Logical Operator'
     *  MinMax: '<S152>/Max'
     *  MinMax: '<S152>/Max1'
     *  RelationalOperator: '<S157>/Relational Operator'
     *  RelationalOperator: '<S157>/Relational Operator1'
     */
    if ((rtb_Saturation1_l_idx_1_p > rtb_Gain1_lx) || (rtb_Saturation1_m <
         rtb_Saturation1_l_idx_0_p)) {
      /* Switch: '<S157>/Switch1' incorporates:
       *  Gain: '<S157>/Gain'
       *  RelationalOperator: '<S157>/Relational Operator2'
       *  RelationalOperator: '<S157>/Relational Operator3'
       *  Sum: '<S157>/Add'
       *  Sum: '<S157>/Subtract'
       *  Sum: '<S157>/Subtract1'
       *  Sum: '<S157>/Subtract2'
       *  Sum: '<S157>/Subtract3'
       *  Switch: '<S157>/Switch2'
       */
      if (rtb_Saturation1_l_idx_1_p - rtb_Saturation1_m > rtb_Gain1_lx -
          rtb_Saturation1_l_idx_0_p) {
        rtb_Saturation_ff = ((rtb_Gain1_lx - rtb_Saturation1_l_idx_1_p) +
                             (rtb_Saturation1_l_idx_0_p - rtb_Saturation1_m)) *
          0.5F;
      } else if (rtb_Saturation1_l_idx_1_p > rtb_Gain1_lx) {
        /* Switch: '<S157>/Switch2' incorporates:
         *  Sum: '<S157>/Subtract4'
         */
        rtb_Saturation_ff = rtb_Gain1_lx - rtb_Saturation1_l_idx_1_p;
      } else {
        /* Switch: '<S157>/Switch2' incorporates:
         *  Sum: '<S157>/Subtract5'
         */
        rtb_Saturation_ff = rtb_Saturation1_l_idx_0_p - rtb_Saturation1_m;
      }

      /* End of Switch: '<S157>/Switch1' */
    } else {
      rtb_Saturation_ff = 0.0F;
    }

    /* End of Switch: '<S157>/Switch' */

    /* Saturate: '<S157>/Saturation' */
    if (rtb_Saturation_ff > 0.2F) {
      rtb_Saturation_ff = 0.2F;
    } else {
      if (rtb_Saturation_ff < -0.2F) {
        rtb_Saturation_ff = -0.2F;
      }
    }

    /* End of Saturate: '<S157>/Saturation' */

    /* Sum: '<S152>/Sum1' incorporates:
     *  Sum: '<S157>/Add3'
     */
    u0_tmp_p = rtb_Saturation_ff + rtb_Divide1;

    /* Saturate: '<S152>/Saturation3' incorporates:
     *  Sum: '<S152>/Sum1'
     */
    if (u0_tmp_p > 1.0F) {
      rtb_Divide1 = 1.0F;
    } else if (u0_tmp_p < 0.0F) {
      rtb_Divide1 = 0.0F;
    } else {
      rtb_Divide1 = u0_tmp_p;
    }

    /* End of Saturate: '<S152>/Saturation3' */

    /* MinMax: '<S157>/Min' incorporates:
     *  MinMax: '<S152>/Max'
     *  MinMax: '<S152>/Max1'
     *  Product: '<S157>/Divide'
     *  Product: '<S157>/Divide1'
     *  Sum: '<S157>/Add1'
     *  Sum: '<S157>/Add2'
     *  Sum: '<S157>/Subtract6'
     *  Sum: '<S157>/Subtract7'
     *  Sum: '<S157>/Subtract8'
     *  Sum: '<S157>/Subtract9'
     */
    rtb_Saturation1_m = fminf((rtb_Gain1_lx - u0_tmp_p) /
      ((rtb_Saturation1_l_idx_1_p + rtb_Saturation_ff) - u0_tmp_p), 1.0F /
      (u0_tmp_p - (rtb_Saturation1_m + rtb_Saturation_ff)) * (u0_tmp_p -
      rtb_Saturation1_l_idx_0_p));

    /* Saturate: '<S157>/Saturation1' */
    if (rtb_Saturation1_m > 1.0F) {
      rtb_Saturation1_m = 1.0F;
    } else {
      if (rtb_Saturation1_m < 0.5F) {
        rtb_Saturation1_m = 0.5F;
      }
    }

    /* End of Saturate: '<S157>/Saturation1' */

    /* Saturate: '<S152>/Saturation4' incorporates:
     *  Product: '<S152>/Multiply1'
     *  Sum: '<S152>/Sum2'
     */
    rtb_Saturation1_l_idx_1_p = rtb_floating_yaw[0] * rtb_Saturation1_m +
      rtb_Divide1;
    if (rtb_Saturation1_l_idx_1_p > 1.0F) {
      rtb_Saturation1_l_idx_1_p = 1.0F;
    } else {
      if (rtb_Saturation1_l_idx_1_p < 0.0F) {
        rtb_Saturation1_l_idx_1_p = 0.0F;
      }
    }

    /* Sum: '<S152>/Sum3' incorporates:
     *  Product: '<S152>/Multiply2'
     */
    rtb_Sum_e[0] = Controller_ConstB.VTOL1.r_column[0] *
      rtb_Saturation1_l_idx_2_p + rtb_Saturation1_l_idx_1_p;

    /* Saturate: '<S152>/Saturation4' incorporates:
     *  Product: '<S152>/Multiply1'
     *  Sum: '<S152>/Sum2'
     */
    rtb_floating_yaw[0] = rtb_Saturation1_l_idx_1_p;
    rtb_Saturation1_l_idx_1_p = rtb_floating_yaw[1] * rtb_Saturation1_m +
      rtb_Divide1;
    if (rtb_Saturation1_l_idx_1_p > 1.0F) {
      rtb_Saturation1_l_idx_1_p = 1.0F;
    } else {
      if (rtb_Saturation1_l_idx_1_p < 0.0F) {
        rtb_Saturation1_l_idx_1_p = 0.0F;
      }
    }

    /* Sum: '<S152>/Sum3' incorporates:
     *  Product: '<S152>/Multiply2'
     */
    rtb_Sum_e[1] = Controller_ConstB.VTOL1.r_column[1] *
      rtb_Saturation1_l_idx_2_p + rtb_Saturation1_l_idx_1_p;

    /* Saturate: '<S152>/Saturation4' incorporates:
     *  Product: '<S152>/Multiply1'
     *  Sum: '<S152>/Sum2'
     */
    rtb_floating_yaw[1] = rtb_Saturation1_l_idx_1_p;
    rtb_Saturation1_l_idx_1_p = rtb_floating_yaw[2] * rtb_Saturation1_m +
      rtb_Divide1;
    if (rtb_Saturation1_l_idx_1_p > 1.0F) {
      rtb_Saturation1_l_idx_1_p = 1.0F;
    } else {
      if (rtb_Saturation1_l_idx_1_p < 0.0F) {
        rtb_Saturation1_l_idx_1_p = 0.0F;
      }
    }

    /* Sum: '<S152>/Sum3' incorporates:
     *  Product: '<S152>/Multiply2'
     */
    rtb_Sum_e[2] = Controller_ConstB.VTOL1.r_column[2] *
      rtb_Saturation1_l_idx_2_p + rtb_Saturation1_l_idx_1_p;

    /* Saturate: '<S152>/Saturation4' incorporates:
     *  Product: '<S152>/Multiply1'
     *  Sum: '<S152>/Sum2'
     */
    rtb_floating_yaw[2] = rtb_Saturation1_l_idx_1_p;
    rtb_Saturation1_l_idx_1_p = rtb_floating_yaw[3] * rtb_Saturation1_m +
      rtb_Divide1;
    if (rtb_Saturation1_l_idx_1_p > 1.0F) {
      rtb_Saturation1_l_idx_1_p = 1.0F;
    } else {
      if (rtb_Saturation1_l_idx_1_p < 0.0F) {
        rtb_Saturation1_l_idx_1_p = 0.0F;
      }
    }

    /* Sum: '<S152>/Sum3' incorporates:
     *  Product: '<S152>/Multiply2'
     */
    rtb_Sum_e[3] = Controller_ConstB.VTOL1.r_column[3] *
      rtb_Saturation1_l_idx_2_p + rtb_Saturation1_l_idx_1_p;

    /* Saturate: '<S152>/Saturation4' incorporates:
     *  Product: '<S152>/Multiply1'
     */
    rtb_floating_yaw[3] = rtb_Saturation1_l_idx_1_p;

    /* MATLAB Function: '<S152>/R_Remix' */
    Controller_R_Remix(rtb_Sum_e, rtb_Gain1_lx, rtb_Saturation1_l_idx_0_p,
                       rtb_floating_yaw);

    /* MultiPortSwitch: '<S153>/Multiport Switch' incorporates:
     *  Constant: '<S154>/Constant1'
     *  Constant: '<S154>/Constant12'
     *  Constant: '<S154>/Constant2'
     *  Constant: '<S154>/Constant7'
     *  DataTypeConversion: '<S159>/Data Type Conversion'
     *  DataTypeConversion: '<S160>/Data Type Conversion'
     *  Inport: '<Root>/FMS_Out'
     */
    switch (Controller_U.FMS_Out.status) {
     case 1:
      for (i_p = 0; i_p < 9; i_p++) {
        rtb_VariantMergeForOutportactua[i_p] = (uint16_T)fmodf(floorf
          (rtb_Saturation_f[i_p]), 65536.0F);
      }
      break;

     case 2:
      for (i_p = 0; i_p < 5; i_p++) {
        /* Saturate: '<S160>/Saturation' incorporates:
         *  Constant: '<S160>/Standby'
         *  Reshape: '<S160>/Reshape'
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

      /* Saturate: '<S160>/Saturation' incorporates:
       *  Bias: '<S160>/Bias'
       *  Constant: '<S160>/Constant'
       *  DataTypeConversion: '<S160>/Data Type Conversion'
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

      /* Saturate: '<S160>/Saturation' incorporates:
       *  Bias: '<S160>/Bias1'
       *  Constant: '<S160>/Constant'
       *  DataTypeConversion: '<S160>/Data Type Conversion'
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

      /* Saturate: '<S160>/Saturation' incorporates:
       *  Bias: '<S160>/Bias2'
       *  Constant: '<S160>/Constant'
       *  DataTypeConversion: '<S160>/Data Type Conversion'
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

      /* Saturate: '<S160>/Saturation' incorporates:
       *  Bias: '<S160>/Bias3'
       *  Constant: '<S160>/Constant'
       *  DataTypeConversion: '<S160>/Data Type Conversion'
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

      /* SignalConversion: '<S154>/ConcatBufferAtVector Concatenate2In3' incorporates:
       *  Constant: '<S154>/Constant11'
       *  Constant: '<S154>/Constant12'
       */
      rtb_MatrixConcatenate[10] = 0.0F;

      /* SignalConversion: '<S154>/ConcatBufferAtVector Concatenate2In2' incorporates:
       *  Constant: '<S154>/Constant10'
       */
      rtb_MatrixConcatenate[9] = 0.0F;

      /* SignalConversion: '<S154>/ConcatBufferAtVector Concatenate2In1' incorporates:
       *  Constant: '<S154>/Constant9'
       */
      rtb_MatrixConcatenate[8] = 0.0F;

      /* SignalConversion: '<S154>/ConcatBufferAtVector Concatenate1In4' incorporates:
       *  Constant: '<S154>/Constant8'
       */
      rtb_MatrixConcatenate[7] = 0.0F;
      rtb_MatrixConcatenate[6] = CONTROL_PARAM.FW_PITCH_EFFC *
        CONTROL_PARAM.FW_ELEVATOR_DIR;

      /* SignalConversion: '<S154>/ConcatBufferAtVector Concatenate1In2' incorporates:
       *  Constant: '<S154>/Constant6'
       *  Constant: '<S154>/Constant7'
       */
      rtb_MatrixConcatenate[5] = 0.0F;

      /* SignalConversion: '<S154>/ConcatBufferAtVector Concatenate1In1' incorporates:
       *  Constant: '<S154>/Constant5'
       */
      rtb_MatrixConcatenate[4] = 0.0F;

      /* SignalConversion: '<S154>/ConcatBufferAtVector ConcatenateIn4' incorporates:
       *  Constant: '<S154>/Constant4'
       */
      rtb_MatrixConcatenate[3] = 0.0F;

      /* SignalConversion: '<S154>/ConcatBufferAtVector ConcatenateIn3' incorporates:
       *  Constant: '<S154>/Constant3'
       */
      rtb_MatrixConcatenate[2] = 0.0F;
      rtb_MatrixConcatenate[1] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON2_DIR;
      rtb_MatrixConcatenate[0] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON1_DIR;

      /* Saturate: '<S151>/Saturation5' incorporates:
       *  Constant: '<S154>/Constant1'
       *  Constant: '<S154>/Constant2'
       */
      if (rtb_Multiply[0] > 1.0F) {
        rtb_Saturation1_l_idx_2_p = 1.0F;
      } else if (rtb_Multiply[0] < -1.0F) {
        rtb_Saturation1_l_idx_2_p = -1.0F;
      } else {
        rtb_Saturation1_l_idx_2_p = rtb_Multiply[0];
      }

      if (rtb_Multiply[1] > 1.0F) {
        rtb_Gain1_lx = 1.0F;
      } else if (rtb_Multiply[1] < -1.0F) {
        rtb_Gain1_lx = -1.0F;
      } else {
        rtb_Gain1_lx = rtb_Multiply[1];
      }

      if (rtb_Multiply[2] > 1.0F) {
        rtb_Saturation1_l_idx_0_p = 1.0F;
      } else if (rtb_Multiply[2] < -1.0F) {
        rtb_Saturation1_l_idx_0_p = -1.0F;
      } else {
        rtb_Saturation1_l_idx_0_p = rtb_Multiply[2];
      }

      /* End of Saturate: '<S151>/Saturation5' */
      for (i_p = 0; i_p < 4; i_p++) {
        /* Bias: '<S151>/Bias' incorporates:
         *  Gain: '<S151>/Gain1'
         *  Product: '<S151>/Multiply1'
         */
        rtb_Saturation5_o[i_p] = 500.0F * (rtb_MatrixConcatenate[i_p + 8] *
          rtb_Saturation1_l_idx_0_p + (rtb_MatrixConcatenate[i_p + 4] *
          rtb_Gain1_lx + rtb_MatrixConcatenate[i_p] * rtb_Saturation1_l_idx_2_p))
          + 1500.0F;

        /* Sum: '<S152>/Sum4' */
        rtb_Saturation1_l_idx_1_p = rtb_Sum_e[i_p] + rtb_floating_yaw[i_p];

        /* Saturate: '<S152>/Saturation5' */
        if (rtb_Saturation1_l_idx_1_p > 1.0F) {
          rtb_Saturation1_l_idx_1_p = 1.0F;
        } else {
          if (rtb_Saturation1_l_idx_1_p < 0.0F) {
            rtb_Saturation1_l_idx_1_p = 0.0F;
          }
        }

        /* End of Saturate: '<S152>/Saturation5' */

        /* DataTypeConversion: '<S152>/Data Type Conversion' incorporates:
         *  Constant: '<S152>/Constant2'
         *  Gain: '<S152>/Gain3'
         *  Sum: '<S152>/Sum5'
         */
        u0_p = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          rtb_Saturation1_l_idx_1_p), 4.2949673E+9F) + 1000U);

        /* Saturate: '<S152>/Saturation' */
        if (u0_p > CONTROL_PARAM.MC_OUT_MAX) {
          rtb_VariantMergeForOutportactua[i_p] = CONTROL_PARAM.MC_OUT_MAX;
        } else if (u0_p < CONTROL_PARAM.MC_OUT_MIN) {
          rtb_VariantMergeForOutportactua[i_p] = CONTROL_PARAM.MC_OUT_MIN;
        } else {
          rtb_VariantMergeForOutportactua[i_p] = u0_p;
        }

        /* End of Saturate: '<S152>/Saturation' */
      }

      /* Saturate: '<S151>/Saturation' */
      if (rtb_Multiply1[0] > 1.0F) {
        rtb_Saturation1_l_idx_2_p = 1.0F;
      } else if (rtb_Multiply1[0] < 0.0F) {
        rtb_Saturation1_l_idx_2_p = 0.0F;
      } else {
        rtb_Saturation1_l_idx_2_p = rtb_Multiply1[0];
      }

      /* End of Saturate: '<S151>/Saturation' */

      /* DataTypeConversion: '<S156>/Data Type Conversion' incorporates:
       *  Constant: '<S156>/Constant1'
       *  Gain: '<S156>/Gain1'
       *  Sum: '<S156>/Sum1'
       */
      u0_p = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
        rtb_Saturation1_l_idx_2_p), 4.2949673E+9F) + 1000U);

      /* Saturate: '<S151>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[4] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[4] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[4] = u0_p;
      }

      /* DataTypeConversion: '<S151>/Data Type Conversion' incorporates:
       *  Bias: '<S151>/Bias1'
       */
      rtb_Saturation1_l_idx_2_p = fmodf(floorf(rtb_Saturation5_o[0] +
        CONTROL_PARAM.SERVO1_BIAS), 65536.0F);
      u0_p = (uint16_T)(rtb_Saturation1_l_idx_2_p < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_l_idx_2_p :
                        (int32_T)(uint16_T)rtb_Saturation1_l_idx_2_p);

      /* Saturate: '<S151>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[5] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[5] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[5] = u0_p;
      }

      /* DataTypeConversion: '<S151>/Data Type Conversion1' incorporates:
       *  Bias: '<S151>/Bias2'
       */
      rtb_Saturation1_l_idx_2_p = fmodf(floorf(rtb_Saturation5_o[1] +
        CONTROL_PARAM.SERVO2_BIAS), 65536.0F);
      u0_p = (uint16_T)(rtb_Saturation1_l_idx_2_p < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_l_idx_2_p :
                        (int32_T)(uint16_T)rtb_Saturation1_l_idx_2_p);

      /* Saturate: '<S151>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[6] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[6] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[6] = u0_p;
      }

      /* DataTypeConversion: '<S151>/Data Type Conversion2' incorporates:
       *  Bias: '<S151>/Bias3'
       */
      rtb_Saturation1_l_idx_2_p = fmodf(floorf(rtb_Saturation5_o[2] +
        CONTROL_PARAM.SERVO3_BIAS), 65536.0F);
      u0_p = (uint16_T)(rtb_Saturation1_l_idx_2_p < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_l_idx_2_p :
                        (int32_T)(uint16_T)rtb_Saturation1_l_idx_2_p);

      /* Saturate: '<S151>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[7] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[7] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[7] = u0_p;
      }

      /* DataTypeConversion: '<S151>/Data Type Conversion3' incorporates:
       *  Bias: '<S151>/Bias4'
       */
      rtb_Saturation1_l_idx_2_p = fmodf(floorf(rtb_Saturation5_o[3] +
        CONTROL_PARAM.SERVO4_BIAS), 65536.0F);
      u0_p = (uint16_T)(rtb_Saturation1_l_idx_2_p < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_l_idx_2_p :
                        (int32_T)(uint16_T)rtb_Saturation1_l_idx_2_p);

      /* Saturate: '<S151>/Saturation1' */
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
          (rtb_Saturation_f[i_p]), 65536.0F);
      }
      break;
    }

    /* End of MultiPortSwitch: '<S153>/Multiport Switch' */
  }

#elif AIRFRAME == 2

  /* Output and update for atomic system: '<S148>/VTOL2' */
  {
    real32_T rtb_Divide1_o;
    real32_T rtb_Saturation_ho;
    real32_T rtb_Saturation1_i;
    real32_T rtb_MatrixConcatenate_g[12];
    real32_T rtb_Saturation5_m[4];
    real32_T rtb_floating_yaw_n[4];
    real32_T rtb_Saturation_k[9];
    real32_T rtb_Sum_m[4];
    real32_T rtb_Gain1_lm;
    int32_T i_o;
    real32_T rtb_Saturation1_p_idx_0_o;
    real32_T rtb_Saturation1_p_idx_1_o;
    real32_T rtb_Saturation1_p_idx_2_o;
    uint16_T u0_o;
    real32_T u0_tmp_o;

    /* Saturate: '<S170>/Saturation' incorporates:
     *  Bias: '<S170>/Bias'
     *  Bias: '<S170>/Bias1'
     *  Bias: '<S170>/Bias2'
     *  Bias: '<S170>/Bias3'
     *  Constant: '<S170>/Constant'
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

    /* End of Saturate: '<S170>/Saturation' */

    /* Saturate: '<S162>/Saturation1' */
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

    /* End of Saturate: '<S162>/Saturation1' */

    /* Saturate: '<S162>/Saturation2' */
    if (rtb_Multiply3[2] > 1.0F) {
      rtb_Divide1_o = 1.0F;
    } else if (rtb_Multiply3[2] < 0.0F) {
      rtb_Divide1_o = 0.0F;
    } else {
      rtb_Divide1_o = rtb_Multiply3[2];
    }

    /* End of Saturate: '<S162>/Saturation2' */

    /* Gain: '<S162>/Gain1' incorporates:
     *  Bias: '<S162>/Bias'
     *  Constant: '<S162>/Constant'
     */
    rtb_Gain1_lm = ((real32_T)CONTROL_PARAM.MC_OUT_MAX + -1000.0F) * 0.001F;
    for (i_o = 0; i_o < 4; i_o++) {
      /* Product: '<S162>/Multiply' */
      rtb_Saturation1_i = Controller_ConstB.VTOL2.pq_column[i_o + 4] *
        rtb_Saturation1_p_idx_1_o + Controller_ConstB.VTOL2.pq_column[i_o] *
        rtb_Saturation1_p_idx_0_o;

      /* Sum: '<S162>/Sum' */
      rtb_Sum_m[i_o] = rtb_Saturation1_i + rtb_Divide1_o;

      /* Product: '<S162>/Multiply' */
      rtb_floating_yaw_n[i_o] = rtb_Saturation1_i;
    }

    /* Gain: '<S162>/Gain2' incorporates:
     *  Bias: '<S162>/Bias1'
     *  Constant: '<S162>/Constant1'
     */
    rtb_Saturation1_p_idx_0_o = ((real32_T)CONTROL_PARAM.MC_OUT_MIN + -1000.0F) *
      0.001F;

    /* MinMax: '<S162>/Max' */
    rtb_Saturation1_p_idx_1_o = fmaxf(fmaxf(fmaxf(rtb_Sum_m[0], rtb_Sum_m[1]),
      rtb_Sum_m[2]), rtb_Sum_m[3]);

    /* MinMax: '<S162>/Max1' */
    rtb_Saturation1_i = fminf(fminf(fminf(rtb_Sum_m[0], rtb_Sum_m[1]),
      rtb_Sum_m[2]), rtb_Sum_m[3]);

    /* Switch: '<S167>/Switch' incorporates:
     *  Constant: '<S167>/Constant2'
     *  Logic: '<S167>/Logical Operator'
     *  MinMax: '<S162>/Max'
     *  MinMax: '<S162>/Max1'
     *  RelationalOperator: '<S167>/Relational Operator'
     *  RelationalOperator: '<S167>/Relational Operator1'
     */
    if ((rtb_Saturation1_p_idx_1_o > rtb_Gain1_lm) || (rtb_Saturation1_i <
         rtb_Saturation1_p_idx_0_o)) {
      /* Switch: '<S167>/Switch1' incorporates:
       *  Gain: '<S167>/Gain'
       *  RelationalOperator: '<S167>/Relational Operator2'
       *  RelationalOperator: '<S167>/Relational Operator3'
       *  Sum: '<S167>/Add'
       *  Sum: '<S167>/Subtract'
       *  Sum: '<S167>/Subtract1'
       *  Sum: '<S167>/Subtract2'
       *  Sum: '<S167>/Subtract3'
       *  Switch: '<S167>/Switch2'
       */
      if (rtb_Saturation1_p_idx_1_o - rtb_Saturation1_i > rtb_Gain1_lm -
          rtb_Saturation1_p_idx_0_o) {
        rtb_Saturation_ho = ((rtb_Gain1_lm - rtb_Saturation1_p_idx_1_o) +
                             (rtb_Saturation1_p_idx_0_o - rtb_Saturation1_i)) *
          0.5F;
      } else if (rtb_Saturation1_p_idx_1_o > rtb_Gain1_lm) {
        /* Switch: '<S167>/Switch2' incorporates:
         *  Sum: '<S167>/Subtract4'
         */
        rtb_Saturation_ho = rtb_Gain1_lm - rtb_Saturation1_p_idx_1_o;
      } else {
        /* Switch: '<S167>/Switch2' incorporates:
         *  Sum: '<S167>/Subtract5'
         */
        rtb_Saturation_ho = rtb_Saturation1_p_idx_0_o - rtb_Saturation1_i;
      }

      /* End of Switch: '<S167>/Switch1' */
    } else {
      rtb_Saturation_ho = 0.0F;
    }

    /* End of Switch: '<S167>/Switch' */

    /* Saturate: '<S167>/Saturation' */
    if (rtb_Saturation_ho > 0.2F) {
      rtb_Saturation_ho = 0.2F;
    } else {
      if (rtb_Saturation_ho < -0.2F) {
        rtb_Saturation_ho = -0.2F;
      }
    }

    /* End of Saturate: '<S167>/Saturation' */

    /* Sum: '<S162>/Sum1' incorporates:
     *  Sum: '<S167>/Add3'
     */
    u0_tmp_o = rtb_Saturation_ho + rtb_Divide1_o;

    /* Saturate: '<S162>/Saturation3' incorporates:
     *  Sum: '<S162>/Sum1'
     */
    if (u0_tmp_o > 1.0F) {
      rtb_Divide1_o = 1.0F;
    } else if (u0_tmp_o < 0.0F) {
      rtb_Divide1_o = 0.0F;
    } else {
      rtb_Divide1_o = u0_tmp_o;
    }

    /* End of Saturate: '<S162>/Saturation3' */

    /* MinMax: '<S167>/Min' incorporates:
     *  MinMax: '<S162>/Max'
     *  MinMax: '<S162>/Max1'
     *  Product: '<S167>/Divide'
     *  Product: '<S167>/Divide1'
     *  Sum: '<S167>/Add1'
     *  Sum: '<S167>/Add2'
     *  Sum: '<S167>/Subtract6'
     *  Sum: '<S167>/Subtract7'
     *  Sum: '<S167>/Subtract8'
     *  Sum: '<S167>/Subtract9'
     */
    rtb_Saturation1_i = fminf((rtb_Gain1_lm - u0_tmp_o) /
      ((rtb_Saturation1_p_idx_1_o + rtb_Saturation_ho) - u0_tmp_o), 1.0F /
      (u0_tmp_o - (rtb_Saturation1_i + rtb_Saturation_ho)) * (u0_tmp_o -
      rtb_Saturation1_p_idx_0_o));

    /* Saturate: '<S167>/Saturation1' */
    if (rtb_Saturation1_i > 1.0F) {
      rtb_Saturation1_i = 1.0F;
    } else {
      if (rtb_Saturation1_i < 0.5F) {
        rtb_Saturation1_i = 0.5F;
      }
    }

    /* End of Saturate: '<S167>/Saturation1' */

    /* Saturate: '<S162>/Saturation4' incorporates:
     *  Product: '<S162>/Multiply1'
     *  Sum: '<S162>/Sum2'
     */
    rtb_Saturation1_p_idx_1_o = rtb_floating_yaw_n[0] * rtb_Saturation1_i +
      rtb_Divide1_o;
    if (rtb_Saturation1_p_idx_1_o > 1.0F) {
      rtb_Saturation1_p_idx_1_o = 1.0F;
    } else {
      if (rtb_Saturation1_p_idx_1_o < 0.0F) {
        rtb_Saturation1_p_idx_1_o = 0.0F;
      }
    }

    /* Sum: '<S162>/Sum3' incorporates:
     *  Product: '<S162>/Multiply2'
     */
    rtb_Sum_m[0] = Controller_ConstB.VTOL2.r_column[0] *
      rtb_Saturation1_p_idx_2_o + rtb_Saturation1_p_idx_1_o;

    /* Saturate: '<S162>/Saturation4' incorporates:
     *  Product: '<S162>/Multiply1'
     *  Sum: '<S162>/Sum2'
     */
    rtb_floating_yaw_n[0] = rtb_Saturation1_p_idx_1_o;
    rtb_Saturation1_p_idx_1_o = rtb_floating_yaw_n[1] * rtb_Saturation1_i +
      rtb_Divide1_o;
    if (rtb_Saturation1_p_idx_1_o > 1.0F) {
      rtb_Saturation1_p_idx_1_o = 1.0F;
    } else {
      if (rtb_Saturation1_p_idx_1_o < 0.0F) {
        rtb_Saturation1_p_idx_1_o = 0.0F;
      }
    }

    /* Sum: '<S162>/Sum3' incorporates:
     *  Product: '<S162>/Multiply2'
     */
    rtb_Sum_m[1] = Controller_ConstB.VTOL2.r_column[1] *
      rtb_Saturation1_p_idx_2_o + rtb_Saturation1_p_idx_1_o;

    /* Saturate: '<S162>/Saturation4' incorporates:
     *  Product: '<S162>/Multiply1'
     *  Sum: '<S162>/Sum2'
     */
    rtb_floating_yaw_n[1] = rtb_Saturation1_p_idx_1_o;
    rtb_Saturation1_p_idx_1_o = rtb_floating_yaw_n[2] * rtb_Saturation1_i +
      rtb_Divide1_o;
    if (rtb_Saturation1_p_idx_1_o > 1.0F) {
      rtb_Saturation1_p_idx_1_o = 1.0F;
    } else {
      if (rtb_Saturation1_p_idx_1_o < 0.0F) {
        rtb_Saturation1_p_idx_1_o = 0.0F;
      }
    }

    /* Sum: '<S162>/Sum3' incorporates:
     *  Product: '<S162>/Multiply2'
     */
    rtb_Sum_m[2] = Controller_ConstB.VTOL2.r_column[2] *
      rtb_Saturation1_p_idx_2_o + rtb_Saturation1_p_idx_1_o;

    /* Saturate: '<S162>/Saturation4' incorporates:
     *  Product: '<S162>/Multiply1'
     *  Sum: '<S162>/Sum2'
     */
    rtb_floating_yaw_n[2] = rtb_Saturation1_p_idx_1_o;
    rtb_Saturation1_p_idx_1_o = rtb_floating_yaw_n[3] * rtb_Saturation1_i +
      rtb_Divide1_o;
    if (rtb_Saturation1_p_idx_1_o > 1.0F) {
      rtb_Saturation1_p_idx_1_o = 1.0F;
    } else {
      if (rtb_Saturation1_p_idx_1_o < 0.0F) {
        rtb_Saturation1_p_idx_1_o = 0.0F;
      }
    }

    /* Sum: '<S162>/Sum3' incorporates:
     *  Product: '<S162>/Multiply2'
     */
    rtb_Sum_m[3] = Controller_ConstB.VTOL2.r_column[3] *
      rtb_Saturation1_p_idx_2_o + rtb_Saturation1_p_idx_1_o;

    /* Saturate: '<S162>/Saturation4' incorporates:
     *  Product: '<S162>/Multiply1'
     */
    rtb_floating_yaw_n[3] = rtb_Saturation1_p_idx_1_o;

    /* MATLAB Function: '<S162>/R_Remix' */
    Controller_R_Remix(rtb_Sum_m, rtb_Gain1_lm, rtb_Saturation1_p_idx_0_o,
                       rtb_floating_yaw_n);

    /* MultiPortSwitch: '<S163>/Multiport Switch' incorporates:
     *  Constant: '<S164>/Constant1'
     *  Constant: '<S164>/Constant11'
     *  Constant: '<S164>/Constant12'
     *  Constant: '<S164>/Constant2'
     *  Constant: '<S164>/Constant7'
     *  Constant: '<S164>/Constant8'
     *  DataTypeConversion: '<S170>/Data Type Conversion'
     *  DataTypeConversion: '<S171>/Data Type Conversion'
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
        /* Saturate: '<S171>/Saturation' incorporates:
         *  Constant: '<S171>/Disarm'
         *  Reshape: '<S171>/Reshape'
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

      /* Saturate: '<S171>/Saturation' incorporates:
       *  Bias: '<S171>/Bias'
       *  Constant: '<S171>/Constant'
       *  DataTypeConversion: '<S171>/Data Type Conversion'
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

      /* Saturate: '<S171>/Saturation' incorporates:
       *  Bias: '<S171>/Bias1'
       *  Constant: '<S171>/Constant'
       *  DataTypeConversion: '<S171>/Data Type Conversion'
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

      /* Saturate: '<S171>/Saturation' incorporates:
       *  Bias: '<S171>/Bias2'
       *  Constant: '<S171>/Constant'
       *  DataTypeConversion: '<S171>/Data Type Conversion'
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

      /* Saturate: '<S171>/Saturation' incorporates:
       *  Bias: '<S171>/Bias3'
       *  Constant: '<S171>/Constant'
       *  DataTypeConversion: '<S171>/Data Type Conversion'
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

      /* SignalConversion: '<S164>/ConcatBufferAtVector Concatenate2In2' incorporates:
       *  Constant: '<S164>/Constant10'
       *  Constant: '<S164>/Constant11'
       *  Constant: '<S164>/Constant12'
       */
      rtb_MatrixConcatenate_g[9] = 0.0F;

      /* SignalConversion: '<S164>/ConcatBufferAtVector Concatenate2In1' incorporates:
       *  Constant: '<S164>/Constant9'
       */
      rtb_MatrixConcatenate_g[8] = 0.0F;
      rtb_MatrixConcatenate_g[7] = -CONTROL_PARAM.FW_PITCH_EFFC *
        CONTROL_PARAM.FW_TAIL2_DIR;
      rtb_MatrixConcatenate_g[6] = CONTROL_PARAM.FW_PITCH_EFFC *
        CONTROL_PARAM.FW_TAIL1_DIR;

      /* SignalConversion: '<S164>/ConcatBufferAtVector Concatenate1In2' incorporates:
       *  Constant: '<S164>/Constant6'
       *  Constant: '<S164>/Constant7'
       *  Constant: '<S164>/Constant8'
       */
      rtb_MatrixConcatenate_g[5] = 0.0F;

      /* SignalConversion: '<S164>/ConcatBufferAtVector Concatenate1In1' incorporates:
       *  Constant: '<S164>/Constant5'
       */
      rtb_MatrixConcatenate_g[4] = 0.0F;

      /* SignalConversion: '<S164>/ConcatBufferAtVector ConcatenateIn4' incorporates:
       *  Constant: '<S164>/Constant4'
       */
      rtb_MatrixConcatenate_g[3] = 0.0F;

      /* SignalConversion: '<S164>/ConcatBufferAtVector ConcatenateIn3' incorporates:
       *  Constant: '<S164>/Constant3'
       */
      rtb_MatrixConcatenate_g[2] = 0.0F;
      rtb_MatrixConcatenate_g[1] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON2_DIR;
      rtb_MatrixConcatenate_g[0] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON1_DIR;

      /* Saturate: '<S161>/Saturation5' incorporates:
       *  Constant: '<S164>/Constant1'
       *  Constant: '<S164>/Constant2'
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
        rtb_Saturation1_p_idx_0_o = 1.0F;
      } else if (rtb_Multiply[2] < -1.0F) {
        rtb_Saturation1_p_idx_0_o = -1.0F;
      } else {
        rtb_Saturation1_p_idx_0_o = rtb_Multiply[2];
      }

      /* End of Saturate: '<S161>/Saturation5' */
      for (i_o = 0; i_o < 4; i_o++) {
        /* Bias: '<S161>/Bias' incorporates:
         *  Gain: '<S161>/Gain1'
         *  Product: '<S161>/Multiply1'
         */
        rtb_Saturation5_m[i_o] = 500.0F * (rtb_MatrixConcatenate_g[i_o + 8] *
          rtb_Saturation1_p_idx_0_o + (rtb_MatrixConcatenate_g[i_o + 4] *
          rtb_Gain1_lm + rtb_MatrixConcatenate_g[i_o] *
          rtb_Saturation1_p_idx_2_o)) + 1500.0F;

        /* Sum: '<S162>/Sum4' */
        rtb_Saturation1_p_idx_1_o = rtb_Sum_m[i_o] + rtb_floating_yaw_n[i_o];

        /* Saturate: '<S162>/Saturation5' */
        if (rtb_Saturation1_p_idx_1_o > 1.0F) {
          rtb_Saturation1_p_idx_1_o = 1.0F;
        } else {
          if (rtb_Saturation1_p_idx_1_o < 0.0F) {
            rtb_Saturation1_p_idx_1_o = 0.0F;
          }
        }

        /* End of Saturate: '<S162>/Saturation5' */

        /* DataTypeConversion: '<S162>/Data Type Conversion' incorporates:
         *  Constant: '<S162>/Constant2'
         *  Gain: '<S162>/Gain3'
         *  Sum: '<S162>/Sum5'
         */
        u0_o = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          rtb_Saturation1_p_idx_1_o), 4.2949673E+9F) + 1000U);

        /* Saturate: '<S162>/Saturation' */
        if (u0_o > CONTROL_PARAM.MC_OUT_MAX) {
          rtb_VariantMergeForOutportactua[i_o] = CONTROL_PARAM.MC_OUT_MAX;
        } else if (u0_o < CONTROL_PARAM.MC_OUT_MIN) {
          rtb_VariantMergeForOutportactua[i_o] = CONTROL_PARAM.MC_OUT_MIN;
        } else {
          rtb_VariantMergeForOutportactua[i_o] = u0_o;
        }

        /* End of Saturate: '<S162>/Saturation' */
      }

      /* Saturate: '<S161>/Saturation4' */
      if (rtb_Multiply1[0] > 1.0F) {
        rtb_Saturation1_p_idx_2_o = 1.0F;
      } else if (rtb_Multiply1[0] < 0.0F) {
        rtb_Saturation1_p_idx_2_o = 0.0F;
      } else {
        rtb_Saturation1_p_idx_2_o = rtb_Multiply1[0];
      }

      /* End of Saturate: '<S161>/Saturation4' */

      /* DataTypeConversion: '<S166>/Data Type Conversion' incorporates:
       *  Constant: '<S166>/Constant1'
       *  Gain: '<S166>/Gain1'
       *  Sum: '<S166>/Sum1'
       */
      u0_o = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
        rtb_Saturation1_p_idx_2_o), 4.2949673E+9F) + 1000U);

      /* Saturate: '<S161>/Saturation1' */
      if (u0_o > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[4] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_o < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[4] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[4] = u0_o;
      }

      /* DataTypeConversion: '<S161>/Data Type Conversion' incorporates:
       *  Bias: '<S161>/Bias1'
       */
      rtb_Saturation1_p_idx_2_o = fmodf(floorf(rtb_Saturation5_m[0] +
        CONTROL_PARAM.SERVO1_BIAS), 65536.0F);
      u0_o = (uint16_T)(rtb_Saturation1_p_idx_2_o < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_p_idx_2_o :
                        (int32_T)(uint16_T)rtb_Saturation1_p_idx_2_o);

      /* Saturate: '<S161>/Saturation1' */
      if (u0_o > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[5] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_o < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[5] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[5] = u0_o;
      }

      /* DataTypeConversion: '<S161>/Data Type Conversion1' incorporates:
       *  Bias: '<S161>/Bias2'
       */
      rtb_Saturation1_p_idx_2_o = fmodf(floorf(rtb_Saturation5_m[1] +
        CONTROL_PARAM.SERVO2_BIAS), 65536.0F);
      u0_o = (uint16_T)(rtb_Saturation1_p_idx_2_o < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_p_idx_2_o :
                        (int32_T)(uint16_T)rtb_Saturation1_p_idx_2_o);

      /* Saturate: '<S161>/Saturation1' */
      if (u0_o > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[6] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_o < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[6] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[6] = u0_o;
      }

      /* DataTypeConversion: '<S161>/Data Type Conversion2' incorporates:
       *  Bias: '<S161>/Bias3'
       */
      rtb_Saturation1_p_idx_2_o = fmodf(floorf(rtb_Saturation5_m[2] +
        CONTROL_PARAM.SERVO3_BIAS), 65536.0F);
      u0_o = (uint16_T)(rtb_Saturation1_p_idx_2_o < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_p_idx_2_o :
                        (int32_T)(uint16_T)rtb_Saturation1_p_idx_2_o);

      /* Saturate: '<S161>/Saturation1' */
      if (u0_o > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[7] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_o < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[7] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[7] = u0_o;
      }

      /* DataTypeConversion: '<S161>/Data Type Conversion3' incorporates:
       *  Bias: '<S161>/Bias4'
       */
      rtb_Saturation1_p_idx_2_o = fmodf(floorf(rtb_Saturation5_m[3] +
        CONTROL_PARAM.SERVO4_BIAS), 65536.0F);
      u0_o = (uint16_T)(rtb_Saturation1_p_idx_2_o < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_p_idx_2_o :
                        (int32_T)(uint16_T)rtb_Saturation1_p_idx_2_o);

      /* Saturate: '<S161>/Saturation1' */
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

    /* End of MultiPortSwitch: '<S163>/Multiport Switch' */
  }

#endif

  /* End of Outputs for SubSystem: '<S7>/VTOL_Control_Allocation' */

  /* Outport: '<Root>/Control_Out' incorporates:
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   *  Reshape: '<S147>/Reshape'
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
  Controller_DW.DiscreteTimeIntegrator5_DSTAT_k += (rtb_MultiportSwitch_idx_0 -
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_k) * 6.28318548F * 0.002F;

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

  /* InitializeConditions for DiscreteIntegrator: '<S9>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S8>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_o = 1U;

  /* SystemInitialize for Enabled SubSystem: '<S2>/FW_Controller' */
  /* InitializeConditions for DiscreteIntegrator: '<S66>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_i = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S26>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_h = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S36>/Integrator1' */
  Controller_DW.Integrator1_DSTATE_c = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S38>/Integrator1' */
  Controller_DW.Integrator1_DSTATE_j = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S25>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_L_hl = 1U;

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

  /* InitializeConditions for DiscreteIntegrator: '<S41>/ ' */
  Controller_DW._DSTATE = 0.05F;

  /* InitializeConditions for DiscreteIntegrator: '<S62>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_n = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_d = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S61>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_h = 1U;
  Controller_DW.DiscreteTimeIntegrator1_Prev_dx = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S58>/ ' */
  Controller_DW._DSTATE_h = Controller_ConstB.Zero1;
  if (Controller_DW._DSTATE_h >= CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
    Controller_DW._DSTATE_h = CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
  } else {
    if (Controller_DW._DSTATE_h <= -CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
      Controller_DW._DSTATE_h = -CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
    }
  }

  Controller_DW._PrevResetState = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S58>/ ' */

  /* InitializeConditions for DiscreteIntegrator: '<S59>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_f = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_b = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S38>/Integrator' */
  Controller_DW.Integrator_DSTATE_d = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S36>/Integrator' */
  Controller_DW.Integrator_DSTATE_n = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S2>/FW_Controller' */

  /* SystemInitialize for Enabled SubSystem: '<S2>/MC_Controller' */
  /* InitializeConditions for DiscreteIntegrator: '<S100>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S100>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S97>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_c = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S102>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* InitializeConditions for Delay: '<S75>/Delay' */
  Controller_DW.Delay_DSTATE = 1U;

  /* SystemInitialize for Enabled SubSystem: '<S74>/Velocity_Controller' */
  /* InitializeConditions for DiscreteIntegrator: '<S120>/Integrator1' */
  Controller_DW.Integrator1_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S120>/Integrator' */
  Controller_DW.Integrator_DSTATE_o[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S125>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S120>/Integrator' */
  Controller_DW.Integrator_DSTATE_o[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S125>/Discrete-Time Integrator' */
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

  Controller_DW.DiscreteTimeIntegrator_PrevRe_p = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S127>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_m = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_a = 0;

  /* End of SystemInitialize for SubSystem: '<S74>/Velocity_Controller' */

  /* SystemInitialize for Enabled SubSystem: '<S75>/Veloxity_Z_Controller' */
  /* InitializeConditions for DiscreteIntegrator: '<S140>/Integrator1' */
  Controller_DW.Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S144>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_IC_LOADI = 1U;
  Controller_DW.DiscreteTimeIntegrator_PrevRe_f = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S146>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_k = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S140>/Integrator' */
  Controller_DW.Integrator_DSTATE = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S75>/Veloxity_Z_Controller' */
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
