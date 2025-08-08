/*
 * File: Controller_data.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.423
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Aug  7 17:30:19 2025
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

  { 0.0F, 0.0F, 0.0F },                /* '<S119>/Constant' */

  { 0.0F, 0.0F, 1.0F },                /* '<S143>/Vector Concatenate3' */
  0.0F,                                /* '<S146>/Constant' */
  19.1986F,                            /* '<S131>/Gain' */
  0.0100000007F,                       /* '<S144>/Square' */
  0.784480035F,                        /* '<S144>/Multiply' */
  -78.448F,                            /* '<S144>/Gain4' */
  0.0F,                                /* '<S158>/Constant' */
  0.00250000018F,                      /* '<S165>/Square' */
  0.196120009F,                        /* '<S165>/Multiply' */
  -78.448F,                            /* '<S165>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S92>/Vector Concatenate3' */

  { 0.0F, 0.0F, 0.0F },                /* '<S26>/Constant' */
  289.0F,                              /* '<S10>/Square1' */
  0.0F,                                /* '<S94>/Zero1' */
  19.1986F,                            /* '<S34>/Gain' */
  0.0F,                                /* '<S97>/Zero' */

  { 0.0F, 0.0F, 0.0F },                /* '<S73>/Constant' */
  0.00250000018F,                      /* '<S46>/Square' */
  0.196120009F,                        /* '<S46>/Multiply' */
  -78.448F                             /* '<S46>/Gain4' */
};

/* Constant parameters (default storage) */
const ConstP_Controller_T Controller_ConstP = {

#if (AIRFRAME == 1) || (AIRFRAME == 2)

  /* Pooled Parameter (Expression: [-sqrt(2) sqrt(2) 1;sqrt(2) -sqrt(2) 1;sqrt(2) sqrt(2) -1;-sqrt(2) -sqrt(2) -1])
   * Referenced by:
   *   '<S175>/Effective_Matrix'
   *   '<S184>/Effective_Matrix'
   */
  { -1.41421354F, 1.41421354F, 1.41421354F, -1.41421354F, 1.41421354F,
    -1.41421354F, 1.41421354F, -1.41421354F, 1.0F, 1.0F, -1.0F, -1.0F },

#endif

#if (AIRFRAME == 1) || (AIRFRAME == 2)

  /* Pooled Parameter (Expression: [1150 1150 1150 1150 1000]')
   * Referenced by:
   *   '<S182>/Disarm'
   *   '<S191>/Disarm'
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
