/*
 * File: Controller_data.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.799
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Sep 23 16:31:22 2025
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
  { 0.0F, 0.0F, 0.0F },                /* '<S134>/Constant' */

  { 0.0F, 0.0F, 1.0F },                /* '<S156>/Vector Concatenate3' */
  0.0F,                                /* '<S159>/Constant' */
  19.1986F,                            /* '<S142>/Gain' */
  6.0F,                                /* '<S117>/Subtract' */
  0.166666672F,                        /* '<S117>/Divide' */
  6.0F,                                /* '<S120>/Subtract' */
  0.166666672F,                        /* '<S120>/Divide' */
  0.00250000018F,                      /* '<S157>/Square' */
  0.14709F,                            /* '<S157>/Multiply' */
  -58.836F,                            /* '<S157>/Gain4' */
  0.00250000018F,                      /* '<S174>/Square' */
  0.196120009F,                        /* '<S174>/Multiply' */
  -78.448F,                            /* '<S174>/Gain4' */

  { 0.0F, 0.0F, 0.0F },                /* '<S59>/Constant' */

  { 0.0F, 0.0F, 1.0F },                /* '<S90>/Vector Concatenate3' */
  0.0F,                                /* '<S95>/Zero' */
  0.0F,                                /* '<S92>/Zero1' */
  0.0016F,                             /* '<S78>/Square' */
  0.0201061927F,                       /* '<S78>/Multiply' */
  -12.566371F,                         /* '<S78>/Gain4' */
  0.00250000018F,                      /* '<S71>/Square' */
  0.14709F,                            /* '<S71>/Multiply' */
  -58.836F,                            /* '<S71>/Gain4' */

#if AIRFRAME == 2

  /* Start of '<S180>/VTOL2' */
  {
    { -0.5F, 0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, 0.5F, -0.5F,
      -0.5F },                         /* '<S200>/Gain' */

    { 0.5F, 0.5F, -0.5F, -0.5F },      /* '<S200>/r_column' */

    { -0.5F, 0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, -0.5F }/* '<S200>/pq_column' */
  }
  ,

  /* End of '<S180>/VTOL2' */
#endif

#if AIRFRAME == 1

  /* Start of '<S180>/VTOL1' */
  {
    { -0.5F, 0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, 0.5F, -0.5F,
      -0.5F },                         /* '<S184>/Gain' */

    { 0.5F, 0.5F, -0.5F, -0.5F },      /* '<S184>/r_column' */

    { -0.5F, 0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, -0.5F }/* '<S184>/pq_column' */
  }
  /* End of '<S180>/VTOL1' */
#endif
};

/* Constant parameters (default storage) */
const ConstP_Controller_T Controller_ConstP = {

#if (AIRFRAME == 1) || (AIRFRAME == 2)

  /* Pooled Parameter (Expression: [1150 1150 1150 1150 1000]')
   * Referenced by:
   *   '<S198>/Standby'
   *   '<S210>/Disarm'
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
