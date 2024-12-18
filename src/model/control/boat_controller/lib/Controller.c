/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.1136
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Dec 12 10:15:20 2024
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
struct_pNbTadB0jgRVqt3p6wG0lB CONTROL_PARAM = {
  0.5F,
  0.1F,
  0.0F,
  0.2F,
  -0.2F,
  0.1F,
  -0.1F,
  1.0F,
  1000.0F,
  1000U,
  250.0F,
  1500U
} ;                                    /* Variable: CONTROL_PARAM
                                        * Referenced by:
                                        *   '<S5>/Gain'
                                        *   '<S7>/Bias'
                                        *   '<S7>/Bias1'
                                        *   '<S7>/Gain'
                                        *   '<S7>/Gain1'
                                        *   '<S17>/gain1'
                                        *   '<S17>/Saturation'
                                        *   '<S18>/gain1'
                                        *   '<S18>/Discrete-Time Integrator'
                                        *   '<S19>/gain1'
                                        *   '<S9>/Disarm'
                                        *   '<S9>/Disarm1'
                                        *   '<S10>/Standby'
                                        *   '<S10>/Standby1'
                                        */

struct_biZzOMrg0u3lxrb7POOubF CONTROL_EXPORT = {
  10U,

  { 66, 111, 97, 116, 32, 67, 111, 110, 116, 114, 111, 108, 108, 101, 114, 32,
    118, 48, 46, 48, 46, 49, 0 }
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
  real32_T rtb_Add;
  int32_T i;
  real32_T rtb_VectorConcatenate_0[3];
  uint16_T u0;

  /* Trigonometry: '<S16>/Trigonometric Function1' incorporates:
   *  Gain: '<S15>/Gain'
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S16>/Trigonometric Function3'
   */
  rtb_u_err = arm_cos_f32(-Controller_U.INS_Out.psi);
  rtb_VectorConcatenate[0] = rtb_u_err;

  /* Trigonometry: '<S16>/Trigonometric Function' incorporates:
   *  Gain: '<S15>/Gain'
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S16>/Trigonometric Function2'
   */
  rtb_Gain = arm_sin_f32(-Controller_U.INS_Out.psi);
  rtb_VectorConcatenate[1] = rtb_Gain;

  /* SignalConversion: '<S16>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S16>/Constant3'
   */
  rtb_VectorConcatenate[2] = 0.0F;

  /* Gain: '<S16>/Gain' */
  rtb_VectorConcatenate[3] = -rtb_Gain;

  /* Trigonometry: '<S16>/Trigonometric Function3' */
  rtb_VectorConcatenate[4] = rtb_u_err;

  /* SignalConversion: '<S16>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S16>/Constant4'
   */
  rtb_VectorConcatenate[5] = 0.0F;

  /* SignalConversion: '<S16>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate[6] = Controller_ConstB.VectorConcatenate3[0];
  rtb_VectorConcatenate[7] = Controller_ConstB.VectorConcatenate3[1];
  rtb_VectorConcatenate[8] = Controller_ConstB.VectorConcatenate3[2];

  /* Product: '<S14>/Multiply' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  SignalConversion: '<S14>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_0[i] = rtb_VectorConcatenate[i + 3] *
      Controller_U.INS_Out.ve + rtb_VectorConcatenate[i] *
      Controller_U.INS_Out.vn;
  }

  /* End of Product: '<S14>/Multiply' */

  /* Sum: '<S11>/Sum' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  rtb_u_err = Controller_U.FMS_Out.u_cmd - rtb_VectorConcatenate_0[0];

  /* DiscreteIntegrator: '<S18>/Discrete-Time Integrator' incorporates:
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

  /* DiscreteIntegrator: '<S20>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
    Controller_DW.DiscreteTimeIntegrator1_DSTATE = rtb_u_err;
  }

  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevRes != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTATE = rtb_u_err;
  }

  /* Gain: '<S20>/Gain' incorporates:
   *  DiscreteIntegrator: '<S20>/Discrete-Time Integrator1'
   *  Sum: '<S20>/Sum5'
   */
  rtb_Gain = (rtb_u_err - Controller_DW.DiscreteTimeIntegrator1_DSTATE) *
    188.49556F;

  /* Outputs for Atomic SubSystem: '<S4>/Boat_1' */
  /* MultiPortSwitch: '<S8>/Multiport Switch' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  switch (Controller_U.FMS_Out.status) {
   case 1:
    /* Outport: '<Root>/Control_Out' incorporates:
     *  Constant: '<S9>/Disarm'
     *  Constant: '<S9>/Disarm1'
     */
    Controller_Y.Control_Out.actuator_cmd[0] = CONTROL_PARAM.THROTTLE_BIAS;
    Controller_Y.Control_Out.actuator_cmd[1] = CONTROL_PARAM.SERVO_BIAS;
    break;

   case 2:
    /* Outport: '<Root>/Control_Out' incorporates:
     *  Constant: '<S10>/Standby'
     *  Constant: '<S10>/Standby1'
     */
    Controller_Y.Control_Out.actuator_cmd[0] = CONTROL_PARAM.THROTTLE_BIAS;
    Controller_Y.Control_Out.actuator_cmd[1] = CONTROL_PARAM.SERVO_BIAS;
    break;

   case 3:
    /* Switch: '<S13>/Switch' incorporates:
     *  Bias: '<S13>/Bias'
     *  Constant: '<S21>/Constant'
     *  Gain: '<S13>/Gain'
     *  RelationalOperator: '<S21>/Compare'
     */
    if (Controller_U.FMS_Out.ctrl_mode >= 5) {
      /* Switch: '<S20>/Switch' incorporates:
       *  Gain: '<S20>/Gain1'
       */
      if (Controller_U.FMS_Out.reset > 0) {
        rtb_Add = 0.0F;
      } else {
        rtb_Add = rtb_Gain;
      }

      /* End of Switch: '<S20>/Switch' */

      /* Product: '<S17>/Multiply' incorporates:
       *  Constant: '<S17>/gain1'
       */
      rtb_Add *= CONTROL_PARAM.VEL_D;

      /* Saturate: '<S17>/Saturation' */
      if (rtb_Add > CONTROL_PARAM.VEL_D_MAX) {
        rtb_Add = CONTROL_PARAM.VEL_D_MAX;
      } else {
        if (rtb_Add < CONTROL_PARAM.VEL_D_MIN) {
          rtb_Add = CONTROL_PARAM.VEL_D_MIN;
        }
      }

      /* End of Saturate: '<S17>/Saturation' */

      /* Sum: '<S12>/Add' incorporates:
       *  Constant: '<S19>/gain1'
       *  DiscreteIntegrator: '<S18>/Discrete-Time Integrator'
       *  Product: '<S19>/Multiply'
       */
      rtb_Add += CONTROL_PARAM.VEL_P * rtb_u_err +
        Controller_DW.DiscreteTimeIntegrator_DSTATE;

      /* Saturate: '<S12>/Saturation' */
      if (rtb_Add > 1.0F) {
        rtb_Add = 1.0F;
      } else {
        if (rtb_Add < -1.0F) {
          rtb_Add = -1.0F;
        }
      }

      /* End of Saturate: '<S12>/Saturation' */
    } else {
      rtb_Add = 0.000999987125F * (real32_T)Controller_U.FMS_Out.throttle_cmd +
        -1.0F;
    }

    /* End of Switch: '<S13>/Switch' */

    /* Saturate: '<S7>/Saturation2' */
    if (rtb_Add > 1.0F) {
      rtb_Add = 1.0F;
    } else {
      if (rtb_Add < 0.0F) {
        rtb_Add = 0.0F;
      }
    }

    /* End of Saturate: '<S7>/Saturation2' */

    /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
     *  Bias: '<S7>/Bias'
     *  Gain: '<S7>/Gain'
     */
    rtb_Add = fmodf(floorf(CONTROL_PARAM.THROTTLE_SCALE * rtb_Add + (real32_T)
      CONTROL_PARAM.THROTTLE_BIAS), 65536.0F);
    u0 = (uint16_T)(rtb_Add < 0.0F ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
                    -rtb_Add : (int32_T)(uint16_T)rtb_Add);

    /* Saturate: '<S7>/Saturation' */
    if (u0 > 1950) {
      /* Outport: '<Root>/Control_Out' */
      Controller_Y.Control_Out.actuator_cmd[0] = 1950U;
    } else if (u0 < 1000) {
      /* Outport: '<Root>/Control_Out' */
      Controller_Y.Control_Out.actuator_cmd[0] = 1000U;
    } else {
      /* Outport: '<Root>/Control_Out' */
      Controller_Y.Control_Out.actuator_cmd[0] = u0;
    }

    /* Gain: '<S5>/Gain' */
    rtb_Add = CONTROL_PARAM.PSI_RATE_P * Controller_U.FMS_Out.psi_rate_cmd;

    /* Saturate: '<S7>/Saturation3' */
    if (rtb_Add > 1.0F) {
      rtb_Add = 1.0F;
    } else {
      if (rtb_Add < -1.0F) {
        rtb_Add = -1.0F;
      }
    }

    /* End of Saturate: '<S7>/Saturation3' */

    /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
     *  Bias: '<S7>/Bias1'
     *  Gain: '<S7>/Gain1'
     */
    rtb_Add = fmodf(floorf(CONTROL_PARAM.SERVO_SCALE * rtb_Add + (real32_T)
      CONTROL_PARAM.SERVO_BIAS), 65536.0F);
    u0 = (uint16_T)(rtb_Add < 0.0F ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
                    -rtb_Add : (int32_T)(uint16_T)rtb_Add);

    /* Saturate: '<S7>/Saturation' */
    if (u0 > 1950) {
      /* Outport: '<Root>/Control_Out' */
      Controller_Y.Control_Out.actuator_cmd[1] = 1950U;
    } else if (u0 < 1000) {
      /* Outport: '<Root>/Control_Out' */
      Controller_Y.Control_Out.actuator_cmd[1] = 1000U;
    } else {
      /* Outport: '<Root>/Control_Out' */
      Controller_Y.Control_Out.actuator_cmd[1] = u0;
    }
    break;

   default:
    /* Outport: '<Root>/Control_Out' incorporates:
     *  Constant: '<S9>/Disarm'
     *  Constant: '<S9>/Disarm1'
     */
    Controller_Y.Control_Out.actuator_cmd[0] = CONTROL_PARAM.THROTTLE_BIAS;
    Controller_Y.Control_Out.actuator_cmd[1] = CONTROL_PARAM.SERVO_BIAS;
    break;
  }

  /* End of MultiPortSwitch: '<S8>/Multiport Switch' */
  /* End of Outputs for SubSystem: '<S4>/Boat_1' */

  /* Outport: '<Root>/Control_Out' incorporates:
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   */
  Controller_Y.Control_Out.timestamp =
    Controller_DW.DiscreteTimeIntegrator_DSTATE_i;
  for (i = 0; i < 14; i++) {
    Controller_Y.Control_Out.actuator_cmd[i + 2] = 0U;
  }

  /* Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S18>/gain1'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S18>/Multiply'
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

  /* End of Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S20>/Discrete-Time Integrator1' incorporates:
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

  /* states (dwork) */
  (void) memset((void *)&Controller_DW, 0,
                sizeof(DW_Controller_T));

  /* external inputs */
  (void)memset(&Controller_U, 0, sizeof(ExtU_Controller_T));

  /* external outputs */
  Controller_Y.Control_Out = Controller_rtZControl_Out_Bus;

  /* InitializeConditions for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S20>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;
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
