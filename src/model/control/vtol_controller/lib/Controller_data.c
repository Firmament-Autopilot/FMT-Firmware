/*
 * File: Controller_data.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.321
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Jun  6 14:34:27 2025
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

  { 0.0F, 0.0F, 1.0F },                /* '<S152>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S154>/Vector Concatenate3' */

  { 0.0F, 0.0F, 0.0F },                /* '<S85>/Constant' */
  289.0F,                              /* '<S70>/Square1' */
  0.0F,                                /* '<S157>/Zero1' */
  19.1986F,                            /* '<S93>/Gain' */

  { 0.0F, 0.0F, 0.0F },                /* '<S133>/Constant' */
  0.00250000018F,                      /* '<S106>/Square' */
  0.196120009F,                        /* '<S106>/Multiply' */
  -78.448F,                            /* '<S106>/Gain4' */
  0.0F                                 /* '<S160>/Zero' */
};

/* Constant parameters (default storage) */
const ConstP_Controller_T Controller_ConstP = {

#if (AIRFRAME == 1) || (AIRFRAME == 2)

  /* Pooled Parameter (Expression: [-sqrt(2) sqrt(2) 1;sqrt(2) -sqrt(2) 1;sqrt(2) sqrt(2) -1;-sqrt(2) -sqrt(2) -1])
   * Referenced by:
   *   '<S242>/Effective_Matrix'
   *   '<S249>/Effective_Matrix'
   */
  { -1.41421354F, 1.41421354F, 1.41421354F, -1.41421354F, 1.41421354F,
    -1.41421354F, 1.41421354F, -1.41421354F, 1.0F, 1.0F, -1.0F, -1.0F },

#endif

#if AIRFRAME == 2

  /* Computed Parameter: Disarm_Value_j
   * Referenced by: '<S256>/Disarm'
   */
  { 1150.0F, 1150.0F, 1150.0F, 1150.0F, 1000.0F },

#endif

#if AIRFRAME == 1

  /* Computed Parameter: Disarm_Value_c
   * Referenced by: '<S243>/Disarm'
   */
  { 1000U, 1000U, 1000U, 1000U, 1000U, 1500U, 1500U, 1500U, 1500U },

#endif

#if AIRFRAME == 1

  /* Computed Parameter: Standby_Value
   * Referenced by: '<S243>/Standby'
   */
  { 1150U, 1150U, 1150U, 1150U, 1000U, 1500U, 1500U, 1500U, 1500U },

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
