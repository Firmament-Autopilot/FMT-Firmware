/*
 * File: Controller_data.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.758
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Sep 17 08:38:28 2025
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
  { 0.0F, 0.0F, 0.0F },                /* '<S108>/Constant' */

  { 0.0F, 0.0F, 1.0F },                /* '<S129>/Vector Concatenate3' */
  0.0F,                                /* '<S132>/Constant' */
  19.1986F,                            /* '<S116>/Gain' */
  6.0F,                                /* '<S95>/Subtract' */
  0.166666672F,                        /* '<S95>/Divide' */
  6.0F,                                /* '<S98>/Subtract' */
  0.166666672F,                        /* '<S98>/Divide' */
  0.00250000018F,                      /* '<S130>/Square' */
  0.14709F,                            /* '<S130>/Multiply' */
  -58.836F,                            /* '<S130>/Gain4' */
  0.00250000018F,                      /* '<S146>/Square' */
  0.196120009F,                        /* '<S146>/Multiply' */
  -78.448F,                            /* '<S146>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S77>/Vector Concatenate3' */
  0.0F,                                /* '<S79>/Zero1' */

  { 0.0F, 0.0F, 0.0F },                /* '<S57>/Constant' */
  0.0F,                                /* '<S82>/Zero' */

#if AIRFRAME == 2

  /* Start of '<S165>/VTOL2' */
  {
    { -0.5F, 0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, 0.5F, -0.5F,
      -0.5F },                         /* '<S185>/Gain' */

    { 0.5F, 0.5F, -0.5F, -0.5F },      /* '<S185>/r_column' */

    { -0.5F, 0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, -0.5F }/* '<S185>/pq_column' */
  }
  ,

  /* End of '<S165>/VTOL2' */
#endif

#if AIRFRAME == 1

  /* Start of '<S165>/VTOL1' */
  {
    { -0.5F, 0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, 0.5F, -0.5F,
      -0.5F },                         /* '<S169>/Gain' */

    { 0.5F, 0.5F, -0.5F, -0.5F },      /* '<S169>/r_column' */

    { -0.5F, 0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, -0.5F }/* '<S169>/pq_column' */
  }
  /* End of '<S165>/VTOL1' */
#endif
};

/* Constant parameters (default storage) */
const ConstP_Controller_T Controller_ConstP = {

#if (AIRFRAME == 1) || (AIRFRAME == 2)

  /* Pooled Parameter (Expression: [1150 1150 1150 1150 1000]')
   * Referenced by:
   *   '<S183>/Standby'
   *   '<S195>/Disarm'
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
