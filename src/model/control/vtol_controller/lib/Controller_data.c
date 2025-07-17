/*
 * File: Controller_data.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.344
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Jul 17 11:32:42 2025
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
  { 0.0F, 0.0F, 0.0F },                /* '<S6>/Constant' */

  { 0.0F, 0.0F, 0.0F },                /* '<S6>/Constant1' */

  { 0.0F, 0.0F, 0.0F },                /* '<S186>/Constant' */

  { 0.0F, 0.0F, 1.0F },                /* '<S210>/Vector Concatenate3' */
  0.0F,                                /* '<S213>/Constant' */
  19.1986F,                            /* '<S198>/Gain' */
  0.00250000018F,                      /* '<S211>/Square' */
  0.14709F,                            /* '<S211>/Multiply' */
  -58.836F,                            /* '<S211>/Gain4' */
  0.0F,                                /* '<S225>/Constant' */
  0.00250000018F,                      /* '<S232>/Square' */
  0.196120009F,                        /* '<S232>/Multiply' */
  -78.448F,                            /* '<S232>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S154>/Vector Concatenate3' */

  { 0.0F, 0.0F, 0.0F },                /* '<S86>/Constant' */
  289.0F,                              /* '<S71>/Square1' */
  0.0F,                                /* '<S157>/Zero1' */
  19.1986F,                            /* '<S94>/Gain' */

  { 0.0F, 0.0F, 0.0F },                /* '<S134>/Constant' */
  0.00250000018F,                      /* '<S107>/Square' */
  0.196120009F,                        /* '<S107>/Multiply' */
  -78.448F,                            /* '<S107>/Gain4' */
  0.0F                                 /* '<S160>/Zero' */
};

/* Constant parameters (default storage) */
const ConstP_Controller_T Controller_ConstP = {

#if (AIRFRAME == 1) || (AIRFRAME == 2)

  /* Pooled Parameter (Expression: [-sqrt(2) sqrt(2) 1;sqrt(2) -sqrt(2) 1;sqrt(2) sqrt(2) -1;-sqrt(2) -sqrt(2) -1])
   * Referenced by:
   *   '<S242>/Effective_Matrix'
   *   '<S252>/Effective_Matrix'
   */
  { -1.41421354F, 1.41421354F, 1.41421354F, -1.41421354F, 1.41421354F,
    -1.41421354F, 1.41421354F, -1.41421354F, 1.0F, 1.0F, -1.0F, -1.0F },

#endif

#if (AIRFRAME == 1) || (AIRFRAME == 2)

  /* Pooled Parameter (Expression: [1150 1150 1150 1150 1000]')
   * Referenced by:
   *   '<S250>/Disarm'
   *   '<S259>/Disarm'
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
