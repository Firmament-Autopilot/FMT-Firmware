/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1137
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Dec 25 10:36:30 2021
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
  0.0016F,                             /* '<S52>/Square' */
  0.0201061927F,                       /* '<S52>/Multiply' */
  -12.566371F,                         /* '<S52>/Gain4' */
  0.0016F,                             /* '<S53>/Square' */
  0.0201061927F,                       /* '<S53>/Multiply' */
  -12.566371F,                         /* '<S53>/Gain4' */
  0.0016F,                             /* '<S116>/Square' */
  0.0201061927F,                       /* '<S116>/Multiply' */
  -12.566371F,                         /* '<S116>/Gain4' */
  0.0016F,                             /* '<S117>/Square' */
  0.0201061927F,                       /* '<S117>/Multiply' */
  -12.566371F,                         /* '<S117>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S245>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S196>/Math Function' */
  1.0F,                                /* '<S196>/Sum of Elements' */
  1.0F,                                /* '<S196>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S196>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S196>/Switch' */

  { 0.0F, 1.0F },                      /* '<S196>/Divide' */
  1.0F,                                /* '<S193>/Square' */
  0.785398185F,                        /* '<S193>/Multiply' */
  -0.785398185F,                       /* '<S193>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S181>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S249>/Vector Concatenate3' */
  1U,                                  /* '<S24>/Data Type Conversion' */
  13U,                                 /* '<S24>/Data Type Conversion1' */
  3U,                                  /* '<S29>/Data Type Conversion' */
  11U,                                 /* '<S29>/Data Type Conversion1' */
  5U,                                  /* '<S29>/Data Type Conversion2' */
  3U,                                  /* '<S28>/Data Type Conversion1' */
  10U,                                 /* '<S28>/Data Type Conversion2' */
  4U,                                  /* '<S28>/Data Type Conversion3' */
  3U,                                  /* '<S30>/Data Type Conversion' */
  9U,                                  /* '<S30>/Data Type Conversion1' */
  3U,                                  /* '<S30>/Data Type Conversion2' */
  3U,                                  /* '<S27>/Data Type Conversion' */
  8U,                                  /* '<S27>/Data Type Conversion1' */
  2U,                                  /* '<S27>/Data Type Conversion2' */
  1U,                                  /* '<S131>/Data Type Conversion' */
  5U,                                  /* '<S131>/Data Type Conversion1' */
  1U,                                  /* '<S132>/Data Type Conversion' */
  4U,                                  /* '<S132>/Data Type Conversion1' */
  3U,                                  /* '<S134>/Data Type Conversion' */
  7U,                                  /* '<S134>/Data Type Conversion1' */
  5U,                                  /* '<S134>/Data Type Conversion2' */
  3U,                                  /* '<S136>/Data Type Conversion' */
  16U,                                 /* '<S136>/Data Type Conversion1' */
  5U,                                  /* '<S136>/Data Type Conversion2' */
  3U,                                  /* '<S135>/Data Type Conversion' */
  17U,                                 /* '<S135>/Data Type Conversion1' */
  5U,                                  /* '<S135>/Data Type Conversion2' */
  3U,                                  /* '<S137>/Data Type Conversion' */
  3U,                                  /* '<S137>/Data Type Conversion1' */
  5U,                                  /* '<S137>/Data Type Conversion2' */
  2U,                                  /* '<S20>/Data Type Conversion2' */
  2U,                                  /* '<S20>/Data Type Conversion1' */

  /* Start of '<S18>/Unknown' */
  {
    1U,                                /* '<S26>/Data Type Conversion' */
    1U                                 /* '<S26>/Data Type Conversion1' */
  }
  ,

  /* End of '<S18>/Unknown' */

  /* Start of '<S22>/Unknown' */
  {
    1U,                                /* '<S31>/Data Type Conversion' */
    1U                                 /* '<S31>/Data Type Conversion1' */
  }
  ,

  /* End of '<S22>/Unknown' */

  /* Start of '<S94>/Move Control' */
  {
    0.00250000018F,                    /* '<S105>/Square' */
    0.14709F,                          /* '<S105>/Multiply' */
    -58.836F                           /* '<S105>/Gain4' */
  }
  ,

  /* End of '<S94>/Move Control' */

  /* Start of '<S94>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S101>/Vector Concatenate3' */
  }
  ,

  /* End of '<S94>/Hold Control' */

  /* Start of '<S81>/Move Control' */
  {
    0.0004F,                           /* '<S91>/Square' */
    0.00628318498F,                    /* '<S91>/Multiply' */
    -15.707963F                        /* '<S91>/Gain4' */
  }
  ,

  /* End of '<S81>/Move Control' */

  /* Start of '<S70>/Move Control' */
  {
    0.00250000018F,                    /* '<S78>/Square' */
    0.196120009F,                      /* '<S78>/Multiply' */
    -78.448F                           /* '<S78>/Gain4' */
  }
  ,

  /* End of '<S70>/Move Control' */

  /* Start of '<S54>/Move Control' */
  {
    0.0004F,                           /* '<S64>/Square' */
    0.00628318498F,                    /* '<S64>/Multiply' */
    -15.707963F                        /* '<S64>/Gain4' */
  }
  ,

  /* End of '<S54>/Move Control' */

  /* Start of '<S37>/Move Control' */
  {
    0.00250000018F,                    /* '<S45>/Square' */
    0.196120009F,                      /* '<S45>/Multiply' */
    -78.448F                           /* '<S45>/Gain4' */
  }
  ,

  /* End of '<S37>/Move Control' */

  /* Start of '<S118>/Move Control' */
  {
    0.0004F,                           /* '<S128>/Square' */
    0.00628318498F,                    /* '<S128>/Multiply' */
    -15.707963F                        /* '<S128>/Gain4' */
  }
  ,

  /* End of '<S118>/Move Control' */

  /* Start of '<S23>/Unknown' */
  {
    1U,                                /* '<S133>/Data Type Conversion' */
    1U                                 /* '<S133>/Data Type Conversion1' */
  }
  ,

  /* End of '<S23>/Unknown' */

  /* Start of '<S25>/Unknown' */
  {
    1U,                                /* '<S138>/Data Type Conversion' */
    1U                                 /* '<S138>/Data Type Conversion1' */
  }
  ,

  /* End of '<S25>/Unknown' */

  /* Start of '<S164>/Move Control' */
  {
    0.00250000018F,                    /* '<S175>/Square' */
    0.14709F,                          /* '<S175>/Multiply' */
    -58.836F                           /* '<S175>/Gain4' */
  }
  ,

  /* End of '<S164>/Move Control' */

  /* Start of '<S164>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S171>/Vector Concatenate3' */
  }
  ,

  /* End of '<S164>/Hold Control' */

  /* Start of '<S152>/Move Control' */
  {
    0.0004F,                           /* '<S162>/Square' */
    0.00628318498F,                    /* '<S162>/Multiply' */
    -15.707963F                        /* '<S162>/Gain4' */
  }
  ,

  /* End of '<S152>/Move Control' */

  /* Start of '<S142>/Move Control' */
  {
    0.00250000018F,                    /* '<S150>/Square' */
    0.196120009F,                      /* '<S150>/Multiply' */
    -78.448F                           /* '<S150>/Gain4' */
  }
  ,

  /* End of '<S142>/Move Control' */

  /* Start of '<S216>/Move Control' */
  {
    0.00250000018F,                    /* '<S227>/Square' */
    0.14709F,                          /* '<S227>/Multiply' */
    -58.836F                           /* '<S227>/Gain4' */
  }
  ,

  /* End of '<S216>/Move Control' */

  /* Start of '<S216>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S223>/Vector Concatenate3' */
  }
  ,

  /* End of '<S216>/Hold Control' */

  /* Start of '<S206>/Move Control' */
  {
    0.00250000018F,                    /* '<S214>/Square' */
    0.196120009F,                      /* '<S214>/Multiply' */
    -78.448F                           /* '<S214>/Gain4' */
  }
  ,

  /* End of '<S206>/Move Control' */

  /* Start of '<S2>/Disarm' */
  {
    1U,                                /* '<S19>/Data Type Conversion' */
    1U                                 /* '<S19>/Data Type Conversion1' */
  }
  /* End of '<S2>/Disarm' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
