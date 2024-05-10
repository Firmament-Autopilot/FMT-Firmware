/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.1113
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri May 10 16:17:26 2024
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
struct_L5ioibiXFlDXzs1YoXn9HB CONTROL_PARAM = {
  2.0F,
  2.0F,
  0.0F,
  0.1F,
  -0.1F,
  0.1F,
  -0.1F,
  5.0F,
  5.0F,
  0.0F,
  0.1F,
  -0.1F,
  0.1F,
  -0.1F
} ;                                    /* Variable: CONTROL_PARAM
                                        * Referenced by:
                                        *   '<S12>/gain1'
                                        *   '<S12>/Saturation'
                                        *   '<S13>/gain1'
                                        *   '<S13>/Discrete-Time Integrator'
                                        *   '<S14>/gain1'
                                        *   '<S21>/gain1'
                                        *   '<S21>/Saturation'
                                        *   '<S22>/gain1'
                                        *   '<S22>/Discrete-Time Integrator'
                                        *   '<S23>/gain1'
                                        */

struct_j3HEuq2gKBtBznker0ckFF CONTROL_EXPORT = {
  10U,

  { 67, 97, 114, 32, 67, 111, 110, 116, 114, 111, 108, 108, 101, 114, 32, 118,
    48, 46, 48, 46, 49, 0 }
} ;                                    /* Variable: CONTROL_EXPORT
                                        * Referenced by: '<S5>/Constant'
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
  real32_T rtb_VectorConcatenate[9];
  real32_T rtb_u_err;
  real32_T rtb_Gain;
  real32_T rtb_r_err;
  real32_T rtb_Gain_f;
  real32_T rtb_Sign;
  real32_T rtb_Saturation_m;
  int32_T i;
  real32_T rtb_VectorConcatenate_0[3];
  uint16_T u0;
  real32_T tmp;

  /* Trigonometry: '<S20>/Trigonometric Function1' incorporates:
   *  Gain: '<S19>/Gain'
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S20>/Trigonometric Function3'
   */
  rtb_u_err = arm_cos_f32(-Controller_U.INS_Out.psi);
  rtb_VectorConcatenate[0] = rtb_u_err;

  /* Trigonometry: '<S20>/Trigonometric Function' incorporates:
   *  Gain: '<S19>/Gain'
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S20>/Trigonometric Function2'
   */
  rtb_Gain = arm_sin_f32(-Controller_U.INS_Out.psi);
  rtb_VectorConcatenate[1] = rtb_Gain;

  /* SignalConversion: '<S20>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S20>/Constant3'
   */
  rtb_VectorConcatenate[2] = 0.0F;

  /* Gain: '<S20>/Gain' */
  rtb_VectorConcatenate[3] = -rtb_Gain;

  /* Trigonometry: '<S20>/Trigonometric Function3' */
  rtb_VectorConcatenate[4] = rtb_u_err;

  /* SignalConversion: '<S20>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S20>/Constant4'
   */
  rtb_VectorConcatenate[5] = 0.0F;

  /* SignalConversion: '<S20>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate[6] = Controller_ConstB.VectorConcatenate3[0];
  rtb_VectorConcatenate[7] = Controller_ConstB.VectorConcatenate3[1];
  rtb_VectorConcatenate[8] = Controller_ConstB.VectorConcatenate3[2];

  /* Product: '<S18>/Multiply' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  SignalConversion: '<S18>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_0[i] = rtb_VectorConcatenate[i + 3] *
      Controller_U.INS_Out.ve + rtb_VectorConcatenate[i] *
      Controller_U.INS_Out.vn;
  }

  /* End of Product: '<S18>/Multiply' */

  /* Sum: '<S16>/Sum' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  rtb_u_err = Controller_U.FMS_Out.u_cmd - rtb_VectorConcatenate_0[0];

  /* DiscreteIntegrator: '<S22>/Discrete-Time Integrator' incorporates:
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

  /* DiscreteIntegrator: '<S24>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
    Controller_DW.DiscreteTimeIntegrator1_DSTATE = rtb_u_err;
  }

  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevRes != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTATE = rtb_u_err;
  }

  /* Gain: '<S24>/Gain' incorporates:
   *  DiscreteIntegrator: '<S24>/Discrete-Time Integrator1'
   *  Sum: '<S24>/Sum5'
   */
  rtb_Gain = (rtb_u_err - Controller_DW.DiscreteTimeIntegrator1_DSTATE) *
    188.49556F;

  /* Sum: '<S10>/Sum' incorporates:
   *  Inport: '<Root>/FMS_Out'
   *  Inport: '<Root>/INS_Out'
   */
  rtb_r_err = Controller_U.FMS_Out.r_cmd - Controller_U.INS_Out.r;

  /* DiscreteIntegrator: '<S13>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator_PrevRe_l != 0)) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_k = Controller_ConstB.Constant_g;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_k >= CONTROL_PARAM.R_I_MAX)
    {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_k = CONTROL_PARAM.R_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_k <= CONTROL_PARAM.R_I_MIN)
      {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_k = CONTROL_PARAM.R_I_MIN;
      }
    }
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_k >= CONTROL_PARAM.R_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_k = CONTROL_PARAM.R_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_k <= CONTROL_PARAM.R_I_MIN)
    {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_k = CONTROL_PARAM.R_I_MIN;
    }
  }

  /* DiscreteIntegrator: '<S15>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_i != 0) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_l = rtb_r_err;
  }

  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevR_n != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_l = rtb_r_err;
  }

  /* Gain: '<S15>/Gain' incorporates:
   *  DiscreteIntegrator: '<S15>/Discrete-Time Integrator1'
   *  Sum: '<S15>/Sum5'
   */
  rtb_Gain_f = (rtb_r_err - Controller_DW.DiscreteTimeIntegrator1_DSTAT_l) *
    188.49556F;

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S3>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  RelationalOperator: '<S3>/Compare'
   */
  if (Controller_U.FMS_Out.status == 3) {
    /* Switch: '<S1>/Switch1' incorporates:
     *  Constant: '<S4>/Constant'
     *  RelationalOperator: '<S4>/Compare'
     *  Switch: '<S24>/Switch'
     */
    if (Controller_U.FMS_Out.ctrl_mode == 1) {
      /* Outport: '<Root>/Control_Out' */
      for (i = 0; i < 16; i++) {
        Controller_Y.Control_Out.actuator_cmd[i] =
          Controller_U.FMS_Out.actuator_cmd[i];
      }
    } else {
      if (Controller_U.FMS_Out.reset > 0) {
        /* Switch: '<S24>/Switch' incorporates:
         *  Gain: '<S24>/Gain1'
         */
        tmp = 0.0F;
      } else {
        /* Switch: '<S24>/Switch' */
        tmp = rtb_Gain;
      }

      /* Product: '<S21>/Multiply' incorporates:
       *  Constant: '<S21>/gain1'
       */
      rtb_Sign = CONTROL_PARAM.VEL_D * tmp;

      /* Saturate: '<S21>/Saturation' */
      if (rtb_Sign > CONTROL_PARAM.VEL_D_MAX) {
        rtb_Sign = CONTROL_PARAM.VEL_D_MAX;
      } else {
        if (rtb_Sign < CONTROL_PARAM.VEL_D_MIN) {
          rtb_Sign = CONTROL_PARAM.VEL_D_MIN;
        }
      }

      /* End of Saturate: '<S21>/Saturation' */

      /* Sum: '<S17>/Add' incorporates:
       *  Constant: '<S23>/gain1'
       *  DiscreteIntegrator: '<S22>/Discrete-Time Integrator'
       *  Product: '<S23>/Multiply'
       */
      rtb_Sign += CONTROL_PARAM.VEL_P * rtb_u_err +
        Controller_DW.DiscreteTimeIntegrator_DSTATE;

      /* Switch: '<S15>/Switch' incorporates:
       *  Gain: '<S15>/Gain1'
       */
      if (Controller_U.FMS_Out.reset > 0) {
        tmp = 0.0F;
      } else {
        tmp = rtb_Gain_f;
      }

      /* End of Switch: '<S15>/Switch' */

      /* Product: '<S12>/Multiply' incorporates:
       *  Constant: '<S12>/gain1'
       */
      rtb_Saturation_m = CONTROL_PARAM.R_D * tmp;

      /* Saturate: '<S12>/Saturation' */
      if (rtb_Saturation_m > CONTROL_PARAM.R_D_MAX) {
        rtb_Saturation_m = CONTROL_PARAM.R_D_MAX;
      } else {
        if (rtb_Saturation_m < CONTROL_PARAM.R_D_MIN) {
          rtb_Saturation_m = CONTROL_PARAM.R_D_MIN;
        }
      }

      /* End of Saturate: '<S12>/Saturation' */

      /* Sum: '<S11>/Add' incorporates:
       *  Constant: '<S14>/gain1'
       *  DiscreteIntegrator: '<S13>/Discrete-Time Integrator'
       *  Product: '<S14>/Multiply'
       */
      rtb_Saturation_m += CONTROL_PARAM.R_P * rtb_r_err +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_k;

      /* Saturate: '<S11>/Saturation' */
      if (rtb_Saturation_m > 1.0F) {
        rtb_Saturation_m = 1.0F;
      } else {
        if (rtb_Saturation_m < -1.0F) {
          rtb_Saturation_m = -1.0F;
        }
      }

      /* End of Saturate: '<S11>/Saturation' */

      /* Saturate: '<S17>/Saturation' */
      if (rtb_Sign > 1.0F) {
        rtb_Sign = 1.0F;
      } else {
        if (rtb_Sign < -1.0F) {
          rtb_Sign = -1.0F;
        }
      }

      /* End of Saturate: '<S17>/Saturation' */

      /* Outputs for Atomic SubSystem: '<S6>/Car_1' */
      /* Gain: '<S9>/Gain' */
      tmp = fmodf(floorf(500.0F * rtb_Sign), 65536.0F);

      /* Bias: '<S9>/Bias' incorporates:
       *  Gain: '<S9>/Gain'
       */
      u0 = (uint16_T)((tmp < 0.0F ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-tmp :
                       (int32_T)(uint16_T)tmp) + 1500U);

      /* Saturate: '<S9>/Saturation' */
      if (u0 > 2000) {
        /* Outport: '<Root>/Control_Out' */
        Controller_Y.Control_Out.actuator_cmd[0] = 2000U;
      } else if (u0 < 1000) {
        /* Outport: '<Root>/Control_Out' */
        Controller_Y.Control_Out.actuator_cmd[0] = 1000U;
      } else {
        /* Outport: '<Root>/Control_Out' */
        Controller_Y.Control_Out.actuator_cmd[0] = u0;
      }

      /* End of Saturate: '<S9>/Saturation' */
      /* End of Outputs for SubSystem: '<S6>/Car_1' */

      /* Signum: '<S7>/Sign' */
      if (Controller_U.FMS_Out.u_cmd < 0.0F) {
        tmp = -1.0F;
      } else if (Controller_U.FMS_Out.u_cmd > 0.0F) {
        tmp = 1.0F;
      } else {
        tmp = Controller_U.FMS_Out.u_cmd;
      }

      /* End of Signum: '<S7>/Sign' */

      /* Outputs for Atomic SubSystem: '<S6>/Car_1' */
      /* Gain: '<S9>/Gain1' incorporates:
       *  Product: '<S7>/Multiply'
       */
      tmp = fmodf(floorf(rtb_Saturation_m * tmp * 500.0F), 65536.0F);

      /* Bias: '<S9>/Bias1' incorporates:
       *  Gain: '<S9>/Gain1'
       */
      u0 = (uint16_T)((tmp < 0.0F ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-tmp :
                       (int32_T)(uint16_T)tmp) + 1500U);

      /* Saturate: '<S9>/Saturation1' */
      if (u0 > 2000) {
        /* Outport: '<Root>/Control_Out' */
        Controller_Y.Control_Out.actuator_cmd[1] = 2000U;
      } else if (u0 < 1000) {
        /* Outport: '<Root>/Control_Out' */
        Controller_Y.Control_Out.actuator_cmd[1] = 1000U;
      } else {
        /* Outport: '<Root>/Control_Out' */
        Controller_Y.Control_Out.actuator_cmd[1] = u0;
      }

      /* End of Saturate: '<S9>/Saturation1' */
      /* End of Outputs for SubSystem: '<S6>/Car_1' */

      /* Outport: '<Root>/Control_Out' */
      for (i = 0; i < 14; i++) {
        Controller_Y.Control_Out.actuator_cmd[i + 2] = 0U;
      }
    }

    /* End of Switch: '<S1>/Switch1' */
  } else {
    /* Outport: '<Root>/Control_Out' */
    for (i = 0; i < 16; i++) {
      Controller_Y.Control_Out.actuator_cmd[i] =
        Controller_U.FMS_Out.actuator_cmd[i];
    }
  }

  /* End of Switch: '<S1>/Switch' */

  /* Outport: '<Root>/Control_Out' incorporates:
   *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator'
   */
  Controller_Y.Control_Out.timestamp =
    Controller_DW.DiscreteTimeIntegrator_DSTATE_b;

  /* Update for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S22>/gain1'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S22>/Multiply'
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

  /* End of Update for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S24>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;
  Controller_DW.DiscreteTimeIntegrator1_DSTATE += 0.01F * rtb_Gain;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S13>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S13>/gain1'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S13>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_k += CONTROL_PARAM.R_I * rtb_r_err
    * 0.01F;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_k >= CONTROL_PARAM.R_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_k = CONTROL_PARAM.R_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_k <= CONTROL_PARAM.R_I_MIN)
    {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_k = CONTROL_PARAM.R_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRe_l = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* End of Update for DiscreteIntegrator: '<S13>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S15>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_i = 0U;
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_l += 0.01F * rtb_Gain_f;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_n = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S5>/Constant'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_b += CONTROL_EXPORT.period;
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

  /* InitializeConditions for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S24>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S13>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_k = Controller_ConstB.Constant_g;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_k >= CONTROL_PARAM.R_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_k = CONTROL_PARAM.R_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_k <= CONTROL_PARAM.R_I_MIN)
    {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_k = CONTROL_PARAM.R_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRe_l = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S13>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S15>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_i = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_n = 0;
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
