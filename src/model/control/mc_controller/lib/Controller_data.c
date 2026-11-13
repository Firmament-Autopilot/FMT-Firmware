/*
 * File: Controller_data.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.1047
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Nov 13 13:47:38 2026
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
  19.1986F,                            /* '<S82>/Gain' */

  { 0.0F, 0.0F, 0.0F },                /* '<S70>/Constant' */
  0.00250000018F,                      /* '<S117>/Square' */
  0.196120009F,                        /* '<S117>/Multiply' */
  -78.448F,                            /* '<S117>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S96>/Vector Concatenate3' */
  0.00250000018F,                      /* '<S97>/Square' */
  0.14709F,                            /* '<S97>/Multiply' */
  -58.836F,                            /* '<S97>/Gain4' */
  0.0F,                                /* '<S99>/Constant' */

#if AIRFRAME == 1

  /* Start of '<S4>/Quadcopter_x' */
  {
    { -0.5F, 0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, -0.5F },/* '<S50>/pq_column' */
    0.799999952F,                      /* '<S53>/Subtract1' */

    { 0.5F, 0.5F, -0.5F, -0.5F }       /* '<S51>/r_column' */
  }
  ,

  /* End of '<S4>/Quadcopter_x' */
#endif

#if AIRFRAME == 2

  /* Start of '<S4>/Quadcopter_+' */
  {
    { -0.5F, 0.5F, 0.0F, 0.0F, 0.0F, 0.0F, 0.5F, -0.5F },/* '<S45>/pq_column' */
    0.799999952F,                      /* '<S48>/Subtract1' */

    { 0.5F, 0.5F, -0.5F, -0.5F }       /* '<S46>/r_column' */
  }
  ,

  /* End of '<S4>/Quadcopter_+' */
#endif

#if AIRFRAME == 7

  /* Start of '<S4>/Octocopter_x' */
  {
    { -0.15F, 0.15F, -0.5F, -0.15F, 0.15F, 0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.15F,
      -0.5F, 0.5F, -0.15F, 0.15F, -0.15F },/* '<S40>/pq_column' */
    0.799999952F,                      /* '<S43>/Subtract1' */

    { -0.5F, -0.5F, 0.5F, 0.5F, 0.5F, 0.5F, -0.5F, -0.5F }/* '<S41>/r_column' */
  }
  ,

  /* End of '<S4>/Octocopter_x' */
#endif

#if AIRFRAME == 8

  /* Start of '<S4>/Octocopter_+' */
  {
    { 0.0F, 0.0F, -0.146F, -0.146F, 0.146F, 0.146F, 0.5F, -0.5F, 0.5F, -0.5F,
      0.146F, -0.146F, 0.146F, -0.146F, 0.0F, 0.0F },/* '<S35>/pq_column' */
    0.799999952F,                      /* '<S38>/Subtract1' */

    { -0.5F, -0.5F, 0.5F, 0.5F, 0.5F, 0.5F, -0.5F, -0.5F }/* '<S36>/r_column' */
  }
  ,

  /* End of '<S4>/Octocopter_+' */
#endif

#if AIRFRAME == 4

  /* Start of '<S4>/Hexacopter_x' */
  {
    { -0.5F, 0.5F, 0.207106784F, -0.207106784F, -0.207106784F, 0.207106784F,
      0.0F, 0.0F, 0.408248305F, -0.408248305F, 0.408248305F, -0.408248305F },/* '<S30>/pq_column' */
    0.799999952F,                      /* '<S33>/Subtract1' */

    { -0.5F, 0.5F, -0.5F, 0.5F, 0.5F, -0.5F }/* '<S31>/r_column' */
  }
  ,

  /* End of '<S4>/Hexacopter_x' */
#endif

#if AIRFRAME == 5

  /* Start of '<S4>/Hexacopter_+' */
  {
    { 0.0F, 0.0F, 0.408248305F, -0.408248305F, 0.408248305F, -0.408248305F, 0.5F,
      -0.5F, -0.207106784F, 0.207106784F, 0.207106784F, -0.207106784F },/* '<S25>/pq_column' */
    0.799999952F,                      /* '<S28>/Subtract1' */

    { -0.5F, 0.5F, -0.5F, 0.5F, 0.5F, -0.5F }/* '<S26>/r_column' */
  }
  ,

  /* End of '<S4>/Hexacopter_+' */
#endif

#if AIRFRAME == 3

  /* Start of '<S4>/Coxial_Quadcopter_x' */
  {
    { -0.5F, 0.5F, 0.5F, -0.5F, 0.5F, -0.5F, -0.5F, 0.5F, 0.5F, 0.5F, -0.5F,
      -0.5F, 0.5F, 0.5F, -0.5F, -0.5F },/* '<S20>/pq_column' */
    0.799999952F,                      /* '<S23>/Subtract1' */

    { 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, -0.5F }/* '<S21>/r_column' */
  }
  ,

  /* End of '<S4>/Coxial_Quadcopter_x' */
#endif

#if AIRFRAME == 6

  /* Start of '<S4>/Coxial_Hexacopter_x' */
  {
    { -0.5F, 0.5F, 0.207106784F, -0.207106784F, -0.207106784F, 0.207106784F,
      -0.5F, 0.5F, 0.207106784F, -0.207106784F, -0.207106784F, 0.207106784F,
      0.0F, 0.0F, 0.408248305F, -0.408248305F, 0.408248305F, -0.408248305F, 0.0F,
      0.0F, 0.408248305F, -0.408248305F, 0.408248305F, -0.408248305F },/* '<S15>/pq_column' */
    0.799999952F,                      /* '<S18>/Subtract1' */

    { -0.5F, 0.5F, -0.5F, 0.5F, 0.5F, -0.5F, 0.5F, -0.5F, 0.5F, -0.5F, -0.5F,
      0.5F }                           /* '<S16>/r_column' */
  }
  /* End of '<S4>/Coxial_Hexacopter_x' */
#endif
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
