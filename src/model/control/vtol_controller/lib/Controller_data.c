/*
 * File: Controller_data.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.724
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Sep 15 11:14:44 2025
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
  { 0.0F, 0.0F, 1.0F },                /* '<S137>/Vector Concatenate3' */
  0.0F,                                /* '<S140>/Constant' */
  19.1986F,                            /* '<S124>/Gain' */
  6.25E-6F,                            /* '<S118>/Square' */
  0.000589048606F,                     /* '<S118>/Multiply' */
  -94.2477798F,                        /* '<S118>/Gain4' */

  { 0.0F, 0.0F, 0.0F },                /* '<S111>/Constant' */
  0.0100000007F,                       /* '<S138>/Square' */
  0.784480035F,                        /* '<S138>/Multiply' */
  -78.448F,                            /* '<S138>/Gain4' */
  0.00250000018F,                      /* '<S154>/Square' */
  0.196120009F,                        /* '<S154>/Multiply' */
  -78.448F,                            /* '<S154>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S77>/Vector Concatenate3' */
  0.0F,                                /* '<S79>/Zero1' */

  { 0.0F, 0.0F, 0.0F },                /* '<S57>/Constant' */
  0.0F,                                /* '<S82>/Zero' */

#if AIRFRAME == 2

  /* Start of '<S164>/VTOL2' */
  {
    { -0.5F, 0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, 0.5F, -0.5F,
      -0.5F },                         /* '<S184>/Gain' */

    { 0.5F, 0.5F, -0.5F, -0.5F },      /* '<S184>/r_column' */

    { -0.5F, 0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, -0.5F }/* '<S184>/pq_column' */
  }
  ,

  /* End of '<S164>/VTOL2' */
#endif

#if AIRFRAME == 1

  /* Start of '<S164>/VTOL1' */
  {
    { -0.5F, 0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, 0.5F, -0.5F,
      -0.5F },                         /* '<S168>/Gain' */

    { 0.5F, 0.5F, -0.5F, -0.5F },      /* '<S168>/r_column' */

    { -0.5F, 0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, -0.5F }/* '<S168>/pq_column' */
  }
  /* End of '<S164>/VTOL1' */
#endif
};

/* Constant parameters (default storage) */
const ConstP_Controller_T Controller_ConstP = {

#if (AIRFRAME == 1) || (AIRFRAME == 2)

  /* Pooled Parameter (Expression: [1150 1150 1150 1150 1000]')
   * Referenced by:
   *   '<S182>/Standby'
   *   '<S194>/Disarm'
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
