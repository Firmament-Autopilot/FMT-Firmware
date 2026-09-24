/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2393
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Sep 24 19:57:53 2026
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
  1.9966471893352524,                  /* '<S340>/Sum' */
  0.0066943799901413165,               /* '<S340>/Multiply3' */
  0.99330562000985867,                 /* '<S340>/Sum4' */
  0.0,                                 /* '<S339>/deg2rad2' */
  0.0,                                 /* '<S342>/SinCos' */
  1.0,                                 /* '<S342>/SinCos' */
  0.00250000018F,                      /* '<S122>/Square' */

  { 0.0F, 0.0F, 1.0F },                /* '<S115>/Vector Concatenate3' */
  0.0016F,                             /* '<S69>/Square' */
  0.0016F,                             /* '<S70>/Square' */
  0.0016F,                             /* '<S136>/Square' */
  0.0016F,                             /* '<S137>/Square' */

  { 0.0F, 0.0F, 1.0F },                /* '<S241>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S191>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S171>/Math Function' */
  1.0F,                                /* '<S171>/Sum of Elements' */
  1.0F,                                /* '<S171>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S171>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S171>/Switch' */

  { 0.0F, 1.0F },                      /* '<S171>/Divide' */
  0.616850317F,                        /* '<S167>/Square' */
  0.645964146F,                        /* '<S167>/Multiply' */
  -1.04719758F,                        /* '<S167>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S322>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S326>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S334>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S331>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S330>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S257>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S259>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S356>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S358>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S491>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S427>/Math Function' */
  1.0F,                                /* '<S427>/Sum of Elements' */
  1.0F,                                /* '<S427>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S427>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S427>/Switch' */

  { 0.0F, 1.0F },                      /* '<S427>/Divide' */
  0.616850317F,                        /* '<S423>/Square' */
  0.645964146F,                        /* '<S423>/Multiply' */
  -1.04719758F,                        /* '<S423>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S410>/Vector Concatenate3' */
  0.122499995F,                        /* '<S406>/Square' */
  1.20123494F,                         /* '<S406>/Multiply' */
  -9.806F,                             /* '<S406>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S505>/Vector Concatenate3' */
  0.122499995F,                        /* '<S501>/Square' */
  1.20123494F,                         /* '<S501>/Multiply' */
  -9.806F,                             /* '<S501>/Gain4' */
  1U,                                  /* '<S38>/Data Type Conversion' */
  12U,                                 /* '<S38>/Data Type Conversion1' */
  3U,                                  /* '<S43>/Data Type Conversion' */
  10U,                                 /* '<S43>/Data Type Conversion1' */
  5U,                                  /* '<S43>/Data Type Conversion2' */
  3U,                                  /* '<S42>/Data Type Conversion1' */
  9U,                                  /* '<S42>/Data Type Conversion2' */
  4U,                                  /* '<S42>/Data Type Conversion3' */
  3U,                                  /* '<S44>/Data Type Conversion' */
  8U,                                  /* '<S44>/Data Type Conversion1' */
  3U,                                  /* '<S44>/Data Type Conversion2' */
  3U,                                  /* '<S41>/Data Type Conversion' */
  7U,                                  /* '<S41>/Data Type Conversion1' */
  2U,                                  /* '<S41>/Data Type Conversion2' */
  3U,                                  /* '<S154>/Data Type Conversion' */
  4U,                                  /* '<S154>/Data Type Conversion1' */
  5U,                                  /* '<S154>/Data Type Conversion2' */
  3U,                                  /* '<S151>/Data Type Conversion' */
  3U,                                  /* '<S151>/Data Type Conversion1' */
  6U,                                  /* '<S151>/Data Type Conversion2' */
  3U,                                  /* '<S359>/Data Type Conversion' */
  6U,                                  /* '<S359>/Data Type Conversion1' */
  5U,                                  /* '<S359>/Data Type Conversion2' */
  3U,                                  /* '<S361>/Data Type Conversion' */
  16U,                                 /* '<S361>/Data Type Conversion1' */
  5U,                                  /* '<S361>/Data Type Conversion2' */
  3U,                                  /* '<S360>/Data Type Conversion' */
  15U,                                 /* '<S360>/Data Type Conversion1' */
  5U,                                  /* '<S360>/Data Type Conversion2' */
  3U,                                  /* '<S362>/Data Type Conversion' */
  17U,                                 /* '<S362>/Data Type Conversion1' */
  5U,                                  /* '<S362>/Data Type Conversion2' */
  2U,                                  /* '<S35>/Data Type Conversion2' */
  2U,                                  /* '<S35>/Data Type Conversion1' */
  1U,                                  /* '<S34>/Data Type Conversion' */
  1U,                                  /* '<S34>/Data Type Conversion1' */

  /* Start of '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S513>/Sum' */
    0.0066943799901413165,             /* '<S513>/Multiply3' */
    0.99330562000985867                /* '<S513>/Sum4' */
  }
  ,

  /* End of '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */

  /* Start of '<S32>/Unknown' */
  {
    1U,                                /* '<S40>/Data Type Conversion' */
    1U                                 /* '<S40>/Data Type Conversion1' */
  }
  ,

  /* End of '<S32>/Unknown' */

  /* Start of '<S36>/Unknown' */
  {
    1U,                                /* '<S45>/Data Type Conversion' */
    1U                                 /* '<S45>/Data Type Conversion1' */
  }
  ,

  /* End of '<S36>/Unknown' */

  /* Start of '<S97>/Move Control' */
  {
    0.0004F,                           /* '<S106>/Square' */
    0.00628318498F,                    /* '<S106>/Multiply' */
    -15.707963F                        /* '<S106>/Gain4' */
  }
  ,

  /* End of '<S97>/Move Control' */

  /* Start of '<S71>/Move Control' */
  {
    0.0004F,                           /* '<S80>/Square' */
    0.00628318498F,                    /* '<S80>/Multiply' */
    -15.707963F                        /* '<S80>/Gain4' */
  }
  ,

  /* End of '<S71>/Move Control' */

  /* Start of '<S138>/Move Control' */
  {
    0.0004F,                           /* '<S147>/Square' */
    0.00628318498F,                    /* '<S147>/Multiply' */
    -15.707963F                        /* '<S147>/Gain4' */
  }
  ,

  /* End of '<S138>/Move Control' */

  /* Start of '<S37>/Unknown' */
  {
    1U,                                /* '<S152>/Data Type Conversion' */
    1U                                 /* '<S152>/Data Type Conversion1' */
  }
  ,

  /* End of '<S37>/Unknown' */

  /* Start of '<S205>/Move Control' */
  {
    0.00250000018F,                    /* '<S216>/Square' */
    0.14709F,                          /* '<S216>/Multiply' */
    -58.836F                           /* '<S216>/Gain4' */
  }
  ,

  /* End of '<S205>/Move Control' */

  /* Start of '<S205>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S212>/Vector Concatenate3' */
  }
  ,

  /* End of '<S205>/Hold Control' */

  /* Start of '<S195>/Move Control' */
  {
    0.00250000018F,                    /* '<S203>/Square' */
    0.196120009F,                      /* '<S203>/Multiply' */
    -78.448F                           /* '<S203>/Gain4' */
  }
  ,

  /* End of '<S195>/Move Control' */

  /* Start of '<S39>/Unknown' */
  {
    1U,                                /* '<S363>/Data Type Conversion' */
    1U                                 /* '<S363>/Data Type Conversion1' */
  }
  ,

  /* End of '<S39>/Unknown' */

  /* Start of '<S389>/Move Control' */
  {
    0.00250000018F,                    /* '<S400>/Square' */
    0.14709F,                          /* '<S400>/Multiply' */
    -58.836F                           /* '<S400>/Gain4' */
  }
  ,

  /* End of '<S389>/Move Control' */

  /* Start of '<S389>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S396>/Vector Concatenate3' */
  }
  ,

  /* End of '<S389>/Hold Control' */

  /* Start of '<S377>/Move Control' */
  {
    0.0004F,                           /* '<S387>/Square' */
    0.00628318498F,                    /* '<S387>/Multiply' */
    -15.707963F                        /* '<S387>/Gain4' */
  }
  ,

  /* End of '<S377>/Move Control' */

  /* Start of '<S367>/Move Control' */
  {
    0.00250000018F,                    /* '<S375>/Square' */
    0.196120009F,                      /* '<S375>/Multiply' */
    -78.448F                           /* '<S375>/Gain4' */
  }
  ,

  /* End of '<S367>/Move Control' */

  /* Start of '<S455>/Move Control' */
  {
    0.00250000018F,                    /* '<S466>/Square' */
    0.14709F,                          /* '<S466>/Multiply' */
    -58.836F                           /* '<S466>/Gain4' */
  }
  ,

  /* End of '<S455>/Move Control' */

  /* Start of '<S455>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S462>/Vector Concatenate3' */
  }
  ,

  /* End of '<S455>/Hold Control' */

  /* Start of '<S445>/Move Control' */
  {
    0.00250000018F,                    /* '<S453>/Square' */
    0.196120009F,                      /* '<S453>/Multiply' */
    -78.448F                           /* '<S453>/Gain4' */
  }
  /* End of '<S445>/Move Control' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
