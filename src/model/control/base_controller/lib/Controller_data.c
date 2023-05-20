/*
 * File: Controller_data.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.934
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat May 20 09:53:37 2023
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
  0.0F,                                /* '<S87>/Constant' */

  { 0.0F, 0.0F, 1.0F },                /* '<S65>/Vector Concatenate3' */
  0.0F,                                /* '<S68>/Constant' */
  19.1986F,                            /* '<S53>/Gain' */

  { 0.0F, 0.0F, 0.0F },                /* '<S41>/Constant' */
  0.00250000018F,                      /* '<S66>/Square' */
  0.14709F,                            /* '<S66>/Multiply' */
  -58.836F,                            /* '<S66>/Gain4' */
  0.00250000018F,                      /* '<S85>/Square' */
  0.196120009F,                        /* '<S85>/Multiply' */
  -78.448F                             /* '<S85>/Gain4' */
};

/* Constant parameters (default storage) */
const ConstP_Controller_T Controller_ConstP = {
  /* Computed Parameter: Effective_Matrix_Value
   * Referenced by: '<S10>/Effective_Matrix'
   */
  { -1.41421354F, 1.41421354F, 1.41421354F, -1.41421354F, 1.41421354F,
    -1.41421354F, 1.41421354F, -1.41421354F, 1.0F, 1.0F, -1.0F, -1.0F }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
