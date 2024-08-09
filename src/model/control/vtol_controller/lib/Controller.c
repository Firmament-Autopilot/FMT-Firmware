/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.196
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Aug  9 11:40:35 2024
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
struct_EKLmLRDj4sm70rxKUP2Rn CONTROL_PARAM = {
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
  17.0F,
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
  0.25F,
  0.1F,
  0.1F
} ;                                    /* Variable: CONTROL_PARAM
                                        * Referenced by:
                                        *   '<S9>/mc_hover_throttle'
                                        *   '<S141>/mc_hover_throttle'
                                        *   '<S184>/Saturation'
                                        *   '<S185>/Gain'
                                        *   '<S185>/Gain1'
                                        *   '<S185>/balabnce_ratio2'
                                        *   '<S185>/balance_ratio'
                                        *   '<S185>/pitch_ff'
                                        *   '<S185>/thorttle_ff'
                                        *   '<S185>/ucmd2pitch'
                                        *   '<S185>/ucmd2thor'
                                        *   '<S185>/wcmd2pitch'
                                        *   '<S185>/wcmd2thor'
                                        *   '<S101>/Saturation'
                                        *   '<S121>/hover_throttle'
                                        *   '<S186>/FF'
                                        *   '<S186>/FF_limit'
                                        *   '<S186>/PI_limit'
                                        *   '<S205>/P_control'
                                        *   '<S206>/P_control'
                                        *   '<S38>/Saturation'
                                        *   '<S77>/Saturation'
                                        *   '<S77>/Saturation1'
                                        *   '<S110>/kd'
                                        *   '<S110>/Saturation'
                                        *   '<S111>/ki'
                                        *   '<S111>/Discrete-Time Integrator'
                                        *   '<S112>/kp'
                                        *   '<S131>/kd'
                                        *   '<S131>/Saturation'
                                        *   '<S132>/Constant'
                                        *   '<S132>/ki'
                                        *   '<S132>/Discrete-Time Integrator'
                                        *   '<S133>/kp'
                                        *   '<S146>/Saturation'
                                        *   '<S146>/Saturation1'
                                        *   '<S190>/trim_speed'
                                        *   '<S191>/trim_speed'
                                        *   '<S216>/Gain'
                                        *   '<S217>/ '
                                        *   '<S217>/Gain3'
                                        *   '<S219>/Gain'
                                        *   '<S220>/Gain'
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
                                        *   '<S66>/Constant1'
                                        *   '<S66>/Constant12'
                                        *   '<S66>/Constant2'
                                        *   '<S66>/Constant7'
                                        *   '<S94>/Constant1'
                                        *   '<S94>/Constant2'
                                        *   '<S158>/Constant1'
                                        *   '<S158>/Constant2'
                                        *   '<S176>/kd'
                                        *   '<S176>/Saturation'
                                        *   '<S177>/Constant'
                                        *   '<S177>/ki'
                                        *   '<S177>/Discrete-Time Integrator'
                                        *   '<S178>/kp'
                                        *   '<S192>/gain1'
                                        *   '<S192>/gain2'
                                        *   '<S192>/gain3'
                                        *   '<S192>/Discrete-Time Integrator'
                                        *   '<S193>/gain1'
                                        *   '<S193>/gain2'
                                        *   '<S193>/gain3'
                                        *   '<S197>/Pitch Offset'
                                        *   '<S197>/Saturation'
                                        *   '<S198>/Constant1'
                                        *   '<S198>/Constant2'
                                        *   '<S236>/Constant1'
                                        *   '<S236>/Constant12'
                                        *   '<S236>/Constant2'
                                        *   '<S236>/Constant7'
                                        *   '<S33>/Constant1'
                                        *   '<S33>/Constant2'
                                        *   '<S83>/gain1'
                                        *   '<S83>/gain2'
                                        *   '<S83>/gain3'
                                        *   '<S83>/Saturation'
                                        *   '<S84>/gain1'
                                        *   '<S84>/gain2'
                                        *   '<S84>/gain3'
                                        *   '<S84>/Discrete-Time Integrator'
                                        *   '<S85>/gain1'
                                        *   '<S85>/gain2'
                                        *   '<S85>/gain3'
                                        *   '<S151>/gain1'
                                        *   '<S151>/gain2'
                                        *   '<S151>/gain3'
                                        *   '<S151>/Saturation'
                                        *   '<S152>/gain1'
                                        *   '<S152>/gain2'
                                        *   '<S152>/gain3'
                                        *   '<S152>/Discrete-Time Integrator'
                                        *   '<S153>/gain1'
                                        *   '<S153>/gain2'
                                        *   '<S153>/gain3'
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
  int8_T rtPrevAction;
  uint8_T rtb_BitwiseAND_n;
  real32_T rtb_Divide_gn;
  real32_T rtb_Saturation_ov;
  int32_T rtb_Relay;
  real32_T rtb_Gain_ms;
  boolean_T rtb_LogicalOperator_b3;
  real32_T rtb_Gain_it;
  real32_T rtb_phi_cmd;
  real32_T rtb_u_c;
  real32_T rtb_Abs;
  real32_T rtb_MatrixConcatenate1[9];
  real32_T rtb_Multiply_kn[3];
  real32_T rtb_VdotPg;
  real32_T rtb_Sum;
  real32_T rtb_Minus;
  real32_T rtb_Gain_il;
  real32_T rtb_PitchOffset;
  boolean_T rtb_LogicalOperator_m;
  real32_T rtb_Saturation_a5;
  real32_T rtb_Saturation_gg;
  real32_T rtb_MatrixConcatenate_a[12];
  real32_T rtb_boost_factor_o;
  uint16_T rtb_DataTypeConversion_k;
  real32_T rtb_Add_cs;
  real32_T rtb_Add1_j4;
  uint16_T rtb_MultiportSwitch_o[4];
  uint16_T rtb_MultiportSwitch_i[9];
  int32_T i;
  real32_T rtb_MatrixConcatenate1_0[3];
  real32_T tmp[4];
  real32_T rtb_DiscreteTimeIntegrator1_md_;
  real32_T rtb_DiscreteTimeIntegrator1_m_0;
  real32_T rtb_DiscreteTimeIntegrator1_m_1;
  real32_T rtb_Divide_i_idx_0;
  real32_T rtb_Divide_i_idx_1;
  real32_T rtb_Divide_i_idx_2;
  real32_T rtb_Divide_i_idx_3;
  real32_T rtb_Saturation1_h_idx_0;
  uint16_T u0;
  real32_T rtb_MatrixConcatenate1_tmp;

  /* S-Function (sfix_bitop): '<S7>/Bitwise AND' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  rtb_BitwiseAND_n = (uint8_T)(Controller_U.FMS_Out.ctrl_mode & 63);

  /* SwitchCase: '<S8>/Switch Case1' incorporates:
   *  Constant: '<S132>/Constant'
   *  Constant: '<S177>/Constant'
   *  Constant: '<S57>/Constant'
   *  DataTypeConversion: '<S8>/Data Type Conversion'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S110>/Multiply'
   *  Product: '<S160>/Divide1'
   *  Product: '<S8>/Divide'
   *  Product: '<S96>/Divide1'
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
       *  DiscreteIntegrator: '<S150>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S152>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S154>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S174>/Integrator'
       *  DiscreteIntegrator: '<S174>/Integrator1'
       *  DiscreteIntegrator: '<S177>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S179>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S180>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S181>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S182>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S192>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S217>/ '
       *  DiscreteIntegrator: '<S218>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S220>/ '
       *  DiscreteIntegrator: '<S221>/Discrete-Time Integrator1'
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
    /* Product: '<S136>/Divide' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Math: '<S136>/Square'
     */
    rtb_Divide_gn = Controller_U.INS_Out.airspeed *
      Controller_U.INS_Out.airspeed / Controller_ConstB.Square1;

    /* DiscreteIntegrator: '<S182>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_L_eo != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_a = rtb_Divide_gn;
    }

    /* Saturate: '<S136>/Saturation' */
    if (Controller_DW.DiscreteTimeIntegrator5_DSTAT_a > 1.0F) {
      rtb_Saturation_ov = 1.0F;
    } else if (Controller_DW.DiscreteTimeIntegrator5_DSTAT_a < 0.0F) {
      rtb_Saturation_ov = 0.0F;
    } else {
      rtb_Saturation_ov = Controller_DW.DiscreteTimeIntegrator5_DSTAT_a;
    }

    /* End of Saturate: '<S136>/Saturation' */

    /* Relay: '<S136>/Relay' */
    if (rtb_Saturation_ov >= 0.95F) {
      Controller_DW.Relay_Mode = true;
    } else {
      if (rtb_Saturation_ov <= 0.85F) {
        Controller_DW.Relay_Mode = false;
      }
    }

    rtb_Relay = !Controller_DW.Relay_Mode;

    /* End of Relay: '<S136>/Relay' */

    /* DiscreteIntegrator: '<S181>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_o != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTA_a2 = (real32_T)rtb_Relay;
    }

    /* Gain: '<S172>/Gain' incorporates:
     *  DiscreteIntegrator: '<S174>/Integrator1'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S172>/Sum1'
     */
    rtb_Gain_ms = -(Controller_DW.Integrator1_DSTATE_i - Controller_U.INS_Out.vd);

    /* Logic: '<S169>/Logical Operator' incorporates:
     *  Constant: '<S171>/Constant'
     *  DiscreteIntegrator: '<S181>/Discrete-Time Integrator5'
     *  RelationalOperator: '<S171>/Compare'
     */
    rtb_LogicalOperator_b3 = ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator5_DSTA_a2 == 0.0F));
    Controller_B.Constant_m = CONTROL_PARAM.MC_VEL_Z_I_MIN;

    /* DiscreteIntegrator: '<S177>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S177>/Constant'
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

    /* DiscreteIntegrator: '<S179>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_i != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTA_ld = rtb_Gain_ms;
    }

    if (rtb_LogicalOperator_b3 || (Controller_DW.DiscreteTimeIntegrator1_PrevR_h
         != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTA_ld = rtb_Gain_ms;
    }

    /* Gain: '<S179>/Gain' incorporates:
     *  DiscreteIntegrator: '<S179>/Discrete-Time Integrator1'
     *  Sum: '<S179>/Sum5'
     */
    rtb_Gain_it = (rtb_Gain_ms - Controller_DW.DiscreteTimeIntegrator1_DSTA_ld) *
      62.831852F;

    /* Trigonometry: '<S184>/Atan' incorporates:
     *  Gain: '<S184>/g_force'
     *  Sum: '<S184>/Minus'
     */
    rtb_phi_cmd = atanf(0.101936802F * Controller_U.FMS_Out.ay_cmd);

    /* Saturate: '<S184>/Saturation' */
    if (rtb_phi_cmd > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_phi_cmd = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_phi_cmd < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_phi_cmd = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      }
    }

    /* End of Saturate: '<S184>/Saturation' */

    /* Switch: '<S204>/Switch' incorporates:
     *  Constant: '<S215>/Constant'
     *  RelationalOperator: '<S215>/Compare'
     */
    if (rtb_BitwiseAND_n == 4) {
      rtb_Add_cs = Controller_U.FMS_Out.phi_cmd;
    } else {
      rtb_Add_cs = rtb_phi_cmd;
    }

    /* End of Switch: '<S204>/Switch' */

    /* Abs: '<S185>/Abs' */
    rtb_Abs = fabsf(rtb_Add_cs);

    /* Trigonometry: '<S212>/Trigonometric Function1' incorporates:
     *  Gain: '<S211>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S212>/Trigonometric Function3'
     *  Trigonometry: '<S214>/Trigonometric Function1'
     *  Trigonometry: '<S214>/Trigonometric Function3'
     */
    rtb_PitchOffset = arm_cos_f32(-Controller_U.INS_Out.psi);
    rtb_MatrixConcatenate1[0] = rtb_PitchOffset;

    /* Trigonometry: '<S212>/Trigonometric Function' incorporates:
     *  Gain: '<S211>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S212>/Trigonometric Function2'
     *  Trigonometry: '<S214>/Trigonometric Function'
     */
    rtb_Saturation1_h_idx_0 = arm_sin_f32(-Controller_U.INS_Out.psi);
    rtb_MatrixConcatenate1[1] = rtb_Saturation1_h_idx_0;

    /* SignalConversion: '<S212>/ConcatBufferAtVector Concatenate1In3' incorporates:
     *  Constant: '<S212>/Constant3'
     */
    rtb_MatrixConcatenate1[2] = 0.0F;

    /* Gain: '<S212>/Gain' */
    rtb_MatrixConcatenate1[3] = -rtb_Saturation1_h_idx_0;

    /* Trigonometry: '<S212>/Trigonometric Function3' */
    rtb_MatrixConcatenate1[4] = rtb_PitchOffset;

    /* SignalConversion: '<S212>/ConcatBufferAtVector Concatenate2In3' incorporates:
     *  Constant: '<S212>/Constant4'
     */
    rtb_MatrixConcatenate1[5] = 0.0F;

    /* SignalConversion: '<S212>/ConcatBufferAtVector ConcatenateIn3' */
    rtb_MatrixConcatenate1[6] = Controller_ConstB.VectorConcatenate3_c[0];
    rtb_MatrixConcatenate1[7] = Controller_ConstB.VectorConcatenate3_c[1];
    rtb_MatrixConcatenate1[8] = Controller_ConstB.VectorConcatenate3_c[2];

    /* SignalConversion: '<S208>/TmpSignal ConversionAtMultiplyInport2' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_DiscreteTimeIntegrator1_md_ = Controller_U.INS_Out.vn;
    rtb_DiscreteTimeIntegrator1_m_0 = Controller_U.INS_Out.ve;
    rtb_DiscreteTimeIntegrator1_m_1 = Controller_U.INS_Out.vd;

    /* Product: '<S208>/Multiply' */
    for (i = 0; i < 3; i++) {
      rtb_Multiply_kn[i] = rtb_MatrixConcatenate1[i + 6] *
        rtb_DiscreteTimeIntegrator1_m_1 + (rtb_MatrixConcatenate1[i + 3] *
        rtb_DiscreteTimeIntegrator1_m_0 + rtb_MatrixConcatenate1[i] *
        rtb_DiscreteTimeIntegrator1_md_);
    }

    /* End of Product: '<S208>/Multiply' */

    /* Switch: '<S208>/Switch' incorporates:
     *  Gain: '<S208>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S208>/Divide'
     *  S-Function (sfix_bitop): '<S208>/Bitwise AND'
     *  Trigonometry: '<S208>/Asin'
     */
    if ((Controller_U.INS_Out.flag & 16U) > 1U) {
      /* Sqrt: '<S208>/Sqrt' incorporates:
       *  Math: '<S208>/Square'
       *  Math: '<S208>/Square1'
       *  Sum: '<S208>/Add'
       */
      rtb_Divide_i_idx_0 = sqrtf(Controller_U.INS_Out.vn *
        Controller_U.INS_Out.vn + Controller_U.INS_Out.ve *
        Controller_U.INS_Out.ve);

      /* Saturate: '<S208>/Saturation' incorporates:
       *  Sqrt: '<S208>/Sqrt'
       */
      if (rtb_Divide_i_idx_0 > 100.0F) {
        rtb_Divide_i_idx_0 = 100.0F;
      } else {
        if (rtb_Divide_i_idx_0 < 8.0F) {
          rtb_Divide_i_idx_0 = 8.0F;
        }
      }

      /* End of Saturate: '<S208>/Saturation' */

      /* DeadZone: '<S208>/Dead Zone' */
      if (Controller_U.INS_Out.vd > 0.1F) {
        rtb_Saturation_a5 = Controller_U.INS_Out.vd - 0.1F;
      } else if (Controller_U.INS_Out.vd >= -0.1F) {
        rtb_Saturation_a5 = 0.0F;
      } else {
        rtb_Saturation_a5 = Controller_U.INS_Out.vd - -0.1F;
      }

      /* End of DeadZone: '<S208>/Dead Zone' */
      rtb_u_c = atanf(1.0F / rtb_Divide_i_idx_0 * -rtb_Saturation_a5);
    } else {
      rtb_u_c = Controller_U.INS_Out.theta;
    }

    /* End of Switch: '<S208>/Switch' */

    /* DeadZone: '<S208>/Dead Zone1' */
    if (rtb_Multiply_kn[0] > 1.0F) {
      rtb_Divide_i_idx_0 = rtb_Multiply_kn[0] - 1.0F;
    } else if (rtb_Multiply_kn[0] >= -1.0F) {
      rtb_Divide_i_idx_0 = 0.0F;
    } else {
      rtb_Divide_i_idx_0 = rtb_Multiply_kn[0] - -1.0F;
    }

    /* End of DeadZone: '<S208>/Dead Zone1' */

    /* Signum: '<S208>/Sign' */
    if (rtb_Divide_i_idx_0 < 0.0F) {
      rtb_Divide_i_idx_0 = -1.0F;
    } else {
      if (rtb_Divide_i_idx_0 > 0.0F) {
        rtb_Divide_i_idx_0 = 1.0F;
      }
    }

    /* End of Signum: '<S208>/Sign' */

    /* Product: '<S208>/Multiply1' */
    rtb_u_c *= rtb_Divide_i_idx_0;

    /* Saturate: '<S208>/Saturation1' */
    if (rtb_u_c > 0.785398185F) {
      rtb_u_c = 0.785398185F;
    } else {
      if (rtb_u_c < -0.785398185F) {
        rtb_u_c = -0.785398185F;
      }
    }

    /* End of Saturate: '<S208>/Saturation1' */

    /* Gain: '<S207>/Gain1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_VdotPg = 0.101936802F * Controller_U.INS_Out.ax;

    /* Sqrt: '<S210>/Sqrt' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Math: '<S210>/Square'
     *  Math: '<S210>/Square1'
     *  Sum: '<S210>/Add'
     */
    rtb_Add_cs = sqrtf(Controller_U.INS_Out.vn * Controller_U.INS_Out.vn +
                       Controller_U.INS_Out.ve * Controller_U.INS_Out.ve);

    /* Trigonometry: '<S214>/Trigonometric Function1' */
    rtb_MatrixConcatenate1[0] = rtb_PitchOffset;

    /* Trigonometry: '<S214>/Trigonometric Function' */
    rtb_MatrixConcatenate1[1] = rtb_Saturation1_h_idx_0;

    /* SignalConversion: '<S214>/ConcatBufferAtVector Concatenate1In3' incorporates:
     *  Constant: '<S214>/Constant3'
     */
    rtb_MatrixConcatenate1[2] = 0.0F;

    /* Gain: '<S214>/Gain' incorporates:
     *  Gain: '<S213>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S214>/Trigonometric Function2'
     */
    rtb_MatrixConcatenate1[3] = -arm_sin_f32(-Controller_U.INS_Out.psi);

    /* Trigonometry: '<S214>/Trigonometric Function3' */
    rtb_MatrixConcatenate1[4] = rtb_PitchOffset;

    /* SignalConversion: '<S214>/ConcatBufferAtVector Concatenate2In3' incorporates:
     *  Constant: '<S214>/Constant4'
     */
    rtb_MatrixConcatenate1[5] = 0.0F;

    /* SignalConversion: '<S214>/ConcatBufferAtVector ConcatenateIn3' */
    rtb_MatrixConcatenate1[6] = Controller_ConstB.VectorConcatenate3_o[0];
    rtb_MatrixConcatenate1[7] = Controller_ConstB.VectorConcatenate3_o[1];
    rtb_MatrixConcatenate1[8] = Controller_ConstB.VectorConcatenate3_o[2];

    /* Product: '<S210>/Multiply' */
    for (i = 0; i < 3; i++) {
      rtb_Multiply_kn[i] = rtb_MatrixConcatenate1[i + 6] *
        rtb_DiscreteTimeIntegrator1_m_1 + (rtb_MatrixConcatenate1[i + 3] *
        rtb_DiscreteTimeIntegrator1_m_0 + rtb_MatrixConcatenate1[i] *
        rtb_DiscreteTimeIntegrator1_md_);
    }

    /* End of Product: '<S210>/Multiply' */

    /* DeadZone: '<S210>/Dead Zone' */
    if (rtb_Multiply_kn[0] > 1.0F) {
      rtb_Divide_i_idx_0 = rtb_Multiply_kn[0] - 1.0F;
    } else if (rtb_Multiply_kn[0] >= -1.0F) {
      rtb_Divide_i_idx_0 = 0.0F;
    } else {
      rtb_Divide_i_idx_0 = rtb_Multiply_kn[0] - -1.0F;
    }

    /* End of DeadZone: '<S210>/Dead Zone' */

    /* Saturate: '<S210>/Saturation1' incorporates:
     *  Sqrt: '<S210>/Sqrt'
     */
    if (rtb_Add_cs > 100.0F) {
      rtb_Add_cs = 100.0F;
    } else {
      if (rtb_Add_cs < 8.0F) {
        rtb_Add_cs = 8.0F;
      }
    }

    /* End of Saturate: '<S210>/Saturation1' */

    /* Signum: '<S210>/Sign' */
    if (rtb_Divide_i_idx_0 < 0.0F) {
      rtb_Divide_i_idx_0 = -1.0F;
    } else {
      if (rtb_Divide_i_idx_0 > 0.0F) {
        rtb_Divide_i_idx_0 = 1.0F;
      }
    }

    /* End of Signum: '<S210>/Sign' */

    /* Product: '<S210>/Multiply1' incorporates:
     *  Gain: '<S210>/Gain'
     *  Product: '<S210>/Divide'
     *  Trigonometry: '<S210>/Asin'
     */
    rtb_Add_cs = atanf(-Controller_U.FMS_Out.w_cmd / rtb_Add_cs) *
      rtb_Divide_i_idx_0;

    /* Saturate: '<S210>/Saturation2' */
    if (rtb_Add_cs > 0.785398185F) {
      rtb_Add_cs = 0.785398185F;
    } else {
      if (rtb_Add_cs < -0.785398185F) {
        rtb_Add_cs = -0.785398185F;
      }
    }

    /* End of Saturate: '<S210>/Saturation2' */

    /* Sum: '<S203>/Minus' */
    rtb_Minus = rtb_Add_cs - rtb_u_c;

    /* Sqrt: '<S229>/Sqrt' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Math: '<S229>/Square'
     *  Sum: '<S229>/Sum of Elements'
     */
    rtb_Sum = sqrtf(((Controller_U.INS_Out.quat[0] * Controller_U.INS_Out.quat[0]
                      + Controller_U.INS_Out.quat[1] *
                      Controller_U.INS_Out.quat[1]) + Controller_U.INS_Out.quat
                     [2] * Controller_U.INS_Out.quat[2]) +
                    Controller_U.INS_Out.quat[3] * Controller_U.INS_Out.quat[3]);

    /* Product: '<S225>/Divide' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_i_idx_0 = Controller_U.INS_Out.quat[0] / rtb_Sum;
    rtb_Divide_i_idx_1 = Controller_U.INS_Out.quat[1] / rtb_Sum;
    rtb_Divide_i_idx_2 = Controller_U.INS_Out.quat[2] / rtb_Sum;
    rtb_Divide_i_idx_3 = Controller_U.INS_Out.quat[3] / rtb_Sum;

    /* Math: '<S226>/Square' incorporates:
     *  Math: '<S227>/Square'
     *  Math: '<S228>/Square'
     */
    rtb_PitchOffset = rtb_Divide_i_idx_0 * rtb_Divide_i_idx_0;

    /* Math: '<S226>/Square2' incorporates:
     *  Math: '<S227>/Square2'
     *  Math: '<S228>/Square2'
     */
    rtb_Saturation1_h_idx_0 = rtb_Divide_i_idx_2 * rtb_Divide_i_idx_2;

    /* Math: '<S226>/Square1' incorporates:
     *  Math: '<S227>/Square1'
     *  Math: '<S228>/Square1'
     */
    rtb_Gain_il = rtb_Divide_i_idx_1 * rtb_Divide_i_idx_1;

    /* Math: '<S226>/Square3' incorporates:
     *  Math: '<S227>/Square3'
     *  Math: '<S228>/Square3'
     */
    rtb_Add_cs = rtb_Divide_i_idx_3 * rtb_Divide_i_idx_3;

    /* Sum: '<S226>/Subtract' incorporates:
     *  Math: '<S226>/Square'
     *  Math: '<S226>/Square1'
     *  Math: '<S226>/Square2'
     *  Math: '<S226>/Square3'
     *  Sum: '<S226>/Add'
     *  Sum: '<S226>/Add1'
     */
    rtb_MatrixConcatenate1[0] = (rtb_PitchOffset + rtb_Gain_il) -
      (rtb_Saturation1_h_idx_0 + rtb_Add_cs);

    /* Product: '<S226>/Multiply' incorporates:
     *  Product: '<S227>/Multiply'
     */
    rtb_Sum = rtb_Divide_i_idx_1 * rtb_Divide_i_idx_2;

    /* Product: '<S226>/Multiply1' incorporates:
     *  Product: '<S227>/Multiply1'
     */
    rtb_Saturation_a5 = rtb_Divide_i_idx_0 * rtb_Divide_i_idx_3;

    /* Gain: '<S226>/Gain' incorporates:
     *  Product: '<S226>/Multiply'
     *  Product: '<S226>/Multiply1'
     *  Sum: '<S226>/Subtract1'
     */
    rtb_MatrixConcatenate1[1] = (rtb_Sum - rtb_Saturation_a5) * 2.0F;

    /* Product: '<S226>/Multiply2' incorporates:
     *  Product: '<S228>/Multiply'
     */
    rtb_Add1_j4 = rtb_Divide_i_idx_1 * rtb_Divide_i_idx_3;

    /* Product: '<S226>/Multiply3' incorporates:
     *  Product: '<S228>/Multiply1'
     */
    rtb_MatrixConcatenate1_tmp = rtb_Divide_i_idx_0 * rtb_Divide_i_idx_2;

    /* Gain: '<S226>/Gain1' incorporates:
     *  Product: '<S226>/Multiply2'
     *  Product: '<S226>/Multiply3'
     *  Sum: '<S226>/Add2'
     */
    rtb_MatrixConcatenate1[2] = (rtb_Add1_j4 + rtb_MatrixConcatenate1_tmp) *
      2.0F;

    /* Gain: '<S227>/Gain' incorporates:
     *  Sum: '<S227>/Add3'
     */
    rtb_MatrixConcatenate1[3] = (rtb_Sum + rtb_Saturation_a5) * 2.0F;

    /* Sum: '<S227>/Subtract' incorporates:
     *  Sum: '<S227>/Add'
     *  Sum: '<S227>/Add1'
     */
    rtb_MatrixConcatenate1[4] = (rtb_PitchOffset + rtb_Saturation1_h_idx_0) -
      (rtb_Gain_il + rtb_Add_cs);

    /* Product: '<S227>/Multiply2' incorporates:
     *  Product: '<S228>/Multiply2'
     */
    rtb_Sum = rtb_Divide_i_idx_2 * rtb_Divide_i_idx_3;

    /* Product: '<S227>/Multiply3' incorporates:
     *  Product: '<S228>/Multiply3'
     */
    rtb_Saturation_a5 = rtb_Divide_i_idx_0 * rtb_Divide_i_idx_1;

    /* Gain: '<S227>/Gain1' incorporates:
     *  Product: '<S227>/Multiply2'
     *  Product: '<S227>/Multiply3'
     *  Sum: '<S227>/Subtract1'
     */
    rtb_MatrixConcatenate1[5] = (rtb_Sum - rtb_Saturation_a5) * 2.0F;

    /* Gain: '<S228>/Gain' incorporates:
     *  Sum: '<S228>/Subtract2'
     */
    rtb_MatrixConcatenate1[6] = (rtb_Add1_j4 - rtb_MatrixConcatenate1_tmp) *
      2.0F;

    /* Gain: '<S228>/Gain1' incorporates:
     *  Sum: '<S228>/Add2'
     */
    rtb_MatrixConcatenate1[7] = (rtb_Sum + rtb_Saturation_a5) * 2.0F;

    /* Sum: '<S228>/Subtract' incorporates:
     *  Sum: '<S228>/Add'
     *  Sum: '<S228>/Add1'
     */
    rtb_MatrixConcatenate1[8] = (rtb_PitchOffset + rtb_Add_cs) - (rtb_Gain_il +
      rtb_Saturation1_h_idx_0);

    /* Product: '<S222>/Multiply' */
    for (i = 0; i < 3; i++) {
      rtb_Multiply_kn[i] = rtb_MatrixConcatenate1[i + 6] *
        rtb_DiscreteTimeIntegrator1_m_1 + (rtb_MatrixConcatenate1[i + 3] *
        rtb_DiscreteTimeIntegrator1_m_0 + rtb_MatrixConcatenate1[i] *
        rtb_DiscreteTimeIntegrator1_md_);
    }

    /* End of Product: '<S222>/Multiply' */

    /* Switch: '<S222>/Switch' incorporates:
     *  Constant: '<S223>/Constant'
     *  Inport: '<Root>/INS_Out'
     *  RelationalOperator: '<S223>/Compare'
     */
    if (rtb_Multiply_kn[0] >= 3.0F) {
      rtb_Divide_i_idx_0 = Controller_U.INS_Out.airspeed;
    } else {
      rtb_Divide_i_idx_0 = rtb_Multiply_kn[0];
    }

    /* End of Switch: '<S222>/Switch' */

    /* Sum: '<S207>/Sum' incorporates:
     *  Gain: '<S207>/Gain'
     *  Sum: '<S207>/Minus'
     */
    rtb_Sum = (Controller_U.FMS_Out.u_cmd - rtb_Divide_i_idx_0) * 0.101936802F -
      rtb_VdotPg;

    /* Sum: '<S185>/Minus1' incorporates:
     *  Gain: '<S185>/ucmd2pitch'
     *  Gain: '<S185>/wcmd2pitch'
     */
    rtb_Divide_i_idx_3 = CONTROL_PARAM.FW_TECS_W2P * rtb_Minus -
      CONTROL_PARAM.FW_TECS_U2P * rtb_Sum;

    /* DiscreteIntegrator: '<S217>/ ' */
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

    /* DiscreteIntegrator: '<S218>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_f != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_e = rtb_Divide_i_idx_3;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_b != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_e = rtb_Divide_i_idx_3;
    }

    /* Gain: '<S218>/Gain' incorporates:
     *  DiscreteIntegrator: '<S218>/Discrete-Time Integrator1'
     *  Sum: '<S218>/Sum5'
     */
    rtb_Gain_il = (rtb_Divide_i_idx_3 -
                   Controller_DW.DiscreteTimeIntegrator1_DSTAT_e) * 62.831852F;

    /* Switch: '<S218>/Switch' incorporates:
     *  Gain: '<S218>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_Saturation_a5 = 0.0F;
    } else {
      rtb_Saturation_a5 = rtb_Gain_il;
    }

    /* End of Switch: '<S218>/Switch' */

    /* Gain: '<S216>/Gain' */
    rtb_PitchOffset = CONTROL_PARAM.FW_TECS_PITCH_D * rtb_Saturation_a5;

    /* Saturate: '<S205>/Saturation1' */
    if (rtb_PitchOffset > 0.3F) {
      rtb_PitchOffset = 0.3F;
    } else {
      if (rtb_PitchOffset < -0.3F) {
        rtb_PitchOffset = -0.3F;
      }
    }

    /* End of Saturate: '<S205>/Saturation1' */

    /* Sum: '<S185>/Sum' incorporates:
     *  DiscreteIntegrator: '<S217>/ '
     *  Gain: '<S185>/Gain'
     *  Gain: '<S185>/balabnce_ratio2'
     *  Gain: '<S185>/pitch_ff'
     *  Gain: '<S205>/P_control'
     *  Sum: '<S185>/Add3'
     *  Sum: '<S185>/Minus'
     *  Sum: '<S205>/Add'
     */
    rtb_PitchOffset = (((2.0F - CONTROL_PARAM.FW_TECS_RATIO) * rtb_u_c -
                        rtb_VdotPg) * CONTROL_PARAM.FW_TECS_PITCH_F +
                       ((CONTROL_PARAM.FW_TECS_PITCH_P * rtb_Divide_i_idx_3 +
                         Controller_DW._DSTATE) + rtb_PitchOffset)) +
      CONTROL_PARAM.FW_TECS_R2P * rtb_Abs;

    /* Switch: '<S163>/Switch' incorporates:
     *  Constant: '<S166>/Constant'
     *  RelationalOperator: '<S166>/Compare'
     */
    if (rtb_BitwiseAND_n <= 4) {
      rtb_Add_cs = Controller_U.FMS_Out.phi_cmd;
    } else {
      rtb_Add_cs = rtb_phi_cmd;
    }

    /* End of Switch: '<S163>/Switch' */

    /* Sum: '<S157>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_i_idx_2 = rtb_Add_cs - Controller_U.INS_Out.phi;

    /* Switch: '<S164>/Switch' incorporates:
     *  Constant: '<S167>/Constant'
     *  RelationalOperator: '<S167>/Compare'
     */
    if (rtb_BitwiseAND_n <= 3) {
      rtb_Add_cs = Controller_U.FMS_Out.theta_cmd;
    } else {
      rtb_Add_cs = rtb_PitchOffset;
    }

    /* End of Switch: '<S164>/Switch' */

    /* Sum: '<S157>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_i_idx_1 = rtb_Add_cs - Controller_U.INS_Out.theta;

    /* Product: '<S160>/Divide1' incorporates:
     *  Abs: '<S160>/Abs'
     *  Constant: '<S160>/const2'
     */
    rtb_DiscreteTimeIntegrator1_m_1 = fabsf(rtb_Divide_i_idx_2) / 0.002F;

    /* Product: '<S160>/Divide' incorporates:
     *  Constant: '<S158>/Constant1'
     *  Constant: '<S160>/const1'
     *  Math: '<S160>/Square'
     *  SignalConversion: '<S160>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_DiscreteTimeIntegrator1_md_ = 9.5993F / (CONTROL_PARAM.MC_ROLL_P *
      CONTROL_PARAM.MC_ROLL_P);

    /* Signum: '<S160>/Sign' incorporates:
     *  Abs: '<S160>/Abs'
     */
    if (rtb_Divide_i_idx_2 < 0.0F) {
      rtb_Add_cs = -1.0F;
    } else if (rtb_Divide_i_idx_2 > 0.0F) {
      rtb_Add_cs = 1.0F;
    } else {
      rtb_Add_cs = rtb_Divide_i_idx_2;
    }

    /* Switch: '<S160>/Switch' incorporates:
     *  Abs: '<S160>/Abs'
     *  Constant: '<S158>/Constant1'
     *  Gain: '<S160>/Gain1'
     *  Gain: '<S160>/Gain2'
     *  Logic: '<S160>/Logical Operator'
     *  Product: '<S160>/Divide'
     *  Product: '<S160>/Multiply'
     *  Product: '<S160>/Multiply1'
     *  Product: '<S160>/Multiply2'
     *  Product: '<S160>/Multiply3'
     *  RelationalOperator: '<S160>/Relational Operator'
     *  RelationalOperator: '<S160>/Relational Operator2'
     *  SignalConversion: '<S160>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S160>/Sqrt'
     *  Sum: '<S160>/Subtract'
     */
    if ((rtb_Divide_i_idx_2 <= rtb_DiscreteTimeIntegrator1_md_) &&
        (rtb_Divide_i_idx_2 >= -rtb_DiscreteTimeIntegrator1_md_)) {
      rtb_Add_cs = rtb_Divide_i_idx_2 * CONTROL_PARAM.MC_ROLL_P;
    } else {
      rtb_Add_cs *= sqrtf((rtb_Add_cs * rtb_Divide_i_idx_2 - 0.5F *
                           rtb_DiscreteTimeIntegrator1_md_) *
                          Controller_ConstB.Gain_np);
    }

    /* Gain: '<S160>/Gain3' */
    rtb_DiscreteTimeIntegrator1_md_ = -rtb_DiscreteTimeIntegrator1_m_1;

    /* Switch: '<S161>/Switch' incorporates:
     *  Gain: '<S160>/Gain3'
     *  RelationalOperator: '<S161>/UpperRelop'
     */
    if (rtb_Add_cs >= -rtb_DiscreteTimeIntegrator1_m_1) {
      rtb_DiscreteTimeIntegrator1_md_ = rtb_Add_cs;
    }

    /* Switch: '<S161>/Switch2' incorporates:
     *  RelationalOperator: '<S161>/LowerRelop1'
     */
    if (rtb_Add_cs <= rtb_DiscreteTimeIntegrator1_m_1) {
      rtb_DiscreteTimeIntegrator1_m_1 = rtb_DiscreteTimeIntegrator1_md_;
    }

    /* Saturate: '<S146>/Saturation1' */
    if (rtb_DiscreteTimeIntegrator1_m_1 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_DiscreteTimeIntegrator1_m_1 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_DiscreteTimeIntegrator1_m_1 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_DiscreteTimeIntegrator1_m_1 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    rtb_Saturation1_h_idx_0 = rtb_DiscreteTimeIntegrator1_m_1;

    /* Product: '<S160>/Divide1' incorporates:
     *  Abs: '<S160>/Abs'
     *  Constant: '<S160>/const2'
     */
    rtb_DiscreteTimeIntegrator1_m_1 = fabsf(rtb_Divide_i_idx_1) / 0.002F;

    /* Product: '<S160>/Divide' incorporates:
     *  Constant: '<S158>/Constant2'
     *  Constant: '<S160>/const1'
     *  Math: '<S160>/Square'
     *  SignalConversion: '<S160>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_DiscreteTimeIntegrator1_md_ = 9.5993F / (CONTROL_PARAM.MC_PITCH_P *
      CONTROL_PARAM.MC_PITCH_P);

    /* Signum: '<S160>/Sign' incorporates:
     *  Abs: '<S160>/Abs'
     */
    if (rtb_Divide_i_idx_1 < 0.0F) {
      rtb_Add_cs = -1.0F;
    } else if (rtb_Divide_i_idx_1 > 0.0F) {
      rtb_Add_cs = 1.0F;
    } else {
      rtb_Add_cs = rtb_Divide_i_idx_1;
    }

    /* Switch: '<S160>/Switch' incorporates:
     *  Abs: '<S160>/Abs'
     *  Constant: '<S158>/Constant2'
     *  Gain: '<S160>/Gain1'
     *  Gain: '<S160>/Gain2'
     *  Logic: '<S160>/Logical Operator'
     *  Product: '<S160>/Divide'
     *  Product: '<S160>/Multiply'
     *  Product: '<S160>/Multiply1'
     *  Product: '<S160>/Multiply2'
     *  Product: '<S160>/Multiply3'
     *  RelationalOperator: '<S160>/Relational Operator'
     *  RelationalOperator: '<S160>/Relational Operator2'
     *  SignalConversion: '<S160>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S160>/Sqrt'
     *  Sum: '<S160>/Subtract'
     */
    if ((rtb_Divide_i_idx_1 <= rtb_DiscreteTimeIntegrator1_md_) &&
        (rtb_Divide_i_idx_1 >= -rtb_DiscreteTimeIntegrator1_md_)) {
      rtb_Add_cs = rtb_Divide_i_idx_1 * CONTROL_PARAM.MC_PITCH_P;
    } else {
      rtb_Add_cs *= sqrtf((rtb_Add_cs * rtb_Divide_i_idx_1 - 0.5F *
                           rtb_DiscreteTimeIntegrator1_md_) *
                          Controller_ConstB.Gain_np);
    }

    /* Gain: '<S160>/Gain3' */
    rtb_DiscreteTimeIntegrator1_md_ = -rtb_DiscreteTimeIntegrator1_m_1;

    /* Switch: '<S161>/Switch' incorporates:
     *  Gain: '<S160>/Gain3'
     *  RelationalOperator: '<S161>/UpperRelop'
     */
    if (rtb_Add_cs >= -rtb_DiscreteTimeIntegrator1_m_1) {
      rtb_DiscreteTimeIntegrator1_md_ = rtb_Add_cs;
    }

    /* Switch: '<S161>/Switch2' incorporates:
     *  RelationalOperator: '<S161>/LowerRelop1'
     */
    if (rtb_Add_cs <= rtb_DiscreteTimeIntegrator1_m_1) {
      rtb_DiscreteTimeIntegrator1_m_1 = rtb_DiscreteTimeIntegrator1_md_;
    }

    /* Saturate: '<S146>/Saturation1' */
    if (rtb_DiscreteTimeIntegrator1_m_1 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_DiscreteTimeIntegrator1_m_1 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_DiscreteTimeIntegrator1_m_1 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_DiscreteTimeIntegrator1_m_1 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    /* Saturate: '<S146>/Saturation' */
    if (Controller_U.FMS_Out.psi_rate_cmd > CONTROL_PARAM.MC_R_CMD_LIM) {
      rtb_Divide_i_idx_2 = CONTROL_PARAM.MC_R_CMD_LIM;
    } else if (Controller_U.FMS_Out.psi_rate_cmd < -CONTROL_PARAM.MC_R_CMD_LIM)
    {
      rtb_Divide_i_idx_2 = -CONTROL_PARAM.MC_R_CMD_LIM;
    } else {
      rtb_Divide_i_idx_2 = Controller_U.FMS_Out.psi_rate_cmd;
    }

    /* End of Saturate: '<S146>/Saturation' */

    /* Trigonometry: '<S155>/Sin' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S188>/Sin'
     */
    rtb_Divide_i_idx_0 = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S155>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S188>/Cos1'
     */
    rtb_Divide_i_idx_1 = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Trigonometry: '<S155>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S188>/Cos'
     */
    rtb_Saturation_a5 = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S155>/Sin1' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S188>/Sin1'
     */
    rtb_Add1_j4 = arm_sin_f32(Controller_U.INS_Out.theta);

    /* Sum: '<S147>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S155>/Multiply'
     *  Product: '<S155>/Multiply1'
     *  Product: '<S155>/Multiply3'
     *  Product: '<S155>/Multiply4'
     *  Product: '<S155>/Multiply5'
     *  Sum: '<S155>/Add'
     *  Sum: '<S155>/Add1'
     *  Sum: '<S155>/Add2'
     *  Trigonometry: '<S155>/Cos'
     *  Trigonometry: '<S155>/Cos1'
     *  Trigonometry: '<S155>/Sin'
     *  Trigonometry: '<S155>/Sin1'
     */
    rtb_DiscreteTimeIntegrator1_md_ = (rtb_Saturation1_h_idx_0 - rtb_Add1_j4 *
      rtb_Divide_i_idx_2) - Controller_U.INS_Out.p;
    rtb_DiscreteTimeIntegrator1_m_0 = (rtb_Divide_i_idx_0 * rtb_Divide_i_idx_1 *
      rtb_Divide_i_idx_2 + rtb_Saturation_a5 * rtb_DiscreteTimeIntegrator1_m_1)
      - Controller_U.INS_Out.q;
    rtb_DiscreteTimeIntegrator1_m_1 = (rtb_Saturation_a5 * rtb_Divide_i_idx_1 *
      rtb_Divide_i_idx_2 - rtb_Divide_i_idx_0 * rtb_DiscreteTimeIntegrator1_m_1)
      - Controller_U.INS_Out.r;

    /* DiscreteIntegrator: '<S150>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_b != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0] =
        rtb_DiscreteTimeIntegrator1_md_;
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1] =
        rtb_DiscreteTimeIntegrator1_m_0;
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2] =
        rtb_DiscreteTimeIntegrator1_m_1;
    }

    /* Logic: '<S142>/Logical Operator' incorporates:
     *  Constant: '<S144>/Constant'
     *  DiscreteIntegrator: '<S181>/Discrete-Time Integrator5'
     *  RelationalOperator: '<S144>/Compare'
     */
    rtb_LogicalOperator_m = ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator5_DSTA_a2 == 0.0F));

    /* DiscreteIntegrator: '<S152>/Discrete-Time Integrator' */
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

    /* DiscreteIntegrator: '<S154>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S150>/Discrete-Time Integrator5'
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

    /* Gain: '<S154>/Gain' incorporates:
     *  DiscreteIntegrator: '<S150>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S154>/Discrete-Time Integrator1'
     *  Sum: '<S154>/Sum5'
     */
    rtb_Multiply_kn[0] = (Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0] -
                          Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[0]) *
      188.49556F;
    rtb_Multiply_kn[1] = (Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1] -
                          Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[1]) *
      188.49556F;
    rtb_Multiply_kn[2] = (Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2] -
                          Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[2]) *
      188.49556F;

    /* DiscreteIntegrator: '<S180>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_g != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j = rtb_Saturation_ov;
    }

    /* Switch: '<S196>/Switch' incorporates:
     *  Logic: '<S196>/Logical Operator'
     *  RelationalOperator: '<S201>/Compare'
     */
    if ((rtb_BitwiseAND_n == 3) || (rtb_BitwiseAND_n == 4)) {
      rtb_phi_cmd = Controller_U.FMS_Out.phi_cmd;
    }

    /* End of Switch: '<S196>/Switch' */

    /* Switch: '<S196>/Switch1' incorporates:
     *  Constant: '<S202>/Constant'
     *  RelationalOperator: '<S202>/Compare'
     */
    if (rtb_BitwiseAND_n == 3) {
      rtb_PitchOffset = Controller_U.FMS_Out.theta_cmd;
    }

    /* End of Switch: '<S196>/Switch1' */

    /* Bias: '<S197>/Pitch Offset' */
    rtb_PitchOffset += CONTROL_PARAM.FW_PITCH_OFFSET;

    /* Saturate: '<S197>/Saturation' */
    if (rtb_PitchOffset > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_PitchOffset = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_PitchOffset < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_PitchOffset = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      }
    }

    /* Product: '<S198>/Multiply' incorporates:
     *  Constant: '<S198>/Constant2'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S197>/Sum'
     */
    rtb_PitchOffset = (rtb_PitchOffset - Controller_U.INS_Out.theta) *
      CONTROL_PARAM.FW_PITCH_P;

    /* Product: '<S200>/Divide' incorporates:
     *  Constant: '<S200>/Constant'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Add_cs = 9.81F / Controller_U.INS_Out.airspeed;

    /* Saturate: '<S200>/Saturation' */
    if (rtb_Add_cs > 1.0F) {
      rtb_Add_cs = 1.0F;
    } else {
      if (rtb_Add_cs < 0.0F) {
        rtb_Add_cs = 0.0F;
      }
    }

    /* End of Saturate: '<S200>/Saturation' */

    /* Sum: '<S195>/Sum' incorporates:
     *  Product: '<S200>/Multiply'
     *  Product: '<S200>/Multiply1'
     *  Trigonometry: '<S200>/Cos'
     *  Trigonometry: '<S200>/Tan'
     */
    rtb_Divide_i_idx_2 = tanf(Controller_U.FMS_Out.phi_cmd) * arm_cos_f32
      (Controller_U.FMS_Out.theta_cmd) * rtb_Add_cs +
      Controller_U.FMS_Out.psi_rate_cmd;

    /* Saturate: '<S197>/Saturation' */
    if (rtb_phi_cmd > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_phi_cmd = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_phi_cmd < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_phi_cmd = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      }
    }

    /* Sum: '<S188>/Add' incorporates:
     *  Constant: '<S198>/Constant1'
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S188>/Multiply'
     *  Product: '<S198>/Multiply'
     *  Sum: '<S197>/Sum'
     */
    rtb_Add_cs = (rtb_phi_cmd - Controller_U.INS_Out.phi) *
      CONTROL_PARAM.FW_ROLL_P - rtb_Add1_j4 * rtb_Divide_i_idx_2;

    /* Sum: '<S188>/Add1' incorporates:
     *  Product: '<S188>/Multiply1'
     *  Product: '<S188>/Multiply3'
     */
    rtb_Add1_j4 = rtb_Divide_i_idx_0 * rtb_Divide_i_idx_1 * rtb_Divide_i_idx_2 +
      rtb_Saturation_a5 * rtb_PitchOffset;

    /* Sum: '<S188>/Add2' incorporates:
     *  Product: '<S188>/Multiply4'
     *  Product: '<S188>/Multiply5'
     */
    rtb_Divide_i_idx_2 = rtb_Saturation_a5 * rtb_Divide_i_idx_1 *
      rtb_Divide_i_idx_2 - rtb_Divide_i_idx_0 * rtb_PitchOffset;

    /* Sum: '<S186>/Minus2' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_phi_cmd = rtb_Add_cs - Controller_U.INS_Out.p;
    rtb_PitchOffset = rtb_Add1_j4 - Controller_U.INS_Out.q;
    rtb_Divide_i_idx_0 = rtb_Divide_i_idx_2 - Controller_U.INS_Out.r;

    /* DiscreteIntegrator: '<S192>/Discrete-Time Integrator' */
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

    /* Sum: '<S185>/Add' incorporates:
     *  Gain: '<S185>/ucmd2thor'
     *  Gain: '<S185>/wcmd2thor'
     */
    rtb_Saturation1_h_idx_0 = CONTROL_PARAM.FW_TECS_W2T * rtb_Minus +
      CONTROL_PARAM.FW_TECS_U2T * rtb_Sum;

    /* DiscreteIntegrator: '<S220>/ ' */
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

    /* DiscreteIntegrator: '<S221>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_L_h0 != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm = rtb_Saturation1_h_idx_0;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_d != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm = rtb_Saturation1_h_idx_0;
    }

    /* Gain: '<S221>/Gain' incorporates:
     *  DiscreteIntegrator: '<S221>/Discrete-Time Integrator1'
     *  Sum: '<S221>/Sum5'
     */
    rtb_Divide_i_idx_1 = (rtb_Saturation1_h_idx_0 -
                          Controller_DW.DiscreteTimeIntegrator1_DSTA_nm) *
      188.49556F;

    /* Outputs for Atomic SubSystem: '<S231>/VTOL1' */
    /* MultiPortSwitch: '<S235>/Multiport Switch' incorporates:
     *  Constant: '<S235>/Disarm'
     *  Constant: '<S235>/Standby'
     *  Constant: '<S236>/Constant1'
     *  Constant: '<S236>/Constant12'
     *  Constant: '<S236>/Constant2'
     *  Constant: '<S236>/Constant7'
     */
    switch (Controller_U.FMS_Out.status) {
     case 1:
      for (i = 0; i < 9; i++) {
        rtb_MultiportSwitch_i[i] = Controller_ConstP.pooled34[i];
      }
      break;

     case 2:
      for (i = 0; i < 9; i++) {
        rtb_MultiportSwitch_i[i] = Controller_ConstP.pooled35[i];
      }
      break;

     case 3:
      /* Saturate: '<S186>/Saturation1' incorporates:
       *  Inport: '<Root>/INS_Out'
       */
      if (Controller_U.INS_Out.airspeed > 999.0F) {
        rtb_Saturation_a5 = 999.0F;
      } else if (Controller_U.INS_Out.airspeed < 0.1F) {
        rtb_Saturation_a5 = 0.1F;
      } else {
        rtb_Saturation_a5 = Controller_U.INS_Out.airspeed;
      }

      /* End of Saturate: '<S186>/Saturation1' */

      /* Product: '<S190>/Divide' incorporates:
       *  Constant: '<S190>/trim_speed'
       *  Math: '<S190>/Square'
       *  Math: '<S190>/Square1'
       */
      rtb_Saturation_gg = CONTROL_PARAM.FW_AIRSPEED_TRIM *
        CONTROL_PARAM.FW_AIRSPEED_TRIM / (rtb_Saturation_a5 * rtb_Saturation_a5);

      /* Saturate: '<S190>/Saturation' */
      if (rtb_Saturation_gg > 1.0F) {
        rtb_Saturation_gg = 1.0F;
      } else {
        if (rtb_Saturation_gg < 0.0F) {
          rtb_Saturation_gg = 0.0F;
        }
      }

      /* End of Saturate: '<S190>/Saturation' */

      /* Product: '<S191>/Divide' incorporates:
       *  Constant: '<S191>/trim_speed'
       */
      rtb_Saturation_a5 = CONTROL_PARAM.FW_AIRSPEED_TRIM / rtb_Saturation_a5;

      /* Saturate: '<S191>/Saturation' */
      if (rtb_Saturation_a5 > 1.0F) {
        rtb_Saturation_a5 = 1.0F;
      } else {
        if (rtb_Saturation_a5 < 0.0F) {
          rtb_Saturation_a5 = 0.0F;
        }
      }

      /* End of Saturate: '<S191>/Saturation' */

      /* Product: '<S186>/Multiply1' incorporates:
       *  Gain: '<S186>/FF'
       */
      rtb_Add_cs = CONTROL_PARAM.FW_FF * rtb_Add_cs * rtb_Saturation_a5;

      /* Product: '<S186>/Multiply' incorporates:
       *  Constant: '<S193>/gain1'
       *  DiscreteIntegrator: '<S192>/Discrete-Time Integrator'
       *  Product: '<S193>/Multiply'
       *  Sum: '<S189>/Add1'
       */
      rtb_Minus = (CONTROL_PARAM.FW_ROLL_RATE_P * rtb_phi_cmd +
                   Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0]) *
        rtb_Saturation_gg;

      /* Product: '<S186>/Multiply1' incorporates:
       *  Gain: '<S186>/FF'
       */
      rtb_Sum = CONTROL_PARAM.FW_FF * rtb_Add1_j4 * rtb_Saturation_a5;

      /* Product: '<S186>/Multiply' incorporates:
       *  Constant: '<S193>/gain2'
       *  DiscreteIntegrator: '<S192>/Discrete-Time Integrator'
       *  Product: '<S193>/Multiply'
       *  Sum: '<S189>/Add1'
       */
      rtb_Add1_j4 = (CONTROL_PARAM.FW_PITCH_RATE_P * rtb_PitchOffset +
                     Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1]) *
        rtb_Saturation_gg;

      /* Product: '<S186>/Multiply1' incorporates:
       *  Gain: '<S186>/FF'
       */
      rtb_Divide_i_idx_2 = CONTROL_PARAM.FW_FF * rtb_Divide_i_idx_2 *
        rtb_Saturation_a5;

      /* Product: '<S186>/Multiply' incorporates:
       *  Constant: '<S193>/gain3'
       *  DiscreteIntegrator: '<S192>/Discrete-Time Integrator'
       *  Product: '<S193>/Multiply'
       *  Sum: '<S189>/Add1'
       */
      rtb_MatrixConcatenate1_tmp = (CONTROL_PARAM.FW_YAW_RATE_P *
        rtb_Divide_i_idx_0 + Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2]) *
        rtb_Saturation_gg;
      rtb_MatrixConcatenate_a[11] = CONTROL_PARAM.FW_YAW_EFFC;

      /* SignalConversion: '<S236>/ConcatBufferAtVector Concatenate2In3' incorporates:
       *  Constant: '<S236>/Constant11'
       *  Constant: '<S236>/Constant12'
       */
      rtb_MatrixConcatenate_a[10] = 0.0F;

      /* SignalConversion: '<S236>/ConcatBufferAtVector Concatenate2In2' incorporates:
       *  Constant: '<S236>/Constant10'
       */
      rtb_MatrixConcatenate_a[9] = 0.0F;

      /* SignalConversion: '<S236>/ConcatBufferAtVector Concatenate2In1' incorporates:
       *  Constant: '<S236>/Constant9'
       */
      rtb_MatrixConcatenate_a[8] = 0.0F;

      /* SignalConversion: '<S236>/ConcatBufferAtVector Concatenate1In4' incorporates:
       *  Constant: '<S236>/Constant8'
       */
      rtb_MatrixConcatenate_a[7] = 0.0F;
      rtb_MatrixConcatenate_a[6] = CONTROL_PARAM.FW_PITCH_EFFC;

      /* SignalConversion: '<S236>/ConcatBufferAtVector Concatenate1In2' incorporates:
       *  Constant: '<S236>/Constant6'
       *  Constant: '<S236>/Constant7'
       */
      rtb_MatrixConcatenate_a[5] = 0.0F;

      /* SignalConversion: '<S236>/ConcatBufferAtVector Concatenate1In1' incorporates:
       *  Constant: '<S236>/Constant5'
       */
      rtb_MatrixConcatenate_a[4] = 0.0F;

      /* SignalConversion: '<S236>/ConcatBufferAtVector ConcatenateIn4' incorporates:
       *  Constant: '<S236>/Constant4'
       */
      rtb_MatrixConcatenate_a[3] = 0.0F;

      /* SignalConversion: '<S236>/ConcatBufferAtVector ConcatenateIn3' incorporates:
       *  Constant: '<S236>/Constant3'
       */
      rtb_MatrixConcatenate_a[2] = 0.0F;
      rtb_MatrixConcatenate_a[1] = CONTROL_PARAM.FW_ROLL_EFFC;
      rtb_MatrixConcatenate_a[0] = CONTROL_PARAM.FW_ROLL_EFFC;

      /* Switch: '<S237>/Switch' incorporates:
       *  Constant: '<S236>/Constant1'
       *  Constant: '<S236>/Constant2'
       *  Constant: '<S238>/Constant1'
       *  Constant: '<S239>/Constant'
       *  DataTypeConversion: '<S238>/Data Type Conversion'
       *  Gain: '<S238>/Gain1'
       *  RelationalOperator: '<S239>/Compare'
       *  Sum: '<S238>/Sum1'
       *  Switch: '<S221>/Switch'
       */
      if (rtb_BitwiseAND_n <= 3) {
        rtb_MultiportSwitch_i[4] = Controller_U.FMS_Out.throttle_cmd;
      } else {
        if (Controller_U.FMS_Out.reset > 0) {
          /* Switch: '<S221>/Switch' incorporates:
           *  Gain: '<S221>/Gain1'
           */
          rtb_Saturation_a5 = 0.0F;
        } else {
          /* Switch: '<S221>/Switch' */
          rtb_Saturation_a5 = rtb_Divide_i_idx_1;
        }

        /* Gain: '<S219>/Gain' */
        rtb_Saturation_a5 *= CONTROL_PARAM.FW_TECS_THOR_D;

        /* Saturate: '<S206>/Saturation1' */
        if (rtb_Saturation_a5 > 0.3F) {
          rtb_Saturation_a5 = 0.3F;
        } else {
          if (rtb_Saturation_a5 < -0.3F) {
            rtb_Saturation_a5 = -0.3F;
          }
        }

        /* End of Saturate: '<S206>/Saturation1' */

        /* Saturate: '<S137>/Saturation2' incorporates:
         *  Constant: '<S137>/cruise_throttle'
         *  DiscreteIntegrator: '<S220>/ '
         *  Gain: '<S185>/Gain1'
         *  Gain: '<S185>/balance_ratio'
         *  Gain: '<S185>/thorttle_ff'
         *  Gain: '<S206>/P_control'
         *  Saturate: '<S137>/Saturation'
         *  Sum: '<S137>/Sum'
         *  Sum: '<S185>/Add1'
         *  Sum: '<S185>/Add2'
         *  Sum: '<S185>/Sum1'
         *  Sum: '<S206>/Add4'
         */
        rtb_Abs = ((((CONTROL_PARAM.FW_TECS_THOR_P * rtb_Saturation1_h_idx_0 +
                      Controller_DW._DSTATE_d) + rtb_Saturation_a5) +
                    (CONTROL_PARAM.FW_TECS_RATIO * rtb_VdotPg + rtb_u_c) *
                    CONTROL_PARAM.FW_TECS_THOR_FF) + CONTROL_PARAM.FW_TECS_R2T *
                   rtb_Abs) + 0.5F;
        if (rtb_Abs > 1.0F) {
          rtb_Abs = 1.0F;
        } else {
          if (rtb_Abs < -1.0F) {
            rtb_Abs = -1.0F;
          }
        }

        /* Saturate: '<S238>/Saturation' incorporates:
         *  Saturate: '<S137>/Saturation2'
         */
        if (rtb_Abs < 0.0F) {
          rtb_Abs = 0.0F;
        }

        /* End of Saturate: '<S238>/Saturation' */
        rtb_MultiportSwitch_i[4] = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          rtb_Abs), 4.2949673E+9F) + 1000U);
      }

      /* End of Switch: '<S237>/Switch' */

      /* Switch: '<S154>/Switch' incorporates:
       *  Gain: '<S154>/Gain1'
       */
      if (rtb_LogicalOperator_m) {
        rtb_Abs = 0.0F;
        rtb_u_c = 0.0F;
        rtb_VdotPg = 0.0F;
      } else {
        rtb_Abs = rtb_Multiply_kn[0];
        rtb_u_c = rtb_Multiply_kn[1];
        rtb_VdotPg = rtb_Multiply_kn[2];
      }

      /* End of Switch: '<S154>/Switch' */

      /* Product: '<S151>/Multiply' incorporates:
       *  Constant: '<S151>/gain1'
       */
      rtb_Saturation_a5 = CONTROL_PARAM.MC_ROLL_RATE_D * rtb_Abs;

      /* Saturate: '<S151>/Saturation' */
      if (rtb_Saturation_a5 > CONTROL_PARAM.MC_RATE_D_MAX) {
        rtb_Saturation_a5 = CONTROL_PARAM.MC_RATE_D_MAX;
      } else {
        if (rtb_Saturation_a5 < CONTROL_PARAM.MC_RATE_D_MIN) {
          rtb_Saturation_a5 = CONTROL_PARAM.MC_RATE_D_MIN;
        }
      }

      /* Saturate: '<S135>/Saturation2' incorporates:
       *  Constant: '<S153>/gain1'
       *  DiscreteIntegrator: '<S150>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S152>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S181>/Discrete-Time Integrator5'
       *  Product: '<S135>/Multiply2'
       *  Product: '<S153>/Multiply'
       *  Sum: '<S148>/Add'
       */
      rtb_Abs = ((CONTROL_PARAM.MC_ROLL_RATE_P *
                  Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0] +
                  Controller_DW.DiscreteTimeIntegrator_DSTATE_d[0]) +
                 rtb_Saturation_a5) *
        Controller_DW.DiscreteTimeIntegrator5_DSTA_a2;
      if (rtb_Abs > 1.0F) {
        rtb_Abs = 1.0F;
      } else {
        if (rtb_Abs < -1.0F) {
          rtb_Abs = -1.0F;
        }
      }

      /* Product: '<S151>/Multiply' incorporates:
       *  Constant: '<S151>/gain2'
       */
      rtb_Saturation_a5 = CONTROL_PARAM.MC_PITCH_RATE_D * rtb_u_c;

      /* Saturate: '<S151>/Saturation' */
      if (rtb_Saturation_a5 > CONTROL_PARAM.MC_RATE_D_MAX) {
        rtb_Saturation_a5 = CONTROL_PARAM.MC_RATE_D_MAX;
      } else {
        if (rtb_Saturation_a5 < CONTROL_PARAM.MC_RATE_D_MIN) {
          rtb_Saturation_a5 = CONTROL_PARAM.MC_RATE_D_MIN;
        }
      }

      /* Saturate: '<S135>/Saturation2' incorporates:
       *  Constant: '<S153>/gain2'
       *  DiscreteIntegrator: '<S150>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S152>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S181>/Discrete-Time Integrator5'
       *  Product: '<S135>/Multiply2'
       *  Product: '<S153>/Multiply'
       *  Sum: '<S148>/Add'
       */
      rtb_u_c = ((CONTROL_PARAM.MC_PITCH_RATE_P *
                  Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1] +
                  Controller_DW.DiscreteTimeIntegrator_DSTATE_d[1]) +
                 rtb_Saturation_a5) *
        Controller_DW.DiscreteTimeIntegrator5_DSTA_a2;
      if (rtb_u_c > 1.0F) {
        rtb_u_c = 1.0F;
      } else {
        if (rtb_u_c < -1.0F) {
          rtb_u_c = -1.0F;
        }
      }

      /* Product: '<S151>/Multiply' incorporates:
       *  Constant: '<S151>/gain3'
       */
      rtb_Saturation_a5 = CONTROL_PARAM.MC_YAW_RATE_D * rtb_VdotPg;

      /* Saturate: '<S151>/Saturation' */
      if (rtb_Saturation_a5 > CONTROL_PARAM.MC_RATE_D_MAX) {
        rtb_Saturation_a5 = CONTROL_PARAM.MC_RATE_D_MAX;
      } else {
        if (rtb_Saturation_a5 < CONTROL_PARAM.MC_RATE_D_MIN) {
          rtb_Saturation_a5 = CONTROL_PARAM.MC_RATE_D_MIN;
        }
      }

      /* Saturate: '<S135>/Saturation2' incorporates:
       *  Constant: '<S153>/gain3'
       *  DiscreteIntegrator: '<S150>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S152>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S181>/Discrete-Time Integrator5'
       *  Product: '<S135>/Multiply2'
       *  Product: '<S153>/Multiply'
       *  Sum: '<S148>/Add'
       */
      rtb_VdotPg = ((CONTROL_PARAM.MC_YAW_RATE_P *
                     Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2] +
                     Controller_DW.DiscreteTimeIntegrator_DSTATE_d[2]) +
                    rtb_Saturation_a5) *
        Controller_DW.DiscreteTimeIntegrator5_DSTA_a2;
      if (rtb_VdotPg > 1.0F) {
        rtb_VdotPg = 1.0F;
      } else {
        if (rtb_VdotPg < -1.0F) {
          rtb_VdotPg = -1.0F;
        }
      }

      /* Product: '<S170>/Multiply' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S170>/Cos'
       *  Trigonometry: '<S170>/Cos1'
       */
      rtb_Saturation_a5 = arm_cos_f32(Controller_U.INS_Out.phi) * arm_cos_f32
        (Controller_U.INS_Out.theta);

      /* Gain: '<S170>/Gain' */
      rtb_Saturation_gg = 2.0F * rtb_Saturation_a5;

      /* Saturate: '<S170>/Saturation1' */
      if (rtb_Saturation_a5 > 1.0F) {
        rtb_Saturation_a5 = 1.0F;
      } else {
        if (rtb_Saturation_a5 < 0.5F) {
          rtb_Saturation_a5 = 0.5F;
        }
      }

      /* End of Saturate: '<S170>/Saturation1' */

      /* Product: '<S170>/Divide' incorporates:
       *  Constant: '<S170>/Constant'
       */
      rtb_boost_factor_o = 1.0F / rtb_Saturation_a5;

      /* Switch: '<S179>/Switch' incorporates:
       *  Gain: '<S179>/Gain1'
       */
      if (rtb_LogicalOperator_b3) {
        rtb_Saturation_a5 = 0.0F;
      } else {
        rtb_Saturation_a5 = rtb_Gain_it;
      }

      /* End of Switch: '<S179>/Switch' */

      /* Product: '<S176>/Multiply' incorporates:
       *  Constant: '<S176>/kd'
       */
      rtb_Saturation_a5 *= CONTROL_PARAM.MC_VEL_Z_D;

      /* Saturate: '<S176>/Saturation' */
      if (rtb_Saturation_a5 > CONTROL_PARAM.MC_VEL_Z_D_MAX) {
        rtb_Saturation_a5 = CONTROL_PARAM.MC_VEL_Z_D_MAX;
      } else {
        if (rtb_Saturation_a5 < CONTROL_PARAM.MC_VEL_Z_D_MIN) {
          rtb_Saturation_a5 = CONTROL_PARAM.MC_VEL_Z_D_MIN;
        }
      }

      /* End of Saturate: '<S176>/Saturation' */

      /* Saturate: '<S170>/Saturation' */
      if (rtb_Saturation_gg > 1.0F) {
        rtb_Saturation_gg = 1.0F;
      } else {
        if (rtb_Saturation_gg < 0.0F) {
          rtb_Saturation_gg = 0.0F;
        }
      }

      /* End of Saturate: '<S170>/Saturation' */

      /* Product: '<S170>/Multiply1' incorporates:
       *  Constant: '<S178>/kp'
       *  DiscreteIntegrator: '<S177>/Discrete-Time Integrator'
       *  Product: '<S178>/Multiply'
       *  Sum: '<S173>/Add'
       */
      rtb_Saturation_gg *= ((CONTROL_PARAM.MC_VEL_Z_P * rtb_Gain_ms +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_b) + rtb_Saturation_a5) *
        rtb_boost_factor_o;

      /* Saturate: '<S169>/Saturation' */
      if (rtb_Saturation_gg > 0.35F) {
        rtb_Saturation_gg = 0.35F;
      } else {
        if (rtb_Saturation_gg < -0.35F) {
          rtb_Saturation_gg = -0.35F;
        }
      }

      /* End of Saturate: '<S169>/Saturation' */

      /* Sum: '<S141>/Sum' incorporates:
       *  Constant: '<S141>/mc_hover_throttle'
       */
      rtb_Saturation_gg += CONTROL_PARAM.MC_HOVER_THRO;

      /* Saturate: '<S141>/Saturation' */
      if (rtb_Saturation_gg > 1.0F) {
        rtb_Saturation_gg = 1.0F;
      } else {
        if (rtb_Saturation_gg < -1.0F) {
          rtb_Saturation_gg = -1.0F;
        }
      }

      /* End of Saturate: '<S141>/Saturation' */

      /* Saturate: '<S135>/Saturation1' incorporates:
       *  DiscreteIntegrator: '<S181>/Discrete-Time Integrator5'
       *  Product: '<S135>/Multiply1'
       */
      rtb_Saturation_gg *= Controller_DW.DiscreteTimeIntegrator5_DSTA_a2;
      if (rtb_Saturation_gg > 1.0F) {
        rtb_Saturation_gg = 1.0F;
      } else {
        if (rtb_Saturation_gg < -1.0F) {
          rtb_Saturation_gg = -1.0F;
        }
      }

      /* End of Saturate: '<S135>/Saturation1' */

      /* Saturate: '<S240>/Saturation' incorporates:
       *  Saturate: '<S234>/Saturation2'
       */
      if (rtb_Saturation_gg < 0.0F) {
        rtb_Saturation_gg = 0.0F;
      }

      /* End of Saturate: '<S240>/Saturation' */

      /* DataTypeConversion: '<S240>/Data Type Conversion' incorporates:
       *  Constant: '<S240>/Constant1'
       *  Gain: '<S240>/Gain1'
       *  Sum: '<S240>/Sum1'
       */
      rtb_DataTypeConversion_k = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
        rtb_Saturation_gg), 4.2949673E+9F) + 1000U);

      /* Product: '<S234>/Multiply' incorporates:
       *  Constant: '<S234>/Effective_Matrix'
       *  Saturate: '<S234>/Saturation1'
       */
      for (i = 0; i < 4; i++) {
        tmp[i] = Controller_ConstP.pooled19[i + 8] * rtb_VdotPg +
          (Controller_ConstP.pooled19[i + 4] * rtb_u_c +
           Controller_ConstP.pooled19[i] * rtb_Abs);
      }

      /* End of Product: '<S234>/Multiply' */

      /* Saturate: '<S186>/FF_limit' */
      if (rtb_Add_cs > CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_Add_cs = CONTROL_PARAM.FW_FF_LIMIT;
      } else {
        if (rtb_Add_cs < -CONTROL_PARAM.FW_FF_LIMIT) {
          rtb_Add_cs = -CONTROL_PARAM.FW_FF_LIMIT;
        }
      }

      /* Saturate: '<S186>/PI_limit' */
      if (rtb_Minus > CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_Minus = CONTROL_PARAM.FW_PI_LIMIT;
      } else {
        if (rtb_Minus < -CONTROL_PARAM.FW_PI_LIMIT) {
          rtb_Minus = -CONTROL_PARAM.FW_PI_LIMIT;
        }
      }

      /* Saturate: '<S137>/Saturation1' incorporates:
       *  DiscreteIntegrator: '<S180>/Discrete-Time Integrator5'
       *  Product: '<S137>/Multiply'
       *  Sum: '<S186>/Add'
       */
      rtb_Add_cs = (rtb_Add_cs + rtb_Minus) *
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;
      if (rtb_Add_cs > 1.0F) {
        rtb_Add_cs = 1.0F;
      } else {
        if (rtb_Add_cs < -1.0F) {
          rtb_Add_cs = -1.0F;
        }
      }

      /* Saturate: '<S186>/FF_limit' */
      if (rtb_Sum > CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_Sum = CONTROL_PARAM.FW_FF_LIMIT;
      } else {
        if (rtb_Sum < -CONTROL_PARAM.FW_FF_LIMIT) {
          rtb_Sum = -CONTROL_PARAM.FW_FF_LIMIT;
        }
      }

      /* Saturate: '<S186>/PI_limit' */
      if (rtb_Add1_j4 > CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_Add1_j4 = CONTROL_PARAM.FW_PI_LIMIT;
      } else {
        if (rtb_Add1_j4 < -CONTROL_PARAM.FW_PI_LIMIT) {
          rtb_Add1_j4 = -CONTROL_PARAM.FW_PI_LIMIT;
        }
      }

      /* Saturate: '<S137>/Saturation1' incorporates:
       *  DiscreteIntegrator: '<S180>/Discrete-Time Integrator5'
       *  Product: '<S137>/Multiply'
       *  Sum: '<S186>/Add'
       */
      rtb_Minus = (rtb_Sum + rtb_Add1_j4) *
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;
      if (rtb_Minus > 1.0F) {
        rtb_Minus = 1.0F;
      } else {
        if (rtb_Minus < -1.0F) {
          rtb_Minus = -1.0F;
        }
      }

      /* Saturate: '<S186>/FF_limit' */
      if (rtb_Divide_i_idx_2 > CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_Divide_i_idx_2 = CONTROL_PARAM.FW_FF_LIMIT;
      } else {
        if (rtb_Divide_i_idx_2 < -CONTROL_PARAM.FW_FF_LIMIT) {
          rtb_Divide_i_idx_2 = -CONTROL_PARAM.FW_FF_LIMIT;
        }
      }

      /* Saturate: '<S186>/PI_limit' */
      if (rtb_MatrixConcatenate1_tmp > CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_MatrixConcatenate1_tmp = CONTROL_PARAM.FW_PI_LIMIT;
      } else {
        if (rtb_MatrixConcatenate1_tmp < -CONTROL_PARAM.FW_PI_LIMIT) {
          rtb_MatrixConcatenate1_tmp = -CONTROL_PARAM.FW_PI_LIMIT;
        }
      }

      /* Saturate: '<S137>/Saturation1' incorporates:
       *  DiscreteIntegrator: '<S180>/Discrete-Time Integrator5'
       *  Product: '<S137>/Multiply'
       *  Sum: '<S186>/Add'
       */
      rtb_Sum = (rtb_Divide_i_idx_2 + rtb_MatrixConcatenate1_tmp) *
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;
      if (rtb_Sum > 1.0F) {
        rtb_Sum = 1.0F;
      } else {
        if (rtb_Sum < -1.0F) {
          rtb_Sum = -1.0F;
        }
      }

      /* Product: '<S233>/Multiply1' incorporates:
       *  Saturate: '<S233>/Saturation1'
       */
      for (i = 0; i < 4; i++) {
        /* Saturate: '<S234>/Saturation' incorporates:
         *  Gain: '<S234>/Gain'
         *  Sum: '<S234>/Add'
         */
        rtb_Saturation_a5 = fmodf(floorf(1000.0F * tmp[i] + (real32_T)
          rtb_DataTypeConversion_k), 65536.0F);
        u0 = (uint16_T)(rtb_Saturation_a5 < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                        (uint16_T)-rtb_Saturation_a5 : (int32_T)(uint16_T)
                        rtb_Saturation_a5);
        if (u0 > 1900) {
          rtb_MultiportSwitch_i[i] = 1900U;
        } else if (u0 < 1000) {
          rtb_MultiportSwitch_i[i] = 1000U;
        } else {
          rtb_MultiportSwitch_i[i] = u0;
        }

        /* End of Saturate: '<S234>/Saturation' */

        /* Saturate: '<S233>/Saturation1' incorporates:
         *  Bias: '<S233>/Bias'
         *  Gain: '<S233>/Gain1'
         *  Saturate: '<S233>/Saturation5'
         */
        rtb_Add1_j4 = 500.0F * (rtb_MatrixConcatenate_a[i + 8] * rtb_Sum +
          (rtb_MatrixConcatenate_a[i + 4] * rtb_Minus +
           rtb_MatrixConcatenate_a[i] * rtb_Add_cs)) + 1500.0F;
        if (rtb_Add1_j4 > 2000.0F) {
          rtb_Add1_j4 = 2000.0F;
        } else {
          if (rtb_Add1_j4 < 1000.0F) {
            rtb_Add1_j4 = 1000.0F;
          }
        }

        rtb_MultiportSwitch_i[i + 5] = (uint16_T)fmodf(floorf(rtb_Add1_j4),
          65536.0F);
      }

      /* End of Product: '<S233>/Multiply1' */
      break;

     default:
      for (i = 0; i < 9; i++) {
        rtb_MultiportSwitch_i[i] = Controller_ConstP.pooled34[i];
      }
      break;
    }

    /* End of MultiPortSwitch: '<S235>/Multiport Switch' */
    /* End of Outputs for SubSystem: '<S231>/VTOL1' */
    for (i = 0; i < 9; i++) {
      /* Outport: '<Root>/Control_Out' incorporates:
       *  Reshape: '<S230>/Reshape'
       */
      Controller_Y.Control_Out.actuator_cmd[i] = rtb_MultiportSwitch_i[i];
    }

    for (i = 0; i < 7; i++) {
      /* Outport: '<Root>/Control_Out' incorporates:
       *  Reshape: '<S230>/Reshape'
       */
      Controller_Y.Control_Out.actuator_cmd[i + 9] = 0U;
    }

    /* Product: '<S152>/Multiply' incorporates:
     *  Constant: '<S152>/gain1'
     *  Constant: '<S152>/gain2'
     *  Constant: '<S152>/gain3'
     *  DiscreteIntegrator: '<S150>/Discrete-Time Integrator5'
     */
    rtb_u_c = CONTROL_PARAM.MC_ROLL_RATE_I *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0];
    rtb_VdotPg = CONTROL_PARAM.MC_PITCH_RATE_I *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1];
    rtb_Minus = CONTROL_PARAM.MC_YAW_RATE_I *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2];

    /* Product: '<S175>/Multiply1' incorporates:
     *  Constant: '<S175>/const1'
     *  DiscreteIntegrator: '<S174>/Integrator'
     */
    rtb_Divide_i_idx_2 = Controller_DW.Integrator_DSTATE_f * 0.05F;

    /* Switch: '<S165>/Switch' incorporates:
     *  Constant: '<S165>/Zero'
     *  Constant: '<S168>/Constant'
     *  RelationalOperator: '<S168>/Compare'
     */
    if (rtb_BitwiseAND_n <= 3) {
      rtb_Add_cs = 0.0F;
    } else {
      rtb_Add_cs = Controller_U.FMS_Out.w_cmd;
    }

    /* End of Switch: '<S165>/Switch' */

    /* Sum: '<S175>/Add' incorporates:
     *  DiscreteIntegrator: '<S174>/Integrator1'
     *  Sum: '<S174>/Subtract'
     */
    rtb_Sum = (Controller_DW.Integrator1_DSTATE_i - rtb_Add_cs) +
      rtb_Divide_i_idx_2;

    /* Signum: '<S175>/Sign' */
    if (rtb_Sum < 0.0F) {
      rtb_Abs = -1.0F;
    } else if (rtb_Sum > 0.0F) {
      rtb_Abs = 1.0F;
    } else {
      rtb_Abs = rtb_Sum;
    }

    /* End of Signum: '<S175>/Sign' */

    /* Sum: '<S175>/Add2' incorporates:
     *  Abs: '<S175>/Abs'
     *  Gain: '<S175>/Gain'
     *  Gain: '<S175>/Gain1'
     *  Product: '<S175>/Multiply2'
     *  Product: '<S175>/Multiply3'
     *  Sqrt: '<S175>/Sqrt'
     *  Sum: '<S175>/Add1'
     *  Sum: '<S175>/Subtract'
     */
    rtb_Add_cs = (sqrtf((8.0F * fabsf(rtb_Sum) + Controller_ConstB.d_m) *
                        Controller_ConstB.d_m) - Controller_ConstB.d_m) * 0.5F *
      rtb_Abs + rtb_Divide_i_idx_2;

    /* Sum: '<S175>/Add4' */
    rtb_Divide_i_idx_2 += rtb_Sum - rtb_Add_cs;

    /* Sum: '<S175>/Add3' */
    rtb_Abs = rtb_Sum + Controller_ConstB.d_m;

    /* Sum: '<S175>/Subtract1' */
    rtb_Sum -= Controller_ConstB.d_m;

    /* Signum: '<S175>/Sign1' */
    if (rtb_Abs < 0.0F) {
      rtb_Abs = -1.0F;
    } else {
      if (rtb_Abs > 0.0F) {
        rtb_Abs = 1.0F;
      }
    }

    /* End of Signum: '<S175>/Sign1' */

    /* Signum: '<S175>/Sign2' */
    if (rtb_Sum < 0.0F) {
      rtb_Sum = -1.0F;
    } else {
      if (rtb_Sum > 0.0F) {
        rtb_Sum = 1.0F;
      }
    }

    /* End of Signum: '<S175>/Sign2' */

    /* Sum: '<S175>/Add5' incorporates:
     *  Gain: '<S175>/Gain2'
     *  Product: '<S175>/Multiply4'
     *  Sum: '<S175>/Subtract2'
     */
    rtb_Add_cs += (rtb_Abs - rtb_Sum) * 0.5F * rtb_Divide_i_idx_2;

    /* Update for DiscreteIntegrator: '<S182>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S182>/Gain'
     *  Sum: '<S182>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_L_eo = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_a += (rtb_Divide_gn -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_a) * 31.415926F * 0.002F;

    /* Update for DiscreteIntegrator: '<S181>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S181>/Gain'
     *  Sum: '<S181>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_o = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTA_a2 += ((real32_T)rtb_Relay -
      Controller_DW.DiscreteTimeIntegrator5_DSTA_a2) * 6.28318548F * 0.002F;

    /* Update for DiscreteIntegrator: '<S174>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S174>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_i += 0.002F *
      Controller_DW.Integrator_DSTATE_f;

    /* Update for DiscreteIntegrator: '<S177>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S177>/ki'
     *  Product: '<S177>/Multiply'
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

    /* End of Update for DiscreteIntegrator: '<S177>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S179>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_i = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTA_ld += 0.002F * rtb_Gain_it;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_h = (int8_T)
      rtb_LogicalOperator_b3;

    /* Update for DiscreteIntegrator: '<S217>/ ' incorporates:
     *  Gain: '<S217>/Gain3'
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

    /* End of Update for DiscreteIntegrator: '<S217>/ ' */

    /* Update for DiscreteIntegrator: '<S218>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_f = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_e += 0.002F * rtb_Gain_il;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_b = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S150>/Discrete-Time Integrator5' */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_b = 0U;

    /* Update for DiscreteIntegrator: '<S152>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_PrevRe_o = (int8_T)
      rtb_LogicalOperator_m;

    /* Update for DiscreteIntegrator: '<S154>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_L_h2 = 0U;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_l = (int8_T)
      rtb_LogicalOperator_m;

    /* Update for DiscreteIntegrator: '<S180>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S180>/Gain'
     *  Sum: '<S180>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_g = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_j += (rtb_Saturation_ov -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j) * 12.566371F * 0.002F;

    /* Update for DiscreteIntegrator: '<S150>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S150>/Gain'
     *  Sum: '<S150>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0] +=
      (rtb_DiscreteTimeIntegrator1_md_ -
       Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S152>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_d[0] += 0.002F * rtb_u_c;
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

    /* Update for DiscreteIntegrator: '<S154>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[0] += 0.002F *
      rtb_Multiply_kn[0];

    /* Update for DiscreteIntegrator: '<S192>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S192>/gain1'
     *  Product: '<S192>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0] +=
      CONTROL_PARAM.FW_ROLL_RATE_I * rtb_phi_cmd * 0.002F;
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

    /* Update for DiscreteIntegrator: '<S150>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S150>/Gain'
     *  Sum: '<S150>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1] +=
      (rtb_DiscreteTimeIntegrator1_m_0 -
       Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S152>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_d[1] += 0.002F * rtb_VdotPg;
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

    /* Update for DiscreteIntegrator: '<S154>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[1] += 0.002F *
      rtb_Multiply_kn[1];

    /* Update for DiscreteIntegrator: '<S192>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S192>/gain2'
     *  Product: '<S192>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1] +=
      CONTROL_PARAM.FW_PITCH_RATE_I * rtb_PitchOffset * 0.002F;
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

    /* Update for DiscreteIntegrator: '<S150>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S150>/Gain'
     *  Sum: '<S150>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2] +=
      (rtb_DiscreteTimeIntegrator1_m_1 -
       Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S152>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_d[2] += 0.002F * rtb_Minus;
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

    /* Update for DiscreteIntegrator: '<S154>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[2] += 0.002F *
      rtb_Multiply_kn[2];

    /* Update for DiscreteIntegrator: '<S192>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S192>/gain3'
     *  Product: '<S192>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2] +=
      CONTROL_PARAM.FW_YAW_RATE_I * rtb_Divide_i_idx_0 * 0.002F;
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

    /* Update for DiscreteIntegrator: '<S220>/ ' incorporates:
     *  Gain: '<S220>/Gain'
     */
    Controller_DW._DSTATE_d += CONTROL_PARAM.FW_TECS_THOR_I *
      rtb_Saturation1_h_idx_0 * 0.002F;
    if (Controller_DW._DSTATE_d >= 0.3F) {
      Controller_DW._DSTATE_d = 0.3F;
    } else {
      if (Controller_DW._DSTATE_d <= -0.3F) {
        Controller_DW._DSTATE_d = -0.3F;
      }
    }

    Controller_DW._PrevResetState_e = (int8_T)(Controller_U.FMS_Out.reset > 0);

    /* End of Update for DiscreteIntegrator: '<S220>/ ' */

    /* Update for DiscreteIntegrator: '<S221>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_L_h0 = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTA_nm += 0.002F * rtb_Divide_i_idx_1;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_d = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Signum: '<S175>/Sign6' incorporates:
     *  Signum: '<S175>/Sign5'
     */
    if (rtb_Add_cs < 0.0F) {
      rtb_DiscreteTimeIntegrator1_m_0 = -1.0F;

      /* Signum: '<S175>/Sign5' */
      rtb_DiscreteTimeIntegrator1_m_1 = -1.0F;
    } else if (rtb_Add_cs > 0.0F) {
      rtb_DiscreteTimeIntegrator1_m_0 = 1.0F;

      /* Signum: '<S175>/Sign5' */
      rtb_DiscreteTimeIntegrator1_m_1 = 1.0F;
    } else {
      rtb_DiscreteTimeIntegrator1_m_0 = rtb_Add_cs;

      /* Signum: '<S175>/Sign5' */
      rtb_DiscreteTimeIntegrator1_m_1 = rtb_Add_cs;
    }

    /* End of Signum: '<S175>/Sign6' */

    /* Sum: '<S175>/Add6' */
    rtb_Abs = rtb_Add_cs + Controller_ConstB.d_m;

    /* Sum: '<S175>/Subtract3' */
    rtb_DiscreteTimeIntegrator1_md_ = rtb_Add_cs - Controller_ConstB.d_m;

    /* Signum: '<S175>/Sign3' */
    if (rtb_Abs < 0.0F) {
      rtb_Abs = -1.0F;
    } else {
      if (rtb_Abs > 0.0F) {
        rtb_Abs = 1.0F;
      }
    }

    /* End of Signum: '<S175>/Sign3' */

    /* Signum: '<S175>/Sign4' */
    if (rtb_DiscreteTimeIntegrator1_md_ < 0.0F) {
      rtb_DiscreteTimeIntegrator1_md_ = -1.0F;
    } else {
      if (rtb_DiscreteTimeIntegrator1_md_ > 0.0F) {
        rtb_DiscreteTimeIntegrator1_md_ = 1.0F;
      }
    }

    /* End of Signum: '<S175>/Sign4' */

    /* Update for DiscreteIntegrator: '<S174>/Integrator' incorporates:
     *  Constant: '<S175>/const'
     *  Gain: '<S175>/Gain3'
     *  Product: '<S175>/Divide'
     *  Product: '<S175>/Multiply5'
     *  Product: '<S175>/Multiply6'
     *  Sum: '<S175>/Subtract4'
     *  Sum: '<S175>/Subtract5'
     *  Sum: '<S175>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE_f += ((rtb_Add_cs / Controller_ConstB.d_m -
      rtb_DiscreteTimeIntegrator1_m_1) * Controller_ConstB.Gain4_o * ((rtb_Abs -
      rtb_DiscreteTimeIntegrator1_md_) * 0.5F) - rtb_DiscreteTimeIntegrator1_m_0
      * 78.448F) * 0.002F;

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
    rtb_Divide_i_idx_2 = Controller_DW.Integrator1_DSTATE_h[0] -
      rtb_MatrixConcatenate1_0[0];
    rtb_Divide_i_idx_1 = Controller_DW.Integrator1_DSTATE_h[1] -
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
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_g[0] = rtb_Divide_i_idx_2;
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_g[1] = rtb_Divide_i_idx_1;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_p != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_g[0] = rtb_Divide_i_idx_2;
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_g[1] = rtb_Divide_i_idx_1;
    }

    /* Gain: '<S49>/Gain' incorporates:
     *  DiscreteIntegrator: '<S49>/Discrete-Time Integrator1'
     *  Sum: '<S49>/Sum5'
     */
    rtb_Saturation1_h_idx_0 = (rtb_Divide_i_idx_2 -
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_g[0]) * 62.831852F;
    rtb_Divide_gn = (rtb_Divide_i_idx_1 -
                     Controller_DW.DiscreteTimeIntegrator1_DSTAT_g[1]) *
      62.831852F;

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
    if (rtb_BitwiseAND_n == 2) {
      rtb_Multiply_kn[0] = Controller_U.FMS_Out.p_cmd;
      rtb_Multiply_kn[1] = Controller_U.FMS_Out.q_cmd;
      rtb_Multiply_kn[2] = Controller_U.FMS_Out.r_cmd;
    } else {
      if (Controller_U.FMS_Out.psi_rate_cmd > CONTROL_PARAM.MC_R_CMD_LIM) {
        /* Saturate: '<S18>/Saturation' */
        rtb_DiscreteTimeIntegrator1_md_ = CONTROL_PARAM.MC_R_CMD_LIM;
      } else if (Controller_U.FMS_Out.psi_rate_cmd < -CONTROL_PARAM.MC_R_CMD_LIM)
      {
        /* Saturate: '<S18>/Saturation' */
        rtb_DiscreteTimeIntegrator1_md_ = -CONTROL_PARAM.MC_R_CMD_LIM;
      } else {
        /* Saturate: '<S18>/Saturation' */
        rtb_DiscreteTimeIntegrator1_md_ = Controller_U.FMS_Out.psi_rate_cmd;
      }

      /* Switch: '<S31>/Switch' incorporates:
       *  Logic: '<S31>/Logical Operator'
       *  RelationalOperator: '<S37>/Compare'
       *  Saturate: '<S18>/Saturation'
       *  Switch: '<S49>/Switch'
       *  Trigonometry: '<S38>/Atan'
       */
      if ((rtb_BitwiseAND_n == 3) || (rtb_BitwiseAND_n == 4)) {
        rtb_Gain_ms = Controller_U.FMS_Out.phi_cmd;
        rtb_u_c = Controller_U.FMS_Out.theta_cmd;
      } else {
        if (Controller_U.FMS_Out.reset > 0) {
          /* Switch: '<S49>/Switch' incorporates:
           *  Gain: '<S49>/Gain1'
           */
          rtb_Gain_ms = 0.0F;
          rtb_u_c = 0.0F;
        } else {
          /* Switch: '<S49>/Switch' */
          rtb_Gain_ms = rtb_Saturation1_h_idx_0;
          rtb_u_c = rtb_Divide_gn;
        }

        /* Product: '<S46>/Multiply' incorporates:
         *  Constant: '<S46>/kd'
         */
        rtb_Gain_it = CONTROL_PARAM.MC_VEL_XY_D * rtb_Gain_ms;

        /* Saturate: '<S46>/Saturation' */
        if (rtb_Gain_it > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
          rtb_Gain_it = CONTROL_PARAM.MC_VEL_XY_D_MAX;
        } else {
          if (rtb_Gain_it < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
            rtb_Gain_it = CONTROL_PARAM.MC_VEL_XY_D_MIN;
          }
        }

        /* Gain: '<S38>/Gain1' incorporates:
         *  Constant: '<S48>/kp'
         *  DiscreteIntegrator: '<S47>/Discrete-Time Integrator'
         *  Product: '<S46>/Multiply'
         *  Product: '<S48>/Multiply'
         *  Sum: '<S40>/Add'
         */
        rtb_Saturation_a5 = (CONTROL_PARAM.MC_VEL_XY_P * rtb_Divide_i_idx_2 +
                             Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[0]) +
          rtb_Gain_it;

        /* Product: '<S46>/Multiply' incorporates:
         *  Constant: '<S46>/kd'
         */
        rtb_Gain_it = CONTROL_PARAM.MC_VEL_XY_D * rtb_u_c;

        /* Saturate: '<S46>/Saturation' */
        if (rtb_Gain_it > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
          rtb_Gain_it = CONTROL_PARAM.MC_VEL_XY_D_MAX;
        } else {
          if (rtb_Gain_it < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
            rtb_Gain_it = CONTROL_PARAM.MC_VEL_XY_D_MIN;
          }
        }

        /* Sum: '<S40>/Add' incorporates:
         *  Constant: '<S48>/kp'
         *  DiscreteIntegrator: '<S47>/Discrete-Time Integrator'
         *  Product: '<S48>/Multiply'
         */
        rtb_Gain_it += CONTROL_PARAM.MC_VEL_XY_P * rtb_Divide_i_idx_1 +
          Controller_DW.DiscreteTimeIntegrator_DSTAT_kh[1];

        /* Trigonometry: '<S38>/Atan' incorporates:
         *  Constant: '<S38>/g'
         *  Gain: '<S38>/gain'
         *  Product: '<S38>/Divide'
         */
        rtb_u_c = atanf(1.1F * rtb_Gain_it / 9.8055F);

        /* Saturate: '<S38>/Saturation' */
        if (rtb_u_c > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          rtb_u_c = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        } else {
          if (rtb_u_c < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
            rtb_u_c = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
          }
        }

        rtb_Gain_ms = rtb_u_c;

        /* Trigonometry: '<S38>/Atan' incorporates:
         *  Constant: '<S38>/g'
         *  Gain: '<S38>/Gain1'
         *  Gain: '<S38>/gain'
         *  Product: '<S38>/Divide'
         */
        rtb_u_c = atanf(1.1F * -rtb_Saturation_a5 / 9.8055F);

        /* Saturate: '<S38>/Saturation' */
        if (rtb_u_c > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          rtb_u_c = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        } else {
          if (rtb_u_c < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
            rtb_u_c = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
          }
        }
      }

      /* End of Switch: '<S31>/Switch' */

      /* Sum: '<S32>/Sum' incorporates:
       *  Inport: '<Root>/INS_Out'
       */
      rtb_Gain_it = rtb_Gain_ms - Controller_U.INS_Out.phi;

      /* Product: '<S35>/Divide1' incorporates:
       *  Abs: '<S35>/Abs'
       *  Constant: '<S35>/const2'
       */
      rtb_Gain_il = fabsf(rtb_Gain_it) / 0.002F;

      /* Gain: '<S35>/Gain3' */
      rtb_Add_cs = -rtb_Gain_il;

      /* Product: '<S35>/Divide' incorporates:
       *  Constant: '<S33>/Constant1'
       *  Constant: '<S35>/const1'
       *  Math: '<S35>/Square'
       *  SignalConversion: '<S35>/TmpSignal ConversionAtSquareInport1'
       */
      rtb_DiscreteTimeIntegrator1_m_0 = 9.5993F / (CONTROL_PARAM.MC_ROLL_P *
        CONTROL_PARAM.MC_ROLL_P);

      /* Signum: '<S35>/Sign' */
      if (rtb_Gain_it < 0.0F) {
        rtb_DiscreteTimeIntegrator1_m_1 = -1.0F;
      } else if (rtb_Gain_it > 0.0F) {
        rtb_DiscreteTimeIntegrator1_m_1 = 1.0F;
      } else {
        rtb_DiscreteTimeIntegrator1_m_1 = rtb_Gain_it;
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
      if ((rtb_Gain_it <= rtb_DiscreteTimeIntegrator1_m_0) && (rtb_Gain_it >=
           -rtb_DiscreteTimeIntegrator1_m_0)) {
        rtb_Gain_it *= CONTROL_PARAM.MC_ROLL_P;
      } else {
        rtb_Gain_it = sqrtf((rtb_DiscreteTimeIntegrator1_m_1 * rtb_Gain_it -
                             0.5F * rtb_DiscreteTimeIntegrator1_m_0) *
                            Controller_ConstB.Gain_n) *
          rtb_DiscreteTimeIntegrator1_m_1;
      }

      /* Switch: '<S36>/Switch' incorporates:
       *  Gain: '<S35>/Gain3'
       *  RelationalOperator: '<S36>/UpperRelop'
       */
      if (rtb_Gain_it >= -rtb_Gain_il) {
        rtb_Add_cs = rtb_Gain_it;
      }

      /* Switch: '<S36>/Switch2' incorporates:
       *  RelationalOperator: '<S36>/LowerRelop1'
       */
      if (rtb_Gain_it <= rtb_Gain_il) {
        rtb_Gain_il = rtb_Add_cs;
      }

      /* Saturate: '<S18>/Saturation1' */
      if (rtb_Gain_il > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_Gain_il = CONTROL_PARAM.MC_P_Q_CMD_LIM;
      } else {
        if (rtb_Gain_il < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
          rtb_Gain_il = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
        }
      }

      rtb_Saturation_ov = rtb_Gain_il;

      /* Sum: '<S32>/Sum' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Product: '<S35>/Divide1'
       */
      rtb_Gain_it = rtb_u_c - Controller_U.INS_Out.theta;

      /* Product: '<S35>/Divide1' incorporates:
       *  Abs: '<S35>/Abs'
       *  Constant: '<S35>/const2'
       */
      rtb_Gain_il = fabsf(rtb_Gain_it) / 0.002F;

      /* Gain: '<S35>/Gain3' */
      rtb_Add_cs = -rtb_Gain_il;

      /* Product: '<S35>/Divide' incorporates:
       *  Constant: '<S33>/Constant2'
       *  Constant: '<S35>/const1'
       *  Math: '<S35>/Square'
       *  SignalConversion: '<S35>/TmpSignal ConversionAtSquareInport1'
       */
      rtb_DiscreteTimeIntegrator1_m_0 = 9.5993F / (CONTROL_PARAM.MC_PITCH_P *
        CONTROL_PARAM.MC_PITCH_P);

      /* Signum: '<S35>/Sign' */
      if (rtb_Gain_it < 0.0F) {
        rtb_DiscreteTimeIntegrator1_m_1 = -1.0F;
      } else if (rtb_Gain_it > 0.0F) {
        rtb_DiscreteTimeIntegrator1_m_1 = 1.0F;
      } else {
        rtb_DiscreteTimeIntegrator1_m_1 = rtb_Gain_it;
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
      if ((rtb_Gain_it <= rtb_DiscreteTimeIntegrator1_m_0) && (rtb_Gain_it >=
           -rtb_DiscreteTimeIntegrator1_m_0)) {
        rtb_Gain_it *= CONTROL_PARAM.MC_PITCH_P;
      } else {
        rtb_Gain_it = sqrtf((rtb_DiscreteTimeIntegrator1_m_1 * rtb_Gain_it -
                             0.5F * rtb_DiscreteTimeIntegrator1_m_0) *
                            Controller_ConstB.Gain_n) *
          rtb_DiscreteTimeIntegrator1_m_1;
      }

      /* Switch: '<S36>/Switch' incorporates:
       *  Gain: '<S35>/Gain3'
       *  RelationalOperator: '<S36>/UpperRelop'
       */
      if (rtb_Gain_it >= -rtb_Gain_il) {
        rtb_Add_cs = rtb_Gain_it;
      }

      /* Switch: '<S36>/Switch2' incorporates:
       *  RelationalOperator: '<S36>/LowerRelop1'
       */
      if (rtb_Gain_it <= rtb_Gain_il) {
        rtb_Gain_il = rtb_Add_cs;
      }

      /* Saturate: '<S18>/Saturation1' */
      if (rtb_Gain_il > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_Gain_il = CONTROL_PARAM.MC_P_Q_CMD_LIM;
      } else {
        if (rtb_Gain_il < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
          rtb_Gain_il = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
        }
      }

      /* Trigonometry: '<S28>/Cos' incorporates:
       *  Inport: '<Root>/INS_Out'
       */
      rtb_DiscreteTimeIntegrator1_m_0 = arm_cos_f32(Controller_U.INS_Out.phi);

      /* Trigonometry: '<S28>/Cos1' incorporates:
       *  Inport: '<Root>/INS_Out'
       */
      rtb_DiscreteTimeIntegrator1_m_1 = arm_cos_f32(Controller_U.INS_Out.theta);

      /* Trigonometry: '<S28>/Sin' incorporates:
       *  Inport: '<Root>/INS_Out'
       */
      rtb_Gain_ms = arm_sin_f32(Controller_U.INS_Out.phi);
      rtb_Multiply_kn[0] = rtb_Saturation_ov - arm_sin_f32
        (Controller_U.INS_Out.theta) * rtb_DiscreteTimeIntegrator1_md_;
      rtb_Multiply_kn[1] = rtb_DiscreteTimeIntegrator1_m_0 * rtb_Gain_il +
        rtb_Gain_ms * rtb_DiscreteTimeIntegrator1_m_1 *
        rtb_DiscreteTimeIntegrator1_md_;
      rtb_Multiply_kn[2] = rtb_DiscreteTimeIntegrator1_m_0 *
        rtb_DiscreteTimeIntegrator1_m_1 * rtb_DiscreteTimeIntegrator1_md_ -
        rtb_Gain_ms * rtb_Gain_il;
    }

    /* End of Switch: '<S19>/Switch' */

    /* Sum: '<S20>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_DiscreteTimeIntegrator1_md_ = rtb_Multiply_kn[0] -
      Controller_U.INS_Out.p;
    rtb_DiscreteTimeIntegrator1_m_0 = rtb_Multiply_kn[1] -
      Controller_U.INS_Out.q;
    rtb_DiscreteTimeIntegrator1_m_1 = rtb_Multiply_kn[2] -
      Controller_U.INS_Out.r;

    /* DiscreteIntegrator: '<S23>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_e != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0] =
        rtb_DiscreteTimeIntegrator1_md_;
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1] =
        rtb_DiscreteTimeIntegrator1_m_0;
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2] =
        rtb_DiscreteTimeIntegrator1_m_1;
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
    rtb_Multiply_kn[0] = (Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0] -
                          Controller_DW.DiscreteTimeIntegrator1_DSTAT_l[0]) *
      188.49556F;
    rtb_Multiply_kn[1] = (Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1] -
                          Controller_DW.DiscreteTimeIntegrator1_DSTAT_l[1]) *
      188.49556F;
    rtb_Multiply_kn[2] = (Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2] -
                          Controller_DW.DiscreteTimeIntegrator1_DSTAT_l[2]) *
      188.49556F;

    /* Gain: '<S52>/Gain' incorporates:
     *  DiscreteIntegrator: '<S54>/Integrator1'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S52>/Sum1'
     */
    rtb_Gain_it = -(Controller_DW.Integrator1_DSTATE_o - Controller_U.INS_Out.vd);
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
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_d = rtb_Gain_it;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_a != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_d = rtb_Gain_it;
    }

    /* Gain: '<S59>/Gain' incorporates:
     *  DiscreteIntegrator: '<S59>/Discrete-Time Integrator1'
     *  Sum: '<S59>/Sum5'
     */
    rtb_Divide_i_idx_3 = (rtb_Gain_it -
                          Controller_DW.DiscreteTimeIntegrator1_DSTAT_d) *
      62.831852F;

    /* Outputs for Atomic SubSystem: '<S61>/VTOL1' */
    /* MultiPortSwitch: '<S65>/Multiport Switch' incorporates:
     *  Constant: '<S65>/Disarm'
     *  Constant: '<S65>/Standby'
     *  Constant: '<S66>/Constant1'
     *  Constant: '<S66>/Constant12'
     *  Constant: '<S66>/Constant2'
     *  Constant: '<S66>/Constant7'
     *  Product: '<S24>/Multiply'
     *  Reshape: '<S62>/Reshape'
     *  Saturate: '<S63>/Saturation1'
     */
    switch (Controller_U.FMS_Out.status) {
     case 1:
      for (i = 0; i < 9; i++) {
        rtb_MultiportSwitch_i[i] = Controller_ConstP.pooled34[i];
      }
      break;

     case 2:
      for (i = 0; i < 9; i++) {
        rtb_MultiportSwitch_i[i] = Controller_ConstP.pooled35[i];
      }
      break;

     case 3:
      /* Switch: '<S27>/Switch' incorporates:
       *  Gain: '<S27>/Gain1'
       */
      if (Controller_U.FMS_Out.reset > 0) {
        rtb_phi_cmd = 0.0F;
        rtb_PitchOffset = 0.0F;
        rtb_Divide_i_idx_0 = 0.0F;
      } else {
        rtb_phi_cmd = rtb_Multiply_kn[0];
        rtb_PitchOffset = rtb_Multiply_kn[1];
        rtb_Divide_i_idx_0 = rtb_Multiply_kn[2];
      }

      /* End of Switch: '<S27>/Switch' */

      /* Product: '<S24>/Multiply' incorporates:
       *  Constant: '<S24>/gain1'
       */
      rtb_Saturation_ov = CONTROL_PARAM.MC_ROLL_RATE_D * rtb_phi_cmd;

      /* Saturate: '<S24>/Saturation' */
      if (rtb_Saturation_ov > CONTROL_PARAM.MC_RATE_D_MAX) {
        rtb_Saturation_ov = CONTROL_PARAM.MC_RATE_D_MAX;
      } else {
        if (rtb_Saturation_ov < CONTROL_PARAM.MC_RATE_D_MIN) {
          rtb_Saturation_ov = CONTROL_PARAM.MC_RATE_D_MIN;
        }
      }

      rtb_phi_cmd = rtb_Saturation_ov;

      /* Product: '<S24>/Multiply' incorporates:
       *  Constant: '<S24>/gain2'
       */
      rtb_Saturation_ov = CONTROL_PARAM.MC_PITCH_RATE_D * rtb_PitchOffset;

      /* Saturate: '<S24>/Saturation' */
      if (rtb_Saturation_ov > CONTROL_PARAM.MC_RATE_D_MAX) {
        rtb_Saturation_ov = CONTROL_PARAM.MC_RATE_D_MAX;
      } else {
        if (rtb_Saturation_ov < CONTROL_PARAM.MC_RATE_D_MIN) {
          rtb_Saturation_ov = CONTROL_PARAM.MC_RATE_D_MIN;
        }
      }

      rtb_PitchOffset = rtb_Saturation_ov;

      /* Product: '<S24>/Multiply' incorporates:
       *  Constant: '<S24>/gain3'
       */
      rtb_Saturation_ov = CONTROL_PARAM.MC_YAW_RATE_D * rtb_Divide_i_idx_0;

      /* Saturate: '<S24>/Saturation' */
      if (rtb_Saturation_ov > CONTROL_PARAM.MC_RATE_D_MAX) {
        rtb_Saturation_ov = CONTROL_PARAM.MC_RATE_D_MAX;
      } else {
        if (rtb_Saturation_ov < CONTROL_PARAM.MC_RATE_D_MIN) {
          rtb_Saturation_ov = CONTROL_PARAM.MC_RATE_D_MIN;
        }
      }

      /* Product: '<S51>/Multiply' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S51>/Cos'
       *  Trigonometry: '<S51>/Cos1'
       */
      rtb_Divide_i_idx_0 = arm_cos_f32(Controller_U.INS_Out.phi) * arm_cos_f32
        (Controller_U.INS_Out.theta);

      /* Gain: '<S51>/Gain' */
      rtb_Add_cs = 2.0F * rtb_Divide_i_idx_0;

      /* Saturate: '<S51>/Saturation1' */
      if (rtb_Divide_i_idx_0 > 1.0F) {
        rtb_Divide_i_idx_0 = 1.0F;
      } else {
        if (rtb_Divide_i_idx_0 < 0.5F) {
          rtb_Divide_i_idx_0 = 0.5F;
        }
      }

      /* End of Saturate: '<S51>/Saturation1' */

      /* Product: '<S51>/Divide' incorporates:
       *  Constant: '<S51>/Constant'
       */
      rtb_Gain_ms = 1.0F / rtb_Divide_i_idx_0;

      /* Switch: '<S59>/Switch' incorporates:
       *  Gain: '<S59>/Gain1'
       */
      if (Controller_U.FMS_Out.reset > 0) {
        rtb_Saturation_a5 = 0.0F;
      } else {
        rtb_Saturation_a5 = rtb_Divide_i_idx_3;
      }

      /* End of Switch: '<S59>/Switch' */

      /* Product: '<S56>/Multiply' incorporates:
       *  Constant: '<S56>/kd'
       */
      rtb_Divide_i_idx_0 = CONTROL_PARAM.MC_VEL_Z_D * rtb_Saturation_a5;

      /* Saturate: '<S56>/Saturation' */
      if (rtb_Divide_i_idx_0 > CONTROL_PARAM.MC_VEL_Z_D_MAX) {
        rtb_Divide_i_idx_0 = CONTROL_PARAM.MC_VEL_Z_D_MAX;
      } else {
        if (rtb_Divide_i_idx_0 < CONTROL_PARAM.MC_VEL_Z_D_MIN) {
          rtb_Divide_i_idx_0 = CONTROL_PARAM.MC_VEL_Z_D_MIN;
        }
      }

      /* End of Saturate: '<S56>/Saturation' */

      /* Saturate: '<S51>/Saturation' */
      if (rtb_Add_cs > 1.0F) {
        rtb_Add_cs = 1.0F;
      } else {
        if (rtb_Add_cs < 0.0F) {
          rtb_Add_cs = 0.0F;
        }
      }

      /* End of Saturate: '<S51>/Saturation' */

      /* Product: '<S51>/Multiply1' incorporates:
       *  Constant: '<S58>/kp'
       *  DiscreteIntegrator: '<S57>/Discrete-Time Integrator'
       *  Product: '<S58>/Multiply'
       *  Sum: '<S53>/Add'
       */
      rtb_Gain_ms = ((CONTROL_PARAM.MC_VEL_Z_P * rtb_Gain_it +
                      Controller_DW.DiscreteTimeIntegrator_DSTATE_p) +
                     rtb_Divide_i_idx_0) * rtb_Gain_ms * rtb_Add_cs;

      /* Saturate: '<S50>/Saturation' */
      if (rtb_Gain_ms > 0.35F) {
        rtb_Gain_ms = 0.35F;
      } else {
        if (rtb_Gain_ms < -0.35F) {
          rtb_Gain_ms = -0.35F;
        }
      }

      /* End of Saturate: '<S50>/Saturation' */

      /* Sum: '<S9>/Sum' incorporates:
       *  Constant: '<S9>/mc_hover_throttle'
       */
      rtb_Gain_ms += CONTROL_PARAM.MC_HOVER_THRO;

      /* Saturate: '<S9>/Saturation' */
      if (rtb_Gain_ms > 1.0F) {
        rtb_Gain_ms = 1.0F;
      } else {
        if (rtb_Gain_ms < -1.0F) {
          rtb_Gain_ms = -1.0F;
        }
      }

      /* End of Saturate: '<S9>/Saturation' */

      /* Saturate: '<S68>/Saturation' */
      if (rtb_Gain_ms < 0.0F) {
        rtb_Gain_ms = 0.0F;
      }

      /* End of Saturate: '<S68>/Saturation' */

      /* DataTypeConversion: '<S68>/Data Type Conversion' incorporates:
       *  Constant: '<S68>/Constant1'
       *  Gain: '<S68>/Gain1'
       *  Sum: '<S68>/Sum1'
       */
      rtb_DataTypeConversion_k = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
        rtb_Gain_ms), 4.2949673E+9F) + 1000U);
      rtb_MatrixConcatenate_a[11] = CONTROL_PARAM.FW_YAW_EFFC;

      /* SignalConversion: '<S66>/ConcatBufferAtVector Concatenate2In3' incorporates:
       *  Constant: '<S66>/Constant11'
       *  Constant: '<S66>/Constant12'
       */
      rtb_MatrixConcatenate_a[10] = 0.0F;

      /* SignalConversion: '<S66>/ConcatBufferAtVector Concatenate2In2' incorporates:
       *  Constant: '<S66>/Constant10'
       */
      rtb_MatrixConcatenate_a[9] = 0.0F;

      /* SignalConversion: '<S66>/ConcatBufferAtVector Concatenate2In1' incorporates:
       *  Constant: '<S66>/Constant9'
       */
      rtb_MatrixConcatenate_a[8] = 0.0F;

      /* SignalConversion: '<S66>/ConcatBufferAtVector Concatenate1In4' incorporates:
       *  Constant: '<S66>/Constant8'
       */
      rtb_MatrixConcatenate_a[7] = 0.0F;
      rtb_MatrixConcatenate_a[6] = CONTROL_PARAM.FW_PITCH_EFFC;

      /* SignalConversion: '<S66>/ConcatBufferAtVector Concatenate1In2' incorporates:
       *  Constant: '<S66>/Constant6'
       *  Constant: '<S66>/Constant7'
       */
      rtb_MatrixConcatenate_a[5] = 0.0F;

      /* SignalConversion: '<S66>/ConcatBufferAtVector Concatenate1In1' incorporates:
       *  Constant: '<S66>/Constant5'
       */
      rtb_MatrixConcatenate_a[4] = 0.0F;

      /* SignalConversion: '<S66>/ConcatBufferAtVector ConcatenateIn4' incorporates:
       *  Constant: '<S66>/Constant4'
       */
      rtb_MatrixConcatenate_a[3] = 0.0F;

      /* SignalConversion: '<S66>/ConcatBufferAtVector ConcatenateIn3' incorporates:
       *  Constant: '<S66>/Constant3'
       */
      rtb_MatrixConcatenate_a[2] = 0.0F;
      rtb_MatrixConcatenate_a[1] = CONTROL_PARAM.FW_ROLL_EFFC;
      rtb_MatrixConcatenate_a[0] = CONTROL_PARAM.FW_ROLL_EFFC;

      /* Saturate: '<S64>/Saturation1' incorporates:
       *  Constant: '<S26>/gain1'
       *  Constant: '<S26>/gain2'
       *  Constant: '<S26>/gain3'
       *  Constant: '<S66>/Constant1'
       *  Constant: '<S66>/Constant2'
       *  DiscreteIntegrator: '<S23>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S25>/Discrete-Time Integrator'
       *  Product: '<S26>/Multiply'
       *  Sum: '<S21>/Add'
       */
      rtb_Add_cs = (CONTROL_PARAM.MC_ROLL_RATE_P *
                    Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0] +
                    Controller_DW.DiscreteTimeIntegrator_DSTATE_g[0]) +
        rtb_phi_cmd;
      if (rtb_Add_cs > 1.0F) {
        rtb_Add_cs = 1.0F;
      } else {
        if (rtb_Add_cs < -1.0F) {
          rtb_Add_cs = -1.0F;
        }
      }

      rtb_Minus = (CONTROL_PARAM.MC_PITCH_RATE_P *
                   Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1] +
                   Controller_DW.DiscreteTimeIntegrator_DSTATE_g[1]) +
        rtb_PitchOffset;
      if (rtb_Minus > 1.0F) {
        rtb_Minus = 1.0F;
      } else {
        if (rtb_Minus < -1.0F) {
          rtb_Minus = -1.0F;
        }
      }

      rtb_Sum = (CONTROL_PARAM.MC_YAW_RATE_P *
                 Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2] +
                 Controller_DW.DiscreteTimeIntegrator_DSTATE_g[2]) +
        rtb_Saturation_ov;
      if (rtb_Sum > 1.0F) {
        rtb_Sum = 1.0F;
      } else {
        if (rtb_Sum < -1.0F) {
          rtb_Sum = -1.0F;
        }
      }

      /* End of Saturate: '<S64>/Saturation1' */
      rtb_MultiportSwitch_i[4] = Controller_ConstB.DataTypeConversion;
      for (i = 0; i < 4; i++) {
        /* Saturate: '<S64>/Saturation' incorporates:
         *  Constant: '<S64>/Effective_Matrix'
         *  Gain: '<S64>/Gain'
         *  Product: '<S64>/Multiply'
         *  Sum: '<S64>/Add'
         */
        rtb_Saturation_a5 = fmodf(floorf(1000.0F * (Controller_ConstP.pooled19[i
          + 8] * rtb_Sum + (Controller_ConstP.pooled19[i + 4] * rtb_Minus +
                            Controller_ConstP.pooled19[i] * rtb_Add_cs)) +
          (real32_T)rtb_DataTypeConversion_k), 65536.0F);
        u0 = (uint16_T)(rtb_Saturation_a5 < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                        (uint16_T)-rtb_Saturation_a5 : (int32_T)(uint16_T)
                        rtb_Saturation_a5);
        if (u0 > 1900) {
          rtb_MultiportSwitch_i[i] = 1900U;
        } else if (u0 < 1000) {
          rtb_MultiportSwitch_i[i] = 1000U;
        } else {
          rtb_MultiportSwitch_i[i] = u0;
        }

        /* End of Saturate: '<S64>/Saturation' */

        /* Saturate: '<S63>/Saturation1' incorporates:
         *  Bias: '<S63>/Bias'
         *  Gain: '<S63>/Gain1'
         *  Product: '<S63>/Multiply1'
         */
        rtb_Add1_j4 = 500.0F * (rtb_MatrixConcatenate_a[i + 8] *
          Controller_ConstB.Saturation5[2] + (rtb_MatrixConcatenate_a[i + 4] *
          Controller_ConstB.Saturation5[1] + rtb_MatrixConcatenate_a[i] *
          Controller_ConstB.Saturation5[0])) + 1500.0F;
        if (rtb_Add1_j4 > 2000.0F) {
          rtb_Add1_j4 = 2000.0F;
        } else {
          if (rtb_Add1_j4 < 1000.0F) {
            rtb_Add1_j4 = 1000.0F;
          }
        }

        rtb_MultiportSwitch_i[i + 5] = (uint16_T)fmodf(floorf(rtb_Add1_j4),
          65536.0F);
      }
      break;

     default:
      for (i = 0; i < 9; i++) {
        rtb_MultiportSwitch_i[i] = Controller_ConstP.pooled34[i];
      }
      break;
    }

    /* End of MultiPortSwitch: '<S65>/Multiport Switch' */
    /* End of Outputs for SubSystem: '<S61>/VTOL1' */
    for (i = 0; i < 9; i++) {
      /* Outport: '<Root>/Control_Out' incorporates:
       *  Reshape: '<S60>/Reshape'
       */
      Controller_Y.Control_Out.actuator_cmd[i] = rtb_MultiportSwitch_i[i];
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
    rtb_phi_cmd = CONTROL_PARAM.MC_ROLL_RATE_I *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0];
    rtb_PitchOffset = CONTROL_PARAM.MC_PITCH_RATE_I *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1];
    rtb_Divide_i_idx_0 = CONTROL_PARAM.MC_YAW_RATE_I *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2];

    /* Product: '<S45>/Multiply1' incorporates:
     *  Constant: '<S45>/const1'
     *  DiscreteIntegrator: '<S42>/Integrator'
     */
    rtb_Gain_ms = Controller_DW.Integrator_DSTATE_jg[0] * 0.05F;
    rtb_u_c = Controller_DW.Integrator_DSTATE_jg[1] * 0.05F;

    /* Sum: '<S45>/Add' incorporates:
     *  DiscreteIntegrator: '<S42>/Integrator1'
     *  Sum: '<S42>/Subtract'
     */
    rtb_Saturation_ov = (Controller_DW.Integrator1_DSTATE_h[0] -
                         Controller_U.FMS_Out.u_cmd) + rtb_Gain_ms;
    rtb_VdotPg = (Controller_DW.Integrator1_DSTATE_h[1] -
                  Controller_U.FMS_Out.v_cmd) + rtb_u_c;

    /* Product: '<S55>/Multiply1' incorporates:
     *  Constant: '<S55>/const1'
     *  DiscreteIntegrator: '<S54>/Integrator'
     */
    rtb_Abs = Controller_DW.Integrator_DSTATE_e * 0.05F;

    /* Sum: '<S55>/Add' incorporates:
     *  DiscreteIntegrator: '<S54>/Integrator1'
     *  Sum: '<S54>/Subtract'
     */
    rtb_Gain_il = (Controller_DW.Integrator1_DSTATE_o -
                   Controller_U.FMS_Out.w_cmd) + rtb_Abs;

    /* Signum: '<S55>/Sign' */
    if (rtb_Gain_il < 0.0F) {
      rtb_Add_cs = -1.0F;
    } else if (rtb_Gain_il > 0.0F) {
      rtb_Add_cs = 1.0F;
    } else {
      rtb_Add_cs = rtb_Gain_il;
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
    rtb_Minus = (sqrtf((8.0F * fabsf(rtb_Gain_il) + Controller_ConstB.d_j) *
                       Controller_ConstB.d_j) - Controller_ConstB.d_j) * 0.5F *
      rtb_Add_cs + rtb_Abs;

    /* Sum: '<S55>/Add4' */
    rtb_Add_cs = (rtb_Gain_il - rtb_Minus) + rtb_Abs;

    /* Sum: '<S55>/Add3' */
    rtb_Abs = rtb_Gain_il + Controller_ConstB.d_j;

    /* Sum: '<S55>/Subtract1' */
    rtb_Gain_il -= Controller_ConstB.d_j;

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
    if (rtb_Gain_il < 0.0F) {
      rtb_Gain_il = -1.0F;
    } else {
      if (rtb_Gain_il > 0.0F) {
        rtb_Gain_il = 1.0F;
      }
    }

    /* End of Signum: '<S55>/Sign2' */

    /* Sum: '<S55>/Add5' incorporates:
     *  Gain: '<S55>/Gain2'
     *  Product: '<S55>/Multiply4'
     *  Sum: '<S55>/Subtract2'
     */
    rtb_Minus += (rtb_Abs - rtb_Gain_il) * 0.5F * rtb_Add_cs;

    /* Update for DiscreteIntegrator: '<S47>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_PrevRe_a = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S49>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_h = 0U;

    /* Signum: '<S45>/Sign' */
    if (rtb_Saturation_ov < 0.0F) {
      rtb_Gain_il = -1.0F;
    } else if (rtb_Saturation_ov > 0.0F) {
      rtb_Gain_il = 1.0F;
    } else {
      rtb_Gain_il = rtb_Saturation_ov;
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
    rtb_Add_cs = (sqrtf((8.0F * fabsf(rtb_Saturation_ov) +
                         Controller_ConstB.d_ih) * Controller_ConstB.d_ih) -
                  Controller_ConstB.d_ih) * 0.5F * rtb_Gain_il + rtb_Gain_ms;

    /* Sum: '<S45>/Add3' incorporates:
     *  Signum: '<S45>/Sign'
     */
    rtb_Abs = rtb_Saturation_ov + Controller_ConstB.d_ih;

    /* Sum: '<S45>/Subtract1' incorporates:
     *  Signum: '<S45>/Sign'
     */
    rtb_Gain_il = rtb_Saturation_ov - Controller_ConstB.d_ih;

    /* Signum: '<S45>/Sign1' */
    if (rtb_Abs < 0.0F) {
      rtb_Abs = -1.0F;
    } else {
      if (rtb_Abs > 0.0F) {
        rtb_Abs = 1.0F;
      }
    }

    /* Signum: '<S45>/Sign2' */
    if (rtb_Gain_il < 0.0F) {
      rtb_Gain_il = -1.0F;
    } else {
      if (rtb_Gain_il > 0.0F) {
        rtb_Gain_il = 1.0F;
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
    rtb_Gain_ms = ((rtb_Saturation_ov - rtb_Add_cs) + rtb_Gain_ms) * ((rtb_Abs -
      rtb_Gain_il) * 0.5F) + rtb_Add_cs;

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
      CONTROL_PARAM.MC_VEL_XY_I * rtb_Divide_i_idx_2 * 0.002F;
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
    if (rtb_VdotPg < 0.0F) {
      rtb_Saturation_ov = -1.0F;
    } else if (rtb_VdotPg > 0.0F) {
      rtb_Saturation_ov = 1.0F;
    } else {
      rtb_Saturation_ov = rtb_VdotPg;
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
    rtb_Add_cs = (sqrtf((8.0F * fabsf(rtb_VdotPg) + Controller_ConstB.d_ih) *
                        Controller_ConstB.d_ih) - Controller_ConstB.d_ih) * 0.5F
      * rtb_Saturation_ov + rtb_u_c;

    /* Sum: '<S45>/Add3' incorporates:
     *  Signum: '<S45>/Sign'
     */
    rtb_Abs = rtb_VdotPg + Controller_ConstB.d_ih;

    /* Sum: '<S45>/Subtract1' incorporates:
     *  Signum: '<S45>/Sign'
     */
    rtb_Gain_il = rtb_VdotPg - Controller_ConstB.d_ih;

    /* Signum: '<S45>/Sign1' */
    if (rtb_Abs < 0.0F) {
      rtb_Abs = -1.0F;
    } else {
      if (rtb_Abs > 0.0F) {
        rtb_Abs = 1.0F;
      }
    }

    /* Signum: '<S45>/Sign2' */
    if (rtb_Gain_il < 0.0F) {
      rtb_Gain_il = -1.0F;
    } else {
      if (rtb_Gain_il > 0.0F) {
        rtb_Gain_il = 1.0F;
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
    rtb_Add_cs += ((rtb_VdotPg - rtb_Add_cs) + rtb_u_c) * ((rtb_Abs -
      rtb_Gain_il) * 0.5F);

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
      CONTROL_PARAM.MC_VEL_XY_I * rtb_Divide_i_idx_1 * 0.002F;
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
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0] +=
      (rtb_DiscreteTimeIntegrator1_md_ -
       Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[0]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_g[0] += 0.002F * rtb_phi_cmd;
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
      rtb_Multiply_kn[0];

    /* Update for DiscreteIntegrator: '<S23>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S23>/Gain'
     *  Sum: '<S23>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1] +=
      (rtb_DiscreteTimeIntegrator1_m_0 -
       Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[1]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_g[1] += 0.002F * rtb_PitchOffset;
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
      rtb_Multiply_kn[1];

    /* Update for DiscreteIntegrator: '<S23>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S23>/Gain'
     *  Sum: '<S23>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2] +=
      (rtb_DiscreteTimeIntegrator1_m_1 -
       Controller_DW.DiscreteTimeIntegrator5_DSTAT_c[2]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_g[2] += 0.002F *
      rtb_Divide_i_idx_0;
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
      rtb_Multiply_kn[2];
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
      rtb_Gain_it * 0.002F;
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
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_d += 0.002F * rtb_Divide_i_idx_3;
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
    rtb_DiscreteTimeIntegrator1_md_ = rtb_Gain_ms - Controller_ConstB.d_ih;

    /* Signum: '<S45>/Sign5' incorporates:
     *  Product: '<S45>/Divide'
     */
    if (rtb_Gain_ms < 0.0F) {
      rtb_Gain_it = -1.0F;
    } else if (rtb_Gain_ms > 0.0F) {
      rtb_Gain_it = 1.0F;
    } else {
      rtb_Gain_it = rtb_Gain_ms;
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
    if (rtb_DiscreteTimeIntegrator1_md_ < 0.0F) {
      rtb_DiscreteTimeIntegrator1_md_ = -1.0F;
    } else {
      if (rtb_DiscreteTimeIntegrator1_md_ > 0.0F) {
        rtb_DiscreteTimeIntegrator1_md_ = 1.0F;
      }
    }

    /* Signum: '<S45>/Sign6' incorporates:
     *  Product: '<S45>/Divide'
     */
    if (rtb_Gain_ms < 0.0F) {
      rtb_DiscreteTimeIntegrator1_m_0 = -1.0F;
    } else if (rtb_Gain_ms > 0.0F) {
      rtb_DiscreteTimeIntegrator1_m_0 = 1.0F;
    } else {
      rtb_DiscreteTimeIntegrator1_m_0 = rtb_Gain_ms;
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
      Controller_ConstB.d_ih - rtb_Gain_it) * Controller_ConstB.Gain4_f *
      ((rtb_Abs - rtb_DiscreteTimeIntegrator1_md_) * 0.5F) -
      rtb_DiscreteTimeIntegrator1_m_0 * 58.836F) * 0.002F;

    /* Signum: '<S45>/Sign3' incorporates:
     *  Sum: '<S45>/Add6'
     */
    rtb_Abs = rtb_Add_cs + Controller_ConstB.d_ih;

    /* Signum: '<S45>/Sign4' incorporates:
     *  Sum: '<S45>/Subtract3'
     */
    rtb_DiscreteTimeIntegrator1_md_ = rtb_Add_cs - Controller_ConstB.d_ih;

    /* Signum: '<S45>/Sign5' */
    if (rtb_Add_cs < 0.0F) {
      rtb_DiscreteTimeIntegrator1_m_0 = -1.0F;
    } else if (rtb_Add_cs > 0.0F) {
      rtb_DiscreteTimeIntegrator1_m_0 = 1.0F;
    } else {
      rtb_DiscreteTimeIntegrator1_m_0 = rtb_Add_cs;
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
    if (rtb_DiscreteTimeIntegrator1_md_ < 0.0F) {
      rtb_DiscreteTimeIntegrator1_md_ = -1.0F;
    } else {
      if (rtb_DiscreteTimeIntegrator1_md_ > 0.0F) {
        rtb_DiscreteTimeIntegrator1_md_ = 1.0F;
      }
    }

    /* Signum: '<S45>/Sign6' */
    if (rtb_Add_cs < 0.0F) {
      rtb_DiscreteTimeIntegrator1_m_1 = -1.0F;
    } else if (rtb_Add_cs > 0.0F) {
      rtb_DiscreteTimeIntegrator1_m_1 = 1.0F;
    } else {
      rtb_DiscreteTimeIntegrator1_m_1 = rtb_Add_cs;
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
    Controller_DW.Integrator_DSTATE_jg[1] += ((rtb_Add_cs /
      Controller_ConstB.d_ih - rtb_DiscreteTimeIntegrator1_m_0) *
      Controller_ConstB.Gain4_f * ((rtb_Abs - rtb_DiscreteTimeIntegrator1_md_) *
      0.5F) - rtb_DiscreteTimeIntegrator1_m_1 * 58.836F) * 0.002F;

    /* Signum: '<S55>/Sign6' incorporates:
     *  Signum: '<S55>/Sign5'
     */
    if (rtb_Minus < 0.0F) {
      rtb_DiscreteTimeIntegrator1_m_0 = -1.0F;

      /* Signum: '<S55>/Sign5' */
      rtb_DiscreteTimeIntegrator1_m_1 = -1.0F;
    } else if (rtb_Minus > 0.0F) {
      rtb_DiscreteTimeIntegrator1_m_0 = 1.0F;

      /* Signum: '<S55>/Sign5' */
      rtb_DiscreteTimeIntegrator1_m_1 = 1.0F;
    } else {
      rtb_DiscreteTimeIntegrator1_m_0 = rtb_Minus;

      /* Signum: '<S55>/Sign5' */
      rtb_DiscreteTimeIntegrator1_m_1 = rtb_Minus;
    }

    /* End of Signum: '<S55>/Sign6' */

    /* Sum: '<S55>/Add6' */
    rtb_Abs = rtb_Minus + Controller_ConstB.d_j;

    /* Sum: '<S55>/Subtract3' */
    rtb_DiscreteTimeIntegrator1_md_ = rtb_Minus - Controller_ConstB.d_j;

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
    if (rtb_DiscreteTimeIntegrator1_md_ < 0.0F) {
      rtb_DiscreteTimeIntegrator1_md_ = -1.0F;
    } else {
      if (rtb_DiscreteTimeIntegrator1_md_ > 0.0F) {
        rtb_DiscreteTimeIntegrator1_md_ = 1.0F;
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
    Controller_DW.Integrator_DSTATE_e += ((rtb_Minus / Controller_ConstB.d_j -
      rtb_DiscreteTimeIntegrator1_m_1) * Controller_ConstB.Gain4_n * ((rtb_Abs -
      rtb_DiscreteTimeIntegrator1_md_) * 0.5F) - rtb_DiscreteTimeIntegrator1_m_0
      * 78.448F) * 0.002F;

    /* End of Outputs for SubSystem: '<S2>/BackTrans_Controller' */
    break;

   case 2:
    if (Controller_DW.SwitchCase1_ActiveSubsystem != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S2>/MC_Controller' incorporates:
       *  ActionPort: '<S5>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S8>/Switch Case1' incorporates:
       *  DiscreteIntegrator: '<S106>/Integrator'
       *  DiscreteIntegrator: '<S106>/Integrator1'
       *  DiscreteIntegrator: '<S111>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S113>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S129>/Integrator'
       *  DiscreteIntegrator: '<S129>/Integrator1'
       *  DiscreteIntegrator: '<S132>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S134>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S82>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S84>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S86>/Discrete-Time Integrator1'
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
    /* DiscreteIntegrator: '<S84>/Discrete-Time Integrator' */
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

    /* Trigonometry: '<S108>/Trigonometric Function1' incorporates:
     *  Gain: '<S107>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1[0] = arm_cos_f32(-Controller_U.INS_Out.psi);

    /* Trigonometry: '<S108>/Trigonometric Function' incorporates:
     *  Gain: '<S107>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1[1] = arm_sin_f32(-Controller_U.INS_Out.psi);

    /* SignalConversion: '<S108>/ConcatBufferAtVector Concatenate1In3' incorporates:
     *  Constant: '<S108>/Constant3'
     */
    rtb_MatrixConcatenate1[2] = 0.0F;

    /* Gain: '<S108>/Gain' incorporates:
     *  Gain: '<S107>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S108>/Trigonometric Function2'
     */
    rtb_MatrixConcatenate1[3] = -arm_sin_f32(-Controller_U.INS_Out.psi);

    /* Trigonometry: '<S108>/Trigonometric Function3' incorporates:
     *  Gain: '<S107>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_MatrixConcatenate1[4] = arm_cos_f32(-Controller_U.INS_Out.psi);

    /* SignalConversion: '<S108>/ConcatBufferAtVector Concatenate2In3' incorporates:
     *  Constant: '<S108>/Constant4'
     */
    rtb_MatrixConcatenate1[5] = 0.0F;

    /* SignalConversion: '<S108>/ConcatBufferAtVector ConcatenateIn3' */
    rtb_MatrixConcatenate1[6] = Controller_ConstB.VectorConcatenate3[0];
    rtb_MatrixConcatenate1[7] = Controller_ConstB.VectorConcatenate3[1];
    rtb_MatrixConcatenate1[8] = Controller_ConstB.VectorConcatenate3[2];

    /* Product: '<S105>/Multiply' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  SignalConversion: '<S105>/TmpSignal ConversionAtMultiplyInport2'
     */
    for (i = 0; i < 3; i++) {
      rtb_MatrixConcatenate1_0[i] = rtb_MatrixConcatenate1[i + 3] *
        Controller_U.INS_Out.ve + rtb_MatrixConcatenate1[i] *
        Controller_U.INS_Out.vn;
    }

    /* End of Product: '<S105>/Multiply' */

    /* Sum: '<S102>/Sum' incorporates:
     *  DiscreteIntegrator: '<S106>/Integrator1'
     */
    rtb_Divide_i_idx_2 = Controller_DW.Integrator1_DSTATE[0] -
      rtb_MatrixConcatenate1_0[0];
    rtb_Divide_i_idx_1 = Controller_DW.Integrator1_DSTATE[1] -
      rtb_MatrixConcatenate1_0[1];

    /* DiscreteIntegrator: '<S111>/Discrete-Time Integrator' */
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

    /* DiscreteIntegrator: '<S113>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] = rtb_Divide_i_idx_2;
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] = rtb_Divide_i_idx_1;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevRes != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] = rtb_Divide_i_idx_2;
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] = rtb_Divide_i_idx_1;
    }

    /* Gain: '<S113>/Gain' incorporates:
     *  DiscreteIntegrator: '<S113>/Discrete-Time Integrator1'
     *  Sum: '<S113>/Sum5'
     */
    rtb_Saturation1_h_idx_0 = (rtb_Divide_i_idx_2 -
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[0]) * 62.831852F;
    rtb_Divide_gn = (rtb_Divide_i_idx_1 -
                     Controller_DW.DiscreteTimeIntegrator1_DSTATE[1]) *
      62.831852F;

    /* Switch: '<S113>/Switch' incorporates:
     *  Gain: '<S113>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_Gain_ms = 0.0F;
      rtb_u_c = 0.0F;
    } else {
      rtb_Gain_ms = rtb_Saturation1_h_idx_0;
      rtb_u_c = rtb_Divide_gn;
    }

    /* End of Switch: '<S113>/Switch' */

    /* Product: '<S110>/Multiply' incorporates:
     *  Constant: '<S110>/kd'
     */
    rtb_Gain_it = CONTROL_PARAM.MC_VEL_XY_D * rtb_Gain_ms;

    /* Saturate: '<S110>/Saturation' */
    if (rtb_Gain_it > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
      rtb_Gain_it = CONTROL_PARAM.MC_VEL_XY_D_MAX;
    } else {
      if (rtb_Gain_it < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
        rtb_Gain_it = CONTROL_PARAM.MC_VEL_XY_D_MIN;
      }
    }

    rtb_Gain_ms = rtb_Gain_it;

    /* Product: '<S110>/Multiply' incorporates:
     *  Constant: '<S110>/kd'
     */
    rtb_Gain_it = CONTROL_PARAM.MC_VEL_XY_D * rtb_u_c;

    /* Saturate: '<S110>/Saturation' */
    if (rtb_Gain_it > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
      rtb_Gain_it = CONTROL_PARAM.MC_VEL_XY_D_MAX;
    } else {
      if (rtb_Gain_it < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
        rtb_Gain_it = CONTROL_PARAM.MC_VEL_XY_D_MIN;
      }
    }

    /* Switch: '<S104>/Switch' incorporates:
     *  Constant: '<S112>/kp'
     *  Constant: '<S114>/Constant'
     *  Constant: '<S116>/Constant'
     *  Constant: '<S117>/Constant'
     *  DiscreteIntegrator: '<S111>/Discrete-Time Integrator'
     *  Product: '<S112>/Multiply'
     *  Product: '<S115>/Multiply2'
     *  Product: '<S115>/Multiply3'
     *  RelationalOperator: '<S114>/Compare'
     *  RelationalOperator: '<S116>/Compare'
     *  RelationalOperator: '<S117>/Compare'
     *  S-Function (sfix_bitop): '<S115>/cmd_ax valid'
     *  S-Function (sfix_bitop): '<S115>/cmd_ay valid'
     *  S-Function (sfix_bitop): '<S115>/cmd_u valid'
     *  S-Function (sfix_bitop): '<S115>/cmd_v valid'
     *  Sum: '<S103>/Add'
     *  Sum: '<S115>/Sum1'
     */
    if (rtb_BitwiseAND_n == 6) {
      rtb_Gain_ms = ((Controller_U.FMS_Out.cmd_mask & 64) > 0 ?
                     (CONTROL_PARAM.MC_VEL_XY_P * rtb_Divide_i_idx_2 +
                      Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0]) +
                     rtb_Gain_ms : 0.0F) + ((Controller_U.FMS_Out.cmd_mask & 512)
        > 0 ? Controller_U.FMS_Out.ax_cmd : 0.0F);
      rtb_u_c = ((Controller_U.FMS_Out.cmd_mask & 128) > 0 ?
                 (CONTROL_PARAM.MC_VEL_XY_P * rtb_Divide_i_idx_1 +
                  Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1]) +
                 rtb_Gain_it : 0.0F) + ((Controller_U.FMS_Out.cmd_mask & 1024) >
        0 ? Controller_U.FMS_Out.ay_cmd : 0.0F);
    } else {
      rtb_Gain_ms += CONTROL_PARAM.MC_VEL_XY_P * rtb_Divide_i_idx_2 +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0];
      rtb_u_c = (CONTROL_PARAM.MC_VEL_XY_P * rtb_Divide_i_idx_1 +
                 Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1]) + rtb_Gain_it;
    }

    /* End of Switch: '<S104>/Switch' */

    /* Trigonometry: '<S101>/Atan' incorporates:
     *  Constant: '<S101>/g'
     *  Gain: '<S101>/Gain1'
     *  Gain: '<S101>/gain'
     *  Product: '<S101>/Divide'
     */
    rtb_Add_cs = atanf(1.1F * rtb_u_c / 9.8055F);
    rtb_u_c = atanf(1.1F * -rtb_Gain_ms / 9.8055F);

    /* Switch: '<S92>/Switch' incorporates:
     *  Constant: '<S99>/Constant'
     *  Logic: '<S92>/Logical Operator'
     *  RelationalOperator: '<S98>/Compare'
     *  RelationalOperator: '<S99>/Compare'
     *  Saturate: '<S101>/Saturation'
     *  Switch: '<S92>/Switch1'
     */
    if ((rtb_BitwiseAND_n == 3) || (rtb_BitwiseAND_n == 4)) {
      rtb_Gain_ms = Controller_U.FMS_Out.phi_cmd;
      rtb_u_c = Controller_U.FMS_Out.theta_cmd;
    } else if (rtb_BitwiseAND_n == 6) {
      /* Switch: '<S100>/Switch' incorporates:
       *  S-Function (sfix_bitop): '<S100>/cmd_phi valid'
       *  S-Function (sfix_bitop): '<S100>/cmd_theta valid'
       *  Saturate: '<S101>/Saturation'
       *  Switch: '<S92>/Switch1'
       */
      if ((Controller_U.FMS_Out.cmd_mask & 8) > 0) {
        rtb_Gain_ms = Controller_U.FMS_Out.phi_cmd;
      } else if (rtb_Add_cs > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S101>/Saturation' */
        rtb_Gain_ms = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else if (rtb_Add_cs < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S101>/Saturation' */
        rtb_Gain_ms = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        rtb_Gain_ms = rtb_Add_cs;
      }

      if ((Controller_U.FMS_Out.cmd_mask & 16) > 0) {
        rtb_u_c = Controller_U.FMS_Out.theta_cmd;
      } else if (rtb_u_c > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S101>/Saturation' */
        rtb_u_c = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_u_c < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Saturate: '<S101>/Saturation' */
          rtb_u_c = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        }
      }

      /* End of Switch: '<S100>/Switch' */
    } else {
      if (rtb_Add_cs > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S101>/Saturation' incorporates:
         *  Switch: '<S92>/Switch1'
         */
        rtb_Gain_ms = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else if (rtb_Add_cs < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S101>/Saturation' incorporates:
         *  Switch: '<S92>/Switch1'
         */
        rtb_Gain_ms = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        /* Switch: '<S92>/Switch1' incorporates:
         *  Saturate: '<S101>/Saturation'
         */
        rtb_Gain_ms = rtb_Add_cs;
      }

      /* Saturate: '<S101>/Saturation' */
      if (rtb_u_c > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Switch: '<S92>/Switch1' */
        rtb_u_c = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_u_c < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Switch: '<S92>/Switch1' */
          rtb_u_c = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        }
      }
    }

    /* End of Switch: '<S92>/Switch' */

    /* Sum: '<S93>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Gain_it = rtb_Gain_ms - Controller_U.INS_Out.phi;

    /* Product: '<S96>/Divide1' incorporates:
     *  Abs: '<S96>/Abs'
     *  Constant: '<S96>/const2'
     */
    rtb_Gain_il = fabsf(rtb_Gain_it) / 0.002F;

    /* Product: '<S96>/Divide' incorporates:
     *  Constant: '<S94>/Constant1'
     *  Constant: '<S96>/const1'
     *  Math: '<S96>/Square'
     *  SignalConversion: '<S96>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_Add_cs = 9.5993F / (CONTROL_PARAM.MC_ROLL_P * CONTROL_PARAM.MC_ROLL_P);

    /* Signum: '<S96>/Sign' */
    if (rtb_Gain_it < 0.0F) {
      rtb_DiscreteTimeIntegrator1_m_0 = -1.0F;
    } else if (rtb_Gain_it > 0.0F) {
      rtb_DiscreteTimeIntegrator1_m_0 = 1.0F;
    } else {
      rtb_DiscreteTimeIntegrator1_m_0 = rtb_Gain_it;
    }

    /* Switch: '<S96>/Switch' incorporates:
     *  Constant: '<S94>/Constant1'
     *  Gain: '<S96>/Gain1'
     *  Gain: '<S96>/Gain2'
     *  Logic: '<S96>/Logical Operator'
     *  Product: '<S96>/Divide'
     *  Product: '<S96>/Multiply'
     *  Product: '<S96>/Multiply1'
     *  Product: '<S96>/Multiply2'
     *  Product: '<S96>/Multiply3'
     *  RelationalOperator: '<S96>/Relational Operator'
     *  RelationalOperator: '<S96>/Relational Operator2'
     *  SignalConversion: '<S96>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S96>/Sqrt'
     *  Sum: '<S96>/Subtract'
     */
    if ((rtb_Gain_it <= rtb_Add_cs) && (rtb_Gain_it >= -rtb_Add_cs)) {
      rtb_DiscreteTimeIntegrator1_m_0 = rtb_Gain_it * CONTROL_PARAM.MC_ROLL_P;
    } else {
      rtb_DiscreteTimeIntegrator1_m_0 *= sqrtf((rtb_DiscreteTimeIntegrator1_m_0 *
        rtb_Gain_it - 0.5F * rtb_Add_cs) * Controller_ConstB.Gain);
    }

    /* Gain: '<S96>/Gain3' */
    rtb_Add_cs = -rtb_Gain_il;

    /* Switch: '<S97>/Switch' incorporates:
     *  Gain: '<S96>/Gain3'
     *  RelationalOperator: '<S97>/UpperRelop'
     */
    if (rtb_DiscreteTimeIntegrator1_m_0 >= -rtb_Gain_il) {
      rtb_Add_cs = rtb_DiscreteTimeIntegrator1_m_0;
    }

    /* Switch: '<S97>/Switch2' incorporates:
     *  RelationalOperator: '<S97>/LowerRelop1'
     */
    if (rtb_DiscreteTimeIntegrator1_m_0 <= rtb_Gain_il) {
      rtb_Gain_il = rtb_Add_cs;
    }

    /* Saturate: '<S77>/Saturation1' */
    if (rtb_Gain_il > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_Gain_il = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_Gain_il < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_Gain_il = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    rtb_Saturation_ov = rtb_Gain_il;

    /* Sum: '<S93>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S96>/Divide1'
     */
    rtb_Gain_it = rtb_u_c - Controller_U.INS_Out.theta;

    /* Product: '<S96>/Divide1' incorporates:
     *  Abs: '<S96>/Abs'
     *  Constant: '<S96>/const2'
     */
    rtb_Gain_il = fabsf(rtb_Gain_it) / 0.002F;

    /* Product: '<S96>/Divide' incorporates:
     *  Constant: '<S94>/Constant2'
     *  Constant: '<S96>/const1'
     *  Math: '<S96>/Square'
     *  SignalConversion: '<S96>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_Add_cs = 9.5993F / (CONTROL_PARAM.MC_PITCH_P * CONTROL_PARAM.MC_PITCH_P);

    /* Signum: '<S96>/Sign' */
    if (rtb_Gain_it < 0.0F) {
      rtb_DiscreteTimeIntegrator1_m_0 = -1.0F;
    } else if (rtb_Gain_it > 0.0F) {
      rtb_DiscreteTimeIntegrator1_m_0 = 1.0F;
    } else {
      rtb_DiscreteTimeIntegrator1_m_0 = rtb_Gain_it;
    }

    /* Switch: '<S96>/Switch' incorporates:
     *  Constant: '<S94>/Constant2'
     *  Gain: '<S96>/Gain1'
     *  Gain: '<S96>/Gain2'
     *  Logic: '<S96>/Logical Operator'
     *  Product: '<S96>/Divide'
     *  Product: '<S96>/Multiply'
     *  Product: '<S96>/Multiply1'
     *  Product: '<S96>/Multiply2'
     *  Product: '<S96>/Multiply3'
     *  RelationalOperator: '<S96>/Relational Operator'
     *  RelationalOperator: '<S96>/Relational Operator2'
     *  SignalConversion: '<S96>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S96>/Sqrt'
     *  Sum: '<S96>/Subtract'
     */
    if ((rtb_Gain_it <= rtb_Add_cs) && (rtb_Gain_it >= -rtb_Add_cs)) {
      rtb_DiscreteTimeIntegrator1_m_0 = rtb_Gain_it * CONTROL_PARAM.MC_PITCH_P;
    } else {
      rtb_DiscreteTimeIntegrator1_m_0 *= sqrtf((rtb_DiscreteTimeIntegrator1_m_0 *
        rtb_Gain_it - 0.5F * rtb_Add_cs) * Controller_ConstB.Gain);
    }

    /* Gain: '<S96>/Gain3' */
    rtb_Add_cs = -rtb_Gain_il;

    /* Switch: '<S97>/Switch' incorporates:
     *  Gain: '<S96>/Gain3'
     *  RelationalOperator: '<S97>/UpperRelop'
     */
    if (rtb_DiscreteTimeIntegrator1_m_0 >= -rtb_Gain_il) {
      rtb_Add_cs = rtb_DiscreteTimeIntegrator1_m_0;
    }

    /* Switch: '<S97>/Switch2' incorporates:
     *  RelationalOperator: '<S97>/LowerRelop1'
     */
    if (rtb_DiscreteTimeIntegrator1_m_0 <= rtb_Gain_il) {
      rtb_Gain_il = rtb_Add_cs;
    }

    /* Saturate: '<S77>/Saturation1' */
    if (rtb_Gain_il > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_Gain_il = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_Gain_il < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_Gain_il = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    /* Saturate: '<S77>/Saturation' */
    if (Controller_U.FMS_Out.psi_rate_cmd > CONTROL_PARAM.MC_R_CMD_LIM) {
      rtb_Add_cs = CONTROL_PARAM.MC_R_CMD_LIM;
    } else if (Controller_U.FMS_Out.psi_rate_cmd < -CONTROL_PARAM.MC_R_CMD_LIM)
    {
      rtb_Add_cs = -CONTROL_PARAM.MC_R_CMD_LIM;
    } else {
      rtb_Add_cs = Controller_U.FMS_Out.psi_rate_cmd;
    }

    /* End of Saturate: '<S77>/Saturation' */

    /* Trigonometry: '<S87>/Sin' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_phi_cmd = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S87>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_DiscreteTimeIntegrator1_md_ = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Product: '<S87>/Multiply3' incorporates:
     *  Trigonometry: '<S87>/Cos1'
     *  Trigonometry: '<S87>/Sin'
     */
    rtb_DiscreteTimeIntegrator1_m_0 = rtb_phi_cmd *
      rtb_DiscreteTimeIntegrator1_md_ * rtb_Add_cs;

    /* Trigonometry: '<S87>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_DiscreteTimeIntegrator1_m_1 = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Product: '<S87>/Multiply1' incorporates:
     *  Trigonometry: '<S87>/Cos'
     */
    rtb_Gain_ms = rtb_DiscreteTimeIntegrator1_m_1 * rtb_Gain_il;

    /* Product: '<S87>/Multiply4' incorporates:
     *  Trigonometry: '<S87>/Sin'
     */
    rtb_phi_cmd *= rtb_Gain_il;

    /* Switch: '<S78>/Switch' incorporates:
     *  Constant: '<S88>/Constant'
     *  Constant: '<S89>/Constant'
     *  RelationalOperator: '<S88>/Compare'
     *  RelationalOperator: '<S89>/Compare'
     *  Switch: '<S78>/Switch1'
     */
    if (rtb_BitwiseAND_n == 2) {
      rtb_Multiply_kn[0] = Controller_U.FMS_Out.p_cmd;
      rtb_Multiply_kn[1] = Controller_U.FMS_Out.q_cmd;
      rtb_Multiply_kn[2] = Controller_U.FMS_Out.r_cmd;
    } else if (rtb_BitwiseAND_n == 6) {
      /* Switch: '<S90>/Switch' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Product: '<S87>/Multiply'
       *  Product: '<S87>/Multiply1'
       *  Product: '<S87>/Multiply5'
       *  S-Function (sfix_bitop): '<S90>/cmd_p valid'
       *  S-Function (sfix_bitop): '<S90>/cmd_q valid'
       *  S-Function (sfix_bitop): '<S90>/cmd_r valid'
       *  Sum: '<S87>/Add'
       *  Sum: '<S87>/Add1'
       *  Sum: '<S87>/Add2'
       *  Switch: '<S78>/Switch1'
       *  Trigonometry: '<S87>/Cos'
       *  Trigonometry: '<S87>/Cos1'
       *  Trigonometry: '<S87>/Sin1'
       */
      if ((Controller_U.FMS_Out.cmd_mask & 1) > 0) {
        rtb_Multiply_kn[0] = Controller_U.FMS_Out.p_cmd;
      } else {
        rtb_Multiply_kn[0] = rtb_Saturation_ov - arm_sin_f32
          (Controller_U.INS_Out.theta) * rtb_Add_cs;
      }

      if ((Controller_U.FMS_Out.cmd_mask & 2) > 0) {
        rtb_Multiply_kn[1] = Controller_U.FMS_Out.q_cmd;
      } else {
        rtb_Multiply_kn[1] = rtb_DiscreteTimeIntegrator1_m_0 + rtb_Gain_ms;
      }

      if ((Controller_U.FMS_Out.cmd_mask & 4) > 0) {
        rtb_Multiply_kn[2] = Controller_U.FMS_Out.r_cmd;
      } else {
        rtb_Multiply_kn[2] = rtb_DiscreteTimeIntegrator1_m_1 *
          rtb_DiscreteTimeIntegrator1_md_ * rtb_Add_cs - rtb_phi_cmd;
      }

      /* End of Switch: '<S90>/Switch' */
    } else {
      /* Switch: '<S78>/Switch1' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Product: '<S87>/Multiply'
       *  Product: '<S87>/Multiply3'
       *  Product: '<S87>/Multiply5'
       *  Sum: '<S87>/Add'
       *  Sum: '<S87>/Add1'
       *  Sum: '<S87>/Add2'
       *  Trigonometry: '<S87>/Cos'
       *  Trigonometry: '<S87>/Cos1'
       *  Trigonometry: '<S87>/Sin1'
       */
      rtb_Multiply_kn[0] = rtb_Saturation_ov - arm_sin_f32
        (Controller_U.INS_Out.theta) * rtb_Add_cs;
      rtb_Multiply_kn[1] = rtb_Gain_ms + rtb_DiscreteTimeIntegrator1_m_0;
      rtb_Multiply_kn[2] = rtb_DiscreteTimeIntegrator1_m_1 *
        rtb_DiscreteTimeIntegrator1_md_ * rtb_Add_cs - rtb_phi_cmd;
    }

    /* End of Switch: '<S78>/Switch' */

    /* Sum: '<S79>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_DiscreteTimeIntegrator1_md_ = rtb_Multiply_kn[0] -
      Controller_U.INS_Out.p;
    rtb_DiscreteTimeIntegrator1_m_0 = rtb_Multiply_kn[1] -
      Controller_U.INS_Out.q;
    rtb_DiscreteTimeIntegrator1_m_1 = rtb_Multiply_kn[2] -
      Controller_U.INS_Out.r;

    /* DiscreteIntegrator: '<S82>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] =
        rtb_DiscreteTimeIntegrator1_md_;
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] =
        rtb_DiscreteTimeIntegrator1_m_0;
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] =
        rtb_DiscreteTimeIntegrator1_m_1;
    }

    /* DiscreteIntegrator: '<S86>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S82>/Discrete-Time Integrator5'
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

    /* Gain: '<S86>/Gain' incorporates:
     *  DiscreteIntegrator: '<S82>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S86>/Discrete-Time Integrator1'
     *  Sum: '<S86>/Sum5'
     */
    rtb_Multiply_kn[0] = (Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] -
                          Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[0]) *
      188.49556F;
    rtb_Multiply_kn[1] = (Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] -
                          Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[1]) *
      188.49556F;
    rtb_Multiply_kn[2] = (Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] -
                          Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[2]) *
      188.49556F;

    /* Gain: '<S127>/Gain' incorporates:
     *  DiscreteIntegrator: '<S129>/Integrator1'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S127>/Sum1'
     */
    rtb_Divide_i_idx_3 = -(Controller_DW.Integrator1_DSTATE_e -
      Controller_U.INS_Out.vd);
    Controller_B.Constant = CONTROL_PARAM.MC_VEL_Z_I_MIN;

    /* DiscreteIntegrator: '<S132>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S132>/Constant'
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

    /* DiscreteIntegrator: '<S134>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_d != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i = rtb_Divide_i_idx_3;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_Prev_ks != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i = rtb_Divide_i_idx_3;
    }

    /* Gain: '<S134>/Gain' incorporates:
     *  DiscreteIntegrator: '<S134>/Discrete-Time Integrator1'
     *  Sum: '<S134>/Sum5'
     */
    rtb_Gain_il = (rtb_Divide_i_idx_3 -
                   Controller_DW.DiscreteTimeIntegrator1_DSTAT_i) * 62.831852F;

    /* Switch: '<S134>/Switch' incorporates:
     *  Gain: '<S134>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_Saturation_a5 = 0.0F;
    } else {
      rtb_Saturation_a5 = rtb_Gain_il;
    }

    /* End of Switch: '<S134>/Switch' */

    /* Product: '<S131>/Multiply' incorporates:
     *  Constant: '<S131>/kd'
     */
    rtb_Add_cs = CONTROL_PARAM.MC_VEL_Z_D * rtb_Saturation_a5;

    /* Saturate: '<S131>/Saturation' */
    if (rtb_Add_cs > CONTROL_PARAM.MC_VEL_Z_D_MAX) {
      rtb_Add_cs = CONTROL_PARAM.MC_VEL_Z_D_MAX;
    } else {
      if (rtb_Add_cs < CONTROL_PARAM.MC_VEL_Z_D_MIN) {
        rtb_Add_cs = CONTROL_PARAM.MC_VEL_Z_D_MIN;
      }
    }

    /* End of Saturate: '<S131>/Saturation' */

    /* Sum: '<S128>/Add' incorporates:
     *  Constant: '<S133>/kp'
     *  DiscreteIntegrator: '<S132>/Discrete-Time Integrator'
     *  Product: '<S133>/Multiply'
     */
    rtb_Saturation_ov = (CONTROL_PARAM.MC_VEL_Z_P * rtb_Divide_i_idx_3 +
                         Controller_DW.DiscreteTimeIntegrator_DSTATE_l) +
      rtb_Add_cs;

    /* Product: '<S126>/Multiply' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S126>/Cos'
     *  Trigonometry: '<S126>/Cos1'
     */
    rtb_Add_cs = arm_cos_f32(Controller_U.INS_Out.phi) * arm_cos_f32
      (Controller_U.INS_Out.theta);

    /* Saturate: '<S126>/Saturation1' */
    if (rtb_Add_cs > 1.0F) {
      rtb_phi_cmd = 1.0F;
    } else if (rtb_Add_cs < 0.5F) {
      rtb_phi_cmd = 0.5F;
    } else {
      rtb_phi_cmd = rtb_Add_cs;
    }

    /* End of Saturate: '<S126>/Saturation1' */

    /* Gain: '<S126>/Gain' */
    rtb_Add_cs *= 2.0F;

    /* Saturate: '<S126>/Saturation' */
    if (rtb_Add_cs > 1.0F) {
      rtb_Add_cs = 1.0F;
    } else {
      if (rtb_Add_cs < 0.0F) {
        rtb_Add_cs = 0.0F;
      }
    }

    /* End of Saturate: '<S126>/Saturation' */

    /* Product: '<S126>/Multiply1' incorporates:
     *  Constant: '<S126>/Constant'
     *  Product: '<S126>/Divide'
     */
    rtb_Add_cs *= 1.0F / rtb_phi_cmd * rtb_Saturation_ov;

    /* Outputs for Atomic SubSystem: '<S70>/Quadcopter_x' */
    /* MultiPortSwitch: '<S120>/Multiport Switch' incorporates:
     *  Product: '<S83>/Multiply'
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
      /* Switch: '<S86>/Switch' incorporates:
       *  Gain: '<S86>/Gain1'
       */
      if (Controller_U.FMS_Out.reset > 0) {
        rtb_phi_cmd = 0.0F;
        rtb_PitchOffset = 0.0F;
        rtb_Divide_i_idx_0 = 0.0F;
      } else {
        rtb_phi_cmd = rtb_Multiply_kn[0];
        rtb_PitchOffset = rtb_Multiply_kn[1];
        rtb_Divide_i_idx_0 = rtb_Multiply_kn[2];
      }

      /* End of Switch: '<S86>/Switch' */

      /* Product: '<S83>/Multiply' incorporates:
       *  Constant: '<S83>/gain1'
       */
      rtb_Saturation_ov = CONTROL_PARAM.MC_ROLL_RATE_D * rtb_phi_cmd;

      /* Saturate: '<S83>/Saturation' */
      if (rtb_Saturation_ov > CONTROL_PARAM.MC_RATE_D_MAX) {
        rtb_Saturation_ov = CONTROL_PARAM.MC_RATE_D_MAX;
      } else {
        if (rtb_Saturation_ov < CONTROL_PARAM.MC_RATE_D_MIN) {
          rtb_Saturation_ov = CONTROL_PARAM.MC_RATE_D_MIN;
        }
      }

      rtb_phi_cmd = rtb_Saturation_ov;

      /* Product: '<S83>/Multiply' incorporates:
       *  Constant: '<S83>/gain2'
       */
      rtb_Saturation_ov = CONTROL_PARAM.MC_PITCH_RATE_D * rtb_PitchOffset;

      /* Saturate: '<S83>/Saturation' */
      if (rtb_Saturation_ov > CONTROL_PARAM.MC_RATE_D_MAX) {
        rtb_Saturation_ov = CONTROL_PARAM.MC_RATE_D_MAX;
      } else {
        if (rtb_Saturation_ov < CONTROL_PARAM.MC_RATE_D_MIN) {
          rtb_Saturation_ov = CONTROL_PARAM.MC_RATE_D_MIN;
        }
      }

      rtb_PitchOffset = rtb_Saturation_ov;

      /* Product: '<S83>/Multiply' incorporates:
       *  Constant: '<S83>/gain3'
       */
      rtb_Saturation_ov = CONTROL_PARAM.MC_YAW_RATE_D * rtb_Divide_i_idx_0;

      /* Saturate: '<S83>/Saturation' */
      if (rtb_Saturation_ov > CONTROL_PARAM.MC_RATE_D_MAX) {
        rtb_Saturation_ov = CONTROL_PARAM.MC_RATE_D_MAX;
      } else {
        if (rtb_Saturation_ov < CONTROL_PARAM.MC_RATE_D_MIN) {
          rtb_Saturation_ov = CONTROL_PARAM.MC_RATE_D_MIN;
        }
      }

      /* Switch: '<S119>/Switch' incorporates:
       *  Constant: '<S123>/Constant'
       *  Logic: '<S119>/Logical Operator'
       *  RelationalOperator: '<S122>/Compare'
       *  RelationalOperator: '<S123>/Compare'
       *  Saturate: '<S125>/Saturation'
       *  Switch: '<S119>/Switch1'
       */
      if ((rtb_BitwiseAND_n == 1) || (rtb_BitwiseAND_n == 2) ||
          (rtb_BitwiseAND_n == 3)) {
        rtb_DataTypeConversion_k = Controller_U.FMS_Out.throttle_cmd;
      } else if (rtb_BitwiseAND_n == 6) {
        /* Switch: '<S124>/Switch' incorporates:
         *  Constant: '<S121>/Constant1'
         *  DataTypeConversion: '<S121>/Data Type Conversion'
         *  Gain: '<S121>/Gain1'
         *  S-Function (sfix_bitop): '<S124>/cmd_throttle valid'
         *  Saturate: '<S125>/Saturation'
         *  Sum: '<S121>/Sum1'
         *  Switch: '<S119>/Switch1'
         */
        if ((Controller_U.FMS_Out.cmd_mask & 4096) > 0) {
          rtb_DataTypeConversion_k = Controller_U.FMS_Out.throttle_cmd;
        } else {
          if (rtb_Add_cs > 0.35F) {
            /* Saturate: '<S125>/Saturation' */
            rtb_Add_cs = 0.35F;
          } else {
            if (rtb_Add_cs < -0.35F) {
              /* Saturate: '<S125>/Saturation' */
              rtb_Add_cs = -0.35F;
            }
          }

          /* Sum: '<S121>/Sum' incorporates:
           *  Constant: '<S121>/hover_throttle'
           *  Saturate: '<S125>/Saturation'
           */
          rtb_Add_cs += CONTROL_PARAM.MC_HOVER_THRO;

          /* Saturate: '<S121>/Saturation' */
          if (rtb_Add_cs > 1.0F) {
            rtb_Add_cs = 1.0F;
          } else {
            if (rtb_Add_cs < 0.0F) {
              rtb_Add_cs = 0.0F;
            }
          }

          rtb_DataTypeConversion_k = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
            rtb_Add_cs), 4.2949673E+9F) + 1000U);
        }

        /* End of Switch: '<S124>/Switch' */
      } else {
        if (rtb_Add_cs > 0.35F) {
          /* Saturate: '<S125>/Saturation' */
          rtb_Add_cs = 0.35F;
        } else {
          if (rtb_Add_cs < -0.35F) {
            /* Saturate: '<S125>/Saturation' */
            rtb_Add_cs = -0.35F;
          }
        }

        /* Sum: '<S121>/Sum' incorporates:
         *  Constant: '<S121>/hover_throttle'
         *  Saturate: '<S125>/Saturation'
         */
        rtb_Add_cs += CONTROL_PARAM.MC_HOVER_THRO;

        /* Saturate: '<S121>/Saturation' */
        if (rtb_Add_cs > 1.0F) {
          rtb_Add_cs = 1.0F;
        } else {
          if (rtb_Add_cs < 0.0F) {
            rtb_Add_cs = 0.0F;
          }
        }

        /* Switch: '<S119>/Switch1' incorporates:
         *  Constant: '<S121>/Constant1'
         *  DataTypeConversion: '<S121>/Data Type Conversion'
         *  Gain: '<S121>/Gain1'
         *  Sum: '<S121>/Sum1'
         */
        rtb_DataTypeConversion_k = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          rtb_Add_cs), 4.2949673E+9F) + 1000U);
      }

      /* End of Switch: '<S119>/Switch' */

      /* Saturate: '<S118>/Saturation1' incorporates:
       *  Constant: '<S85>/gain1'
       *  Constant: '<S85>/gain2'
       *  Constant: '<S85>/gain3'
       *  DiscreteIntegrator: '<S82>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S84>/Discrete-Time Integrator'
       *  Product: '<S85>/Multiply'
       *  Sum: '<S80>/Add'
       */
      rtb_Add_cs = (CONTROL_PARAM.MC_ROLL_RATE_P *
                    Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] +
                    Controller_DW.DiscreteTimeIntegrator_DSTATE[0]) +
        rtb_phi_cmd;
      if (rtb_Add_cs > 1.0F) {
        rtb_Add_cs = 1.0F;
      } else {
        if (rtb_Add_cs < -1.0F) {
          rtb_Add_cs = -1.0F;
        }
      }

      rtb_Minus = (CONTROL_PARAM.MC_PITCH_RATE_P *
                   Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] +
                   Controller_DW.DiscreteTimeIntegrator_DSTATE[1]) +
        rtb_PitchOffset;
      if (rtb_Minus > 1.0F) {
        rtb_Minus = 1.0F;
      } else {
        if (rtb_Minus < -1.0F) {
          rtb_Minus = -1.0F;
        }
      }

      rtb_Sum = (CONTROL_PARAM.MC_YAW_RATE_P *
                 Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] +
                 Controller_DW.DiscreteTimeIntegrator_DSTATE[2]) +
        rtb_Saturation_ov;
      if (rtb_Sum > 1.0F) {
        rtb_Sum = 1.0F;
      } else {
        if (rtb_Sum < -1.0F) {
          rtb_Sum = -1.0F;
        }
      }

      /* End of Saturate: '<S118>/Saturation1' */

      /* Product: '<S118>/Multiply' */
      for (i = 0; i < 4; i++) {
        /* Saturate: '<S118>/Saturation' incorporates:
         *  Constant: '<S118>/Effective_Matrix'
         *  Gain: '<S118>/Gain'
         *  Sum: '<S118>/Add'
         */
        rtb_Saturation_a5 = fmodf(floorf(1000.0F * (Controller_ConstP.pooled19[i
          + 8] * rtb_Sum + (Controller_ConstP.pooled19[i + 4] * rtb_Minus +
                            Controller_ConstP.pooled19[i] * rtb_Add_cs)) +
          (real32_T)rtb_DataTypeConversion_k), 65536.0F);
        u0 = (uint16_T)(rtb_Saturation_a5 < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                        (uint16_T)-rtb_Saturation_a5 : (int32_T)(uint16_T)
                        rtb_Saturation_a5);
        if (u0 > 1900) {
          rtb_MultiportSwitch_o[i] = 1900U;
        } else if (u0 < 1100) {
          rtb_MultiportSwitch_o[i] = 1100U;
        } else {
          rtb_MultiportSwitch_o[i] = u0;
        }

        /* End of Saturate: '<S118>/Saturation' */
      }

      /* End of Product: '<S118>/Multiply' */
      break;

     default:
      rtb_MultiportSwitch_o[0] = 1000U;
      rtb_MultiportSwitch_o[1] = 1000U;
      rtb_MultiportSwitch_o[2] = 1000U;
      rtb_MultiportSwitch_o[3] = 1000U;
      break;
    }

    /* End of MultiPortSwitch: '<S120>/Multiport Switch' */

    /* Outport: '<Root>/Control_Out' incorporates:
     *  Constant: '<S120>/Disarm1'
     *  Reshape: '<S120>/Reshape'
     */
    Controller_Y.Control_Out.actuator_cmd[0] = rtb_MultiportSwitch_o[0];
    Controller_Y.Control_Out.actuator_cmd[1] = rtb_MultiportSwitch_o[1];
    Controller_Y.Control_Out.actuator_cmd[2] = rtb_MultiportSwitch_o[2];
    Controller_Y.Control_Out.actuator_cmd[3] = rtb_MultiportSwitch_o[3];
    for (i = 0; i < 5; i++) {
      Controller_Y.Control_Out.actuator_cmd[i + 4] =
        Controller_ConstP.Disarm1_Value[i];
    }

    for (i = 0; i < 7; i++) {
      Controller_Y.Control_Out.actuator_cmd[i + 9] = 0U;
    }

    /* End of Outputs for SubSystem: '<S70>/Quadcopter_x' */

    /* Product: '<S109>/Multiply1' incorporates:
     *  Constant: '<S109>/const1'
     *  DiscreteIntegrator: '<S106>/Integrator'
     */
    rtb_Saturation_ov = Controller_DW.Integrator_DSTATE[0] * 0.05F;
    rtb_VdotPg = Controller_DW.Integrator_DSTATE[1] * 0.05F;

    /* Sum: '<S109>/Add' incorporates:
     *  DiscreteIntegrator: '<S106>/Integrator1'
     *  Sum: '<S106>/Subtract'
     */
    rtb_Gain_ms = (Controller_DW.Integrator1_DSTATE[0] -
                   Controller_U.FMS_Out.u_cmd) + rtb_Saturation_ov;
    rtb_PitchOffset = (Controller_DW.Integrator1_DSTATE[1] -
                       Controller_U.FMS_Out.v_cmd) + rtb_VdotPg;

    /* Signum: '<S109>/Sign' */
    if (rtb_Gain_ms < 0.0F) {
      rtb_Gain_it = -1.0F;
    } else if (rtb_Gain_ms > 0.0F) {
      rtb_Gain_it = 1.0F;
    } else {
      rtb_Gain_it = rtb_Gain_ms;
    }

    /* Sum: '<S109>/Add2' incorporates:
     *  Abs: '<S109>/Abs'
     *  Gain: '<S109>/Gain'
     *  Gain: '<S109>/Gain1'
     *  Product: '<S109>/Multiply2'
     *  Product: '<S109>/Multiply3'
     *  Signum: '<S109>/Sign'
     *  Sqrt: '<S109>/Sqrt'
     *  Sum: '<S109>/Add1'
     *  Sum: '<S109>/Subtract'
     */
    rtb_Gain_it = (sqrtf((8.0F * fabsf(rtb_Gain_ms) + Controller_ConstB.d) *
                         Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
      rtb_Gain_it + rtb_Saturation_ov;

    /* Sum: '<S109>/Add3' incorporates:
     *  Signum: '<S109>/Sign'
     */
    rtb_Abs = rtb_Gain_ms + Controller_ConstB.d;

    /* Sum: '<S109>/Subtract1' incorporates:
     *  Signum: '<S109>/Sign'
     */
    rtb_Add_cs = rtb_Gain_ms - Controller_ConstB.d;

    /* Signum: '<S109>/Sign1' */
    if (rtb_Abs < 0.0F) {
      rtb_Abs = -1.0F;
    } else {
      if (rtb_Abs > 0.0F) {
        rtb_Abs = 1.0F;
      }
    }

    /* Signum: '<S109>/Sign2' */
    if (rtb_Add_cs < 0.0F) {
      rtb_Add_cs = -1.0F;
    } else {
      if (rtb_Add_cs > 0.0F) {
        rtb_Add_cs = 1.0F;
      }
    }

    /* Sum: '<S109>/Add2' incorporates:
     *  Gain: '<S109>/Gain2'
     *  Product: '<S109>/Multiply4'
     *  Signum: '<S109>/Sign'
     *  Sum: '<S109>/Add4'
     *  Sum: '<S109>/Add5'
     *  Sum: '<S109>/Subtract2'
     */
    rtb_Gain_ms = ((rtb_Gain_ms - rtb_Gain_it) + rtb_Saturation_ov) * ((rtb_Abs
      - rtb_Add_cs) * 0.5F) + rtb_Gain_it;

    /* Signum: '<S109>/Sign' */
    if (rtb_PitchOffset < 0.0F) {
      rtb_Saturation_ov = -1.0F;
    } else if (rtb_PitchOffset > 0.0F) {
      rtb_Saturation_ov = 1.0F;
    } else {
      rtb_Saturation_ov = rtb_PitchOffset;
    }

    /* Sum: '<S109>/Add2' incorporates:
     *  Abs: '<S109>/Abs'
     *  Gain: '<S109>/Gain'
     *  Gain: '<S109>/Gain1'
     *  Product: '<S109>/Multiply2'
     *  Product: '<S109>/Multiply3'
     *  Signum: '<S109>/Sign'
     *  Sqrt: '<S109>/Sqrt'
     *  Sum: '<S109>/Add1'
     *  Sum: '<S109>/Subtract'
     */
    rtb_Gain_it = (sqrtf((8.0F * fabsf(rtb_PitchOffset) + Controller_ConstB.d) *
                         Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
      rtb_Saturation_ov + rtb_VdotPg;

    /* Sum: '<S109>/Add3' incorporates:
     *  Signum: '<S109>/Sign'
     */
    rtb_Abs = rtb_PitchOffset + Controller_ConstB.d;

    /* Sum: '<S109>/Subtract1' incorporates:
     *  Signum: '<S109>/Sign'
     */
    rtb_Add_cs = rtb_PitchOffset - Controller_ConstB.d;

    /* Signum: '<S109>/Sign1' */
    if (rtb_Abs < 0.0F) {
      rtb_Abs = -1.0F;
    } else {
      if (rtb_Abs > 0.0F) {
        rtb_Abs = 1.0F;
      }
    }

    /* Signum: '<S109>/Sign2' */
    if (rtb_Add_cs < 0.0F) {
      rtb_Add_cs = -1.0F;
    } else {
      if (rtb_Add_cs > 0.0F) {
        rtb_Add_cs = 1.0F;
      }
    }

    /* Sum: '<S109>/Add5' incorporates:
     *  Gain: '<S109>/Gain2'
     *  Product: '<S109>/Multiply4'
     *  Signum: '<S109>/Sign'
     *  Sum: '<S109>/Add2'
     *  Sum: '<S109>/Add4'
     *  Sum: '<S109>/Subtract2'
     */
    rtb_Gain_it += ((rtb_PitchOffset - rtb_Gain_it) + rtb_VdotPg) * ((rtb_Abs -
      rtb_Add_cs) * 0.5F);

    /* Product: '<S130>/Multiply1' incorporates:
     *  Constant: '<S130>/const1'
     *  DiscreteIntegrator: '<S129>/Integrator'
     */
    rtb_phi_cmd = Controller_DW.Integrator_DSTATE_j * 0.05F;

    /* Sum: '<S130>/Add' incorporates:
     *  DiscreteIntegrator: '<S129>/Integrator1'
     *  Sum: '<S129>/Subtract'
     */
    rtb_Add_cs = (Controller_DW.Integrator1_DSTATE_e -
                  Controller_U.FMS_Out.w_cmd) + rtb_phi_cmd;

    /* Signum: '<S130>/Sign' */
    if (rtb_Add_cs < 0.0F) {
      rtb_Saturation_ov = -1.0F;
    } else if (rtb_Add_cs > 0.0F) {
      rtb_Saturation_ov = 1.0F;
    } else {
      rtb_Saturation_ov = rtb_Add_cs;
    }

    /* End of Signum: '<S130>/Sign' */

    /* Sum: '<S130>/Add2' incorporates:
     *  Abs: '<S130>/Abs'
     *  Gain: '<S130>/Gain'
     *  Gain: '<S130>/Gain1'
     *  Product: '<S130>/Multiply2'
     *  Product: '<S130>/Multiply3'
     *  Sqrt: '<S130>/Sqrt'
     *  Sum: '<S130>/Add1'
     *  Sum: '<S130>/Subtract'
     */
    rtb_Saturation_ov = (sqrtf((8.0F * fabsf(rtb_Add_cs) + Controller_ConstB.d_i)
      * Controller_ConstB.d_i) - Controller_ConstB.d_i) * 0.5F *
      rtb_Saturation_ov + rtb_phi_cmd;

    /* Sum: '<S130>/Add4' */
    rtb_phi_cmd += rtb_Add_cs - rtb_Saturation_ov;

    /* Sum: '<S130>/Add3' */
    rtb_Abs = rtb_Add_cs + Controller_ConstB.d_i;

    /* Sum: '<S130>/Subtract1' */
    rtb_Add_cs -= Controller_ConstB.d_i;

    /* Signum: '<S130>/Sign1' */
    if (rtb_Abs < 0.0F) {
      rtb_Abs = -1.0F;
    } else {
      if (rtb_Abs > 0.0F) {
        rtb_Abs = 1.0F;
      }
    }

    /* End of Signum: '<S130>/Sign1' */

    /* Signum: '<S130>/Sign2' */
    if (rtb_Add_cs < 0.0F) {
      rtb_Add_cs = -1.0F;
    } else {
      if (rtb_Add_cs > 0.0F) {
        rtb_Add_cs = 1.0F;
      }
    }

    /* End of Signum: '<S130>/Sign2' */

    /* Sum: '<S130>/Add5' incorporates:
     *  Gain: '<S130>/Gain2'
     *  Product: '<S130>/Multiply4'
     *  Sum: '<S130>/Subtract2'
     */
    rtb_Saturation_ov += (rtb_Abs - rtb_Add_cs) * 0.5F * rtb_phi_cmd;

    /* Update for DiscreteIntegrator: '<S84>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S84>/gain1'
     *  Constant: '<S84>/gain2'
     *  Constant: '<S84>/gain3'
     *  DiscreteIntegrator: '<S82>/Discrete-Time Integrator5'
     *  Product: '<S84>/Multiply'
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

    /* End of Update for DiscreteIntegrator: '<S84>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S111>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_PrevRe_p = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S113>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;

    /* Update for DiscreteIntegrator: '<S106>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S106>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE[0] += 0.002F *
      Controller_DW.Integrator_DSTATE[0];

    /* Update for DiscreteIntegrator: '<S111>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S111>/ki'
     *  Product: '<S111>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0] +=
      CONTROL_PARAM.MC_VEL_XY_I * rtb_Divide_i_idx_2 * 0.002F;
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

    /* Update for DiscreteIntegrator: '<S113>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] += 0.002F *
      rtb_Saturation1_h_idx_0;

    /* Update for DiscreteIntegrator: '<S106>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S106>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE[1] += 0.002F *
      Controller_DW.Integrator_DSTATE[1];

    /* Update for DiscreteIntegrator: '<S111>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S111>/ki'
     *  Product: '<S111>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1] +=
      CONTROL_PARAM.MC_VEL_XY_I * rtb_Divide_i_idx_1 * 0.002F;
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

    /* Update for DiscreteIntegrator: '<S113>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] += 0.002F * rtb_Divide_gn;
    Controller_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S82>/Discrete-Time Integrator5' */
    Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;

    /* Update for DiscreteIntegrator: '<S86>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 0U;

    /* Update for DiscreteIntegrator: '<S82>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S82>/Gain'
     *  Sum: '<S82>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] +=
      (rtb_DiscreteTimeIntegrator1_md_ -
       Controller_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S86>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[0] += 0.002F *
      rtb_Multiply_kn[0];

    /* Update for DiscreteIntegrator: '<S82>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S82>/Gain'
     *  Sum: '<S82>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] +=
      (rtb_DiscreteTimeIntegrator1_m_0 -
       Controller_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S86>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[1] += 0.002F *
      rtb_Multiply_kn[1];

    /* Update for DiscreteIntegrator: '<S82>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S82>/Gain'
     *  Sum: '<S82>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] +=
      (rtb_DiscreteTimeIntegrator1_m_1 -
       Controller_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S86>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[2] += 0.002F *
      rtb_Multiply_kn[2];
    Controller_DW.DiscreteTimeIntegrator1_PrevR_k = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S129>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S129>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_e += 0.002F *
      Controller_DW.Integrator_DSTATE_j;

    /* Update for DiscreteIntegrator: '<S132>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S132>/ki'
     *  Product: '<S132>/Multiply'
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

    /* End of Update for DiscreteIntegrator: '<S132>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S134>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_i += 0.002F * rtb_Gain_il;
    Controller_DW.DiscreteTimeIntegrator1_Prev_ks = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Signum: '<S109>/Sign3' incorporates:
     *  Product: '<S109>/Divide'
     *  Sum: '<S109>/Add6'
     */
    rtb_Abs = rtb_Gain_ms + Controller_ConstB.d;

    /* Signum: '<S109>/Sign4' incorporates:
     *  Product: '<S109>/Divide'
     *  Sum: '<S109>/Subtract3'
     */
    rtb_DiscreteTimeIntegrator1_md_ = rtb_Gain_ms - Controller_ConstB.d;

    /* Signum: '<S109>/Sign5' incorporates:
     *  Product: '<S109>/Divide'
     */
    if (rtb_Gain_ms < 0.0F) {
      rtb_DiscreteTimeIntegrator1_m_0 = -1.0F;
    } else if (rtb_Gain_ms > 0.0F) {
      rtb_DiscreteTimeIntegrator1_m_0 = 1.0F;
    } else {
      rtb_DiscreteTimeIntegrator1_m_0 = rtb_Gain_ms;
    }

    /* Signum: '<S109>/Sign3' */
    if (rtb_Abs < 0.0F) {
      rtb_Abs = -1.0F;
    } else {
      if (rtb_Abs > 0.0F) {
        rtb_Abs = 1.0F;
      }
    }

    /* Signum: '<S109>/Sign4' */
    if (rtb_DiscreteTimeIntegrator1_md_ < 0.0F) {
      rtb_DiscreteTimeIntegrator1_md_ = -1.0F;
    } else {
      if (rtb_DiscreteTimeIntegrator1_md_ > 0.0F) {
        rtb_DiscreteTimeIntegrator1_md_ = 1.0F;
      }
    }

    /* Signum: '<S109>/Sign6' incorporates:
     *  Product: '<S109>/Divide'
     */
    if (rtb_Gain_ms < 0.0F) {
      rtb_DiscreteTimeIntegrator1_m_1 = -1.0F;
    } else if (rtb_Gain_ms > 0.0F) {
      rtb_DiscreteTimeIntegrator1_m_1 = 1.0F;
    } else {
      rtb_DiscreteTimeIntegrator1_m_1 = rtb_Gain_ms;
    }

    /* Update for DiscreteIntegrator: '<S106>/Integrator' incorporates:
     *  Constant: '<S109>/const'
     *  Gain: '<S109>/Gain3'
     *  Product: '<S109>/Divide'
     *  Product: '<S109>/Multiply5'
     *  Product: '<S109>/Multiply6'
     *  Sum: '<S109>/Subtract4'
     *  Sum: '<S109>/Subtract5'
     *  Sum: '<S109>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE[0] += ((rtb_Gain_ms / Controller_ConstB.d -
      rtb_DiscreteTimeIntegrator1_m_0) * Controller_ConstB.Gain4 * ((rtb_Abs -
      rtb_DiscreteTimeIntegrator1_md_) * 0.5F) - rtb_DiscreteTimeIntegrator1_m_1
      * 58.836F) * 0.002F;

    /* Signum: '<S109>/Sign3' incorporates:
     *  Sum: '<S109>/Add6'
     */
    rtb_Abs = rtb_Gain_it + Controller_ConstB.d;

    /* Signum: '<S109>/Sign4' incorporates:
     *  Sum: '<S109>/Subtract3'
     */
    rtb_DiscreteTimeIntegrator1_md_ = rtb_Gain_it - Controller_ConstB.d;

    /* Signum: '<S109>/Sign5' */
    if (rtb_Gain_it < 0.0F) {
      rtb_DiscreteTimeIntegrator1_m_0 = -1.0F;
    } else if (rtb_Gain_it > 0.0F) {
      rtb_DiscreteTimeIntegrator1_m_0 = 1.0F;
    } else {
      rtb_DiscreteTimeIntegrator1_m_0 = rtb_Gain_it;
    }

    /* Signum: '<S109>/Sign3' */
    if (rtb_Abs < 0.0F) {
      rtb_Abs = -1.0F;
    } else {
      if (rtb_Abs > 0.0F) {
        rtb_Abs = 1.0F;
      }
    }

    /* Signum: '<S109>/Sign4' */
    if (rtb_DiscreteTimeIntegrator1_md_ < 0.0F) {
      rtb_DiscreteTimeIntegrator1_md_ = -1.0F;
    } else {
      if (rtb_DiscreteTimeIntegrator1_md_ > 0.0F) {
        rtb_DiscreteTimeIntegrator1_md_ = 1.0F;
      }
    }

    /* Signum: '<S109>/Sign6' */
    if (rtb_Gain_it < 0.0F) {
      rtb_DiscreteTimeIntegrator1_m_1 = -1.0F;
    } else if (rtb_Gain_it > 0.0F) {
      rtb_DiscreteTimeIntegrator1_m_1 = 1.0F;
    } else {
      rtb_DiscreteTimeIntegrator1_m_1 = rtb_Gain_it;
    }

    /* Update for DiscreteIntegrator: '<S106>/Integrator' incorporates:
     *  Constant: '<S109>/const'
     *  Gain: '<S109>/Gain3'
     *  Product: '<S109>/Divide'
     *  Product: '<S109>/Multiply5'
     *  Product: '<S109>/Multiply6'
     *  Sum: '<S109>/Subtract4'
     *  Sum: '<S109>/Subtract5'
     *  Sum: '<S109>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE[1] += ((rtb_Gain_it / Controller_ConstB.d -
      rtb_DiscreteTimeIntegrator1_m_0) * Controller_ConstB.Gain4 * ((rtb_Abs -
      rtb_DiscreteTimeIntegrator1_md_) * 0.5F) - rtb_DiscreteTimeIntegrator1_m_1
      * 58.836F) * 0.002F;

    /* Signum: '<S130>/Sign6' incorporates:
     *  Signum: '<S130>/Sign5'
     */
    if (rtb_Saturation_ov < 0.0F) {
      rtb_DiscreteTimeIntegrator1_m_0 = -1.0F;

      /* Signum: '<S130>/Sign5' */
      rtb_DiscreteTimeIntegrator1_m_1 = -1.0F;
    } else if (rtb_Saturation_ov > 0.0F) {
      rtb_DiscreteTimeIntegrator1_m_0 = 1.0F;

      /* Signum: '<S130>/Sign5' */
      rtb_DiscreteTimeIntegrator1_m_1 = 1.0F;
    } else {
      rtb_DiscreteTimeIntegrator1_m_0 = rtb_Saturation_ov;

      /* Signum: '<S130>/Sign5' */
      rtb_DiscreteTimeIntegrator1_m_1 = rtb_Saturation_ov;
    }

    /* End of Signum: '<S130>/Sign6' */

    /* Sum: '<S130>/Add6' */
    rtb_Abs = rtb_Saturation_ov + Controller_ConstB.d_i;

    /* Sum: '<S130>/Subtract3' */
    rtb_DiscreteTimeIntegrator1_md_ = rtb_Saturation_ov - Controller_ConstB.d_i;

    /* Signum: '<S130>/Sign3' */
    if (rtb_Abs < 0.0F) {
      rtb_Abs = -1.0F;
    } else {
      if (rtb_Abs > 0.0F) {
        rtb_Abs = 1.0F;
      }
    }

    /* End of Signum: '<S130>/Sign3' */

    /* Signum: '<S130>/Sign4' */
    if (rtb_DiscreteTimeIntegrator1_md_ < 0.0F) {
      rtb_DiscreteTimeIntegrator1_md_ = -1.0F;
    } else {
      if (rtb_DiscreteTimeIntegrator1_md_ > 0.0F) {
        rtb_DiscreteTimeIntegrator1_md_ = 1.0F;
      }
    }

    /* End of Signum: '<S130>/Sign4' */

    /* Update for DiscreteIntegrator: '<S129>/Integrator' incorporates:
     *  Constant: '<S130>/const'
     *  Gain: '<S130>/Gain3'
     *  Product: '<S130>/Divide'
     *  Product: '<S130>/Multiply5'
     *  Product: '<S130>/Multiply6'
     *  Sum: '<S130>/Subtract4'
     *  Sum: '<S130>/Subtract5'
     *  Sum: '<S130>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE_j += ((rtb_Saturation_ov /
      Controller_ConstB.d_i - rtb_DiscreteTimeIntegrator1_m_1) *
      Controller_ConstB.Gain4_p * ((rtb_Abs - rtb_DiscreteTimeIntegrator1_md_) *
      0.5F) - rtb_DiscreteTimeIntegrator1_m_0 * 78.448F) * 0.002F;

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
  /* Start for Constant: '<S177>/Constant' */
  Controller_B.Constant_m = CONTROL_PARAM.MC_VEL_Z_I_MIN;

  /* End of Start for SubSystem: '<S2>/VTOL_Controller' */

  /* Start for IfAction SubSystem: '<S2>/BackTrans_Controller' */
  /* Start for Constant: '<S57>/Constant' */
  Controller_B.Constant_i = CONTROL_PARAM.MC_VEL_Z_I_MIN;

  /* End of Start for SubSystem: '<S2>/BackTrans_Controller' */

  /* Start for IfAction SubSystem: '<S2>/MC_Controller' */
  /* Start for Constant: '<S132>/Constant' */
  Controller_B.Constant = CONTROL_PARAM.MC_VEL_Z_I_MIN;

  /* End of Start for SubSystem: '<S2>/MC_Controller' */

  /* SystemInitialize for IfAction SubSystem: '<S2>/VTOL_Controller' */
  /* InitializeConditions for DiscreteIntegrator: '<S182>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_L_eo = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S181>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_o = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S174>/Integrator1' */
  Controller_DW.Integrator1_DSTATE_i = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S177>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S177>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S179>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_i = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_h = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S217>/ ' */
  Controller_DW._DSTATE = Controller_ConstB.Zero1;
  if (Controller_DW._DSTATE >= CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
    Controller_DW._DSTATE = CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
  } else {
    if (Controller_DW._DSTATE <= -CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
      Controller_DW._DSTATE = -CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
    }
  }

  Controller_DW._PrevResetState = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S217>/ ' */

  /* InitializeConditions for DiscreteIntegrator: '<S218>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_f = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_b = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S150>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_b = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S152>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_PrevRe_o = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S154>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_L_h2 = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_l = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S180>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_g = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S152>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S192>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S152>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S192>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S152>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S192>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S220>/ ' */
  Controller_DW._DSTATE_d = Controller_ConstB.Zero;
  if (Controller_DW._DSTATE_d >= 0.3F) {
    Controller_DW._DSTATE_d = 0.3F;
  } else {
    if (Controller_DW._DSTATE_d <= -0.3F) {
      Controller_DW._DSTATE_d = -0.3F;
    }
  }

  Controller_DW._PrevResetState_e = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S220>/ ' */

  /* InitializeConditions for DiscreteIntegrator: '<S221>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_L_h0 = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_d = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S174>/Integrator' */
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
  /* InitializeConditions for DiscreteIntegrator: '<S84>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S84>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S106>/Integrator1' */
  Controller_DW.Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S111>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S106>/Integrator1' */
  Controller_DW.Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S111>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S113>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S82>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S86>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_k = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S129>/Integrator1' */
  Controller_DW.Integrator1_DSTATE_e = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S132>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S132>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S134>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 1U;
  Controller_DW.DiscreteTimeIntegrator1_Prev_ks = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S106>/Integrator' */
  Controller_DW.Integrator_DSTATE[0] = 0.0F;
  Controller_DW.Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S129>/Integrator' */
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
