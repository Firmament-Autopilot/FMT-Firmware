/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.221
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Aug 20 13:42:12 2024
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
struct_66Lz2XM6ObrCrxI96MstFF CONTROL_PARAM = {
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
  17.0F,
  0.2F,
  0.3F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  0.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
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
  0.25F,
  0.1F,
  0.1F,
  0.0F,
  0.0F,
  0.0F,
  0.0F
} ;                                    /* Variable: CONTROL_PARAM
                                        * Referenced by:
                                        *   '<S9>/mc_hover_throttle'
                                        *   '<S150>/mc_hover_throttle'
                                        *   '<S193>/Saturation'
                                        *   '<S194>/Gain'
                                        *   '<S194>/Gain1'
                                        *   '<S194>/balabnce_ratio2'
                                        *   '<S194>/balance_ratio'
                                        *   '<S194>/pitch_ff'
                                        *   '<S194>/thorttle_ff'
                                        *   '<S194>/ucmd2pitch'
                                        *   '<S194>/ucmd2thor'
                                        *   '<S194>/wcmd2pitch'
                                        *   '<S194>/wcmd2thor'
                                        *   '<S110>/Saturation'
                                        *   '<S130>/hover_throttle'
                                        *   '<S195>/FF'
                                        *   '<S195>/FF_limit'
                                        *   '<S195>/PI_limit'
                                        *   '<S214>/P_control'
                                        *   '<S215>/P_control'
                                        *   '<S38>/Saturation'
                                        *   '<S70>/Bias1'
                                        *   '<S70>/Bias2'
                                        *   '<S70>/Bias3'
                                        *   '<S70>/Bias4'
                                        *   '<S86>/Saturation'
                                        *   '<S86>/Saturation1'
                                        *   '<S119>/kd'
                                        *   '<S119>/Saturation'
                                        *   '<S120>/ki'
                                        *   '<S120>/Discrete-Time Integrator'
                                        *   '<S121>/kp'
                                        *   '<S140>/kd'
                                        *   '<S140>/Saturation'
                                        *   '<S141>/Constant'
                                        *   '<S141>/ki'
                                        *   '<S141>/Discrete-Time Integrator'
                                        *   '<S142>/kp'
                                        *   '<S155>/Saturation'
                                        *   '<S155>/Saturation1'
                                        *   '<S199>/trim_speed'
                                        *   '<S200>/trim_speed'
                                        *   '<S225>/Gain'
                                        *   '<S226>/ '
                                        *   '<S226>/Gain3'
                                        *   '<S228>/Gain'
                                        *   '<S229>/Gain'
                                        *   '<S251>/Bias1'
                                        *   '<S251>/Bias2'
                                        *   '<S251>/Bias3'
                                        *   '<S251>/Bias4'
                                        *   '<S18>/Saturation'
                                        *   '<S18>/Saturation1'
                                        *   '<S46>/kd'
                                        *   '<S46>/Saturation'
                                        *   '<S47>/ki'
                                        *   '<S47>/Discrete-Time Integrator'
                                        *   '<S48>/kp'
                                        *   '<S56>/kd'
                                        *   '<S56>/Saturation'
                                        *   '<S57>/Constant'
                                        *   '<S57>/ki'
                                        *   '<S57>/Discrete-Time Integrator'
                                        *   '<S58>/kp'
                                        *   '<S67>/Constant1'
                                        *   '<S67>/Constant12'
                                        *   '<S67>/Constant2'
                                        *   '<S67>/Constant7'
                                        *   '<S73>/Constant1'
                                        *   '<S73>/Constant11'
                                        *   '<S73>/Constant12'
                                        *   '<S73>/Constant2'
                                        *   '<S73>/Constant7'
                                        *   '<S73>/Constant8'
                                        *   '<S76>/Bias'
                                        *   '<S76>/Bias1'
                                        *   '<S76>/Bias2'
                                        *   '<S76>/Bias3'
                                        *   '<S77>/Bias'
                                        *   '<S77>/Bias1'
                                        *   '<S77>/Bias2'
                                        *   '<S77>/Bias3'
                                        *   '<S103>/Constant1'
                                        *   '<S103>/Constant2'
                                        *   '<S167>/Constant1'
                                        *   '<S167>/Constant2'
                                        *   '<S185>/kd'
                                        *   '<S185>/Saturation'
                                        *   '<S186>/Constant'
                                        *   '<S186>/ki'
                                        *   '<S186>/Discrete-Time Integrator'
                                        *   '<S187>/kp'
                                        *   '<S201>/gain1'
                                        *   '<S201>/gain2'
                                        *   '<S201>/gain3'
                                        *   '<S201>/Discrete-Time Integrator'
                                        *   '<S202>/gain1'
                                        *   '<S202>/gain2'
                                        *   '<S202>/gain3'
                                        *   '<S206>/Pitch Offset'
                                        *   '<S206>/Saturation'
                                        *   '<S207>/Constant1'
                                        *   '<S207>/Constant2'
                                        *   '<S246>/Constant1'
                                        *   '<S246>/Constant12'
                                        *   '<S246>/Constant2'
                                        *   '<S246>/Constant7'
                                        *   '<S254>/Constant1'
                                        *   '<S254>/Constant11'
                                        *   '<S254>/Constant12'
                                        *   '<S254>/Constant2'
                                        *   '<S254>/Constant7'
                                        *   '<S254>/Constant8'
                                        *   '<S259>/Bias'
                                        *   '<S259>/Bias1'
                                        *   '<S259>/Bias2'
                                        *   '<S259>/Bias3'
                                        *   '<S260>/Bias'
                                        *   '<S260>/Bias1'
                                        *   '<S260>/Bias2'
                                        *   '<S260>/Bias3'
                                        *   '<S33>/Constant1'
                                        *   '<S33>/Constant2'
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
                                        *   '<S160>/gain1'
                                        *   '<S160>/gain2'
                                        *   '<S160>/gain3'
                                        *   '<S160>/Saturation'
                                        *   '<S161>/gain1'
                                        *   '<S161>/gain2'
                                        *   '<S161>/gain3'
                                        *   '<S161>/Discrete-Time Integrator'
                                        *   '<S162>/gain1'
                                        *   '<S162>/gain2'
                                        *   '<S162>/gain3'
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
  real32_T rtb_Add_h[3];
  real32_T rtb_Saturation_hi;
  real32_T rtb_Saturation1[3];
  real32_T rtb_Saturation2[3];
  real32_T rtb_Saturation1_f[3];
  real32_T rtb_Saturation2_l[3];
  uint16_T rtb_VariantMergeForOutportactua[9];
  uint16_T rtb_VariantMergeForOutportact_h[9];
  uint8_T rtb_BitwiseAND_a;
  int8_T rtPrevAction;
  real32_T rtb_Divide_gn;
  real32_T rtb_Saturation_ov;
  int32_T rtb_Relay;
  real32_T rtb_Gain_ms;
  boolean_T rtb_LogicalOperator_b3;
  real32_T rtb_Gain_it;
  real32_T rtb_Cos_j;
  real32_T rtb_Cos1_d;
  real32_T rtb_Add_c;
  real32_T rtb_Abs;
  real32_T rtb_Saturation1_ih;
  real32_T rtb_MatrixConcatenate1[9];
  real32_T rtb_DiscreteTimeIntegrator1_k1[3];
  real32_T rtb_VdotPg;
  real32_T rtb_Sum;
  real32_T rtb_Minus;
  real32_T rtb_B_err;
  real32_T rtb_Gain_il;
  real32_T rtb_Add2_h;
  real32_T rtb_DiscreteTimeIntegrator1_g;
  boolean_T rtb_LogicalOperator_m;
  real32_T rtb_u;
  real32_T rtb_Gain_cu;
  uint16_T rtb_throttle_cmd;
  uint16_T rtb_MultiportSwitch[4];
  int32_T i;
  real32_T rtb_MatrixConcatenate1_0[3];
  real32_T rtb_FF_limit_idx_1;
  real32_T rtb_FF_limit_idx_2;
  real32_T rtb_Divide_i_idx_0;
  real32_T rtb_Divide_i_idx_1;
  real32_T rtb_Divide_i_idx_2;
  real32_T rtb_Divide_i_idx_3;
  real32_T rtb_Saturation1_h_idx_0;
  real32_T rtb_Multiply_ga_idx_0;
  real32_T u0;
  uint16_T u0_0;
  real32_T rtb_MatrixConcatenate1_tmp;

  /* S-Function (sfix_bitop): '<S7>/Bitwise AND' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  rtb_BitwiseAND_a = (uint8_T)(Controller_U.FMS_Out.ctrl_mode & 63);

  /* SwitchCase: '<S8>/Switch Case1' incorporates:
   *  Constant: '<S141>/Constant'
   *  Constant: '<S186>/Constant'
   *  Constant: '<S57>/Constant'
   *  DataTypeConversion: '<S8>/Data Type Conversion'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S105>/Divide1'
   *  Product: '<S119>/Multiply'
   *  Product: '<S160>/Multiply'
   *  Product: '<S169>/Divide1'
   *  Product: '<S24>/Multiply'
   *  Product: '<S8>/Divide'
   *  S-Function (sfix_bitop): '<S8>/Bitwise AND'
   */
  rtPrevAction = Controller_DW.SwitchCase1_ActiveSubsystem;
  switch ((int32_T)(uint8_T)((uint32_T)(Controller_U.FMS_Out.ctrl_mode & 192) >>
           6)) {
   case VTOLState_Fixwing:
    Controller_DW.SwitchCase1_ActiveSubsystem = 0;
    break;

   case VTOLState_BackTrans:
    Controller_DW.SwitchCase1_ActiveSubsystem = 1;
    break;

   default:
    Controller_DW.SwitchCase1_ActiveSubsystem = 2;
    break;
  }

  switch (Controller_DW.SwitchCase1_ActiveSubsystem) {
   case 0:
    if (Controller_DW.SwitchCase1_ActiveSubsystem != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S2>/VTOL_Controller' incorporates:
       *  ActionPort: '<S6>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S8>/Switch Case1' incorporates:
       *  DiscreteIntegrator: '<S159>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S161>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S163>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S183>/Integrator'
       *  DiscreteIntegrator: '<S183>/Integrator1'
       *  DiscreteIntegrator: '<S186>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S188>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S189>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S190>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S191>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S201>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S226>/ '
       *  DiscreteIntegrator: '<S227>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S229>/ '
       *  DiscreteIntegrator: '<S230>/Discrete-Time Integrator1'
       */
      Controller_DW.DiscreteTimeIntegrator5_IC_L_eo = 1U;
      Controller_DW.DiscreteTimeIntegrator5_IC_LO_o = 1U;
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
      Controller_DW.DiscreteTimeIntegrator_PrevRe_o = 0;
      Controller_DW.DiscreteTimeIntegrator1_IC_L_h2 = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevR_l = 0;
      Controller_DW.DiscreteTimeIntegrator5_IC_LO_g = 1U;
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
      Controller_DW._DSTATE_d = Controller_ConstB.Zero;
      if (Controller_DW._DSTATE_d >= 0.3F) {
        Controller_DW._DSTATE_d = 0.3F;
      } else {
        if (Controller_DW._DSTATE_d <= -0.3F) {
          Controller_DW._DSTATE_d = -0.3F;
        }
      }

      Controller_DW._PrevResetState_e = 0;
      Controller_DW.DiscreteTimeIntegrator1_IC_L_h0 = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevR_d = 0;
      Controller_DW.Integrator_DSTATE_f = 0.0F;

      /* End of InitializeConditions for SubSystem: '<S2>/VTOL_Controller' */
    }

    /* Outputs for IfAction SubSystem: '<S2>/VTOL_Controller' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    /* Product: '<S145>/Divide' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Math: '<S145>/Square'
     */
    rtb_Divide_gn = Controller_U.INS_Out.airspeed *
      Controller_U.INS_Out.airspeed / Controller_ConstB.Square1;

    /* DiscreteIntegrator: '<S191>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_L_eo != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_a = rtb_Divide_gn;
    }

    /* Saturate: '<S145>/Saturation' */
    if (Controller_DW.DiscreteTimeIntegrator5_DSTAT_a > 1.0F) {
      rtb_Saturation_ov = 1.0F;
    } else if (Controller_DW.DiscreteTimeIntegrator5_DSTAT_a < 0.0F) {
      rtb_Saturation_ov = 0.0F;
    } else {
      rtb_Saturation_ov = Controller_DW.DiscreteTimeIntegrator5_DSTAT_a;
    }

    /* End of Saturate: '<S145>/Saturation' */

    /* Relay: '<S145>/Relay' */
    if (rtb_Saturation_ov >= 0.95F) {
      Controller_DW.Relay_Mode = true;
    } else {
      if (rtb_Saturation_ov <= 0.85F) {
        Controller_DW.Relay_Mode = false;
      }
    }

    rtb_Relay = !Controller_DW.Relay_Mode;

    /* End of Relay: '<S145>/Relay' */

    /* DiscreteIntegrator: '<S190>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_o != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTA_a2 = (real32_T)rtb_Relay;
    }

    /* Gain: '<S181>/Gain' incorporates:
     *  DiscreteIntegrator: '<S183>/Integrator1'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S181>/Sum1'
     */
    rtb_Gain_ms = -(Controller_DW.Integrator1_DSTATE_i - Controller_U.INS_Out.vd);

    /* Logic: '<S178>/Logical Operator' incorporates:
     *  Constant: '<S180>/Constant'
     *  DiscreteIntegrator: '<S190>/Discrete-Time Integrator5'
     *  RelationalOperator: '<S180>/Compare'
     */
    rtb_LogicalOperator_b3 = ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator5_DSTA_a2 == 0.0F));
    Controller_B.Constant_m = CONTROL_PARAM.MC_VEL_Z_I_MIN;

    /* DiscreteIntegrator: '<S186>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S186>/Constant'
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

    /* DiscreteIntegrator: '<S188>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_i != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTA_ld = rtb_Gain_ms;
    }

    if (rtb_LogicalOperator_b3 || (Controller_DW.DiscreteTimeIntegrator1_PrevR_h
         != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTA_ld = rtb_Gain_ms;
    }

    /* Gain: '<S188>/Gain' incorporates:
     *  DiscreteIntegrator: '<S188>/Discrete-Time Integrator1'
     *  Sum: '<S188>/Sum5'
     */
    rtb_Gain_it = (rtb_Gain_ms - Controller_DW.DiscreteTimeIntegrator1_DSTA_ld) *
      62.831852F;

    /* Switch: '<S188>/Switch' incorporates:
     *  Gain: '<S188>/Gain1'
     */
    if (rtb_LogicalOperator_b3) {
      rtb_Add_c = 0.0F;
    } else {
      rtb_Add_c = rtb_Gain_it;
    }

    /* End of Switch: '<S188>/Switch' */

    /* Product: '<S185>/Multiply' incorporates:
     *  Constant: '<S185>/kd'
     */
    rtb_Cos_j = CONTROL_PARAM.MC_VEL_Z_D * rtb_Add_c;

    /* Saturate: '<S185>/Saturation' */
    if (rtb_Cos_j > CONTROL_PARAM.MC_VEL_Z_D_MAX) {
      rtb_Cos_j = CONTROL_PARAM.MC_VEL_Z_D_MAX;
    } else {
      if (rtb_Cos_j < CONTROL_PARAM.MC_VEL_Z_D_MIN) {
        rtb_Cos_j = CONTROL_PARAM.MC_VEL_Z_D_MIN;
      }
    }

    /* End of Saturate: '<S185>/Saturation' */

    /* Sum: '<S182>/Add' incorporates:
     *  Constant: '<S187>/kp'
     *  DiscreteIntegrator: '<S186>/Discrete-Time Integrator'
     *  Product: '<S187>/Multiply'
     */
    rtb_Add_c = (CONTROL_PARAM.MC_VEL_Z_P * rtb_Gain_ms +
                 Controller_DW.DiscreteTimeIntegrator_DSTATE_b) + rtb_Cos_j;

    /* Trigonometry: '<S179>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S164>/Cos1'
     *  Trigonometry: '<S197>/Cos1'
     */
    rtb_Gain_cu = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Trigonometry: '<S179>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S164>/Cos'
     *  Trigonometry: '<S197>/Cos'
     */
    rtb_Multiply_ga_idx_0 = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Product: '<S179>/Multiply' incorporates:
     *  Trigonometry: '<S179>/Cos'
     *  Trigonometry: '<S179>/Cos1'
     */
    rtb_FF_limit_idx_1 = rtb_Multiply_ga_idx_0 * rtb_Gain_cu;

    /* Saturate: '<S179>/Saturation1' incorporates:
     *  Product: '<S179>/Multiply'
     */
    if (rtb_FF_limit_idx_1 > 1.0F) {
      rtb_Cos1_d = 1.0F;
    } else if (rtb_FF_limit_idx_1 < 0.5F) {
      rtb_Cos1_d = 0.5F;
    } else {
      rtb_Cos1_d = rtb_FF_limit_idx_1;
    }

    /* End of Saturate: '<S179>/Saturation1' */

    /* Gain: '<S179>/Gain' incorporates:
     *  Product: '<S179>/Multiply'
     */
    rtb_Cos_j = 2.0F * rtb_FF_limit_idx_1;

    /* Saturate: '<S179>/Saturation' */
    if (rtb_Cos_j > 1.0F) {
      rtb_Cos_j = 1.0F;
    } else {
      if (rtb_Cos_j < 0.0F) {
        rtb_Cos_j = 0.0F;
      }
    }

    /* End of Saturate: '<S179>/Saturation' */

    /* Product: '<S179>/Multiply1' incorporates:
     *  Constant: '<S179>/Constant'
     *  Product: '<S179>/Divide'
     */
    rtb_Cos_j *= 1.0F / rtb_Cos1_d * rtb_Add_c;

    /* Saturate: '<S178>/Saturation' */
    if (rtb_Cos_j > 0.35F) {
      rtb_Cos_j = 0.35F;
    } else {
      if (rtb_Cos_j < -0.35F) {
        rtb_Cos_j = -0.35F;
      }
    }

    /* End of Saturate: '<S178>/Saturation' */

    /* Sum: '<S150>/Sum' incorporates:
     *  Constant: '<S150>/mc_hover_throttle'
     */
    rtb_Cos_j += CONTROL_PARAM.MC_HOVER_THRO;

    /* Saturate: '<S150>/Saturation' */
    if (rtb_Cos_j > 1.0F) {
      rtb_Cos_j = 1.0F;
    } else {
      if (rtb_Cos_j < -1.0F) {
        rtb_Cos_j = -1.0F;
      }
    }

    /* End of Saturate: '<S150>/Saturation' */

    /* Saturate: '<S144>/Saturation1' incorporates:
     *  Constant: '<S150>/Constant'
     *  Product: '<S144>/Multiply1'
     */
    rtb_Saturation1[0] = 0.0F;
    rtb_Saturation1[1] = 0.0F;

    /* Product: '<S144>/Multiply1' incorporates:
     *  DiscreteIntegrator: '<S190>/Discrete-Time Integrator5'
     */
    u0 = rtb_Cos_j * Controller_DW.DiscreteTimeIntegrator5_DSTA_a2;

    /* Saturate: '<S144>/Saturation1' */
    if (u0 > 1.0F) {
      rtb_Saturation1[2] = 1.0F;
    } else if (u0 < -1.0F) {
      rtb_Saturation1[2] = -1.0F;
    } else {
      rtb_Saturation1[2] = u0;
    }

    /* Trigonometry: '<S193>/Atan' incorporates:
     *  Gain: '<S193>/g_force'
     *  Sum: '<S193>/Minus'
     */
    rtb_Cos1_d = atanf(0.101936802F * Controller_U.FMS_Out.ay_cmd);

    /* Saturate: '<S193>/Saturation' */
    if (rtb_Cos1_d > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Cos1_d = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_Cos1_d < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_Cos1_d = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      }
    }

    /* End of Saturate: '<S193>/Saturation' */

    /* Switch: '<S213>/Switch' incorporates:
     *  Constant: '<S224>/Constant'
     *  RelationalOperator: '<S224>/Compare'
     */
    if (rtb_BitwiseAND_a == 4) {
      rtb_MatrixConcatenate1_tmp = Controller_U.FMS_Out.phi_cmd;
    } else {
      rtb_MatrixConcatenate1_tmp = rtb_Cos1_d;
    }

    /* End of Switch: '<S213>/Switch' */

    /* Abs: '<S194>/Abs' */
    rtb_Abs = fabsf(rtb_MatrixConcatenate1_tmp);

    /* Trigonometry: '<S221>/Trigonometric Function1' incorporates:
     *  Gain: '<S220>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S221>/Trigonometric Function3'
     *  Trigonometry: '<S223>/Trigonometric Function1'
     *  Trigonometry: '<S223>/Trigonometric Function3'
     */
    rtb_Cos_j = arm_cos_f32(-Controller_U.INS_Out.psi);
    rtb_MatrixConcatenate1[0] = rtb_Cos_j;

    /* Trigonometry: '<S221>/Trigonometric Function' incorporates:
     *  Gain: '<S220>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S221>/Trigonometric Function2'
     *  Trigonometry: '<S223>/Trigonometric Function'
     */
    rtb_Saturation1_h_idx_0 = arm_sin_f32(-Controller_U.INS_Out.psi);
    rtb_MatrixConcatenate1[1] = rtb_Saturation1_h_idx_0;

    /* SignalConversion: '<S221>/ConcatBufferAtVector Concatenate1In3' incorporates:
     *  Constant: '<S221>/Constant3'
     */
    rtb_MatrixConcatenate1[2] = 0.0F;

    /* Gain: '<S221>/Gain' */
    rtb_MatrixConcatenate1[3] = -rtb_Saturation1_h_idx_0;

    /* Trigonometry: '<S221>/Trigonometric Function3' */
    rtb_MatrixConcatenate1[4] = rtb_Cos_j;

    /* SignalConversion: '<S221>/ConcatBufferAtVector Concatenate2In3' incorporates:
     *  Constant: '<S221>/Constant4'
     */
    rtb_MatrixConcatenate1[5] = 0.0F;

    /* SignalConversion: '<S221>/ConcatBufferAtVector ConcatenateIn3' */
    rtb_MatrixConcatenate1[6] = Controller_ConstB.VectorConcatenate3_c[0];
    rtb_MatrixConcatenate1[7] = Controller_ConstB.VectorConcatenate3_c[1];
    rtb_MatrixConcatenate1[8] = Controller_ConstB.VectorConcatenate3_c[2];

    /* SignalConversion: '<S217>/TmpSignal ConversionAtMultiplyInport2' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Add_c = Controller_U.INS_Out.vn;
    rtb_FF_limit_idx_1 = Controller_U.INS_Out.ve;
    rtb_FF_limit_idx_2 = Controller_U.INS_Out.vd;

    /* Product: '<S217>/Multiply' */
    for (i = 0; i < 3; i++) {
      rtb_DiscreteTimeIntegrator1_k1[i] = rtb_MatrixConcatenate1[i + 6] *
        rtb_FF_limit_idx_2 + (rtb_MatrixConcatenate1[i + 3] * rtb_FF_limit_idx_1
        + rtb_MatrixConcatenate1[i] * rtb_Add_c);
    }

    /* End of Product: '<S217>/Multiply' */

    /* Switch: '<S217>/Switch' incorporates:
     *  Gain: '<S217>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S217>/Divide'
     *  S-Function (sfix_bitop): '<S217>/Bitwise AND'
     *  Trigonometry: '<S217>/Asin'
     */
    if ((Controller_U.INS_Out.flag & 16U) > 1U) {
      /* Sqrt: '<S217>/Sqrt' incorporates:
       *  Math: '<S217>/Square'
       *  Math: '<S217>/Square1'
       *  Sum: '<S217>/Add'
       */
      rtb_Divide_i_idx_0 = sqrtf(Controller_U.INS_Out.vn *
        Controller_U.INS_Out.vn + Controller_U.INS_Out.ve *
        Controller_U.INS_Out.ve);

      /* Saturate: '<S217>/Saturation' incorporates:
       *  Sqrt: '<S217>/Sqrt'
       */
      if (rtb_Divide_i_idx_0 > 100.0F) {
        rtb_Divide_i_idx_0 = 100.0F;
      } else {
        if (rtb_Divide_i_idx_0 < 8.0F) {
          rtb_Divide_i_idx_0 = 8.0F;
        }
      }

      /* End of Saturate: '<S217>/Saturation' */

      /* DeadZone: '<S217>/Dead Zone' */
      if (Controller_U.INS_Out.vd > 0.1F) {
        rtb_MatrixConcatenate1_tmp = Controller_U.INS_Out.vd - 0.1F;
      } else if (Controller_U.INS_Out.vd >= -0.1F) {
        rtb_MatrixConcatenate1_tmp = 0.0F;
      } else {
        rtb_MatrixConcatenate1_tmp = Controller_U.INS_Out.vd - -0.1F;
      }

      /* End of DeadZone: '<S217>/Dead Zone' */
      rtb_Saturation1_ih = atanf(1.0F / rtb_Divide_i_idx_0 *
        -rtb_MatrixConcatenate1_tmp);
    } else {
      rtb_Saturation1_ih = Controller_U.INS_Out.theta;
    }

    /* End of Switch: '<S217>/Switch' */

    /* DeadZone: '<S217>/Dead Zone1' */
    if (rtb_DiscreteTimeIntegrator1_k1[0] > 1.0F) {
      rtb_Divide_i_idx_0 = rtb_DiscreteTimeIntegrator1_k1[0] - 1.0F;
    } else if (rtb_DiscreteTimeIntegrator1_k1[0] >= -1.0F) {
      rtb_Divide_i_idx_0 = 0.0F;
    } else {
      rtb_Divide_i_idx_0 = rtb_DiscreteTimeIntegrator1_k1[0] - -1.0F;
    }

    /* End of DeadZone: '<S217>/Dead Zone1' */

    /* Signum: '<S217>/Sign' */
    if (rtb_Divide_i_idx_0 < 0.0F) {
      rtb_Divide_i_idx_0 = -1.0F;
    } else {
      if (rtb_Divide_i_idx_0 > 0.0F) {
        rtb_Divide_i_idx_0 = 1.0F;
      }
    }

    /* End of Signum: '<S217>/Sign' */

    /* Product: '<S217>/Multiply1' */
    rtb_Saturation1_ih *= rtb_Divide_i_idx_0;

    /* Saturate: '<S217>/Saturation1' */
    if (rtb_Saturation1_ih > 0.785398185F) {
      rtb_Saturation1_ih = 0.785398185F;
    } else {
      if (rtb_Saturation1_ih < -0.785398185F) {
        rtb_Saturation1_ih = -0.785398185F;
      }
    }

    /* End of Saturate: '<S217>/Saturation1' */

    /* Gain: '<S216>/Gain1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_VdotPg = 0.101936802F * Controller_U.INS_Out.ax;

    /* Sqrt: '<S219>/Sqrt' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Math: '<S219>/Square'
     *  Math: '<S219>/Square1'
     *  Sum: '<S219>/Add'
     */
    u0 = sqrtf(Controller_U.INS_Out.vn * Controller_U.INS_Out.vn +
               Controller_U.INS_Out.ve * Controller_U.INS_Out.ve);

    /* Trigonometry: '<S223>/Trigonometric Function1' */
    rtb_MatrixConcatenate1[0] = rtb_Cos_j;

    /* Trigonometry: '<S223>/Trigonometric Function' */
    rtb_MatrixConcatenate1[1] = rtb_Saturation1_h_idx_0;

    /* SignalConversion: '<S223>/ConcatBufferAtVector Concatenate1In3' incorporates:
     *  Constant: '<S223>/Constant3'
     */
    rtb_MatrixConcatenate1[2] = 0.0F;

    /* Gain: '<S223>/Gain' incorporates:
     *  Gain: '<S222>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S223>/Trigonometric Function2'
     */
    rtb_MatrixConcatenate1[3] = -arm_sin_f32(-Controller_U.INS_Out.psi);

    /* Trigonometry: '<S223>/Trigonometric Function3' */
    rtb_MatrixConcatenate1[4] = rtb_Cos_j;

    /* SignalConversion: '<S223>/ConcatBufferAtVector Concatenate2In3' incorporates:
     *  Constant: '<S223>/Constant4'
     */
    rtb_MatrixConcatenate1[5] = 0.0F;

    /* SignalConversion: '<S223>/ConcatBufferAtVector ConcatenateIn3' */
    rtb_MatrixConcatenate1[6] = Controller_ConstB.VectorConcatenate3_o[0];
    rtb_MatrixConcatenate1[7] = Controller_ConstB.VectorConcatenate3_o[1];
    rtb_MatrixConcatenate1[8] = Controller_ConstB.VectorConcatenate3_o[2];

    /* Product: '<S219>/Multiply' */
    for (i = 0; i < 3; i++) {
      rtb_DiscreteTimeIntegrator1_k1[i] = rtb_MatrixConcatenate1[i + 6] *
        rtb_FF_limit_idx_2 + (rtb_MatrixConcatenate1[i + 3] * rtb_FF_limit_idx_1
        + rtb_MatrixConcatenate1[i] * rtb_Add_c);
    }

    /* End of Product: '<S219>/Multiply' */

    /* DeadZone: '<S219>/Dead Zone' */
    if (rtb_DiscreteTimeIntegrator1_k1[0] > 1.0F) {
      rtb_Divide_i_idx_0 = rtb_DiscreteTimeIntegrator1_k1[0] - 1.0F;
    } else if (rtb_DiscreteTimeIntegrator1_k1[0] >= -1.0F) {
      rtb_Divide_i_idx_0 = 0.0F;
    } else {
      rtb_Divide_i_idx_0 = rtb_DiscreteTimeIntegrator1_k1[0] - -1.0F;
    }

    /* End of DeadZone: '<S219>/Dead Zone' */

    /* Saturate: '<S219>/Saturation1' incorporates:
     *  Sqrt: '<S219>/Sqrt'
     */
    if (u0 > 100.0F) {
      u0 = 100.0F;
    } else {
      if (u0 < 8.0F) {
        u0 = 8.0F;
      }
    }

    /* End of Saturate: '<S219>/Saturation1' */

    /* Signum: '<S219>/Sign' */
    if (rtb_Divide_i_idx_0 < 0.0F) {
      rtb_Divide_i_idx_0 = -1.0F;
    } else {
      if (rtb_Divide_i_idx_0 > 0.0F) {
        rtb_Divide_i_idx_0 = 1.0F;
      }
    }

    /* End of Signum: '<S219>/Sign' */

    /* Product: '<S219>/Multiply1' incorporates:
     *  Gain: '<S219>/Gain'
     *  Product: '<S219>/Divide'
     *  Trigonometry: '<S219>/Asin'
     */
    u0 = atanf(-Controller_U.FMS_Out.w_cmd / u0) * rtb_Divide_i_idx_0;

    /* Saturate: '<S219>/Saturation2' */
    if (u0 > 0.785398185F) {
      u0 = 0.785398185F;
    } else {
      if (u0 < -0.785398185F) {
        u0 = -0.785398185F;
      }
    }

    /* End of Saturate: '<S219>/Saturation2' */

    /* Sum: '<S212>/Minus' */
    rtb_Minus = u0 - rtb_Saturation1_ih;

    /* Sqrt: '<S238>/Sqrt' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Math: '<S238>/Square'
     *  Sum: '<S238>/Sum of Elements'
     */
    rtb_Sum = sqrtf(((Controller_U.INS_Out.quat[0] * Controller_U.INS_Out.quat[0]
                      + Controller_U.INS_Out.quat[1] *
                      Controller_U.INS_Out.quat[1]) + Controller_U.INS_Out.quat
                     [2] * Controller_U.INS_Out.quat[2]) +
                    Controller_U.INS_Out.quat[3] * Controller_U.INS_Out.quat[3]);

    /* Product: '<S234>/Divide' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_i_idx_0 = Controller_U.INS_Out.quat[0] / rtb_Sum;
    rtb_Divide_i_idx_1 = Controller_U.INS_Out.quat[1] / rtb_Sum;
    rtb_Divide_i_idx_2 = Controller_U.INS_Out.quat[2] / rtb_Sum;
    rtb_Divide_i_idx_3 = Controller_U.INS_Out.quat[3] / rtb_Sum;

    /* Math: '<S235>/Square' incorporates:
     *  Math: '<S236>/Square'
     *  Math: '<S237>/Square'
     */
    rtb_Cos_j = rtb_Divide_i_idx_0 * rtb_Divide_i_idx_0;

    /* Math: '<S235>/Square2' incorporates:
     *  Math: '<S236>/Square2'
     *  Math: '<S237>/Square2'
     */
    rtb_Saturation1_h_idx_0 = rtb_Divide_i_idx_2 * rtb_Divide_i_idx_2;

    /* Math: '<S235>/Square1' incorporates:
     *  Math: '<S236>/Square1'
     *  Math: '<S237>/Square1'
     */
    rtb_MatrixConcatenate1_tmp = rtb_Divide_i_idx_1 * rtb_Divide_i_idx_1;

    /* Math: '<S235>/Square3' incorporates:
     *  Math: '<S236>/Square3'
     *  Math: '<S237>/Square3'
     */
    rtb_B_err = rtb_Divide_i_idx_3 * rtb_Divide_i_idx_3;

    /* Sum: '<S235>/Subtract' incorporates:
     *  Math: '<S235>/Square'
     *  Math: '<S235>/Square1'
     *  Math: '<S235>/Square2'
     *  Math: '<S235>/Square3'
     *  Sum: '<S235>/Add'
     *  Sum: '<S235>/Add1'
     */
    rtb_MatrixConcatenate1[0] = (rtb_Cos_j + rtb_MatrixConcatenate1_tmp) -
      (rtb_Saturation1_h_idx_0 + rtb_B_err);

    /* Product: '<S235>/Multiply' incorporates:
     *  Product: '<S236>/Multiply'
     */
    rtb_Gain_il = rtb_Divide_i_idx_1 * rtb_Divide_i_idx_2;

    /* Product: '<S235>/Multiply1' incorporates:
     *  Product: '<S236>/Multiply1'
     */
    u0 = rtb_Divide_i_idx_0 * rtb_Divide_i_idx_3;

    /* Gain: '<S235>/Gain' incorporates:
     *  Product: '<S235>/Multiply'
     *  Product: '<S235>/Multiply1'
     *  Sum: '<S235>/Subtract1'
     */
    rtb_MatrixConcatenate1[1] = (rtb_Gain_il - u0) * 2.0F;

    /* Product: '<S235>/Multiply2' incorporates:
     *  Product: '<S237>/Multiply'
     */
    rtb_Sum = rtb_Divide_i_idx_1 * rtb_Divide_i_idx_3;

    /* Product: '<S235>/Multiply3' incorporates:
     *  Product: '<S237>/Multiply1'
     */
    rtb_Add2_h = rtb_Divide_i_idx_0 * rtb_Divide_i_idx_2;

    /* Gain: '<S235>/Gain1' incorporates:
     *  Product: '<S235>/Multiply2'
     *  Product: '<S235>/Multiply3'
     *  Sum: '<S235>/Add2'
     */
    rtb_MatrixConcatenate1[2] = (rtb_Sum + rtb_Add2_h) * 2.0F;

    /* Gain: '<S236>/Gain' incorporates:
     *  Sum: '<S236>/Add3'
     */
    rtb_MatrixConcatenate1[3] = (rtb_Gain_il + u0) * 2.0F;

    /* Sum: '<S236>/Subtract' incorporates:
     *  Sum: '<S236>/Add'
     *  Sum: '<S236>/Add1'
     */
    rtb_MatrixConcatenate1[4] = (rtb_Cos_j + rtb_Saturation1_h_idx_0) -
      (rtb_MatrixConcatenate1_tmp + rtb_B_err);

    /* Product: '<S236>/Multiply2' incorporates:
     *  Product: '<S237>/Multiply2'
     */
    rtb_Gain_il = rtb_Divide_i_idx_2 * rtb_Divide_i_idx_3;

    /* Product: '<S236>/Multiply3' incorporates:
     *  Product: '<S237>/Multiply3'
     */
    u0 = rtb_Divide_i_idx_0 * rtb_Divide_i_idx_1;

    /* Gain: '<S236>/Gain1' incorporates:
     *  Product: '<S236>/Multiply2'
     *  Product: '<S236>/Multiply3'
     *  Sum: '<S236>/Subtract1'
     */
    rtb_MatrixConcatenate1[5] = (rtb_Gain_il - u0) * 2.0F;

    /* Gain: '<S237>/Gain' incorporates:
     *  Sum: '<S237>/Subtract2'
     */
    rtb_MatrixConcatenate1[6] = (rtb_Sum - rtb_Add2_h) * 2.0F;

    /* Gain: '<S237>/Gain1' incorporates:
     *  Sum: '<S237>/Add2'
     */
    rtb_MatrixConcatenate1[7] = (rtb_Gain_il + u0) * 2.0F;

    /* Sum: '<S237>/Subtract' incorporates:
     *  Sum: '<S237>/Add'
     *  Sum: '<S237>/Add1'
     */
    rtb_MatrixConcatenate1[8] = (rtb_Cos_j + rtb_B_err) -
      (rtb_MatrixConcatenate1_tmp + rtb_Saturation1_h_idx_0);

    /* Product: '<S231>/Multiply' */
    for (i = 0; i < 3; i++) {
      rtb_DiscreteTimeIntegrator1_k1[i] = rtb_MatrixConcatenate1[i + 6] *
        rtb_FF_limit_idx_2 + (rtb_MatrixConcatenate1[i + 3] * rtb_FF_limit_idx_1
        + rtb_MatrixConcatenate1[i] * rtb_Add_c);
    }

    /* End of Product: '<S231>/Multiply' */

    /* Switch: '<S231>/Switch' incorporates:
     *  Constant: '<S232>/Constant'
     *  Inport: '<Root>/INS_Out'
     *  RelationalOperator: '<S232>/Compare'
     */
    if (rtb_DiscreteTimeIntegrator1_k1[0] >= 3.0F) {
      rtb_Divide_i_idx_0 = Controller_U.INS_Out.airspeed;
    } else {
      rtb_Divide_i_idx_0 = rtb_DiscreteTimeIntegrator1_k1[0];
    }

    /* End of Switch: '<S231>/Switch' */

    /* Sum: '<S216>/Sum' incorporates:
     *  Gain: '<S216>/Gain'
     *  Sum: '<S216>/Minus'
     */
    rtb_Sum = (Controller_U.FMS_Out.u_cmd - rtb_Divide_i_idx_0) * 0.101936802F -
      rtb_VdotPg;

    /* Sum: '<S194>/Minus1' incorporates:
     *  Gain: '<S194>/ucmd2pitch'
     *  Gain: '<S194>/wcmd2pitch'
     */
    rtb_B_err = CONTROL_PARAM.FW_TECS_W2P * rtb_Minus -
      CONTROL_PARAM.FW_TECS_U2P * rtb_Sum;

    /* DiscreteIntegrator: '<S226>/ ' */
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

    /* DiscreteIntegrator: '<S227>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_f != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_e = rtb_B_err;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_b != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_e = rtb_B_err;
    }

    /* Gain: '<S227>/Gain' incorporates:
     *  DiscreteIntegrator: '<S227>/Discrete-Time Integrator1'
     *  Sum: '<S227>/Sum5'
     */
    rtb_Gain_il = (rtb_B_err - Controller_DW.DiscreteTimeIntegrator1_DSTAT_e) *
      62.831852F;

    /* Switch: '<S227>/Switch' incorporates:
     *  Gain: '<S227>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_MatrixConcatenate1_tmp = 0.0F;
    } else {
      rtb_MatrixConcatenate1_tmp = rtb_Gain_il;
    }

    /* End of Switch: '<S227>/Switch' */

    /* Gain: '<S225>/Gain' */
    rtb_Add2_h = CONTROL_PARAM.FW_TECS_PITCH_D * rtb_MatrixConcatenate1_tmp;

    /* Saturate: '<S214>/Saturation1' */
    if (rtb_Add2_h > 0.3F) {
      rtb_Add2_h = 0.3F;
    } else {
      if (rtb_Add2_h < -0.3F) {
        rtb_Add2_h = -0.3F;
      }
    }

    /* End of Saturate: '<S214>/Saturation1' */

    /* Sum: '<S194>/Sum' incorporates:
     *  DiscreteIntegrator: '<S226>/ '
     *  Gain: '<S194>/Gain'
     *  Gain: '<S194>/balabnce_ratio2'
     *  Gain: '<S194>/balance_ratio'
     *  Gain: '<S194>/pitch_ff'
     *  Gain: '<S214>/P_control'
     *  Sum: '<S194>/Add3'
     *  Sum: '<S194>/Minus'
     *  Sum: '<S214>/Add'
     */
    rtb_Add2_h = (((2.0F - CONTROL_PARAM.FW_TECS_RATIO) * rtb_Saturation1_ih -
                   CONTROL_PARAM.FW_TECS_RATIO * rtb_VdotPg) *
                  CONTROL_PARAM.FW_TECS_PITCH_F +
                  ((CONTROL_PARAM.FW_TECS_PITCH_P * rtb_B_err +
                    Controller_DW._DSTATE) + rtb_Add2_h)) +
      CONTROL_PARAM.FW_TECS_R2P * rtb_Abs;

    /* Switch: '<S172>/Switch' incorporates:
     *  Constant: '<S175>/Constant'
     *  RelationalOperator: '<S175>/Compare'
     */
    if (rtb_BitwiseAND_a <= 4) {
      rtb_MatrixConcatenate1_tmp = Controller_U.FMS_Out.phi_cmd;
    } else {
      rtb_MatrixConcatenate1_tmp = rtb_Cos1_d;
    }

    /* End of Switch: '<S172>/Switch' */

    /* Sum: '<S166>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_i_idx_0 = rtb_MatrixConcatenate1_tmp - Controller_U.INS_Out.phi;

    /* Switch: '<S173>/Switch' incorporates:
     *  Constant: '<S176>/Constant'
     *  RelationalOperator: '<S176>/Compare'
     */
    if (rtb_BitwiseAND_a <= 3) {
      rtb_MatrixConcatenate1_tmp = Controller_U.FMS_Out.theta_cmd;
    } else {
      rtb_MatrixConcatenate1_tmp = rtb_Add2_h;
    }

    /* End of Switch: '<S173>/Switch' */

    /* Sum: '<S166>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Cos_j = rtb_MatrixConcatenate1_tmp - Controller_U.INS_Out.theta;

    /* Product: '<S169>/Divide1' incorporates:
     *  Abs: '<S169>/Abs'
     *  Constant: '<S169>/const2'
     */
    rtb_FF_limit_idx_2 = fabsf(rtb_Divide_i_idx_0) / 0.002F;

    /* Product: '<S169>/Divide' incorporates:
     *  Constant: '<S167>/Constant1'
     *  Constant: '<S169>/const1'
     *  Math: '<S169>/Square'
     *  SignalConversion: '<S169>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_Add_c = 9.5993F / (CONTROL_PARAM.MC_ROLL_P * CONTROL_PARAM.MC_ROLL_P);

    /* Signum: '<S169>/Sign' incorporates:
     *  Abs: '<S169>/Abs'
     */
    if (rtb_Divide_i_idx_0 < 0.0F) {
      rtb_MatrixConcatenate1_tmp = -1.0F;
    } else if (rtb_Divide_i_idx_0 > 0.0F) {
      rtb_MatrixConcatenate1_tmp = 1.0F;
    } else {
      rtb_MatrixConcatenate1_tmp = rtb_Divide_i_idx_0;
    }

    /* Switch: '<S169>/Switch' incorporates:
     *  Abs: '<S169>/Abs'
     *  Constant: '<S167>/Constant1'
     *  Gain: '<S169>/Gain1'
     *  Gain: '<S169>/Gain2'
     *  Logic: '<S169>/Logical Operator'
     *  Product: '<S169>/Divide'
     *  Product: '<S169>/Multiply'
     *  Product: '<S169>/Multiply1'
     *  Product: '<S169>/Multiply2'
     *  Product: '<S169>/Multiply3'
     *  RelationalOperator: '<S169>/Relational Operator'
     *  RelationalOperator: '<S169>/Relational Operator2'
     *  SignalConversion: '<S169>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S169>/Sqrt'
     *  Sum: '<S169>/Subtract'
     */
    if ((rtb_Divide_i_idx_0 <= rtb_Add_c) && (rtb_Divide_i_idx_0 >= -rtb_Add_c))
    {
      rtb_MatrixConcatenate1_tmp = rtb_Divide_i_idx_0 * CONTROL_PARAM.MC_ROLL_P;
    } else {
      rtb_MatrixConcatenate1_tmp *= sqrtf((rtb_MatrixConcatenate1_tmp *
        rtb_Divide_i_idx_0 - 0.5F * rtb_Add_c) * Controller_ConstB.Gain_np);
    }

    /* Gain: '<S169>/Gain3' */
    rtb_Add_c = -rtb_FF_limit_idx_2;

    /* Switch: '<S170>/Switch' incorporates:
     *  Gain: '<S169>/Gain3'
     *  RelationalOperator: '<S170>/UpperRelop'
     */
    if (rtb_MatrixConcatenate1_tmp >= -rtb_FF_limit_idx_2) {
      rtb_Add_c = rtb_MatrixConcatenate1_tmp;
    }

    /* Switch: '<S170>/Switch2' incorporates:
     *  RelationalOperator: '<S170>/LowerRelop1'
     */
    if (rtb_MatrixConcatenate1_tmp <= rtb_FF_limit_idx_2) {
      rtb_FF_limit_idx_2 = rtb_Add_c;
    }

    /* Saturate: '<S155>/Saturation1' */
    if (rtb_FF_limit_idx_2 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_FF_limit_idx_2 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_FF_limit_idx_2 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_FF_limit_idx_2 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    rtb_Saturation1_h_idx_0 = rtb_FF_limit_idx_2;

    /* Product: '<S169>/Divide1' incorporates:
     *  Abs: '<S169>/Abs'
     *  Constant: '<S169>/const2'
     */
    rtb_FF_limit_idx_2 = fabsf(rtb_Cos_j) / 0.002F;

    /* Product: '<S169>/Divide' incorporates:
     *  Constant: '<S167>/Constant2'
     *  Constant: '<S169>/const1'
     *  Math: '<S169>/Square'
     *  SignalConversion: '<S169>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_Add_c = 9.5993F / (CONTROL_PARAM.MC_PITCH_P * CONTROL_PARAM.MC_PITCH_P);

    /* Signum: '<S169>/Sign' incorporates:
     *  Abs: '<S169>/Abs'
     */
    if (rtb_Cos_j < 0.0F) {
      rtb_MatrixConcatenate1_tmp = -1.0F;
    } else if (rtb_Cos_j > 0.0F) {
      rtb_MatrixConcatenate1_tmp = 1.0F;
    } else {
      rtb_MatrixConcatenate1_tmp = rtb_Cos_j;
    }

    /* Switch: '<S169>/Switch' incorporates:
     *  Abs: '<S169>/Abs'
     *  Constant: '<S167>/Constant2'
     *  Gain: '<S169>/Gain1'
     *  Gain: '<S169>/Gain2'
     *  Logic: '<S169>/Logical Operator'
     *  Product: '<S169>/Divide'
     *  Product: '<S169>/Multiply'
     *  Product: '<S169>/Multiply1'
     *  Product: '<S169>/Multiply2'
     *  Product: '<S169>/Multiply3'
     *  RelationalOperator: '<S169>/Relational Operator'
     *  RelationalOperator: '<S169>/Relational Operator2'
     *  SignalConversion: '<S169>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S169>/Sqrt'
     *  Sum: '<S169>/Subtract'
     */
    if ((rtb_Cos_j <= rtb_Add_c) && (rtb_Cos_j >= -rtb_Add_c)) {
      rtb_MatrixConcatenate1_tmp = rtb_Cos_j * CONTROL_PARAM.MC_PITCH_P;
    } else {
      rtb_MatrixConcatenate1_tmp *= sqrtf((rtb_MatrixConcatenate1_tmp *
        rtb_Cos_j - 0.5F * rtb_Add_c) * Controller_ConstB.Gain_np);
    }

    /* Gain: '<S169>/Gain3' */
    rtb_Add_c = -rtb_FF_limit_idx_2;

    /* Switch: '<S170>/Switch' incorporates:
     *  Gain: '<S169>/Gain3'
     *  RelationalOperator: '<S170>/UpperRelop'
     */
    if (rtb_MatrixConcatenate1_tmp >= -rtb_FF_limit_idx_2) {
      rtb_Add_c = rtb_MatrixConcatenate1_tmp;
    }

    /* Switch: '<S170>/Switch2' incorporates:
     *  RelationalOperator: '<S170>/LowerRelop1'
     */
    if (rtb_MatrixConcatenate1_tmp <= rtb_FF_limit_idx_2) {
      rtb_FF_limit_idx_2 = rtb_Add_c;
    }

    /* Saturate: '<S155>/Saturation1' */
    if (rtb_FF_limit_idx_2 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_FF_limit_idx_2 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_FF_limit_idx_2 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_FF_limit_idx_2 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    /* Saturate: '<S155>/Saturation' */
    if (Controller_U.FMS_Out.psi_rate_cmd > CONTROL_PARAM.MC_R_CMD_LIM) {
      rtb_Cos_j = CONTROL_PARAM.MC_R_CMD_LIM;
    } else if (Controller_U.FMS_Out.psi_rate_cmd < -CONTROL_PARAM.MC_R_CMD_LIM)
    {
      rtb_Cos_j = -CONTROL_PARAM.MC_R_CMD_LIM;
    } else {
      rtb_Cos_j = Controller_U.FMS_Out.psi_rate_cmd;
    }

    /* End of Saturate: '<S155>/Saturation' */

    /* Trigonometry: '<S164>/Sin' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S197>/Sin'
     */
    rtb_MatrixConcatenate1_tmp = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S164>/Sin1' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S197>/Sin1'
     */
    rtb_u = arm_sin_f32(Controller_U.INS_Out.theta);

    /* Sum: '<S156>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S164>/Multiply'
     *  Product: '<S164>/Multiply1'
     *  Product: '<S164>/Multiply3'
     *  Product: '<S164>/Multiply4'
     *  Product: '<S164>/Multiply5'
     *  Sum: '<S164>/Add'
     *  Sum: '<S164>/Add1'
     *  Sum: '<S164>/Add2'
     *  Trigonometry: '<S164>/Sin'
     *  Trigonometry: '<S164>/Sin1'
     */
    rtb_Add_c = (rtb_Saturation1_h_idx_0 - rtb_u * rtb_Cos_j) -
      Controller_U.INS_Out.p;
    rtb_FF_limit_idx_1 = (rtb_MatrixConcatenate1_tmp * rtb_Gain_cu * rtb_Cos_j +
                          rtb_Multiply_ga_idx_0 * rtb_FF_limit_idx_2) -
      Controller_U.INS_Out.q;
    rtb_FF_limit_idx_2 = (rtb_Multiply_ga_idx_0 * rtb_Gain_cu * rtb_Cos_j -
                          rtb_MatrixConcatenate1_tmp * rtb_FF_limit_idx_2) -
      Controller_U.INS_Out.r;

    /* DiscreteIntegrator: '<S159>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_b != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0] = rtb_Add_c;
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1] = rtb_FF_limit_idx_1;
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2] = rtb_FF_limit_idx_2;
    }

    /* Logic: '<S151>/Logical Operator' incorporates:
     *  Constant: '<S153>/Constant'
     *  DiscreteIntegrator: '<S190>/Discrete-Time Integrator5'
     *  RelationalOperator: '<S153>/Compare'
     */
    rtb_LogicalOperator_m = ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator5_DSTA_a2 == 0.0F));

    /* DiscreteIntegrator: '<S161>/Discrete-Time Integrator' */
    if (rtb_LogicalOperator_m || (Controller_DW.DiscreteTimeIntegrator_PrevRe_o
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

    /* DiscreteIntegrator: '<S163>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S159>/Discrete-Time Integrator5'
     */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_L_h2 != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[0] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0];
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[1] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1];
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[2] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2];
    }

    if (rtb_LogicalOperator_m || (Controller_DW.DiscreteTimeIntegrator1_PrevR_l
         != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[0] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0];
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[1] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1];
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[2] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2];
    }

    /* Gain: '<S163>/Gain' incorporates:
     *  DiscreteIntegrator: '<S159>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S163>/Discrete-Time Integrator1'
     *  Sum: '<S163>/Sum5'
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

    /* Switch: '<S163>/Switch' incorporates:
     *  Gain: '<S163>/Gain1'
     */
    if (rtb_LogicalOperator_m) {
      rtb_Divide_i_idx_1 = 0.0F;
      rtb_Divide_i_idx_2 = 0.0F;
      rtb_Divide_i_idx_3 = 0.0F;
    } else {
      rtb_Divide_i_idx_1 = rtb_DiscreteTimeIntegrator1_k1[0];
      rtb_Divide_i_idx_2 = rtb_DiscreteTimeIntegrator1_k1[1];
      rtb_Divide_i_idx_3 = rtb_DiscreteTimeIntegrator1_k1[2];
    }

    /* End of Switch: '<S163>/Switch' */

    /* Product: '<S160>/Multiply' incorporates:
     *  Constant: '<S160>/gain1'
     */
    rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_ROLL_RATE_D *
      rtb_Divide_i_idx_1;

    /* Saturate: '<S160>/Saturation' */
    if (rtb_DiscreteTimeIntegrator1_g > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_DiscreteTimeIntegrator1_g < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    rtb_Divide_i_idx_1 = rtb_DiscreteTimeIntegrator1_g;

    /* Product: '<S160>/Multiply' incorporates:
     *  Constant: '<S160>/gain2'
     */
    rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_PITCH_RATE_D *
      rtb_Divide_i_idx_2;

    /* Saturate: '<S160>/Saturation' */
    if (rtb_DiscreteTimeIntegrator1_g > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_DiscreteTimeIntegrator1_g < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    rtb_Divide_i_idx_2 = rtb_DiscreteTimeIntegrator1_g;

    /* Product: '<S160>/Multiply' incorporates:
     *  Constant: '<S160>/gain3'
     */
    rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_YAW_RATE_D *
      rtb_Divide_i_idx_3;

    /* Saturate: '<S160>/Saturation' */
    if (rtb_DiscreteTimeIntegrator1_g > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_DiscreteTimeIntegrator1_g < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    /* Product: '<S144>/Multiply2' incorporates:
     *  Constant: '<S162>/gain1'
     *  DiscreteIntegrator: '<S159>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S161>/Discrete-Time Integrator'
     *  DiscreteIntegrator: '<S190>/Discrete-Time Integrator5'
     *  Product: '<S162>/Multiply'
     *  Sum: '<S157>/Add'
     */
    u0 = ((CONTROL_PARAM.MC_ROLL_RATE_P *
           Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0] +
           Controller_DW.DiscreteTimeIntegrator_DSTATE_d[0]) +
          rtb_Divide_i_idx_1) * Controller_DW.DiscreteTimeIntegrator5_DSTA_a2;

    /* Saturate: '<S144>/Saturation2' */
    if (u0 > 1.0F) {
      rtb_Saturation2[0] = 1.0F;
    } else if (u0 < -1.0F) {
      rtb_Saturation2[0] = -1.0F;
    } else {
      rtb_Saturation2[0] = u0;
    }

    /* Product: '<S144>/Multiply2' incorporates:
     *  Constant: '<S162>/gain2'
     *  DiscreteIntegrator: '<S159>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S161>/Discrete-Time Integrator'
     *  DiscreteIntegrator: '<S190>/Discrete-Time Integrator5'
     *  Product: '<S162>/Multiply'
     *  Sum: '<S157>/Add'
     */
    u0 = ((CONTROL_PARAM.MC_PITCH_RATE_P *
           Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1] +
           Controller_DW.DiscreteTimeIntegrator_DSTATE_d[1]) +
          rtb_Divide_i_idx_2) * Controller_DW.DiscreteTimeIntegrator5_DSTA_a2;

    /* Saturate: '<S144>/Saturation2' */
    if (u0 > 1.0F) {
      rtb_Saturation2[1] = 1.0F;
    } else if (u0 < -1.0F) {
      rtb_Saturation2[1] = -1.0F;
    } else {
      rtb_Saturation2[1] = u0;
    }

    /* Product: '<S144>/Multiply2' incorporates:
     *  Constant: '<S162>/gain3'
     *  DiscreteIntegrator: '<S159>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S161>/Discrete-Time Integrator'
     *  DiscreteIntegrator: '<S190>/Discrete-Time Integrator5'
     *  Product: '<S162>/Multiply'
     *  Sum: '<S157>/Add'
     */
    u0 = ((CONTROL_PARAM.MC_YAW_RATE_P *
           Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2] +
           Controller_DW.DiscreteTimeIntegrator_DSTATE_d[2]) +
          rtb_DiscreteTimeIntegrator1_g) *
      Controller_DW.DiscreteTimeIntegrator5_DSTA_a2;

    /* Saturate: '<S144>/Saturation2' */
    if (u0 > 1.0F) {
      rtb_Saturation2[2] = 1.0F;
    } else if (u0 < -1.0F) {
      rtb_Saturation2[2] = -1.0F;
    } else {
      rtb_Saturation2[2] = u0;
    }

    /* DiscreteIntegrator: '<S189>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_g != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j = rtb_Saturation_ov;
    }

    /* Saturate: '<S195>/Saturation1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    if (Controller_U.INS_Out.airspeed > 999.0F) {
      rtb_DiscreteTimeIntegrator1_g = 999.0F;
    } else if (Controller_U.INS_Out.airspeed < 0.1F) {
      rtb_DiscreteTimeIntegrator1_g = 0.1F;
    } else {
      rtb_DiscreteTimeIntegrator1_g = Controller_U.INS_Out.airspeed;
    }

    /* End of Saturate: '<S195>/Saturation1' */

    /* Product: '<S200>/Divide' incorporates:
     *  Constant: '<S200>/trim_speed'
     */
    rtb_Saturation1_h_idx_0 = CONTROL_PARAM.FW_AIRSPEED_TRIM /
      rtb_DiscreteTimeIntegrator1_g;

    /* Saturate: '<S200>/Saturation' */
    if (rtb_Saturation1_h_idx_0 > 1.0F) {
      rtb_Saturation1_h_idx_0 = 1.0F;
    } else {
      if (rtb_Saturation1_h_idx_0 < 0.0F) {
        rtb_Saturation1_h_idx_0 = 0.0F;
      }
    }

    /* End of Saturate: '<S200>/Saturation' */

    /* Switch: '<S205>/Switch' incorporates:
     *  Logic: '<S205>/Logical Operator'
     *  RelationalOperator: '<S210>/Compare'
     */
    if ((rtb_BitwiseAND_a == 3) || (rtb_BitwiseAND_a == 4)) {
      rtb_Cos1_d = Controller_U.FMS_Out.phi_cmd;
    }

    /* End of Switch: '<S205>/Switch' */

    /* Switch: '<S205>/Switch1' incorporates:
     *  Constant: '<S211>/Constant'
     *  RelationalOperator: '<S211>/Compare'
     */
    if (rtb_BitwiseAND_a == 3) {
      rtb_Add2_h = Controller_U.FMS_Out.theta_cmd;
    }

    /* End of Switch: '<S205>/Switch1' */

    /* Bias: '<S206>/Pitch Offset' */
    rtb_Add2_h += CONTROL_PARAM.FW_PITCH_OFFSET;

    /* Saturate: '<S206>/Saturation' */
    if (rtb_Add2_h > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Add2_h = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_Add2_h < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_Add2_h = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      }
    }

    /* Product: '<S207>/Multiply' incorporates:
     *  Constant: '<S207>/Constant2'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S206>/Sum'
     */
    rtb_Cos_j = (rtb_Add2_h - Controller_U.INS_Out.theta) *
      CONTROL_PARAM.FW_PITCH_P;

    /* Product: '<S209>/Divide' incorporates:
     *  Constant: '<S209>/Constant'
     *  Inport: '<Root>/INS_Out'
     */
    u0 = 9.81F / Controller_U.INS_Out.airspeed;

    /* Saturate: '<S209>/Saturation' */
    if (u0 > 1.0F) {
      u0 = 1.0F;
    } else {
      if (u0 < 0.0F) {
        u0 = 0.0F;
      }
    }

    /* End of Saturate: '<S209>/Saturation' */

    /* Sum: '<S204>/Sum' incorporates:
     *  Product: '<S209>/Multiply'
     *  Product: '<S209>/Multiply1'
     *  Trigonometry: '<S209>/Cos'
     *  Trigonometry: '<S209>/Tan'
     */
    rtb_Divide_i_idx_0 = tanf(Controller_U.FMS_Out.phi_cmd) * arm_cos_f32
      (Controller_U.FMS_Out.theta_cmd) * u0 + Controller_U.FMS_Out.psi_rate_cmd;

    /* Saturate: '<S206>/Saturation' */
    if (rtb_Cos1_d > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Cos1_d = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_Cos1_d < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_Cos1_d = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      }
    }

    /* Sum: '<S197>/Add' incorporates:
     *  Constant: '<S207>/Constant1'
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S197>/Multiply'
     *  Product: '<S207>/Multiply'
     *  Sum: '<S206>/Sum'
     */
    rtb_Cos1_d = (rtb_Cos1_d - Controller_U.INS_Out.phi) *
      CONTROL_PARAM.FW_ROLL_P - rtb_u * rtb_Divide_i_idx_0;

    /* Sum: '<S197>/Add1' incorporates:
     *  Product: '<S197>/Multiply1'
     *  Product: '<S197>/Multiply3'
     */
    rtb_u = rtb_MatrixConcatenate1_tmp * rtb_Gain_cu * rtb_Divide_i_idx_0 +
      rtb_Multiply_ga_idx_0 * rtb_Cos_j;

    /* Sum: '<S197>/Add2' incorporates:
     *  Product: '<S197>/Multiply4'
     *  Product: '<S197>/Multiply5'
     */
    rtb_Add2_h = rtb_Multiply_ga_idx_0 * rtb_Gain_cu * rtb_Divide_i_idx_0 -
      rtb_MatrixConcatenate1_tmp * rtb_Cos_j;

    /* Product: '<S199>/Divide' incorporates:
     *  Constant: '<S199>/trim_speed'
     *  Math: '<S199>/Square'
     *  Math: '<S199>/Square1'
     */
    rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.FW_AIRSPEED_TRIM *
      CONTROL_PARAM.FW_AIRSPEED_TRIM / (rtb_DiscreteTimeIntegrator1_g *
      rtb_DiscreteTimeIntegrator1_g);

    /* Saturate: '<S199>/Saturation' */
    if (rtb_DiscreteTimeIntegrator1_g > 1.0F) {
      rtb_DiscreteTimeIntegrator1_g = 1.0F;
    } else {
      if (rtb_DiscreteTimeIntegrator1_g < 0.0F) {
        rtb_DiscreteTimeIntegrator1_g = 0.0F;
      }
    }

    /* End of Saturate: '<S199>/Saturation' */

    /* Sum: '<S195>/Minus2' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_i_idx_1 = rtb_Cos1_d - Controller_U.INS_Out.p;
    rtb_Divide_i_idx_2 = rtb_u - Controller_U.INS_Out.q;
    rtb_Divide_i_idx_3 = rtb_Add2_h - Controller_U.INS_Out.r;

    /* DiscreteIntegrator: '<S201>/Discrete-Time Integrator' */
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

    /* Product: '<S195>/Multiply1' incorporates:
     *  Gain: '<S195>/FF'
     */
    u0 = CONTROL_PARAM.FW_FF * rtb_Cos1_d * rtb_Saturation1_h_idx_0;

    /* Product: '<S195>/Multiply' incorporates:
     *  Constant: '<S202>/gain1'
     *  DiscreteIntegrator: '<S201>/Discrete-Time Integrator'
     *  Product: '<S202>/Multiply'
     *  Sum: '<S198>/Add1'
     */
    rtb_Multiply_ga_idx_0 = (CONTROL_PARAM.FW_ROLL_RATE_P * rtb_Divide_i_idx_1 +
      Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0]) *
      rtb_DiscreteTimeIntegrator1_g;

    /* Saturate: '<S195>/FF_limit' */
    if (u0 > CONTROL_PARAM.FW_FF_LIMIT) {
      u0 = CONTROL_PARAM.FW_FF_LIMIT;
    } else {
      if (u0 < -CONTROL_PARAM.FW_FF_LIMIT) {
        u0 = -CONTROL_PARAM.FW_FF_LIMIT;
      }
    }

    /* Saturate: '<S195>/PI_limit' */
    if (rtb_Multiply_ga_idx_0 > CONTROL_PARAM.FW_PI_LIMIT) {
      rtb_Multiply_ga_idx_0 = CONTROL_PARAM.FW_PI_LIMIT;
    } else {
      if (rtb_Multiply_ga_idx_0 < -CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_Multiply_ga_idx_0 = -CONTROL_PARAM.FW_PI_LIMIT;
      }
    }

    /* Product: '<S146>/Multiply' incorporates:
     *  DiscreteIntegrator: '<S189>/Discrete-Time Integrator5'
     *  Sum: '<S195>/Add'
     */
    u0 = (u0 + rtb_Multiply_ga_idx_0) *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;

    /* Saturate: '<S146>/Saturation1' */
    if (u0 > 1.0F) {
      rtb_Saturation1_f[0] = 1.0F;
    } else if (u0 < -1.0F) {
      rtb_Saturation1_f[0] = -1.0F;
    } else {
      rtb_Saturation1_f[0] = u0;
    }

    /* Product: '<S195>/Multiply1' incorporates:
     *  Gain: '<S195>/FF'
     */
    u0 = CONTROL_PARAM.FW_FF * rtb_u * rtb_Saturation1_h_idx_0;

    /* Product: '<S195>/Multiply' incorporates:
     *  Constant: '<S202>/gain2'
     *  DiscreteIntegrator: '<S201>/Discrete-Time Integrator'
     *  Product: '<S202>/Multiply'
     *  Sum: '<S198>/Add1'
     */
    rtb_Multiply_ga_idx_0 = (CONTROL_PARAM.FW_PITCH_RATE_P * rtb_Divide_i_idx_2
      + Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1]) *
      rtb_DiscreteTimeIntegrator1_g;

    /* Saturate: '<S195>/FF_limit' */
    if (u0 > CONTROL_PARAM.FW_FF_LIMIT) {
      u0 = CONTROL_PARAM.FW_FF_LIMIT;
    } else {
      if (u0 < -CONTROL_PARAM.FW_FF_LIMIT) {
        u0 = -CONTROL_PARAM.FW_FF_LIMIT;
      }
    }

    /* Saturate: '<S195>/PI_limit' */
    if (rtb_Multiply_ga_idx_0 > CONTROL_PARAM.FW_PI_LIMIT) {
      rtb_Multiply_ga_idx_0 = CONTROL_PARAM.FW_PI_LIMIT;
    } else {
      if (rtb_Multiply_ga_idx_0 < -CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_Multiply_ga_idx_0 = -CONTROL_PARAM.FW_PI_LIMIT;
      }
    }

    /* Product: '<S146>/Multiply' incorporates:
     *  DiscreteIntegrator: '<S189>/Discrete-Time Integrator5'
     *  Sum: '<S195>/Add'
     */
    u0 = (u0 + rtb_Multiply_ga_idx_0) *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;

    /* Saturate: '<S146>/Saturation1' */
    if (u0 > 1.0F) {
      rtb_Saturation1_f[1] = 1.0F;
    } else if (u0 < -1.0F) {
      rtb_Saturation1_f[1] = -1.0F;
    } else {
      rtb_Saturation1_f[1] = u0;
    }

    /* Product: '<S195>/Multiply1' incorporates:
     *  Gain: '<S195>/FF'
     */
    u0 = CONTROL_PARAM.FW_FF * rtb_Add2_h * rtb_Saturation1_h_idx_0;

    /* Product: '<S195>/Multiply' incorporates:
     *  Constant: '<S202>/gain3'
     *  DiscreteIntegrator: '<S201>/Discrete-Time Integrator'
     *  Product: '<S202>/Multiply'
     *  Sum: '<S198>/Add1'
     */
    rtb_Multiply_ga_idx_0 = (CONTROL_PARAM.FW_YAW_RATE_P * rtb_Divide_i_idx_3 +
      Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2]) *
      rtb_DiscreteTimeIntegrator1_g;

    /* Saturate: '<S195>/FF_limit' */
    if (u0 > CONTROL_PARAM.FW_FF_LIMIT) {
      u0 = CONTROL_PARAM.FW_FF_LIMIT;
    } else {
      if (u0 < -CONTROL_PARAM.FW_FF_LIMIT) {
        u0 = -CONTROL_PARAM.FW_FF_LIMIT;
      }
    }

    /* Saturate: '<S195>/PI_limit' */
    if (rtb_Multiply_ga_idx_0 > CONTROL_PARAM.FW_PI_LIMIT) {
      rtb_Multiply_ga_idx_0 = CONTROL_PARAM.FW_PI_LIMIT;
    } else {
      if (rtb_Multiply_ga_idx_0 < -CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_Multiply_ga_idx_0 = -CONTROL_PARAM.FW_PI_LIMIT;
      }
    }

    /* Product: '<S146>/Multiply' incorporates:
     *  DiscreteIntegrator: '<S189>/Discrete-Time Integrator5'
     *  Sum: '<S195>/Add'
     */
    u0 = (u0 + rtb_Multiply_ga_idx_0) *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;

    /* Saturate: '<S146>/Saturation1' */
    if (u0 > 1.0F) {
      rtb_Saturation1_f[2] = 1.0F;
    } else if (u0 < -1.0F) {
      rtb_Saturation1_f[2] = -1.0F;
    } else {
      rtb_Saturation1_f[2] = u0;
    }

    /* Sum: '<S194>/Add' incorporates:
     *  Gain: '<S194>/ucmd2thor'
     *  Gain: '<S194>/wcmd2thor'
     */
    rtb_Cos_j = CONTROL_PARAM.FW_TECS_W2T * rtb_Minus +
      CONTROL_PARAM.FW_TECS_U2T * rtb_Sum;

    /* DiscreteIntegrator: '<S229>/ ' */
    if ((Controller_U.FMS_Out.reset != 0) || (Controller_DW._PrevResetState_e !=
         0)) {
      Controller_DW._DSTATE_d = Controller_ConstB.Zero;
      if (Controller_DW._DSTATE_d >= 0.3F) {
        Controller_DW._DSTATE_d = 0.3F;
      } else {
        if (Controller_DW._DSTATE_d <= -0.3F) {
          Controller_DW._DSTATE_d = -0.3F;
        }
      }
    }

    if (Controller_DW._DSTATE_d >= 0.3F) {
      Controller_DW._DSTATE_d = 0.3F;
    } else {
      if (Controller_DW._DSTATE_d <= -0.3F) {
        Controller_DW._DSTATE_d = -0.3F;
      }
    }

    /* DiscreteIntegrator: '<S230>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_L_h0 != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm = rtb_Cos_j;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_d != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm = rtb_Cos_j;
    }

    /* Gain: '<S230>/Gain' incorporates:
     *  DiscreteIntegrator: '<S230>/Discrete-Time Integrator1'
     *  Sum: '<S230>/Sum5'
     */
    rtb_Gain_cu = (rtb_Cos_j - Controller_DW.DiscreteTimeIntegrator1_DSTA_nm) *
      188.49556F;

    /* Switch: '<S230>/Switch' incorporates:
     *  Gain: '<S230>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_MatrixConcatenate1_tmp = 0.0F;
    } else {
      rtb_MatrixConcatenate1_tmp = rtb_Gain_cu;
    }

    /* End of Switch: '<S230>/Switch' */

    /* Gain: '<S228>/Gain' */
    rtb_Saturation1_h_idx_0 = CONTROL_PARAM.FW_TECS_THOR_D *
      rtb_MatrixConcatenate1_tmp;

    /* Saturate: '<S215>/Saturation1' */
    if (rtb_Saturation1_h_idx_0 > 0.3F) {
      rtb_Saturation1_h_idx_0 = 0.3F;
    } else {
      if (rtb_Saturation1_h_idx_0 < -0.3F) {
        rtb_Saturation1_h_idx_0 = -0.3F;
      }
    }

    /* End of Saturate: '<S215>/Saturation1' */

    /* Sum: '<S146>/Sum' incorporates:
     *  Constant: '<S146>/cruise_throttle'
     *  DiscreteIntegrator: '<S229>/ '
     *  Gain: '<S194>/Gain1'
     *  Gain: '<S194>/thorttle_ff'
     *  Gain: '<S215>/P_control'
     *  Sum: '<S194>/Add1'
     *  Sum: '<S194>/Add2'
     *  Sum: '<S194>/Sum1'
     *  Sum: '<S215>/Add4'
     */
    u0 = ((((CONTROL_PARAM.FW_TECS_THOR_P * rtb_Cos_j + Controller_DW._DSTATE_d)
            + rtb_Saturation1_h_idx_0) + (rtb_Saturation1_ih + rtb_VdotPg) *
           CONTROL_PARAM.FW_TECS_THOR_FF) + CONTROL_PARAM.FW_TECS_R2T * rtb_Abs)
      + 0.5F;

    /* Saturate: '<S146>/Saturation' */
    if (u0 > 1.0F) {
      /* Saturate: '<S146>/Saturation2' */
      rtb_Saturation2_l[0] = 1.0F;
    } else if (u0 < -1.0F) {
      /* Saturate: '<S146>/Saturation2' */
      rtb_Saturation2_l[0] = -1.0F;
    } else {
      /* Saturate: '<S146>/Saturation2' */
      rtb_Saturation2_l[0] = u0;
    }

    /* End of Saturate: '<S146>/Saturation' */

    /* Saturate: '<S146>/Saturation2' incorporates:
     *  Constant: '<S146>/Constant'
     */
    rtb_Saturation2_l[1] = 0.0F;
    rtb_Saturation2_l[2] = 0.0F;

    /* Outputs for Atomic SubSystem: '<S147>/VTOL_Control_Allocation' */
#if AIRFRAME == 1

    /* Output and update for atomic system: '<S240>/VTOL1' */
    {
      real32_T rtb_MatrixConcatenate[12];
      uint16_T rtb_DataTypeConversion_i;
      int32_T i_f;
      real32_T tmp_f[4];
      real32_T tmp_c;
      real32_T tmp_n;
      real32_T tmp_k;
      real32_T u0_f;
      uint16_T u0_c;

      /* MultiPortSwitch: '<S245>/Multiport Switch' incorporates:
       *  Constant: '<S245>/Disarm'
       *  Constant: '<S245>/Standby'
       *  Constant: '<S246>/Constant1'
       *  Constant: '<S246>/Constant12'
       *  Constant: '<S246>/Constant2'
       *  Constant: '<S246>/Constant7'
       *  Inport: '<Root>/FMS_Out'
       */
      switch (Controller_U.FMS_Out.status) {
       case 1:
        for (i_f = 0; i_f < 9; i_f++) {
          rtb_VariantMergeForOutportact_h[i_f] = Controller_ConstP.pooled37[i_f];
        }
        break;

       case 2:
        for (i_f = 0; i_f < 9; i_f++) {
          rtb_VariantMergeForOutportact_h[i_f] = Controller_ConstP.pooled38[i_f];
        }
        break;

       case 3:
        rtb_MatrixConcatenate[11] = CONTROL_PARAM.FW_YAW_EFFC *
          CONTROL_PARAM.FW_RUDDER_DIR;

        /* SignalConversion: '<S246>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S246>/Constant11'
         *  Constant: '<S246>/Constant12'
         */
        rtb_MatrixConcatenate[10] = 0.0F;

        /* SignalConversion: '<S246>/ConcatBufferAtVector Concatenate2In2' incorporates:
         *  Constant: '<S246>/Constant10'
         */
        rtb_MatrixConcatenate[9] = 0.0F;

        /* SignalConversion: '<S246>/ConcatBufferAtVector Concatenate2In1' incorporates:
         *  Constant: '<S246>/Constant9'
         */
        rtb_MatrixConcatenate[8] = 0.0F;

        /* SignalConversion: '<S246>/ConcatBufferAtVector Concatenate1In4' incorporates:
         *  Constant: '<S246>/Constant8'
         */
        rtb_MatrixConcatenate[7] = 0.0F;
        rtb_MatrixConcatenate[6] = CONTROL_PARAM.FW_PITCH_EFFC *
          CONTROL_PARAM.FW_ELEVATOR_DIR;

        /* SignalConversion: '<S246>/ConcatBufferAtVector Concatenate1In2' incorporates:
         *  Constant: '<S246>/Constant6'
         *  Constant: '<S246>/Constant7'
         */
        rtb_MatrixConcatenate[5] = 0.0F;

        /* SignalConversion: '<S246>/ConcatBufferAtVector Concatenate1In1' incorporates:
         *  Constant: '<S246>/Constant5'
         */
        rtb_MatrixConcatenate[4] = 0.0F;

        /* SignalConversion: '<S246>/ConcatBufferAtVector ConcatenateIn4' incorporates:
         *  Constant: '<S246>/Constant4'
         */
        rtb_MatrixConcatenate[3] = 0.0F;

        /* SignalConversion: '<S246>/ConcatBufferAtVector ConcatenateIn3' incorporates:
         *  Constant: '<S246>/Constant3'
         */
        rtb_MatrixConcatenate[2] = 0.0F;
        rtb_MatrixConcatenate[1] = CONTROL_PARAM.FW_ROLL_EFFC *
          CONTROL_PARAM.FW_AILERON2_DIR;
        rtb_MatrixConcatenate[0] = CONTROL_PARAM.FW_ROLL_EFFC *
          CONTROL_PARAM.FW_AILERON1_DIR;

        /* Switch: '<S247>/Switch' incorporates:
         *  Constant: '<S246>/Constant1'
         *  Constant: '<S246>/Constant2'
         *  Constant: '<S248>/Constant1'
         *  Constant: '<S249>/Constant'
         *  DataTypeConversion: '<S248>/Data Type Conversion'
         *  Gain: '<S248>/Gain1'
         *  RelationalOperator: '<S249>/Compare'
         *  Saturate: '<S243>/Saturation4'
         *  Sum: '<S248>/Sum1'
         */
        if (rtb_BitwiseAND_a <= 3) {
          rtb_VariantMergeForOutportact_h[4] = Controller_U.FMS_Out.throttle_cmd;
        } else {
          if (rtb_Saturation2_l[0] > 1.0F) {
            /* Saturate: '<S243>/Saturation4' */
            u0_f = 1.0F;
          } else if (rtb_Saturation2_l[0] < -1.0F) {
            /* Saturate: '<S243>/Saturation4' */
            u0_f = -1.0F;
          } else {
            /* Saturate: '<S243>/Saturation4' */
            u0_f = rtb_Saturation2_l[0];
          }

          /* Saturate: '<S248>/Saturation' incorporates:
           *  Saturate: '<S243>/Saturation4'
           */
          if (u0_f < 0.0F) {
            u0_f = 0.0F;
          }

          /* End of Saturate: '<S248>/Saturation' */
          rtb_VariantMergeForOutportact_h[4] = (uint16_T)((uint32_T)fmodf(floorf
            (1000.0F * u0_f), 4.2949673E+9F) + 1000U);
        }

        /* End of Switch: '<S247>/Switch' */

        /* Saturate: '<S244>/Saturation2' */
        if (rtb_Saturation1[2] > 1.0F) {
          u0_f = 1.0F;
        } else if (rtb_Saturation1[2] < -1.0F) {
          u0_f = -1.0F;
        } else {
          u0_f = rtb_Saturation1[2];
        }

        /* End of Saturate: '<S244>/Saturation2' */

        /* Saturate: '<S250>/Saturation' */
        if (u0_f < 0.0F) {
          u0_f = 0.0F;
        }

        /* End of Saturate: '<S250>/Saturation' */

        /* DataTypeConversion: '<S250>/Data Type Conversion' incorporates:
         *  Constant: '<S250>/Constant1'
         *  Gain: '<S250>/Gain1'
         *  Sum: '<S250>/Sum1'
         */
        rtb_DataTypeConversion_i = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          u0_f), 4.2949673E+9F) + 1000U);

        /* Saturate: '<S244>/Saturation1' */
        if (rtb_Saturation2[0] > 1.0F) {
          tmp_c = 1.0F;
        } else if (rtb_Saturation2[0] < -1.0F) {
          tmp_c = -1.0F;
        } else {
          tmp_c = rtb_Saturation2[0];
        }

        if (rtb_Saturation2[1] > 1.0F) {
          tmp_n = 1.0F;
        } else if (rtb_Saturation2[1] < -1.0F) {
          tmp_n = -1.0F;
        } else {
          tmp_n = rtb_Saturation2[1];
        }

        if (rtb_Saturation2[2] > 1.0F) {
          tmp_k = 1.0F;
        } else if (rtb_Saturation2[2] < -1.0F) {
          tmp_k = -1.0F;
        } else {
          tmp_k = rtb_Saturation2[2];
        }

        /* End of Saturate: '<S244>/Saturation1' */

        /* Product: '<S244>/Multiply' incorporates:
         *  Constant: '<S244>/Effective_Matrix'
         */
        for (i_f = 0; i_f < 4; i_f++) {
          tmp_f[i_f] = Controller_ConstP.pooled16[i_f + 8] * tmp_k +
            (Controller_ConstP.pooled16[i_f + 4] * tmp_n +
             Controller_ConstP.pooled16[i_f] * tmp_c);
        }

        /* End of Product: '<S244>/Multiply' */

        /* Saturate: '<S243>/Saturation5' */
        if (rtb_Saturation1_f[0] > 1.0F) {
          tmp_c = 1.0F;
        } else if (rtb_Saturation1_f[0] < -1.0F) {
          tmp_c = -1.0F;
        } else {
          tmp_c = rtb_Saturation1_f[0];
        }

        if (rtb_Saturation1_f[1] > 1.0F) {
          tmp_n = 1.0F;
        } else if (rtb_Saturation1_f[1] < -1.0F) {
          tmp_n = -1.0F;
        } else {
          tmp_n = rtb_Saturation1_f[1];
        }

        if (rtb_Saturation1_f[2] > 1.0F) {
          tmp_k = 1.0F;
        } else if (rtb_Saturation1_f[2] < -1.0F) {
          tmp_k = -1.0F;
        } else {
          tmp_k = rtb_Saturation1_f[2];
        }

        /* End of Saturate: '<S243>/Saturation5' */

        /* Product: '<S243>/Multiply1' incorporates:
         *  Saturate: '<S243>/Saturation1'
         */
        for (i_f = 0; i_f < 4; i_f++) {
          /* Saturate: '<S244>/Saturation' incorporates:
           *  Gain: '<S244>/Gain'
           *  Sum: '<S244>/Add'
           */
          u0_f = fmodf(floorf(1000.0F * tmp_f[i_f] + (real32_T)
                              rtb_DataTypeConversion_i), 65536.0F);
          u0_c = (uint16_T)(u0_f < 0.0F ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
                            -u0_f : (int32_T)(uint16_T)u0_f);
          if (u0_c > 1900) {
            rtb_VariantMergeForOutportact_h[i_f] = 1900U;
          } else if (u0_c < 1000) {
            rtb_VariantMergeForOutportact_h[i_f] = 1000U;
          } else {
            rtb_VariantMergeForOutportact_h[i_f] = u0_c;
          }

          /* End of Saturate: '<S244>/Saturation' */

          /* Saturate: '<S243>/Saturation1' incorporates:
           *  Bias: '<S243>/Bias'
           *  Gain: '<S243>/Gain1'
           */
          u0_f = 500.0F * (rtb_MatrixConcatenate[i_f + 8] * tmp_k +
                           (rtb_MatrixConcatenate[i_f + 4] * tmp_n +
                            rtb_MatrixConcatenate[i_f] * tmp_c)) + 1500.0F;
          if (u0_f > 2000.0F) {
            u0_f = 2000.0F;
          } else {
            if (u0_f < 1000.0F) {
              u0_f = 1000.0F;
            }
          }

          rtb_VariantMergeForOutportact_h[i_f + 5] = (uint16_T)fmodf(floorf(u0_f),
            65536.0F);
        }

        /* End of Product: '<S243>/Multiply1' */
        break;

       default:
        for (i_f = 0; i_f < 9; i_f++) {
          rtb_VariantMergeForOutportact_h[i_f] = Controller_ConstP.pooled37[i_f];
        }
        break;
      }

      /* End of MultiPortSwitch: '<S245>/Multiport Switch' */
    }

#elif AIRFRAME == 2

    /* Output and update for atomic system: '<S240>/VTOL2' */
    {
      real32_T rtb_MatrixConcatenate_g[12];
      real32_T rtb_Multiply_ka[4];
      uint16_T rtb_DataTypeConversion_f;
      uint16_T rtb_Switch_f;
      real32_T rtb_Saturation_kl[9];
      int32_T i_b;
      uint16_T rtb_Switch_f_b[5];
      real32_T tmp_b;
      real32_T tmp_o;
      real32_T tmp_c;
      real32_T u0_b;

      /* Saturate: '<S259>/Saturation' incorporates:
       *  Bias: '<S259>/Bias'
       *  Bias: '<S259>/Bias1'
       *  Bias: '<S259>/Bias2'
       *  Bias: '<S259>/Bias3'
       *  Constant: '<S259>/Constant'
       */
      for (i_b = 0; i_b < 5; i_b++) {
        rtb_Saturation_kl[i_b] = 1000.0F;
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

      /* End of Saturate: '<S259>/Saturation' */

      /* MultiPortSwitch: '<S253>/Multiport Switch' incorporates:
       *  Constant: '<S254>/Constant1'
       *  Constant: '<S254>/Constant11'
       *  Constant: '<S254>/Constant12'
       *  Constant: '<S254>/Constant2'
       *  Constant: '<S254>/Constant7'
       *  Constant: '<S254>/Constant8'
       *  DataTypeConversion: '<S259>/Data Type Conversion'
       *  DataTypeConversion: '<S260>/Data Type Conversion'
       *  Inport: '<Root>/FMS_Out'
       *  Saturate: '<S260>/Saturation'
       */
      switch (Controller_U.FMS_Out.status) {
       case 1:
        for (i_b = 0; i_b < 9; i_b++) {
          rtb_VariantMergeForOutportact_h[i_b] = (uint16_T)fmodf(floorf
            (rtb_Saturation_kl[i_b]), 65536.0F);
        }
        break;

       case 2:
        for (i_b = 0; i_b < 5; i_b++) {
          rtb_VariantMergeForOutportact_h[i_b] = 1150U;
        }

        /* Saturate: '<S260>/Saturation' incorporates:
         *  Bias: '<S260>/Bias'
         *  Constant: '<S260>/Constant'
         *  DataTypeConversion: '<S260>/Data Type Conversion'
         */
        if (1500.0F + CONTROL_PARAM.SERVO1_BIAS > 2000.0F) {
          u0_b = 2000.0F;
        } else if (1500.0F + CONTROL_PARAM.SERVO1_BIAS < 1000.0F) {
          u0_b = 1000.0F;
        } else {
          u0_b = 1500.0F + CONTROL_PARAM.SERVO1_BIAS;
        }

        rtb_VariantMergeForOutportact_h[5] = (uint16_T)fmodf(floorf(u0_b),
          65536.0F);

        /* Saturate: '<S260>/Saturation' incorporates:
         *  Bias: '<S260>/Bias1'
         *  Constant: '<S260>/Constant'
         *  DataTypeConversion: '<S260>/Data Type Conversion'
         */
        if (1500.0F + CONTROL_PARAM.SERVO2_BIAS > 2000.0F) {
          u0_b = 2000.0F;
        } else if (1500.0F + CONTROL_PARAM.SERVO2_BIAS < 1000.0F) {
          u0_b = 1000.0F;
        } else {
          u0_b = 1500.0F + CONTROL_PARAM.SERVO2_BIAS;
        }

        rtb_VariantMergeForOutportact_h[6] = (uint16_T)fmodf(floorf(u0_b),
          65536.0F);

        /* Saturate: '<S260>/Saturation' incorporates:
         *  Bias: '<S260>/Bias2'
         *  Constant: '<S260>/Constant'
         *  DataTypeConversion: '<S260>/Data Type Conversion'
         */
        if (1500.0F + CONTROL_PARAM.SERVO3_BIAS > 2000.0F) {
          u0_b = 2000.0F;
        } else if (1500.0F + CONTROL_PARAM.SERVO3_BIAS < 1000.0F) {
          u0_b = 1000.0F;
        } else {
          u0_b = 1500.0F + CONTROL_PARAM.SERVO3_BIAS;
        }

        rtb_VariantMergeForOutportact_h[7] = (uint16_T)fmodf(floorf(u0_b),
          65536.0F);

        /* Saturate: '<S260>/Saturation' incorporates:
         *  Bias: '<S260>/Bias3'
         *  Constant: '<S260>/Constant'
         *  DataTypeConversion: '<S260>/Data Type Conversion'
         */
        if (1500.0F + CONTROL_PARAM.SERVO4_BIAS > 2000.0F) {
          u0_b = 2000.0F;
        } else if (1500.0F + CONTROL_PARAM.SERVO4_BIAS < 1000.0F) {
          u0_b = 1000.0F;
        } else {
          u0_b = 1500.0F + CONTROL_PARAM.SERVO4_BIAS;
        }

        rtb_VariantMergeForOutportact_h[8] = (uint16_T)fmodf(floorf(u0_b),
          65536.0F);
        break;

       case 3:
        /* Switch: '<S255>/Switch' incorporates:
         *  Constant: '<S256>/Constant1'
         *  Constant: '<S257>/Constant'
         *  DataTypeConversion: '<S256>/Data Type Conversion'
         *  Gain: '<S256>/Gain1'
         *  RelationalOperator: '<S257>/Compare'
         *  Saturate: '<S251>/Saturation4'
         *  Sum: '<S256>/Sum1'
         */
        if (rtb_BitwiseAND_a <= 3) {
          rtb_Switch_f = Controller_U.FMS_Out.throttle_cmd;
        } else {
          if (rtb_Saturation2_l[0] > 1.0F) {
            /* Saturate: '<S251>/Saturation4' */
            u0_b = 1.0F;
          } else if (rtb_Saturation2_l[0] < -1.0F) {
            /* Saturate: '<S251>/Saturation4' */
            u0_b = -1.0F;
          } else {
            /* Saturate: '<S251>/Saturation4' */
            u0_b = rtb_Saturation2_l[0];
          }

          /* Saturate: '<S256>/Saturation' incorporates:
           *  Saturate: '<S251>/Saturation4'
           */
          if (u0_b < 0.0F) {
            u0_b = 0.0F;
          }

          /* End of Saturate: '<S256>/Saturation' */
          rtb_Switch_f = (uint16_T)((uint32_T)fmodf(floorf(1000.0F * u0_b),
            4.2949673E+9F) + 1000U);
        }

        /* End of Switch: '<S255>/Switch' */
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
        if (rtb_Saturation1_f[0] > 1.0F) {
          tmp_b = 1.0F;
        } else if (rtb_Saturation1_f[0] < -1.0F) {
          tmp_b = -1.0F;
        } else {
          tmp_b = rtb_Saturation1_f[0];
        }

        if (rtb_Saturation1_f[1] > 1.0F) {
          tmp_o = 1.0F;
        } else if (rtb_Saturation1_f[1] < -1.0F) {
          tmp_o = -1.0F;
        } else {
          tmp_o = rtb_Saturation1_f[1];
        }

        if (rtb_Saturation1_f[2] > 1.0F) {
          tmp_c = 1.0F;
        } else if (rtb_Saturation1_f[2] < -1.0F) {
          tmp_c = -1.0F;
        } else {
          tmp_c = rtb_Saturation1_f[2];
        }

        /* End of Saturate: '<S251>/Saturation5' */
        for (i_b = 0; i_b < 4; i_b++) {
          /* Bias: '<S251>/Bias' incorporates:
           *  Gain: '<S251>/Gain1'
           *  Product: '<S251>/Multiply1'
           */
          rtb_Multiply_ka[i_b] = 500.0F * (rtb_MatrixConcatenate_g[i_b + 8] *
            tmp_c + (rtb_MatrixConcatenate_g[i_b + 4] * tmp_o +
                     rtb_MatrixConcatenate_g[i_b] * tmp_b)) + 1500.0F;
        }

        /* Saturate: '<S252>/Saturation2' */
        if (rtb_Saturation1[2] > 1.0F) {
          u0_b = 1.0F;
        } else if (rtb_Saturation1[2] < -1.0F) {
          u0_b = -1.0F;
        } else {
          u0_b = rtb_Saturation1[2];
        }

        /* End of Saturate: '<S252>/Saturation2' */

        /* Saturate: '<S258>/Saturation' */
        if (u0_b < 0.0F) {
          u0_b = 0.0F;
        }

        /* End of Saturate: '<S258>/Saturation' */

        /* DataTypeConversion: '<S258>/Data Type Conversion' incorporates:
         *  Constant: '<S258>/Constant1'
         *  Gain: '<S258>/Gain1'
         *  Sum: '<S258>/Sum1'
         */
        rtb_DataTypeConversion_f = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          u0_b), 4.2949673E+9F) + 1000U);

        /* Saturate: '<S252>/Saturation1' */
        if (rtb_Saturation2[0] > 1.0F) {
          tmp_b = 1.0F;
        } else if (rtb_Saturation2[0] < -1.0F) {
          tmp_b = -1.0F;
        } else {
          tmp_b = rtb_Saturation2[0];
        }

        if (rtb_Saturation2[1] > 1.0F) {
          tmp_o = 1.0F;
        } else if (rtb_Saturation2[1] < -1.0F) {
          tmp_o = -1.0F;
        } else {
          tmp_o = rtb_Saturation2[1];
        }

        if (rtb_Saturation2[2] > 1.0F) {
          tmp_c = 1.0F;
        } else if (rtb_Saturation2[2] < -1.0F) {
          tmp_c = -1.0F;
        } else {
          tmp_c = rtb_Saturation2[2];
        }

        /* End of Saturate: '<S252>/Saturation1' */

        /* Saturate: '<S251>/Saturation1' */
        rtb_Switch_f_b[0] = rtb_Switch_f;

        /* DataTypeConversion: '<S251>/Data Type Conversion' incorporates:
         *  Bias: '<S251>/Bias1'
         */
        u0_b = fmodf(floorf(rtb_Multiply_ka[0] + CONTROL_PARAM.SERVO1_BIAS),
                     65536.0F);

        /* Saturate: '<S251>/Saturation1' incorporates:
         *  DataTypeConversion: '<S251>/Data Type Conversion'
         */
        rtb_Switch_f_b[1] = (uint16_T)(u0_b < 0.0F ? (int32_T)(uint16_T)
          -(int16_T)(uint16_T)-u0_b : (int32_T)(uint16_T)u0_b);

        /* DataTypeConversion: '<S251>/Data Type Conversion1' incorporates:
         *  Bias: '<S251>/Bias2'
         */
        u0_b = fmodf(floorf(rtb_Multiply_ka[1] + CONTROL_PARAM.SERVO2_BIAS),
                     65536.0F);

        /* Saturate: '<S251>/Saturation1' incorporates:
         *  DataTypeConversion: '<S251>/Data Type Conversion1'
         */
        rtb_Switch_f_b[2] = (uint16_T)(u0_b < 0.0F ? (int32_T)(uint16_T)
          -(int16_T)(uint16_T)-u0_b : (int32_T)(uint16_T)u0_b);

        /* DataTypeConversion: '<S251>/Data Type Conversion2' incorporates:
         *  Bias: '<S251>/Bias3'
         */
        u0_b = fmodf(floorf(rtb_Multiply_ka[2] + CONTROL_PARAM.SERVO3_BIAS),
                     65536.0F);

        /* Saturate: '<S251>/Saturation1' incorporates:
         *  DataTypeConversion: '<S251>/Data Type Conversion2'
         */
        rtb_Switch_f_b[3] = (uint16_T)(u0_b < 0.0F ? (int32_T)(uint16_T)
          -(int16_T)(uint16_T)-u0_b : (int32_T)(uint16_T)u0_b);

        /* DataTypeConversion: '<S251>/Data Type Conversion3' incorporates:
         *  Bias: '<S251>/Bias4'
         */
        u0_b = fmodf(floorf(rtb_Multiply_ka[3] + CONTROL_PARAM.SERVO4_BIAS),
                     65536.0F);

        /* Saturate: '<S251>/Saturation1' incorporates:
         *  DataTypeConversion: '<S251>/Data Type Conversion3'
         */
        rtb_Switch_f_b[4] = (uint16_T)(u0_b < 0.0F ? (int32_T)(uint16_T)
          -(int16_T)(uint16_T)-u0_b : (int32_T)(uint16_T)u0_b);

        /* Product: '<S252>/Multiply' */
        for (i_b = 0; i_b < 4; i_b++) {
          /* Saturate: '<S252>/Saturation' incorporates:
           *  Constant: '<S252>/Effective_Matrix'
           *  Gain: '<S252>/Gain'
           *  Sum: '<S252>/Add'
           */
          u0_b = fmodf(floorf(1000.0F * (Controller_ConstP.pooled16[i_b + 8] *
            tmp_c + (Controller_ConstP.pooled16[i_b + 4] * tmp_o +
                     Controller_ConstP.pooled16[i_b] * tmp_b)) + (real32_T)
                              rtb_DataTypeConversion_f), 65536.0F);
          rtb_Switch_f = (uint16_T)(u0_b < 0.0F ? (int32_T)(uint16_T)-(int16_T)
            (uint16_T)-u0_b : (int32_T)(uint16_T)u0_b);
          if (rtb_Switch_f > 1900) {
            rtb_VariantMergeForOutportact_h[i_b] = 1900U;
          } else if (rtb_Switch_f < 1000) {
            rtb_VariantMergeForOutportact_h[i_b] = 1000U;
          } else {
            rtb_VariantMergeForOutportact_h[i_b] = rtb_Switch_f;
          }

          /* End of Saturate: '<S252>/Saturation' */
        }

        /* End of Product: '<S252>/Multiply' */
        for (i_b = 0; i_b < 5; i_b++) {
          /* Saturate: '<S251>/Saturation1' */
          if (rtb_Switch_f_b[i_b] > 2000) {
            rtb_VariantMergeForOutportact_h[i_b + 4] = 2000U;
          } else if (rtb_Switch_f_b[i_b] < 1000) {
            rtb_VariantMergeForOutportact_h[i_b + 4] = 1000U;
          } else {
            rtb_VariantMergeForOutportact_h[i_b + 4] = rtb_Switch_f_b[i_b];
          }
        }
        break;

       default:
        for (i_b = 0; i_b < 9; i_b++) {
          rtb_VariantMergeForOutportact_h[i_b] = (uint16_T)fmodf(floorf
            (rtb_Saturation_kl[i_b]), 65536.0F);
        }
        break;
      }

      /* End of MultiPortSwitch: '<S253>/Multiport Switch' */
    }

#endif

    /* End of Outputs for SubSystem: '<S147>/VTOL_Control_Allocation' */
    for (i = 0; i < 9; i++) {
      /* Outport: '<Root>/Control_Out' incorporates:
       *  Reshape: '<S239>/Reshape'
       */
      Controller_Y.Control_Out.actuator_cmd[i] =
        rtb_VariantMergeForOutportact_h[i];
    }

    for (i = 0; i < 7; i++) {
      /* Outport: '<Root>/Control_Out' incorporates:
       *  Reshape: '<S239>/Reshape'
       */
      Controller_Y.Control_Out.actuator_cmd[i + 9] = 0U;
    }

    /* Product: '<S161>/Multiply' incorporates:
     *  Constant: '<S161>/gain1'
     *  Constant: '<S161>/gain2'
     *  Constant: '<S161>/gain3'
     *  DiscreteIntegrator: '<S159>/Discrete-Time Integrator5'
     */
    rtb_Multiply_ga_idx_0 = CONTROL_PARAM.MC_ROLL_RATE_I *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0];
    rtb_Saturation1_ih = CONTROL_PARAM.MC_PITCH_RATE_I *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1];
    rtb_VdotPg = CONTROL_PARAM.MC_YAW_RATE_I *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2];

    /* Product: '<S184>/Multiply1' incorporates:
     *  Constant: '<S184>/const1'
     *  DiscreteIntegrator: '<S183>/Integrator'
     */
    rtb_Saturation1_h_idx_0 = Controller_DW.Integrator_DSTATE_f * 0.05F;

    /* Switch: '<S174>/Switch' incorporates:
     *  Constant: '<S174>/Zero'
     *  Constant: '<S177>/Constant'
     *  RelationalOperator: '<S177>/Compare'
     */
    if (rtb_BitwiseAND_a <= 3) {
      rtb_MatrixConcatenate1_tmp = 0.0F;
    } else {
      rtb_MatrixConcatenate1_tmp = Controller_U.FMS_Out.w_cmd;
    }

    /* End of Switch: '<S174>/Switch' */

    /* Sum: '<S184>/Add' incorporates:
     *  DiscreteIntegrator: '<S183>/Integrator1'
     *  Sum: '<S183>/Subtract'
     */
    rtb_Cos1_d = (Controller_DW.Integrator1_DSTATE_i -
                  rtb_MatrixConcatenate1_tmp) + rtb_Saturation1_h_idx_0;

    /* Signum: '<S184>/Sign' */
    if (rtb_Cos1_d < 0.0F) {
      rtb_Divide_i_idx_0 = -1.0F;
    } else if (rtb_Cos1_d > 0.0F) {
      rtb_Divide_i_idx_0 = 1.0F;
    } else {
      rtb_Divide_i_idx_0 = rtb_Cos1_d;
    }

    /* End of Signum: '<S184>/Sign' */

    /* Sum: '<S184>/Add2' incorporates:
     *  Abs: '<S184>/Abs'
     *  Gain: '<S184>/Gain'
     *  Gain: '<S184>/Gain1'
     *  Product: '<S184>/Multiply2'
     *  Product: '<S184>/Multiply3'
     *  Sqrt: '<S184>/Sqrt'
     *  Sum: '<S184>/Add1'
     *  Sum: '<S184>/Subtract'
     */
    rtb_Divide_i_idx_0 = (sqrtf((8.0F * fabsf(rtb_Cos1_d) +
      Controller_ConstB.d_m) * Controller_ConstB.d_m) - Controller_ConstB.d_m) *
      0.5F * rtb_Divide_i_idx_0 + rtb_Saturation1_h_idx_0;

    /* Sum: '<S184>/Add4' */
    rtb_Saturation1_h_idx_0 += rtb_Cos1_d - rtb_Divide_i_idx_0;

    /* Sum: '<S184>/Add3' */
    rtb_Abs = rtb_Cos1_d + Controller_ConstB.d_m;

    /* Sum: '<S184>/Subtract1' */
    rtb_Cos1_d -= Controller_ConstB.d_m;

    /* Signum: '<S184>/Sign1' */
    if (rtb_Abs < 0.0F) {
      rtb_Abs = -1.0F;
    } else {
      if (rtb_Abs > 0.0F) {
        rtb_Abs = 1.0F;
      }
    }

    /* End of Signum: '<S184>/Sign1' */

    /* Signum: '<S184>/Sign2' */
    if (rtb_Cos1_d < 0.0F) {
      rtb_Cos1_d = -1.0F;
    } else {
      if (rtb_Cos1_d > 0.0F) {
        rtb_Cos1_d = 1.0F;
      }
    }

    /* End of Signum: '<S184>/Sign2' */

    /* Sum: '<S184>/Add5' incorporates:
     *  Gain: '<S184>/Gain2'
     *  Product: '<S184>/Multiply4'
     *  Sum: '<S184>/Subtract2'
     */
    rtb_Divide_i_idx_0 += (rtb_Abs - rtb_Cos1_d) * 0.5F *
      rtb_Saturation1_h_idx_0;

    /* Update for DiscreteIntegrator: '<S191>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S191>/Gain'
     *  Sum: '<S191>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_L_eo = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_a += (rtb_Divide_gn -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_a) * 31.415926F * 0.002F;

    /* Update for DiscreteIntegrator: '<S190>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S190>/Gain'
     *  Sum: '<S190>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_o = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTA_a2 += ((real32_T)rtb_Relay -
      Controller_DW.DiscreteTimeIntegrator5_DSTA_a2) * 6.28318548F * 0.002F;

    /* Update for DiscreteIntegrator: '<S183>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S183>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_i += 0.002F *
      Controller_DW.Integrator_DSTATE_f;

    /* Update for DiscreteIntegrator: '<S186>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S186>/ki'
     *  Product: '<S186>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_b += CONTROL_PARAM.MC_VEL_Z_I *
      rtb_Gain_ms * 0.002F;
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

    /* End of Update for DiscreteIntegrator: '<S186>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S188>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_i = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTA_ld += 0.002F * rtb_Gain_it;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_h = (int8_T)
      rtb_LogicalOperator_b3;

    /* Update for DiscreteIntegrator: '<S226>/ ' incorporates:
     *  Gain: '<S226>/Gain3'
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

    /* End of Update for DiscreteIntegrator: '<S226>/ ' */

    /* Update for DiscreteIntegrator: '<S227>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_f = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_e += 0.002F * rtb_Gain_il;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_b = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S159>/Discrete-Time Integrator5' */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_b = 0U;

    /* Update for DiscreteIntegrator: '<S161>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_PrevRe_o = (int8_T)
      rtb_LogicalOperator_m;

    /* Update for DiscreteIntegrator: '<S163>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_L_h2 = 0U;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_l = (int8_T)
      rtb_LogicalOperator_m;

    /* Update for DiscreteIntegrator: '<S189>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S189>/Gain'
     *  Sum: '<S189>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_g = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_j += (rtb_Saturation_ov -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j) * 12.566371F * 0.002F;

    /* Update for DiscreteIntegrator: '<S159>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S159>/Gain'
     *  Sum: '<S159>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0] += (rtb_Add_c -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S161>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_d[0] += 0.002F *
      rtb_Multiply_ga_idx_0;
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

    /* Update for DiscreteIntegrator: '<S163>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[0] += 0.002F *
      rtb_DiscreteTimeIntegrator1_k1[0];

    /* Update for DiscreteIntegrator: '<S201>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S201>/gain1'
     *  Product: '<S201>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0] +=
      CONTROL_PARAM.FW_ROLL_RATE_I * rtb_Divide_i_idx_1 * 0.002F;
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

    /* Update for DiscreteIntegrator: '<S159>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S159>/Gain'
     *  Sum: '<S159>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1] += (rtb_FF_limit_idx_1 -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S161>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_d[1] += 0.002F *
      rtb_Saturation1_ih;
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

    /* Update for DiscreteIntegrator: '<S163>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[1] += 0.002F *
      rtb_DiscreteTimeIntegrator1_k1[1];

    /* Update for DiscreteIntegrator: '<S201>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S201>/gain2'
     *  Product: '<S201>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1] +=
      CONTROL_PARAM.FW_PITCH_RATE_I * rtb_Divide_i_idx_2 * 0.002F;
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

    /* Update for DiscreteIntegrator: '<S159>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S159>/Gain'
     *  Sum: '<S159>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2] += (rtb_FF_limit_idx_2 -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S161>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_d[2] += 0.002F * rtb_VdotPg;
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

    /* Update for DiscreteIntegrator: '<S163>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[2] += 0.002F *
      rtb_DiscreteTimeIntegrator1_k1[2];

    /* Update for DiscreteIntegrator: '<S201>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S201>/gain3'
     *  Product: '<S201>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2] +=
      CONTROL_PARAM.FW_YAW_RATE_I * rtb_Divide_i_idx_3 * 0.002F;
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

    /* Update for DiscreteIntegrator: '<S229>/ ' incorporates:
     *  Gain: '<S229>/Gain'
     */
    Controller_DW._DSTATE_d += CONTROL_PARAM.FW_TECS_THOR_I * rtb_Cos_j * 0.002F;
    if (Controller_DW._DSTATE_d >= 0.3F) {
      Controller_DW._DSTATE_d = 0.3F;
    } else {
      if (Controller_DW._DSTATE_d <= -0.3F) {
        Controller_DW._DSTATE_d = -0.3F;
      }
    }

    Controller_DW._PrevResetState_e = (int8_T)(Controller_U.FMS_Out.reset > 0);

    /* End of Update for DiscreteIntegrator: '<S229>/ ' */

    /* Update for DiscreteIntegrator: '<S230>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_L_h0 = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTA_nm += 0.002F * rtb_Gain_cu;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_d = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Signum: '<S184>/Sign6' incorporates:
     *  Signum: '<S184>/Sign5'
     */
    if (rtb_Divide_i_idx_0 < 0.0F) {
      rtb_FF_limit_idx_1 = -1.0F;

      /* Signum: '<S184>/Sign5' */
      rtb_FF_limit_idx_2 = -1.0F;
    } else if (rtb_Divide_i_idx_0 > 0.0F) {
      rtb_FF_limit_idx_1 = 1.0F;

      /* Signum: '<S184>/Sign5' */
      rtb_FF_limit_idx_2 = 1.0F;
    } else {
      rtb_FF_limit_idx_1 = rtb_Divide_i_idx_0;

      /* Signum: '<S184>/Sign5' */
      rtb_FF_limit_idx_2 = rtb_Divide_i_idx_0;
    }

    /* End of Signum: '<S184>/Sign6' */

    /* Sum: '<S184>/Add6' */
    rtb_Abs = rtb_Divide_i_idx_0 + Controller_ConstB.d_m;

    /* Sum: '<S184>/Subtract3' */
    rtb_Add_c = rtb_Divide_i_idx_0 - Controller_ConstB.d_m;

    /* Signum: '<S184>/Sign3' */
    if (rtb_Abs < 0.0F) {
      rtb_Abs = -1.0F;
    } else {
      if (rtb_Abs > 0.0F) {
        rtb_Abs = 1.0F;
      }
    }

    /* End of Signum: '<S184>/Sign3' */

    /* Signum: '<S184>/Sign4' */
    if (rtb_Add_c < 0.0F) {
      rtb_Add_c = -1.0F;
    } else {
      if (rtb_Add_c > 0.0F) {
        rtb_Add_c = 1.0F;
      }
    }

    /* End of Signum: '<S184>/Sign4' */

    /* Update for DiscreteIntegrator: '<S183>/Integrator' incorporates:
     *  Constant: '<S184>/const'
     *  Gain: '<S184>/Gain3'
     *  Product: '<S184>/Divide'
     *  Product: '<S184>/Multiply5'
     *  Product: '<S184>/Multiply6'
     *  Sum: '<S184>/Subtract4'
     *  Sum: '<S184>/Subtract5'
     *  Sum: '<S184>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE_f += ((rtb_Divide_i_idx_0 /
      Controller_ConstB.d_m - rtb_FF_limit_idx_2) * Controller_ConstB.Gain4_o *
      ((rtb_Abs - rtb_Add_c) * 0.5F) - rtb_FF_limit_idx_1 * 78.448F) * 0.002F;

    /* End of Outputs for SubSystem: '<S2>/VTOL_Controller' */
    break;

   case 1:
    if (Controller_DW.SwitchCase1_ActiveSubsystem != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S2>/BackTrans_Controller' incorporates:
       *  ActionPort: '<S4>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S8>/Switch Case1' incorporates:
       *  DiscreteIntegrator: '<S23>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S25>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S27>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S42>/Integrator'
       *  DiscreteIntegrator: '<S42>/Integrator1'
       *  DiscreteIntegrator: '<S47>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S49>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S54>/Integrator'
       *  DiscreteIntegrator: '<S54>/Integrator1'
       *  DiscreteIntegrator: '<S57>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S59>/Discrete-Time Integrator1'
       */
      Controller_DW.Integrator1_DSTATE_h[0] = 0.0F;
      Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[0] =
        Controller_ConstB.Constant_e4;
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[0] >=
          CONTROL_PARAM.MC_VEL_XY_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[0] =
          CONTROL_PARAM.MC_VEL_XY_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[0] <=
            CONTROL_PARAM.MC_VEL_XY_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[0] =
            CONTROL_PARAM.MC_VEL_XY_I_MIN;
        }
      }

      Controller_DW.Integrator1_DSTATE_h[1] = 0.0F;
      Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[1] =
        Controller_ConstB.Constant_e4;
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[1] >=
          CONTROL_PARAM.MC_VEL_XY_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[1] =
          CONTROL_PARAM.MC_VEL_XY_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[1] <=
            CONTROL_PARAM.MC_VEL_XY_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[1] =
            CONTROL_PARAM.MC_VEL_XY_I_MIN;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_PrevRe_a = 0;
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_h = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevR_p = 0;
      Controller_DW.DiscreteTimeIntegrator5_IC_LO_e = 1U;
      Controller_DW.DiscreteTimeIntegrator_DSTATE_g[0] =
        Controller_ConstB.Constant_a[0];
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_g[0] >=
          CONTROL_PARAM.MC_RATE_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_g[0] =
          CONTROL_PARAM.MC_RATE_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_g[0] <=
            CONTROL_PARAM.MC_RATE_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_g[0] =
            CONTROL_PARAM.MC_RATE_I_MIN;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_DSTATE_g[1] =
        Controller_ConstB.Constant_a[1];
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_g[1] >=
          CONTROL_PARAM.MC_RATE_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_g[1] =
          CONTROL_PARAM.MC_RATE_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_g[1] <=
            CONTROL_PARAM.MC_RATE_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_g[1] =
            CONTROL_PARAM.MC_RATE_I_MIN;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_DSTATE_g[2] =
        Controller_ConstB.Constant_a[2];
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_g[2] >=
          CONTROL_PARAM.MC_RATE_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_g[2] =
          CONTROL_PARAM.MC_RATE_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_g[2] <=
            CONTROL_PARAM.MC_RATE_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_g[2] =
            CONTROL_PARAM.MC_RATE_I_MIN;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_PrevR_ps = 0;
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_p = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevR_c = 0;
      Controller_DW.Integrator1_DSTATE_o = 0.0F;
      Controller_DW.DiscreteTimeIntegrator_DSTATE_p = Controller_B.Constant_i;
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_p >=
          CONTROL_PARAM.MC_VEL_Z_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_p =
          CONTROL_PARAM.MC_VEL_Z_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_p <=
            CONTROL_PARAM.MC_VEL_Z_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_p =
            CONTROL_PARAM.MC_VEL_Z_I_MIN;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_PrevRe_c = 0;
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_b = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevR_a = 0;
      Controller_DW.Integrator_DSTATE_jg[0] = 0.0F;
      Controller_DW.Integrator_DSTATE_jg[1] = 0.0F;
      Controller_DW.Integrator_DSTATE_e = 0.0F;

      /* End of InitializeConditions for SubSystem: '<S2>/BackTrans_Controller' */
    }

    /* Outputs for IfAction SubSystem: '<S2>/BackTrans_Controller' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* Trigonometry: '<S44>/Trigonometric Function1' incorporates:
     *  Gain: '<S43>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1[0] = arm_cos_f32(-Controller_U.INS_Out.psi);

    /* Trigonometry: '<S44>/Trigonometric Function' incorporates:
     *  Gain: '<S43>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1[1] = arm_sin_f32(-Controller_U.INS_Out.psi);

    /* SignalConversion: '<S44>/ConcatBufferAtVector Concatenate1In3' incorporates:
     *  Constant: '<S44>/Constant3'
     */
    rtb_MatrixConcatenate1[2] = 0.0F;

    /* Gain: '<S44>/Gain' incorporates:
     *  Gain: '<S43>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S44>/Trigonometric Function2'
     */
    rtb_MatrixConcatenate1[3] = -arm_sin_f32(-Controller_U.INS_Out.psi);

    /* Trigonometry: '<S44>/Trigonometric Function3' incorporates:
     *  Gain: '<S43>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1[4] = arm_cos_f32(-Controller_U.INS_Out.psi);

    /* SignalConversion: '<S44>/ConcatBufferAtVector Concatenate2In3' incorporates:
     *  Constant: '<S44>/Constant4'
     */
    rtb_MatrixConcatenate1[5] = 0.0F;

    /* SignalConversion: '<S44>/ConcatBufferAtVector ConcatenateIn3' */
    rtb_MatrixConcatenate1[6] = Controller_ConstB.VectorConcatenate3_a[0];
    rtb_MatrixConcatenate1[7] = Controller_ConstB.VectorConcatenate3_a[1];
    rtb_MatrixConcatenate1[8] = Controller_ConstB.VectorConcatenate3_a[2];

    /* Product: '<S41>/Multiply' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  SignalConversion: '<S41>/TmpSignal ConversionAtMultiplyInport2'
     */
    for (i = 0; i < 3; i++) {
      rtb_MatrixConcatenate1_0[i] = rtb_MatrixConcatenate1[i + 3] *
        Controller_U.INS_Out.ve + rtb_MatrixConcatenate1[i] *
        Controller_U.INS_Out.vn;
    }

    /* End of Product: '<S41>/Multiply' */

    /* Sum: '<S39>/Sum' incorporates:
     *  DiscreteIntegrator: '<S42>/Integrator1'
     */
    rtb_Divide_i_idx_0 = Controller_DW.Integrator1_DSTATE_h[0] -
      rtb_MatrixConcatenate1_0[0];
    rtb_Cos_j = Controller_DW.Integrator1_DSTATE_h[1] -
      rtb_MatrixConcatenate1_0[1];

    /* DiscreteIntegrator: '<S47>/Discrete-Time Integrator' */
    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator_PrevRe_a != 0)) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[0] =
        Controller_ConstB.Constant_e4;
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[0] >=
          CONTROL_PARAM.MC_VEL_XY_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[0] =
          CONTROL_PARAM.MC_VEL_XY_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[0] <=
            CONTROL_PARAM.MC_VEL_XY_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[0] =
            CONTROL_PARAM.MC_VEL_XY_I_MIN;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[1] =
        Controller_ConstB.Constant_e4;
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[1] >=
          CONTROL_PARAM.MC_VEL_XY_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[1] =
          CONTROL_PARAM.MC_VEL_XY_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[1] <=
            CONTROL_PARAM.MC_VEL_XY_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[1] =
            CONTROL_PARAM.MC_VEL_XY_I_MIN;
        }
      }
    }

    if (Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[0] >=
        CONTROL_PARAM.MC_VEL_XY_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[0] =
        CONTROL_PARAM.MC_VEL_XY_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[0] <=
          CONTROL_PARAM.MC_VEL_XY_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[0] =
          CONTROL_PARAM.MC_VEL_XY_I_MIN;
      }
    }

    if (Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[1] >=
        CONTROL_PARAM.MC_VEL_XY_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[1] =
        CONTROL_PARAM.MC_VEL_XY_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[1] <=
          CONTROL_PARAM.MC_VEL_XY_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[1] =
          CONTROL_PARAM.MC_VEL_XY_I_MIN;
      }
    }

    /* DiscreteIntegrator: '<S49>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_h != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_g[0] = rtb_Divide_i_idx_0;
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_g[1] = rtb_Cos_j;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_p != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_g[0] = rtb_Divide_i_idx_0;
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_g[1] = rtb_Cos_j;
    }

    /* Gain: '<S49>/Gain' incorporates:
     *  DiscreteIntegrator: '<S49>/Discrete-Time Integrator1'
     *  Sum: '<S49>/Sum5'
     */
    rtb_Saturation1_h_idx_0 = (rtb_Divide_i_idx_0 -
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_g[0]) * 62.831852F;
    rtb_Divide_gn = (rtb_Cos_j - Controller_DW.DiscreteTimeIntegrator1_DSTAT_g[1])
      * 62.831852F;

    /* Switch: '<S19>/Switch' incorporates:
     *  Constant: '<S29>/Constant'
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S28>/Multiply'
     *  Product: '<S28>/Multiply1'
     *  Product: '<S28>/Multiply3'
     *  Product: '<S28>/Multiply4'
     *  Product: '<S28>/Multiply5'
     *  Product: '<S35>/Divide1'
     *  RelationalOperator: '<S29>/Compare'
     *  Saturate: '<S18>/Saturation'
     *  Sum: '<S28>/Add'
     *  Sum: '<S28>/Add1'
     *  Sum: '<S28>/Add2'
     *  Trigonometry: '<S28>/Cos'
     *  Trigonometry: '<S28>/Cos1'
     *  Trigonometry: '<S28>/Sin'
     *  Trigonometry: '<S28>/Sin1'
     */
    if (rtb_BitwiseAND_a == 2) {
      rtb_DiscreteTimeIntegrator1_k1[0] = Controller_U.FMS_Out.p_cmd;
      rtb_DiscreteTimeIntegrator1_k1[1] = Controller_U.FMS_Out.q_cmd;
      rtb_DiscreteTimeIntegrator1_k1[2] = Controller_U.FMS_Out.r_cmd;
    } else {
      if (Controller_U.FMS_Out.psi_rate_cmd > CONTROL_PARAM.MC_R_CMD_LIM) {
        /* Saturate: '<S18>/Saturation' */
        rtb_Add_c = CONTROL_PARAM.MC_R_CMD_LIM;
      } else if (Controller_U.FMS_Out.psi_rate_cmd < -CONTROL_PARAM.MC_R_CMD_LIM)
      {
        /* Saturate: '<S18>/Saturation' */
        rtb_Add_c = -CONTROL_PARAM.MC_R_CMD_LIM;
      } else {
        /* Saturate: '<S18>/Saturation' */
        rtb_Add_c = Controller_U.FMS_Out.psi_rate_cmd;
      }

      /* Switch: '<S31>/Switch' incorporates:
       *  Logic: '<S31>/Logical Operator'
       *  RelationalOperator: '<S37>/Compare'
       *  Saturate: '<S18>/Saturation'
       *  Switch: '<S49>/Switch'
       *  Trigonometry: '<S38>/Atan'
       */
      if ((rtb_BitwiseAND_a == 3) || (rtb_BitwiseAND_a == 4)) {
        rtb_Gain_ms = Controller_U.FMS_Out.phi_cmd;
        rtb_Gain_cu = Controller_U.FMS_Out.theta_cmd;
      } else {
        if (Controller_U.FMS_Out.reset > 0) {
          /* Switch: '<S49>/Switch' incorporates:
           *  Gain: '<S49>/Gain1'
           */
          rtb_Gain_ms = 0.0F;
          rtb_Gain_cu = 0.0F;
        } else {
          /* Switch: '<S49>/Switch' */
          rtb_Gain_ms = rtb_Saturation1_h_idx_0;
          rtb_Gain_cu = rtb_Divide_gn;
        }

        /* Product: '<S46>/Multiply' incorporates:
         *  Constant: '<S46>/kd'
         */
        rtb_Divide_i_idx_1 = CONTROL_PARAM.MC_VEL_XY_D * rtb_Gain_ms;

        /* Saturate: '<S46>/Saturation' */
        if (rtb_Divide_i_idx_1 > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
          rtb_Divide_i_idx_1 = CONTROL_PARAM.MC_VEL_XY_D_MAX;
        } else {
          if (rtb_Divide_i_idx_1 < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
            rtb_Divide_i_idx_1 = CONTROL_PARAM.MC_VEL_XY_D_MIN;
          }
        }

        /* Gain: '<S38>/Gain1' incorporates:
         *  Constant: '<S48>/kp'
         *  DiscreteIntegrator: '<S47>/Discrete-Time Integrator'
         *  Product: '<S46>/Multiply'
         *  Product: '<S48>/Multiply'
         *  Sum: '<S40>/Add'
         */
        rtb_MatrixConcatenate1_tmp = (CONTROL_PARAM.MC_VEL_XY_P *
          rtb_Divide_i_idx_0 + Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[0])
          + rtb_Divide_i_idx_1;

        /* Product: '<S46>/Multiply' incorporates:
         *  Constant: '<S46>/kd'
         */
        rtb_Divide_i_idx_1 = CONTROL_PARAM.MC_VEL_XY_D * rtb_Gain_cu;

        /* Saturate: '<S46>/Saturation' */
        if (rtb_Divide_i_idx_1 > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
          rtb_Divide_i_idx_1 = CONTROL_PARAM.MC_VEL_XY_D_MAX;
        } else {
          if (rtb_Divide_i_idx_1 < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
            rtb_Divide_i_idx_1 = CONTROL_PARAM.MC_VEL_XY_D_MIN;
          }
        }

        /* Sum: '<S40>/Add' incorporates:
         *  Constant: '<S48>/kp'
         *  DiscreteIntegrator: '<S47>/Discrete-Time Integrator'
         *  Product: '<S48>/Multiply'
         */
        rtb_Divide_i_idx_1 += CONTROL_PARAM.MC_VEL_XY_P * rtb_Cos_j +
          Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[1];

        /* Trigonometry: '<S38>/Atan' incorporates:
         *  Constant: '<S38>/g'
         *  Gain: '<S38>/gain'
         *  Product: '<S38>/Divide'
         */
        rtb_Gain_cu = atanf(1.1F * rtb_Divide_i_idx_1 / 9.8055F);

        /* Saturate: '<S38>/Saturation' */
        if (rtb_Gain_cu > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          rtb_Gain_cu = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        } else {
          if (rtb_Gain_cu < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
            rtb_Gain_cu = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
          }
        }

        rtb_Gain_ms = rtb_Gain_cu;

        /* Trigonometry: '<S38>/Atan' incorporates:
         *  Constant: '<S38>/g'
         *  Gain: '<S38>/Gain1'
         *  Gain: '<S38>/gain'
         *  Product: '<S38>/Divide'
         */
        rtb_Gain_cu = atanf(1.1F * -rtb_MatrixConcatenate1_tmp / 9.8055F);

        /* Saturate: '<S38>/Saturation' */
        if (rtb_Gain_cu > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          rtb_Gain_cu = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        } else {
          if (rtb_Gain_cu < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
            rtb_Gain_cu = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
          }
        }
      }

      /* End of Switch: '<S31>/Switch' */

      /* Sum: '<S32>/Sum' incorporates:
       *  Inport: '<Root>/INS_Out'
       */
      rtb_Divide_i_idx_1 = rtb_Gain_ms - Controller_U.INS_Out.phi;

      /* Product: '<S35>/Divide1' incorporates:
       *  Abs: '<S35>/Abs'
       *  Constant: '<S35>/const2'
       */
      rtb_Gain_it = fabsf(rtb_Divide_i_idx_1) / 0.002F;

      /* Gain: '<S35>/Gain3' */
      rtb_MatrixConcatenate1_tmp = -rtb_Gain_it;

      /* Product: '<S35>/Divide' incorporates:
       *  Constant: '<S33>/Constant1'
       *  Constant: '<S35>/const1'
       *  Math: '<S35>/Square'
       *  SignalConversion: '<S35>/TmpSignal ConversionAtSquareInport1'
       */
      rtb_FF_limit_idx_1 = 9.5993F / (CONTROL_PARAM.MC_ROLL_P *
        CONTROL_PARAM.MC_ROLL_P);

      /* Signum: '<S35>/Sign' */
      if (rtb_Divide_i_idx_1 < 0.0F) {
        rtb_FF_limit_idx_2 = -1.0F;
      } else if (rtb_Divide_i_idx_1 > 0.0F) {
        rtb_FF_limit_idx_2 = 1.0F;
      } else {
        rtb_FF_limit_idx_2 = rtb_Divide_i_idx_1;
      }

      /* Switch: '<S35>/Switch' incorporates:
       *  Constant: '<S33>/Constant1'
       *  Gain: '<S35>/Gain1'
       *  Gain: '<S35>/Gain2'
       *  Logic: '<S35>/Logical Operator'
       *  Product: '<S35>/Divide'
       *  Product: '<S35>/Multiply'
       *  Product: '<S35>/Multiply1'
       *  Product: '<S35>/Multiply2'
       *  Product: '<S35>/Multiply3'
       *  RelationalOperator: '<S35>/Relational Operator'
       *  RelationalOperator: '<S35>/Relational Operator2'
       *  SignalConversion: '<S35>/TmpSignal ConversionAtSquareInport1'
       *  Sqrt: '<S35>/Sqrt'
       *  Sum: '<S35>/Subtract'
       */
      if ((rtb_Divide_i_idx_1 <= rtb_FF_limit_idx_1) && (rtb_Divide_i_idx_1 >=
           -rtb_FF_limit_idx_1)) {
        rtb_Divide_i_idx_1 *= CONTROL_PARAM.MC_ROLL_P;
      } else {
        rtb_Divide_i_idx_1 = sqrtf((rtb_FF_limit_idx_2 * rtb_Divide_i_idx_1 -
          0.5F * rtb_FF_limit_idx_1) * Controller_ConstB.Gain_n) *
          rtb_FF_limit_idx_2;
      }

      /* Switch: '<S36>/Switch' incorporates:
       *  Gain: '<S35>/Gain3'
       *  RelationalOperator: '<S36>/UpperRelop'
       */
      if (rtb_Divide_i_idx_1 >= -rtb_Gain_it) {
        rtb_MatrixConcatenate1_tmp = rtb_Divide_i_idx_1;
      }

      /* Switch: '<S36>/Switch2' incorporates:
       *  RelationalOperator: '<S36>/LowerRelop1'
       */
      if (rtb_Divide_i_idx_1 <= rtb_Gain_it) {
        rtb_Gain_it = rtb_MatrixConcatenate1_tmp;
      }

      /* Saturate: '<S18>/Saturation1' */
      if (rtb_Gain_it > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_Gain_it = CONTROL_PARAM.MC_P_Q_CMD_LIM;
      } else {
        if (rtb_Gain_it < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
          rtb_Gain_it = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
        }
      }

      rtb_Saturation_ov = rtb_Gain_it;

      /* Sum: '<S32>/Sum' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Product: '<S35>/Divide1'
       */
      rtb_Divide_i_idx_1 = rtb_Gain_cu - Controller_U.INS_Out.theta;

      /* Product: '<S35>/Divide1' incorporates:
       *  Abs: '<S35>/Abs'
       *  Constant: '<S35>/const2'
       */
      rtb_Gain_it = fabsf(rtb_Divide_i_idx_1) / 0.002F;

      /* Gain: '<S35>/Gain3' */
      rtb_MatrixConcatenate1_tmp = -rtb_Gain_it;

      /* Product: '<S35>/Divide' incorporates:
       *  Constant: '<S33>/Constant2'
       *  Constant: '<S35>/const1'
       *  Math: '<S35>/Square'
       *  SignalConversion: '<S35>/TmpSignal ConversionAtSquareInport1'
       */
      rtb_FF_limit_idx_1 = 9.5993F / (CONTROL_PARAM.MC_PITCH_P *
        CONTROL_PARAM.MC_PITCH_P);

      /* Signum: '<S35>/Sign' */
      if (rtb_Divide_i_idx_1 < 0.0F) {
        rtb_FF_limit_idx_2 = -1.0F;
      } else if (rtb_Divide_i_idx_1 > 0.0F) {
        rtb_FF_limit_idx_2 = 1.0F;
      } else {
        rtb_FF_limit_idx_2 = rtb_Divide_i_idx_1;
      }

      /* Switch: '<S35>/Switch' incorporates:
       *  Constant: '<S33>/Constant2'
       *  Gain: '<S35>/Gain1'
       *  Gain: '<S35>/Gain2'
       *  Logic: '<S35>/Logical Operator'
       *  Product: '<S35>/Divide'
       *  Product: '<S35>/Multiply'
       *  Product: '<S35>/Multiply1'
       *  Product: '<S35>/Multiply2'
       *  Product: '<S35>/Multiply3'
       *  RelationalOperator: '<S35>/Relational Operator'
       *  RelationalOperator: '<S35>/Relational Operator2'
       *  SignalConversion: '<S35>/TmpSignal ConversionAtSquareInport1'
       *  Sqrt: '<S35>/Sqrt'
       *  Sum: '<S35>/Subtract'
       */
      if ((rtb_Divide_i_idx_1 <= rtb_FF_limit_idx_1) && (rtb_Divide_i_idx_1 >=
           -rtb_FF_limit_idx_1)) {
        rtb_Divide_i_idx_1 *= CONTROL_PARAM.MC_PITCH_P;
      } else {
        rtb_Divide_i_idx_1 = sqrtf((rtb_FF_limit_idx_2 * rtb_Divide_i_idx_1 -
          0.5F * rtb_FF_limit_idx_1) * Controller_ConstB.Gain_n) *
          rtb_FF_limit_idx_2;
      }

      /* Switch: '<S36>/Switch' incorporates:
       *  Gain: '<S35>/Gain3'
       *  RelationalOperator: '<S36>/UpperRelop'
       */
      if (rtb_Divide_i_idx_1 >= -rtb_Gain_it) {
        rtb_MatrixConcatenate1_tmp = rtb_Divide_i_idx_1;
      }

      /* Switch: '<S36>/Switch2' incorporates:
       *  RelationalOperator: '<S36>/LowerRelop1'
       */
      if (rtb_Divide_i_idx_1 <= rtb_Gain_it) {
        rtb_Gain_it = rtb_MatrixConcatenate1_tmp;
      }

      /* Saturate: '<S18>/Saturation1' */
      if (rtb_Gain_it > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_Gain_it = CONTROL_PARAM.MC_P_Q_CMD_LIM;
      } else {
        if (rtb_Gain_it < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
          rtb_Gain_it = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
        }
      }

      /* Trigonometry: '<S28>/Cos' incorporates:
       *  Inport: '<Root>/INS_Out'
       */
      rtb_FF_limit_idx_1 = arm_cos_f32(Controller_U.INS_Out.phi);

      /* Trigonometry: '<S28>/Cos1' incorporates:
       *  Inport: '<Root>/INS_Out'
       */
      rtb_FF_limit_idx_2 = arm_cos_f32(Controller_U.INS_Out.theta);

      /* Trigonometry: '<S28>/Sin' incorporates:
       *  Inport: '<Root>/INS_Out'
       */
      rtb_Gain_ms = arm_sin_f32(Controller_U.INS_Out.phi);
      rtb_DiscreteTimeIntegrator1_k1[0] = rtb_Saturation_ov - arm_sin_f32
        (Controller_U.INS_Out.theta) * rtb_Add_c;
      rtb_DiscreteTimeIntegrator1_k1[1] = rtb_FF_limit_idx_1 * rtb_Gain_it +
        rtb_Gain_ms * rtb_FF_limit_idx_2 * rtb_Add_c;
      rtb_DiscreteTimeIntegrator1_k1[2] = rtb_FF_limit_idx_1 *
        rtb_FF_limit_idx_2 * rtb_Add_c - rtb_Gain_ms * rtb_Gain_it;
    }

    /* End of Switch: '<S19>/Switch' */

    /* Sum: '<S20>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Add_c = rtb_DiscreteTimeIntegrator1_k1[0] - Controller_U.INS_Out.p;
    rtb_FF_limit_idx_1 = rtb_DiscreteTimeIntegrator1_k1[1] -
      Controller_U.INS_Out.q;
    rtb_FF_limit_idx_2 = rtb_DiscreteTimeIntegrator1_k1[2] -
      Controller_U.INS_Out.r;

    /* DiscreteIntegrator: '<S23>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_e != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0] = rtb_Add_c;
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1] = rtb_FF_limit_idx_1;
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2] = rtb_FF_limit_idx_2;
    }

    /* DiscreteIntegrator: '<S25>/Discrete-Time Integrator' */
    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator_PrevR_ps != 0)) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_g[0] =
        Controller_ConstB.Constant_a[0];
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_g[0] >=
          CONTROL_PARAM.MC_RATE_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_g[0] =
          CONTROL_PARAM.MC_RATE_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_g[0] <=
            CONTROL_PARAM.MC_RATE_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_g[0] =
            CONTROL_PARAM.MC_RATE_I_MIN;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_DSTATE_g[1] =
        Controller_ConstB.Constant_a[1];
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_g[1] >=
          CONTROL_PARAM.MC_RATE_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_g[1] =
          CONTROL_PARAM.MC_RATE_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_g[1] <=
            CONTROL_PARAM.MC_RATE_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_g[1] =
            CONTROL_PARAM.MC_RATE_I_MIN;
        }
      }

      Controller_DW.DiscreteTimeIntegrator_DSTATE_g[2] =
        Controller_ConstB.Constant_a[2];
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_g[2] >=
          CONTROL_PARAM.MC_RATE_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_g[2] =
          CONTROL_PARAM.MC_RATE_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_g[2] <=
            CONTROL_PARAM.MC_RATE_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_g[2] =
            CONTROL_PARAM.MC_RATE_I_MIN;
        }
      }
    }

    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_g[0] >=
        CONTROL_PARAM.MC_RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_g[0] =
        CONTROL_PARAM.MC_RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_g[0] <=
          CONTROL_PARAM.MC_RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_g[0] =
          CONTROL_PARAM.MC_RATE_I_MIN;
      }
    }

    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_g[1] >=
        CONTROL_PARAM.MC_RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_g[1] =
        CONTROL_PARAM.MC_RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_g[1] <=
          CONTROL_PARAM.MC_RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_g[1] =
          CONTROL_PARAM.MC_RATE_I_MIN;
      }
    }

    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_g[2] >=
        CONTROL_PARAM.MC_RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_g[2] =
        CONTROL_PARAM.MC_RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_g[2] <=
          CONTROL_PARAM.MC_RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_g[2] =
          CONTROL_PARAM.MC_RATE_I_MIN;
      }
    }

    /* DiscreteIntegrator: '<S27>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S23>/Discrete-Time Integrator5'
     */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_p != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_l[0] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0];
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_l[1] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1];
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_l[2] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2];
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_c != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_l[0] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0];
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_l[1] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1];
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_l[2] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2];
    }

    /* Gain: '<S27>/Gain' incorporates:
     *  DiscreteIntegrator: '<S23>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S27>/Discrete-Time Integrator1'
     *  Sum: '<S27>/Sum5'
     */
    rtb_DiscreteTimeIntegrator1_k1[0] =
      (Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0] -
       Controller_DW.DiscreteTimeIntegrator1_DSTAT_l[0]) * 188.49556F;
    rtb_DiscreteTimeIntegrator1_k1[1] =
      (Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1] -
       Controller_DW.DiscreteTimeIntegrator1_DSTAT_l[1]) * 188.49556F;
    rtb_DiscreteTimeIntegrator1_k1[2] =
      (Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2] -
       Controller_DW.DiscreteTimeIntegrator1_DSTAT_l[2]) * 188.49556F;

    /* Switch: '<S27>/Switch' incorporates:
     *  Gain: '<S27>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_Divide_i_idx_1 = 0.0F;
      rtb_Divide_i_idx_2 = 0.0F;
      rtb_Divide_i_idx_3 = 0.0F;
    } else {
      rtb_Divide_i_idx_1 = rtb_DiscreteTimeIntegrator1_k1[0];
      rtb_Divide_i_idx_2 = rtb_DiscreteTimeIntegrator1_k1[1];
      rtb_Divide_i_idx_3 = rtb_DiscreteTimeIntegrator1_k1[2];
    }

    /* End of Switch: '<S27>/Switch' */

    /* Product: '<S24>/Multiply' incorporates:
     *  Constant: '<S24>/gain1'
     */
    rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_ROLL_RATE_D *
      rtb_Divide_i_idx_1;

    /* Saturate: '<S24>/Saturation' */
    if (rtb_DiscreteTimeIntegrator1_g > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_DiscreteTimeIntegrator1_g < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    rtb_Divide_i_idx_1 = rtb_DiscreteTimeIntegrator1_g;

    /* Product: '<S24>/Multiply' incorporates:
     *  Constant: '<S24>/gain2'
     */
    rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_PITCH_RATE_D *
      rtb_Divide_i_idx_2;

    /* Saturate: '<S24>/Saturation' */
    if (rtb_DiscreteTimeIntegrator1_g > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_DiscreteTimeIntegrator1_g < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    rtb_Divide_i_idx_2 = rtb_DiscreteTimeIntegrator1_g;

    /* Product: '<S24>/Multiply' incorporates:
     *  Constant: '<S24>/gain3'
     */
    rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_YAW_RATE_D *
      rtb_Divide_i_idx_3;

    /* Saturate: '<S24>/Saturation' */
    if (rtb_DiscreteTimeIntegrator1_g > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_DiscreteTimeIntegrator1_g < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    /* Sum: '<S21>/Add' incorporates:
     *  Constant: '<S26>/gain1'
     *  Constant: '<S26>/gain2'
     *  Constant: '<S26>/gain3'
     *  DiscreteIntegrator: '<S23>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S25>/Discrete-Time Integrator'
     *  Product: '<S26>/Multiply'
     */
    rtb_Add_h[0] = (CONTROL_PARAM.MC_ROLL_RATE_P *
                    Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0] +
                    Controller_DW.DiscreteTimeIntegrator_DSTATE_g[0]) +
      rtb_Divide_i_idx_1;
    rtb_Add_h[1] = (CONTROL_PARAM.MC_PITCH_RATE_P *
                    Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1] +
                    Controller_DW.DiscreteTimeIntegrator_DSTATE_g[1]) +
      rtb_Divide_i_idx_2;
    rtb_Add_h[2] = (CONTROL_PARAM.MC_YAW_RATE_P *
                    Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2] +
                    Controller_DW.DiscreteTimeIntegrator_DSTATE_g[2]) +
      rtb_DiscreteTimeIntegrator1_g;

    /* Gain: '<S52>/Gain' incorporates:
     *  DiscreteIntegrator: '<S54>/Integrator1'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S52>/Sum1'
     */
    rtb_VdotPg = -(Controller_DW.Integrator1_DSTATE_o - Controller_U.INS_Out.vd);
    Controller_B.Constant_i = CONTROL_PARAM.MC_VEL_Z_I_MIN;

    /* DiscreteIntegrator: '<S57>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S57>/Constant'
     */
    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator_PrevRe_c != 0)) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_p = Controller_B.Constant_i;
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_p >=
          CONTROL_PARAM.MC_VEL_Z_I_MAX) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_p =
          CONTROL_PARAM.MC_VEL_Z_I_MAX;
      } else {
        if (Controller_DW.DiscreteTimeIntegrator_DSTATE_p <=
            CONTROL_PARAM.MC_VEL_Z_I_MIN) {
          Controller_DW.DiscreteTimeIntegrator_DSTATE_p =
            CONTROL_PARAM.MC_VEL_Z_I_MIN;
        }
      }
    }

    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_p >=
        CONTROL_PARAM.MC_VEL_Z_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_p =
        CONTROL_PARAM.MC_VEL_Z_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_p <=
          CONTROL_PARAM.MC_VEL_Z_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_p =
          CONTROL_PARAM.MC_VEL_Z_I_MIN;
      }
    }

    /* DiscreteIntegrator: '<S59>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_b != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_d = rtb_VdotPg;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_a != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_d = rtb_VdotPg;
    }

    /* Gain: '<S59>/Gain' incorporates:
     *  DiscreteIntegrator: '<S59>/Discrete-Time Integrator1'
     *  Sum: '<S59>/Sum5'
     */
    rtb_Cos1_d = (rtb_VdotPg - Controller_DW.DiscreteTimeIntegrator1_DSTAT_d) *
      62.831852F;

    /* Switch: '<S59>/Switch' incorporates:
     *  Gain: '<S59>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_MatrixConcatenate1_tmp = 0.0F;
    } else {
      rtb_MatrixConcatenate1_tmp = rtb_Cos1_d;
    }

    /* End of Switch: '<S59>/Switch' */

    /* Product: '<S56>/Multiply' incorporates:
     *  Constant: '<S56>/kd'
     */
    rtb_Abs = CONTROL_PARAM.MC_VEL_Z_D * rtb_MatrixConcatenate1_tmp;

    /* Saturate: '<S56>/Saturation' */
    if (rtb_Abs > CONTROL_PARAM.MC_VEL_Z_D_MAX) {
      rtb_Abs = CONTROL_PARAM.MC_VEL_Z_D_MAX;
    } else {
      if (rtb_Abs < CONTROL_PARAM.MC_VEL_Z_D_MIN) {
        rtb_Abs = CONTROL_PARAM.MC_VEL_Z_D_MIN;
      }
    }

    /* End of Saturate: '<S56>/Saturation' */

    /* Sum: '<S53>/Add' incorporates:
     *  Constant: '<S58>/kp'
     *  DiscreteIntegrator: '<S57>/Discrete-Time Integrator'
     *  Product: '<S58>/Multiply'
     */
    rtb_Saturation_ov = (CONTROL_PARAM.MC_VEL_Z_P * rtb_VdotPg +
                         Controller_DW.DiscreteTimeIntegrator_DSTATE_p) +
      rtb_Abs;

    /* Product: '<S51>/Multiply' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S51>/Cos'
     *  Trigonometry: '<S51>/Cos1'
     */
    rtb_Abs = arm_cos_f32(Controller_U.INS_Out.phi) * arm_cos_f32
      (Controller_U.INS_Out.theta);

    /* Saturate: '<S51>/Saturation1' incorporates:
     *  Product: '<S51>/Multiply'
     */
    if (rtb_Abs > 1.0F) {
      rtb_Gain_it = 1.0F;
    } else if (rtb_Abs < 0.5F) {
      rtb_Gain_it = 0.5F;
    } else {
      rtb_Gain_it = rtb_Abs;
    }

    /* End of Saturate: '<S51>/Saturation1' */

    /* Gain: '<S51>/Gain' incorporates:
     *  Product: '<S51>/Multiply'
     */
    rtb_Abs *= 2.0F;

    /* Saturate: '<S51>/Saturation' */
    if (rtb_Abs > 1.0F) {
      rtb_Abs = 1.0F;
    } else {
      if (rtb_Abs < 0.0F) {
        rtb_Abs = 0.0F;
      }
    }

    /* End of Saturate: '<S51>/Saturation' */

    /* Product: '<S51>/Multiply1' incorporates:
     *  Constant: '<S51>/Constant'
     *  Product: '<S51>/Divide'
     */
    rtb_Abs *= 1.0F / rtb_Gain_it * rtb_Saturation_ov;

    /* Saturate: '<S50>/Saturation' */
    if (rtb_Abs > 0.35F) {
      rtb_Abs = 0.35F;
    } else {
      if (rtb_Abs < -0.35F) {
        rtb_Abs = -0.35F;
      }
    }

    /* End of Saturate: '<S50>/Saturation' */

    /* Sum: '<S9>/Sum' incorporates:
     *  Constant: '<S9>/mc_hover_throttle'
     */
    rtb_Abs += CONTROL_PARAM.MC_HOVER_THRO;

    /* Saturate: '<S9>/Saturation' */
    if (rtb_Abs > 1.0F) {
      rtb_Saturation_hi = 1.0F;
    } else if (rtb_Abs < -1.0F) {
      rtb_Saturation_hi = -1.0F;
    } else {
      rtb_Saturation_hi = rtb_Abs;
    }

    /* End of Saturate: '<S9>/Saturation' */

    /* Outputs for Atomic SubSystem: '<S10>/VTOL_Control_Allocation' */
#if AIRFRAME == 1

    /* Output and update for atomic system: '<S61>/VTOL1' */
    {
      uint16_T rtb_DataTypeConversion_b;
      real32_T rtb_MatrixConcatenate_b[12];
      int32_T i_n;
      real32_T tmp_n;
      real32_T tmp_o;
      real32_T tmp_k;
      real32_T u0_n;
      uint16_T u0_o;

      /* MultiPortSwitch: '<S66>/Multiport Switch' incorporates:
       *  Constant: '<S66>/Disarm'
       *  Constant: '<S66>/Standby'
       *  Constant: '<S67>/Constant1'
       *  Constant: '<S67>/Constant12'
       *  Constant: '<S67>/Constant2'
       *  Constant: '<S67>/Constant7'
       *  Inport: '<Root>/FMS_Out'
       *  Reshape: '<S62>/Reshape'
       *  Saturate: '<S64>/Saturation1'
       */
      switch (Controller_U.FMS_Out.status) {
       case 1:
        for (i_n = 0; i_n < 9; i_n++) {
          rtb_VariantMergeForOutportactua[i_n] = Controller_ConstP.pooled37[i_n];
        }
        break;

       case 2:
        for (i_n = 0; i_n < 9; i_n++) {
          rtb_VariantMergeForOutportactua[i_n] = Controller_ConstP.pooled38[i_n];
        }
        break;

       case 3:
        /* Saturate: '<S65>/Saturation2' */
        if (rtb_Saturation_hi > 1.0F) {
          u0_n = 1.0F;
        } else if (rtb_Saturation_hi < -1.0F) {
          u0_n = -1.0F;
        } else {
          u0_n = rtb_Saturation_hi;
        }

        /* End of Saturate: '<S65>/Saturation2' */

        /* Saturate: '<S69>/Saturation' */
        if (u0_n > 1.0F) {
          u0_n = 1.0F;
        } else {
          if (u0_n < 0.0F) {
            u0_n = 0.0F;
          }
        }

        /* End of Saturate: '<S69>/Saturation' */

        /* DataTypeConversion: '<S69>/Data Type Conversion' incorporates:
         *  Constant: '<S69>/Constant1'
         *  Gain: '<S69>/Gain1'
         *  Sum: '<S69>/Sum1'
         */
        rtb_DataTypeConversion_b = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          u0_n), 4.2949673E+9F) + 1000U);
        rtb_MatrixConcatenate_b[11] = CONTROL_PARAM.FW_YAW_EFFC *
          CONTROL_PARAM.FW_RUDDER_DIR;

        /* SignalConversion: '<S67>/ConcatBufferAtVector Concatenate2In3' incorporates:
         *  Constant: '<S67>/Constant11'
         *  Constant: '<S67>/Constant12'
         */
        rtb_MatrixConcatenate_b[10] = 0.0F;

        /* SignalConversion: '<S67>/ConcatBufferAtVector Concatenate2In2' incorporates:
         *  Constant: '<S67>/Constant10'
         */
        rtb_MatrixConcatenate_b[9] = 0.0F;

        /* SignalConversion: '<S67>/ConcatBufferAtVector Concatenate2In1' incorporates:
         *  Constant: '<S67>/Constant9'
         */
        rtb_MatrixConcatenate_b[8] = 0.0F;

        /* SignalConversion: '<S67>/ConcatBufferAtVector Concatenate1In4' incorporates:
         *  Constant: '<S67>/Constant8'
         */
        rtb_MatrixConcatenate_b[7] = 0.0F;
        rtb_MatrixConcatenate_b[6] = CONTROL_PARAM.FW_PITCH_EFFC *
          CONTROL_PARAM.FW_ELEVATOR_DIR;

        /* SignalConversion: '<S67>/ConcatBufferAtVector Concatenate1In2' incorporates:
         *  Constant: '<S67>/Constant6'
         *  Constant: '<S67>/Constant7'
         */
        rtb_MatrixConcatenate_b[5] = 0.0F;

        /* SignalConversion: '<S67>/ConcatBufferAtVector Concatenate1In1' incorporates:
         *  Constant: '<S67>/Constant5'
         */
        rtb_MatrixConcatenate_b[4] = 0.0F;

        /* SignalConversion: '<S67>/ConcatBufferAtVector ConcatenateIn4' incorporates:
         *  Constant: '<S67>/Constant4'
         */
        rtb_MatrixConcatenate_b[3] = 0.0F;

        /* SignalConversion: '<S67>/ConcatBufferAtVector ConcatenateIn3' incorporates:
         *  Constant: '<S67>/Constant3'
         */
        rtb_MatrixConcatenate_b[2] = 0.0F;
        rtb_MatrixConcatenate_b[1] = CONTROL_PARAM.FW_ROLL_EFFC *
          CONTROL_PARAM.FW_AILERON2_DIR;
        rtb_MatrixConcatenate_b[0] = CONTROL_PARAM.FW_ROLL_EFFC *
          CONTROL_PARAM.FW_AILERON1_DIR;

        /* Saturate: '<S65>/Saturation1' incorporates:
         *  Constant: '<S67>/Constant1'
         *  Constant: '<S67>/Constant2'
         */
        if (rtb_Add_h[0] > 1.0F) {
          tmp_n = 1.0F;
        } else if (rtb_Add_h[0] < -1.0F) {
          tmp_n = -1.0F;
        } else {
          tmp_n = rtb_Add_h[0];
        }

        if (rtb_Add_h[1] > 1.0F) {
          tmp_o = 1.0F;
        } else if (rtb_Add_h[1] < -1.0F) {
          tmp_o = -1.0F;
        } else {
          tmp_o = rtb_Add_h[1];
        }

        if (rtb_Add_h[2] > 1.0F) {
          tmp_k = 1.0F;
        } else if (rtb_Add_h[2] < -1.0F) {
          tmp_k = -1.0F;
        } else {
          tmp_k = rtb_Add_h[2];
        }

        /* End of Saturate: '<S65>/Saturation1' */
        rtb_VariantMergeForOutportactua[4] =
          Controller_ConstB.VTOL1_n.DataTypeConversion;
        for (i_n = 0; i_n < 4; i_n++) {
          /* Saturate: '<S65>/Saturation' incorporates:
           *  Constant: '<S65>/Effective_Matrix'
           *  Gain: '<S65>/Gain'
           *  Product: '<S65>/Multiply'
           *  Sum: '<S65>/Add'
           */
          u0_n = fmodf(floorf(1000.0F * (Controller_ConstP.pooled16[i_n + 8] *
            tmp_k + (Controller_ConstP.pooled16[i_n + 4] * tmp_o +
                     Controller_ConstP.pooled16[i_n] * tmp_n)) + (real32_T)
                              rtb_DataTypeConversion_b), 65536.0F);
          u0_o = (uint16_T)(u0_n < 0.0F ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
                            -u0_n : (int32_T)(uint16_T)u0_n);
          if (u0_o > 1900) {
            rtb_VariantMergeForOutportactua[i_n] = 1900U;
          } else if (u0_o < 1000) {
            rtb_VariantMergeForOutportactua[i_n] = 1000U;
          } else {
            rtb_VariantMergeForOutportactua[i_n] = u0_o;
          }

          /* End of Saturate: '<S65>/Saturation' */

          /* Saturate: '<S64>/Saturation1' incorporates:
           *  Bias: '<S64>/Bias'
           *  Gain: '<S64>/Gain1'
           *  Product: '<S64>/Multiply1'
           */
          u0_n = 500.0F * (rtb_MatrixConcatenate_b[i_n + 8] *
                           Controller_ConstB.VTOL1_n.Saturation5[2] +
                           (rtb_MatrixConcatenate_b[i_n + 4] *
                            Controller_ConstB.VTOL1_n.Saturation5[1] +
                            rtb_MatrixConcatenate_b[i_n] *
                            Controller_ConstB.VTOL1_n.Saturation5[0])) + 1500.0F;
          if (u0_n > 2000.0F) {
            u0_n = 2000.0F;
          } else {
            if (u0_n < 1000.0F) {
              u0_n = 1000.0F;
            }
          }

          rtb_VariantMergeForOutportactua[i_n + 5] = (uint16_T)fmodf(floorf(u0_n),
            65536.0F);
        }
        break;

       default:
        for (i_n = 0; i_n < 9; i_n++) {
          rtb_VariantMergeForOutportactua[i_n] = Controller_ConstP.pooled37[i_n];
        }
        break;
      }

      /* End of MultiPortSwitch: '<S66>/Multiport Switch' */
    }

#elif AIRFRAME == 2

    /* Output and update for atomic system: '<S61>/VTOL2' */
    {
      real32_T rtb_Saturation1_j[4];
      uint16_T rtb_tail_right_h;
      real32_T rtb_MatrixConcatenate_a[12];
      real32_T rtb_Saturation_fr[9];
      int32_T i_m;
      real32_T tmp_m;
      real32_T tmp_p;
      real32_T tmp_j;
      real32_T u0_m;
      uint16_T u0_p;

      /* Saturate: '<S76>/Saturation' incorporates:
       *  Bias: '<S76>/Bias'
       *  Bias: '<S76>/Bias1'
       *  Bias: '<S76>/Bias2'
       *  Bias: '<S76>/Bias3'
       *  Constant: '<S76>/Constant'
       */
      for (i_m = 0; i_m < 5; i_m++) {
        rtb_Saturation_fr[i_m] = 1000.0F;
      }

      if (1500.0F + CONTROL_PARAM.SERVO1_BIAS > 2000.0F) {
        rtb_Saturation_fr[5] = 2000.0F;
      } else if (1500.0F + CONTROL_PARAM.SERVO1_BIAS < 1000.0F) {
        rtb_Saturation_fr[5] = 1000.0F;
      } else {
        rtb_Saturation_fr[5] = 1500.0F + CONTROL_PARAM.SERVO1_BIAS;
      }

      if (1500.0F + CONTROL_PARAM.SERVO2_BIAS > 2000.0F) {
        rtb_Saturation_fr[6] = 2000.0F;
      } else if (1500.0F + CONTROL_PARAM.SERVO2_BIAS < 1000.0F) {
        rtb_Saturation_fr[6] = 1000.0F;
      } else {
        rtb_Saturation_fr[6] = 1500.0F + CONTROL_PARAM.SERVO2_BIAS;
      }

      if (1500.0F + CONTROL_PARAM.SERVO3_BIAS > 2000.0F) {
        rtb_Saturation_fr[7] = 2000.0F;
      } else if (1500.0F + CONTROL_PARAM.SERVO3_BIAS < 1000.0F) {
        rtb_Saturation_fr[7] = 1000.0F;
      } else {
        rtb_Saturation_fr[7] = 1500.0F + CONTROL_PARAM.SERVO3_BIAS;
      }

      if (1500.0F + CONTROL_PARAM.SERVO4_BIAS > 2000.0F) {
        rtb_Saturation_fr[8] = 2000.0F;
      } else if (1500.0F + CONTROL_PARAM.SERVO4_BIAS < 1000.0F) {
        rtb_Saturation_fr[8] = 1000.0F;
      } else {
        rtb_Saturation_fr[8] = 1500.0F + CONTROL_PARAM.SERVO4_BIAS;
      }

      /* End of Saturate: '<S76>/Saturation' */

      /* MultiPortSwitch: '<S72>/Multiport Switch' incorporates:
       *  Constant: '<S73>/Constant1'
       *  Constant: '<S73>/Constant11'
       *  Constant: '<S73>/Constant12'
       *  Constant: '<S73>/Constant2'
       *  Constant: '<S73>/Constant7'
       *  Constant: '<S73>/Constant8'
       *  DataTypeConversion: '<S70>/Data Type Conversion'
       *  DataTypeConversion: '<S70>/Data Type Conversion1'
       *  DataTypeConversion: '<S70>/Data Type Conversion2'
       *  DataTypeConversion: '<S70>/Data Type Conversion3'
       *  DataTypeConversion: '<S76>/Data Type Conversion'
       *  DataTypeConversion: '<S77>/Data Type Conversion'
       *  Inport: '<Root>/FMS_Out'
       *  Reshape: '<S63>/Reshape'
       *  Saturate: '<S77>/Saturation'
       */
      switch (Controller_U.FMS_Out.status) {
       case 1:
        for (i_m = 0; i_m < 9; i_m++) {
          rtb_VariantMergeForOutportactua[i_m] = (uint16_T)fmodf(floorf
            (rtb_Saturation_fr[i_m]), 65536.0F);
        }
        break;

       case 2:
        for (i_m = 0; i_m < 5; i_m++) {
          rtb_VariantMergeForOutportactua[i_m] = 1150U;
        }

        /* Saturate: '<S77>/Saturation' incorporates:
         *  Bias: '<S77>/Bias'
         *  Constant: '<S77>/Constant'
         *  DataTypeConversion: '<S77>/Data Type Conversion'
         */
        if (1500.0F + CONTROL_PARAM.SERVO1_BIAS > 2000.0F) {
          u0_m = 2000.0F;
        } else if (1500.0F + CONTROL_PARAM.SERVO1_BIAS < 1000.0F) {
          u0_m = 1000.0F;
        } else {
          u0_m = 1500.0F + CONTROL_PARAM.SERVO1_BIAS;
        }

        rtb_VariantMergeForOutportactua[5] = (uint16_T)fmodf(floorf(u0_m),
          65536.0F);

        /* Saturate: '<S77>/Saturation' incorporates:
         *  Bias: '<S77>/Bias1'
         *  Constant: '<S77>/Constant'
         *  DataTypeConversion: '<S77>/Data Type Conversion'
         */
        if (1500.0F + CONTROL_PARAM.SERVO2_BIAS > 2000.0F) {
          u0_m = 2000.0F;
        } else if (1500.0F + CONTROL_PARAM.SERVO2_BIAS < 1000.0F) {
          u0_m = 1000.0F;
        } else {
          u0_m = 1500.0F + CONTROL_PARAM.SERVO2_BIAS;
        }

        rtb_VariantMergeForOutportactua[6] = (uint16_T)fmodf(floorf(u0_m),
          65536.0F);

        /* Saturate: '<S77>/Saturation' incorporates:
         *  Bias: '<S77>/Bias2'
         *  Constant: '<S77>/Constant'
         *  DataTypeConversion: '<S77>/Data Type Conversion'
         */
        if (1500.0F + CONTROL_PARAM.SERVO3_BIAS > 2000.0F) {
          u0_m = 2000.0F;
        } else if (1500.0F + CONTROL_PARAM.SERVO3_BIAS < 1000.0F) {
          u0_m = 1000.0F;
        } else {
          u0_m = 1500.0F + CONTROL_PARAM.SERVO3_BIAS;
        }

        rtb_VariantMergeForOutportactua[7] = (uint16_T)fmodf(floorf(u0_m),
          65536.0F);

        /* Saturate: '<S77>/Saturation' incorporates:
         *  Bias: '<S77>/Bias3'
         *  Constant: '<S77>/Constant'
         *  DataTypeConversion: '<S77>/Data Type Conversion'
         */
        if (1500.0F + CONTROL_PARAM.SERVO4_BIAS > 2000.0F) {
          u0_m = 2000.0F;
        } else if (1500.0F + CONTROL_PARAM.SERVO4_BIAS < 1000.0F) {
          u0_m = 1000.0F;
        } else {
          u0_m = 1500.0F + CONTROL_PARAM.SERVO4_BIAS;
        }

        rtb_VariantMergeForOutportactua[8] = (uint16_T)fmodf(floorf(u0_m),
          65536.0F);
        break;

       case 3:
        /* Saturate: '<S71>/Saturation2' */
        if (rtb_Saturation_hi > 1.0F) {
          u0_m = 1.0F;
        } else if (rtb_Saturation_hi < -1.0F) {
          u0_m = -1.0F;
        } else {
          u0_m = rtb_Saturation_hi;
        }

        /* End of Saturate: '<S71>/Saturation2' */

        /* Saturate: '<S75>/Saturation' */
        if (u0_m > 1.0F) {
          u0_m = 1.0F;
        } else {
          if (u0_m < 0.0F) {
            u0_m = 0.0F;
          }
        }

        /* End of Saturate: '<S75>/Saturation' */

        /* DataTypeConversion: '<S75>/Data Type Conversion' incorporates:
         *  Constant: '<S75>/Constant1'
         *  Gain: '<S75>/Gain1'
         *  Sum: '<S75>/Sum1'
         */
        rtb_tail_right_h = (uint16_T)((uint32_T)fmodf(floorf(1000.0F * u0_m),
          4.2949673E+9F) + 1000U);
        rtb_MatrixConcatenate_a[11] = CONTROL_PARAM.FW_YAW_EFFC *
          CONTROL_PARAM.FW_TAIL2_DIR;
        rtb_MatrixConcatenate_a[10] = CONTROL_PARAM.FW_YAW_EFFC *
          CONTROL_PARAM.FW_TAIL1_DIR;

        /* SignalConversion: '<S73>/ConcatBufferAtVector Concatenate2In2' incorporates:
         *  Constant: '<S73>/Constant10'
         *  Constant: '<S73>/Constant11'
         *  Constant: '<S73>/Constant12'
         */
        rtb_MatrixConcatenate_a[9] = 0.0F;

        /* SignalConversion: '<S73>/ConcatBufferAtVector Concatenate2In1' incorporates:
         *  Constant: '<S73>/Constant9'
         */
        rtb_MatrixConcatenate_a[8] = 0.0F;
        rtb_MatrixConcatenate_a[7] = -CONTROL_PARAM.FW_PITCH_EFFC *
          CONTROL_PARAM.FW_TAIL2_DIR;
        rtb_MatrixConcatenate_a[6] = CONTROL_PARAM.FW_PITCH_EFFC *
          CONTROL_PARAM.FW_TAIL1_DIR;

        /* SignalConversion: '<S73>/ConcatBufferAtVector Concatenate1In2' incorporates:
         *  Constant: '<S73>/Constant6'
         *  Constant: '<S73>/Constant7'
         *  Constant: '<S73>/Constant8'
         */
        rtb_MatrixConcatenate_a[5] = 0.0F;

        /* SignalConversion: '<S73>/ConcatBufferAtVector Concatenate1In1' incorporates:
         *  Constant: '<S73>/Constant5'
         */
        rtb_MatrixConcatenate_a[4] = 0.0F;

        /* SignalConversion: '<S73>/ConcatBufferAtVector ConcatenateIn4' incorporates:
         *  Constant: '<S73>/Constant4'
         */
        rtb_MatrixConcatenate_a[3] = 0.0F;

        /* SignalConversion: '<S73>/ConcatBufferAtVector ConcatenateIn3' incorporates:
         *  Constant: '<S73>/Constant3'
         */
        rtb_MatrixConcatenate_a[2] = 0.0F;
        rtb_MatrixConcatenate_a[1] = CONTROL_PARAM.FW_ROLL_EFFC *
          CONTROL_PARAM.FW_AILERON2_DIR;
        rtb_MatrixConcatenate_a[0] = CONTROL_PARAM.FW_ROLL_EFFC *
          CONTROL_PARAM.FW_AILERON1_DIR;
        for (i_m = 0; i_m < 4; i_m++) {
          /* Saturate: '<S70>/Saturation1' incorporates:
           *  Bias: '<S70>/Bias'
           *  Gain: '<S70>/Gain1'
           *  Product: '<S70>/Multiply1'
           */
          u0_m = 500.0F * (rtb_MatrixConcatenate_a[i_m + 8] *
                           Controller_ConstB.VTOL2_p.Saturation5[2] +
                           (rtb_MatrixConcatenate_a[i_m + 4] *
                            Controller_ConstB.VTOL2_p.Saturation5[1] +
                            rtb_MatrixConcatenate_a[i_m] *
                            Controller_ConstB.VTOL2_p.Saturation5[0])) + 1500.0F;
          if (u0_m > 2000.0F) {
            rtb_Saturation1_j[i_m] = 2000.0F;
          } else if (u0_m < 1000.0F) {
            rtb_Saturation1_j[i_m] = 1000.0F;
          } else {
            rtb_Saturation1_j[i_m] = u0_m;
          }

          /* End of Saturate: '<S70>/Saturation1' */
        }

        /* Saturate: '<S71>/Saturation1' incorporates:
         *  Constant: '<S73>/Constant1'
         *  Constant: '<S73>/Constant2'
         */
        if (rtb_Add_h[0] > 1.0F) {
          tmp_m = 1.0F;
        } else if (rtb_Add_h[0] < -1.0F) {
          tmp_m = -1.0F;
        } else {
          tmp_m = rtb_Add_h[0];
        }

        if (rtb_Add_h[1] > 1.0F) {
          tmp_p = 1.0F;
        } else if (rtb_Add_h[1] < -1.0F) {
          tmp_p = -1.0F;
        } else {
          tmp_p = rtb_Add_h[1];
        }

        if (rtb_Add_h[2] > 1.0F) {
          tmp_j = 1.0F;
        } else if (rtb_Add_h[2] < -1.0F) {
          tmp_j = -1.0F;
        } else {
          tmp_j = rtb_Add_h[2];
        }

        /* End of Saturate: '<S71>/Saturation1' */
        for (i_m = 0; i_m < 4; i_m++) {
          /* Saturate: '<S71>/Saturation' incorporates:
           *  Constant: '<S71>/Effective_Matrix'
           *  Gain: '<S71>/Gain'
           *  Product: '<S71>/Multiply'
           *  Reshape: '<S63>/Reshape'
           *  Sum: '<S71>/Add'
           */
          u0_m = fmodf(floorf(1000.0F * (Controller_ConstP.pooled16[i_m + 8] *
            tmp_j + (Controller_ConstP.pooled16[i_m + 4] * tmp_p +
                     Controller_ConstP.pooled16[i_m] * tmp_m)) + (real32_T)
                              rtb_tail_right_h), 65536.0F);
          u0_p = (uint16_T)(u0_m < 0.0F ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
                            -u0_m : (int32_T)(uint16_T)u0_m);
          if (u0_p > 1900) {
            rtb_VariantMergeForOutportactua[i_m] = 1900U;
          } else if (u0_p < 1000) {
            rtb_VariantMergeForOutportactua[i_m] = 1000U;
          } else {
            rtb_VariantMergeForOutportactua[i_m] = u0_p;
          }

          /* End of Saturate: '<S71>/Saturation' */
        }

        rtb_VariantMergeForOutportactua[4] =
          Controller_ConstB.VTOL2_p.DataTypeConversion;

        /* DataTypeConversion: '<S70>/Data Type Conversion' incorporates:
         *  Bias: '<S70>/Bias1'
         *  Reshape: '<S63>/Reshape'
         */
        u0_m = fmodf(floorf(rtb_Saturation1_j[0] + CONTROL_PARAM.SERVO1_BIAS),
                     65536.0F);
        rtb_VariantMergeForOutportactua[5] = (uint16_T)(u0_m < 0.0F ? (int32_T)
          (uint16_T)-(int16_T)(uint16_T)-u0_m : (int32_T)(uint16_T)u0_m);

        /* DataTypeConversion: '<S70>/Data Type Conversion1' incorporates:
         *  Bias: '<S70>/Bias2'
         *  DataTypeConversion: '<S70>/Data Type Conversion'
         *  Reshape: '<S63>/Reshape'
         */
        u0_m = fmodf(floorf(rtb_Saturation1_j[1] + CONTROL_PARAM.SERVO2_BIAS),
                     65536.0F);
        rtb_VariantMergeForOutportactua[6] = (uint16_T)(u0_m < 0.0F ? (int32_T)
          (uint16_T)-(int16_T)(uint16_T)-u0_m : (int32_T)(uint16_T)u0_m);

        /* DataTypeConversion: '<S70>/Data Type Conversion2' incorporates:
         *  Bias: '<S70>/Bias3'
         *  DataTypeConversion: '<S70>/Data Type Conversion1'
         *  Reshape: '<S63>/Reshape'
         */
        u0_m = fmodf(floorf(rtb_Saturation1_j[2] + CONTROL_PARAM.SERVO3_BIAS),
                     65536.0F);
        rtb_VariantMergeForOutportactua[7] = (uint16_T)(u0_m < 0.0F ? (int32_T)
          (uint16_T)-(int16_T)(uint16_T)-u0_m : (int32_T)(uint16_T)u0_m);

        /* DataTypeConversion: '<S70>/Data Type Conversion3' incorporates:
         *  Bias: '<S70>/Bias4'
         *  DataTypeConversion: '<S70>/Data Type Conversion2'
         *  Reshape: '<S63>/Reshape'
         */
        u0_m = fmodf(floorf(rtb_Saturation1_j[3] + CONTROL_PARAM.SERVO4_BIAS),
                     65536.0F);
        rtb_VariantMergeForOutportactua[8] = (uint16_T)(u0_m < 0.0F ? (int32_T)
          (uint16_T)-(int16_T)(uint16_T)-u0_m : (int32_T)(uint16_T)u0_m);
        break;

       default:
        for (i_m = 0; i_m < 9; i_m++) {
          rtb_VariantMergeForOutportactua[i_m] = (uint16_T)fmodf(floorf
            (rtb_Saturation_fr[i_m]), 65536.0F);
        }
        break;
      }

      /* End of MultiPortSwitch: '<S72>/Multiport Switch' */
    }

#endif

    /* End of Outputs for SubSystem: '<S10>/VTOL_Control_Allocation' */
    for (i = 0; i < 9; i++) {
      /* Outport: '<Root>/Control_Out' incorporates:
       *  Reshape: '<S60>/Reshape'
       */
      Controller_Y.Control_Out.actuator_cmd[i] =
        rtb_VariantMergeForOutportactua[i];
    }

    for (i = 0; i < 7; i++) {
      /* Outport: '<Root>/Control_Out' incorporates:
       *  Reshape: '<S60>/Reshape'
       */
      Controller_Y.Control_Out.actuator_cmd[i + 9] = 0U;
    }

    /* Product: '<S25>/Multiply' incorporates:
     *  Constant: '<S25>/gain1'
     *  Constant: '<S25>/gain2'
     *  Constant: '<S25>/gain3'
     *  DiscreteIntegrator: '<S23>/Discrete-Time Integrator5'
     */
    rtb_Divide_i_idx_1 = CONTROL_PARAM.MC_ROLL_RATE_I *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0];
    rtb_Divide_i_idx_2 = CONTROL_PARAM.MC_PITCH_RATE_I *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1];
    rtb_Divide_i_idx_3 = CONTROL_PARAM.MC_YAW_RATE_I *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2];

    /* Product: '<S45>/Multiply1' incorporates:
     *  Constant: '<S45>/const1'
     *  DiscreteIntegrator: '<S42>/Integrator'
     */
    rtb_Gain_ms = Controller_DW.Integrator_DSTATE_jg[0] * 0.05F;
    rtb_Gain_cu = Controller_DW.Integrator_DSTATE_jg[1] * 0.05F;

    /* Sum: '<S45>/Add' incorporates:
     *  DiscreteIntegrator: '<S42>/Integrator1'
     *  Sum: '<S42>/Subtract'
     */
    rtb_Saturation_ov = (Controller_DW.Integrator1_DSTATE_h[0] -
                         Controller_U.FMS_Out.u_cmd) + rtb_Gain_ms;
    rtb_Multiply_ga_idx_0 = (Controller_DW.Integrator1_DSTATE_h[1] -
      Controller_U.FMS_Out.v_cmd) + rtb_Gain_cu;

    /* Product: '<S55>/Multiply1' incorporates:
     *  Constant: '<S55>/const1'
     *  DiscreteIntegrator: '<S54>/Integrator'
     */
    rtb_Abs = Controller_DW.Integrator_DSTATE_e * 0.05F;

    /* Sum: '<S55>/Add' incorporates:
     *  DiscreteIntegrator: '<S54>/Integrator1'
     *  Sum: '<S54>/Subtract'
     */
    rtb_Gain_it = (Controller_DW.Integrator1_DSTATE_o -
                   Controller_U.FMS_Out.w_cmd) + rtb_Abs;

    /* Signum: '<S55>/Sign' */
    if (rtb_Gain_it < 0.0F) {
      rtb_Saturation1_ih = -1.0F;
    } else if (rtb_Gain_it > 0.0F) {
      rtb_Saturation1_ih = 1.0F;
    } else {
      rtb_Saturation1_ih = rtb_Gain_it;
    }

    /* End of Signum: '<S55>/Sign' */

    /* Sum: '<S55>/Add2' incorporates:
     *  Abs: '<S55>/Abs'
     *  Gain: '<S55>/Gain'
     *  Gain: '<S55>/Gain1'
     *  Product: '<S55>/Multiply2'
     *  Product: '<S55>/Multiply3'
     *  Sqrt: '<S55>/Sqrt'
     *  Sum: '<S55>/Add1'
     *  Sum: '<S55>/Subtract'
     */
    rtb_Saturation1_ih = (sqrtf((8.0F * fabsf(rtb_Gain_it) +
      Controller_ConstB.d_j) * Controller_ConstB.d_j) - Controller_ConstB.d_j) *
      0.5F * rtb_Saturation1_ih + rtb_Abs;

    /* Sum: '<S55>/Add4' */
    rtb_Minus = (rtb_Gain_it - rtb_Saturation1_ih) + rtb_Abs;

    /* Sum: '<S55>/Add3' */
    rtb_Abs = rtb_Gain_it + Controller_ConstB.d_j;

    /* Sum: '<S55>/Subtract1' */
    rtb_Gain_it -= Controller_ConstB.d_j;

    /* Signum: '<S55>/Sign1' */
    if (rtb_Abs < 0.0F) {
      rtb_Abs = -1.0F;
    } else {
      if (rtb_Abs > 0.0F) {
        rtb_Abs = 1.0F;
      }
    }

    /* End of Signum: '<S55>/Sign1' */

    /* Signum: '<S55>/Sign2' */
    if (rtb_Gain_it < 0.0F) {
      rtb_Gain_it = -1.0F;
    } else {
      if (rtb_Gain_it > 0.0F) {
        rtb_Gain_it = 1.0F;
      }
    }

    /* End of Signum: '<S55>/Sign2' */

    /* Sum: '<S55>/Add5' incorporates:
     *  Gain: '<S55>/Gain2'
     *  Product: '<S55>/Multiply4'
     *  Sum: '<S55>/Subtract2'
     */
    rtb_Saturation1_ih += (rtb_Abs - rtb_Gain_it) * 0.5F * rtb_Minus;

    /* Update for DiscreteIntegrator: '<S47>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_PrevRe_a = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S49>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_h = 0U;

    /* Signum: '<S45>/Sign' */
    if (rtb_Saturation_ov < 0.0F) {
      rtb_Gain_it = -1.0F;
    } else if (rtb_Saturation_ov > 0.0F) {
      rtb_Gain_it = 1.0F;
    } else {
      rtb_Gain_it = rtb_Saturation_ov;
    }

    /* Sum: '<S45>/Add2' incorporates:
     *  Abs: '<S45>/Abs'
     *  Gain: '<S45>/Gain'
     *  Gain: '<S45>/Gain1'
     *  Product: '<S45>/Multiply2'
     *  Product: '<S45>/Multiply3'
     *  Signum: '<S45>/Sign'
     *  Sqrt: '<S45>/Sqrt'
     *  Sum: '<S45>/Add1'
     *  Sum: '<S45>/Subtract'
     */
    rtb_MatrixConcatenate1_tmp = (sqrtf((8.0F * fabsf(rtb_Saturation_ov) +
      Controller_ConstB.d_ih) * Controller_ConstB.d_ih) - Controller_ConstB.d_ih)
      * 0.5F * rtb_Gain_it + rtb_Gain_ms;

    /* Sum: '<S45>/Add3' incorporates:
     *  Signum: '<S45>/Sign'
     */
    rtb_Abs = rtb_Saturation_ov + Controller_ConstB.d_ih;

    /* Sum: '<S45>/Subtract1' incorporates:
     *  Signum: '<S45>/Sign'
     */
    rtb_Gain_it = rtb_Saturation_ov - Controller_ConstB.d_ih;

    /* Signum: '<S45>/Sign1' */
    if (rtb_Abs < 0.0F) {
      rtb_Abs = -1.0F;
    } else {
      if (rtb_Abs > 0.0F) {
        rtb_Abs = 1.0F;
      }
    }

    /* Signum: '<S45>/Sign2' */
    if (rtb_Gain_it < 0.0F) {
      rtb_Gain_it = -1.0F;
    } else {
      if (rtb_Gain_it > 0.0F) {
        rtb_Gain_it = 1.0F;
      }
    }

    /* Sum: '<S45>/Add2' incorporates:
     *  Gain: '<S45>/Gain2'
     *  Product: '<S45>/Multiply4'
     *  Signum: '<S45>/Sign'
     *  Sum: '<S45>/Add4'
     *  Sum: '<S45>/Add5'
     *  Sum: '<S45>/Subtract2'
     */
    rtb_Gain_ms = ((rtb_Saturation_ov - rtb_MatrixConcatenate1_tmp) +
                   rtb_Gain_ms) * ((rtb_Abs - rtb_Gain_it) * 0.5F) +
      rtb_MatrixConcatenate1_tmp;

    /* Update for DiscreteIntegrator: '<S42>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S42>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_h[0] += 0.002F *
      Controller_DW.Integrator_DSTATE_jg[0];

    /* Update for DiscreteIntegrator: '<S47>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S47>/ki'
     *  Product: '<S47>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[0] +=
      CONTROL_PARAM.MC_VEL_XY_I * rtb_Divide_i_idx_0 * 0.002F;
    if (Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[0] >=
        CONTROL_PARAM.MC_VEL_XY_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[0] =
        CONTROL_PARAM.MC_VEL_XY_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[0] <=
          CONTROL_PARAM.MC_VEL_XY_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[0] =
          CONTROL_PARAM.MC_VEL_XY_I_MIN;
      }
    }

    /* Update for DiscreteIntegrator: '<S49>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_g[0] += 0.002F *
      rtb_Saturation1_h_idx_0;

    /* Signum: '<S45>/Sign' */
    if (rtb_Multiply_ga_idx_0 < 0.0F) {
      rtb_Saturation1_h_idx_0 = -1.0F;
    } else if (rtb_Multiply_ga_idx_0 > 0.0F) {
      rtb_Saturation1_h_idx_0 = 1.0F;
    } else {
      rtb_Saturation1_h_idx_0 = rtb_Multiply_ga_idx_0;
    }

    /* Sum: '<S45>/Add2' incorporates:
     *  Abs: '<S45>/Abs'
     *  Gain: '<S45>/Gain'
     *  Gain: '<S45>/Gain1'
     *  Product: '<S45>/Multiply2'
     *  Product: '<S45>/Multiply3'
     *  Signum: '<S45>/Sign'
     *  Sqrt: '<S45>/Sqrt'
     *  Sum: '<S45>/Add1'
     *  Sum: '<S45>/Subtract'
     */
    rtb_MatrixConcatenate1_tmp = (sqrtf((8.0F * fabsf(rtb_Multiply_ga_idx_0) +
      Controller_ConstB.d_ih) * Controller_ConstB.d_ih) - Controller_ConstB.d_ih)
      * 0.5F * rtb_Saturation1_h_idx_0 + rtb_Gain_cu;

    /* Sum: '<S45>/Add3' incorporates:
     *  Signum: '<S45>/Sign'
     */
    rtb_Abs = rtb_Multiply_ga_idx_0 + Controller_ConstB.d_ih;

    /* Sum: '<S45>/Subtract1' incorporates:
     *  Signum: '<S45>/Sign'
     */
    rtb_Gain_it = rtb_Multiply_ga_idx_0 - Controller_ConstB.d_ih;

    /* Signum: '<S45>/Sign1' */
    if (rtb_Abs < 0.0F) {
      rtb_Abs = -1.0F;
    } else {
      if (rtb_Abs > 0.0F) {
        rtb_Abs = 1.0F;
      }
    }

    /* Signum: '<S45>/Sign2' */
    if (rtb_Gain_it < 0.0F) {
      rtb_Gain_it = -1.0F;
    } else {
      if (rtb_Gain_it > 0.0F) {
        rtb_Gain_it = 1.0F;
      }
    }

    /* Sum: '<S45>/Add5' incorporates:
     *  Gain: '<S45>/Gain2'
     *  Product: '<S45>/Multiply4'
     *  Signum: '<S45>/Sign'
     *  Sum: '<S45>/Add2'
     *  Sum: '<S45>/Add4'
     *  Sum: '<S45>/Subtract2'
     */
    rtb_MatrixConcatenate1_tmp += ((rtb_Multiply_ga_idx_0 -
      rtb_MatrixConcatenate1_tmp) + rtb_Gain_cu) * ((rtb_Abs - rtb_Gain_it) *
      0.5F);

    /* Update for DiscreteIntegrator: '<S42>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S42>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_h[1] += 0.002F *
      Controller_DW.Integrator_DSTATE_jg[1];

    /* Update for DiscreteIntegrator: '<S47>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S47>/ki'
     *  Product: '<S47>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[1] +=
      CONTROL_PARAM.MC_VEL_XY_I * rtb_Cos_j * 0.002F;
    if (Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[1] >=
        CONTROL_PARAM.MC_VEL_XY_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[1] =
        CONTROL_PARAM.MC_VEL_XY_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[1] <=
          CONTROL_PARAM.MC_VEL_XY_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[1] =
          CONTROL_PARAM.MC_VEL_XY_I_MIN;
      }
    }

    /* Update for DiscreteIntegrator: '<S49>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_g[1] += 0.002F * rtb_Divide_gn;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_p = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S23>/Discrete-Time Integrator5' */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_e = 0U;

    /* Update for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_PrevR_ps = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S27>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_p = 0U;

    /* Update for DiscreteIntegrator: '<S23>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S23>/Gain'
     *  Sum: '<S23>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0] += (rtb_Add_c -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_g[0] += 0.002F *
      rtb_Divide_i_idx_1;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_g[0] >=
        CONTROL_PARAM.MC_RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_g[0] =
        CONTROL_PARAM.MC_RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_g[0] <=
          CONTROL_PARAM.MC_RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_g[0] =
          CONTROL_PARAM.MC_RATE_I_MIN;
      }
    }

    /* Update for DiscreteIntegrator: '<S27>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_l[0] += 0.002F *
      rtb_DiscreteTimeIntegrator1_k1[0];

    /* Update for DiscreteIntegrator: '<S23>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S23>/Gain'
     *  Sum: '<S23>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1] += (rtb_FF_limit_idx_1 -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_g[1] += 0.002F *
      rtb_Divide_i_idx_2;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_g[1] >=
        CONTROL_PARAM.MC_RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_g[1] =
        CONTROL_PARAM.MC_RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_g[1] <=
          CONTROL_PARAM.MC_RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_g[1] =
          CONTROL_PARAM.MC_RATE_I_MIN;
      }
    }

    /* Update for DiscreteIntegrator: '<S27>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_l[1] += 0.002F *
      rtb_DiscreteTimeIntegrator1_k1[1];

    /* Update for DiscreteIntegrator: '<S23>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S23>/Gain'
     *  Sum: '<S23>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2] += (rtb_FF_limit_idx_2 -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_g[2] += 0.002F *
      rtb_Divide_i_idx_3;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_g[2] >=
        CONTROL_PARAM.MC_RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_g[2] =
        CONTROL_PARAM.MC_RATE_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_g[2] <=
          CONTROL_PARAM.MC_RATE_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_g[2] =
          CONTROL_PARAM.MC_RATE_I_MIN;
      }
    }

    /* Update for DiscreteIntegrator: '<S27>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_l[2] += 0.002F *
      rtb_DiscreteTimeIntegrator1_k1[2];
    Controller_DW.DiscreteTimeIntegrator1_PrevR_c = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S54>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S54>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_o += 0.002F *
      Controller_DW.Integrator_DSTATE_e;

    /* Update for DiscreteIntegrator: '<S57>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S57>/ki'
     *  Product: '<S57>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_p += CONTROL_PARAM.MC_VEL_Z_I *
      rtb_VdotPg * 0.002F;
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_p >=
        CONTROL_PARAM.MC_VEL_Z_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_p =
        CONTROL_PARAM.MC_VEL_Z_I_MAX;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator_DSTATE_p <=
          CONTROL_PARAM.MC_VEL_Z_I_MIN) {
        Controller_DW.DiscreteTimeIntegrator_DSTATE_p =
          CONTROL_PARAM.MC_VEL_Z_I_MIN;
      }
    }

    Controller_DW.DiscreteTimeIntegrator_PrevRe_c = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* End of Update for DiscreteIntegrator: '<S57>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S59>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_b = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_d += 0.002F * rtb_Cos1_d;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_a = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Signum: '<S45>/Sign3' incorporates:
     *  Product: '<S45>/Divide'
     *  Sum: '<S45>/Add6'
     */
    rtb_Abs = rtb_Gain_ms + Controller_ConstB.d_ih;

    /* Signum: '<S45>/Sign4' incorporates:
     *  Product: '<S45>/Divide'
     *  Sum: '<S45>/Subtract3'
     */
    rtb_Add_c = rtb_Gain_ms - Controller_ConstB.d_ih;

    /* Signum: '<S45>/Sign5' incorporates:
     *  Product: '<S45>/Divide'
     */
    if (rtb_Gain_ms < 0.0F) {
      rtb_Divide_i_idx_1 = -1.0F;
    } else if (rtb_Gain_ms > 0.0F) {
      rtb_Divide_i_idx_1 = 1.0F;
    } else {
      rtb_Divide_i_idx_1 = rtb_Gain_ms;
    }

    /* Signum: '<S45>/Sign3' */
    if (rtb_Abs < 0.0F) {
      rtb_Abs = -1.0F;
    } else {
      if (rtb_Abs > 0.0F) {
        rtb_Abs = 1.0F;
      }
    }

    /* Signum: '<S45>/Sign4' */
    if (rtb_Add_c < 0.0F) {
      rtb_Add_c = -1.0F;
    } else {
      if (rtb_Add_c > 0.0F) {
        rtb_Add_c = 1.0F;
      }
    }

    /* Signum: '<S45>/Sign6' incorporates:
     *  Product: '<S45>/Divide'
     */
    if (rtb_Gain_ms < 0.0F) {
      rtb_FF_limit_idx_1 = -1.0F;
    } else if (rtb_Gain_ms > 0.0F) {
      rtb_FF_limit_idx_1 = 1.0F;
    } else {
      rtb_FF_limit_idx_1 = rtb_Gain_ms;
    }

    /* Update for DiscreteIntegrator: '<S42>/Integrator' incorporates:
     *  Constant: '<S45>/const'
     *  Gain: '<S45>/Gain3'
     *  Product: '<S45>/Divide'
     *  Product: '<S45>/Multiply5'
     *  Product: '<S45>/Multiply6'
     *  Sum: '<S45>/Subtract4'
     *  Sum: '<S45>/Subtract5'
     *  Sum: '<S45>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE_jg[0] += ((rtb_Gain_ms /
      Controller_ConstB.d_ih - rtb_Divide_i_idx_1) * Controller_ConstB.Gain4_f *
      ((rtb_Abs - rtb_Add_c) * 0.5F) - rtb_FF_limit_idx_1 * 58.836F) * 0.002F;

    /* Signum: '<S45>/Sign3' incorporates:
     *  Sum: '<S45>/Add6'
     */
    rtb_Abs = rtb_MatrixConcatenate1_tmp + Controller_ConstB.d_ih;

    /* Signum: '<S45>/Sign4' incorporates:
     *  Sum: '<S45>/Subtract3'
     */
    rtb_Add_c = rtb_MatrixConcatenate1_tmp - Controller_ConstB.d_ih;

    /* Signum: '<S45>/Sign5' */
    if (rtb_MatrixConcatenate1_tmp < 0.0F) {
      rtb_FF_limit_idx_1 = -1.0F;
    } else if (rtb_MatrixConcatenate1_tmp > 0.0F) {
      rtb_FF_limit_idx_1 = 1.0F;
    } else {
      rtb_FF_limit_idx_1 = rtb_MatrixConcatenate1_tmp;
    }

    /* Signum: '<S45>/Sign3' */
    if (rtb_Abs < 0.0F) {
      rtb_Abs = -1.0F;
    } else {
      if (rtb_Abs > 0.0F) {
        rtb_Abs = 1.0F;
      }
    }

    /* Signum: '<S45>/Sign4' */
    if (rtb_Add_c < 0.0F) {
      rtb_Add_c = -1.0F;
    } else {
      if (rtb_Add_c > 0.0F) {
        rtb_Add_c = 1.0F;
      }
    }

    /* Signum: '<S45>/Sign6' */
    if (rtb_MatrixConcatenate1_tmp < 0.0F) {
      rtb_FF_limit_idx_2 = -1.0F;
    } else if (rtb_MatrixConcatenate1_tmp > 0.0F) {
      rtb_FF_limit_idx_2 = 1.0F;
    } else {
      rtb_FF_limit_idx_2 = rtb_MatrixConcatenate1_tmp;
    }

    /* Update for DiscreteIntegrator: '<S42>/Integrator' incorporates:
     *  Constant: '<S45>/const'
     *  Gain: '<S45>/Gain3'
     *  Product: '<S45>/Divide'
     *  Product: '<S45>/Multiply5'
     *  Product: '<S45>/Multiply6'
     *  Sum: '<S45>/Subtract4'
     *  Sum: '<S45>/Subtract5'
     *  Sum: '<S45>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE_jg[1] += ((rtb_MatrixConcatenate1_tmp /
      Controller_ConstB.d_ih - rtb_FF_limit_idx_1) * Controller_ConstB.Gain4_f *
      ((rtb_Abs - rtb_Add_c) * 0.5F) - rtb_FF_limit_idx_2 * 58.836F) * 0.002F;

    /* Signum: '<S55>/Sign6' incorporates:
     *  Signum: '<S55>/Sign5'
     */
    if (rtb_Saturation1_ih < 0.0F) {
      rtb_FF_limit_idx_1 = -1.0F;

      /* Signum: '<S55>/Sign5' */
      rtb_FF_limit_idx_2 = -1.0F;
    } else if (rtb_Saturation1_ih > 0.0F) {
      rtb_FF_limit_idx_1 = 1.0F;

      /* Signum: '<S55>/Sign5' */
      rtb_FF_limit_idx_2 = 1.0F;
    } else {
      rtb_FF_limit_idx_1 = rtb_Saturation1_ih;

      /* Signum: '<S55>/Sign5' */
      rtb_FF_limit_idx_2 = rtb_Saturation1_ih;
    }

    /* End of Signum: '<S55>/Sign6' */

    /* Sum: '<S55>/Add6' */
    rtb_Abs = rtb_Saturation1_ih + Controller_ConstB.d_j;

    /* Sum: '<S55>/Subtract3' */
    rtb_Add_c = rtb_Saturation1_ih - Controller_ConstB.d_j;

    /* Signum: '<S55>/Sign3' */
    if (rtb_Abs < 0.0F) {
      rtb_Abs = -1.0F;
    } else {
      if (rtb_Abs > 0.0F) {
        rtb_Abs = 1.0F;
      }
    }

    /* End of Signum: '<S55>/Sign3' */

    /* Signum: '<S55>/Sign4' */
    if (rtb_Add_c < 0.0F) {
      rtb_Add_c = -1.0F;
    } else {
      if (rtb_Add_c > 0.0F) {
        rtb_Add_c = 1.0F;
      }
    }

    /* End of Signum: '<S55>/Sign4' */

    /* Update for DiscreteIntegrator: '<S54>/Integrator' incorporates:
     *  Constant: '<S55>/const'
     *  Gain: '<S55>/Gain3'
     *  Product: '<S55>/Divide'
     *  Product: '<S55>/Multiply5'
     *  Product: '<S55>/Multiply6'
     *  Sum: '<S55>/Subtract4'
     *  Sum: '<S55>/Subtract5'
     *  Sum: '<S55>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE_e += ((rtb_Saturation1_ih /
      Controller_ConstB.d_j - rtb_FF_limit_idx_2) * Controller_ConstB.Gain4_n *
      ((rtb_Abs - rtb_Add_c) * 0.5F) - rtb_FF_limit_idx_1 * 78.448F) * 0.002F;

    /* End of Outputs for SubSystem: '<S2>/BackTrans_Controller' */
    break;

   case 2:
    if (Controller_DW.SwitchCase1_ActiveSubsystem != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S2>/MC_Controller' incorporates:
       *  ActionPort: '<S5>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S8>/Switch Case1' incorporates:
       *  DiscreteIntegrator: '<S115>/Integrator'
       *  DiscreteIntegrator: '<S115>/Integrator1'
       *  DiscreteIntegrator: '<S120>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S122>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S138>/Integrator'
       *  DiscreteIntegrator: '<S138>/Integrator1'
       *  DiscreteIntegrator: '<S141>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S143>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S91>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S93>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S95>/Discrete-Time Integrator1'
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

      Controller_DW.DiscreteTimeIntegrator_PrevRe_p = 0;
      Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;
      Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 1U;
      Controller_DW.DiscreteTimeIntegrator1_PrevR_k = 0;
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
      Controller_DW.Integrator_DSTATE[0] = 0.0F;
      Controller_DW.Integrator_DSTATE[1] = 0.0F;
      Controller_DW.Integrator_DSTATE_j = 0.0F;

      /* End of InitializeConditions for SubSystem: '<S2>/MC_Controller' */
    }

    /* Outputs for IfAction SubSystem: '<S2>/MC_Controller' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* DiscreteIntegrator: '<S93>/Discrete-Time Integrator' */
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

    /* Trigonometry: '<S117>/Trigonometric Function1' incorporates:
     *  Gain: '<S116>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1[0] = arm_cos_f32(-Controller_U.INS_Out.psi);

    /* Trigonometry: '<S117>/Trigonometric Function' incorporates:
     *  Gain: '<S116>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1[1] = arm_sin_f32(-Controller_U.INS_Out.psi);

    /* SignalConversion: '<S117>/ConcatBufferAtVector Concatenate1In3' incorporates:
     *  Constant: '<S117>/Constant3'
     */
    rtb_MatrixConcatenate1[2] = 0.0F;

    /* Gain: '<S117>/Gain' incorporates:
     *  Gain: '<S116>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S117>/Trigonometric Function2'
     */
    rtb_MatrixConcatenate1[3] = -arm_sin_f32(-Controller_U.INS_Out.psi);

    /* Trigonometry: '<S117>/Trigonometric Function3' incorporates:
     *  Gain: '<S116>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1[4] = arm_cos_f32(-Controller_U.INS_Out.psi);

    /* SignalConversion: '<S117>/ConcatBufferAtVector Concatenate2In3' incorporates:
     *  Constant: '<S117>/Constant4'
     */
    rtb_MatrixConcatenate1[5] = 0.0F;

    /* SignalConversion: '<S117>/ConcatBufferAtVector ConcatenateIn3' */
    rtb_MatrixConcatenate1[6] = Controller_ConstB.VectorConcatenate3[0];
    rtb_MatrixConcatenate1[7] = Controller_ConstB.VectorConcatenate3[1];
    rtb_MatrixConcatenate1[8] = Controller_ConstB.VectorConcatenate3[2];

    /* Product: '<S114>/Multiply' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  SignalConversion: '<S114>/TmpSignal ConversionAtMultiplyInport2'
     */
    for (i = 0; i < 3; i++) {
      rtb_MatrixConcatenate1_0[i] = rtb_MatrixConcatenate1[i + 3] *
        Controller_U.INS_Out.ve + rtb_MatrixConcatenate1[i] *
        Controller_U.INS_Out.vn;
    }

    /* End of Product: '<S114>/Multiply' */

    /* Sum: '<S111>/Sum' incorporates:
     *  DiscreteIntegrator: '<S115>/Integrator1'
     */
    rtb_Divide_i_idx_0 = Controller_DW.Integrator1_DSTATE[0] -
      rtb_MatrixConcatenate1_0[0];
    rtb_Cos_j = Controller_DW.Integrator1_DSTATE[1] - rtb_MatrixConcatenate1_0[1];

    /* DiscreteIntegrator: '<S120>/Discrete-Time Integrator' */
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

    /* DiscreteIntegrator: '<S122>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] = rtb_Divide_i_idx_0;
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] = rtb_Cos_j;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevRes != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] = rtb_Divide_i_idx_0;
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] = rtb_Cos_j;
    }

    /* Gain: '<S122>/Gain' incorporates:
     *  DiscreteIntegrator: '<S122>/Discrete-Time Integrator1'
     *  Sum: '<S122>/Sum5'
     */
    rtb_Saturation1_h_idx_0 = (rtb_Divide_i_idx_0 -
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[0]) * 62.831852F;
    rtb_Divide_gn = (rtb_Cos_j - Controller_DW.DiscreteTimeIntegrator1_DSTATE[1])
      * 62.831852F;

    /* Switch: '<S122>/Switch' incorporates:
     *  Gain: '<S122>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_Gain_ms = 0.0F;
      rtb_Gain_cu = 0.0F;
    } else {
      rtb_Gain_ms = rtb_Saturation1_h_idx_0;
      rtb_Gain_cu = rtb_Divide_gn;
    }

    /* End of Switch: '<S122>/Switch' */

    /* Product: '<S119>/Multiply' incorporates:
     *  Constant: '<S119>/kd'
     */
    rtb_Divide_i_idx_1 = CONTROL_PARAM.MC_VEL_XY_D * rtb_Gain_ms;

    /* Saturate: '<S119>/Saturation' */
    if (rtb_Divide_i_idx_1 > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
      rtb_Divide_i_idx_1 = CONTROL_PARAM.MC_VEL_XY_D_MAX;
    } else {
      if (rtb_Divide_i_idx_1 < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
        rtb_Divide_i_idx_1 = CONTROL_PARAM.MC_VEL_XY_D_MIN;
      }
    }

    rtb_Gain_ms = rtb_Divide_i_idx_1;

    /* Product: '<S119>/Multiply' incorporates:
     *  Constant: '<S119>/kd'
     */
    rtb_Divide_i_idx_1 = CONTROL_PARAM.MC_VEL_XY_D * rtb_Gain_cu;

    /* Saturate: '<S119>/Saturation' */
    if (rtb_Divide_i_idx_1 > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
      rtb_Divide_i_idx_1 = CONTROL_PARAM.MC_VEL_XY_D_MAX;
    } else {
      if (rtb_Divide_i_idx_1 < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
        rtb_Divide_i_idx_1 = CONTROL_PARAM.MC_VEL_XY_D_MIN;
      }
    }

    /* Switch: '<S113>/Switch' incorporates:
     *  Constant: '<S121>/kp'
     *  Constant: '<S123>/Constant'
     *  Constant: '<S125>/Constant'
     *  Constant: '<S126>/Constant'
     *  DiscreteIntegrator: '<S120>/Discrete-Time Integrator'
     *  Product: '<S121>/Multiply'
     *  Product: '<S124>/Multiply2'
     *  Product: '<S124>/Multiply3'
     *  RelationalOperator: '<S123>/Compare'
     *  RelationalOperator: '<S125>/Compare'
     *  RelationalOperator: '<S126>/Compare'
     *  S-Function (sfix_bitop): '<S124>/cmd_ax valid'
     *  S-Function (sfix_bitop): '<S124>/cmd_ay valid'
     *  S-Function (sfix_bitop): '<S124>/cmd_u valid'
     *  S-Function (sfix_bitop): '<S124>/cmd_v valid'
     *  Sum: '<S112>/Add'
     *  Sum: '<S124>/Sum1'
     */
    if (rtb_BitwiseAND_a == 6) {
      rtb_Gain_ms = ((Controller_U.FMS_Out.cmd_mask & 64) > 0 ?
                     (CONTROL_PARAM.MC_VEL_XY_P * rtb_Divide_i_idx_0 +
                      Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0]) +
                     rtb_Gain_ms : 0.0F) + ((Controller_U.FMS_Out.cmd_mask & 512)
        > 0 ? Controller_U.FMS_Out.ax_cmd : 0.0F);
      rtb_Gain_cu = ((Controller_U.FMS_Out.cmd_mask & 128) > 0 ?
                     (CONTROL_PARAM.MC_VEL_XY_P * rtb_Cos_j +
                      Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1]) +
                     rtb_Divide_i_idx_1 : 0.0F) +
        ((Controller_U.FMS_Out.cmd_mask & 1024) > 0 ?
         Controller_U.FMS_Out.ay_cmd : 0.0F);
    } else {
      rtb_Gain_ms += CONTROL_PARAM.MC_VEL_XY_P * rtb_Divide_i_idx_0 +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0];
      rtb_Gain_cu = (CONTROL_PARAM.MC_VEL_XY_P * rtb_Cos_j +
                     Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1]) +
        rtb_Divide_i_idx_1;
    }

    /* End of Switch: '<S113>/Switch' */

    /* Trigonometry: '<S110>/Atan' incorporates:
     *  Constant: '<S110>/g'
     *  Gain: '<S110>/Gain1'
     *  Gain: '<S110>/gain'
     *  Product: '<S110>/Divide'
     */
    u0 = atanf(1.1F * rtb_Gain_cu / 9.8055F);
    rtb_Gain_cu = atanf(1.1F * -rtb_Gain_ms / 9.8055F);

    /* Switch: '<S101>/Switch' incorporates:
     *  Constant: '<S108>/Constant'
     *  Logic: '<S101>/Logical Operator'
     *  RelationalOperator: '<S107>/Compare'
     *  RelationalOperator: '<S108>/Compare'
     *  Saturate: '<S110>/Saturation'
     *  Switch: '<S101>/Switch1'
     */
    if ((rtb_BitwiseAND_a == 3) || (rtb_BitwiseAND_a == 4)) {
      rtb_Gain_ms = Controller_U.FMS_Out.phi_cmd;
      rtb_Gain_cu = Controller_U.FMS_Out.theta_cmd;
    } else if (rtb_BitwiseAND_a == 6) {
      /* Switch: '<S109>/Switch' incorporates:
       *  S-Function (sfix_bitop): '<S109>/cmd_phi valid'
       *  S-Function (sfix_bitop): '<S109>/cmd_theta valid'
       *  Saturate: '<S110>/Saturation'
       *  Switch: '<S101>/Switch1'
       */
      if ((Controller_U.FMS_Out.cmd_mask & 8) > 0) {
        rtb_Gain_ms = Controller_U.FMS_Out.phi_cmd;
      } else if (u0 > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S110>/Saturation' */
        rtb_Gain_ms = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else if (u0 < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S110>/Saturation' */
        rtb_Gain_ms = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        rtb_Gain_ms = u0;
      }

      if ((Controller_U.FMS_Out.cmd_mask & 16) > 0) {
        rtb_Gain_cu = Controller_U.FMS_Out.theta_cmd;
      } else if (rtb_Gain_cu > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S110>/Saturation' */
        rtb_Gain_cu = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_Gain_cu < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Saturate: '<S110>/Saturation' */
          rtb_Gain_cu = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        }
      }

      /* End of Switch: '<S109>/Switch' */
    } else {
      if (u0 > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S110>/Saturation' incorporates:
         *  Switch: '<S101>/Switch1'
         */
        rtb_Gain_ms = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else if (u0 < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S110>/Saturation' incorporates:
         *  Switch: '<S101>/Switch1'
         */
        rtb_Gain_ms = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        /* Switch: '<S101>/Switch1' incorporates:
         *  Saturate: '<S110>/Saturation'
         */
        rtb_Gain_ms = u0;
      }

      /* Saturate: '<S110>/Saturation' */
      if (rtb_Gain_cu > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Switch: '<S101>/Switch1' */
        rtb_Gain_cu = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_Gain_cu < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Switch: '<S101>/Switch1' */
          rtb_Gain_cu = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        }
      }
    }

    /* End of Switch: '<S101>/Switch' */

    /* Sum: '<S102>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_i_idx_1 = rtb_Gain_ms - Controller_U.INS_Out.phi;

    /* Product: '<S105>/Divide1' incorporates:
     *  Abs: '<S105>/Abs'
     *  Constant: '<S105>/const2'
     */
    rtb_Gain_it = fabsf(rtb_Divide_i_idx_1) / 0.002F;

    /* Product: '<S105>/Divide' incorporates:
     *  Constant: '<S103>/Constant1'
     *  Constant: '<S105>/const1'
     *  Math: '<S105>/Square'
     *  SignalConversion: '<S105>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_MatrixConcatenate1_tmp = 9.5993F / (CONTROL_PARAM.MC_ROLL_P *
      CONTROL_PARAM.MC_ROLL_P);

    /* Signum: '<S105>/Sign' */
    if (rtb_Divide_i_idx_1 < 0.0F) {
      rtb_FF_limit_idx_1 = -1.0F;
    } else if (rtb_Divide_i_idx_1 > 0.0F) {
      rtb_FF_limit_idx_1 = 1.0F;
    } else {
      rtb_FF_limit_idx_1 = rtb_Divide_i_idx_1;
    }

    /* Switch: '<S105>/Switch' incorporates:
     *  Constant: '<S103>/Constant1'
     *  Gain: '<S105>/Gain1'
     *  Gain: '<S105>/Gain2'
     *  Logic: '<S105>/Logical Operator'
     *  Product: '<S105>/Divide'
     *  Product: '<S105>/Multiply'
     *  Product: '<S105>/Multiply1'
     *  Product: '<S105>/Multiply2'
     *  Product: '<S105>/Multiply3'
     *  RelationalOperator: '<S105>/Relational Operator'
     *  RelationalOperator: '<S105>/Relational Operator2'
     *  SignalConversion: '<S105>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S105>/Sqrt'
     *  Sum: '<S105>/Subtract'
     */
    if ((rtb_Divide_i_idx_1 <= rtb_MatrixConcatenate1_tmp) &&
        (rtb_Divide_i_idx_1 >= -rtb_MatrixConcatenate1_tmp)) {
      rtb_FF_limit_idx_1 = rtb_Divide_i_idx_1 * CONTROL_PARAM.MC_ROLL_P;
    } else {
      rtb_FF_limit_idx_1 *= sqrtf((rtb_FF_limit_idx_1 * rtb_Divide_i_idx_1 -
        0.5F * rtb_MatrixConcatenate1_tmp) * Controller_ConstB.Gain);
    }

    /* Gain: '<S105>/Gain3' */
    rtb_MatrixConcatenate1_tmp = -rtb_Gain_it;

    /* Switch: '<S106>/Switch' incorporates:
     *  Gain: '<S105>/Gain3'
     *  RelationalOperator: '<S106>/UpperRelop'
     */
    if (rtb_FF_limit_idx_1 >= -rtb_Gain_it) {
      rtb_MatrixConcatenate1_tmp = rtb_FF_limit_idx_1;
    }

    /* Switch: '<S106>/Switch2' incorporates:
     *  RelationalOperator: '<S106>/LowerRelop1'
     */
    if (rtb_FF_limit_idx_1 <= rtb_Gain_it) {
      rtb_Gain_it = rtb_MatrixConcatenate1_tmp;
    }

    /* Saturate: '<S86>/Saturation1' */
    if (rtb_Gain_it > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_Gain_it = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_Gain_it < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_Gain_it = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    rtb_Saturation_ov = rtb_Gain_it;

    /* Sum: '<S102>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S105>/Divide1'
     */
    rtb_Divide_i_idx_1 = rtb_Gain_cu - Controller_U.INS_Out.theta;

    /* Product: '<S105>/Divide1' incorporates:
     *  Abs: '<S105>/Abs'
     *  Constant: '<S105>/const2'
     */
    rtb_Gain_it = fabsf(rtb_Divide_i_idx_1) / 0.002F;

    /* Product: '<S105>/Divide' incorporates:
     *  Constant: '<S103>/Constant2'
     *  Constant: '<S105>/const1'
     *  Math: '<S105>/Square'
     *  SignalConversion: '<S105>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_MatrixConcatenate1_tmp = 9.5993F / (CONTROL_PARAM.MC_PITCH_P *
      CONTROL_PARAM.MC_PITCH_P);

    /* Signum: '<S105>/Sign' */
    if (rtb_Divide_i_idx_1 < 0.0F) {
      rtb_FF_limit_idx_1 = -1.0F;
    } else if (rtb_Divide_i_idx_1 > 0.0F) {
      rtb_FF_limit_idx_1 = 1.0F;
    } else {
      rtb_FF_limit_idx_1 = rtb_Divide_i_idx_1;
    }

    /* Switch: '<S105>/Switch' incorporates:
     *  Constant: '<S103>/Constant2'
     *  Gain: '<S105>/Gain1'
     *  Gain: '<S105>/Gain2'
     *  Logic: '<S105>/Logical Operator'
     *  Product: '<S105>/Divide'
     *  Product: '<S105>/Multiply'
     *  Product: '<S105>/Multiply1'
     *  Product: '<S105>/Multiply2'
     *  Product: '<S105>/Multiply3'
     *  RelationalOperator: '<S105>/Relational Operator'
     *  RelationalOperator: '<S105>/Relational Operator2'
     *  SignalConversion: '<S105>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S105>/Sqrt'
     *  Sum: '<S105>/Subtract'
     */
    if ((rtb_Divide_i_idx_1 <= rtb_MatrixConcatenate1_tmp) &&
        (rtb_Divide_i_idx_1 >= -rtb_MatrixConcatenate1_tmp)) {
      rtb_FF_limit_idx_1 = rtb_Divide_i_idx_1 * CONTROL_PARAM.MC_PITCH_P;
    } else {
      rtb_FF_limit_idx_1 *= sqrtf((rtb_FF_limit_idx_1 * rtb_Divide_i_idx_1 -
        0.5F * rtb_MatrixConcatenate1_tmp) * Controller_ConstB.Gain);
    }

    /* Gain: '<S105>/Gain3' */
    rtb_MatrixConcatenate1_tmp = -rtb_Gain_it;

    /* Switch: '<S106>/Switch' incorporates:
     *  Gain: '<S105>/Gain3'
     *  RelationalOperator: '<S106>/UpperRelop'
     */
    if (rtb_FF_limit_idx_1 >= -rtb_Gain_it) {
      rtb_MatrixConcatenate1_tmp = rtb_FF_limit_idx_1;
    }

    /* Switch: '<S106>/Switch2' incorporates:
     *  RelationalOperator: '<S106>/LowerRelop1'
     */
    if (rtb_FF_limit_idx_1 <= rtb_Gain_it) {
      rtb_Gain_it = rtb_MatrixConcatenate1_tmp;
    }

    /* Saturate: '<S86>/Saturation1' */
    if (rtb_Gain_it > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_Gain_it = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_Gain_it < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_Gain_it = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    /* Saturate: '<S86>/Saturation' */
    if (Controller_U.FMS_Out.psi_rate_cmd > CONTROL_PARAM.MC_R_CMD_LIM) {
      rtb_Multiply_ga_idx_0 = CONTROL_PARAM.MC_R_CMD_LIM;
    } else if (Controller_U.FMS_Out.psi_rate_cmd < -CONTROL_PARAM.MC_R_CMD_LIM)
    {
      rtb_Multiply_ga_idx_0 = -CONTROL_PARAM.MC_R_CMD_LIM;
    } else {
      rtb_Multiply_ga_idx_0 = Controller_U.FMS_Out.psi_rate_cmd;
    }

    /* End of Saturate: '<S86>/Saturation' */

    /* Trigonometry: '<S96>/Sin' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_i_idx_2 = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S96>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Add_c = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Product: '<S96>/Multiply3' incorporates:
     *  Trigonometry: '<S96>/Cos1'
     *  Trigonometry: '<S96>/Sin'
     */
    rtb_FF_limit_idx_1 = rtb_Divide_i_idx_2 * rtb_Add_c * rtb_Multiply_ga_idx_0;

    /* Trigonometry: '<S96>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_FF_limit_idx_2 = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Product: '<S96>/Multiply1' incorporates:
     *  Trigonometry: '<S96>/Cos'
     */
    rtb_Gain_ms = rtb_FF_limit_idx_2 * rtb_Gain_it;

    /* Product: '<S96>/Multiply4' incorporates:
     *  Trigonometry: '<S96>/Sin'
     */
    rtb_Divide_i_idx_2 *= rtb_Gain_it;

    /* Switch: '<S87>/Switch' incorporates:
     *  Constant: '<S97>/Constant'
     *  Constant: '<S98>/Constant'
     *  RelationalOperator: '<S97>/Compare'
     *  RelationalOperator: '<S98>/Compare'
     *  Switch: '<S87>/Switch1'
     */
    if (rtb_BitwiseAND_a == 2) {
      rtb_DiscreteTimeIntegrator1_k1[0] = Controller_U.FMS_Out.p_cmd;
      rtb_DiscreteTimeIntegrator1_k1[1] = Controller_U.FMS_Out.q_cmd;
      rtb_DiscreteTimeIntegrator1_k1[2] = Controller_U.FMS_Out.r_cmd;
    } else if (rtb_BitwiseAND_a == 6) {
      /* Switch: '<S99>/Switch' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Product: '<S96>/Multiply'
       *  Product: '<S96>/Multiply1'
       *  Product: '<S96>/Multiply5'
       *  S-Function (sfix_bitop): '<S99>/cmd_p valid'
       *  S-Function (sfix_bitop): '<S99>/cmd_q valid'
       *  S-Function (sfix_bitop): '<S99>/cmd_r valid'
       *  Sum: '<S96>/Add'
       *  Sum: '<S96>/Add1'
       *  Sum: '<S96>/Add2'
       *  Switch: '<S87>/Switch1'
       *  Trigonometry: '<S96>/Cos'
       *  Trigonometry: '<S96>/Cos1'
       *  Trigonometry: '<S96>/Sin1'
       */
      if ((Controller_U.FMS_Out.cmd_mask & 1) > 0) {
        rtb_DiscreteTimeIntegrator1_k1[0] = Controller_U.FMS_Out.p_cmd;
      } else {
        rtb_DiscreteTimeIntegrator1_k1[0] = rtb_Saturation_ov - arm_sin_f32
          (Controller_U.INS_Out.theta) * rtb_Multiply_ga_idx_0;
      }

      if ((Controller_U.FMS_Out.cmd_mask & 2) > 0) {
        rtb_DiscreteTimeIntegrator1_k1[1] = Controller_U.FMS_Out.q_cmd;
      } else {
        rtb_DiscreteTimeIntegrator1_k1[1] = rtb_FF_limit_idx_1 + rtb_Gain_ms;
      }

      if ((Controller_U.FMS_Out.cmd_mask & 4) > 0) {
        rtb_DiscreteTimeIntegrator1_k1[2] = Controller_U.FMS_Out.r_cmd;
      } else {
        rtb_DiscreteTimeIntegrator1_k1[2] = rtb_FF_limit_idx_2 * rtb_Add_c *
          rtb_Multiply_ga_idx_0 - rtb_Divide_i_idx_2;
      }

      /* End of Switch: '<S99>/Switch' */
    } else {
      /* Switch: '<S87>/Switch1' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Product: '<S96>/Multiply'
       *  Product: '<S96>/Multiply3'
       *  Product: '<S96>/Multiply5'
       *  Sum: '<S96>/Add'
       *  Sum: '<S96>/Add1'
       *  Sum: '<S96>/Add2'
       *  Trigonometry: '<S96>/Cos'
       *  Trigonometry: '<S96>/Cos1'
       *  Trigonometry: '<S96>/Sin1'
       */
      rtb_DiscreteTimeIntegrator1_k1[0] = rtb_Saturation_ov - arm_sin_f32
        (Controller_U.INS_Out.theta) * rtb_Multiply_ga_idx_0;
      rtb_DiscreteTimeIntegrator1_k1[1] = rtb_Gain_ms + rtb_FF_limit_idx_1;
      rtb_DiscreteTimeIntegrator1_k1[2] = rtb_FF_limit_idx_2 * rtb_Add_c *
        rtb_Multiply_ga_idx_0 - rtb_Divide_i_idx_2;
    }

    /* End of Switch: '<S87>/Switch' */

    /* Sum: '<S88>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Add_c = rtb_DiscreteTimeIntegrator1_k1[0] - Controller_U.INS_Out.p;
    rtb_FF_limit_idx_1 = rtb_DiscreteTimeIntegrator1_k1[1] -
      Controller_U.INS_Out.q;
    rtb_FF_limit_idx_2 = rtb_DiscreteTimeIntegrator1_k1[2] -
      Controller_U.INS_Out.r;

    /* DiscreteIntegrator: '<S91>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] = rtb_Add_c;
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] = rtb_FF_limit_idx_1;
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] = rtb_FF_limit_idx_2;
    }

    /* DiscreteIntegrator: '<S95>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S91>/Discrete-Time Integrator5'
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

    /* Gain: '<S95>/Gain' incorporates:
     *  DiscreteIntegrator: '<S91>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S95>/Discrete-Time Integrator1'
     *  Sum: '<S95>/Sum5'
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

    /* Gain: '<S136>/Gain' incorporates:
     *  DiscreteIntegrator: '<S138>/Integrator1'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S136>/Sum1'
     */
    rtb_Gain_it = -(Controller_DW.Integrator1_DSTATE_e - Controller_U.INS_Out.vd);
    Controller_B.Constant = CONTROL_PARAM.MC_VEL_Z_I_MIN;

    /* DiscreteIntegrator: '<S141>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S141>/Constant'
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

    /* DiscreteIntegrator: '<S143>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_d != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i = rtb_Gain_it;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_Prev_ks != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i = rtb_Gain_it;
    }

    /* Gain: '<S143>/Gain' incorporates:
     *  DiscreteIntegrator: '<S143>/Discrete-Time Integrator1'
     *  Sum: '<S143>/Sum5'
     */
    rtb_Gain_cu = (rtb_Gain_it - Controller_DW.DiscreteTimeIntegrator1_DSTAT_i) *
      62.831852F;

    /* Switch: '<S143>/Switch' incorporates:
     *  Gain: '<S143>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_MatrixConcatenate1_tmp = 0.0F;
    } else {
      rtb_MatrixConcatenate1_tmp = rtb_Gain_cu;
    }

    /* End of Switch: '<S143>/Switch' */

    /* Product: '<S140>/Multiply' incorporates:
     *  Constant: '<S140>/kd'
     */
    rtb_Multiply_ga_idx_0 = CONTROL_PARAM.MC_VEL_Z_D *
      rtb_MatrixConcatenate1_tmp;

    /* Saturate: '<S140>/Saturation' */
    if (rtb_Multiply_ga_idx_0 > CONTROL_PARAM.MC_VEL_Z_D_MAX) {
      rtb_Multiply_ga_idx_0 = CONTROL_PARAM.MC_VEL_Z_D_MAX;
    } else {
      if (rtb_Multiply_ga_idx_0 < CONTROL_PARAM.MC_VEL_Z_D_MIN) {
        rtb_Multiply_ga_idx_0 = CONTROL_PARAM.MC_VEL_Z_D_MIN;
      }
    }

    /* End of Saturate: '<S140>/Saturation' */

    /* Sum: '<S137>/Add' incorporates:
     *  Constant: '<S142>/kp'
     *  DiscreteIntegrator: '<S141>/Discrete-Time Integrator'
     *  Product: '<S142>/Multiply'
     */
    rtb_Saturation_ov = (CONTROL_PARAM.MC_VEL_Z_P * rtb_Gain_it +
                         Controller_DW.DiscreteTimeIntegrator_DSTATE_l) +
      rtb_Multiply_ga_idx_0;

    /* Product: '<S135>/Multiply' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S135>/Cos'
     *  Trigonometry: '<S135>/Cos1'
     */
    rtb_Multiply_ga_idx_0 = arm_cos_f32(Controller_U.INS_Out.phi) * arm_cos_f32
      (Controller_U.INS_Out.theta);

    /* Saturate: '<S135>/Saturation1' incorporates:
     *  Product: '<S135>/Multiply'
     */
    if (rtb_Multiply_ga_idx_0 > 1.0F) {
      rtb_Divide_i_idx_2 = 1.0F;
    } else if (rtb_Multiply_ga_idx_0 < 0.5F) {
      rtb_Divide_i_idx_2 = 0.5F;
    } else {
      rtb_Divide_i_idx_2 = rtb_Multiply_ga_idx_0;
    }

    /* End of Saturate: '<S135>/Saturation1' */

    /* Gain: '<S135>/Gain' incorporates:
     *  Product: '<S135>/Multiply'
     */
    rtb_Multiply_ga_idx_0 *= 2.0F;

    /* Saturate: '<S135>/Saturation' */
    if (rtb_Multiply_ga_idx_0 > 1.0F) {
      rtb_Multiply_ga_idx_0 = 1.0F;
    } else {
      if (rtb_Multiply_ga_idx_0 < 0.0F) {
        rtb_Multiply_ga_idx_0 = 0.0F;
      }
    }

    /* End of Saturate: '<S135>/Saturation' */

    /* Product: '<S135>/Multiply1' incorporates:
     *  Constant: '<S135>/Constant'
     *  Product: '<S135>/Divide'
     */
    rtb_Multiply_ga_idx_0 *= 1.0F / rtb_Divide_i_idx_2 * rtb_Saturation_ov;

    /* Outputs for Atomic SubSystem: '<S79>/Quadcopter_x' */
    /* MultiPortSwitch: '<S129>/Multiport Switch' incorporates:
     *  Product: '<S92>/Multiply'
     */
    switch (Controller_U.FMS_Out.status) {
     case 1:
      rtb_MultiportSwitch[0] = 1000U;
      rtb_MultiportSwitch[1] = 1000U;
      rtb_MultiportSwitch[2] = 1000U;
      rtb_MultiportSwitch[3] = 1000U;
      break;

     case 2:
      rtb_MultiportSwitch[0] = 1150U;
      rtb_MultiportSwitch[1] = 1150U;
      rtb_MultiportSwitch[2] = 1150U;
      rtb_MultiportSwitch[3] = 1150U;
      break;

     case 3:
      /* Switch: '<S95>/Switch' incorporates:
       *  Gain: '<S95>/Gain1'
       */
      if (Controller_U.FMS_Out.reset > 0) {
        rtb_Divide_i_idx_1 = 0.0F;
        rtb_Divide_i_idx_2 = 0.0F;
        rtb_Divide_i_idx_3 = 0.0F;
      } else {
        rtb_Divide_i_idx_1 = rtb_DiscreteTimeIntegrator1_k1[0];
        rtb_Divide_i_idx_2 = rtb_DiscreteTimeIntegrator1_k1[1];
        rtb_Divide_i_idx_3 = rtb_DiscreteTimeIntegrator1_k1[2];
      }

      /* End of Switch: '<S95>/Switch' */

      /* Product: '<S92>/Multiply' incorporates:
       *  Constant: '<S92>/gain1'
       */
      rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_ROLL_RATE_D *
        rtb_Divide_i_idx_1;

      /* Saturate: '<S92>/Saturation' */
      if (rtb_DiscreteTimeIntegrator1_g > CONTROL_PARAM.MC_RATE_D_MAX) {
        rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_RATE_D_MAX;
      } else {
        if (rtb_DiscreteTimeIntegrator1_g < CONTROL_PARAM.MC_RATE_D_MIN) {
          rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_RATE_D_MIN;
        }
      }

      rtb_Divide_i_idx_1 = rtb_DiscreteTimeIntegrator1_g;

      /* Product: '<S92>/Multiply' incorporates:
       *  Constant: '<S92>/gain2'
       */
      rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_PITCH_RATE_D *
        rtb_Divide_i_idx_2;

      /* Saturate: '<S92>/Saturation' */
      if (rtb_DiscreteTimeIntegrator1_g > CONTROL_PARAM.MC_RATE_D_MAX) {
        rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_RATE_D_MAX;
      } else {
        if (rtb_DiscreteTimeIntegrator1_g < CONTROL_PARAM.MC_RATE_D_MIN) {
          rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_RATE_D_MIN;
        }
      }

      rtb_Divide_i_idx_2 = rtb_DiscreteTimeIntegrator1_g;

      /* Product: '<S92>/Multiply' incorporates:
       *  Constant: '<S92>/gain3'
       */
      rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_YAW_RATE_D *
        rtb_Divide_i_idx_3;

      /* Saturate: '<S92>/Saturation' */
      if (rtb_DiscreteTimeIntegrator1_g > CONTROL_PARAM.MC_RATE_D_MAX) {
        rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_RATE_D_MAX;
      } else {
        if (rtb_DiscreteTimeIntegrator1_g < CONTROL_PARAM.MC_RATE_D_MIN) {
          rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_RATE_D_MIN;
        }
      }

      /* Switch: '<S128>/Switch' incorporates:
       *  Constant: '<S132>/Constant'
       *  Logic: '<S128>/Logical Operator'
       *  RelationalOperator: '<S131>/Compare'
       *  RelationalOperator: '<S132>/Compare'
       *  Saturate: '<S134>/Saturation'
       *  Switch: '<S128>/Switch1'
       */
      if ((rtb_BitwiseAND_a == 1) || (rtb_BitwiseAND_a == 2) ||
          (rtb_BitwiseAND_a == 3)) {
        rtb_throttle_cmd = Controller_U.FMS_Out.throttle_cmd;
      } else if (rtb_BitwiseAND_a == 6) {
        /* Switch: '<S133>/Switch' incorporates:
         *  Constant: '<S130>/Constant1'
         *  DataTypeConversion: '<S130>/Data Type Conversion'
         *  Gain: '<S130>/Gain1'
         *  S-Function (sfix_bitop): '<S133>/cmd_throttle valid'
         *  Saturate: '<S134>/Saturation'
         *  Sum: '<S130>/Sum1'
         *  Switch: '<S128>/Switch1'
         */
        if ((Controller_U.FMS_Out.cmd_mask & 4096) > 0) {
          rtb_throttle_cmd = Controller_U.FMS_Out.throttle_cmd;
        } else {
          if (rtb_Multiply_ga_idx_0 > 0.35F) {
            /* Saturate: '<S134>/Saturation' */
            rtb_Multiply_ga_idx_0 = 0.35F;
          } else {
            if (rtb_Multiply_ga_idx_0 < -0.35F) {
              /* Saturate: '<S134>/Saturation' */
              rtb_Multiply_ga_idx_0 = -0.35F;
            }
          }

          /* Sum: '<S130>/Sum' incorporates:
           *  Constant: '<S130>/hover_throttle'
           *  Saturate: '<S134>/Saturation'
           */
          u0 = rtb_Multiply_ga_idx_0 + CONTROL_PARAM.MC_HOVER_THRO;

          /* Saturate: '<S130>/Saturation' */
          if (u0 > 1.0F) {
            u0 = 1.0F;
          } else {
            if (u0 < 0.0F) {
              u0 = 0.0F;
            }
          }

          rtb_throttle_cmd = (uint16_T)((uint32_T)fmodf(floorf(1000.0F * u0),
            4.2949673E+9F) + 1000U);
        }

        /* End of Switch: '<S133>/Switch' */
      } else {
        if (rtb_Multiply_ga_idx_0 > 0.35F) {
          /* Saturate: '<S134>/Saturation' */
          rtb_Multiply_ga_idx_0 = 0.35F;
        } else {
          if (rtb_Multiply_ga_idx_0 < -0.35F) {
            /* Saturate: '<S134>/Saturation' */
            rtb_Multiply_ga_idx_0 = -0.35F;
          }
        }

        /* Sum: '<S130>/Sum' incorporates:
         *  Constant: '<S130>/hover_throttle'
         *  Saturate: '<S134>/Saturation'
         */
        u0 = rtb_Multiply_ga_idx_0 + CONTROL_PARAM.MC_HOVER_THRO;

        /* Saturate: '<S130>/Saturation' */
        if (u0 > 1.0F) {
          u0 = 1.0F;
        } else {
          if (u0 < 0.0F) {
            u0 = 0.0F;
          }
        }

        /* Switch: '<S128>/Switch1' incorporates:
         *  Constant: '<S130>/Constant1'
         *  DataTypeConversion: '<S130>/Data Type Conversion'
         *  Gain: '<S130>/Gain1'
         *  Sum: '<S130>/Sum1'
         */
        rtb_throttle_cmd = (uint16_T)((uint32_T)fmodf(floorf(1000.0F * u0),
          4.2949673E+9F) + 1000U);
      }

      /* End of Switch: '<S128>/Switch' */

      /* Saturate: '<S127>/Saturation1' incorporates:
       *  Constant: '<S94>/gain1'
       *  Constant: '<S94>/gain2'
       *  Constant: '<S94>/gain3'
       *  DiscreteIntegrator: '<S91>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S93>/Discrete-Time Integrator'
       *  Product: '<S94>/Multiply'
       *  Sum: '<S89>/Add'
       */
      u0 = (CONTROL_PARAM.MC_ROLL_RATE_P *
            Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] +
            Controller_DW.DiscreteTimeIntegrator_DSTATE[0]) + rtb_Divide_i_idx_1;
      if (u0 > 1.0F) {
        u0 = 1.0F;
      } else {
        if (u0 < -1.0F) {
          u0 = -1.0F;
        }
      }

      rtb_Multiply_ga_idx_0 = (CONTROL_PARAM.MC_PITCH_RATE_P *
        Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] +
        Controller_DW.DiscreteTimeIntegrator_DSTATE[1]) + rtb_Divide_i_idx_2;
      if (rtb_Multiply_ga_idx_0 > 1.0F) {
        rtb_Multiply_ga_idx_0 = 1.0F;
      } else {
        if (rtb_Multiply_ga_idx_0 < -1.0F) {
          rtb_Multiply_ga_idx_0 = -1.0F;
        }
      }

      rtb_Saturation_ov = (CONTROL_PARAM.MC_YAW_RATE_P *
                           Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] +
                           Controller_DW.DiscreteTimeIntegrator_DSTATE[2]) +
        rtb_DiscreteTimeIntegrator1_g;
      if (rtb_Saturation_ov > 1.0F) {
        rtb_Saturation_ov = 1.0F;
      } else {
        if (rtb_Saturation_ov < -1.0F) {
          rtb_Saturation_ov = -1.0F;
        }
      }

      /* End of Saturate: '<S127>/Saturation1' */

      /* Product: '<S127>/Multiply' */
      for (i = 0; i < 4; i++) {
        /* Saturate: '<S127>/Saturation' incorporates:
         *  Constant: '<S127>/Effective_Matrix'
         *  Gain: '<S127>/Gain'
         *  Sum: '<S127>/Add'
         */
        rtb_MatrixConcatenate1_tmp = fmodf(floorf(1000.0F *
          (Controller_ConstP.pooled16[i + 8] * rtb_Saturation_ov +
           (Controller_ConstP.pooled16[i + 4] * rtb_Multiply_ga_idx_0 +
            Controller_ConstP.pooled16[i] * u0)) + (real32_T)rtb_throttle_cmd),
          65536.0F);
        u0_0 = (uint16_T)(rtb_MatrixConcatenate1_tmp < 0.0F ? (int32_T)(uint16_T)
                          -(int16_T)(uint16_T)-rtb_MatrixConcatenate1_tmp :
                          (int32_T)(uint16_T)rtb_MatrixConcatenate1_tmp);
        if (u0_0 > 1900) {
          rtb_MultiportSwitch[i] = 1900U;
        } else if (u0_0 < 1100) {
          rtb_MultiportSwitch[i] = 1100U;
        } else {
          rtb_MultiportSwitch[i] = u0_0;
        }

        /* End of Saturate: '<S127>/Saturation' */
      }

      /* End of Product: '<S127>/Multiply' */
      break;

     default:
      rtb_MultiportSwitch[0] = 1000U;
      rtb_MultiportSwitch[1] = 1000U;
      rtb_MultiportSwitch[2] = 1000U;
      rtb_MultiportSwitch[3] = 1000U;
      break;
    }

    /* End of MultiPortSwitch: '<S129>/Multiport Switch' */

    /* Outport: '<Root>/Control_Out' incorporates:
     *  Constant: '<S129>/Disarm1'
     *  Reshape: '<S129>/Reshape'
     */
    Controller_Y.Control_Out.actuator_cmd[0] = rtb_MultiportSwitch[0];
    Controller_Y.Control_Out.actuator_cmd[1] = rtb_MultiportSwitch[1];
    Controller_Y.Control_Out.actuator_cmd[2] = rtb_MultiportSwitch[2];
    Controller_Y.Control_Out.actuator_cmd[3] = rtb_MultiportSwitch[3];
    for (i = 0; i < 5; i++) {
      Controller_Y.Control_Out.actuator_cmd[i + 4] =
        Controller_ConstP.Disarm1_Value[i];
    }

    for (i = 0; i < 7; i++) {
      Controller_Y.Control_Out.actuator_cmd[i + 9] = 0U;
    }

    /* End of Outputs for SubSystem: '<S79>/Quadcopter_x' */

    /* Product: '<S118>/Multiply1' incorporates:
     *  Constant: '<S118>/const1'
     *  DiscreteIntegrator: '<S115>/Integrator'
     */
    rtb_Saturation_ov = Controller_DW.Integrator_DSTATE[0] * 0.05F;
    rtb_Multiply_ga_idx_0 = Controller_DW.Integrator_DSTATE[1] * 0.05F;

    /* Sum: '<S118>/Add' incorporates:
     *  DiscreteIntegrator: '<S115>/Integrator1'
     *  Sum: '<S115>/Subtract'
     */
    rtb_Gain_ms = (Controller_DW.Integrator1_DSTATE[0] -
                   Controller_U.FMS_Out.u_cmd) + rtb_Saturation_ov;
    rtb_Divide_i_idx_2 = (Controller_DW.Integrator1_DSTATE[1] -
                          Controller_U.FMS_Out.v_cmd) + rtb_Multiply_ga_idx_0;

    /* Signum: '<S118>/Sign' */
    if (rtb_Gain_ms < 0.0F) {
      rtb_Divide_i_idx_1 = -1.0F;
    } else if (rtb_Gain_ms > 0.0F) {
      rtb_Divide_i_idx_1 = 1.0F;
    } else {
      rtb_Divide_i_idx_1 = rtb_Gain_ms;
    }

    /* Sum: '<S118>/Add2' incorporates:
     *  Abs: '<S118>/Abs'
     *  Gain: '<S118>/Gain'
     *  Gain: '<S118>/Gain1'
     *  Product: '<S118>/Multiply2'
     *  Product: '<S118>/Multiply3'
     *  Signum: '<S118>/Sign'
     *  Sqrt: '<S118>/Sqrt'
     *  Sum: '<S118>/Add1'
     *  Sum: '<S118>/Subtract'
     */
    rtb_Divide_i_idx_1 = (sqrtf((8.0F * fabsf(rtb_Gain_ms) + Controller_ConstB.d)
      * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F * rtb_Divide_i_idx_1
      + rtb_Saturation_ov;

    /* Sum: '<S118>/Add3' incorporates:
     *  Signum: '<S118>/Sign'
     */
    rtb_Abs = rtb_Gain_ms + Controller_ConstB.d;

    /* Sum: '<S118>/Subtract1' incorporates:
     *  Signum: '<S118>/Sign'
     */
    rtb_MatrixConcatenate1_tmp = rtb_Gain_ms - Controller_ConstB.d;

    /* Signum: '<S118>/Sign1' */
    if (rtb_Abs < 0.0F) {
      rtb_Abs = -1.0F;
    } else {
      if (rtb_Abs > 0.0F) {
        rtb_Abs = 1.0F;
      }
    }

    /* Signum: '<S118>/Sign2' */
    if (rtb_MatrixConcatenate1_tmp < 0.0F) {
      rtb_MatrixConcatenate1_tmp = -1.0F;
    } else {
      if (rtb_MatrixConcatenate1_tmp > 0.0F) {
        rtb_MatrixConcatenate1_tmp = 1.0F;
      }
    }

    /* Sum: '<S118>/Add2' incorporates:
     *  Gain: '<S118>/Gain2'
     *  Product: '<S118>/Multiply4'
     *  Signum: '<S118>/Sign'
     *  Sum: '<S118>/Add4'
     *  Sum: '<S118>/Add5'
     *  Sum: '<S118>/Subtract2'
     */
    rtb_Gain_ms = ((rtb_Gain_ms - rtb_Divide_i_idx_1) + rtb_Saturation_ov) *
      ((rtb_Abs - rtb_MatrixConcatenate1_tmp) * 0.5F) + rtb_Divide_i_idx_1;

    /* Signum: '<S118>/Sign' */
    if (rtb_Divide_i_idx_2 < 0.0F) {
      rtb_Saturation_ov = -1.0F;
    } else if (rtb_Divide_i_idx_2 > 0.0F) {
      rtb_Saturation_ov = 1.0F;
    } else {
      rtb_Saturation_ov = rtb_Divide_i_idx_2;
    }

    /* Sum: '<S118>/Add2' incorporates:
     *  Abs: '<S118>/Abs'
     *  Gain: '<S118>/Gain'
     *  Gain: '<S118>/Gain1'
     *  Product: '<S118>/Multiply2'
     *  Product: '<S118>/Multiply3'
     *  Signum: '<S118>/Sign'
     *  Sqrt: '<S118>/Sqrt'
     *  Sum: '<S118>/Add1'
     *  Sum: '<S118>/Subtract'
     */
    rtb_Divide_i_idx_1 = (sqrtf((8.0F * fabsf(rtb_Divide_i_idx_2) +
      Controller_ConstB.d) * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
      rtb_Saturation_ov + rtb_Multiply_ga_idx_0;

    /* Sum: '<S118>/Add3' incorporates:
     *  Signum: '<S118>/Sign'
     */
    rtb_Abs = rtb_Divide_i_idx_2 + Controller_ConstB.d;

    /* Sum: '<S118>/Subtract1' incorporates:
     *  Signum: '<S118>/Sign'
     */
    rtb_MatrixConcatenate1_tmp = rtb_Divide_i_idx_2 - Controller_ConstB.d;

    /* Signum: '<S118>/Sign1' */
    if (rtb_Abs < 0.0F) {
      rtb_Abs = -1.0F;
    } else {
      if (rtb_Abs > 0.0F) {
        rtb_Abs = 1.0F;
      }
    }

    /* Signum: '<S118>/Sign2' */
    if (rtb_MatrixConcatenate1_tmp < 0.0F) {
      rtb_MatrixConcatenate1_tmp = -1.0F;
    } else {
      if (rtb_MatrixConcatenate1_tmp > 0.0F) {
        rtb_MatrixConcatenate1_tmp = 1.0F;
      }
    }

    /* Sum: '<S118>/Add5' incorporates:
     *  Gain: '<S118>/Gain2'
     *  Product: '<S118>/Multiply4'
     *  Signum: '<S118>/Sign'
     *  Sum: '<S118>/Add2'
     *  Sum: '<S118>/Add4'
     *  Sum: '<S118>/Subtract2'
     */
    rtb_Divide_i_idx_1 += ((rtb_Divide_i_idx_2 - rtb_Divide_i_idx_1) +
      rtb_Multiply_ga_idx_0) * ((rtb_Abs - rtb_MatrixConcatenate1_tmp) * 0.5F);

    /* Product: '<S139>/Multiply1' incorporates:
     *  Constant: '<S139>/const1'
     *  DiscreteIntegrator: '<S138>/Integrator'
     */
    rtb_Divide_i_idx_2 = Controller_DW.Integrator_DSTATE_j * 0.05F;

    /* Sum: '<S139>/Add' incorporates:
     *  DiscreteIntegrator: '<S138>/Integrator1'
     *  Sum: '<S138>/Subtract'
     */
    rtb_Multiply_ga_idx_0 = (Controller_DW.Integrator1_DSTATE_e -
      Controller_U.FMS_Out.w_cmd) + rtb_Divide_i_idx_2;

    /* Signum: '<S139>/Sign' */
    if (rtb_Multiply_ga_idx_0 < 0.0F) {
      rtb_Saturation_ov = -1.0F;
    } else if (rtb_Multiply_ga_idx_0 > 0.0F) {
      rtb_Saturation_ov = 1.0F;
    } else {
      rtb_Saturation_ov = rtb_Multiply_ga_idx_0;
    }

    /* End of Signum: '<S139>/Sign' */

    /* Sum: '<S139>/Add2' incorporates:
     *  Abs: '<S139>/Abs'
     *  Gain: '<S139>/Gain'
     *  Gain: '<S139>/Gain1'
     *  Product: '<S139>/Multiply2'
     *  Product: '<S139>/Multiply3'
     *  Sqrt: '<S139>/Sqrt'
     *  Sum: '<S139>/Add1'
     *  Sum: '<S139>/Subtract'
     */
    rtb_Saturation_ov = (sqrtf((8.0F * fabsf(rtb_Multiply_ga_idx_0) +
      Controller_ConstB.d_i) * Controller_ConstB.d_i) - Controller_ConstB.d_i) *
      0.5F * rtb_Saturation_ov + rtb_Divide_i_idx_2;

    /* Sum: '<S139>/Add4' */
    rtb_Divide_i_idx_2 += rtb_Multiply_ga_idx_0 - rtb_Saturation_ov;

    /* Sum: '<S139>/Add3' */
    rtb_Abs = rtb_Multiply_ga_idx_0 + Controller_ConstB.d_i;

    /* Sum: '<S139>/Subtract1' */
    rtb_Multiply_ga_idx_0 -= Controller_ConstB.d_i;

    /* Signum: '<S139>/Sign1' */
    if (rtb_Abs < 0.0F) {
      rtb_Abs = -1.0F;
    } else {
      if (rtb_Abs > 0.0F) {
        rtb_Abs = 1.0F;
      }
    }

    /* End of Signum: '<S139>/Sign1' */

    /* Signum: '<S139>/Sign2' */
    if (rtb_Multiply_ga_idx_0 < 0.0F) {
      rtb_Multiply_ga_idx_0 = -1.0F;
    } else {
      if (rtb_Multiply_ga_idx_0 > 0.0F) {
        rtb_Multiply_ga_idx_0 = 1.0F;
      }
    }

    /* End of Signum: '<S139>/Sign2' */

    /* Sum: '<S139>/Add5' incorporates:
     *  Gain: '<S139>/Gain2'
     *  Product: '<S139>/Multiply4'
     *  Sum: '<S139>/Subtract2'
     */
    rtb_Saturation_ov += (rtb_Abs - rtb_Multiply_ga_idx_0) * 0.5F *
      rtb_Divide_i_idx_2;

    /* Update for DiscreteIntegrator: '<S93>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S93>/gain1'
     *  Constant: '<S93>/gain2'
     *  Constant: '<S93>/gain3'
     *  DiscreteIntegrator: '<S91>/Discrete-Time Integrator5'
     *  Product: '<S93>/Multiply'
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

    /* End of Update for DiscreteIntegrator: '<S93>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S120>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_PrevRe_p = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S122>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;

    /* Update for DiscreteIntegrator: '<S115>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S115>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE[0] += 0.002F *
      Controller_DW.Integrator_DSTATE[0];

    /* Update for DiscreteIntegrator: '<S120>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S120>/ki'
     *  Product: '<S120>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0] +=
      CONTROL_PARAM.MC_VEL_XY_I * rtb_Divide_i_idx_0 * 0.002F;
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

    /* Update for DiscreteIntegrator: '<S122>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] += 0.002F *
      rtb_Saturation1_h_idx_0;

    /* Update for DiscreteIntegrator: '<S115>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S115>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE[1] += 0.002F *
      Controller_DW.Integrator_DSTATE[1];

    /* Update for DiscreteIntegrator: '<S120>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S120>/ki'
     *  Product: '<S120>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1] +=
      CONTROL_PARAM.MC_VEL_XY_I * rtb_Cos_j * 0.002F;
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

    /* Update for DiscreteIntegrator: '<S122>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] += 0.002F * rtb_Divide_gn;
    Controller_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S91>/Discrete-Time Integrator5' */
    Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;

    /* Update for DiscreteIntegrator: '<S95>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 0U;

    /* Update for DiscreteIntegrator: '<S91>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S91>/Gain'
     *  Sum: '<S91>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] += (rtb_Add_c -
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S95>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[0] += 0.002F *
      rtb_DiscreteTimeIntegrator1_k1[0];

    /* Update for DiscreteIntegrator: '<S91>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S91>/Gain'
     *  Sum: '<S91>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] += (rtb_FF_limit_idx_1 -
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S95>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[1] += 0.002F *
      rtb_DiscreteTimeIntegrator1_k1[1];

    /* Update for DiscreteIntegrator: '<S91>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S91>/Gain'
     *  Sum: '<S91>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] += (rtb_FF_limit_idx_2 -
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S95>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[2] += 0.002F *
      rtb_DiscreteTimeIntegrator1_k1[2];
    Controller_DW.DiscreteTimeIntegrator1_PrevR_k = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S138>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S138>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_e += 0.002F *
      Controller_DW.Integrator_DSTATE_j;

    /* Update for DiscreteIntegrator: '<S141>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S141>/ki'
     *  Product: '<S141>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_l += CONTROL_PARAM.MC_VEL_Z_I *
      rtb_Gain_it * 0.002F;
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

    /* End of Update for DiscreteIntegrator: '<S141>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S143>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_i += 0.002F * rtb_Gain_cu;
    Controller_DW.DiscreteTimeIntegrator1_Prev_ks = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Signum: '<S118>/Sign3' incorporates:
     *  Product: '<S118>/Divide'
     *  Sum: '<S118>/Add6'
     */
    rtb_Abs = rtb_Gain_ms + Controller_ConstB.d;

    /* Signum: '<S118>/Sign4' incorporates:
     *  Product: '<S118>/Divide'
     *  Sum: '<S118>/Subtract3'
     */
    rtb_Add_c = rtb_Gain_ms - Controller_ConstB.d;

    /* Signum: '<S118>/Sign5' incorporates:
     *  Product: '<S118>/Divide'
     */
    if (rtb_Gain_ms < 0.0F) {
      rtb_FF_limit_idx_1 = -1.0F;
    } else if (rtb_Gain_ms > 0.0F) {
      rtb_FF_limit_idx_1 = 1.0F;
    } else {
      rtb_FF_limit_idx_1 = rtb_Gain_ms;
    }

    /* Signum: '<S118>/Sign3' */
    if (rtb_Abs < 0.0F) {
      rtb_Abs = -1.0F;
    } else {
      if (rtb_Abs > 0.0F) {
        rtb_Abs = 1.0F;
      }
    }

    /* Signum: '<S118>/Sign4' */
    if (rtb_Add_c < 0.0F) {
      rtb_Add_c = -1.0F;
    } else {
      if (rtb_Add_c > 0.0F) {
        rtb_Add_c = 1.0F;
      }
    }

    /* Signum: '<S118>/Sign6' incorporates:
     *  Product: '<S118>/Divide'
     */
    if (rtb_Gain_ms < 0.0F) {
      rtb_FF_limit_idx_2 = -1.0F;
    } else if (rtb_Gain_ms > 0.0F) {
      rtb_FF_limit_idx_2 = 1.0F;
    } else {
      rtb_FF_limit_idx_2 = rtb_Gain_ms;
    }

    /* Update for DiscreteIntegrator: '<S115>/Integrator' incorporates:
     *  Constant: '<S118>/const'
     *  Gain: '<S118>/Gain3'
     *  Product: '<S118>/Divide'
     *  Product: '<S118>/Multiply5'
     *  Product: '<S118>/Multiply6'
     *  Sum: '<S118>/Subtract4'
     *  Sum: '<S118>/Subtract5'
     *  Sum: '<S118>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE[0] += ((rtb_Gain_ms / Controller_ConstB.d -
      rtb_FF_limit_idx_1) * Controller_ConstB.Gain4 * ((rtb_Abs - rtb_Add_c) *
      0.5F) - rtb_FF_limit_idx_2 * 58.836F) * 0.002F;

    /* Signum: '<S118>/Sign3' incorporates:
     *  Sum: '<S118>/Add6'
     */
    rtb_Abs = rtb_Divide_i_idx_1 + Controller_ConstB.d;

    /* Signum: '<S118>/Sign4' incorporates:
     *  Sum: '<S118>/Subtract3'
     */
    rtb_Add_c = rtb_Divide_i_idx_1 - Controller_ConstB.d;

    /* Signum: '<S118>/Sign5' */
    if (rtb_Divide_i_idx_1 < 0.0F) {
      rtb_FF_limit_idx_1 = -1.0F;
    } else if (rtb_Divide_i_idx_1 > 0.0F) {
      rtb_FF_limit_idx_1 = 1.0F;
    } else {
      rtb_FF_limit_idx_1 = rtb_Divide_i_idx_1;
    }

    /* Signum: '<S118>/Sign3' */
    if (rtb_Abs < 0.0F) {
      rtb_Abs = -1.0F;
    } else {
      if (rtb_Abs > 0.0F) {
        rtb_Abs = 1.0F;
      }
    }

    /* Signum: '<S118>/Sign4' */
    if (rtb_Add_c < 0.0F) {
      rtb_Add_c = -1.0F;
    } else {
      if (rtb_Add_c > 0.0F) {
        rtb_Add_c = 1.0F;
      }
    }

    /* Signum: '<S118>/Sign6' */
    if (rtb_Divide_i_idx_1 < 0.0F) {
      rtb_FF_limit_idx_2 = -1.0F;
    } else if (rtb_Divide_i_idx_1 > 0.0F) {
      rtb_FF_limit_idx_2 = 1.0F;
    } else {
      rtb_FF_limit_idx_2 = rtb_Divide_i_idx_1;
    }

    /* Update for DiscreteIntegrator: '<S115>/Integrator' incorporates:
     *  Constant: '<S118>/const'
     *  Gain: '<S118>/Gain3'
     *  Product: '<S118>/Divide'
     *  Product: '<S118>/Multiply5'
     *  Product: '<S118>/Multiply6'
     *  Sum: '<S118>/Subtract4'
     *  Sum: '<S118>/Subtract5'
     *  Sum: '<S118>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE[1] += ((rtb_Divide_i_idx_1 /
      Controller_ConstB.d - rtb_FF_limit_idx_1) * Controller_ConstB.Gain4 *
      ((rtb_Abs - rtb_Add_c) * 0.5F) - rtb_FF_limit_idx_2 * 58.836F) * 0.002F;

    /* Signum: '<S139>/Sign6' incorporates:
     *  Signum: '<S139>/Sign5'
     */
    if (rtb_Saturation_ov < 0.0F) {
      rtb_FF_limit_idx_1 = -1.0F;

      /* Signum: '<S139>/Sign5' */
      rtb_FF_limit_idx_2 = -1.0F;
    } else if (rtb_Saturation_ov > 0.0F) {
      rtb_FF_limit_idx_1 = 1.0F;

      /* Signum: '<S139>/Sign5' */
      rtb_FF_limit_idx_2 = 1.0F;
    } else {
      rtb_FF_limit_idx_1 = rtb_Saturation_ov;

      /* Signum: '<S139>/Sign5' */
      rtb_FF_limit_idx_2 = rtb_Saturation_ov;
    }

    /* End of Signum: '<S139>/Sign6' */

    /* Sum: '<S139>/Add6' */
    rtb_Abs = rtb_Saturation_ov + Controller_ConstB.d_i;

    /* Sum: '<S139>/Subtract3' */
    rtb_Add_c = rtb_Saturation_ov - Controller_ConstB.d_i;

    /* Signum: '<S139>/Sign3' */
    if (rtb_Abs < 0.0F) {
      rtb_Abs = -1.0F;
    } else {
      if (rtb_Abs > 0.0F) {
        rtb_Abs = 1.0F;
      }
    }

    /* End of Signum: '<S139>/Sign3' */

    /* Signum: '<S139>/Sign4' */
    if (rtb_Add_c < 0.0F) {
      rtb_Add_c = -1.0F;
    } else {
      if (rtb_Add_c > 0.0F) {
        rtb_Add_c = 1.0F;
      }
    }

    /* End of Signum: '<S139>/Sign4' */

    /* Update for DiscreteIntegrator: '<S138>/Integrator' incorporates:
     *  Constant: '<S139>/const'
     *  Gain: '<S139>/Gain3'
     *  Product: '<S139>/Divide'
     *  Product: '<S139>/Multiply5'
     *  Product: '<S139>/Multiply6'
     *  Sum: '<S139>/Subtract4'
     *  Sum: '<S139>/Subtract5'
     *  Sum: '<S139>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE_j += ((rtb_Saturation_ov /
      Controller_ConstB.d_i - rtb_FF_limit_idx_2) * Controller_ConstB.Gain4_p *
      ((rtb_Abs - rtb_Add_c) * 0.5F) - rtb_FF_limit_idx_1 * 78.448F) * 0.002F;

    /* End of Outputs for SubSystem: '<S2>/MC_Controller' */
    break;
  }

  /* End of SwitchCase: '<S8>/Switch Case1' */

  /* Outport: '<Root>/Control_Out' incorporates:
   *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
   */
  Controller_Y.Control_Out.timestamp =
    Controller_DW.DiscreteTimeIntegrator_DSTATE_n;

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

  /* Start for IfAction SubSystem: '<S2>/VTOL_Controller' */
  /* Start for Constant: '<S186>/Constant' */
  Controller_B.Constant_m = CONTROL_PARAM.MC_VEL_Z_I_MIN;

  /* End of Start for SubSystem: '<S2>/VTOL_Controller' */

  /* Start for IfAction SubSystem: '<S2>/BackTrans_Controller' */
  /* Start for Constant: '<S57>/Constant' */
  Controller_B.Constant_i = CONTROL_PARAM.MC_VEL_Z_I_MIN;

  /* End of Start for SubSystem: '<S2>/BackTrans_Controller' */

  /* Start for IfAction SubSystem: '<S2>/MC_Controller' */
  /* Start for Constant: '<S141>/Constant' */
  Controller_B.Constant = CONTROL_PARAM.MC_VEL_Z_I_MIN;

  /* End of Start for SubSystem: '<S2>/MC_Controller' */

  /* SystemInitialize for IfAction SubSystem: '<S2>/VTOL_Controller' */
  /* InitializeConditions for DiscreteIntegrator: '<S191>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_L_eo = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S190>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_o = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S183>/Integrator1' */
  Controller_DW.Integrator1_DSTATE_i = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S186>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S186>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S188>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_i = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_h = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S226>/ ' */
  Controller_DW._DSTATE = Controller_ConstB.Zero1;
  if (Controller_DW._DSTATE >= CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
    Controller_DW._DSTATE = CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
  } else {
    if (Controller_DW._DSTATE <= -CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
      Controller_DW._DSTATE = -CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
    }
  }

  Controller_DW._PrevResetState = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S226>/ ' */

  /* InitializeConditions for DiscreteIntegrator: '<S227>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_f = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_b = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S159>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_b = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S161>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_PrevRe_o = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S163>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_L_h2 = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_l = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S189>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_g = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S161>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S201>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S161>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S201>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S161>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S201>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S229>/ ' */
  Controller_DW._DSTATE_d = Controller_ConstB.Zero;
  if (Controller_DW._DSTATE_d >= 0.3F) {
    Controller_DW._DSTATE_d = 0.3F;
  } else {
    if (Controller_DW._DSTATE_d <= -0.3F) {
      Controller_DW._DSTATE_d = -0.3F;
    }
  }

  Controller_DW._PrevResetState_e = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S229>/ ' */

  /* InitializeConditions for DiscreteIntegrator: '<S230>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_L_h0 = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_d = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S183>/Integrator' */
  Controller_DW.Integrator_DSTATE_f = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S2>/VTOL_Controller' */

  /* SystemInitialize for IfAction SubSystem: '<S2>/BackTrans_Controller' */
  /* InitializeConditions for DiscreteIntegrator: '<S42>/Integrator1' */
  Controller_DW.Integrator1_DSTATE_h[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S47>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[0] =
    Controller_ConstB.Constant_e4;
  if (Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[0] >=
      CONTROL_PARAM.MC_VEL_XY_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[0] =
      CONTROL_PARAM.MC_VEL_XY_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[0] <=
        CONTROL_PARAM.MC_VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[0] =
        CONTROL_PARAM.MC_VEL_XY_I_MIN;
    }
  }

  /* InitializeConditions for DiscreteIntegrator: '<S42>/Integrator1' */
  Controller_DW.Integrator1_DSTATE_h[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S47>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[1] =
    Controller_ConstB.Constant_e4;
  if (Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[1] >=
      CONTROL_PARAM.MC_VEL_XY_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[1] =
      CONTROL_PARAM.MC_VEL_XY_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[1] <=
        CONTROL_PARAM.MC_VEL_XY_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[1] =
        CONTROL_PARAM.MC_VEL_XY_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRe_a = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S49>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_h = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_p = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S23>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_e = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_g[0] =
    Controller_ConstB.Constant_a[0];
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_g[0] >=
      CONTROL_PARAM.MC_RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_g[0] =
      CONTROL_PARAM.MC_RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_g[0] <=
        CONTROL_PARAM.MC_RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_g[0] =
        CONTROL_PARAM.MC_RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_DSTATE_g[1] =
    Controller_ConstB.Constant_a[1];
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_g[1] >=
      CONTROL_PARAM.MC_RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_g[1] =
      CONTROL_PARAM.MC_RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_g[1] <=
        CONTROL_PARAM.MC_RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_g[1] =
        CONTROL_PARAM.MC_RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_DSTATE_g[2] =
    Controller_ConstB.Constant_a[2];
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_g[2] >=
      CONTROL_PARAM.MC_RATE_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_g[2] =
      CONTROL_PARAM.MC_RATE_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_g[2] <=
        CONTROL_PARAM.MC_RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_g[2] =
        CONTROL_PARAM.MC_RATE_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevR_ps = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S27>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_p = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_c = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S54>/Integrator1' */
  Controller_DW.Integrator1_DSTATE_o = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S57>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_p = Controller_B.Constant_i;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE_p >=
      CONTROL_PARAM.MC_VEL_Z_I_MAX) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE_p = CONTROL_PARAM.MC_VEL_Z_I_MAX;
  } else {
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE_p <=
        CONTROL_PARAM.MC_VEL_Z_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE_p =
        CONTROL_PARAM.MC_VEL_Z_I_MIN;
    }
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRe_c = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S57>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S59>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_b = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_a = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S42>/Integrator' */
  Controller_DW.Integrator_DSTATE_jg[0] = 0.0F;
  Controller_DW.Integrator_DSTATE_jg[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S54>/Integrator' */
  Controller_DW.Integrator_DSTATE_e = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S2>/BackTrans_Controller' */

  /* SystemInitialize for IfAction SubSystem: '<S2>/MC_Controller' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S115>/Integrator1' */
  Controller_DW.Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S120>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S115>/Integrator1' */
  Controller_DW.Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S120>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S122>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S91>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S95>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_k = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S138>/Integrator1' */
  Controller_DW.Integrator1_DSTATE_e = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S141>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S141>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S143>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 1U;
  Controller_DW.DiscreteTimeIntegrator1_Prev_ks = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S115>/Integrator' */
  Controller_DW.Integrator_DSTATE[0] = 0.0F;
  Controller_DW.Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S138>/Integrator' */
  Controller_DW.Integrator_DSTATE_j = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S2>/MC_Controller' */
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
