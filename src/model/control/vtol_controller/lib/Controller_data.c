/*
 * File: Controller_data.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.196
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Aug  9 11:40:35 2024
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
  0U,                                  /* '<S67>/Gain1' */
  1000U,                               /* '<S67>/Sum1' */

  { 0.0F, 0.0F, 0.0F },                /* '<S84>/Constant' */

  { 0.0F, 0.0F, 1.0F },                /* '<S108>/Vector Concatenate3' */
  0.0F,                                /* '<S111>/Constant' */
  19.1986F,                            /* '<S96>/Gain' */
  0.00250000018F,                      /* '<S109>/Square' */
  0.14709F,                            /* '<S109>/Multiply' */
  -58.836F,                            /* '<S109>/Gain4' */
  0.00250000018F,                      /* '<S130>/Square' */
  0.196120009F,                        /* '<S130>/Multiply' */
  -78.448F,                            /* '<S130>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S44>/Vector Concatenate3' */
  0.0F,                                /* '<S47>/Constant' */
  19.1986F,                            /* '<S35>/Gain' */

  { 0.0F, 0.0F, 0.0F },                /* '<S25>/Constant' */
  0.00250000018F,                      /* '<S45>/Square' */
  0.14709F,                            /* '<S45>/Multiply' */
  -58.836F,                            /* '<S45>/Gain4' */
  0.00250000018F,                      /* '<S55>/Square' */
  0.196120009F,                        /* '<S55>/Multiply' */
  -78.448F,                            /* '<S55>/Gain4' */

  { 0.0F, 0.0F, 0.0F },                /* '<S63>/Saturation5' */
  0.0F,                                /* '<S63>/Saturation4' */
  0.0F,                                /* '<S67>/Saturation' */
  289.0F,                              /* '<S136>/Square1' */

  { 0.0F, 0.0F, 1.0F },                /* '<S212>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S214>/Vector Concatenate3' */
  0.0F,                                /* '<S217>/Zero1' */
  19.1986F,                            /* '<S160>/Gain' */

  { 0.0F, 0.0F, 0.0F },                /* '<S152>/Constant' */

  { 0.0F, 0.0F, 0.0F },                /* '<S192>/Constant' */
  0.0F,                                /* '<S220>/Zero' */
  0.00250000018F,                      /* '<S175>/Square' */
  0.196120009F,                        /* '<S175>/Multiply' */
  -78.448F,                            /* '<S175>/Gain4' */
  1000U                                /* '<S67>/Data Type Conversion' */
};

/* Constant parameters (default storage) */
const ConstP_Controller_T Controller_ConstP = {
  /* Pooled Parameter (Expression: [-sqrt(2) sqrt(2) 1;sqrt(2) -sqrt(2) 1;sqrt(2) sqrt(2) -1;-sqrt(2) -sqrt(2) -1])
   * Referenced by:
   *   '<S118>/Effective_Matrix'
   *   '<S64>/Effective_Matrix'
   *   '<S234>/Effective_Matrix'
   */
  { -1.41421354F, 1.41421354F, 1.41421354F, -1.41421354F, 1.41421354F,
    -1.41421354F, 1.41421354F, -1.41421354F, 1.0F, 1.0F, -1.0F, -1.0F },

  /* Pooled Parameter (Expression: [1000 1000 1000 1000 1000 1500 1500 1500 1500]')
   * Referenced by:
   *   '<S65>/Disarm'
   *   '<S235>/Disarm'
   */
  { 1000U, 1000U, 1000U, 1000U, 1000U, 1500U, 1500U, 1500U, 1500U },

  /* Pooled Parameter (Expression: [1150 1150 1150 1150 1000 1500 1500 1500 1500]')
   * Referenced by:
   *   '<S65>/Standby'
   *   '<S235>/Standby'
   */
  { 1150U, 1150U, 1150U, 1150U, 1000U, 1500U, 1500U, 1500U, 1500U },

  /* Computed Parameter: Disarm1_Value
   * Referenced by: '<S120>/Disarm1'
   */
  { 1000U, 1500U, 1500U, 1500U, 1500U }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
