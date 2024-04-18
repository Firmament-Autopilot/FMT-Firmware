/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2122
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Apr 17 17:26:33 2024
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
  1.9966471893352524,                  /* '<S257>/Sum' */
  0.0066943799901413165,               /* '<S257>/Multiply3' */
  0.99330562000985867,                 /* '<S257>/Sum4' */
  0.0,                                 /* '<S256>/deg2rad2' */
  0.0,                                 /* '<S259>/SinCos' */
  1.0,                                 /* '<S259>/SinCos' */
  0.0016F,                             /* '<S62>/Square' */
  0.0201061927F,                       /* '<S62>/Multiply' */
  -12.566371F,                         /* '<S62>/Gain4' */
  0.0016F,                             /* '<S61>/Square' */
  0.0201061927F,                       /* '<S61>/Multiply' */
  -12.566371F,                         /* '<S61>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S169>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S109>/Math Function' */
  1.0F,                                /* '<S109>/Sum of Elements' */
  1.0F,                                /* '<S109>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S109>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S109>/Switch' */

  { 0.0F, 1.0F },                      /* '<S109>/Divide' */
  0.616850317F,                        /* '<S105>/Square' */
  0.645964146F,                        /* '<S105>/Multiply' */
  -1.04719758F,                        /* '<S105>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S250>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S251>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S247>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S243>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S181>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S183>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S272>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S274>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S403>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S343>/Math Function' */
  1.0F,                                /* '<S343>/Sum of Elements' */
  1.0F,                                /* '<S343>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S343>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S343>/Switch' */

  { 0.0F, 1.0F },                      /* '<S343>/Divide' */
  0.616850317F,                        /* '<S339>/Square' */
  0.645964146F,                        /* '<S339>/Multiply' */
  -1.04719758F,                        /* '<S339>/Gain4' */
  0.00250000018F,                      /* '<S384>/Square' */
  0.14709F,                            /* '<S384>/Multiply' */
  -58.836F,                            /* '<S384>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S326>/Vector Concatenate3' */
  0.122499995F,                        /* '<S322>/Square' */
  1.20123494F,                         /* '<S322>/Multiply' */
  -9.806F,                             /* '<S322>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S414>/Vector Concatenate3' */
  0.122499995F,                        /* '<S410>/Square' */
  1.20123494F,                         /* '<S410>/Multiply' */
  -9.806F,                             /* '<S410>/Gain4' */
  1U,                                  /* '<S35>/Data Type Conversion' */
  12U,                                 /* '<S35>/Data Type Conversion1' */
  3U,                                  /* '<S39>/Data Type Conversion' */
  10U,                                 /* '<S39>/Data Type Conversion1' */
  5U,                                  /* '<S39>/Data Type Conversion2' */
  3U,                                  /* '<S38>/Data Type Conversion1' */
  9U,                                  /* '<S38>/Data Type Conversion2' */
  4U,                                  /* '<S38>/Data Type Conversion3' */
  3U,                                  /* '<S40>/Data Type Conversion' */
  8U,                                  /* '<S40>/Data Type Conversion1' */
  3U,                                  /* '<S40>/Data Type Conversion2' */
  3U,                                  /* '<S92>/Data Type Conversion' */
  4U,                                  /* '<S92>/Data Type Conversion1' */
  5U,                                  /* '<S92>/Data Type Conversion2' */
  3U,                                  /* '<S89>/Data Type Conversion' */
  3U,                                  /* '<S89>/Data Type Conversion1' */
  6U,                                  /* '<S89>/Data Type Conversion2' */
  3U,                                  /* '<S275>/Data Type Conversion' */
  6U,                                  /* '<S275>/Data Type Conversion1' */
  5U,                                  /* '<S275>/Data Type Conversion2' */
  3U,                                  /* '<S277>/Data Type Conversion' */
  16U,                                 /* '<S277>/Data Type Conversion1' */
  5U,                                  /* '<S277>/Data Type Conversion2' */
  3U,                                  /* '<S276>/Data Type Conversion' */
  15U,                                 /* '<S276>/Data Type Conversion1' */
  5U,                                  /* '<S276>/Data Type Conversion2' */
  3U,                                  /* '<S278>/Data Type Conversion' */
  17U,                                 /* '<S278>/Data Type Conversion1' */
  5U,                                  /* '<S278>/Data Type Conversion2' */
  2U,                                  /* '<S32>/Data Type Conversion2' */
  2U,                                  /* '<S32>/Data Type Conversion1' */
  1U,                                  /* '<S31>/Data Type Conversion' */
  1U,                                  /* '<S31>/Data Type Conversion1' */

  /* Start of '<S5>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S420>/Sum' */
    0.0066943799901413165,             /* '<S420>/Multiply3' */
    0.99330562000985867                /* '<S420>/Sum4' */
  }
  ,

  /* End of '<S5>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */

  /* Start of '<S29>/Unknown' */
  {
    1U,                                /* '<S37>/Data Type Conversion' */
    1U                                 /* '<S37>/Data Type Conversion1' */
  }
  ,

  /* End of '<S29>/Unknown' */

  /* Start of '<S33>/Unknown' */
  {
    1U,                                /* '<S41>/Data Type Conversion' */
    1U                                 /* '<S41>/Data Type Conversion1' */
  }
  ,

  /* End of '<S33>/Unknown' */

  /* Start of '<S63>/Move Control' */
  {
    0.0004F,                           /* '<S73>/Square' */
    0.00628318498F,                    /* '<S73>/Multiply' */
    -15.707963F                        /* '<S73>/Gain4' */
  }
  ,

  /* End of '<S63>/Move Control' */

  /* Start of '<S34>/Unknown' */
  {
    1U,                                /* '<S90>/Data Type Conversion' */
    1U                                 /* '<S90>/Data Type Conversion1' */
  }
  ,

  /* End of '<S34>/Unknown' */

  /* Start of '<S139>/Move Control' */
  {
    0.00250000018F,                    /* '<S150>/Square' */
    0.14709F,                          /* '<S150>/Multiply' */
    -58.836F                           /* '<S150>/Gain4' */
  }
  ,

  /* End of '<S139>/Move Control' */

  /* Start of '<S139>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S146>/Vector Concatenate3' */
  }
  ,

  /* End of '<S139>/Hold Control' */

  /* Start of '<S129>/Move Control' */
  {
    0.00250000018F,                    /* '<S137>/Square' */
    0.196120009F,                      /* '<S137>/Multiply' */
    -78.448F                           /* '<S137>/Gain4' */
  }
  ,

  /* End of '<S129>/Move Control' */

  /* Start of '<S36>/Unknown' */
  {
    1U,                                /* '<S279>/Data Type Conversion' */
    1U                                 /* '<S279>/Data Type Conversion1' */
  }
  ,

  /* End of '<S36>/Unknown' */

  /* Start of '<S305>/Move Control' */
  {
    0.00250000018F,                    /* '<S316>/Square' */
    0.14709F,                          /* '<S316>/Multiply' */
    -58.836F                           /* '<S316>/Gain4' */
  }
  ,

  /* End of '<S305>/Move Control' */

  /* Start of '<S305>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S312>/Vector Concatenate3' */
  }
  ,

  /* End of '<S305>/Hold Control' */

  /* Start of '<S293>/Move Control' */
  {
    0.0004F,                           /* '<S303>/Square' */
    0.00628318498F,                    /* '<S303>/Multiply' */
    -15.707963F                        /* '<S303>/Gain4' */
  }
  ,

  /* End of '<S293>/Move Control' */

  /* Start of '<S283>/Move Control' */
  {
    0.00250000018F,                    /* '<S291>/Square' */
    0.196120009F,                      /* '<S291>/Multiply' */
    -78.448F                           /* '<S291>/Gain4' */
  }
  ,

  /* End of '<S283>/Move Control' */

  /* Start of '<S373>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S380>/Vector Concatenate3' */
  }
  ,

  /* End of '<S373>/Hold Control' */

  /* Start of '<S363>/Move Control' */
  {
    0.00250000018F,                    /* '<S371>/Square' */
    0.196120009F,                      /* '<S371>/Multiply' */
    -78.448F                           /* '<S371>/Gain4' */
  }
  /* End of '<S363>/Move Control' */
};

/* Constant parameters (default storage) */
const ConstP_FMS_T FMS_ConstP = {
  /* Pooled Parameter (Expression: [4,4,2])
   * Referenced by:
   *   '<S236>/Saturation1'
   *   '<S238>/Saturation'
   *   '<S239>/Saturation1'
   */
  { 4.0F, 4.0F, 2.0F },

  /* Pooled Parameter (Expression: [-4,-4,-2])
   * Referenced by:
   *   '<S236>/Saturation1'
   *   '<S238>/Saturation'
   *   '<S239>/Saturation1'
   */
  { -4.0F, -4.0F, -2.0F }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
