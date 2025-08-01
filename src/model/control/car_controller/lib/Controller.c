/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.1146
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Aug  1 15:46:08 2025
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
struct_XvtsEoSrVi3a89S22AK4KE CONTROL_PARAM = {
  1.0F,
  1.0F,
  0.0F,
  0.6F,
  -0.6F,
  0.1F,
  -0.1F,
  0.0F,
  0.1F,
  0.0F,
  0.5F,
  -0.5F,
  0.1F,
  -0.1F,
  -500.0F,
  1500U,
  500.0F,
  1500U,
  0.4F
} ;                                    /* Variable: CONTROL_PARAM
                                        * Referenced by:
                                        *   '<S5>/FF'
                                        *   '<S7>/Bias'
                                        *   '<S7>/Bias1'
                                        *   '<S7>/Gain'
                                        *   '<S7>/Gain1'
                                        *   '<S13>/gain1'
                                        *   '<S13>/Saturation'
                                        *   '<S14>/gain1'
                                        *   '<S14>/Discrete-Time Integrator'
                                        *   '<S15>/gain1'
                                        *   '<S23>/gain1'
                                        *   '<S23>/Saturation'
                                        *   '<S24>/gain1'
                                        *   '<S24>/Discrete-Time Integrator'
                                        *   '<S25>/gain1'
                                        */

struct_j3HEuq2gKBtBznker0ckFF CONTROL_EXPORT = {
  10U,

  { 67, 97, 114, 32, 67, 111, 110, 116, 114, 111, 108, 108, 101, 114, 32, 118,
    48, 46, 48, 46, 49, 0 }
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
  real32_T rtb_VectorConcatenate[9];
  real32_T rtb_u_err;
  real32_T rtb_Gain;
  real32_T rtb_r_err;
  real32_T rtb_Gain_f;
  real32_T rtb_Add;
  int32_T i;
  real32_T rtb_VectorConcatenate_0[3];
  real32_T rtb_Saturation_m_idx_0;
  real32_T rtb_Saturation_m_idx_1;
  uint16_T u0;

  /* Trigonometry: '<S22>/Trigonometric Function1' incorporates:
   *  Gain: '<S21>/Gain'
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S22>/Trigonometric Function3'
   */
  rtb_u_err = arm_cos_f32(-Controller_U.INS_Out.psi);
  rtb_VectorConcatenate[0] = rtb_u_err;

  /* Trigonometry: '<S22>/Trigonometric Function' incorporates:
   *  Gain: '<S21>/Gain'
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S22>/Trigonometric Function2'
   */
  rtb_Gain = arm_sin_f32(-Controller_U.INS_Out.psi);
  rtb_VectorConcatenate[1] = rtb_Gain;

  /* SignalConversion: '<S22>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S22>/Constant3'
   */
  rtb_VectorConcatenate[2] = 0.0F;

  /* Gain: '<S22>/Gain' */
  rtb_VectorConcatenate[3] = -rtb_Gain;

  /* Trigonometry: '<S22>/Trigonometric Function3' */
  rtb_VectorConcatenate[4] = rtb_u_err;

  /* SignalConversion: '<S22>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S22>/Constant4'
   */
  rtb_VectorConcatenate[5] = 0.0F;

  /* SignalConversion: '<S22>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate[6] = Controller_ConstB.VectorConcatenate3[0];
  rtb_VectorConcatenate[7] = Controller_ConstB.VectorConcatenate3[1];
  rtb_VectorConcatenate[8] = Controller_ConstB.VectorConcatenate3[2];

  /* Product: '<S20>/Multiply' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  SignalConversion: '<S20>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_0[i] = rtb_VectorConcatenate[i + 3] *
      Controller_U.INS_Out.ve + rtb_VectorConcatenate[i] *
      Controller_U.INS_Out.vn;
  }

  /* End of Product: '<S20>/Multiply' */

  /* Sum: '<S17>/Sum' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  rtb_u_err = Controller_U.FMS_Out.u_cmd - rtb_VectorConcatenate_0[0];

  /* DiscreteIntegrator: '<S24>/Discrete-Time Integrator' incorporates:
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

  /* DiscreteIntegrator: '<S26>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
    Controller_DW.DiscreteTimeIntegrator1_DSTATE = rtb_u_err;
  }

  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevRes != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTATE = rtb_u_err;
  }

  /* Gain: '<S26>/Gain' incorporates:
   *  DiscreteIntegrator: '<S26>/Discrete-Time Integrator1'
   *  Sum: '<S26>/Sum5'
   */
  rtb_Gain = (rtb_u_err - Controller_DW.DiscreteTimeIntegrator1_DSTATE) *
    188.49556F;

  /* Sum: '<S11>/Sum' incorporates:
   *  Inport: '<Root>/FMS_Out'
   *  Inport: '<Root>/INS_Out'
   */
  rtb_r_err = Controller_U.FMS_Out.r_cmd - Controller_U.INS_Out.r;

  /* DiscreteIntegrator: '<S14>/Discrete-Time Integrator' incorporates:
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

  /* DiscreteIntegrator: '<S16>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_i != 0) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_l = rtb_r_err;
  }

  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevR_n != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_l = rtb_r_err;
  }

  /* Gain: '<S16>/Gain' incorporates:
   *  DiscreteIntegrator: '<S16>/Discrete-Time Integrator1'
   *  Sum: '<S16>/Sum5'
   */
  rtb_Gain_f = (rtb_r_err - Controller_DW.DiscreteTimeIntegrator1_DSTAT_l) *
    188.49556F;

  /* Outputs for Atomic SubSystem: '<S4>/Car_1' */
  /* MultiPortSwitch: '<S9>/Multiport Switch' incorporates:
   *  Inport: '<Root>/FMS_Out'
   *  Saturate: '<S8>/Saturation'
   */
  switch (Controller_U.FMS_Out.status) {
   case 1:
    /* Outport: '<Root>/Control_Out' */
    Controller_Y.Control_Out.actuator_cmd[0] = 1500U;
    Controller_Y.Control_Out.actuator_cmd[1] = 1500U;
    break;

   case 2:
    /* Outport: '<Root>/Control_Out' */
    Controller_Y.Control_Out.actuator_cmd[0] = 1500U;
    Controller_Y.Control_Out.actuator_cmd[1] = 1500U;
    break;

   case 3:
    /* Switch: '<S8>/Switch1' incorporates:
     *  Bias: '<S8>/Bias'
     *  Constant: '<S10>/Constant'
     *  Constant: '<S27>/Constant'
     *  DataTypeConversion: '<S8>/Data Type Conversion'
     *  Gain: '<S8>/Gain'
     *  RelationalOperator: '<S10>/Compare'
     *  RelationalOperator: '<S27>/Compare'
     *  Switch: '<S19>/Switch'
     */
    if (Controller_U.FMS_Out.ctrl_mode == 1) {
      rtb_Saturation_m_idx_0 = ((real32_T)Controller_U.FMS_Out.actuator_cmd[0] +
        -1500.0F) * 0.002F;
      rtb_Saturation_m_idx_1 = ((real32_T)Controller_U.FMS_Out.actuator_cmd[1] +
        -1500.0F) * 0.002F;
    } else {
      if (Controller_U.FMS_Out.ctrl_mode >= 5) {
        /* Switch: '<S26>/Switch' incorporates:
         *  Gain: '<S26>/Gain1'
         *  Switch: '<S19>/Switch'
         */
        if (Controller_U.FMS_Out.reset > 0) {
          rtb_Saturation_m_idx_1 = 0.0F;
        } else {
          rtb_Saturation_m_idx_1 = rtb_Gain;
        }

        /* End of Switch: '<S26>/Switch' */

        /* Product: '<S23>/Multiply' incorporates:
         *  Constant: '<S23>/gain1'
         *  Switch: '<S19>/Switch'
         */
        rtb_Add = CONTROL_PARAM.VEL_D * rtb_Saturation_m_idx_1;

        /* Saturate: '<S23>/Saturation' incorporates:
         *  Switch: '<S19>/Switch'
         */
        if (rtb_Add > CONTROL_PARAM.VEL_D_MAX) {
          rtb_Add = CONTROL_PARAM.VEL_D_MAX;
        } else {
          if (rtb_Add < CONTROL_PARAM.VEL_D_MIN) {
            rtb_Add = CONTROL_PARAM.VEL_D_MIN;
          }
        }

        /* End of Saturate: '<S23>/Saturation' */

        /* Sum: '<S18>/Add' incorporates:
         *  Constant: '<S25>/gain1'
         *  DiscreteIntegrator: '<S24>/Discrete-Time Integrator'
         *  Product: '<S25>/Multiply'
         *  Switch: '<S19>/Switch'
         */
        rtb_Add += CONTROL_PARAM.VEL_P * rtb_u_err +
          Controller_DW.DiscreteTimeIntegrator_DSTATE;

        /* Saturate: '<S18>/Saturation' incorporates:
         *  Switch: '<S19>/Switch'
         */
        if (rtb_Add > 1.0F) {
          rtb_Add = 1.0F;
        } else {
          if (rtb_Add < -1.0F) {
            rtb_Add = -1.0F;
          }
        }

        /* End of Saturate: '<S18>/Saturation' */
      } else {
        /* Switch: '<S19>/Switch' */
        rtb_Add = Controller_U.FMS_Out.u_cmd;
      }

      /* Saturate: '<S6>/Saturation' */
      if (rtb_Add > 1.0F) {
        rtb_Saturation_m_idx_0 = 1.0F;
      } else if (rtb_Add < -1.0F) {
        rtb_Saturation_m_idx_0 = -1.0F;
      } else {
        rtb_Saturation_m_idx_0 = rtb_Add;
      }

      /* End of Saturate: '<S6>/Saturation' */

      /* Switch: '<S16>/Switch' incorporates:
       *  Gain: '<S16>/Gain1'
       */
      if (Controller_U.FMS_Out.reset > 0) {
        rtb_Saturation_m_idx_1 = 0.0F;
      } else {
        rtb_Saturation_m_idx_1 = rtb_Gain_f;
      }

      /* End of Switch: '<S16>/Switch' */

      /* Product: '<S13>/Multiply' incorporates:
       *  Constant: '<S13>/gain1'
       */
      rtb_Add = CONTROL_PARAM.R_D * rtb_Saturation_m_idx_1;

      /* Saturate: '<S13>/Saturation' */
      if (rtb_Add > CONTROL_PARAM.R_D_MAX) {
        rtb_Add = CONTROL_PARAM.R_D_MAX;
      } else {
        if (rtb_Add < CONTROL_PARAM.R_D_MIN) {
          rtb_Add = CONTROL_PARAM.R_D_MIN;
        }
      }

      /* End of Saturate: '<S13>/Saturation' */

      /* Sum: '<S12>/Add' incorporates:
       *  Constant: '<S15>/gain1'
       *  DiscreteIntegrator: '<S14>/Discrete-Time Integrator'
       *  Product: '<S15>/Multiply'
       */
      rtb_Add += CONTROL_PARAM.R_P * rtb_r_err +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_k;

      /* Saturate: '<S12>/Saturation' */
      if (rtb_Add > 1.0F) {
        rtb_Add = 1.0F;
      } else {
        if (rtb_Add < -1.0F) {
          rtb_Add = -1.0F;
        }
      }

      /* End of Saturate: '<S12>/Saturation' */

      /* Gain: '<S5>/FF' */
      rtb_Saturation_m_idx_1 = CONTROL_PARAM.R_FF * Controller_U.FMS_Out.r_cmd;

      /* Saturate: '<S5>/Saturation1' */
      if (rtb_Saturation_m_idx_1 > 0.5F) {
        rtb_Saturation_m_idx_1 = 0.5F;
      } else {
        if (rtb_Saturation_m_idx_1 < -0.5F) {
          rtb_Saturation_m_idx_1 = -0.5F;
        }
      }

      /* End of Saturate: '<S5>/Saturation1' */

      /* Sum: '<S5>/Sum' */
      rtb_Saturation_m_idx_1 += rtb_Add;

      /* Saturate: '<S5>/Saturation' */
      if (rtb_Saturation_m_idx_1 > 1.0F) {
        rtb_Saturation_m_idx_1 = 1.0F;
      } else {
        if (rtb_Saturation_m_idx_1 < -1.0F) {
          rtb_Saturation_m_idx_1 = -1.0F;
        }
      }

      /* End of Saturate: '<S5>/Saturation' */
    }

    /* End of Switch: '<S8>/Switch1' */
    rtb_Add = rtb_Saturation_m_idx_0;

    /* Saturate: '<S8>/Saturation' */
    if (rtb_Saturation_m_idx_0 > 1.0F) {
      rtb_Add = 1.0F;
    } else {
      if (rtb_Saturation_m_idx_0 < -1.0F) {
        rtb_Add = -1.0F;
      }
    }

    rtb_Saturation_m_idx_0 = rtb_Add;
    rtb_Add = rtb_Saturation_m_idx_1;

    /* Saturate: '<S8>/Saturation' */
    if (rtb_Saturation_m_idx_1 > 1.0F) {
      rtb_Add = 1.0F;
    } else {
      if (rtb_Saturation_m_idx_1 < -1.0F) {
        rtb_Add = -1.0F;
      }
    }

    /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
     *  Bias: '<S7>/Bias'
     *  Gain: '<S7>/Gain'
     */
    rtb_Saturation_m_idx_1 = fmodf(floorf(CONTROL_PARAM.THROTTLE_SCALE *
      rtb_Saturation_m_idx_0 + (real32_T)CONTROL_PARAM.THROTTLE_BIAS), 65536.0F);
    u0 = (uint16_T)(rtb_Saturation_m_idx_1 < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                    (uint16_T)-rtb_Saturation_m_idx_1 : (int32_T)(uint16_T)
                    rtb_Saturation_m_idx_1);

    /* Saturate: '<S7>/Saturation1' */
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

    /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
     *  Bias: '<S7>/Bias1'
     *  Gain: '<S7>/Gain1'
     */
    rtb_Saturation_m_idx_1 = fmodf(floorf(CONTROL_PARAM.SERVO_SCALE * rtb_Add +
      (real32_T)CONTROL_PARAM.SERVO_BIAS), 65536.0F);
    u0 = (uint16_T)(rtb_Saturation_m_idx_1 < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                    (uint16_T)-rtb_Saturation_m_idx_1 : (int32_T)(uint16_T)
                    rtb_Saturation_m_idx_1);

    /* Saturate: '<S7>/Saturation1' */
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
    break;

   default:
    /* Outport: '<Root>/Control_Out' */
    Controller_Y.Control_Out.actuator_cmd[0] = 1500U;
    Controller_Y.Control_Out.actuator_cmd[1] = 1500U;
    break;
  }

  /* End of MultiPortSwitch: '<S9>/Multiport Switch' */
  /* End of Outputs for SubSystem: '<S4>/Car_1' */

  /* Outport: '<Root>/Control_Out' incorporates:
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   */
  Controller_Y.Control_Out.timestamp =
    Controller_DW.DiscreteTimeIntegrator_DSTATE_f;
  for (i = 0; i < 14; i++) {
    Controller_Y.Control_Out.actuator_cmd[i + 2] = 0U;
  }

  /* Update for DiscreteIntegrator: '<S24>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S24>/gain1'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S24>/Multiply'
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

  /* End of Update for DiscreteIntegrator: '<S24>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S26>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;
  Controller_DW.DiscreteTimeIntegrator1_DSTATE += 0.01F * rtb_Gain;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S14>/gain1'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S14>/Multiply'
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

  /* End of Update for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S16>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_i = 0U;
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_l += 0.01F * rtb_Gain_f;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_n = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S3>/Constant'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_f += CONTROL_EXPORT.period;
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

  /* InitializeConditions for DiscreteIntegrator: '<S24>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S24>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S26>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S16>/Discrete-Time Integrator1' */
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
