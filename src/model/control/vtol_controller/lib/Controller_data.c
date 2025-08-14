/*
 * File: Controller_data.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.430
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Aug 13 14:18:47 2025
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

  { 0.0F, 0.0F, 0.0F },                /* '<S121>/Constant' */

  { 0.0F, 0.0F, 1.0F },                /* '<S145>/Vector Concatenate3' */
  0.0F,                                /* '<S148>/Constant' */
  19.1986F,                            /* '<S133>/Gain' */
  0.0100000007F,                       /* '<S146>/Square' */
  0.784480035F,                        /* '<S146>/Multiply' */
  -78.448F,                            /* '<S146>/Gain4' */
  0.0F,                                /* '<S155>/Constant' */
  0.00250000018F,                      /* '<S162>/Square' */
  0.196120009F,                        /* '<S162>/Multiply' */
  -78.448F,                            /* '<S162>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S96>/Vector Concatenate3' */

  { 0.0F, 0.0F, 0.0F },                /* '<S26>/Constant' */
  289.0F,                              /* '<S10>/Square1' */
  0.0F,                                /* '<S98>/Zero1' */
  19.1986F,                            /* '<S34>/Gain' */
  0.0F,                                /* '<S101>/Zero' */

  { 0.0F, 0.0F, 0.0F },                /* '<S77>/Constant' */
  0.00250000018F,                      /* '<S49>/Square' */
  0.196120009F,                        /* '<S49>/Multiply' */
  -78.448F                             /* '<S49>/Gain4' */
};

/* Constant parameters (default storage) */
const ConstP_Controller_T Controller_ConstP = {

#if (AIRFRAME == 1) || (AIRFRAME == 2)

  /* Pooled Parameter (Expression: [-sqrt(2) sqrt(2) 1;sqrt(2) -sqrt(2) 1;sqrt(2) sqrt(2) -1;-sqrt(2) -sqrt(2) -1])
   * Referenced by:
   *   '<S172>/Effective_Matrix'
   *   '<S182>/Effective_Matrix'
   */
  { -1.41421354F, 1.41421354F, 1.41421354F, -1.41421354F, 1.41421354F,
    -1.41421354F, 1.41421354F, -1.41421354F, 1.0F, 1.0F, -1.0F, -1.0F },

#endif

#if (AIRFRAME == 1) || (AIRFRAME == 2)

  /* Pooled Parameter (Expression: [1150 1150 1150 1150 1000]')
   * Referenced by:
   *   '<S180>/Disarm'
   *   '<S190>/Disarm'
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
