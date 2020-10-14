/*
 * File: Controller_data.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.760
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Oct 12 15:35:03 2020
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
  0.0F,                                /* '<S56>/Constant' */

  { 0.0F, 0.0F, 1.0F },                /* '<S35>/VecConcentate3' */
  0.0F,                                /* '<S37>/Constant' */
  19.1986F,                            /* '<S28>/Gain' */

  { 0.0F, 0.0F, 0.0F }                 /* '<S20>/Constant' */
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
