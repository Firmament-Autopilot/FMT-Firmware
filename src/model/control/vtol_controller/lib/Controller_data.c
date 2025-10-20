/*
 * File: Controller_data.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.844
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Oct 17 15:41:37 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Controller.h"
#include "Controller_private.h"

/* Invariant block signals (default storage) */
const ConstB_Controller_T Controller_ConstB = {
  { 0.0F, 0.0F, 0.0F },                /* '<S99>/Constant' */

  { 0.0F, 0.0F, 1.0F },                /* '<S121>/Vector Concatenate3' */
  0.0F,                                /* '<S124>/Constant' */
  19.1986F,                            /* '<S107>/Gain' */
  6.0F,                                /* '<S82>/Subtract' */
  0.166666672F,                        /* '<S82>/Divide' */
  6.0F,                                /* '<S85>/Subtract' */
  0.166666672F,                        /* '<S85>/Divide' */
  0.00250000018F,                      /* '<S122>/Square' */
  0.14709F,                            /* '<S122>/Multiply' */
  -58.836F,                            /* '<S122>/Gain4' */
  0.00250000018F,                      /* '<S139>/Square' */
  0.196120009F,                        /* '<S139>/Multiply' */
  -78.448F,                            /* '<S139>/Gain4' */

  { 0.0F, 0.0F, 0.0F },                /* '<S23>/Constant' */

  { 0.0F, 0.0F, 1.0F },                /* '<S55>/Vector Concatenate3' */
  0.0F,                                /* '<S58>/Zero1' */
  0.0016F,                             /* '<S43>/Square' */
  0.0201061927F,                       /* '<S43>/Multiply' */
  -12.566371F,                         /* '<S43>/Gain4' */
  0.00250000018F,                      /* '<S37>/Square' */
  0.14709F,                            /* '<S37>/Multiply' */
  -58.836F,                            /* '<S37>/Gain4' */

#if AIRFRAME == 2

  /* Start of '<S145>/VTOL2' */
  {
    { -0.5F, 0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, 0.5F, -0.5F,
      -0.5F },                         /* '<S165>/Gain' */

    { 0.5F, 0.5F, -0.5F, -0.5F },      /* '<S165>/r_column' */

    { -0.5F, 0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, -0.5F }/* '<S165>/pq_column' */
  }
  ,

  /* End of '<S145>/VTOL2' */
#endif

#if AIRFRAME == 1

  /* Start of '<S145>/VTOL1' */
  {
    { -0.5F, 0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, 0.5F, -0.5F,
      -0.5F },                         /* '<S149>/Gain' */

    { 0.5F, 0.5F, -0.5F, -0.5F },      /* '<S149>/r_column' */

    { -0.5F, 0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, -0.5F }/* '<S149>/pq_column' */
  }
  /* End of '<S145>/VTOL1' */
#endif
};

/* Constant parameters (default storage) */
const ConstP_Controller_T Controller_ConstP = {

#if (AIRFRAME == 1) || (AIRFRAME == 2)

  /* Pooled Parameter (Expression: [1150 1150 1150 1150 1000]')
   * Referenced by:
   *   '<S163>/Standby'
   *   '<S176>/Disarm'
   */
  { 1150.0F, 1150.0F, 1150.0F, 1150.0F, 1000.0F },

#endif

#ifndef CONSTP_CONTROLLER_T_VARIANT_EXISTS

  0
#endif
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
