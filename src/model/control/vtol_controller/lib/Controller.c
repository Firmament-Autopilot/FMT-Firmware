/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.430
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Aug 13 14:18:47 2025
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
struct_EmZSH4Jwlm4SR6cVayiT1B CONTROL_PARAM = {
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
  0.0F,
  0.785398185F
} ;                                    /* Variable: CONTROL_PARAM
                                        * Referenced by:
                                        *   '<S68>/Saturation'
                                        *   '<S69>/Gain'
                                        *   '<S69>/Gain1'
                                        *   '<S69>/balabnce_ratio2'
                                        *   '<S69>/balance_ratio'
                                        *   '<S69>/pitch_ff'
                                        *   '<S69>/thorttle_ff'
                                        *   '<S69>/ucmd2pitch'
                                        *   '<S69>/ucmd2thor'
                                        *   '<S69>/wcmd2pitch'
                                        *   '<S69>/wcmd2thor'
                                        *   '<S156>/hover_throttle'
                                        *   '<S43>/hover_throttle'
                                        *   '<S71>/FF'
                                        *   '<S71>/FF_limit'
                                        *   '<S71>/PI_limit'
                                        *   '<S89>/P_control'
                                        *   '<S90>/P_control'
                                        *   '<S91>/Kv'
                                        *   '<S138>/Saturation'
                                        *   '<S171>/Bias1'
                                        *   '<S171>/Bias2'
                                        *   '<S171>/Bias3'
                                        *   '<S171>/Bias4'
                                        *   '<S181>/Bias1'
                                        *   '<S181>/Bias2'
                                        *   '<S181>/Bias3'
                                        *   '<S181>/Bias4'
                                        *   '<S20>/Saturation'
                                        *   '<S20>/Saturation1'
                                        *   '<S75>/trim_speed'
                                        *   '<S76>/trim_speed'
                                        *   '<S80>/Saturation'
                                        *   '<S97>/Gain'
                                        *   '<S98>/ '
                                        *   '<S98>/Gain3'
                                        *   '<S100>/Gain'
                                        *   '<S101>/Gain'
                                        *   '<S114>/Saturation'
                                        *   '<S114>/Saturation1'
                                        *   '<S147>/kd'
                                        *   '<S147>/Saturation'
                                        *   '<S148>/ki'
                                        *   '<S148>/Discrete-Time Integrator'
                                        *   '<S149>/kp'
                                        *   '<S163>/kd'
                                        *   '<S163>/Saturation'
                                        *   '<S164>/Constant'
                                        *   '<S164>/ki'
                                        *   '<S164>/Discrete-Time Integrator'
                                        *   '<S165>/kp'
                                        *   '<S174>/Constant1'
                                        *   '<S174>/Constant12'
                                        *   '<S174>/Constant2'
                                        *   '<S174>/Constant7'
                                        *   '<S179>/Bias'
                                        *   '<S179>/Bias1'
                                        *   '<S179>/Bias2'
                                        *   '<S179>/Bias3'
                                        *   '<S180>/Bias'
                                        *   '<S180>/Bias1'
                                        *   '<S180>/Bias2'
                                        *   '<S180>/Bias3'
                                        *   '<S184>/Constant1'
                                        *   '<S184>/Constant11'
                                        *   '<S184>/Constant12'
                                        *   '<S184>/Constant2'
                                        *   '<S184>/Constant7'
                                        *   '<S184>/Constant8'
                                        *   '<S189>/Bias'
                                        *   '<S189>/Bias1'
                                        *   '<S189>/Bias2'
                                        *   '<S189>/Bias3'
                                        *   '<S190>/Bias'
                                        *   '<S190>/Bias1'
                                        *   '<S190>/Bias2'
                                        *   '<S190>/Bias3'
                                        *   '<S32>/Constant1'
                                        *   '<S32>/Constant2'
                                        *   '<S50>/kd'
                                        *   '<S50>/Saturation'
                                        *   '<S51>/Constant'
                                        *   '<S51>/ki'
                                        *   '<S51>/Discrete-Time Integrator'
                                        *   '<S52>/kp'
                                        *   '<S77>/gain1'
                                        *   '<S77>/gain2'
                                        *   '<S77>/gain3'
                                        *   '<S77>/Discrete-Time Integrator'
                                        *   '<S78>/gain1'
                                        *   '<S78>/gain2'
                                        *   '<S78>/gain3'
                                        *   '<S82>/Pitch Offset'
                                        *   '<S82>/Saturation'
                                        *   '<S83>/Constant1'
                                        *   '<S83>/Constant2'
                                        *   '<S131>/Constant1'
                                        *   '<S131>/Constant2'
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
                                        *   '<S120>/gain1'
                                        *   '<S120>/gain2'
                                        *   '<S120>/gain3'
                                        *   '<S120>/Saturation'
                                        *   '<S121>/gain1'
                                        *   '<S121>/gain2'
                                        *   '<S121>/gain3'
                                        *   '<S121>/Discrete-Time Integrator'
                                        *   '<S122>/gain1'
                                        *   '<S122>/gain2'
                                        *   '<S122>/gain3'
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
  boolean_T rtb_Compare_nq;
  int32_T rtb_Relay;
  boolean_T rtb_LogicalOperator_i;
  real32_T rtb_phi_cmd;
  real32_T rtb_Abs;
  real32_T rtb_Sum_l;
  real32_T rtb_DiscreteTimeIntegrator5_h5;
  real32_T rtb_VdotPg;
  real32_T rtb_Multiply1_e;
  real32_T rtb_Gain_c4;
  real32_T rtb_Add3_fc;
  boolean_T rtb_LogicalOperator_g;
  real32_T rtb_Cos_j;
  real32_T rtb_Square_d;
  real32_T rtb_MatrixConcatenate1[9];
  real32_T rtb_Multiply_ni[3];
  real32_T rtb_Saturation_g;
  int32_T i;
  real32_T rtb_MatrixConcatenate1_0[3];
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
  uint32_T tmp;
  real32_T rtb_TmpSignalConversionAtMult_3;
  real32_T rtb_DiscreteTimeIntegrator1_a_t;
  real32_T rtb_Integrator1_o_tmp;

  /* S-Function (sfix_bitop): '<S7>/Bitwise AND' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  rtb_BitwiseAND_n = (uint8_T)(Controller_U.FMS_Out.ctrl_mode & 63);

  /* SwitchCase: '<S8>/Switch Case1' incorporates:
   *  Constant: '<S164>/Constant'
   *  Constant: '<S51>/Constant'
   *  DataTypeConversion: '<S8>/Data Type Conversion'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S120>/Multiply'
   *  Product: '<S133>/Divide1'
   *  Product: '<S147>/Multiply'
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
       *  DiscreteIntegrator: '<S101>/ '
       *  DiscreteIntegrator: '<S102>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S103>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S24>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S26>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S28>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S48>/Integrator'
       *  DiscreteIntegrator: '<S48>/Integrator1'
       *  DiscreteIntegrator: '<S51>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S53>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S54>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S55>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S56>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S59>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S77>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S98>/ '
       *  DiscreteIntegrator: '<S99>/Discrete-Time Integrator1'
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
    /* SignalConversion: '<S60>/TmpSignal ConversionAtMultiplyInport2' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_TmpSignalConversionAtMult_0 = Controller_U.INS_Out.vn;
    rtb_TmpSignalConversionAtMult_1 = Controller_U.INS_Out.ve;
    rtb_TmpSignalConversionAtMult_2 = Controller_U.INS_Out.vd;

    /* Relay: '<S57>/Relay' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    if (Controller_U.INS_Out.airspeed >= 10.0F) {
      Controller_DW.Relay_Mode = true;
    } else {
      if (Controller_U.INS_Out.airspeed <= 6.0F) {
        Controller_DW.Relay_Mode = false;
      }
    }

    /* S-Function (sfix_bitop): '<S57>/vel_valid' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  S-Function (sfix_bitop): '<S92>/Bitwise AND'
     *  S-Function (sfix_bitop): '<S93>/Bitwise AND'
     *  S-Function (sfix_bitop): '<S94>/Bitwise AND'
     */
    tmp = Controller_U.INS_Out.flag & 16U;

    /* Switch: '<S57>/Switch' incorporates:
     *  Constant: '<S58>/Constant'
     *  Inport: '<Root>/INS_Out'
     *  Logic: '<S57>/Logical Operator'
     *  Logic: '<S57>/Logical Operator1'
     *  Math: '<S57>/Square2'
     *  Math: '<S57>/Square3'
     *  Product: '<S57>/Multiply'
     *  RelationalOperator: '<S58>/Compare'
     *  Relay: '<S57>/Relay'
     *  S-Function (sfix_bitop): '<S57>/airspeed_valid'
     *  S-Function (sfix_bitop): '<S57>/vel_valid'
     *  Sqrt: '<S57>/Sqrt'
     *  Sum: '<S57>/Add'
     */
    if ((Controller_DW.Relay_Mode && ((Controller_U.INS_Out.flag & 512U) != 0U))
        || (tmp == 0U)) {
      rtb_Divide_m_idx_0 = Controller_U.INS_Out.airspeed;
    } else {
      /* Sqrt: '<S66>/Sqrt' incorporates:
       *  Math: '<S66>/Square'
       *  Sum: '<S66>/Sum of Elements'
       */
      rtb_Square_d = sqrtf(((Controller_U.INS_Out.quat[0] *
        Controller_U.INS_Out.quat[0] + Controller_U.INS_Out.quat[1] *
        Controller_U.INS_Out.quat[1]) + Controller_U.INS_Out.quat[2] *
                            Controller_U.INS_Out.quat[2]) +
                           Controller_U.INS_Out.quat[3] *
                           Controller_U.INS_Out.quat[3]);

      /* Product: '<S62>/Divide' */
      rtb_Divide_m_idx_0 = Controller_U.INS_Out.quat[0] / rtb_Square_d;
      rtb_Divide_m_idx_1 = Controller_U.INS_Out.quat[1] / rtb_Square_d;
      rtb_Divide_m_idx_2 = Controller_U.INS_Out.quat[2] / rtb_Square_d;
      rtb_Divide_m_idx_3 = Controller_U.INS_Out.quat[3] / rtb_Square_d;

      /* Math: '<S65>/Square' incorporates:
       *  Math: '<S63>/Square'
       *  Math: '<S64>/Square'
       */
      rtb_Square_d = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_0;

      /* Math: '<S65>/Square2' incorporates:
       *  Math: '<S63>/Square2'
       *  Math: '<S64>/Square2'
       */
      rtb_Gain_c4 = rtb_Divide_m_idx_2 * rtb_Divide_m_idx_2;

      /* Math: '<S65>/Square1' incorporates:
       *  Math: '<S63>/Square1'
       *  Math: '<S64>/Square1'
       */
      rtb_Add3_fc = rtb_Divide_m_idx_1 * rtb_Divide_m_idx_1;

      /* Math: '<S65>/Square3' incorporates:
       *  Math: '<S63>/Square3'
       *  Math: '<S64>/Square3'
       */
      rtb_aux_att_error_B_rad_idx_0 = rtb_Divide_m_idx_3 * rtb_Divide_m_idx_3;

      /* Sum: '<S65>/Subtract' incorporates:
       *  Math: '<S65>/Square'
       *  Math: '<S65>/Square1'
       *  Math: '<S65>/Square2'
       *  Math: '<S65>/Square3'
       *  Sum: '<S65>/Add'
       *  Sum: '<S65>/Add1'
       */
      rtb_MatrixConcatenate1[8] = (rtb_Square_d + rtb_aux_att_error_B_rad_idx_0)
        - (rtb_Add3_fc + rtb_Gain_c4);

      /* Product: '<S65>/Multiply2' incorporates:
       *  Product: '<S64>/Multiply2'
       */
      rtb_aux_att_error_B_rad_idx_1 = rtb_Divide_m_idx_2 * rtb_Divide_m_idx_3;

      /* Product: '<S65>/Multiply3' incorporates:
       *  Product: '<S64>/Multiply3'
       */
      rtb_Saturation_g = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_1;

      /* Gain: '<S65>/Gain1' incorporates:
       *  Product: '<S65>/Multiply2'
       *  Product: '<S65>/Multiply3'
       *  Sum: '<S65>/Add2'
       */
      rtb_MatrixConcatenate1[7] = (rtb_aux_att_error_B_rad_idx_1 +
        rtb_Saturation_g) * 2.0F;

      /* Product: '<S65>/Multiply' incorporates:
       *  Product: '<S63>/Multiply2'
       */
      rtb_Saturation_j_idx_0 = rtb_Divide_m_idx_1 * rtb_Divide_m_idx_3;

      /* Product: '<S65>/Multiply1' incorporates:
       *  Product: '<S63>/Multiply3'
       */
      rtb_phi_cmd = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_2;

      /* Gain: '<S65>/Gain' incorporates:
       *  Product: '<S65>/Multiply'
       *  Product: '<S65>/Multiply1'
       *  Sum: '<S65>/Subtract2'
       */
      rtb_MatrixConcatenate1[6] = (rtb_Saturation_j_idx_0 - rtb_phi_cmd) * 2.0F;

      /* Gain: '<S64>/Gain1' incorporates:
       *  Sum: '<S64>/Subtract1'
       */
      rtb_MatrixConcatenate1[5] = (rtb_aux_att_error_B_rad_idx_1 -
        rtb_Saturation_g) * 2.0F;

      /* Sum: '<S64>/Subtract' incorporates:
       *  Sum: '<S64>/Add'
       *  Sum: '<S64>/Add1'
       */
      rtb_MatrixConcatenate1[4] = (rtb_Square_d + rtb_Gain_c4) - (rtb_Add3_fc +
        rtb_aux_att_error_B_rad_idx_0);

      /* Product: '<S64>/Multiply' incorporates:
       *  Product: '<S63>/Multiply'
       */
      rtb_aux_att_error_B_rad_idx_1 = rtb_Divide_m_idx_1 * rtb_Divide_m_idx_2;

      /* Product: '<S64>/Multiply1' incorporates:
       *  Product: '<S63>/Multiply1'
       */
      rtb_Saturation_g = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_3;

      /* Gain: '<S64>/Gain' incorporates:
       *  Product: '<S64>/Multiply'
       *  Product: '<S64>/Multiply1'
       *  Sum: '<S64>/Add3'
       */
      rtb_MatrixConcatenate1[3] = (rtb_aux_att_error_B_rad_idx_1 +
        rtb_Saturation_g) * 2.0F;

      /* Gain: '<S63>/Gain1' incorporates:
       *  Sum: '<S63>/Add2'
       */
      rtb_MatrixConcatenate1[2] = (rtb_Saturation_j_idx_0 + rtb_phi_cmd) * 2.0F;

      /* Gain: '<S63>/Gain' incorporates:
       *  Sum: '<S63>/Subtract1'
       */
      rtb_MatrixConcatenate1[1] = (rtb_aux_att_error_B_rad_idx_1 -
        rtb_Saturation_g) * 2.0F;

      /* Sum: '<S63>/Subtract' incorporates:
       *  Sum: '<S63>/Add'
       *  Sum: '<S63>/Add1'
       */
      rtb_MatrixConcatenate1[0] = (rtb_Square_d + rtb_Add3_fc) - (rtb_Gain_c4 +
        rtb_aux_att_error_B_rad_idx_0);

      /* Product: '<S60>/Multiply' */
      for (i = 0; i < 3; i++) {
        rtb_MatrixConcatenate1_0[i] = rtb_MatrixConcatenate1[i + 6] *
          rtb_TmpSignalConversionAtMult_2 + (rtb_MatrixConcatenate1[i + 3] *
          rtb_TmpSignalConversionAtMult_1 + rtb_MatrixConcatenate1[i] *
          rtb_TmpSignalConversionAtMult_0);
      }

      /* End of Product: '<S60>/Multiply' */

      /* Signum: '<S60>/Sign' */
      if (rtb_MatrixConcatenate1_0[0] < 0.0F) {
        rtb_Divide_m_idx_0 = -1.0F;
      } else if (rtb_MatrixConcatenate1_0[0] > 0.0F) {
        rtb_Divide_m_idx_0 = 1.0F;
      } else {
        rtb_Divide_m_idx_0 = rtb_MatrixConcatenate1_0[0];
      }

      /* End of Signum: '<S60>/Sign' */
      rtb_Divide_m_idx_0 *= sqrtf(Controller_U.INS_Out.vn *
        Controller_U.INS_Out.vn + Controller_U.INS_Out.ve *
        Controller_U.INS_Out.ve);
    }

    /* End of Switch: '<S57>/Switch' */

    /* Saturate: '<S57>/Saturation1' */
    if (rtb_Divide_m_idx_0 > 100.0F) {
      rtb_Divide_m_idx_0 = 100.0F;
    } else {
      if (rtb_Divide_m_idx_0 < 0.1F) {
        rtb_Divide_m_idx_0 = 0.1F;
      }
    }

    /* End of Saturate: '<S57>/Saturation1' */

    /* DiscreteIntegrator: '<S59>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_e != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j = rtb_Divide_m_idx_0;
    }

    /* Math: '<S10>/Square' incorporates:
     *  DiscreteIntegrator: '<S59>/Discrete-Time Integrator5'
     *  Math: '<S75>/Square1'
     *  Switch: '<S12>/Switch'
     */
    rtb_Saturation_g = Controller_DW.DiscreteTimeIntegrator5_DSTAT_j *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;

    /* Product: '<S10>/Divide' incorporates:
     *  Math: '<S10>/Square'
     */
    rtb_Divide_m_idx_1 = rtb_Saturation_g / Controller_ConstB.Square1;

    /* DiscreteIntegrator: '<S56>/Discrete-Time Integrator5' */
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

    /* DiscreteIntegrator: '<S55>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_o != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTA_a2 = (real32_T)rtb_Relay;
    }

    /* Logic: '<S16>/Logical Operator' incorporates:
     *  Constant: '<S18>/Constant'
     *  DiscreteIntegrator: '<S55>/Discrete-Time Integrator5'
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

    /* Switch: '<S81>/Switch' incorporates:
     *  Logic: '<S81>/Logical Operator'
     *  RelationalOperator: '<S86>/Compare'
     */
    if ((rtb_BitwiseAND_n == 3) || (rtb_BitwiseAND_n == 4)) {
      rtb_phi_cmd = Controller_U.FMS_Out.phi_cmd;
    } else {
      /* Trigonometry: '<S68>/Atan' incorporates:
       *  Gain: '<S68>/g_force'
       */
      rtb_phi_cmd = atanf(0.101936802F * Controller_U.FMS_Out.ay_cmd);

      /* Saturate: '<S68>/Saturation' */
      if (rtb_phi_cmd > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_phi_cmd = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_phi_cmd < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
          rtb_phi_cmd = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
        }
      }

      /* End of Saturate: '<S68>/Saturation' */
    }

    /* End of Switch: '<S81>/Switch' */

    /* Abs: '<S69>/Abs' */
    rtb_Abs = fabsf(rtb_phi_cmd);

    /* Switch: '<S93>/Switch' incorporates:
     *  Constant: '<S93>/Constant'
     */
    if (tmp > 0U) {
      /* SignalConversion: '<S96>/ConcatBufferAtVector ConcatenateIn3' */
      rtb_MatrixConcatenate1[6] = Controller_ConstB.VectorConcatenate3_g[0];
      rtb_MatrixConcatenate1[7] = Controller_ConstB.VectorConcatenate3_g[1];
      rtb_MatrixConcatenate1[8] = Controller_ConstB.VectorConcatenate3_g[2];

      /* SignalConversion: '<S96>/ConcatBufferAtVector Concatenate2In3' incorporates:
       *  Constant: '<S96>/Constant4'
       */
      rtb_MatrixConcatenate1[5] = 0.0F;

      /* Trigonometry: '<S96>/Trigonometric Function3' incorporates:
       *  Gain: '<S95>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S96>/Trigonometric Function1'
       */
      rtb_Square_d = arm_cos_f32(-Controller_U.INS_Out.psi);
      rtb_MatrixConcatenate1[4] = rtb_Square_d;

      /* Trigonometry: '<S96>/Trigonometric Function2' incorporates:
       *  Gain: '<S95>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S96>/Trigonometric Function'
       */
      rtb_Gain_c4 = arm_sin_f32(-Controller_U.INS_Out.psi);

      /* Gain: '<S96>/Gain' incorporates:
       *  Trigonometry: '<S96>/Trigonometric Function2'
       */
      rtb_MatrixConcatenate1[3] = -rtb_Gain_c4;

      /* SignalConversion: '<S96>/ConcatBufferAtVector Concatenate1In3' incorporates:
       *  Constant: '<S96>/Constant3'
       */
      rtb_MatrixConcatenate1[2] = 0.0F;

      /* Trigonometry: '<S96>/Trigonometric Function' */
      rtb_MatrixConcatenate1[1] = rtb_Gain_c4;

      /* Trigonometry: '<S96>/Trigonometric Function1' */
      rtb_MatrixConcatenate1[0] = rtb_Square_d;

      /* Product: '<S93>/Multiply' */
      for (i = 0; i < 3; i++) {
        rtb_Multiply_ni[i] = rtb_MatrixConcatenate1[i + 6] *
          rtb_TmpSignalConversionAtMult_2 + (rtb_MatrixConcatenate1[i + 3] *
          rtb_TmpSignalConversionAtMult_1 + rtb_MatrixConcatenate1[i] *
          rtb_TmpSignalConversionAtMult_0);
      }

      /* End of Product: '<S93>/Multiply' */

      /* DeadZone: '<S93>/Dead Zone' */
      if (rtb_Multiply_ni[0] > 1.0F) {
        rtb_Sum_l = rtb_Multiply_ni[0] - 1.0F;
      } else if (rtb_Multiply_ni[0] >= -1.0F) {
        rtb_Sum_l = 0.0F;
      } else {
        rtb_Sum_l = rtb_Multiply_ni[0] - -1.0F;
      }

      /* End of DeadZone: '<S93>/Dead Zone' */

      /* Signum: '<S93>/Sign' */
      if (rtb_Sum_l < 0.0F) {
        rtb_Sum_l = -1.0F;
      } else {
        if (rtb_Sum_l > 0.0F) {
          rtb_Sum_l = 1.0F;
        }
      }

      /* End of Signum: '<S93>/Sign' */
    } else {
      rtb_Sum_l = 1.0F;
    }

    /* End of Switch: '<S93>/Switch' */

    /* Switch: '<S92>/Switch' incorporates:
     *  Gain: '<S92>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S92>/Divide'
     *  Trigonometry: '<S92>/Asin'
     */
    if (tmp > 1U) {
      /* Sqrt: '<S92>/Sqrt' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Math: '<S92>/Square'
       *  Math: '<S92>/Square1'
       *  Sum: '<S92>/Add'
       */
      rtb_Add3_fc = sqrtf(Controller_U.INS_Out.vn * Controller_U.INS_Out.vn +
                          Controller_U.INS_Out.ve * Controller_U.INS_Out.ve);

      /* Saturate: '<S92>/Saturation' incorporates:
       *  Sqrt: '<S92>/Sqrt'
       */
      if (rtb_Add3_fc > 100.0F) {
        rtb_Add3_fc = 100.0F;
      } else {
        if (rtb_Add3_fc < 8.0F) {
          rtb_Add3_fc = 8.0F;
        }
      }

      /* End of Saturate: '<S92>/Saturation' */

      /* DeadZone: '<S92>/Dead Zone' incorporates:
       *  Inport: '<Root>/INS_Out'
       */
      if (Controller_U.INS_Out.vd > 0.1F) {
        rtb_Saturation_j_idx_1 = Controller_U.INS_Out.vd - 0.1F;
      } else if (Controller_U.INS_Out.vd >= -0.1F) {
        rtb_Saturation_j_idx_1 = 0.0F;
      } else {
        rtb_Saturation_j_idx_1 = Controller_U.INS_Out.vd - -0.1F;
      }

      /* End of DeadZone: '<S92>/Dead Zone' */
      rtb_DiscreteTimeIntegrator5_h5 = atanf(1.0F / rtb_Add3_fc *
        -rtb_Saturation_j_idx_1);
    } else {
      rtb_DiscreteTimeIntegrator5_h5 = Controller_U.INS_Out.theta;
    }

    /* End of Switch: '<S92>/Switch' */

    /* Product: '<S92>/Multiply1' */
    rtb_DiscreteTimeIntegrator5_h5 *= rtb_Sum_l;

    /* Saturate: '<S92>/Saturation1' */
    if (rtb_DiscreteTimeIntegrator5_h5 > 0.785398185F) {
      rtb_DiscreteTimeIntegrator5_h5 = 0.785398185F;
    } else {
      if (rtb_DiscreteTimeIntegrator5_h5 < -0.785398185F) {
        rtb_DiscreteTimeIntegrator5_h5 = -0.785398185F;
      }
    }

    /* End of Saturate: '<S92>/Saturation1' */

    /* DiscreteIntegrator: '<S103>/Discrete-Time Integrator5' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_n != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_f = Controller_U.INS_Out.ax;
    }

    /* Gain: '<S91>/Gain1' incorporates:
     *  DiscreteIntegrator: '<S103>/Discrete-Time Integrator5'
     */
    rtb_VdotPg = 0.101936802F * Controller_DW.DiscreteTimeIntegrator5_DSTAT_f;

    /* Switch: '<S94>/Switch' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Math: '<S94>/Square'
     *  Math: '<S94>/Square1'
     *  Sqrt: '<S94>/Sqrt'
     *  Sum: '<S94>/Add'
     */
    if (tmp > 0U) {
      rtb_Multiply1_e = sqrtf(Controller_U.INS_Out.vn * Controller_U.INS_Out.vn
        + Controller_U.INS_Out.ve * Controller_U.INS_Out.ve);
    } else {
      rtb_Multiply1_e = Controller_U.INS_Out.airspeed;
    }

    /* End of Switch: '<S94>/Switch' */

    /* Saturate: '<S94>/Saturation1' */
    if (rtb_Multiply1_e > 100.0F) {
      rtb_Multiply1_e = 100.0F;
    } else {
      if (rtb_Multiply1_e < 8.0F) {
        rtb_Multiply1_e = 8.0F;
      }
    }

    /* End of Saturate: '<S94>/Saturation1' */

    /* Product: '<S94>/Multiply1' incorporates:
     *  Gain: '<S94>/Gain'
     *  Product: '<S94>/Divide'
     *  Trigonometry: '<S94>/Asin'
     */
    rtb_Sum_l *= atanf(-Controller_U.FMS_Out.w_cmd / rtb_Multiply1_e);

    /* Saturate: '<S94>/Saturation2' */
    if (rtb_Sum_l > 0.785398185F) {
      rtb_Sum_l = 0.785398185F;
    } else {
      if (rtb_Sum_l < -0.785398185F) {
        rtb_Sum_l = -0.785398185F;
      }
    }

    /* End of Saturate: '<S94>/Saturation2' */

    /* Sum: '<S88>/Sum' */
    rtb_Sum_l -= rtb_DiscreteTimeIntegrator5_h5;

    /* Sum: '<S91>/Sum' incorporates:
     *  DiscreteIntegrator: '<S59>/Discrete-Time Integrator5'
     *  Gain: '<S91>/Gain'
     *  Gain: '<S91>/Kv'
     *  Sum: '<S91>/Minus'
     */
    rtb_Multiply1_e = (Controller_U.FMS_Out.u_cmd -
                       Controller_DW.DiscreteTimeIntegrator5_DSTAT_j) *
      CONTROL_PARAM.FW_TECS_VEL_P * 0.101936802F - rtb_VdotPg;

    /* Sum: '<S69>/Minus1' incorporates:
     *  Gain: '<S69>/ucmd2pitch'
     *  Gain: '<S69>/wcmd2pitch'
     */
    rtb_Square_d = CONTROL_PARAM.FW_TECS_W2P * rtb_Sum_l -
      CONTROL_PARAM.FW_TECS_U2P * rtb_Multiply1_e;

    /* DiscreteIntegrator: '<S98>/ ' */
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

    /* DiscreteIntegrator: '<S99>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_f != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_e = rtb_Square_d;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_b != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_e = rtb_Square_d;
    }

    /* Gain: '<S99>/Gain' incorporates:
     *  DiscreteIntegrator: '<S99>/Discrete-Time Integrator1'
     *  Sum: '<S99>/Sum5'
     */
    rtb_Gain_c4 = (rtb_Square_d - Controller_DW.DiscreteTimeIntegrator1_DSTAT_e)
      * 62.831852F;

    /* Switch: '<S81>/Switch1' incorporates:
     *  Constant: '<S87>/Constant'
     *  DiscreteIntegrator: '<S98>/ '
     *  Gain: '<S69>/Gain'
     *  Gain: '<S69>/balabnce_ratio2'
     *  Gain: '<S69>/balance_ratio'
     *  Gain: '<S69>/pitch_ff'
     *  Gain: '<S89>/P_control'
     *  RelationalOperator: '<S87>/Compare'
     *  Sum: '<S69>/Add3'
     *  Sum: '<S69>/Minus'
     *  Sum: '<S69>/Sum'
     *  Sum: '<S89>/Add'
     *  Switch: '<S99>/Switch'
     */
    if (rtb_BitwiseAND_n == 3) {
      rtb_Cos_j = Controller_U.FMS_Out.theta_cmd;
    } else {
      if (Controller_U.FMS_Out.reset > 0) {
        /* Switch: '<S99>/Switch' incorporates:
         *  Gain: '<S99>/Gain1'
         */
        rtb_Saturation_j_idx_1 = 0.0F;
      } else {
        /* Switch: '<S99>/Switch' */
        rtb_Saturation_j_idx_1 = rtb_Gain_c4;
      }

      /* Gain: '<S97>/Gain' */
      rtb_TmpSignalConversionAtMult_0 = CONTROL_PARAM.FW_TECS_PITCH_D *
        rtb_Saturation_j_idx_1;

      /* Saturate: '<S89>/Saturation1' */
      if (rtb_TmpSignalConversionAtMult_0 > 0.3F) {
        rtb_TmpSignalConversionAtMult_0 = 0.3F;
      } else {
        if (rtb_TmpSignalConversionAtMult_0 < -0.3F) {
          rtb_TmpSignalConversionAtMult_0 = -0.3F;
        }
      }

      /* End of Saturate: '<S89>/Saturation1' */
      rtb_Cos_j = (((2.0F - CONTROL_PARAM.FW_TECS_RATIO) *
                    rtb_DiscreteTimeIntegrator5_h5 - CONTROL_PARAM.FW_TECS_RATIO
                    * rtb_VdotPg) * CONTROL_PARAM.FW_TECS_PITCH_F +
                   ((CONTROL_PARAM.FW_TECS_PITCH_P * rtb_Square_d +
                     Controller_DW._DSTATE) + rtb_TmpSignalConversionAtMult_0))
        + CONTROL_PARAM.FW_TECS_R2P * rtb_Abs;
    }

    /* End of Switch: '<S81>/Switch1' */

    /* Sum: '<S31>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_aux_att_error_B_rad_idx_0 = rtb_phi_cmd - Controller_U.INS_Out.phi;
    rtb_aux_att_error_B_rad_idx_1 = rtb_Cos_j - Controller_U.INS_Out.theta;

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
     *  Trigonometry: '<S73>/Sin'
     */
    rtb_aux_att_error_B_rad_idx_1 = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S29>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S73>/Cos1'
     */
    rtb_DiscreteTimeIntegrator1_a_t = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Trigonometry: '<S29>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S73>/Cos'
     */
    rtb_Integrator1_o_tmp = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S29>/Sin1' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S73>/Sin1'
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
    rtb_Multiply_ni[0] = (Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0] -
                          Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[0]) *
      188.49556F;
    rtb_Multiply_ni[1] = (Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1] -
                          Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[1]) *
      188.49556F;
    rtb_Multiply_ni[2] = (Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2] -
                          Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[2]) *
      188.49556F;

    /* RelationalOperator: '<S105>/Compare' incorporates:
     *  Constant: '<S105>/Constant'
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
        rtb_Saturation_j_idx_0 = rtb_Multiply_ni[0];
        rtb_Saturation_j_idx_1 = rtb_Multiply_ni[1];
        rtb_Saturation_j_idx_2 = rtb_Multiply_ni[2];
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
       *  DiscreteIntegrator: '<S55>/Discrete-Time Integrator5'
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
       *  DiscreteIntegrator: '<S55>/Discrete-Time Integrator5'
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
       *  DiscreteIntegrator: '<S55>/Discrete-Time Integrator5'
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

    /* Sum: '<S69>/Add' incorporates:
     *  Gain: '<S69>/ucmd2thor'
     *  Gain: '<S69>/wcmd2thor'
     */
    rtb_Divide_m_idx_3 = CONTROL_PARAM.FW_TECS_W2T * rtb_Sum_l +
      CONTROL_PARAM.FW_TECS_U2T * rtb_Multiply1_e;

    /* DiscreteIntegrator: '<S101>/ ' */
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

    /* DiscreteIntegrator: '<S102>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_L_h0 != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm = rtb_Divide_m_idx_3;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_d != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm = rtb_Divide_m_idx_3;
    }

    /* Gain: '<S102>/Gain' incorporates:
     *  DiscreteIntegrator: '<S102>/Discrete-Time Integrator1'
     *  Sum: '<S102>/Sum5'
     */
    rtb_aux_att_error_B_rad_idx_0 = (rtb_Divide_m_idx_3 -
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm) * 188.49556F;

    /* Switch: '<S12>/Switch' incorporates:
     *  Constant: '<S104>/Constant'
     *  Constant: '<S106>/Constant2'
     *  Constant: '<S70>/Constant'
     *  RelationalOperator: '<S104>/Compare'
     *  Saturate: '<S70>/Saturation2'
     *  Switch: '<S102>/Switch'
     *  Switch: '<S70>/Switch'
     */
    if (rtb_Compare_nq) {
      Controller_B.fw_force_cmd[0] = Controller_U.FMS_Out.u_cmd;
      Controller_B.fw_force_cmd[1] = 0.0F;
      Controller_B.fw_force_cmd[2] = 0.0F;
    } else {
      if (rtb_BitwiseAND_n <= 3) {
        /* Switch: '<S70>/Switch' incorporates:
         *  Bias: '<S70>/Bias'
         *  Gain: '<S70>/Gain'
         */
        rtb_Add3_fc = 0.000999987125F * (real32_T)
          Controller_U.FMS_Out.throttle_cmd + -1.0F;
      } else {
        if (Controller_U.FMS_Out.reset > 0) {
          /* Switch: '<S102>/Switch' incorporates:
           *  Gain: '<S102>/Gain1'
           *  Switch: '<S70>/Switch'
           */
          rtb_Saturation_j_idx_1 = 0.0F;
        } else {
          /* Switch: '<S102>/Switch' incorporates:
           *  Switch: '<S70>/Switch'
           */
          rtb_Saturation_j_idx_1 = rtb_aux_att_error_B_rad_idx_0;
        }

        /* Gain: '<S100>/Gain' incorporates:
         *  Switch: '<S70>/Switch'
         */
        rtb_Add3_fc = CONTROL_PARAM.FW_TECS_THOR_D * rtb_Saturation_j_idx_1;

        /* Saturate: '<S90>/Saturation1' incorporates:
         *  Switch: '<S70>/Switch'
         */
        if (rtb_Add3_fc > 0.3F) {
          rtb_Add3_fc = 0.3F;
        } else {
          if (rtb_Add3_fc < -0.3F) {
            rtb_Add3_fc = -0.3F;
          }
        }

        /* End of Saturate: '<S90>/Saturation1' */

        /* Sum: '<S69>/Sum1' incorporates:
         *  DiscreteIntegrator: '<S101>/ '
         *  Gain: '<S69>/Gain1'
         *  Gain: '<S69>/thorttle_ff'
         *  Gain: '<S90>/P_control'
         *  Sum: '<S69>/Add1'
         *  Sum: '<S69>/Add2'
         *  Sum: '<S90>/Add4'
         *  Switch: '<S70>/Switch'
         */
        rtb_Add3_fc = (((CONTROL_PARAM.FW_TECS_THOR_P * rtb_Divide_m_idx_3 +
                         Controller_DW._DSTATE_d) + rtb_Add3_fc) +
                       (rtb_DiscreteTimeIntegrator5_h5 + rtb_VdotPg) *
                       CONTROL_PARAM.FW_TECS_THOR_FF) +
          CONTROL_PARAM.FW_TECS_R2T * rtb_Abs;

        /* Saturate: '<S70>/Saturation' incorporates:
         *  Switch: '<S70>/Switch'
         */
        if (rtb_Add3_fc > 1.0F) {
          rtb_Add3_fc = 1.0F;
        } else {
          if (rtb_Add3_fc < -1.0F) {
            rtb_Add3_fc = -1.0F;
          }
        }

        /* End of Saturate: '<S70>/Saturation' */
      }

      /* Saturate: '<S70>/Saturation2' incorporates:
       *  Switch: '<S102>/Switch'
       *  Switch: '<S70>/Switch'
       */
      if (rtb_Add3_fc > 1.0F) {
        Controller_B.fw_force_cmd[0] = 1.0F;
      } else {
        Controller_B.fw_force_cmd[0] = rtb_Add3_fc;
      }

      Controller_B.fw_force_cmd[1] = 0.0F;
      Controller_B.fw_force_cmd[2] = 0.0F;
    }

    /* Gain: '<S46>/Gain' incorporates:
     *  DiscreteIntegrator: '<S48>/Integrator1'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S46>/Sum1'
     */
    rtb_Abs = -(Controller_DW.Integrator1_DSTATE_i - Controller_U.INS_Out.vd);

    /* Logic: '<S43>/Logical Operator' incorporates:
     *  Constant: '<S45>/Constant'
     *  DiscreteIntegrator: '<S55>/Discrete-Time Integrator5'
     *  RelationalOperator: '<S45>/Compare'
     */
    rtb_LogicalOperator_g = ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator5_DSTA_a2 == 0.0F));
    Controller_B.Constant_m = CONTROL_PARAM.MC_VEL_Z_I_MIN;

    /* DiscreteIntegrator: '<S51>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S51>/Constant'
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

    /* DiscreteIntegrator: '<S53>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_i != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_l = rtb_Abs;
    }

    if (rtb_LogicalOperator_g || (Controller_DW.DiscreteTimeIntegrator1_PrevR_h
         != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_l = rtb_Abs;
    }

    /* Gain: '<S53>/Gain' incorporates:
     *  DiscreteIntegrator: '<S53>/Discrete-Time Integrator1'
     *  Sum: '<S53>/Sum5'
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
      /* Product: '<S44>/Multiply' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S44>/Cos'
       *  Trigonometry: '<S44>/Cos1'
       */
      rtb_Saturation_j_idx_1 = arm_cos_f32(Controller_U.INS_Out.phi) *
        arm_cos_f32(Controller_U.INS_Out.theta);

      /* Gain: '<S44>/Gain' */
      rtb_Add3_fc = 2.0F * rtb_Saturation_j_idx_1;

      /* Saturate: '<S44>/Saturation1' */
      if (rtb_Saturation_j_idx_1 > 1.0F) {
        rtb_Saturation_j_idx_1 = 1.0F;
      } else {
        if (rtb_Saturation_j_idx_1 < 0.5F) {
          rtb_Saturation_j_idx_1 = 0.5F;
        }
      }

      /* End of Saturate: '<S44>/Saturation1' */

      /* Product: '<S44>/Divide' incorporates:
       *  Constant: '<S44>/Constant'
       */
      rtb_Saturation_j_idx_0 = 1.0F / rtb_Saturation_j_idx_1;

      /* Switch: '<S53>/Switch' incorporates:
       *  Gain: '<S53>/Gain1'
       */
      if (rtb_LogicalOperator_g) {
        rtb_Saturation_j_idx_1 = 0.0F;
      } else {
        rtb_Saturation_j_idx_1 = rtb_DiscreteTimeIntegrator5_h5;
      }

      /* End of Switch: '<S53>/Switch' */

      /* Product: '<S50>/Multiply' incorporates:
       *  Constant: '<S50>/kd'
       */
      rtb_Saturation_j_idx_1 *= CONTROL_PARAM.MC_VEL_Z_D;

      /* Saturate: '<S50>/Saturation' */
      if (rtb_Saturation_j_idx_1 > CONTROL_PARAM.MC_VEL_Z_D_MAX) {
        rtb_Saturation_j_idx_1 = CONTROL_PARAM.MC_VEL_Z_D_MAX;
      } else {
        if (rtb_Saturation_j_idx_1 < CONTROL_PARAM.MC_VEL_Z_D_MIN) {
          rtb_Saturation_j_idx_1 = CONTROL_PARAM.MC_VEL_Z_D_MIN;
        }
      }

      /* End of Saturate: '<S50>/Saturation' */

      /* Saturate: '<S44>/Saturation' */
      if (rtb_Add3_fc > 1.0F) {
        rtb_Add3_fc = 1.0F;
      } else {
        if (rtb_Add3_fc < 0.0F) {
          rtb_Add3_fc = 0.0F;
        }
      }

      /* End of Saturate: '<S44>/Saturation' */

      /* Product: '<S44>/Multiply1' incorporates:
       *  Constant: '<S52>/kp'
       *  DiscreteIntegrator: '<S51>/Discrete-Time Integrator'
       *  Product: '<S52>/Multiply'
       *  Sum: '<S47>/Add'
       */
      rtb_Add3_fc *= ((CONTROL_PARAM.MC_VEL_Z_P * rtb_Abs +
                       Controller_DW.DiscreteTimeIntegrator_DSTATE_b) +
                      rtb_Saturation_j_idx_1) * rtb_Saturation_j_idx_0;

      /* Saturate: '<S43>/Saturation' */
      if (rtb_Add3_fc > 0.35F) {
        rtb_Add3_fc = 0.35F;
      } else {
        if (rtb_Add3_fc < -0.35F) {
          rtb_Add3_fc = -0.35F;
        }
      }

      /* End of Saturate: '<S43>/Saturation' */

      /* Sum: '<S43>/Sum1' incorporates:
       *  Constant: '<S43>/hover_throttle'
       */
      rtb_Add3_fc += CONTROL_PARAM.MC_HOVER_THRO;
      Controller_B.mc_force_cmd[0] = 0.0F;
      Controller_B.mc_force_cmd[1] = 0.0F;

      /* Product: '<S9>/Multiply1' incorporates:
       *  Constant: '<S15>/Constant'
       *  DiscreteIntegrator: '<S55>/Discrete-Time Integrator5'
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

    /* DiscreteIntegrator: '<S54>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_g != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTA_jo = rtb_Divide_m_idx_2;
    }

    /* Bias: '<S82>/Pitch Offset' */
    rtb_Add3_fc = rtb_Cos_j + CONTROL_PARAM.FW_PITCH_OFFSET;

    /* Saturate: '<S82>/Saturation' */
    if (rtb_Add3_fc > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Add3_fc = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_Add3_fc < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_Add3_fc = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      }
    }

    /* Product: '<S83>/Multiply' incorporates:
     *  Constant: '<S83>/Constant2'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S82>/Sum'
     */
    rtb_Saturation_j_idx_0 = (rtb_Add3_fc - Controller_U.INS_Out.theta) *
      CONTROL_PARAM.FW_PITCH_P;

    /* Product: '<S85>/Divide' incorporates:
     *  Constant: '<S85>/Constant'
     *  DiscreteIntegrator: '<S59>/Discrete-Time Integrator5'
     */
    rtb_Add3_fc = 9.81F / Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;

    /* Saturate: '<S85>/Saturation' */
    if (rtb_Add3_fc > 1.0F) {
      rtb_Add3_fc = 1.0F;
    } else {
      if (rtb_Add3_fc < 0.2F) {
        rtb_Add3_fc = 0.2F;
      }
    }

    /* End of Saturate: '<S85>/Saturation' */

    /* Sum: '<S80>/Sum' incorporates:
     *  Product: '<S85>/Multiply'
     *  Product: '<S85>/Multiply1'
     *  Trigonometry: '<S85>/Cos'
     *  Trigonometry: '<S85>/Tan'
     */
    rtb_Add3_fc = tanf(rtb_phi_cmd) * arm_cos_f32(rtb_Cos_j) * rtb_Add3_fc +
      Controller_U.FMS_Out.psi_rate_cmd;

    /* Saturate: '<S80>/Saturation' */
    if (rtb_Add3_fc > CONTROL_PARAM.FW_YAW_RATE_LIM) {
      rtb_Add3_fc = CONTROL_PARAM.FW_YAW_RATE_LIM;
    } else {
      if (rtb_Add3_fc < -CONTROL_PARAM.FW_YAW_RATE_LIM) {
        rtb_Add3_fc = -CONTROL_PARAM.FW_YAW_RATE_LIM;
      }
    }

    /* End of Saturate: '<S80>/Saturation' */

    /* Saturate: '<S82>/Saturation' */
    if (rtb_phi_cmd > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_phi_cmd = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_phi_cmd < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_phi_cmd = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      }
    }

    /* Sum: '<S73>/Add' incorporates:
     *  Constant: '<S83>/Constant1'
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S73>/Multiply'
     *  Product: '<S83>/Multiply'
     *  Sum: '<S82>/Sum'
     */
    rtb_Cos_j = (rtb_phi_cmd - Controller_U.INS_Out.phi) *
      CONTROL_PARAM.FW_ROLL_P - rtb_TmpSignalConversionAtMult_3 * rtb_Add3_fc;

    /* Sum: '<S73>/Add1' incorporates:
     *  Product: '<S73>/Multiply1'
     *  Product: '<S73>/Multiply3'
     */
    rtb_phi_cmd = rtb_aux_att_error_B_rad_idx_1 *
      rtb_DiscreteTimeIntegrator1_a_t * rtb_Add3_fc + rtb_Integrator1_o_tmp *
      rtb_Saturation_j_idx_0;

    /* Sum: '<S73>/Add2' incorporates:
     *  Product: '<S73>/Multiply4'
     *  Product: '<S73>/Multiply5'
     */
    rtb_aux_att_error_B_rad_idx_1 = rtb_Integrator1_o_tmp *
      rtb_DiscreteTimeIntegrator1_a_t * rtb_Add3_fc -
      rtb_aux_att_error_B_rad_idx_1 * rtb_Saturation_j_idx_0;

    /* Sum: '<S71>/Minus2' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Saturation_j_idx_0 = rtb_Cos_j - Controller_U.INS_Out.p;
    rtb_Saturation_j_idx_1 = rtb_phi_cmd - Controller_U.INS_Out.q;
    rtb_Saturation_j_idx_2 = rtb_aux_att_error_B_rad_idx_1 -
      Controller_U.INS_Out.r;

    /* DiscreteIntegrator: '<S77>/Discrete-Time Integrator' */
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
      /* Product: '<S75>/Divide' incorporates:
       *  Constant: '<S75>/trim_speed'
       *  Math: '<S75>/Square'
       */
      rtb_Saturation_g = CONTROL_PARAM.FW_AIRSPEED_TRIM *
        CONTROL_PARAM.FW_AIRSPEED_TRIM / rtb_Saturation_g;

      /* Saturate: '<S75>/Saturation' */
      if (rtb_Saturation_g > 1.0F) {
        rtb_Saturation_g = 1.0F;
      } else {
        if (rtb_Saturation_g < 0.0F) {
          rtb_Saturation_g = 0.0F;
        }
      }

      /* End of Saturate: '<S75>/Saturation' */

      /* Product: '<S71>/Multiply' incorporates:
       *  Constant: '<S78>/gain1'
       *  Constant: '<S78>/gain2'
       *  Constant: '<S78>/gain3'
       *  DiscreteIntegrator: '<S77>/Discrete-Time Integrator'
       *  Product: '<S78>/Multiply'
       *  Sum: '<S74>/Add1'
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

      /* Product: '<S76>/Divide' incorporates:
       *  Constant: '<S76>/trim_speed'
       *  DiscreteIntegrator: '<S59>/Discrete-Time Integrator5'
       */
      rtb_Saturation_g = CONTROL_PARAM.FW_AIRSPEED_TRIM /
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;

      /* Saturate: '<S76>/Saturation' */
      if (rtb_Saturation_g > 1.0F) {
        rtb_Saturation_g = 1.0F;
      } else {
        if (rtb_Saturation_g < 0.0F) {
          rtb_Saturation_g = 0.0F;
        }
      }

      /* End of Saturate: '<S76>/Saturation' */

      /* Product: '<S71>/Multiply1' incorporates:
       *  Gain: '<S71>/FF'
       */
      rtb_Cos_j = CONTROL_PARAM.FW_FF * rtb_Cos_j * rtb_Saturation_g;

      /* Saturate: '<S71>/FF_limit' */
      if (rtb_Cos_j > CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_Cos_j = CONTROL_PARAM.FW_FF_LIMIT;
      } else {
        if (rtb_Cos_j < -CONTROL_PARAM.FW_FF_LIMIT) {
          rtb_Cos_j = -CONTROL_PARAM.FW_FF_LIMIT;
        }
      }

      /* Saturate: '<S71>/PI_limit' */
      if (rtb_Add3_fc > CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_Add3_fc = CONTROL_PARAM.FW_PI_LIMIT;
      } else {
        if (rtb_Add3_fc < -CONTROL_PARAM.FW_PI_LIMIT) {
          rtb_Add3_fc = -CONTROL_PARAM.FW_PI_LIMIT;
        }
      }

      /* Product: '<S11>/Multiply' incorporates:
       *  DiscreteIntegrator: '<S54>/Discrete-Time Integrator5'
       *  Sum: '<S71>/Add'
       */
      rtb_Add3_fc = (rtb_Cos_j + rtb_Add3_fc) *
        Controller_DW.DiscreteTimeIntegrator5_DSTA_jo;

      /* Saturate: '<S11>/Saturation1' */
      if (rtb_Add3_fc > 1.0F) {
        Controller_B.fw_torque_cmd[0] = 1.0F;
      } else if (rtb_Add3_fc < -1.0F) {
        Controller_B.fw_torque_cmd[0] = -1.0F;
      } else {
        Controller_B.fw_torque_cmd[0] = rtb_Add3_fc;
      }

      /* Product: '<S71>/Multiply1' incorporates:
       *  Gain: '<S71>/FF'
       */
      rtb_Add3_fc = CONTROL_PARAM.FW_FF * rtb_phi_cmd * rtb_Saturation_g;

      /* Saturate: '<S71>/FF_limit' */
      if (rtb_Add3_fc > CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_Add3_fc = CONTROL_PARAM.FW_FF_LIMIT;
      } else {
        if (rtb_Add3_fc < -CONTROL_PARAM.FW_FF_LIMIT) {
          rtb_Add3_fc = -CONTROL_PARAM.FW_FF_LIMIT;
        }
      }

      /* Saturate: '<S71>/PI_limit' */
      if (rtb_DiscreteTimeIntegrator1_a_t > CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_DiscreteTimeIntegrator1_a_t = CONTROL_PARAM.FW_PI_LIMIT;
      } else {
        if (rtb_DiscreteTimeIntegrator1_a_t < -CONTROL_PARAM.FW_PI_LIMIT) {
          rtb_DiscreteTimeIntegrator1_a_t = -CONTROL_PARAM.FW_PI_LIMIT;
        }
      }

      /* Product: '<S11>/Multiply' incorporates:
       *  DiscreteIntegrator: '<S54>/Discrete-Time Integrator5'
       *  Sum: '<S71>/Add'
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

      /* Product: '<S71>/Multiply1' incorporates:
       *  Gain: '<S71>/FF'
       */
      rtb_Add3_fc = CONTROL_PARAM.FW_FF * rtb_aux_att_error_B_rad_idx_1 *
        rtb_Saturation_g;

      /* Saturate: '<S71>/FF_limit' */
      if (rtb_Add3_fc > CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_Add3_fc = CONTROL_PARAM.FW_FF_LIMIT;
      } else {
        if (rtb_Add3_fc < -CONTROL_PARAM.FW_FF_LIMIT) {
          rtb_Add3_fc = -CONTROL_PARAM.FW_FF_LIMIT;
        }
      }

      /* Saturate: '<S71>/PI_limit' */
      if (rtb_Integrator1_o_tmp > CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_Integrator1_o_tmp = CONTROL_PARAM.FW_PI_LIMIT;
      } else {
        if (rtb_Integrator1_o_tmp < -CONTROL_PARAM.FW_PI_LIMIT) {
          rtb_Integrator1_o_tmp = -CONTROL_PARAM.FW_PI_LIMIT;
        }
      }

      /* Product: '<S11>/Multiply' incorporates:
       *  DiscreteIntegrator: '<S54>/Discrete-Time Integrator5'
       *  Sum: '<S71>/Add'
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

    /* Product: '<S49>/Multiply1' incorporates:
     *  Constant: '<S49>/const1'
     *  DiscreteIntegrator: '<S48>/Integrator'
     */
    rtb_Add3_fc = Controller_DW.Integrator_DSTATE_f * 0.05F;

    /* Sum: '<S49>/Add' incorporates:
     *  DiscreteIntegrator: '<S48>/Integrator1'
     *  Sum: '<S48>/Subtract'
     */
    rtb_Saturation_g = (Controller_DW.Integrator1_DSTATE_i -
                        Controller_U.FMS_Out.w_cmd) + rtb_Add3_fc;

    /* Signum: '<S49>/Sign' */
    if (rtb_Saturation_g < 0.0F) {
      rtb_aux_att_error_B_rad_idx_1 = -1.0F;
    } else if (rtb_Saturation_g > 0.0F) {
      rtb_aux_att_error_B_rad_idx_1 = 1.0F;
    } else {
      rtb_aux_att_error_B_rad_idx_1 = rtb_Saturation_g;
    }

    /* End of Signum: '<S49>/Sign' */

    /* Sum: '<S49>/Add2' incorporates:
     *  Abs: '<S49>/Abs'
     *  Gain: '<S49>/Gain'
     *  Gain: '<S49>/Gain1'
     *  Product: '<S49>/Multiply2'
     *  Product: '<S49>/Multiply3'
     *  Sqrt: '<S49>/Sqrt'
     *  Sum: '<S49>/Add1'
     *  Sum: '<S49>/Subtract'
     */
    rtb_aux_att_error_B_rad_idx_1 = (sqrtf((8.0F * fabsf(rtb_Saturation_g) +
      Controller_ConstB.d_m) * Controller_ConstB.d_m) - Controller_ConstB.d_m) *
      0.5F * rtb_aux_att_error_B_rad_idx_1 + rtb_Add3_fc;

    /* Sum: '<S49>/Add4' */
    rtb_phi_cmd = (rtb_Saturation_g - rtb_aux_att_error_B_rad_idx_1) +
      rtb_Add3_fc;

    /* Sum: '<S49>/Add3' */
    rtb_Add3_fc = rtb_Saturation_g + Controller_ConstB.d_m;

    /* Sum: '<S49>/Subtract1' */
    rtb_Saturation_g -= Controller_ConstB.d_m;

    /* Signum: '<S49>/Sign1' */
    if (rtb_Add3_fc < 0.0F) {
      rtb_Add3_fc = -1.0F;
    } else {
      if (rtb_Add3_fc > 0.0F) {
        rtb_Add3_fc = 1.0F;
      }
    }

    /* End of Signum: '<S49>/Sign1' */

    /* Signum: '<S49>/Sign2' */
    if (rtb_Saturation_g < 0.0F) {
      rtb_Saturation_g = -1.0F;
    } else {
      if (rtb_Saturation_g > 0.0F) {
        rtb_Saturation_g = 1.0F;
      }
    }

    /* End of Signum: '<S49>/Sign2' */

    /* Sum: '<S49>/Add5' incorporates:
     *  Gain: '<S49>/Gain2'
     *  Product: '<S49>/Multiply4'
     *  Sum: '<S49>/Subtract2'
     */
    rtb_aux_att_error_B_rad_idx_1 += (rtb_Add3_fc - rtb_Saturation_g) * 0.5F *
      rtb_phi_cmd;

    /* Update for DiscreteIntegrator: '<S59>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S59>/Gain'
     *  Sum: '<S59>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_e = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_j += (rtb_Divide_m_idx_0 -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j) * 125.663704F * 0.002F;

    /* Update for DiscreteIntegrator: '<S56>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S56>/Gain'
     *  Sum: '<S56>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_L_eo = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_a += (rtb_Divide_m_idx_1 -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_a) * 31.415926F * 0.002F;

    /* Update for DiscreteIntegrator: '<S55>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S55>/Gain'
     *  Sum: '<S55>/Sum5'
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

    /* Update for DiscreteIntegrator: '<S103>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S103>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S103>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_n = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_f += (Controller_U.INS_Out.ax -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_f) * 31.415926F * 0.002F;

    /* Update for DiscreteIntegrator: '<S98>/ ' incorporates:
     *  Gain: '<S98>/Gain3'
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

    /* End of Update for DiscreteIntegrator: '<S98>/ ' */

    /* Update for DiscreteIntegrator: '<S99>/Discrete-Time Integrator1' */
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
      rtb_Multiply_ni[0];

    /* Update for DiscreteIntegrator: '<S24>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S24>/Gain'
     *  Sum: '<S24>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1] +=
      (rtb_TmpSignalConversionAtMult_1 -
       Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S28>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[1] += 0.002F *
      rtb_Multiply_ni[1];

    /* Update for DiscreteIntegrator: '<S24>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S24>/Gain'
     *  Sum: '<S24>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2] +=
      (rtb_TmpSignalConversionAtMult_2 -
       Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S28>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[2] += 0.002F *
      rtb_Multiply_ni[2];
    Controller_DW.DiscreteTimeIntegrator1_PrevR_l = (int8_T)
      rtb_LogicalOperator_i;

    /* Update for DiscreteIntegrator: '<S101>/ ' incorporates:
     *  Gain: '<S101>/Gain'
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

    /* End of Update for DiscreteIntegrator: '<S101>/ ' */

    /* Update for DiscreteIntegrator: '<S102>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_L_h0 = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTA_nm += 0.002F *
      rtb_aux_att_error_B_rad_idx_0;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_d = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S48>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S48>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_i += 0.002F *
      Controller_DW.Integrator_DSTATE_f;

    /* Update for DiscreteIntegrator: '<S51>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S51>/ki'
     *  Product: '<S51>/Multiply'
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

    /* End of Update for DiscreteIntegrator: '<S51>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S53>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_i = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_l += 0.002F *
      rtb_DiscreteTimeIntegrator5_h5;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_h = (int8_T)
      rtb_LogicalOperator_g;

    /* Update for DiscreteIntegrator: '<S54>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S54>/Gain'
     *  Sum: '<S54>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_g = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTA_jo += (rtb_Divide_m_idx_2 -
      Controller_DW.DiscreteTimeIntegrator5_DSTA_jo) * 12.566371F * 0.002F;

    /* Update for DiscreteIntegrator: '<S77>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S77>/gain1'
     *  Constant: '<S77>/gain2'
     *  Constant: '<S77>/gain3'
     *  Product: '<S77>/Multiply'
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

    /* End of Update for DiscreteIntegrator: '<S77>/Discrete-Time Integrator' */

    /* Signum: '<S49>/Sign6' incorporates:
     *  Signum: '<S49>/Sign5'
     */
    if (rtb_aux_att_error_B_rad_idx_1 < 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = -1.0F;

      /* Signum: '<S49>/Sign5' */
      rtb_TmpSignalConversionAtMult_2 = -1.0F;
    } else if (rtb_aux_att_error_B_rad_idx_1 > 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = 1.0F;

      /* Signum: '<S49>/Sign5' */
      rtb_TmpSignalConversionAtMult_2 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_1 = rtb_aux_att_error_B_rad_idx_1;

      /* Signum: '<S49>/Sign5' */
      rtb_TmpSignalConversionAtMult_2 = rtb_aux_att_error_B_rad_idx_1;
    }

    /* End of Signum: '<S49>/Sign6' */

    /* Sum: '<S49>/Add6' */
    rtb_Add3_fc = rtb_aux_att_error_B_rad_idx_1 + Controller_ConstB.d_m;

    /* Sum: '<S49>/Subtract3' */
    rtb_TmpSignalConversionAtMult_0 = rtb_aux_att_error_B_rad_idx_1 -
      Controller_ConstB.d_m;

    /* Signum: '<S49>/Sign3' */
    if (rtb_Add3_fc < 0.0F) {
      rtb_Add3_fc = -1.0F;
    } else {
      if (rtb_Add3_fc > 0.0F) {
        rtb_Add3_fc = 1.0F;
      }
    }

    /* End of Signum: '<S49>/Sign3' */

    /* Signum: '<S49>/Sign4' */
    if (rtb_TmpSignalConversionAtMult_0 < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else {
      if (rtb_TmpSignalConversionAtMult_0 > 0.0F) {
        rtb_TmpSignalConversionAtMult_0 = 1.0F;
      }
    }

    /* End of Signum: '<S49>/Sign4' */

    /* Update for DiscreteIntegrator: '<S48>/Integrator' incorporates:
     *  Constant: '<S49>/const'
     *  Gain: '<S49>/Gain3'
     *  Product: '<S49>/Divide'
     *  Product: '<S49>/Multiply5'
     *  Product: '<S49>/Multiply6'
     *  Sum: '<S49>/Subtract4'
     *  Sum: '<S49>/Subtract5'
     *  Sum: '<S49>/Subtract6'
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
       *  DiscreteIntegrator: '<S119>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S121>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S123>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S143>/Integrator'
       *  DiscreteIntegrator: '<S143>/Integrator1'
       *  DiscreteIntegrator: '<S148>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S150>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S161>/Integrator'
       *  DiscreteIntegrator: '<S161>/Integrator1'
       *  DiscreteIntegrator: '<S164>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S166>/Discrete-Time Integrator1'
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

    /* DiscreteIntegrator: '<S121>/Discrete-Time Integrator' */
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

    /* Trigonometry: '<S145>/Trigonometric Function1' incorporates:
     *  Gain: '<S144>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1[0] = arm_cos_f32(-Controller_U.INS_Out.psi);

    /* Trigonometry: '<S145>/Trigonometric Function' incorporates:
     *  Gain: '<S144>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1[1] = arm_sin_f32(-Controller_U.INS_Out.psi);

    /* SignalConversion: '<S145>/ConcatBufferAtVector Concatenate1In3' incorporates:
     *  Constant: '<S145>/Constant3'
     */
    rtb_MatrixConcatenate1[2] = 0.0F;

    /* Gain: '<S145>/Gain' incorporates:
     *  Gain: '<S144>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S145>/Trigonometric Function2'
     */
    rtb_MatrixConcatenate1[3] = -arm_sin_f32(-Controller_U.INS_Out.psi);

    /* Trigonometry: '<S145>/Trigonometric Function3' incorporates:
     *  Gain: '<S144>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1[4] = arm_cos_f32(-Controller_U.INS_Out.psi);

    /* SignalConversion: '<S145>/ConcatBufferAtVector Concatenate2In3' incorporates:
     *  Constant: '<S145>/Constant4'
     */
    rtb_MatrixConcatenate1[5] = 0.0F;

    /* SignalConversion: '<S145>/ConcatBufferAtVector ConcatenateIn3' */
    rtb_MatrixConcatenate1[6] = Controller_ConstB.VectorConcatenate3[0];
    rtb_MatrixConcatenate1[7] = Controller_ConstB.VectorConcatenate3[1];
    rtb_MatrixConcatenate1[8] = Controller_ConstB.VectorConcatenate3[2];

    /* Product: '<S142>/Multiply' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  SignalConversion: '<S142>/TmpSignal ConversionAtMultiplyInport2'
     */
    for (i = 0; i < 3; i++) {
      rtb_MatrixConcatenate1_0[i] = rtb_MatrixConcatenate1[i + 3] *
        Controller_U.INS_Out.ve + rtb_MatrixConcatenate1[i] *
        Controller_U.INS_Out.vn;
    }

    /* End of Product: '<S142>/Multiply' */

    /* Sum: '<S139>/Sum' incorporates:
     *  DiscreteIntegrator: '<S143>/Integrator1'
     */
    rtb_aux_att_error_B_rad_idx_0 = Controller_DW.Integrator1_DSTATE[0] -
      rtb_MatrixConcatenate1_0[0];
    rtb_aux_att_error_B_rad_idx_1 = Controller_DW.Integrator1_DSTATE[1] -
      rtb_MatrixConcatenate1_0[1];

    /* DiscreteIntegrator: '<S148>/Discrete-Time Integrator' */
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

    /* DiscreteIntegrator: '<S150>/Discrete-Time Integrator1' */
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

    /* Gain: '<S150>/Gain' incorporates:
     *  DiscreteIntegrator: '<S150>/Discrete-Time Integrator1'
     *  Sum: '<S150>/Sum5'
     */
    rtb_Divide_m_idx_3 = (rtb_aux_att_error_B_rad_idx_0 -
                          Controller_DW.DiscreteTimeIntegrator1_DSTATE[0]) *
      62.831852F;
    rtb_Divide_m_idx_0 = (rtb_aux_att_error_B_rad_idx_1 -
                          Controller_DW.DiscreteTimeIntegrator1_DSTATE[1]) *
      62.831852F;

    /* Switch: '<S150>/Switch' incorporates:
     *  Gain: '<S150>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_Divide_m_idx_1 = 0.0F;
      rtb_Divide_m_idx_2 = 0.0F;
    } else {
      rtb_Divide_m_idx_1 = rtb_Divide_m_idx_3;
      rtb_Divide_m_idx_2 = rtb_Divide_m_idx_0;
    }

    /* End of Switch: '<S150>/Switch' */

    /* Product: '<S147>/Multiply' incorporates:
     *  Constant: '<S147>/kd'
     */
    rtb_Square_d = CONTROL_PARAM.MC_VEL_XY_D * rtb_Divide_m_idx_1;

    /* Saturate: '<S147>/Saturation' */
    if (rtb_Square_d > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
      rtb_Square_d = CONTROL_PARAM.MC_VEL_XY_D_MAX;
    } else {
      if (rtb_Square_d < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
        rtb_Square_d = CONTROL_PARAM.MC_VEL_XY_D_MIN;
      }
    }

    rtb_Divide_m_idx_1 = rtb_Square_d;

    /* Product: '<S147>/Multiply' incorporates:
     *  Constant: '<S147>/kd'
     */
    rtb_Square_d = CONTROL_PARAM.MC_VEL_XY_D * rtb_Divide_m_idx_2;

    /* Saturate: '<S147>/Saturation' */
    if (rtb_Square_d > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
      rtb_Square_d = CONTROL_PARAM.MC_VEL_XY_D_MAX;
    } else {
      if (rtb_Square_d < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
        rtb_Square_d = CONTROL_PARAM.MC_VEL_XY_D_MIN;
      }
    }

    /* Switch: '<S141>/Switch' incorporates:
     *  Constant: '<S149>/kp'
     *  Constant: '<S151>/Constant'
     *  Constant: '<S153>/Constant'
     *  Constant: '<S154>/Constant'
     *  DiscreteIntegrator: '<S148>/Discrete-Time Integrator'
     *  Product: '<S149>/Multiply'
     *  Product: '<S152>/Multiply2'
     *  Product: '<S152>/Multiply3'
     *  RelationalOperator: '<S151>/Compare'
     *  RelationalOperator: '<S153>/Compare'
     *  RelationalOperator: '<S154>/Compare'
     *  S-Function (sfix_bitop): '<S152>/cmd_ax valid'
     *  S-Function (sfix_bitop): '<S152>/cmd_ay valid'
     *  S-Function (sfix_bitop): '<S152>/cmd_u valid'
     *  S-Function (sfix_bitop): '<S152>/cmd_v valid'
     *  Sum: '<S140>/Add'
     *  Sum: '<S152>/Sum1'
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

    /* End of Switch: '<S141>/Switch' */

    /* Trigonometry: '<S138>/Atan' incorporates:
     *  Constant: '<S138>/g'
     *  Gain: '<S138>/Gain1'
     *  Gain: '<S138>/gain'
     *  Product: '<S138>/Divide'
     */
    rtb_Add3_fc = atanf(1.1F * rtb_Divide_m_idx_2 / 9.8055F);
    rtb_Divide_m_idx_2 = atanf(1.1F * -rtb_Divide_m_idx_1 / 9.8055F);

    /* Switch: '<S129>/Switch' incorporates:
     *  Constant: '<S136>/Constant'
     *  Logic: '<S129>/Logical Operator'
     *  RelationalOperator: '<S135>/Compare'
     *  RelationalOperator: '<S136>/Compare'
     *  Saturate: '<S138>/Saturation'
     *  Switch: '<S129>/Switch1'
     */
    if ((rtb_BitwiseAND_n == 3) || (rtb_BitwiseAND_n == 4)) {
      rtb_Divide_m_idx_1 = Controller_U.FMS_Out.phi_cmd;
      rtb_Divide_m_idx_2 = Controller_U.FMS_Out.theta_cmd;
    } else if (rtb_BitwiseAND_n == 6) {
      /* Switch: '<S137>/Switch' incorporates:
       *  S-Function (sfix_bitop): '<S137>/cmd_phi valid'
       *  S-Function (sfix_bitop): '<S137>/cmd_theta valid'
       *  Saturate: '<S138>/Saturation'
       *  Switch: '<S129>/Switch1'
       */
      if ((Controller_U.FMS_Out.cmd_mask & 8) > 0) {
        rtb_Divide_m_idx_1 = Controller_U.FMS_Out.phi_cmd;
      } else if (rtb_Add3_fc > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S138>/Saturation' */
        rtb_Divide_m_idx_1 = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else if (rtb_Add3_fc < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S138>/Saturation' */
        rtb_Divide_m_idx_1 = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        rtb_Divide_m_idx_1 = rtb_Add3_fc;
      }

      if ((Controller_U.FMS_Out.cmd_mask & 16) > 0) {
        rtb_Divide_m_idx_2 = Controller_U.FMS_Out.theta_cmd;
      } else if (rtb_Divide_m_idx_2 > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S138>/Saturation' */
        rtb_Divide_m_idx_2 = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_Divide_m_idx_2 < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Saturate: '<S138>/Saturation' */
          rtb_Divide_m_idx_2 = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        }
      }

      /* End of Switch: '<S137>/Switch' */
    } else {
      if (rtb_Add3_fc > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S138>/Saturation' incorporates:
         *  Switch: '<S129>/Switch1'
         */
        rtb_Divide_m_idx_1 = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else if (rtb_Add3_fc < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S138>/Saturation' incorporates:
         *  Switch: '<S129>/Switch1'
         */
        rtb_Divide_m_idx_1 = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        /* Switch: '<S129>/Switch1' incorporates:
         *  Saturate: '<S138>/Saturation'
         */
        rtb_Divide_m_idx_1 = rtb_Add3_fc;
      }

      /* Saturate: '<S138>/Saturation' */
      if (rtb_Divide_m_idx_2 > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Switch: '<S129>/Switch1' */
        rtb_Divide_m_idx_2 = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_Divide_m_idx_2 < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Switch: '<S129>/Switch1' */
          rtb_Divide_m_idx_2 = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        }
      }
    }

    /* End of Switch: '<S129>/Switch' */

    /* Sum: '<S130>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Square_d = rtb_Divide_m_idx_1 - Controller_U.INS_Out.phi;

    /* Product: '<S133>/Divide1' incorporates:
     *  Abs: '<S133>/Abs'
     *  Constant: '<S133>/const2'
     */
    rtb_Saturation_j_idx_0 = fabsf(rtb_Square_d) / 0.002F;

    /* Product: '<S133>/Divide' incorporates:
     *  Constant: '<S131>/Constant1'
     *  Constant: '<S133>/const1'
     *  Math: '<S133>/Square'
     *  SignalConversion: '<S133>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_TmpSignalConversionAtMult_1 = 9.5993F / (CONTROL_PARAM.MC_ROLL_P *
      CONTROL_PARAM.MC_ROLL_P);

    /* Signum: '<S133>/Sign' */
    if (rtb_Square_d < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else if (rtb_Square_d > 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_0 = rtb_Square_d;
    }

    /* Switch: '<S133>/Switch' incorporates:
     *  Constant: '<S131>/Constant1'
     *  Gain: '<S133>/Gain1'
     *  Gain: '<S133>/Gain2'
     *  Logic: '<S133>/Logical Operator'
     *  Product: '<S133>/Divide'
     *  Product: '<S133>/Multiply'
     *  Product: '<S133>/Multiply1'
     *  Product: '<S133>/Multiply2'
     *  Product: '<S133>/Multiply3'
     *  RelationalOperator: '<S133>/Relational Operator'
     *  RelationalOperator: '<S133>/Relational Operator2'
     *  SignalConversion: '<S133>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S133>/Sqrt'
     *  Sum: '<S133>/Subtract'
     */
    if ((rtb_Square_d <= rtb_TmpSignalConversionAtMult_1) && (rtb_Square_d >=
         -rtb_TmpSignalConversionAtMult_1)) {
      rtb_TmpSignalConversionAtMult_0 = rtb_Square_d * CONTROL_PARAM.MC_ROLL_P;
    } else {
      rtb_TmpSignalConversionAtMult_0 *= sqrtf((rtb_TmpSignalConversionAtMult_0 *
        rtb_Square_d - 0.5F * rtb_TmpSignalConversionAtMult_1) *
        Controller_ConstB.Gain);
    }

    /* Gain: '<S133>/Gain3' */
    rtb_TmpSignalConversionAtMult_1 = -rtb_Saturation_j_idx_0;

    /* Switch: '<S134>/Switch' incorporates:
     *  Gain: '<S133>/Gain3'
     *  RelationalOperator: '<S134>/UpperRelop'
     */
    if (rtb_TmpSignalConversionAtMult_0 >= -rtb_Saturation_j_idx_0) {
      rtb_TmpSignalConversionAtMult_1 = rtb_TmpSignalConversionAtMult_0;
    }

    /* Switch: '<S134>/Switch2' incorporates:
     *  RelationalOperator: '<S134>/LowerRelop1'
     */
    if (rtb_TmpSignalConversionAtMult_0 <= rtb_Saturation_j_idx_0) {
      rtb_Saturation_j_idx_0 = rtb_TmpSignalConversionAtMult_1;
    }

    /* Saturate: '<S114>/Saturation1' */
    if (rtb_Saturation_j_idx_0 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_Saturation_j_idx_0 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_Saturation_j_idx_0 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_Saturation_j_idx_0 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    rtb_Divide_m_idx_1 = rtb_Saturation_j_idx_0;

    /* Sum: '<S130>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S133>/Divide1'
     */
    rtb_Square_d = rtb_Divide_m_idx_2 - Controller_U.INS_Out.theta;

    /* Product: '<S133>/Divide1' incorporates:
     *  Abs: '<S133>/Abs'
     *  Constant: '<S133>/const2'
     */
    rtb_Saturation_j_idx_0 = fabsf(rtb_Square_d) / 0.002F;

    /* Product: '<S133>/Divide' incorporates:
     *  Constant: '<S131>/Constant2'
     *  Constant: '<S133>/const1'
     *  Math: '<S133>/Square'
     *  SignalConversion: '<S133>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_TmpSignalConversionAtMult_1 = 9.5993F / (CONTROL_PARAM.MC_PITCH_P *
      CONTROL_PARAM.MC_PITCH_P);

    /* Signum: '<S133>/Sign' */
    if (rtb_Square_d < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else if (rtb_Square_d > 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_0 = rtb_Square_d;
    }

    /* Switch: '<S133>/Switch' incorporates:
     *  Constant: '<S131>/Constant2'
     *  Gain: '<S133>/Gain1'
     *  Gain: '<S133>/Gain2'
     *  Logic: '<S133>/Logical Operator'
     *  Product: '<S133>/Divide'
     *  Product: '<S133>/Multiply'
     *  Product: '<S133>/Multiply1'
     *  Product: '<S133>/Multiply2'
     *  Product: '<S133>/Multiply3'
     *  RelationalOperator: '<S133>/Relational Operator'
     *  RelationalOperator: '<S133>/Relational Operator2'
     *  SignalConversion: '<S133>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S133>/Sqrt'
     *  Sum: '<S133>/Subtract'
     */
    if ((rtb_Square_d <= rtb_TmpSignalConversionAtMult_1) && (rtb_Square_d >=
         -rtb_TmpSignalConversionAtMult_1)) {
      rtb_TmpSignalConversionAtMult_0 = rtb_Square_d * CONTROL_PARAM.MC_PITCH_P;
    } else {
      rtb_TmpSignalConversionAtMult_0 *= sqrtf((rtb_TmpSignalConversionAtMult_0 *
        rtb_Square_d - 0.5F * rtb_TmpSignalConversionAtMult_1) *
        Controller_ConstB.Gain);
    }

    /* Gain: '<S133>/Gain3' */
    rtb_TmpSignalConversionAtMult_1 = -rtb_Saturation_j_idx_0;

    /* Switch: '<S134>/Switch' incorporates:
     *  Gain: '<S133>/Gain3'
     *  RelationalOperator: '<S134>/UpperRelop'
     */
    if (rtb_TmpSignalConversionAtMult_0 >= -rtb_Saturation_j_idx_0) {
      rtb_TmpSignalConversionAtMult_1 = rtb_TmpSignalConversionAtMult_0;
    }

    /* Switch: '<S134>/Switch2' incorporates:
     *  RelationalOperator: '<S134>/LowerRelop1'
     */
    if (rtb_TmpSignalConversionAtMult_0 <= rtb_Saturation_j_idx_0) {
      rtb_Saturation_j_idx_0 = rtb_TmpSignalConversionAtMult_1;
    }

    /* Saturate: '<S114>/Saturation1' */
    if (rtb_Saturation_j_idx_0 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_Saturation_j_idx_0 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_Saturation_j_idx_0 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_Saturation_j_idx_0 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    /* Saturate: '<S114>/Saturation' */
    if (Controller_U.FMS_Out.psi_rate_cmd > CONTROL_PARAM.MC_R_CMD_LIM) {
      rtb_Add3_fc = CONTROL_PARAM.MC_R_CMD_LIM;
    } else if (Controller_U.FMS_Out.psi_rate_cmd < -CONTROL_PARAM.MC_R_CMD_LIM)
    {
      rtb_Add3_fc = -CONTROL_PARAM.MC_R_CMD_LIM;
    } else {
      rtb_Add3_fc = Controller_U.FMS_Out.psi_rate_cmd;
    }

    /* End of Saturate: '<S114>/Saturation' */

    /* Trigonometry: '<S124>/Sin' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Gain_c4 = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S124>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Saturation_g = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Product: '<S124>/Multiply3' incorporates:
     *  Trigonometry: '<S124>/Cos1'
     *  Trigonometry: '<S124>/Sin'
     */
    rtb_TmpSignalConversionAtMult_0 = rtb_Gain_c4 * rtb_Saturation_g *
      rtb_Add3_fc;

    /* Trigonometry: '<S124>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_TmpSignalConversionAtMult_1 = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Product: '<S124>/Multiply1' incorporates:
     *  Trigonometry: '<S124>/Cos'
     */
    rtb_TmpSignalConversionAtMult_2 = rtb_TmpSignalConversionAtMult_1 *
      rtb_Saturation_j_idx_0;

    /* Product: '<S124>/Multiply4' incorporates:
     *  Trigonometry: '<S124>/Sin'
     */
    rtb_Gain_c4 *= rtb_Saturation_j_idx_0;

    /* Switch: '<S115>/Switch' incorporates:
     *  Constant: '<S125>/Constant'
     *  Constant: '<S126>/Constant'
     *  RelationalOperator: '<S125>/Compare'
     *  RelationalOperator: '<S126>/Compare'
     *  Switch: '<S115>/Switch1'
     */
    if (rtb_BitwiseAND_n == 2) {
      rtb_Multiply_ni[0] = Controller_U.FMS_Out.p_cmd;
      rtb_Multiply_ni[1] = Controller_U.FMS_Out.q_cmd;
      rtb_Multiply_ni[2] = Controller_U.FMS_Out.r_cmd;
    } else if (rtb_BitwiseAND_n == 6) {
      /* Switch: '<S127>/Switch' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Product: '<S124>/Multiply'
       *  Product: '<S124>/Multiply1'
       *  Product: '<S124>/Multiply5'
       *  S-Function (sfix_bitop): '<S127>/cmd_p valid'
       *  S-Function (sfix_bitop): '<S127>/cmd_q valid'
       *  S-Function (sfix_bitop): '<S127>/cmd_r valid'
       *  Sum: '<S124>/Add'
       *  Sum: '<S124>/Add1'
       *  Sum: '<S124>/Add2'
       *  Switch: '<S115>/Switch1'
       *  Trigonometry: '<S124>/Cos'
       *  Trigonometry: '<S124>/Cos1'
       *  Trigonometry: '<S124>/Sin1'
       */
      if ((Controller_U.FMS_Out.cmd_mask & 1) > 0) {
        rtb_Multiply_ni[0] = Controller_U.FMS_Out.p_cmd;
      } else {
        rtb_Multiply_ni[0] = rtb_Divide_m_idx_1 - arm_sin_f32
          (Controller_U.INS_Out.theta) * rtb_Add3_fc;
      }

      if ((Controller_U.FMS_Out.cmd_mask & 2) > 0) {
        rtb_Multiply_ni[1] = Controller_U.FMS_Out.q_cmd;
      } else {
        rtb_Multiply_ni[1] = rtb_TmpSignalConversionAtMult_0 +
          rtb_TmpSignalConversionAtMult_2;
      }

      if ((Controller_U.FMS_Out.cmd_mask & 4) > 0) {
        rtb_Multiply_ni[2] = Controller_U.FMS_Out.r_cmd;
      } else {
        rtb_Multiply_ni[2] = rtb_TmpSignalConversionAtMult_1 * rtb_Saturation_g *
          rtb_Add3_fc - rtb_Gain_c4;
      }

      /* End of Switch: '<S127>/Switch' */
    } else {
      /* Switch: '<S115>/Switch1' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Product: '<S124>/Multiply'
       *  Product: '<S124>/Multiply3'
       *  Product: '<S124>/Multiply5'
       *  Sum: '<S124>/Add'
       *  Sum: '<S124>/Add1'
       *  Sum: '<S124>/Add2'
       *  Trigonometry: '<S124>/Cos'
       *  Trigonometry: '<S124>/Cos1'
       *  Trigonometry: '<S124>/Sin1'
       */
      rtb_Multiply_ni[0] = rtb_Divide_m_idx_1 - arm_sin_f32
        (Controller_U.INS_Out.theta) * rtb_Add3_fc;
      rtb_Multiply_ni[1] = rtb_TmpSignalConversionAtMult_2 +
        rtb_TmpSignalConversionAtMult_0;
      rtb_Multiply_ni[2] = rtb_TmpSignalConversionAtMult_1 * rtb_Saturation_g *
        rtb_Add3_fc - rtb_Gain_c4;
    }

    /* End of Switch: '<S115>/Switch' */

    /* Sum: '<S116>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_TmpSignalConversionAtMult_0 = rtb_Multiply_ni[0] -
      Controller_U.INS_Out.p;
    rtb_TmpSignalConversionAtMult_1 = rtb_Multiply_ni[1] -
      Controller_U.INS_Out.q;
    rtb_TmpSignalConversionAtMult_2 = rtb_Multiply_ni[2] -
      Controller_U.INS_Out.r;

    /* DiscreteIntegrator: '<S119>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] =
        rtb_TmpSignalConversionAtMult_0;
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] =
        rtb_TmpSignalConversionAtMult_1;
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] =
        rtb_TmpSignalConversionAtMult_2;
    }

    /* DiscreteIntegrator: '<S123>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S119>/Discrete-Time Integrator5'
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

    /* Gain: '<S123>/Gain' incorporates:
     *  DiscreteIntegrator: '<S119>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S123>/Discrete-Time Integrator1'
     *  Sum: '<S123>/Sum5'
     */
    rtb_Multiply_ni[0] = (Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] -
                          Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[0]) *
      188.49556F;
    rtb_Multiply_ni[1] = (Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] -
                          Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[1]) *
      188.49556F;
    rtb_Multiply_ni[2] = (Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] -
                          Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[2]) *
      188.49556F;

    /* Switch: '<S123>/Switch' incorporates:
     *  Gain: '<S123>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_Saturation_j_idx_0 = 0.0F;
      rtb_Saturation_j_idx_1 = 0.0F;
      rtb_Saturation_j_idx_2 = 0.0F;
    } else {
      rtb_Saturation_j_idx_0 = rtb_Multiply_ni[0];
      rtb_Saturation_j_idx_1 = rtb_Multiply_ni[1];
      rtb_Saturation_j_idx_2 = rtb_Multiply_ni[2];
    }

    /* End of Switch: '<S123>/Switch' */

    /* Product: '<S120>/Multiply' incorporates:
     *  Constant: '<S120>/gain1'
     */
    rtb_Saturation_ni = CONTROL_PARAM.MC_ROLL_RATE_D * rtb_Saturation_j_idx_0;

    /* Saturate: '<S120>/Saturation' */
    if (rtb_Saturation_ni > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Saturation_ni = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Saturation_ni < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Saturation_ni = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    rtb_Saturation_j_idx_0 = rtb_Saturation_ni;

    /* Product: '<S120>/Multiply' incorporates:
     *  Constant: '<S120>/gain2'
     */
    rtb_Saturation_ni = CONTROL_PARAM.MC_PITCH_RATE_D * rtb_Saturation_j_idx_1;

    /* Saturate: '<S120>/Saturation' */
    if (rtb_Saturation_ni > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Saturation_ni = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Saturation_ni < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Saturation_ni = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    rtb_Saturation_j_idx_1 = rtb_Saturation_ni;

    /* Product: '<S120>/Multiply' incorporates:
     *  Constant: '<S120>/gain3'
     */
    rtb_Saturation_ni = CONTROL_PARAM.MC_YAW_RATE_D * rtb_Saturation_j_idx_2;

    /* Saturate: '<S120>/Saturation' */
    if (rtb_Saturation_ni > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Saturation_ni = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Saturation_ni < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Saturation_ni = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    /* SignalConversion: '<S5>/BusConversion_InsertedFor_VTOL_actuator_cmd_at_inport_0' incorporates:
     *  Constant: '<S122>/gain1'
     *  Constant: '<S122>/gain2'
     *  Constant: '<S122>/gain3'
     *  DiscreteIntegrator: '<S119>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S121>/Discrete-Time Integrator'
     *  Product: '<S122>/Multiply'
     *  Sum: '<S117>/Add'
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

    /* Product: '<S146>/Multiply1' incorporates:
     *  Constant: '<S146>/const1'
     *  DiscreteIntegrator: '<S143>/Integrator'
     */
    rtb_Saturation_g = Controller_DW.Integrator_DSTATE[0] * 0.1F;
    rtb_Gain_c4 = Controller_DW.Integrator_DSTATE[1] * 0.1F;

    /* Sum: '<S146>/Add' incorporates:
     *  DiscreteIntegrator: '<S143>/Integrator1'
     *  Sum: '<S143>/Subtract'
     */
    rtb_Divide_m_idx_1 = (Controller_DW.Integrator1_DSTATE[0] -
                          Controller_U.FMS_Out.u_cmd) + rtb_Saturation_g;
    rtb_Divide_m_idx_2 = (Controller_DW.Integrator1_DSTATE[1] -
                          Controller_U.FMS_Out.v_cmd) + rtb_Gain_c4;

    /* Signum: '<S146>/Sign' */
    if (rtb_Divide_m_idx_1 < 0.0F) {
      rtb_Square_d = -1.0F;
    } else if (rtb_Divide_m_idx_1 > 0.0F) {
      rtb_Square_d = 1.0F;
    } else {
      rtb_Square_d = rtb_Divide_m_idx_1;
    }

    /* Sum: '<S146>/Add2' incorporates:
     *  Abs: '<S146>/Abs'
     *  Gain: '<S146>/Gain'
     *  Gain: '<S146>/Gain1'
     *  Product: '<S146>/Multiply2'
     *  Product: '<S146>/Multiply3'
     *  Signum: '<S146>/Sign'
     *  Sqrt: '<S146>/Sqrt'
     *  Sum: '<S146>/Add1'
     *  Sum: '<S146>/Subtract'
     */
    rtb_Saturation_j_idx_0 = (sqrtf((8.0F * fabsf(rtb_Divide_m_idx_1) +
      Controller_ConstB.d) * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
      rtb_Square_d + rtb_Saturation_g;

    /* Sum: '<S146>/Add3' incorporates:
     *  Signum: '<S146>/Sign'
     */
    rtb_Add3_fc = rtb_Divide_m_idx_1 + Controller_ConstB.d;

    /* Sum: '<S146>/Subtract1' incorporates:
     *  Signum: '<S146>/Sign'
     */
    rtb_Square_d = rtb_Divide_m_idx_1 - Controller_ConstB.d;

    /* Signum: '<S146>/Sign1' */
    if (rtb_Add3_fc < 0.0F) {
      rtb_Add3_fc = -1.0F;
    } else {
      if (rtb_Add3_fc > 0.0F) {
        rtb_Add3_fc = 1.0F;
      }
    }

    /* Signum: '<S146>/Sign2' */
    if (rtb_Square_d < 0.0F) {
      rtb_Square_d = -1.0F;
    } else {
      if (rtb_Square_d > 0.0F) {
        rtb_Square_d = 1.0F;
      }
    }

    /* Sum: '<S146>/Add2' incorporates:
     *  Gain: '<S146>/Gain2'
     *  Product: '<S146>/Multiply4'
     *  Signum: '<S146>/Sign'
     *  Sum: '<S146>/Add4'
     *  Sum: '<S146>/Add5'
     *  Sum: '<S146>/Subtract2'
     */
    rtb_Divide_m_idx_1 = ((rtb_Divide_m_idx_1 - rtb_Saturation_j_idx_0) +
                          rtb_Saturation_g) * ((rtb_Add3_fc - rtb_Square_d) *
      0.5F) + rtb_Saturation_j_idx_0;

    /* Signum: '<S146>/Sign' */
    if (rtb_Divide_m_idx_2 < 0.0F) {
      rtb_Square_d = -1.0F;
    } else if (rtb_Divide_m_idx_2 > 0.0F) {
      rtb_Square_d = 1.0F;
    } else {
      rtb_Square_d = rtb_Divide_m_idx_2;
    }

    /* Sum: '<S146>/Add2' incorporates:
     *  Abs: '<S146>/Abs'
     *  Gain: '<S146>/Gain'
     *  Gain: '<S146>/Gain1'
     *  Product: '<S146>/Multiply2'
     *  Product: '<S146>/Multiply3'
     *  Signum: '<S146>/Sign'
     *  Sqrt: '<S146>/Sqrt'
     *  Sum: '<S146>/Add1'
     *  Sum: '<S146>/Subtract'
     */
    rtb_Saturation_j_idx_0 = (sqrtf((8.0F * fabsf(rtb_Divide_m_idx_2) +
      Controller_ConstB.d) * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
      rtb_Square_d + rtb_Gain_c4;

    /* Sum: '<S146>/Add3' incorporates:
     *  Signum: '<S146>/Sign'
     */
    rtb_Add3_fc = rtb_Divide_m_idx_2 + Controller_ConstB.d;

    /* Sum: '<S146>/Subtract1' incorporates:
     *  Signum: '<S146>/Sign'
     */
    rtb_Square_d = rtb_Divide_m_idx_2 - Controller_ConstB.d;

    /* Signum: '<S146>/Sign1' */
    if (rtb_Add3_fc < 0.0F) {
      rtb_Add3_fc = -1.0F;
    } else {
      if (rtb_Add3_fc > 0.0F) {
        rtb_Add3_fc = 1.0F;
      }
    }

    /* Signum: '<S146>/Sign2' */
    if (rtb_Square_d < 0.0F) {
      rtb_Square_d = -1.0F;
    } else {
      if (rtb_Square_d > 0.0F) {
        rtb_Square_d = 1.0F;
      }
    }

    /* Sum: '<S146>/Add5' incorporates:
     *  Gain: '<S146>/Gain2'
     *  Product: '<S146>/Multiply4'
     *  Signum: '<S146>/Sign'
     *  Sum: '<S146>/Add2'
     *  Sum: '<S146>/Add4'
     *  Sum: '<S146>/Subtract2'
     */
    rtb_Saturation_j_idx_0 += ((rtb_Divide_m_idx_2 - rtb_Saturation_j_idx_0) +
      rtb_Gain_c4) * ((rtb_Add3_fc - rtb_Square_d) * 0.5F);

    /* Gain: '<S159>/Gain' incorporates:
     *  DiscreteIntegrator: '<S161>/Integrator1'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S159>/Sum1'
     */
    rtb_Divide_m_idx_2 = -(Controller_DW.Integrator1_DSTATE_e -
      Controller_U.INS_Out.vd);
    Controller_B.Constant = CONTROL_PARAM.MC_VEL_Z_I_MIN;

    /* DiscreteIntegrator: '<S164>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S164>/Constant'
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

    /* DiscreteIntegrator: '<S166>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_d != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i = rtb_Divide_m_idx_2;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_Prev_ks != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i = rtb_Divide_m_idx_2;
    }

    /* Gain: '<S166>/Gain' incorporates:
     *  DiscreteIntegrator: '<S166>/Discrete-Time Integrator1'
     *  Sum: '<S166>/Sum5'
     */
    rtb_Square_d = (rtb_Divide_m_idx_2 -
                    Controller_DW.DiscreteTimeIntegrator1_DSTAT_i) * 62.831852F;

    /* Switch: '<S155>/Switch' incorporates:
     *  Constant: '<S157>/Constant'
     *  RelationalOperator: '<S157>/Compare'
     */
    if (rtb_BitwiseAND_n <= 3) {
      /* SignalConversion: '<S5>/BusConversion_InsertedFor_VTOL_actuator_cmd_at_inport_0' incorporates:
       *  Bias: '<S155>/Bias'
       *  Gain: '<S155>/Gain'
       */
      Controller_B.mc_force_cmd[2] = 0.000999987125F * (real32_T)
        Controller_U.FMS_Out.throttle_cmd + -1.0F;
    } else {
      /* Product: '<S158>/Multiply' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S158>/Cos'
       *  Trigonometry: '<S158>/Cos1'
       */
      rtb_Saturation_g = arm_cos_f32(Controller_U.INS_Out.phi) * arm_cos_f32
        (Controller_U.INS_Out.theta);

      /* Gain: '<S158>/Gain' */
      rtb_Add3_fc = 2.0F * rtb_Saturation_g;

      /* Saturate: '<S158>/Saturation1' */
      if (rtb_Saturation_g > 1.0F) {
        rtb_Saturation_g = 1.0F;
      } else {
        if (rtb_Saturation_g < 0.5F) {
          rtb_Saturation_g = 0.5F;
        }
      }

      /* End of Saturate: '<S158>/Saturation1' */

      /* Product: '<S158>/Divide' incorporates:
       *  Constant: '<S158>/Constant'
       */
      rtb_Gain_c4 = 1.0F / rtb_Saturation_g;

      /* Switch: '<S166>/Switch' incorporates:
       *  Gain: '<S166>/Gain1'
       */
      if (Controller_U.FMS_Out.reset > 0) {
        rtb_Saturation_j_idx_1 = 0.0F;
      } else {
        rtb_Saturation_j_idx_1 = rtb_Square_d;
      }

      /* End of Switch: '<S166>/Switch' */

      /* Product: '<S163>/Multiply' incorporates:
       *  Constant: '<S163>/kd'
       */
      rtb_Saturation_g = CONTROL_PARAM.MC_VEL_Z_D * rtb_Saturation_j_idx_1;

      /* Saturate: '<S163>/Saturation' */
      if (rtb_Saturation_g > CONTROL_PARAM.MC_VEL_Z_D_MAX) {
        rtb_Saturation_g = CONTROL_PARAM.MC_VEL_Z_D_MAX;
      } else {
        if (rtb_Saturation_g < CONTROL_PARAM.MC_VEL_Z_D_MIN) {
          rtb_Saturation_g = CONTROL_PARAM.MC_VEL_Z_D_MIN;
        }
      }

      /* End of Saturate: '<S163>/Saturation' */

      /* Saturate: '<S158>/Saturation' */
      if (rtb_Add3_fc > 1.0F) {
        rtb_Add3_fc = 1.0F;
      } else {
        if (rtb_Add3_fc < 0.0F) {
          rtb_Add3_fc = 0.0F;
        }
      }

      /* End of Saturate: '<S158>/Saturation' */

      /* Product: '<S158>/Multiply1' incorporates:
       *  Constant: '<S165>/kp'
       *  DiscreteIntegrator: '<S164>/Discrete-Time Integrator'
       *  Product: '<S165>/Multiply'
       *  Sum: '<S160>/Add'
       */
      rtb_Gain_c4 = ((CONTROL_PARAM.MC_VEL_Z_P * rtb_Divide_m_idx_2 +
                      Controller_DW.DiscreteTimeIntegrator_DSTATE_l) +
                     rtb_Saturation_g) * rtb_Gain_c4 * rtb_Add3_fc;

      /* Saturate: '<S156>/Saturation' */
      if (rtb_Gain_c4 > 0.35F) {
        rtb_Gain_c4 = 0.35F;
      } else {
        if (rtb_Gain_c4 < -0.35F) {
          rtb_Gain_c4 = -0.35F;
        }
      }

      /* End of Saturate: '<S156>/Saturation' */

      /* SignalConversion: '<S5>/BusConversion_InsertedFor_VTOL_actuator_cmd_at_inport_0' incorporates:
       *  Constant: '<S156>/hover_throttle'
       *  Sum: '<S156>/Sum'
       */
      Controller_B.mc_force_cmd[2] = rtb_Gain_c4 + CONTROL_PARAM.MC_HOVER_THRO;
    }

    /* End of Switch: '<S155>/Switch' */

    /* SignalConversion: '<S5>/BusConversion_InsertedFor_VTOL_actuator_cmd_at_inport_0' */
    Controller_B.mc_force_cmd[0] = Controller_ConstB.TmpBufferAtConstantOutport1;
    Controller_B.mc_force_cmd[1] = Controller_ConstB.TmpBufferAtConstantOutport1;

    /* Product: '<S162>/Multiply1' incorporates:
     *  Constant: '<S162>/const1'
     *  DiscreteIntegrator: '<S161>/Integrator'
     */
    rtb_Add3_fc = Controller_DW.Integrator_DSTATE_j * 0.05F;

    /* Sum: '<S162>/Add' incorporates:
     *  DiscreteIntegrator: '<S161>/Integrator1'
     *  Sum: '<S161>/Subtract'
     */
    rtb_Saturation_g = (Controller_DW.Integrator1_DSTATE_e -
                        Controller_U.FMS_Out.w_cmd) + rtb_Add3_fc;

    /* Signum: '<S162>/Sign' */
    if (rtb_Saturation_g < 0.0F) {
      rtb_Gain_c4 = -1.0F;
    } else if (rtb_Saturation_g > 0.0F) {
      rtb_Gain_c4 = 1.0F;
    } else {
      rtb_Gain_c4 = rtb_Saturation_g;
    }

    /* End of Signum: '<S162>/Sign' */

    /* Sum: '<S162>/Add2' incorporates:
     *  Abs: '<S162>/Abs'
     *  Gain: '<S162>/Gain'
     *  Gain: '<S162>/Gain1'
     *  Product: '<S162>/Multiply2'
     *  Product: '<S162>/Multiply3'
     *  Sqrt: '<S162>/Sqrt'
     *  Sum: '<S162>/Add1'
     *  Sum: '<S162>/Subtract'
     */
    rtb_Gain_c4 = (sqrtf((8.0F * fabsf(rtb_Saturation_g) + Controller_ConstB.d_i)
                         * Controller_ConstB.d_i) - Controller_ConstB.d_i) *
      0.5F * rtb_Gain_c4 + rtb_Add3_fc;

    /* Sum: '<S162>/Add4' */
    rtb_phi_cmd = (rtb_Saturation_g - rtb_Gain_c4) + rtb_Add3_fc;

    /* Sum: '<S162>/Add3' */
    rtb_Add3_fc = rtb_Saturation_g + Controller_ConstB.d_i;

    /* Sum: '<S162>/Subtract1' */
    rtb_Saturation_g -= Controller_ConstB.d_i;

    /* Signum: '<S162>/Sign1' */
    if (rtb_Add3_fc < 0.0F) {
      rtb_Add3_fc = -1.0F;
    } else {
      if (rtb_Add3_fc > 0.0F) {
        rtb_Add3_fc = 1.0F;
      }
    }

    /* End of Signum: '<S162>/Sign1' */

    /* Signum: '<S162>/Sign2' */
    if (rtb_Saturation_g < 0.0F) {
      rtb_Saturation_g = -1.0F;
    } else {
      if (rtb_Saturation_g > 0.0F) {
        rtb_Saturation_g = 1.0F;
      }
    }

    /* End of Signum: '<S162>/Sign2' */

    /* Sum: '<S162>/Add5' incorporates:
     *  Gain: '<S162>/Gain2'
     *  Product: '<S162>/Multiply4'
     *  Sum: '<S162>/Subtract2'
     */
    rtb_Gain_c4 += (rtb_Add3_fc - rtb_Saturation_g) * 0.5F * rtb_phi_cmd;

    /* Update for DiscreteIntegrator: '<S121>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S121>/gain1'
     *  Constant: '<S121>/gain2'
     *  Constant: '<S121>/gain3'
     *  DiscreteIntegrator: '<S119>/Discrete-Time Integrator5'
     *  Product: '<S121>/Multiply'
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

    /* End of Update for DiscreteIntegrator: '<S121>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S148>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_PrevRe_p = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S150>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;

    /* Update for DiscreteIntegrator: '<S143>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S143>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE[0] += 0.002F *
      Controller_DW.Integrator_DSTATE[0];

    /* Update for DiscreteIntegrator: '<S148>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S148>/ki'
     *  Product: '<S148>/Multiply'
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

    /* Update for DiscreteIntegrator: '<S150>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] += 0.002F *
      rtb_Divide_m_idx_3;

    /* Update for DiscreteIntegrator: '<S143>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S143>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE[1] += 0.002F *
      Controller_DW.Integrator_DSTATE[1];

    /* Update for DiscreteIntegrator: '<S148>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S148>/ki'
     *  Product: '<S148>/Multiply'
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

    /* Update for DiscreteIntegrator: '<S150>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] += 0.002F *
      rtb_Divide_m_idx_0;
    Controller_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S119>/Discrete-Time Integrator5' */
    Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;

    /* Update for DiscreteIntegrator: '<S123>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 0U;

    /* Update for DiscreteIntegrator: '<S119>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S119>/Gain'
     *  Sum: '<S119>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] +=
      (rtb_TmpSignalConversionAtMult_0 -
       Controller_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S123>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[0] += 0.002F *
      rtb_Multiply_ni[0];

    /* Update for DiscreteIntegrator: '<S119>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S119>/Gain'
     *  Sum: '<S119>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] +=
      (rtb_TmpSignalConversionAtMult_1 -
       Controller_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S123>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[1] += 0.002F *
      rtb_Multiply_ni[1];

    /* Update for DiscreteIntegrator: '<S119>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S119>/Gain'
     *  Sum: '<S119>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] +=
      (rtb_TmpSignalConversionAtMult_2 -
       Controller_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S123>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[2] += 0.002F *
      rtb_Multiply_ni[2];
    Controller_DW.DiscreteTimeIntegrator1_PrevR_k = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Signum: '<S146>/Sign3' incorporates:
     *  Product: '<S146>/Divide'
     *  Sum: '<S146>/Add6'
     */
    rtb_Add3_fc = rtb_Divide_m_idx_1 + Controller_ConstB.d;

    /* Signum: '<S146>/Sign4' incorporates:
     *  Product: '<S146>/Divide'
     *  Sum: '<S146>/Subtract3'
     */
    rtb_TmpSignalConversionAtMult_0 = rtb_Divide_m_idx_1 - Controller_ConstB.d;

    /* Signum: '<S146>/Sign5' incorporates:
     *  Product: '<S146>/Divide'
     */
    if (rtb_Divide_m_idx_1 < 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = -1.0F;
    } else if (rtb_Divide_m_idx_1 > 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_1 = rtb_Divide_m_idx_1;
    }

    /* Signum: '<S146>/Sign3' */
    if (rtb_Add3_fc < 0.0F) {
      rtb_Add3_fc = -1.0F;
    } else {
      if (rtb_Add3_fc > 0.0F) {
        rtb_Add3_fc = 1.0F;
      }
    }

    /* Signum: '<S146>/Sign4' */
    if (rtb_TmpSignalConversionAtMult_0 < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else {
      if (rtb_TmpSignalConversionAtMult_0 > 0.0F) {
        rtb_TmpSignalConversionAtMult_0 = 1.0F;
      }
    }

    /* Signum: '<S146>/Sign6' incorporates:
     *  Product: '<S146>/Divide'
     */
    if (rtb_Divide_m_idx_1 < 0.0F) {
      rtb_TmpSignalConversionAtMult_2 = -1.0F;
    } else if (rtb_Divide_m_idx_1 > 0.0F) {
      rtb_TmpSignalConversionAtMult_2 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_2 = rtb_Divide_m_idx_1;
    }

    /* Update for DiscreteIntegrator: '<S143>/Integrator' incorporates:
     *  Constant: '<S146>/const'
     *  Gain: '<S146>/Gain3'
     *  Product: '<S146>/Divide'
     *  Product: '<S146>/Multiply5'
     *  Product: '<S146>/Multiply6'
     *  Sum: '<S146>/Subtract4'
     *  Sum: '<S146>/Subtract5'
     *  Sum: '<S146>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE[0] += ((rtb_Divide_m_idx_1 /
      Controller_ConstB.d - rtb_TmpSignalConversionAtMult_1) *
      Controller_ConstB.Gain4 * ((rtb_Add3_fc - rtb_TmpSignalConversionAtMult_0)
      * 0.5F) - rtb_TmpSignalConversionAtMult_2 * 78.448F) * 0.002F;

    /* Signum: '<S146>/Sign3' incorporates:
     *  Sum: '<S146>/Add6'
     */
    rtb_Add3_fc = rtb_Saturation_j_idx_0 + Controller_ConstB.d;

    /* Signum: '<S146>/Sign4' incorporates:
     *  Sum: '<S146>/Subtract3'
     */
    rtb_TmpSignalConversionAtMult_0 = rtb_Saturation_j_idx_0 -
      Controller_ConstB.d;

    /* Signum: '<S146>/Sign5' */
    if (rtb_Saturation_j_idx_0 < 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = -1.0F;
    } else if (rtb_Saturation_j_idx_0 > 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_1 = rtb_Saturation_j_idx_0;
    }

    /* Signum: '<S146>/Sign3' */
    if (rtb_Add3_fc < 0.0F) {
      rtb_Add3_fc = -1.0F;
    } else {
      if (rtb_Add3_fc > 0.0F) {
        rtb_Add3_fc = 1.0F;
      }
    }

    /* Signum: '<S146>/Sign4' */
    if (rtb_TmpSignalConversionAtMult_0 < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else {
      if (rtb_TmpSignalConversionAtMult_0 > 0.0F) {
        rtb_TmpSignalConversionAtMult_0 = 1.0F;
      }
    }

    /* Signum: '<S146>/Sign6' */
    if (rtb_Saturation_j_idx_0 < 0.0F) {
      rtb_TmpSignalConversionAtMult_2 = -1.0F;
    } else if (rtb_Saturation_j_idx_0 > 0.0F) {
      rtb_TmpSignalConversionAtMult_2 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_2 = rtb_Saturation_j_idx_0;
    }

    /* Update for DiscreteIntegrator: '<S143>/Integrator' incorporates:
     *  Constant: '<S146>/const'
     *  Gain: '<S146>/Gain3'
     *  Product: '<S146>/Divide'
     *  Product: '<S146>/Multiply5'
     *  Product: '<S146>/Multiply6'
     *  Sum: '<S146>/Subtract4'
     *  Sum: '<S146>/Subtract5'
     *  Sum: '<S146>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE[1] += ((rtb_Saturation_j_idx_0 /
      Controller_ConstB.d - rtb_TmpSignalConversionAtMult_1) *
      Controller_ConstB.Gain4 * ((rtb_Add3_fc - rtb_TmpSignalConversionAtMult_0)
      * 0.5F) - rtb_TmpSignalConversionAtMult_2 * 78.448F) * 0.002F;

    /* Update for DiscreteIntegrator: '<S161>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S161>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_e += 0.002F *
      Controller_DW.Integrator_DSTATE_j;

    /* Update for DiscreteIntegrator: '<S164>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S164>/ki'
     *  Product: '<S164>/Multiply'
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

    /* End of Update for DiscreteIntegrator: '<S164>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S166>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_i += 0.002F * rtb_Square_d;
    Controller_DW.DiscreteTimeIntegrator1_Prev_ks = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Signum: '<S162>/Sign6' incorporates:
     *  Signum: '<S162>/Sign5'
     */
    if (rtb_Gain_c4 < 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = -1.0F;

      /* Signum: '<S162>/Sign5' */
      rtb_TmpSignalConversionAtMult_2 = -1.0F;
    } else if (rtb_Gain_c4 > 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = 1.0F;

      /* Signum: '<S162>/Sign5' */
      rtb_TmpSignalConversionAtMult_2 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_1 = rtb_Gain_c4;

      /* Signum: '<S162>/Sign5' */
      rtb_TmpSignalConversionAtMult_2 = rtb_Gain_c4;
    }

    /* End of Signum: '<S162>/Sign6' */

    /* Sum: '<S162>/Add6' */
    rtb_Add3_fc = rtb_Gain_c4 + Controller_ConstB.d_i;

    /* Sum: '<S162>/Subtract3' */
    rtb_TmpSignalConversionAtMult_0 = rtb_Gain_c4 - Controller_ConstB.d_i;

    /* Signum: '<S162>/Sign3' */
    if (rtb_Add3_fc < 0.0F) {
      rtb_Add3_fc = -1.0F;
    } else {
      if (rtb_Add3_fc > 0.0F) {
        rtb_Add3_fc = 1.0F;
      }
    }

    /* End of Signum: '<S162>/Sign3' */

    /* Signum: '<S162>/Sign4' */
    if (rtb_TmpSignalConversionAtMult_0 < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else {
      if (rtb_TmpSignalConversionAtMult_0 > 0.0F) {
        rtb_TmpSignalConversionAtMult_0 = 1.0F;
      }
    }

    /* End of Signum: '<S162>/Sign4' */

    /* Update for DiscreteIntegrator: '<S161>/Integrator' incorporates:
     *  Constant: '<S162>/const'
     *  Gain: '<S162>/Gain3'
     *  Product: '<S162>/Divide'
     *  Product: '<S162>/Multiply5'
     *  Product: '<S162>/Multiply6'
     *  Sum: '<S162>/Subtract4'
     *  Sum: '<S162>/Subtract5'
     *  Sum: '<S162>/Subtract6'
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

  /* Output and update for atomic system: '<S168>/VTOL1' */
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

    /* Saturate: '<S179>/Saturation' incorporates:
     *  Bias: '<S179>/Bias'
     *  Bias: '<S179>/Bias1'
     *  Bias: '<S179>/Bias2'
     *  Bias: '<S179>/Bias3'
     *  Constant: '<S179>/Constant'
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

    /* End of Saturate: '<S179>/Saturation' */

    /* MultiPortSwitch: '<S173>/Multiport Switch' incorporates:
     *  Constant: '<S174>/Constant1'
     *  Constant: '<S174>/Constant12'
     *  Constant: '<S174>/Constant2'
     *  Constant: '<S174>/Constant7'
     *  DataTypeConversion: '<S179>/Data Type Conversion'
     *  DataTypeConversion: '<S180>/Data Type Conversion'
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
        /* Saturate: '<S180>/Saturation' incorporates:
         *  Constant: '<S180>/Disarm'
         *  Reshape: '<S180>/Reshape'
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

      /* Saturate: '<S180>/Saturation' incorporates:
       *  Bias: '<S180>/Bias'
       *  Constant: '<S180>/Constant'
       *  DataTypeConversion: '<S180>/Data Type Conversion'
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

      /* Saturate: '<S180>/Saturation' incorporates:
       *  Bias: '<S180>/Bias1'
       *  Constant: '<S180>/Constant'
       *  DataTypeConversion: '<S180>/Data Type Conversion'
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

      /* Saturate: '<S180>/Saturation' incorporates:
       *  Bias: '<S180>/Bias2'
       *  Constant: '<S180>/Constant'
       *  DataTypeConversion: '<S180>/Data Type Conversion'
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

      /* Saturate: '<S180>/Saturation' incorporates:
       *  Bias: '<S180>/Bias3'
       *  Constant: '<S180>/Constant'
       *  DataTypeConversion: '<S180>/Data Type Conversion'
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

      /* SignalConversion: '<S174>/ConcatBufferAtVector Concatenate2In3' incorporates:
       *  Constant: '<S174>/Constant11'
       *  Constant: '<S174>/Constant12'
       */
      rtb_MatrixConcatenate[10] = 0.0F;

      /* SignalConversion: '<S174>/ConcatBufferAtVector Concatenate2In2' incorporates:
       *  Constant: '<S174>/Constant10'
       */
      rtb_MatrixConcatenate[9] = 0.0F;

      /* SignalConversion: '<S174>/ConcatBufferAtVector Concatenate2In1' incorporates:
       *  Constant: '<S174>/Constant9'
       */
      rtb_MatrixConcatenate[8] = 0.0F;

      /* SignalConversion: '<S174>/ConcatBufferAtVector Concatenate1In4' incorporates:
       *  Constant: '<S174>/Constant8'
       */
      rtb_MatrixConcatenate[7] = 0.0F;
      rtb_MatrixConcatenate[6] = CONTROL_PARAM.FW_PITCH_EFFC *
        CONTROL_PARAM.FW_ELEVATOR_DIR;

      /* SignalConversion: '<S174>/ConcatBufferAtVector Concatenate1In2' incorporates:
       *  Constant: '<S174>/Constant6'
       *  Constant: '<S174>/Constant7'
       */
      rtb_MatrixConcatenate[5] = 0.0F;

      /* SignalConversion: '<S174>/ConcatBufferAtVector Concatenate1In1' incorporates:
       *  Constant: '<S174>/Constant5'
       */
      rtb_MatrixConcatenate[4] = 0.0F;

      /* SignalConversion: '<S174>/ConcatBufferAtVector ConcatenateIn4' incorporates:
       *  Constant: '<S174>/Constant4'
       */
      rtb_MatrixConcatenate[3] = 0.0F;

      /* SignalConversion: '<S174>/ConcatBufferAtVector ConcatenateIn3' incorporates:
       *  Constant: '<S174>/Constant3'
       */
      rtb_MatrixConcatenate[2] = 0.0F;
      rtb_MatrixConcatenate[1] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON2_DIR;
      rtb_MatrixConcatenate[0] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON1_DIR;

      /* Saturate: '<S171>/Saturation5' incorporates:
       *  Constant: '<S174>/Constant1'
       *  Constant: '<S174>/Constant2'
       */
      if (Controller_B.fw_torque_cmd[0] > 1.0F) {
        /* Product: '<S171>/Multiply1' */
        tmp_c = 1.0F;
      } else if (Controller_B.fw_torque_cmd[0] < -1.0F) {
        /* Product: '<S171>/Multiply1' */
        tmp_c = -1.0F;
      } else {
        /* Product: '<S171>/Multiply1' */
        tmp_c = Controller_B.fw_torque_cmd[0];
      }

      if (Controller_B.fw_torque_cmd[1] > 1.0F) {
        /* Product: '<S171>/Multiply1' */
        tmp_d = 1.0F;
      } else if (Controller_B.fw_torque_cmd[1] < -1.0F) {
        /* Product: '<S171>/Multiply1' */
        tmp_d = -1.0F;
      } else {
        /* Product: '<S171>/Multiply1' */
        tmp_d = Controller_B.fw_torque_cmd[1];
      }

      if (Controller_B.fw_torque_cmd[2] > 1.0F) {
        /* Product: '<S171>/Multiply1' */
        tmp_nk = 1.0F;
      } else if (Controller_B.fw_torque_cmd[2] < -1.0F) {
        /* Product: '<S171>/Multiply1' */
        tmp_nk = -1.0F;
      } else {
        /* Product: '<S171>/Multiply1' */
        tmp_nk = Controller_B.fw_torque_cmd[2];
      }

      /* End of Saturate: '<S171>/Saturation5' */
      for (i_p = 0; i_p < 4; i_p++) {
        /* Bias: '<S171>/Bias' incorporates:
         *  Gain: '<S171>/Gain1'
         *  Product: '<S171>/Multiply1'
         */
        rtb_Multiply_fw[i_p] = 500.0F * (rtb_MatrixConcatenate[i_p + 8] * tmp_nk
          + (rtb_MatrixConcatenate[i_p + 4] * tmp_d + rtb_MatrixConcatenate[i_p]
             * tmp_c)) + 1500.0F;
      }

      /* Saturate: '<S172>/Saturation2' */
      if (Controller_B.mc_force_cmd[2] > 1.0F) {
        tmp_a = 1.0F;
      } else if (Controller_B.mc_force_cmd[2] < 0.0F) {
        tmp_a = 0.0F;
      } else {
        tmp_a = Controller_B.mc_force_cmd[2];
      }

      /* End of Saturate: '<S172>/Saturation2' */

      /* DataTypeConversion: '<S178>/Data Type Conversion' incorporates:
       *  Constant: '<S178>/Constant1'
       *  Gain: '<S178>/Gain1'
       *  Sum: '<S178>/Sum1'
       */
      rtb_DataTypeConversion_i = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
        tmp_a), 4.2949673E+9F) + 1000U);

      /* Saturate: '<S172>/Saturation1' */
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

      /* End of Saturate: '<S172>/Saturation1' */

      /* Saturate: '<S171>/Saturation' */
      if (Controller_B.fw_force_cmd[0] > 1.0F) {
        tmp_a = 1.0F;
      } else if (Controller_B.fw_force_cmd[0] < 0.0F) {
        tmp_a = 0.0F;
      } else {
        tmp_a = Controller_B.fw_force_cmd[0];
      }

      /* End of Saturate: '<S171>/Saturation' */

      /* Saturate: '<S171>/Saturation1' incorporates:
       *  Constant: '<S176>/Constant1'
       *  DataTypeConversion: '<S176>/Data Type Conversion'
       *  Gain: '<S176>/Gain1'
       *  Sum: '<S176>/Sum1'
       */
      tmp_p[0] = (uint16_T)((uint32_T)fmodf(floorf(1000.0F * tmp_a),
        4.2949673E+9F) + 1000U);

      /* DataTypeConversion: '<S171>/Data Type Conversion' incorporates:
       *  Bias: '<S171>/Bias1'
       */
      tmp_a = fmodf(floorf(rtb_Multiply_fw[0] + CONTROL_PARAM.SERVO1_BIAS),
                    65536.0F);

      /* Saturate: '<S171>/Saturation1' incorporates:
       *  DataTypeConversion: '<S171>/Data Type Conversion'
       */
      tmp_p[1] = (uint16_T)(tmp_a < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_a : (int32_T)(uint16_T)tmp_a);

      /* DataTypeConversion: '<S171>/Data Type Conversion1' incorporates:
       *  Bias: '<S171>/Bias2'
       */
      tmp_a = fmodf(floorf(rtb_Multiply_fw[1] + CONTROL_PARAM.SERVO2_BIAS),
                    65536.0F);

      /* Saturate: '<S171>/Saturation1' incorporates:
       *  DataTypeConversion: '<S171>/Data Type Conversion1'
       */
      tmp_p[2] = (uint16_T)(tmp_a < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_a : (int32_T)(uint16_T)tmp_a);

      /* DataTypeConversion: '<S171>/Data Type Conversion2' incorporates:
       *  Bias: '<S171>/Bias3'
       */
      tmp_a = fmodf(floorf(rtb_Multiply_fw[2] + CONTROL_PARAM.SERVO3_BIAS),
                    65536.0F);

      /* Saturate: '<S171>/Saturation1' incorporates:
       *  DataTypeConversion: '<S171>/Data Type Conversion2'
       */
      tmp_p[3] = (uint16_T)(tmp_a < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_a : (int32_T)(uint16_T)tmp_a);

      /* DataTypeConversion: '<S171>/Data Type Conversion3' incorporates:
       *  Bias: '<S171>/Bias4'
       */
      tmp_a = fmodf(floorf(rtb_Multiply_fw[3] + CONTROL_PARAM.SERVO4_BIAS),
                    65536.0F);

      /* Saturate: '<S171>/Saturation1' incorporates:
       *  DataTypeConversion: '<S171>/Data Type Conversion3'
       */
      tmp_p[4] = (uint16_T)(tmp_a < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_a : (int32_T)(uint16_T)tmp_a);

      /* Product: '<S172>/Multiply' */
      for (i_p = 0; i_p < 4; i_p++) {
        /* Saturate: '<S172>/Saturation' incorporates:
         *  Constant: '<S172>/Effective_Matrix'
         *  Gain: '<S172>/Gain'
         *  Sum: '<S172>/Add'
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

        /* End of Saturate: '<S172>/Saturation' */
      }

      /* End of Product: '<S172>/Multiply' */
      for (i_p = 0; i_p < 5; i_p++) {
        /* Saturate: '<S171>/Saturation1' */
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

    /* End of MultiPortSwitch: '<S173>/Multiport Switch' */
  }

#elif AIRFRAME == 2

  /* Output and update for atomic system: '<S168>/VTOL2' */
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

    /* Saturate: '<S189>/Saturation' incorporates:
     *  Bias: '<S189>/Bias'
     *  Bias: '<S189>/Bias1'
     *  Bias: '<S189>/Bias2'
     *  Bias: '<S189>/Bias3'
     *  Constant: '<S189>/Constant'
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

    /* End of Saturate: '<S189>/Saturation' */

    /* MultiPortSwitch: '<S183>/Multiport Switch' incorporates:
     *  Constant: '<S184>/Constant1'
     *  Constant: '<S184>/Constant11'
     *  Constant: '<S184>/Constant12'
     *  Constant: '<S184>/Constant2'
     *  Constant: '<S184>/Constant7'
     *  Constant: '<S184>/Constant8'
     *  DataTypeConversion: '<S189>/Data Type Conversion'
     *  DataTypeConversion: '<S190>/Data Type Conversion'
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
        /* Saturate: '<S190>/Saturation' incorporates:
         *  Constant: '<S190>/Disarm'
         *  Reshape: '<S190>/Reshape'
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

      /* Saturate: '<S190>/Saturation' incorporates:
       *  Bias: '<S190>/Bias'
       *  Constant: '<S190>/Constant'
       *  DataTypeConversion: '<S190>/Data Type Conversion'
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

      /* Saturate: '<S190>/Saturation' incorporates:
       *  Bias: '<S190>/Bias1'
       *  Constant: '<S190>/Constant'
       *  DataTypeConversion: '<S190>/Data Type Conversion'
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

      /* Saturate: '<S190>/Saturation' incorporates:
       *  Bias: '<S190>/Bias2'
       *  Constant: '<S190>/Constant'
       *  DataTypeConversion: '<S190>/Data Type Conversion'
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

      /* Saturate: '<S190>/Saturation' incorporates:
       *  Bias: '<S190>/Bias3'
       *  Constant: '<S190>/Constant'
       *  DataTypeConversion: '<S190>/Data Type Conversion'
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

      /* SignalConversion: '<S184>/ConcatBufferAtVector Concatenate2In2' incorporates:
       *  Constant: '<S184>/Constant10'
       *  Constant: '<S184>/Constant11'
       *  Constant: '<S184>/Constant12'
       */
      rtb_MatrixConcatenate_g[9] = 0.0F;

      /* SignalConversion: '<S184>/ConcatBufferAtVector Concatenate2In1' incorporates:
       *  Constant: '<S184>/Constant9'
       */
      rtb_MatrixConcatenate_g[8] = 0.0F;
      rtb_MatrixConcatenate_g[7] = -CONTROL_PARAM.FW_PITCH_EFFC *
        CONTROL_PARAM.FW_TAIL2_DIR;
      rtb_MatrixConcatenate_g[6] = CONTROL_PARAM.FW_PITCH_EFFC *
        CONTROL_PARAM.FW_TAIL1_DIR;

      /* SignalConversion: '<S184>/ConcatBufferAtVector Concatenate1In2' incorporates:
       *  Constant: '<S184>/Constant6'
       *  Constant: '<S184>/Constant7'
       *  Constant: '<S184>/Constant8'
       */
      rtb_MatrixConcatenate_g[5] = 0.0F;

      /* SignalConversion: '<S184>/ConcatBufferAtVector Concatenate1In1' incorporates:
       *  Constant: '<S184>/Constant5'
       */
      rtb_MatrixConcatenate_g[4] = 0.0F;

      /* SignalConversion: '<S184>/ConcatBufferAtVector ConcatenateIn4' incorporates:
       *  Constant: '<S184>/Constant4'
       */
      rtb_MatrixConcatenate_g[3] = 0.0F;

      /* SignalConversion: '<S184>/ConcatBufferAtVector ConcatenateIn3' incorporates:
       *  Constant: '<S184>/Constant3'
       */
      rtb_MatrixConcatenate_g[2] = 0.0F;
      rtb_MatrixConcatenate_g[1] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON2_DIR;
      rtb_MatrixConcatenate_g[0] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON1_DIR;

      /* Saturate: '<S181>/Saturation5' incorporates:
       *  Constant: '<S184>/Constant1'
       *  Constant: '<S184>/Constant2'
       */
      if (Controller_B.fw_torque_cmd[0] > 1.0F) {
        /* Product: '<S181>/Multiply1' */
        tmp_m = 1.0F;
      } else if (Controller_B.fw_torque_cmd[0] < -1.0F) {
        /* Product: '<S181>/Multiply1' */
        tmp_m = -1.0F;
      } else {
        /* Product: '<S181>/Multiply1' */
        tmp_m = Controller_B.fw_torque_cmd[0];
      }

      if (Controller_B.fw_torque_cmd[1] > 1.0F) {
        /* Product: '<S181>/Multiply1' */
        tmp_ev = 1.0F;
      } else if (Controller_B.fw_torque_cmd[1] < -1.0F) {
        /* Product: '<S181>/Multiply1' */
        tmp_ev = -1.0F;
      } else {
        /* Product: '<S181>/Multiply1' */
        tmp_ev = Controller_B.fw_torque_cmd[1];
      }

      if (Controller_B.fw_torque_cmd[2] > 1.0F) {
        /* Product: '<S181>/Multiply1' */
        tmp_k = 1.0F;
      } else if (Controller_B.fw_torque_cmd[2] < -1.0F) {
        /* Product: '<S181>/Multiply1' */
        tmp_k = -1.0F;
      } else {
        /* Product: '<S181>/Multiply1' */
        tmp_k = Controller_B.fw_torque_cmd[2];
      }

      /* End of Saturate: '<S181>/Saturation5' */
      for (i_o = 0; i_o < 4; i_o++) {
        /* Bias: '<S181>/Bias' incorporates:
         *  Gain: '<S181>/Gain1'
         *  Product: '<S181>/Multiply1'
         */
        rtb_Multiply_ka[i_o] = 500.0F * (rtb_MatrixConcatenate_g[i_o + 8] *
          tmp_k + (rtb_MatrixConcatenate_g[i_o + 4] * tmp_ev +
                   rtb_MatrixConcatenate_g[i_o] * tmp_m)) + 1500.0F;
      }

      /* Saturate: '<S182>/Saturation2' */
      if (Controller_B.mc_force_cmd[2] > 1.0F) {
        tmp_gf = 1.0F;
      } else if (Controller_B.mc_force_cmd[2] < 0.0F) {
        tmp_gf = 0.0F;
      } else {
        tmp_gf = Controller_B.mc_force_cmd[2];
      }

      /* End of Saturate: '<S182>/Saturation2' */

      /* DataTypeConversion: '<S188>/Data Type Conversion' incorporates:
       *  Constant: '<S188>/Constant1'
       *  Gain: '<S188>/Gain1'
       *  Sum: '<S188>/Sum1'
       */
      rtb_DataTypeConversion_o = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
        tmp_gf), 4.2949673E+9F) + 1000U);

      /* Saturate: '<S182>/Saturation1' */
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

      /* End of Saturate: '<S182>/Saturation1' */

      /* Saturate: '<S181>/Saturation4' */
      if (Controller_B.fw_force_cmd[0] > 1.0F) {
        tmp_gf = 1.0F;
      } else if (Controller_B.fw_force_cmd[0] < 0.0F) {
        tmp_gf = 0.0F;
      } else {
        tmp_gf = Controller_B.fw_force_cmd[0];
      }

      /* End of Saturate: '<S181>/Saturation4' */

      /* Saturate: '<S181>/Saturation1' incorporates:
       *  Constant: '<S186>/Constant1'
       *  DataTypeConversion: '<S186>/Data Type Conversion'
       *  Gain: '<S186>/Gain1'
       *  Sum: '<S186>/Sum1'
       */
      tmp_o[0] = (uint16_T)((uint32_T)fmodf(floorf(1000.0F * tmp_gf),
        4.2949673E+9F) + 1000U);

      /* DataTypeConversion: '<S181>/Data Type Conversion' incorporates:
       *  Bias: '<S181>/Bias1'
       */
      tmp_gf = fmodf(floorf(rtb_Multiply_ka[0] + CONTROL_PARAM.SERVO1_BIAS),
                     65536.0F);

      /* Saturate: '<S181>/Saturation1' incorporates:
       *  DataTypeConversion: '<S181>/Data Type Conversion'
       */
      tmp_o[1] = (uint16_T)(tmp_gf < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_gf : (int32_T)(uint16_T)tmp_gf);

      /* DataTypeConversion: '<S181>/Data Type Conversion1' incorporates:
       *  Bias: '<S181>/Bias2'
       */
      tmp_gf = fmodf(floorf(rtb_Multiply_ka[1] + CONTROL_PARAM.SERVO2_BIAS),
                     65536.0F);

      /* Saturate: '<S181>/Saturation1' incorporates:
       *  DataTypeConversion: '<S181>/Data Type Conversion1'
       */
      tmp_o[2] = (uint16_T)(tmp_gf < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_gf : (int32_T)(uint16_T)tmp_gf);

      /* DataTypeConversion: '<S181>/Data Type Conversion2' incorporates:
       *  Bias: '<S181>/Bias3'
       */
      tmp_gf = fmodf(floorf(rtb_Multiply_ka[2] + CONTROL_PARAM.SERVO3_BIAS),
                     65536.0F);

      /* Saturate: '<S181>/Saturation1' incorporates:
       *  DataTypeConversion: '<S181>/Data Type Conversion2'
       */
      tmp_o[3] = (uint16_T)(tmp_gf < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_gf : (int32_T)(uint16_T)tmp_gf);

      /* DataTypeConversion: '<S181>/Data Type Conversion3' incorporates:
       *  Bias: '<S181>/Bias4'
       */
      tmp_gf = fmodf(floorf(rtb_Multiply_ka[3] + CONTROL_PARAM.SERVO4_BIAS),
                     65536.0F);

      /* Saturate: '<S181>/Saturation1' incorporates:
       *  DataTypeConversion: '<S181>/Data Type Conversion3'
       */
      tmp_o[4] = (uint16_T)(tmp_gf < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_gf : (int32_T)(uint16_T)tmp_gf);

      /* Product: '<S182>/Multiply' */
      for (i_o = 0; i_o < 4; i_o++) {
        /* Saturate: '<S182>/Saturation' incorporates:
         *  Constant: '<S182>/Effective_Matrix'
         *  Gain: '<S182>/Gain'
         *  Sum: '<S182>/Add'
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

        /* End of Saturate: '<S182>/Saturation' */
      }

      /* End of Product: '<S182>/Multiply' */
      for (i_o = 0; i_o < 5; i_o++) {
        /* Saturate: '<S181>/Saturation1' */
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

    /* End of MultiPortSwitch: '<S183>/Multiport Switch' */
  }

#endif

  /* End of Outputs for SubSystem: '<S6>/VTOL_Control_Allocation' */

  /* Outport: '<Root>/Control_Out' incorporates:
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   *  Reshape: '<S167>/Reshape'
   */
  Controller_Y.Control_Out.timestamp =
    Controller_DW.DiscreteTimeIntegrator_DSTATE_n;
  for (i = 0; i < 9; i++) {
    Controller_Y.Control_Out.actuator_cmd[i] = rtb_VariantMergeForOutportactua[i];
  }

  for (i = 0; i < 7; i++) {
    Controller_Y.Control_Out.actuator_cmd[i + 9] = 0U;
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
  /* Start for Constant: '<S51>/Constant' */
  Controller_B.Constant_m = CONTROL_PARAM.MC_VEL_Z_I_MIN;

  /* End of Start for SubSystem: '<S2>/FW_Controller' */

  /* Start for IfAction SubSystem: '<S2>/MC_Controller' */
  /* Start for Constant: '<S164>/Constant' */
  Controller_B.Constant = CONTROL_PARAM.MC_VEL_Z_I_MIN;

  /* End of Start for SubSystem: '<S2>/MC_Controller' */

  /* SystemInitialize for IfAction SubSystem: '<S2>/FW_Controller' */
  /* InitializeConditions for DiscreteIntegrator: '<S59>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_e = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S56>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_L_eo = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S55>/Discrete-Time Integrator5' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S103>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_n = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S98>/ ' */
  Controller_DW._DSTATE = Controller_ConstB.Zero1;
  if (Controller_DW._DSTATE >= CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
    Controller_DW._DSTATE = CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
  } else {
    if (Controller_DW._DSTATE <= -CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
      Controller_DW._DSTATE = -CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
    }
  }

  Controller_DW._PrevResetState = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S98>/ ' */

  /* InitializeConditions for DiscreteIntegrator: '<S99>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_f = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_b = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S24>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_b = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S28>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_h = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_l = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S101>/ ' */
  Controller_DW._DSTATE_d = Controller_ConstB.Zero;
  if (Controller_DW._DSTATE_d >= 1.0F) {
    Controller_DW._DSTATE_d = 1.0F;
  } else {
    if (Controller_DW._DSTATE_d <= 0.0F) {
      Controller_DW._DSTATE_d = 0.0F;
    }
  }

  Controller_DW._PrevResetState_e = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S101>/ ' */

  /* InitializeConditions for DiscreteIntegrator: '<S102>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_L_h0 = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_d = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S48>/Integrator1' */
  Controller_DW.Integrator1_DSTATE_i = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S51>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S51>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S53>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_i = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_h = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S54>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_g = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S77>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_PrevR_ef = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S48>/Integrator' */
  Controller_DW.Integrator_DSTATE_f = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S77>/Discrete-Time Integrator' */
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
  /* InitializeConditions for DiscreteIntegrator: '<S121>/Discrete-Time Integrator' */
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
  /* InitializeConditions for DiscreteIntegrator: '<S77>/Discrete-Time Integrator' */
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
  /* InitializeConditions for DiscreteIntegrator: '<S121>/Discrete-Time Integrator' */
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
  /* InitializeConditions for DiscreteIntegrator: '<S77>/Discrete-Time Integrator' */
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
  /* InitializeConditions for DiscreteIntegrator: '<S121>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S148>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_PrevRe_p = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S150>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S119>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S123>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_k = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S143>/Integrator1' */
  Controller_DW.Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S148>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S143>/Integrator' */
  Controller_DW.Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S143>/Integrator1' */
  Controller_DW.Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S148>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S143>/Integrator' */
  Controller_DW.Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S161>/Integrator1' */
  Controller_DW.Integrator1_DSTATE_e = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S164>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S164>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S166>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 1U;
  Controller_DW.DiscreteTimeIntegrator1_Prev_ks = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S161>/Integrator' */
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
