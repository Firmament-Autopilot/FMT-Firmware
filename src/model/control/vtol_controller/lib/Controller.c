/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.141
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Aug  6 13:46:11 2024
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
  0.1F,
  0.1F,
  0.1F
} ;                                    /* Variable: CONTROL_PARAM
                                        * Referenced by:
                                        *   '<S80>/mc_hover_throttle'
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
                                        *   '<S40>/Saturation'
                                        *   '<S60>/hover_throttle'
                                        *   '<S128>/FF'
                                        *   '<S128>/FF_limit'
                                        *   '<S128>/PI_limit'
                                        *   '<S147>/P_control'
                                        *   '<S148>/P_control'
                                        *   '<S16>/Saturation'
                                        *   '<S16>/Saturation1'
                                        *   '<S49>/kd'
                                        *   '<S49>/Saturation'
                                        *   '<S50>/ki'
                                        *   '<S50>/Discrete-Time Integrator'
                                        *   '<S51>/kp'
                                        *   '<S70>/kd'
                                        *   '<S70>/Saturation'
                                        *   '<S71>/Constant'
                                        *   '<S71>/ki'
                                        *   '<S71>/Discrete-Time Integrator'
                                        *   '<S72>/kp'
                                        *   '<S85>/Saturation'
                                        *   '<S85>/Saturation1'
                                        *   '<S132>/trim_speed'
                                        *   '<S133>/trim_speed'
                                        *   '<S150>/Constant'
                                        *   '<S151>/Constant'
                                        *   '<S153>/Gain'
                                        *   '<S154>/ '
                                        *   '<S154>/Gain3'
                                        *   '<S156>/Gain'
                                        *   '<S157>/Gain'
                                        *   '<S159>/Constant'
                                        *   '<S33>/Constant1'
                                        *   '<S33>/Constant2'
                                        *   '<S97>/Constant1'
                                        *   '<S97>/Constant2'
                                        *   '<S118>/kd'
                                        *   '<S118>/Saturation'
                                        *   '<S119>/Constant'
                                        *   '<S119>/ki'
                                        *   '<S119>/Discrete-Time Integrator'
                                        *   '<S120>/kp'
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
                                        *   '<S166>/Constant1'
                                        *   '<S166>/Constant12'
                                        *   '<S166>/Constant2'
                                        *   '<S166>/Constant7'
                                        *   '<S22>/gain1'
                                        *   '<S22>/gain2'
                                        *   '<S22>/gain3'
                                        *   '<S22>/Saturation'
                                        *   '<S23>/gain1'
                                        *   '<S23>/gain2'
                                        *   '<S23>/gain3'
                                        *   '<S23>/Discrete-Time Integrator'
                                        *   '<S24>/gain1'
                                        *   '<S24>/gain2'
                                        *   '<S24>/gain3'
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
  VTOLState rtb_VTOL_State;
  int8_T rtPrevAction;
  uint8_T rtb_BitwiseAND;
  real32_T rtb_Divide_i;
  real32_T rtb_Saturation_j;
  int32_T rtb_Relay;
  real32_T rtb_Gain_ms;
  boolean_T rtb_LogicalOperator_b3;
  real32_T rtb_Gain_it;
  real32_T rtb_Saturation_lu;
  real32_T rtb_Vdot_errg;
  real32_T rtb_Abs;
  real32_T rtb_Switch_h;
  real32_T rtb_Vdotg;
  real32_T rtb_Minus;
  real32_T rtb_B_err;
  real32_T rtb_Gain_il;
  real32_T rtb_Multiply1;
  real32_T rtb_Subtract3_o;
  boolean_T rtb_LogicalOperator_m;
  real32_T rtb_VectorConcatenate[9];
  real32_T rtb_Sum;
  real32_T rtb_Saturation_c;
  real32_T rtb_Saturation_gg;
  real32_T rtb_MatrixConcatenate[12];
  real32_T rtb_boost_factor_o;
  uint16_T rtb_DataTypeConversion_k;
  real32_T rtb_Add_k;
  real32_T rtb_Add2_h;
  uint16_T rtb_MultiportSwitch_o[4];
  uint16_T rtb_MultiportSwitch[9];
  int32_T i;
  real32_T rtb_VectorConcatenate_0[3];
  real32_T tmp[4];
  real32_T rtb_Gain_a_idx_1;
  real32_T rtb_Gain_a_idx_2;
  real32_T rtb_att_error_B_rad_idx_0;
  real32_T rtb_att_error_B_rad_idx_1;
  real32_T rtb_rate_error_B_radPs_b_idx_1;
  real32_T rtb_rate_error_B_radPs_b_idx_2;
  real32_T rtb_rate_err_B_idx_2;
  real32_T rtb_rate_error_B_radPs_b_idx_0;
  real32_T rtb_Saturation1_h_idx_0;
  uint16_T u0;

  /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S7>/Divide'
   *  S-Function (sfix_bitop): '<S7>/Bitwise AND'
   */
  rtb_VTOL_State = (VTOLState)(uint8_T)((uint32_T)
    (Controller_U.FMS_Out.ctrl_mode & 192) >> 6);

  /* S-Function (sfix_bitop): '<S6>/Bitwise AND' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  rtb_BitwiseAND = (uint8_T)(Controller_U.FMS_Out.ctrl_mode & 63);

  /* SwitchCase: '<S7>/Switch Case1' incorporates:
   *  Constant: '<S119>/Constant'
   *  Constant: '<S71>/Constant'
   *  Product: '<S35>/Divide1'
   *  Product: '<S49>/Multiply'
   *  Product: '<S99>/Divide1'
   */
  rtPrevAction = Controller_DW.SwitchCase1_ActiveSubsystem;
  switch (rtb_VTOL_State) {
   case VTOLState_Fixwing:
   case VTOLState_BackTrans:
    Controller_DW.SwitchCase1_ActiveSubsystem = 0;
    break;

   default:
    Controller_DW.SwitchCase1_ActiveSubsystem = 1;
    break;
  }

  switch (Controller_DW.SwitchCase1_ActiveSubsystem) {
   case 0:
    if (Controller_DW.SwitchCase1_ActiveSubsystem != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S2>/VTOL_Controller' incorporates:
       *  ActionPort: '<S5>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S7>/Switch Case1' incorporates:
       *  DiscreteIntegrator: '<S116>/Integrator'
       *  DiscreteIntegrator: '<S116>/Integrator1'
       *  DiscreteIntegrator: '<S119>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S121>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S122>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S123>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S124>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S134>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S154>/ '
       *  DiscreteIntegrator: '<S155>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S157>/ '
       *  DiscreteIntegrator: '<S158>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S89>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S91>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S93>/Discrete-Time Integrator1'
       */
      Controller_DW.DiscreteTimeIntegrator5_IC_LO_e = 1U;
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
      Controller_DW.DiscreteTimeIntegrator1_IC_LO_h = 1U;
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

      /* SystemReset for IfAction SubSystem: '<S2>/VTOL_Controller' incorporates:
       *  ActionPort: '<S5>/Action Port'
       */
      /* SystemReset for Atomic SubSystem: '<S161>/VTOL1' */
      /* SystemReset for SwitchCase: '<S7>/Switch Case1' incorporates:
       *  Delay: '<S167>/Delay'
       */
      Controller_DW.Delay_DSTATE = 0U;

      /* End of SystemReset for SubSystem: '<S161>/VTOL1' */
      /* End of SystemReset for SubSystem: '<S2>/VTOL_Controller' */
    }

    /* Outputs for IfAction SubSystem: '<S2>/VTOL_Controller' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* Product: '<S75>/Divide' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Math: '<S75>/Square'
     */
    rtb_Divide_i = Controller_U.INS_Out.airspeed * Controller_U.INS_Out.airspeed
      / Controller_ConstB.Square1;

    /* DiscreteIntegrator: '<S124>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_e != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_a = rtb_Divide_i;
    }

    /* Saturate: '<S75>/Saturation' */
    if (Controller_DW.DiscreteTimeIntegrator5_DSTAT_a > 1.0F) {
      rtb_Saturation_j = 1.0F;
    } else if (Controller_DW.DiscreteTimeIntegrator5_DSTAT_a < 0.0F) {
      rtb_Saturation_j = 0.0F;
    } else {
      rtb_Saturation_j = Controller_DW.DiscreteTimeIntegrator5_DSTAT_a;
    }

    /* End of Saturate: '<S75>/Saturation' */

    /* Relay: '<S75>/Relay' */
    if (rtb_Saturation_j >= 0.95F) {
      Controller_DW.Relay_Mode = true;
    } else {
      if (rtb_Saturation_j <= 0.85F) {
        Controller_DW.Relay_Mode = false;
      }
    }

    rtb_Relay = !Controller_DW.Relay_Mode;

    /* End of Relay: '<S75>/Relay' */

    /* DiscreteIntegrator: '<S123>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_o != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTA_a2 = (real32_T)rtb_Relay;
    }

    /* Gain: '<S114>/Gain' incorporates:
     *  DiscreteIntegrator: '<S116>/Integrator1'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S114>/Sum1'
     */
    rtb_Gain_ms = -(Controller_DW.Integrator1_DSTATE_i - Controller_U.INS_Out.vd);

    /* Logic: '<S111>/Logical Operator' incorporates:
     *  Constant: '<S113>/Constant'
     *  DiscreteIntegrator: '<S123>/Discrete-Time Integrator5'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S113>/Compare'
     */
    rtb_LogicalOperator_b3 = ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator5_DSTA_a2 == 0.0F));
    Controller_B.Constant_m = CONTROL_PARAM.MC_VEL_Z_I_MIN;

    /* DiscreteIntegrator: '<S119>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S119>/Constant'
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

    /* DiscreteIntegrator: '<S121>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_i != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_l = rtb_Gain_ms;
    }

    if (rtb_LogicalOperator_b3 || (Controller_DW.DiscreteTimeIntegrator1_PrevR_h
         != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_l = rtb_Gain_ms;
    }

    /* Gain: '<S121>/Gain' incorporates:
     *  DiscreteIntegrator: '<S121>/Discrete-Time Integrator1'
     *  Sum: '<S121>/Sum5'
     */
    rtb_Gain_it = (rtb_Gain_ms - Controller_DW.DiscreteTimeIntegrator1_DSTAT_l) *
      62.831852F;

    /* Trigonometry: '<S126>/Atan' incorporates:
     *  Gain: '<S126>/g_force'
     *  Inport: '<Root>/FMS_Out'
     *  Sum: '<S126>/Minus'
     */
    rtb_Saturation_lu = atanf(0.101936802F * Controller_U.FMS_Out.ay_cmd);

    /* Saturate: '<S126>/Saturation' */
    if (rtb_Saturation_lu > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Saturation_lu = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_Saturation_lu < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_Saturation_lu = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      }
    }

    /* End of Saturate: '<S126>/Saturation' */

    /* Switch: '<S146>/Switch' incorporates:
     *  Constant: '<S152>/Constant'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S152>/Compare'
     */
    if (rtb_BitwiseAND == 4) {
      rtb_Multiply1 = Controller_U.FMS_Out.phi_cmd;
    } else {
      rtb_Multiply1 = rtb_Saturation_lu;
    }

    /* End of Switch: '<S146>/Switch' */

    /* Abs: '<S127>/Abs' */
    rtb_Abs = fabsf(rtb_Multiply1);

    /* Switch: '<S150>/Switch' incorporates:
     *  Constant: '<S150>/Constant'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S150>/Asin'
     */
    if (CONTROL_PARAM.FW_TECS_ANSW > 1.0F) {
      /* Product: '<S150>/Divide' incorporates:
       *  Gain: '<S150>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  Math: '<S150>/Square'
       *  Math: '<S150>/Square1'
       *  Math: '<S150>/Square2'
       *  Sqrt: '<S150>/Sqrt'
       *  Sum: '<S150>/Add'
       */
      rtb_Subtract3_o = 1.0F / sqrtf((Controller_U.INS_Out.vn *
        Controller_U.INS_Out.vn + Controller_U.INS_Out.ve *
        Controller_U.INS_Out.ve) + Controller_U.INS_Out.vd *
        Controller_U.INS_Out.vd) * -Controller_U.INS_Out.vd;

      /* Trigonometry: '<S150>/Asin' */
      if (rtb_Subtract3_o > 1.0F) {
        rtb_Subtract3_o = 1.0F;
      } else {
        if (rtb_Subtract3_o < -1.0F) {
          rtb_Subtract3_o = -1.0F;
        }
      }

      rtb_Switch_h = asinf(rtb_Subtract3_o);
    } else {
      rtb_Switch_h = Controller_U.INS_Out.theta;
    }

    /* End of Switch: '<S150>/Switch' */

    /* Gain: '<S149>/Gain1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Vdotg = 0.101936802F * Controller_U.INS_Out.ax;

    /* Switch: '<S151>/Switch' incorporates:
     *  Constant: '<S151>/Constant'
     *  Inport: '<Root>/INS_Out'
     *  Switch: '<S159>/Switch'
     */
    if (CONTROL_PARAM.FW_TECS_SWITCH > 1.0F) {
      /* Saturate: '<S151>/Saturation' incorporates:
       *  Inport: '<Root>/INS_Out'
       */
      if (Controller_U.INS_Out.airspeed > 100.0F) {
        rtb_Minus = 100.0F;
      } else if (Controller_U.INS_Out.airspeed < 0.1F) {
        rtb_Minus = 0.1F;
      } else {
        rtb_Minus = Controller_U.INS_Out.airspeed;
      }

      /* End of Saturate: '<S151>/Saturation' */
      rtb_Vdot_errg = Controller_U.INS_Out.airspeed;
    } else {
      /* Sqrt: '<S151>/Sqrt' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Math: '<S151>/Square'
       *  Math: '<S151>/Square1'
       *  Math: '<S151>/Square2'
       *  Sum: '<S151>/Add'
       */
      rtb_Minus = sqrtf((Controller_U.INS_Out.vn * Controller_U.INS_Out.vn +
                         Controller_U.INS_Out.ve * Controller_U.INS_Out.ve) +
                        Controller_U.INS_Out.vd * Controller_U.INS_Out.vd);

      /* Saturate: '<S151>/Saturation1' incorporates:
       *  Sqrt: '<S151>/Sqrt'
       */
      if (rtb_Minus > 100.0F) {
        rtb_Minus = 100.0F;
      } else {
        if (rtb_Minus < 0.01F) {
          rtb_Minus = 0.01F;
        }
      }

      /* End of Saturate: '<S151>/Saturation1' */

      /* Sqrt: '<S159>/Sqrt' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Math: '<S159>/Square'
       *  Math: '<S159>/Square1'
       *  Math: '<S159>/Square2'
       *  Sum: '<S159>/Add'
       */
      rtb_Vdot_errg = sqrtf((Controller_U.INS_Out.vn * Controller_U.INS_Out.vn +
        Controller_U.INS_Out.ve * Controller_U.INS_Out.ve) +
                            Controller_U.INS_Out.vd * Controller_U.INS_Out.vd);

      /* Saturate: '<S159>/Saturation' incorporates:
       *  Sqrt: '<S159>/Sqrt'
       */
      if (rtb_Vdot_errg > 100.0F) {
        rtb_Vdot_errg = 100.0F;
      } else {
        if (rtb_Vdot_errg < 0.01F) {
          rtb_Vdot_errg = 0.01F;
        }
      }

      /* End of Saturate: '<S159>/Saturation' */
    }

    /* End of Switch: '<S151>/Switch' */

    /* Sum: '<S145>/Minus' incorporates:
     *  Gain: '<S151>/Gain'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S151>/Divide'
     */
    rtb_Minus = -Controller_U.FMS_Out.w_cmd / rtb_Minus - rtb_Switch_h;

    /* Saturate: '<S149>/Saturation' */
    if (rtb_Vdot_errg > 100.0F) {
      rtb_Vdot_errg = 100.0F;
    } else {
      if (rtb_Vdot_errg < 0.1F) {
        rtb_Vdot_errg = 0.1F;
      }
    }

    /* End of Saturate: '<S149>/Saturation' */

    /* Sum: '<S149>/Minus' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    rtb_Vdot_errg = Controller_U.FMS_Out.u_cmd - rtb_Vdot_errg;

    /* Sum: '<S149>/Minus1' incorporates:
     *  Gain: '<S149>/Gain'
     */
    rtb_Vdot_errg = 0.101936802F * rtb_Vdot_errg - rtb_Vdotg;

    /* Sum: '<S127>/Minus1' incorporates:
     *  Gain: '<S127>/ucmd2pitch'
     *  Gain: '<S127>/wcmd2pitch'
     */
    rtb_B_err = CONTROL_PARAM.FW_TECS_W2P * rtb_Minus -
      CONTROL_PARAM.FW_TECS_U2P * rtb_Vdot_errg;

    /* DiscreteIntegrator: '<S154>/ ' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
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

    /* DiscreteIntegrator: '<S155>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_f != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_e = rtb_B_err;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_b != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_e = rtb_B_err;
    }

    /* Gain: '<S155>/Gain' incorporates:
     *  DiscreteIntegrator: '<S155>/Discrete-Time Integrator1'
     *  Sum: '<S155>/Sum5'
     */
    rtb_Gain_il = (rtb_B_err - Controller_DW.DiscreteTimeIntegrator1_DSTAT_e) *
      62.831852F;

    /* Switch: '<S155>/Switch' incorporates:
     *  Gain: '<S155>/Gain1'
     *  Inport: '<Root>/FMS_Out'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_Saturation_c = 0.0F;
    } else {
      rtb_Saturation_c = rtb_Gain_il;
    }

    /* End of Switch: '<S155>/Switch' */

    /* Gain: '<S153>/Gain' */
    rtb_Multiply1 = CONTROL_PARAM.FW_TECS_PITCH_D * rtb_Saturation_c;

    /* Saturate: '<S147>/Saturation1' */
    if (rtb_Multiply1 > 0.3F) {
      rtb_Multiply1 = 0.3F;
    } else {
      if (rtb_Multiply1 < -0.3F) {
        rtb_Multiply1 = -0.3F;
      }
    }

    /* End of Saturate: '<S147>/Saturation1' */

    /* Sum: '<S127>/Sum' incorporates:
     *  DiscreteIntegrator: '<S154>/ '
     *  Gain: '<S127>/Gain'
     *  Gain: '<S127>/balabnce_ratio2'
     *  Gain: '<S127>/pitch_ff'
     *  Gain: '<S147>/P_control'
     *  Sum: '<S127>/Add3'
     *  Sum: '<S127>/Minus'
     *  Sum: '<S147>/Add'
     */
    rtb_Sum = (((2.0F - CONTROL_PARAM.FW_TECS_RATIO) * rtb_Switch_h - rtb_Vdotg)
               * CONTROL_PARAM.FW_TECS_PITCH_F + ((CONTROL_PARAM.FW_TECS_PITCH_P
      * rtb_B_err + Controller_DW._DSTATE) + rtb_Multiply1)) +
      CONTROL_PARAM.FW_TECS_R2P * rtb_Abs;

    /* Switch: '<S102>/Switch1' incorporates:
     *  Constant: '<S105>/Constant'
     *  Constant: '<S106>/Constant'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S105>/Compare'
     *  RelationalOperator: '<S106>/Compare'
     *  Switch: '<S102>/Switch'
     */
    if (rtb_VTOL_State == VTOLState_BackTrans) {
      rtb_att_error_B_rad_idx_1 = Controller_U.FMS_Out.phi_cmd;
    } else if (rtb_BitwiseAND <= 4) {
      /* Switch: '<S102>/Switch' incorporates:
       *  Inport: '<Root>/FMS_Out'
       */
      rtb_att_error_B_rad_idx_1 = Controller_U.FMS_Out.phi_cmd;
    } else {
      rtb_att_error_B_rad_idx_1 = rtb_Saturation_lu;
    }

    /* End of Switch: '<S102>/Switch1' */

    /* Sum: '<S96>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_att_error_B_rad_idx_0 = rtb_att_error_B_rad_idx_1 -
      Controller_U.INS_Out.phi;

    /* Switch: '<S103>/Switch1' incorporates:
     *  Constant: '<S107>/Constant'
     *  Constant: '<S108>/Constant'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S107>/Compare'
     *  RelationalOperator: '<S108>/Compare'
     *  Switch: '<S103>/Switch'
     */
    if (rtb_VTOL_State == VTOLState_BackTrans) {
      rtb_att_error_B_rad_idx_1 = Controller_U.FMS_Out.theta_cmd;
    } else if (rtb_BitwiseAND <= 3) {
      /* Switch: '<S103>/Switch' incorporates:
       *  Inport: '<Root>/FMS_Out'
       */
      rtb_att_error_B_rad_idx_1 = Controller_U.FMS_Out.theta_cmd;
    } else {
      rtb_att_error_B_rad_idx_1 = rtb_Sum;
    }

    /* End of Switch: '<S103>/Switch1' */

    /* Sum: '<S96>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_att_error_B_rad_idx_1 -= Controller_U.INS_Out.theta;

    /* Product: '<S99>/Divide1' incorporates:
     *  Abs: '<S99>/Abs'
     *  Constant: '<S99>/const2'
     */
    rtb_Gain_a_idx_1 = fabsf(rtb_att_error_B_rad_idx_0) / 0.002F;

    /* Product: '<S99>/Divide' incorporates:
     *  Constant: '<S97>/Constant1'
     *  Constant: '<S99>/const1'
     *  Math: '<S99>/Square'
     *  SignalConversion: '<S99>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_Multiply1 = 9.5993F / (CONTROL_PARAM.MC_ROLL_P * CONTROL_PARAM.MC_ROLL_P);

    /* Signum: '<S99>/Sign' incorporates:
     *  Abs: '<S99>/Abs'
     */
    if (rtb_att_error_B_rad_idx_0 < 0.0F) {
      rtb_rate_err_B_idx_2 = -1.0F;
    } else if (rtb_att_error_B_rad_idx_0 > 0.0F) {
      rtb_rate_err_B_idx_2 = 1.0F;
    } else {
      rtb_rate_err_B_idx_2 = rtb_att_error_B_rad_idx_0;
    }

    /* Switch: '<S99>/Switch' incorporates:
     *  Abs: '<S99>/Abs'
     *  Constant: '<S97>/Constant1'
     *  Gain: '<S99>/Gain1'
     *  Gain: '<S99>/Gain2'
     *  Logic: '<S99>/Logical Operator'
     *  Product: '<S99>/Divide'
     *  Product: '<S99>/Multiply'
     *  Product: '<S99>/Multiply1'
     *  Product: '<S99>/Multiply2'
     *  Product: '<S99>/Multiply3'
     *  RelationalOperator: '<S99>/Relational Operator'
     *  RelationalOperator: '<S99>/Relational Operator2'
     *  SignalConversion: '<S99>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S99>/Sqrt'
     *  Sum: '<S99>/Subtract'
     */
    if ((rtb_att_error_B_rad_idx_0 <= rtb_Multiply1) &&
        (rtb_att_error_B_rad_idx_0 >= -rtb_Multiply1)) {
      rtb_rate_err_B_idx_2 = rtb_att_error_B_rad_idx_0 * CONTROL_PARAM.MC_ROLL_P;
    } else {
      rtb_rate_err_B_idx_2 *= sqrtf((rtb_rate_err_B_idx_2 *
        rtb_att_error_B_rad_idx_0 - 0.5F * rtb_Multiply1) *
        Controller_ConstB.Gain_n);
    }

    /* Gain: '<S99>/Gain3' */
    rtb_Multiply1 = -rtb_Gain_a_idx_1;

    /* Switch: '<S100>/Switch' incorporates:
     *  Gain: '<S99>/Gain3'
     *  RelationalOperator: '<S100>/UpperRelop'
     */
    if (rtb_rate_err_B_idx_2 >= -rtb_Gain_a_idx_1) {
      rtb_Multiply1 = rtb_rate_err_B_idx_2;
    }

    /* Switch: '<S100>/Switch2' incorporates:
     *  RelationalOperator: '<S100>/LowerRelop1'
     */
    if (rtb_rate_err_B_idx_2 <= rtb_Gain_a_idx_1) {
      rtb_Gain_a_idx_1 = rtb_Multiply1;
    }

    /* Saturate: '<S85>/Saturation1' */
    if (rtb_Gain_a_idx_1 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_Gain_a_idx_1 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_Gain_a_idx_1 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_Gain_a_idx_1 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    rtb_Saturation1_h_idx_0 = rtb_Gain_a_idx_1;

    /* Product: '<S99>/Divide1' incorporates:
     *  Abs: '<S99>/Abs'
     *  Constant: '<S99>/const2'
     */
    rtb_Gain_a_idx_1 = fabsf(rtb_att_error_B_rad_idx_1) / 0.002F;

    /* Product: '<S99>/Divide' incorporates:
     *  Constant: '<S97>/Constant2'
     *  Constant: '<S99>/const1'
     *  Math: '<S99>/Square'
     *  SignalConversion: '<S99>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_Multiply1 = 9.5993F / (CONTROL_PARAM.MC_PITCH_P *
      CONTROL_PARAM.MC_PITCH_P);

    /* Signum: '<S99>/Sign' incorporates:
     *  Abs: '<S99>/Abs'
     */
    if (rtb_att_error_B_rad_idx_1 < 0.0F) {
      rtb_rate_err_B_idx_2 = -1.0F;
    } else if (rtb_att_error_B_rad_idx_1 > 0.0F) {
      rtb_rate_err_B_idx_2 = 1.0F;
    } else {
      rtb_rate_err_B_idx_2 = rtb_att_error_B_rad_idx_1;
    }

    /* Switch: '<S99>/Switch' incorporates:
     *  Abs: '<S99>/Abs'
     *  Constant: '<S97>/Constant2'
     *  Gain: '<S99>/Gain1'
     *  Gain: '<S99>/Gain2'
     *  Logic: '<S99>/Logical Operator'
     *  Product: '<S99>/Divide'
     *  Product: '<S99>/Multiply'
     *  Product: '<S99>/Multiply1'
     *  Product: '<S99>/Multiply2'
     *  Product: '<S99>/Multiply3'
     *  RelationalOperator: '<S99>/Relational Operator'
     *  RelationalOperator: '<S99>/Relational Operator2'
     *  SignalConversion: '<S99>/TmpSignal ConversionAtSquareInport1'
     *  Sqrt: '<S99>/Sqrt'
     *  Sum: '<S99>/Subtract'
     */
    if ((rtb_att_error_B_rad_idx_1 <= rtb_Multiply1) &&
        (rtb_att_error_B_rad_idx_1 >= -rtb_Multiply1)) {
      rtb_rate_err_B_idx_2 = rtb_att_error_B_rad_idx_1 *
        CONTROL_PARAM.MC_PITCH_P;
    } else {
      rtb_rate_err_B_idx_2 *= sqrtf((rtb_rate_err_B_idx_2 *
        rtb_att_error_B_rad_idx_1 - 0.5F * rtb_Multiply1) *
        Controller_ConstB.Gain_n);
    }

    /* Gain: '<S99>/Gain3' */
    rtb_Multiply1 = -rtb_Gain_a_idx_1;

    /* Switch: '<S100>/Switch' incorporates:
     *  Gain: '<S99>/Gain3'
     *  RelationalOperator: '<S100>/UpperRelop'
     */
    if (rtb_rate_err_B_idx_2 >= -rtb_Gain_a_idx_1) {
      rtb_Multiply1 = rtb_rate_err_B_idx_2;
    }

    /* Switch: '<S100>/Switch2' incorporates:
     *  RelationalOperator: '<S100>/LowerRelop1'
     */
    if (rtb_rate_err_B_idx_2 <= rtb_Gain_a_idx_1) {
      rtb_Gain_a_idx_1 = rtb_Multiply1;
    }

    /* Saturate: '<S85>/Saturation1' */
    if (rtb_Gain_a_idx_1 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_Gain_a_idx_1 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_Gain_a_idx_1 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_Gain_a_idx_1 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    /* Saturate: '<S85>/Saturation' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    if (Controller_U.FMS_Out.psi_rate_cmd > CONTROL_PARAM.MC_R_CMD_LIM) {
      rtb_Multiply1 = CONTROL_PARAM.MC_R_CMD_LIM;
    } else if (Controller_U.FMS_Out.psi_rate_cmd < -CONTROL_PARAM.MC_R_CMD_LIM)
    {
      rtb_Multiply1 = -CONTROL_PARAM.MC_R_CMD_LIM;
    } else {
      rtb_Multiply1 = Controller_U.FMS_Out.psi_rate_cmd;
    }

    /* End of Saturate: '<S85>/Saturation' */

    /* Trigonometry: '<S94>/Sin' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S130>/Sin'
     */
    rtb_rate_err_B_idx_2 = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S94>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S130>/Cos1'
     */
    rtb_att_error_B_rad_idx_0 = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Trigonometry: '<S94>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S130>/Cos'
     */
    rtb_Saturation_c = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S94>/Sin1' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S130>/Sin1'
     */
    rtb_att_error_B_rad_idx_1 = arm_sin_f32(Controller_U.INS_Out.theta);

    /* Sum: '<S86>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S94>/Multiply'
     *  Product: '<S94>/Multiply1'
     *  Product: '<S94>/Multiply3'
     *  Product: '<S94>/Multiply4'
     *  Product: '<S94>/Multiply5'
     *  Sum: '<S94>/Add'
     *  Sum: '<S94>/Add1'
     *  Sum: '<S94>/Add2'
     *  Trigonometry: '<S94>/Cos'
     *  Trigonometry: '<S94>/Cos1'
     *  Trigonometry: '<S94>/Sin'
     *  Trigonometry: '<S94>/Sin1'
     */
    rtb_rate_error_B_radPs_b_idx_0 = (rtb_Saturation1_h_idx_0 -
      rtb_att_error_B_rad_idx_1 * rtb_Multiply1) - Controller_U.INS_Out.p;
    rtb_rate_error_B_radPs_b_idx_1 = (rtb_rate_err_B_idx_2 *
      rtb_att_error_B_rad_idx_0 * rtb_Multiply1 + rtb_Saturation_c *
      rtb_Gain_a_idx_1) - Controller_U.INS_Out.q;
    rtb_rate_error_B_radPs_b_idx_2 = (rtb_Saturation_c *
      rtb_att_error_B_rad_idx_0 * rtb_Multiply1 - rtb_rate_err_B_idx_2 *
      rtb_Gain_a_idx_1) - Controller_U.INS_Out.r;

    /* DiscreteIntegrator: '<S89>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_b != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0] =
        rtb_rate_error_B_radPs_b_idx_0;
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1] =
        rtb_rate_error_B_radPs_b_idx_1;
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2] =
        rtb_rate_error_B_radPs_b_idx_2;
    }

    /* Logic: '<S81>/Logical Operator' incorporates:
     *  Constant: '<S83>/Constant'
     *  DiscreteIntegrator: '<S123>/Discrete-Time Integrator5'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S83>/Compare'
     */
    rtb_LogicalOperator_m = ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator5_DSTA_a2 == 0.0F));

    /* DiscreteIntegrator: '<S91>/Discrete-Time Integrator' */
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

    /* DiscreteIntegrator: '<S93>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S89>/Discrete-Time Integrator5'
     */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_h != 0) {
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

    /* Gain: '<S93>/Gain' incorporates:
     *  DiscreteIntegrator: '<S89>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S93>/Discrete-Time Integrator1'
     *  Sum: '<S93>/Sum5'
     */
    rtb_Multiply1 = (Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0] -
                     Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[0]) *
      188.49556F;
    rtb_Gain_a_idx_1 = (Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1] -
                        Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[1]) *
      188.49556F;
    rtb_Gain_a_idx_2 = (Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2] -
                        Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[2]) *
      188.49556F;

    /* DiscreteIntegrator: '<S122>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_g != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j = rtb_Saturation_j;
    }

    /* Switch: '<S138>/Switch' incorporates:
     *  Inport: '<Root>/FMS_Out'
     *  Logic: '<S138>/Logical Operator'
     *  RelationalOperator: '<S143>/Compare'
     */
    if ((rtb_BitwiseAND == 3) || (rtb_BitwiseAND == 4)) {
      rtb_Saturation_lu = Controller_U.FMS_Out.phi_cmd;
    }

    /* End of Switch: '<S138>/Switch' */

    /* Switch: '<S138>/Switch1' incorporates:
     *  Constant: '<S144>/Constant'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S144>/Compare'
     */
    if (rtb_BitwiseAND == 3) {
      rtb_Sum = Controller_U.FMS_Out.theta_cmd;
    }

    /* End of Switch: '<S138>/Switch1' */

    /* Bias: '<S139>/Pitch Offset' */
    rtb_Subtract3_o = rtb_Sum + CONTROL_PARAM.FW_PITCH_OFFSET;

    /* Saturate: '<S139>/Saturation' */
    if (rtb_Subtract3_o > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Subtract3_o = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_Subtract3_o < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_Subtract3_o = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      }
    }

    /* Product: '<S140>/Multiply' incorporates:
     *  Constant: '<S140>/Constant2'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S139>/Sum'
     */
    rtb_Sum = (rtb_Subtract3_o - Controller_U.INS_Out.theta) *
      CONTROL_PARAM.FW_PITCH_P;

    /* Product: '<S142>/Divide' incorporates:
     *  Constant: '<S142>/Constant'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Subtract3_o = 9.81F / Controller_U.INS_Out.airspeed;

    /* Saturate: '<S142>/Saturation' */
    if (rtb_Subtract3_o > 1.0F) {
      rtb_Subtract3_o = 1.0F;
    } else {
      if (rtb_Subtract3_o < 0.0F) {
        rtb_Subtract3_o = 0.0F;
      }
    }

    /* End of Saturate: '<S142>/Saturation' */

    /* Sum: '<S137>/Sum' incorporates:
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S142>/Multiply'
     *  Product: '<S142>/Multiply1'
     *  Trigonometry: '<S142>/Cos'
     *  Trigonometry: '<S142>/Tan'
     */
    rtb_Subtract3_o = tanf(Controller_U.FMS_Out.phi_cmd) * arm_cos_f32
      (Controller_U.FMS_Out.theta_cmd) * rtb_Subtract3_o +
      Controller_U.FMS_Out.psi_rate_cmd;

    /* Saturate: '<S139>/Saturation' */
    if (rtb_Saturation_lu > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Saturation_lu = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_Saturation_lu < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_Saturation_lu = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      }
    }

    /* Sum: '<S130>/Add' incorporates:
     *  Constant: '<S140>/Constant1'
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S130>/Multiply'
     *  Product: '<S140>/Multiply'
     *  Sum: '<S139>/Sum'
     */
    rtb_Add_k = (rtb_Saturation_lu - Controller_U.INS_Out.phi) *
      CONTROL_PARAM.FW_ROLL_P - rtb_att_error_B_rad_idx_1 * rtb_Subtract3_o;

    /* Sum: '<S130>/Add1' incorporates:
     *  Product: '<S130>/Multiply1'
     *  Product: '<S130>/Multiply3'
     */
    rtb_att_error_B_rad_idx_1 = rtb_rate_err_B_idx_2 * rtb_att_error_B_rad_idx_0
      * rtb_Subtract3_o + rtb_Saturation_c * rtb_Sum;

    /* Sum: '<S130>/Add2' incorporates:
     *  Product: '<S130>/Multiply4'
     *  Product: '<S130>/Multiply5'
     */
    rtb_Add2_h = rtb_Saturation_c * rtb_att_error_B_rad_idx_0 * rtb_Subtract3_o
      - rtb_rate_err_B_idx_2 * rtb_Sum;

    /* Sum: '<S128>/Minus2' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Sum = rtb_Add_k - Controller_U.INS_Out.p;
    rtb_Saturation_lu = rtb_att_error_B_rad_idx_1 - Controller_U.INS_Out.q;
    rtb_rate_err_B_idx_2 = rtb_Add2_h - Controller_U.INS_Out.r;

    /* DiscreteIntegrator: '<S134>/Discrete-Time Integrator' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
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

    /* Sum: '<S127>/Add' incorporates:
     *  Gain: '<S127>/ucmd2thor'
     *  Gain: '<S127>/wcmd2thor'
     */
    rtb_Saturation1_h_idx_0 = CONTROL_PARAM.FW_TECS_W2T * rtb_Minus +
      CONTROL_PARAM.FW_TECS_U2T * rtb_Vdot_errg;

    /* DiscreteIntegrator: '<S157>/ ' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
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

    /* DiscreteIntegrator: '<S158>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_L_h0 != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm = rtb_Saturation1_h_idx_0;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_d != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm = rtb_Saturation1_h_idx_0;
    }

    /* Gain: '<S158>/Gain' incorporates:
     *  DiscreteIntegrator: '<S158>/Discrete-Time Integrator1'
     *  Sum: '<S158>/Sum5'
     */
    rtb_att_error_B_rad_idx_0 = (rtb_Saturation1_h_idx_0 -
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm) * 188.49556F;

    /* Outputs for Atomic SubSystem: '<S161>/VTOL1' */
    /* Switch: '<S167>/Switch1' incorporates:
     *  Constant: '<S169>/Constant'
     *  Constant: '<S170>/Constant'
     *  Delay: '<S167>/Delay'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S169>/Compare'
     *  RelationalOperator: '<S170>/Compare'
     *  Saturate: '<S167>/Saturation'
     *  Switch: '<S158>/Switch'
     *  Switch: '<S167>/Switch'
     */
    if (rtb_VTOL_State == VTOLState_BackTrans) {
      /* Sum: '<S167>/Sum' incorporates:
       *  Delay: '<S167>/Delay'
       */
      rtb_Subtract3_o = (real32_T)Controller_DW.Delay_DSTATE -
        Controller_ConstB.dT;

      /* Saturate: '<S167>/Saturation' */
      if (rtb_Subtract3_o > 2000.0F) {
        rtb_Subtract3_o = 2000.0F;
      } else {
        if (rtb_Subtract3_o < 1000.0F) {
          rtb_Subtract3_o = 1000.0F;
        }
      }

      Controller_DW.Delay_DSTATE = (uint16_T)fmodf(floorf(rtb_Subtract3_o),
        65536.0F);
    } else if (rtb_BitwiseAND <= 3) {
      /* Delay: '<S167>/Delay' incorporates:
       *  Inport: '<Root>/FMS_Out'
       *  Switch: '<S167>/Switch'
       */
      Controller_DW.Delay_DSTATE = Controller_U.FMS_Out.throttle_cmd;
    } else {
      if (Controller_U.FMS_Out.reset > 0) {
        /* Switch: '<S158>/Switch' incorporates:
         *  Gain: '<S158>/Gain1'
         *  Switch: '<S167>/Switch'
         */
        rtb_Saturation_c = 0.0F;
      } else {
        /* Switch: '<S158>/Switch' incorporates:
         *  Switch: '<S167>/Switch'
         */
        rtb_Saturation_c = rtb_att_error_B_rad_idx_0;
      }

      /* Gain: '<S156>/Gain' incorporates:
       *  Switch: '<S167>/Switch'
       */
      rtb_Subtract3_o = CONTROL_PARAM.FW_TECS_THOR_D * rtb_Saturation_c;

      /* Saturate: '<S148>/Saturation1' incorporates:
       *  Switch: '<S167>/Switch'
       */
      if (rtb_Subtract3_o > 0.3F) {
        rtb_Subtract3_o = 0.3F;
      } else {
        if (rtb_Subtract3_o < -0.3F) {
          rtb_Subtract3_o = -0.3F;
        }
      }

      /* End of Saturate: '<S148>/Saturation1' */

      /* Saturate: '<S76>/Saturation2' incorporates:
       *  Constant: '<S76>/cruise_throttle'
       *  DiscreteIntegrator: '<S157>/ '
       *  Gain: '<S127>/Gain1'
       *  Gain: '<S127>/balance_ratio'
       *  Gain: '<S127>/thorttle_ff'
       *  Gain: '<S148>/P_control'
       *  Saturate: '<S76>/Saturation'
       *  Sum: '<S127>/Add1'
       *  Sum: '<S127>/Add2'
       *  Sum: '<S127>/Sum1'
       *  Sum: '<S148>/Add4'
       *  Sum: '<S76>/Sum'
       *  Switch: '<S167>/Switch'
       */
      rtb_Subtract3_o = ((((CONTROL_PARAM.FW_TECS_THOR_P *
                            rtb_Saturation1_h_idx_0 + Controller_DW._DSTATE_d) +
                           rtb_Subtract3_o) + (CONTROL_PARAM.FW_TECS_RATIO *
        rtb_Vdotg + rtb_Switch_h) * CONTROL_PARAM.FW_TECS_THOR_FF) +
                         CONTROL_PARAM.FW_TECS_R2T * rtb_Abs) + 0.5F;
      if (rtb_Subtract3_o > 1.0F) {
        rtb_Subtract3_o = 1.0F;
      } else {
        if (rtb_Subtract3_o < -1.0F) {
          rtb_Subtract3_o = -1.0F;
        }
      }

      /* Saturate: '<S168>/Saturation' incorporates:
       *  Saturate: '<S76>/Saturation2'
       *  Switch: '<S167>/Switch'
       */
      if (rtb_Subtract3_o < 0.0F) {
        rtb_Subtract3_o = 0.0F;
      }

      /* End of Saturate: '<S168>/Saturation' */

      /* Delay: '<S167>/Delay' incorporates:
       *  Constant: '<S168>/Constant1'
       *  DataTypeConversion: '<S168>/Data Type Conversion'
       *  Gain: '<S168>/Gain1'
       *  Sum: '<S168>/Sum1'
       *  Switch: '<S167>/Switch'
       */
      Controller_DW.Delay_DSTATE = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
        rtb_Subtract3_o), 4.2949673E+9F) + 1000U);
    }

    /* End of Switch: '<S167>/Switch1' */

    /* MultiPortSwitch: '<S165>/Multiport Switch' incorporates:
     *  Constant: '<S165>/Disarm'
     *  Constant: '<S165>/Standby'
     *  Constant: '<S166>/Constant1'
     *  Constant: '<S166>/Constant12'
     *  Constant: '<S166>/Constant2'
     *  Constant: '<S166>/Constant7'
     *  Delay: '<S167>/Delay'
     *  Inport: '<Root>/FMS_Out'
     */
    switch (Controller_U.FMS_Out.status) {
     case 1:
      for (i = 0; i < 9; i++) {
        rtb_MultiportSwitch[i] = Controller_ConstP.Disarm_Value[i];
      }
      break;

     case 2:
      for (i = 0; i < 9; i++) {
        rtb_MultiportSwitch[i] = Controller_ConstP.Standby_Value[i];
      }
      break;

     case 3:
      /* Saturate: '<S128>/Saturation1' incorporates:
       *  Inport: '<Root>/INS_Out'
       */
      if (Controller_U.INS_Out.airspeed > 999.0F) {
        rtb_Saturation_c = 999.0F;
      } else if (Controller_U.INS_Out.airspeed < 0.1F) {
        rtb_Saturation_c = 0.1F;
      } else {
        rtb_Saturation_c = Controller_U.INS_Out.airspeed;
      }

      /* End of Saturate: '<S128>/Saturation1' */

      /* Product: '<S132>/Divide' incorporates:
       *  Constant: '<S132>/trim_speed'
       *  Math: '<S132>/Square'
       *  Math: '<S132>/Square1'
       */
      rtb_Saturation_gg = CONTROL_PARAM.FW_AIRSPEED_TRIM *
        CONTROL_PARAM.FW_AIRSPEED_TRIM / (rtb_Saturation_c * rtb_Saturation_c);

      /* Saturate: '<S132>/Saturation' */
      if (rtb_Saturation_gg > 1.0F) {
        rtb_Saturation_gg = 1.0F;
      } else {
        if (rtb_Saturation_gg < 0.0F) {
          rtb_Saturation_gg = 0.0F;
        }
      }

      /* End of Saturate: '<S132>/Saturation' */

      /* Product: '<S133>/Divide' incorporates:
       *  Constant: '<S133>/trim_speed'
       */
      rtb_Saturation_c = CONTROL_PARAM.FW_AIRSPEED_TRIM / rtb_Saturation_c;

      /* Saturate: '<S133>/Saturation' */
      if (rtb_Saturation_c > 1.0F) {
        rtb_Saturation_c = 1.0F;
      } else {
        if (rtb_Saturation_c < 0.0F) {
          rtb_Saturation_c = 0.0F;
        }
      }

      /* End of Saturate: '<S133>/Saturation' */

      /* Product: '<S128>/Multiply1' incorporates:
       *  Gain: '<S128>/FF'
       */
      rtb_Subtract3_o = CONTROL_PARAM.FW_FF * rtb_Add_k * rtb_Saturation_c;

      /* Product: '<S128>/Multiply' incorporates:
       *  Constant: '<S135>/gain1'
       *  DiscreteIntegrator: '<S134>/Discrete-Time Integrator'
       *  Product: '<S135>/Multiply'
       *  Sum: '<S131>/Add1'
       */
      rtb_Abs = (CONTROL_PARAM.FW_ROLL_RATE_P * rtb_Sum +
                 Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0]) *
        rtb_Saturation_gg;

      /* Product: '<S128>/Multiply1' incorporates:
       *  Gain: '<S128>/FF'
       */
      rtb_Switch_h = CONTROL_PARAM.FW_FF * rtb_att_error_B_rad_idx_1 *
        rtb_Saturation_c;

      /* Product: '<S128>/Multiply' incorporates:
       *  Constant: '<S135>/gain2'
       *  DiscreteIntegrator: '<S134>/Discrete-Time Integrator'
       *  Product: '<S135>/Multiply'
       *  Sum: '<S131>/Add1'
       */
      rtb_att_error_B_rad_idx_1 = (CONTROL_PARAM.FW_PITCH_RATE_P *
        rtb_Saturation_lu + Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1]) *
        rtb_Saturation_gg;

      /* Product: '<S128>/Multiply1' incorporates:
       *  Gain: '<S128>/FF'
       */
      rtb_Vdotg = CONTROL_PARAM.FW_FF * rtb_Add2_h * rtb_Saturation_c;

      /* Product: '<S128>/Multiply' incorporates:
       *  Constant: '<S135>/gain3'
       *  DiscreteIntegrator: '<S134>/Discrete-Time Integrator'
       *  Product: '<S135>/Multiply'
       *  Sum: '<S131>/Add1'
       */
      rtb_Minus = (CONTROL_PARAM.FW_YAW_RATE_P * rtb_rate_err_B_idx_2 +
                   Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2]) *
        rtb_Saturation_gg;
      rtb_MatrixConcatenate[11] = CONTROL_PARAM.FW_YAW_EFFC;

      /* SignalConversion: '<S166>/ConcatBufferAtVector Concatenate2In3' incorporates:
       *  Constant: '<S166>/Constant11'
       *  Constant: '<S166>/Constant12'
       */
      rtb_MatrixConcatenate[10] = 0.0F;

      /* SignalConversion: '<S166>/ConcatBufferAtVector Concatenate2In2' incorporates:
       *  Constant: '<S166>/Constant10'
       */
      rtb_MatrixConcatenate[9] = 0.0F;

      /* SignalConversion: '<S166>/ConcatBufferAtVector Concatenate2In1' incorporates:
       *  Constant: '<S166>/Constant9'
       */
      rtb_MatrixConcatenate[8] = 0.0F;

      /* SignalConversion: '<S166>/ConcatBufferAtVector Concatenate1In4' incorporates:
       *  Constant: '<S166>/Constant8'
       */
      rtb_MatrixConcatenate[7] = 0.0F;
      rtb_MatrixConcatenate[6] = CONTROL_PARAM.FW_PITCH_EFFC;

      /* SignalConversion: '<S166>/ConcatBufferAtVector Concatenate1In2' incorporates:
       *  Constant: '<S166>/Constant6'
       *  Constant: '<S166>/Constant7'
       */
      rtb_MatrixConcatenate[5] = 0.0F;

      /* SignalConversion: '<S166>/ConcatBufferAtVector Concatenate1In1' incorporates:
       *  Constant: '<S166>/Constant5'
       */
      rtb_MatrixConcatenate[4] = 0.0F;

      /* SignalConversion: '<S166>/ConcatBufferAtVector ConcatenateIn4' incorporates:
       *  Constant: '<S166>/Constant4'
       */
      rtb_MatrixConcatenate[3] = 0.0F;

      /* SignalConversion: '<S166>/ConcatBufferAtVector ConcatenateIn3' incorporates:
       *  Constant: '<S166>/Constant3'
       */
      rtb_MatrixConcatenate[2] = 0.0F;
      rtb_MatrixConcatenate[1] = CONTROL_PARAM.FW_ROLL_EFFC;
      rtb_MatrixConcatenate[0] = CONTROL_PARAM.FW_ROLL_EFFC;

      /* Switch: '<S93>/Switch' incorporates:
       *  Constant: '<S166>/Constant1'
       *  Constant: '<S166>/Constant2'
       *  Gain: '<S93>/Gain1'
       */
      if (rtb_LogicalOperator_m) {
        rtb_Vdot_errg = 0.0F;
        rtb_Add_k = 0.0F;
        rtb_Saturation_c = 0.0F;
      } else {
        rtb_Vdot_errg = rtb_Multiply1;
        rtb_Add_k = rtb_Gain_a_idx_1;
        rtb_Saturation_c = rtb_Gain_a_idx_2;
      }

      /* End of Switch: '<S93>/Switch' */

      /* Product: '<S90>/Multiply' incorporates:
       *  Constant: '<S90>/gain1'
       */
      rtb_Add2_h = CONTROL_PARAM.MC_ROLL_RATE_D * rtb_Vdot_errg;

      /* Saturate: '<S90>/Saturation' */
      if (rtb_Add2_h > CONTROL_PARAM.MC_RATE_D_MAX) {
        rtb_Add2_h = CONTROL_PARAM.MC_RATE_D_MAX;
      } else {
        if (rtb_Add2_h < CONTROL_PARAM.MC_RATE_D_MIN) {
          rtb_Add2_h = CONTROL_PARAM.MC_RATE_D_MIN;
        }
      }

      /* Saturate: '<S74>/Saturation2' incorporates:
       *  Constant: '<S92>/gain1'
       *  DiscreteIntegrator: '<S123>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S89>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S91>/Discrete-Time Integrator'
       *  Product: '<S74>/Multiply2'
       *  Product: '<S92>/Multiply'
       *  Sum: '<S87>/Add'
       */
      rtb_Vdot_errg = ((CONTROL_PARAM.MC_ROLL_RATE_P *
                        Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0] +
                        Controller_DW.DiscreteTimeIntegrator_DSTATE_d[0]) +
                       rtb_Add2_h) *
        Controller_DW.DiscreteTimeIntegrator5_DSTA_a2;
      if (rtb_Vdot_errg > 1.0F) {
        rtb_Vdot_errg = 1.0F;
      } else {
        if (rtb_Vdot_errg < -1.0F) {
          rtb_Vdot_errg = -1.0F;
        }
      }

      /* Product: '<S90>/Multiply' incorporates:
       *  Constant: '<S90>/gain2'
       */
      rtb_Add2_h = CONTROL_PARAM.MC_PITCH_RATE_D * rtb_Add_k;

      /* Saturate: '<S90>/Saturation' */
      if (rtb_Add2_h > CONTROL_PARAM.MC_RATE_D_MAX) {
        rtb_Add2_h = CONTROL_PARAM.MC_RATE_D_MAX;
      } else {
        if (rtb_Add2_h < CONTROL_PARAM.MC_RATE_D_MIN) {
          rtb_Add2_h = CONTROL_PARAM.MC_RATE_D_MIN;
        }
      }

      /* Saturate: '<S74>/Saturation2' incorporates:
       *  Constant: '<S92>/gain2'
       *  DiscreteIntegrator: '<S123>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S89>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S91>/Discrete-Time Integrator'
       *  Product: '<S74>/Multiply2'
       *  Product: '<S92>/Multiply'
       *  Sum: '<S87>/Add'
       */
      rtb_Add_k = ((CONTROL_PARAM.MC_PITCH_RATE_P *
                    Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1] +
                    Controller_DW.DiscreteTimeIntegrator_DSTATE_d[1]) +
                   rtb_Add2_h) * Controller_DW.DiscreteTimeIntegrator5_DSTA_a2;
      if (rtb_Add_k > 1.0F) {
        rtb_Add_k = 1.0F;
      } else {
        if (rtb_Add_k < -1.0F) {
          rtb_Add_k = -1.0F;
        }
      }

      /* Product: '<S90>/Multiply' incorporates:
       *  Constant: '<S90>/gain3'
       */
      rtb_Add2_h = CONTROL_PARAM.MC_YAW_RATE_D * rtb_Saturation_c;

      /* Saturate: '<S90>/Saturation' */
      if (rtb_Add2_h > CONTROL_PARAM.MC_RATE_D_MAX) {
        rtb_Add2_h = CONTROL_PARAM.MC_RATE_D_MAX;
      } else {
        if (rtb_Add2_h < CONTROL_PARAM.MC_RATE_D_MIN) {
          rtb_Add2_h = CONTROL_PARAM.MC_RATE_D_MIN;
        }
      }

      /* Saturate: '<S74>/Saturation2' incorporates:
       *  Constant: '<S92>/gain3'
       *  DiscreteIntegrator: '<S123>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S89>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S91>/Discrete-Time Integrator'
       *  Product: '<S74>/Multiply2'
       *  Product: '<S92>/Multiply'
       *  Sum: '<S87>/Add'
       */
      rtb_Add2_h = ((CONTROL_PARAM.MC_YAW_RATE_P *
                     Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2] +
                     Controller_DW.DiscreteTimeIntegrator_DSTATE_d[2]) +
                    rtb_Add2_h) * Controller_DW.DiscreteTimeIntegrator5_DSTA_a2;
      if (rtb_Add2_h > 1.0F) {
        rtb_Add2_h = 1.0F;
      } else {
        if (rtb_Add2_h < -1.0F) {
          rtb_Add2_h = -1.0F;
        }
      }

      /* Product: '<S112>/Multiply' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S112>/Cos'
       *  Trigonometry: '<S112>/Cos1'
       */
      rtb_Saturation_c = arm_cos_f32(Controller_U.INS_Out.phi) * arm_cos_f32
        (Controller_U.INS_Out.theta);

      /* Gain: '<S112>/Gain' */
      rtb_Saturation_gg = 2.0F * rtb_Saturation_c;

      /* Saturate: '<S112>/Saturation1' */
      if (rtb_Saturation_c > 1.0F) {
        rtb_Saturation_c = 1.0F;
      } else {
        if (rtb_Saturation_c < 0.5F) {
          rtb_Saturation_c = 0.5F;
        }
      }

      /* End of Saturate: '<S112>/Saturation1' */

      /* Product: '<S112>/Divide' incorporates:
       *  Constant: '<S112>/Constant'
       */
      rtb_boost_factor_o = 1.0F / rtb_Saturation_c;

      /* Switch: '<S121>/Switch' incorporates:
       *  Gain: '<S121>/Gain1'
       */
      if (rtb_LogicalOperator_b3) {
        rtb_Saturation_c = 0.0F;
      } else {
        rtb_Saturation_c = rtb_Gain_it;
      }

      /* End of Switch: '<S121>/Switch' */

      /* Product: '<S118>/Multiply' incorporates:
       *  Constant: '<S118>/kd'
       */
      rtb_Saturation_c *= CONTROL_PARAM.MC_VEL_Z_D;

      /* Saturate: '<S118>/Saturation' */
      if (rtb_Saturation_c > CONTROL_PARAM.MC_VEL_Z_D_MAX) {
        rtb_Saturation_c = CONTROL_PARAM.MC_VEL_Z_D_MAX;
      } else {
        if (rtb_Saturation_c < CONTROL_PARAM.MC_VEL_Z_D_MIN) {
          rtb_Saturation_c = CONTROL_PARAM.MC_VEL_Z_D_MIN;
        }
      }

      /* End of Saturate: '<S118>/Saturation' */

      /* Saturate: '<S112>/Saturation' */
      if (rtb_Saturation_gg > 1.0F) {
        rtb_Saturation_gg = 1.0F;
      } else {
        if (rtb_Saturation_gg < 0.0F) {
          rtb_Saturation_gg = 0.0F;
        }
      }

      /* End of Saturate: '<S112>/Saturation' */

      /* Product: '<S112>/Multiply1' incorporates:
       *  Constant: '<S120>/kp'
       *  DiscreteIntegrator: '<S119>/Discrete-Time Integrator'
       *  Product: '<S120>/Multiply'
       *  Sum: '<S115>/Add'
       */
      rtb_Saturation_gg *= ((CONTROL_PARAM.MC_VEL_Z_P * rtb_Gain_ms +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_b) + rtb_Saturation_c) *
        rtb_boost_factor_o;

      /* Saturate: '<S111>/Saturation' */
      if (rtb_Saturation_gg > 0.35F) {
        rtb_Saturation_gg = 0.35F;
      } else {
        if (rtb_Saturation_gg < -0.35F) {
          rtb_Saturation_gg = -0.35F;
        }
      }

      /* End of Saturate: '<S111>/Saturation' */

      /* Sum: '<S80>/Sum' incorporates:
       *  Constant: '<S80>/mc_hover_throttle'
       */
      rtb_Saturation_gg += CONTROL_PARAM.MC_HOVER_THRO;

      /* Saturate: '<S80>/Saturation' */
      if (rtb_Saturation_gg > 1.0F) {
        rtb_Saturation_gg = 1.0F;
      } else {
        if (rtb_Saturation_gg < -1.0F) {
          rtb_Saturation_gg = -1.0F;
        }
      }

      /* End of Saturate: '<S80>/Saturation' */

      /* Saturate: '<S74>/Saturation1' incorporates:
       *  DiscreteIntegrator: '<S123>/Discrete-Time Integrator5'
       *  Product: '<S74>/Multiply1'
       */
      rtb_Saturation_gg *= Controller_DW.DiscreteTimeIntegrator5_DSTA_a2;
      if (rtb_Saturation_gg > 1.0F) {
        rtb_Saturation_gg = 1.0F;
      } else {
        if (rtb_Saturation_gg < -1.0F) {
          rtb_Saturation_gg = -1.0F;
        }
      }

      /* End of Saturate: '<S74>/Saturation1' */

      /* Saturate: '<S171>/Saturation' incorporates:
       *  Saturate: '<S164>/Saturation2'
       */
      if (rtb_Saturation_gg < 0.0F) {
        rtb_Saturation_gg = 0.0F;
      }

      /* End of Saturate: '<S171>/Saturation' */

      /* DataTypeConversion: '<S171>/Data Type Conversion' incorporates:
       *  Constant: '<S171>/Constant1'
       *  Gain: '<S171>/Gain1'
       *  Sum: '<S171>/Sum1'
       */
      rtb_DataTypeConversion_k = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
        rtb_Saturation_gg), 4.2949673E+9F) + 1000U);

      /* Product: '<S164>/Multiply' incorporates:
       *  Constant: '<S164>/Effective_Matrix'
       *  Saturate: '<S164>/Saturation1'
       */
      for (i = 0; i < 4; i++) {
        tmp[i] = Controller_ConstP.pooled12[i + 8] * rtb_Add2_h +
          (Controller_ConstP.pooled12[i + 4] * rtb_Add_k +
           Controller_ConstP.pooled12[i] * rtb_Vdot_errg);
      }

      /* End of Product: '<S164>/Multiply' */

      /* Saturate: '<S128>/FF_limit' */
      if (rtb_Subtract3_o > CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_Subtract3_o = CONTROL_PARAM.FW_FF_LIMIT;
      } else {
        if (rtb_Subtract3_o < -CONTROL_PARAM.FW_FF_LIMIT) {
          rtb_Subtract3_o = -CONTROL_PARAM.FW_FF_LIMIT;
        }
      }

      /* Saturate: '<S128>/PI_limit' */
      if (rtb_Abs > CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_Abs = CONTROL_PARAM.FW_PI_LIMIT;
      } else {
        if (rtb_Abs < -CONTROL_PARAM.FW_PI_LIMIT) {
          rtb_Abs = -CONTROL_PARAM.FW_PI_LIMIT;
        }
      }

      /* Saturate: '<S76>/Saturation1' incorporates:
       *  DiscreteIntegrator: '<S122>/Discrete-Time Integrator5'
       *  Product: '<S76>/Multiply'
       *  Sum: '<S128>/Add'
       */
      rtb_Subtract3_o = (rtb_Subtract3_o + rtb_Abs) *
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;
      if (rtb_Subtract3_o > 1.0F) {
        rtb_Subtract3_o = 1.0F;
      } else {
        if (rtb_Subtract3_o < -1.0F) {
          rtb_Subtract3_o = -1.0F;
        }
      }

      /* Saturate: '<S128>/FF_limit' */
      if (rtb_Switch_h > CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_Switch_h = CONTROL_PARAM.FW_FF_LIMIT;
      } else {
        if (rtb_Switch_h < -CONTROL_PARAM.FW_FF_LIMIT) {
          rtb_Switch_h = -CONTROL_PARAM.FW_FF_LIMIT;
        }
      }

      /* Saturate: '<S128>/PI_limit' */
      if (rtb_att_error_B_rad_idx_1 > CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_att_error_B_rad_idx_1 = CONTROL_PARAM.FW_PI_LIMIT;
      } else {
        if (rtb_att_error_B_rad_idx_1 < -CONTROL_PARAM.FW_PI_LIMIT) {
          rtb_att_error_B_rad_idx_1 = -CONTROL_PARAM.FW_PI_LIMIT;
        }
      }

      /* Saturate: '<S76>/Saturation1' incorporates:
       *  DiscreteIntegrator: '<S122>/Discrete-Time Integrator5'
       *  Product: '<S76>/Multiply'
       *  Sum: '<S128>/Add'
       */
      rtb_Abs = (rtb_Switch_h + rtb_att_error_B_rad_idx_1) *
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;
      if (rtb_Abs > 1.0F) {
        rtb_Abs = 1.0F;
      } else {
        if (rtb_Abs < -1.0F) {
          rtb_Abs = -1.0F;
        }
      }

      /* Saturate: '<S128>/FF_limit' */
      if (rtb_Vdotg > CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_Vdotg = CONTROL_PARAM.FW_FF_LIMIT;
      } else {
        if (rtb_Vdotg < -CONTROL_PARAM.FW_FF_LIMIT) {
          rtb_Vdotg = -CONTROL_PARAM.FW_FF_LIMIT;
        }
      }

      /* Saturate: '<S128>/PI_limit' */
      if (rtb_Minus > CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_Minus = CONTROL_PARAM.FW_PI_LIMIT;
      } else {
        if (rtb_Minus < -CONTROL_PARAM.FW_PI_LIMIT) {
          rtb_Minus = -CONTROL_PARAM.FW_PI_LIMIT;
        }
      }

      /* Saturate: '<S76>/Saturation1' incorporates:
       *  DiscreteIntegrator: '<S122>/Discrete-Time Integrator5'
       *  Product: '<S76>/Multiply'
       *  Sum: '<S128>/Add'
       */
      rtb_Switch_h = (rtb_Vdotg + rtb_Minus) *
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;
      if (rtb_Switch_h > 1.0F) {
        rtb_Switch_h = 1.0F;
      } else {
        if (rtb_Switch_h < -1.0F) {
          rtb_Switch_h = -1.0F;
        }
      }

      rtb_MultiportSwitch[4] = Controller_DW.Delay_DSTATE;

      /* Product: '<S163>/Multiply1' incorporates:
       *  Delay: '<S167>/Delay'
       *  Saturate: '<S163>/Saturation1'
       */
      for (i = 0; i < 4; i++) {
        /* Saturate: '<S164>/Saturation' incorporates:
         *  Gain: '<S164>/Gain'
         *  Sum: '<S164>/Add'
         */
        rtb_Saturation_c = fmodf(floorf(1000.0F * tmp[i] + (real32_T)
          rtb_DataTypeConversion_k), 65536.0F);
        u0 = (uint16_T)(rtb_Saturation_c < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                        (uint16_T)-rtb_Saturation_c : (int32_T)(uint16_T)
                        rtb_Saturation_c);
        if (u0 > 1900) {
          rtb_MultiportSwitch[i] = 1900U;
        } else if (u0 < 1000) {
          rtb_MultiportSwitch[i] = 1000U;
        } else {
          rtb_MultiportSwitch[i] = u0;
        }

        /* End of Saturate: '<S164>/Saturation' */

        /* Saturate: '<S163>/Saturation1' incorporates:
         *  Bias: '<S163>/Bias'
         *  Gain: '<S163>/Gain1'
         *  Saturate: '<S163>/Saturation5'
         */
        rtb_att_error_B_rad_idx_1 = 500.0F * (rtb_MatrixConcatenate[i + 8] *
          rtb_Switch_h + (rtb_MatrixConcatenate[i + 4] * rtb_Abs +
                          rtb_MatrixConcatenate[i] * rtb_Subtract3_o)) + 1500.0F;
        if (rtb_att_error_B_rad_idx_1 > 2000.0F) {
          rtb_att_error_B_rad_idx_1 = 2000.0F;
        } else {
          if (rtb_att_error_B_rad_idx_1 < 1000.0F) {
            rtb_att_error_B_rad_idx_1 = 1000.0F;
          }
        }

        rtb_MultiportSwitch[i + 5] = (uint16_T)fmodf(floorf
          (rtb_att_error_B_rad_idx_1), 65536.0F);
      }

      /* End of Product: '<S163>/Multiply1' */
      break;

     default:
      for (i = 0; i < 9; i++) {
        rtb_MultiportSwitch[i] = Controller_ConstP.Disarm_Value[i];
      }
      break;
    }

    /* End of MultiPortSwitch: '<S165>/Multiport Switch' */
    /* End of Outputs for SubSystem: '<S161>/VTOL1' */
    for (i = 0; i < 9; i++) {
      /* Outport: '<Root>/Control_Out' incorporates:
       *  Reshape: '<S160>/Reshape'
       */
      Controller_Y.Control_Out.actuator_cmd[i] = rtb_MultiportSwitch[i];
    }

    for (i = 0; i < 7; i++) {
      /* Outport: '<Root>/Control_Out' incorporates:
       *  Reshape: '<S160>/Reshape'
       */
      Controller_Y.Control_Out.actuator_cmd[i + 9] = 0U;
    }

    /* Product: '<S91>/Multiply' incorporates:
     *  Constant: '<S91>/gain1'
     *  Constant: '<S91>/gain2'
     *  Constant: '<S91>/gain3'
     *  DiscreteIntegrator: '<S89>/Discrete-Time Integrator5'
     */
    rtb_Abs = CONTROL_PARAM.MC_ROLL_RATE_I *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0];
    rtb_Switch_h = CONTROL_PARAM.MC_PITCH_RATE_I *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1];
    rtb_Vdotg = CONTROL_PARAM.MC_YAW_RATE_I *
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2];

    /* Product: '<S117>/Multiply1' incorporates:
     *  Constant: '<S117>/const1'
     *  DiscreteIntegrator: '<S116>/Integrator'
     */
    rtb_Subtract3_o = Controller_DW.Integrator_DSTATE_f * 0.05F;

    /* Switch: '<S104>/Switch1' incorporates:
     *  Constant: '<S109>/Constant'
     *  Constant: '<S110>/Constant'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S109>/Compare'
     *  RelationalOperator: '<S110>/Compare'
     *  Switch: '<S104>/Switch'
     */
    if (rtb_VTOL_State == VTOLState_BackTrans) {
      rtb_att_error_B_rad_idx_1 = Controller_U.FMS_Out.w_cmd;
    } else if (rtb_BitwiseAND <= 3) {
      /* Switch: '<S104>/Switch' incorporates:
       *  Constant: '<S104>/Zero'
       */
      rtb_att_error_B_rad_idx_1 = 0.0F;
    } else {
      rtb_att_error_B_rad_idx_1 = Controller_U.FMS_Out.w_cmd;
    }

    /* End of Switch: '<S104>/Switch1' */

    /* Sum: '<S117>/Add' incorporates:
     *  DiscreteIntegrator: '<S116>/Integrator1'
     *  Sum: '<S116>/Subtract'
     */
    rtb_Minus = (Controller_DW.Integrator1_DSTATE_i - rtb_att_error_B_rad_idx_1)
      + rtb_Subtract3_o;

    /* Signum: '<S117>/Sign' */
    if (rtb_Minus < 0.0F) {
      rtb_att_error_B_rad_idx_1 = -1.0F;
    } else if (rtb_Minus > 0.0F) {
      rtb_att_error_B_rad_idx_1 = 1.0F;
    } else {
      rtb_att_error_B_rad_idx_1 = rtb_Minus;
    }

    /* End of Signum: '<S117>/Sign' */

    /* Sum: '<S117>/Add2' incorporates:
     *  Abs: '<S117>/Abs'
     *  Gain: '<S117>/Gain'
     *  Gain: '<S117>/Gain1'
     *  Product: '<S117>/Multiply2'
     *  Product: '<S117>/Multiply3'
     *  Sqrt: '<S117>/Sqrt'
     *  Sum: '<S117>/Add1'
     *  Sum: '<S117>/Subtract'
     */
    rtb_att_error_B_rad_idx_1 = (sqrtf((8.0F * fabsf(rtb_Minus) +
      Controller_ConstB.d_m) * Controller_ConstB.d_m) - Controller_ConstB.d_m) *
      0.5F * rtb_att_error_B_rad_idx_1 + rtb_Subtract3_o;

    /* Sum: '<S117>/Add4' */
    rtb_Vdot_errg = (rtb_Minus - rtb_att_error_B_rad_idx_1) + rtb_Subtract3_o;

    /* Sum: '<S117>/Add3' */
    rtb_Subtract3_o = rtb_Minus + Controller_ConstB.d_m;

    /* Sum: '<S117>/Subtract1' */
    rtb_Minus -= Controller_ConstB.d_m;

    /* Signum: '<S117>/Sign1' */
    if (rtb_Subtract3_o < 0.0F) {
      rtb_Subtract3_o = -1.0F;
    } else {
      if (rtb_Subtract3_o > 0.0F) {
        rtb_Subtract3_o = 1.0F;
      }
    }

    /* End of Signum: '<S117>/Sign1' */

    /* Signum: '<S117>/Sign2' */
    if (rtb_Minus < 0.0F) {
      rtb_Minus = -1.0F;
    } else {
      if (rtb_Minus > 0.0F) {
        rtb_Minus = 1.0F;
      }
    }

    /* End of Signum: '<S117>/Sign2' */

    /* Sum: '<S117>/Add5' incorporates:
     *  Gain: '<S117>/Gain2'
     *  Product: '<S117>/Multiply4'
     *  Sum: '<S117>/Subtract2'
     */
    rtb_att_error_B_rad_idx_1 += (rtb_Subtract3_o - rtb_Minus) * 0.5F *
      rtb_Vdot_errg;

    /* Update for DiscreteIntegrator: '<S124>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S124>/Gain'
     *  Sum: '<S124>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_e = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_a += (rtb_Divide_i -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_a) * 31.415926F * 0.002F;

    /* Update for DiscreteIntegrator: '<S123>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S123>/Gain'
     *  Sum: '<S123>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_o = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTA_a2 += ((real32_T)rtb_Relay -
      Controller_DW.DiscreteTimeIntegrator5_DSTA_a2) * 6.28318548F * 0.002F;

    /* Update for DiscreteIntegrator: '<S116>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S116>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_i += 0.002F *
      Controller_DW.Integrator_DSTATE_f;

    /* Update for DiscreteIntegrator: '<S119>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S119>/ki'
     *  Product: '<S119>/Multiply'
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

    /* End of Update for DiscreteIntegrator: '<S119>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S121>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_i = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_l += 0.002F * rtb_Gain_it;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_h = (int8_T)
      rtb_LogicalOperator_b3;

    /* Update for DiscreteIntegrator: '<S154>/ ' incorporates:
     *  Gain: '<S154>/Gain3'
     *  Inport: '<Root>/FMS_Out'
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

    /* End of Update for DiscreteIntegrator: '<S154>/ ' */

    /* Update for DiscreteIntegrator: '<S155>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_f = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_e += 0.002F * rtb_Gain_il;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_b = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S89>/Discrete-Time Integrator5' */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_b = 0U;

    /* Update for DiscreteIntegrator: '<S91>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_PrevRe_o = (int8_T)
      rtb_LogicalOperator_m;

    /* Update for DiscreteIntegrator: '<S93>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_h = 0U;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_l = (int8_T)
      rtb_LogicalOperator_m;

    /* Update for DiscreteIntegrator: '<S122>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S122>/Gain'
     *  Sum: '<S122>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_g = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_j += (rtb_Saturation_j -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j) * 12.566371F * 0.002F;

    /* Update for DiscreteIntegrator: '<S89>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S89>/Gain'
     *  Sum: '<S89>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0] +=
      (rtb_rate_error_B_radPs_b_idx_0 -
       Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S91>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_d[0] += 0.002F * rtb_Abs;
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

    /* Update for DiscreteIntegrator: '<S93>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[0] += 0.002F * rtb_Multiply1;

    /* Update for DiscreteIntegrator: '<S134>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S134>/gain1'
     *  Product: '<S134>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0] +=
      CONTROL_PARAM.FW_ROLL_RATE_I * rtb_Sum * 0.002F;
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

    /* Update for DiscreteIntegrator: '<S89>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S89>/Gain'
     *  Sum: '<S89>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1] +=
      (rtb_rate_error_B_radPs_b_idx_1 -
       Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S91>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_d[1] += 0.002F * rtb_Switch_h;
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

    /* Update for DiscreteIntegrator: '<S93>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[1] += 0.002F *
      rtb_Gain_a_idx_1;

    /* Update for DiscreteIntegrator: '<S134>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S134>/gain2'
     *  Product: '<S134>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1] +=
      CONTROL_PARAM.FW_PITCH_RATE_I * rtb_Saturation_lu * 0.002F;
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

    /* Update for DiscreteIntegrator: '<S89>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S89>/Gain'
     *  Sum: '<S89>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2] +=
      (rtb_rate_error_B_radPs_b_idx_2 -
       Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S91>/Discrete-Time Integrator' */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_d[2] += 0.002F * rtb_Vdotg;
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

    /* Update for DiscreteIntegrator: '<S93>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[2] += 0.002F *
      rtb_Gain_a_idx_2;

    /* Update for DiscreteIntegrator: '<S134>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S134>/gain3'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S134>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2] +=
      CONTROL_PARAM.FW_YAW_RATE_I * rtb_rate_err_B_idx_2 * 0.002F;
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

    /* Update for DiscreteIntegrator: '<S157>/ ' incorporates:
     *  Gain: '<S157>/Gain'
     *  Inport: '<Root>/FMS_Out'
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

    /* End of Update for DiscreteIntegrator: '<S157>/ ' */

    /* Update for DiscreteIntegrator: '<S158>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.DiscreteTimeIntegrator1_IC_L_h0 = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTA_nm += 0.002F *
      rtb_att_error_B_rad_idx_0;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_d = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Signum: '<S117>/Sign6' incorporates:
     *  Signum: '<S117>/Sign5'
     */
    if (rtb_att_error_B_rad_idx_1 < 0.0F) {
      rtb_rate_error_B_radPs_b_idx_0 = -1.0F;

      /* Signum: '<S117>/Sign5' */
      rtb_rate_error_B_radPs_b_idx_1 = -1.0F;
    } else if (rtb_att_error_B_rad_idx_1 > 0.0F) {
      rtb_rate_error_B_radPs_b_idx_0 = 1.0F;

      /* Signum: '<S117>/Sign5' */
      rtb_rate_error_B_radPs_b_idx_1 = 1.0F;
    } else {
      rtb_rate_error_B_radPs_b_idx_0 = rtb_att_error_B_rad_idx_1;

      /* Signum: '<S117>/Sign5' */
      rtb_rate_error_B_radPs_b_idx_1 = rtb_att_error_B_rad_idx_1;
    }

    /* End of Signum: '<S117>/Sign6' */

    /* Sum: '<S117>/Add6' */
    rtb_Subtract3_o = rtb_att_error_B_rad_idx_1 + Controller_ConstB.d_m;

    /* Sum: '<S117>/Subtract3' */
    rtb_Multiply1 = rtb_att_error_B_rad_idx_1 - Controller_ConstB.d_m;

    /* Signum: '<S117>/Sign3' */
    if (rtb_Subtract3_o < 0.0F) {
      rtb_Subtract3_o = -1.0F;
    } else {
      if (rtb_Subtract3_o > 0.0F) {
        rtb_Subtract3_o = 1.0F;
      }
    }

    /* End of Signum: '<S117>/Sign3' */

    /* Signum: '<S117>/Sign4' */
    if (rtb_Multiply1 < 0.0F) {
      rtb_Multiply1 = -1.0F;
    } else {
      if (rtb_Multiply1 > 0.0F) {
        rtb_Multiply1 = 1.0F;
      }
    }

    /* End of Signum: '<S117>/Sign4' */

    /* Update for DiscreteIntegrator: '<S116>/Integrator' incorporates:
     *  Constant: '<S117>/const'
     *  Gain: '<S117>/Gain3'
     *  Product: '<S117>/Divide'
     *  Product: '<S117>/Multiply5'
     *  Product: '<S117>/Multiply6'
     *  Sum: '<S117>/Subtract4'
     *  Sum: '<S117>/Subtract5'
     *  Sum: '<S117>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE_f += ((rtb_att_error_B_rad_idx_1 /
      Controller_ConstB.d_m - rtb_rate_error_B_radPs_b_idx_1) *
      Controller_ConstB.Gain4_o * ((rtb_Subtract3_o - rtb_Multiply1) * 0.5F) -
      rtb_rate_error_B_radPs_b_idx_0 * 78.448F) * 0.002F;

    /* End of Outputs for SubSystem: '<S2>/VTOL_Controller' */
    break;

   case 1:
    if (Controller_DW.SwitchCase1_ActiveSubsystem != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S2>/MC_Controller' incorporates:
       *  ActionPort: '<S4>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S7>/Switch Case1' incorporates:
       *  DiscreteIntegrator: '<S21>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S23>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S25>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S45>/Integrator'
       *  DiscreteIntegrator: '<S45>/Integrator1'
       *  DiscreteIntegrator: '<S50>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S52>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S68>/Integrator'
       *  DiscreteIntegrator: '<S68>/Integrator1'
       *  DiscreteIntegrator: '<S71>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S73>/Discrete-Time Integrator1'
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
     *  ActionPort: '<S4>/Action Port'
     */
    /* DiscreteIntegrator: '<S23>/Discrete-Time Integrator' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
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

    /* Trigonometry: '<S47>/Trigonometric Function1' incorporates:
     *  Gain: '<S46>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S47>/Trigonometric Function3'
     */
    rtb_Multiply1 = arm_cos_f32(-Controller_U.INS_Out.psi);
    rtb_VectorConcatenate[0] = rtb_Multiply1;

    /* Trigonometry: '<S47>/Trigonometric Function' incorporates:
     *  Gain: '<S46>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S47>/Trigonometric Function2'
     */
    rtb_rate_error_B_radPs_b_idx_0 = arm_sin_f32(-Controller_U.INS_Out.psi);
    rtb_VectorConcatenate[1] = rtb_rate_error_B_radPs_b_idx_0;

    /* SignalConversion: '<S47>/ConcatBufferAtVector Concatenate1In3' incorporates:
     *  Constant: '<S47>/Constant3'
     */
    rtb_VectorConcatenate[2] = 0.0F;

    /* Gain: '<S47>/Gain' */
    rtb_VectorConcatenate[3] = -rtb_rate_error_B_radPs_b_idx_0;

    /* Trigonometry: '<S47>/Trigonometric Function3' */
    rtb_VectorConcatenate[4] = rtb_Multiply1;

    /* SignalConversion: '<S47>/ConcatBufferAtVector Concatenate2In3' incorporates:
     *  Constant: '<S47>/Constant4'
     */
    rtb_VectorConcatenate[5] = 0.0F;

    /* SignalConversion: '<S47>/ConcatBufferAtVector ConcatenateIn3' */
    rtb_VectorConcatenate[6] = Controller_ConstB.VectorConcatenate3[0];
    rtb_VectorConcatenate[7] = Controller_ConstB.VectorConcatenate3[1];
    rtb_VectorConcatenate[8] = Controller_ConstB.VectorConcatenate3[2];

    /* Product: '<S44>/Multiply' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  SignalConversion: '<S44>/TmpSignal ConversionAtMultiplyInport2'
     */
    for (i = 0; i < 3; i++) {
      rtb_VectorConcatenate_0[i] = rtb_VectorConcatenate[i + 3] *
        Controller_U.INS_Out.ve + rtb_VectorConcatenate[i] *
        Controller_U.INS_Out.vn;
    }

    /* End of Product: '<S44>/Multiply' */

    /* Sum: '<S41>/Sum' incorporates:
     *  DiscreteIntegrator: '<S45>/Integrator1'
     */
    rtb_att_error_B_rad_idx_0 = Controller_DW.Integrator1_DSTATE[0] -
      rtb_VectorConcatenate_0[0];
    rtb_att_error_B_rad_idx_1 = Controller_DW.Integrator1_DSTATE[1] -
      rtb_VectorConcatenate_0[1];

    /* DiscreteIntegrator: '<S50>/Discrete-Time Integrator' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
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

    /* DiscreteIntegrator: '<S52>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] =
        rtb_att_error_B_rad_idx_0;
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] =
        rtb_att_error_B_rad_idx_1;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevRes != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] =
        rtb_att_error_B_rad_idx_0;
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] =
        rtb_att_error_B_rad_idx_1;
    }

    /* Gain: '<S52>/Gain' incorporates:
     *  DiscreteIntegrator: '<S52>/Discrete-Time Integrator1'
     *  Sum: '<S52>/Sum5'
     */
    rtb_Saturation1_h_idx_0 = (rtb_att_error_B_rad_idx_0 -
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[0]) * 62.831852F;
    rtb_Divide_i = (rtb_att_error_B_rad_idx_1 -
                    Controller_DW.DiscreteTimeIntegrator1_DSTATE[1]) *
      62.831852F;

    /* Switch: '<S52>/Switch' incorporates:
     *  Gain: '<S52>/Gain1'
     *  Inport: '<Root>/FMS_Out'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_Gain_il = 0.0F;
      rtb_rate_error_B_radPs_b_idx_0 = 0.0F;
    } else {
      rtb_Gain_il = rtb_Saturation1_h_idx_0;
      rtb_rate_error_B_radPs_b_idx_0 = rtb_Divide_i;
    }

    /* End of Switch: '<S52>/Switch' */

    /* Product: '<S49>/Multiply' incorporates:
     *  Constant: '<S49>/kd'
     */
    rtb_Gain_it = CONTROL_PARAM.MC_VEL_XY_D * rtb_Gain_il;

    /* Saturate: '<S49>/Saturation' */
    if (rtb_Gain_it > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
      rtb_Gain_it = CONTROL_PARAM.MC_VEL_XY_D_MAX;
    } else {
      if (rtb_Gain_it < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
        rtb_Gain_it = CONTROL_PARAM.MC_VEL_XY_D_MIN;
      }
    }

    rtb_Gain_il = rtb_Gain_it;

    /* Product: '<S49>/Multiply' incorporates:
     *  Constant: '<S49>/kd'
     */
    rtb_Gain_it = CONTROL_PARAM.MC_VEL_XY_D * rtb_rate_error_B_radPs_b_idx_0;

    /* Saturate: '<S49>/Saturation' */
    if (rtb_Gain_it > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
      rtb_Gain_it = CONTROL_PARAM.MC_VEL_XY_D_MAX;
    } else {
      if (rtb_Gain_it < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
        rtb_Gain_it = CONTROL_PARAM.MC_VEL_XY_D_MIN;
      }
    }

    /* Switch: '<S43>/Switch' incorporates:
     *  Constant: '<S51>/kp'
     *  Constant: '<S53>/Constant'
     *  Constant: '<S55>/Constant'
     *  Constant: '<S56>/Constant'
     *  DiscreteIntegrator: '<S50>/Discrete-Time Integrator'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S51>/Multiply'
     *  Product: '<S54>/Multiply2'
     *  Product: '<S54>/Multiply3'
     *  RelationalOperator: '<S53>/Compare'
     *  RelationalOperator: '<S55>/Compare'
     *  RelationalOperator: '<S56>/Compare'
     *  S-Function (sfix_bitop): '<S54>/cmd_ax valid'
     *  S-Function (sfix_bitop): '<S54>/cmd_ay valid'
     *  S-Function (sfix_bitop): '<S54>/cmd_u valid'
     *  S-Function (sfix_bitop): '<S54>/cmd_v valid'
     *  Sum: '<S42>/Add'
     *  Sum: '<S54>/Sum1'
     */
    if (rtb_BitwiseAND == 6) {
      rtb_Gain_il = ((Controller_U.FMS_Out.cmd_mask & 64) > 0 ?
                     (CONTROL_PARAM.MC_VEL_XY_P * rtb_att_error_B_rad_idx_0 +
                      Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0]) +
                     rtb_Gain_il : 0.0F) + ((Controller_U.FMS_Out.cmd_mask & 512)
        > 0 ? Controller_U.FMS_Out.ax_cmd : 0.0F);
      rtb_rate_error_B_radPs_b_idx_0 = ((Controller_U.FMS_Out.cmd_mask & 128) >
        0 ? (CONTROL_PARAM.MC_VEL_XY_P * rtb_att_error_B_rad_idx_1 +
             Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1]) + rtb_Gain_it :
        0.0F) + ((Controller_U.FMS_Out.cmd_mask & 1024) > 0 ?
                 Controller_U.FMS_Out.ay_cmd : 0.0F);
    } else {
      rtb_Gain_il += CONTROL_PARAM.MC_VEL_XY_P * rtb_att_error_B_rad_idx_0 +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0];
      rtb_rate_error_B_radPs_b_idx_0 = (CONTROL_PARAM.MC_VEL_XY_P *
        rtb_att_error_B_rad_idx_1 +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1]) + rtb_Gain_it;
    }

    /* End of Switch: '<S43>/Switch' */

    /* Trigonometry: '<S40>/Atan' incorporates:
     *  Constant: '<S40>/g'
     *  Gain: '<S40>/Gain1'
     *  Gain: '<S40>/gain'
     *  Product: '<S40>/Divide'
     */
    rtb_Subtract3_o = atanf(1.1F * rtb_rate_error_B_radPs_b_idx_0 / 9.8055F);
    rtb_rate_error_B_radPs_b_idx_0 = atanf(1.1F * -rtb_Gain_il / 9.8055F);

    /* Switch: '<S31>/Switch' incorporates:
     *  Constant: '<S38>/Constant'
     *  Inport: '<Root>/FMS_Out'
     *  Logic: '<S31>/Logical Operator'
     *  RelationalOperator: '<S37>/Compare'
     *  RelationalOperator: '<S38>/Compare'
     *  Saturate: '<S40>/Saturation'
     *  Switch: '<S31>/Switch1'
     */
    if ((rtb_BitwiseAND == 3) || (rtb_BitwiseAND == 4)) {
      rtb_Gain_il = Controller_U.FMS_Out.phi_cmd;
      rtb_rate_error_B_radPs_b_idx_0 = Controller_U.FMS_Out.theta_cmd;
    } else if (rtb_BitwiseAND == 6) {
      /* Switch: '<S39>/Switch' incorporates:
       *  Inport: '<Root>/FMS_Out'
       *  S-Function (sfix_bitop): '<S39>/cmd_phi valid'
       *  S-Function (sfix_bitop): '<S39>/cmd_theta valid'
       *  Saturate: '<S40>/Saturation'
       *  Switch: '<S31>/Switch1'
       */
      if ((Controller_U.FMS_Out.cmd_mask & 8) > 0) {
        rtb_Gain_il = Controller_U.FMS_Out.phi_cmd;
      } else if (rtb_Subtract3_o > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S40>/Saturation' */
        rtb_Gain_il = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else if (rtb_Subtract3_o < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S40>/Saturation' */
        rtb_Gain_il = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        rtb_Gain_il = rtb_Subtract3_o;
      }

      if ((Controller_U.FMS_Out.cmd_mask & 16) > 0) {
        rtb_rate_error_B_radPs_b_idx_0 = Controller_U.FMS_Out.theta_cmd;
      } else if (rtb_rate_error_B_radPs_b_idx_0 >
                 CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S40>/Saturation' */
        rtb_rate_error_B_radPs_b_idx_0 = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_rate_error_B_radPs_b_idx_0 <
            -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Saturate: '<S40>/Saturation' */
          rtb_rate_error_B_radPs_b_idx_0 = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        }
      }

      /* End of Switch: '<S39>/Switch' */
    } else {
      if (rtb_Subtract3_o > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S40>/Saturation' incorporates:
         *  Switch: '<S31>/Switch1'
         */
        rtb_Gain_il = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else if (rtb_Subtract3_o < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S40>/Saturation' incorporates:
         *  Switch: '<S31>/Switch1'
         */
        rtb_Gain_il = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        /* Switch: '<S31>/Switch1' incorporates:
         *  Saturate: '<S40>/Saturation'
         */
        rtb_Gain_il = rtb_Subtract3_o;
      }

      /* Saturate: '<S40>/Saturation' */
      if (rtb_rate_error_B_radPs_b_idx_0 > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM)
      {
        /* Switch: '<S31>/Switch1' */
        rtb_rate_error_B_radPs_b_idx_0 = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_rate_error_B_radPs_b_idx_0 <
            -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Switch: '<S31>/Switch1' */
          rtb_rate_error_B_radPs_b_idx_0 = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        }
      }
    }

    /* End of Switch: '<S31>/Switch' */

    /* Sum: '<S32>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Gain_it = rtb_Gain_il - Controller_U.INS_Out.phi;

    /* Product: '<S35>/Divide1' incorporates:
     *  Abs: '<S35>/Abs'
     *  Constant: '<S35>/const2'
     */
    rtb_Multiply1 = fabsf(rtb_Gain_it) / 0.002F;

    /* Product: '<S35>/Divide' incorporates:
     *  Constant: '<S33>/Constant1'
     *  Constant: '<S35>/const1'
     *  Math: '<S35>/Square'
     *  SignalConversion: '<S35>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_rate_err_B_idx_2 = 9.5993F / (CONTROL_PARAM.MC_ROLL_P *
      CONTROL_PARAM.MC_ROLL_P);

    /* Signum: '<S35>/Sign' */
    if (rtb_Gain_it < 0.0F) {
      rtb_rate_error_B_radPs_b_idx_1 = -1.0F;
    } else if (rtb_Gain_it > 0.0F) {
      rtb_rate_error_B_radPs_b_idx_1 = 1.0F;
    } else {
      rtb_rate_error_B_radPs_b_idx_1 = rtb_Gain_it;
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
    if ((rtb_Gain_it <= rtb_rate_err_B_idx_2) && (rtb_Gain_it >=
         -rtb_rate_err_B_idx_2)) {
      rtb_rate_error_B_radPs_b_idx_1 = rtb_Gain_it * CONTROL_PARAM.MC_ROLL_P;
    } else {
      rtb_rate_error_B_radPs_b_idx_1 *= sqrtf((rtb_rate_error_B_radPs_b_idx_1 *
        rtb_Gain_it - 0.5F * rtb_rate_err_B_idx_2) * Controller_ConstB.Gain);
    }

    /* Gain: '<S35>/Gain3' */
    rtb_rate_err_B_idx_2 = -rtb_Multiply1;

    /* Switch: '<S36>/Switch' incorporates:
     *  Gain: '<S35>/Gain3'
     *  RelationalOperator: '<S36>/UpperRelop'
     */
    if (rtb_rate_error_B_radPs_b_idx_1 >= -rtb_Multiply1) {
      rtb_rate_err_B_idx_2 = rtb_rate_error_B_radPs_b_idx_1;
    }

    /* Switch: '<S36>/Switch2' incorporates:
     *  RelationalOperator: '<S36>/LowerRelop1'
     */
    if (rtb_rate_error_B_radPs_b_idx_1 <= rtb_Multiply1) {
      rtb_Multiply1 = rtb_rate_err_B_idx_2;
    }

    /* Saturate: '<S16>/Saturation1' */
    if (rtb_Multiply1 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_Multiply1 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_Multiply1 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_Multiply1 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    rtb_Gain_il = rtb_Multiply1;

    /* Sum: '<S32>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S35>/Divide1'
     */
    rtb_Gain_it = rtb_rate_error_B_radPs_b_idx_0 - Controller_U.INS_Out.theta;

    /* Product: '<S35>/Divide1' incorporates:
     *  Abs: '<S35>/Abs'
     *  Constant: '<S35>/const2'
     */
    rtb_Multiply1 = fabsf(rtb_Gain_it) / 0.002F;

    /* Product: '<S35>/Divide' incorporates:
     *  Constant: '<S33>/Constant2'
     *  Constant: '<S35>/const1'
     *  Math: '<S35>/Square'
     *  SignalConversion: '<S35>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_rate_err_B_idx_2 = 9.5993F / (CONTROL_PARAM.MC_PITCH_P *
      CONTROL_PARAM.MC_PITCH_P);

    /* Signum: '<S35>/Sign' */
    if (rtb_Gain_it < 0.0F) {
      rtb_rate_error_B_radPs_b_idx_1 = -1.0F;
    } else if (rtb_Gain_it > 0.0F) {
      rtb_rate_error_B_radPs_b_idx_1 = 1.0F;
    } else {
      rtb_rate_error_B_radPs_b_idx_1 = rtb_Gain_it;
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
    if ((rtb_Gain_it <= rtb_rate_err_B_idx_2) && (rtb_Gain_it >=
         -rtb_rate_err_B_idx_2)) {
      rtb_rate_error_B_radPs_b_idx_1 = rtb_Gain_it * CONTROL_PARAM.MC_PITCH_P;
    } else {
      rtb_rate_error_B_radPs_b_idx_1 *= sqrtf((rtb_rate_error_B_radPs_b_idx_1 *
        rtb_Gain_it - 0.5F * rtb_rate_err_B_idx_2) * Controller_ConstB.Gain);
    }

    /* Gain: '<S35>/Gain3' */
    rtb_rate_err_B_idx_2 = -rtb_Multiply1;

    /* Switch: '<S36>/Switch' incorporates:
     *  Gain: '<S35>/Gain3'
     *  RelationalOperator: '<S36>/UpperRelop'
     */
    if (rtb_rate_error_B_radPs_b_idx_1 >= -rtb_Multiply1) {
      rtb_rate_err_B_idx_2 = rtb_rate_error_B_radPs_b_idx_1;
    }

    /* Switch: '<S36>/Switch2' incorporates:
     *  RelationalOperator: '<S36>/LowerRelop1'
     */
    if (rtb_rate_error_B_radPs_b_idx_1 <= rtb_Multiply1) {
      rtb_Multiply1 = rtb_rate_err_B_idx_2;
    }

    /* Saturate: '<S16>/Saturation1' */
    if (rtb_Multiply1 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_Multiply1 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_Multiply1 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_Multiply1 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    /* Saturate: '<S16>/Saturation' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    if (Controller_U.FMS_Out.psi_rate_cmd > CONTROL_PARAM.MC_R_CMD_LIM) {
      rtb_B_err = CONTROL_PARAM.MC_R_CMD_LIM;
    } else if (Controller_U.FMS_Out.psi_rate_cmd < -CONTROL_PARAM.MC_R_CMD_LIM)
    {
      rtb_B_err = -CONTROL_PARAM.MC_R_CMD_LIM;
    } else {
      rtb_B_err = Controller_U.FMS_Out.psi_rate_cmd;
    }

    /* End of Saturate: '<S16>/Saturation' */

    /* Trigonometry: '<S26>/Sin' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Saturation_lu = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S26>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_rate_error_B_radPs_b_idx_0 = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Product: '<S26>/Multiply3' incorporates:
     *  Trigonometry: '<S26>/Cos1'
     *  Trigonometry: '<S26>/Sin'
     */
    rtb_Gain_a_idx_1 = rtb_Saturation_lu * rtb_rate_error_B_radPs_b_idx_0 *
      rtb_B_err;

    /* Trigonometry: '<S26>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_rate_error_B_radPs_b_idx_1 = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Product: '<S26>/Multiply1' incorporates:
     *  Trigonometry: '<S26>/Cos'
     */
    rtb_rate_error_B_radPs_b_idx_2 = rtb_rate_error_B_radPs_b_idx_1 *
      rtb_Multiply1;

    /* Product: '<S26>/Multiply4' incorporates:
     *  Trigonometry: '<S26>/Sin'
     */
    rtb_Saturation_lu *= rtb_Multiply1;

    /* Switch: '<S17>/Switch' incorporates:
     *  Constant: '<S27>/Constant'
     *  Constant: '<S28>/Constant'
     *  Inport: '<Root>/FMS_Out'
     *  RelationalOperator: '<S27>/Compare'
     *  RelationalOperator: '<S28>/Compare'
     *  Switch: '<S17>/Switch1'
     */
    if (rtb_BitwiseAND == 2) {
      rtb_Multiply1 = Controller_U.FMS_Out.p_cmd;
      rtb_Gain_a_idx_1 = Controller_U.FMS_Out.q_cmd;
      rtb_Gain_a_idx_2 = Controller_U.FMS_Out.r_cmd;
    } else if (rtb_BitwiseAND == 6) {
      /* Switch: '<S29>/Switch' incorporates:
       *  Inport: '<Root>/FMS_Out'
       *  Inport: '<Root>/INS_Out'
       *  Product: '<S26>/Multiply'
       *  Product: '<S26>/Multiply1'
       *  Product: '<S26>/Multiply5'
       *  S-Function (sfix_bitop): '<S29>/cmd_p valid'
       *  S-Function (sfix_bitop): '<S29>/cmd_q valid'
       *  S-Function (sfix_bitop): '<S29>/cmd_r valid'
       *  Sum: '<S26>/Add'
       *  Sum: '<S26>/Add1'
       *  Sum: '<S26>/Add2'
       *  Switch: '<S17>/Switch1'
       *  Trigonometry: '<S26>/Cos'
       *  Trigonometry: '<S26>/Cos1'
       *  Trigonometry: '<S26>/Sin1'
       */
      if ((Controller_U.FMS_Out.cmd_mask & 1) > 0) {
        rtb_Multiply1 = Controller_U.FMS_Out.p_cmd;
      } else {
        rtb_Multiply1 = rtb_Gain_il - arm_sin_f32(Controller_U.INS_Out.theta) *
          rtb_B_err;
      }

      if ((Controller_U.FMS_Out.cmd_mask & 2) > 0) {
        rtb_Gain_a_idx_1 = Controller_U.FMS_Out.q_cmd;
      } else {
        rtb_Gain_a_idx_1 += rtb_rate_error_B_radPs_b_idx_2;
      }

      if ((Controller_U.FMS_Out.cmd_mask & 4) > 0) {
        rtb_Gain_a_idx_2 = Controller_U.FMS_Out.r_cmd;
      } else {
        rtb_Gain_a_idx_2 = rtb_rate_error_B_radPs_b_idx_1 *
          rtb_rate_error_B_radPs_b_idx_0 * rtb_B_err - rtb_Saturation_lu;
      }

      /* End of Switch: '<S29>/Switch' */
    } else {
      /* Switch: '<S17>/Switch1' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Product: '<S26>/Multiply'
       *  Product: '<S26>/Multiply3'
       *  Product: '<S26>/Multiply5'
       *  Sum: '<S26>/Add'
       *  Sum: '<S26>/Add1'
       *  Sum: '<S26>/Add2'
       *  Trigonometry: '<S26>/Cos'
       *  Trigonometry: '<S26>/Cos1'
       *  Trigonometry: '<S26>/Sin1'
       */
      rtb_Multiply1 = rtb_Gain_il - arm_sin_f32(Controller_U.INS_Out.theta) *
        rtb_B_err;
      rtb_Gain_a_idx_1 += rtb_rate_error_B_radPs_b_idx_2;
      rtb_Gain_a_idx_2 = rtb_rate_error_B_radPs_b_idx_1 *
        rtb_rate_error_B_radPs_b_idx_0 * rtb_B_err - rtb_Saturation_lu;
    }

    /* End of Switch: '<S17>/Switch' */

    /* Sum: '<S18>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_rate_error_B_radPs_b_idx_0 = rtb_Multiply1 - Controller_U.INS_Out.p;
    rtb_rate_error_B_radPs_b_idx_1 = rtb_Gain_a_idx_1 - Controller_U.INS_Out.q;
    rtb_rate_error_B_radPs_b_idx_2 = rtb_Gain_a_idx_2 - Controller_U.INS_Out.r;

    /* DiscreteIntegrator: '<S21>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] =
        rtb_rate_error_B_radPs_b_idx_0;
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] =
        rtb_rate_error_B_radPs_b_idx_1;
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] =
        rtb_rate_error_B_radPs_b_idx_2;
    }

    /* DiscreteIntegrator: '<S25>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S21>/Discrete-Time Integrator5'
     *  Inport: '<Root>/FMS_Out'
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

    /* Gain: '<S25>/Gain' incorporates:
     *  DiscreteIntegrator: '<S21>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S25>/Discrete-Time Integrator1'
     *  Sum: '<S25>/Sum5'
     */
    rtb_Multiply1 = (Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] -
                     Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[0]) *
      188.49556F;
    rtb_Gain_a_idx_1 = (Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] -
                        Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[1]) *
      188.49556F;
    rtb_Gain_a_idx_2 = (Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] -
                        Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[2]) *
      188.49556F;

    /* Gain: '<S66>/Gain' incorporates:
     *  DiscreteIntegrator: '<S68>/Integrator1'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S66>/Sum1'
     */
    rtb_Saturation_j = -(Controller_DW.Integrator1_DSTATE_e -
                         Controller_U.INS_Out.vd);
    Controller_B.Constant = CONTROL_PARAM.MC_VEL_Z_I_MIN;

    /* DiscreteIntegrator: '<S71>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S71>/Constant'
     *  Inport: '<Root>/FMS_Out'
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

    /* DiscreteIntegrator: '<S73>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_d != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i = rtb_Saturation_j;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_Prev_ks != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i = rtb_Saturation_j;
    }

    /* Gain: '<S73>/Gain' incorporates:
     *  DiscreteIntegrator: '<S73>/Discrete-Time Integrator1'
     *  Sum: '<S73>/Sum5'
     */
    rtb_Gain_ms = (rtb_Saturation_j -
                   Controller_DW.DiscreteTimeIntegrator1_DSTAT_i) * 62.831852F;

    /* Switch: '<S73>/Switch' incorporates:
     *  Gain: '<S73>/Gain1'
     *  Inport: '<Root>/FMS_Out'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_Saturation_c = 0.0F;
    } else {
      rtb_Saturation_c = rtb_Gain_ms;
    }

    /* End of Switch: '<S73>/Switch' */

    /* Product: '<S70>/Multiply' incorporates:
     *  Constant: '<S70>/kd'
     */
    rtb_B_err = CONTROL_PARAM.MC_VEL_Z_D * rtb_Saturation_c;

    /* Saturate: '<S70>/Saturation' */
    if (rtb_B_err > CONTROL_PARAM.MC_VEL_Z_D_MAX) {
      rtb_B_err = CONTROL_PARAM.MC_VEL_Z_D_MAX;
    } else {
      if (rtb_B_err < CONTROL_PARAM.MC_VEL_Z_D_MIN) {
        rtb_B_err = CONTROL_PARAM.MC_VEL_Z_D_MIN;
      }
    }

    /* End of Saturate: '<S70>/Saturation' */

    /* Sum: '<S67>/Add' incorporates:
     *  Constant: '<S72>/kp'
     *  DiscreteIntegrator: '<S71>/Discrete-Time Integrator'
     *  Product: '<S72>/Multiply'
     */
    rtb_Gain_it = (CONTROL_PARAM.MC_VEL_Z_P * rtb_Saturation_j +
                   Controller_DW.DiscreteTimeIntegrator_DSTATE_l) + rtb_B_err;

    /* Product: '<S65>/Multiply' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S65>/Cos'
     *  Trigonometry: '<S65>/Cos1'
     */
    rtb_B_err = arm_cos_f32(Controller_U.INS_Out.phi) * arm_cos_f32
      (Controller_U.INS_Out.theta);

    /* Saturate: '<S65>/Saturation1' */
    if (rtb_B_err > 1.0F) {
      rtb_Saturation_lu = 1.0F;
    } else if (rtb_B_err < 0.5F) {
      rtb_Saturation_lu = 0.5F;
    } else {
      rtb_Saturation_lu = rtb_B_err;
    }

    /* End of Saturate: '<S65>/Saturation1' */

    /* Gain: '<S65>/Gain' */
    rtb_B_err *= 2.0F;

    /* Saturate: '<S65>/Saturation' */
    if (rtb_B_err > 1.0F) {
      rtb_B_err = 1.0F;
    } else {
      if (rtb_B_err < 0.0F) {
        rtb_B_err = 0.0F;
      }
    }

    /* End of Saturate: '<S65>/Saturation' */

    /* Product: '<S65>/Multiply1' incorporates:
     *  Constant: '<S65>/Constant'
     *  Product: '<S65>/Divide'
     */
    rtb_B_err *= 1.0F / rtb_Saturation_lu * rtb_Gain_it;

    /* Outputs for Atomic SubSystem: '<S9>/Quadcopter_x' */
    /* MultiPortSwitch: '<S59>/Multiport Switch' incorporates:
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S22>/Multiply'
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
      /* Switch: '<S25>/Switch' incorporates:
       *  Gain: '<S25>/Gain1'
       */
      if (Controller_U.FMS_Out.reset > 0) {
        rtb_Sum = 0.0F;
        rtb_Saturation_lu = 0.0F;
        rtb_rate_err_B_idx_2 = 0.0F;
      } else {
        rtb_Sum = rtb_Multiply1;
        rtb_Saturation_lu = rtb_Gain_a_idx_1;
        rtb_rate_err_B_idx_2 = rtb_Gain_a_idx_2;
      }

      /* End of Switch: '<S25>/Switch' */

      /* Product: '<S22>/Multiply' incorporates:
       *  Constant: '<S22>/gain1'
       */
      rtb_Gain_it = CONTROL_PARAM.MC_ROLL_RATE_D * rtb_Sum;

      /* Saturate: '<S22>/Saturation' */
      if (rtb_Gain_it > CONTROL_PARAM.MC_RATE_D_MAX) {
        rtb_Gain_it = CONTROL_PARAM.MC_RATE_D_MAX;
      } else {
        if (rtb_Gain_it < CONTROL_PARAM.MC_RATE_D_MIN) {
          rtb_Gain_it = CONTROL_PARAM.MC_RATE_D_MIN;
        }
      }

      rtb_Sum = rtb_Gain_it;

      /* Product: '<S22>/Multiply' incorporates:
       *  Constant: '<S22>/gain2'
       */
      rtb_Gain_it = CONTROL_PARAM.MC_PITCH_RATE_D * rtb_Saturation_lu;

      /* Saturate: '<S22>/Saturation' */
      if (rtb_Gain_it > CONTROL_PARAM.MC_RATE_D_MAX) {
        rtb_Gain_it = CONTROL_PARAM.MC_RATE_D_MAX;
      } else {
        if (rtb_Gain_it < CONTROL_PARAM.MC_RATE_D_MIN) {
          rtb_Gain_it = CONTROL_PARAM.MC_RATE_D_MIN;
        }
      }

      rtb_Saturation_lu = rtb_Gain_it;

      /* Product: '<S22>/Multiply' incorporates:
       *  Constant: '<S22>/gain3'
       */
      rtb_Gain_it = CONTROL_PARAM.MC_YAW_RATE_D * rtb_rate_err_B_idx_2;

      /* Saturate: '<S22>/Saturation' */
      if (rtb_Gain_it > CONTROL_PARAM.MC_RATE_D_MAX) {
        rtb_Gain_it = CONTROL_PARAM.MC_RATE_D_MAX;
      } else {
        if (rtb_Gain_it < CONTROL_PARAM.MC_RATE_D_MIN) {
          rtb_Gain_it = CONTROL_PARAM.MC_RATE_D_MIN;
        }
      }

      /* Switch: '<S58>/Switch' incorporates:
       *  Constant: '<S62>/Constant'
       *  Logic: '<S58>/Logical Operator'
       *  RelationalOperator: '<S61>/Compare'
       *  RelationalOperator: '<S62>/Compare'
       *  Saturate: '<S64>/Saturation'
       *  Switch: '<S58>/Switch1'
       */
      if ((rtb_BitwiseAND == 1) || (rtb_BitwiseAND == 2) || (rtb_BitwiseAND == 3))
      {
        rtb_DataTypeConversion_k = Controller_U.FMS_Out.throttle_cmd;
      } else if (rtb_BitwiseAND == 6) {
        /* Switch: '<S63>/Switch' incorporates:
         *  Constant: '<S60>/Constant1'
         *  DataTypeConversion: '<S60>/Data Type Conversion'
         *  Gain: '<S60>/Gain1'
         *  S-Function (sfix_bitop): '<S63>/cmd_throttle valid'
         *  Saturate: '<S64>/Saturation'
         *  Sum: '<S60>/Sum1'
         *  Switch: '<S58>/Switch1'
         */
        if ((Controller_U.FMS_Out.cmd_mask & 4096) > 0) {
          rtb_DataTypeConversion_k = Controller_U.FMS_Out.throttle_cmd;
        } else {
          if (rtb_B_err > 0.35F) {
            /* Saturate: '<S64>/Saturation' */
            rtb_B_err = 0.35F;
          } else {
            if (rtb_B_err < -0.35F) {
              /* Saturate: '<S64>/Saturation' */
              rtb_B_err = -0.35F;
            }
          }

          /* Sum: '<S60>/Sum' incorporates:
           *  Constant: '<S60>/hover_throttle'
           *  Saturate: '<S64>/Saturation'
           */
          rtb_Subtract3_o = rtb_B_err + CONTROL_PARAM.MC_HOVER_THRO;

          /* Saturate: '<S60>/Saturation' */
          if (rtb_Subtract3_o > 1.0F) {
            rtb_Subtract3_o = 1.0F;
          } else {
            if (rtb_Subtract3_o < 0.0F) {
              rtb_Subtract3_o = 0.0F;
            }
          }

          rtb_DataTypeConversion_k = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
            rtb_Subtract3_o), 4.2949673E+9F) + 1000U);
        }

        /* End of Switch: '<S63>/Switch' */
      } else {
        if (rtb_B_err > 0.35F) {
          /* Saturate: '<S64>/Saturation' */
          rtb_B_err = 0.35F;
        } else {
          if (rtb_B_err < -0.35F) {
            /* Saturate: '<S64>/Saturation' */
            rtb_B_err = -0.35F;
          }
        }

        /* Sum: '<S60>/Sum' incorporates:
         *  Constant: '<S60>/hover_throttle'
         *  Saturate: '<S64>/Saturation'
         */
        rtb_Subtract3_o = rtb_B_err + CONTROL_PARAM.MC_HOVER_THRO;

        /* Saturate: '<S60>/Saturation' */
        if (rtb_Subtract3_o > 1.0F) {
          rtb_Subtract3_o = 1.0F;
        } else {
          if (rtb_Subtract3_o < 0.0F) {
            rtb_Subtract3_o = 0.0F;
          }
        }

        /* Switch: '<S58>/Switch1' incorporates:
         *  Constant: '<S60>/Constant1'
         *  DataTypeConversion: '<S60>/Data Type Conversion'
         *  Gain: '<S60>/Gain1'
         *  Sum: '<S60>/Sum1'
         */
        rtb_DataTypeConversion_k = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          rtb_Subtract3_o), 4.2949673E+9F) + 1000U);
      }

      /* End of Switch: '<S58>/Switch' */

      /* Saturate: '<S57>/Saturation1' incorporates:
       *  Constant: '<S24>/gain1'
       *  Constant: '<S24>/gain2'
       *  Constant: '<S24>/gain3'
       *  DiscreteIntegrator: '<S21>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S23>/Discrete-Time Integrator'
       *  Product: '<S24>/Multiply'
       *  Sum: '<S19>/Add'
       */
      rtb_Subtract3_o = (CONTROL_PARAM.MC_ROLL_RATE_P *
                         Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] +
                         Controller_DW.DiscreteTimeIntegrator_DSTATE[0]) +
        rtb_Sum;
      if (rtb_Subtract3_o > 1.0F) {
        rtb_Subtract3_o = 1.0F;
      } else {
        if (rtb_Subtract3_o < -1.0F) {
          rtb_Subtract3_o = -1.0F;
        }
      }

      rtb_Abs = (CONTROL_PARAM.MC_PITCH_RATE_P *
                 Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] +
                 Controller_DW.DiscreteTimeIntegrator_DSTATE[1]) +
        rtb_Saturation_lu;
      if (rtb_Abs > 1.0F) {
        rtb_Abs = 1.0F;
      } else {
        if (rtb_Abs < -1.0F) {
          rtb_Abs = -1.0F;
        }
      }

      rtb_Switch_h = (CONTROL_PARAM.MC_YAW_RATE_P *
                      Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] +
                      Controller_DW.DiscreteTimeIntegrator_DSTATE[2]) +
        rtb_Gain_it;
      if (rtb_Switch_h > 1.0F) {
        rtb_Switch_h = 1.0F;
      } else {
        if (rtb_Switch_h < -1.0F) {
          rtb_Switch_h = -1.0F;
        }
      }

      /* End of Saturate: '<S57>/Saturation1' */

      /* Product: '<S57>/Multiply' */
      for (i = 0; i < 4; i++) {
        /* Saturate: '<S57>/Saturation' incorporates:
         *  Constant: '<S57>/Effective_Matrix'
         *  Gain: '<S57>/Gain'
         *  Sum: '<S57>/Add'
         */
        rtb_Saturation_c = fmodf(floorf(1000.0F * (Controller_ConstP.pooled12[i
          + 8] * rtb_Switch_h + (Controller_ConstP.pooled12[i + 4] * rtb_Abs +
          Controller_ConstP.pooled12[i] * rtb_Subtract3_o)) + (real32_T)
          rtb_DataTypeConversion_k), 65536.0F);
        u0 = (uint16_T)(rtb_Saturation_c < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                        (uint16_T)-rtb_Saturation_c : (int32_T)(uint16_T)
                        rtb_Saturation_c);
        if (u0 > 1900) {
          rtb_MultiportSwitch_o[i] = 1900U;
        } else if (u0 < 1100) {
          rtb_MultiportSwitch_o[i] = 1100U;
        } else {
          rtb_MultiportSwitch_o[i] = u0;
        }

        /* End of Saturate: '<S57>/Saturation' */
      }

      /* End of Product: '<S57>/Multiply' */
      break;

     default:
      rtb_MultiportSwitch_o[0] = 1000U;
      rtb_MultiportSwitch_o[1] = 1000U;
      rtb_MultiportSwitch_o[2] = 1000U;
      rtb_MultiportSwitch_o[3] = 1000U;
      break;
    }

    /* End of MultiPortSwitch: '<S59>/Multiport Switch' */

    /* Outport: '<Root>/Control_Out' incorporates:
     *  Constant: '<S59>/Disarm1'
     *  Reshape: '<S59>/Reshape'
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

    /* End of Outputs for SubSystem: '<S9>/Quadcopter_x' */

    /* Product: '<S48>/Multiply1' incorporates:
     *  Constant: '<S48>/const1'
     *  DiscreteIntegrator: '<S45>/Integrator'
     */
    rtb_Gain_il = Controller_DW.Integrator_DSTATE[0] * 0.05F;
    rtb_Sum = Controller_DW.Integrator_DSTATE[1] * 0.05F;

    /* Sum: '<S48>/Add' incorporates:
     *  DiscreteIntegrator: '<S45>/Integrator1'
     *  Inport: '<Root>/FMS_Out'
     *  Sum: '<S45>/Subtract'
     */
    rtb_Saturation_lu = (Controller_DW.Integrator1_DSTATE[0] -
                         Controller_U.FMS_Out.u_cmd) + rtb_Gain_il;
    rtb_B_err = (Controller_DW.Integrator1_DSTATE[1] -
                 Controller_U.FMS_Out.v_cmd) + rtb_Sum;

    /* Signum: '<S48>/Sign' */
    if (rtb_Saturation_lu < 0.0F) {
      rtb_Gain_it = -1.0F;
    } else if (rtb_Saturation_lu > 0.0F) {
      rtb_Gain_it = 1.0F;
    } else {
      rtb_Gain_it = rtb_Saturation_lu;
    }

    /* Sum: '<S48>/Add2' incorporates:
     *  Abs: '<S48>/Abs'
     *  Gain: '<S48>/Gain'
     *  Gain: '<S48>/Gain1'
     *  Product: '<S48>/Multiply2'
     *  Product: '<S48>/Multiply3'
     *  Signum: '<S48>/Sign'
     *  Sqrt: '<S48>/Sqrt'
     *  Sum: '<S48>/Add1'
     *  Sum: '<S48>/Subtract'
     */
    rtb_Gain_it = (sqrtf((8.0F * fabsf(rtb_Saturation_lu) + Controller_ConstB.d)
                         * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
      rtb_Gain_it + rtb_Gain_il;

    /* Sum: '<S48>/Add3' incorporates:
     *  Signum: '<S48>/Sign'
     */
    rtb_Subtract3_o = rtb_Saturation_lu + Controller_ConstB.d;

    /* Sum: '<S48>/Subtract1' incorporates:
     *  Signum: '<S48>/Sign'
     */
    rtb_rate_err_B_idx_2 = rtb_Saturation_lu - Controller_ConstB.d;

    /* Signum: '<S48>/Sign1' */
    if (rtb_Subtract3_o < 0.0F) {
      rtb_Subtract3_o = -1.0F;
    } else {
      if (rtb_Subtract3_o > 0.0F) {
        rtb_Subtract3_o = 1.0F;
      }
    }

    /* Signum: '<S48>/Sign2' */
    if (rtb_rate_err_B_idx_2 < 0.0F) {
      rtb_rate_err_B_idx_2 = -1.0F;
    } else {
      if (rtb_rate_err_B_idx_2 > 0.0F) {
        rtb_rate_err_B_idx_2 = 1.0F;
      }
    }

    /* Sum: '<S48>/Add2' incorporates:
     *  Gain: '<S48>/Gain2'
     *  Product: '<S48>/Multiply4'
     *  Signum: '<S48>/Sign'
     *  Sum: '<S48>/Add4'
     *  Sum: '<S48>/Add5'
     *  Sum: '<S48>/Subtract2'
     */
    rtb_Gain_il = ((rtb_Saturation_lu - rtb_Gain_it) + rtb_Gain_il) *
      ((rtb_Subtract3_o - rtb_rate_err_B_idx_2) * 0.5F) + rtb_Gain_it;

    /* Signum: '<S48>/Sign' */
    if (rtb_B_err < 0.0F) {
      rtb_Gain_it = -1.0F;
    } else if (rtb_B_err > 0.0F) {
      rtb_Gain_it = 1.0F;
    } else {
      rtb_Gain_it = rtb_B_err;
    }

    /* Sum: '<S48>/Add2' incorporates:
     *  Abs: '<S48>/Abs'
     *  Gain: '<S48>/Gain'
     *  Gain: '<S48>/Gain1'
     *  Product: '<S48>/Multiply2'
     *  Product: '<S48>/Multiply3'
     *  Signum: '<S48>/Sign'
     *  Sqrt: '<S48>/Sqrt'
     *  Sum: '<S48>/Add1'
     *  Sum: '<S48>/Subtract'
     */
    rtb_Gain_it = (sqrtf((8.0F * fabsf(rtb_B_err) + Controller_ConstB.d) *
                         Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
      rtb_Gain_it + rtb_Sum;

    /* Sum: '<S48>/Add3' incorporates:
     *  Signum: '<S48>/Sign'
     */
    rtb_Subtract3_o = rtb_B_err + Controller_ConstB.d;

    /* Sum: '<S48>/Subtract1' incorporates:
     *  Signum: '<S48>/Sign'
     */
    rtb_rate_err_B_idx_2 = rtb_B_err - Controller_ConstB.d;

    /* Signum: '<S48>/Sign1' */
    if (rtb_Subtract3_o < 0.0F) {
      rtb_Subtract3_o = -1.0F;
    } else {
      if (rtb_Subtract3_o > 0.0F) {
        rtb_Subtract3_o = 1.0F;
      }
    }

    /* Signum: '<S48>/Sign2' */
    if (rtb_rate_err_B_idx_2 < 0.0F) {
      rtb_rate_err_B_idx_2 = -1.0F;
    } else {
      if (rtb_rate_err_B_idx_2 > 0.0F) {
        rtb_rate_err_B_idx_2 = 1.0F;
      }
    }

    /* Sum: '<S48>/Add5' incorporates:
     *  Gain: '<S48>/Gain2'
     *  Product: '<S48>/Multiply4'
     *  Signum: '<S48>/Sign'
     *  Sum: '<S48>/Add2'
     *  Sum: '<S48>/Add4'
     *  Sum: '<S48>/Subtract2'
     */
    rtb_Gain_it += ((rtb_B_err - rtb_Gain_it) + rtb_Sum) * ((rtb_Subtract3_o -
      rtb_rate_err_B_idx_2) * 0.5F);

    /* Product: '<S69>/Multiply1' incorporates:
     *  Constant: '<S69>/const1'
     *  DiscreteIntegrator: '<S68>/Integrator'
     */
    rtb_Saturation_lu = Controller_DW.Integrator_DSTATE_j * 0.05F;

    /* Sum: '<S69>/Add' incorporates:
     *  DiscreteIntegrator: '<S68>/Integrator1'
     *  Inport: '<Root>/FMS_Out'
     *  Sum: '<S68>/Subtract'
     */
    rtb_B_err = (Controller_DW.Integrator1_DSTATE_e - Controller_U.FMS_Out.w_cmd)
      + rtb_Saturation_lu;

    /* Signum: '<S69>/Sign' */
    if (rtb_B_err < 0.0F) {
      rtb_Sum = -1.0F;
    } else if (rtb_B_err > 0.0F) {
      rtb_Sum = 1.0F;
    } else {
      rtb_Sum = rtb_B_err;
    }

    /* End of Signum: '<S69>/Sign' */

    /* Sum: '<S69>/Add2' incorporates:
     *  Abs: '<S69>/Abs'
     *  Gain: '<S69>/Gain'
     *  Gain: '<S69>/Gain1'
     *  Product: '<S69>/Multiply2'
     *  Product: '<S69>/Multiply3'
     *  Sqrt: '<S69>/Sqrt'
     *  Sum: '<S69>/Add1'
     *  Sum: '<S69>/Subtract'
     */
    rtb_Sum = (sqrtf((8.0F * fabsf(rtb_B_err) + Controller_ConstB.d_i) *
                     Controller_ConstB.d_i) - Controller_ConstB.d_i) * 0.5F *
      rtb_Sum + rtb_Saturation_lu;

    /* Sum: '<S69>/Add4' */
    rtb_Saturation_lu += rtb_B_err - rtb_Sum;

    /* Sum: '<S69>/Add3' */
    rtb_Subtract3_o = rtb_B_err + Controller_ConstB.d_i;

    /* Sum: '<S69>/Subtract1' */
    rtb_B_err -= Controller_ConstB.d_i;

    /* Signum: '<S69>/Sign1' */
    if (rtb_Subtract3_o < 0.0F) {
      rtb_Subtract3_o = -1.0F;
    } else {
      if (rtb_Subtract3_o > 0.0F) {
        rtb_Subtract3_o = 1.0F;
      }
    }

    /* End of Signum: '<S69>/Sign1' */

    /* Signum: '<S69>/Sign2' */
    if (rtb_B_err < 0.0F) {
      rtb_B_err = -1.0F;
    } else {
      if (rtb_B_err > 0.0F) {
        rtb_B_err = 1.0F;
      }
    }

    /* End of Signum: '<S69>/Sign2' */

    /* Sum: '<S69>/Add5' incorporates:
     *  Gain: '<S69>/Gain2'
     *  Product: '<S69>/Multiply4'
     *  Sum: '<S69>/Subtract2'
     */
    rtb_Sum += (rtb_Subtract3_o - rtb_B_err) * 0.5F * rtb_Saturation_lu;

    /* Update for DiscreteIntegrator: '<S23>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S23>/gain1'
     *  Constant: '<S23>/gain2'
     *  Constant: '<S23>/gain3'
     *  DiscreteIntegrator: '<S21>/Discrete-Time Integrator5'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S23>/Multiply'
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

    /* End of Update for DiscreteIntegrator: '<S23>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S50>/Discrete-Time Integrator' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.DiscreteTimeIntegrator_PrevRe_p = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S52>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;

    /* Update for DiscreteIntegrator: '<S45>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S45>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE[0] += 0.002F *
      Controller_DW.Integrator_DSTATE[0];

    /* Update for DiscreteIntegrator: '<S50>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S50>/ki'
     *  Product: '<S50>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0] +=
      CONTROL_PARAM.MC_VEL_XY_I * rtb_att_error_B_rad_idx_0 * 0.002F;
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

    /* Update for DiscreteIntegrator: '<S52>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] += 0.002F *
      rtb_Saturation1_h_idx_0;

    /* Update for DiscreteIntegrator: '<S45>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S45>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE[1] += 0.002F *
      Controller_DW.Integrator_DSTATE[1];

    /* Update for DiscreteIntegrator: '<S50>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S50>/ki'
     *  Product: '<S50>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1] +=
      CONTROL_PARAM.MC_VEL_XY_I * rtb_att_error_B_rad_idx_1 * 0.002F;
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

    /* Update for DiscreteIntegrator: '<S52>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] += 0.002F * rtb_Divide_i;
    Controller_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S21>/Discrete-Time Integrator5' */
    Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;

    /* Update for DiscreteIntegrator: '<S25>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 0U;

    /* Update for DiscreteIntegrator: '<S21>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S21>/Gain'
     *  Sum: '<S21>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] +=
      (rtb_rate_error_B_radPs_b_idx_0 -
       Controller_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S25>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[0] += 0.002F * rtb_Multiply1;

    /* Update for DiscreteIntegrator: '<S21>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S21>/Gain'
     *  Sum: '<S21>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] +=
      (rtb_rate_error_B_radPs_b_idx_1 -
       Controller_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S25>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[1] += 0.002F *
      rtb_Gain_a_idx_1;

    /* Update for DiscreteIntegrator: '<S21>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S21>/Gain'
     *  Sum: '<S21>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] +=
      (rtb_rate_error_B_radPs_b_idx_2 -
       Controller_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S25>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[2] += 0.002F *
      rtb_Gain_a_idx_2;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_k = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S68>/Integrator1' incorporates:
     *  DiscreteIntegrator: '<S68>/Integrator'
     */
    Controller_DW.Integrator1_DSTATE_e += 0.002F *
      Controller_DW.Integrator_DSTATE_j;

    /* Update for DiscreteIntegrator: '<S71>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S71>/ki'
     *  Inport: '<Root>/FMS_Out'
     *  Product: '<S71>/Multiply'
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

    /* End of Update for DiscreteIntegrator: '<S71>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S73>/Discrete-Time Integrator1' incorporates:
     *  Inport: '<Root>/FMS_Out'
     */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_i += 0.002F * rtb_Gain_ms;
    Controller_DW.DiscreteTimeIntegrator1_Prev_ks = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Signum: '<S48>/Sign3' incorporates:
     *  Product: '<S48>/Divide'
     *  Sum: '<S48>/Add6'
     */
    rtb_Subtract3_o = rtb_Gain_il + Controller_ConstB.d;

    /* Signum: '<S48>/Sign4' incorporates:
     *  Product: '<S48>/Divide'
     *  Sum: '<S48>/Subtract3'
     */
    rtb_Multiply1 = rtb_Gain_il - Controller_ConstB.d;

    /* Signum: '<S48>/Sign5' incorporates:
     *  Product: '<S48>/Divide'
     */
    if (rtb_Gain_il < 0.0F) {
      rtb_rate_error_B_radPs_b_idx_0 = -1.0F;
    } else if (rtb_Gain_il > 0.0F) {
      rtb_rate_error_B_radPs_b_idx_0 = 1.0F;
    } else {
      rtb_rate_error_B_radPs_b_idx_0 = rtb_Gain_il;
    }

    /* Signum: '<S48>/Sign3' */
    if (rtb_Subtract3_o < 0.0F) {
      rtb_Subtract3_o = -1.0F;
    } else {
      if (rtb_Subtract3_o > 0.0F) {
        rtb_Subtract3_o = 1.0F;
      }
    }

    /* Signum: '<S48>/Sign4' */
    if (rtb_Multiply1 < 0.0F) {
      rtb_Multiply1 = -1.0F;
    } else {
      if (rtb_Multiply1 > 0.0F) {
        rtb_Multiply1 = 1.0F;
      }
    }

    /* Signum: '<S48>/Sign6' incorporates:
     *  Product: '<S48>/Divide'
     */
    if (rtb_Gain_il < 0.0F) {
      rtb_rate_error_B_radPs_b_idx_1 = -1.0F;
    } else if (rtb_Gain_il > 0.0F) {
      rtb_rate_error_B_radPs_b_idx_1 = 1.0F;
    } else {
      rtb_rate_error_B_radPs_b_idx_1 = rtb_Gain_il;
    }

    /* Update for DiscreteIntegrator: '<S45>/Integrator' incorporates:
     *  Constant: '<S48>/const'
     *  Gain: '<S48>/Gain3'
     *  Product: '<S48>/Divide'
     *  Product: '<S48>/Multiply5'
     *  Product: '<S48>/Multiply6'
     *  Sum: '<S48>/Subtract4'
     *  Sum: '<S48>/Subtract5'
     *  Sum: '<S48>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE[0] += ((rtb_Gain_il / Controller_ConstB.d -
      rtb_rate_error_B_radPs_b_idx_0) * Controller_ConstB.Gain4 *
      ((rtb_Subtract3_o - rtb_Multiply1) * 0.5F) -
      rtb_rate_error_B_radPs_b_idx_1 * 58.836F) * 0.002F;

    /* Signum: '<S48>/Sign3' incorporates:
     *  Sum: '<S48>/Add6'
     */
    rtb_Subtract3_o = rtb_Gain_it + Controller_ConstB.d;

    /* Signum: '<S48>/Sign4' incorporates:
     *  Sum: '<S48>/Subtract3'
     */
    rtb_Multiply1 = rtb_Gain_it - Controller_ConstB.d;

    /* Signum: '<S48>/Sign5' */
    if (rtb_Gain_it < 0.0F) {
      rtb_rate_error_B_radPs_b_idx_0 = -1.0F;
    } else if (rtb_Gain_it > 0.0F) {
      rtb_rate_error_B_radPs_b_idx_0 = 1.0F;
    } else {
      rtb_rate_error_B_radPs_b_idx_0 = rtb_Gain_it;
    }

    /* Signum: '<S48>/Sign3' */
    if (rtb_Subtract3_o < 0.0F) {
      rtb_Subtract3_o = -1.0F;
    } else {
      if (rtb_Subtract3_o > 0.0F) {
        rtb_Subtract3_o = 1.0F;
      }
    }

    /* Signum: '<S48>/Sign4' */
    if (rtb_Multiply1 < 0.0F) {
      rtb_Multiply1 = -1.0F;
    } else {
      if (rtb_Multiply1 > 0.0F) {
        rtb_Multiply1 = 1.0F;
      }
    }

    /* Signum: '<S48>/Sign6' */
    if (rtb_Gain_it < 0.0F) {
      rtb_rate_error_B_radPs_b_idx_1 = -1.0F;
    } else if (rtb_Gain_it > 0.0F) {
      rtb_rate_error_B_radPs_b_idx_1 = 1.0F;
    } else {
      rtb_rate_error_B_radPs_b_idx_1 = rtb_Gain_it;
    }

    /* Update for DiscreteIntegrator: '<S45>/Integrator' incorporates:
     *  Constant: '<S48>/const'
     *  Gain: '<S48>/Gain3'
     *  Product: '<S48>/Divide'
     *  Product: '<S48>/Multiply5'
     *  Product: '<S48>/Multiply6'
     *  Sum: '<S48>/Subtract4'
     *  Sum: '<S48>/Subtract5'
     *  Sum: '<S48>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE[1] += ((rtb_Gain_it / Controller_ConstB.d -
      rtb_rate_error_B_radPs_b_idx_0) * Controller_ConstB.Gain4 *
      ((rtb_Subtract3_o - rtb_Multiply1) * 0.5F) -
      rtb_rate_error_B_radPs_b_idx_1 * 58.836F) * 0.002F;

    /* Signum: '<S69>/Sign6' incorporates:
     *  Signum: '<S69>/Sign5'
     */
    if (rtb_Sum < 0.0F) {
      rtb_rate_error_B_radPs_b_idx_0 = -1.0F;

      /* Signum: '<S69>/Sign5' */
      rtb_rate_error_B_radPs_b_idx_1 = -1.0F;
    } else if (rtb_Sum > 0.0F) {
      rtb_rate_error_B_radPs_b_idx_0 = 1.0F;

      /* Signum: '<S69>/Sign5' */
      rtb_rate_error_B_radPs_b_idx_1 = 1.0F;
    } else {
      rtb_rate_error_B_radPs_b_idx_0 = rtb_Sum;

      /* Signum: '<S69>/Sign5' */
      rtb_rate_error_B_radPs_b_idx_1 = rtb_Sum;
    }

    /* End of Signum: '<S69>/Sign6' */

    /* Sum: '<S69>/Add6' */
    rtb_Subtract3_o = rtb_Sum + Controller_ConstB.d_i;

    /* Sum: '<S69>/Subtract3' */
    rtb_Multiply1 = rtb_Sum - Controller_ConstB.d_i;

    /* Signum: '<S69>/Sign3' */
    if (rtb_Subtract3_o < 0.0F) {
      rtb_Subtract3_o = -1.0F;
    } else {
      if (rtb_Subtract3_o > 0.0F) {
        rtb_Subtract3_o = 1.0F;
      }
    }

    /* End of Signum: '<S69>/Sign3' */

    /* Signum: '<S69>/Sign4' */
    if (rtb_Multiply1 < 0.0F) {
      rtb_Multiply1 = -1.0F;
    } else {
      if (rtb_Multiply1 > 0.0F) {
        rtb_Multiply1 = 1.0F;
      }
    }

    /* End of Signum: '<S69>/Sign4' */

    /* Update for DiscreteIntegrator: '<S68>/Integrator' incorporates:
     *  Constant: '<S69>/const'
     *  Gain: '<S69>/Gain3'
     *  Product: '<S69>/Divide'
     *  Product: '<S69>/Multiply5'
     *  Product: '<S69>/Multiply6'
     *  Sum: '<S69>/Subtract4'
     *  Sum: '<S69>/Subtract5'
     *  Sum: '<S69>/Subtract6'
     */
    Controller_DW.Integrator_DSTATE_j += ((rtb_Sum / Controller_ConstB.d_i -
      rtb_rate_error_B_radPs_b_idx_1) * Controller_ConstB.Gain4_p *
      ((rtb_Subtract3_o - rtb_Multiply1) * 0.5F) -
      rtb_rate_error_B_radPs_b_idx_0 * 78.448F) * 0.002F;

    /* End of Outputs for SubSystem: '<S2>/MC_Controller' */
    break;
  }

  /* End of SwitchCase: '<S7>/Switch Case1' */

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

  /* Start for SwitchCase: '<S7>/Switch Case1' */
  Controller_DW.SwitchCase1_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S2>/VTOL_Controller' */
  /* Start for Constant: '<S119>/Constant' */
  Controller_B.Constant_m = CONTROL_PARAM.MC_VEL_Z_I_MIN;

  /* End of Start for SubSystem: '<S2>/VTOL_Controller' */

  /* Start for IfAction SubSystem: '<S2>/MC_Controller' */
  /* Start for Constant: '<S71>/Constant' */
  Controller_B.Constant = CONTROL_PARAM.MC_VEL_Z_I_MIN;

  /* End of Start for SubSystem: '<S2>/MC_Controller' */

  /* SystemInitialize for IfAction SubSystem: '<S2>/VTOL_Controller' */
  /* InitializeConditions for DiscreteIntegrator: '<S124>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_e = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S123>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_o = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S116>/Integrator1' */
  Controller_DW.Integrator1_DSTATE_i = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S119>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S119>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S121>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_i = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_h = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S154>/ ' */
  Controller_DW._DSTATE = Controller_ConstB.Zero1;
  if (Controller_DW._DSTATE >= CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
    Controller_DW._DSTATE = CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
  } else {
    if (Controller_DW._DSTATE <= -CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
      Controller_DW._DSTATE = -CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
    }
  }

  Controller_DW._PrevResetState = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S154>/ ' */

  /* InitializeConditions for DiscreteIntegrator: '<S155>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_f = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_b = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S89>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_b = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S91>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_PrevRe_o = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S93>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_h = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_l = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S122>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_g = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S91>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S91>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S134>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S91>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S134>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S157>/ ' */
  Controller_DW._DSTATE_d = Controller_ConstB.Zero;
  if (Controller_DW._DSTATE_d >= 0.3F) {
    Controller_DW._DSTATE_d = 0.3F;
  } else {
    if (Controller_DW._DSTATE_d <= -0.3F) {
      Controller_DW._DSTATE_d = -0.3F;
    }
  }

  Controller_DW._PrevResetState_e = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S157>/ ' */

  /* InitializeConditions for DiscreteIntegrator: '<S158>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_L_h0 = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_d = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S116>/Integrator' */
  Controller_DW.Integrator_DSTATE_f = 0.0F;

  /* SystemInitialize for Atomic SubSystem: '<S161>/VTOL1' */
  /* InitializeConditions for Delay: '<S167>/Delay' */
  Controller_DW.Delay_DSTATE = 0U;

  /* End of SystemInitialize for SubSystem: '<S161>/VTOL1' */
  /* End of SystemInitialize for SubSystem: '<S2>/VTOL_Controller' */

  /* SystemInitialize for IfAction SubSystem: '<S2>/MC_Controller' */
  /* InitializeConditions for DiscreteIntegrator: '<S23>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S23>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S45>/Integrator1' */
  Controller_DW.Integrator1_DSTATE[0] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S50>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S45>/Integrator1' */
  Controller_DW.Integrator1_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S50>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S52>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S21>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S25>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_k = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S68>/Integrator1' */
  Controller_DW.Integrator1_DSTATE_e = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S71>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S71>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S73>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_d = 1U;
  Controller_DW.DiscreteTimeIntegrator1_Prev_ks = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S45>/Integrator' */
  Controller_DW.Integrator_DSTATE[0] = 0.0F;
  Controller_DW.Integrator_DSTATE[1] = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S68>/Integrator' */
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
