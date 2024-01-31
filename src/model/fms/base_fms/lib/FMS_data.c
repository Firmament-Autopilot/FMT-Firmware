/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2104
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Jan 31 09:13:54 2024
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
  1.9966471893352524,                  /* '<S314>/Sum' */
  0.0066943799901413165,               /* '<S314>/Multiply3' */
  0.99330562000985867,                 /* '<S314>/Sum4' */
  0.0,                                 /* '<S313>/deg2rad2' */
  0.0,                                 /* '<S316>/SinCos' */
  1.0,                                 /* '<S316>/SinCos' */
  0.0016F,                             /* '<S66>/Square' */
  0.0201061927F,                       /* '<S66>/Multiply' */
  -12.566371F,                         /* '<S66>/Gain4' */
  0.0016F,                             /* '<S65>/Square' */
  0.0201061927F,                       /* '<S65>/Multiply' */
  -12.566371F,                         /* '<S65>/Gain4' */
  0.0016F,                             /* '<S131>/Square' */
  0.0201061927F,                       /* '<S131>/Multiply' */
  -12.566371F,                         /* '<S131>/Gain4' */
  0.0016F,                             /* '<S130>/Square' */
  0.0201061927F,                       /* '<S130>/Multiply' */
  -12.566371F,                         /* '<S130>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S226>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S166>/Math Function' */
  1.0F,                                /* '<S166>/Sum of Elements' */
  1.0F,                                /* '<S166>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S166>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S166>/Switch' */

  { 0.0F, 1.0F },                      /* '<S166>/Divide' */
  0.616850317F,                        /* '<S162>/Square' */
  0.645964146F,                        /* '<S162>/Multiply' */
  -1.04719758F,                        /* '<S162>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S307>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S308>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S304>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S300>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S238>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S240>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S329>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S331>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S499>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S401>/Math Function' */
  1.0F,                                /* '<S401>/Sum of Elements' */
  1.0F,                                /* '<S401>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S401>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S401>/Switch' */

  { 0.0F, 1.0F },                      /* '<S401>/Divide' */
  0.616850317F,                        /* '<S397>/Square' */
  0.645964146F,                        /* '<S397>/Multiply' */
  -1.04719758F,                        /* '<S397>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S383>/Vector Concatenate3' */
  0.122499995F,                        /* '<S379>/Square' */
  1.20123494F,                         /* '<S379>/Multiply' */
  -9.806F,                             /* '<S379>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S510>/Vector Concatenate3' */
  0.122499995F,                        /* '<S506>/Square' */
  1.20123494F,                         /* '<S506>/Multiply' */
  -9.806F,                             /* '<S506>/Gain4' */
  1U,                                  /* '<S36>/Data Type Conversion' */
  12U,                                 /* '<S36>/Data Type Conversion1' */
  3U,                                  /* '<S41>/Data Type Conversion' */
  10U,                                 /* '<S41>/Data Type Conversion1' */
  5U,                                  /* '<S41>/Data Type Conversion2' */
  3U,                                  /* '<S40>/Data Type Conversion1' */
  9U,                                  /* '<S40>/Data Type Conversion2' */
  4U,                                  /* '<S40>/Data Type Conversion3' */
  3U,                                  /* '<S42>/Data Type Conversion' */
  8U,                                  /* '<S42>/Data Type Conversion1' */
  3U,                                  /* '<S42>/Data Type Conversion2' */
  3U,                                  /* '<S39>/Data Type Conversion' */
  7U,                                  /* '<S39>/Data Type Conversion1' */
  2U,                                  /* '<S39>/Data Type Conversion2' */
  3U,                                  /* '<S149>/Data Type Conversion' */
  4U,                                  /* '<S149>/Data Type Conversion1' */
  5U,                                  /* '<S149>/Data Type Conversion2' */
  3U,                                  /* '<S146>/Data Type Conversion' */
  3U,                                  /* '<S146>/Data Type Conversion1' */
  6U,                                  /* '<S146>/Data Type Conversion2' */
  3U,                                  /* '<S332>/Data Type Conversion' */
  6U,                                  /* '<S332>/Data Type Conversion1' */
  5U,                                  /* '<S332>/Data Type Conversion2' */
  3U,                                  /* '<S334>/Data Type Conversion' */
  16U,                                 /* '<S334>/Data Type Conversion1' */
  5U,                                  /* '<S334>/Data Type Conversion2' */
  3U,                                  /* '<S333>/Data Type Conversion' */
  15U,                                 /* '<S333>/Data Type Conversion1' */
  5U,                                  /* '<S333>/Data Type Conversion2' */
  3U,                                  /* '<S335>/Data Type Conversion' */
  17U,                                 /* '<S335>/Data Type Conversion1' */
  5U,                                  /* '<S335>/Data Type Conversion2' */
  2U,                                  /* '<S33>/Data Type Conversion2' */
  2U,                                  /* '<S33>/Data Type Conversion1' */
  1U,                                  /* '<S32>/Data Type Conversion' */
  1U,                                  /* '<S32>/Data Type Conversion1' */

  /* Start of '<S5>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S516>/Sum' */
    0.0066943799901413165,             /* '<S516>/Multiply3' */
    0.99330562000985867                /* '<S516>/Sum4' */
  }
  ,

  /* End of '<S5>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */

  /* Start of '<S30>/Unknown' */
  {
    1U,                                /* '<S38>/Data Type Conversion' */
    1U                                 /* '<S38>/Data Type Conversion1' */
  }
  ,

  /* End of '<S30>/Unknown' */

  /* Start of '<S34>/Unknown' */
  {
    1U,                                /* '<S43>/Data Type Conversion' */
    1U                                 /* '<S43>/Data Type Conversion1' */
  }
  ,

  /* End of '<S34>/Unknown' */

  /* Start of '<S108>/Move Control' */
  {
    0.00250000018F,                    /* '<S119>/Square' */
    0.14709F,                          /* '<S119>/Multiply' */
    -58.836F                           /* '<S119>/Gain4' */
  }
  ,

  /* End of '<S108>/Move Control' */

  /* Start of '<S108>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S115>/Vector Concatenate3' */
  }
  ,

  /* End of '<S108>/Hold Control' */

  /* Start of '<S95>/Move Control' */
  {
    0.0004F,                           /* '<S105>/Square' */
    0.00628318498F,                    /* '<S105>/Multiply' */
    -15.707963F                        /* '<S105>/Gain4' */
  }
  ,

  /* End of '<S95>/Move Control' */

  /* Start of '<S67>/Move Control' */
  {
    0.0004F,                           /* '<S77>/Square' */
    0.00628318498F,                    /* '<S77>/Multiply' */
    -15.707963F                        /* '<S77>/Gain4' */
  }
  ,

  /* End of '<S67>/Move Control' */

  /* Start of '<S132>/Move Control' */
  {
    0.0004F,                           /* '<S142>/Square' */
    0.00628318498F,                    /* '<S142>/Multiply' */
    -15.707963F                        /* '<S142>/Gain4' */
  }
  ,

  /* End of '<S132>/Move Control' */

  /* Start of '<S35>/Unknown' */
  {
    1U,                                /* '<S147>/Data Type Conversion' */
    1U                                 /* '<S147>/Data Type Conversion1' */
  }
  ,

  /* End of '<S35>/Unknown' */

  /* Start of '<S196>/Move Control' */
  {
    0.00250000018F,                    /* '<S207>/Square' */
    0.14709F,                          /* '<S207>/Multiply' */
    -58.836F                           /* '<S207>/Gain4' */
  }
  ,

  /* End of '<S196>/Move Control' */

  /* Start of '<S196>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S203>/Vector Concatenate3' */
  }
  ,

  /* End of '<S196>/Hold Control' */

  /* Start of '<S186>/Move Control' */
  {
    0.00250000018F,                    /* '<S194>/Square' */
    0.196120009F,                      /* '<S194>/Multiply' */
    -78.448F                           /* '<S194>/Gain4' */
  }
  ,

  /* End of '<S186>/Move Control' */

  /* Start of '<S37>/Unknown' */
  {
    1U,                                /* '<S336>/Data Type Conversion' */
    1U                                 /* '<S336>/Data Type Conversion1' */
  }
  ,

  /* End of '<S37>/Unknown' */

  /* Start of '<S362>/Move Control' */
  {
    0.00250000018F,                    /* '<S373>/Square' */
    0.14709F,                          /* '<S373>/Multiply' */
    -58.836F                           /* '<S373>/Gain4' */
  }
  ,

  /* End of '<S362>/Move Control' */

  /* Start of '<S362>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S369>/Vector Concatenate3' */
  }
  ,

  /* End of '<S362>/Hold Control' */

  /* Start of '<S350>/Move Control' */
  {
    0.0004F,                           /* '<S360>/Square' */
    0.00628318498F,                    /* '<S360>/Multiply' */
    -15.707963F                        /* '<S360>/Gain4' */
  }
  ,

  /* End of '<S350>/Move Control' */

  /* Start of '<S340>/Move Control' */
  {
    0.00250000018F,                    /* '<S348>/Square' */
    0.196120009F,                      /* '<S348>/Multiply' */
    -78.448F                           /* '<S348>/Gain4' */
  }
  ,

  /* End of '<S340>/Move Control' */

  /* Start of '<S469>/Move Control' */
  {
    0.00250000018F,                    /* '<S480>/Square' */
    0.14709F,                          /* '<S480>/Multiply' */
    -58.836F                           /* '<S480>/Gain4' */
  }
  ,

  /* End of '<S469>/Move Control' */

  /* Start of '<S469>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S476>/Vector Concatenate3' */
  }
  ,

  /* End of '<S469>/Hold Control' */

  /* Start of '<S459>/Move Control' */
  {
    0.00250000018F,                    /* '<S467>/Square' */
    0.196120009F,                      /* '<S467>/Multiply' */
    -78.448F                           /* '<S467>/Gain4' */
  }
  /* End of '<S459>/Move Control' */
};

/* Constant parameters (default storage) */
const ConstP_FMS_T FMS_ConstP = {
  /* Pooled Parameter (Expression: [4,4,2])
   * Referenced by:
   *   '<S293>/Saturation1'
   *   '<S295>/Saturation'
   *   '<S296>/Saturation1'
   */
  { 4.0F, 4.0F, 2.0F },

  /* Pooled Parameter (Expression: [-4,-4,-2])
   * Referenced by:
   *   '<S293>/Saturation1'
   *   '<S295>/Saturation'
   *   '<S296>/Saturation1'
   */
  { -4.0F, -4.0F, -2.0F }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
