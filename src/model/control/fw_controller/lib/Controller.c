/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.966
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sun Jul 17 14:37:52 2022
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
struct_M8LEl4uNQE6bF6Ay89SKzG CONTROL_PARAM = {
  5.0F,
  7.0F,
  1.04719758F,
  0.1F,
  0.2F,
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
  -1.0F,
  -1.0F,
  1.0F,
  1.0F,
  1.0F,
  0.05F,
  0.5F,
  0.1F,
  0.1F,
  0.05F,
  0.05F,
  0.01F,
  0.01F,
  1.0F,
  1.0F,
  2.0F,
  1.0F,
  0.1F
} ;                                    /* Variable: CONTROL_PARAM
                                        * Referenced by:
                                        *   '<S5>/Saturation'
                                        *   '<S7>/pitch_ff'
                                        *   '<S7>/ratio'
                                        *   '<S7>/ratio2'
                                        *   '<S7>/thorttle_ff'
                                        *   '<S8>/Gain'
                                        *   '<S10>/FF'
                                        *   '<S10>/FF_limit'
                                        *   '<S10>/PI_limit'
                                        *   '<S28>/Gain3'
                                        *   '<S30>/P_control'
                                        *   '<S31>/P_control'
                                        *   '<S44>/Constant1'
                                        *   '<S44>/Constant12'
                                        *   '<S44>/Constant2'
                                        *   '<S44>/Constant7'
                                        *   '<S14>/trim_speed'
                                        *   '<S15>/trim_speed'
                                        *   '<S32>/Constant'
                                        *   '<S33>/Constant'
                                        *   '<S34>/Constant'
                                        *   '<S34>/Gain1'
                                        *   '<S35>/Gain'
                                        *   '<S36>/Gain3'
                                        *   '<S38>/Gain'
                                        *   '<S39>/Gain'
                                        *   '<S16>/gain1'
                                        *   '<S16>/gain2'
                                        *   '<S16>/gain3'
                                        *   '<S16>/Discrete-Time Integrator'
                                        *   '<S17>/gain1'
                                        *   '<S17>/gain2'
                                        *   '<S17>/gain3'
                                        *   '<S22>/Constant1'
                                        *   '<S22>/Constant2'
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
  real32_T rtb_u_l;
  real32_T rtb_B_err;
  real32_T rtb_Switch;
  real32_T rtb_Vdotg;
  real32_T rtb_E_err;
  real32_T rtb_Gain;
  real32_T rtb_Cos1;
  real32_T rtb_VectorConcatenate[9];
  real32_T rtb_Sum;
  real32_T rtb_Multiply4;
  real32_T rtb_Cos;
  real32_T rtb_Saturation_b;
  real32_T rtb_MatrixConcatenate[12];
  uint16_T rtb_throttle_cmd;
  real32_T rtb_Saturation_d;
  real32_T rtb_Add_a;
  real32_T rtb_Add1;
  int32_T i;
  real32_T rtb_VectorConcatenate_0[3];
  real32_T rtb_Multiply_d_idx_1;

  /* Switch: '<S34>/Switch' incorporates:
   *  Constant: '<S34>/Constant'
   *  Inport: '<Root>/INS_Out'
   *  Saturate: '<S34>/Saturation'
   *  Switch: '<S33>/Switch'
   *  Trigonometry: '<S33>/Asin'
   */
  if (CONTROL_PARAM.FW_TECS_SWITCH > 1.0F) {
    /* Sqrt: '<S34>/Sqrt' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Math: '<S34>/Square'
     *  Math: '<S34>/Square1'
     *  Math: '<S34>/Square2'
     *  Sqrt: '<S33>/Sqrt'
     *  Sum: '<S34>/Add'
     */
    rtb_E_err = sqrtf((Controller_U.INS_Out.vn * Controller_U.INS_Out.vn +
                       Controller_U.INS_Out.ve * Controller_U.INS_Out.ve) +
                      Controller_U.INS_Out.vd * Controller_U.INS_Out.vd);

    /* Saturate: '<S34>/Saturation1' incorporates:
     *  Sqrt: '<S34>/Sqrt'
     */
    if (rtb_E_err > 100.0F) {
      rtb_B_err = 100.0F;
    } else if (rtb_E_err < 0.01F) {
      rtb_B_err = 0.01F;
    } else {
      rtb_B_err = rtb_E_err;
    }

    /* End of Saturate: '<S34>/Saturation1' */

    /* Product: '<S33>/Divide' incorporates:
     *  Gain: '<S33>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Switch = 1.0F / rtb_E_err * -Controller_U.INS_Out.vd;

    /* Trigonometry: '<S33>/Asin' */
    if (rtb_Switch > 1.0F) {
      rtb_Switch = 1.0F;
    } else {
      if (rtb_Switch < -1.0F) {
        rtb_Switch = -1.0F;
      }
    }

    rtb_Switch = asinf(rtb_Switch);
  } else {
    if (Controller_U.INS_Out.airspeed > 100.0F) {
      /* Saturate: '<S34>/Saturation' */
      rtb_B_err = 100.0F;
    } else if (Controller_U.INS_Out.airspeed < 0.1F) {
      /* Saturate: '<S34>/Saturation' */
      rtb_B_err = 0.1F;
    } else {
      /* Saturate: '<S34>/Saturation' incorporates:
       *  Inport: '<Root>/INS_Out'
       */
      rtb_B_err = Controller_U.INS_Out.airspeed;
    }

    rtb_Switch = Controller_U.INS_Out.theta;
  }

  /* End of Switch: '<S34>/Switch' */

  /* Sum: '<S29>/Minus' incorporates:
   *  Gain: '<S34>/Gain'
   *  Gain: '<S34>/Gain1'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S34>/Divide'
   */
  rtb_B_err = -Controller_U.FMS_Out.w_cmd / rtb_B_err *
    CONTROL_PARAM.FW_TECS_ANG_K - rtb_Switch;

  /* Switch: '<S32>/Switch' incorporates:
   *  Constant: '<S32>/Constant'
   *  Inport: '<Root>/INS_Out'
   */
  if (CONTROL_PARAM.FW_TECS_SWITCH > 1.0F) {
    /* Sqrt: '<S32>/Sqrt' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Math: '<S32>/Square'
     *  Math: '<S32>/Square1'
     *  Math: '<S32>/Square2'
     *  Sum: '<S32>/Add'
     */
    rtb_u_l = sqrtf((Controller_U.INS_Out.vn * Controller_U.INS_Out.vn +
                     Controller_U.INS_Out.ve * Controller_U.INS_Out.ve) +
                    Controller_U.INS_Out.vd * Controller_U.INS_Out.vd);

    /* Saturate: '<S32>/Saturation' incorporates:
     *  Sqrt: '<S32>/Sqrt'
     */
    if (rtb_u_l > 100.0F) {
      rtb_u_l = 100.0F;
    } else {
      if (rtb_u_l < 0.01F) {
        rtb_u_l = 0.01F;
      }
    }

    /* End of Saturate: '<S32>/Saturation' */
  } else {
    rtb_u_l = Controller_U.INS_Out.airspeed;
  }

  /* End of Switch: '<S32>/Switch' */

  /* Saturate: '<S28>/Saturation' */
  if (rtb_u_l > 100.0F) {
    rtb_u_l = 100.0F;
  } else {
    if (rtb_u_l < 0.1F) {
      rtb_u_l = 0.1F;
    }
  }

  /* End of Saturate: '<S28>/Saturation' */

  /* Sum: '<S28>/Minus' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  rtb_u_l = Controller_U.FMS_Out.u_cmd - rtb_u_l;

  /* Gain: '<S28>/Gain1' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Vdotg = 0.101936802F * Controller_U.INS_Out.ax;

  /* Gain: '<S28>/Gain3' incorporates:
   *  Gain: '<S28>/Gain'
   *  Sum: '<S28>/Minus1'
   */
  rtb_u_l = (0.101936802F * rtb_u_l - rtb_Vdotg) * CONTROL_PARAM.FW_TECS_VERR_K;

  /* Sum: '<S7>/Add' */
  rtb_E_err = rtb_B_err + rtb_u_l;

  /* DiscreteIntegrator: '<S39>/ ' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) || (Controller_DW._PrevResetState != 0))
  {
    Controller_DW._DSTATE = Controller_ConstB.Zero;
    if (Controller_DW._DSTATE >= 0.1F) {
      Controller_DW._DSTATE = 0.1F;
    } else {
      if (Controller_DW._DSTATE <= -0.1F) {
        Controller_DW._DSTATE = -0.1F;
      }
    }
  }

  if (Controller_DW._DSTATE >= 0.1F) {
    Controller_DW._DSTATE = 0.1F;
  } else {
    if (Controller_DW._DSTATE <= -0.1F) {
      Controller_DW._DSTATE = -0.1F;
    }
  }

  /* DiscreteIntegrator: '<S40>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevRes != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTATE = 0.0F;
  }

  /* Gain: '<S40>/Gain' incorporates:
   *  DiscreteIntegrator: '<S40>/Discrete-Time Integrator1'
   *  Sum: '<S40>/Sum5'
   */
  rtb_Gain = (rtb_E_err - Controller_DW.DiscreteTimeIntegrator1_DSTATE) *
    188.49556F;

  /* Trigonometry: '<S43>/Trigonometric Function1' incorporates:
   *  Gain: '<S42>/Gain'
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S43>/Trigonometric Function3'
   */
  rtb_Add1 = arm_cos_f32(-Controller_U.INS_Out.psi);
  rtb_VectorConcatenate[0] = rtb_Add1;

  /* Trigonometry: '<S43>/Trigonometric Function' incorporates:
   *  Gain: '<S42>/Gain'
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S43>/Trigonometric Function2'
   */
  rtb_Multiply4 = arm_sin_f32(-Controller_U.INS_Out.psi);
  rtb_VectorConcatenate[1] = rtb_Multiply4;

  /* SignalConversion: '<S43>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S43>/Constant3'
   */
  rtb_VectorConcatenate[2] = 0.0F;

  /* Gain: '<S43>/Gain' */
  rtb_VectorConcatenate[3] = -rtb_Multiply4;

  /* Trigonometry: '<S43>/Trigonometric Function3' */
  rtb_VectorConcatenate[4] = rtb_Add1;

  /* SignalConversion: '<S43>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S43>/Constant4'
   */
  rtb_VectorConcatenate[5] = 0.0F;

  /* SignalConversion: '<S43>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate[6] = Controller_ConstB.VectorConcatenate3[0];
  rtb_VectorConcatenate[7] = Controller_ConstB.VectorConcatenate3[1];
  rtb_VectorConcatenate[8] = Controller_ConstB.VectorConcatenate3[2];

  /* Sum: '<S7>/Minus1' */
  rtb_B_err -= rtb_u_l;

  /* DiscreteIntegrator: '<S36>/ ' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) || (Controller_DW._PrevResetState_c != 0))
  {
    Controller_DW._DSTATE_n = Controller_ConstB.Zero1;
    if (Controller_DW._DSTATE_n >= 0.1F) {
      Controller_DW._DSTATE_n = 0.1F;
    } else {
      if (Controller_DW._DSTATE_n <= -0.1F) {
        Controller_DW._DSTATE_n = -0.1F;
      }
    }
  }

  if (Controller_DW._DSTATE_n >= 0.1F) {
    Controller_DW._DSTATE_n = 0.1F;
  } else {
    if (Controller_DW._DSTATE_n <= -0.1F) {
      Controller_DW._DSTATE_n = -0.1F;
    }
  }

  /* End of DiscreteIntegrator: '<S36>/ ' */

  /* DiscreteIntegrator: '<S37>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevR_b != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o = 0.0F;
  }

  /* Gain: '<S37>/Gain' incorporates:
   *  DiscreteIntegrator: '<S37>/Discrete-Time Integrator1'
   *  Sum: '<S37>/Sum5'
   */
  rtb_u_l = (rtb_B_err - Controller_DW.DiscreteTimeIntegrator1_DSTAT_o) *
    188.49556F;

  /* Switch: '<S37>/Switch' incorporates:
   *  Gain: '<S37>/Gain1'
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_U.FMS_Out.reset > 0) {
    rtb_Saturation_d = 0.0F;
  } else {
    rtb_Saturation_d = rtb_u_l;
  }

  /* End of Switch: '<S37>/Switch' */

  /* Gain: '<S35>/Gain' */
  rtb_Multiply4 = CONTROL_PARAM.FW_TECS_PITCH_D * rtb_Saturation_d;

  /* Saturate: '<S30>/Saturation1' */
  if (rtb_Multiply4 > 0.1F) {
    rtb_Multiply4 = 0.1F;
  } else {
    if (rtb_Multiply4 < -0.1F) {
      rtb_Multiply4 = -0.1F;
    }
  }

  /* End of Saturate: '<S30>/Saturation1' */

  /* Product: '<S41>/Multiply' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  SignalConversion: '<S41>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_0[i] = rtb_VectorConcatenate[i + 3] *
      Controller_U.INS_Out.ve;
  }

  /* End of Product: '<S41>/Multiply' */

  /* Saturate: '<S5>/Saturation' incorporates:
   *  Gain: '<S8>/Gain'
   *  Inport: '<Root>/FMS_Out'
   *  Sum: '<S8>/Minus'
   */
  rtb_Add1 = (Controller_U.FMS_Out.v_cmd - rtb_VectorConcatenate_0[1]) *
    CONTROL_PARAM.FW_L1_ROLL_P;

  /* Saturate: '<S30>/Saturation' */
  if (Controller_DW._DSTATE_n > 0.1F) {
    rtb_Saturation_d = 0.1F;
  } else if (Controller_DW._DSTATE_n < -0.1F) {
    rtb_Saturation_d = -0.1F;
  } else {
    rtb_Saturation_d = Controller_DW._DSTATE_n;
  }

  /* End of Saturate: '<S30>/Saturation' */

  /* Saturate: '<S5>/Saturation' incorporates:
   *  Gain: '<S30>/P_control'
   *  Gain: '<S7>/pitch_ff'
   *  Gain: '<S7>/ratio2'
   *  Sum: '<S30>/Add'
   *  Sum: '<S7>/Add3'
   *  Sum: '<S7>/Minus'
   */
  rtb_Multiply4 = ((2.0F - CONTROL_PARAM.FW_TECS_RATIO) * rtb_Switch - rtb_Vdotg)
    * CONTROL_PARAM.FW_TECS_PITCH_F + ((CONTROL_PARAM.FW_TECS_PITCH_P *
    rtb_B_err + rtb_Saturation_d) + rtb_Multiply4);

  /* Switch: '<S20>/Switch1' incorporates:
   *  Constant: '<S26>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  RelationalOperator: '<S26>/Compare'
   *  Saturate: '<S5>/Saturation'
   */
  if (Controller_U.FMS_Out.ctrl_mode == 3) {
    rtb_Multiply4 = Controller_U.FMS_Out.theta_cmd;
  } else if (rtb_Multiply4 > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
    /* Saturate: '<S5>/Saturation' */
    rtb_Multiply4 = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
  } else {
    if (rtb_Multiply4 < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      /* Saturate: '<S5>/Saturation' */
      rtb_Multiply4 = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    }
  }

  /* End of Switch: '<S20>/Switch1' */

  /* Product: '<S22>/Multiply' incorporates:
   *  Constant: '<S22>/Constant2'
   *  Inport: '<Root>/INS_Out'
   *  Sum: '<S21>/Sum'
   */
  rtb_Multiply_d_idx_1 = (rtb_Multiply4 - Controller_U.INS_Out.theta) *
    CONTROL_PARAM.PITCH_P;

  /* Sum: '<S19>/Sum' incorporates:
   *  Constant: '<S24>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  Inport: '<Root>/INS_Out'
   *  Product: '<S24>/Divide'
   *  Product: '<S24>/Multiply'
   *  Product: '<S24>/Multiply1'
   *  Trigonometry: '<S24>/Cos'
   *  Trigonometry: '<S24>/Tan'
   */
  rtb_Sum = tanf(Controller_U.FMS_Out.phi_cmd) * arm_cos_f32
    (Controller_U.FMS_Out.theta_cmd) * (9.81F / Controller_U.INS_Out.airspeed) +
    Controller_U.FMS_Out.psi_rate_cmd;

  /* Switch: '<S20>/Switch' incorporates:
   *  Inport: '<Root>/FMS_Out'
   *  Logic: '<S20>/Logical Operator'
   *  RelationalOperator: '<S25>/Compare'
   *  Saturate: '<S5>/Saturation'
   */
  if ((Controller_U.FMS_Out.ctrl_mode == 3) || (Controller_U.FMS_Out.ctrl_mode ==
       4)) {
    rtb_Add1 = Controller_U.FMS_Out.phi_cmd;
  } else if (rtb_Add1 > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
    /* Saturate: '<S5>/Saturation' */
    rtb_Add1 = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
  } else {
    if (rtb_Add1 < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      /* Saturate: '<S5>/Saturation' */
      rtb_Add1 = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    }
  }

  /* End of Switch: '<S20>/Switch' */

  /* Sum: '<S12>/Add' incorporates:
   *  Constant: '<S22>/Constant1'
   *  Inport: '<Root>/INS_Out'
   *  Product: '<S12>/Multiply'
   *  Product: '<S22>/Multiply'
   *  Sum: '<S21>/Sum'
   *  Trigonometry: '<S12>/Sin1'
   */
  rtb_Add_a = (rtb_Add1 - Controller_U.INS_Out.phi) * CONTROL_PARAM.ROLL_P -
    arm_sin_f32(Controller_U.INS_Out.theta) * rtb_Sum;

  /* Trigonometry: '<S12>/Sin' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Multiply4 = arm_sin_f32(Controller_U.INS_Out.phi);

  /* Trigonometry: '<S12>/Cos1' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Cos1 = arm_cos_f32(Controller_U.INS_Out.theta);

  /* Trigonometry: '<S12>/Cos' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Cos = arm_cos_f32(Controller_U.INS_Out.phi);

  /* Sum: '<S12>/Add1' incorporates:
   *  Product: '<S12>/Multiply1'
   *  Product: '<S12>/Multiply3'
   */
  rtb_Add1 = rtb_Multiply4 * rtb_Cos1 * rtb_Sum + rtb_Cos * rtb_Multiply_d_idx_1;

  /* Product: '<S12>/Multiply4' */
  rtb_Multiply4 *= rtb_Multiply_d_idx_1;

  /* Sum: '<S12>/Add2' incorporates:
   *  Product: '<S12>/Multiply5'
   */
  rtb_Cos = rtb_Cos * rtb_Cos1 * rtb_Sum - rtb_Multiply4;

  /* Sum: '<S10>/Minus2' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Multiply4 = rtb_Add_a - Controller_U.INS_Out.p;
  rtb_Multiply_d_idx_1 = rtb_Add1 - Controller_U.INS_Out.q;
  rtb_Sum = rtb_Cos - Controller_U.INS_Out.r;

  /* DiscreteIntegrator: '<S16>/Discrete-Time Integrator' incorporates:
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
   *  Constant: '<S3>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  RelationalOperator: '<S3>/Compare'
   */
  if (Controller_U.FMS_Out.status == 3) {
    /* Switch: '<S6>/Switch' incorporates:
     *  Constant: '<S27>/Constant'
     *  Constant: '<S44>/Constant1'
     *  Constant: '<S44>/Constant12'
     *  Constant: '<S44>/Constant2'
     *  Constant: '<S44>/Constant7'
     *  Inport: '<Root>/INS_Out'
     *  RelationalOperator: '<S27>/Compare'
     *  Saturate: '<S10>/Saturation1'
     */
    if (Controller_U.FMS_Out.ctrl_mode == 1) {
      /* Outport: '<Root>/Control_Out' */
      for (i = 0; i < 16; i++) {
        Controller_Y.Control_Out.actuator_cmd[i] =
          Controller_U.FMS_Out.actuator_cmd[i];
      }
    } else {
      if (Controller_U.INS_Out.airspeed > 999.0F) {
        /* Saturate: '<S10>/Saturation1' */
        rtb_Saturation_b = 999.0F;
      } else if (Controller_U.INS_Out.airspeed < 0.1F) {
        /* Saturate: '<S10>/Saturation1' */
        rtb_Saturation_b = 0.1F;
      } else {
        /* Saturate: '<S10>/Saturation1' incorporates:
         *  Inport: '<Root>/INS_Out'
         */
        rtb_Saturation_b = Controller_U.INS_Out.airspeed;
      }

      /* Product: '<S14>/Divide' incorporates:
       *  Constant: '<S14>/trim_speed'
       *  Inport: '<Root>/INS_Out'
       *  Math: '<S14>/Square'
       *  Math: '<S14>/Square1'
       *  Saturate: '<S10>/Saturation1'
       */
      rtb_Cos1 = CONTROL_PARAM.FW_AIRSPEED_TRIM * CONTROL_PARAM.FW_AIRSPEED_TRIM
        / (rtb_Saturation_b * rtb_Saturation_b);

      /* Saturate: '<S14>/Saturation' */
      if (rtb_Cos1 > 1.0F) {
        rtb_Cos1 = 1.0F;
      } else {
        if (rtb_Cos1 < 0.0F) {
          rtb_Cos1 = 0.0F;
        }
      }

      /* End of Saturate: '<S14>/Saturation' */

      /* Product: '<S15>/Divide' incorporates:
       *  Constant: '<S15>/trim_speed'
       */
      rtb_Saturation_b = CONTROL_PARAM.FW_AIRSPEED_TRIM / rtb_Saturation_b;

      /* Saturate: '<S15>/Saturation' */
      if (rtb_Saturation_b > 1.0F) {
        rtb_Saturation_b = 1.0F;
      } else {
        if (rtb_Saturation_b < 0.0F) {
          rtb_Saturation_b = 0.0F;
        }
      }

      /* End of Saturate: '<S15>/Saturation' */
      rtb_MatrixConcatenate[11] = CONTROL_PARAM.FW_YAW_EFFC;

      /* SignalConversion: '<S44>/ConcatBufferAtVector Concatenate2In3' incorporates:
       *  Constant: '<S44>/Constant11'
       *  Constant: '<S44>/Constant12'
       */
      rtb_MatrixConcatenate[10] = 0.0F;

      /* SignalConversion: '<S44>/ConcatBufferAtVector Concatenate2In2' incorporates:
       *  Constant: '<S44>/Constant10'
       */
      rtb_MatrixConcatenate[9] = 0.0F;

      /* SignalConversion: '<S44>/ConcatBufferAtVector Concatenate2In1' incorporates:
       *  Constant: '<S44>/Constant9'
       */
      rtb_MatrixConcatenate[8] = 0.0F;

      /* SignalConversion: '<S44>/ConcatBufferAtVector Concatenate1In4' incorporates:
       *  Constant: '<S44>/Constant8'
       */
      rtb_MatrixConcatenate[7] = 0.0F;
      rtb_MatrixConcatenate[6] = CONTROL_PARAM.FW_PITCH_EFFC;

      /* SignalConversion: '<S44>/ConcatBufferAtVector Concatenate1In2' incorporates:
       *  Constant: '<S44>/Constant6'
       *  Constant: '<S44>/Constant7'
       */
      rtb_MatrixConcatenate[5] = 0.0F;

      /* SignalConversion: '<S44>/ConcatBufferAtVector Concatenate1In1' incorporates:
       *  Constant: '<S44>/Constant5'
       */
      rtb_MatrixConcatenate[4] = 0.0F;

      /* SignalConversion: '<S44>/ConcatBufferAtVector ConcatenateIn4' incorporates:
       *  Constant: '<S44>/Constant4'
       */
      rtb_MatrixConcatenate[3] = 0.0F;

      /* SignalConversion: '<S44>/ConcatBufferAtVector ConcatenateIn3' incorporates:
       *  Constant: '<S44>/Constant3'
       */
      rtb_MatrixConcatenate[2] = 0.0F;
      rtb_MatrixConcatenate[1] = CONTROL_PARAM.FW_ROLL_EFFC;
      rtb_MatrixConcatenate[0] = CONTROL_PARAM.FW_ROLL_EFFC;

      /* Switch: '<S45>/Switch' incorporates:
       *  Constant: '<S44>/Constant1'
       *  Constant: '<S44>/Constant2'
       *  Constant: '<S46>/Constant1'
       *  DataTypeConversion: '<S46>/Data Type Conversion'
       *  Gain: '<S46>/Gain1'
       *  Logic: '<S45>/Logical Operator'
       *  RelationalOperator: '<S47>/Compare'
       *  Sum: '<S46>/Sum1'
       *  Switch: '<S40>/Switch'
       */
      if ((Controller_U.FMS_Out.ctrl_mode == 1) ||
          (Controller_U.FMS_Out.ctrl_mode == 2) ||
          (Controller_U.FMS_Out.ctrl_mode == 3)) {
        rtb_throttle_cmd = (uint16_T)Controller_U.FMS_Out.throttle_cmd;
      } else {
        if (Controller_U.FMS_Out.reset > 0) {
          /* Switch: '<S40>/Switch' incorporates:
           *  Gain: '<S40>/Gain1'
           */
          rtb_Saturation_d = 0.0F;
        } else {
          /* Switch: '<S40>/Switch' */
          rtb_Saturation_d = rtb_Gain;
        }

        /* Gain: '<S38>/Gain' */
        rtb_Saturation_d *= CONTROL_PARAM.FW_TECS_THOR_D;

        /* Saturate: '<S31>/Saturation1' */
        if (rtb_Saturation_d > 0.1F) {
          rtb_Saturation_d = 0.1F;
        } else {
          if (rtb_Saturation_d < -0.1F) {
            rtb_Saturation_d = -0.1F;
          }
        }

        /* End of Saturate: '<S31>/Saturation1' */

        /* Sum: '<S7>/Add2' incorporates:
         *  DiscreteIntegrator: '<S39>/ '
         *  Gain: '<S31>/P_control'
         *  Gain: '<S7>/ratio'
         *  Gain: '<S7>/thorttle_ff'
         *  Sum: '<S31>/Add4'
         *  Sum: '<S7>/Add1'
         */
        rtb_Switch = ((CONTROL_PARAM.FW_TECS_THOR_P * rtb_E_err +
                       Controller_DW._DSTATE) + rtb_Saturation_d) +
          (CONTROL_PARAM.FW_TECS_RATIO * rtb_Vdotg + rtb_Switch) *
          CONTROL_PARAM.FW_TECS_THOR_FF;

        /* Saturate: '<S9>/Saturation2' */
        if (rtb_Switch > 1.0F) {
          rtb_Switch = 1.0F;
        } else {
          if (rtb_Switch < -1.0F) {
            rtb_Switch = -1.0F;
          }
        }

        /* End of Saturate: '<S9>/Saturation2' */

        /* Saturate: '<S46>/Saturation' */
        if (rtb_Switch < 0.0F) {
          rtb_Switch = 0.0F;
        }

        /* End of Saturate: '<S46>/Saturation' */
        rtb_throttle_cmd = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          rtb_Switch), 4.2949673E+9F) + 1000U);
      }

      /* End of Switch: '<S45>/Switch' */

      /* Product: '<S10>/Multiply1' incorporates:
       *  Gain: '<S10>/FF'
       */
      rtb_Vdotg = CONTROL_PARAM.FW_FF * rtb_Add_a * rtb_Saturation_b;
      rtb_Add1 = CONTROL_PARAM.FW_FF * rtb_Add1 * rtb_Saturation_b;
      rtb_Add_a = CONTROL_PARAM.FW_FF * rtb_Cos * rtb_Saturation_b;

      /* Saturate: '<S10>/PI_limit' incorporates:
       *  Constant: '<S17>/gain1'
       *  DiscreteIntegrator: '<S16>/Discrete-Time Integrator'
       *  Product: '<S10>/Multiply'
       *  Product: '<S17>/Multiply'
       *  Saturate: '<S10>/FF_limit'
       *  Sum: '<S13>/Add1'
       */
      rtb_Switch = (CONTROL_PARAM.ROLL_RATE_P * rtb_Multiply4 +
                    Controller_DW.DiscreteTimeIntegrator_DSTATE[0]) * rtb_Cos1;

      /* Saturate: '<S10>/FF_limit' */
      if (rtb_Vdotg > CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_Vdotg = CONTROL_PARAM.FW_FF_LIMIT;
      } else {
        if (rtb_Vdotg < -CONTROL_PARAM.FW_FF_LIMIT) {
          rtb_Vdotg = -CONTROL_PARAM.FW_FF_LIMIT;
        }
      }

      /* Saturate: '<S10>/PI_limit' */
      if (rtb_Switch > CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_Switch = CONTROL_PARAM.FW_PI_LIMIT;
      } else {
        if (rtb_Switch < -CONTROL_PARAM.FW_PI_LIMIT) {
          rtb_Switch = -CONTROL_PARAM.FW_PI_LIMIT;
        }
      }

      /* Saturate: '<S9>/Saturation1' incorporates:
       *  Sum: '<S10>/Add'
       */
      rtb_Switch += rtb_Vdotg;
      if (rtb_Switch > 1.0F) {
        rtb_Switch = 1.0F;
      } else {
        if (rtb_Switch < -1.0F) {
          rtb_Switch = -1.0F;
        }
      }

      /* Saturate: '<S10>/PI_limit' incorporates:
       *  Constant: '<S17>/gain2'
       *  DiscreteIntegrator: '<S16>/Discrete-Time Integrator'
       *  Product: '<S10>/Multiply'
       *  Product: '<S17>/Multiply'
       *  Saturate: '<S10>/FF_limit'
       *  Sum: '<S13>/Add1'
       */
      rtb_Vdotg = (CONTROL_PARAM.PITCH_RATE_P * rtb_Multiply_d_idx_1 +
                   Controller_DW.DiscreteTimeIntegrator_DSTATE[1]) * rtb_Cos1;

      /* Saturate: '<S10>/FF_limit' */
      if (rtb_Add1 > CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_Add1 = CONTROL_PARAM.FW_FF_LIMIT;
      } else {
        if (rtb_Add1 < -CONTROL_PARAM.FW_FF_LIMIT) {
          rtb_Add1 = -CONTROL_PARAM.FW_FF_LIMIT;
        }
      }

      /* Saturate: '<S10>/PI_limit' */
      if (rtb_Vdotg > CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_Vdotg = CONTROL_PARAM.FW_PI_LIMIT;
      } else {
        if (rtb_Vdotg < -CONTROL_PARAM.FW_PI_LIMIT) {
          rtb_Vdotg = -CONTROL_PARAM.FW_PI_LIMIT;
        }
      }

      /* Saturate: '<S9>/Saturation1' incorporates:
       *  Sum: '<S10>/Add'
       */
      rtb_Vdotg += rtb_Add1;
      if (rtb_Vdotg > 1.0F) {
        rtb_Vdotg = 1.0F;
      } else {
        if (rtb_Vdotg < -1.0F) {
          rtb_Vdotg = -1.0F;
        }
      }

      /* Saturate: '<S10>/PI_limit' incorporates:
       *  Constant: '<S17>/gain3'
       *  DiscreteIntegrator: '<S16>/Discrete-Time Integrator'
       *  Product: '<S10>/Multiply'
       *  Product: '<S17>/Multiply'
       *  Saturate: '<S10>/FF_limit'
       *  Sum: '<S13>/Add1'
       */
      rtb_Add1 = (CONTROL_PARAM.YAW_RATE_P * rtb_Sum +
                  Controller_DW.DiscreteTimeIntegrator_DSTATE[2]) * rtb_Cos1;

      /* Saturate: '<S10>/FF_limit' */
      if (rtb_Add_a > CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_Add_a = CONTROL_PARAM.FW_FF_LIMIT;
      } else {
        if (rtb_Add_a < -CONTROL_PARAM.FW_FF_LIMIT) {
          rtb_Add_a = -CONTROL_PARAM.FW_FF_LIMIT;
        }
      }

      /* Saturate: '<S10>/PI_limit' */
      if (rtb_Add1 > CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_Add1 = CONTROL_PARAM.FW_PI_LIMIT;
      } else {
        if (rtb_Add1 < -CONTROL_PARAM.FW_PI_LIMIT) {
          rtb_Add1 = -CONTROL_PARAM.FW_PI_LIMIT;
        }
      }

      /* Saturate: '<S9>/Saturation1' incorporates:
       *  Sum: '<S10>/Add'
       */
      rtb_Add1 += rtb_Add_a;
      if (rtb_Add1 > 1.0F) {
        rtb_Add1 = 1.0F;
      } else {
        if (rtb_Add1 < -1.0F) {
          rtb_Add1 = -1.0F;
        }
      }

      /* Outport: '<Root>/Control_Out' incorporates:
       *  Reshape: '<S9>/Reshape'
       */
      Controller_Y.Control_Out.actuator_cmd[0] = rtb_throttle_cmd;
      Controller_Y.Control_Out.actuator_cmd[1] = rtb_throttle_cmd;
      for (i = 0; i < 4; i++) {
        /* Saturate: '<S9>/Saturation' incorporates:
         *  Bias: '<S9>/Bias'
         *  Gain: '<S9>/Gain'
         *  Product: '<S9>/Multiply'
         */
        rtb_Add_a = 500.0F * (rtb_MatrixConcatenate[i + 8] * rtb_Add1 +
                              (rtb_MatrixConcatenate[i + 4] * rtb_Vdotg +
          rtb_MatrixConcatenate[i] * rtb_Switch)) + 1500.0F;
        if (rtb_Add_a > 2000.0F) {
          rtb_Add_a = 2000.0F;
        } else {
          if (rtb_Add_a < 1000.0F) {
            rtb_Add_a = 1000.0F;
          }
        }

        /* Outport: '<Root>/Control_Out' incorporates:
         *  Reshape: '<S9>/Reshape'
         *  Saturate: '<S9>/Saturation'
         */
        Controller_Y.Control_Out.actuator_cmd[i + 2] = (uint16_T)fmodf(floorf
          (rtb_Add_a), 65536.0F);
      }

      /* Reshape: '<S9>/Reshape' */
      for (i = 0; i < 10; i++) {
        /* Outport: '<Root>/Control_Out' incorporates:
         *  Constant: '<S9>/Constant'
         */
        Controller_Y.Control_Out.actuator_cmd[i + 6] = 0U;
      }
    }

    /* End of Switch: '<S6>/Switch' */
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

  /* Update for DiscreteIntegrator: '<S39>/ ' incorporates:
   *  Gain: '<S39>/Gain'
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW._DSTATE += CONTROL_PARAM.FW_TECS_THOR_I * rtb_E_err * 0.002F;
  if (Controller_DW._DSTATE >= 0.1F) {
    Controller_DW._DSTATE = 0.1F;
  } else {
    if (Controller_DW._DSTATE <= -0.1F) {
      Controller_DW._DSTATE = -0.1F;
    }
  }

  Controller_DW._PrevResetState = (int8_T)(Controller_U.FMS_Out.reset > 0);

  /* End of Update for DiscreteIntegrator: '<S39>/ ' */

  /* Update for DiscreteIntegrator: '<S40>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_DSTATE += 0.002F * rtb_Gain;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S36>/ ' incorporates:
   *  Gain: '<S36>/Gain3'
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW._DSTATE_n += CONTROL_PARAM.FW_TECS_PITCH_I * rtb_B_err * 0.002F;
  if (Controller_DW._DSTATE_n >= 0.1F) {
    Controller_DW._DSTATE_n = 0.1F;
  } else {
    if (Controller_DW._DSTATE_n <= -0.1F) {
      Controller_DW._DSTATE_n = -0.1F;
    }
  }

  Controller_DW._PrevResetState_c = (int8_T)(Controller_U.FMS_Out.reset > 0);

  /* End of Update for DiscreteIntegrator: '<S36>/ ' */

  /* Update for DiscreteIntegrator: '<S37>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_o += 0.002F * rtb_u_l;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_b = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S16>/gain1'
   *  Constant: '<S16>/gain2'
   *  Constant: '<S16>/gain3'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S16>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE[0] += CONTROL_PARAM.ROLL_RATE_I *
    rtb_Multiply4 * 0.002F;
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
    rtb_Multiply_d_idx_1 * 0.002F;
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
    rtb_Sum * 0.002F;
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

  /* End of Update for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' */

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

  /* InitializeConditions for DiscreteIntegrator: '<S39>/ ' */
  Controller_DW._DSTATE = Controller_ConstB.Zero;
  if (Controller_DW._DSTATE >= 0.1F) {
    Controller_DW._DSTATE = 0.1F;
  } else {
    if (Controller_DW._DSTATE <= -0.1F) {
      Controller_DW._DSTATE = -0.1F;
    }
  }

  Controller_DW._PrevResetState = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S39>/ ' */

  /* InitializeConditions for DiscreteIntegrator: '<S40>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S36>/ ' */
  Controller_DW._DSTATE_n = Controller_ConstB.Zero1;
  if (Controller_DW._DSTATE_n >= 0.1F) {
    Controller_DW._DSTATE_n = 0.1F;
  } else {
    if (Controller_DW._DSTATE_n <= -0.1F) {
      Controller_DW._DSTATE_n = -0.1F;
    }
  }

  Controller_DW._PrevResetState_c = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S36>/ ' */

  /* InitializeConditions for DiscreteIntegrator: '<S37>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_PrevR_b = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' */
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
