/*
 * File: Controller_data.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.141
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Aug  6 13:46:11 2024
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
  { 0.0F, 0.0F, 0.0F },                /* '<S23>/Constant' */

  { 0.0F, 0.0F, 1.0F },                /* '<S47>/Vector Concatenate3' */
  0.0F,                                /* '<S50>/Constant' */
  19.1986F,                            /* '<S35>/Gain' */
  0.00250000018F,                      /* '<S48>/Square' */
  0.14709F,                            /* '<S48>/Multiply' */
  -58.836F,                            /* '<S48>/Gain4' */
  0.00250000018F,                      /* '<S69>/Square' */
  0.196120009F,                        /* '<S69>/Multiply' */
  -78.448F,                            /* '<S69>/Gain4' */
  289.0F,                              /* '<S75>/Square1' */
  0.0F,                                /* '<S154>/Zero1' */
  19.1986F,                            /* '<S99>/Gain' */

  { 0.0F, 0.0F, 0.0F },                /* '<S91>/Constant' */

  { 0.0F, 0.0F, 0.0F },                /* '<S134>/Constant' */
  0.0F,                                /* '<S157>/Zero' */
  0.00250000018F,                      /* '<S117>/Square' */
  0.196120009F,                        /* '<S117>/Multiply' */
  -78.448F,                            /* '<S117>/Gain4' */
  0.1F                                 /* '<S167>/dT' */
};

/* Constant parameters (default storage) */
const ConstP_Controller_T Controller_ConstP = {
  /* Pooled Parameter (Expression: [-sqrt(2) sqrt(2) 1;sqrt(2) -sqrt(2) 1;sqrt(2) sqrt(2) -1;-sqrt(2) -sqrt(2) -1])
   * Referenced by:
   *   '<S57>/Effective_Matrix'
   *   '<S164>/Effective_Matrix'
   */
  { -1.41421354F, 1.41421354F, 1.41421354F, -1.41421354F, 1.41421354F,
    -1.41421354F, 1.41421354F, -1.41421354F, 1.0F, 1.0F, -1.0F, -1.0F },

  /* Computed Parameter: Disarm_Value
   * Referenced by: '<S165>/Disarm'
   */
  { 1000U, 1000U, 1000U, 1000U, 1000U, 1500U, 1500U, 1500U, 1500U },

  /* Computed Parameter: Standby_Value
   * Referenced by: '<S165>/Standby'
   */
  { 1150U, 1150U, 1150U, 1150U, 1000U, 1500U, 1500U, 1500U, 1500U },

  /* Computed Parameter: Disarm1_Value
   * Referenced by: '<S59>/Disarm1'
   */
  { 1000U, 1500U, 1500U, 1500U, 1500U }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
