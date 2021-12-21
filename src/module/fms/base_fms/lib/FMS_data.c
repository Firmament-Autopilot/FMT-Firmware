/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1018
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Dec 21 14:39:40 2021
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
  0.0016F,                             /* '<S40>/Square' */
  0.0201061927F,                       /* '<S40>/Multiply' */
  -12.566371F,                         /* '<S40>/Gain4' */
  0.0016F,                             /* '<S41>/Square' */
  0.0201061927F,                       /* '<S41>/Multiply' */
  -12.566371F,                         /* '<S41>/Gain4' */
  0.0016F,                             /* '<S104>/Square' */
  0.0201061927F,                       /* '<S104>/Multiply' */
  -12.566371F,                         /* '<S104>/Gain4' */
  0.0016F,                             /* '<S105>/Square' */
  0.0201061927F,                       /* '<S105>/Multiply' */
  -12.566371F,                         /* '<S105>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S205>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S182>/Math Function' */
  1.0F,                                /* '<S182>/Sum of Elements' */
  1.0F,                                /* '<S182>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S182>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S182>/Switch' */

  { 0.0F, 1.0F },                      /* '<S182>/Divide' */
  1.0F,                                /* '<S180>/Square' */
  0.785398185F,                        /* '<S180>/Multiply' */
  -0.785398185F,                       /* '<S180>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S169>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S209>/Vector Concatenate3' */
  1U,                                  /* '<S12>/Data Type Conversion' */
  13U,                                 /* '<S12>/Data Type Conversion1' */
  3U,                                  /* '<S17>/Data Type Conversion' */
  11U,                                 /* '<S17>/Data Type Conversion1' */
  5U,                                  /* '<S17>/Data Type Conversion2' */
  3U,                                  /* '<S16>/Data Type Conversion1' */
  10U,                                 /* '<S16>/Data Type Conversion2' */
  4U,                                  /* '<S16>/Data Type Conversion3' */
  3U,                                  /* '<S18>/Data Type Conversion' */
  9U,                                  /* '<S18>/Data Type Conversion1' */
  3U,                                  /* '<S18>/Data Type Conversion2' */
  3U,                                  /* '<S15>/Data Type Conversion' */
  8U,                                  /* '<S15>/Data Type Conversion1' */
  2U,                                  /* '<S15>/Data Type Conversion2' */
  1U,                                  /* '<S119>/Data Type Conversion' */
  5U,                                  /* '<S119>/Data Type Conversion1' */
  1U,                                  /* '<S120>/Data Type Conversion' */
  4U,                                  /* '<S120>/Data Type Conversion1' */
  3U,                                  /* '<S122>/Data Type Conversion' */
  7U,                                  /* '<S122>/Data Type Conversion1' */
  5U,                                  /* '<S122>/Data Type Conversion2' */
  3U,                                  /* '<S124>/Data Type Conversion' */
  16U,                                 /* '<S124>/Data Type Conversion1' */
  5U,                                  /* '<S124>/Data Type Conversion2' */
  3U,                                  /* '<S123>/Data Type Conversion' */
  17U,                                 /* '<S123>/Data Type Conversion1' */
  5U,                                  /* '<S123>/Data Type Conversion2' */
  3U,                                  /* '<S125>/Data Type Conversion' */
  3U,                                  /* '<S125>/Data Type Conversion1' */
  5U,                                  /* '<S125>/Data Type Conversion2' */
  2U,                                  /* '<S8>/Data Type Conversion2' */
  2U,                                  /* '<S8>/Data Type Conversion1' */

  /* Start of '<S6>/Unknown' */
  {
    1U,                                /* '<S14>/Data Type Conversion' */
    1U                                 /* '<S14>/Data Type Conversion1' */
  }
  ,

  /* End of '<S6>/Unknown' */

  /* Start of '<S10>/Unknown' */
  {
    1U,                                /* '<S19>/Data Type Conversion' */
    1U                                 /* '<S19>/Data Type Conversion1' */
  }
  ,

  /* End of '<S10>/Unknown' */

  /* Start of '<S82>/Move Control' */
  {
    0.00250000018F,                    /* '<S93>/Square' */
    0.14709F,                          /* '<S93>/Multiply' */
    -58.836F                           /* '<S93>/Gain4' */
  }
  ,

  /* End of '<S82>/Move Control' */

  /* Start of '<S82>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S89>/Vector Concatenate3' */
  }
  ,

  /* End of '<S82>/Hold Control' */

  /* Start of '<S69>/Move Control' */
  {
    0.0004F,                           /* '<S79>/Square' */
    0.00628318498F,                    /* '<S79>/Multiply' */
    -15.707963F                        /* '<S79>/Gain4' */
  }
  ,

  /* End of '<S69>/Move Control' */

  /* Start of '<S58>/Move Control' */
  {
    0.00250000018F,                    /* '<S66>/Square' */
    0.196120009F,                      /* '<S66>/Multiply' */
    -78.448F                           /* '<S66>/Gain4' */
  }
  ,

  /* End of '<S58>/Move Control' */

  /* Start of '<S42>/Move Control' */
  {
    0.0004F,                           /* '<S52>/Square' */
    0.00628318498F,                    /* '<S52>/Multiply' */
    -15.707963F                        /* '<S52>/Gain4' */
  }
  ,

  /* End of '<S42>/Move Control' */

  /* Start of '<S25>/Move Control' */
  {
    0.00250000018F,                    /* '<S33>/Square' */
    0.196120009F,                      /* '<S33>/Multiply' */
    -78.448F                           /* '<S33>/Gain4' */
  }
  ,

  /* End of '<S25>/Move Control' */

  /* Start of '<S106>/Move Control' */
  {
    0.0004F,                           /* '<S116>/Square' */
    0.00628318498F,                    /* '<S116>/Multiply' */
    -15.707963F                        /* '<S116>/Gain4' */
  }
  ,

  /* End of '<S106>/Move Control' */

  /* Start of '<S11>/Unknown' */
  {
    1U,                                /* '<S121>/Data Type Conversion' */
    1U                                 /* '<S121>/Data Type Conversion1' */
  }
  ,

  /* End of '<S11>/Unknown' */

  /* Start of '<S13>/Unknown' */
  {
    1U,                                /* '<S126>/Data Type Conversion' */
    1U                                 /* '<S126>/Data Type Conversion1' */
  }
  ,

  /* End of '<S13>/Unknown' */

  /* Start of '<S152>/Move Control' */
  {
    0.00250000018F,                    /* '<S163>/Square' */
    0.14709F,                          /* '<S163>/Multiply' */
    -58.836F                           /* '<S163>/Gain4' */
  }
  ,

  /* End of '<S152>/Move Control' */

  /* Start of '<S152>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S159>/Vector Concatenate3' */
  }
  ,

  /* End of '<S152>/Hold Control' */

  /* Start of '<S140>/Move Control' */
  {
    0.0004F,                           /* '<S150>/Square' */
    0.00628318498F,                    /* '<S150>/Multiply' */
    -15.707963F                        /* '<S150>/Gain4' */
  }
  ,

  /* End of '<S140>/Move Control' */

  /* Start of '<S130>/Move Control' */
  {
    0.00250000018F,                    /* '<S138>/Square' */
    0.196120009F,                      /* '<S138>/Multiply' */
    -78.448F                           /* '<S138>/Gain4' */
  }
  ,

  /* End of '<S130>/Move Control' */

  /* Start of '<S2>/Disarm' */
  {
    1U,                                /* '<S7>/Data Type Conversion' */
    1U                                 /* '<S7>/Data Type Conversion1' */
  }
  /* End of '<S2>/Disarm' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
