/*
 * File: Controller_data.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.615
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Aug 28 10:26:49 2025
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
  { 0.0F, 0.0F, 0.0F },                /* '<S5>/Constant' */

  { 0.0F, 0.0F, 0.0F },                /* '<S5>/Constant1' */

  { 0.0F, 0.0F, 0.0F },                /* '<S117>/Constant' */

  { 0.0F, 0.0F, 1.0F },                /* '<S141>/Vector Concatenate3' */
  0.0F,                                /* '<S144>/Constant' */
  19.1986F,                            /* '<S129>/Gain' */
  0.0100000007F,                       /* '<S142>/Square' */
  0.784480035F,                        /* '<S142>/Multiply' */
  -78.448F,                            /* '<S142>/Gain4' */
  0.0F,                                /* '<S151>/Constant' */
  0.00250000018F,                      /* '<S158>/Square' */
  0.196120009F,                        /* '<S158>/Multiply' */
  -78.448F,                            /* '<S158>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S92>/Vector Concatenate3' */

  { 0.0F, 0.0F, 0.0F },                /* '<S25>/Constant' */
  289.0F,                              /* '<S10>/Square1' */
  0.0F,                                /* '<S94>/Zero1' */
  19.1986F,                            /* '<S33>/Gain' */
  0.0F,                                /* '<S97>/Zero' */

  { 0.0F, 0.0F, 0.0F },                /* '<S73>/Constant' */
  0.00250000018F,                      /* '<S44>/Square' */
  0.196120009F,                        /* '<S44>/Multiply' */
  -78.448F,                            /* '<S44>/Gain4' */

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
   *   '<S191>/Disarm'
   */
  { 1150.0F, 1150.0F, 1150.0F, 1150.0F, 1000.0F },

#endif

#if AIRFRAME == 2

  /* Computed Parameter: Effective_Matrix_Value_c
   * Referenced by: '<S184>/Effective_Matrix'
   */
  { -1.41421354F, 1.41421354F, 1.41421354F, -1.41421354F, 1.41421354F,
    -1.41421354F, 1.41421354F, -1.41421354F, 1.0F, 1.0F, -1.0F, -1.0F },

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
