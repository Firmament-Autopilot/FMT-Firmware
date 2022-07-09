/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.937
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Jul  6 20:31:41 2022
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
struct_PV3SQCFgY9osXK4X1JOmc CONTROL_PARAM = {
  5.0F,
  5.0F,
  0.52359879F,
  0.1F,
  0.1F,
  0.15F,
  0.1F,
  0.1F,
  0.2F,
  -0.1F,
  0.1F,
  1.57079637F,
  3.14159274F,
  13.0F,
  0.2F,
  0.3F,
  0.7F,
  1.0F,
  1.0F,
  1.0F
} ;                                    /* Variable: CONTROL_PARAM
                                        * Referenced by:
                                        *   '<S5>/Saturation'
                                        *   '<S9>/FF'
                                        *   '<S9>/FF_limit'
                                        *   '<S9>/PI_limit'
                                        *   '<S26>/Constant1'
                                        *   '<S26>/Constant12'
                                        *   '<S26>/Constant2'
                                        *   '<S26>/Constant7'
                                        *   '<S13>/trim_speed'
                                        *   '<S14>/trim_speed'
                                        *   '<S15>/gain1'
                                        *   '<S15>/gain2'
                                        *   '<S15>/gain3'
                                        *   '<S15>/Discrete-Time Integrator'
                                        *   '<S16>/gain1'
                                        *   '<S16>/gain2'
                                        *   '<S16>/gain3'
                                        *   '<S21>/Constant1'
                                        *   '<S21>/Constant2'
                                        */

struct_ny3PY9hontv4J5WqwlFzJB CONTROL_EXPORT = {
  2U,

  { 70, 87, 32, 67, 111, 110, 116, 114, 111, 108, 108, 101, 114, 32, 118, 48, 46,
    48, 46, 49, 0 }
} ;                                    /* Variable: CONTROL_EXPORT
                                        * Referenced by: '<S4>/Constant'
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
  real32_T rtb_Multiply4;
  real32_T rtb_Cos1;
  real32_T rtb_Sum;
  real32_T rtb_Cos;
  real32_T rtb_Saturation_b;
  real32_T rtb_MatrixConcatenate[12];
  uint16_T rtb_throttle_cmd;
  real32_T rtb_Add;
  real32_T rtb_Add1;
  int32_T i;
  real32_T rtb_Multiply_d_idx_1;

  /* Switch: '<S19>/Switch1' incorporates:
   *  Constant: '<S25>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  RelationalOperator: '<S25>/Compare'
   *  Saturate: '<S5>/Saturation'
   */
  if (Controller_U.FMS_Out.ctrl_mode == 3) {
    rtb_Multiply4 = Controller_U.FMS_Out.theta_cmd;
  } else if (0.0F > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
    /* Saturate: '<S5>/Saturation' */
    rtb_Multiply4 = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
  } else if (0.0F < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
    /* Saturate: '<S5>/Saturation' */
    rtb_Multiply4 = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
  } else {
    rtb_Multiply4 = 0.0F;
  }

  /* End of Switch: '<S19>/Switch1' */

  /* Product: '<S21>/Multiply' incorporates:
   *  Constant: '<S21>/Constant2'
   *  Inport: '<Root>/INS_Out'
   *  Sum: '<S20>/Sum'
   */
  rtb_Multiply_d_idx_1 = (rtb_Multiply4 - Controller_U.INS_Out.theta) *
    CONTROL_PARAM.PITCH_P;

  /* Sum: '<S18>/Sum' incorporates:
   *  Constant: '<S23>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  Inport: '<Root>/INS_Out'
   *  Product: '<S23>/Divide'
   *  Product: '<S23>/Multiply'
   *  Product: '<S23>/Multiply1'
   *  Trigonometry: '<S23>/Cos'
   *  Trigonometry: '<S23>/Tan'
   */
  rtb_Sum = tanf(Controller_U.FMS_Out.phi_cmd) * arm_cos_f32
    (Controller_U.FMS_Out.theta_cmd) * (9.81F / Controller_U.INS_Out.airspeed) +
    Controller_U.FMS_Out.psi_rate_cmd;

  /* Switch: '<S19>/Switch' incorporates:
   *  Inport: '<Root>/FMS_Out'
   *  Logic: '<S19>/Logical Operator'
   *  RelationalOperator: '<S24>/Compare'
   *  Saturate: '<S5>/Saturation'
   */
  if ((Controller_U.FMS_Out.ctrl_mode == 3) || (Controller_U.FMS_Out.ctrl_mode ==
       4)) {
    rtb_Multiply4 = Controller_U.FMS_Out.phi_cmd;
  } else if (0.0F > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
    /* Saturate: '<S5>/Saturation' */
    rtb_Multiply4 = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
  } else if (0.0F < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
    /* Saturate: '<S5>/Saturation' */
    rtb_Multiply4 = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
  } else {
    rtb_Multiply4 = 0.0F;
  }

  /* End of Switch: '<S19>/Switch' */

  /* Sum: '<S11>/Add' incorporates:
   *  Constant: '<S21>/Constant1'
   *  Inport: '<Root>/INS_Out'
   *  Product: '<S11>/Multiply'
   *  Product: '<S21>/Multiply'
   *  Sum: '<S20>/Sum'
   *  Trigonometry: '<S11>/Sin1'
   */
  rtb_Add = (rtb_Multiply4 - Controller_U.INS_Out.phi) * CONTROL_PARAM.ROLL_P -
    arm_sin_f32(Controller_U.INS_Out.theta) * rtb_Sum;

  /* Trigonometry: '<S11>/Sin' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Multiply4 = arm_sin_f32(Controller_U.INS_Out.phi);

  /* Trigonometry: '<S11>/Cos1' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Cos1 = arm_cos_f32(Controller_U.INS_Out.theta);

  /* Trigonometry: '<S11>/Cos' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Cos = arm_cos_f32(Controller_U.INS_Out.phi);

  /* Sum: '<S11>/Add1' incorporates:
   *  Product: '<S11>/Multiply1'
   *  Product: '<S11>/Multiply3'
   */
  rtb_Add1 = rtb_Multiply4 * rtb_Cos1 * rtb_Sum + rtb_Cos * rtb_Multiply_d_idx_1;

  /* Product: '<S11>/Multiply4' */
  rtb_Multiply4 *= rtb_Multiply_d_idx_1;

  /* Sum: '<S11>/Add2' incorporates:
   *  Product: '<S11>/Multiply5'
   */
  rtb_Cos = rtb_Cos * rtb_Cos1 * rtb_Sum - rtb_Multiply4;

  /* Sum: '<S9>/Minus2' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Multiply_d_idx_1 = rtb_Add - Controller_U.INS_Out.p;
  rtb_Sum = rtb_Add1 - Controller_U.INS_Out.q;
  rtb_Multiply4 = rtb_Cos - Controller_U.INS_Out.r;

  /* DiscreteIntegrator: '<S15>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator_PrevRese != 0)) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = Controller_ConstB.Constant
      [0];
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] >=
        CONTROL_PARAM.RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = CONTROL_PARAM.RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] <=
          CONTROL_PARAM.RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
          CONTROL_PARAM.RATE_I_MIN;
      }
    }

    Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = Controller_ConstB.Constant
      [1];
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] >=
        CONTROL_PARAM.RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = CONTROL_PARAM.RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] <=
          CONTROL_PARAM.RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
          CONTROL_PARAM.RATE_I_MIN;
      }
    }

    Controller_DW.DiscreteTimeIntegrator_DSTATE[2] = Controller_ConstB.Constant
      [2];
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[2] >=
        CONTROL_PARAM.RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[2] = CONTROL_PARAM.RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE[2] <=
          CONTROL_PARAM.RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE[2] =
          CONTROL_PARAM.RATE_I_MIN;
      }
    }
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] >= CONTROL_PARAM.RATE_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = CONTROL_PARAM.RATE_I_MIN;
    }
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] >= CONTROL_PARAM.RATE_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = CONTROL_PARAM.RATE_I_MIN;
    }
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[2] >= CONTROL_PARAM.RATE_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[2] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[2] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[2] = CONTROL_PARAM.RATE_I_MIN;
    }
  }

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S26>/Constant1'
   *  Constant: '<S26>/Constant12'
   *  Constant: '<S26>/Constant2'
   *  Constant: '<S26>/Constant7'
   *  Constant: '<S3>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  RelationalOperator: '<S3>/Compare'
   */
  if (Controller_U.FMS_Out.status == 3) {
    /* Saturate: '<S9>/Saturation1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    if (Controller_U.INS_Out.airspeed > 999.0F) {
      rtb_Saturation_b = 999.0F;
    } else if (Controller_U.INS_Out.airspeed < 0.1F) {
      rtb_Saturation_b = 0.1F;
    } else {
      rtb_Saturation_b = Controller_U.INS_Out.airspeed;
    }

    /* End of Saturate: '<S9>/Saturation1' */

    /* Product: '<S13>/Divide' incorporates:
     *  Constant: '<S13>/trim_speed'
     *  Math: '<S13>/Square'
     *  Math: '<S13>/Square1'
     */
    rtb_Cos1 = CONTROL_PARAM.FW_AIRSPEED_TRIM * CONTROL_PARAM.FW_AIRSPEED_TRIM /
      (rtb_Saturation_b * rtb_Saturation_b);

    /* Saturate: '<S13>/Saturation' */
    if (rtb_Cos1 > 1.0F) {
      rtb_Cos1 = 1.0F;
    } else {
      if (rtb_Cos1 < 0.0F) {
        rtb_Cos1 = 0.0F;
      }
    }

    /* End of Saturate: '<S13>/Saturation' */

    /* Product: '<S14>/Divide' incorporates:
     *  Constant: '<S14>/trim_speed'
     */
    rtb_Saturation_b = CONTROL_PARAM.FW_AIRSPEED_TRIM / rtb_Saturation_b;

    /* Saturate: '<S14>/Saturation' */
    if (rtb_Saturation_b > 1.0F) {
      rtb_Saturation_b = 1.0F;
    } else {
      if (rtb_Saturation_b < 0.0F) {
        rtb_Saturation_b = 0.0F;
      }
    }

    /* End of Saturate: '<S14>/Saturation' */
    rtb_MatrixConcatenate[11] = CONTROL_PARAM.FW_YAW_EFFC;

    /* SignalConversion: '<S26>/ConcatBufferAtVector Concatenate2In3' incorporates:
     *  Constant: '<S26>/Constant11'
     *  Constant: '<S26>/Constant12'
     */
    rtb_MatrixConcatenate[10] = 0.0F;

    /* SignalConversion: '<S26>/ConcatBufferAtVector Concatenate2In2' incorporates:
     *  Constant: '<S26>/Constant10'
     */
    rtb_MatrixConcatenate[9] = 0.0F;

    /* SignalConversion: '<S26>/ConcatBufferAtVector Concatenate2In1' incorporates:
     *  Constant: '<S26>/Constant9'
     */
    rtb_MatrixConcatenate[8] = 0.0F;

    /* SignalConversion: '<S26>/ConcatBufferAtVector Concatenate1In4' incorporates:
     *  Constant: '<S26>/Constant8'
     */
    rtb_MatrixConcatenate[7] = 0.0F;
    rtb_MatrixConcatenate[6] = CONTROL_PARAM.FW_PITCH_EFFC;

    /* SignalConversion: '<S26>/ConcatBufferAtVector Concatenate1In2' incorporates:
     *  Constant: '<S26>/Constant6'
     *  Constant: '<S26>/Constant7'
     */
    rtb_MatrixConcatenate[5] = 0.0F;

    /* SignalConversion: '<S26>/ConcatBufferAtVector Concatenate1In1' incorporates:
     *  Constant: '<S26>/Constant5'
     */
    rtb_MatrixConcatenate[4] = 0.0F;

    /* SignalConversion: '<S26>/ConcatBufferAtVector ConcatenateIn4' incorporates:
     *  Constant: '<S26>/Constant4'
     */
    rtb_MatrixConcatenate[3] = 0.0F;

    /* SignalConversion: '<S26>/ConcatBufferAtVector ConcatenateIn3' incorporates:
     *  Constant: '<S26>/Constant3'
     */
    rtb_MatrixConcatenate[2] = 0.0F;
    rtb_MatrixConcatenate[1] = CONTROL_PARAM.FW_ROLL_EFFC;
    rtb_MatrixConcatenate[0] = CONTROL_PARAM.FW_ROLL_EFFC;

    /* Switch: '<S27>/Switch' incorporates:
     *  Constant: '<S26>/Constant1'
     *  Constant: '<S26>/Constant2'
     *  Logic: '<S27>/Logical Operator'
     *  RelationalOperator: '<S29>/Compare'
     */
    if ((Controller_U.FMS_Out.ctrl_mode == 1) || (Controller_U.FMS_Out.ctrl_mode
         == 2) || (Controller_U.FMS_Out.ctrl_mode == 3)) {
      rtb_throttle_cmd = (uint16_T)Controller_U.FMS_Out.throttle_cmd;
    } else {
      rtb_throttle_cmd = Controller_ConstB.DataTypeConversion;
    }

    /* End of Switch: '<S27>/Switch' */

    /* Product: '<S9>/Multiply1' incorporates:
     *  Gain: '<S9>/FF'
     */
    rtb_Add = CONTROL_PARAM.FW_FF * rtb_Add * rtb_Saturation_b;
    rtb_Add1 = CONTROL_PARAM.FW_FF * rtb_Add1 * rtb_Saturation_b;
    rtb_Saturation_b *= CONTROL_PARAM.FW_FF * rtb_Cos;

    /* Saturate: '<S9>/PI_limit' incorporates:
     *  Constant: '<S16>/gain1'
     *  DiscreteIntegrator: '<S15>/Discrete-Time Integrator'
     *  Product: '<S16>/Multiply'
     *  Product: '<S9>/Multiply'
     *  Saturate: '<S9>/FF_limit'
     *  Sum: '<S12>/Add1'
     */
    rtb_Cos = (CONTROL_PARAM.ROLL_RATE_P * rtb_Multiply_d_idx_1 +
               Controller_DW.DiscreteTimeIntegrator_DSTATE[0]) * rtb_Cos1;

    /* Saturate: '<S9>/FF_limit' */
    if (rtb_Add > CONTROL_PARAM.FW_FF_LIMIT) {
      rtb_Add = CONTROL_PARAM.FW_FF_LIMIT;
    } else {
      if (rtb_Add < -CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_Add = -CONTROL_PARAM.FW_FF_LIMIT;
      }
    }

    /* Saturate: '<S9>/PI_limit' */
    if (rtb_Cos > CONTROL_PARAM.FW_PI_LIMIT) {
      rtb_Cos = CONTROL_PARAM.FW_PI_LIMIT;
    } else {
      if (rtb_Cos < -CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_Cos = -CONTROL_PARAM.FW_PI_LIMIT;
      }
    }

    /* Saturate: '<S8>/Saturation1' incorporates:
     *  Sum: '<S9>/Add'
     */
    rtb_Cos += rtb_Add;
    if (rtb_Cos > 1.0F) {
      rtb_Cos = 1.0F;
    } else {
      if (rtb_Cos < -1.0F) {
        rtb_Cos = -1.0F;
      }
    }

    /* Saturate: '<S9>/PI_limit' incorporates:
     *  Constant: '<S16>/gain2'
     *  DiscreteIntegrator: '<S15>/Discrete-Time Integrator'
     *  Product: '<S16>/Multiply'
     *  Product: '<S9>/Multiply'
     *  Saturate: '<S9>/FF_limit'
     *  Sum: '<S12>/Add1'
     */
    rtb_Add = (CONTROL_PARAM.PITCH_RATE_P * rtb_Sum +
               Controller_DW.DiscreteTimeIntegrator_DSTATE[1]) * rtb_Cos1;

    /* Saturate: '<S9>/FF_limit' */
    if (rtb_Add1 > CONTROL_PARAM.FW_FF_LIMIT) {
      rtb_Add1 = CONTROL_PARAM.FW_FF_LIMIT;
    } else {
      if (rtb_Add1 < -CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_Add1 = -CONTROL_PARAM.FW_FF_LIMIT;
      }
    }

    /* Saturate: '<S9>/PI_limit' */
    if (rtb_Add > CONTROL_PARAM.FW_PI_LIMIT) {
      rtb_Add = CONTROL_PARAM.FW_PI_LIMIT;
    } else {
      if (rtb_Add < -CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_Add = -CONTROL_PARAM.FW_PI_LIMIT;
      }
    }

    /* Saturate: '<S8>/Saturation1' incorporates:
     *  Sum: '<S9>/Add'
     */
    rtb_Add += rtb_Add1;
    if (rtb_Add > 1.0F) {
      rtb_Add = 1.0F;
    } else {
      if (rtb_Add < -1.0F) {
        rtb_Add = -1.0F;
      }
    }

    /* Saturate: '<S9>/PI_limit' incorporates:
     *  Constant: '<S16>/gain3'
     *  DiscreteIntegrator: '<S15>/Discrete-Time Integrator'
     *  Product: '<S16>/Multiply'
     *  Product: '<S9>/Multiply'
     *  Saturate: '<S9>/FF_limit'
     *  Sum: '<S12>/Add1'
     */
    rtb_Add1 = (CONTROL_PARAM.YAW_RATE_P * rtb_Multiply4 +
                Controller_DW.DiscreteTimeIntegrator_DSTATE[2]) * rtb_Cos1;

    /* Saturate: '<S9>/FF_limit' */
    if (rtb_Saturation_b > CONTROL_PARAM.FW_FF_LIMIT) {
      rtb_Saturation_b = CONTROL_PARAM.FW_FF_LIMIT;
    } else {
      if (rtb_Saturation_b < -CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_Saturation_b = -CONTROL_PARAM.FW_FF_LIMIT;
      }
    }

    /* Saturate: '<S9>/PI_limit' */
    if (rtb_Add1 > CONTROL_PARAM.FW_PI_LIMIT) {
      rtb_Add1 = CONTROL_PARAM.FW_PI_LIMIT;
    } else {
      if (rtb_Add1 < -CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_Add1 = -CONTROL_PARAM.FW_PI_LIMIT;
      }
    }

    /* Saturate: '<S8>/Saturation1' incorporates:
     *  Sum: '<S9>/Add'
     */
    rtb_Add1 += rtb_Saturation_b;
    if (rtb_Add1 > 1.0F) {
      rtb_Add1 = 1.0F;
    } else {
      if (rtb_Add1 < -1.0F) {
        rtb_Add1 = -1.0F;
      }
    }

    /* Outport: '<Root>/Control_Out' incorporates:
     *  Reshape: '<S8>/Reshape'
     */
    Controller_Y.Control_Out.actuator_cmd[0] = rtb_throttle_cmd;
    Controller_Y.Control_Out.actuator_cmd[1] = rtb_throttle_cmd;
    for (i = 0; i < 4; i++) {
      /* Saturate: '<S8>/Saturation' incorporates:
       *  Bias: '<S8>/Bias'
       *  Gain: '<S8>/Gain'
       *  Product: '<S8>/Multiply'
       */
      rtb_Cos1 = 500.0F * (rtb_MatrixConcatenate[i + 8] * rtb_Add1 +
                           (rtb_MatrixConcatenate[i + 4] * rtb_Add +
                            rtb_MatrixConcatenate[i] * rtb_Cos)) + 1500.0F;
      if (rtb_Cos1 > 1900.0F) {
        rtb_Cos1 = 1900.0F;
      } else {
        if (rtb_Cos1 < 1100.0F) {
          rtb_Cos1 = 1100.0F;
        }
      }

      /* Outport: '<Root>/Control_Out' incorporates:
       *  Reshape: '<S8>/Reshape'
       *  Saturate: '<S8>/Saturation'
       */
      Controller_Y.Control_Out.actuator_cmd[i + 2] = (uint16_T)fmodf(floorf
        (rtb_Cos1), 65536.0F);
    }

    /* Reshape: '<S8>/Reshape' */
    for (i = 0; i < 10; i++) {
      /* Outport: '<Root>/Control_Out' incorporates:
       *  Constant: '<S8>/Constant'
       */
      Controller_Y.Control_Out.actuator_cmd[i + 6] = 0U;
    }
  } else {
    /* Outport: '<Root>/Control_Out' */
    for (i = 0; i < 16; i++) {
      Controller_Y.Control_Out.actuator_cmd[i] =
        Controller_U.FMS_Out.actuator_cmd[i];
    }
  }

  /* End of Switch: '<S1>/Switch' */

  /* Outport: '<Root>/Control_Out' incorporates:
   *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
   */
  Controller_Y.Control_Out.timestamp =
    Controller_DW.DiscreteTimeIntegrator_DSTATE_n;

  /* Update for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S15>/gain1'
   *  Constant: '<S15>/gain2'
   *  Constant: '<S15>/gain3'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S15>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE[0] += CONTROL_PARAM.ROLL_RATE_I *
    rtb_Multiply_d_idx_1 * 0.002F;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] >= CONTROL_PARAM.RATE_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = CONTROL_PARAM.RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_DSTATE[1] += CONTROL_PARAM.PITCH_RATE_I *
    rtb_Sum * 0.002F;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] >= CONTROL_PARAM.RATE_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = CONTROL_PARAM.RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_DSTATE[2] += CONTROL_PARAM.YAW_RATE_I *
    rtb_Multiply4 * 0.002F;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[2] >= CONTROL_PARAM.RATE_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[2] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[2] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[2] = CONTROL_PARAM.RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* End of Update for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S4>/Constant'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_n += CONTROL_EXPORT.period;
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

  /* InitializeConditions for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = Controller_ConstB.Constant[0];
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] >= CONTROL_PARAM.RATE_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = CONTROL_PARAM.RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = Controller_ConstB.Constant[1];
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] >= CONTROL_PARAM.RATE_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = CONTROL_PARAM.RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_DSTATE[2] = Controller_ConstB.Constant[2];
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[2] >= CONTROL_PARAM.RATE_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[2] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[2] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[2] = CONTROL_PARAM.RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRese = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' */
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
