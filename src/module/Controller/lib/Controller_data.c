/*
 * File: Controller_data.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.840
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Jul 31 15:22:50 2021
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

  { 0.0F, 0.0F, 1.0F },                /* '<S40>/Vector Concatenate3' */
  0.0F,                                /* '<S43>/Constant' */
  19.1986F,                            /* '<S31>/Gain' */

  { 0.0F, 0.0F, 0.0F },                /* '<S19>/Constant' */
  0.00250000018F,                      /* '<S41>/Square' */
  0.14709F,                            /* '<S41>/Multiply' */
  -58.836F,                            /* '<S41>/Gain4' */
  0.0004F,                             /* '<S24>/Square' */
  0.00628318498F,                      /* '<S24>/Multiply' */
  -15.707963F,                         /* '<S24>/Gain4' */
  0.00250000018F,                      /* '<S54>/Square' */
  0.196120009F,                        /* '<S54>/Multiply' */
  -78.448F                             /* '<S54>/Gain4' */
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
