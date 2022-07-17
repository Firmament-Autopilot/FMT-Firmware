/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1772
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Jul 16 23:29:46 2022
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
  0.0004F,                             /* '<S53>/Square' */
  0.00628318498F,                      /* '<S53>/Multiply' */
  -15.707963F,                         /* '<S53>/Gain4' */
  0.0016F,                             /* '<S50>/Square' */
  0.0201061927F,                       /* '<S50>/Multiply' */
  -12.566371F,                         /* '<S50>/Gain4' */
  0.0016F,                             /* '<S94>/Square' */
  0.0201061927F,                       /* '<S94>/Multiply' */
  -12.566371F,                         /* '<S94>/Gain4' */
  0.0004F,                             /* '<S98>/Square' */
  0.00628318498F,                      /* '<S98>/Multiply' */
  -15.707963F,                         /* '<S98>/Gain4' */
  0.0016F,                             /* '<S95>/Square' */
  0.0201061927F,                       /* '<S95>/Multiply' */
  -12.566371F,                         /* '<S95>/Gain4' */

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
  0.0004F,                             /* '<S204>/Square' */
  0.00628318498F,                      /* '<S204>/Multiply' */
  -15.707963F,                         /* '<S204>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S290>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S240>/Math Function' */
  1.0F,                                /* '<S240>/Sum of Elements' */
  1.0F,                                /* '<S240>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S240>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S240>/Switch' */

  { 0.0F, 1.0F },                      /* '<S240>/Divide' */
  0.616850317F,                        /* '<S236>/Square' */
  0.645964146F,                        /* '<S236>/Multiply' */
  -1.04719758F,                        /* '<S236>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S223>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S298>/Vector Concatenate3' */
  3U,                                  /* '<S23>/Data Type Conversion' */
  12U,                                 /* '<S23>/Data Type Conversion1' */
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
  3U,                                  /* '<S176>/Data Type Conversion' */
  6U,                                  /* '<S176>/Data Type Conversion1' */
  5U,                                  /* '<S176>/Data Type Conversion2' */
  3U,                                  /* '<S178>/Data Type Conversion' */
  16U,                                 /* '<S178>/Data Type Conversion1' */
  5U,                                  /* '<S178>/Data Type Conversion2' */
  3U,                                  /* '<S177>/Data Type Conversion' */
  15U,                                 /* '<S177>/Data Type Conversion1' */
  5U,                                  /* '<S177>/Data Type Conversion2' */
  3U,                                  /* '<S179>/Data Type Conversion' */
  17U,                                 /* '<S179>/Data Type Conversion1' */
  5U,                                  /* '<S179>/Data Type Conversion2' */
  2U,                                  /* '<S20>/Data Type Conversion2' */
  2U,                                  /* '<S20>/Data Type Conversion1' */
  1U,                                  /* '<S19>/Data Type Conversion' */
  1U,                                  /* '<S19>/Data Type Conversion1' */

  /* Start of '<S3>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S304>/Sum' */
    0.0066943799901413165,             /* '<S304>/Multiply3' */
    0.99330562000985867                /* '<S304>/Sum4' */
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

  /* Start of '<S58>/Move Control' */
  {
    0.00250000018F,                    /* '<S66>/Square' */
    0.196120009F,                      /* '<S66>/Multiply' */
    -78.448F                           /* '<S66>/Gain4' */
  }
  ,

  /* End of '<S58>/Move Control' */

  /* Start of '<S37>/Move Control' */
  {
    0.00250000018F,                    /* '<S45>/Square' */
    0.196120009F,                      /* '<S45>/Multiply' */
    -78.448F                           /* '<S45>/Gain4' */
  }
  ,

  /* End of '<S37>/Move Control' */

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
    1U,                                /* '<S180>/Data Type Conversion' */
    1U                                 /* '<S180>/Data Type Conversion1' */
  }
  ,

  /* End of '<S24>/Unknown' */

  /* Start of '<S206>/Move Control' */
  {
    0.00250000018F,                    /* '<S217>/Square' */
    0.14709F,                          /* '<S217>/Multiply' */
    -58.836F                           /* '<S217>/Gain4' */
  }
  ,

  /* End of '<S206>/Move Control' */

  /* Start of '<S206>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S213>/Vector Concatenate3' */
  }
  ,

  /* End of '<S206>/Hold Control' */

  /* Start of '<S184>/Move Control' */
  {
    0.00250000018F,                    /* '<S192>/Square' */
    0.196120009F,                      /* '<S192>/Multiply' */
    -78.448F                           /* '<S192>/Gain4' */
  }
  ,

  /* End of '<S184>/Move Control' */

  /* Start of '<S260>/Move Control' */
  {
    0.00250000018F,                    /* '<S271>/Square' */
    0.14709F,                          /* '<S271>/Multiply' */
    -58.836F                           /* '<S271>/Gain4' */
  }
  ,

  /* End of '<S260>/Move Control' */

  /* Start of '<S260>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S267>/Vector Concatenate3' */
  }
  ,

  /* End of '<S260>/Hold Control' */

  /* Start of '<S250>/Move Control' */
  {
    0.00250000018F,                    /* '<S258>/Square' */
    0.196120009F,                      /* '<S258>/Multiply' */
    -78.448F                           /* '<S258>/Gain4' */
  }
  /* End of '<S250>/Move Control' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
