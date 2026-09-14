/*
 * File: Controller_data.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.864
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Sep 14 14:57:33 2026
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
  { 0.0F, 0.0F, 0.0F },                /* '<S100>/Constant' */
  19.1986F,                            /* '<S108>/Gain' */
  6.0F,                                /* '<S83>/Subtract' */
  0.166666672F,                        /* '<S83>/Divide' */
  6.0F,                                /* '<S86>/Subtract' */
  0.166666672F,                        /* '<S86>/Divide' */
  0.00250000018F,                      /* '<S141>/Square' */
  0.196120009F,                        /* '<S141>/Multiply' */
  -78.448F,                            /* '<S141>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S122>/Vector Concatenate3' */
  0.00250000018F,                      /* '<S123>/Square' */
  0.14709F,                            /* '<S123>/Multiply' */
  -58.836F,                            /* '<S123>/Gain4' */
  0.0F,                                /* '<S125>/Constant' */

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

  /* Start of '<S148>/VTOL2' */
  {
    { -0.5F, 0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, 0.5F, -0.5F,
      -0.5F },                         /* '<S162>/Gain' */

    { 0.5F, 0.5F, -0.5F, -0.5F },      /* '<S162>/r_column' */

    { -0.5F, 0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, -0.5F }/* '<S162>/pq_column' */
  }
  ,

  /* End of '<S148>/VTOL2' */
#endif

#if AIRFRAME == 1

  /* Start of '<S148>/VTOL1' */
  {
    { -0.5F, 0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, 0.5F, -0.5F,
      -0.5F },                         /* '<S152>/Gain' */

    { 0.5F, 0.5F, -0.5F, -0.5F },      /* '<S152>/r_column' */

    { -0.5F, 0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, -0.5F }/* '<S152>/pq_column' */
  }
  /* End of '<S148>/VTOL1' */
#endif
};

/* Constant parameters (default storage) */
const ConstP_Controller_T Controller_ConstP = {

#if (AIRFRAME == 1) || (AIRFRAME == 2)

  /* Pooled Parameter (Expression: [1150 1150 1150 1150 1000]')
   * Referenced by:
   *   '<S160>/Standby'
   *   '<S171>/Disarm'
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
