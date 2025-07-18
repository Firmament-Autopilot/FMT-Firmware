/*
 * File: Controller_data.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.358
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Jul 17 15:44:51 2025
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

  { 0.0F, 0.0F, 0.0F },                /* '<S189>/Constant' */

  { 0.0F, 0.0F, 1.0F },                /* '<S213>/Vector Concatenate3' */
  0.0F,                                /* '<S216>/Constant' */
  19.1986F,                            /* '<S201>/Gain' */
  0.00250000018F,                      /* '<S214>/Square' */
  0.14709F,                            /* '<S214>/Multiply' */
  -58.836F,                            /* '<S214>/Gain4' */
  0.0F,                                /* '<S228>/Constant' */
  0.00250000018F,                      /* '<S235>/Square' */
  0.196120009F,                        /* '<S235>/Multiply' */
  -78.448F,                            /* '<S235>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S155>/Vector Concatenate3' */

  { 0.0F, 0.0F, 0.0F },                /* '<S87>/Constant' */
  289.0F,                              /* '<S71>/Square1' */
  0.0F,                                /* '<S158>/Zero1' */
  19.1986F,                            /* '<S95>/Gain' */
  0.0F,                                /* '<S161>/Zero' */

  { 0.0F, 0.0F, 0.0F },                /* '<S135>/Constant' */
  0.00250000018F,                      /* '<S108>/Square' */
  0.196120009F,                        /* '<S108>/Multiply' */
  -78.448F                             /* '<S108>/Gain4' */
};

/* Constant parameters (default storage) */
const ConstP_Controller_T Controller_ConstP = {

#if (AIRFRAME == 1) || (AIRFRAME == 2)

  /* Pooled Parameter (Expression: [-sqrt(2) sqrt(2) 1;sqrt(2) -sqrt(2) 1;sqrt(2) sqrt(2) -1;-sqrt(2) -sqrt(2) -1])
   * Referenced by:
   *   '<S245>/Effective_Matrix'
   *   '<S254>/Effective_Matrix'
   */
  { -1.41421354F, 1.41421354F, 1.41421354F, -1.41421354F, 1.41421354F,
    -1.41421354F, 1.41421354F, -1.41421354F, 1.0F, 1.0F, -1.0F, -1.0F },

#endif

#if (AIRFRAME == 1) || (AIRFRAME == 2)

  /* Pooled Parameter (Expression: [1150 1150 1150 1150 1000]')
   * Referenced by:
   *   '<S252>/Disarm'
   *   '<S261>/Disarm'
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
