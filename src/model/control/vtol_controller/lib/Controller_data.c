/*
 * File: Controller_data.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.67
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Jul 24 10:38:02 2024
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
  256.0F,                              /* '<S120>/Square1' */
  0.0F,                                /* '<S150>/Zero1' */
  19.1986F,                            /* '<S101>/Gain' */

  { 0.0F, 0.0F, 0.0F },                /* '<S93>/Constant' */

  { 0.0F, 0.0F, 0.0F },                /* '<S130>/Constant' */
  0.0F,                                /* '<S153>/Zero' */
  0.00250000018F,                      /* '<S115>/Square' */
  0.196120009F,                        /* '<S115>/Multiply' */
  -78.448F,                            /* '<S115>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S48>/Vector Concatenate3' */
  0.0F,                                /* '<S51>/Constant' */
  19.1986F,                            /* '<S36>/Gain' */

  { 0.0F, 0.0F, 0.0F },                /* '<S24>/Constant' */
  0.00250000018F,                      /* '<S49>/Square' */
  0.14709F,                            /* '<S49>/Multiply' */
  -58.836F,                            /* '<S49>/Gain4' */
  0.00250000018F,                      /* '<S70>/Square' */
  0.196120009F,                        /* '<S70>/Multiply' */
  -78.448F                             /* '<S70>/Gain4' */
};

/* Constant parameters (default storage) */
const ConstP_Controller_T Controller_ConstP = {
  /* Pooled Parameter (Expression: [-sqrt(2) sqrt(2) 1;sqrt(2) -sqrt(2) 1;sqrt(2) sqrt(2) -1;-sqrt(2) -sqrt(2) -1])
   * Referenced by:
   *   '<S58>/Effective_Matrix'
   *   '<S165>/Effective_Matrix'
   */
  { -1.41421354F, 1.41421354F, 1.41421354F, -1.41421354F, 1.41421354F,
    -1.41421354F, 1.41421354F, -1.41421354F, 1.0F, 1.0F, -1.0F, -1.0F },

  /* Pooled Parameter (Expression: [1000 1500 1500 1500 1500]')
   * Referenced by:
   *   '<S60>/Disarm1'
   *   '<S162>/Disarm'
   */
  { 1000U, 1500U, 1500U, 1500U, 1500U },

  /* Computed Parameter: Standby_Value
   * Referenced by: '<S162>/Standby'
   */
  { 1050U, 1500U, 1500U, 1500U, 1500U }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
