/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.67
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Jul 24 10:38:02 2024
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
struct_04mtDUt8mpbOWDWTaHkfhC CONTROL_PARAM = {
  1.4F,
  0.2F,
  0.2F,
  0.6F,
  0.1F,
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
  0.52359879F,
  0.1F,
  0.1F,
  0.3F,
  0.1F,
  0.1F,
  0.2F,
  0.003F,
  0.003F,
  0.001F,
  -0.1F,
  0.1F,
  -0.1F,
  0.1F,
  1.57079637F,
  3.14159274F,
  0.5F,
  10.0F,
  20.0F,
  1.04719758F,
  0.1F,
  1.0F,
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
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  0.0F,
  0.1F,
  0.1F,
  0.1F,
  0.1F,
  0.1F,
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
  0.1F,
  0.1F,
  16.0F
} ;                                    /* Variable: CONTROL_PARAM
                                        * Referenced by:
                                        *   '<S122>/Gain'
                                        *   '<S122>/Gain1'
                                        *   '<S122>/balabnce_ratio2'
                                        *   '<S122>/balance_ratio'
                                        *   '<S122>/pitch_ff'
                                        *   '<S122>/thorttle_ff'
                                        *   '<S122>/ucmd2pitch'
                                        *   '<S122>/ucmd2thor'
                                        *   '<S122>/wcmd2pitch'
                                        *   '<S122>/wcmd2thor'
                                        *   '<S123>/Saturation'
                                        *   '<S41>/Saturation'
                                        *   '<S61>/hover_throttle'
                                        *   '<S124>/FF'
                                        *   '<S124>/FF_limit'
                                        *   '<S124>/PI_limit'
                                        *   '<S143>/P_control'
                                        *   '<S144>/P_control'
                                        *   '<S17>/Saturation'
                                        *   '<S17>/Saturation1'
                                        *   '<S50>/kd'
                                        *   '<S50>/Saturation'
                                        *   '<S51>/ki'
                                        *   '<S51>/Discrete-Time Integrator'
                                        *   '<S52>/kp'
                                        *   '<S71>/kd'
                                        *   '<S71>/Saturation'
                                        *   '<S72>/Constant'
                                        *   '<S72>/ki'
                                        *   '<S72>/Discrete-Time Integrator'
                                        *   '<S73>/kp'
                                        *   '<S87>/Saturation'
                                        *   '<S87>/Saturation1'
                                        *   '<S128>/trim_speed'
                                        *   '<S129>/trim_speed'
                                        *   '<S146>/Constant'
                                        *   '<S147>/Constant'
                                        *   '<S149>/Gain'
                                        *   '<S150>/ '
                                        *   '<S150>/Gain3'
                                        *   '<S152>/Gain'
                                        *   '<S153>/Gain'
                                        *   '<S155>/Constant'
                                        *   '<S160>/Constant1'
                                        *   '<S160>/Constant12'
                                        *   '<S160>/Constant2'
                                        *   '<S160>/Constant7'
                                        *   '<S167>/hover_throttle'
                                        *   '<S34>/Constant1'
                                        *   '<S34>/Constant2'
                                        *   '<S99>/Constant1'
                                        *   '<S99>/Constant2'
                                        *   '<S116>/kd'
                                        *   '<S116>/Saturation'
                                        *   '<S117>/Constant'
                                        *   '<S117>/ki'
                                        *   '<S117>/Discrete-Time Integrator'
                                        *   '<S118>/kp'
                                        *   '<S130>/gain1'
                                        *   '<S130>/gain2'
                                        *   '<S130>/gain3'
                                        *   '<S130>/Discrete-Time Integrator'
                                        *   '<S131>/gain1'
                                        *   '<S131>/gain2'
                                        *   '<S131>/gain3'
                                        *   '<S135>/Pitch Offset'
                                        *   '<S135>/Saturation'
                                        *   '<S136>/Constant1'
                                        *   '<S136>/Constant2'
                                        *   '<S23>/gain1'
                                        *   '<S23>/gain2'
                                        *   '<S23>/gain3'
                                        *   '<S23>/Saturation'
                                        *   '<S24>/gain1'
                                        *   '<S24>/gain2'
                                        *   '<S24>/gain3'
                                        *   '<S24>/Discrete-Time Integrator'
                                        *   '<S25>/gain1'
                                        *   '<S25>/gain2'
                                        *   '<S25>/gain3'
                                        *   '<S92>/gain1'
                                        *   '<S92>/gain2'
                                        *   '<S92>/gain3'
                                        *   '<S92>/Saturation'
                                        *   '<S93>/gain1'
                                        *   '<S93>/gain2'
                                        *   '<S93>/gain3'
                                        *   '<S93>/Discrete-Time Integrator'
                                        *   '<S94>/gain1'
                                        *   '<S94>/gain2'
                                        *   '<S94>/gain3'
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

/* Model step function */
void Controller_step(void)
{
  int8_T rtPrevAction;
  boolean_T rtb_Compare_ev;
  real32_T rtb_Add3_e;
  real32_T rtb_VectorConcatenate[9];
  real32_T rtb_Subtract3_g;
  real32_T rtb_Gain_ap;
  real32_T rtb_Gain_cq;
  real32_T rtb_Add_b;
  real32_T rtb_a;
  real32_T rtb_Add4_l;
  real32_T rtb_Multiply1;
  uint16_T rtb_throttle_cmd_m;
  int32_T rtb_Switch_a;
  real32_T rtb_MatrixConcatenate[12];
  real32_T rtb_Add_cx;
  uint16_T rtb_MultiportSwitch_o[4];
  uint16_T rtb_MultiportSwitch_b3[5];
  int32_T i;
  real32_T rtb_VectorConcatenate_0[3];
  real32_T rtb_Saturation_h_idx_1;
  real32_T rtb_a_m_idx_0;
  real32_T rtb_a_m_idx_1;
  real32_T rtb_DiscreteTimeIntegrator1_n_i;
  real32_T rtb_DiscreteTimeIntegrator1_n_0;
  real32_T rtb_uv_error_C_mPs_idx_0;
  real32_T rtb_uv_error_C_mPs_idx_1;
  real32_T rtb_rate_error_B_radPs_n_idx_1;
  real32_T rtb_rate_error_B_radPs_n_idx_2;
  real32_T rtb_Saturation_k_idx_1;
  real32_T rtb_Saturation_k_idx_2;
  real32_T rtb_Gain_b_idx_1;
  real32_T rtb_Gain_b_idx_0;
  real32_T rtb_rate_error_B_radPs_n_idx_0;
  real32_T rtb_Subtract3_idx_0;
  real32_T rtb_Subtract3_idx_1;
  uint16_T u0;
  real32_T u0_0;
  real32_T rtb_BitwiseAND_0;
  uint8_T rtb_BitwiseAND_p_tmp;
  uint32_T tmp;

  /* SwitchCase: '<S7>/Switch Case1' */
  rtPrevAction = Controller_DW.SwitchCase1_ActiveSubsystem;

  /* S-Function (sfix_bitop): '<S7>/Bitwise AND' incorporates:
   *  Inport: '<Root>/FMS_Out'
   *  S-Function (sfix_bitop): '<S5>/Bitwise AND'
   */
  tmp = Controller_U.FMS_Out.ctrl_mode & 128U;

  /* SwitchCase: '<S7>/Switch Case1' incorporates:
   *  Constant: '<S117>/Constant'
   *  Constant: '<S168>/Constant'
   *  Constant: '<S72>/Constant'
   *  Product: '<S101>/Divide1'
   *  Product: '<S36>/Divide1'
   *  Product: '<S50>/Multiply'
   *  RelationalOperator: '<S168>/Compare'
   *  S-Function (sfix_bitop): '<S7>/Bitwise AND'
   */
  if (tmp == 0U) {
    Controller_DW.SwitchCase1_ActiveSubsystem = 0;
  } else {
    Controller_DW.SwitchCase1_ActiveSubsystem = 1;
  }

  switch (Controller_DW.SwitchCase1_ActiveSubsystem) {
   case 0:
    if (Controller_DW.SwitchCase1_ActiveSubsystem != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S2>/MC_Controller' incorporates:
       *  ActionPort: '<S4>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S7>/Switch Case1' incorporates:
       *  DiscreteIntegrator: '<S22>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S24>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S26>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S46>/Integrator'
       *  DiscreteIntegrator: '<S46>/Integrator1'
       *  DiscreteIntegrator: '<S51>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S53>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S69>/Integrator'
       *  DiscreteIntegrator: '<S69>/Integrator1'
       *  DiscreteIntegrator: '<S72>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S74>/Discrete-Time Integrator1'
       */
      Controller_DW.Integrator1_DSTATE_e[0] = 0.0F;
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

      Controller_DW.Integrator1_DSTATE_e[1] = 0.0F;
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
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_m = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevR_a = 0;
      Controller_DW.DiscreteTimeIntegrator5_IC_LO_c = 1U;
      Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[0] =
        Controller_ConstB.Constant_a[0];
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[0] >=
          CONTROL_PARAM.MC_RATE_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[0] =
          CONTROL_PARAM.MC_RATE_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[0] <=
            CONTROL_PARAM.MC_RATE_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[0] =
            CONTROL_PARAM.MC_RATE_I_MIN;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[1] =
        Controller_ConstB.Constant_a[1];
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[1] >=
          CONTROL_PARAM.MC_RATE_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[1] =
          CONTROL_PARAM.MC_RATE_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[1] <=
            CONTROL_PARAM.MC_RATE_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[1] =
            CONTROL_PARAM.MC_RATE_I_MIN;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[2] =
        Controller_ConstB.Constant_a[2];
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[2] >=
          CONTROL_PARAM.MC_RATE_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[2] =
          CONTROL_PARAM.MC_RATE_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[2] <=
            CONTROL_PARAM.MC_RATE_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[2] =
            CONTROL_PARAM.MC_RATE_I_MIN;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_PrevRe_d = 0;
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevR_k = 0;
      Controller_DW.Integrator1_DSTATE_eq = 0.0F;
      Controller_DW.DiscreteTimeIntegrator_DSTAT_lc = Controller_B.Constant_b;
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_lc >=
          CONTROL_PARAM.MC_VEL_Z_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_lc =
          CONTROL_PARAM.MC_VEL_Z_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTAT_lc <=
            CONTROL_PARAM.MC_VEL_Z_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTAT_lc =
            CONTROL_PARAM.MC_VEL_Z_I_MIN;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_PrevRe_f = 0;
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 1U;
      Controller_DW.DiscreteTimeIntegrator1_Prev_ks = 0;
      Controller_DW.Integrator_DSTATE_l[0] = 0.0F;
      Controller_DW.Integrator_DSTATE_l[1] = 0.0F;
      Controller_DW.Integrator_DSTATE_j = 0.0F;

      /* End of InitializeConditions for SubSystem: '<S2>/MC_Controller' */
    }

    /* Outputs for IfAction SubSystem: '<S2>/MC_Controller' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* S-Function (sfix_bitop): '<S11>/Bitwise AND' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    rtb_BitwiseAND_p_tmp = (uint8_T)(Controller_U.FMS_Out.ctrl_mode & 127);

    /* Trigonometry: '<S48>/Trigonometric Function1' incorporates:
     *  Gain: '<S47>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S48>/Trigonometric Function3'
     */
    rtb_DiscreteTimeIntegrator1_n_i = arm_cos_f32(-Controller_U.INS_Out.psi);
    rtb_VectorConcatenate[0] = rtb_DiscreteTimeIntegrator1_n_i;

    /* Trigonometry: '<S48>/Trigonometric Function' incorporates:
     *  Gain: '<S47>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S48>/Trigonometric Function2'
     */
    rtb_a_m_idx_1 = arm_sin_f32(-Controller_U.INS_Out.psi);
    rtb_VectorConcatenate[1] = rtb_a_m_idx_1;

    /* SignalConversion: '<S48>/ConcatBufferAtVector Concatenate1In3' incorporates:
     *  Constant: '<S48>/Constant3'
     */
    rtb_VectorConcatenate[2] = 0.0F;

    /* Gain: '<S48>/Gain' */
    rtb_VectorConcatenate[3] = -rtb_a_m_idx_1;

    /* Trigonometry: '<S48>/Trigonometric Function3' */
    rtb_VectorConcatenate[4] = rtb_DiscreteTimeIntegrator1_n_i;

    /* SignalConversion: '<S48>/ConcatBufferAtVector Concatenate2In3' incorporates:
     *  Constant: '<S48>/Constant4'
     */
    rtb_VectorConcatenate[5] = 0.0F;

    /* SignalConversion: '<S48>/ConcatBufferAtVector ConcatenateIn3' */
    rtb_VectorConcatenate[6] = Controller_ConstB.VectorConcatenate3[0];
    rtb_VectorConcatenate[7] = Controller_ConstB.VectorConcatenate3[1];
    rtb_VectorConcatenate[8] = Controller_ConstB.VectorConcatenate3[2];

    /* Product: '<S45>/Multiply' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  SignalConversion: '<S45>/TmpSignal ConversionAtMultiplyInport2'
     */
    for (i = 0; i < 3; i++) {
      rtb_VectorConcatenate_0[i] = rtb_VectorConcatenate[i + 3] *
        Controller_U.INS_Out.ve + rtb_VectorConcatenate[i] *
        Controller_U.INS_Out.vn;
    }

    /* End of Product: '<S45>/Multiply' */

    /* Sum: '<S42>/Sum' incorporates:
     *  DiscreteIntegrator: '<S46>/Integrator1'
     */
    rtb_uv_error_C_mPs_idx_0 = Controller_DW.Integrator1_DSTATE_e[0] -
      rtb_VectorConcatenate_0[0];
    rtb_uv_error_C_mPs_idx_1 = Controller_DW.Integrator1_DSTATE_e[1] -
      rtb_VectorConcatenate_0[1];

    /* DiscreteIntegrator: '<S51>/Discrete-Time Integrator' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator_PrevRe_p != 0)) {
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

    /* DiscreteIntegrator: '<S53>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_m != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[0] =
        rtb_uv_error_C_mPs_idx_0;
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[1] =
        rtb_uv_error_C_mPs_idx_1;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_a != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[0] =
        rtb_uv_error_C_mPs_idx_0;
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[1] =
        rtb_uv_error_C_mPs_idx_1;
    }

    /* Gain: '<S53>/Gain' incorporates:
     *  DiscreteIntegrator: '<S53>/Discrete-Time Integrator1'
     *  Sum: '<S53>/Sum5'
     */
    rtb_Gain_b_idx_0 = (rtb_uv_error_C_mPs_idx_0 -
                        Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[0]) *
      62.831852F;
    rtb_Gain_b_idx_1 = (rtb_uv_error_C_mPs_idx_1 -
                        Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[1]) *
      62.831852F;

    /* Switch: '<S53>/Switch' incorporates:
     *  Gain: '<S53>/Gain1'
     *  Inport: '<Root>/FMS_Out'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_a_m_idx_0 = 0.0F;
      rtb_a_m_idx_1 = 0.0F;
    } else {
      rtb_a_m_idx_0 = rtb_Gain_b_idx_0;
      rtb_a_m_idx_1 = rtb_Gain_b_idx_1;
    }

    /* End of Switch: '<S53>/Switch' */

    /* Product: '<S50>/Multiply' incorporates:
     *  Constant: '<S50>/kd'
     */
    rtb_Subtract3_g = CONTROL_PARAM.MC_VEL_XY_D * rtb_a_m_idx_0;

    /* Saturate: '<S50>/Saturation' */
    if (rtb_Subtract3_g > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
      rtb_Subtract3_g = CONTROL_PARAM.MC_VEL_XY_D_MAX;
    } else {
      if (rtb_Subtract3_g < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
        rtb_Subtract3_g = CONTROL_PARAM.MC_VEL_XY_D_MIN;
      }
    }

    rtb_a_m_idx_0 = rtb_Subtract3_g;

    /* Product: '<S50>/Multiply' incorporates:
     *  Constant: '<S50>/kd'
     */
    rtb_Subtract3_g = CONTROL_PARAM.MC_VEL_XY_D * rtb_a_m_idx_1;

    /* Saturate: '<S50>/Saturation' */
    if (rtb_Subtract3_g > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
      rtb_Subtract3_g = CONTROL_PARAM.MC_VEL_XY_D_MAX;
    } else {
      if (rtb_Subtract3_g < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
        rtb_Subtract3_g = CONTROL_PARAM.MC_VEL_XY_D_MIN;
      }
    }

    /* Switch: '<S44>/Switch' incorporates:
     *  Constant: '<S52>/kp'
     *  Constant: '<S54>/Constant'
     *  Constant: '<S56>/Constant'
     *  Constant: '<S57>/Constant'
     *  DiscreteIntegrator: '<S51>/Discrete-Time Integrator'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S52>/Multiply'
     *  Product: '<S55>/Multiply2'
     *  Product: '<S55>/Multiply3'
     *  RelationalOperator: '<S54>/Compare'
     *  RelationalOperator: '<S56>/Compare'
     *  RelationalOperator: '<S57>/Compare'
     *  S-Function (sfix_bitop): '<S11>/Bitwise AND'
     *  S-Function (sfix_bitop): '<S55>/cmd_ax valid'
     *  S-Function (sfix_bitop): '<S55>/cmd_ay valid'
     *  S-Function (sfix_bitop): '<S55>/cmd_u valid'
     *  S-Function (sfix_bitop): '<S55>/cmd_v valid'
     *  Sum: '<S43>/Add'
     *  Sum: '<S55>/Sum1'
     */
    if (rtb_BitwiseAND_p_tmp == 6) {
      rtb_a_m_idx_0 = ((Controller_U.FMS_Out.cmd_mask & 64) > 0 ?
                       (CONTROL_PARAM.MC_VEL_XY_P * rtb_uv_error_C_mPs_idx_0 +
                        Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0]) +
                       rtb_a_m_idx_0 : 0.0F) + ((Controller_U.FMS_Out.cmd_mask &
        512) > 0 ? Controller_U.FMS_Out.ax_cmd : 0.0F);
      rtb_a_m_idx_1 = ((Controller_U.FMS_Out.cmd_mask & 128) > 0 ?
                       (CONTROL_PARAM.MC_VEL_XY_P * rtb_uv_error_C_mPs_idx_1 +
                        Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1]) +
                       rtb_Subtract3_g : 0.0F) + ((Controller_U.FMS_Out.cmd_mask
        & 1024) > 0 ? Controller_U.FMS_Out.ay_cmd : 0.0F);
    } else {
      rtb_a_m_idx_0 += CONTROL_PARAM.MC_VEL_XY_P * rtb_uv_error_C_mPs_idx_0 +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0];
      rtb_a_m_idx_1 = (CONTROL_PARAM.MC_VEL_XY_P * rtb_uv_error_C_mPs_idx_1 +
                       Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1]) +
        rtb_Subtract3_g;
    }

    /* End of Switch: '<S44>/Switch' */

    /* Trigonometry: '<S41>/Atan' incorporates:
     *  Constant: '<S41>/g'
     *  Gain: '<S41>/Gain1'
     *  Gain: '<S41>/gain'
     *  Product: '<S41>/Divide'
     */
    rtb_Add4_l = atanf(1.1F * rtb_a_m_idx_1 / 9.8055F);
    rtb_a_m_idx_1 = atanf(1.1F * -rtb_a_m_idx_0 / 9.8055F);

    /* Switch: '<S32>/Switch' incorporates:
     *  Constant: '<S39>/Constant'
     *  Inport: '<Root>/FMS_Out'
     *  Logic: '<S32>/Logical Operator'
     *  RelationalOperator: '<S38>/Compare'
     *  RelationalOperator: '<S39>/Compare'
     *  S-Function (sfix_bitop): '<S11>/Bitwise AND'
     *  Saturate: '<S41>/Saturation'
     *  Switch: '<S32>/Switch1'
     */
    if ((rtb_BitwiseAND_p_tmp == 3) || (rtb_BitwiseAND_p_tmp == 4)) {
      rtb_a_m_idx_0 = Controller_U.FMS_Out.phi_cmd;
      rtb_a_m_idx_1 = Controller_U.FMS_Out.theta_cmd;
    } else if (rtb_BitwiseAND_p_tmp == 6) {
      /* Switch: '<S40>/Switch' incorporates:
       *  Inport: '<Root>/FMS_Out'
       *  S-Function (sfix_bitop): '<S40>/cmd_phi valid'
       *  S-Function (sfix_bitop): '<S40>/cmd_theta valid'
       *  Saturate: '<S41>/Saturation'
       *  Switch: '<S32>/Switch1'
       */
      if ((Controller_U.FMS_Out.cmd_mask & 8) > 0) {
        rtb_a_m_idx_0 = Controller_U.FMS_Out.phi_cmd;
      } else if (rtb_Add4_l > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S41>/Saturation' */
        rtb_a_m_idx_0 = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else if (rtb_Add4_l < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S41>/Saturation' */
        rtb_a_m_idx_0 = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        rtb_a_m_idx_0 = rtb_Add4_l;
      }

      if ((Controller_U.FMS_Out.cmd_mask & 16) > 0) {
        rtb_a_m_idx_1 = Controller_U.FMS_Out.theta_cmd;
      } else if (rtb_a_m_idx_1 > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S41>/Saturation' */
        rtb_a_m_idx_1 = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_a_m_idx_1 < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Saturate: '<S41>/Saturation' */
          rtb_a_m_idx_1 = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        }
      }

      /* End of Switch: '<S40>/Switch' */
    } else {
      if (rtb_Add4_l > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S41>/Saturation' incorporates:
         *  Switch: '<S32>/Switch1'
         */
        rtb_a_m_idx_0 = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else if (rtb_Add4_l < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S41>/Saturation' incorporates:
         *  Switch: '<S32>/Switch1'
         */
        rtb_a_m_idx_0 = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        /* Switch: '<S32>/Switch1' incorporates:
         *  Saturate: '<S41>/Saturation'
         */
        rtb_a_m_idx_0 = rtb_Add4_l;
      }

      /* Saturate: '<S41>/Saturation' */
      if (rtb_a_m_idx_1 > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Switch: '<S32>/Switch1' */
        rtb_a_m_idx_1 = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_a_m_idx_1 < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Switch: '<S32>/Switch1' */
          rtb_a_m_idx_1 = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        }
      }
    }

    /* End of Switch: '<S32>/Switch' */

    /* Sum: '<S33>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Subtract3_g = rtb_a_m_idx_0 - Controller_U.INS_Out.phi;

    /* Product: '<S36>/Divide1' incorporates:
     *  Abs: '<S36>/Abs'
     *  Constant: '<S36>/const2'
     */
    rtb_DiscreteTimeIntegrator1_n_i = fabsf(rtb_Subtract3_g) / 0.002F;

    /* Product: '<S36>/Divide' incorporates:
     *  Constant: '<S34>/Constant1'
     *  Constant: '<S36>/const1'
     *  Math: '<S36>/Square'
     *  SignalConversion: '<S36>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_rate_error_B_radPs_n_idx_1 = 9.5993F / (CONTROL_PARAM.MC_ROLL_P *
      CONTROL_PARAM.MC_ROLL_P);

    /* Signum: '<S36>/Sign' */
    if (rtb_Subtract3_g < 0.0F) {
      rtb_rate_error_B_radPs_n_idx_0 = -1.0F;
    } else if (rtb_Subtract3_g > 0.0F) {
      rtb_rate_error_B_radPs_n_idx_0 = 1.0F;
    } else {
      rtb_rate_error_B_radPs_n_idx_0 = rtb_Subtract3_g;
    }

    /* Switch: '<S36>/Switch' incorporates:
     *  Constant: '<S34>/Constant1'
     *  Gain: '<S36>/Gain1'
     *  Gain: '<S36>/Gain2'
     *  Logic: '<S36>/Logical Operator'
     *  Product: '<S36>/Divide'
     *  Product: '<S36>/Multiply'
     *  Product: '<S36>/Multiply1'
     *  Product: '<S36>/Multiply2'
     *  Product: '<S36>/Multiply3'
     *  RelationalOperator: '<S36>/Relational Operator'
     *  RelationalOperator: '<S36>/Relational Operator2'
     *  SignalConversion: '<S36>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S36>/Sqrt'
     *  Sum: '<S36>/Subtract'
     */
    if ((rtb_Subtract3_g <= rtb_rate_error_B_radPs_n_idx_1) && (rtb_Subtract3_g >=
         -rtb_rate_error_B_radPs_n_idx_1)) {
      rtb_rate_error_B_radPs_n_idx_0 = rtb_Subtract3_g * CONTROL_PARAM.MC_ROLL_P;
    } else {
      rtb_rate_error_B_radPs_n_idx_0 *= sqrtf((rtb_rate_error_B_radPs_n_idx_0 *
        rtb_Subtract3_g - 0.5F * rtb_rate_error_B_radPs_n_idx_1) *
        Controller_ConstB.Gain_d);
    }

    /* Gain: '<S36>/Gain3' */
    rtb_Add4_l = -rtb_DiscreteTimeIntegrator1_n_i;

    /* Switch: '<S37>/Switch' incorporates:
     *  Gain: '<S36>/Gain3'
     *  RelationalOperator: '<S37>/UpperRelop'
     */
    if (rtb_rate_error_B_radPs_n_idx_0 >= -rtb_DiscreteTimeIntegrator1_n_i) {
      rtb_Add4_l = rtb_rate_error_B_radPs_n_idx_0;
    }

    /* Switch: '<S37>/Switch2' incorporates:
     *  RelationalOperator: '<S37>/LowerRelop1'
     */
    if (rtb_rate_error_B_radPs_n_idx_0 <= rtb_DiscreteTimeIntegrator1_n_i) {
      rtb_DiscreteTimeIntegrator1_n_i = rtb_Add4_l;
    }

    /* Saturate: '<S17>/Saturation1' */
    if (rtb_DiscreteTimeIntegrator1_n_i > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_DiscreteTimeIntegrator1_n_i = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_DiscreteTimeIntegrator1_n_i < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_DiscreteTimeIntegrator1_n_i = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    rtb_a_m_idx_0 = rtb_DiscreteTimeIntegrator1_n_i;

    /* Sum: '<S33>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S36>/Divide1'
     */
    rtb_Subtract3_g = rtb_a_m_idx_1 - Controller_U.INS_Out.theta;

    /* Product: '<S36>/Divide1' incorporates:
     *  Abs: '<S36>/Abs'
     *  Constant: '<S36>/const2'
     */
    rtb_DiscreteTimeIntegrator1_n_i = fabsf(rtb_Subtract3_g) / 0.002F;

    /* Product: '<S36>/Divide' incorporates:
     *  Constant: '<S34>/Constant2'
     *  Constant: '<S36>/const1'
     *  Math: '<S36>/Square'
     *  SignalConversion: '<S36>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_rate_error_B_radPs_n_idx_1 = 9.5993F / (CONTROL_PARAM.MC_PITCH_P *
      CONTROL_PARAM.MC_PITCH_P);

    /* Signum: '<S36>/Sign' */
    if (rtb_Subtract3_g < 0.0F) {
      rtb_rate_error_B_radPs_n_idx_0 = -1.0F;
    } else if (rtb_Subtract3_g > 0.0F) {
      rtb_rate_error_B_radPs_n_idx_0 = 1.0F;
    } else {
      rtb_rate_error_B_radPs_n_idx_0 = rtb_Subtract3_g;
    }

    /* Switch: '<S36>/Switch' incorporates:
     *  Constant: '<S34>/Constant2'
     *  Gain: '<S36>/Gain1'
     *  Gain: '<S36>/Gain2'
     *  Logic: '<S36>/Logical Operator'
     *  Product: '<S36>/Divide'
     *  Product: '<S36>/Multiply'
     *  Product: '<S36>/Multiply1'
     *  Product: '<S36>/Multiply2'
     *  Product: '<S36>/Multiply3'
     *  RelationalOperator: '<S36>/Relational Operator'
     *  RelationalOperator: '<S36>/Relational Operator2'
     *  SignalConversion: '<S36>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S36>/Sqrt'
     *  Sum: '<S36>/Subtract'
     */
    if ((rtb_Subtract3_g <= rtb_rate_error_B_radPs_n_idx_1) && (rtb_Subtract3_g >=
         -rtb_rate_error_B_radPs_n_idx_1)) {
      rtb_rate_error_B_radPs_n_idx_0 = rtb_Subtract3_g *
        CONTROL_PARAM.MC_PITCH_P;
    } else {
      rtb_rate_error_B_radPs_n_idx_0 *= sqrtf((rtb_rate_error_B_radPs_n_idx_0 *
        rtb_Subtract3_g - 0.5F * rtb_rate_error_B_radPs_n_idx_1) *
        Controller_ConstB.Gain_d);
    }

    /* Gain: '<S36>/Gain3' */
    rtb_Add4_l = -rtb_DiscreteTimeIntegrator1_n_i;

    /* Switch: '<S37>/Switch' incorporates:
     *  Gain: '<S36>/Gain3'
     *  RelationalOperator: '<S37>/UpperRelop'
     */
    if (rtb_rate_error_B_radPs_n_idx_0 >= -rtb_DiscreteTimeIntegrator1_n_i) {
      rtb_Add4_l = rtb_rate_error_B_radPs_n_idx_0;
    }

    /* Switch: '<S37>/Switch2' incorporates:
     *  RelationalOperator: '<S37>/LowerRelop1'
     */
    if (rtb_rate_error_B_radPs_n_idx_0 <= rtb_DiscreteTimeIntegrator1_n_i) {
      rtb_DiscreteTimeIntegrator1_n_i = rtb_Add4_l;
    }

    /* Saturate: '<S17>/Saturation1' */
    if (rtb_DiscreteTimeIntegrator1_n_i > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_DiscreteTimeIntegrator1_n_i = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_DiscreteTimeIntegrator1_n_i < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_DiscreteTimeIntegrator1_n_i = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    /* Saturate: '<S17>/Saturation' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    if (Controller_U.FMS_Out.psi_rate_cmd > CONTROL_PARAM.MC_R_CMD_LIM) {
      rtb_Subtract3_g = CONTROL_PARAM.MC_R_CMD_LIM;
    } else if (Controller_U.FMS_Out.psi_rate_cmd < -CONTROL_PARAM.MC_R_CMD_LIM)
    {
      rtb_Subtract3_g = -CONTROL_PARAM.MC_R_CMD_LIM;
    } else {
      rtb_Subtract3_g = Controller_U.FMS_Out.psi_rate_cmd;
    }

    /* End of Saturate: '<S17>/Saturation' */

    /* Trigonometry: '<S27>/Sin' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_rate_error_B_radPs_n_idx_2 = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S27>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_rate_error_B_radPs_n_idx_0 = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Product: '<S27>/Multiply3' incorporates:
     *  Trigonometry: '<S27>/Cos1'
     *  Trigonometry: '<S27>/Sin'
     */
    rtb_a_m_idx_1 = rtb_rate_error_B_radPs_n_idx_2 *
      rtb_rate_error_B_radPs_n_idx_0 * rtb_Subtract3_g;

    /* Trigonometry: '<S27>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_rate_error_B_radPs_n_idx_1 = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Product: '<S27>/Multiply1' incorporates:
     *  Trigonometry: '<S27>/Cos'
     */
    rtb_DiscreteTimeIntegrator1_n_0 = rtb_rate_error_B_radPs_n_idx_1 *
      rtb_DiscreteTimeIntegrator1_n_i;

    /* Product: '<S27>/Multiply4' incorporates:
     *  Trigonometry: '<S27>/Sin'
     */
    rtb_Add3_e = rtb_rate_error_B_radPs_n_idx_2 *
      rtb_DiscreteTimeIntegrator1_n_i;

    /* Switch: '<S18>/Switch' incorporates:
     *  Constant: '<S28>/Constant'
     *  Constant: '<S29>/Constant'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S28>/Compare'
     *  RelationalOperator: '<S29>/Compare'
     *  S-Function (sfix_bitop): '<S11>/Bitwise AND'
     *  Switch: '<S18>/Switch1'
     */
    if (rtb_BitwiseAND_p_tmp == 2) {
      rtb_DiscreteTimeIntegrator1_n_i = Controller_U.FMS_Out.p_cmd;
      rtb_a_m_idx_1 = Controller_U.FMS_Out.q_cmd;
      rtb_DiscreteTimeIntegrator1_n_0 = Controller_U.FMS_Out.r_cmd;
    } else if (rtb_BitwiseAND_p_tmp == 6) {
      /* Switch: '<S30>/Switch' incorporates:
       *  Inport: '<Root>/FMS_Out'
       *  Inport: '<Root>/INS_Out'
       *  Product: '<S27>/Multiply'
       *  Product: '<S27>/Multiply1'
       *  Product: '<S27>/Multiply5'
       *  S-Function (sfix_bitop): '<S30>/cmd_p valid'
       *  S-Function (sfix_bitop): '<S30>/cmd_q valid'
       *  S-Function (sfix_bitop): '<S30>/cmd_r valid'
       *  Sum: '<S27>/Add'
       *  Sum: '<S27>/Add1'
       *  Sum: '<S27>/Add2'
       *  Switch: '<S18>/Switch1'
       *  Trigonometry: '<S27>/Cos'
       *  Trigonometry: '<S27>/Cos1'
       *  Trigonometry: '<S27>/Sin1'
       */
      if ((Controller_U.FMS_Out.cmd_mask & 1) > 0) {
        rtb_DiscreteTimeIntegrator1_n_i = Controller_U.FMS_Out.p_cmd;
      } else {
        rtb_DiscreteTimeIntegrator1_n_i = rtb_a_m_idx_0 - arm_sin_f32
          (Controller_U.INS_Out.theta) * rtb_Subtract3_g;
      }

      if ((Controller_U.FMS_Out.cmd_mask & 2) > 0) {
        rtb_a_m_idx_1 = Controller_U.FMS_Out.q_cmd;
      } else {
        rtb_a_m_idx_1 += rtb_DiscreteTimeIntegrator1_n_0;
      }

      if ((Controller_U.FMS_Out.cmd_mask & 4) > 0) {
        rtb_DiscreteTimeIntegrator1_n_0 = Controller_U.FMS_Out.r_cmd;
      } else {
        rtb_DiscreteTimeIntegrator1_n_0 = rtb_rate_error_B_radPs_n_idx_1 *
          rtb_rate_error_B_radPs_n_idx_0 * rtb_Subtract3_g - rtb_Add3_e;
      }

      /* End of Switch: '<S30>/Switch' */
    } else {
      /* Switch: '<S18>/Switch1' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Product: '<S27>/Multiply'
       *  Product: '<S27>/Multiply3'
       *  Product: '<S27>/Multiply5'
       *  Sum: '<S27>/Add'
       *  Sum: '<S27>/Add1'
       *  Sum: '<S27>/Add2'
       *  Trigonometry: '<S27>/Cos'
       *  Trigonometry: '<S27>/Cos1'
       *  Trigonometry: '<S27>/Sin1'
       */
      rtb_DiscreteTimeIntegrator1_n_i = rtb_a_m_idx_0 - arm_sin_f32
        (Controller_U.INS_Out.theta) * rtb_Subtract3_g;
      rtb_a_m_idx_1 += rtb_DiscreteTimeIntegrator1_n_0;
      rtb_DiscreteTimeIntegrator1_n_0 = rtb_rate_error_B_radPs_n_idx_1 *
        rtb_rate_error_B_radPs_n_idx_0 * rtb_Subtract3_g - rtb_Add3_e;
    }

    /* End of Switch: '<S18>/Switch' */

    /* Sum: '<S19>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_rate_error_B_radPs_n_idx_0 = rtb_DiscreteTimeIntegrator1_n_i -
      Controller_U.INS_Out.p;
    rtb_rate_error_B_radPs_n_idx_1 = rtb_a_m_idx_1 - Controller_U.INS_Out.q;
    rtb_rate_error_B_radPs_n_idx_2 = rtb_DiscreteTimeIntegrator1_n_0 -
      Controller_U.INS_Out.r;

    /* DiscreteIntegrator: '<S22>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_c != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0] =
        rtb_rate_error_B_radPs_n_idx_0;
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1] =
        rtb_rate_error_B_radPs_n_idx_1;
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2] =
        rtb_rate_error_B_radPs_n_idx_2;
    }

    /* DiscreteIntegrator: '<S24>/Discrete-Time Integrator' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator_PrevRe_d != 0)) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[0] =
        Controller_ConstB.Constant_a[0];
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[0] >=
          CONTROL_PARAM.MC_RATE_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[0] =
          CONTROL_PARAM.MC_RATE_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[0] <=
            CONTROL_PARAM.MC_RATE_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[0] =
            CONTROL_PARAM.MC_RATE_I_MIN;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[1] =
        Controller_ConstB.Constant_a[1];
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[1] >=
          CONTROL_PARAM.MC_RATE_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[1] =
          CONTROL_PARAM.MC_RATE_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[1] <=
            CONTROL_PARAM.MC_RATE_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[1] =
            CONTROL_PARAM.MC_RATE_I_MIN;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[2] =
        Controller_ConstB.Constant_a[2];
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[2] >=
          CONTROL_PARAM.MC_RATE_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[2] =
          CONTROL_PARAM.MC_RATE_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[2] <=
            CONTROL_PARAM.MC_RATE_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[2] =
            CONTROL_PARAM.MC_RATE_I_MIN;
        }
      }
    }

    if (Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[0] >=
        CONTROL_PARAM.MC_RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[0] =
        CONTROL_PARAM.MC_RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[0] <=
          CONTROL_PARAM.MC_RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[0] =
          CONTROL_PARAM.MC_RATE_I_MIN;
      }
    }

    if (Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[1] >=
        CONTROL_PARAM.MC_RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[1] =
        CONTROL_PARAM.MC_RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[1] <=
          CONTROL_PARAM.MC_RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[1] =
          CONTROL_PARAM.MC_RATE_I_MIN;
      }
    }

    if (Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[2] >=
        CONTROL_PARAM.MC_RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[2] =
        CONTROL_PARAM.MC_RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[2] <=
          CONTROL_PARAM.MC_RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[2] =
          CONTROL_PARAM.MC_RATE_I_MIN;
      }
    }

    /* DiscreteIntegrator: '<S26>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S22>/Discrete-Time Integrator5'
     *  Inport: '<Root>/FMS_Out'
     */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_j != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm[0] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0];
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm[1] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1];
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm[2] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2];
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_k != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm[0] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0];
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm[1] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1];
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm[2] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2];
    }

    /* Gain: '<S26>/Gain' incorporates:
     *  DiscreteIntegrator: '<S22>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S26>/Discrete-Time Integrator1'
     *  Sum: '<S26>/Sum5'
     */
    rtb_DiscreteTimeIntegrator1_n_i =
      (Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0] -
       Controller_DW.DiscreteTimeIntegrator1_DSTA_nm[0]) * 188.49556F;
    rtb_a_m_idx_1 = (Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1] -
                     Controller_DW.DiscreteTimeIntegrator1_DSTA_nm[1]) *
      188.49556F;
    rtb_DiscreteTimeIntegrator1_n_0 =
      (Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2] -
       Controller_DW.DiscreteTimeIntegrator1_DSTA_nm[2]) * 188.49556F;

    /* Gain: '<S67>/Gain' incorporates:
     *  DiscreteIntegrator: '<S69>/Integrator1'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S67>/Sum1'
     */
    rtb_Gain_ap = -(Controller_DW.Integrator1_DSTATE_eq -
                    Controller_U.INS_Out.vd);
    Controller_B.Constant_b = CONTROL_PARAM.MC_VEL_Z_I_MIN;

    /* DiscreteIntegrator: '<S72>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S72>/Constant'
     *  Inport: '<Root>/FMS_Out'
     */
    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator_PrevRe_f != 0)) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_lc = Controller_B.Constant_b;
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_lc >=
          CONTROL_PARAM.MC_VEL_Z_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_lc =
          CONTROL_PARAM.MC_VEL_Z_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTAT_lc <=
            CONTROL_PARAM.MC_VEL_Z_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTAT_lc =
            CONTROL_PARAM.MC_VEL_Z_I_MIN;
        }
      }
    }

    if (Controller_DW.DiscreteTimeIntegrator_DSTAT_lc >=
        CONTROL_PARAM.MC_VEL_Z_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_lc =
        CONTROL_PARAM.MC_VEL_Z_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_lc <=
          CONTROL_PARAM.MC_VEL_Z_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_lc =
          CONTROL_PARAM.MC_VEL_Z_I_MIN;
      }
    }

    /* DiscreteIntegrator: '<S74>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_d != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i = rtb_Gain_ap;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_Prev_ks != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i = rtb_Gain_ap;
    }

    /* Gain: '<S74>/Gain' incorporates:
     *  DiscreteIntegrator: '<S74>/Discrete-Time Integrator1'
     *  Sum: '<S74>/Sum5'
     */
    rtb_Gain_cq = (rtb_Gain_ap - Controller_DW.DiscreteTimeIntegrator1_DSTAT_i) *
      62.831852F;

    /* Switch: '<S74>/Switch' incorporates:
     *  Gain: '<S74>/Gain1'
     *  Inport: '<Root>/FMS_Out'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_BitwiseAND_0 = 0.0F;
    } else {
      rtb_BitwiseAND_0 = rtb_Gain_cq;
    }

    /* End of Switch: '<S74>/Switch' */

    /* Product: '<S71>/Multiply' incorporates:
     *  Constant: '<S71>/kd'
     */
    rtb_Subtract3_g = CONTROL_PARAM.MC_VEL_Z_D * rtb_BitwiseAND_0;

    /* Saturate: '<S71>/Saturation' */
    if (rtb_Subtract3_g > CONTROL_PARAM.MC_VEL_Z_D_MAX) {
      rtb_Subtract3_g = CONTROL_PARAM.MC_VEL_Z_D_MAX;
    } else {
      if (rtb_Subtract3_g < CONTROL_PARAM.MC_VEL_Z_D_MIN) {
        rtb_Subtract3_g = CONTROL_PARAM.MC_VEL_Z_D_MIN;
      }
    }

    /* End of Saturate: '<S71>/Saturation' */

    /* Sum: '<S68>/Add' incorporates:
     *  Constant: '<S73>/kp'
     *  DiscreteIntegrator: '<S72>/Discrete-Time Integrator'
     *  Product: '<S73>/Multiply'
     */
    rtb_Add_b = (CONTROL_PARAM.MC_VEL_Z_P * rtb_Gain_ap +
                 Controller_DW.DiscreteTimeIntegrator_DSTAT_lc) +
      rtb_Subtract3_g;

    /* Product: '<S66>/Multiply' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S66>/Cos'
     *  Trigonometry: '<S66>/Cos1'
     */
    rtb_Subtract3_g = arm_cos_f32(Controller_U.INS_Out.phi) * arm_cos_f32
      (Controller_U.INS_Out.theta);

    /* Saturate: '<S66>/Saturation1' */
    if (rtb_Subtract3_g > 1.0F) {
      rtb_Add3_e = 1.0F;
    } else if (rtb_Subtract3_g < 0.5F) {
      rtb_Add3_e = 0.5F;
    } else {
      rtb_Add3_e = rtb_Subtract3_g;
    }

    /* End of Saturate: '<S66>/Saturation1' */

    /* Gain: '<S66>/Gain' */
    rtb_Subtract3_g *= 2.0F;

    /* Saturate: '<S66>/Saturation' */
    if (rtb_Subtract3_g > 1.0F) {
      rtb_Subtract3_g = 1.0F;
    } else {
      if (rtb_Subtract3_g < 0.0F) {
        rtb_Subtract3_g = 0.0F;
      }
    }

    /* End of Saturate: '<S66>/Saturation' */

    /* Product: '<S66>/Multiply1' incorporates:
     *  Constant: '<S66>/Constant'
     *  Product: '<S66>/Divide'
     */
    rtb_Subtract3_g *= 1.0F / rtb_Add3_e * rtb_Add_b;

    /* Outputs for Atomic SubSystem: '<S9>/Quadcopter_x' */
    /* MultiPortSwitch: '<S60>/Multiport Switch' incorporates:
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S23>/Multiply'
     */
    switch (Controller_U.FMS_Out.status) {
     case 1:
      rtb_MultiportSwitch_o[0] = 1000U;
      rtb_MultiportSwitch_o[1] = 1000U;
      rtb_MultiportSwitch_o[2] = 1000U;
      rtb_MultiportSwitch_o[3] = 1000U;
      break;

     case 2:
      rtb_MultiportSwitch_o[0] = 1150U;
      rtb_MultiportSwitch_o[1] = 1150U;
      rtb_MultiportSwitch_o[2] = 1150U;
      rtb_MultiportSwitch_o[3] = 1150U;
      break;

     case 3:
      /* Switch: '<S26>/Switch' incorporates:
       *  Gain: '<S26>/Gain1'
       */
      if (Controller_U.FMS_Out.reset > 0) {
        rtb_Add_b = 0.0F;
        rtb_Saturation_k_idx_1 = 0.0F;
        rtb_Saturation_k_idx_2 = 0.0F;
      } else {
        rtb_Add_b = rtb_DiscreteTimeIntegrator1_n_i;
        rtb_Saturation_k_idx_1 = rtb_a_m_idx_1;
        rtb_Saturation_k_idx_2 = rtb_DiscreteTimeIntegrator1_n_0;
      }

      /* End of Switch: '<S26>/Switch' */

      /* Product: '<S23>/Multiply' incorporates:
       *  Constant: '<S23>/gain1'
       */
      rtb_Saturation_h_idx_1 = CONTROL_PARAM.MC_ROLL_RATE_D * rtb_Add_b;

      /* Saturate: '<S23>/Saturation' */
      if (rtb_Saturation_h_idx_1 > CONTROL_PARAM.MC_RATE_D_MAX) {
        rtb_Saturation_h_idx_1 = CONTROL_PARAM.MC_RATE_D_MAX;
      } else {
        if (rtb_Saturation_h_idx_1 < CONTROL_PARAM.MC_RATE_D_MIN) {
          rtb_Saturation_h_idx_1 = CONTROL_PARAM.MC_RATE_D_MIN;
        }
      }

      rtb_Add_b = rtb_Saturation_h_idx_1;

      /* Product: '<S23>/Multiply' incorporates:
       *  Constant: '<S23>/gain2'
       */
      rtb_Saturation_h_idx_1 = CONTROL_PARAM.MC_PITCH_RATE_D *
        rtb_Saturation_k_idx_1;

      /* Saturate: '<S23>/Saturation' */
      if (rtb_Saturation_h_idx_1 > CONTROL_PARAM.MC_RATE_D_MAX) {
        rtb_Saturation_h_idx_1 = CONTROL_PARAM.MC_RATE_D_MAX;
      } else {
        if (rtb_Saturation_h_idx_1 < CONTROL_PARAM.MC_RATE_D_MIN) {
          rtb_Saturation_h_idx_1 = CONTROL_PARAM.MC_RATE_D_MIN;
        }
      }

      rtb_Saturation_k_idx_1 = rtb_Saturation_h_idx_1;

      /* Product: '<S23>/Multiply' incorporates:
       *  Constant: '<S23>/gain3'
       */
      rtb_Saturation_h_idx_1 = CONTROL_PARAM.MC_YAW_RATE_D *
        rtb_Saturation_k_idx_2;

      /* Saturate: '<S23>/Saturation' */
      if (rtb_Saturation_h_idx_1 > CONTROL_PARAM.MC_RATE_D_MAX) {
        rtb_Saturation_h_idx_1 = CONTROL_PARAM.MC_RATE_D_MAX;
      } else {
        if (rtb_Saturation_h_idx_1 < CONTROL_PARAM.MC_RATE_D_MIN) {
          rtb_Saturation_h_idx_1 = CONTROL_PARAM.MC_RATE_D_MIN;
        }
      }

      /* Switch: '<S59>/Switch' incorporates:
       *  Constant: '<S63>/Constant'
       *  Logic: '<S59>/Logical Operator'
       *  RelationalOperator: '<S62>/Compare'
       *  RelationalOperator: '<S63>/Compare'
       *  S-Function (sfix_bitop): '<S11>/Bitwise AND'
       *  Saturate: '<S65>/Saturation'
       *  Switch: '<S59>/Switch1'
       */
      if ((rtb_BitwiseAND_p_tmp == 1) || (rtb_BitwiseAND_p_tmp == 2) ||
          (rtb_BitwiseAND_p_tmp == 3)) {
        rtb_throttle_cmd_m = Controller_U.FMS_Out.throttle_cmd;
      } else if (rtb_BitwiseAND_p_tmp == 6) {
        /* Switch: '<S64>/Switch' incorporates:
         *  Constant: '<S61>/Constant1'
         *  DataTypeConversion: '<S61>/Data Type Conversion'
         *  Gain: '<S61>/Gain1'
         *  S-Function (sfix_bitop): '<S64>/cmd_throttle valid'
         *  Saturate: '<S65>/Saturation'
         *  Sum: '<S61>/Sum1'
         *  Switch: '<S59>/Switch1'
         */
        if ((Controller_U.FMS_Out.cmd_mask & 4096) > 0) {
          rtb_throttle_cmd_m = Controller_U.FMS_Out.throttle_cmd;
        } else {
          if (rtb_Subtract3_g > 0.35F) {
            /* Saturate: '<S65>/Saturation' */
            rtb_Subtract3_g = 0.35F;
          } else {
            if (rtb_Subtract3_g < -0.35F) {
              /* Saturate: '<S65>/Saturation' */
              rtb_Subtract3_g = -0.35F;
            }
          }

          /* Sum: '<S61>/Sum' incorporates:
           *  Constant: '<S61>/hover_throttle'
           *  Saturate: '<S65>/Saturation'
           */
          rtb_Add4_l = rtb_Subtract3_g + CONTROL_PARAM.MC_HOVER_THRO;

          /* Saturate: '<S61>/Saturation' */
          if (rtb_Add4_l > 1.0F) {
            rtb_Add4_l = 1.0F;
          } else {
            if (rtb_Add4_l < 0.0F) {
              rtb_Add4_l = 0.0F;
            }
          }

          rtb_throttle_cmd_m = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
            rtb_Add4_l), 4.2949673E+9F) + 1000U);
        }

        /* End of Switch: '<S64>/Switch' */
      } else {
        if (rtb_Subtract3_g > 0.35F) {
          /* Saturate: '<S65>/Saturation' */
          rtb_Subtract3_g = 0.35F;
        } else {
          if (rtb_Subtract3_g < -0.35F) {
            /* Saturate: '<S65>/Saturation' */
            rtb_Subtract3_g = -0.35F;
          }
        }

        /* Sum: '<S61>/Sum' incorporates:
         *  Constant: '<S61>/hover_throttle'
         *  Saturate: '<S65>/Saturation'
         */
        rtb_Add4_l = rtb_Subtract3_g + CONTROL_PARAM.MC_HOVER_THRO;

        /* Saturate: '<S61>/Saturation' */
        if (rtb_Add4_l > 1.0F) {
          rtb_Add4_l = 1.0F;
        } else {
          if (rtb_Add4_l < 0.0F) {
            rtb_Add4_l = 0.0F;
          }
        }

        /* Switch: '<S59>/Switch1' incorporates:
         *  Constant: '<S61>/Constant1'
         *  DataTypeConversion: '<S61>/Data Type Conversion'
         *  Gain: '<S61>/Gain1'
         *  Sum: '<S61>/Sum1'
         */
        rtb_throttle_cmd_m = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          rtb_Add4_l), 4.2949673E+9F) + 1000U);
      }

      /* End of Switch: '<S59>/Switch' */

      /* Saturate: '<S58>/Saturation1' incorporates:
       *  Constant: '<S25>/gain1'
       *  Constant: '<S25>/gain2'
       *  Constant: '<S25>/gain3'
       *  DiscreteIntegrator: '<S22>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S24>/Discrete-Time Integrator'
       *  Product: '<S25>/Multiply'
       *  Sum: '<S20>/Add'
       */
      rtb_Add4_l = (CONTROL_PARAM.MC_ROLL_RATE_P *
                    Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0] +
                    Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[0]) +
        rtb_Add_b;
      if (rtb_Add4_l > 1.0F) {
        rtb_Add4_l = 1.0F;
      } else {
        if (rtb_Add4_l < -1.0F) {
          rtb_Add4_l = -1.0F;
        }
      }

      rtb_Add_cx = (CONTROL_PARAM.MC_PITCH_RATE_P *
                    Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1] +
                    Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[1]) +
        rtb_Saturation_k_idx_1;
      if (rtb_Add_cx > 1.0F) {
        rtb_Add_cx = 1.0F;
      } else {
        if (rtb_Add_cx < -1.0F) {
          rtb_Add_cx = -1.0F;
        }
      }

      u0_0 = (CONTROL_PARAM.MC_YAW_RATE_P *
              Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2] +
              Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[2]) +
        rtb_Saturation_h_idx_1;
      if (u0_0 > 1.0F) {
        u0_0 = 1.0F;
      } else {
        if (u0_0 < -1.0F) {
          u0_0 = -1.0F;
        }
      }

      /* End of Saturate: '<S58>/Saturation1' */

      /* Product: '<S58>/Multiply' */
      for (i = 0; i < 4; i++) {
        /* Saturate: '<S58>/Saturation' incorporates:
         *  Constant: '<S58>/Effective_Matrix'
         *  Gain: '<S58>/Gain'
         *  Sum: '<S58>/Add'
         */
        rtb_BitwiseAND_0 = fmodf(floorf(1000.0F * (Controller_ConstP.pooled5[i +
          8] * u0_0 + (Controller_ConstP.pooled5[i + 4] * rtb_Add_cx +
                       Controller_ConstP.pooled5[i] * rtb_Add4_l)) + (real32_T)
          rtb_throttle_cmd_m), 65536.0F);
        u0 = (uint16_T)(rtb_BitwiseAND_0 < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                        (uint16_T)-rtb_BitwiseAND_0 : (int32_T)(uint16_T)
                        rtb_BitwiseAND_0);
        if (u0 > 1900) {
          rtb_MultiportSwitch_o[i] = 1900U;
        } else if (u0 < 1100) {
          rtb_MultiportSwitch_o[i] = 1100U;
        } else {
          rtb_MultiportSwitch_o[i] = u0;
        }

        /* End of Saturate: '<S58>/Saturation' */
      }

      /* End of Product: '<S58>/Multiply' */
      break;

     default:
      rtb_MultiportSwitch_o[0] = 1000U;
      rtb_MultiportSwitch_o[1] = 1000U;
      rtb_MultiportSwitch_o[2] = 1000U;
      rtb_MultiportSwitch_o[3] = 1000U;
      break;
    }

    /* End of MultiPortSwitch: '<S60>/Multiport Switch' */

    /* Reshape: '<S60>/Reshape' incorporates:
     *  Constant: '<S60>/Disarm1'
     */
    Controller_B.Reshape_g[0] = rtb_MultiportSwitch_o[0];
    Controller_B.Reshape_g[1] = rtb_MultiportSwitch_o[1];
    Controller_B.Reshape_g[2] = rtb_MultiportSwitch_o[2];
    Controller_B.Reshape_g[3] = rtb_MultiportSwitch_o[3];
    for (i = 0; i < 5; i++) {
      Controller_B.Reshape_g[i + 4] = Controller_ConstP.pooled28[i];
    }

    for (i = 0; i < 7; i++) {
      Controller_B.Reshape_g[i + 9] = 0U;
    }

    /* End of Reshape: '<S60>/Reshape' */
    /* End of Outputs for SubSystem: '<S9>/Quadcopter_x' */

    /* Product: '<S24>/Multiply' incorporates:
     *  Constant: '<S24>/gain1'
     *  Constant: '<S24>/gain2'
     *  Constant: '<S24>/gain3'
     *  DiscreteIntegrator: '<S22>/Discrete-Time Integrator5'
     */
    rtb_Add_b = CONTROL_PARAM.MC_ROLL_RATE_I *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0];
    rtb_Saturation_k_idx_1 = CONTROL_PARAM.MC_PITCH_RATE_I *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1];
    rtb_Saturation_k_idx_2 = CONTROL_PARAM.MC_YAW_RATE_I *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2];

    /* Product: '<S49>/Multiply1' incorporates:
     *  Constant: '<S49>/const1'
     *  DiscreteIntegrator: '<S46>/Integrator'
     */
    rtb_a_m_idx_0 = Controller_DW.Integrator_DSTATE_l[0] * 0.05F;
    rtb_Saturation_h_idx_1 = Controller_DW.Integrator_DSTATE_l[1] * 0.05F;

    /* Sum: '<S49>/Add' incorporates:
     *  DiscreteIntegrator: '<S46>/Integrator1'
     *  Inport: '<Root>/FMS_Out'
     *  Sum: '<S46>/Subtract'
     */
    rtb_Subtract3_idx_0 = (Controller_DW.Integrator1_DSTATE_e[0] -
      Controller_U.FMS_Out.u_cmd) + rtb_a_m_idx_0;
    rtb_Subtract3_idx_1 = (Controller_DW.Integrator1_DSTATE_e[1] -
      Controller_U.FMS_Out.v_cmd) + rtb_Saturation_h_idx_1;

    /* Product: '<S70>/Multiply1' incorporates:
     *  Constant: '<S70>/const1'
     *  DiscreteIntegrator: '<S69>/Integrator'
     */
    rtb_Add3_e = Controller_DW.Integrator_DSTATE_j * 0.05F;

    /* Sum: '<S70>/Add' incorporates:
     *  DiscreteIntegrator: '<S69>/Integrator1'
     *  Inport: '<Root>/FMS_Out'
     *  Sum: '<S69>/Subtract'
     */
    rtb_Subtract3_g = (Controller_DW.Integrator1_DSTATE_eq -
                       Controller_U.FMS_Out.w_cmd) + rtb_Add3_e;

    /* Signum: '<S70>/Sign' */
    if (rtb_Subtract3_g < 0.0F) {
      rtb_a = -1.0F;
    } else if (rtb_Subtract3_g > 0.0F) {
      rtb_a = 1.0F;
    } else {
      rtb_a = rtb_Subtract3_g;
    }

    /* End of Signum: '<S70>/Sign' */

    /* Sum: '<S70>/Add2' incorporates:
     *  Abs: '<S70>/Abs'
     *  Gain: '<S70>/Gain'
     *  Gain: '<S70>/Gain1'
     *  Product: '<S70>/Multiply2'
     *  Product: '<S70>/Multiply3'
     *  Sqrt: '<S70>/Sqrt'
     *  Sum: '<S70>/Add1'
     *  Sum: '<S70>/Subtract'
     */
    rtb_a = (sqrtf((8.0F * fabsf(rtb_Subtract3_g) + Controller_ConstB.d_i) *
                   Controller_ConstB.d_i) - Controller_ConstB.d_i) * 0.5F *
      rtb_a + rtb_Add3_e;

    /* Sum: '<S70>/Add4' */
    rtb_Add4_l = (rtb_Subtract3_g - rtb_a) + rtb_Add3_e;

    /* Sum: '<S70>/Add3' */
    rtb_Add3_e = rtb_Subtract3_g + Controller_ConstB.d_i;

    /* Sum: '<S70>/Subtract1' */
    rtb_Subtract3_g -= Controller_ConstB.d_i;

    /* Signum: '<S70>/Sign1' */
    if (rtb_Add3_e < 0.0F) {
      rtb_Add3_e = -1.0F;
    } else {
      if (rtb_Add3_e > 0.0F) {
        rtb_Add3_e = 1.0F;
      }
    }

    /* End of Signum: '<S70>/Sign1' */

    /* Signum: '<S70>/Sign2' */
    if (rtb_Subtract3_g < 0.0F) {
      rtb_Subtract3_g = -1.0F;
    } else {
      if (rtb_Subtract3_g > 0.0F) {
        rtb_Subtract3_g = 1.0F;
      }
    }

    /* End of Signum: '<S70>/Sign2' */

    /* Sum: '<S70>/Add5' incorporates:
     *  Gain: '<S70>/Gain2'
     *  Product: '<S70>/Multiply4'
     *  Sum: '<S70>/Subtract2'
     */
    rtb_a += (rtb_Add3_e - rtb_Subtract3_g) * 0.5F * rtb_Add4_l;

    /* Update for DiscreteIntegrator: '<S51>/Discrete-Time Integrator' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.DiscreteTimeIntegrator_PrevRe_p = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S53>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_m = 0U;

    /* Signum: '<S49>/Sign' */
    if (rtb_Subtract3_idx_0 < 0.0F) {
      rtb_Add3_e = -1.0F;
    } else if (rtb_Subtract3_idx_0 > 0.0F) {
      rtb_Add3_e = 1.0F;
    } else {
      rtb_Add3_e = rtb_Subtract3_idx_0;
    }

    /* Sum: '<S49>/Add2' incorporates:
     *  Abs: '<S49>/Abs'
     *  Gain: '<S49>/Gain'
     *  Gain: '<S49>/Gain1'
     *  Product: '<S49>/Multiply2'
     *  Product: '<S49>/Multiply3'
     *  Signum: '<S49>/Sign'
     *  Sqrt: '<S49>/Sqrt'
     *  Sum: '<S49>/Add1'
     *  Sum: '<S49>/Subtract'
     */
    rtb_Subtract3_g = (sqrtf((8.0F * fabsf(rtb_Subtract3_idx_0) +
      Controller_ConstB.d_f) * Controller_ConstB.d_f) - Controller_ConstB.d_f) *
      0.5F * rtb_Add3_e + rtb_a_m_idx_0;

    /* Sum: '<S49>/Add3' incorporates:
     *  Signum: '<S49>/Sign'
     */
    rtb_Add3_e = rtb_Subtract3_idx_0 + Controller_ConstB.d_f;

    /* Sum: '<S49>/Subtract1' incorporates:
     *  Signum: '<S49>/Sign'
     */
    rtb_Add4_l = rtb_Subtract3_idx_0 - Controller_ConstB.d_f;

    /* Signum: '<S49>/Sign1' */
    if (rtb_Add3_e < 0.0F) {
      rtb_Add3_e = -1.0F;
    } else {
      if (rtb_Add3_e > 0.0F) {
        rtb_Add3_e = 1.0F;
      }
    }

    /* Signum: '<S49>/Sign2' */
    if (rtb_Add4_l < 0.0F) {
      rtb_Add4_l = -1.0F;
    } else {
      if (rtb_Add4_l > 0.0F) {
        rtb_Add4_l = 1.0F;
      }
    }

    /* Sum: '<S49>/Add2' incorporates:
     *  Gain: '<S49>/Gain2'
     *  Product: '<S49>/Multiply4'
     *  Signum: '<S49>/Sign'
     *  Sum: '<S49>/Add4'
     *  Sum: '<S49>/Add5'
     *  Sum: '<S49>/Subtract2'
     */
    rtb_a_m_idx_0 = ((rtb_Subtract3_idx_0 - rtb_Subtract3_g) + rtb_a_m_idx_0) *
      ((rtb_Add3_e - rtb_Add4_l) * 0.5F) + rtb_Subtract3_g;

    /* Update for DiscreteIntegrator: '<S46>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S46>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_e[0] += 0.002F *
      Controller_DW.Integrator_DSTATE_l[0];

    /* Update for DiscreteIntegrator: '<S51>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S51>/ki'
     *  Product: '<S51>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0] +=
      CONTROL_PARAM.MC_VEL_XY_I * rtb_uv_error_C_mPs_idx_0 * 0.002F;
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

    /* Update for DiscreteIntegrator: '<S53>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[0] += 0.002F *
      rtb_Gain_b_idx_0;

    /* Signum: '<S49>/Sign' */
    if (rtb_Subtract3_idx_1 < 0.0F) {
      rtb_Gain_b_idx_0 = -1.0F;
    } else if (rtb_Subtract3_idx_1 > 0.0F) {
      rtb_Gain_b_idx_0 = 1.0F;
    } else {
      rtb_Gain_b_idx_0 = rtb_Subtract3_idx_1;
    }

    /* Sum: '<S49>/Add2' incorporates:
     *  Abs: '<S49>/Abs'
     *  Gain: '<S49>/Gain'
     *  Gain: '<S49>/Gain1'
     *  Product: '<S49>/Multiply2'
     *  Product: '<S49>/Multiply3'
     *  Signum: '<S49>/Sign'
     *  Sqrt: '<S49>/Sqrt'
     *  Sum: '<S49>/Add1'
     *  Sum: '<S49>/Subtract'
     */
    rtb_Subtract3_g = (sqrtf((8.0F * fabsf(rtb_Subtract3_idx_1) +
      Controller_ConstB.d_f) * Controller_ConstB.d_f) - Controller_ConstB.d_f) *
      0.5F * rtb_Gain_b_idx_0 + rtb_Saturation_h_idx_1;

    /* Sum: '<S49>/Add3' incorporates:
     *  Signum: '<S49>/Sign'
     */
    rtb_Add3_e = rtb_Subtract3_idx_1 + Controller_ConstB.d_f;

    /* Sum: '<S49>/Subtract1' incorporates:
     *  Signum: '<S49>/Sign'
     */
    rtb_Add4_l = rtb_Subtract3_idx_1 - Controller_ConstB.d_f;

    /* Signum: '<S49>/Sign1' */
    if (rtb_Add3_e < 0.0F) {
      rtb_Add3_e = -1.0F;
    } else {
      if (rtb_Add3_e > 0.0F) {
        rtb_Add3_e = 1.0F;
      }
    }

    /* Signum: '<S49>/Sign2' */
    if (rtb_Add4_l < 0.0F) {
      rtb_Add4_l = -1.0F;
    } else {
      if (rtb_Add4_l > 0.0F) {
        rtb_Add4_l = 1.0F;
      }
    }

    /* Sum: '<S49>/Add5' incorporates:
     *  Gain: '<S49>/Gain2'
     *  Product: '<S49>/Multiply4'
     *  Signum: '<S49>/Sign'
     *  Sum: '<S49>/Add2'
     *  Sum: '<S49>/Add4'
     *  Sum: '<S49>/Subtract2'
     */
    rtb_Subtract3_g += ((rtb_Subtract3_idx_1 - rtb_Subtract3_g) +
                        rtb_Saturation_h_idx_1) * ((rtb_Add3_e - rtb_Add4_l) *
      0.5F);

    /* Update for DiscreteIntegrator: '<S46>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S46>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_e[1] += 0.002F *
      Controller_DW.Integrator_DSTATE_l[1];

    /* Update for DiscreteIntegrator: '<S51>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S51>/ki'
     *  Product: '<S51>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1] +=
      CONTROL_PARAM.MC_VEL_XY_I * rtb_uv_error_C_mPs_idx_1 * 0.002F;
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

    /* Update for DiscreteIntegrator: '<S53>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o[1] += 0.002F *
      rtb_Gain_b_idx_1;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_a = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S22>/Discrete-Time Integrator5' */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_c = 0U;

    /* Update for DiscreteIntegrator: '<S24>/Discrete-Time Integrator' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.DiscreteTimeIntegrator_PrevRe_d = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S26>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 0U;

    /* Update for DiscreteIntegrator: '<S22>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S22>/Gain'
     *  Sum: '<S22>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0] +=
      (rtb_rate_error_B_radPs_n_idx_0 -
       Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S24>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[0] += 0.002F * rtb_Add_b;
    if (Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[0] >=
        CONTROL_PARAM.MC_RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[0] =
        CONTROL_PARAM.MC_RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[0] <=
          CONTROL_PARAM.MC_RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[0] =
          CONTROL_PARAM.MC_RATE_I_MIN;
      }
    }

    /* Update for DiscreteIntegrator: '<S26>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTA_nm[0] += 0.002F *
      rtb_DiscreteTimeIntegrator1_n_i;

    /* Update for DiscreteIntegrator: '<S22>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S22>/Gain'
     *  Sum: '<S22>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1] +=
      (rtb_rate_error_B_radPs_n_idx_1 -
       Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S24>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[1] += 0.002F *
      rtb_Saturation_k_idx_1;
    if (Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[1] >=
        CONTROL_PARAM.MC_RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[1] =
        CONTROL_PARAM.MC_RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[1] <=
          CONTROL_PARAM.MC_RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[1] =
          CONTROL_PARAM.MC_RATE_I_MIN;
      }
    }

    /* Update for DiscreteIntegrator: '<S26>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTA_nm[1] += 0.002F * rtb_a_m_idx_1;

    /* Update for DiscreteIntegrator: '<S22>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S22>/Gain'
     *  Sum: '<S22>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2] +=
      (rtb_rate_error_B_radPs_n_idx_2 -
       Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S24>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[2] += 0.002F *
      rtb_Saturation_k_idx_2;
    if (Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[2] >=
        CONTROL_PARAM.MC_RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[2] =
        CONTROL_PARAM.MC_RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[2] <=
          CONTROL_PARAM.MC_RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[2] =
          CONTROL_PARAM.MC_RATE_I_MIN;
      }
    }

    /* Update for DiscreteIntegrator: '<S26>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.DiscreteTimeIntegrator1_DSTA_nm[2] += 0.002F *
      rtb_DiscreteTimeIntegrator1_n_0;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_k = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S69>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S69>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_eq += 0.002F *
      Controller_DW.Integrator_DSTATE_j;

    /* Update for DiscreteIntegrator: '<S72>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S72>/ki'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S72>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTAT_lc += CONTROL_PARAM.MC_VEL_Z_I *
      rtb_Gain_ap * 0.002F;
    if (Controller_DW.DiscreteTimeIntegrator_DSTAT_lc >=
        CONTROL_PARAM.MC_VEL_Z_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_lc =
        CONTROL_PARAM.MC_VEL_Z_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_lc <=
          CONTROL_PARAM.MC_VEL_Z_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_lc =
          CONTROL_PARAM.MC_VEL_Z_I_MIN;
      }
    }

    Controller_DW.DiscreteTimeIntegrator_PrevRe_f = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* End of Update for DiscreteIntegrator: '<S72>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S74>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_i += 0.002F * rtb_Gain_cq;
    Controller_DW.DiscreteTimeIntegrator1_Prev_ks = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Signum: '<S49>/Sign3' incorporates:
     *  Product: '<S49>/Divide'
     *  Sum: '<S49>/Add6'
     */
    rtb_Add3_e = rtb_a_m_idx_0 + Controller_ConstB.d_f;

    /* Signum: '<S49>/Sign4' incorporates:
     *  Product: '<S49>/Divide'
     *  Sum: '<S49>/Subtract3'
     */
    rtb_DiscreteTimeIntegrator1_n_i = rtb_a_m_idx_0 - Controller_ConstB.d_f;

    /* Signum: '<S49>/Sign5' incorporates:
     *  Product: '<S49>/Divide'
     */
    if (rtb_a_m_idx_0 < 0.0F) {
      rtb_a_m_idx_1 = -1.0F;
    } else if (rtb_a_m_idx_0 > 0.0F) {
      rtb_a_m_idx_1 = 1.0F;
    } else {
      rtb_a_m_idx_1 = rtb_a_m_idx_0;
    }

    /* Signum: '<S49>/Sign3' */
    if (rtb_Add3_e < 0.0F) {
      rtb_Add3_e = -1.0F;
    } else {
      if (rtb_Add3_e > 0.0F) {
        rtb_Add3_e = 1.0F;
      }
    }

    /* Signum: '<S49>/Sign4' */
    if (rtb_DiscreteTimeIntegrator1_n_i < 0.0F) {
      rtb_DiscreteTimeIntegrator1_n_i = -1.0F;
    } else {
      if (rtb_DiscreteTimeIntegrator1_n_i > 0.0F) {
        rtb_DiscreteTimeIntegrator1_n_i = 1.0F;
      }
    }

    /* Signum: '<S49>/Sign6' incorporates:
     *  Product: '<S49>/Divide'
     */
    if (rtb_a_m_idx_0 < 0.0F) {
      rtb_rate_error_B_radPs_n_idx_0 = -1.0F;
    } else if (rtb_a_m_idx_0 > 0.0F) {
      rtb_rate_error_B_radPs_n_idx_0 = 1.0F;
    } else {
      rtb_rate_error_B_radPs_n_idx_0 = rtb_a_m_idx_0;
    }

    /* Update for DiscreteIntegrator: '<S46>/Integrator' incorporates:
     *  Constant: '<S49>/const'
     *  Gain: '<S49>/Gain3'
     *  Product: '<S49>/Divide'
     *  Product: '<S49>/Multiply5'
     *  Product: '<S49>/Multiply6'
     *  Sum: '<S49>/Subtract4'
     *  Sum: '<S49>/Subtract5'
     *  Sum: '<S49>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE_l[0] += ((rtb_a_m_idx_0 /
      Controller_ConstB.d_f - rtb_a_m_idx_1) * Controller_ConstB.Gain4_b *
      ((rtb_Add3_e - rtb_DiscreteTimeIntegrator1_n_i) * 0.5F) -
      rtb_rate_error_B_radPs_n_idx_0 * 58.836F) * 0.002F;

    /* Signum: '<S49>/Sign3' incorporates:
     *  Sum: '<S49>/Add6'
     */
    rtb_Add3_e = rtb_Subtract3_g + Controller_ConstB.d_f;

    /* Signum: '<S49>/Sign4' incorporates:
     *  Sum: '<S49>/Subtract3'
     */
    rtb_DiscreteTimeIntegrator1_n_i = rtb_Subtract3_g - Controller_ConstB.d_f;

    /* Signum: '<S49>/Sign5' */
    if (rtb_Subtract3_g < 0.0F) {
      rtb_a_m_idx_1 = -1.0F;
    } else if (rtb_Subtract3_g > 0.0F) {
      rtb_a_m_idx_1 = 1.0F;
    } else {
      rtb_a_m_idx_1 = rtb_Subtract3_g;
    }

    /* Signum: '<S49>/Sign3' */
    if (rtb_Add3_e < 0.0F) {
      rtb_Add3_e = -1.0F;
    } else {
      if (rtb_Add3_e > 0.0F) {
        rtb_Add3_e = 1.0F;
      }
    }

    /* Signum: '<S49>/Sign4' */
    if (rtb_DiscreteTimeIntegrator1_n_i < 0.0F) {
      rtb_DiscreteTimeIntegrator1_n_i = -1.0F;
    } else {
      if (rtb_DiscreteTimeIntegrator1_n_i > 0.0F) {
        rtb_DiscreteTimeIntegrator1_n_i = 1.0F;
      }
    }

    /* Signum: '<S49>/Sign6' */
    if (rtb_Subtract3_g < 0.0F) {
      rtb_rate_error_B_radPs_n_idx_0 = -1.0F;
    } else if (rtb_Subtract3_g > 0.0F) {
      rtb_rate_error_B_radPs_n_idx_0 = 1.0F;
    } else {
      rtb_rate_error_B_radPs_n_idx_0 = rtb_Subtract3_g;
    }

    /* Update for DiscreteIntegrator: '<S46>/Integrator' incorporates:
     *  Constant: '<S49>/const'
     *  Gain: '<S49>/Gain3'
     *  Product: '<S49>/Divide'
     *  Product: '<S49>/Multiply5'
     *  Product: '<S49>/Multiply6'
     *  Sum: '<S49>/Subtract4'
     *  Sum: '<S49>/Subtract5'
     *  Sum: '<S49>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE_l[1] += ((rtb_Subtract3_g /
      Controller_ConstB.d_f - rtb_a_m_idx_1) * Controller_ConstB.Gain4_b *
      ((rtb_Add3_e - rtb_DiscreteTimeIntegrator1_n_i) * 0.5F) -
      rtb_rate_error_B_radPs_n_idx_0 * 58.836F) * 0.002F;

    /* Signum: '<S70>/Sign6' incorporates:
     *  Signum: '<S70>/Sign5'
     */
    if (rtb_a < 0.0F) {
      rtb_Subtract3_g = -1.0F;

      /* Signum: '<S70>/Sign5' */
      rtb_a_m_idx_1 = -1.0F;
    } else if (rtb_a > 0.0F) {
      rtb_Subtract3_g = 1.0F;

      /* Signum: '<S70>/Sign5' */
      rtb_a_m_idx_1 = 1.0F;
    } else {
      rtb_Subtract3_g = rtb_a;

      /* Signum: '<S70>/Sign5' */
      rtb_a_m_idx_1 = rtb_a;
    }

    /* End of Signum: '<S70>/Sign6' */

    /* Sum: '<S70>/Add6' */
    rtb_Add3_e = rtb_a + Controller_ConstB.d_i;

    /* Sum: '<S70>/Subtract3' */
    rtb_DiscreteTimeIntegrator1_n_i = rtb_a - Controller_ConstB.d_i;

    /* Signum: '<S70>/Sign3' */
    if (rtb_Add3_e < 0.0F) {
      rtb_Add3_e = -1.0F;
    } else {
      if (rtb_Add3_e > 0.0F) {
        rtb_Add3_e = 1.0F;
      }
    }

    /* End of Signum: '<S70>/Sign3' */

    /* Signum: '<S70>/Sign4' */
    if (rtb_DiscreteTimeIntegrator1_n_i < 0.0F) {
      rtb_DiscreteTimeIntegrator1_n_i = -1.0F;
    } else {
      if (rtb_DiscreteTimeIntegrator1_n_i > 0.0F) {
        rtb_DiscreteTimeIntegrator1_n_i = 1.0F;
      }
    }

    /* End of Signum: '<S70>/Sign4' */

    /* Update for DiscreteIntegrator: '<S69>/Integrator' incorporates:
     *  Constant: '<S70>/const'
     *  Gain: '<S70>/Gain3'
     *  Product: '<S70>/Divide'
     *  Product: '<S70>/Multiply5'
     *  Product: '<S70>/Multiply6'
     *  Sum: '<S70>/Subtract4'
     *  Sum: '<S70>/Subtract5'
     *  Sum: '<S70>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE_j += ((rtb_a / Controller_ConstB.d_i -
      rtb_a_m_idx_1) * Controller_ConstB.Gain4_p * ((rtb_Add3_e -
      rtb_DiscreteTimeIntegrator1_n_i) * 0.5F) - rtb_Subtract3_g * 78.448F) *
      0.002F;

    /* End of Outputs for SubSystem: '<S2>/MC_Controller' */
    break;

   case 1:
    if (Controller_DW.SwitchCase1_ActiveSubsystem != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S2>/VTOL_Controller' incorporates:
       *  ActionPort: '<S6>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S7>/Switch Case1' incorporates:
       *  DiscreteIntegrator: '<S114>/Integrator'
       *  DiscreteIntegrator: '<S114>/Integrator1'
       *  DiscreteIntegrator: '<S117>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S119>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S130>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S150>/ '
       *  DiscreteIntegrator: '<S151>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S153>/ '
       *  DiscreteIntegrator: '<S154>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S91>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S93>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S95>/Discrete-Time Integrator1'
       */
      Controller_DW._DSTATE = Controller_ConstB.Zero1;
      if (Controller_DW._DSTATE >= CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
        Controller_DW._DSTATE = CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
      } else {
        if (Controller_DW._DSTATE <= -CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
          Controller_DW._DSTATE = -CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
        }
      }

      Controller_DW._PrevResetState = 0;
      Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;
      Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;
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
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_h = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevR_l = 0;
      Controller_DW.Integrator1_DSTATE = 0.0F;
      Controller_DW.DiscreteTimeIntegrator_DSTATE_b = Controller_B.Constant;
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_b >=
          CONTROL_PARAM.MC_VEL_Z_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_b =
          CONTROL_PARAM.MC_VEL_Z_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_b <=
            CONTROL_PARAM.MC_VEL_Z_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_b =
            CONTROL_PARAM.MC_VEL_Z_I_MIN;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_PrevRe_e = 0;
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_i = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevR_h = 0;
      Controller_DW.DiscreteTimeIntegrator_DSTATE_l[0] =
        Controller_ConstB.Constant_c[0];
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_l[0] >=
          CONTROL_PARAM.FW_RATE_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_l[0] =
          CONTROL_PARAM.FW_RATE_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_l[0] <=
            CONTROL_PARAM.FW_RATE_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_l[0] =
            CONTROL_PARAM.FW_RATE_I_MIN;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_DSTATE_l[1] =
        Controller_ConstB.Constant_c[1];
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_l[1] >=
          CONTROL_PARAM.FW_RATE_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_l[1] =
          CONTROL_PARAM.FW_RATE_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_l[1] <=
            CONTROL_PARAM.FW_RATE_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_l[1] =
            CONTROL_PARAM.FW_RATE_I_MIN;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_DSTATE_l[2] =
        Controller_ConstB.Constant_c[2];
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_l[2] >=
          CONTROL_PARAM.FW_RATE_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_l[2] =
          CONTROL_PARAM.FW_RATE_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_l[2] <=
            CONTROL_PARAM.FW_RATE_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_l[2] =
            CONTROL_PARAM.FW_RATE_I_MIN;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_PrevR_ef = 0;
      Controller_DW._DSTATE_d = Controller_ConstB.Zero;
      if (Controller_DW._DSTATE_d >= 0.1F) {
        Controller_DW._DSTATE_d = 0.1F;
      } else {
        if (Controller_DW._DSTATE_d <= -0.1F) {
          Controller_DW._DSTATE_d = -0.1F;
        }
      }

      Controller_DW._PrevResetState_e = 0;
      Controller_DW.DiscreteTimeIntegrator1_IC_L_h0 = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevR_d = 0;
      Controller_DW.Integrator_DSTATE = 0.0F;

      /* End of InitializeConditions for SubSystem: '<S2>/VTOL_Controller' */
    }

    /* Outputs for IfAction SubSystem: '<S2>/VTOL_Controller' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    /* Product: '<S120>/Divide' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Math: '<S120>/Square'
     */
    rtb_Add3_e = Controller_U.INS_Out.airspeed * Controller_U.INS_Out.airspeed /
      Controller_ConstB.Square1;

    /* Saturate: '<S120>/Saturation' */
    if (rtb_Add3_e > 1.0F) {
      rtb_Add3_e = 1.0F;
    } else {
      if (rtb_Add3_e < 0.0F) {
        rtb_Add3_e = 0.0F;
      }
    }

    /* End of Saturate: '<S120>/Saturation' */

    /* S-Function (sfix_bitop): '<S80>/Bitwise AND' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    rtb_BitwiseAND_p_tmp = (uint8_T)(Controller_U.FMS_Out.ctrl_mode & 127);

    /* Trigonometry: '<S123>/Atan' incorporates:
     *  Gain: '<S123>/g_force'
     *  Inport: '<Root>/FMS_Out'
     *  Sum: '<S123>/Minus'
     */
    rtb_Multiply1 = atanf(0.101936802F * Controller_U.FMS_Out.ay_cmd);

    /* Saturate: '<S123>/Saturation' */
    if (rtb_Multiply1 > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Multiply1 = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_Multiply1 < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_Multiply1 = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      }
    }

    /* End of Saturate: '<S123>/Saturation' */

    /* Switch: '<S142>/Switch' incorporates:
     *  Constant: '<S148>/Constant'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S148>/Compare'
     *  S-Function (sfix_bitop): '<S80>/Bitwise AND'
     */
    if (rtb_BitwiseAND_p_tmp == 4) {
      rtb_BitwiseAND_0 = Controller_U.FMS_Out.phi_cmd;
    } else {
      rtb_BitwiseAND_0 = rtb_Multiply1;
    }

    /* End of Switch: '<S142>/Switch' */

    /* Abs: '<S122>/Abs' */
    rtb_a = fabsf(rtb_BitwiseAND_0);

    /* Switch: '<S146>/Switch' incorporates:
     *  Constant: '<S146>/Constant'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S146>/Asin'
     */
    if (CONTROL_PARAM.FW_TECS_ANSW > 1.0F) {
      /* Product: '<S146>/Divide' incorporates:
       *  Gain: '<S146>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  Math: '<S146>/Square'
       *  Math: '<S146>/Square1'
       *  Math: '<S146>/Square2'
       *  Sqrt: '<S146>/Sqrt'
       *  Sum: '<S146>/Add'
       */
      rtb_Add4_l = 1.0F / sqrtf((Controller_U.INS_Out.vn *
        Controller_U.INS_Out.vn + Controller_U.INS_Out.ve *
        Controller_U.INS_Out.ve) + Controller_U.INS_Out.vd *
        Controller_U.INS_Out.vd) * -Controller_U.INS_Out.vd;

      /* Trigonometry: '<S146>/Asin' */
      if (rtb_Add4_l > 1.0F) {
        rtb_Add4_l = 1.0F;
      } else {
        if (rtb_Add4_l < -1.0F) {
          rtb_Add4_l = -1.0F;
        }
      }

      rtb_Subtract3_g = asinf(rtb_Add4_l);
    } else {
      rtb_Subtract3_g = Controller_U.INS_Out.theta;
    }

    /* End of Switch: '<S146>/Switch' */

    /* Gain: '<S145>/Gain1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Subtract3_idx_1 = 0.101936802F * Controller_U.INS_Out.ax;

    /* Switch: '<S147>/Switch' incorporates:
     *  Constant: '<S147>/Constant'
     *  Inport: '<Root>/INS_Out'
     *  Switch: '<S155>/Switch'
     */
    if (CONTROL_PARAM.FW_TECS_SWITCH > 1.0F) {
      /* Saturate: '<S147>/Saturation' incorporates:
       *  Inport: '<Root>/INS_Out'
       */
      if (Controller_U.INS_Out.airspeed > 100.0F) {
        rtb_Gain_ap = 100.0F;
      } else if (Controller_U.INS_Out.airspeed < 0.1F) {
        rtb_Gain_ap = 0.1F;
      } else {
        rtb_Gain_ap = Controller_U.INS_Out.airspeed;
      }

      /* End of Saturate: '<S147>/Saturation' */
      rtb_Subtract3_idx_0 = Controller_U.INS_Out.airspeed;
    } else {
      /* Sqrt: '<S147>/Sqrt' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Math: '<S147>/Square'
       *  Math: '<S147>/Square1'
       *  Math: '<S147>/Square2'
       *  Sum: '<S147>/Add'
       */
      rtb_Gain_ap = sqrtf((Controller_U.INS_Out.vn * Controller_U.INS_Out.vn +
                           Controller_U.INS_Out.ve * Controller_U.INS_Out.ve) +
                          Controller_U.INS_Out.vd * Controller_U.INS_Out.vd);

      /* Saturate: '<S147>/Saturation1' incorporates:
       *  Sqrt: '<S147>/Sqrt'
       */
      if (rtb_Gain_ap > 100.0F) {
        rtb_Gain_ap = 100.0F;
      } else {
        if (rtb_Gain_ap < 0.01F) {
          rtb_Gain_ap = 0.01F;
        }
      }

      /* End of Saturate: '<S147>/Saturation1' */

      /* Sqrt: '<S155>/Sqrt' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Math: '<S155>/Square'
       *  Math: '<S155>/Square1'
       *  Math: '<S155>/Square2'
       *  Sum: '<S155>/Add'
       */
      rtb_Subtract3_idx_0 = sqrtf((Controller_U.INS_Out.vn *
        Controller_U.INS_Out.vn + Controller_U.INS_Out.ve *
        Controller_U.INS_Out.ve) + Controller_U.INS_Out.vd *
        Controller_U.INS_Out.vd);

      /* Saturate: '<S155>/Saturation' incorporates:
       *  Sqrt: '<S155>/Sqrt'
       */
      if (rtb_Subtract3_idx_0 > 100.0F) {
        rtb_Subtract3_idx_0 = 100.0F;
      } else {
        if (rtb_Subtract3_idx_0 < 0.01F) {
          rtb_Subtract3_idx_0 = 0.01F;
        }
      }

      /* End of Saturate: '<S155>/Saturation' */
    }

    /* End of Switch: '<S147>/Switch' */

    /* Sum: '<S141>/Minus' incorporates:
     *  Gain: '<S147>/Gain'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S147>/Divide'
     */
    rtb_Gain_ap = -Controller_U.FMS_Out.w_cmd / rtb_Gain_ap - rtb_Subtract3_g;

    /* Saturate: '<S145>/Saturation' */
    if (rtb_Subtract3_idx_0 > 100.0F) {
      rtb_Subtract3_idx_0 = 100.0F;
    } else {
      if (rtb_Subtract3_idx_0 < 0.1F) {
        rtb_Subtract3_idx_0 = 0.1F;
      }
    }

    /* End of Saturate: '<S145>/Saturation' */

    /* Sum: '<S145>/Minus' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    rtb_Subtract3_idx_0 = Controller_U.FMS_Out.u_cmd - rtb_Subtract3_idx_0;

    /* Sum: '<S145>/Minus1' incorporates:
     *  Gain: '<S145>/Gain'
     */
    rtb_Subtract3_idx_0 = 0.101936802F * rtb_Subtract3_idx_0 -
      rtb_Subtract3_idx_1;

    /* Sum: '<S122>/Minus1' incorporates:
     *  Gain: '<S122>/ucmd2pitch'
     *  Gain: '<S122>/wcmd2pitch'
     */
    rtb_Gain_b_idx_1 = CONTROL_PARAM.FW_TECS_W2P * rtb_Gain_ap -
      CONTROL_PARAM.FW_TECS_U2P * rtb_Subtract3_idx_0;

    /* DiscreteIntegrator: '<S150>/ ' incorporates:
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

    /* DiscreteIntegrator: '<S151>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTATE = rtb_Gain_b_idx_1;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevRes != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTATE = rtb_Gain_b_idx_1;
    }

    /* Gain: '<S151>/Gain' incorporates:
     *  DiscreteIntegrator: '<S151>/Discrete-Time Integrator1'
     *  Sum: '<S151>/Sum5'
     */
    rtb_a_m_idx_0 = (rtb_Gain_b_idx_1 -
                     Controller_DW.DiscreteTimeIntegrator1_DSTATE) * 62.831852F;

    /* Switch: '<S151>/Switch' incorporates:
     *  Gain: '<S151>/Gain1'
     *  Inport: '<Root>/FMS_Out'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_BitwiseAND_0 = 0.0F;
    } else {
      rtb_BitwiseAND_0 = rtb_a_m_idx_0;
    }

    /* End of Switch: '<S151>/Switch' */

    /* Gain: '<S149>/Gain' */
    rtb_Gain_cq = CONTROL_PARAM.FW_TECS_PITCH_D * rtb_BitwiseAND_0;

    /* Saturate: '<S143>/Saturation1' */
    if (rtb_Gain_cq > 0.3F) {
      rtb_Gain_cq = 0.3F;
    } else {
      if (rtb_Gain_cq < -0.3F) {
        rtb_Gain_cq = -0.3F;
      }
    }

    /* End of Saturate: '<S143>/Saturation1' */

    /* Switch: '<S104>/Switch' incorporates:
     *  Constant: '<S107>/Constant'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S107>/Compare'
     *  S-Function (sfix_bitop): '<S80>/Bitwise AND'
     */
    if (rtb_BitwiseAND_p_tmp <= 4) {
      rtb_BitwiseAND_0 = Controller_U.FMS_Out.phi_cmd;
    } else {
      rtb_BitwiseAND_0 = rtb_Multiply1;
    }

    /* End of Switch: '<S104>/Switch' */

    /* Sum: '<S98>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_uv_error_C_mPs_idx_0 = rtb_BitwiseAND_0 - Controller_U.INS_Out.phi;

    /* Switch: '<S105>/Switch' incorporates:
     *  Constant: '<S108>/Constant'
     *  Gain: '<S105>/Gain'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S108>/Compare'
     *  S-Function (sfix_bitop): '<S80>/Bitwise AND'
     */
    if (rtb_BitwiseAND_p_tmp <= 3) {
      rtb_BitwiseAND_0 = Controller_U.FMS_Out.theta_cmd;
    } else {
      rtb_BitwiseAND_0 = 0.0F;
    }

    /* End of Switch: '<S105>/Switch' */

    /* Sum: '<S98>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_uv_error_C_mPs_idx_1 = rtb_BitwiseAND_0 - Controller_U.INS_Out.theta;

    /* Product: '<S101>/Divide1' incorporates:
     *  Abs: '<S101>/Abs'
     *  Constant: '<S101>/const2'
     */
    rtb_a_m_idx_1 = fabsf(rtb_uv_error_C_mPs_idx_0) / 0.002F;

    /* Product: '<S101>/Divide' incorporates:
     *  Constant: '<S101>/const1'
     *  Constant: '<S99>/Constant1'
     *  Math: '<S101>/Square'
     *  SignalConversion: '<S101>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_DiscreteTimeIntegrator1_n_i = 9.5993F / (CONTROL_PARAM.MC_ROLL_P *
      CONTROL_PARAM.MC_ROLL_P);

    /* Signum: '<S101>/Sign' incorporates:
     *  Abs: '<S101>/Abs'
     */
    if (rtb_uv_error_C_mPs_idx_0 < 0.0F) {
      rtb_Add4_l = -1.0F;
    } else if (rtb_uv_error_C_mPs_idx_0 > 0.0F) {
      rtb_Add4_l = 1.0F;
    } else {
      rtb_Add4_l = rtb_uv_error_C_mPs_idx_0;
    }

    /* Switch: '<S101>/Switch' incorporates:
     *  Abs: '<S101>/Abs'
     *  Constant: '<S99>/Constant1'
     *  Gain: '<S101>/Gain1'
     *  Gain: '<S101>/Gain2'
     *  Logic: '<S101>/Logical Operator'
     *  Product: '<S101>/Divide'
     *  Product: '<S101>/Multiply'
     *  Product: '<S101>/Multiply1'
     *  Product: '<S101>/Multiply2'
     *  Product: '<S101>/Multiply3'
     *  RelationalOperator: '<S101>/Relational Operator'
     *  RelationalOperator: '<S101>/Relational Operator2'
     *  SignalConversion: '<S101>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S101>/Sqrt'
     *  Sum: '<S101>/Subtract'
     */
    if ((rtb_uv_error_C_mPs_idx_0 <= rtb_DiscreteTimeIntegrator1_n_i) &&
        (rtb_uv_error_C_mPs_idx_0 >= -rtb_DiscreteTimeIntegrator1_n_i)) {
      rtb_Add4_l = rtb_uv_error_C_mPs_idx_0 * CONTROL_PARAM.MC_ROLL_P;
    } else {
      rtb_Add4_l *= sqrtf((rtb_Add4_l * rtb_uv_error_C_mPs_idx_0 - 0.5F *
                           rtb_DiscreteTimeIntegrator1_n_i) *
                          Controller_ConstB.Gain);
    }

    /* Gain: '<S101>/Gain3' */
    rtb_DiscreteTimeIntegrator1_n_i = -rtb_a_m_idx_1;

    /* Switch: '<S102>/Switch' incorporates:
     *  Gain: '<S101>/Gain3'
     *  RelationalOperator: '<S102>/UpperRelop'
     */
    if (rtb_Add4_l >= -rtb_a_m_idx_1) {
      rtb_DiscreteTimeIntegrator1_n_i = rtb_Add4_l;
    }

    /* Switch: '<S102>/Switch2' incorporates:
     *  RelationalOperator: '<S102>/LowerRelop1'
     */
    if (rtb_Add4_l <= rtb_a_m_idx_1) {
      rtb_a_m_idx_1 = rtb_DiscreteTimeIntegrator1_n_i;
    }

    /* Saturate: '<S87>/Saturation1' */
    if (rtb_a_m_idx_1 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_a_m_idx_1 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_a_m_idx_1 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_a_m_idx_1 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    rtb_Gain_b_idx_0 = rtb_a_m_idx_1;

    /* Product: '<S101>/Divide1' incorporates:
     *  Abs: '<S101>/Abs'
     *  Constant: '<S101>/const2'
     */
    rtb_a_m_idx_1 = fabsf(rtb_uv_error_C_mPs_idx_1) / 0.002F;

    /* Product: '<S101>/Divide' incorporates:
     *  Constant: '<S101>/const1'
     *  Constant: '<S99>/Constant2'
     *  Math: '<S101>/Square'
     *  SignalConversion: '<S101>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_DiscreteTimeIntegrator1_n_i = 9.5993F / (CONTROL_PARAM.MC_PITCH_P *
      CONTROL_PARAM.MC_PITCH_P);

    /* Signum: '<S101>/Sign' incorporates:
     *  Abs: '<S101>/Abs'
     */
    if (rtb_uv_error_C_mPs_idx_1 < 0.0F) {
      rtb_Add4_l = -1.0F;
    } else if (rtb_uv_error_C_mPs_idx_1 > 0.0F) {
      rtb_Add4_l = 1.0F;
    } else {
      rtb_Add4_l = rtb_uv_error_C_mPs_idx_1;
    }

    /* Switch: '<S101>/Switch' incorporates:
     *  Abs: '<S101>/Abs'
     *  Constant: '<S99>/Constant2'
     *  Gain: '<S101>/Gain1'
     *  Gain: '<S101>/Gain2'
     *  Logic: '<S101>/Logical Operator'
     *  Product: '<S101>/Divide'
     *  Product: '<S101>/Multiply'
     *  Product: '<S101>/Multiply1'
     *  Product: '<S101>/Multiply2'
     *  Product: '<S101>/Multiply3'
     *  RelationalOperator: '<S101>/Relational Operator'
     *  RelationalOperator: '<S101>/Relational Operator2'
     *  SignalConversion: '<S101>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S101>/Sqrt'
     *  Sum: '<S101>/Subtract'
     */
    if ((rtb_uv_error_C_mPs_idx_1 <= rtb_DiscreteTimeIntegrator1_n_i) &&
        (rtb_uv_error_C_mPs_idx_1 >= -rtb_DiscreteTimeIntegrator1_n_i)) {
      rtb_Add4_l = rtb_uv_error_C_mPs_idx_1 * CONTROL_PARAM.MC_PITCH_P;
    } else {
      rtb_Add4_l *= sqrtf((rtb_Add4_l * rtb_uv_error_C_mPs_idx_1 - 0.5F *
                           rtb_DiscreteTimeIntegrator1_n_i) *
                          Controller_ConstB.Gain);
    }

    /* Gain: '<S101>/Gain3' */
    rtb_DiscreteTimeIntegrator1_n_i = -rtb_a_m_idx_1;

    /* Switch: '<S102>/Switch' incorporates:
     *  Gain: '<S101>/Gain3'
     *  RelationalOperator: '<S102>/UpperRelop'
     */
    if (rtb_Add4_l >= -rtb_a_m_idx_1) {
      rtb_DiscreteTimeIntegrator1_n_i = rtb_Add4_l;
    }

    /* Switch: '<S102>/Switch2' incorporates:
     *  RelationalOperator: '<S102>/LowerRelop1'
     */
    if (rtb_Add4_l <= rtb_a_m_idx_1) {
      rtb_a_m_idx_1 = rtb_DiscreteTimeIntegrator1_n_i;
    }

    /* Saturate: '<S87>/Saturation1' */
    if (rtb_a_m_idx_1 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_a_m_idx_1 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_a_m_idx_1 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_a_m_idx_1 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    /* Saturate: '<S87>/Saturation' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    if (Controller_U.FMS_Out.psi_rate_cmd > CONTROL_PARAM.MC_R_CMD_LIM) {
      rtb_Add_b = CONTROL_PARAM.MC_R_CMD_LIM;
    } else if (Controller_U.FMS_Out.psi_rate_cmd < -CONTROL_PARAM.MC_R_CMD_LIM)
    {
      rtb_Add_b = -CONTROL_PARAM.MC_R_CMD_LIM;
    } else {
      rtb_Add_b = Controller_U.FMS_Out.psi_rate_cmd;
    }

    /* End of Saturate: '<S87>/Saturation' */

    /* Trigonometry: '<S96>/Sin' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Add4_l = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S96>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Saturation_k_idx_1 = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Trigonometry: '<S96>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_DiscreteTimeIntegrator1_n_i = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Sum: '<S88>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S96>/Multiply'
     *  Product: '<S96>/Multiply1'
     *  Product: '<S96>/Multiply3'
     *  Product: '<S96>/Multiply4'
     *  Product: '<S96>/Multiply5'
     *  Sum: '<S96>/Add'
     *  Sum: '<S96>/Add1'
     *  Sum: '<S96>/Add2'
     *  Trigonometry: '<S96>/Cos'
     *  Trigonometry: '<S96>/Cos1'
     *  Trigonometry: '<S96>/Sin'
     *  Trigonometry: '<S96>/Sin1'
     */
    rtb_rate_error_B_radPs_n_idx_0 = (rtb_Gain_b_idx_0 - arm_sin_f32
      (Controller_U.INS_Out.theta) * rtb_Add_b) - Controller_U.INS_Out.p;
    rtb_rate_error_B_radPs_n_idx_1 = (rtb_Add4_l * rtb_Saturation_k_idx_1 *
      rtb_Add_b + rtb_DiscreteTimeIntegrator1_n_i * rtb_a_m_idx_1) -
      Controller_U.INS_Out.q;
    rtb_rate_error_B_radPs_n_idx_2 = (rtb_DiscreteTimeIntegrator1_n_i *
      rtb_Saturation_k_idx_1 * rtb_Add_b - rtb_Add4_l * rtb_a_m_idx_1) -
      Controller_U.INS_Out.r;

    /* DiscreteIntegrator: '<S91>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] =
        rtb_rate_error_B_radPs_n_idx_0;
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] =
        rtb_rate_error_B_radPs_n_idx_1;
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] =
        rtb_rate_error_B_radPs_n_idx_2;
    }

    /* DiscreteIntegrator: '<S93>/Discrete-Time Integrator' incorporates:
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

    /* DiscreteIntegrator: '<S95>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S91>/Discrete-Time Integrator5'
     *  Inport: '<Root>/FMS_Out'
     */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_h != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[0] =
        Controller_DW.DiscreteTimeIntegrator5_DSTATE[0];
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[1] =
        Controller_DW.DiscreteTimeIntegrator5_DSTATE[1];
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[2] =
        Controller_DW.DiscreteTimeIntegrator5_DSTATE[2];
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_l != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[0] =
        Controller_DW.DiscreteTimeIntegrator5_DSTATE[0];
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[1] =
        Controller_DW.DiscreteTimeIntegrator5_DSTATE[1];
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[2] =
        Controller_DW.DiscreteTimeIntegrator5_DSTATE[2];
    }

    /* Gain: '<S95>/Gain' incorporates:
     *  DiscreteIntegrator: '<S91>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S95>/Discrete-Time Integrator1'
     *  Sum: '<S95>/Sum5'
     */
    rtb_DiscreteTimeIntegrator1_n_i =
      (Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] -
       Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[0]) * 188.49556F;
    rtb_a_m_idx_1 = (Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] -
                     Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[1]) *
      188.49556F;
    rtb_DiscreteTimeIntegrator1_n_0 =
      (Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] -
       Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[2]) * 188.49556F;

    /* Gain: '<S112>/Gain' incorporates:
     *  DiscreteIntegrator: '<S114>/Integrator1'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S112>/Sum1'
     */
    rtb_Gain_b_idx_0 = -(Controller_DW.Integrator1_DSTATE -
                         Controller_U.INS_Out.vd);
    Controller_B.Constant = CONTROL_PARAM.MC_VEL_Z_I_MIN;

    /* DiscreteIntegrator: '<S117>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S117>/Constant'
     *  Inport: '<Root>/FMS_Out'
     */
    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator_PrevRe_e != 0)) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_b = Controller_B.Constant;
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_b >=
          CONTROL_PARAM.MC_VEL_Z_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_b =
          CONTROL_PARAM.MC_VEL_Z_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_b <=
            CONTROL_PARAM.MC_VEL_Z_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_b =
            CONTROL_PARAM.MC_VEL_Z_I_MIN;
        }
      }
    }

    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_b >=
        CONTROL_PARAM.MC_VEL_Z_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_b =
        CONTROL_PARAM.MC_VEL_Z_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_b <=
          CONTROL_PARAM.MC_VEL_Z_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_b =
          CONTROL_PARAM.MC_VEL_Z_I_MIN;
      }
    }

    /* DiscreteIntegrator: '<S119>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_i != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_l = rtb_Gain_b_idx_0;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_h != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_l = rtb_Gain_b_idx_0;
    }

    /* Gain: '<S119>/Gain' incorporates:
     *  DiscreteIntegrator: '<S119>/Discrete-Time Integrator1'
     *  Sum: '<S119>/Sum5'
     */
    rtb_uv_error_C_mPs_idx_0 = (rtb_Gain_b_idx_0 -
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_l) * 62.831852F;

    /* Outputs for Atomic SubSystem: '<S158>/Quadcopter_x' */
    /* MultiPortSwitch: '<S166>/Multiport Switch' incorporates:
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S92>/Multiply'
     */
    switch (Controller_U.FMS_Out.status) {
     case 1:
      rtb_MultiportSwitch_o[0] = 1000U;
      rtb_MultiportSwitch_o[1] = 1000U;
      rtb_MultiportSwitch_o[2] = 1000U;
      rtb_MultiportSwitch_o[3] = 1000U;
      break;

     case 2:
      rtb_MultiportSwitch_o[0] = 1150U;
      rtb_MultiportSwitch_o[1] = 1150U;
      rtb_MultiportSwitch_o[2] = 1150U;
      rtb_MultiportSwitch_o[3] = 1150U;
      break;

     case 3:
      /* Switch: '<S95>/Switch' incorporates:
       *  Gain: '<S95>/Gain1'
       */
      if (Controller_U.FMS_Out.reset > 0) {
        rtb_Add_b = 0.0F;
        rtb_Saturation_k_idx_1 = 0.0F;
        rtb_Saturation_k_idx_2 = 0.0F;
      } else {
        rtb_Add_b = rtb_DiscreteTimeIntegrator1_n_i;
        rtb_Saturation_k_idx_1 = rtb_a_m_idx_1;
        rtb_Saturation_k_idx_2 = rtb_DiscreteTimeIntegrator1_n_0;
      }

      /* End of Switch: '<S95>/Switch' */

      /* Product: '<S92>/Multiply' incorporates:
       *  Constant: '<S92>/gain1'
       */
      rtb_Saturation_h_idx_1 = CONTROL_PARAM.MC_ROLL_RATE_D * rtb_Add_b;

      /* Saturate: '<S92>/Saturation' */
      if (rtb_Saturation_h_idx_1 > CONTROL_PARAM.MC_RATE_D_MAX) {
        rtb_Saturation_h_idx_1 = CONTROL_PARAM.MC_RATE_D_MAX;
      } else {
        if (rtb_Saturation_h_idx_1 < CONTROL_PARAM.MC_RATE_D_MIN) {
          rtb_Saturation_h_idx_1 = CONTROL_PARAM.MC_RATE_D_MIN;
        }
      }

      rtb_Add_b = rtb_Saturation_h_idx_1;

      /* Product: '<S92>/Multiply' incorporates:
       *  Constant: '<S92>/gain2'
       */
      rtb_Saturation_h_idx_1 = CONTROL_PARAM.MC_PITCH_RATE_D *
        rtb_Saturation_k_idx_1;

      /* Saturate: '<S92>/Saturation' */
      if (rtb_Saturation_h_idx_1 > CONTROL_PARAM.MC_RATE_D_MAX) {
        rtb_Saturation_h_idx_1 = CONTROL_PARAM.MC_RATE_D_MAX;
      } else {
        if (rtb_Saturation_h_idx_1 < CONTROL_PARAM.MC_RATE_D_MIN) {
          rtb_Saturation_h_idx_1 = CONTROL_PARAM.MC_RATE_D_MIN;
        }
      }

      rtb_Saturation_k_idx_1 = rtb_Saturation_h_idx_1;

      /* Product: '<S92>/Multiply' incorporates:
       *  Constant: '<S92>/gain3'
       */
      rtb_Saturation_h_idx_1 = CONTROL_PARAM.MC_YAW_RATE_D *
        rtb_Saturation_k_idx_2;

      /* Saturate: '<S92>/Saturation' */
      if (rtb_Saturation_h_idx_1 > CONTROL_PARAM.MC_RATE_D_MAX) {
        rtb_Saturation_h_idx_1 = CONTROL_PARAM.MC_RATE_D_MAX;
      } else {
        if (rtb_Saturation_h_idx_1 < CONTROL_PARAM.MC_RATE_D_MIN) {
          rtb_Saturation_h_idx_1 = CONTROL_PARAM.MC_RATE_D_MIN;
        }
      }

      /* Switch: '<S120>/Switch' */
      rtb_Switch_a = (rtb_Add3_e < 1.0F);

      /* Product: '<S111>/Multiply' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S111>/Cos'
       *  Trigonometry: '<S111>/Cos1'
       */
      rtb_Saturation_k_idx_2 = arm_cos_f32(Controller_U.INS_Out.phi) *
        arm_cos_f32(Controller_U.INS_Out.theta);

      /* Gain: '<S111>/Gain' */
      rtb_Add4_l = 2.0F * rtb_Saturation_k_idx_2;

      /* Switch: '<S119>/Switch' incorporates:
       *  Gain: '<S119>/Gain1'
       */
      if (Controller_U.FMS_Out.reset > 0) {
        rtb_BitwiseAND_0 = 0.0F;
      } else {
        rtb_BitwiseAND_0 = rtb_uv_error_C_mPs_idx_0;
      }

      /* End of Switch: '<S119>/Switch' */

      /* Product: '<S116>/Multiply' incorporates:
       *  Constant: '<S116>/kd'
       */
      rtb_uv_error_C_mPs_idx_1 = CONTROL_PARAM.MC_VEL_Z_D * rtb_BitwiseAND_0;

      /* Saturate: '<S116>/Saturation' */
      if (rtb_uv_error_C_mPs_idx_1 > CONTROL_PARAM.MC_VEL_Z_D_MAX) {
        rtb_uv_error_C_mPs_idx_1 = CONTROL_PARAM.MC_VEL_Z_D_MAX;
      } else {
        if (rtb_uv_error_C_mPs_idx_1 < CONTROL_PARAM.MC_VEL_Z_D_MIN) {
          rtb_uv_error_C_mPs_idx_1 = CONTROL_PARAM.MC_VEL_Z_D_MIN;
        }
      }

      /* End of Saturate: '<S116>/Saturation' */

      /* Saturate: '<S111>/Saturation1' */
      if (rtb_Saturation_k_idx_2 > 1.0F) {
        rtb_Saturation_k_idx_2 = 1.0F;
      } else {
        if (rtb_Saturation_k_idx_2 < 0.5F) {
          rtb_Saturation_k_idx_2 = 0.5F;
        }
      }

      /* End of Saturate: '<S111>/Saturation1' */

      /* Saturate: '<S111>/Saturation' */
      if (rtb_Add4_l > 1.0F) {
        rtb_Add4_l = 1.0F;
      } else {
        if (rtb_Add4_l < 0.0F) {
          rtb_Add4_l = 0.0F;
        }
      }

      /* End of Saturate: '<S111>/Saturation' */

      /* Product: '<S111>/Multiply1' incorporates:
       *  Constant: '<S111>/Constant'
       *  Constant: '<S118>/kp'
       *  DiscreteIntegrator: '<S117>/Discrete-Time Integrator'
       *  Product: '<S111>/Divide'
       *  Product: '<S118>/Multiply'
       *  Sum: '<S113>/Add'
       */
      rtb_Saturation_k_idx_2 = ((CONTROL_PARAM.MC_VEL_Z_P * rtb_Gain_b_idx_0 +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_b) +
        rtb_uv_error_C_mPs_idx_1) * (1.0F / rtb_Saturation_k_idx_2) * rtb_Add4_l;

      /* Saturate: '<S110>/Saturation' */
      if (rtb_Saturation_k_idx_2 > 0.35F) {
        rtb_Saturation_k_idx_2 = 0.35F;
      } else {
        if (rtb_Saturation_k_idx_2 < -0.35F) {
          rtb_Saturation_k_idx_2 = -0.35F;
        }
      }

      /* End of Saturate: '<S110>/Saturation' */

      /* Product: '<S77>/Multiply3' */
      rtb_Saturation_k_idx_2 *= (real32_T)rtb_Switch_a;

      /* Sum: '<S167>/Sum' incorporates:
       *  Constant: '<S167>/hover_throttle'
       */
      rtb_Saturation_k_idx_2 += CONTROL_PARAM.MC_HOVER_THRO;

      /* Saturate: '<S167>/Saturation' */
      if (rtb_Saturation_k_idx_2 > 1.0F) {
        rtb_Saturation_k_idx_2 = 1.0F;
      } else {
        if (rtb_Saturation_k_idx_2 < 0.0F) {
          rtb_Saturation_k_idx_2 = 0.0F;
        }
      }

      /* End of Saturate: '<S167>/Saturation' */

      /* DataTypeConversion: '<S167>/Data Type Conversion' incorporates:
       *  Constant: '<S167>/Constant1'
       *  Gain: '<S167>/Gain1'
       *  Product: '<S167>/Multiply'
       *  Sum: '<S167>/Sum1'
       */
      i = (int32_T)fmodf((real32_T)((int32_T)(uint32_T)fmodf(floorf(1000.0F *
        rtb_Saturation_k_idx_2), 4.2949673E+9F) * rtb_Switch_a) + 1000.0F,
                         65536.0F);

      /* Saturate: '<S165>/Saturation1' incorporates:
       *  Constant: '<S94>/gain1'
       *  Constant: '<S94>/gain2'
       *  Constant: '<S94>/gain3'
       *  DiscreteIntegrator: '<S91>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S93>/Discrete-Time Integrator'
       *  Product: '<S77>/Multiply2'
       *  Product: '<S94>/Multiply'
       *  Sum: '<S89>/Add'
       */
      rtb_Add4_l = ((CONTROL_PARAM.MC_ROLL_RATE_P *
                     Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] +
                     Controller_DW.DiscreteTimeIntegrator_DSTATE[0]) + rtb_Add_b)
        * (real32_T)rtb_Switch_a;
      if (rtb_Add4_l > 1.0F) {
        rtb_Add4_l = 1.0F;
      } else {
        if (rtb_Add4_l < -1.0F) {
          rtb_Add4_l = -1.0F;
        }
      }

      rtb_Add_cx = ((CONTROL_PARAM.MC_PITCH_RATE_P *
                     Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] +
                     Controller_DW.DiscreteTimeIntegrator_DSTATE[1]) +
                    rtb_Saturation_k_idx_1) * (real32_T)rtb_Switch_a;
      if (rtb_Add_cx > 1.0F) {
        rtb_Add_cx = 1.0F;
      } else {
        if (rtb_Add_cx < -1.0F) {
          rtb_Add_cx = -1.0F;
        }
      }

      u0_0 = ((CONTROL_PARAM.MC_YAW_RATE_P *
               Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] +
               Controller_DW.DiscreteTimeIntegrator_DSTATE[2]) +
              rtb_Saturation_h_idx_1) * (real32_T)rtb_Switch_a;
      if (u0_0 > 1.0F) {
        u0_0 = 1.0F;
      } else {
        if (u0_0 < -1.0F) {
          u0_0 = -1.0F;
        }
      }

      /* End of Saturate: '<S165>/Saturation1' */

      /* Product: '<S165>/Multiply' */
      for (rtb_Switch_a = 0; rtb_Switch_a < 4; rtb_Switch_a++) {
        /* Saturate: '<S165>/Saturation' incorporates:
         *  Constant: '<S165>/Effective_Matrix'
         *  DataTypeConversion: '<S167>/Data Type Conversion'
         *  Gain: '<S165>/Gain'
         *  Sum: '<S165>/Add'
         */
        rtb_BitwiseAND_0 = fmodf(floorf(1000.0F *
          (Controller_ConstP.pooled5[rtb_Switch_a + 8] * u0_0 +
           (Controller_ConstP.pooled5[rtb_Switch_a + 4] * rtb_Add_cx +
            Controller_ConstP.pooled5[rtb_Switch_a] * rtb_Add4_l)) + (real32_T)
          (uint16_T)i), 65536.0F);
        u0 = (uint16_T)(rtb_BitwiseAND_0 < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                        (uint16_T)-rtb_BitwiseAND_0 : (int32_T)(uint16_T)
                        rtb_BitwiseAND_0);
        if (u0 > 1900) {
          rtb_MultiportSwitch_o[rtb_Switch_a] = 1900U;
        } else if (u0 < 1000) {
          rtb_MultiportSwitch_o[rtb_Switch_a] = 1000U;
        } else {
          rtb_MultiportSwitch_o[rtb_Switch_a] = u0;
        }

        /* End of Saturate: '<S165>/Saturation' */
      }

      /* End of Product: '<S165>/Multiply' */
      break;

     default:
      rtb_MultiportSwitch_o[0] = 1000U;
      rtb_MultiportSwitch_o[1] = 1000U;
      rtb_MultiportSwitch_o[2] = 1000U;
      rtb_MultiportSwitch_o[3] = 1000U;
      break;
    }

    /* End of MultiPortSwitch: '<S166>/Multiport Switch' */
    /* End of Outputs for SubSystem: '<S158>/Quadcopter_x' */

    /* Switch: '<S134>/Switch' incorporates:
     *  Inport: '<Root>/FMS_Out'
     *  Logic: '<S134>/Logical Operator'
     *  RelationalOperator: '<S139>/Compare'
     *  S-Function (sfix_bitop): '<S80>/Bitwise AND'
     */
    if ((rtb_BitwiseAND_p_tmp == 3) || (rtb_BitwiseAND_p_tmp == 4)) {
      rtb_Multiply1 = Controller_U.FMS_Out.phi_cmd;
    }

    /* End of Switch: '<S134>/Switch' */

    /* Switch: '<S134>/Switch1' incorporates:
     *  Constant: '<S140>/Constant'
     *  DiscreteIntegrator: '<S150>/ '
     *  Gain: '<S122>/Gain'
     *  Gain: '<S122>/balabnce_ratio2'
     *  Gain: '<S122>/pitch_ff'
     *  Gain: '<S143>/P_control'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S140>/Compare'
     *  S-Function (sfix_bitop): '<S80>/Bitwise AND'
     *  Sum: '<S122>/Add3'
     *  Sum: '<S122>/Minus'
     *  Sum: '<S122>/Sum'
     *  Sum: '<S143>/Add'
     */
    if (rtb_BitwiseAND_p_tmp == 3) {
      rtb_BitwiseAND_0 = Controller_U.FMS_Out.theta_cmd;
    } else {
      rtb_BitwiseAND_0 = (((2.0F - CONTROL_PARAM.FW_TECS_RATIO) *
                           rtb_Subtract3_g - rtb_Subtract3_idx_1) *
                          CONTROL_PARAM.FW_TECS_PITCH_F +
                          ((CONTROL_PARAM.FW_TECS_PITCH_P * rtb_Gain_b_idx_1 +
                            Controller_DW._DSTATE) + rtb_Gain_cq)) +
        CONTROL_PARAM.FW_TECS_R2P * rtb_a;
    }

    /* End of Switch: '<S134>/Switch1' */

    /* Bias: '<S135>/Pitch Offset' */
    rtb_Add4_l = rtb_BitwiseAND_0 + CONTROL_PARAM.FW_PITCH_OFFSET;

    /* Saturate: '<S135>/Saturation' */
    if (rtb_Add4_l > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Add4_l = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_Add4_l < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_Add4_l = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      }
    }

    /* Product: '<S136>/Multiply' incorporates:
     *  Constant: '<S136>/Constant2'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S135>/Sum'
     */
    rtb_Saturation_h_idx_1 = (rtb_Add4_l - Controller_U.INS_Out.theta) *
      CONTROL_PARAM.FW_PITCH_P;

    /* Product: '<S138>/Divide' incorporates:
     *  Constant: '<S138>/Constant'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Add4_l = 9.81F / Controller_U.INS_Out.airspeed;

    /* Saturate: '<S138>/Saturation' */
    if (rtb_Add4_l > 1.0F) {
      rtb_Add4_l = 1.0F;
    } else {
      if (rtb_Add4_l < 0.0F) {
        rtb_Add4_l = 0.0F;
      }
    }

    /* End of Saturate: '<S138>/Saturation' */

    /* Sum: '<S133>/Sum' incorporates:
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S138>/Multiply'
     *  Product: '<S138>/Multiply1'
     *  Trigonometry: '<S138>/Cos'
     *  Trigonometry: '<S138>/Tan'
     */
    rtb_Add4_l = tanf(Controller_U.FMS_Out.phi_cmd) * arm_cos_f32
      (Controller_U.FMS_Out.theta_cmd) * rtb_Add4_l +
      Controller_U.FMS_Out.psi_rate_cmd;

    /* Saturate: '<S135>/Saturation' */
    if (rtb_Multiply1 > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Multiply1 = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_Multiply1 < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_Multiply1 = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      }
    }

    /* Sum: '<S126>/Add' incorporates:
     *  Constant: '<S136>/Constant1'
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S126>/Multiply'
     *  Product: '<S136>/Multiply'
     *  Sum: '<S135>/Sum'
     *  Trigonometry: '<S126>/Sin1'
     */
    rtb_Add_cx = (rtb_Multiply1 - Controller_U.INS_Out.phi) *
      CONTROL_PARAM.FW_ROLL_P - arm_sin_f32(Controller_U.INS_Out.theta) *
      rtb_Add4_l;

    /* Trigonometry: '<S126>/Sin' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Saturation_k_idx_1 = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S126>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Gain_cq = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Trigonometry: '<S126>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Add_b = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Sum: '<S126>/Add1' incorporates:
     *  Product: '<S126>/Multiply1'
     *  Product: '<S126>/Multiply3'
     *  Trigonometry: '<S126>/Cos'
     *  Trigonometry: '<S126>/Cos1'
     *  Trigonometry: '<S126>/Sin'
     */
    rtb_Multiply1 = rtb_Saturation_k_idx_1 * rtb_Gain_cq * rtb_Add4_l +
      rtb_Add_b * rtb_Saturation_h_idx_1;

    /* Sum: '<S126>/Add2' incorporates:
     *  Product: '<S126>/Multiply4'
     *  Product: '<S126>/Multiply5'
     *  Trigonometry: '<S126>/Cos'
     *  Trigonometry: '<S126>/Cos1'
     *  Trigonometry: '<S126>/Sin'
     */
    rtb_Gain_cq = rtb_Add_b * rtb_Gain_cq * rtb_Add4_l - rtb_Saturation_k_idx_1 *
      rtb_Saturation_h_idx_1;

    /* Sum: '<S124>/Minus2' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Add_b = rtb_Add_cx - Controller_U.INS_Out.p;
    rtb_Saturation_k_idx_1 = rtb_Multiply1 - Controller_U.INS_Out.q;
    rtb_Saturation_k_idx_2 = rtb_Gain_cq - Controller_U.INS_Out.r;

    /* DiscreteIntegrator: '<S130>/Discrete-Time Integrator' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator_PrevR_ef != 0)) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_l[0] =
        Controller_ConstB.Constant_c[0];
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_l[0] >=
          CONTROL_PARAM.FW_RATE_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_l[0] =
          CONTROL_PARAM.FW_RATE_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_l[0] <=
            CONTROL_PARAM.FW_RATE_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_l[0] =
            CONTROL_PARAM.FW_RATE_I_MIN;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_DSTATE_l[1] =
        Controller_ConstB.Constant_c[1];
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_l[1] >=
          CONTROL_PARAM.FW_RATE_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_l[1] =
          CONTROL_PARAM.FW_RATE_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_l[1] <=
            CONTROL_PARAM.FW_RATE_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_l[1] =
            CONTROL_PARAM.FW_RATE_I_MIN;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_DSTATE_l[2] =
        Controller_ConstB.Constant_c[2];
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_l[2] >=
          CONTROL_PARAM.FW_RATE_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_l[2] =
          CONTROL_PARAM.FW_RATE_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_l[2] <=
            CONTROL_PARAM.FW_RATE_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_l[2] =
            CONTROL_PARAM.FW_RATE_I_MIN;
        }
      }
    }

    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_l[0] >=
        CONTROL_PARAM.FW_RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_l[0] =
        CONTROL_PARAM.FW_RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_l[0] <=
          CONTROL_PARAM.FW_RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_l[0] =
          CONTROL_PARAM.FW_RATE_I_MIN;
      }
    }

    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_l[1] >=
        CONTROL_PARAM.FW_RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_l[1] =
        CONTROL_PARAM.FW_RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_l[1] <=
          CONTROL_PARAM.FW_RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_l[1] =
          CONTROL_PARAM.FW_RATE_I_MIN;
      }
    }

    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_l[2] >=
        CONTROL_PARAM.FW_RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_l[2] =
        CONTROL_PARAM.FW_RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_l[2] <=
          CONTROL_PARAM.FW_RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_l[2] =
          CONTROL_PARAM.FW_RATE_I_MIN;
      }
    }

    /* Sum: '<S122>/Add' incorporates:
     *  Gain: '<S122>/ucmd2thor'
     *  Gain: '<S122>/wcmd2thor'
     */
    rtb_uv_error_C_mPs_idx_1 = CONTROL_PARAM.FW_TECS_W2T * rtb_Gain_ap +
      CONTROL_PARAM.FW_TECS_U2T * rtb_Subtract3_idx_0;

    /* DiscreteIntegrator: '<S153>/ ' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    if ((Controller_U.FMS_Out.reset != 0) || (Controller_DW._PrevResetState_e !=
         0)) {
      Controller_DW._DSTATE_d = Controller_ConstB.Zero;
      if (Controller_DW._DSTATE_d >= 0.1F) {
        Controller_DW._DSTATE_d = 0.1F;
      } else {
        if (Controller_DW._DSTATE_d <= -0.1F) {
          Controller_DW._DSTATE_d = -0.1F;
        }
      }
    }

    if (Controller_DW._DSTATE_d >= 0.1F) {
      Controller_DW._DSTATE_d = 0.1F;
    } else {
      if (Controller_DW._DSTATE_d <= -0.1F) {
        Controller_DW._DSTATE_d = -0.1F;
      }
    }

    /* DiscreteIntegrator: '<S154>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_L_h0 != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_n = rtb_uv_error_C_mPs_idx_1;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_d != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_n = rtb_uv_error_C_mPs_idx_1;
    }

    /* Gain: '<S154>/Gain' incorporates:
     *  DiscreteIntegrator: '<S154>/Discrete-Time Integrator1'
     *  Sum: '<S154>/Sum5'
     */
    rtb_Saturation_h_idx_1 = (rtb_uv_error_C_mPs_idx_1 -
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_n) * 188.49556F;

    /* Outputs for Atomic SubSystem: '<S157>/Fixwing' */
    /* MultiPortSwitch: '<S162>/Multiport Switch' incorporates:
     *  Constant: '<S160>/Constant1'
     *  Constant: '<S160>/Constant12'
     *  Constant: '<S160>/Constant2'
     *  Constant: '<S160>/Constant7'
     *  Constant: '<S162>/Disarm'
     *  Constant: '<S162>/Standby'
     *  Inport: '<Root>/FMS_Out'
     */
    switch (Controller_U.FMS_Out.status) {
     case 1:
      for (i = 0; i < 5; i++) {
        rtb_MultiportSwitch_b3[i] = Controller_ConstP.pooled28[i];
      }
      break;

     case 2:
      for (i = 0; i < 5; i++) {
        rtb_MultiportSwitch_b3[i] = Controller_ConstP.Standby_Value[i];
      }
      break;

     case 3:
      /* Saturate: '<S124>/Saturation1' incorporates:
       *  Inport: '<Root>/INS_Out'
       */
      if (Controller_U.INS_Out.airspeed > 999.0F) {
        rtb_Subtract3_idx_0 = 999.0F;
      } else if (Controller_U.INS_Out.airspeed < 0.1F) {
        rtb_Subtract3_idx_0 = 0.1F;
      } else {
        rtb_Subtract3_idx_0 = Controller_U.INS_Out.airspeed;
      }

      /* End of Saturate: '<S124>/Saturation1' */

      /* Product: '<S128>/Divide' incorporates:
       *  Constant: '<S128>/trim_speed'
       *  Math: '<S128>/Square'
       *  Math: '<S128>/Square1'
       */
      rtb_Gain_ap = CONTROL_PARAM.FW_AIRSPEED_TRIM *
        CONTROL_PARAM.FW_AIRSPEED_TRIM / (rtb_Subtract3_idx_0 *
        rtb_Subtract3_idx_0);

      /* Saturate: '<S128>/Saturation' */
      if (rtb_Gain_ap > 1.0F) {
        rtb_Gain_ap = 1.0F;
      } else {
        if (rtb_Gain_ap < 0.0F) {
          rtb_Gain_ap = 0.0F;
        }
      }

      /* End of Saturate: '<S128>/Saturation' */

      /* Product: '<S129>/Divide' incorporates:
       *  Constant: '<S129>/trim_speed'
       */
      rtb_Subtract3_idx_0 = CONTROL_PARAM.FW_AIRSPEED_TRIM / rtb_Subtract3_idx_0;

      /* Saturate: '<S129>/Saturation' */
      if (rtb_Subtract3_idx_0 > 1.0F) {
        rtb_Subtract3_idx_0 = 1.0F;
      } else {
        if (rtb_Subtract3_idx_0 < 0.0F) {
          rtb_Subtract3_idx_0 = 0.0F;
        }
      }

      /* End of Saturate: '<S129>/Saturation' */
      rtb_MatrixConcatenate[11] = CONTROL_PARAM.FW_YAW_EFFC;

      /* SignalConversion: '<S160>/ConcatBufferAtVector Concatenate2In3' incorporates:
       *  Constant: '<S160>/Constant11'
       *  Constant: '<S160>/Constant12'
       */
      rtb_MatrixConcatenate[10] = 0.0F;

      /* SignalConversion: '<S160>/ConcatBufferAtVector Concatenate2In2' incorporates:
       *  Constant: '<S160>/Constant10'
       */
      rtb_MatrixConcatenate[9] = 0.0F;

      /* SignalConversion: '<S160>/ConcatBufferAtVector Concatenate2In1' incorporates:
       *  Constant: '<S160>/Constant9'
       */
      rtb_MatrixConcatenate[8] = 0.0F;

      /* SignalConversion: '<S160>/ConcatBufferAtVector Concatenate1In4' incorporates:
       *  Constant: '<S160>/Constant8'
       */
      rtb_MatrixConcatenate[7] = 0.0F;
      rtb_MatrixConcatenate[6] = CONTROL_PARAM.FW_PITCH_EFFC;

      /* SignalConversion: '<S160>/ConcatBufferAtVector Concatenate1In2' incorporates:
       *  Constant: '<S160>/Constant6'
       *  Constant: '<S160>/Constant7'
       */
      rtb_MatrixConcatenate[5] = 0.0F;

      /* SignalConversion: '<S160>/ConcatBufferAtVector Concatenate1In1' incorporates:
       *  Constant: '<S160>/Constant5'
       */
      rtb_MatrixConcatenate[4] = 0.0F;

      /* SignalConversion: '<S160>/ConcatBufferAtVector ConcatenateIn4' incorporates:
       *  Constant: '<S160>/Constant4'
       */
      rtb_MatrixConcatenate[3] = 0.0F;

      /* SignalConversion: '<S160>/ConcatBufferAtVector ConcatenateIn3' incorporates:
       *  Constant: '<S160>/Constant3'
       */
      rtb_MatrixConcatenate[2] = 0.0F;
      rtb_MatrixConcatenate[1] = CONTROL_PARAM.FW_ROLL_EFFC;
      rtb_MatrixConcatenate[0] = CONTROL_PARAM.FW_ROLL_EFFC;

      /* Switch: '<S161>/Switch' incorporates:
       *  Constant: '<S160>/Constant1'
       *  Constant: '<S160>/Constant2'
       *  Constant: '<S163>/Constant1'
       *  DataTypeConversion: '<S163>/Data Type Conversion'
       *  Gain: '<S163>/Gain1'
       *  Logic: '<S161>/Logical Operator'
       *  RelationalOperator: '<S164>/Compare'
       *  S-Function (sfix_bitop): '<S80>/Bitwise AND'
       *  Sum: '<S163>/Sum1'
       *  Switch: '<S154>/Switch'
       */
      if ((rtb_BitwiseAND_p_tmp == 1) || (rtb_BitwiseAND_p_tmp == 2) ||
          (rtb_BitwiseAND_p_tmp == 3)) {
        rtb_MultiportSwitch_b3[0] = Controller_U.FMS_Out.throttle_cmd;
      } else {
        if (Controller_U.FMS_Out.reset > 0) {
          /* Switch: '<S154>/Switch' incorporates:
           *  Gain: '<S154>/Gain1'
           */
          rtb_BitwiseAND_0 = 0.0F;
        } else {
          /* Switch: '<S154>/Switch' */
          rtb_BitwiseAND_0 = rtb_Saturation_h_idx_1;
        }

        /* Gain: '<S152>/Gain' */
        rtb_Add4_l = CONTROL_PARAM.FW_TECS_THOR_D * rtb_BitwiseAND_0;

        /* Saturate: '<S144>/Saturation1' */
        if (rtb_Add4_l > 0.3F) {
          rtb_Add4_l = 0.3F;
        } else {
          if (rtb_Add4_l < -0.3F) {
            rtb_Add4_l = -0.3F;
          }
        }

        /* End of Saturate: '<S144>/Saturation1' */

        /* Sum: '<S122>/Sum1' incorporates:
         *  DiscreteIntegrator: '<S153>/ '
         *  Gain: '<S122>/Gain1'
         *  Gain: '<S122>/balance_ratio'
         *  Gain: '<S122>/thorttle_ff'
         *  Gain: '<S144>/P_control'
         *  Sum: '<S122>/Add1'
         *  Sum: '<S122>/Add2'
         *  Sum: '<S144>/Add4'
         */
        rtb_Add4_l = (((CONTROL_PARAM.FW_TECS_THOR_P * rtb_uv_error_C_mPs_idx_1
                        + Controller_DW._DSTATE_d) + rtb_Add4_l) +
                      (CONTROL_PARAM.FW_TECS_RATIO * rtb_Subtract3_idx_1 +
                       rtb_Subtract3_g) * CONTROL_PARAM.FW_TECS_THOR_FF) +
          CONTROL_PARAM.FW_TECS_R2T * rtb_a;

        /* Saturate: '<S159>/Saturation5' */
        if (rtb_Add4_l > 1.0F) {
          rtb_Add4_l = 1.0F;
        } else {
          if (rtb_Add4_l < -1.0F) {
            rtb_Add4_l = -1.0F;
          }
        }

        /* End of Saturate: '<S159>/Saturation5' */

        /* Saturate: '<S163>/Saturation' incorporates:
         *  Constant: '<S163>/cruise_throttle'
         *  Sum: '<S163>/Sum'
         */
        if (rtb_Add4_l + 0.5F > 1.0F) {
          rtb_Subtract3_g = 1.0F;
        } else if (rtb_Add4_l + 0.5F < 0.0F) {
          rtb_Subtract3_g = 0.0F;
        } else {
          rtb_Subtract3_g = rtb_Add4_l + 0.5F;
        }

        /* End of Saturate: '<S163>/Saturation' */
        rtb_MultiportSwitch_b3[0] = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          rtb_Subtract3_g), 4.2949673E+9F) + 1000U);
      }

      /* End of Switch: '<S161>/Switch' */

      /* Product: '<S124>/Multiply1' incorporates:
       *  Gain: '<S124>/FF'
       */
      rtb_a = CONTROL_PARAM.FW_FF * rtb_Add_cx * rtb_Subtract3_idx_0;
      rtb_Subtract3_g = CONTROL_PARAM.FW_FF * rtb_Multiply1 *
        rtb_Subtract3_idx_0;
      rtb_Gain_cq = CONTROL_PARAM.FW_FF * rtb_Gain_cq * rtb_Subtract3_idx_0;

      /* Saturate: '<S124>/PI_limit' incorporates:
       *  Constant: '<S131>/gain1'
       *  DiscreteIntegrator: '<S130>/Discrete-Time Integrator'
       *  Product: '<S124>/Multiply'
       *  Product: '<S131>/Multiply'
       *  Saturate: '<S124>/FF_limit'
       *  Sum: '<S127>/Add1'
       */
      rtb_Add4_l = (CONTROL_PARAM.FW_ROLL_RATE_P * rtb_Add_b +
                    Controller_DW.DiscreteTimeIntegrator_DSTATE_l[0]) *
        rtb_Gain_ap;

      /* Saturate: '<S124>/FF_limit' */
      if (rtb_a > CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_a = CONTROL_PARAM.FW_FF_LIMIT;
      } else {
        if (rtb_a < -CONTROL_PARAM.FW_FF_LIMIT) {
          rtb_a = -CONTROL_PARAM.FW_FF_LIMIT;
        }
      }

      /* Saturate: '<S124>/PI_limit' */
      if (rtb_Add4_l > CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_Add4_l = CONTROL_PARAM.FW_PI_LIMIT;
      } else {
        if (rtb_Add4_l < -CONTROL_PARAM.FW_PI_LIMIT) {
          rtb_Add4_l = -CONTROL_PARAM.FW_PI_LIMIT;
        }
      }

      /* Saturate: '<S159>/Saturation4' incorporates:
       *  Product: '<S77>/Multiply'
       *  Sum: '<S124>/Add'
       */
      rtb_Add4_l = (rtb_a + rtb_Add4_l) * rtb_Add3_e;
      if (rtb_Add4_l > 1.0F) {
        rtb_Add4_l = 1.0F;
      } else {
        if (rtb_Add4_l < -1.0F) {
          rtb_Add4_l = -1.0F;
        }
      }

      /* Saturate: '<S124>/PI_limit' incorporates:
       *  Constant: '<S131>/gain2'
       *  DiscreteIntegrator: '<S130>/Discrete-Time Integrator'
       *  Product: '<S124>/Multiply'
       *  Product: '<S131>/Multiply'
       *  Saturate: '<S124>/FF_limit'
       *  Sum: '<S127>/Add1'
       */
      rtb_Add_cx = (CONTROL_PARAM.FW_PITCH_RATE_P * rtb_Saturation_k_idx_1 +
                    Controller_DW.DiscreteTimeIntegrator_DSTATE_l[1]) *
        rtb_Gain_ap;

      /* Saturate: '<S124>/FF_limit' */
      if (rtb_Subtract3_g > CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_Subtract3_g = CONTROL_PARAM.FW_FF_LIMIT;
      } else {
        if (rtb_Subtract3_g < -CONTROL_PARAM.FW_FF_LIMIT) {
          rtb_Subtract3_g = -CONTROL_PARAM.FW_FF_LIMIT;
        }
      }

      /* Saturate: '<S124>/PI_limit' */
      if (rtb_Add_cx > CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_Add_cx = CONTROL_PARAM.FW_PI_LIMIT;
      } else {
        if (rtb_Add_cx < -CONTROL_PARAM.FW_PI_LIMIT) {
          rtb_Add_cx = -CONTROL_PARAM.FW_PI_LIMIT;
        }
      }

      /* Saturate: '<S159>/Saturation4' incorporates:
       *  Product: '<S77>/Multiply'
       *  Sum: '<S124>/Add'
       */
      rtb_Add_cx = (rtb_Subtract3_g + rtb_Add_cx) * rtb_Add3_e;
      if (rtb_Add_cx > 1.0F) {
        rtb_Add_cx = 1.0F;
      } else {
        if (rtb_Add_cx < -1.0F) {
          rtb_Add_cx = -1.0F;
        }
      }

      /* Saturate: '<S124>/PI_limit' incorporates:
       *  Constant: '<S131>/gain3'
       *  DiscreteIntegrator: '<S130>/Discrete-Time Integrator'
       *  Product: '<S124>/Multiply'
       *  Product: '<S131>/Multiply'
       *  Saturate: '<S124>/FF_limit'
       *  Sum: '<S127>/Add1'
       */
      u0_0 = (CONTROL_PARAM.FW_YAW_RATE_P * rtb_Saturation_k_idx_2 +
              Controller_DW.DiscreteTimeIntegrator_DSTATE_l[2]) * rtb_Gain_ap;

      /* Saturate: '<S124>/FF_limit' */
      if (rtb_Gain_cq > CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_Gain_cq = CONTROL_PARAM.FW_FF_LIMIT;
      } else {
        if (rtb_Gain_cq < -CONTROL_PARAM.FW_FF_LIMIT) {
          rtb_Gain_cq = -CONTROL_PARAM.FW_FF_LIMIT;
        }
      }

      /* Saturate: '<S124>/PI_limit' */
      if (u0_0 > CONTROL_PARAM.FW_PI_LIMIT) {
        u0_0 = CONTROL_PARAM.FW_PI_LIMIT;
      } else {
        if (u0_0 < -CONTROL_PARAM.FW_PI_LIMIT) {
          u0_0 = -CONTROL_PARAM.FW_PI_LIMIT;
        }
      }

      /* Saturate: '<S159>/Saturation4' incorporates:
       *  Product: '<S77>/Multiply'
       *  Sum: '<S124>/Add'
       */
      u0_0 = (rtb_Gain_cq + u0_0) * rtb_Add3_e;
      if (u0_0 > 1.0F) {
        u0_0 = 1.0F;
      } else {
        if (u0_0 < -1.0F) {
          u0_0 = -1.0F;
        }
      }

      /* Product: '<S159>/Multiply1' incorporates:
       *  Saturate: '<S159>/Saturation3'
       */
      for (i = 0; i < 4; i++) {
        /* Saturate: '<S159>/Saturation3' incorporates:
         *  Bias: '<S159>/Bias'
         *  Gain: '<S159>/Gain1'
         */
        rtb_Gain_ap = 500.0F * (rtb_MatrixConcatenate[i + 8] * u0_0 +
          (rtb_MatrixConcatenate[i + 4] * rtb_Add_cx + rtb_MatrixConcatenate[i] *
           rtb_Add4_l)) + 1500.0F;
        if (rtb_Gain_ap > 2000.0F) {
          rtb_Gain_ap = 2000.0F;
        } else {
          if (rtb_Gain_ap < 1000.0F) {
            rtb_Gain_ap = 1000.0F;
          }
        }

        rtb_MultiportSwitch_b3[i + 1] = (uint16_T)fmodf(floorf(rtb_Gain_ap),
          65536.0F);
      }

      /* End of Product: '<S159>/Multiply1' */
      break;

     default:
      for (i = 0; i < 5; i++) {
        rtb_MultiportSwitch_b3[i] = Controller_ConstP.pooled28[i];
      }
      break;
    }

    /* End of MultiPortSwitch: '<S162>/Multiport Switch' */
    /* End of Outputs for SubSystem: '<S157>/Fixwing' */

    /* Outputs for Atomic SubSystem: '<S158>/Quadcopter_x' */
    /* Reshape: '<S156>/Reshape' incorporates:
     *  Reshape: '<S162>/Reshape'
     *  Reshape: '<S166>/Reshape'
     */
    Controller_B.Reshape[0] = rtb_MultiportSwitch_o[0];
    Controller_B.Reshape[1] = rtb_MultiportSwitch_o[1];
    Controller_B.Reshape[2] = rtb_MultiportSwitch_o[2];
    Controller_B.Reshape[3] = rtb_MultiportSwitch_o[3];

    /* End of Outputs for SubSystem: '<S158>/Quadcopter_x' */
    for (i = 0; i < 5; i++) {
      /* Outputs for Atomic SubSystem: '<S157>/Fixwing' */
      Controller_B.Reshape[i + 4] = rtb_MultiportSwitch_b3[i];

      /* End of Outputs for SubSystem: '<S157>/Fixwing' */
    }

    for (i = 0; i < 7; i++) {
      Controller_B.Reshape[i + 9] = 0U;
    }

    /* End of Reshape: '<S156>/Reshape' */

    /* Product: '<S93>/Multiply' incorporates:
     *  Constant: '<S93>/gain1'
     *  Constant: '<S93>/gain2'
     *  Constant: '<S93>/gain3'
     *  DiscreteIntegrator: '<S91>/Discrete-Time Integrator5'
     */
    rtb_a = CONTROL_PARAM.MC_ROLL_RATE_I *
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[0];
    rtb_Subtract3_g = CONTROL_PARAM.MC_PITCH_RATE_I *
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[1];
    rtb_Subtract3_idx_1 = CONTROL_PARAM.MC_YAW_RATE_I *
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[2];

    /* Product: '<S115>/Multiply1' incorporates:
     *  Constant: '<S115>/const1'
     *  DiscreteIntegrator: '<S114>/Integrator'
     */
    rtb_Add4_l = Controller_DW.Integrator_DSTATE * 0.05F;

    /* Switch: '<S106>/Switch' incorporates:
     *  Constant: '<S106>/Zero'
     *  Constant: '<S109>/Constant'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S109>/Compare'
     *  S-Function (sfix_bitop): '<S80>/Bitwise AND'
     */
    if (rtb_BitwiseAND_p_tmp <= 3) {
      rtb_BitwiseAND_0 = 0.0F;
    } else {
      rtb_BitwiseAND_0 = Controller_U.FMS_Out.w_cmd;
    }

    /* End of Switch: '<S106>/Switch' */

    /* Sum: '<S115>/Add' incorporates:
     *  DiscreteIntegrator: '<S114>/Integrator1'
     *  Sum: '<S114>/Subtract'
     */
    rtb_Gain_cq = (Controller_DW.Integrator1_DSTATE - rtb_BitwiseAND_0) +
      rtb_Add4_l;

    /* Signum: '<S115>/Sign' */
    if (rtb_Gain_cq < 0.0F) {
      rtb_Gain_ap = -1.0F;
    } else if (rtb_Gain_cq > 0.0F) {
      rtb_Gain_ap = 1.0F;
    } else {
      rtb_Gain_ap = rtb_Gain_cq;
    }

    /* End of Signum: '<S115>/Sign' */

    /* Sum: '<S115>/Add2' incorporates:
     *  Abs: '<S115>/Abs'
     *  Gain: '<S115>/Gain'
     *  Gain: '<S115>/Gain1'
     *  Product: '<S115>/Multiply2'
     *  Product: '<S115>/Multiply3'
     *  Sqrt: '<S115>/Sqrt'
     *  Sum: '<S115>/Add1'
     *  Sum: '<S115>/Subtract'
     */
    rtb_Gain_ap = (sqrtf((8.0F * fabsf(rtb_Gain_cq) + Controller_ConstB.d) *
                         Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
      rtb_Gain_ap + rtb_Add4_l;

    /* Sum: '<S115>/Add4' */
    rtb_Add4_l += rtb_Gain_cq - rtb_Gain_ap;

    /* Sum: '<S115>/Add3' */
    rtb_Add3_e = rtb_Gain_cq + Controller_ConstB.d;

    /* Sum: '<S115>/Subtract1' */
    rtb_Gain_cq -= Controller_ConstB.d;

    /* Signum: '<S115>/Sign1' */
    if (rtb_Add3_e < 0.0F) {
      rtb_Add3_e = -1.0F;
    } else {
      if (rtb_Add3_e > 0.0F) {
        rtb_Add3_e = 1.0F;
      }
    }

    /* End of Signum: '<S115>/Sign1' */

    /* Signum: '<S115>/Sign2' */
    if (rtb_Gain_cq < 0.0F) {
      rtb_Gain_cq = -1.0F;
    } else {
      if (rtb_Gain_cq > 0.0F) {
        rtb_Gain_cq = 1.0F;
      }
    }

    /* End of Signum: '<S115>/Sign2' */

    /* Sum: '<S115>/Add5' incorporates:
     *  Gain: '<S115>/Gain2'
     *  Product: '<S115>/Multiply4'
     *  Sum: '<S115>/Subtract2'
     */
    rtb_Gain_ap += (rtb_Add3_e - rtb_Gain_cq) * 0.5F * rtb_Add4_l;

    /* Update for DiscreteIntegrator: '<S150>/ ' incorporates:
     *  Gain: '<S150>/Gain3'
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW._DSTATE += CONTROL_PARAM.FW_TECS_PITCH_I * rtb_Gain_b_idx_1 *
      0.002F;
    if (Controller_DW._DSTATE >= CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
      Controller_DW._DSTATE = CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
    } else {
      if (Controller_DW._DSTATE <= -CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
        Controller_DW._DSTATE = -CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
      }
    }

    Controller_DW._PrevResetState = (int8_T)(Controller_U.FMS_Out.reset > 0);

    /* End of Update for DiscreteIntegrator: '<S150>/ ' */

    /* Update for DiscreteIntegrator: '<S151>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTATE += 0.002F * rtb_a_m_idx_0;
    Controller_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S91>/Discrete-Time Integrator5' */
    Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;

    /* Update for DiscreteIntegrator: '<S93>/Discrete-Time Integrator' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S95>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_h = 0U;

    /* Update for DiscreteIntegrator: '<S91>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S91>/Gain'
     *  Sum: '<S91>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] +=
      (rtb_rate_error_B_radPs_n_idx_0 -
       Controller_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S93>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] += 0.002F * rtb_a;
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

    /* Update for DiscreteIntegrator: '<S95>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[0] += 0.002F *
      rtb_DiscreteTimeIntegrator1_n_i;

    /* Update for DiscreteIntegrator: '<S91>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S91>/Gain'
     *  Sum: '<S91>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] +=
      (rtb_rate_error_B_radPs_n_idx_1 -
       Controller_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S93>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_DSTATE[1] += 0.002F * rtb_Subtract3_g;
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

    /* Update for DiscreteIntegrator: '<S95>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[1] += 0.002F * rtb_a_m_idx_1;

    /* Update for DiscreteIntegrator: '<S91>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S91>/Gain'
     *  Sum: '<S91>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] +=
      (rtb_rate_error_B_radPs_n_idx_2 -
       Controller_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S93>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_DSTATE[2] += 0.002F *
      rtb_Subtract3_idx_1;
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

    /* Update for DiscreteIntegrator: '<S95>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[2] += 0.002F *
      rtb_DiscreteTimeIntegrator1_n_0;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_l = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S114>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S114>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE += 0.002F * Controller_DW.Integrator_DSTATE;

    /* Update for DiscreteIntegrator: '<S117>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S117>/ki'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S117>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_b += CONTROL_PARAM.MC_VEL_Z_I *
      rtb_Gain_b_idx_0 * 0.002F;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_b >=
        CONTROL_PARAM.MC_VEL_Z_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_b =
        CONTROL_PARAM.MC_VEL_Z_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_b <=
          CONTROL_PARAM.MC_VEL_Z_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_b =
          CONTROL_PARAM.MC_VEL_Z_I_MIN;
      }
    }

    Controller_DW.DiscreteTimeIntegrator_PrevRe_e = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* End of Update for DiscreteIntegrator: '<S117>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S119>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_i = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_l += 0.002F *
      rtb_uv_error_C_mPs_idx_0;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_h = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S130>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S130>/gain1'
     *  Constant: '<S130>/gain2'
     *  Constant: '<S130>/gain3'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S130>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_l[0] +=
      CONTROL_PARAM.FW_ROLL_RATE_I * rtb_Add_b * 0.002F;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_l[0] >=
        CONTROL_PARAM.FW_RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_l[0] =
        CONTROL_PARAM.FW_RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_l[0] <=
          CONTROL_PARAM.FW_RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_l[0] =
          CONTROL_PARAM.FW_RATE_I_MIN;
      }
    }

    Controller_DW.DiscreteTimeIntegrator_DSTATE_l[1] +=
      CONTROL_PARAM.FW_PITCH_RATE_I * rtb_Saturation_k_idx_1 * 0.002F;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_l[1] >=
        CONTROL_PARAM.FW_RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_l[1] =
        CONTROL_PARAM.FW_RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_l[1] <=
          CONTROL_PARAM.FW_RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_l[1] =
          CONTROL_PARAM.FW_RATE_I_MIN;
      }
    }

    Controller_DW.DiscreteTimeIntegrator_DSTATE_l[2] +=
      CONTROL_PARAM.FW_YAW_RATE_I * rtb_Saturation_k_idx_2 * 0.002F;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_l[2] >=
        CONTROL_PARAM.FW_RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_l[2] =
        CONTROL_PARAM.FW_RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_l[2] <=
          CONTROL_PARAM.FW_RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_l[2] =
          CONTROL_PARAM.FW_RATE_I_MIN;
      }
    }

    Controller_DW.DiscreteTimeIntegrator_PrevR_ef = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* End of Update for DiscreteIntegrator: '<S130>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S153>/ ' incorporates:
     *  Gain: '<S153>/Gain'
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW._DSTATE_d += CONTROL_PARAM.FW_TECS_THOR_I *
      rtb_uv_error_C_mPs_idx_1 * 0.002F;
    if (Controller_DW._DSTATE_d >= 0.1F) {
      Controller_DW._DSTATE_d = 0.1F;
    } else {
      if (Controller_DW._DSTATE_d <= -0.1F) {
        Controller_DW._DSTATE_d = -0.1F;
      }
    }

    Controller_DW._PrevResetState_e = (int8_T)(Controller_U.FMS_Out.reset > 0);

    /* End of Update for DiscreteIntegrator: '<S153>/ ' */

    /* Update for DiscreteIntegrator: '<S154>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.DiscreteTimeIntegrator1_IC_L_h0 = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n += 0.002F *
      rtb_Saturation_h_idx_1;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_d = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Signum: '<S115>/Sign6' incorporates:
     *  Signum: '<S115>/Sign5'
     */
    if (rtb_Gain_ap < 0.0F) {
      rtb_Subtract3_g = -1.0F;

      /* Signum: '<S115>/Sign5' */
      rtb_a_m_idx_1 = -1.0F;
    } else if (rtb_Gain_ap > 0.0F) {
      rtb_Subtract3_g = 1.0F;

      /* Signum: '<S115>/Sign5' */
      rtb_a_m_idx_1 = 1.0F;
    } else {
      rtb_Subtract3_g = rtb_Gain_ap;

      /* Signum: '<S115>/Sign5' */
      rtb_a_m_idx_1 = rtb_Gain_ap;
    }

    /* End of Signum: '<S115>/Sign6' */

    /* Sum: '<S115>/Add6' */
    rtb_Add3_e = rtb_Gain_ap + Controller_ConstB.d;

    /* Sum: '<S115>/Subtract3' */
    rtb_DiscreteTimeIntegrator1_n_i = rtb_Gain_ap - Controller_ConstB.d;

    /* Signum: '<S115>/Sign3' */
    if (rtb_Add3_e < 0.0F) {
      rtb_Add3_e = -1.0F;
    } else {
      if (rtb_Add3_e > 0.0F) {
        rtb_Add3_e = 1.0F;
      }
    }

    /* End of Signum: '<S115>/Sign3' */

    /* Signum: '<S115>/Sign4' */
    if (rtb_DiscreteTimeIntegrator1_n_i < 0.0F) {
      rtb_DiscreteTimeIntegrator1_n_i = -1.0F;
    } else {
      if (rtb_DiscreteTimeIntegrator1_n_i > 0.0F) {
        rtb_DiscreteTimeIntegrator1_n_i = 1.0F;
      }
    }

    /* End of Signum: '<S115>/Sign4' */

    /* Update for DiscreteIntegrator: '<S114>/Integrator' incorporates:
     *  Constant: '<S115>/const'
     *  Gain: '<S115>/Gain3'
     *  Product: '<S115>/Divide'
     *  Product: '<S115>/Multiply5'
     *  Product: '<S115>/Multiply6'
     *  Sum: '<S115>/Subtract4'
     *  Sum: '<S115>/Subtract5'
     *  Sum: '<S115>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE += ((rtb_Gain_ap / Controller_ConstB.d -
      rtb_a_m_idx_1) * Controller_ConstB.Gain4 * ((rtb_Add3_e -
      rtb_DiscreteTimeIntegrator1_n_i) * 0.5F) - rtb_Subtract3_g * 78.448F) *
      0.002F;

    /* End of Outputs for SubSystem: '<S2>/VTOL_Controller' */
    break;
  }

  /* RelationalOperator: '<S75>/Compare' incorporates:
   *  Constant: '<S75>/Constant'
   */
  rtb_Compare_ev = (tmp == 0U);

  /* Outport: '<Root>/Control_Out' incorporates:
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   */
  Controller_Y.Control_Out.timestamp =
    Controller_DW.DiscreteTimeIntegrator_DSTATE_n;
  for (i = 0; i < 16; i++) {
    /* Switch: '<S5>/Switch' */
    if (rtb_Compare_ev) {
      Controller_Y.Control_Out.actuator_cmd[i] = Controller_B.Reshape_g[i];
    } else {
      Controller_Y.Control_Out.actuator_cmd[i] = Controller_B.Reshape[i];
    }

    /* End of Switch: '<S5>/Switch' */
  }

  /* End of Outport: '<Root>/Control_Out' */

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

  /* Start for SwitchCase: '<S7>/Switch Case1' */
  Controller_DW.SwitchCase1_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S2>/MC_Controller' */
  /* Start for Constant: '<S72>/Constant' */
  Controller_B.Constant_b = CONTROL_PARAM.MC_VEL_Z_I_MIN;

  /* End of Start for SubSystem: '<S2>/MC_Controller' */

  /* Start for IfAction SubSystem: '<S2>/VTOL_Controller' */
  /* Start for Constant: '<S117>/Constant' */
  Controller_B.Constant = CONTROL_PARAM.MC_VEL_Z_I_MIN;

  /* End of Start for SubSystem: '<S2>/VTOL_Controller' */

  /* SystemInitialize for IfAction SubSystem: '<S2>/MC_Controller' */
  /* InitializeConditions for DiscreteIntegrator: '<S46>/Integrator1' */
  Controller_DW.Integrator1_DSTATE_e[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S51>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S46>/Integrator1' */
  Controller_DW.Integrator1_DSTATE_e[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S51>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S53>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_m = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_a = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S22>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_c = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S24>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[0] =
    Controller_ConstB.Constant_a[0];
  if (Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[0] >=
      CONTROL_PARAM.MC_RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[0] =
      CONTROL_PARAM.MC_RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[0] <=
        CONTROL_PARAM.MC_RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[0] =
        CONTROL_PARAM.MC_RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[1] =
    Controller_ConstB.Constant_a[1];
  if (Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[1] >=
      CONTROL_PARAM.MC_RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[1] =
      CONTROL_PARAM.MC_RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[1] <=
        CONTROL_PARAM.MC_RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[1] =
        CONTROL_PARAM.MC_RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[2] =
    Controller_ConstB.Constant_a[2];
  if (Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[2] >=
      CONTROL_PARAM.MC_RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[2] =
      CONTROL_PARAM.MC_RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[2] <=
        CONTROL_PARAM.MC_RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_b0[2] =
        CONTROL_PARAM.MC_RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRe_d = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S24>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S26>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_k = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S69>/Integrator1' */
  Controller_DW.Integrator1_DSTATE_eq = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S72>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTAT_lc = Controller_B.Constant_b;
  if (Controller_DW.DiscreteTimeIntegrator_DSTAT_lc >=
      CONTROL_PARAM.MC_VEL_Z_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTAT_lc = CONTROL_PARAM.MC_VEL_Z_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTAT_lc <=
        CONTROL_PARAM.MC_VEL_Z_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_lc =
        CONTROL_PARAM.MC_VEL_Z_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRe_f = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S72>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S74>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 1U;
  Controller_DW.DiscreteTimeIntegrator1_Prev_ks = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S46>/Integrator' */
  Controller_DW.Integrator_DSTATE_l[0] = 0.0F;
  Controller_DW.Integrator_DSTATE_l[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S69>/Integrator' */
  Controller_DW.Integrator_DSTATE_j = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S2>/MC_Controller' */

  /* SystemInitialize for IfAction SubSystem: '<S2>/VTOL_Controller' */
  /* InitializeConditions for DiscreteIntegrator: '<S150>/ ' */
  Controller_DW._DSTATE = Controller_ConstB.Zero1;
  if (Controller_DW._DSTATE >= CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
    Controller_DW._DSTATE = CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
  } else {
    if (Controller_DW._DSTATE <= -CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
      Controller_DW._DSTATE = -CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
    }
  }

  Controller_DW._PrevResetState = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S150>/ ' */

  /* InitializeConditions for DiscreteIntegrator: '<S151>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S91>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S93>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S93>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S95>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_h = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_l = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S114>/Integrator1' */
  Controller_DW.Integrator1_DSTATE = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S117>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_b = Controller_B.Constant;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_b >=
      CONTROL_PARAM.MC_VEL_Z_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_b = CONTROL_PARAM.MC_VEL_Z_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_b <=
        CONTROL_PARAM.MC_VEL_Z_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_b =
        CONTROL_PARAM.MC_VEL_Z_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRe_e = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S117>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S119>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_i = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_h = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S130>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_l[0] =
    Controller_ConstB.Constant_c[0];
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_l[0] >=
      CONTROL_PARAM.FW_RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_l[0] =
      CONTROL_PARAM.FW_RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_l[0] <=
        CONTROL_PARAM.FW_RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_l[0] =
        CONTROL_PARAM.FW_RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_DSTATE_l[1] =
    Controller_ConstB.Constant_c[1];
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_l[1] >=
      CONTROL_PARAM.FW_RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_l[1] =
      CONTROL_PARAM.FW_RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_l[1] <=
        CONTROL_PARAM.FW_RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_l[1] =
        CONTROL_PARAM.FW_RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_DSTATE_l[2] =
    Controller_ConstB.Constant_c[2];
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_l[2] >=
      CONTROL_PARAM.FW_RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_l[2] =
      CONTROL_PARAM.FW_RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_l[2] <=
        CONTROL_PARAM.FW_RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_l[2] =
        CONTROL_PARAM.FW_RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevR_ef = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S130>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S153>/ ' */
  Controller_DW._DSTATE_d = Controller_ConstB.Zero;
  if (Controller_DW._DSTATE_d >= 0.1F) {
    Controller_DW._DSTATE_d = 0.1F;
  } else {
    if (Controller_DW._DSTATE_d <= -0.1F) {
      Controller_DW._DSTATE_d = -0.1F;
    }
  }

  Controller_DW._PrevResetState_e = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S153>/ ' */

  /* InitializeConditions for DiscreteIntegrator: '<S154>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_L_h0 = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_d = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S114>/Integrator' */
  Controller_DW.Integrator_DSTATE = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S2>/VTOL_Controller' */
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
