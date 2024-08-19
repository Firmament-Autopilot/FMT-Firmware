/*
 * File: Controller_data.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.207
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Aug 19 14:49:22 2024
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
  { 0.0F, 0.0F, 0.0F },                /* '<S91>/Constant' */

  { 0.0F, 0.0F, 1.0F },                /* '<S115>/Vector Concatenate3' */
  0.0F,                                /* '<S118>/Constant' */
  19.1986F,                            /* '<S103>/Gain' */
  0.00250000018F,                      /* '<S116>/Square' */
  0.14709F,                            /* '<S116>/Multiply' */
  -58.836F,                            /* '<S116>/Gain4' */
  0.00250000018F,                      /* '<S137>/Square' */
  0.196120009F,                        /* '<S137>/Multiply' */
  -78.448F,                            /* '<S137>/Gain4' */

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
  289.0F,                              /* '<S143>/Square1' */

  { 0.0F, 0.0F, 1.0F },                /* '<S219>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S221>/Vector Concatenate3' */
  0.0F,                                /* '<S224>/Zero1' */
  19.1986F,                            /* '<S167>/Gain' */

  { 0.0F, 0.0F, 0.0F },                /* '<S159>/Constant' */

  { 0.0F, 0.0F, 0.0F },                /* '<S199>/Constant' */
  0.0F,                                /* '<S227>/Zero' */
  0.00250000018F,                      /* '<S182>/Square' */
  0.196120009F,                        /* '<S182>/Multiply' */
  -78.448F,                            /* '<S182>/Gain4' */

#if AIRFRAME == 2

  /* Start of '<S61>/VTOL2' */
  {
    0U,                                /* '<S74>/Gain1' */
    1000U,                             /* '<S74>/Sum1' */

    { 0.0F, 0.0F, 0.0F },              /* '<S70>/Saturation5' */
    0.0F,                              /* '<S70>/Saturation4' */
    0.0F,                              /* '<S74>/Saturation' */
    1000U                              /* '<S74>/Data Type Conversion' */
  }
  ,

  /* End of '<S61>/VTOL2' */
#endif

#if AIRFRAME == 1

  /* Start of '<S61>/VTOL1' */
  {
    0U,                                /* '<S68>/Gain1' */
    1000U,                             /* '<S68>/Sum1' */

    { 0.0F, 0.0F, 0.0F },              /* '<S64>/Saturation5' */
    0.0F,                              /* '<S64>/Saturation4' */
    0.0F,                              /* '<S68>/Saturation' */
    1000U                              /* '<S68>/Data Type Conversion' */
  }
  /* End of '<S61>/VTOL1' */
#endif
};

/* Constant parameters (default storage) */
const ConstP_Controller_T Controller_ConstP = {
  /* Pooled Parameter (Expression: [-sqrt(2) sqrt(2) 1;sqrt(2) -sqrt(2) 1;sqrt(2) sqrt(2) -1;-sqrt(2) -sqrt(2) -1])
   * Referenced by:
   *   '<S125>/Effective_Matrix'
   *   '<S65>/Effective_Matrix'
   *   '<S71>/Effective_Matrix'
   *   '<S242>/Effective_Matrix'
   *   '<S250>/Effective_Matrix'
   */
  { -1.41421354F, 1.41421354F, 1.41421354F, -1.41421354F, 1.41421354F,
    -1.41421354F, 1.41421354F, -1.41421354F, 1.0F, 1.0F, -1.0F, -1.0F },

#if (AIRFRAME == 1) || (AIRFRAME == 2)

  /* Pooled Parameter (Expression: [1000 1000 1000 1000 1000 1500 1500 1500 1500]')
   * Referenced by:
   *   '<S66>/Disarm'
   *   '<S72>/Disarm'
   *   '<S243>/Disarm'
   *   '<S251>/Disarm'
   */
  { 1000U, 1000U, 1000U, 1000U, 1000U, 1500U, 1500U, 1500U, 1500U },

#endif

#if (AIRFRAME == 1) || (AIRFRAME == 2)

  /* Pooled Parameter (Expression: [1150 1150 1150 1150 1000 1500 1500 1500 1500]')
   * Referenced by:
   *   '<S66>/Standby'
   *   '<S72>/Standby'
   *   '<S243>/Standby'
   *   '<S251>/Standby'
   */
  { 1150U, 1150U, 1150U, 1150U, 1000U, 1500U, 1500U, 1500U, 1500U },

#endif

  /* Computed Parameter: Disarm1_Value
   * Referenced by: '<S127>/Disarm1'
   */
  { 1000U, 1500U, 1500U, 1500U, 1500U }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
