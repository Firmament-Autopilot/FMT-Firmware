/*
 * File: Controller_data.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.824
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Sep 30 15:14:14 2025
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
  { 0.0F, 0.0F, 0.0F },                /* '<S97>/Constant' */

  { 0.0F, 0.0F, 1.0F },                /* '<S119>/Vector Concatenate3' */
  0.0F,                                /* '<S122>/Constant' */
  19.1986F,                            /* '<S105>/Gain' */
  6.0F,                                /* '<S80>/Subtract' */
  0.166666672F,                        /* '<S80>/Divide' */
  6.0F,                                /* '<S83>/Subtract' */
  0.166666672F,                        /* '<S83>/Divide' */
  0.00250000018F,                      /* '<S120>/Square' */
  0.14709F,                            /* '<S120>/Multiply' */
  -58.836F,                            /* '<S120>/Gain4' */
  0.00250000018F,                      /* '<S137>/Square' */
  0.196120009F,                        /* '<S137>/Multiply' */
  -78.448F,                            /* '<S137>/Gain4' */

  { 0.0F, 0.0F, 0.0F },                /* '<S23>/Constant' */

  { 0.0F, 0.0F, 1.0F },                /* '<S53>/Vector Concatenate3' */
  0.0F,                                /* '<S56>/Zero1' */
  0.0016F,                             /* '<S41>/Square' */
  0.0201061927F,                       /* '<S41>/Multiply' */
  -12.566371F,                         /* '<S41>/Gain4' */
  0.00250000018F,                      /* '<S35>/Square' */
  0.14709F,                            /* '<S35>/Multiply' */
  -58.836F,                            /* '<S35>/Gain4' */

#if AIRFRAME == 2

  /* Start of '<S143>/VTOL2' */
  {
    { -0.5F, 0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, 0.5F, -0.5F,
      -0.5F },                         /* '<S163>/Gain' */

    { 0.5F, 0.5F, -0.5F, -0.5F },      /* '<S163>/r_column' */

    { -0.5F, 0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, -0.5F }/* '<S163>/pq_column' */
  }
  ,

  /* End of '<S143>/VTOL2' */
#endif

#if AIRFRAME == 1

  /* Start of '<S143>/VTOL1' */
  {
    { -0.5F, 0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, 0.5F, -0.5F,
      -0.5F },                         /* '<S147>/Gain' */

    { 0.5F, 0.5F, -0.5F, -0.5F },      /* '<S147>/r_column' */

    { -0.5F, 0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, -0.5F }/* '<S147>/pq_column' */
  }
  /* End of '<S143>/VTOL1' */
#endif
};

/* Constant parameters (default storage) */
const ConstP_Controller_T Controller_ConstP = {

#if (AIRFRAME == 1) || (AIRFRAME == 2)

  /* Pooled Parameter (Expression: [1150 1150 1150 1150 1000]')
   * Referenced by:
   *   '<S161>/Standby'
   *   '<S173>/Disarm'
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
