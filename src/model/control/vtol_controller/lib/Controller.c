/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.207
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Aug 19 14:49:22 2024
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
struct_DYyzgxJdfX95CMtHDL7qw CONTROL_PARAM = {
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
  0.1F
} ;                                    /* Variable: CONTROL_PARAM
                                        * Referenced by:
                                        *   '<S9>/mc_hover_throttle'
                                        *   '<S148>/mc_hover_throttle'
                                        *   '<S191>/Saturation'
                                        *   '<S192>/Gain'
                                        *   '<S192>/Gain1'
                                        *   '<S192>/balabnce_ratio2'
                                        *   '<S192>/balance_ratio'
                                        *   '<S192>/pitch_ff'
                                        *   '<S192>/thorttle_ff'
                                        *   '<S192>/ucmd2pitch'
                                        *   '<S192>/ucmd2thor'
                                        *   '<S192>/wcmd2pitch'
                                        *   '<S192>/wcmd2thor'
                                        *   '<S108>/Saturation'
                                        *   '<S128>/hover_throttle'
                                        *   '<S193>/FF'
                                        *   '<S193>/FF_limit'
                                        *   '<S193>/PI_limit'
                                        *   '<S212>/P_control'
                                        *   '<S213>/P_control'
                                        *   '<S38>/Saturation'
                                        *   '<S84>/Saturation'
                                        *   '<S84>/Saturation1'
                                        *   '<S117>/kd'
                                        *   '<S117>/Saturation'
                                        *   '<S118>/ki'
                                        *   '<S118>/Discrete-Time Integrator'
                                        *   '<S119>/kp'
                                        *   '<S138>/kd'
                                        *   '<S138>/Saturation'
                                        *   '<S139>/Constant'
                                        *   '<S139>/ki'
                                        *   '<S139>/Discrete-Time Integrator'
                                        *   '<S140>/kp'
                                        *   '<S153>/Saturation'
                                        *   '<S153>/Saturation1'
                                        *   '<S197>/trim_speed'
                                        *   '<S198>/trim_speed'
                                        *   '<S223>/Gain'
                                        *   '<S224>/ '
                                        *   '<S224>/Gain3'
                                        *   '<S226>/Gain'
                                        *   '<S227>/Gain'
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
                                        *   '<S101>/Constant1'
                                        *   '<S101>/Constant2'
                                        *   '<S165>/Constant1'
                                        *   '<S165>/Constant2'
                                        *   '<S183>/kd'
                                        *   '<S183>/Saturation'
                                        *   '<S184>/Constant'
                                        *   '<S184>/ki'
                                        *   '<S184>/Discrete-Time Integrator'
                                        *   '<S185>/kp'
                                        *   '<S199>/gain1'
                                        *   '<S199>/gain2'
                                        *   '<S199>/gain3'
                                        *   '<S199>/Discrete-Time Integrator'
                                        *   '<S200>/gain1'
                                        *   '<S200>/gain2'
                                        *   '<S200>/gain3'
                                        *   '<S204>/Pitch Offset'
                                        *   '<S204>/Saturation'
                                        *   '<S205>/Constant1'
                                        *   '<S205>/Constant2'
                                        *   '<S244>/Constant1'
                                        *   '<S244>/Constant12'
                                        *   '<S244>/Constant2'
                                        *   '<S244>/Constant7'
                                        *   '<S252>/Constant1'
                                        *   '<S252>/Constant11'
                                        *   '<S252>/Constant12'
                                        *   '<S252>/Constant2'
                                        *   '<S252>/Constant7'
                                        *   '<S252>/Constant8'
                                        *   '<S33>/Constant1'
                                        *   '<S33>/Constant2'
                                        *   '<S90>/gain1'
                                        *   '<S90>/gain2'
                                        *   '<S90>/gain3'
                                        *   '<S90>/Saturation'
                                        *   '<S91>/gain1'
                                        *   '<S91>/gain2'
                                        *   '<S91>/gain3'
                                        *   '<S91>/Discrete-Time Integrator'
                                        *   '<S92>/gain1'
                                        *   '<S92>/gain2'
                                        *   '<S92>/gain3'
                                        *   '<S158>/gain1'
                                        *   '<S158>/gain2'
                                        *   '<S158>/gain3'
                                        *   '<S158>/Saturation'
                                        *   '<S159>/gain1'
                                        *   '<S159>/gain2'
                                        *   '<S159>/gain3'
                                        *   '<S159>/Discrete-Time Integrator'
                                        *   '<S160>/gain1'
                                        *   '<S160>/gain2'
                                        *   '<S160>/gain3'
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
   *  Constant: '<S139>/Constant'
   *  Constant: '<S184>/Constant'
   *  Constant: '<S57>/Constant'
   *  DataTypeConversion: '<S8>/Data Type Conversion'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S103>/Divide1'
   *  Product: '<S117>/Multiply'
   *  Product: '<S158>/Multiply'
   *  Product: '<S167>/Divide1'
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
       *  DiscreteIntegrator: '<S157>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S159>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S161>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S181>/Integrator'
       *  DiscreteIntegrator: '<S181>/Integrator1'
       *  DiscreteIntegrator: '<S184>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S186>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S187>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S188>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S189>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S199>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S224>/ '
       *  DiscreteIntegrator: '<S225>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S227>/ '
       *  DiscreteIntegrator: '<S228>/Discrete-Time Integrator1'
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
    /* Product: '<S143>/Divide' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Math: '<S143>/Square'
     */
    rtb_Divide_gn = Controller_U.INS_Out.airspeed *
      Controller_U.INS_Out.airspeed / Controller_ConstB.Square1;

    /* DiscreteIntegrator: '<S189>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_L_eo != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_a = rtb_Divide_gn;
    }

    /* Saturate: '<S143>/Saturation' */
    if (Controller_DW.DiscreteTimeIntegrator5_DSTAT_a > 1.0F) {
      rtb_Saturation_ov = 1.0F;
    } else if (Controller_DW.DiscreteTimeIntegrator5_DSTAT_a < 0.0F) {
      rtb_Saturation_ov = 0.0F;
    } else {
      rtb_Saturation_ov = Controller_DW.DiscreteTimeIntegrator5_DSTAT_a;
    }

    /* End of Saturate: '<S143>/Saturation' */

    /* Relay: '<S143>/Relay' */
    if (rtb_Saturation_ov >= 0.95F) {
      Controller_DW.Relay_Mode = true;
    } else {
      if (rtb_Saturation_ov <= 0.85F) {
        Controller_DW.Relay_Mode = false;
      }
    }

    rtb_Relay = !Controller_DW.Relay_Mode;

    /* End of Relay: '<S143>/Relay' */

    /* DiscreteIntegrator: '<S188>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_o != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTA_a2 = (real32_T)rtb_Relay;
    }

    /* Gain: '<S179>/Gain' incorporates:
     *  DiscreteIntegrator: '<S181>/Integrator1'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S179>/Sum1'
     */
    rtb_Gain_ms = -(Controller_DW.Integrator1_DSTATE_i - Controller_U.INS_Out.vd);

    /* Logic: '<S176>/Logical Operator' incorporates:
     *  Constant: '<S178>/Constant'
     *  DiscreteIntegrator: '<S188>/Discrete-Time Integrator5'
     *  RelationalOperator: '<S178>/Compare'
     */
    rtb_LogicalOperator_b3 = ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator5_DSTA_a2 == 0.0F));
    Controller_B.Constant_m = CONTROL_PARAM.MC_VEL_Z_I_MIN;

    /* DiscreteIntegrator: '<S184>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S184>/Constant'
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

    /* DiscreteIntegrator: '<S186>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_i != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTA_ld = rtb_Gain_ms;
    }

    if (rtb_LogicalOperator_b3 || (Controller_DW.DiscreteTimeIntegrator1_PrevR_h
         != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTA_ld = rtb_Gain_ms;
    }

    /* Gain: '<S186>/Gain' incorporates:
     *  DiscreteIntegrator: '<S186>/Discrete-Time Integrator1'
     *  Sum: '<S186>/Sum5'
     */
    rtb_Gain_it = (rtb_Gain_ms - Controller_DW.DiscreteTimeIntegrator1_DSTA_ld) *
      62.831852F;

    /* Switch: '<S186>/Switch' incorporates:
     *  Gain: '<S186>/Gain1'
     */
    if (rtb_LogicalOperator_b3) {
      rtb_Add_c = 0.0F;
    } else {
      rtb_Add_c = rtb_Gain_it;
    }

    /* End of Switch: '<S186>/Switch' */

    /* Product: '<S183>/Multiply' incorporates:
     *  Constant: '<S183>/kd'
     */
    rtb_Cos_j = CONTROL_PARAM.MC_VEL_Z_D * rtb_Add_c;

    /* Saturate: '<S183>/Saturation' */
    if (rtb_Cos_j > CONTROL_PARAM.MC_VEL_Z_D_MAX) {
      rtb_Cos_j = CONTROL_PARAM.MC_VEL_Z_D_MAX;
    } else {
      if (rtb_Cos_j < CONTROL_PARAM.MC_VEL_Z_D_MIN) {
        rtb_Cos_j = CONTROL_PARAM.MC_VEL_Z_D_MIN;
      }
    }

    /* End of Saturate: '<S183>/Saturation' */

    /* Sum: '<S180>/Add' incorporates:
     *  Constant: '<S185>/kp'
     *  DiscreteIntegrator: '<S184>/Discrete-Time Integrator'
     *  Product: '<S185>/Multiply'
     */
    rtb_Add_c = (CONTROL_PARAM.MC_VEL_Z_P * rtb_Gain_ms +
                 Controller_DW.DiscreteTimeIntegrator_DSTATE_b) + rtb_Cos_j;

    /* Trigonometry: '<S177>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S162>/Cos1'
     *  Trigonometry: '<S195>/Cos1'
     */
    rtb_Gain_cu = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Trigonometry: '<S177>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S162>/Cos'
     *  Trigonometry: '<S195>/Cos'
     */
    rtb_Multiply_ga_idx_0 = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Product: '<S177>/Multiply' incorporates:
     *  Trigonometry: '<S177>/Cos'
     *  Trigonometry: '<S177>/Cos1'
     */
    rtb_FF_limit_idx_1 = rtb_Multiply_ga_idx_0 * rtb_Gain_cu;

    /* Saturate: '<S177>/Saturation1' incorporates:
     *  Product: '<S177>/Multiply'
     */
    if (rtb_FF_limit_idx_1 > 1.0F) {
      rtb_Cos1_d = 1.0F;
    } else if (rtb_FF_limit_idx_1 < 0.5F) {
      rtb_Cos1_d = 0.5F;
    } else {
      rtb_Cos1_d = rtb_FF_limit_idx_1;
    }

    /* End of Saturate: '<S177>/Saturation1' */

    /* Gain: '<S177>/Gain' incorporates:
     *  Product: '<S177>/Multiply'
     */
    rtb_Cos_j = 2.0F * rtb_FF_limit_idx_1;

    /* Saturate: '<S177>/Saturation' */
    if (rtb_Cos_j > 1.0F) {
      rtb_Cos_j = 1.0F;
    } else {
      if (rtb_Cos_j < 0.0F) {
        rtb_Cos_j = 0.0F;
      }
    }

    /* End of Saturate: '<S177>/Saturation' */

    /* Product: '<S177>/Multiply1' incorporates:
     *  Constant: '<S177>/Constant'
     *  Product: '<S177>/Divide'
     */
    rtb_Cos_j *= 1.0F / rtb_Cos1_d * rtb_Add_c;

    /* Saturate: '<S176>/Saturation' */
    if (rtb_Cos_j > 0.35F) {
      rtb_Cos_j = 0.35F;
    } else {
      if (rtb_Cos_j < -0.35F) {
        rtb_Cos_j = -0.35F;
      }
    }

    /* End of Saturate: '<S176>/Saturation' */

    /* Sum: '<S148>/Sum' incorporates:
     *  Constant: '<S148>/mc_hover_throttle'
     */
    rtb_Cos_j += CONTROL_PARAM.MC_HOVER_THRO;

    /* Saturate: '<S148>/Saturation' */
    if (rtb_Cos_j > 1.0F) {
      rtb_Cos_j = 1.0F;
    } else {
      if (rtb_Cos_j < -1.0F) {
        rtb_Cos_j = -1.0F;
      }
    }

    /* End of Saturate: '<S148>/Saturation' */

    /* Saturate: '<S142>/Saturation1' incorporates:
     *  Constant: '<S148>/Constant'
     *  Product: '<S142>/Multiply1'
     */
    rtb_Saturation1[0] = 0.0F;
    rtb_Saturation1[1] = 0.0F;

    /* Product: '<S142>/Multiply1' incorporates:
     *  DiscreteIntegrator: '<S188>/Discrete-Time Integrator5'
     */
    u0 = rtb_Cos_j * Controller_DW.DiscreteTimeIntegrator5_DSTA_a2;

    /* Saturate: '<S142>/Saturation1' */
    if (u0 > 1.0F) {
      rtb_Saturation1[2] = 1.0F;
    } else if (u0 < -1.0F) {
      rtb_Saturation1[2] = -1.0F;
    } else {
      rtb_Saturation1[2] = u0;
    }

    /* Trigonometry: '<S191>/Atan' incorporates:
     *  Gain: '<S191>/g_force'
     *  Sum: '<S191>/Minus'
     */
    rtb_Cos1_d = atanf(0.101936802F * Controller_U.FMS_Out.ay_cmd);

    /* Saturate: '<S191>/Saturation' */
    if (rtb_Cos1_d > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Cos1_d = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_Cos1_d < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_Cos1_d = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      }
    }

    /* End of Saturate: '<S191>/Saturation' */

    /* Switch: '<S211>/Switch' incorporates:
     *  Constant: '<S222>/Constant'
     *  RelationalOperator: '<S222>/Compare'
     */
    if (rtb_BitwiseAND_a == 4) {
      rtb_MatrixConcatenate1_tmp = Controller_U.FMS_Out.phi_cmd;
    } else {
      rtb_MatrixConcatenate1_tmp = rtb_Cos1_d;
    }

    /* End of Switch: '<S211>/Switch' */

    /* Abs: '<S192>/Abs' */
    rtb_Abs = fabsf(rtb_MatrixConcatenate1_tmp);

    /* Trigonometry: '<S219>/Trigonometric Function1' incorporates:
     *  Gain: '<S218>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S219>/Trigonometric Function3'
     *  Trigonometry: '<S221>/Trigonometric Function1'
     *  Trigonometry: '<S221>/Trigonometric Function3'
     */
    rtb_Cos_j = arm_cos_f32(-Controller_U.INS_Out.psi);
    rtb_MatrixConcatenate1[0] = rtb_Cos_j;

    /* Trigonometry: '<S219>/Trigonometric Function' incorporates:
     *  Gain: '<S218>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S219>/Trigonometric Function2'
     *  Trigonometry: '<S221>/Trigonometric Function'
     */
    rtb_Saturation1_h_idx_0 = arm_sin_f32(-Controller_U.INS_Out.psi);
    rtb_MatrixConcatenate1[1] = rtb_Saturation1_h_idx_0;

    /* SignalConversion: '<S219>/ConcatBufferAtVector Concatenate1In3' incorporates:
     *  Constant: '<S219>/Constant3'
     */
    rtb_MatrixConcatenate1[2] = 0.0F;

    /* Gain: '<S219>/Gain' */
    rtb_MatrixConcatenate1[3] = -rtb_Saturation1_h_idx_0;

    /* Trigonometry: '<S219>/Trigonometric Function3' */
    rtb_MatrixConcatenate1[4] = rtb_Cos_j;

    /* SignalConversion: '<S219>/ConcatBufferAtVector Concatenate2In3' incorporates:
     *  Constant: '<S219>/Constant4'
     */
    rtb_MatrixConcatenate1[5] = 0.0F;

    /* SignalConversion: '<S219>/ConcatBufferAtVector ConcatenateIn3' */
    rtb_MatrixConcatenate1[6] = Controller_ConstB.VectorConcatenate3_c[0];
    rtb_MatrixConcatenate1[7] = Controller_ConstB.VectorConcatenate3_c[1];
    rtb_MatrixConcatenate1[8] = Controller_ConstB.VectorConcatenate3_c[2];

    /* SignalConversion: '<S215>/TmpSignal ConversionAtMultiplyInport2' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Add_c = Controller_U.INS_Out.vn;
    rtb_FF_limit_idx_1 = Controller_U.INS_Out.ve;
    rtb_FF_limit_idx_2 = Controller_U.INS_Out.vd;

    /* Product: '<S215>/Multiply' */
    for (i = 0; i < 3; i++) {
      rtb_DiscreteTimeIntegrator1_k1[i] = rtb_MatrixConcatenate1[i + 6] *
        rtb_FF_limit_idx_2 + (rtb_MatrixConcatenate1[i + 3] * rtb_FF_limit_idx_1
        + rtb_MatrixConcatenate1[i] * rtb_Add_c);
    }

    /* End of Product: '<S215>/Multiply' */

    /* Switch: '<S215>/Switch' incorporates:
     *  Gain: '<S215>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S215>/Divide'
     *  S-Function (sfix_bitop): '<S215>/Bitwise AND'
     *  Trigonometry: '<S215>/Asin'
     */
    if ((Controller_U.INS_Out.flag & 16U) > 1U) {
      /* Sqrt: '<S215>/Sqrt' incorporates:
       *  Math: '<S215>/Square'
       *  Math: '<S215>/Square1'
       *  Sum: '<S215>/Add'
       */
      rtb_Divide_i_idx_0 = sqrtf(Controller_U.INS_Out.vn *
        Controller_U.INS_Out.vn + Controller_U.INS_Out.ve *
        Controller_U.INS_Out.ve);

      /* Saturate: '<S215>/Saturation' incorporates:
       *  Sqrt: '<S215>/Sqrt'
       */
      if (rtb_Divide_i_idx_0 > 100.0F) {
        rtb_Divide_i_idx_0 = 100.0F;
      } else {
        if (rtb_Divide_i_idx_0 < 8.0F) {
          rtb_Divide_i_idx_0 = 8.0F;
        }
      }

      /* End of Saturate: '<S215>/Saturation' */

      /* DeadZone: '<S215>/Dead Zone' */
      if (Controller_U.INS_Out.vd > 0.1F) {
        rtb_MatrixConcatenate1_tmp = Controller_U.INS_Out.vd - 0.1F;
      } else if (Controller_U.INS_Out.vd >= -0.1F) {
        rtb_MatrixConcatenate1_tmp = 0.0F;
      } else {
        rtb_MatrixConcatenate1_tmp = Controller_U.INS_Out.vd - -0.1F;
      }

      /* End of DeadZone: '<S215>/Dead Zone' */
      rtb_Saturation1_ih = atanf(1.0F / rtb_Divide_i_idx_0 *
        -rtb_MatrixConcatenate1_tmp);
    } else {
      rtb_Saturation1_ih = Controller_U.INS_Out.theta;
    }

    /* End of Switch: '<S215>/Switch' */

    /* DeadZone: '<S215>/Dead Zone1' */
    if (rtb_DiscreteTimeIntegrator1_k1[0] > 1.0F) {
      rtb_Divide_i_idx_0 = rtb_DiscreteTimeIntegrator1_k1[0] - 1.0F;
    } else if (rtb_DiscreteTimeIntegrator1_k1[0] >= -1.0F) {
      rtb_Divide_i_idx_0 = 0.0F;
    } else {
      rtb_Divide_i_idx_0 = rtb_DiscreteTimeIntegrator1_k1[0] - -1.0F;
    }

    /* End of DeadZone: '<S215>/Dead Zone1' */

    /* Signum: '<S215>/Sign' */
    if (rtb_Divide_i_idx_0 < 0.0F) {
      rtb_Divide_i_idx_0 = -1.0F;
    } else {
      if (rtb_Divide_i_idx_0 > 0.0F) {
        rtb_Divide_i_idx_0 = 1.0F;
      }
    }

    /* End of Signum: '<S215>/Sign' */

    /* Product: '<S215>/Multiply1' */
    rtb_Saturation1_ih *= rtb_Divide_i_idx_0;

    /* Saturate: '<S215>/Saturation1' */
    if (rtb_Saturation1_ih > 0.785398185F) {
      rtb_Saturation1_ih = 0.785398185F;
    } else {
      if (rtb_Saturation1_ih < -0.785398185F) {
        rtb_Saturation1_ih = -0.785398185F;
      }
    }

    /* End of Saturate: '<S215>/Saturation1' */

    /* Gain: '<S214>/Gain1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_VdotPg = 0.101936802F * Controller_U.INS_Out.ax;

    /* Sqrt: '<S217>/Sqrt' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Math: '<S217>/Square'
     *  Math: '<S217>/Square1'
     *  Sum: '<S217>/Add'
     */
    u0 = sqrtf(Controller_U.INS_Out.vn * Controller_U.INS_Out.vn +
               Controller_U.INS_Out.ve * Controller_U.INS_Out.ve);

    /* Trigonometry: '<S221>/Trigonometric Function1' */
    rtb_MatrixConcatenate1[0] = rtb_Cos_j;

    /* Trigonometry: '<S221>/Trigonometric Function' */
    rtb_MatrixConcatenate1[1] = rtb_Saturation1_h_idx_0;

    /* SignalConversion: '<S221>/ConcatBufferAtVector Concatenate1In3' incorporates:
     *  Constant: '<S221>/Constant3'
     */
    rtb_MatrixConcatenate1[2] = 0.0F;

    /* Gain: '<S221>/Gain' incorporates:
     *  Gain: '<S220>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S221>/Trigonometric Function2'
     */
    rtb_MatrixConcatenate1[3] = -arm_sin_f32(-Controller_U.INS_Out.psi);

    /* Trigonometry: '<S221>/Trigonometric Function3' */
    rtb_MatrixConcatenate1[4] = rtb_Cos_j;

    /* SignalConversion: '<S221>/ConcatBufferAtVector Concatenate2In3' incorporates:
     *  Constant: '<S221>/Constant4'
     */
    rtb_MatrixConcatenate1[5] = 0.0F;

    /* SignalConversion: '<S221>/ConcatBufferAtVector ConcatenateIn3' */
    rtb_MatrixConcatenate1[6] = Controller_ConstB.VectorConcatenate3_o[0];
    rtb_MatrixConcatenate1[7] = Controller_ConstB.VectorConcatenate3_o[1];
    rtb_MatrixConcatenate1[8] = Controller_ConstB.VectorConcatenate3_o[2];

    /* Product: '<S217>/Multiply' */
    for (i = 0; i < 3; i++) {
      rtb_DiscreteTimeIntegrator1_k1[i] = rtb_MatrixConcatenate1[i + 6] *
        rtb_FF_limit_idx_2 + (rtb_MatrixConcatenate1[i + 3] * rtb_FF_limit_idx_1
        + rtb_MatrixConcatenate1[i] * rtb_Add_c);
    }

    /* End of Product: '<S217>/Multiply' */

    /* DeadZone: '<S217>/Dead Zone' */
    if (rtb_DiscreteTimeIntegrator1_k1[0] > 1.0F) {
      rtb_Divide_i_idx_0 = rtb_DiscreteTimeIntegrator1_k1[0] - 1.0F;
    } else if (rtb_DiscreteTimeIntegrator1_k1[0] >= -1.0F) {
      rtb_Divide_i_idx_0 = 0.0F;
    } else {
      rtb_Divide_i_idx_0 = rtb_DiscreteTimeIntegrator1_k1[0] - -1.0F;
    }

    /* End of DeadZone: '<S217>/Dead Zone' */

    /* Saturate: '<S217>/Saturation1' incorporates:
     *  Sqrt: '<S217>/Sqrt'
     */
    if (u0 > 100.0F) {
      u0 = 100.0F;
    } else {
      if (u0 < 8.0F) {
        u0 = 8.0F;
      }
    }

    /* End of Saturate: '<S217>/Saturation1' */

    /* Signum: '<S217>/Sign' */
    if (rtb_Divide_i_idx_0 < 0.0F) {
      rtb_Divide_i_idx_0 = -1.0F;
    } else {
      if (rtb_Divide_i_idx_0 > 0.0F) {
        rtb_Divide_i_idx_0 = 1.0F;
      }
    }

    /* End of Signum: '<S217>/Sign' */

    /* Product: '<S217>/Multiply1' incorporates:
     *  Gain: '<S217>/Gain'
     *  Product: '<S217>/Divide'
     *  Trigonometry: '<S217>/Asin'
     */
    u0 = atanf(-Controller_U.FMS_Out.w_cmd / u0) * rtb_Divide_i_idx_0;

    /* Saturate: '<S217>/Saturation2' */
    if (u0 > 0.785398185F) {
      u0 = 0.785398185F;
    } else {
      if (u0 < -0.785398185F) {
        u0 = -0.785398185F;
      }
    }

    /* End of Saturate: '<S217>/Saturation2' */

    /* Sum: '<S210>/Minus' */
    rtb_Minus = u0 - rtb_Saturation1_ih;

    /* Sqrt: '<S236>/Sqrt' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Math: '<S236>/Square'
     *  Sum: '<S236>/Sum of Elements'
     */
    rtb_Sum = sqrtf(((Controller_U.INS_Out.quat[0] * Controller_U.INS_Out.quat[0]
                      + Controller_U.INS_Out.quat[1] *
                      Controller_U.INS_Out.quat[1]) + Controller_U.INS_Out.quat
                     [2] * Controller_U.INS_Out.quat[2]) +
                    Controller_U.INS_Out.quat[3] * Controller_U.INS_Out.quat[3]);

    /* Product: '<S232>/Divide' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_i_idx_0 = Controller_U.INS_Out.quat[0] / rtb_Sum;
    rtb_Divide_i_idx_1 = Controller_U.INS_Out.quat[1] / rtb_Sum;
    rtb_Divide_i_idx_2 = Controller_U.INS_Out.quat[2] / rtb_Sum;
    rtb_Divide_i_idx_3 = Controller_U.INS_Out.quat[3] / rtb_Sum;

    /* Math: '<S233>/Square' incorporates:
     *  Math: '<S234>/Square'
     *  Math: '<S235>/Square'
     */
    rtb_Cos_j = rtb_Divide_i_idx_0 * rtb_Divide_i_idx_0;

    /* Math: '<S233>/Square2' incorporates:
     *  Math: '<S234>/Square2'
     *  Math: '<S235>/Square2'
     */
    rtb_Saturation1_h_idx_0 = rtb_Divide_i_idx_2 * rtb_Divide_i_idx_2;

    /* Math: '<S233>/Square1' incorporates:
     *  Math: '<S234>/Square1'
     *  Math: '<S235>/Square1'
     */
    rtb_MatrixConcatenate1_tmp = rtb_Divide_i_idx_1 * rtb_Divide_i_idx_1;

    /* Math: '<S233>/Square3' incorporates:
     *  Math: '<S234>/Square3'
     *  Math: '<S235>/Square3'
     */
    rtb_B_err = rtb_Divide_i_idx_3 * rtb_Divide_i_idx_3;

    /* Sum: '<S233>/Subtract' incorporates:
     *  Math: '<S233>/Square'
     *  Math: '<S233>/Square1'
     *  Math: '<S233>/Square2'
     *  Math: '<S233>/Square3'
     *  Sum: '<S233>/Add'
     *  Sum: '<S233>/Add1'
     */
    rtb_MatrixConcatenate1[0] = (rtb_Cos_j + rtb_MatrixConcatenate1_tmp) -
      (rtb_Saturation1_h_idx_0 + rtb_B_err);

    /* Product: '<S233>/Multiply' incorporates:
     *  Product: '<S234>/Multiply'
     */
    rtb_Gain_il = rtb_Divide_i_idx_1 * rtb_Divide_i_idx_2;

    /* Product: '<S233>/Multiply1' incorporates:
     *  Product: '<S234>/Multiply1'
     */
    u0 = rtb_Divide_i_idx_0 * rtb_Divide_i_idx_3;

    /* Gain: '<S233>/Gain' incorporates:
     *  Product: '<S233>/Multiply'
     *  Product: '<S233>/Multiply1'
     *  Sum: '<S233>/Subtract1'
     */
    rtb_MatrixConcatenate1[1] = (rtb_Gain_il - u0) * 2.0F;

    /* Product: '<S233>/Multiply2' incorporates:
     *  Product: '<S235>/Multiply'
     */
    rtb_Sum = rtb_Divide_i_idx_1 * rtb_Divide_i_idx_3;

    /* Product: '<S233>/Multiply3' incorporates:
     *  Product: '<S235>/Multiply1'
     */
    rtb_Add2_h = rtb_Divide_i_idx_0 * rtb_Divide_i_idx_2;

    /* Gain: '<S233>/Gain1' incorporates:
     *  Product: '<S233>/Multiply2'
     *  Product: '<S233>/Multiply3'
     *  Sum: '<S233>/Add2'
     */
    rtb_MatrixConcatenate1[2] = (rtb_Sum + rtb_Add2_h) * 2.0F;

    /* Gain: '<S234>/Gain' incorporates:
     *  Sum: '<S234>/Add3'
     */
    rtb_MatrixConcatenate1[3] = (rtb_Gain_il + u0) * 2.0F;

    /* Sum: '<S234>/Subtract' incorporates:
     *  Sum: '<S234>/Add'
     *  Sum: '<S234>/Add1'
     */
    rtb_MatrixConcatenate1[4] = (rtb_Cos_j + rtb_Saturation1_h_idx_0) -
      (rtb_MatrixConcatenate1_tmp + rtb_B_err);

    /* Product: '<S234>/Multiply2' incorporates:
     *  Product: '<S235>/Multiply2'
     */
    rtb_Gain_il = rtb_Divide_i_idx_2 * rtb_Divide_i_idx_3;

    /* Product: '<S234>/Multiply3' incorporates:
     *  Product: '<S235>/Multiply3'
     */
    u0 = rtb_Divide_i_idx_0 * rtb_Divide_i_idx_1;

    /* Gain: '<S234>/Gain1' incorporates:
     *  Product: '<S234>/Multiply2'
     *  Product: '<S234>/Multiply3'
     *  Sum: '<S234>/Subtract1'
     */
    rtb_MatrixConcatenate1[5] = (rtb_Gain_il - u0) * 2.0F;

    /* Gain: '<S235>/Gain' incorporates:
     *  Sum: '<S235>/Subtract2'
     */
    rtb_MatrixConcatenate1[6] = (rtb_Sum - rtb_Add2_h) * 2.0F;

    /* Gain: '<S235>/Gain1' incorporates:
     *  Sum: '<S235>/Add2'
     */
    rtb_MatrixConcatenate1[7] = (rtb_Gain_il + u0) * 2.0F;

    /* Sum: '<S235>/Subtract' incorporates:
     *  Sum: '<S235>/Add'
     *  Sum: '<S235>/Add1'
     */
    rtb_MatrixConcatenate1[8] = (rtb_Cos_j + rtb_B_err) -
      (rtb_MatrixConcatenate1_tmp + rtb_Saturation1_h_idx_0);

    /* Product: '<S229>/Multiply' */
    for (i = 0; i < 3; i++) {
      rtb_DiscreteTimeIntegrator1_k1[i] = rtb_MatrixConcatenate1[i + 6] *
        rtb_FF_limit_idx_2 + (rtb_MatrixConcatenate1[i + 3] * rtb_FF_limit_idx_1
        + rtb_MatrixConcatenate1[i] * rtb_Add_c);
    }

    /* End of Product: '<S229>/Multiply' */

    /* Switch: '<S229>/Switch' incorporates:
     *  Constant: '<S230>/Constant'
     *  Inport: '<Root>/INS_Out'
     *  RelationalOperator: '<S230>/Compare'
     */
    if (rtb_DiscreteTimeIntegrator1_k1[0] >= 3.0F) {
      rtb_Divide_i_idx_0 = Controller_U.INS_Out.airspeed;
    } else {
      rtb_Divide_i_idx_0 = rtb_DiscreteTimeIntegrator1_k1[0];
    }

    /* End of Switch: '<S229>/Switch' */

    /* Sum: '<S214>/Sum' incorporates:
     *  Gain: '<S214>/Gain'
     *  Sum: '<S214>/Minus'
     */
    rtb_Sum = (Controller_U.FMS_Out.u_cmd - rtb_Divide_i_idx_0) * 0.101936802F -
      rtb_VdotPg;

    /* Sum: '<S192>/Minus1' incorporates:
     *  Gain: '<S192>/ucmd2pitch'
     *  Gain: '<S192>/wcmd2pitch'
     */
    rtb_B_err = CONTROL_PARAM.FW_TECS_W2P * rtb_Minus -
      CONTROL_PARAM.FW_TECS_U2P * rtb_Sum;

    /* DiscreteIntegrator: '<S224>/ ' */
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

    /* DiscreteIntegrator: '<S225>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_f != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_e = rtb_B_err;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_b != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_e = rtb_B_err;
    }

    /* Gain: '<S225>/Gain' incorporates:
     *  DiscreteIntegrator: '<S225>/Discrete-Time Integrator1'
     *  Sum: '<S225>/Sum5'
     */
    rtb_Gain_il = (rtb_B_err - Controller_DW.DiscreteTimeIntegrator1_DSTAT_e) *
      62.831852F;

    /* Switch: '<S225>/Switch' incorporates:
     *  Gain: '<S225>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_MatrixConcatenate1_tmp = 0.0F;
    } else {
      rtb_MatrixConcatenate1_tmp = rtb_Gain_il;
    }

    /* End of Switch: '<S225>/Switch' */

    /* Gain: '<S223>/Gain' */
    rtb_Add2_h = CONTROL_PARAM.FW_TECS_PITCH_D * rtb_MatrixConcatenate1_tmp;

    /* Saturate: '<S212>/Saturation1' */
    if (rtb_Add2_h > 0.3F) {
      rtb_Add2_h = 0.3F;
    } else {
      if (rtb_Add2_h < -0.3F) {
        rtb_Add2_h = -0.3F;
      }
    }

    /* End of Saturate: '<S212>/Saturation1' */

    /* Sum: '<S192>/Sum' incorporates:
     *  DiscreteIntegrator: '<S224>/ '
     *  Gain: '<S192>/Gain'
     *  Gain: '<S192>/balabnce_ratio2'
     *  Gain: '<S192>/balance_ratio'
     *  Gain: '<S192>/pitch_ff'
     *  Gain: '<S212>/P_control'
     *  Sum: '<S192>/Add3'
     *  Sum: '<S192>/Minus'
     *  Sum: '<S212>/Add'
     */
    rtb_Add2_h = (((2.0F - CONTROL_PARAM.FW_TECS_RATIO) * rtb_Saturation1_ih -
                   CONTROL_PARAM.FW_TECS_RATIO * rtb_VdotPg) *
                  CONTROL_PARAM.FW_TECS_PITCH_F +
                  ((CONTROL_PARAM.FW_TECS_PITCH_P * rtb_B_err +
                    Controller_DW._DSTATE) + rtb_Add2_h)) +
      CONTROL_PARAM.FW_TECS_R2P * rtb_Abs;

    /* Switch: '<S170>/Switch' incorporates:
     *  Constant: '<S173>/Constant'
     *  RelationalOperator: '<S173>/Compare'
     */
    if (rtb_BitwiseAND_a <= 4) {
      rtb_MatrixConcatenate1_tmp = Controller_U.FMS_Out.phi_cmd;
    } else {
      rtb_MatrixConcatenate1_tmp = rtb_Cos1_d;
    }

    /* End of Switch: '<S170>/Switch' */

    /* Sum: '<S164>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_i_idx_0 = rtb_MatrixConcatenate1_tmp - Controller_U.INS_Out.phi;

    /* Switch: '<S171>/Switch' incorporates:
     *  Constant: '<S174>/Constant'
     *  RelationalOperator: '<S174>/Compare'
     */
    if (rtb_BitwiseAND_a <= 3) {
      rtb_MatrixConcatenate1_tmp = Controller_U.FMS_Out.theta_cmd;
    } else {
      rtb_MatrixConcatenate1_tmp = rtb_Add2_h;
    }

    /* End of Switch: '<S171>/Switch' */

    /* Sum: '<S164>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Cos_j = rtb_MatrixConcatenate1_tmp - Controller_U.INS_Out.theta;

    /* Product: '<S167>/Divide1' incorporates:
     *  Abs: '<S167>/Abs'
     *  Constant: '<S167>/const2'
     */
    rtb_FF_limit_idx_2 = fabsf(rtb_Divide_i_idx_0) / 0.002F;

    /* Product: '<S167>/Divide' incorporates:
     *  Constant: '<S165>/Constant1'
     *  Constant: '<S167>/const1'
     *  Math: '<S167>/Square'
     *  SignalConversion: '<S167>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_Add_c = 9.5993F / (CONTROL_PARAM.MC_ROLL_P * CONTROL_PARAM.MC_ROLL_P);

    /* Signum: '<S167>/Sign' incorporates:
     *  Abs: '<S167>/Abs'
     */
    if (rtb_Divide_i_idx_0 < 0.0F) {
      rtb_MatrixConcatenate1_tmp = -1.0F;
    } else if (rtb_Divide_i_idx_0 > 0.0F) {
      rtb_MatrixConcatenate1_tmp = 1.0F;
    } else {
      rtb_MatrixConcatenate1_tmp = rtb_Divide_i_idx_0;
    }

    /* Switch: '<S167>/Switch' incorporates:
     *  Abs: '<S167>/Abs'
     *  Constant: '<S165>/Constant1'
     *  Gain: '<S167>/Gain1'
     *  Gain: '<S167>/Gain2'
     *  Logic: '<S167>/Logical Operator'
     *  Product: '<S167>/Divide'
     *  Product: '<S167>/Multiply'
     *  Product: '<S167>/Multiply1'
     *  Product: '<S167>/Multiply2'
     *  Product: '<S167>/Multiply3'
     *  RelationalOperator: '<S167>/Relational Operator'
     *  RelationalOperator: '<S167>/Relational Operator2'
     *  SignalConversion: '<S167>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S167>/Sqrt'
     *  Sum: '<S167>/Subtract'
     */
    if ((rtb_Divide_i_idx_0 <= rtb_Add_c) && (rtb_Divide_i_idx_0 >= -rtb_Add_c))
    {
      rtb_MatrixConcatenate1_tmp = rtb_Divide_i_idx_0 * CONTROL_PARAM.MC_ROLL_P;
    } else {
      rtb_MatrixConcatenate1_tmp *= sqrtf((rtb_MatrixConcatenate1_tmp *
        rtb_Divide_i_idx_0 - 0.5F * rtb_Add_c) * Controller_ConstB.Gain_np);
    }

    /* Gain: '<S167>/Gain3' */
    rtb_Add_c = -rtb_FF_limit_idx_2;

    /* Switch: '<S168>/Switch' incorporates:
     *  Gain: '<S167>/Gain3'
     *  RelationalOperator: '<S168>/UpperRelop'
     */
    if (rtb_MatrixConcatenate1_tmp >= -rtb_FF_limit_idx_2) {
      rtb_Add_c = rtb_MatrixConcatenate1_tmp;
    }

    /* Switch: '<S168>/Switch2' incorporates:
     *  RelationalOperator: '<S168>/LowerRelop1'
     */
    if (rtb_MatrixConcatenate1_tmp <= rtb_FF_limit_idx_2) {
      rtb_FF_limit_idx_2 = rtb_Add_c;
    }

    /* Saturate: '<S153>/Saturation1' */
    if (rtb_FF_limit_idx_2 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_FF_limit_idx_2 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_FF_limit_idx_2 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_FF_limit_idx_2 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    rtb_Saturation1_h_idx_0 = rtb_FF_limit_idx_2;

    /* Product: '<S167>/Divide1' incorporates:
     *  Abs: '<S167>/Abs'
     *  Constant: '<S167>/const2'
     */
    rtb_FF_limit_idx_2 = fabsf(rtb_Cos_j) / 0.002F;

    /* Product: '<S167>/Divide' incorporates:
     *  Constant: '<S165>/Constant2'
     *  Constant: '<S167>/const1'
     *  Math: '<S167>/Square'
     *  SignalConversion: '<S167>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_Add_c = 9.5993F / (CONTROL_PARAM.MC_PITCH_P * CONTROL_PARAM.MC_PITCH_P);

    /* Signum: '<S167>/Sign' incorporates:
     *  Abs: '<S167>/Abs'
     */
    if (rtb_Cos_j < 0.0F) {
      rtb_MatrixConcatenate1_tmp = -1.0F;
    } else if (rtb_Cos_j > 0.0F) {
      rtb_MatrixConcatenate1_tmp = 1.0F;
    } else {
      rtb_MatrixConcatenate1_tmp = rtb_Cos_j;
    }

    /* Switch: '<S167>/Switch' incorporates:
     *  Abs: '<S167>/Abs'
     *  Constant: '<S165>/Constant2'
     *  Gain: '<S167>/Gain1'
     *  Gain: '<S167>/Gain2'
     *  Logic: '<S167>/Logical Operator'
     *  Product: '<S167>/Divide'
     *  Product: '<S167>/Multiply'
     *  Product: '<S167>/Multiply1'
     *  Product: '<S167>/Multiply2'
     *  Product: '<S167>/Multiply3'
     *  RelationalOperator: '<S167>/Relational Operator'
     *  RelationalOperator: '<S167>/Relational Operator2'
     *  SignalConversion: '<S167>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S167>/Sqrt'
     *  Sum: '<S167>/Subtract'
     */
    if ((rtb_Cos_j <= rtb_Add_c) && (rtb_Cos_j >= -rtb_Add_c)) {
      rtb_MatrixConcatenate1_tmp = rtb_Cos_j * CONTROL_PARAM.MC_PITCH_P;
    } else {
      rtb_MatrixConcatenate1_tmp *= sqrtf((rtb_MatrixConcatenate1_tmp *
        rtb_Cos_j - 0.5F * rtb_Add_c) * Controller_ConstB.Gain_np);
    }

    /* Gain: '<S167>/Gain3' */
    rtb_Add_c = -rtb_FF_limit_idx_2;

    /* Switch: '<S168>/Switch' incorporates:
     *  Gain: '<S167>/Gain3'
     *  RelationalOperator: '<S168>/UpperRelop'
     */
    if (rtb_MatrixConcatenate1_tmp >= -rtb_FF_limit_idx_2) {
      rtb_Add_c = rtb_MatrixConcatenate1_tmp;
    }

    /* Switch: '<S168>/Switch2' incorporates:
     *  RelationalOperator: '<S168>/LowerRelop1'
     */
    if (rtb_MatrixConcatenate1_tmp <= rtb_FF_limit_idx_2) {
      rtb_FF_limit_idx_2 = rtb_Add_c;
    }

    /* Saturate: '<S153>/Saturation1' */
    if (rtb_FF_limit_idx_2 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_FF_limit_idx_2 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_FF_limit_idx_2 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_FF_limit_idx_2 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    /* Saturate: '<S153>/Saturation' */
    if (Controller_U.FMS_Out.psi_rate_cmd > CONTROL_PARAM.MC_R_CMD_LIM) {
      rtb_Cos_j = CONTROL_PARAM.MC_R_CMD_LIM;
    } else if (Controller_U.FMS_Out.psi_rate_cmd < -CONTROL_PARAM.MC_R_CMD_LIM)
    {
      rtb_Cos_j = -CONTROL_PARAM.MC_R_CMD_LIM;
    } else {
      rtb_Cos_j = Controller_U.FMS_Out.psi_rate_cmd;
    }

    /* End of Saturate: '<S153>/Saturation' */

    /* Trigonometry: '<S162>/Sin' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S195>/Sin'
     */
    rtb_MatrixConcatenate1_tmp = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S162>/Sin1' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S195>/Sin1'
     */
    rtb_u = arm_sin_f32(Controller_U.INS_Out.theta);

    /* Sum: '<S154>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S162>/Multiply'
     *  Product: '<S162>/Multiply1'
     *  Product: '<S162>/Multiply3'
     *  Product: '<S162>/Multiply4'
     *  Product: '<S162>/Multiply5'
     *  Sum: '<S162>/Add'
     *  Sum: '<S162>/Add1'
     *  Sum: '<S162>/Add2'
     *  Trigonometry: '<S162>/Sin'
     *  Trigonometry: '<S162>/Sin1'
     */
    rtb_Add_c = (rtb_Saturation1_h_idx_0 - rtb_u * rtb_Cos_j) -
      Controller_U.INS_Out.p;
    rtb_FF_limit_idx_1 = (rtb_MatrixConcatenate1_tmp * rtb_Gain_cu * rtb_Cos_j +
                          rtb_Multiply_ga_idx_0 * rtb_FF_limit_idx_2) -
      Controller_U.INS_Out.q;
    rtb_FF_limit_idx_2 = (rtb_Multiply_ga_idx_0 * rtb_Gain_cu * rtb_Cos_j -
                          rtb_MatrixConcatenate1_tmp * rtb_FF_limit_idx_2) -
      Controller_U.INS_Out.r;

    /* DiscreteIntegrator: '<S157>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_b != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0] = rtb_Add_c;
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1] = rtb_FF_limit_idx_1;
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2] = rtb_FF_limit_idx_2;
    }

    /* Logic: '<S149>/Logical Operator' incorporates:
     *  Constant: '<S151>/Constant'
     *  DiscreteIntegrator: '<S188>/Discrete-Time Integrator5'
     *  RelationalOperator: '<S151>/Compare'
     */
    rtb_LogicalOperator_m = ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator5_DSTA_a2 == 0.0F));

    /* DiscreteIntegrator: '<S159>/Discrete-Time Integrator' */
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

    /* DiscreteIntegrator: '<S161>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S157>/Discrete-Time Integrator5'
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

    /* Gain: '<S161>/Gain' incorporates:
     *  DiscreteIntegrator: '<S157>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S161>/Discrete-Time Integrator1'
     *  Sum: '<S161>/Sum5'
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

    /* Switch: '<S161>/Switch' incorporates:
     *  Gain: '<S161>/Gain1'
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

    /* End of Switch: '<S161>/Switch' */

    /* Product: '<S158>/Multiply' incorporates:
     *  Constant: '<S158>/gain1'
     */
    rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_ROLL_RATE_D *
      rtb_Divide_i_idx_1;

    /* Saturate: '<S158>/Saturation' */
    if (rtb_DiscreteTimeIntegrator1_g > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_DiscreteTimeIntegrator1_g < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    rtb_Divide_i_idx_1 = rtb_DiscreteTimeIntegrator1_g;

    /* Product: '<S158>/Multiply' incorporates:
     *  Constant: '<S158>/gain2'
     */
    rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_PITCH_RATE_D *
      rtb_Divide_i_idx_2;

    /* Saturate: '<S158>/Saturation' */
    if (rtb_DiscreteTimeIntegrator1_g > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_DiscreteTimeIntegrator1_g < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    rtb_Divide_i_idx_2 = rtb_DiscreteTimeIntegrator1_g;

    /* Product: '<S158>/Multiply' incorporates:
     *  Constant: '<S158>/gain3'
     */
    rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_YAW_RATE_D *
      rtb_Divide_i_idx_3;

    /* Saturate: '<S158>/Saturation' */
    if (rtb_DiscreteTimeIntegrator1_g > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_DiscreteTimeIntegrator1_g < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    /* Product: '<S142>/Multiply2' incorporates:
     *  Constant: '<S160>/gain1'
     *  DiscreteIntegrator: '<S157>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S159>/Discrete-Time Integrator'
     *  DiscreteIntegrator: '<S188>/Discrete-Time Integrator5'
     *  Product: '<S160>/Multiply'
     *  Sum: '<S155>/Add'
     */
    u0 = ((CONTROL_PARAM.MC_ROLL_RATE_P *
           Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0] +
           Controller_DW.DiscreteTimeIntegrator_DSTATE_d[0]) +
          rtb_Divide_i_idx_1) * Controller_DW.DiscreteTimeIntegrator5_DSTA_a2;

    /* Saturate: '<S142>/Saturation2' */
    if (u0 > 1.0F) {
      rtb_Saturation2[0] = 1.0F;
    } else if (u0 < -1.0F) {
      rtb_Saturation2[0] = -1.0F;
    } else {
      rtb_Saturation2[0] = u0;
    }

    /* Product: '<S142>/Multiply2' incorporates:
     *  Constant: '<S160>/gain2'
     *  DiscreteIntegrator: '<S157>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S159>/Discrete-Time Integrator'
     *  DiscreteIntegrator: '<S188>/Discrete-Time Integrator5'
     *  Product: '<S160>/Multiply'
     *  Sum: '<S155>/Add'
     */
    u0 = ((CONTROL_PARAM.MC_PITCH_RATE_P *
           Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1] +
           Controller_DW.DiscreteTimeIntegrator_DSTATE_d[1]) +
          rtb_Divide_i_idx_2) * Controller_DW.DiscreteTimeIntegrator5_DSTA_a2;

    /* Saturate: '<S142>/Saturation2' */
    if (u0 > 1.0F) {
      rtb_Saturation2[1] = 1.0F;
    } else if (u0 < -1.0F) {
      rtb_Saturation2[1] = -1.0F;
    } else {
      rtb_Saturation2[1] = u0;
    }

    /* Product: '<S142>/Multiply2' incorporates:
     *  Constant: '<S160>/gain3'
     *  DiscreteIntegrator: '<S157>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S159>/Discrete-Time Integrator'
     *  DiscreteIntegrator: '<S188>/Discrete-Time Integrator5'
     *  Product: '<S160>/Multiply'
     *  Sum: '<S155>/Add'
     */
    u0 = ((CONTROL_PARAM.MC_YAW_RATE_P *
           Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2] +
           Controller_DW.DiscreteTimeIntegrator_DSTATE_d[2]) +
          rtb_DiscreteTimeIntegrator1_g) *
      Controller_DW.DiscreteTimeIntegrator5_DSTA_a2;

    /* Saturate: '<S142>/Saturation2' */
    if (u0 > 1.0F) {
      rtb_Saturation2[2] = 1.0F;
    } else if (u0 < -1.0F) {
      rtb_Saturation2[2] = -1.0F;
    } else {
      rtb_Saturation2[2] = u0;
    }

    /* DiscreteIntegrator: '<S187>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_g != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j = rtb_Saturation_ov;
    }

    /* Saturate: '<S193>/Saturation1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    if (Controller_U.INS_Out.airspeed > 999.0F) {
      rtb_DiscreteTimeIntegrator1_g = 999.0F;
    } else if (Controller_U.INS_Out.airspeed < 0.1F) {
      rtb_DiscreteTimeIntegrator1_g = 0.1F;
    } else {
      rtb_DiscreteTimeIntegrator1_g = Controller_U.INS_Out.airspeed;
    }

    /* End of Saturate: '<S193>/Saturation1' */

    /* Product: '<S198>/Divide' incorporates:
     *  Constant: '<S198>/trim_speed'
     */
    rtb_Saturation1_h_idx_0 = CONTROL_PARAM.FW_AIRSPEED_TRIM /
      rtb_DiscreteTimeIntegrator1_g;

    /* Saturate: '<S198>/Saturation' */
    if (rtb_Saturation1_h_idx_0 > 1.0F) {
      rtb_Saturation1_h_idx_0 = 1.0F;
    } else {
      if (rtb_Saturation1_h_idx_0 < 0.0F) {
        rtb_Saturation1_h_idx_0 = 0.0F;
      }
    }

    /* End of Saturate: '<S198>/Saturation' */

    /* Switch: '<S203>/Switch' incorporates:
     *  Logic: '<S203>/Logical Operator'
     *  RelationalOperator: '<S208>/Compare'
     */
    if ((rtb_BitwiseAND_a == 3) || (rtb_BitwiseAND_a == 4)) {
      rtb_Cos1_d = Controller_U.FMS_Out.phi_cmd;
    }

    /* End of Switch: '<S203>/Switch' */

    /* Switch: '<S203>/Switch1' incorporates:
     *  Constant: '<S209>/Constant'
     *  RelationalOperator: '<S209>/Compare'
     */
    if (rtb_BitwiseAND_a == 3) {
      rtb_Add2_h = Controller_U.FMS_Out.theta_cmd;
    }

    /* End of Switch: '<S203>/Switch1' */

    /* Bias: '<S204>/Pitch Offset' */
    rtb_Add2_h += CONTROL_PARAM.FW_PITCH_OFFSET;

    /* Saturate: '<S204>/Saturation' */
    if (rtb_Add2_h > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Add2_h = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_Add2_h < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_Add2_h = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      }
    }

    /* Product: '<S205>/Multiply' incorporates:
     *  Constant: '<S205>/Constant2'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S204>/Sum'
     */
    rtb_Cos_j = (rtb_Add2_h - Controller_U.INS_Out.theta) *
      CONTROL_PARAM.FW_PITCH_P;

    /* Product: '<S207>/Divide' incorporates:
     *  Constant: '<S207>/Constant'
     *  Inport: '<Root>/INS_Out'
     */
    u0 = 9.81F / Controller_U.INS_Out.airspeed;

    /* Saturate: '<S207>/Saturation' */
    if (u0 > 1.0F) {
      u0 = 1.0F;
    } else {
      if (u0 < 0.0F) {
        u0 = 0.0F;
      }
    }

    /* End of Saturate: '<S207>/Saturation' */

    /* Sum: '<S202>/Sum' incorporates:
     *  Product: '<S207>/Multiply'
     *  Product: '<S207>/Multiply1'
     *  Trigonometry: '<S207>/Cos'
     *  Trigonometry: '<S207>/Tan'
     */
    rtb_Divide_i_idx_0 = tanf(Controller_U.FMS_Out.phi_cmd) * arm_cos_f32
      (Controller_U.FMS_Out.theta_cmd) * u0 + Controller_U.FMS_Out.psi_rate_cmd;

    /* Saturate: '<S204>/Saturation' */
    if (rtb_Cos1_d > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Cos1_d = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_Cos1_d < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_Cos1_d = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      }
    }

    /* Sum: '<S195>/Add' incorporates:
     *  Constant: '<S205>/Constant1'
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S195>/Multiply'
     *  Product: '<S205>/Multiply'
     *  Sum: '<S204>/Sum'
     */
    rtb_Cos1_d = (rtb_Cos1_d - Controller_U.INS_Out.phi) *
      CONTROL_PARAM.FW_ROLL_P - rtb_u * rtb_Divide_i_idx_0;

    /* Sum: '<S195>/Add1' incorporates:
     *  Product: '<S195>/Multiply1'
     *  Product: '<S195>/Multiply3'
     */
    rtb_u = rtb_MatrixConcatenate1_tmp * rtb_Gain_cu * rtb_Divide_i_idx_0 +
      rtb_Multiply_ga_idx_0 * rtb_Cos_j;

    /* Sum: '<S195>/Add2' incorporates:
     *  Product: '<S195>/Multiply4'
     *  Product: '<S195>/Multiply5'
     */
    rtb_Add2_h = rtb_Multiply_ga_idx_0 * rtb_Gain_cu * rtb_Divide_i_idx_0 -
      rtb_MatrixConcatenate1_tmp * rtb_Cos_j;

    /* Product: '<S197>/Divide' incorporates:
     *  Constant: '<S197>/trim_speed'
     *  Math: '<S197>/Square'
     *  Math: '<S197>/Square1'
     */
    rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.FW_AIRSPEED_TRIM *
      CONTROL_PARAM.FW_AIRSPEED_TRIM / (rtb_DiscreteTimeIntegrator1_g *
      rtb_DiscreteTimeIntegrator1_g);

    /* Saturate: '<S197>/Saturation' */
    if (rtb_DiscreteTimeIntegrator1_g > 1.0F) {
      rtb_DiscreteTimeIntegrator1_g = 1.0F;
    } else {
      if (rtb_DiscreteTimeIntegrator1_g < 0.0F) {
        rtb_DiscreteTimeIntegrator1_g = 0.0F;
      }
    }

    /* End of Saturate: '<S197>/Saturation' */

    /* Sum: '<S193>/Minus2' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_i_idx_1 = rtb_Cos1_d - Controller_U.INS_Out.p;
    rtb_Divide_i_idx_2 = rtb_u - Controller_U.INS_Out.q;
    rtb_Divide_i_idx_3 = rtb_Add2_h - Controller_U.INS_Out.r;

    /* DiscreteIntegrator: '<S199>/Discrete-Time Integrator' */
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

    /* Product: '<S193>/Multiply1' incorporates:
     *  Gain: '<S193>/FF'
     */
    u0 = CONTROL_PARAM.FW_FF * rtb_Cos1_d * rtb_Saturation1_h_idx_0;

    /* Product: '<S193>/Multiply' incorporates:
     *  Constant: '<S200>/gain1'
     *  DiscreteIntegrator: '<S199>/Discrete-Time Integrator'
     *  Product: '<S200>/Multiply'
     *  Sum: '<S196>/Add1'
     */
    rtb_Multiply_ga_idx_0 = (CONTROL_PARAM.FW_ROLL_RATE_P * rtb_Divide_i_idx_1 +
      Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0]) *
      rtb_DiscreteTimeIntegrator1_g;

    /* Saturate: '<S193>/FF_limit' */
    if (u0 > CONTROL_PARAM.FW_FF_LIMIT) {
      u0 = CONTROL_PARAM.FW_FF_LIMIT;
    } else {
      if (u0 < -CONTROL_PARAM.FW_FF_LIMIT) {
        u0 = -CONTROL_PARAM.FW_FF_LIMIT;
      }
    }

    /* Saturate: '<S193>/PI_limit' */
    if (rtb_Multiply_ga_idx_0 > CONTROL_PARAM.FW_PI_LIMIT) {
      rtb_Multiply_ga_idx_0 = CONTROL_PARAM.FW_PI_LIMIT;
    } else {
      if (rtb_Multiply_ga_idx_0 < -CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_Multiply_ga_idx_0 = -CONTROL_PARAM.FW_PI_LIMIT;
      }
    }

    /* Product: '<S144>/Multiply' incorporates:
     *  DiscreteIntegrator: '<S187>/Discrete-Time Integrator5'
     *  Sum: '<S193>/Add'
     */
    u0 = (u0 + rtb_Multiply_ga_idx_0) *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;

    /* Saturate: '<S144>/Saturation1' */
    if (u0 > 1.0F) {
      rtb_Saturation1_f[0] = 1.0F;
    } else if (u0 < -1.0F) {
      rtb_Saturation1_f[0] = -1.0F;
    } else {
      rtb_Saturation1_f[0] = u0;
    }

    /* Product: '<S193>/Multiply1' incorporates:
     *  Gain: '<S193>/FF'
     */
    u0 = CONTROL_PARAM.FW_FF * rtb_u * rtb_Saturation1_h_idx_0;

    /* Product: '<S193>/Multiply' incorporates:
     *  Constant: '<S200>/gain2'
     *  DiscreteIntegrator: '<S199>/Discrete-Time Integrator'
     *  Product: '<S200>/Multiply'
     *  Sum: '<S196>/Add1'
     */
    rtb_Multiply_ga_idx_0 = (CONTROL_PARAM.FW_PITCH_RATE_P * rtb_Divide_i_idx_2
      + Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1]) *
      rtb_DiscreteTimeIntegrator1_g;

    /* Saturate: '<S193>/FF_limit' */
    if (u0 > CONTROL_PARAM.FW_FF_LIMIT) {
      u0 = CONTROL_PARAM.FW_FF_LIMIT;
    } else {
      if (u0 < -CONTROL_PARAM.FW_FF_LIMIT) {
        u0 = -CONTROL_PARAM.FW_FF_LIMIT;
      }
    }

    /* Saturate: '<S193>/PI_limit' */
    if (rtb_Multiply_ga_idx_0 > CONTROL_PARAM.FW_PI_LIMIT) {
      rtb_Multiply_ga_idx_0 = CONTROL_PARAM.FW_PI_LIMIT;
    } else {
      if (rtb_Multiply_ga_idx_0 < -CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_Multiply_ga_idx_0 = -CONTROL_PARAM.FW_PI_LIMIT;
      }
    }

    /* Product: '<S144>/Multiply' incorporates:
     *  DiscreteIntegrator: '<S187>/Discrete-Time Integrator5'
     *  Sum: '<S193>/Add'
     */
    u0 = (u0 + rtb_Multiply_ga_idx_0) *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;

    /* Saturate: '<S144>/Saturation1' */
    if (u0 > 1.0F) {
      rtb_Saturation1_f[1] = 1.0F;
    } else if (u0 < -1.0F) {
      rtb_Saturation1_f[1] = -1.0F;
    } else {
      rtb_Saturation1_f[1] = u0;
    }

    /* Product: '<S193>/Multiply1' incorporates:
     *  Gain: '<S193>/FF'
     */
    u0 = CONTROL_PARAM.FW_FF * rtb_Add2_h * rtb_Saturation1_h_idx_0;

    /* Product: '<S193>/Multiply' incorporates:
     *  Constant: '<S200>/gain3'
     *  DiscreteIntegrator: '<S199>/Discrete-Time Integrator'
     *  Product: '<S200>/Multiply'
     *  Sum: '<S196>/Add1'
     */
    rtb_Multiply_ga_idx_0 = (CONTROL_PARAM.FW_YAW_RATE_P * rtb_Divide_i_idx_3 +
      Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2]) *
      rtb_DiscreteTimeIntegrator1_g;

    /* Saturate: '<S193>/FF_limit' */
    if (u0 > CONTROL_PARAM.FW_FF_LIMIT) {
      u0 = CONTROL_PARAM.FW_FF_LIMIT;
    } else {
      if (u0 < -CONTROL_PARAM.FW_FF_LIMIT) {
        u0 = -CONTROL_PARAM.FW_FF_LIMIT;
      }
    }

    /* Saturate: '<S193>/PI_limit' */
    if (rtb_Multiply_ga_idx_0 > CONTROL_PARAM.FW_PI_LIMIT) {
      rtb_Multiply_ga_idx_0 = CONTROL_PARAM.FW_PI_LIMIT;
    } else {
      if (rtb_Multiply_ga_idx_0 < -CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_Multiply_ga_idx_0 = -CONTROL_PARAM.FW_PI_LIMIT;
      }
    }

    /* Product: '<S144>/Multiply' incorporates:
     *  DiscreteIntegrator: '<S187>/Discrete-Time Integrator5'
     *  Sum: '<S193>/Add'
     */
    u0 = (u0 + rtb_Multiply_ga_idx_0) *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;

    /* Saturate: '<S144>/Saturation1' */
    if (u0 > 1.0F) {
      rtb_Saturation1_f[2] = 1.0F;
    } else if (u0 < -1.0F) {
      rtb_Saturation1_f[2] = -1.0F;
    } else {
      rtb_Saturation1_f[2] = u0;
    }

    /* Sum: '<S192>/Add' incorporates:
     *  Gain: '<S192>/ucmd2thor'
     *  Gain: '<S192>/wcmd2thor'
     */
    rtb_Cos_j = CONTROL_PARAM.FW_TECS_W2T * rtb_Minus +
      CONTROL_PARAM.FW_TECS_U2T * rtb_Sum;

    /* DiscreteIntegrator: '<S227>/ ' */
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

    /* DiscreteIntegrator: '<S228>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_L_h0 != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm = rtb_Cos_j;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_d != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm = rtb_Cos_j;
    }

    /* Gain: '<S228>/Gain' incorporates:
     *  DiscreteIntegrator: '<S228>/Discrete-Time Integrator1'
     *  Sum: '<S228>/Sum5'
     */
    rtb_Gain_cu = (rtb_Cos_j - Controller_DW.DiscreteTimeIntegrator1_DSTA_nm) *
      188.49556F;

    /* Switch: '<S228>/Switch' incorporates:
     *  Gain: '<S228>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_MatrixConcatenate1_tmp = 0.0F;
    } else {
      rtb_MatrixConcatenate1_tmp = rtb_Gain_cu;
    }

    /* End of Switch: '<S228>/Switch' */

    /* Gain: '<S226>/Gain' */
    rtb_Saturation1_h_idx_0 = CONTROL_PARAM.FW_TECS_THOR_D *
      rtb_MatrixConcatenate1_tmp;

    /* Saturate: '<S213>/Saturation1' */
    if (rtb_Saturation1_h_idx_0 > 0.3F) {
      rtb_Saturation1_h_idx_0 = 0.3F;
    } else {
      if (rtb_Saturation1_h_idx_0 < -0.3F) {
        rtb_Saturation1_h_idx_0 = -0.3F;
      }
    }

    /* End of Saturate: '<S213>/Saturation1' */

    /* Sum: '<S144>/Sum' incorporates:
     *  Constant: '<S144>/cruise_throttle'
     *  DiscreteIntegrator: '<S227>/ '
     *  Gain: '<S192>/Gain1'
     *  Gain: '<S192>/thorttle_ff'
     *  Gain: '<S213>/P_control'
     *  Sum: '<S192>/Add1'
     *  Sum: '<S192>/Add2'
     *  Sum: '<S192>/Sum1'
     *  Sum: '<S213>/Add4'
     */
    u0 = ((((CONTROL_PARAM.FW_TECS_THOR_P * rtb_Cos_j + Controller_DW._DSTATE_d)
            + rtb_Saturation1_h_idx_0) + (rtb_Saturation1_ih + rtb_VdotPg) *
           CONTROL_PARAM.FW_TECS_THOR_FF) + CONTROL_PARAM.FW_TECS_R2T * rtb_Abs)
      + 0.5F;

    /* Saturate: '<S144>/Saturation' */
    if (u0 > 1.0F) {
      /* Saturate: '<S144>/Saturation2' */
      rtb_Saturation2_l[0] = 1.0F;
    } else if (u0 < -1.0F) {
      /* Saturate: '<S144>/Saturation2' */
      rtb_Saturation2_l[0] = -1.0F;
    } else {
      /* Saturate: '<S144>/Saturation2' */
      rtb_Saturation2_l[0] = u0;
    }

    /* End of Saturate: '<S144>/Saturation' */

    /* Saturate: '<S144>/Saturation2' incorporates:
     *  Constant: '<S144>/Constant'
     */
    rtb_Saturation2_l[1] = 0.0F;
    rtb_Saturation2_l[2] = 0.0F;

    /* Outputs for Atomic SubSystem: '<S145>/VTOL_Control_Allocation' */
#if AIRFRAME == 1

    /* Output and update for atomic system: '<S238>/VTOL1' */
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
        for (i_f = 0; i_f < 9; i_f++) {
          rtb_VariantMergeForOutportact_h[i_f] = Controller_ConstP.pooled34[i_f];
        }
        break;

       case 2:
        for (i_f = 0; i_f < 9; i_f++) {
          rtb_VariantMergeForOutportact_h[i_f] = Controller_ConstP.pooled35[i_f];
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

        /* Switch: '<S245>/Switch' incorporates:
         *  Constant: '<S244>/Constant1'
         *  Constant: '<S244>/Constant2'
         *  Constant: '<S246>/Constant1'
         *  Constant: '<S247>/Constant'
         *  DataTypeConversion: '<S246>/Data Type Conversion'
         *  Gain: '<S246>/Gain1'
         *  RelationalOperator: '<S247>/Compare'
         *  Saturate: '<S241>/Saturation4'
         *  Sum: '<S246>/Sum1'
         */
        if (rtb_BitwiseAND_a <= 3) {
          rtb_VariantMergeForOutportact_h[4] = Controller_U.FMS_Out.throttle_cmd;
        } else {
          if (rtb_Saturation2_l[0] > 1.0F) {
            /* Saturate: '<S241>/Saturation4' */
            u0_f = 1.0F;
          } else if (rtb_Saturation2_l[0] < -1.0F) {
            /* Saturate: '<S241>/Saturation4' */
            u0_f = -1.0F;
          } else {
            /* Saturate: '<S241>/Saturation4' */
            u0_f = rtb_Saturation2_l[0];
          }

          /* Saturate: '<S246>/Saturation' incorporates:
           *  Saturate: '<S241>/Saturation4'
           */
          if (u0_f < 0.0F) {
            u0_f = 0.0F;
          }

          /* End of Saturate: '<S246>/Saturation' */
          rtb_VariantMergeForOutportact_h[4] = (uint16_T)((uint32_T)fmodf(floorf
            (1000.0F * u0_f), 4.2949673E+9F) + 1000U);
        }

        /* End of Switch: '<S245>/Switch' */

        /* Saturate: '<S242>/Saturation2' */
        if (rtb_Saturation1[2] > 1.0F) {
          u0_f = 1.0F;
        } else if (rtb_Saturation1[2] < -1.0F) {
          u0_f = -1.0F;
        } else {
          u0_f = rtb_Saturation1[2];
        }

        /* End of Saturate: '<S242>/Saturation2' */

        /* Saturate: '<S248>/Saturation' */
        if (u0_f < 0.0F) {
          u0_f = 0.0F;
        }

        /* End of Saturate: '<S248>/Saturation' */

        /* DataTypeConversion: '<S248>/Data Type Conversion' incorporates:
         *  Constant: '<S248>/Constant1'
         *  Gain: '<S248>/Gain1'
         *  Sum: '<S248>/Sum1'
         */
        rtb_DataTypeConversion_i = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          u0_f), 4.2949673E+9F) + 1000U);

        /* Saturate: '<S242>/Saturation1' */
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

        /* End of Saturate: '<S242>/Saturation1' */

        /* Product: '<S242>/Multiply' incorporates:
         *  Constant: '<S242>/Effective_Matrix'
         */
        for (i_f = 0; i_f < 4; i_f++) {
          tmp_f[i_f] = Controller_ConstP.pooled16[i_f + 8] * tmp_k +
            (Controller_ConstP.pooled16[i_f + 4] * tmp_n +
             Controller_ConstP.pooled16[i_f] * tmp_c);
        }

        /* End of Product: '<S242>/Multiply' */

        /* Saturate: '<S241>/Saturation5' */
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

        /* End of Saturate: '<S241>/Saturation5' */

        /* Product: '<S241>/Multiply1' incorporates:
         *  Saturate: '<S241>/Saturation1'
         */
        for (i_f = 0; i_f < 4; i_f++) {
          /* Saturate: '<S242>/Saturation' incorporates:
           *  Gain: '<S242>/Gain'
           *  Sum: '<S242>/Add'
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

          /* End of Saturate: '<S242>/Saturation' */

          /* Saturate: '<S241>/Saturation1' incorporates:
           *  Bias: '<S241>/Bias'
           *  Gain: '<S241>/Gain1'
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

        /* End of Product: '<S241>/Multiply1' */
        break;

       default:
        for (i_f = 0; i_f < 9; i_f++) {
          rtb_VariantMergeForOutportact_h[i_f] = Controller_ConstP.pooled34[i_f];
        }
        break;
      }

      /* End of MultiPortSwitch: '<S243>/Multiport Switch' */
    }

#elif AIRFRAME == 2

    /* Output and update for atomic system: '<S238>/VTOL2' */
    {
      real32_T rtb_MatrixConcatenate_g[12];
      uint16_T rtb_DataTypeConversion_f;
      int32_T i_b;
      real32_T tmp_b[4];
      real32_T tmp_o;
      real32_T tmp_c;
      real32_T tmp_p;
      real32_T u0_b;
      uint16_T u0_o;

      /* MultiPortSwitch: '<S251>/Multiport Switch' incorporates:
       *  Constant: '<S251>/Disarm'
       *  Constant: '<S251>/Standby'
       *  Constant: '<S252>/Constant1'
       *  Constant: '<S252>/Constant11'
       *  Constant: '<S252>/Constant12'
       *  Constant: '<S252>/Constant2'
       *  Constant: '<S252>/Constant7'
       *  Constant: '<S252>/Constant8'
       *  Inport: '<Root>/FMS_Out'
       */
      switch (Controller_U.FMS_Out.status) {
       case 1:
        for (i_b = 0; i_b < 9; i_b++) {
          rtb_VariantMergeForOutportact_h[i_b] = Controller_ConstP.pooled34[i_b];
        }
        break;

       case 2:
        for (i_b = 0; i_b < 9; i_b++) {
          rtb_VariantMergeForOutportact_h[i_b] = Controller_ConstP.pooled35[i_b];
        }
        break;

       case 3:
        rtb_MatrixConcatenate_g[11] = CONTROL_PARAM.FW_YAW_EFFC *
          CONTROL_PARAM.FW_TAIL2_DIR;
        rtb_MatrixConcatenate_g[10] = CONTROL_PARAM.FW_YAW_EFFC *
          CONTROL_PARAM.FW_TAIL1_DIR;

        /* SignalConversion: '<S252>/ConcatBufferAtVector Concatenate2In2' incorporates:
         *  Constant: '<S252>/Constant10'
         *  Constant: '<S252>/Constant11'
         *  Constant: '<S252>/Constant12'
         */
        rtb_MatrixConcatenate_g[9] = 0.0F;

        /* SignalConversion: '<S252>/ConcatBufferAtVector Concatenate2In1' incorporates:
         *  Constant: '<S252>/Constant9'
         */
        rtb_MatrixConcatenate_g[8] = 0.0F;
        rtb_MatrixConcatenate_g[7] = -CONTROL_PARAM.FW_PITCH_EFFC *
          CONTROL_PARAM.FW_TAIL2_DIR;
        rtb_MatrixConcatenate_g[6] = CONTROL_PARAM.FW_PITCH_EFFC *
          CONTROL_PARAM.FW_TAIL1_DIR;

        /* SignalConversion: '<S252>/ConcatBufferAtVector Concatenate1In2' incorporates:
         *  Constant: '<S252>/Constant6'
         *  Constant: '<S252>/Constant7'
         *  Constant: '<S252>/Constant8'
         */
        rtb_MatrixConcatenate_g[5] = 0.0F;

        /* SignalConversion: '<S252>/ConcatBufferAtVector Concatenate1In1' incorporates:
         *  Constant: '<S252>/Constant5'
         */
        rtb_MatrixConcatenate_g[4] = 0.0F;

        /* SignalConversion: '<S252>/ConcatBufferAtVector ConcatenateIn4' incorporates:
         *  Constant: '<S252>/Constant4'
         */
        rtb_MatrixConcatenate_g[3] = 0.0F;

        /* SignalConversion: '<S252>/ConcatBufferAtVector ConcatenateIn3' incorporates:
         *  Constant: '<S252>/Constant3'
         */
        rtb_MatrixConcatenate_g[2] = 0.0F;
        rtb_MatrixConcatenate_g[1] = CONTROL_PARAM.FW_ROLL_EFFC *
          CONTROL_PARAM.FW_AILERON2_DIR;
        rtb_MatrixConcatenate_g[0] = CONTROL_PARAM.FW_ROLL_EFFC *
          CONTROL_PARAM.FW_AILERON1_DIR;

        /* Switch: '<S253>/Switch' incorporates:
         *  Constant: '<S252>/Constant1'
         *  Constant: '<S252>/Constant2'
         *  Constant: '<S254>/Constant1'
         *  Constant: '<S255>/Constant'
         *  DataTypeConversion: '<S254>/Data Type Conversion'
         *  Gain: '<S254>/Gain1'
         *  RelationalOperator: '<S255>/Compare'
         *  Saturate: '<S249>/Saturation4'
         *  Sum: '<S254>/Sum1'
         */
        if (rtb_BitwiseAND_a <= 3) {
          rtb_VariantMergeForOutportact_h[4] = Controller_U.FMS_Out.throttle_cmd;
        } else {
          if (rtb_Saturation2_l[0] > 1.0F) {
            /* Saturate: '<S249>/Saturation4' */
            u0_b = 1.0F;
          } else if (rtb_Saturation2_l[0] < -1.0F) {
            /* Saturate: '<S249>/Saturation4' */
            u0_b = -1.0F;
          } else {
            /* Saturate: '<S249>/Saturation4' */
            u0_b = rtb_Saturation2_l[0];
          }

          /* Saturate: '<S254>/Saturation' incorporates:
           *  Saturate: '<S249>/Saturation4'
           */
          if (u0_b < 0.0F) {
            u0_b = 0.0F;
          }

          /* End of Saturate: '<S254>/Saturation' */
          rtb_VariantMergeForOutportact_h[4] = (uint16_T)((uint32_T)fmodf(floorf
            (1000.0F * u0_b), 4.2949673E+9F) + 1000U);
        }

        /* End of Switch: '<S253>/Switch' */

        /* Saturate: '<S250>/Saturation2' */
        if (rtb_Saturation1[2] > 1.0F) {
          u0_b = 1.0F;
        } else if (rtb_Saturation1[2] < -1.0F) {
          u0_b = -1.0F;
        } else {
          u0_b = rtb_Saturation1[2];
        }

        /* End of Saturate: '<S250>/Saturation2' */

        /* Saturate: '<S256>/Saturation' */
        if (u0_b < 0.0F) {
          u0_b = 0.0F;
        }

        /* End of Saturate: '<S256>/Saturation' */

        /* DataTypeConversion: '<S256>/Data Type Conversion' incorporates:
         *  Constant: '<S256>/Constant1'
         *  Gain: '<S256>/Gain1'
         *  Sum: '<S256>/Sum1'
         */
        rtb_DataTypeConversion_f = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          u0_b), 4.2949673E+9F) + 1000U);

        /* Saturate: '<S250>/Saturation1' */
        if (rtb_Saturation2[0] > 1.0F) {
          tmp_o = 1.0F;
        } else if (rtb_Saturation2[0] < -1.0F) {
          tmp_o = -1.0F;
        } else {
          tmp_o = rtb_Saturation2[0];
        }

        if (rtb_Saturation2[1] > 1.0F) {
          tmp_c = 1.0F;
        } else if (rtb_Saturation2[1] < -1.0F) {
          tmp_c = -1.0F;
        } else {
          tmp_c = rtb_Saturation2[1];
        }

        if (rtb_Saturation2[2] > 1.0F) {
          tmp_p = 1.0F;
        } else if (rtb_Saturation2[2] < -1.0F) {
          tmp_p = -1.0F;
        } else {
          tmp_p = rtb_Saturation2[2];
        }

        /* End of Saturate: '<S250>/Saturation1' */

        /* Product: '<S250>/Multiply' incorporates:
         *  Constant: '<S250>/Effective_Matrix'
         */
        for (i_b = 0; i_b < 4; i_b++) {
          tmp_b[i_b] = Controller_ConstP.pooled16[i_b + 8] * tmp_p +
            (Controller_ConstP.pooled16[i_b + 4] * tmp_c +
             Controller_ConstP.pooled16[i_b] * tmp_o);
        }

        /* End of Product: '<S250>/Multiply' */

        /* Saturate: '<S249>/Saturation5' */
        if (rtb_Saturation1_f[0] > 1.0F) {
          tmp_o = 1.0F;
        } else if (rtb_Saturation1_f[0] < -1.0F) {
          tmp_o = -1.0F;
        } else {
          tmp_o = rtb_Saturation1_f[0];
        }

        if (rtb_Saturation1_f[1] > 1.0F) {
          tmp_c = 1.0F;
        } else if (rtb_Saturation1_f[1] < -1.0F) {
          tmp_c = -1.0F;
        } else {
          tmp_c = rtb_Saturation1_f[1];
        }

        if (rtb_Saturation1_f[2] > 1.0F) {
          tmp_p = 1.0F;
        } else if (rtb_Saturation1_f[2] < -1.0F) {
          tmp_p = -1.0F;
        } else {
          tmp_p = rtb_Saturation1_f[2];
        }

        /* End of Saturate: '<S249>/Saturation5' */

        /* Product: '<S249>/Multiply1' incorporates:
         *  Saturate: '<S249>/Saturation1'
         */
        for (i_b = 0; i_b < 4; i_b++) {
          /* Saturate: '<S250>/Saturation' incorporates:
           *  Gain: '<S250>/Gain'
           *  Sum: '<S250>/Add'
           */
          u0_b = fmodf(floorf(1000.0F * tmp_b[i_b] + (real32_T)
                              rtb_DataTypeConversion_f), 65536.0F);
          u0_o = (uint16_T)(u0_b < 0.0F ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
                            -u0_b : (int32_T)(uint16_T)u0_b);
          if (u0_o > 1900) {
            rtb_VariantMergeForOutportact_h[i_b] = 1900U;
          } else if (u0_o < 1000) {
            rtb_VariantMergeForOutportact_h[i_b] = 1000U;
          } else {
            rtb_VariantMergeForOutportact_h[i_b] = u0_o;
          }

          /* End of Saturate: '<S250>/Saturation' */

          /* Saturate: '<S249>/Saturation1' incorporates:
           *  Bias: '<S249>/Bias'
           *  Gain: '<S249>/Gain1'
           */
          u0_b = 500.0F * (rtb_MatrixConcatenate_g[i_b + 8] * tmp_p +
                           (rtb_MatrixConcatenate_g[i_b + 4] * tmp_c +
                            rtb_MatrixConcatenate_g[i_b] * tmp_o)) + 1500.0F;
          if (u0_b > 2000.0F) {
            u0_b = 2000.0F;
          } else {
            if (u0_b < 1000.0F) {
              u0_b = 1000.0F;
            }
          }

          rtb_VariantMergeForOutportact_h[i_b + 5] = (uint16_T)fmodf(floorf(u0_b),
            65536.0F);
        }

        /* End of Product: '<S249>/Multiply1' */
        break;

       default:
        for (i_b = 0; i_b < 9; i_b++) {
          rtb_VariantMergeForOutportact_h[i_b] = Controller_ConstP.pooled34[i_b];
        }
        break;
      }

      /* End of MultiPortSwitch: '<S251>/Multiport Switch' */
    }

#endif

    /* End of Outputs for SubSystem: '<S145>/VTOL_Control_Allocation' */
    for (i = 0; i < 9; i++) {
      /* Outport: '<Root>/Control_Out' incorporates:
       *  Reshape: '<S237>/Reshape'
       */
      Controller_Y.Control_Out.actuator_cmd[i] =
        rtb_VariantMergeForOutportact_h[i];
    }

    for (i = 0; i < 7; i++) {
      /* Outport: '<Root>/Control_Out' incorporates:
       *  Reshape: '<S237>/Reshape'
       */
      Controller_Y.Control_Out.actuator_cmd[i + 9] = 0U;
    }

    /* Product: '<S159>/Multiply' incorporates:
     *  Constant: '<S159>/gain1'
     *  Constant: '<S159>/gain2'
     *  Constant: '<S159>/gain3'
     *  DiscreteIntegrator: '<S157>/Discrete-Time Integrator5'
     */
    rtb_Multiply_ga_idx_0 = CONTROL_PARAM.MC_ROLL_RATE_I *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0];
    rtb_Saturation1_ih = CONTROL_PARAM.MC_PITCH_RATE_I *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1];
    rtb_VdotPg = CONTROL_PARAM.MC_YAW_RATE_I *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2];

    /* Product: '<S182>/Multiply1' incorporates:
     *  Constant: '<S182>/const1'
     *  DiscreteIntegrator: '<S181>/Integrator'
     */
    rtb_Saturation1_h_idx_0 = Controller_DW.Integrator_DSTATE_f * 0.05F;

    /* Switch: '<S172>/Switch' incorporates:
     *  Constant: '<S172>/Zero'
     *  Constant: '<S175>/Constant'
     *  RelationalOperator: '<S175>/Compare'
     */
    if (rtb_BitwiseAND_a <= 3) {
      rtb_MatrixConcatenate1_tmp = 0.0F;
    } else {
      rtb_MatrixConcatenate1_tmp = Controller_U.FMS_Out.w_cmd;
    }

    /* End of Switch: '<S172>/Switch' */

    /* Sum: '<S182>/Add' incorporates:
     *  DiscreteIntegrator: '<S181>/Integrator1'
     *  Sum: '<S181>/Subtract'
     */
    rtb_Cos1_d = (Controller_DW.Integrator1_DSTATE_i -
                  rtb_MatrixConcatenate1_tmp) + rtb_Saturation1_h_idx_0;

    /* Signum: '<S182>/Sign' */
    if (rtb_Cos1_d < 0.0F) {
      rtb_Divide_i_idx_0 = -1.0F;
    } else if (rtb_Cos1_d > 0.0F) {
      rtb_Divide_i_idx_0 = 1.0F;
    } else {
      rtb_Divide_i_idx_0 = rtb_Cos1_d;
    }

    /* End of Signum: '<S182>/Sign' */

    /* Sum: '<S182>/Add2' incorporates:
     *  Abs: '<S182>/Abs'
     *  Gain: '<S182>/Gain'
     *  Gain: '<S182>/Gain1'
     *  Product: '<S182>/Multiply2'
     *  Product: '<S182>/Multiply3'
     *  Sqrt: '<S182>/Sqrt'
     *  Sum: '<S182>/Add1'
     *  Sum: '<S182>/Subtract'
     */
    rtb_Divide_i_idx_0 = (sqrtf((8.0F * fabsf(rtb_Cos1_d) +
      Controller_ConstB.d_m) * Controller_ConstB.d_m) - Controller_ConstB.d_m) *
      0.5F * rtb_Divide_i_idx_0 + rtb_Saturation1_h_idx_0;

    /* Sum: '<S182>/Add4' */
    rtb_Saturation1_h_idx_0 += rtb_Cos1_d - rtb_Divide_i_idx_0;

    /* Sum: '<S182>/Add3' */
    rtb_Abs = rtb_Cos1_d + Controller_ConstB.d_m;

    /* Sum: '<S182>/Subtract1' */
    rtb_Cos1_d -= Controller_ConstB.d_m;

    /* Signum: '<S182>/Sign1' */
    if (rtb_Abs < 0.0F) {
      rtb_Abs = -1.0F;
    } else {
      if (rtb_Abs > 0.0F) {
        rtb_Abs = 1.0F;
      }
    }

    /* End of Signum: '<S182>/Sign1' */

    /* Signum: '<S182>/Sign2' */
    if (rtb_Cos1_d < 0.0F) {
      rtb_Cos1_d = -1.0F;
    } else {
      if (rtb_Cos1_d > 0.0F) {
        rtb_Cos1_d = 1.0F;
      }
    }

    /* End of Signum: '<S182>/Sign2' */

    /* Sum: '<S182>/Add5' incorporates:
     *  Gain: '<S182>/Gain2'
     *  Product: '<S182>/Multiply4'
     *  Sum: '<S182>/Subtract2'
     */
    rtb_Divide_i_idx_0 += (rtb_Abs - rtb_Cos1_d) * 0.5F *
      rtb_Saturation1_h_idx_0;

    /* Update for DiscreteIntegrator: '<S189>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S189>/Gain'
     *  Sum: '<S189>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_L_eo = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_a += (rtb_Divide_gn -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_a) * 31.415926F * 0.002F;

    /* Update for DiscreteIntegrator: '<S188>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S188>/Gain'
     *  Sum: '<S188>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_o = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTA_a2 += ((real32_T)rtb_Relay -
      Controller_DW.DiscreteTimeIntegrator5_DSTA_a2) * 6.28318548F * 0.002F;

    /* Update for DiscreteIntegrator: '<S181>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S181>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_i += 0.002F *
      Controller_DW.Integrator_DSTATE_f;

    /* Update for DiscreteIntegrator: '<S184>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S184>/ki'
     *  Product: '<S184>/Multiply'
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

    /* End of Update for DiscreteIntegrator: '<S184>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S186>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_i = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTA_ld += 0.002F * rtb_Gain_it;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_h = (int8_T)
      rtb_LogicalOperator_b3;

    /* Update for DiscreteIntegrator: '<S224>/ ' incorporates:
     *  Gain: '<S224>/Gain3'
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

    /* End of Update for DiscreteIntegrator: '<S224>/ ' */

    /* Update for DiscreteIntegrator: '<S225>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_f = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_e += 0.002F * rtb_Gain_il;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_b = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S157>/Discrete-Time Integrator5' */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_b = 0U;

    /* Update for DiscreteIntegrator: '<S159>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_PrevRe_o = (int8_T)
      rtb_LogicalOperator_m;

    /* Update for DiscreteIntegrator: '<S161>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_L_h2 = 0U;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_l = (int8_T)
      rtb_LogicalOperator_m;

    /* Update for DiscreteIntegrator: '<S187>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S187>/Gain'
     *  Sum: '<S187>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_g = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_j += (rtb_Saturation_ov -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j) * 12.566371F * 0.002F;

    /* Update for DiscreteIntegrator: '<S157>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S157>/Gain'
     *  Sum: '<S157>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0] += (rtb_Add_c -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S159>/Discrete-Time Integrator' */
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

    /* Update for DiscreteIntegrator: '<S161>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[0] += 0.002F *
      rtb_DiscreteTimeIntegrator1_k1[0];

    /* Update for DiscreteIntegrator: '<S199>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S199>/gain1'
     *  Product: '<S199>/Multiply'
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

    /* Update for DiscreteIntegrator: '<S157>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S157>/Gain'
     *  Sum: '<S157>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1] += (rtb_FF_limit_idx_1 -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S159>/Discrete-Time Integrator' */
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

    /* Update for DiscreteIntegrator: '<S161>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[1] += 0.002F *
      rtb_DiscreteTimeIntegrator1_k1[1];

    /* Update for DiscreteIntegrator: '<S199>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S199>/gain2'
     *  Product: '<S199>/Multiply'
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

    /* Update for DiscreteIntegrator: '<S157>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S157>/Gain'
     *  Sum: '<S157>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2] += (rtb_FF_limit_idx_2 -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S159>/Discrete-Time Integrator' */
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

    /* Update for DiscreteIntegrator: '<S161>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[2] += 0.002F *
      rtb_DiscreteTimeIntegrator1_k1[2];

    /* Update for DiscreteIntegrator: '<S199>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S199>/gain3'
     *  Product: '<S199>/Multiply'
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

    /* Update for DiscreteIntegrator: '<S227>/ ' incorporates:
     *  Gain: '<S227>/Gain'
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

    /* End of Update for DiscreteIntegrator: '<S227>/ ' */

    /* Update for DiscreteIntegrator: '<S228>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_L_h0 = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTA_nm += 0.002F * rtb_Gain_cu;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_d = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Signum: '<S182>/Sign6' incorporates:
     *  Signum: '<S182>/Sign5'
     */
    if (rtb_Divide_i_idx_0 < 0.0F) {
      rtb_FF_limit_idx_1 = -1.0F;

      /* Signum: '<S182>/Sign5' */
      rtb_FF_limit_idx_2 = -1.0F;
    } else if (rtb_Divide_i_idx_0 > 0.0F) {
      rtb_FF_limit_idx_1 = 1.0F;

      /* Signum: '<S182>/Sign5' */
      rtb_FF_limit_idx_2 = 1.0F;
    } else {
      rtb_FF_limit_idx_1 = rtb_Divide_i_idx_0;

      /* Signum: '<S182>/Sign5' */
      rtb_FF_limit_idx_2 = rtb_Divide_i_idx_0;
    }

    /* End of Signum: '<S182>/Sign6' */

    /* Sum: '<S182>/Add6' */
    rtb_Abs = rtb_Divide_i_idx_0 + Controller_ConstB.d_m;

    /* Sum: '<S182>/Subtract3' */
    rtb_Add_c = rtb_Divide_i_idx_0 - Controller_ConstB.d_m;

    /* Signum: '<S182>/Sign3' */
    if (rtb_Abs < 0.0F) {
      rtb_Abs = -1.0F;
    } else {
      if (rtb_Abs > 0.0F) {
        rtb_Abs = 1.0F;
      }
    }

    /* End of Signum: '<S182>/Sign3' */

    /* Signum: '<S182>/Sign4' */
    if (rtb_Add_c < 0.0F) {
      rtb_Add_c = -1.0F;
    } else {
      if (rtb_Add_c > 0.0F) {
        rtb_Add_c = 1.0F;
      }
    }

    /* End of Signum: '<S182>/Sign4' */

    /* Update for DiscreteIntegrator: '<S181>/Integrator' incorporates:
     *  Constant: '<S182>/const'
     *  Gain: '<S182>/Gain3'
     *  Product: '<S182>/Divide'
     *  Product: '<S182>/Multiply5'
     *  Product: '<S182>/Multiply6'
     *  Sum: '<S182>/Subtract4'
     *  Sum: '<S182>/Subtract5'
     *  Sum: '<S182>/Subtract6'
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
          rtb_VariantMergeForOutportactua[i_n] = Controller_ConstP.pooled34[i_n];
        }
        break;

       case 2:
        for (i_n = 0; i_n < 9; i_n++) {
          rtb_VariantMergeForOutportactua[i_n] = Controller_ConstP.pooled35[i_n];
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
          rtb_VariantMergeForOutportactua[i_n] = Controller_ConstP.pooled34[i_n];
        }
        break;
      }

      /* End of MultiPortSwitch: '<S66>/Multiport Switch' */
    }

#elif AIRFRAME == 2

    /* Output and update for atomic system: '<S61>/VTOL2' */
    {
      uint16_T rtb_DataTypeConversion_b1;
      real32_T rtb_MatrixConcatenate_a[12];
      int32_T i_m;
      real32_T tmp_m;
      real32_T tmp_p;
      real32_T tmp_j;
      real32_T u0_m;
      uint16_T u0_p;

      /* MultiPortSwitch: '<S72>/Multiport Switch' incorporates:
       *  Constant: '<S72>/Disarm'
       *  Constant: '<S72>/Standby'
       *  Constant: '<S73>/Constant1'
       *  Constant: '<S73>/Constant11'
       *  Constant: '<S73>/Constant12'
       *  Constant: '<S73>/Constant2'
       *  Constant: '<S73>/Constant7'
       *  Constant: '<S73>/Constant8'
       *  Inport: '<Root>/FMS_Out'
       *  Reshape: '<S63>/Reshape'
       *  Saturate: '<S70>/Saturation1'
       */
      switch (Controller_U.FMS_Out.status) {
       case 1:
        for (i_m = 0; i_m < 9; i_m++) {
          rtb_VariantMergeForOutportactua[i_m] = Controller_ConstP.pooled34[i_m];
        }
        break;

       case 2:
        for (i_m = 0; i_m < 9; i_m++) {
          rtb_VariantMergeForOutportactua[i_m] = Controller_ConstP.pooled35[i_m];
        }
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
        rtb_DataTypeConversion_b1 = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          u0_m), 4.2949673E+9F) + 1000U);
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
        rtb_VariantMergeForOutportactua[4] =
          Controller_ConstB.VTOL2_p.DataTypeConversion;
        for (i_m = 0; i_m < 4; i_m++) {
          /* Saturate: '<S71>/Saturation' incorporates:
           *  Constant: '<S71>/Effective_Matrix'
           *  Gain: '<S71>/Gain'
           *  Product: '<S71>/Multiply'
           *  Sum: '<S71>/Add'
           */
          u0_m = fmodf(floorf(1000.0F * (Controller_ConstP.pooled16[i_m + 8] *
            tmp_j + (Controller_ConstP.pooled16[i_m + 4] * tmp_p +
                     Controller_ConstP.pooled16[i_m] * tmp_m)) + (real32_T)
                              rtb_DataTypeConversion_b1), 65536.0F);
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
            u0_m = 2000.0F;
          } else {
            if (u0_m < 1000.0F) {
              u0_m = 1000.0F;
            }
          }

          rtb_VariantMergeForOutportactua[i_m + 5] = (uint16_T)fmodf(floorf(u0_m),
            65536.0F);
        }
        break;

       default:
        for (i_m = 0; i_m < 9; i_m++) {
          rtb_VariantMergeForOutportactua[i_m] = Controller_ConstP.pooled34[i_m];
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
       *  DiscreteIntegrator: '<S113>/Integrator'
       *  DiscreteIntegrator: '<S113>/Integrator1'
       *  DiscreteIntegrator: '<S118>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S120>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S136>/Integrator'
       *  DiscreteIntegrator: '<S136>/Integrator1'
       *  DiscreteIntegrator: '<S139>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S141>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S89>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S91>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S93>/Discrete-Time Integrator1'
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
    /* DiscreteIntegrator: '<S91>/Discrete-Time Integrator' */
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

    /* Trigonometry: '<S115>/Trigonometric Function1' incorporates:
     *  Gain: '<S114>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1[0] = arm_cos_f32(-Controller_U.INS_Out.psi);

    /* Trigonometry: '<S115>/Trigonometric Function' incorporates:
     *  Gain: '<S114>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1[1] = arm_sin_f32(-Controller_U.INS_Out.psi);

    /* SignalConversion: '<S115>/ConcatBufferAtVector Concatenate1In3' incorporates:
     *  Constant: '<S115>/Constant3'
     */
    rtb_MatrixConcatenate1[2] = 0.0F;

    /* Gain: '<S115>/Gain' incorporates:
     *  Gain: '<S114>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S115>/Trigonometric Function2'
     */
    rtb_MatrixConcatenate1[3] = -arm_sin_f32(-Controller_U.INS_Out.psi);

    /* Trigonometry: '<S115>/Trigonometric Function3' incorporates:
     *  Gain: '<S114>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1[4] = arm_cos_f32(-Controller_U.INS_Out.psi);

    /* SignalConversion: '<S115>/ConcatBufferAtVector Concatenate2In3' incorporates:
     *  Constant: '<S115>/Constant4'
     */
    rtb_MatrixConcatenate1[5] = 0.0F;

    /* SignalConversion: '<S115>/ConcatBufferAtVector ConcatenateIn3' */
    rtb_MatrixConcatenate1[6] = Controller_ConstB.VectorConcatenate3[0];
    rtb_MatrixConcatenate1[7] = Controller_ConstB.VectorConcatenate3[1];
    rtb_MatrixConcatenate1[8] = Controller_ConstB.VectorConcatenate3[2];

    /* Product: '<S112>/Multiply' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  SignalConversion: '<S112>/TmpSignal ConversionAtMultiplyInport2'
     */
    for (i = 0; i < 3; i++) {
      rtb_MatrixConcatenate1_0[i] = rtb_MatrixConcatenate1[i + 3] *
        Controller_U.INS_Out.ve + rtb_MatrixConcatenate1[i] *
        Controller_U.INS_Out.vn;
    }

    /* End of Product: '<S112>/Multiply' */

    /* Sum: '<S109>/Sum' incorporates:
     *  DiscreteIntegrator: '<S113>/Integrator1'
     */
    rtb_Divide_i_idx_0 = Controller_DW.Integrator1_DSTATE[0] -
      rtb_MatrixConcatenate1_0[0];
    rtb_Cos_j = Controller_DW.Integrator1_DSTATE[1] - rtb_MatrixConcatenate1_0[1];

    /* DiscreteIntegrator: '<S118>/Discrete-Time Integrator' */
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

    /* DiscreteIntegrator: '<S120>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] = rtb_Divide_i_idx_0;
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] = rtb_Cos_j;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevRes != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] = rtb_Divide_i_idx_0;
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] = rtb_Cos_j;
    }

    /* Gain: '<S120>/Gain' incorporates:
     *  DiscreteIntegrator: '<S120>/Discrete-Time Integrator1'
     *  Sum: '<S120>/Sum5'
     */
    rtb_Saturation1_h_idx_0 = (rtb_Divide_i_idx_0 -
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[0]) * 62.831852F;
    rtb_Divide_gn = (rtb_Cos_j - Controller_DW.DiscreteTimeIntegrator1_DSTATE[1])
      * 62.831852F;

    /* Switch: '<S120>/Switch' incorporates:
     *  Gain: '<S120>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_Gain_ms = 0.0F;
      rtb_Gain_cu = 0.0F;
    } else {
      rtb_Gain_ms = rtb_Saturation1_h_idx_0;
      rtb_Gain_cu = rtb_Divide_gn;
    }

    /* End of Switch: '<S120>/Switch' */

    /* Product: '<S117>/Multiply' incorporates:
     *  Constant: '<S117>/kd'
     */
    rtb_Divide_i_idx_1 = CONTROL_PARAM.MC_VEL_XY_D * rtb_Gain_ms;

    /* Saturate: '<S117>/Saturation' */
    if (rtb_Divide_i_idx_1 > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
      rtb_Divide_i_idx_1 = CONTROL_PARAM.MC_VEL_XY_D_MAX;
    } else {
      if (rtb_Divide_i_idx_1 < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
        rtb_Divide_i_idx_1 = CONTROL_PARAM.MC_VEL_XY_D_MIN;
      }
    }

    rtb_Gain_ms = rtb_Divide_i_idx_1;

    /* Product: '<S117>/Multiply' incorporates:
     *  Constant: '<S117>/kd'
     */
    rtb_Divide_i_idx_1 = CONTROL_PARAM.MC_VEL_XY_D * rtb_Gain_cu;

    /* Saturate: '<S117>/Saturation' */
    if (rtb_Divide_i_idx_1 > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
      rtb_Divide_i_idx_1 = CONTROL_PARAM.MC_VEL_XY_D_MAX;
    } else {
      if (rtb_Divide_i_idx_1 < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
        rtb_Divide_i_idx_1 = CONTROL_PARAM.MC_VEL_XY_D_MIN;
      }
    }

    /* Switch: '<S111>/Switch' incorporates:
     *  Constant: '<S119>/kp'
     *  Constant: '<S121>/Constant'
     *  Constant: '<S123>/Constant'
     *  Constant: '<S124>/Constant'
     *  DiscreteIntegrator: '<S118>/Discrete-Time Integrator'
     *  Product: '<S119>/Multiply'
     *  Product: '<S122>/Multiply2'
     *  Product: '<S122>/Multiply3'
     *  RelationalOperator: '<S121>/Compare'
     *  RelationalOperator: '<S123>/Compare'
     *  RelationalOperator: '<S124>/Compare'
     *  S-Function (sfix_bitop): '<S122>/cmd_ax valid'
     *  S-Function (sfix_bitop): '<S122>/cmd_ay valid'
     *  S-Function (sfix_bitop): '<S122>/cmd_u valid'
     *  S-Function (sfix_bitop): '<S122>/cmd_v valid'
     *  Sum: '<S110>/Add'
     *  Sum: '<S122>/Sum1'
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

    /* End of Switch: '<S111>/Switch' */

    /* Trigonometry: '<S108>/Atan' incorporates:
     *  Constant: '<S108>/g'
     *  Gain: '<S108>/Gain1'
     *  Gain: '<S108>/gain'
     *  Product: '<S108>/Divide'
     */
    u0 = atanf(1.1F * rtb_Gain_cu / 9.8055F);
    rtb_Gain_cu = atanf(1.1F * -rtb_Gain_ms / 9.8055F);

    /* Switch: '<S99>/Switch' incorporates:
     *  Constant: '<S106>/Constant'
     *  Logic: '<S99>/Logical Operator'
     *  RelationalOperator: '<S105>/Compare'
     *  RelationalOperator: '<S106>/Compare'
     *  Saturate: '<S108>/Saturation'
     *  Switch: '<S99>/Switch1'
     */
    if ((rtb_BitwiseAND_a == 3) || (rtb_BitwiseAND_a == 4)) {
      rtb_Gain_ms = Controller_U.FMS_Out.phi_cmd;
      rtb_Gain_cu = Controller_U.FMS_Out.theta_cmd;
    } else if (rtb_BitwiseAND_a == 6) {
      /* Switch: '<S107>/Switch' incorporates:
       *  S-Function (sfix_bitop): '<S107>/cmd_phi valid'
       *  S-Function (sfix_bitop): '<S107>/cmd_theta valid'
       *  Saturate: '<S108>/Saturation'
       *  Switch: '<S99>/Switch1'
       */
      if ((Controller_U.FMS_Out.cmd_mask & 8) > 0) {
        rtb_Gain_ms = Controller_U.FMS_Out.phi_cmd;
      } else if (u0 > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S108>/Saturation' */
        rtb_Gain_ms = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else if (u0 < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S108>/Saturation' */
        rtb_Gain_ms = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        rtb_Gain_ms = u0;
      }

      if ((Controller_U.FMS_Out.cmd_mask & 16) > 0) {
        rtb_Gain_cu = Controller_U.FMS_Out.theta_cmd;
      } else if (rtb_Gain_cu > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S108>/Saturation' */
        rtb_Gain_cu = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_Gain_cu < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Saturate: '<S108>/Saturation' */
          rtb_Gain_cu = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        }
      }

      /* End of Switch: '<S107>/Switch' */
    } else {
      if (u0 > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S108>/Saturation' incorporates:
         *  Switch: '<S99>/Switch1'
         */
        rtb_Gain_ms = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else if (u0 < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S108>/Saturation' incorporates:
         *  Switch: '<S99>/Switch1'
         */
        rtb_Gain_ms = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        /* Switch: '<S99>/Switch1' incorporates:
         *  Saturate: '<S108>/Saturation'
         */
        rtb_Gain_ms = u0;
      }

      /* Saturate: '<S108>/Saturation' */
      if (rtb_Gain_cu > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Switch: '<S99>/Switch1' */
        rtb_Gain_cu = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_Gain_cu < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Switch: '<S99>/Switch1' */
          rtb_Gain_cu = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        }
      }
    }

    /* End of Switch: '<S99>/Switch' */

    /* Sum: '<S100>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_i_idx_1 = rtb_Gain_ms - Controller_U.INS_Out.phi;

    /* Product: '<S103>/Divide1' incorporates:
     *  Abs: '<S103>/Abs'
     *  Constant: '<S103>/const2'
     */
    rtb_Gain_it = fabsf(rtb_Divide_i_idx_1) / 0.002F;

    /* Product: '<S103>/Divide' incorporates:
     *  Constant: '<S101>/Constant1'
     *  Constant: '<S103>/const1'
     *  Math: '<S103>/Square'
     *  SignalConversion: '<S103>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_MatrixConcatenate1_tmp = 9.5993F / (CONTROL_PARAM.MC_ROLL_P *
      CONTROL_PARAM.MC_ROLL_P);

    /* Signum: '<S103>/Sign' */
    if (rtb_Divide_i_idx_1 < 0.0F) {
      rtb_FF_limit_idx_1 = -1.0F;
    } else if (rtb_Divide_i_idx_1 > 0.0F) {
      rtb_FF_limit_idx_1 = 1.0F;
    } else {
      rtb_FF_limit_idx_1 = rtb_Divide_i_idx_1;
    }

    /* Switch: '<S103>/Switch' incorporates:
     *  Constant: '<S101>/Constant1'
     *  Gain: '<S103>/Gain1'
     *  Gain: '<S103>/Gain2'
     *  Logic: '<S103>/Logical Operator'
     *  Product: '<S103>/Divide'
     *  Product: '<S103>/Multiply'
     *  Product: '<S103>/Multiply1'
     *  Product: '<S103>/Multiply2'
     *  Product: '<S103>/Multiply3'
     *  RelationalOperator: '<S103>/Relational Operator'
     *  RelationalOperator: '<S103>/Relational Operator2'
     *  SignalConversion: '<S103>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S103>/Sqrt'
     *  Sum: '<S103>/Subtract'
     */
    if ((rtb_Divide_i_idx_1 <= rtb_MatrixConcatenate1_tmp) &&
        (rtb_Divide_i_idx_1 >= -rtb_MatrixConcatenate1_tmp)) {
      rtb_FF_limit_idx_1 = rtb_Divide_i_idx_1 * CONTROL_PARAM.MC_ROLL_P;
    } else {
      rtb_FF_limit_idx_1 *= sqrtf((rtb_FF_limit_idx_1 * rtb_Divide_i_idx_1 -
        0.5F * rtb_MatrixConcatenate1_tmp) * Controller_ConstB.Gain);
    }

    /* Gain: '<S103>/Gain3' */
    rtb_MatrixConcatenate1_tmp = -rtb_Gain_it;

    /* Switch: '<S104>/Switch' incorporates:
     *  Gain: '<S103>/Gain3'
     *  RelationalOperator: '<S104>/UpperRelop'
     */
    if (rtb_FF_limit_idx_1 >= -rtb_Gain_it) {
      rtb_MatrixConcatenate1_tmp = rtb_FF_limit_idx_1;
    }

    /* Switch: '<S104>/Switch2' incorporates:
     *  RelationalOperator: '<S104>/LowerRelop1'
     */
    if (rtb_FF_limit_idx_1 <= rtb_Gain_it) {
      rtb_Gain_it = rtb_MatrixConcatenate1_tmp;
    }

    /* Saturate: '<S84>/Saturation1' */
    if (rtb_Gain_it > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_Gain_it = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_Gain_it < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_Gain_it = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    rtb_Saturation_ov = rtb_Gain_it;

    /* Sum: '<S100>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S103>/Divide1'
     */
    rtb_Divide_i_idx_1 = rtb_Gain_cu - Controller_U.INS_Out.theta;

    /* Product: '<S103>/Divide1' incorporates:
     *  Abs: '<S103>/Abs'
     *  Constant: '<S103>/const2'
     */
    rtb_Gain_it = fabsf(rtb_Divide_i_idx_1) / 0.002F;

    /* Product: '<S103>/Divide' incorporates:
     *  Constant: '<S101>/Constant2'
     *  Constant: '<S103>/const1'
     *  Math: '<S103>/Square'
     *  SignalConversion: '<S103>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_MatrixConcatenate1_tmp = 9.5993F / (CONTROL_PARAM.MC_PITCH_P *
      CONTROL_PARAM.MC_PITCH_P);

    /* Signum: '<S103>/Sign' */
    if (rtb_Divide_i_idx_1 < 0.0F) {
      rtb_FF_limit_idx_1 = -1.0F;
    } else if (rtb_Divide_i_idx_1 > 0.0F) {
      rtb_FF_limit_idx_1 = 1.0F;
    } else {
      rtb_FF_limit_idx_1 = rtb_Divide_i_idx_1;
    }

    /* Switch: '<S103>/Switch' incorporates:
     *  Constant: '<S101>/Constant2'
     *  Gain: '<S103>/Gain1'
     *  Gain: '<S103>/Gain2'
     *  Logic: '<S103>/Logical Operator'
     *  Product: '<S103>/Divide'
     *  Product: '<S103>/Multiply'
     *  Product: '<S103>/Multiply1'
     *  Product: '<S103>/Multiply2'
     *  Product: '<S103>/Multiply3'
     *  RelationalOperator: '<S103>/Relational Operator'
     *  RelationalOperator: '<S103>/Relational Operator2'
     *  SignalConversion: '<S103>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S103>/Sqrt'
     *  Sum: '<S103>/Subtract'
     */
    if ((rtb_Divide_i_idx_1 <= rtb_MatrixConcatenate1_tmp) &&
        (rtb_Divide_i_idx_1 >= -rtb_MatrixConcatenate1_tmp)) {
      rtb_FF_limit_idx_1 = rtb_Divide_i_idx_1 * CONTROL_PARAM.MC_PITCH_P;
    } else {
      rtb_FF_limit_idx_1 *= sqrtf((rtb_FF_limit_idx_1 * rtb_Divide_i_idx_1 -
        0.5F * rtb_MatrixConcatenate1_tmp) * Controller_ConstB.Gain);
    }

    /* Gain: '<S103>/Gain3' */
    rtb_MatrixConcatenate1_tmp = -rtb_Gain_it;

    /* Switch: '<S104>/Switch' incorporates:
     *  Gain: '<S103>/Gain3'
     *  RelationalOperator: '<S104>/UpperRelop'
     */
    if (rtb_FF_limit_idx_1 >= -rtb_Gain_it) {
      rtb_MatrixConcatenate1_tmp = rtb_FF_limit_idx_1;
    }

    /* Switch: '<S104>/Switch2' incorporates:
     *  RelationalOperator: '<S104>/LowerRelop1'
     */
    if (rtb_FF_limit_idx_1 <= rtb_Gain_it) {
      rtb_Gain_it = rtb_MatrixConcatenate1_tmp;
    }

    /* Saturate: '<S84>/Saturation1' */
    if (rtb_Gain_it > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_Gain_it = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_Gain_it < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_Gain_it = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    /* Saturate: '<S84>/Saturation' */
    if (Controller_U.FMS_Out.psi_rate_cmd > CONTROL_PARAM.MC_R_CMD_LIM) {
      rtb_Multiply_ga_idx_0 = CONTROL_PARAM.MC_R_CMD_LIM;
    } else if (Controller_U.FMS_Out.psi_rate_cmd < -CONTROL_PARAM.MC_R_CMD_LIM)
    {
      rtb_Multiply_ga_idx_0 = -CONTROL_PARAM.MC_R_CMD_LIM;
    } else {
      rtb_Multiply_ga_idx_0 = Controller_U.FMS_Out.psi_rate_cmd;
    }

    /* End of Saturate: '<S84>/Saturation' */

    /* Trigonometry: '<S94>/Sin' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_i_idx_2 = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S94>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Add_c = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Product: '<S94>/Multiply3' incorporates:
     *  Trigonometry: '<S94>/Cos1'
     *  Trigonometry: '<S94>/Sin'
     */
    rtb_FF_limit_idx_1 = rtb_Divide_i_idx_2 * rtb_Add_c * rtb_Multiply_ga_idx_0;

    /* Trigonometry: '<S94>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_FF_limit_idx_2 = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Product: '<S94>/Multiply1' incorporates:
     *  Trigonometry: '<S94>/Cos'
     */
    rtb_Gain_ms = rtb_FF_limit_idx_2 * rtb_Gain_it;

    /* Product: '<S94>/Multiply4' incorporates:
     *  Trigonometry: '<S94>/Sin'
     */
    rtb_Divide_i_idx_2 *= rtb_Gain_it;

    /* Switch: '<S85>/Switch' incorporates:
     *  Constant: '<S95>/Constant'
     *  Constant: '<S96>/Constant'
     *  RelationalOperator: '<S95>/Compare'
     *  RelationalOperator: '<S96>/Compare'
     *  Switch: '<S85>/Switch1'
     */
    if (rtb_BitwiseAND_a == 2) {
      rtb_DiscreteTimeIntegrator1_k1[0] = Controller_U.FMS_Out.p_cmd;
      rtb_DiscreteTimeIntegrator1_k1[1] = Controller_U.FMS_Out.q_cmd;
      rtb_DiscreteTimeIntegrator1_k1[2] = Controller_U.FMS_Out.r_cmd;
    } else if (rtb_BitwiseAND_a == 6) {
      /* Switch: '<S97>/Switch' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Product: '<S94>/Multiply'
       *  Product: '<S94>/Multiply1'
       *  Product: '<S94>/Multiply5'
       *  S-Function (sfix_bitop): '<S97>/cmd_p valid'
       *  S-Function (sfix_bitop): '<S97>/cmd_q valid'
       *  S-Function (sfix_bitop): '<S97>/cmd_r valid'
       *  Sum: '<S94>/Add'
       *  Sum: '<S94>/Add1'
       *  Sum: '<S94>/Add2'
       *  Switch: '<S85>/Switch1'
       *  Trigonometry: '<S94>/Cos'
       *  Trigonometry: '<S94>/Cos1'
       *  Trigonometry: '<S94>/Sin1'
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

      /* End of Switch: '<S97>/Switch' */
    } else {
      /* Switch: '<S85>/Switch1' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Product: '<S94>/Multiply'
       *  Product: '<S94>/Multiply3'
       *  Product: '<S94>/Multiply5'
       *  Sum: '<S94>/Add'
       *  Sum: '<S94>/Add1'
       *  Sum: '<S94>/Add2'
       *  Trigonometry: '<S94>/Cos'
       *  Trigonometry: '<S94>/Cos1'
       *  Trigonometry: '<S94>/Sin1'
       */
      rtb_DiscreteTimeIntegrator1_k1[0] = rtb_Saturation_ov - arm_sin_f32
        (Controller_U.INS_Out.theta) * rtb_Multiply_ga_idx_0;
      rtb_DiscreteTimeIntegrator1_k1[1] = rtb_Gain_ms + rtb_FF_limit_idx_1;
      rtb_DiscreteTimeIntegrator1_k1[2] = rtb_FF_limit_idx_2 * rtb_Add_c *
        rtb_Multiply_ga_idx_0 - rtb_Divide_i_idx_2;
    }

    /* End of Switch: '<S85>/Switch' */

    /* Sum: '<S86>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Add_c = rtb_DiscreteTimeIntegrator1_k1[0] - Controller_U.INS_Out.p;
    rtb_FF_limit_idx_1 = rtb_DiscreteTimeIntegrator1_k1[1] -
      Controller_U.INS_Out.q;
    rtb_FF_limit_idx_2 = rtb_DiscreteTimeIntegrator1_k1[2] -
      Controller_U.INS_Out.r;

    /* DiscreteIntegrator: '<S89>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] = rtb_Add_c;
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] = rtb_FF_limit_idx_1;
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] = rtb_FF_limit_idx_2;
    }

    /* DiscreteIntegrator: '<S93>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S89>/Discrete-Time Integrator5'
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

    /* Gain: '<S93>/Gain' incorporates:
     *  DiscreteIntegrator: '<S89>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S93>/Discrete-Time Integrator1'
     *  Sum: '<S93>/Sum5'
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

    /* Gain: '<S134>/Gain' incorporates:
     *  DiscreteIntegrator: '<S136>/Integrator1'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S134>/Sum1'
     */
    rtb_Gain_it = -(Controller_DW.Integrator1_DSTATE_e - Controller_U.INS_Out.vd);
    Controller_B.Constant = CONTROL_PARAM.MC_VEL_Z_I_MIN;

    /* DiscreteIntegrator: '<S139>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S139>/Constant'
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

    /* DiscreteIntegrator: '<S141>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_d != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i = rtb_Gain_it;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_Prev_ks != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i = rtb_Gain_it;
    }

    /* Gain: '<S141>/Gain' incorporates:
     *  DiscreteIntegrator: '<S141>/Discrete-Time Integrator1'
     *  Sum: '<S141>/Sum5'
     */
    rtb_Gain_cu = (rtb_Gain_it - Controller_DW.DiscreteTimeIntegrator1_DSTAT_i) *
      62.831852F;

    /* Switch: '<S141>/Switch' incorporates:
     *  Gain: '<S141>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_MatrixConcatenate1_tmp = 0.0F;
    } else {
      rtb_MatrixConcatenate1_tmp = rtb_Gain_cu;
    }

    /* End of Switch: '<S141>/Switch' */

    /* Product: '<S138>/Multiply' incorporates:
     *  Constant: '<S138>/kd'
     */
    rtb_Multiply_ga_idx_0 = CONTROL_PARAM.MC_VEL_Z_D *
      rtb_MatrixConcatenate1_tmp;

    /* Saturate: '<S138>/Saturation' */
    if (rtb_Multiply_ga_idx_0 > CONTROL_PARAM.MC_VEL_Z_D_MAX) {
      rtb_Multiply_ga_idx_0 = CONTROL_PARAM.MC_VEL_Z_D_MAX;
    } else {
      if (rtb_Multiply_ga_idx_0 < CONTROL_PARAM.MC_VEL_Z_D_MIN) {
        rtb_Multiply_ga_idx_0 = CONTROL_PARAM.MC_VEL_Z_D_MIN;
      }
    }

    /* End of Saturate: '<S138>/Saturation' */

    /* Sum: '<S135>/Add' incorporates:
     *  Constant: '<S140>/kp'
     *  DiscreteIntegrator: '<S139>/Discrete-Time Integrator'
     *  Product: '<S140>/Multiply'
     */
    rtb_Saturation_ov = (CONTROL_PARAM.MC_VEL_Z_P * rtb_Gain_it +
                         Controller_DW.DiscreteTimeIntegrator_DSTATE_l) +
      rtb_Multiply_ga_idx_0;

    /* Product: '<S133>/Multiply' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S133>/Cos'
     *  Trigonometry: '<S133>/Cos1'
     */
    rtb_Multiply_ga_idx_0 = arm_cos_f32(Controller_U.INS_Out.phi) * arm_cos_f32
      (Controller_U.INS_Out.theta);

    /* Saturate: '<S133>/Saturation1' incorporates:
     *  Product: '<S133>/Multiply'
     */
    if (rtb_Multiply_ga_idx_0 > 1.0F) {
      rtb_Divide_i_idx_2 = 1.0F;
    } else if (rtb_Multiply_ga_idx_0 < 0.5F) {
      rtb_Divide_i_idx_2 = 0.5F;
    } else {
      rtb_Divide_i_idx_2 = rtb_Multiply_ga_idx_0;
    }

    /* End of Saturate: '<S133>/Saturation1' */

    /* Gain: '<S133>/Gain' incorporates:
     *  Product: '<S133>/Multiply'
     */
    rtb_Multiply_ga_idx_0 *= 2.0F;

    /* Saturate: '<S133>/Saturation' */
    if (rtb_Multiply_ga_idx_0 > 1.0F) {
      rtb_Multiply_ga_idx_0 = 1.0F;
    } else {
      if (rtb_Multiply_ga_idx_0 < 0.0F) {
        rtb_Multiply_ga_idx_0 = 0.0F;
      }
    }

    /* End of Saturate: '<S133>/Saturation' */

    /* Product: '<S133>/Multiply1' incorporates:
     *  Constant: '<S133>/Constant'
     *  Product: '<S133>/Divide'
     */
    rtb_Multiply_ga_idx_0 *= 1.0F / rtb_Divide_i_idx_2 * rtb_Saturation_ov;

    /* Outputs for Atomic SubSystem: '<S77>/Quadcopter_x' */
    /* MultiPortSwitch: '<S127>/Multiport Switch' incorporates:
     *  Product: '<S90>/Multiply'
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
      /* Switch: '<S93>/Switch' incorporates:
       *  Gain: '<S93>/Gain1'
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

      /* End of Switch: '<S93>/Switch' */

      /* Product: '<S90>/Multiply' incorporates:
       *  Constant: '<S90>/gain1'
       */
      rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_ROLL_RATE_D *
        rtb_Divide_i_idx_1;

      /* Saturate: '<S90>/Saturation' */
      if (rtb_DiscreteTimeIntegrator1_g > CONTROL_PARAM.MC_RATE_D_MAX) {
        rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_RATE_D_MAX;
      } else {
        if (rtb_DiscreteTimeIntegrator1_g < CONTROL_PARAM.MC_RATE_D_MIN) {
          rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_RATE_D_MIN;
        }
      }

      rtb_Divide_i_idx_1 = rtb_DiscreteTimeIntegrator1_g;

      /* Product: '<S90>/Multiply' incorporates:
       *  Constant: '<S90>/gain2'
       */
      rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_PITCH_RATE_D *
        rtb_Divide_i_idx_2;

      /* Saturate: '<S90>/Saturation' */
      if (rtb_DiscreteTimeIntegrator1_g > CONTROL_PARAM.MC_RATE_D_MAX) {
        rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_RATE_D_MAX;
      } else {
        if (rtb_DiscreteTimeIntegrator1_g < CONTROL_PARAM.MC_RATE_D_MIN) {
          rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_RATE_D_MIN;
        }
      }

      rtb_Divide_i_idx_2 = rtb_DiscreteTimeIntegrator1_g;

      /* Product: '<S90>/Multiply' incorporates:
       *  Constant: '<S90>/gain3'
       */
      rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_YAW_RATE_D *
        rtb_Divide_i_idx_3;

      /* Saturate: '<S90>/Saturation' */
      if (rtb_DiscreteTimeIntegrator1_g > CONTROL_PARAM.MC_RATE_D_MAX) {
        rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_RATE_D_MAX;
      } else {
        if (rtb_DiscreteTimeIntegrator1_g < CONTROL_PARAM.MC_RATE_D_MIN) {
          rtb_DiscreteTimeIntegrator1_g = CONTROL_PARAM.MC_RATE_D_MIN;
        }
      }

      /* Switch: '<S126>/Switch' incorporates:
       *  Constant: '<S130>/Constant'
       *  Logic: '<S126>/Logical Operator'
       *  RelationalOperator: '<S129>/Compare'
       *  RelationalOperator: '<S130>/Compare'
       *  Saturate: '<S132>/Saturation'
       *  Switch: '<S126>/Switch1'
       */
      if ((rtb_BitwiseAND_a == 1) || (rtb_BitwiseAND_a == 2) ||
          (rtb_BitwiseAND_a == 3)) {
        rtb_throttle_cmd = Controller_U.FMS_Out.throttle_cmd;
      } else if (rtb_BitwiseAND_a == 6) {
        /* Switch: '<S131>/Switch' incorporates:
         *  Constant: '<S128>/Constant1'
         *  DataTypeConversion: '<S128>/Data Type Conversion'
         *  Gain: '<S128>/Gain1'
         *  S-Function (sfix_bitop): '<S131>/cmd_throttle valid'
         *  Saturate: '<S132>/Saturation'
         *  Sum: '<S128>/Sum1'
         *  Switch: '<S126>/Switch1'
         */
        if ((Controller_U.FMS_Out.cmd_mask & 4096) > 0) {
          rtb_throttle_cmd = Controller_U.FMS_Out.throttle_cmd;
        } else {
          if (rtb_Multiply_ga_idx_0 > 0.35F) {
            /* Saturate: '<S132>/Saturation' */
            rtb_Multiply_ga_idx_0 = 0.35F;
          } else {
            if (rtb_Multiply_ga_idx_0 < -0.35F) {
              /* Saturate: '<S132>/Saturation' */
              rtb_Multiply_ga_idx_0 = -0.35F;
            }
          }

          /* Sum: '<S128>/Sum' incorporates:
           *  Constant: '<S128>/hover_throttle'
           *  Saturate: '<S132>/Saturation'
           */
          u0 = rtb_Multiply_ga_idx_0 + CONTROL_PARAM.MC_HOVER_THRO;

          /* Saturate: '<S128>/Saturation' */
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

        /* End of Switch: '<S131>/Switch' */
      } else {
        if (rtb_Multiply_ga_idx_0 > 0.35F) {
          /* Saturate: '<S132>/Saturation' */
          rtb_Multiply_ga_idx_0 = 0.35F;
        } else {
          if (rtb_Multiply_ga_idx_0 < -0.35F) {
            /* Saturate: '<S132>/Saturation' */
            rtb_Multiply_ga_idx_0 = -0.35F;
          }
        }

        /* Sum: '<S128>/Sum' incorporates:
         *  Constant: '<S128>/hover_throttle'
         *  Saturate: '<S132>/Saturation'
         */
        u0 = rtb_Multiply_ga_idx_0 + CONTROL_PARAM.MC_HOVER_THRO;

        /* Saturate: '<S128>/Saturation' */
        if (u0 > 1.0F) {
          u0 = 1.0F;
        } else {
          if (u0 < 0.0F) {
            u0 = 0.0F;
          }
        }

        /* Switch: '<S126>/Switch1' incorporates:
         *  Constant: '<S128>/Constant1'
         *  DataTypeConversion: '<S128>/Data Type Conversion'
         *  Gain: '<S128>/Gain1'
         *  Sum: '<S128>/Sum1'
         */
        rtb_throttle_cmd = (uint16_T)((uint32_T)fmodf(floorf(1000.0F * u0),
          4.2949673E+9F) + 1000U);
      }

      /* End of Switch: '<S126>/Switch' */

      /* Saturate: '<S125>/Saturation1' incorporates:
       *  Constant: '<S92>/gain1'
       *  Constant: '<S92>/gain2'
       *  Constant: '<S92>/gain3'
       *  DiscreteIntegrator: '<S89>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S91>/Discrete-Time Integrator'
       *  Product: '<S92>/Multiply'
       *  Sum: '<S87>/Add'
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

      /* End of Saturate: '<S125>/Saturation1' */

      /* Product: '<S125>/Multiply' */
      for (i = 0; i < 4; i++) {
        /* Saturate: '<S125>/Saturation' incorporates:
         *  Constant: '<S125>/Effective_Matrix'
         *  Gain: '<S125>/Gain'
         *  Sum: '<S125>/Add'
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

        /* End of Saturate: '<S125>/Saturation' */
      }

      /* End of Product: '<S125>/Multiply' */
      break;

     default:
      rtb_MultiportSwitch[0] = 1000U;
      rtb_MultiportSwitch[1] = 1000U;
      rtb_MultiportSwitch[2] = 1000U;
      rtb_MultiportSwitch[3] = 1000U;
      break;
    }

    /* End of MultiPortSwitch: '<S127>/Multiport Switch' */

    /* Outport: '<Root>/Control_Out' incorporates:
     *  Constant: '<S127>/Disarm1'
     *  Reshape: '<S127>/Reshape'
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

    /* End of Outputs for SubSystem: '<S77>/Quadcopter_x' */

    /* Product: '<S116>/Multiply1' incorporates:
     *  Constant: '<S116>/const1'
     *  DiscreteIntegrator: '<S113>/Integrator'
     */
    rtb_Saturation_ov = Controller_DW.Integrator_DSTATE[0] * 0.05F;
    rtb_Multiply_ga_idx_0 = Controller_DW.Integrator_DSTATE[1] * 0.05F;

    /* Sum: '<S116>/Add' incorporates:
     *  DiscreteIntegrator: '<S113>/Integrator1'
     *  Sum: '<S113>/Subtract'
     */
    rtb_Gain_ms = (Controller_DW.Integrator1_DSTATE[0] -
                   Controller_U.FMS_Out.u_cmd) + rtb_Saturation_ov;
    rtb_Divide_i_idx_2 = (Controller_DW.Integrator1_DSTATE[1] -
                          Controller_U.FMS_Out.v_cmd) + rtb_Multiply_ga_idx_0;

    /* Signum: '<S116>/Sign' */
    if (rtb_Gain_ms < 0.0F) {
      rtb_Divide_i_idx_1 = -1.0F;
    } else if (rtb_Gain_ms > 0.0F) {
      rtb_Divide_i_idx_1 = 1.0F;
    } else {
      rtb_Divide_i_idx_1 = rtb_Gain_ms;
    }

    /* Sum: '<S116>/Add2' incorporates:
     *  Abs: '<S116>/Abs'
     *  Gain: '<S116>/Gain'
     *  Gain: '<S116>/Gain1'
     *  Product: '<S116>/Multiply2'
     *  Product: '<S116>/Multiply3'
     *  Signum: '<S116>/Sign'
     *  Sqrt: '<S116>/Sqrt'
     *  Sum: '<S116>/Add1'
     *  Sum: '<S116>/Subtract'
     */
    rtb_Divide_i_idx_1 = (sqrtf((8.0F * fabsf(rtb_Gain_ms) + Controller_ConstB.d)
      * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F * rtb_Divide_i_idx_1
      + rtb_Saturation_ov;

    /* Sum: '<S116>/Add3' incorporates:
     *  Signum: '<S116>/Sign'
     */
    rtb_Abs = rtb_Gain_ms + Controller_ConstB.d;

    /* Sum: '<S116>/Subtract1' incorporates:
     *  Signum: '<S116>/Sign'
     */
    rtb_MatrixConcatenate1_tmp = rtb_Gain_ms - Controller_ConstB.d;

    /* Signum: '<S116>/Sign1' */
    if (rtb_Abs < 0.0F) {
      rtb_Abs = -1.0F;
    } else {
      if (rtb_Abs > 0.0F) {
        rtb_Abs = 1.0F;
      }
    }

    /* Signum: '<S116>/Sign2' */
    if (rtb_MatrixConcatenate1_tmp < 0.0F) {
      rtb_MatrixConcatenate1_tmp = -1.0F;
    } else {
      if (rtb_MatrixConcatenate1_tmp > 0.0F) {
        rtb_MatrixConcatenate1_tmp = 1.0F;
      }
    }

    /* Sum: '<S116>/Add2' incorporates:
     *  Gain: '<S116>/Gain2'
     *  Product: '<S116>/Multiply4'
     *  Signum: '<S116>/Sign'
     *  Sum: '<S116>/Add4'
     *  Sum: '<S116>/Add5'
     *  Sum: '<S116>/Subtract2'
     */
    rtb_Gain_ms = ((rtb_Gain_ms - rtb_Divide_i_idx_1) + rtb_Saturation_ov) *
      ((rtb_Abs - rtb_MatrixConcatenate1_tmp) * 0.5F) + rtb_Divide_i_idx_1;

    /* Signum: '<S116>/Sign' */
    if (rtb_Divide_i_idx_2 < 0.0F) {
      rtb_Saturation_ov = -1.0F;
    } else if (rtb_Divide_i_idx_2 > 0.0F) {
      rtb_Saturation_ov = 1.0F;
    } else {
      rtb_Saturation_ov = rtb_Divide_i_idx_2;
    }

    /* Sum: '<S116>/Add2' incorporates:
     *  Abs: '<S116>/Abs'
     *  Gain: '<S116>/Gain'
     *  Gain: '<S116>/Gain1'
     *  Product: '<S116>/Multiply2'
     *  Product: '<S116>/Multiply3'
     *  Signum: '<S116>/Sign'
     *  Sqrt: '<S116>/Sqrt'
     *  Sum: '<S116>/Add1'
     *  Sum: '<S116>/Subtract'
     */
    rtb_Divide_i_idx_1 = (sqrtf((8.0F * fabsf(rtb_Divide_i_idx_2) +
      Controller_ConstB.d) * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
      rtb_Saturation_ov + rtb_Multiply_ga_idx_0;

    /* Sum: '<S116>/Add3' incorporates:
     *  Signum: '<S116>/Sign'
     */
    rtb_Abs = rtb_Divide_i_idx_2 + Controller_ConstB.d;

    /* Sum: '<S116>/Subtract1' incorporates:
     *  Signum: '<S116>/Sign'
     */
    rtb_MatrixConcatenate1_tmp = rtb_Divide_i_idx_2 - Controller_ConstB.d;

    /* Signum: '<S116>/Sign1' */
    if (rtb_Abs < 0.0F) {
      rtb_Abs = -1.0F;
    } else {
      if (rtb_Abs > 0.0F) {
        rtb_Abs = 1.0F;
      }
    }

    /* Signum: '<S116>/Sign2' */
    if (rtb_MatrixConcatenate1_tmp < 0.0F) {
      rtb_MatrixConcatenate1_tmp = -1.0F;
    } else {
      if (rtb_MatrixConcatenate1_tmp > 0.0F) {
        rtb_MatrixConcatenate1_tmp = 1.0F;
      }
    }

    /* Sum: '<S116>/Add5' incorporates:
     *  Gain: '<S116>/Gain2'
     *  Product: '<S116>/Multiply4'
     *  Signum: '<S116>/Sign'
     *  Sum: '<S116>/Add2'
     *  Sum: '<S116>/Add4'
     *  Sum: '<S116>/Subtract2'
     */
    rtb_Divide_i_idx_1 += ((rtb_Divide_i_idx_2 - rtb_Divide_i_idx_1) +
      rtb_Multiply_ga_idx_0) * ((rtb_Abs - rtb_MatrixConcatenate1_tmp) * 0.5F);

    /* Product: '<S137>/Multiply1' incorporates:
     *  Constant: '<S137>/const1'
     *  DiscreteIntegrator: '<S136>/Integrator'
     */
    rtb_Divide_i_idx_2 = Controller_DW.Integrator_DSTATE_j * 0.05F;

    /* Sum: '<S137>/Add' incorporates:
     *  DiscreteIntegrator: '<S136>/Integrator1'
     *  Sum: '<S136>/Subtract'
     */
    rtb_Multiply_ga_idx_0 = (Controller_DW.Integrator1_DSTATE_e -
      Controller_U.FMS_Out.w_cmd) + rtb_Divide_i_idx_2;

    /* Signum: '<S137>/Sign' */
    if (rtb_Multiply_ga_idx_0 < 0.0F) {
      rtb_Saturation_ov = -1.0F;
    } else if (rtb_Multiply_ga_idx_0 > 0.0F) {
      rtb_Saturation_ov = 1.0F;
    } else {
      rtb_Saturation_ov = rtb_Multiply_ga_idx_0;
    }

    /* End of Signum: '<S137>/Sign' */

    /* Sum: '<S137>/Add2' incorporates:
     *  Abs: '<S137>/Abs'
     *  Gain: '<S137>/Gain'
     *  Gain: '<S137>/Gain1'
     *  Product: '<S137>/Multiply2'
     *  Product: '<S137>/Multiply3'
     *  Sqrt: '<S137>/Sqrt'
     *  Sum: '<S137>/Add1'
     *  Sum: '<S137>/Subtract'
     */
    rtb_Saturation_ov = (sqrtf((8.0F * fabsf(rtb_Multiply_ga_idx_0) +
      Controller_ConstB.d_i) * Controller_ConstB.d_i) - Controller_ConstB.d_i) *
      0.5F * rtb_Saturation_ov + rtb_Divide_i_idx_2;

    /* Sum: '<S137>/Add4' */
    rtb_Divide_i_idx_2 += rtb_Multiply_ga_idx_0 - rtb_Saturation_ov;

    /* Sum: '<S137>/Add3' */
    rtb_Abs = rtb_Multiply_ga_idx_0 + Controller_ConstB.d_i;

    /* Sum: '<S137>/Subtract1' */
    rtb_Multiply_ga_idx_0 -= Controller_ConstB.d_i;

    /* Signum: '<S137>/Sign1' */
    if (rtb_Abs < 0.0F) {
      rtb_Abs = -1.0F;
    } else {
      if (rtb_Abs > 0.0F) {
        rtb_Abs = 1.0F;
      }
    }

    /* End of Signum: '<S137>/Sign1' */

    /* Signum: '<S137>/Sign2' */
    if (rtb_Multiply_ga_idx_0 < 0.0F) {
      rtb_Multiply_ga_idx_0 = -1.0F;
    } else {
      if (rtb_Multiply_ga_idx_0 > 0.0F) {
        rtb_Multiply_ga_idx_0 = 1.0F;
      }
    }

    /* End of Signum: '<S137>/Sign2' */

    /* Sum: '<S137>/Add5' incorporates:
     *  Gain: '<S137>/Gain2'
     *  Product: '<S137>/Multiply4'
     *  Sum: '<S137>/Subtract2'
     */
    rtb_Saturation_ov += (rtb_Abs - rtb_Multiply_ga_idx_0) * 0.5F *
      rtb_Divide_i_idx_2;

    /* Update for DiscreteIntegrator: '<S91>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S91>/gain1'
     *  Constant: '<S91>/gain2'
     *  Constant: '<S91>/gain3'
     *  DiscreteIntegrator: '<S89>/Discrete-Time Integrator5'
     *  Product: '<S91>/Multiply'
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

    /* End of Update for DiscreteIntegrator: '<S91>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S118>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_PrevRe_p = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S120>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;

    /* Update for DiscreteIntegrator: '<S113>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S113>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE[0] += 0.002F *
      Controller_DW.Integrator_DSTATE[0];

    /* Update for DiscreteIntegrator: '<S118>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S118>/ki'
     *  Product: '<S118>/Multiply'
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

    /* Update for DiscreteIntegrator: '<S120>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] += 0.002F *
      rtb_Saturation1_h_idx_0;

    /* Update for DiscreteIntegrator: '<S113>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S113>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE[1] += 0.002F *
      Controller_DW.Integrator_DSTATE[1];

    /* Update for DiscreteIntegrator: '<S118>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S118>/ki'
     *  Product: '<S118>/Multiply'
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

    /* Update for DiscreteIntegrator: '<S120>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] += 0.002F * rtb_Divide_gn;
    Controller_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S89>/Discrete-Time Integrator5' */
    Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;

    /* Update for DiscreteIntegrator: '<S93>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 0U;

    /* Update for DiscreteIntegrator: '<S89>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S89>/Gain'
     *  Sum: '<S89>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] += (rtb_Add_c -
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S93>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[0] += 0.002F *
      rtb_DiscreteTimeIntegrator1_k1[0];

    /* Update for DiscreteIntegrator: '<S89>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S89>/Gain'
     *  Sum: '<S89>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] += (rtb_FF_limit_idx_1 -
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S93>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[1] += 0.002F *
      rtb_DiscreteTimeIntegrator1_k1[1];

    /* Update for DiscreteIntegrator: '<S89>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S89>/Gain'
     *  Sum: '<S89>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] += (rtb_FF_limit_idx_2 -
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S93>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[2] += 0.002F *
      rtb_DiscreteTimeIntegrator1_k1[2];
    Controller_DW.DiscreteTimeIntegrator1_PrevR_k = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S136>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S136>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_e += 0.002F *
      Controller_DW.Integrator_DSTATE_j;

    /* Update for DiscreteIntegrator: '<S139>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S139>/ki'
     *  Product: '<S139>/Multiply'
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

    /* End of Update for DiscreteIntegrator: '<S139>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S141>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_i += 0.002F * rtb_Gain_cu;
    Controller_DW.DiscreteTimeIntegrator1_Prev_ks = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Signum: '<S116>/Sign3' incorporates:
     *  Product: '<S116>/Divide'
     *  Sum: '<S116>/Add6'
     */
    rtb_Abs = rtb_Gain_ms + Controller_ConstB.d;

    /* Signum: '<S116>/Sign4' incorporates:
     *  Product: '<S116>/Divide'
     *  Sum: '<S116>/Subtract3'
     */
    rtb_Add_c = rtb_Gain_ms - Controller_ConstB.d;

    /* Signum: '<S116>/Sign5' incorporates:
     *  Product: '<S116>/Divide'
     */
    if (rtb_Gain_ms < 0.0F) {
      rtb_FF_limit_idx_1 = -1.0F;
    } else if (rtb_Gain_ms > 0.0F) {
      rtb_FF_limit_idx_1 = 1.0F;
    } else {
      rtb_FF_limit_idx_1 = rtb_Gain_ms;
    }

    /* Signum: '<S116>/Sign3' */
    if (rtb_Abs < 0.0F) {
      rtb_Abs = -1.0F;
    } else {
      if (rtb_Abs > 0.0F) {
        rtb_Abs = 1.0F;
      }
    }

    /* Signum: '<S116>/Sign4' */
    if (rtb_Add_c < 0.0F) {
      rtb_Add_c = -1.0F;
    } else {
      if (rtb_Add_c > 0.0F) {
        rtb_Add_c = 1.0F;
      }
    }

    /* Signum: '<S116>/Sign6' incorporates:
     *  Product: '<S116>/Divide'
     */
    if (rtb_Gain_ms < 0.0F) {
      rtb_FF_limit_idx_2 = -1.0F;
    } else if (rtb_Gain_ms > 0.0F) {
      rtb_FF_limit_idx_2 = 1.0F;
    } else {
      rtb_FF_limit_idx_2 = rtb_Gain_ms;
    }

    /* Update for DiscreteIntegrator: '<S113>/Integrator' incorporates:
     *  Constant: '<S116>/const'
     *  Gain: '<S116>/Gain3'
     *  Product: '<S116>/Divide'
     *  Product: '<S116>/Multiply5'
     *  Product: '<S116>/Multiply6'
     *  Sum: '<S116>/Subtract4'
     *  Sum: '<S116>/Subtract5'
     *  Sum: '<S116>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE[0] += ((rtb_Gain_ms / Controller_ConstB.d -
      rtb_FF_limit_idx_1) * Controller_ConstB.Gain4 * ((rtb_Abs - rtb_Add_c) *
      0.5F) - rtb_FF_limit_idx_2 * 58.836F) * 0.002F;

    /* Signum: '<S116>/Sign3' incorporates:
     *  Sum: '<S116>/Add6'
     */
    rtb_Abs = rtb_Divide_i_idx_1 + Controller_ConstB.d;

    /* Signum: '<S116>/Sign4' incorporates:
     *  Sum: '<S116>/Subtract3'
     */
    rtb_Add_c = rtb_Divide_i_idx_1 - Controller_ConstB.d;

    /* Signum: '<S116>/Sign5' */
    if (rtb_Divide_i_idx_1 < 0.0F) {
      rtb_FF_limit_idx_1 = -1.0F;
    } else if (rtb_Divide_i_idx_1 > 0.0F) {
      rtb_FF_limit_idx_1 = 1.0F;
    } else {
      rtb_FF_limit_idx_1 = rtb_Divide_i_idx_1;
    }

    /* Signum: '<S116>/Sign3' */
    if (rtb_Abs < 0.0F) {
      rtb_Abs = -1.0F;
    } else {
      if (rtb_Abs > 0.0F) {
        rtb_Abs = 1.0F;
      }
    }

    /* Signum: '<S116>/Sign4' */
    if (rtb_Add_c < 0.0F) {
      rtb_Add_c = -1.0F;
    } else {
      if (rtb_Add_c > 0.0F) {
        rtb_Add_c = 1.0F;
      }
    }

    /* Signum: '<S116>/Sign6' */
    if (rtb_Divide_i_idx_1 < 0.0F) {
      rtb_FF_limit_idx_2 = -1.0F;
    } else if (rtb_Divide_i_idx_1 > 0.0F) {
      rtb_FF_limit_idx_2 = 1.0F;
    } else {
      rtb_FF_limit_idx_2 = rtb_Divide_i_idx_1;
    }

    /* Update for DiscreteIntegrator: '<S113>/Integrator' incorporates:
     *  Constant: '<S116>/const'
     *  Gain: '<S116>/Gain3'
     *  Product: '<S116>/Divide'
     *  Product: '<S116>/Multiply5'
     *  Product: '<S116>/Multiply6'
     *  Sum: '<S116>/Subtract4'
     *  Sum: '<S116>/Subtract5'
     *  Sum: '<S116>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE[1] += ((rtb_Divide_i_idx_1 /
      Controller_ConstB.d - rtb_FF_limit_idx_1) * Controller_ConstB.Gain4 *
      ((rtb_Abs - rtb_Add_c) * 0.5F) - rtb_FF_limit_idx_2 * 58.836F) * 0.002F;

    /* Signum: '<S137>/Sign6' incorporates:
     *  Signum: '<S137>/Sign5'
     */
    if (rtb_Saturation_ov < 0.0F) {
      rtb_FF_limit_idx_1 = -1.0F;

      /* Signum: '<S137>/Sign5' */
      rtb_FF_limit_idx_2 = -1.0F;
    } else if (rtb_Saturation_ov > 0.0F) {
      rtb_FF_limit_idx_1 = 1.0F;

      /* Signum: '<S137>/Sign5' */
      rtb_FF_limit_idx_2 = 1.0F;
    } else {
      rtb_FF_limit_idx_1 = rtb_Saturation_ov;

      /* Signum: '<S137>/Sign5' */
      rtb_FF_limit_idx_2 = rtb_Saturation_ov;
    }

    /* End of Signum: '<S137>/Sign6' */

    /* Sum: '<S137>/Add6' */
    rtb_Abs = rtb_Saturation_ov + Controller_ConstB.d_i;

    /* Sum: '<S137>/Subtract3' */
    rtb_Add_c = rtb_Saturation_ov - Controller_ConstB.d_i;

    /* Signum: '<S137>/Sign3' */
    if (rtb_Abs < 0.0F) {
      rtb_Abs = -1.0F;
    } else {
      if (rtb_Abs > 0.0F) {
        rtb_Abs = 1.0F;
      }
    }

    /* End of Signum: '<S137>/Sign3' */

    /* Signum: '<S137>/Sign4' */
    if (rtb_Add_c < 0.0F) {
      rtb_Add_c = -1.0F;
    } else {
      if (rtb_Add_c > 0.0F) {
        rtb_Add_c = 1.0F;
      }
    }

    /* End of Signum: '<S137>/Sign4' */

    /* Update for DiscreteIntegrator: '<S136>/Integrator' incorporates:
     *  Constant: '<S137>/const'
     *  Gain: '<S137>/Gain3'
     *  Product: '<S137>/Divide'
     *  Product: '<S137>/Multiply5'
     *  Product: '<S137>/Multiply6'
     *  Sum: '<S137>/Subtract4'
     *  Sum: '<S137>/Subtract5'
     *  Sum: '<S137>/Subtract6'
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
  /* Start for Constant: '<S184>/Constant' */
  Controller_B.Constant_m = CONTROL_PARAM.MC_VEL_Z_I_MIN;

  /* End of Start for SubSystem: '<S2>/VTOL_Controller' */

  /* Start for IfAction SubSystem: '<S2>/BackTrans_Controller' */
  /* Start for Constant: '<S57>/Constant' */
  Controller_B.Constant_i = CONTROL_PARAM.MC_VEL_Z_I_MIN;

  /* End of Start for SubSystem: '<S2>/BackTrans_Controller' */

  /* Start for IfAction SubSystem: '<S2>/MC_Controller' */
  /* Start for Constant: '<S139>/Constant' */
  Controller_B.Constant = CONTROL_PARAM.MC_VEL_Z_I_MIN;

  /* End of Start for SubSystem: '<S2>/MC_Controller' */

  /* SystemInitialize for IfAction SubSystem: '<S2>/VTOL_Controller' */
  /* InitializeConditions for DiscreteIntegrator: '<S189>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_L_eo = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S188>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_o = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S181>/Integrator1' */
  Controller_DW.Integrator1_DSTATE_i = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S184>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S184>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S186>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_i = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_h = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S224>/ ' */
  Controller_DW._DSTATE = Controller_ConstB.Zero1;
  if (Controller_DW._DSTATE >= CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
    Controller_DW._DSTATE = CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
  } else {
    if (Controller_DW._DSTATE <= -CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
      Controller_DW._DSTATE = -CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
    }
  }

  Controller_DW._PrevResetState = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S224>/ ' */

  /* InitializeConditions for DiscreteIntegrator: '<S225>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_f = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_b = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S157>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_b = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S159>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_PrevRe_o = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S161>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_L_h2 = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_l = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S187>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_g = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S159>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S199>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S159>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S199>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S159>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S199>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S227>/ ' */
  Controller_DW._DSTATE_d = Controller_ConstB.Zero;
  if (Controller_DW._DSTATE_d >= 0.3F) {
    Controller_DW._DSTATE_d = 0.3F;
  } else {
    if (Controller_DW._DSTATE_d <= -0.3F) {
      Controller_DW._DSTATE_d = -0.3F;
    }
  }

  Controller_DW._PrevResetState_e = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S227>/ ' */

  /* InitializeConditions for DiscreteIntegrator: '<S228>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_L_h0 = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_d = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S181>/Integrator' */
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
  /* InitializeConditions for DiscreteIntegrator: '<S91>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S91>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S113>/Integrator1' */
  Controller_DW.Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S118>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S113>/Integrator1' */
  Controller_DW.Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S118>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S120>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S89>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S93>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_k = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S136>/Integrator1' */
  Controller_DW.Integrator1_DSTATE_e = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S139>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S139>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S141>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 1U;
  Controller_DW.DiscreteTimeIntegrator1_Prev_ks = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S113>/Integrator' */
  Controller_DW.Integrator_DSTATE[0] = 0.0F;
  Controller_DW.Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S136>/Integrator' */
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
