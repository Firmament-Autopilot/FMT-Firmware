/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.1188
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Nov 15 11:15:33 2025
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
struct_KPrsn48OrR8nBbHqB69JGB CONTROL_PARAM = {
  0.5F,
  0.1F,
  0.0F,
  0.6F,
  -0.6F,
  0.1F,
  -0.1F,
  0.0F,
  0.2F,
  0.0F,
  2.0F,
  2.0F,
  0.2F,
  0.05F,
  0.0F,
  1.0F,
  -1.0F,
  500.0F,
  1500U,
  500.0F,
  1500U,
  250.0F,
  1500U,
  1.0F,
  -1.0F
} ;                                    /* Variable: CONTROL_PARAM
                                        * Referenced by:
                                        *   '<S7>/Bias'
                                        *   '<S7>/Bias1'
                                        *   '<S7>/Gain'
                                        *   '<S7>/Gain1'
                                        *   '<S7>/Saturation1'
                                        *   '<S7>/Saturation2'
                                        *   '<S8>/Bias'
                                        *   '<S8>/Bias1'
                                        *   '<S8>/Gain'
                                        *   '<S8>/Gain1'
                                        *   '<S8>/Gain2'
                                        *   '<S8>/Saturation1'
                                        *   '<S8>/Saturation2'
                                        *   '<S15>/BW_FF'
                                        *   '<S15>/FW_FF'
                                        *   '<S36>/gain1'
                                        *   '<S36>/Saturation'
                                        *   '<S37>/gain1'
                                        *   '<S37>/Discrete-Time Integrator'
                                        *   '<S38>/gain1'
                                        *   '<S10>/Disarm'
                                        *   '<S10>/Disarm1'
                                        *   '<S11>/Standby'
                                        *   '<S11>/Standby1'
                                        *   '<S13>/Disarm'
                                        *   '<S13>/Disarm1'
                                        *   '<S14>/Standby'
                                        *   '<S14>/Standby1'
                                        *   '<S21>/gain1'
                                        *   '<S22>/gain1'
                                        *   '<S23>/gain1'
                                        *   '<S25>/gain1'
                                        *   '<S26>/gain1'
                                        *   '<S27>/gain1'
                                        */

struct_biZzOMrg0u3lxrb7POOubF CONTROL_EXPORT = {
  10U,

  { 66, 111, 97, 116, 32, 67, 111, 110, 116, 114, 111, 108, 108, 101, 114, 32,
    118, 49, 46, 48, 46, 48, 0 }
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

/* Model step function */
void Controller_step(void)
{
  /* local block i/o variables */
  real32_T rtb_Saturation;
  real32_T rtb_Saturation_g;
  uint16_T rtb_VariantMergeForOutportactua[16];
  real32_T rtb_VectorConcatenate[9];
  real32_T rtb_u_err;
  real32_T rtb_Gain;
  real32_T rtb_Sum;
  real32_T rtb_Gain_h;
  real32_T rtb_Gain_hj;
  int32_T i;
  real32_T rtb_VectorConcatenate_0[3];

  /* Trigonometry: '<S35>/Trigonometric Function1' incorporates:
   *  Gain: '<S34>/Gain'
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S35>/Trigonometric Function3'
   */
  rtb_u_err = arm_cos_f32(-Controller_U.INS_Out.psi);
  rtb_VectorConcatenate[0] = rtb_u_err;

  /* Trigonometry: '<S35>/Trigonometric Function' incorporates:
   *  Gain: '<S34>/Gain'
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S35>/Trigonometric Function2'
   */
  rtb_Gain = arm_sin_f32(-Controller_U.INS_Out.psi);
  rtb_VectorConcatenate[1] = rtb_Gain;

  /* SignalConversion: '<S35>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S35>/Constant3'
   */
  rtb_VectorConcatenate[2] = 0.0F;

  /* Gain: '<S35>/Gain' */
  rtb_VectorConcatenate[3] = -rtb_Gain;

  /* Trigonometry: '<S35>/Trigonometric Function3' */
  rtb_VectorConcatenate[4] = rtb_u_err;

  /* SignalConversion: '<S35>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S35>/Constant4'
   */
  rtb_VectorConcatenate[5] = 0.0F;

  /* SignalConversion: '<S35>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate[6] = Controller_ConstB.VectorConcatenate3[0];
  rtb_VectorConcatenate[7] = Controller_ConstB.VectorConcatenate3[1];
  rtb_VectorConcatenate[8] = Controller_ConstB.VectorConcatenate3[2];

  /* Product: '<S33>/Multiply' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  SignalConversion: '<S33>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_0[i] = rtb_VectorConcatenate[i + 3] *
      Controller_U.INS_Out.ve + rtb_VectorConcatenate[i] *
      Controller_U.INS_Out.vn;
  }

  /* End of Product: '<S33>/Multiply' */

  /* Sum: '<S30>/Sum' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  rtb_u_err = Controller_U.FMS_Out.u_cmd - rtb_VectorConcatenate_0[0];

  /* DiscreteIntegrator: '<S37>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator_PrevRese != 0)) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE = Controller_ConstB.Constant;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE >= CONTROL_PARAM.VEL_I_MAX)
    {
      Controller_DW.DiscreteTimeIntegrator_DSTATE = CONTROL_PARAM.VEL_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE <= CONTROL_PARAM.VEL_I_MIN)
      {
        Controller_DW.DiscreteTimeIntegrator_DSTATE = CONTROL_PARAM.VEL_I_MIN;
      }
    }
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE >= CONTROL_PARAM.VEL_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE = CONTROL_PARAM.VEL_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE <= CONTROL_PARAM.VEL_I_MIN)
    {
      Controller_DW.DiscreteTimeIntegrator_DSTATE = CONTROL_PARAM.VEL_I_MIN;
    }
  }

  /* DiscreteIntegrator: '<S39>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
    Controller_DW.DiscreteTimeIntegrator1_DSTATE = rtb_u_err;
  }

  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevRes != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTATE = rtb_u_err;
  }

  /* Gain: '<S39>/Gain' incorporates:
   *  DiscreteIntegrator: '<S39>/Discrete-Time Integrator1'
   *  Sum: '<S39>/Sum5'
   */
  rtb_Gain = (rtb_u_err - Controller_DW.DiscreteTimeIntegrator1_DSTATE) *
    188.49556F;

  /* Switch: '<S32>/Switch' incorporates:
   *  Constant: '<S40>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  RelationalOperator: '<S40>/Compare'
   */
  if (Controller_U.FMS_Out.ctrl_mode >= 5) {
    /* Switch: '<S39>/Switch' incorporates:
     *  Gain: '<S39>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_Gain_hj = 0.0F;
    } else {
      rtb_Gain_hj = rtb_Gain;
    }

    /* End of Switch: '<S39>/Switch' */

    /* Product: '<S36>/Multiply' incorporates:
     *  Constant: '<S36>/gain1'
     */
    rtb_Saturation_g = CONTROL_PARAM.VEL_D * rtb_Gain_hj;

    /* Saturate: '<S36>/Saturation' */
    if (rtb_Saturation_g > CONTROL_PARAM.VEL_D_MAX) {
      rtb_Saturation_g = CONTROL_PARAM.VEL_D_MAX;
    } else {
      if (rtb_Saturation_g < CONTROL_PARAM.VEL_D_MIN) {
        rtb_Saturation_g = CONTROL_PARAM.VEL_D_MIN;
      }
    }

    /* End of Saturate: '<S36>/Saturation' */

    /* Sum: '<S31>/Add' incorporates:
     *  Constant: '<S38>/gain1'
     *  DiscreteIntegrator: '<S37>/Discrete-Time Integrator'
     *  Product: '<S38>/Multiply'
     */
    rtb_Saturation_g += CONTROL_PARAM.VEL_P * rtb_u_err +
      Controller_DW.DiscreteTimeIntegrator_DSTATE;

    /* Saturate: '<S31>/Saturation' */
    if (rtb_Saturation_g > 1.0F) {
      rtb_Saturation_g = 1.0F;
    } else {
      if (rtb_Saturation_g < -1.0F) {
        rtb_Saturation_g = -1.0F;
      }
    }

    /* End of Saturate: '<S31>/Saturation' */
  } else {
    rtb_Saturation_g = Controller_U.FMS_Out.u_cmd;
  }

  /* End of Switch: '<S32>/Switch' */

  /* Saturate: '<S6>/Saturation' */
  if (rtb_Saturation_g > 1.0F) {
    rtb_Saturation = 1.0F;
  } else if (rtb_Saturation_g < -1.0F) {
    rtb_Saturation = -1.0F;
  } else {
    rtb_Saturation = rtb_Saturation_g;
  }

  /* End of Saturate: '<S6>/Saturation' */

  /* Sum: '<S5>/Sum' incorporates:
   *  Inport: '<Root>/FMS_Out'
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Sum = Controller_U.FMS_Out.r_cmd - Controller_U.INS_Out.r;

  /* Outputs for Enabled SubSystem: '<S16>/Forward' incorporates:
   *  EnablePort: '<S20>/Enable'
   */
  /* RelationalOperator: '<S19>/Compare' incorporates:
   *  Constant: '<S19>/Constant'
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_U.FMS_Out.u_cmd >= 0.0F) {
    if (!Controller_DW.Forward_MODE) {
      /* InitializeConditions for DiscreteIntegrator: '<S26>/Discrete-Time Integrator' */
      Controller_DW.DiscreteTimeIntegrator_DSTATE_f =
        Controller_ConstB.Constant_e;
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_f >= 0.2F) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_f = 0.2F;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_f <= -0.2F) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_f = -0.2F;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_PrevRe_p = 0;

      /* End of InitializeConditions for DiscreteIntegrator: '<S26>/Discrete-Time Integrator' */

      /* InitializeConditions for DiscreteIntegrator: '<S28>/Discrete-Time Integrator1' */
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_c = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevR_b = 0;
      Controller_DW.Forward_MODE = true;
    }

    /* DiscreteIntegrator: '<S26>/Discrete-Time Integrator' */
    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator_PrevRe_p != 0)) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_f =
        Controller_ConstB.Constant_e;
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_f >= 0.2F) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_f = 0.2F;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_f <= -0.2F) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_f = -0.2F;
        }
      }
    }

    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_f >= 0.2F) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_f = 0.2F;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_f <= -0.2F) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_f = -0.2F;
      }
    }

    /* DiscreteIntegrator: '<S28>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_c != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_e = rtb_Sum;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_b != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_e = rtb_Sum;
    }

    /* Gain: '<S28>/Gain' incorporates:
     *  DiscreteIntegrator: '<S28>/Discrete-Time Integrator1'
     *  Sum: '<S28>/Sum5'
     */
    rtb_Gain_h = (rtb_Sum - Controller_DW.DiscreteTimeIntegrator1_DSTAT_e) *
      188.49556F;

    /* Switch: '<S28>/Switch' incorporates:
     *  Gain: '<S28>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_Gain_hj = 0.0F;
    } else {
      rtb_Gain_hj = rtb_Gain_h;
    }

    /* End of Switch: '<S28>/Switch' */

    /* Product: '<S25>/Multiply' incorporates:
     *  Constant: '<S25>/gain1'
     */
    rtb_Gain_hj *= CONTROL_PARAM.FW_PSI_RATE_D;

    /* Saturate: '<S25>/Saturation' */
    if (rtb_Gain_hj > 0.2F) {
      rtb_Gain_hj = 0.2F;
    } else {
      if (rtb_Gain_hj < -0.2F) {
        rtb_Gain_hj = -0.2F;
      }
    }

    /* End of Saturate: '<S25>/Saturation' */

    /* Sum: '<S20>/Add' incorporates:
     *  Constant: '<S27>/gain1'
     *  DiscreteIntegrator: '<S26>/Discrete-Time Integrator'
     *  Product: '<S27>/Multiply'
     */
    Controller_B.Merge = (CONTROL_PARAM.FW_PSI_RATE_P * rtb_Sum +
                          Controller_DW.DiscreteTimeIntegrator_DSTATE_f) +
      rtb_Gain_hj;

    /* Update for DiscreteIntegrator: '<S26>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S26>/gain1'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S26>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_f += CONTROL_PARAM.FW_PSI_RATE_I
      * rtb_Sum * 0.01F;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_f >= 0.2F) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_f = 0.2F;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_f <= -0.2F) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_f = -0.2F;
      }
    }

    Controller_DW.DiscreteTimeIntegrator_PrevRe_p = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* End of Update for DiscreteIntegrator: '<S26>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S28>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_c = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_e += 0.01F * rtb_Gain_h;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_b = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Outputs for Enabled SubSystem: '<S16>/Backward' incorporates:
     *  EnablePort: '<S18>/Enable'
     */
    if (Controller_DW.Backward_MODE) {
      Controller_DW.Backward_MODE = false;
    }

    /* End of Outputs for SubSystem: '<S16>/Backward' */
  } else {
    if (Controller_DW.Forward_MODE) {
      Controller_DW.Forward_MODE = false;
    }

    /* Outputs for Enabled SubSystem: '<S16>/Backward' incorporates:
     *  EnablePort: '<S18>/Enable'
     */
    if (!Controller_DW.Backward_MODE) {
      /* InitializeConditions for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' */
      Controller_DW.DiscreteTimeIntegrator_DSTATE_c =
        Controller_ConstB.Constant_b;
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_c >= 0.2F) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_c = 0.2F;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_c <= -0.2F) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_c = -0.2F;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_PrevRe_m = 0;

      /* End of InitializeConditions for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' */

      /* InitializeConditions for DiscreteIntegrator: '<S24>/Discrete-Time Integrator1' */
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_m = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevR_f = 0;
      Controller_DW.Backward_MODE = true;
    }

    /* DiscreteIntegrator: '<S22>/Discrete-Time Integrator' */
    if ((rtb_Sum != 0.0F) || (Controller_DW.DiscreteTimeIntegrator_PrevRe_m != 0))
    {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_c =
        Controller_ConstB.Constant_b;
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_c >= 0.2F) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_c = 0.2F;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_c <= -0.2F) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_c = -0.2F;
        }
      }
    }

    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_c >= 0.2F) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_c = 0.2F;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_c <= -0.2F) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_c = -0.2F;
      }
    }

    /* DiscreteIntegrator: '<S24>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_m != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_p = rtb_Sum;
    }

    if ((rtb_Sum != 0.0F) || (Controller_DW.DiscreteTimeIntegrator1_PrevR_f != 0))
    {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_p = rtb_Sum;
    }

    /* Gain: '<S24>/Gain' incorporates:
     *  DiscreteIntegrator: '<S24>/Discrete-Time Integrator1'
     *  Sum: '<S24>/Sum5'
     */
    rtb_Gain_hj = (rtb_Sum - Controller_DW.DiscreteTimeIntegrator1_DSTAT_p) *
      188.49556F;

    /* Switch: '<S24>/Switch' incorporates:
     *  Gain: '<S24>/Gain1'
     */
    if (rtb_Sum > 0.0F) {
      rtb_Gain_h = 0.0F;
    } else {
      rtb_Gain_h = rtb_Gain_hj;
    }

    /* End of Switch: '<S24>/Switch' */

    /* Product: '<S21>/Multiply' incorporates:
     *  Constant: '<S21>/gain1'
     */
    rtb_Saturation_g = CONTROL_PARAM.BW_PSI_RATE_D * rtb_Gain_h;

    /* Saturate: '<S21>/Saturation' */
    if (rtb_Saturation_g > 0.2F) {
      rtb_Saturation_g = 0.2F;
    } else {
      if (rtb_Saturation_g < -0.2F) {
        rtb_Saturation_g = -0.2F;
      }
    }

    /* End of Saturate: '<S21>/Saturation' */

    /* Sum: '<S18>/Add' incorporates:
     *  Constant: '<S23>/gain1'
     *  DiscreteIntegrator: '<S22>/Discrete-Time Integrator'
     *  Product: '<S23>/Multiply'
     */
    Controller_B.Merge = (CONTROL_PARAM.BW_PSI_RATE_P * rtb_Sum +
                          Controller_DW.DiscreteTimeIntegrator_DSTATE_c) +
      rtb_Saturation_g;

    /* Update for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S22>/gain1'
     *  DiscreteIntegrator: '<S24>/Discrete-Time Integrator1'
     *  Product: '<S22>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_c += CONTROL_PARAM.BW_PSI_RATE_I
      * rtb_Sum * 0.01F;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_c >= 0.2F) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_c = 0.2F;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_c <= -0.2F) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_c = -0.2F;
      }
    }

    if (rtb_Sum > 0.0F) {
      Controller_DW.DiscreteTimeIntegrator_PrevRe_m = 1;
      Controller_DW.DiscreteTimeIntegrator1_PrevR_f = 1;
    } else {
      if (rtb_Sum < 0.0F) {
        Controller_DW.DiscreteTimeIntegrator_PrevRe_m = -1;
      } else if (rtb_Sum == 0.0F) {
        Controller_DW.DiscreteTimeIntegrator_PrevRe_m = 0;
      } else {
        Controller_DW.DiscreteTimeIntegrator_PrevRe_m = 2;
      }

      if (rtb_Sum < 0.0F) {
        Controller_DW.DiscreteTimeIntegrator1_PrevR_f = -1;
      } else if (rtb_Sum == 0.0F) {
        Controller_DW.DiscreteTimeIntegrator1_PrevR_f = 0;
      } else {
        Controller_DW.DiscreteTimeIntegrator1_PrevR_f = 2;
      }
    }

    /* End of Update for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S24>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_m = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_p += 0.01F * rtb_Gain_hj;

    /* End of Outputs for SubSystem: '<S16>/Backward' */
  }

  /* End of RelationalOperator: '<S19>/Compare' */
  /* End of Outputs for SubSystem: '<S16>/Forward' */

  /* Switch: '<S17>/Switch' incorporates:
   *  Constant: '<S29>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  RelationalOperator: '<S29>/Compare'
   *  Sum: '<S5>/Sum1'
   */
  if (Controller_U.FMS_Out.ctrl_mode >= 3) {
    /* Switch: '<S15>/Switch' incorporates:
     *  Gain: '<S15>/BW_FF'
     *  Gain: '<S15>/FW_FF'
     */
    if (Controller_U.FMS_Out.u_cmd >= 0.0F) {
      rtb_Sum = CONTROL_PARAM.FW_PSI_RATE_FF * Controller_U.FMS_Out.r_cmd;
    } else {
      rtb_Sum = CONTROL_PARAM.BW_PSI_RATE_FF * Controller_U.FMS_Out.r_cmd;
    }

    /* End of Switch: '<S15>/Switch' */

    /* Saturate: '<S15>/Saturation' */
    if (rtb_Sum > 1.0F) {
      rtb_Sum = 1.0F;
    } else {
      if (rtb_Sum < -1.0F) {
        rtb_Sum = -1.0F;
      }
    }

    /* End of Saturate: '<S15>/Saturation' */

    /* Saturate: '<S16>/Saturation' */
    if (Controller_B.Merge > 1.0F) {
      rtb_Gain_hj = 1.0F;
    } else if (Controller_B.Merge < -1.0F) {
      rtb_Gain_hj = -1.0F;
    } else {
      rtb_Gain_hj = Controller_B.Merge;
    }

    /* End of Saturate: '<S16>/Saturation' */
    rtb_Saturation_g = rtb_Sum + rtb_Gain_hj;
  } else {
    rtb_Saturation_g = Controller_U.FMS_Out.r_cmd;
  }

  /* End of Switch: '<S17>/Switch' */

  /* Saturate: '<S5>/Saturation' */
  if (rtb_Saturation_g > 1.0F) {
    rtb_Saturation_g = 1.0F;
  } else {
    if (rtb_Saturation_g < -1.0F) {
      rtb_Saturation_g = -1.0F;
    }
  }

  /* End of Saturate: '<S5>/Saturation' */

  /* Outputs for Atomic SubSystem: '<S2>/Control_Allocation' */
#if AIRFRAME == 1

  /* Output and update for atomic system: '<S4>/Boat_1' */
  {
    real32_T rtb_thruster;
    int32_T i_j;
    real32_T tmp_j;
    uint16_T u0_j;

    /* MultiPortSwitch: '<S9>/Multiport Switch' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    switch (Controller_U.FMS_Out.status) {
     case 1:
      /* Reshape: '<S9>/Reshape' incorporates:
       *  Constant: '<S10>/Disarm'
       *  Constant: '<S10>/Disarm1'
       */
      rtb_VariantMergeForOutportactua[0] = CONTROL_PARAM.THROTTLE_BIAS;
      rtb_VariantMergeForOutportactua[1] = CONTROL_PARAM.SERVO_BIAS;
      break;

     case 2:
      /* Reshape: '<S9>/Reshape' incorporates:
       *  Constant: '<S11>/Standby'
       *  Constant: '<S11>/Standby1'
       */
      rtb_VariantMergeForOutportactua[0] = CONTROL_PARAM.THROTTLE_BIAS;
      rtb_VariantMergeForOutportactua[1] = CONTROL_PARAM.SERVO_BIAS;
      break;

     case 3:
      /* Saturate: '<S7>/Saturation1' */
      if (rtb_Saturation > CONTROL_PARAM.THROTTLE_MAX) {
        rtb_thruster = CONTROL_PARAM.THROTTLE_MAX;
      } else if (rtb_Saturation < CONTROL_PARAM.THROTTLE_MIN) {
        rtb_thruster = CONTROL_PARAM.THROTTLE_MIN;
      } else {
        rtb_thruster = rtb_Saturation;
      }

      /* End of Saturate: '<S7>/Saturation1' */

      /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
       *  Bias: '<S7>/Bias'
       *  Gain: '<S7>/Gain'
       */
      tmp_j = fmodf(floorf(CONTROL_PARAM.THROTTLE_SCALE * rtb_thruster +
                           (real32_T)CONTROL_PARAM.THROTTLE_BIAS), 65536.0F);
      u0_j = (uint16_T)(tmp_j < 0.0F ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
                        -tmp_j : (int32_T)(uint16_T)tmp_j);

      /* Saturate: '<S7>/Saturation' */
      if (u0_j > 2000) {
        /* Reshape: '<S9>/Reshape' */
        rtb_VariantMergeForOutportactua[0] = 2000U;
      } else if (u0_j < 1000) {
        /* Reshape: '<S9>/Reshape' */
        rtb_VariantMergeForOutportactua[0] = 1000U;
      } else {
        /* Reshape: '<S9>/Reshape' */
        rtb_VariantMergeForOutportactua[0] = u0_j;
      }

      /* Signum: '<S7>/Sign' */
      if (rtb_thruster < 0.0F) {
        rtb_thruster = -1.0F;
      } else {
        if (rtb_thruster > 0.0F) {
          rtb_thruster = 1.0F;
        }
      }

      /* End of Signum: '<S7>/Sign' */

      /* Product: '<S7>/Multiply' */
      rtb_thruster *= rtb_Saturation_g;

      /* Saturate: '<S7>/Saturation2' */
      if (rtb_thruster > CONTROL_PARAM.SERVO_MAX) {
        rtb_thruster = CONTROL_PARAM.SERVO_MAX;
      } else {
        if (rtb_thruster < CONTROL_PARAM.SERVO_MIN) {
          rtb_thruster = CONTROL_PARAM.SERVO_MIN;
        }
      }

      /* End of Saturate: '<S7>/Saturation2' */

      /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
       *  Bias: '<S7>/Bias1'
       *  Gain: '<S7>/Gain1'
       */
      tmp_j = fmodf(floorf(CONTROL_PARAM.SERVO_SCALE * rtb_thruster + (real32_T)
                           CONTROL_PARAM.SERVO_BIAS), 65536.0F);
      u0_j = (uint16_T)(tmp_j < 0.0F ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
                        -tmp_j : (int32_T)(uint16_T)tmp_j);

      /* Saturate: '<S7>/Saturation' */
      if (u0_j > 2000) {
        /* Reshape: '<S9>/Reshape' */
        rtb_VariantMergeForOutportactua[1] = 2000U;
      } else if (u0_j < 1000) {
        /* Reshape: '<S9>/Reshape' */
        rtb_VariantMergeForOutportactua[1] = 1000U;
      } else {
        /* Reshape: '<S9>/Reshape' */
        rtb_VariantMergeForOutportactua[1] = u0_j;
      }
      break;

     default:
      /* Reshape: '<S9>/Reshape' incorporates:
       *  Constant: '<S10>/Disarm'
       *  Constant: '<S10>/Disarm1'
       */
      rtb_VariantMergeForOutportactua[0] = CONTROL_PARAM.THROTTLE_BIAS;
      rtb_VariantMergeForOutportactua[1] = CONTROL_PARAM.SERVO_BIAS;
      break;
    }

    /* End of MultiPortSwitch: '<S9>/Multiport Switch' */

    /* Reshape: '<S9>/Reshape' */
    for (i_j = 0; i_j < 14; i_j++) {
      rtb_VariantMergeForOutportactua[i_j + 2] = 0U;
    }
  }

#elif AIRFRAME == 2

  /* Output and update for atomic system: '<S4>/Boat_2' */
  {
    real32_T rtb_Saturation1;
    real32_T rtb_thruster1;
    int32_T i_e;
    real32_T u0_e;

    /* MultiPortSwitch: '<S12>/Multiport Switch' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    switch (Controller_U.FMS_Out.status) {
     case 1:
      /* Reshape: '<S12>/Reshape' incorporates:
       *  Constant: '<S13>/Disarm'
       *  Constant: '<S13>/Disarm1'
       */
      rtb_VariantMergeForOutportactua[0] = CONTROL_PARAM.THROTTLE_BIAS;
      rtb_VariantMergeForOutportactua[1] = CONTROL_PARAM.THROTTLE2_BIAS;
      break;

     case 2:
      /* Reshape: '<S12>/Reshape' incorporates:
       *  Constant: '<S14>/Standby'
       *  Constant: '<S14>/Standby1'
       */
      rtb_VariantMergeForOutportactua[0] = CONTROL_PARAM.THROTTLE_BIAS;
      rtb_VariantMergeForOutportactua[1] = CONTROL_PARAM.THROTTLE2_BIAS;
      break;

     case 3:
      /* Saturate: '<S8>/Saturation1' */
      if (rtb_Saturation > CONTROL_PARAM.THROTTLE_MAX) {
        rtb_Saturation1 = CONTROL_PARAM.THROTTLE_MAX;
      } else if (rtb_Saturation < CONTROL_PARAM.THROTTLE_MIN) {
        rtb_Saturation1 = CONTROL_PARAM.THROTTLE_MIN;
      } else {
        rtb_Saturation1 = rtb_Saturation;
      }

      /* End of Saturate: '<S8>/Saturation1' */

      /* Saturate: '<S8>/Saturation2' */
      if (rtb_Saturation_g > CONTROL_PARAM.SERVO_MAX) {
        rtb_thruster1 = CONTROL_PARAM.SERVO_MAX;
      } else if (rtb_Saturation_g < CONTROL_PARAM.SERVO_MIN) {
        rtb_thruster1 = CONTROL_PARAM.SERVO_MIN;
      } else {
        rtb_thruster1 = rtb_Saturation_g;
      }

      /* End of Saturate: '<S8>/Saturation2' */

      /* Gain: '<S8>/Gain1' */
      rtb_thruster1 *= CONTROL_PARAM.SERVO_SCALE;

      /* Bias: '<S8>/Bias' incorporates:
       *  Gain: '<S8>/Gain'
       *  Sum: '<S8>/Add'
       */
      u0_e = (CONTROL_PARAM.THROTTLE_SCALE * rtb_Saturation1 + rtb_thruster1) +
        (real32_T)CONTROL_PARAM.THROTTLE_BIAS;

      /* Saturate: '<S8>/Saturation' */
      if (u0_e > 2000.0F) {
        u0_e = 2000.0F;
      } else {
        if (u0_e < 1000.0F) {
          u0_e = 1000.0F;
        }
      }

      /* Reshape: '<S12>/Reshape' incorporates:
       *  DataTypeConversion: '<S8>/Data Type Conversion'
       */
      rtb_VariantMergeForOutportactua[0] = (uint16_T)fmodf(floorf(u0_e),
        65536.0F);

      /* Bias: '<S8>/Bias1' incorporates:
       *  Gain: '<S8>/Gain2'
       *  Sum: '<S8>/Add1'
       */
      u0_e = (CONTROL_PARAM.THROTTLE2_SCALE * rtb_Saturation1 - rtb_thruster1) +
        (real32_T)CONTROL_PARAM.THROTTLE2_BIAS;

      /* Saturate: '<S8>/Saturation' */
      if (u0_e > 2000.0F) {
        u0_e = 2000.0F;
      } else {
        if (u0_e < 1000.0F) {
          u0_e = 1000.0F;
        }
      }

      /* Reshape: '<S12>/Reshape' incorporates:
       *  DataTypeConversion: '<S8>/Data Type Conversion'
       */
      rtb_VariantMergeForOutportactua[1] = (uint16_T)fmodf(floorf(u0_e),
        65536.0F);
      break;

     default:
      /* Reshape: '<S12>/Reshape' incorporates:
       *  Constant: '<S13>/Disarm'
       *  Constant: '<S13>/Disarm1'
       */
      rtb_VariantMergeForOutportactua[0] = CONTROL_PARAM.THROTTLE_BIAS;
      rtb_VariantMergeForOutportactua[1] = CONTROL_PARAM.THROTTLE2_BIAS;
      break;
    }

    /* End of MultiPortSwitch: '<S12>/Multiport Switch' */

    /* Reshape: '<S12>/Reshape' */
    for (i_e = 0; i_e < 14; i_e++) {
      rtb_VariantMergeForOutportactua[i_e + 2] = 0U;
    }
  }

#endif

  /* End of Outputs for SubSystem: '<S2>/Control_Allocation' */

  /* Outport: '<Root>/Control_Out' incorporates:
   *  BusAssignment: '<S1>/Bus Assignment'
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   */
  Controller_Y.Control_Out.timestamp =
    Controller_DW.DiscreteTimeIntegrator_DSTATE_i;
  for (i = 0; i < 16; i++) {
    Controller_Y.Control_Out.actuator_cmd[i] = rtb_VariantMergeForOutportactua[i];
  }

  /* End of Outport: '<Root>/Control_Out' */

  /* Update for DiscreteIntegrator: '<S37>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S37>/gain1'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S37>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE += CONTROL_PARAM.VEL_I * rtb_u_err
    * 0.01F;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE >= CONTROL_PARAM.VEL_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE = CONTROL_PARAM.VEL_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE <= CONTROL_PARAM.VEL_I_MIN)
    {
      Controller_DW.DiscreteTimeIntegrator_DSTATE = CONTROL_PARAM.VEL_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* End of Update for DiscreteIntegrator: '<S37>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S39>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;
  Controller_DW.DiscreteTimeIntegrator1_DSTATE += 0.01F * rtb_Gain;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S3>/Constant'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_i += CONTROL_EXPORT.period;
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

  /* InitializeConditions for DiscreteIntegrator: '<S37>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE = Controller_ConstB.Constant;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE >= CONTROL_PARAM.VEL_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE = CONTROL_PARAM.VEL_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE <= CONTROL_PARAM.VEL_I_MIN)
    {
      Controller_DW.DiscreteTimeIntegrator_DSTATE = CONTROL_PARAM.VEL_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRese = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S37>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S39>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* SystemInitialize for Enabled SubSystem: '<S16>/Forward' */
  /* InitializeConditions for DiscreteIntegrator: '<S26>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_f = Controller_ConstB.Constant_e;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_f >= 0.2F) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_f = 0.2F;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_f <= -0.2F) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_f = -0.2F;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRe_p = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S26>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S28>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_c = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_b = 0;

  /* End of SystemInitialize for SubSystem: '<S16>/Forward' */

  /* SystemInitialize for Enabled SubSystem: '<S16>/Backward' */
  /* InitializeConditions for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_c = Controller_ConstB.Constant_b;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_c >= 0.2F) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_c = 0.2F;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_c <= -0.2F) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_c = -0.2F;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRe_m = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S24>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_m = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_f = 0;

  /* End of SystemInitialize for SubSystem: '<S16>/Backward' */
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
