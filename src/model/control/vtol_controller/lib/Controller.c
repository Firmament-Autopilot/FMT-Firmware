/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.859
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Dec 22 15:59:52 2025
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
  7.0F,
  5.0F,
  0.52359879F,
  0.18F,
  0.18F,
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
  1.57079637F,
  1.04719758F,
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
  17.0F,
  0.2F,
  1.0F,
  1.0F,
  1.0F,
  0.0F,
  0.2F,
  0.25F,
  0.2F,
  0.75F,
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
                                        *   '<S132>/hover_throttle'
                                        *   '<S17>/FF'
                                        *   '<S40>/P_control'
                                        *   '<S41>/Gain'
                                        *   '<S41>/Gain1'
                                        *   '<S41>/P_control'
                                        *   '<S42>/Kv'
                                        *   '<S112>/Saturation'
                                        *   '<S148>/Bias1'
                                        *   '<S148>/Bias2'
                                        *   '<S148>/Bias3'
                                        *   '<S148>/Bias4'
                                        *   '<S148>/Saturation1'
                                        *   '<S149>/Constant'
                                        *   '<S149>/Constant1'
                                        *   '<S149>/Saturation'
                                        *   '<S158>/Bias1'
                                        *   '<S158>/Bias2'
                                        *   '<S158>/Bias3'
                                        *   '<S158>/Bias4'
                                        *   '<S158>/Saturation1'
                                        *   '<S159>/Constant'
                                        *   '<S159>/Constant1'
                                        *   '<S159>/Saturation'
                                        *   '<S21>/trim_speed'
                                        *   '<S22>/trim_speed'
                                        *   '<S28>/Saturation'
                                        *   '<S57>/Gain'
                                        *   '<S58>/ '
                                        *   '<S58>/Gain3'
                                        *   '<S80>/Saturation'
                                        *   '<S80>/Saturation1'
                                        *   '<S80>/Saturation2'
                                        *   '<S123>/kd'
                                        *   '<S123>/Saturation'
                                        *   '<S124>/ki'
                                        *   '<S124>/Discrete-Time Integrator'
                                        *   '<S125>/kp'
                                        *   '<S140>/kd'
                                        *   '<S140>/Saturation'
                                        *   '<S141>/Constant'
                                        *   '<S141>/ki'
                                        *   '<S141>/Discrete-Time Integrator'
                                        *   '<S142>/kp'
                                        *   '<S151>/Constant1'
                                        *   '<S151>/Constant12'
                                        *   '<S151>/Constant2'
                                        *   '<S151>/Constant7'
                                        *   '<S156>/Bias'
                                        *   '<S156>/Bias1'
                                        *   '<S156>/Bias2'
                                        *   '<S156>/Bias3'
                                        *   '<S157>/Bias'
                                        *   '<S157>/Bias1'
                                        *   '<S157>/Bias2'
                                        *   '<S157>/Bias3'
                                        *   '<S161>/Constant1'
                                        *   '<S161>/Constant11'
                                        *   '<S161>/Constant12'
                                        *   '<S161>/Constant2'
                                        *   '<S161>/Constant7'
                                        *   '<S161>/Constant8'
                                        *   '<S167>/Bias'
                                        *   '<S167>/Bias1'
                                        *   '<S167>/Bias2'
                                        *   '<S167>/Bias3'
                                        *   '<S168>/Bias'
                                        *   '<S168>/Bias1'
                                        *   '<S168>/Bias2'
                                        *   '<S168>/Bias3'
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
                                        *   '<S93>/Gain'
                                        *   '<S93>/Gain1'
                                        *   '<S105>/Constant1'
                                        *   '<S105>/Constant2'
                                        *   '<S98>/gain1'
                                        *   '<S98>/gain2'
                                        *   '<S98>/gain3'
                                        *   '<S98>/Saturation'
                                        *   '<S99>/gain1'
                                        *   '<S99>/gain2'
                                        *   '<S99>/gain3'
                                        *   '<S99>/Discrete-Time Integrator'
                                        *   '<S100>/gain1'
                                        *   '<S100>/gain2'
                                        *   '<S100>/gain3'
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
 *    '<S149>/R_Remix'
 *    '<S159>/R_Remix'
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
  real32_T rtb_Saturation_g;
  real32_T rtb_DiscreteTimeIntegrator1_e;
  real32_T rtb_Saturation_bx;
  boolean_T rtb_Compare;
  real32_T rtb_Saturation2;
  real32_T rtb_Gain_az;
  real32_T rtb_Saturation_p;
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
      Controller_DW._DSTATE = 0.25F;

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
      rtb_Divide_m_idx_2 = Controller_U.INS_Out.airspeed;
    } else {
      /* Sqrt: '<S73>/Sqrt' incorporates:
       *  Math: '<S73>/Square'
       *  Sum: '<S73>/Sum of Elements'
       */
      rtb_Add_k = sqrtf(((Controller_U.INS_Out.quat[0] *
                          Controller_U.INS_Out.quat[0] +
                          Controller_U.INS_Out.quat[1] *
                          Controller_U.INS_Out.quat[1]) +
                         Controller_U.INS_Out.quat[2] *
                         Controller_U.INS_Out.quat[2]) +
                        Controller_U.INS_Out.quat[3] *
                        Controller_U.INS_Out.quat[3]);

      /* Product: '<S69>/Divide' incorporates:
       *  Sqrt: '<S73>/Sqrt'
       */
      rtb_Divide_m_idx_0 = Controller_U.INS_Out.quat[0] / rtb_Add_k;
      rtb_Divide_m_idx_1 = Controller_U.INS_Out.quat[1] / rtb_Add_k;
      rtb_Divide_m_idx_2 = Controller_U.INS_Out.quat[2] / rtb_Add_k;
      rtb_Divide_m_idx_3 = Controller_U.INS_Out.quat[3] / rtb_Add_k;

      /* Math: '<S72>/Square' incorporates:
       *  Math: '<S70>/Square'
       *  Math: '<S71>/Square'
       */
      rtb_Gain_az = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_0;

      /* Math: '<S72>/Square2' incorporates:
       *  Math: '<S70>/Square2'
       *  Math: '<S71>/Square2'
       */
      rtb_Saturation_p = rtb_Divide_m_idx_2 * rtb_Divide_m_idx_2;

      /* Math: '<S72>/Square1' incorporates:
       *  Math: '<S70>/Square1'
       *  Math: '<S71>/Square1'
       */
      rtb_Add_k = rtb_Divide_m_idx_1 * rtb_Divide_m_idx_1;

      /* Math: '<S72>/Square3' incorporates:
       *  Math: '<S70>/Square3'
       *  Math: '<S71>/Square3'
       */
      rtb_Saturation1 = rtb_Divide_m_idx_3 * rtb_Divide_m_idx_3;

      /* Sum: '<S72>/Subtract' incorporates:
       *  Math: '<S72>/Square'
       *  Math: '<S72>/Square1'
       *  Math: '<S72>/Square2'
       *  Math: '<S72>/Square3'
       *  Sum: '<S72>/Add'
       *  Sum: '<S72>/Add1'
       */
      rtb_MatrixConcatenate1[8] = (rtb_Gain_az + rtb_Saturation1) - (rtb_Add_k +
        rtb_Saturation_p);

      /* Product: '<S72>/Multiply2' incorporates:
       *  Product: '<S71>/Multiply2'
       */
      rtb_Saturation_g = rtb_Divide_m_idx_2 * rtb_Divide_m_idx_3;

      /* Product: '<S72>/Multiply3' incorporates:
       *  Product: '<S71>/Multiply3'
       */
      rtb_Add1_j4 = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_1;

      /* Gain: '<S72>/Gain1' incorporates:
       *  Product: '<S72>/Multiply2'
       *  Product: '<S72>/Multiply3'
       *  Sum: '<S72>/Add2'
       */
      rtb_MatrixConcatenate1[7] = (rtb_Saturation_g + rtb_Add1_j4) * 2.0F;

      /* Product: '<S72>/Multiply' incorporates:
       *  Product: '<S70>/Multiply2'
       */
      rtb_Saturation_bx = rtb_Divide_m_idx_1 * rtb_Divide_m_idx_3;

      /* Product: '<S72>/Multiply1' incorporates:
       *  Product: '<S70>/Multiply3'
       */
      rtb_Add2_h = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_2;

      /* Gain: '<S72>/Gain' incorporates:
       *  Product: '<S72>/Multiply'
       *  Product: '<S72>/Multiply1'
       *  Sum: '<S72>/Subtract2'
       */
      rtb_MatrixConcatenate1[6] = (rtb_Saturation_bx - rtb_Add2_h) * 2.0F;

      /* Gain: '<S71>/Gain1' incorporates:
       *  Sum: '<S71>/Subtract1'
       */
      rtb_MatrixConcatenate1[5] = (rtb_Saturation_g - rtb_Add1_j4) * 2.0F;

      /* Sum: '<S71>/Subtract' incorporates:
       *  Sum: '<S71>/Add'
       *  Sum: '<S71>/Add1'
       */
      rtb_MatrixConcatenate1[4] = (rtb_Gain_az + rtb_Saturation_p) - (rtb_Add_k
        + rtb_Saturation1);

      /* Product: '<S71>/Multiply' incorporates:
       *  Product: '<S70>/Multiply'
       */
      rtb_Saturation_g = rtb_Divide_m_idx_1 * rtb_Divide_m_idx_2;

      /* Product: '<S71>/Multiply1' incorporates:
       *  Product: '<S70>/Multiply1'
       */
      rtb_Add1_j4 = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_3;

      /* Gain: '<S71>/Gain' incorporates:
       *  Product: '<S71>/Multiply'
       *  Product: '<S71>/Multiply1'
       *  Sum: '<S71>/Add3'
       */
      rtb_MatrixConcatenate1[3] = (rtb_Saturation_g + rtb_Add1_j4) * 2.0F;

      /* Gain: '<S70>/Gain1' incorporates:
       *  Sum: '<S70>/Add2'
       */
      rtb_MatrixConcatenate1[2] = (rtb_Saturation_bx + rtb_Add2_h) * 2.0F;

      /* Gain: '<S70>/Gain' incorporates:
       *  Sum: '<S70>/Subtract1'
       */
      rtb_MatrixConcatenate1[1] = (rtb_Saturation_g - rtb_Add1_j4) * 2.0F;

      /* Sum: '<S70>/Subtract' incorporates:
       *  Sum: '<S70>/Add'
       *  Sum: '<S70>/Add1'
       */
      rtb_MatrixConcatenate1[0] = (rtb_Gain_az + rtb_Add_k) - (rtb_Saturation_p
        + rtb_Saturation1);

      /* Product: '<S67>/Multiply' */
      for (i = 0; i < 3; i++) {
        rtb_MatrixConcatenate1_0[i] = rtb_MatrixConcatenate1[i + 6] *
          rtb_TmpSignalConversionAtMultip[2] + (rtb_MatrixConcatenate1[i + 3] *
          rtb_TmpSignalConversionAtMultip[1] + rtb_MatrixConcatenate1[i] *
          rtb_TmpSignalConversionAtMultip[0]);
      }

      /* End of Product: '<S67>/Multiply' */
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
      rtb_Divide_m_idx_2 = Controller_U.FMS_Out.phi_cmd;
    } else {
      /* Trigonometry: '<S14>/Atan' incorporates:
       *  DiscreteIntegrator: '<S36>/Integrator1'
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

    /* End of Switch: '<S29>/Switch' */

    /* Switch: '<S29>/Switch1' incorporates:
     *  Constant: '<S35>/Constant'
     *  DiscreteIntegrator: '<S38>/Integrator1'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S35>/Compare'
     */
    if (Controller_U.FMS_Out.ctrl_mode == 3) {
      rtb_Divide_m_idx_0 = Controller_U.FMS_Out.theta_cmd;
    } else {
      rtb_Divide_m_idx_0 = Controller_DW.Integrator1_DSTATE_j;
    }

    /* End of Switch: '<S29>/Switch1' */

    /* Saturate: '<S30>/Saturation' */
    if (rtb_Divide_m_idx_2 > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Add_k = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else if (rtb_Divide_m_idx_2 < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Add_k = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      rtb_Add_k = rtb_Divide_m_idx_2;
    }

    /* Reshape: '<S18>/Reshape' incorporates:
     *  Constant: '<S31>/Constant1'
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S31>/Multiply'
     *  Sum: '<S30>/Sum'
     */
    Controller_B.Reshape[0] = (rtb_Add_k - Controller_U.INS_Out.phi) *
      CONTROL_PARAM.FW_ROLL_P;

    /* Bias: '<S30>/Pitch Offset' */
    rtb_Add_k = rtb_Divide_m_idx_0 + CONTROL_PARAM.FW_PITCH_OFFSET;

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
    rtb_Add_k = tanf(rtb_Divide_m_idx_2) * arm_cos_f32(rtb_Divide_m_idx_0) *
      rtb_Add_k + Controller_U.FMS_Out.psi_rate_cmd;

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
    rtb_Divide_m_idx_0 = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S19>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_m_idx_1 = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Trigonometry: '<S19>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_m_idx_2 = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Sum: '<S19>/Add1' incorporates:
     *  Product: '<S19>/Multiply1'
     *  Product: '<S19>/Multiply3'
     *  Trigonometry: '<S19>/Cos'
     *  Trigonometry: '<S19>/Cos1'
     *  Trigonometry: '<S19>/Sin'
     */
    rtb_Add1_j4 = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_1 *
      Controller_B.Reshape[2] + rtb_Divide_m_idx_2 * Controller_B.Reshape[1];

    /* Sum: '<S19>/Add2' incorporates:
     *  Product: '<S19>/Multiply4'
     *  Product: '<S19>/Multiply5'
     *  Trigonometry: '<S19>/Cos'
     *  Trigonometry: '<S19>/Cos1'
     *  Trigonometry: '<S19>/Sin'
     */
    rtb_Add2_h = rtb_Divide_m_idx_2 * rtb_Divide_m_idx_1 * Controller_B.Reshape
      [2] - rtb_Divide_m_idx_0 * Controller_B.Reshape[1];

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
    rtb_Compare = (Controller_U.FMS_Out.ext_state == 1);

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
      rtb_Gain_az = sqrtf(((Controller_U.INS_Out.quat[0] *
                            Controller_U.INS_Out.quat[0] +
                            Controller_U.INS_Out.quat[1] *
                            Controller_U.INS_Out.quat[1]) +
                           Controller_U.INS_Out.quat[2] *
                           Controller_U.INS_Out.quat[2]) +
                          Controller_U.INS_Out.quat[3] *
                          Controller_U.INS_Out.quat[3]);

      /* Product: '<S49>/Divide' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Sqrt: '<S53>/Sqrt'
       */
      rtb_Divide_m_idx_0 = Controller_U.INS_Out.quat[0] / rtb_Gain_az;
      rtb_Divide_m_idx_1 = Controller_U.INS_Out.quat[1] / rtb_Gain_az;
      rtb_Divide_m_idx_2 = Controller_U.INS_Out.quat[2] / rtb_Gain_az;
      rtb_Divide_m_idx_3 = Controller_U.INS_Out.quat[3] / rtb_Gain_az;

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
      rtb_Divide_m_idx_2 = rtb_MatrixConcatenate1_0[0];

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
      rtb_Gain_az = arm_cos_f32(-Controller_U.INS_Out.psi);
      rtb_MatrixConcatenate1[4] = rtb_Gain_az;

      /* Trigonometry: '<S55>/Trigonometric Function2' incorporates:
       *  Gain: '<S54>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S55>/Trigonometric Function'
       */
      rtb_Saturation_p = arm_sin_f32(-Controller_U.INS_Out.psi);

      /* Gain: '<S55>/Gain' incorporates:
       *  Trigonometry: '<S55>/Trigonometric Function2'
       */
      rtb_MatrixConcatenate1[3] = -rtb_Saturation_p;

      /* SignalConversion: '<S55>/ConcatBufferAtVector Concatenate1In3' incorporates:
       *  Constant: '<S55>/Constant3'
       */
      rtb_MatrixConcatenate1[2] = 0.0F;

      /* Trigonometry: '<S55>/Trigonometric Function' */
      rtb_MatrixConcatenate1[1] = rtb_Saturation_p;

      /* Trigonometry: '<S55>/Trigonometric Function1' */
      rtb_MatrixConcatenate1[0] = rtb_Gain_az;

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
        rtb_DiscreteTimeIntegrator1_e = rtb_Multiply_ni[0] - 1.0F;
      } else if (rtb_Multiply_ni[0] >= -1.0F) {
        rtb_DiscreteTimeIntegrator1_e = 0.0F;
      } else {
        rtb_DiscreteTimeIntegrator1_e = rtb_Multiply_ni[0] - -1.0F;
      }

      /* End of DeadZone: '<S46>/Dead Zone' */

      /* Signum: '<S46>/Sign' */
      if (rtb_DiscreteTimeIntegrator1_e < 0.0F) {
        rtb_DiscreteTimeIntegrator1_e = -1.0F;
      } else {
        if (rtb_DiscreteTimeIntegrator1_e > 0.0F) {
          rtb_DiscreteTimeIntegrator1_e = 1.0F;
        }
      }

      /* End of Signum: '<S46>/Sign' */
    } else {
      rtb_Divide_m_idx_2 = Controller_U.INS_Out.airspeed;
      rtb_DiscreteTimeIntegrator1_e = 1.0F;
    }

    /* End of Switch: '<S45>/Switch' */

    /* Saturate: '<S45>/Saturation' */
    if (rtb_Divide_m_idx_2 > 100.0F) {
      rtb_Divide_m_idx_2 = 100.0F;
    } else {
      if (rtb_Divide_m_idx_2 < 8.0F) {
        rtb_Divide_m_idx_2 = 8.0F;
      }
    }

    /* End of Saturate: '<S45>/Saturation' */

    /* Product: '<S47>/Multiply1' incorporates:
     *  Gain: '<S47>/Gain'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S47>/Divide'
     *  Trigonometry: '<S47>/Asin'
     */
    rtb_Saturation2 = atanf(-Controller_U.FMS_Out.w_cmd / rtb_Divide_m_idx_2) *
      rtb_DiscreteTimeIntegrator1_e;

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
    rtb_DiscreteTimeIntegrator1_e *= atanf(1.0F / rtb_Divide_m_idx_2 *
      -rtb_Divide_m_idx_0);

    /* Saturate: '<S44>/Saturation1' */
    if (rtb_DiscreteTimeIntegrator1_e > 0.785398185F) {
      rtb_DiscreteTimeIntegrator1_e = 0.785398185F;
    } else {
      if (rtb_DiscreteTimeIntegrator1_e < -0.785398185F) {
        rtb_DiscreteTimeIntegrator1_e = -0.785398185F;
      }
    }

    /* End of Saturate: '<S44>/Saturation1' */

    /* Sum: '<S39>/Sum' */
    rtb_DiscreteTimeIntegrator1_e = rtb_Saturation2 -
      rtb_DiscreteTimeIntegrator1_e;

    /* Gain: '<S42>/Gain' incorporates:
     *  DiscreteIntegrator: '<S66>/Discrete-Time Integrator5'
     *  Gain: '<S42>/Kv'
     *  Inport: '<Root>/FMS_Out'
     *  Sum: '<S42>/Minus'
     */
    rtb_Divide_m_idx_2 = (Controller_U.FMS_Out.u_cmd -
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
    rtb_Gain_az = (Controller_DW.DiscreteTimeIntegrator5_DSTAT_j -
                   Controller_DW.DiscreteTimeIntegrator1_DSTAT_h) * 8.88442421F;

    /* Sum: '<S42>/Sum' incorporates:
     *  Gain: '<S42>/Gain1'
     */
    rtb_Divide_m_idx_0 = rtb_Divide_m_idx_2 - 0.101936802F * rtb_Gain_az;

    /* Sum: '<S15>/Add' incorporates:
     *  Gain: '<S15>/Gain'
     *  Gain: '<S15>/Gain1'
     */
    rtb_Saturation_p = CONTROL_PARAM.FW_TECS_W2T * rtb_DiscreteTimeIntegrator1_e
      + CONTROL_PARAM.FW_TECS_U2T * rtb_Divide_m_idx_0;

    /* Saturate: '<S15>/Saturation' */
    if (rtb_Saturation_p > 0.5F) {
      rtb_Saturation_p = 0.5F;
    } else {
      if (rtb_Saturation_p < -0.5F) {
        rtb_Saturation_p = -0.5F;
      }
    }

    /* End of Saturate: '<S15>/Saturation' */

    /* DiscreteIntegrator: '<S61>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_h != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm = rtb_Saturation_p;
    }

    if (rtb_Compare || (Controller_DW.DiscreteTimeIntegrator1_Prev_dx != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm = rtb_Saturation_p;
    }

    /* Gain: '<S61>/Gain' incorporates:
     *  DiscreteIntegrator: '<S61>/Discrete-Time Integrator1'
     *  Sum: '<S61>/Sum5'
     */
    rtb_Divide_m_idx_3 = (rtb_Saturation_p -
                          Controller_DW.DiscreteTimeIntegrator1_DSTA_nm) *
      188.49556F;

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
        if (rtb_Compare) {
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
          rtb_Divide_m_idx_1 = CONTROL_PARAM.FW_TECS_THOR_D * rtb_Divide_m_idx_3;

          /* Saturate: '<S41>/Saturation1' incorporates:
           *  Switch: '<S16>/Switch'
           *  Switch: '<S41>/Switch'
           */
          if (rtb_Divide_m_idx_1 > 0.3F) {
            rtb_Divide_m_idx_1 = 0.3F;
          } else {
            if (rtb_Divide_m_idx_1 < -0.3F) {
              rtb_Divide_m_idx_1 = -0.3F;
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
                     CONTROL_PARAM.FW_TECS_U2T * rtb_Divide_m_idx_2) *
            CONTROL_PARAM.FW_TECS_THOR_FF + (CONTROL_PARAM.FW_TECS_THOR_P *
            rtb_Saturation_p + rtb_Divide_m_idx_1);
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
      rtb_Divide_m_idx_1 = (CONTROL_PARAM.FW_ROLL_RATE_P * rtb_fw_rate_err_B[0]
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
      if (rtb_Divide_m_idx_1 > 1.0F) {
        rtb_Divide_m_idx_1 = 1.0F;
      } else {
        if (rtb_Divide_m_idx_1 < -1.0F) {
          rtb_Divide_m_idx_1 = -1.0F;
        }
      }

      /* Sum: '<S17>/Add' */
      rtb_Add_k += rtb_Divide_m_idx_1;

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
      rtb_Divide_m_idx_1 = (CONTROL_PARAM.FW_PITCH_RATE_P * rtb_fw_rate_err_B[1]
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
      if (rtb_Divide_m_idx_1 > 1.0F) {
        rtb_Divide_m_idx_1 = 1.0F;
      } else {
        if (rtb_Divide_m_idx_1 < -1.0F) {
          rtb_Divide_m_idx_1 = -1.0F;
        }
      }

      /* Sum: '<S17>/Add' */
      rtb_Add_k += rtb_Divide_m_idx_1;

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
      rtb_Divide_m_idx_1 = (CONTROL_PARAM.FW_YAW_RATE_P * rtb_fw_rate_err_B[2] +
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
      if (rtb_Divide_m_idx_1 > 1.0F) {
        rtb_Divide_m_idx_1 = 1.0F;
      } else {
        if (rtb_Divide_m_idx_1 < -1.0F) {
          rtb_Divide_m_idx_1 = -1.0F;
        }
      }

      /* Sum: '<S17>/Add' */
      rtb_Add_k += rtb_Divide_m_idx_1;

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
    rtb_Divide_m_idx_1 = CONTROL_PARAM.FW_TECS_W2P *
      rtb_DiscreteTimeIntegrator1_e - CONTROL_PARAM.FW_TECS_U2P *
      rtb_Divide_m_idx_0;

    /* RelationalOperator: '<S56>/Compare' incorporates:
     *  Constant: '<S56>/Constant'
     *  Inport: '<Root>/FMS_Out'
     */
    rtb_Compare_i = (Controller_U.FMS_Out.ext_state == 1);

    /* DiscreteIntegrator: '<S58>/ ' */
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

    /* DiscreteIntegrator: '<S59>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_f != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_e = rtb_Divide_m_idx_1;
    }

    if (rtb_Compare_i || (Controller_DW.DiscreteTimeIntegrator1_PrevR_b != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_e = rtb_Divide_m_idx_1;
    }

    /* Gain: '<S59>/Gain' incorporates:
     *  DiscreteIntegrator: '<S59>/Discrete-Time Integrator1'
     *  Sum: '<S59>/Sum5'
     */
    rtb_Add2_h = (rtb_Divide_m_idx_1 -
                  Controller_DW.DiscreteTimeIntegrator1_DSTAT_e) * 62.831852F;

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
    if (rtb_Compare_i) {
      rtb_Divide_m_idx_0 = 0.0F;
    } else {
      /* Gain: '<S57>/Gain' incorporates:
       *  Switch: '<S59>/Switch'
       */
      rtb_Divide_m_idx_0 = CONTROL_PARAM.FW_TECS_PITCH_D * rtb_Add2_h;

      /* Saturate: '<S40>/Saturation1' */
      if (rtb_Divide_m_idx_0 > 0.3F) {
        rtb_Divide_m_idx_0 = 0.3F;
      } else {
        if (rtb_Divide_m_idx_0 < -0.3F) {
          rtb_Divide_m_idx_0 = -0.3F;
        }
      }

      /* End of Saturate: '<S40>/Saturation1' */
      rtb_Divide_m_idx_0 = ((CONTROL_PARAM.FW_TECS_PITCH_P * rtb_Divide_m_idx_1
        + Controller_DW._DSTATE_h) + rtb_Divide_m_idx_0) +
        (CONTROL_PARAM.FW_TECS_W2P * rtb_Saturation2 - CONTROL_PARAM.FW_TECS_U2P
         * rtb_Divide_m_idx_2) * CONTROL_PARAM.FW_TECS_PITCH_F;
    }

    /* End of Switch: '<S40>/Switch' */

    /* Sum: '<S38>/Subtract' incorporates:
     *  DiscreteIntegrator: '<S38>/Integrator1'
     */
    rtb_Add_k = Controller_DW.Integrator1_DSTATE_j - rtb_Divide_m_idx_0;

    /* Product: '<S43>/Multiply1' incorporates:
     *  Constant: '<S43>/const1'
     *  DiscreteIntegrator: '<S38>/Integrator'
     */
    rtb_Divide_m_idx_0 = Controller_DW.Integrator_DSTATE_d * 0.04F;

    /* Sum: '<S43>/Add' */
    rtb_Add1_j4 = rtb_Add_k + rtb_Divide_m_idx_0;

    /* Signum: '<S43>/Sign' */
    if (rtb_Add1_j4 < 0.0F) {
      rtb_Add_k = -1.0F;
    } else if (rtb_Add1_j4 > 0.0F) {
      rtb_Add_k = 1.0F;
    } else {
      rtb_Add_k = rtb_Add1_j4;
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
    rtb_Saturation2 = (sqrtf((8.0F * fabsf(rtb_Add1_j4) + Controller_ConstB.d_f)
      * Controller_ConstB.d_f) - Controller_ConstB.d_f) * 0.5F * rtb_Add_k +
      rtb_Divide_m_idx_0;

    /* Sum: '<S43>/Add4' */
    rtb_Divide_m_idx_0 += rtb_Add1_j4 - rtb_Saturation2;

    /* Sum: '<S43>/Add3' */
    rtb_Divide_m_idx_2 = rtb_Add1_j4 + Controller_ConstB.d_f;

    /* Sum: '<S43>/Subtract1' */
    rtb_Add1_j4 -= Controller_ConstB.d_f;

    /* Signum: '<S43>/Sign1' */
    if (rtb_Divide_m_idx_2 < 0.0F) {
      rtb_Divide_m_idx_2 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_2 > 0.0F) {
        rtb_Divide_m_idx_2 = 1.0F;
      }
    }

    /* End of Signum: '<S43>/Sign1' */

    /* Signum: '<S43>/Sign2' */
    if (rtb_Add1_j4 < 0.0F) {
      rtb_Add1_j4 = -1.0F;
    } else {
      if (rtb_Add1_j4 > 0.0F) {
        rtb_Add1_j4 = 1.0F;
      }
    }

    /* End of Signum: '<S43>/Sign2' */

    /* Sum: '<S43>/Add5' incorporates:
     *  Gain: '<S43>/Gain2'
     *  Product: '<S43>/Multiply4'
     *  Sum: '<S43>/Subtract2'
     */
    rtb_Saturation2 += (rtb_Divide_m_idx_2 - rtb_Add1_j4) * 0.5F *
      rtb_Divide_m_idx_0;

    /* Sum: '<S43>/Subtract3' */
    rtb_Divide_m_idx_2 = rtb_Saturation2 - Controller_ConstB.d_f;

    /* Sum: '<S43>/Add6' */
    rtb_Add_k = rtb_Saturation2 + Controller_ConstB.d_f;

    /* Product: '<S43>/Divide' */
    rtb_Sum = rtb_Saturation2 / Controller_ConstB.d_f;

    /* Signum: '<S43>/Sign5' incorporates:
     *  Signum: '<S43>/Sign6'
     */
    if (rtb_Saturation2 < 0.0F) {
      rtb_Sign5_f = -1.0F;

      /* Signum: '<S43>/Sign6' */
      rtb_DiscreteTimeIntegrator1_e = -1.0F;
    } else if (rtb_Saturation2 > 0.0F) {
      rtb_Sign5_f = 1.0F;

      /* Signum: '<S43>/Sign6' */
      rtb_DiscreteTimeIntegrator1_e = 1.0F;
    } else {
      rtb_Sign5_f = rtb_Saturation2;

      /* Signum: '<S43>/Sign6' */
      rtb_DiscreteTimeIntegrator1_e = rtb_Saturation2;
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
    rtb_Saturation2 = (Controller_DW.Integrator1_DSTATE_c -
                       Controller_U.FMS_Out.ay_cmd) + rtb_Divide_m_idx_0;

    /* Signum: '<S37>/Sign' */
    if (rtb_Saturation2 < 0.0F) {
      rtb_Add1_j4 = -1.0F;
    } else if (rtb_Saturation2 > 0.0F) {
      rtb_Add1_j4 = 1.0F;
    } else {
      rtb_Add1_j4 = rtb_Saturation2;
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
    rtb_Add1_j4 = (sqrtf((8.0F * fabsf(rtb_Saturation2) + Controller_ConstB.d_ih)
                         * Controller_ConstB.d_ih) - Controller_ConstB.d_ih) *
      0.5F * rtb_Add1_j4 + rtb_Divide_m_idx_0;

    /* Sum: '<S37>/Add4' */
    rtb_Divide_m_idx_0 += rtb_Saturation2 - rtb_Add1_j4;

    /* Sum: '<S37>/Add3' */
    u = rtb_Saturation2 + Controller_ConstB.d_ih;

    /* Sum: '<S37>/Subtract1' */
    rtb_Saturation2 -= Controller_ConstB.d_ih;

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
    if (rtb_Saturation2 < 0.0F) {
      rtb_Saturation2 = -1.0F;
    } else {
      if (rtb_Saturation2 > 0.0F) {
        rtb_Saturation2 = 1.0F;
      }
    }

    /* End of Signum: '<S37>/Sign2' */

    /* Sum: '<S37>/Add5' incorporates:
     *  Gain: '<S37>/Gain2'
     *  Product: '<S37>/Multiply4'
     *  Sum: '<S37>/Subtract2'
     */
    rtb_Add1_j4 += (u - rtb_Saturation2) * 0.5F * rtb_Divide_m_idx_0;

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
    Controller_DW._DSTATE += CONTROL_PARAM.FW_TECS_THOR_I * rtb_Saturation_p *
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
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_h += 0.002F * rtb_Gain_az;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_d = 0;

    /* Update for DiscreteIntegrator: '<S61>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_h = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTA_nm += 0.002F * rtb_Divide_m_idx_3;
    Controller_DW.DiscreteTimeIntegrator1_Prev_dx = (int8_T)rtb_Compare;

    /* Update for DiscreteIntegrator: '<S58>/ ' incorporates:
     *  Gain: '<S58>/Gain3'
     */
    Controller_DW._DSTATE_h += CONTROL_PARAM.FW_TECS_PITCH_I *
      rtb_Divide_m_idx_1 * 0.002F;
    if (Controller_DW._DSTATE_h >= CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
      Controller_DW._DSTATE_h = CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
    } else {
      if (Controller_DW._DSTATE_h <= -CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
        Controller_DW._DSTATE_h = -CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
      }
    }

    Controller_DW._PrevResetState = (int8_T)rtb_Compare_i;

    /* End of Update for DiscreteIntegrator: '<S58>/ ' */

    /* Update for DiscreteIntegrator: '<S59>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_f = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_e += 0.002F * rtb_Add2_h;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_b = (int8_T)rtb_Compare_i;

    /* Signum: '<S43>/Sign3' */
    if (rtb_Add_k < 0.0F) {
      rtb_Add_k = -1.0F;
    } else {
      if (rtb_Add_k > 0.0F) {
        rtb_Add_k = 1.0F;
      }
    }

    /* End of Signum: '<S43>/Sign3' */

    /* Signum: '<S43>/Sign4' */
    if (rtb_Divide_m_idx_2 < 0.0F) {
      rtb_Divide_m_idx_2 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_2 > 0.0F) {
        rtb_Divide_m_idx_2 = 1.0F;
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
      Controller_ConstB.Gain4_n * ((rtb_Add_k - rtb_Divide_m_idx_2) * 0.5F) -
      rtb_DiscreteTimeIntegrator1_e * 12.566371F) * 0.002F;

    /* Signum: '<S37>/Sign6' incorporates:
     *  Signum: '<S37>/Sign5'
     */
    if (rtb_Add1_j4 < 0.0F) {
      rtb_DiscreteTimeIntegrator1_e = -1.0F;

      /* Signum: '<S37>/Sign5' */
      rtb_Divide_m_idx_0 = -1.0F;
    } else if (rtb_Add1_j4 > 0.0F) {
      rtb_DiscreteTimeIntegrator1_e = 1.0F;

      /* Signum: '<S37>/Sign5' */
      rtb_Divide_m_idx_0 = 1.0F;
    } else {
      rtb_DiscreteTimeIntegrator1_e = rtb_Add1_j4;

      /* Signum: '<S37>/Sign5' */
      rtb_Divide_m_idx_0 = rtb_Add1_j4;
    }

    /* End of Signum: '<S37>/Sign6' */

    /* Sum: '<S37>/Add6' */
    rtb_Divide_m_idx_2 = rtb_Add1_j4 + Controller_ConstB.d_ih;

    /* Sum: '<S37>/Subtract3' */
    rtb_Add_k = rtb_Add1_j4 - Controller_ConstB.d_ih;

    /* Signum: '<S37>/Sign3' */
    if (rtb_Divide_m_idx_2 < 0.0F) {
      rtb_Divide_m_idx_2 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_2 > 0.0F) {
        rtb_Divide_m_idx_2 = 1.0F;
      }
    }

    /* End of Signum: '<S37>/Sign3' */

    /* Signum: '<S37>/Sign4' */
    if (rtb_Add_k < 0.0F) {
      rtb_Add_k = -1.0F;
    } else {
      if (rtb_Add_k > 0.0F) {
        rtb_Add_k = 1.0F;
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
    Controller_DW.Integrator_DSTATE_n += ((rtb_Add1_j4 / Controller_ConstB.d_ih
      - rtb_Divide_m_idx_0) * Controller_ConstB.Gain4_g * ((rtb_Divide_m_idx_2 -
      rtb_Add_k) * 0.5F) - rtb_DiscreteTimeIntegrator1_e * 58.836F) * 0.002F;
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
   *  Constant: '<S141>/Constant'
   *  Product: '<S107>/Divide1'
   *  Product: '<S123>/Multiply'
   *  Product: '<S98>/Multiply'
   *  Signum: '<S107>/Sign'
   */
  if (Controller_DW.Relay_Mode) {
    if (!Controller_DW.MC_Controller_MODE) {
      /* InitializeConditions for DiscreteIntegrator: '<S99>/Discrete-Time Integrator' */
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

      /* End of InitializeConditions for DiscreteIntegrator: '<S99>/Discrete-Time Integrator' */

      /* InitializeConditions for DiscreteIntegrator: '<S124>/Discrete-Time Integrator' */
      Controller_DW.DiscreteTimeIntegrator_PrevRe_p = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S126>/Discrete-Time Integrator1' */
      Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S96>/Discrete-Time Integrator5' */
      Controller_DW.DiscreteTimeIntegrator5_IC_LO_c = 1U;

      /* InitializeConditions for DiscreteIntegrator: '<S101>/Discrete-Time Integrator1' */
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevR_k = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S119>/Integrator1' */
      Controller_DW.Integrator1_DSTATE[0] = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S124>/Discrete-Time Integrator' */
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

      /* InitializeConditions for DiscreteIntegrator: '<S119>/Integrator' */
      Controller_DW.Integrator_DSTATE[0] = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S119>/Integrator1' */
      Controller_DW.Integrator1_DSTATE[1] = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S124>/Discrete-Time Integrator' */
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

      /* InitializeConditions for DiscreteIntegrator: '<S119>/Integrator' */
      Controller_DW.Integrator_DSTATE[1] = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S138>/Integrator1' */
      Controller_DW.Integrator1_DSTATE_e = 0.0F;

      /* InitializeConditions for DiscreteIntegrator: '<S141>/Discrete-Time Integrator' */
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

      /* End of InitializeConditions for DiscreteIntegrator: '<S141>/Discrete-Time Integrator' */

      /* InitializeConditions for DiscreteIntegrator: '<S143>/Discrete-Time Integrator1' */
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 1U;
      Controller_DW.DiscreteTimeIntegrator1_Prev_ks = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S138>/Integrator' */
      Controller_DW.Integrator_DSTATE_j = 0.0F;
      Controller_DW.MC_Controller_MODE = true;
    }

    /* Sqrt: '<S91>/Sqrt' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Math: '<S91>/Square'
     *  Sum: '<S91>/Sum of Elements'
     */
    rtb_Add1_j4 = sqrtf(((Controller_U.INS_Out.quat[0] *
                          Controller_U.INS_Out.quat[0] +
                          Controller_U.INS_Out.quat[1] *
                          Controller_U.INS_Out.quat[1]) +
                         Controller_U.INS_Out.quat[2] *
                         Controller_U.INS_Out.quat[2]) +
                        Controller_U.INS_Out.quat[3] *
                        Controller_U.INS_Out.quat[3]);

    /* Product: '<S87>/Divide' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Sqrt: '<S91>/Sqrt'
     */
    rtb_Divide_m_idx_0 = Controller_U.INS_Out.quat[0] / rtb_Add1_j4;
    rtb_Divide_m_idx_1 = Controller_U.INS_Out.quat[1] / rtb_Add1_j4;
    rtb_Divide_m_idx_2 = Controller_U.INS_Out.quat[2] / rtb_Add1_j4;
    rtb_Divide_m_idx_3 = Controller_U.INS_Out.quat[3] / rtb_Add1_j4;

    /* Sum: '<S88>/Subtract' incorporates:
     *  Math: '<S88>/Square'
     *  Math: '<S88>/Square1'
     *  Math: '<S88>/Square2'
     *  Math: '<S88>/Square3'
     *  Sum: '<S88>/Add'
     *  Sum: '<S88>/Add1'
     */
    rtb_MatrixConcatenate1[0] = (rtb_Divide_m_idx_0 * rtb_Divide_m_idx_0 +
      rtb_Divide_m_idx_1 * rtb_Divide_m_idx_1) - (rtb_Divide_m_idx_2 *
      rtb_Divide_m_idx_2 + rtb_Divide_m_idx_3 * rtb_Divide_m_idx_3);

    /* Gain: '<S88>/Gain' incorporates:
     *  Product: '<S88>/Multiply'
     *  Product: '<S88>/Multiply1'
     *  Sum: '<S88>/Subtract1'
     */
    rtb_MatrixConcatenate1[1] = (rtb_Divide_m_idx_1 * rtb_Divide_m_idx_2 -
      rtb_Divide_m_idx_0 * rtb_Divide_m_idx_3) * 2.0F;

    /* Gain: '<S88>/Gain1' incorporates:
     *  Product: '<S88>/Multiply2'
     *  Product: '<S88>/Multiply3'
     *  Sum: '<S88>/Add2'
     */
    rtb_MatrixConcatenate1[2] = (rtb_Divide_m_idx_1 * rtb_Divide_m_idx_3 +
      rtb_Divide_m_idx_0 * rtb_Divide_m_idx_2) * 2.0F;

    /* Gain: '<S89>/Gain' incorporates:
     *  Product: '<S89>/Multiply'
     *  Product: '<S89>/Multiply1'
     *  Sum: '<S89>/Add3'
     */
    rtb_MatrixConcatenate1[3] = (rtb_Divide_m_idx_1 * rtb_Divide_m_idx_2 +
      rtb_Divide_m_idx_0 * rtb_Divide_m_idx_3) * 2.0F;

    /* Sum: '<S89>/Subtract' incorporates:
     *  Math: '<S89>/Square'
     *  Math: '<S89>/Square1'
     *  Math: '<S89>/Square2'
     *  Math: '<S89>/Square3'
     *  Sum: '<S89>/Add'
     *  Sum: '<S89>/Add1'
     */
    rtb_MatrixConcatenate1[4] = (rtb_Divide_m_idx_0 * rtb_Divide_m_idx_0 +
      rtb_Divide_m_idx_2 * rtb_Divide_m_idx_2) - (rtb_Divide_m_idx_1 *
      rtb_Divide_m_idx_1 + rtb_Divide_m_idx_3 * rtb_Divide_m_idx_3);

    /* Gain: '<S89>/Gain1' incorporates:
     *  Product: '<S89>/Multiply2'
     *  Product: '<S89>/Multiply3'
     *  Sum: '<S89>/Subtract1'
     */
    rtb_MatrixConcatenate1[5] = (rtb_Divide_m_idx_2 * rtb_Divide_m_idx_3 -
      rtb_Divide_m_idx_0 * rtb_Divide_m_idx_1) * 2.0F;

    /* Gain: '<S90>/Gain' incorporates:
     *  Product: '<S90>/Multiply'
     *  Product: '<S90>/Multiply1'
     *  Sum: '<S90>/Subtract2'
     */
    rtb_MatrixConcatenate1[6] = (rtb_Divide_m_idx_1 * rtb_Divide_m_idx_3 -
      rtb_Divide_m_idx_0 * rtb_Divide_m_idx_2) * 2.0F;

    /* Gain: '<S90>/Gain1' incorporates:
     *  Product: '<S90>/Multiply2'
     *  Product: '<S90>/Multiply3'
     *  Sum: '<S90>/Add2'
     */
    rtb_MatrixConcatenate1[7] = (rtb_Divide_m_idx_2 * rtb_Divide_m_idx_3 +
      rtb_Divide_m_idx_0 * rtb_Divide_m_idx_1) * 2.0F;

    /* Sum: '<S90>/Subtract' incorporates:
     *  Math: '<S90>/Square'
     *  Math: '<S90>/Square1'
     *  Math: '<S90>/Square2'
     *  Math: '<S90>/Square3'
     *  Sum: '<S90>/Add'
     *  Sum: '<S90>/Add1'
     */
    rtb_MatrixConcatenate1[8] = (rtb_Divide_m_idx_0 * rtb_Divide_m_idx_0 +
      rtb_Divide_m_idx_3 * rtb_Divide_m_idx_3) - (rtb_Divide_m_idx_1 *
      rtb_Divide_m_idx_1 + rtb_Divide_m_idx_2 * rtb_Divide_m_idx_2);

    /* Product: '<S84>/Multiply' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  SignalConversion: '<S84>/TmpSignal ConversionAtMultiplyInport2'
     */
    for (i = 0; i < 3; i++) {
      rtb_TmpSignalConversionAtMultip[i] = rtb_MatrixConcatenate1[i + 6] *
        Controller_U.INS_Out.vd + (rtb_MatrixConcatenate1[i + 3] *
        Controller_U.INS_Out.ve + rtb_MatrixConcatenate1[i] *
        Controller_U.INS_Out.vn);
    }

    /* End of Product: '<S84>/Multiply' */

    /* DiscreteIntegrator: '<S99>/Discrete-Time Integrator' incorporates:
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

    /* RelationalOperator: '<S118>/Compare' incorporates:
     *  Constant: '<S118>/Constant'
     *  Inport: '<Root>/FMS_Out'
     */
    rtb_Compare = (Controller_U.FMS_Out.mode >= 5);

    /* Trigonometry: '<S121>/Trigonometric Function1' incorporates:
     *  Gain: '<S120>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1[0] = arm_cos_f32(-Controller_U.INS_Out.psi);

    /* Trigonometry: '<S121>/Trigonometric Function' incorporates:
     *  Gain: '<S120>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1[1] = arm_sin_f32(-Controller_U.INS_Out.psi);

    /* SignalConversion: '<S121>/ConcatBufferAtVector Concatenate1In3' incorporates:
     *  Constant: '<S121>/Constant3'
     */
    rtb_MatrixConcatenate1[2] = 0.0F;

    /* Gain: '<S121>/Gain' incorporates:
     *  Gain: '<S120>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S121>/Trigonometric Function2'
     */
    rtb_MatrixConcatenate1[3] = -arm_sin_f32(-Controller_U.INS_Out.psi);

    /* Trigonometry: '<S121>/Trigonometric Function3' incorporates:
     *  Gain: '<S120>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1[4] = arm_cos_f32(-Controller_U.INS_Out.psi);

    /* SignalConversion: '<S121>/ConcatBufferAtVector Concatenate2In3' incorporates:
     *  Constant: '<S121>/Constant4'
     */
    rtb_MatrixConcatenate1[5] = 0.0F;

    /* SignalConversion: '<S121>/ConcatBufferAtVector ConcatenateIn3' */
    rtb_MatrixConcatenate1[6] = Controller_ConstB.VectorConcatenate3[0];
    rtb_MatrixConcatenate1[7] = Controller_ConstB.VectorConcatenate3[1];
    rtb_MatrixConcatenate1[8] = Controller_ConstB.VectorConcatenate3[2];

    /* Product: '<S117>/Multiply' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  SignalConversion: '<S117>/TmpSignal ConversionAtMultiplyInport2'
     */
    for (i = 0; i < 3; i++) {
      rtb_fw_rate_err_B[i] = rtb_MatrixConcatenate1[i + 3] *
        Controller_U.INS_Out.ve + rtb_MatrixConcatenate1[i] *
        Controller_U.INS_Out.vn;
    }

    /* End of Product: '<S117>/Multiply' */

    /* Product: '<S114>/Multiply' incorporates:
     *  DataTypeConversion: '<S114>/Data Type Conversion'
     *  DiscreteIntegrator: '<S119>/Integrator1'
     *  Sum: '<S114>/Sum'
     */
    rtb_Saturation1 = (Controller_DW.Integrator1_DSTATE[0] - rtb_fw_rate_err_B[0])
      * (real32_T)rtb_Compare;
    rtb_Saturation_g = (Controller_DW.Integrator1_DSTATE[1] - rtb_fw_rate_err_B
                        [1]) * (real32_T)rtb_Compare;

    /* Logic: '<S77>/Logical Operator' incorporates:
     *  Constant: '<S113>/Constant'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S113>/Compare'
     */
    rtb_Compare_i = ((Controller_U.FMS_Out.reset != 0) ||
                     (Controller_U.FMS_Out.ext_state != 0));

    /* DiscreteIntegrator: '<S124>/Discrete-Time Integrator' */
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

    /* DiscreteIntegrator: '<S126>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] = rtb_Saturation1;
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] = rtb_Saturation_g;
    }

    if (rtb_Compare_i || (Controller_DW.DiscreteTimeIntegrator1_PrevRes != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] = rtb_Saturation1;
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] = rtb_Saturation_g;
    }

    /* Gain: '<S126>/Gain' incorporates:
     *  DiscreteIntegrator: '<S126>/Discrete-Time Integrator1'
     *  Sum: '<S126>/Sum5'
     */
    rtb_Saturation_bx = (rtb_Saturation1 -
                         Controller_DW.DiscreteTimeIntegrator1_DSTATE[0]) *
      62.831852F;
    rtb_Gain_az = (rtb_Saturation_g -
                   Controller_DW.DiscreteTimeIntegrator1_DSTATE[1]) * 62.831852F;

    /* Switch: '<S126>/Switch' incorporates:
     *  Gain: '<S126>/Gain1'
     */
    if (rtb_Compare_i) {
      rtb_Divide_m_idx_3 = 0.0F;
      rtb_Add1_j4 = 0.0F;
    } else {
      rtb_Divide_m_idx_3 = rtb_Saturation_bx;
      rtb_Add1_j4 = rtb_Gain_az;
    }

    /* End of Switch: '<S126>/Switch' */

    /* Product: '<S123>/Multiply' incorporates:
     *  Constant: '<S123>/kd'
     */
    rtb_Divide_m_idx_2 = CONTROL_PARAM.MC_VEL_XY_D * rtb_Divide_m_idx_3;

    /* Saturate: '<S123>/Saturation' */
    if (rtb_Divide_m_idx_2 > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
      rtb_Divide_m_idx_2 = CONTROL_PARAM.MC_VEL_XY_D_MAX;
    } else {
      if (rtb_Divide_m_idx_2 < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
        rtb_Divide_m_idx_2 = CONTROL_PARAM.MC_VEL_XY_D_MIN;
      }
    }

    rtb_Divide_m_idx_3 = rtb_Divide_m_idx_2;

    /* Product: '<S123>/Multiply' incorporates:
     *  Constant: '<S123>/kd'
     */
    rtb_Divide_m_idx_2 = CONTROL_PARAM.MC_VEL_XY_D * rtb_Add1_j4;

    /* Saturate: '<S123>/Saturation' */
    if (rtb_Divide_m_idx_2 > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
      rtb_Divide_m_idx_2 = CONTROL_PARAM.MC_VEL_XY_D_MAX;
    } else {
      if (rtb_Divide_m_idx_2 < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
        rtb_Divide_m_idx_2 = CONTROL_PARAM.MC_VEL_XY_D_MIN;
      }
    }

    /* Switch: '<S116>/Switch' incorporates:
     *  Constant: '<S125>/kp'
     *  Constant: '<S127>/Constant'
     *  Constant: '<S129>/Constant'
     *  Constant: '<S130>/Constant'
     *  DiscreteIntegrator: '<S124>/Discrete-Time Integrator'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S125>/Multiply'
     *  Product: '<S128>/Multiply2'
     *  Product: '<S128>/Multiply3'
     *  RelationalOperator: '<S127>/Compare'
     *  RelationalOperator: '<S129>/Compare'
     *  RelationalOperator: '<S130>/Compare'
     *  S-Function (sfix_bitop): '<S128>/cmd_ax valid'
     *  S-Function (sfix_bitop): '<S128>/cmd_ay valid'
     *  S-Function (sfix_bitop): '<S128>/cmd_u valid'
     *  S-Function (sfix_bitop): '<S128>/cmd_v valid'
     *  Sum: '<S115>/Add'
     *  Sum: '<S128>/Sum1'
     */
    if (Controller_U.FMS_Out.ctrl_mode == 6) {
      rtb_Divide_m_idx_3 = ((Controller_U.FMS_Out.cmd_mask & 64) > 0 ?
                            (CONTROL_PARAM.MC_VEL_XY_P * rtb_Saturation1 +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0]) + rtb_Divide_m_idx_3 :
                            0.0F) + ((Controller_U.FMS_Out.cmd_mask & 512) > 0 ?
        Controller_U.FMS_Out.ax_cmd : 0.0F);
      rtb_Add1_j4 = ((Controller_U.FMS_Out.cmd_mask & 128) > 0 ?
                     (CONTROL_PARAM.MC_VEL_XY_P * rtb_Saturation_g +
                      Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1]) +
                     rtb_Divide_m_idx_2 : 0.0F) +
        ((Controller_U.FMS_Out.cmd_mask & 1024) > 0 ?
         Controller_U.FMS_Out.ay_cmd : 0.0F);
    } else {
      rtb_Divide_m_idx_3 += CONTROL_PARAM.MC_VEL_XY_P * rtb_Saturation1 +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0];
      rtb_Add1_j4 = (CONTROL_PARAM.MC_VEL_XY_P * rtb_Saturation_g +
                     Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1]) +
        rtb_Divide_m_idx_2;
    }

    /* End of Switch: '<S116>/Switch' */

    /* Trigonometry: '<S112>/Atan' incorporates:
     *  Constant: '<S112>/g'
     *  Gain: '<S112>/Gain1'
     *  Gain: '<S112>/gain'
     *  Product: '<S112>/Divide'
     */
    rtb_Add_k = atanf(1.1F * rtb_Add1_j4 / 9.8055F);
    rtb_Add1_j4 = atanf(1.1F * -rtb_Divide_m_idx_3 / 9.8055F);

    /* Switch: '<S103>/Switch' incorporates:
     *  Constant: '<S110>/Constant'
     *  Inport: '<Root>/FMS_Out'
     *  Logic: '<S103>/Logical Operator'
     *  RelationalOperator: '<S109>/Compare'
     *  RelationalOperator: '<S110>/Compare'
     *  Saturate: '<S112>/Saturation'
     *  Switch: '<S103>/Switch1'
     */
    if ((Controller_U.FMS_Out.ctrl_mode == 3) || (Controller_U.FMS_Out.ctrl_mode
         == 4)) {
      rtb_Divide_m_idx_3 = Controller_U.FMS_Out.phi_cmd;
      rtb_Add1_j4 = Controller_U.FMS_Out.theta_cmd;
    } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
      /* Switch: '<S111>/Switch' incorporates:
       *  S-Function (sfix_bitop): '<S111>/cmd_phi valid'
       *  S-Function (sfix_bitop): '<S111>/cmd_theta valid'
       *  Saturate: '<S112>/Saturation'
       *  Switch: '<S103>/Switch1'
       */
      if ((Controller_U.FMS_Out.cmd_mask & 8) > 0) {
        rtb_Divide_m_idx_3 = Controller_U.FMS_Out.phi_cmd;
      } else if (rtb_Add_k > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S112>/Saturation' */
        rtb_Divide_m_idx_3 = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else if (rtb_Add_k < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S112>/Saturation' */
        rtb_Divide_m_idx_3 = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        rtb_Divide_m_idx_3 = rtb_Add_k;
      }

      if ((Controller_U.FMS_Out.cmd_mask & 16) > 0) {
        rtb_Add1_j4 = Controller_U.FMS_Out.theta_cmd;
      } else if (rtb_Add1_j4 > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S112>/Saturation' */
        rtb_Add1_j4 = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_Add1_j4 < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Saturate: '<S112>/Saturation' */
          rtb_Add1_j4 = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        }
      }

      /* End of Switch: '<S111>/Switch' */
    } else {
      if (rtb_Add_k > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S112>/Saturation' incorporates:
         *  Switch: '<S103>/Switch1'
         */
        rtb_Divide_m_idx_3 = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else if (rtb_Add_k < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S112>/Saturation' incorporates:
         *  Switch: '<S103>/Switch1'
         */
        rtb_Divide_m_idx_3 = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        /* Switch: '<S103>/Switch1' incorporates:
         *  Saturate: '<S112>/Saturation'
         */
        rtb_Divide_m_idx_3 = rtb_Add_k;
      }

      /* Saturate: '<S112>/Saturation' */
      if (rtb_Add1_j4 > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Switch: '<S103>/Switch1' */
        rtb_Add1_j4 = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_Add1_j4 < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Switch: '<S103>/Switch1' */
          rtb_Add1_j4 = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        }
      }
    }

    /* End of Switch: '<S103>/Switch' */

    /* Sum: '<S104>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_m_idx_2 = rtb_Divide_m_idx_3 - Controller_U.INS_Out.phi;

    /* Product: '<S107>/Divide1' incorporates:
     *  Abs: '<S107>/Abs'
     *  Constant: '<S107>/const2'
     */
    rtb_Saturation_p = fabsf(rtb_Divide_m_idx_2) / 0.002F;

    /* Product: '<S107>/Divide' incorporates:
     *  Constant: '<S105>/Constant1'
     *  Constant: '<S107>/const1'
     *  Math: '<S107>/Square'
     *  SignalConversion: '<S107>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_Divide_m_idx_1 = 9.5993F / (CONTROL_PARAM.MC_ROLL_P *
      CONTROL_PARAM.MC_ROLL_P);

    /* Signum: '<S107>/Sign' */
    if (rtb_Divide_m_idx_2 < 0.0F) {
      rtb_Saturation2 = -1.0F;
    } else if (rtb_Divide_m_idx_2 > 0.0F) {
      rtb_Saturation2 = 1.0F;
    } else {
      rtb_Saturation2 = rtb_Divide_m_idx_2;
    }

    /* Switch: '<S107>/Switch' incorporates:
     *  Constant: '<S105>/Constant1'
     *  Gain: '<S107>/Gain1'
     *  Gain: '<S107>/Gain2'
     *  Logic: '<S107>/Logical Operator'
     *  Product: '<S107>/Multiply'
     *  Product: '<S107>/Multiply1'
     *  Product: '<S107>/Multiply2'
     *  Product: '<S107>/Multiply3'
     *  RelationalOperator: '<S107>/Relational Operator'
     *  RelationalOperator: '<S107>/Relational Operator2'
     *  SignalConversion: '<S107>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S107>/Sqrt'
     *  Sum: '<S107>/Subtract'
     */
    if ((rtb_Divide_m_idx_2 <= rtb_Divide_m_idx_1) && (rtb_Divide_m_idx_2 >=
         -rtb_Divide_m_idx_1)) {
      rtb_Saturation2 = rtb_Divide_m_idx_2 * CONTROL_PARAM.MC_ROLL_P;
    } else {
      rtb_Saturation2 *= sqrtf((rtb_Saturation2 * rtb_Divide_m_idx_2 - 0.5F *
        rtb_Divide_m_idx_1) * Controller_ConstB.Gain);
    }

    /* Product: '<S107>/Divide' incorporates:
     *  Gain: '<S107>/Gain3'
     */
    rtb_Add_k = -rtb_Saturation_p;

    /* Switch: '<S108>/Switch' incorporates:
     *  Gain: '<S107>/Gain3'
     *  RelationalOperator: '<S108>/UpperRelop'
     */
    if (rtb_Saturation2 >= -rtb_Saturation_p) {
      /* Product: '<S107>/Divide' */
      rtb_Add_k = rtb_Saturation2;
    }

    rtb_Divide_m_idx_3 = rtb_Saturation_p;
    rtb_Divide_m_idx_0 = rtb_Saturation2;

    /* Sum: '<S104>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S107>/Divide1'
     *  Signum: '<S107>/Sign'
     */
    rtb_Divide_m_idx_2 = rtb_Add1_j4 - Controller_U.INS_Out.theta;

    /* Product: '<S107>/Divide1' incorporates:
     *  Abs: '<S107>/Abs'
     *  Constant: '<S107>/const2'
     */
    rtb_Saturation_p = fabsf(rtb_Divide_m_idx_2) / 0.002F;

    /* Product: '<S107>/Divide' incorporates:
     *  Constant: '<S105>/Constant2'
     *  Constant: '<S107>/const1'
     *  Math: '<S107>/Square'
     *  SignalConversion: '<S107>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_Divide_m_idx_1 = 9.5993F / (CONTROL_PARAM.MC_PITCH_P *
      CONTROL_PARAM.MC_PITCH_P);

    /* Signum: '<S107>/Sign' */
    if (rtb_Divide_m_idx_2 < 0.0F) {
      rtb_Saturation2 = -1.0F;
    } else if (rtb_Divide_m_idx_2 > 0.0F) {
      rtb_Saturation2 = 1.0F;
    } else {
      rtb_Saturation2 = rtb_Divide_m_idx_2;
    }

    /* Switch: '<S107>/Switch' incorporates:
     *  Constant: '<S105>/Constant2'
     *  Gain: '<S107>/Gain1'
     *  Gain: '<S107>/Gain2'
     *  Logic: '<S107>/Logical Operator'
     *  Product: '<S107>/Multiply'
     *  Product: '<S107>/Multiply1'
     *  Product: '<S107>/Multiply2'
     *  Product: '<S107>/Multiply3'
     *  RelationalOperator: '<S107>/Relational Operator'
     *  RelationalOperator: '<S107>/Relational Operator2'
     *  SignalConversion: '<S107>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S107>/Sqrt'
     *  Sum: '<S107>/Subtract'
     */
    if ((rtb_Divide_m_idx_2 <= rtb_Divide_m_idx_1) && (rtb_Divide_m_idx_2 >=
         -rtb_Divide_m_idx_1)) {
      rtb_Saturation2 = rtb_Divide_m_idx_2 * CONTROL_PARAM.MC_PITCH_P;
    } else {
      rtb_Saturation2 *= sqrtf((rtb_Saturation2 * rtb_Divide_m_idx_2 - 0.5F *
        rtb_Divide_m_idx_1) * Controller_ConstB.Gain);
    }

    /* Gain: '<S107>/Gain3' */
    rtb_Divide_m_idx_1 = -rtb_Saturation_p;

    /* Switch: '<S108>/Switch' incorporates:
     *  Gain: '<S107>/Gain3'
     *  RelationalOperator: '<S108>/UpperRelop'
     */
    if (rtb_Saturation2 >= -rtb_Saturation_p) {
      rtb_Divide_m_idx_1 = rtb_Saturation2;
    }

    /* MultiPortSwitch: '<S80>/Multiport Switch' incorporates:
     *  Constant: '<S82>/Constant3'
     *  Constant: '<S85>/Constant3'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S82>/Multiply1'
     *  Product: '<S82>/Multiply2'
     *  Product: '<S85>/Multiply1'
     *  Product: '<S85>/Multiply2'
     *  Sum: '<S82>/Sum'
     *  Sum: '<S82>/Sum1'
     *  Sum: '<S85>/Sum'
     *  Sum: '<S85>/Sum1'
     */
    switch (Controller_U.FMS_Out.ext_state) {
     case 1:
      /* Saturate: '<S85>/Saturation3' */
      if (rtb_TmpSignalConversionAtMultip[0] > 8.0F) {
        rtb_Add1_j4 = 8.0F;
      } else if (rtb_TmpSignalConversionAtMultip[0] < 2.0F) {
        rtb_Add1_j4 = 2.0F;
      } else {
        rtb_Add1_j4 = rtb_TmpSignalConversionAtMultip[0];
      }

      /* End of Saturate: '<S85>/Saturation3' */

      /* Product: '<S85>/Multiply' incorporates:
       *  Constant: '<S85>/Constant1'
       *  Sum: '<S85>/Subtract1'
       */
      rtb_Divide_m_idx_1 = (rtb_Add1_j4 - 2.0F) * Controller_ConstB.Divide_k;

      /* Switch: '<S108>/Switch2' incorporates:
       *  RelationalOperator: '<S108>/LowerRelop1'
       */
      if (rtb_Divide_m_idx_0 > rtb_Divide_m_idx_3) {
        rtb_Add_k = rtb_Divide_m_idx_3;
      }

      Controller_B.Multiply[0] = (1.0F - rtb_Divide_m_idx_1) * rtb_Add_k +
        rtb_Divide_m_idx_1 * Controller_B.Reshape[0];
      Controller_B.Multiply[1] = Controller_B.Reshape[1];
      Controller_B.Multiply[2] = (1.0F - rtb_Divide_m_idx_1) *
        Controller_U.FMS_Out.psi_rate_cmd + rtb_Divide_m_idx_1 *
        Controller_B.Reshape[2];
      break;

     case 3:
      /* Saturate: '<S82>/Saturation3' */
      if (rtb_TmpSignalConversionAtMultip[0] > 8.0F) {
        rtb_Add1_j4 = 8.0F;
      } else if (rtb_TmpSignalConversionAtMultip[0] < 2.0F) {
        rtb_Add1_j4 = 2.0F;
      } else {
        rtb_Add1_j4 = rtb_TmpSignalConversionAtMultip[0];
      }

      /* End of Saturate: '<S82>/Saturation3' */

      /* Product: '<S82>/Multiply' incorporates:
       *  Constant: '<S82>/Constant1'
       *  Sum: '<S82>/Subtract1'
       */
      rtb_Add1_j4 = (rtb_Add1_j4 - 2.0F) * Controller_ConstB.Divide;

      /* Switch: '<S108>/Switch2' incorporates:
       *  RelationalOperator: '<S108>/LowerRelop1'
       */
      if (rtb_Divide_m_idx_0 > rtb_Divide_m_idx_3) {
        rtb_Add_k = rtb_Divide_m_idx_3;
      }

      Controller_B.Multiply[0] = (1.0F - rtb_Add1_j4) * rtb_Add_k + rtb_Add1_j4 *
        Controller_B.Reshape[0];

      /* Switch: '<S108>/Switch2' incorporates:
       *  Constant: '<S82>/Constant3'
       *  Product: '<S82>/Multiply1'
       *  Product: '<S82>/Multiply2'
       *  RelationalOperator: '<S108>/LowerRelop1'
       *  Sum: '<S82>/Sum'
       *  Sum: '<S82>/Sum1'
       */
      if (rtb_Saturation2 > rtb_Saturation_p) {
        rtb_Divide_m_idx_1 = rtb_Saturation_p;
      }

      Controller_B.Multiply[1] = (1.0F - rtb_Add1_j4) * rtb_Divide_m_idx_1 +
        rtb_Add1_j4 * Controller_B.Reshape[1];
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
      /* Switch: '<S108>/Switch2' incorporates:
       *  RelationalOperator: '<S108>/LowerRelop1'
       */
      if (rtb_Divide_m_idx_0 > rtb_Divide_m_idx_3) {
        Controller_B.Multiply[0] = rtb_Divide_m_idx_3;
      } else {
        Controller_B.Multiply[0] = rtb_Add_k;
      }

      if (rtb_Saturation2 > rtb_Saturation_p) {
        Controller_B.Multiply[1] = rtb_Saturation_p;
      } else {
        Controller_B.Multiply[1] = rtb_Divide_m_idx_1;
      }

      Controller_B.Multiply[2] = Controller_U.FMS_Out.psi_rate_cmd;
      break;
    }

    /* End of MultiPortSwitch: '<S80>/Multiport Switch' */

    /* Trigonometry: '<S83>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Sum = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Trigonometry: '<S83>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Add1_j4 = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S83>/Sin' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Saturation_p = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Sum: '<S83>/Add2' incorporates:
     *  Product: '<S83>/Multiply4'
     *  Product: '<S83>/Multiply5'
     *  Trigonometry: '<S83>/Cos'
     *  Trigonometry: '<S83>/Cos1'
     *  Trigonometry: '<S83>/Sin'
     */
    rtb_Divide_m_idx_0 = rtb_Add1_j4 * rtb_Sum * Controller_B.Multiply[2] -
      rtb_Saturation_p * Controller_B.Multiply[1];

    /* Saturate: '<S80>/Saturation' */
    if (rtb_Divide_m_idx_0 > CONTROL_PARAM.MC_R_CMD_LIM) {
      rtb_Divide_m_idx_0 = CONTROL_PARAM.MC_R_CMD_LIM;
    } else {
      if (rtb_Divide_m_idx_0 < -CONTROL_PARAM.MC_R_CMD_LIM) {
        rtb_Divide_m_idx_0 = -CONTROL_PARAM.MC_R_CMD_LIM;
      }
    }

    /* End of Saturate: '<S80>/Saturation' */

    /* Sum: '<S83>/Add' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S83>/Multiply'
     *  Trigonometry: '<S83>/Sin1'
     */
    rtb_Divide_m_idx_2 = Controller_B.Multiply[0] - arm_sin_f32
      (Controller_U.INS_Out.theta) * Controller_B.Multiply[2];

    /* Saturate: '<S80>/Saturation1' */
    if (rtb_Divide_m_idx_2 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_Divide_m_idx_2 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_Divide_m_idx_2 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_Divide_m_idx_2 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    /* End of Saturate: '<S80>/Saturation1' */

    /* Sum: '<S83>/Add1' incorporates:
     *  Product: '<S83>/Multiply1'
     *  Product: '<S83>/Multiply3'
     *  Trigonometry: '<S83>/Cos'
     *  Trigonometry: '<S83>/Cos1'
     *  Trigonometry: '<S83>/Sin'
     */
    rtb_Saturation_p = rtb_Saturation_p * rtb_Sum * Controller_B.Multiply[2] +
      rtb_Add1_j4 * Controller_B.Multiply[1];

    /* Saturate: '<S80>/Saturation2' */
    if (rtb_Saturation_p > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_Saturation_p = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_Saturation_p < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_Saturation_p = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    /* End of Saturate: '<S80>/Saturation2' */

    /* Sum: '<S92>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Add_k = rtb_Divide_m_idx_2 - Controller_U.INS_Out.p;

    /* Saturate: '<S92>/Saturation' */
    if (rtb_Add_k > 3.14159274F) {
      rtb_Add_k = 3.14159274F;
    } else {
      if (rtb_Add_k < -3.14159274F) {
        rtb_Add_k = -3.14159274F;
      }
    }

    /* Sum: '<S92>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_m_idx_1 = rtb_Saturation_p - Controller_U.INS_Out.q;

    /* Saturate: '<S92>/Saturation' */
    if (rtb_Divide_m_idx_1 > 3.14159274F) {
      rtb_Divide_m_idx_1 = 3.14159274F;
    } else {
      if (rtb_Divide_m_idx_1 < -3.14159274F) {
        rtb_Divide_m_idx_1 = -3.14159274F;
      }
    }

    /* Sum: '<S92>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Add2_h = rtb_Divide_m_idx_0 - Controller_U.INS_Out.r;

    /* Saturate: '<S92>/Saturation' */
    if (rtb_Add2_h > 3.14159274F) {
      rtb_Add2_h = 3.14159274F;
    } else {
      if (rtb_Add2_h < -3.14159274F) {
        rtb_Add2_h = -3.14159274F;
      }
    }

    /* DiscreteIntegrator: '<S96>/Discrete-Time Integrator5' incorporates:
     *  Saturate: '<S92>/Saturation'
     */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_c != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0] = rtb_Add_k;
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1] = rtb_Divide_m_idx_1;
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2] = rtb_Add2_h;
    }

    /* DiscreteIntegrator: '<S101>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S96>/Discrete-Time Integrator5'
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

    /* Gain: '<S101>/Gain' incorporates:
     *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator1'
     *  DiscreteIntegrator: '<S96>/Discrete-Time Integrator5'
     *  Sum: '<S101>/Sum5'
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

    /* Switch: '<S101>/Switch' incorporates:
     *  Gain: '<S101>/Gain1'
     *  Inport: '<Root>/FMS_Out'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_Add1_j4 = 0.0F;
      rtb_Divide_m_idx_3 = 0.0F;
      rtb_Saturation2 = 0.0F;
    } else {
      rtb_Add1_j4 = rtb_Multiply_ni[0];
      rtb_Divide_m_idx_3 = rtb_Multiply_ni[1];
      rtb_Saturation2 = rtb_Multiply_ni[2];
    }

    /* End of Switch: '<S101>/Switch' */

    /* Product: '<S98>/Multiply' incorporates:
     *  Constant: '<S98>/gain1'
     */
    rtb_DiscreteTimeIntegrator1_e = CONTROL_PARAM.MC_ROLL_RATE_D * rtb_Add1_j4;

    /* Saturate: '<S98>/Saturation' */
    if (rtb_DiscreteTimeIntegrator1_e > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_DiscreteTimeIntegrator1_e = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_DiscreteTimeIntegrator1_e < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_DiscreteTimeIntegrator1_e = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    rtb_Add1_j4 = rtb_DiscreteTimeIntegrator1_e;

    /* Product: '<S98>/Multiply' incorporates:
     *  Constant: '<S98>/gain2'
     */
    rtb_DiscreteTimeIntegrator1_e = CONTROL_PARAM.MC_PITCH_RATE_D *
      rtb_Divide_m_idx_3;

    /* Saturate: '<S98>/Saturation' */
    if (rtb_DiscreteTimeIntegrator1_e > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_DiscreteTimeIntegrator1_e = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_DiscreteTimeIntegrator1_e < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_DiscreteTimeIntegrator1_e = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    rtb_Divide_m_idx_3 = rtb_DiscreteTimeIntegrator1_e;

    /* Product: '<S98>/Multiply' incorporates:
     *  Constant: '<S98>/gain3'
     */
    rtb_DiscreteTimeIntegrator1_e = CONTROL_PARAM.MC_YAW_RATE_D *
      rtb_Saturation2;

    /* Saturate: '<S98>/Saturation' */
    if (rtb_DiscreteTimeIntegrator1_e > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_DiscreteTimeIntegrator1_e = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_DiscreteTimeIntegrator1_e < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_DiscreteTimeIntegrator1_e = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    /* Sum: '<S94>/Add' incorporates:
     *  Constant: '<S100>/gain1'
     *  Constant: '<S100>/gain2'
     *  Constant: '<S100>/gain3'
     *  DiscreteIntegrator: '<S96>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S99>/Discrete-Time Integrator'
     *  Product: '<S100>/Multiply'
     */
    Controller_B.Multiply[0] = (CONTROL_PARAM.MC_ROLL_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0]) + rtb_Add1_j4;
    Controller_B.Multiply[1] = (CONTROL_PARAM.MC_PITCH_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1]) + rtb_Divide_m_idx_3;
    Controller_B.Multiply[2] = (CONTROL_PARAM.MC_YAW_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[2]) +
      rtb_DiscreteTimeIntegrator1_e;

    /* DeadZone: '<S97>/Dead Zone' */
    if (rtb_Divide_m_idx_2 > 0.1F) {
      rtb_Divide_m_idx_2 -= 0.1F;
    } else if (rtb_Divide_m_idx_2 >= -0.1F) {
      rtb_Divide_m_idx_2 = 0.0F;
    } else {
      rtb_Divide_m_idx_2 -= -0.1F;
    }

    /* Sum: '<S81>/Sum' incorporates:
     *  Gain: '<S93>/Gain'
     *  Gain: '<S97>/Gain'
     */
    Controller_B.Multiply[0] += 1.11111116F * rtb_Divide_m_idx_2 *
      CONTROL_PARAM.MC_ROLL_RATE_FF;

    /* Product: '<S6>/Multiply' incorporates:
     *  DiscreteIntegrator: '<S9>/Discrete-Time Integrator5'
     */
    Controller_B.Multiply[0] *= Controller_DW.DiscreteTimeIntegrator5_DSTATE;

    /* DeadZone: '<S97>/Dead Zone' */
    if (rtb_Saturation_p > 0.1F) {
      rtb_Saturation_p -= 0.1F;
    } else if (rtb_Saturation_p >= -0.1F) {
      rtb_Saturation_p = 0.0F;
    } else {
      rtb_Saturation_p -= -0.1F;
    }

    /* Sum: '<S81>/Sum' incorporates:
     *  Gain: '<S93>/Gain'
     *  Gain: '<S97>/Gain'
     */
    Controller_B.Multiply[1] += 1.11111116F * rtb_Saturation_p *
      CONTROL_PARAM.MC_ROLL_RATE_FF;

    /* Product: '<S6>/Multiply' incorporates:
     *  DiscreteIntegrator: '<S9>/Discrete-Time Integrator5'
     */
    Controller_B.Multiply[1] *= Controller_DW.DiscreteTimeIntegrator5_DSTATE;

    /* DeadZone: '<S97>/Dead Zone' */
    if (rtb_Divide_m_idx_0 > 0.1F) {
      rtb_Divide_m_idx_0 -= 0.1F;
    } else if (rtb_Divide_m_idx_0 >= -0.1F) {
      rtb_Divide_m_idx_0 = 0.0F;
    } else {
      rtb_Divide_m_idx_0 -= -0.1F;
    }

    /* Sum: '<S81>/Sum' incorporates:
     *  Gain: '<S93>/Gain1'
     *  Gain: '<S97>/Gain'
     */
    Controller_B.Multiply[2] += 1.11111116F * rtb_Divide_m_idx_0 *
      CONTROL_PARAM.MC_PITCH_RATE_FF;

    /* Product: '<S6>/Multiply' incorporates:
     *  DiscreteIntegrator: '<S9>/Discrete-Time Integrator5'
     */
    Controller_B.Multiply[2] *= Controller_DW.DiscreteTimeIntegrator5_DSTATE;

    /* Product: '<S122>/Multiply1' incorporates:
     *  Constant: '<S122>/const1'
     *  DiscreteIntegrator: '<S119>/Integrator'
     */
    rtb_Divide_m_idx_3 = Controller_DW.Integrator_DSTATE[0] * 0.05F;
    rtb_Add1_j4 = Controller_DW.Integrator_DSTATE[1] * 0.05F;

    /* Switch: '<S114>/Switch' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    if (rtb_Compare) {
      rtb_Divide_m_idx_2 = Controller_U.FMS_Out.u_cmd;
    } else {
      rtb_Divide_m_idx_2 = rtb_fw_rate_err_B[0];
    }

    /* Sum: '<S122>/Add' incorporates:
     *  DiscreteIntegrator: '<S119>/Integrator1'
     *  Sum: '<S119>/Subtract'
     */
    rtb_Divide_m_idx_0 = (Controller_DW.Integrator1_DSTATE[0] -
                          rtb_Divide_m_idx_2) + rtb_Divide_m_idx_3;

    /* Switch: '<S114>/Switch' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    if (rtb_Compare) {
      rtb_Divide_m_idx_2 = Controller_U.FMS_Out.v_cmd;
    } else {
      rtb_Divide_m_idx_2 = rtb_fw_rate_err_B[1];
    }

    /* Sum: '<S122>/Add' incorporates:
     *  DiscreteIntegrator: '<S119>/Integrator1'
     *  Sum: '<S119>/Subtract'
     */
    rtb_DiscreteTimeIntegrator1_e = (Controller_DW.Integrator1_DSTATE[1] -
      rtb_Divide_m_idx_2) + rtb_Add1_j4;

    /* Signum: '<S122>/Sign' */
    if (rtb_Divide_m_idx_0 < 0.0F) {
      rtb_Divide_m_idx_2 = -1.0F;
    } else if (rtb_Divide_m_idx_0 > 0.0F) {
      rtb_Divide_m_idx_2 = 1.0F;
    } else {
      rtb_Divide_m_idx_2 = rtb_Divide_m_idx_0;
    }

    /* Sum: '<S122>/Add2' incorporates:
     *  Abs: '<S122>/Abs'
     *  Gain: '<S122>/Gain'
     *  Gain: '<S122>/Gain1'
     *  Product: '<S122>/Multiply2'
     *  Product: '<S122>/Multiply3'
     *  Signum: '<S122>/Sign'
     *  Sqrt: '<S122>/Sqrt'
     *  Sum: '<S122>/Add1'
     *  Sum: '<S122>/Subtract'
     */
    rtb_Saturation_p = (sqrtf((8.0F * fabsf(rtb_Divide_m_idx_0) +
      Controller_ConstB.d) * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
      rtb_Divide_m_idx_2 + rtb_Divide_m_idx_3;

    /* Sum: '<S122>/Add3' incorporates:
     *  Signum: '<S122>/Sign'
     */
    rtb_Divide_m_idx_2 = rtb_Divide_m_idx_0 + Controller_ConstB.d;

    /* Sum: '<S122>/Subtract1' incorporates:
     *  Signum: '<S122>/Sign'
     */
    rtb_Saturation2 = rtb_Divide_m_idx_0 - Controller_ConstB.d;

    /* Signum: '<S122>/Sign1' */
    if (rtb_Divide_m_idx_2 < 0.0F) {
      rtb_Divide_m_idx_2 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_2 > 0.0F) {
        rtb_Divide_m_idx_2 = 1.0F;
      }
    }

    /* Signum: '<S122>/Sign2' */
    if (rtb_Saturation2 < 0.0F) {
      rtb_Saturation2 = -1.0F;
    } else {
      if (rtb_Saturation2 > 0.0F) {
        rtb_Saturation2 = 1.0F;
      }
    }

    /* Sum: '<S122>/Add2' incorporates:
     *  Gain: '<S122>/Gain2'
     *  Product: '<S122>/Multiply4'
     *  Signum: '<S122>/Sign'
     *  Sum: '<S122>/Add4'
     *  Sum: '<S122>/Add5'
     *  Sum: '<S122>/Subtract2'
     */
    rtb_Divide_m_idx_3 = ((rtb_Divide_m_idx_0 - rtb_Saturation_p) +
                          rtb_Divide_m_idx_3) * ((rtb_Divide_m_idx_2 -
      rtb_Saturation2) * 0.5F) + rtb_Saturation_p;

    /* Signum: '<S122>/Sign' */
    if (rtb_DiscreteTimeIntegrator1_e < 0.0F) {
      rtb_Divide_m_idx_0 = -1.0F;
    } else if (rtb_DiscreteTimeIntegrator1_e > 0.0F) {
      rtb_Divide_m_idx_0 = 1.0F;
    } else {
      rtb_Divide_m_idx_0 = rtb_DiscreteTimeIntegrator1_e;
    }

    /* Sum: '<S122>/Add2' incorporates:
     *  Abs: '<S122>/Abs'
     *  Gain: '<S122>/Gain'
     *  Gain: '<S122>/Gain1'
     *  Product: '<S122>/Multiply2'
     *  Product: '<S122>/Multiply3'
     *  Signum: '<S122>/Sign'
     *  Sqrt: '<S122>/Sqrt'
     *  Sum: '<S122>/Add1'
     *  Sum: '<S122>/Subtract'
     */
    rtb_Saturation_p = (sqrtf((8.0F * fabsf(rtb_DiscreteTimeIntegrator1_e) +
      Controller_ConstB.d) * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
      rtb_Divide_m_idx_0 + rtb_Add1_j4;

    /* Sum: '<S122>/Add3' incorporates:
     *  Signum: '<S122>/Sign'
     */
    rtb_Divide_m_idx_2 = rtb_DiscreteTimeIntegrator1_e + Controller_ConstB.d;

    /* Sum: '<S122>/Subtract1' incorporates:
     *  Signum: '<S122>/Sign'
     */
    rtb_Saturation2 = rtb_DiscreteTimeIntegrator1_e - Controller_ConstB.d;

    /* Signum: '<S122>/Sign1' */
    if (rtb_Divide_m_idx_2 < 0.0F) {
      rtb_Divide_m_idx_2 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_2 > 0.0F) {
        rtb_Divide_m_idx_2 = 1.0F;
      }
    }

    /* Signum: '<S122>/Sign2' */
    if (rtb_Saturation2 < 0.0F) {
      rtb_Saturation2 = -1.0F;
    } else {
      if (rtb_Saturation2 > 0.0F) {
        rtb_Saturation2 = 1.0F;
      }
    }

    /* Sum: '<S122>/Add5' incorporates:
     *  Gain: '<S122>/Gain2'
     *  Product: '<S122>/Multiply4'
     *  Signum: '<S122>/Sign'
     *  Sum: '<S122>/Add2'
     *  Sum: '<S122>/Add4'
     *  Sum: '<S122>/Subtract2'
     */
    rtb_Saturation_p += ((rtb_DiscreteTimeIntegrator1_e - rtb_Saturation_p) +
                         rtb_Add1_j4) * ((rtb_Divide_m_idx_2 - rtb_Saturation2) *
      0.5F);

    /* RelationalOperator: '<S137>/Compare' incorporates:
     *  Constant: '<S137>/Constant'
     *  Inport: '<Root>/FMS_Out'
     */
    rtb_Compare = (Controller_U.FMS_Out.mode >= 4);

    /* Product: '<S135>/Multiply' incorporates:
     *  DataTypeConversion: '<S135>/Data Type Conversion'
     *  DiscreteIntegrator: '<S138>/Integrator1'
     *  Gain: '<S135>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S135>/Sum1'
     */
    rtb_Saturation2 = -(Controller_DW.Integrator1_DSTATE_e -
                        Controller_U.INS_Out.vd) * (real32_T)rtb_Compare;
    Controller_B.Constant = CONTROL_PARAM.MC_VEL_Z_I_MIN;

    /* DiscreteIntegrator: '<S141>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S141>/Constant'
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

    /* DiscreteIntegrator: '<S143>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_d != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i = rtb_Saturation2;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_Prev_ks != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i = rtb_Saturation2;
    }

    /* Gain: '<S143>/Gain' incorporates:
     *  DiscreteIntegrator: '<S143>/Discrete-Time Integrator1'
     *  Sum: '<S143>/Sum5'
     */
    rtb_DiscreteTimeIntegrator1_e = (rtb_Saturation2 -
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i) * 62.831852F;

    /* Switch: '<S131>/Switch' incorporates:
     *  Bias: '<S131>/Bias'
     *  Constant: '<S133>/Constant'
     *  Gain: '<S131>/Gain'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S133>/Compare'
     */
    if (Controller_U.FMS_Out.ctrl_mode <= 3) {
      rtb_Divide_m_idx_0 = 0.000999987125F * (real32_T)
        Controller_U.FMS_Out.throttle_cmd + -1.0F;
    } else {
      /* Product: '<S134>/Multiply' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S134>/Cos'
       *  Trigonometry: '<S134>/Cos1'
       */
      rtb_Divide_m_idx_0 = arm_cos_f32(Controller_U.INS_Out.phi) * arm_cos_f32
        (Controller_U.INS_Out.theta);

      /* Gain: '<S134>/Gain' */
      rtb_Add1_j4 = 2.0F * rtb_Divide_m_idx_0;

      /* Saturate: '<S134>/Saturation1' */
      if (rtb_Divide_m_idx_0 > 1.0F) {
        rtb_Divide_m_idx_0 = 1.0F;
      } else {
        if (rtb_Divide_m_idx_0 < 0.5F) {
          rtb_Divide_m_idx_0 = 0.5F;
        }
      }

      /* End of Saturate: '<S134>/Saturation1' */

      /* Product: '<S134>/Divide' incorporates:
       *  Constant: '<S134>/Constant'
       */
      rtb_Divide_m_idx_2 = 1.0F / rtb_Divide_m_idx_0;

      /* Switch: '<S143>/Switch' incorporates:
       *  Gain: '<S143>/Gain1'
       */
      if (Controller_U.FMS_Out.reset > 0) {
        rtb_Divide_m_idx_0 = 0.0F;
      } else {
        rtb_Divide_m_idx_0 = rtb_DiscreteTimeIntegrator1_e;
      }

      /* End of Switch: '<S143>/Switch' */

      /* Product: '<S140>/Multiply' incorporates:
       *  Constant: '<S140>/kd'
       */
      rtb_Divide_m_idx_0 *= CONTROL_PARAM.MC_VEL_Z_D;

      /* Saturate: '<S140>/Saturation' */
      if (rtb_Divide_m_idx_0 > CONTROL_PARAM.MC_VEL_Z_D_MAX) {
        rtb_Divide_m_idx_0 = CONTROL_PARAM.MC_VEL_Z_D_MAX;
      } else {
        if (rtb_Divide_m_idx_0 < CONTROL_PARAM.MC_VEL_Z_D_MIN) {
          rtb_Divide_m_idx_0 = CONTROL_PARAM.MC_VEL_Z_D_MIN;
        }
      }

      /* End of Saturate: '<S140>/Saturation' */

      /* Saturate: '<S134>/Saturation' */
      if (rtb_Add1_j4 > 1.0F) {
        rtb_Add1_j4 = 1.0F;
      } else {
        if (rtb_Add1_j4 < 0.0F) {
          rtb_Add1_j4 = 0.0F;
        }
      }

      /* End of Saturate: '<S134>/Saturation' */

      /* Sum: '<S132>/Sum' incorporates:
       *  Constant: '<S132>/hover_throttle'
       *  Constant: '<S142>/kp'
       *  DiscreteIntegrator: '<S141>/Discrete-Time Integrator'
       *  Product: '<S134>/Multiply1'
       *  Product: '<S142>/Multiply'
       *  Sum: '<S136>/Add'
       */
      rtb_Divide_m_idx_0 = ((CONTROL_PARAM.MC_VEL_Z_P * rtb_Saturation2 +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_l) + rtb_Divide_m_idx_0) *
        rtb_Divide_m_idx_2 * rtb_Add1_j4 + CONTROL_PARAM.MC_HOVER_THRO;

      /* Saturate: '<S132>/Saturation' */
      if (rtb_Divide_m_idx_0 > 0.85F) {
        rtb_Divide_m_idx_0 = 0.85F;
      } else {
        if (rtb_Divide_m_idx_0 < 0.25F) {
          rtb_Divide_m_idx_0 = 0.25F;
        }
      }

      /* End of Saturate: '<S132>/Saturation' */
    }

    /* End of Switch: '<S131>/Switch' */

    /* Product: '<S6>/Multiply1' incorporates:
     *  Constant: '<S131>/Constant'
     *  DiscreteIntegrator: '<S9>/Discrete-Time Integrator5'
     */
    Controller_B.Multiply1[0] = 0.0F;
    Controller_B.Multiply1[1] = 0.0F;
    Controller_B.Multiply1[2] = Controller_DW.DiscreteTimeIntegrator5_DSTATE *
      rtb_Divide_m_idx_0;

    /* Product: '<S139>/Multiply1' incorporates:
     *  Constant: '<S139>/const1'
     *  DiscreteIntegrator: '<S138>/Integrator'
     */
    rtb_Divide_m_idx_0 = Controller_DW.Integrator_DSTATE_j * 0.05F;

    /* Switch: '<S135>/Switch' incorporates:
     *  Inport: '<Root>/FMS_Out'
     *  Inport: '<Root>/INS_Out'
     */
    if (rtb_Compare) {
      rtb_Divide_m_idx_2 = Controller_U.FMS_Out.w_cmd;
    } else {
      rtb_Divide_m_idx_2 = Controller_U.INS_Out.vd;
    }

    /* End of Switch: '<S135>/Switch' */

    /* Sum: '<S139>/Add' incorporates:
     *  DiscreteIntegrator: '<S138>/Integrator1'
     *  Sum: '<S138>/Subtract'
     */
    rtb_Sum = (Controller_DW.Integrator1_DSTATE_e - rtb_Divide_m_idx_2) +
      rtb_Divide_m_idx_0;

    /* Signum: '<S139>/Sign' */
    if (rtb_Sum < 0.0F) {
      rtb_Add1_j4 = -1.0F;
    } else if (rtb_Sum > 0.0F) {
      rtb_Add1_j4 = 1.0F;
    } else {
      rtb_Add1_j4 = rtb_Sum;
    }

    /* End of Signum: '<S139>/Sign' */

    /* Sum: '<S139>/Add2' incorporates:
     *  Abs: '<S139>/Abs'
     *  Gain: '<S139>/Gain'
     *  Gain: '<S139>/Gain1'
     *  Product: '<S139>/Multiply2'
     *  Product: '<S139>/Multiply3'
     *  Sqrt: '<S139>/Sqrt'
     *  Sum: '<S139>/Add1'
     *  Sum: '<S139>/Subtract'
     */
    rtb_Add1_j4 = (sqrtf((8.0F * fabsf(rtb_Sum) + Controller_ConstB.d_i) *
                         Controller_ConstB.d_i) - Controller_ConstB.d_i) * 0.5F *
      rtb_Add1_j4 + rtb_Divide_m_idx_0;

    /* Sum: '<S139>/Add4' */
    rtb_Divide_m_idx_0 += rtb_Sum - rtb_Add1_j4;

    /* Sum: '<S139>/Add3' */
    rtb_Divide_m_idx_2 = rtb_Sum + Controller_ConstB.d_i;

    /* Sum: '<S139>/Subtract1' */
    rtb_Sum -= Controller_ConstB.d_i;

    /* Signum: '<S139>/Sign1' */
    if (rtb_Divide_m_idx_2 < 0.0F) {
      rtb_Divide_m_idx_2 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_2 > 0.0F) {
        rtb_Divide_m_idx_2 = 1.0F;
      }
    }

    /* End of Signum: '<S139>/Sign1' */

    /* Signum: '<S139>/Sign2' */
    if (rtb_Sum < 0.0F) {
      rtb_Sum = -1.0F;
    } else {
      if (rtb_Sum > 0.0F) {
        rtb_Sum = 1.0F;
      }
    }

    /* End of Signum: '<S139>/Sign2' */

    /* Sum: '<S139>/Add5' incorporates:
     *  Gain: '<S139>/Gain2'
     *  Product: '<S139>/Multiply4'
     *  Sum: '<S139>/Subtract2'
     */
    rtb_Add1_j4 += (rtb_Divide_m_idx_2 - rtb_Sum) * 0.5F * rtb_Divide_m_idx_0;

    /* Update for DiscreteIntegrator: '<S99>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S99>/gain1'
     *  Constant: '<S99>/gain2'
     *  Constant: '<S99>/gain3'
     *  DiscreteIntegrator: '<S96>/Discrete-Time Integrator5'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S99>/Multiply'
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

    /* End of Update for DiscreteIntegrator: '<S99>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S124>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_PrevRe_p = (int8_T)rtb_Compare_i;

    /* Update for DiscreteIntegrator: '<S126>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;

    /* Update for DiscreteIntegrator: '<S119>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S119>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE[0] += 0.002F *
      Controller_DW.Integrator_DSTATE[0];

    /* Update for DiscreteIntegrator: '<S124>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S124>/ki'
     *  Product: '<S124>/Multiply'
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

    /* Update for DiscreteIntegrator: '<S126>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] += 0.002F *
      rtb_Saturation_bx;

    /* Update for DiscreteIntegrator: '<S119>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S119>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE[1] += 0.002F *
      Controller_DW.Integrator_DSTATE[1];

    /* Update for DiscreteIntegrator: '<S124>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S124>/ki'
     *  Product: '<S124>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1] +=
      CONTROL_PARAM.MC_VEL_XY_I * rtb_Saturation_g * 0.002F;
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

    /* Update for DiscreteIntegrator: '<S126>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] += 0.002F * rtb_Gain_az;
    Controller_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)rtb_Compare_i;

    /* Update for DiscreteIntegrator: '<S96>/Discrete-Time Integrator5' */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_c = 0U;

    /* Update for DiscreteIntegrator: '<S101>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 0U;

    /* Update for DiscreteIntegrator: '<S96>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S96>/Gain'
     *  Saturate: '<S92>/Saturation'
     *  Sum: '<S96>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0] += (rtb_Add_k -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S101>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[0] += 0.002F *
      rtb_Multiply_ni[0];

    /* Update for DiscreteIntegrator: '<S96>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S96>/Gain'
     *  Saturate: '<S92>/Saturation'
     *  Sum: '<S96>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1] += (rtb_Divide_m_idx_1 -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S101>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[1] += 0.002F *
      rtb_Multiply_ni[1];

    /* Update for DiscreteIntegrator: '<S96>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S96>/Gain'
     *  Saturate: '<S92>/Saturation'
     *  Sum: '<S96>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2] += (rtb_Add2_h -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S101>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[2] += 0.002F *
      rtb_Multiply_ni[2];
    Controller_DW.DiscreteTimeIntegrator1_PrevR_k = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Signum: '<S122>/Sign3' incorporates:
     *  Product: '<S122>/Divide'
     *  Sum: '<S122>/Add6'
     */
    rtb_Divide_m_idx_2 = rtb_Divide_m_idx_3 + Controller_ConstB.d;

    /* Signum: '<S122>/Sign4' incorporates:
     *  Product: '<S122>/Divide'
     *  Sum: '<S122>/Subtract3'
     */
    rtb_Add_k = rtb_Divide_m_idx_3 - Controller_ConstB.d;

    /* Signum: '<S122>/Sign5' incorporates:
     *  Product: '<S122>/Divide'
     */
    if (rtb_Divide_m_idx_3 < 0.0F) {
      rtb_Divide_m_idx_0 = -1.0F;
    } else if (rtb_Divide_m_idx_3 > 0.0F) {
      rtb_Divide_m_idx_0 = 1.0F;
    } else {
      rtb_Divide_m_idx_0 = rtb_Divide_m_idx_3;
    }

    /* Signum: '<S122>/Sign3' */
    if (rtb_Divide_m_idx_2 < 0.0F) {
      rtb_Divide_m_idx_2 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_2 > 0.0F) {
        rtb_Divide_m_idx_2 = 1.0F;
      }
    }

    /* Signum: '<S122>/Sign4' */
    if (rtb_Add_k < 0.0F) {
      rtb_Add_k = -1.0F;
    } else {
      if (rtb_Add_k > 0.0F) {
        rtb_Add_k = 1.0F;
      }
    }

    /* Signum: '<S122>/Sign6' incorporates:
     *  Product: '<S122>/Divide'
     */
    if (rtb_Divide_m_idx_3 < 0.0F) {
      rtb_Divide_m_idx_1 = -1.0F;
    } else if (rtb_Divide_m_idx_3 > 0.0F) {
      rtb_Divide_m_idx_1 = 1.0F;
    } else {
      rtb_Divide_m_idx_1 = rtb_Divide_m_idx_3;
    }

    /* Update for DiscreteIntegrator: '<S119>/Integrator' incorporates:
     *  Constant: '<S122>/const'
     *  Gain: '<S122>/Gain3'
     *  Product: '<S122>/Divide'
     *  Product: '<S122>/Multiply5'
     *  Product: '<S122>/Multiply6'
     *  Sum: '<S122>/Subtract4'
     *  Sum: '<S122>/Subtract5'
     *  Sum: '<S122>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE[0] += ((rtb_Divide_m_idx_3 /
      Controller_ConstB.d - rtb_Divide_m_idx_0) * Controller_ConstB.Gain4 *
      ((rtb_Divide_m_idx_2 - rtb_Add_k) * 0.5F) - rtb_Divide_m_idx_1 * 58.836F) *
      0.002F;

    /* Signum: '<S122>/Sign3' incorporates:
     *  Sum: '<S122>/Add6'
     */
    rtb_Divide_m_idx_2 = rtb_Saturation_p + Controller_ConstB.d;

    /* Signum: '<S122>/Sign4' incorporates:
     *  Sum: '<S122>/Subtract3'
     */
    rtb_Add_k = rtb_Saturation_p - Controller_ConstB.d;

    /* Signum: '<S122>/Sign5' */
    if (rtb_Saturation_p < 0.0F) {
      rtb_Divide_m_idx_0 = -1.0F;
    } else if (rtb_Saturation_p > 0.0F) {
      rtb_Divide_m_idx_0 = 1.0F;
    } else {
      rtb_Divide_m_idx_0 = rtb_Saturation_p;
    }

    /* Signum: '<S122>/Sign3' */
    if (rtb_Divide_m_idx_2 < 0.0F) {
      rtb_Divide_m_idx_2 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_2 > 0.0F) {
        rtb_Divide_m_idx_2 = 1.0F;
      }
    }

    /* Signum: '<S122>/Sign4' */
    if (rtb_Add_k < 0.0F) {
      rtb_Add_k = -1.0F;
    } else {
      if (rtb_Add_k > 0.0F) {
        rtb_Add_k = 1.0F;
      }
    }

    /* Signum: '<S122>/Sign6' */
    if (rtb_Saturation_p < 0.0F) {
      rtb_Divide_m_idx_1 = -1.0F;
    } else if (rtb_Saturation_p > 0.0F) {
      rtb_Divide_m_idx_1 = 1.0F;
    } else {
      rtb_Divide_m_idx_1 = rtb_Saturation_p;
    }

    /* Update for DiscreteIntegrator: '<S119>/Integrator' incorporates:
     *  Constant: '<S122>/const'
     *  Gain: '<S122>/Gain3'
     *  Product: '<S122>/Divide'
     *  Product: '<S122>/Multiply5'
     *  Product: '<S122>/Multiply6'
     *  Sum: '<S122>/Subtract4'
     *  Sum: '<S122>/Subtract5'
     *  Sum: '<S122>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE[1] += ((rtb_Saturation_p /
      Controller_ConstB.d - rtb_Divide_m_idx_0) * Controller_ConstB.Gain4 *
      ((rtb_Divide_m_idx_2 - rtb_Add_k) * 0.5F) - rtb_Divide_m_idx_1 * 58.836F) *
      0.002F;

    /* Update for DiscreteIntegrator: '<S138>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S138>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_e += 0.002F *
      Controller_DW.Integrator_DSTATE_j;

    /* Update for DiscreteIntegrator: '<S141>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S141>/ki'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S141>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_l += CONTROL_PARAM.MC_VEL_Z_I *
      rtb_Saturation2 * 0.002F;
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

    /* End of Update for DiscreteIntegrator: '<S141>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S143>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_i += 0.002F *
      rtb_DiscreteTimeIntegrator1_e;
    Controller_DW.DiscreteTimeIntegrator1_Prev_ks = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Signum: '<S139>/Sign6' incorporates:
     *  Signum: '<S139>/Sign5'
     */
    if (rtb_Add1_j4 < 0.0F) {
      rtb_DiscreteTimeIntegrator1_e = -1.0F;

      /* Signum: '<S139>/Sign5' */
      rtb_Divide_m_idx_0 = -1.0F;
    } else if (rtb_Add1_j4 > 0.0F) {
      rtb_DiscreteTimeIntegrator1_e = 1.0F;

      /* Signum: '<S139>/Sign5' */
      rtb_Divide_m_idx_0 = 1.0F;
    } else {
      rtb_DiscreteTimeIntegrator1_e = rtb_Add1_j4;

      /* Signum: '<S139>/Sign5' */
      rtb_Divide_m_idx_0 = rtb_Add1_j4;
    }

    /* End of Signum: '<S139>/Sign6' */

    /* Sum: '<S139>/Add6' */
    rtb_Divide_m_idx_2 = rtb_Add1_j4 + Controller_ConstB.d_i;

    /* Sum: '<S139>/Subtract3' */
    rtb_Add_k = rtb_Add1_j4 - Controller_ConstB.d_i;

    /* Signum: '<S139>/Sign3' */
    if (rtb_Divide_m_idx_2 < 0.0F) {
      rtb_Divide_m_idx_2 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_2 > 0.0F) {
        rtb_Divide_m_idx_2 = 1.0F;
      }
    }

    /* End of Signum: '<S139>/Sign3' */

    /* Signum: '<S139>/Sign4' */
    if (rtb_Add_k < 0.0F) {
      rtb_Add_k = -1.0F;
    } else {
      if (rtb_Add_k > 0.0F) {
        rtb_Add_k = 1.0F;
      }
    }

    /* End of Signum: '<S139>/Sign4' */

    /* Update for DiscreteIntegrator: '<S138>/Integrator' incorporates:
     *  Constant: '<S139>/const'
     *  Gain: '<S139>/Gain3'
     *  Product: '<S139>/Divide'
     *  Product: '<S139>/Multiply5'
     *  Product: '<S139>/Multiply6'
     *  Sum: '<S139>/Subtract4'
     *  Sum: '<S139>/Subtract5'
     *  Sum: '<S139>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE_j += ((rtb_Add1_j4 / Controller_ConstB.d_i -
      rtb_Divide_m_idx_0) * Controller_ConstB.Gain4_p * ((rtb_Divide_m_idx_2 -
      rtb_Add_k) * 0.5F) - rtb_DiscreteTimeIntegrator1_e * 78.448F) * 0.002F;
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

  /* Output and update for atomic system: '<S145>/VTOL1' */
  {
    real32_T rtb_Divide1;
    real32_T rtb_Saturation_ff;
    real32_T rtb_Saturation1_m;
    real32_T rtb_MatrixConcatenate[12];
    real32_T rtb_Saturation5_o[4];
    real32_T rtb_floating_yaw[4];
    real32_T rtb_Saturation_fa[9];
    real32_T rtb_Sum_e[4];
    real32_T rtb_Gain1_lx;
    int32_T i_p;
    real32_T rtb_Saturation1_l_idx_0_p;
    real32_T rtb_Saturation1_l_idx_1_p;
    real32_T rtb_Saturation1_l_idx_2_p;
    uint16_T u0_p;
    real32_T u0_tmp_p;

    /* Saturate: '<S156>/Saturation' incorporates:
     *  Bias: '<S156>/Bias'
     *  Bias: '<S156>/Bias1'
     *  Bias: '<S156>/Bias2'
     *  Bias: '<S156>/Bias3'
     *  Constant: '<S156>/Constant'
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

    /* End of Saturate: '<S156>/Saturation' */

    /* Saturate: '<S149>/Saturation1' */
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

    /* End of Saturate: '<S149>/Saturation1' */

    /* Saturate: '<S149>/Saturation2' */
    if (rtb_Multiply3[2] > 1.0F) {
      rtb_Divide1 = 1.0F;
    } else if (rtb_Multiply3[2] < 0.0F) {
      rtb_Divide1 = 0.0F;
    } else {
      rtb_Divide1 = rtb_Multiply3[2];
    }

    /* End of Saturate: '<S149>/Saturation2' */

    /* Gain: '<S149>/Gain1' incorporates:
     *  Bias: '<S149>/Bias'
     *  Constant: '<S149>/Constant'
     */
    rtb_Gain1_lx = ((real32_T)CONTROL_PARAM.MC_OUT_MAX + -1000.0F) * 0.001F;
    for (i_p = 0; i_p < 4; i_p++) {
      /* Product: '<S149>/Multiply' */
      rtb_Saturation1_m = Controller_ConstB.VTOL1.pq_column[i_p + 4] *
        rtb_Saturation1_l_idx_1_p + Controller_ConstB.VTOL1.pq_column[i_p] *
        rtb_Saturation1_l_idx_0_p;

      /* Sum: '<S149>/Sum' */
      rtb_Sum_e[i_p] = rtb_Saturation1_m + rtb_Divide1;

      /* Product: '<S149>/Multiply' */
      rtb_floating_yaw[i_p] = rtb_Saturation1_m;
    }

    /* Gain: '<S149>/Gain2' incorporates:
     *  Bias: '<S149>/Bias1'
     *  Constant: '<S149>/Constant1'
     */
    rtb_Saturation1_l_idx_0_p = ((real32_T)CONTROL_PARAM.MC_OUT_MIN + -1000.0F) *
      0.001F;

    /* MinMax: '<S149>/Max' */
    rtb_Saturation1_l_idx_1_p = fmaxf(fmaxf(fmaxf(rtb_Sum_e[0], rtb_Sum_e[1]),
      rtb_Sum_e[2]), rtb_Sum_e[3]);

    /* MinMax: '<S149>/Max1' */
    rtb_Saturation1_m = fminf(fminf(fminf(rtb_Sum_e[0], rtb_Sum_e[1]),
      rtb_Sum_e[2]), rtb_Sum_e[3]);

    /* Switch: '<S154>/Switch' incorporates:
     *  Constant: '<S154>/Constant2'
     *  Logic: '<S154>/Logical Operator'
     *  MinMax: '<S149>/Max'
     *  MinMax: '<S149>/Max1'
     *  RelationalOperator: '<S154>/Relational Operator'
     *  RelationalOperator: '<S154>/Relational Operator1'
     */
    if ((rtb_Saturation1_l_idx_1_p > rtb_Gain1_lx) || (rtb_Saturation1_m <
         rtb_Saturation1_l_idx_0_p)) {
      /* Switch: '<S154>/Switch1' incorporates:
       *  Gain: '<S154>/Gain'
       *  RelationalOperator: '<S154>/Relational Operator2'
       *  RelationalOperator: '<S154>/Relational Operator3'
       *  Sum: '<S154>/Add'
       *  Sum: '<S154>/Subtract'
       *  Sum: '<S154>/Subtract1'
       *  Sum: '<S154>/Subtract2'
       *  Sum: '<S154>/Subtract3'
       *  Switch: '<S154>/Switch2'
       */
      if (rtb_Saturation1_l_idx_1_p - rtb_Saturation1_m > rtb_Gain1_lx -
          rtb_Saturation1_l_idx_0_p) {
        rtb_Saturation_ff = ((rtb_Gain1_lx - rtb_Saturation1_l_idx_1_p) +
                             (rtb_Saturation1_l_idx_0_p - rtb_Saturation1_m)) *
          0.5F;
      } else if (rtb_Saturation1_l_idx_1_p > rtb_Gain1_lx) {
        /* Switch: '<S154>/Switch2' incorporates:
         *  Sum: '<S154>/Subtract4'
         */
        rtb_Saturation_ff = rtb_Gain1_lx - rtb_Saturation1_l_idx_1_p;
      } else {
        /* Switch: '<S154>/Switch2' incorporates:
         *  Sum: '<S154>/Subtract5'
         */
        rtb_Saturation_ff = rtb_Saturation1_l_idx_0_p - rtb_Saturation1_m;
      }

      /* End of Switch: '<S154>/Switch1' */
    } else {
      rtb_Saturation_ff = 0.0F;
    }

    /* End of Switch: '<S154>/Switch' */

    /* Saturate: '<S154>/Saturation' */
    if (rtb_Saturation_ff > 0.2F) {
      rtb_Saturation_ff = 0.2F;
    } else {
      if (rtb_Saturation_ff < -0.2F) {
        rtb_Saturation_ff = -0.2F;
      }
    }

    /* End of Saturate: '<S154>/Saturation' */

    /* Sum: '<S149>/Sum1' incorporates:
     *  Sum: '<S154>/Add3'
     */
    u0_tmp_p = rtb_Saturation_ff + rtb_Divide1;

    /* Saturate: '<S149>/Saturation3' incorporates:
     *  Sum: '<S149>/Sum1'
     */
    if (u0_tmp_p > 1.0F) {
      rtb_Divide1 = 1.0F;
    } else if (u0_tmp_p < 0.0F) {
      rtb_Divide1 = 0.0F;
    } else {
      rtb_Divide1 = u0_tmp_p;
    }

    /* End of Saturate: '<S149>/Saturation3' */

    /* MinMax: '<S154>/Min' incorporates:
     *  MinMax: '<S149>/Max'
     *  MinMax: '<S149>/Max1'
     *  Product: '<S154>/Divide'
     *  Product: '<S154>/Divide1'
     *  Sum: '<S154>/Add1'
     *  Sum: '<S154>/Add2'
     *  Sum: '<S154>/Subtract6'
     *  Sum: '<S154>/Subtract7'
     *  Sum: '<S154>/Subtract8'
     *  Sum: '<S154>/Subtract9'
     */
    rtb_Saturation1_m = fminf((rtb_Gain1_lx - u0_tmp_p) /
      ((rtb_Saturation1_l_idx_1_p + rtb_Saturation_ff) - u0_tmp_p), 1.0F /
      (u0_tmp_p - (rtb_Saturation1_m + rtb_Saturation_ff)) * (u0_tmp_p -
      rtb_Saturation1_l_idx_0_p));

    /* Saturate: '<S154>/Saturation1' */
    if (rtb_Saturation1_m > 1.0F) {
      rtb_Saturation1_m = 1.0F;
    } else {
      if (rtb_Saturation1_m < 0.5F) {
        rtb_Saturation1_m = 0.5F;
      }
    }

    /* End of Saturate: '<S154>/Saturation1' */

    /* Saturate: '<S149>/Saturation4' incorporates:
     *  Product: '<S149>/Multiply1'
     *  Sum: '<S149>/Sum2'
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

    /* Sum: '<S149>/Sum3' incorporates:
     *  Product: '<S149>/Multiply2'
     */
    rtb_Sum_e[0] = Controller_ConstB.VTOL1.r_column[0] *
      rtb_Saturation1_l_idx_2_p + rtb_Saturation1_l_idx_1_p;

    /* Saturate: '<S149>/Saturation4' incorporates:
     *  Product: '<S149>/Multiply1'
     *  Sum: '<S149>/Sum2'
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

    /* Sum: '<S149>/Sum3' incorporates:
     *  Product: '<S149>/Multiply2'
     */
    rtb_Sum_e[1] = Controller_ConstB.VTOL1.r_column[1] *
      rtb_Saturation1_l_idx_2_p + rtb_Saturation1_l_idx_1_p;

    /* Saturate: '<S149>/Saturation4' incorporates:
     *  Product: '<S149>/Multiply1'
     *  Sum: '<S149>/Sum2'
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

    /* Sum: '<S149>/Sum3' incorporates:
     *  Product: '<S149>/Multiply2'
     */
    rtb_Sum_e[2] = Controller_ConstB.VTOL1.r_column[2] *
      rtb_Saturation1_l_idx_2_p + rtb_Saturation1_l_idx_1_p;

    /* Saturate: '<S149>/Saturation4' incorporates:
     *  Product: '<S149>/Multiply1'
     *  Sum: '<S149>/Sum2'
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

    /* Sum: '<S149>/Sum3' incorporates:
     *  Product: '<S149>/Multiply2'
     */
    rtb_Sum_e[3] = Controller_ConstB.VTOL1.r_column[3] *
      rtb_Saturation1_l_idx_2_p + rtb_Saturation1_l_idx_1_p;

    /* Saturate: '<S149>/Saturation4' incorporates:
     *  Product: '<S149>/Multiply1'
     */
    rtb_floating_yaw[3] = rtb_Saturation1_l_idx_1_p;

    /* MATLAB Function: '<S149>/R_Remix' */
    Controller_R_Remix(rtb_Sum_e, rtb_Gain1_lx, rtb_Saturation1_l_idx_0_p,
                       rtb_floating_yaw);

    /* MultiPortSwitch: '<S150>/Multiport Switch' incorporates:
     *  Constant: '<S151>/Constant1'
     *  Constant: '<S151>/Constant12'
     *  Constant: '<S151>/Constant2'
     *  Constant: '<S151>/Constant7'
     *  DataTypeConversion: '<S156>/Data Type Conversion'
     *  DataTypeConversion: '<S157>/Data Type Conversion'
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
        /* Saturate: '<S157>/Saturation' incorporates:
         *  Constant: '<S157>/Standby'
         *  Reshape: '<S157>/Reshape'
         */
        if (Controller_ConstP.pooled33[i_p] > 2000.0F) {
          rtb_Saturation1_l_idx_2_p = 2000.0F;
        } else if (Controller_ConstP.pooled33[i_p] < 1000.0F) {
          rtb_Saturation1_l_idx_2_p = 1000.0F;
        } else {
          rtb_Saturation1_l_idx_2_p = Controller_ConstP.pooled33[i_p];
        }

        rtb_VariantMergeForOutportactua[i_p] = (uint16_T)fmodf(floorf
          (rtb_Saturation1_l_idx_2_p), 65536.0F);
      }

      /* Saturate: '<S157>/Saturation' incorporates:
       *  Bias: '<S157>/Bias'
       *  Constant: '<S157>/Constant'
       *  DataTypeConversion: '<S157>/Data Type Conversion'
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

      /* Saturate: '<S157>/Saturation' incorporates:
       *  Bias: '<S157>/Bias1'
       *  Constant: '<S157>/Constant'
       *  DataTypeConversion: '<S157>/Data Type Conversion'
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

      /* Saturate: '<S157>/Saturation' incorporates:
       *  Bias: '<S157>/Bias2'
       *  Constant: '<S157>/Constant'
       *  DataTypeConversion: '<S157>/Data Type Conversion'
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

      /* Saturate: '<S157>/Saturation' incorporates:
       *  Bias: '<S157>/Bias3'
       *  Constant: '<S157>/Constant'
       *  DataTypeConversion: '<S157>/Data Type Conversion'
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

      /* Saturate: '<S148>/Saturation5' incorporates:
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

      /* End of Saturate: '<S148>/Saturation5' */
      for (i_p = 0; i_p < 4; i_p++) {
        /* Bias: '<S148>/Bias' incorporates:
         *  Gain: '<S148>/Gain1'
         *  Product: '<S148>/Multiply1'
         */
        rtb_Saturation5_o[i_p] = 500.0F * (rtb_MatrixConcatenate[i_p + 8] *
          rtb_Saturation1_l_idx_0_p + (rtb_MatrixConcatenate[i_p + 4] *
          rtb_Gain1_lx + rtb_MatrixConcatenate[i_p] * rtb_Saturation1_l_idx_2_p))
          + 1500.0F;

        /* Sum: '<S149>/Sum4' */
        rtb_Saturation1_l_idx_1_p = rtb_Sum_e[i_p] + rtb_floating_yaw[i_p];

        /* Saturate: '<S149>/Saturation5' */
        if (rtb_Saturation1_l_idx_1_p > 1.0F) {
          rtb_Saturation1_l_idx_1_p = 1.0F;
        } else {
          if (rtb_Saturation1_l_idx_1_p < 0.0F) {
            rtb_Saturation1_l_idx_1_p = 0.0F;
          }
        }

        /* End of Saturate: '<S149>/Saturation5' */

        /* DataTypeConversion: '<S149>/Data Type Conversion' incorporates:
         *  Constant: '<S149>/Constant2'
         *  Gain: '<S149>/Gain3'
         *  Sum: '<S149>/Sum5'
         */
        u0_p = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          rtb_Saturation1_l_idx_1_p), 4.2949673E+9F) + 1000U);

        /* Saturate: '<S149>/Saturation' */
        if (u0_p > CONTROL_PARAM.MC_OUT_MAX) {
          rtb_VariantMergeForOutportactua[i_p] = CONTROL_PARAM.MC_OUT_MAX;
        } else if (u0_p < CONTROL_PARAM.MC_OUT_MIN) {
          rtb_VariantMergeForOutportactua[i_p] = CONTROL_PARAM.MC_OUT_MIN;
        } else {
          rtb_VariantMergeForOutportactua[i_p] = u0_p;
        }

        /* End of Saturate: '<S149>/Saturation' */
      }

      /* Saturate: '<S148>/Saturation' */
      if (rtb_Multiply1[0] > 1.0F) {
        rtb_Saturation1_l_idx_2_p = 1.0F;
      } else if (rtb_Multiply1[0] < 0.0F) {
        rtb_Saturation1_l_idx_2_p = 0.0F;
      } else {
        rtb_Saturation1_l_idx_2_p = rtb_Multiply1[0];
      }

      /* End of Saturate: '<S148>/Saturation' */

      /* DataTypeConversion: '<S153>/Data Type Conversion' incorporates:
       *  Constant: '<S153>/Constant1'
       *  Gain: '<S153>/Gain1'
       *  Sum: '<S153>/Sum1'
       */
      u0_p = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
        rtb_Saturation1_l_idx_2_p), 4.2949673E+9F) + 1000U);

      /* Saturate: '<S148>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[4] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[4] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[4] = u0_p;
      }

      /* DataTypeConversion: '<S148>/Data Type Conversion' incorporates:
       *  Bias: '<S148>/Bias1'
       */
      rtb_Saturation1_l_idx_2_p = fmodf(floorf(rtb_Saturation5_o[0] +
        CONTROL_PARAM.SERVO1_BIAS), 65536.0F);
      u0_p = (uint16_T)(rtb_Saturation1_l_idx_2_p < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_l_idx_2_p :
                        (int32_T)(uint16_T)rtb_Saturation1_l_idx_2_p);

      /* Saturate: '<S148>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[5] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[5] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[5] = u0_p;
      }

      /* DataTypeConversion: '<S148>/Data Type Conversion1' incorporates:
       *  Bias: '<S148>/Bias2'
       */
      rtb_Saturation1_l_idx_2_p = fmodf(floorf(rtb_Saturation5_o[1] +
        CONTROL_PARAM.SERVO2_BIAS), 65536.0F);
      u0_p = (uint16_T)(rtb_Saturation1_l_idx_2_p < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_l_idx_2_p :
                        (int32_T)(uint16_T)rtb_Saturation1_l_idx_2_p);

      /* Saturate: '<S148>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[6] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[6] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[6] = u0_p;
      }

      /* DataTypeConversion: '<S148>/Data Type Conversion2' incorporates:
       *  Bias: '<S148>/Bias3'
       */
      rtb_Saturation1_l_idx_2_p = fmodf(floorf(rtb_Saturation5_o[2] +
        CONTROL_PARAM.SERVO3_BIAS), 65536.0F);
      u0_p = (uint16_T)(rtb_Saturation1_l_idx_2_p < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_l_idx_2_p :
                        (int32_T)(uint16_T)rtb_Saturation1_l_idx_2_p);

      /* Saturate: '<S148>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[7] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[7] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[7] = u0_p;
      }

      /* DataTypeConversion: '<S148>/Data Type Conversion3' incorporates:
       *  Bias: '<S148>/Bias4'
       */
      rtb_Saturation1_l_idx_2_p = fmodf(floorf(rtb_Saturation5_o[3] +
        CONTROL_PARAM.SERVO4_BIAS), 65536.0F);
      u0_p = (uint16_T)(rtb_Saturation1_l_idx_2_p < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_l_idx_2_p :
                        (int32_T)(uint16_T)rtb_Saturation1_l_idx_2_p);

      /* Saturate: '<S148>/Saturation1' */
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

  /* Output and update for atomic system: '<S145>/VTOL2' */
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

    /* Saturate: '<S167>/Saturation' incorporates:
     *  Bias: '<S167>/Bias'
     *  Bias: '<S167>/Bias1'
     *  Bias: '<S167>/Bias2'
     *  Bias: '<S167>/Bias3'
     *  Constant: '<S167>/Constant'
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

    /* End of Saturate: '<S167>/Saturation' */

    /* Saturate: '<S159>/Saturation1' */
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

    /* End of Saturate: '<S159>/Saturation1' */

    /* Saturate: '<S159>/Saturation2' */
    if (rtb_Multiply3[2] > 1.0F) {
      rtb_Divide1_o = 1.0F;
    } else if (rtb_Multiply3[2] < 0.0F) {
      rtb_Divide1_o = 0.0F;
    } else {
      rtb_Divide1_o = rtb_Multiply3[2];
    }

    /* End of Saturate: '<S159>/Saturation2' */

    /* Gain: '<S159>/Gain1' incorporates:
     *  Bias: '<S159>/Bias'
     *  Constant: '<S159>/Constant'
     */
    rtb_Gain1_lm = ((real32_T)CONTROL_PARAM.MC_OUT_MAX + -1000.0F) * 0.001F;
    for (i_o = 0; i_o < 4; i_o++) {
      /* Product: '<S159>/Multiply' */
      rtb_Saturation1_i = Controller_ConstB.VTOL2.pq_column[i_o + 4] *
        rtb_Saturation1_p_idx_1_o + Controller_ConstB.VTOL2.pq_column[i_o] *
        rtb_Saturation1_p_idx_0_o;

      /* Sum: '<S159>/Sum' */
      rtb_Sum_m[i_o] = rtb_Saturation1_i + rtb_Divide1_o;

      /* Product: '<S159>/Multiply' */
      rtb_floating_yaw_n[i_o] = rtb_Saturation1_i;
    }

    /* Gain: '<S159>/Gain2' incorporates:
     *  Bias: '<S159>/Bias1'
     *  Constant: '<S159>/Constant1'
     */
    rtb_Saturation1_p_idx_0_o = ((real32_T)CONTROL_PARAM.MC_OUT_MIN + -1000.0F) *
      0.001F;

    /* MinMax: '<S159>/Max' */
    rtb_Saturation1_p_idx_1_o = fmaxf(fmaxf(fmaxf(rtb_Sum_m[0], rtb_Sum_m[1]),
      rtb_Sum_m[2]), rtb_Sum_m[3]);

    /* MinMax: '<S159>/Max1' */
    rtb_Saturation1_i = fminf(fminf(fminf(rtb_Sum_m[0], rtb_Sum_m[1]),
      rtb_Sum_m[2]), rtb_Sum_m[3]);

    /* Switch: '<S164>/Switch' incorporates:
     *  Constant: '<S164>/Constant2'
     *  Logic: '<S164>/Logical Operator'
     *  MinMax: '<S159>/Max'
     *  MinMax: '<S159>/Max1'
     *  RelationalOperator: '<S164>/Relational Operator'
     *  RelationalOperator: '<S164>/Relational Operator1'
     */
    if ((rtb_Saturation1_p_idx_1_o > rtb_Gain1_lm) || (rtb_Saturation1_i <
         rtb_Saturation1_p_idx_0_o)) {
      /* Switch: '<S164>/Switch1' incorporates:
       *  Gain: '<S164>/Gain'
       *  RelationalOperator: '<S164>/Relational Operator2'
       *  RelationalOperator: '<S164>/Relational Operator3'
       *  Sum: '<S164>/Add'
       *  Sum: '<S164>/Subtract'
       *  Sum: '<S164>/Subtract1'
       *  Sum: '<S164>/Subtract2'
       *  Sum: '<S164>/Subtract3'
       *  Switch: '<S164>/Switch2'
       */
      if (rtb_Saturation1_p_idx_1_o - rtb_Saturation1_i > rtb_Gain1_lm -
          rtb_Saturation1_p_idx_0_o) {
        rtb_Saturation_ho = ((rtb_Gain1_lm - rtb_Saturation1_p_idx_1_o) +
                             (rtb_Saturation1_p_idx_0_o - rtb_Saturation1_i)) *
          0.5F;
      } else if (rtb_Saturation1_p_idx_1_o > rtb_Gain1_lm) {
        /* Switch: '<S164>/Switch2' incorporates:
         *  Sum: '<S164>/Subtract4'
         */
        rtb_Saturation_ho = rtb_Gain1_lm - rtb_Saturation1_p_idx_1_o;
      } else {
        /* Switch: '<S164>/Switch2' incorporates:
         *  Sum: '<S164>/Subtract5'
         */
        rtb_Saturation_ho = rtb_Saturation1_p_idx_0_o - rtb_Saturation1_i;
      }

      /* End of Switch: '<S164>/Switch1' */
    } else {
      rtb_Saturation_ho = 0.0F;
    }

    /* End of Switch: '<S164>/Switch' */

    /* Saturate: '<S164>/Saturation' */
    if (rtb_Saturation_ho > 0.2F) {
      rtb_Saturation_ho = 0.2F;
    } else {
      if (rtb_Saturation_ho < -0.2F) {
        rtb_Saturation_ho = -0.2F;
      }
    }

    /* End of Saturate: '<S164>/Saturation' */

    /* Sum: '<S159>/Sum1' incorporates:
     *  Sum: '<S164>/Add3'
     */
    u0_tmp_o = rtb_Saturation_ho + rtb_Divide1_o;

    /* Saturate: '<S159>/Saturation3' incorporates:
     *  Sum: '<S159>/Sum1'
     */
    if (u0_tmp_o > 1.0F) {
      rtb_Divide1_o = 1.0F;
    } else if (u0_tmp_o < 0.0F) {
      rtb_Divide1_o = 0.0F;
    } else {
      rtb_Divide1_o = u0_tmp_o;
    }

    /* End of Saturate: '<S159>/Saturation3' */

    /* MinMax: '<S164>/Min' incorporates:
     *  MinMax: '<S159>/Max'
     *  MinMax: '<S159>/Max1'
     *  Product: '<S164>/Divide'
     *  Product: '<S164>/Divide1'
     *  Sum: '<S164>/Add1'
     *  Sum: '<S164>/Add2'
     *  Sum: '<S164>/Subtract6'
     *  Sum: '<S164>/Subtract7'
     *  Sum: '<S164>/Subtract8'
     *  Sum: '<S164>/Subtract9'
     */
    rtb_Saturation1_i = fminf((rtb_Gain1_lm - u0_tmp_o) /
      ((rtb_Saturation1_p_idx_1_o + rtb_Saturation_ho) - u0_tmp_o), 1.0F /
      (u0_tmp_o - (rtb_Saturation1_i + rtb_Saturation_ho)) * (u0_tmp_o -
      rtb_Saturation1_p_idx_0_o));

    /* Saturate: '<S164>/Saturation1' */
    if (rtb_Saturation1_i > 1.0F) {
      rtb_Saturation1_i = 1.0F;
    } else {
      if (rtb_Saturation1_i < 0.5F) {
        rtb_Saturation1_i = 0.5F;
      }
    }

    /* End of Saturate: '<S164>/Saturation1' */

    /* Saturate: '<S159>/Saturation4' incorporates:
     *  Product: '<S159>/Multiply1'
     *  Sum: '<S159>/Sum2'
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

    /* Sum: '<S159>/Sum3' incorporates:
     *  Product: '<S159>/Multiply2'
     */
    rtb_Sum_m[0] = Controller_ConstB.VTOL2.r_column[0] *
      rtb_Saturation1_p_idx_2_o + rtb_Saturation1_p_idx_1_o;

    /* Saturate: '<S159>/Saturation4' incorporates:
     *  Product: '<S159>/Multiply1'
     *  Sum: '<S159>/Sum2'
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

    /* Sum: '<S159>/Sum3' incorporates:
     *  Product: '<S159>/Multiply2'
     */
    rtb_Sum_m[1] = Controller_ConstB.VTOL2.r_column[1] *
      rtb_Saturation1_p_idx_2_o + rtb_Saturation1_p_idx_1_o;

    /* Saturate: '<S159>/Saturation4' incorporates:
     *  Product: '<S159>/Multiply1'
     *  Sum: '<S159>/Sum2'
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

    /* Sum: '<S159>/Sum3' incorporates:
     *  Product: '<S159>/Multiply2'
     */
    rtb_Sum_m[2] = Controller_ConstB.VTOL2.r_column[2] *
      rtb_Saturation1_p_idx_2_o + rtb_Saturation1_p_idx_1_o;

    /* Saturate: '<S159>/Saturation4' incorporates:
     *  Product: '<S159>/Multiply1'
     *  Sum: '<S159>/Sum2'
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

    /* Sum: '<S159>/Sum3' incorporates:
     *  Product: '<S159>/Multiply2'
     */
    rtb_Sum_m[3] = Controller_ConstB.VTOL2.r_column[3] *
      rtb_Saturation1_p_idx_2_o + rtb_Saturation1_p_idx_1_o;

    /* Saturate: '<S159>/Saturation4' incorporates:
     *  Product: '<S159>/Multiply1'
     */
    rtb_floating_yaw_n[3] = rtb_Saturation1_p_idx_1_o;

    /* MATLAB Function: '<S159>/R_Remix' */
    Controller_R_Remix(rtb_Sum_m, rtb_Gain1_lm, rtb_Saturation1_p_idx_0_o,
                       rtb_floating_yaw_n);

    /* MultiPortSwitch: '<S160>/Multiport Switch' incorporates:
     *  Constant: '<S161>/Constant1'
     *  Constant: '<S161>/Constant11'
     *  Constant: '<S161>/Constant12'
     *  Constant: '<S161>/Constant2'
     *  Constant: '<S161>/Constant7'
     *  Constant: '<S161>/Constant8'
     *  DataTypeConversion: '<S167>/Data Type Conversion'
     *  DataTypeConversion: '<S168>/Data Type Conversion'
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
        /* Saturate: '<S168>/Saturation' incorporates:
         *  Constant: '<S168>/Disarm'
         *  Reshape: '<S168>/Reshape'
         */
        if (Controller_ConstP.pooled33[i_o] > 2000.0F) {
          rtb_Saturation1_p_idx_2_o = 2000.0F;
        } else if (Controller_ConstP.pooled33[i_o] < 1000.0F) {
          rtb_Saturation1_p_idx_2_o = 1000.0F;
        } else {
          rtb_Saturation1_p_idx_2_o = Controller_ConstP.pooled33[i_o];
        }

        rtb_VariantMergeForOutportactua[i_o] = (uint16_T)fmodf(floorf
          (rtb_Saturation1_p_idx_2_o), 65536.0F);
      }

      /* Saturate: '<S168>/Saturation' incorporates:
       *  Bias: '<S168>/Bias'
       *  Constant: '<S168>/Constant'
       *  DataTypeConversion: '<S168>/Data Type Conversion'
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

      /* Saturate: '<S168>/Saturation' incorporates:
       *  Bias: '<S168>/Bias1'
       *  Constant: '<S168>/Constant'
       *  DataTypeConversion: '<S168>/Data Type Conversion'
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

      /* Saturate: '<S168>/Saturation' incorporates:
       *  Bias: '<S168>/Bias2'
       *  Constant: '<S168>/Constant'
       *  DataTypeConversion: '<S168>/Data Type Conversion'
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

      /* Saturate: '<S168>/Saturation' incorporates:
       *  Bias: '<S168>/Bias3'
       *  Constant: '<S168>/Constant'
       *  DataTypeConversion: '<S168>/Data Type Conversion'
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

      /* SignalConversion: '<S161>/ConcatBufferAtVector Concatenate2In2' incorporates:
       *  Constant: '<S161>/Constant10'
       *  Constant: '<S161>/Constant11'
       *  Constant: '<S161>/Constant12'
       */
      rtb_MatrixConcatenate_g[9] = 0.0F;

      /* SignalConversion: '<S161>/ConcatBufferAtVector Concatenate2In1' incorporates:
       *  Constant: '<S161>/Constant9'
       */
      rtb_MatrixConcatenate_g[8] = 0.0F;
      rtb_MatrixConcatenate_g[7] = -CONTROL_PARAM.FW_PITCH_EFFC *
        CONTROL_PARAM.FW_TAIL2_DIR;
      rtb_MatrixConcatenate_g[6] = CONTROL_PARAM.FW_PITCH_EFFC *
        CONTROL_PARAM.FW_TAIL1_DIR;

      /* SignalConversion: '<S161>/ConcatBufferAtVector Concatenate1In2' incorporates:
       *  Constant: '<S161>/Constant6'
       *  Constant: '<S161>/Constant7'
       *  Constant: '<S161>/Constant8'
       */
      rtb_MatrixConcatenate_g[5] = 0.0F;

      /* SignalConversion: '<S161>/ConcatBufferAtVector Concatenate1In1' incorporates:
       *  Constant: '<S161>/Constant5'
       */
      rtb_MatrixConcatenate_g[4] = 0.0F;

      /* SignalConversion: '<S161>/ConcatBufferAtVector ConcatenateIn4' incorporates:
       *  Constant: '<S161>/Constant4'
       */
      rtb_MatrixConcatenate_g[3] = 0.0F;

      /* SignalConversion: '<S161>/ConcatBufferAtVector ConcatenateIn3' incorporates:
       *  Constant: '<S161>/Constant3'
       */
      rtb_MatrixConcatenate_g[2] = 0.0F;
      rtb_MatrixConcatenate_g[1] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON2_DIR;
      rtb_MatrixConcatenate_g[0] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON1_DIR;

      /* Saturate: '<S158>/Saturation5' incorporates:
       *  Constant: '<S161>/Constant1'
       *  Constant: '<S161>/Constant2'
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

      /* End of Saturate: '<S158>/Saturation5' */
      for (i_o = 0; i_o < 4; i_o++) {
        /* Bias: '<S158>/Bias' incorporates:
         *  Gain: '<S158>/Gain1'
         *  Product: '<S158>/Multiply1'
         */
        rtb_Saturation5_m[i_o] = 500.0F * (rtb_MatrixConcatenate_g[i_o + 8] *
          rtb_Saturation1_p_idx_0_o + (rtb_MatrixConcatenate_g[i_o + 4] *
          rtb_Gain1_lm + rtb_MatrixConcatenate_g[i_o] *
          rtb_Saturation1_p_idx_2_o)) + 1500.0F;

        /* Sum: '<S159>/Sum4' */
        rtb_Saturation1_p_idx_1_o = rtb_Sum_m[i_o] + rtb_floating_yaw_n[i_o];

        /* Saturate: '<S159>/Saturation5' */
        if (rtb_Saturation1_p_idx_1_o > 1.0F) {
          rtb_Saturation1_p_idx_1_o = 1.0F;
        } else {
          if (rtb_Saturation1_p_idx_1_o < 0.0F) {
            rtb_Saturation1_p_idx_1_o = 0.0F;
          }
        }

        /* End of Saturate: '<S159>/Saturation5' */

        /* DataTypeConversion: '<S159>/Data Type Conversion' incorporates:
         *  Constant: '<S159>/Constant2'
         *  Gain: '<S159>/Gain3'
         *  Sum: '<S159>/Sum5'
         */
        u0_o = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          rtb_Saturation1_p_idx_1_o), 4.2949673E+9F) + 1000U);

        /* Saturate: '<S159>/Saturation' */
        if (u0_o > CONTROL_PARAM.MC_OUT_MAX) {
          rtb_VariantMergeForOutportactua[i_o] = CONTROL_PARAM.MC_OUT_MAX;
        } else if (u0_o < CONTROL_PARAM.MC_OUT_MIN) {
          rtb_VariantMergeForOutportactua[i_o] = CONTROL_PARAM.MC_OUT_MIN;
        } else {
          rtb_VariantMergeForOutportactua[i_o] = u0_o;
        }

        /* End of Saturate: '<S159>/Saturation' */
      }

      /* Saturate: '<S158>/Saturation4' */
      if (rtb_Multiply1[0] > 1.0F) {
        rtb_Saturation1_p_idx_2_o = 1.0F;
      } else if (rtb_Multiply1[0] < 0.0F) {
        rtb_Saturation1_p_idx_2_o = 0.0F;
      } else {
        rtb_Saturation1_p_idx_2_o = rtb_Multiply1[0];
      }

      /* End of Saturate: '<S158>/Saturation4' */

      /* DataTypeConversion: '<S163>/Data Type Conversion' incorporates:
       *  Constant: '<S163>/Constant1'
       *  Gain: '<S163>/Gain1'
       *  Sum: '<S163>/Sum1'
       */
      u0_o = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
        rtb_Saturation1_p_idx_2_o), 4.2949673E+9F) + 1000U);

      /* Saturate: '<S158>/Saturation1' */
      if (u0_o > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[4] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_o < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[4] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[4] = u0_o;
      }

      /* DataTypeConversion: '<S158>/Data Type Conversion' incorporates:
       *  Bias: '<S158>/Bias1'
       */
      rtb_Saturation1_p_idx_2_o = fmodf(floorf(rtb_Saturation5_m[0] +
        CONTROL_PARAM.SERVO1_BIAS), 65536.0F);
      u0_o = (uint16_T)(rtb_Saturation1_p_idx_2_o < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_p_idx_2_o :
                        (int32_T)(uint16_T)rtb_Saturation1_p_idx_2_o);

      /* Saturate: '<S158>/Saturation1' */
      if (u0_o > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[5] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_o < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[5] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[5] = u0_o;
      }

      /* DataTypeConversion: '<S158>/Data Type Conversion1' incorporates:
       *  Bias: '<S158>/Bias2'
       */
      rtb_Saturation1_p_idx_2_o = fmodf(floorf(rtb_Saturation5_m[1] +
        CONTROL_PARAM.SERVO2_BIAS), 65536.0F);
      u0_o = (uint16_T)(rtb_Saturation1_p_idx_2_o < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_p_idx_2_o :
                        (int32_T)(uint16_T)rtb_Saturation1_p_idx_2_o);

      /* Saturate: '<S158>/Saturation1' */
      if (u0_o > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[6] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_o < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[6] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[6] = u0_o;
      }

      /* DataTypeConversion: '<S158>/Data Type Conversion2' incorporates:
       *  Bias: '<S158>/Bias3'
       */
      rtb_Saturation1_p_idx_2_o = fmodf(floorf(rtb_Saturation5_m[2] +
        CONTROL_PARAM.SERVO3_BIAS), 65536.0F);
      u0_o = (uint16_T)(rtb_Saturation1_p_idx_2_o < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_p_idx_2_o :
                        (int32_T)(uint16_T)rtb_Saturation1_p_idx_2_o);

      /* Saturate: '<S158>/Saturation1' */
      if (u0_o > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[7] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_o < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[7] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[7] = u0_o;
      }

      /* DataTypeConversion: '<S158>/Data Type Conversion3' incorporates:
       *  Bias: '<S158>/Bias4'
       */
      rtb_Saturation1_p_idx_2_o = fmodf(floorf(rtb_Saturation5_m[3] +
        CONTROL_PARAM.SERVO4_BIAS), 65536.0F);
      u0_o = (uint16_T)(rtb_Saturation1_p_idx_2_o < 0.0F ? (int32_T)(uint16_T)
                        -(int16_T)(uint16_T)-rtb_Saturation1_p_idx_2_o :
                        (int32_T)(uint16_T)rtb_Saturation1_p_idx_2_o);

      /* Saturate: '<S158>/Saturation1' */
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

    /* End of MultiPortSwitch: '<S160>/Multiport Switch' */
  }

#endif

  /* End of Outputs for SubSystem: '<S7>/VTOL_Control_Allocation' */

  /* Outport: '<Root>/Control_Out' incorporates:
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   *  Reshape: '<S144>/Reshape'
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

  /* Start for Enabled SubSystem: '<S2>/MC_Controller' */
  /* Start for Constant: '<S141>/Constant' */
  Controller_B.Constant = CONTROL_PARAM.MC_VEL_Z_I_MIN;

  /* End of Start for SubSystem: '<S2>/MC_Controller' */

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
  Controller_DW._DSTATE = 0.25F;

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
  /* InitializeConditions for DiscreteIntegrator: '<S99>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S99>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S124>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_PrevRe_p = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S126>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S96>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_c = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S101>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_k = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S119>/Integrator1' */
  Controller_DW.Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S124>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S119>/Integrator' */
  Controller_DW.Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S119>/Integrator1' */
  Controller_DW.Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S124>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S119>/Integrator' */
  Controller_DW.Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S138>/Integrator1' */
  Controller_DW.Integrator1_DSTATE_e = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S141>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S141>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S143>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 1U;
  Controller_DW.DiscreteTimeIntegrator1_Prev_ks = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S138>/Integrator' */
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
