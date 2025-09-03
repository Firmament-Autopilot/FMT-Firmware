/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.654
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Sep  3 11:56:36 2025
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
struct_bbisFpyguPkQQvdqSWKvqB CONTROL_PARAM = {
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
  0.0F,
  0.0F,
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
  -0.3F,
  0.3F,
  1.57079637F,
  3.14159274F,
  0.785398185F,
  17.0F,
  0.2F,
  1.0F,
  1.0F,
  1.0F,
  0.0F,
  0.5F,
  0.1F,
  0.1F,
  0.15F,
  0.5F,
  0.2F,
  0.2F,
  0.2F,
  0.0F,
  0.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  2.0F,
  0.2F,
  0.0F,
  0.0F,
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
                                        *   '<S66>/Saturation'
                                        *   '<S67>/Gain'
                                        *   '<S67>/Gain1'
                                        *   '<S67>/balabnce_ratio2'
                                        *   '<S67>/balance_ratio'
                                        *   '<S67>/pitch_ff'
                                        *   '<S67>/thorttle_ff'
                                        *   '<S67>/ucmd2pitch'
                                        *   '<S67>/ucmd2thor'
                                        *   '<S67>/wcmd2pitch'
                                        *   '<S67>/wcmd2thor'
                                        *   '<S156>/hover_throttle'
                                        *   '<S41>/hover_throttle'
                                        *   '<S69>/FF'
                                        *   '<S87>/P_control'
                                        *   '<S88>/P_control'
                                        *   '<S89>/Kv'
                                        *   '<S138>/Saturation'
                                        *   '<S171>/Bias1'
                                        *   '<S171>/Bias2'
                                        *   '<S171>/Bias3'
                                        *   '<S171>/Bias4'
                                        *   '<S171>/Saturation1'
                                        *   '<S172>/Constant'
                                        *   '<S172>/Constant1'
                                        *   '<S172>/Saturation'
                                        *   '<S187>/Bias1'
                                        *   '<S187>/Bias2'
                                        *   '<S187>/Bias3'
                                        *   '<S187>/Bias4'
                                        *   '<S19>/Saturation2'
                                        *   '<S19>/Saturation3'
                                        *   '<S19>/Saturation4'
                                        *   '<S73>/trim_speed'
                                        *   '<S74>/trim_speed'
                                        *   '<S78>/Saturation'
                                        *   '<S95>/Gain'
                                        *   '<S96>/ '
                                        *   '<S96>/Gain3'
                                        *   '<S98>/Gain'
                                        *   '<S99>/Gain'
                                        *   '<S112>/Saturation'
                                        *   '<S112>/Saturation1'
                                        *   '<S112>/Saturation2'
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
                                        *   '<S176>/Constant1'
                                        *   '<S176>/Constant12'
                                        *   '<S176>/Constant2'
                                        *   '<S176>/Constant7'
                                        *   '<S185>/Bias'
                                        *   '<S185>/Bias1'
                                        *   '<S185>/Bias2'
                                        *   '<S185>/Bias3'
                                        *   '<S186>/Bias'
                                        *   '<S186>/Bias1'
                                        *   '<S186>/Bias2'
                                        *   '<S186>/Bias3'
                                        *   '<S190>/Constant1'
                                        *   '<S190>/Constant11'
                                        *   '<S190>/Constant12'
                                        *   '<S190>/Constant2'
                                        *   '<S190>/Constant7'
                                        *   '<S190>/Constant8'
                                        *   '<S194>/Bias'
                                        *   '<S194>/Bias1'
                                        *   '<S194>/Bias2'
                                        *   '<S194>/Bias3'
                                        *   '<S195>/Bias'
                                        *   '<S195>/Bias1'
                                        *   '<S195>/Bias2'
                                        *   '<S195>/Bias3'
                                        *   '<S21>/Gain'
                                        *   '<S21>/Gain1'
                                        *   '<S33>/Constant1'
                                        *   '<S33>/Constant2'
                                        *   '<S47>/kd'
                                        *   '<S47>/Saturation'
                                        *   '<S48>/Constant'
                                        *   '<S48>/ki'
                                        *   '<S48>/Discrete-Time Integrator'
                                        *   '<S49>/kp'
                                        *   '<S75>/gain1'
                                        *   '<S75>/gain2'
                                        *   '<S75>/gain3'
                                        *   '<S75>/Discrete-Time Integrator'
                                        *   '<S76>/gain1'
                                        *   '<S76>/gain2'
                                        *   '<S76>/gain3'
                                        *   '<S80>/Pitch Offset'
                                        *   '<S80>/Saturation'
                                        *   '<S81>/Constant1'
                                        *   '<S81>/Constant2'
                                        *   '<S115>/Gain'
                                        *   '<S115>/Gain1'
                                        *   '<S131>/Constant1'
                                        *   '<S131>/Constant2'
                                        *   '<S26>/gain1'
                                        *   '<S26>/gain2'
                                        *   '<S26>/gain3'
                                        *   '<S26>/Saturation'
                                        *   '<S27>/gain1'
                                        *   '<S27>/gain2'
                                        *   '<S27>/gain3'
                                        *   '<S27>/Discrete-Time Integrator'
                                        *   '<S28>/gain1'
                                        *   '<S28>/gain2'
                                        *   '<S28>/gain3'
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
  real32_T rtb_phi_cmd;
  boolean_T rtb_aux_reset;
  real32_T rtb_Abs;
  real32_T rtb_Multiply1_e;
  real32_T rtb_DiscreteTimeIntegrator5_h5;
  real32_T rtb_VdotPg;
  real32_T rtb_Cos_j;
  boolean_T rtb_Compare_nq;
  real32_T rtb_Saturation3;
  real32_T rtb_DiscreteTimeIntegrator1_i;
  real32_T rtb_Gain_ms;
  boolean_T rtb_LogicalOperator_b3;
  boolean_T rtb_LogicalOperator_g;
  real32_T rtb_VectorConcatenate_o[9];
  real32_T rtb_Multiply_ni[3];
  real32_T rtb_Square_d;
  int32_T i;
  real32_T rtb_VectorConcatenate_k[3];
  real32_T rtb_TmpSignalConversionAtMult_0;
  real32_T rtb_TmpSignalConversionAtMult_1;
  real32_T rtb_TmpSignalConversionAtMult_2;
  real32_T rtb_MultiportSwitch_idx_0;
  real32_T rtb_MultiportSwitch_idx_1;
  real32_T rtb_Switch2_n_idx_0;
  real32_T rtb_aux_att_error_B_rad_idx_0;
  real32_T rtb_aux_att_error_B_rad_idx_1;
  real32_T rtb_Divide_m_idx_0;
  real32_T rtb_Divide_m_idx_3;
  real32_T rtb_Divide_m_idx_1;
  real32_T rtb_Divide_m_idx_2;
  real32_T rtb_Saturation_j_idx_1;
  real32_T rtb_Saturation_j_idx_2;
  uint32_T tmp;
  real32_T u0_tmp;
  real32_T rtb_VectorConcatenate_k_tmp;

  /* SwitchCase: '<S7>/Switch Case1' incorporates:
   *  Constant: '<S164>/Constant'
   *  Constant: '<S48>/Constant'
   *  DataTypeConversion: '<S7>/Data Type Conversion'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S120>/Multiply'
   *  Product: '<S133>/Divide1'
   *  Product: '<S147>/Multiply'
   *  Product: '<S35>/Divide1'
   */
  rtPrevAction = Controller_DW.SwitchCase1_ActiveSubsystem;
  switch ((int32_T)Controller_U.FMS_Out.ext_state) {
   case VTOLState_Fixwing:
   case VTOLState_ForwardTrans:
   case VTOLState_BackwardTrans:
   case VTOLState_Stall:
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
      /* InitializeConditions for SwitchCase: '<S7>/Switch Case1' incorporates:
       *  DiscreteIntegrator: '<S100>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S24>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S27>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S29>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S45>/Integrator'
       *  DiscreteIntegrator: '<S45>/Integrator1'
       *  DiscreteIntegrator: '<S48>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S50>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S51>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S52>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S55>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S75>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S96>/ '
       *  DiscreteIntegrator: '<S97>/Discrete-Time Integrator1'
       *  DiscreteIntegrator: '<S99>/ '
       */
      Controller_DW.DiscreteTimeIntegrator5_IC_LO_b = 1U;
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
      Controller_DW.DiscreteTimeIntegrator5_IC_LO_e = 1U;
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
      Controller_DW.DiscreteTimeIntegrator5_IC_L_bo = 1U;
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
      Controller_DW.DiscreteTimeIntegrator5_IC_LO_o = 1U;
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
    rtb_TmpSignalConversionAtMult_2 = Controller_U.INS_Out.vd;

    /* MultiPortSwitch: '<S9>/Multiport Switch' incorporates:
     *  Constant: '<S9>/Constant'
     *  Constant: '<S9>/Constant1'
     *  Constant: '<S9>/Constant2'
     *  Constant: '<S9>/Constant6'
     */
    switch (Controller_U.FMS_Out.ext_state) {
     case 0:
      rtb_MultiportSwitch_idx_0 = 0.0F;
      rtb_MultiportSwitch_idx_1 = 1.0F;
      break;

     case 1:
      rtb_MultiportSwitch_idx_0 = 0.0F;
      rtb_MultiportSwitch_idx_1 = 1.0F;
      break;

     case 2:
      rtb_MultiportSwitch_idx_0 = 1.0F;
      rtb_MultiportSwitch_idx_1 = 0.0F;
      break;

     case 3:
      rtb_MultiportSwitch_idx_0 = 0.0F;
      rtb_MultiportSwitch_idx_1 = 1.0F;
      break;

     default:
      rtb_MultiportSwitch_idx_0 = 0.0F;
      rtb_MultiportSwitch_idx_1 = 1.0F;
      break;
    }

    /* End of MultiPortSwitch: '<S9>/Multiport Switch' */

    /* DiscreteIntegrator: '<S52>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_b != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_d = rtb_MultiportSwitch_idx_1;
    }

    /* Relay: '<S18>/Relay' incorporates:
     *  DiscreteIntegrator: '<S52>/Discrete-Time Integrator5'
     */
    if (Controller_DW.DiscreteTimeIntegrator5_DSTAT_d >= 0.3F) {
      Controller_DW.Relay_Mode = true;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator5_DSTAT_d <= 0.1F) {
        Controller_DW.Relay_Mode = false;
      }
    }

    /* Logic: '<S18>/Logical Operator' incorporates:
     *  Relay: '<S18>/Relay'
     */
    rtb_aux_reset = ((Controller_U.FMS_Out.reset != 0) ||
                     (!Controller_DW.Relay_Mode));

    /* DiscreteIntegrator: '<S27>/Discrete-Time Integrator' */
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

    /* Switch: '<S79>/Switch' incorporates:
     *  Logic: '<S79>/Logical Operator'
     *  RelationalOperator: '<S84>/Compare'
     */
    if ((Controller_U.FMS_Out.ctrl_mode == 3) || (Controller_U.FMS_Out.ctrl_mode
         == 4)) {
      rtb_phi_cmd = Controller_U.FMS_Out.phi_cmd;
    } else {
      /* Trigonometry: '<S66>/Atan' incorporates:
       *  Gain: '<S66>/g_force'
       */
      rtb_phi_cmd = atanf(0.101936802F * Controller_U.FMS_Out.ay_cmd);

      /* Saturate: '<S66>/Saturation' */
      if (rtb_phi_cmd > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_phi_cmd = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_phi_cmd < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
          rtb_phi_cmd = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
        }
      }

      /* End of Saturate: '<S66>/Saturation' */
    }

    /* End of Switch: '<S79>/Switch' */

    /* Abs: '<S67>/Abs' */
    rtb_Abs = fabsf(rtb_phi_cmd);

    /* S-Function (sfix_bitop): '<S91>/Bitwise AND' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  S-Function (sfix_bitop): '<S53>/vel_valid'
     *  S-Function (sfix_bitop): '<S90>/Bitwise AND'
     *  S-Function (sfix_bitop): '<S92>/Bitwise AND'
     */
    tmp = Controller_U.INS_Out.flag & 16U;

    /* Switch: '<S91>/Switch' incorporates:
     *  Constant: '<S91>/Constant'
     *  S-Function (sfix_bitop): '<S91>/Bitwise AND'
     */
    if (tmp > 0U) {
      /* SignalConversion: '<S94>/ConcatBufferAtVector ConcatenateIn3' */
      rtb_VectorConcatenate_o[6] = Controller_ConstB.VectorConcatenate3_g[0];
      rtb_VectorConcatenate_o[7] = Controller_ConstB.VectorConcatenate3_g[1];
      rtb_VectorConcatenate_o[8] = Controller_ConstB.VectorConcatenate3_g[2];

      /* SignalConversion: '<S94>/ConcatBufferAtVector Concatenate2In3' incorporates:
       *  Constant: '<S94>/Constant4'
       */
      rtb_VectorConcatenate_o[5] = 0.0F;

      /* Trigonometry: '<S94>/Trigonometric Function3' incorporates:
       *  Gain: '<S93>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S94>/Trigonometric Function1'
       */
      rtb_Square_d = arm_cos_f32(-Controller_U.INS_Out.psi);
      rtb_VectorConcatenate_o[4] = rtb_Square_d;

      /* Trigonometry: '<S94>/Trigonometric Function2' incorporates:
       *  Gain: '<S93>/Gain'
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S94>/Trigonometric Function'
       */
      rtb_Gain_ms = arm_sin_f32(-Controller_U.INS_Out.psi);

      /* Gain: '<S94>/Gain' incorporates:
       *  Trigonometry: '<S94>/Trigonometric Function2'
       */
      rtb_VectorConcatenate_o[3] = -rtb_Gain_ms;

      /* SignalConversion: '<S94>/ConcatBufferAtVector Concatenate1In3' incorporates:
       *  Constant: '<S94>/Constant3'
       */
      rtb_VectorConcatenate_o[2] = 0.0F;

      /* Trigonometry: '<S94>/Trigonometric Function' */
      rtb_VectorConcatenate_o[1] = rtb_Gain_ms;

      /* Trigonometry: '<S94>/Trigonometric Function1' */
      rtb_VectorConcatenate_o[0] = rtb_Square_d;

      /* Product: '<S91>/Multiply' */
      for (i = 0; i < 3; i++) {
        rtb_Multiply_ni[i] = rtb_VectorConcatenate_o[i + 6] *
          rtb_TmpSignalConversionAtMult_2 + (rtb_VectorConcatenate_o[i + 3] *
          rtb_TmpSignalConversionAtMult_1 + rtb_VectorConcatenate_o[i] *
          rtb_TmpSignalConversionAtMult_0);
      }

      /* End of Product: '<S91>/Multiply' */

      /* DeadZone: '<S91>/Dead Zone' */
      if (rtb_Multiply_ni[0] > 1.0F) {
        rtb_Multiply1_e = rtb_Multiply_ni[0] - 1.0F;
      } else if (rtb_Multiply_ni[0] >= -1.0F) {
        rtb_Multiply1_e = 0.0F;
      } else {
        rtb_Multiply1_e = rtb_Multiply_ni[0] - -1.0F;
      }

      /* End of DeadZone: '<S91>/Dead Zone' */

      /* Signum: '<S91>/Sign' */
      if (rtb_Multiply1_e < 0.0F) {
        rtb_Multiply1_e = -1.0F;
      } else {
        if (rtb_Multiply1_e > 0.0F) {
          rtb_Multiply1_e = 1.0F;
        }
      }

      /* End of Signum: '<S91>/Sign' */
    } else {
      rtb_Multiply1_e = 1.0F;
    }

    /* End of Switch: '<S91>/Switch' */

    /* Switch: '<S90>/Switch' incorporates:
     *  Gain: '<S90>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S90>/Divide'
     *  Trigonometry: '<S90>/Asin'
     */
    if (tmp > 1U) {
      /* Sqrt: '<S90>/Sqrt' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Math: '<S90>/Square'
       *  Math: '<S90>/Square1'
       *  Sum: '<S90>/Add'
       */
      u0_tmp = sqrtf(Controller_U.INS_Out.vn * Controller_U.INS_Out.vn +
                     Controller_U.INS_Out.ve * Controller_U.INS_Out.ve);

      /* Saturate: '<S90>/Saturation' incorporates:
       *  Sqrt: '<S90>/Sqrt'
       */
      if (u0_tmp > 100.0F) {
        u0_tmp = 100.0F;
      } else {
        if (u0_tmp < 8.0F) {
          u0_tmp = 8.0F;
        }
      }

      /* End of Saturate: '<S90>/Saturation' */

      /* DeadZone: '<S90>/Dead Zone' incorporates:
       *  Inport: '<Root>/INS_Out'
       */
      if (Controller_U.INS_Out.vd > 0.1F) {
        rtb_Saturation_j_idx_1 = Controller_U.INS_Out.vd - 0.1F;
      } else if (Controller_U.INS_Out.vd >= -0.1F) {
        rtb_Saturation_j_idx_1 = 0.0F;
      } else {
        rtb_Saturation_j_idx_1 = Controller_U.INS_Out.vd - -0.1F;
      }

      /* End of DeadZone: '<S90>/Dead Zone' */
      rtb_DiscreteTimeIntegrator5_h5 = atanf(1.0F / u0_tmp *
        -rtb_Saturation_j_idx_1);
    } else {
      rtb_DiscreteTimeIntegrator5_h5 = Controller_U.INS_Out.theta;
    }

    /* End of Switch: '<S90>/Switch' */

    /* Product: '<S90>/Multiply1' */
    rtb_DiscreteTimeIntegrator5_h5 *= rtb_Multiply1_e;

    /* Saturate: '<S90>/Saturation1' */
    if (rtb_DiscreteTimeIntegrator5_h5 > 0.785398185F) {
      rtb_DiscreteTimeIntegrator5_h5 = 0.785398185F;
    } else {
      if (rtb_DiscreteTimeIntegrator5_h5 < -0.785398185F) {
        rtb_DiscreteTimeIntegrator5_h5 = -0.785398185F;
      }
    }

    /* End of Saturate: '<S90>/Saturation1' */

    /* DiscreteIntegrator: '<S101>/Discrete-Time Integrator5' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_n != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_f = Controller_U.INS_Out.ax;
    }

    /* Gain: '<S89>/Gain1' incorporates:
     *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator5'
     */
    rtb_VdotPg = 0.101936802F * Controller_DW.DiscreteTimeIntegrator5_DSTAT_f;

    /* Switch: '<S92>/Switch' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Math: '<S92>/Square'
     *  Math: '<S92>/Square1'
     *  Sqrt: '<S92>/Sqrt'
     *  Sum: '<S92>/Add'
     */
    if (tmp > 0U) {
      rtb_Cos_j = sqrtf(Controller_U.INS_Out.vn * Controller_U.INS_Out.vn +
                        Controller_U.INS_Out.ve * Controller_U.INS_Out.ve);
    } else {
      rtb_Cos_j = Controller_U.INS_Out.airspeed;
    }

    /* End of Switch: '<S92>/Switch' */

    /* Saturate: '<S92>/Saturation1' */
    if (rtb_Cos_j > 100.0F) {
      rtb_Cos_j = 100.0F;
    } else {
      if (rtb_Cos_j < 8.0F) {
        rtb_Cos_j = 8.0F;
      }
    }

    /* End of Saturate: '<S92>/Saturation1' */

    /* Product: '<S92>/Multiply1' incorporates:
     *  Gain: '<S92>/Gain'
     *  Product: '<S92>/Divide'
     *  Trigonometry: '<S92>/Asin'
     */
    rtb_Multiply1_e *= atanf(-Controller_U.FMS_Out.w_cmd / rtb_Cos_j);

    /* Saturate: '<S92>/Saturation2' */
    if (rtb_Multiply1_e > 0.785398185F) {
      rtb_Multiply1_e = 0.785398185F;
    } else {
      if (rtb_Multiply1_e < -0.785398185F) {
        rtb_Multiply1_e = -0.785398185F;
      }
    }

    /* End of Saturate: '<S92>/Saturation2' */

    /* Sum: '<S86>/Sum' */
    rtb_Multiply1_e -= rtb_DiscreteTimeIntegrator5_h5;

    /* Relay: '<S53>/Relay' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    if (Controller_U.INS_Out.airspeed >= 10.0F) {
      Controller_DW.Relay_Mode_i = true;
    } else {
      if (Controller_U.INS_Out.airspeed <= 6.0F) {
        Controller_DW.Relay_Mode_i = false;
      }
    }

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
     *  Sqrt: '<S53>/Sqrt'
     *  Sum: '<S53>/Add'
     */
    if ((Controller_DW.Relay_Mode_i && ((Controller_U.INS_Out.flag & 512U) != 0U))
        || (tmp == 0U)) {
      rtb_Cos_j = Controller_U.INS_Out.airspeed;
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
      rtb_Divide_m_idx_3 = Controller_U.INS_Out.quat[3] / rtb_Square_d;

      /* Math: '<S61>/Square' incorporates:
       *  Math: '<S59>/Square'
       *  Math: '<S60>/Square'
       */
      rtb_Square_d = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_0;

      /* Math: '<S61>/Square2' incorporates:
       *  Math: '<S59>/Square2'
       *  Math: '<S60>/Square2'
       */
      rtb_Gain_ms = rtb_Divide_m_idx_2 * rtb_Divide_m_idx_2;

      /* Math: '<S61>/Square1' incorporates:
       *  Math: '<S59>/Square1'
       *  Math: '<S60>/Square1'
       */
      rtb_aux_att_error_B_rad_idx_0 = rtb_Divide_m_idx_1 * rtb_Divide_m_idx_1;

      /* Math: '<S61>/Square3' incorporates:
       *  Math: '<S59>/Square3'
       *  Math: '<S60>/Square3'
       */
      rtb_aux_att_error_B_rad_idx_1 = rtb_Divide_m_idx_3 * rtb_Divide_m_idx_3;

      /* Sum: '<S61>/Subtract' incorporates:
       *  Math: '<S61>/Square'
       *  Math: '<S61>/Square1'
       *  Math: '<S61>/Square2'
       *  Math: '<S61>/Square3'
       *  Sum: '<S61>/Add'
       *  Sum: '<S61>/Add1'
       */
      rtb_VectorConcatenate_o[8] = (rtb_Square_d + rtb_aux_att_error_B_rad_idx_1)
        - (rtb_aux_att_error_B_rad_idx_0 + rtb_Gain_ms);

      /* Product: '<S61>/Multiply2' incorporates:
       *  Product: '<S60>/Multiply2'
       */
      rtb_Switch2_n_idx_0 = rtb_Divide_m_idx_2 * rtb_Divide_m_idx_3;

      /* Product: '<S61>/Multiply3' incorporates:
       *  Product: '<S60>/Multiply3'
       */
      rtb_VectorConcatenate_k_tmp = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_1;

      /* Gain: '<S61>/Gain1' incorporates:
       *  Product: '<S61>/Multiply2'
       *  Product: '<S61>/Multiply3'
       *  Sum: '<S61>/Add2'
       */
      rtb_VectorConcatenate_o[7] = (rtb_Switch2_n_idx_0 +
        rtb_VectorConcatenate_k_tmp) * 2.0F;

      /* Product: '<S61>/Multiply' incorporates:
       *  Product: '<S59>/Multiply2'
       */
      u0_tmp = rtb_Divide_m_idx_1 * rtb_Divide_m_idx_3;

      /* Product: '<S61>/Multiply1' incorporates:
       *  Product: '<S59>/Multiply3'
       */
      rtb_Cos_j = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_2;

      /* Gain: '<S61>/Gain' incorporates:
       *  Product: '<S61>/Multiply'
       *  Product: '<S61>/Multiply1'
       *  Sum: '<S61>/Subtract2'
       */
      rtb_VectorConcatenate_o[6] = (u0_tmp - rtb_Cos_j) * 2.0F;

      /* Gain: '<S60>/Gain1' incorporates:
       *  Sum: '<S60>/Subtract1'
       */
      rtb_VectorConcatenate_o[5] = (rtb_Switch2_n_idx_0 -
        rtb_VectorConcatenate_k_tmp) * 2.0F;

      /* Sum: '<S60>/Subtract' incorporates:
       *  Sum: '<S60>/Add'
       *  Sum: '<S60>/Add1'
       */
      rtb_VectorConcatenate_o[4] = (rtb_Square_d + rtb_Gain_ms) -
        (rtb_aux_att_error_B_rad_idx_0 + rtb_aux_att_error_B_rad_idx_1);

      /* Product: '<S60>/Multiply' incorporates:
       *  Product: '<S59>/Multiply'
       */
      rtb_Switch2_n_idx_0 = rtb_Divide_m_idx_1 * rtb_Divide_m_idx_2;

      /* Product: '<S60>/Multiply1' incorporates:
       *  Product: '<S59>/Multiply1'
       */
      rtb_VectorConcatenate_k_tmp = rtb_Divide_m_idx_0 * rtb_Divide_m_idx_3;

      /* Gain: '<S60>/Gain' incorporates:
       *  Product: '<S60>/Multiply'
       *  Product: '<S60>/Multiply1'
       *  Sum: '<S60>/Add3'
       */
      rtb_VectorConcatenate_o[3] = (rtb_Switch2_n_idx_0 +
        rtb_VectorConcatenate_k_tmp) * 2.0F;

      /* Gain: '<S59>/Gain1' incorporates:
       *  Sum: '<S59>/Add2'
       */
      rtb_VectorConcatenate_o[2] = (u0_tmp + rtb_Cos_j) * 2.0F;

      /* Gain: '<S59>/Gain' incorporates:
       *  Sum: '<S59>/Subtract1'
       */
      rtb_VectorConcatenate_o[1] = (rtb_Switch2_n_idx_0 -
        rtb_VectorConcatenate_k_tmp) * 2.0F;

      /* Sum: '<S59>/Subtract' incorporates:
       *  Sum: '<S59>/Add'
       *  Sum: '<S59>/Add1'
       */
      rtb_VectorConcatenate_o[0] = (rtb_Square_d + rtb_aux_att_error_B_rad_idx_0)
        - (rtb_Gain_ms + rtb_aux_att_error_B_rad_idx_1);

      /* Product: '<S56>/Multiply' */
      for (i = 0; i < 3; i++) {
        rtb_VectorConcatenate_k[i] = rtb_VectorConcatenate_o[i + 6] *
          rtb_TmpSignalConversionAtMult_2 + (rtb_VectorConcatenate_o[i + 3] *
          rtb_TmpSignalConversionAtMult_1 + rtb_VectorConcatenate_o[i] *
          rtb_TmpSignalConversionAtMult_0);
      }

      /* End of Product: '<S56>/Multiply' */

      /* Signum: '<S56>/Sign' */
      if (rtb_VectorConcatenate_k[0] < 0.0F) {
        rtb_TmpSignalConversionAtMult_0 = -1.0F;
      } else if (rtb_VectorConcatenate_k[0] > 0.0F) {
        rtb_TmpSignalConversionAtMult_0 = 1.0F;
      } else {
        rtb_TmpSignalConversionAtMult_0 = rtb_VectorConcatenate_k[0];
      }

      /* End of Signum: '<S56>/Sign' */
      rtb_Cos_j = sqrtf(Controller_U.INS_Out.vn * Controller_U.INS_Out.vn +
                        Controller_U.INS_Out.ve * Controller_U.INS_Out.ve) *
        rtb_TmpSignalConversionAtMult_0;
    }

    /* End of Switch: '<S53>/Switch' */

    /* Saturate: '<S53>/Saturation1' */
    if (rtb_Cos_j > 100.0F) {
      rtb_Divide_m_idx_0 = 100.0F;
    } else if (rtb_Cos_j < 0.1F) {
      rtb_Divide_m_idx_0 = 0.1F;
    } else {
      rtb_Divide_m_idx_0 = rtb_Cos_j;
    }

    /* End of Saturate: '<S53>/Saturation1' */

    /* DiscreteIntegrator: '<S55>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_e != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j = rtb_Divide_m_idx_0;
    }

    /* Sum: '<S89>/Sum' incorporates:
     *  DiscreteIntegrator: '<S55>/Discrete-Time Integrator5'
     *  Gain: '<S89>/Gain'
     *  Gain: '<S89>/Kv'
     *  Sum: '<S89>/Minus'
     */
    rtb_Cos_j = (Controller_U.FMS_Out.u_cmd -
                 Controller_DW.DiscreteTimeIntegrator5_DSTAT_j) *
      CONTROL_PARAM.FW_TECS_VEL_P * 0.101936802F - rtb_VdotPg;

    /* Sum: '<S67>/Minus1' incorporates:
     *  Gain: '<S67>/ucmd2pitch'
     *  Gain: '<S67>/wcmd2pitch'
     */
    rtb_Divide_m_idx_1 = CONTROL_PARAM.FW_TECS_W2P * rtb_Multiply1_e -
      CONTROL_PARAM.FW_TECS_U2P * rtb_Cos_j;

    /* DiscreteIntegrator: '<S96>/ ' */
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

    /* DiscreteIntegrator: '<S97>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_f != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_e = rtb_Divide_m_idx_1;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_b != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_e = rtb_Divide_m_idx_1;
    }

    /* Gain: '<S97>/Gain' incorporates:
     *  DiscreteIntegrator: '<S97>/Discrete-Time Integrator1'
     *  Sum: '<S97>/Sum5'
     */
    rtb_Divide_m_idx_2 = (rtb_Divide_m_idx_1 -
                          Controller_DW.DiscreteTimeIntegrator1_DSTAT_e) *
      62.831852F;

    /* Switch: '<S79>/Switch1' incorporates:
     *  Constant: '<S85>/Constant'
     *  DiscreteIntegrator: '<S96>/ '
     *  Gain: '<S67>/Gain'
     *  Gain: '<S67>/balabnce_ratio2'
     *  Gain: '<S67>/balance_ratio'
     *  Gain: '<S67>/pitch_ff'
     *  Gain: '<S87>/P_control'
     *  RelationalOperator: '<S85>/Compare'
     *  Sum: '<S67>/Add3'
     *  Sum: '<S67>/Minus'
     *  Sum: '<S67>/Sum'
     *  Sum: '<S87>/Add'
     *  Switch: '<S97>/Switch'
     */
    if (Controller_U.FMS_Out.ctrl_mode == 3) {
      rtb_Square_d = Controller_U.FMS_Out.theta_cmd;
    } else {
      if (Controller_U.FMS_Out.reset > 0) {
        /* Switch: '<S97>/Switch' incorporates:
         *  Gain: '<S97>/Gain1'
         */
        rtb_Saturation_j_idx_1 = 0.0F;
      } else {
        /* Switch: '<S97>/Switch' */
        rtb_Saturation_j_idx_1 = rtb_Divide_m_idx_2;
      }

      /* Gain: '<S95>/Gain' */
      rtb_TmpSignalConversionAtMult_0 = CONTROL_PARAM.FW_TECS_PITCH_D *
        rtb_Saturation_j_idx_1;

      /* Saturate: '<S87>/Saturation1' */
      if (rtb_TmpSignalConversionAtMult_0 > 0.3F) {
        rtb_TmpSignalConversionAtMult_0 = 0.3F;
      } else {
        if (rtb_TmpSignalConversionAtMult_0 < -0.3F) {
          rtb_TmpSignalConversionAtMult_0 = -0.3F;
        }
      }

      /* End of Saturate: '<S87>/Saturation1' */
      rtb_Square_d = (((2.0F - CONTROL_PARAM.FW_TECS_RATIO) *
                       rtb_DiscreteTimeIntegrator5_h5 -
                       CONTROL_PARAM.FW_TECS_RATIO * rtb_VdotPg) *
                      CONTROL_PARAM.FW_TECS_PITCH_F +
                      ((CONTROL_PARAM.FW_TECS_PITCH_P * rtb_Divide_m_idx_1 +
                        Controller_DW._DSTATE) + rtb_TmpSignalConversionAtMult_0))
        + CONTROL_PARAM.FW_TECS_R2P * rtb_Abs;
    }

    /* End of Switch: '<S79>/Switch1' */

    /* Sum: '<S32>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_aux_att_error_B_rad_idx_0 = rtb_phi_cmd - Controller_U.INS_Out.phi;
    rtb_aux_att_error_B_rad_idx_1 = rtb_Square_d - Controller_U.INS_Out.theta;

    /* Product: '<S35>/Divide1' incorporates:
     *  Abs: '<S35>/Abs'
     *  Constant: '<S35>/const2'
     */
    rtb_Gain_ms = fabsf(rtb_aux_att_error_B_rad_idx_0) / 0.002F;

    /* Product: '<S35>/Divide' incorporates:
     *  Constant: '<S33>/Constant1'
     *  Constant: '<S35>/const1'
     *  Math: '<S35>/Square'
     *  SignalConversion: '<S35>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_TmpSignalConversionAtMult_1 = 9.5993F / (CONTROL_PARAM.MC_ROLL_P *
      CONTROL_PARAM.MC_ROLL_P);

    /* Signum: '<S35>/Sign' incorporates:
     *  Abs: '<S35>/Abs'
     */
    if (rtb_aux_att_error_B_rad_idx_0 < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else if (rtb_aux_att_error_B_rad_idx_0 > 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_0 = rtb_aux_att_error_B_rad_idx_0;
    }

    /* Switch: '<S35>/Switch' incorporates:
     *  Abs: '<S35>/Abs'
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
    if ((rtb_aux_att_error_B_rad_idx_0 <= rtb_TmpSignalConversionAtMult_1) &&
        (rtb_aux_att_error_B_rad_idx_0 >= -rtb_TmpSignalConversionAtMult_1)) {
      rtb_TmpSignalConversionAtMult_0 = rtb_aux_att_error_B_rad_idx_0 *
        CONTROL_PARAM.MC_ROLL_P;
    } else {
      rtb_TmpSignalConversionAtMult_0 *= sqrtf((rtb_TmpSignalConversionAtMult_0 *
        rtb_aux_att_error_B_rad_idx_0 - 0.5F * rtb_TmpSignalConversionAtMult_1) *
        Controller_ConstB.Gain_n);
    }

    /* Gain: '<S35>/Gain3' */
    rtb_Divide_m_idx_3 = -rtb_Gain_ms;

    /* Switch: '<S36>/Switch' incorporates:
     *  Gain: '<S35>/Gain3'
     *  RelationalOperator: '<S36>/UpperRelop'
     */
    if (rtb_TmpSignalConversionAtMult_0 >= -rtb_Gain_ms) {
      rtb_Divide_m_idx_3 = rtb_TmpSignalConversionAtMult_0;
    }

    /* Switch: '<S36>/Switch2' incorporates:
     *  RelationalOperator: '<S36>/LowerRelop1'
     */
    if (rtb_TmpSignalConversionAtMult_0 <= rtb_Gain_ms) {
      rtb_Gain_ms = rtb_Divide_m_idx_3;
    }

    rtb_Switch2_n_idx_0 = rtb_Gain_ms;

    /* Product: '<S35>/Divide1' incorporates:
     *  Abs: '<S35>/Abs'
     *  Constant: '<S35>/const2'
     */
    rtb_Gain_ms = fabsf(rtb_aux_att_error_B_rad_idx_1) / 0.002F;

    /* Product: '<S35>/Divide' incorporates:
     *  Constant: '<S33>/Constant2'
     *  Constant: '<S35>/const1'
     *  Math: '<S35>/Square'
     *  SignalConversion: '<S35>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_TmpSignalConversionAtMult_1 = 9.5993F / (CONTROL_PARAM.MC_PITCH_P *
      CONTROL_PARAM.MC_PITCH_P);

    /* Signum: '<S35>/Sign' incorporates:
     *  Abs: '<S35>/Abs'
     */
    if (rtb_aux_att_error_B_rad_idx_1 < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else if (rtb_aux_att_error_B_rad_idx_1 > 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_0 = rtb_aux_att_error_B_rad_idx_1;
    }

    /* Switch: '<S35>/Switch' incorporates:
     *  Abs: '<S35>/Abs'
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
    if ((rtb_aux_att_error_B_rad_idx_1 <= rtb_TmpSignalConversionAtMult_1) &&
        (rtb_aux_att_error_B_rad_idx_1 >= -rtb_TmpSignalConversionAtMult_1)) {
      rtb_TmpSignalConversionAtMult_0 = rtb_aux_att_error_B_rad_idx_1 *
        CONTROL_PARAM.MC_PITCH_P;
    } else {
      rtb_TmpSignalConversionAtMult_0 *= sqrtf((rtb_TmpSignalConversionAtMult_0 *
        rtb_aux_att_error_B_rad_idx_1 - 0.5F * rtb_TmpSignalConversionAtMult_1) *
        Controller_ConstB.Gain_n);
    }

    /* Gain: '<S35>/Gain3' */
    rtb_Divide_m_idx_3 = -rtb_Gain_ms;

    /* Switch: '<S36>/Switch' incorporates:
     *  Gain: '<S35>/Gain3'
     *  RelationalOperator: '<S36>/UpperRelop'
     */
    if (rtb_TmpSignalConversionAtMult_0 >= -rtb_Gain_ms) {
      rtb_Divide_m_idx_3 = rtb_TmpSignalConversionAtMult_0;
    }

    /* Switch: '<S36>/Switch2' incorporates:
     *  RelationalOperator: '<S36>/LowerRelop1'
     */
    if (rtb_TmpSignalConversionAtMult_0 <= rtb_Gain_ms) {
      rtb_Gain_ms = rtb_Divide_m_idx_3;
    }

    /* Trigonometry: '<S30>/Sin1' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S71>/Sin1'
     */
    u0_tmp = arm_sin_f32(Controller_U.INS_Out.theta);

    /* Sum: '<S30>/Add' incorporates:
     *  Product: '<S30>/Multiply'
     *  Trigonometry: '<S30>/Sin1'
     */
    rtb_Saturation3 = rtb_Switch2_n_idx_0 - u0_tmp *
      Controller_U.FMS_Out.psi_rate_cmd;

    /* Saturate: '<S19>/Saturation3' */
    if (rtb_Saturation3 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_Saturation3 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_Saturation3 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_Saturation3 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    /* End of Saturate: '<S19>/Saturation3' */

    /* Trigonometry: '<S30>/Sin' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S71>/Sin'
     */
    rtb_aux_att_error_B_rad_idx_1 = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S30>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S71>/Cos1'
     */
    rtb_Switch2_n_idx_0 = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Trigonometry: '<S30>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S71>/Cos'
     */
    rtb_VectorConcatenate_k_tmp = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Sum: '<S30>/Add1' incorporates:
     *  Product: '<S30>/Multiply1'
     *  Product: '<S30>/Multiply3'
     *  Trigonometry: '<S30>/Cos'
     *  Trigonometry: '<S30>/Cos1'
     *  Trigonometry: '<S30>/Sin'
     */
    rtb_aux_att_error_B_rad_idx_0 = rtb_aux_att_error_B_rad_idx_1 *
      rtb_Switch2_n_idx_0 * Controller_U.FMS_Out.psi_rate_cmd +
      rtb_VectorConcatenate_k_tmp * rtb_Gain_ms;

    /* Saturate: '<S19>/Saturation4' */
    if (rtb_aux_att_error_B_rad_idx_0 > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
      rtb_aux_att_error_B_rad_idx_0 = CONTROL_PARAM.MC_P_Q_CMD_LIM;
    } else {
      if (rtb_aux_att_error_B_rad_idx_0 < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        rtb_aux_att_error_B_rad_idx_0 = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
      }
    }

    /* End of Saturate: '<S19>/Saturation4' */

    /* Sum: '<S30>/Add2' incorporates:
     *  Product: '<S30>/Multiply4'
     *  Product: '<S30>/Multiply5'
     *  Trigonometry: '<S30>/Cos'
     *  Trigonometry: '<S30>/Cos1'
     *  Trigonometry: '<S30>/Sin'
     */
    rtb_DiscreteTimeIntegrator1_i = rtb_VectorConcatenate_k_tmp *
      rtb_Switch2_n_idx_0 * Controller_U.FMS_Out.psi_rate_cmd -
      rtb_aux_att_error_B_rad_idx_1 * rtb_Gain_ms;

    /* Saturate: '<S19>/Saturation2' */
    if (rtb_DiscreteTimeIntegrator1_i > CONTROL_PARAM.MC_R_CMD_LIM) {
      rtb_DiscreteTimeIntegrator1_i = CONTROL_PARAM.MC_R_CMD_LIM;
    } else {
      if (rtb_DiscreteTimeIntegrator1_i < -CONTROL_PARAM.MC_R_CMD_LIM) {
        rtb_DiscreteTimeIntegrator1_i = -CONTROL_PARAM.MC_R_CMD_LIM;
      }
    }

    /* End of Saturate: '<S19>/Saturation2' */

    /* Sum: '<S20>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_TmpSignalConversionAtMult_0 = rtb_Saturation3 - Controller_U.INS_Out.p;

    /* Saturate: '<S20>/Saturation' */
    if (rtb_TmpSignalConversionAtMult_0 > 3.14159274F) {
      rtb_TmpSignalConversionAtMult_0 = 3.14159274F;
    } else {
      if (rtb_TmpSignalConversionAtMult_0 < -3.14159274F) {
        rtb_TmpSignalConversionAtMult_0 = -3.14159274F;
      }
    }

    /* Sum: '<S20>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_TmpSignalConversionAtMult_1 = rtb_aux_att_error_B_rad_idx_0 -
      Controller_U.INS_Out.q;

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
    rtb_TmpSignalConversionAtMult_2 = rtb_DiscreteTimeIntegrator1_i -
      Controller_U.INS_Out.r;

    /* Saturate: '<S20>/Saturation' */
    if (rtb_TmpSignalConversionAtMult_2 > 3.14159274F) {
      rtb_TmpSignalConversionAtMult_2 = 3.14159274F;
    } else {
      if (rtb_TmpSignalConversionAtMult_2 < -3.14159274F) {
        rtb_TmpSignalConversionAtMult_2 = -3.14159274F;
      }
    }

    /* DiscreteIntegrator: '<S24>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_L_bo != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0] =
        rtb_TmpSignalConversionAtMult_0;
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1] =
        rtb_TmpSignalConversionAtMult_1;
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2] =
        rtb_TmpSignalConversionAtMult_2;
    }

    /* DiscreteIntegrator: '<S29>/Discrete-Time Integrator1' incorporates:
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

    if (rtb_aux_reset || (Controller_DW.DiscreteTimeIntegrator1_PrevR_l != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[0] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0];
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[1] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1];
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[2] =
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2];
    }

    /* Gain: '<S29>/Gain' incorporates:
     *  DiscreteIntegrator: '<S24>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S29>/Discrete-Time Integrator1'
     *  Sum: '<S29>/Sum5'
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

    /* RelationalOperator: '<S103>/Compare' incorporates:
     *  Constant: '<S103>/Constant'
     */
    rtb_Compare_nq = (Controller_U.FMS_Out.ctrl_mode == 1);

    /* Switch: '<S12>/Switch' incorporates:
     *  Product: '<S26>/Multiply'
     *  Switch: '<S29>/Switch'
     */
    if (rtb_Compare_nq) {
      Controller_B.mc_torque_cmd[0] = 0.0F;
      Controller_B.mc_torque_cmd[1] = 0.0F;
      Controller_B.mc_torque_cmd[2] = 0.0F;
    } else {
      if (rtb_aux_reset) {
        /* Switch: '<S29>/Switch' incorporates:
         *  Gain: '<S29>/Gain1'
         */
        rtb_Divide_m_idx_3 = 0.0F;
        rtb_Saturation_j_idx_1 = 0.0F;
        rtb_Saturation_j_idx_2 = 0.0F;
      } else {
        /* Switch: '<S29>/Switch' */
        rtb_Divide_m_idx_3 = rtb_Multiply_ni[0];
        rtb_Saturation_j_idx_1 = rtb_Multiply_ni[1];
        rtb_Saturation_j_idx_2 = rtb_Multiply_ni[2];
      }

      /* Product: '<S26>/Multiply' incorporates:
       *  Constant: '<S26>/gain1'
       */
      rtb_Gain_ms = CONTROL_PARAM.MC_ROLL_RATE_D * rtb_Divide_m_idx_3;

      /* Saturate: '<S26>/Saturation' */
      if (rtb_Gain_ms > CONTROL_PARAM.MC_RATE_D_MAX) {
        rtb_Gain_ms = CONTROL_PARAM.MC_RATE_D_MAX;
      } else {
        if (rtb_Gain_ms < CONTROL_PARAM.MC_RATE_D_MIN) {
          rtb_Gain_ms = CONTROL_PARAM.MC_RATE_D_MIN;
        }
      }

      rtb_Divide_m_idx_3 = rtb_Gain_ms;

      /* Product: '<S26>/Multiply' incorporates:
       *  Constant: '<S26>/gain2'
       */
      rtb_Gain_ms = CONTROL_PARAM.MC_PITCH_RATE_D * rtb_Saturation_j_idx_1;

      /* Saturate: '<S26>/Saturation' */
      if (rtb_Gain_ms > CONTROL_PARAM.MC_RATE_D_MAX) {
        rtb_Gain_ms = CONTROL_PARAM.MC_RATE_D_MAX;
      } else {
        if (rtb_Gain_ms < CONTROL_PARAM.MC_RATE_D_MIN) {
          rtb_Gain_ms = CONTROL_PARAM.MC_RATE_D_MIN;
        }
      }

      rtb_Saturation_j_idx_1 = rtb_Gain_ms;

      /* Product: '<S26>/Multiply' incorporates:
       *  Constant: '<S26>/gain3'
       */
      rtb_Gain_ms = CONTROL_PARAM.MC_YAW_RATE_D * rtb_Saturation_j_idx_2;

      /* Saturate: '<S26>/Saturation' */
      if (rtb_Gain_ms > CONTROL_PARAM.MC_RATE_D_MAX) {
        rtb_Gain_ms = CONTROL_PARAM.MC_RATE_D_MAX;
      } else {
        if (rtb_Gain_ms < CONTROL_PARAM.MC_RATE_D_MIN) {
          rtb_Gain_ms = CONTROL_PARAM.MC_RATE_D_MIN;
        }
      }

      /* DeadZone: '<S25>/Dead Zone' */
      if (rtb_Saturation3 > 0.1F) {
        rtb_Saturation3 -= 0.1F;
      } else if (rtb_Saturation3 >= -0.1F) {
        rtb_Saturation3 = 0.0F;
      } else {
        rtb_Saturation3 -= -0.1F;
      }

      /* Product: '<S18>/Multiply' incorporates:
       *  Constant: '<S28>/gain1'
       *  DiscreteIntegrator: '<S24>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S27>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S52>/Discrete-Time Integrator5'
       *  Gain: '<S21>/Gain'
       *  Gain: '<S25>/Gain'
       *  Product: '<S28>/Multiply'
       *  Sum: '<S18>/Sum'
       *  Sum: '<S22>/Add'
       */
      rtb_Divide_m_idx_3 = (((CONTROL_PARAM.MC_ROLL_RATE_P *
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0] +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_d[0]) + rtb_Divide_m_idx_3)
                            + 1.11111116F * rtb_Saturation3 *
                            CONTROL_PARAM.MC_ROLL_RATE_FF) *
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_d;

      /* Saturate: '<S8>/Saturation2' */
      if (rtb_Divide_m_idx_3 > 1.0F) {
        Controller_B.mc_torque_cmd[0] = 1.0F;
      } else if (rtb_Divide_m_idx_3 < -1.0F) {
        Controller_B.mc_torque_cmd[0] = -1.0F;
      } else {
        Controller_B.mc_torque_cmd[0] = rtb_Divide_m_idx_3;
      }

      /* DeadZone: '<S25>/Dead Zone' */
      if (rtb_aux_att_error_B_rad_idx_0 > 0.1F) {
        rtb_aux_att_error_B_rad_idx_0 -= 0.1F;
      } else if (rtb_aux_att_error_B_rad_idx_0 >= -0.1F) {
        rtb_aux_att_error_B_rad_idx_0 = 0.0F;
      } else {
        rtb_aux_att_error_B_rad_idx_0 -= -0.1F;
      }

      /* Product: '<S18>/Multiply' incorporates:
       *  Constant: '<S28>/gain2'
       *  DiscreteIntegrator: '<S24>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S27>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S52>/Discrete-Time Integrator5'
       *  Gain: '<S21>/Gain'
       *  Gain: '<S25>/Gain'
       *  Product: '<S28>/Multiply'
       *  Sum: '<S18>/Sum'
       *  Sum: '<S22>/Add'
       */
      rtb_Divide_m_idx_3 = (((CONTROL_PARAM.MC_PITCH_RATE_P *
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1] +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_d[1]) +
        rtb_Saturation_j_idx_1) + 1.11111116F * rtb_aux_att_error_B_rad_idx_0 *
                            CONTROL_PARAM.MC_ROLL_RATE_FF) *
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_d;

      /* Saturate: '<S8>/Saturation2' */
      if (rtb_Divide_m_idx_3 > 1.0F) {
        Controller_B.mc_torque_cmd[1] = 1.0F;
      } else if (rtb_Divide_m_idx_3 < -1.0F) {
        Controller_B.mc_torque_cmd[1] = -1.0F;
      } else {
        Controller_B.mc_torque_cmd[1] = rtb_Divide_m_idx_3;
      }

      /* DeadZone: '<S25>/Dead Zone' */
      if (rtb_DiscreteTimeIntegrator1_i > 0.1F) {
        rtb_Divide_m_idx_3 = rtb_DiscreteTimeIntegrator1_i - 0.1F;
      } else if (rtb_DiscreteTimeIntegrator1_i >= -0.1F) {
        rtb_Divide_m_idx_3 = 0.0F;
      } else {
        rtb_Divide_m_idx_3 = rtb_DiscreteTimeIntegrator1_i - -0.1F;
      }

      /* Product: '<S18>/Multiply' incorporates:
       *  Constant: '<S28>/gain3'
       *  DiscreteIntegrator: '<S24>/Discrete-Time Integrator5'
       *  DiscreteIntegrator: '<S27>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S52>/Discrete-Time Integrator5'
       *  Gain: '<S21>/Gain1'
       *  Gain: '<S25>/Gain'
       *  Product: '<S28>/Multiply'
       *  Sum: '<S18>/Sum'
       *  Sum: '<S22>/Add'
       */
      rtb_Divide_m_idx_3 = (((CONTROL_PARAM.MC_YAW_RATE_P *
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2] +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_d[2]) + rtb_Gain_ms) +
                            1.11111116F * rtb_Divide_m_idx_3 *
                            CONTROL_PARAM.MC_PITCH_RATE_FF) *
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_d;

      /* Saturate: '<S8>/Saturation2' */
      if (rtb_Divide_m_idx_3 > 1.0F) {
        Controller_B.mc_torque_cmd[2] = 1.0F;
      } else if (rtb_Divide_m_idx_3 < -1.0F) {
        Controller_B.mc_torque_cmd[2] = -1.0F;
      } else {
        Controller_B.mc_torque_cmd[2] = rtb_Divide_m_idx_3;
      }
    }

    /* Gain: '<S43>/Gain' incorporates:
     *  DiscreteIntegrator: '<S45>/Integrator1'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S43>/Sum1'
     */
    rtb_Gain_ms = -(Controller_DW.Integrator1_DSTATE_i - Controller_U.INS_Out.vd);

    /* Relay: '<S41>/Relay' incorporates:
     *  DiscreteIntegrator: '<S52>/Discrete-Time Integrator5'
     */
    if (Controller_DW.DiscreteTimeIntegrator5_DSTAT_d >= 0.3F) {
      Controller_DW.Relay_Mode_l = true;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator5_DSTAT_d <= 0.1F) {
        Controller_DW.Relay_Mode_l = false;
      }
    }

    /* Logic: '<S41>/Logical Operator' incorporates:
     *  Relay: '<S41>/Relay'
     */
    rtb_LogicalOperator_b3 = ((Controller_U.FMS_Out.reset != 0) ||
      (!Controller_DW.Relay_Mode_l));
    Controller_B.Constant_m = CONTROL_PARAM.MC_VEL_Z_I_MIN;

    /* DiscreteIntegrator: '<S48>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S48>/Constant'
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

    /* DiscreteIntegrator: '<S50>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_LO_i != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_l = rtb_Gain_ms;
    }

    if (rtb_LogicalOperator_b3 || (Controller_DW.DiscreteTimeIntegrator1_PrevR_h
         != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_l = rtb_Gain_ms;
    }

    /* Gain: '<S50>/Gain' incorporates:
     *  DiscreteIntegrator: '<S50>/Discrete-Time Integrator1'
     *  Sum: '<S50>/Sum5'
     */
    rtb_aux_att_error_B_rad_idx_0 = (rtb_Gain_ms -
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_l) * 62.831852F;

    /* Switch: '<S12>/Switch' incorporates:
     *  Constant: '<S15>/Constant'
     *  Saturate: '<S8>/Saturation1'
     */
    if (rtb_Compare_nq) {
      Controller_B.mc_force_cmd[0] = 0.0F;
      Controller_B.mc_force_cmd[1] = 0.0F;
      Controller_B.mc_force_cmd[2] = 0.0F;
    } else {
      /* Product: '<S42>/Multiply' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Trigonometry: '<S42>/Cos'
       *  Trigonometry: '<S42>/Cos1'
       */
      rtb_Saturation_j_idx_2 = arm_cos_f32(Controller_U.INS_Out.phi) *
        arm_cos_f32(Controller_U.INS_Out.theta);

      /* Gain: '<S42>/Gain' */
      rtb_Divide_m_idx_3 = 2.0F * rtb_Saturation_j_idx_2;

      /* Saturate: '<S42>/Saturation1' */
      if (rtb_Saturation_j_idx_2 > 1.0F) {
        rtb_Saturation_j_idx_2 = 1.0F;
      } else {
        if (rtb_Saturation_j_idx_2 < 0.5F) {
          rtb_Saturation_j_idx_2 = 0.5F;
        }
      }

      /* End of Saturate: '<S42>/Saturation1' */

      /* Product: '<S42>/Divide' incorporates:
       *  Constant: '<S42>/Constant'
       */
      rtb_Saturation_j_idx_1 = 1.0F / rtb_Saturation_j_idx_2;

      /* Switch: '<S50>/Switch' incorporates:
       *  Gain: '<S50>/Gain1'
       */
      if (rtb_LogicalOperator_b3) {
        rtb_Saturation_j_idx_2 = 0.0F;
      } else {
        rtb_Saturation_j_idx_2 = rtb_aux_att_error_B_rad_idx_0;
      }

      /* End of Switch: '<S50>/Switch' */

      /* Product: '<S47>/Multiply' incorporates:
       *  Constant: '<S47>/kd'
       */
      rtb_Saturation_j_idx_2 *= CONTROL_PARAM.MC_VEL_Z_D;

      /* Saturate: '<S47>/Saturation' */
      if (rtb_Saturation_j_idx_2 > CONTROL_PARAM.MC_VEL_Z_D_MAX) {
        rtb_Saturation_j_idx_2 = CONTROL_PARAM.MC_VEL_Z_D_MAX;
      } else {
        if (rtb_Saturation_j_idx_2 < CONTROL_PARAM.MC_VEL_Z_D_MIN) {
          rtb_Saturation_j_idx_2 = CONTROL_PARAM.MC_VEL_Z_D_MIN;
        }
      }

      /* End of Saturate: '<S47>/Saturation' */

      /* Saturate: '<S42>/Saturation' */
      if (rtb_Divide_m_idx_3 > 1.0F) {
        rtb_Divide_m_idx_3 = 1.0F;
      } else {
        if (rtb_Divide_m_idx_3 < 0.0F) {
          rtb_Divide_m_idx_3 = 0.0F;
        }
      }

      /* End of Saturate: '<S42>/Saturation' */

      /* Product: '<S42>/Multiply1' incorporates:
       *  Constant: '<S49>/kp'
       *  DiscreteIntegrator: '<S48>/Discrete-Time Integrator'
       *  Product: '<S49>/Multiply'
       *  Sum: '<S44>/Add'
       */
      rtb_Divide_m_idx_3 *= ((CONTROL_PARAM.MC_VEL_Z_P * rtb_Gain_ms +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_b) + rtb_Saturation_j_idx_2)
        * rtb_Saturation_j_idx_1;

      /* Saturate: '<S41>/Saturation' */
      if (rtb_Divide_m_idx_3 > 0.35F) {
        rtb_Divide_m_idx_3 = 0.35F;
      } else {
        if (rtb_Divide_m_idx_3 < -0.35F) {
          rtb_Divide_m_idx_3 = -0.35F;
        }
      }

      /* End of Saturate: '<S41>/Saturation' */
      Controller_B.mc_force_cmd[0] = 0.0F;
      Controller_B.mc_force_cmd[1] = 0.0F;

      /* Product: '<S41>/Multiply' incorporates:
       *  Constant: '<S15>/Constant'
       *  Constant: '<S41>/hover_throttle'
       *  DiscreteIntegrator: '<S52>/Discrete-Time Integrator5'
       *  Saturate: '<S8>/Saturation1'
       *  Sum: '<S41>/Sum1'
       */
      rtb_Divide_m_idx_3 = (rtb_Divide_m_idx_3 + CONTROL_PARAM.MC_HOVER_THRO) *
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_d;

      /* Saturate: '<S8>/Saturation1' */
      if (rtb_Divide_m_idx_3 > 1.0F) {
        Controller_B.mc_force_cmd[2] = 1.0F;
      } else if (rtb_Divide_m_idx_3 < -1.0F) {
        Controller_B.mc_force_cmd[2] = -1.0F;
      } else {
        Controller_B.mc_force_cmd[2] = rtb_Divide_m_idx_3;
      }
    }

    /* Sum: '<S67>/Add' incorporates:
     *  Gain: '<S67>/ucmd2thor'
     *  Gain: '<S67>/wcmd2thor'
     */
    rtb_Multiply1_e = CONTROL_PARAM.FW_TECS_W2T * rtb_Multiply1_e +
      CONTROL_PARAM.FW_TECS_U2T * rtb_Cos_j;

    /* DiscreteIntegrator: '<S99>/ ' */
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

    /* DiscreteIntegrator: '<S100>/Discrete-Time Integrator1' */
    if (Controller_DW.DiscreteTimeIntegrator1_IC_L_h0 != 0) {
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm = rtb_Multiply1_e;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevR_d != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTA_nm = rtb_Multiply1_e;
    }

    /* Gain: '<S100>/Gain' incorporates:
     *  DiscreteIntegrator: '<S100>/Discrete-Time Integrator1'
     *  Sum: '<S100>/Sum5'
     */
    rtb_Cos_j = (rtb_Multiply1_e - Controller_DW.DiscreteTimeIntegrator1_DSTA_nm)
      * 188.49556F;

    /* Switch: '<S12>/Switch' incorporates:
     *  Constant: '<S102>/Constant'
     *  Constant: '<S104>/Constant2'
     *  Constant: '<S68>/Constant'
     *  RelationalOperator: '<S102>/Compare'
     *  Saturate: '<S68>/Saturation2'
     *  Switch: '<S100>/Switch'
     *  Switch: '<S68>/Switch'
     */
    if (rtb_Compare_nq) {
      Controller_B.fw_force_cmd[0] = Controller_U.FMS_Out.u_cmd;
      Controller_B.fw_force_cmd[1] = 0.0F;
      Controller_B.fw_force_cmd[2] = 0.0F;
    } else {
      if (Controller_U.FMS_Out.ctrl_mode <= 3) {
        /* Switch: '<S68>/Switch' incorporates:
         *  Bias: '<S68>/Bias'
         *  Gain: '<S68>/Gain'
         */
        rtb_Abs = 0.000999987125F * (real32_T)Controller_U.FMS_Out.throttle_cmd
          + -1.0F;
      } else {
        if (Controller_U.FMS_Out.reset > 0) {
          /* Switch: '<S100>/Switch' incorporates:
           *  Gain: '<S100>/Gain1'
           *  Switch: '<S68>/Switch'
           */
          rtb_Saturation_j_idx_1 = 0.0F;
        } else {
          /* Switch: '<S100>/Switch' incorporates:
           *  Switch: '<S68>/Switch'
           */
          rtb_Saturation_j_idx_1 = rtb_Cos_j;
        }

        /* Gain: '<S98>/Gain' incorporates:
         *  Switch: '<S68>/Switch'
         */
        rtb_Divide_m_idx_3 = CONTROL_PARAM.FW_TECS_THOR_D *
          rtb_Saturation_j_idx_1;

        /* Saturate: '<S88>/Saturation1' incorporates:
         *  Switch: '<S68>/Switch'
         */
        if (rtb_Divide_m_idx_3 > 0.3F) {
          rtb_Divide_m_idx_3 = 0.3F;
        } else {
          if (rtb_Divide_m_idx_3 < -0.3F) {
            rtb_Divide_m_idx_3 = -0.3F;
          }
        }

        /* End of Saturate: '<S88>/Saturation1' */

        /* Sum: '<S67>/Sum1' incorporates:
         *  DiscreteIntegrator: '<S99>/ '
         *  Gain: '<S67>/Gain1'
         *  Gain: '<S67>/thorttle_ff'
         *  Gain: '<S88>/P_control'
         *  Sum: '<S67>/Add1'
         *  Sum: '<S67>/Add2'
         *  Sum: '<S88>/Add4'
         *  Switch: '<S68>/Switch'
         */
        rtb_Abs = (((CONTROL_PARAM.FW_TECS_THOR_P * rtb_Multiply1_e +
                     Controller_DW._DSTATE_d) + rtb_Divide_m_idx_3) +
                   (rtb_DiscreteTimeIntegrator5_h5 + rtb_VdotPg) *
                   CONTROL_PARAM.FW_TECS_THOR_FF) + CONTROL_PARAM.FW_TECS_R2T *
          rtb_Abs;

        /* Saturate: '<S68>/Saturation' incorporates:
         *  Switch: '<S68>/Switch'
         */
        if (rtb_Abs > 1.0F) {
          rtb_Abs = 1.0F;
        } else {
          if (rtb_Abs < -1.0F) {
            rtb_Abs = -1.0F;
          }
        }

        /* End of Saturate: '<S68>/Saturation' */
      }

      /* Saturate: '<S68>/Saturation2' incorporates:
       *  Switch: '<S100>/Switch'
       *  Switch: '<S68>/Switch'
       */
      if (rtb_Abs > 1.0F) {
        Controller_B.fw_force_cmd[0] = 1.0F;
      } else {
        Controller_B.fw_force_cmd[0] = rtb_Abs;
      }

      Controller_B.fw_force_cmd[1] = 0.0F;
      Controller_B.fw_force_cmd[2] = 0.0F;
    }

    /* DiscreteIntegrator: '<S51>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LO_o != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_a = rtb_MultiportSwitch_idx_0;
    }

    /* Bias: '<S80>/Pitch Offset' */
    rtb_Divide_m_idx_3 = rtb_Square_d + CONTROL_PARAM.FW_PITCH_OFFSET;

    /* Saturate: '<S80>/Saturation' */
    if (rtb_Divide_m_idx_3 > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_Divide_m_idx_3 = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_Divide_m_idx_3 < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_Divide_m_idx_3 = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      }
    }

    /* Product: '<S81>/Multiply' incorporates:
     *  Constant: '<S81>/Constant2'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S80>/Sum'
     */
    rtb_Abs = (rtb_Divide_m_idx_3 - Controller_U.INS_Out.theta) *
      CONTROL_PARAM.FW_PITCH_P;

    /* Product: '<S83>/Divide' incorporates:
     *  Constant: '<S83>/Constant'
     *  DiscreteIntegrator: '<S55>/Discrete-Time Integrator5'
     */
    rtb_Divide_m_idx_3 = 9.81F / Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;

    /* Saturate: '<S83>/Saturation' */
    if (rtb_Divide_m_idx_3 > 1.0F) {
      rtb_Divide_m_idx_3 = 1.0F;
    } else {
      if (rtb_Divide_m_idx_3 < 0.2F) {
        rtb_Divide_m_idx_3 = 0.2F;
      }
    }

    /* End of Saturate: '<S83>/Saturation' */

    /* Sum: '<S78>/Sum' incorporates:
     *  Product: '<S83>/Multiply'
     *  Product: '<S83>/Multiply1'
     *  Trigonometry: '<S83>/Cos'
     *  Trigonometry: '<S83>/Tan'
     */
    rtb_Divide_m_idx_3 = tanf(rtb_phi_cmd) * arm_cos_f32(rtb_Square_d) *
      rtb_Divide_m_idx_3 + Controller_U.FMS_Out.psi_rate_cmd;

    /* Saturate: '<S78>/Saturation' */
    if (rtb_Divide_m_idx_3 > CONTROL_PARAM.FW_YAW_RATE_LIM) {
      rtb_Divide_m_idx_3 = CONTROL_PARAM.FW_YAW_RATE_LIM;
    } else {
      if (rtb_Divide_m_idx_3 < -CONTROL_PARAM.FW_YAW_RATE_LIM) {
        rtb_Divide_m_idx_3 = -CONTROL_PARAM.FW_YAW_RATE_LIM;
      }
    }

    /* End of Saturate: '<S78>/Saturation' */

    /* Saturate: '<S80>/Saturation' */
    if (rtb_phi_cmd > CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
      rtb_phi_cmd = CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
    } else {
      if (rtb_phi_cmd < -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM) {
        rtb_phi_cmd = -CONTROL_PARAM.FW_ROLL_PITCH_CMD_LIM;
      }
    }

    /* Sum: '<S71>/Add' incorporates:
     *  Constant: '<S81>/Constant1'
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S71>/Multiply'
     *  Product: '<S81>/Multiply'
     *  Sum: '<S80>/Sum'
     */
    rtb_Square_d = (rtb_phi_cmd - Controller_U.INS_Out.phi) *
      CONTROL_PARAM.FW_ROLL_P - u0_tmp * rtb_Divide_m_idx_3;

    /* Sum: '<S71>/Add1' incorporates:
     *  Product: '<S71>/Multiply1'
     *  Product: '<S71>/Multiply3'
     */
    rtb_DiscreteTimeIntegrator5_h5 = rtb_aux_att_error_B_rad_idx_1 *
      rtb_Switch2_n_idx_0 * rtb_Divide_m_idx_3 + rtb_VectorConcatenate_k_tmp *
      rtb_Abs;

    /* Sum: '<S71>/Add2' incorporates:
     *  Product: '<S71>/Multiply4'
     *  Product: '<S71>/Multiply5'
     */
    rtb_aux_att_error_B_rad_idx_1 = rtb_VectorConcatenate_k_tmp *
      rtb_Switch2_n_idx_0 * rtb_Divide_m_idx_3 - rtb_aux_att_error_B_rad_idx_1 *
      rtb_Abs;

    /* Sum: '<S69>/Minus2' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_VdotPg = rtb_Square_d - Controller_U.INS_Out.p;
    rtb_phi_cmd = rtb_DiscreteTimeIntegrator5_h5 - Controller_U.INS_Out.q;
    rtb_Abs = rtb_aux_att_error_B_rad_idx_1 - Controller_U.INS_Out.r;

    /* Relay: '<S69>/Relay' incorporates:
     *  DiscreteIntegrator: '<S51>/Discrete-Time Integrator5'
     */
    if (Controller_DW.DiscreteTimeIntegrator5_DSTAT_a >= 0.3F) {
      Controller_DW.Relay_Mode_lh = true;
    } else {
      if (Controller_DW.DiscreteTimeIntegrator5_DSTAT_a <= 0.1F) {
        Controller_DW.Relay_Mode_lh = false;
      }
    }

    /* Logic: '<S69>/Logical Operator' incorporates:
     *  Relay: '<S69>/Relay'
     */
    rtb_LogicalOperator_g = ((Controller_U.FMS_Out.reset != 0) ||
      (!Controller_DW.Relay_Mode_lh));

    /* DiscreteIntegrator: '<S75>/Discrete-Time Integrator' */
    if (rtb_LogicalOperator_g || (Controller_DW.DiscreteTimeIntegrator_PrevR_ef
         != 0)) {
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
      /* Product: '<S73>/Divide' incorporates:
       *  Constant: '<S73>/trim_speed'
       *  DiscreteIntegrator: '<S55>/Discrete-Time Integrator5'
       *  Math: '<S73>/Square'
       *  Math: '<S73>/Square1'
       */
      rtb_Switch2_n_idx_0 = CONTROL_PARAM.FW_AIRSPEED_TRIM *
        CONTROL_PARAM.FW_AIRSPEED_TRIM /
        (Controller_DW.DiscreteTimeIntegrator5_DSTAT_j *
         Controller_DW.DiscreteTimeIntegrator5_DSTAT_j);

      /* Saturate: '<S73>/Saturation' */
      if (rtb_Switch2_n_idx_0 > 1.0F) {
        rtb_Switch2_n_idx_0 = 1.0F;
      } else {
        if (rtb_Switch2_n_idx_0 < 0.0F) {
          rtb_Switch2_n_idx_0 = 0.0F;
        }
      }

      /* End of Saturate: '<S73>/Saturation' */

      /* Product: '<S69>/Multiply' incorporates:
       *  Constant: '<S76>/gain1'
       *  Constant: '<S76>/gain2'
       *  Constant: '<S76>/gain3'
       *  DiscreteIntegrator: '<S75>/Discrete-Time Integrator'
       *  Product: '<S76>/Multiply'
       *  Sum: '<S72>/Add1'
       */
      rtb_Divide_m_idx_3 = (CONTROL_PARAM.FW_ROLL_RATE_P * rtb_VdotPg +
                            Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0]) *
        rtb_Switch2_n_idx_0;
      rtb_VectorConcatenate_k_tmp = (CONTROL_PARAM.FW_PITCH_RATE_P * rtb_phi_cmd
        + Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[1]) *
        rtb_Switch2_n_idx_0;
      u0_tmp = (CONTROL_PARAM.FW_YAW_RATE_P * rtb_Abs +
                Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[2]) *
        rtb_Switch2_n_idx_0;

      /* Product: '<S74>/Divide' incorporates:
       *  Constant: '<S74>/trim_speed'
       *  DiscreteIntegrator: '<S55>/Discrete-Time Integrator5'
       */
      rtb_Switch2_n_idx_0 = CONTROL_PARAM.FW_AIRSPEED_TRIM /
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_j;

      /* Saturate: '<S74>/Saturation' */
      if (rtb_Switch2_n_idx_0 > 1.0F) {
        rtb_Switch2_n_idx_0 = 1.0F;
      } else {
        if (rtb_Switch2_n_idx_0 < 0.0F) {
          rtb_Switch2_n_idx_0 = 0.0F;
        }
      }

      /* End of Saturate: '<S74>/Saturation' */

      /* Product: '<S69>/Multiply1' incorporates:
       *  Gain: '<S69>/FF'
       */
      rtb_Square_d = CONTROL_PARAM.FW_FF * rtb_Square_d * rtb_Switch2_n_idx_0;

      /* Saturate: '<S69>/FF_limit' */
      if (rtb_Square_d > 0.3F) {
        rtb_Square_d = 0.3F;
      } else {
        if (rtb_Square_d < -0.3F) {
          rtb_Square_d = -0.3F;
        }
      }

      /* Saturate: '<S69>/PI_limit' */
      if (rtb_Divide_m_idx_3 > 1.0F) {
        rtb_Divide_m_idx_3 = 1.0F;
      } else {
        if (rtb_Divide_m_idx_3 < -1.0F) {
          rtb_Divide_m_idx_3 = -1.0F;
        }
      }

      /* Product: '<S69>/Multiply2' incorporates:
       *  DiscreteIntegrator: '<S51>/Discrete-Time Integrator5'
       *  Sum: '<S69>/Add'
       */
      rtb_Divide_m_idx_3 = (rtb_Square_d + rtb_Divide_m_idx_3) *
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_a;

      /* Saturate: '<S11>/Saturation1' */
      if (rtb_Divide_m_idx_3 > 1.0F) {
        Controller_B.fw_torque_cmd[0] = 1.0F;
      } else if (rtb_Divide_m_idx_3 < -1.0F) {
        Controller_B.fw_torque_cmd[0] = -1.0F;
      } else {
        Controller_B.fw_torque_cmd[0] = rtb_Divide_m_idx_3;
      }

      /* Product: '<S69>/Multiply1' incorporates:
       *  Gain: '<S69>/FF'
       */
      rtb_Divide_m_idx_3 = CONTROL_PARAM.FW_FF * rtb_DiscreteTimeIntegrator5_h5 *
        rtb_Switch2_n_idx_0;

      /* Saturate: '<S69>/FF_limit' */
      if (rtb_Divide_m_idx_3 > 0.3F) {
        rtb_Divide_m_idx_3 = 0.3F;
      } else {
        if (rtb_Divide_m_idx_3 < -0.3F) {
          rtb_Divide_m_idx_3 = -0.3F;
        }
      }

      /* Saturate: '<S69>/PI_limit' */
      if (rtb_VectorConcatenate_k_tmp > 1.0F) {
        rtb_VectorConcatenate_k_tmp = 1.0F;
      } else {
        if (rtb_VectorConcatenate_k_tmp < -1.0F) {
          rtb_VectorConcatenate_k_tmp = -1.0F;
        }
      }

      /* Product: '<S69>/Multiply2' incorporates:
       *  DiscreteIntegrator: '<S51>/Discrete-Time Integrator5'
       *  Sum: '<S69>/Add'
       */
      rtb_Divide_m_idx_3 = (rtb_Divide_m_idx_3 + rtb_VectorConcatenate_k_tmp) *
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_a;

      /* Saturate: '<S11>/Saturation1' */
      if (rtb_Divide_m_idx_3 > 1.0F) {
        Controller_B.fw_torque_cmd[1] = 1.0F;
      } else if (rtb_Divide_m_idx_3 < -1.0F) {
        Controller_B.fw_torque_cmd[1] = -1.0F;
      } else {
        Controller_B.fw_torque_cmd[1] = rtb_Divide_m_idx_3;
      }

      /* Product: '<S69>/Multiply1' incorporates:
       *  Gain: '<S69>/FF'
       */
      rtb_Divide_m_idx_3 = CONTROL_PARAM.FW_FF * rtb_aux_att_error_B_rad_idx_1 *
        rtb_Switch2_n_idx_0;

      /* Saturate: '<S69>/FF_limit' */
      if (rtb_Divide_m_idx_3 > 0.3F) {
        rtb_Divide_m_idx_3 = 0.3F;
      } else {
        if (rtb_Divide_m_idx_3 < -0.3F) {
          rtb_Divide_m_idx_3 = -0.3F;
        }
      }

      /* Saturate: '<S69>/PI_limit' */
      if (u0_tmp > 1.0F) {
        u0_tmp = 1.0F;
      } else {
        if (u0_tmp < -1.0F) {
          u0_tmp = -1.0F;
        }
      }

      /* Product: '<S69>/Multiply2' incorporates:
       *  DiscreteIntegrator: '<S51>/Discrete-Time Integrator5'
       *  Sum: '<S69>/Add'
       */
      rtb_Divide_m_idx_3 = (rtb_Divide_m_idx_3 + u0_tmp) *
        Controller_DW.DiscreteTimeIntegrator5_DSTAT_a;

      /* Saturate: '<S11>/Saturation1' */
      if (rtb_Divide_m_idx_3 > 1.0F) {
        Controller_B.fw_torque_cmd[2] = 1.0F;
      } else if (rtb_Divide_m_idx_3 < -1.0F) {
        Controller_B.fw_torque_cmd[2] = -1.0F;
      } else {
        Controller_B.fw_torque_cmd[2] = rtb_Divide_m_idx_3;
      }
    }

    /* Product: '<S46>/Multiply1' incorporates:
     *  Constant: '<S46>/const1'
     *  DiscreteIntegrator: '<S45>/Integrator'
     */
    rtb_Divide_m_idx_3 = Controller_DW.Integrator_DSTATE_f * 0.05F;

    /* Sum: '<S46>/Add' incorporates:
     *  DiscreteIntegrator: '<S45>/Integrator1'
     *  Sum: '<S45>/Subtract'
     */
    rtb_aux_att_error_B_rad_idx_1 = (Controller_DW.Integrator1_DSTATE_i -
      Controller_U.FMS_Out.w_cmd) + rtb_Divide_m_idx_3;

    /* Signum: '<S46>/Sign' */
    if (rtb_aux_att_error_B_rad_idx_1 < 0.0F) {
      rtb_DiscreteTimeIntegrator5_h5 = -1.0F;
    } else if (rtb_aux_att_error_B_rad_idx_1 > 0.0F) {
      rtb_DiscreteTimeIntegrator5_h5 = 1.0F;
    } else {
      rtb_DiscreteTimeIntegrator5_h5 = rtb_aux_att_error_B_rad_idx_1;
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
    rtb_Square_d = (sqrtf((8.0F * fabsf(rtb_aux_att_error_B_rad_idx_1) +
      Controller_ConstB.d_m) * Controller_ConstB.d_m) - Controller_ConstB.d_m) *
      0.5F * rtb_DiscreteTimeIntegrator5_h5 + rtb_Divide_m_idx_3;

    /* Sum: '<S46>/Add4' */
    rtb_Divide_m_idx_3 += rtb_aux_att_error_B_rad_idx_1 - rtb_Square_d;

    /* Sum: '<S46>/Add3' */
    rtb_DiscreteTimeIntegrator5_h5 = rtb_aux_att_error_B_rad_idx_1 +
      Controller_ConstB.d_m;

    /* Sum: '<S46>/Subtract1' */
    rtb_aux_att_error_B_rad_idx_1 -= Controller_ConstB.d_m;

    /* Signum: '<S46>/Sign1' */
    if (rtb_DiscreteTimeIntegrator5_h5 < 0.0F) {
      rtb_DiscreteTimeIntegrator5_h5 = -1.0F;
    } else {
      if (rtb_DiscreteTimeIntegrator5_h5 > 0.0F) {
        rtb_DiscreteTimeIntegrator5_h5 = 1.0F;
      }
    }

    /* End of Signum: '<S46>/Sign1' */

    /* Signum: '<S46>/Sign2' */
    if (rtb_aux_att_error_B_rad_idx_1 < 0.0F) {
      rtb_aux_att_error_B_rad_idx_1 = -1.0F;
    } else {
      if (rtb_aux_att_error_B_rad_idx_1 > 0.0F) {
        rtb_aux_att_error_B_rad_idx_1 = 1.0F;
      }
    }

    /* End of Signum: '<S46>/Sign2' */

    /* Sum: '<S46>/Add5' incorporates:
     *  Gain: '<S46>/Gain2'
     *  Product: '<S46>/Multiply4'
     *  Sum: '<S46>/Subtract2'
     */
    rtb_Square_d += (rtb_DiscreteTimeIntegrator5_h5 -
                     rtb_aux_att_error_B_rad_idx_1) * 0.5F * rtb_Divide_m_idx_3;

    /* Update for DiscreteIntegrator: '<S52>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S52>/Gain'
     *  Sum: '<S52>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_b = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_d += (rtb_MultiportSwitch_idx_1
      - Controller_DW.DiscreteTimeIntegrator5_DSTAT_d) * 3.14159274F * 0.002F;

    /* Update for DiscreteIntegrator: '<S27>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S27>/gain1'
     *  Constant: '<S27>/gain2'
     *  Constant: '<S27>/gain3'
     *  DiscreteIntegrator: '<S24>/Discrete-Time Integrator5'
     *  Product: '<S27>/Multiply'
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

    /* End of Update for DiscreteIntegrator: '<S27>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S101>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S101>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S101>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_n = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_f += (Controller_U.INS_Out.ax -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_f) * 31.415926F * 0.002F;

    /* Update for DiscreteIntegrator: '<S55>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S55>/Gain'
     *  Sum: '<S55>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_e = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_j += (rtb_Divide_m_idx_0 -
      Controller_DW.DiscreteTimeIntegrator5_DSTAT_j) * 62.831852F * 0.002F;

    /* Update for DiscreteIntegrator: '<S96>/ ' incorporates:
     *  Gain: '<S96>/Gain3'
     */
    Controller_DW._DSTATE += CONTROL_PARAM.FW_TECS_PITCH_I * rtb_Divide_m_idx_1 *
      0.002F;
    if (Controller_DW._DSTATE >= CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
      Controller_DW._DSTATE = CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
    } else {
      if (Controller_DW._DSTATE <= -CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
        Controller_DW._DSTATE = -CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
      }
    }

    Controller_DW._PrevResetState = (int8_T)(Controller_U.FMS_Out.reset > 0);

    /* End of Update for DiscreteIntegrator: '<S96>/ ' */

    /* Update for DiscreteIntegrator: '<S97>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_f = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_e += 0.002F * rtb_Divide_m_idx_2;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_b = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S24>/Discrete-Time Integrator5' */
    Controller_DW.DiscreteTimeIntegrator5_IC_L_bo = 0U;

    /* Update for DiscreteIntegrator: '<S29>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_h = 0U;

    /* Update for DiscreteIntegrator: '<S24>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S24>/Gain'
     *  Sum: '<S24>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0] +=
      (rtb_TmpSignalConversionAtMult_0 -
       Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[0]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S29>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[0] += 0.002F *
      rtb_Multiply_ni[0];

    /* Update for DiscreteIntegrator: '<S24>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S24>/Gain'
     *  Sum: '<S24>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1] +=
      (rtb_TmpSignalConversionAtMult_1 -
       Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[1]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S29>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[1] += 0.002F *
      rtb_Multiply_ni[1];

    /* Update for DiscreteIntegrator: '<S24>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S24>/Gain'
     *  Sum: '<S24>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2] +=
      (rtb_TmpSignalConversionAtMult_2 -
       Controller_DW.DiscreteTimeIntegrator5_DSTAT_l[2]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S29>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_p[2] += 0.002F *
      rtb_Multiply_ni[2];
    Controller_DW.DiscreteTimeIntegrator1_PrevR_l = (int8_T)rtb_aux_reset;

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

    /* End of Update for DiscreteIntegrator: '<S48>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S50>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_i = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_l += 0.002F *
      rtb_aux_att_error_B_rad_idx_0;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_h = (int8_T)
      rtb_LogicalOperator_b3;

    /* Update for DiscreteIntegrator: '<S99>/ ' incorporates:
     *  Gain: '<S99>/Gain'
     */
    Controller_DW._DSTATE_d += CONTROL_PARAM.FW_TECS_THOR_I * rtb_Multiply1_e *
      0.002F;
    if (Controller_DW._DSTATE_d >= 1.0F) {
      Controller_DW._DSTATE_d = 1.0F;
    } else {
      if (Controller_DW._DSTATE_d <= 0.0F) {
        Controller_DW._DSTATE_d = 0.0F;
      }
    }

    Controller_DW._PrevResetState_e = (int8_T)(Controller_U.FMS_Out.reset > 0);

    /* End of Update for DiscreteIntegrator: '<S99>/ ' */

    /* Update for DiscreteIntegrator: '<S100>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_L_h0 = 0U;
    Controller_DW.DiscreteTimeIntegrator1_DSTA_nm += 0.002F * rtb_Cos_j;
    Controller_DW.DiscreteTimeIntegrator1_PrevR_d = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S51>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S51>/Gain'
     *  Sum: '<S51>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_IC_LO_o = 0U;
    Controller_DW.DiscreteTimeIntegrator5_DSTAT_a += (rtb_MultiportSwitch_idx_0
      - Controller_DW.DiscreteTimeIntegrator5_DSTAT_a) * 6.28318548F * 0.002F;

    /* Update for DiscreteIntegrator: '<S75>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S75>/gain1'
     *  Constant: '<S75>/gain2'
     *  Constant: '<S75>/gain3'
     *  Product: '<S75>/Multiply'
     */
    Controller_DW.DiscreteTimeIntegrator_DSTAT_l5[0] +=
      CONTROL_PARAM.FW_ROLL_RATE_I * rtb_VdotPg * 0.002F;
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
      CONTROL_PARAM.FW_PITCH_RATE_I * rtb_phi_cmd * 0.002F;
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
      CONTROL_PARAM.FW_YAW_RATE_I * rtb_Abs * 0.002F;
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
      rtb_LogicalOperator_g;

    /* End of Update for DiscreteIntegrator: '<S75>/Discrete-Time Integrator' */

    /* Signum: '<S46>/Sign6' incorporates:
     *  Signum: '<S46>/Sign5'
     */
    if (rtb_Square_d < 0.0F) {
      rtb_MultiportSwitch_idx_1 = -1.0F;

      /* Signum: '<S46>/Sign5' */
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else if (rtb_Square_d > 0.0F) {
      rtb_MultiportSwitch_idx_1 = 1.0F;

      /* Signum: '<S46>/Sign5' */
      rtb_TmpSignalConversionAtMult_0 = 1.0F;
    } else {
      rtb_MultiportSwitch_idx_1 = rtb_Square_d;

      /* Signum: '<S46>/Sign5' */
      rtb_TmpSignalConversionAtMult_0 = rtb_Square_d;
    }

    /* End of Signum: '<S46>/Sign6' */

    /* Sum: '<S46>/Add6' */
    rtb_DiscreteTimeIntegrator5_h5 = rtb_Square_d + Controller_ConstB.d_m;

    /* Sum: '<S46>/Subtract3' */
    rtb_MultiportSwitch_idx_0 = rtb_Square_d - Controller_ConstB.d_m;

    /* Signum: '<S46>/Sign3' */
    if (rtb_DiscreteTimeIntegrator5_h5 < 0.0F) {
      rtb_DiscreteTimeIntegrator5_h5 = -1.0F;
    } else {
      if (rtb_DiscreteTimeIntegrator5_h5 > 0.0F) {
        rtb_DiscreteTimeIntegrator5_h5 = 1.0F;
      }
    }

    /* End of Signum: '<S46>/Sign3' */

    /* Signum: '<S46>/Sign4' */
    if (rtb_MultiportSwitch_idx_0 < 0.0F) {
      rtb_MultiportSwitch_idx_0 = -1.0F;
    } else {
      if (rtb_MultiportSwitch_idx_0 > 0.0F) {
        rtb_MultiportSwitch_idx_0 = 1.0F;
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
    Controller_DW.Integrator_DSTATE_f += ((rtb_Square_d / Controller_ConstB.d_m
      - rtb_TmpSignalConversionAtMult_0) * Controller_ConstB.Gain4_o *
      ((rtb_DiscreteTimeIntegrator5_h5 - rtb_MultiportSwitch_idx_0) * 0.5F) -
      rtb_MultiportSwitch_idx_1 * 78.448F) * 0.002F;

    /* End of Outputs for SubSystem: '<S2>/FW_Controller' */
    break;

   case 1:
    if (Controller_DW.SwitchCase1_ActiveSubsystem != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S2>/MC_Controller' incorporates:
       *  ActionPort: '<S5>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S7>/Switch Case1' incorporates:
       *  DiscreteIntegrator: '<S118>/Discrete-Time Integrator5'
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
    rtb_VectorConcatenate_o[0] = arm_cos_f32(-Controller_U.INS_Out.psi);

    /* Trigonometry: '<S145>/Trigonometric Function' incorporates:
     *  Gain: '<S144>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_VectorConcatenate_o[1] = arm_sin_f32(-Controller_U.INS_Out.psi);

    /* SignalConversion: '<S145>/ConcatBufferAtVector Concatenate1In3' incorporates:
     *  Constant: '<S145>/Constant3'
     */
    rtb_VectorConcatenate_o[2] = 0.0F;

    /* Gain: '<S145>/Gain' incorporates:
     *  Gain: '<S144>/Gain'
     *  Inport: '<Root>/INS_Out'
     *  Trigonometry: '<S145>/Trigonometric Function2'
     */
    rtb_VectorConcatenate_o[3] = -arm_sin_f32(-Controller_U.INS_Out.psi);

    /* Trigonometry: '<S145>/Trigonometric Function3' incorporates:
     *  Gain: '<S144>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_VectorConcatenate_o[4] = arm_cos_f32(-Controller_U.INS_Out.psi);

    /* SignalConversion: '<S145>/ConcatBufferAtVector Concatenate2In3' incorporates:
     *  Constant: '<S145>/Constant4'
     */
    rtb_VectorConcatenate_o[5] = 0.0F;

    /* SignalConversion: '<S145>/ConcatBufferAtVector ConcatenateIn3' */
    rtb_VectorConcatenate_o[6] = Controller_ConstB.VectorConcatenate3[0];
    rtb_VectorConcatenate_o[7] = Controller_ConstB.VectorConcatenate3[1];
    rtb_VectorConcatenate_o[8] = Controller_ConstB.VectorConcatenate3[2];

    /* Product: '<S142>/Multiply' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  SignalConversion: '<S142>/TmpSignal ConversionAtMultiplyInport2'
     */
    for (i = 0; i < 3; i++) {
      rtb_VectorConcatenate_k[i] = rtb_VectorConcatenate_o[i + 3] *
        Controller_U.INS_Out.ve + rtb_VectorConcatenate_o[i] *
        Controller_U.INS_Out.vn;
    }

    /* End of Product: '<S142>/Multiply' */

    /* Sum: '<S139>/Sum' incorporates:
     *  DiscreteIntegrator: '<S143>/Integrator1'
     */
    rtb_MultiportSwitch_idx_0 = Controller_DW.Integrator1_DSTATE[0] -
      rtb_VectorConcatenate_k[0];
    rtb_MultiportSwitch_idx_1 = Controller_DW.Integrator1_DSTATE[1] -
      rtb_VectorConcatenate_k[1];

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
        rtb_MultiportSwitch_idx_0;
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] =
        rtb_MultiportSwitch_idx_1;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_PrevRes != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[0] =
        rtb_MultiportSwitch_idx_0;
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[1] =
        rtb_MultiportSwitch_idx_1;
    }

    /* Gain: '<S150>/Gain' incorporates:
     *  DiscreteIntegrator: '<S150>/Discrete-Time Integrator1'
     *  Sum: '<S150>/Sum5'
     */
    rtb_aux_att_error_B_rad_idx_0 = (rtb_MultiportSwitch_idx_0 -
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[0]) * 62.831852F;
    rtb_aux_att_error_B_rad_idx_1 = (rtb_MultiportSwitch_idx_1 -
      Controller_DW.DiscreteTimeIntegrator1_DSTATE[1]) * 62.831852F;

    /* Switch: '<S150>/Switch' incorporates:
     *  Gain: '<S150>/Gain1'
     */
    if (Controller_U.FMS_Out.reset > 0) {
      rtb_Switch2_n_idx_0 = 0.0F;
      rtb_TmpSignalConversionAtMult_2 = 0.0F;
    } else {
      rtb_Switch2_n_idx_0 = rtb_aux_att_error_B_rad_idx_0;
      rtb_TmpSignalConversionAtMult_2 = rtb_aux_att_error_B_rad_idx_1;
    }

    /* End of Switch: '<S150>/Switch' */

    /* Product: '<S147>/Multiply' incorporates:
     *  Constant: '<S147>/kd'
     */
    rtb_Gain_ms = CONTROL_PARAM.MC_VEL_XY_D * rtb_Switch2_n_idx_0;

    /* Saturate: '<S147>/Saturation' */
    if (rtb_Gain_ms > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
      rtb_Gain_ms = CONTROL_PARAM.MC_VEL_XY_D_MAX;
    } else {
      if (rtb_Gain_ms < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
        rtb_Gain_ms = CONTROL_PARAM.MC_VEL_XY_D_MIN;
      }
    }

    rtb_Switch2_n_idx_0 = rtb_Gain_ms;

    /* Product: '<S147>/Multiply' incorporates:
     *  Constant: '<S147>/kd'
     */
    rtb_Gain_ms = CONTROL_PARAM.MC_VEL_XY_D * rtb_TmpSignalConversionAtMult_2;

    /* Saturate: '<S147>/Saturation' */
    if (rtb_Gain_ms > CONTROL_PARAM.MC_VEL_XY_D_MAX) {
      rtb_Gain_ms = CONTROL_PARAM.MC_VEL_XY_D_MAX;
    } else {
      if (rtb_Gain_ms < CONTROL_PARAM.MC_VEL_XY_D_MIN) {
        rtb_Gain_ms = CONTROL_PARAM.MC_VEL_XY_D_MIN;
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
    if (Controller_U.FMS_Out.ctrl_mode == 6) {
      rtb_Switch2_n_idx_0 = ((Controller_U.FMS_Out.cmd_mask & 64) > 0 ?
        (CONTROL_PARAM.MC_VEL_XY_P * rtb_MultiportSwitch_idx_0 +
         Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0]) + rtb_Switch2_n_idx_0
        : 0.0F) + ((Controller_U.FMS_Out.cmd_mask & 512) > 0 ?
                   Controller_U.FMS_Out.ax_cmd : 0.0F);
      rtb_TmpSignalConversionAtMult_2 = ((Controller_U.FMS_Out.cmd_mask & 128) >
        0 ? (CONTROL_PARAM.MC_VEL_XY_P * rtb_MultiportSwitch_idx_1 +
             Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1]) + rtb_Gain_ms :
        0.0F) + ((Controller_U.FMS_Out.cmd_mask & 1024) > 0 ?
                 Controller_U.FMS_Out.ay_cmd : 0.0F);
    } else {
      rtb_Switch2_n_idx_0 += CONTROL_PARAM.MC_VEL_XY_P *
        rtb_MultiportSwitch_idx_0 +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_k[0];
      rtb_TmpSignalConversionAtMult_2 = (CONTROL_PARAM.MC_VEL_XY_P *
        rtb_MultiportSwitch_idx_1 +
        Controller_DW.DiscreteTimeIntegrator_DSTATE_k[1]) + rtb_Gain_ms;
    }

    /* End of Switch: '<S141>/Switch' */

    /* Trigonometry: '<S138>/Atan' incorporates:
     *  Constant: '<S138>/g'
     *  Gain: '<S138>/Gain1'
     *  Gain: '<S138>/gain'
     *  Product: '<S138>/Divide'
     */
    rtb_Divide_m_idx_3 = atanf(1.1F * rtb_TmpSignalConversionAtMult_2 / 9.8055F);
    rtb_TmpSignalConversionAtMult_2 = atanf(1.1F * -rtb_Switch2_n_idx_0 /
      9.8055F);

    /* Switch: '<S129>/Switch' incorporates:
     *  Constant: '<S136>/Constant'
     *  Logic: '<S129>/Logical Operator'
     *  RelationalOperator: '<S135>/Compare'
     *  RelationalOperator: '<S136>/Compare'
     *  Saturate: '<S138>/Saturation'
     *  Switch: '<S129>/Switch1'
     */
    if ((Controller_U.FMS_Out.ctrl_mode == 3) || (Controller_U.FMS_Out.ctrl_mode
         == 4)) {
      rtb_Switch2_n_idx_0 = Controller_U.FMS_Out.phi_cmd;
      rtb_TmpSignalConversionAtMult_2 = Controller_U.FMS_Out.theta_cmd;
    } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
      /* Switch: '<S137>/Switch' incorporates:
       *  S-Function (sfix_bitop): '<S137>/cmd_phi valid'
       *  S-Function (sfix_bitop): '<S137>/cmd_theta valid'
       *  Saturate: '<S138>/Saturation'
       *  Switch: '<S129>/Switch1'
       */
      if ((Controller_U.FMS_Out.cmd_mask & 8) > 0) {
        rtb_Switch2_n_idx_0 = Controller_U.FMS_Out.phi_cmd;
      } else if (rtb_Divide_m_idx_3 > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S138>/Saturation' */
        rtb_Switch2_n_idx_0 = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else if (rtb_Divide_m_idx_3 < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S138>/Saturation' */
        rtb_Switch2_n_idx_0 = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        rtb_Switch2_n_idx_0 = rtb_Divide_m_idx_3;
      }

      if ((Controller_U.FMS_Out.cmd_mask & 16) > 0) {
        rtb_TmpSignalConversionAtMult_2 = Controller_U.FMS_Out.theta_cmd;
      } else if (rtb_TmpSignalConversionAtMult_2 >
                 CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S138>/Saturation' */
        rtb_TmpSignalConversionAtMult_2 = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_TmpSignalConversionAtMult_2 <
            -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Saturate: '<S138>/Saturation' */
          rtb_TmpSignalConversionAtMult_2 = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        }
      }

      /* End of Switch: '<S137>/Switch' */
    } else {
      if (rtb_Divide_m_idx_3 > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S138>/Saturation' incorporates:
         *  Switch: '<S129>/Switch1'
         */
        rtb_Switch2_n_idx_0 = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else if (rtb_Divide_m_idx_3 < -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
        /* Saturate: '<S138>/Saturation' incorporates:
         *  Switch: '<S129>/Switch1'
         */
        rtb_Switch2_n_idx_0 = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        /* Switch: '<S129>/Switch1' incorporates:
         *  Saturate: '<S138>/Saturation'
         */
        rtb_Switch2_n_idx_0 = rtb_Divide_m_idx_3;
      }

      /* Saturate: '<S138>/Saturation' */
      if (rtb_TmpSignalConversionAtMult_2 > CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM)
      {
        /* Switch: '<S129>/Switch1' */
        rtb_TmpSignalConversionAtMult_2 = CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
      } else {
        if (rtb_TmpSignalConversionAtMult_2 <
            -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM) {
          /* Switch: '<S129>/Switch1' */
          rtb_TmpSignalConversionAtMult_2 = -CONTROL_PARAM.MC_ROLL_PITCH_CMD_LIM;
        }
      }
    }

    /* End of Switch: '<S129>/Switch' */

    /* Sum: '<S130>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Gain_ms = rtb_Switch2_n_idx_0 - Controller_U.INS_Out.phi;

    /* Product: '<S133>/Divide1' incorporates:
     *  Abs: '<S133>/Abs'
     *  Constant: '<S133>/const2'
     */
    rtb_TmpSignalConversionAtMult_0 = fabsf(rtb_Gain_ms) / 0.002F;

    /* Product: '<S133>/Divide' incorporates:
     *  Constant: '<S131>/Constant1'
     *  Constant: '<S133>/const1'
     *  Math: '<S133>/Square'
     *  SignalConversion: '<S133>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_phi_cmd = 9.5993F / (CONTROL_PARAM.MC_ROLL_P * CONTROL_PARAM.MC_ROLL_P);

    /* Signum: '<S133>/Sign' */
    if (rtb_Gain_ms < 0.0F) {
      rtb_Divide_m_idx_3 = -1.0F;
    } else if (rtb_Gain_ms > 0.0F) {
      rtb_Divide_m_idx_3 = 1.0F;
    } else {
      rtb_Divide_m_idx_3 = rtb_Gain_ms;
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
    if ((rtb_Gain_ms <= rtb_phi_cmd) && (rtb_Gain_ms >= -rtb_phi_cmd)) {
      rtb_Divide_m_idx_3 = rtb_Gain_ms * CONTROL_PARAM.MC_ROLL_P;
    } else {
      rtb_Divide_m_idx_3 *= sqrtf((rtb_Divide_m_idx_3 * rtb_Gain_ms - 0.5F *
        rtb_phi_cmd) * Controller_ConstB.Gain);
    }

    /* Gain: '<S133>/Gain3' */
    rtb_phi_cmd = -rtb_TmpSignalConversionAtMult_0;

    /* Switch: '<S134>/Switch' incorporates:
     *  Gain: '<S133>/Gain3'
     *  RelationalOperator: '<S134>/UpperRelop'
     */
    if (rtb_Divide_m_idx_3 >= -rtb_TmpSignalConversionAtMult_0) {
      rtb_phi_cmd = rtb_Divide_m_idx_3;
    }

    /* Switch: '<S134>/Switch2' incorporates:
     *  RelationalOperator: '<S134>/LowerRelop1'
     */
    if (rtb_Divide_m_idx_3 <= rtb_TmpSignalConversionAtMult_0) {
      rtb_TmpSignalConversionAtMult_0 = rtb_phi_cmd;
    }

    rtb_TmpSignalConversionAtMult_1 = rtb_TmpSignalConversionAtMult_0;

    /* Sum: '<S130>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Product: '<S133>/Divide1'
     */
    rtb_Gain_ms = rtb_TmpSignalConversionAtMult_2 - Controller_U.INS_Out.theta;

    /* Product: '<S133>/Divide1' incorporates:
     *  Abs: '<S133>/Abs'
     *  Constant: '<S133>/const2'
     */
    rtb_TmpSignalConversionAtMult_0 = fabsf(rtb_Gain_ms) / 0.002F;

    /* Product: '<S133>/Divide' incorporates:
     *  Constant: '<S131>/Constant2'
     *  Constant: '<S133>/const1'
     *  Math: '<S133>/Square'
     *  SignalConversion: '<S133>/TmpSignal ConversionAtSquareInport1'
     */
    rtb_phi_cmd = 9.5993F / (CONTROL_PARAM.MC_PITCH_P * CONTROL_PARAM.MC_PITCH_P);

    /* Signum: '<S133>/Sign' */
    if (rtb_Gain_ms < 0.0F) {
      rtb_Divide_m_idx_3 = -1.0F;
    } else if (rtb_Gain_ms > 0.0F) {
      rtb_Divide_m_idx_3 = 1.0F;
    } else {
      rtb_Divide_m_idx_3 = rtb_Gain_ms;
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
    if ((rtb_Gain_ms <= rtb_phi_cmd) && (rtb_Gain_ms >= -rtb_phi_cmd)) {
      rtb_Divide_m_idx_3 = rtb_Gain_ms * CONTROL_PARAM.MC_PITCH_P;
    } else {
      rtb_Divide_m_idx_3 *= sqrtf((rtb_Divide_m_idx_3 * rtb_Gain_ms - 0.5F *
        rtb_phi_cmd) * Controller_ConstB.Gain);
    }

    /* Gain: '<S133>/Gain3' */
    rtb_phi_cmd = -rtb_TmpSignalConversionAtMult_0;

    /* Switch: '<S134>/Switch' incorporates:
     *  Gain: '<S133>/Gain3'
     *  RelationalOperator: '<S134>/UpperRelop'
     */
    if (rtb_Divide_m_idx_3 >= -rtb_TmpSignalConversionAtMult_0) {
      rtb_phi_cmd = rtb_Divide_m_idx_3;
    }

    /* Switch: '<S134>/Switch2' incorporates:
     *  RelationalOperator: '<S134>/LowerRelop1'
     */
    if (rtb_Divide_m_idx_3 <= rtb_TmpSignalConversionAtMult_0) {
      rtb_TmpSignalConversionAtMult_0 = rtb_phi_cmd;
    }

    /* Trigonometry: '<S124>/Sin' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Divide_m_idx_0 = arm_sin_f32(Controller_U.INS_Out.phi);

    /* Trigonometry: '<S124>/Cos1' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_DiscreteTimeIntegrator5_h5 = arm_cos_f32(Controller_U.INS_Out.theta);

    /* Trigonometry: '<S124>/Cos' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Abs = arm_cos_f32(Controller_U.INS_Out.phi);

    /* Sum: '<S124>/Add1' incorporates:
     *  Product: '<S124>/Multiply1'
     *  Product: '<S124>/Multiply3'
     *  Trigonometry: '<S124>/Cos'
     *  Trigonometry: '<S124>/Cos1'
     *  Trigonometry: '<S124>/Sin'
     */
    rtb_phi_cmd = rtb_Divide_m_idx_0 * rtb_DiscreteTimeIntegrator5_h5 *
      Controller_U.FMS_Out.psi_rate_cmd + rtb_Abs *
      rtb_TmpSignalConversionAtMult_0;

    /* Sum: '<S124>/Add2' incorporates:
     *  Product: '<S124>/Multiply4'
     *  Product: '<S124>/Multiply5'
     *  Trigonometry: '<S124>/Cos'
     *  Trigonometry: '<S124>/Cos1'
     *  Trigonometry: '<S124>/Sin'
     */
    rtb_Abs = rtb_Abs * rtb_DiscreteTimeIntegrator5_h5 *
      Controller_U.FMS_Out.psi_rate_cmd - rtb_Divide_m_idx_0 *
      rtb_TmpSignalConversionAtMult_0;

    /* Switch: '<S113>/Switch' incorporates:
     *  Constant: '<S125>/Constant'
     *  Constant: '<S126>/Constant'
     *  RelationalOperator: '<S125>/Compare'
     *  RelationalOperator: '<S126>/Compare'
     *  Switch: '<S113>/Switch1'
     */
    if (Controller_U.FMS_Out.ctrl_mode == 2) {
      rtb_VdotPg = Controller_U.FMS_Out.p_cmd;
      rtb_phi_cmd = Controller_U.FMS_Out.q_cmd;
      rtb_Abs = Controller_U.FMS_Out.r_cmd;
    } else if (Controller_U.FMS_Out.ctrl_mode == 6) {
      /* Switch: '<S127>/Switch' incorporates:
       *  S-Function (sfix_bitop): '<S127>/cmd_p valid'
       *  S-Function (sfix_bitop): '<S127>/cmd_q valid'
       *  S-Function (sfix_bitop): '<S127>/cmd_r valid'
       *  Saturate: '<S112>/Saturation'
       *  Saturate: '<S112>/Saturation2'
       *  Switch: '<S113>/Switch1'
       */
      if ((Controller_U.FMS_Out.cmd_mask & 1) > 0) {
        rtb_VdotPg = Controller_U.FMS_Out.p_cmd;
      } else {
        /* Sum: '<S124>/Add' incorporates:
         *  Inport: '<Root>/INS_Out'
         *  Product: '<S124>/Multiply'
         *  Trigonometry: '<S124>/Sin1'
         */
        rtb_VdotPg = rtb_TmpSignalConversionAtMult_1 - arm_sin_f32
          (Controller_U.INS_Out.theta) * Controller_U.FMS_Out.psi_rate_cmd;

        /* Saturate: '<S112>/Saturation1' incorporates:
         *  Sum: '<S124>/Add'
         */
        if (rtb_VdotPg > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
          rtb_VdotPg = CONTROL_PARAM.MC_P_Q_CMD_LIM;
        } else {
          if (rtb_VdotPg < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
            rtb_VdotPg = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
          }
        }
      }

      if ((Controller_U.FMS_Out.cmd_mask & 2) > 0) {
        rtb_phi_cmd = Controller_U.FMS_Out.q_cmd;
      } else if (rtb_phi_cmd > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        /* Saturate: '<S112>/Saturation2' */
        rtb_phi_cmd = CONTROL_PARAM.MC_P_Q_CMD_LIM;
      } else {
        if (rtb_phi_cmd < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
          /* Saturate: '<S112>/Saturation2' */
          rtb_phi_cmd = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
        }
      }

      if ((Controller_U.FMS_Out.cmd_mask & 4) > 0) {
        rtb_Abs = Controller_U.FMS_Out.r_cmd;
      } else if (rtb_Abs > CONTROL_PARAM.MC_R_CMD_LIM) {
        /* Saturate: '<S112>/Saturation' */
        rtb_Abs = CONTROL_PARAM.MC_R_CMD_LIM;
      } else {
        if (rtb_Abs < -CONTROL_PARAM.MC_R_CMD_LIM) {
          /* Saturate: '<S112>/Saturation' */
          rtb_Abs = -CONTROL_PARAM.MC_R_CMD_LIM;
        }
      }

      /* End of Switch: '<S127>/Switch' */
    } else {
      /* Sum: '<S124>/Add' incorporates:
       *  Inport: '<Root>/INS_Out'
       *  Product: '<S124>/Multiply'
       *  Trigonometry: '<S124>/Sin1'
       */
      rtb_VdotPg = rtb_TmpSignalConversionAtMult_1 - arm_sin_f32
        (Controller_U.INS_Out.theta) * Controller_U.FMS_Out.psi_rate_cmd;

      /* Saturate: '<S112>/Saturation1' incorporates:
       *  Sum: '<S124>/Add'
       */
      if (rtb_VdotPg > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        /* Switch: '<S113>/Switch1' */
        rtb_VdotPg = CONTROL_PARAM.MC_P_Q_CMD_LIM;
      } else {
        if (rtb_VdotPg < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
          /* Switch: '<S113>/Switch1' */
          rtb_VdotPg = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
        }
      }

      /* Saturate: '<S112>/Saturation2' */
      if (rtb_phi_cmd > CONTROL_PARAM.MC_P_Q_CMD_LIM) {
        /* Switch: '<S113>/Switch1' */
        rtb_phi_cmd = CONTROL_PARAM.MC_P_Q_CMD_LIM;
      } else {
        if (rtb_phi_cmd < -CONTROL_PARAM.MC_P_Q_CMD_LIM) {
          /* Switch: '<S113>/Switch1' */
          rtb_phi_cmd = -CONTROL_PARAM.MC_P_Q_CMD_LIM;
        }
      }

      /* Saturate: '<S112>/Saturation' */
      if (rtb_Abs > CONTROL_PARAM.MC_R_CMD_LIM) {
        /* Switch: '<S113>/Switch1' */
        rtb_Abs = CONTROL_PARAM.MC_R_CMD_LIM;
      } else {
        if (rtb_Abs < -CONTROL_PARAM.MC_R_CMD_LIM) {
          /* Switch: '<S113>/Switch1' */
          rtb_Abs = -CONTROL_PARAM.MC_R_CMD_LIM;
        }
      }
    }

    /* End of Switch: '<S113>/Switch' */

    /* Sum: '<S114>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_TmpSignalConversionAtMult_0 = rtb_VdotPg - Controller_U.INS_Out.p;

    /* Saturate: '<S114>/Saturation' */
    if (rtb_TmpSignalConversionAtMult_0 > 3.14159274F) {
      rtb_TmpSignalConversionAtMult_0 = 3.14159274F;
    } else {
      if (rtb_TmpSignalConversionAtMult_0 < -3.14159274F) {
        rtb_TmpSignalConversionAtMult_0 = -3.14159274F;
      }
    }

    /* Sum: '<S114>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_TmpSignalConversionAtMult_1 = rtb_phi_cmd - Controller_U.INS_Out.q;

    /* Saturate: '<S114>/Saturation' */
    if (rtb_TmpSignalConversionAtMult_1 > 3.14159274F) {
      rtb_TmpSignalConversionAtMult_1 = 3.14159274F;
    } else {
      if (rtb_TmpSignalConversionAtMult_1 < -3.14159274F) {
        rtb_TmpSignalConversionAtMult_1 = -3.14159274F;
      }
    }

    /* Sum: '<S114>/Sum' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    rtb_TmpSignalConversionAtMult_2 = rtb_Abs - Controller_U.INS_Out.r;

    /* Saturate: '<S114>/Saturation' */
    if (rtb_TmpSignalConversionAtMult_2 > 3.14159274F) {
      rtb_TmpSignalConversionAtMult_2 = 3.14159274F;
    } else {
      if (rtb_TmpSignalConversionAtMult_2 < -3.14159274F) {
        rtb_TmpSignalConversionAtMult_2 = -3.14159274F;
      }
    }

    /* DiscreteIntegrator: '<S118>/Discrete-Time Integrator5' */
    if (Controller_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] =
        rtb_TmpSignalConversionAtMult_0;
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] =
        rtb_TmpSignalConversionAtMult_1;
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] =
        rtb_TmpSignalConversionAtMult_2;
    }

    /* DiscreteIntegrator: '<S123>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S118>/Discrete-Time Integrator5'
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
     *  DiscreteIntegrator: '<S118>/Discrete-Time Integrator5'
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
      rtb_Divide_m_idx_3 = 0.0F;
      rtb_Saturation_j_idx_1 = 0.0F;
      rtb_Saturation_j_idx_2 = 0.0F;
    } else {
      rtb_Divide_m_idx_3 = rtb_Multiply_ni[0];
      rtb_Saturation_j_idx_1 = rtb_Multiply_ni[1];
      rtb_Saturation_j_idx_2 = rtb_Multiply_ni[2];
    }

    /* End of Switch: '<S123>/Switch' */

    /* Product: '<S120>/Multiply' incorporates:
     *  Constant: '<S120>/gain1'
     */
    rtb_Gain_ms = CONTROL_PARAM.MC_ROLL_RATE_D * rtb_Divide_m_idx_3;

    /* Saturate: '<S120>/Saturation' */
    if (rtb_Gain_ms > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Gain_ms = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Gain_ms < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Gain_ms = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    rtb_Divide_m_idx_3 = rtb_Gain_ms;

    /* DeadZone: '<S119>/Dead Zone' incorporates:
     *  Product: '<S120>/Multiply'
     */
    if (rtb_VdotPg > 0.1F) {
      rtb_VdotPg -= 0.1F;
    } else if (rtb_VdotPg >= -0.1F) {
      rtb_VdotPg = 0.0F;
    } else {
      rtb_VdotPg -= -0.1F;
    }

    /* Product: '<S120>/Multiply' incorporates:
     *  Constant: '<S120>/gain2'
     */
    rtb_Gain_ms = CONTROL_PARAM.MC_PITCH_RATE_D * rtb_Saturation_j_idx_1;

    /* Saturate: '<S120>/Saturation' */
    if (rtb_Gain_ms > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Gain_ms = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Gain_ms < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Gain_ms = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    rtb_Saturation_j_idx_1 = rtb_Gain_ms;

    /* DeadZone: '<S119>/Dead Zone' incorporates:
     *  Product: '<S120>/Multiply'
     */
    if (rtb_phi_cmd > 0.1F) {
      rtb_phi_cmd -= 0.1F;
    } else if (rtb_phi_cmd >= -0.1F) {
      rtb_phi_cmd = 0.0F;
    } else {
      rtb_phi_cmd -= -0.1F;
    }

    /* Product: '<S120>/Multiply' incorporates:
     *  Constant: '<S120>/gain3'
     */
    rtb_Gain_ms = CONTROL_PARAM.MC_YAW_RATE_D * rtb_Saturation_j_idx_2;

    /* Saturate: '<S120>/Saturation' */
    if (rtb_Gain_ms > CONTROL_PARAM.MC_RATE_D_MAX) {
      rtb_Gain_ms = CONTROL_PARAM.MC_RATE_D_MAX;
    } else {
      if (rtb_Gain_ms < CONTROL_PARAM.MC_RATE_D_MIN) {
        rtb_Gain_ms = CONTROL_PARAM.MC_RATE_D_MIN;
      }
    }

    /* SignalConversion: '<S5>/BusConversion_InsertedFor_VTOL_actuator_cmd_at_inport_0' incorporates:
     *  Constant: '<S122>/gain1'
     *  Constant: '<S122>/gain2'
     *  DiscreteIntegrator: '<S118>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S121>/Discrete-Time Integrator'
     *  Gain: '<S115>/Gain'
     *  Gain: '<S119>/Gain'
     *  Product: '<S122>/Multiply'
     *  Sum: '<S111>/Sum'
     *  Sum: '<S116>/Add'
     */
    Controller_B.mc_torque_cmd[0] = ((CONTROL_PARAM.MC_ROLL_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0]) + rtb_Divide_m_idx_3) +
      CONTROL_PARAM.MC_ROLL_RATE_FF * (1.11111116F * rtb_VdotPg);
    Controller_B.mc_torque_cmd[1] = ((CONTROL_PARAM.MC_PITCH_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1]) + rtb_Saturation_j_idx_1)
      + CONTROL_PARAM.MC_ROLL_RATE_FF * (1.11111116F * rtb_phi_cmd);

    /* DeadZone: '<S119>/Dead Zone' */
    if (rtb_Abs > 0.1F) {
      rtb_phi_cmd = rtb_Abs - 0.1F;
    } else if (rtb_Abs >= -0.1F) {
      rtb_phi_cmd = 0.0F;
    } else {
      rtb_phi_cmd = rtb_Abs - -0.1F;
    }

    /* SignalConversion: '<S5>/BusConversion_InsertedFor_VTOL_actuator_cmd_at_inport_0' incorporates:
     *  Constant: '<S122>/gain3'
     *  DiscreteIntegrator: '<S118>/Discrete-Time Integrator5'
     *  DiscreteIntegrator: '<S121>/Discrete-Time Integrator'
     *  Gain: '<S115>/Gain1'
     *  Gain: '<S119>/Gain'
     *  Product: '<S122>/Multiply'
     *  Sum: '<S111>/Sum'
     *  Sum: '<S116>/Add'
     */
    Controller_B.mc_torque_cmd[2] = ((CONTROL_PARAM.MC_YAW_RATE_P *
      Controller_DW.DiscreteTimeIntegrator5_DSTATE[2] +
      Controller_DW.DiscreteTimeIntegrator_DSTATE[2]) + rtb_Gain_ms) +
      1.11111116F * rtb_phi_cmd * CONTROL_PARAM.MC_PITCH_RATE_FF;

    /* Product: '<S146>/Multiply1' incorporates:
     *  Constant: '<S146>/const1'
     *  DiscreteIntegrator: '<S143>/Integrator'
     */
    rtb_Divide_m_idx_0 = Controller_DW.Integrator_DSTATE[0] * 0.1F;
    rtb_phi_cmd = Controller_DW.Integrator_DSTATE[1] * 0.1F;

    /* Sum: '<S146>/Add' incorporates:
     *  DiscreteIntegrator: '<S143>/Integrator1'
     *  Sum: '<S143>/Subtract'
     */
    rtb_Divide_m_idx_1 = (Controller_DW.Integrator1_DSTATE[0] -
                          Controller_U.FMS_Out.u_cmd) + rtb_Divide_m_idx_0;
    rtb_Abs = (Controller_DW.Integrator1_DSTATE[1] - Controller_U.FMS_Out.v_cmd)
      + rtb_phi_cmd;

    /* Signum: '<S146>/Sign' */
    if (rtb_Divide_m_idx_1 < 0.0F) {
      rtb_Divide_m_idx_2 = -1.0F;
    } else if (rtb_Divide_m_idx_1 > 0.0F) {
      rtb_Divide_m_idx_2 = 1.0F;
    } else {
      rtb_Divide_m_idx_2 = rtb_Divide_m_idx_1;
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
    rtb_Gain_ms = (sqrtf((8.0F * fabsf(rtb_Divide_m_idx_1) + Controller_ConstB.d)
                         * Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
      rtb_Divide_m_idx_2 + rtb_Divide_m_idx_0;

    /* Sum: '<S146>/Add3' incorporates:
     *  Signum: '<S146>/Sign'
     */
    rtb_DiscreteTimeIntegrator5_h5 = rtb_Divide_m_idx_1 + Controller_ConstB.d;

    /* Sum: '<S146>/Subtract1' incorporates:
     *  Signum: '<S146>/Sign'
     */
    rtb_Divide_m_idx_3 = rtb_Divide_m_idx_1 - Controller_ConstB.d;

    /* Signum: '<S146>/Sign1' */
    if (rtb_DiscreteTimeIntegrator5_h5 < 0.0F) {
      rtb_DiscreteTimeIntegrator5_h5 = -1.0F;
    } else {
      if (rtb_DiscreteTimeIntegrator5_h5 > 0.0F) {
        rtb_DiscreteTimeIntegrator5_h5 = 1.0F;
      }
    }

    /* Signum: '<S146>/Sign2' */
    if (rtb_Divide_m_idx_3 < 0.0F) {
      rtb_Divide_m_idx_3 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_3 > 0.0F) {
        rtb_Divide_m_idx_3 = 1.0F;
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
    rtb_Switch2_n_idx_0 = ((rtb_Divide_m_idx_1 - rtb_Gain_ms) +
      rtb_Divide_m_idx_0) * ((rtb_DiscreteTimeIntegrator5_h5 -
      rtb_Divide_m_idx_3) * 0.5F) + rtb_Gain_ms;

    /* Signum: '<S146>/Sign' */
    if (rtb_Abs < 0.0F) {
      rtb_Divide_m_idx_0 = -1.0F;
    } else if (rtb_Abs > 0.0F) {
      rtb_Divide_m_idx_0 = 1.0F;
    } else {
      rtb_Divide_m_idx_0 = rtb_Abs;
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
    rtb_Gain_ms = (sqrtf((8.0F * fabsf(rtb_Abs) + Controller_ConstB.d) *
                         Controller_ConstB.d) - Controller_ConstB.d) * 0.5F *
      rtb_Divide_m_idx_0 + rtb_phi_cmd;

    /* Sum: '<S146>/Add3' incorporates:
     *  Signum: '<S146>/Sign'
     */
    rtb_DiscreteTimeIntegrator5_h5 = rtb_Abs + Controller_ConstB.d;

    /* Sum: '<S146>/Subtract1' incorporates:
     *  Signum: '<S146>/Sign'
     */
    rtb_Divide_m_idx_3 = rtb_Abs - Controller_ConstB.d;

    /* Signum: '<S146>/Sign1' */
    if (rtb_DiscreteTimeIntegrator5_h5 < 0.0F) {
      rtb_DiscreteTimeIntegrator5_h5 = -1.0F;
    } else {
      if (rtb_DiscreteTimeIntegrator5_h5 > 0.0F) {
        rtb_DiscreteTimeIntegrator5_h5 = 1.0F;
      }
    }

    /* Signum: '<S146>/Sign2' */
    if (rtb_Divide_m_idx_3 < 0.0F) {
      rtb_Divide_m_idx_3 = -1.0F;
    } else {
      if (rtb_Divide_m_idx_3 > 0.0F) {
        rtb_Divide_m_idx_3 = 1.0F;
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
    rtb_Gain_ms += ((rtb_Abs - rtb_Gain_ms) + rtb_phi_cmd) *
      ((rtb_DiscreteTimeIntegrator5_h5 - rtb_Divide_m_idx_3) * 0.5F);

    /* Gain: '<S159>/Gain' incorporates:
     *  DiscreteIntegrator: '<S161>/Integrator1'
     *  Inport: '<Root>/INS_Out'
     *  Sum: '<S159>/Sum1'
     */
    rtb_Divide_m_idx_1 = -(Controller_DW.Integrator1_DSTATE_e -
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
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i = rtb_Divide_m_idx_1;
    }

    if ((Controller_U.FMS_Out.reset != 0) ||
        (Controller_DW.DiscreteTimeIntegrator1_Prev_ks != 0)) {
      Controller_DW.DiscreteTimeIntegrator1_DSTAT_i = rtb_Divide_m_idx_1;
    }

    /* Gain: '<S166>/Gain' incorporates:
     *  DiscreteIntegrator: '<S166>/Discrete-Time Integrator1'
     *  Sum: '<S166>/Sum5'
     */
    rtb_Divide_m_idx_2 = (rtb_Divide_m_idx_1 -
                          Controller_DW.DiscreteTimeIntegrator1_DSTAT_i) *
      62.831852F;

    /* Switch: '<S155>/Switch' incorporates:
     *  Constant: '<S157>/Constant'
     *  RelationalOperator: '<S157>/Compare'
     */
    if (Controller_U.FMS_Out.ctrl_mode <= 3) {
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
      rtb_Divide_m_idx_0 = arm_cos_f32(Controller_U.INS_Out.phi) * arm_cos_f32
        (Controller_U.INS_Out.theta);

      /* Gain: '<S158>/Gain' */
      rtb_Divide_m_idx_3 = 2.0F * rtb_Divide_m_idx_0;

      /* Saturate: '<S158>/Saturation1' */
      if (rtb_Divide_m_idx_0 > 1.0F) {
        rtb_Divide_m_idx_0 = 1.0F;
      } else {
        if (rtb_Divide_m_idx_0 < 0.5F) {
          rtb_Divide_m_idx_0 = 0.5F;
        }
      }

      /* End of Saturate: '<S158>/Saturation1' */

      /* Product: '<S158>/Divide' incorporates:
       *  Constant: '<S158>/Constant'
       */
      rtb_phi_cmd = 1.0F / rtb_Divide_m_idx_0;

      /* Switch: '<S166>/Switch' incorporates:
       *  Gain: '<S166>/Gain1'
       */
      if (Controller_U.FMS_Out.reset > 0) {
        rtb_Saturation_j_idx_1 = 0.0F;
      } else {
        rtb_Saturation_j_idx_1 = rtb_Divide_m_idx_2;
      }

      /* End of Switch: '<S166>/Switch' */

      /* Product: '<S163>/Multiply' incorporates:
       *  Constant: '<S163>/kd'
       */
      rtb_Divide_m_idx_0 = CONTROL_PARAM.MC_VEL_Z_D * rtb_Saturation_j_idx_1;

      /* Saturate: '<S163>/Saturation' */
      if (rtb_Divide_m_idx_0 > CONTROL_PARAM.MC_VEL_Z_D_MAX) {
        rtb_Divide_m_idx_0 = CONTROL_PARAM.MC_VEL_Z_D_MAX;
      } else {
        if (rtb_Divide_m_idx_0 < CONTROL_PARAM.MC_VEL_Z_D_MIN) {
          rtb_Divide_m_idx_0 = CONTROL_PARAM.MC_VEL_Z_D_MIN;
        }
      }

      /* End of Saturate: '<S163>/Saturation' */

      /* Saturate: '<S158>/Saturation' */
      if (rtb_Divide_m_idx_3 > 1.0F) {
        rtb_Divide_m_idx_3 = 1.0F;
      } else {
        if (rtb_Divide_m_idx_3 < 0.0F) {
          rtb_Divide_m_idx_3 = 0.0F;
        }
      }

      /* End of Saturate: '<S158>/Saturation' */

      /* SignalConversion: '<S5>/BusConversion_InsertedFor_VTOL_actuator_cmd_at_inport_0' incorporates:
       *  Constant: '<S156>/hover_throttle'
       *  Constant: '<S165>/kp'
       *  DiscreteIntegrator: '<S164>/Discrete-Time Integrator'
       *  Product: '<S158>/Multiply1'
       *  Product: '<S165>/Multiply'
       *  Sum: '<S156>/Sum'
       *  Sum: '<S160>/Add'
       */
      Controller_B.mc_force_cmd[2] = ((CONTROL_PARAM.MC_VEL_Z_P *
        rtb_Divide_m_idx_1 + Controller_DW.DiscreteTimeIntegrator_DSTATE_l) +
        rtb_Divide_m_idx_0) * rtb_phi_cmd * rtb_Divide_m_idx_3 +
        CONTROL_PARAM.MC_HOVER_THRO;
    }

    /* End of Switch: '<S155>/Switch' */

    /* SignalConversion: '<S5>/BusConversion_InsertedFor_VTOL_actuator_cmd_at_inport_0' */
    Controller_B.mc_force_cmd[0] = Controller_ConstB.TmpBufferAtConstantOutport1;
    Controller_B.mc_force_cmd[1] = Controller_ConstB.TmpBufferAtConstantOutport1;

    /* Product: '<S162>/Multiply1' incorporates:
     *  Constant: '<S162>/const1'
     *  DiscreteIntegrator: '<S161>/Integrator'
     */
    rtb_DiscreteTimeIntegrator5_h5 = Controller_DW.Integrator_DSTATE_j * 0.05F;

    /* Sum: '<S162>/Add' incorporates:
     *  DiscreteIntegrator: '<S161>/Integrator1'
     *  Sum: '<S161>/Subtract'
     */
    rtb_phi_cmd = (Controller_DW.Integrator1_DSTATE_e -
                   Controller_U.FMS_Out.w_cmd) + rtb_DiscreteTimeIntegrator5_h5;

    /* Signum: '<S162>/Sign' */
    if (rtb_phi_cmd < 0.0F) {
      rtb_Divide_m_idx_0 = -1.0F;
    } else if (rtb_phi_cmd > 0.0F) {
      rtb_Divide_m_idx_0 = 1.0F;
    } else {
      rtb_Divide_m_idx_0 = rtb_phi_cmd;
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
    rtb_Divide_m_idx_0 = (sqrtf((8.0F * fabsf(rtb_phi_cmd) +
      Controller_ConstB.d_i) * Controller_ConstB.d_i) - Controller_ConstB.d_i) *
      0.5F * rtb_Divide_m_idx_0 + rtb_DiscreteTimeIntegrator5_h5;

    /* Sum: '<S162>/Add4' */
    rtb_Abs = (rtb_phi_cmd - rtb_Divide_m_idx_0) +
      rtb_DiscreteTimeIntegrator5_h5;

    /* Sum: '<S162>/Add3' */
    rtb_DiscreteTimeIntegrator5_h5 = rtb_phi_cmd + Controller_ConstB.d_i;

    /* Sum: '<S162>/Subtract1' */
    rtb_phi_cmd -= Controller_ConstB.d_i;

    /* Signum: '<S162>/Sign1' */
    if (rtb_DiscreteTimeIntegrator5_h5 < 0.0F) {
      rtb_DiscreteTimeIntegrator5_h5 = -1.0F;
    } else {
      if (rtb_DiscreteTimeIntegrator5_h5 > 0.0F) {
        rtb_DiscreteTimeIntegrator5_h5 = 1.0F;
      }
    }

    /* End of Signum: '<S162>/Sign1' */

    /* Signum: '<S162>/Sign2' */
    if (rtb_phi_cmd < 0.0F) {
      rtb_phi_cmd = -1.0F;
    } else {
      if (rtb_phi_cmd > 0.0F) {
        rtb_phi_cmd = 1.0F;
      }
    }

    /* End of Signum: '<S162>/Sign2' */

    /* Sum: '<S162>/Add5' incorporates:
     *  Gain: '<S162>/Gain2'
     *  Product: '<S162>/Multiply4'
     *  Sum: '<S162>/Subtract2'
     */
    rtb_Divide_m_idx_0 += (rtb_DiscreteTimeIntegrator5_h5 - rtb_phi_cmd) * 0.5F *
      rtb_Abs;

    /* Update for DiscreteIntegrator: '<S121>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S121>/gain1'
     *  Constant: '<S121>/gain2'
     *  Constant: '<S121>/gain3'
     *  DiscreteIntegrator: '<S118>/Discrete-Time Integrator5'
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
      CONTROL_PARAM.MC_VEL_XY_I * rtb_MultiportSwitch_idx_0 * 0.002F;
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
      rtb_aux_att_error_B_rad_idx_0;

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
      CONTROL_PARAM.MC_VEL_XY_I * rtb_MultiportSwitch_idx_1 * 0.002F;
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
      rtb_aux_att_error_B_rad_idx_1;
    Controller_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Update for DiscreteIntegrator: '<S118>/Discrete-Time Integrator5' */
    Controller_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;

    /* Update for DiscreteIntegrator: '<S123>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_IC_LO_j = 0U;

    /* Update for DiscreteIntegrator: '<S118>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S118>/Gain'
     *  Sum: '<S118>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[0] +=
      (rtb_TmpSignalConversionAtMult_0 -
       Controller_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S123>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[0] += 0.002F *
      rtb_Multiply_ni[0];

    /* Update for DiscreteIntegrator: '<S118>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S118>/Gain'
     *  Sum: '<S118>/Sum5'
     */
    Controller_DW.DiscreteTimeIntegrator5_DSTATE[1] +=
      (rtb_TmpSignalConversionAtMult_1 -
       Controller_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 188.49556F * 0.002F;

    /* Update for DiscreteIntegrator: '<S123>/Discrete-Time Integrator1' */
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_n[1] += 0.002F *
      rtb_Multiply_ni[1];

    /* Update for DiscreteIntegrator: '<S118>/Discrete-Time Integrator5' incorporates:
     *  Gain: '<S118>/Gain'
     *  Sum: '<S118>/Sum5'
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
    rtb_DiscreteTimeIntegrator5_h5 = rtb_Switch2_n_idx_0 + Controller_ConstB.d;

    /* Signum: '<S146>/Sign4' incorporates:
     *  Product: '<S146>/Divide'
     *  Sum: '<S146>/Subtract3'
     */
    rtb_MultiportSwitch_idx_0 = rtb_Switch2_n_idx_0 - Controller_ConstB.d;

    /* Signum: '<S146>/Sign5' incorporates:
     *  Product: '<S146>/Divide'
     */
    if (rtb_Switch2_n_idx_0 < 0.0F) {
      rtb_MultiportSwitch_idx_1 = -1.0F;
    } else if (rtb_Switch2_n_idx_0 > 0.0F) {
      rtb_MultiportSwitch_idx_1 = 1.0F;
    } else {
      rtb_MultiportSwitch_idx_1 = rtb_Switch2_n_idx_0;
    }

    /* Signum: '<S146>/Sign3' */
    if (rtb_DiscreteTimeIntegrator5_h5 < 0.0F) {
      rtb_DiscreteTimeIntegrator5_h5 = -1.0F;
    } else {
      if (rtb_DiscreteTimeIntegrator5_h5 > 0.0F) {
        rtb_DiscreteTimeIntegrator5_h5 = 1.0F;
      }
    }

    /* Signum: '<S146>/Sign4' */
    if (rtb_MultiportSwitch_idx_0 < 0.0F) {
      rtb_MultiportSwitch_idx_0 = -1.0F;
    } else {
      if (rtb_MultiportSwitch_idx_0 > 0.0F) {
        rtb_MultiportSwitch_idx_0 = 1.0F;
      }
    }

    /* Signum: '<S146>/Sign6' incorporates:
     *  Product: '<S146>/Divide'
     */
    if (rtb_Switch2_n_idx_0 < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else if (rtb_Switch2_n_idx_0 > 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_0 = rtb_Switch2_n_idx_0;
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
    Controller_DW.Integrator_DSTATE[0] += ((rtb_Switch2_n_idx_0 /
      Controller_ConstB.d - rtb_MultiportSwitch_idx_1) * Controller_ConstB.Gain4
      * ((rtb_DiscreteTimeIntegrator5_h5 - rtb_MultiportSwitch_idx_0) * 0.5F) -
      rtb_TmpSignalConversionAtMult_0 * 78.448F) * 0.002F;

    /* Signum: '<S146>/Sign3' incorporates:
     *  Sum: '<S146>/Add6'
     */
    rtb_DiscreteTimeIntegrator5_h5 = rtb_Gain_ms + Controller_ConstB.d;

    /* Signum: '<S146>/Sign4' incorporates:
     *  Sum: '<S146>/Subtract3'
     */
    rtb_MultiportSwitch_idx_0 = rtb_Gain_ms - Controller_ConstB.d;

    /* Signum: '<S146>/Sign5' */
    if (rtb_Gain_ms < 0.0F) {
      rtb_MultiportSwitch_idx_1 = -1.0F;
    } else if (rtb_Gain_ms > 0.0F) {
      rtb_MultiportSwitch_idx_1 = 1.0F;
    } else {
      rtb_MultiportSwitch_idx_1 = rtb_Gain_ms;
    }

    /* Signum: '<S146>/Sign3' */
    if (rtb_DiscreteTimeIntegrator5_h5 < 0.0F) {
      rtb_DiscreteTimeIntegrator5_h5 = -1.0F;
    } else {
      if (rtb_DiscreteTimeIntegrator5_h5 > 0.0F) {
        rtb_DiscreteTimeIntegrator5_h5 = 1.0F;
      }
    }

    /* Signum: '<S146>/Sign4' */
    if (rtb_MultiportSwitch_idx_0 < 0.0F) {
      rtb_MultiportSwitch_idx_0 = -1.0F;
    } else {
      if (rtb_MultiportSwitch_idx_0 > 0.0F) {
        rtb_MultiportSwitch_idx_0 = 1.0F;
      }
    }

    /* Signum: '<S146>/Sign6' */
    if (rtb_Gain_ms < 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else if (rtb_Gain_ms > 0.0F) {
      rtb_TmpSignalConversionAtMult_0 = 1.0F;
    } else {
      rtb_TmpSignalConversionAtMult_0 = rtb_Gain_ms;
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
    Controller_DW.Integrator_DSTATE[1] += ((rtb_Gain_ms / Controller_ConstB.d -
      rtb_MultiportSwitch_idx_1) * Controller_ConstB.Gain4 *
      ((rtb_DiscreteTimeIntegrator5_h5 - rtb_MultiportSwitch_idx_0) * 0.5F) -
      rtb_TmpSignalConversionAtMult_0 * 78.448F) * 0.002F;

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
      rtb_Divide_m_idx_1 * 0.002F;
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
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_i += 0.002F * rtb_Divide_m_idx_2;
    Controller_DW.DiscreteTimeIntegrator1_Prev_ks = (int8_T)
      (Controller_U.FMS_Out.reset > 0);

    /* Signum: '<S162>/Sign6' incorporates:
     *  Signum: '<S162>/Sign5'
     */
    if (rtb_Divide_m_idx_0 < 0.0F) {
      rtb_MultiportSwitch_idx_1 = -1.0F;

      /* Signum: '<S162>/Sign5' */
      rtb_TmpSignalConversionAtMult_0 = -1.0F;
    } else if (rtb_Divide_m_idx_0 > 0.0F) {
      rtb_MultiportSwitch_idx_1 = 1.0F;

      /* Signum: '<S162>/Sign5' */
      rtb_TmpSignalConversionAtMult_0 = 1.0F;
    } else {
      rtb_MultiportSwitch_idx_1 = rtb_Divide_m_idx_0;

      /* Signum: '<S162>/Sign5' */
      rtb_TmpSignalConversionAtMult_0 = rtb_Divide_m_idx_0;
    }

    /* End of Signum: '<S162>/Sign6' */

    /* Sum: '<S162>/Add6' */
    rtb_DiscreteTimeIntegrator5_h5 = rtb_Divide_m_idx_0 + Controller_ConstB.d_i;

    /* Sum: '<S162>/Subtract3' */
    rtb_MultiportSwitch_idx_0 = rtb_Divide_m_idx_0 - Controller_ConstB.d_i;

    /* Signum: '<S162>/Sign3' */
    if (rtb_DiscreteTimeIntegrator5_h5 < 0.0F) {
      rtb_DiscreteTimeIntegrator5_h5 = -1.0F;
    } else {
      if (rtb_DiscreteTimeIntegrator5_h5 > 0.0F) {
        rtb_DiscreteTimeIntegrator5_h5 = 1.0F;
      }
    }

    /* End of Signum: '<S162>/Sign3' */

    /* Signum: '<S162>/Sign4' */
    if (rtb_MultiportSwitch_idx_0 < 0.0F) {
      rtb_MultiportSwitch_idx_0 = -1.0F;
    } else {
      if (rtb_MultiportSwitch_idx_0 > 0.0F) {
        rtb_MultiportSwitch_idx_0 = 1.0F;
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
    Controller_DW.Integrator_DSTATE_j += ((rtb_Divide_m_idx_0 /
      Controller_ConstB.d_i - rtb_TmpSignalConversionAtMult_0) *
      Controller_ConstB.Gain4_p * ((rtb_DiscreteTimeIntegrator5_h5 -
      rtb_MultiportSwitch_idx_0) * 0.5F) - rtb_MultiportSwitch_idx_1 * 78.448F) *
      0.002F;

    /* End of Outputs for SubSystem: '<S2>/MC_Controller' */
    break;
  }

  /* End of SwitchCase: '<S7>/Switch Case1' */

  /* Outputs for Atomic SubSystem: '<S6>/VTOL_Control_Allocation' */
#if AIRFRAME == 1

  /* Output and update for atomic system: '<S168>/VTOL1' */
  {
    real32_T b_max_p;
    int32_T max_index_p;
    real32_T rtb_Saturation3_j;
    real32_T rtb_Gain1_l;
    real32_T rtb_MatrixConcatenate[12];
    real32_T rtb_Saturation5_o[4];
    real32_T rtb_Subtract_h;
    real32_T rtb_Saturation_fa[9];
    real32_T rtb_Saturation4_n[4];
    real32_T rtb_Sum_e[4];
    int32_T i_p;
    real32_T rtb_Switch_gr_idx_1_p;
    real32_T rtb_Saturation1_l_idx_2_p;
    real32_T rtb_Saturation1_l_idx_0_p;
    real32_T rtb_Saturation1_l_idx_1_p;
    uint16_T u0_p;

    /* Saturate: '<S185>/Saturation' incorporates:
     *  Bias: '<S185>/Bias'
     *  Bias: '<S185>/Bias1'
     *  Bias: '<S185>/Bias2'
     *  Bias: '<S185>/Bias3'
     *  Constant: '<S185>/Constant'
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

    /* End of Saturate: '<S185>/Saturation' */

    /* Saturate: '<S172>/Saturation1' */
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

    /* End of Saturate: '<S172>/Saturation1' */

    /* Gain: '<S172>/Gain1' incorporates:
     *  Bias: '<S172>/Bias'
     *  Constant: '<S172>/Constant'
     */
    rtb_Gain1_l = ((real32_T)CONTROL_PARAM.MC_OUT_MAX + -1000.0F) * 0.001F;

    /* Saturate: '<S172>/Saturation2' */
    if (Controller_B.mc_force_cmd[2] > 1.0F) {
      rtb_Saturation3_j = 1.0F;
    } else if (Controller_B.mc_force_cmd[2] < 0.0F) {
      rtb_Saturation3_j = 0.0F;
    } else {
      rtb_Saturation3_j = Controller_B.mc_force_cmd[2];
    }

    /* End of Saturate: '<S172>/Saturation2' */
    for (i_p = 0; i_p < 4; i_p++) {
      /* Product: '<S172>/Multiply' */
      rtb_Switch_gr_idx_1_p = Controller_ConstB.VTOL1.pq_column[i_p + 4] *
        rtb_Saturation1_l_idx_1_p + Controller_ConstB.VTOL1.pq_column[i_p] *
        rtb_Saturation1_l_idx_0_p;

      /* Sum: '<S172>/Sum' */
      rtb_Sum_e[i_p] = rtb_Switch_gr_idx_1_p + rtb_Saturation3_j;

      /* Product: '<S172>/Multiply' */
      rtb_Saturation4_n[i_p] = rtb_Switch_gr_idx_1_p;
    }

    /* Gain: '<S172>/Gain2' incorporates:
     *  Bias: '<S172>/Bias1'
     *  Constant: '<S172>/Constant1'
     */
    rtb_Saturation1_l_idx_0_p = ((real32_T)CONTROL_PARAM.MC_OUT_MIN + -1000.0F) *
      0.001F;

    /* MinMax: '<S172>/Max' */
    rtb_Switch_gr_idx_1_p = fmaxf(fmaxf(fmaxf(rtb_Sum_e[0], rtb_Sum_e[1]),
      rtb_Sum_e[2]), rtb_Sum_e[3]);

    /* MinMax: '<S172>/Max1' */
    b_max_p = fminf(fminf(fminf(rtb_Sum_e[0], rtb_Sum_e[1]), rtb_Sum_e[2]),
                    rtb_Sum_e[3]);

    /* Switch: '<S179>/Switch' incorporates:
     *  Logic: '<S179>/Logical Operator'
     *  MinMax: '<S172>/Max'
     *  MinMax: '<S172>/Max1'
     *  RelationalOperator: '<S179>/Relational Operator'
     *  RelationalOperator: '<S179>/Relational Operator1'
     */
    if ((rtb_Switch_gr_idx_1_p > rtb_Gain1_l) || (b_max_p <
         rtb_Saturation1_l_idx_0_p)) {
      /* Sum: '<S179>/Subtract1' */
      rtb_Saturation1_l_idx_1_p = rtb_Gain1_l - rtb_Saturation1_l_idx_0_p;

      /* Sum: '<S179>/Subtract' */
      rtb_Subtract_h = rtb_Switch_gr_idx_1_p - b_max_p;

      /* Switch: '<S179>/Switch1' incorporates:
       *  Constant: '<S179>/Constant3'
       *  Gain: '<S179>/Gain'
       *  Product: '<S179>/Divide'
       *  RelationalOperator: '<S179>/Relational Operator2'
       *  Sum: '<S179>/Add'
       *  Sum: '<S179>/Subtract2'
       *  Sum: '<S179>/Subtract3'
       */
      if (rtb_Subtract_h > rtb_Saturation1_l_idx_1_p) {
        rtb_Saturation1_l_idx_1_p /= rtb_Subtract_h;
        rtb_Switch_gr_idx_1_p = ((rtb_Gain1_l - rtb_Switch_gr_idx_1_p) +
          (rtb_Saturation1_l_idx_0_p - b_max_p)) * 0.5F;
      } else {
        rtb_Saturation1_l_idx_1_p = 1.0F;

        /* Switch: '<S179>/Switch2' incorporates:
         *  Constant: '<S179>/Constant3'
         *  RelationalOperator: '<S179>/Relational Operator3'
         *  Sum: '<S179>/Subtract4'
         *  Sum: '<S179>/Subtract5'
         */
        if (rtb_Switch_gr_idx_1_p > rtb_Gain1_l) {
          rtb_Switch_gr_idx_1_p = rtb_Gain1_l - rtb_Switch_gr_idx_1_p;
        } else {
          rtb_Switch_gr_idx_1_p = rtb_Saturation1_l_idx_0_p - b_max_p;
        }

        /* End of Switch: '<S179>/Switch2' */
      }

      /* End of Switch: '<S179>/Switch1' */
    } else {
      rtb_Saturation1_l_idx_1_p = 1.0F;
      rtb_Switch_gr_idx_1_p = 0.0F;
    }

    /* End of Switch: '<S179>/Switch' */

    /* Sum: '<S172>/Sum1' */
    rtb_Saturation3_j += rtb_Switch_gr_idx_1_p;

    /* Saturate: '<S172>/Saturation3' */
    if (rtb_Saturation3_j > 1.0F) {
      rtb_Saturation3_j = 1.0F;
    } else {
      if (rtb_Saturation3_j < 0.0F) {
        rtb_Saturation3_j = 0.0F;
      }
    }

    /* End of Saturate: '<S172>/Saturation3' */

    /* MATLAB Function: '<S172>/R_Remix' */
    rtb_Subtract_h = 100.0F;
    b_max_p = -100.0F;
    i_p = 0;
    max_index_p = 0;

    /* Sum: '<S172>/Sum2' incorporates:
     *  Product: '<S172>/Multiply1'
     */
    rtb_Switch_gr_idx_1_p = rtb_Saturation4_n[0] * rtb_Saturation1_l_idx_1_p +
      rtb_Saturation3_j;

    /* Saturate: '<S172>/Saturation4' */
    if (rtb_Switch_gr_idx_1_p > 1.0F) {
      rtb_Switch_gr_idx_1_p = 1.0F;
    } else {
      if (rtb_Switch_gr_idx_1_p < 0.0F) {
        rtb_Switch_gr_idx_1_p = 0.0F;
      }
    }

    /* Sum: '<S172>/Sum3' incorporates:
     *  Product: '<S172>/Multiply2'
     */
    rtb_Switch_gr_idx_1_p += Controller_ConstB.VTOL1.r_column[0] *
      rtb_Saturation1_l_idx_2_p;

    /* MATLAB Function: '<S172>/R_Remix' */
    if (rtb_Switch_gr_idx_1_p < 100.0F) {
      rtb_Subtract_h = rtb_Switch_gr_idx_1_p;
      i_p = 1;
    }

    if (rtb_Switch_gr_idx_1_p > -100.0F) {
      b_max_p = rtb_Switch_gr_idx_1_p;
      max_index_p = 1;
    }

    /* Product: '<S172>/Multiply1' */
    rtb_Saturation4_n[0] = rtb_Switch_gr_idx_1_p;

    /* Sum: '<S172>/Sum2' incorporates:
     *  Product: '<S172>/Multiply1'
     */
    rtb_Switch_gr_idx_1_p = rtb_Saturation4_n[1] * rtb_Saturation1_l_idx_1_p +
      rtb_Saturation3_j;

    /* Saturate: '<S172>/Saturation4' */
    if (rtb_Switch_gr_idx_1_p > 1.0F) {
      rtb_Switch_gr_idx_1_p = 1.0F;
    } else {
      if (rtb_Switch_gr_idx_1_p < 0.0F) {
        rtb_Switch_gr_idx_1_p = 0.0F;
      }
    }

    /* Sum: '<S172>/Sum3' incorporates:
     *  Product: '<S172>/Multiply2'
     */
    rtb_Switch_gr_idx_1_p += Controller_ConstB.VTOL1.r_column[1] *
      rtb_Saturation1_l_idx_2_p;

    /* MATLAB Function: '<S172>/R_Remix' */
    if (rtb_Switch_gr_idx_1_p < rtb_Subtract_h) {
      rtb_Subtract_h = rtb_Switch_gr_idx_1_p;
      i_p = 2;
    }

    if (rtb_Switch_gr_idx_1_p > b_max_p) {
      b_max_p = rtb_Switch_gr_idx_1_p;
      max_index_p = 2;
    }

    /* Product: '<S172>/Multiply1' */
    rtb_Saturation4_n[1] = rtb_Switch_gr_idx_1_p;

    /* Sum: '<S172>/Sum2' incorporates:
     *  Product: '<S172>/Multiply1'
     */
    rtb_Switch_gr_idx_1_p = rtb_Saturation4_n[2] * rtb_Saturation1_l_idx_1_p +
      rtb_Saturation3_j;

    /* Saturate: '<S172>/Saturation4' */
    if (rtb_Switch_gr_idx_1_p > 1.0F) {
      rtb_Switch_gr_idx_1_p = 1.0F;
    } else {
      if (rtb_Switch_gr_idx_1_p < 0.0F) {
        rtb_Switch_gr_idx_1_p = 0.0F;
      }
    }

    /* Sum: '<S172>/Sum3' incorporates:
     *  Product: '<S172>/Multiply2'
     */
    rtb_Switch_gr_idx_1_p += Controller_ConstB.VTOL1.r_column[2] *
      rtb_Saturation1_l_idx_2_p;

    /* MATLAB Function: '<S172>/R_Remix' */
    if (rtb_Switch_gr_idx_1_p < rtb_Subtract_h) {
      rtb_Subtract_h = rtb_Switch_gr_idx_1_p;
      i_p = 3;
    }

    if (rtb_Switch_gr_idx_1_p > b_max_p) {
      b_max_p = rtb_Switch_gr_idx_1_p;
      max_index_p = 3;
    }

    /* Product: '<S172>/Multiply1' */
    rtb_Saturation4_n[2] = rtb_Switch_gr_idx_1_p;

    /* Sum: '<S172>/Sum2' incorporates:
     *  Product: '<S172>/Multiply1'
     */
    rtb_Switch_gr_idx_1_p = rtb_Saturation4_n[3] * rtb_Saturation1_l_idx_1_p +
      rtb_Saturation3_j;

    /* Saturate: '<S172>/Saturation4' */
    if (rtb_Switch_gr_idx_1_p > 1.0F) {
      rtb_Switch_gr_idx_1_p = 1.0F;
    } else {
      if (rtb_Switch_gr_idx_1_p < 0.0F) {
        rtb_Switch_gr_idx_1_p = 0.0F;
      }
    }

    /* Sum: '<S172>/Sum3' incorporates:
     *  Product: '<S172>/Multiply2'
     */
    rtb_Switch_gr_idx_1_p += Controller_ConstB.VTOL1.r_column[3] *
      rtb_Saturation1_l_idx_2_p;

    /* MATLAB Function: '<S172>/R_Remix' */
    if (rtb_Switch_gr_idx_1_p < rtb_Subtract_h) {
      rtb_Subtract_h = rtb_Switch_gr_idx_1_p;
      i_p = 4;
    }

    if (rtb_Switch_gr_idx_1_p > b_max_p) {
      b_max_p = rtb_Switch_gr_idx_1_p;
      max_index_p = 4;
    }

    /* Product: '<S172>/Multiply1' */
    rtb_Saturation4_n[3] = rtb_Switch_gr_idx_1_p;

    /* MATLAB Function: '<S172>/R_Remix' */
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

    /* MultiPortSwitch: '<S175>/Multiport Switch' incorporates:
     *  Constant: '<S176>/Constant1'
     *  Constant: '<S176>/Constant12'
     *  Constant: '<S176>/Constant2'
     *  Constant: '<S176>/Constant7'
     *  DataTypeConversion: '<S185>/Data Type Conversion'
     *  DataTypeConversion: '<S186>/Data Type Conversion'
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
        /* Saturate: '<S186>/Saturation' incorporates:
         *  Constant: '<S186>/Standby'
         *  Reshape: '<S186>/Reshape'
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

      /* Saturate: '<S186>/Saturation' incorporates:
       *  Bias: '<S186>/Bias'
       *  Constant: '<S186>/Constant'
       *  DataTypeConversion: '<S186>/Data Type Conversion'
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

      /* Saturate: '<S186>/Saturation' incorporates:
       *  Bias: '<S186>/Bias1'
       *  Constant: '<S186>/Constant'
       *  DataTypeConversion: '<S186>/Data Type Conversion'
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

      /* Saturate: '<S186>/Saturation' incorporates:
       *  Bias: '<S186>/Bias2'
       *  Constant: '<S186>/Constant'
       *  DataTypeConversion: '<S186>/Data Type Conversion'
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

      /* Saturate: '<S186>/Saturation' incorporates:
       *  Bias: '<S186>/Bias3'
       *  Constant: '<S186>/Constant'
       *  DataTypeConversion: '<S186>/Data Type Conversion'
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

      /* SignalConversion: '<S176>/ConcatBufferAtVector Concatenate2In3' incorporates:
       *  Constant: '<S176>/Constant11'
       *  Constant: '<S176>/Constant12'
       */
      rtb_MatrixConcatenate[10] = 0.0F;

      /* SignalConversion: '<S176>/ConcatBufferAtVector Concatenate2In2' incorporates:
       *  Constant: '<S176>/Constant10'
       */
      rtb_MatrixConcatenate[9] = 0.0F;

      /* SignalConversion: '<S176>/ConcatBufferAtVector Concatenate2In1' incorporates:
       *  Constant: '<S176>/Constant9'
       */
      rtb_MatrixConcatenate[8] = 0.0F;

      /* SignalConversion: '<S176>/ConcatBufferAtVector Concatenate1In4' incorporates:
       *  Constant: '<S176>/Constant8'
       */
      rtb_MatrixConcatenate[7] = 0.0F;
      rtb_MatrixConcatenate[6] = CONTROL_PARAM.FW_PITCH_EFFC *
        CONTROL_PARAM.FW_ELEVATOR_DIR;

      /* SignalConversion: '<S176>/ConcatBufferAtVector Concatenate1In2' incorporates:
       *  Constant: '<S176>/Constant6'
       *  Constant: '<S176>/Constant7'
       */
      rtb_MatrixConcatenate[5] = 0.0F;

      /* SignalConversion: '<S176>/ConcatBufferAtVector Concatenate1In1' incorporates:
       *  Constant: '<S176>/Constant5'
       */
      rtb_MatrixConcatenate[4] = 0.0F;

      /* SignalConversion: '<S176>/ConcatBufferAtVector ConcatenateIn4' incorporates:
       *  Constant: '<S176>/Constant4'
       */
      rtb_MatrixConcatenate[3] = 0.0F;

      /* SignalConversion: '<S176>/ConcatBufferAtVector ConcatenateIn3' incorporates:
       *  Constant: '<S176>/Constant3'
       */
      rtb_MatrixConcatenate[2] = 0.0F;
      rtb_MatrixConcatenate[1] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON2_DIR;
      rtb_MatrixConcatenate[0] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON1_DIR;

      /* Saturate: '<S171>/Saturation5' incorporates:
       *  Constant: '<S176>/Constant1'
       *  Constant: '<S176>/Constant2'
       */
      if (Controller_B.fw_torque_cmd[0] > 1.0F) {
        /* Product: '<S171>/Multiply1' */
        rtb_Gain1_l = 1.0F;
      } else if (Controller_B.fw_torque_cmd[0] < -1.0F) {
        /* Product: '<S171>/Multiply1' */
        rtb_Gain1_l = -1.0F;
      } else {
        /* Product: '<S171>/Multiply1' */
        rtb_Gain1_l = Controller_B.fw_torque_cmd[0];
      }

      if (Controller_B.fw_torque_cmd[1] > 1.0F) {
        /* Product: '<S171>/Multiply1' */
        rtb_Saturation1_l_idx_2_p = 1.0F;
      } else if (Controller_B.fw_torque_cmd[1] < -1.0F) {
        /* Product: '<S171>/Multiply1' */
        rtb_Saturation1_l_idx_2_p = -1.0F;
      } else {
        /* Product: '<S171>/Multiply1' */
        rtb_Saturation1_l_idx_2_p = Controller_B.fw_torque_cmd[1];
      }

      if (Controller_B.fw_torque_cmd[2] > 1.0F) {
        /* Product: '<S171>/Multiply1' */
        rtb_Saturation3_j = 1.0F;
      } else if (Controller_B.fw_torque_cmd[2] < -1.0F) {
        /* Product: '<S171>/Multiply1' */
        rtb_Saturation3_j = -1.0F;
      } else {
        /* Product: '<S171>/Multiply1' */
        rtb_Saturation3_j = Controller_B.fw_torque_cmd[2];
      }

      /* End of Saturate: '<S171>/Saturation5' */
      for (i_p = 0; i_p < 4; i_p++) {
        /* Bias: '<S171>/Bias' incorporates:
         *  Gain: '<S171>/Gain1'
         *  Product: '<S171>/Multiply1'
         */
        rtb_Saturation5_o[i_p] = 500.0F * (rtb_MatrixConcatenate[i_p + 8] *
          rtb_Saturation3_j + (rtb_MatrixConcatenate[i_p + 4] *
          rtb_Saturation1_l_idx_2_p + rtb_MatrixConcatenate[i_p] * rtb_Gain1_l))
          + 1500.0F;

        /* Sum: '<S172>/Sum4' */
        rtb_Saturation1_l_idx_0_p = rtb_Saturation4_n[i_p] + rtb_Sum_e[i_p];

        /* Saturate: '<S172>/Saturation5' */
        if (rtb_Saturation1_l_idx_0_p > 1.0F) {
          rtb_Saturation1_l_idx_0_p = 1.0F;
        } else {
          if (rtb_Saturation1_l_idx_0_p < 0.0F) {
            rtb_Saturation1_l_idx_0_p = 0.0F;
          }
        }

        /* End of Saturate: '<S172>/Saturation5' */

        /* DataTypeConversion: '<S172>/Data Type Conversion' incorporates:
         *  Constant: '<S172>/Constant2'
         *  Gain: '<S172>/Gain3'
         *  Sum: '<S172>/Sum5'
         */
        u0_p = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
          rtb_Saturation1_l_idx_0_p), 4.2949673E+9F) + 1000U);

        /* Saturate: '<S172>/Saturation' */
        if (u0_p > CONTROL_PARAM.MC_OUT_MAX) {
          rtb_VariantMergeForOutportactua[i_p] = CONTROL_PARAM.MC_OUT_MAX;
        } else if (u0_p < CONTROL_PARAM.MC_OUT_MIN) {
          rtb_VariantMergeForOutportactua[i_p] = CONTROL_PARAM.MC_OUT_MIN;
        } else {
          rtb_VariantMergeForOutportactua[i_p] = u0_p;
        }

        /* End of Saturate: '<S172>/Saturation' */
      }

      /* Saturate: '<S171>/Saturation' */
      if (Controller_B.fw_force_cmd[0] > 1.0F) {
        rtb_Gain1_l = 1.0F;
      } else if (Controller_B.fw_force_cmd[0] < 0.0F) {
        rtb_Gain1_l = 0.0F;
      } else {
        rtb_Gain1_l = Controller_B.fw_force_cmd[0];
      }

      /* End of Saturate: '<S171>/Saturation' */

      /* DataTypeConversion: '<S178>/Data Type Conversion' incorporates:
       *  Constant: '<S178>/Constant1'
       *  Gain: '<S178>/Gain1'
       *  Sum: '<S178>/Sum1'
       */
      u0_p = (uint16_T)((uint32_T)fmodf(floorf(1000.0F * rtb_Gain1_l),
        4.2949673E+9F) + 1000U);

      /* Saturate: '<S171>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[4] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[4] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[4] = u0_p;
      }

      /* DataTypeConversion: '<S171>/Data Type Conversion' incorporates:
       *  Bias: '<S171>/Bias1'
       */
      rtb_Gain1_l = fmodf(floorf(rtb_Saturation5_o[0] +
        CONTROL_PARAM.SERVO1_BIAS), 65536.0F);
      u0_p = (uint16_T)(rtb_Gain1_l < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                        (uint16_T)-rtb_Gain1_l : (int32_T)(uint16_T)rtb_Gain1_l);

      /* Saturate: '<S171>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[5] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[5] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[5] = u0_p;
      }

      /* DataTypeConversion: '<S171>/Data Type Conversion1' incorporates:
       *  Bias: '<S171>/Bias2'
       */
      rtb_Gain1_l = fmodf(floorf(rtb_Saturation5_o[1] +
        CONTROL_PARAM.SERVO2_BIAS), 65536.0F);
      u0_p = (uint16_T)(rtb_Gain1_l < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                        (uint16_T)-rtb_Gain1_l : (int32_T)(uint16_T)rtb_Gain1_l);

      /* Saturate: '<S171>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[6] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[6] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[6] = u0_p;
      }

      /* DataTypeConversion: '<S171>/Data Type Conversion2' incorporates:
       *  Bias: '<S171>/Bias3'
       */
      rtb_Gain1_l = fmodf(floorf(rtb_Saturation5_o[2] +
        CONTROL_PARAM.SERVO3_BIAS), 65536.0F);
      u0_p = (uint16_T)(rtb_Gain1_l < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                        (uint16_T)-rtb_Gain1_l : (int32_T)(uint16_T)rtb_Gain1_l);

      /* Saturate: '<S171>/Saturation1' */
      if (u0_p > CONTROL_PARAM.FW_OUT_MAX) {
        rtb_VariantMergeForOutportactua[7] = CONTROL_PARAM.FW_OUT_MAX;
      } else if (u0_p < CONTROL_PARAM.FW_OUT_MIN) {
        rtb_VariantMergeForOutportactua[7] = CONTROL_PARAM.FW_OUT_MIN;
      } else {
        rtb_VariantMergeForOutportactua[7] = u0_p;
      }

      /* DataTypeConversion: '<S171>/Data Type Conversion3' incorporates:
       *  Bias: '<S171>/Bias4'
       */
      rtb_Gain1_l = fmodf(floorf(rtb_Saturation5_o[3] +
        CONTROL_PARAM.SERVO4_BIAS), 65536.0F);
      u0_p = (uint16_T)(rtb_Gain1_l < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                        (uint16_T)-rtb_Gain1_l : (int32_T)(uint16_T)rtb_Gain1_l);

      /* Saturate: '<S171>/Saturation1' */
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

    /* End of MultiPortSwitch: '<S175>/Multiport Switch' */
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

    /* Saturate: '<S194>/Saturation' incorporates:
     *  Bias: '<S194>/Bias'
     *  Bias: '<S194>/Bias1'
     *  Bias: '<S194>/Bias2'
     *  Bias: '<S194>/Bias3'
     *  Constant: '<S194>/Constant'
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

    /* End of Saturate: '<S194>/Saturation' */

    /* MultiPortSwitch: '<S189>/Multiport Switch' incorporates:
     *  Constant: '<S190>/Constant1'
     *  Constant: '<S190>/Constant11'
     *  Constant: '<S190>/Constant12'
     *  Constant: '<S190>/Constant2'
     *  Constant: '<S190>/Constant7'
     *  Constant: '<S190>/Constant8'
     *  DataTypeConversion: '<S194>/Data Type Conversion'
     *  DataTypeConversion: '<S195>/Data Type Conversion'
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
        /* Saturate: '<S195>/Saturation' incorporates:
         *  Constant: '<S195>/Disarm'
         *  Reshape: '<S195>/Reshape'
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

      /* Saturate: '<S195>/Saturation' incorporates:
       *  Bias: '<S195>/Bias'
       *  Constant: '<S195>/Constant'
       *  DataTypeConversion: '<S195>/Data Type Conversion'
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

      /* Saturate: '<S195>/Saturation' incorporates:
       *  Bias: '<S195>/Bias1'
       *  Constant: '<S195>/Constant'
       *  DataTypeConversion: '<S195>/Data Type Conversion'
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

      /* Saturate: '<S195>/Saturation' incorporates:
       *  Bias: '<S195>/Bias2'
       *  Constant: '<S195>/Constant'
       *  DataTypeConversion: '<S195>/Data Type Conversion'
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

      /* Saturate: '<S195>/Saturation' incorporates:
       *  Bias: '<S195>/Bias3'
       *  Constant: '<S195>/Constant'
       *  DataTypeConversion: '<S195>/Data Type Conversion'
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

      /* SignalConversion: '<S190>/ConcatBufferAtVector Concatenate2In2' incorporates:
       *  Constant: '<S190>/Constant10'
       *  Constant: '<S190>/Constant11'
       *  Constant: '<S190>/Constant12'
       */
      rtb_MatrixConcatenate_g[9] = 0.0F;

      /* SignalConversion: '<S190>/ConcatBufferAtVector Concatenate2In1' incorporates:
       *  Constant: '<S190>/Constant9'
       */
      rtb_MatrixConcatenate_g[8] = 0.0F;
      rtb_MatrixConcatenate_g[7] = -CONTROL_PARAM.FW_PITCH_EFFC *
        CONTROL_PARAM.FW_TAIL2_DIR;
      rtb_MatrixConcatenate_g[6] = CONTROL_PARAM.FW_PITCH_EFFC *
        CONTROL_PARAM.FW_TAIL1_DIR;

      /* SignalConversion: '<S190>/ConcatBufferAtVector Concatenate1In2' incorporates:
       *  Constant: '<S190>/Constant6'
       *  Constant: '<S190>/Constant7'
       *  Constant: '<S190>/Constant8'
       */
      rtb_MatrixConcatenate_g[5] = 0.0F;

      /* SignalConversion: '<S190>/ConcatBufferAtVector Concatenate1In1' incorporates:
       *  Constant: '<S190>/Constant5'
       */
      rtb_MatrixConcatenate_g[4] = 0.0F;

      /* SignalConversion: '<S190>/ConcatBufferAtVector ConcatenateIn4' incorporates:
       *  Constant: '<S190>/Constant4'
       */
      rtb_MatrixConcatenate_g[3] = 0.0F;

      /* SignalConversion: '<S190>/ConcatBufferAtVector ConcatenateIn3' incorporates:
       *  Constant: '<S190>/Constant3'
       */
      rtb_MatrixConcatenate_g[2] = 0.0F;
      rtb_MatrixConcatenate_g[1] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON2_DIR;
      rtb_MatrixConcatenate_g[0] = CONTROL_PARAM.FW_ROLL_EFFC *
        CONTROL_PARAM.FW_AILERON1_DIR;

      /* Saturate: '<S187>/Saturation5' incorporates:
       *  Constant: '<S190>/Constant1'
       *  Constant: '<S190>/Constant2'
       */
      if (Controller_B.fw_torque_cmd[0] > 1.0F) {
        /* Product: '<S187>/Multiply1' */
        tmp_m = 1.0F;
      } else if (Controller_B.fw_torque_cmd[0] < -1.0F) {
        /* Product: '<S187>/Multiply1' */
        tmp_m = -1.0F;
      } else {
        /* Product: '<S187>/Multiply1' */
        tmp_m = Controller_B.fw_torque_cmd[0];
      }

      if (Controller_B.fw_torque_cmd[1] > 1.0F) {
        /* Product: '<S187>/Multiply1' */
        tmp_ev = 1.0F;
      } else if (Controller_B.fw_torque_cmd[1] < -1.0F) {
        /* Product: '<S187>/Multiply1' */
        tmp_ev = -1.0F;
      } else {
        /* Product: '<S187>/Multiply1' */
        tmp_ev = Controller_B.fw_torque_cmd[1];
      }

      if (Controller_B.fw_torque_cmd[2] > 1.0F) {
        /* Product: '<S187>/Multiply1' */
        tmp_k = 1.0F;
      } else if (Controller_B.fw_torque_cmd[2] < -1.0F) {
        /* Product: '<S187>/Multiply1' */
        tmp_k = -1.0F;
      } else {
        /* Product: '<S187>/Multiply1' */
        tmp_k = Controller_B.fw_torque_cmd[2];
      }

      /* End of Saturate: '<S187>/Saturation5' */
      for (i_o = 0; i_o < 4; i_o++) {
        /* Bias: '<S187>/Bias' incorporates:
         *  Gain: '<S187>/Gain1'
         *  Product: '<S187>/Multiply1'
         */
        rtb_Multiply_ka[i_o] = 500.0F * (rtb_MatrixConcatenate_g[i_o + 8] *
          tmp_k + (rtb_MatrixConcatenate_g[i_o + 4] * tmp_ev +
                   rtb_MatrixConcatenate_g[i_o] * tmp_m)) + 1500.0F;
      }

      /* Saturate: '<S188>/Saturation2' */
      if (Controller_B.mc_force_cmd[2] > 1.0F) {
        tmp_gf = 1.0F;
      } else if (Controller_B.mc_force_cmd[2] < 0.0F) {
        tmp_gf = 0.0F;
      } else {
        tmp_gf = Controller_B.mc_force_cmd[2];
      }

      /* End of Saturate: '<S188>/Saturation2' */

      /* DataTypeConversion: '<S193>/Data Type Conversion' incorporates:
       *  Constant: '<S193>/Constant1'
       *  Gain: '<S193>/Gain1'
       *  Sum: '<S193>/Sum1'
       */
      rtb_DataTypeConversion_o = (uint16_T)((uint32_T)fmodf(floorf(1000.0F *
        tmp_gf), 4.2949673E+9F) + 1000U);

      /* Saturate: '<S188>/Saturation1' */
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

      /* End of Saturate: '<S188>/Saturation1' */

      /* Saturate: '<S187>/Saturation4' */
      if (Controller_B.fw_force_cmd[0] > 1.0F) {
        tmp_gf = 1.0F;
      } else if (Controller_B.fw_force_cmd[0] < 0.0F) {
        tmp_gf = 0.0F;
      } else {
        tmp_gf = Controller_B.fw_force_cmd[0];
      }

      /* End of Saturate: '<S187>/Saturation4' */

      /* Saturate: '<S187>/Saturation1' incorporates:
       *  Constant: '<S192>/Constant1'
       *  DataTypeConversion: '<S192>/Data Type Conversion'
       *  Gain: '<S192>/Gain1'
       *  Sum: '<S192>/Sum1'
       */
      tmp_o[0] = (uint16_T)((uint32_T)fmodf(floorf(1000.0F * tmp_gf),
        4.2949673E+9F) + 1000U);

      /* DataTypeConversion: '<S187>/Data Type Conversion' incorporates:
       *  Bias: '<S187>/Bias1'
       */
      tmp_gf = fmodf(floorf(rtb_Multiply_ka[0] + CONTROL_PARAM.SERVO1_BIAS),
                     65536.0F);

      /* Saturate: '<S187>/Saturation1' incorporates:
       *  DataTypeConversion: '<S187>/Data Type Conversion'
       */
      tmp_o[1] = (uint16_T)(tmp_gf < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_gf : (int32_T)(uint16_T)tmp_gf);

      /* DataTypeConversion: '<S187>/Data Type Conversion1' incorporates:
       *  Bias: '<S187>/Bias2'
       */
      tmp_gf = fmodf(floorf(rtb_Multiply_ka[1] + CONTROL_PARAM.SERVO2_BIAS),
                     65536.0F);

      /* Saturate: '<S187>/Saturation1' incorporates:
       *  DataTypeConversion: '<S187>/Data Type Conversion1'
       */
      tmp_o[2] = (uint16_T)(tmp_gf < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_gf : (int32_T)(uint16_T)tmp_gf);

      /* DataTypeConversion: '<S187>/Data Type Conversion2' incorporates:
       *  Bias: '<S187>/Bias3'
       */
      tmp_gf = fmodf(floorf(rtb_Multiply_ka[2] + CONTROL_PARAM.SERVO3_BIAS),
                     65536.0F);

      /* Saturate: '<S187>/Saturation1' incorporates:
       *  DataTypeConversion: '<S187>/Data Type Conversion2'
       */
      tmp_o[3] = (uint16_T)(tmp_gf < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_gf : (int32_T)(uint16_T)tmp_gf);

      /* DataTypeConversion: '<S187>/Data Type Conversion3' incorporates:
       *  Bias: '<S187>/Bias4'
       */
      tmp_gf = fmodf(floorf(rtb_Multiply_ka[3] + CONTROL_PARAM.SERVO4_BIAS),
                     65536.0F);

      /* Saturate: '<S187>/Saturation1' incorporates:
       *  DataTypeConversion: '<S187>/Data Type Conversion3'
       */
      tmp_o[4] = (uint16_T)(tmp_gf < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-tmp_gf : (int32_T)(uint16_T)tmp_gf);

      /* Product: '<S188>/Multiply' */
      for (i_o = 0; i_o < 4; i_o++) {
        /* Saturate: '<S188>/Saturation' incorporates:
         *  Constant: '<S188>/Effective_Matrix'
         *  Gain: '<S188>/Gain'
         *  Sum: '<S188>/Add'
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

        /* End of Saturate: '<S188>/Saturation' */
      }

      /* End of Product: '<S188>/Multiply' */
      for (i_o = 0; i_o < 5; i_o++) {
        /* Saturate: '<S187>/Saturation1' */
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

    /* End of MultiPortSwitch: '<S189>/Multiport Switch' */
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

  /* Start for SwitchCase: '<S7>/Switch Case1' */
  Controller_DW.SwitchCase1_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S2>/FW_Controller' */
  /* Start for Constant: '<S48>/Constant' */
  Controller_B.Constant_m = CONTROL_PARAM.MC_VEL_Z_I_MIN;

  /* End of Start for SubSystem: '<S2>/FW_Controller' */

  /* Start for IfAction SubSystem: '<S2>/MC_Controller' */
  /* Start for Constant: '<S164>/Constant' */
  Controller_B.Constant = CONTROL_PARAM.MC_VEL_Z_I_MIN;

  /* End of Start for SubSystem: '<S2>/MC_Controller' */

  /* SystemInitialize for IfAction SubSystem: '<S2>/FW_Controller' */
  /* InitializeConditions for DiscreteIntegrator: '<S52>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_b = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S27>/Discrete-Time Integrator' */
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

  /* End of InitializeConditions for DiscreteIntegrator: '<S27>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S101>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_n = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S55>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_e = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S96>/ ' */
  Controller_DW._DSTATE = Controller_ConstB.Zero1;
  if (Controller_DW._DSTATE >= CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
    Controller_DW._DSTATE = CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
  } else {
    if (Controller_DW._DSTATE <= -CONTROL_PARAM.FW_TECS_PITCH_I_LIM) {
      Controller_DW._DSTATE = -CONTROL_PARAM.FW_TECS_PITCH_I_LIM;
    }
  }

  Controller_DW._PrevResetState = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S96>/ ' */

  /* InitializeConditions for DiscreteIntegrator: '<S97>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_f = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_b = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S24>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_L_bo = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S29>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_LO_h = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_l = 0;

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

  /* InitializeConditions for DiscreteIntegrator: '<S99>/ ' */
  Controller_DW._DSTATE_d = Controller_ConstB.Zero;
  if (Controller_DW._DSTATE_d >= 1.0F) {
    Controller_DW._DSTATE_d = 1.0F;
  } else {
    if (Controller_DW._DSTATE_d <= 0.0F) {
      Controller_DW._DSTATE_d = 0.0F;
    }
  }

  Controller_DW._PrevResetState_e = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S99>/ ' */

  /* InitializeConditions for DiscreteIntegrator: '<S100>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_IC_L_h0 = 1U;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_d = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S51>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_IC_LO_o = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S75>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_PrevR_ef = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S45>/Integrator' */
  Controller_DW.Integrator_DSTATE_f = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S75>/Discrete-Time Integrator' */
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
  /* InitializeConditions for DiscreteIntegrator: '<S75>/Discrete-Time Integrator' */
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
  /* InitializeConditions for DiscreteIntegrator: '<S75>/Discrete-Time Integrator' */
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

  /* InitializeConditions for DiscreteIntegrator: '<S118>/Discrete-Time Integrator5' */
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
