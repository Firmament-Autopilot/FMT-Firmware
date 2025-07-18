/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.358
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Jul 17 15:44:51 2025
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
                                        *   '<S126>/Saturation'
                                        *   '<S127>/Gain'
                                        *   '<S127>/Gain1'
                                        *   '<S127>/balabnce_ratio2'
                                        *   '<S127>/balance_ratio'
                                        *   '<S127>/pitch_ff'
                                        *   '<S127>/thorttle_ff'
                                        *   '<S127>/ucmd2pitch'
                                        *   '<S127>/ucmd2thor'
                                        *   '<S127>/wcmd2pitch'
                                        *   '<S127>/wcmd2thor'
                                        *   '<S128>/cruise_throttle'
                                        *   '<S229>/hover_throttle'
                                        *   '<S102>/hover_throttle'
                                        *   '<S129>/FF'
                                        *   '<S129>/FF_limit'
                                        *   '<S129>/PI_limit'
                                        *   '<S148>/P_control'
                                        *   '<S149>/P_control'
                                        *   '<S206>/Saturation'
                                        *   '<S244>/Bias1'
                                        *   '<S244>/Bias2'
                                        *   '<S244>/Bias3'
                                        *   '<S244>/Bias4'
                                        *   '<S253>/Bias1'
                                        *   '<S253>/Bias2'
                                        *   '<S253>/Bias3'
                                        *   '<S253>/Bias4'
                                        *   '<S81>/Saturation'
                                        *   '<S81>/Saturation1'
                                        *   '<S133>/trim_speed'
                                        *   '<S134>/trim_speed'
                                        *   '<S157>/Gain'
                                        *   '<S158>/ '
                                        *   '<S158>/Gain3'
                                        *   '<S160>/Gain'
                                        *   '<S161>/ '
                                        *   '<S161>/Gain'
                                        *   '<S182>/Saturation'
                                        *   '<S182>/Saturation1'
                                        *   '<S215>/kd'
                                        *   '<S215>/Saturation'
                                        *   '<S216>/ki'
                                        *   '<S216>/Discrete-Time Integrator'
                                        *   '<S217>/kp'
                                        *   '<S236>/kd'
                                        *   '<S236>/Saturation'
                                        *   '<S237>/Constant'
                                        *   '<S237>/ki'
                                        *   '<S237>/Discrete-Time Integrator'
                                        *   '<S238>/kp'
                                        *   '<S247>/Constant1'
                                        *   '<S247>/Constant12'
                                        *   '<S247>/Constant2'
                                        *   '<S247>/Constant7'
                                        *   '<S251>/Bias'
                                        *   '<S251>/Bias1'
                                        *   '<S251>/Bias2'
                                        *   '<S251>/Bias3'
                                        *   '<S252>/Bias'
                                        *   '<S252>/Bias1'
                                        *   '<S252>/Bias2'
                                        *   '<S252>/Bias3'
                                        *   '<S256>/Constant1'
                                        *   '<S256>/Constant11'
                                        *   '<S256>/Constant12'
                                        *   '<S256>/Constant2'
                                        *   '<S256>/Constant7'
                                        *   '<S256>/Constant8'
                                        *   '<S260>/Bias'
                                        *   '<S260>/Bias1'
                                        *   '<S260>/Bias2'
                                        *   '<S260>/Bias3'
                                        *   '<S261>/Bias'
                                        *   '<S261>/Bias1'
                                        *   '<S261>/Bias2'
                                        *   '<S261>/Bias3'
                                        *   '<S93>/Constant1'
                                        *   '<S93>/Constant2'
                                        *   '<S109>/kd'
                                        *   '<S109>/Saturation'
                                        *   '<S110>/Constant'
                                        *   '<S110>/ki'
                                        *   '<S110>/Discrete-Time Integrator'
                                        *   '<S111>/kp'
                                        *   '<S135>/gain1'
                                        *   '<S135>/gain2'
                                        *   '<S135>/gain3'
                                        *   '<S135>/Discrete-Time Integrator'
                                        *   '<S136>/gain1'
                                        *   '<S136>/gain2'
                                        *   '<S136>/gain3'
                                        *   '<S140>/Pitch Offset'
                                        *   '<S140>/Saturation'
                                        *   '<S141>/Constant1'
                                        *   '<S141>/Constant2'
                                        *   '<S199>/Constant1'
                                        *   '<S199>/Constant2'
                                        *   '<S86>/gain1'
                                        *   '<S86>/gain2'
                                        *   '<S86>/gain3'
                                        *   '<S86>/Saturation'
                                        *   '<S87>/gain1'
                                        *   '<S87>/gain2'
                                        *   '<S87>/gain3'
                                        *   '<S87>/Discrete-Time Integrator'
                                        *   '<S88>/gain1'
                                        *   '<S88>/gain2'
                                        *   '<S88>/gain3'
                                        *   '<S188>/gain1'
                                        *   '<S188>/gain2'
                                        *   '<S188>/gain3'
                                        *   '<S188>/Saturation'
                                        *   '<S189>/gain1'
                                        *   '<S189>/gain2'
                                        *   '<S189>/gain3'
                                        *   '<S189>/Discrete-Time Integrator'
                                        *   '<S190>/gain1'
                                        *   '<S190>/gain2'
                                        *   '<S190>/gain3'
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
  real32_T rtb_Sum_l;
  real32_T rtb_MatrixConcatenate1_b[9];
  real32_T rtb_DiscreteTimeIntegrator1_k1[3];
  real32_T rtb_Multiply_kn[3];
  int32_T rtb_Relay;
  boolean_T rtb_LogicalOperator_i;
  boolean_T rtb_Compare_nq;
  real32_T rtb_Abs;
  real32_T rtb_Multiply1_e;
  real32_T rtb_Saturation1_ih;
  real32_T rtb_VdotPg;
  real32_T rtb_Cos;
  real32_T rtb_Gain_c4;
  real32_T rtb_Add3_fc;
  boolean_T rtb_LogicalOperator_g;
  real32_T rtb_phi_cmd;
  real32_T rtb_Saturation_ph;
  real32_T rtb_Saturation_c;
  real32_T rtb_Add_k;
  real32_T rtb_MatrixConcatenate1_p[3];
  real32_T rtb_TmpSignalConversionAtMult_0;
  real32_T rtb_TmpSignalConversionAtMult_1;
  real32_T rtb_TmpSignalConversionAtMult_2;
  real32_T rtb_Switch_e_idx_0;
  real32_T rtb_Switch_e_idx_1;
  real32_T rtb_Divide_i_idx_0;
  real32_T rtb_Divide_i_idx_1;
  real32_T rtb_Divide_i_idx_2;
  real32_T rtb_Divide_i_idx_3;
  real32_T rtb_Divide_m_idx_3;
  real32_T rtb_MatrixConcatenate1_p_tmp;
  real32_T rtb_Integrator1_o_tmp;

  /* S-Function (sfix_bitop): '<S8>/Bitwise AND' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  rtb_BitwiseAND_n = (uint8_T)(Controller_U.FMS_Out.ctrl_mode & 63);

  /* SwitchCase: '<S9>/Switch Case1' incorporates:
   *  Constant: '<S110>/Constant'
   *  Constant: '<S237>/Constant'
   *  DataTypeConversion: '<S9>/Data Type Conversion'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S188>/Multiply'
   *  Product: '<S201>/Divide1'
   *  Product: '<S215>/Multiply'
   *  Product: '<S95>/Divide1'
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
       *  DiscreteIntegrator: '<S107>/Integrator'
       *  DiscreteIntegrator: '<S107>/Integrator1'
       *  DiscreteIntegrator: '<S110>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S112>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S113>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S114>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S115>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S117>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S135>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S158>/ '
       *  DiscreteIntegrator: '<S159>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S161>/ '
       *  DiscreteIntegrator: '<S162>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S85>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S87>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S89>/Discrete-Time Integrator1'
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
     *  ActionPort: '<S5>/Action Port'
     */
    /* Sqrt: '<S170>/Sqrt' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Math: '<S170>/Square'
     *  Sqrt: '<S124>/Sqrt'
     *  Sum: '<S170>/Sum of Elements'
     *  Switch: '<S116>/Switch'
     */
    rtb_Divide_m_idx_3 = sqrtf(((Controller_U.INS_Out.quat[0] *
      Controller_U.INS_Out.quat[0] + Controller_U.INS_Out.quat[1] *
      Controller_U.INS_Out.quat[1]) + Controller_U.INS_Out.quat[2] *
      Controller_U.INS_Out.quat[2]) + Controller_U.INS_Out.quat[3] *
      Controller_U.INS_Out.quat[3]);

    /* Product: '<S166>/Divide' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Sqrt: '<S170>/Sqrt'
     */
    rtb_Divide_i_idx_0 = Controller_U.INS_Out.quat[0] / rtb_Divide_m_idx_3;
    rtb_Divide_i_idx_1 = Controller_U.INS_Out.quat[1] / rtb_Divide_m_idx_3;
    rtb_Divide_i_idx_2 = Controller_U.INS_Out.quat[2] / rtb_Divide_m_idx_3;
    rtb_Divide_i_idx_3 = Controller_U.INS_Out.quat[3] / rtb_Divide_m_idx_3;

    /* SignalConversion: '<S118>/TmpSignal ConversionAtMultiplyInport2' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_TmpSignalConversionAtMult_0 = Controller_U.INS_Out.vn;
    rtb_TmpSignalConversionAtMult_1 = Controller_U.INS_Out.ve;
    rtb_TmpSignalConversionAtMult_2 = Controller_U.INS_Out.vd;

    /* Trigonometry: '<S155>/Trigonometric Function1' incorporates:
     *  Gain: '<S154>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S155>/Trigonometric Function3'
     */
    rtb_Gain_c4 = arm_cos_f32(-Controller_U.INS_Out.psi);
    rtb_MatrixConcatenate1_b[0] = rtb_Gain_c4;

    /* Trigonometry: '<S155>/Trigonometric Function' incorporates:
     *  Gain: '<S154>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S155>/Trigonometric Function2'
     */
    rtb_Switch_e_idx_1 = arm_sin_f32(-Controller_U.INS_Out.psi);
    rtb_MatrixConcatenate1_b[1] = rtb_Switch_e_idx_1;

    /* SignalConversion: '<S155>/ConcatBufferAtVector Concatenate1In3' incorporates:
     *  Constant: '<S155>/Constant3'
     */
    rtb_MatrixConcatenate1_b[2] = 0.0F;

    /* Gain: '<S155>/Gain' */
    rtb_MatrixConcatenate1_b[3] = -rtb_Switch_e_idx_1;

    /* Trigonometry: '<S155>/Trigonometric Function3' */
    rtb_MatrixConcatenate1_b[4] = rtb_Gain_c4;

    /* SignalConversion: '<S155>/ConcatBufferAtVector Concatenate2In3' incorporates:
     *  Constant: '<S155>/Constant4'
     */
    rtb_MatrixConcatenate1_b[5] = 0.0F;

    /* SignalConversion: '<S155>/ConcatBufferAtVector ConcatenateIn3' */
    rtb_MatrixConcatenate1_b[6] = Controller_ConstB.VectorConcatenate3_g[0];
    rtb_MatrixConcatenate1_b[7] = Controller_ConstB.VectorConcatenate3_g[1];
    rtb_MatrixConcatenate1_b[8] = Controller_ConstB.VectorConcatenate3_g[2];

    /* Product: '<S152>/Multiply' */
    for (rtb_Relay = 0; rtb_Relay < 3; rtb_Relay++) {
      rtb_DiscreteTimeIntegrator1_k1[rtb_Relay] =
        rtb_MatrixConcatenate1_b[rtb_Relay + 6] *
        rtb_TmpSignalConversionAtMult_2 + (rtb_MatrixConcatenate1_b[rtb_Relay +
        3] * rtb_TmpSignalConversionAtMult_1 +
        rtb_MatrixConcatenate1_b[rtb_Relay] * rtb_TmpSignalConversionAtMult_0);
    }

    /* End of Product: '<S152>/Multiply' */

    /* Math: '<S167>/Square' incorporates:
     *  Math: '<S168>/Square'
     *  Math: '<S169>/Square'
     */
    rtb_Gain_c4 = rtb_Divide_i_idx_0 * rtb_Divide_i_idx_0;

    /* Math: '<S167>/Square2' incorporates:
     *  Math: '<S168>/Square2'
     *  Math: '<S169>/Square2'
     */
    rtb_Switch_e_idx_1 = rtb_Divide_i_idx_2 * rtb_Divide_i_idx_2;

    /* Math: '<S167>/Square1' incorporates:
     *  Math: '<S168>/Square1'
     *  Math: '<S169>/Square1'
     */
    rtb_Add3_fc = rtb_Divide_i_idx_1 * rtb_Divide_i_idx_1;

    /* Math: '<S167>/Square3' incorporates:
     *  Math: '<S168>/Square3'
     *  Math: '<S169>/Square3'
     */
    rtb_Switch_e_idx_0 = rtb_Divide_i_idx_3 * rtb_Divide_i_idx_3;

    /* Sum: '<S167>/Subtract' incorporates:
     *  Math: '<S167>/Square'
     *  Math: '<S167>/Square1'
     *  Math: '<S167>/Square2'
     *  Math: '<S167>/Square3'
     *  Sum: '<S167>/Add'
     *  Sum: '<S167>/Add1'
     */
    rtb_MatrixConcatenate1_b[0] = (rtb_Gain_c4 + rtb_Add3_fc) -
      (rtb_Switch_e_idx_1 + rtb_Switch_e_idx_0);

    /* Product: '<S167>/Multiply' incorporates:
     *  Product: '<S168>/Multiply'
     */
    rtb_Saturation_c = rtb_Divide_i_idx_1 * rtb_Divide_i_idx_2;

    /* Product: '<S167>/Multiply1' incorporates:
     *  Product: '<S168>/Multiply1'
     */
    rtb_phi_cmd = rtb_Divide_i_idx_0 * rtb_Divide_i_idx_3;

    /* Gain: '<S167>/Gain' incorporates:
     *  Product: '<S167>/Multiply'
     *  Product: '<S167>/Multiply1'
     *  Sum: '<S167>/Subtract1'
     */
    rtb_MatrixConcatenate1_b[1] = (rtb_Saturation_c - rtb_phi_cmd) * 2.0F;

    /* Product: '<S167>/Multiply2' incorporates:
     *  Product: '<S169>/Multiply'
     */
    rtb_Multiply1_e = rtb_Divide_i_idx_1 * rtb_Divide_i_idx_3;

    /* Product: '<S167>/Multiply3' incorporates:
     *  Product: '<S169>/Multiply1'
     */
    rtb_MatrixConcatenate1_p_tmp = rtb_Divide_i_idx_0 * rtb_Divide_i_idx_2;

    /* Gain: '<S167>/Gain1' incorporates:
     *  Product: '<S167>/Multiply2'
     *  Product: '<S167>/Multiply3'
     *  Sum: '<S167>/Add2'
     */
    rtb_MatrixConcatenate1_b[2] = (rtb_Multiply1_e +
      rtb_MatrixConcatenate1_p_tmp) * 2.0F;

    /* Gain: '<S168>/Gain' incorporates:
     *  Sum: '<S168>/Add3'
     */
    rtb_MatrixConcatenate1_b[3] = (rtb_Saturation_c + rtb_phi_cmd) * 2.0F;

    /* Sum: '<S168>/Subtract' incorporates:
     *  Sum: '<S168>/Add'
     *  Sum: '<S168>/Add1'
     */
    rtb_MatrixConcatenate1_b[4] = (rtb_Gain_c4 + rtb_Switch_e_idx_1) -
      (rtb_Add3_fc + rtb_Switch_e_idx_0);

    /* Product: '<S168>/Multiply2' incorporates:
     *  Product: '<S169>/Multiply2'
     */
    rtb_Saturation_c = rtb_Divide_i_idx_2 * rtb_Divide_i_idx_3;

    /* Product: '<S168>/Multiply3' incorporates:
     *  Product: '<S169>/Multiply3'
     */
    rtb_phi_cmd = rtb_Divide_i_idx_0 * rtb_Divide_i_idx_1;

    /* Gain: '<S168>/Gain1' incorporates:
     *  Product: '<S168>/Multiply2'
     *  Product: '<S168>/Multiply3'
     *  Sum: '<S168>/Subtract1'
     */
    rtb_MatrixConcatenate1_b[5] = (rtb_Saturation_c - rtb_phi_cmd) * 2.0F;

    /* Gain: '<S169>/Gain' incorporates:
     *  Sum: '<S169>/Subtract2'
     */
    rtb_MatrixConcatenate1_b[6] = (rtb_Multiply1_e -
      rtb_MatrixConcatenate1_p_tmp) * 2.0F;

    /* Gain: '<S169>/Gain1' incorporates:
     *  Sum: '<S169>/Add2'
     */
    rtb_MatrixConcatenate1_b[7] = (rtb_Saturation_c + rtb_phi_cmd) * 2.0F;

    /* Sum: '<S169>/Subtract' incorporates:
     *  Sum: '<S169>/Add'
     *  Sum: '<S169>/Add1'
     */
    rtb_MatrixConcatenate1_b[8] = (rtb_Gain_c4 + rtb_Switch_e_idx_0) -
      (rtb_Add3_fc + rtb_Switch_e_idx_1);

    /* Product: '<S163>/Multiply' */
    for (rtb_Relay = 0; rtb_Relay < 3; rtb_Relay++) {
      rtb_Multiply_kn[rtb_Relay] = rtb_MatrixConcatenate1_b[rtb_Relay + 6] *
        rtb_TmpSignalConversionAtMult_2 + (rtb_MatrixConcatenate1_b[rtb_Relay +
        3] * rtb_TmpSignalConversionAtMult_1 +
        rtb_MatrixConcatenate1_b[rtb_Relay] * rtb_TmpSignalConversionAtMult_0);
    }

    /* End of Product: '<S163>/Multiply' */

    /* Switch: '<S116>/Switch' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Math: '<S116>/Square2'
     *  Math: '<S116>/Square3'
     *  Product: '<S116>/Multiply'
     *  S-Function (sfix_bitop): '<S116>/Bitwise AND'
     *  Sqrt: '<S116>/Sqrt'
     *  Sum: '<S116>/Add'
     */
    if ((Controller_U.INS_Out.flag & 512U) > 0U) {
      rtb_Divide_i_idx_0 = Controller_U.INS_Out.airspeed;
    } else {
      /* Product: '<S120>/Divide' */
      rtb_Divide_i_idx_0 = Controller_U.INS_Out.quat[0] / rtb_Divide_m_idx_3;
      rtb_Divide_i_idx_1 = Controller_U.INS_Out.quat[1] / rtb_Divide_m_idx_3;
      rtb_Divide_i_idx_2 = Controller_U.INS_Out.quat[2] / rtb_Divide_m_idx_3;
      rtb_Divide_m_idx_3 = Controller_U.INS_Out.quat[3] / rtb_Divide_m_idx_3;

      /* Sum: '<S123>/Subtract' incorporates:
       *  Math: '<S123>/Square'
       *  Math: '<S123>/Square1'
       *  Math: '<S123>/Square2'
       *  Math: '<S123>/Square3'
       *  Sum: '<S123>/Add'
       *  Sum: '<S123>/Add1'
       */
      rtb_MatrixConcatenate1_b[8] = (rtb_Divide_i_idx_0 * rtb_Divide_i_idx_0 +
        rtb_Divide_m_idx_3 * rtb_Divide_m_idx_3) - (rtb_Divide_i_idx_1 *
        rtb_Divide_i_idx_1 + rtb_Divide_i_idx_2 * rtb_Divide_i_idx_2);

      /* Gain: '<S123>/Gain1' incorporates:
       *  Product: '<S123>/Multiply2'
       *  Product: '<S123>/Multiply3'
       *  Sum: '<S123>/Add2'
       */
      rtb_MatrixConcatenate1_b[7] = (rtb_Divide_i_idx_2 * rtb_Divide_m_idx_3 +
        rtb_Divide_i_idx_0 * rtb_Divide_i_idx_1) * 2.0F;

      /* Gain: '<S123>/Gain' incorporates:
       *  Product: '<S123>/Multiply'
       *  Product: '<S123>/Multiply1'
       *  Sum: '<S123>/Subtract2'
       */
      rtb_MatrixConcatenate1_b[6] = (rtb_Divide_i_idx_1 * rtb_Divide_m_idx_3 -
        rtb_Divide_i_idx_0 * rtb_Divide_i_idx_2) * 2.0F;

      /* Gain: '<S122>/Gain1' incorporates:
       *  Product: '<S122>/Multiply2'
       *  Product: '<S122>/Multiply3'
       *  Sum: '<S122>/Subtract1'
       */
      rtb_MatrixConcatenate1_b[5] = (rtb_Divide_i_idx_2 * rtb_Divide_m_idx_3 -
        rtb_Divide_i_idx_0 * rtb_Divide_i_idx_1) * 2.0F;

      /* Sum: '<S122>/Subtract' incorporates:
       *  Math: '<S122>/Square'
       *  Math: '<S122>/Square1'
       *  Math: '<S122>/Square2'
       *  Math: '<S122>/Square3'
       *  Sum: '<S122>/Add'
       *  Sum: '<S122>/Add1'
       */
      rtb_MatrixConcatenate1_b[4] = (rtb_Divide_i_idx_0 * rtb_Divide_i_idx_0 +
        rtb_Divide_i_idx_2 * rtb_Divide_i_idx_2) - (rtb_Divide_i_idx_1 *
        rtb_Divide_i_idx_1 + rtb_Divide_m_idx_3 * rtb_Divide_m_idx_3);

      /* Gain: '<S122>/Gain' incorporates:
       *  Product: '<S122>/Multiply'
       *  Product: '<S122>/Multiply1'
       *  Sum: '<S122>/Add3'
       */
      rtb_MatrixConcatenate1_b[3] = (rtb_Divide_i_idx_1 * rtb_Divide_i_idx_2 +
        rtb_Divide_i_idx_0 * rtb_Divide_m_idx_3) * 2.0F;

      /* Gain: '<S121>/Gain1' incorporates:
       *  Product: '<S121>/Multiply2'
       *  Product: '<S121>/Multiply3'
       *  Sum: '<S121>/Add2'
       */
      rtb_MatrixConcatenate1_b[2] = (rtb_Divide_i_idx_1 * rtb_Divide_m_idx_3 +
        rtb_Divide_i_idx_0 * rtb_Divide_i_idx_2) * 2.0F;

      /* Gain: '<S121>/Gain' incorporates:
       *  Product: '<S121>/Multiply'
       *  Product: '<S121>/Multiply1'
       *  Sum: '<S121>/Subtract1'
       */
      rtb_MatrixConcatenate1_b[1] = (rtb_Divide_i_idx_1 * rtb_Divide_i_idx_2 -
        rtb_Divide_i_idx_0 * rtb_Divide_m_idx_3) * 2.0F;

      /* Sum: '<S121>/Subtract' incorporates:
       *  Math: '<S121>/Square'
       *  Math: '<S121>/Square1'
       *  Math: '<S121>/Square2'
       *  Math: '<S121>/Square3'
       *  Sum: '<S121>/Add'
       *  Sum: '<S121>/Add1'
       */
      rtb_MatrixConcatenate1_b[0] = (rtb_Divide_i_idx_0 * rtb_Divide_i_idx_0 +
        rtb_Divide_i_idx_1 * rtb_Divide_i_idx_1) - (rtb_Divide_i_idx_2 *
        rtb_Divide_i_idx_2 + rtb_Divide_m_idx_3 * rtb_Divide_m_idx_3);

      /* Product: '<S118>/Multiply' */
      for (rtb_Relay = 0; rtb_Relay < 3; rtb_Relay++) {
        rtb_MatrixConcatenate1_p[rtb_Relay] = rtb_MatrixConcatenate1_b[rtb_Relay
          + 6] * rtb_TmpSignalConversionAtMult_2 +
          (rtb_MatrixConcatenate1_b[rtb_Relay + 3] *
           rtb_TmpSignalConversionAtMult_1 + rtb_MatrixConcatenate1_b[rtb_Relay]
           * rtb_TmpSignalConversionAtMult_0);
      }

      /* End of Product: '<S118>/Multiply' */

      /* Signum: '<S118>/Sign' */
      if (rtb_MatrixConcatenate1_p[0] < 0.0F) {
        rtb_TmpSignalConversionAtMult_0 = -1.0F;
      } else if (rtb_MatrixConcatenate1_p[0] > 0.0F) {
        rtb_TmpSignalConversionAtMult_0 = 1.0F;
      } else {
        rtb_TmpSignalConversionAtMult_0 = rtb_MatrixConcatenate1_p[0];
      }

      /* End of Signum: '<S118>/Sign' */
      rtb_Divide_i_idx_0 = sqrtf(Controller_U.INS_Out.vn *
        Controller_U.INS_Out.vn + Controller_U.INS_Out.ve *
        Controller_U.INS_Out.ve) * rtb_TmpSignalConversionAtMult_0;
    }

    /* Saturate: '<S116>/Saturation1' */
    if (rtb_Divide_i_idx_0 > 100.0F) {
      rtb_Divide_i_idx_0 = 100.0F;
    } else {
      if (rtb_Divide_i_idx_0 < 0.1F) {
        rtb_Divide_i_idx_0 = 0.1F;
      }
    }

    /* End of Saturate: '<S116>/Saturation1' */

    /* DiscreteIntegrator: '<S117>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_e != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j = rtb_Divide_i_idx_0;
    }

    /* Math: '<S71>/Square' incorporates:
     *  DiscreteIntegrator: '<S117>/Discrete-Time Integrator5'
     *  Math: '<S133>/Square1'
     *  Switch: '<S73>/Switch'
     */
    rtb_Saturation_c = Controller_DW.DiscreteTimeIntegrator5_DSTAT_j *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;

    /* Product: '<S71>/Divide' incorporates:
     *  Math: '<S71>/Square'
     */
    rtb_Divide_i_idx_1 = rtb_Saturation_c / Controller_ConstB.Square1;

    /* DiscreteIntegrator: '<S115>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_L_eo != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_a = rtb_Divide_i_idx_1;
    }

    /* Saturate: '<S71>/Saturation' */
    if (Controller_DW.DiscreteTimeIntegrator5_DSTAT_a > 1.0F) {
      rtb_Divide_i_idx_2 = 1.0F;
    } else if (Controller_DW.DiscreteTimeIntegrator5_DSTAT_a < 0.0F) {
      rtb_Divide_i_idx_2 = 0.0F;
    } else {
      rtb_Divide_i_idx_2 = Controller_DW.DiscreteTimeIntegrator5_DSTAT_a;
    }

    /* End of Saturate: '<S71>/Saturation' */

    /* Relay: '<S71>/Relay' */
    if (rtb_Divide_i_idx_2 >= 0.95F) {
      Controller_DW.Relay_Mode = true;
    } else {
      if (rtb_Divide_i_idx_2 <= 0.85F) {
        Controller_DW.Relay_Mode = false;
      }
    }

    rtb_Relay = !Controller_DW.Relay_Mode;

    /* End of Relay: '<S71>/Relay' */

    /* DiscreteIntegrator: '<S114>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_o != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTA_a2 = (real32_T)rtb_Relay;
    }

    /* Logic: '<S77>/Logical Operator' incorporates:
     *  Constant: '<S79>/Constant'
     *  DiscreteIntegrator: '<S114>/Discrete-Time Integrator5'
     *  RelationalOperator: '<S79>/Compare'
     */
    rtb_LogicalOperator_i = ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator5_DSTA_a2 == 0.0F));

    /* DiscreteIntegrator: '<S87>/Discrete-Time Integrator' */
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

    /* Trigonometry: '<S126>/Atan' incorporates:
     *  Gain: '<S126>/g_force'
     */
    rtb_Sum_l = atanf(0.101936802F * Controller_U.FMS_Out.ay_cmd);

    /* Saturate: '<S126>/Saturation' */
    if (rtb_Sum_l > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Sum_l = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_Sum_l < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_Sum_l = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      }
    }

    /* End of Saturate: '<S126>/Saturation' */

    /* Switch: '<S139>/Switch' incorporates:
     *  Logic: '<S139>/Logical Operator'
     *  RelationalOperator: '<S144>/Compare'
     */
    if ((rtb_BitwiseAND_n == 3) || (rtb_BitwiseAND_n == 4)) {
      rtb_phi_cmd = Controller_U.FMS_Out.phi_cmd;
    } else {
      rtb_phi_cmd = rtb_Sum_l;
    }

    /* End of Switch: '<S139>/Switch' */

    /* Switch: '<S147>/Switch' incorporates:
     *  Constant: '<S156>/Constant'
     *  RelationalOperator: '<S156>/Compare'
     */
    if (rtb_BitwiseAND_n == 4) {
      rtb_Sum_l = Controller_U.FMS_Out.phi_cmd;
    }

    /* End of Switch: '<S147>/Switch' */

    /* Abs: '<S127>/Abs' */
    rtb_Abs = fabsf(rtb_Sum_l);

    /* DeadZone: '<S152>/Dead Zone' */
    if (rtb_DiscreteTimeIntegrator1_k1[0] > 1.0F) {
      rtb_Sum_l = rtb_DiscreteTimeIntegrator1_k1[0] - 1.0F;
    } else if (rtb_DiscreteTimeIntegrator1_k1[0] >= -1.0F) {
      rtb_Sum_l = 0.0F;
    } else {
      rtb_Sum_l = rtb_DiscreteTimeIntegrator1_k1[0] - -1.0F;
    }

    /* End of DeadZone: '<S152>/Dead Zone' */

    /* Signum: '<S152>/Sign' */
    if (rtb_Sum_l < 0.0F) {
      rtb_Sum_l = -1.0F;
    } else {
      if (rtb_Sum_l > 0.0F) {
        rtb_Sum_l = 1.0F;
      }
    }

    /* End of Signum: '<S152>/Sign' */

    /* Switch: '<S151>/Switch' incorporates:
     *  Gain: '<S151>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S151>/Divide'
     *  S-Function (sfix_bitop): '<S151>/Bitwise AND'
     *  Trigonometry: '<S151>/Asin'
     */
    if ((Controller_U.INS_Out.flag & 16U) > 1U) {
      /* Sqrt: '<S151>/Sqrt' incorporates:
       *  Math: '<S151>/Square'
       *  Math: '<S151>/Square1'
       *  Sum: '<S151>/Add'
       */
      rtb_Add3_fc = sqrtf(Controller_U.INS_Out.vn * Controller_U.INS_Out.vn +
                          Controller_U.INS_Out.ve * Controller_U.INS_Out.ve);

      /* Saturate: '<S151>/Saturation' incorporates:
       *  Sqrt: '<S151>/Sqrt'
       */
      if (rtb_Add3_fc > 100.0F) {
        rtb_Add3_fc = 100.0F;
      } else {
        if (rtb_Add3_fc < 8.0F) {
          rtb_Add3_fc = 8.0F;
        }
      }

      /* End of Saturate: '<S151>/Saturation' */

      /* DeadZone: '<S151>/Dead Zone' */
      if (Controller_U.INS_Out.vd > 0.1F) {
        rtb_Saturation_ph = Controller_U.INS_Out.vd - 0.1F;
      } else if (Controller_U.INS_Out.vd >= -0.1F) {
        rtb_Saturation_ph = 0.0F;
      } else {
        rtb_Saturation_ph = Controller_U.INS_Out.vd - -0.1F;
      }

      /* End of DeadZone: '<S151>/Dead Zone' */
      rtb_Multiply1_e = atanf(1.0F / rtb_Add3_fc * -rtb_Saturation_ph);
    } else {
      rtb_Multiply1_e = Controller_U.INS_Out.theta;
    }

    /* End of Switch: '<S151>/Switch' */

    /* Product: '<S151>/Multiply1' */
    rtb_Multiply1_e *= rtb_Sum_l;

    /* Saturate: '<S151>/Saturation1' */
    if (rtb_Multiply1_e > 0.785398185F) {
      rtb_Saturation1_ih = 0.785398185F;
    } else if (rtb_Multiply1_e < -0.785398185F) {
      rtb_Saturation1_ih = -0.785398185F;
    } else {
      rtb_Saturation1_ih = rtb_Multiply1_e;
    }

    /* End of Saturate: '<S151>/Saturation1' */

    /* Gain: '<S150>/Gain1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_VdotPg = 0.101936802F * Controller_U.INS_Out.ax;

    /* Sqrt: '<S153>/Sqrt' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Math: '<S153>/Square'
     *  Math: '<S153>/Square1'
     *  Sum: '<S153>/Add'
     */
    rtb_Add3_fc = sqrtf(Controller_U.INS_Out.vn * Controller_U.INS_Out.vn +
                        Controller_U.INS_Out.ve * Controller_U.INS_Out.ve);

    /* Saturate: '<S153>/Saturation1' incorporates:
     *  Sqrt: '<S153>/Sqrt'
     */
    if (rtb_Add3_fc > 100.0F) {
      rtb_Add3_fc = 100.0F;
    } else {
      if (rtb_Add3_fc < 8.0F) {
        rtb_Add3_fc = 8.0F;
      }
    }

    /* End of Saturate: '<S153>/Saturation1' */

    /* Product: '<S153>/Multiply1' incorporates:
     *  Gain: '<S153>/Gain'
     *  Product: '<S153>/Divide'
     *  Trigonometry: '<S153>/Asin'
     */
    rtb_Sum_l *= atanf(-Controller_U.FMS_Out.w_cmd / rtb_Add3_fc);

    /* Saturate: '<S153>/Saturation2' */
    if (rtb_Sum_l > 0.785398185F) {
      rtb_Sum_l = 0.785398185F;
    } else {
      if (rtb_Sum_l < -0.785398185F) {
        rtb_Sum_l = -0.785398185F;
      }
    }

    /* End of Saturate: '<S153>/Saturation2' */

    /* Sum: '<S146>/Sum' */
    rtb_Sum_l -= rtb_Saturation1_ih;

    /* Switch: '<S163>/Switch' incorporates:
     *  Constant: '<S164>/Constant'
     *  DiscreteIntegrator: '<S117>/Discrete-Time Integrator5'
     *  RelationalOperator: '<S164>/Compare'
     */
    if (rtb_Multiply_kn[0] >= 3.0F) {
      rtb_Saturation_ph = Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;
    } else {
      rtb_Saturation_ph = rtb_Multiply_kn[0];
    }

    /* End of Switch: '<S163>/Switch' */

    /* Sum: '<S150>/Sum' incorporates:
     *  Gain: '<S150>/Gain'
     *  Sum: '<S150>/Minus'
     */
    rtb_Cos = (Controller_U.FMS_Out.u_cmd - rtb_Saturation_ph) * 0.101936802F -
      rtb_VdotPg;

    /* Sum: '<S127>/Minus1' incorporates:
     *  Gain: '<S127>/ucmd2pitch'
     *  Gain: '<S127>/wcmd2pitch'
     */
    rtb_Divide_i_idx_3 = CONTROL_PARAM.FW_TECS_W2P * rtb_Sum_l -
      CONTROL_PARAM.FW_TECS_U2P * rtb_Cos;

    /* DiscreteIntegrator: '<S158>/ ' */
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

    /* DiscreteIntegrator: '<S159>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_f != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_e = rtb_Divide_i_idx_3;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_b != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_e = rtb_Divide_i_idx_3;
    }

    /* Gain: '<S159>/Gain' incorporates:
     *  DiscreteIntegrator: '<S159>/Discrete-Time Integrator1'
     *  Sum: '<S159>/Sum5'
     */
    rtb_Gain_c4 = (rtb_Divide_i_idx_3 -
                   Controller_DW.DiscreteTimeIntegrator1_DSTAT_e) * 62.831852F;

    /* Switch: '<S139>/Switch1' incorporates:
     *  Constant: '<S145>/Constant'
     *  DiscreteIntegrator: '<S158>/ '
     *  Gain: '<S127>/Gain'
     *  Gain: '<S127>/balabnce_ratio2'
     *  Gain: '<S127>/balance_ratio'
     *  Gain: '<S127>/pitch_ff'
     *  Gain: '<S148>/P_control'
     *  RelationalOperator: '<S145>/Compare'
     *  Sum: '<S127>/Add3'
     *  Sum: '<S127>/Minus'
     *  Sum: '<S127>/Sum'
     *  Sum: '<S148>/Add'
     *  Switch: '<S159>/Switch'
     */
    if (rtb_BitwiseAND_n == 3) {
      rtb_Multiply1_e = Controller_U.FMS_Out.theta_cmd;
    } else {
      if (Controller_U.FMS_Out.reset > 0) {
        /* Switch: '<S159>/Switch' incorporates:
         *  Gain: '<S159>/Gain1'
         */
        rtb_Saturation_ph = 0.0F;
      } else {
        /* Switch: '<S159>/Switch' */
        rtb_Saturation_ph = rtb_Gain_c4;
      }

      /* Gain: '<S157>/Gain' */
      rtb_TmpSignalConversionAtMult_0 = CONTROL_PARAM.FW_TECS_PITCH_D *
        rtb_Saturation_ph;

      /* Saturate: '<S148>/Saturation1' */
      if (rtb_TmpSignalConversionAtMult_0 > 0.3F) {
        rtb_TmpSignalConversionAtMult_0 = 0.3F;
      } else {
        if (rtb_TmpSignalConversionAtMult_0 < -0.3F) {
          rtb_TmpSignalConversionAtMult_0 = -0.3F;
        }
      }

      /* End of Saturate: '<S148>/Saturation1' */
      rtb_Multiply1_e = (((2.0F - CONTROL_PARAM.FW_TECS_RATIO) *
                          rtb_Saturation1_ih - CONTROL_PARAM.FW_TECS_RATIO *
                          rtb_VdotPg) * CONTROL_PARAM.FW_TECS_PITCH_F +
                         ((CONTROL_PARAM.FW_TECS_PITCH_P * rtb_Divide_i_idx_3 +
                           Controller_DW._DSTATE) +
                          rtb_TmpSignalConversionAtMult_0)) +
        CONTROL_PARAM.FW_TECS_R2P * rtb_Abs;
    }

    /* End of Switch: '<S139>/Switch1' */

    /* Sum: '<S92>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Switch_e_idx_0 = rtb_phi_cmd - Controller_U.INS_Out.phi;
    rtb_Switch_e_idx_1 = rtb_Multiply1_e - Controller_U.INS_Out.theta;

    /* Product: '<S95>/Divide1' incorporates:
     *  Abs: '<S95>/Abs'
     *  Constant: '<S95>/const2'
     */
    rtb_TmpSignalConversionAtMult_2 = fabsf(rtb_Switch_e_idx_0) / 0.002F;

    /* Product: '<S95>/Divide' incorporates:
     *  Constant: '<S93>/Constant1'
     *  Constant: '<S95>/const1'
     *  Math: '<S95>/Square'
     *  SignalConversion: '<S95>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_TmpSignalConversionAtMult_1 = 9.5993F / (CONTROL_PARAM.MC_ROLL_P *
      CONTROL_PARAM.MC_ROLL_P);

    /* Signum: '<S95>/Sign' incorporates:
     *  Abs: '<S95>/Abs'
     */
    if (rtb_Switch_e_idx_0 < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else if (rtb_Switch_e_idx_0 > 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_0 = rtb_Switch_e_idx_0;
    }

    /* Switch: '<S95>/Switch' incorporates:
     *  Abs: '<S95>/Abs'
     *  Constant: '<S93>/Constant1'
     *  Gain: '<S95>/Gain1'
     *  Gain: '<S95>/Gain2'
     *  Logic: '<S95>/Logical Operator'
     *  Product: '<S95>/Divide'
     *  Product: '<S95>/Multiply'
     *  Product: '<S95>/Multiply1'
     *  Product: '<S95>/Multiply2'
     *  Product: '<S95>/Multiply3'
     *  RelationalOperator: '<S95>/Relational Operator'
     *  RelationalOperator: '<S95>/Relational Operator2'
     *  SignalConversion: '<S95>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S95>/Sqrt'
     *  Sum: '<S95>/Subtract'
     */
    if ((rtb_Switch_e_idx_0 <= rtb_TmpSignalConversionAtMult_1) &&
        (rtb_Switch_e_idx_0 >= -rtb_TmpSignalConversionAtMult_1)) {
      rtb_TmpSignalConversionAtMult_0 = rtb_Switch_e_idx_0 *
        CONTROL_PARAM.MC_ROLL_P;
    } else {
      rtb_TmpSignalConversionAtMult_0 *= sqrtf((rtb_TmpSignalConversionAtMult_0 *
        rtb_Switch_e_idx_0 - 0.5F * rtb_TmpSignalConversionAtMult_1) *
        Controller_ConstB.Gain_n);
    }

    /* Gain: '<S95>/Gain3' */
    rtb_TmpSignalConversionAtMult_1 = -rtb_TmpSignalConversionAtMult_2;

    /* Switch: '<S96>/Switch' incorporates:
     *  Gain: '<S95>/Gain3'
     *  RelationalOperator: '<S96>/UpperRelop'
     */
    if (rtb_TmpSignalConversionAtMult_0 >= -rtb_TmpSignalConversionAtMult_2) {
      rtb_TmpSignalConversionAtMult_1 = rtb_TmpSignalConversionAtMult_0;
    }

    /* Switch: '<S96>/Switch2' incorporates:
     *  RelationalOperator: '<S96>/LowerRelop1'
     */
    if (rtb_TmpSignalConversionAtMult_0 <= rtb_TmpSignalConversionAtMult_2) {
      rtb_TmpSignalConversionAtMult_2 = rtb_TmpSignalConversionAtMult_1;
    }

    /* Saturate: '<S81>/Saturation1' */
    if (rtb_TmpSignalConversionAtMult_2 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_TmpSignalConversionAtMult_2 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_TmpSignalConversionAtMult_2 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_TmpSignalConversionAtMult_2 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    rtb_Divide_m_idx_3 = rtb_TmpSignalConversionAtMult_2;

    /* Product: '<S95>/Divide1' incorporates:
     *  Abs: '<S95>/Abs'
     *  Constant: '<S95>/const2'
     */
    rtb_TmpSignalConversionAtMult_2 = fabsf(rtb_Switch_e_idx_1) / 0.002F;

    /* Product: '<S95>/Divide' incorporates:
     *  Constant: '<S93>/Constant2'
     *  Constant: '<S95>/const1'
     *  Math: '<S95>/Square'
     *  SignalConversion: '<S95>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_TmpSignalConversionAtMult_1 = 9.5993F / (CONTROL_PARAM.MC_PITCH_P *
      CONTROL_PARAM.MC_PITCH_P);

    /* Signum: '<S95>/Sign' incorporates:
     *  Abs: '<S95>/Abs'
     */
    if (rtb_Switch_e_idx_1 < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else if (rtb_Switch_e_idx_1 > 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_0 = rtb_Switch_e_idx_1;
    }

    /* Switch: '<S95>/Switch' incorporates:
     *  Abs: '<S95>/Abs'
     *  Constant: '<S93>/Constant2'
     *  Gain: '<S95>/Gain1'
     *  Gain: '<S95>/Gain2'
     *  Logic: '<S95>/Logical Operator'
     *  Product: '<S95>/Divide'
     *  Product: '<S95>/Multiply'
     *  Product: '<S95>/Multiply1'
     *  Product: '<S95>/Multiply2'
     *  Product: '<S95>/Multiply3'
     *  RelationalOperator: '<S95>/Relational Operator'
     *  RelationalOperator: '<S95>/Relational Operator2'
     *  SignalConversion: '<S95>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S95>/Sqrt'
     *  Sum: '<S95>/Subtract'
     */
    if ((rtb_Switch_e_idx_1 <= rtb_TmpSignalConversionAtMult_1) &&
        (rtb_Switch_e_idx_1 >= -rtb_TmpSignalConversionAtMult_1)) {
      rtb_TmpSignalConversionAtMult_0 = rtb_Switch_e_idx_1 *
        CONTROL_PARAM.MC_PITCH_P;
    } else {
      rtb_TmpSignalConversionAtMult_0 *= sqrtf((rtb_TmpSignalConversionAtMult_0 *
        rtb_Switch_e_idx_1 - 0.5F * rtb_TmpSignalConversionAtMult_1) *
        Controller_ConstB.Gain_n);
    }

    /* Gain: '<S95>/Gain3' */
    rtb_TmpSignalConversionAtMult_1 = -rtb_TmpSignalConversionAtMult_2;

    /* Switch: '<S96>/Switch' incorporates:
     *  Gain: '<S95>/Gain3'
     *  RelationalOperator: '<S96>/UpperRelop'
     */
    if (rtb_TmpSignalConversionAtMult_0 >= -rtb_TmpSignalConversionAtMult_2) {
      rtb_TmpSignalConversionAtMult_1 = rtb_TmpSignalConversionAtMult_0;
    }

    /* Switch: '<S96>/Switch2' incorporates:
     *  RelationalOperator: '<S96>/LowerRelop1'
     */
    if (rtb_TmpSignalConversionAtMult_0 <= rtb_TmpSignalConversionAtMult_2) {
      rtb_TmpSignalConversionAtMult_2 = rtb_TmpSignalConversionAtMult_1;
    }

    /* Saturate: '<S81>/Saturation1' */
    if (rtb_TmpSignalConversionAtMult_2 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_TmpSignalConversionAtMult_2 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_TmpSignalConversionAtMult_2 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_TmpSignalConversionAtMult_2 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    /* Saturate: '<S81>/Saturation' */
    if (Controller_U.FMS_Out.psi_rate_cmd > CONTROL_PARAM.MC_R_CMD_LIM) {
      rtb_Add3_fc = CONTROL_PARAM.MC_R_CMD_LIM;
    } else if (Controller_U.FMS_Out.psi_rate_cmd < -CONTROL_PARAM.MC_R_CMD_LIM)
    {
      rtb_Add3_fc = -CONTROL_PARAM.MC_R_CMD_LIM;
    } else {
      rtb_Add3_fc = Controller_U.FMS_Out.psi_rate_cmd;
    }

    /* End of Saturate: '<S81>/Saturation' */

    /* Trigonometry: '<S90>/Sin' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S131>/Sin'
     */
    rtb_Switch_e_idx_0 = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S90>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S131>/Cos1'
     */
    rtb_MatrixConcatenate1_p_tmp = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Trigonometry: '<S90>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S131>/Cos'
     */
    rtb_Integrator1_o_tmp = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S90>/Sin1' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S131>/Sin1'
     */
    rtb_Add_k = arm_sin_f32(Controller_U.INS_Out.theta);

    /* Sum: '<S82>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S90>/Multiply'
     *  Product: '<S90>/Multiply1'
     *  Product: '<S90>/Multiply3'
     *  Product: '<S90>/Multiply4'
     *  Product: '<S90>/Multiply5'
     *  Sum: '<S90>/Add'
     *  Sum: '<S90>/Add1'
     *  Sum: '<S90>/Add2'
     *  Trigonometry: '<S90>/Cos'
     *  Trigonometry: '<S90>/Cos1'
     *  Trigonometry: '<S90>/Sin'
     *  Trigonometry: '<S90>/Sin1'
     */
    rtb_TmpSignalConversionAtMult_0 = (rtb_Divide_m_idx_3 - rtb_Add_k *
      rtb_Add3_fc) - Controller_U.INS_Out.p;
    rtb_TmpSignalConversionAtMult_1 = (rtb_Switch_e_idx_0 *
      rtb_MatrixConcatenate1_p_tmp * rtb_Add3_fc + rtb_Integrator1_o_tmp *
      rtb_TmpSignalConversionAtMult_2) - Controller_U.INS_Out.q;
    rtb_TmpSignalConversionAtMult_2 = (rtb_Integrator1_o_tmp *
      rtb_MatrixConcatenate1_p_tmp * rtb_Add3_fc - rtb_Switch_e_idx_0 *
      rtb_TmpSignalConversionAtMult_2) - Controller_U.INS_Out.r;

    /* DiscreteIntegrator: '<S85>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_b != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0] =
        rtb_TmpSignalConversionAtMult_0;
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1] =
        rtb_TmpSignalConversionAtMult_1;
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2] =
        rtb_TmpSignalConversionAtMult_2;
    }

    /* DiscreteIntegrator: '<S89>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S85>/Discrete-Time Integrator5'
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

    /* Gain: '<S89>/Gain' incorporates:
     *  DiscreteIntegrator: '<S85>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S89>/Discrete-Time Integrator1'
     *  Sum: '<S89>/Sum5'
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

    /* RelationalOperator: '<S172>/Compare' incorporates:
     *  Constant: '<S172>/Constant'
     */
    rtb_Compare_nq = (rtb_BitwiseAND_n == 1);

    /* Switch: '<S73>/Switch' incorporates:
     *  Product: '<S86>/Multiply'
     *  Switch: '<S89>/Switch'
     */
    if (rtb_Compare_nq) {
      Controller_B.mc_torque_cmd[0] = 0.0F;
      Controller_B.mc_torque_cmd[1] = 0.0F;
      Controller_B.mc_torque_cmd[2] = 0.0F;
    } else {
      if (rtb_LogicalOperator_i) {
        /* Switch: '<S89>/Switch' incorporates:
         *  Gain: '<S89>/Gain1'
         */
        rtb_Multiply_kn[0] = 0.0F;
        rtb_Multiply_kn[1] = 0.0F;
        rtb_Multiply_kn[2] = 0.0F;
      } else {
        /* Switch: '<S89>/Switch' */
        rtb_Multiply_kn[0] = rtb_DiscreteTimeIntegrator1_k1[0];
        rtb_Multiply_kn[1] = rtb_DiscreteTimeIntegrator1_k1[1];
        rtb_Multiply_kn[2] = rtb_DiscreteTimeIntegrator1_k1[2];
      }

      /* Product: '<S86>/Multiply' incorporates:
       *  Constant: '<S86>/gain1'
       */
      rtb_Saturation_ph = CONTROL_PARAM.MC_ROLL_RATE_D * rtb_Multiply_kn[0];

      /* Saturate: '<S86>/Saturation' */
      if (rtb_Saturation_ph > CONTROL_PARAM.MC_RATE_D_MAX) {
        rtb_Saturation_ph = CONTROL_PARAM.MC_RATE_D_MAX;
      } else {
        if (rtb_Saturation_ph < CONTROL_PARAM.MC_RATE_D_MIN) {
          rtb_Saturation_ph = CONTROL_PARAM.MC_RATE_D_MIN;
        }
      }

      rtb_Multiply_kn[0] = rtb_Saturation_ph;

      /* Product: '<S86>/Multiply' incorporates:
       *  Constant: '<S86>/gain2'
       */
      rtb_Saturation_ph = CONTROL_PARAM.MC_PITCH_RATE_D * rtb_Multiply_kn[1];

      /* Saturate: '<S86>/Saturation' */
      if (rtb_Saturation_ph > CONTROL_PARAM.MC_RATE_D_MAX) {
        rtb_Saturation_ph = CONTROL_PARAM.MC_RATE_D_MAX;
      } else {
        if (rtb_Saturation_ph < CONTROL_PARAM.MC_RATE_D_MIN) {
          rtb_Saturation_ph = CONTROL_PARAM.MC_RATE_D_MIN;
        }
      }

      rtb_Multiply_kn[1] = rtb_Saturation_ph;

      /* Product: '<S86>/Multiply' incorporates:
       *  Constant: '<S86>/gain3'
       */
      rtb_Saturation_ph = CONTROL_PARAM.MC_YAW_RATE_D * rtb_Multiply_kn[2];

      /* Saturate: '<S86>/Saturation' */
      if (rtb_Saturation_ph > CONTROL_PARAM.MC_RATE_D_MAX) {
        rtb_Saturation_ph = CONTROL_PARAM.MC_RATE_D_MAX;
      } else {
        if (rtb_Saturation_ph < CONTROL_PARAM.MC_RATE_D_MIN) {
          rtb_Saturation_ph = CONTROL_PARAM.MC_RATE_D_MIN;
        }
      }

      /* Product: '<S70>/Multiply2' incorporates:
       *  Constant: '<S88>/gain1'
       *  DiscreteIntegrator: '<S114>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S85>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S87>/Discrete-Time Integrator'
       *  Product: '<S88>/Multiply'
       *  Sum: '<S83>/Add'
       */
      rtb_Add3_fc = ((CONTROL_PARAM.MC_ROLL_RATE_P *
                      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0] +
                      Controller_DW.DiscreteTimeIntegrator_DSTATE_d[0]) +
                     rtb_Multiply_kn[0]) *
        Controller_DW.DiscreteTimeIntegrator5_DSTA_a2;

      /* Saturate: '<S70>/Saturation2' */
      if (rtb_Add3_fc > 1.0F) {
        Controller_B.mc_torque_cmd[0] = 1.0F;
      } else if (rtb_Add3_fc < -1.0F) {
        Controller_B.mc_torque_cmd[0] = -1.0F;
      } else {
        Controller_B.mc_torque_cmd[0] = rtb_Add3_fc;
      }

      /* Product: '<S70>/Multiply2' incorporates:
       *  Constant: '<S88>/gain2'
       *  DiscreteIntegrator: '<S114>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S85>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S87>/Discrete-Time Integrator'
       *  Product: '<S88>/Multiply'
       *  Sum: '<S83>/Add'
       */
      rtb_Add3_fc = ((CONTROL_PARAM.MC_PITCH_RATE_P *
                      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1] +
                      Controller_DW.DiscreteTimeIntegrator_DSTATE_d[1]) +
                     rtb_Multiply_kn[1]) *
        Controller_DW.DiscreteTimeIntegrator5_DSTA_a2;

      /* Saturate: '<S70>/Saturation2' */
      if (rtb_Add3_fc > 1.0F) {
        Controller_B.mc_torque_cmd[1] = 1.0F;
      } else if (rtb_Add3_fc < -1.0F) {
        Controller_B.mc_torque_cmd[1] = -1.0F;
      } else {
        Controller_B.mc_torque_cmd[1] = rtb_Add3_fc;
      }

      /* Product: '<S70>/Multiply2' incorporates:
       *  Constant: '<S88>/gain3'
       *  DiscreteIntegrator: '<S114>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S85>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S87>/Discrete-Time Integrator'
       *  Product: '<S88>/Multiply'
       *  Sum: '<S83>/Add'
       */
      rtb_Add3_fc = ((CONTROL_PARAM.MC_YAW_RATE_P *
                      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2] +
                      Controller_DW.DiscreteTimeIntegrator_DSTATE_d[2]) +
                     rtb_Saturation_ph) *
        Controller_DW.DiscreteTimeIntegrator5_DSTA_a2;

      /* Saturate: '<S70>/Saturation2' */
      if (rtb_Add3_fc > 1.0F) {
        Controller_B.mc_torque_cmd[2] = 1.0F;
      } else if (rtb_Add3_fc < -1.0F) {
        Controller_B.mc_torque_cmd[2] = -1.0F;
      } else {
        Controller_B.mc_torque_cmd[2] = rtb_Add3_fc;
      }
    }

    /* Sum: '<S127>/Add' incorporates:
     *  Gain: '<S127>/ucmd2thor'
     *  Gain: '<S127>/wcmd2thor'
     */
    rtb_Divide_m_idx_3 = CONTROL_PARAM.FW_TECS_W2T * rtb_Sum_l +
      CONTROL_PARAM.FW_TECS_U2T * rtb_Cos;

    /* DiscreteIntegrator: '<S161>/ ' */
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

    /* DiscreteIntegrator: '<S162>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_L_h0 != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm = rtb_Divide_m_idx_3;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_d != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm = rtb_Divide_m_idx_3;
    }

    /* Gain: '<S162>/Gain' incorporates:
     *  DiscreteIntegrator: '<S162>/Discrete-Time Integrator1'
     *  Sum: '<S162>/Sum5'
     */
    rtb_Switch_e_idx_1 = (rtb_Divide_m_idx_3 -
                          Controller_DW.DiscreteTimeIntegrator1_DSTA_nm) *
      188.49556F;

    /* Switch: '<S73>/Switch' incorporates:
     *  Constant: '<S128>/Constant'
     *  Constant: '<S171>/Constant'
     *  Constant: '<S173>/Constant2'
     *  RelationalOperator: '<S171>/Compare'
     *  Saturate: '<S128>/Saturation2'
     *  Switch: '<S128>/Switch'
     *  Switch: '<S162>/Switch'
     */
    if (rtb_Compare_nq) {
      Controller_B.fw_force_cmd[0] = Controller_U.FMS_Out.u_cmd;
      Controller_B.fw_force_cmd[1] = 0.0F;
      Controller_B.fw_force_cmd[2] = 0.0F;
    } else {
      if (rtb_BitwiseAND_n <= 3) {
        /* Switch: '<S128>/Switch' incorporates:
         *  Bias: '<S128>/Bias'
         *  Gain: '<S128>/Gain'
         */
        rtb_Add3_fc = 0.000999987125F * (real32_T)
          Controller_U.FMS_Out.throttle_cmd + -1.0F;
      } else {
        if (Controller_U.FMS_Out.reset > 0) {
          /* Switch: '<S162>/Switch' incorporates:
           *  Gain: '<S162>/Gain1'
           *  Switch: '<S128>/Switch'
           */
          rtb_Saturation_ph = 0.0F;
        } else {
          /* Switch: '<S162>/Switch' incorporates:
           *  Switch: '<S128>/Switch'
           */
          rtb_Saturation_ph = rtb_Switch_e_idx_1;
        }

        /* Gain: '<S160>/Gain' incorporates:
         *  Switch: '<S128>/Switch'
         */
        rtb_Add3_fc = CONTROL_PARAM.FW_TECS_THOR_D * rtb_Saturation_ph;

        /* Saturate: '<S149>/Saturation1' incorporates:
         *  Switch: '<S128>/Switch'
         */
        if (rtb_Add3_fc > 0.3F) {
          rtb_Add3_fc = 0.3F;
        } else {
          if (rtb_Add3_fc < -0.3F) {
            rtb_Add3_fc = -0.3F;
          }
        }

        /* End of Saturate: '<S149>/Saturation1' */

        /* Sum: '<S128>/Sum' incorporates:
         *  Constant: '<S128>/cruise_throttle'
         *  DiscreteIntegrator: '<S161>/ '
         *  Gain: '<S127>/Gain1'
         *  Gain: '<S127>/thorttle_ff'
         *  Gain: '<S149>/P_control'
         *  Sum: '<S127>/Add1'
         *  Sum: '<S127>/Add2'
         *  Sum: '<S127>/Sum1'
         *  Sum: '<S149>/Add4'
         *  Switch: '<S128>/Switch'
         */
        rtb_Add3_fc = ((((CONTROL_PARAM.FW_TECS_THOR_P * rtb_Divide_m_idx_3 +
                          Controller_DW._DSTATE_d) + rtb_Add3_fc) +
                        (rtb_Saturation1_ih + rtb_VdotPg) *
                        CONTROL_PARAM.FW_TECS_THOR_FF) +
                       CONTROL_PARAM.FW_TECS_R2T * rtb_Abs) +
          CONTROL_PARAM.FW_CRUISE_THRO;

        /* Saturate: '<S128>/Saturation' incorporates:
         *  Switch: '<S128>/Switch'
         */
        if (rtb_Add3_fc > 1.0F) {
          rtb_Add3_fc = 1.0F;
        } else {
          if (rtb_Add3_fc < -1.0F) {
            rtb_Add3_fc = -1.0F;
          }
        }

        /* End of Saturate: '<S128>/Saturation' */
      }

      /* Saturate: '<S128>/Saturation2' incorporates:
       *  Switch: '<S128>/Switch'
       *  Switch: '<S162>/Switch'
       */
      if (rtb_Add3_fc > 1.0F) {
        Controller_B.fw_force_cmd[0] = 1.0F;
      } else {
        Controller_B.fw_force_cmd[0] = rtb_Add3_fc;
      }

      Controller_B.fw_force_cmd[1] = 0.0F;
      Controller_B.fw_force_cmd[2] = 0.0F;
    }

    /* Gain: '<S105>/Gain' incorporates:
     *  DiscreteIntegrator: '<S107>/Integrator1'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S105>/Sum1'
     */
    rtb_Abs = -(Controller_DW.Integrator1_DSTATE_i - Controller_U.INS_Out.vd);

    /* Logic: '<S102>/Logical Operator' incorporates:
     *  Constant: '<S104>/Constant'
     *  DiscreteIntegrator: '<S114>/Discrete-Time Integrator5'
     *  RelationalOperator: '<S104>/Compare'
     */
    rtb_LogicalOperator_g = ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator5_DSTA_a2 == 0.0F));
    Controller_B.Constant_m = CONTROL_PARAM.MC_VEL_Z_I_MIN;

    /* DiscreteIntegrator: '<S110>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S110>/Constant'
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

    /* DiscreteIntegrator: '<S112>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_i != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_l = rtb_Abs;
    }

    if (rtb_LogicalOperator_g || (Controller_DW.DiscreteTimeIntegrator1_PrevR_h
         != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_l = rtb_Abs;
    }

    /* Gain: '<S112>/Gain' incorporates:
     *  DiscreteIntegrator: '<S112>/Discrete-Time Integrator1'
     *  Sum: '<S112>/Sum5'
     */
    rtb_Saturation1_ih = (rtb_Abs -
                          Controller_DW.DiscreteTimeIntegrator1_DSTAT_l) *
      62.831852F;

    /* Switch: '<S73>/Switch' incorporates:
     *  Constant: '<S76>/Constant'
     *  Product: '<S70>/Multiply1'
     *  Saturate: '<S70>/Saturation1'
     */
    if (rtb_Compare_nq) {
      Controller_B.mc_force_cmd[0] = 0.0F;
      Controller_B.mc_force_cmd[1] = 0.0F;
      Controller_B.mc_force_cmd[2] = 0.0F;
    } else {
      /* Product: '<S103>/Multiply' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S103>/Cos'
       *  Trigonometry: '<S103>/Cos1'
       */
      rtb_Saturation_ph = arm_cos_f32(Controller_U.INS_Out.phi) * arm_cos_f32
        (Controller_U.INS_Out.theta);

      /* Gain: '<S103>/Gain' */
      rtb_Add3_fc = 2.0F * rtb_Saturation_ph;

      /* Saturate: '<S103>/Saturation1' */
      if (rtb_Saturation_ph > 1.0F) {
        rtb_Saturation_ph = 1.0F;
      } else {
        if (rtb_Saturation_ph < 0.5F) {
          rtb_Saturation_ph = 0.5F;
        }
      }

      /* End of Saturate: '<S103>/Saturation1' */

      /* Product: '<S103>/Divide' incorporates:
       *  Constant: '<S103>/Constant'
       */
      rtb_VdotPg = 1.0F / rtb_Saturation_ph;

      /* Switch: '<S112>/Switch' incorporates:
       *  Gain: '<S112>/Gain1'
       */
      if (rtb_LogicalOperator_g) {
        rtb_Saturation_ph = 0.0F;
      } else {
        rtb_Saturation_ph = rtb_Saturation1_ih;
      }

      /* End of Switch: '<S112>/Switch' */

      /* Product: '<S109>/Multiply' incorporates:
       *  Constant: '<S109>/kd'
       */
      rtb_Saturation_ph *= CONTROL_PARAM.MC_VEL_Z_D;

      /* Saturate: '<S109>/Saturation' */
      if (rtb_Saturation_ph > CONTROL_PARAM.MC_VEL_Z_D_MAX) {
        rtb_Saturation_ph = CONTROL_PARAM.MC_VEL_Z_D_MAX;
      } else {
        if (rtb_Saturation_ph < CONTROL_PARAM.MC_VEL_Z_D_MIN) {
          rtb_Saturation_ph = CONTROL_PARAM.MC_VEL_Z_D_MIN;
        }
      }

      /* End of Saturate: '<S109>/Saturation' */

      /* Saturate: '<S103>/Saturation' */
      if (rtb_Add3_fc > 1.0F) {
        rtb_Add3_fc = 1.0F;
      } else {
        if (rtb_Add3_fc < 0.0F) {
          rtb_Add3_fc = 0.0F;
        }
      }

      /* End of Saturate: '<S103>/Saturation' */

      /* Product: '<S103>/Multiply1' incorporates:
       *  Constant: '<S111>/kp'
       *  DiscreteIntegrator: '<S110>/Discrete-Time Integrator'
       *  Product: '<S111>/Multiply'
       *  Sum: '<S106>/Add'
       */
      rtb_Add3_fc *= ((CONTROL_PARAM.MC_VEL_Z_P * rtb_Abs +
                       Controller_DW.DiscreteTimeIntegrator_DSTATE_b) +
                      rtb_Saturation_ph) * rtb_VdotPg;

      /* Saturate: '<S102>/Saturation' */
      if (rtb_Add3_fc > 0.35F) {
        rtb_Add3_fc = 0.35F;
      } else {
        if (rtb_Add3_fc < -0.35F) {
          rtb_Add3_fc = -0.35F;
        }
      }

      /* End of Saturate: '<S102>/Saturation' */

      /* Sum: '<S102>/Sum1' incorporates:
       *  Constant: '<S102>/hover_throttle'
       */
      rtb_Add3_fc += CONTROL_PARAM.MC_HOVER_THRO;
      Controller_B.mc_force_cmd[0] = 0.0F;
      Controller_B.mc_force_cmd[1] = 0.0F;

      /* Product: '<S70>/Multiply1' incorporates:
       *  Constant: '<S76>/Constant'
       *  DiscreteIntegrator: '<S114>/Discrete-Time Integrator5'
       *  Saturate: '<S70>/Saturation1'
       */
      rtb_Add3_fc *= Controller_DW.DiscreteTimeIntegrator5_DSTA_a2;

      /* Saturate: '<S70>/Saturation1' */
      if (rtb_Add3_fc > 1.0F) {
        Controller_B.mc_force_cmd[2] = 1.0F;
      } else if (rtb_Add3_fc < -1.0F) {
        Controller_B.mc_force_cmd[2] = -1.0F;
      } else {
        Controller_B.mc_force_cmd[2] = rtb_Add3_fc;
      }
    }

    /* DiscreteIntegrator: '<S113>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_g != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTA_jo = rtb_Divide_i_idx_2;
    }

    /* Bias: '<S140>/Pitch Offset' */
    rtb_Multiply1_e += CONTROL_PARAM.FW_PITCH_OFFSET;

    /* Saturate: '<S140>/Saturation' */
    if (rtb_Multiply1_e > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Multiply1_e = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_Multiply1_e < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_Multiply1_e = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      }
    }

    /* Product: '<S141>/Multiply' incorporates:
     *  Constant: '<S141>/Constant2'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S140>/Sum'
     */
    rtb_Multiply1_e = (rtb_Multiply1_e - Controller_U.INS_Out.theta) *
      CONTROL_PARAM.FW_PITCH_P;

    /* Product: '<S143>/Divide' incorporates:
     *  Constant: '<S143>/Constant'
     *  DiscreteIntegrator: '<S117>/Discrete-Time Integrator5'
     */
    rtb_Add3_fc = 9.81F / Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;

    /* Saturate: '<S143>/Saturation' */
    if (rtb_Add3_fc > 1.0F) {
      rtb_Add3_fc = 1.0F;
    } else {
      if (rtb_Add3_fc < 0.0F) {
        rtb_Add3_fc = 0.0F;
      }
    }

    /* End of Saturate: '<S143>/Saturation' */

    /* Sum: '<S138>/Sum' incorporates:
     *  Product: '<S143>/Multiply'
     *  Product: '<S143>/Multiply1'
     *  Trigonometry: '<S143>/Cos'
     *  Trigonometry: '<S143>/Tan'
     */
    rtb_Add3_fc = tanf(Controller_U.FMS_Out.phi_cmd) * arm_cos_f32
      (Controller_U.FMS_Out.theta_cmd) * rtb_Add3_fc +
      Controller_U.FMS_Out.psi_rate_cmd;

    /* Saturate: '<S140>/Saturation' */
    if (rtb_phi_cmd > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_phi_cmd = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_phi_cmd < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_phi_cmd = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      }
    }

    /* Sum: '<S131>/Add' incorporates:
     *  Constant: '<S141>/Constant1'
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S131>/Multiply'
     *  Product: '<S141>/Multiply'
     *  Sum: '<S140>/Sum'
     */
    rtb_Add_k = (rtb_phi_cmd - Controller_U.INS_Out.phi) *
      CONTROL_PARAM.FW_ROLL_P - rtb_Add_k * rtb_Add3_fc;

    /* Sum: '<S131>/Add1' incorporates:
     *  Product: '<S131>/Multiply1'
     *  Product: '<S131>/Multiply3'
     */
    rtb_phi_cmd = rtb_Switch_e_idx_0 * rtb_MatrixConcatenate1_p_tmp *
      rtb_Add3_fc + rtb_Integrator1_o_tmp * rtb_Multiply1_e;

    /* Sum: '<S131>/Add2' incorporates:
     *  Product: '<S131>/Multiply4'
     *  Product: '<S131>/Multiply5'
     */
    rtb_Switch_e_idx_0 = rtb_Integrator1_o_tmp * rtb_MatrixConcatenate1_p_tmp *
      rtb_Add3_fc - rtb_Switch_e_idx_0 * rtb_Multiply1_e;

    /* Sum: '<S129>/Minus2' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Multiply_kn[0] = rtb_Add_k - Controller_U.INS_Out.p;
    rtb_Multiply_kn[1] = rtb_phi_cmd - Controller_U.INS_Out.q;
    rtb_Multiply_kn[2] = rtb_Switch_e_idx_0 - Controller_U.INS_Out.r;

    /* DiscreteIntegrator: '<S135>/Discrete-Time Integrator' */
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

    /* Switch: '<S73>/Switch' */
    if (rtb_Compare_nq) {
      Controller_B.fw_torque_cmd[0] = Controller_U.FMS_Out.p_cmd;
      Controller_B.fw_torque_cmd[1] = Controller_U.FMS_Out.q_cmd;
      Controller_B.fw_torque_cmd[2] = Controller_U.FMS_Out.r_cmd;
    } else {
      /* Product: '<S133>/Divide' incorporates:
       *  Constant: '<S133>/trim_speed'
       *  Math: '<S133>/Square'
       */
      rtb_Saturation_c = CONTROL_PARAM.FW_AIRSPEED_TRIM *
        CONTROL_PARAM.FW_AIRSPEED_TRIM / rtb_Saturation_c;

      /* Saturate: '<S133>/Saturation' */
      if (rtb_Saturation_c > 1.0F) {
        rtb_Saturation_c = 1.0F;
      } else {
        if (rtb_Saturation_c < 0.0F) {
          rtb_Saturation_c = 0.0F;
        }
      }

      /* End of Saturate: '<S133>/Saturation' */

      /* Product: '<S129>/Multiply' incorporates:
       *  Constant: '<S136>/gain1'
       *  Constant: '<S136>/gain2'
       *  Constant: '<S136>/gain3'
       *  DiscreteIntegrator: '<S135>/Discrete-Time Integrator'
       *  Product: '<S136>/Multiply'
       *  Sum: '<S132>/Add1'
       */
      rtb_Add3_fc = (CONTROL_PARAM.FW_ROLL_RATE_P * rtb_Multiply_kn[0] +
                     Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0]) *
        rtb_Saturation_c;
      rtb_Multiply1_e = (CONTROL_PARAM.FW_PITCH_RATE_P * rtb_Multiply_kn[1] +
                         Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1]) *
        rtb_Saturation_c;
      rtb_MatrixConcatenate1_p_tmp = (CONTROL_PARAM.FW_YAW_RATE_P *
        rtb_Multiply_kn[2] + Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2]) *
        rtb_Saturation_c;

      /* Product: '<S134>/Divide' incorporates:
       *  Constant: '<S134>/trim_speed'
       *  DiscreteIntegrator: '<S117>/Discrete-Time Integrator5'
       */
      rtb_Saturation_c = CONTROL_PARAM.FW_AIRSPEED_TRIM /
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;

      /* Saturate: '<S134>/Saturation' */
      if (rtb_Saturation_c > 1.0F) {
        rtb_Saturation_c = 1.0F;
      } else {
        if (rtb_Saturation_c < 0.0F) {
          rtb_Saturation_c = 0.0F;
        }
      }

      /* End of Saturate: '<S134>/Saturation' */

      /* Product: '<S129>/Multiply1' incorporates:
       *  Gain: '<S129>/FF'
       */
      rtb_Integrator1_o_tmp = CONTROL_PARAM.FW_FF * rtb_Add_k * rtb_Saturation_c;

      /* Saturate: '<S129>/FF_limit' */
      if (rtb_Integrator1_o_tmp > CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_Integrator1_o_tmp = CONTROL_PARAM.FW_FF_LIMIT;
      } else {
        if (rtb_Integrator1_o_tmp < -CONTROL_PARAM.FW_FF_LIMIT) {
          rtb_Integrator1_o_tmp = -CONTROL_PARAM.FW_FF_LIMIT;
        }
      }

      /* Saturate: '<S129>/PI_limit' */
      if (rtb_Add3_fc > CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_Add3_fc = CONTROL_PARAM.FW_PI_LIMIT;
      } else {
        if (rtb_Add3_fc < -CONTROL_PARAM.FW_PI_LIMIT) {
          rtb_Add3_fc = -CONTROL_PARAM.FW_PI_LIMIT;
        }
      }

      /* Product: '<S72>/Multiply' incorporates:
       *  DiscreteIntegrator: '<S113>/Discrete-Time Integrator5'
       *  Sum: '<S129>/Add'
       */
      rtb_Add3_fc = (rtb_Integrator1_o_tmp + rtb_Add3_fc) *
        Controller_DW.DiscreteTimeIntegrator5_DSTA_jo;

      /* Saturate: '<S72>/Saturation1' */
      if (rtb_Add3_fc > 1.0F) {
        Controller_B.fw_torque_cmd[0] = 1.0F;
      } else if (rtb_Add3_fc < -1.0F) {
        Controller_B.fw_torque_cmd[0] = -1.0F;
      } else {
        Controller_B.fw_torque_cmd[0] = rtb_Add3_fc;
      }

      /* Product: '<S129>/Multiply1' incorporates:
       *  Gain: '<S129>/FF'
       */
      rtb_Add3_fc = CONTROL_PARAM.FW_FF * rtb_phi_cmd * rtb_Saturation_c;

      /* Saturate: '<S129>/FF_limit' */
      if (rtb_Add3_fc > CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_Add3_fc = CONTROL_PARAM.FW_FF_LIMIT;
      } else {
        if (rtb_Add3_fc < -CONTROL_PARAM.FW_FF_LIMIT) {
          rtb_Add3_fc = -CONTROL_PARAM.FW_FF_LIMIT;
        }
      }

      /* Saturate: '<S129>/PI_limit' */
      if (rtb_Multiply1_e > CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_Multiply1_e = CONTROL_PARAM.FW_PI_LIMIT;
      } else {
        if (rtb_Multiply1_e < -CONTROL_PARAM.FW_PI_LIMIT) {
          rtb_Multiply1_e = -CONTROL_PARAM.FW_PI_LIMIT;
        }
      }

      /* Product: '<S72>/Multiply' incorporates:
       *  DiscreteIntegrator: '<S113>/Discrete-Time Integrator5'
       *  Sum: '<S129>/Add'
       */
      rtb_Add3_fc = (rtb_Add3_fc + rtb_Multiply1_e) *
        Controller_DW.DiscreteTimeIntegrator5_DSTA_jo;

      /* Saturate: '<S72>/Saturation1' */
      if (rtb_Add3_fc > 1.0F) {
        Controller_B.fw_torque_cmd[1] = 1.0F;
      } else if (rtb_Add3_fc < -1.0F) {
        Controller_B.fw_torque_cmd[1] = -1.0F;
      } else {
        Controller_B.fw_torque_cmd[1] = rtb_Add3_fc;
      }

      /* Product: '<S129>/Multiply1' incorporates:
       *  Gain: '<S129>/FF'
       */
      rtb_Add3_fc = CONTROL_PARAM.FW_FF * rtb_Switch_e_idx_0 * rtb_Saturation_c;

      /* Saturate: '<S129>/FF_limit' */
      if (rtb_Add3_fc > CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_Add3_fc = CONTROL_PARAM.FW_FF_LIMIT;
      } else {
        if (rtb_Add3_fc < -CONTROL_PARAM.FW_FF_LIMIT) {
          rtb_Add3_fc = -CONTROL_PARAM.FW_FF_LIMIT;
        }
      }

      /* Saturate: '<S129>/PI_limit' */
      if (rtb_MatrixConcatenate1_p_tmp > CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_MatrixConcatenate1_p_tmp = CONTROL_PARAM.FW_PI_LIMIT;
      } else {
        if (rtb_MatrixConcatenate1_p_tmp < -CONTROL_PARAM.FW_PI_LIMIT) {
          rtb_MatrixConcatenate1_p_tmp = -CONTROL_PARAM.FW_PI_LIMIT;
        }
      }

      /* Product: '<S72>/Multiply' incorporates:
       *  DiscreteIntegrator: '<S113>/Discrete-Time Integrator5'
       *  Sum: '<S129>/Add'
       */
      rtb_Add3_fc = (rtb_Add3_fc + rtb_MatrixConcatenate1_p_tmp) *
        Controller_DW.DiscreteTimeIntegrator5_DSTA_jo;

      /* Saturate: '<S72>/Saturation1' */
      if (rtb_Add3_fc > 1.0F) {
        Controller_B.fw_torque_cmd[2] = 1.0F;
      } else if (rtb_Add3_fc < -1.0F) {
        Controller_B.fw_torque_cmd[2] = -1.0F;
      } else {
        Controller_B.fw_torque_cmd[2] = rtb_Add3_fc;
      }
    }

    /* Product: '<S108>/Multiply1' incorporates:
     *  Constant: '<S108>/const1'
     *  DiscreteIntegrator: '<S107>/Integrator'
     */
    rtb_Add3_fc = Controller_DW.Integrator_DSTATE_f * 0.05F;

    /* Sum: '<S108>/Add' incorporates:
     *  DiscreteIntegrator: '<S107>/Integrator1'
     *  Sum: '<S107>/Subtract'
     */
    rtb_Saturation_c = (Controller_DW.Integrator1_DSTATE_i -
                        Controller_U.FMS_Out.w_cmd) + rtb_Add3_fc;

    /* Signum: '<S108>/Sign' */
    if (rtb_Saturation_c < 0.0F) {
      rtb_Switch_e_idx_0 = -1.0F;
    } else if (rtb_Saturation_c > 0.0F) {
      rtb_Switch_e_idx_0 = 1.0F;
    } else {
      rtb_Switch_e_idx_0 = rtb_Saturation_c;
    }

    /* End of Signum: '<S108>/Sign' */

    /* Sum: '<S108>/Add2' incorporates:
     *  Abs: '<S108>/Abs'
     *  Gain: '<S108>/Gain'
     *  Gain: '<S108>/Gain1'
     *  Product: '<S108>/Multiply2'
     *  Product: '<S108>/Multiply3'
     *  Sqrt: '<S108>/Sqrt'
     *  Sum: '<S108>/Add1'
     *  Sum: '<S108>/Subtract'
     */
    rtb_Switch_e_idx_0 = (sqrtf((8.0F * fabsf(rtb_Saturation_c) +
      Controller_ConstB.d_m) * Controller_ConstB.d_m) - Controller_ConstB.d_m) *
      0.5F * rtb_Switch_e_idx_0 + rtb_Add3_fc;

    /* Sum: '<S108>/Add4' */
    rtb_phi_cmd = (rtb_Saturation_c - rtb_Switch_e_idx_0) + rtb_Add3_fc;

    /* Sum: '<S108>/Add3' */
    rtb_Add3_fc = rtb_Saturation_c + Controller_ConstB.d_m;

    /* Sum: '<S108>/Subtract1' */
    rtb_Saturation_c -= Controller_ConstB.d_m;

    /* Signum: '<S108>/Sign1' */
    if (rtb_Add3_fc < 0.0F) {
      rtb_Add3_fc = -1.0F;
    } else {
      if (rtb_Add3_fc > 0.0F) {
        rtb_Add3_fc = 1.0F;
      }
    }

    /* End of Signum: '<S108>/Sign1' */

    /* Signum: '<S108>/Sign2' */
    if (rtb_Saturation_c < 0.0F) {
      rtb_Saturation_c = -1.0F;
    } else {
      if (rtb_Saturation_c > 0.0F) {
        rtb_Saturation_c = 1.0F;
      }
    }

    /* End of Signum: '<S108>/Sign2' */

    /* Sum: '<S108>/Add5' incorporates:
     *  Gain: '<S108>/Gain2'
     *  Product: '<S108>/Multiply4'
     *  Sum: '<S108>/Subtract2'
     */
    rtb_Switch_e_idx_0 += (rtb_Add3_fc - rtb_Saturation_c) * 0.5F * rtb_phi_cmd;

    /* Update for DiscreteIntegrator: '<S117>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S117>/Gain'
     *  Sum: '<S117>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_e = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_j += (rtb_Divide_i_idx_0 -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j) * 125.663704F * 0.002F;

    /* Update for DiscreteIntegrator: '<S115>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S115>/Gain'
     *  Sum: '<S115>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_L_eo = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_a += (rtb_Divide_i_idx_1 -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_a) * 31.415926F * 0.002F;

    /* Update for DiscreteIntegrator: '<S114>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S114>/Gain'
     *  Sum: '<S114>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_o = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTA_a2 += ((real32_T)rtb_Relay -
      Controller_DW.DiscreteTimeIntegrator5_DSTA_a2) * 6.28318548F * 0.002F;

    /* Update for DiscreteIntegrator: '<S87>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S87>/gain1'
     *  Constant: '<S87>/gain2'
     *  Constant: '<S87>/gain3'
     *  DiscreteIntegrator: '<S85>/Discrete-Time Integrator5'
     *  Product: '<S87>/Multiply'
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

    /* End of Update for DiscreteIntegrator: '<S87>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S158>/ ' incorporates:
     *  Gain: '<S158>/Gain3'
     */
    Controller_DW._DSTATE += CONTROL_PARAM.FW_TECS_PITCH_I * rtb_Divide_i_idx_3 *
      0.002F;
    if (Controller_DW._DSTATE >= CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
      Controller_DW._DSTATE = CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
    } else {
      if (Controller_DW._DSTATE <= -CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
        Controller_DW._DSTATE = -CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
      }
    }

    Controller_DW._PrevResetState = (int8_T)(Controller_U.FMS_Out.reset > 0);

    /* End of Update for DiscreteIntegrator: '<S158>/ ' */

    /* Update for DiscreteIntegrator: '<S159>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_f = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_e += 0.002F * rtb_Gain_c4;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_b = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S85>/Discrete-Time Integrator5' */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_b = 0U;

    /* Update for DiscreteIntegrator: '<S89>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_h = 0U;

    /* Update for DiscreteIntegrator: '<S85>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S85>/Gain'
     *  Sum: '<S85>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0] +=
      (rtb_TmpSignalConversionAtMult_0 -
       Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S89>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[0] += 0.002F *
      rtb_DiscreteTimeIntegrator1_k1[0];

    /* Update for DiscreteIntegrator: '<S85>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S85>/Gain'
     *  Sum: '<S85>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1] +=
      (rtb_TmpSignalConversionAtMult_1 -
       Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S89>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[1] += 0.002F *
      rtb_DiscreteTimeIntegrator1_k1[1];

    /* Update for DiscreteIntegrator: '<S85>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S85>/Gain'
     *  Sum: '<S85>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2] +=
      (rtb_TmpSignalConversionAtMult_2 -
       Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S89>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[2] += 0.002F *
      rtb_DiscreteTimeIntegrator1_k1[2];
    Controller_DW.DiscreteTimeIntegrator1_PrevR_l = (int8_T)
      rtb_LogicalOperator_i;

    /* Update for DiscreteIntegrator: '<S161>/ ' incorporates:
     *  Gain: '<S161>/Gain'
     */
    Controller_DW._DSTATE_d += CONTROL_PARAM.FW_TECS_THOR_I * rtb_Divide_m_idx_3
      * 0.002F;
    if (Controller_DW._DSTATE_d >= CONTROL_PARAM.FW_CRUISE_THRO) {
      Controller_DW._DSTATE_d = CONTROL_PARAM.FW_CRUISE_THRO;
    } else {
      if (Controller_DW._DSTATE_d <= -CONTROL_PARAM.FW_CRUISE_THRO) {
        Controller_DW._DSTATE_d = -CONTROL_PARAM.FW_CRUISE_THRO;
      }
    }

    Controller_DW._PrevResetState_e = (int8_T)(Controller_U.FMS_Out.reset > 0);

    /* End of Update for DiscreteIntegrator: '<S161>/ ' */

    /* Update for DiscreteIntegrator: '<S162>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_L_h0 = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTA_nm += 0.002F * rtb_Switch_e_idx_1;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_d = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S107>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S107>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_i += 0.002F *
      Controller_DW.Integrator_DSTATE_f;

    /* Update for DiscreteIntegrator: '<S110>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S110>/ki'
     *  Product: '<S110>/Multiply'
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

    /* End of Update for DiscreteIntegrator: '<S110>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S112>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_i = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_l += 0.002F * rtb_Saturation1_ih;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_h = (int8_T)
      rtb_LogicalOperator_g;

    /* Update for DiscreteIntegrator: '<S113>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S113>/Gain'
     *  Sum: '<S113>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_g = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTA_jo += (rtb_Divide_i_idx_2 -
      Controller_DW.DiscreteTimeIntegrator5_DSTA_jo) * 12.566371F * 0.002F;

    /* Update for DiscreteIntegrator: '<S135>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S135>/gain1'
     *  Constant: '<S135>/gain2'
     *  Constant: '<S135>/gain3'
     *  Product: '<S135>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0] +=
      CONTROL_PARAM.FW_ROLL_RATE_I * rtb_Multiply_kn[0] * 0.002F;
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
      CONTROL_PARAM.FW_PITCH_RATE_I * rtb_Multiply_kn[1] * 0.002F;
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
      CONTROL_PARAM.FW_YAW_RATE_I * rtb_Multiply_kn[2] * 0.002F;
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

    /* End of Update for DiscreteIntegrator: '<S135>/Discrete-Time Integrator' */

    /* Signum: '<S108>/Sign6' incorporates:
     *  Signum: '<S108>/Sign5'
     */
    if (rtb_Switch_e_idx_0 < 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = -1.0F;

      /* Signum: '<S108>/Sign5' */
      rtb_TmpSignalConversionAtMult_2 = -1.0F;
    } else if (rtb_Switch_e_idx_0 > 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = 1.0F;

      /* Signum: '<S108>/Sign5' */
      rtb_TmpSignalConversionAtMult_2 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_1 = rtb_Switch_e_idx_0;

      /* Signum: '<S108>/Sign5' */
      rtb_TmpSignalConversionAtMult_2 = rtb_Switch_e_idx_0;
    }

    /* End of Signum: '<S108>/Sign6' */

    /* Sum: '<S108>/Add6' */
    rtb_Add3_fc = rtb_Switch_e_idx_0 + Controller_ConstB.d_m;

    /* Sum: '<S108>/Subtract3' */
    rtb_TmpSignalConversionAtMult_0 = rtb_Switch_e_idx_0 - Controller_ConstB.d_m;

    /* Signum: '<S108>/Sign3' */
    if (rtb_Add3_fc < 0.0F) {
      rtb_Add3_fc = -1.0F;
    } else {
      if (rtb_Add3_fc > 0.0F) {
        rtb_Add3_fc = 1.0F;
      }
    }

    /* End of Signum: '<S108>/Sign3' */

    /* Signum: '<S108>/Sign4' */
    if (rtb_TmpSignalConversionAtMult_0 < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else {
      if (rtb_TmpSignalConversionAtMult_0 > 0.0F) {
        rtb_TmpSignalConversionAtMult_0 = 1.0F;
      }
    }

    /* End of Signum: '<S108>/Sign4' */

    /* Update for DiscreteIntegrator: '<S107>/Integrator' incorporates:
     *  Constant: '<S108>/const'
     *  Gain: '<S108>/Gain3'
     *  Product: '<S108>/Divide'
     *  Product: '<S108>/Multiply5'
     *  Product: '<S108>/Multiply6'
     *  Sum: '<S108>/Subtract4'
     *  Sum: '<S108>/Subtract5'
     *  Sum: '<S108>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE_f += ((rtb_Switch_e_idx_0 /
      Controller_ConstB.d_m - rtb_TmpSignalConversionAtMult_2) *
      Controller_ConstB.Gain4_o * ((rtb_Add3_fc -
      rtb_TmpSignalConversionAtMult_0) * 0.5F) - rtb_TmpSignalConversionAtMult_1
      * 78.448F) * 0.002F;

    /* End of Outputs for SubSystem: '<S2>/FW_Controller' */
    break;

   case 1:
    if (Controller_DW.SwitchCase1_ActiveSubsystem != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S2>/MC_Controller' incorporates:
       *  ActionPort: '<S6>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S9>/Switch Case1' incorporates:
       *  DiscreteIntegrator: '<S187>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S189>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S191>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S211>/Integrator'
       *  DiscreteIntegrator: '<S211>/Integrator1'
       *  DiscreteIntegrator: '<S216>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S218>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S234>/Integrator'
       *  DiscreteIntegrator: '<S234>/Integrator1'
       *  DiscreteIntegrator: '<S237>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S239>/Discrete-Time Integrator1'
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

    /* DiscreteIntegrator: '<S189>/Discrete-Time Integrator' */
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

    /* Trigonometry: '<S213>/Trigonometric Function1' incorporates:
     *  Gain: '<S212>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1_b[0] = arm_cos_f32(-Controller_U.INS_Out.psi);

    /* Trigonometry: '<S213>/Trigonometric Function' incorporates:
     *  Gain: '<S212>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1_b[1] = arm_sin_f32(-Controller_U.INS_Out.psi);

    /* SignalConversion: '<S213>/ConcatBufferAtVector Concatenate1In3' incorporates:
     *  Constant: '<S213>/Constant3'
     */
    rtb_MatrixConcatenate1_b[2] = 0.0F;

    /* Gain: '<S213>/Gain' incorporates:
     *  Gain: '<S212>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S213>/Trigonometric Function2'
     */
    rtb_MatrixConcatenate1_b[3] = -arm_sin_f32(-Controller_U.INS_Out.psi);

    /* Trigonometry: '<S213>/Trigonometric Function3' incorporates:
     *  Gain: '<S212>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1_b[4] = arm_cos_f32(-Controller_U.INS_Out.psi);

    /* SignalConversion: '<S213>/ConcatBufferAtVector Concatenate2In3' incorporates:
     *  Constant: '<S213>/Constant4'
     */
    rtb_MatrixConcatenate1_b[5] = 0.0F;

    /* SignalConversion: '<S213>/ConcatBufferAtVector ConcatenateIn3' */
    rtb_MatrixConcatenate1_b[6] = Controller_ConstB.VectorConcatenate3[0];
    rtb_MatrixConcatenate1_b[7] = Controller_ConstB.VectorConcatenate3[1];
    rtb_MatrixConcatenate1_b[8] = Controller_ConstB.VectorConcatenate3[2];

    /* Product: '<S210>/Multiply' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  SignalConversion: '<S210>/TmpSignal ConversionAtMultiplyInport2'
     */
    for (rtb_Relay = 0; rtb_Relay < 3; rtb_Relay++) {
      rtb_MatrixConcatenate1_p[rtb_Relay] = rtb_MatrixConcatenate1_b[rtb_Relay +
        3] * Controller_U.INS_Out.ve + rtb_MatrixConcatenate1_b[rtb_Relay] *
        Controller_U.INS_Out.vn;
    }

    /* End of Product: '<S210>/Multiply' */

    /* Sum: '<S207>/Sum' incorporates:
     *  DiscreteIntegrator: '<S211>/Integrator1'
     */
    rtb_Switch_e_idx_0 = Controller_DW.Integrator1_DSTATE[0] -
      rtb_MatrixConcatenate1_p[0];
    rtb_Switch_e_idx_1 = Controller_DW.Integrator1_DSTATE[1] -
      rtb_MatrixConcatenate1_p[1];

    /* DiscreteIntegrator: '<S216>/Discrete-Time Integrator' */
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

    /* DiscreteIntegrator: '<S218>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] = rtb_Switch_e_idx_0;
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] = rtb_Switch_e_idx_1;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevRes != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] = rtb_Switch_e_idx_0;
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] = rtb_Switch_e_idx_1;
    }

    /* Gain: '<S218>/Gain' incorporates:
     *  DiscreteIntegrator: '<S218>/Discrete-Time Integrator1'
     *  Sum: '<S218>/Sum5'
     */
    rtb_Divide_m_idx_3 = (rtb_Switch_e_idx_0 -
                          Controller_DW.DiscreteTimeIntegrator1_DSTATE[0]) *
      62.831852F;
    rtb_Divide_i_idx_1 = (rtb_Switch_e_idx_1 -
                          Controller_DW.DiscreteTimeIntegrator1_DSTATE[1]) *
      62.831852F;

    /* Switch: '<S218>/Switch' incorporates:
     *  Gain: '<S218>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_Divide_i_idx_2 = 0.0F;
      rtb_Divide_i_idx_3 = 0.0F;
    } else {
      rtb_Divide_i_idx_2 = rtb_Divide_m_idx_3;
      rtb_Divide_i_idx_3 = rtb_Divide_i_idx_1;
    }

    /* End of Switch: '<S218>/Switch' */

    /* Product: '<S215>/Multiply' incorporates:
     *  Constant: '<S215>/kd'
     */
    rtb_Gain_c4 = CONTROL_PARAM.MC_VEL_XY_D * rtb_Divide_i_idx_2;

    /* Saturate: '<S215>/Saturation' */
    if (rtb_Gain_c4 > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
      rtb_Gain_c4 = CONTROL_PARAM.MC_VEL_XY_D_MAX;
    } else {
      if (rtb_Gain_c4 < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
        rtb_Gain_c4 = CONTROL_PARAM.MC_VEL_XY_D_MIN;
      }
    }

    rtb_Divide_i_idx_2 = rtb_Gain_c4;

    /* Product: '<S215>/Multiply' incorporates:
     *  Constant: '<S215>/kd'
     */
    rtb_Gain_c4 = CONTROL_PARAM.MC_VEL_XY_D * rtb_Divide_i_idx_3;

    /* Saturate: '<S215>/Saturation' */
    if (rtb_Gain_c4 > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
      rtb_Gain_c4 = CONTROL_PARAM.MC_VEL_XY_D_MAX;
    } else {
      if (rtb_Gain_c4 < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
        rtb_Gain_c4 = CONTROL_PARAM.MC_VEL_XY_D_MIN;
      }
    }

    /* Switch: '<S209>/Switch' incorporates:
     *  Constant: '<S217>/kp'
     *  Constant: '<S219>/Constant'
     *  Constant: '<S221>/Constant'
     *  Constant: '<S222>/Constant'
     *  DiscreteIntegrator: '<S216>/Discrete-Time Integrator'
     *  Product: '<S217>/Multiply'
     *  Product: '<S220>/Multiply2'
     *  Product: '<S220>/Multiply3'
     *  RelationalOperator: '<S219>/Compare'
     *  RelationalOperator: '<S221>/Compare'
     *  RelationalOperator: '<S222>/Compare'
     *  S-Function (sfix_bitop): '<S220>/cmd_ax valid'
     *  S-Function (sfix_bitop): '<S220>/cmd_ay valid'
     *  S-Function (sfix_bitop): '<S220>/cmd_u valid'
     *  S-Function (sfix_bitop): '<S220>/cmd_v valid'
     *  Sum: '<S208>/Add'
     *  Sum: '<S220>/Sum1'
     */
    if (rtb_BitwiseAND_n == 6) {
      rtb_Divide_i_idx_2 = ((Controller_U.FMS_Out.cmd_mask & 64) > 0 ?
                            (CONTROL_PARAM.MC_VEL_XY_P * rtb_Switch_e_idx_0 +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0]) + rtb_Divide_i_idx_2 :
                            0.0F) + ((Controller_U.FMS_Out.cmd_mask & 512) > 0 ?
        Controller_U.FMS_Out.ax_cmd : 0.0F);
      rtb_Divide_i_idx_3 = ((Controller_U.FMS_Out.cmd_mask & 128) > 0 ?
                            (CONTROL_PARAM.MC_VEL_XY_P * rtb_Switch_e_idx_1 +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1]) + rtb_Gain_c4 : 0.0F)
        + ((Controller_U.FMS_Out.cmd_mask & 1024) > 0 ?
           Controller_U.FMS_Out.ay_cmd : 0.0F);
    } else {
      rtb_Divide_i_idx_2 += CONTROL_PARAM.MC_VEL_XY_P * rtb_Switch_e_idx_0 +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0];
      rtb_Divide_i_idx_3 = (CONTROL_PARAM.MC_VEL_XY_P * rtb_Switch_e_idx_1 +
                            Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1]) +
        rtb_Gain_c4;
    }

    /* End of Switch: '<S209>/Switch' */

    /* Trigonometry: '<S206>/Atan' incorporates:
     *  Constant: '<S206>/g'
     *  Gain: '<S206>/Gain1'
     *  Gain: '<S206>/gain'
     *  Product: '<S206>/Divide'
     */
    rtb_Add3_fc = atanf(1.1F * rtb_Divide_i_idx_3 / 9.8055F);
    rtb_Divide_i_idx_3 = atanf(1.1F * -rtb_Divide_i_idx_2 / 9.8055F);

    /* Switch: '<S197>/Switch' incorporates:
     *  Constant: '<S204>/Constant'
     *  Logic: '<S197>/Logical Operator'
     *  RelationalOperator: '<S203>/Compare'
     *  RelationalOperator: '<S204>/Compare'
     *  Saturate: '<S206>/Saturation'
     *  Switch: '<S197>/Switch1'
     */
    if ((rtb_BitwiseAND_n == 3) || (rtb_BitwiseAND_n == 4)) {
      rtb_Divide_i_idx_2 = Controller_U.FMS_Out.phi_cmd;
      rtb_Divide_i_idx_3 = Controller_U.FMS_Out.theta_cmd;
    } else if (rtb_BitwiseAND_n == 6) {
      /* Switch: '<S205>/Switch' incorporates:
       *  S-Function (sfix_bitop): '<S205>/cmd_phi valid'
       *  S-Function (sfix_bitop): '<S205>/cmd_theta valid'
       *  Saturate: '<S206>/Saturation'
       *  Switch: '<S197>/Switch1'
       */
      if ((Controller_U.FMS_Out.cmd_mask & 8) > 0) {
        rtb_Divide_i_idx_2 = Controller_U.FMS_Out.phi_cmd;
      } else if (rtb_Add3_fc > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S206>/Saturation' */
        rtb_Divide_i_idx_2 = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else if (rtb_Add3_fc < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S206>/Saturation' */
        rtb_Divide_i_idx_2 = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        rtb_Divide_i_idx_2 = rtb_Add3_fc;
      }

      if ((Controller_U.FMS_Out.cmd_mask & 16) > 0) {
        rtb_Divide_i_idx_3 = Controller_U.FMS_Out.theta_cmd;
      } else if (rtb_Divide_i_idx_3 > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S206>/Saturation' */
        rtb_Divide_i_idx_3 = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_Divide_i_idx_3 < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Saturate: '<S206>/Saturation' */
          rtb_Divide_i_idx_3 = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        }
      }

      /* End of Switch: '<S205>/Switch' */
    } else {
      if (rtb_Add3_fc > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S206>/Saturation' incorporates:
         *  Switch: '<S197>/Switch1'
         */
        rtb_Divide_i_idx_2 = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else if (rtb_Add3_fc < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S206>/Saturation' incorporates:
         *  Switch: '<S197>/Switch1'
         */
        rtb_Divide_i_idx_2 = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        /* Switch: '<S197>/Switch1' incorporates:
         *  Saturate: '<S206>/Saturation'
         */
        rtb_Divide_i_idx_2 = rtb_Add3_fc;
      }

      /* Saturate: '<S206>/Saturation' */
      if (rtb_Divide_i_idx_3 > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Switch: '<S197>/Switch1' */
        rtb_Divide_i_idx_3 = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_Divide_i_idx_3 < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Switch: '<S197>/Switch1' */
          rtb_Divide_i_idx_3 = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        }
      }
    }

    /* End of Switch: '<S197>/Switch' */

    /* Sum: '<S198>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Gain_c4 = rtb_Divide_i_idx_2 - Controller_U.INS_Out.phi;

    /* Product: '<S201>/Divide1' incorporates:
     *  Abs: '<S201>/Abs'
     *  Constant: '<S201>/const2'
     */
    rtb_Divide_i_idx_0 = fabsf(rtb_Gain_c4) / 0.002F;

    /* Product: '<S201>/Divide' incorporates:
     *  Constant: '<S199>/Constant1'
     *  Constant: '<S201>/const1'
     *  Math: '<S201>/Square'
     *  SignalConversion: '<S201>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_TmpSignalConversionAtMult_1 = 9.5993F / (CONTROL_PARAM.MC_ROLL_P *
      CONTROL_PARAM.MC_ROLL_P);

    /* Signum: '<S201>/Sign' */
    if (rtb_Gain_c4 < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else if (rtb_Gain_c4 > 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_0 = rtb_Gain_c4;
    }

    /* Switch: '<S201>/Switch' incorporates:
     *  Constant: '<S199>/Constant1'
     *  Gain: '<S201>/Gain1'
     *  Gain: '<S201>/Gain2'
     *  Logic: '<S201>/Logical Operator'
     *  Product: '<S201>/Divide'
     *  Product: '<S201>/Multiply'
     *  Product: '<S201>/Multiply1'
     *  Product: '<S201>/Multiply2'
     *  Product: '<S201>/Multiply3'
     *  RelationalOperator: '<S201>/Relational Operator'
     *  RelationalOperator: '<S201>/Relational Operator2'
     *  SignalConversion: '<S201>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S201>/Sqrt'
     *  Sum: '<S201>/Subtract'
     */
    if ((rtb_Gain_c4 <= rtb_TmpSignalConversionAtMult_1) && (rtb_Gain_c4 >=
         -rtb_TmpSignalConversionAtMult_1)) {
      rtb_TmpSignalConversionAtMult_0 = rtb_Gain_c4 * CONTROL_PARAM.MC_ROLL_P;
    } else {
      rtb_TmpSignalConversionAtMult_0 *= sqrtf((rtb_TmpSignalConversionAtMult_0 *
        rtb_Gain_c4 - 0.5F * rtb_TmpSignalConversionAtMult_1) *
        Controller_ConstB.Gain);
    }

    /* Gain: '<S201>/Gain3' */
    rtb_TmpSignalConversionAtMult_1 = -rtb_Divide_i_idx_0;

    /* Switch: '<S202>/Switch' incorporates:
     *  Gain: '<S201>/Gain3'
     *  RelationalOperator: '<S202>/UpperRelop'
     */
    if (rtb_TmpSignalConversionAtMult_0 >= -rtb_Divide_i_idx_0) {
      rtb_TmpSignalConversionAtMult_1 = rtb_TmpSignalConversionAtMult_0;
    }

    /* Switch: '<S202>/Switch2' incorporates:
     *  RelationalOperator: '<S202>/LowerRelop1'
     */
    if (rtb_TmpSignalConversionAtMult_0 <= rtb_Divide_i_idx_0) {
      rtb_Divide_i_idx_0 = rtb_TmpSignalConversionAtMult_1;
    }

    /* Saturate: '<S182>/Saturation1' */
    if (rtb_Divide_i_idx_0 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_Divide_i_idx_0 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_Divide_i_idx_0 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_Divide_i_idx_0 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    rtb_Divide_i_idx_2 = rtb_Divide_i_idx_0;

    /* Sum: '<S198>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S201>/Divide1'
     */
    rtb_Gain_c4 = rtb_Divide_i_idx_3 - Controller_U.INS_Out.theta;

    /* Product: '<S201>/Divide1' incorporates:
     *  Abs: '<S201>/Abs'
     *  Constant: '<S201>/const2'
     */
    rtb_Divide_i_idx_0 = fabsf(rtb_Gain_c4) / 0.002F;

    /* Product: '<S201>/Divide' incorporates:
     *  Constant: '<S199>/Constant2'
     *  Constant: '<S201>/const1'
     *  Math: '<S201>/Square'
     *  SignalConversion: '<S201>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_TmpSignalConversionAtMult_1 = 9.5993F / (CONTROL_PARAM.MC_PITCH_P *
      CONTROL_PARAM.MC_PITCH_P);

    /* Signum: '<S201>/Sign' */
    if (rtb_Gain_c4 < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else if (rtb_Gain_c4 > 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_0 = rtb_Gain_c4;
    }

    /* Switch: '<S201>/Switch' incorporates:
     *  Constant: '<S199>/Constant2'
     *  Gain: '<S201>/Gain1'
     *  Gain: '<S201>/Gain2'
     *  Logic: '<S201>/Logical Operator'
     *  Product: '<S201>/Divide'
     *  Product: '<S201>/Multiply'
     *  Product: '<S201>/Multiply1'
     *  Product: '<S201>/Multiply2'
     *  Product: '<S201>/Multiply3'
     *  RelationalOperator: '<S201>/Relational Operator'
     *  RelationalOperator: '<S201>/Relational Operator2'
     *  SignalConversion: '<S201>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S201>/Sqrt'
     *  Sum: '<S201>/Subtract'
     */
    if ((rtb_Gain_c4 <= rtb_TmpSignalConversionAtMult_1) && (rtb_Gain_c4 >=
         -rtb_TmpSignalConversionAtMult_1)) {
      rtb_TmpSignalConversionAtMult_0 = rtb_Gain_c4 * CONTROL_PARAM.MC_PITCH_P;
    } else {
      rtb_TmpSignalConversionAtMult_0 *= sqrtf((rtb_TmpSignalConversionAtMult_0 *
        rtb_Gain_c4 - 0.5F * rtb_TmpSignalConversionAtMult_1) *
        Controller_ConstB.Gain);
    }

    /* Gain: '<S201>/Gain3' */
    rtb_TmpSignalConversionAtMult_1 = -rtb_Divide_i_idx_0;

    /* Switch: '<S202>/Switch' incorporates:
     *  Gain: '<S201>/Gain3'
     *  RelationalOperator: '<S202>/UpperRelop'
     */
    if (rtb_TmpSignalConversionAtMult_0 >= -rtb_Divide_i_idx_0) {
      rtb_TmpSignalConversionAtMult_1 = rtb_TmpSignalConversionAtMult_0;
    }

    /* Switch: '<S202>/Switch2' incorporates:
     *  RelationalOperator: '<S202>/LowerRelop1'
     */
    if (rtb_TmpSignalConversionAtMult_0 <= rtb_Divide_i_idx_0) {
      rtb_Divide_i_idx_0 = rtb_TmpSignalConversionAtMult_1;
    }

    /* Saturate: '<S182>/Saturation1' */
    if (rtb_Divide_i_idx_0 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_Divide_i_idx_0 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_Divide_i_idx_0 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_Divide_i_idx_0 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    /* Saturate: '<S182>/Saturation' */
    if (Controller_U.FMS_Out.psi_rate_cmd > CONTROL_PARAM.MC_R_CMD_LIM) {
      rtb_Add3_fc = CONTROL_PARAM.MC_R_CMD_LIM;
    } else if (Controller_U.FMS_Out.psi_rate_cmd < -CONTROL_PARAM.MC_R_CMD_LIM)
    {
      rtb_Add3_fc = -CONTROL_PARAM.MC_R_CMD_LIM;
    } else {
      rtb_Add3_fc = Controller_U.FMS_Out.psi_rate_cmd;
    }

    /* End of Saturate: '<S182>/Saturation' */

    /* Trigonometry: '<S192>/Sin' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Saturation_c = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S192>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_phi_cmd = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Product: '<S192>/Multiply3' incorporates:
     *  Trigonometry: '<S192>/Cos1'
     *  Trigonometry: '<S192>/Sin'
     */
    rtb_TmpSignalConversionAtMult_0 = rtb_Saturation_c * rtb_phi_cmd *
      rtb_Add3_fc;

    /* Trigonometry: '<S192>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_TmpSignalConversionAtMult_1 = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Product: '<S192>/Multiply1' incorporates:
     *  Trigonometry: '<S192>/Cos'
     */
    rtb_TmpSignalConversionAtMult_2 = rtb_TmpSignalConversionAtMult_1 *
      rtb_Divide_i_idx_0;

    /* Product: '<S192>/Multiply4' incorporates:
     *  Trigonometry: '<S192>/Sin'
     */
    rtb_Saturation_c *= rtb_Divide_i_idx_0;

    /* Switch: '<S183>/Switch' incorporates:
     *  Constant: '<S193>/Constant'
     *  Constant: '<S194>/Constant'
     *  RelationalOperator: '<S193>/Compare'
     *  RelationalOperator: '<S194>/Compare'
     *  Switch: '<S183>/Switch1'
     */
    if (rtb_BitwiseAND_n == 2) {
      rtb_DiscreteTimeIntegrator1_k1[0] = Controller_U.FMS_Out.p_cmd;
      rtb_DiscreteTimeIntegrator1_k1[1] = Controller_U.FMS_Out.q_cmd;
      rtb_DiscreteTimeIntegrator1_k1[2] = Controller_U.FMS_Out.r_cmd;
    } else if (rtb_BitwiseAND_n == 6) {
      /* Switch: '<S195>/Switch' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Product: '<S192>/Multiply'
       *  Product: '<S192>/Multiply1'
       *  Product: '<S192>/Multiply5'
       *  S-Function (sfix_bitop): '<S195>/cmd_p valid'
       *  S-Function (sfix_bitop): '<S195>/cmd_q valid'
       *  S-Function (sfix_bitop): '<S195>/cmd_r valid'
       *  Sum: '<S192>/Add'
       *  Sum: '<S192>/Add1'
       *  Sum: '<S192>/Add2'
       *  Switch: '<S183>/Switch1'
       *  Trigonometry: '<S192>/Cos'
       *  Trigonometry: '<S192>/Cos1'
       *  Trigonometry: '<S192>/Sin1'
       */
      if ((Controller_U.FMS_Out.cmd_mask & 1) > 0) {
        rtb_DiscreteTimeIntegrator1_k1[0] = Controller_U.FMS_Out.p_cmd;
      } else {
        rtb_DiscreteTimeIntegrator1_k1[0] = rtb_Divide_i_idx_2 - arm_sin_f32
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
          rtb_phi_cmd * rtb_Add3_fc - rtb_Saturation_c;
      }

      /* End of Switch: '<S195>/Switch' */
    } else {
      /* Switch: '<S183>/Switch1' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Product: '<S192>/Multiply'
       *  Product: '<S192>/Multiply3'
       *  Product: '<S192>/Multiply5'
       *  Sum: '<S192>/Add'
       *  Sum: '<S192>/Add1'
       *  Sum: '<S192>/Add2'
       *  Trigonometry: '<S192>/Cos'
       *  Trigonometry: '<S192>/Cos1'
       *  Trigonometry: '<S192>/Sin1'
       */
      rtb_DiscreteTimeIntegrator1_k1[0] = rtb_Divide_i_idx_2 - arm_sin_f32
        (Controller_U.INS_Out.theta) * rtb_Add3_fc;
      rtb_DiscreteTimeIntegrator1_k1[1] = rtb_TmpSignalConversionAtMult_2 +
        rtb_TmpSignalConversionAtMult_0;
      rtb_DiscreteTimeIntegrator1_k1[2] = rtb_TmpSignalConversionAtMult_1 *
        rtb_phi_cmd * rtb_Add3_fc - rtb_Saturation_c;
    }

    /* End of Switch: '<S183>/Switch' */

    /* Sum: '<S184>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_TmpSignalConversionAtMult_0 = rtb_DiscreteTimeIntegrator1_k1[0] -
      Controller_U.INS_Out.p;
    rtb_TmpSignalConversionAtMult_1 = rtb_DiscreteTimeIntegrator1_k1[1] -
      Controller_U.INS_Out.q;
    rtb_TmpSignalConversionAtMult_2 = rtb_DiscreteTimeIntegrator1_k1[2] -
      Controller_U.INS_Out.r;

    /* DiscreteIntegrator: '<S187>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] =
        rtb_TmpSignalConversionAtMult_0;
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] =
        rtb_TmpSignalConversionAtMult_1;
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] =
        rtb_TmpSignalConversionAtMult_2;
    }

    /* DiscreteIntegrator: '<S191>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S187>/Discrete-Time Integrator5'
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

    /* Gain: '<S191>/Gain' incorporates:
     *  DiscreteIntegrator: '<S187>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S191>/Discrete-Time Integrator1'
     *  Sum: '<S191>/Sum5'
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

    /* Switch: '<S191>/Switch' incorporates:
     *  Gain: '<S191>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_Multiply_kn[0] = 0.0F;
      rtb_Multiply_kn[1] = 0.0F;
      rtb_Multiply_kn[2] = 0.0F;
    } else {
      rtb_Multiply_kn[0] = rtb_DiscreteTimeIntegrator1_k1[0];
      rtb_Multiply_kn[1] = rtb_DiscreteTimeIntegrator1_k1[1];
      rtb_Multiply_kn[2] = rtb_DiscreteTimeIntegrator1_k1[2];
    }

    /* End of Switch: '<S191>/Switch' */

    /* Product: '<S188>/Multiply' incorporates:
     *  Constant: '<S188>/gain1'
     */
    rtb_Saturation_ph = CONTROL_PARAM.MC_ROLL_RATE_D * rtb_Multiply_kn[0];

    /* Saturate: '<S188>/Saturation' */
    if (rtb_Saturation_ph > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Saturation_ph = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Saturation_ph < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Saturation_ph = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    rtb_Multiply_kn[0] = rtb_Saturation_ph;

    /* Product: '<S188>/Multiply' incorporates:
     *  Constant: '<S188>/gain2'
     */
    rtb_Saturation_ph = CONTROL_PARAM.MC_PITCH_RATE_D * rtb_Multiply_kn[1];

    /* Saturate: '<S188>/Saturation' */
    if (rtb_Saturation_ph > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Saturation_ph = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Saturation_ph < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Saturation_ph = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    rtb_Multiply_kn[1] = rtb_Saturation_ph;

    /* Product: '<S188>/Multiply' incorporates:
     *  Constant: '<S188>/gain3'
     */
    rtb_Saturation_ph = CONTROL_PARAM.MC_YAW_RATE_D * rtb_Multiply_kn[2];

    /* Saturate: '<S188>/Saturation' */
    if (rtb_Saturation_ph > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Saturation_ph = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Saturation_ph < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Saturation_ph = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    /* SignalConversion: '<S6>/BusConversion_InsertedFor_VTOL_actuator_cmd_at_inport_0' incorporates:
     *  Constant: '<S190>/gain1'
     *  Constant: '<S190>/gain2'
     *  Constant: '<S190>/gain3'
     *  DiscreteIntegrator: '<S187>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S189>/Discrete-Time Integrator'
     *  Product: '<S190>/Multiply'
     *  Sum: '<S185>/Add'
     */
    Controller_B.mc_torque_cmd[0] = (CONTROL_PARAM.MC_ROLL_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0]) + rtb_Multiply_kn[0];
    Controller_B.mc_torque_cmd[1] = (CONTROL_PARAM.MC_PITCH_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1]) + rtb_Multiply_kn[1];
    Controller_B.mc_torque_cmd[2] = (CONTROL_PARAM.MC_YAW_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[2]) + rtb_Saturation_ph;

    /* Product: '<S214>/Multiply1' incorporates:
     *  Constant: '<S214>/const1'
     *  DiscreteIntegrator: '<S211>/Integrator'
     */
    rtb_Saturation_c = Controller_DW.Integrator_DSTATE[0] * 0.05F;
    rtb_Multiply1_e = Controller_DW.Integrator_DSTATE[1] * 0.05F;

    /* Sum: '<S214>/Add' incorporates:
     *  DiscreteIntegrator: '<S211>/Integrator1'
     *  Sum: '<S211>/Subtract'
     */
    rtb_Divide_i_idx_2 = (Controller_DW.Integrator1_DSTATE[0] -
                          Controller_U.FMS_Out.u_cmd) + rtb_Saturation_c;
    rtb_Divide_i_idx_3 = (Controller_DW.Integrator1_DSTATE[1] -
                          Controller_U.FMS_Out.v_cmd) + rtb_Multiply1_e;

    /* Signum: '<S214>/Sign' */
    if (rtb_Divide_i_idx_2 < 0.0F) {
      rtb_Divide_i_idx_0 = -1.0F;
    } else if (rtb_Divide_i_idx_2 > 0.0F) {
      rtb_Divide_i_idx_0 = 1.0F;
    } else {
      rtb_Divide_i_idx_0 = rtb_Divide_i_idx_2;
    }

    /* Sum: '<S214>/Add2' incorporates:
     *  Abs: '<S214>/Abs'
     *  Gain: '<S214>/Gain'
     *  Gain: '<S214>/Gain1'
     *  Product: '<S214>/Multiply2'
     *  Product: '<S214>/Multiply3'
     *  Signum: '<S214>/Sign'
     *  Sqrt: '<S214>/Sqrt'
     *  Sum: '<S214>/Add1'
     *  Sum: '<S214>/Subtract'
     */
    rtb_Divide_i_idx_0 = (sqrtf((8.0F * fabsf(rtb_Divide_i_idx_2) +
      Controller_ConstB.d) * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
      rtb_Divide_i_idx_0 + rtb_Saturation_c;

    /* Sum: '<S214>/Add3' incorporates:
     *  Signum: '<S214>/Sign'
     */
    rtb_Add3_fc = rtb_Divide_i_idx_2 + Controller_ConstB.d;

    /* Sum: '<S214>/Subtract1' incorporates:
     *  Signum: '<S214>/Sign'
     */
    rtb_Gain_c4 = rtb_Divide_i_idx_2 - Controller_ConstB.d;

    /* Signum: '<S214>/Sign1' */
    if (rtb_Add3_fc < 0.0F) {
      rtb_Add3_fc = -1.0F;
    } else {
      if (rtb_Add3_fc > 0.0F) {
        rtb_Add3_fc = 1.0F;
      }
    }

    /* Signum: '<S214>/Sign2' */
    if (rtb_Gain_c4 < 0.0F) {
      rtb_Gain_c4 = -1.0F;
    } else {
      if (rtb_Gain_c4 > 0.0F) {
        rtb_Gain_c4 = 1.0F;
      }
    }

    /* Sum: '<S214>/Add2' incorporates:
     *  Gain: '<S214>/Gain2'
     *  Product: '<S214>/Multiply4'
     *  Signum: '<S214>/Sign'
     *  Sum: '<S214>/Add4'
     *  Sum: '<S214>/Add5'
     *  Sum: '<S214>/Subtract2'
     */
    rtb_Divide_i_idx_2 = ((rtb_Divide_i_idx_2 - rtb_Divide_i_idx_0) +
                          rtb_Saturation_c) * ((rtb_Add3_fc - rtb_Gain_c4) *
      0.5F) + rtb_Divide_i_idx_0;

    /* Signum: '<S214>/Sign' */
    if (rtb_Divide_i_idx_3 < 0.0F) {
      rtb_Divide_i_idx_0 = -1.0F;
    } else if (rtb_Divide_i_idx_3 > 0.0F) {
      rtb_Divide_i_idx_0 = 1.0F;
    } else {
      rtb_Divide_i_idx_0 = rtb_Divide_i_idx_3;
    }

    /* Sum: '<S214>/Add2' incorporates:
     *  Abs: '<S214>/Abs'
     *  Gain: '<S214>/Gain'
     *  Gain: '<S214>/Gain1'
     *  Product: '<S214>/Multiply2'
     *  Product: '<S214>/Multiply3'
     *  Signum: '<S214>/Sign'
     *  Sqrt: '<S214>/Sqrt'
     *  Sum: '<S214>/Add1'
     *  Sum: '<S214>/Subtract'
     */
    rtb_Divide_i_idx_0 = (sqrtf((8.0F * fabsf(rtb_Divide_i_idx_3) +
      Controller_ConstB.d) * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
      rtb_Divide_i_idx_0 + rtb_Multiply1_e;

    /* Sum: '<S214>/Add3' incorporates:
     *  Signum: '<S214>/Sign'
     */
    rtb_Add3_fc = rtb_Divide_i_idx_3 + Controller_ConstB.d;

    /* Sum: '<S214>/Subtract1' incorporates:
     *  Signum: '<S214>/Sign'
     */
    rtb_Gain_c4 = rtb_Divide_i_idx_3 - Controller_ConstB.d;

    /* Signum: '<S214>/Sign1' */
    if (rtb_Add3_fc < 0.0F) {
      rtb_Add3_fc = -1.0F;
    } else {
      if (rtb_Add3_fc > 0.0F) {
        rtb_Add3_fc = 1.0F;
      }
    }

    /* Signum: '<S214>/Sign2' */
    if (rtb_Gain_c4 < 0.0F) {
      rtb_Gain_c4 = -1.0F;
    } else {
      if (rtb_Gain_c4 > 0.0F) {
        rtb_Gain_c4 = 1.0F;
      }
    }

    /* Sum: '<S214>/Add5' incorporates:
     *  Gain: '<S214>/Gain2'
     *  Product: '<S214>/Multiply4'
     *  Signum: '<S214>/Sign'
     *  Sum: '<S214>/Add2'
     *  Sum: '<S214>/Add4'
     *  Sum: '<S214>/Subtract2'
     */
    rtb_Divide_i_idx_0 += ((rtb_Divide_i_idx_3 - rtb_Divide_i_idx_0) +
      rtb_Multiply1_e) * ((rtb_Add3_fc - rtb_Gain_c4) * 0.5F);

    /* Gain: '<S232>/Gain' incorporates:
     *  DiscreteIntegrator: '<S234>/Integrator1'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S232>/Sum1'
     */
    rtb_Divide_i_idx_3 = -(Controller_DW.Integrator1_DSTATE_e -
      Controller_U.INS_Out.vd);
    Controller_B.Constant = CONTROL_PARAM.MC_VEL_Z_I_MIN;

    /* DiscreteIntegrator: '<S237>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S237>/Constant'
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

    /* DiscreteIntegrator: '<S239>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_d != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i = rtb_Divide_i_idx_3;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_Prev_ks != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i = rtb_Divide_i_idx_3;
    }

    /* Gain: '<S239>/Gain' incorporates:
     *  DiscreteIntegrator: '<S239>/Discrete-Time Integrator1'
     *  Sum: '<S239>/Sum5'
     */
    rtb_Gain_c4 = (rtb_Divide_i_idx_3 -
                   Controller_DW.DiscreteTimeIntegrator1_DSTAT_i) * 62.831852F;

    /* Switch: '<S228>/Switch' incorporates:
     *  Constant: '<S230>/Constant'
     *  RelationalOperator: '<S230>/Compare'
     */
    if (rtb_BitwiseAND_n <= 3) {
      /* SignalConversion: '<S6>/BusConversion_InsertedFor_VTOL_actuator_cmd_at_inport_0' incorporates:
       *  Bias: '<S228>/Bias'
       *  Gain: '<S228>/Gain'
       */
      Controller_B.mc_force_cmd[2] = 0.000999987125F * (real32_T)
        Controller_U.FMS_Out.throttle_cmd + -1.0F;
    } else {
      /* Product: '<S231>/Multiply' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S231>/Cos'
       *  Trigonometry: '<S231>/Cos1'
       */
      rtb_phi_cmd = arm_cos_f32(Controller_U.INS_Out.phi) * arm_cos_f32
        (Controller_U.INS_Out.theta);

      /* Gain: '<S231>/Gain' */
      rtb_Add3_fc = 2.0F * rtb_phi_cmd;

      /* Saturate: '<S231>/Saturation1' */
      if (rtb_phi_cmd > 1.0F) {
        rtb_phi_cmd = 1.0F;
      } else {
        if (rtb_phi_cmd < 0.5F) {
          rtb_phi_cmd = 0.5F;
        }
      }

      /* End of Saturate: '<S231>/Saturation1' */

      /* Product: '<S231>/Divide' incorporates:
       *  Constant: '<S231>/Constant'
       */
      rtb_Saturation_c = 1.0F / rtb_phi_cmd;

      /* Switch: '<S239>/Switch' incorporates:
       *  Gain: '<S239>/Gain1'
       */
      if (Controller_U.FMS_Out.reset > 0) {
        rtb_Saturation_ph = 0.0F;
      } else {
        rtb_Saturation_ph = rtb_Gain_c4;
      }

      /* End of Switch: '<S239>/Switch' */

      /* Product: '<S236>/Multiply' incorporates:
       *  Constant: '<S236>/kd'
       */
      rtb_phi_cmd = CONTROL_PARAM.MC_VEL_Z_D * rtb_Saturation_ph;

      /* Saturate: '<S236>/Saturation' */
      if (rtb_phi_cmd > CONTROL_PARAM.MC_VEL_Z_D_MAX) {
        rtb_phi_cmd = CONTROL_PARAM.MC_VEL_Z_D_MAX;
      } else {
        if (rtb_phi_cmd < CONTROL_PARAM.MC_VEL_Z_D_MIN) {
          rtb_phi_cmd = CONTROL_PARAM.MC_VEL_Z_D_MIN;
        }
      }

      /* End of Saturate: '<S236>/Saturation' */

      /* Saturate: '<S231>/Saturation' */
      if (rtb_Add3_fc > 1.0F) {
        rtb_Add3_fc = 1.0F;
      } else {
        if (rtb_Add3_fc < 0.0F) {
          rtb_Add3_fc = 0.0F;
        }
      }

      /* End of Saturate: '<S231>/Saturation' */

      /* Product: '<S231>/Multiply1' incorporates:
       *  Constant: '<S238>/kp'
       *  DiscreteIntegrator: '<S237>/Discrete-Time Integrator'
       *  Product: '<S238>/Multiply'
       *  Sum: '<S233>/Add'
       */
      rtb_Add3_fc *= ((CONTROL_PARAM.MC_VEL_Z_P * rtb_Divide_i_idx_3 +
                       Controller_DW.DiscreteTimeIntegrator_DSTATE_l) +
                      rtb_phi_cmd) * rtb_Saturation_c;

      /* Saturate: '<S229>/Saturation' */
      if (rtb_Add3_fc > 0.35F) {
        rtb_Add3_fc = 0.35F;
      } else {
        if (rtb_Add3_fc < -0.35F) {
          rtb_Add3_fc = -0.35F;
        }
      }

      /* End of Saturate: '<S229>/Saturation' */

      /* SignalConversion: '<S6>/BusConversion_InsertedFor_VTOL_actuator_cmd_at_inport_0' incorporates:
       *  Constant: '<S229>/hover_throttle'
       *  Sum: '<S229>/Sum'
       */
      Controller_B.mc_force_cmd[2] = rtb_Add3_fc + CONTROL_PARAM.MC_HOVER_THRO;
    }

    /* End of Switch: '<S228>/Switch' */

    /* SignalConversion: '<S6>/BusConversion_InsertedFor_VTOL_actuator_cmd_at_inport_0' */
    Controller_B.mc_force_cmd[0] = Controller_ConstB.TmpBufferAtConstantOutport1;
    Controller_B.mc_force_cmd[1] = Controller_ConstB.TmpBufferAtConstantOutport1;

    /* Product: '<S235>/Multiply1' incorporates:
     *  Constant: '<S235>/const1'
     *  DiscreteIntegrator: '<S234>/Integrator'
     */
    rtb_Add3_fc = Controller_DW.Integrator_DSTATE_j * 0.05F;

    /* Sum: '<S235>/Add' incorporates:
     *  DiscreteIntegrator: '<S234>/Integrator1'
     *  Sum: '<S234>/Subtract'
     */
    rtb_phi_cmd = (Controller_DW.Integrator1_DSTATE_e -
                   Controller_U.FMS_Out.w_cmd) + rtb_Add3_fc;

    /* Signum: '<S235>/Sign' */
    if (rtb_phi_cmd < 0.0F) {
      rtb_Saturation_c = -1.0F;
    } else if (rtb_phi_cmd > 0.0F) {
      rtb_Saturation_c = 1.0F;
    } else {
      rtb_Saturation_c = rtb_phi_cmd;
    }

    /* End of Signum: '<S235>/Sign' */

    /* Sum: '<S235>/Add2' incorporates:
     *  Abs: '<S235>/Abs'
     *  Gain: '<S235>/Gain'
     *  Gain: '<S235>/Gain1'
     *  Product: '<S235>/Multiply2'
     *  Product: '<S235>/Multiply3'
     *  Sqrt: '<S235>/Sqrt'
     *  Sum: '<S235>/Add1'
     *  Sum: '<S235>/Subtract'
     */
    rtb_Saturation_c = (sqrtf((8.0F * fabsf(rtb_phi_cmd) + Controller_ConstB.d_i)
      * Controller_ConstB.d_i) - Controller_ConstB.d_i) * 0.5F *
      rtb_Saturation_c + rtb_Add3_fc;

    /* Sum: '<S235>/Add4' */
    rtb_Multiply1_e = (rtb_phi_cmd - rtb_Saturation_c) + rtb_Add3_fc;

    /* Sum: '<S235>/Add3' */
    rtb_Add3_fc = rtb_phi_cmd + Controller_ConstB.d_i;

    /* Sum: '<S235>/Subtract1' */
    rtb_phi_cmd -= Controller_ConstB.d_i;

    /* Signum: '<S235>/Sign1' */
    if (rtb_Add3_fc < 0.0F) {
      rtb_Add3_fc = -1.0F;
    } else {
      if (rtb_Add3_fc > 0.0F) {
        rtb_Add3_fc = 1.0F;
      }
    }

    /* End of Signum: '<S235>/Sign1' */

    /* Signum: '<S235>/Sign2' */
    if (rtb_phi_cmd < 0.0F) {
      rtb_phi_cmd = -1.0F;
    } else {
      if (rtb_phi_cmd > 0.0F) {
        rtb_phi_cmd = 1.0F;
      }
    }

    /* End of Signum: '<S235>/Sign2' */

    /* Sum: '<S235>/Add5' incorporates:
     *  Gain: '<S235>/Gain2'
     *  Product: '<S235>/Multiply4'
     *  Sum: '<S235>/Subtract2'
     */
    rtb_Saturation_c += (rtb_Add3_fc - rtb_phi_cmd) * 0.5F * rtb_Multiply1_e;

    /* Update for DiscreteIntegrator: '<S189>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S189>/gain1'
     *  Constant: '<S189>/gain2'
     *  Constant: '<S189>/gain3'
     *  DiscreteIntegrator: '<S187>/Discrete-Time Integrator5'
     *  Product: '<S189>/Multiply'
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

    /* End of Update for DiscreteIntegrator: '<S189>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S216>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_PrevRe_p = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S218>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;

    /* Update for DiscreteIntegrator: '<S211>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S211>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE[0] += 0.002F *
      Controller_DW.Integrator_DSTATE[0];

    /* Update for DiscreteIntegrator: '<S216>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S216>/ki'
     *  Product: '<S216>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0] +=
      CONTROL_PARAM.MC_VEL_XY_I * rtb_Switch_e_idx_0 * 0.002F;
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

    /* Update for DiscreteIntegrator: '<S218>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] += 0.002F *
      rtb_Divide_m_idx_3;

    /* Update for DiscreteIntegrator: '<S211>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S211>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE[1] += 0.002F *
      Controller_DW.Integrator_DSTATE[1];

    /* Update for DiscreteIntegrator: '<S216>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S216>/ki'
     *  Product: '<S216>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1] +=
      CONTROL_PARAM.MC_VEL_XY_I * rtb_Switch_e_idx_1 * 0.002F;
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

    /* Update for DiscreteIntegrator: '<S218>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] += 0.002F *
      rtb_Divide_i_idx_1;
    Controller_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S187>/Discrete-Time Integrator5' */
    Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;

    /* Update for DiscreteIntegrator: '<S191>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 0U;

    /* Update for DiscreteIntegrator: '<S187>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S187>/Gain'
     *  Sum: '<S187>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] +=
      (rtb_TmpSignalConversionAtMult_0 -
       Controller_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S191>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[0] += 0.002F *
      rtb_DiscreteTimeIntegrator1_k1[0];

    /* Update for DiscreteIntegrator: '<S187>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S187>/Gain'
     *  Sum: '<S187>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] +=
      (rtb_TmpSignalConversionAtMult_1 -
       Controller_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S191>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[1] += 0.002F *
      rtb_DiscreteTimeIntegrator1_k1[1];

    /* Update for DiscreteIntegrator: '<S187>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S187>/Gain'
     *  Sum: '<S187>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] +=
      (rtb_TmpSignalConversionAtMult_2 -
       Controller_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S191>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[2] += 0.002F *
      rtb_DiscreteTimeIntegrator1_k1[2];
    Controller_DW.DiscreteTimeIntegrator1_PrevR_k = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Signum: '<S214>/Sign3' incorporates:
     *  Product: '<S214>/Divide'
     *  Sum: '<S214>/Add6'
     */
    rtb_Add3_fc = rtb_Divide_i_idx_2 + Controller_ConstB.d;

    /* Signum: '<S214>/Sign4' incorporates:
     *  Product: '<S214>/Divide'
     *  Sum: '<S214>/Subtract3'
     */
    rtb_TmpSignalConversionAtMult_0 = rtb_Divide_i_idx_2 - Controller_ConstB.d;

    /* Signum: '<S214>/Sign5' incorporates:
     *  Product: '<S214>/Divide'
     */
    if (rtb_Divide_i_idx_2 < 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = -1.0F;
    } else if (rtb_Divide_i_idx_2 > 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_1 = rtb_Divide_i_idx_2;
    }

    /* Signum: '<S214>/Sign3' */
    if (rtb_Add3_fc < 0.0F) {
      rtb_Add3_fc = -1.0F;
    } else {
      if (rtb_Add3_fc > 0.0F) {
        rtb_Add3_fc = 1.0F;
      }
    }

    /* Signum: '<S214>/Sign4' */
    if (rtb_TmpSignalConversionAtMult_0 < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else {
      if (rtb_TmpSignalConversionAtMult_0 > 0.0F) {
        rtb_TmpSignalConversionAtMult_0 = 1.0F;
      }
    }

    /* Signum: '<S214>/Sign6' incorporates:
     *  Product: '<S214>/Divide'
     */
    if (rtb_Divide_i_idx_2 < 0.0F) {
      rtb_TmpSignalConversionAtMult_2 = -1.0F;
    } else if (rtb_Divide_i_idx_2 > 0.0F) {
      rtb_TmpSignalConversionAtMult_2 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_2 = rtb_Divide_i_idx_2;
    }

    /* Update for DiscreteIntegrator: '<S211>/Integrator' incorporates:
     *  Constant: '<S214>/const'
     *  Gain: '<S214>/Gain3'
     *  Product: '<S214>/Divide'
     *  Product: '<S214>/Multiply5'
     *  Product: '<S214>/Multiply6'
     *  Sum: '<S214>/Subtract4'
     *  Sum: '<S214>/Subtract5'
     *  Sum: '<S214>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE[0] += ((rtb_Divide_i_idx_2 /
      Controller_ConstB.d - rtb_TmpSignalConversionAtMult_1) *
      Controller_ConstB.Gain4 * ((rtb_Add3_fc - rtb_TmpSignalConversionAtMult_0)
      * 0.5F) - rtb_TmpSignalConversionAtMult_2 * 58.836F) * 0.002F;

    /* Signum: '<S214>/Sign3' incorporates:
     *  Sum: '<S214>/Add6'
     */
    rtb_Add3_fc = rtb_Divide_i_idx_0 + Controller_ConstB.d;

    /* Signum: '<S214>/Sign4' incorporates:
     *  Sum: '<S214>/Subtract3'
     */
    rtb_TmpSignalConversionAtMult_0 = rtb_Divide_i_idx_0 - Controller_ConstB.d;

    /* Signum: '<S214>/Sign5' */
    if (rtb_Divide_i_idx_0 < 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = -1.0F;
    } else if (rtb_Divide_i_idx_0 > 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_1 = rtb_Divide_i_idx_0;
    }

    /* Signum: '<S214>/Sign3' */
    if (rtb_Add3_fc < 0.0F) {
      rtb_Add3_fc = -1.0F;
    } else {
      if (rtb_Add3_fc > 0.0F) {
        rtb_Add3_fc = 1.0F;
      }
    }

    /* Signum: '<S214>/Sign4' */
    if (rtb_TmpSignalConversionAtMult_0 < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else {
      if (rtb_TmpSignalConversionAtMult_0 > 0.0F) {
        rtb_TmpSignalConversionAtMult_0 = 1.0F;
      }
    }

    /* Signum: '<S214>/Sign6' */
    if (rtb_Divide_i_idx_0 < 0.0F) {
      rtb_TmpSignalConversionAtMult_2 = -1.0F;
    } else if (rtb_Divide_i_idx_0 > 0.0F) {
      rtb_TmpSignalConversionAtMult_2 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_2 = rtb_Divide_i_idx_0;
    }

    /* Update for DiscreteIntegrator: '<S211>/Integrator' incorporates:
     *  Constant: '<S214>/const'
     *  Gain: '<S214>/Gain3'
     *  Product: '<S214>/Divide'
     *  Product: '<S214>/Multiply5'
     *  Product: '<S214>/Multiply6'
     *  Sum: '<S214>/Subtract4'
     *  Sum: '<S214>/Subtract5'
     *  Sum: '<S214>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE[1] += ((rtb_Divide_i_idx_0 /
      Controller_ConstB.d - rtb_TmpSignalConversionAtMult_1) *
      Controller_ConstB.Gain4 * ((rtb_Add3_fc - rtb_TmpSignalConversionAtMult_0)
      * 0.5F) - rtb_TmpSignalConversionAtMult_2 * 58.836F) * 0.002F;

    /* Update for DiscreteIntegrator: '<S234>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S234>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_e += 0.002F *
      Controller_DW.Integrator_DSTATE_j;

    /* Update for DiscreteIntegrator: '<S237>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S237>/ki'
     *  Product: '<S237>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_l += CONTROL_PARAM.MC_VEL_Z_I *
      rtb_Divide_i_idx_3 * 0.002F;
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

    /* End of Update for DiscreteIntegrator: '<S237>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S239>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_i += 0.002F * rtb_Gain_c4;
    Controller_DW.DiscreteTimeIntegrator1_Prev_ks = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Signum: '<S235>/Sign6' incorporates:
     *  Signum: '<S235>/Sign5'
     */
    if (rtb_Saturation_c < 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = -1.0F;

      /* Signum: '<S235>/Sign5' */
      rtb_TmpSignalConversionAtMult_2 = -1.0F;
    } else if (rtb_Saturation_c > 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = 1.0F;

      /* Signum: '<S235>/Sign5' */
      rtb_TmpSignalConversionAtMult_2 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_1 = rtb_Saturation_c;

      /* Signum: '<S235>/Sign5' */
      rtb_TmpSignalConversionAtMult_2 = rtb_Saturation_c;
    }

    /* End of Signum: '<S235>/Sign6' */

    /* Sum: '<S235>/Add6' */
    rtb_Add3_fc = rtb_Saturation_c + Controller_ConstB.d_i;

    /* Sum: '<S235>/Subtract3' */
    rtb_TmpSignalConversionAtMult_0 = rtb_Saturation_c - Controller_ConstB.d_i;

    /* Signum: '<S235>/Sign3' */
    if (rtb_Add3_fc < 0.0F) {
      rtb_Add3_fc = -1.0F;
    } else {
      if (rtb_Add3_fc > 0.0F) {
        rtb_Add3_fc = 1.0F;
      }
    }

    /* End of Signum: '<S235>/Sign3' */

    /* Signum: '<S235>/Sign4' */
    if (rtb_TmpSignalConversionAtMult_0 < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else {
      if (rtb_TmpSignalConversionAtMult_0 > 0.0F) {
        rtb_TmpSignalConversionAtMult_0 = 1.0F;
      }
    }

    /* End of Signum: '<S235>/Sign4' */

    /* Update for DiscreteIntegrator: '<S234>/Integrator' incorporates:
     *  Constant: '<S235>/const'
     *  Gain: '<S235>/Gain3'
     *  Product: '<S235>/Divide'
     *  Product: '<S235>/Multiply5'
     *  Product: '<S235>/Multiply6'
     *  Sum: '<S235>/Subtract4'
     *  Sum: '<S235>/Subtract5'
     *  Sum: '<S235>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE_j += ((rtb_Saturation_c /
      Controller_ConstB.d_i - rtb_TmpSignalConversionAtMult_2) *
      Controller_ConstB.Gain4_p * ((rtb_Add3_fc -
      rtb_TmpSignalConversionAtMult_0) * 0.5F) - rtb_TmpSignalConversionAtMult_1
      * 78.448F) * 0.002F;

    /* End of Outputs for SubSystem: '<S2>/MC_Controller' */
    break;
  }

  /* End of SwitchCase: '<S9>/Switch Case1' */

  /* Outputs for Atomic SubSystem: '<S7>/VTOL_Control_Allocation' */
#if AIRFRAME == 1

  /* Output and update for atomic system: '<S241>/VTOL1' */
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

    /* Saturate: '<S251>/Saturation' incorporates:
     *  Bias: '<S251>/Bias'
     *  Bias: '<S251>/Bias1'
     *  Bias: '<S251>/Bias2'
     *  Bias: '<S251>/Bias3'
     *  Constant: '<S251>/Constant'
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

    /* End of Saturate: '<S251>/Saturation' */

    /* MultiPortSwitch: '<S246>/Multiport Switch' incorporates:
     *  Constant: '<S247>/Constant1'
     *  Constant: '<S247>/Constant12'
     *  Constant: '<S247>/Constant2'
     *  Constant: '<S247>/Constant7'
     *  DataTypeConversion: '<S251>/Data Type Conversion'
     *  DataTypeConversion: '<S252>/Data Type Conversion'
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
        /* Saturate: '<S252>/Saturation' incorporates:
         *  Constant: '<S252>/Disarm'
         *  Reshape: '<S252>/Reshape'
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

      /* Saturate: '<S252>/Saturation' incorporates:
       *  Bias: '<S252>/Bias'
       *  Constant: '<S252>/Constant'
       *  DataTypeConversion: '<S252>/Data Type Conversion'
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

      /* Saturate: '<S252>/Saturation' incorporates:
       *  Bias: '<S252>/Bias1'
       *  Constant: '<S252>/Constant'
       *  DataTypeConversion: '<S252>/Data Type Conversion'
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

      /* Saturate: '<S252>/Saturation' incorporates:
       *  Bias: '<S252>/Bias2'
       *  Constant: '<S252>/Constant'
       *  DataTypeConversion: '<S252>/Data Type Conversion'
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

      /* Saturate: '<S252>/Saturation' incorporates:
       *  Bias: '<S252>/Bias3'
       *  Constant: '<S252>/Constant'
       *  DataTypeConversion: '<S252>/Data Type Conversion'
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

      /* SignalConversion: '<S247>/ConcatBufferAtVector Concatenate2In3' incorporates:
       *  Constant: '<S247>/Constant11'
       *  Constant: '<S247>/Constant12'
       */
      rtb_MatrixConcatenate[10] = 0.0F;

      /* SignalConversion: '<S247>/ConcatBufferAtVector Concatenate2In2' incorporates:
       *  Constant: '<S247>/Constant10'
       */
      rtb_MatrixConcatenate[9] = 0.0F;

      /* SignalConversion: '<S247>/ConcatBufferAtVector Concatenate2In1' incorporates:
       *  Constant: '<S247>/Constant9'
       */
      rtb_MatrixConcatenate[8] = 0.0F;

      /* SignalConversion: '<S247>/ConcatBufferAtVector Concatenate1In4' incorporates:
       *  Constant: '<S247>/Constant8'
       */
      rtb_MatrixConcatenate[7] = 0.0F;
      rtb_MatrixConcatenate[6] = CONTROL_PARAM.FW_PITCH_EFFC *
        CONTROL_PARAM.FW_ELEVATOR_DIR;

      /* SignalConversion: '<S247>/ConcatBufferAtVector Concatenate1In2' incorporates:
       *  Constant: '<S247>/Constant6'
       *  Constant: '<S247>/Constant7'
       */
      rtb_MatrixConcatenate[5] = 0.0F;

      /* SignalConversion: '<S247>/ConcatBufferAtVector Concatenate1In1' incorporates:
       *  Constant: '<S247>/Constant5'
       */
      rtb_MatrixConcatenate[4] = 0.0F;

      /* SignalConversion: '<S247>/ConcatBufferAtVector ConcatenateIn4' incorporates:
       *  Constant: '<S247>/Constant4'
       */
      rtb_MatrixConcatenate[3] = 0.0F;

      /* SignalConversion: '<S247>/ConcatBufferAtVector ConcatenateIn3' incorporates:
       *  Constant: '<S247>/Constant3'
       */
      rtb_MatrixConcatenate[2] = 0.0F;
      rtb_MatrixConcatenate[1] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON2_DIR;
      rtb_MatrixConcatenate[0] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON1_DIR;

      /* Saturate: '<S244>/Saturation5' incorporates:
       *  Constant: '<S247>/Constant1'
       *  Constant: '<S247>/Constant2'
       */
      if (Controller_B.fw_torque_cmd[0] > 1.0F) {
        /* Product: '<S244>/Multiply1' */
        tmp_c = 1.0F;
      } else if (Controller_B.fw_torque_cmd[0] < -1.0F) {
        /* Product: '<S244>/Multiply1' */
        tmp_c = -1.0F;
      } else {
        /* Product: '<S244>/Multiply1' */
        tmp_c = Controller_B.fw_torque_cmd[0];
      }

      if (Controller_B.fw_torque_cmd[1] > 1.0F) {
        /* Product: '<S244>/Multiply1' */
        tmp_d = 1.0F;
      } else if (Controller_B.fw_torque_cmd[1] < -1.0F) {
        /* Product: '<S244>/Multiply1' */
        tmp_d = -1.0F;
      } else {
        /* Product: '<S244>/Multiply1' */
        tmp_d = Controller_B.fw_torque_cmd[1];
      }

      if (Controller_B.fw_torque_cmd[2] > 1.0F) {
        /* Product: '<S244>/Multiply1' */
        tmp_nk = 1.0F;
      } else if (Controller_B.fw_torque_cmd[2] < -1.0F) {
        /* Product: '<S244>/Multiply1' */
        tmp_nk = -1.0F;
      } else {
        /* Product: '<S244>/Multiply1' */
        tmp_nk = Controller_B.fw_torque_cmd[2];
      }

      /* End of Saturate: '<S244>/Saturation5' */
      for (i_p = 0; i_p < 4; i_p++) {
        /* Bias: '<S244>/Bias' incorporates:
         *  Gain: '<S244>/Gain1'
         *  Product: '<S244>/Multiply1'
         */
        rtb_Multiply_fw[i_p] = 500.0F * (rtb_MatrixConcatenate[i_p + 8] * tmp_nk
          + (rtb_MatrixConcatenate[i_p + 4] * tmp_d + rtb_MatrixConcatenate[i_p]
             * tmp_c)) + 1500.0F;
      }

      /* Saturate: '<S245>/Saturation2' */
      if (Controller_B.mc_force_cmd[2] > 1.0F) {
        tmp_a = 1.0F;
      } else if (Controller_B.mc_force_cmd[2] < 0.0F) {
        tmp_a = 0.0F;
      } else {
        tmp_a = Controller_B.mc_force_cmd[2];
      }

      /* End of Saturate: '<S245>/Saturation2' */

      /* DataTypeConversion: '<S250>/Data Type Conversion' incorporates:
       *  Constant: '<S250>/Constant1'
       *  Gain: '<S250>/Gain1'
       *  Sum: '<S250>/Sum1'
       */
      rtb_DataTypeConversion_i = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
        tmp_a), 4.2949673E+9F) + 1000U);

      /* Saturate: '<S245>/Saturation1' */
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

      /* End of Saturate: '<S245>/Saturation1' */

      /* Saturate: '<S244>/Saturation' */
      if (Controller_B.fw_force_cmd[0] > 1.0F) {
        tmp_a = 1.0F;
      } else if (Controller_B.fw_force_cmd[0] < 0.0F) {
        tmp_a = 0.0F;
      } else {
        tmp_a = Controller_B.fw_force_cmd[0];
      }

      /* End of Saturate: '<S244>/Saturation' */

      /* Saturate: '<S244>/Saturation1' incorporates:
       *  Constant: '<S249>/Constant1'
       *  DataTypeConversion: '<S249>/Data Type Conversion'
       *  Gain: '<S249>/Gain1'
       *  Sum: '<S249>/Sum1'
       */
      tmp_p[0] = (uint16_T)((uint32_T)fmodf(floorf(1000.0F * tmp_a),
        4.2949673E+9F) + 1000U);

      /* DataTypeConversion: '<S244>/Data Type Conversion' incorporates:
       *  Bias: '<S244>/Bias1'
       */
      tmp_a = fmodf(floorf(rtb_Multiply_fw[0] + CONTROL_PARAM.SERVO1_BIAS),
                    65536.0F);

      /* Saturate: '<S244>/Saturation1' incorporates:
       *  DataTypeConversion: '<S244>/Data Type Conversion'
       */
      tmp_p[1] = (uint16_T)(tmp_a < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_a : (int32_T)(uint16_T)tmp_a);

      /* DataTypeConversion: '<S244>/Data Type Conversion1' incorporates:
       *  Bias: '<S244>/Bias2'
       */
      tmp_a = fmodf(floorf(rtb_Multiply_fw[1] + CONTROL_PARAM.SERVO2_BIAS),
                    65536.0F);

      /* Saturate: '<S244>/Saturation1' incorporates:
       *  DataTypeConversion: '<S244>/Data Type Conversion1'
       */
      tmp_p[2] = (uint16_T)(tmp_a < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_a : (int32_T)(uint16_T)tmp_a);

      /* DataTypeConversion: '<S244>/Data Type Conversion2' incorporates:
       *  Bias: '<S244>/Bias3'
       */
      tmp_a = fmodf(floorf(rtb_Multiply_fw[2] + CONTROL_PARAM.SERVO3_BIAS),
                    65536.0F);

      /* Saturate: '<S244>/Saturation1' incorporates:
       *  DataTypeConversion: '<S244>/Data Type Conversion2'
       */
      tmp_p[3] = (uint16_T)(tmp_a < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_a : (int32_T)(uint16_T)tmp_a);

      /* DataTypeConversion: '<S244>/Data Type Conversion3' incorporates:
       *  Bias: '<S244>/Bias4'
       */
      tmp_a = fmodf(floorf(rtb_Multiply_fw[3] + CONTROL_PARAM.SERVO4_BIAS),
                    65536.0F);

      /* Saturate: '<S244>/Saturation1' incorporates:
       *  DataTypeConversion: '<S244>/Data Type Conversion3'
       */
      tmp_p[4] = (uint16_T)(tmp_a < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_a : (int32_T)(uint16_T)tmp_a);

      /* Product: '<S245>/Multiply' */
      for (i_p = 0; i_p < 4; i_p++) {
        /* Saturate: '<S245>/Saturation' incorporates:
         *  Constant: '<S245>/Effective_Matrix'
         *  Gain: '<S245>/Gain'
         *  Sum: '<S245>/Add'
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

        /* End of Saturate: '<S245>/Saturation' */
      }

      /* End of Product: '<S245>/Multiply' */
      for (i_p = 0; i_p < 5; i_p++) {
        /* Saturate: '<S244>/Saturation1' */
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

    /* End of MultiPortSwitch: '<S246>/Multiport Switch' */
  }

#elif AIRFRAME == 2

  /* Output and update for atomic system: '<S241>/VTOL2' */
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

    /* Saturate: '<S260>/Saturation' incorporates:
     *  Bias: '<S260>/Bias'
     *  Bias: '<S260>/Bias1'
     *  Bias: '<S260>/Bias2'
     *  Bias: '<S260>/Bias3'
     *  Constant: '<S260>/Constant'
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

    /* End of Saturate: '<S260>/Saturation' */

    /* MultiPortSwitch: '<S255>/Multiport Switch' incorporates:
     *  Constant: '<S256>/Constant1'
     *  Constant: '<S256>/Constant11'
     *  Constant: '<S256>/Constant12'
     *  Constant: '<S256>/Constant2'
     *  Constant: '<S256>/Constant7'
     *  Constant: '<S256>/Constant8'
     *  DataTypeConversion: '<S260>/Data Type Conversion'
     *  DataTypeConversion: '<S261>/Data Type Conversion'
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
        /* Saturate: '<S261>/Saturation' incorporates:
         *  Constant: '<S261>/Disarm'
         *  Reshape: '<S261>/Reshape'
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

      /* Saturate: '<S261>/Saturation' incorporates:
       *  Bias: '<S261>/Bias'
       *  Constant: '<S261>/Constant'
       *  DataTypeConversion: '<S261>/Data Type Conversion'
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

      /* Saturate: '<S261>/Saturation' incorporates:
       *  Bias: '<S261>/Bias1'
       *  Constant: '<S261>/Constant'
       *  DataTypeConversion: '<S261>/Data Type Conversion'
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

      /* Saturate: '<S261>/Saturation' incorporates:
       *  Bias: '<S261>/Bias2'
       *  Constant: '<S261>/Constant'
       *  DataTypeConversion: '<S261>/Data Type Conversion'
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

      /* Saturate: '<S261>/Saturation' incorporates:
       *  Bias: '<S261>/Bias3'
       *  Constant: '<S261>/Constant'
       *  DataTypeConversion: '<S261>/Data Type Conversion'
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

      /* SignalConversion: '<S256>/ConcatBufferAtVector Concatenate2In2' incorporates:
       *  Constant: '<S256>/Constant10'
       *  Constant: '<S256>/Constant11'
       *  Constant: '<S256>/Constant12'
       */
      rtb_MatrixConcatenate_g[9] = 0.0F;

      /* SignalConversion: '<S256>/ConcatBufferAtVector Concatenate2In1' incorporates:
       *  Constant: '<S256>/Constant9'
       */
      rtb_MatrixConcatenate_g[8] = 0.0F;
      rtb_MatrixConcatenate_g[7] = -CONTROL_PARAM.FW_PITCH_EFFC *
        CONTROL_PARAM.FW_TAIL2_DIR;
      rtb_MatrixConcatenate_g[6] = CONTROL_PARAM.FW_PITCH_EFFC *
        CONTROL_PARAM.FW_TAIL1_DIR;

      /* SignalConversion: '<S256>/ConcatBufferAtVector Concatenate1In2' incorporates:
       *  Constant: '<S256>/Constant6'
       *  Constant: '<S256>/Constant7'
       *  Constant: '<S256>/Constant8'
       */
      rtb_MatrixConcatenate_g[5] = 0.0F;

      /* SignalConversion: '<S256>/ConcatBufferAtVector Concatenate1In1' incorporates:
       *  Constant: '<S256>/Constant5'
       */
      rtb_MatrixConcatenate_g[4] = 0.0F;

      /* SignalConversion: '<S256>/ConcatBufferAtVector ConcatenateIn4' incorporates:
       *  Constant: '<S256>/Constant4'
       */
      rtb_MatrixConcatenate_g[3] = 0.0F;

      /* SignalConversion: '<S256>/ConcatBufferAtVector ConcatenateIn3' incorporates:
       *  Constant: '<S256>/Constant3'
       */
      rtb_MatrixConcatenate_g[2] = 0.0F;
      rtb_MatrixConcatenate_g[1] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON2_DIR;
      rtb_MatrixConcatenate_g[0] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON1_DIR;

      /* Saturate: '<S253>/Saturation5' incorporates:
       *  Constant: '<S256>/Constant1'
       *  Constant: '<S256>/Constant2'
       */
      if (Controller_B.fw_torque_cmd[0] > 1.0F) {
        /* Product: '<S253>/Multiply1' */
        tmp_m = 1.0F;
      } else if (Controller_B.fw_torque_cmd[0] < -1.0F) {
        /* Product: '<S253>/Multiply1' */
        tmp_m = -1.0F;
      } else {
        /* Product: '<S253>/Multiply1' */
        tmp_m = Controller_B.fw_torque_cmd[0];
      }

      if (Controller_B.fw_torque_cmd[1] > 1.0F) {
        /* Product: '<S253>/Multiply1' */
        tmp_ev = 1.0F;
      } else if (Controller_B.fw_torque_cmd[1] < -1.0F) {
        /* Product: '<S253>/Multiply1' */
        tmp_ev = -1.0F;
      } else {
        /* Product: '<S253>/Multiply1' */
        tmp_ev = Controller_B.fw_torque_cmd[1];
      }

      if (Controller_B.fw_torque_cmd[2] > 1.0F) {
        /* Product: '<S253>/Multiply1' */
        tmp_k = 1.0F;
      } else if (Controller_B.fw_torque_cmd[2] < -1.0F) {
        /* Product: '<S253>/Multiply1' */
        tmp_k = -1.0F;
      } else {
        /* Product: '<S253>/Multiply1' */
        tmp_k = Controller_B.fw_torque_cmd[2];
      }

      /* End of Saturate: '<S253>/Saturation5' */
      for (i_o = 0; i_o < 4; i_o++) {
        /* Bias: '<S253>/Bias' incorporates:
         *  Gain: '<S253>/Gain1'
         *  Product: '<S253>/Multiply1'
         */
        rtb_Multiply_ka[i_o] = 500.0F * (rtb_MatrixConcatenate_g[i_o + 8] *
          tmp_k + (rtb_MatrixConcatenate_g[i_o + 4] * tmp_ev +
                   rtb_MatrixConcatenate_g[i_o] * tmp_m)) + 1500.0F;
      }

      /* Saturate: '<S254>/Saturation2' */
      if (Controller_B.mc_force_cmd[2] > 1.0F) {
        tmp_gf = 1.0F;
      } else if (Controller_B.mc_force_cmd[2] < 0.0F) {
        tmp_gf = 0.0F;
      } else {
        tmp_gf = Controller_B.mc_force_cmd[2];
      }

      /* End of Saturate: '<S254>/Saturation2' */

      /* DataTypeConversion: '<S259>/Data Type Conversion' incorporates:
       *  Constant: '<S259>/Constant1'
       *  Gain: '<S259>/Gain1'
       *  Sum: '<S259>/Sum1'
       */
      rtb_DataTypeConversion_o = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
        tmp_gf), 4.2949673E+9F) + 1000U);

      /* Saturate: '<S254>/Saturation1' */
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

      /* End of Saturate: '<S254>/Saturation1' */

      /* Saturate: '<S253>/Saturation4' */
      if (Controller_B.fw_force_cmd[0] > 1.0F) {
        tmp_gf = 1.0F;
      } else if (Controller_B.fw_force_cmd[0] < 0.0F) {
        tmp_gf = 0.0F;
      } else {
        tmp_gf = Controller_B.fw_force_cmd[0];
      }

      /* End of Saturate: '<S253>/Saturation4' */

      /* Saturate: '<S253>/Saturation1' incorporates:
       *  Constant: '<S258>/Constant1'
       *  DataTypeConversion: '<S258>/Data Type Conversion'
       *  Gain: '<S258>/Gain1'
       *  Sum: '<S258>/Sum1'
       */
      tmp_o[0] = (uint16_T)((uint32_T)fmodf(floorf(1000.0F * tmp_gf),
        4.2949673E+9F) + 1000U);

      /* DataTypeConversion: '<S253>/Data Type Conversion' incorporates:
       *  Bias: '<S253>/Bias1'
       */
      tmp_gf = fmodf(floorf(rtb_Multiply_ka[0] + CONTROL_PARAM.SERVO1_BIAS),
                     65536.0F);

      /* Saturate: '<S253>/Saturation1' incorporates:
       *  DataTypeConversion: '<S253>/Data Type Conversion'
       */
      tmp_o[1] = (uint16_T)(tmp_gf < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_gf : (int32_T)(uint16_T)tmp_gf);

      /* DataTypeConversion: '<S253>/Data Type Conversion1' incorporates:
       *  Bias: '<S253>/Bias2'
       */
      tmp_gf = fmodf(floorf(rtb_Multiply_ka[1] + CONTROL_PARAM.SERVO2_BIAS),
                     65536.0F);

      /* Saturate: '<S253>/Saturation1' incorporates:
       *  DataTypeConversion: '<S253>/Data Type Conversion1'
       */
      tmp_o[2] = (uint16_T)(tmp_gf < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_gf : (int32_T)(uint16_T)tmp_gf);

      /* DataTypeConversion: '<S253>/Data Type Conversion2' incorporates:
       *  Bias: '<S253>/Bias3'
       */
      tmp_gf = fmodf(floorf(rtb_Multiply_ka[2] + CONTROL_PARAM.SERVO3_BIAS),
                     65536.0F);

      /* Saturate: '<S253>/Saturation1' incorporates:
       *  DataTypeConversion: '<S253>/Data Type Conversion2'
       */
      tmp_o[3] = (uint16_T)(tmp_gf < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_gf : (int32_T)(uint16_T)tmp_gf);

      /* DataTypeConversion: '<S253>/Data Type Conversion3' incorporates:
       *  Bias: '<S253>/Bias4'
       */
      tmp_gf = fmodf(floorf(rtb_Multiply_ka[3] + CONTROL_PARAM.SERVO4_BIAS),
                     65536.0F);

      /* Saturate: '<S253>/Saturation1' incorporates:
       *  DataTypeConversion: '<S253>/Data Type Conversion3'
       */
      tmp_o[4] = (uint16_T)(tmp_gf < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_gf : (int32_T)(uint16_T)tmp_gf);

      /* Product: '<S254>/Multiply' */
      for (i_o = 0; i_o < 4; i_o++) {
        /* Saturate: '<S254>/Saturation' incorporates:
         *  Constant: '<S254>/Effective_Matrix'
         *  Gain: '<S254>/Gain'
         *  Sum: '<S254>/Add'
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

        /* End of Saturate: '<S254>/Saturation' */
      }

      /* End of Product: '<S254>/Multiply' */
      for (i_o = 0; i_o < 5; i_o++) {
        /* Saturate: '<S253>/Saturation1' */
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

    /* End of MultiPortSwitch: '<S255>/Multiport Switch' */
  }

#endif

  /* End of Outputs for SubSystem: '<S7>/VTOL_Control_Allocation' */

  /* Outport: '<Root>/Control_Out' incorporates:
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   *  Reshape: '<S240>/Reshape'
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
  /* Start for Constant: '<S110>/Constant' */
  Controller_B.Constant_m = CONTROL_PARAM.MC_VEL_Z_I_MIN;

  /* End of Start for SubSystem: '<S2>/FW_Controller' */

  /* Start for IfAction SubSystem: '<S2>/MC_Controller' */
  /* Start for Constant: '<S237>/Constant' */
  Controller_B.Constant = CONTROL_PARAM.MC_VEL_Z_I_MIN;

  /* End of Start for SubSystem: '<S2>/MC_Controller' */

  /* SystemInitialize for IfAction SubSystem: '<S2>/FW_Controller' */
  /* InitializeConditions for DiscreteIntegrator: '<S117>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_e = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S115>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_L_eo = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S114>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_o = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S87>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S87>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S158>/ ' */
  Controller_DW._DSTATE = Controller_ConstB.Zero1;
  if (Controller_DW._DSTATE >= CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
    Controller_DW._DSTATE = CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
  } else {
    if (Controller_DW._DSTATE <= -CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
      Controller_DW._DSTATE = -CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
    }
  }

  Controller_DW._PrevResetState = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S158>/ ' */

  /* InitializeConditions for DiscreteIntegrator: '<S159>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_f = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_b = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S85>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_b = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S89>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_h = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_l = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S161>/ ' */
  Controller_DW._DSTATE_d = Controller_ConstB.Zero;
  if (Controller_DW._DSTATE_d >= CONTROL_PARAM.FW_CRUISE_THRO) {
    Controller_DW._DSTATE_d = CONTROL_PARAM.FW_CRUISE_THRO;
  } else {
    if (Controller_DW._DSTATE_d <= -CONTROL_PARAM.FW_CRUISE_THRO) {
      Controller_DW._DSTATE_d = -CONTROL_PARAM.FW_CRUISE_THRO;
    }
  }

  Controller_DW._PrevResetState_e = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S161>/ ' */

  /* InitializeConditions for DiscreteIntegrator: '<S162>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_L_h0 = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_d = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S107>/Integrator1' */
  Controller_DW.Integrator1_DSTATE_i = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S110>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S110>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S112>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_i = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_h = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S113>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_g = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S135>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_PrevR_ef = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S107>/Integrator' */
  Controller_DW.Integrator_DSTATE_f = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S135>/Discrete-Time Integrator' */
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
  /* InitializeConditions for DiscreteIntegrator: '<S189>/Discrete-Time Integrator' */
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
  /* InitializeConditions for DiscreteIntegrator: '<S135>/Discrete-Time Integrator' */
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
  /* InitializeConditions for DiscreteIntegrator: '<S189>/Discrete-Time Integrator' */
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
  /* InitializeConditions for DiscreteIntegrator: '<S135>/Discrete-Time Integrator' */
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
  /* InitializeConditions for DiscreteIntegrator: '<S189>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S216>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_PrevRe_p = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S218>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S187>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S191>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_k = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S211>/Integrator1' */
  Controller_DW.Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S216>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S211>/Integrator' */
  Controller_DW.Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S211>/Integrator1' */
  Controller_DW.Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S216>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S211>/Integrator' */
  Controller_DW.Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S234>/Integrator1' */
  Controller_DW.Integrator1_DSTATE_e = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S237>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S237>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S239>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 1U;
  Controller_DW.DiscreteTimeIntegrator1_Prev_ks = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S234>/Integrator' */
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
