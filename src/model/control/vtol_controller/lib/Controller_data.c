/*
 * File: Controller_data.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.572
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Aug 20 09:48:40 2025
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

  { 0.0F, 0.0F, 0.0F },                /* '<S118>/Constant' */

  { 0.0F, 0.0F, 1.0F },                /* '<S142>/Vector Concatenate3' */
  0.0F,                                /* '<S145>/Constant' */
  19.1986F,                            /* '<S130>/Gain' */
  0.0100000007F,                       /* '<S143>/Square' */
  0.784480035F,                        /* '<S143>/Multiply' */
  -78.448F,                            /* '<S143>/Gain4' */
  0.0F,                                /* '<S152>/Constant' */
  0.00250000018F,                      /* '<S159>/Square' */
  0.196120009F,                        /* '<S159>/Multiply' */
  -78.448F,                            /* '<S159>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S93>/Vector Concatenate3' */

  { 0.0F, 0.0F, 0.0F },                /* '<S26>/Constant' */
  289.0F,                              /* '<S10>/Square1' */
  0.0F,                                /* '<S95>/Zero1' */
  19.1986F,                            /* '<S34>/Gain' */
  0.0F,                                /* '<S98>/Zero' */

  { 0.0F, 0.0F, 0.0F },                /* '<S74>/Constant' */
  0.00250000018F,                      /* '<S46>/Square' */
  0.196120009F,                        /* '<S46>/Multiply' */
  -78.448F,                            /* '<S46>/Gain4' */

#if AIRFRAME == 1

  /* Start of '<S165>/VTOL1' */
  {
    { -0.5F, 0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, 0.5F, -0.5F,
      -0.5F },                         /* '<S169>/Gain' */

    { 0.5F, 0.5F, -0.5F, -0.5F },      /* '<S169>/r_column' */

    { -0.5F, 0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, -0.5F }/* '<S169>/pq_column' */
  }
  /* End of '<S165>/VTOL1' */
#endif
};

/* Constant parameters (default storage) */
const ConstP_Controller_T Controller_ConstP = {

#if (AIRFRAME == 1) || (AIRFRAME == 2)

  /* Pooled Parameter (Expression: [1150 1150 1150 1150 1000]')
   * Referenced by:
   *   '<S183>/Standby'
   *   '<S192>/Disarm'
   */
  { 1150.0F, 1150.0F, 1150.0F, 1150.0F, 1000.0F },

#endif

#if AIRFRAME == 2

  /* Computed Parameter: Effective_Matrix_Value_c
   * Referenced by: '<S185>/Effective_Matrix'
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
