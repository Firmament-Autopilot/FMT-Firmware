/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.344
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Jul 17 11:32:42 2025
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
struct_QRK8c3803lO9d4oZFNG08F CONTROL_PARAM = {
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
  0.15F,
  0.1F,
  0.1F,
  0.2F,
  -0.1F,
  0.1F,
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
  0.12F,
  0.1F,
  0.1F,
  0.15F,
  0.1F,
  0.0F,
  0.0F,
  1.0F,
  2.0F,
  2.0F,
  1.0F,
  1.0F,
  2.0F,
  0.25F,
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
                                        *   '<S125>/Saturation'
                                        *   '<S126>/Gain'
                                        *   '<S126>/Gain1'
                                        *   '<S126>/balabnce_ratio2'
                                        *   '<S126>/balance_ratio'
                                        *   '<S126>/pitch_ff'
                                        *   '<S126>/thorttle_ff'
                                        *   '<S126>/ucmd2pitch'
                                        *   '<S126>/ucmd2thor'
                                        *   '<S126>/wcmd2pitch'
                                        *   '<S126>/wcmd2thor'
                                        *   '<S127>/cruise_throttle'
                                        *   '<S226>/hover_throttle'
                                        *   '<S101>/hover_throttle'
                                        *   '<S128>/FF'
                                        *   '<S128>/FF_limit'
                                        *   '<S128>/PI_limit'
                                        *   '<S147>/P_control'
                                        *   '<S148>/P_control'
                                        *   '<S203>/Saturation'
                                        *   '<S241>/Bias1'
                                        *   '<S241>/Bias2'
                                        *   '<S241>/Bias3'
                                        *   '<S241>/Bias4'
                                        *   '<S251>/Bias1'
                                        *   '<S251>/Bias2'
                                        *   '<S251>/Bias3'
                                        *   '<S251>/Bias4'
                                        *   '<S80>/Saturation'
                                        *   '<S80>/Saturation1'
                                        *   '<S132>/trim_speed'
                                        *   '<S133>/trim_speed'
                                        *   '<S156>/Gain'
                                        *   '<S157>/ '
                                        *   '<S157>/Gain3'
                                        *   '<S159>/Gain'
                                        *   '<S160>/ '
                                        *   '<S160>/Gain'
                                        *   '<S179>/Saturation'
                                        *   '<S179>/Saturation1'
                                        *   '<S212>/kd'
                                        *   '<S212>/Saturation'
                                        *   '<S213>/ki'
                                        *   '<S213>/Discrete-Time Integrator'
                                        *   '<S214>/kp'
                                        *   '<S233>/kd'
                                        *   '<S233>/Saturation'
                                        *   '<S234>/Constant'
                                        *   '<S234>/ki'
                                        *   '<S234>/Discrete-Time Integrator'
                                        *   '<S235>/kp'
                                        *   '<S244>/Constant1'
                                        *   '<S244>/Constant12'
                                        *   '<S244>/Constant2'
                                        *   '<S244>/Constant7'
                                        *   '<S249>/Bias'
                                        *   '<S249>/Bias1'
                                        *   '<S249>/Bias2'
                                        *   '<S249>/Bias3'
                                        *   '<S250>/Bias'
                                        *   '<S250>/Bias1'
                                        *   '<S250>/Bias2'
                                        *   '<S250>/Bias3'
                                        *   '<S254>/Constant1'
                                        *   '<S254>/Constant11'
                                        *   '<S254>/Constant12'
                                        *   '<S254>/Constant2'
                                        *   '<S254>/Constant7'
                                        *   '<S254>/Constant8'
                                        *   '<S258>/Bias'
                                        *   '<S258>/Bias1'
                                        *   '<S258>/Bias2'
                                        *   '<S258>/Bias3'
                                        *   '<S259>/Bias'
                                        *   '<S259>/Bias1'
                                        *   '<S259>/Bias2'
                                        *   '<S259>/Bias3'
                                        *   '<S92>/Constant1'
                                        *   '<S92>/Constant2'
                                        *   '<S108>/kd'
                                        *   '<S108>/Saturation'
                                        *   '<S109>/Constant'
                                        *   '<S109>/ki'
                                        *   '<S109>/Discrete-Time Integrator'
                                        *   '<S110>/kp'
                                        *   '<S134>/gain1'
                                        *   '<S134>/gain2'
                                        *   '<S134>/gain3'
                                        *   '<S134>/Discrete-Time Integrator'
                                        *   '<S135>/gain1'
                                        *   '<S135>/gain2'
                                        *   '<S135>/gain3'
                                        *   '<S139>/Pitch Offset'
                                        *   '<S139>/Saturation'
                                        *   '<S140>/Constant1'
                                        *   '<S140>/Constant2'
                                        *   '<S196>/Constant1'
                                        *   '<S196>/Constant2'
                                        *   '<S85>/gain1'
                                        *   '<S85>/gain2'
                                        *   '<S85>/gain3'
                                        *   '<S85>/Saturation'
                                        *   '<S86>/gain1'
                                        *   '<S86>/gain2'
                                        *   '<S86>/gain3'
                                        *   '<S86>/Discrete-Time Integrator'
                                        *   '<S87>/gain1'
                                        *   '<S87>/gain2'
                                        *   '<S87>/gain3'
                                        *   '<S185>/gain1'
                                        *   '<S185>/gain2'
                                        *   '<S185>/gain3'
                                        *   '<S185>/Saturation'
                                        *   '<S186>/gain1'
                                        *   '<S186>/gain2'
                                        *   '<S186>/gain3'
                                        *   '<S186>/Discrete-Time Integrator'
                                        *   '<S187>/gain1'
                                        *   '<S187>/gain2'
                                        *   '<S187>/gain3'
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
  real32_T rtb_MatrixConcatenate1_b[9];
  real32_T rtb_rate_err_B[3];
  real32_T rtb_PI_limit[3];
  real32_T rtb_Saturation_j;
  int32_T rtb_Relay;
  boolean_T rtb_LogicalOperator_i;
  real32_T rtb_Sum_l;
  real32_T rtb_Abs;
  real32_T rtb_Cos1;
  real32_T rtb_Saturation1_ih;
  real32_T rtb_VdotPg;
  real32_T rtb_VdotPg_err;
  real32_T rtb_Ldot_err;
  real32_T rtb_Gain_c4;
  real32_T rtb_Switch_j;
  real32_T rtb_DiscreteTimeIntegrator1_o;
  boolean_T rtb_LogicalOperator_g;
  real32_T rtb_Cos;
  real32_T rtb_Add4_m;
  real32_T rtb_Sum_c;
  real32_T rtb_MatrixConcatenate1_p[3];
  real32_T rtb_TmpSignalConversionAtMult_0;
  real32_T rtb_TmpSignalConversionAtMult_1;
  real32_T rtb_TmpSignalConversionAtMult_2;
  real32_T rtb_Divide_i_idx_0;
  real32_T rtb_Divide_i_idx_1;
  real32_T rtb_Divide_i_idx_2;
  real32_T rtb_Divide_i_idx_3;
  real32_T rtb_Divide_m_idx_3;
  real32_T rtb_Gain_a_idx_0;
  real32_T rtb_Gain_a_idx_1;
  real32_T rtb_Gain_a_idx_2;
  real32_T rtb_TmpSignalConversionAtMult_3;
  real32_T rtb_DiscreteTimeIntegrator1_e_t;
  real32_T rtb_DiscreteTimeIntegrator1_a_t;
  real32_T rtb_DiscreteTimeIntegrator_p_tm;

  /* S-Function (sfix_bitop): '<S8>/Bitwise AND' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  rtb_BitwiseAND_n = (uint8_T)(Controller_U.FMS_Out.ctrl_mode & 63);

  /* SwitchCase: '<S9>/Switch Case1' incorporates:
   *  Constant: '<S109>/Constant'
   *  Constant: '<S234>/Constant'
   *  DataTypeConversion: '<S9>/Data Type Conversion'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S185>/Multiply'
   *  Product: '<S198>/Divide1'
   *  Product: '<S212>/Multiply'
   *  Product: '<S85>/Multiply'
   *  Product: '<S94>/Divide1'
   *  Product: '<S9>/Divide'
   *  S-Function (sfix_bitop): '<S9>/Bitwise AND'
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
       *  ActionPort: '<S5>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S9>/Switch Case1' incorporates:
       *  DiscreteIntegrator: '<S106>/Integrator'
       *  DiscreteIntegrator: '<S106>/Integrator1'
       *  DiscreteIntegrator: '<S109>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S111>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S113>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S114>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S115>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S116>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S134>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S157>/ '
       *  DiscreteIntegrator: '<S158>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S160>/ '
       *  DiscreteIntegrator: '<S161>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S84>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S86>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S88>/Discrete-Time Integrator1'
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
      Controller_DW.DiscreteTimeIntegrator5_IC_LO_g = 1U;
      Controller_DW.Integrator_DSTATE_f = 0.0F;
      Controller_DW._DSTATE_d = Controller_ConstB.Zero;
      if (Controller_DW._DSTATE_d >= CONTROL_PARAM.FW_CRUISE_THRO) {
        Controller_DW._DSTATE_d = CONTROL_PARAM.FW_CRUISE_THRO;
      } else {
        if (Controller_DW._DSTATE_d <= -CONTROL_PARAM.FW_CRUISE_THRO) {
          Controller_DW._DSTATE_d = -CONTROL_PARAM.FW_CRUISE_THRO;
        }
      }

      Controller_DW._PrevResetState_e = 0;
      Controller_DW.DiscreteTimeIntegrator1_IC_L_h0 = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevR_d = 0;

      /* End of InitializeConditions for SubSystem: '<S2>/FW_Controller' */
    }

    /* Outputs for IfAction SubSystem: '<S2>/FW_Controller' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* Sqrt: '<S169>/Sqrt' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Math: '<S169>/Square'
     *  Sqrt: '<S123>/Sqrt'
     *  Sum: '<S169>/Sum of Elements'
     *  Switch: '<S112>/Switch'
     */
    rtb_Divide_m_idx_3 = sqrtf(((Controller_U.INS_Out.quat[0] *
      Controller_U.INS_Out.quat[0] + Controller_U.INS_Out.quat[1] *
      Controller_U.INS_Out.quat[1]) + Controller_U.INS_Out.quat[2] *
      Controller_U.INS_Out.quat[2]) + Controller_U.INS_Out.quat[3] *
      Controller_U.INS_Out.quat[3]);

    /* Product: '<S165>/Divide' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Sqrt: '<S169>/Sqrt'
     */
    rtb_Divide_i_idx_0 = Controller_U.INS_Out.quat[0] / rtb_Divide_m_idx_3;
    rtb_Divide_i_idx_1 = Controller_U.INS_Out.quat[1] / rtb_Divide_m_idx_3;
    rtb_Divide_i_idx_2 = Controller_U.INS_Out.quat[2] / rtb_Divide_m_idx_3;
    rtb_Divide_i_idx_3 = Controller_U.INS_Out.quat[3] / rtb_Divide_m_idx_3;

    /* SignalConversion: '<S117>/TmpSignal ConversionAtMultiplyInport2' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_TmpSignalConversionAtMult_0 = Controller_U.INS_Out.vn;
    rtb_TmpSignalConversionAtMult_1 = Controller_U.INS_Out.ve;
    rtb_TmpSignalConversionAtMult_2 = Controller_U.INS_Out.vd;

    /* Trigonometry: '<S154>/Trigonometric Function1' incorporates:
     *  Gain: '<S153>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S154>/Trigonometric Function3'
     */
    rtb_Saturation_j = arm_cos_f32(-Controller_U.INS_Out.psi);
    rtb_MatrixConcatenate1_b[0] = rtb_Saturation_j;

    /* Trigonometry: '<S154>/Trigonometric Function' incorporates:
     *  Gain: '<S153>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S154>/Trigonometric Function2'
     */
    rtb_Abs = arm_sin_f32(-Controller_U.INS_Out.psi);
    rtb_MatrixConcatenate1_b[1] = rtb_Abs;

    /* SignalConversion: '<S154>/ConcatBufferAtVector Concatenate1In3' incorporates:
     *  Constant: '<S154>/Constant3'
     */
    rtb_MatrixConcatenate1_b[2] = 0.0F;

    /* Gain: '<S154>/Gain' */
    rtb_MatrixConcatenate1_b[3] = -rtb_Abs;

    /* Trigonometry: '<S154>/Trigonometric Function3' */
    rtb_MatrixConcatenate1_b[4] = rtb_Saturation_j;

    /* SignalConversion: '<S154>/ConcatBufferAtVector Concatenate2In3' incorporates:
     *  Constant: '<S154>/Constant4'
     */
    rtb_MatrixConcatenate1_b[5] = 0.0F;

    /* SignalConversion: '<S154>/ConcatBufferAtVector ConcatenateIn3' */
    rtb_MatrixConcatenate1_b[6] = Controller_ConstB.VectorConcatenate3_g[0];
    rtb_MatrixConcatenate1_b[7] = Controller_ConstB.VectorConcatenate3_g[1];
    rtb_MatrixConcatenate1_b[8] = Controller_ConstB.VectorConcatenate3_g[2];

    /* Product: '<S151>/Multiply' */
    for (rtb_Relay = 0; rtb_Relay < 3; rtb_Relay++) {
      rtb_rate_err_B[rtb_Relay] = rtb_MatrixConcatenate1_b[rtb_Relay + 6] *
        rtb_TmpSignalConversionAtMult_2 + (rtb_MatrixConcatenate1_b[rtb_Relay +
        3] * rtb_TmpSignalConversionAtMult_1 +
        rtb_MatrixConcatenate1_b[rtb_Relay] * rtb_TmpSignalConversionAtMult_0);
    }

    /* End of Product: '<S151>/Multiply' */

    /* Math: '<S166>/Square' incorporates:
     *  Math: '<S167>/Square'
     *  Math: '<S168>/Square'
     */
    rtb_Saturation_j = rtb_Divide_i_idx_0 * rtb_Divide_i_idx_0;

    /* Math: '<S166>/Square2' incorporates:
     *  Math: '<S167>/Square2'
     *  Math: '<S168>/Square2'
     */
    rtb_Abs = rtb_Divide_i_idx_2 * rtb_Divide_i_idx_2;

    /* Math: '<S166>/Square1' incorporates:
     *  Math: '<S167>/Square1'
     *  Math: '<S168>/Square1'
     */
    rtb_Saturation1_ih = rtb_Divide_i_idx_1 * rtb_Divide_i_idx_1;

    /* Math: '<S166>/Square3' incorporates:
     *  Math: '<S167>/Square3'
     *  Math: '<S168>/Square3'
     */
    rtb_VdotPg = rtb_Divide_i_idx_3 * rtb_Divide_i_idx_3;

    /* Sum: '<S166>/Subtract' incorporates:
     *  Math: '<S166>/Square'
     *  Math: '<S166>/Square1'
     *  Math: '<S166>/Square2'
     *  Math: '<S166>/Square3'
     *  Sum: '<S166>/Add'
     *  Sum: '<S166>/Add1'
     */
    rtb_MatrixConcatenate1_b[0] = (rtb_Saturation_j + rtb_Saturation1_ih) -
      (rtb_Abs + rtb_VdotPg);

    /* Product: '<S166>/Multiply' incorporates:
     *  Product: '<S167>/Multiply'
     */
    rtb_Ldot_err = rtb_Divide_i_idx_1 * rtb_Divide_i_idx_2;

    /* Product: '<S166>/Multiply1' incorporates:
     *  Product: '<S167>/Multiply1'
     */
    rtb_Gain_c4 = rtb_Divide_i_idx_0 * rtb_Divide_i_idx_3;

    /* Gain: '<S166>/Gain' incorporates:
     *  Product: '<S166>/Multiply'
     *  Product: '<S166>/Multiply1'
     *  Sum: '<S166>/Subtract1'
     */
    rtb_MatrixConcatenate1_b[1] = (rtb_Ldot_err - rtb_Gain_c4) * 2.0F;

    /* Product: '<S166>/Multiply2' incorporates:
     *  Product: '<S168>/Multiply'
     */
    rtb_Gain_a_idx_0 = rtb_Divide_i_idx_1 * rtb_Divide_i_idx_3;

    /* Product: '<S166>/Multiply3' incorporates:
     *  Product: '<S168>/Multiply1'
     */
    rtb_Sum_l = rtb_Divide_i_idx_0 * rtb_Divide_i_idx_2;

    /* Gain: '<S166>/Gain1' incorporates:
     *  Product: '<S166>/Multiply2'
     *  Product: '<S166>/Multiply3'
     *  Sum: '<S166>/Add2'
     */
    rtb_MatrixConcatenate1_b[2] = (rtb_Gain_a_idx_0 + rtb_Sum_l) * 2.0F;

    /* Gain: '<S167>/Gain' incorporates:
     *  Sum: '<S167>/Add3'
     */
    rtb_MatrixConcatenate1_b[3] = (rtb_Ldot_err + rtb_Gain_c4) * 2.0F;

    /* Sum: '<S167>/Subtract' incorporates:
     *  Sum: '<S167>/Add'
     *  Sum: '<S167>/Add1'
     */
    rtb_MatrixConcatenate1_b[4] = (rtb_Saturation_j + rtb_Abs) -
      (rtb_Saturation1_ih + rtb_VdotPg);

    /* Product: '<S167>/Multiply2' incorporates:
     *  Product: '<S168>/Multiply2'
     */
    rtb_Ldot_err = rtb_Divide_i_idx_2 * rtb_Divide_i_idx_3;

    /* Product: '<S167>/Multiply3' incorporates:
     *  Product: '<S168>/Multiply3'
     */
    rtb_Gain_c4 = rtb_Divide_i_idx_0 * rtb_Divide_i_idx_1;

    /* Gain: '<S167>/Gain1' incorporates:
     *  Product: '<S167>/Multiply2'
     *  Product: '<S167>/Multiply3'
     *  Sum: '<S167>/Subtract1'
     */
    rtb_MatrixConcatenate1_b[5] = (rtb_Ldot_err - rtb_Gain_c4) * 2.0F;

    /* Gain: '<S168>/Gain' incorporates:
     *  Sum: '<S168>/Subtract2'
     */
    rtb_MatrixConcatenate1_b[6] = (rtb_Gain_a_idx_0 - rtb_Sum_l) * 2.0F;

    /* Gain: '<S168>/Gain1' incorporates:
     *  Sum: '<S168>/Add2'
     */
    rtb_MatrixConcatenate1_b[7] = (rtb_Ldot_err + rtb_Gain_c4) * 2.0F;

    /* Sum: '<S168>/Subtract' incorporates:
     *  Sum: '<S168>/Add'
     *  Sum: '<S168>/Add1'
     */
    rtb_MatrixConcatenate1_b[8] = (rtb_Saturation_j + rtb_VdotPg) -
      (rtb_Saturation1_ih + rtb_Abs);

    /* Product: '<S162>/Multiply' */
    for (rtb_Relay = 0; rtb_Relay < 3; rtb_Relay++) {
      rtb_PI_limit[rtb_Relay] = rtb_MatrixConcatenate1_b[rtb_Relay + 6] *
        rtb_TmpSignalConversionAtMult_2 + (rtb_MatrixConcatenate1_b[rtb_Relay +
        3] * rtb_TmpSignalConversionAtMult_1 +
        rtb_MatrixConcatenate1_b[rtb_Relay] * rtb_TmpSignalConversionAtMult_0);
    }

    /* End of Product: '<S162>/Multiply' */

    /* Switch: '<S112>/Switch' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Math: '<S112>/Square2'
     *  Math: '<S112>/Square3'
     *  Product: '<S112>/Multiply'
     *  S-Function (sfix_bitop): '<S112>/Bitwise AND'
     *  Sqrt: '<S112>/Sqrt'
     *  Sum: '<S112>/Add'
     */
    if ((Controller_U.INS_Out.flag & 512U) > 0U) {
      rtb_Divide_i_idx_2 = Controller_U.INS_Out.airspeed;
    } else {
      /* Product: '<S119>/Divide' */
      rtb_Divide_i_idx_0 = Controller_U.INS_Out.quat[0] / rtb_Divide_m_idx_3;
      rtb_Divide_i_idx_1 = Controller_U.INS_Out.quat[1] / rtb_Divide_m_idx_3;
      rtb_Divide_i_idx_2 = Controller_U.INS_Out.quat[2] / rtb_Divide_m_idx_3;
      rtb_Divide_m_idx_3 = Controller_U.INS_Out.quat[3] / rtb_Divide_m_idx_3;

      /* Sum: '<S122>/Subtract' incorporates:
       *  Math: '<S122>/Square'
       *  Math: '<S122>/Square1'
       *  Math: '<S122>/Square2'
       *  Math: '<S122>/Square3'
       *  Sum: '<S122>/Add'
       *  Sum: '<S122>/Add1'
       */
      rtb_MatrixConcatenate1_b[8] = (rtb_Divide_i_idx_0 * rtb_Divide_i_idx_0 +
        rtb_Divide_m_idx_3 * rtb_Divide_m_idx_3) - (rtb_Divide_i_idx_1 *
        rtb_Divide_i_idx_1 + rtb_Divide_i_idx_2 * rtb_Divide_i_idx_2);

      /* Gain: '<S122>/Gain1' incorporates:
       *  Product: '<S122>/Multiply2'
       *  Product: '<S122>/Multiply3'
       *  Sum: '<S122>/Add2'
       */
      rtb_MatrixConcatenate1_b[7] = (rtb_Divide_i_idx_2 * rtb_Divide_m_idx_3 +
        rtb_Divide_i_idx_0 * rtb_Divide_i_idx_1) * 2.0F;

      /* Gain: '<S122>/Gain' incorporates:
       *  Product: '<S122>/Multiply'
       *  Product: '<S122>/Multiply1'
       *  Sum: '<S122>/Subtract2'
       */
      rtb_MatrixConcatenate1_b[6] = (rtb_Divide_i_idx_1 * rtb_Divide_m_idx_3 -
        rtb_Divide_i_idx_0 * rtb_Divide_i_idx_2) * 2.0F;

      /* Gain: '<S121>/Gain1' incorporates:
       *  Product: '<S121>/Multiply2'
       *  Product: '<S121>/Multiply3'
       *  Sum: '<S121>/Subtract1'
       */
      rtb_MatrixConcatenate1_b[5] = (rtb_Divide_i_idx_2 * rtb_Divide_m_idx_3 -
        rtb_Divide_i_idx_0 * rtb_Divide_i_idx_1) * 2.0F;

      /* Sum: '<S121>/Subtract' incorporates:
       *  Math: '<S121>/Square'
       *  Math: '<S121>/Square1'
       *  Math: '<S121>/Square2'
       *  Math: '<S121>/Square3'
       *  Sum: '<S121>/Add'
       *  Sum: '<S121>/Add1'
       */
      rtb_MatrixConcatenate1_b[4] = (rtb_Divide_i_idx_0 * rtb_Divide_i_idx_0 +
        rtb_Divide_i_idx_2 * rtb_Divide_i_idx_2) - (rtb_Divide_i_idx_1 *
        rtb_Divide_i_idx_1 + rtb_Divide_m_idx_3 * rtb_Divide_m_idx_3);

      /* Gain: '<S121>/Gain' incorporates:
       *  Product: '<S121>/Multiply'
       *  Product: '<S121>/Multiply1'
       *  Sum: '<S121>/Add3'
       */
      rtb_MatrixConcatenate1_b[3] = (rtb_Divide_i_idx_1 * rtb_Divide_i_idx_2 +
        rtb_Divide_i_idx_0 * rtb_Divide_m_idx_3) * 2.0F;

      /* Gain: '<S120>/Gain1' incorporates:
       *  Product: '<S120>/Multiply2'
       *  Product: '<S120>/Multiply3'
       *  Sum: '<S120>/Add2'
       */
      rtb_MatrixConcatenate1_b[2] = (rtb_Divide_i_idx_1 * rtb_Divide_m_idx_3 +
        rtb_Divide_i_idx_0 * rtb_Divide_i_idx_2) * 2.0F;

      /* Gain: '<S120>/Gain' incorporates:
       *  Product: '<S120>/Multiply'
       *  Product: '<S120>/Multiply1'
       *  Sum: '<S120>/Subtract1'
       */
      rtb_MatrixConcatenate1_b[1] = (rtb_Divide_i_idx_1 * rtb_Divide_i_idx_2 -
        rtb_Divide_i_idx_0 * rtb_Divide_m_idx_3) * 2.0F;

      /* Sum: '<S120>/Subtract' incorporates:
       *  Math: '<S120>/Square'
       *  Math: '<S120>/Square1'
       *  Math: '<S120>/Square2'
       *  Math: '<S120>/Square3'
       *  Sum: '<S120>/Add'
       *  Sum: '<S120>/Add1'
       */
      rtb_MatrixConcatenate1_b[0] = (rtb_Divide_i_idx_0 * rtb_Divide_i_idx_0 +
        rtb_Divide_i_idx_1 * rtb_Divide_i_idx_1) - (rtb_Divide_i_idx_2 *
        rtb_Divide_i_idx_2 + rtb_Divide_m_idx_3 * rtb_Divide_m_idx_3);

      /* Product: '<S117>/Multiply' */
      for (rtb_Relay = 0; rtb_Relay < 3; rtb_Relay++) {
        rtb_MatrixConcatenate1_p[rtb_Relay] = rtb_MatrixConcatenate1_b[rtb_Relay
          + 6] * rtb_TmpSignalConversionAtMult_2 +
          (rtb_MatrixConcatenate1_b[rtb_Relay + 3] *
           rtb_TmpSignalConversionAtMult_1 + rtb_MatrixConcatenate1_b[rtb_Relay]
           * rtb_TmpSignalConversionAtMult_0);
      }

      /* End of Product: '<S117>/Multiply' */

      /* Signum: '<S117>/Sign' */
      if (rtb_MatrixConcatenate1_p[0] < 0.0F) {
        rtb_TmpSignalConversionAtMult_0 = -1.0F;
      } else if (rtb_MatrixConcatenate1_p[0] > 0.0F) {
        rtb_TmpSignalConversionAtMult_0 = 1.0F;
      } else {
        rtb_TmpSignalConversionAtMult_0 = rtb_MatrixConcatenate1_p[0];
      }

      /* End of Signum: '<S117>/Sign' */
      rtb_Divide_i_idx_2 = sqrtf(Controller_U.INS_Out.vn *
        Controller_U.INS_Out.vn + Controller_U.INS_Out.ve *
        Controller_U.INS_Out.ve) * rtb_TmpSignalConversionAtMult_0;
    }

    /* Saturate: '<S112>/Saturation1' */
    if (rtb_Divide_i_idx_2 > 100.0F) {
      rtb_Divide_i_idx_2 = 100.0F;
    } else {
      if (rtb_Divide_i_idx_2 < 0.1F) {
        rtb_Divide_i_idx_2 = 0.1F;
      }
    }

    /* End of Saturate: '<S112>/Saturation1' */

    /* DiscreteIntegrator: '<S116>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_e != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j = rtb_Divide_i_idx_2;
    }

    /* Math: '<S71>/Square' incorporates:
     *  DiscreteIntegrator: '<S116>/Discrete-Time Integrator5'
     *  Math: '<S132>/Square1'
     */
    rtb_Add4_m = Controller_DW.DiscreteTimeIntegrator5_DSTAT_j *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;

    /* Product: '<S71>/Divide' incorporates:
     *  Math: '<S71>/Square'
     */
    rtb_Divide_i_idx_3 = rtb_Add4_m / Controller_ConstB.Square1;

    /* DiscreteIntegrator: '<S115>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_L_eo != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_a = rtb_Divide_i_idx_3;
    }

    /* Saturate: '<S71>/Saturation' */
    if (Controller_DW.DiscreteTimeIntegrator5_DSTAT_a > 1.0F) {
      rtb_Saturation_j = 1.0F;
    } else if (Controller_DW.DiscreteTimeIntegrator5_DSTAT_a < 0.0F) {
      rtb_Saturation_j = 0.0F;
    } else {
      rtb_Saturation_j = Controller_DW.DiscreteTimeIntegrator5_DSTAT_a;
    }

    /* End of Saturate: '<S71>/Saturation' */

    /* Relay: '<S71>/Relay' */
    if (rtb_Saturation_j >= 0.95F) {
      Controller_DW.Relay_Mode = true;
    } else {
      if (rtb_Saturation_j <= 0.85F) {
        Controller_DW.Relay_Mode = false;
      }
    }

    rtb_Relay = !Controller_DW.Relay_Mode;

    /* End of Relay: '<S71>/Relay' */

    /* DiscreteIntegrator: '<S114>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_o != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTA_a2 = (real32_T)rtb_Relay;
    }

    /* Logic: '<S76>/Logical Operator' incorporates:
     *  Constant: '<S78>/Constant'
     *  DiscreteIntegrator: '<S114>/Discrete-Time Integrator5'
     *  RelationalOperator: '<S78>/Compare'
     */
    rtb_LogicalOperator_i = ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator5_DSTA_a2 == 0.0F));

    /* DiscreteIntegrator: '<S86>/Discrete-Time Integrator' */
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

    /* Trigonometry: '<S125>/Atan' incorporates:
     *  Gain: '<S125>/g_force'
     */
    rtb_Sum_l = atanf(0.101936802F * Controller_U.FMS_Out.ay_cmd);

    /* Saturate: '<S125>/Saturation' */
    if (rtb_Sum_l > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Sum_l = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_Sum_l < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_Sum_l = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      }
    }

    /* End of Saturate: '<S125>/Saturation' */

    /* Switch: '<S138>/Switch' incorporates:
     *  Logic: '<S138>/Logical Operator'
     *  RelationalOperator: '<S143>/Compare'
     */
    if ((rtb_BitwiseAND_n == 3) || (rtb_BitwiseAND_n == 4)) {
      rtb_Cos = Controller_U.FMS_Out.phi_cmd;
    } else {
      rtb_Cos = rtb_Sum_l;
    }

    /* End of Switch: '<S138>/Switch' */

    /* Switch: '<S146>/Switch' incorporates:
     *  Constant: '<S155>/Constant'
     *  RelationalOperator: '<S155>/Compare'
     */
    if (rtb_BitwiseAND_n == 4) {
      rtb_Sum_l = Controller_U.FMS_Out.phi_cmd;
    }

    /* End of Switch: '<S146>/Switch' */

    /* Abs: '<S126>/Abs' */
    rtb_Abs = fabsf(rtb_Sum_l);

    /* DeadZone: '<S151>/Dead Zone' */
    if (rtb_rate_err_B[0] > 1.0F) {
      rtb_Sum_l = rtb_rate_err_B[0] - 1.0F;
    } else if (rtb_rate_err_B[0] >= -1.0F) {
      rtb_Sum_l = 0.0F;
    } else {
      rtb_Sum_l = rtb_rate_err_B[0] - -1.0F;
    }

    /* End of DeadZone: '<S151>/Dead Zone' */

    /* Signum: '<S151>/Sign' */
    if (rtb_Sum_l < 0.0F) {
      rtb_Sum_l = -1.0F;
    } else {
      if (rtb_Sum_l > 0.0F) {
        rtb_Sum_l = 1.0F;
      }
    }

    /* End of Signum: '<S151>/Sign' */

    /* Switch: '<S150>/Switch' incorporates:
     *  Gain: '<S150>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S150>/Divide'
     *  S-Function (sfix_bitop): '<S150>/Bitwise AND'
     *  Trigonometry: '<S150>/Asin'
     */
    if ((Controller_U.INS_Out.flag & 16U) > 1U) {
      /* Sqrt: '<S150>/Sqrt' incorporates:
       *  Math: '<S150>/Square'
       *  Math: '<S150>/Square1'
       *  Sum: '<S150>/Add'
       */
      rtb_Sum_c = sqrtf(Controller_U.INS_Out.vn * Controller_U.INS_Out.vn +
                        Controller_U.INS_Out.ve * Controller_U.INS_Out.ve);

      /* Saturate: '<S150>/Saturation' incorporates:
       *  Sqrt: '<S150>/Sqrt'
       */
      if (rtb_Sum_c > 100.0F) {
        rtb_Sum_c = 100.0F;
      } else {
        if (rtb_Sum_c < 8.0F) {
          rtb_Sum_c = 8.0F;
        }
      }

      /* End of Saturate: '<S150>/Saturation' */

      /* DeadZone: '<S150>/Dead Zone' */
      if (Controller_U.INS_Out.vd > 0.1F) {
        rtb_Switch_j = Controller_U.INS_Out.vd - 0.1F;
      } else if (Controller_U.INS_Out.vd >= -0.1F) {
        rtb_Switch_j = 0.0F;
      } else {
        rtb_Switch_j = Controller_U.INS_Out.vd - -0.1F;
      }

      /* End of DeadZone: '<S150>/Dead Zone' */
      rtb_Cos1 = atanf(1.0F / rtb_Sum_c * -rtb_Switch_j);
    } else {
      rtb_Cos1 = Controller_U.INS_Out.theta;
    }

    /* End of Switch: '<S150>/Switch' */

    /* Product: '<S150>/Multiply1' */
    rtb_Cos1 *= rtb_Sum_l;

    /* Saturate: '<S150>/Saturation1' */
    if (rtb_Cos1 > 0.785398185F) {
      rtb_Saturation1_ih = 0.785398185F;
    } else if (rtb_Cos1 < -0.785398185F) {
      rtb_Saturation1_ih = -0.785398185F;
    } else {
      rtb_Saturation1_ih = rtb_Cos1;
    }

    /* End of Saturate: '<S150>/Saturation1' */

    /* Gain: '<S149>/Gain1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_VdotPg = 0.101936802F * Controller_U.INS_Out.ax;

    /* Sqrt: '<S152>/Sqrt' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Math: '<S152>/Square'
     *  Math: '<S152>/Square1'
     *  Sum: '<S152>/Add'
     */
    rtb_Sum_c = sqrtf(Controller_U.INS_Out.vn * Controller_U.INS_Out.vn +
                      Controller_U.INS_Out.ve * Controller_U.INS_Out.ve);

    /* Saturate: '<S152>/Saturation1' incorporates:
     *  Sqrt: '<S152>/Sqrt'
     */
    if (rtb_Sum_c > 100.0F) {
      rtb_Sum_c = 100.0F;
    } else {
      if (rtb_Sum_c < 8.0F) {
        rtb_Sum_c = 8.0F;
      }
    }

    /* End of Saturate: '<S152>/Saturation1' */

    /* Product: '<S152>/Multiply1' incorporates:
     *  Gain: '<S152>/Gain'
     *  Product: '<S152>/Divide'
     *  Trigonometry: '<S152>/Asin'
     */
    rtb_Sum_l *= atanf(-Controller_U.FMS_Out.w_cmd / rtb_Sum_c);

    /* Saturate: '<S152>/Saturation2' */
    if (rtb_Sum_l > 0.785398185F) {
      rtb_Sum_l = 0.785398185F;
    } else {
      if (rtb_Sum_l < -0.785398185F) {
        rtb_Sum_l = -0.785398185F;
      }
    }

    /* End of Saturate: '<S152>/Saturation2' */

    /* Sum: '<S145>/Sum' */
    rtb_Sum_l -= rtb_Saturation1_ih;

    /* Switch: '<S162>/Switch' incorporates:
     *  Constant: '<S163>/Constant'
     *  DiscreteIntegrator: '<S116>/Discrete-Time Integrator5'
     *  RelationalOperator: '<S163>/Compare'
     */
    if (rtb_PI_limit[0] >= 3.0F) {
      rtb_TmpSignalConversionAtMult_0 =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;
    } else {
      rtb_TmpSignalConversionAtMult_0 = rtb_PI_limit[0];
    }

    /* End of Switch: '<S162>/Switch' */

    /* Sum: '<S149>/Sum' incorporates:
     *  Gain: '<S149>/Gain'
     *  Sum: '<S149>/Minus'
     */
    rtb_VdotPg_err = (Controller_U.FMS_Out.u_cmd -
                      rtb_TmpSignalConversionAtMult_0) * 0.101936802F -
      rtb_VdotPg;

    /* Sum: '<S126>/Minus1' incorporates:
     *  Gain: '<S126>/ucmd2pitch'
     *  Gain: '<S126>/wcmd2pitch'
     */
    rtb_Ldot_err = CONTROL_PARAM.FW_TECS_W2P * rtb_Sum_l -
      CONTROL_PARAM.FW_TECS_U2P * rtb_VdotPg_err;

    /* DiscreteIntegrator: '<S157>/ ' */
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

    /* DiscreteIntegrator: '<S158>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_f != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_e = rtb_Ldot_err;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_b != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_e = rtb_Ldot_err;
    }

    /* Gain: '<S158>/Gain' incorporates:
     *  DiscreteIntegrator: '<S158>/Discrete-Time Integrator1'
     *  Sum: '<S158>/Sum5'
     */
    rtb_Gain_c4 = (rtb_Ldot_err - Controller_DW.DiscreteTimeIntegrator1_DSTAT_e)
      * 62.831852F;

    /* Switch: '<S138>/Switch1' incorporates:
     *  Constant: '<S144>/Constant'
     *  DiscreteIntegrator: '<S157>/ '
     *  Gain: '<S126>/Gain'
     *  Gain: '<S126>/balabnce_ratio2'
     *  Gain: '<S126>/balance_ratio'
     *  Gain: '<S126>/pitch_ff'
     *  Gain: '<S147>/P_control'
     *  RelationalOperator: '<S144>/Compare'
     *  Sum: '<S126>/Add3'
     *  Sum: '<S126>/Minus'
     *  Sum: '<S126>/Sum'
     *  Sum: '<S147>/Add'
     *  Switch: '<S158>/Switch'
     */
    if (rtb_BitwiseAND_n == 3) {
      rtb_Cos1 = Controller_U.FMS_Out.theta_cmd;
    } else {
      if (Controller_U.FMS_Out.reset > 0) {
        /* Switch: '<S158>/Switch' incorporates:
         *  Gain: '<S158>/Gain1'
         */
        rtb_Switch_j = 0.0F;
      } else {
        /* Switch: '<S158>/Switch' */
        rtb_Switch_j = rtb_Gain_c4;
      }

      /* Gain: '<S156>/Gain' */
      rtb_TmpSignalConversionAtMult_0 = CONTROL_PARAM.FW_TECS_PITCH_D *
        rtb_Switch_j;

      /* Saturate: '<S147>/Saturation1' */
      if (rtb_TmpSignalConversionAtMult_0 > 0.3F) {
        rtb_TmpSignalConversionAtMult_0 = 0.3F;
      } else {
        if (rtb_TmpSignalConversionAtMult_0 < -0.3F) {
          rtb_TmpSignalConversionAtMult_0 = -0.3F;
        }
      }

      /* End of Saturate: '<S147>/Saturation1' */
      rtb_Cos1 = (((2.0F - CONTROL_PARAM.FW_TECS_RATIO) * rtb_Saturation1_ih -
                   CONTROL_PARAM.FW_TECS_RATIO * rtb_VdotPg) *
                  CONTROL_PARAM.FW_TECS_PITCH_F +
                  ((CONTROL_PARAM.FW_TECS_PITCH_P * rtb_Ldot_err +
                    Controller_DW._DSTATE) + rtb_TmpSignalConversionAtMult_0)) +
        CONTROL_PARAM.FW_TECS_R2P * rtb_Abs;
    }

    /* End of Switch: '<S138>/Switch1' */

    /* Sum: '<S91>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_i_idx_1 = rtb_Cos - Controller_U.INS_Out.phi;
    rtb_Divide_m_idx_3 = rtb_Cos1 - Controller_U.INS_Out.theta;

    /* Product: '<S94>/Divide1' incorporates:
     *  Abs: '<S94>/Abs'
     *  Constant: '<S94>/const2'
     */
    rtb_TmpSignalConversionAtMult_2 = fabsf(rtb_Divide_i_idx_1) / 0.002F;

    /* Product: '<S94>/Divide' incorporates:
     *  Constant: '<S92>/Constant1'
     *  Constant: '<S94>/const1'
     *  Math: '<S94>/Square'
     *  SignalConversion: '<S94>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_TmpSignalConversionAtMult_1 = 9.5993F / (CONTROL_PARAM.MC_ROLL_P *
      CONTROL_PARAM.MC_ROLL_P);

    /* Signum: '<S94>/Sign' incorporates:
     *  Abs: '<S94>/Abs'
     */
    if (rtb_Divide_i_idx_1 < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else if (rtb_Divide_i_idx_1 > 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_0 = rtb_Divide_i_idx_1;
    }

    /* Switch: '<S94>/Switch' incorporates:
     *  Abs: '<S94>/Abs'
     *  Constant: '<S92>/Constant1'
     *  Gain: '<S94>/Gain1'
     *  Gain: '<S94>/Gain2'
     *  Logic: '<S94>/Logical Operator'
     *  Product: '<S94>/Divide'
     *  Product: '<S94>/Multiply'
     *  Product: '<S94>/Multiply1'
     *  Product: '<S94>/Multiply2'
     *  Product: '<S94>/Multiply3'
     *  RelationalOperator: '<S94>/Relational Operator'
     *  RelationalOperator: '<S94>/Relational Operator2'
     *  SignalConversion: '<S94>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S94>/Sqrt'
     *  Sum: '<S94>/Subtract'
     */
    if ((rtb_Divide_i_idx_1 <= rtb_TmpSignalConversionAtMult_1) &&
        (rtb_Divide_i_idx_1 >= -rtb_TmpSignalConversionAtMult_1)) {
      rtb_TmpSignalConversionAtMult_0 = rtb_Divide_i_idx_1 *
        CONTROL_PARAM.MC_ROLL_P;
    } else {
      rtb_TmpSignalConversionAtMult_0 *= sqrtf((rtb_TmpSignalConversionAtMult_0 *
        rtb_Divide_i_idx_1 - 0.5F * rtb_TmpSignalConversionAtMult_1) *
        Controller_ConstB.Gain_n);
    }

    /* Gain: '<S94>/Gain3' */
    rtb_Gain_a_idx_0 = -rtb_TmpSignalConversionAtMult_2;

    /* Switch: '<S95>/Switch' incorporates:
     *  Gain: '<S94>/Gain3'
     *  RelationalOperator: '<S95>/UpperRelop'
     */
    if (rtb_TmpSignalConversionAtMult_0 >= -rtb_TmpSignalConversionAtMult_2) {
      rtb_Gain_a_idx_0 = rtb_TmpSignalConversionAtMult_0;
    }

    /* Switch: '<S95>/Switch2' incorporates:
     *  RelationalOperator: '<S95>/LowerRelop1'
     */
    if (rtb_TmpSignalConversionAtMult_0 <= rtb_TmpSignalConversionAtMult_2) {
      rtb_TmpSignalConversionAtMult_2 = rtb_Gain_a_idx_0;
    }

    /* Saturate: '<S80>/Saturation1' */
    if (rtb_TmpSignalConversionAtMult_2 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_TmpSignalConversionAtMult_2 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_TmpSignalConversionAtMult_2 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_TmpSignalConversionAtMult_2 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    rtb_Divide_i_idx_0 = rtb_TmpSignalConversionAtMult_2;

    /* Product: '<S94>/Divide1' incorporates:
     *  Abs: '<S94>/Abs'
     *  Constant: '<S94>/const2'
     */
    rtb_TmpSignalConversionAtMult_2 = fabsf(rtb_Divide_m_idx_3) / 0.002F;

    /* Product: '<S94>/Divide' incorporates:
     *  Constant: '<S92>/Constant2'
     *  Constant: '<S94>/const1'
     *  Math: '<S94>/Square'
     *  SignalConversion: '<S94>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_TmpSignalConversionAtMult_1 = 9.5993F / (CONTROL_PARAM.MC_PITCH_P *
      CONTROL_PARAM.MC_PITCH_P);

    /* Signum: '<S94>/Sign' incorporates:
     *  Abs: '<S94>/Abs'
     */
    if (rtb_Divide_m_idx_3 < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else if (rtb_Divide_m_idx_3 > 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_0 = rtb_Divide_m_idx_3;
    }

    /* Switch: '<S94>/Switch' incorporates:
     *  Abs: '<S94>/Abs'
     *  Constant: '<S92>/Constant2'
     *  Gain: '<S94>/Gain1'
     *  Gain: '<S94>/Gain2'
     *  Logic: '<S94>/Logical Operator'
     *  Product: '<S94>/Divide'
     *  Product: '<S94>/Multiply'
     *  Product: '<S94>/Multiply1'
     *  Product: '<S94>/Multiply2'
     *  Product: '<S94>/Multiply3'
     *  RelationalOperator: '<S94>/Relational Operator'
     *  RelationalOperator: '<S94>/Relational Operator2'
     *  SignalConversion: '<S94>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S94>/Sqrt'
     *  Sum: '<S94>/Subtract'
     */
    if ((rtb_Divide_m_idx_3 <= rtb_TmpSignalConversionAtMult_1) &&
        (rtb_Divide_m_idx_3 >= -rtb_TmpSignalConversionAtMult_1)) {
      rtb_TmpSignalConversionAtMult_0 = rtb_Divide_m_idx_3 *
        CONTROL_PARAM.MC_PITCH_P;
    } else {
      rtb_TmpSignalConversionAtMult_0 *= sqrtf((rtb_TmpSignalConversionAtMult_0 *
        rtb_Divide_m_idx_3 - 0.5F * rtb_TmpSignalConversionAtMult_1) *
        Controller_ConstB.Gain_n);
    }

    /* Gain: '<S94>/Gain3' */
    rtb_Gain_a_idx_0 = -rtb_TmpSignalConversionAtMult_2;

    /* Switch: '<S95>/Switch' incorporates:
     *  Gain: '<S94>/Gain3'
     *  RelationalOperator: '<S95>/UpperRelop'
     */
    if (rtb_TmpSignalConversionAtMult_0 >= -rtb_TmpSignalConversionAtMult_2) {
      rtb_Gain_a_idx_0 = rtb_TmpSignalConversionAtMult_0;
    }

    /* Switch: '<S95>/Switch2' incorporates:
     *  RelationalOperator: '<S95>/LowerRelop1'
     */
    if (rtb_TmpSignalConversionAtMult_0 <= rtb_TmpSignalConversionAtMult_2) {
      rtb_TmpSignalConversionAtMult_2 = rtb_Gain_a_idx_0;
    }

    /* Saturate: '<S80>/Saturation1' */
    if (rtb_TmpSignalConversionAtMult_2 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_TmpSignalConversionAtMult_2 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_TmpSignalConversionAtMult_2 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_TmpSignalConversionAtMult_2 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    /* Saturate: '<S80>/Saturation' */
    if (Controller_U.FMS_Out.psi_rate_cmd > CONTROL_PARAM.MC_R_CMD_LIM) {
      rtb_Switch_j = CONTROL_PARAM.MC_R_CMD_LIM;
    } else if (Controller_U.FMS_Out.psi_rate_cmd < -CONTROL_PARAM.MC_R_CMD_LIM)
    {
      rtb_Switch_j = -CONTROL_PARAM.MC_R_CMD_LIM;
    } else {
      rtb_Switch_j = Controller_U.FMS_Out.psi_rate_cmd;
    }

    /* End of Saturate: '<S80>/Saturation' */

    /* Trigonometry: '<S89>/Sin' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S130>/Sin'
     */
    rtb_DiscreteTimeIntegrator1_e_t = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S89>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S130>/Cos1'
     */
    rtb_DiscreteTimeIntegrator1_a_t = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Trigonometry: '<S89>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S130>/Cos'
     */
    rtb_DiscreteTimeIntegrator_p_tm = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S89>/Sin1' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S130>/Sin1'
     */
    rtb_TmpSignalConversionAtMult_3 = arm_sin_f32(Controller_U.INS_Out.theta);

    /* Sum: '<S81>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S89>/Multiply'
     *  Product: '<S89>/Multiply1'
     *  Product: '<S89>/Multiply3'
     *  Product: '<S89>/Multiply4'
     *  Product: '<S89>/Multiply5'
     *  Sum: '<S89>/Add'
     *  Sum: '<S89>/Add1'
     *  Sum: '<S89>/Add2'
     *  Trigonometry: '<S89>/Cos'
     *  Trigonometry: '<S89>/Cos1'
     *  Trigonometry: '<S89>/Sin'
     *  Trigonometry: '<S89>/Sin1'
     */
    rtb_TmpSignalConversionAtMult_0 = (rtb_Divide_i_idx_0 -
      rtb_TmpSignalConversionAtMult_3 * rtb_Switch_j) - Controller_U.INS_Out.p;
    rtb_TmpSignalConversionAtMult_1 = (rtb_DiscreteTimeIntegrator1_e_t *
      rtb_DiscreteTimeIntegrator1_a_t * rtb_Switch_j +
      rtb_DiscreteTimeIntegrator_p_tm * rtb_TmpSignalConversionAtMult_2) -
      Controller_U.INS_Out.q;
    rtb_TmpSignalConversionAtMult_2 = (rtb_DiscreteTimeIntegrator_p_tm *
      rtb_DiscreteTimeIntegrator1_a_t * rtb_Switch_j -
      rtb_DiscreteTimeIntegrator1_e_t * rtb_TmpSignalConversionAtMult_2) -
      Controller_U.INS_Out.r;

    /* DiscreteIntegrator: '<S84>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_b != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0] =
        rtb_TmpSignalConversionAtMult_0;
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1] =
        rtb_TmpSignalConversionAtMult_1;
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2] =
        rtb_TmpSignalConversionAtMult_2;
    }

    /* DiscreteIntegrator: '<S88>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S84>/Discrete-Time Integrator5'
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

    /* Gain: '<S88>/Gain' incorporates:
     *  DiscreteIntegrator: '<S84>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S88>/Discrete-Time Integrator1'
     *  Sum: '<S88>/Sum5'
     */
    rtb_Gain_a_idx_0 = (Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0] -
                        Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[0]) *
      188.49556F;
    rtb_Gain_a_idx_1 = (Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1] -
                        Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[1]) *
      188.49556F;
    rtb_Gain_a_idx_2 = (Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2] -
                        Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[2]) *
      188.49556F;

    /* Switch: '<S88>/Switch' incorporates:
     *  Gain: '<S88>/Gain1'
     */
    if (rtb_LogicalOperator_i) {
      rtb_rate_err_B[0] = 0.0F;
      rtb_rate_err_B[1] = 0.0F;
      rtb_rate_err_B[2] = 0.0F;
    } else {
      rtb_rate_err_B[0] = rtb_Gain_a_idx_0;
      rtb_rate_err_B[1] = rtb_Gain_a_idx_1;
      rtb_rate_err_B[2] = rtb_Gain_a_idx_2;
    }

    /* End of Switch: '<S88>/Switch' */

    /* Product: '<S85>/Multiply' incorporates:
     *  Constant: '<S85>/gain1'
     */
    rtb_Divide_m_idx_3 = CONTROL_PARAM.MC_ROLL_RATE_D * rtb_rate_err_B[0];

    /* Saturate: '<S85>/Saturation' */
    if (rtb_Divide_m_idx_3 > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Divide_m_idx_3 = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Divide_m_idx_3 < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Divide_m_idx_3 = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    rtb_rate_err_B[0] = rtb_Divide_m_idx_3;

    /* Product: '<S85>/Multiply' incorporates:
     *  Constant: '<S85>/gain2'
     */
    rtb_Divide_m_idx_3 = CONTROL_PARAM.MC_PITCH_RATE_D * rtb_rate_err_B[1];

    /* Saturate: '<S85>/Saturation' */
    if (rtb_Divide_m_idx_3 > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Divide_m_idx_3 = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Divide_m_idx_3 < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Divide_m_idx_3 = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    rtb_rate_err_B[1] = rtb_Divide_m_idx_3;

    /* Product: '<S85>/Multiply' incorporates:
     *  Constant: '<S85>/gain3'
     */
    rtb_Divide_m_idx_3 = CONTROL_PARAM.MC_YAW_RATE_D * rtb_rate_err_B[2];

    /* Saturate: '<S85>/Saturation' */
    if (rtb_Divide_m_idx_3 > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Divide_m_idx_3 = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Divide_m_idx_3 < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Divide_m_idx_3 = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    /* Product: '<S70>/Multiply2' incorporates:
     *  Constant: '<S87>/gain1'
     *  DiscreteIntegrator: '<S114>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S84>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S86>/Discrete-Time Integrator'
     *  Product: '<S87>/Multiply'
     *  Sum: '<S82>/Add'
     */
    rtb_Sum_c = ((CONTROL_PARAM.MC_ROLL_RATE_P *
                  Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0] +
                  Controller_DW.DiscreteTimeIntegrator_DSTATE_d[0]) +
                 rtb_rate_err_B[0]) *
      Controller_DW.DiscreteTimeIntegrator5_DSTA_a2;

    /* Saturate: '<S70>/Saturation2' */
    if (rtb_Sum_c > 1.0F) {
      Controller_B.mc_torque_cmd[0] = 1.0F;
    } else if (rtb_Sum_c < -1.0F) {
      Controller_B.mc_torque_cmd[0] = -1.0F;
    } else {
      Controller_B.mc_torque_cmd[0] = rtb_Sum_c;
    }

    /* Product: '<S70>/Multiply2' incorporates:
     *  Constant: '<S87>/gain2'
     *  DiscreteIntegrator: '<S114>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S84>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S86>/Discrete-Time Integrator'
     *  Product: '<S87>/Multiply'
     *  Sum: '<S82>/Add'
     */
    rtb_Sum_c = ((CONTROL_PARAM.MC_PITCH_RATE_P *
                  Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1] +
                  Controller_DW.DiscreteTimeIntegrator_DSTATE_d[1]) +
                 rtb_rate_err_B[1]) *
      Controller_DW.DiscreteTimeIntegrator5_DSTA_a2;

    /* Saturate: '<S70>/Saturation2' */
    if (rtb_Sum_c > 1.0F) {
      Controller_B.mc_torque_cmd[1] = 1.0F;
    } else if (rtb_Sum_c < -1.0F) {
      Controller_B.mc_torque_cmd[1] = -1.0F;
    } else {
      Controller_B.mc_torque_cmd[1] = rtb_Sum_c;
    }

    /* Product: '<S70>/Multiply2' incorporates:
     *  Constant: '<S87>/gain3'
     *  DiscreteIntegrator: '<S114>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S84>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S86>/Discrete-Time Integrator'
     *  Product: '<S87>/Multiply'
     *  Sum: '<S82>/Add'
     */
    rtb_Sum_c = ((CONTROL_PARAM.MC_YAW_RATE_P *
                  Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2] +
                  Controller_DW.DiscreteTimeIntegrator_DSTATE_d[2]) +
                 rtb_Divide_m_idx_3) *
      Controller_DW.DiscreteTimeIntegrator5_DSTA_a2;

    /* Saturate: '<S70>/Saturation2' */
    if (rtb_Sum_c > 1.0F) {
      Controller_B.mc_torque_cmd[2] = 1.0F;
    } else if (rtb_Sum_c < -1.0F) {
      Controller_B.mc_torque_cmd[2] = -1.0F;
    } else {
      Controller_B.mc_torque_cmd[2] = rtb_Sum_c;
    }

    /* Gain: '<S104>/Gain' incorporates:
     *  DiscreteIntegrator: '<S106>/Integrator1'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S104>/Sum1'
     */
    rtb_Divide_i_idx_0 = -(Controller_DW.Integrator1_DSTATE_i -
      Controller_U.INS_Out.vd);

    /* Logic: '<S101>/Logical Operator' incorporates:
     *  Constant: '<S103>/Constant'
     *  DiscreteIntegrator: '<S114>/Discrete-Time Integrator5'
     *  RelationalOperator: '<S103>/Compare'
     */
    rtb_LogicalOperator_g = ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator5_DSTA_a2 == 0.0F));
    Controller_B.Constant_m = CONTROL_PARAM.MC_VEL_Z_I_MIN;

    /* DiscreteIntegrator: '<S109>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S109>/Constant'
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

    /* DiscreteIntegrator: '<S111>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_i != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_l = rtb_Divide_i_idx_0;
    }

    if (rtb_LogicalOperator_g || (Controller_DW.DiscreteTimeIntegrator1_PrevR_h
         != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_l = rtb_Divide_i_idx_0;
    }

    /* Gain: '<S111>/Gain' incorporates:
     *  DiscreteIntegrator: '<S111>/Discrete-Time Integrator1'
     *  Sum: '<S111>/Sum5'
     */
    rtb_Divide_i_idx_1 = (rtb_Divide_i_idx_0 -
                          Controller_DW.DiscreteTimeIntegrator1_DSTAT_l) *
      62.831852F;

    /* Switch: '<S111>/Switch' incorporates:
     *  Gain: '<S111>/Gain1'
     */
    if (rtb_LogicalOperator_g) {
      rtb_Divide_m_idx_3 = 0.0F;
    } else {
      rtb_Divide_m_idx_3 = rtb_Divide_i_idx_1;
    }

    /* End of Switch: '<S111>/Switch' */

    /* Product: '<S108>/Multiply' incorporates:
     *  Constant: '<S108>/kd'
     */
    rtb_DiscreteTimeIntegrator1_o = CONTROL_PARAM.MC_VEL_Z_D *
      rtb_Divide_m_idx_3;

    /* Saturate: '<S108>/Saturation' */
    if (rtb_DiscreteTimeIntegrator1_o > CONTROL_PARAM.MC_VEL_Z_D_MAX) {
      rtb_DiscreteTimeIntegrator1_o = CONTROL_PARAM.MC_VEL_Z_D_MAX;
    } else {
      if (rtb_DiscreteTimeIntegrator1_o < CONTROL_PARAM.MC_VEL_Z_D_MIN) {
        rtb_DiscreteTimeIntegrator1_o = CONTROL_PARAM.MC_VEL_Z_D_MIN;
      }
    }

    /* End of Saturate: '<S108>/Saturation' */

    /* Sum: '<S105>/Add' incorporates:
     *  Constant: '<S110>/kp'
     *  DiscreteIntegrator: '<S109>/Discrete-Time Integrator'
     *  Product: '<S110>/Multiply'
     */
    rtb_Divide_m_idx_3 = (CONTROL_PARAM.MC_VEL_Z_P * rtb_Divide_i_idx_0 +
                          Controller_DW.DiscreteTimeIntegrator_DSTATE_b) +
      rtb_DiscreteTimeIntegrator1_o;

    /* Product: '<S102>/Multiply' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S102>/Cos'
     *  Trigonometry: '<S102>/Cos1'
     */
    rtb_DiscreteTimeIntegrator1_o = arm_cos_f32(Controller_U.INS_Out.phi) *
      arm_cos_f32(Controller_U.INS_Out.theta);

    /* Saturate: '<S102>/Saturation1' */
    if (rtb_DiscreteTimeIntegrator1_o > 1.0F) {
      rtb_Switch_j = 1.0F;
    } else if (rtb_DiscreteTimeIntegrator1_o < 0.5F) {
      rtb_Switch_j = 0.5F;
    } else {
      rtb_Switch_j = rtb_DiscreteTimeIntegrator1_o;
    }

    /* End of Saturate: '<S102>/Saturation1' */

    /* Gain: '<S102>/Gain' */
    rtb_DiscreteTimeIntegrator1_o *= 2.0F;

    /* Saturate: '<S102>/Saturation' */
    if (rtb_DiscreteTimeIntegrator1_o > 1.0F) {
      rtb_DiscreteTimeIntegrator1_o = 1.0F;
    } else {
      if (rtb_DiscreteTimeIntegrator1_o < 0.0F) {
        rtb_DiscreteTimeIntegrator1_o = 0.0F;
      }
    }

    /* End of Saturate: '<S102>/Saturation' */

    /* Product: '<S102>/Multiply1' incorporates:
     *  Constant: '<S102>/Constant'
     *  Product: '<S102>/Divide'
     */
    rtb_DiscreteTimeIntegrator1_o *= 1.0F / rtb_Switch_j * rtb_Divide_m_idx_3;

    /* Saturate: '<S101>/Saturation' */
    if (rtb_DiscreteTimeIntegrator1_o > 0.35F) {
      rtb_DiscreteTimeIntegrator1_o = 0.35F;
    } else {
      if (rtb_DiscreteTimeIntegrator1_o < -0.35F) {
        rtb_DiscreteTimeIntegrator1_o = -0.35F;
      }
    }

    /* End of Saturate: '<S101>/Saturation' */

    /* Sum: '<S101>/Sum1' incorporates:
     *  Constant: '<S101>/hover_throttle'
     */
    rtb_DiscreteTimeIntegrator1_o += CONTROL_PARAM.MC_HOVER_THRO;

    /* Saturate: '<S70>/Saturation1' incorporates:
     *  Constant: '<S75>/Constant'
     *  Product: '<S70>/Multiply1'
     */
    Controller_B.mc_force_cmd[0] = 0.0F;
    Controller_B.mc_force_cmd[1] = 0.0F;

    /* Product: '<S70>/Multiply1' incorporates:
     *  DiscreteIntegrator: '<S114>/Discrete-Time Integrator5'
     */
    rtb_Sum_c = rtb_DiscreteTimeIntegrator1_o *
      Controller_DW.DiscreteTimeIntegrator5_DSTA_a2;

    /* Saturate: '<S70>/Saturation1' */
    if (rtb_Sum_c > 1.0F) {
      Controller_B.mc_force_cmd[2] = 1.0F;
    } else if (rtb_Sum_c < -1.0F) {
      Controller_B.mc_force_cmd[2] = -1.0F;
    } else {
      Controller_B.mc_force_cmd[2] = rtb_Sum_c;
    }

    /* DiscreteIntegrator: '<S134>/Discrete-Time Integrator' */
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

    /* Bias: '<S139>/Pitch Offset' */
    rtb_Cos1 += CONTROL_PARAM.FW_PITCH_OFFSET;

    /* Saturate: '<S139>/Saturation' */
    if (rtb_Cos1 > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Cos1 = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_Cos1 < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_Cos1 = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      }
    }

    /* Product: '<S140>/Multiply' incorporates:
     *  Constant: '<S140>/Constant2'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S139>/Sum'
     */
    rtb_Divide_m_idx_3 = (rtb_Cos1 - Controller_U.INS_Out.theta) *
      CONTROL_PARAM.FW_PITCH_P;

    /* Product: '<S142>/Divide' incorporates:
     *  Constant: '<S142>/Constant'
     *  DiscreteIntegrator: '<S116>/Discrete-Time Integrator5'
     */
    rtb_Sum_c = 9.81F / Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;

    /* Saturate: '<S142>/Saturation' */
    if (rtb_Sum_c > 1.0F) {
      rtb_Sum_c = 1.0F;
    } else {
      if (rtb_Sum_c < 0.0F) {
        rtb_Sum_c = 0.0F;
      }
    }

    /* End of Saturate: '<S142>/Saturation' */

    /* Sum: '<S137>/Sum' incorporates:
     *  Product: '<S142>/Multiply'
     *  Product: '<S142>/Multiply1'
     *  Trigonometry: '<S142>/Cos'
     *  Trigonometry: '<S142>/Tan'
     */
    rtb_Switch_j = tanf(Controller_U.FMS_Out.phi_cmd) * arm_cos_f32
      (Controller_U.FMS_Out.theta_cmd) * rtb_Sum_c +
      Controller_U.FMS_Out.psi_rate_cmd;

    /* Saturate: '<S139>/Saturation' */
    if (rtb_Cos > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Cos = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_Cos < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_Cos = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      }
    }

    /* Sum: '<S130>/Add' incorporates:
     *  Constant: '<S140>/Constant1'
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S130>/Multiply'
     *  Product: '<S140>/Multiply'
     *  Sum: '<S139>/Sum'
     */
    rtb_DiscreteTimeIntegrator1_o = (rtb_Cos - Controller_U.INS_Out.phi) *
      CONTROL_PARAM.FW_ROLL_P - rtb_TmpSignalConversionAtMult_3 * rtb_Switch_j;

    /* Sum: '<S130>/Add1' incorporates:
     *  Product: '<S130>/Multiply1'
     *  Product: '<S130>/Multiply3'
     */
    rtb_Cos = rtb_DiscreteTimeIntegrator1_e_t * rtb_DiscreteTimeIntegrator1_a_t *
      rtb_Switch_j + rtb_DiscreteTimeIntegrator_p_tm * rtb_Divide_m_idx_3;

    /* Sum: '<S130>/Add2' incorporates:
     *  Product: '<S130>/Multiply4'
     *  Product: '<S130>/Multiply5'
     */
    rtb_Divide_m_idx_3 = rtb_DiscreteTimeIntegrator_p_tm *
      rtb_DiscreteTimeIntegrator1_a_t * rtb_Switch_j -
      rtb_DiscreteTimeIntegrator1_e_t * rtb_Divide_m_idx_3;

    /* Sum: '<S128>/Minus2' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_rate_err_B[0] = rtb_DiscreteTimeIntegrator1_o - Controller_U.INS_Out.p;
    rtb_rate_err_B[1] = rtb_Cos - Controller_U.INS_Out.q;
    rtb_rate_err_B[2] = rtb_Divide_m_idx_3 - Controller_U.INS_Out.r;

    /* Product: '<S132>/Divide' incorporates:
     *  Constant: '<S132>/trim_speed'
     *  Math: '<S132>/Square'
     */
    rtb_Switch_j = CONTROL_PARAM.FW_AIRSPEED_TRIM *
      CONTROL_PARAM.FW_AIRSPEED_TRIM / rtb_Add4_m;

    /* Saturate: '<S132>/Saturation' */
    if (rtb_Switch_j > 1.0F) {
      rtb_Switch_j = 1.0F;
    } else {
      if (rtb_Switch_j < 0.0F) {
        rtb_Switch_j = 0.0F;
      }
    }

    /* End of Saturate: '<S132>/Saturation' */

    /* Product: '<S128>/Multiply' incorporates:
     *  Constant: '<S135>/gain1'
     *  Constant: '<S135>/gain2'
     *  Constant: '<S135>/gain3'
     *  DiscreteIntegrator: '<S134>/Discrete-Time Integrator'
     *  Product: '<S135>/Multiply'
     *  Sum: '<S131>/Add1'
     */
    rtb_Sum_c = (CONTROL_PARAM.FW_ROLL_RATE_P * rtb_rate_err_B[0] +
                 Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0]) *
      rtb_Switch_j;
    rtb_Add4_m = (CONTROL_PARAM.FW_PITCH_RATE_P * rtb_rate_err_B[1] +
                  Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1]) *
      rtb_Switch_j;
    rtb_Cos1 = (CONTROL_PARAM.FW_YAW_RATE_P * rtb_rate_err_B[2] +
                Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2]) * rtb_Switch_j;

    /* Product: '<S133>/Divide' incorporates:
     *  Constant: '<S133>/trim_speed'
     *  DiscreteIntegrator: '<S116>/Discrete-Time Integrator5'
     */
    rtb_Switch_j = CONTROL_PARAM.FW_AIRSPEED_TRIM /
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;

    /* Saturate: '<S133>/Saturation' */
    if (rtb_Switch_j > 1.0F) {
      rtb_Switch_j = 1.0F;
    } else {
      if (rtb_Switch_j < 0.0F) {
        rtb_Switch_j = 0.0F;
      }
    }

    /* End of Saturate: '<S133>/Saturation' */

    /* DiscreteIntegrator: '<S113>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_g != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTA_jo = rtb_Saturation_j;
    }

    /* Product: '<S128>/Multiply1' incorporates:
     *  Gain: '<S128>/FF'
     */
    rtb_DiscreteTimeIntegrator1_o = CONTROL_PARAM.FW_FF *
      rtb_DiscreteTimeIntegrator1_o * rtb_Switch_j;

    /* Saturate: '<S128>/FF_limit' */
    if (rtb_DiscreteTimeIntegrator1_o > CONTROL_PARAM.FW_FF_LIMIT) {
      rtb_DiscreteTimeIntegrator1_o = CONTROL_PARAM.FW_FF_LIMIT;
    } else {
      if (rtb_DiscreteTimeIntegrator1_o < -CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_DiscreteTimeIntegrator1_o = -CONTROL_PARAM.FW_FF_LIMIT;
      }
    }

    /* Saturate: '<S128>/PI_limit' */
    if (rtb_Sum_c > CONTROL_PARAM.FW_PI_LIMIT) {
      rtb_Sum_c = CONTROL_PARAM.FW_PI_LIMIT;
    } else {
      if (rtb_Sum_c < -CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_Sum_c = -CONTROL_PARAM.FW_PI_LIMIT;
      }
    }

    /* Product: '<S72>/Multiply' incorporates:
     *  DiscreteIntegrator: '<S113>/Discrete-Time Integrator5'
     *  Sum: '<S128>/Add'
     */
    rtb_Sum_c = (rtb_DiscreteTimeIntegrator1_o + rtb_Sum_c) *
      Controller_DW.DiscreteTimeIntegrator5_DSTA_jo;

    /* Saturate: '<S72>/Saturation1' */
    if (rtb_Sum_c > 1.0F) {
      Controller_B.fw_torque_cmd[0] = 1.0F;
    } else if (rtb_Sum_c < -1.0F) {
      Controller_B.fw_torque_cmd[0] = -1.0F;
    } else {
      Controller_B.fw_torque_cmd[0] = rtb_Sum_c;
    }

    /* Product: '<S128>/Multiply1' incorporates:
     *  Gain: '<S128>/FF'
     */
    rtb_Sum_c = CONTROL_PARAM.FW_FF * rtb_Cos * rtb_Switch_j;

    /* Saturate: '<S128>/FF_limit' */
    if (rtb_Sum_c > CONTROL_PARAM.FW_FF_LIMIT) {
      rtb_Sum_c = CONTROL_PARAM.FW_FF_LIMIT;
    } else {
      if (rtb_Sum_c < -CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_Sum_c = -CONTROL_PARAM.FW_FF_LIMIT;
      }
    }

    /* Saturate: '<S128>/PI_limit' */
    if (rtb_Add4_m > CONTROL_PARAM.FW_PI_LIMIT) {
      rtb_Add4_m = CONTROL_PARAM.FW_PI_LIMIT;
    } else {
      if (rtb_Add4_m < -CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_Add4_m = -CONTROL_PARAM.FW_PI_LIMIT;
      }
    }

    /* Product: '<S72>/Multiply' incorporates:
     *  DiscreteIntegrator: '<S113>/Discrete-Time Integrator5'
     *  Sum: '<S128>/Add'
     */
    rtb_Sum_c = (rtb_Sum_c + rtb_Add4_m) *
      Controller_DW.DiscreteTimeIntegrator5_DSTA_jo;

    /* Saturate: '<S72>/Saturation1' */
    if (rtb_Sum_c > 1.0F) {
      Controller_B.fw_torque_cmd[1] = 1.0F;
    } else if (rtb_Sum_c < -1.0F) {
      Controller_B.fw_torque_cmd[1] = -1.0F;
    } else {
      Controller_B.fw_torque_cmd[1] = rtb_Sum_c;
    }

    /* Product: '<S128>/Multiply1' incorporates:
     *  Gain: '<S128>/FF'
     */
    rtb_Sum_c = CONTROL_PARAM.FW_FF * rtb_Divide_m_idx_3 * rtb_Switch_j;

    /* Saturate: '<S128>/FF_limit' */
    if (rtb_Sum_c > CONTROL_PARAM.FW_FF_LIMIT) {
      rtb_Sum_c = CONTROL_PARAM.FW_FF_LIMIT;
    } else {
      if (rtb_Sum_c < -CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_Sum_c = -CONTROL_PARAM.FW_FF_LIMIT;
      }
    }

    /* Saturate: '<S128>/PI_limit' */
    if (rtb_Cos1 > CONTROL_PARAM.FW_PI_LIMIT) {
      rtb_Cos1 = CONTROL_PARAM.FW_PI_LIMIT;
    } else {
      if (rtb_Cos1 < -CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_Cos1 = -CONTROL_PARAM.FW_PI_LIMIT;
      }
    }

    /* Product: '<S72>/Multiply' incorporates:
     *  DiscreteIntegrator: '<S113>/Discrete-Time Integrator5'
     *  Sum: '<S128>/Add'
     */
    rtb_Sum_c = (rtb_Sum_c + rtb_Cos1) *
      Controller_DW.DiscreteTimeIntegrator5_DSTA_jo;

    /* Saturate: '<S72>/Saturation1' */
    if (rtb_Sum_c > 1.0F) {
      Controller_B.fw_torque_cmd[2] = 1.0F;
    } else if (rtb_Sum_c < -1.0F) {
      Controller_B.fw_torque_cmd[2] = -1.0F;
    } else {
      Controller_B.fw_torque_cmd[2] = rtb_Sum_c;
    }

    /* Product: '<S107>/Multiply1' incorporates:
     *  Constant: '<S107>/const1'
     *  DiscreteIntegrator: '<S106>/Integrator'
     */
    rtb_Switch_j = Controller_DW.Integrator_DSTATE_f * 0.05F;

    /* Sum: '<S107>/Add' incorporates:
     *  DiscreteIntegrator: '<S106>/Integrator1'
     *  Sum: '<S106>/Subtract'
     */
    rtb_DiscreteTimeIntegrator1_o = (Controller_DW.Integrator1_DSTATE_i -
      Controller_U.FMS_Out.w_cmd) + rtb_Switch_j;

    /* Signum: '<S107>/Sign' */
    if (rtb_DiscreteTimeIntegrator1_o < 0.0F) {
      rtb_Divide_m_idx_3 = -1.0F;
    } else if (rtb_DiscreteTimeIntegrator1_o > 0.0F) {
      rtb_Divide_m_idx_3 = 1.0F;
    } else {
      rtb_Divide_m_idx_3 = rtb_DiscreteTimeIntegrator1_o;
    }

    /* End of Signum: '<S107>/Sign' */

    /* Sum: '<S107>/Add2' incorporates:
     *  Abs: '<S107>/Abs'
     *  Gain: '<S107>/Gain'
     *  Gain: '<S107>/Gain1'
     *  Product: '<S107>/Multiply2'
     *  Product: '<S107>/Multiply3'
     *  Sqrt: '<S107>/Sqrt'
     *  Sum: '<S107>/Add1'
     *  Sum: '<S107>/Subtract'
     */
    rtb_Divide_m_idx_3 = (sqrtf((8.0F * fabsf(rtb_DiscreteTimeIntegrator1_o) +
      Controller_ConstB.d_m) * Controller_ConstB.d_m) - Controller_ConstB.d_m) *
      0.5F * rtb_Divide_m_idx_3 + rtb_Switch_j;

    /* Sum: '<S107>/Add4' */
    rtb_Add4_m = (rtb_DiscreteTimeIntegrator1_o - rtb_Divide_m_idx_3) +
      rtb_Switch_j;

    /* Sum: '<S107>/Add3' */
    rtb_Sum_c = rtb_DiscreteTimeIntegrator1_o + Controller_ConstB.d_m;

    /* Sum: '<S107>/Subtract1' */
    rtb_DiscreteTimeIntegrator1_o -= Controller_ConstB.d_m;

    /* Signum: '<S107>/Sign1' */
    if (rtb_Sum_c < 0.0F) {
      rtb_Sum_c = -1.0F;
    } else {
      if (rtb_Sum_c > 0.0F) {
        rtb_Sum_c = 1.0F;
      }
    }

    /* End of Signum: '<S107>/Sign1' */

    /* Signum: '<S107>/Sign2' */
    if (rtb_DiscreteTimeIntegrator1_o < 0.0F) {
      rtb_DiscreteTimeIntegrator1_o = -1.0F;
    } else {
      if (rtb_DiscreteTimeIntegrator1_o > 0.0F) {
        rtb_DiscreteTimeIntegrator1_o = 1.0F;
      }
    }

    /* End of Signum: '<S107>/Sign2' */

    /* Sum: '<S107>/Add5' incorporates:
     *  Gain: '<S107>/Gain2'
     *  Product: '<S107>/Multiply4'
     *  Sum: '<S107>/Subtract2'
     */
    rtb_Divide_m_idx_3 += (rtb_Sum_c - rtb_DiscreteTimeIntegrator1_o) * 0.5F *
      rtb_Add4_m;

    /* Sum: '<S126>/Add' incorporates:
     *  Gain: '<S126>/ucmd2thor'
     *  Gain: '<S126>/wcmd2thor'
     */
    rtb_Sum_l = CONTROL_PARAM.FW_TECS_W2T * rtb_Sum_l +
      CONTROL_PARAM.FW_TECS_U2T * rtb_VdotPg_err;

    /* DiscreteIntegrator: '<S160>/ ' */
    if ((Controller_U.FMS_Out.reset != 0) || (Controller_DW._PrevResetState_e !=
         0)) {
      Controller_DW._DSTATE_d = Controller_ConstB.Zero;
      if (Controller_DW._DSTATE_d >= CONTROL_PARAM.FW_CRUISE_THRO) {
        Controller_DW._DSTATE_d = CONTROL_PARAM.FW_CRUISE_THRO;
      } else {
        if (Controller_DW._DSTATE_d <= -CONTROL_PARAM.FW_CRUISE_THRO) {
          Controller_DW._DSTATE_d = -CONTROL_PARAM.FW_CRUISE_THRO;
        }
      }
    }

    if (Controller_DW._DSTATE_d >= CONTROL_PARAM.FW_CRUISE_THRO) {
      Controller_DW._DSTATE_d = CONTROL_PARAM.FW_CRUISE_THRO;
    } else {
      if (Controller_DW._DSTATE_d <= -CONTROL_PARAM.FW_CRUISE_THRO) {
        Controller_DW._DSTATE_d = -CONTROL_PARAM.FW_CRUISE_THRO;
      }
    }

    /* DiscreteIntegrator: '<S161>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_L_h0 != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm = rtb_Sum_l;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_d != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm = rtb_Sum_l;
    }

    /* Gain: '<S161>/Gain' incorporates:
     *  DiscreteIntegrator: '<S161>/Discrete-Time Integrator1'
     *  Sum: '<S161>/Sum5'
     */
    rtb_VdotPg_err = (rtb_Sum_l - Controller_DW.DiscreteTimeIntegrator1_DSTA_nm)
      * 188.49556F;

    /* Switch: '<S127>/Switch' incorporates:
     *  Bias: '<S127>/Bias'
     *  Constant: '<S170>/Constant'
     *  Gain: '<S127>/Gain'
     *  RelationalOperator: '<S170>/Compare'
     *  Switch: '<S161>/Switch'
     */
    if (rtb_BitwiseAND_n <= 3) {
      rtb_Switch_j = 0.000999987125F * (real32_T)
        Controller_U.FMS_Out.throttle_cmd + -1.0F;
    } else {
      if (Controller_U.FMS_Out.reset > 0) {
        /* Switch: '<S161>/Switch' incorporates:
         *  Gain: '<S161>/Gain1'
         */
        rtb_Switch_j = 0.0F;
      } else {
        /* Switch: '<S161>/Switch' */
        rtb_Switch_j = rtb_VdotPg_err;
      }

      /* Gain: '<S159>/Gain' */
      rtb_Sum_c = CONTROL_PARAM.FW_TECS_THOR_D * rtb_Switch_j;

      /* Saturate: '<S148>/Saturation1' */
      if (rtb_Sum_c > 0.3F) {
        rtb_Sum_c = 0.3F;
      } else {
        if (rtb_Sum_c < -0.3F) {
          rtb_Sum_c = -0.3F;
        }
      }

      /* End of Saturate: '<S148>/Saturation1' */

      /* Sum: '<S127>/Sum' incorporates:
       *  Constant: '<S127>/cruise_throttle'
       *  DiscreteIntegrator: '<S160>/ '
       *  Gain: '<S126>/Gain1'
       *  Gain: '<S126>/thorttle_ff'
       *  Gain: '<S148>/P_control'
       *  Sum: '<S126>/Add1'
       *  Sum: '<S126>/Add2'
       *  Sum: '<S126>/Sum1'
       *  Sum: '<S148>/Add4'
       */
      rtb_Switch_j = ((((CONTROL_PARAM.FW_TECS_THOR_P * rtb_Sum_l +
                         Controller_DW._DSTATE_d) + rtb_Sum_c) +
                       (rtb_Saturation1_ih + rtb_VdotPg) *
                       CONTROL_PARAM.FW_TECS_THOR_FF) +
                      CONTROL_PARAM.FW_TECS_R2T * rtb_Abs) +
        CONTROL_PARAM.FW_CRUISE_THRO;

      /* Saturate: '<S127>/Saturation' */
      if (rtb_Switch_j > 1.0F) {
        rtb_Switch_j = 1.0F;
      } else {
        if (rtb_Switch_j < -1.0F) {
          rtb_Switch_j = -1.0F;
        }
      }

      /* End of Saturate: '<S127>/Saturation' */
    }

    /* End of Switch: '<S127>/Switch' */

    /* Saturate: '<S127>/Saturation2' incorporates:
     *  Constant: '<S127>/Constant'
     */
    if (rtb_Switch_j > 1.0F) {
      Controller_B.fw_force_cmd[0] = 1.0F;
    } else {
      Controller_B.fw_force_cmd[0] = rtb_Switch_j;
    }

    Controller_B.fw_force_cmd[1] = 0.0F;
    Controller_B.fw_force_cmd[2] = 0.0F;

    /* End of Saturate: '<S127>/Saturation2' */

    /* Update for DiscreteIntegrator: '<S116>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S116>/Gain'
     *  Sum: '<S116>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_e = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_j += (rtb_Divide_i_idx_2 -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j) * 125.663704F * 0.002F;

    /* Update for DiscreteIntegrator: '<S115>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S115>/Gain'
     *  Sum: '<S115>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_L_eo = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_a += (rtb_Divide_i_idx_3 -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_a) * 31.415926F * 0.002F;

    /* Update for DiscreteIntegrator: '<S114>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S114>/Gain'
     *  Sum: '<S114>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_o = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTA_a2 += ((real32_T)rtb_Relay -
      Controller_DW.DiscreteTimeIntegrator5_DSTA_a2) * 6.28318548F * 0.002F;

    /* Update for DiscreteIntegrator: '<S86>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S86>/gain1'
     *  Constant: '<S86>/gain2'
     *  Constant: '<S86>/gain3'
     *  DiscreteIntegrator: '<S84>/Discrete-Time Integrator5'
     *  Product: '<S86>/Multiply'
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

    /* End of Update for DiscreteIntegrator: '<S86>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S157>/ ' incorporates:
     *  Gain: '<S157>/Gain3'
     */
    Controller_DW._DSTATE += CONTROL_PARAM.FW_TECS_PITCH_I * rtb_Ldot_err *
      0.002F;
    if (Controller_DW._DSTATE >= CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
      Controller_DW._DSTATE = CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
    } else {
      if (Controller_DW._DSTATE <= -CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
        Controller_DW._DSTATE = -CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
      }
    }

    Controller_DW._PrevResetState = (int8_T)(Controller_U.FMS_Out.reset > 0);

    /* End of Update for DiscreteIntegrator: '<S157>/ ' */

    /* Update for DiscreteIntegrator: '<S158>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_f = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_e += 0.002F * rtb_Gain_c4;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_b = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S84>/Discrete-Time Integrator5' */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_b = 0U;

    /* Update for DiscreteIntegrator: '<S88>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_h = 0U;

    /* Update for DiscreteIntegrator: '<S84>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S84>/Gain'
     *  Sum: '<S84>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0] +=
      (rtb_TmpSignalConversionAtMult_0 -
       Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S88>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[0] += 0.002F *
      rtb_Gain_a_idx_0;

    /* Update for DiscreteIntegrator: '<S84>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S84>/Gain'
     *  Sum: '<S84>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1] +=
      (rtb_TmpSignalConversionAtMult_1 -
       Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S88>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[1] += 0.002F *
      rtb_Gain_a_idx_1;

    /* Update for DiscreteIntegrator: '<S84>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S84>/Gain'
     *  Sum: '<S84>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2] +=
      (rtb_TmpSignalConversionAtMult_2 -
       Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S88>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[2] += 0.002F *
      rtb_Gain_a_idx_2;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_l = (int8_T)
      rtb_LogicalOperator_i;

    /* Update for DiscreteIntegrator: '<S106>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S106>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_i += 0.002F *
      Controller_DW.Integrator_DSTATE_f;

    /* Update for DiscreteIntegrator: '<S109>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S109>/ki'
     *  Product: '<S109>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_b += CONTROL_PARAM.MC_VEL_Z_I *
      rtb_Divide_i_idx_0 * 0.002F;
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

    /* End of Update for DiscreteIntegrator: '<S109>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S111>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_i = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_l += 0.002F * rtb_Divide_i_idx_1;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_h = (int8_T)
      rtb_LogicalOperator_g;

    /* Update for DiscreteIntegrator: '<S134>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S134>/gain1'
     *  Constant: '<S134>/gain2'
     *  Constant: '<S134>/gain3'
     *  Product: '<S134>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0] +=
      CONTROL_PARAM.FW_ROLL_RATE_I * rtb_rate_err_B[0] * 0.002F;
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
      CONTROL_PARAM.FW_PITCH_RATE_I * rtb_rate_err_B[1] * 0.002F;
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
      CONTROL_PARAM.FW_YAW_RATE_I * rtb_rate_err_B[2] * 0.002F;
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

    /* End of Update for DiscreteIntegrator: '<S134>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S113>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S113>/Gain'
     *  Sum: '<S113>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_g = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTA_jo += (rtb_Saturation_j -
      Controller_DW.DiscreteTimeIntegrator5_DSTA_jo) * 12.566371F * 0.002F;

    /* Signum: '<S107>/Sign6' incorporates:
     *  Signum: '<S107>/Sign5'
     */
    if (rtb_Divide_m_idx_3 < 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = -1.0F;

      /* Signum: '<S107>/Sign5' */
      rtb_TmpSignalConversionAtMult_2 = -1.0F;
    } else if (rtb_Divide_m_idx_3 > 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = 1.0F;

      /* Signum: '<S107>/Sign5' */
      rtb_TmpSignalConversionAtMult_2 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_1 = rtb_Divide_m_idx_3;

      /* Signum: '<S107>/Sign5' */
      rtb_TmpSignalConversionAtMult_2 = rtb_Divide_m_idx_3;
    }

    /* End of Signum: '<S107>/Sign6' */

    /* Sum: '<S107>/Add6' */
    rtb_Sum_c = rtb_Divide_m_idx_3 + Controller_ConstB.d_m;

    /* Sum: '<S107>/Subtract3' */
    rtb_TmpSignalConversionAtMult_0 = rtb_Divide_m_idx_3 - Controller_ConstB.d_m;

    /* Signum: '<S107>/Sign3' */
    if (rtb_Sum_c < 0.0F) {
      rtb_Sum_c = -1.0F;
    } else {
      if (rtb_Sum_c > 0.0F) {
        rtb_Sum_c = 1.0F;
      }
    }

    /* End of Signum: '<S107>/Sign3' */

    /* Signum: '<S107>/Sign4' */
    if (rtb_TmpSignalConversionAtMult_0 < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else {
      if (rtb_TmpSignalConversionAtMult_0 > 0.0F) {
        rtb_TmpSignalConversionAtMult_0 = 1.0F;
      }
    }

    /* End of Signum: '<S107>/Sign4' */

    /* Update for DiscreteIntegrator: '<S106>/Integrator' incorporates:
     *  Constant: '<S107>/const'
     *  Gain: '<S107>/Gain3'
     *  Product: '<S107>/Divide'
     *  Product: '<S107>/Multiply5'
     *  Product: '<S107>/Multiply6'
     *  Sum: '<S107>/Subtract4'
     *  Sum: '<S107>/Subtract5'
     *  Sum: '<S107>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE_f += ((rtb_Divide_m_idx_3 /
      Controller_ConstB.d_m - rtb_TmpSignalConversionAtMult_2) *
      Controller_ConstB.Gain4_o * ((rtb_Sum_c - rtb_TmpSignalConversionAtMult_0)
      * 0.5F) - rtb_TmpSignalConversionAtMult_1 * 78.448F) * 0.002F;

    /* Update for DiscreteIntegrator: '<S160>/ ' incorporates:
     *  Gain: '<S160>/Gain'
     */
    Controller_DW._DSTATE_d += CONTROL_PARAM.FW_TECS_THOR_I * rtb_Sum_l * 0.002F;
    if (Controller_DW._DSTATE_d >= CONTROL_PARAM.FW_CRUISE_THRO) {
      Controller_DW._DSTATE_d = CONTROL_PARAM.FW_CRUISE_THRO;
    } else {
      if (Controller_DW._DSTATE_d <= -CONTROL_PARAM.FW_CRUISE_THRO) {
        Controller_DW._DSTATE_d = -CONTROL_PARAM.FW_CRUISE_THRO;
      }
    }

    Controller_DW._PrevResetState_e = (int8_T)(Controller_U.FMS_Out.reset > 0);

    /* End of Update for DiscreteIntegrator: '<S160>/ ' */

    /* Update for DiscreteIntegrator: '<S161>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_L_h0 = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTA_nm += 0.002F * rtb_VdotPg_err;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_d = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* End of Outputs for SubSystem: '<S2>/FW_Controller' */
    break;

   case 1:
    if (Controller_DW.SwitchCase1_ActiveSubsystem != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S2>/MC_Controller' incorporates:
       *  ActionPort: '<S6>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S9>/Switch Case1' incorporates:
       *  DiscreteIntegrator: '<S184>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S186>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S188>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S208>/Integrator'
       *  DiscreteIntegrator: '<S208>/Integrator1'
       *  DiscreteIntegrator: '<S213>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S215>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S231>/Integrator'
       *  DiscreteIntegrator: '<S231>/Integrator1'
       *  DiscreteIntegrator: '<S234>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S236>/Discrete-Time Integrator1'
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
     *  ActionPort: '<S6>/Action Port'
     */
    /* SignalConversion: '<S6>/BusConversion_InsertedFor_VTOL_actuator_cmd_at_inport_0' */
    Controller_B.fw_torque_cmd[0] = Controller_ConstB.fw_torque_cmd[0];

    /* SignalConversion: '<S6>/BusConversion_InsertedFor_VTOL_actuator_cmd_at_inport_0' */
    Controller_B.fw_force_cmd[0] = Controller_ConstB.fw_force_cmd[0];

    /* SignalConversion: '<S6>/BusConversion_InsertedFor_VTOL_actuator_cmd_at_inport_0' */
    Controller_B.fw_torque_cmd[1] = Controller_ConstB.fw_torque_cmd[1];

    /* SignalConversion: '<S6>/BusConversion_InsertedFor_VTOL_actuator_cmd_at_inport_0' */
    Controller_B.fw_force_cmd[1] = Controller_ConstB.fw_force_cmd[1];

    /* SignalConversion: '<S6>/BusConversion_InsertedFor_VTOL_actuator_cmd_at_inport_0' */
    Controller_B.fw_torque_cmd[2] = Controller_ConstB.fw_torque_cmd[2];

    /* SignalConversion: '<S6>/BusConversion_InsertedFor_VTOL_actuator_cmd_at_inport_0' */
    Controller_B.fw_force_cmd[2] = Controller_ConstB.fw_force_cmd[2];

    /* DiscreteIntegrator: '<S186>/Discrete-Time Integrator' */
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

    /* Trigonometry: '<S210>/Trigonometric Function1' incorporates:
     *  Gain: '<S209>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1_b[0] = arm_cos_f32(-Controller_U.INS_Out.psi);

    /* Trigonometry: '<S210>/Trigonometric Function' incorporates:
     *  Gain: '<S209>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1_b[1] = arm_sin_f32(-Controller_U.INS_Out.psi);

    /* SignalConversion: '<S210>/ConcatBufferAtVector Concatenate1In3' incorporates:
     *  Constant: '<S210>/Constant3'
     */
    rtb_MatrixConcatenate1_b[2] = 0.0F;

    /* Gain: '<S210>/Gain' incorporates:
     *  Gain: '<S209>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S210>/Trigonometric Function2'
     */
    rtb_MatrixConcatenate1_b[3] = -arm_sin_f32(-Controller_U.INS_Out.psi);

    /* Trigonometry: '<S210>/Trigonometric Function3' incorporates:
     *  Gain: '<S209>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1_b[4] = arm_cos_f32(-Controller_U.INS_Out.psi);

    /* SignalConversion: '<S210>/ConcatBufferAtVector Concatenate2In3' incorporates:
     *  Constant: '<S210>/Constant4'
     */
    rtb_MatrixConcatenate1_b[5] = 0.0F;

    /* SignalConversion: '<S210>/ConcatBufferAtVector ConcatenateIn3' */
    rtb_MatrixConcatenate1_b[6] = Controller_ConstB.VectorConcatenate3[0];
    rtb_MatrixConcatenate1_b[7] = Controller_ConstB.VectorConcatenate3[1];
    rtb_MatrixConcatenate1_b[8] = Controller_ConstB.VectorConcatenate3[2];

    /* Product: '<S207>/Multiply' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  SignalConversion: '<S207>/TmpSignal ConversionAtMultiplyInport2'
     */
    for (rtb_Relay = 0; rtb_Relay < 3; rtb_Relay++) {
      rtb_MatrixConcatenate1_p[rtb_Relay] = rtb_MatrixConcatenate1_b[rtb_Relay +
        3] * Controller_U.INS_Out.ve + rtb_MatrixConcatenate1_b[rtb_Relay] *
        Controller_U.INS_Out.vn;
    }

    /* End of Product: '<S207>/Multiply' */

    /* Sum: '<S204>/Sum' incorporates:
     *  DiscreteIntegrator: '<S208>/Integrator1'
     */
    rtb_Divide_i_idx_1 = Controller_DW.Integrator1_DSTATE[0] -
      rtb_MatrixConcatenate1_p[0];
    rtb_Divide_m_idx_3 = Controller_DW.Integrator1_DSTATE[1] -
      rtb_MatrixConcatenate1_p[1];

    /* DiscreteIntegrator: '<S213>/Discrete-Time Integrator' */
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

    /* DiscreteIntegrator: '<S215>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] = rtb_Divide_i_idx_1;
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] = rtb_Divide_m_idx_3;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevRes != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] = rtb_Divide_i_idx_1;
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] = rtb_Divide_m_idx_3;
    }

    /* Gain: '<S215>/Gain' incorporates:
     *  DiscreteIntegrator: '<S215>/Discrete-Time Integrator1'
     *  Sum: '<S215>/Sum5'
     */
    rtb_Divide_i_idx_0 = (rtb_Divide_i_idx_1 -
                          Controller_DW.DiscreteTimeIntegrator1_DSTATE[0]) *
      62.831852F;
    rtb_Divide_i_idx_2 = (rtb_Divide_m_idx_3 -
                          Controller_DW.DiscreteTimeIntegrator1_DSTATE[1]) *
      62.831852F;

    /* Switch: '<S215>/Switch' incorporates:
     *  Gain: '<S215>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_Divide_i_idx_3 = 0.0F;
      rtb_Saturation_j = 0.0F;
    } else {
      rtb_Divide_i_idx_3 = rtb_Divide_i_idx_0;
      rtb_Saturation_j = rtb_Divide_i_idx_2;
    }

    /* End of Switch: '<S215>/Switch' */

    /* Product: '<S212>/Multiply' incorporates:
     *  Constant: '<S212>/kd'
     */
    rtb_Abs = CONTROL_PARAM.MC_VEL_XY_D * rtb_Divide_i_idx_3;

    /* Saturate: '<S212>/Saturation' */
    if (rtb_Abs > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
      rtb_Abs = CONTROL_PARAM.MC_VEL_XY_D_MAX;
    } else {
      if (rtb_Abs < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
        rtb_Abs = CONTROL_PARAM.MC_VEL_XY_D_MIN;
      }
    }

    rtb_Divide_i_idx_3 = rtb_Abs;

    /* Product: '<S212>/Multiply' incorporates:
     *  Constant: '<S212>/kd'
     */
    rtb_Abs = CONTROL_PARAM.MC_VEL_XY_D * rtb_Saturation_j;

    /* Saturate: '<S212>/Saturation' */
    if (rtb_Abs > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
      rtb_Abs = CONTROL_PARAM.MC_VEL_XY_D_MAX;
    } else {
      if (rtb_Abs < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
        rtb_Abs = CONTROL_PARAM.MC_VEL_XY_D_MIN;
      }
    }

    /* Switch: '<S206>/Switch' incorporates:
     *  Constant: '<S214>/kp'
     *  Constant: '<S216>/Constant'
     *  Constant: '<S218>/Constant'
     *  Constant: '<S219>/Constant'
     *  DiscreteIntegrator: '<S213>/Discrete-Time Integrator'
     *  Product: '<S214>/Multiply'
     *  Product: '<S217>/Multiply2'
     *  Product: '<S217>/Multiply3'
     *  RelationalOperator: '<S216>/Compare'
     *  RelationalOperator: '<S218>/Compare'
     *  RelationalOperator: '<S219>/Compare'
     *  S-Function (sfix_bitop): '<S217>/cmd_ax valid'
     *  S-Function (sfix_bitop): '<S217>/cmd_ay valid'
     *  S-Function (sfix_bitop): '<S217>/cmd_u valid'
     *  S-Function (sfix_bitop): '<S217>/cmd_v valid'
     *  Sum: '<S205>/Add'
     *  Sum: '<S217>/Sum1'
     */
    if (rtb_BitwiseAND_n == 6) {
      rtb_Divide_i_idx_3 = ((Controller_U.FMS_Out.cmd_mask & 64) > 0 ?
                            (CONTROL_PARAM.MC_VEL_XY_P * rtb_Divide_i_idx_1 +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0]) + rtb_Divide_i_idx_3 :
                            0.0F) + ((Controller_U.FMS_Out.cmd_mask & 512) > 0 ?
        Controller_U.FMS_Out.ax_cmd : 0.0F);
      rtb_Saturation_j = ((Controller_U.FMS_Out.cmd_mask & 128) > 0 ?
                          (CONTROL_PARAM.MC_VEL_XY_P * rtb_Divide_m_idx_3 +
                           Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1]) +
                          rtb_Abs : 0.0F) + ((Controller_U.FMS_Out.cmd_mask &
        1024) > 0 ? Controller_U.FMS_Out.ay_cmd : 0.0F);
    } else {
      rtb_Divide_i_idx_3 += CONTROL_PARAM.MC_VEL_XY_P * rtb_Divide_i_idx_1 +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0];
      rtb_Saturation_j = (CONTROL_PARAM.MC_VEL_XY_P * rtb_Divide_m_idx_3 +
                          Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1]) +
        rtb_Abs;
    }

    /* End of Switch: '<S206>/Switch' */

    /* Trigonometry: '<S203>/Atan' incorporates:
     *  Constant: '<S203>/g'
     *  Gain: '<S203>/Gain1'
     *  Gain: '<S203>/gain'
     *  Product: '<S203>/Divide'
     */
    rtb_Sum_c = atanf(1.1F * rtb_Saturation_j / 9.8055F);
    rtb_Saturation_j = atanf(1.1F * -rtb_Divide_i_idx_3 / 9.8055F);

    /* Switch: '<S194>/Switch' incorporates:
     *  Constant: '<S201>/Constant'
     *  Logic: '<S194>/Logical Operator'
     *  RelationalOperator: '<S200>/Compare'
     *  RelationalOperator: '<S201>/Compare'
     *  Saturate: '<S203>/Saturation'
     *  Switch: '<S194>/Switch1'
     */
    if ((rtb_BitwiseAND_n == 3) || (rtb_BitwiseAND_n == 4)) {
      rtb_Divide_i_idx_3 = Controller_U.FMS_Out.phi_cmd;
      rtb_Saturation_j = Controller_U.FMS_Out.theta_cmd;
    } else if (rtb_BitwiseAND_n == 6) {
      /* Switch: '<S202>/Switch' incorporates:
       *  S-Function (sfix_bitop): '<S202>/cmd_phi valid'
       *  S-Function (sfix_bitop): '<S202>/cmd_theta valid'
       *  Saturate: '<S203>/Saturation'
       *  Switch: '<S194>/Switch1'
       */
      if ((Controller_U.FMS_Out.cmd_mask & 8) > 0) {
        rtb_Divide_i_idx_3 = Controller_U.FMS_Out.phi_cmd;
      } else if (rtb_Sum_c > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S203>/Saturation' */
        rtb_Divide_i_idx_3 = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else if (rtb_Sum_c < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S203>/Saturation' */
        rtb_Divide_i_idx_3 = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        rtb_Divide_i_idx_3 = rtb_Sum_c;
      }

      if ((Controller_U.FMS_Out.cmd_mask & 16) > 0) {
        rtb_Saturation_j = Controller_U.FMS_Out.theta_cmd;
      } else if (rtb_Saturation_j > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S203>/Saturation' */
        rtb_Saturation_j = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_Saturation_j < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Saturate: '<S203>/Saturation' */
          rtb_Saturation_j = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        }
      }

      /* End of Switch: '<S202>/Switch' */
    } else {
      if (rtb_Sum_c > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S203>/Saturation' incorporates:
         *  Switch: '<S194>/Switch1'
         */
        rtb_Divide_i_idx_3 = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else if (rtb_Sum_c < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S203>/Saturation' incorporates:
         *  Switch: '<S194>/Switch1'
         */
        rtb_Divide_i_idx_3 = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        /* Switch: '<S194>/Switch1' incorporates:
         *  Saturate: '<S203>/Saturation'
         */
        rtb_Divide_i_idx_3 = rtb_Sum_c;
      }

      /* Saturate: '<S203>/Saturation' */
      if (rtb_Saturation_j > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Switch: '<S194>/Switch1' */
        rtb_Saturation_j = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_Saturation_j < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Switch: '<S194>/Switch1' */
          rtb_Saturation_j = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        }
      }
    }

    /* End of Switch: '<S194>/Switch' */

    /* Sum: '<S195>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Abs = rtb_Divide_i_idx_3 - Controller_U.INS_Out.phi;

    /* Product: '<S198>/Divide1' incorporates:
     *  Abs: '<S198>/Abs'
     *  Constant: '<S198>/const2'
     */
    rtb_Gain_a_idx_0 = fabsf(rtb_Abs) / 0.002F;

    /* Product: '<S198>/Divide' incorporates:
     *  Constant: '<S196>/Constant1'
     *  Constant: '<S198>/const1'
     *  Math: '<S198>/Square'
     *  SignalConversion: '<S198>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_TmpSignalConversionAtMult_1 = 9.5993F / (CONTROL_PARAM.MC_ROLL_P *
      CONTROL_PARAM.MC_ROLL_P);

    /* Signum: '<S198>/Sign' */
    if (rtb_Abs < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else if (rtb_Abs > 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_0 = rtb_Abs;
    }

    /* Switch: '<S198>/Switch' incorporates:
     *  Constant: '<S196>/Constant1'
     *  Gain: '<S198>/Gain1'
     *  Gain: '<S198>/Gain2'
     *  Logic: '<S198>/Logical Operator'
     *  Product: '<S198>/Divide'
     *  Product: '<S198>/Multiply'
     *  Product: '<S198>/Multiply1'
     *  Product: '<S198>/Multiply2'
     *  Product: '<S198>/Multiply3'
     *  RelationalOperator: '<S198>/Relational Operator'
     *  RelationalOperator: '<S198>/Relational Operator2'
     *  SignalConversion: '<S198>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S198>/Sqrt'
     *  Sum: '<S198>/Subtract'
     */
    if ((rtb_Abs <= rtb_TmpSignalConversionAtMult_1) && (rtb_Abs >=
         -rtb_TmpSignalConversionAtMult_1)) {
      rtb_TmpSignalConversionAtMult_0 = rtb_Abs * CONTROL_PARAM.MC_ROLL_P;
    } else {
      rtb_TmpSignalConversionAtMult_0 *= sqrtf((rtb_TmpSignalConversionAtMult_0 *
        rtb_Abs - 0.5F * rtb_TmpSignalConversionAtMult_1) *
        Controller_ConstB.Gain);
    }

    /* Gain: '<S198>/Gain3' */
    rtb_TmpSignalConversionAtMult_1 = -rtb_Gain_a_idx_0;

    /* Switch: '<S199>/Switch' incorporates:
     *  Gain: '<S198>/Gain3'
     *  RelationalOperator: '<S199>/UpperRelop'
     */
    if (rtb_TmpSignalConversionAtMult_0 >= -rtb_Gain_a_idx_0) {
      rtb_TmpSignalConversionAtMult_1 = rtb_TmpSignalConversionAtMult_0;
    }

    /* Switch: '<S199>/Switch2' incorporates:
     *  RelationalOperator: '<S199>/LowerRelop1'
     */
    if (rtb_TmpSignalConversionAtMult_0 <= rtb_Gain_a_idx_0) {
      rtb_Gain_a_idx_0 = rtb_TmpSignalConversionAtMult_1;
    }

    /* Saturate: '<S179>/Saturation1' */
    if (rtb_Gain_a_idx_0 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_Gain_a_idx_0 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_Gain_a_idx_0 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_Gain_a_idx_0 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    rtb_Divide_i_idx_3 = rtb_Gain_a_idx_0;

    /* Sum: '<S195>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S198>/Divide1'
     */
    rtb_Abs = rtb_Saturation_j - Controller_U.INS_Out.theta;

    /* Product: '<S198>/Divide1' incorporates:
     *  Abs: '<S198>/Abs'
     *  Constant: '<S198>/const2'
     */
    rtb_Gain_a_idx_0 = fabsf(rtb_Abs) / 0.002F;

    /* Product: '<S198>/Divide' incorporates:
     *  Constant: '<S196>/Constant2'
     *  Constant: '<S198>/const1'
     *  Math: '<S198>/Square'
     *  SignalConversion: '<S198>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_TmpSignalConversionAtMult_1 = 9.5993F / (CONTROL_PARAM.MC_PITCH_P *
      CONTROL_PARAM.MC_PITCH_P);

    /* Signum: '<S198>/Sign' */
    if (rtb_Abs < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else if (rtb_Abs > 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_0 = rtb_Abs;
    }

    /* Switch: '<S198>/Switch' incorporates:
     *  Constant: '<S196>/Constant2'
     *  Gain: '<S198>/Gain1'
     *  Gain: '<S198>/Gain2'
     *  Logic: '<S198>/Logical Operator'
     *  Product: '<S198>/Divide'
     *  Product: '<S198>/Multiply'
     *  Product: '<S198>/Multiply1'
     *  Product: '<S198>/Multiply2'
     *  Product: '<S198>/Multiply3'
     *  RelationalOperator: '<S198>/Relational Operator'
     *  RelationalOperator: '<S198>/Relational Operator2'
     *  SignalConversion: '<S198>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S198>/Sqrt'
     *  Sum: '<S198>/Subtract'
     */
    if ((rtb_Abs <= rtb_TmpSignalConversionAtMult_1) && (rtb_Abs >=
         -rtb_TmpSignalConversionAtMult_1)) {
      rtb_TmpSignalConversionAtMult_0 = rtb_Abs * CONTROL_PARAM.MC_PITCH_P;
    } else {
      rtb_TmpSignalConversionAtMult_0 *= sqrtf((rtb_TmpSignalConversionAtMult_0 *
        rtb_Abs - 0.5F * rtb_TmpSignalConversionAtMult_1) *
        Controller_ConstB.Gain);
    }

    /* Gain: '<S198>/Gain3' */
    rtb_TmpSignalConversionAtMult_1 = -rtb_Gain_a_idx_0;

    /* Switch: '<S199>/Switch' incorporates:
     *  Gain: '<S198>/Gain3'
     *  RelationalOperator: '<S199>/UpperRelop'
     */
    if (rtb_TmpSignalConversionAtMult_0 >= -rtb_Gain_a_idx_0) {
      rtb_TmpSignalConversionAtMult_1 = rtb_TmpSignalConversionAtMult_0;
    }

    /* Switch: '<S199>/Switch2' incorporates:
     *  RelationalOperator: '<S199>/LowerRelop1'
     */
    if (rtb_TmpSignalConversionAtMult_0 <= rtb_Gain_a_idx_0) {
      rtb_Gain_a_idx_0 = rtb_TmpSignalConversionAtMult_1;
    }

    /* Saturate: '<S179>/Saturation1' */
    if (rtb_Gain_a_idx_0 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_Gain_a_idx_0 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_Gain_a_idx_0 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_Gain_a_idx_0 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    /* Saturate: '<S179>/Saturation' */
    if (Controller_U.FMS_Out.psi_rate_cmd > CONTROL_PARAM.MC_R_CMD_LIM) {
      rtb_Ldot_err = CONTROL_PARAM.MC_R_CMD_LIM;
    } else if (Controller_U.FMS_Out.psi_rate_cmd < -CONTROL_PARAM.MC_R_CMD_LIM)
    {
      rtb_Ldot_err = -CONTROL_PARAM.MC_R_CMD_LIM;
    } else {
      rtb_Ldot_err = Controller_U.FMS_Out.psi_rate_cmd;
    }

    /* End of Saturate: '<S179>/Saturation' */

    /* Trigonometry: '<S189>/Sin' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Saturation1_ih = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S189>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_VdotPg = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Product: '<S189>/Multiply3' incorporates:
     *  Trigonometry: '<S189>/Cos1'
     *  Trigonometry: '<S189>/Sin'
     */
    rtb_TmpSignalConversionAtMult_1 = rtb_Saturation1_ih * rtb_VdotPg *
      rtb_Ldot_err;

    /* Trigonometry: '<S189>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_TmpSignalConversionAtMult_2 = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Product: '<S189>/Multiply1' incorporates:
     *  Trigonometry: '<S189>/Cos'
     */
    rtb_Saturation_j = rtb_TmpSignalConversionAtMult_2 * rtb_Gain_a_idx_0;

    /* Product: '<S189>/Multiply4' incorporates:
     *  Trigonometry: '<S189>/Sin'
     */
    rtb_Saturation1_ih *= rtb_Gain_a_idx_0;

    /* Switch: '<S180>/Switch' incorporates:
     *  Constant: '<S190>/Constant'
     *  Constant: '<S191>/Constant'
     *  RelationalOperator: '<S190>/Compare'
     *  RelationalOperator: '<S191>/Compare'
     *  Switch: '<S180>/Switch1'
     */
    if (rtb_BitwiseAND_n == 2) {
      rtb_TmpSignalConversionAtMult_0 = Controller_U.FMS_Out.p_cmd;
      rtb_TmpSignalConversionAtMult_1 = Controller_U.FMS_Out.q_cmd;
      rtb_TmpSignalConversionAtMult_2 = Controller_U.FMS_Out.r_cmd;
    } else if (rtb_BitwiseAND_n == 6) {
      /* Switch: '<S192>/Switch' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Product: '<S189>/Multiply'
       *  Product: '<S189>/Multiply1'
       *  Product: '<S189>/Multiply5'
       *  S-Function (sfix_bitop): '<S192>/cmd_p valid'
       *  S-Function (sfix_bitop): '<S192>/cmd_q valid'
       *  S-Function (sfix_bitop): '<S192>/cmd_r valid'
       *  Sum: '<S189>/Add'
       *  Sum: '<S189>/Add1'
       *  Sum: '<S189>/Add2'
       *  Switch: '<S180>/Switch1'
       *  Trigonometry: '<S189>/Cos'
       *  Trigonometry: '<S189>/Cos1'
       *  Trigonometry: '<S189>/Sin1'
       */
      if ((Controller_U.FMS_Out.cmd_mask & 1) > 0) {
        rtb_TmpSignalConversionAtMult_0 = Controller_U.FMS_Out.p_cmd;
      } else {
        rtb_TmpSignalConversionAtMult_0 = rtb_Divide_i_idx_3 - arm_sin_f32
          (Controller_U.INS_Out.theta) * rtb_Ldot_err;
      }

      if ((Controller_U.FMS_Out.cmd_mask & 2) > 0) {
        rtb_TmpSignalConversionAtMult_1 = Controller_U.FMS_Out.q_cmd;
      } else {
        rtb_TmpSignalConversionAtMult_1 += rtb_Saturation_j;
      }

      if ((Controller_U.FMS_Out.cmd_mask & 4) > 0) {
        rtb_TmpSignalConversionAtMult_2 = Controller_U.FMS_Out.r_cmd;
      } else {
        rtb_TmpSignalConversionAtMult_2 = rtb_TmpSignalConversionAtMult_2 *
          rtb_VdotPg * rtb_Ldot_err - rtb_Saturation1_ih;
      }

      /* End of Switch: '<S192>/Switch' */
    } else {
      /* Switch: '<S180>/Switch1' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Product: '<S189>/Multiply'
       *  Product: '<S189>/Multiply3'
       *  Product: '<S189>/Multiply5'
       *  Sum: '<S189>/Add'
       *  Sum: '<S189>/Add1'
       *  Sum: '<S189>/Add2'
       *  Trigonometry: '<S189>/Cos'
       *  Trigonometry: '<S189>/Cos1'
       *  Trigonometry: '<S189>/Sin1'
       */
      rtb_TmpSignalConversionAtMult_0 = rtb_Divide_i_idx_3 - arm_sin_f32
        (Controller_U.INS_Out.theta) * rtb_Ldot_err;
      rtb_TmpSignalConversionAtMult_1 += rtb_Saturation_j;
      rtb_TmpSignalConversionAtMult_2 = rtb_TmpSignalConversionAtMult_2 *
        rtb_VdotPg * rtb_Ldot_err - rtb_Saturation1_ih;
    }

    /* End of Switch: '<S180>/Switch' */

    /* Sum: '<S181>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_rate_err_B[0] = rtb_TmpSignalConversionAtMult_0 - Controller_U.INS_Out.p;
    rtb_rate_err_B[1] = rtb_TmpSignalConversionAtMult_1 - Controller_U.INS_Out.q;
    rtb_rate_err_B[2] = rtb_TmpSignalConversionAtMult_2 - Controller_U.INS_Out.r;

    /* DiscreteIntegrator: '<S184>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] = rtb_rate_err_B[0];
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] = rtb_rate_err_B[1];
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] = rtb_rate_err_B[2];
    }

    /* DiscreteIntegrator: '<S188>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S184>/Discrete-Time Integrator5'
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

    /* Gain: '<S188>/Gain' incorporates:
     *  DiscreteIntegrator: '<S184>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S188>/Discrete-Time Integrator1'
     *  Sum: '<S188>/Sum5'
     */
    rtb_TmpSignalConversionAtMult_0 =
      (Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] -
       Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[0]) * 188.49556F;
    rtb_TmpSignalConversionAtMult_1 =
      (Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] -
       Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[1]) * 188.49556F;
    rtb_TmpSignalConversionAtMult_2 =
      (Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] -
       Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[2]) * 188.49556F;

    /* Switch: '<S188>/Switch' incorporates:
     *  Gain: '<S188>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_Gain_a_idx_0 = 0.0F;
      rtb_Gain_a_idx_1 = 0.0F;
      rtb_Gain_a_idx_2 = 0.0F;
    } else {
      rtb_Gain_a_idx_0 = rtb_TmpSignalConversionAtMult_0;
      rtb_Gain_a_idx_1 = rtb_TmpSignalConversionAtMult_1;
      rtb_Gain_a_idx_2 = rtb_TmpSignalConversionAtMult_2;
    }

    /* End of Switch: '<S188>/Switch' */

    /* Product: '<S185>/Multiply' incorporates:
     *  Constant: '<S185>/gain1'
     */
    rtb_Divide_i_idx_3 = CONTROL_PARAM.MC_ROLL_RATE_D * rtb_Gain_a_idx_0;

    /* Saturate: '<S185>/Saturation' */
    if (rtb_Divide_i_idx_3 > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Divide_i_idx_3 = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Divide_i_idx_3 < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Divide_i_idx_3 = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    rtb_Gain_a_idx_0 = rtb_Divide_i_idx_3;

    /* Product: '<S185>/Multiply' incorporates:
     *  Constant: '<S185>/gain2'
     */
    rtb_Divide_i_idx_3 = CONTROL_PARAM.MC_PITCH_RATE_D * rtb_Gain_a_idx_1;

    /* Saturate: '<S185>/Saturation' */
    if (rtb_Divide_i_idx_3 > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Divide_i_idx_3 = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Divide_i_idx_3 < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Divide_i_idx_3 = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    rtb_Gain_a_idx_1 = rtb_Divide_i_idx_3;

    /* Product: '<S185>/Multiply' incorporates:
     *  Constant: '<S185>/gain3'
     */
    rtb_Divide_i_idx_3 = CONTROL_PARAM.MC_YAW_RATE_D * rtb_Gain_a_idx_2;

    /* Saturate: '<S185>/Saturation' */
    if (rtb_Divide_i_idx_3 > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Divide_i_idx_3 = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Divide_i_idx_3 < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Divide_i_idx_3 = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    /* SignalConversion: '<S6>/BusConversion_InsertedFor_VTOL_actuator_cmd_at_inport_0' incorporates:
     *  Constant: '<S187>/gain1'
     *  Constant: '<S187>/gain2'
     *  Constant: '<S187>/gain3'
     *  DiscreteIntegrator: '<S184>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S186>/Discrete-Time Integrator'
     *  Product: '<S187>/Multiply'
     *  Sum: '<S182>/Add'
     */
    Controller_B.mc_torque_cmd[0] = (CONTROL_PARAM.MC_ROLL_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0]) + rtb_Gain_a_idx_0;
    Controller_B.mc_torque_cmd[1] = (CONTROL_PARAM.MC_PITCH_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1]) + rtb_Gain_a_idx_1;
    Controller_B.mc_torque_cmd[2] = (CONTROL_PARAM.MC_YAW_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[2]) + rtb_Divide_i_idx_3;

    /* Product: '<S211>/Multiply1' incorporates:
     *  Constant: '<S211>/const1'
     *  DiscreteIntegrator: '<S208>/Integrator'
     */
    rtb_VdotPg = Controller_DW.Integrator_DSTATE[0] * 0.05F;
    rtb_Saturation1_ih = Controller_DW.Integrator_DSTATE[1] * 0.05F;

    /* Sum: '<S211>/Add' incorporates:
     *  DiscreteIntegrator: '<S208>/Integrator1'
     *  Sum: '<S208>/Subtract'
     */
    rtb_Divide_i_idx_3 = (Controller_DW.Integrator1_DSTATE[0] -
                          Controller_U.FMS_Out.u_cmd) + rtb_VdotPg;
    rtb_Saturation_j = (Controller_DW.Integrator1_DSTATE[1] -
                        Controller_U.FMS_Out.v_cmd) + rtb_Saturation1_ih;

    /* Signum: '<S211>/Sign' */
    if (rtb_Divide_i_idx_3 < 0.0F) {
      rtb_Abs = -1.0F;
    } else if (rtb_Divide_i_idx_3 > 0.0F) {
      rtb_Abs = 1.0F;
    } else {
      rtb_Abs = rtb_Divide_i_idx_3;
    }

    /* Sum: '<S211>/Add2' incorporates:
     *  Abs: '<S211>/Abs'
     *  Gain: '<S211>/Gain'
     *  Gain: '<S211>/Gain1'
     *  Product: '<S211>/Multiply2'
     *  Product: '<S211>/Multiply3'
     *  Signum: '<S211>/Sign'
     *  Sqrt: '<S211>/Sqrt'
     *  Sum: '<S211>/Add1'
     *  Sum: '<S211>/Subtract'
     */
    rtb_Gain_a_idx_0 = (sqrtf((8.0F * fabsf(rtb_Divide_i_idx_3) +
      Controller_ConstB.d) * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
      rtb_Abs + rtb_VdotPg;

    /* Sum: '<S211>/Add3' incorporates:
     *  Signum: '<S211>/Sign'
     */
    rtb_Sum_c = rtb_Divide_i_idx_3 + Controller_ConstB.d;

    /* Sum: '<S211>/Subtract1' incorporates:
     *  Signum: '<S211>/Sign'
     */
    rtb_Abs = rtb_Divide_i_idx_3 - Controller_ConstB.d;

    /* Signum: '<S211>/Sign1' */
    if (rtb_Sum_c < 0.0F) {
      rtb_Sum_c = -1.0F;
    } else {
      if (rtb_Sum_c > 0.0F) {
        rtb_Sum_c = 1.0F;
      }
    }

    /* Signum: '<S211>/Sign2' */
    if (rtb_Abs < 0.0F) {
      rtb_Abs = -1.0F;
    } else {
      if (rtb_Abs > 0.0F) {
        rtb_Abs = 1.0F;
      }
    }

    /* Sum: '<S211>/Add2' incorporates:
     *  Gain: '<S211>/Gain2'
     *  Product: '<S211>/Multiply4'
     *  Signum: '<S211>/Sign'
     *  Sum: '<S211>/Add4'
     *  Sum: '<S211>/Add5'
     *  Sum: '<S211>/Subtract2'
     */
    rtb_Divide_i_idx_3 = ((rtb_Divide_i_idx_3 - rtb_Gain_a_idx_0) + rtb_VdotPg) *
      ((rtb_Sum_c - rtb_Abs) * 0.5F) + rtb_Gain_a_idx_0;

    /* Signum: '<S211>/Sign' */
    if (rtb_Saturation_j < 0.0F) {
      rtb_Abs = -1.0F;
    } else if (rtb_Saturation_j > 0.0F) {
      rtb_Abs = 1.0F;
    } else {
      rtb_Abs = rtb_Saturation_j;
    }

    /* Sum: '<S211>/Add2' incorporates:
     *  Abs: '<S211>/Abs'
     *  Gain: '<S211>/Gain'
     *  Gain: '<S211>/Gain1'
     *  Product: '<S211>/Multiply2'
     *  Product: '<S211>/Multiply3'
     *  Signum: '<S211>/Sign'
     *  Sqrt: '<S211>/Sqrt'
     *  Sum: '<S211>/Add1'
     *  Sum: '<S211>/Subtract'
     */
    rtb_Gain_a_idx_0 = (sqrtf((8.0F * fabsf(rtb_Saturation_j) +
      Controller_ConstB.d) * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
      rtb_Abs + rtb_Saturation1_ih;

    /* Sum: '<S211>/Add3' incorporates:
     *  Signum: '<S211>/Sign'
     */
    rtb_Sum_c = rtb_Saturation_j + Controller_ConstB.d;

    /* Sum: '<S211>/Subtract1' incorporates:
     *  Signum: '<S211>/Sign'
     */
    rtb_Abs = rtb_Saturation_j - Controller_ConstB.d;

    /* Signum: '<S211>/Sign1' */
    if (rtb_Sum_c < 0.0F) {
      rtb_Sum_c = -1.0F;
    } else {
      if (rtb_Sum_c > 0.0F) {
        rtb_Sum_c = 1.0F;
      }
    }

    /* Signum: '<S211>/Sign2' */
    if (rtb_Abs < 0.0F) {
      rtb_Abs = -1.0F;
    } else {
      if (rtb_Abs > 0.0F) {
        rtb_Abs = 1.0F;
      }
    }

    /* Sum: '<S211>/Add5' incorporates:
     *  Gain: '<S211>/Gain2'
     *  Product: '<S211>/Multiply4'
     *  Signum: '<S211>/Sign'
     *  Sum: '<S211>/Add2'
     *  Sum: '<S211>/Add4'
     *  Sum: '<S211>/Subtract2'
     */
    rtb_Gain_a_idx_0 += ((rtb_Saturation_j - rtb_Gain_a_idx_0) +
                         rtb_Saturation1_ih) * ((rtb_Sum_c - rtb_Abs) * 0.5F);

    /* Gain: '<S229>/Gain' incorporates:
     *  DiscreteIntegrator: '<S231>/Integrator1'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S229>/Sum1'
     */
    rtb_Saturation_j = -(Controller_DW.Integrator1_DSTATE_e -
                         Controller_U.INS_Out.vd);
    Controller_B.Constant = CONTROL_PARAM.MC_VEL_Z_I_MIN;

    /* DiscreteIntegrator: '<S234>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S234>/Constant'
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

    /* DiscreteIntegrator: '<S236>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_d != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i = rtb_Saturation_j;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_Prev_ks != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i = rtb_Saturation_j;
    }

    /* Gain: '<S236>/Gain' incorporates:
     *  DiscreteIntegrator: '<S236>/Discrete-Time Integrator1'
     *  Sum: '<S236>/Sum5'
     */
    rtb_Abs = (rtb_Saturation_j - Controller_DW.DiscreteTimeIntegrator1_DSTAT_i)
      * 62.831852F;

    /* Switch: '<S225>/Switch' incorporates:
     *  Constant: '<S227>/Constant'
     *  RelationalOperator: '<S227>/Compare'
     */
    if (rtb_BitwiseAND_n <= 3) {
      /* SignalConversion: '<S6>/BusConversion_InsertedFor_VTOL_actuator_cmd_at_inport_0' incorporates:
       *  Bias: '<S225>/Bias'
       *  Gain: '<S225>/Gain'
       */
      Controller_B.mc_force_cmd[2] = 0.000999987125F * (real32_T)
        Controller_U.FMS_Out.throttle_cmd + -1.0F;
    } else {
      /* Product: '<S228>/Multiply' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S228>/Cos'
       *  Trigonometry: '<S228>/Cos1'
       */
      rtb_VdotPg = arm_cos_f32(Controller_U.INS_Out.phi) * arm_cos_f32
        (Controller_U.INS_Out.theta);

      /* Gain: '<S228>/Gain' */
      rtb_Sum_c = 2.0F * rtb_VdotPg;

      /* Saturate: '<S228>/Saturation1' */
      if (rtb_VdotPg > 1.0F) {
        rtb_VdotPg = 1.0F;
      } else {
        if (rtb_VdotPg < 0.5F) {
          rtb_VdotPg = 0.5F;
        }
      }

      /* End of Saturate: '<S228>/Saturation1' */

      /* Product: '<S228>/Divide' incorporates:
       *  Constant: '<S228>/Constant'
       */
      rtb_Saturation1_ih = 1.0F / rtb_VdotPg;

      /* Switch: '<S236>/Switch' incorporates:
       *  Gain: '<S236>/Gain1'
       */
      if (Controller_U.FMS_Out.reset > 0) {
        rtb_Switch_j = 0.0F;
      } else {
        rtb_Switch_j = rtb_Abs;
      }

      /* End of Switch: '<S236>/Switch' */

      /* Product: '<S233>/Multiply' incorporates:
       *  Constant: '<S233>/kd'
       */
      rtb_VdotPg = CONTROL_PARAM.MC_VEL_Z_D * rtb_Switch_j;

      /* Saturate: '<S233>/Saturation' */
      if (rtb_VdotPg > CONTROL_PARAM.MC_VEL_Z_D_MAX) {
        rtb_VdotPg = CONTROL_PARAM.MC_VEL_Z_D_MAX;
      } else {
        if (rtb_VdotPg < CONTROL_PARAM.MC_VEL_Z_D_MIN) {
          rtb_VdotPg = CONTROL_PARAM.MC_VEL_Z_D_MIN;
        }
      }

      /* End of Saturate: '<S233>/Saturation' */

      /* Saturate: '<S228>/Saturation' */
      if (rtb_Sum_c > 1.0F) {
        rtb_Sum_c = 1.0F;
      } else {
        if (rtb_Sum_c < 0.0F) {
          rtb_Sum_c = 0.0F;
        }
      }

      /* End of Saturate: '<S228>/Saturation' */

      /* Product: '<S228>/Multiply1' incorporates:
       *  Constant: '<S235>/kp'
       *  DiscreteIntegrator: '<S234>/Discrete-Time Integrator'
       *  Product: '<S235>/Multiply'
       *  Sum: '<S230>/Add'
       */
      rtb_Saturation1_ih = ((CONTROL_PARAM.MC_VEL_Z_P * rtb_Saturation_j +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_l) + rtb_VdotPg) *
        rtb_Saturation1_ih * rtb_Sum_c;

      /* Saturate: '<S226>/Saturation' */
      if (rtb_Saturation1_ih > 0.35F) {
        rtb_Saturation1_ih = 0.35F;
      } else {
        if (rtb_Saturation1_ih < -0.35F) {
          rtb_Saturation1_ih = -0.35F;
        }
      }

      /* End of Saturate: '<S226>/Saturation' */

      /* SignalConversion: '<S6>/BusConversion_InsertedFor_VTOL_actuator_cmd_at_inport_0' incorporates:
       *  Constant: '<S226>/hover_throttle'
       *  Sum: '<S226>/Sum'
       */
      Controller_B.mc_force_cmd[2] = rtb_Saturation1_ih +
        CONTROL_PARAM.MC_HOVER_THRO;
    }

    /* End of Switch: '<S225>/Switch' */

    /* SignalConversion: '<S6>/BusConversion_InsertedFor_VTOL_actuator_cmd_at_inport_0' */
    Controller_B.mc_force_cmd[0] = Controller_ConstB.TmpBufferAtConstantOutport1;
    Controller_B.mc_force_cmd[1] = Controller_ConstB.TmpBufferAtConstantOutport1;

    /* Product: '<S232>/Multiply1' incorporates:
     *  Constant: '<S232>/const1'
     *  DiscreteIntegrator: '<S231>/Integrator'
     */
    rtb_Ldot_err = Controller_DW.Integrator_DSTATE_j * 0.05F;

    /* Sum: '<S232>/Add' incorporates:
     *  DiscreteIntegrator: '<S231>/Integrator1'
     *  Sum: '<S231>/Subtract'
     */
    rtb_VdotPg = (Controller_DW.Integrator1_DSTATE_e -
                  Controller_U.FMS_Out.w_cmd) + rtb_Ldot_err;

    /* Signum: '<S232>/Sign' */
    if (rtb_VdotPg < 0.0F) {
      rtb_Saturation1_ih = -1.0F;
    } else if (rtb_VdotPg > 0.0F) {
      rtb_Saturation1_ih = 1.0F;
    } else {
      rtb_Saturation1_ih = rtb_VdotPg;
    }

    /* End of Signum: '<S232>/Sign' */

    /* Sum: '<S232>/Add2' incorporates:
     *  Abs: '<S232>/Abs'
     *  Gain: '<S232>/Gain'
     *  Gain: '<S232>/Gain1'
     *  Product: '<S232>/Multiply2'
     *  Product: '<S232>/Multiply3'
     *  Sqrt: '<S232>/Sqrt'
     *  Sum: '<S232>/Add1'
     *  Sum: '<S232>/Subtract'
     */
    rtb_Saturation1_ih = (sqrtf((8.0F * fabsf(rtb_VdotPg) +
      Controller_ConstB.d_i) * Controller_ConstB.d_i) - Controller_ConstB.d_i) *
      0.5F * rtb_Saturation1_ih + rtb_Ldot_err;

    /* Sum: '<S232>/Add4' */
    rtb_Ldot_err += rtb_VdotPg - rtb_Saturation1_ih;

    /* Sum: '<S232>/Add3' */
    rtb_Sum_c = rtb_VdotPg + Controller_ConstB.d_i;

    /* Sum: '<S232>/Subtract1' */
    rtb_VdotPg -= Controller_ConstB.d_i;

    /* Signum: '<S232>/Sign1' */
    if (rtb_Sum_c < 0.0F) {
      rtb_Sum_c = -1.0F;
    } else {
      if (rtb_Sum_c > 0.0F) {
        rtb_Sum_c = 1.0F;
      }
    }

    /* End of Signum: '<S232>/Sign1' */

    /* Signum: '<S232>/Sign2' */
    if (rtb_VdotPg < 0.0F) {
      rtb_VdotPg = -1.0F;
    } else {
      if (rtb_VdotPg > 0.0F) {
        rtb_VdotPg = 1.0F;
      }
    }

    /* End of Signum: '<S232>/Sign2' */

    /* Sum: '<S232>/Add5' incorporates:
     *  Gain: '<S232>/Gain2'
     *  Product: '<S232>/Multiply4'
     *  Sum: '<S232>/Subtract2'
     */
    rtb_Saturation1_ih += (rtb_Sum_c - rtb_VdotPg) * 0.5F * rtb_Ldot_err;

    /* Update for DiscreteIntegrator: '<S186>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S186>/gain1'
     *  Constant: '<S186>/gain2'
     *  Constant: '<S186>/gain3'
     *  DiscreteIntegrator: '<S184>/Discrete-Time Integrator5'
     *  Product: '<S186>/Multiply'
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

    /* End of Update for DiscreteIntegrator: '<S186>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S213>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_PrevRe_p = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S215>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;

    /* Update for DiscreteIntegrator: '<S208>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S208>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE[0] += 0.002F *
      Controller_DW.Integrator_DSTATE[0];

    /* Update for DiscreteIntegrator: '<S213>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S213>/ki'
     *  Product: '<S213>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0] +=
      CONTROL_PARAM.MC_VEL_XY_I * rtb_Divide_i_idx_1 * 0.002F;
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

    /* Update for DiscreteIntegrator: '<S215>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] += 0.002F *
      rtb_Divide_i_idx_0;

    /* Update for DiscreteIntegrator: '<S208>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S208>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE[1] += 0.002F *
      Controller_DW.Integrator_DSTATE[1];

    /* Update for DiscreteIntegrator: '<S213>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S213>/ki'
     *  Product: '<S213>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1] +=
      CONTROL_PARAM.MC_VEL_XY_I * rtb_Divide_m_idx_3 * 0.002F;
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

    /* Update for DiscreteIntegrator: '<S215>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] += 0.002F *
      rtb_Divide_i_idx_2;
    Controller_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S184>/Discrete-Time Integrator5' */
    Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;

    /* Update for DiscreteIntegrator: '<S188>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 0U;

    /* Update for DiscreteIntegrator: '<S184>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S184>/Gain'
     *  Sum: '<S184>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] += (rtb_rate_err_B[0] -
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S188>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[0] += 0.002F *
      rtb_TmpSignalConversionAtMult_0;

    /* Update for DiscreteIntegrator: '<S184>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S184>/Gain'
     *  Sum: '<S184>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] += (rtb_rate_err_B[1] -
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S188>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[1] += 0.002F *
      rtb_TmpSignalConversionAtMult_1;

    /* Update for DiscreteIntegrator: '<S184>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S184>/Gain'
     *  Sum: '<S184>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] += (rtb_rate_err_B[2] -
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S188>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[2] += 0.002F *
      rtb_TmpSignalConversionAtMult_2;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_k = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Signum: '<S211>/Sign3' incorporates:
     *  Product: '<S211>/Divide'
     *  Sum: '<S211>/Add6'
     */
    rtb_Sum_c = rtb_Divide_i_idx_3 + Controller_ConstB.d;

    /* Signum: '<S211>/Sign4' incorporates:
     *  Product: '<S211>/Divide'
     *  Sum: '<S211>/Subtract3'
     */
    rtb_TmpSignalConversionAtMult_0 = rtb_Divide_i_idx_3 - Controller_ConstB.d;

    /* Signum: '<S211>/Sign5' incorporates:
     *  Product: '<S211>/Divide'
     */
    if (rtb_Divide_i_idx_3 < 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = -1.0F;
    } else if (rtb_Divide_i_idx_3 > 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_1 = rtb_Divide_i_idx_3;
    }

    /* Signum: '<S211>/Sign3' */
    if (rtb_Sum_c < 0.0F) {
      rtb_Sum_c = -1.0F;
    } else {
      if (rtb_Sum_c > 0.0F) {
        rtb_Sum_c = 1.0F;
      }
    }

    /* Signum: '<S211>/Sign4' */
    if (rtb_TmpSignalConversionAtMult_0 < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else {
      if (rtb_TmpSignalConversionAtMult_0 > 0.0F) {
        rtb_TmpSignalConversionAtMult_0 = 1.0F;
      }
    }

    /* Signum: '<S211>/Sign6' incorporates:
     *  Product: '<S211>/Divide'
     */
    if (rtb_Divide_i_idx_3 < 0.0F) {
      rtb_TmpSignalConversionAtMult_2 = -1.0F;
    } else if (rtb_Divide_i_idx_3 > 0.0F) {
      rtb_TmpSignalConversionAtMult_2 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_2 = rtb_Divide_i_idx_3;
    }

    /* Update for DiscreteIntegrator: '<S208>/Integrator' incorporates:
     *  Constant: '<S211>/const'
     *  Gain: '<S211>/Gain3'
     *  Product: '<S211>/Divide'
     *  Product: '<S211>/Multiply5'
     *  Product: '<S211>/Multiply6'
     *  Sum: '<S211>/Subtract4'
     *  Sum: '<S211>/Subtract5'
     *  Sum: '<S211>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE[0] += ((rtb_Divide_i_idx_3 /
      Controller_ConstB.d - rtb_TmpSignalConversionAtMult_1) *
      Controller_ConstB.Gain4 * ((rtb_Sum_c - rtb_TmpSignalConversionAtMult_0) *
      0.5F) - rtb_TmpSignalConversionAtMult_2 * 58.836F) * 0.002F;

    /* Signum: '<S211>/Sign3' incorporates:
     *  Sum: '<S211>/Add6'
     */
    rtb_Sum_c = rtb_Gain_a_idx_0 + Controller_ConstB.d;

    /* Signum: '<S211>/Sign4' incorporates:
     *  Sum: '<S211>/Subtract3'
     */
    rtb_TmpSignalConversionAtMult_0 = rtb_Gain_a_idx_0 - Controller_ConstB.d;

    /* Signum: '<S211>/Sign5' */
    if (rtb_Gain_a_idx_0 < 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = -1.0F;
    } else if (rtb_Gain_a_idx_0 > 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_1 = rtb_Gain_a_idx_0;
    }

    /* Signum: '<S211>/Sign3' */
    if (rtb_Sum_c < 0.0F) {
      rtb_Sum_c = -1.0F;
    } else {
      if (rtb_Sum_c > 0.0F) {
        rtb_Sum_c = 1.0F;
      }
    }

    /* Signum: '<S211>/Sign4' */
    if (rtb_TmpSignalConversionAtMult_0 < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else {
      if (rtb_TmpSignalConversionAtMult_0 > 0.0F) {
        rtb_TmpSignalConversionAtMult_0 = 1.0F;
      }
    }

    /* Signum: '<S211>/Sign6' */
    if (rtb_Gain_a_idx_0 < 0.0F) {
      rtb_TmpSignalConversionAtMult_2 = -1.0F;
    } else if (rtb_Gain_a_idx_0 > 0.0F) {
      rtb_TmpSignalConversionAtMult_2 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_2 = rtb_Gain_a_idx_0;
    }

    /* Update for DiscreteIntegrator: '<S208>/Integrator' incorporates:
     *  Constant: '<S211>/const'
     *  Gain: '<S211>/Gain3'
     *  Product: '<S211>/Divide'
     *  Product: '<S211>/Multiply5'
     *  Product: '<S211>/Multiply6'
     *  Sum: '<S211>/Subtract4'
     *  Sum: '<S211>/Subtract5'
     *  Sum: '<S211>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE[1] += ((rtb_Gain_a_idx_0 /
      Controller_ConstB.d - rtb_TmpSignalConversionAtMult_1) *
      Controller_ConstB.Gain4 * ((rtb_Sum_c - rtb_TmpSignalConversionAtMult_0) *
      0.5F) - rtb_TmpSignalConversionAtMult_2 * 58.836F) * 0.002F;

    /* Update for DiscreteIntegrator: '<S231>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S231>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_e += 0.002F *
      Controller_DW.Integrator_DSTATE_j;

    /* Update for DiscreteIntegrator: '<S234>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S234>/ki'
     *  Product: '<S234>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_l += CONTROL_PARAM.MC_VEL_Z_I *
      rtb_Saturation_j * 0.002F;
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

    /* End of Update for DiscreteIntegrator: '<S234>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S236>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_i += 0.002F * rtb_Abs;
    Controller_DW.DiscreteTimeIntegrator1_Prev_ks = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Signum: '<S232>/Sign6' incorporates:
     *  Signum: '<S232>/Sign5'
     */
    if (rtb_Saturation1_ih < 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = -1.0F;

      /* Signum: '<S232>/Sign5' */
      rtb_TmpSignalConversionAtMult_2 = -1.0F;
    } else if (rtb_Saturation1_ih > 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = 1.0F;

      /* Signum: '<S232>/Sign5' */
      rtb_TmpSignalConversionAtMult_2 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_1 = rtb_Saturation1_ih;

      /* Signum: '<S232>/Sign5' */
      rtb_TmpSignalConversionAtMult_2 = rtb_Saturation1_ih;
    }

    /* End of Signum: '<S232>/Sign6' */

    /* Sum: '<S232>/Add6' */
    rtb_Sum_c = rtb_Saturation1_ih + Controller_ConstB.d_i;

    /* Sum: '<S232>/Subtract3' */
    rtb_TmpSignalConversionAtMult_0 = rtb_Saturation1_ih - Controller_ConstB.d_i;

    /* Signum: '<S232>/Sign3' */
    if (rtb_Sum_c < 0.0F) {
      rtb_Sum_c = -1.0F;
    } else {
      if (rtb_Sum_c > 0.0F) {
        rtb_Sum_c = 1.0F;
      }
    }

    /* End of Signum: '<S232>/Sign3' */

    /* Signum: '<S232>/Sign4' */
    if (rtb_TmpSignalConversionAtMult_0 < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else {
      if (rtb_TmpSignalConversionAtMult_0 > 0.0F) {
        rtb_TmpSignalConversionAtMult_0 = 1.0F;
      }
    }

    /* End of Signum: '<S232>/Sign4' */

    /* Update for DiscreteIntegrator: '<S231>/Integrator' incorporates:
     *  Constant: '<S232>/const'
     *  Gain: '<S232>/Gain3'
     *  Product: '<S232>/Divide'
     *  Product: '<S232>/Multiply5'
     *  Product: '<S232>/Multiply6'
     *  Sum: '<S232>/Subtract4'
     *  Sum: '<S232>/Subtract5'
     *  Sum: '<S232>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE_j += ((rtb_Saturation1_ih /
      Controller_ConstB.d_i - rtb_TmpSignalConversionAtMult_2) *
      Controller_ConstB.Gain4_p * ((rtb_Sum_c - rtb_TmpSignalConversionAtMult_0)
      * 0.5F) - rtb_TmpSignalConversionAtMult_1 * 78.448F) * 0.002F;

    /* End of Outputs for SubSystem: '<S2>/MC_Controller' */
    break;
  }

  /* End of SwitchCase: '<S9>/Switch Case1' */

  /* Outputs for Atomic SubSystem: '<S7>/VTOL_Control_Allocation' */
#if AIRFRAME == 1

  /* Output and update for atomic system: '<S238>/VTOL1' */
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

    /* Saturate: '<S249>/Saturation' incorporates:
     *  Bias: '<S249>/Bias'
     *  Bias: '<S249>/Bias1'
     *  Bias: '<S249>/Bias2'
     *  Bias: '<S249>/Bias3'
     *  Constant: '<S249>/Constant'
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

    /* End of Saturate: '<S249>/Saturation' */

    /* MultiPortSwitch: '<S243>/Multiport Switch' incorporates:
     *  Constant: '<S244>/Constant1'
     *  Constant: '<S244>/Constant12'
     *  Constant: '<S244>/Constant2'
     *  Constant: '<S244>/Constant7'
     *  DataTypeConversion: '<S249>/Data Type Conversion'
     *  DataTypeConversion: '<S250>/Data Type Conversion'
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
        /* Saturate: '<S250>/Saturation' incorporates:
         *  Constant: '<S250>/Disarm'
         *  Reshape: '<S250>/Reshape'
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

      /* Saturate: '<S250>/Saturation' incorporates:
       *  Bias: '<S250>/Bias'
       *  Constant: '<S250>/Constant'
       *  DataTypeConversion: '<S250>/Data Type Conversion'
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

      /* Saturate: '<S250>/Saturation' incorporates:
       *  Bias: '<S250>/Bias1'
       *  Constant: '<S250>/Constant'
       *  DataTypeConversion: '<S250>/Data Type Conversion'
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

      /* Saturate: '<S250>/Saturation' incorporates:
       *  Bias: '<S250>/Bias2'
       *  Constant: '<S250>/Constant'
       *  DataTypeConversion: '<S250>/Data Type Conversion'
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

      /* Saturate: '<S250>/Saturation' incorporates:
       *  Bias: '<S250>/Bias3'
       *  Constant: '<S250>/Constant'
       *  DataTypeConversion: '<S250>/Data Type Conversion'
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

      /* SignalConversion: '<S244>/ConcatBufferAtVector Concatenate2In3' incorporates:
       *  Constant: '<S244>/Constant11'
       *  Constant: '<S244>/Constant12'
       */
      rtb_MatrixConcatenate[10] = 0.0F;

      /* SignalConversion: '<S244>/ConcatBufferAtVector Concatenate2In2' incorporates:
       *  Constant: '<S244>/Constant10'
       */
      rtb_MatrixConcatenate[9] = 0.0F;

      /* SignalConversion: '<S244>/ConcatBufferAtVector Concatenate2In1' incorporates:
       *  Constant: '<S244>/Constant9'
       */
      rtb_MatrixConcatenate[8] = 0.0F;

      /* SignalConversion: '<S244>/ConcatBufferAtVector Concatenate1In4' incorporates:
       *  Constant: '<S244>/Constant8'
       */
      rtb_MatrixConcatenate[7] = 0.0F;
      rtb_MatrixConcatenate[6] = CONTROL_PARAM.FW_PITCH_EFFC *
        CONTROL_PARAM.FW_ELEVATOR_DIR;

      /* SignalConversion: '<S244>/ConcatBufferAtVector Concatenate1In2' incorporates:
       *  Constant: '<S244>/Constant6'
       *  Constant: '<S244>/Constant7'
       */
      rtb_MatrixConcatenate[5] = 0.0F;

      /* SignalConversion: '<S244>/ConcatBufferAtVector Concatenate1In1' incorporates:
       *  Constant: '<S244>/Constant5'
       */
      rtb_MatrixConcatenate[4] = 0.0F;

      /* SignalConversion: '<S244>/ConcatBufferAtVector ConcatenateIn4' incorporates:
       *  Constant: '<S244>/Constant4'
       */
      rtb_MatrixConcatenate[3] = 0.0F;

      /* SignalConversion: '<S244>/ConcatBufferAtVector ConcatenateIn3' incorporates:
       *  Constant: '<S244>/Constant3'
       */
      rtb_MatrixConcatenate[2] = 0.0F;
      rtb_MatrixConcatenate[1] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON2_DIR;
      rtb_MatrixConcatenate[0] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON1_DIR;

      /* Saturate: '<S241>/Saturation5' incorporates:
       *  Constant: '<S244>/Constant1'
       *  Constant: '<S244>/Constant2'
       */
      if (Controller_B.fw_torque_cmd[0] > 1.0F) {
        /* Product: '<S241>/Multiply1' */
        tmp_c = 1.0F;
      } else if (Controller_B.fw_torque_cmd[0] < -1.0F) {
        /* Product: '<S241>/Multiply1' */
        tmp_c = -1.0F;
      } else {
        /* Product: '<S241>/Multiply1' */
        tmp_c = Controller_B.fw_torque_cmd[0];
      }

      if (Controller_B.fw_torque_cmd[1] > 1.0F) {
        /* Product: '<S241>/Multiply1' */
        tmp_d = 1.0F;
      } else if (Controller_B.fw_torque_cmd[1] < -1.0F) {
        /* Product: '<S241>/Multiply1' */
        tmp_d = -1.0F;
      } else {
        /* Product: '<S241>/Multiply1' */
        tmp_d = Controller_B.fw_torque_cmd[1];
      }

      if (Controller_B.fw_torque_cmd[2] > 1.0F) {
        /* Product: '<S241>/Multiply1' */
        tmp_nk = 1.0F;
      } else if (Controller_B.fw_torque_cmd[2] < -1.0F) {
        /* Product: '<S241>/Multiply1' */
        tmp_nk = -1.0F;
      } else {
        /* Product: '<S241>/Multiply1' */
        tmp_nk = Controller_B.fw_torque_cmd[2];
      }

      /* End of Saturate: '<S241>/Saturation5' */
      for (i_p = 0; i_p < 4; i_p++) {
        /* Bias: '<S241>/Bias' incorporates:
         *  Gain: '<S241>/Gain1'
         *  Product: '<S241>/Multiply1'
         */
        rtb_Multiply_fw[i_p] = 500.0F * (rtb_MatrixConcatenate[i_p + 8] * tmp_nk
          + (rtb_MatrixConcatenate[i_p + 4] * tmp_d + rtb_MatrixConcatenate[i_p]
             * tmp_c)) + 1500.0F;
      }

      /* Saturate: '<S242>/Saturation2' */
      if (Controller_B.mc_force_cmd[2] > 1.0F) {
        tmp_a = 1.0F;
      } else if (Controller_B.mc_force_cmd[2] < 0.0F) {
        tmp_a = 0.0F;
      } else {
        tmp_a = Controller_B.mc_force_cmd[2];
      }

      /* End of Saturate: '<S242>/Saturation2' */

      /* DataTypeConversion: '<S248>/Data Type Conversion' incorporates:
       *  Constant: '<S248>/Constant1'
       *  Gain: '<S248>/Gain1'
       *  Sum: '<S248>/Sum1'
       */
      rtb_DataTypeConversion_i = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
        tmp_a), 4.2949673E+9F) + 1000U);

      /* Saturate: '<S242>/Saturation1' */
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

      /* End of Saturate: '<S242>/Saturation1' */

      /* Saturate: '<S241>/Saturation' */
      if (Controller_B.fw_force_cmd[0] > 1.0F) {
        tmp_a = 1.0F;
      } else if (Controller_B.fw_force_cmd[0] < 0.0F) {
        tmp_a = 0.0F;
      } else {
        tmp_a = Controller_B.fw_force_cmd[0];
      }

      /* End of Saturate: '<S241>/Saturation' */

      /* Saturate: '<S241>/Saturation1' incorporates:
       *  Constant: '<S246>/Constant1'
       *  DataTypeConversion: '<S246>/Data Type Conversion'
       *  Gain: '<S246>/Gain1'
       *  Sum: '<S246>/Sum1'
       */
      tmp_p[0] = (uint16_T)((uint32_T)fmodf(floorf(1000.0F * tmp_a),
        4.2949673E+9F) + 1000U);

      /* DataTypeConversion: '<S241>/Data Type Conversion' incorporates:
       *  Bias: '<S241>/Bias1'
       */
      tmp_a = fmodf(floorf(rtb_Multiply_fw[0] + CONTROL_PARAM.SERVO1_BIAS),
                    65536.0F);

      /* Saturate: '<S241>/Saturation1' incorporates:
       *  DataTypeConversion: '<S241>/Data Type Conversion'
       */
      tmp_p[1] = (uint16_T)(tmp_a < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_a : (int32_T)(uint16_T)tmp_a);

      /* DataTypeConversion: '<S241>/Data Type Conversion1' incorporates:
       *  Bias: '<S241>/Bias2'
       */
      tmp_a = fmodf(floorf(rtb_Multiply_fw[1] + CONTROL_PARAM.SERVO2_BIAS),
                    65536.0F);

      /* Saturate: '<S241>/Saturation1' incorporates:
       *  DataTypeConversion: '<S241>/Data Type Conversion1'
       */
      tmp_p[2] = (uint16_T)(tmp_a < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_a : (int32_T)(uint16_T)tmp_a);

      /* DataTypeConversion: '<S241>/Data Type Conversion2' incorporates:
       *  Bias: '<S241>/Bias3'
       */
      tmp_a = fmodf(floorf(rtb_Multiply_fw[2] + CONTROL_PARAM.SERVO3_BIAS),
                    65536.0F);

      /* Saturate: '<S241>/Saturation1' incorporates:
       *  DataTypeConversion: '<S241>/Data Type Conversion2'
       */
      tmp_p[3] = (uint16_T)(tmp_a < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_a : (int32_T)(uint16_T)tmp_a);

      /* DataTypeConversion: '<S241>/Data Type Conversion3' incorporates:
       *  Bias: '<S241>/Bias4'
       */
      tmp_a = fmodf(floorf(rtb_Multiply_fw[3] + CONTROL_PARAM.SERVO4_BIAS),
                    65536.0F);

      /* Saturate: '<S241>/Saturation1' incorporates:
       *  DataTypeConversion: '<S241>/Data Type Conversion3'
       */
      tmp_p[4] = (uint16_T)(tmp_a < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_a : (int32_T)(uint16_T)tmp_a);

      /* Product: '<S242>/Multiply' */
      for (i_p = 0; i_p < 4; i_p++) {
        /* Saturate: '<S242>/Saturation' incorporates:
         *  Constant: '<S242>/Effective_Matrix'
         *  Gain: '<S242>/Gain'
         *  Sum: '<S242>/Add'
         */
        tmp_a = fmodf(floorf(1000.0F * (Controller_ConstP.pooled5[i_p + 8] *
          tmp_nk + (Controller_ConstP.pooled5[i_p + 4] * tmp_d +
                    Controller_ConstP.pooled5[i_p] * tmp_c)) + (real32_T)
                             rtb_DataTypeConversion_i), 65536.0F);
        u0_p = (uint16_T)(tmp_a < 0.0F ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
                          -tmp_a : (int32_T)(uint16_T)tmp_a);
        if (u0_p > 1900) {
          rtb_VariantMergeForOutportactua[i_p] = 1900U;
        } else if (u0_p < 1000) {
          rtb_VariantMergeForOutportactua[i_p] = 1000U;
        } else {
          rtb_VariantMergeForOutportactua[i_p] = u0_p;
        }

        /* End of Saturate: '<S242>/Saturation' */
      }

      /* End of Product: '<S242>/Multiply' */
      for (i_p = 0; i_p < 5; i_p++) {
        /* Saturate: '<S241>/Saturation1' */
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

    /* End of MultiPortSwitch: '<S243>/Multiport Switch' */
  }

#elif AIRFRAME == 2

  /* Output and update for atomic system: '<S238>/VTOL2' */
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

    /* Saturate: '<S258>/Saturation' incorporates:
     *  Bias: '<S258>/Bias'
     *  Bias: '<S258>/Bias1'
     *  Bias: '<S258>/Bias2'
     *  Bias: '<S258>/Bias3'
     *  Constant: '<S258>/Constant'
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

    /* End of Saturate: '<S258>/Saturation' */

    /* MultiPortSwitch: '<S253>/Multiport Switch' incorporates:
     *  Constant: '<S254>/Constant1'
     *  Constant: '<S254>/Constant11'
     *  Constant: '<S254>/Constant12'
     *  Constant: '<S254>/Constant2'
     *  Constant: '<S254>/Constant7'
     *  Constant: '<S254>/Constant8'
     *  DataTypeConversion: '<S258>/Data Type Conversion'
     *  DataTypeConversion: '<S259>/Data Type Conversion'
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
        /* Saturate: '<S259>/Saturation' incorporates:
         *  Constant: '<S259>/Disarm'
         *  Reshape: '<S259>/Reshape'
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

      /* Saturate: '<S259>/Saturation' incorporates:
       *  Bias: '<S259>/Bias'
       *  Constant: '<S259>/Constant'
       *  DataTypeConversion: '<S259>/Data Type Conversion'
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

      /* Saturate: '<S259>/Saturation' incorporates:
       *  Bias: '<S259>/Bias1'
       *  Constant: '<S259>/Constant'
       *  DataTypeConversion: '<S259>/Data Type Conversion'
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

      /* Saturate: '<S259>/Saturation' incorporates:
       *  Bias: '<S259>/Bias2'
       *  Constant: '<S259>/Constant'
       *  DataTypeConversion: '<S259>/Data Type Conversion'
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

      /* Saturate: '<S259>/Saturation' incorporates:
       *  Bias: '<S259>/Bias3'
       *  Constant: '<S259>/Constant'
       *  DataTypeConversion: '<S259>/Data Type Conversion'
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

      /* SignalConversion: '<S254>/ConcatBufferAtVector Concatenate2In2' incorporates:
       *  Constant: '<S254>/Constant10'
       *  Constant: '<S254>/Constant11'
       *  Constant: '<S254>/Constant12'
       */
      rtb_MatrixConcatenate_g[9] = 0.0F;

      /* SignalConversion: '<S254>/ConcatBufferAtVector Concatenate2In1' incorporates:
       *  Constant: '<S254>/Constant9'
       */
      rtb_MatrixConcatenate_g[8] = 0.0F;
      rtb_MatrixConcatenate_g[7] = -CONTROL_PARAM.FW_PITCH_EFFC *
        CONTROL_PARAM.FW_TAIL2_DIR;
      rtb_MatrixConcatenate_g[6] = CONTROL_PARAM.FW_PITCH_EFFC *
        CONTROL_PARAM.FW_TAIL1_DIR;

      /* SignalConversion: '<S254>/ConcatBufferAtVector Concatenate1In2' incorporates:
       *  Constant: '<S254>/Constant6'
       *  Constant: '<S254>/Constant7'
       *  Constant: '<S254>/Constant8'
       */
      rtb_MatrixConcatenate_g[5] = 0.0F;

      /* SignalConversion: '<S254>/ConcatBufferAtVector Concatenate1In1' incorporates:
       *  Constant: '<S254>/Constant5'
       */
      rtb_MatrixConcatenate_g[4] = 0.0F;

      /* SignalConversion: '<S254>/ConcatBufferAtVector ConcatenateIn4' incorporates:
       *  Constant: '<S254>/Constant4'
       */
      rtb_MatrixConcatenate_g[3] = 0.0F;

      /* SignalConversion: '<S254>/ConcatBufferAtVector ConcatenateIn3' incorporates:
       *  Constant: '<S254>/Constant3'
       */
      rtb_MatrixConcatenate_g[2] = 0.0F;
      rtb_MatrixConcatenate_g[1] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON2_DIR;
      rtb_MatrixConcatenate_g[0] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON1_DIR;

      /* Saturate: '<S251>/Saturation5' incorporates:
       *  Constant: '<S254>/Constant1'
       *  Constant: '<S254>/Constant2'
       */
      if (Controller_B.fw_torque_cmd[0] > 1.0F) {
        /* Product: '<S251>/Multiply1' */
        tmp_m = 1.0F;
      } else if (Controller_B.fw_torque_cmd[0] < -1.0F) {
        /* Product: '<S251>/Multiply1' */
        tmp_m = -1.0F;
      } else {
        /* Product: '<S251>/Multiply1' */
        tmp_m = Controller_B.fw_torque_cmd[0];
      }

      if (Controller_B.fw_torque_cmd[1] > 1.0F) {
        /* Product: '<S251>/Multiply1' */
        tmp_ev = 1.0F;
      } else if (Controller_B.fw_torque_cmd[1] < -1.0F) {
        /* Product: '<S251>/Multiply1' */
        tmp_ev = -1.0F;
      } else {
        /* Product: '<S251>/Multiply1' */
        tmp_ev = Controller_B.fw_torque_cmd[1];
      }

      if (Controller_B.fw_torque_cmd[2] > 1.0F) {
        /* Product: '<S251>/Multiply1' */
        tmp_k = 1.0F;
      } else if (Controller_B.fw_torque_cmd[2] < -1.0F) {
        /* Product: '<S251>/Multiply1' */
        tmp_k = -1.0F;
      } else {
        /* Product: '<S251>/Multiply1' */
        tmp_k = Controller_B.fw_torque_cmd[2];
      }

      /* End of Saturate: '<S251>/Saturation5' */
      for (i_o = 0; i_o < 4; i_o++) {
        /* Bias: '<S251>/Bias' incorporates:
         *  Gain: '<S251>/Gain1'
         *  Product: '<S251>/Multiply1'
         */
        rtb_Multiply_ka[i_o] = 500.0F * (rtb_MatrixConcatenate_g[i_o + 8] *
          tmp_k + (rtb_MatrixConcatenate_g[i_o + 4] * tmp_ev +
                   rtb_MatrixConcatenate_g[i_o] * tmp_m)) + 1500.0F;
      }

      /* Saturate: '<S252>/Saturation2' */
      if (Controller_B.mc_force_cmd[2] > 1.0F) {
        tmp_gf = 1.0F;
      } else if (Controller_B.mc_force_cmd[2] < 0.0F) {
        tmp_gf = 0.0F;
      } else {
        tmp_gf = Controller_B.mc_force_cmd[2];
      }

      /* End of Saturate: '<S252>/Saturation2' */

      /* DataTypeConversion: '<S257>/Data Type Conversion' incorporates:
       *  Constant: '<S257>/Constant1'
       *  Gain: '<S257>/Gain1'
       *  Sum: '<S257>/Sum1'
       */
      rtb_DataTypeConversion_o = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
        tmp_gf), 4.2949673E+9F) + 1000U);

      /* Saturate: '<S252>/Saturation1' */
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

      /* End of Saturate: '<S252>/Saturation1' */

      /* Saturate: '<S251>/Saturation4' */
      if (Controller_B.fw_force_cmd[0] > 1.0F) {
        tmp_gf = 1.0F;
      } else if (Controller_B.fw_force_cmd[0] < 0.0F) {
        tmp_gf = 0.0F;
      } else {
        tmp_gf = Controller_B.fw_force_cmd[0];
      }

      /* End of Saturate: '<S251>/Saturation4' */

      /* Saturate: '<S251>/Saturation1' incorporates:
       *  Constant: '<S256>/Constant1'
       *  DataTypeConversion: '<S256>/Data Type Conversion'
       *  Gain: '<S256>/Gain1'
       *  Sum: '<S256>/Sum1'
       */
      tmp_o[0] = (uint16_T)((uint32_T)fmodf(floorf(1000.0F * tmp_gf),
        4.2949673E+9F) + 1000U);

      /* DataTypeConversion: '<S251>/Data Type Conversion' incorporates:
       *  Bias: '<S251>/Bias1'
       */
      tmp_gf = fmodf(floorf(rtb_Multiply_ka[0] + CONTROL_PARAM.SERVO1_BIAS),
                     65536.0F);

      /* Saturate: '<S251>/Saturation1' incorporates:
       *  DataTypeConversion: '<S251>/Data Type Conversion'
       */
      tmp_o[1] = (uint16_T)(tmp_gf < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_gf : (int32_T)(uint16_T)tmp_gf);

      /* DataTypeConversion: '<S251>/Data Type Conversion1' incorporates:
       *  Bias: '<S251>/Bias2'
       */
      tmp_gf = fmodf(floorf(rtb_Multiply_ka[1] + CONTROL_PARAM.SERVO2_BIAS),
                     65536.0F);

      /* Saturate: '<S251>/Saturation1' incorporates:
       *  DataTypeConversion: '<S251>/Data Type Conversion1'
       */
      tmp_o[2] = (uint16_T)(tmp_gf < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_gf : (int32_T)(uint16_T)tmp_gf);

      /* DataTypeConversion: '<S251>/Data Type Conversion2' incorporates:
       *  Bias: '<S251>/Bias3'
       */
      tmp_gf = fmodf(floorf(rtb_Multiply_ka[2] + CONTROL_PARAM.SERVO3_BIAS),
                     65536.0F);

      /* Saturate: '<S251>/Saturation1' incorporates:
       *  DataTypeConversion: '<S251>/Data Type Conversion2'
       */
      tmp_o[3] = (uint16_T)(tmp_gf < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_gf : (int32_T)(uint16_T)tmp_gf);

      /* DataTypeConversion: '<S251>/Data Type Conversion3' incorporates:
       *  Bias: '<S251>/Bias4'
       */
      tmp_gf = fmodf(floorf(rtb_Multiply_ka[3] + CONTROL_PARAM.SERVO4_BIAS),
                     65536.0F);

      /* Saturate: '<S251>/Saturation1' incorporates:
       *  DataTypeConversion: '<S251>/Data Type Conversion3'
       */
      tmp_o[4] = (uint16_T)(tmp_gf < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_gf : (int32_T)(uint16_T)tmp_gf);

      /* Product: '<S252>/Multiply' */
      for (i_o = 0; i_o < 4; i_o++) {
        /* Saturate: '<S252>/Saturation' incorporates:
         *  Constant: '<S252>/Effective_Matrix'
         *  Gain: '<S252>/Gain'
         *  Sum: '<S252>/Add'
         */
        tmp_gf = fmodf(floorf(1000.0F * (Controller_ConstP.pooled5[i_o + 8] *
          tmp_k + (Controller_ConstP.pooled5[i_o + 4] * tmp_ev +
                   Controller_ConstP.pooled5[i_o] * tmp_m)) + (real32_T)
                              rtb_DataTypeConversion_o), 65536.0F);
        u0_o = (uint16_T)(tmp_gf < 0.0F ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
                          -tmp_gf : (int32_T)(uint16_T)tmp_gf);
        if (u0_o > 1900) {
          rtb_VariantMergeForOutportactua[i_o] = 1900U;
        } else if (u0_o < 1000) {
          rtb_VariantMergeForOutportactua[i_o] = 1000U;
        } else {
          rtb_VariantMergeForOutportactua[i_o] = u0_o;
        }

        /* End of Saturate: '<S252>/Saturation' */
      }

      /* End of Product: '<S252>/Multiply' */
      for (i_o = 0; i_o < 5; i_o++) {
        /* Saturate: '<S251>/Saturation1' */
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

    /* End of MultiPortSwitch: '<S253>/Multiport Switch' */
  }

#endif

  /* End of Outputs for SubSystem: '<S7>/VTOL_Control_Allocation' */

  /* Outport: '<Root>/Control_Out' incorporates:
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   *  Reshape: '<S237>/Reshape'
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

  /* Start for SwitchCase: '<S9>/Switch Case1' */
  Controller_DW.SwitchCase1_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S2>/FW_Controller' */
  /* Start for Constant: '<S109>/Constant' */
  Controller_B.Constant_m = CONTROL_PARAM.MC_VEL_Z_I_MIN;

  /* End of Start for SubSystem: '<S2>/FW_Controller' */

  /* Start for IfAction SubSystem: '<S2>/MC_Controller' */
  /* Start for Constant: '<S234>/Constant' */
  Controller_B.Constant = CONTROL_PARAM.MC_VEL_Z_I_MIN;

  /* End of Start for SubSystem: '<S2>/MC_Controller' */

  /* SystemInitialize for IfAction SubSystem: '<S2>/FW_Controller' */
  /* InitializeConditions for DiscreteIntegrator: '<S116>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_e = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S115>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_L_eo = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S114>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_o = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S86>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S86>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S157>/ ' */
  Controller_DW._DSTATE = Controller_ConstB.Zero1;
  if (Controller_DW._DSTATE >= CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
    Controller_DW._DSTATE = CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
  } else {
    if (Controller_DW._DSTATE <= -CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
      Controller_DW._DSTATE = -CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
    }
  }

  Controller_DW._PrevResetState = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S157>/ ' */

  /* InitializeConditions for DiscreteIntegrator: '<S158>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_f = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_b = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S84>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_b = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S88>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_h = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_l = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S106>/Integrator1' */
  Controller_DW.Integrator1_DSTATE_i = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S109>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S109>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S111>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_i = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_h = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S134>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S134>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S113>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_g = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S106>/Integrator' */
  Controller_DW.Integrator_DSTATE_f = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S160>/ ' */
  Controller_DW._DSTATE_d = Controller_ConstB.Zero;
  if (Controller_DW._DSTATE_d >= CONTROL_PARAM.FW_CRUISE_THRO) {
    Controller_DW._DSTATE_d = CONTROL_PARAM.FW_CRUISE_THRO;
  } else {
    if (Controller_DW._DSTATE_d <= -CONTROL_PARAM.FW_CRUISE_THRO) {
      Controller_DW._DSTATE_d = -CONTROL_PARAM.FW_CRUISE_THRO;
    }
  }

  Controller_DW._PrevResetState_e = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S160>/ ' */

  /* InitializeConditions for DiscreteIntegrator: '<S161>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_L_h0 = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_d = 0;

  /* End of SystemInitialize for SubSystem: '<S2>/FW_Controller' */

  /* SystemInitialize for IfAction SubSystem: '<S2>/MC_Controller' */
  /* InitializeConditions for DiscreteIntegrator: '<S186>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S186>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S213>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_PrevRe_p = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S215>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S184>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S188>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_k = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S208>/Integrator1' */
  Controller_DW.Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S213>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S208>/Integrator' */
  Controller_DW.Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S208>/Integrator1' */
  Controller_DW.Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S213>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S208>/Integrator' */
  Controller_DW.Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S231>/Integrator1' */
  Controller_DW.Integrator1_DSTATE_e = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S234>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S234>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S236>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 1U;
  Controller_DW.DiscreteTimeIntegrator1_Prev_ks = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S231>/Integrator' */
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
