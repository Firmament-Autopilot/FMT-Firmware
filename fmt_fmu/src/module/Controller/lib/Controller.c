/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.710
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sun Sep  6 09:56:46 2020
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
struct_Ae52N6uY2eO0jd5TMQiCYB CONTROL_PARAM = {
  0.9F,
  0.09F,
  0.01F,
  0.5F,
  0.2F,
  0.01F,
  -1.0F,
  1.0F,
  -1.0F,
  1.0F,
  -0.15F,
  0.15F,
  -0.1F,
  0.1F,
  4.5F,
  4.5F,
  0.52359879F,
  0.075F,
  0.075F,
  0.2F,
  0.1F,
  0.1F,
  0.1F,
  0.001F,
  0.001F,
  0.001F,
  -0.1F,
  0.1F,
  -0.1F,
  0.1F,
  1.57079637F,
  3.14159274F
} ;                                    /* Variable: CONTROL_PARAM
                                        * Referenced by:
                                        *   '<S9>/Saturation'
                                        *   '<S12>/Saturation'
                                        *   '<S12>/Saturation1'
                                        *   '<S37>/kd'
                                        *   '<S37>/Saturation'
                                        *   '<S38>/ki'
                                        *   '<S38>/Discrete-Time Integrator'
                                        *   '<S39>/kp'
                                        *   '<S48>/kd'
                                        *   '<S48>/Saturation'
                                        *   '<S49>/ki'
                                        *   '<S49>/Discrete-Time Integrator'
                                        *   '<S50>/kp'
                                        *   '<S28>/Constant1'
                                        *   '<S28>/Constant2'
                                        *   '<S19>/gain1'
                                        *   '<S19>/gain2'
                                        *   '<S19>/gain3'
                                        *   '<S19>/Saturation'
                                        *   '<S20>/gain1'
                                        *   '<S20>/gain2'
                                        *   '<S20>/gain3'
                                        *   '<S20>/Discrete-Time Integrator'
                                        *   '<S21>/gain1'
                                        *   '<S21>/gain2'
                                        *   '<S21>/gain3'
                                        */

struct_4XfCoaAMTej5uH3d8u88xB CONTROL_EXPORT = {
  4U
} ;                                    /* Variable: CONTROL_EXPORT
                                        * Referenced by: '<S4>/Constant'
                                        */

/* Block states (default storage) */
DW_Controller_T Controller_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Controller_T Controller_PrevZCX;

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
  real32_T rtb_TrigoFcn1;
  real32_T rtb_Gain;
  real32_T rtb_M_z[9];
  real32_T rtb_TrigoFcn;
  real32_T rtb_Saturation_m;
  real32_T rtb_Cos1;
  real32_T rtb_Multiply4;
  real32_T rtb_Multiply3_n;
  uint32_T rtb_throttle_cmd;
  int32_T i;
  real32_T rtb_M_z_0[3];
  real32_T rtb_Sign;
  real32_T rtb_Switch_idx_1;
  real32_T rtb_Atan_idx_0;
  real32_T rtb_Atan_idx_1;
  real32_T rtb_k_pt_idx_0;
  real32_T rtb_k_pt_idx_1;
  uint16_T u0;

  /* Gain: '<S45>/Gain' incorporates:
   *  Inport: '<Root>/FMS_Out'
   *  Inport: '<Root>/INS_Out'
   *  Sum: '<S45>/Sum1'
   */
  rtb_Gain = -(Controller_U.FMS_Out.w_cmd - Controller_U.INS_Out.vd);

  /* DiscreteIntegrator: '<S49>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator_PrevRese != 0)) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE = Controller_ConstB.Constant;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE >= CONTROL_PARAM.VEL_Z_I_MAX)
    {
      Controller_DW.DiscreteTimeIntegrator_DSTATE = CONTROL_PARAM.VEL_Z_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE <=
          CONTROL_PARAM.VEL_Z_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE = CONTROL_PARAM.VEL_Z_I_MIN;
      }
    }
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE >= CONTROL_PARAM.VEL_Z_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE = CONTROL_PARAM.VEL_Z_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE <= CONTROL_PARAM.VEL_Z_I_MIN)
    {
      Controller_DW.DiscreteTimeIntegrator_DSTATE = CONTROL_PARAM.VEL_Z_I_MIN;
    }
  }

  /* Delay: '<S52>/Delay1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((((Controller_U.FMS_Out.reset > 0) != (Controller_PrevZCX.Delay1_Reset_ZCE
         == POS_ZCSIG)) && (Controller_PrevZCX.Delay1_Reset_ZCE !=
        UNINITIALIZED_ZCSIG)) || (Controller_U.FMS_Out.reset != 0)) {
    Controller_DW.icLoad = 1U;
  }

  Controller_PrevZCX.Delay1_Reset_ZCE = (ZCSigState)(Controller_U.FMS_Out.reset >
    0);
  if (Controller_DW.icLoad != 0) {
    Controller_DW.Delay1_DSTATE = rtb_Gain;
  }

  /* Sum: '<S52>/Sum1' incorporates:
   *  Constant: '<S52>/alpha'
   *  Delay: '<S52>/Delay1'
   *  Product: '<S52>/Multiply'
   *  Sum: '<S52>/Sum'
   */
  Controller_DW.Delay1_DSTATE += (rtb_Gain - Controller_DW.Delay1_DSTATE) *
    0.200848639F;

  /* Delay: '<S51>/Delay' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((((Controller_U.FMS_Out.reset > 0) != (Controller_PrevZCX.Delay_Reset_ZCE ==
         POS_ZCSIG)) && (Controller_PrevZCX.Delay_Reset_ZCE !=
                         UNINITIALIZED_ZCSIG)) || (Controller_U.FMS_Out.reset !=
       0)) {
    Controller_DW.icLoad_g = 1U;
  }

  Controller_PrevZCX.Delay_Reset_ZCE = (ZCSigState)(Controller_U.FMS_Out.reset >
    0);
  if (Controller_DW.icLoad_g != 0) {
    Controller_DW.Delay_DSTATE = Controller_DW.Delay1_DSTATE;
  }

  /* Trigonometry: '<S36>/TrigoFcn1' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_TrigoFcn1 = arm_cos_f32(Controller_U.INS_Out.psi);

  /* SignalConversion: '<S36>/ConcatBufferAtVecConcentateIn1' */
  rtb_M_z[0] = rtb_TrigoFcn1;

  /* Trigonometry: '<S36>/TrigoFcn' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_TrigoFcn = arm_sin_f32(Controller_U.INS_Out.psi);

  /* Gain: '<S36>/Gain' */
  rtb_M_z[1] = -rtb_TrigoFcn;

  /* SignalConversion: '<S36>/ConcatBufferAtVecConcentateIn3' incorporates:
   *  Constant: '<S36>/Constant1'
   */
  rtb_M_z[2] = 0.0F;

  /* SignalConversion: '<S36>/ConcatBufferAtVecConcentate2In1' */
  rtb_M_z[3] = rtb_TrigoFcn;

  /* SignalConversion: '<S36>/ConcatBufferAtVecConcentate2In2' */
  rtb_M_z[4] = rtb_TrigoFcn1;

  /* SignalConversion: '<S36>/ConcatBufferAtVecConcentate2In3' incorporates:
   *  Constant: '<S36>/Constant1'
   */
  rtb_M_z[5] = 0.0F;

  /* SignalConversion: '<S36>/ConcatBufferAtVecConcentate1In3' */
  rtb_M_z[6] = Controller_ConstB.VecConcentate3[0];
  rtb_M_z[7] = Controller_ConstB.VecConcentate3[1];
  rtb_M_z[8] = Controller_ConstB.VecConcentate3[2];

  /* Product: '<S35>/Multiply' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  SignalConversion: '<S35>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_M_z_0[i] = rtb_M_z[i + 3] * Controller_U.INS_Out.ve + rtb_M_z[i] *
      Controller_U.INS_Out.vn;
  }

  /* End of Product: '<S35>/Multiply' */

  /* Sum: '<S33>/Sum' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  rtb_TrigoFcn1 = Controller_U.FMS_Out.u_cmd - rtb_M_z_0[0];
  rtb_TrigoFcn = Controller_U.FMS_Out.v_cmd - rtb_M_z_0[1];

  /* DiscreteIntegrator: '<S38>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator_PrevRe_e != 0)) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
      Controller_ConstB.Constant_g;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] >=
        CONTROL_PARAM.VEL_XY_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
        CONTROL_PARAM.VEL_XY_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] <=
          CONTROL_PARAM.VEL_XY_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
          CONTROL_PARAM.VEL_XY_I_MIN;
      }
    }

    Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
      Controller_ConstB.Constant_g;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] >=
        CONTROL_PARAM.VEL_XY_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
        CONTROL_PARAM.VEL_XY_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] <=
          CONTROL_PARAM.VEL_XY_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
          CONTROL_PARAM.VEL_XY_I_MIN;
      }
    }
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] >=
      CONTROL_PARAM.VEL_XY_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
      CONTROL_PARAM.VEL_XY_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] <=
        CONTROL_PARAM.VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
        CONTROL_PARAM.VEL_XY_I_MIN;
    }
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] >=
      CONTROL_PARAM.VEL_XY_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
      CONTROL_PARAM.VEL_XY_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] <=
        CONTROL_PARAM.VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
        CONTROL_PARAM.VEL_XY_I_MIN;
    }
  }

  /* DiscreteIntegrator: '<S40>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevRes != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] = 0.0F;
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] = 0.0F;
  }

  /* Gain: '<S40>/k_pt' incorporates:
   *  DiscreteIntegrator: '<S40>/Discrete-Time Integrator1'
   *  Sum: '<S40>/Sum5'
   */
  rtb_k_pt_idx_0 = (rtb_TrigoFcn1 -
                    Controller_DW.DiscreteTimeIntegrator1_DSTATE[0]) * 10.0F;
  rtb_k_pt_idx_1 = (rtb_TrigoFcn - Controller_DW.DiscreteTimeIntegrator1_DSTATE
                    [1]) * 10.0F;

  /* Switch: '<S14>/Switch' incorporates:
   *  Constant: '<S24>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  Inport: '<Root>/INS_Out'
   *  Product: '<S15>/Multiply'
   *  Product: '<S15>/Multiply1'
   *  Product: '<S15>/Multiply5'
   *  Product: '<S29>/Divide1'
   *  RelationalOperator: '<S24>/Compare'
   *  Saturate: '<S12>/Saturation'
   *  Sum: '<S15>/Add'
   *  Sum: '<S15>/Add1'
   *  Sum: '<S15>/Add2'
   *  Trigonometry: '<S15>/Sin1'
   */
  if (Controller_U.FMS_Out.mode == 5) {
    rtb_Atan_idx_0 = Controller_U.FMS_Out.p_cmd;
    rtb_Switch_idx_1 = Controller_U.FMS_Out.q_cmd;
    rtb_Atan_idx_1 = Controller_U.FMS_Out.r_cmd;
  } else {
    if (Controller_U.FMS_Out.psi_rate_cmd > CONTROL_PARAM.R_CMD_LIM) {
      /* Saturate: '<S12>/Saturation' */
      rtb_Saturation_m = CONTROL_PARAM.R_CMD_LIM;
    } else if (Controller_U.FMS_Out.psi_rate_cmd < -CONTROL_PARAM.R_CMD_LIM) {
      /* Saturate: '<S12>/Saturation' */
      rtb_Saturation_m = -CONTROL_PARAM.R_CMD_LIM;
    } else {
      /* Saturate: '<S12>/Saturation' */
      rtb_Saturation_m = Controller_U.FMS_Out.psi_rate_cmd;
    }

    /* Switch: '<S26>/Switch' incorporates:
     *  Constant: '<S31>/Constant'
     *  RelationalOperator: '<S31>/Compare'
     *  Saturate: '<S12>/Saturation'
     *  Trigonometry: '<S32>/Atan'
     */
    if (Controller_U.FMS_Out.mode >= 3) {
      rtb_Atan_idx_0 = Controller_U.FMS_Out.phi_cmd;
      rtb_Atan_idx_1 = Controller_U.FMS_Out.theta_cmd;
    } else {
      /* Product: '<S37>/Multiply' incorporates:
       *  Constant: '<S37>/kd'
       */
      rtb_Switch_idx_1 = CONTROL_PARAM.VEL_XY_D * rtb_k_pt_idx_0;
      rtb_Cos1 = CONTROL_PARAM.VEL_XY_D * rtb_k_pt_idx_1;

      /* Saturate: '<S37>/Saturation' */
      if (rtb_Cos1 > CONTROL_PARAM.VEL_XY_D_MAX) {
        rtb_Cos1 = CONTROL_PARAM.VEL_XY_D_MAX;
      } else {
        if (rtb_Cos1 < CONTROL_PARAM.VEL_XY_D_MIN) {
          rtb_Cos1 = CONTROL_PARAM.VEL_XY_D_MIN;
        }
      }

      /* Trigonometry: '<S32>/Atan' incorporates:
       *  Constant: '<S32>/Constant'
       *  Constant: '<S39>/kp'
       *  DiscreteIntegrator: '<S38>/Discrete-Time Integrator'
       *  Gain: '<S32>/mass'
       *  Product: '<S32>/Divide'
       *  Product: '<S39>/Multiply'
       *  Sum: '<S34>/Add'
       */
      rtb_Atan_idx_1 = atanf(((CONTROL_PARAM.VEL_XY_P * rtb_TrigoFcn +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1]) + rtb_Cos1) * 1.4F /
        9.806F);

      /* Saturate: '<S9>/Saturation' */
      if (rtb_Atan_idx_1 > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
        rtb_Atan_idx_1 = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_Atan_idx_1 < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
          rtb_Atan_idx_1 = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
        }
      }

      rtb_Atan_idx_0 = rtb_Atan_idx_1;

      /* Saturate: '<S37>/Saturation' incorporates:
       *  Trigonometry: '<S32>/Atan'
       */
      if (rtb_Switch_idx_1 > CONTROL_PARAM.VEL_XY_D_MAX) {
        rtb_Switch_idx_1 = CONTROL_PARAM.VEL_XY_D_MAX;
      } else {
        if (rtb_Switch_idx_1 < CONTROL_PARAM.VEL_XY_D_MIN) {
          rtb_Switch_idx_1 = CONTROL_PARAM.VEL_XY_D_MIN;
        }
      }

      /* Trigonometry: '<S32>/Atan' incorporates:
       *  Constant: '<S32>/Constant'
       *  Constant: '<S39>/kp'
       *  DiscreteIntegrator: '<S38>/Discrete-Time Integrator'
       *  Gain: '<S32>/Gain1'
       *  Gain: '<S32>/mass'
       *  Product: '<S32>/Divide'
       *  Product: '<S39>/Multiply'
       *  Sum: '<S34>/Add'
       */
      rtb_Atan_idx_1 = atanf(-((CONTROL_PARAM.VEL_XY_P * rtb_TrigoFcn1 +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0]) + rtb_Switch_idx_1) *
        1.4F / 9.806F);

      /* Saturate: '<S9>/Saturation' */
      if (rtb_Atan_idx_1 > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
        rtb_Atan_idx_1 = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_Atan_idx_1 < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
          rtb_Atan_idx_1 = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
        }
      }
    }

    /* End of Switch: '<S26>/Switch' */

    /* Sum: '<S27>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Cos1 = rtb_Atan_idx_0 - Controller_U.INS_Out.phi;

    /* Product: '<S29>/Divide1' incorporates:
     *  Abs: '<S29>/Abs'
     *  Constant: '<S29>/const2'
     */
    rtb_Switch_idx_1 = fabsf(rtb_Cos1) / 0.004F;

    /* Gain: '<S29>/Gain3' */
    rtb_Multiply4 = -rtb_Switch_idx_1;

    /* Product: '<S29>/Divide' incorporates:
     *  Constant: '<S28>/Constant1'
     *  Constant: '<S29>/const1'
     *  Math: '<S29>/Square'
     *  SignalConversion: '<S29>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_Multiply3_n = 9.5993F / (CONTROL_PARAM.ROLL_P * CONTROL_PARAM.ROLL_P);

    /* Signum: '<S29>/Sign' */
    if (rtb_Cos1 < 0.0F) {
      rtb_Sign = -1.0F;
    } else if (rtb_Cos1 > 0.0F) {
      rtb_Sign = 1.0F;
    } else {
      rtb_Sign = rtb_Cos1;
    }

    /* Switch: '<S29>/Switch' incorporates:
     *  Constant: '<S28>/Constant1'
     *  Gain: '<S29>/Gain1'
     *  Gain: '<S29>/Gain2'
     *  Logic: '<S29>/Logical Operator'
     *  Product: '<S29>/Multiply'
     *  Product: '<S29>/Multiply1'
     *  Product: '<S29>/Multiply2'
     *  Product: '<S29>/Multiply3'
     *  RelationalOperator: '<S29>/Relational Operator'
     *  RelationalOperator: '<S29>/Relational Operator2'
     *  SignalConversion: '<S29>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S29>/Sqrt'
     *  Sum: '<S29>/Subtract'
     */
    if ((rtb_Cos1 <= rtb_Multiply3_n) && (rtb_Cos1 >= -rtb_Multiply3_n)) {
      rtb_Cos1 *= CONTROL_PARAM.ROLL_P;
    } else {
      rtb_Cos1 = sqrtf((rtb_Sign * rtb_Cos1 - 0.5F * rtb_Multiply3_n) *
                       Controller_ConstB.Gain) * rtb_Sign;
    }

    /* Switch: '<S30>/Switch' incorporates:
     *  Gain: '<S29>/Gain3'
     *  RelationalOperator: '<S30>/UpperRelop'
     */
    if (rtb_Cos1 >= -rtb_Switch_idx_1) {
      rtb_Multiply4 = rtb_Cos1;
    }

    /* Switch: '<S30>/Switch2' incorporates:
     *  RelationalOperator: '<S30>/LowerRelop1'
     */
    if (rtb_Cos1 <= rtb_Switch_idx_1) {
      rtb_Switch_idx_1 = rtb_Multiply4;
    }

    /* Saturate: '<S12>/Saturation1' */
    if (rtb_Switch_idx_1 > CONTROL_PARAM.P_Q_CMD_LIM) {
      rtb_Switch_idx_1 = CONTROL_PARAM.P_Q_CMD_LIM;
    } else {
      if (rtb_Switch_idx_1 < -CONTROL_PARAM.P_Q_CMD_LIM) {
        rtb_Switch_idx_1 = -CONTROL_PARAM.P_Q_CMD_LIM;
      }
    }

    rtb_Atan_idx_0 = rtb_Switch_idx_1;

    /* Sum: '<S27>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S29>/Divide1'
     */
    rtb_Cos1 = rtb_Atan_idx_1 - Controller_U.INS_Out.theta;

    /* Product: '<S29>/Divide1' incorporates:
     *  Abs: '<S29>/Abs'
     *  Constant: '<S29>/const2'
     */
    rtb_Switch_idx_1 = fabsf(rtb_Cos1) / 0.004F;

    /* Gain: '<S29>/Gain3' */
    rtb_Multiply4 = -rtb_Switch_idx_1;

    /* Product: '<S29>/Divide' incorporates:
     *  Constant: '<S28>/Constant2'
     *  Constant: '<S29>/const1'
     *  Math: '<S29>/Square'
     *  SignalConversion: '<S29>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_Multiply3_n = 9.5993F / (CONTROL_PARAM.PITCH_P * CONTROL_PARAM.PITCH_P);

    /* Signum: '<S29>/Sign' */
    if (rtb_Cos1 < 0.0F) {
      rtb_Sign = -1.0F;
    } else if (rtb_Cos1 > 0.0F) {
      rtb_Sign = 1.0F;
    } else {
      rtb_Sign = rtb_Cos1;
    }

    /* Switch: '<S29>/Switch' incorporates:
     *  Constant: '<S28>/Constant2'
     *  Gain: '<S29>/Gain1'
     *  Gain: '<S29>/Gain2'
     *  Logic: '<S29>/Logical Operator'
     *  Product: '<S29>/Multiply'
     *  Product: '<S29>/Multiply1'
     *  Product: '<S29>/Multiply2'
     *  Product: '<S29>/Multiply3'
     *  RelationalOperator: '<S29>/Relational Operator'
     *  RelationalOperator: '<S29>/Relational Operator2'
     *  SignalConversion: '<S29>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S29>/Sqrt'
     *  Sum: '<S29>/Subtract'
     */
    if ((rtb_Cos1 <= rtb_Multiply3_n) && (rtb_Cos1 >= -rtb_Multiply3_n)) {
      rtb_Cos1 *= CONTROL_PARAM.PITCH_P;
    } else {
      rtb_Cos1 = sqrtf((rtb_Sign * rtb_Cos1 - 0.5F * rtb_Multiply3_n) *
                       Controller_ConstB.Gain) * rtb_Sign;
    }

    /* Switch: '<S30>/Switch' incorporates:
     *  Gain: '<S29>/Gain3'
     *  RelationalOperator: '<S30>/UpperRelop'
     */
    if (rtb_Cos1 >= -rtb_Switch_idx_1) {
      rtb_Multiply4 = rtb_Cos1;
    }

    /* Switch: '<S30>/Switch2' incorporates:
     *  RelationalOperator: '<S30>/LowerRelop1'
     */
    if (rtb_Cos1 <= rtb_Switch_idx_1) {
      rtb_Switch_idx_1 = rtb_Multiply4;
    }

    /* Saturate: '<S12>/Saturation1' */
    if (rtb_Switch_idx_1 > CONTROL_PARAM.P_Q_CMD_LIM) {
      rtb_Switch_idx_1 = CONTROL_PARAM.P_Q_CMD_LIM;
    } else {
      if (rtb_Switch_idx_1 < -CONTROL_PARAM.P_Q_CMD_LIM) {
        rtb_Switch_idx_1 = -CONTROL_PARAM.P_Q_CMD_LIM;
      }
    }

    /* Trigonometry: '<S15>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Atan_idx_1 = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S15>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Cos1 = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Trigonometry: '<S15>/Sin' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Multiply4 = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Product: '<S15>/Multiply3' */
    rtb_Multiply3_n = rtb_Multiply4 * rtb_Cos1 * rtb_Saturation_m;

    /* Product: '<S15>/Multiply4' */
    rtb_Multiply4 *= rtb_Switch_idx_1;
    rtb_Atan_idx_0 -= arm_sin_f32(Controller_U.INS_Out.theta) * rtb_Saturation_m;
    rtb_Switch_idx_1 = rtb_Atan_idx_1 * rtb_Switch_idx_1 + rtb_Multiply3_n;
    rtb_Atan_idx_1 = rtb_Atan_idx_1 * rtb_Cos1 * rtb_Saturation_m -
      rtb_Multiply4;
  }

  /* End of Switch: '<S14>/Switch' */

  /* Sum: '<S16>/Sum' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Saturation_m = rtb_Atan_idx_0 - Controller_U.INS_Out.p;
  rtb_Atan_idx_0 = rtb_Switch_idx_1 - Controller_U.INS_Out.q;
  rtb_Atan_idx_1 -= Controller_U.INS_Out.r;

  /* DiscreteIntegrator: '<S20>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator_PrevRe_g != 0)) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] =
      Controller_ConstB.Constant_n[0];
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] >=
        CONTROL_PARAM.RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] =
        CONTROL_PARAM.RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] <=
          CONTROL_PARAM.RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] =
          CONTROL_PARAM.RATE_I_MIN;
      }
    }

    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] =
      Controller_ConstB.Constant_n[1];
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] >=
        CONTROL_PARAM.RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] =
        CONTROL_PARAM.RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] <=
          CONTROL_PARAM.RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] =
          CONTROL_PARAM.RATE_I_MIN;
      }
    }

    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] =
      Controller_ConstB.Constant_n[2];
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] >=
        CONTROL_PARAM.RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] =
        CONTROL_PARAM.RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] <=
          CONTROL_PARAM.RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] =
          CONTROL_PARAM.RATE_I_MIN;
      }
    }
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] >=
      CONTROL_PARAM.RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] =
        CONTROL_PARAM.RATE_I_MIN;
    }
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] >=
      CONTROL_PARAM.RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] =
        CONTROL_PARAM.RATE_I_MIN;
    }
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] >=
      CONTROL_PARAM.RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] =
        CONTROL_PARAM.RATE_I_MIN;
    }
  }

  /* Delay: '<S23>/Delay1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((((Controller_U.FMS_Out.reset > 0) !=
        (Controller_PrevZCX.Delay1_Reset_ZCE_p == POS_ZCSIG)) &&
       (Controller_PrevZCX.Delay1_Reset_ZCE_p != UNINITIALIZED_ZCSIG)) ||
      (Controller_U.FMS_Out.reset != 0)) {
    Controller_DW.icLoad_c = 1U;
  }

  Controller_PrevZCX.Delay1_Reset_ZCE_p = (ZCSigState)
    (Controller_U.FMS_Out.reset > 0);
  if (Controller_DW.icLoad_c != 0) {
    Controller_DW.Delay1_DSTATE_d[0] = rtb_Saturation_m;
    Controller_DW.Delay1_DSTATE_d[1] = rtb_Atan_idx_0;
    Controller_DW.Delay1_DSTATE_d[2] = rtb_Atan_idx_1;
  }

  /* Sum: '<S23>/Sum1' incorporates:
   *  Constant: '<S23>/alpha'
   *  Delay: '<S23>/Delay1'
   *  Product: '<S23>/Multiply'
   *  Sum: '<S23>/Sum'
   */
  Controller_DW.Delay1_DSTATE_d[0] += (rtb_Saturation_m -
    Controller_DW.Delay1_DSTATE_d[0]) * 0.111635208F;
  Controller_DW.Delay1_DSTATE_d[1] += (rtb_Atan_idx_0 -
    Controller_DW.Delay1_DSTATE_d[1]) * 0.111635208F;
  Controller_DW.Delay1_DSTATE_d[2] += (rtb_Atan_idx_1 -
    Controller_DW.Delay1_DSTATE_d[2]) * 0.111635208F;

  /* Delay: '<S22>/Delay' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((((Controller_U.FMS_Out.reset > 0) !=
        (Controller_PrevZCX.Delay_Reset_ZCE_b == POS_ZCSIG)) &&
       (Controller_PrevZCX.Delay_Reset_ZCE_b != UNINITIALIZED_ZCSIG)) ||
      (Controller_U.FMS_Out.reset != 0)) {
    Controller_DW.icLoad_c2 = 1U;
  }

  Controller_PrevZCX.Delay_Reset_ZCE_b = (ZCSigState)(Controller_U.FMS_Out.reset
    > 0);
  if (Controller_DW.icLoad_c2 != 0) {
    Controller_DW.Delay_DSTATE_b[0] = Controller_DW.Delay1_DSTATE_d[0];
    Controller_DW.Delay_DSTATE_b[1] = Controller_DW.Delay1_DSTATE_d[1];
    Controller_DW.Delay_DSTATE_b[2] = Controller_DW.Delay1_DSTATE_d[2];
  }

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S3>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  RelationalOperator: '<S3>/Compare'
   */
  if (Controller_U.FMS_Out.state == 2) {
    /* Switch: '<S22>/Switch' incorporates:
     *  Delay: '<S22>/Delay'
     *  Gain: '<S22>/1//T'
     *  Gain: '<S22>/zero'
     *  Sum: '<S22>/Sum'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      Controller_DW.Delay_DSTATE_b[0] = 0.0F;
      Controller_DW.Delay_DSTATE_b[1] = 0.0F;
      Controller_DW.Delay_DSTATE_b[2] = 0.0F;
    } else {
      Controller_DW.Delay_DSTATE_b[0] = (Controller_DW.Delay1_DSTATE_d[0] -
        Controller_DW.Delay_DSTATE_b[0]) * 250.0F;
      Controller_DW.Delay_DSTATE_b[1] = (Controller_DW.Delay1_DSTATE_d[1] -
        Controller_DW.Delay_DSTATE_b[1]) * 250.0F;
      Controller_DW.Delay_DSTATE_b[2] = (Controller_DW.Delay1_DSTATE_d[2] -
        Controller_DW.Delay_DSTATE_b[2]) * 250.0F;
    }

    /* End of Switch: '<S22>/Switch' */

    /* Product: '<S19>/Multiply' incorporates:
     *  Constant: '<S19>/gain1'
     */
    Controller_DW.Delay_DSTATE_b[0] *= CONTROL_PARAM.ROLL_RATE_D;

    /* Saturate: '<S19>/Saturation' */
    if (Controller_DW.Delay_DSTATE_b[0] > CONTROL_PARAM.RATE_D_MAX) {
      Controller_DW.Delay_DSTATE_b[0] = CONTROL_PARAM.RATE_D_MAX;
    } else {
      if (Controller_DW.Delay_DSTATE_b[0] < CONTROL_PARAM.RATE_D_MIN) {
        Controller_DW.Delay_DSTATE_b[0] = CONTROL_PARAM.RATE_D_MIN;
      }
    }

    /* Product: '<S19>/Multiply' incorporates:
     *  Constant: '<S19>/gain2'
     */
    Controller_DW.Delay_DSTATE_b[1] *= CONTROL_PARAM.PITCH_RATE_D;

    /* Saturate: '<S19>/Saturation' */
    if (Controller_DW.Delay_DSTATE_b[1] > CONTROL_PARAM.RATE_D_MAX) {
      Controller_DW.Delay_DSTATE_b[1] = CONTROL_PARAM.RATE_D_MAX;
    } else {
      if (Controller_DW.Delay_DSTATE_b[1] < CONTROL_PARAM.RATE_D_MIN) {
        Controller_DW.Delay_DSTATE_b[1] = CONTROL_PARAM.RATE_D_MIN;
      }
    }

    /* Product: '<S19>/Multiply' incorporates:
     *  Constant: '<S19>/gain3'
     */
    Controller_DW.Delay_DSTATE_b[2] *= CONTROL_PARAM.YAW_RATE_D;

    /* Saturate: '<S19>/Saturation' */
    if (Controller_DW.Delay_DSTATE_b[2] > CONTROL_PARAM.RATE_D_MAX) {
      Controller_DW.Delay_DSTATE_b[2] = CONTROL_PARAM.RATE_D_MAX;
    } else {
      if (Controller_DW.Delay_DSTATE_b[2] < CONTROL_PARAM.RATE_D_MIN) {
        Controller_DW.Delay_DSTATE_b[2] = CONTROL_PARAM.RATE_D_MIN;
      }
    }

    /* Switch: '<S41>/Switch' incorporates:
     *  Constant: '<S42>/Constant1'
     *  Constant: '<S43>/Constant'
     *  Gain: '<S42>/Gain1'
     *  RelationalOperator: '<S43>/Compare'
     *  Sum: '<S42>/Sum1'
     */
    if (Controller_U.FMS_Out.mode >= 4) {
      rtb_throttle_cmd = Controller_U.FMS_Out.throttle_cmd;
    } else {
      /* Product: '<S47>/Multiply' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S47>/Cos'
       *  Trigonometry: '<S47>/Cos1'
       */
      rtb_Multiply4 = arm_cos_f32(Controller_U.INS_Out.phi) * arm_cos_f32
        (Controller_U.INS_Out.theta);

      /* Gain: '<S47>/Gain' */
      rtb_Switch_idx_1 = 2.0F * rtb_Multiply4;

      /* Saturate: '<S47>/Saturation1' */
      if (rtb_Multiply4 > 1.0F) {
        rtb_Multiply4 = 1.0F;
      } else {
        if (rtb_Multiply4 < 0.5F) {
          rtb_Multiply4 = 0.5F;
        }
      }

      /* End of Saturate: '<S47>/Saturation1' */

      /* Product: '<S47>/Divide' incorporates:
       *  Constant: '<S47>/Constant'
       */
      rtb_Cos1 = 1.0F / rtb_Multiply4;

      /* Switch: '<S51>/Switch' incorporates:
       *  Delay: '<S51>/Delay'
       *  Gain: '<S51>/1//T'
       *  Gain: '<S51>/zero'
       *  Sum: '<S51>/Sum'
       */
      if (Controller_U.FMS_Out.reset > 0) {
        rtb_Multiply4 = 0.0F;
      } else {
        rtb_Multiply4 = (Controller_DW.Delay1_DSTATE -
                         Controller_DW.Delay_DSTATE) * 250.0F;
      }

      /* End of Switch: '<S51>/Switch' */

      /* Product: '<S48>/Multiply' incorporates:
       *  Constant: '<S48>/kd'
       */
      rtb_Multiply4 *= CONTROL_PARAM.VEL_Z_D;

      /* Saturate: '<S48>/Saturation' */
      if (rtb_Multiply4 > CONTROL_PARAM.VEL_Z_D_MAX) {
        rtb_Multiply4 = CONTROL_PARAM.VEL_Z_D_MAX;
      } else {
        if (rtb_Multiply4 < CONTROL_PARAM.VEL_Z_D_MIN) {
          rtb_Multiply4 = CONTROL_PARAM.VEL_Z_D_MIN;
        }
      }

      /* End of Saturate: '<S48>/Saturation' */

      /* Saturate: '<S47>/Saturation' */
      if (rtb_Switch_idx_1 > 1.0F) {
        rtb_Switch_idx_1 = 1.0F;
      } else {
        if (rtb_Switch_idx_1 < 0.0F) {
          rtb_Switch_idx_1 = 0.0F;
        }
      }

      /* End of Saturate: '<S47>/Saturation' */

      /* Product: '<S47>/Multiply1' incorporates:
       *  Constant: '<S50>/kp'
       *  DiscreteIntegrator: '<S49>/Discrete-Time Integrator'
       *  Product: '<S50>/Multiply'
       *  Sum: '<S46>/Add'
       */
      rtb_Switch_idx_1 *= ((CONTROL_PARAM.VEL_Z_P * rtb_Gain +
                            Controller_DW.DiscreteTimeIntegrator_DSTATE) +
                           rtb_Multiply4) * rtb_Cos1;

      /* Saturate: '<S44>/Saturation' */
      if (rtb_Switch_idx_1 > 0.35F) {
        rtb_Switch_idx_1 = 0.35F;
      } else {
        if (rtb_Switch_idx_1 < -0.35F) {
          rtb_Switch_idx_1 = -0.35F;
        }
      }

      /* End of Saturate: '<S44>/Saturation' */

      /* Sum: '<S42>/Sum' incorporates:
       *  Constant: '<S42>/hover_throttle'
       */
      rtb_Switch_idx_1 += 0.5F;
      rtb_throttle_cmd = (uint32_T)fmodf(floorf(1000.0F * rtb_Switch_idx_1),
        4.2949673E+9F) + 1000U;
    }

    /* End of Switch: '<S41>/Switch' */

    /* Saturate: '<S6>/Saturation1' incorporates:
     *  Constant: '<S21>/gain1'
     *  Constant: '<S21>/gain2'
     *  Constant: '<S21>/gain3'
     *  DiscreteIntegrator: '<S20>/Discrete-Time Integrator'
     *  Product: '<S21>/Multiply'
     *  Sum: '<S17>/Add'
     */
    rtb_Switch_idx_1 = (CONTROL_PARAM.ROLL_RATE_P * rtb_Saturation_m +
                        Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0]) +
      Controller_DW.Delay_DSTATE_b[0];
    if (rtb_Switch_idx_1 > 1.0F) {
      rtb_Switch_idx_1 = 1.0F;
    } else {
      if (rtb_Switch_idx_1 < -1.0F) {
        rtb_Switch_idx_1 = -1.0F;
      }
    }

    rtb_Cos1 = (CONTROL_PARAM.PITCH_RATE_P * rtb_Atan_idx_0 +
                Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1]) +
      Controller_DW.Delay_DSTATE_b[1];
    if (rtb_Cos1 > 1.0F) {
      rtb_Cos1 = 1.0F;
    } else {
      if (rtb_Cos1 < -1.0F) {
        rtb_Cos1 = -1.0F;
      }
    }

    rtb_Multiply3_n = (CONTROL_PARAM.YAW_RATE_P * rtb_Atan_idx_1 +
                       Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2]) +
      Controller_DW.Delay_DSTATE_b[2];
    if (rtb_Multiply3_n > 1.0F) {
      rtb_Multiply3_n = 1.0F;
    } else {
      if (rtb_Multiply3_n < -1.0F) {
        rtb_Multiply3_n = -1.0F;
      }
    }

    /* End of Saturate: '<S6>/Saturation1' */
    for (i = 0; i < 4; i++) {
      /* Saturate: '<S6>/Saturation' incorporates:
       *  Constant: '<S6>/X_Frame_Effective_Matrix'
       *  Gain: '<S6>/Gain'
       *  Product: '<S6>/Multiply'
       *  Sum: '<S6>/Add'
       */
      rtb_Multiply4 = fmodf(floorf(1000.0F *
        (Controller_ConstP.X_Frame_Effective_Matrix_Value[i + 8] *
         rtb_Multiply3_n + (Controller_ConstP.X_Frame_Effective_Matrix_Value[i +
                            4] * rtb_Cos1 +
                            Controller_ConstP.X_Frame_Effective_Matrix_Value[i] *
                            rtb_Switch_idx_1))), 65536.0F);
      u0 = (uint16_T)((uint32_T)(rtb_Multiply4 < 0.0F ? (int32_T)(uint16_T)
        -(int16_T)(uint16_T)-rtb_Multiply4 : (int32_T)(uint16_T)rtb_Multiply4) +
                      (uint16_T)rtb_throttle_cmd);
      if (u0 > 2000) {
        /* Outport: '<Root>/Control_Out' incorporates:
         *  Reshape: '<S6>/Reshape'
         */
        Controller_Y.Control_Out.actuator_cmd[i] = 2000U;
      } else if (u0 < 1100) {
        /* Outport: '<Root>/Control_Out' incorporates:
         *  Reshape: '<S6>/Reshape'
         */
        Controller_Y.Control_Out.actuator_cmd[i] = 1100U;
      } else {
        /* Outport: '<Root>/Control_Out' incorporates:
         *  Reshape: '<S6>/Reshape'
         */
        Controller_Y.Control_Out.actuator_cmd[i] = u0;
      }

      /* End of Saturate: '<S6>/Saturation' */
    }

    /* Reshape: '<S6>/Reshape' */
    for (i = 0; i < 12; i++) {
      /* Outport: '<Root>/Control_Out' incorporates:
       *  Constant: '<S6>/Constant'
       */
      Controller_Y.Control_Out.actuator_cmd[i + 4] = 0U;
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

  /* Update for DiscreteIntegrator: '<S49>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S49>/ki'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S49>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE += CONTROL_PARAM.VEL_Z_I *
    rtb_Gain * 0.004F;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE >= CONTROL_PARAM.VEL_Z_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE = CONTROL_PARAM.VEL_Z_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE <= CONTROL_PARAM.VEL_Z_I_MIN)
    {
      Controller_DW.DiscreteTimeIntegrator_DSTATE = CONTROL_PARAM.VEL_Z_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* End of Update for DiscreteIntegrator: '<S49>/Discrete-Time Integrator' */

  /* Update for Delay: '<S52>/Delay1' */
  Controller_DW.icLoad = 0U;

  /* Update for Delay: '<S51>/Delay' */
  Controller_DW.icLoad_g = 0U;
  Controller_DW.Delay_DSTATE = Controller_DW.Delay1_DSTATE;

  /* Update for DiscreteIntegrator: '<S38>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S38>/ki'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S38>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_PrevRe_e = (int8_T)
    (Controller_U.FMS_Out.reset > 0);
  Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] += CONTROL_PARAM.VEL_XY_I *
    rtb_TrigoFcn1 * 0.004F;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] >=
      CONTROL_PARAM.VEL_XY_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
      CONTROL_PARAM.VEL_XY_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] <=
        CONTROL_PARAM.VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
        CONTROL_PARAM.VEL_XY_I_MIN;
    }
  }

  /* Update for DiscreteIntegrator: '<S40>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] += 0.004F * rtb_k_pt_idx_0;

  /* Update for DiscreteIntegrator: '<S38>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S38>/ki'
   *  Product: '<S38>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] += CONTROL_PARAM.VEL_XY_I *
    rtb_TrigoFcn * 0.004F;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] >=
      CONTROL_PARAM.VEL_XY_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
      CONTROL_PARAM.VEL_XY_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] <=
        CONTROL_PARAM.VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
        CONTROL_PARAM.VEL_XY_I_MIN;
    }
  }

  /* Update for DiscreteIntegrator: '<S40>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] += 0.004F * rtb_k_pt_idx_1;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S20>/Discrete-Time Integrator' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator_PrevRe_g = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for Delay: '<S23>/Delay1' */
  Controller_DW.icLoad_c = 0U;

  /* Update for Delay: '<S22>/Delay' */
  Controller_DW.icLoad_c2 = 0U;

  /* Update for DiscreteIntegrator: '<S20>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S20>/gain1'
   *  Product: '<S20>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] += CONTROL_PARAM.ROLL_RATE_I *
    rtb_Saturation_m * 0.004F;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] >=
      CONTROL_PARAM.RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] =
        CONTROL_PARAM.RATE_I_MIN;
    }
  }

  /* Update for Delay: '<S22>/Delay' */
  Controller_DW.Delay_DSTATE_b[0] = Controller_DW.Delay1_DSTATE_d[0];

  /* Update for DiscreteIntegrator: '<S20>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S20>/gain2'
   *  Product: '<S20>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] += CONTROL_PARAM.PITCH_RATE_I
    * rtb_Atan_idx_0 * 0.004F;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] >=
      CONTROL_PARAM.RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] =
        CONTROL_PARAM.RATE_I_MIN;
    }
  }

  /* Update for Delay: '<S22>/Delay' */
  Controller_DW.Delay_DSTATE_b[1] = Controller_DW.Delay1_DSTATE_d[1];

  /* Update for DiscreteIntegrator: '<S20>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S20>/gain3'
   *  Product: '<S20>/Multiply'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] += CONTROL_PARAM.YAW_RATE_I *
    rtb_Atan_idx_1 * 0.004F;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] >=
      CONTROL_PARAM.RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] =
        CONTROL_PARAM.RATE_I_MIN;
    }
  }

  /* Update for Delay: '<S22>/Delay' */
  Controller_DW.Delay_DSTATE_b[2] = Controller_DW.Delay1_DSTATE_d[2];

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
  Controller_PrevZCX.Delay1_Reset_ZCE = UNINITIALIZED_ZCSIG;
  Controller_PrevZCX.Delay_Reset_ZCE = UNINITIALIZED_ZCSIG;
  Controller_PrevZCX.Delay1_Reset_ZCE_p = UNINITIALIZED_ZCSIG;
  Controller_PrevZCX.Delay_Reset_ZCE_b = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for DiscreteIntegrator: '<S49>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE = Controller_ConstB.Constant;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE >= CONTROL_PARAM.VEL_Z_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE = CONTROL_PARAM.VEL_Z_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE <= CONTROL_PARAM.VEL_Z_I_MIN)
    {
      Controller_DW.DiscreteTimeIntegrator_DSTATE = CONTROL_PARAM.VEL_Z_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRese = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S49>/Discrete-Time Integrator' */

  /* InitializeConditions for Delay: '<S52>/Delay1' */
  Controller_DW.icLoad = 1U;

  /* InitializeConditions for Delay: '<S51>/Delay' */
  Controller_DW.icLoad_g = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S38>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
    Controller_ConstB.Constant_g;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] >=
      CONTROL_PARAM.VEL_XY_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
      CONTROL_PARAM.VEL_XY_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] <=
        CONTROL_PARAM.VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m[0] =
        CONTROL_PARAM.VEL_XY_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
    Controller_ConstB.Constant_g;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] >=
      CONTROL_PARAM.VEL_XY_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
      CONTROL_PARAM.VEL_XY_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] <=
        CONTROL_PARAM.VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_m[1] =
        CONTROL_PARAM.VEL_XY_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRe_e = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S38>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S40>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S20>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] =
    Controller_ConstB.Constant_n[0];
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] >=
      CONTROL_PARAM.RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[0] =
        CONTROL_PARAM.RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] =
    Controller_ConstB.Constant_n[1];
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] >=
      CONTROL_PARAM.RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[1] =
        CONTROL_PARAM.RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] =
    Controller_ConstB.Constant_n[2];
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] >=
      CONTROL_PARAM.RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] = CONTROL_PARAM.RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] <=
        CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_o[2] =
        CONTROL_PARAM.RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRe_g = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S20>/Discrete-Time Integrator' */

  /* InitializeConditions for Delay: '<S23>/Delay1' */
  Controller_DW.icLoad_c = 1U;

  /* InitializeConditions for Delay: '<S22>/Delay' */
  Controller_DW.icLoad_c2 = 1U;
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
