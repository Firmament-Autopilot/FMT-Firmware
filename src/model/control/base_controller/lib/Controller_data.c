/*
 * File: Controller_data.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.940
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat May 20 10:48:40 2023
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
  { 0.0F, 0.0F, 1.0F },                /* '<S64>/Vector Concatenate3' */
  0.0F,                                /* '<S67>/Constant' */
  19.1986F,                            /* '<S52>/Gain' */

  { 0.0F, 0.0F, 0.0F },                /* '<S40>/Constant' */
  0.0F,                                /* '<S81>/Constant' */
  0.00250000018F,                      /* '<S65>/Square' */
  0.14709F,                            /* '<S65>/Multiply' */
  -58.836F,                            /* '<S65>/Gain4' */
  0.00250000018F,                      /* '<S79>/Square' */
  0.196120009F,                        /* '<S79>/Multiply' */
  -78.448F                             /* '<S79>/Gain4' */
};

/* Constant parameters (default storage) */
const ConstP_Controller_T Controller_ConstP = {

#if AIRFRAME == 3

  /* Computed Parameter: Effective_Matrix_Value
   * Referenced by: '<S7>/Effective_Matrix'
   */
  { -0.707106769F, 0.707106769F, 0.707106769F, -0.707106769F, 0.707106769F,
    -0.707106769F, -0.707106769F, 0.707106769F, 0.707106769F, 0.707106769F,
    -0.707106769F, -0.707106769F, 0.707106769F, 0.707106769F, -0.707106769F,
    -0.707106769F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, -0.5F },

#endif

#if AIRFRAME == 2

  /* Computed Parameter: Effective_Matrix_Value_f
   * Referenced by: '<S8>/Effective_Matrix'
   */
  { -2.0F, 2.0F, 0.0F, 0.0F, 0.0F, 0.0F, 2.0F, -2.0F, 1.0F, 1.0F, -1.0F, -1.0F },

#endif

#if AIRFRAME == 1

  /* Computed Parameter: Effective_Matrix_Value_h
   * Referenced by: '<S9>/Effective_Matrix'
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
