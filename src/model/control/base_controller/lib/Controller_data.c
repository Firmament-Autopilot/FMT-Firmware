/*
 * File: Controller_data.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.968
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sun Sep 10 08:50:03 2023
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
  { 0.0F, 0.0F, 1.0F },                /* '<S99>/Vector Concatenate3' */
  0.0F,                                /* '<S102>/Constant' */
  19.1986F,                            /* '<S87>/Gain' */

  { 0.0F, 0.0F, 0.0F },                /* '<S75>/Constant' */
  0.00250000018F,                      /* '<S100>/Square' */
  0.14709F,                            /* '<S100>/Multiply' */
  -58.836F,                            /* '<S100>/Gain4' */
  0.00250000018F,                      /* '<S114>/Square' */
  0.196120009F,                        /* '<S114>/Multiply' */
  -78.448F                             /* '<S114>/Gain4' */
};

/* Constant parameters (default storage) */
const ConstP_Controller_T Controller_ConstP = {

#if AIRFRAME == 6

  /* Computed Parameter: Effective_Matrix_Value
   * Referenced by: '<S7>/Effective_Matrix'
   */
  { -0.5F, 0.5F, 0.5F, -0.5F, -0.5F, 0.5F, -0.5F, 0.5F, 0.5F, -0.5F, -0.5F, 0.5F,
    0.0F, 0.0F, 0.577350259F, -0.577350259F, 0.577350259F, -0.577350259F, 0.0F,
    0.0F, 0.577350259F, -0.577350259F, 0.577350259F, -0.577350259F,
    -0.333333343F, 0.333333343F, -0.333333343F, 0.333333343F, 0.333333343F,
    -0.333333343F, 0.333333343F, -0.333333343F, 0.333333343F, -0.333333343F,
    -0.333333343F, 0.333333343F },

#endif

#if AIRFRAME == 3

  /* Computed Parameter: Effective_Matrix_Value_j
   * Referenced by: '<S8>/Effective_Matrix'
   */
  { -0.707106769F, 0.707106769F, 0.707106769F, -0.707106769F, 0.707106769F,
    -0.707106769F, -0.707106769F, 0.707106769F, 0.707106769F, 0.707106769F,
    -0.707106769F, -0.707106769F, 0.707106769F, 0.707106769F, -0.707106769F,
    -0.707106769F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, -0.5F },

#endif

#if AIRFRAME == 5

  /* Computed Parameter: Effective_Matrix_Value_je
   * Referenced by: '<S9>/Effective_Matrix'
   */
  { 0.0F, 0.0F, 1.15470052F, -1.15470052F, 1.15470052F, -1.15470052F, 1.0F,
    -1.0F, -1.0F, 1.0F, 1.0F, -1.0F, -0.666666687F, 0.666666687F, -0.666666687F,
    0.666666687F, 0.666666687F, -0.666666687F },

#endif

#if AIRFRAME == 4

  /* Computed Parameter: Effective_Matrix_Value_f
   * Referenced by: '<S10>/Effective_Matrix'
   */
  { -1.0F, 1.0F, 1.0F, -1.0F, -1.0F, 1.0F, 0.0F, 0.0F, 1.15470052F, -1.15470052F,
    1.15470052F, -1.15470052F, -0.666666687F, 0.666666687F, -0.666666687F,
    0.666666687F, 0.666666687F, -0.666666687F },

#endif

#if AIRFRAME == 8

  /* Computed Parameter: Effective_Matrix_Value_m
   * Referenced by: '<S11>/Effective_Matrix'
   */
  { 0.0F, 0.0F, -0.707106769F, -0.707106769F, 0.707106769F, 0.707106769F, 1.0F,
    -1.0F, 1.0F, -1.0F, 0.707106769F, -0.707106769F, 0.707106769F, -0.707106769F,
    0.0F, 0.0F, -0.5F, -0.5F, 0.5F, 0.5F, 0.5F, 0.5F, -0.5F, -0.5F },

#endif

#if AIRFRAME == 7

  /* Computed Parameter: Effective_Matrix_Value_k
   * Referenced by: '<S12>/Effective_Matrix'
   */
  { -0.765F, 0.765F, -0.765F, -0.765F, 0.765F, 0.765F, 0.765F, -0.765F, 0.765F,
    -0.765F, 0.765F, -0.765F, 0.765F, -0.765F, 0.765F, -0.765F, -0.5F, -0.5F,
    0.5F, 0.5F, 0.5F, 0.5F, -0.5F, -0.5F },

#endif

#if AIRFRAME == 2

  /* Computed Parameter: Effective_Matrix_Value_fr
   * Referenced by: '<S13>/Effective_Matrix'
   */
  { -2.0F, 2.0F, 0.0F, 0.0F, 0.0F, 0.0F, 2.0F, -2.0F, 1.0F, 1.0F, -1.0F, -1.0F },

#endif

#if AIRFRAME == 1

  /* Computed Parameter: Effective_Matrix_Value_h
   * Referenced by: '<S14>/Effective_Matrix'
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
