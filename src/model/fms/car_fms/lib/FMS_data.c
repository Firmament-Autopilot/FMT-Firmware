/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2089
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Sep 18 15:45:01 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FMS.h"
#include "FMS_private.h"

/* Invariant block signals (default storage) */
const ConstB_FMS_T FMS_ConstB = {
  {
    0U,
    0.0F,
    0.0F,
    0.0F,
    0.0F,
    0.0F,
    0.0F,
    0.0F,
    0.0F,
    0.0F,
    0.0F,
    0.0F,
    0.0F,

    { 1500U, 1500U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },
    0U,
    0U,
    3U,
    6U,
    0U,
    1U,
    0U,
    1U,
    0U,
    0U,

    { 0.0F, 0.0F, 0.0F, 0.0F },
    0U
  },                                   /* '<S169>/Bus Assignment' */

  {
    0U,
    0.0F,
    0.0F,
    0.0F,
    0.0F,
    0.0F,
    0.0F,
    0.0F,
    0.0F,
    0.0F,
    0.0F,
    0.0F,
    0.0F,

    { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },
    0U,
    0U,
    3U,
    10U,
    0U,
    5U,
    0U,
    0U,
    0U,
    0U,

    { 0.0F, 0.0F, 0.0F, 0.0F },
    0U
  },                                   /* '<S168>/Bus Assignment' */
  1.9966471893352524,                  /* '<S191>/Sum' */
  0.0066943799901413165,               /* '<S191>/Multiply3' */
  0.99330562000985867,                 /* '<S191>/Sum4' */
  1.9966471893352524,                  /* '<S152>/Sum' */
  0.0066943799901413165,               /* '<S152>/Multiply3' */
  0.99330562000985867,                 /* '<S152>/Sum4' */
  0.0,                                 /* '<S151>/deg2rad2' */
  0.0,                                 /* '<S154>/SinCos' */
  1.0,                                 /* '<S154>/SinCos' */

  { 0.0F, 0.0F, 1.0F },                /* '<S140>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S146>/Vector Concatenate3' */
  -0.0F,                               /* '<S143>/Gain' */
  1.0F,                                /* '<S144>/Trigonometric Function1' */
  -0.0F,                               /* '<S144>/Trigonometric Function' */
  -0.0F,                               /* '<S144>/Trigonometric Function2' */
  0.0F,                                /* '<S144>/Gain' */
  1.0F,                                /* '<S144>/Trigonometric Function3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S144>/Vector Concatenate3' */

  { 1.0F, -0.0F, 0.0F },               /* '<S144>/Vector Concatenate1' */

  { 0.0F, 1.0F, 0.0F },                /* '<S144>/Vector Concatenate2' */

  { 1.0F, -0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 1.0F },/* '<S144>/Vector Concatenate' */
  3U,                                  /* '<S28>/Data Type Conversion' */
  12U,                                 /* '<S28>/Data Type Conversion1' */
  1U,                                  /* '<S28>/Data Type Conversion2' */
  3U,                                  /* '<S31>/Data Type Conversion' */
  10U,                                 /* '<S31>/Data Type Conversion1' */
  5U,                                  /* '<S31>/Data Type Conversion2' */
  3U,                                  /* '<S32>/Data Type Conversion' */
  8U,                                  /* '<S32>/Data Type Conversion1' */
  3U,                                  /* '<S32>/Data Type Conversion2' */
  3U,                                  /* '<S86>/Data Type Conversion' */
  4U,                                  /* '<S86>/Data Type Conversion1' */
  5U,                                  /* '<S86>/Data Type Conversion2' */
  3U,                                  /* '<S83>/Data Type Conversion' */
  3U,                                  /* '<S83>/Data Type Conversion1' */
  6U,                                  /* '<S83>/Data Type Conversion2' */
  3U,                                  /* '<S169>/Data Type Conversion' */
  6U,                                  /* '<S169>/Data Type Conversion1' */
  1U,                                  /* '<S169>/Data Type Conversion2' */
  3U,                                  /* '<S168>/Data Type Conversion' */
  10U,                                 /* '<S168>/Data Type Conversion1' */
  5U,                                  /* '<S168>/Data Type Conversion2' */
  3U,                                  /* '<S166>/Data Type Conversion' */
  16U,                                 /* '<S166>/Data Type Conversion1' */
  5U,                                  /* '<S166>/Data Type Conversion2' */
  2U,                                  /* '<S25>/Data Type Conversion2' */
  2U,                                  /* '<S25>/Data Type Conversion1' */
  1U,                                  /* '<S24>/Data Type Conversion' */
  1U,                                  /* '<S24>/Data Type Conversion1' */

  /* Start of '<S22>/Unknown' */
  {
    1U,                                /* '<S30>/Data Type Conversion' */
    1U                                 /* '<S30>/Data Type Conversion1' */
  }
  ,

  /* End of '<S22>/Unknown' */

  /* Start of '<S26>/Unknown' */
  {
    1U,                                /* '<S33>/Data Type Conversion' */
    1U                                 /* '<S33>/Data Type Conversion1' */
  }
  ,

  /* End of '<S26>/Unknown' */

  /* Start of '<S27>/Unknown' */
  {
    1U,                                /* '<S84>/Data Type Conversion' */
    1U                                 /* '<S84>/Data Type Conversion1' */
  }
  ,

  /* End of '<S27>/Unknown' */

  /* Start of '<S29>/Unknown' */
  {
    1U,                                /* '<S167>/Data Type Conversion' */
    1U                                 /* '<S167>/Data Type Conversion1' */
  }
  /* End of '<S29>/Unknown' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
