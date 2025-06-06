/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.321
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Jun  6 14:34:27 2025
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
                                        *   '<S124>/Saturation'
                                        *   '<S125>/Gain'
                                        *   '<S125>/Gain1'
                                        *   '<S125>/balabnce_ratio2'
                                        *   '<S125>/balance_ratio'
                                        *   '<S125>/pitch_ff'
                                        *   '<S125>/thorttle_ff'
                                        *   '<S125>/ucmd2pitch'
                                        *   '<S125>/ucmd2thor'
                                        *   '<S125>/wcmd2pitch'
                                        *   '<S125>/wcmd2thor'
                                        *   '<S126>/cruise_throttle'
                                        *   '<S226>/hover_throttle'
                                        *   '<S100>/hover_throttle'
                                        *   '<S127>/FF'
                                        *   '<S127>/FF_limit'
                                        *   '<S127>/PI_limit'
                                        *   '<S146>/P_control'
                                        *   '<S147>/P_control'
                                        *   '<S203>/Saturation'
                                        *   '<S241>/Bias1'
                                        *   '<S241>/Bias2'
                                        *   '<S241>/Bias3'
                                        *   '<S241>/Bias4'
                                        *   '<S248>/Bias1'
                                        *   '<S248>/Bias2'
                                        *   '<S248>/Bias3'
                                        *   '<S248>/Bias4'
                                        *   '<S79>/Saturation'
                                        *   '<S79>/Saturation1'
                                        *   '<S131>/trim_speed'
                                        *   '<S132>/trim_speed'
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
                                        *   '<S251>/Constant1'
                                        *   '<S251>/Constant11'
                                        *   '<S251>/Constant12'
                                        *   '<S251>/Constant2'
                                        *   '<S251>/Constant7'
                                        *   '<S251>/Constant8'
                                        *   '<S255>/Bias'
                                        *   '<S255>/Bias1'
                                        *   '<S255>/Bias2'
                                        *   '<S255>/Bias3'
                                        *   '<S256>/Bias'
                                        *   '<S256>/Bias1'
                                        *   '<S256>/Bias2'
                                        *   '<S256>/Bias3'
                                        *   '<S91>/Constant1'
                                        *   '<S91>/Constant2'
                                        *   '<S107>/kd'
                                        *   '<S107>/Saturation'
                                        *   '<S108>/Constant'
                                        *   '<S108>/ki'
                                        *   '<S108>/Discrete-Time Integrator'
                                        *   '<S109>/kp'
                                        *   '<S133>/gain1'
                                        *   '<S133>/gain2'
                                        *   '<S133>/gain3'
                                        *   '<S133>/Discrete-Time Integrator'
                                        *   '<S134>/gain1'
                                        *   '<S134>/gain2'
                                        *   '<S134>/gain3'
                                        *   '<S138>/Pitch Offset'
                                        *   '<S138>/Saturation'
                                        *   '<S139>/Constant1'
                                        *   '<S139>/Constant2'
                                        *   '<S196>/Constant1'
                                        *   '<S196>/Constant2'
                                        *   '<S84>/gain1'
                                        *   '<S84>/gain2'
                                        *   '<S84>/gain3'
                                        *   '<S84>/Saturation'
                                        *   '<S85>/gain1'
                                        *   '<S85>/gain2'
                                        *   '<S85>/gain3'
                                        *   '<S85>/Discrete-Time Integrator'
                                        *   '<S86>/gain1'
                                        *   '<S86>/gain2'
                                        *   '<S86>/gain3'
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
  real32_T rtb_MatrixConcatenate1[9];
  real32_T rtb_DiscreteTimeIntegrator1_k1[3];
  real32_T rtb_DiscreteTimeIntegrator_ex[3];
  real32_T rtb_Multiply_b[3];
  real32_T rtb_rate_err_B[3];
  real32_T rtb_Saturation1;
  real32_T rtb_Divide_gn;
  real32_T rtb_Saturation_j;
  int32_T rtb_Relay;
  boolean_T rtb_LogicalOperator_i;
  real32_T rtb_DiscreteTimeIntegrator1_c;
  real32_T rtb_Abs;
  real32_T rtb_VdotPg;
  real32_T rtb_VdotPg_err;
  real32_T rtb_Minus;
  real32_T rtb_B_err;
  real32_T rtb_Gain_c4;
  real32_T rtb_DiscreteTimeIntegrator1_d;
  boolean_T rtb_LogicalOperator_g;
  real32_T rtb_Add_c;
  real32_T rtb_Cos1;
  real32_T rtb_Cos;
  real32_T rtb_DiscreteTimeIntegrator_l_id;
  real32_T rtb_DiscreteTimeIntegrator_l__0;
  real32_T rtb_DiscreteTimeIntegrator_l__1;
  real32_T rtb_Multiply_k_idx_1;
  real32_T rtb_Switch_c_idx_0;
  real32_T rtb_Switch_c_idx_1;
  real32_T rtb_Saturation1_h_idx_0;
  real32_T rtb_MatrixConcatenate1_tmp;
  real32_T rtb_DiscreteTimeIntegrator_l__2;
  real32_T rtb_DiscreteTimeIntegrator1_e_t;
  real32_T rtb_DiscreteTimeIntegrator1_a_t;
  real32_T rtb_DiscreteTimeIntegrator_p_tm;

  /* S-Function (sfix_bitop): '<S8>/Bitwise AND' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  rtb_BitwiseAND_n = (uint8_T)(Controller_U.FMS_Out.ctrl_mode & 63);

  /* SwitchCase: '<S9>/Switch Case1' incorporates:
   *  Constant: '<S108>/Constant'
   *  Constant: '<S234>/Constant'
   *  DataTypeConversion: '<S9>/Data Type Conversion'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S185>/Multiply'
   *  Product: '<S198>/Divide1'
   *  Product: '<S212>/Multiply'
   *  Product: '<S84>/Multiply'
   *  Product: '<S93>/Divide1'
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
       *  DiscreteIntegrator: '<S105>/Integrator'
       *  DiscreteIntegrator: '<S105>/Integrator1'
       *  DiscreteIntegrator: '<S108>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S110>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S112>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S113>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S114>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S115>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S133>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S157>/ '
       *  DiscreteIntegrator: '<S158>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S160>/ '
       *  DiscreteIntegrator: '<S161>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S83>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S85>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S87>/Discrete-Time Integrator1'
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
    /* Sqrt: '<S122>/Sqrt' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Math: '<S122>/Square'
     *  Sqrt: '<S169>/Sqrt'
     *  Sum: '<S122>/Sum of Elements'
     */
    rtb_DiscreteTimeIntegrator_l_id = sqrtf(((Controller_U.INS_Out.quat[0] *
      Controller_U.INS_Out.quat[0] + Controller_U.INS_Out.quat[1] *
      Controller_U.INS_Out.quat[1]) + Controller_U.INS_Out.quat[2] *
      Controller_U.INS_Out.quat[2]) + Controller_U.INS_Out.quat[3] *
      Controller_U.INS_Out.quat[3]);

    /* Product: '<S118>/Divide' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Sqrt: '<S122>/Sqrt'
     */
    rtb_Saturation1_h_idx_0 = Controller_U.INS_Out.quat[0] /
      rtb_DiscreteTimeIntegrator_l_id;
    rtb_Saturation1 = Controller_U.INS_Out.quat[1] /
      rtb_DiscreteTimeIntegrator_l_id;
    rtb_Divide_gn = Controller_U.INS_Out.quat[2] /
      rtb_DiscreteTimeIntegrator_l_id;
    rtb_Saturation_j = Controller_U.INS_Out.quat[3] /
      rtb_DiscreteTimeIntegrator_l_id;

    /* Product: '<S165>/Divide' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_DiscreteTimeIntegrator1_c = Controller_U.INS_Out.quat[0] /
      rtb_DiscreteTimeIntegrator_l_id;
    rtb_Abs = Controller_U.INS_Out.quat[1] / rtb_DiscreteTimeIntegrator_l_id;
    rtb_VdotPg = Controller_U.INS_Out.quat[2] / rtb_DiscreteTimeIntegrator_l_id;
    rtb_Switch_c_idx_1 = Controller_U.INS_Out.quat[3] /
      rtb_DiscreteTimeIntegrator_l_id;

    /* SignalConversion: '<S116>/TmpSignal ConversionAtMultiplyInport2' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_DiscreteTimeIntegrator_l_id = Controller_U.INS_Out.vn;
    rtb_DiscreteTimeIntegrator_l__0 = Controller_U.INS_Out.ve;
    rtb_DiscreteTimeIntegrator_l__1 = Controller_U.INS_Out.vd;

    /* Trigonometry: '<S152>/Trigonometric Function1' incorporates:
     *  Gain: '<S151>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S152>/Trigonometric Function3'
     *  Trigonometry: '<S154>/Trigonometric Function1'
     *  Trigonometry: '<S154>/Trigonometric Function3'
     */
    rtb_B_err = arm_cos_f32(-Controller_U.INS_Out.psi);
    rtb_MatrixConcatenate1[0] = rtb_B_err;

    /* Trigonometry: '<S152>/Trigonometric Function' incorporates:
     *  Gain: '<S151>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S152>/Trigonometric Function2'
     *  Trigonometry: '<S154>/Trigonometric Function'
     */
    rtb_Gain_c4 = arm_sin_f32(-Controller_U.INS_Out.psi);
    rtb_MatrixConcatenate1[1] = rtb_Gain_c4;

    /* SignalConversion: '<S152>/ConcatBufferAtVector Concatenate1In3' incorporates:
     *  Constant: '<S152>/Constant3'
     */
    rtb_MatrixConcatenate1[2] = 0.0F;

    /* Gain: '<S152>/Gain' */
    rtb_MatrixConcatenate1[3] = -rtb_Gain_c4;

    /* Trigonometry: '<S152>/Trigonometric Function3' */
    rtb_MatrixConcatenate1[4] = rtb_B_err;

    /* SignalConversion: '<S152>/ConcatBufferAtVector Concatenate2In3' incorporates:
     *  Constant: '<S152>/Constant4'
     */
    rtb_MatrixConcatenate1[5] = 0.0F;

    /* SignalConversion: '<S152>/ConcatBufferAtVector ConcatenateIn3' */
    rtb_MatrixConcatenate1[6] = Controller_ConstB.VectorConcatenate3_c[0];
    rtb_MatrixConcatenate1[7] = Controller_ConstB.VectorConcatenate3_c[1];
    rtb_MatrixConcatenate1[8] = Controller_ConstB.VectorConcatenate3_c[2];

    /* Product: '<S149>/Multiply' */
    for (rtb_Relay = 0; rtb_Relay < 3; rtb_Relay++) {
      rtb_DiscreteTimeIntegrator1_k1[rtb_Relay] =
        rtb_MatrixConcatenate1[rtb_Relay + 6] * rtb_DiscreteTimeIntegrator_l__1
        + (rtb_MatrixConcatenate1[rtb_Relay + 3] *
           rtb_DiscreteTimeIntegrator_l__0 + rtb_MatrixConcatenate1[rtb_Relay] *
           rtb_DiscreteTimeIntegrator_l_id);
    }

    /* End of Product: '<S149>/Multiply' */

    /* Trigonometry: '<S154>/Trigonometric Function1' */
    rtb_MatrixConcatenate1[0] = rtb_B_err;

    /* Trigonometry: '<S154>/Trigonometric Function' */
    rtb_MatrixConcatenate1[1] = rtb_Gain_c4;

    /* SignalConversion: '<S154>/ConcatBufferAtVector Concatenate1In3' incorporates:
     *  Constant: '<S154>/Constant3'
     */
    rtb_MatrixConcatenate1[2] = 0.0F;

    /* Gain: '<S154>/Gain' incorporates:
     *  Gain: '<S153>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S154>/Trigonometric Function2'
     */
    rtb_MatrixConcatenate1[3] = -arm_sin_f32(-Controller_U.INS_Out.psi);

    /* Trigonometry: '<S154>/Trigonometric Function3' */
    rtb_MatrixConcatenate1[4] = rtb_B_err;

    /* SignalConversion: '<S154>/ConcatBufferAtVector Concatenate2In3' incorporates:
     *  Constant: '<S154>/Constant4'
     */
    rtb_MatrixConcatenate1[5] = 0.0F;

    /* SignalConversion: '<S154>/ConcatBufferAtVector ConcatenateIn3' */
    rtb_MatrixConcatenate1[6] = Controller_ConstB.VectorConcatenate3_o[0];
    rtb_MatrixConcatenate1[7] = Controller_ConstB.VectorConcatenate3_o[1];
    rtb_MatrixConcatenate1[8] = Controller_ConstB.VectorConcatenate3_o[2];

    /* Product: '<S150>/Multiply' */
    for (rtb_Relay = 0; rtb_Relay < 3; rtb_Relay++) {
      rtb_DiscreteTimeIntegrator_ex[rtb_Relay] =
        rtb_MatrixConcatenate1[rtb_Relay + 6] * rtb_DiscreteTimeIntegrator_l__1
        + (rtb_MatrixConcatenate1[rtb_Relay + 3] *
           rtb_DiscreteTimeIntegrator_l__0 + rtb_MatrixConcatenate1[rtb_Relay] *
           rtb_DiscreteTimeIntegrator_l_id);
    }

    /* End of Product: '<S150>/Multiply' */

    /* Math: '<S119>/Square' incorporates:
     *  Math: '<S120>/Square'
     *  Math: '<S121>/Square'
     *  Product: '<S118>/Divide'
     */
    rtb_B_err = rtb_Saturation1_h_idx_0 * rtb_Saturation1_h_idx_0;

    /* Math: '<S119>/Square2' incorporates:
     *  Math: '<S120>/Square2'
     *  Math: '<S121>/Square2'
     *  Product: '<S118>/Divide'
     */
    rtb_Gain_c4 = rtb_Divide_gn * rtb_Divide_gn;

    /* Math: '<S119>/Square1' incorporates:
     *  Math: '<S120>/Square1'
     *  Math: '<S121>/Square1'
     *  Product: '<S118>/Divide'
     */
    rtb_Switch_c_idx_0 = rtb_Saturation1 * rtb_Saturation1;

    /* Math: '<S119>/Square3' incorporates:
     *  Math: '<S120>/Square3'
     *  Math: '<S121>/Square3'
     *  Product: '<S118>/Divide'
     */
    rtb_Minus = rtb_Saturation_j * rtb_Saturation_j;

    /* Sum: '<S119>/Subtract' incorporates:
     *  Math: '<S119>/Square'
     *  Math: '<S119>/Square1'
     *  Math: '<S119>/Square2'
     *  Math: '<S119>/Square3'
     *  Sum: '<S119>/Add'
     *  Sum: '<S119>/Add1'
     */
    rtb_MatrixConcatenate1[0] = (rtb_B_err + rtb_Switch_c_idx_0) - (rtb_Gain_c4
      + rtb_Minus);

    /* Product: '<S119>/Multiply' incorporates:
     *  Product: '<S118>/Divide'
     *  Product: '<S120>/Multiply'
     */
    rtb_VdotPg_err = rtb_Saturation1 * rtb_Divide_gn;

    /* Product: '<S119>/Multiply1' incorporates:
     *  Product: '<S118>/Divide'
     *  Product: '<S120>/Multiply1'
     */
    rtb_Add_c = rtb_Saturation1_h_idx_0 * rtb_Saturation_j;

    /* Gain: '<S119>/Gain' incorporates:
     *  Product: '<S119>/Multiply'
     *  Product: '<S119>/Multiply1'
     *  Sum: '<S119>/Subtract1'
     */
    rtb_MatrixConcatenate1[1] = (rtb_VdotPg_err - rtb_Add_c) * 2.0F;

    /* Product: '<S119>/Multiply2' incorporates:
     *  Product: '<S118>/Divide'
     *  Product: '<S121>/Multiply'
     */
    rtb_MatrixConcatenate1_tmp = rtb_Saturation1 * rtb_Saturation_j;

    /* Product: '<S119>/Multiply3' incorporates:
     *  Product: '<S118>/Divide'
     *  Product: '<S121>/Multiply1'
     */
    rtb_Cos = rtb_Saturation1_h_idx_0 * rtb_Divide_gn;

    /* Gain: '<S119>/Gain1' incorporates:
     *  Product: '<S119>/Multiply2'
     *  Product: '<S119>/Multiply3'
     *  Sum: '<S119>/Add2'
     */
    rtb_MatrixConcatenate1[2] = (rtb_MatrixConcatenate1_tmp + rtb_Cos) * 2.0F;

    /* Gain: '<S120>/Gain' incorporates:
     *  Sum: '<S120>/Add3'
     */
    rtb_MatrixConcatenate1[3] = (rtb_VdotPg_err + rtb_Add_c) * 2.0F;

    /* Sum: '<S120>/Subtract' incorporates:
     *  Sum: '<S120>/Add'
     *  Sum: '<S120>/Add1'
     */
    rtb_MatrixConcatenate1[4] = (rtb_B_err + rtb_Gain_c4) - (rtb_Switch_c_idx_0
      + rtb_Minus);

    /* Product: '<S120>/Multiply2' incorporates:
     *  Product: '<S118>/Divide'
     *  Product: '<S121>/Multiply2'
     */
    rtb_VdotPg_err = rtb_Divide_gn * rtb_Saturation_j;

    /* Product: '<S120>/Multiply3' incorporates:
     *  Product: '<S118>/Divide'
     *  Product: '<S121>/Multiply3'
     */
    rtb_Add_c = rtb_Saturation1_h_idx_0 * rtb_Saturation1;

    /* Gain: '<S120>/Gain1' incorporates:
     *  Product: '<S120>/Multiply2'
     *  Product: '<S120>/Multiply3'
     *  Sum: '<S120>/Subtract1'
     */
    rtb_MatrixConcatenate1[5] = (rtb_VdotPg_err - rtb_Add_c) * 2.0F;

    /* Gain: '<S121>/Gain' incorporates:
     *  Sum: '<S121>/Subtract2'
     */
    rtb_MatrixConcatenate1[6] = (rtb_MatrixConcatenate1_tmp - rtb_Cos) * 2.0F;

    /* Gain: '<S121>/Gain1' incorporates:
     *  Sum: '<S121>/Add2'
     */
    rtb_MatrixConcatenate1[7] = (rtb_VdotPg_err + rtb_Add_c) * 2.0F;

    /* Sum: '<S121>/Subtract' incorporates:
     *  Sum: '<S121>/Add'
     *  Sum: '<S121>/Add1'
     */
    rtb_MatrixConcatenate1[8] = (rtb_B_err + rtb_Minus) - (rtb_Switch_c_idx_0 +
      rtb_Gain_c4);

    /* Product: '<S116>/Multiply' */
    for (rtb_Relay = 0; rtb_Relay < 3; rtb_Relay++) {
      rtb_Multiply_b[rtb_Relay] = rtb_MatrixConcatenate1[rtb_Relay + 6] *
        rtb_DiscreteTimeIntegrator_l__1 + (rtb_MatrixConcatenate1[rtb_Relay + 3]
        * rtb_DiscreteTimeIntegrator_l__0 + rtb_MatrixConcatenate1[rtb_Relay] *
        rtb_DiscreteTimeIntegrator_l_id);
    }

    /* End of Product: '<S116>/Multiply' */

    /* Sum: '<S166>/Subtract' incorporates:
     *  Math: '<S166>/Square'
     *  Math: '<S166>/Square1'
     *  Math: '<S166>/Square2'
     *  Math: '<S166>/Square3'
     *  Product: '<S165>/Divide'
     *  Sum: '<S166>/Add'
     *  Sum: '<S166>/Add1'
     */
    rtb_MatrixConcatenate1[0] = (rtb_DiscreteTimeIntegrator1_c *
      rtb_DiscreteTimeIntegrator1_c + rtb_Abs * rtb_Abs) - (rtb_VdotPg *
      rtb_VdotPg + rtb_Switch_c_idx_1 * rtb_Switch_c_idx_1);

    /* Gain: '<S166>/Gain' incorporates:
     *  Product: '<S165>/Divide'
     *  Product: '<S166>/Multiply'
     *  Product: '<S166>/Multiply1'
     *  Sum: '<S166>/Subtract1'
     */
    rtb_MatrixConcatenate1[1] = (rtb_Abs * rtb_VdotPg -
      rtb_DiscreteTimeIntegrator1_c * rtb_Switch_c_idx_1) * 2.0F;

    /* Gain: '<S166>/Gain1' incorporates:
     *  Product: '<S165>/Divide'
     *  Product: '<S166>/Multiply2'
     *  Product: '<S166>/Multiply3'
     *  Sum: '<S166>/Add2'
     */
    rtb_MatrixConcatenate1[2] = (rtb_Abs * rtb_Switch_c_idx_1 +
      rtb_DiscreteTimeIntegrator1_c * rtb_VdotPg) * 2.0F;

    /* Gain: '<S167>/Gain' incorporates:
     *  Product: '<S165>/Divide'
     *  Product: '<S167>/Multiply'
     *  Product: '<S167>/Multiply1'
     *  Sum: '<S167>/Add3'
     */
    rtb_MatrixConcatenate1[3] = (rtb_Abs * rtb_VdotPg +
      rtb_DiscreteTimeIntegrator1_c * rtb_Switch_c_idx_1) * 2.0F;

    /* Sum: '<S167>/Subtract' incorporates:
     *  Math: '<S167>/Square'
     *  Math: '<S167>/Square1'
     *  Math: '<S167>/Square2'
     *  Math: '<S167>/Square3'
     *  Product: '<S165>/Divide'
     *  Sum: '<S167>/Add'
     *  Sum: '<S167>/Add1'
     */
    rtb_MatrixConcatenate1[4] = (rtb_DiscreteTimeIntegrator1_c *
      rtb_DiscreteTimeIntegrator1_c + rtb_VdotPg * rtb_VdotPg) - (rtb_Abs *
      rtb_Abs + rtb_Switch_c_idx_1 * rtb_Switch_c_idx_1);

    /* Gain: '<S167>/Gain1' incorporates:
     *  Product: '<S165>/Divide'
     *  Product: '<S167>/Multiply2'
     *  Product: '<S167>/Multiply3'
     *  Sum: '<S167>/Subtract1'
     */
    rtb_MatrixConcatenate1[5] = (rtb_VdotPg * rtb_Switch_c_idx_1 -
      rtb_DiscreteTimeIntegrator1_c * rtb_Abs) * 2.0F;

    /* Gain: '<S168>/Gain' incorporates:
     *  Product: '<S165>/Divide'
     *  Product: '<S168>/Multiply'
     *  Product: '<S168>/Multiply1'
     *  Sum: '<S168>/Subtract2'
     */
    rtb_MatrixConcatenate1[6] = (rtb_Abs * rtb_Switch_c_idx_1 -
      rtb_DiscreteTimeIntegrator1_c * rtb_VdotPg) * 2.0F;

    /* Gain: '<S168>/Gain1' incorporates:
     *  Product: '<S165>/Divide'
     *  Product: '<S168>/Multiply2'
     *  Product: '<S168>/Multiply3'
     *  Sum: '<S168>/Add2'
     */
    rtb_MatrixConcatenate1[7] = (rtb_VdotPg * rtb_Switch_c_idx_1 +
      rtb_DiscreteTimeIntegrator1_c * rtb_Abs) * 2.0F;

    /* Sum: '<S168>/Subtract' incorporates:
     *  Math: '<S168>/Square'
     *  Math: '<S168>/Square1'
     *  Math: '<S168>/Square2'
     *  Math: '<S168>/Square3'
     *  Product: '<S165>/Divide'
     *  Sum: '<S168>/Add'
     *  Sum: '<S168>/Add1'
     */
    rtb_MatrixConcatenate1[8] = (rtb_DiscreteTimeIntegrator1_c *
      rtb_DiscreteTimeIntegrator1_c + rtb_Switch_c_idx_1 * rtb_Switch_c_idx_1) -
      (rtb_Abs * rtb_Abs + rtb_VdotPg * rtb_VdotPg);

    /* Product: '<S162>/Multiply' */
    for (rtb_Relay = 0; rtb_Relay < 3; rtb_Relay++) {
      rtb_rate_err_B[rtb_Relay] = rtb_MatrixConcatenate1[rtb_Relay + 6] *
        rtb_DiscreteTimeIntegrator_l__1 + (rtb_MatrixConcatenate1[rtb_Relay + 3]
        * rtb_DiscreteTimeIntegrator_l__0 + rtb_MatrixConcatenate1[rtb_Relay] *
        rtb_DiscreteTimeIntegrator_l_id);
    }

    /* End of Product: '<S162>/Multiply' */

    /* Signum: '<S116>/Sign' */
    if (rtb_Multiply_b[0] < 0.0F) {
      rtb_DiscreteTimeIntegrator_l__0 = -1.0F;
    } else if (rtb_Multiply_b[0] > 0.0F) {
      rtb_DiscreteTimeIntegrator_l__0 = 1.0F;
    } else {
      rtb_DiscreteTimeIntegrator_l__0 = rtb_Multiply_b[0];
    }

    /* End of Signum: '<S116>/Sign' */

    /* Sqrt: '<S111>/Sqrt' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Math: '<S111>/Square2'
     *  Math: '<S111>/Square3'
     *  Sqrt: '<S149>/Sqrt'
     *  Sqrt: '<S150>/Sqrt'
     *  Sum: '<S111>/Add'
     *  Switch: '<S149>/Switch'
     */
    rtb_DiscreteTimeIntegrator_l_id = sqrtf(Controller_U.INS_Out.vn *
      Controller_U.INS_Out.vn + Controller_U.INS_Out.ve *
      Controller_U.INS_Out.ve);

    /* Product: '<S111>/Multiply' incorporates:
     *  Sqrt: '<S111>/Sqrt'
     */
    rtb_Saturation1 = rtb_DiscreteTimeIntegrator_l_id *
      rtb_DiscreteTimeIntegrator_l__0;

    /* Saturate: '<S111>/Saturation1' */
    if (rtb_Saturation1 > 100.0F) {
      rtb_Saturation1 = 100.0F;
    } else {
      if (rtb_Saturation1 < 0.1F) {
        rtb_Saturation1 = 0.1F;
      }
    }

    /* End of Saturate: '<S111>/Saturation1' */

    /* DiscreteIntegrator: '<S115>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_e != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j = rtb_Saturation1;
    }

    /* Math: '<S70>/Square' incorporates:
     *  DiscreteIntegrator: '<S115>/Discrete-Time Integrator5'
     *  Math: '<S131>/Square1'
     */
    rtb_MatrixConcatenate1_tmp = Controller_DW.DiscreteTimeIntegrator5_DSTAT_j *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;

    /* Product: '<S70>/Divide' incorporates:
     *  Math: '<S70>/Square'
     */
    rtb_Divide_gn = rtb_MatrixConcatenate1_tmp / Controller_ConstB.Square1;

    /* DiscreteIntegrator: '<S114>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_L_eo != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_a = rtb_Divide_gn;
    }

    /* Saturate: '<S70>/Saturation' */
    if (Controller_DW.DiscreteTimeIntegrator5_DSTAT_a > 1.0F) {
      rtb_Saturation_j = 1.0F;
    } else if (Controller_DW.DiscreteTimeIntegrator5_DSTAT_a < 0.0F) {
      rtb_Saturation_j = 0.0F;
    } else {
      rtb_Saturation_j = Controller_DW.DiscreteTimeIntegrator5_DSTAT_a;
    }

    /* End of Saturate: '<S70>/Saturation' */

    /* Relay: '<S70>/Relay' */
    if (rtb_Saturation_j >= 0.95F) {
      Controller_DW.Relay_Mode = true;
    } else {
      if (rtb_Saturation_j <= 0.85F) {
        Controller_DW.Relay_Mode = false;
      }
    }

    rtb_Relay = !Controller_DW.Relay_Mode;

    /* End of Relay: '<S70>/Relay' */

    /* DiscreteIntegrator: '<S113>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_o != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTA_a2 = (real32_T)rtb_Relay;
    }

    /* Logic: '<S75>/Logical Operator' incorporates:
     *  Constant: '<S77>/Constant'
     *  DiscreteIntegrator: '<S113>/Discrete-Time Integrator5'
     *  RelationalOperator: '<S77>/Compare'
     */
    rtb_LogicalOperator_i = ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator5_DSTA_a2 == 0.0F));

    /* DiscreteIntegrator: '<S85>/Discrete-Time Integrator' */
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

    /* Trigonometry: '<S124>/Atan' incorporates:
     *  Gain: '<S124>/g_force'
     *  Sum: '<S124>/Minus'
     */
    rtb_DiscreteTimeIntegrator1_c = atanf(0.101936802F *
      Controller_U.FMS_Out.ay_cmd);

    /* Saturate: '<S124>/Saturation' */
    if (rtb_DiscreteTimeIntegrator1_c > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_DiscreteTimeIntegrator1_c = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_DiscreteTimeIntegrator1_c < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM)
      {
        rtb_DiscreteTimeIntegrator1_c = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      }
    }

    /* End of Saturate: '<S124>/Saturation' */

    /* Switch: '<S137>/Switch' incorporates:
     *  Logic: '<S137>/Logical Operator'
     *  RelationalOperator: '<S142>/Compare'
     */
    if ((rtb_BitwiseAND_n == 3) || (rtb_BitwiseAND_n == 4)) {
      rtb_Cos = Controller_U.FMS_Out.phi_cmd;
    } else {
      rtb_Cos = rtb_DiscreteTimeIntegrator1_c;
    }

    /* End of Switch: '<S137>/Switch' */

    /* Switch: '<S145>/Switch' incorporates:
     *  Constant: '<S155>/Constant'
     *  RelationalOperator: '<S155>/Compare'
     */
    if (rtb_BitwiseAND_n == 4) {
      rtb_DiscreteTimeIntegrator1_c = Controller_U.FMS_Out.phi_cmd;
    }

    /* End of Switch: '<S145>/Switch' */

    /* Abs: '<S125>/Abs' */
    rtb_Abs = fabsf(rtb_DiscreteTimeIntegrator1_c);

    /* Switch: '<S149>/Switch' incorporates:
     *  Gain: '<S149>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S149>/Divide'
     *  S-Function (sfix_bitop): '<S149>/Bitwise AND'
     *  Trigonometry: '<S149>/Asin'
     */
    if ((Controller_U.INS_Out.flag & 16U) > 1U) {
      /* Saturate: '<S149>/Saturation' */
      if (rtb_DiscreteTimeIntegrator_l_id > 100.0F) {
        rtb_Add_c = 100.0F;
      } else if (rtb_DiscreteTimeIntegrator_l_id < 8.0F) {
        rtb_Add_c = 8.0F;
      } else {
        rtb_Add_c = rtb_DiscreteTimeIntegrator_l_id;
      }

      /* End of Saturate: '<S149>/Saturation' */

      /* DeadZone: '<S149>/Dead Zone' */
      if (Controller_U.INS_Out.vd > 0.1F) {
        rtb_Cos1 = Controller_U.INS_Out.vd - 0.1F;
      } else if (Controller_U.INS_Out.vd >= -0.1F) {
        rtb_Cos1 = 0.0F;
      } else {
        rtb_Cos1 = Controller_U.INS_Out.vd - -0.1F;
      }

      /* End of DeadZone: '<S149>/Dead Zone' */
      rtb_DiscreteTimeIntegrator1_c = atanf(1.0F / rtb_Add_c * -rtb_Cos1);
    } else {
      rtb_DiscreteTimeIntegrator1_c = Controller_U.INS_Out.theta;
    }

    /* DeadZone: '<S149>/Dead Zone1' */
    if (rtb_DiscreteTimeIntegrator1_k1[0] > 1.0F) {
      rtb_DiscreteTimeIntegrator_l__0 = rtb_DiscreteTimeIntegrator1_k1[0] - 1.0F;
    } else if (rtb_DiscreteTimeIntegrator1_k1[0] >= -1.0F) {
      rtb_DiscreteTimeIntegrator_l__0 = 0.0F;
    } else {
      rtb_DiscreteTimeIntegrator_l__0 = rtb_DiscreteTimeIntegrator1_k1[0] -
        -1.0F;
    }

    /* End of DeadZone: '<S149>/Dead Zone1' */

    /* Signum: '<S149>/Sign' */
    if (rtb_DiscreteTimeIntegrator_l__0 < 0.0F) {
      rtb_DiscreteTimeIntegrator_l__0 = -1.0F;
    } else {
      if (rtb_DiscreteTimeIntegrator_l__0 > 0.0F) {
        rtb_DiscreteTimeIntegrator_l__0 = 1.0F;
      }
    }

    /* End of Signum: '<S149>/Sign' */

    /* Product: '<S149>/Multiply1' */
    rtb_DiscreteTimeIntegrator1_c *= rtb_DiscreteTimeIntegrator_l__0;

    /* Saturate: '<S149>/Saturation1' */
    if (rtb_DiscreteTimeIntegrator1_c > 0.785398185F) {
      rtb_DiscreteTimeIntegrator1_c = 0.785398185F;
    } else {
      if (rtb_DiscreteTimeIntegrator1_c < -0.785398185F) {
        rtb_DiscreteTimeIntegrator1_c = -0.785398185F;
      }
    }

    /* End of Saturate: '<S149>/Saturation1' */

    /* Gain: '<S148>/Gain1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_VdotPg = 0.101936802F * Controller_U.INS_Out.ax;

    /* DeadZone: '<S150>/Dead Zone' */
    if (rtb_DiscreteTimeIntegrator_ex[0] > 1.0F) {
      rtb_DiscreteTimeIntegrator_l__0 = rtb_DiscreteTimeIntegrator_ex[0] - 1.0F;
    } else if (rtb_DiscreteTimeIntegrator_ex[0] >= -1.0F) {
      rtb_DiscreteTimeIntegrator_l__0 = 0.0F;
    } else {
      rtb_DiscreteTimeIntegrator_l__0 = rtb_DiscreteTimeIntegrator_ex[0] - -1.0F;
    }

    /* End of DeadZone: '<S150>/Dead Zone' */

    /* Saturate: '<S150>/Saturation1' */
    if (rtb_DiscreteTimeIntegrator_l_id > 100.0F) {
      rtb_DiscreteTimeIntegrator_l_id = 100.0F;
    } else {
      if (rtb_DiscreteTimeIntegrator_l_id < 8.0F) {
        rtb_DiscreteTimeIntegrator_l_id = 8.0F;
      }
    }

    /* End of Saturate: '<S150>/Saturation1' */

    /* Signum: '<S150>/Sign' */
    if (rtb_DiscreteTimeIntegrator_l__0 < 0.0F) {
      rtb_DiscreteTimeIntegrator_l__0 = -1.0F;
    } else {
      if (rtb_DiscreteTimeIntegrator_l__0 > 0.0F) {
        rtb_DiscreteTimeIntegrator_l__0 = 1.0F;
      }
    }

    /* End of Signum: '<S150>/Sign' */

    /* Product: '<S150>/Multiply1' incorporates:
     *  Gain: '<S150>/Gain'
     *  Product: '<S150>/Divide'
     *  Trigonometry: '<S150>/Asin'
     */
    rtb_Add_c = atanf(-Controller_U.FMS_Out.w_cmd /
                      rtb_DiscreteTimeIntegrator_l_id) *
      rtb_DiscreteTimeIntegrator_l__0;

    /* Saturate: '<S150>/Saturation2' */
    if (rtb_Add_c > 0.785398185F) {
      rtb_Add_c = 0.785398185F;
    } else {
      if (rtb_Add_c < -0.785398185F) {
        rtb_Add_c = -0.785398185F;
      }
    }

    /* End of Saturate: '<S150>/Saturation2' */

    /* Sum: '<S144>/Minus' */
    rtb_Minus = rtb_Add_c - rtb_DiscreteTimeIntegrator1_c;

    /* Switch: '<S162>/Switch' incorporates:
     *  Constant: '<S163>/Constant'
     *  DiscreteIntegrator: '<S115>/Discrete-Time Integrator5'
     *  RelationalOperator: '<S163>/Compare'
     */
    if (rtb_rate_err_B[0] >= 3.0F) {
      rtb_Saturation1_h_idx_0 = Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;
    } else {
      rtb_Saturation1_h_idx_0 = rtb_rate_err_B[0];
    }

    /* End of Switch: '<S162>/Switch' */

    /* Sum: '<S148>/Sum' incorporates:
     *  Gain: '<S148>/Gain'
     *  Sum: '<S148>/Minus'
     */
    rtb_VdotPg_err = (Controller_U.FMS_Out.u_cmd - rtb_Saturation1_h_idx_0) *
      0.101936802F - rtb_VdotPg;

    /* Sum: '<S125>/Minus1' incorporates:
     *  Gain: '<S125>/ucmd2pitch'
     *  Gain: '<S125>/wcmd2pitch'
     */
    rtb_B_err = CONTROL_PARAM.FW_TECS_W2P * rtb_Minus -
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
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_e = rtb_B_err;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_b != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_e = rtb_B_err;
    }

    /* Gain: '<S158>/Gain' incorporates:
     *  DiscreteIntegrator: '<S158>/Discrete-Time Integrator1'
     *  Sum: '<S158>/Sum5'
     */
    rtb_Gain_c4 = (rtb_B_err - Controller_DW.DiscreteTimeIntegrator1_DSTAT_e) *
      62.831852F;

    /* Switch: '<S137>/Switch1' incorporates:
     *  Constant: '<S143>/Constant'
     *  DiscreteIntegrator: '<S157>/ '
     *  Gain: '<S125>/Gain'
     *  Gain: '<S125>/balabnce_ratio2'
     *  Gain: '<S125>/balance_ratio'
     *  Gain: '<S125>/pitch_ff'
     *  Gain: '<S146>/P_control'
     *  RelationalOperator: '<S143>/Compare'
     *  Sum: '<S125>/Add3'
     *  Sum: '<S125>/Minus'
     *  Sum: '<S125>/Sum'
     *  Sum: '<S146>/Add'
     *  Switch: '<S158>/Switch'
     */
    if (rtb_BitwiseAND_n == 3) {
      rtb_Cos1 = Controller_U.FMS_Out.theta_cmd;
    } else {
      if (Controller_U.FMS_Out.reset > 0) {
        /* Switch: '<S158>/Switch' incorporates:
         *  Gain: '<S158>/Gain1'
         */
        rtb_Cos1 = 0.0F;
      } else {
        /* Switch: '<S158>/Switch' */
        rtb_Cos1 = rtb_Gain_c4;
      }

      /* Gain: '<S156>/Gain' */
      rtb_DiscreteTimeIntegrator_l_id = CONTROL_PARAM.FW_TECS_PITCH_D * rtb_Cos1;

      /* Saturate: '<S146>/Saturation1' */
      if (rtb_DiscreteTimeIntegrator_l_id > 0.3F) {
        rtb_DiscreteTimeIntegrator_l_id = 0.3F;
      } else {
        if (rtb_DiscreteTimeIntegrator_l_id < -0.3F) {
          rtb_DiscreteTimeIntegrator_l_id = -0.3F;
        }
      }

      /* End of Saturate: '<S146>/Saturation1' */
      rtb_Cos1 = (((2.0F - CONTROL_PARAM.FW_TECS_RATIO) *
                   rtb_DiscreteTimeIntegrator1_c - CONTROL_PARAM.FW_TECS_RATIO *
                   rtb_VdotPg) * CONTROL_PARAM.FW_TECS_PITCH_F +
                  ((CONTROL_PARAM.FW_TECS_PITCH_P * rtb_B_err +
                    Controller_DW._DSTATE) + rtb_DiscreteTimeIntegrator_l_id)) +
        CONTROL_PARAM.FW_TECS_R2P * rtb_Abs;
    }

    /* End of Switch: '<S137>/Switch1' */

    /* Sum: '<S90>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Switch_c_idx_0 = rtb_Cos - Controller_U.INS_Out.phi;
    rtb_Switch_c_idx_1 = rtb_Cos1 - Controller_U.INS_Out.theta;

    /* Product: '<S93>/Divide1' incorporates:
     *  Abs: '<S93>/Abs'
     *  Constant: '<S93>/const2'
     */
    rtb_DiscreteTimeIntegrator_l__1 = fabsf(rtb_Switch_c_idx_0) / 0.002F;

    /* Product: '<S93>/Divide' incorporates:
     *  Constant: '<S91>/Constant1'
     *  Constant: '<S93>/const1'
     *  Math: '<S93>/Square'
     *  SignalConversion: '<S93>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_DiscreteTimeIntegrator_l_id = 9.5993F / (CONTROL_PARAM.MC_ROLL_P *
      CONTROL_PARAM.MC_ROLL_P);

    /* Signum: '<S93>/Sign' incorporates:
     *  Abs: '<S93>/Abs'
     */
    if (rtb_Switch_c_idx_0 < 0.0F) {
      rtb_Add_c = -1.0F;
    } else if (rtb_Switch_c_idx_0 > 0.0F) {
      rtb_Add_c = 1.0F;
    } else {
      rtb_Add_c = rtb_Switch_c_idx_0;
    }

    /* Switch: '<S93>/Switch' incorporates:
     *  Abs: '<S93>/Abs'
     *  Constant: '<S91>/Constant1'
     *  Gain: '<S93>/Gain1'
     *  Gain: '<S93>/Gain2'
     *  Logic: '<S93>/Logical Operator'
     *  Product: '<S93>/Divide'
     *  Product: '<S93>/Multiply'
     *  Product: '<S93>/Multiply1'
     *  Product: '<S93>/Multiply2'
     *  Product: '<S93>/Multiply3'
     *  RelationalOperator: '<S93>/Relational Operator'
     *  RelationalOperator: '<S93>/Relational Operator2'
     *  SignalConversion: '<S93>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S93>/Sqrt'
     *  Sum: '<S93>/Subtract'
     */
    if ((rtb_Switch_c_idx_0 <= rtb_DiscreteTimeIntegrator_l_id) &&
        (rtb_Switch_c_idx_0 >= -rtb_DiscreteTimeIntegrator_l_id)) {
      rtb_DiscreteTimeIntegrator_l__0 = rtb_Switch_c_idx_0 *
        CONTROL_PARAM.MC_ROLL_P;
    } else {
      rtb_DiscreteTimeIntegrator_l__0 = sqrtf((rtb_Add_c * rtb_Switch_c_idx_0 -
        0.5F * rtb_DiscreteTimeIntegrator_l_id) * Controller_ConstB.Gain_n) *
        rtb_Add_c;
    }

    /* Gain: '<S93>/Gain3' */
    rtb_DiscreteTimeIntegrator_l_id = -rtb_DiscreteTimeIntegrator_l__1;

    /* Switch: '<S94>/Switch' incorporates:
     *  Gain: '<S93>/Gain3'
     *  RelationalOperator: '<S94>/UpperRelop'
     */
    if (rtb_DiscreteTimeIntegrator_l__0 >= -rtb_DiscreteTimeIntegrator_l__1) {
      rtb_DiscreteTimeIntegrator_l_id = rtb_DiscreteTimeIntegrator_l__0;
    }

    /* Switch: '<S94>/Switch2' incorporates:
     *  RelationalOperator: '<S94>/LowerRelop1'
     */
    if (rtb_DiscreteTimeIntegrator_l__0 <= rtb_DiscreteTimeIntegrator_l__1) {
      rtb_DiscreteTimeIntegrator_l__1 = rtb_DiscreteTimeIntegrator_l_id;
    }

    /* Saturate: '<S79>/Saturation1' */
    if (rtb_DiscreteTimeIntegrator_l__1 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_DiscreteTimeIntegrator_l__1 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_DiscreteTimeIntegrator_l__1 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_DiscreteTimeIntegrator_l__1 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    rtb_Saturation1_h_idx_0 = rtb_DiscreteTimeIntegrator_l__1;

    /* Product: '<S93>/Divide1' incorporates:
     *  Abs: '<S93>/Abs'
     *  Constant: '<S93>/const2'
     */
    rtb_DiscreteTimeIntegrator_l__1 = fabsf(rtb_Switch_c_idx_1) / 0.002F;

    /* Product: '<S93>/Divide' incorporates:
     *  Constant: '<S91>/Constant2'
     *  Constant: '<S93>/const1'
     *  Math: '<S93>/Square'
     *  SignalConversion: '<S93>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_DiscreteTimeIntegrator_l_id = 9.5993F / (CONTROL_PARAM.MC_PITCH_P *
      CONTROL_PARAM.MC_PITCH_P);

    /* Signum: '<S93>/Sign' incorporates:
     *  Abs: '<S93>/Abs'
     */
    if (rtb_Switch_c_idx_1 < 0.0F) {
      rtb_Add_c = -1.0F;
    } else if (rtb_Switch_c_idx_1 > 0.0F) {
      rtb_Add_c = 1.0F;
    } else {
      rtb_Add_c = rtb_Switch_c_idx_1;
    }

    /* Switch: '<S93>/Switch' incorporates:
     *  Abs: '<S93>/Abs'
     *  Constant: '<S91>/Constant2'
     *  Gain: '<S93>/Gain1'
     *  Gain: '<S93>/Gain2'
     *  Logic: '<S93>/Logical Operator'
     *  Product: '<S93>/Divide'
     *  Product: '<S93>/Multiply'
     *  Product: '<S93>/Multiply1'
     *  Product: '<S93>/Multiply2'
     *  Product: '<S93>/Multiply3'
     *  RelationalOperator: '<S93>/Relational Operator'
     *  RelationalOperator: '<S93>/Relational Operator2'
     *  SignalConversion: '<S93>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S93>/Sqrt'
     *  Sum: '<S93>/Subtract'
     */
    if ((rtb_Switch_c_idx_1 <= rtb_DiscreteTimeIntegrator_l_id) &&
        (rtb_Switch_c_idx_1 >= -rtb_DiscreteTimeIntegrator_l_id)) {
      rtb_DiscreteTimeIntegrator_l__0 = rtb_Switch_c_idx_1 *
        CONTROL_PARAM.MC_PITCH_P;
    } else {
      rtb_DiscreteTimeIntegrator_l__0 = sqrtf((rtb_Add_c * rtb_Switch_c_idx_1 -
        0.5F * rtb_DiscreteTimeIntegrator_l_id) * Controller_ConstB.Gain_n) *
        rtb_Add_c;
    }

    /* Gain: '<S93>/Gain3' */
    rtb_DiscreteTimeIntegrator_l_id = -rtb_DiscreteTimeIntegrator_l__1;

    /* Switch: '<S94>/Switch' incorporates:
     *  Gain: '<S93>/Gain3'
     *  RelationalOperator: '<S94>/UpperRelop'
     */
    if (rtb_DiscreteTimeIntegrator_l__0 >= -rtb_DiscreteTimeIntegrator_l__1) {
      rtb_DiscreteTimeIntegrator_l_id = rtb_DiscreteTimeIntegrator_l__0;
    }

    /* Switch: '<S94>/Switch2' incorporates:
     *  RelationalOperator: '<S94>/LowerRelop1'
     */
    if (rtb_DiscreteTimeIntegrator_l__0 <= rtb_DiscreteTimeIntegrator_l__1) {
      rtb_DiscreteTimeIntegrator_l__1 = rtb_DiscreteTimeIntegrator_l_id;
    }

    /* Saturate: '<S79>/Saturation1' */
    if (rtb_DiscreteTimeIntegrator_l__1 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_DiscreteTimeIntegrator_l__1 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_DiscreteTimeIntegrator_l__1 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_DiscreteTimeIntegrator_l__1 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    /* Saturate: '<S79>/Saturation' */
    if (Controller_U.FMS_Out.psi_rate_cmd > CONTROL_PARAM.MC_R_CMD_LIM) {
      rtb_Switch_c_idx_0 = CONTROL_PARAM.MC_R_CMD_LIM;
    } else if (Controller_U.FMS_Out.psi_rate_cmd < -CONTROL_PARAM.MC_R_CMD_LIM)
    {
      rtb_Switch_c_idx_0 = -CONTROL_PARAM.MC_R_CMD_LIM;
    } else {
      rtb_Switch_c_idx_0 = Controller_U.FMS_Out.psi_rate_cmd;
    }

    /* End of Saturate: '<S79>/Saturation' */

    /* Trigonometry: '<S88>/Sin' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S129>/Sin'
     */
    rtb_DiscreteTimeIntegrator1_e_t = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S88>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S129>/Cos1'
     */
    rtb_DiscreteTimeIntegrator1_a_t = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Trigonometry: '<S88>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S129>/Cos'
     */
    rtb_DiscreteTimeIntegrator_p_tm = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S88>/Sin1' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S129>/Sin1'
     */
    rtb_DiscreteTimeIntegrator_l__2 = arm_sin_f32(Controller_U.INS_Out.theta);

    /* Sum: '<S80>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S88>/Multiply'
     *  Product: '<S88>/Multiply1'
     *  Product: '<S88>/Multiply3'
     *  Product: '<S88>/Multiply4'
     *  Product: '<S88>/Multiply5'
     *  Sum: '<S88>/Add'
     *  Sum: '<S88>/Add1'
     *  Sum: '<S88>/Add2'
     *  Trigonometry: '<S88>/Cos'
     *  Trigonometry: '<S88>/Cos1'
     *  Trigonometry: '<S88>/Sin'
     *  Trigonometry: '<S88>/Sin1'
     */
    rtb_DiscreteTimeIntegrator_l_id = (rtb_Saturation1_h_idx_0 -
      rtb_DiscreteTimeIntegrator_l__2 * rtb_Switch_c_idx_0) -
      Controller_U.INS_Out.p;
    rtb_DiscreteTimeIntegrator_l__0 = (rtb_DiscreteTimeIntegrator1_e_t *
      rtb_DiscreteTimeIntegrator1_a_t * rtb_Switch_c_idx_0 +
      rtb_DiscreteTimeIntegrator_p_tm * rtb_DiscreteTimeIntegrator_l__1) -
      Controller_U.INS_Out.q;
    rtb_DiscreteTimeIntegrator_l__1 = (rtb_DiscreteTimeIntegrator_p_tm *
      rtb_DiscreteTimeIntegrator1_a_t * rtb_Switch_c_idx_0 -
      rtb_DiscreteTimeIntegrator1_e_t * rtb_DiscreteTimeIntegrator_l__1) -
      Controller_U.INS_Out.r;

    /* DiscreteIntegrator: '<S83>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_b != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0] =
        rtb_DiscreteTimeIntegrator_l_id;
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1] =
        rtb_DiscreteTimeIntegrator_l__0;
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2] =
        rtb_DiscreteTimeIntegrator_l__1;
    }

    /* DiscreteIntegrator: '<S87>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S83>/Discrete-Time Integrator5'
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

    /* Gain: '<S87>/Gain' incorporates:
     *  DiscreteIntegrator: '<S83>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S87>/Discrete-Time Integrator1'
     *  Sum: '<S87>/Sum5'
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

    /* Switch: '<S87>/Switch' incorporates:
     *  Gain: '<S87>/Gain1'
     */
    if (rtb_LogicalOperator_i) {
      rtb_rate_err_B[0] = 0.0F;
      rtb_rate_err_B[1] = 0.0F;
      rtb_rate_err_B[2] = 0.0F;
    } else {
      rtb_rate_err_B[0] = rtb_DiscreteTimeIntegrator1_k1[0];
      rtb_rate_err_B[1] = rtb_DiscreteTimeIntegrator1_k1[1];
      rtb_rate_err_B[2] = rtb_DiscreteTimeIntegrator1_k1[2];
    }

    /* End of Switch: '<S87>/Switch' */

    /* Product: '<S84>/Multiply' incorporates:
     *  Constant: '<S84>/gain1'
     */
    rtb_Saturation1_h_idx_0 = CONTROL_PARAM.MC_ROLL_RATE_D * rtb_rate_err_B[0];

    /* Saturate: '<S84>/Saturation' */
    if (rtb_Saturation1_h_idx_0 > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Saturation1_h_idx_0 = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Saturation1_h_idx_0 < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Saturation1_h_idx_0 = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    rtb_rate_err_B[0] = rtb_Saturation1_h_idx_0;

    /* Product: '<S84>/Multiply' incorporates:
     *  Constant: '<S84>/gain2'
     */
    rtb_Saturation1_h_idx_0 = CONTROL_PARAM.MC_PITCH_RATE_D * rtb_rate_err_B[1];

    /* Saturate: '<S84>/Saturation' */
    if (rtb_Saturation1_h_idx_0 > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Saturation1_h_idx_0 = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Saturation1_h_idx_0 < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Saturation1_h_idx_0 = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    rtb_rate_err_B[1] = rtb_Saturation1_h_idx_0;

    /* Product: '<S84>/Multiply' incorporates:
     *  Constant: '<S84>/gain3'
     */
    rtb_Saturation1_h_idx_0 = CONTROL_PARAM.MC_YAW_RATE_D * rtb_rate_err_B[2];

    /* Saturate: '<S84>/Saturation' */
    if (rtb_Saturation1_h_idx_0 > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Saturation1_h_idx_0 = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Saturation1_h_idx_0 < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Saturation1_h_idx_0 = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    /* Product: '<S69>/Multiply2' incorporates:
     *  Constant: '<S86>/gain1'
     *  DiscreteIntegrator: '<S113>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S83>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S85>/Discrete-Time Integrator'
     *  Product: '<S86>/Multiply'
     *  Sum: '<S81>/Add'
     */
    rtb_Add_c = ((CONTROL_PARAM.MC_ROLL_RATE_P *
                  Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0] +
                  Controller_DW.DiscreteTimeIntegrator_DSTATE_d[0]) +
                 rtb_rate_err_B[0]) *
      Controller_DW.DiscreteTimeIntegrator5_DSTA_a2;

    /* Saturate: '<S69>/Saturation2' */
    if (rtb_Add_c > 1.0F) {
      Controller_B.mc_torque_cmd[0] = 1.0F;
    } else if (rtb_Add_c < -1.0F) {
      Controller_B.mc_torque_cmd[0] = -1.0F;
    } else {
      Controller_B.mc_torque_cmd[0] = rtb_Add_c;
    }

    /* Product: '<S69>/Multiply2' incorporates:
     *  Constant: '<S86>/gain2'
     *  DiscreteIntegrator: '<S113>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S83>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S85>/Discrete-Time Integrator'
     *  Product: '<S86>/Multiply'
     *  Sum: '<S81>/Add'
     */
    rtb_Add_c = ((CONTROL_PARAM.MC_PITCH_RATE_P *
                  Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1] +
                  Controller_DW.DiscreteTimeIntegrator_DSTATE_d[1]) +
                 rtb_rate_err_B[1]) *
      Controller_DW.DiscreteTimeIntegrator5_DSTA_a2;

    /* Saturate: '<S69>/Saturation2' */
    if (rtb_Add_c > 1.0F) {
      Controller_B.mc_torque_cmd[1] = 1.0F;
    } else if (rtb_Add_c < -1.0F) {
      Controller_B.mc_torque_cmd[1] = -1.0F;
    } else {
      Controller_B.mc_torque_cmd[1] = rtb_Add_c;
    }

    /* Product: '<S69>/Multiply2' incorporates:
     *  Constant: '<S86>/gain3'
     *  DiscreteIntegrator: '<S113>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S83>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S85>/Discrete-Time Integrator'
     *  Product: '<S86>/Multiply'
     *  Sum: '<S81>/Add'
     */
    rtb_Add_c = ((CONTROL_PARAM.MC_YAW_RATE_P *
                  Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2] +
                  Controller_DW.DiscreteTimeIntegrator_DSTATE_d[2]) +
                 rtb_Saturation1_h_idx_0) *
      Controller_DW.DiscreteTimeIntegrator5_DSTA_a2;

    /* Saturate: '<S69>/Saturation2' */
    if (rtb_Add_c > 1.0F) {
      Controller_B.mc_torque_cmd[2] = 1.0F;
    } else if (rtb_Add_c < -1.0F) {
      Controller_B.mc_torque_cmd[2] = -1.0F;
    } else {
      Controller_B.mc_torque_cmd[2] = rtb_Add_c;
    }

    /* Gain: '<S103>/Gain' incorporates:
     *  DiscreteIntegrator: '<S105>/Integrator1'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S103>/Sum1'
     */
    rtb_Saturation1_h_idx_0 = -(Controller_DW.Integrator1_DSTATE_i -
      Controller_U.INS_Out.vd);

    /* Logic: '<S100>/Logical Operator' incorporates:
     *  Constant: '<S102>/Constant'
     *  DiscreteIntegrator: '<S113>/Discrete-Time Integrator5'
     *  RelationalOperator: '<S102>/Compare'
     */
    rtb_LogicalOperator_g = ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator5_DSTA_a2 == 0.0F));
    Controller_B.Constant_m = CONTROL_PARAM.MC_VEL_Z_I_MIN;

    /* DiscreteIntegrator: '<S108>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S108>/Constant'
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

    /* DiscreteIntegrator: '<S110>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_i != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_l = rtb_Saturation1_h_idx_0;
    }

    if (rtb_LogicalOperator_g || (Controller_DW.DiscreteTimeIntegrator1_PrevR_h
         != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_l = rtb_Saturation1_h_idx_0;
    }

    /* Gain: '<S110>/Gain' incorporates:
     *  DiscreteIntegrator: '<S110>/Discrete-Time Integrator1'
     *  Sum: '<S110>/Sum5'
     */
    rtb_Switch_c_idx_1 = (rtb_Saturation1_h_idx_0 -
                          Controller_DW.DiscreteTimeIntegrator1_DSTAT_l) *
      62.831852F;

    /* Switch: '<S110>/Switch' incorporates:
     *  Gain: '<S110>/Gain1'
     */
    if (rtb_LogicalOperator_g) {
      rtb_Switch_c_idx_0 = 0.0F;
    } else {
      rtb_Switch_c_idx_0 = rtb_Switch_c_idx_1;
    }

    /* End of Switch: '<S110>/Switch' */

    /* Product: '<S107>/Multiply' incorporates:
     *  Constant: '<S107>/kd'
     */
    rtb_DiscreteTimeIntegrator1_d = CONTROL_PARAM.MC_VEL_Z_D *
      rtb_Switch_c_idx_0;

    /* Saturate: '<S107>/Saturation' */
    if (rtb_DiscreteTimeIntegrator1_d > CONTROL_PARAM.MC_VEL_Z_D_MAX) {
      rtb_DiscreteTimeIntegrator1_d = CONTROL_PARAM.MC_VEL_Z_D_MAX;
    } else {
      if (rtb_DiscreteTimeIntegrator1_d < CONTROL_PARAM.MC_VEL_Z_D_MIN) {
        rtb_DiscreteTimeIntegrator1_d = CONTROL_PARAM.MC_VEL_Z_D_MIN;
      }
    }

    /* End of Saturate: '<S107>/Saturation' */

    /* Sum: '<S104>/Add' incorporates:
     *  Constant: '<S109>/kp'
     *  DiscreteIntegrator: '<S108>/Discrete-Time Integrator'
     *  Product: '<S109>/Multiply'
     */
    rtb_Add_c = (CONTROL_PARAM.MC_VEL_Z_P * rtb_Saturation1_h_idx_0 +
                 Controller_DW.DiscreteTimeIntegrator_DSTATE_b) +
      rtb_DiscreteTimeIntegrator1_d;

    /* Product: '<S101>/Multiply' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S101>/Cos'
     *  Trigonometry: '<S101>/Cos1'
     */
    rtb_DiscreteTimeIntegrator1_d = arm_cos_f32(Controller_U.INS_Out.phi) *
      arm_cos_f32(Controller_U.INS_Out.theta);

    /* Saturate: '<S101>/Saturation1' */
    if (rtb_DiscreteTimeIntegrator1_d > 1.0F) {
      rtb_Switch_c_idx_0 = 1.0F;
    } else if (rtb_DiscreteTimeIntegrator1_d < 0.5F) {
      rtb_Switch_c_idx_0 = 0.5F;
    } else {
      rtb_Switch_c_idx_0 = rtb_DiscreteTimeIntegrator1_d;
    }

    /* End of Saturate: '<S101>/Saturation1' */

    /* Gain: '<S101>/Gain' */
    rtb_DiscreteTimeIntegrator1_d *= 2.0F;

    /* Saturate: '<S101>/Saturation' */
    if (rtb_DiscreteTimeIntegrator1_d > 1.0F) {
      rtb_DiscreteTimeIntegrator1_d = 1.0F;
    } else {
      if (rtb_DiscreteTimeIntegrator1_d < 0.0F) {
        rtb_DiscreteTimeIntegrator1_d = 0.0F;
      }
    }

    /* End of Saturate: '<S101>/Saturation' */

    /* Product: '<S101>/Multiply1' incorporates:
     *  Constant: '<S101>/Constant'
     *  Product: '<S101>/Divide'
     */
    rtb_DiscreteTimeIntegrator1_d *= 1.0F / rtb_Switch_c_idx_0 * rtb_Add_c;

    /* Saturate: '<S100>/Saturation' */
    if (rtb_DiscreteTimeIntegrator1_d > 0.35F) {
      rtb_DiscreteTimeIntegrator1_d = 0.35F;
    } else {
      if (rtb_DiscreteTimeIntegrator1_d < -0.35F) {
        rtb_DiscreteTimeIntegrator1_d = -0.35F;
      }
    }

    /* End of Saturate: '<S100>/Saturation' */

    /* Sum: '<S100>/Sum1' incorporates:
     *  Constant: '<S100>/hover_throttle'
     */
    rtb_DiscreteTimeIntegrator1_d += CONTROL_PARAM.MC_HOVER_THRO;

    /* Saturate: '<S69>/Saturation1' incorporates:
     *  Constant: '<S74>/Constant'
     *  Product: '<S69>/Multiply1'
     */
    Controller_B.mc_force_cmd[0] = 0.0F;
    Controller_B.mc_force_cmd[1] = 0.0F;

    /* Product: '<S69>/Multiply1' incorporates:
     *  DiscreteIntegrator: '<S113>/Discrete-Time Integrator5'
     */
    rtb_Add_c = rtb_DiscreteTimeIntegrator1_d *
      Controller_DW.DiscreteTimeIntegrator5_DSTA_a2;

    /* Saturate: '<S69>/Saturation1' */
    if (rtb_Add_c > 1.0F) {
      Controller_B.mc_force_cmd[2] = 1.0F;
    } else if (rtb_Add_c < -1.0F) {
      Controller_B.mc_force_cmd[2] = -1.0F;
    } else {
      Controller_B.mc_force_cmd[2] = rtb_Add_c;
    }

    /* DiscreteIntegrator: '<S133>/Discrete-Time Integrator' */
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

    /* Bias: '<S138>/Pitch Offset' */
    rtb_Cos1 += CONTROL_PARAM.FW_PITCH_OFFSET;

    /* Saturate: '<S138>/Saturation' */
    if (rtb_Cos1 > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Cos1 = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_Cos1 < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_Cos1 = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      }
    }

    /* Product: '<S139>/Multiply' incorporates:
     *  Constant: '<S139>/Constant2'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S138>/Sum'
     */
    rtb_Multiply_k_idx_1 = (rtb_Cos1 - Controller_U.INS_Out.theta) *
      CONTROL_PARAM.FW_PITCH_P;

    /* Product: '<S141>/Divide' incorporates:
     *  Constant: '<S141>/Constant'
     *  DiscreteIntegrator: '<S115>/Discrete-Time Integrator5'
     */
    rtb_Add_c = 9.81F / Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;

    /* Saturate: '<S141>/Saturation' */
    if (rtb_Add_c > 1.0F) {
      rtb_Add_c = 1.0F;
    } else {
      if (rtb_Add_c < 0.0F) {
        rtb_Add_c = 0.0F;
      }
    }

    /* End of Saturate: '<S141>/Saturation' */

    /* Sum: '<S136>/Sum' incorporates:
     *  Product: '<S141>/Multiply'
     *  Product: '<S141>/Multiply1'
     *  Trigonometry: '<S141>/Cos'
     *  Trigonometry: '<S141>/Tan'
     */
    rtb_Switch_c_idx_0 = tanf(Controller_U.FMS_Out.phi_cmd) * arm_cos_f32
      (Controller_U.FMS_Out.theta_cmd) * rtb_Add_c +
      Controller_U.FMS_Out.psi_rate_cmd;

    /* Saturate: '<S138>/Saturation' */
    if (rtb_Cos > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Cos = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_Cos < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_Cos = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      }
    }

    /* Sum: '<S129>/Add' incorporates:
     *  Constant: '<S139>/Constant1'
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S129>/Multiply'
     *  Product: '<S139>/Multiply'
     *  Sum: '<S138>/Sum'
     */
    rtb_DiscreteTimeIntegrator1_d = (rtb_Cos - Controller_U.INS_Out.phi) *
      CONTROL_PARAM.FW_ROLL_P - rtb_DiscreteTimeIntegrator_l__2 *
      rtb_Switch_c_idx_0;

    /* Sum: '<S129>/Add1' incorporates:
     *  Product: '<S129>/Multiply1'
     *  Product: '<S129>/Multiply3'
     */
    rtb_Cos1 = rtb_DiscreteTimeIntegrator1_e_t * rtb_DiscreteTimeIntegrator1_a_t
      * rtb_Switch_c_idx_0 + rtb_DiscreteTimeIntegrator_p_tm *
      rtb_Multiply_k_idx_1;

    /* Sum: '<S129>/Add2' incorporates:
     *  Product: '<S129>/Multiply4'
     *  Product: '<S129>/Multiply5'
     */
    rtb_Cos = rtb_DiscreteTimeIntegrator_p_tm * rtb_DiscreteTimeIntegrator1_a_t *
      rtb_Switch_c_idx_0 - rtb_DiscreteTimeIntegrator1_e_t *
      rtb_Multiply_k_idx_1;

    /* Sum: '<S127>/Minus2' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_rate_err_B[0] = rtb_DiscreteTimeIntegrator1_d - Controller_U.INS_Out.p;
    rtb_rate_err_B[1] = rtb_Cos1 - Controller_U.INS_Out.q;
    rtb_rate_err_B[2] = rtb_Cos - Controller_U.INS_Out.r;

    /* Product: '<S131>/Divide' incorporates:
     *  Constant: '<S131>/trim_speed'
     *  Math: '<S131>/Square'
     */
    rtb_Switch_c_idx_0 = CONTROL_PARAM.FW_AIRSPEED_TRIM *
      CONTROL_PARAM.FW_AIRSPEED_TRIM / rtb_MatrixConcatenate1_tmp;

    /* Saturate: '<S131>/Saturation' */
    if (rtb_Switch_c_idx_0 > 1.0F) {
      rtb_Switch_c_idx_0 = 1.0F;
    } else {
      if (rtb_Switch_c_idx_0 < 0.0F) {
        rtb_Switch_c_idx_0 = 0.0F;
      }
    }

    /* End of Saturate: '<S131>/Saturation' */

    /* Product: '<S127>/Multiply' incorporates:
     *  Constant: '<S134>/gain1'
     *  Constant: '<S134>/gain2'
     *  Constant: '<S134>/gain3'
     *  DiscreteIntegrator: '<S133>/Discrete-Time Integrator'
     *  Product: '<S134>/Multiply'
     *  Sum: '<S130>/Add1'
     */
    rtb_Add_c = (CONTROL_PARAM.FW_ROLL_RATE_P * rtb_rate_err_B[0] +
                 Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0]) *
      rtb_Switch_c_idx_0;
    rtb_MatrixConcatenate1_tmp = (CONTROL_PARAM.FW_PITCH_RATE_P *
      rtb_rate_err_B[1] + Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1]) *
      rtb_Switch_c_idx_0;
    rtb_DiscreteTimeIntegrator1_e_t = (CONTROL_PARAM.FW_YAW_RATE_P *
      rtb_rate_err_B[2] + Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2]) *
      rtb_Switch_c_idx_0;

    /* Product: '<S132>/Divide' incorporates:
     *  Constant: '<S132>/trim_speed'
     *  DiscreteIntegrator: '<S115>/Discrete-Time Integrator5'
     */
    rtb_Switch_c_idx_0 = CONTROL_PARAM.FW_AIRSPEED_TRIM /
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;

    /* Saturate: '<S132>/Saturation' */
    if (rtb_Switch_c_idx_0 > 1.0F) {
      rtb_Switch_c_idx_0 = 1.0F;
    } else {
      if (rtb_Switch_c_idx_0 < 0.0F) {
        rtb_Switch_c_idx_0 = 0.0F;
      }
    }

    /* End of Saturate: '<S132>/Saturation' */

    /* DiscreteIntegrator: '<S112>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_g != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTA_jo = rtb_Saturation_j;
    }

    /* Product: '<S127>/Multiply1' incorporates:
     *  Gain: '<S127>/FF'
     */
    rtb_DiscreteTimeIntegrator1_d = CONTROL_PARAM.FW_FF *
      rtb_DiscreteTimeIntegrator1_d * rtb_Switch_c_idx_0;

    /* Saturate: '<S127>/FF_limit' */
    if (rtb_DiscreteTimeIntegrator1_d > CONTROL_PARAM.FW_FF_LIMIT) {
      rtb_DiscreteTimeIntegrator1_d = CONTROL_PARAM.FW_FF_LIMIT;
    } else {
      if (rtb_DiscreteTimeIntegrator1_d < -CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_DiscreteTimeIntegrator1_d = -CONTROL_PARAM.FW_FF_LIMIT;
      }
    }

    /* Saturate: '<S127>/PI_limit' */
    if (rtb_Add_c > CONTROL_PARAM.FW_PI_LIMIT) {
      rtb_Add_c = CONTROL_PARAM.FW_PI_LIMIT;
    } else {
      if (rtb_Add_c < -CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_Add_c = -CONTROL_PARAM.FW_PI_LIMIT;
      }
    }

    /* Product: '<S71>/Multiply' incorporates:
     *  DiscreteIntegrator: '<S112>/Discrete-Time Integrator5'
     *  Sum: '<S127>/Add'
     */
    rtb_Add_c = (rtb_DiscreteTimeIntegrator1_d + rtb_Add_c) *
      Controller_DW.DiscreteTimeIntegrator5_DSTA_jo;

    /* Saturate: '<S71>/Saturation1' */
    if (rtb_Add_c > 1.0F) {
      Controller_B.fw_torque_cmd[0] = 1.0F;
    } else if (rtb_Add_c < -1.0F) {
      Controller_B.fw_torque_cmd[0] = -1.0F;
    } else {
      Controller_B.fw_torque_cmd[0] = rtb_Add_c;
    }

    /* Product: '<S127>/Multiply1' incorporates:
     *  Gain: '<S127>/FF'
     */
    rtb_Add_c = CONTROL_PARAM.FW_FF * rtb_Cos1 * rtb_Switch_c_idx_0;

    /* Saturate: '<S127>/FF_limit' */
    if (rtb_Add_c > CONTROL_PARAM.FW_FF_LIMIT) {
      rtb_Add_c = CONTROL_PARAM.FW_FF_LIMIT;
    } else {
      if (rtb_Add_c < -CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_Add_c = -CONTROL_PARAM.FW_FF_LIMIT;
      }
    }

    /* Saturate: '<S127>/PI_limit' */
    if (rtb_MatrixConcatenate1_tmp > CONTROL_PARAM.FW_PI_LIMIT) {
      rtb_MatrixConcatenate1_tmp = CONTROL_PARAM.FW_PI_LIMIT;
    } else {
      if (rtb_MatrixConcatenate1_tmp < -CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_MatrixConcatenate1_tmp = -CONTROL_PARAM.FW_PI_LIMIT;
      }
    }

    /* Product: '<S71>/Multiply' incorporates:
     *  DiscreteIntegrator: '<S112>/Discrete-Time Integrator5'
     *  Sum: '<S127>/Add'
     */
    rtb_Add_c = (rtb_Add_c + rtb_MatrixConcatenate1_tmp) *
      Controller_DW.DiscreteTimeIntegrator5_DSTA_jo;

    /* Saturate: '<S71>/Saturation1' */
    if (rtb_Add_c > 1.0F) {
      Controller_B.fw_torque_cmd[1] = 1.0F;
    } else if (rtb_Add_c < -1.0F) {
      Controller_B.fw_torque_cmd[1] = -1.0F;
    } else {
      Controller_B.fw_torque_cmd[1] = rtb_Add_c;
    }

    /* Product: '<S127>/Multiply1' incorporates:
     *  Gain: '<S127>/FF'
     */
    rtb_Add_c = CONTROL_PARAM.FW_FF * rtb_Cos * rtb_Switch_c_idx_0;

    /* Saturate: '<S127>/FF_limit' */
    if (rtb_Add_c > CONTROL_PARAM.FW_FF_LIMIT) {
      rtb_Add_c = CONTROL_PARAM.FW_FF_LIMIT;
    } else {
      if (rtb_Add_c < -CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_Add_c = -CONTROL_PARAM.FW_FF_LIMIT;
      }
    }

    /* Saturate: '<S127>/PI_limit' */
    if (rtb_DiscreteTimeIntegrator1_e_t > CONTROL_PARAM.FW_PI_LIMIT) {
      rtb_DiscreteTimeIntegrator1_e_t = CONTROL_PARAM.FW_PI_LIMIT;
    } else {
      if (rtb_DiscreteTimeIntegrator1_e_t < -CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_DiscreteTimeIntegrator1_e_t = -CONTROL_PARAM.FW_PI_LIMIT;
      }
    }

    /* Product: '<S71>/Multiply' incorporates:
     *  DiscreteIntegrator: '<S112>/Discrete-Time Integrator5'
     *  Sum: '<S127>/Add'
     */
    rtb_Add_c = (rtb_Add_c + rtb_DiscreteTimeIntegrator1_e_t) *
      Controller_DW.DiscreteTimeIntegrator5_DSTA_jo;

    /* Saturate: '<S71>/Saturation1' */
    if (rtb_Add_c > 1.0F) {
      Controller_B.fw_torque_cmd[2] = 1.0F;
    } else if (rtb_Add_c < -1.0F) {
      Controller_B.fw_torque_cmd[2] = -1.0F;
    } else {
      Controller_B.fw_torque_cmd[2] = rtb_Add_c;
    }

    /* Product: '<S106>/Multiply1' incorporates:
     *  Constant: '<S106>/const1'
     *  DiscreteIntegrator: '<S105>/Integrator'
     */
    rtb_Switch_c_idx_0 = Controller_DW.Integrator_DSTATE_f * 0.05F;

    /* Sum: '<S106>/Add' incorporates:
     *  DiscreteIntegrator: '<S105>/Integrator1'
     *  Sum: '<S105>/Subtract'
     */
    rtb_DiscreteTimeIntegrator1_d = (Controller_DW.Integrator1_DSTATE_i -
      Controller_U.FMS_Out.w_cmd) + rtb_Switch_c_idx_0;

    /* Signum: '<S106>/Sign' */
    if (rtb_DiscreteTimeIntegrator1_d < 0.0F) {
      rtb_Add_c = -1.0F;
    } else if (rtb_DiscreteTimeIntegrator1_d > 0.0F) {
      rtb_Add_c = 1.0F;
    } else {
      rtb_Add_c = rtb_DiscreteTimeIntegrator1_d;
    }

    /* End of Signum: '<S106>/Sign' */

    /* Sum: '<S106>/Add2' incorporates:
     *  Abs: '<S106>/Abs'
     *  Gain: '<S106>/Gain'
     *  Gain: '<S106>/Gain1'
     *  Product: '<S106>/Multiply2'
     *  Product: '<S106>/Multiply3'
     *  Sqrt: '<S106>/Sqrt'
     *  Sum: '<S106>/Add1'
     *  Sum: '<S106>/Subtract'
     */
    rtb_Cos = (sqrtf((8.0F * fabsf(rtb_DiscreteTimeIntegrator1_d) +
                      Controller_ConstB.d_m) * Controller_ConstB.d_m) -
               Controller_ConstB.d_m) * 0.5F * rtb_Add_c + rtb_Switch_c_idx_0;

    /* Sum: '<S106>/Add4' */
    rtb_Switch_c_idx_0 += rtb_DiscreteTimeIntegrator1_d - rtb_Cos;

    /* Sum: '<S106>/Add3' */
    rtb_Add_c = rtb_DiscreteTimeIntegrator1_d + Controller_ConstB.d_m;

    /* Sum: '<S106>/Subtract1' */
    rtb_DiscreteTimeIntegrator1_d -= Controller_ConstB.d_m;

    /* Signum: '<S106>/Sign1' */
    if (rtb_Add_c < 0.0F) {
      rtb_Add_c = -1.0F;
    } else {
      if (rtb_Add_c > 0.0F) {
        rtb_Add_c = 1.0F;
      }
    }

    /* End of Signum: '<S106>/Sign1' */

    /* Signum: '<S106>/Sign2' */
    if (rtb_DiscreteTimeIntegrator1_d < 0.0F) {
      rtb_DiscreteTimeIntegrator1_d = -1.0F;
    } else {
      if (rtb_DiscreteTimeIntegrator1_d > 0.0F) {
        rtb_DiscreteTimeIntegrator1_d = 1.0F;
      }
    }

    /* End of Signum: '<S106>/Sign2' */

    /* Sum: '<S106>/Add5' incorporates:
     *  Gain: '<S106>/Gain2'
     *  Product: '<S106>/Multiply4'
     *  Sum: '<S106>/Subtract2'
     */
    rtb_Cos += (rtb_Add_c - rtb_DiscreteTimeIntegrator1_d) * 0.5F *
      rtb_Switch_c_idx_0;

    /* Sum: '<S125>/Add' incorporates:
     *  Gain: '<S125>/ucmd2thor'
     *  Gain: '<S125>/wcmd2thor'
     */
    rtb_Minus = CONTROL_PARAM.FW_TECS_W2T * rtb_Minus +
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
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm = rtb_Minus;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_d != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm = rtb_Minus;
    }

    /* Gain: '<S161>/Gain' incorporates:
     *  DiscreteIntegrator: '<S161>/Discrete-Time Integrator1'
     *  Sum: '<S161>/Sum5'
     */
    rtb_VdotPg_err = (rtb_Minus - Controller_DW.DiscreteTimeIntegrator1_DSTA_nm)
      * 188.49556F;

    /* Switch: '<S126>/Switch' incorporates:
     *  Bias: '<S126>/Bias'
     *  Constant: '<S170>/Constant'
     *  Gain: '<S126>/Gain'
     *  RelationalOperator: '<S170>/Compare'
     *  Switch: '<S161>/Switch'
     */
    if (rtb_BitwiseAND_n <= 3) {
      rtb_Switch_c_idx_0 = 0.000999987125F * (real32_T)
        Controller_U.FMS_Out.throttle_cmd + -1.0F;
    } else {
      if (Controller_U.FMS_Out.reset > 0) {
        /* Switch: '<S161>/Switch' incorporates:
         *  Gain: '<S161>/Gain1'
         */
        rtb_Cos1 = 0.0F;
      } else {
        /* Switch: '<S161>/Switch' */
        rtb_Cos1 = rtb_VdotPg_err;
      }

      /* Gain: '<S159>/Gain' */
      rtb_Switch_c_idx_0 = CONTROL_PARAM.FW_TECS_THOR_D * rtb_Cos1;

      /* Saturate: '<S147>/Saturation1' */
      if (rtb_Switch_c_idx_0 > 0.3F) {
        rtb_Switch_c_idx_0 = 0.3F;
      } else {
        if (rtb_Switch_c_idx_0 < -0.3F) {
          rtb_Switch_c_idx_0 = -0.3F;
        }
      }

      /* End of Saturate: '<S147>/Saturation1' */

      /* Sum: '<S126>/Sum' incorporates:
       *  Constant: '<S126>/cruise_throttle'
       *  DiscreteIntegrator: '<S160>/ '
       *  Gain: '<S125>/Gain1'
       *  Gain: '<S125>/thorttle_ff'
       *  Gain: '<S147>/P_control'
       *  Sum: '<S125>/Add1'
       *  Sum: '<S125>/Add2'
       *  Sum: '<S125>/Sum1'
       *  Sum: '<S147>/Add4'
       */
      rtb_Switch_c_idx_0 = ((((CONTROL_PARAM.FW_TECS_THOR_P * rtb_Minus +
        Controller_DW._DSTATE_d) + rtb_Switch_c_idx_0) +
        (rtb_DiscreteTimeIntegrator1_c + rtb_VdotPg) *
        CONTROL_PARAM.FW_TECS_THOR_FF) + CONTROL_PARAM.FW_TECS_R2T * rtb_Abs) +
        CONTROL_PARAM.FW_CRUISE_THRO;

      /* Saturate: '<S126>/Saturation' */
      if (rtb_Switch_c_idx_0 > 1.0F) {
        rtb_Switch_c_idx_0 = 1.0F;
      } else {
        if (rtb_Switch_c_idx_0 < -1.0F) {
          rtb_Switch_c_idx_0 = -1.0F;
        }
      }

      /* End of Saturate: '<S126>/Saturation' */
    }

    /* End of Switch: '<S126>/Switch' */

    /* Saturate: '<S126>/Saturation2' incorporates:
     *  Constant: '<S126>/Constant'
     */
    if (rtb_Switch_c_idx_0 > 1.0F) {
      Controller_B.fw_force_cmd[0] = 1.0F;
    } else {
      Controller_B.fw_force_cmd[0] = rtb_Switch_c_idx_0;
    }

    Controller_B.fw_force_cmd[1] = 0.0F;
    Controller_B.fw_force_cmd[2] = 0.0F;

    /* End of Saturate: '<S126>/Saturation2' */

    /* Update for DiscreteIntegrator: '<S115>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S115>/Gain'
     *  Sum: '<S115>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_e = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_j += (rtb_Saturation1 -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j) * 125.663704F * 0.002F;

    /* Update for DiscreteIntegrator: '<S114>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S114>/Gain'
     *  Sum: '<S114>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_L_eo = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_a += (rtb_Divide_gn -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_a) * 31.415926F * 0.002F;

    /* Update for DiscreteIntegrator: '<S113>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S113>/Gain'
     *  Sum: '<S113>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_o = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTA_a2 += ((real32_T)rtb_Relay -
      Controller_DW.DiscreteTimeIntegrator5_DSTA_a2) * 6.28318548F * 0.002F;

    /* Update for DiscreteIntegrator: '<S85>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S85>/gain1'
     *  Constant: '<S85>/gain2'
     *  Constant: '<S85>/gain3'
     *  DiscreteIntegrator: '<S83>/Discrete-Time Integrator5'
     *  Product: '<S85>/Multiply'
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

    /* End of Update for DiscreteIntegrator: '<S85>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S157>/ ' incorporates:
     *  Gain: '<S157>/Gain3'
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

    /* End of Update for DiscreteIntegrator: '<S157>/ ' */

    /* Update for DiscreteIntegrator: '<S158>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_f = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_e += 0.002F * rtb_Gain_c4;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_b = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S83>/Discrete-Time Integrator5' */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_b = 0U;

    /* Update for DiscreteIntegrator: '<S87>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_h = 0U;

    /* Update for DiscreteIntegrator: '<S83>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S83>/Gain'
     *  Sum: '<S83>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0] +=
      (rtb_DiscreteTimeIntegrator_l_id -
       Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S87>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[0] += 0.002F *
      rtb_DiscreteTimeIntegrator1_k1[0];

    /* Update for DiscreteIntegrator: '<S83>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S83>/Gain'
     *  Sum: '<S83>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1] +=
      (rtb_DiscreteTimeIntegrator_l__0 -
       Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S87>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[1] += 0.002F *
      rtb_DiscreteTimeIntegrator1_k1[1];

    /* Update for DiscreteIntegrator: '<S83>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S83>/Gain'
     *  Sum: '<S83>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2] +=
      (rtb_DiscreteTimeIntegrator_l__1 -
       Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S87>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[2] += 0.002F *
      rtb_DiscreteTimeIntegrator1_k1[2];
    Controller_DW.DiscreteTimeIntegrator1_PrevR_l = (int8_T)
      rtb_LogicalOperator_i;

    /* Update for DiscreteIntegrator: '<S105>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S105>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_i += 0.002F *
      Controller_DW.Integrator_DSTATE_f;

    /* Update for DiscreteIntegrator: '<S108>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S108>/ki'
     *  Product: '<S108>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_b += CONTROL_PARAM.MC_VEL_Z_I *
      rtb_Saturation1_h_idx_0 * 0.002F;
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

    /* End of Update for DiscreteIntegrator: '<S108>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S110>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_i = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_l += 0.002F * rtb_Switch_c_idx_1;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_h = (int8_T)
      rtb_LogicalOperator_g;

    /* Update for DiscreteIntegrator: '<S133>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S133>/gain1'
     *  Constant: '<S133>/gain2'
     *  Constant: '<S133>/gain3'
     *  Product: '<S133>/Multiply'
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

    /* End of Update for DiscreteIntegrator: '<S133>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S112>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S112>/Gain'
     *  Sum: '<S112>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_g = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTA_jo += (rtb_Saturation_j -
      Controller_DW.DiscreteTimeIntegrator5_DSTA_jo) * 12.566371F * 0.002F;

    /* Signum: '<S106>/Sign6' incorporates:
     *  Signum: '<S106>/Sign5'
     */
    if (rtb_Cos < 0.0F) {
      rtb_DiscreteTimeIntegrator_l_id = -1.0F;

      /* Signum: '<S106>/Sign5' */
      rtb_DiscreteTimeIntegrator_l__0 = -1.0F;
    } else if (rtb_Cos > 0.0F) {
      rtb_DiscreteTimeIntegrator_l_id = 1.0F;

      /* Signum: '<S106>/Sign5' */
      rtb_DiscreteTimeIntegrator_l__0 = 1.0F;
    } else {
      rtb_DiscreteTimeIntegrator_l_id = rtb_Cos;

      /* Signum: '<S106>/Sign5' */
      rtb_DiscreteTimeIntegrator_l__0 = rtb_Cos;
    }

    /* End of Signum: '<S106>/Sign6' */

    /* Sum: '<S106>/Add6' */
    rtb_Add_c = rtb_Cos + Controller_ConstB.d_m;

    /* Sum: '<S106>/Subtract3' */
    rtb_Saturation1_h_idx_0 = rtb_Cos - Controller_ConstB.d_m;

    /* Signum: '<S106>/Sign3' */
    if (rtb_Add_c < 0.0F) {
      rtb_Add_c = -1.0F;
    } else {
      if (rtb_Add_c > 0.0F) {
        rtb_Add_c = 1.0F;
      }
    }

    /* End of Signum: '<S106>/Sign3' */

    /* Signum: '<S106>/Sign4' */
    if (rtb_Saturation1_h_idx_0 < 0.0F) {
      rtb_Saturation1_h_idx_0 = -1.0F;
    } else {
      if (rtb_Saturation1_h_idx_0 > 0.0F) {
        rtb_Saturation1_h_idx_0 = 1.0F;
      }
    }

    /* End of Signum: '<S106>/Sign4' */

    /* Update for DiscreteIntegrator: '<S105>/Integrator' incorporates:
     *  Constant: '<S106>/const'
     *  Gain: '<S106>/Gain3'
     *  Product: '<S106>/Divide'
     *  Product: '<S106>/Multiply5'
     *  Product: '<S106>/Multiply6'
     *  Sum: '<S106>/Subtract4'
     *  Sum: '<S106>/Subtract5'
     *  Sum: '<S106>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE_f += ((rtb_Cos / Controller_ConstB.d_m -
      rtb_DiscreteTimeIntegrator_l__0) * Controller_ConstB.Gain4_o * ((rtb_Add_c
      - rtb_Saturation1_h_idx_0) * 0.5F) - rtb_DiscreteTimeIntegrator_l_id *
      78.448F) * 0.002F;

    /* Update for DiscreteIntegrator: '<S160>/ ' incorporates:
     *  Gain: '<S160>/Gain'
     */
    Controller_DW._DSTATE_d += CONTROL_PARAM.FW_TECS_THOR_I * rtb_Minus * 0.002F;
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
    rtb_MatrixConcatenate1[0] = arm_cos_f32(-Controller_U.INS_Out.psi);

    /* Trigonometry: '<S210>/Trigonometric Function' incorporates:
     *  Gain: '<S209>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1[1] = arm_sin_f32(-Controller_U.INS_Out.psi);

    /* SignalConversion: '<S210>/ConcatBufferAtVector Concatenate1In3' incorporates:
     *  Constant: '<S210>/Constant3'
     */
    rtb_MatrixConcatenate1[2] = 0.0F;

    /* Gain: '<S210>/Gain' incorporates:
     *  Gain: '<S209>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S210>/Trigonometric Function2'
     */
    rtb_MatrixConcatenate1[3] = -arm_sin_f32(-Controller_U.INS_Out.psi);

    /* Trigonometry: '<S210>/Trigonometric Function3' incorporates:
     *  Gain: '<S209>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1[4] = arm_cos_f32(-Controller_U.INS_Out.psi);

    /* SignalConversion: '<S210>/ConcatBufferAtVector Concatenate2In3' incorporates:
     *  Constant: '<S210>/Constant4'
     */
    rtb_MatrixConcatenate1[5] = 0.0F;

    /* SignalConversion: '<S210>/ConcatBufferAtVector ConcatenateIn3' */
    rtb_MatrixConcatenate1[6] = Controller_ConstB.VectorConcatenate3[0];
    rtb_MatrixConcatenate1[7] = Controller_ConstB.VectorConcatenate3[1];
    rtb_MatrixConcatenate1[8] = Controller_ConstB.VectorConcatenate3[2];

    /* Product: '<S207>/Multiply' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  SignalConversion: '<S207>/TmpSignal ConversionAtMultiplyInport2'
     */
    for (rtb_Relay = 0; rtb_Relay < 3; rtb_Relay++) {
      rtb_DiscreteTimeIntegrator1_k1[rtb_Relay] =
        rtb_MatrixConcatenate1[rtb_Relay + 3] * Controller_U.INS_Out.ve +
        rtb_MatrixConcatenate1[rtb_Relay] * Controller_U.INS_Out.vn;
    }

    /* End of Product: '<S207>/Multiply' */

    /* Sum: '<S204>/Sum' incorporates:
     *  DiscreteIntegrator: '<S208>/Integrator1'
     */
    rtb_Switch_c_idx_0 = Controller_DW.Integrator1_DSTATE[0] -
      rtb_DiscreteTimeIntegrator1_k1[0];
    rtb_Switch_c_idx_1 = Controller_DW.Integrator1_DSTATE[1] -
      rtb_DiscreteTimeIntegrator1_k1[1];

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
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] = rtb_Switch_c_idx_0;
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] = rtb_Switch_c_idx_1;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevRes != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] = rtb_Switch_c_idx_0;
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] = rtb_Switch_c_idx_1;
    }

    /* Gain: '<S215>/Gain' incorporates:
     *  DiscreteIntegrator: '<S215>/Discrete-Time Integrator1'
     *  Sum: '<S215>/Sum5'
     */
    rtb_Saturation1_h_idx_0 = (rtb_Switch_c_idx_0 -
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[0]) * 62.831852F;
    rtb_Saturation1 = (rtb_Switch_c_idx_1 -
                       Controller_DW.DiscreteTimeIntegrator1_DSTATE[1]) *
      62.831852F;

    /* Switch: '<S215>/Switch' incorporates:
     *  Gain: '<S215>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_DiscreteTimeIntegrator_l__0 = 0.0F;
      rtb_DiscreteTimeIntegrator_l__1 = 0.0F;
    } else {
      rtb_DiscreteTimeIntegrator_l__0 = rtb_Saturation1_h_idx_0;
      rtb_DiscreteTimeIntegrator_l__1 = rtb_Saturation1;
    }

    /* End of Switch: '<S215>/Switch' */

    /* Product: '<S212>/Multiply' incorporates:
     *  Constant: '<S212>/kd'
     */
    rtb_Divide_gn = CONTROL_PARAM.MC_VEL_XY_D * rtb_DiscreteTimeIntegrator_l__0;

    /* Saturate: '<S212>/Saturation' */
    if (rtb_Divide_gn > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
      rtb_Divide_gn = CONTROL_PARAM.MC_VEL_XY_D_MAX;
    } else {
      if (rtb_Divide_gn < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
        rtb_Divide_gn = CONTROL_PARAM.MC_VEL_XY_D_MIN;
      }
    }

    rtb_DiscreteTimeIntegrator_l__0 = rtb_Divide_gn;

    /* Product: '<S212>/Multiply' incorporates:
     *  Constant: '<S212>/kd'
     */
    rtb_Divide_gn = CONTROL_PARAM.MC_VEL_XY_D * rtb_DiscreteTimeIntegrator_l__1;

    /* Saturate: '<S212>/Saturation' */
    if (rtb_Divide_gn > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
      rtb_Divide_gn = CONTROL_PARAM.MC_VEL_XY_D_MAX;
    } else {
      if (rtb_Divide_gn < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
        rtb_Divide_gn = CONTROL_PARAM.MC_VEL_XY_D_MIN;
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
      rtb_DiscreteTimeIntegrator_l__0 = ((Controller_U.FMS_Out.cmd_mask & 64) >
        0 ? (CONTROL_PARAM.MC_VEL_XY_P * rtb_Switch_c_idx_0 +
             Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0]) +
        rtb_DiscreteTimeIntegrator_l__0 : 0.0F) +
        ((Controller_U.FMS_Out.cmd_mask & 512) > 0 ? Controller_U.FMS_Out.ax_cmd
         : 0.0F);
      rtb_DiscreteTimeIntegrator_l__1 = ((Controller_U.FMS_Out.cmd_mask & 128) >
        0 ? (CONTROL_PARAM.MC_VEL_XY_P * rtb_Switch_c_idx_1 +
             Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1]) + rtb_Divide_gn :
        0.0F) + ((Controller_U.FMS_Out.cmd_mask & 1024) > 0 ?
                 Controller_U.FMS_Out.ay_cmd : 0.0F);
    } else {
      rtb_DiscreteTimeIntegrator_l__0 += CONTROL_PARAM.MC_VEL_XY_P *
        rtb_Switch_c_idx_0 + Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0];
      rtb_DiscreteTimeIntegrator_l__1 = (CONTROL_PARAM.MC_VEL_XY_P *
        rtb_Switch_c_idx_1 + Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1]) +
        rtb_Divide_gn;
    }

    /* End of Switch: '<S206>/Switch' */

    /* Trigonometry: '<S203>/Atan' incorporates:
     *  Constant: '<S203>/g'
     *  Gain: '<S203>/Gain1'
     *  Gain: '<S203>/gain'
     *  Product: '<S203>/Divide'
     */
    rtb_Add_c = atanf(1.1F * rtb_DiscreteTimeIntegrator_l__1 / 9.8055F);
    rtb_DiscreteTimeIntegrator_l__1 = atanf(1.1F *
      -rtb_DiscreteTimeIntegrator_l__0 / 9.8055F);

    /* Switch: '<S194>/Switch' incorporates:
     *  Constant: '<S201>/Constant'
     *  Logic: '<S194>/Logical Operator'
     *  RelationalOperator: '<S200>/Compare'
     *  RelationalOperator: '<S201>/Compare'
     *  Saturate: '<S203>/Saturation'
     *  Switch: '<S194>/Switch1'
     */
    if ((rtb_BitwiseAND_n == 3) || (rtb_BitwiseAND_n == 4)) {
      rtb_DiscreteTimeIntegrator_l__0 = Controller_U.FMS_Out.phi_cmd;
      rtb_DiscreteTimeIntegrator_l__1 = Controller_U.FMS_Out.theta_cmd;
    } else if (rtb_BitwiseAND_n == 6) {
      /* Switch: '<S202>/Switch' incorporates:
       *  S-Function (sfix_bitop): '<S202>/cmd_phi valid'
       *  S-Function (sfix_bitop): '<S202>/cmd_theta valid'
       *  Saturate: '<S203>/Saturation'
       *  Switch: '<S194>/Switch1'
       */
      if ((Controller_U.FMS_Out.cmd_mask & 8) > 0) {
        rtb_DiscreteTimeIntegrator_l__0 = Controller_U.FMS_Out.phi_cmd;
      } else if (rtb_Add_c > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S203>/Saturation' */
        rtb_DiscreteTimeIntegrator_l__0 = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else if (rtb_Add_c < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S203>/Saturation' */
        rtb_DiscreteTimeIntegrator_l__0 = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        rtb_DiscreteTimeIntegrator_l__0 = rtb_Add_c;
      }

      if ((Controller_U.FMS_Out.cmd_mask & 16) > 0) {
        rtb_DiscreteTimeIntegrator_l__1 = Controller_U.FMS_Out.theta_cmd;
      } else if (rtb_DiscreteTimeIntegrator_l__1 >
                 CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S203>/Saturation' */
        rtb_DiscreteTimeIntegrator_l__1 = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_DiscreteTimeIntegrator_l__1 <
            -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Saturate: '<S203>/Saturation' */
          rtb_DiscreteTimeIntegrator_l__1 = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        }
      }

      /* End of Switch: '<S202>/Switch' */
    } else {
      if (rtb_Add_c > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S203>/Saturation' incorporates:
         *  Switch: '<S194>/Switch1'
         */
        rtb_DiscreteTimeIntegrator_l__0 = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else if (rtb_Add_c < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S203>/Saturation' incorporates:
         *  Switch: '<S194>/Switch1'
         */
        rtb_DiscreteTimeIntegrator_l__0 = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        /* Switch: '<S194>/Switch1' incorporates:
         *  Saturate: '<S203>/Saturation'
         */
        rtb_DiscreteTimeIntegrator_l__0 = rtb_Add_c;
      }

      /* Saturate: '<S203>/Saturation' */
      if (rtb_DiscreteTimeIntegrator_l__1 > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM)
      {
        /* Switch: '<S194>/Switch1' */
        rtb_DiscreteTimeIntegrator_l__1 = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_DiscreteTimeIntegrator_l__1 <
            -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Switch: '<S194>/Switch1' */
          rtb_DiscreteTimeIntegrator_l__1 = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        }
      }
    }

    /* End of Switch: '<S194>/Switch' */

    /* Sum: '<S195>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_gn = rtb_DiscreteTimeIntegrator_l__0 - Controller_U.INS_Out.phi;

    /* Product: '<S198>/Divide1' incorporates:
     *  Abs: '<S198>/Abs'
     *  Constant: '<S198>/const2'
     */
    rtb_DiscreteTimeIntegrator_l_id = fabsf(rtb_Divide_gn) / 0.002F;

    /* Product: '<S198>/Divide' incorporates:
     *  Constant: '<S196>/Constant1'
     *  Constant: '<S198>/const1'
     *  Math: '<S198>/Square'
     *  SignalConversion: '<S198>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_Saturation_j = 9.5993F / (CONTROL_PARAM.MC_ROLL_P *
      CONTROL_PARAM.MC_ROLL_P);

    /* Signum: '<S198>/Sign' */
    if (rtb_Divide_gn < 0.0F) {
      rtb_Add_c = -1.0F;
    } else if (rtb_Divide_gn > 0.0F) {
      rtb_Add_c = 1.0F;
    } else {
      rtb_Add_c = rtb_Divide_gn;
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
    if ((rtb_Divide_gn <= rtb_Saturation_j) && (rtb_Divide_gn >=
         -rtb_Saturation_j)) {
      rtb_Add_c = rtb_Divide_gn * CONTROL_PARAM.MC_ROLL_P;
    } else {
      rtb_Add_c *= sqrtf((rtb_Add_c * rtb_Divide_gn - 0.5F * rtb_Saturation_j) *
                         Controller_ConstB.Gain);
    }

    /* Gain: '<S198>/Gain3' */
    rtb_Saturation_j = -rtb_DiscreteTimeIntegrator_l_id;

    /* Switch: '<S199>/Switch' incorporates:
     *  Gain: '<S198>/Gain3'
     *  RelationalOperator: '<S199>/UpperRelop'
     */
    if (rtb_Add_c >= -rtb_DiscreteTimeIntegrator_l_id) {
      rtb_Saturation_j = rtb_Add_c;
    }

    /* Switch: '<S199>/Switch2' incorporates:
     *  RelationalOperator: '<S199>/LowerRelop1'
     */
    if (rtb_Add_c <= rtb_DiscreteTimeIntegrator_l_id) {
      rtb_DiscreteTimeIntegrator_l_id = rtb_Saturation_j;
    }

    /* Saturate: '<S179>/Saturation1' */
    if (rtb_DiscreteTimeIntegrator_l_id > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_DiscreteTimeIntegrator_l_id = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_DiscreteTimeIntegrator_l_id < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_DiscreteTimeIntegrator_l_id = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    rtb_DiscreteTimeIntegrator_l__0 = rtb_DiscreteTimeIntegrator_l_id;

    /* Sum: '<S195>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S198>/Divide1'
     */
    rtb_Divide_gn = rtb_DiscreteTimeIntegrator_l__1 - Controller_U.INS_Out.theta;

    /* Product: '<S198>/Divide1' incorporates:
     *  Abs: '<S198>/Abs'
     *  Constant: '<S198>/const2'
     */
    rtb_DiscreteTimeIntegrator_l_id = fabsf(rtb_Divide_gn) / 0.002F;

    /* Product: '<S198>/Divide' incorporates:
     *  Constant: '<S196>/Constant2'
     *  Constant: '<S198>/const1'
     *  Math: '<S198>/Square'
     *  SignalConversion: '<S198>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_Saturation_j = 9.5993F / (CONTROL_PARAM.MC_PITCH_P *
      CONTROL_PARAM.MC_PITCH_P);

    /* Signum: '<S198>/Sign' */
    if (rtb_Divide_gn < 0.0F) {
      rtb_Add_c = -1.0F;
    } else if (rtb_Divide_gn > 0.0F) {
      rtb_Add_c = 1.0F;
    } else {
      rtb_Add_c = rtb_Divide_gn;
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
    if ((rtb_Divide_gn <= rtb_Saturation_j) && (rtb_Divide_gn >=
         -rtb_Saturation_j)) {
      rtb_Add_c = rtb_Divide_gn * CONTROL_PARAM.MC_PITCH_P;
    } else {
      rtb_Add_c *= sqrtf((rtb_Add_c * rtb_Divide_gn - 0.5F * rtb_Saturation_j) *
                         Controller_ConstB.Gain);
    }

    /* Gain: '<S198>/Gain3' */
    rtb_Saturation_j = -rtb_DiscreteTimeIntegrator_l_id;

    /* Switch: '<S199>/Switch' incorporates:
     *  Gain: '<S198>/Gain3'
     *  RelationalOperator: '<S199>/UpperRelop'
     */
    if (rtb_Add_c >= -rtb_DiscreteTimeIntegrator_l_id) {
      rtb_Saturation_j = rtb_Add_c;
    }

    /* Switch: '<S199>/Switch2' incorporates:
     *  RelationalOperator: '<S199>/LowerRelop1'
     */
    if (rtb_Add_c <= rtb_DiscreteTimeIntegrator_l_id) {
      rtb_DiscreteTimeIntegrator_l_id = rtb_Saturation_j;
    }

    /* Saturate: '<S179>/Saturation1' */
    if (rtb_DiscreteTimeIntegrator_l_id > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_DiscreteTimeIntegrator_l_id = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_DiscreteTimeIntegrator_l_id < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_DiscreteTimeIntegrator_l_id = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    /* Saturate: '<S179>/Saturation' */
    if (Controller_U.FMS_Out.psi_rate_cmd > CONTROL_PARAM.MC_R_CMD_LIM) {
      rtb_Abs = CONTROL_PARAM.MC_R_CMD_LIM;
    } else if (Controller_U.FMS_Out.psi_rate_cmd < -CONTROL_PARAM.MC_R_CMD_LIM)
    {
      rtb_Abs = -CONTROL_PARAM.MC_R_CMD_LIM;
    } else {
      rtb_Abs = Controller_U.FMS_Out.psi_rate_cmd;
    }

    /* End of Saturate: '<S179>/Saturation' */

    /* Trigonometry: '<S189>/Sin' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Saturation_j = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S189>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_DiscreteTimeIntegrator1_c = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Product: '<S189>/Multiply3' incorporates:
     *  Trigonometry: '<S189>/Cos1'
     *  Trigonometry: '<S189>/Sin'
     */
    rtb_DiscreteTimeIntegrator_l__1 = rtb_Saturation_j *
      rtb_DiscreteTimeIntegrator1_c * rtb_Abs;

    /* Trigonometry: '<S189>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_gn = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Product: '<S189>/Multiply1' incorporates:
     *  Trigonometry: '<S189>/Cos'
     */
    rtb_VdotPg = rtb_Divide_gn * rtb_DiscreteTimeIntegrator_l_id;

    /* Product: '<S189>/Multiply4' incorporates:
     *  Trigonometry: '<S189>/Sin'
     */
    rtb_Saturation_j *= rtb_DiscreteTimeIntegrator_l_id;

    /* Switch: '<S180>/Switch' incorporates:
     *  Constant: '<S190>/Constant'
     *  Constant: '<S191>/Constant'
     *  RelationalOperator: '<S190>/Compare'
     *  RelationalOperator: '<S191>/Compare'
     *  Switch: '<S180>/Switch1'
     */
    if (rtb_BitwiseAND_n == 2) {
      rtb_Multiply_b[0] = Controller_U.FMS_Out.p_cmd;
      rtb_Multiply_b[1] = Controller_U.FMS_Out.q_cmd;
      rtb_Multiply_b[2] = Controller_U.FMS_Out.r_cmd;
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
        rtb_Multiply_b[0] = Controller_U.FMS_Out.p_cmd;
      } else {
        rtb_Multiply_b[0] = rtb_DiscreteTimeIntegrator_l__0 - arm_sin_f32
          (Controller_U.INS_Out.theta) * rtb_Abs;
      }

      if ((Controller_U.FMS_Out.cmd_mask & 2) > 0) {
        rtb_Multiply_b[1] = Controller_U.FMS_Out.q_cmd;
      } else {
        rtb_Multiply_b[1] = rtb_DiscreteTimeIntegrator_l__1 + rtb_VdotPg;
      }

      if ((Controller_U.FMS_Out.cmd_mask & 4) > 0) {
        rtb_Multiply_b[2] = Controller_U.FMS_Out.r_cmd;
      } else {
        rtb_Multiply_b[2] = rtb_Divide_gn * rtb_DiscreteTimeIntegrator1_c *
          rtb_Abs - rtb_Saturation_j;
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
      rtb_Multiply_b[0] = rtb_DiscreteTimeIntegrator_l__0 - arm_sin_f32
        (Controller_U.INS_Out.theta) * rtb_Abs;
      rtb_Multiply_b[1] = rtb_VdotPg + rtb_DiscreteTimeIntegrator_l__1;
      rtb_Multiply_b[2] = rtb_Divide_gn * rtb_DiscreteTimeIntegrator1_c *
        rtb_Abs - rtb_Saturation_j;
    }

    /* End of Switch: '<S180>/Switch' */

    /* Sum: '<S181>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_rate_err_B[0] = rtb_Multiply_b[0] - Controller_U.INS_Out.p;
    rtb_rate_err_B[1] = rtb_Multiply_b[1] - Controller_U.INS_Out.q;
    rtb_rate_err_B[2] = rtb_Multiply_b[2] - Controller_U.INS_Out.r;

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
    rtb_Multiply_b[0] = (Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] -
                         Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[0]) *
      188.49556F;
    rtb_Multiply_b[1] = (Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] -
                         Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[1]) *
      188.49556F;
    rtb_Multiply_b[2] = (Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] -
                         Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[2]) *
      188.49556F;

    /* Switch: '<S188>/Switch' incorporates:
     *  Gain: '<S188>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_DiscreteTimeIntegrator_l_id = 0.0F;
      rtb_DiscreteTimeIntegrator_l__0 = 0.0F;
      rtb_DiscreteTimeIntegrator_l__1 = 0.0F;
    } else {
      rtb_DiscreteTimeIntegrator_l_id = rtb_Multiply_b[0];
      rtb_DiscreteTimeIntegrator_l__0 = rtb_Multiply_b[1];
      rtb_DiscreteTimeIntegrator_l__1 = rtb_Multiply_b[2];
    }

    /* End of Switch: '<S188>/Switch' */

    /* Product: '<S185>/Multiply' incorporates:
     *  Constant: '<S185>/gain1'
     */
    rtb_Divide_gn = CONTROL_PARAM.MC_ROLL_RATE_D *
      rtb_DiscreteTimeIntegrator_l_id;

    /* Saturate: '<S185>/Saturation' */
    if (rtb_Divide_gn > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Divide_gn = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Divide_gn < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Divide_gn = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    rtb_DiscreteTimeIntegrator_l_id = rtb_Divide_gn;

    /* Product: '<S185>/Multiply' incorporates:
     *  Constant: '<S185>/gain2'
     */
    rtb_Divide_gn = CONTROL_PARAM.MC_PITCH_RATE_D *
      rtb_DiscreteTimeIntegrator_l__0;

    /* Saturate: '<S185>/Saturation' */
    if (rtb_Divide_gn > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Divide_gn = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Divide_gn < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Divide_gn = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    rtb_DiscreteTimeIntegrator_l__0 = rtb_Divide_gn;

    /* Product: '<S185>/Multiply' incorporates:
     *  Constant: '<S185>/gain3'
     */
    rtb_Divide_gn = CONTROL_PARAM.MC_YAW_RATE_D *
      rtb_DiscreteTimeIntegrator_l__1;

    /* Saturate: '<S185>/Saturation' */
    if (rtb_Divide_gn > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Divide_gn = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Divide_gn < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Divide_gn = CONTROL_PARAM.MC_RATE_D_MIN;
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
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0]) +
      rtb_DiscreteTimeIntegrator_l_id;
    Controller_B.mc_torque_cmd[1] = (CONTROL_PARAM.MC_PITCH_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1]) +
      rtb_DiscreteTimeIntegrator_l__0;
    Controller_B.mc_torque_cmd[2] = (CONTROL_PARAM.MC_YAW_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[2]) + rtb_Divide_gn;

    /* Product: '<S211>/Multiply1' incorporates:
     *  Constant: '<S211>/const1'
     *  DiscreteIntegrator: '<S208>/Integrator'
     */
    rtb_DiscreteTimeIntegrator1_c = Controller_DW.Integrator_DSTATE[0] * 0.05F;
    rtb_Saturation_j = Controller_DW.Integrator_DSTATE[1] * 0.05F;

    /* Sum: '<S211>/Add' incorporates:
     *  DiscreteIntegrator: '<S208>/Integrator1'
     *  Sum: '<S208>/Subtract'
     */
    rtb_DiscreteTimeIntegrator_l__0 = (Controller_DW.Integrator1_DSTATE[0] -
      Controller_U.FMS_Out.u_cmd) + rtb_DiscreteTimeIntegrator1_c;
    rtb_DiscreteTimeIntegrator_l__1 = (Controller_DW.Integrator1_DSTATE[1] -
      Controller_U.FMS_Out.v_cmd) + rtb_Saturation_j;

    /* Signum: '<S211>/Sign' */
    if (rtb_DiscreteTimeIntegrator_l__0 < 0.0F) {
      rtb_DiscreteTimeIntegrator_l_id = -1.0F;
    } else if (rtb_DiscreteTimeIntegrator_l__0 > 0.0F) {
      rtb_DiscreteTimeIntegrator_l_id = 1.0F;
    } else {
      rtb_DiscreteTimeIntegrator_l_id = rtb_DiscreteTimeIntegrator_l__0;
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
    rtb_DiscreteTimeIntegrator_l_id = (sqrtf((8.0F * fabsf
      (rtb_DiscreteTimeIntegrator_l__0) + Controller_ConstB.d) *
      Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
      rtb_DiscreteTimeIntegrator_l_id + rtb_DiscreteTimeIntegrator1_c;

    /* Sum: '<S211>/Add3' incorporates:
     *  Signum: '<S211>/Sign'
     */
    rtb_Add_c = rtb_DiscreteTimeIntegrator_l__0 + Controller_ConstB.d;

    /* Sum: '<S211>/Subtract1' incorporates:
     *  Signum: '<S211>/Sign'
     */
    rtb_Divide_gn = rtb_DiscreteTimeIntegrator_l__0 - Controller_ConstB.d;

    /* Signum: '<S211>/Sign1' */
    if (rtb_Add_c < 0.0F) {
      rtb_Add_c = -1.0F;
    } else {
      if (rtb_Add_c > 0.0F) {
        rtb_Add_c = 1.0F;
      }
    }

    /* Signum: '<S211>/Sign2' */
    if (rtb_Divide_gn < 0.0F) {
      rtb_Divide_gn = -1.0F;
    } else {
      if (rtb_Divide_gn > 0.0F) {
        rtb_Divide_gn = 1.0F;
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
    rtb_DiscreteTimeIntegrator_l__0 = ((rtb_DiscreteTimeIntegrator_l__0 -
      rtb_DiscreteTimeIntegrator_l_id) + rtb_DiscreteTimeIntegrator1_c) *
      ((rtb_Add_c - rtb_Divide_gn) * 0.5F) + rtb_DiscreteTimeIntegrator_l_id;

    /* Signum: '<S211>/Sign' */
    if (rtb_DiscreteTimeIntegrator_l__1 < 0.0F) {
      rtb_DiscreteTimeIntegrator_l_id = -1.0F;
    } else if (rtb_DiscreteTimeIntegrator_l__1 > 0.0F) {
      rtb_DiscreteTimeIntegrator_l_id = 1.0F;
    } else {
      rtb_DiscreteTimeIntegrator_l_id = rtb_DiscreteTimeIntegrator_l__1;
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
    rtb_DiscreteTimeIntegrator_l_id = (sqrtf((8.0F * fabsf
      (rtb_DiscreteTimeIntegrator_l__1) + Controller_ConstB.d) *
      Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
      rtb_DiscreteTimeIntegrator_l_id + rtb_Saturation_j;

    /* Sum: '<S211>/Add3' incorporates:
     *  Signum: '<S211>/Sign'
     */
    rtb_Add_c = rtb_DiscreteTimeIntegrator_l__1 + Controller_ConstB.d;

    /* Sum: '<S211>/Subtract1' incorporates:
     *  Signum: '<S211>/Sign'
     */
    rtb_Divide_gn = rtb_DiscreteTimeIntegrator_l__1 - Controller_ConstB.d;

    /* Signum: '<S211>/Sign1' */
    if (rtb_Add_c < 0.0F) {
      rtb_Add_c = -1.0F;
    } else {
      if (rtb_Add_c > 0.0F) {
        rtb_Add_c = 1.0F;
      }
    }

    /* Signum: '<S211>/Sign2' */
    if (rtb_Divide_gn < 0.0F) {
      rtb_Divide_gn = -1.0F;
    } else {
      if (rtb_Divide_gn > 0.0F) {
        rtb_Divide_gn = 1.0F;
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
    rtb_DiscreteTimeIntegrator_l_id += ((rtb_DiscreteTimeIntegrator_l__1 -
      rtb_DiscreteTimeIntegrator_l_id) + rtb_Saturation_j) * ((rtb_Add_c -
      rtb_Divide_gn) * 0.5F);

    /* Gain: '<S229>/Gain' incorporates:
     *  DiscreteIntegrator: '<S231>/Integrator1'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S229>/Sum1'
     */
    rtb_DiscreteTimeIntegrator_l__1 = -(Controller_DW.Integrator1_DSTATE_e -
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
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i =
        rtb_DiscreteTimeIntegrator_l__1;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_Prev_ks != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i =
        rtb_DiscreteTimeIntegrator_l__1;
    }

    /* Gain: '<S236>/Gain' incorporates:
     *  DiscreteIntegrator: '<S236>/Discrete-Time Integrator1'
     *  Sum: '<S236>/Sum5'
     */
    rtb_Divide_gn = (rtb_DiscreteTimeIntegrator_l__1 -
                     Controller_DW.DiscreteTimeIntegrator1_DSTAT_i) * 62.831852F;

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
      rtb_DiscreteTimeIntegrator1_c = arm_cos_f32(Controller_U.INS_Out.phi) *
        arm_cos_f32(Controller_U.INS_Out.theta);

      /* Gain: '<S228>/Gain' */
      rtb_Add_c = 2.0F * rtb_DiscreteTimeIntegrator1_c;

      /* Saturate: '<S228>/Saturation1' */
      if (rtb_DiscreteTimeIntegrator1_c > 1.0F) {
        rtb_DiscreteTimeIntegrator1_c = 1.0F;
      } else {
        if (rtb_DiscreteTimeIntegrator1_c < 0.5F) {
          rtb_DiscreteTimeIntegrator1_c = 0.5F;
        }
      }

      /* End of Saturate: '<S228>/Saturation1' */

      /* Product: '<S228>/Divide' incorporates:
       *  Constant: '<S228>/Constant'
       */
      rtb_Saturation_j = 1.0F / rtb_DiscreteTimeIntegrator1_c;

      /* Switch: '<S236>/Switch' incorporates:
       *  Gain: '<S236>/Gain1'
       */
      if (Controller_U.FMS_Out.reset > 0) {
        rtb_Cos1 = 0.0F;
      } else {
        rtb_Cos1 = rtb_Divide_gn;
      }

      /* End of Switch: '<S236>/Switch' */

      /* Product: '<S233>/Multiply' incorporates:
       *  Constant: '<S233>/kd'
       */
      rtb_DiscreteTimeIntegrator1_c = CONTROL_PARAM.MC_VEL_Z_D * rtb_Cos1;

      /* Saturate: '<S233>/Saturation' */
      if (rtb_DiscreteTimeIntegrator1_c > CONTROL_PARAM.MC_VEL_Z_D_MAX) {
        rtb_DiscreteTimeIntegrator1_c = CONTROL_PARAM.MC_VEL_Z_D_MAX;
      } else {
        if (rtb_DiscreteTimeIntegrator1_c < CONTROL_PARAM.MC_VEL_Z_D_MIN) {
          rtb_DiscreteTimeIntegrator1_c = CONTROL_PARAM.MC_VEL_Z_D_MIN;
        }
      }

      /* End of Saturate: '<S233>/Saturation' */

      /* Saturate: '<S228>/Saturation' */
      if (rtb_Add_c > 1.0F) {
        rtb_Add_c = 1.0F;
      } else {
        if (rtb_Add_c < 0.0F) {
          rtb_Add_c = 0.0F;
        }
      }

      /* End of Saturate: '<S228>/Saturation' */

      /* Product: '<S228>/Multiply1' incorporates:
       *  Constant: '<S235>/kp'
       *  DiscreteIntegrator: '<S234>/Discrete-Time Integrator'
       *  Product: '<S235>/Multiply'
       *  Sum: '<S230>/Add'
       */
      rtb_Saturation_j = ((CONTROL_PARAM.MC_VEL_Z_P *
                           rtb_DiscreteTimeIntegrator_l__1 +
                           Controller_DW.DiscreteTimeIntegrator_DSTATE_l) +
                          rtb_DiscreteTimeIntegrator1_c) * rtb_Saturation_j *
        rtb_Add_c;

      /* Saturate: '<S226>/Saturation' */
      if (rtb_Saturation_j > 0.35F) {
        rtb_Saturation_j = 0.35F;
      } else {
        if (rtb_Saturation_j < -0.35F) {
          rtb_Saturation_j = -0.35F;
        }
      }

      /* End of Saturate: '<S226>/Saturation' */

      /* SignalConversion: '<S6>/BusConversion_InsertedFor_VTOL_actuator_cmd_at_inport_0' incorporates:
       *  Constant: '<S226>/hover_throttle'
       *  Sum: '<S226>/Sum'
       */
      Controller_B.mc_force_cmd[2] = rtb_Saturation_j +
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
    rtb_Abs = Controller_DW.Integrator_DSTATE_j * 0.05F;

    /* Sum: '<S232>/Add' incorporates:
     *  DiscreteIntegrator: '<S231>/Integrator1'
     *  Sum: '<S231>/Subtract'
     */
    rtb_DiscreteTimeIntegrator1_c = (Controller_DW.Integrator1_DSTATE_e -
      Controller_U.FMS_Out.w_cmd) + rtb_Abs;

    /* Signum: '<S232>/Sign' */
    if (rtb_DiscreteTimeIntegrator1_c < 0.0F) {
      rtb_Saturation_j = -1.0F;
    } else if (rtb_DiscreteTimeIntegrator1_c > 0.0F) {
      rtb_Saturation_j = 1.0F;
    } else {
      rtb_Saturation_j = rtb_DiscreteTimeIntegrator1_c;
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
    rtb_Saturation_j = (sqrtf((8.0F * fabsf(rtb_DiscreteTimeIntegrator1_c) +
      Controller_ConstB.d_i) * Controller_ConstB.d_i) - Controller_ConstB.d_i) *
      0.5F * rtb_Saturation_j + rtb_Abs;

    /* Sum: '<S232>/Add4' */
    rtb_Abs += rtb_DiscreteTimeIntegrator1_c - rtb_Saturation_j;

    /* Sum: '<S232>/Add3' */
    rtb_Add_c = rtb_DiscreteTimeIntegrator1_c + Controller_ConstB.d_i;

    /* Sum: '<S232>/Subtract1' */
    rtb_DiscreteTimeIntegrator1_c -= Controller_ConstB.d_i;

    /* Signum: '<S232>/Sign1' */
    if (rtb_Add_c < 0.0F) {
      rtb_Add_c = -1.0F;
    } else {
      if (rtb_Add_c > 0.0F) {
        rtb_Add_c = 1.0F;
      }
    }

    /* End of Signum: '<S232>/Sign1' */

    /* Signum: '<S232>/Sign2' */
    if (rtb_DiscreteTimeIntegrator1_c < 0.0F) {
      rtb_DiscreteTimeIntegrator1_c = -1.0F;
    } else {
      if (rtb_DiscreteTimeIntegrator1_c > 0.0F) {
        rtb_DiscreteTimeIntegrator1_c = 1.0F;
      }
    }

    /* End of Signum: '<S232>/Sign2' */

    /* Sum: '<S232>/Add5' incorporates:
     *  Gain: '<S232>/Gain2'
     *  Product: '<S232>/Multiply4'
     *  Sum: '<S232>/Subtract2'
     */
    rtb_Saturation_j += (rtb_Add_c - rtb_DiscreteTimeIntegrator1_c) * 0.5F *
      rtb_Abs;

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
      CONTROL_PARAM.MC_VEL_XY_I * rtb_Switch_c_idx_0 * 0.002F;
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
      rtb_Saturation1_h_idx_0;

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
      CONTROL_PARAM.MC_VEL_XY_I * rtb_Switch_c_idx_1 * 0.002F;
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
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] += 0.002F * rtb_Saturation1;
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
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[0] += 0.002F * rtb_Multiply_b
      [0];

    /* Update for DiscreteIntegrator: '<S184>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S184>/Gain'
     *  Sum: '<S184>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] += (rtb_rate_err_B[1] -
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S188>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[1] += 0.002F * rtb_Multiply_b
      [1];

    /* Update for DiscreteIntegrator: '<S184>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S184>/Gain'
     *  Sum: '<S184>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] += (rtb_rate_err_B[2] -
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S188>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[2] += 0.002F * rtb_Multiply_b
      [2];
    Controller_DW.DiscreteTimeIntegrator1_PrevR_k = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Signum: '<S211>/Sign3' incorporates:
     *  Product: '<S211>/Divide'
     *  Sum: '<S211>/Add6'
     */
    rtb_Add_c = rtb_DiscreteTimeIntegrator_l__0 + Controller_ConstB.d;

    /* Signum: '<S211>/Sign4' incorporates:
     *  Product: '<S211>/Divide'
     *  Sum: '<S211>/Subtract3'
     */
    rtb_Saturation1_h_idx_0 = rtb_DiscreteTimeIntegrator_l__0 -
      Controller_ConstB.d;

    /* Signum: '<S211>/Sign5' incorporates:
     *  Product: '<S211>/Divide'
     */
    if (rtb_DiscreteTimeIntegrator_l__0 < 0.0F) {
      rtb_Saturation1 = -1.0F;
    } else if (rtb_DiscreteTimeIntegrator_l__0 > 0.0F) {
      rtb_Saturation1 = 1.0F;
    } else {
      rtb_Saturation1 = rtb_DiscreteTimeIntegrator_l__0;
    }

    /* Signum: '<S211>/Sign3' */
    if (rtb_Add_c < 0.0F) {
      rtb_Add_c = -1.0F;
    } else {
      if (rtb_Add_c > 0.0F) {
        rtb_Add_c = 1.0F;
      }
    }

    /* Signum: '<S211>/Sign4' */
    if (rtb_Saturation1_h_idx_0 < 0.0F) {
      rtb_Saturation1_h_idx_0 = -1.0F;
    } else {
      if (rtb_Saturation1_h_idx_0 > 0.0F) {
        rtb_Saturation1_h_idx_0 = 1.0F;
      }
    }

    /* Signum: '<S211>/Sign6' incorporates:
     *  Product: '<S211>/Divide'
     */
    if (rtb_DiscreteTimeIntegrator_l__0 < 0.0F) {
      rtb_DiscreteTimeIntegrator1_c = -1.0F;
    } else if (rtb_DiscreteTimeIntegrator_l__0 > 0.0F) {
      rtb_DiscreteTimeIntegrator1_c = 1.0F;
    } else {
      rtb_DiscreteTimeIntegrator1_c = rtb_DiscreteTimeIntegrator_l__0;
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
    Controller_DW.Integrator_DSTATE[0] += ((rtb_DiscreteTimeIntegrator_l__0 /
      Controller_ConstB.d - rtb_Saturation1) * Controller_ConstB.Gain4 *
      ((rtb_Add_c - rtb_Saturation1_h_idx_0) * 0.5F) -
      rtb_DiscreteTimeIntegrator1_c * 58.836F) * 0.002F;

    /* Signum: '<S211>/Sign3' incorporates:
     *  Sum: '<S211>/Add6'
     */
    rtb_Add_c = rtb_DiscreteTimeIntegrator_l_id + Controller_ConstB.d;

    /* Signum: '<S211>/Sign4' incorporates:
     *  Sum: '<S211>/Subtract3'
     */
    rtb_Saturation1_h_idx_0 = rtb_DiscreteTimeIntegrator_l_id -
      Controller_ConstB.d;

    /* Signum: '<S211>/Sign5' */
    if (rtb_DiscreteTimeIntegrator_l_id < 0.0F) {
      rtb_DiscreteTimeIntegrator_l__0 = -1.0F;
    } else if (rtb_DiscreteTimeIntegrator_l_id > 0.0F) {
      rtb_DiscreteTimeIntegrator_l__0 = 1.0F;
    } else {
      rtb_DiscreteTimeIntegrator_l__0 = rtb_DiscreteTimeIntegrator_l_id;
    }

    /* Signum: '<S211>/Sign3' */
    if (rtb_Add_c < 0.0F) {
      rtb_Add_c = -1.0F;
    } else {
      if (rtb_Add_c > 0.0F) {
        rtb_Add_c = 1.0F;
      }
    }

    /* Signum: '<S211>/Sign4' */
    if (rtb_Saturation1_h_idx_0 < 0.0F) {
      rtb_Saturation1_h_idx_0 = -1.0F;
    } else {
      if (rtb_Saturation1_h_idx_0 > 0.0F) {
        rtb_Saturation1_h_idx_0 = 1.0F;
      }
    }

    /* Signum: '<S211>/Sign6' */
    if (rtb_DiscreteTimeIntegrator_l_id < 0.0F) {
      rtb_Saturation1 = -1.0F;
    } else if (rtb_DiscreteTimeIntegrator_l_id > 0.0F) {
      rtb_Saturation1 = 1.0F;
    } else {
      rtb_Saturation1 = rtb_DiscreteTimeIntegrator_l_id;
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
    Controller_DW.Integrator_DSTATE[1] += ((rtb_DiscreteTimeIntegrator_l_id /
      Controller_ConstB.d - rtb_DiscreteTimeIntegrator_l__0) *
      Controller_ConstB.Gain4 * ((rtb_Add_c - rtb_Saturation1_h_idx_0) * 0.5F) -
      rtb_Saturation1 * 58.836F) * 0.002F;

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
      rtb_DiscreteTimeIntegrator_l__1 * 0.002F;
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
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_i += 0.002F * rtb_Divide_gn;
    Controller_DW.DiscreteTimeIntegrator1_Prev_ks = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Signum: '<S232>/Sign6' incorporates:
     *  Signum: '<S232>/Sign5'
     */
    if (rtb_Saturation_j < 0.0F) {
      rtb_DiscreteTimeIntegrator_l_id = -1.0F;

      /* Signum: '<S232>/Sign5' */
      rtb_DiscreteTimeIntegrator_l__0 = -1.0F;
    } else if (rtb_Saturation_j > 0.0F) {
      rtb_DiscreteTimeIntegrator_l_id = 1.0F;

      /* Signum: '<S232>/Sign5' */
      rtb_DiscreteTimeIntegrator_l__0 = 1.0F;
    } else {
      rtb_DiscreteTimeIntegrator_l_id = rtb_Saturation_j;

      /* Signum: '<S232>/Sign5' */
      rtb_DiscreteTimeIntegrator_l__0 = rtb_Saturation_j;
    }

    /* End of Signum: '<S232>/Sign6' */

    /* Sum: '<S232>/Add6' */
    rtb_Add_c = rtb_Saturation_j + Controller_ConstB.d_i;

    /* Sum: '<S232>/Subtract3' */
    rtb_Saturation1_h_idx_0 = rtb_Saturation_j - Controller_ConstB.d_i;

    /* Signum: '<S232>/Sign3' */
    if (rtb_Add_c < 0.0F) {
      rtb_Add_c = -1.0F;
    } else {
      if (rtb_Add_c > 0.0F) {
        rtb_Add_c = 1.0F;
      }
    }

    /* End of Signum: '<S232>/Sign3' */

    /* Signum: '<S232>/Sign4' */
    if (rtb_Saturation1_h_idx_0 < 0.0F) {
      rtb_Saturation1_h_idx_0 = -1.0F;
    } else {
      if (rtb_Saturation1_h_idx_0 > 0.0F) {
        rtb_Saturation1_h_idx_0 = 1.0F;
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
    Controller_DW.Integrator_DSTATE_j += ((rtb_Saturation_j /
      Controller_ConstB.d_i - rtb_DiscreteTimeIntegrator_l__0) *
      Controller_ConstB.Gain4_p * ((rtb_Add_c - rtb_Saturation1_h_idx_0) * 0.5F)
      - rtb_DiscreteTimeIntegrator_l_id * 78.448F) * 0.002F;

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
    int32_T i_p;
    uint16_T tmp_p[5];
    real32_T tmp_c;
    real32_T tmp_d;
    real32_T tmp_nk;
    uint16_T u0_p;
    real32_T tmp_a;

    /* MultiPortSwitch: '<S243>/Multiport Switch' incorporates:
     *  Constant: '<S243>/Disarm'
     *  Constant: '<S243>/Standby'
     *  Constant: '<S244>/Constant1'
     *  Constant: '<S244>/Constant12'
     *  Constant: '<S244>/Constant2'
     *  Constant: '<S244>/Constant7'
     *  Inport: '<Root>/FMS_Out'
     */
    switch (Controller_U.FMS_Out.status) {
     case 1:
      for (i_p = 0; i_p < 9; i_p++) {
        rtb_VariantMergeForOutportactua[i_p] =
          Controller_ConstP.Disarm_Value_c[i_p];
      }
      break;

     case 2:
      for (i_p = 0; i_p < 9; i_p++) {
        rtb_VariantMergeForOutportactua[i_p] =
          Controller_ConstP.Standby_Value[i_p];
      }
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

      /* DataTypeConversion: '<S247>/Data Type Conversion' incorporates:
       *  Constant: '<S247>/Constant1'
       *  Gain: '<S247>/Gain1'
       *  Sum: '<S247>/Sum1'
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
        tmp_a = fmodf(floorf(1000.0F * (Controller_ConstP.pooled4[i_p + 8] *
          tmp_nk + (Controller_ConstP.pooled4[i_p + 4] * tmp_d +
                    Controller_ConstP.pooled4[i_p] * tmp_c)) + (real32_T)
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
        rtb_VariantMergeForOutportactua[i_p] =
          Controller_ConstP.Disarm_Value_c[i_p];
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

    /* Saturate: '<S255>/Saturation' incorporates:
     *  Bias: '<S255>/Bias'
     *  Bias: '<S255>/Bias1'
     *  Bias: '<S255>/Bias2'
     *  Bias: '<S255>/Bias3'
     *  Constant: '<S255>/Constant'
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

    /* End of Saturate: '<S255>/Saturation' */

    /* MultiPortSwitch: '<S250>/Multiport Switch' incorporates:
     *  Constant: '<S251>/Constant1'
     *  Constant: '<S251>/Constant11'
     *  Constant: '<S251>/Constant12'
     *  Constant: '<S251>/Constant2'
     *  Constant: '<S251>/Constant7'
     *  Constant: '<S251>/Constant8'
     *  DataTypeConversion: '<S255>/Data Type Conversion'
     *  DataTypeConversion: '<S256>/Data Type Conversion'
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
        /* Saturate: '<S256>/Saturation' incorporates:
         *  Constant: '<S256>/Disarm'
         *  Reshape: '<S256>/Reshape'
         */
        if (Controller_ConstP.Disarm_Value_j[i_o] > 2000.0F) {
          tmp_gf = 2000.0F;
        } else if (Controller_ConstP.Disarm_Value_j[i_o] < 1000.0F) {
          tmp_gf = 1000.0F;
        } else {
          tmp_gf = Controller_ConstP.Disarm_Value_j[i_o];
        }

        rtb_VariantMergeForOutportactua[i_o] = (uint16_T)fmodf(floorf(tmp_gf),
          65536.0F);
      }

      /* Saturate: '<S256>/Saturation' incorporates:
       *  Bias: '<S256>/Bias'
       *  Constant: '<S256>/Constant'
       *  DataTypeConversion: '<S256>/Data Type Conversion'
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

      /* Saturate: '<S256>/Saturation' incorporates:
       *  Bias: '<S256>/Bias1'
       *  Constant: '<S256>/Constant'
       *  DataTypeConversion: '<S256>/Data Type Conversion'
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

      /* Saturate: '<S256>/Saturation' incorporates:
       *  Bias: '<S256>/Bias2'
       *  Constant: '<S256>/Constant'
       *  DataTypeConversion: '<S256>/Data Type Conversion'
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

      /* Saturate: '<S256>/Saturation' incorporates:
       *  Bias: '<S256>/Bias3'
       *  Constant: '<S256>/Constant'
       *  DataTypeConversion: '<S256>/Data Type Conversion'
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

      /* SignalConversion: '<S251>/ConcatBufferAtVector Concatenate2In2' incorporates:
       *  Constant: '<S251>/Constant10'
       *  Constant: '<S251>/Constant11'
       *  Constant: '<S251>/Constant12'
       */
      rtb_MatrixConcatenate_g[9] = 0.0F;

      /* SignalConversion: '<S251>/ConcatBufferAtVector Concatenate2In1' incorporates:
       *  Constant: '<S251>/Constant9'
       */
      rtb_MatrixConcatenate_g[8] = 0.0F;
      rtb_MatrixConcatenate_g[7] = -CONTROL_PARAM.FW_PITCH_EFFC *
        CONTROL_PARAM.FW_TAIL2_DIR;
      rtb_MatrixConcatenate_g[6] = CONTROL_PARAM.FW_PITCH_EFFC *
        CONTROL_PARAM.FW_TAIL1_DIR;

      /* SignalConversion: '<S251>/ConcatBufferAtVector Concatenate1In2' incorporates:
       *  Constant: '<S251>/Constant6'
       *  Constant: '<S251>/Constant7'
       *  Constant: '<S251>/Constant8'
       */
      rtb_MatrixConcatenate_g[5] = 0.0F;

      /* SignalConversion: '<S251>/ConcatBufferAtVector Concatenate1In1' incorporates:
       *  Constant: '<S251>/Constant5'
       */
      rtb_MatrixConcatenate_g[4] = 0.0F;

      /* SignalConversion: '<S251>/ConcatBufferAtVector ConcatenateIn4' incorporates:
       *  Constant: '<S251>/Constant4'
       */
      rtb_MatrixConcatenate_g[3] = 0.0F;

      /* SignalConversion: '<S251>/ConcatBufferAtVector ConcatenateIn3' incorporates:
       *  Constant: '<S251>/Constant3'
       */
      rtb_MatrixConcatenate_g[2] = 0.0F;
      rtb_MatrixConcatenate_g[1] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON2_DIR;
      rtb_MatrixConcatenate_g[0] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON1_DIR;

      /* Saturate: '<S248>/Saturation5' incorporates:
       *  Constant: '<S251>/Constant1'
       *  Constant: '<S251>/Constant2'
       */
      if (Controller_B.fw_torque_cmd[0] > 1.0F) {
        /* Product: '<S248>/Multiply1' */
        tmp_m = 1.0F;
      } else if (Controller_B.fw_torque_cmd[0] < -1.0F) {
        /* Product: '<S248>/Multiply1' */
        tmp_m = -1.0F;
      } else {
        /* Product: '<S248>/Multiply1' */
        tmp_m = Controller_B.fw_torque_cmd[0];
      }

      if (Controller_B.fw_torque_cmd[1] > 1.0F) {
        /* Product: '<S248>/Multiply1' */
        tmp_ev = 1.0F;
      } else if (Controller_B.fw_torque_cmd[1] < -1.0F) {
        /* Product: '<S248>/Multiply1' */
        tmp_ev = -1.0F;
      } else {
        /* Product: '<S248>/Multiply1' */
        tmp_ev = Controller_B.fw_torque_cmd[1];
      }

      if (Controller_B.fw_torque_cmd[2] > 1.0F) {
        /* Product: '<S248>/Multiply1' */
        tmp_k = 1.0F;
      } else if (Controller_B.fw_torque_cmd[2] < -1.0F) {
        /* Product: '<S248>/Multiply1' */
        tmp_k = -1.0F;
      } else {
        /* Product: '<S248>/Multiply1' */
        tmp_k = Controller_B.fw_torque_cmd[2];
      }

      /* End of Saturate: '<S248>/Saturation5' */
      for (i_o = 0; i_o < 4; i_o++) {
        /* Bias: '<S248>/Bias' incorporates:
         *  Gain: '<S248>/Gain1'
         *  Product: '<S248>/Multiply1'
         */
        rtb_Multiply_ka[i_o] = 500.0F * (rtb_MatrixConcatenate_g[i_o + 8] *
          tmp_k + (rtb_MatrixConcatenate_g[i_o + 4] * tmp_ev +
                   rtb_MatrixConcatenate_g[i_o] * tmp_m)) + 1500.0F;
      }

      /* Saturate: '<S249>/Saturation2' */
      if (Controller_B.mc_force_cmd[2] > 1.0F) {
        tmp_gf = 1.0F;
      } else if (Controller_B.mc_force_cmd[2] < 0.0F) {
        tmp_gf = 0.0F;
      } else {
        tmp_gf = Controller_B.mc_force_cmd[2];
      }

      /* End of Saturate: '<S249>/Saturation2' */

      /* DataTypeConversion: '<S254>/Data Type Conversion' incorporates:
       *  Constant: '<S254>/Constant1'
       *  Gain: '<S254>/Gain1'
       *  Sum: '<S254>/Sum1'
       */
      rtb_DataTypeConversion_o = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
        tmp_gf), 4.2949673E+9F) + 1000U);

      /* Saturate: '<S249>/Saturation1' */
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

      /* End of Saturate: '<S249>/Saturation1' */

      /* Saturate: '<S248>/Saturation4' */
      if (Controller_B.fw_force_cmd[0] > 1.0F) {
        tmp_gf = 1.0F;
      } else if (Controller_B.fw_force_cmd[0] < 0.0F) {
        tmp_gf = 0.0F;
      } else {
        tmp_gf = Controller_B.fw_force_cmd[0];
      }

      /* End of Saturate: '<S248>/Saturation4' */

      /* Saturate: '<S248>/Saturation1' incorporates:
       *  Constant: '<S253>/Constant1'
       *  DataTypeConversion: '<S253>/Data Type Conversion'
       *  Gain: '<S253>/Gain1'
       *  Sum: '<S253>/Sum1'
       */
      tmp_o[0] = (uint16_T)((uint32_T)fmodf(floorf(1000.0F * tmp_gf),
        4.2949673E+9F) + 1000U);

      /* DataTypeConversion: '<S248>/Data Type Conversion' incorporates:
       *  Bias: '<S248>/Bias1'
       */
      tmp_gf = fmodf(floorf(rtb_Multiply_ka[0] + CONTROL_PARAM.SERVO1_BIAS),
                     65536.0F);

      /* Saturate: '<S248>/Saturation1' incorporates:
       *  DataTypeConversion: '<S248>/Data Type Conversion'
       */
      tmp_o[1] = (uint16_T)(tmp_gf < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_gf : (int32_T)(uint16_T)tmp_gf);

      /* DataTypeConversion: '<S248>/Data Type Conversion1' incorporates:
       *  Bias: '<S248>/Bias2'
       */
      tmp_gf = fmodf(floorf(rtb_Multiply_ka[1] + CONTROL_PARAM.SERVO2_BIAS),
                     65536.0F);

      /* Saturate: '<S248>/Saturation1' incorporates:
       *  DataTypeConversion: '<S248>/Data Type Conversion1'
       */
      tmp_o[2] = (uint16_T)(tmp_gf < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_gf : (int32_T)(uint16_T)tmp_gf);

      /* DataTypeConversion: '<S248>/Data Type Conversion2' incorporates:
       *  Bias: '<S248>/Bias3'
       */
      tmp_gf = fmodf(floorf(rtb_Multiply_ka[2] + CONTROL_PARAM.SERVO3_BIAS),
                     65536.0F);

      /* Saturate: '<S248>/Saturation1' incorporates:
       *  DataTypeConversion: '<S248>/Data Type Conversion2'
       */
      tmp_o[3] = (uint16_T)(tmp_gf < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_gf : (int32_T)(uint16_T)tmp_gf);

      /* DataTypeConversion: '<S248>/Data Type Conversion3' incorporates:
       *  Bias: '<S248>/Bias4'
       */
      tmp_gf = fmodf(floorf(rtb_Multiply_ka[3] + CONTROL_PARAM.SERVO4_BIAS),
                     65536.0F);

      /* Saturate: '<S248>/Saturation1' incorporates:
       *  DataTypeConversion: '<S248>/Data Type Conversion3'
       */
      tmp_o[4] = (uint16_T)(tmp_gf < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_gf : (int32_T)(uint16_T)tmp_gf);

      /* Product: '<S249>/Multiply' */
      for (i_o = 0; i_o < 4; i_o++) {
        /* Saturate: '<S249>/Saturation' incorporates:
         *  Constant: '<S249>/Effective_Matrix'
         *  Gain: '<S249>/Gain'
         *  Sum: '<S249>/Add'
         */
        tmp_gf = fmodf(floorf(1000.0F * (Controller_ConstP.pooled4[i_o + 8] *
          tmp_k + (Controller_ConstP.pooled4[i_o + 4] * tmp_ev +
                   Controller_ConstP.pooled4[i_o] * tmp_m)) + (real32_T)
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

        /* End of Saturate: '<S249>/Saturation' */
      }

      /* End of Product: '<S249>/Multiply' */
      for (i_o = 0; i_o < 5; i_o++) {
        /* Saturate: '<S248>/Saturation1' */
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

    /* End of MultiPortSwitch: '<S250>/Multiport Switch' */
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
  /* Start for Constant: '<S108>/Constant' */
  Controller_B.Constant_m = CONTROL_PARAM.MC_VEL_Z_I_MIN;

  /* End of Start for SubSystem: '<S2>/FW_Controller' */

  /* Start for IfAction SubSystem: '<S2>/MC_Controller' */
  /* Start for Constant: '<S234>/Constant' */
  Controller_B.Constant = CONTROL_PARAM.MC_VEL_Z_I_MIN;

  /* End of Start for SubSystem: '<S2>/MC_Controller' */

  /* SystemInitialize for IfAction SubSystem: '<S2>/FW_Controller' */
  /* InitializeConditions for DiscreteIntegrator: '<S115>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_e = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S114>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_L_eo = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S113>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_o = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S85>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S85>/Discrete-Time Integrator' */

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

  /* InitializeConditions for DiscreteIntegrator: '<S83>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_b = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S87>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_h = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_l = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S105>/Integrator1' */
  Controller_DW.Integrator1_DSTATE_i = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S108>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S108>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S110>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_i = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_h = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S133>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S133>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S112>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_g = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S105>/Integrator' */
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
