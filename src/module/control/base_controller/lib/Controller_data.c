/*
 * File: Controller_data.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.877
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Dec 21 10:11:52 2021
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
  0.0F,                                /* '<S55>/Constant' */

  { 0.0F, 0.0F, 1.0F },                /* '<S39>/Vector Concatenate3' */
  0.0F,                                /* '<S42>/Constant' */
  19.1986F,                            /* '<S30>/Gain' */

  { 0.0F, 0.0F, 0.0F },                /* '<S20>/Constant' */
  0.00250000018F,                      /* '<S40>/Square' */
  0.14709F,                            /* '<S40>/Multiply' */
  -58.836F,                            /* '<S40>/Gain4' */
  0.00250000018F,                      /* '<S53>/Square' */
  0.196120009F,                        /* '<S53>/Multiply' */
  -78.448F                             /* '<S53>/Gain4' */
};

/* Constant parameters (default storage) */
const ConstP_Controller_T Controller_ConstP = {
  /* Computed Parameter: X_Frame_Effective_Matrix_Value
   * Referenced by: '<S6>/X_Frame_Effective_Matrix'
   */
  { -1.0F, 1.0F, 1.0F, -1.0F, 1.0F, -1.0F, 1.0F, -1.0F, 1.0F, 1.0F, -1.0F, -1.0F
  }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
