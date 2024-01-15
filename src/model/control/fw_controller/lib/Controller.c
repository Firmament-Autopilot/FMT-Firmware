/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.1086
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Jan 15 09:50:49 2024
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
struct_VdEoPQWX2EedVH2abVW5XB CONTROL_PARAM = {
  7.0F,
  7.0F,
  0.785398F,
  0.1F,
  0.2F,
  0.15F,
  0.1F,
  0.1F,
  0.2F,
  -0.1F,
  0.1F,
  1.57079601F,
  3.14159298F,
  13.0F,
  0.2F,
  0.3F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  0.05236F,
  0.1F,
  0.1F,
  0.4F,
  0.2F,
  0.2F,
  0.2F,
  0.1F,
  0.0F,
  0.0F,
  1.0F,
  2.0F,
  2.0F,
  1.0F,
  1.0F,
  2.0F,
  0.1F,
  0.2F,
  0.2F
} ;                                    /* Variable: CONTROL_PARAM
                                        * Referenced by:
                                        *   '<S6>/Gain'
                                        *   '<S6>/Gain1'
                                        *   '<S6>/balabnce_ratio2'
                                        *   '<S6>/balance_ratio'
                                        *   '<S6>/pitch_ff'
                                        *   '<S6>/thorttle_ff'
                                        *   '<S6>/ucmd2pitch'
                                        *   '<S6>/ucmd2thor'
                                        *   '<S6>/wcmd2pitch'
                                        *   '<S6>/wcmd2thor'
                                        *   '<S7>/Saturation'
                                        *   '<S8>/FF'
                                        *   '<S8>/FF_limit'
                                        *   '<S8>/PI_limit'
                                        *   '<S35>/P_control'
                                        *   '<S36>/P_control'
                                        *   '<S12>/trim_speed'
                                        *   '<S13>/trim_speed'
                                        *   '<S26>/Constant1'
                                        *   '<S26>/Constant12'
                                        *   '<S26>/Constant2'
                                        *   '<S26>/Constant7'
                                        *   '<S38>/Constant'
                                        *   '<S39>/Constant'
                                        *   '<S41>/Gain'
                                        *   '<S42>/ '
                                        *   '<S42>/Gain3'
                                        *   '<S44>/Gain'
                                        *   '<S45>/Gain'
                                        *   '<S47>/Constant'
                                        *   '<S14>/gain1'
                                        *   '<S14>/gain2'
                                        *   '<S14>/gain3'
                                        *   '<S14>/Discrete-Time Integrator'
                                        *   '<S15>/gain1'
                                        *   '<S15>/gain2'
                                        *   '<S15>/gain3'
                                        *   '<S19>/Pitch Offset'
                                        *   '<S19>/Saturation'
                                        *   '<S20>/Constant1'
                                        *   '<S20>/Constant2'
                                        */

struct_ny3PY9hontv4J5WqwlFzJB CONTROL_EXPORT = {
  2U,

  { 70, 87, 32, 67, 111, 110, 116, 114, 111, 108, 108, 101, 114, 32, 118, 49, 46,
    48, 46, 48, 0 }
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
  real32_T rtb_Vdot_errg;
  real32_T rtb_Abs;
  real32_T rtb_Vdotg;
  real32_T rtb_Minus;
  real32_T rtb_Switch;
  real32_T rtb_B_err;
  real32_T rtb_Gain;
  real32_T rtb_Multiply4;
  real32_T rtb_Cos1;
  real32_T rtb_Sum_p;
  real32_T rtb_Cos;
  real32_T rtb_pitch_dout;
  real32_T rtb_Saturation_b;
  real32_T rtb_Saturation_n;
  real32_T rtb_MatrixConcatenate[12];
  uint16_T rtb_throttle_cmd;
  real32_T rtb_Add;
  uint16_T rtb_MultiportSwitch[6];
  int32_T i;
  real32_T rtb_Multiply_d_idx_1;

  /* Trigonometry: '<S7>/Atan' incorporates:
   *  Gain: '<S7>/g_force'
   *  Inport: '<Root>/FMS_Out'
   *  Sum: '<S7>/Minus'
   */
  rtb_Vdot_errg = atanf(0.101936802F * Controller_U.FMS_Out.ay_cmd);

  /* Saturate: '<S7>/Saturation' */
  if (rtb_Vdot_errg > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
    rtb_Vdot_errg = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
  } else {
    if (rtb_Vdot_errg < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      rtb_Vdot_errg = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    }
  }

  /* End of Saturate: '<S7>/Saturation' */

  /* Switch: '<S18>/Switch' incorporates:
   *  Inport: '<Root>/FMS_Out'
   *  Logic: '<S18>/Logical Operator'
   *  RelationalOperator: '<S23>/Compare'
   */
  if ((Controller_U.FMS_Out.ctrl_mode == 3) || (Controller_U.FMS_Out.ctrl_mode ==
       4)) {
    rtb_Cos1 = Controller_U.FMS_Out.phi_cmd;
  } else {
    rtb_Cos1 = rtb_Vdot_errg;
  }

  /* End of Switch: '<S18>/Switch' */

  /* Switch: '<S34>/Switch' incorporates:
   *  Constant: '<S40>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  RelationalOperator: '<S40>/Compare'
   */
  if (Controller_U.FMS_Out.ctrl_mode == 4) {
    rtb_Vdot_errg = Controller_U.FMS_Out.phi_cmd;
  }

  /* End of Switch: '<S34>/Switch' */

  /* Abs: '<S6>/Abs' */
  rtb_Abs = fabsf(rtb_Vdot_errg);

  /* Switch: '<S38>/Switch' incorporates:
   *  Constant: '<S38>/Constant'
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S38>/Asin'
   */
  if (CONTROL_PARAM.FW_TECS_ANSW > 1.0F) {
    /* Product: '<S38>/Divide' incorporates:
     *  Gain: '<S38>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Math: '<S38>/Square'
     *  Math: '<S38>/Square1'
     *  Math: '<S38>/Square2'
     *  Sqrt: '<S38>/Sqrt'
     *  Sum: '<S38>/Add'
     */
    rtb_Sum_p = 1.0F / sqrtf((Controller_U.INS_Out.vn * Controller_U.INS_Out.vn
      + Controller_U.INS_Out.ve * Controller_U.INS_Out.ve) +
      Controller_U.INS_Out.vd * Controller_U.INS_Out.vd) *
      -Controller_U.INS_Out.vd;

    /* Trigonometry: '<S38>/Asin' */
    if (rtb_Sum_p > 1.0F) {
      rtb_Sum_p = 1.0F;
    } else {
      if (rtb_Sum_p < -1.0F) {
        rtb_Sum_p = -1.0F;
      }
    }

    rtb_Switch = asinf(rtb_Sum_p);
  } else {
    rtb_Switch = Controller_U.INS_Out.theta;
  }

  /* End of Switch: '<S38>/Switch' */

  /* Gain: '<S37>/Gain1' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Vdotg = 0.101936802F * Controller_U.INS_Out.ax;

  /* Switch: '<S39>/Switch' incorporates:
   *  Constant: '<S39>/Constant'
   *  Inport: '<Root>/INS_Out'
   *  Switch: '<S47>/Switch'
   */
  if (CONTROL_PARAM.FW_TECS_SWITCH > 1.0F) {
    /* Saturate: '<S39>/Saturation' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    if (Controller_U.INS_Out.airspeed > 100.0F) {
      rtb_Minus = 100.0F;
    } else if (Controller_U.INS_Out.airspeed < 0.1F) {
      rtb_Minus = 0.1F;
    } else {
      rtb_Minus = Controller_U.INS_Out.airspeed;
    }

    /* End of Saturate: '<S39>/Saturation' */
    rtb_Vdot_errg = Controller_U.INS_Out.airspeed;
  } else {
    /* Sqrt: '<S39>/Sqrt' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Math: '<S39>/Square'
     *  Math: '<S39>/Square1'
     *  Math: '<S39>/Square2'
     *  Sum: '<S39>/Add'
     */
    rtb_Minus = sqrtf((Controller_U.INS_Out.vn * Controller_U.INS_Out.vn +
                       Controller_U.INS_Out.ve * Controller_U.INS_Out.ve) +
                      Controller_U.INS_Out.vd * Controller_U.INS_Out.vd);

    /* Saturate: '<S39>/Saturation1' incorporates:
     *  Sqrt: '<S39>/Sqrt'
     */
    if (rtb_Minus > 100.0F) {
      rtb_Minus = 100.0F;
    } else {
      if (rtb_Minus < 0.01F) {
        rtb_Minus = 0.01F;
      }
    }

    /* End of Saturate: '<S39>/Saturation1' */

    /* Sqrt: '<S47>/Sqrt' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Math: '<S47>/Square'
     *  Math: '<S47>/Square1'
     *  Math: '<S47>/Square2'
     *  Sum: '<S47>/Add'
     */
    rtb_Vdot_errg = sqrtf((Controller_U.INS_Out.vn * Controller_U.INS_Out.vn +
      Controller_U.INS_Out.ve * Controller_U.INS_Out.ve) +
                          Controller_U.INS_Out.vd * Controller_U.INS_Out.vd);

    /* Saturate: '<S47>/Saturation' incorporates:
     *  Sqrt: '<S47>/Sqrt'
     */
    if (rtb_Vdot_errg > 100.0F) {
      rtb_Vdot_errg = 100.0F;
    } else {
      if (rtb_Vdot_errg < 0.01F) {
        rtb_Vdot_errg = 0.01F;
      }
    }

    /* End of Saturate: '<S47>/Saturation' */
  }

  /* End of Switch: '<S39>/Switch' */

  /* Sum: '<S33>/Minus' incorporates:
   *  Gain: '<S39>/Gain'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S39>/Divide'
   */
  rtb_Minus = -Controller_U.FMS_Out.w_cmd / rtb_Minus - rtb_Switch;

  /* Saturate: '<S37>/Saturation' */
  if (rtb_Vdot_errg > 100.0F) {
    rtb_Vdot_errg = 100.0F;
  } else {
    if (rtb_Vdot_errg < 0.1F) {
      rtb_Vdot_errg = 0.1F;
    }
  }

  /* End of Saturate: '<S37>/Saturation' */

  /* Sum: '<S37>/Minus' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  rtb_Vdot_errg = Controller_U.FMS_Out.u_cmd - rtb_Vdot_errg;

  /* Sum: '<S37>/Minus1' incorporates:
   *  Gain: '<S37>/Gain'
   */
  rtb_Vdot_errg = 0.101936802F * rtb_Vdot_errg - rtb_Vdotg;

  /* Sum: '<S6>/Minus1' incorporates:
   *  Gain: '<S6>/ucmd2pitch'
   *  Gain: '<S6>/wcmd2pitch'
   */
  rtb_B_err = CONTROL_PARAM.FW_TECS_W2P * rtb_Minus - CONTROL_PARAM.FW_TECS_U2P *
    rtb_Vdot_errg;

  /* DiscreteIntegrator: '<S42>/ ' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) || (Controller_DW._PrevResetState != 0))
  {
    Controller_DW._DSTATE = Controller_ConstB.Zero1;
    if (Controller_DW._DSTATE >= CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
      Controller_DW._DSTATE = CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
    } else {
      if (Controller_DW._DSTATE <= -CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
        Controller_DW._DSTATE = -CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
      }
    }
  }

  if (Controller_DW._DSTATE >= CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
    Controller_DW._DSTATE = CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
  } else {
    if (Controller_DW._DSTATE <= -CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
      Controller_DW._DSTATE = -CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
    }
  }

  /* DiscreteIntegrator: '<S43>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
    Controller_DW.DiscreteTimeIntegrator1_DSTATE = rtb_B_err;
  }

  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevRes != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTATE = rtb_B_err;
  }

  /* Gain: '<S43>/Gain' incorporates:
   *  DiscreteIntegrator: '<S43>/Discrete-Time Integrator1'
   *  Sum: '<S43>/Sum5'
   */
  rtb_Gain = (rtb_B_err - Controller_DW.DiscreteTimeIntegrator1_DSTATE) *
    62.831852F;

  /* Switch: '<S18>/Switch1' incorporates:
   *  Constant: '<S24>/Constant'
   *  DiscreteIntegrator: '<S42>/ '
   *  Gain: '<S35>/P_control'
   *  Gain: '<S6>/Gain'
   *  Gain: '<S6>/balabnce_ratio2'
   *  Gain: '<S6>/pitch_ff'
   *  Inport: '<Root>/FMS_Out'
   *  RelationalOperator: '<S24>/Compare'
   *  Sum: '<S35>/Add'
   *  Sum: '<S6>/Add3'
   *  Sum: '<S6>/Minus'
   *  Sum: '<S6>/Sum'
   *  Switch: '<S43>/Switch'
   */
  if (Controller_U.FMS_Out.ctrl_mode == 3) {
    rtb_Multiply4 = Controller_U.FMS_Out.theta_cmd;
  } else {
    if (Controller_U.FMS_Out.reset > 0) {
      /* Switch: '<S43>/Switch' incorporates:
       *  Gain: '<S43>/Gain1'
       */
      rtb_Sum_p = 0.0F;
    } else {
      /* Switch: '<S43>/Switch' */
      rtb_Sum_p = rtb_Gain;
    }

    /* Gain: '<S41>/Gain' */
    rtb_pitch_dout = CONTROL_PARAM.FW_TECS_PITCH_D * rtb_Sum_p;

    /* Saturate: '<S35>/Saturation1' */
    if (rtb_pitch_dout > 0.3F) {
      rtb_pitch_dout = 0.3F;
    } else {
      if (rtb_pitch_dout < -0.3F) {
        rtb_pitch_dout = -0.3F;
      }
    }

    /* End of Saturate: '<S35>/Saturation1' */
    rtb_Multiply4 = (((2.0F - CONTROL_PARAM.FW_TECS_RATIO) * rtb_Switch -
                      rtb_Vdotg) * CONTROL_PARAM.FW_TECS_PITCH_F +
                     ((CONTROL_PARAM.FW_TECS_PITCH_P * rtb_B_err +
                       Controller_DW._DSTATE) + rtb_pitch_dout)) +
      CONTROL_PARAM.FW_TECS_R2P * rtb_Abs;
  }

  /* End of Switch: '<S18>/Switch1' */

  /* Bias: '<S19>/Pitch Offset' */
  rtb_Multiply4 += CONTROL_PARAM.FW_PITCH_OFFSET;

  /* Saturate: '<S19>/Saturation' */
  if (rtb_Multiply4 > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
    rtb_Multiply4 = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
  } else {
    if (rtb_Multiply4 < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      rtb_Multiply4 = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    }
  }

  /* Product: '<S20>/Multiply' incorporates:
   *  Constant: '<S20>/Constant2'
   *  Inport: '<Root>/INS_Out'
   *  Sum: '<S19>/Sum'
   */
  rtb_Multiply_d_idx_1 = (rtb_Multiply4 - Controller_U.INS_Out.theta) *
    CONTROL_PARAM.PITCH_P;

  /* Product: '<S22>/Divide' incorporates:
   *  Constant: '<S22>/Constant'
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Sum_p = 9.81F / Controller_U.INS_Out.airspeed;

  /* Saturate: '<S22>/Saturation' */
  if (rtb_Sum_p > 1.0F) {
    rtb_Sum_p = 1.0F;
  } else {
    if (rtb_Sum_p < 0.0F) {
      rtb_Sum_p = 0.0F;
    }
  }

  /* End of Saturate: '<S22>/Saturation' */

  /* Sum: '<S17>/Sum' incorporates:
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S22>/Multiply'
   *  Product: '<S22>/Multiply1'
   *  Trigonometry: '<S22>/Cos'
   *  Trigonometry: '<S22>/Tan'
   */
  rtb_Sum_p = tanf(Controller_U.FMS_Out.phi_cmd) * arm_cos_f32
    (Controller_U.FMS_Out.theta_cmd) * rtb_Sum_p +
    Controller_U.FMS_Out.psi_rate_cmd;

  /* Saturate: '<S19>/Saturation' */
  if (rtb_Cos1 > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
    rtb_Cos1 = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
  } else {
    if (rtb_Cos1 < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
      rtb_Cos1 = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
    }
  }

  /* Sum: '<S10>/Add' incorporates:
   *  Constant: '<S20>/Constant1'
   *  Inport: '<Root>/INS_Out'
   *  Product: '<S10>/Multiply'
   *  Product: '<S20>/Multiply'
   *  Sum: '<S19>/Sum'
   *  Trigonometry: '<S10>/Sin1'
   */
  rtb_Add = (rtb_Cos1 - Controller_U.INS_Out.phi) * CONTROL_PARAM.ROLL_P -
    arm_sin_f32(Controller_U.INS_Out.theta) * rtb_Sum_p;

  /* Trigonometry: '<S10>/Sin' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Multiply4 = arm_sin_f32(Controller_U.INS_Out.phi);

  /* Trigonometry: '<S10>/Cos1' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Cos1 = arm_cos_f32(Controller_U.INS_Out.theta);

  /* Trigonometry: '<S10>/Cos' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Cos = arm_cos_f32(Controller_U.INS_Out.phi);

  /* Sum: '<S10>/Add1' incorporates:
   *  Product: '<S10>/Multiply1'
   *  Product: '<S10>/Multiply3'
   */
  rtb_pitch_dout = rtb_Multiply4 * rtb_Cos1 * rtb_Sum_p + rtb_Cos *
    rtb_Multiply_d_idx_1;

  /* Product: '<S10>/Multiply4' */
  rtb_Multiply4 *= rtb_Multiply_d_idx_1;

  /* Sum: '<S10>/Add2' incorporates:
   *  Product: '<S10>/Multiply5'
   */
  rtb_Cos = rtb_Cos * rtb_Cos1 * rtb_Sum_p - rtb_Multiply4;

  /* Sum: '<S8>/Minus2' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Cos1 = rtb_Add - Controller_U.INS_Out.p;
  rtb_Multiply_d_idx_1 = rtb_pitch_dout - Controller_U.INS_Out.q;
  rtb_Multiply4 = rtb_Cos - Controller_U.INS_Out.r;

  /* DiscreteIntegrator: '<S14>/Discrete-Time Integrator' incorporates:
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

  /* Sum: '<S6>/Add' incorporates:
   *  Gain: '<S6>/ucmd2thor'
   *  Gain: '<S6>/wcmd2thor'
   */
  rtb_Vdot_errg = CONTROL_PARAM.FW_TECS_W2T * rtb_Minus +
    CONTROL_PARAM.FW_TECS_U2T * rtb_Vdot_errg;

  /* DiscreteIntegrator: '<S45>/ ' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) || (Controller_DW._PrevResetState_k != 0))
  {
    Controller_DW._DSTATE_m = Controller_ConstB.Zero;
    if (Controller_DW._DSTATE_m >= 0.1F) {
      Controller_DW._DSTATE_m = 0.1F;
    } else {
      if (Controller_DW._DSTATE_m <= -0.1F) {
        Controller_DW._DSTATE_m = -0.1F;
      }
    }
  }

  if (Controller_DW._DSTATE_m >= 0.1F) {
    Controller_DW._DSTATE_m = 0.1F;
  } else {
    if (Controller_DW._DSTATE_m <= -0.1F) {
      Controller_DW._DSTATE_m = -0.1F;
    }
  }

  /* DiscreteIntegrator: '<S46>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_o != 0) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_b = rtb_Vdot_errg;
  }

  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevR_m != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_b = rtb_Vdot_errg;
  }

  /* Gain: '<S46>/Gain' incorporates:
   *  DiscreteIntegrator: '<S46>/Discrete-Time Integrator1'
   *  Sum: '<S46>/Sum5'
   */
  rtb_Minus = (rtb_Vdot_errg - Controller_DW.DiscreteTimeIntegrator1_DSTAT_b) *
    188.49556F;

  /* Outputs for Atomic SubSystem: '<S5>/Fixwing' */
  /* MultiPortSwitch: '<S29>/Multiport Switch' incorporates:
   *  Constant: '<S29>/Disarm'
   *  Constant: '<S29>/Standby'
   *  Inport: '<Root>/FMS_Out'
   */
  switch (Controller_U.FMS_Out.status) {
   case 1:
    for (i = 0; i < 6; i++) {
      rtb_MultiportSwitch[i] = Controller_ConstP.Disarm_Value[i];
    }
    break;

   case 2:
    for (i = 0; i < 6; i++) {
      rtb_MultiportSwitch[i] = Controller_ConstP.Standby_Value[i];
    }
    break;

   case 3:
    /* Switch: '<S28>/Switch' incorporates:
     *  Constant: '<S26>/Constant1'
     *  Constant: '<S26>/Constant12'
     *  Constant: '<S26>/Constant2'
     *  Constant: '<S26>/Constant7'
     *  Constant: '<S32>/Constant'
     *  Inport: '<Root>/INS_Out'
     *  RelationalOperator: '<S32>/Compare'
     *  Saturate: '<S8>/Saturation1'
     */
    if (Controller_U.FMS_Out.ctrl_mode == 1) {
      for (i = 0; i < 6; i++) {
        rtb_MultiportSwitch[i] = Controller_U.FMS_Out.actuator_cmd[i];
      }
    } else {
      if (Controller_U.INS_Out.airspeed > 999.0F) {
        /* Saturate: '<S8>/Saturation1' */
        rtb_Saturation_b = 999.0F;
      } else if (Controller_U.INS_Out.airspeed < 0.1F) {
        /* Saturate: '<S8>/Saturation1' */
        rtb_Saturation_b = 0.1F;
      } else {
        /* Saturate: '<S8>/Saturation1' incorporates:
         *  Inport: '<Root>/INS_Out'
         */
        rtb_Saturation_b = Controller_U.INS_Out.airspeed;
      }

      /* Product: '<S12>/Divide' incorporates:
       *  Constant: '<S12>/trim_speed'
       *  Inport: '<Root>/INS_Out'
       *  Math: '<S12>/Square'
       *  Math: '<S12>/Square1'
       *  Saturate: '<S8>/Saturation1'
       */
      rtb_Saturation_n = CONTROL_PARAM.FW_AIRSPEED_TRIM *
        CONTROL_PARAM.FW_AIRSPEED_TRIM / (rtb_Saturation_b * rtb_Saturation_b);

      /* Saturate: '<S12>/Saturation' */
      if (rtb_Saturation_n > 1.0F) {
        rtb_Saturation_n = 1.0F;
      } else {
        if (rtb_Saturation_n < 0.0F) {
          rtb_Saturation_n = 0.0F;
        }
      }

      /* End of Saturate: '<S12>/Saturation' */

      /* Product: '<S13>/Divide' incorporates:
       *  Constant: '<S13>/trim_speed'
       */
      rtb_Saturation_b = CONTROL_PARAM.FW_AIRSPEED_TRIM / rtb_Saturation_b;

      /* Saturate: '<S13>/Saturation' */
      if (rtb_Saturation_b > 1.0F) {
        rtb_Saturation_b = 1.0F;
      } else {
        if (rtb_Saturation_b < 0.0F) {
          rtb_Saturation_b = 0.0F;
        }
      }

      /* End of Saturate: '<S13>/Saturation' */
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
       *  Constant: '<S30>/Constant1'
       *  DataTypeConversion: '<S30>/Data Type Conversion'
       *  Gain: '<S30>/Gain1'
       *  Logic: '<S27>/Logical Operator'
       *  RelationalOperator: '<S31>/Compare'
       *  Sum: '<S30>/Sum1'
       *  Switch: '<S46>/Switch'
       */
      if ((Controller_U.FMS_Out.ctrl_mode == 1) ||
          (Controller_U.FMS_Out.ctrl_mode == 2) ||
          (Controller_U.FMS_Out.ctrl_mode == 3)) {
        rtb_throttle_cmd = Controller_U.FMS_Out.throttle_cmd;
      } else {
        if (Controller_U.FMS_Out.reset > 0) {
          /* Switch: '<S46>/Switch' incorporates:
           *  Gain: '<S46>/Gain1'
           */
          rtb_Sum_p = 0.0F;
        } else {
          /* Switch: '<S46>/Switch' */
          rtb_Sum_p = rtb_Minus;
        }

        /* Gain: '<S44>/Gain' */
        rtb_Sum_p *= CONTROL_PARAM.FW_TECS_THOR_D;

        /* Saturate: '<S36>/Saturation1' */
        if (rtb_Sum_p > 0.3F) {
          rtb_Sum_p = 0.3F;
        } else {
          if (rtb_Sum_p < -0.3F) {
            rtb_Sum_p = -0.3F;
          }
        }

        /* End of Saturate: '<S36>/Saturation1' */

        /* Sum: '<S6>/Sum1' incorporates:
         *  DiscreteIntegrator: '<S45>/ '
         *  Gain: '<S36>/P_control'
         *  Gain: '<S6>/Gain1'
         *  Gain: '<S6>/balance_ratio'
         *  Gain: '<S6>/thorttle_ff'
         *  Sum: '<S36>/Add4'
         *  Sum: '<S6>/Add1'
         *  Sum: '<S6>/Add2'
         */
        rtb_Sum_p = (((CONTROL_PARAM.FW_TECS_THOR_P * rtb_Vdot_errg +
                       Controller_DW._DSTATE_m) + rtb_Sum_p) +
                     (CONTROL_PARAM.FW_TECS_RATIO * rtb_Vdotg + rtb_Switch) *
                     CONTROL_PARAM.FW_TECS_THOR_FF) + CONTROL_PARAM.FW_TECS_R2T *
          rtb_Abs;

        /* Saturate: '<S25>/Saturation5' */
        if (rtb_Sum_p > 1.0F) {
          rtb_Sum_p = 1.0F;
        } else {
          if (rtb_Sum_p < -1.0F) {
            rtb_Sum_p = -1.0F;
          }
        }

        /* End of Saturate: '<S25>/Saturation5' */

        /* Saturate: '<S30>/Saturation' incorporates:
         *  Constant: '<S30>/cruise_throttle'
         *  Sum: '<S30>/Sum'
         */
        if (rtb_Sum_p + 0.5F > 1.0F) {
          rtb_Abs = 1.0F;
        } else if (rtb_Sum_p + 0.5F < 0.0F) {
          rtb_Abs = 0.0F;
        } else {
          rtb_Abs = rtb_Sum_p + 0.5F;
        }

        /* End of Saturate: '<S30>/Saturation' */
        rtb_throttle_cmd = (uint16_T)((uint32_T)fmodf(floorf(1000.0F * rtb_Abs),
          4.2949673E+9F) + 1000U);
      }

      /* End of Switch: '<S27>/Switch' */

      /* Product: '<S8>/Multiply1' incorporates:
       *  Gain: '<S8>/FF'
       */
      rtb_Abs = CONTROL_PARAM.FW_FF * rtb_Add * rtb_Saturation_b;
      rtb_pitch_dout = CONTROL_PARAM.FW_FF * rtb_pitch_dout * rtb_Saturation_b;
      rtb_Switch = CONTROL_PARAM.FW_FF * rtb_Cos * rtb_Saturation_b;

      /* Saturate: '<S8>/PI_limit' incorporates:
       *  Constant: '<S15>/gain1'
       *  DiscreteIntegrator: '<S14>/Discrete-Time Integrator'
       *  Product: '<S15>/Multiply'
       *  Product: '<S8>/Multiply'
       *  Saturate: '<S8>/FF_limit'
       *  Sum: '<S11>/Add1'
       */
      rtb_Sum_p = (CONTROL_PARAM.ROLL_RATE_P * rtb_Cos1 +
                   Controller_DW.DiscreteTimeIntegrator_DSTATE[0]) *
        rtb_Saturation_n;

      /* Saturate: '<S8>/FF_limit' */
      if (rtb_Abs > CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_Abs = CONTROL_PARAM.FW_FF_LIMIT;
      } else {
        if (rtb_Abs < -CONTROL_PARAM.FW_FF_LIMIT) {
          rtb_Abs = -CONTROL_PARAM.FW_FF_LIMIT;
        }
      }

      /* Saturate: '<S8>/PI_limit' */
      if (rtb_Sum_p > CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_Sum_p = CONTROL_PARAM.FW_PI_LIMIT;
      } else {
        if (rtb_Sum_p < -CONTROL_PARAM.FW_PI_LIMIT) {
          rtb_Sum_p = -CONTROL_PARAM.FW_PI_LIMIT;
        }
      }

      /* Saturate: '<S25>/Saturation4' incorporates:
       *  Sum: '<S8>/Add'
       */
      rtb_Sum_p += rtb_Abs;
      if (rtb_Sum_p > 1.0F) {
        rtb_Sum_p = 1.0F;
      } else {
        if (rtb_Sum_p < -1.0F) {
          rtb_Sum_p = -1.0F;
        }
      }

      /* Saturate: '<S8>/PI_limit' incorporates:
       *  Constant: '<S15>/gain2'
       *  DiscreteIntegrator: '<S14>/Discrete-Time Integrator'
       *  Product: '<S15>/Multiply'
       *  Product: '<S8>/Multiply'
       *  Saturate: '<S8>/FF_limit'
       *  Sum: '<S11>/Add1'
       */
      rtb_Abs = (CONTROL_PARAM.PITCH_RATE_P * rtb_Multiply_d_idx_1 +
                 Controller_DW.DiscreteTimeIntegrator_DSTATE[1]) *
        rtb_Saturation_n;

      /* Saturate: '<S8>/FF_limit' */
      if (rtb_pitch_dout > CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_pitch_dout = CONTROL_PARAM.FW_FF_LIMIT;
      } else {
        if (rtb_pitch_dout < -CONTROL_PARAM.FW_FF_LIMIT) {
          rtb_pitch_dout = -CONTROL_PARAM.FW_FF_LIMIT;
        }
      }

      /* Saturate: '<S8>/PI_limit' */
      if (rtb_Abs > CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_Abs = CONTROL_PARAM.FW_PI_LIMIT;
      } else {
        if (rtb_Abs < -CONTROL_PARAM.FW_PI_LIMIT) {
          rtb_Abs = -CONTROL_PARAM.FW_PI_LIMIT;
        }
      }

      /* Saturate: '<S25>/Saturation4' incorporates:
       *  Sum: '<S8>/Add'
       */
      rtb_Abs += rtb_pitch_dout;
      if (rtb_Abs > 1.0F) {
        rtb_Abs = 1.0F;
      } else {
        if (rtb_Abs < -1.0F) {
          rtb_Abs = -1.0F;
        }
      }

      /* Saturate: '<S8>/PI_limit' incorporates:
       *  Constant: '<S15>/gain3'
       *  DiscreteIntegrator: '<S14>/Discrete-Time Integrator'
       *  Product: '<S15>/Multiply'
       *  Product: '<S8>/Multiply'
       *  Saturate: '<S8>/FF_limit'
       *  Sum: '<S11>/Add1'
       */
      rtb_pitch_dout = (CONTROL_PARAM.YAW_RATE_P * rtb_Multiply4 +
                        Controller_DW.DiscreteTimeIntegrator_DSTATE[2]) *
        rtb_Saturation_n;

      /* Saturate: '<S8>/FF_limit' */
      if (rtb_Switch > CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_Switch = CONTROL_PARAM.FW_FF_LIMIT;
      } else {
        if (rtb_Switch < -CONTROL_PARAM.FW_FF_LIMIT) {
          rtb_Switch = -CONTROL_PARAM.FW_FF_LIMIT;
        }
      }

      /* Saturate: '<S8>/PI_limit' */
      if (rtb_pitch_dout > CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_pitch_dout = CONTROL_PARAM.FW_PI_LIMIT;
      } else {
        if (rtb_pitch_dout < -CONTROL_PARAM.FW_PI_LIMIT) {
          rtb_pitch_dout = -CONTROL_PARAM.FW_PI_LIMIT;
        }
      }

      /* Saturate: '<S25>/Saturation4' incorporates:
       *  Sum: '<S8>/Add'
       */
      rtb_pitch_dout += rtb_Switch;
      if (rtb_pitch_dout > 1.0F) {
        rtb_pitch_dout = 1.0F;
      } else {
        if (rtb_pitch_dout < -1.0F) {
          rtb_pitch_dout = -1.0F;
        }
      }

      rtb_MultiportSwitch[0] = rtb_throttle_cmd;
      rtb_MultiportSwitch[1] = rtb_throttle_cmd;

      /* Product: '<S25>/Multiply1' incorporates:
       *  Saturate: '<S25>/Saturation3'
       */
      for (i = 0; i < 4; i++) {
        /* Saturate: '<S25>/Saturation3' incorporates:
         *  Bias: '<S25>/Bias'
         *  Gain: '<S25>/Gain1'
         */
        rtb_Switch = 500.0F * (rtb_MatrixConcatenate[i + 8] * rtb_pitch_dout +
          (rtb_MatrixConcatenate[i + 4] * rtb_Abs + rtb_MatrixConcatenate[i] *
           rtb_Sum_p)) + 1500.0F;
        if (rtb_Switch > 2000.0F) {
          rtb_Switch = 2000.0F;
        } else {
          if (rtb_Switch < 1000.0F) {
            rtb_Switch = 1000.0F;
          }
        }

        rtb_MultiportSwitch[i + 2] = (uint16_T)fmodf(floorf(rtb_Switch),
          65536.0F);
      }

      /* End of Product: '<S25>/Multiply1' */
    }

    /* End of Switch: '<S28>/Switch' */
    break;

   default:
    for (i = 0; i < 6; i++) {
      rtb_MultiportSwitch[i] = Controller_ConstP.Disarm_Value[i];
    }
    break;
  }

  /* End of MultiPortSwitch: '<S29>/Multiport Switch' */
  /* End of Outputs for SubSystem: '<S5>/Fixwing' */

  /* Outport: '<Root>/Control_Out' incorporates:
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   *  Reshape: '<S29>/Reshape'
   */
  Controller_Y.Control_Out.timestamp =
    Controller_DW.DiscreteTimeIntegrator_DSTATE_n;
  for (i = 0; i < 6; i++) {
    /* Outputs for Atomic SubSystem: '<S5>/Fixwing' */
    Controller_Y.Control_Out.actuator_cmd[i] = rtb_MultiportSwitch[i];

    /* End of Outputs for SubSystem: '<S5>/Fixwing' */
  }

  for (i = 0; i < 10; i++) {
    Controller_Y.Control_Out.actuator_cmd[i + 6] = 0U;
  }

  /* End of Outport: '<Root>/Control_Out' */

  /* Update for DiscreteIntegrator: '<S42>/ ' incorporates:
   *  Gain: '<S42>/Gain3'
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW._DSTATE += CONTROL_PARAM.FW_TECS_PITCH_I * rtb_B_err * 0.002F;
  if (Controller_DW._DSTATE >= CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
    Controller_DW._DSTATE = CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
  } else {
    if (Controller_DW._DSTATE <= -CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
      Controller_DW._DSTATE = -CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
    }
  }

  Controller_DW._PrevResetState = (int8_T)(Controller_U.FMS_Out.reset > 0);

  /* End of Update for DiscreteIntegrator: '<S42>/ ' */

  /* Update for DiscreteIntegrator: '<S43>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;
  Controller_DW.DiscreteTimeIntegrator1_DSTATE += 0.002F * rtb_Gain;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S14>/gain1'
   *  Constant: '<S14>/gain2'
   *  Constant: '<S14>/gain3'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S14>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE[0] += CONTROL_PARAM.ROLL_RATE_I *
    rtb_Cos1 * 0.002F;
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

  /* End of Update for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S45>/ ' incorporates:
   *  Gain: '<S45>/Gain'
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW._DSTATE_m += CONTROL_PARAM.FW_TECS_THOR_I * rtb_Vdot_errg *
    0.002F;
  if (Controller_DW._DSTATE_m >= 0.1F) {
    Controller_DW._DSTATE_m = 0.1F;
  } else {
    if (Controller_DW._DSTATE_m <= -0.1F) {
      Controller_DW._DSTATE_m = -0.1F;
    }
  }

  Controller_DW._PrevResetState_k = (int8_T)(Controller_U.FMS_Out.reset > 0);

  /* End of Update for DiscreteIntegrator: '<S45>/ ' */

  /* Update for DiscreteIntegrator: '<S46>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_o = 0U;
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_b += 0.002F * rtb_Minus;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_m = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

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

  /* states (dwork) */
  (void) memset((void *)&Controller_DW, 0,
                sizeof(DW_Controller_T));

  /* external inputs */
  (void)memset(&Controller_U, 0, sizeof(ExtU_Controller_T));

  /* external outputs */
  Controller_Y.Control_Out = Controller_rtZControl_Out_Bus;

  /* InitializeConditions for DiscreteIntegrator: '<S42>/ ' */
  Controller_DW._DSTATE = Controller_ConstB.Zero1;
  if (Controller_DW._DSTATE >= CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
    Controller_DW._DSTATE = CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
  } else {
    if (Controller_DW._DSTATE <= -CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
      Controller_DW._DSTATE = -CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
    }
  }

  Controller_DW._PrevResetState = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S42>/ ' */

  /* InitializeConditions for DiscreteIntegrator: '<S43>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S45>/ ' */
  Controller_DW._DSTATE_m = Controller_ConstB.Zero;
  if (Controller_DW._DSTATE_m >= 0.1F) {
    Controller_DW._DSTATE_m = 0.1F;
  } else {
    if (Controller_DW._DSTATE_m <= -0.1F) {
      Controller_DW._DSTATE_m = -0.1F;
    }
  }

  Controller_DW._PrevResetState_k = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S45>/ ' */

  /* InitializeConditions for DiscreteIntegrator: '<S46>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_o = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_m = 0;
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
