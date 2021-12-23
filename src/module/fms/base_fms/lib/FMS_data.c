/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1129
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Dec 23 16:25:01 2021
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
  0.0016F,                             /* '<S49>/Square' */
  0.0201061927F,                       /* '<S49>/Multiply' */
  -12.566371F,                         /* '<S49>/Gain4' */
  0.0016F,                             /* '<S50>/Square' */
  0.0201061927F,                       /* '<S50>/Multiply' */
  -12.566371F,                         /* '<S50>/Gain4' */
  0.0016F,                             /* '<S113>/Square' */
  0.0201061927F,                       /* '<S113>/Multiply' */
  -12.566371F,                         /* '<S113>/Gain4' */
  0.0016F,                             /* '<S114>/Square' */
  0.0201061927F,                       /* '<S114>/Multiply' */
  -12.566371F,                         /* '<S114>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S242>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S193>/Math Function' */
  1.0F,                                /* '<S193>/Sum of Elements' */
  1.0F,                                /* '<S193>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S193>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S193>/Switch' */

  { 0.0F, 1.0F },                      /* '<S193>/Divide' */
  1.0F,                                /* '<S190>/Square' */
  0.785398185F,                        /* '<S190>/Multiply' */
  -0.785398185F,                       /* '<S190>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S178>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S246>/Vector Concatenate3' */
  1U,                                  /* '<S21>/Data Type Conversion' */
  13U,                                 /* '<S21>/Data Type Conversion1' */
  3U,                                  /* '<S26>/Data Type Conversion' */
  11U,                                 /* '<S26>/Data Type Conversion1' */
  5U,                                  /* '<S26>/Data Type Conversion2' */
  3U,                                  /* '<S25>/Data Type Conversion1' */
  10U,                                 /* '<S25>/Data Type Conversion2' */
  4U,                                  /* '<S25>/Data Type Conversion3' */
  3U,                                  /* '<S27>/Data Type Conversion' */
  9U,                                  /* '<S27>/Data Type Conversion1' */
  3U,                                  /* '<S27>/Data Type Conversion2' */
  3U,                                  /* '<S24>/Data Type Conversion' */
  8U,                                  /* '<S24>/Data Type Conversion1' */
  2U,                                  /* '<S24>/Data Type Conversion2' */
  1U,                                  /* '<S128>/Data Type Conversion' */
  5U,                                  /* '<S128>/Data Type Conversion1' */
  1U,                                  /* '<S129>/Data Type Conversion' */
  4U,                                  /* '<S129>/Data Type Conversion1' */
  3U,                                  /* '<S131>/Data Type Conversion' */
  7U,                                  /* '<S131>/Data Type Conversion1' */
  5U,                                  /* '<S131>/Data Type Conversion2' */
  3U,                                  /* '<S133>/Data Type Conversion' */
  16U,                                 /* '<S133>/Data Type Conversion1' */
  5U,                                  /* '<S133>/Data Type Conversion2' */
  3U,                                  /* '<S132>/Data Type Conversion' */
  17U,                                 /* '<S132>/Data Type Conversion1' */
  5U,                                  /* '<S132>/Data Type Conversion2' */
  3U,                                  /* '<S134>/Data Type Conversion' */
  3U,                                  /* '<S134>/Data Type Conversion1' */
  5U,                                  /* '<S134>/Data Type Conversion2' */
  2U,                                  /* '<S17>/Data Type Conversion2' */
  2U,                                  /* '<S17>/Data Type Conversion1' */

  /* Start of '<S15>/Unknown' */
  {
    1U,                                /* '<S23>/Data Type Conversion' */
    1U                                 /* '<S23>/Data Type Conversion1' */
  }
  ,

  /* End of '<S15>/Unknown' */

  /* Start of '<S19>/Unknown' */
  {
    1U,                                /* '<S28>/Data Type Conversion' */
    1U                                 /* '<S28>/Data Type Conversion1' */
  }
  ,

  /* End of '<S19>/Unknown' */

  /* Start of '<S91>/Move Control' */
  {
    0.00250000018F,                    /* '<S102>/Square' */
    0.14709F,                          /* '<S102>/Multiply' */
    -58.836F                           /* '<S102>/Gain4' */
  }
  ,

  /* End of '<S91>/Move Control' */

  /* Start of '<S91>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S98>/Vector Concatenate3' */
  }
  ,

  /* End of '<S91>/Hold Control' */

  /* Start of '<S78>/Move Control' */
  {
    0.0004F,                           /* '<S88>/Square' */
    0.00628318498F,                    /* '<S88>/Multiply' */
    -15.707963F                        /* '<S88>/Gain4' */
  }
  ,

  /* End of '<S78>/Move Control' */

  /* Start of '<S67>/Move Control' */
  {
    0.00250000018F,                    /* '<S75>/Square' */
    0.196120009F,                      /* '<S75>/Multiply' */
    -78.448F                           /* '<S75>/Gain4' */
  }
  ,

  /* End of '<S67>/Move Control' */

  /* Start of '<S51>/Move Control' */
  {
    0.0004F,                           /* '<S61>/Square' */
    0.00628318498F,                    /* '<S61>/Multiply' */
    -15.707963F                        /* '<S61>/Gain4' */
  }
  ,

  /* End of '<S51>/Move Control' */

  /* Start of '<S34>/Move Control' */
  {
    0.00250000018F,                    /* '<S42>/Square' */
    0.196120009F,                      /* '<S42>/Multiply' */
    -78.448F                           /* '<S42>/Gain4' */
  }
  ,

  /* End of '<S34>/Move Control' */

  /* Start of '<S115>/Move Control' */
  {
    0.0004F,                           /* '<S125>/Square' */
    0.00628318498F,                    /* '<S125>/Multiply' */
    -15.707963F                        /* '<S125>/Gain4' */
  }
  ,

  /* End of '<S115>/Move Control' */

  /* Start of '<S20>/Unknown' */
  {
    1U,                                /* '<S130>/Data Type Conversion' */
    1U                                 /* '<S130>/Data Type Conversion1' */
  }
  ,

  /* End of '<S20>/Unknown' */

  /* Start of '<S22>/Unknown' */
  {
    1U,                                /* '<S135>/Data Type Conversion' */
    1U                                 /* '<S135>/Data Type Conversion1' */
  }
  ,

  /* End of '<S22>/Unknown' */

  /* Start of '<S161>/Move Control' */
  {
    0.00250000018F,                    /* '<S172>/Square' */
    0.14709F,                          /* '<S172>/Multiply' */
    -58.836F                           /* '<S172>/Gain4' */
  }
  ,

  /* End of '<S161>/Move Control' */

  /* Start of '<S161>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S168>/Vector Concatenate3' */
  }
  ,

  /* End of '<S161>/Hold Control' */

  /* Start of '<S149>/Move Control' */
  {
    0.0004F,                           /* '<S159>/Square' */
    0.00628318498F,                    /* '<S159>/Multiply' */
    -15.707963F                        /* '<S159>/Gain4' */
  }
  ,

  /* End of '<S149>/Move Control' */

  /* Start of '<S139>/Move Control' */
  {
    0.00250000018F,                    /* '<S147>/Square' */
    0.196120009F,                      /* '<S147>/Multiply' */
    -78.448F                           /* '<S147>/Gain4' */
  }
  ,

  /* End of '<S139>/Move Control' */

  /* Start of '<S213>/Move Control' */
  {
    0.00250000018F,                    /* '<S224>/Square' */
    0.14709F,                          /* '<S224>/Multiply' */
    -58.836F                           /* '<S224>/Gain4' */
  }
  ,

  /* End of '<S213>/Move Control' */

  /* Start of '<S213>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S220>/Vector Concatenate3' */
  }
  ,

  /* End of '<S213>/Hold Control' */

  /* Start of '<S203>/Move Control' */
  {
    0.00250000018F,                    /* '<S211>/Square' */
    0.196120009F,                      /* '<S211>/Multiply' */
    -78.448F                           /* '<S211>/Gain4' */
  }
  ,

  /* End of '<S203>/Move Control' */

  /* Start of '<S2>/Disarm' */
  {
    1U,                                /* '<S16>/Data Type Conversion' */
    1U                                 /* '<S16>/Data Type Conversion1' */
  }
  /* End of '<S2>/Disarm' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
