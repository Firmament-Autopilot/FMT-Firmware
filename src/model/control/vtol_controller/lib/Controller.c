/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.423
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Aug  7 17:30:19 2025
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
struct_wPl8ajGklGKyYxGcwjdpiH CONTROL_PARAM = {
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
  0.34906584F,
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
  7.0F,
  7.0F,
  1.04719758F,
  0.1F,
  0.2F,
  0.2F,
  0.1F,
  0.1F,
  0.2F,
  -0.2F,
  0.2F,
  1.57079637F,
  3.14159274F,
  17.0F,
  0.2F,
  0.3F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  0.0F,
  0.5F,
  0.1F,
  0.1F,
  0.15F,
  0.1F,
  0.2F,
  0.15F,
  0.2F,
  0.0F,
  0.0F,
  1.0F,
  1.0F,
  2.0F,
  2.0F,
  1.0F,
  1.0F,
  2.0F,
  0.1F,
  0.1F,
  0.1F,
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
                                        *   '<S64>/Saturation'
                                        *   '<S65>/Gain'
                                        *   '<S65>/Gain1'
                                        *   '<S65>/balabnce_ratio2'
                                        *   '<S65>/balance_ratio'
                                        *   '<S65>/pitch_ff'
                                        *   '<S65>/thorttle_ff'
                                        *   '<S65>/ucmd2pitch'
                                        *   '<S65>/ucmd2thor'
                                        *   '<S65>/wcmd2pitch'
                                        *   '<S65>/wcmd2thor'
                                        *   '<S159>/hover_throttle'
                                        *   '<S40>/hover_throttle'
                                        *   '<S67>/FF'
                                        *   '<S67>/FF_limit'
                                        *   '<S67>/PI_limit'
                                        *   '<S85>/P_control'
                                        *   '<S86>/P_control'
                                        *   '<S87>/Kv'
                                        *   '<S136>/Saturation'
                                        *   '<S174>/Bias1'
                                        *   '<S174>/Bias2'
                                        *   '<S174>/Bias3'
                                        *   '<S174>/Bias4'
                                        *   '<S183>/Bias1'
                                        *   '<S183>/Bias2'
                                        *   '<S183>/Bias3'
                                        *   '<S183>/Bias4'
                                        *   '<S20>/Saturation'
                                        *   '<S20>/Saturation1'
                                        *   '<S71>/trim_speed'
                                        *   '<S72>/trim_speed'
                                        *   '<S93>/Gain'
                                        *   '<S94>/ '
                                        *   '<S94>/Gain3'
                                        *   '<S96>/Gain'
                                        *   '<S97>/Gain'
                                        *   '<S112>/Saturation'
                                        *   '<S112>/Saturation1'
                                        *   '<S145>/kd'
                                        *   '<S145>/Saturation'
                                        *   '<S146>/ki'
                                        *   '<S146>/Discrete-Time Integrator'
                                        *   '<S147>/kp'
                                        *   '<S166>/kd'
                                        *   '<S166>/Saturation'
                                        *   '<S167>/Constant'
                                        *   '<S167>/ki'
                                        *   '<S167>/Discrete-Time Integrator'
                                        *   '<S168>/kp'
                                        *   '<S177>/Constant1'
                                        *   '<S177>/Constant12'
                                        *   '<S177>/Constant2'
                                        *   '<S177>/Constant7'
                                        *   '<S181>/Bias'
                                        *   '<S181>/Bias1'
                                        *   '<S181>/Bias2'
                                        *   '<S181>/Bias3'
                                        *   '<S182>/Bias'
                                        *   '<S182>/Bias1'
                                        *   '<S182>/Bias2'
                                        *   '<S182>/Bias3'
                                        *   '<S186>/Constant1'
                                        *   '<S186>/Constant11'
                                        *   '<S186>/Constant12'
                                        *   '<S186>/Constant2'
                                        *   '<S186>/Constant7'
                                        *   '<S186>/Constant8'
                                        *   '<S190>/Bias'
                                        *   '<S190>/Bias1'
                                        *   '<S190>/Bias2'
                                        *   '<S190>/Bias3'
                                        *   '<S191>/Bias'
                                        *   '<S191>/Bias1'
                                        *   '<S191>/Bias2'
                                        *   '<S191>/Bias3'
                                        *   '<S32>/Constant1'
                                        *   '<S32>/Constant2'
                                        *   '<S47>/kd'
                                        *   '<S47>/Saturation'
                                        *   '<S48>/Constant'
                                        *   '<S48>/ki'
                                        *   '<S48>/Discrete-Time Integrator'
                                        *   '<S49>/kp'
                                        *   '<S73>/gain1'
                                        *   '<S73>/gain2'
                                        *   '<S73>/gain3'
                                        *   '<S73>/Discrete-Time Integrator'
                                        *   '<S74>/gain1'
                                        *   '<S74>/gain2'
                                        *   '<S74>/gain3'
                                        *   '<S78>/Pitch Offset'
                                        *   '<S78>/Saturation'
                                        *   '<S79>/Constant1'
                                        *   '<S79>/Constant2'
                                        *   '<S129>/Constant1'
                                        *   '<S129>/Constant2'
                                        *   '<S25>/gain1'
                                        *   '<S25>/gain2'
                                        *   '<S25>/gain3'
                                        *   '<S25>/Saturation'
                                        *   '<S26>/gain1'
                                        *   '<S26>/gain2'
                                        *   '<S26>/gain3'
                                        *   '<S26>/Discrete-Time Integrator'
                                        *   '<S27>/gain1'
                                        *   '<S27>/gain2'
                                        *   '<S27>/gain3'
                                        *   '<S118>/gain1'
                                        *   '<S118>/gain2'
                                        *   '<S118>/gain3'
                                        *   '<S118>/Saturation'
                                        *   '<S119>/gain1'
                                        *   '<S119>/gain2'
                                        *   '<S119>/gain3'
                                        *   '<S119>/Discrete-Time Integrator'
                                        *   '<S120>/gain1'
                                        *   '<S120>/gain2'
                                        *   '<S120>/gain3'
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
  /* local block i/o variables */
  uint16_T rtb_VariantMergeForOutportactua[9];
  int8_T rtPrevAction;
  uint8_T rtb_BitwiseAND_n;
  real32_T rtb_VectorConcatenate_o[9];
  real32_T rtb_DiscreteTimeIntegrator1_k1[3];
  boolean_T rtb_Compare_nq;
  int32_T rtb_Relay;
  boolean_T rtb_LogicalOperator_i;
  real32_T rtb_phi_cmd;
  real32_T rtb_Abs;
  real32_T rtb_Sum_l;
  real32_T rtb_DiscreteTimeIntegrator5_h5;
  real32_T rtb_VdotPg;
  real32_T rtb_Multiply1_e;
  real32_T rtb_Cos_j;
  real32_T rtb_Gain_c4;
  real32_T rtb_Add3_fc;
  boolean_T rtb_LogicalOperator_g;
  real32_T rtb_Square_d;
  real32_T rtb_Saturation_g;
  real32_T rtb_VectorConcatenate_k[3];
  real32_T rtb_Saturation_ni;
  real32_T rtb_TmpSignalConversionAtMult_0;
  real32_T rtb_TmpSignalConversionAtMult_1;
  real32_T rtb_TmpSignalConversionAtMult_2;
  real32_T rtb_aux_att_error_B_rad_idx_0;
  real32_T rtb_aux_att_error_B_rad_idx_1;
  real32_T rtb_Saturation_j_idx_0;
  real32_T rtb_Saturation_j_idx_1;
  real32_T rtb_Saturation_j_idx_2;
  real32_T rtb_Divide_m_idx_0;
  real32_T rtb_Divide_m_idx_3;
  real32_T rtb_Divide_m_idx_1;
  real32_T rtb_Divide_m_idx_2;
  real32_T rtb_TmpSignalConversionAtMult_3;
  real32_T rtb_DiscreteTimeIntegrator1_a_t;
  real32_T rtb_Integrator1_o_tmp;

  /* S-Function (sfix_bitop): '<S7>/Bitwise AND' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  rtb_BitwiseAND_n = (uint8_T)(Controller_U.FMS_Out.ctrl_mode & 63);

  /* SwitchCase: '<S8>/Switch Case1' incorporates:
   *  Constant: '<S167>/Constant'
   *  Constant: '<S48>/Constant'
   *  DataTypeConversion: '<S8>/Data Type Conversion'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S118>/Multiply'
   *  Product: '<S131>/Divide1'
   *  Product: '<S145>/Multiply'
   *  Product: '<S34>/Divide1'
   *  Product: '<S8>/Divide'
   *  S-Function (sfix_bitop): '<S8>/Bitwise AND'
   */
  rtPrevAction = Controller_DW.SwitchCase1_ActiveSubsystem;
  switch ((int32_T)(uint8_T)((uint32_T)(Controller_U.FMS_Out.ctrl_mode & 192) >>
           6)) {
   case VTOLState_Fixwing:
   case VTOLState_ForwardTrans:
   case VTOLState_BackwardTrans:
    Controller_DW.SwitchCase1_ActiveSubsystem = 0;
    break;

   default:
    Controller_DW.SwitchCase1_ActiveSubsystem = 1;
    break;
  }

  switch (Controller_DW.SwitchCase1_ActiveSubsystem) {
   case 0:
    if (Controller_DW.SwitchCase1_ActiveSubsystem != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S2>/FW_Controller' incorporates:
       *  ActionPort: '<S4>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S8>/Switch Case1' incorporates:
       *  DiscreteIntegrator: '<S24>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S26>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S28>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S45>/Integrator'
       *  DiscreteIntegrator: '<S45>/Integrator1'
       *  DiscreteIntegrator: '<S48>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S50>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S51>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S52>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S53>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S55>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S73>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S94>/ '
       *  DiscreteIntegrator: '<S95>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S97>/ '
       *  DiscreteIntegrator: '<S98>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S99>/Discrete-Time Integrator5'
       */
      Controller_DW.DiscreteTimeIntegrator5_IC_LO_e = 1U;
      Controller_DW.DiscreteTimeIntegrator5_IC_L_eo = 1U;
      Controller_DW.DiscreteTimeIntegrator5_IC_LO_o = 1U;
      Controller_DW.DiscreteTimeIntegrator_DSTATE_d[0] =
        Controller_ConstB.Constant_j[0];
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_d[0] >=
          CONTROL_PARAM.MC_RATE_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_d[0] =
          CONTROL_PARAM.MC_RATE_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_d[0] <=
            CONTROL_PARAM.MC_RATE_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_d[0] =
            CONTROL_PARAM.MC_RATE_I_MIN;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_DSTATE_d[1] =
        Controller_ConstB.Constant_j[1];
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_d[1] >=
          CONTROL_PARAM.MC_RATE_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_d[1] =
          CONTROL_PARAM.MC_RATE_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_d[1] <=
            CONTROL_PARAM.MC_RATE_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_d[1] =
            CONTROL_PARAM.MC_RATE_I_MIN;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_DSTATE_d[2] =
        Controller_ConstB.Constant_j[2];
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_d[2] >=
          CONTROL_PARAM.MC_RATE_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_d[2] =
          CONTROL_PARAM.MC_RATE_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_d[2] <=
            CONTROL_PARAM.MC_RATE_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_d[2] =
            CONTROL_PARAM.MC_RATE_I_MIN;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_PrevRe_o = 0;
      Controller_DW.DiscreteTimeIntegrator5_IC_LO_n = 1U;
      Controller_DW._DSTATE = Controller_ConstB.Zero1;
      if (Controller_DW._DSTATE >= CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
        Controller_DW._DSTATE = CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
      } else {
        if (Controller_DW._DSTATE <= -CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
          Controller_DW._DSTATE = -CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
        }
      }

      Controller_DW._PrevResetState = 0;
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_f = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevR_b = 0;
      Controller_DW.DiscreteTimeIntegrator5_IC_LO_b = 1U;
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_h = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevR_l = 0;
      Controller_DW._DSTATE_d = Controller_ConstB.Zero;
      if (Controller_DW._DSTATE_d >= 1.0F) {
        Controller_DW._DSTATE_d = 1.0F;
      } else {
        if (Controller_DW._DSTATE_d <= 0.0F) {
          Controller_DW._DSTATE_d = 0.0F;
        }
      }

      Controller_DW._PrevResetState_e = 0;
      Controller_DW.DiscreteTimeIntegrator1_IC_L_h0 = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevR_d = 0;
      Controller_DW.Integrator1_DSTATE_i = 0.0F;
      Controller_DW.DiscreteTimeIntegrator_DSTATE_b = Controller_B.Constant_m;
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
      Controller_DW.DiscreteTimeIntegrator5_IC_LO_g = 1U;
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

      Controller_DW.DiscreteTimeIntegrator_PrevR_ef = 0;
      Controller_DW.Integrator_DSTATE_f = 0.0F;

      /* End of InitializeConditions for SubSystem: '<S2>/FW_Controller' */
    }

    /* Outputs for IfAction SubSystem: '<S2>/FW_Controller' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* SignalConversion: '<S56>/TmpSignal ConversionAtMultiplyInport2' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_TmpSignalConversionAtMult_0 = Controller_U.INS_Out.vn;
    rtb_TmpSignalConversionAtMult_1 = Controller_U.INS_Out.ve;
    rtb_TmpSignalConversionAtMult_2 = Controller_U.INS_Out.vd;

    /* Trigonometry: '<S92>/Trigonometric Function1' incorporates:
     *  Gain: '<S91>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S92>/Trigonometric Function3'
     */
    rtb_Square_d = arm_cos_f32(-Controller_U.INS_Out.psi);
    rtb_VectorConcatenate_o[0] = rtb_Square_d;

    /* Trigonometry: '<S92>/Trigonometric Function' incorporates:
     *  Gain: '<S91>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S92>/Trigonometric Function2'
     */
    rtb_Gain_c4 = arm_sin_f32(-Controller_U.INS_Out.psi);
    rtb_VectorConcatenate_o[1] = rtb_Gain_c4;

    /* SignalConversion: '<S92>/ConcatBufferAtVector Concatenate1In3' incorporates:
     *  Constant: '<S92>/Constant3'
     */
    rtb_VectorConcatenate_o[2] = 0.0F;

    /* Gain: '<S92>/Gain' */
    rtb_VectorConcatenate_o[3] = -rtb_Gain_c4;

    /* Trigonometry: '<S92>/Trigonometric Function3' */
    rtb_VectorConcatenate_o[4] = rtb_Square_d;

    /* SignalConversion: '<S92>/ConcatBufferAtVector Concatenate2In3' incorporates:
     *  Constant: '<S92>/Constant4'
     */
    rtb_VectorConcatenate_o[5] = 0.0F;

    /* SignalConversion: '<S92>/ConcatBufferAtVector ConcatenateIn3' */
    rtb_VectorConcatenate_o[6] = Controller_ConstB.VectorConcatenate3_g[0];
    rtb_VectorConcatenate_o[7] = Controller_ConstB.VectorConcatenate3_g[1];
    rtb_VectorConcatenate_o[8] = Controller_ConstB.VectorConcatenate3_g[2];

    /* Product: '<S89>/Multiply' */
    for (rtb_Relay = 0; rtb_Relay < 3; rtb_Relay++) {
      rtb_DiscreteTimeIntegrator1_k1[rtb_Relay] =
        rtb_VectorConcatenate_o[rtb_Relay + 6] * rtb_TmpSignalConversionAtMult_2
        + (rtb_VectorConcatenate_o[rtb_Relay + 3] *
           rtb_TmpSignalConversionAtMult_1 + rtb_VectorConcatenate_o[rtb_Relay] *
           rtb_TmpSignalConversionAtMult_0);
    }

    /* End of Product: '<S89>/Multiply' */

    /* Relay: '<S54>/Relay' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    if (Controller_U.INS_Out.airspeed >= 10.0F) {
      Controller_DW.Relay_Mode = true;
    } else {
      if (Controller_U.INS_Out.airspeed <= 6.0F) {
        Controller_DW.Relay_Mode = false;
      }
    }

    /* Switch: '<S54>/Switch' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Logic: '<S54>/Logical Operator'
     *  Math: '<S54>/Square2'
     *  Math: '<S54>/Square3'
     *  Product: '<S54>/Multiply'
     *  Relay: '<S54>/Relay'
     *  S-Function (sfix_bitop): '<S54>/Bitwise AND'
     *  Sqrt: '<S54>/Sqrt'
     *  Sum: '<S54>/Add'
     */
    if (Controller_DW.Relay_Mode && ((Controller_U.INS_Out.flag & 512U) != 0U))
    {
      rtb_Divide_m_idx_0 = Controller_U.INS_Out.airspeed;
    } else {
      /* Sqrt: '<S62>/Sqrt' incorporates:
       *  Math: '<S62>/Square'
       *  Sum: '<S62>/Sum of Elements'
       */
      rtb_Square_d = sqrtf(((Controller_U.INS_Out.quat[0] *
        Controller_U.INS_Out.quat[0] + Controller_U.INS_Out.quat[1] *
        Controller_U.INS_Out.quat[1]) + Controller_U.INS_Out.quat[2] *
                            Controller_U.INS_Out.quat[2]) +
                           Controller_U.INS_Out.quat[3] *
                           Controller_U.INS_Out.quat[3]);

      /* Product: '<S58>/Divide' */
      rtb_Divide_m_idx_0 = Controller_U.INS_Out.quat[0] / rtb_Square_d;
      rtb_Divide_m_idx_1 = Controller_U.INS_Out.quat[1] / rtb_Square_d;
      rtb_Divide_m_idx_2 = Controller_U.INS_Out.quat[2] / rtb_Square_d;
      rtb_Divide_m_idx_3 = Controller_U.INS_Out.quat[3] / rtb_Square_d;

      /* Math: '<S61>/Square' incorporates:
       *  Math: '<S59>/Square'
       *  Math: '<S60>/Square'
       */
      rtb_Square_d = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_0;

      /* Math: '<S61>/Square2' incorporates:
       *  Math: '<S59>/Square2'
       *  Math: '<S60>/Square2'
       */
      rtb_Gain_c4 = rtb_Divide_m_idx_2 * rtb_Divide_m_idx_2;

      /* Math: '<S61>/Square1' incorporates:
       *  Math: '<S59>/Square1'
       *  Math: '<S60>/Square1'
       */
      rtb_Add3_fc = rtb_Divide_m_idx_1 * rtb_Divide_m_idx_1;

      /* Math: '<S61>/Square3' incorporates:
       *  Math: '<S59>/Square3'
       *  Math: '<S60>/Square3'
       */
      rtb_aux_att_error_B_rad_idx_0 = rtb_Divide_m_idx_3 * rtb_Divide_m_idx_3;

      /* Sum: '<S61>/Subtract' incorporates:
       *  Math: '<S61>/Square'
       *  Math: '<S61>/Square1'
       *  Math: '<S61>/Square2'
       *  Math: '<S61>/Square3'
       *  Sum: '<S61>/Add'
       *  Sum: '<S61>/Add1'
       */
      rtb_VectorConcatenate_o[8] = (rtb_Square_d + rtb_aux_att_error_B_rad_idx_0)
        - (rtb_Add3_fc + rtb_Gain_c4);

      /* Product: '<S61>/Multiply2' incorporates:
       *  Product: '<S60>/Multiply2'
       */
      rtb_aux_att_error_B_rad_idx_1 = rtb_Divide_m_idx_2 * rtb_Divide_m_idx_3;

      /* Product: '<S61>/Multiply3' incorporates:
       *  Product: '<S60>/Multiply3'
       */
      rtb_Saturation_j_idx_0 = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_1;

      /* Gain: '<S61>/Gain1' incorporates:
       *  Product: '<S61>/Multiply2'
       *  Product: '<S61>/Multiply3'
       *  Sum: '<S61>/Add2'
       */
      rtb_VectorConcatenate_o[7] = (rtb_aux_att_error_B_rad_idx_1 +
        rtb_Saturation_j_idx_0) * 2.0F;

      /* Product: '<S61>/Multiply' incorporates:
       *  Product: '<S59>/Multiply2'
       */
      rtb_Saturation_g = rtb_Divide_m_idx_1 * rtb_Divide_m_idx_3;

      /* Product: '<S61>/Multiply1' incorporates:
       *  Product: '<S59>/Multiply3'
       */
      rtb_phi_cmd = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_2;

      /* Gain: '<S61>/Gain' incorporates:
       *  Product: '<S61>/Multiply'
       *  Product: '<S61>/Multiply1'
       *  Sum: '<S61>/Subtract2'
       */
      rtb_VectorConcatenate_o[6] = (rtb_Saturation_g - rtb_phi_cmd) * 2.0F;

      /* Gain: '<S60>/Gain1' incorporates:
       *  Sum: '<S60>/Subtract1'
       */
      rtb_VectorConcatenate_o[5] = (rtb_aux_att_error_B_rad_idx_1 -
        rtb_Saturation_j_idx_0) * 2.0F;

      /* Sum: '<S60>/Subtract' incorporates:
       *  Sum: '<S60>/Add'
       *  Sum: '<S60>/Add1'
       */
      rtb_VectorConcatenate_o[4] = (rtb_Square_d + rtb_Gain_c4) - (rtb_Add3_fc +
        rtb_aux_att_error_B_rad_idx_0);

      /* Product: '<S60>/Multiply' incorporates:
       *  Product: '<S59>/Multiply'
       */
      rtb_aux_att_error_B_rad_idx_1 = rtb_Divide_m_idx_1 * rtb_Divide_m_idx_2;

      /* Product: '<S60>/Multiply1' incorporates:
       *  Product: '<S59>/Multiply1'
       */
      rtb_Saturation_j_idx_0 = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_3;

      /* Gain: '<S60>/Gain' incorporates:
       *  Product: '<S60>/Multiply'
       *  Product: '<S60>/Multiply1'
       *  Sum: '<S60>/Add3'
       */
      rtb_VectorConcatenate_o[3] = (rtb_aux_att_error_B_rad_idx_1 +
        rtb_Saturation_j_idx_0) * 2.0F;

      /* Gain: '<S59>/Gain1' incorporates:
       *  Sum: '<S59>/Add2'
       */
      rtb_VectorConcatenate_o[2] = (rtb_Saturation_g + rtb_phi_cmd) * 2.0F;

      /* Gain: '<S59>/Gain' incorporates:
       *  Sum: '<S59>/Subtract1'
       */
      rtb_VectorConcatenate_o[1] = (rtb_aux_att_error_B_rad_idx_1 -
        rtb_Saturation_j_idx_0) * 2.0F;

      /* Sum: '<S59>/Subtract' incorporates:
       *  Sum: '<S59>/Add'
       *  Sum: '<S59>/Add1'
       */
      rtb_VectorConcatenate_o[0] = (rtb_Square_d + rtb_Add3_fc) - (rtb_Gain_c4 +
        rtb_aux_att_error_B_rad_idx_0);

      /* Product: '<S56>/Multiply' */
      for (rtb_Relay = 0; rtb_Relay < 3; rtb_Relay++) {
        rtb_VectorConcatenate_k[rtb_Relay] = rtb_VectorConcatenate_o[rtb_Relay +
          6] * rtb_TmpSignalConversionAtMult_2 +
          (rtb_VectorConcatenate_o[rtb_Relay + 3] *
           rtb_TmpSignalConversionAtMult_1 + rtb_VectorConcatenate_o[rtb_Relay] *
           rtb_TmpSignalConversionAtMult_0);
      }

      /* End of Product: '<S56>/Multiply' */

      /* Signum: '<S56>/Sign' */
      if (rtb_VectorConcatenate_k[0] < 0.0F) {
        rtb_TmpSignalConversionAtMult_0 = -1.0F;
      } else if (rtb_VectorConcatenate_k[0] > 0.0F) {
        rtb_TmpSignalConversionAtMult_0 = 1.0F;
      } else {
        rtb_TmpSignalConversionAtMult_0 = rtb_VectorConcatenate_k[0];
      }

      /* End of Signum: '<S56>/Sign' */
      rtb_Divide_m_idx_0 = sqrtf(Controller_U.INS_Out.vn *
        Controller_U.INS_Out.vn + Controller_U.INS_Out.ve *
        Controller_U.INS_Out.ve) * rtb_TmpSignalConversionAtMult_0;
    }

    /* End of Switch: '<S54>/Switch' */

    /* Saturate: '<S54>/Saturation1' */
    if (rtb_Divide_m_idx_0 > 100.0F) {
      rtb_Divide_m_idx_0 = 100.0F;
    } else {
      if (rtb_Divide_m_idx_0 < 0.1F) {
        rtb_Divide_m_idx_0 = 0.1F;
      }
    }

    /* End of Saturate: '<S54>/Saturation1' */

    /* DiscreteIntegrator: '<S55>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_e != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j = rtb_Divide_m_idx_0;
    }

    /* Math: '<S10>/Square' incorporates:
     *  DiscreteIntegrator: '<S55>/Discrete-Time Integrator5'
     *  Math: '<S71>/Square1'
     *  Switch: '<S12>/Switch'
     */
    rtb_Saturation_g = Controller_DW.DiscreteTimeIntegrator5_DSTAT_j *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;

    /* Product: '<S10>/Divide' incorporates:
     *  Math: '<S10>/Square'
     */
    rtb_Divide_m_idx_1 = rtb_Saturation_g / Controller_ConstB.Square1;

    /* DiscreteIntegrator: '<S53>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_L_eo != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_a = rtb_Divide_m_idx_1;
    }

    /* Saturate: '<S10>/Saturation' */
    if (Controller_DW.DiscreteTimeIntegrator5_DSTAT_a > 1.0F) {
      rtb_Divide_m_idx_2 = 1.0F;
    } else if (Controller_DW.DiscreteTimeIntegrator5_DSTAT_a < 0.0F) {
      rtb_Divide_m_idx_2 = 0.0F;
    } else {
      rtb_Divide_m_idx_2 = Controller_DW.DiscreteTimeIntegrator5_DSTAT_a;
    }

    /* End of Saturate: '<S10>/Saturation' */

    /* Relay: '<S10>/Relay' */
    if (rtb_Divide_m_idx_2 >= 0.95F) {
      Controller_DW.Relay_Mode_m = true;
    } else {
      if (rtb_Divide_m_idx_2 <= 0.85F) {
        Controller_DW.Relay_Mode_m = false;
      }
    }

    rtb_Relay = !Controller_DW.Relay_Mode_m;

    /* End of Relay: '<S10>/Relay' */

    /* DiscreteIntegrator: '<S52>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_o != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTA_a2 = (real32_T)rtb_Relay;
    }

    /* Logic: '<S16>/Logical Operator' incorporates:
     *  Constant: '<S18>/Constant'
     *  DiscreteIntegrator: '<S52>/Discrete-Time Integrator5'
     *  RelationalOperator: '<S18>/Compare'
     */
    rtb_LogicalOperator_i = ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator5_DSTA_a2 == 0.0F));

    /* DiscreteIntegrator: '<S26>/Discrete-Time Integrator' */
    if (rtb_LogicalOperator_i || (Controller_DW.DiscreteTimeIntegrator_PrevRe_o
         != 0)) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_d[0] =
        Controller_ConstB.Constant_j[0];
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_d[0] >=
          CONTROL_PARAM.MC_RATE_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_d[0] =
          CONTROL_PARAM.MC_RATE_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_d[0] <=
            CONTROL_PARAM.MC_RATE_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_d[0] =
            CONTROL_PARAM.MC_RATE_I_MIN;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_DSTATE_d[1] =
        Controller_ConstB.Constant_j[1];
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_d[1] >=
          CONTROL_PARAM.MC_RATE_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_d[1] =
          CONTROL_PARAM.MC_RATE_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_d[1] <=
            CONTROL_PARAM.MC_RATE_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_d[1] =
            CONTROL_PARAM.MC_RATE_I_MIN;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_DSTATE_d[2] =
        Controller_ConstB.Constant_j[2];
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_d[2] >=
          CONTROL_PARAM.MC_RATE_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_d[2] =
          CONTROL_PARAM.MC_RATE_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_d[2] <=
            CONTROL_PARAM.MC_RATE_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_d[2] =
            CONTROL_PARAM.MC_RATE_I_MIN;
        }
      }
    }

    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_d[0] >=
        CONTROL_PARAM.MC_RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_d[0] =
        CONTROL_PARAM.MC_RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_d[0] <=
          CONTROL_PARAM.MC_RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_d[0] =
          CONTROL_PARAM.MC_RATE_I_MIN;
      }
    }

    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_d[1] >=
        CONTROL_PARAM.MC_RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_d[1] =
        CONTROL_PARAM.MC_RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_d[1] <=
          CONTROL_PARAM.MC_RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_d[1] =
          CONTROL_PARAM.MC_RATE_I_MIN;
      }
    }

    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_d[2] >=
        CONTROL_PARAM.MC_RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_d[2] =
        CONTROL_PARAM.MC_RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_d[2] <=
          CONTROL_PARAM.MC_RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_d[2] =
          CONTROL_PARAM.MC_RATE_I_MIN;
      }
    }

    /* Switch: '<S77>/Switch' incorporates:
     *  Logic: '<S77>/Logical Operator'
     *  RelationalOperator: '<S82>/Compare'
     */
    if ((rtb_BitwiseAND_n == 3) || (rtb_BitwiseAND_n == 4)) {
      rtb_phi_cmd = Controller_U.FMS_Out.phi_cmd;
    } else {
      /* Trigonometry: '<S64>/Atan' incorporates:
       *  Gain: '<S64>/g_force'
       */
      rtb_phi_cmd = atanf(0.101936802F * Controller_U.FMS_Out.ay_cmd);

      /* Saturate: '<S64>/Saturation' */
      if (rtb_phi_cmd > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_phi_cmd = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_phi_cmd < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
          rtb_phi_cmd = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
        }
      }

      /* End of Saturate: '<S64>/Saturation' */
    }

    /* End of Switch: '<S77>/Switch' */

    /* Abs: '<S65>/Abs' */
    rtb_Abs = fabsf(rtb_phi_cmd);

    /* DeadZone: '<S89>/Dead Zone' */
    if (rtb_DiscreteTimeIntegrator1_k1[0] > 1.0F) {
      rtb_Sum_l = rtb_DiscreteTimeIntegrator1_k1[0] - 1.0F;
    } else if (rtb_DiscreteTimeIntegrator1_k1[0] >= -1.0F) {
      rtb_Sum_l = 0.0F;
    } else {
      rtb_Sum_l = rtb_DiscreteTimeIntegrator1_k1[0] - -1.0F;
    }

    /* End of DeadZone: '<S89>/Dead Zone' */

    /* Signum: '<S89>/Sign' */
    if (rtb_Sum_l < 0.0F) {
      rtb_Sum_l = -1.0F;
    } else {
      if (rtb_Sum_l > 0.0F) {
        rtb_Sum_l = 1.0F;
      }
    }

    /* End of Signum: '<S89>/Sign' */

    /* Switch: '<S88>/Switch' incorporates:
     *  Gain: '<S88>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S88>/Divide'
     *  S-Function (sfix_bitop): '<S88>/Bitwise AND'
     *  Trigonometry: '<S88>/Asin'
     */
    if ((Controller_U.INS_Out.flag & 16U) > 1U) {
      /* Sqrt: '<S88>/Sqrt' incorporates:
       *  Math: '<S88>/Square'
       *  Math: '<S88>/Square1'
       *  Sum: '<S88>/Add'
       */
      rtb_Add3_fc = sqrtf(Controller_U.INS_Out.vn * Controller_U.INS_Out.vn +
                          Controller_U.INS_Out.ve * Controller_U.INS_Out.ve);

      /* Saturate: '<S88>/Saturation' incorporates:
       *  Sqrt: '<S88>/Sqrt'
       */
      if (rtb_Add3_fc > 100.0F) {
        rtb_Add3_fc = 100.0F;
      } else {
        if (rtb_Add3_fc < 8.0F) {
          rtb_Add3_fc = 8.0F;
        }
      }

      /* End of Saturate: '<S88>/Saturation' */

      /* DeadZone: '<S88>/Dead Zone' */
      if (Controller_U.INS_Out.vd > 0.1F) {
        rtb_Saturation_j_idx_1 = Controller_U.INS_Out.vd - 0.1F;
      } else if (Controller_U.INS_Out.vd >= -0.1F) {
        rtb_Saturation_j_idx_1 = 0.0F;
      } else {
        rtb_Saturation_j_idx_1 = Controller_U.INS_Out.vd - -0.1F;
      }

      /* End of DeadZone: '<S88>/Dead Zone' */
      rtb_DiscreteTimeIntegrator5_h5 = atanf(1.0F / rtb_Add3_fc *
        -rtb_Saturation_j_idx_1);
    } else {
      rtb_DiscreteTimeIntegrator5_h5 = Controller_U.INS_Out.theta;
    }

    /* End of Switch: '<S88>/Switch' */

    /* Product: '<S88>/Multiply1' */
    rtb_DiscreteTimeIntegrator5_h5 *= rtb_Sum_l;

    /* Saturate: '<S88>/Saturation1' */
    if (rtb_DiscreteTimeIntegrator5_h5 > 0.785398185F) {
      rtb_DiscreteTimeIntegrator5_h5 = 0.785398185F;
    } else {
      if (rtb_DiscreteTimeIntegrator5_h5 < -0.785398185F) {
        rtb_DiscreteTimeIntegrator5_h5 = -0.785398185F;
      }
    }

    /* End of Saturate: '<S88>/Saturation1' */

    /* DiscreteIntegrator: '<S99>/Discrete-Time Integrator5' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_n != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_f = Controller_U.INS_Out.ax;
    }

    /* Gain: '<S87>/Gain1' incorporates:
     *  DiscreteIntegrator: '<S99>/Discrete-Time Integrator5'
     */
    rtb_VdotPg = 0.101936802F * Controller_DW.DiscreteTimeIntegrator5_DSTAT_f;

    /* Sqrt: '<S90>/Sqrt' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Math: '<S90>/Square'
     *  Math: '<S90>/Square1'
     *  Sum: '<S90>/Add'
     */
    rtb_Add3_fc = sqrtf(Controller_U.INS_Out.vn * Controller_U.INS_Out.vn +
                        Controller_U.INS_Out.ve * Controller_U.INS_Out.ve);

    /* Saturate: '<S90>/Saturation1' incorporates:
     *  Sqrt: '<S90>/Sqrt'
     */
    if (rtb_Add3_fc > 100.0F) {
      rtb_Add3_fc = 100.0F;
    } else {
      if (rtb_Add3_fc < 8.0F) {
        rtb_Add3_fc = 8.0F;
      }
    }

    /* End of Saturate: '<S90>/Saturation1' */

    /* Product: '<S90>/Multiply1' incorporates:
     *  Gain: '<S90>/Gain'
     *  Product: '<S90>/Divide'
     *  Trigonometry: '<S90>/Asin'
     */
    rtb_Sum_l *= atanf(-Controller_U.FMS_Out.w_cmd / rtb_Add3_fc);

    /* Saturate: '<S90>/Saturation2' */
    if (rtb_Sum_l > 0.785398185F) {
      rtb_Sum_l = 0.785398185F;
    } else {
      if (rtb_Sum_l < -0.785398185F) {
        rtb_Sum_l = -0.785398185F;
      }
    }

    /* End of Saturate: '<S90>/Saturation2' */

    /* Sum: '<S84>/Sum' */
    rtb_Sum_l -= rtb_DiscreteTimeIntegrator5_h5;

    /* Sum: '<S87>/Sum' incorporates:
     *  DiscreteIntegrator: '<S55>/Discrete-Time Integrator5'
     *  Gain: '<S87>/Gain'
     *  Gain: '<S87>/Kv'
     *  Sum: '<S87>/Minus'
     */
    rtb_Cos_j = (Controller_U.FMS_Out.u_cmd -
                 Controller_DW.DiscreteTimeIntegrator5_DSTAT_j) *
      CONTROL_PARAM.FW_TECS_VEL_P * 0.101936802F - rtb_VdotPg;

    /* Sum: '<S65>/Minus1' incorporates:
     *  Gain: '<S65>/ucmd2pitch'
     *  Gain: '<S65>/wcmd2pitch'
     */
    rtb_Square_d = CONTROL_PARAM.FW_TECS_W2P * rtb_Sum_l -
      CONTROL_PARAM.FW_TECS_U2P * rtb_Cos_j;

    /* DiscreteIntegrator: '<S94>/ ' */
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

    /* DiscreteIntegrator: '<S95>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_f != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_e = rtb_Square_d;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_b != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_e = rtb_Square_d;
    }

    /* Gain: '<S95>/Gain' incorporates:
     *  DiscreteIntegrator: '<S95>/Discrete-Time Integrator1'
     *  Sum: '<S95>/Sum5'
     */
    rtb_Gain_c4 = (rtb_Square_d - Controller_DW.DiscreteTimeIntegrator1_DSTAT_e)
      * 62.831852F;

    /* Switch: '<S77>/Switch1' incorporates:
     *  Constant: '<S83>/Constant'
     *  DiscreteIntegrator: '<S94>/ '
     *  Gain: '<S65>/Gain'
     *  Gain: '<S65>/balabnce_ratio2'
     *  Gain: '<S65>/balance_ratio'
     *  Gain: '<S65>/pitch_ff'
     *  Gain: '<S85>/P_control'
     *  RelationalOperator: '<S83>/Compare'
     *  Sum: '<S65>/Add3'
     *  Sum: '<S65>/Minus'
     *  Sum: '<S65>/Sum'
     *  Sum: '<S85>/Add'
     *  Switch: '<S95>/Switch'
     */
    if (rtb_BitwiseAND_n == 3) {
      rtb_Multiply1_e = Controller_U.FMS_Out.theta_cmd;
    } else {
      if (Controller_U.FMS_Out.reset > 0) {
        /* Switch: '<S95>/Switch' incorporates:
         *  Gain: '<S95>/Gain1'
         */
        rtb_Saturation_j_idx_1 = 0.0F;
      } else {
        /* Switch: '<S95>/Switch' */
        rtb_Saturation_j_idx_1 = rtb_Gain_c4;
      }

      /* Gain: '<S93>/Gain' */
      rtb_TmpSignalConversionAtMult_0 = CONTROL_PARAM.FW_TECS_PITCH_D *
        rtb_Saturation_j_idx_1;

      /* Saturate: '<S85>/Saturation1' */
      if (rtb_TmpSignalConversionAtMult_0 > 0.3F) {
        rtb_TmpSignalConversionAtMult_0 = 0.3F;
      } else {
        if (rtb_TmpSignalConversionAtMult_0 < -0.3F) {
          rtb_TmpSignalConversionAtMult_0 = -0.3F;
        }
      }

      /* End of Saturate: '<S85>/Saturation1' */
      rtb_Multiply1_e = (((2.0F - CONTROL_PARAM.FW_TECS_RATIO) *
                          rtb_DiscreteTimeIntegrator5_h5 -
                          CONTROL_PARAM.FW_TECS_RATIO * rtb_VdotPg) *
                         CONTROL_PARAM.FW_TECS_PITCH_F +
                         ((CONTROL_PARAM.FW_TECS_PITCH_P * rtb_Square_d +
                           Controller_DW._DSTATE) +
                          rtb_TmpSignalConversionAtMult_0)) +
        CONTROL_PARAM.FW_TECS_R2P * rtb_Abs;
    }

    /* End of Switch: '<S77>/Switch1' */

    /* Sum: '<S31>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_aux_att_error_B_rad_idx_0 = rtb_phi_cmd - Controller_U.INS_Out.phi;
    rtb_aux_att_error_B_rad_idx_1 = rtb_Multiply1_e - Controller_U.INS_Out.theta;

    /* Product: '<S34>/Divide1' incorporates:
     *  Abs: '<S34>/Abs'
     *  Constant: '<S34>/const2'
     */
    rtb_TmpSignalConversionAtMult_2 = fabsf(rtb_aux_att_error_B_rad_idx_0) /
      0.002F;

    /* Product: '<S34>/Divide' incorporates:
     *  Constant: '<S32>/Constant1'
     *  Constant: '<S34>/const1'
     *  Math: '<S34>/Square'
     *  SignalConversion: '<S34>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_TmpSignalConversionAtMult_1 = 9.5993F / (CONTROL_PARAM.MC_ROLL_P *
      CONTROL_PARAM.MC_ROLL_P);

    /* Signum: '<S34>/Sign' incorporates:
     *  Abs: '<S34>/Abs'
     */
    if (rtb_aux_att_error_B_rad_idx_0 < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else if (rtb_aux_att_error_B_rad_idx_0 > 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_0 = rtb_aux_att_error_B_rad_idx_0;
    }

    /* Switch: '<S34>/Switch' incorporates:
     *  Abs: '<S34>/Abs'
     *  Constant: '<S32>/Constant1'
     *  Gain: '<S34>/Gain1'
     *  Gain: '<S34>/Gain2'
     *  Logic: '<S34>/Logical Operator'
     *  Product: '<S34>/Divide'
     *  Product: '<S34>/Multiply'
     *  Product: '<S34>/Multiply1'
     *  Product: '<S34>/Multiply2'
     *  Product: '<S34>/Multiply3'
     *  RelationalOperator: '<S34>/Relational Operator'
     *  RelationalOperator: '<S34>/Relational Operator2'
     *  SignalConversion: '<S34>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S34>/Sqrt'
     *  Sum: '<S34>/Subtract'
     */
    if ((rtb_aux_att_error_B_rad_idx_0 <= rtb_TmpSignalConversionAtMult_1) &&
        (rtb_aux_att_error_B_rad_idx_0 >= -rtb_TmpSignalConversionAtMult_1)) {
      rtb_TmpSignalConversionAtMult_0 = rtb_aux_att_error_B_rad_idx_0 *
        CONTROL_PARAM.MC_ROLL_P;
    } else {
      rtb_TmpSignalConversionAtMult_0 *= sqrtf((rtb_TmpSignalConversionAtMult_0 *
        rtb_aux_att_error_B_rad_idx_0 - 0.5F * rtb_TmpSignalConversionAtMult_1) *
        Controller_ConstB.Gain_n);
    }

    /* Gain: '<S34>/Gain3' */
    rtb_Saturation_j_idx_0 = -rtb_TmpSignalConversionAtMult_2;

    /* Switch: '<S35>/Switch' incorporates:
     *  Gain: '<S34>/Gain3'
     *  RelationalOperator: '<S35>/UpperRelop'
     */
    if (rtb_TmpSignalConversionAtMult_0 >= -rtb_TmpSignalConversionAtMult_2) {
      rtb_Saturation_j_idx_0 = rtb_TmpSignalConversionAtMult_0;
    }

    /* Switch: '<S35>/Switch2' incorporates:
     *  RelationalOperator: '<S35>/LowerRelop1'
     */
    if (rtb_TmpSignalConversionAtMult_0 <= rtb_TmpSignalConversionAtMult_2) {
      rtb_TmpSignalConversionAtMult_2 = rtb_Saturation_j_idx_0;
    }

    /* Saturate: '<S20>/Saturation1' */
    if (rtb_TmpSignalConversionAtMult_2 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_TmpSignalConversionAtMult_2 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_TmpSignalConversionAtMult_2 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_TmpSignalConversionAtMult_2 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    rtb_Divide_m_idx_3 = rtb_TmpSignalConversionAtMult_2;

    /* Product: '<S34>/Divide1' incorporates:
     *  Abs: '<S34>/Abs'
     *  Constant: '<S34>/const2'
     */
    rtb_TmpSignalConversionAtMult_2 = fabsf(rtb_aux_att_error_B_rad_idx_1) /
      0.002F;

    /* Product: '<S34>/Divide' incorporates:
     *  Constant: '<S32>/Constant2'
     *  Constant: '<S34>/const1'
     *  Math: '<S34>/Square'
     *  SignalConversion: '<S34>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_TmpSignalConversionAtMult_1 = 9.5993F / (CONTROL_PARAM.MC_PITCH_P *
      CONTROL_PARAM.MC_PITCH_P);

    /* Signum: '<S34>/Sign' incorporates:
     *  Abs: '<S34>/Abs'
     */
    if (rtb_aux_att_error_B_rad_idx_1 < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else if (rtb_aux_att_error_B_rad_idx_1 > 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_0 = rtb_aux_att_error_B_rad_idx_1;
    }

    /* Switch: '<S34>/Switch' incorporates:
     *  Abs: '<S34>/Abs'
     *  Constant: '<S32>/Constant2'
     *  Gain: '<S34>/Gain1'
     *  Gain: '<S34>/Gain2'
     *  Logic: '<S34>/Logical Operator'
     *  Product: '<S34>/Divide'
     *  Product: '<S34>/Multiply'
     *  Product: '<S34>/Multiply1'
     *  Product: '<S34>/Multiply2'
     *  Product: '<S34>/Multiply3'
     *  RelationalOperator: '<S34>/Relational Operator'
     *  RelationalOperator: '<S34>/Relational Operator2'
     *  SignalConversion: '<S34>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S34>/Sqrt'
     *  Sum: '<S34>/Subtract'
     */
    if ((rtb_aux_att_error_B_rad_idx_1 <= rtb_TmpSignalConversionAtMult_1) &&
        (rtb_aux_att_error_B_rad_idx_1 >= -rtb_TmpSignalConversionAtMult_1)) {
      rtb_TmpSignalConversionAtMult_0 = rtb_aux_att_error_B_rad_idx_1 *
        CONTROL_PARAM.MC_PITCH_P;
    } else {
      rtb_TmpSignalConversionAtMult_0 *= sqrtf((rtb_TmpSignalConversionAtMult_0 *
        rtb_aux_att_error_B_rad_idx_1 - 0.5F * rtb_TmpSignalConversionAtMult_1) *
        Controller_ConstB.Gain_n);
    }

    /* Gain: '<S34>/Gain3' */
    rtb_Saturation_j_idx_0 = -rtb_TmpSignalConversionAtMult_2;

    /* Switch: '<S35>/Switch' incorporates:
     *  Gain: '<S34>/Gain3'
     *  RelationalOperator: '<S35>/UpperRelop'
     */
    if (rtb_TmpSignalConversionAtMult_0 >= -rtb_TmpSignalConversionAtMult_2) {
      rtb_Saturation_j_idx_0 = rtb_TmpSignalConversionAtMult_0;
    }

    /* Switch: '<S35>/Switch2' incorporates:
     *  RelationalOperator: '<S35>/LowerRelop1'
     */
    if (rtb_TmpSignalConversionAtMult_0 <= rtb_TmpSignalConversionAtMult_2) {
      rtb_TmpSignalConversionAtMult_2 = rtb_Saturation_j_idx_0;
    }

    /* Saturate: '<S20>/Saturation1' */
    if (rtb_TmpSignalConversionAtMult_2 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_TmpSignalConversionAtMult_2 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_TmpSignalConversionAtMult_2 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_TmpSignalConversionAtMult_2 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    /* Saturate: '<S20>/Saturation' */
    if (Controller_U.FMS_Out.psi_rate_cmd > CONTROL_PARAM.MC_R_CMD_LIM) {
      rtb_Add3_fc = CONTROL_PARAM.MC_R_CMD_LIM;
    } else if (Controller_U.FMS_Out.psi_rate_cmd < -CONTROL_PARAM.MC_R_CMD_LIM)
    {
      rtb_Add3_fc = -CONTROL_PARAM.MC_R_CMD_LIM;
    } else {
      rtb_Add3_fc = Controller_U.FMS_Out.psi_rate_cmd;
    }

    /* End of Saturate: '<S20>/Saturation' */

    /* Trigonometry: '<S29>/Sin' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S69>/Sin'
     */
    rtb_aux_att_error_B_rad_idx_1 = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S29>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S69>/Cos1'
     */
    rtb_DiscreteTimeIntegrator1_a_t = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Trigonometry: '<S29>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S69>/Cos'
     */
    rtb_Integrator1_o_tmp = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S29>/Sin1' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S69>/Sin1'
     */
    rtb_TmpSignalConversionAtMult_3 = arm_sin_f32(Controller_U.INS_Out.theta);

    /* Sum: '<S21>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S29>/Multiply'
     *  Product: '<S29>/Multiply1'
     *  Product: '<S29>/Multiply3'
     *  Product: '<S29>/Multiply4'
     *  Product: '<S29>/Multiply5'
     *  Sum: '<S29>/Add'
     *  Sum: '<S29>/Add1'
     *  Sum: '<S29>/Add2'
     *  Trigonometry: '<S29>/Cos'
     *  Trigonometry: '<S29>/Cos1'
     *  Trigonometry: '<S29>/Sin'
     *  Trigonometry: '<S29>/Sin1'
     */
    rtb_TmpSignalConversionAtMult_0 = (rtb_Divide_m_idx_3 -
      rtb_TmpSignalConversionAtMult_3 * rtb_Add3_fc) - Controller_U.INS_Out.p;
    rtb_TmpSignalConversionAtMult_1 = (rtb_aux_att_error_B_rad_idx_1 *
      rtb_DiscreteTimeIntegrator1_a_t * rtb_Add3_fc + rtb_Integrator1_o_tmp *
      rtb_TmpSignalConversionAtMult_2) - Controller_U.INS_Out.q;
    rtb_TmpSignalConversionAtMult_2 = (rtb_Integrator1_o_tmp *
      rtb_DiscreteTimeIntegrator1_a_t * rtb_Add3_fc -
      rtb_aux_att_error_B_rad_idx_1 * rtb_TmpSignalConversionAtMult_2) -
      Controller_U.INS_Out.r;

    /* DiscreteIntegrator: '<S24>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_b != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0] =
        rtb_TmpSignalConversionAtMult_0;
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1] =
        rtb_TmpSignalConversionAtMult_1;
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2] =
        rtb_TmpSignalConversionAtMult_2;
    }

    /* DiscreteIntegrator: '<S28>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S24>/Discrete-Time Integrator5'
     */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_h != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[0] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0];
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[1] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1];
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[2] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2];
    }

    if (rtb_LogicalOperator_i || (Controller_DW.DiscreteTimeIntegrator1_PrevR_l
         != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[0] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0];
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[1] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1];
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[2] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2];
    }

    /* Gain: '<S28>/Gain' incorporates:
     *  DiscreteIntegrator: '<S24>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S28>/Discrete-Time Integrator1'
     *  Sum: '<S28>/Sum5'
     */
    rtb_DiscreteTimeIntegrator1_k1[0] =
      (Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0] -
       Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[0]) * 188.49556F;
    rtb_DiscreteTimeIntegrator1_k1[1] =
      (Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1] -
       Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[1]) * 188.49556F;
    rtb_DiscreteTimeIntegrator1_k1[2] =
      (Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2] -
       Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[2]) * 188.49556F;

    /* RelationalOperator: '<S102>/Compare' incorporates:
     *  Constant: '<S102>/Constant'
     */
    rtb_Compare_nq = (rtb_BitwiseAND_n == 1);

    /* Switch: '<S12>/Switch' incorporates:
     *  Product: '<S25>/Multiply'
     *  Switch: '<S28>/Switch'
     */
    if (rtb_Compare_nq) {
      Controller_B.mc_torque_cmd[0] = 0.0F;
      Controller_B.mc_torque_cmd[1] = 0.0F;
      Controller_B.mc_torque_cmd[2] = 0.0F;
    } else {
      if (rtb_LogicalOperator_i) {
        /* Switch: '<S28>/Switch' incorporates:
         *  Gain: '<S28>/Gain1'
         */
        rtb_Saturation_j_idx_0 = 0.0F;
        rtb_Saturation_j_idx_1 = 0.0F;
        rtb_Saturation_j_idx_2 = 0.0F;
      } else {
        /* Switch: '<S28>/Switch' */
        rtb_Saturation_j_idx_0 = rtb_DiscreteTimeIntegrator1_k1[0];
        rtb_Saturation_j_idx_1 = rtb_DiscreteTimeIntegrator1_k1[1];
        rtb_Saturation_j_idx_2 = rtb_DiscreteTimeIntegrator1_k1[2];
      }

      /* Product: '<S25>/Multiply' incorporates:
       *  Constant: '<S25>/gain1'
       */
      rtb_Saturation_ni = CONTROL_PARAM.MC_ROLL_RATE_D * rtb_Saturation_j_idx_0;

      /* Saturate: '<S25>/Saturation' */
      if (rtb_Saturation_ni > CONTROL_PARAM.MC_RATE_D_MAX) {
        rtb_Saturation_ni = CONTROL_PARAM.MC_RATE_D_MAX;
      } else {
        if (rtb_Saturation_ni < CONTROL_PARAM.MC_RATE_D_MIN) {
          rtb_Saturation_ni = CONTROL_PARAM.MC_RATE_D_MIN;
        }
      }

      rtb_Saturation_j_idx_0 = rtb_Saturation_ni;

      /* Product: '<S25>/Multiply' incorporates:
       *  Constant: '<S25>/gain2'
       */
      rtb_Saturation_ni = CONTROL_PARAM.MC_PITCH_RATE_D * rtb_Saturation_j_idx_1;

      /* Saturate: '<S25>/Saturation' */
      if (rtb_Saturation_ni > CONTROL_PARAM.MC_RATE_D_MAX) {
        rtb_Saturation_ni = CONTROL_PARAM.MC_RATE_D_MAX;
      } else {
        if (rtb_Saturation_ni < CONTROL_PARAM.MC_RATE_D_MIN) {
          rtb_Saturation_ni = CONTROL_PARAM.MC_RATE_D_MIN;
        }
      }

      rtb_Saturation_j_idx_1 = rtb_Saturation_ni;

      /* Product: '<S25>/Multiply' incorporates:
       *  Constant: '<S25>/gain3'
       */
      rtb_Saturation_ni = CONTROL_PARAM.MC_YAW_RATE_D * rtb_Saturation_j_idx_2;

      /* Saturate: '<S25>/Saturation' */
      if (rtb_Saturation_ni > CONTROL_PARAM.MC_RATE_D_MAX) {
        rtb_Saturation_ni = CONTROL_PARAM.MC_RATE_D_MAX;
      } else {
        if (rtb_Saturation_ni < CONTROL_PARAM.MC_RATE_D_MIN) {
          rtb_Saturation_ni = CONTROL_PARAM.MC_RATE_D_MIN;
        }
      }

      /* Product: '<S9>/Multiply2' incorporates:
       *  Constant: '<S27>/gain1'
       *  DiscreteIntegrator: '<S24>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S26>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S52>/Discrete-Time Integrator5'
       *  Product: '<S27>/Multiply'
       *  Sum: '<S22>/Add'
       */
      rtb_Add3_fc = ((CONTROL_PARAM.MC_ROLL_RATE_P *
                      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0] +
                      Controller_DW.DiscreteTimeIntegrator_DSTATE_d[0]) +
                     rtb_Saturation_j_idx_0) *
        Controller_DW.DiscreteTimeIntegrator5_DSTA_a2;

      /* Saturate: '<S9>/Saturation2' */
      if (rtb_Add3_fc > 1.0F) {
        Controller_B.mc_torque_cmd[0] = 1.0F;
      } else if (rtb_Add3_fc < -1.0F) {
        Controller_B.mc_torque_cmd[0] = -1.0F;
      } else {
        Controller_B.mc_torque_cmd[0] = rtb_Add3_fc;
      }

      /* Product: '<S9>/Multiply2' incorporates:
       *  Constant: '<S27>/gain2'
       *  DiscreteIntegrator: '<S24>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S26>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S52>/Discrete-Time Integrator5'
       *  Product: '<S27>/Multiply'
       *  Sum: '<S22>/Add'
       */
      rtb_Add3_fc = ((CONTROL_PARAM.MC_PITCH_RATE_P *
                      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1] +
                      Controller_DW.DiscreteTimeIntegrator_DSTATE_d[1]) +
                     rtb_Saturation_j_idx_1) *
        Controller_DW.DiscreteTimeIntegrator5_DSTA_a2;

      /* Saturate: '<S9>/Saturation2' */
      if (rtb_Add3_fc > 1.0F) {
        Controller_B.mc_torque_cmd[1] = 1.0F;
      } else if (rtb_Add3_fc < -1.0F) {
        Controller_B.mc_torque_cmd[1] = -1.0F;
      } else {
        Controller_B.mc_torque_cmd[1] = rtb_Add3_fc;
      }

      /* Product: '<S9>/Multiply2' incorporates:
       *  Constant: '<S27>/gain3'
       *  DiscreteIntegrator: '<S24>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S26>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S52>/Discrete-Time Integrator5'
       *  Product: '<S27>/Multiply'
       *  Sum: '<S22>/Add'
       */
      rtb_Add3_fc = ((CONTROL_PARAM.MC_YAW_RATE_P *
                      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2] +
                      Controller_DW.DiscreteTimeIntegrator_DSTATE_d[2]) +
                     rtb_Saturation_ni) *
        Controller_DW.DiscreteTimeIntegrator5_DSTA_a2;

      /* Saturate: '<S9>/Saturation2' */
      if (rtb_Add3_fc > 1.0F) {
        Controller_B.mc_torque_cmd[2] = 1.0F;
      } else if (rtb_Add3_fc < -1.0F) {
        Controller_B.mc_torque_cmd[2] = -1.0F;
      } else {
        Controller_B.mc_torque_cmd[2] = rtb_Add3_fc;
      }
    }

    /* Sum: '<S65>/Add' incorporates:
     *  Gain: '<S65>/ucmd2thor'
     *  Gain: '<S65>/wcmd2thor'
     */
    rtb_Divide_m_idx_3 = CONTROL_PARAM.FW_TECS_W2T * rtb_Sum_l +
      CONTROL_PARAM.FW_TECS_U2T * rtb_Cos_j;

    /* DiscreteIntegrator: '<S97>/ ' */
    if ((Controller_U.FMS_Out.reset != 0) || (Controller_DW._PrevResetState_e !=
         0)) {
      Controller_DW._DSTATE_d = Controller_ConstB.Zero;
      if (Controller_DW._DSTATE_d >= 1.0F) {
        Controller_DW._DSTATE_d = 1.0F;
      } else {
        if (Controller_DW._DSTATE_d <= 0.0F) {
          Controller_DW._DSTATE_d = 0.0F;
        }
      }
    }

    if (Controller_DW._DSTATE_d >= 1.0F) {
      Controller_DW._DSTATE_d = 1.0F;
    } else {
      if (Controller_DW._DSTATE_d <= 0.0F) {
        Controller_DW._DSTATE_d = 0.0F;
      }
    }

    /* DiscreteIntegrator: '<S98>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_L_h0 != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm = rtb_Divide_m_idx_3;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_d != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm = rtb_Divide_m_idx_3;
    }

    /* Gain: '<S98>/Gain' incorporates:
     *  DiscreteIntegrator: '<S98>/Discrete-Time Integrator1'
     *  Sum: '<S98>/Sum5'
     */
    rtb_aux_att_error_B_rad_idx_0 = (rtb_Divide_m_idx_3 -
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm) * 188.49556F;

    /* Switch: '<S12>/Switch' incorporates:
     *  Constant: '<S101>/Constant'
     *  Constant: '<S103>/Constant2'
     *  Constant: '<S66>/Constant'
     *  RelationalOperator: '<S101>/Compare'
     *  Saturate: '<S66>/Saturation2'
     *  Switch: '<S66>/Switch'
     *  Switch: '<S98>/Switch'
     */
    if (rtb_Compare_nq) {
      Controller_B.fw_force_cmd[0] = Controller_U.FMS_Out.u_cmd;
      Controller_B.fw_force_cmd[1] = 0.0F;
      Controller_B.fw_force_cmd[2] = 0.0F;
    } else {
      if (rtb_BitwiseAND_n <= 3) {
        /* Switch: '<S66>/Switch' incorporates:
         *  Bias: '<S66>/Bias'
         *  Gain: '<S66>/Gain'
         */
        rtb_Add3_fc = 0.000999987125F * (real32_T)
          Controller_U.FMS_Out.throttle_cmd + -1.0F;
      } else {
        if (Controller_U.FMS_Out.reset > 0) {
          /* Switch: '<S98>/Switch' incorporates:
           *  Gain: '<S98>/Gain1'
           *  Switch: '<S66>/Switch'
           */
          rtb_Saturation_j_idx_1 = 0.0F;
        } else {
          /* Switch: '<S98>/Switch' incorporates:
           *  Switch: '<S66>/Switch'
           */
          rtb_Saturation_j_idx_1 = rtb_aux_att_error_B_rad_idx_0;
        }

        /* Gain: '<S96>/Gain' incorporates:
         *  Switch: '<S66>/Switch'
         */
        rtb_Add3_fc = CONTROL_PARAM.FW_TECS_THOR_D * rtb_Saturation_j_idx_1;

        /* Saturate: '<S86>/Saturation1' incorporates:
         *  Switch: '<S66>/Switch'
         */
        if (rtb_Add3_fc > 0.3F) {
          rtb_Add3_fc = 0.3F;
        } else {
          if (rtb_Add3_fc < -0.3F) {
            rtb_Add3_fc = -0.3F;
          }
        }

        /* End of Saturate: '<S86>/Saturation1' */

        /* Sum: '<S65>/Sum1' incorporates:
         *  DiscreteIntegrator: '<S97>/ '
         *  Gain: '<S65>/Gain1'
         *  Gain: '<S65>/thorttle_ff'
         *  Gain: '<S86>/P_control'
         *  Sum: '<S65>/Add1'
         *  Sum: '<S65>/Add2'
         *  Sum: '<S86>/Add4'
         *  Switch: '<S66>/Switch'
         */
        rtb_Add3_fc = (((CONTROL_PARAM.FW_TECS_THOR_P * rtb_Divide_m_idx_3 +
                         Controller_DW._DSTATE_d) + rtb_Add3_fc) +
                       (rtb_DiscreteTimeIntegrator5_h5 + rtb_VdotPg) *
                       CONTROL_PARAM.FW_TECS_THOR_FF) +
          CONTROL_PARAM.FW_TECS_R2T * rtb_Abs;

        /* Saturate: '<S66>/Saturation' incorporates:
         *  Switch: '<S66>/Switch'
         */
        if (rtb_Add3_fc > 1.0F) {
          rtb_Add3_fc = 1.0F;
        } else {
          if (rtb_Add3_fc < -1.0F) {
            rtb_Add3_fc = -1.0F;
          }
        }

        /* End of Saturate: '<S66>/Saturation' */
      }

      /* Saturate: '<S66>/Saturation2' incorporates:
       *  Switch: '<S66>/Switch'
       *  Switch: '<S98>/Switch'
       */
      if (rtb_Add3_fc > 1.0F) {
        Controller_B.fw_force_cmd[0] = 1.0F;
      } else {
        Controller_B.fw_force_cmd[0] = rtb_Add3_fc;
      }

      Controller_B.fw_force_cmd[1] = 0.0F;
      Controller_B.fw_force_cmd[2] = 0.0F;
    }

    /* Gain: '<S43>/Gain' incorporates:
     *  DiscreteIntegrator: '<S45>/Integrator1'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S43>/Sum1'
     */
    rtb_Abs = -(Controller_DW.Integrator1_DSTATE_i - Controller_U.INS_Out.vd);

    /* Logic: '<S40>/Logical Operator' incorporates:
     *  Constant: '<S42>/Constant'
     *  DiscreteIntegrator: '<S52>/Discrete-Time Integrator5'
     *  RelationalOperator: '<S42>/Compare'
     */
    rtb_LogicalOperator_g = ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator5_DSTA_a2 == 0.0F));
    Controller_B.Constant_m = CONTROL_PARAM.MC_VEL_Z_I_MIN;

    /* DiscreteIntegrator: '<S48>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S48>/Constant'
     */
    if (rtb_LogicalOperator_g || (Controller_DW.DiscreteTimeIntegrator_PrevRe_e
         != 0)) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_b = Controller_B.Constant_m;
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

    /* DiscreteIntegrator: '<S50>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_i != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_l = rtb_Abs;
    }

    if (rtb_LogicalOperator_g || (Controller_DW.DiscreteTimeIntegrator1_PrevR_h
         != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_l = rtb_Abs;
    }

    /* Gain: '<S50>/Gain' incorporates:
     *  DiscreteIntegrator: '<S50>/Discrete-Time Integrator1'
     *  Sum: '<S50>/Sum5'
     */
    rtb_DiscreteTimeIntegrator5_h5 = (rtb_Abs -
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_l) * 62.831852F;

    /* Switch: '<S12>/Switch' incorporates:
     *  Constant: '<S15>/Constant'
     *  Product: '<S9>/Multiply1'
     *  Saturate: '<S9>/Saturation1'
     */
    if (rtb_Compare_nq) {
      Controller_B.mc_force_cmd[0] = 0.0F;
      Controller_B.mc_force_cmd[1] = 0.0F;
      Controller_B.mc_force_cmd[2] = 0.0F;
    } else {
      /* Product: '<S41>/Multiply' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S41>/Cos'
       *  Trigonometry: '<S41>/Cos1'
       */
      rtb_Saturation_j_idx_1 = arm_cos_f32(Controller_U.INS_Out.phi) *
        arm_cos_f32(Controller_U.INS_Out.theta);

      /* Gain: '<S41>/Gain' */
      rtb_Add3_fc = 2.0F * rtb_Saturation_j_idx_1;

      /* Saturate: '<S41>/Saturation1' */
      if (rtb_Saturation_j_idx_1 > 1.0F) {
        rtb_Saturation_j_idx_1 = 1.0F;
      } else {
        if (rtb_Saturation_j_idx_1 < 0.5F) {
          rtb_Saturation_j_idx_1 = 0.5F;
        }
      }

      /* End of Saturate: '<S41>/Saturation1' */

      /* Product: '<S41>/Divide' incorporates:
       *  Constant: '<S41>/Constant'
       */
      rtb_Saturation_j_idx_0 = 1.0F / rtb_Saturation_j_idx_1;

      /* Switch: '<S50>/Switch' incorporates:
       *  Gain: '<S50>/Gain1'
       */
      if (rtb_LogicalOperator_g) {
        rtb_Saturation_j_idx_1 = 0.0F;
      } else {
        rtb_Saturation_j_idx_1 = rtb_DiscreteTimeIntegrator5_h5;
      }

      /* End of Switch: '<S50>/Switch' */

      /* Product: '<S47>/Multiply' incorporates:
       *  Constant: '<S47>/kd'
       */
      rtb_Saturation_j_idx_1 *= CONTROL_PARAM.MC_VEL_Z_D;

      /* Saturate: '<S47>/Saturation' */
      if (rtb_Saturation_j_idx_1 > CONTROL_PARAM.MC_VEL_Z_D_MAX) {
        rtb_Saturation_j_idx_1 = CONTROL_PARAM.MC_VEL_Z_D_MAX;
      } else {
        if (rtb_Saturation_j_idx_1 < CONTROL_PARAM.MC_VEL_Z_D_MIN) {
          rtb_Saturation_j_idx_1 = CONTROL_PARAM.MC_VEL_Z_D_MIN;
        }
      }

      /* End of Saturate: '<S47>/Saturation' */

      /* Saturate: '<S41>/Saturation' */
      if (rtb_Add3_fc > 1.0F) {
        rtb_Add3_fc = 1.0F;
      } else {
        if (rtb_Add3_fc < 0.0F) {
          rtb_Add3_fc = 0.0F;
        }
      }

      /* End of Saturate: '<S41>/Saturation' */

      /* Product: '<S41>/Multiply1' incorporates:
       *  Constant: '<S49>/kp'
       *  DiscreteIntegrator: '<S48>/Discrete-Time Integrator'
       *  Product: '<S49>/Multiply'
       *  Sum: '<S44>/Add'
       */
      rtb_Add3_fc *= ((CONTROL_PARAM.MC_VEL_Z_P * rtb_Abs +
                       Controller_DW.DiscreteTimeIntegrator_DSTATE_b) +
                      rtb_Saturation_j_idx_1) * rtb_Saturation_j_idx_0;

      /* Saturate: '<S40>/Saturation' */
      if (rtb_Add3_fc > 0.35F) {
        rtb_Add3_fc = 0.35F;
      } else {
        if (rtb_Add3_fc < -0.35F) {
          rtb_Add3_fc = -0.35F;
        }
      }

      /* End of Saturate: '<S40>/Saturation' */

      /* Sum: '<S40>/Sum1' incorporates:
       *  Constant: '<S40>/hover_throttle'
       */
      rtb_Add3_fc += CONTROL_PARAM.MC_HOVER_THRO;
      Controller_B.mc_force_cmd[0] = 0.0F;
      Controller_B.mc_force_cmd[1] = 0.0F;

      /* Product: '<S9>/Multiply1' incorporates:
       *  Constant: '<S15>/Constant'
       *  DiscreteIntegrator: '<S52>/Discrete-Time Integrator5'
       *  Saturate: '<S9>/Saturation1'
       */
      rtb_Add3_fc *= Controller_DW.DiscreteTimeIntegrator5_DSTA_a2;

      /* Saturate: '<S9>/Saturation1' */
      if (rtb_Add3_fc > 1.0F) {
        Controller_B.mc_force_cmd[2] = 1.0F;
      } else if (rtb_Add3_fc < -1.0F) {
        Controller_B.mc_force_cmd[2] = -1.0F;
      } else {
        Controller_B.mc_force_cmd[2] = rtb_Add3_fc;
      }
    }

    /* DiscreteIntegrator: '<S51>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_g != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTA_jo = rtb_Divide_m_idx_2;
    }

    /* Bias: '<S78>/Pitch Offset' */
    rtb_Add3_fc = rtb_Multiply1_e + CONTROL_PARAM.FW_PITCH_OFFSET;

    /* Saturate: '<S78>/Saturation' */
    if (rtb_Add3_fc > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Add3_fc = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_Add3_fc < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_Add3_fc = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      }
    }

    /* Product: '<S79>/Multiply' incorporates:
     *  Constant: '<S79>/Constant2'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S78>/Sum'
     */
    rtb_Saturation_j_idx_1 = (rtb_Add3_fc - Controller_U.INS_Out.theta) *
      CONTROL_PARAM.FW_PITCH_P;

    /* Product: '<S81>/Divide' incorporates:
     *  Constant: '<S81>/Constant'
     *  DiscreteIntegrator: '<S55>/Discrete-Time Integrator5'
     */
    rtb_Add3_fc = 9.81F / Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;

    /* Saturate: '<S81>/Saturation' */
    if (rtb_Add3_fc > 1.0F) {
      rtb_Add3_fc = 1.0F;
    } else {
      if (rtb_Add3_fc < 0.2F) {
        rtb_Add3_fc = 0.2F;
      }
    }

    /* End of Saturate: '<S81>/Saturation' */

    /* Sum: '<S76>/Sum' incorporates:
     *  Product: '<S81>/Multiply'
     *  Product: '<S81>/Multiply1'
     *  Trigonometry: '<S81>/Cos'
     *  Trigonometry: '<S81>/Tan'
     */
    rtb_Add3_fc = tanf(rtb_phi_cmd) * arm_cos_f32(rtb_Multiply1_e) * rtb_Add3_fc
      + Controller_U.FMS_Out.psi_rate_cmd;

    /* Saturate: '<S78>/Saturation' */
    if (rtb_phi_cmd > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_phi_cmd = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_phi_cmd < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_phi_cmd = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      }
    }

    /* Sum: '<S69>/Add' incorporates:
     *  Constant: '<S79>/Constant1'
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S69>/Multiply'
     *  Product: '<S79>/Multiply'
     *  Sum: '<S78>/Sum'
     */
    rtb_Multiply1_e = (rtb_phi_cmd - Controller_U.INS_Out.phi) *
      CONTROL_PARAM.FW_ROLL_P - rtb_TmpSignalConversionAtMult_3 * rtb_Add3_fc;

    /* Sum: '<S69>/Add1' incorporates:
     *  Product: '<S69>/Multiply1'
     *  Product: '<S69>/Multiply3'
     */
    rtb_phi_cmd = rtb_aux_att_error_B_rad_idx_1 *
      rtb_DiscreteTimeIntegrator1_a_t * rtb_Add3_fc + rtb_Integrator1_o_tmp *
      rtb_Saturation_j_idx_1;

    /* Sum: '<S69>/Add2' incorporates:
     *  Product: '<S69>/Multiply4'
     *  Product: '<S69>/Multiply5'
     */
    rtb_aux_att_error_B_rad_idx_1 = rtb_Integrator1_o_tmp *
      rtb_DiscreteTimeIntegrator1_a_t * rtb_Add3_fc -
      rtb_aux_att_error_B_rad_idx_1 * rtb_Saturation_j_idx_1;

    /* Sum: '<S67>/Minus2' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Saturation_j_idx_0 = rtb_Multiply1_e - Controller_U.INS_Out.p;
    rtb_Saturation_j_idx_1 = rtb_phi_cmd - Controller_U.INS_Out.q;
    rtb_Saturation_j_idx_2 = rtb_aux_att_error_B_rad_idx_1 -
      Controller_U.INS_Out.r;

    /* DiscreteIntegrator: '<S73>/Discrete-Time Integrator' */
    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator_PrevR_ef != 0)) {
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

    /* Switch: '<S12>/Switch' */
    if (rtb_Compare_nq) {
      Controller_B.fw_torque_cmd[0] = Controller_U.FMS_Out.p_cmd;
      Controller_B.fw_torque_cmd[1] = Controller_U.FMS_Out.q_cmd;
      Controller_B.fw_torque_cmd[2] = Controller_U.FMS_Out.r_cmd;
    } else {
      /* Product: '<S71>/Divide' incorporates:
       *  Constant: '<S71>/trim_speed'
       *  Math: '<S71>/Square'
       */
      rtb_Saturation_g = CONTROL_PARAM.FW_AIRSPEED_TRIM *
        CONTROL_PARAM.FW_AIRSPEED_TRIM / rtb_Saturation_g;

      /* Saturate: '<S71>/Saturation' */
      if (rtb_Saturation_g > 1.0F) {
        rtb_Saturation_g = 1.0F;
      } else {
        if (rtb_Saturation_g < 0.0F) {
          rtb_Saturation_g = 0.0F;
        }
      }

      /* End of Saturate: '<S71>/Saturation' */

      /* Product: '<S67>/Multiply' incorporates:
       *  Constant: '<S74>/gain1'
       *  Constant: '<S74>/gain2'
       *  Constant: '<S74>/gain3'
       *  DiscreteIntegrator: '<S73>/Discrete-Time Integrator'
       *  Product: '<S74>/Multiply'
       *  Sum: '<S70>/Add1'
       */
      rtb_Add3_fc = (CONTROL_PARAM.FW_ROLL_RATE_P * rtb_Saturation_j_idx_0 +
                     Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0]) *
        rtb_Saturation_g;
      rtb_DiscreteTimeIntegrator1_a_t = (CONTROL_PARAM.FW_PITCH_RATE_P *
        rtb_Saturation_j_idx_1 + Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1])
        * rtb_Saturation_g;
      rtb_Integrator1_o_tmp = (CONTROL_PARAM.FW_YAW_RATE_P *
        rtb_Saturation_j_idx_2 + Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2])
        * rtb_Saturation_g;

      /* Product: '<S72>/Divide' incorporates:
       *  Constant: '<S72>/trim_speed'
       *  DiscreteIntegrator: '<S55>/Discrete-Time Integrator5'
       */
      rtb_Saturation_g = CONTROL_PARAM.FW_AIRSPEED_TRIM /
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;

      /* Saturate: '<S72>/Saturation' */
      if (rtb_Saturation_g > 1.0F) {
        rtb_Saturation_g = 1.0F;
      } else {
        if (rtb_Saturation_g < 0.0F) {
          rtb_Saturation_g = 0.0F;
        }
      }

      /* End of Saturate: '<S72>/Saturation' */

      /* Product: '<S67>/Multiply1' incorporates:
       *  Gain: '<S67>/FF'
       */
      rtb_Multiply1_e = CONTROL_PARAM.FW_FF * rtb_Multiply1_e * rtb_Saturation_g;

      /* Saturate: '<S67>/FF_limit' */
      if (rtb_Multiply1_e > CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_Multiply1_e = CONTROL_PARAM.FW_FF_LIMIT;
      } else {
        if (rtb_Multiply1_e < -CONTROL_PARAM.FW_FF_LIMIT) {
          rtb_Multiply1_e = -CONTROL_PARAM.FW_FF_LIMIT;
        }
      }

      /* Saturate: '<S67>/PI_limit' */
      if (rtb_Add3_fc > CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_Add3_fc = CONTROL_PARAM.FW_PI_LIMIT;
      } else {
        if (rtb_Add3_fc < -CONTROL_PARAM.FW_PI_LIMIT) {
          rtb_Add3_fc = -CONTROL_PARAM.FW_PI_LIMIT;
        }
      }

      /* Product: '<S11>/Multiply' incorporates:
       *  DiscreteIntegrator: '<S51>/Discrete-Time Integrator5'
       *  Sum: '<S67>/Add'
       */
      rtb_Add3_fc = (rtb_Multiply1_e + rtb_Add3_fc) *
        Controller_DW.DiscreteTimeIntegrator5_DSTA_jo;

      /* Saturate: '<S11>/Saturation1' */
      if (rtb_Add3_fc > 1.0F) {
        Controller_B.fw_torque_cmd[0] = 1.0F;
      } else if (rtb_Add3_fc < -1.0F) {
        Controller_B.fw_torque_cmd[0] = -1.0F;
      } else {
        Controller_B.fw_torque_cmd[0] = rtb_Add3_fc;
      }

      /* Product: '<S67>/Multiply1' incorporates:
       *  Gain: '<S67>/FF'
       */
      rtb_Add3_fc = CONTROL_PARAM.FW_FF * rtb_phi_cmd * rtb_Saturation_g;

      /* Saturate: '<S67>/FF_limit' */
      if (rtb_Add3_fc > CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_Add3_fc = CONTROL_PARAM.FW_FF_LIMIT;
      } else {
        if (rtb_Add3_fc < -CONTROL_PARAM.FW_FF_LIMIT) {
          rtb_Add3_fc = -CONTROL_PARAM.FW_FF_LIMIT;
        }
      }

      /* Saturate: '<S67>/PI_limit' */
      if (rtb_DiscreteTimeIntegrator1_a_t > CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_DiscreteTimeIntegrator1_a_t = CONTROL_PARAM.FW_PI_LIMIT;
      } else {
        if (rtb_DiscreteTimeIntegrator1_a_t < -CONTROL_PARAM.FW_PI_LIMIT) {
          rtb_DiscreteTimeIntegrator1_a_t = -CONTROL_PARAM.FW_PI_LIMIT;
        }
      }

      /* Product: '<S11>/Multiply' incorporates:
       *  DiscreteIntegrator: '<S51>/Discrete-Time Integrator5'
       *  Sum: '<S67>/Add'
       */
      rtb_Add3_fc = (rtb_Add3_fc + rtb_DiscreteTimeIntegrator1_a_t) *
        Controller_DW.DiscreteTimeIntegrator5_DSTA_jo;

      /* Saturate: '<S11>/Saturation1' */
      if (rtb_Add3_fc > 1.0F) {
        Controller_B.fw_torque_cmd[1] = 1.0F;
      } else if (rtb_Add3_fc < -1.0F) {
        Controller_B.fw_torque_cmd[1] = -1.0F;
      } else {
        Controller_B.fw_torque_cmd[1] = rtb_Add3_fc;
      }

      /* Product: '<S67>/Multiply1' incorporates:
       *  Gain: '<S67>/FF'
       */
      rtb_Add3_fc = CONTROL_PARAM.FW_FF * rtb_aux_att_error_B_rad_idx_1 *
        rtb_Saturation_g;

      /* Saturate: '<S67>/FF_limit' */
      if (rtb_Add3_fc > CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_Add3_fc = CONTROL_PARAM.FW_FF_LIMIT;
      } else {
        if (rtb_Add3_fc < -CONTROL_PARAM.FW_FF_LIMIT) {
          rtb_Add3_fc = -CONTROL_PARAM.FW_FF_LIMIT;
        }
      }

      /* Saturate: '<S67>/PI_limit' */
      if (rtb_Integrator1_o_tmp > CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_Integrator1_o_tmp = CONTROL_PARAM.FW_PI_LIMIT;
      } else {
        if (rtb_Integrator1_o_tmp < -CONTROL_PARAM.FW_PI_LIMIT) {
          rtb_Integrator1_o_tmp = -CONTROL_PARAM.FW_PI_LIMIT;
        }
      }

      /* Product: '<S11>/Multiply' incorporates:
       *  DiscreteIntegrator: '<S51>/Discrete-Time Integrator5'
       *  Sum: '<S67>/Add'
       */
      rtb_Add3_fc = (rtb_Add3_fc + rtb_Integrator1_o_tmp) *
        Controller_DW.DiscreteTimeIntegrator5_DSTA_jo;

      /* Saturate: '<S11>/Saturation1' */
      if (rtb_Add3_fc > 1.0F) {
        Controller_B.fw_torque_cmd[2] = 1.0F;
      } else if (rtb_Add3_fc < -1.0F) {
        Controller_B.fw_torque_cmd[2] = -1.0F;
      } else {
        Controller_B.fw_torque_cmd[2] = rtb_Add3_fc;
      }
    }

    /* Product: '<S46>/Multiply1' incorporates:
     *  Constant: '<S46>/const1'
     *  DiscreteIntegrator: '<S45>/Integrator'
     */
    rtb_Add3_fc = Controller_DW.Integrator_DSTATE_f * 0.05F;

    /* Sum: '<S46>/Add' incorporates:
     *  DiscreteIntegrator: '<S45>/Integrator1'
     *  Sum: '<S45>/Subtract'
     */
    rtb_Saturation_g = (Controller_DW.Integrator1_DSTATE_i -
                        Controller_U.FMS_Out.w_cmd) + rtb_Add3_fc;

    /* Signum: '<S46>/Sign' */
    if (rtb_Saturation_g < 0.0F) {
      rtb_aux_att_error_B_rad_idx_1 = -1.0F;
    } else if (rtb_Saturation_g > 0.0F) {
      rtb_aux_att_error_B_rad_idx_1 = 1.0F;
    } else {
      rtb_aux_att_error_B_rad_idx_1 = rtb_Saturation_g;
    }

    /* End of Signum: '<S46>/Sign' */

    /* Sum: '<S46>/Add2' incorporates:
     *  Abs: '<S46>/Abs'
     *  Gain: '<S46>/Gain'
     *  Gain: '<S46>/Gain1'
     *  Product: '<S46>/Multiply2'
     *  Product: '<S46>/Multiply3'
     *  Sqrt: '<S46>/Sqrt'
     *  Sum: '<S46>/Add1'
     *  Sum: '<S46>/Subtract'
     */
    rtb_aux_att_error_B_rad_idx_1 = (sqrtf((8.0F * fabsf(rtb_Saturation_g) +
      Controller_ConstB.d_m) * Controller_ConstB.d_m) - Controller_ConstB.d_m) *
      0.5F * rtb_aux_att_error_B_rad_idx_1 + rtb_Add3_fc;

    /* Sum: '<S46>/Add4' */
    rtb_phi_cmd = (rtb_Saturation_g - rtb_aux_att_error_B_rad_idx_1) +
      rtb_Add3_fc;

    /* Sum: '<S46>/Add3' */
    rtb_Add3_fc = rtb_Saturation_g + Controller_ConstB.d_m;

    /* Sum: '<S46>/Subtract1' */
    rtb_Saturation_g -= Controller_ConstB.d_m;

    /* Signum: '<S46>/Sign1' */
    if (rtb_Add3_fc < 0.0F) {
      rtb_Add3_fc = -1.0F;
    } else {
      if (rtb_Add3_fc > 0.0F) {
        rtb_Add3_fc = 1.0F;
      }
    }

    /* End of Signum: '<S46>/Sign1' */

    /* Signum: '<S46>/Sign2' */
    if (rtb_Saturation_g < 0.0F) {
      rtb_Saturation_g = -1.0F;
    } else {
      if (rtb_Saturation_g > 0.0F) {
        rtb_Saturation_g = 1.0F;
      }
    }

    /* End of Signum: '<S46>/Sign2' */

    /* Sum: '<S46>/Add5' incorporates:
     *  Gain: '<S46>/Gain2'
     *  Product: '<S46>/Multiply4'
     *  Sum: '<S46>/Subtract2'
     */
    rtb_aux_att_error_B_rad_idx_1 += (rtb_Add3_fc - rtb_Saturation_g) * 0.5F *
      rtb_phi_cmd;

    /* Update for DiscreteIntegrator: '<S55>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S55>/Gain'
     *  Sum: '<S55>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_e = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_j += (rtb_Divide_m_idx_0 -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j) * 125.663704F * 0.002F;

    /* Update for DiscreteIntegrator: '<S53>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S53>/Gain'
     *  Sum: '<S53>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_L_eo = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_a += (rtb_Divide_m_idx_1 -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_a) * 31.415926F * 0.002F;

    /* Update for DiscreteIntegrator: '<S52>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S52>/Gain'
     *  Sum: '<S52>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_o = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTA_a2 += ((real32_T)rtb_Relay -
      Controller_DW.DiscreteTimeIntegrator5_DSTA_a2) * 6.28318548F * 0.002F;

    /* Update for DiscreteIntegrator: '<S26>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S26>/gain1'
     *  Constant: '<S26>/gain2'
     *  Constant: '<S26>/gain3'
     *  DiscreteIntegrator: '<S24>/Discrete-Time Integrator5'
     *  Product: '<S26>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_d[0] +=
      CONTROL_PARAM.MC_ROLL_RATE_I *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0] * 0.002F;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_d[0] >=
        CONTROL_PARAM.MC_RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_d[0] =
        CONTROL_PARAM.MC_RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_d[0] <=
          CONTROL_PARAM.MC_RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_d[0] =
          CONTROL_PARAM.MC_RATE_I_MIN;
      }
    }

    Controller_DW.DiscreteTimeIntegrator_DSTATE_d[1] +=
      CONTROL_PARAM.MC_PITCH_RATE_I *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1] * 0.002F;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_d[1] >=
        CONTROL_PARAM.MC_RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_d[1] =
        CONTROL_PARAM.MC_RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_d[1] <=
          CONTROL_PARAM.MC_RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_d[1] =
          CONTROL_PARAM.MC_RATE_I_MIN;
      }
    }

    Controller_DW.DiscreteTimeIntegrator_DSTATE_d[2] +=
      CONTROL_PARAM.MC_YAW_RATE_I *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2] * 0.002F;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_d[2] >=
        CONTROL_PARAM.MC_RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_d[2] =
        CONTROL_PARAM.MC_RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_d[2] <=
          CONTROL_PARAM.MC_RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_d[2] =
          CONTROL_PARAM.MC_RATE_I_MIN;
      }
    }

    Controller_DW.DiscreteTimeIntegrator_PrevRe_o = (int8_T)
      rtb_LogicalOperator_i;

    /* End of Update for DiscreteIntegrator: '<S26>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S99>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S99>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S99>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_n = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_f += (Controller_U.INS_Out.ax -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_f) * 31.415926F * 0.002F;

    /* Update for DiscreteIntegrator: '<S94>/ ' incorporates:
     *  Gain: '<S94>/Gain3'
     */
    Controller_DW._DSTATE += CONTROL_PARAM.FW_TECS_PITCH_I * rtb_Square_d *
      0.002F;
    if (Controller_DW._DSTATE >= CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
      Controller_DW._DSTATE = CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
    } else {
      if (Controller_DW._DSTATE <= -CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
        Controller_DW._DSTATE = -CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
      }
    }

    Controller_DW._PrevResetState = (int8_T)(Controller_U.FMS_Out.reset > 0);

    /* End of Update for DiscreteIntegrator: '<S94>/ ' */

    /* Update for DiscreteIntegrator: '<S95>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_f = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_e += 0.002F * rtb_Gain_c4;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_b = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S24>/Discrete-Time Integrator5' */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_b = 0U;

    /* Update for DiscreteIntegrator: '<S28>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_h = 0U;

    /* Update for DiscreteIntegrator: '<S24>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S24>/Gain'
     *  Sum: '<S24>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0] +=
      (rtb_TmpSignalConversionAtMult_0 -
       Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S28>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[0] += 0.002F *
      rtb_DiscreteTimeIntegrator1_k1[0];

    /* Update for DiscreteIntegrator: '<S24>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S24>/Gain'
     *  Sum: '<S24>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1] +=
      (rtb_TmpSignalConversionAtMult_1 -
       Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S28>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[1] += 0.002F *
      rtb_DiscreteTimeIntegrator1_k1[1];

    /* Update for DiscreteIntegrator: '<S24>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S24>/Gain'
     *  Sum: '<S24>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2] +=
      (rtb_TmpSignalConversionAtMult_2 -
       Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S28>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[2] += 0.002F *
      rtb_DiscreteTimeIntegrator1_k1[2];
    Controller_DW.DiscreteTimeIntegrator1_PrevR_l = (int8_T)
      rtb_LogicalOperator_i;

    /* Update for DiscreteIntegrator: '<S97>/ ' incorporates:
     *  Gain: '<S97>/Gain'
     */
    Controller_DW._DSTATE_d += CONTROL_PARAM.FW_TECS_THOR_I * rtb_Divide_m_idx_3
      * 0.002F;
    if (Controller_DW._DSTATE_d >= 1.0F) {
      Controller_DW._DSTATE_d = 1.0F;
    } else {
      if (Controller_DW._DSTATE_d <= 0.0F) {
        Controller_DW._DSTATE_d = 0.0F;
      }
    }

    Controller_DW._PrevResetState_e = (int8_T)(Controller_U.FMS_Out.reset > 0);

    /* End of Update for DiscreteIntegrator: '<S97>/ ' */

    /* Update for DiscreteIntegrator: '<S98>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_L_h0 = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTA_nm += 0.002F *
      rtb_aux_att_error_B_rad_idx_0;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_d = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S45>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S45>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_i += 0.002F *
      Controller_DW.Integrator_DSTATE_f;

    /* Update for DiscreteIntegrator: '<S48>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S48>/ki'
     *  Product: '<S48>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_b += CONTROL_PARAM.MC_VEL_Z_I *
      rtb_Abs * 0.002F;
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
      rtb_LogicalOperator_g;

    /* End of Update for DiscreteIntegrator: '<S48>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S50>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_i = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_l += 0.002F *
      rtb_DiscreteTimeIntegrator5_h5;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_h = (int8_T)
      rtb_LogicalOperator_g;

    /* Update for DiscreteIntegrator: '<S51>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S51>/Gain'
     *  Sum: '<S51>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_g = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTA_jo += (rtb_Divide_m_idx_2 -
      Controller_DW.DiscreteTimeIntegrator5_DSTA_jo) * 12.566371F * 0.002F;

    /* Update for DiscreteIntegrator: '<S73>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S73>/gain1'
     *  Constant: '<S73>/gain2'
     *  Constant: '<S73>/gain3'
     *  Product: '<S73>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0] +=
      CONTROL_PARAM.FW_ROLL_RATE_I * rtb_Saturation_j_idx_0 * 0.002F;
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
      CONTROL_PARAM.FW_PITCH_RATE_I * rtb_Saturation_j_idx_1 * 0.002F;
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
      CONTROL_PARAM.FW_YAW_RATE_I * rtb_Saturation_j_idx_2 * 0.002F;
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

    Controller_DW.DiscreteTimeIntegrator_PrevR_ef = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* End of Update for DiscreteIntegrator: '<S73>/Discrete-Time Integrator' */

    /* Signum: '<S46>/Sign6' incorporates:
     *  Signum: '<S46>/Sign5'
     */
    if (rtb_aux_att_error_B_rad_idx_1 < 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = -1.0F;

      /* Signum: '<S46>/Sign5' */
      rtb_TmpSignalConversionAtMult_2 = -1.0F;
    } else if (rtb_aux_att_error_B_rad_idx_1 > 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = 1.0F;

      /* Signum: '<S46>/Sign5' */
      rtb_TmpSignalConversionAtMult_2 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_1 = rtb_aux_att_error_B_rad_idx_1;

      /* Signum: '<S46>/Sign5' */
      rtb_TmpSignalConversionAtMult_2 = rtb_aux_att_error_B_rad_idx_1;
    }

    /* End of Signum: '<S46>/Sign6' */

    /* Sum: '<S46>/Add6' */
    rtb_Add3_fc = rtb_aux_att_error_B_rad_idx_1 + Controller_ConstB.d_m;

    /* Sum: '<S46>/Subtract3' */
    rtb_TmpSignalConversionAtMult_0 = rtb_aux_att_error_B_rad_idx_1 -
      Controller_ConstB.d_m;

    /* Signum: '<S46>/Sign3' */
    if (rtb_Add3_fc < 0.0F) {
      rtb_Add3_fc = -1.0F;
    } else {
      if (rtb_Add3_fc > 0.0F) {
        rtb_Add3_fc = 1.0F;
      }
    }

    /* End of Signum: '<S46>/Sign3' */

    /* Signum: '<S46>/Sign4' */
    if (rtb_TmpSignalConversionAtMult_0 < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else {
      if (rtb_TmpSignalConversionAtMult_0 > 0.0F) {
        rtb_TmpSignalConversionAtMult_0 = 1.0F;
      }
    }

    /* End of Signum: '<S46>/Sign4' */

    /* Update for DiscreteIntegrator: '<S45>/Integrator' incorporates:
     *  Constant: '<S46>/const'
     *  Gain: '<S46>/Gain3'
     *  Product: '<S46>/Divide'
     *  Product: '<S46>/Multiply5'
     *  Product: '<S46>/Multiply6'
     *  Sum: '<S46>/Subtract4'
     *  Sum: '<S46>/Subtract5'
     *  Sum: '<S46>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE_f += ((rtb_aux_att_error_B_rad_idx_1 /
      Controller_ConstB.d_m - rtb_TmpSignalConversionAtMult_2) *
      Controller_ConstB.Gain4_o * ((rtb_Add3_fc -
      rtb_TmpSignalConversionAtMult_0) * 0.5F) - rtb_TmpSignalConversionAtMult_1
      * 78.448F) * 0.002F;

    /* End of Outputs for SubSystem: '<S2>/FW_Controller' */
    break;

   case 1:
    if (Controller_DW.SwitchCase1_ActiveSubsystem != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S2>/MC_Controller' incorporates:
       *  ActionPort: '<S5>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S8>/Switch Case1' incorporates:
       *  DiscreteIntegrator: '<S117>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S119>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S121>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S141>/Integrator'
       *  DiscreteIntegrator: '<S141>/Integrator1'
       *  DiscreteIntegrator: '<S146>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S148>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S164>/Integrator'
       *  DiscreteIntegrator: '<S164>/Integrator1'
       *  DiscreteIntegrator: '<S167>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S169>/Discrete-Time Integrator1'
       */
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
      Controller_DW.DiscreteTimeIntegrator_PrevRe_p = 0;
      Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;
      Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevR_k = 0;
      Controller_DW.Integrator1_DSTATE[0] = 0.0F;
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

      Controller_DW.Integrator_DSTATE[0] = 0.0F;
      Controller_DW.Integrator1_DSTATE[1] = 0.0F;
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

      Controller_DW.Integrator_DSTATE[1] = 0.0F;
      Controller_DW.Integrator1_DSTATE_e = 0.0F;
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
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 1U;
      Controller_DW.DiscreteTimeIntegrator1_Prev_ks = 0;
      Controller_DW.Integrator_DSTATE_j = 0.0F;

      /* End of InitializeConditions for SubSystem: '<S2>/MC_Controller' */
    }

    /* Outputs for IfAction SubSystem: '<S2>/MC_Controller' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* SignalConversion: '<S5>/BusConversion_InsertedFor_VTOL_actuator_cmd_at_inport_0' */
    Controller_B.fw_torque_cmd[0] = Controller_ConstB.fw_torque_cmd[0];

    /* SignalConversion: '<S5>/BusConversion_InsertedFor_VTOL_actuator_cmd_at_inport_0' */
    Controller_B.fw_force_cmd[0] = Controller_ConstB.fw_force_cmd[0];

    /* SignalConversion: '<S5>/BusConversion_InsertedFor_VTOL_actuator_cmd_at_inport_0' */
    Controller_B.fw_torque_cmd[1] = Controller_ConstB.fw_torque_cmd[1];

    /* SignalConversion: '<S5>/BusConversion_InsertedFor_VTOL_actuator_cmd_at_inport_0' */
    Controller_B.fw_force_cmd[1] = Controller_ConstB.fw_force_cmd[1];

    /* SignalConversion: '<S5>/BusConversion_InsertedFor_VTOL_actuator_cmd_at_inport_0' */
    Controller_B.fw_torque_cmd[2] = Controller_ConstB.fw_torque_cmd[2];

    /* SignalConversion: '<S5>/BusConversion_InsertedFor_VTOL_actuator_cmd_at_inport_0' */
    Controller_B.fw_force_cmd[2] = Controller_ConstB.fw_force_cmd[2];

    /* DiscreteIntegrator: '<S119>/Discrete-Time Integrator' */
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

    /* Trigonometry: '<S143>/Trigonometric Function1' incorporates:
     *  Gain: '<S142>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_VectorConcatenate_o[0] = arm_cos_f32(-Controller_U.INS_Out.psi);

    /* Trigonometry: '<S143>/Trigonometric Function' incorporates:
     *  Gain: '<S142>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_VectorConcatenate_o[1] = arm_sin_f32(-Controller_U.INS_Out.psi);

    /* SignalConversion: '<S143>/ConcatBufferAtVector Concatenate1In3' incorporates:
     *  Constant: '<S143>/Constant3'
     */
    rtb_VectorConcatenate_o[2] = 0.0F;

    /* Gain: '<S143>/Gain' incorporates:
     *  Gain: '<S142>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S143>/Trigonometric Function2'
     */
    rtb_VectorConcatenate_o[3] = -arm_sin_f32(-Controller_U.INS_Out.psi);

    /* Trigonometry: '<S143>/Trigonometric Function3' incorporates:
     *  Gain: '<S142>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_VectorConcatenate_o[4] = arm_cos_f32(-Controller_U.INS_Out.psi);

    /* SignalConversion: '<S143>/ConcatBufferAtVector Concatenate2In3' incorporates:
     *  Constant: '<S143>/Constant4'
     */
    rtb_VectorConcatenate_o[5] = 0.0F;

    /* SignalConversion: '<S143>/ConcatBufferAtVector ConcatenateIn3' */
    rtb_VectorConcatenate_o[6] = Controller_ConstB.VectorConcatenate3[0];
    rtb_VectorConcatenate_o[7] = Controller_ConstB.VectorConcatenate3[1];
    rtb_VectorConcatenate_o[8] = Controller_ConstB.VectorConcatenate3[2];

    /* Product: '<S140>/Multiply' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  SignalConversion: '<S140>/TmpSignal ConversionAtMultiplyInport2'
     */
    for (rtb_Relay = 0; rtb_Relay < 3; rtb_Relay++) {
      rtb_VectorConcatenate_k[rtb_Relay] = rtb_VectorConcatenate_o[rtb_Relay + 3]
        * Controller_U.INS_Out.ve + rtb_VectorConcatenate_o[rtb_Relay] *
        Controller_U.INS_Out.vn;
    }

    /* End of Product: '<S140>/Multiply' */

    /* Sum: '<S137>/Sum' incorporates:
     *  DiscreteIntegrator: '<S141>/Integrator1'
     */
    rtb_aux_att_error_B_rad_idx_0 = Controller_DW.Integrator1_DSTATE[0] -
      rtb_VectorConcatenate_k[0];
    rtb_aux_att_error_B_rad_idx_1 = Controller_DW.Integrator1_DSTATE[1] -
      rtb_VectorConcatenate_k[1];

    /* DiscreteIntegrator: '<S146>/Discrete-Time Integrator' */
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

    /* DiscreteIntegrator: '<S148>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] =
        rtb_aux_att_error_B_rad_idx_0;
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] =
        rtb_aux_att_error_B_rad_idx_1;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevRes != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] =
        rtb_aux_att_error_B_rad_idx_0;
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] =
        rtb_aux_att_error_B_rad_idx_1;
    }

    /* Gain: '<S148>/Gain' incorporates:
     *  DiscreteIntegrator: '<S148>/Discrete-Time Integrator1'
     *  Sum: '<S148>/Sum5'
     */
    rtb_Divide_m_idx_3 = (rtb_aux_att_error_B_rad_idx_0 -
                          Controller_DW.DiscreteTimeIntegrator1_DSTATE[0]) *
      62.831852F;
    rtb_Divide_m_idx_0 = (rtb_aux_att_error_B_rad_idx_1 -
                          Controller_DW.DiscreteTimeIntegrator1_DSTATE[1]) *
      62.831852F;

    /* Switch: '<S148>/Switch' incorporates:
     *  Gain: '<S148>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_Divide_m_idx_1 = 0.0F;
      rtb_Divide_m_idx_2 = 0.0F;
    } else {
      rtb_Divide_m_idx_1 = rtb_Divide_m_idx_3;
      rtb_Divide_m_idx_2 = rtb_Divide_m_idx_0;
    }

    /* End of Switch: '<S148>/Switch' */

    /* Product: '<S145>/Multiply' incorporates:
     *  Constant: '<S145>/kd'
     */
    rtb_Square_d = CONTROL_PARAM.MC_VEL_XY_D * rtb_Divide_m_idx_1;

    /* Saturate: '<S145>/Saturation' */
    if (rtb_Square_d > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
      rtb_Square_d = CONTROL_PARAM.MC_VEL_XY_D_MAX;
    } else {
      if (rtb_Square_d < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
        rtb_Square_d = CONTROL_PARAM.MC_VEL_XY_D_MIN;
      }
    }

    rtb_Divide_m_idx_1 = rtb_Square_d;

    /* Product: '<S145>/Multiply' incorporates:
     *  Constant: '<S145>/kd'
     */
    rtb_Square_d = CONTROL_PARAM.MC_VEL_XY_D * rtb_Divide_m_idx_2;

    /* Saturate: '<S145>/Saturation' */
    if (rtb_Square_d > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
      rtb_Square_d = CONTROL_PARAM.MC_VEL_XY_D_MAX;
    } else {
      if (rtb_Square_d < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
        rtb_Square_d = CONTROL_PARAM.MC_VEL_XY_D_MIN;
      }
    }

    /* Switch: '<S139>/Switch' incorporates:
     *  Constant: '<S147>/kp'
     *  Constant: '<S149>/Constant'
     *  Constant: '<S151>/Constant'
     *  Constant: '<S152>/Constant'
     *  DiscreteIntegrator: '<S146>/Discrete-Time Integrator'
     *  Product: '<S147>/Multiply'
     *  Product: '<S150>/Multiply2'
     *  Product: '<S150>/Multiply3'
     *  RelationalOperator: '<S149>/Compare'
     *  RelationalOperator: '<S151>/Compare'
     *  RelationalOperator: '<S152>/Compare'
     *  S-Function (sfix_bitop): '<S150>/cmd_ax valid'
     *  S-Function (sfix_bitop): '<S150>/cmd_ay valid'
     *  S-Function (sfix_bitop): '<S150>/cmd_u valid'
     *  S-Function (sfix_bitop): '<S150>/cmd_v valid'
     *  Sum: '<S138>/Add'
     *  Sum: '<S150>/Sum1'
     */
    if (rtb_BitwiseAND_n == 6) {
      rtb_Divide_m_idx_1 = ((Controller_U.FMS_Out.cmd_mask & 64) > 0 ?
                            (CONTROL_PARAM.MC_VEL_XY_P *
        rtb_aux_att_error_B_rad_idx_0 +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0]) + rtb_Divide_m_idx_1 :
                            0.0F) + ((Controller_U.FMS_Out.cmd_mask & 512) > 0 ?
        Controller_U.FMS_Out.ax_cmd : 0.0F);
      rtb_Divide_m_idx_2 = ((Controller_U.FMS_Out.cmd_mask & 128) > 0 ?
                            (CONTROL_PARAM.MC_VEL_XY_P *
        rtb_aux_att_error_B_rad_idx_1 +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1]) + rtb_Square_d : 0.0F)
        + ((Controller_U.FMS_Out.cmd_mask & 1024) > 0 ?
           Controller_U.FMS_Out.ay_cmd : 0.0F);
    } else {
      rtb_Divide_m_idx_1 += CONTROL_PARAM.MC_VEL_XY_P *
        rtb_aux_att_error_B_rad_idx_0 +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0];
      rtb_Divide_m_idx_2 = (CONTROL_PARAM.MC_VEL_XY_P *
                            rtb_aux_att_error_B_rad_idx_1 +
                            Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1]) +
        rtb_Square_d;
    }

    /* End of Switch: '<S139>/Switch' */

    /* Trigonometry: '<S136>/Atan' incorporates:
     *  Constant: '<S136>/g'
     *  Gain: '<S136>/Gain1'
     *  Gain: '<S136>/gain'
     *  Product: '<S136>/Divide'
     */
    rtb_Add3_fc = atanf(1.1F * rtb_Divide_m_idx_2 / 9.8055F);
    rtb_Divide_m_idx_2 = atanf(1.1F * -rtb_Divide_m_idx_1 / 9.8055F);

    /* Switch: '<S127>/Switch' incorporates:
     *  Constant: '<S134>/Constant'
     *  Logic: '<S127>/Logical Operator'
     *  RelationalOperator: '<S133>/Compare'
     *  RelationalOperator: '<S134>/Compare'
     *  Saturate: '<S136>/Saturation'
     *  Switch: '<S127>/Switch1'
     */
    if ((rtb_BitwiseAND_n == 3) || (rtb_BitwiseAND_n == 4)) {
      rtb_Divide_m_idx_1 = Controller_U.FMS_Out.phi_cmd;
      rtb_Divide_m_idx_2 = Controller_U.FMS_Out.theta_cmd;
    } else if (rtb_BitwiseAND_n == 6) {
      /* Switch: '<S135>/Switch' incorporates:
       *  S-Function (sfix_bitop): '<S135>/cmd_phi valid'
       *  S-Function (sfix_bitop): '<S135>/cmd_theta valid'
       *  Saturate: '<S136>/Saturation'
       *  Switch: '<S127>/Switch1'
       */
      if ((Controller_U.FMS_Out.cmd_mask & 8) > 0) {
        rtb_Divide_m_idx_1 = Controller_U.FMS_Out.phi_cmd;
      } else if (rtb_Add3_fc > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S136>/Saturation' */
        rtb_Divide_m_idx_1 = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else if (rtb_Add3_fc < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S136>/Saturation' */
        rtb_Divide_m_idx_1 = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        rtb_Divide_m_idx_1 = rtb_Add3_fc;
      }

      if ((Controller_U.FMS_Out.cmd_mask & 16) > 0) {
        rtb_Divide_m_idx_2 = Controller_U.FMS_Out.theta_cmd;
      } else if (rtb_Divide_m_idx_2 > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S136>/Saturation' */
        rtb_Divide_m_idx_2 = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_Divide_m_idx_2 < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Saturate: '<S136>/Saturation' */
          rtb_Divide_m_idx_2 = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        }
      }

      /* End of Switch: '<S135>/Switch' */
    } else {
      if (rtb_Add3_fc > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S136>/Saturation' incorporates:
         *  Switch: '<S127>/Switch1'
         */
        rtb_Divide_m_idx_1 = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else if (rtb_Add3_fc < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S136>/Saturation' incorporates:
         *  Switch: '<S127>/Switch1'
         */
        rtb_Divide_m_idx_1 = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        /* Switch: '<S127>/Switch1' incorporates:
         *  Saturate: '<S136>/Saturation'
         */
        rtb_Divide_m_idx_1 = rtb_Add3_fc;
      }

      /* Saturate: '<S136>/Saturation' */
      if (rtb_Divide_m_idx_2 > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Switch: '<S127>/Switch1' */
        rtb_Divide_m_idx_2 = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_Divide_m_idx_2 < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Switch: '<S127>/Switch1' */
          rtb_Divide_m_idx_2 = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        }
      }
    }

    /* End of Switch: '<S127>/Switch' */

    /* Sum: '<S128>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Square_d = rtb_Divide_m_idx_1 - Controller_U.INS_Out.phi;

    /* Product: '<S131>/Divide1' incorporates:
     *  Abs: '<S131>/Abs'
     *  Constant: '<S131>/const2'
     */
    rtb_Saturation_j_idx_0 = fabsf(rtb_Square_d) / 0.002F;

    /* Product: '<S131>/Divide' incorporates:
     *  Constant: '<S129>/Constant1'
     *  Constant: '<S131>/const1'
     *  Math: '<S131>/Square'
     *  SignalConversion: '<S131>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_TmpSignalConversionAtMult_1 = 9.5993F / (CONTROL_PARAM.MC_ROLL_P *
      CONTROL_PARAM.MC_ROLL_P);

    /* Signum: '<S131>/Sign' */
    if (rtb_Square_d < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else if (rtb_Square_d > 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_0 = rtb_Square_d;
    }

    /* Switch: '<S131>/Switch' incorporates:
     *  Constant: '<S129>/Constant1'
     *  Gain: '<S131>/Gain1'
     *  Gain: '<S131>/Gain2'
     *  Logic: '<S131>/Logical Operator'
     *  Product: '<S131>/Divide'
     *  Product: '<S131>/Multiply'
     *  Product: '<S131>/Multiply1'
     *  Product: '<S131>/Multiply2'
     *  Product: '<S131>/Multiply3'
     *  RelationalOperator: '<S131>/Relational Operator'
     *  RelationalOperator: '<S131>/Relational Operator2'
     *  SignalConversion: '<S131>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S131>/Sqrt'
     *  Sum: '<S131>/Subtract'
     */
    if ((rtb_Square_d <= rtb_TmpSignalConversionAtMult_1) && (rtb_Square_d >=
         -rtb_TmpSignalConversionAtMult_1)) {
      rtb_TmpSignalConversionAtMult_0 = rtb_Square_d * CONTROL_PARAM.MC_ROLL_P;
    } else {
      rtb_TmpSignalConversionAtMult_0 *= sqrtf((rtb_TmpSignalConversionAtMult_0 *
        rtb_Square_d - 0.5F * rtb_TmpSignalConversionAtMult_1) *
        Controller_ConstB.Gain);
    }

    /* Gain: '<S131>/Gain3' */
    rtb_TmpSignalConversionAtMult_1 = -rtb_Saturation_j_idx_0;

    /* Switch: '<S132>/Switch' incorporates:
     *  Gain: '<S131>/Gain3'
     *  RelationalOperator: '<S132>/UpperRelop'
     */
    if (rtb_TmpSignalConversionAtMult_0 >= -rtb_Saturation_j_idx_0) {
      rtb_TmpSignalConversionAtMult_1 = rtb_TmpSignalConversionAtMult_0;
    }

    /* Switch: '<S132>/Switch2' incorporates:
     *  RelationalOperator: '<S132>/LowerRelop1'
     */
    if (rtb_TmpSignalConversionAtMult_0 <= rtb_Saturation_j_idx_0) {
      rtb_Saturation_j_idx_0 = rtb_TmpSignalConversionAtMult_1;
    }

    /* Saturate: '<S112>/Saturation1' */
    if (rtb_Saturation_j_idx_0 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_Saturation_j_idx_0 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_Saturation_j_idx_0 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_Saturation_j_idx_0 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    rtb_Divide_m_idx_1 = rtb_Saturation_j_idx_0;

    /* Sum: '<S128>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S131>/Divide1'
     */
    rtb_Square_d = rtb_Divide_m_idx_2 - Controller_U.INS_Out.theta;

    /* Product: '<S131>/Divide1' incorporates:
     *  Abs: '<S131>/Abs'
     *  Constant: '<S131>/const2'
     */
    rtb_Saturation_j_idx_0 = fabsf(rtb_Square_d) / 0.002F;

    /* Product: '<S131>/Divide' incorporates:
     *  Constant: '<S129>/Constant2'
     *  Constant: '<S131>/const1'
     *  Math: '<S131>/Square'
     *  SignalConversion: '<S131>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_TmpSignalConversionAtMult_1 = 9.5993F / (CONTROL_PARAM.MC_PITCH_P *
      CONTROL_PARAM.MC_PITCH_P);

    /* Signum: '<S131>/Sign' */
    if (rtb_Square_d < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else if (rtb_Square_d > 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_0 = rtb_Square_d;
    }

    /* Switch: '<S131>/Switch' incorporates:
     *  Constant: '<S129>/Constant2'
     *  Gain: '<S131>/Gain1'
     *  Gain: '<S131>/Gain2'
     *  Logic: '<S131>/Logical Operator'
     *  Product: '<S131>/Divide'
     *  Product: '<S131>/Multiply'
     *  Product: '<S131>/Multiply1'
     *  Product: '<S131>/Multiply2'
     *  Product: '<S131>/Multiply3'
     *  RelationalOperator: '<S131>/Relational Operator'
     *  RelationalOperator: '<S131>/Relational Operator2'
     *  SignalConversion: '<S131>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S131>/Sqrt'
     *  Sum: '<S131>/Subtract'
     */
    if ((rtb_Square_d <= rtb_TmpSignalConversionAtMult_1) && (rtb_Square_d >=
         -rtb_TmpSignalConversionAtMult_1)) {
      rtb_TmpSignalConversionAtMult_0 = rtb_Square_d * CONTROL_PARAM.MC_PITCH_P;
    } else {
      rtb_TmpSignalConversionAtMult_0 *= sqrtf((rtb_TmpSignalConversionAtMult_0 *
        rtb_Square_d - 0.5F * rtb_TmpSignalConversionAtMult_1) *
        Controller_ConstB.Gain);
    }

    /* Gain: '<S131>/Gain3' */
    rtb_TmpSignalConversionAtMult_1 = -rtb_Saturation_j_idx_0;

    /* Switch: '<S132>/Switch' incorporates:
     *  Gain: '<S131>/Gain3'
     *  RelationalOperator: '<S132>/UpperRelop'
     */
    if (rtb_TmpSignalConversionAtMult_0 >= -rtb_Saturation_j_idx_0) {
      rtb_TmpSignalConversionAtMult_1 = rtb_TmpSignalConversionAtMult_0;
    }

    /* Switch: '<S132>/Switch2' incorporates:
     *  RelationalOperator: '<S132>/LowerRelop1'
     */
    if (rtb_TmpSignalConversionAtMult_0 <= rtb_Saturation_j_idx_0) {
      rtb_Saturation_j_idx_0 = rtb_TmpSignalConversionAtMult_1;
    }

    /* Saturate: '<S112>/Saturation1' */
    if (rtb_Saturation_j_idx_0 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_Saturation_j_idx_0 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_Saturation_j_idx_0 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_Saturation_j_idx_0 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    /* Saturate: '<S112>/Saturation' */
    if (Controller_U.FMS_Out.psi_rate_cmd > CONTROL_PARAM.MC_R_CMD_LIM) {
      rtb_Add3_fc = CONTROL_PARAM.MC_R_CMD_LIM;
    } else if (Controller_U.FMS_Out.psi_rate_cmd < -CONTROL_PARAM.MC_R_CMD_LIM)
    {
      rtb_Add3_fc = -CONTROL_PARAM.MC_R_CMD_LIM;
    } else {
      rtb_Add3_fc = Controller_U.FMS_Out.psi_rate_cmd;
    }

    /* End of Saturate: '<S112>/Saturation' */

    /* Trigonometry: '<S122>/Sin' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Gain_c4 = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S122>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Saturation_g = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Product: '<S122>/Multiply3' incorporates:
     *  Trigonometry: '<S122>/Cos1'
     *  Trigonometry: '<S122>/Sin'
     */
    rtb_TmpSignalConversionAtMult_0 = rtb_Gain_c4 * rtb_Saturation_g *
      rtb_Add3_fc;

    /* Trigonometry: '<S122>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_TmpSignalConversionAtMult_1 = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Product: '<S122>/Multiply1' incorporates:
     *  Trigonometry: '<S122>/Cos'
     */
    rtb_TmpSignalConversionAtMult_2 = rtb_TmpSignalConversionAtMult_1 *
      rtb_Saturation_j_idx_0;

    /* Product: '<S122>/Multiply4' incorporates:
     *  Trigonometry: '<S122>/Sin'
     */
    rtb_Gain_c4 *= rtb_Saturation_j_idx_0;

    /* Switch: '<S113>/Switch' incorporates:
     *  Constant: '<S123>/Constant'
     *  Constant: '<S124>/Constant'
     *  RelationalOperator: '<S123>/Compare'
     *  RelationalOperator: '<S124>/Compare'
     *  Switch: '<S113>/Switch1'
     */
    if (rtb_BitwiseAND_n == 2) {
      rtb_DiscreteTimeIntegrator1_k1[0] = Controller_U.FMS_Out.p_cmd;
      rtb_DiscreteTimeIntegrator1_k1[1] = Controller_U.FMS_Out.q_cmd;
      rtb_DiscreteTimeIntegrator1_k1[2] = Controller_U.FMS_Out.r_cmd;
    } else if (rtb_BitwiseAND_n == 6) {
      /* Switch: '<S125>/Switch' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Product: '<S122>/Multiply'
       *  Product: '<S122>/Multiply1'
       *  Product: '<S122>/Multiply5'
       *  S-Function (sfix_bitop): '<S125>/cmd_p valid'
       *  S-Function (sfix_bitop): '<S125>/cmd_q valid'
       *  S-Function (sfix_bitop): '<S125>/cmd_r valid'
       *  Sum: '<S122>/Add'
       *  Sum: '<S122>/Add1'
       *  Sum: '<S122>/Add2'
       *  Switch: '<S113>/Switch1'
       *  Trigonometry: '<S122>/Cos'
       *  Trigonometry: '<S122>/Cos1'
       *  Trigonometry: '<S122>/Sin1'
       */
      if ((Controller_U.FMS_Out.cmd_mask & 1) > 0) {
        rtb_DiscreteTimeIntegrator1_k1[0] = Controller_U.FMS_Out.p_cmd;
      } else {
        rtb_DiscreteTimeIntegrator1_k1[0] = rtb_Divide_m_idx_1 - arm_sin_f32
          (Controller_U.INS_Out.theta) * rtb_Add3_fc;
      }

      if ((Controller_U.FMS_Out.cmd_mask & 2) > 0) {
        rtb_DiscreteTimeIntegrator1_k1[1] = Controller_U.FMS_Out.q_cmd;
      } else {
        rtb_DiscreteTimeIntegrator1_k1[1] = rtb_TmpSignalConversionAtMult_0 +
          rtb_TmpSignalConversionAtMult_2;
      }

      if ((Controller_U.FMS_Out.cmd_mask & 4) > 0) {
        rtb_DiscreteTimeIntegrator1_k1[2] = Controller_U.FMS_Out.r_cmd;
      } else {
        rtb_DiscreteTimeIntegrator1_k1[2] = rtb_TmpSignalConversionAtMult_1 *
          rtb_Saturation_g * rtb_Add3_fc - rtb_Gain_c4;
      }

      /* End of Switch: '<S125>/Switch' */
    } else {
      /* Switch: '<S113>/Switch1' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Product: '<S122>/Multiply'
       *  Product: '<S122>/Multiply3'
       *  Product: '<S122>/Multiply5'
       *  Sum: '<S122>/Add'
       *  Sum: '<S122>/Add1'
       *  Sum: '<S122>/Add2'
       *  Trigonometry: '<S122>/Cos'
       *  Trigonometry: '<S122>/Cos1'
       *  Trigonometry: '<S122>/Sin1'
       */
      rtb_DiscreteTimeIntegrator1_k1[0] = rtb_Divide_m_idx_1 - arm_sin_f32
        (Controller_U.INS_Out.theta) * rtb_Add3_fc;
      rtb_DiscreteTimeIntegrator1_k1[1] = rtb_TmpSignalConversionAtMult_2 +
        rtb_TmpSignalConversionAtMult_0;
      rtb_DiscreteTimeIntegrator1_k1[2] = rtb_TmpSignalConversionAtMult_1 *
        rtb_Saturation_g * rtb_Add3_fc - rtb_Gain_c4;
    }

    /* End of Switch: '<S113>/Switch' */

    /* Sum: '<S114>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_TmpSignalConversionAtMult_0 = rtb_DiscreteTimeIntegrator1_k1[0] -
      Controller_U.INS_Out.p;
    rtb_TmpSignalConversionAtMult_1 = rtb_DiscreteTimeIntegrator1_k1[1] -
      Controller_U.INS_Out.q;
    rtb_TmpSignalConversionAtMult_2 = rtb_DiscreteTimeIntegrator1_k1[2] -
      Controller_U.INS_Out.r;

    /* DiscreteIntegrator: '<S117>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] =
        rtb_TmpSignalConversionAtMult_0;
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] =
        rtb_TmpSignalConversionAtMult_1;
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] =
        rtb_TmpSignalConversionAtMult_2;
    }

    /* DiscreteIntegrator: '<S121>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S117>/Discrete-Time Integrator5'
     */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_j != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[0] =
        Controller_DW.DiscreteTimeIntegrator5_DSTATE[0];
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[1] =
        Controller_DW.DiscreteTimeIntegrator5_DSTATE[1];
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[2] =
        Controller_DW.DiscreteTimeIntegrator5_DSTATE[2];
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_k != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[0] =
        Controller_DW.DiscreteTimeIntegrator5_DSTATE[0];
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[1] =
        Controller_DW.DiscreteTimeIntegrator5_DSTATE[1];
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[2] =
        Controller_DW.DiscreteTimeIntegrator5_DSTATE[2];
    }

    /* Gain: '<S121>/Gain' incorporates:
     *  DiscreteIntegrator: '<S117>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S121>/Discrete-Time Integrator1'
     *  Sum: '<S121>/Sum5'
     */
    rtb_DiscreteTimeIntegrator1_k1[0] =
      (Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] -
       Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[0]) * 188.49556F;
    rtb_DiscreteTimeIntegrator1_k1[1] =
      (Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] -
       Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[1]) * 188.49556F;
    rtb_DiscreteTimeIntegrator1_k1[2] =
      (Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] -
       Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[2]) * 188.49556F;

    /* Switch: '<S121>/Switch' incorporates:
     *  Gain: '<S121>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_Saturation_j_idx_0 = 0.0F;
      rtb_Saturation_j_idx_1 = 0.0F;
      rtb_Saturation_j_idx_2 = 0.0F;
    } else {
      rtb_Saturation_j_idx_0 = rtb_DiscreteTimeIntegrator1_k1[0];
      rtb_Saturation_j_idx_1 = rtb_DiscreteTimeIntegrator1_k1[1];
      rtb_Saturation_j_idx_2 = rtb_DiscreteTimeIntegrator1_k1[2];
    }

    /* End of Switch: '<S121>/Switch' */

    /* Product: '<S118>/Multiply' incorporates:
     *  Constant: '<S118>/gain1'
     */
    rtb_Saturation_ni = CONTROL_PARAM.MC_ROLL_RATE_D * rtb_Saturation_j_idx_0;

    /* Saturate: '<S118>/Saturation' */
    if (rtb_Saturation_ni > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Saturation_ni = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Saturation_ni < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Saturation_ni = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    rtb_Saturation_j_idx_0 = rtb_Saturation_ni;

    /* Product: '<S118>/Multiply' incorporates:
     *  Constant: '<S118>/gain2'
     */
    rtb_Saturation_ni = CONTROL_PARAM.MC_PITCH_RATE_D * rtb_Saturation_j_idx_1;

    /* Saturate: '<S118>/Saturation' */
    if (rtb_Saturation_ni > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Saturation_ni = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Saturation_ni < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Saturation_ni = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    rtb_Saturation_j_idx_1 = rtb_Saturation_ni;

    /* Product: '<S118>/Multiply' incorporates:
     *  Constant: '<S118>/gain3'
     */
    rtb_Saturation_ni = CONTROL_PARAM.MC_YAW_RATE_D * rtb_Saturation_j_idx_2;

    /* Saturate: '<S118>/Saturation' */
    if (rtb_Saturation_ni > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Saturation_ni = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Saturation_ni < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Saturation_ni = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    /* SignalConversion: '<S5>/BusConversion_InsertedFor_VTOL_actuator_cmd_at_inport_0' incorporates:
     *  Constant: '<S120>/gain1'
     *  Constant: '<S120>/gain2'
     *  Constant: '<S120>/gain3'
     *  DiscreteIntegrator: '<S117>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S119>/Discrete-Time Integrator'
     *  Product: '<S120>/Multiply'
     *  Sum: '<S115>/Add'
     */
    Controller_B.mc_torque_cmd[0] = (CONTROL_PARAM.MC_ROLL_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0]) + rtb_Saturation_j_idx_0;
    Controller_B.mc_torque_cmd[1] = (CONTROL_PARAM.MC_PITCH_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1]) + rtb_Saturation_j_idx_1;
    Controller_B.mc_torque_cmd[2] = (CONTROL_PARAM.MC_YAW_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[2]) + rtb_Saturation_ni;

    /* Product: '<S144>/Multiply1' incorporates:
     *  Constant: '<S144>/const1'
     *  DiscreteIntegrator: '<S141>/Integrator'
     */
    rtb_Gain_c4 = Controller_DW.Integrator_DSTATE[0] * 0.1F;
    rtb_Saturation_j_idx_1 = Controller_DW.Integrator_DSTATE[1] * 0.1F;

    /* Sum: '<S144>/Add' incorporates:
     *  DiscreteIntegrator: '<S141>/Integrator1'
     *  Sum: '<S141>/Subtract'
     */
    rtb_Divide_m_idx_1 = (Controller_DW.Integrator1_DSTATE[0] -
                          Controller_U.FMS_Out.u_cmd) + rtb_Gain_c4;
    rtb_Divide_m_idx_2 = (Controller_DW.Integrator1_DSTATE[1] -
                          Controller_U.FMS_Out.v_cmd) + rtb_Saturation_j_idx_1;

    /* Signum: '<S144>/Sign' */
    if (rtb_Divide_m_idx_1 < 0.0F) {
      rtb_Square_d = -1.0F;
    } else if (rtb_Divide_m_idx_1 > 0.0F) {
      rtb_Square_d = 1.0F;
    } else {
      rtb_Square_d = rtb_Divide_m_idx_1;
    }

    /* Sum: '<S144>/Add2' incorporates:
     *  Abs: '<S144>/Abs'
     *  Gain: '<S144>/Gain'
     *  Gain: '<S144>/Gain1'
     *  Product: '<S144>/Multiply2'
     *  Product: '<S144>/Multiply3'
     *  Signum: '<S144>/Sign'
     *  Sqrt: '<S144>/Sqrt'
     *  Sum: '<S144>/Add1'
     *  Sum: '<S144>/Subtract'
     */
    rtb_Saturation_j_idx_0 = (sqrtf((8.0F * fabsf(rtb_Divide_m_idx_1) +
      Controller_ConstB.d) * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
      rtb_Square_d + rtb_Gain_c4;

    /* Sum: '<S144>/Add3' incorporates:
     *  Signum: '<S144>/Sign'
     */
    rtb_Add3_fc = rtb_Divide_m_idx_1 + Controller_ConstB.d;

    /* Sum: '<S144>/Subtract1' incorporates:
     *  Signum: '<S144>/Sign'
     */
    rtb_Square_d = rtb_Divide_m_idx_1 - Controller_ConstB.d;

    /* Signum: '<S144>/Sign1' */
    if (rtb_Add3_fc < 0.0F) {
      rtb_Add3_fc = -1.0F;
    } else {
      if (rtb_Add3_fc > 0.0F) {
        rtb_Add3_fc = 1.0F;
      }
    }

    /* Signum: '<S144>/Sign2' */
    if (rtb_Square_d < 0.0F) {
      rtb_Square_d = -1.0F;
    } else {
      if (rtb_Square_d > 0.0F) {
        rtb_Square_d = 1.0F;
      }
    }

    /* Sum: '<S144>/Add2' incorporates:
     *  Gain: '<S144>/Gain2'
     *  Product: '<S144>/Multiply4'
     *  Signum: '<S144>/Sign'
     *  Sum: '<S144>/Add4'
     *  Sum: '<S144>/Add5'
     *  Sum: '<S144>/Subtract2'
     */
    rtb_Divide_m_idx_1 = ((rtb_Divide_m_idx_1 - rtb_Saturation_j_idx_0) +
                          rtb_Gain_c4) * ((rtb_Add3_fc - rtb_Square_d) * 0.5F) +
      rtb_Saturation_j_idx_0;

    /* Signum: '<S144>/Sign' */
    if (rtb_Divide_m_idx_2 < 0.0F) {
      rtb_Square_d = -1.0F;
    } else if (rtb_Divide_m_idx_2 > 0.0F) {
      rtb_Square_d = 1.0F;
    } else {
      rtb_Square_d = rtb_Divide_m_idx_2;
    }

    /* Sum: '<S144>/Add2' incorporates:
     *  Abs: '<S144>/Abs'
     *  Gain: '<S144>/Gain'
     *  Gain: '<S144>/Gain1'
     *  Product: '<S144>/Multiply2'
     *  Product: '<S144>/Multiply3'
     *  Signum: '<S144>/Sign'
     *  Sqrt: '<S144>/Sqrt'
     *  Sum: '<S144>/Add1'
     *  Sum: '<S144>/Subtract'
     */
    rtb_Saturation_j_idx_0 = (sqrtf((8.0F * fabsf(rtb_Divide_m_idx_2) +
      Controller_ConstB.d) * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
      rtb_Square_d + rtb_Saturation_j_idx_1;

    /* Sum: '<S144>/Add3' incorporates:
     *  Signum: '<S144>/Sign'
     */
    rtb_Add3_fc = rtb_Divide_m_idx_2 + Controller_ConstB.d;

    /* Sum: '<S144>/Subtract1' incorporates:
     *  Signum: '<S144>/Sign'
     */
    rtb_Square_d = rtb_Divide_m_idx_2 - Controller_ConstB.d;

    /* Signum: '<S144>/Sign1' */
    if (rtb_Add3_fc < 0.0F) {
      rtb_Add3_fc = -1.0F;
    } else {
      if (rtb_Add3_fc > 0.0F) {
        rtb_Add3_fc = 1.0F;
      }
    }

    /* Signum: '<S144>/Sign2' */
    if (rtb_Square_d < 0.0F) {
      rtb_Square_d = -1.0F;
    } else {
      if (rtb_Square_d > 0.0F) {
        rtb_Square_d = 1.0F;
      }
    }

    /* Sum: '<S144>/Add5' incorporates:
     *  Gain: '<S144>/Gain2'
     *  Product: '<S144>/Multiply4'
     *  Signum: '<S144>/Sign'
     *  Sum: '<S144>/Add2'
     *  Sum: '<S144>/Add4'
     *  Sum: '<S144>/Subtract2'
     */
    rtb_Saturation_j_idx_0 += ((rtb_Divide_m_idx_2 - rtb_Saturation_j_idx_0) +
      rtb_Saturation_j_idx_1) * ((rtb_Add3_fc - rtb_Square_d) * 0.5F);

    /* Gain: '<S162>/Gain' incorporates:
     *  DiscreteIntegrator: '<S164>/Integrator1'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S162>/Sum1'
     */
    rtb_Divide_m_idx_2 = -(Controller_DW.Integrator1_DSTATE_e -
      Controller_U.INS_Out.vd);
    Controller_B.Constant = CONTROL_PARAM.MC_VEL_Z_I_MIN;

    /* DiscreteIntegrator: '<S167>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S167>/Constant'
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

    /* DiscreteIntegrator: '<S169>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_d != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i = rtb_Divide_m_idx_2;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_Prev_ks != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i = rtb_Divide_m_idx_2;
    }

    /* Gain: '<S169>/Gain' incorporates:
     *  DiscreteIntegrator: '<S169>/Discrete-Time Integrator1'
     *  Sum: '<S169>/Sum5'
     */
    rtb_Square_d = (rtb_Divide_m_idx_2 -
                    Controller_DW.DiscreteTimeIntegrator1_DSTAT_i) * 62.831852F;

    /* Switch: '<S158>/Switch' incorporates:
     *  Constant: '<S160>/Constant'
     *  RelationalOperator: '<S160>/Compare'
     */
    if (rtb_BitwiseAND_n <= 3) {
      /* SignalConversion: '<S5>/BusConversion_InsertedFor_VTOL_actuator_cmd_at_inport_0' incorporates:
       *  Bias: '<S158>/Bias'
       *  Gain: '<S158>/Gain'
       */
      Controller_B.mc_force_cmd[2] = 0.000999987125F * (real32_T)
        Controller_U.FMS_Out.throttle_cmd + -1.0F;
    } else {
      /* Product: '<S161>/Multiply' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S161>/Cos'
       *  Trigonometry: '<S161>/Cos1'
       */
      rtb_Saturation_g = arm_cos_f32(Controller_U.INS_Out.phi) * arm_cos_f32
        (Controller_U.INS_Out.theta);

      /* Gain: '<S161>/Gain' */
      rtb_Add3_fc = 2.0F * rtb_Saturation_g;

      /* Saturate: '<S161>/Saturation1' */
      if (rtb_Saturation_g > 1.0F) {
        rtb_Saturation_g = 1.0F;
      } else {
        if (rtb_Saturation_g < 0.5F) {
          rtb_Saturation_g = 0.5F;
        }
      }

      /* End of Saturate: '<S161>/Saturation1' */

      /* Product: '<S161>/Divide' incorporates:
       *  Constant: '<S161>/Constant'
       */
      rtb_Gain_c4 = 1.0F / rtb_Saturation_g;

      /* Switch: '<S169>/Switch' incorporates:
       *  Gain: '<S169>/Gain1'
       */
      if (Controller_U.FMS_Out.reset > 0) {
        rtb_Saturation_j_idx_1 = 0.0F;
      } else {
        rtb_Saturation_j_idx_1 = rtb_Square_d;
      }

      /* End of Switch: '<S169>/Switch' */

      /* Product: '<S166>/Multiply' incorporates:
       *  Constant: '<S166>/kd'
       */
      rtb_Saturation_g = CONTROL_PARAM.MC_VEL_Z_D * rtb_Saturation_j_idx_1;

      /* Saturate: '<S166>/Saturation' */
      if (rtb_Saturation_g > CONTROL_PARAM.MC_VEL_Z_D_MAX) {
        rtb_Saturation_g = CONTROL_PARAM.MC_VEL_Z_D_MAX;
      } else {
        if (rtb_Saturation_g < CONTROL_PARAM.MC_VEL_Z_D_MIN) {
          rtb_Saturation_g = CONTROL_PARAM.MC_VEL_Z_D_MIN;
        }
      }

      /* End of Saturate: '<S166>/Saturation' */

      /* Saturate: '<S161>/Saturation' */
      if (rtb_Add3_fc > 1.0F) {
        rtb_Add3_fc = 1.0F;
      } else {
        if (rtb_Add3_fc < 0.0F) {
          rtb_Add3_fc = 0.0F;
        }
      }

      /* End of Saturate: '<S161>/Saturation' */

      /* Product: '<S161>/Multiply1' incorporates:
       *  Constant: '<S168>/kp'
       *  DiscreteIntegrator: '<S167>/Discrete-Time Integrator'
       *  Product: '<S168>/Multiply'
       *  Sum: '<S163>/Add'
       */
      rtb_Gain_c4 = ((CONTROL_PARAM.MC_VEL_Z_P * rtb_Divide_m_idx_2 +
                      Controller_DW.DiscreteTimeIntegrator_DSTATE_l) +
                     rtb_Saturation_g) * rtb_Gain_c4 * rtb_Add3_fc;

      /* Saturate: '<S159>/Saturation' */
      if (rtb_Gain_c4 > 0.35F) {
        rtb_Gain_c4 = 0.35F;
      } else {
        if (rtb_Gain_c4 < -0.35F) {
          rtb_Gain_c4 = -0.35F;
        }
      }

      /* End of Saturate: '<S159>/Saturation' */

      /* SignalConversion: '<S5>/BusConversion_InsertedFor_VTOL_actuator_cmd_at_inport_0' incorporates:
       *  Constant: '<S159>/hover_throttle'
       *  Sum: '<S159>/Sum'
       */
      Controller_B.mc_force_cmd[2] = rtb_Gain_c4 + CONTROL_PARAM.MC_HOVER_THRO;
    }

    /* End of Switch: '<S158>/Switch' */

    /* SignalConversion: '<S5>/BusConversion_InsertedFor_VTOL_actuator_cmd_at_inport_0' */
    Controller_B.mc_force_cmd[0] = Controller_ConstB.TmpBufferAtConstantOutport1;
    Controller_B.mc_force_cmd[1] = Controller_ConstB.TmpBufferAtConstantOutport1;

    /* Product: '<S165>/Multiply1' incorporates:
     *  Constant: '<S165>/const1'
     *  DiscreteIntegrator: '<S164>/Integrator'
     */
    rtb_Add3_fc = Controller_DW.Integrator_DSTATE_j * 0.05F;

    /* Sum: '<S165>/Add' incorporates:
     *  DiscreteIntegrator: '<S164>/Integrator1'
     *  Sum: '<S164>/Subtract'
     */
    rtb_Saturation_g = (Controller_DW.Integrator1_DSTATE_e -
                        Controller_U.FMS_Out.w_cmd) + rtb_Add3_fc;

    /* Signum: '<S165>/Sign' */
    if (rtb_Saturation_g < 0.0F) {
      rtb_Gain_c4 = -1.0F;
    } else if (rtb_Saturation_g > 0.0F) {
      rtb_Gain_c4 = 1.0F;
    } else {
      rtb_Gain_c4 = rtb_Saturation_g;
    }

    /* End of Signum: '<S165>/Sign' */

    /* Sum: '<S165>/Add2' incorporates:
     *  Abs: '<S165>/Abs'
     *  Gain: '<S165>/Gain'
     *  Gain: '<S165>/Gain1'
     *  Product: '<S165>/Multiply2'
     *  Product: '<S165>/Multiply3'
     *  Sqrt: '<S165>/Sqrt'
     *  Sum: '<S165>/Add1'
     *  Sum: '<S165>/Subtract'
     */
    rtb_Gain_c4 = (sqrtf((8.0F * fabsf(rtb_Saturation_g) + Controller_ConstB.d_i)
                         * Controller_ConstB.d_i) - Controller_ConstB.d_i) *
      0.5F * rtb_Gain_c4 + rtb_Add3_fc;

    /* Sum: '<S165>/Add4' */
    rtb_phi_cmd = (rtb_Saturation_g - rtb_Gain_c4) + rtb_Add3_fc;

    /* Sum: '<S165>/Add3' */
    rtb_Add3_fc = rtb_Saturation_g + Controller_ConstB.d_i;

    /* Sum: '<S165>/Subtract1' */
    rtb_Saturation_g -= Controller_ConstB.d_i;

    /* Signum: '<S165>/Sign1' */
    if (rtb_Add3_fc < 0.0F) {
      rtb_Add3_fc = -1.0F;
    } else {
      if (rtb_Add3_fc > 0.0F) {
        rtb_Add3_fc = 1.0F;
      }
    }

    /* End of Signum: '<S165>/Sign1' */

    /* Signum: '<S165>/Sign2' */
    if (rtb_Saturation_g < 0.0F) {
      rtb_Saturation_g = -1.0F;
    } else {
      if (rtb_Saturation_g > 0.0F) {
        rtb_Saturation_g = 1.0F;
      }
    }

    /* End of Signum: '<S165>/Sign2' */

    /* Sum: '<S165>/Add5' incorporates:
     *  Gain: '<S165>/Gain2'
     *  Product: '<S165>/Multiply4'
     *  Sum: '<S165>/Subtract2'
     */
    rtb_Gain_c4 += (rtb_Add3_fc - rtb_Saturation_g) * 0.5F * rtb_phi_cmd;

    /* Update for DiscreteIntegrator: '<S119>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S119>/gain1'
     *  Constant: '<S119>/gain2'
     *  Constant: '<S119>/gain3'
     *  DiscreteIntegrator: '<S117>/Discrete-Time Integrator5'
     *  Product: '<S119>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] +=
      CONTROL_PARAM.MC_ROLL_RATE_I *
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] * 0.002F;
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
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] * 0.002F;
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
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] * 0.002F;
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

    /* End of Update for DiscreteIntegrator: '<S119>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S146>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_PrevRe_p = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S148>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;

    /* Update for DiscreteIntegrator: '<S141>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S141>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE[0] += 0.002F *
      Controller_DW.Integrator_DSTATE[0];

    /* Update for DiscreteIntegrator: '<S146>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S146>/ki'
     *  Product: '<S146>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0] +=
      CONTROL_PARAM.MC_VEL_XY_I * rtb_aux_att_error_B_rad_idx_0 * 0.002F;
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

    /* Update for DiscreteIntegrator: '<S148>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] += 0.002F *
      rtb_Divide_m_idx_3;

    /* Update for DiscreteIntegrator: '<S141>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S141>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE[1] += 0.002F *
      Controller_DW.Integrator_DSTATE[1];

    /* Update for DiscreteIntegrator: '<S146>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S146>/ki'
     *  Product: '<S146>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1] +=
      CONTROL_PARAM.MC_VEL_XY_I * rtb_aux_att_error_B_rad_idx_1 * 0.002F;
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

    /* Update for DiscreteIntegrator: '<S148>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] += 0.002F *
      rtb_Divide_m_idx_0;
    Controller_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S117>/Discrete-Time Integrator5' */
    Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;

    /* Update for DiscreteIntegrator: '<S121>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 0U;

    /* Update for DiscreteIntegrator: '<S117>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S117>/Gain'
     *  Sum: '<S117>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] +=
      (rtb_TmpSignalConversionAtMult_0 -
       Controller_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S121>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[0] += 0.002F *
      rtb_DiscreteTimeIntegrator1_k1[0];

    /* Update for DiscreteIntegrator: '<S117>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S117>/Gain'
     *  Sum: '<S117>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] +=
      (rtb_TmpSignalConversionAtMult_1 -
       Controller_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S121>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[1] += 0.002F *
      rtb_DiscreteTimeIntegrator1_k1[1];

    /* Update for DiscreteIntegrator: '<S117>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S117>/Gain'
     *  Sum: '<S117>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] +=
      (rtb_TmpSignalConversionAtMult_2 -
       Controller_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S121>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[2] += 0.002F *
      rtb_DiscreteTimeIntegrator1_k1[2];
    Controller_DW.DiscreteTimeIntegrator1_PrevR_k = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Signum: '<S144>/Sign3' incorporates:
     *  Product: '<S144>/Divide'
     *  Sum: '<S144>/Add6'
     */
    rtb_Add3_fc = rtb_Divide_m_idx_1 + Controller_ConstB.d;

    /* Signum: '<S144>/Sign4' incorporates:
     *  Product: '<S144>/Divide'
     *  Sum: '<S144>/Subtract3'
     */
    rtb_TmpSignalConversionAtMult_0 = rtb_Divide_m_idx_1 - Controller_ConstB.d;

    /* Signum: '<S144>/Sign5' incorporates:
     *  Product: '<S144>/Divide'
     */
    if (rtb_Divide_m_idx_1 < 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = -1.0F;
    } else if (rtb_Divide_m_idx_1 > 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_1 = rtb_Divide_m_idx_1;
    }

    /* Signum: '<S144>/Sign3' */
    if (rtb_Add3_fc < 0.0F) {
      rtb_Add3_fc = -1.0F;
    } else {
      if (rtb_Add3_fc > 0.0F) {
        rtb_Add3_fc = 1.0F;
      }
    }

    /* Signum: '<S144>/Sign4' */
    if (rtb_TmpSignalConversionAtMult_0 < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else {
      if (rtb_TmpSignalConversionAtMult_0 > 0.0F) {
        rtb_TmpSignalConversionAtMult_0 = 1.0F;
      }
    }

    /* Signum: '<S144>/Sign6' incorporates:
     *  Product: '<S144>/Divide'
     */
    if (rtb_Divide_m_idx_1 < 0.0F) {
      rtb_TmpSignalConversionAtMult_2 = -1.0F;
    } else if (rtb_Divide_m_idx_1 > 0.0F) {
      rtb_TmpSignalConversionAtMult_2 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_2 = rtb_Divide_m_idx_1;
    }

    /* Update for DiscreteIntegrator: '<S141>/Integrator' incorporates:
     *  Constant: '<S144>/const'
     *  Gain: '<S144>/Gain3'
     *  Product: '<S144>/Divide'
     *  Product: '<S144>/Multiply5'
     *  Product: '<S144>/Multiply6'
     *  Sum: '<S144>/Subtract4'
     *  Sum: '<S144>/Subtract5'
     *  Sum: '<S144>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE[0] += ((rtb_Divide_m_idx_1 /
      Controller_ConstB.d - rtb_TmpSignalConversionAtMult_1) *
      Controller_ConstB.Gain4 * ((rtb_Add3_fc - rtb_TmpSignalConversionAtMult_0)
      * 0.5F) - rtb_TmpSignalConversionAtMult_2 * 78.448F) * 0.002F;

    /* Signum: '<S144>/Sign3' incorporates:
     *  Sum: '<S144>/Add6'
     */
    rtb_Add3_fc = rtb_Saturation_j_idx_0 + Controller_ConstB.d;

    /* Signum: '<S144>/Sign4' incorporates:
     *  Sum: '<S144>/Subtract3'
     */
    rtb_TmpSignalConversionAtMult_0 = rtb_Saturation_j_idx_0 -
      Controller_ConstB.d;

    /* Signum: '<S144>/Sign5' */
    if (rtb_Saturation_j_idx_0 < 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = -1.0F;
    } else if (rtb_Saturation_j_idx_0 > 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_1 = rtb_Saturation_j_idx_0;
    }

    /* Signum: '<S144>/Sign3' */
    if (rtb_Add3_fc < 0.0F) {
      rtb_Add3_fc = -1.0F;
    } else {
      if (rtb_Add3_fc > 0.0F) {
        rtb_Add3_fc = 1.0F;
      }
    }

    /* Signum: '<S144>/Sign4' */
    if (rtb_TmpSignalConversionAtMult_0 < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else {
      if (rtb_TmpSignalConversionAtMult_0 > 0.0F) {
        rtb_TmpSignalConversionAtMult_0 = 1.0F;
      }
    }

    /* Signum: '<S144>/Sign6' */
    if (rtb_Saturation_j_idx_0 < 0.0F) {
      rtb_TmpSignalConversionAtMult_2 = -1.0F;
    } else if (rtb_Saturation_j_idx_0 > 0.0F) {
      rtb_TmpSignalConversionAtMult_2 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_2 = rtb_Saturation_j_idx_0;
    }

    /* Update for DiscreteIntegrator: '<S141>/Integrator' incorporates:
     *  Constant: '<S144>/const'
     *  Gain: '<S144>/Gain3'
     *  Product: '<S144>/Divide'
     *  Product: '<S144>/Multiply5'
     *  Product: '<S144>/Multiply6'
     *  Sum: '<S144>/Subtract4'
     *  Sum: '<S144>/Subtract5'
     *  Sum: '<S144>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE[1] += ((rtb_Saturation_j_idx_0 /
      Controller_ConstB.d - rtb_TmpSignalConversionAtMult_1) *
      Controller_ConstB.Gain4 * ((rtb_Add3_fc - rtb_TmpSignalConversionAtMult_0)
      * 0.5F) - rtb_TmpSignalConversionAtMult_2 * 78.448F) * 0.002F;

    /* Update for DiscreteIntegrator: '<S164>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S164>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_e += 0.002F *
      Controller_DW.Integrator_DSTATE_j;

    /* Update for DiscreteIntegrator: '<S167>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S167>/ki'
     *  Product: '<S167>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_l += CONTROL_PARAM.MC_VEL_Z_I *
      rtb_Divide_m_idx_2 * 0.002F;
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

    /* End of Update for DiscreteIntegrator: '<S167>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S169>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_i += 0.002F * rtb_Square_d;
    Controller_DW.DiscreteTimeIntegrator1_Prev_ks = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Signum: '<S165>/Sign6' incorporates:
     *  Signum: '<S165>/Sign5'
     */
    if (rtb_Gain_c4 < 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = -1.0F;

      /* Signum: '<S165>/Sign5' */
      rtb_TmpSignalConversionAtMult_2 = -1.0F;
    } else if (rtb_Gain_c4 > 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = 1.0F;

      /* Signum: '<S165>/Sign5' */
      rtb_TmpSignalConversionAtMult_2 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_1 = rtb_Gain_c4;

      /* Signum: '<S165>/Sign5' */
      rtb_TmpSignalConversionAtMult_2 = rtb_Gain_c4;
    }

    /* End of Signum: '<S165>/Sign6' */

    /* Sum: '<S165>/Add6' */
    rtb_Add3_fc = rtb_Gain_c4 + Controller_ConstB.d_i;

    /* Sum: '<S165>/Subtract3' */
    rtb_TmpSignalConversionAtMult_0 = rtb_Gain_c4 - Controller_ConstB.d_i;

    /* Signum: '<S165>/Sign3' */
    if (rtb_Add3_fc < 0.0F) {
      rtb_Add3_fc = -1.0F;
    } else {
      if (rtb_Add3_fc > 0.0F) {
        rtb_Add3_fc = 1.0F;
      }
    }

    /* End of Signum: '<S165>/Sign3' */

    /* Signum: '<S165>/Sign4' */
    if (rtb_TmpSignalConversionAtMult_0 < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else {
      if (rtb_TmpSignalConversionAtMult_0 > 0.0F) {
        rtb_TmpSignalConversionAtMult_0 = 1.0F;
      }
    }

    /* End of Signum: '<S165>/Sign4' */

    /* Update for DiscreteIntegrator: '<S164>/Integrator' incorporates:
     *  Constant: '<S165>/const'
     *  Gain: '<S165>/Gain3'
     *  Product: '<S165>/Divide'
     *  Product: '<S165>/Multiply5'
     *  Product: '<S165>/Multiply6'
     *  Sum: '<S165>/Subtract4'
     *  Sum: '<S165>/Subtract5'
     *  Sum: '<S165>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE_j += ((rtb_Gain_c4 / Controller_ConstB.d_i -
      rtb_TmpSignalConversionAtMult_2) * Controller_ConstB.Gain4_p *
      ((rtb_Add3_fc - rtb_TmpSignalConversionAtMult_0) * 0.5F) -
      rtb_TmpSignalConversionAtMult_1 * 78.448F) * 0.002F;

    /* End of Outputs for SubSystem: '<S2>/MC_Controller' */
    break;
  }

  /* End of SwitchCase: '<S8>/Switch Case1' */

  /* Outputs for Atomic SubSystem: '<S6>/VTOL_Control_Allocation' */
#if AIRFRAME == 1

  /* Output and update for atomic system: '<S171>/VTOL1' */
  {
    real32_T rtb_MatrixConcatenate[12];
    uint16_T rtb_DataTypeConversion_i;
    real32_T rtb_Multiply_fw[4];
    real32_T rtb_Saturation_fa[9];
    int32_T i_p;
    uint16_T tmp_p[5];
    real32_T tmp_c;
    real32_T tmp_d;
    real32_T tmp_nk;
    uint16_T u0_p;
    real32_T tmp_a;

    /* Saturate: '<S181>/Saturation' incorporates:
     *  Bias: '<S181>/Bias'
     *  Bias: '<S181>/Bias1'
     *  Bias: '<S181>/Bias2'
     *  Bias: '<S181>/Bias3'
     *  Constant: '<S181>/Constant'
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

    /* End of Saturate: '<S181>/Saturation' */

    /* MultiPortSwitch: '<S176>/Multiport Switch' incorporates:
     *  Constant: '<S177>/Constant1'
     *  Constant: '<S177>/Constant12'
     *  Constant: '<S177>/Constant2'
     *  Constant: '<S177>/Constant7'
     *  DataTypeConversion: '<S181>/Data Type Conversion'
     *  DataTypeConversion: '<S182>/Data Type Conversion'
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
        /* Saturate: '<S182>/Saturation' incorporates:
         *  Constant: '<S182>/Disarm'
         *  Reshape: '<S182>/Reshape'
         */
        if (Controller_ConstP.pooled7[i_p] > 2000.0F) {
          tmp_a = 2000.0F;
        } else if (Controller_ConstP.pooled7[i_p] < 1000.0F) {
          tmp_a = 1000.0F;
        } else {
          tmp_a = Controller_ConstP.pooled7[i_p];
        }

        rtb_VariantMergeForOutportactua[i_p] = (uint16_T)fmodf(floorf(tmp_a),
          65536.0F);
      }

      /* Saturate: '<S182>/Saturation' incorporates:
       *  Bias: '<S182>/Bias'
       *  Constant: '<S182>/Constant'
       *  DataTypeConversion: '<S182>/Data Type Conversion'
       */
      if (1500.0F + CONTROL_PARAM.SERVO1_BIAS > 2000.0F) {
        tmp_a = 2000.0F;
      } else if (1500.0F + CONTROL_PARAM.SERVO1_BIAS < 1000.0F) {
        tmp_a = 1000.0F;
      } else {
        tmp_a = 1500.0F + CONTROL_PARAM.SERVO1_BIAS;
      }

      rtb_VariantMergeForOutportactua[5] = (uint16_T)fmodf(floorf(tmp_a),
        65536.0F);

      /* Saturate: '<S182>/Saturation' incorporates:
       *  Bias: '<S182>/Bias1'
       *  Constant: '<S182>/Constant'
       *  DataTypeConversion: '<S182>/Data Type Conversion'
       */
      if (1500.0F + CONTROL_PARAM.SERVO2_BIAS > 2000.0F) {
        tmp_a = 2000.0F;
      } else if (1500.0F + CONTROL_PARAM.SERVO2_BIAS < 1000.0F) {
        tmp_a = 1000.0F;
      } else {
        tmp_a = 1500.0F + CONTROL_PARAM.SERVO2_BIAS;
      }

      rtb_VariantMergeForOutportactua[6] = (uint16_T)fmodf(floorf(tmp_a),
        65536.0F);

      /* Saturate: '<S182>/Saturation' incorporates:
       *  Bias: '<S182>/Bias2'
       *  Constant: '<S182>/Constant'
       *  DataTypeConversion: '<S182>/Data Type Conversion'
       */
      if (1500.0F + CONTROL_PARAM.SERVO3_BIAS > 2000.0F) {
        tmp_a = 2000.0F;
      } else if (1500.0F + CONTROL_PARAM.SERVO3_BIAS < 1000.0F) {
        tmp_a = 1000.0F;
      } else {
        tmp_a = 1500.0F + CONTROL_PARAM.SERVO3_BIAS;
      }

      rtb_VariantMergeForOutportactua[7] = (uint16_T)fmodf(floorf(tmp_a),
        65536.0F);

      /* Saturate: '<S182>/Saturation' incorporates:
       *  Bias: '<S182>/Bias3'
       *  Constant: '<S182>/Constant'
       *  DataTypeConversion: '<S182>/Data Type Conversion'
       */
      if (1500.0F + CONTROL_PARAM.SERVO4_BIAS > 2000.0F) {
        tmp_a = 2000.0F;
      } else if (1500.0F + CONTROL_PARAM.SERVO4_BIAS < 1000.0F) {
        tmp_a = 1000.0F;
      } else {
        tmp_a = 1500.0F + CONTROL_PARAM.SERVO4_BIAS;
      }

      rtb_VariantMergeForOutportactua[8] = (uint16_T)fmodf(floorf(tmp_a),
        65536.0F);
      break;

     case 3:
      rtb_MatrixConcatenate[11] = CONTROL_PARAM.FW_YAW_EFFC *
        CONTROL_PARAM.FW_RUDDER_DIR;

      /* SignalConversion: '<S177>/ConcatBufferAtVector Concatenate2In3' incorporates:
       *  Constant: '<S177>/Constant11'
       *  Constant: '<S177>/Constant12'
       */
      rtb_MatrixConcatenate[10] = 0.0F;

      /* SignalConversion: '<S177>/ConcatBufferAtVector Concatenate2In2' incorporates:
       *  Constant: '<S177>/Constant10'
       */
      rtb_MatrixConcatenate[9] = 0.0F;

      /* SignalConversion: '<S177>/ConcatBufferAtVector Concatenate2In1' incorporates:
       *  Constant: '<S177>/Constant9'
       */
      rtb_MatrixConcatenate[8] = 0.0F;

      /* SignalConversion: '<S177>/ConcatBufferAtVector Concatenate1In4' incorporates:
       *  Constant: '<S177>/Constant8'
       */
      rtb_MatrixConcatenate[7] = 0.0F;
      rtb_MatrixConcatenate[6] = CONTROL_PARAM.FW_PITCH_EFFC *
        CONTROL_PARAM.FW_ELEVATOR_DIR;

      /* SignalConversion: '<S177>/ConcatBufferAtVector Concatenate1In2' incorporates:
       *  Constant: '<S177>/Constant6'
       *  Constant: '<S177>/Constant7'
       */
      rtb_MatrixConcatenate[5] = 0.0F;

      /* SignalConversion: '<S177>/ConcatBufferAtVector Concatenate1In1' incorporates:
       *  Constant: '<S177>/Constant5'
       */
      rtb_MatrixConcatenate[4] = 0.0F;

      /* SignalConversion: '<S177>/ConcatBufferAtVector ConcatenateIn4' incorporates:
       *  Constant: '<S177>/Constant4'
       */
      rtb_MatrixConcatenate[3] = 0.0F;

      /* SignalConversion: '<S177>/ConcatBufferAtVector ConcatenateIn3' incorporates:
       *  Constant: '<S177>/Constant3'
       */
      rtb_MatrixConcatenate[2] = 0.0F;
      rtb_MatrixConcatenate[1] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON2_DIR;
      rtb_MatrixConcatenate[0] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON1_DIR;

      /* Saturate: '<S174>/Saturation5' incorporates:
       *  Constant: '<S177>/Constant1'
       *  Constant: '<S177>/Constant2'
       */
      if (Controller_B.fw_torque_cmd[0] > 1.0F) {
        /* Product: '<S174>/Multiply1' */
        tmp_c = 1.0F;
      } else if (Controller_B.fw_torque_cmd[0] < -1.0F) {
        /* Product: '<S174>/Multiply1' */
        tmp_c = -1.0F;
      } else {
        /* Product: '<S174>/Multiply1' */
        tmp_c = Controller_B.fw_torque_cmd[0];
      }

      if (Controller_B.fw_torque_cmd[1] > 1.0F) {
        /* Product: '<S174>/Multiply1' */
        tmp_d = 1.0F;
      } else if (Controller_B.fw_torque_cmd[1] < -1.0F) {
        /* Product: '<S174>/Multiply1' */
        tmp_d = -1.0F;
      } else {
        /* Product: '<S174>/Multiply1' */
        tmp_d = Controller_B.fw_torque_cmd[1];
      }

      if (Controller_B.fw_torque_cmd[2] > 1.0F) {
        /* Product: '<S174>/Multiply1' */
        tmp_nk = 1.0F;
      } else if (Controller_B.fw_torque_cmd[2] < -1.0F) {
        /* Product: '<S174>/Multiply1' */
        tmp_nk = -1.0F;
      } else {
        /* Product: '<S174>/Multiply1' */
        tmp_nk = Controller_B.fw_torque_cmd[2];
      }

      /* End of Saturate: '<S174>/Saturation5' */
      for (i_p = 0; i_p < 4; i_p++) {
        /* Bias: '<S174>/Bias' incorporates:
         *  Gain: '<S174>/Gain1'
         *  Product: '<S174>/Multiply1'
         */
        rtb_Multiply_fw[i_p] = 500.0F * (rtb_MatrixConcatenate[i_p + 8] * tmp_nk
          + (rtb_MatrixConcatenate[i_p + 4] * tmp_d + rtb_MatrixConcatenate[i_p]
             * tmp_c)) + 1500.0F;
      }

      /* Saturate: '<S175>/Saturation2' */
      if (Controller_B.mc_force_cmd[2] > 1.0F) {
        tmp_a = 1.0F;
      } else if (Controller_B.mc_force_cmd[2] < 0.0F) {
        tmp_a = 0.0F;
      } else {
        tmp_a = Controller_B.mc_force_cmd[2];
      }

      /* End of Saturate: '<S175>/Saturation2' */

      /* DataTypeConversion: '<S180>/Data Type Conversion' incorporates:
       *  Constant: '<S180>/Constant1'
       *  Gain: '<S180>/Gain1'
       *  Sum: '<S180>/Sum1'
       */
      rtb_DataTypeConversion_i = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
        tmp_a), 4.2949673E+9F) + 1000U);

      /* Saturate: '<S175>/Saturation1' */
      if (Controller_B.mc_torque_cmd[0] > 1.0F) {
        tmp_c = 1.0F;
      } else if (Controller_B.mc_torque_cmd[0] < -1.0F) {
        tmp_c = -1.0F;
      } else {
        tmp_c = Controller_B.mc_torque_cmd[0];
      }

      if (Controller_B.mc_torque_cmd[1] > 1.0F) {
        tmp_d = 1.0F;
      } else if (Controller_B.mc_torque_cmd[1] < -1.0F) {
        tmp_d = -1.0F;
      } else {
        tmp_d = Controller_B.mc_torque_cmd[1];
      }

      if (Controller_B.mc_torque_cmd[2] > 1.0F) {
        tmp_nk = 1.0F;
      } else if (Controller_B.mc_torque_cmd[2] < -1.0F) {
        tmp_nk = -1.0F;
      } else {
        tmp_nk = Controller_B.mc_torque_cmd[2];
      }

      /* End of Saturate: '<S175>/Saturation1' */

      /* Saturate: '<S174>/Saturation' */
      if (Controller_B.fw_force_cmd[0] > 1.0F) {
        tmp_a = 1.0F;
      } else if (Controller_B.fw_force_cmd[0] < 0.0F) {
        tmp_a = 0.0F;
      } else {
        tmp_a = Controller_B.fw_force_cmd[0];
      }

      /* End of Saturate: '<S174>/Saturation' */

      /* Saturate: '<S174>/Saturation1' incorporates:
       *  Constant: '<S179>/Constant1'
       *  DataTypeConversion: '<S179>/Data Type Conversion'
       *  Gain: '<S179>/Gain1'
       *  Sum: '<S179>/Sum1'
       */
      tmp_p[0] = (uint16_T)((uint32_T)fmodf(floorf(1000.0F * tmp_a),
        4.2949673E+9F) + 1000U);

      /* DataTypeConversion: '<S174>/Data Type Conversion' incorporates:
       *  Bias: '<S174>/Bias1'
       */
      tmp_a = fmodf(floorf(rtb_Multiply_fw[0] + CONTROL_PARAM.SERVO1_BIAS),
                    65536.0F);

      /* Saturate: '<S174>/Saturation1' incorporates:
       *  DataTypeConversion: '<S174>/Data Type Conversion'
       */
      tmp_p[1] = (uint16_T)(tmp_a < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_a : (int32_T)(uint16_T)tmp_a);

      /* DataTypeConversion: '<S174>/Data Type Conversion1' incorporates:
       *  Bias: '<S174>/Bias2'
       */
      tmp_a = fmodf(floorf(rtb_Multiply_fw[1] + CONTROL_PARAM.SERVO2_BIAS),
                    65536.0F);

      /* Saturate: '<S174>/Saturation1' incorporates:
       *  DataTypeConversion: '<S174>/Data Type Conversion1'
       */
      tmp_p[2] = (uint16_T)(tmp_a < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_a : (int32_T)(uint16_T)tmp_a);

      /* DataTypeConversion: '<S174>/Data Type Conversion2' incorporates:
       *  Bias: '<S174>/Bias3'
       */
      tmp_a = fmodf(floorf(rtb_Multiply_fw[2] + CONTROL_PARAM.SERVO3_BIAS),
                    65536.0F);

      /* Saturate: '<S174>/Saturation1' incorporates:
       *  DataTypeConversion: '<S174>/Data Type Conversion2'
       */
      tmp_p[3] = (uint16_T)(tmp_a < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_a : (int32_T)(uint16_T)tmp_a);

      /* DataTypeConversion: '<S174>/Data Type Conversion3' incorporates:
       *  Bias: '<S174>/Bias4'
       */
      tmp_a = fmodf(floorf(rtb_Multiply_fw[3] + CONTROL_PARAM.SERVO4_BIAS),
                    65536.0F);

      /* Saturate: '<S174>/Saturation1' incorporates:
       *  DataTypeConversion: '<S174>/Data Type Conversion3'
       */
      tmp_p[4] = (uint16_T)(tmp_a < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_a : (int32_T)(uint16_T)tmp_a);

      /* Product: '<S175>/Multiply' */
      for (i_p = 0; i_p < 4; i_p++) {
        /* Saturate: '<S175>/Saturation' incorporates:
         *  Constant: '<S175>/Effective_Matrix'
         *  Gain: '<S175>/Gain'
         *  Sum: '<S175>/Add'
         */
        tmp_a = fmodf(floorf(1000.0F * (Controller_ConstP.pooled5[i_p + 8] *
          tmp_nk + (Controller_ConstP.pooled5[i_p + 4] * tmp_d +
                    Controller_ConstP.pooled5[i_p] * tmp_c)) + (real32_T)
                             rtb_DataTypeConversion_i), 65536.0F);
        u0_p = (uint16_T)(tmp_a < 0.0F ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
                          -tmp_a : (int32_T)(uint16_T)tmp_a);
        if (u0_p > 2000) {
          rtb_VariantMergeForOutportactua[i_p] = 2000U;
        } else if (u0_p < 1000) {
          rtb_VariantMergeForOutportactua[i_p] = 1000U;
        } else {
          rtb_VariantMergeForOutportactua[i_p] = u0_p;
        }

        /* End of Saturate: '<S175>/Saturation' */
      }

      /* End of Product: '<S175>/Multiply' */
      for (i_p = 0; i_p < 5; i_p++) {
        /* Saturate: '<S174>/Saturation1' */
        if (tmp_p[i_p] > 2000) {
          rtb_VariantMergeForOutportactua[i_p + 4] = 2000U;
        } else if (tmp_p[i_p] < 1000) {
          rtb_VariantMergeForOutportactua[i_p + 4] = 1000U;
        } else {
          rtb_VariantMergeForOutportactua[i_p + 4] = tmp_p[i_p];
        }
      }
      break;

     default:
      for (i_p = 0; i_p < 9; i_p++) {
        rtb_VariantMergeForOutportactua[i_p] = (uint16_T)fmodf(floorf
          (rtb_Saturation_fa[i_p]), 65536.0F);
      }
      break;
    }

    /* End of MultiPortSwitch: '<S176>/Multiport Switch' */
  }

#elif AIRFRAME == 2

  /* Output and update for atomic system: '<S171>/VTOL2' */
  {
    real32_T rtb_MatrixConcatenate_g[12];
    uint16_T rtb_DataTypeConversion_o;
    real32_T rtb_Multiply_ka[4];
    real32_T rtb_Saturation_kl[9];
    int32_T i_o;
    uint16_T tmp_o[5];
    real32_T tmp_m;
    real32_T tmp_ev;
    real32_T tmp_k;
    uint16_T u0_o;
    real32_T tmp_gf;

    /* Saturate: '<S190>/Saturation' incorporates:
     *  Bias: '<S190>/Bias'
     *  Bias: '<S190>/Bias1'
     *  Bias: '<S190>/Bias2'
     *  Bias: '<S190>/Bias3'
     *  Constant: '<S190>/Constant'
     */
    for (i_o = 0; i_o < 5; i_o++) {
      rtb_Saturation_kl[i_o] = 1000.0F;
    }

    if (1500.0F + CONTROL_PARAM.SERVO1_BIAS > 2000.0F) {
      rtb_Saturation_kl[5] = 2000.0F;
    } else if (1500.0F + CONTROL_PARAM.SERVO1_BIAS < 1000.0F) {
      rtb_Saturation_kl[5] = 1000.0F;
    } else {
      rtb_Saturation_kl[5] = 1500.0F + CONTROL_PARAM.SERVO1_BIAS;
    }

    if (1500.0F + CONTROL_PARAM.SERVO2_BIAS > 2000.0F) {
      rtb_Saturation_kl[6] = 2000.0F;
    } else if (1500.0F + CONTROL_PARAM.SERVO2_BIAS < 1000.0F) {
      rtb_Saturation_kl[6] = 1000.0F;
    } else {
      rtb_Saturation_kl[6] = 1500.0F + CONTROL_PARAM.SERVO2_BIAS;
    }

    if (1500.0F + CONTROL_PARAM.SERVO3_BIAS > 2000.0F) {
      rtb_Saturation_kl[7] = 2000.0F;
    } else if (1500.0F + CONTROL_PARAM.SERVO3_BIAS < 1000.0F) {
      rtb_Saturation_kl[7] = 1000.0F;
    } else {
      rtb_Saturation_kl[7] = 1500.0F + CONTROL_PARAM.SERVO3_BIAS;
    }

    if (1500.0F + CONTROL_PARAM.SERVO4_BIAS > 2000.0F) {
      rtb_Saturation_kl[8] = 2000.0F;
    } else if (1500.0F + CONTROL_PARAM.SERVO4_BIAS < 1000.0F) {
      rtb_Saturation_kl[8] = 1000.0F;
    } else {
      rtb_Saturation_kl[8] = 1500.0F + CONTROL_PARAM.SERVO4_BIAS;
    }

    /* End of Saturate: '<S190>/Saturation' */

    /* MultiPortSwitch: '<S185>/Multiport Switch' incorporates:
     *  Constant: '<S186>/Constant1'
     *  Constant: '<S186>/Constant11'
     *  Constant: '<S186>/Constant12'
     *  Constant: '<S186>/Constant2'
     *  Constant: '<S186>/Constant7'
     *  Constant: '<S186>/Constant8'
     *  DataTypeConversion: '<S190>/Data Type Conversion'
     *  DataTypeConversion: '<S191>/Data Type Conversion'
     *  Inport: '<Root>/FMS_Out'
     */
    switch (Controller_U.FMS_Out.status) {
     case 1:
      for (i_o = 0; i_o < 9; i_o++) {
        rtb_VariantMergeForOutportactua[i_o] = (uint16_T)fmodf(floorf
          (rtb_Saturation_kl[i_o]), 65536.0F);
      }
      break;

     case 2:
      for (i_o = 0; i_o < 5; i_o++) {
        /* Saturate: '<S191>/Saturation' incorporates:
         *  Constant: '<S191>/Disarm'
         *  Reshape: '<S191>/Reshape'
         */
        if (Controller_ConstP.pooled7[i_o] > 2000.0F) {
          tmp_gf = 2000.0F;
        } else if (Controller_ConstP.pooled7[i_o] < 1000.0F) {
          tmp_gf = 1000.0F;
        } else {
          tmp_gf = Controller_ConstP.pooled7[i_o];
        }

        rtb_VariantMergeForOutportactua[i_o] = (uint16_T)fmodf(floorf(tmp_gf),
          65536.0F);
      }

      /* Saturate: '<S191>/Saturation' incorporates:
       *  Bias: '<S191>/Bias'
       *  Constant: '<S191>/Constant'
       *  DataTypeConversion: '<S191>/Data Type Conversion'
       */
      if (1500.0F + CONTROL_PARAM.SERVO1_BIAS > 2000.0F) {
        tmp_gf = 2000.0F;
      } else if (1500.0F + CONTROL_PARAM.SERVO1_BIAS < 1000.0F) {
        tmp_gf = 1000.0F;
      } else {
        tmp_gf = 1500.0F + CONTROL_PARAM.SERVO1_BIAS;
      }

      rtb_VariantMergeForOutportactua[5] = (uint16_T)fmodf(floorf(tmp_gf),
        65536.0F);

      /* Saturate: '<S191>/Saturation' incorporates:
       *  Bias: '<S191>/Bias1'
       *  Constant: '<S191>/Constant'
       *  DataTypeConversion: '<S191>/Data Type Conversion'
       */
      if (1500.0F + CONTROL_PARAM.SERVO2_BIAS > 2000.0F) {
        tmp_gf = 2000.0F;
      } else if (1500.0F + CONTROL_PARAM.SERVO2_BIAS < 1000.0F) {
        tmp_gf = 1000.0F;
      } else {
        tmp_gf = 1500.0F + CONTROL_PARAM.SERVO2_BIAS;
      }

      rtb_VariantMergeForOutportactua[6] = (uint16_T)fmodf(floorf(tmp_gf),
        65536.0F);

      /* Saturate: '<S191>/Saturation' incorporates:
       *  Bias: '<S191>/Bias2'
       *  Constant: '<S191>/Constant'
       *  DataTypeConversion: '<S191>/Data Type Conversion'
       */
      if (1500.0F + CONTROL_PARAM.SERVO3_BIAS > 2000.0F) {
        tmp_gf = 2000.0F;
      } else if (1500.0F + CONTROL_PARAM.SERVO3_BIAS < 1000.0F) {
        tmp_gf = 1000.0F;
      } else {
        tmp_gf = 1500.0F + CONTROL_PARAM.SERVO3_BIAS;
      }

      rtb_VariantMergeForOutportactua[7] = (uint16_T)fmodf(floorf(tmp_gf),
        65536.0F);

      /* Saturate: '<S191>/Saturation' incorporates:
       *  Bias: '<S191>/Bias3'
       *  Constant: '<S191>/Constant'
       *  DataTypeConversion: '<S191>/Data Type Conversion'
       */
      if (1500.0F + CONTROL_PARAM.SERVO4_BIAS > 2000.0F) {
        tmp_gf = 2000.0F;
      } else if (1500.0F + CONTROL_PARAM.SERVO4_BIAS < 1000.0F) {
        tmp_gf = 1000.0F;
      } else {
        tmp_gf = 1500.0F + CONTROL_PARAM.SERVO4_BIAS;
      }

      rtb_VariantMergeForOutportactua[8] = (uint16_T)fmodf(floorf(tmp_gf),
        65536.0F);
      break;

     case 3:
      rtb_MatrixConcatenate_g[11] = CONTROL_PARAM.FW_YAW_EFFC *
        CONTROL_PARAM.FW_TAIL2_DIR;
      rtb_MatrixConcatenate_g[10] = CONTROL_PARAM.FW_YAW_EFFC *
        CONTROL_PARAM.FW_TAIL1_DIR;

      /* SignalConversion: '<S186>/ConcatBufferAtVector Concatenate2In2' incorporates:
       *  Constant: '<S186>/Constant10'
       *  Constant: '<S186>/Constant11'
       *  Constant: '<S186>/Constant12'
       */
      rtb_MatrixConcatenate_g[9] = 0.0F;

      /* SignalConversion: '<S186>/ConcatBufferAtVector Concatenate2In1' incorporates:
       *  Constant: '<S186>/Constant9'
       */
      rtb_MatrixConcatenate_g[8] = 0.0F;
      rtb_MatrixConcatenate_g[7] = -CONTROL_PARAM.FW_PITCH_EFFC *
        CONTROL_PARAM.FW_TAIL2_DIR;
      rtb_MatrixConcatenate_g[6] = CONTROL_PARAM.FW_PITCH_EFFC *
        CONTROL_PARAM.FW_TAIL1_DIR;

      /* SignalConversion: '<S186>/ConcatBufferAtVector Concatenate1In2' incorporates:
       *  Constant: '<S186>/Constant6'
       *  Constant: '<S186>/Constant7'
       *  Constant: '<S186>/Constant8'
       */
      rtb_MatrixConcatenate_g[5] = 0.0F;

      /* SignalConversion: '<S186>/ConcatBufferAtVector Concatenate1In1' incorporates:
       *  Constant: '<S186>/Constant5'
       */
      rtb_MatrixConcatenate_g[4] = 0.0F;

      /* SignalConversion: '<S186>/ConcatBufferAtVector ConcatenateIn4' incorporates:
       *  Constant: '<S186>/Constant4'
       */
      rtb_MatrixConcatenate_g[3] = 0.0F;

      /* SignalConversion: '<S186>/ConcatBufferAtVector ConcatenateIn3' incorporates:
       *  Constant: '<S186>/Constant3'
       */
      rtb_MatrixConcatenate_g[2] = 0.0F;
      rtb_MatrixConcatenate_g[1] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON2_DIR;
      rtb_MatrixConcatenate_g[0] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON1_DIR;

      /* Saturate: '<S183>/Saturation5' incorporates:
       *  Constant: '<S186>/Constant1'
       *  Constant: '<S186>/Constant2'
       */
      if (Controller_B.fw_torque_cmd[0] > 1.0F) {
        /* Product: '<S183>/Multiply1' */
        tmp_m = 1.0F;
      } else if (Controller_B.fw_torque_cmd[0] < -1.0F) {
        /* Product: '<S183>/Multiply1' */
        tmp_m = -1.0F;
      } else {
        /* Product: '<S183>/Multiply1' */
        tmp_m = Controller_B.fw_torque_cmd[0];
      }

      if (Controller_B.fw_torque_cmd[1] > 1.0F) {
        /* Product: '<S183>/Multiply1' */
        tmp_ev = 1.0F;
      } else if (Controller_B.fw_torque_cmd[1] < -1.0F) {
        /* Product: '<S183>/Multiply1' */
        tmp_ev = -1.0F;
      } else {
        /* Product: '<S183>/Multiply1' */
        tmp_ev = Controller_B.fw_torque_cmd[1];
      }

      if (Controller_B.fw_torque_cmd[2] > 1.0F) {
        /* Product: '<S183>/Multiply1' */
        tmp_k = 1.0F;
      } else if (Controller_B.fw_torque_cmd[2] < -1.0F) {
        /* Product: '<S183>/Multiply1' */
        tmp_k = -1.0F;
      } else {
        /* Product: '<S183>/Multiply1' */
        tmp_k = Controller_B.fw_torque_cmd[2];
      }

      /* End of Saturate: '<S183>/Saturation5' */
      for (i_o = 0; i_o < 4; i_o++) {
        /* Bias: '<S183>/Bias' incorporates:
         *  Gain: '<S183>/Gain1'
         *  Product: '<S183>/Multiply1'
         */
        rtb_Multiply_ka[i_o] = 500.0F * (rtb_MatrixConcatenate_g[i_o + 8] *
          tmp_k + (rtb_MatrixConcatenate_g[i_o + 4] * tmp_ev +
                   rtb_MatrixConcatenate_g[i_o] * tmp_m)) + 1500.0F;
      }

      /* Saturate: '<S184>/Saturation2' */
      if (Controller_B.mc_force_cmd[2] > 1.0F) {
        tmp_gf = 1.0F;
      } else if (Controller_B.mc_force_cmd[2] < 0.0F) {
        tmp_gf = 0.0F;
      } else {
        tmp_gf = Controller_B.mc_force_cmd[2];
      }

      /* End of Saturate: '<S184>/Saturation2' */

      /* DataTypeConversion: '<S189>/Data Type Conversion' incorporates:
       *  Constant: '<S189>/Constant1'
       *  Gain: '<S189>/Gain1'
       *  Sum: '<S189>/Sum1'
       */
      rtb_DataTypeConversion_o = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
        tmp_gf), 4.2949673E+9F) + 1000U);

      /* Saturate: '<S184>/Saturation1' */
      if (Controller_B.mc_torque_cmd[0] > 1.0F) {
        tmp_m = 1.0F;
      } else if (Controller_B.mc_torque_cmd[0] < -1.0F) {
        tmp_m = -1.0F;
      } else {
        tmp_m = Controller_B.mc_torque_cmd[0];
      }

      if (Controller_B.mc_torque_cmd[1] > 1.0F) {
        tmp_ev = 1.0F;
      } else if (Controller_B.mc_torque_cmd[1] < -1.0F) {
        tmp_ev = -1.0F;
      } else {
        tmp_ev = Controller_B.mc_torque_cmd[1];
      }

      if (Controller_B.mc_torque_cmd[2] > 1.0F) {
        tmp_k = 1.0F;
      } else if (Controller_B.mc_torque_cmd[2] < -1.0F) {
        tmp_k = -1.0F;
      } else {
        tmp_k = Controller_B.mc_torque_cmd[2];
      }

      /* End of Saturate: '<S184>/Saturation1' */

      /* Saturate: '<S183>/Saturation4' */
      if (Controller_B.fw_force_cmd[0] > 1.0F) {
        tmp_gf = 1.0F;
      } else if (Controller_B.fw_force_cmd[0] < 0.0F) {
        tmp_gf = 0.0F;
      } else {
        tmp_gf = Controller_B.fw_force_cmd[0];
      }

      /* End of Saturate: '<S183>/Saturation4' */

      /* Saturate: '<S183>/Saturation1' incorporates:
       *  Constant: '<S188>/Constant1'
       *  DataTypeConversion: '<S188>/Data Type Conversion'
       *  Gain: '<S188>/Gain1'
       *  Sum: '<S188>/Sum1'
       */
      tmp_o[0] = (uint16_T)((uint32_T)fmodf(floorf(1000.0F * tmp_gf),
        4.2949673E+9F) + 1000U);

      /* DataTypeConversion: '<S183>/Data Type Conversion' incorporates:
       *  Bias: '<S183>/Bias1'
       */
      tmp_gf = fmodf(floorf(rtb_Multiply_ka[0] + CONTROL_PARAM.SERVO1_BIAS),
                     65536.0F);

      /* Saturate: '<S183>/Saturation1' incorporates:
       *  DataTypeConversion: '<S183>/Data Type Conversion'
       */
      tmp_o[1] = (uint16_T)(tmp_gf < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_gf : (int32_T)(uint16_T)tmp_gf);

      /* DataTypeConversion: '<S183>/Data Type Conversion1' incorporates:
       *  Bias: '<S183>/Bias2'
       */
      tmp_gf = fmodf(floorf(rtb_Multiply_ka[1] + CONTROL_PARAM.SERVO2_BIAS),
                     65536.0F);

      /* Saturate: '<S183>/Saturation1' incorporates:
       *  DataTypeConversion: '<S183>/Data Type Conversion1'
       */
      tmp_o[2] = (uint16_T)(tmp_gf < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_gf : (int32_T)(uint16_T)tmp_gf);

      /* DataTypeConversion: '<S183>/Data Type Conversion2' incorporates:
       *  Bias: '<S183>/Bias3'
       */
      tmp_gf = fmodf(floorf(rtb_Multiply_ka[2] + CONTROL_PARAM.SERVO3_BIAS),
                     65536.0F);

      /* Saturate: '<S183>/Saturation1' incorporates:
       *  DataTypeConversion: '<S183>/Data Type Conversion2'
       */
      tmp_o[3] = (uint16_T)(tmp_gf < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_gf : (int32_T)(uint16_T)tmp_gf);

      /* DataTypeConversion: '<S183>/Data Type Conversion3' incorporates:
       *  Bias: '<S183>/Bias4'
       */
      tmp_gf = fmodf(floorf(rtb_Multiply_ka[3] + CONTROL_PARAM.SERVO4_BIAS),
                     65536.0F);

      /* Saturate: '<S183>/Saturation1' incorporates:
       *  DataTypeConversion: '<S183>/Data Type Conversion3'
       */
      tmp_o[4] = (uint16_T)(tmp_gf < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_gf : (int32_T)(uint16_T)tmp_gf);

      /* Product: '<S184>/Multiply' */
      for (i_o = 0; i_o < 4; i_o++) {
        /* Saturate: '<S184>/Saturation' incorporates:
         *  Constant: '<S184>/Effective_Matrix'
         *  Gain: '<S184>/Gain'
         *  Sum: '<S184>/Add'
         */
        tmp_gf = fmodf(floorf(1000.0F * (Controller_ConstP.pooled5[i_o + 8] *
          tmp_k + (Controller_ConstP.pooled5[i_o + 4] * tmp_ev +
                   Controller_ConstP.pooled5[i_o] * tmp_m)) + (real32_T)
                              rtb_DataTypeConversion_o), 65536.0F);
        u0_o = (uint16_T)(tmp_gf < 0.0F ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
                          -tmp_gf : (int32_T)(uint16_T)tmp_gf);
        if (u0_o > 2000) {
          rtb_VariantMergeForOutportactua[i_o] = 2000U;
        } else if (u0_o < 1000) {
          rtb_VariantMergeForOutportactua[i_o] = 1000U;
        } else {
          rtb_VariantMergeForOutportactua[i_o] = u0_o;
        }

        /* End of Saturate: '<S184>/Saturation' */
      }

      /* End of Product: '<S184>/Multiply' */
      for (i_o = 0; i_o < 5; i_o++) {
        /* Saturate: '<S183>/Saturation1' */
        if (tmp_o[i_o] > 2000) {
          rtb_VariantMergeForOutportactua[i_o + 4] = 2000U;
        } else if (tmp_o[i_o] < 1000) {
          rtb_VariantMergeForOutportactua[i_o + 4] = 1000U;
        } else {
          rtb_VariantMergeForOutportactua[i_o + 4] = tmp_o[i_o];
        }
      }
      break;

     default:
      for (i_o = 0; i_o < 9; i_o++) {
        rtb_VariantMergeForOutportactua[i_o] = (uint16_T)fmodf(floorf
          (rtb_Saturation_kl[i_o]), 65536.0F);
      }
      break;
    }

    /* End of MultiPortSwitch: '<S185>/Multiport Switch' */
  }

#endif

  /* End of Outputs for SubSystem: '<S6>/VTOL_Control_Allocation' */

  /* Outport: '<Root>/Control_Out' incorporates:
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   *  Reshape: '<S170>/Reshape'
   */
  Controller_Y.Control_Out.timestamp =
    Controller_DW.DiscreteTimeIntegrator_DSTATE_n;
  for (rtb_Relay = 0; rtb_Relay < 9; rtb_Relay++) {
    Controller_Y.Control_Out.actuator_cmd[rtb_Relay] =
      rtb_VariantMergeForOutportactua[rtb_Relay];
  }

  for (rtb_Relay = 0; rtb_Relay < 7; rtb_Relay++) {
    Controller_Y.Control_Out.actuator_cmd[rtb_Relay + 9] = 0U;
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

  /* Start for SwitchCase: '<S8>/Switch Case1' */
  Controller_DW.SwitchCase1_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S2>/FW_Controller' */
  /* Start for Constant: '<S48>/Constant' */
  Controller_B.Constant_m = CONTROL_PARAM.MC_VEL_Z_I_MIN;

  /* End of Start for SubSystem: '<S2>/FW_Controller' */

  /* Start for IfAction SubSystem: '<S2>/MC_Controller' */
  /* Start for Constant: '<S167>/Constant' */
  Controller_B.Constant = CONTROL_PARAM.MC_VEL_Z_I_MIN;

  /* End of Start for SubSystem: '<S2>/MC_Controller' */

  /* SystemInitialize for IfAction SubSystem: '<S2>/FW_Controller' */
  /* InitializeConditions for DiscreteIntegrator: '<S55>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_e = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S53>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_L_eo = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S52>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_o = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S26>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_d[0] =
    Controller_ConstB.Constant_j[0];
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_d[0] >=
      CONTROL_PARAM.MC_RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_d[0] =
      CONTROL_PARAM.MC_RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_d[0] <=
        CONTROL_PARAM.MC_RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_d[0] =
        CONTROL_PARAM.MC_RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_DSTATE_d[1] =
    Controller_ConstB.Constant_j[1];
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_d[1] >=
      CONTROL_PARAM.MC_RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_d[1] =
      CONTROL_PARAM.MC_RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_d[1] <=
        CONTROL_PARAM.MC_RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_d[1] =
        CONTROL_PARAM.MC_RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_DSTATE_d[2] =
    Controller_ConstB.Constant_j[2];
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_d[2] >=
      CONTROL_PARAM.MC_RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_d[2] =
      CONTROL_PARAM.MC_RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_d[2] <=
        CONTROL_PARAM.MC_RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_d[2] =
        CONTROL_PARAM.MC_RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRe_o = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S26>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S99>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_n = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S94>/ ' */
  Controller_DW._DSTATE = Controller_ConstB.Zero1;
  if (Controller_DW._DSTATE >= CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
    Controller_DW._DSTATE = CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
  } else {
    if (Controller_DW._DSTATE <= -CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
      Controller_DW._DSTATE = -CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
    }
  }

  Controller_DW._PrevResetState = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S94>/ ' */

  /* InitializeConditions for DiscreteIntegrator: '<S95>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_f = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_b = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S24>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_b = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S28>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_h = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_l = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S97>/ ' */
  Controller_DW._DSTATE_d = Controller_ConstB.Zero;
  if (Controller_DW._DSTATE_d >= 1.0F) {
    Controller_DW._DSTATE_d = 1.0F;
  } else {
    if (Controller_DW._DSTATE_d <= 0.0F) {
      Controller_DW._DSTATE_d = 0.0F;
    }
  }

  Controller_DW._PrevResetState_e = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S97>/ ' */

  /* InitializeConditions for DiscreteIntegrator: '<S98>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_L_h0 = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_d = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S45>/Integrator1' */
  Controller_DW.Integrator1_DSTATE_i = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S48>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_b = Controller_B.Constant_m;
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S48>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S50>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_i = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_h = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S51>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_g = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S73>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_PrevR_ef = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S45>/Integrator' */
  Controller_DW.Integrator_DSTATE_f = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S73>/Discrete-Time Integrator' */
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

  /* End of SystemInitialize for SubSystem: '<S2>/FW_Controller' */

  /* SystemInitialize for IfAction SubSystem: '<S2>/MC_Controller' */
  /* InitializeConditions for DiscreteIntegrator: '<S119>/Discrete-Time Integrator' */
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

  /* End of SystemInitialize for SubSystem: '<S2>/MC_Controller' */

  /* SystemInitialize for IfAction SubSystem: '<S2>/FW_Controller' */
  /* InitializeConditions for DiscreteIntegrator: '<S73>/Discrete-Time Integrator' */
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

  /* End of SystemInitialize for SubSystem: '<S2>/FW_Controller' */

  /* SystemInitialize for IfAction SubSystem: '<S2>/MC_Controller' */
  /* InitializeConditions for DiscreteIntegrator: '<S119>/Discrete-Time Integrator' */
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

  /* End of SystemInitialize for SubSystem: '<S2>/MC_Controller' */

  /* SystemInitialize for IfAction SubSystem: '<S2>/FW_Controller' */
  /* InitializeConditions for DiscreteIntegrator: '<S73>/Discrete-Time Integrator' */
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

  /* End of SystemInitialize for SubSystem: '<S2>/FW_Controller' */

  /* SystemInitialize for IfAction SubSystem: '<S2>/MC_Controller' */
  /* InitializeConditions for DiscreteIntegrator: '<S119>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S146>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_PrevRe_p = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S148>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S117>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S121>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_k = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S141>/Integrator1' */
  Controller_DW.Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S146>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S141>/Integrator' */
  Controller_DW.Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S141>/Integrator1' */
  Controller_DW.Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S146>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S141>/Integrator' */
  Controller_DW.Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S164>/Integrator1' */
  Controller_DW.Integrator1_DSTATE_e = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S167>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S167>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S169>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 1U;
  Controller_DW.DiscreteTimeIntegrator1_Prev_ks = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S164>/Integrator' */
  Controller_DW.Integrator_DSTATE_j = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S2>/MC_Controller' */

  /* SystemInitialize for Merge: '<S2>/Merge' */
  Controller_B.mc_torque_cmd[0] = 0.0F;
  Controller_B.mc_force_cmd[0] = 0.0F;
  Controller_B.fw_torque_cmd[0] = 0.0F;
  Controller_B.fw_force_cmd[0] = 0.0F;
  Controller_B.mc_torque_cmd[1] = 0.0F;
  Controller_B.mc_force_cmd[1] = 0.0F;
  Controller_B.fw_torque_cmd[1] = 0.0F;
  Controller_B.fw_force_cmd[1] = 0.0F;
  Controller_B.mc_torque_cmd[2] = 0.0F;
  Controller_B.mc_force_cmd[2] = 0.0F;
  Controller_B.fw_torque_cmd[2] = 0.0F;
  Controller_B.fw_force_cmd[2] = 0.0F;
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
