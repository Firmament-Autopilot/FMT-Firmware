/*
 * File: Controller_data.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.785
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Sep 22 10:29:21 2025
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
  { 0.0F, 0.0F, 0.0F },                /* '<S124>/Constant' */

  { 0.0F, 0.0F, 1.0F },                /* '<S146>/Vector Concatenate3' */
  0.0F,                                /* '<S149>/Constant' */
  19.1986F,                            /* '<S132>/Gain' */
  6.0F,                                /* '<S107>/Subtract' */
  0.166666672F,                        /* '<S107>/Divide' */
  6.0F,                                /* '<S110>/Subtract' */
  0.166666672F,                        /* '<S110>/Divide' */
  0.00250000018F,                      /* '<S147>/Square' */
  0.14709F,                            /* '<S147>/Multiply' */
  -58.836F,                            /* '<S147>/Gain4' */
  0.00250000018F,                      /* '<S164>/Square' */
  0.196120009F,                        /* '<S164>/Multiply' */
  -78.448F,                            /* '<S164>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S81>/Vector Concatenate3' */
  0.0F,                                /* '<S83>/Zero1' */

  { 0.0F, 0.0F, 0.0F },                /* '<S59>/Constant' */
  0.0F,                                /* '<S86>/Zero' */
  0.00250000018F,                      /* '<S71>/Square' */
  0.14709F,                            /* '<S71>/Multiply' */
  -58.836F,                            /* '<S71>/Gain4' */

#if AIRFRAME == 2

  /* Start of '<S172>/VTOL2' */
  {
    { -0.5F, 0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, 0.5F, -0.5F,
      -0.5F },                         /* '<S192>/Gain' */

    { 0.5F, 0.5F, -0.5F, -0.5F },      /* '<S192>/r_column' */

    { -0.5F, 0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, -0.5F }/* '<S192>/pq_column' */
  }
  ,

  /* End of '<S172>/VTOL2' */
#endif

#if AIRFRAME == 1

  /* Start of '<S172>/VTOL1' */
  {
    { -0.5F, 0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, 0.5F, -0.5F,
      -0.5F },                         /* '<S176>/Gain' */

    { 0.5F, 0.5F, -0.5F, -0.5F },      /* '<S176>/r_column' */

    { -0.5F, 0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, -0.5F }/* '<S176>/pq_column' */
  }
  /* End of '<S172>/VTOL1' */
#endif
};

/* Constant parameters (default storage) */
const ConstP_Controller_T Controller_ConstP = {

#if (AIRFRAME == 1) || (AIRFRAME == 2)

  /* Pooled Parameter (Expression: [1150 1150 1150 1150 1000]')
   * Referenced by:
   *   '<S190>/Standby'
   *   '<S202>/Disarm'
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
