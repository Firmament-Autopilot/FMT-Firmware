/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.572
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Aug 20 09:48:40 2025
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
struct_mdDdQrQ86BvYjyHVnXla1 CONTROL_PARAM = {
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
  0.3F,
  0.3F,
  0.6F,
  0.3F,
  0.3F,
  0.4F,
  0.009F,
  0.009F,
  0.002F,
  -0.25F,
  0.25F,
  -0.25F,
  0.25F,
  1.57079637F,
  3.14159274F,
  0.5F,
  2000U,
  1000U,
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
  0.785398185F,
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
  2000U,
  1000U,
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
                                        *   '<S65>/Saturation'
                                        *   '<S66>/Gain'
                                        *   '<S66>/Gain1'
                                        *   '<S66>/balabnce_ratio2'
                                        *   '<S66>/balance_ratio'
                                        *   '<S66>/pitch_ff'
                                        *   '<S66>/thorttle_ff'
                                        *   '<S66>/ucmd2pitch'
                                        *   '<S66>/ucmd2thor'
                                        *   '<S66>/wcmd2pitch'
                                        *   '<S66>/wcmd2thor'
                                        *   '<S153>/hover_throttle'
                                        *   '<S40>/hover_throttle'
                                        *   '<S68>/FF'
                                        *   '<S68>/FF_limit'
                                        *   '<S68>/PI_limit'
                                        *   '<S86>/P_control'
                                        *   '<S87>/P_control'
                                        *   '<S88>/Kv'
                                        *   '<S135>/Saturation'
                                        *   '<S168>/Bias1'
                                        *   '<S168>/Bias2'
                                        *   '<S168>/Bias3'
                                        *   '<S168>/Bias4'
                                        *   '<S168>/Saturation1'
                                        *   '<S169>/Constant'
                                        *   '<S169>/Constant1'
                                        *   '<S169>/Saturation'
                                        *   '<S184>/Bias1'
                                        *   '<S184>/Bias2'
                                        *   '<S184>/Bias3'
                                        *   '<S184>/Bias4'
                                        *   '<S20>/Saturation'
                                        *   '<S20>/Saturation1'
                                        *   '<S72>/trim_speed'
                                        *   '<S73>/trim_speed'
                                        *   '<S77>/Saturation'
                                        *   '<S94>/Gain'
                                        *   '<S95>/ '
                                        *   '<S95>/Gain3'
                                        *   '<S97>/Gain'
                                        *   '<S98>/Gain'
                                        *   '<S111>/Saturation'
                                        *   '<S111>/Saturation1'
                                        *   '<S144>/kd'
                                        *   '<S144>/Saturation'
                                        *   '<S145>/ki'
                                        *   '<S145>/Discrete-Time Integrator'
                                        *   '<S146>/kp'
                                        *   '<S160>/kd'
                                        *   '<S160>/Saturation'
                                        *   '<S161>/Constant'
                                        *   '<S161>/ki'
                                        *   '<S161>/Discrete-Time Integrator'
                                        *   '<S162>/kp'
                                        *   '<S173>/Constant1'
                                        *   '<S173>/Constant12'
                                        *   '<S173>/Constant2'
                                        *   '<S173>/Constant7'
                                        *   '<S182>/Bias'
                                        *   '<S182>/Bias1'
                                        *   '<S182>/Bias2'
                                        *   '<S182>/Bias3'
                                        *   '<S183>/Bias'
                                        *   '<S183>/Bias1'
                                        *   '<S183>/Bias2'
                                        *   '<S183>/Bias3'
                                        *   '<S187>/Constant1'
                                        *   '<S187>/Constant11'
                                        *   '<S187>/Constant12'
                                        *   '<S187>/Constant2'
                                        *   '<S187>/Constant7'
                                        *   '<S187>/Constant8'
                                        *   '<S191>/Bias'
                                        *   '<S191>/Bias1'
                                        *   '<S191>/Bias2'
                                        *   '<S191>/Bias3'
                                        *   '<S192>/Bias'
                                        *   '<S192>/Bias1'
                                        *   '<S192>/Bias2'
                                        *   '<S192>/Bias3'
                                        *   '<S32>/Constant1'
                                        *   '<S32>/Constant2'
                                        *   '<S47>/kd'
                                        *   '<S47>/Saturation'
                                        *   '<S48>/Constant'
                                        *   '<S48>/ki'
                                        *   '<S48>/Discrete-Time Integrator'
                                        *   '<S49>/kp'
                                        *   '<S74>/gain1'
                                        *   '<S74>/gain2'
                                        *   '<S74>/gain3'
                                        *   '<S74>/Discrete-Time Integrator'
                                        *   '<S75>/gain1'
                                        *   '<S75>/gain2'
                                        *   '<S75>/gain3'
                                        *   '<S79>/Pitch Offset'
                                        *   '<S79>/Saturation'
                                        *   '<S80>/Constant1'
                                        *   '<S80>/Constant2'
                                        *   '<S128>/Constant1'
                                        *   '<S128>/Constant2'
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
                                        *   '<S117>/gain1'
                                        *   '<S117>/gain2'
                                        *   '<S117>/gain3'
                                        *   '<S117>/Saturation'
                                        *   '<S118>/gain1'
                                        *   '<S118>/gain2'
                                        *   '<S118>/gain3'
                                        *   '<S118>/Discrete-Time Integrator'
                                        *   '<S119>/gain1'
                                        *   '<S119>/gain2'
                                        *   '<S119>/gain3'
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
   *  Constant: '<S161>/Constant'
   *  Constant: '<S48>/Constant'
   *  DataTypeConversion: '<S8>/Data Type Conversion'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S117>/Multiply'
   *  Product: '<S130>/Divide1'
   *  Product: '<S144>/Multiply'
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
       *  DiscreteIntegrator: '<S100>/Discrete-Time Integrator5'
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
       *  DiscreteIntegrator: '<S56>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S74>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S95>/ '
       *  DiscreteIntegrator: '<S96>/Discrete-Time Integrator1'
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
    /* SignalConversion: '<S57>/TmpSignal ConversionAtMultiplyInport2' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_TmpSignalConversionAtMult_0 = Controller_U.INS_Out.vn;
    rtb_TmpSignalConversionAtMult_1 = Controller_U.INS_Out.ve;
    rtb_TmpSignalConversionAtMult_2 = Controller_U.INS_Out.vd;

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

    /* S-Function (sfix_bitop): '<S54>/vel_valid' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  S-Function (sfix_bitop): '<S89>/Bitwise AND'
     *  S-Function (sfix_bitop): '<S90>/Bitwise AND'
     *  S-Function (sfix_bitop): '<S91>/Bitwise AND'
     */
    tmp = Controller_U.INS_Out.flag & 16U;

    /* Switch: '<S54>/Switch' incorporates:
     *  Constant: '<S55>/Constant'
     *  Inport: '<Root>/INS_Out'
     *  Logic: '<S54>/Logical Operator'
     *  Logic: '<S54>/Logical Operator1'
     *  Math: '<S54>/Square2'
     *  Math: '<S54>/Square3'
     *  Product: '<S54>/Multiply'
     *  RelationalOperator: '<S55>/Compare'
     *  Relay: '<S54>/Relay'
     *  S-Function (sfix_bitop): '<S54>/airspeed_valid'
     *  S-Function (sfix_bitop): '<S54>/vel_valid'
     *  Sqrt: '<S54>/Sqrt'
     *  Sum: '<S54>/Add'
     */
    if ((Controller_DW.Relay_Mode && ((Controller_U.INS_Out.flag & 512U) != 0U))
        || (tmp == 0U)) {
      rtb_Divide_m_idx_0 = Controller_U.INS_Out.airspeed;
    } else {
      /* Sqrt: '<S63>/Sqrt' incorporates:
       *  Math: '<S63>/Square'
       *  Sum: '<S63>/Sum of Elements'
       */
      rtb_Square_d = sqrtf(((Controller_U.INS_Out.quat[0] *
        Controller_U.INS_Out.quat[0] + Controller_U.INS_Out.quat[1] *
        Controller_U.INS_Out.quat[1]) + Controller_U.INS_Out.quat[2] *
                            Controller_U.INS_Out.quat[2]) +
                           Controller_U.INS_Out.quat[3] *
                           Controller_U.INS_Out.quat[3]);

      /* Product: '<S59>/Divide' */
      rtb_Divide_m_idx_0 = Controller_U.INS_Out.quat[0] / rtb_Square_d;
      rtb_Divide_m_idx_1 = Controller_U.INS_Out.quat[1] / rtb_Square_d;
      rtb_Divide_m_idx_2 = Controller_U.INS_Out.quat[2] / rtb_Square_d;
      rtb_Divide_m_idx_3 = Controller_U.INS_Out.quat[3] / rtb_Square_d;

      /* Math: '<S62>/Square' incorporates:
       *  Math: '<S60>/Square'
       *  Math: '<S61>/Square'
       */
      rtb_Square_d = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_0;

      /* Math: '<S62>/Square2' incorporates:
       *  Math: '<S60>/Square2'
       *  Math: '<S61>/Square2'
       */
      rtb_Gain_c4 = rtb_Divide_m_idx_2 * rtb_Divide_m_idx_2;

      /* Math: '<S62>/Square1' incorporates:
       *  Math: '<S60>/Square1'
       *  Math: '<S61>/Square1'
       */
      rtb_Add3_fc = rtb_Divide_m_idx_1 * rtb_Divide_m_idx_1;

      /* Math: '<S62>/Square3' incorporates:
       *  Math: '<S60>/Square3'
       *  Math: '<S61>/Square3'
       */
      rtb_aux_att_error_B_rad_idx_0 = rtb_Divide_m_idx_3 * rtb_Divide_m_idx_3;

      /* Sum: '<S62>/Subtract' incorporates:
       *  Math: '<S62>/Square'
       *  Math: '<S62>/Square1'
       *  Math: '<S62>/Square2'
       *  Math: '<S62>/Square3'
       *  Sum: '<S62>/Add'
       *  Sum: '<S62>/Add1'
       */
      rtb_MatrixConcatenate1[8] = (rtb_Square_d + rtb_aux_att_error_B_rad_idx_0)
        - (rtb_Add3_fc + rtb_Gain_c4);

      /* Product: '<S62>/Multiply2' incorporates:
       *  Product: '<S61>/Multiply2'
       */
      rtb_aux_att_error_B_rad_idx_1 = rtb_Divide_m_idx_2 * rtb_Divide_m_idx_3;

      /* Product: '<S62>/Multiply3' incorporates:
       *  Product: '<S61>/Multiply3'
       */
      rtb_Saturation_g = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_1;

      /* Gain: '<S62>/Gain1' incorporates:
       *  Product: '<S62>/Multiply2'
       *  Product: '<S62>/Multiply3'
       *  Sum: '<S62>/Add2'
       */
      rtb_MatrixConcatenate1[7] = (rtb_aux_att_error_B_rad_idx_1 +
        rtb_Saturation_g) * 2.0F;

      /* Product: '<S62>/Multiply' incorporates:
       *  Product: '<S60>/Multiply2'
       */
      rtb_Saturation_j_idx_0 = rtb_Divide_m_idx_1 * rtb_Divide_m_idx_3;

      /* Product: '<S62>/Multiply1' incorporates:
       *  Product: '<S60>/Multiply3'
       */
      rtb_phi_cmd = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_2;

      /* Gain: '<S62>/Gain' incorporates:
       *  Product: '<S62>/Multiply'
       *  Product: '<S62>/Multiply1'
       *  Sum: '<S62>/Subtract2'
       */
      rtb_MatrixConcatenate1[6] = (rtb_Saturation_j_idx_0 - rtb_phi_cmd) * 2.0F;

      /* Gain: '<S61>/Gain1' incorporates:
       *  Sum: '<S61>/Subtract1'
       */
      rtb_MatrixConcatenate1[5] = (rtb_aux_att_error_B_rad_idx_1 -
        rtb_Saturation_g) * 2.0F;

      /* Sum: '<S61>/Subtract' incorporates:
       *  Sum: '<S61>/Add'
       *  Sum: '<S61>/Add1'
       */
      rtb_MatrixConcatenate1[4] = (rtb_Square_d + rtb_Gain_c4) - (rtb_Add3_fc +
        rtb_aux_att_error_B_rad_idx_0);

      /* Product: '<S61>/Multiply' incorporates:
       *  Product: '<S60>/Multiply'
       */
      rtb_aux_att_error_B_rad_idx_1 = rtb_Divide_m_idx_1 * rtb_Divide_m_idx_2;

      /* Product: '<S61>/Multiply1' incorporates:
       *  Product: '<S60>/Multiply1'
       */
      rtb_Saturation_g = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_3;

      /* Gain: '<S61>/Gain' incorporates:
       *  Product: '<S61>/Multiply'
       *  Product: '<S61>/Multiply1'
       *  Sum: '<S61>/Add3'
       */
      rtb_MatrixConcatenate1[3] = (rtb_aux_att_error_B_rad_idx_1 +
        rtb_Saturation_g) * 2.0F;

      /* Gain: '<S60>/Gain1' incorporates:
       *  Sum: '<S60>/Add2'
       */
      rtb_MatrixConcatenate1[2] = (rtb_Saturation_j_idx_0 + rtb_phi_cmd) * 2.0F;

      /* Gain: '<S60>/Gain' incorporates:
       *  Sum: '<S60>/Subtract1'
       */
      rtb_MatrixConcatenate1[1] = (rtb_aux_att_error_B_rad_idx_1 -
        rtb_Saturation_g) * 2.0F;

      /* Sum: '<S60>/Subtract' incorporates:
       *  Sum: '<S60>/Add'
       *  Sum: '<S60>/Add1'
       */
      rtb_MatrixConcatenate1[0] = (rtb_Square_d + rtb_Add3_fc) - (rtb_Gain_c4 +
        rtb_aux_att_error_B_rad_idx_0);

      /* Product: '<S57>/Multiply' */
      for (i = 0; i < 3; i++) {
        rtb_MatrixConcatenate1_0[i] = rtb_MatrixConcatenate1[i + 6] *
          rtb_TmpSignalConversionAtMult_2 + (rtb_MatrixConcatenate1[i + 3] *
          rtb_TmpSignalConversionAtMult_1 + rtb_MatrixConcatenate1[i] *
          rtb_TmpSignalConversionAtMult_0);
      }

      /* End of Product: '<S57>/Multiply' */

      /* Signum: '<S57>/Sign' */
      if (rtb_MatrixConcatenate1_0[0] < 0.0F) {
        rtb_Divide_m_idx_0 = -1.0F;
      } else if (rtb_MatrixConcatenate1_0[0] > 0.0F) {
        rtb_Divide_m_idx_0 = 1.0F;
      } else {
        rtb_Divide_m_idx_0 = rtb_MatrixConcatenate1_0[0];
      }

      /* End of Signum: '<S57>/Sign' */
      rtb_Divide_m_idx_0 *= sqrtf(Controller_U.INS_Out.vn *
        Controller_U.INS_Out.vn + Controller_U.INS_Out.ve *
        Controller_U.INS_Out.ve);
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

    /* DiscreteIntegrator: '<S56>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_e != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j = rtb_Divide_m_idx_0;
    }

    /* Math: '<S10>/Square' incorporates:
     *  DiscreteIntegrator: '<S56>/Discrete-Time Integrator5'
     *  Math: '<S72>/Square1'
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

    /* Switch: '<S78>/Switch' incorporates:
     *  Logic: '<S78>/Logical Operator'
     *  RelationalOperator: '<S83>/Compare'
     */
    if ((rtb_BitwiseAND_n == 3) || (rtb_BitwiseAND_n == 4)) {
      rtb_phi_cmd = Controller_U.FMS_Out.phi_cmd;
    } else {
      /* Trigonometry: '<S65>/Atan' incorporates:
       *  Gain: '<S65>/g_force'
       */
      rtb_phi_cmd = atanf(0.101936802F * Controller_U.FMS_Out.ay_cmd);

      /* Saturate: '<S65>/Saturation' */
      if (rtb_phi_cmd > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_phi_cmd = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_phi_cmd < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
          rtb_phi_cmd = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
        }
      }

      /* End of Saturate: '<S65>/Saturation' */
    }

    /* End of Switch: '<S78>/Switch' */

    /* Abs: '<S66>/Abs' */
    rtb_Abs = fabsf(rtb_phi_cmd);

    /* Switch: '<S90>/Switch' incorporates:
     *  Constant: '<S90>/Constant'
     */
    if (tmp > 0U) {
      /* SignalConversion: '<S93>/ConcatBufferAtVector ConcatenateIn3' */
      rtb_MatrixConcatenate1[6] = Controller_ConstB.VectorConcatenate3_g[0];
      rtb_MatrixConcatenate1[7] = Controller_ConstB.VectorConcatenate3_g[1];
      rtb_MatrixConcatenate1[8] = Controller_ConstB.VectorConcatenate3_g[2];

      /* SignalConversion: '<S93>/ConcatBufferAtVector Concatenate2In3' incorporates:
       *  Constant: '<S93>/Constant4'
       */
      rtb_MatrixConcatenate1[5] = 0.0F;

      /* Trigonometry: '<S93>/Trigonometric Function3' incorporates:
       *  Gain: '<S92>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S93>/Trigonometric Function1'
       */
      rtb_Square_d = arm_cos_f32(-Controller_U.INS_Out.psi);
      rtb_MatrixConcatenate1[4] = rtb_Square_d;

      /* Trigonometry: '<S93>/Trigonometric Function2' incorporates:
       *  Gain: '<S92>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S93>/Trigonometric Function'
       */
      rtb_Gain_c4 = arm_sin_f32(-Controller_U.INS_Out.psi);

      /* Gain: '<S93>/Gain' incorporates:
       *  Trigonometry: '<S93>/Trigonometric Function2'
       */
      rtb_MatrixConcatenate1[3] = -rtb_Gain_c4;

      /* SignalConversion: '<S93>/ConcatBufferAtVector Concatenate1In3' incorporates:
       *  Constant: '<S93>/Constant3'
       */
      rtb_MatrixConcatenate1[2] = 0.0F;

      /* Trigonometry: '<S93>/Trigonometric Function' */
      rtb_MatrixConcatenate1[1] = rtb_Gain_c4;

      /* Trigonometry: '<S93>/Trigonometric Function1' */
      rtb_MatrixConcatenate1[0] = rtb_Square_d;

      /* Product: '<S90>/Multiply' */
      for (i = 0; i < 3; i++) {
        rtb_Multiply_ni[i] = rtb_MatrixConcatenate1[i + 6] *
          rtb_TmpSignalConversionAtMult_2 + (rtb_MatrixConcatenate1[i + 3] *
          rtb_TmpSignalConversionAtMult_1 + rtb_MatrixConcatenate1[i] *
          rtb_TmpSignalConversionAtMult_0);
      }

      /* End of Product: '<S90>/Multiply' */

      /* DeadZone: '<S90>/Dead Zone' */
      if (rtb_Multiply_ni[0] > 1.0F) {
        rtb_Sum_l = rtb_Multiply_ni[0] - 1.0F;
      } else if (rtb_Multiply_ni[0] >= -1.0F) {
        rtb_Sum_l = 0.0F;
      } else {
        rtb_Sum_l = rtb_Multiply_ni[0] - -1.0F;
      }

      /* End of DeadZone: '<S90>/Dead Zone' */

      /* Signum: '<S90>/Sign' */
      if (rtb_Sum_l < 0.0F) {
        rtb_Sum_l = -1.0F;
      } else {
        if (rtb_Sum_l > 0.0F) {
          rtb_Sum_l = 1.0F;
        }
      }

      /* End of Signum: '<S90>/Sign' */
    } else {
      rtb_Sum_l = 1.0F;
    }

    /* End of Switch: '<S90>/Switch' */

    /* Switch: '<S89>/Switch' incorporates:
     *  Gain: '<S89>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S89>/Divide'
     *  Trigonometry: '<S89>/Asin'
     */
    if (tmp > 1U) {
      /* Sqrt: '<S89>/Sqrt' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Math: '<S89>/Square'
       *  Math: '<S89>/Square1'
       *  Sum: '<S89>/Add'
       */
      rtb_Add3_fc = sqrtf(Controller_U.INS_Out.vn * Controller_U.INS_Out.vn +
                          Controller_U.INS_Out.ve * Controller_U.INS_Out.ve);

      /* Saturate: '<S89>/Saturation' incorporates:
       *  Sqrt: '<S89>/Sqrt'
       */
      if (rtb_Add3_fc > 100.0F) {
        rtb_Add3_fc = 100.0F;
      } else {
        if (rtb_Add3_fc < 8.0F) {
          rtb_Add3_fc = 8.0F;
        }
      }

      /* End of Saturate: '<S89>/Saturation' */

      /* DeadZone: '<S89>/Dead Zone' incorporates:
       *  Inport: '<Root>/INS_Out'
       */
      if (Controller_U.INS_Out.vd > 0.1F) {
        rtb_Saturation_j_idx_1 = Controller_U.INS_Out.vd - 0.1F;
      } else if (Controller_U.INS_Out.vd >= -0.1F) {
        rtb_Saturation_j_idx_1 = 0.0F;
      } else {
        rtb_Saturation_j_idx_1 = Controller_U.INS_Out.vd - -0.1F;
      }

      /* End of DeadZone: '<S89>/Dead Zone' */
      rtb_DiscreteTimeIntegrator5_h5 = atanf(1.0F / rtb_Add3_fc *
        -rtb_Saturation_j_idx_1);
    } else {
      rtb_DiscreteTimeIntegrator5_h5 = Controller_U.INS_Out.theta;
    }

    /* End of Switch: '<S89>/Switch' */

    /* Product: '<S89>/Multiply1' */
    rtb_DiscreteTimeIntegrator5_h5 *= rtb_Sum_l;

    /* Saturate: '<S89>/Saturation1' */
    if (rtb_DiscreteTimeIntegrator5_h5 > 0.785398185F) {
      rtb_DiscreteTimeIntegrator5_h5 = 0.785398185F;
    } else {
      if (rtb_DiscreteTimeIntegrator5_h5 < -0.785398185F) {
        rtb_DiscreteTimeIntegrator5_h5 = -0.785398185F;
      }
    }

    /* End of Saturate: '<S89>/Saturation1' */

    /* DiscreteIntegrator: '<S100>/Discrete-Time Integrator5' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_n != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_f = Controller_U.INS_Out.ax;
    }

    /* Gain: '<S88>/Gain1' incorporates:
     *  DiscreteIntegrator: '<S100>/Discrete-Time Integrator5'
     */
    rtb_VdotPg = 0.101936802F * Controller_DW.DiscreteTimeIntegrator5_DSTAT_f;

    /* Switch: '<S91>/Switch' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Math: '<S91>/Square'
     *  Math: '<S91>/Square1'
     *  Sqrt: '<S91>/Sqrt'
     *  Sum: '<S91>/Add'
     */
    if (tmp > 0U) {
      rtb_Multiply1_e = sqrtf(Controller_U.INS_Out.vn * Controller_U.INS_Out.vn
        + Controller_U.INS_Out.ve * Controller_U.INS_Out.ve);
    } else {
      rtb_Multiply1_e = Controller_U.INS_Out.airspeed;
    }

    /* End of Switch: '<S91>/Switch' */

    /* Saturate: '<S91>/Saturation1' */
    if (rtb_Multiply1_e > 100.0F) {
      rtb_Multiply1_e = 100.0F;
    } else {
      if (rtb_Multiply1_e < 8.0F) {
        rtb_Multiply1_e = 8.0F;
      }
    }

    /* End of Saturate: '<S91>/Saturation1' */

    /* Product: '<S91>/Multiply1' incorporates:
     *  Gain: '<S91>/Gain'
     *  Product: '<S91>/Divide'
     *  Trigonometry: '<S91>/Asin'
     */
    rtb_Sum_l *= atanf(-Controller_U.FMS_Out.w_cmd / rtb_Multiply1_e);

    /* Saturate: '<S91>/Saturation2' */
    if (rtb_Sum_l > 0.785398185F) {
      rtb_Sum_l = 0.785398185F;
    } else {
      if (rtb_Sum_l < -0.785398185F) {
        rtb_Sum_l = -0.785398185F;
      }
    }

    /* End of Saturate: '<S91>/Saturation2' */

    /* Sum: '<S85>/Sum' */
    rtb_Sum_l -= rtb_DiscreteTimeIntegrator5_h5;

    /* Sum: '<S88>/Sum' incorporates:
     *  DiscreteIntegrator: '<S56>/Discrete-Time Integrator5'
     *  Gain: '<S88>/Gain'
     *  Gain: '<S88>/Kv'
     *  Sum: '<S88>/Minus'
     */
    rtb_Multiply1_e = (Controller_U.FMS_Out.u_cmd -
                       Controller_DW.DiscreteTimeIntegrator5_DSTAT_j) *
      CONTROL_PARAM.FW_TECS_VEL_P * 0.101936802F - rtb_VdotPg;

    /* Sum: '<S66>/Minus1' incorporates:
     *  Gain: '<S66>/ucmd2pitch'
     *  Gain: '<S66>/wcmd2pitch'
     */
    rtb_Square_d = CONTROL_PARAM.FW_TECS_W2P * rtb_Sum_l -
      CONTROL_PARAM.FW_TECS_U2P * rtb_Multiply1_e;

    /* DiscreteIntegrator: '<S95>/ ' */
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

    /* DiscreteIntegrator: '<S96>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_f != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_e = rtb_Square_d;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_b != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_e = rtb_Square_d;
    }

    /* Gain: '<S96>/Gain' incorporates:
     *  DiscreteIntegrator: '<S96>/Discrete-Time Integrator1'
     *  Sum: '<S96>/Sum5'
     */
    rtb_Gain_c4 = (rtb_Square_d - Controller_DW.DiscreteTimeIntegrator1_DSTAT_e)
      * 62.831852F;

    /* Switch: '<S78>/Switch1' incorporates:
     *  Constant: '<S84>/Constant'
     *  DiscreteIntegrator: '<S95>/ '
     *  Gain: '<S66>/Gain'
     *  Gain: '<S66>/balabnce_ratio2'
     *  Gain: '<S66>/balance_ratio'
     *  Gain: '<S66>/pitch_ff'
     *  Gain: '<S86>/P_control'
     *  RelationalOperator: '<S84>/Compare'
     *  Sum: '<S66>/Add3'
     *  Sum: '<S66>/Minus'
     *  Sum: '<S66>/Sum'
     *  Sum: '<S86>/Add'
     *  Switch: '<S96>/Switch'
     */
    if (rtb_BitwiseAND_n == 3) {
      rtb_Cos_j = Controller_U.FMS_Out.theta_cmd;
    } else {
      if (Controller_U.FMS_Out.reset > 0) {
        /* Switch: '<S96>/Switch' incorporates:
         *  Gain: '<S96>/Gain1'
         */
        rtb_Saturation_j_idx_1 = 0.0F;
      } else {
        /* Switch: '<S96>/Switch' */
        rtb_Saturation_j_idx_1 = rtb_Gain_c4;
      }

      /* Gain: '<S94>/Gain' */
      rtb_TmpSignalConversionAtMult_0 = CONTROL_PARAM.FW_TECS_PITCH_D *
        rtb_Saturation_j_idx_1;

      /* Saturate: '<S86>/Saturation1' */
      if (rtb_TmpSignalConversionAtMult_0 > 0.3F) {
        rtb_TmpSignalConversionAtMult_0 = 0.3F;
      } else {
        if (rtb_TmpSignalConversionAtMult_0 < -0.3F) {
          rtb_TmpSignalConversionAtMult_0 = -0.3F;
        }
      }

      /* End of Saturate: '<S86>/Saturation1' */
      rtb_Cos_j = (((2.0F - CONTROL_PARAM.FW_TECS_RATIO) *
                    rtb_DiscreteTimeIntegrator5_h5 - CONTROL_PARAM.FW_TECS_RATIO
                    * rtb_VdotPg) * CONTROL_PARAM.FW_TECS_PITCH_F +
                   ((CONTROL_PARAM.FW_TECS_PITCH_P * rtb_Square_d +
                     Controller_DW._DSTATE) + rtb_TmpSignalConversionAtMult_0))
        + CONTROL_PARAM.FW_TECS_R2P * rtb_Abs;
    }

    /* End of Switch: '<S78>/Switch1' */

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
     *  Trigonometry: '<S70>/Sin'
     */
    rtb_aux_att_error_B_rad_idx_1 = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S29>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S70>/Cos1'
     */
    rtb_DiscreteTimeIntegrator1_a_t = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Trigonometry: '<S29>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S70>/Cos'
     */
    rtb_Integrator1_o_tmp = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S29>/Sin1' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S70>/Sin1'
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
      125.663704F;
    rtb_Multiply_ni[1] = (Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1] -
                          Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[1]) *
      125.663704F;
    rtb_Multiply_ni[2] = (Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2] -
                          Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[2]) *
      125.663704F;

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

    /* Sum: '<S66>/Add' incorporates:
     *  Gain: '<S66>/ucmd2thor'
     *  Gain: '<S66>/wcmd2thor'
     */
    rtb_Divide_m_idx_3 = CONTROL_PARAM.FW_TECS_W2T * rtb_Sum_l +
      CONTROL_PARAM.FW_TECS_U2T * rtb_Multiply1_e;

    /* DiscreteIntegrator: '<S98>/ ' */
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

    /* DiscreteIntegrator: '<S99>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_L_h0 != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm = rtb_Divide_m_idx_3;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_d != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm = rtb_Divide_m_idx_3;
    }

    /* Gain: '<S99>/Gain' incorporates:
     *  DiscreteIntegrator: '<S99>/Discrete-Time Integrator1'
     *  Sum: '<S99>/Sum5'
     */
    rtb_aux_att_error_B_rad_idx_0 = (rtb_Divide_m_idx_3 -
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm) * 188.49556F;

    /* Switch: '<S12>/Switch' incorporates:
     *  Constant: '<S101>/Constant'
     *  Constant: '<S103>/Constant2'
     *  Constant: '<S67>/Constant'
     *  RelationalOperator: '<S101>/Compare'
     *  Saturate: '<S67>/Saturation2'
     *  Switch: '<S67>/Switch'
     *  Switch: '<S99>/Switch'
     */
    if (rtb_Compare_nq) {
      Controller_B.fw_force_cmd[0] = Controller_U.FMS_Out.u_cmd;
      Controller_B.fw_force_cmd[1] = 0.0F;
      Controller_B.fw_force_cmd[2] = 0.0F;
    } else {
      if (rtb_BitwiseAND_n <= 3) {
        /* Switch: '<S67>/Switch' incorporates:
         *  Bias: '<S67>/Bias'
         *  Gain: '<S67>/Gain'
         */
        rtb_Add3_fc = 0.000999987125F * (real32_T)
          Controller_U.FMS_Out.throttle_cmd + -1.0F;
      } else {
        if (Controller_U.FMS_Out.reset > 0) {
          /* Switch: '<S99>/Switch' incorporates:
           *  Gain: '<S99>/Gain1'
           *  Switch: '<S67>/Switch'
           */
          rtb_Saturation_j_idx_1 = 0.0F;
        } else {
          /* Switch: '<S99>/Switch' incorporates:
           *  Switch: '<S67>/Switch'
           */
          rtb_Saturation_j_idx_1 = rtb_aux_att_error_B_rad_idx_0;
        }

        /* Gain: '<S97>/Gain' incorporates:
         *  Switch: '<S67>/Switch'
         */
        rtb_Add3_fc = CONTROL_PARAM.FW_TECS_THOR_D * rtb_Saturation_j_idx_1;

        /* Saturate: '<S87>/Saturation1' incorporates:
         *  Switch: '<S67>/Switch'
         */
        if (rtb_Add3_fc > 0.3F) {
          rtb_Add3_fc = 0.3F;
        } else {
          if (rtb_Add3_fc < -0.3F) {
            rtb_Add3_fc = -0.3F;
          }
        }

        /* End of Saturate: '<S87>/Saturation1' */

        /* Sum: '<S66>/Sum1' incorporates:
         *  DiscreteIntegrator: '<S98>/ '
         *  Gain: '<S66>/Gain1'
         *  Gain: '<S66>/thorttle_ff'
         *  Gain: '<S87>/P_control'
         *  Sum: '<S66>/Add1'
         *  Sum: '<S66>/Add2'
         *  Sum: '<S87>/Add4'
         *  Switch: '<S67>/Switch'
         */
        rtb_Add3_fc = (((CONTROL_PARAM.FW_TECS_THOR_P * rtb_Divide_m_idx_3 +
                         Controller_DW._DSTATE_d) + rtb_Add3_fc) +
                       (rtb_DiscreteTimeIntegrator5_h5 + rtb_VdotPg) *
                       CONTROL_PARAM.FW_TECS_THOR_FF) +
          CONTROL_PARAM.FW_TECS_R2T * rtb_Abs;

        /* Saturate: '<S67>/Saturation' incorporates:
         *  Switch: '<S67>/Switch'
         */
        if (rtb_Add3_fc > 1.0F) {
          rtb_Add3_fc = 1.0F;
        } else {
          if (rtb_Add3_fc < -1.0F) {
            rtb_Add3_fc = -1.0F;
          }
        }

        /* End of Saturate: '<S67>/Saturation' */
      }

      /* Saturate: '<S67>/Saturation2' incorporates:
       *  Switch: '<S67>/Switch'
       *  Switch: '<S99>/Switch'
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

    /* Bias: '<S79>/Pitch Offset' */
    rtb_Add3_fc = rtb_Cos_j + CONTROL_PARAM.FW_PITCH_OFFSET;

    /* Saturate: '<S79>/Saturation' */
    if (rtb_Add3_fc > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Add3_fc = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_Add3_fc < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_Add3_fc = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      }
    }

    /* Product: '<S80>/Multiply' incorporates:
     *  Constant: '<S80>/Constant2'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S79>/Sum'
     */
    rtb_Saturation_j_idx_0 = (rtb_Add3_fc - Controller_U.INS_Out.theta) *
      CONTROL_PARAM.FW_PITCH_P;

    /* Product: '<S82>/Divide' incorporates:
     *  Constant: '<S82>/Constant'
     *  DiscreteIntegrator: '<S56>/Discrete-Time Integrator5'
     */
    rtb_Add3_fc = 9.81F / Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;

    /* Saturate: '<S82>/Saturation' */
    if (rtb_Add3_fc > 1.0F) {
      rtb_Add3_fc = 1.0F;
    } else {
      if (rtb_Add3_fc < 0.2F) {
        rtb_Add3_fc = 0.2F;
      }
    }

    /* End of Saturate: '<S82>/Saturation' */

    /* Sum: '<S77>/Sum' incorporates:
     *  Product: '<S82>/Multiply'
     *  Product: '<S82>/Multiply1'
     *  Trigonometry: '<S82>/Cos'
     *  Trigonometry: '<S82>/Tan'
     */
    rtb_Add3_fc = tanf(rtb_phi_cmd) * arm_cos_f32(rtb_Cos_j) * rtb_Add3_fc +
      Controller_U.FMS_Out.psi_rate_cmd;

    /* Saturate: '<S77>/Saturation' */
    if (rtb_Add3_fc > CONTROL_PARAM.FW_YAW_RATE_LIM) {
      rtb_Add3_fc = CONTROL_PARAM.FW_YAW_RATE_LIM;
    } else {
      if (rtb_Add3_fc < -CONTROL_PARAM.FW_YAW_RATE_LIM) {
        rtb_Add3_fc = -CONTROL_PARAM.FW_YAW_RATE_LIM;
      }
    }

    /* End of Saturate: '<S77>/Saturation' */

    /* Saturate: '<S79>/Saturation' */
    if (rtb_phi_cmd > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_phi_cmd = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_phi_cmd < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_phi_cmd = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      }
    }

    /* Sum: '<S70>/Add' incorporates:
     *  Constant: '<S80>/Constant1'
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S70>/Multiply'
     *  Product: '<S80>/Multiply'
     *  Sum: '<S79>/Sum'
     */
    rtb_Cos_j = (rtb_phi_cmd - Controller_U.INS_Out.phi) *
      CONTROL_PARAM.FW_ROLL_P - rtb_TmpSignalConversionAtMult_3 * rtb_Add3_fc;

    /* Sum: '<S70>/Add1' incorporates:
     *  Product: '<S70>/Multiply1'
     *  Product: '<S70>/Multiply3'
     */
    rtb_phi_cmd = rtb_aux_att_error_B_rad_idx_1 *
      rtb_DiscreteTimeIntegrator1_a_t * rtb_Add3_fc + rtb_Integrator1_o_tmp *
      rtb_Saturation_j_idx_0;

    /* Sum: '<S70>/Add2' incorporates:
     *  Product: '<S70>/Multiply4'
     *  Product: '<S70>/Multiply5'
     */
    rtb_aux_att_error_B_rad_idx_1 = rtb_Integrator1_o_tmp *
      rtb_DiscreteTimeIntegrator1_a_t * rtb_Add3_fc -
      rtb_aux_att_error_B_rad_idx_1 * rtb_Saturation_j_idx_0;

    /* Sum: '<S68>/Minus2' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Saturation_j_idx_0 = rtb_Cos_j - Controller_U.INS_Out.p;
    rtb_Saturation_j_idx_1 = rtb_phi_cmd - Controller_U.INS_Out.q;
    rtb_Saturation_j_idx_2 = rtb_aux_att_error_B_rad_idx_1 -
      Controller_U.INS_Out.r;

    /* DiscreteIntegrator: '<S74>/Discrete-Time Integrator' */
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
      /* Product: '<S72>/Divide' incorporates:
       *  Constant: '<S72>/trim_speed'
       *  Math: '<S72>/Square'
       */
      rtb_Saturation_g = CONTROL_PARAM.FW_AIRSPEED_TRIM *
        CONTROL_PARAM.FW_AIRSPEED_TRIM / rtb_Saturation_g;

      /* Saturate: '<S72>/Saturation' */
      if (rtb_Saturation_g > 1.0F) {
        rtb_Saturation_g = 1.0F;
      } else {
        if (rtb_Saturation_g < 0.0F) {
          rtb_Saturation_g = 0.0F;
        }
      }

      /* End of Saturate: '<S72>/Saturation' */

      /* Product: '<S68>/Multiply' incorporates:
       *  Constant: '<S75>/gain1'
       *  Constant: '<S75>/gain2'
       *  Constant: '<S75>/gain3'
       *  DiscreteIntegrator: '<S74>/Discrete-Time Integrator'
       *  Product: '<S75>/Multiply'
       *  Sum: '<S71>/Add1'
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

      /* Product: '<S73>/Divide' incorporates:
       *  Constant: '<S73>/trim_speed'
       *  DiscreteIntegrator: '<S56>/Discrete-Time Integrator5'
       */
      rtb_Saturation_g = CONTROL_PARAM.FW_AIRSPEED_TRIM /
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;

      /* Saturate: '<S73>/Saturation' */
      if (rtb_Saturation_g > 1.0F) {
        rtb_Saturation_g = 1.0F;
      } else {
        if (rtb_Saturation_g < 0.0F) {
          rtb_Saturation_g = 0.0F;
        }
      }

      /* End of Saturate: '<S73>/Saturation' */

      /* Product: '<S68>/Multiply1' incorporates:
       *  Gain: '<S68>/FF'
       */
      rtb_Cos_j = CONTROL_PARAM.FW_FF * rtb_Cos_j * rtb_Saturation_g;

      /* Saturate: '<S68>/FF_limit' */
      if (rtb_Cos_j > CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_Cos_j = CONTROL_PARAM.FW_FF_LIMIT;
      } else {
        if (rtb_Cos_j < -CONTROL_PARAM.FW_FF_LIMIT) {
          rtb_Cos_j = -CONTROL_PARAM.FW_FF_LIMIT;
        }
      }

      /* Saturate: '<S68>/PI_limit' */
      if (rtb_Add3_fc > CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_Add3_fc = CONTROL_PARAM.FW_PI_LIMIT;
      } else {
        if (rtb_Add3_fc < -CONTROL_PARAM.FW_PI_LIMIT) {
          rtb_Add3_fc = -CONTROL_PARAM.FW_PI_LIMIT;
        }
      }

      /* Product: '<S11>/Multiply' incorporates:
       *  DiscreteIntegrator: '<S51>/Discrete-Time Integrator5'
       *  Sum: '<S68>/Add'
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

      /* Product: '<S68>/Multiply1' incorporates:
       *  Gain: '<S68>/FF'
       */
      rtb_Add3_fc = CONTROL_PARAM.FW_FF * rtb_phi_cmd * rtb_Saturation_g;

      /* Saturate: '<S68>/FF_limit' */
      if (rtb_Add3_fc > CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_Add3_fc = CONTROL_PARAM.FW_FF_LIMIT;
      } else {
        if (rtb_Add3_fc < -CONTROL_PARAM.FW_FF_LIMIT) {
          rtb_Add3_fc = -CONTROL_PARAM.FW_FF_LIMIT;
        }
      }

      /* Saturate: '<S68>/PI_limit' */
      if (rtb_DiscreteTimeIntegrator1_a_t > CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_DiscreteTimeIntegrator1_a_t = CONTROL_PARAM.FW_PI_LIMIT;
      } else {
        if (rtb_DiscreteTimeIntegrator1_a_t < -CONTROL_PARAM.FW_PI_LIMIT) {
          rtb_DiscreteTimeIntegrator1_a_t = -CONTROL_PARAM.FW_PI_LIMIT;
        }
      }

      /* Product: '<S11>/Multiply' incorporates:
       *  DiscreteIntegrator: '<S51>/Discrete-Time Integrator5'
       *  Sum: '<S68>/Add'
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

      /* Product: '<S68>/Multiply1' incorporates:
       *  Gain: '<S68>/FF'
       */
      rtb_Add3_fc = CONTROL_PARAM.FW_FF * rtb_aux_att_error_B_rad_idx_1 *
        rtb_Saturation_g;

      /* Saturate: '<S68>/FF_limit' */
      if (rtb_Add3_fc > CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_Add3_fc = CONTROL_PARAM.FW_FF_LIMIT;
      } else {
        if (rtb_Add3_fc < -CONTROL_PARAM.FW_FF_LIMIT) {
          rtb_Add3_fc = -CONTROL_PARAM.FW_FF_LIMIT;
        }
      }

      /* Saturate: '<S68>/PI_limit' */
      if (rtb_Integrator1_o_tmp > CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_Integrator1_o_tmp = CONTROL_PARAM.FW_PI_LIMIT;
      } else {
        if (rtb_Integrator1_o_tmp < -CONTROL_PARAM.FW_PI_LIMIT) {
          rtb_Integrator1_o_tmp = -CONTROL_PARAM.FW_PI_LIMIT;
        }
      }

      /* Product: '<S11>/Multiply' incorporates:
       *  DiscreteIntegrator: '<S51>/Discrete-Time Integrator5'
       *  Sum: '<S68>/Add'
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

    /* Update for DiscreteIntegrator: '<S56>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S56>/Gain'
     *  Sum: '<S56>/Sum5'
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

    /* Update for DiscreteIntegrator: '<S100>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S100>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S100>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_n = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_f += (Controller_U.INS_Out.ax -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_f) * 31.415926F * 0.002F;

    /* Update for DiscreteIntegrator: '<S95>/ ' incorporates:
     *  Gain: '<S95>/Gain3'
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

    /* End of Update for DiscreteIntegrator: '<S95>/ ' */

    /* Update for DiscreteIntegrator: '<S96>/Discrete-Time Integrator1' */
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

    /* Update for DiscreteIntegrator: '<S98>/ ' incorporates:
     *  Gain: '<S98>/Gain'
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

    /* End of Update for DiscreteIntegrator: '<S98>/ ' */

    /* Update for DiscreteIntegrator: '<S99>/Discrete-Time Integrator1' */
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

    /* Update for DiscreteIntegrator: '<S74>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S74>/gain1'
     *  Constant: '<S74>/gain2'
     *  Constant: '<S74>/gain3'
     *  Product: '<S74>/Multiply'
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

    /* End of Update for DiscreteIntegrator: '<S74>/Discrete-Time Integrator' */

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
       *  DiscreteIntegrator: '<S116>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S118>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S120>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S140>/Integrator'
       *  DiscreteIntegrator: '<S140>/Integrator1'
       *  DiscreteIntegrator: '<S145>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S147>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S158>/Integrator'
       *  DiscreteIntegrator: '<S158>/Integrator1'
       *  DiscreteIntegrator: '<S161>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S163>/Discrete-Time Integrator1'
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

    /* DiscreteIntegrator: '<S118>/Discrete-Time Integrator' */
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

    /* Trigonometry: '<S142>/Trigonometric Function1' incorporates:
     *  Gain: '<S141>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1[0] = arm_cos_f32(-Controller_U.INS_Out.psi);

    /* Trigonometry: '<S142>/Trigonometric Function' incorporates:
     *  Gain: '<S141>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1[1] = arm_sin_f32(-Controller_U.INS_Out.psi);

    /* SignalConversion: '<S142>/ConcatBufferAtVector Concatenate1In3' incorporates:
     *  Constant: '<S142>/Constant3'
     */
    rtb_MatrixConcatenate1[2] = 0.0F;

    /* Gain: '<S142>/Gain' incorporates:
     *  Gain: '<S141>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S142>/Trigonometric Function2'
     */
    rtb_MatrixConcatenate1[3] = -arm_sin_f32(-Controller_U.INS_Out.psi);

    /* Trigonometry: '<S142>/Trigonometric Function3' incorporates:
     *  Gain: '<S141>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1[4] = arm_cos_f32(-Controller_U.INS_Out.psi);

    /* SignalConversion: '<S142>/ConcatBufferAtVector Concatenate2In3' incorporates:
     *  Constant: '<S142>/Constant4'
     */
    rtb_MatrixConcatenate1[5] = 0.0F;

    /* SignalConversion: '<S142>/ConcatBufferAtVector ConcatenateIn3' */
    rtb_MatrixConcatenate1[6] = Controller_ConstB.VectorConcatenate3[0];
    rtb_MatrixConcatenate1[7] = Controller_ConstB.VectorConcatenate3[1];
    rtb_MatrixConcatenate1[8] = Controller_ConstB.VectorConcatenate3[2];

    /* Product: '<S139>/Multiply' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  SignalConversion: '<S139>/TmpSignal ConversionAtMultiplyInport2'
     */
    for (i = 0; i < 3; i++) {
      rtb_MatrixConcatenate1_0[i] = rtb_MatrixConcatenate1[i + 3] *
        Controller_U.INS_Out.ve + rtb_MatrixConcatenate1[i] *
        Controller_U.INS_Out.vn;
    }

    /* End of Product: '<S139>/Multiply' */

    /* Sum: '<S136>/Sum' incorporates:
     *  DiscreteIntegrator: '<S140>/Integrator1'
     */
    rtb_aux_att_error_B_rad_idx_0 = Controller_DW.Integrator1_DSTATE[0] -
      rtb_MatrixConcatenate1_0[0];
    rtb_aux_att_error_B_rad_idx_1 = Controller_DW.Integrator1_DSTATE[1] -
      rtb_MatrixConcatenate1_0[1];

    /* DiscreteIntegrator: '<S145>/Discrete-Time Integrator' */
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

    /* DiscreteIntegrator: '<S147>/Discrete-Time Integrator1' */
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

    /* Gain: '<S147>/Gain' incorporates:
     *  DiscreteIntegrator: '<S147>/Discrete-Time Integrator1'
     *  Sum: '<S147>/Sum5'
     */
    rtb_Divide_m_idx_3 = (rtb_aux_att_error_B_rad_idx_0 -
                          Controller_DW.DiscreteTimeIntegrator1_DSTATE[0]) *
      62.831852F;
    rtb_Divide_m_idx_0 = (rtb_aux_att_error_B_rad_idx_1 -
                          Controller_DW.DiscreteTimeIntegrator1_DSTATE[1]) *
      62.831852F;

    /* Switch: '<S147>/Switch' incorporates:
     *  Gain: '<S147>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_Divide_m_idx_1 = 0.0F;
      rtb_Divide_m_idx_2 = 0.0F;
    } else {
      rtb_Divide_m_idx_1 = rtb_Divide_m_idx_3;
      rtb_Divide_m_idx_2 = rtb_Divide_m_idx_0;
    }

    /* End of Switch: '<S147>/Switch' */

    /* Product: '<S144>/Multiply' incorporates:
     *  Constant: '<S144>/kd'
     */
    rtb_Square_d = CONTROL_PARAM.MC_VEL_XY_D * rtb_Divide_m_idx_1;

    /* Saturate: '<S144>/Saturation' */
    if (rtb_Square_d > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
      rtb_Square_d = CONTROL_PARAM.MC_VEL_XY_D_MAX;
    } else {
      if (rtb_Square_d < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
        rtb_Square_d = CONTROL_PARAM.MC_VEL_XY_D_MIN;
      }
    }

    rtb_Divide_m_idx_1 = rtb_Square_d;

    /* Product: '<S144>/Multiply' incorporates:
     *  Constant: '<S144>/kd'
     */
    rtb_Square_d = CONTROL_PARAM.MC_VEL_XY_D * rtb_Divide_m_idx_2;

    /* Saturate: '<S144>/Saturation' */
    if (rtb_Square_d > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
      rtb_Square_d = CONTROL_PARAM.MC_VEL_XY_D_MAX;
    } else {
      if (rtb_Square_d < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
        rtb_Square_d = CONTROL_PARAM.MC_VEL_XY_D_MIN;
      }
    }

    /* Switch: '<S138>/Switch' incorporates:
     *  Constant: '<S146>/kp'
     *  Constant: '<S148>/Constant'
     *  Constant: '<S150>/Constant'
     *  Constant: '<S151>/Constant'
     *  DiscreteIntegrator: '<S145>/Discrete-Time Integrator'
     *  Product: '<S146>/Multiply'
     *  Product: '<S149>/Multiply2'
     *  Product: '<S149>/Multiply3'
     *  RelationalOperator: '<S148>/Compare'
     *  RelationalOperator: '<S150>/Compare'
     *  RelationalOperator: '<S151>/Compare'
     *  S-Function (sfix_bitop): '<S149>/cmd_ax valid'
     *  S-Function (sfix_bitop): '<S149>/cmd_ay valid'
     *  S-Function (sfix_bitop): '<S149>/cmd_u valid'
     *  S-Function (sfix_bitop): '<S149>/cmd_v valid'
     *  Sum: '<S137>/Add'
     *  Sum: '<S149>/Sum1'
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

    /* End of Switch: '<S138>/Switch' */

    /* Trigonometry: '<S135>/Atan' incorporates:
     *  Constant: '<S135>/g'
     *  Gain: '<S135>/Gain1'
     *  Gain: '<S135>/gain'
     *  Product: '<S135>/Divide'
     */
    rtb_Add3_fc = atanf(1.1F * rtb_Divide_m_idx_2 / 9.8055F);
    rtb_Divide_m_idx_2 = atanf(1.1F * -rtb_Divide_m_idx_1 / 9.8055F);

    /* Switch: '<S126>/Switch' incorporates:
     *  Constant: '<S133>/Constant'
     *  Logic: '<S126>/Logical Operator'
     *  RelationalOperator: '<S132>/Compare'
     *  RelationalOperator: '<S133>/Compare'
     *  Saturate: '<S135>/Saturation'
     *  Switch: '<S126>/Switch1'
     */
    if ((rtb_BitwiseAND_n == 3) || (rtb_BitwiseAND_n == 4)) {
      rtb_Divide_m_idx_1 = Controller_U.FMS_Out.phi_cmd;
      rtb_Divide_m_idx_2 = Controller_U.FMS_Out.theta_cmd;
    } else if (rtb_BitwiseAND_n == 6) {
      /* Switch: '<S134>/Switch' incorporates:
       *  S-Function (sfix_bitop): '<S134>/cmd_phi valid'
       *  S-Function (sfix_bitop): '<S134>/cmd_theta valid'
       *  Saturate: '<S135>/Saturation'
       *  Switch: '<S126>/Switch1'
       */
      if ((Controller_U.FMS_Out.cmd_mask & 8) > 0) {
        rtb_Divide_m_idx_1 = Controller_U.FMS_Out.phi_cmd;
      } else if (rtb_Add3_fc > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S135>/Saturation' */
        rtb_Divide_m_idx_1 = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else if (rtb_Add3_fc < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S135>/Saturation' */
        rtb_Divide_m_idx_1 = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        rtb_Divide_m_idx_1 = rtb_Add3_fc;
      }

      if ((Controller_U.FMS_Out.cmd_mask & 16) > 0) {
        rtb_Divide_m_idx_2 = Controller_U.FMS_Out.theta_cmd;
      } else if (rtb_Divide_m_idx_2 > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S135>/Saturation' */
        rtb_Divide_m_idx_2 = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_Divide_m_idx_2 < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Saturate: '<S135>/Saturation' */
          rtb_Divide_m_idx_2 = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        }
      }

      /* End of Switch: '<S134>/Switch' */
    } else {
      if (rtb_Add3_fc > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S135>/Saturation' incorporates:
         *  Switch: '<S126>/Switch1'
         */
        rtb_Divide_m_idx_1 = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else if (rtb_Add3_fc < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S135>/Saturation' incorporates:
         *  Switch: '<S126>/Switch1'
         */
        rtb_Divide_m_idx_1 = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        /* Switch: '<S126>/Switch1' incorporates:
         *  Saturate: '<S135>/Saturation'
         */
        rtb_Divide_m_idx_1 = rtb_Add3_fc;
      }

      /* Saturate: '<S135>/Saturation' */
      if (rtb_Divide_m_idx_2 > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Switch: '<S126>/Switch1' */
        rtb_Divide_m_idx_2 = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_Divide_m_idx_2 < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Switch: '<S126>/Switch1' */
          rtb_Divide_m_idx_2 = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        }
      }
    }

    /* End of Switch: '<S126>/Switch' */

    /* Sum: '<S127>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Square_d = rtb_Divide_m_idx_1 - Controller_U.INS_Out.phi;

    /* Product: '<S130>/Divide1' incorporates:
     *  Abs: '<S130>/Abs'
     *  Constant: '<S130>/const2'
     */
    rtb_Saturation_j_idx_0 = fabsf(rtb_Square_d) / 0.002F;

    /* Product: '<S130>/Divide' incorporates:
     *  Constant: '<S128>/Constant1'
     *  Constant: '<S130>/const1'
     *  Math: '<S130>/Square'
     *  SignalConversion: '<S130>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_TmpSignalConversionAtMult_1 = 9.5993F / (CONTROL_PARAM.MC_ROLL_P *
      CONTROL_PARAM.MC_ROLL_P);

    /* Signum: '<S130>/Sign' */
    if (rtb_Square_d < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else if (rtb_Square_d > 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_0 = rtb_Square_d;
    }

    /* Switch: '<S130>/Switch' incorporates:
     *  Constant: '<S128>/Constant1'
     *  Gain: '<S130>/Gain1'
     *  Gain: '<S130>/Gain2'
     *  Logic: '<S130>/Logical Operator'
     *  Product: '<S130>/Divide'
     *  Product: '<S130>/Multiply'
     *  Product: '<S130>/Multiply1'
     *  Product: '<S130>/Multiply2'
     *  Product: '<S130>/Multiply3'
     *  RelationalOperator: '<S130>/Relational Operator'
     *  RelationalOperator: '<S130>/Relational Operator2'
     *  SignalConversion: '<S130>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S130>/Sqrt'
     *  Sum: '<S130>/Subtract'
     */
    if ((rtb_Square_d <= rtb_TmpSignalConversionAtMult_1) && (rtb_Square_d >=
         -rtb_TmpSignalConversionAtMult_1)) {
      rtb_TmpSignalConversionAtMult_0 = rtb_Square_d * CONTROL_PARAM.MC_ROLL_P;
    } else {
      rtb_TmpSignalConversionAtMult_0 *= sqrtf((rtb_TmpSignalConversionAtMult_0 *
        rtb_Square_d - 0.5F * rtb_TmpSignalConversionAtMult_1) *
        Controller_ConstB.Gain);
    }

    /* Gain: '<S130>/Gain3' */
    rtb_TmpSignalConversionAtMult_1 = -rtb_Saturation_j_idx_0;

    /* Switch: '<S131>/Switch' incorporates:
     *  Gain: '<S130>/Gain3'
     *  RelationalOperator: '<S131>/UpperRelop'
     */
    if (rtb_TmpSignalConversionAtMult_0 >= -rtb_Saturation_j_idx_0) {
      rtb_TmpSignalConversionAtMult_1 = rtb_TmpSignalConversionAtMult_0;
    }

    /* Switch: '<S131>/Switch2' incorporates:
     *  RelationalOperator: '<S131>/LowerRelop1'
     */
    if (rtb_TmpSignalConversionAtMult_0 <= rtb_Saturation_j_idx_0) {
      rtb_Saturation_j_idx_0 = rtb_TmpSignalConversionAtMult_1;
    }

    /* Saturate: '<S111>/Saturation1' */
    if (rtb_Saturation_j_idx_0 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_Saturation_j_idx_0 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_Saturation_j_idx_0 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_Saturation_j_idx_0 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    rtb_Divide_m_idx_1 = rtb_Saturation_j_idx_0;

    /* Sum: '<S127>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S130>/Divide1'
     */
    rtb_Square_d = rtb_Divide_m_idx_2 - Controller_U.INS_Out.theta;

    /* Product: '<S130>/Divide1' incorporates:
     *  Abs: '<S130>/Abs'
     *  Constant: '<S130>/const2'
     */
    rtb_Saturation_j_idx_0 = fabsf(rtb_Square_d) / 0.002F;

    /* Product: '<S130>/Divide' incorporates:
     *  Constant: '<S128>/Constant2'
     *  Constant: '<S130>/const1'
     *  Math: '<S130>/Square'
     *  SignalConversion: '<S130>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_TmpSignalConversionAtMult_1 = 9.5993F / (CONTROL_PARAM.MC_PITCH_P *
      CONTROL_PARAM.MC_PITCH_P);

    /* Signum: '<S130>/Sign' */
    if (rtb_Square_d < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else if (rtb_Square_d > 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_0 = rtb_Square_d;
    }

    /* Switch: '<S130>/Switch' incorporates:
     *  Constant: '<S128>/Constant2'
     *  Gain: '<S130>/Gain1'
     *  Gain: '<S130>/Gain2'
     *  Logic: '<S130>/Logical Operator'
     *  Product: '<S130>/Divide'
     *  Product: '<S130>/Multiply'
     *  Product: '<S130>/Multiply1'
     *  Product: '<S130>/Multiply2'
     *  Product: '<S130>/Multiply3'
     *  RelationalOperator: '<S130>/Relational Operator'
     *  RelationalOperator: '<S130>/Relational Operator2'
     *  SignalConversion: '<S130>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S130>/Sqrt'
     *  Sum: '<S130>/Subtract'
     */
    if ((rtb_Square_d <= rtb_TmpSignalConversionAtMult_1) && (rtb_Square_d >=
         -rtb_TmpSignalConversionAtMult_1)) {
      rtb_TmpSignalConversionAtMult_0 = rtb_Square_d * CONTROL_PARAM.MC_PITCH_P;
    } else {
      rtb_TmpSignalConversionAtMult_0 *= sqrtf((rtb_TmpSignalConversionAtMult_0 *
        rtb_Square_d - 0.5F * rtb_TmpSignalConversionAtMult_1) *
        Controller_ConstB.Gain);
    }

    /* Gain: '<S130>/Gain3' */
    rtb_TmpSignalConversionAtMult_1 = -rtb_Saturation_j_idx_0;

    /* Switch: '<S131>/Switch' incorporates:
     *  Gain: '<S130>/Gain3'
     *  RelationalOperator: '<S131>/UpperRelop'
     */
    if (rtb_TmpSignalConversionAtMult_0 >= -rtb_Saturation_j_idx_0) {
      rtb_TmpSignalConversionAtMult_1 = rtb_TmpSignalConversionAtMult_0;
    }

    /* Switch: '<S131>/Switch2' incorporates:
     *  RelationalOperator: '<S131>/LowerRelop1'
     */
    if (rtb_TmpSignalConversionAtMult_0 <= rtb_Saturation_j_idx_0) {
      rtb_Saturation_j_idx_0 = rtb_TmpSignalConversionAtMult_1;
    }

    /* Saturate: '<S111>/Saturation1' */
    if (rtb_Saturation_j_idx_0 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_Saturation_j_idx_0 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_Saturation_j_idx_0 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_Saturation_j_idx_0 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    /* Saturate: '<S111>/Saturation' */
    if (Controller_U.FMS_Out.psi_rate_cmd > CONTROL_PARAM.MC_R_CMD_LIM) {
      rtb_Add3_fc = CONTROL_PARAM.MC_R_CMD_LIM;
    } else if (Controller_U.FMS_Out.psi_rate_cmd < -CONTROL_PARAM.MC_R_CMD_LIM)
    {
      rtb_Add3_fc = -CONTROL_PARAM.MC_R_CMD_LIM;
    } else {
      rtb_Add3_fc = Controller_U.FMS_Out.psi_rate_cmd;
    }

    /* End of Saturate: '<S111>/Saturation' */

    /* Trigonometry: '<S121>/Sin' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_m_idx_2 = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S121>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Saturation_g = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Product: '<S121>/Multiply3' incorporates:
     *  Trigonometry: '<S121>/Cos1'
     *  Trigonometry: '<S121>/Sin'
     */
    rtb_TmpSignalConversionAtMult_0 = rtb_Divide_m_idx_2 * rtb_Saturation_g *
      rtb_Add3_fc;

    /* Trigonometry: '<S121>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_TmpSignalConversionAtMult_1 = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Product: '<S121>/Multiply1' incorporates:
     *  Trigonometry: '<S121>/Cos'
     */
    rtb_TmpSignalConversionAtMult_2 = rtb_TmpSignalConversionAtMult_1 *
      rtb_Saturation_j_idx_0;

    /* Product: '<S121>/Multiply4' incorporates:
     *  Trigonometry: '<S121>/Sin'
     */
    rtb_Divide_m_idx_2 *= rtb_Saturation_j_idx_0;

    /* Switch: '<S112>/Switch' incorporates:
     *  Constant: '<S122>/Constant'
     *  Constant: '<S123>/Constant'
     *  RelationalOperator: '<S122>/Compare'
     *  RelationalOperator: '<S123>/Compare'
     *  Switch: '<S112>/Switch1'
     */
    if (rtb_BitwiseAND_n == 2) {
      rtb_Multiply_ni[0] = Controller_U.FMS_Out.p_cmd;
      rtb_Multiply_ni[1] = Controller_U.FMS_Out.q_cmd;
      rtb_Multiply_ni[2] = Controller_U.FMS_Out.r_cmd;
    } else if (rtb_BitwiseAND_n == 6) {
      /* Switch: '<S124>/Switch' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Product: '<S121>/Multiply'
       *  Product: '<S121>/Multiply1'
       *  Product: '<S121>/Multiply5'
       *  S-Function (sfix_bitop): '<S124>/cmd_p valid'
       *  S-Function (sfix_bitop): '<S124>/cmd_q valid'
       *  S-Function (sfix_bitop): '<S124>/cmd_r valid'
       *  Sum: '<S121>/Add'
       *  Sum: '<S121>/Add1'
       *  Sum: '<S121>/Add2'
       *  Switch: '<S112>/Switch1'
       *  Trigonometry: '<S121>/Cos'
       *  Trigonometry: '<S121>/Cos1'
       *  Trigonometry: '<S121>/Sin1'
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
          rtb_Add3_fc - rtb_Divide_m_idx_2;
      }

      /* End of Switch: '<S124>/Switch' */
    } else {
      /* Switch: '<S112>/Switch1' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Product: '<S121>/Multiply'
       *  Product: '<S121>/Multiply3'
       *  Product: '<S121>/Multiply5'
       *  Sum: '<S121>/Add'
       *  Sum: '<S121>/Add1'
       *  Sum: '<S121>/Add2'
       *  Trigonometry: '<S121>/Cos'
       *  Trigonometry: '<S121>/Cos1'
       *  Trigonometry: '<S121>/Sin1'
       */
      rtb_Multiply_ni[0] = rtb_Divide_m_idx_1 - arm_sin_f32
        (Controller_U.INS_Out.theta) * rtb_Add3_fc;
      rtb_Multiply_ni[1] = rtb_TmpSignalConversionAtMult_2 +
        rtb_TmpSignalConversionAtMult_0;
      rtb_Multiply_ni[2] = rtb_TmpSignalConversionAtMult_1 * rtb_Saturation_g *
        rtb_Add3_fc - rtb_Divide_m_idx_2;
    }

    /* End of Switch: '<S112>/Switch' */

    /* Sum: '<S113>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_TmpSignalConversionAtMult_0 = rtb_Multiply_ni[0] -
      Controller_U.INS_Out.p;
    rtb_TmpSignalConversionAtMult_1 = rtb_Multiply_ni[1] -
      Controller_U.INS_Out.q;
    rtb_TmpSignalConversionAtMult_2 = rtb_Multiply_ni[2] -
      Controller_U.INS_Out.r;

    /* DiscreteIntegrator: '<S116>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] =
        rtb_TmpSignalConversionAtMult_0;
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] =
        rtb_TmpSignalConversionAtMult_1;
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] =
        rtb_TmpSignalConversionAtMult_2;
    }

    /* DiscreteIntegrator: '<S120>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S116>/Discrete-Time Integrator5'
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

    /* Gain: '<S120>/Gain' incorporates:
     *  DiscreteIntegrator: '<S116>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S120>/Discrete-Time Integrator1'
     *  Sum: '<S120>/Sum5'
     */
    rtb_Multiply_ni[0] = (Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] -
                          Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[0]) *
      125.663704F;
    rtb_Multiply_ni[1] = (Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] -
                          Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[1]) *
      125.663704F;
    rtb_Multiply_ni[2] = (Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] -
                          Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[2]) *
      125.663704F;

    /* Switch: '<S120>/Switch' incorporates:
     *  Gain: '<S120>/Gain1'
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

    /* End of Switch: '<S120>/Switch' */

    /* Product: '<S117>/Multiply' incorporates:
     *  Constant: '<S117>/gain1'
     */
    rtb_Saturation_ni = CONTROL_PARAM.MC_ROLL_RATE_D * rtb_Saturation_j_idx_0;

    /* Saturate: '<S117>/Saturation' */
    if (rtb_Saturation_ni > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Saturation_ni = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Saturation_ni < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Saturation_ni = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    rtb_Saturation_j_idx_0 = rtb_Saturation_ni;

    /* Product: '<S117>/Multiply' incorporates:
     *  Constant: '<S117>/gain2'
     */
    rtb_Saturation_ni = CONTROL_PARAM.MC_PITCH_RATE_D * rtb_Saturation_j_idx_1;

    /* Saturate: '<S117>/Saturation' */
    if (rtb_Saturation_ni > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Saturation_ni = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Saturation_ni < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Saturation_ni = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    rtb_Saturation_j_idx_1 = rtb_Saturation_ni;

    /* Product: '<S117>/Multiply' incorporates:
     *  Constant: '<S117>/gain3'
     */
    rtb_Saturation_ni = CONTROL_PARAM.MC_YAW_RATE_D * rtb_Saturation_j_idx_2;

    /* Saturate: '<S117>/Saturation' */
    if (rtb_Saturation_ni > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Saturation_ni = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Saturation_ni < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Saturation_ni = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    /* SignalConversion: '<S5>/BusConversion_InsertedFor_VTOL_actuator_cmd_at_inport_0' incorporates:
     *  Constant: '<S119>/gain1'
     *  Constant: '<S119>/gain2'
     *  Constant: '<S119>/gain3'
     *  DiscreteIntegrator: '<S116>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S118>/Discrete-Time Integrator'
     *  Product: '<S119>/Multiply'
     *  Sum: '<S114>/Add'
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

    /* Product: '<S143>/Multiply1' incorporates:
     *  Constant: '<S143>/const1'
     *  DiscreteIntegrator: '<S140>/Integrator'
     */
    rtb_Saturation_g = Controller_DW.Integrator_DSTATE[0] * 0.1F;
    rtb_Gain_c4 = Controller_DW.Integrator_DSTATE[1] * 0.1F;

    /* Sum: '<S143>/Add' incorporates:
     *  DiscreteIntegrator: '<S140>/Integrator1'
     *  Sum: '<S140>/Subtract'
     */
    rtb_Divide_m_idx_1 = (Controller_DW.Integrator1_DSTATE[0] -
                          Controller_U.FMS_Out.u_cmd) + rtb_Saturation_g;
    rtb_Divide_m_idx_2 = (Controller_DW.Integrator1_DSTATE[1] -
                          Controller_U.FMS_Out.v_cmd) + rtb_Gain_c4;

    /* Signum: '<S143>/Sign' */
    if (rtb_Divide_m_idx_1 < 0.0F) {
      rtb_Square_d = -1.0F;
    } else if (rtb_Divide_m_idx_1 > 0.0F) {
      rtb_Square_d = 1.0F;
    } else {
      rtb_Square_d = rtb_Divide_m_idx_1;
    }

    /* Sum: '<S143>/Add2' incorporates:
     *  Abs: '<S143>/Abs'
     *  Gain: '<S143>/Gain'
     *  Gain: '<S143>/Gain1'
     *  Product: '<S143>/Multiply2'
     *  Product: '<S143>/Multiply3'
     *  Signum: '<S143>/Sign'
     *  Sqrt: '<S143>/Sqrt'
     *  Sum: '<S143>/Add1'
     *  Sum: '<S143>/Subtract'
     */
    rtb_Saturation_j_idx_0 = (sqrtf((8.0F * fabsf(rtb_Divide_m_idx_1) +
      Controller_ConstB.d) * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
      rtb_Square_d + rtb_Saturation_g;

    /* Sum: '<S143>/Add3' incorporates:
     *  Signum: '<S143>/Sign'
     */
    rtb_Add3_fc = rtb_Divide_m_idx_1 + Controller_ConstB.d;

    /* Sum: '<S143>/Subtract1' incorporates:
     *  Signum: '<S143>/Sign'
     */
    rtb_Square_d = rtb_Divide_m_idx_1 - Controller_ConstB.d;

    /* Signum: '<S143>/Sign1' */
    if (rtb_Add3_fc < 0.0F) {
      rtb_Add3_fc = -1.0F;
    } else {
      if (rtb_Add3_fc > 0.0F) {
        rtb_Add3_fc = 1.0F;
      }
    }

    /* Signum: '<S143>/Sign2' */
    if (rtb_Square_d < 0.0F) {
      rtb_Square_d = -1.0F;
    } else {
      if (rtb_Square_d > 0.0F) {
        rtb_Square_d = 1.0F;
      }
    }

    /* Sum: '<S143>/Add2' incorporates:
     *  Gain: '<S143>/Gain2'
     *  Product: '<S143>/Multiply4'
     *  Signum: '<S143>/Sign'
     *  Sum: '<S143>/Add4'
     *  Sum: '<S143>/Add5'
     *  Sum: '<S143>/Subtract2'
     */
    rtb_Divide_m_idx_1 = ((rtb_Divide_m_idx_1 - rtb_Saturation_j_idx_0) +
                          rtb_Saturation_g) * ((rtb_Add3_fc - rtb_Square_d) *
      0.5F) + rtb_Saturation_j_idx_0;

    /* Signum: '<S143>/Sign' */
    if (rtb_Divide_m_idx_2 < 0.0F) {
      rtb_Square_d = -1.0F;
    } else if (rtb_Divide_m_idx_2 > 0.0F) {
      rtb_Square_d = 1.0F;
    } else {
      rtb_Square_d = rtb_Divide_m_idx_2;
    }

    /* Sum: '<S143>/Add2' incorporates:
     *  Abs: '<S143>/Abs'
     *  Gain: '<S143>/Gain'
     *  Gain: '<S143>/Gain1'
     *  Product: '<S143>/Multiply2'
     *  Product: '<S143>/Multiply3'
     *  Signum: '<S143>/Sign'
     *  Sqrt: '<S143>/Sqrt'
     *  Sum: '<S143>/Add1'
     *  Sum: '<S143>/Subtract'
     */
    rtb_Saturation_j_idx_0 = (sqrtf((8.0F * fabsf(rtb_Divide_m_idx_2) +
      Controller_ConstB.d) * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
      rtb_Square_d + rtb_Gain_c4;

    /* Sum: '<S143>/Add3' incorporates:
     *  Signum: '<S143>/Sign'
     */
    rtb_Add3_fc = rtb_Divide_m_idx_2 + Controller_ConstB.d;

    /* Sum: '<S143>/Subtract1' incorporates:
     *  Signum: '<S143>/Sign'
     */
    rtb_Square_d = rtb_Divide_m_idx_2 - Controller_ConstB.d;

    /* Signum: '<S143>/Sign1' */
    if (rtb_Add3_fc < 0.0F) {
      rtb_Add3_fc = -1.0F;
    } else {
      if (rtb_Add3_fc > 0.0F) {
        rtb_Add3_fc = 1.0F;
      }
    }

    /* Signum: '<S143>/Sign2' */
    if (rtb_Square_d < 0.0F) {
      rtb_Square_d = -1.0F;
    } else {
      if (rtb_Square_d > 0.0F) {
        rtb_Square_d = 1.0F;
      }
    }

    /* Sum: '<S143>/Add5' incorporates:
     *  Gain: '<S143>/Gain2'
     *  Product: '<S143>/Multiply4'
     *  Signum: '<S143>/Sign'
     *  Sum: '<S143>/Add2'
     *  Sum: '<S143>/Add4'
     *  Sum: '<S143>/Subtract2'
     */
    rtb_Saturation_j_idx_0 += ((rtb_Divide_m_idx_2 - rtb_Saturation_j_idx_0) +
      rtb_Gain_c4) * ((rtb_Add3_fc - rtb_Square_d) * 0.5F);

    /* Gain: '<S156>/Gain' incorporates:
     *  DiscreteIntegrator: '<S158>/Integrator1'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S156>/Sum1'
     */
    rtb_Square_d = -(Controller_DW.Integrator1_DSTATE_e -
                     Controller_U.INS_Out.vd);
    Controller_B.Constant = CONTROL_PARAM.MC_VEL_Z_I_MIN;

    /* DiscreteIntegrator: '<S161>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S161>/Constant'
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

    /* DiscreteIntegrator: '<S163>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_d != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i = rtb_Square_d;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_Prev_ks != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i = rtb_Square_d;
    }

    /* Gain: '<S163>/Gain' incorporates:
     *  DiscreteIntegrator: '<S163>/Discrete-Time Integrator1'
     *  Sum: '<S163>/Sum5'
     */
    rtb_Gain_c4 = (rtb_Square_d - Controller_DW.DiscreteTimeIntegrator1_DSTAT_i)
      * 62.831852F;

    /* Switch: '<S152>/Switch' incorporates:
     *  Constant: '<S154>/Constant'
     *  RelationalOperator: '<S154>/Compare'
     */
    if (rtb_BitwiseAND_n <= 3) {
      /* SignalConversion: '<S5>/BusConversion_InsertedFor_VTOL_actuator_cmd_at_inport_0' incorporates:
       *  Bias: '<S152>/Bias'
       *  Gain: '<S152>/Gain'
       */
      Controller_B.mc_force_cmd[2] = 0.000999987125F * (real32_T)
        Controller_U.FMS_Out.throttle_cmd + -1.0F;
    } else {
      /* Product: '<S155>/Multiply' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S155>/Cos'
       *  Trigonometry: '<S155>/Cos1'
       */
      rtb_Saturation_g = arm_cos_f32(Controller_U.INS_Out.phi) * arm_cos_f32
        (Controller_U.INS_Out.theta);

      /* Gain: '<S155>/Gain' */
      rtb_Add3_fc = 2.0F * rtb_Saturation_g;

      /* Saturate: '<S155>/Saturation1' */
      if (rtb_Saturation_g > 1.0F) {
        rtb_Saturation_g = 1.0F;
      } else {
        if (rtb_Saturation_g < 0.5F) {
          rtb_Saturation_g = 0.5F;
        }
      }

      /* End of Saturate: '<S155>/Saturation1' */

      /* Product: '<S155>/Divide' incorporates:
       *  Constant: '<S155>/Constant'
       */
      rtb_Divide_m_idx_2 = 1.0F / rtb_Saturation_g;

      /* Switch: '<S163>/Switch' incorporates:
       *  Gain: '<S163>/Gain1'
       */
      if (Controller_U.FMS_Out.reset > 0) {
        rtb_Saturation_j_idx_1 = 0.0F;
      } else {
        rtb_Saturation_j_idx_1 = rtb_Gain_c4;
      }

      /* End of Switch: '<S163>/Switch' */

      /* Product: '<S160>/Multiply' incorporates:
       *  Constant: '<S160>/kd'
       */
      rtb_Saturation_g = CONTROL_PARAM.MC_VEL_Z_D * rtb_Saturation_j_idx_1;

      /* Saturate: '<S160>/Saturation' */
      if (rtb_Saturation_g > CONTROL_PARAM.MC_VEL_Z_D_MAX) {
        rtb_Saturation_g = CONTROL_PARAM.MC_VEL_Z_D_MAX;
      } else {
        if (rtb_Saturation_g < CONTROL_PARAM.MC_VEL_Z_D_MIN) {
          rtb_Saturation_g = CONTROL_PARAM.MC_VEL_Z_D_MIN;
        }
      }

      /* End of Saturate: '<S160>/Saturation' */

      /* Saturate: '<S155>/Saturation' */
      if (rtb_Add3_fc > 1.0F) {
        rtb_Add3_fc = 1.0F;
      } else {
        if (rtb_Add3_fc < 0.0F) {
          rtb_Add3_fc = 0.0F;
        }
      }

      /* End of Saturate: '<S155>/Saturation' */

      /* SignalConversion: '<S5>/BusConversion_InsertedFor_VTOL_actuator_cmd_at_inport_0' incorporates:
       *  Constant: '<S153>/hover_throttle'
       *  Constant: '<S162>/kp'
       *  DiscreteIntegrator: '<S161>/Discrete-Time Integrator'
       *  Product: '<S155>/Multiply1'
       *  Product: '<S162>/Multiply'
       *  Sum: '<S153>/Sum'
       *  Sum: '<S157>/Add'
       */
      Controller_B.mc_force_cmd[2] = ((CONTROL_PARAM.MC_VEL_Z_P * rtb_Square_d +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_l) + rtb_Saturation_g) *
        rtb_Divide_m_idx_2 * rtb_Add3_fc + CONTROL_PARAM.MC_HOVER_THRO;
    }

    /* End of Switch: '<S152>/Switch' */

    /* SignalConversion: '<S5>/BusConversion_InsertedFor_VTOL_actuator_cmd_at_inport_0' */
    Controller_B.mc_force_cmd[0] = Controller_ConstB.TmpBufferAtConstantOutport1;
    Controller_B.mc_force_cmd[1] = Controller_ConstB.TmpBufferAtConstantOutport1;

    /* Product: '<S159>/Multiply1' incorporates:
     *  Constant: '<S159>/const1'
     *  DiscreteIntegrator: '<S158>/Integrator'
     */
    rtb_Add3_fc = Controller_DW.Integrator_DSTATE_j * 0.05F;

    /* Sum: '<S159>/Add' incorporates:
     *  DiscreteIntegrator: '<S158>/Integrator1'
     *  Sum: '<S158>/Subtract'
     */
    rtb_Saturation_g = (Controller_DW.Integrator1_DSTATE_e -
                        Controller_U.FMS_Out.w_cmd) + rtb_Add3_fc;

    /* Signum: '<S159>/Sign' */
    if (rtb_Saturation_g < 0.0F) {
      rtb_Divide_m_idx_2 = -1.0F;
    } else if (rtb_Saturation_g > 0.0F) {
      rtb_Divide_m_idx_2 = 1.0F;
    } else {
      rtb_Divide_m_idx_2 = rtb_Saturation_g;
    }

    /* End of Signum: '<S159>/Sign' */

    /* Sum: '<S159>/Add2' incorporates:
     *  Abs: '<S159>/Abs'
     *  Gain: '<S159>/Gain'
     *  Gain: '<S159>/Gain1'
     *  Product: '<S159>/Multiply2'
     *  Product: '<S159>/Multiply3'
     *  Sqrt: '<S159>/Sqrt'
     *  Sum: '<S159>/Add1'
     *  Sum: '<S159>/Subtract'
     */
    rtb_Divide_m_idx_2 = (sqrtf((8.0F * fabsf(rtb_Saturation_g) +
      Controller_ConstB.d_i) * Controller_ConstB.d_i) - Controller_ConstB.d_i) *
      0.5F * rtb_Divide_m_idx_2 + rtb_Add3_fc;

    /* Sum: '<S159>/Add4' */
    rtb_phi_cmd = (rtb_Saturation_g - rtb_Divide_m_idx_2) + rtb_Add3_fc;

    /* Sum: '<S159>/Add3' */
    rtb_Add3_fc = rtb_Saturation_g + Controller_ConstB.d_i;

    /* Sum: '<S159>/Subtract1' */
    rtb_Saturation_g -= Controller_ConstB.d_i;

    /* Signum: '<S159>/Sign1' */
    if (rtb_Add3_fc < 0.0F) {
      rtb_Add3_fc = -1.0F;
    } else {
      if (rtb_Add3_fc > 0.0F) {
        rtb_Add3_fc = 1.0F;
      }
    }

    /* End of Signum: '<S159>/Sign1' */

    /* Signum: '<S159>/Sign2' */
    if (rtb_Saturation_g < 0.0F) {
      rtb_Saturation_g = -1.0F;
    } else {
      if (rtb_Saturation_g > 0.0F) {
        rtb_Saturation_g = 1.0F;
      }
    }

    /* End of Signum: '<S159>/Sign2' */

    /* Sum: '<S159>/Add5' incorporates:
     *  Gain: '<S159>/Gain2'
     *  Product: '<S159>/Multiply4'
     *  Sum: '<S159>/Subtract2'
     */
    rtb_Divide_m_idx_2 += (rtb_Add3_fc - rtb_Saturation_g) * 0.5F * rtb_phi_cmd;

    /* Update for DiscreteIntegrator: '<S118>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S118>/gain1'
     *  Constant: '<S118>/gain2'
     *  Constant: '<S118>/gain3'
     *  DiscreteIntegrator: '<S116>/Discrete-Time Integrator5'
     *  Product: '<S118>/Multiply'
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

    /* End of Update for DiscreteIntegrator: '<S118>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S145>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_PrevRe_p = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S147>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;

    /* Update for DiscreteIntegrator: '<S140>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S140>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE[0] += 0.002F *
      Controller_DW.Integrator_DSTATE[0];

    /* Update for DiscreteIntegrator: '<S145>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S145>/ki'
     *  Product: '<S145>/Multiply'
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

    /* Update for DiscreteIntegrator: '<S147>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] += 0.002F *
      rtb_Divide_m_idx_3;

    /* Update for DiscreteIntegrator: '<S140>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S140>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE[1] += 0.002F *
      Controller_DW.Integrator_DSTATE[1];

    /* Update for DiscreteIntegrator: '<S145>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S145>/ki'
     *  Product: '<S145>/Multiply'
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

    /* Update for DiscreteIntegrator: '<S147>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] += 0.002F *
      rtb_Divide_m_idx_0;
    Controller_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S116>/Discrete-Time Integrator5' */
    Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;

    /* Update for DiscreteIntegrator: '<S120>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 0U;

    /* Update for DiscreteIntegrator: '<S116>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S116>/Gain'
     *  Sum: '<S116>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] +=
      (rtb_TmpSignalConversionAtMult_0 -
       Controller_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S120>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[0] += 0.002F *
      rtb_Multiply_ni[0];

    /* Update for DiscreteIntegrator: '<S116>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S116>/Gain'
     *  Sum: '<S116>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] +=
      (rtb_TmpSignalConversionAtMult_1 -
       Controller_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S120>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[1] += 0.002F *
      rtb_Multiply_ni[1];

    /* Update for DiscreteIntegrator: '<S116>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S116>/Gain'
     *  Sum: '<S116>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] +=
      (rtb_TmpSignalConversionAtMult_2 -
       Controller_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S120>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[2] += 0.002F *
      rtb_Multiply_ni[2];
    Controller_DW.DiscreteTimeIntegrator1_PrevR_k = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Signum: '<S143>/Sign3' incorporates:
     *  Product: '<S143>/Divide'
     *  Sum: '<S143>/Add6'
     */
    rtb_Add3_fc = rtb_Divide_m_idx_1 + Controller_ConstB.d;

    /* Signum: '<S143>/Sign4' incorporates:
     *  Product: '<S143>/Divide'
     *  Sum: '<S143>/Subtract3'
     */
    rtb_TmpSignalConversionAtMult_0 = rtb_Divide_m_idx_1 - Controller_ConstB.d;

    /* Signum: '<S143>/Sign5' incorporates:
     *  Product: '<S143>/Divide'
     */
    if (rtb_Divide_m_idx_1 < 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = -1.0F;
    } else if (rtb_Divide_m_idx_1 > 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_1 = rtb_Divide_m_idx_1;
    }

    /* Signum: '<S143>/Sign3' */
    if (rtb_Add3_fc < 0.0F) {
      rtb_Add3_fc = -1.0F;
    } else {
      if (rtb_Add3_fc > 0.0F) {
        rtb_Add3_fc = 1.0F;
      }
    }

    /* Signum: '<S143>/Sign4' */
    if (rtb_TmpSignalConversionAtMult_0 < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else {
      if (rtb_TmpSignalConversionAtMult_0 > 0.0F) {
        rtb_TmpSignalConversionAtMult_0 = 1.0F;
      }
    }

    /* Signum: '<S143>/Sign6' incorporates:
     *  Product: '<S143>/Divide'
     */
    if (rtb_Divide_m_idx_1 < 0.0F) {
      rtb_TmpSignalConversionAtMult_2 = -1.0F;
    } else if (rtb_Divide_m_idx_1 > 0.0F) {
      rtb_TmpSignalConversionAtMult_2 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_2 = rtb_Divide_m_idx_1;
    }

    /* Update for DiscreteIntegrator: '<S140>/Integrator' incorporates:
     *  Constant: '<S143>/const'
     *  Gain: '<S143>/Gain3'
     *  Product: '<S143>/Divide'
     *  Product: '<S143>/Multiply5'
     *  Product: '<S143>/Multiply6'
     *  Sum: '<S143>/Subtract4'
     *  Sum: '<S143>/Subtract5'
     *  Sum: '<S143>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE[0] += ((rtb_Divide_m_idx_1 /
      Controller_ConstB.d - rtb_TmpSignalConversionAtMult_1) *
      Controller_ConstB.Gain4 * ((rtb_Add3_fc - rtb_TmpSignalConversionAtMult_0)
      * 0.5F) - rtb_TmpSignalConversionAtMult_2 * 78.448F) * 0.002F;

    /* Signum: '<S143>/Sign3' incorporates:
     *  Sum: '<S143>/Add6'
     */
    rtb_Add3_fc = rtb_Saturation_j_idx_0 + Controller_ConstB.d;

    /* Signum: '<S143>/Sign4' incorporates:
     *  Sum: '<S143>/Subtract3'
     */
    rtb_TmpSignalConversionAtMult_0 = rtb_Saturation_j_idx_0 -
      Controller_ConstB.d;

    /* Signum: '<S143>/Sign5' */
    if (rtb_Saturation_j_idx_0 < 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = -1.0F;
    } else if (rtb_Saturation_j_idx_0 > 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_1 = rtb_Saturation_j_idx_0;
    }

    /* Signum: '<S143>/Sign3' */
    if (rtb_Add3_fc < 0.0F) {
      rtb_Add3_fc = -1.0F;
    } else {
      if (rtb_Add3_fc > 0.0F) {
        rtb_Add3_fc = 1.0F;
      }
    }

    /* Signum: '<S143>/Sign4' */
    if (rtb_TmpSignalConversionAtMult_0 < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else {
      if (rtb_TmpSignalConversionAtMult_0 > 0.0F) {
        rtb_TmpSignalConversionAtMult_0 = 1.0F;
      }
    }

    /* Signum: '<S143>/Sign6' */
    if (rtb_Saturation_j_idx_0 < 0.0F) {
      rtb_TmpSignalConversionAtMult_2 = -1.0F;
    } else if (rtb_Saturation_j_idx_0 > 0.0F) {
      rtb_TmpSignalConversionAtMult_2 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_2 = rtb_Saturation_j_idx_0;
    }

    /* Update for DiscreteIntegrator: '<S140>/Integrator' incorporates:
     *  Constant: '<S143>/const'
     *  Gain: '<S143>/Gain3'
     *  Product: '<S143>/Divide'
     *  Product: '<S143>/Multiply5'
     *  Product: '<S143>/Multiply6'
     *  Sum: '<S143>/Subtract4'
     *  Sum: '<S143>/Subtract5'
     *  Sum: '<S143>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE[1] += ((rtb_Saturation_j_idx_0 /
      Controller_ConstB.d - rtb_TmpSignalConversionAtMult_1) *
      Controller_ConstB.Gain4 * ((rtb_Add3_fc - rtb_TmpSignalConversionAtMult_0)
      * 0.5F) - rtb_TmpSignalConversionAtMult_2 * 78.448F) * 0.002F;

    /* Update for DiscreteIntegrator: '<S158>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S158>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_e += 0.002F *
      Controller_DW.Integrator_DSTATE_j;

    /* Update for DiscreteIntegrator: '<S161>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S161>/ki'
     *  Product: '<S161>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_l += CONTROL_PARAM.MC_VEL_Z_I *
      rtb_Square_d * 0.002F;
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

    /* End of Update for DiscreteIntegrator: '<S161>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S163>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_i += 0.002F * rtb_Gain_c4;
    Controller_DW.DiscreteTimeIntegrator1_Prev_ks = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Signum: '<S159>/Sign6' incorporates:
     *  Signum: '<S159>/Sign5'
     */
    if (rtb_Divide_m_idx_2 < 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = -1.0F;

      /* Signum: '<S159>/Sign5' */
      rtb_TmpSignalConversionAtMult_2 = -1.0F;
    } else if (rtb_Divide_m_idx_2 > 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = 1.0F;

      /* Signum: '<S159>/Sign5' */
      rtb_TmpSignalConversionAtMult_2 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_1 = rtb_Divide_m_idx_2;

      /* Signum: '<S159>/Sign5' */
      rtb_TmpSignalConversionAtMult_2 = rtb_Divide_m_idx_2;
    }

    /* End of Signum: '<S159>/Sign6' */

    /* Sum: '<S159>/Add6' */
    rtb_Add3_fc = rtb_Divide_m_idx_2 + Controller_ConstB.d_i;

    /* Sum: '<S159>/Subtract3' */
    rtb_TmpSignalConversionAtMult_0 = rtb_Divide_m_idx_2 - Controller_ConstB.d_i;

    /* Signum: '<S159>/Sign3' */
    if (rtb_Add3_fc < 0.0F) {
      rtb_Add3_fc = -1.0F;
    } else {
      if (rtb_Add3_fc > 0.0F) {
        rtb_Add3_fc = 1.0F;
      }
    }

    /* End of Signum: '<S159>/Sign3' */

    /* Signum: '<S159>/Sign4' */
    if (rtb_TmpSignalConversionAtMult_0 < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else {
      if (rtb_TmpSignalConversionAtMult_0 > 0.0F) {
        rtb_TmpSignalConversionAtMult_0 = 1.0F;
      }
    }

    /* End of Signum: '<S159>/Sign4' */

    /* Update for DiscreteIntegrator: '<S158>/Integrator' incorporates:
     *  Constant: '<S159>/const'
     *  Gain: '<S159>/Gain3'
     *  Product: '<S159>/Divide'
     *  Product: '<S159>/Multiply5'
     *  Product: '<S159>/Multiply6'
     *  Sum: '<S159>/Subtract4'
     *  Sum: '<S159>/Subtract5'
     *  Sum: '<S159>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE_j += ((rtb_Divide_m_idx_2 /
      Controller_ConstB.d_i - rtb_TmpSignalConversionAtMult_2) *
      Controller_ConstB.Gain4_p * ((rtb_Add3_fc -
      rtb_TmpSignalConversionAtMult_0) * 0.5F) - rtb_TmpSignalConversionAtMult_1
      * 78.448F) * 0.002F;

    /* End of Outputs for SubSystem: '<S2>/MC_Controller' */
    break;
  }

  /* End of SwitchCase: '<S8>/Switch Case1' */

  /* Outputs for Atomic SubSystem: '<S6>/VTOL_Control_Allocation' */
#if AIRFRAME == 1

  /* Output and update for atomic system: '<S165>/VTOL1' */
  {
    real32_T b_max_p;
    int32_T max_index_p;
    real32_T rtb_Saturation3;
    real32_T rtb_Gain1_l;
    real32_T rtb_MatrixConcatenate[12];
    real32_T rtb_Saturation5_o[4];
    real32_T rtb_Subtract_h;
    real32_T rtb_Saturation_fa[9];
    real32_T rtb_Saturation4[4];
    real32_T rtb_Sum_e[4];
    int32_T i_p;
    real32_T rtb_Switch_gr_idx_1_p;
    real32_T rtb_Saturation1_l_idx_2_p;
    real32_T rtb_Saturation1_l_idx_0_p;
    real32_T rtb_Saturation1_l_idx_1_p;
    uint16_T u0_p;

    /* Saturate: '<S182>/Saturation' incorporates:
     *  Bias: '<S182>/Bias'
     *  Bias: '<S182>/Bias1'
     *  Bias: '<S182>/Bias2'
     *  Bias: '<S182>/Bias3'
     *  Constant: '<S182>/Constant'
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

    /* End of Saturate: '<S182>/Saturation' */

    /* Saturate: '<S169>/Saturation1' */
    if (Controller_B.mc_torque_cmd[0] > 1.0F) {
      rtb_Saturation1_l_idx_0_p = 1.0F;
    } else if (Controller_B.mc_torque_cmd[0] < -1.0F) {
      rtb_Saturation1_l_idx_0_p = -1.0F;
    } else {
      rtb_Saturation1_l_idx_0_p = Controller_B.mc_torque_cmd[0];
    }

    if (Controller_B.mc_torque_cmd[1] > 1.0F) {
      rtb_Saturation1_l_idx_1_p = 1.0F;
    } else if (Controller_B.mc_torque_cmd[1] < -1.0F) {
      rtb_Saturation1_l_idx_1_p = -1.0F;
    } else {
      rtb_Saturation1_l_idx_1_p = Controller_B.mc_torque_cmd[1];
    }

    if (Controller_B.mc_torque_cmd[2] > 1.0F) {
      rtb_Saturation1_l_idx_2_p = 1.0F;
    } else if (Controller_B.mc_torque_cmd[2] < -1.0F) {
      rtb_Saturation1_l_idx_2_p = -1.0F;
    } else {
      rtb_Saturation1_l_idx_2_p = Controller_B.mc_torque_cmd[2];
    }

    /* End of Saturate: '<S169>/Saturation1' */

    /* Gain: '<S169>/Gain1' incorporates:
     *  Bias: '<S169>/Bias'
     *  Constant: '<S169>/Constant'
     */
    rtb_Gain1_l = ((real32_T)CONTROL_PARAM.MC_OUT_MAX + -1000.0F) * 0.001F;

    /* Saturate: '<S169>/Saturation2' */
    if (Controller_B.mc_force_cmd[2] > 1.0F) {
      rtb_Saturation3 = 1.0F;
    } else if (Controller_B.mc_force_cmd[2] < 0.0F) {
      rtb_Saturation3 = 0.0F;
    } else {
      rtb_Saturation3 = Controller_B.mc_force_cmd[2];
    }

    /* End of Saturate: '<S169>/Saturation2' */
    for (i_p = 0; i_p < 4; i_p++) {
      /* Product: '<S169>/Multiply' */
      rtb_Switch_gr_idx_1_p = Controller_ConstB.VTOL1.pq_column[i_p + 4] *
        rtb_Saturation1_l_idx_1_p + Controller_ConstB.VTOL1.pq_column[i_p] *
        rtb_Saturation1_l_idx_0_p;

      /* Sum: '<S169>/Sum' */
      rtb_Sum_e[i_p] = rtb_Switch_gr_idx_1_p + rtb_Saturation3;

      /* Product: '<S169>/Multiply' */
      rtb_Saturation4[i_p] = rtb_Switch_gr_idx_1_p;
    }

    /* Gain: '<S169>/Gain2' incorporates:
     *  Bias: '<S169>/Bias1'
     *  Constant: '<S169>/Constant1'
     */
    rtb_Saturation1_l_idx_0_p = ((real32_T)CONTROL_PARAM.MC_OUT_MIN + -1000.0F) *
      0.001F;

    /* MinMax: '<S169>/Max' */
    rtb_Switch_gr_idx_1_p = fmaxf(fmaxf(fmaxf(rtb_Sum_e[0], rtb_Sum_e[1]),
      rtb_Sum_e[2]), rtb_Sum_e[3]);

    /* MinMax: '<S169>/Max1' */
    b_max_p = fminf(fminf(fminf(rtb_Sum_e[0], rtb_Sum_e[1]), rtb_Sum_e[2]),
                    rtb_Sum_e[3]);

    /* Switch: '<S176>/Switch' incorporates:
     *  Logic: '<S176>/Logical Operator'
     *  MinMax: '<S169>/Max'
     *  MinMax: '<S169>/Max1'
     *  RelationalOperator: '<S176>/Relational Operator'
     *  RelationalOperator: '<S176>/Relational Operator1'
     */
    if ((rtb_Switch_gr_idx_1_p > rtb_Gain1_l) || (b_max_p <
         rtb_Saturation1_l_idx_0_p)) {
      /* Sum: '<S176>/Subtract1' */
      rtb_Saturation1_l_idx_1_p = rtb_Gain1_l - rtb_Saturation1_l_idx_0_p;

      /* Sum: '<S176>/Subtract' */
      rtb_Subtract_h = rtb_Switch_gr_idx_1_p - b_max_p;

      /* Switch: '<S176>/Switch1' incorporates:
       *  Constant: '<S176>/Constant3'
       *  Gain: '<S176>/Gain'
       *  Product: '<S176>/Divide'
       *  RelationalOperator: '<S176>/Relational Operator2'
       *  Sum: '<S176>/Add'
       *  Sum: '<S176>/Subtract2'
       *  Sum: '<S176>/Subtract3'
       */
      if (rtb_Subtract_h > rtb_Saturation1_l_idx_1_p) {
        rtb_Saturation1_l_idx_1_p /= rtb_Subtract_h;
        rtb_Switch_gr_idx_1_p = ((rtb_Gain1_l - rtb_Switch_gr_idx_1_p) +
          (rtb_Saturation1_l_idx_0_p - b_max_p)) * 0.5F;
      } else {
        rtb_Saturation1_l_idx_1_p = 1.0F;

        /* Switch: '<S176>/Switch2' incorporates:
         *  Constant: '<S176>/Constant3'
         *  RelationalOperator: '<S176>/Relational Operator3'
         *  Sum: '<S176>/Subtract4'
         *  Sum: '<S176>/Subtract5'
         */
        if (rtb_Switch_gr_idx_1_p > rtb_Gain1_l) {
          rtb_Switch_gr_idx_1_p = rtb_Gain1_l - rtb_Switch_gr_idx_1_p;
        } else {
          rtb_Switch_gr_idx_1_p = rtb_Saturation1_l_idx_0_p - b_max_p;
        }

        /* End of Switch: '<S176>/Switch2' */
      }

      /* End of Switch: '<S176>/Switch1' */
    } else {
      rtb_Saturation1_l_idx_1_p = 1.0F;
      rtb_Switch_gr_idx_1_p = 0.0F;
    }

    /* End of Switch: '<S176>/Switch' */

    /* Sum: '<S169>/Sum1' */
    rtb_Saturation3 += rtb_Switch_gr_idx_1_p;

    /* Saturate: '<S169>/Saturation3' */
    if (rtb_Saturation3 > 1.0F) {
      rtb_Saturation3 = 1.0F;
    } else {
      if (rtb_Saturation3 < 0.0F) {
        rtb_Saturation3 = 0.0F;
      }
    }

    /* End of Saturate: '<S169>/Saturation3' */

    /* MATLAB Function: '<S169>/R_Remix' */
    rtb_Subtract_h = 100.0F;
    b_max_p = -100.0F;
    i_p = 0;
    max_index_p = 0;

    /* Sum: '<S169>/Sum2' incorporates:
     *  Product: '<S169>/Multiply1'
     */
    rtb_Switch_gr_idx_1_p = rtb_Saturation4[0] * rtb_Saturation1_l_idx_1_p +
      rtb_Saturation3;

    /* Saturate: '<S169>/Saturation4' */
    if (rtb_Switch_gr_idx_1_p > 1.0F) {
      rtb_Switch_gr_idx_1_p = 1.0F;
    } else {
      if (rtb_Switch_gr_idx_1_p < 0.0F) {
        rtb_Switch_gr_idx_1_p = 0.0F;
      }
    }

    /* Sum: '<S169>/Sum3' incorporates:
     *  Product: '<S169>/Multiply2'
     */
    rtb_Switch_gr_idx_1_p += Controller_ConstB.VTOL1.r_column[0] *
      rtb_Saturation1_l_idx_2_p;

    /* MATLAB Function: '<S169>/R_Remix' */
    if (rtb_Switch_gr_idx_1_p < 100.0F) {
      rtb_Subtract_h = rtb_Switch_gr_idx_1_p;
      i_p = 1;
    }

    if (rtb_Switch_gr_idx_1_p > -100.0F) {
      b_max_p = rtb_Switch_gr_idx_1_p;
      max_index_p = 1;
    }

    /* Product: '<S169>/Multiply1' */
    rtb_Saturation4[0] = rtb_Switch_gr_idx_1_p;

    /* Sum: '<S169>/Sum2' incorporates:
     *  Product: '<S169>/Multiply1'
     */
    rtb_Switch_gr_idx_1_p = rtb_Saturation4[1] * rtb_Saturation1_l_idx_1_p +
      rtb_Saturation3;

    /* Saturate: '<S169>/Saturation4' */
    if (rtb_Switch_gr_idx_1_p > 1.0F) {
      rtb_Switch_gr_idx_1_p = 1.0F;
    } else {
      if (rtb_Switch_gr_idx_1_p < 0.0F) {
        rtb_Switch_gr_idx_1_p = 0.0F;
      }
    }

    /* Sum: '<S169>/Sum3' incorporates:
     *  Product: '<S169>/Multiply2'
     */
    rtb_Switch_gr_idx_1_p += Controller_ConstB.VTOL1.r_column[1] *
      rtb_Saturation1_l_idx_2_p;

    /* MATLAB Function: '<S169>/R_Remix' */
    if (rtb_Switch_gr_idx_1_p < rtb_Subtract_h) {
      rtb_Subtract_h = rtb_Switch_gr_idx_1_p;
      i_p = 2;
    }

    if (rtb_Switch_gr_idx_1_p > b_max_p) {
      b_max_p = rtb_Switch_gr_idx_1_p;
      max_index_p = 2;
    }

    /* Product: '<S169>/Multiply1' */
    rtb_Saturation4[1] = rtb_Switch_gr_idx_1_p;

    /* Sum: '<S169>/Sum2' incorporates:
     *  Product: '<S169>/Multiply1'
     */
    rtb_Switch_gr_idx_1_p = rtb_Saturation4[2] * rtb_Saturation1_l_idx_1_p +
      rtb_Saturation3;

    /* Saturate: '<S169>/Saturation4' */
    if (rtb_Switch_gr_idx_1_p > 1.0F) {
      rtb_Switch_gr_idx_1_p = 1.0F;
    } else {
      if (rtb_Switch_gr_idx_1_p < 0.0F) {
        rtb_Switch_gr_idx_1_p = 0.0F;
      }
    }

    /* Sum: '<S169>/Sum3' incorporates:
     *  Product: '<S169>/Multiply2'
     */
    rtb_Switch_gr_idx_1_p += Controller_ConstB.VTOL1.r_column[2] *
      rtb_Saturation1_l_idx_2_p;

    /* MATLAB Function: '<S169>/R_Remix' */
    if (rtb_Switch_gr_idx_1_p < rtb_Subtract_h) {
      rtb_Subtract_h = rtb_Switch_gr_idx_1_p;
      i_p = 3;
    }

    if (rtb_Switch_gr_idx_1_p > b_max_p) {
      b_max_p = rtb_Switch_gr_idx_1_p;
      max_index_p = 3;
    }

    /* Product: '<S169>/Multiply1' */
    rtb_Saturation4[2] = rtb_Switch_gr_idx_1_p;

    /* Sum: '<S169>/Sum2' incorporates:
     *  Product: '<S169>/Multiply1'
     */
    rtb_Switch_gr_idx_1_p = rtb_Saturation4[3] * rtb_Saturation1_l_idx_1_p +
      rtb_Saturation3;

    /* Saturate: '<S169>/Saturation4' */
    if (rtb_Switch_gr_idx_1_p > 1.0F) {
      rtb_Switch_gr_idx_1_p = 1.0F;
    } else {
      if (rtb_Switch_gr_idx_1_p < 0.0F) {
        rtb_Switch_gr_idx_1_p = 0.0F;
      }
    }

    /* Sum: '<S169>/Sum3' incorporates:
     *  Product: '<S169>/Multiply2'
     */
    rtb_Switch_gr_idx_1_p += Controller_ConstB.VTOL1.r_column[3] *
      rtb_Saturation1_l_idx_2_p;

    /* MATLAB Function: '<S169>/R_Remix' */
    if (rtb_Switch_gr_idx_1_p < rtb_Subtract_h) {
      rtb_Subtract_h = rtb_Switch_gr_idx_1_p;
      i_p = 4;
    }

    if (rtb_Switch_gr_idx_1_p > b_max_p) {
      b_max_p = rtb_Switch_gr_idx_1_p;
      max_index_p = 4;
    }

    /* Product: '<S169>/Multiply1' */
    rtb_Saturation4[3] = rtb_Switch_gr_idx_1_p;

    /* MATLAB Function: '<S169>/R_Remix' */
    if ((b_max_p > rtb_Gain1_l) || (rtb_Subtract_h < rtb_Saturation1_l_idx_0_p))
    {
      rtb_Saturation1_l_idx_2_p = rtb_Saturation1_l_idx_0_p - rtb_Subtract_h;
      if (b_max_p - rtb_Gain1_l > rtb_Saturation1_l_idx_2_p) {
        rtb_Saturation1_l_idx_2_p = rtb_Gain1_l - b_max_p;
        if ((max_index_p == 3) || (max_index_p == 4)) {
          rtb_Saturation1_l_idx_2_p = -rtb_Saturation1_l_idx_2_p;
        }
      } else {
        if ((i_p == 3) || (i_p == 4)) {
          rtb_Saturation1_l_idx_2_p = -rtb_Saturation1_l_idx_2_p;
        }
      }

      rtb_Sum_e[0] = rtb_Saturation1_l_idx_2_p;
      rtb_Sum_e[1] = rtb_Saturation1_l_idx_2_p;
      rtb_Sum_e[2] = -rtb_Saturation1_l_idx_2_p;
      rtb_Sum_e[3] = -rtb_Saturation1_l_idx_2_p;
    } else {
      rtb_Sum_e[0] = 0.0F;
      rtb_Sum_e[1] = 0.0F;
      rtb_Sum_e[2] = 0.0F;
      rtb_Sum_e[3] = 0.0F;
    }

    /* MultiPortSwitch: '<S172>/Multiport Switch' incorporates:
     *  Constant: '<S173>/Constant1'
     *  Constant: '<S173>/Constant12'
     *  Constant: '<S173>/Constant2'
     *  Constant: '<S173>/Constant7'
     *  DataTypeConversion: '<S182>/Data Type Conversion'
     *  DataTypeConversion: '<S183>/Data Type Conversion'
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
        /* Saturate: '<S183>/Saturation' incorporates:
         *  Constant: '<S183>/Standby'
         *  Reshape: '<S183>/Reshape'
         */
        if (Controller_ConstP.pooled7[i_p] > 2000.0F) {
          rtb_Gain1_l = 2000.0F;
        } else if (Controller_ConstP.pooled7[i_p] < 1000.0F) {
          rtb_Gain1_l = 1000.0F;
        } else {
          rtb_Gain1_l = Controller_ConstP.pooled7[i_p];
        }

        rtb_VariantMergeForOutportactua[i_p] = (uint16_T)fmodf(floorf
          (rtb_Gain1_l), 65536.0F);
      }

      /* Saturate: '<S183>/Saturation' incorporates:
       *  Bias: '<S183>/Bias'
       *  Constant: '<S183>/Constant'
       *  DataTypeConversion: '<S183>/Data Type Conversion'
       */
      if (1500.0F + CONTROL_PARAM.SERVO1_BIAS > 2000.0F) {
        rtb_Gain1_l = 2000.0F;
      } else if (1500.0F + CONTROL_PARAM.SERVO1_BIAS < 1000.0F) {
        rtb_Gain1_l = 1000.0F;
      } else {
        rtb_Gain1_l = 1500.0F + CONTROL_PARAM.SERVO1_BIAS;
      }

      rtb_VariantMergeForOutportactua[5] = (uint16_T)fmodf(floorf(rtb_Gain1_l),
        65536.0F);

      /* Saturate: '<S183>/Saturation' incorporates:
       *  Bias: '<S183>/Bias1'
       *  Constant: '<S183>/Constant'
       *  DataTypeConversion: '<S183>/Data Type Conversion'
       */
      if (1500.0F + CONTROL_PARAM.SERVO2_BIAS > 2000.0F) {
        rtb_Gain1_l = 2000.0F;
      } else if (1500.0F + CONTROL_PARAM.SERVO2_BIAS < 1000.0F) {
        rtb_Gain1_l = 1000.0F;
      } else {
        rtb_Gain1_l = 1500.0F + CONTROL_PARAM.SERVO2_BIAS;
      }

      rtb_VariantMergeForOutportactua[6] = (uint16_T)fmodf(floorf(rtb_Gain1_l),
        65536.0F);

      /* Saturate: '<S183>/Saturation' incorporates:
       *  Bias: '<S183>/Bias2'
       *  Constant: '<S183>/Constant'
       *  DataTypeConversion: '<S183>/Data Type Conversion'
       */
      if (1500.0F + CONTROL_PARAM.SERVO3_BIAS > 2000.0F) {
        rtb_Gain1_l = 2000.0F;
      } else if (1500.0F + CONTROL_PARAM.SERVO3_BIAS < 1000.0F) {
        rtb_Gain1_l = 1000.0F;
      } else {
        rtb_Gain1_l = 1500.0F + CONTROL_PARAM.SERVO3_BIAS;
      }

      rtb_VariantMergeForOutportactua[7] = (uint16_T)fmodf(floorf(rtb_Gain1_l),
        65536.0F);

      /* Saturate: '<S183>/Saturation' incorporates:
       *  Bias: '<S183>/Bias3'
       *  Constant: '<S183>/Constant'
       *  DataTypeConversion: '<S183>/Data Type Conversion'
       */
      if (1500.0F + CONTROL_PARAM.SERVO4_BIAS > 2000.0F) {
        rtb_Gain1_l = 2000.0F;
      } else if (1500.0F + CONTROL_PARAM.SERVO4_BIAS < 1000.0F) {
        rtb_Gain1_l = 1000.0F;
      } else {
        rtb_Gain1_l = 1500.0F + CONTROL_PARAM.SERVO4_BIAS;
      }

      rtb_VariantMergeForOutportactua[8] = (uint16_T)fmodf(floorf(rtb_Gain1_l),
        65536.0F);
      break;

     case 3:
      rtb_MatrixConcatenate[11] = CONTROL_PARAM.FW_YAW_EFFC *
        CONTROL_PARAM.FW_RUDDER_DIR;

      /* SignalConversion: '<S173>/ConcatBufferAtVector Concatenate2In3' incorporates:
       *  Constant: '<S173>/Constant11'
       *  Constant: '<S173>/Constant12'
       */
      rtb_MatrixConcatenate[10] = 0.0F;

      /* SignalConversion: '<S173>/ConcatBufferAtVector Concatenate2In2' incorporates:
       *  Constant: '<S173>/Constant10'
       */
      rtb_MatrixConcatenate[9] = 0.0F;

      /* SignalConversion: '<S173>/ConcatBufferAtVector Concatenate2In1' incorporates:
       *  Constant: '<S173>/Constant9'
       */
      rtb_MatrixConcatenate[8] = 0.0F;

      /* SignalConversion: '<S173>/ConcatBufferAtVector Concatenate1In4' incorporates:
       *  Constant: '<S173>/Constant8'
       */
      rtb_MatrixConcatenate[7] = 0.0F;
      rtb_MatrixConcatenate[6] = CONTROL_PARAM.FW_PITCH_EFFC *
        CONTROL_PARAM.FW_ELEVATOR_DIR;

      /* SignalConversion: '<S173>/ConcatBufferAtVector Concatenate1In2' incorporates:
       *  Constant: '<S173>/Constant6'
       *  Constant: '<S173>/Constant7'
       */
      rtb_MatrixConcatenate[5] = 0.0F;

      /* SignalConversion: '<S173>/ConcatBufferAtVector Concatenate1In1' incorporates:
       *  Constant: '<S173>/Constant5'
       */
      rtb_MatrixConcatenate[4] = 0.0F;

      /* SignalConversion: '<S173>/ConcatBufferAtVector ConcatenateIn4' incorporates:
       *  Constant: '<S173>/Constant4'
       */
      rtb_MatrixConcatenate[3] = 0.0F;

      /* SignalConversion: '<S173>/ConcatBufferAtVector ConcatenateIn3' incorporates:
       *  Constant: '<S173>/Constant3'
       */
      rtb_MatrixConcatenate[2] = 0.0F;
      rtb_MatrixConcatenate[1] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON2_DIR;
      rtb_MatrixConcatenate[0] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON1_DIR;

      /* Saturate: '<S168>/Saturation5' incorporates:
       *  Constant: '<S173>/Constant1'
       *  Constant: '<S173>/Constant2'
       */
      if (Controller_B.fw_torque_cmd[0] > 1.0F) {
        /* Product: '<S168>/Multiply1' */
        rtb_Gain1_l = 1.0F;
      } else if (Controller_B.fw_torque_cmd[0] < -1.0F) {
        /* Product: '<S168>/Multiply1' */
        rtb_Gain1_l = -1.0F;
      } else {
        /* Product: '<S168>/Multiply1' */
        rtb_Gain1_l = Controller_B.fw_torque_cmd[0];
      }

      if (Controller_B.fw_torque_cmd[1] > 1.0F) {
        /* Product: '<S168>/Multiply1' */
        rtb_Saturation1_l_idx_2_p = 1.0F;
      } else if (Controller_B.fw_torque_cmd[1] < -1.0F) {
        /* Product: '<S168>/Multiply1' */
        rtb_Saturation1_l_idx_2_p = -1.0F;
      } else {
        /* Product: '<S168>/Multiply1' */
        rtb_Saturation1_l_idx_2_p = Controller_B.fw_torque_cmd[1];
      }

      if (Controller_B.fw_torque_cmd[2] > 1.0F) {
        /* Product: '<S168>/Multiply1' */
        rtb_Saturation3 = 1.0F;
      } else if (Controller_B.fw_torque_cmd[2] < -1.0F) {
        /* Product: '<S168>/Multiply1' */
        rtb_Saturation3 = -1.0F;
      } else {
        /* Product: '<S168>/Multiply1' */
        rtb_Saturation3 = Controller_B.fw_torque_cmd[2];
      }

      /* End of Saturate: '<S168>/Saturation5' */
      for (i_p = 0; i_p < 4; i_p++) {
        /* Bias: '<S168>/Bias' incorporates:
         *  Gain: '<S168>/Gain1'
         *  Product: '<S168>/Multiply1'
         */
        rtb_Saturation5_o[i_p] = 500.0F * (rtb_MatrixConcatenate[i_p + 8] *
          rtb_Saturation3 + (rtb_MatrixConcatenate[i_p + 4] *
                             rtb_Saturation1_l_idx_2_p +
                             rtb_MatrixConcatenate[i_p] * rtb_Gain1_l)) +
          1500.0F;

        /* Sum: '<S169>/Sum4' */
        rtb_Saturation1_l_idx_0_p = rtb_Saturation4[i_p] + rtb_Sum_e[i_p];

        /* Saturate: '<S169>/Saturation5' */
        if (rtb_Saturation1_l_idx_0_p > 1.0F) {
          rtb_Saturation1_l_idx_0_p = 1.0F;
        } else {
          if (rtb_Saturation1_l_idx_0_p < 0.0F) {
            rtb_Saturation1_l_idx_0_p = 0.0F;
          }
        }

        /* End of Saturate: '<S169>/Saturation5' */

        /* DataTypeConversion: '<S169>/Data Type Conversion' incorporates:
         *  Constant: '<S169>/Constant2'
         *  Gain: '<S169>/Gain3'
         *  Sum: '<S169>/Sum5'
         */
        u0_p = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          rtb_Saturation1_l_idx_0_p), 4.2949673E+9F) + 1000U);

        /* Saturate: '<S169>/Saturation' */
        if (u0_p > CONTROL_PARAM.MC_OUT_MAX) {
          rtb_VariantMergeForOutportactua[i_p] = CONTROL_PARAM.MC_OUT_MAX;
        } else if (u0_p < CONTROL_PARAM.MC_OUT_MIN) {
          rtb_VariantMergeForOutportactua[i_p] = CONTROL_PARAM.MC_OUT_MIN;
        } else {
          rtb_VariantMergeForOutportactua[i_p] = u0_p;
        }

        /* End of Saturate: '<S169>/Saturation' */
      }

      /* Saturate: '<S168>/Saturation' */
      if (Controller_B.fw_force_cmd[0] > 1.0F) {
        rtb_Gain1_l = 1.0F;
      } else if (Controller_B.fw_force_cmd[0] < 0.0F) {
        rtb_Gain1_l = 0.0F;
      } else {
        rtb_Gain1_l = Controller_B.fw_force_cmd[0];
      }

      /* End of Saturate: '<S168>/Saturation' */

      /* DataTypeConversion: '<S175>/Data Type Conversion' incorporates:
       *  Constant: '<S175>/Constant1'
       *  Gain: '<S175>/Gain1'
       *  Sum: '<S175>/Sum1'
       */
      u0_p = (uint16_T)((uint32_T)fmodf(floorf(1000.0F * rtb_Gain1_l),
        4.2949673E+9F) + 1000U);

      /* Saturate: '<S168>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[4] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[4] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[4] = u0_p;
      }

      /* DataTypeConversion: '<S168>/Data Type Conversion' incorporates:
       *  Bias: '<S168>/Bias1'
       */
      rtb_Gain1_l = fmodf(floorf(rtb_Saturation5_o[0] +
        CONTROL_PARAM.SERVO1_BIAS), 65536.0F);
      u0_p = (uint16_T)(rtb_Gain1_l < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                        (uint16_T)-rtb_Gain1_l : (int32_T)(uint16_T)rtb_Gain1_l);

      /* Saturate: '<S168>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[5] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[5] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[5] = u0_p;
      }

      /* DataTypeConversion: '<S168>/Data Type Conversion1' incorporates:
       *  Bias: '<S168>/Bias2'
       */
      rtb_Gain1_l = fmodf(floorf(rtb_Saturation5_o[1] +
        CONTROL_PARAM.SERVO2_BIAS), 65536.0F);
      u0_p = (uint16_T)(rtb_Gain1_l < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                        (uint16_T)-rtb_Gain1_l : (int32_T)(uint16_T)rtb_Gain1_l);

      /* Saturate: '<S168>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[6] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[6] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[6] = u0_p;
      }

      /* DataTypeConversion: '<S168>/Data Type Conversion2' incorporates:
       *  Bias: '<S168>/Bias3'
       */
      rtb_Gain1_l = fmodf(floorf(rtb_Saturation5_o[2] +
        CONTROL_PARAM.SERVO3_BIAS), 65536.0F);
      u0_p = (uint16_T)(rtb_Gain1_l < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                        (uint16_T)-rtb_Gain1_l : (int32_T)(uint16_T)rtb_Gain1_l);

      /* Saturate: '<S168>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[7] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[7] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[7] = u0_p;
      }

      /* DataTypeConversion: '<S168>/Data Type Conversion3' incorporates:
       *  Bias: '<S168>/Bias4'
       */
      rtb_Gain1_l = fmodf(floorf(rtb_Saturation5_o[3] +
        CONTROL_PARAM.SERVO4_BIAS), 65536.0F);
      u0_p = (uint16_T)(rtb_Gain1_l < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                        (uint16_T)-rtb_Gain1_l : (int32_T)(uint16_T)rtb_Gain1_l);

      /* Saturate: '<S168>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[8] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[8] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[8] = u0_p;
      }
      break;

     default:
      for (i_p = 0; i_p < 9; i_p++) {
        rtb_VariantMergeForOutportactua[i_p] = (uint16_T)fmodf(floorf
          (rtb_Saturation_fa[i_p]), 65536.0F);
      }
      break;
    }

    /* End of MultiPortSwitch: '<S172>/Multiport Switch' */
  }

#elif AIRFRAME == 2

  /* Output and update for atomic system: '<S165>/VTOL2' */
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

    /* Saturate: '<S191>/Saturation' incorporates:
     *  Bias: '<S191>/Bias'
     *  Bias: '<S191>/Bias1'
     *  Bias: '<S191>/Bias2'
     *  Bias: '<S191>/Bias3'
     *  Constant: '<S191>/Constant'
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

    /* End of Saturate: '<S191>/Saturation' */

    /* MultiPortSwitch: '<S186>/Multiport Switch' incorporates:
     *  Constant: '<S187>/Constant1'
     *  Constant: '<S187>/Constant11'
     *  Constant: '<S187>/Constant12'
     *  Constant: '<S187>/Constant2'
     *  Constant: '<S187>/Constant7'
     *  Constant: '<S187>/Constant8'
     *  DataTypeConversion: '<S191>/Data Type Conversion'
     *  DataTypeConversion: '<S192>/Data Type Conversion'
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
        /* Saturate: '<S192>/Saturation' incorporates:
         *  Constant: '<S192>/Disarm'
         *  Reshape: '<S192>/Reshape'
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

      /* Saturate: '<S192>/Saturation' incorporates:
       *  Bias: '<S192>/Bias'
       *  Constant: '<S192>/Constant'
       *  DataTypeConversion: '<S192>/Data Type Conversion'
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

      /* Saturate: '<S192>/Saturation' incorporates:
       *  Bias: '<S192>/Bias1'
       *  Constant: '<S192>/Constant'
       *  DataTypeConversion: '<S192>/Data Type Conversion'
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

      /* Saturate: '<S192>/Saturation' incorporates:
       *  Bias: '<S192>/Bias2'
       *  Constant: '<S192>/Constant'
       *  DataTypeConversion: '<S192>/Data Type Conversion'
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

      /* Saturate: '<S192>/Saturation' incorporates:
       *  Bias: '<S192>/Bias3'
       *  Constant: '<S192>/Constant'
       *  DataTypeConversion: '<S192>/Data Type Conversion'
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

      /* SignalConversion: '<S187>/ConcatBufferAtVector Concatenate2In2' incorporates:
       *  Constant: '<S187>/Constant10'
       *  Constant: '<S187>/Constant11'
       *  Constant: '<S187>/Constant12'
       */
      rtb_MatrixConcatenate_g[9] = 0.0F;

      /* SignalConversion: '<S187>/ConcatBufferAtVector Concatenate2In1' incorporates:
       *  Constant: '<S187>/Constant9'
       */
      rtb_MatrixConcatenate_g[8] = 0.0F;
      rtb_MatrixConcatenate_g[7] = -CONTROL_PARAM.FW_PITCH_EFFC *
        CONTROL_PARAM.FW_TAIL2_DIR;
      rtb_MatrixConcatenate_g[6] = CONTROL_PARAM.FW_PITCH_EFFC *
        CONTROL_PARAM.FW_TAIL1_DIR;

      /* SignalConversion: '<S187>/ConcatBufferAtVector Concatenate1In2' incorporates:
       *  Constant: '<S187>/Constant6'
       *  Constant: '<S187>/Constant7'
       *  Constant: '<S187>/Constant8'
       */
      rtb_MatrixConcatenate_g[5] = 0.0F;

      /* SignalConversion: '<S187>/ConcatBufferAtVector Concatenate1In1' incorporates:
       *  Constant: '<S187>/Constant5'
       */
      rtb_MatrixConcatenate_g[4] = 0.0F;

      /* SignalConversion: '<S187>/ConcatBufferAtVector ConcatenateIn4' incorporates:
       *  Constant: '<S187>/Constant4'
       */
      rtb_MatrixConcatenate_g[3] = 0.0F;

      /* SignalConversion: '<S187>/ConcatBufferAtVector ConcatenateIn3' incorporates:
       *  Constant: '<S187>/Constant3'
       */
      rtb_MatrixConcatenate_g[2] = 0.0F;
      rtb_MatrixConcatenate_g[1] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON2_DIR;
      rtb_MatrixConcatenate_g[0] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON1_DIR;

      /* Saturate: '<S184>/Saturation5' incorporates:
       *  Constant: '<S187>/Constant1'
       *  Constant: '<S187>/Constant2'
       */
      if (Controller_B.fw_torque_cmd[0] > 1.0F) {
        /* Product: '<S184>/Multiply1' */
        tmp_m = 1.0F;
      } else if (Controller_B.fw_torque_cmd[0] < -1.0F) {
        /* Product: '<S184>/Multiply1' */
        tmp_m = -1.0F;
      } else {
        /* Product: '<S184>/Multiply1' */
        tmp_m = Controller_B.fw_torque_cmd[0];
      }

      if (Controller_B.fw_torque_cmd[1] > 1.0F) {
        /* Product: '<S184>/Multiply1' */
        tmp_ev = 1.0F;
      } else if (Controller_B.fw_torque_cmd[1] < -1.0F) {
        /* Product: '<S184>/Multiply1' */
        tmp_ev = -1.0F;
      } else {
        /* Product: '<S184>/Multiply1' */
        tmp_ev = Controller_B.fw_torque_cmd[1];
      }

      if (Controller_B.fw_torque_cmd[2] > 1.0F) {
        /* Product: '<S184>/Multiply1' */
        tmp_k = 1.0F;
      } else if (Controller_B.fw_torque_cmd[2] < -1.0F) {
        /* Product: '<S184>/Multiply1' */
        tmp_k = -1.0F;
      } else {
        /* Product: '<S184>/Multiply1' */
        tmp_k = Controller_B.fw_torque_cmd[2];
      }

      /* End of Saturate: '<S184>/Saturation5' */
      for (i_o = 0; i_o < 4; i_o++) {
        /* Bias: '<S184>/Bias' incorporates:
         *  Gain: '<S184>/Gain1'
         *  Product: '<S184>/Multiply1'
         */
        rtb_Multiply_ka[i_o] = 500.0F * (rtb_MatrixConcatenate_g[i_o + 8] *
          tmp_k + (rtb_MatrixConcatenate_g[i_o + 4] * tmp_ev +
                   rtb_MatrixConcatenate_g[i_o] * tmp_m)) + 1500.0F;
      }

      /* Saturate: '<S185>/Saturation2' */
      if (Controller_B.mc_force_cmd[2] > 1.0F) {
        tmp_gf = 1.0F;
      } else if (Controller_B.mc_force_cmd[2] < 0.0F) {
        tmp_gf = 0.0F;
      } else {
        tmp_gf = Controller_B.mc_force_cmd[2];
      }

      /* End of Saturate: '<S185>/Saturation2' */

      /* DataTypeConversion: '<S190>/Data Type Conversion' incorporates:
       *  Constant: '<S190>/Constant1'
       *  Gain: '<S190>/Gain1'
       *  Sum: '<S190>/Sum1'
       */
      rtb_DataTypeConversion_o = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
        tmp_gf), 4.2949673E+9F) + 1000U);

      /* Saturate: '<S185>/Saturation1' */
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

      /* End of Saturate: '<S185>/Saturation1' */

      /* Saturate: '<S184>/Saturation4' */
      if (Controller_B.fw_force_cmd[0] > 1.0F) {
        tmp_gf = 1.0F;
      } else if (Controller_B.fw_force_cmd[0] < 0.0F) {
        tmp_gf = 0.0F;
      } else {
        tmp_gf = Controller_B.fw_force_cmd[0];
      }

      /* End of Saturate: '<S184>/Saturation4' */

      /* Saturate: '<S184>/Saturation1' incorporates:
       *  Constant: '<S189>/Constant1'
       *  DataTypeConversion: '<S189>/Data Type Conversion'
       *  Gain: '<S189>/Gain1'
       *  Sum: '<S189>/Sum1'
       */
      tmp_o[0] = (uint16_T)((uint32_T)fmodf(floorf(1000.0F * tmp_gf),
        4.2949673E+9F) + 1000U);

      /* DataTypeConversion: '<S184>/Data Type Conversion' incorporates:
       *  Bias: '<S184>/Bias1'
       */
      tmp_gf = fmodf(floorf(rtb_Multiply_ka[0] + CONTROL_PARAM.SERVO1_BIAS),
                     65536.0F);

      /* Saturate: '<S184>/Saturation1' incorporates:
       *  DataTypeConversion: '<S184>/Data Type Conversion'
       */
      tmp_o[1] = (uint16_T)(tmp_gf < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_gf : (int32_T)(uint16_T)tmp_gf);

      /* DataTypeConversion: '<S184>/Data Type Conversion1' incorporates:
       *  Bias: '<S184>/Bias2'
       */
      tmp_gf = fmodf(floorf(rtb_Multiply_ka[1] + CONTROL_PARAM.SERVO2_BIAS),
                     65536.0F);

      /* Saturate: '<S184>/Saturation1' incorporates:
       *  DataTypeConversion: '<S184>/Data Type Conversion1'
       */
      tmp_o[2] = (uint16_T)(tmp_gf < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_gf : (int32_T)(uint16_T)tmp_gf);

      /* DataTypeConversion: '<S184>/Data Type Conversion2' incorporates:
       *  Bias: '<S184>/Bias3'
       */
      tmp_gf = fmodf(floorf(rtb_Multiply_ka[2] + CONTROL_PARAM.SERVO3_BIAS),
                     65536.0F);

      /* Saturate: '<S184>/Saturation1' incorporates:
       *  DataTypeConversion: '<S184>/Data Type Conversion2'
       */
      tmp_o[3] = (uint16_T)(tmp_gf < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_gf : (int32_T)(uint16_T)tmp_gf);

      /* DataTypeConversion: '<S184>/Data Type Conversion3' incorporates:
       *  Bias: '<S184>/Bias4'
       */
      tmp_gf = fmodf(floorf(rtb_Multiply_ka[3] + CONTROL_PARAM.SERVO4_BIAS),
                     65536.0F);

      /* Saturate: '<S184>/Saturation1' incorporates:
       *  DataTypeConversion: '<S184>/Data Type Conversion3'
       */
      tmp_o[4] = (uint16_T)(tmp_gf < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_gf : (int32_T)(uint16_T)tmp_gf);

      /* Product: '<S185>/Multiply' */
      for (i_o = 0; i_o < 4; i_o++) {
        /* Saturate: '<S185>/Saturation' incorporates:
         *  Constant: '<S185>/Effective_Matrix'
         *  Gain: '<S185>/Gain'
         *  Sum: '<S185>/Add'
         */
        tmp_gf = fmodf(floorf(1000.0F *
                              (Controller_ConstP.Effective_Matrix_Value_c[i_o +
          8] * tmp_k + (Controller_ConstP.Effective_Matrix_Value_c[i_o + 4] *
                        tmp_ev + Controller_ConstP.Effective_Matrix_Value_c[i_o]
                        * tmp_m)) + (real32_T)rtb_DataTypeConversion_o),
                       65536.0F);
        u0_o = (uint16_T)(tmp_gf < 0.0F ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
                          -tmp_gf : (int32_T)(uint16_T)tmp_gf);
        if (u0_o > 1950) {
          rtb_VariantMergeForOutportactua[i_o] = 1950U;
        } else if (u0_o < 1050) {
          rtb_VariantMergeForOutportactua[i_o] = 1050U;
        } else {
          rtb_VariantMergeForOutportactua[i_o] = u0_o;
        }

        /* End of Saturate: '<S185>/Saturation' */
      }

      /* End of Product: '<S185>/Multiply' */
      for (i_o = 0; i_o < 5; i_o++) {
        /* Saturate: '<S184>/Saturation1' */
        if (tmp_o[i_o] > 1950) {
          rtb_VariantMergeForOutportactua[i_o + 4] = 1950U;
        } else if (tmp_o[i_o] < 1050) {
          rtb_VariantMergeForOutportactua[i_o + 4] = 1050U;
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

    /* End of MultiPortSwitch: '<S186>/Multiport Switch' */
  }

#endif

  /* End of Outputs for SubSystem: '<S6>/VTOL_Control_Allocation' */

  /* Outport: '<Root>/Control_Out' incorporates:
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   *  Reshape: '<S164>/Reshape'
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
  /* Start for Constant: '<S48>/Constant' */
  Controller_B.Constant_m = CONTROL_PARAM.MC_VEL_Z_I_MIN;

  /* End of Start for SubSystem: '<S2>/FW_Controller' */

  /* Start for IfAction SubSystem: '<S2>/MC_Controller' */
  /* Start for Constant: '<S161>/Constant' */
  Controller_B.Constant = CONTROL_PARAM.MC_VEL_Z_I_MIN;

  /* End of Start for SubSystem: '<S2>/MC_Controller' */

  /* SystemInitialize for IfAction SubSystem: '<S2>/FW_Controller' */
  /* InitializeConditions for DiscreteIntegrator: '<S56>/Discrete-Time Integrator5' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S100>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_n = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S95>/ ' */
  Controller_DW._DSTATE = Controller_ConstB.Zero1;
  if (Controller_DW._DSTATE >= CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
    Controller_DW._DSTATE = CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
  } else {
    if (Controller_DW._DSTATE <= -CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
      Controller_DW._DSTATE = -CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
    }
  }

  Controller_DW._PrevResetState = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S95>/ ' */

  /* InitializeConditions for DiscreteIntegrator: '<S96>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_f = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_b = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S24>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_b = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S28>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_h = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_l = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S98>/ ' */
  Controller_DW._DSTATE_d = Controller_ConstB.Zero;
  if (Controller_DW._DSTATE_d >= 1.0F) {
    Controller_DW._DSTATE_d = 1.0F;
  } else {
    if (Controller_DW._DSTATE_d <= 0.0F) {
      Controller_DW._DSTATE_d = 0.0F;
    }
  }

  Controller_DW._PrevResetState_e = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S98>/ ' */

  /* InitializeConditions for DiscreteIntegrator: '<S99>/Discrete-Time Integrator1' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S74>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_PrevR_ef = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S45>/Integrator' */
  Controller_DW.Integrator_DSTATE_f = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S74>/Discrete-Time Integrator' */
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
  /* InitializeConditions for DiscreteIntegrator: '<S118>/Discrete-Time Integrator' */
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
  /* InitializeConditions for DiscreteIntegrator: '<S74>/Discrete-Time Integrator' */
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
  /* InitializeConditions for DiscreteIntegrator: '<S118>/Discrete-Time Integrator' */
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
  /* InitializeConditions for DiscreteIntegrator: '<S74>/Discrete-Time Integrator' */
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
  /* InitializeConditions for DiscreteIntegrator: '<S118>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S145>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_PrevRe_p = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S147>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S116>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S120>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_k = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S140>/Integrator1' */
  Controller_DW.Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S145>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S140>/Integrator' */
  Controller_DW.Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S140>/Integrator1' */
  Controller_DW.Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S145>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S140>/Integrator' */
  Controller_DW.Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S158>/Integrator1' */
  Controller_DW.Integrator1_DSTATE_e = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S161>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S161>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S163>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 1U;
  Controller_DW.DiscreteTimeIntegrator1_Prev_ks = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S158>/Integrator' */
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
