/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1779
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sun Jul 17 14:34:43 2022
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
  { 0.0F, 0.0F, 1.0F },                /* '<S86>/Vector Concatenate3' */
  0.0004F,                             /* '<S71>/Square' */
  0.00628318498F,                      /* '<S71>/Multiply' */
  -15.707963F,                         /* '<S71>/Gain4' */
  0.00250000018F,                      /* '<S82>/Square' */
  0.14709F,                            /* '<S82>/Multiply' */
  -58.836F,                            /* '<S82>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S79>/Vector Concatenate3' */
  0.00250000018F,                      /* '<S66>/Square' */
  0.196120009F,                        /* '<S66>/Multiply' */
  -78.448F,                            /* '<S66>/Gain4' */
  0.0004F,                             /* '<S98>/Square' */
  0.00628318498F,                      /* '<S98>/Multiply' */
  -15.707963F,                         /* '<S98>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S174>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S120>/Math Function' */
  1.0F,                                /* '<S120>/Sum of Elements' */
  1.0F,                                /* '<S120>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S120>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S120>/Switch' */

  { 0.0F, 1.0F },                      /* '<S120>/Divide' */
  0.616850317F,                        /* '<S116>/Square' */
  0.645964146F,                        /* '<S116>/Multiply' */
  -1.04719758F,                        /* '<S116>/Gain4' */
  0.0004F,                             /* '<S205>/Square' */
  0.00628318498F,                      /* '<S205>/Multiply' */
  -15.707963F,                         /* '<S205>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S291>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S241>/Math Function' */
  1.0F,                                /* '<S241>/Sum of Elements' */
  1.0F,                                /* '<S241>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S241>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S241>/Switch' */

  { 0.0F, 1.0F },                      /* '<S241>/Divide' */
  0.616850317F,                        /* '<S237>/Square' */
  0.645964146F,                        /* '<S237>/Multiply' */
  -1.04719758F,                        /* '<S237>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S224>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S299>/Vector Concatenate3' */
  3U,                                  /* '<S23>/Data Type Conversion' */
  12U,                                 /* '<S23>/Data Type Conversion1' */
  1U,                                  /* '<S23>/Data Type Conversion2' */
  3U,                                  /* '<S28>/Data Type Conversion' */
  10U,                                 /* '<S28>/Data Type Conversion1' */
  5U,                                  /* '<S28>/Data Type Conversion2' */
  3U,                                  /* '<S27>/Data Type Conversion1' */
  9U,                                  /* '<S27>/Data Type Conversion2' */
  4U,                                  /* '<S27>/Data Type Conversion3' */
  3U,                                  /* '<S29>/Data Type Conversion' */
  8U,                                  /* '<S29>/Data Type Conversion1' */
  3U,                                  /* '<S29>/Data Type Conversion2' */
  3U,                                  /* '<S26>/Data Type Conversion' */
  7U,                                  /* '<S26>/Data Type Conversion1' */
  2U,                                  /* '<S26>/Data Type Conversion2' */
  3U,                                  /* '<S103>/Data Type Conversion' */
  4U,                                  /* '<S103>/Data Type Conversion1' */
  5U,                                  /* '<S103>/Data Type Conversion2' */
  1U,                                  /* '<S100>/Data Type Conversion' */
  3U,                                  /* '<S100>/Data Type Conversion1' */
  3U,                                  /* '<S177>/Data Type Conversion' */
  6U,                                  /* '<S177>/Data Type Conversion1' */
  5U,                                  /* '<S177>/Data Type Conversion2' */
  3U,                                  /* '<S179>/Data Type Conversion' */
  16U,                                 /* '<S179>/Data Type Conversion1' */
  5U,                                  /* '<S179>/Data Type Conversion2' */
  3U,                                  /* '<S178>/Data Type Conversion' */
  15U,                                 /* '<S178>/Data Type Conversion1' */
  5U,                                  /* '<S178>/Data Type Conversion2' */
  3U,                                  /* '<S180>/Data Type Conversion' */
  17U,                                 /* '<S180>/Data Type Conversion1' */
  5U,                                  /* '<S180>/Data Type Conversion2' */
  2U,                                  /* '<S20>/Data Type Conversion2' */
  2U,                                  /* '<S20>/Data Type Conversion1' */
  1U,                                  /* '<S19>/Data Type Conversion' */
  1U,                                  /* '<S19>/Data Type Conversion1' */

  /* Start of '<S3>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S305>/Sum' */
    0.0066943799901413165,             /* '<S305>/Multiply3' */
    0.99330562000985867                /* '<S305>/Sum4' */
  }
  ,

  /* End of '<S3>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */

  /* Start of '<S17>/Unknown' */
  {
    1U,                                /* '<S25>/Data Type Conversion' */
    1U                                 /* '<S25>/Data Type Conversion1' */
  }
  ,

  /* End of '<S17>/Unknown' */

  /* Start of '<S21>/Unknown' */
  {
    1U,                                /* '<S30>/Data Type Conversion' */
    1U                                 /* '<S30>/Data Type Conversion1' */
  }
  ,

  /* End of '<S21>/Unknown' */

  /* Start of '<S22>/Unknown' */
  {
    1U,                                /* '<S101>/Data Type Conversion' */
    1U                                 /* '<S101>/Data Type Conversion1' */
  }
  ,

  /* End of '<S22>/Unknown' */

  /* Start of '<S144>/Move Control' */
  {
    0.00250000018F,                    /* '<S155>/Square' */
    0.14709F,                          /* '<S155>/Multiply' */
    -58.836F                           /* '<S155>/Gain4' */
  }
  ,

  /* End of '<S144>/Move Control' */

  /* Start of '<S144>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S151>/Vector Concatenate3' */
  }
  ,

  /* End of '<S144>/Hold Control' */

  /* Start of '<S134>/Move Control' */
  {
    0.00250000018F,                    /* '<S142>/Square' */
    0.196120009F,                      /* '<S142>/Multiply' */
    -78.448F                           /* '<S142>/Gain4' */
  }
  ,

  /* End of '<S134>/Move Control' */

  /* Start of '<S24>/Unknown' */
  {
    1U,                                /* '<S181>/Data Type Conversion' */
    1U                                 /* '<S181>/Data Type Conversion1' */
  }
  ,

  /* End of '<S24>/Unknown' */

  /* Start of '<S207>/Move Control' */
  {
    0.00250000018F,                    /* '<S218>/Square' */
    0.14709F,                          /* '<S218>/Multiply' */
    -58.836F                           /* '<S218>/Gain4' */
  }
  ,

  /* End of '<S207>/Move Control' */

  /* Start of '<S207>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S214>/Vector Concatenate3' */
  }
  ,

  /* End of '<S207>/Hold Control' */

  /* Start of '<S185>/Move Control' */
  {
    0.00250000018F,                    /* '<S193>/Square' */
    0.196120009F,                      /* '<S193>/Multiply' */
    -78.448F                           /* '<S193>/Gain4' */
  }
  ,

  /* End of '<S185>/Move Control' */

  /* Start of '<S261>/Move Control' */
  {
    0.00250000018F,                    /* '<S272>/Square' */
    0.14709F,                          /* '<S272>/Multiply' */
    -58.836F                           /* '<S272>/Gain4' */
  }
  ,

  /* End of '<S261>/Move Control' */

  /* Start of '<S261>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S268>/Vector Concatenate3' */
  }
  ,

  /* End of '<S261>/Hold Control' */

  /* Start of '<S251>/Move Control' */
  {
    0.00250000018F,                    /* '<S259>/Square' */
    0.196120009F,                      /* '<S259>/Multiply' */
    -78.448F                           /* '<S259>/Gain4' */
  }
  /* End of '<S251>/Move Control' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
