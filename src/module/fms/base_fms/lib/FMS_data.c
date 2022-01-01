/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1213
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Jan  1 10:44:14 2022
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
  0.0016F,                             /* '<S51>/Square' */
  0.0201061927F,                       /* '<S51>/Multiply' */
  -12.566371F,                         /* '<S51>/Gain4' */
  0.0016F,                             /* '<S52>/Square' */
  0.0201061927F,                       /* '<S52>/Multiply' */
  -12.566371F,                         /* '<S52>/Gain4' */
  0.0016F,                             /* '<S115>/Square' */
  0.0201061927F,                       /* '<S115>/Multiply' */
  -12.566371F,                         /* '<S115>/Gain4' */
  0.0016F,                             /* '<S116>/Square' */
  0.0201061927F,                       /* '<S116>/Multiply' */
  -12.566371F,                         /* '<S116>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S246>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S197>/Math Function' */
  1.0F,                                /* '<S197>/Sum of Elements' */
  1.0F,                                /* '<S197>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S197>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S197>/Switch' */

  { 0.0F, 1.0F },                      /* '<S197>/Divide' */
  1.0F,                                /* '<S193>/Square' */
  0.785398185F,                        /* '<S193>/Multiply' */
  -0.785398185F,                       /* '<S193>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S180>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S250>/Vector Concatenate3' */
  1U,                                  /* '<S23>/Data Type Conversion' */
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
  1U,                                  /* '<S130>/Data Type Conversion' */
  4U,                                  /* '<S130>/Data Type Conversion1' */
  1U,                                  /* '<S131>/Data Type Conversion' */
  3U,                                  /* '<S131>/Data Type Conversion1' */
  3U,                                  /* '<S133>/Data Type Conversion' */
  6U,                                  /* '<S133>/Data Type Conversion1' */
  5U,                                  /* '<S133>/Data Type Conversion2' */
  3U,                                  /* '<S135>/Data Type Conversion' */
  16U,                                 /* '<S135>/Data Type Conversion1' */
  5U,                                  /* '<S135>/Data Type Conversion2' */
  3U,                                  /* '<S134>/Data Type Conversion' */
  15U,                                 /* '<S134>/Data Type Conversion1' */
  5U,                                  /* '<S134>/Data Type Conversion2' */
  3U,                                  /* '<S136>/Data Type Conversion' */
  17U,                                 /* '<S136>/Data Type Conversion1' */
  5U,                                  /* '<S136>/Data Type Conversion2' */
  2U,                                  /* '<S19>/Data Type Conversion2' */
  2U,                                  /* '<S19>/Data Type Conversion1' */

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

  /* Start of '<S93>/Move Control' */
  {
    0.00250000018F,                    /* '<S104>/Square' */
    0.14709F,                          /* '<S104>/Multiply' */
    -58.836F                           /* '<S104>/Gain4' */
  }
  ,

  /* End of '<S93>/Move Control' */

  /* Start of '<S93>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S100>/Vector Concatenate3' */
  }
  ,

  /* End of '<S93>/Hold Control' */

  /* Start of '<S80>/Move Control' */
  {
    0.0004F,                           /* '<S90>/Square' */
    0.00628318498F,                    /* '<S90>/Multiply' */
    -15.707963F                        /* '<S90>/Gain4' */
  }
  ,

  /* End of '<S80>/Move Control' */

  /* Start of '<S69>/Move Control' */
  {
    0.00250000018F,                    /* '<S77>/Square' */
    0.196120009F,                      /* '<S77>/Multiply' */
    -78.448F                           /* '<S77>/Gain4' */
  }
  ,

  /* End of '<S69>/Move Control' */

  /* Start of '<S53>/Move Control' */
  {
    0.0004F,                           /* '<S63>/Square' */
    0.00628318498F,                    /* '<S63>/Multiply' */
    -15.707963F                        /* '<S63>/Gain4' */
  }
  ,

  /* End of '<S53>/Move Control' */

  /* Start of '<S36>/Move Control' */
  {
    0.00250000018F,                    /* '<S44>/Square' */
    0.196120009F,                      /* '<S44>/Multiply' */
    -78.448F                           /* '<S44>/Gain4' */
  }
  ,

  /* End of '<S36>/Move Control' */

  /* Start of '<S117>/Move Control' */
  {
    0.0004F,                           /* '<S127>/Square' */
    0.00628318498F,                    /* '<S127>/Multiply' */
    -15.707963F                        /* '<S127>/Gain4' */
  }
  ,

  /* End of '<S117>/Move Control' */

  /* Start of '<S22>/Unknown' */
  {
    1U,                                /* '<S132>/Data Type Conversion' */
    1U                                 /* '<S132>/Data Type Conversion1' */
  }
  ,

  /* End of '<S22>/Unknown' */

  /* Start of '<S24>/Unknown' */
  {
    1U,                                /* '<S137>/Data Type Conversion' */
    1U                                 /* '<S137>/Data Type Conversion1' */
  }
  ,

  /* End of '<S24>/Unknown' */

  /* Start of '<S163>/Move Control' */
  {
    0.00250000018F,                    /* '<S174>/Square' */
    0.14709F,                          /* '<S174>/Multiply' */
    -58.836F                           /* '<S174>/Gain4' */
  }
  ,

  /* End of '<S163>/Move Control' */

  /* Start of '<S163>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S170>/Vector Concatenate3' */
  }
  ,

  /* End of '<S163>/Hold Control' */

  /* Start of '<S151>/Move Control' */
  {
    0.0004F,                           /* '<S161>/Square' */
    0.00628318498F,                    /* '<S161>/Multiply' */
    -15.707963F                        /* '<S161>/Gain4' */
  }
  ,

  /* End of '<S151>/Move Control' */

  /* Start of '<S141>/Move Control' */
  {
    0.00250000018F,                    /* '<S149>/Square' */
    0.196120009F,                      /* '<S149>/Multiply' */
    -78.448F                           /* '<S149>/Gain4' */
  }
  ,

  /* End of '<S141>/Move Control' */

  /* Start of '<S217>/Move Control' */
  {
    0.00250000018F,                    /* '<S228>/Square' */
    0.14709F,                          /* '<S228>/Multiply' */
    -58.836F                           /* '<S228>/Gain4' */
  }
  ,

  /* End of '<S217>/Move Control' */

  /* Start of '<S217>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S224>/Vector Concatenate3' */
  }
  ,

  /* End of '<S217>/Hold Control' */

  /* Start of '<S207>/Move Control' */
  {
    0.00250000018F,                    /* '<S215>/Square' */
    0.196120009F,                      /* '<S215>/Multiply' */
    -78.448F                           /* '<S215>/Gain4' */
  }
  ,

  /* End of '<S207>/Move Control' */

  /* Start of '<S2>/Disarm' */
  {
    1U,                                /* '<S18>/Data Type Conversion' */
    1U                                 /* '<S18>/Data Type Conversion1' */
  }
  /* End of '<S2>/Disarm' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
