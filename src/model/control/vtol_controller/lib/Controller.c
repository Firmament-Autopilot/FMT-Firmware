/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.615
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Aug 28 10:26:49 2025
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
struct_GUtUWj3sckzFQXBoUWuuj CONTROL_PARAM = {
  1.4F,
  0.2F,
  0.1F,
  0.5F,
  0.12F,
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
  0.523599F,
  0.12F,
  0.18F,
  0.6F,
  0.15F,
  0.15F,
  0.2F,
  0.006F,
  0.009F,
  0.02F,
  -0.3F,
  0.3F,
  -0.3F,
  0.3F,
  1.047F,
  0.785F,
  0.55F,
  1950U,
  1050U,
  0.5F,
  7.0F,
  7.0F,
  0.785398F,
  0.1F,
  0.12F,
  0.15F,
  0.1F,
  0.1F,
  0.2F,
  -0.4F,
  0.4F,
  1.57079601F,
  1.57079601F,
  0.785398185F,
  14.0F,
  0.2F,
  1.0F,
  1.0F,
  1.0F,
  0.0F,
  0.5F,
  0.1F,
  0.1F,
  0.12F,
  0.5F,
  0.2F,
  0.2F,
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
  0.2F,
  0.0F,
  0.0F,
  2000U,
  1000U,
  -1.0F,
  -1.0F,
  -1.0F,
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
                                        *   '<S152>/hover_throttle'
                                        *   '<S39>/hover_throttle'
                                        *   '<S67>/FF'
                                        *   '<S85>/P_control'
                                        *   '<S86>/P_control'
                                        *   '<S87>/Kv'
                                        *   '<S134>/Saturation'
                                        *   '<S167>/Bias1'
                                        *   '<S167>/Bias2'
                                        *   '<S167>/Bias3'
                                        *   '<S167>/Bias4'
                                        *   '<S167>/Saturation1'
                                        *   '<S168>/Constant'
                                        *   '<S168>/Constant1'
                                        *   '<S168>/Saturation'
                                        *   '<S183>/Bias1'
                                        *   '<S183>/Bias2'
                                        *   '<S183>/Bias3'
                                        *   '<S183>/Bias4'
                                        *   '<S19>/Saturation2'
                                        *   '<S19>/Saturation3'
                                        *   '<S19>/Saturation4'
                                        *   '<S71>/trim_speed'
                                        *   '<S72>/trim_speed'
                                        *   '<S76>/Saturation'
                                        *   '<S93>/Gain'
                                        *   '<S94>/ '
                                        *   '<S94>/Gain3'
                                        *   '<S96>/Gain'
                                        *   '<S97>/Gain'
                                        *   '<S110>/Saturation'
                                        *   '<S110>/Saturation1'
                                        *   '<S110>/Saturation2'
                                        *   '<S143>/kd'
                                        *   '<S143>/Saturation'
                                        *   '<S144>/ki'
                                        *   '<S144>/Discrete-Time Integrator'
                                        *   '<S145>/kp'
                                        *   '<S159>/kd'
                                        *   '<S159>/Saturation'
                                        *   '<S160>/Constant'
                                        *   '<S160>/ki'
                                        *   '<S160>/Discrete-Time Integrator'
                                        *   '<S161>/kp'
                                        *   '<S172>/Constant1'
                                        *   '<S172>/Constant12'
                                        *   '<S172>/Constant2'
                                        *   '<S172>/Constant7'
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
                                        *   '<S31>/Constant1'
                                        *   '<S31>/Constant2'
                                        *   '<S45>/kd'
                                        *   '<S45>/Saturation'
                                        *   '<S46>/Constant'
                                        *   '<S46>/ki'
                                        *   '<S46>/Discrete-Time Integrator'
                                        *   '<S47>/kp'
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
                                        *   '<S127>/Constant1'
                                        *   '<S127>/Constant2'
                                        *   '<S24>/gain1'
                                        *   '<S24>/gain2'
                                        *   '<S24>/gain3'
                                        *   '<S24>/Saturation'
                                        *   '<S25>/gain1'
                                        *   '<S25>/gain2'
                                        *   '<S25>/gain3'
                                        *   '<S25>/Discrete-Time Integrator'
                                        *   '<S26>/gain1'
                                        *   '<S26>/gain2'
                                        *   '<S26>/gain3'
                                        *   '<S116>/gain1'
                                        *   '<S116>/gain2'
                                        *   '<S116>/gain3'
                                        *   '<S116>/Saturation'
                                        *   '<S117>/gain1'
                                        *   '<S117>/gain2'
                                        *   '<S117>/gain3'
                                        *   '<S117>/Discrete-Time Integrator'
                                        *   '<S118>/gain1'
                                        *   '<S118>/gain2'
                                        *   '<S118>/gain3'
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
  real32_T rtb_phi_cmd_e;
  int32_T rtb_Relay;
  boolean_T rtb_aux_reset;
  real32_T rtb_Abs;
  real32_T rtb_Sum_l;
  real32_T rtb_DiscreteTimeIntegrator5_h5;
  real32_T rtb_VdotPg;
  real32_T rtb_Multiply1_e;
  real32_T rtb_Ldot_err;
  real32_T rtb_Gain_c4;
  real32_T rtb_Integrator1_m;
  boolean_T rtb_LogicalOperator_b3;
  real32_T rtb_Cos_j;
  real32_T rtb_Square_d;
  real32_T rtb_MatrixConcatenate1[9];
  real32_T rtb_Multiply_ni[3];
  real32_T rtb_Saturation_g;
  real32_T rtb_Sum1_g;
  int32_T i;
  real32_T rtb_MatrixConcatenate1_0[3];
  real32_T rtb_TmpSignalConversionAtMult_0;
  real32_T rtb_TmpSignalConversionAtMult_1;
  real32_T rtb_aux_att_error_B_rad_idx_0;
  real32_T rtb_aux_att_error_B_rad_idx_1;
  real32_T rtb_Add_gy_idx_0;
  real32_T rtb_Add_gy_idx_1;
  real32_T rtb_Add_gy_idx_2;
  real32_T rtb_Divide_m_idx_0;
  real32_T rtb_Divide_m_idx_1;
  real32_T rtb_Divide_m_idx_2;
  real32_T rtb_Switch2_idx_0;
  real32_T u0;
  uint32_T tmp;
  real32_T u0_tmp;
  real32_T rtb_Sum5_j0_tmp;
  real32_T rtb_Integrator1_o_tmp;

  /* S-Function (sfix_bitop): '<S7>/Bitwise AND' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  rtb_BitwiseAND_n = (uint8_T)(Controller_U.FMS_Out.ctrl_mode & 63);

  /* SwitchCase: '<S8>/Switch Case1' incorporates:
   *  Constant: '<S160>/Constant'
   *  Constant: '<S46>/Constant'
   *  DataTypeConversion: '<S8>/Data Type Conversion'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S116>/Multiply'
   *  Product: '<S129>/Divide1'
   *  Product: '<S143>/Multiply'
   *  Product: '<S33>/Divide1'
   *  Product: '<S8>/Divide'
   *  S-Function (sfix_bitop): '<S8>/Bitwise AND'
   *  Sum: '<S112>/Sum'
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
       *  DiscreteIntegrator: '<S23>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S25>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S27>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S43>/Integrator'
       *  DiscreteIntegrator: '<S43>/Integrator1'
       *  DiscreteIntegrator: '<S46>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S48>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S49>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S50>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S51>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S52>/Discrete-Time Integrator5'
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
      Controller_DW.DiscreteTimeIntegrator5_IC_LO_g = 1U;
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
      Controller_DW.DiscreteTimeIntegrator5_IC_LO_c = 1U;
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
    rtb_Integrator1_m = Controller_U.INS_Out.vd;

    /* Relay: '<S53>/Relay' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    if (Controller_U.INS_Out.airspeed >= 10.0F) {
      Controller_DW.Relay_Mode = true;
    } else {
      if (Controller_U.INS_Out.airspeed <= 6.0F) {
        Controller_DW.Relay_Mode = false;
      }
    }

    /* S-Function (sfix_bitop): '<S53>/vel_valid' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  S-Function (sfix_bitop): '<S88>/Bitwise AND'
     *  S-Function (sfix_bitop): '<S89>/Bitwise AND'
     *  S-Function (sfix_bitop): '<S90>/Bitwise AND'
     */
    tmp = Controller_U.INS_Out.flag & 16U;

    /* Switch: '<S53>/Switch' incorporates:
     *  Constant: '<S54>/Constant'
     *  Inport: '<Root>/INS_Out'
     *  Logic: '<S53>/Logical Operator'
     *  Logic: '<S53>/Logical Operator1'
     *  Math: '<S53>/Square2'
     *  Math: '<S53>/Square3'
     *  Product: '<S53>/Multiply'
     *  RelationalOperator: '<S54>/Compare'
     *  Relay: '<S53>/Relay'
     *  S-Function (sfix_bitop): '<S53>/airspeed_valid'
     *  S-Function (sfix_bitop): '<S53>/vel_valid'
     *  Sqrt: '<S53>/Sqrt'
     *  Sum: '<S53>/Add'
     */
    if ((Controller_DW.Relay_Mode && ((Controller_U.INS_Out.flag & 512U) != 0U))
        || (tmp == 0U)) {
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
      rtb_Square_d = Controller_U.INS_Out.quat[3] / rtb_Square_d;

      /* Math: '<S61>/Square' incorporates:
       *  Math: '<S59>/Square'
       *  Math: '<S60>/Square'
       */
      rtb_Ldot_err = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_0;

      /* Math: '<S61>/Square2' incorporates:
       *  Math: '<S59>/Square2'
       *  Math: '<S60>/Square2'
       */
      rtb_Gain_c4 = rtb_Divide_m_idx_2 * rtb_Divide_m_idx_2;

      /* Math: '<S61>/Square1' incorporates:
       *  Math: '<S59>/Square1'
       *  Math: '<S60>/Square1'
       */
      rtb_Sum1_g = rtb_Divide_m_idx_1 * rtb_Divide_m_idx_1;

      /* Math: '<S61>/Square3' incorporates:
       *  Math: '<S59>/Square3'
       *  Math: '<S60>/Square3'
       */
      rtb_Switch2_idx_0 = rtb_Square_d * rtb_Square_d;

      /* Sum: '<S61>/Subtract' incorporates:
       *  Math: '<S61>/Square'
       *  Math: '<S61>/Square1'
       *  Math: '<S61>/Square2'
       *  Math: '<S61>/Square3'
       *  Sum: '<S61>/Add'
       *  Sum: '<S61>/Add1'
       */
      rtb_MatrixConcatenate1[8] = (rtb_Ldot_err + rtb_Switch2_idx_0) -
        (rtb_Sum1_g + rtb_Gain_c4);

      /* Product: '<S61>/Multiply2' incorporates:
       *  Product: '<S60>/Multiply2'
       */
      rtb_Saturation_g = rtb_Divide_m_idx_2 * rtb_Square_d;

      /* Product: '<S61>/Multiply3' incorporates:
       *  Product: '<S60>/Multiply3'
       */
      rtb_phi_cmd_e = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_1;

      /* Gain: '<S61>/Gain1' incorporates:
       *  Product: '<S61>/Multiply2'
       *  Product: '<S61>/Multiply3'
       *  Sum: '<S61>/Add2'
       */
      rtb_MatrixConcatenate1[7] = (rtb_Saturation_g + rtb_phi_cmd_e) * 2.0F;

      /* Product: '<S61>/Multiply' incorporates:
       *  Product: '<S59>/Multiply2'
       */
      rtb_aux_att_error_B_rad_idx_0 = rtb_Divide_m_idx_1 * rtb_Square_d;

      /* Product: '<S61>/Multiply1' incorporates:
       *  Product: '<S59>/Multiply3'
       */
      rtb_aux_att_error_B_rad_idx_1 = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_2;

      /* Gain: '<S61>/Gain' incorporates:
       *  Product: '<S61>/Multiply'
       *  Product: '<S61>/Multiply1'
       *  Sum: '<S61>/Subtract2'
       */
      rtb_MatrixConcatenate1[6] = (rtb_aux_att_error_B_rad_idx_0 -
        rtb_aux_att_error_B_rad_idx_1) * 2.0F;

      /* Gain: '<S60>/Gain1' incorporates:
       *  Sum: '<S60>/Subtract1'
       */
      rtb_MatrixConcatenate1[5] = (rtb_Saturation_g - rtb_phi_cmd_e) * 2.0F;

      /* Sum: '<S60>/Subtract' incorporates:
       *  Sum: '<S60>/Add'
       *  Sum: '<S60>/Add1'
       */
      rtb_MatrixConcatenate1[4] = (rtb_Ldot_err + rtb_Gain_c4) - (rtb_Sum1_g +
        rtb_Switch2_idx_0);

      /* Product: '<S60>/Multiply' incorporates:
       *  Product: '<S59>/Multiply'
       */
      rtb_Saturation_g = rtb_Divide_m_idx_1 * rtb_Divide_m_idx_2;

      /* Product: '<S60>/Multiply1' incorporates:
       *  Product: '<S59>/Multiply1'
       */
      rtb_phi_cmd_e = rtb_Divide_m_idx_0 * rtb_Square_d;

      /* Gain: '<S60>/Gain' incorporates:
       *  Product: '<S60>/Multiply'
       *  Product: '<S60>/Multiply1'
       *  Sum: '<S60>/Add3'
       */
      rtb_MatrixConcatenate1[3] = (rtb_Saturation_g + rtb_phi_cmd_e) * 2.0F;

      /* Gain: '<S59>/Gain1' incorporates:
       *  Sum: '<S59>/Add2'
       */
      rtb_MatrixConcatenate1[2] = (rtb_aux_att_error_B_rad_idx_0 +
        rtb_aux_att_error_B_rad_idx_1) * 2.0F;

      /* Gain: '<S59>/Gain' incorporates:
       *  Sum: '<S59>/Subtract1'
       */
      rtb_MatrixConcatenate1[1] = (rtb_Saturation_g - rtb_phi_cmd_e) * 2.0F;

      /* Sum: '<S59>/Subtract' incorporates:
       *  Sum: '<S59>/Add'
       *  Sum: '<S59>/Add1'
       */
      rtb_MatrixConcatenate1[0] = (rtb_Ldot_err + rtb_Sum1_g) - (rtb_Gain_c4 +
        rtb_Switch2_idx_0);

      /* Product: '<S56>/Multiply' */
      for (i = 0; i < 3; i++) {
        rtb_MatrixConcatenate1_0[i] = rtb_MatrixConcatenate1[i + 6] *
          rtb_Integrator1_m + (rtb_MatrixConcatenate1[i + 3] *
          rtb_TmpSignalConversionAtMult_1 + rtb_MatrixConcatenate1[i] *
          rtb_TmpSignalConversionAtMult_0);
      }

      /* End of Product: '<S56>/Multiply' */

      /* Signum: '<S56>/Sign' */
      if (rtb_MatrixConcatenate1_0[0] < 0.0F) {
        rtb_Divide_m_idx_0 = -1.0F;
      } else if (rtb_MatrixConcatenate1_0[0] > 0.0F) {
        rtb_Divide_m_idx_0 = 1.0F;
      } else {
        rtb_Divide_m_idx_0 = rtb_MatrixConcatenate1_0[0];
      }

      /* End of Signum: '<S56>/Sign' */
      rtb_Divide_m_idx_0 *= sqrtf(Controller_U.INS_Out.vn *
        Controller_U.INS_Out.vn + Controller_U.INS_Out.ve *
        Controller_U.INS_Out.ve);
    }

    /* End of Switch: '<S53>/Switch' */

    /* Saturate: '<S53>/Saturation1' */
    if (rtb_Divide_m_idx_0 > 100.0F) {
      rtb_Divide_m_idx_0 = 100.0F;
    } else {
      if (rtb_Divide_m_idx_0 < 0.1F) {
        rtb_Divide_m_idx_0 = 0.1F;
      }
    }

    /* End of Saturate: '<S53>/Saturation1' */

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

    /* DiscreteIntegrator: '<S51>/Discrete-Time Integrator5' */
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

    /* DiscreteIntegrator: '<S49>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_g != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTA_jo = rtb_Divide_m_idx_2;
    }

    /* Relay: '<S10>/Relay' incorporates:
     *  DiscreteIntegrator: '<S49>/Discrete-Time Integrator5'
     */
    if (Controller_DW.DiscreteTimeIntegrator5_DSTA_jo >= 0.95F) {
      Controller_DW.Relay_Mode_m = true;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator5_DSTA_jo <= 0.8F) {
        Controller_DW.Relay_Mode_m = false;
      }
    }

    rtb_Relay = !Controller_DW.Relay_Mode_m;

    /* End of Relay: '<S10>/Relay' */

    /* Saturate: '<S10>/Saturation1' incorporates:
     *  Constant: '<S10>/Constant'
     *  DiscreteIntegrator: '<S49>/Discrete-Time Integrator5'
     *  Sum: '<S10>/Subtract'
     */
    if (1.0F - Controller_DW.DiscreteTimeIntegrator5_DSTA_jo > 1.0F) {
      rtb_Add_gy_idx_1 = 1.0F;
    } else if (1.0F - Controller_DW.DiscreteTimeIntegrator5_DSTA_jo < 0.0F) {
      rtb_Add_gy_idx_1 = 0.0F;
    } else {
      rtb_Add_gy_idx_1 = 1.0F - Controller_DW.DiscreteTimeIntegrator5_DSTA_jo;
    }

    /* End of Saturate: '<S10>/Saturation1' */

    /* Product: '<S10>/Multiply' */
    rtb_Square_d = (real32_T)rtb_Relay * rtb_Add_gy_idx_1;

    /* DiscreteIntegrator: '<S50>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_o != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTA_a2 = rtb_Square_d;
    }

    /* Relay: '<S18>/Relay' incorporates:
     *  DiscreteIntegrator: '<S50>/Discrete-Time Integrator5'
     */
    if (Controller_DW.DiscreteTimeIntegrator5_DSTA_a2 >= 0.2F) {
      Controller_DW.Relay_Mode_j = true;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator5_DSTA_a2 <= 0.1F) {
        Controller_DW.Relay_Mode_j = false;
      }
    }

    /* Logic: '<S18>/Logical Operator' incorporates:
     *  Relay: '<S18>/Relay'
     */
    rtb_aux_reset = ((Controller_U.FMS_Out.reset != 0) ||
                     (!Controller_DW.Relay_Mode_j));

    /* DiscreteIntegrator: '<S25>/Discrete-Time Integrator' */
    if (rtb_aux_reset || (Controller_DW.DiscreteTimeIntegrator_PrevRe_o != 0)) {
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
      rtb_phi_cmd_e = Controller_U.FMS_Out.phi_cmd;
    } else {
      /* Trigonometry: '<S64>/Atan' incorporates:
       *  Gain: '<S64>/g_force'
       */
      rtb_phi_cmd_e = atanf(0.101936802F * Controller_U.FMS_Out.ay_cmd);

      /* Saturate: '<S64>/Saturation' */
      if (rtb_phi_cmd_e > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_phi_cmd_e = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_phi_cmd_e < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
          rtb_phi_cmd_e = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
        }
      }

      /* End of Saturate: '<S64>/Saturation' */
    }

    /* End of Switch: '<S77>/Switch' */

    /* Abs: '<S65>/Abs' */
    rtb_Abs = fabsf(rtb_phi_cmd_e);

    /* Switch: '<S89>/Switch' incorporates:
     *  Constant: '<S89>/Constant'
     */
    if (tmp > 0U) {
      /* SignalConversion: '<S92>/ConcatBufferAtVector ConcatenateIn3' */
      rtb_MatrixConcatenate1[6] = Controller_ConstB.VectorConcatenate3_g[0];
      rtb_MatrixConcatenate1[7] = Controller_ConstB.VectorConcatenate3_g[1];
      rtb_MatrixConcatenate1[8] = Controller_ConstB.VectorConcatenate3_g[2];

      /* SignalConversion: '<S92>/ConcatBufferAtVector Concatenate2In3' incorporates:
       *  Constant: '<S92>/Constant4'
       */
      rtb_MatrixConcatenate1[5] = 0.0F;

      /* Trigonometry: '<S92>/Trigonometric Function3' incorporates:
       *  Gain: '<S91>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S92>/Trigonometric Function1'
       */
      rtb_Ldot_err = arm_cos_f32(-Controller_U.INS_Out.psi);
      rtb_MatrixConcatenate1[4] = rtb_Ldot_err;

      /* Trigonometry: '<S92>/Trigonometric Function2' incorporates:
       *  Gain: '<S91>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S92>/Trigonometric Function'
       */
      rtb_Gain_c4 = arm_sin_f32(-Controller_U.INS_Out.psi);

      /* Gain: '<S92>/Gain' incorporates:
       *  Trigonometry: '<S92>/Trigonometric Function2'
       */
      rtb_MatrixConcatenate1[3] = -rtb_Gain_c4;

      /* SignalConversion: '<S92>/ConcatBufferAtVector Concatenate1In3' incorporates:
       *  Constant: '<S92>/Constant3'
       */
      rtb_MatrixConcatenate1[2] = 0.0F;

      /* Trigonometry: '<S92>/Trigonometric Function' */
      rtb_MatrixConcatenate1[1] = rtb_Gain_c4;

      /* Trigonometry: '<S92>/Trigonometric Function1' */
      rtb_MatrixConcatenate1[0] = rtb_Ldot_err;

      /* Product: '<S89>/Multiply' */
      for (i = 0; i < 3; i++) {
        rtb_Multiply_ni[i] = rtb_MatrixConcatenate1[i + 6] * rtb_Integrator1_m +
          (rtb_MatrixConcatenate1[i + 3] * rtb_TmpSignalConversionAtMult_1 +
           rtb_MatrixConcatenate1[i] * rtb_TmpSignalConversionAtMult_0);
      }

      /* End of Product: '<S89>/Multiply' */

      /* DeadZone: '<S89>/Dead Zone' */
      if (rtb_Multiply_ni[0] > 1.0F) {
        rtb_Sum_l = rtb_Multiply_ni[0] - 1.0F;
      } else if (rtb_Multiply_ni[0] >= -1.0F) {
        rtb_Sum_l = 0.0F;
      } else {
        rtb_Sum_l = rtb_Multiply_ni[0] - -1.0F;
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
    } else {
      rtb_Sum_l = 1.0F;
    }

    /* End of Switch: '<S89>/Switch' */

    /* Switch: '<S88>/Switch' incorporates:
     *  Gain: '<S88>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S88>/Divide'
     *  Trigonometry: '<S88>/Asin'
     */
    if (tmp > 1U) {
      /* Sqrt: '<S88>/Sqrt' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Math: '<S88>/Square'
       *  Math: '<S88>/Square1'
       *  Sum: '<S88>/Add'
       */
      rtb_Sum1_g = sqrtf(Controller_U.INS_Out.vn * Controller_U.INS_Out.vn +
                         Controller_U.INS_Out.ve * Controller_U.INS_Out.ve);

      /* Saturate: '<S88>/Saturation' incorporates:
       *  Sqrt: '<S88>/Sqrt'
       */
      if (rtb_Sum1_g > 100.0F) {
        rtb_Sum1_g = 100.0F;
      } else {
        if (rtb_Sum1_g < 8.0F) {
          rtb_Sum1_g = 8.0F;
        }
      }

      /* End of Saturate: '<S88>/Saturation' */

      /* DeadZone: '<S88>/Dead Zone' incorporates:
       *  Inport: '<Root>/INS_Out'
       */
      if (Controller_U.INS_Out.vd > 0.1F) {
        rtb_Add_gy_idx_1 = Controller_U.INS_Out.vd - 0.1F;
      } else if (Controller_U.INS_Out.vd >= -0.1F) {
        rtb_Add_gy_idx_1 = 0.0F;
      } else {
        rtb_Add_gy_idx_1 = Controller_U.INS_Out.vd - -0.1F;
      }

      /* End of DeadZone: '<S88>/Dead Zone' */
      rtb_DiscreteTimeIntegrator5_h5 = atanf(1.0F / rtb_Sum1_g *
        -rtb_Add_gy_idx_1);
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

    /* Switch: '<S90>/Switch' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Math: '<S90>/Square'
     *  Math: '<S90>/Square1'
     *  Sqrt: '<S90>/Sqrt'
     *  Sum: '<S90>/Add'
     */
    if (tmp > 0U) {
      rtb_Multiply1_e = sqrtf(Controller_U.INS_Out.vn * Controller_U.INS_Out.vn
        + Controller_U.INS_Out.ve * Controller_U.INS_Out.ve);
    } else {
      rtb_Multiply1_e = Controller_U.INS_Out.airspeed;
    }

    /* End of Switch: '<S90>/Switch' */

    /* Saturate: '<S90>/Saturation1' */
    if (rtb_Multiply1_e > 100.0F) {
      rtb_Multiply1_e = 100.0F;
    } else {
      if (rtb_Multiply1_e < 8.0F) {
        rtb_Multiply1_e = 8.0F;
      }
    }

    /* End of Saturate: '<S90>/Saturation1' */

    /* Product: '<S90>/Multiply1' incorporates:
     *  Gain: '<S90>/Gain'
     *  Product: '<S90>/Divide'
     *  Trigonometry: '<S90>/Asin'
     */
    rtb_Sum_l *= atanf(-Controller_U.FMS_Out.w_cmd / rtb_Multiply1_e);

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
    rtb_Multiply1_e = (Controller_U.FMS_Out.u_cmd -
                       Controller_DW.DiscreteTimeIntegrator5_DSTAT_j) *
      CONTROL_PARAM.FW_TECS_VEL_P * 0.101936802F - rtb_VdotPg;

    /* Sum: '<S65>/Minus1' incorporates:
     *  Gain: '<S65>/ucmd2pitch'
     *  Gain: '<S65>/wcmd2pitch'
     */
    rtb_Ldot_err = CONTROL_PARAM.FW_TECS_W2P * rtb_Sum_l -
      CONTROL_PARAM.FW_TECS_U2P * rtb_Multiply1_e;

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
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_e = rtb_Ldot_err;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_b != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_e = rtb_Ldot_err;
    }

    /* Gain: '<S95>/Gain' incorporates:
     *  DiscreteIntegrator: '<S95>/Discrete-Time Integrator1'
     *  Sum: '<S95>/Sum5'
     */
    rtb_Gain_c4 = (rtb_Ldot_err - Controller_DW.DiscreteTimeIntegrator1_DSTAT_e)
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
      rtb_Cos_j = Controller_U.FMS_Out.theta_cmd;
    } else {
      if (Controller_U.FMS_Out.reset > 0) {
        /* Switch: '<S95>/Switch' incorporates:
         *  Gain: '<S95>/Gain1'
         */
        rtb_Add_gy_idx_1 = 0.0F;
      } else {
        /* Switch: '<S95>/Switch' */
        rtb_Add_gy_idx_1 = rtb_Gain_c4;
      }

      /* Gain: '<S93>/Gain' */
      rtb_TmpSignalConversionAtMult_0 = CONTROL_PARAM.FW_TECS_PITCH_D *
        rtb_Add_gy_idx_1;

      /* Saturate: '<S85>/Saturation1' */
      if (rtb_TmpSignalConversionAtMult_0 > 0.3F) {
        rtb_TmpSignalConversionAtMult_0 = 0.3F;
      } else {
        if (rtb_TmpSignalConversionAtMult_0 < -0.3F) {
          rtb_TmpSignalConversionAtMult_0 = -0.3F;
        }
      }

      /* End of Saturate: '<S85>/Saturation1' */
      rtb_Cos_j = (((2.0F - CONTROL_PARAM.FW_TECS_RATIO) *
                    rtb_DiscreteTimeIntegrator5_h5 - CONTROL_PARAM.FW_TECS_RATIO
                    * rtb_VdotPg) * CONTROL_PARAM.FW_TECS_PITCH_F +
                   ((CONTROL_PARAM.FW_TECS_PITCH_P * rtb_Ldot_err +
                     Controller_DW._DSTATE) + rtb_TmpSignalConversionAtMult_0))
        + CONTROL_PARAM.FW_TECS_R2P * rtb_Abs;
    }

    /* End of Switch: '<S77>/Switch1' */

    /* Sum: '<S30>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_aux_att_error_B_rad_idx_0 = rtb_phi_cmd_e - Controller_U.INS_Out.phi;
    rtb_aux_att_error_B_rad_idx_1 = rtb_Cos_j - Controller_U.INS_Out.theta;

    /* Product: '<S33>/Divide1' incorporates:
     *  Abs: '<S33>/Abs'
     *  Constant: '<S33>/const2'
     */
    rtb_TmpSignalConversionAtMult_1 = fabsf(rtb_aux_att_error_B_rad_idx_0) /
      0.002F;

    /* Product: '<S33>/Divide' incorporates:
     *  Constant: '<S31>/Constant1'
     *  Constant: '<S33>/const1'
     *  Math: '<S33>/Square'
     *  SignalConversion: '<S33>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_Integrator1_m = 9.5993F / (CONTROL_PARAM.MC_ROLL_P *
      CONTROL_PARAM.MC_ROLL_P);

    /* Signum: '<S33>/Sign' incorporates:
     *  Abs: '<S33>/Abs'
     */
    if (rtb_aux_att_error_B_rad_idx_0 < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else if (rtb_aux_att_error_B_rad_idx_0 > 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_0 = rtb_aux_att_error_B_rad_idx_0;
    }

    /* Switch: '<S33>/Switch' incorporates:
     *  Abs: '<S33>/Abs'
     *  Constant: '<S31>/Constant1'
     *  Gain: '<S33>/Gain1'
     *  Gain: '<S33>/Gain2'
     *  Logic: '<S33>/Logical Operator'
     *  Product: '<S33>/Divide'
     *  Product: '<S33>/Multiply'
     *  Product: '<S33>/Multiply1'
     *  Product: '<S33>/Multiply2'
     *  Product: '<S33>/Multiply3'
     *  RelationalOperator: '<S33>/Relational Operator'
     *  RelationalOperator: '<S33>/Relational Operator2'
     *  SignalConversion: '<S33>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S33>/Sqrt'
     *  Sum: '<S33>/Subtract'
     */
    if ((rtb_aux_att_error_B_rad_idx_0 <= rtb_Integrator1_m) &&
        (rtb_aux_att_error_B_rad_idx_0 >= -rtb_Integrator1_m)) {
      rtb_TmpSignalConversionAtMult_0 = rtb_aux_att_error_B_rad_idx_0 *
        CONTROL_PARAM.MC_ROLL_P;
    } else {
      rtb_TmpSignalConversionAtMult_0 *= sqrtf((rtb_TmpSignalConversionAtMult_0 *
        rtb_aux_att_error_B_rad_idx_0 - 0.5F * rtb_Integrator1_m) *
        Controller_ConstB.Gain_n);
    }

    /* Gain: '<S33>/Gain3' */
    rtb_Add_gy_idx_0 = -rtb_TmpSignalConversionAtMult_1;

    /* Switch: '<S34>/Switch' incorporates:
     *  Gain: '<S33>/Gain3'
     *  RelationalOperator: '<S34>/UpperRelop'
     */
    if (rtb_TmpSignalConversionAtMult_0 >= -rtb_TmpSignalConversionAtMult_1) {
      rtb_Add_gy_idx_0 = rtb_TmpSignalConversionAtMult_0;
    }

    /* Switch: '<S34>/Switch2' incorporates:
     *  RelationalOperator: '<S34>/LowerRelop1'
     */
    if (rtb_TmpSignalConversionAtMult_0 <= rtb_TmpSignalConversionAtMult_1) {
      rtb_TmpSignalConversionAtMult_1 = rtb_Add_gy_idx_0;
    }

    rtb_Switch2_idx_0 = rtb_TmpSignalConversionAtMult_1;

    /* Product: '<S33>/Divide1' incorporates:
     *  Abs: '<S33>/Abs'
     *  Constant: '<S33>/const2'
     */
    rtb_TmpSignalConversionAtMult_1 = fabsf(rtb_aux_att_error_B_rad_idx_1) /
      0.002F;

    /* Product: '<S33>/Divide' incorporates:
     *  Constant: '<S31>/Constant2'
     *  Constant: '<S33>/const1'
     *  Math: '<S33>/Square'
     *  SignalConversion: '<S33>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_Integrator1_m = 9.5993F / (CONTROL_PARAM.MC_PITCH_P *
      CONTROL_PARAM.MC_PITCH_P);

    /* Signum: '<S33>/Sign' incorporates:
     *  Abs: '<S33>/Abs'
     */
    if (rtb_aux_att_error_B_rad_idx_1 < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else if (rtb_aux_att_error_B_rad_idx_1 > 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_0 = rtb_aux_att_error_B_rad_idx_1;
    }

    /* Switch: '<S33>/Switch' incorporates:
     *  Abs: '<S33>/Abs'
     *  Constant: '<S31>/Constant2'
     *  Gain: '<S33>/Gain1'
     *  Gain: '<S33>/Gain2'
     *  Logic: '<S33>/Logical Operator'
     *  Product: '<S33>/Divide'
     *  Product: '<S33>/Multiply'
     *  Product: '<S33>/Multiply1'
     *  Product: '<S33>/Multiply2'
     *  Product: '<S33>/Multiply3'
     *  RelationalOperator: '<S33>/Relational Operator'
     *  RelationalOperator: '<S33>/Relational Operator2'
     *  SignalConversion: '<S33>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S33>/Sqrt'
     *  Sum: '<S33>/Subtract'
     */
    if ((rtb_aux_att_error_B_rad_idx_1 <= rtb_Integrator1_m) &&
        (rtb_aux_att_error_B_rad_idx_1 >= -rtb_Integrator1_m)) {
      rtb_TmpSignalConversionAtMult_0 = rtb_aux_att_error_B_rad_idx_1 *
        CONTROL_PARAM.MC_PITCH_P;
    } else {
      rtb_TmpSignalConversionAtMult_0 *= sqrtf((rtb_TmpSignalConversionAtMult_0 *
        rtb_aux_att_error_B_rad_idx_1 - 0.5F * rtb_Integrator1_m) *
        Controller_ConstB.Gain_n);
    }

    /* Gain: '<S33>/Gain3' */
    rtb_Add_gy_idx_0 = -rtb_TmpSignalConversionAtMult_1;

    /* Switch: '<S34>/Switch' incorporates:
     *  Gain: '<S33>/Gain3'
     *  RelationalOperator: '<S34>/UpperRelop'
     */
    if (rtb_TmpSignalConversionAtMult_0 >= -rtb_TmpSignalConversionAtMult_1) {
      rtb_Add_gy_idx_0 = rtb_TmpSignalConversionAtMult_0;
    }

    /* Switch: '<S34>/Switch2' incorporates:
     *  RelationalOperator: '<S34>/LowerRelop1'
     */
    if (rtb_TmpSignalConversionAtMult_0 <= rtb_TmpSignalConversionAtMult_1) {
      rtb_TmpSignalConversionAtMult_1 = rtb_Add_gy_idx_0;
    }

    /* Trigonometry: '<S28>/Sin' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S69>/Sin'
     */
    rtb_aux_att_error_B_rad_idx_1 = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S28>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S69>/Cos1'
     */
    rtb_Sum5_j0_tmp = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Trigonometry: '<S28>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S69>/Cos'
     */
    rtb_Integrator1_o_tmp = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Sum: '<S28>/Add1' incorporates:
     *  Product: '<S28>/Multiply1'
     *  Product: '<S28>/Multiply3'
     *  Trigonometry: '<S28>/Cos'
     *  Trigonometry: '<S28>/Cos1'
     *  Trigonometry: '<S28>/Sin'
     */
    rtb_Sum1_g = rtb_aux_att_error_B_rad_idx_1 * rtb_Sum5_j0_tmp *
      Controller_U.FMS_Out.psi_rate_cmd + rtb_Integrator1_o_tmp *
      rtb_TmpSignalConversionAtMult_1;

    /* Sum: '<S28>/Add2' incorporates:
     *  Product: '<S28>/Multiply4'
     *  Product: '<S28>/Multiply5'
     *  Trigonometry: '<S28>/Cos'
     *  Trigonometry: '<S28>/Cos1'
     *  Trigonometry: '<S28>/Sin'
     */
    rtb_Integrator1_m = rtb_Integrator1_o_tmp * rtb_Sum5_j0_tmp *
      Controller_U.FMS_Out.psi_rate_cmd - rtb_aux_att_error_B_rad_idx_1 *
      rtb_TmpSignalConversionAtMult_1;

    /* Saturate: '<S19>/Saturation2' */
    if (rtb_Integrator1_m > CONTROL_PARAM.MC_R_CMD_LIM) {
      rtb_Integrator1_m = CONTROL_PARAM.MC_R_CMD_LIM;
    } else {
      if (rtb_Integrator1_m < -CONTROL_PARAM.MC_R_CMD_LIM) {
        rtb_Integrator1_m = -CONTROL_PARAM.MC_R_CMD_LIM;
      }
    }

    /* End of Saturate: '<S19>/Saturation2' */

    /* Trigonometry: '<S28>/Sin1' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S69>/Sin1'
     */
    u0_tmp = arm_sin_f32(Controller_U.INS_Out.theta);

    /* Sum: '<S28>/Add' incorporates:
     *  Product: '<S28>/Multiply'
     *  Trigonometry: '<S28>/Sin1'
     */
    u0 = rtb_Switch2_idx_0 - u0_tmp * Controller_U.FMS_Out.psi_rate_cmd;

    /* Saturate: '<S19>/Saturation3' */
    if (u0 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      u0 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (u0 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        u0 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    /* End of Saturate: '<S19>/Saturation3' */

    /* Sum: '<S20>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_TmpSignalConversionAtMult_0 = u0 - Controller_U.INS_Out.p;

    /* Saturate: '<S20>/Saturation' */
    if (rtb_TmpSignalConversionAtMult_0 > 3.14159274F) {
      rtb_TmpSignalConversionAtMult_0 = 3.14159274F;
    } else {
      if (rtb_TmpSignalConversionAtMult_0 < -3.14159274F) {
        rtb_TmpSignalConversionAtMult_0 = -3.14159274F;
      }
    }

    /* Saturate: '<S19>/Saturation4' */
    if (rtb_Sum1_g > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_Sum1_g = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_Sum1_g < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_Sum1_g = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    /* End of Saturate: '<S19>/Saturation4' */

    /* Sum: '<S20>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_TmpSignalConversionAtMult_1 = rtb_Sum1_g - Controller_U.INS_Out.q;

    /* Saturate: '<S20>/Saturation' */
    if (rtb_TmpSignalConversionAtMult_1 > 3.14159274F) {
      rtb_TmpSignalConversionAtMult_1 = 3.14159274F;
    } else {
      if (rtb_TmpSignalConversionAtMult_1 < -3.14159274F) {
        rtb_TmpSignalConversionAtMult_1 = -3.14159274F;
      }
    }

    /* Sum: '<S20>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Integrator1_m -= Controller_U.INS_Out.r;

    /* Saturate: '<S20>/Saturation' */
    if (rtb_Integrator1_m > 3.14159274F) {
      rtb_Integrator1_m = 3.14159274F;
    } else {
      if (rtb_Integrator1_m < -3.14159274F) {
        rtb_Integrator1_m = -3.14159274F;
      }
    }

    /* DiscreteIntegrator: '<S23>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_b != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0] =
        rtb_TmpSignalConversionAtMult_0;
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1] =
        rtb_TmpSignalConversionAtMult_1;
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2] = rtb_Integrator1_m;
    }

    /* DiscreteIntegrator: '<S27>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S23>/Discrete-Time Integrator5'
     */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_h != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[0] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0];
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[1] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1];
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[2] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2];
    }

    if (rtb_aux_reset || (Controller_DW.DiscreteTimeIntegrator1_PrevR_l != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[0] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0];
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[1] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1];
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[2] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2];
    }

    /* Gain: '<S27>/Gain' incorporates:
     *  DiscreteIntegrator: '<S23>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S27>/Discrete-Time Integrator1'
     *  Sum: '<S27>/Sum5'
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

    /* RelationalOperator: '<S101>/Compare' incorporates:
     *  Constant: '<S101>/Constant'
     */
    rtb_Compare_nq = (rtb_BitwiseAND_n == 1);

    /* Switch: '<S12>/Switch' incorporates:
     *  Switch: '<S27>/Switch'
     */
    if (rtb_Compare_nq) {
      Controller_B.mc_torque_cmd[0] = 0.0F;
      Controller_B.mc_torque_cmd[1] = 0.0F;
      Controller_B.mc_torque_cmd[2] = 0.0F;
    } else {
      if (rtb_aux_reset) {
        /* Switch: '<S27>/Switch' incorporates:
         *  Gain: '<S27>/Gain1'
         */
        rtb_Add_gy_idx_0 = 0.0F;
        rtb_Add_gy_idx_1 = 0.0F;
        rtb_Add_gy_idx_2 = 0.0F;
      } else {
        /* Switch: '<S27>/Switch' */
        rtb_Add_gy_idx_0 = rtb_Multiply_ni[0];
        rtb_Add_gy_idx_1 = rtb_Multiply_ni[1];
        rtb_Add_gy_idx_2 = rtb_Multiply_ni[2];
      }

      /* Product: '<S24>/Multiply' incorporates:
       *  Constant: '<S24>/gain1'
       */
      rtb_Sum1_g = CONTROL_PARAM.MC_ROLL_RATE_D * rtb_Add_gy_idx_0;

      /* Saturate: '<S24>/Saturation' */
      if (rtb_Sum1_g > CONTROL_PARAM.MC_RATE_D_MAX) {
        rtb_Sum1_g = CONTROL_PARAM.MC_RATE_D_MAX;
      } else {
        if (rtb_Sum1_g < CONTROL_PARAM.MC_RATE_D_MIN) {
          rtb_Sum1_g = CONTROL_PARAM.MC_RATE_D_MIN;
        }
      }

      /* Sum: '<S21>/Add' incorporates:
       *  Constant: '<S26>/gain1'
       *  DiscreteIntegrator: '<S23>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S25>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S50>/Discrete-Time Integrator5'
       *  Product: '<S21>/Multiply'
       *  Product: '<S26>/Multiply'
       */
      rtb_Sum1_g += CONTROL_PARAM.MC_ROLL_RATE_P *
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0] *
        Controller_DW.DiscreteTimeIntegrator5_DSTA_a2 +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_d[0];

      /* Saturate: '<S9>/Saturation2' */
      if (rtb_Sum1_g > 1.0F) {
        Controller_B.mc_torque_cmd[0] = 1.0F;
      } else if (rtb_Sum1_g < -1.0F) {
        Controller_B.mc_torque_cmd[0] = -1.0F;
      } else {
        Controller_B.mc_torque_cmd[0] = rtb_Sum1_g;
      }

      /* Product: '<S24>/Multiply' incorporates:
       *  Constant: '<S24>/gain2'
       */
      rtb_Sum1_g = CONTROL_PARAM.MC_PITCH_RATE_D * rtb_Add_gy_idx_1;

      /* Saturate: '<S24>/Saturation' */
      if (rtb_Sum1_g > CONTROL_PARAM.MC_RATE_D_MAX) {
        rtb_Sum1_g = CONTROL_PARAM.MC_RATE_D_MAX;
      } else {
        if (rtb_Sum1_g < CONTROL_PARAM.MC_RATE_D_MIN) {
          rtb_Sum1_g = CONTROL_PARAM.MC_RATE_D_MIN;
        }
      }

      /* Sum: '<S21>/Add' incorporates:
       *  Constant: '<S26>/gain2'
       *  DiscreteIntegrator: '<S23>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S25>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S50>/Discrete-Time Integrator5'
       *  Product: '<S21>/Multiply'
       *  Product: '<S26>/Multiply'
       */
      rtb_Sum1_g += CONTROL_PARAM.MC_PITCH_RATE_P *
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1] *
        Controller_DW.DiscreteTimeIntegrator5_DSTA_a2 +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_d[1];

      /* Saturate: '<S9>/Saturation2' */
      if (rtb_Sum1_g > 1.0F) {
        Controller_B.mc_torque_cmd[1] = 1.0F;
      } else if (rtb_Sum1_g < -1.0F) {
        Controller_B.mc_torque_cmd[1] = -1.0F;
      } else {
        Controller_B.mc_torque_cmd[1] = rtb_Sum1_g;
      }

      /* Product: '<S24>/Multiply' incorporates:
       *  Constant: '<S24>/gain3'
       */
      rtb_Sum1_g = CONTROL_PARAM.MC_YAW_RATE_D * rtb_Add_gy_idx_2;

      /* Saturate: '<S24>/Saturation' */
      if (rtb_Sum1_g > CONTROL_PARAM.MC_RATE_D_MAX) {
        rtb_Sum1_g = CONTROL_PARAM.MC_RATE_D_MAX;
      } else {
        if (rtb_Sum1_g < CONTROL_PARAM.MC_RATE_D_MIN) {
          rtb_Sum1_g = CONTROL_PARAM.MC_RATE_D_MIN;
        }
      }

      /* Sum: '<S21>/Add' incorporates:
       *  Constant: '<S26>/gain3'
       *  DiscreteIntegrator: '<S23>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S25>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S50>/Discrete-Time Integrator5'
       *  Product: '<S21>/Multiply'
       *  Product: '<S26>/Multiply'
       */
      rtb_Sum1_g += CONTROL_PARAM.MC_YAW_RATE_P *
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2] *
        Controller_DW.DiscreteTimeIntegrator5_DSTA_a2 +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_d[2];

      /* Saturate: '<S9>/Saturation2' */
      if (rtb_Sum1_g > 1.0F) {
        Controller_B.mc_torque_cmd[2] = 1.0F;
      } else if (rtb_Sum1_g < -1.0F) {
        Controller_B.mc_torque_cmd[2] = -1.0F;
      } else {
        Controller_B.mc_torque_cmd[2] = rtb_Sum1_g;
      }
    }

    /* Sum: '<S65>/Add' incorporates:
     *  Gain: '<S65>/ucmd2thor'
     *  Gain: '<S65>/wcmd2thor'
     */
    rtb_Switch2_idx_0 = CONTROL_PARAM.FW_TECS_W2T * rtb_Sum_l +
      CONTROL_PARAM.FW_TECS_U2T * rtb_Multiply1_e;

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
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm = rtb_Switch2_idx_0;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_d != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm = rtb_Switch2_idx_0;
    }

    /* Gain: '<S98>/Gain' incorporates:
     *  DiscreteIntegrator: '<S98>/Discrete-Time Integrator1'
     *  Sum: '<S98>/Sum5'
     */
    rtb_aux_att_error_B_rad_idx_0 = (rtb_Switch2_idx_0 -
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm) * 188.49556F;

    /* Switch: '<S12>/Switch' incorporates:
     *  Constant: '<S100>/Constant'
     *  Constant: '<S102>/Constant2'
     *  Constant: '<S66>/Constant'
     *  RelationalOperator: '<S100>/Compare'
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
        rtb_Sum1_g = 0.000999987125F * (real32_T)
          Controller_U.FMS_Out.throttle_cmd + -1.0F;
      } else {
        if (Controller_U.FMS_Out.reset > 0) {
          /* Switch: '<S98>/Switch' incorporates:
           *  Gain: '<S98>/Gain1'
           *  Switch: '<S66>/Switch'
           */
          rtb_Add_gy_idx_1 = 0.0F;
        } else {
          /* Switch: '<S98>/Switch' incorporates:
           *  Switch: '<S66>/Switch'
           */
          rtb_Add_gy_idx_1 = rtb_aux_att_error_B_rad_idx_0;
        }

        /* Gain: '<S96>/Gain' incorporates:
         *  Switch: '<S66>/Switch'
         */
        rtb_Sum1_g = CONTROL_PARAM.FW_TECS_THOR_D * rtb_Add_gy_idx_1;

        /* Saturate: '<S86>/Saturation1' incorporates:
         *  Switch: '<S66>/Switch'
         */
        if (rtb_Sum1_g > 0.3F) {
          rtb_Sum1_g = 0.3F;
        } else {
          if (rtb_Sum1_g < -0.3F) {
            rtb_Sum1_g = -0.3F;
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
        rtb_Sum1_g = (((CONTROL_PARAM.FW_TECS_THOR_P * rtb_Switch2_idx_0 +
                        Controller_DW._DSTATE_d) + rtb_Sum1_g) +
                      (rtb_DiscreteTimeIntegrator5_h5 + rtb_VdotPg) *
                      CONTROL_PARAM.FW_TECS_THOR_FF) + CONTROL_PARAM.FW_TECS_R2T
          * rtb_Abs;

        /* Saturate: '<S66>/Saturation' incorporates:
         *  Switch: '<S66>/Switch'
         */
        if (rtb_Sum1_g > 1.0F) {
          rtb_Sum1_g = 1.0F;
        } else {
          if (rtb_Sum1_g < -1.0F) {
            rtb_Sum1_g = -1.0F;
          }
        }

        /* End of Saturate: '<S66>/Saturation' */
      }

      /* Saturate: '<S66>/Saturation2' incorporates:
       *  Switch: '<S66>/Switch'
       *  Switch: '<S98>/Switch'
       */
      if (rtb_Sum1_g > 1.0F) {
        Controller_B.fw_force_cmd[0] = 1.0F;
      } else {
        Controller_B.fw_force_cmd[0] = rtb_Sum1_g;
      }

      Controller_B.fw_force_cmd[1] = 0.0F;
      Controller_B.fw_force_cmd[2] = 0.0F;
    }

    /* Saturate: '<S10>/Saturation2' incorporates:
     *  Constant: '<S10>/Constant1'
     *  DiscreteIntegrator: '<S49>/Discrete-Time Integrator5'
     *  Sum: '<S10>/Subtract1'
     */
    if (1.5F - Controller_DW.DiscreteTimeIntegrator5_DSTA_jo > 1.0F) {
      rtb_Add_gy_idx_1 = 1.0F;
    } else if (1.5F - Controller_DW.DiscreteTimeIntegrator5_DSTA_jo < 0.0F) {
      rtb_Add_gy_idx_1 = 0.0F;
    } else {
      rtb_Add_gy_idx_1 = 1.5F - Controller_DW.DiscreteTimeIntegrator5_DSTA_jo;
    }

    /* End of Saturate: '<S10>/Saturation2' */

    /* Product: '<S10>/Multiply1' */
    rtb_Abs = (real32_T)rtb_Relay * rtb_Add_gy_idx_1;

    /* DiscreteIntegrator: '<S52>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_c != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_h = rtb_Abs;
    }

    /* Gain: '<S41>/Gain' incorporates:
     *  DiscreteIntegrator: '<S43>/Integrator1'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S41>/Sum1'
     */
    rtb_DiscreteTimeIntegrator5_h5 = -(Controller_DW.Integrator1_DSTATE_i -
      Controller_U.INS_Out.vd);

    /* Relay: '<S39>/Relay' incorporates:
     *  DiscreteIntegrator: '<S52>/Discrete-Time Integrator5'
     */
    if (Controller_DW.DiscreteTimeIntegrator5_DSTAT_h >= 0.2F) {
      Controller_DW.Relay_Mode_l = true;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator5_DSTAT_h <= 0.1F) {
        Controller_DW.Relay_Mode_l = false;
      }
    }

    /* Logic: '<S39>/Logical Operator' incorporates:
     *  Relay: '<S39>/Relay'
     */
    rtb_LogicalOperator_b3 = ((Controller_U.FMS_Out.reset != 0) ||
      (!Controller_DW.Relay_Mode_l));
    Controller_B.Constant_m = CONTROL_PARAM.MC_VEL_Z_I_MIN;

    /* DiscreteIntegrator: '<S46>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S46>/Constant'
     */
    if (rtb_LogicalOperator_b3 || (Controller_DW.DiscreteTimeIntegrator_PrevRe_e
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

    /* DiscreteIntegrator: '<S48>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_i != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_l =
        rtb_DiscreteTimeIntegrator5_h5;
    }

    if (rtb_LogicalOperator_b3 || (Controller_DW.DiscreteTimeIntegrator1_PrevR_h
         != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_l =
        rtb_DiscreteTimeIntegrator5_h5;
    }

    /* Gain: '<S48>/Gain' incorporates:
     *  DiscreteIntegrator: '<S48>/Discrete-Time Integrator1'
     *  Sum: '<S48>/Sum5'
     */
    rtb_VdotPg = (rtb_DiscreteTimeIntegrator5_h5 -
                  Controller_DW.DiscreteTimeIntegrator1_DSTAT_l) * 62.831852F;

    /* Switch: '<S12>/Switch' incorporates:
     *  Constant: '<S15>/Constant'
     *  Saturate: '<S9>/Saturation1'
     */
    if (rtb_Compare_nq) {
      Controller_B.mc_force_cmd[0] = 0.0F;
      Controller_B.mc_force_cmd[1] = 0.0F;
      Controller_B.mc_force_cmd[2] = 0.0F;
    } else {
      /* Product: '<S40>/Multiply' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S40>/Cos'
       *  Trigonometry: '<S40>/Cos1'
       */
      rtb_Add_gy_idx_1 = arm_cos_f32(Controller_U.INS_Out.phi) * arm_cos_f32
        (Controller_U.INS_Out.theta);

      /* Gain: '<S40>/Gain' */
      rtb_Sum1_g = 2.0F * rtb_Add_gy_idx_1;

      /* Saturate: '<S40>/Saturation1' */
      if (rtb_Add_gy_idx_1 > 1.0F) {
        rtb_Add_gy_idx_1 = 1.0F;
      } else {
        if (rtb_Add_gy_idx_1 < 0.5F) {
          rtb_Add_gy_idx_1 = 0.5F;
        }
      }

      /* End of Saturate: '<S40>/Saturation1' */

      /* Product: '<S40>/Divide' incorporates:
       *  Constant: '<S40>/Constant'
       */
      rtb_Add_gy_idx_0 = 1.0F / rtb_Add_gy_idx_1;

      /* Switch: '<S48>/Switch' incorporates:
       *  Gain: '<S48>/Gain1'
       */
      if (rtb_LogicalOperator_b3) {
        rtb_Add_gy_idx_1 = 0.0F;
      } else {
        rtb_Add_gy_idx_1 = rtb_VdotPg;
      }

      /* End of Switch: '<S48>/Switch' */

      /* Product: '<S45>/Multiply' incorporates:
       *  Constant: '<S45>/kd'
       */
      rtb_Add_gy_idx_1 *= CONTROL_PARAM.MC_VEL_Z_D;

      /* Saturate: '<S45>/Saturation' */
      if (rtb_Add_gy_idx_1 > CONTROL_PARAM.MC_VEL_Z_D_MAX) {
        rtb_Add_gy_idx_1 = CONTROL_PARAM.MC_VEL_Z_D_MAX;
      } else {
        if (rtb_Add_gy_idx_1 < CONTROL_PARAM.MC_VEL_Z_D_MIN) {
          rtb_Add_gy_idx_1 = CONTROL_PARAM.MC_VEL_Z_D_MIN;
        }
      }

      /* End of Saturate: '<S45>/Saturation' */

      /* Saturate: '<S40>/Saturation' */
      if (rtb_Sum1_g > 1.0F) {
        rtb_Sum1_g = 1.0F;
      } else {
        if (rtb_Sum1_g < 0.0F) {
          rtb_Sum1_g = 0.0F;
        }
      }

      /* End of Saturate: '<S40>/Saturation' */

      /* Product: '<S40>/Multiply1' incorporates:
       *  Constant: '<S47>/kp'
       *  DiscreteIntegrator: '<S46>/Discrete-Time Integrator'
       *  Product: '<S47>/Multiply'
       *  Sum: '<S42>/Add'
       */
      rtb_Sum1_g *= ((CONTROL_PARAM.MC_VEL_Z_P * rtb_DiscreteTimeIntegrator5_h5
                      + Controller_DW.DiscreteTimeIntegrator_DSTATE_b) +
                     rtb_Add_gy_idx_1) * rtb_Add_gy_idx_0;

      /* Saturate: '<S39>/Saturation' */
      if (rtb_Sum1_g > 0.35F) {
        rtb_Sum1_g = 0.35F;
      } else {
        if (rtb_Sum1_g < -0.35F) {
          rtb_Sum1_g = -0.35F;
        }
      }

      /* End of Saturate: '<S39>/Saturation' */
      Controller_B.mc_force_cmd[0] = 0.0F;
      Controller_B.mc_force_cmd[1] = 0.0F;

      /* Product: '<S39>/Multiply' incorporates:
       *  Constant: '<S15>/Constant'
       *  Constant: '<S39>/hover_throttle'
       *  DiscreteIntegrator: '<S52>/Discrete-Time Integrator5'
       *  Saturate: '<S9>/Saturation1'
       *  Sum: '<S39>/Sum1'
       */
      rtb_Sum1_g = (rtb_Sum1_g + CONTROL_PARAM.MC_HOVER_THRO) *
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_h;

      /* Saturate: '<S9>/Saturation1' */
      if (rtb_Sum1_g > 1.0F) {
        Controller_B.mc_force_cmd[2] = 1.0F;
      } else if (rtb_Sum1_g < -1.0F) {
        Controller_B.mc_force_cmd[2] = -1.0F;
      } else {
        Controller_B.mc_force_cmd[2] = rtb_Sum1_g;
      }
    }

    /* Bias: '<S78>/Pitch Offset' */
    rtb_Sum1_g = rtb_Cos_j + CONTROL_PARAM.FW_PITCH_OFFSET;

    /* Saturate: '<S78>/Saturation' */
    if (rtb_Sum1_g > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Sum1_g = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_Sum1_g < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_Sum1_g = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      }
    }

    /* Product: '<S79>/Multiply' incorporates:
     *  Constant: '<S79>/Constant2'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S78>/Sum'
     */
    rtb_Add_gy_idx_0 = (rtb_Sum1_g - Controller_U.INS_Out.theta) *
      CONTROL_PARAM.FW_PITCH_P;

    /* Product: '<S81>/Divide' incorporates:
     *  Constant: '<S81>/Constant'
     *  DiscreteIntegrator: '<S55>/Discrete-Time Integrator5'
     */
    rtb_Sum1_g = 9.81F / Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;

    /* Saturate: '<S81>/Saturation' */
    if (rtb_Sum1_g > 1.0F) {
      rtb_Sum1_g = 1.0F;
    } else {
      if (rtb_Sum1_g < 0.2F) {
        rtb_Sum1_g = 0.2F;
      }
    }

    /* End of Saturate: '<S81>/Saturation' */

    /* Sum: '<S76>/Sum' incorporates:
     *  Product: '<S81>/Multiply'
     *  Product: '<S81>/Multiply1'
     *  Trigonometry: '<S81>/Cos'
     *  Trigonometry: '<S81>/Tan'
     */
    rtb_Sum1_g = tanf(rtb_phi_cmd_e) * arm_cos_f32(rtb_Cos_j) * rtb_Sum1_g +
      Controller_U.FMS_Out.psi_rate_cmd;

    /* Saturate: '<S76>/Saturation' */
    if (rtb_Sum1_g > CONTROL_PARAM.FW_YAW_RATE_LIM) {
      rtb_Sum1_g = CONTROL_PARAM.FW_YAW_RATE_LIM;
    } else {
      if (rtb_Sum1_g < -CONTROL_PARAM.FW_YAW_RATE_LIM) {
        rtb_Sum1_g = -CONTROL_PARAM.FW_YAW_RATE_LIM;
      }
    }

    /* End of Saturate: '<S76>/Saturation' */

    /* Saturate: '<S78>/Saturation' */
    if (rtb_phi_cmd_e > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_phi_cmd_e = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_phi_cmd_e < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_phi_cmd_e = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      }
    }

    /* Sum: '<S69>/Add' incorporates:
     *  Constant: '<S79>/Constant1'
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S69>/Multiply'
     *  Product: '<S79>/Multiply'
     *  Sum: '<S78>/Sum'
     */
    rtb_Cos_j = (rtb_phi_cmd_e - Controller_U.INS_Out.phi) *
      CONTROL_PARAM.FW_ROLL_P - u0_tmp * rtb_Sum1_g;

    /* Sum: '<S69>/Add1' incorporates:
     *  Product: '<S69>/Multiply1'
     *  Product: '<S69>/Multiply3'
     */
    rtb_phi_cmd_e = rtb_aux_att_error_B_rad_idx_1 * rtb_Sum5_j0_tmp * rtb_Sum1_g
      + rtb_Integrator1_o_tmp * rtb_Add_gy_idx_0;

    /* Sum: '<S69>/Add2' incorporates:
     *  Product: '<S69>/Multiply4'
     *  Product: '<S69>/Multiply5'
     */
    rtb_aux_att_error_B_rad_idx_1 = rtb_Integrator1_o_tmp * rtb_Sum5_j0_tmp *
      rtb_Sum1_g - rtb_aux_att_error_B_rad_idx_1 * rtb_Add_gy_idx_0;

    /* Sum: '<S67>/Minus2' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Add_gy_idx_0 = rtb_Cos_j - Controller_U.INS_Out.p;
    rtb_Add_gy_idx_1 = rtb_phi_cmd_e - Controller_U.INS_Out.q;
    rtb_Add_gy_idx_2 = rtb_aux_att_error_B_rad_idx_1 - Controller_U.INS_Out.r;

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
      rtb_Sum1_g = (CONTROL_PARAM.FW_ROLL_RATE_P * rtb_Add_gy_idx_0 +
                    Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0]) *
        rtb_Saturation_g;
      u0 = (CONTROL_PARAM.FW_PITCH_RATE_P * rtb_Add_gy_idx_1 +
            Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1]) * rtb_Saturation_g;
      rtb_Sum5_j0_tmp = (CONTROL_PARAM.FW_YAW_RATE_P * rtb_Add_gy_idx_2 +
                         Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2]) *
        rtb_Saturation_g;

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
      rtb_Cos_j = CONTROL_PARAM.FW_FF * rtb_Cos_j * rtb_Saturation_g;

      /* Saturate: '<S67>/FF_limit' */
      if (rtb_Cos_j > 0.3F) {
        rtb_Cos_j = 0.3F;
      } else {
        if (rtb_Cos_j < -0.3F) {
          rtb_Cos_j = -0.3F;
        }
      }

      /* Saturate: '<S67>/PI_limit' */
      if (rtb_Sum1_g > 1.0F) {
        rtb_Sum1_g = 1.0F;
      } else {
        if (rtb_Sum1_g < -1.0F) {
          rtb_Sum1_g = -1.0F;
        }
      }

      /* Product: '<S11>/Multiply' incorporates:
       *  DiscreteIntegrator: '<S49>/Discrete-Time Integrator5'
       *  Sum: '<S67>/Add'
       */
      rtb_Sum1_g = (rtb_Cos_j + rtb_Sum1_g) *
        Controller_DW.DiscreteTimeIntegrator5_DSTA_jo;

      /* Saturate: '<S11>/Saturation1' */
      if (rtb_Sum1_g > 1.0F) {
        Controller_B.fw_torque_cmd[0] = 1.0F;
      } else if (rtb_Sum1_g < -1.0F) {
        Controller_B.fw_torque_cmd[0] = -1.0F;
      } else {
        Controller_B.fw_torque_cmd[0] = rtb_Sum1_g;
      }

      /* Product: '<S67>/Multiply1' incorporates:
       *  Gain: '<S67>/FF'
       */
      rtb_Sum1_g = CONTROL_PARAM.FW_FF * rtb_phi_cmd_e * rtb_Saturation_g;

      /* Saturate: '<S67>/FF_limit' */
      if (rtb_Sum1_g > 0.3F) {
        rtb_Sum1_g = 0.3F;
      } else {
        if (rtb_Sum1_g < -0.3F) {
          rtb_Sum1_g = -0.3F;
        }
      }

      /* Saturate: '<S67>/PI_limit' */
      if (u0 > 1.0F) {
        u0 = 1.0F;
      } else {
        if (u0 < -1.0F) {
          u0 = -1.0F;
        }
      }

      /* Product: '<S11>/Multiply' incorporates:
       *  DiscreteIntegrator: '<S49>/Discrete-Time Integrator5'
       *  Sum: '<S67>/Add'
       */
      rtb_Sum1_g = (rtb_Sum1_g + u0) *
        Controller_DW.DiscreteTimeIntegrator5_DSTA_jo;

      /* Saturate: '<S11>/Saturation1' */
      if (rtb_Sum1_g > 1.0F) {
        Controller_B.fw_torque_cmd[1] = 1.0F;
      } else if (rtb_Sum1_g < -1.0F) {
        Controller_B.fw_torque_cmd[1] = -1.0F;
      } else {
        Controller_B.fw_torque_cmd[1] = rtb_Sum1_g;
      }

      /* Product: '<S67>/Multiply1' incorporates:
       *  Gain: '<S67>/FF'
       */
      rtb_Sum1_g = CONTROL_PARAM.FW_FF * rtb_aux_att_error_B_rad_idx_1 *
        rtb_Saturation_g;

      /* Saturate: '<S67>/FF_limit' */
      if (rtb_Sum1_g > 0.3F) {
        rtb_Sum1_g = 0.3F;
      } else {
        if (rtb_Sum1_g < -0.3F) {
          rtb_Sum1_g = -0.3F;
        }
      }

      /* Saturate: '<S67>/PI_limit' */
      if (rtb_Sum5_j0_tmp > 1.0F) {
        rtb_Sum5_j0_tmp = 1.0F;
      } else {
        if (rtb_Sum5_j0_tmp < -1.0F) {
          rtb_Sum5_j0_tmp = -1.0F;
        }
      }

      /* Product: '<S11>/Multiply' incorporates:
       *  DiscreteIntegrator: '<S49>/Discrete-Time Integrator5'
       *  Sum: '<S67>/Add'
       */
      rtb_Sum1_g = (rtb_Sum1_g + rtb_Sum5_j0_tmp) *
        Controller_DW.DiscreteTimeIntegrator5_DSTA_jo;

      /* Saturate: '<S11>/Saturation1' */
      if (rtb_Sum1_g > 1.0F) {
        Controller_B.fw_torque_cmd[2] = 1.0F;
      } else if (rtb_Sum1_g < -1.0F) {
        Controller_B.fw_torque_cmd[2] = -1.0F;
      } else {
        Controller_B.fw_torque_cmd[2] = rtb_Sum1_g;
      }
    }

    /* Product: '<S44>/Multiply1' incorporates:
     *  Constant: '<S44>/const1'
     *  DiscreteIntegrator: '<S43>/Integrator'
     */
    rtb_Sum1_g = Controller_DW.Integrator_DSTATE_f * 0.05F;

    /* Sum: '<S44>/Add' incorporates:
     *  DiscreteIntegrator: '<S43>/Integrator1'
     *  Sum: '<S43>/Subtract'
     */
    rtb_phi_cmd_e = (Controller_DW.Integrator1_DSTATE_i -
                     Controller_U.FMS_Out.w_cmd) + rtb_Sum1_g;

    /* Signum: '<S44>/Sign' */
    if (rtb_phi_cmd_e < 0.0F) {
      rtb_Saturation_g = -1.0F;
    } else if (rtb_phi_cmd_e > 0.0F) {
      rtb_Saturation_g = 1.0F;
    } else {
      rtb_Saturation_g = rtb_phi_cmd_e;
    }

    /* End of Signum: '<S44>/Sign' */

    /* Sum: '<S44>/Add2' incorporates:
     *  Abs: '<S44>/Abs'
     *  Gain: '<S44>/Gain'
     *  Gain: '<S44>/Gain1'
     *  Product: '<S44>/Multiply2'
     *  Product: '<S44>/Multiply3'
     *  Sqrt: '<S44>/Sqrt'
     *  Sum: '<S44>/Add1'
     *  Sum: '<S44>/Subtract'
     */
    rtb_Saturation_g = (sqrtf((8.0F * fabsf(rtb_phi_cmd_e) +
      Controller_ConstB.d_m) * Controller_ConstB.d_m) - Controller_ConstB.d_m) *
      0.5F * rtb_Saturation_g + rtb_Sum1_g;

    /* Sum: '<S44>/Add4' */
    rtb_aux_att_error_B_rad_idx_1 = (rtb_phi_cmd_e - rtb_Saturation_g) +
      rtb_Sum1_g;

    /* Sum: '<S44>/Add3' */
    rtb_Sum1_g = rtb_phi_cmd_e + Controller_ConstB.d_m;

    /* Sum: '<S44>/Subtract1' */
    rtb_phi_cmd_e -= Controller_ConstB.d_m;

    /* Signum: '<S44>/Sign1' */
    if (rtb_Sum1_g < 0.0F) {
      rtb_Sum1_g = -1.0F;
    } else {
      if (rtb_Sum1_g > 0.0F) {
        rtb_Sum1_g = 1.0F;
      }
    }

    /* End of Signum: '<S44>/Sign1' */

    /* Signum: '<S44>/Sign2' */
    if (rtb_phi_cmd_e < 0.0F) {
      rtb_phi_cmd_e = -1.0F;
    } else {
      if (rtb_phi_cmd_e > 0.0F) {
        rtb_phi_cmd_e = 1.0F;
      }
    }

    /* End of Signum: '<S44>/Sign2' */

    /* Sum: '<S44>/Add5' incorporates:
     *  Gain: '<S44>/Gain2'
     *  Product: '<S44>/Multiply4'
     *  Sum: '<S44>/Subtract2'
     */
    rtb_Saturation_g += (rtb_Sum1_g - rtb_phi_cmd_e) * 0.5F *
      rtb_aux_att_error_B_rad_idx_1;

    /* Update for DiscreteIntegrator: '<S55>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S55>/Gain'
     *  Sum: '<S55>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_e = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_j += (rtb_Divide_m_idx_0 -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j) * 125.663704F * 0.002F;

    /* Update for DiscreteIntegrator: '<S51>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S51>/Gain'
     *  Sum: '<S51>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_L_eo = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_a += (rtb_Divide_m_idx_1 -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_a) * 31.415926F * 0.002F;

    /* Update for DiscreteIntegrator: '<S49>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S49>/Gain'
     *  Sum: '<S49>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_g = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTA_jo += (rtb_Divide_m_idx_2 -
      Controller_DW.DiscreteTimeIntegrator5_DSTA_jo) * 12.566371F * 0.002F;

    /* Update for DiscreteIntegrator: '<S50>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S50>/Gain'
     *  Sum: '<S50>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_o = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTA_a2 += (rtb_Square_d -
      Controller_DW.DiscreteTimeIntegrator5_DSTA_a2) * 6.28318548F * 0.002F;

    /* Update for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S25>/gain1'
     *  Constant: '<S25>/gain2'
     *  Constant: '<S25>/gain3'
     *  DiscreteIntegrator: '<S23>/Discrete-Time Integrator5'
     *  Product: '<S25>/Multiply'
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

    Controller_DW.DiscreteTimeIntegrator_PrevRe_o = (int8_T)rtb_aux_reset;

    /* End of Update for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' */

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

    /* End of Update for DiscreteIntegrator: '<S94>/ ' */

    /* Update for DiscreteIntegrator: '<S95>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_f = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_e += 0.002F * rtb_Gain_c4;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_b = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S23>/Discrete-Time Integrator5' */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_b = 0U;

    /* Update for DiscreteIntegrator: '<S27>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_h = 0U;

    /* Update for DiscreteIntegrator: '<S23>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S23>/Gain'
     *  Sum: '<S23>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0] +=
      (rtb_TmpSignalConversionAtMult_0 -
       Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S27>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[0] += 0.002F *
      rtb_Multiply_ni[0];

    /* Update for DiscreteIntegrator: '<S23>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S23>/Gain'
     *  Sum: '<S23>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1] +=
      (rtb_TmpSignalConversionAtMult_1 -
       Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S27>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[1] += 0.002F *
      rtb_Multiply_ni[1];

    /* Update for DiscreteIntegrator: '<S23>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S23>/Gain'
     *  Sum: '<S23>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2] += (rtb_Integrator1_m -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S27>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[2] += 0.002F *
      rtb_Multiply_ni[2];
    Controller_DW.DiscreteTimeIntegrator1_PrevR_l = (int8_T)rtb_aux_reset;

    /* Update for DiscreteIntegrator: '<S97>/ ' incorporates:
     *  Gain: '<S97>/Gain'
     */
    Controller_DW._DSTATE_d += CONTROL_PARAM.FW_TECS_THOR_I * rtb_Switch2_idx_0 *
      0.002F;
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

    /* Update for DiscreteIntegrator: '<S52>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S52>/Gain'
     *  Sum: '<S52>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_c = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_h += (rtb_Abs -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_h) * 3.14159274F * 0.002F;

    /* Update for DiscreteIntegrator: '<S43>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S43>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_i += 0.002F *
      Controller_DW.Integrator_DSTATE_f;

    /* Update for DiscreteIntegrator: '<S46>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S46>/ki'
     *  Product: '<S46>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_b += CONTROL_PARAM.MC_VEL_Z_I *
      rtb_DiscreteTimeIntegrator5_h5 * 0.002F;
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
      rtb_LogicalOperator_b3;

    /* End of Update for DiscreteIntegrator: '<S46>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S48>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_i = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_l += 0.002F * rtb_VdotPg;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_h = (int8_T)
      rtb_LogicalOperator_b3;

    /* Update for DiscreteIntegrator: '<S73>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S73>/gain1'
     *  Constant: '<S73>/gain2'
     *  Constant: '<S73>/gain3'
     *  Product: '<S73>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0] +=
      CONTROL_PARAM.FW_ROLL_RATE_I * rtb_Add_gy_idx_0 * 0.002F;
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
      CONTROL_PARAM.FW_PITCH_RATE_I * rtb_Add_gy_idx_1 * 0.002F;
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
      CONTROL_PARAM.FW_YAW_RATE_I * rtb_Add_gy_idx_2 * 0.002F;
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

    /* Signum: '<S44>/Sign6' incorporates:
     *  Signum: '<S44>/Sign5'
     */
    if (rtb_Saturation_g < 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = -1.0F;

      /* Signum: '<S44>/Sign5' */
      rtb_Integrator1_m = -1.0F;
    } else if (rtb_Saturation_g > 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = 1.0F;

      /* Signum: '<S44>/Sign5' */
      rtb_Integrator1_m = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_1 = rtb_Saturation_g;

      /* Signum: '<S44>/Sign5' */
      rtb_Integrator1_m = rtb_Saturation_g;
    }

    /* End of Signum: '<S44>/Sign6' */

    /* Sum: '<S44>/Add6' */
    rtb_Sum1_g = rtb_Saturation_g + Controller_ConstB.d_m;

    /* Sum: '<S44>/Subtract3' */
    rtb_TmpSignalConversionAtMult_0 = rtb_Saturation_g - Controller_ConstB.d_m;

    /* Signum: '<S44>/Sign3' */
    if (rtb_Sum1_g < 0.0F) {
      rtb_Sum1_g = -1.0F;
    } else {
      if (rtb_Sum1_g > 0.0F) {
        rtb_Sum1_g = 1.0F;
      }
    }

    /* End of Signum: '<S44>/Sign3' */

    /* Signum: '<S44>/Sign4' */
    if (rtb_TmpSignalConversionAtMult_0 < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else {
      if (rtb_TmpSignalConversionAtMult_0 > 0.0F) {
        rtb_TmpSignalConversionAtMult_0 = 1.0F;
      }
    }

    /* End of Signum: '<S44>/Sign4' */

    /* Update for DiscreteIntegrator: '<S43>/Integrator' incorporates:
     *  Constant: '<S44>/const'
     *  Gain: '<S44>/Gain3'
     *  Product: '<S44>/Divide'
     *  Product: '<S44>/Multiply5'
     *  Product: '<S44>/Multiply6'
     *  Sum: '<S44>/Subtract4'
     *  Sum: '<S44>/Subtract5'
     *  Sum: '<S44>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE_f += ((rtb_Saturation_g /
      Controller_ConstB.d_m - rtb_Integrator1_m) * Controller_ConstB.Gain4_o *
      ((rtb_Sum1_g - rtb_TmpSignalConversionAtMult_0) * 0.5F) -
      rtb_TmpSignalConversionAtMult_1 * 78.448F) * 0.002F;

    /* End of Outputs for SubSystem: '<S2>/FW_Controller' */
    break;

   case 1:
    if (Controller_DW.SwitchCase1_ActiveSubsystem != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S2>/MC_Controller' incorporates:
       *  ActionPort: '<S5>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S8>/Switch Case1' incorporates:
       *  DiscreteIntegrator: '<S115>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S117>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S119>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S139>/Integrator'
       *  DiscreteIntegrator: '<S139>/Integrator1'
       *  DiscreteIntegrator: '<S144>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S146>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S157>/Integrator'
       *  DiscreteIntegrator: '<S157>/Integrator1'
       *  DiscreteIntegrator: '<S160>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S162>/Discrete-Time Integrator1'
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

    /* DiscreteIntegrator: '<S117>/Discrete-Time Integrator' */
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

    /* Trigonometry: '<S141>/Trigonometric Function1' incorporates:
     *  Gain: '<S140>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1[0] = arm_cos_f32(-Controller_U.INS_Out.psi);

    /* Trigonometry: '<S141>/Trigonometric Function' incorporates:
     *  Gain: '<S140>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1[1] = arm_sin_f32(-Controller_U.INS_Out.psi);

    /* SignalConversion: '<S141>/ConcatBufferAtVector Concatenate1In3' incorporates:
     *  Constant: '<S141>/Constant3'
     */
    rtb_MatrixConcatenate1[2] = 0.0F;

    /* Gain: '<S141>/Gain' incorporates:
     *  Gain: '<S140>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S141>/Trigonometric Function2'
     */
    rtb_MatrixConcatenate1[3] = -arm_sin_f32(-Controller_U.INS_Out.psi);

    /* Trigonometry: '<S141>/Trigonometric Function3' incorporates:
     *  Gain: '<S140>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1[4] = arm_cos_f32(-Controller_U.INS_Out.psi);

    /* SignalConversion: '<S141>/ConcatBufferAtVector Concatenate2In3' incorporates:
     *  Constant: '<S141>/Constant4'
     */
    rtb_MatrixConcatenate1[5] = 0.0F;

    /* SignalConversion: '<S141>/ConcatBufferAtVector ConcatenateIn3' */
    rtb_MatrixConcatenate1[6] = Controller_ConstB.VectorConcatenate3[0];
    rtb_MatrixConcatenate1[7] = Controller_ConstB.VectorConcatenate3[1];
    rtb_MatrixConcatenate1[8] = Controller_ConstB.VectorConcatenate3[2];

    /* Product: '<S138>/Multiply' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  SignalConversion: '<S138>/TmpSignal ConversionAtMultiplyInport2'
     */
    for (i = 0; i < 3; i++) {
      rtb_MatrixConcatenate1_0[i] = rtb_MatrixConcatenate1[i + 3] *
        Controller_U.INS_Out.ve + rtb_MatrixConcatenate1[i] *
        Controller_U.INS_Out.vn;
    }

    /* End of Product: '<S138>/Multiply' */

    /* Sum: '<S135>/Sum' incorporates:
     *  DiscreteIntegrator: '<S139>/Integrator1'
     */
    rtb_aux_att_error_B_rad_idx_0 = Controller_DW.Integrator1_DSTATE[0] -
      rtb_MatrixConcatenate1_0[0];
    rtb_aux_att_error_B_rad_idx_1 = Controller_DW.Integrator1_DSTATE[1] -
      rtb_MatrixConcatenate1_0[1];

    /* DiscreteIntegrator: '<S144>/Discrete-Time Integrator' */
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

    /* DiscreteIntegrator: '<S146>/Discrete-Time Integrator1' */
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

    /* Gain: '<S146>/Gain' incorporates:
     *  DiscreteIntegrator: '<S146>/Discrete-Time Integrator1'
     *  Sum: '<S146>/Sum5'
     */
    rtb_Switch2_idx_0 = (rtb_aux_att_error_B_rad_idx_0 -
                         Controller_DW.DiscreteTimeIntegrator1_DSTATE[0]) *
      62.831852F;
    rtb_Divide_m_idx_0 = (rtb_aux_att_error_B_rad_idx_1 -
                          Controller_DW.DiscreteTimeIntegrator1_DSTATE[1]) *
      62.831852F;

    /* Switch: '<S146>/Switch' incorporates:
     *  Gain: '<S146>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_Divide_m_idx_2 = 0.0F;
      rtb_Integrator1_m = 0.0F;
    } else {
      rtb_Divide_m_idx_2 = rtb_Switch2_idx_0;
      rtb_Integrator1_m = rtb_Divide_m_idx_0;
    }

    /* End of Switch: '<S146>/Switch' */

    /* Product: '<S143>/Multiply' incorporates:
     *  Constant: '<S143>/kd'
     */
    rtb_Square_d = CONTROL_PARAM.MC_VEL_XY_D * rtb_Divide_m_idx_2;

    /* Saturate: '<S143>/Saturation' */
    if (rtb_Square_d > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
      rtb_Square_d = CONTROL_PARAM.MC_VEL_XY_D_MAX;
    } else {
      if (rtb_Square_d < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
        rtb_Square_d = CONTROL_PARAM.MC_VEL_XY_D_MIN;
      }
    }

    rtb_Divide_m_idx_2 = rtb_Square_d;

    /* Product: '<S143>/Multiply' incorporates:
     *  Constant: '<S143>/kd'
     */
    rtb_Square_d = CONTROL_PARAM.MC_VEL_XY_D * rtb_Integrator1_m;

    /* Saturate: '<S143>/Saturation' */
    if (rtb_Square_d > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
      rtb_Square_d = CONTROL_PARAM.MC_VEL_XY_D_MAX;
    } else {
      if (rtb_Square_d < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
        rtb_Square_d = CONTROL_PARAM.MC_VEL_XY_D_MIN;
      }
    }

    /* Switch: '<S137>/Switch' incorporates:
     *  Constant: '<S145>/kp'
     *  Constant: '<S147>/Constant'
     *  Constant: '<S149>/Constant'
     *  Constant: '<S150>/Constant'
     *  DiscreteIntegrator: '<S144>/Discrete-Time Integrator'
     *  Product: '<S145>/Multiply'
     *  Product: '<S148>/Multiply2'
     *  Product: '<S148>/Multiply3'
     *  RelationalOperator: '<S147>/Compare'
     *  RelationalOperator: '<S149>/Compare'
     *  RelationalOperator: '<S150>/Compare'
     *  S-Function (sfix_bitop): '<S148>/cmd_ax valid'
     *  S-Function (sfix_bitop): '<S148>/cmd_ay valid'
     *  S-Function (sfix_bitop): '<S148>/cmd_u valid'
     *  S-Function (sfix_bitop): '<S148>/cmd_v valid'
     *  Sum: '<S136>/Add'
     *  Sum: '<S148>/Sum1'
     */
    if (rtb_BitwiseAND_n == 6) {
      rtb_Divide_m_idx_2 = ((Controller_U.FMS_Out.cmd_mask & 64) > 0 ?
                            (CONTROL_PARAM.MC_VEL_XY_P *
        rtb_aux_att_error_B_rad_idx_0 +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0]) + rtb_Divide_m_idx_2 :
                            0.0F) + ((Controller_U.FMS_Out.cmd_mask & 512) > 0 ?
        Controller_U.FMS_Out.ax_cmd : 0.0F);
      rtb_Integrator1_m = ((Controller_U.FMS_Out.cmd_mask & 128) > 0 ?
                           (CONTROL_PARAM.MC_VEL_XY_P *
                            rtb_aux_att_error_B_rad_idx_1 +
                            Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1]) +
                           rtb_Square_d : 0.0F) +
        ((Controller_U.FMS_Out.cmd_mask & 1024) > 0 ?
         Controller_U.FMS_Out.ay_cmd : 0.0F);
    } else {
      rtb_Divide_m_idx_2 += CONTROL_PARAM.MC_VEL_XY_P *
        rtb_aux_att_error_B_rad_idx_0 +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0];
      rtb_Integrator1_m = (CONTROL_PARAM.MC_VEL_XY_P *
                           rtb_aux_att_error_B_rad_idx_1 +
                           Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1]) +
        rtb_Square_d;
    }

    /* End of Switch: '<S137>/Switch' */

    /* Trigonometry: '<S134>/Atan' incorporates:
     *  Constant: '<S134>/g'
     *  Gain: '<S134>/Gain1'
     *  Gain: '<S134>/gain'
     *  Product: '<S134>/Divide'
     */
    rtb_Sum1_g = atanf(1.1F * rtb_Integrator1_m / 9.8055F);
    rtb_Integrator1_m = atanf(1.1F * -rtb_Divide_m_idx_2 / 9.8055F);

    /* Switch: '<S125>/Switch' incorporates:
     *  Constant: '<S132>/Constant'
     *  Logic: '<S125>/Logical Operator'
     *  RelationalOperator: '<S131>/Compare'
     *  RelationalOperator: '<S132>/Compare'
     *  Saturate: '<S134>/Saturation'
     *  Switch: '<S125>/Switch1'
     */
    if ((rtb_BitwiseAND_n == 3) || (rtb_BitwiseAND_n == 4)) {
      rtb_Divide_m_idx_2 = Controller_U.FMS_Out.phi_cmd;
      rtb_Integrator1_m = Controller_U.FMS_Out.theta_cmd;
    } else if (rtb_BitwiseAND_n == 6) {
      /* Switch: '<S133>/Switch' incorporates:
       *  S-Function (sfix_bitop): '<S133>/cmd_phi valid'
       *  S-Function (sfix_bitop): '<S133>/cmd_theta valid'
       *  Saturate: '<S134>/Saturation'
       *  Switch: '<S125>/Switch1'
       */
      if ((Controller_U.FMS_Out.cmd_mask & 8) > 0) {
        rtb_Divide_m_idx_2 = Controller_U.FMS_Out.phi_cmd;
      } else if (rtb_Sum1_g > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S134>/Saturation' */
        rtb_Divide_m_idx_2 = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else if (rtb_Sum1_g < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S134>/Saturation' */
        rtb_Divide_m_idx_2 = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        rtb_Divide_m_idx_2 = rtb_Sum1_g;
      }

      if ((Controller_U.FMS_Out.cmd_mask & 16) > 0) {
        rtb_Integrator1_m = Controller_U.FMS_Out.theta_cmd;
      } else if (rtb_Integrator1_m > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S134>/Saturation' */
        rtb_Integrator1_m = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_Integrator1_m < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Saturate: '<S134>/Saturation' */
          rtb_Integrator1_m = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        }
      }

      /* End of Switch: '<S133>/Switch' */
    } else {
      if (rtb_Sum1_g > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S134>/Saturation' incorporates:
         *  Switch: '<S125>/Switch1'
         */
        rtb_Divide_m_idx_2 = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else if (rtb_Sum1_g < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S134>/Saturation' incorporates:
         *  Switch: '<S125>/Switch1'
         */
        rtb_Divide_m_idx_2 = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        /* Switch: '<S125>/Switch1' incorporates:
         *  Saturate: '<S134>/Saturation'
         */
        rtb_Divide_m_idx_2 = rtb_Sum1_g;
      }

      /* Saturate: '<S134>/Saturation' */
      if (rtb_Integrator1_m > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Switch: '<S125>/Switch1' */
        rtb_Integrator1_m = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_Integrator1_m < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Switch: '<S125>/Switch1' */
          rtb_Integrator1_m = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        }
      }
    }

    /* End of Switch: '<S125>/Switch' */

    /* Sum: '<S126>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Square_d = rtb_Divide_m_idx_2 - Controller_U.INS_Out.phi;

    /* Product: '<S129>/Divide1' incorporates:
     *  Abs: '<S129>/Abs'
     *  Constant: '<S129>/const2'
     */
    rtb_Add_gy_idx_0 = fabsf(rtb_Square_d) / 0.002F;

    /* Product: '<S129>/Divide' incorporates:
     *  Constant: '<S127>/Constant1'
     *  Constant: '<S129>/const1'
     *  Math: '<S129>/Square'
     *  SignalConversion: '<S129>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_TmpSignalConversionAtMult_1 = 9.5993F / (CONTROL_PARAM.MC_ROLL_P *
      CONTROL_PARAM.MC_ROLL_P);

    /* Signum: '<S129>/Sign' */
    if (rtb_Square_d < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else if (rtb_Square_d > 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_0 = rtb_Square_d;
    }

    /* Switch: '<S129>/Switch' incorporates:
     *  Constant: '<S127>/Constant1'
     *  Gain: '<S129>/Gain1'
     *  Gain: '<S129>/Gain2'
     *  Logic: '<S129>/Logical Operator'
     *  Product: '<S129>/Divide'
     *  Product: '<S129>/Multiply'
     *  Product: '<S129>/Multiply1'
     *  Product: '<S129>/Multiply2'
     *  Product: '<S129>/Multiply3'
     *  RelationalOperator: '<S129>/Relational Operator'
     *  RelationalOperator: '<S129>/Relational Operator2'
     *  SignalConversion: '<S129>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S129>/Sqrt'
     *  Sum: '<S129>/Subtract'
     */
    if ((rtb_Square_d <= rtb_TmpSignalConversionAtMult_1) && (rtb_Square_d >=
         -rtb_TmpSignalConversionAtMult_1)) {
      rtb_TmpSignalConversionAtMult_0 = rtb_Square_d * CONTROL_PARAM.MC_ROLL_P;
    } else {
      rtb_TmpSignalConversionAtMult_0 *= sqrtf((rtb_TmpSignalConversionAtMult_0 *
        rtb_Square_d - 0.5F * rtb_TmpSignalConversionAtMult_1) *
        Controller_ConstB.Gain);
    }

    /* Gain: '<S129>/Gain3' */
    rtb_TmpSignalConversionAtMult_1 = -rtb_Add_gy_idx_0;

    /* Switch: '<S130>/Switch' incorporates:
     *  Gain: '<S129>/Gain3'
     *  RelationalOperator: '<S130>/UpperRelop'
     */
    if (rtb_TmpSignalConversionAtMult_0 >= -rtb_Add_gy_idx_0) {
      rtb_TmpSignalConversionAtMult_1 = rtb_TmpSignalConversionAtMult_0;
    }

    /* Switch: '<S130>/Switch2' incorporates:
     *  RelationalOperator: '<S130>/LowerRelop1'
     */
    if (rtb_TmpSignalConversionAtMult_0 <= rtb_Add_gy_idx_0) {
      rtb_Add_gy_idx_0 = rtb_TmpSignalConversionAtMult_1;
    }

    rtb_Divide_m_idx_2 = rtb_Add_gy_idx_0;

    /* Sum: '<S126>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S129>/Divide1'
     */
    rtb_Square_d = rtb_Integrator1_m - Controller_U.INS_Out.theta;

    /* Product: '<S129>/Divide1' incorporates:
     *  Abs: '<S129>/Abs'
     *  Constant: '<S129>/const2'
     */
    rtb_Add_gy_idx_0 = fabsf(rtb_Square_d) / 0.002F;

    /* Product: '<S129>/Divide' incorporates:
     *  Constant: '<S127>/Constant2'
     *  Constant: '<S129>/const1'
     *  Math: '<S129>/Square'
     *  SignalConversion: '<S129>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_TmpSignalConversionAtMult_1 = 9.5993F / (CONTROL_PARAM.MC_PITCH_P *
      CONTROL_PARAM.MC_PITCH_P);

    /* Signum: '<S129>/Sign' */
    if (rtb_Square_d < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else if (rtb_Square_d > 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_0 = rtb_Square_d;
    }

    /* Switch: '<S129>/Switch' incorporates:
     *  Constant: '<S127>/Constant2'
     *  Gain: '<S129>/Gain1'
     *  Gain: '<S129>/Gain2'
     *  Logic: '<S129>/Logical Operator'
     *  Product: '<S129>/Divide'
     *  Product: '<S129>/Multiply'
     *  Product: '<S129>/Multiply1'
     *  Product: '<S129>/Multiply2'
     *  Product: '<S129>/Multiply3'
     *  RelationalOperator: '<S129>/Relational Operator'
     *  RelationalOperator: '<S129>/Relational Operator2'
     *  SignalConversion: '<S129>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S129>/Sqrt'
     *  Sum: '<S129>/Subtract'
     */
    if ((rtb_Square_d <= rtb_TmpSignalConversionAtMult_1) && (rtb_Square_d >=
         -rtb_TmpSignalConversionAtMult_1)) {
      rtb_TmpSignalConversionAtMult_0 = rtb_Square_d * CONTROL_PARAM.MC_PITCH_P;
    } else {
      rtb_TmpSignalConversionAtMult_0 *= sqrtf((rtb_TmpSignalConversionAtMult_0 *
        rtb_Square_d - 0.5F * rtb_TmpSignalConversionAtMult_1) *
        Controller_ConstB.Gain);
    }

    /* Gain: '<S129>/Gain3' */
    rtb_TmpSignalConversionAtMult_1 = -rtb_Add_gy_idx_0;

    /* Switch: '<S130>/Switch' incorporates:
     *  Gain: '<S129>/Gain3'
     *  RelationalOperator: '<S130>/UpperRelop'
     */
    if (rtb_TmpSignalConversionAtMult_0 >= -rtb_Add_gy_idx_0) {
      rtb_TmpSignalConversionAtMult_1 = rtb_TmpSignalConversionAtMult_0;
    }

    /* Switch: '<S130>/Switch2' incorporates:
     *  RelationalOperator: '<S130>/LowerRelop1'
     */
    if (rtb_TmpSignalConversionAtMult_0 <= rtb_Add_gy_idx_0) {
      rtb_Add_gy_idx_0 = rtb_TmpSignalConversionAtMult_1;
    }

    /* Trigonometry: '<S120>/Sin' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Ldot_err = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S120>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Sum1_g = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Trigonometry: '<S120>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Integrator1_m = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Sum: '<S120>/Add1' incorporates:
     *  Product: '<S120>/Multiply1'
     *  Product: '<S120>/Multiply3'
     *  Trigonometry: '<S120>/Cos'
     *  Trigonometry: '<S120>/Cos1'
     *  Trigonometry: '<S120>/Sin'
     */
    rtb_Gain_c4 = rtb_Ldot_err * rtb_Sum1_g * Controller_U.FMS_Out.psi_rate_cmd
      + rtb_Integrator1_m * rtb_Add_gy_idx_0;

    /* Sum: '<S120>/Add2' incorporates:
     *  Product: '<S120>/Multiply4'
     *  Product: '<S120>/Multiply5'
     *  Trigonometry: '<S120>/Cos'
     *  Trigonometry: '<S120>/Cos1'
     *  Trigonometry: '<S120>/Sin'
     */
    rtb_Integrator1_m = rtb_Integrator1_m * rtb_Sum1_g *
      Controller_U.FMS_Out.psi_rate_cmd - rtb_Ldot_err * rtb_Add_gy_idx_0;

    /* Switch: '<S111>/Switch' incorporates:
     *  Constant: '<S121>/Constant'
     *  Constant: '<S122>/Constant'
     *  RelationalOperator: '<S121>/Compare'
     *  RelationalOperator: '<S122>/Compare'
     *  Switch: '<S111>/Switch1'
     */
    if (rtb_BitwiseAND_n == 2) {
      rtb_TmpSignalConversionAtMult_0 = Controller_U.FMS_Out.p_cmd;
      rtb_TmpSignalConversionAtMult_1 = Controller_U.FMS_Out.q_cmd;
      rtb_Integrator1_m = Controller_U.FMS_Out.r_cmd;
    } else if (rtb_BitwiseAND_n == 6) {
      /* Switch: '<S123>/Switch' incorporates:
       *  S-Function (sfix_bitop): '<S123>/cmd_p valid'
       *  S-Function (sfix_bitop): '<S123>/cmd_q valid'
       *  S-Function (sfix_bitop): '<S123>/cmd_r valid'
       *  Saturate: '<S110>/Saturation'
       *  Saturate: '<S110>/Saturation2'
       *  Switch: '<S111>/Switch1'
       */
      if ((Controller_U.FMS_Out.cmd_mask & 1) > 0) {
        rtb_TmpSignalConversionAtMult_0 = Controller_U.FMS_Out.p_cmd;
      } else {
        /* Sum: '<S120>/Add' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S120>/Multiply'
         *  Trigonometry: '<S120>/Sin1'
         */
        rtb_TmpSignalConversionAtMult_0 = rtb_Divide_m_idx_2 - arm_sin_f32
          (Controller_U.INS_Out.theta) * Controller_U.FMS_Out.psi_rate_cmd;

        /* Saturate: '<S110>/Saturation1' incorporates:
         *  Sum: '<S120>/Add'
         */
        if (rtb_TmpSignalConversionAtMult_0 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
          rtb_TmpSignalConversionAtMult_0 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
        } else {
          if (rtb_TmpSignalConversionAtMult_0 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
            rtb_TmpSignalConversionAtMult_0 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
          }
        }
      }

      if ((Controller_U.FMS_Out.cmd_mask & 2) > 0) {
        rtb_TmpSignalConversionAtMult_1 = Controller_U.FMS_Out.q_cmd;
      } else if (rtb_Gain_c4 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        /* Saturate: '<S110>/Saturation2' */
        rtb_TmpSignalConversionAtMult_1 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
      } else if (rtb_Gain_c4 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        /* Saturate: '<S110>/Saturation2' */
        rtb_TmpSignalConversionAtMult_1 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      } else {
        /* Saturate: '<S110>/Saturation2' */
        rtb_TmpSignalConversionAtMult_1 = rtb_Gain_c4;
      }

      if ((Controller_U.FMS_Out.cmd_mask & 4) > 0) {
        rtb_Integrator1_m = Controller_U.FMS_Out.r_cmd;
      } else if (rtb_Integrator1_m > CONTROL_PARAM.MC_R_CMD_LIM) {
        /* Saturate: '<S110>/Saturation' */
        rtb_Integrator1_m = CONTROL_PARAM.MC_R_CMD_LIM;
      } else {
        if (rtb_Integrator1_m < -CONTROL_PARAM.MC_R_CMD_LIM) {
          /* Saturate: '<S110>/Saturation' */
          rtb_Integrator1_m = -CONTROL_PARAM.MC_R_CMD_LIM;
        }
      }

      /* End of Switch: '<S123>/Switch' */
    } else {
      /* Sum: '<S120>/Add' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Product: '<S120>/Multiply'
       *  Trigonometry: '<S120>/Sin1'
       */
      rtb_TmpSignalConversionAtMult_0 = rtb_Divide_m_idx_2 - arm_sin_f32
        (Controller_U.INS_Out.theta) * Controller_U.FMS_Out.psi_rate_cmd;

      /* Saturate: '<S110>/Saturation1' incorporates:
       *  Sum: '<S120>/Add'
       */
      if (rtb_TmpSignalConversionAtMult_0 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        /* Switch: '<S111>/Switch1' */
        rtb_TmpSignalConversionAtMult_0 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
      } else {
        if (rtb_TmpSignalConversionAtMult_0 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
          /* Switch: '<S111>/Switch1' */
          rtb_TmpSignalConversionAtMult_0 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
        }
      }

      /* Saturate: '<S110>/Saturation2' */
      if (rtb_Gain_c4 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        /* Switch: '<S111>/Switch1' */
        rtb_TmpSignalConversionAtMult_1 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
      } else if (rtb_Gain_c4 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        /* Switch: '<S111>/Switch1' */
        rtb_TmpSignalConversionAtMult_1 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      } else {
        /* Switch: '<S111>/Switch1' */
        rtb_TmpSignalConversionAtMult_1 = rtb_Gain_c4;
      }

      /* Saturate: '<S110>/Saturation' */
      if (rtb_Integrator1_m > CONTROL_PARAM.MC_R_CMD_LIM) {
        /* Switch: '<S111>/Switch1' */
        rtb_Integrator1_m = CONTROL_PARAM.MC_R_CMD_LIM;
      } else {
        if (rtb_Integrator1_m < -CONTROL_PARAM.MC_R_CMD_LIM) {
          /* Switch: '<S111>/Switch1' */
          rtb_Integrator1_m = -CONTROL_PARAM.MC_R_CMD_LIM;
        }
      }
    }

    /* End of Switch: '<S111>/Switch' */

    /* Sum: '<S112>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_m_idx_1 = rtb_TmpSignalConversionAtMult_0 -
      Controller_U.INS_Out.p;

    /* Saturate: '<S112>/Saturation' */
    if (rtb_Divide_m_idx_1 > 3.14159274F) {
      rtb_Divide_m_idx_1 = 3.14159274F;
    } else {
      if (rtb_Divide_m_idx_1 < -3.14159274F) {
        rtb_Divide_m_idx_1 = -3.14159274F;
      }
    }

    rtb_TmpSignalConversionAtMult_0 = rtb_Divide_m_idx_1;

    /* Sum: '<S112>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_m_idx_1 = rtb_TmpSignalConversionAtMult_1 -
      Controller_U.INS_Out.q;

    /* Saturate: '<S112>/Saturation' */
    if (rtb_Divide_m_idx_1 > 3.14159274F) {
      rtb_Divide_m_idx_1 = 3.14159274F;
    } else {
      if (rtb_Divide_m_idx_1 < -3.14159274F) {
        rtb_Divide_m_idx_1 = -3.14159274F;
      }
    }

    rtb_TmpSignalConversionAtMult_1 = rtb_Divide_m_idx_1;

    /* Sum: '<S112>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_m_idx_1 = rtb_Integrator1_m - Controller_U.INS_Out.r;

    /* Saturate: '<S112>/Saturation' */
    if (rtb_Divide_m_idx_1 > 3.14159274F) {
      rtb_Divide_m_idx_1 = 3.14159274F;
    } else {
      if (rtb_Divide_m_idx_1 < -3.14159274F) {
        rtb_Divide_m_idx_1 = -3.14159274F;
      }
    }

    /* DiscreteIntegrator: '<S115>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] =
        rtb_TmpSignalConversionAtMult_0;
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] =
        rtb_TmpSignalConversionAtMult_1;
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] = rtb_Divide_m_idx_1;
    }

    /* DiscreteIntegrator: '<S119>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S115>/Discrete-Time Integrator5'
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

    /* Gain: '<S119>/Gain' incorporates:
     *  DiscreteIntegrator: '<S115>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S119>/Discrete-Time Integrator1'
     *  Sum: '<S119>/Sum5'
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

    /* Switch: '<S119>/Switch' incorporates:
     *  Gain: '<S119>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_Add_gy_idx_0 = 0.0F;
      rtb_Add_gy_idx_1 = 0.0F;
      rtb_Add_gy_idx_2 = 0.0F;
    } else {
      rtb_Add_gy_idx_0 = rtb_Multiply_ni[0];
      rtb_Add_gy_idx_1 = rtb_Multiply_ni[1];
      rtb_Add_gy_idx_2 = rtb_Multiply_ni[2];
    }

    /* End of Switch: '<S119>/Switch' */

    /* Product: '<S116>/Multiply' incorporates:
     *  Constant: '<S116>/gain1'
     */
    rtb_Sum1_g = CONTROL_PARAM.MC_ROLL_RATE_D * rtb_Add_gy_idx_0;

    /* Saturate: '<S116>/Saturation' */
    if (rtb_Sum1_g > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Sum1_g = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Sum1_g < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Sum1_g = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    rtb_Add_gy_idx_0 = rtb_Sum1_g;

    /* Product: '<S116>/Multiply' incorporates:
     *  Constant: '<S116>/gain2'
     */
    rtb_Sum1_g = CONTROL_PARAM.MC_PITCH_RATE_D * rtb_Add_gy_idx_1;

    /* Saturate: '<S116>/Saturation' */
    if (rtb_Sum1_g > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Sum1_g = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Sum1_g < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Sum1_g = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    rtb_Add_gy_idx_1 = rtb_Sum1_g;

    /* Product: '<S116>/Multiply' incorporates:
     *  Constant: '<S116>/gain3'
     */
    rtb_Sum1_g = CONTROL_PARAM.MC_YAW_RATE_D * rtb_Add_gy_idx_2;

    /* Saturate: '<S116>/Saturation' */
    if (rtb_Sum1_g > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Sum1_g = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Sum1_g < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Sum1_g = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    /* SignalConversion: '<S5>/BusConversion_InsertedFor_VTOL_actuator_cmd_at_inport_0' incorporates:
     *  Constant: '<S118>/gain1'
     *  Constant: '<S118>/gain2'
     *  Constant: '<S118>/gain3'
     *  DiscreteIntegrator: '<S115>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S117>/Discrete-Time Integrator'
     *  Product: '<S118>/Multiply'
     *  Sum: '<S113>/Add'
     */
    Controller_B.mc_torque_cmd[0] = (CONTROL_PARAM.MC_ROLL_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0]) + rtb_Add_gy_idx_0;
    Controller_B.mc_torque_cmd[1] = (CONTROL_PARAM.MC_PITCH_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1]) + rtb_Add_gy_idx_1;
    Controller_B.mc_torque_cmd[2] = (CONTROL_PARAM.MC_YAW_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[2]) + rtb_Sum1_g;

    /* Product: '<S142>/Multiply1' incorporates:
     *  Constant: '<S142>/const1'
     *  DiscreteIntegrator: '<S139>/Integrator'
     */
    rtb_Gain_c4 = Controller_DW.Integrator_DSTATE[0] * 0.1F;
    rtb_Ldot_err = Controller_DW.Integrator_DSTATE[1] * 0.1F;

    /* Sum: '<S142>/Add' incorporates:
     *  DiscreteIntegrator: '<S139>/Integrator1'
     *  Sum: '<S139>/Subtract'
     */
    rtb_Divide_m_idx_2 = (Controller_DW.Integrator1_DSTATE[0] -
                          Controller_U.FMS_Out.u_cmd) + rtb_Gain_c4;
    rtb_Integrator1_m = (Controller_DW.Integrator1_DSTATE[1] -
                         Controller_U.FMS_Out.v_cmd) + rtb_Ldot_err;

    /* Signum: '<S142>/Sign' */
    if (rtb_Divide_m_idx_2 < 0.0F) {
      rtb_Square_d = -1.0F;
    } else if (rtb_Divide_m_idx_2 > 0.0F) {
      rtb_Square_d = 1.0F;
    } else {
      rtb_Square_d = rtb_Divide_m_idx_2;
    }

    /* Sum: '<S142>/Add2' incorporates:
     *  Abs: '<S142>/Abs'
     *  Gain: '<S142>/Gain'
     *  Gain: '<S142>/Gain1'
     *  Product: '<S142>/Multiply2'
     *  Product: '<S142>/Multiply3'
     *  Signum: '<S142>/Sign'
     *  Sqrt: '<S142>/Sqrt'
     *  Sum: '<S142>/Add1'
     *  Sum: '<S142>/Subtract'
     */
    rtb_Add_gy_idx_0 = (sqrtf((8.0F * fabsf(rtb_Divide_m_idx_2) +
      Controller_ConstB.d) * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
      rtb_Square_d + rtb_Gain_c4;

    /* Sum: '<S142>/Add3' incorporates:
     *  Signum: '<S142>/Sign'
     */
    rtb_Sum1_g = rtb_Divide_m_idx_2 + Controller_ConstB.d;

    /* Sum: '<S142>/Subtract1' incorporates:
     *  Signum: '<S142>/Sign'
     */
    rtb_Square_d = rtb_Divide_m_idx_2 - Controller_ConstB.d;

    /* Signum: '<S142>/Sign1' */
    if (rtb_Sum1_g < 0.0F) {
      rtb_Sum1_g = -1.0F;
    } else {
      if (rtb_Sum1_g > 0.0F) {
        rtb_Sum1_g = 1.0F;
      }
    }

    /* Signum: '<S142>/Sign2' */
    if (rtb_Square_d < 0.0F) {
      rtb_Square_d = -1.0F;
    } else {
      if (rtb_Square_d > 0.0F) {
        rtb_Square_d = 1.0F;
      }
    }

    /* Sum: '<S142>/Add2' incorporates:
     *  Gain: '<S142>/Gain2'
     *  Product: '<S142>/Multiply4'
     *  Signum: '<S142>/Sign'
     *  Sum: '<S142>/Add4'
     *  Sum: '<S142>/Add5'
     *  Sum: '<S142>/Subtract2'
     */
    rtb_Divide_m_idx_2 = ((rtb_Divide_m_idx_2 - rtb_Add_gy_idx_0) + rtb_Gain_c4)
      * ((rtb_Sum1_g - rtb_Square_d) * 0.5F) + rtb_Add_gy_idx_0;

    /* Signum: '<S142>/Sign' */
    if (rtb_Integrator1_m < 0.0F) {
      rtb_Square_d = -1.0F;
    } else if (rtb_Integrator1_m > 0.0F) {
      rtb_Square_d = 1.0F;
    } else {
      rtb_Square_d = rtb_Integrator1_m;
    }

    /* Sum: '<S142>/Add2' incorporates:
     *  Abs: '<S142>/Abs'
     *  Gain: '<S142>/Gain'
     *  Gain: '<S142>/Gain1'
     *  Product: '<S142>/Multiply2'
     *  Product: '<S142>/Multiply3'
     *  Signum: '<S142>/Sign'
     *  Sqrt: '<S142>/Sqrt'
     *  Sum: '<S142>/Add1'
     *  Sum: '<S142>/Subtract'
     */
    rtb_Add_gy_idx_0 = (sqrtf((8.0F * fabsf(rtb_Integrator1_m) +
      Controller_ConstB.d) * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
      rtb_Square_d + rtb_Ldot_err;

    /* Sum: '<S142>/Add3' incorporates:
     *  Signum: '<S142>/Sign'
     */
    rtb_Sum1_g = rtb_Integrator1_m + Controller_ConstB.d;

    /* Sum: '<S142>/Subtract1' incorporates:
     *  Signum: '<S142>/Sign'
     */
    rtb_Square_d = rtb_Integrator1_m - Controller_ConstB.d;

    /* Signum: '<S142>/Sign1' */
    if (rtb_Sum1_g < 0.0F) {
      rtb_Sum1_g = -1.0F;
    } else {
      if (rtb_Sum1_g > 0.0F) {
        rtb_Sum1_g = 1.0F;
      }
    }

    /* Signum: '<S142>/Sign2' */
    if (rtb_Square_d < 0.0F) {
      rtb_Square_d = -1.0F;
    } else {
      if (rtb_Square_d > 0.0F) {
        rtb_Square_d = 1.0F;
      }
    }

    /* Sum: '<S142>/Add5' incorporates:
     *  Gain: '<S142>/Gain2'
     *  Product: '<S142>/Multiply4'
     *  Signum: '<S142>/Sign'
     *  Sum: '<S142>/Add2'
     *  Sum: '<S142>/Add4'
     *  Sum: '<S142>/Subtract2'
     */
    rtb_Add_gy_idx_0 += ((rtb_Integrator1_m - rtb_Add_gy_idx_0) + rtb_Ldot_err) *
      ((rtb_Sum1_g - rtb_Square_d) * 0.5F);

    /* Gain: '<S155>/Gain' incorporates:
     *  DiscreteIntegrator: '<S157>/Integrator1'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S155>/Sum1'
     */
    rtb_Integrator1_m = -(Controller_DW.Integrator1_DSTATE_e -
                          Controller_U.INS_Out.vd);
    Controller_B.Constant = CONTROL_PARAM.MC_VEL_Z_I_MIN;

    /* DiscreteIntegrator: '<S160>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S160>/Constant'
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

    /* DiscreteIntegrator: '<S162>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_d != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i = rtb_Integrator1_m;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_Prev_ks != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i = rtb_Integrator1_m;
    }

    /* Gain: '<S162>/Gain' incorporates:
     *  DiscreteIntegrator: '<S162>/Discrete-Time Integrator1'
     *  Sum: '<S162>/Sum5'
     */
    rtb_Square_d = (rtb_Integrator1_m -
                    Controller_DW.DiscreteTimeIntegrator1_DSTAT_i) * 62.831852F;

    /* Switch: '<S151>/Switch' incorporates:
     *  Constant: '<S153>/Constant'
     *  RelationalOperator: '<S153>/Compare'
     */
    if (rtb_BitwiseAND_n <= 3) {
      /* SignalConversion: '<S5>/BusConversion_InsertedFor_VTOL_actuator_cmd_at_inport_0' incorporates:
       *  Bias: '<S151>/Bias'
       *  Gain: '<S151>/Gain'
       */
      Controller_B.mc_force_cmd[2] = 0.000999987125F * (real32_T)
        Controller_U.FMS_Out.throttle_cmd + -1.0F;
    } else {
      /* Product: '<S154>/Multiply' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S154>/Cos'
       *  Trigonometry: '<S154>/Cos1'
       */
      rtb_Gain_c4 = arm_cos_f32(Controller_U.INS_Out.phi) * arm_cos_f32
        (Controller_U.INS_Out.theta);

      /* Gain: '<S154>/Gain' */
      rtb_Sum1_g = 2.0F * rtb_Gain_c4;

      /* Saturate: '<S154>/Saturation1' */
      if (rtb_Gain_c4 > 1.0F) {
        rtb_Gain_c4 = 1.0F;
      } else {
        if (rtb_Gain_c4 < 0.5F) {
          rtb_Gain_c4 = 0.5F;
        }
      }

      /* End of Saturate: '<S154>/Saturation1' */

      /* Product: '<S154>/Divide' incorporates:
       *  Constant: '<S154>/Constant'
       */
      rtb_Ldot_err = 1.0F / rtb_Gain_c4;

      /* Switch: '<S162>/Switch' incorporates:
       *  Gain: '<S162>/Gain1'
       */
      if (Controller_U.FMS_Out.reset > 0) {
        rtb_Add_gy_idx_1 = 0.0F;
      } else {
        rtb_Add_gy_idx_1 = rtb_Square_d;
      }

      /* End of Switch: '<S162>/Switch' */

      /* Product: '<S159>/Multiply' incorporates:
       *  Constant: '<S159>/kd'
       */
      rtb_Gain_c4 = CONTROL_PARAM.MC_VEL_Z_D * rtb_Add_gy_idx_1;

      /* Saturate: '<S159>/Saturation' */
      if (rtb_Gain_c4 > CONTROL_PARAM.MC_VEL_Z_D_MAX) {
        rtb_Gain_c4 = CONTROL_PARAM.MC_VEL_Z_D_MAX;
      } else {
        if (rtb_Gain_c4 < CONTROL_PARAM.MC_VEL_Z_D_MIN) {
          rtb_Gain_c4 = CONTROL_PARAM.MC_VEL_Z_D_MIN;
        }
      }

      /* End of Saturate: '<S159>/Saturation' */

      /* Saturate: '<S154>/Saturation' */
      if (rtb_Sum1_g > 1.0F) {
        rtb_Sum1_g = 1.0F;
      } else {
        if (rtb_Sum1_g < 0.0F) {
          rtb_Sum1_g = 0.0F;
        }
      }

      /* End of Saturate: '<S154>/Saturation' */

      /* SignalConversion: '<S5>/BusConversion_InsertedFor_VTOL_actuator_cmd_at_inport_0' incorporates:
       *  Constant: '<S152>/hover_throttle'
       *  Constant: '<S161>/kp'
       *  DiscreteIntegrator: '<S160>/Discrete-Time Integrator'
       *  Product: '<S154>/Multiply1'
       *  Product: '<S161>/Multiply'
       *  Sum: '<S152>/Sum'
       *  Sum: '<S156>/Add'
       */
      Controller_B.mc_force_cmd[2] = ((CONTROL_PARAM.MC_VEL_Z_P *
        rtb_Integrator1_m + Controller_DW.DiscreteTimeIntegrator_DSTATE_l) +
        rtb_Gain_c4) * rtb_Ldot_err * rtb_Sum1_g + CONTROL_PARAM.MC_HOVER_THRO;
    }

    /* End of Switch: '<S151>/Switch' */

    /* SignalConversion: '<S5>/BusConversion_InsertedFor_VTOL_actuator_cmd_at_inport_0' */
    Controller_B.mc_force_cmd[0] = Controller_ConstB.TmpBufferAtConstantOutport1;
    Controller_B.mc_force_cmd[1] = Controller_ConstB.TmpBufferAtConstantOutport1;

    /* Product: '<S158>/Multiply1' incorporates:
     *  Constant: '<S158>/const1'
     *  DiscreteIntegrator: '<S157>/Integrator'
     */
    rtb_Sum1_g = Controller_DW.Integrator_DSTATE_j * 0.05F;

    /* Sum: '<S158>/Add' incorporates:
     *  DiscreteIntegrator: '<S157>/Integrator1'
     *  Sum: '<S157>/Subtract'
     */
    rtb_Gain_c4 = (Controller_DW.Integrator1_DSTATE_e -
                   Controller_U.FMS_Out.w_cmd) + rtb_Sum1_g;

    /* Signum: '<S158>/Sign' */
    if (rtb_Gain_c4 < 0.0F) {
      rtb_Ldot_err = -1.0F;
    } else if (rtb_Gain_c4 > 0.0F) {
      rtb_Ldot_err = 1.0F;
    } else {
      rtb_Ldot_err = rtb_Gain_c4;
    }

    /* End of Signum: '<S158>/Sign' */

    /* Sum: '<S158>/Add2' incorporates:
     *  Abs: '<S158>/Abs'
     *  Gain: '<S158>/Gain'
     *  Gain: '<S158>/Gain1'
     *  Product: '<S158>/Multiply2'
     *  Product: '<S158>/Multiply3'
     *  Sqrt: '<S158>/Sqrt'
     *  Sum: '<S158>/Add1'
     *  Sum: '<S158>/Subtract'
     */
    rtb_Ldot_err = (sqrtf((8.0F * fabsf(rtb_Gain_c4) + Controller_ConstB.d_i) *
                          Controller_ConstB.d_i) - Controller_ConstB.d_i) * 0.5F
      * rtb_Ldot_err + rtb_Sum1_g;

    /* Sum: '<S158>/Add4' */
    rtb_Saturation_g = (rtb_Gain_c4 - rtb_Ldot_err) + rtb_Sum1_g;

    /* Sum: '<S158>/Add3' */
    rtb_Sum1_g = rtb_Gain_c4 + Controller_ConstB.d_i;

    /* Sum: '<S158>/Subtract1' */
    rtb_Gain_c4 -= Controller_ConstB.d_i;

    /* Signum: '<S158>/Sign1' */
    if (rtb_Sum1_g < 0.0F) {
      rtb_Sum1_g = -1.0F;
    } else {
      if (rtb_Sum1_g > 0.0F) {
        rtb_Sum1_g = 1.0F;
      }
    }

    /* End of Signum: '<S158>/Sign1' */

    /* Signum: '<S158>/Sign2' */
    if (rtb_Gain_c4 < 0.0F) {
      rtb_Gain_c4 = -1.0F;
    } else {
      if (rtb_Gain_c4 > 0.0F) {
        rtb_Gain_c4 = 1.0F;
      }
    }

    /* End of Signum: '<S158>/Sign2' */

    /* Sum: '<S158>/Add5' incorporates:
     *  Gain: '<S158>/Gain2'
     *  Product: '<S158>/Multiply4'
     *  Sum: '<S158>/Subtract2'
     */
    rtb_Ldot_err += (rtb_Sum1_g - rtb_Gain_c4) * 0.5F * rtb_Saturation_g;

    /* Update for DiscreteIntegrator: '<S117>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S117>/gain1'
     *  Constant: '<S117>/gain2'
     *  Constant: '<S117>/gain3'
     *  DiscreteIntegrator: '<S115>/Discrete-Time Integrator5'
     *  Product: '<S117>/Multiply'
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

    /* End of Update for DiscreteIntegrator: '<S117>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S144>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_PrevRe_p = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S146>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;

    /* Update for DiscreteIntegrator: '<S139>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S139>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE[0] += 0.002F *
      Controller_DW.Integrator_DSTATE[0];

    /* Update for DiscreteIntegrator: '<S144>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S144>/ki'
     *  Product: '<S144>/Multiply'
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

    /* Update for DiscreteIntegrator: '<S146>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] += 0.002F *
      rtb_Switch2_idx_0;

    /* Update for DiscreteIntegrator: '<S139>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S139>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE[1] += 0.002F *
      Controller_DW.Integrator_DSTATE[1];

    /* Update for DiscreteIntegrator: '<S144>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S144>/ki'
     *  Product: '<S144>/Multiply'
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

    /* Update for DiscreteIntegrator: '<S146>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] += 0.002F *
      rtb_Divide_m_idx_0;
    Controller_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S115>/Discrete-Time Integrator5' */
    Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;

    /* Update for DiscreteIntegrator: '<S119>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 0U;

    /* Update for DiscreteIntegrator: '<S115>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S115>/Gain'
     *  Sum: '<S115>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] +=
      (rtb_TmpSignalConversionAtMult_0 -
       Controller_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S119>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[0] += 0.002F *
      rtb_Multiply_ni[0];

    /* Update for DiscreteIntegrator: '<S115>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S115>/Gain'
     *  Sum: '<S115>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] +=
      (rtb_TmpSignalConversionAtMult_1 -
       Controller_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S119>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[1] += 0.002F *
      rtb_Multiply_ni[1];

    /* Update for DiscreteIntegrator: '<S115>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S115>/Gain'
     *  Sum: '<S115>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] += (rtb_Divide_m_idx_1 -
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S119>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[2] += 0.002F *
      rtb_Multiply_ni[2];
    Controller_DW.DiscreteTimeIntegrator1_PrevR_k = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Signum: '<S142>/Sign3' incorporates:
     *  Product: '<S142>/Divide'
     *  Sum: '<S142>/Add6'
     */
    rtb_Sum1_g = rtb_Divide_m_idx_2 + Controller_ConstB.d;

    /* Signum: '<S142>/Sign4' incorporates:
     *  Product: '<S142>/Divide'
     *  Sum: '<S142>/Subtract3'
     */
    rtb_TmpSignalConversionAtMult_0 = rtb_Divide_m_idx_2 - Controller_ConstB.d;

    /* Signum: '<S142>/Sign5' incorporates:
     *  Product: '<S142>/Divide'
     */
    if (rtb_Divide_m_idx_2 < 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = -1.0F;
    } else if (rtb_Divide_m_idx_2 > 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_1 = rtb_Divide_m_idx_2;
    }

    /* Signum: '<S142>/Sign3' */
    if (rtb_Sum1_g < 0.0F) {
      rtb_Sum1_g = -1.0F;
    } else {
      if (rtb_Sum1_g > 0.0F) {
        rtb_Sum1_g = 1.0F;
      }
    }

    /* Signum: '<S142>/Sign4' */
    if (rtb_TmpSignalConversionAtMult_0 < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else {
      if (rtb_TmpSignalConversionAtMult_0 > 0.0F) {
        rtb_TmpSignalConversionAtMult_0 = 1.0F;
      }
    }

    /* Signum: '<S142>/Sign6' incorporates:
     *  Product: '<S142>/Divide'
     */
    if (rtb_Divide_m_idx_2 < 0.0F) {
      rtb_Divide_m_idx_0 = -1.0F;
    } else if (rtb_Divide_m_idx_2 > 0.0F) {
      rtb_Divide_m_idx_0 = 1.0F;
    } else {
      rtb_Divide_m_idx_0 = rtb_Divide_m_idx_2;
    }

    /* Update for DiscreteIntegrator: '<S139>/Integrator' incorporates:
     *  Constant: '<S142>/const'
     *  Gain: '<S142>/Gain3'
     *  Product: '<S142>/Divide'
     *  Product: '<S142>/Multiply5'
     *  Product: '<S142>/Multiply6'
     *  Sum: '<S142>/Subtract4'
     *  Sum: '<S142>/Subtract5'
     *  Sum: '<S142>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE[0] += ((rtb_Divide_m_idx_2 /
      Controller_ConstB.d - rtb_TmpSignalConversionAtMult_1) *
      Controller_ConstB.Gain4 * ((rtb_Sum1_g - rtb_TmpSignalConversionAtMult_0) *
      0.5F) - rtb_Divide_m_idx_0 * 78.448F) * 0.002F;

    /* Signum: '<S142>/Sign3' incorporates:
     *  Sum: '<S142>/Add6'
     */
    rtb_Sum1_g = rtb_Add_gy_idx_0 + Controller_ConstB.d;

    /* Signum: '<S142>/Sign4' incorporates:
     *  Sum: '<S142>/Subtract3'
     */
    rtb_TmpSignalConversionAtMult_0 = rtb_Add_gy_idx_0 - Controller_ConstB.d;

    /* Signum: '<S142>/Sign5' */
    if (rtb_Add_gy_idx_0 < 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = -1.0F;
    } else if (rtb_Add_gy_idx_0 > 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_1 = rtb_Add_gy_idx_0;
    }

    /* Signum: '<S142>/Sign3' */
    if (rtb_Sum1_g < 0.0F) {
      rtb_Sum1_g = -1.0F;
    } else {
      if (rtb_Sum1_g > 0.0F) {
        rtb_Sum1_g = 1.0F;
      }
    }

    /* Signum: '<S142>/Sign4' */
    if (rtb_TmpSignalConversionAtMult_0 < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else {
      if (rtb_TmpSignalConversionAtMult_0 > 0.0F) {
        rtb_TmpSignalConversionAtMult_0 = 1.0F;
      }
    }

    /* Signum: '<S142>/Sign6' */
    if (rtb_Add_gy_idx_0 < 0.0F) {
      rtb_Divide_m_idx_0 = -1.0F;
    } else if (rtb_Add_gy_idx_0 > 0.0F) {
      rtb_Divide_m_idx_0 = 1.0F;
    } else {
      rtb_Divide_m_idx_0 = rtb_Add_gy_idx_0;
    }

    /* Update for DiscreteIntegrator: '<S139>/Integrator' incorporates:
     *  Constant: '<S142>/const'
     *  Gain: '<S142>/Gain3'
     *  Product: '<S142>/Divide'
     *  Product: '<S142>/Multiply5'
     *  Product: '<S142>/Multiply6'
     *  Sum: '<S142>/Subtract4'
     *  Sum: '<S142>/Subtract5'
     *  Sum: '<S142>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE[1] += ((rtb_Add_gy_idx_0 /
      Controller_ConstB.d - rtb_TmpSignalConversionAtMult_1) *
      Controller_ConstB.Gain4 * ((rtb_Sum1_g - rtb_TmpSignalConversionAtMult_0) *
      0.5F) - rtb_Divide_m_idx_0 * 78.448F) * 0.002F;

    /* Update for DiscreteIntegrator: '<S157>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S157>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_e += 0.002F *
      Controller_DW.Integrator_DSTATE_j;

    /* Update for DiscreteIntegrator: '<S160>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S160>/ki'
     *  Product: '<S160>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_l += CONTROL_PARAM.MC_VEL_Z_I *
      rtb_Integrator1_m * 0.002F;
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

    /* End of Update for DiscreteIntegrator: '<S160>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S162>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_i += 0.002F * rtb_Square_d;
    Controller_DW.DiscreteTimeIntegrator1_Prev_ks = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Signum: '<S158>/Sign6' incorporates:
     *  Signum: '<S158>/Sign5'
     */
    if (rtb_Ldot_err < 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = -1.0F;

      /* Signum: '<S158>/Sign5' */
      rtb_Integrator1_m = -1.0F;
    } else if (rtb_Ldot_err > 0.0F) {
      rtb_TmpSignalConversionAtMult_1 = 1.0F;

      /* Signum: '<S158>/Sign5' */
      rtb_Integrator1_m = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_1 = rtb_Ldot_err;

      /* Signum: '<S158>/Sign5' */
      rtb_Integrator1_m = rtb_Ldot_err;
    }

    /* End of Signum: '<S158>/Sign6' */

    /* Sum: '<S158>/Add6' */
    rtb_Sum1_g = rtb_Ldot_err + Controller_ConstB.d_i;

    /* Sum: '<S158>/Subtract3' */
    rtb_TmpSignalConversionAtMult_0 = rtb_Ldot_err - Controller_ConstB.d_i;

    /* Signum: '<S158>/Sign3' */
    if (rtb_Sum1_g < 0.0F) {
      rtb_Sum1_g = -1.0F;
    } else {
      if (rtb_Sum1_g > 0.0F) {
        rtb_Sum1_g = 1.0F;
      }
    }

    /* End of Signum: '<S158>/Sign3' */

    /* Signum: '<S158>/Sign4' */
    if (rtb_TmpSignalConversionAtMult_0 < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else {
      if (rtb_TmpSignalConversionAtMult_0 > 0.0F) {
        rtb_TmpSignalConversionAtMult_0 = 1.0F;
      }
    }

    /* End of Signum: '<S158>/Sign4' */

    /* Update for DiscreteIntegrator: '<S157>/Integrator' incorporates:
     *  Constant: '<S158>/const'
     *  Gain: '<S158>/Gain3'
     *  Product: '<S158>/Divide'
     *  Product: '<S158>/Multiply5'
     *  Product: '<S158>/Multiply6'
     *  Sum: '<S158>/Subtract4'
     *  Sum: '<S158>/Subtract5'
     *  Sum: '<S158>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE_j += ((rtb_Ldot_err / Controller_ConstB.d_i
      - rtb_Integrator1_m) * Controller_ConstB.Gain4_p * ((rtb_Sum1_g -
      rtb_TmpSignalConversionAtMult_0) * 0.5F) - rtb_TmpSignalConversionAtMult_1
      * 78.448F) * 0.002F;

    /* End of Outputs for SubSystem: '<S2>/MC_Controller' */
    break;
  }

  /* End of SwitchCase: '<S8>/Switch Case1' */

  /* Outputs for Atomic SubSystem: '<S6>/VTOL_Control_Allocation' */
#if AIRFRAME == 1

  /* Output and update for atomic system: '<S164>/VTOL1' */
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

    /* Saturate: '<S168>/Saturation1' */
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

    /* End of Saturate: '<S168>/Saturation1' */

    /* Gain: '<S168>/Gain1' incorporates:
     *  Bias: '<S168>/Bias'
     *  Constant: '<S168>/Constant'
     */
    rtb_Gain1_l = ((real32_T)CONTROL_PARAM.MC_OUT_MAX + -1000.0F) * 0.001F;

    /* Saturate: '<S168>/Saturation2' */
    if (Controller_B.mc_force_cmd[2] > 1.0F) {
      rtb_Saturation3 = 1.0F;
    } else if (Controller_B.mc_force_cmd[2] < 0.0F) {
      rtb_Saturation3 = 0.0F;
    } else {
      rtb_Saturation3 = Controller_B.mc_force_cmd[2];
    }

    /* End of Saturate: '<S168>/Saturation2' */
    for (i_p = 0; i_p < 4; i_p++) {
      /* Product: '<S168>/Multiply' */
      rtb_Switch_gr_idx_1_p = Controller_ConstB.VTOL1.pq_column[i_p + 4] *
        rtb_Saturation1_l_idx_1_p + Controller_ConstB.VTOL1.pq_column[i_p] *
        rtb_Saturation1_l_idx_0_p;

      /* Sum: '<S168>/Sum' */
      rtb_Sum_e[i_p] = rtb_Switch_gr_idx_1_p + rtb_Saturation3;

      /* Product: '<S168>/Multiply' */
      rtb_Saturation4[i_p] = rtb_Switch_gr_idx_1_p;
    }

    /* Gain: '<S168>/Gain2' incorporates:
     *  Bias: '<S168>/Bias1'
     *  Constant: '<S168>/Constant1'
     */
    rtb_Saturation1_l_idx_0_p = ((real32_T)CONTROL_PARAM.MC_OUT_MIN + -1000.0F) *
      0.001F;

    /* MinMax: '<S168>/Max' */
    rtb_Switch_gr_idx_1_p = fmaxf(fmaxf(fmaxf(rtb_Sum_e[0], rtb_Sum_e[1]),
      rtb_Sum_e[2]), rtb_Sum_e[3]);

    /* MinMax: '<S168>/Max1' */
    b_max_p = fminf(fminf(fminf(rtb_Sum_e[0], rtb_Sum_e[1]), rtb_Sum_e[2]),
                    rtb_Sum_e[3]);

    /* Switch: '<S175>/Switch' incorporates:
     *  Logic: '<S175>/Logical Operator'
     *  MinMax: '<S168>/Max'
     *  MinMax: '<S168>/Max1'
     *  RelationalOperator: '<S175>/Relational Operator'
     *  RelationalOperator: '<S175>/Relational Operator1'
     */
    if ((rtb_Switch_gr_idx_1_p > rtb_Gain1_l) || (b_max_p <
         rtb_Saturation1_l_idx_0_p)) {
      /* Sum: '<S175>/Subtract1' */
      rtb_Saturation1_l_idx_1_p = rtb_Gain1_l - rtb_Saturation1_l_idx_0_p;

      /* Sum: '<S175>/Subtract' */
      rtb_Subtract_h = rtb_Switch_gr_idx_1_p - b_max_p;

      /* Switch: '<S175>/Switch1' incorporates:
       *  Constant: '<S175>/Constant3'
       *  Gain: '<S175>/Gain'
       *  Product: '<S175>/Divide'
       *  RelationalOperator: '<S175>/Relational Operator2'
       *  Sum: '<S175>/Add'
       *  Sum: '<S175>/Subtract2'
       *  Sum: '<S175>/Subtract3'
       */
      if (rtb_Subtract_h > rtb_Saturation1_l_idx_1_p) {
        rtb_Saturation1_l_idx_1_p /= rtb_Subtract_h;
        rtb_Switch_gr_idx_1_p = ((rtb_Gain1_l - rtb_Switch_gr_idx_1_p) +
          (rtb_Saturation1_l_idx_0_p - b_max_p)) * 0.5F;
      } else {
        rtb_Saturation1_l_idx_1_p = 1.0F;

        /* Switch: '<S175>/Switch2' incorporates:
         *  Constant: '<S175>/Constant3'
         *  RelationalOperator: '<S175>/Relational Operator3'
         *  Sum: '<S175>/Subtract4'
         *  Sum: '<S175>/Subtract5'
         */
        if (rtb_Switch_gr_idx_1_p > rtb_Gain1_l) {
          rtb_Switch_gr_idx_1_p = rtb_Gain1_l - rtb_Switch_gr_idx_1_p;
        } else {
          rtb_Switch_gr_idx_1_p = rtb_Saturation1_l_idx_0_p - b_max_p;
        }

        /* End of Switch: '<S175>/Switch2' */
      }

      /* End of Switch: '<S175>/Switch1' */
    } else {
      rtb_Saturation1_l_idx_1_p = 1.0F;
      rtb_Switch_gr_idx_1_p = 0.0F;
    }

    /* End of Switch: '<S175>/Switch' */

    /* Sum: '<S168>/Sum1' */
    rtb_Saturation3 += rtb_Switch_gr_idx_1_p;

    /* Saturate: '<S168>/Saturation3' */
    if (rtb_Saturation3 > 1.0F) {
      rtb_Saturation3 = 1.0F;
    } else {
      if (rtb_Saturation3 < 0.0F) {
        rtb_Saturation3 = 0.0F;
      }
    }

    /* End of Saturate: '<S168>/Saturation3' */

    /* MATLAB Function: '<S168>/R_Remix' */
    rtb_Subtract_h = 100.0F;
    b_max_p = -100.0F;
    i_p = 0;
    max_index_p = 0;

    /* Sum: '<S168>/Sum2' incorporates:
     *  Product: '<S168>/Multiply1'
     */
    rtb_Switch_gr_idx_1_p = rtb_Saturation4[0] * rtb_Saturation1_l_idx_1_p +
      rtb_Saturation3;

    /* Saturate: '<S168>/Saturation4' */
    if (rtb_Switch_gr_idx_1_p > 1.0F) {
      rtb_Switch_gr_idx_1_p = 1.0F;
    } else {
      if (rtb_Switch_gr_idx_1_p < 0.0F) {
        rtb_Switch_gr_idx_1_p = 0.0F;
      }
    }

    /* Sum: '<S168>/Sum3' incorporates:
     *  Product: '<S168>/Multiply2'
     */
    rtb_Switch_gr_idx_1_p += Controller_ConstB.VTOL1.r_column[0] *
      rtb_Saturation1_l_idx_2_p;

    /* MATLAB Function: '<S168>/R_Remix' */
    if (rtb_Switch_gr_idx_1_p < 100.0F) {
      rtb_Subtract_h = rtb_Switch_gr_idx_1_p;
      i_p = 1;
    }

    if (rtb_Switch_gr_idx_1_p > -100.0F) {
      b_max_p = rtb_Switch_gr_idx_1_p;
      max_index_p = 1;
    }

    /* Product: '<S168>/Multiply1' */
    rtb_Saturation4[0] = rtb_Switch_gr_idx_1_p;

    /* Sum: '<S168>/Sum2' incorporates:
     *  Product: '<S168>/Multiply1'
     */
    rtb_Switch_gr_idx_1_p = rtb_Saturation4[1] * rtb_Saturation1_l_idx_1_p +
      rtb_Saturation3;

    /* Saturate: '<S168>/Saturation4' */
    if (rtb_Switch_gr_idx_1_p > 1.0F) {
      rtb_Switch_gr_idx_1_p = 1.0F;
    } else {
      if (rtb_Switch_gr_idx_1_p < 0.0F) {
        rtb_Switch_gr_idx_1_p = 0.0F;
      }
    }

    /* Sum: '<S168>/Sum3' incorporates:
     *  Product: '<S168>/Multiply2'
     */
    rtb_Switch_gr_idx_1_p += Controller_ConstB.VTOL1.r_column[1] *
      rtb_Saturation1_l_idx_2_p;

    /* MATLAB Function: '<S168>/R_Remix' */
    if (rtb_Switch_gr_idx_1_p < rtb_Subtract_h) {
      rtb_Subtract_h = rtb_Switch_gr_idx_1_p;
      i_p = 2;
    }

    if (rtb_Switch_gr_idx_1_p > b_max_p) {
      b_max_p = rtb_Switch_gr_idx_1_p;
      max_index_p = 2;
    }

    /* Product: '<S168>/Multiply1' */
    rtb_Saturation4[1] = rtb_Switch_gr_idx_1_p;

    /* Sum: '<S168>/Sum2' incorporates:
     *  Product: '<S168>/Multiply1'
     */
    rtb_Switch_gr_idx_1_p = rtb_Saturation4[2] * rtb_Saturation1_l_idx_1_p +
      rtb_Saturation3;

    /* Saturate: '<S168>/Saturation4' */
    if (rtb_Switch_gr_idx_1_p > 1.0F) {
      rtb_Switch_gr_idx_1_p = 1.0F;
    } else {
      if (rtb_Switch_gr_idx_1_p < 0.0F) {
        rtb_Switch_gr_idx_1_p = 0.0F;
      }
    }

    /* Sum: '<S168>/Sum3' incorporates:
     *  Product: '<S168>/Multiply2'
     */
    rtb_Switch_gr_idx_1_p += Controller_ConstB.VTOL1.r_column[2] *
      rtb_Saturation1_l_idx_2_p;

    /* MATLAB Function: '<S168>/R_Remix' */
    if (rtb_Switch_gr_idx_1_p < rtb_Subtract_h) {
      rtb_Subtract_h = rtb_Switch_gr_idx_1_p;
      i_p = 3;
    }

    if (rtb_Switch_gr_idx_1_p > b_max_p) {
      b_max_p = rtb_Switch_gr_idx_1_p;
      max_index_p = 3;
    }

    /* Product: '<S168>/Multiply1' */
    rtb_Saturation4[2] = rtb_Switch_gr_idx_1_p;

    /* Sum: '<S168>/Sum2' incorporates:
     *  Product: '<S168>/Multiply1'
     */
    rtb_Switch_gr_idx_1_p = rtb_Saturation4[3] * rtb_Saturation1_l_idx_1_p +
      rtb_Saturation3;

    /* Saturate: '<S168>/Saturation4' */
    if (rtb_Switch_gr_idx_1_p > 1.0F) {
      rtb_Switch_gr_idx_1_p = 1.0F;
    } else {
      if (rtb_Switch_gr_idx_1_p < 0.0F) {
        rtb_Switch_gr_idx_1_p = 0.0F;
      }
    }

    /* Sum: '<S168>/Sum3' incorporates:
     *  Product: '<S168>/Multiply2'
     */
    rtb_Switch_gr_idx_1_p += Controller_ConstB.VTOL1.r_column[3] *
      rtb_Saturation1_l_idx_2_p;

    /* MATLAB Function: '<S168>/R_Remix' */
    if (rtb_Switch_gr_idx_1_p < rtb_Subtract_h) {
      rtb_Subtract_h = rtb_Switch_gr_idx_1_p;
      i_p = 4;
    }

    if (rtb_Switch_gr_idx_1_p > b_max_p) {
      b_max_p = rtb_Switch_gr_idx_1_p;
      max_index_p = 4;
    }

    /* Product: '<S168>/Multiply1' */
    rtb_Saturation4[3] = rtb_Switch_gr_idx_1_p;

    /* MATLAB Function: '<S168>/R_Remix' */
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

    /* MultiPortSwitch: '<S171>/Multiport Switch' incorporates:
     *  Constant: '<S172>/Constant1'
     *  Constant: '<S172>/Constant12'
     *  Constant: '<S172>/Constant2'
     *  Constant: '<S172>/Constant7'
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
         *  Constant: '<S182>/Standby'
         *  Reshape: '<S182>/Reshape'
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

      /* Saturate: '<S182>/Saturation' incorporates:
       *  Bias: '<S182>/Bias'
       *  Constant: '<S182>/Constant'
       *  DataTypeConversion: '<S182>/Data Type Conversion'
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

      /* Saturate: '<S182>/Saturation' incorporates:
       *  Bias: '<S182>/Bias1'
       *  Constant: '<S182>/Constant'
       *  DataTypeConversion: '<S182>/Data Type Conversion'
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

      /* Saturate: '<S182>/Saturation' incorporates:
       *  Bias: '<S182>/Bias2'
       *  Constant: '<S182>/Constant'
       *  DataTypeConversion: '<S182>/Data Type Conversion'
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

      /* Saturate: '<S182>/Saturation' incorporates:
       *  Bias: '<S182>/Bias3'
       *  Constant: '<S182>/Constant'
       *  DataTypeConversion: '<S182>/Data Type Conversion'
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

      /* SignalConversion: '<S172>/ConcatBufferAtVector Concatenate2In3' incorporates:
       *  Constant: '<S172>/Constant11'
       *  Constant: '<S172>/Constant12'
       */
      rtb_MatrixConcatenate[10] = 0.0F;

      /* SignalConversion: '<S172>/ConcatBufferAtVector Concatenate2In2' incorporates:
       *  Constant: '<S172>/Constant10'
       */
      rtb_MatrixConcatenate[9] = 0.0F;

      /* SignalConversion: '<S172>/ConcatBufferAtVector Concatenate2In1' incorporates:
       *  Constant: '<S172>/Constant9'
       */
      rtb_MatrixConcatenate[8] = 0.0F;

      /* SignalConversion: '<S172>/ConcatBufferAtVector Concatenate1In4' incorporates:
       *  Constant: '<S172>/Constant8'
       */
      rtb_MatrixConcatenate[7] = 0.0F;
      rtb_MatrixConcatenate[6] = CONTROL_PARAM.FW_PITCH_EFFC *
        CONTROL_PARAM.FW_ELEVATOR_DIR;

      /* SignalConversion: '<S172>/ConcatBufferAtVector Concatenate1In2' incorporates:
       *  Constant: '<S172>/Constant6'
       *  Constant: '<S172>/Constant7'
       */
      rtb_MatrixConcatenate[5] = 0.0F;

      /* SignalConversion: '<S172>/ConcatBufferAtVector Concatenate1In1' incorporates:
       *  Constant: '<S172>/Constant5'
       */
      rtb_MatrixConcatenate[4] = 0.0F;

      /* SignalConversion: '<S172>/ConcatBufferAtVector ConcatenateIn4' incorporates:
       *  Constant: '<S172>/Constant4'
       */
      rtb_MatrixConcatenate[3] = 0.0F;

      /* SignalConversion: '<S172>/ConcatBufferAtVector ConcatenateIn3' incorporates:
       *  Constant: '<S172>/Constant3'
       */
      rtb_MatrixConcatenate[2] = 0.0F;
      rtb_MatrixConcatenate[1] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON2_DIR;
      rtb_MatrixConcatenate[0] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON1_DIR;

      /* Saturate: '<S167>/Saturation5' incorporates:
       *  Constant: '<S172>/Constant1'
       *  Constant: '<S172>/Constant2'
       */
      if (Controller_B.fw_torque_cmd[0] > 1.0F) {
        /* Product: '<S167>/Multiply1' */
        rtb_Gain1_l = 1.0F;
      } else if (Controller_B.fw_torque_cmd[0] < -1.0F) {
        /* Product: '<S167>/Multiply1' */
        rtb_Gain1_l = -1.0F;
      } else {
        /* Product: '<S167>/Multiply1' */
        rtb_Gain1_l = Controller_B.fw_torque_cmd[0];
      }

      if (Controller_B.fw_torque_cmd[1] > 1.0F) {
        /* Product: '<S167>/Multiply1' */
        rtb_Saturation1_l_idx_2_p = 1.0F;
      } else if (Controller_B.fw_torque_cmd[1] < -1.0F) {
        /* Product: '<S167>/Multiply1' */
        rtb_Saturation1_l_idx_2_p = -1.0F;
      } else {
        /* Product: '<S167>/Multiply1' */
        rtb_Saturation1_l_idx_2_p = Controller_B.fw_torque_cmd[1];
      }

      if (Controller_B.fw_torque_cmd[2] > 1.0F) {
        /* Product: '<S167>/Multiply1' */
        rtb_Saturation3 = 1.0F;
      } else if (Controller_B.fw_torque_cmd[2] < -1.0F) {
        /* Product: '<S167>/Multiply1' */
        rtb_Saturation3 = -1.0F;
      } else {
        /* Product: '<S167>/Multiply1' */
        rtb_Saturation3 = Controller_B.fw_torque_cmd[2];
      }

      /* End of Saturate: '<S167>/Saturation5' */
      for (i_p = 0; i_p < 4; i_p++) {
        /* Bias: '<S167>/Bias' incorporates:
         *  Gain: '<S167>/Gain1'
         *  Product: '<S167>/Multiply1'
         */
        rtb_Saturation5_o[i_p] = 500.0F * (rtb_MatrixConcatenate[i_p + 8] *
          rtb_Saturation3 + (rtb_MatrixConcatenate[i_p + 4] *
                             rtb_Saturation1_l_idx_2_p +
                             rtb_MatrixConcatenate[i_p] * rtb_Gain1_l)) +
          1500.0F;

        /* Sum: '<S168>/Sum4' */
        rtb_Saturation1_l_idx_0_p = rtb_Saturation4[i_p] + rtb_Sum_e[i_p];

        /* Saturate: '<S168>/Saturation5' */
        if (rtb_Saturation1_l_idx_0_p > 1.0F) {
          rtb_Saturation1_l_idx_0_p = 1.0F;
        } else {
          if (rtb_Saturation1_l_idx_0_p < 0.0F) {
            rtb_Saturation1_l_idx_0_p = 0.0F;
          }
        }

        /* End of Saturate: '<S168>/Saturation5' */

        /* DataTypeConversion: '<S168>/Data Type Conversion' incorporates:
         *  Constant: '<S168>/Constant2'
         *  Gain: '<S168>/Gain3'
         *  Sum: '<S168>/Sum5'
         */
        u0_p = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          rtb_Saturation1_l_idx_0_p), 4.2949673E+9F) + 1000U);

        /* Saturate: '<S168>/Saturation' */
        if (u0_p > CONTROL_PARAM.MC_OUT_MAX) {
          rtb_VariantMergeForOutportactua[i_p] = CONTROL_PARAM.MC_OUT_MAX;
        } else if (u0_p < CONTROL_PARAM.MC_OUT_MIN) {
          rtb_VariantMergeForOutportactua[i_p] = CONTROL_PARAM.MC_OUT_MIN;
        } else {
          rtb_VariantMergeForOutportactua[i_p] = u0_p;
        }

        /* End of Saturate: '<S168>/Saturation' */
      }

      /* Saturate: '<S167>/Saturation' */
      if (Controller_B.fw_force_cmd[0] > 1.0F) {
        rtb_Gain1_l = 1.0F;
      } else if (Controller_B.fw_force_cmd[0] < 0.0F) {
        rtb_Gain1_l = 0.0F;
      } else {
        rtb_Gain1_l = Controller_B.fw_force_cmd[0];
      }

      /* End of Saturate: '<S167>/Saturation' */

      /* DataTypeConversion: '<S174>/Data Type Conversion' incorporates:
       *  Constant: '<S174>/Constant1'
       *  Gain: '<S174>/Gain1'
       *  Sum: '<S174>/Sum1'
       */
      u0_p = (uint16_T)((uint32_T)fmodf(floorf(1000.0F * rtb_Gain1_l),
        4.2949673E+9F) + 1000U);

      /* Saturate: '<S167>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[4] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[4] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[4] = u0_p;
      }

      /* DataTypeConversion: '<S167>/Data Type Conversion' incorporates:
       *  Bias: '<S167>/Bias1'
       */
      rtb_Gain1_l = fmodf(floorf(rtb_Saturation5_o[0] +
        CONTROL_PARAM.SERVO1_BIAS), 65536.0F);
      u0_p = (uint16_T)(rtb_Gain1_l < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                        (uint16_T)-rtb_Gain1_l : (int32_T)(uint16_T)rtb_Gain1_l);

      /* Saturate: '<S167>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[5] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[5] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[5] = u0_p;
      }

      /* DataTypeConversion: '<S167>/Data Type Conversion1' incorporates:
       *  Bias: '<S167>/Bias2'
       */
      rtb_Gain1_l = fmodf(floorf(rtb_Saturation5_o[1] +
        CONTROL_PARAM.SERVO2_BIAS), 65536.0F);
      u0_p = (uint16_T)(rtb_Gain1_l < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                        (uint16_T)-rtb_Gain1_l : (int32_T)(uint16_T)rtb_Gain1_l);

      /* Saturate: '<S167>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[6] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[6] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[6] = u0_p;
      }

      /* DataTypeConversion: '<S167>/Data Type Conversion2' incorporates:
       *  Bias: '<S167>/Bias3'
       */
      rtb_Gain1_l = fmodf(floorf(rtb_Saturation5_o[2] +
        CONTROL_PARAM.SERVO3_BIAS), 65536.0F);
      u0_p = (uint16_T)(rtb_Gain1_l < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                        (uint16_T)-rtb_Gain1_l : (int32_T)(uint16_T)rtb_Gain1_l);

      /* Saturate: '<S167>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[7] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[7] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[7] = u0_p;
      }

      /* DataTypeConversion: '<S167>/Data Type Conversion3' incorporates:
       *  Bias: '<S167>/Bias4'
       */
      rtb_Gain1_l = fmodf(floorf(rtb_Saturation5_o[3] +
        CONTROL_PARAM.SERVO4_BIAS), 65536.0F);
      u0_p = (uint16_T)(rtb_Gain1_l < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                        (uint16_T)-rtb_Gain1_l : (int32_T)(uint16_T)rtb_Gain1_l);

      /* Saturate: '<S167>/Saturation1' */
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

    /* End of MultiPortSwitch: '<S171>/Multiport Switch' */
  }

#elif AIRFRAME == 2

  /* Output and update for atomic system: '<S164>/VTOL2' */
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

        /* End of Saturate: '<S184>/Saturation' */
      }

      /* End of Product: '<S184>/Multiply' */
      for (i_o = 0; i_o < 5; i_o++) {
        /* Saturate: '<S183>/Saturation1' */
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

    /* End of MultiPortSwitch: '<S185>/Multiport Switch' */
  }

#endif

  /* End of Outputs for SubSystem: '<S6>/VTOL_Control_Allocation' */

  /* Outport: '<Root>/Control_Out' incorporates:
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   *  Reshape: '<S163>/Reshape'
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
  /* Start for Constant: '<S46>/Constant' */
  Controller_B.Constant_m = CONTROL_PARAM.MC_VEL_Z_I_MIN;

  /* End of Start for SubSystem: '<S2>/FW_Controller' */

  /* Start for IfAction SubSystem: '<S2>/MC_Controller' */
  /* Start for Constant: '<S160>/Constant' */
  Controller_B.Constant = CONTROL_PARAM.MC_VEL_Z_I_MIN;

  /* End of Start for SubSystem: '<S2>/MC_Controller' */

  /* SystemInitialize for IfAction SubSystem: '<S2>/FW_Controller' */
  /* InitializeConditions for DiscreteIntegrator: '<S55>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_e = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S51>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_L_eo = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S49>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_g = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S50>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_o = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' */

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

  /* InitializeConditions for DiscreteIntegrator: '<S23>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_b = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S27>/Discrete-Time Integrator1' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S52>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_c = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S43>/Integrator1' */
  Controller_DW.Integrator1_DSTATE_i = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S46>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S46>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S48>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_i = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_h = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S73>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_PrevR_ef = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S43>/Integrator' */
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
  /* InitializeConditions for DiscreteIntegrator: '<S117>/Discrete-Time Integrator' */
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
  /* InitializeConditions for DiscreteIntegrator: '<S117>/Discrete-Time Integrator' */
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
  /* InitializeConditions for DiscreteIntegrator: '<S117>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S144>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_PrevRe_p = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S146>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S115>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S119>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_k = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S139>/Integrator1' */
  Controller_DW.Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S144>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S139>/Integrator' */
  Controller_DW.Integrator_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S139>/Integrator1' */
  Controller_DW.Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S144>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S139>/Integrator' */
  Controller_DW.Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S157>/Integrator1' */
  Controller_DW.Integrator1_DSTATE_e = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S160>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S160>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S162>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 1U;
  Controller_DW.DiscreteTimeIntegrator1_Prev_ks = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S157>/Integrator' */
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
