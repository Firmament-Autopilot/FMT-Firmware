/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2062
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Nov 13 11:33:44 2023
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
  1.9966471893352524,                  /* '<S308>/Sum' */
  0.0066943799901413165,               /* '<S308>/Multiply3' */
  0.99330562000985867,                 /* '<S308>/Sum4' */
  0.0,                                 /* '<S307>/deg2rad2' */
  0.0,                                 /* '<S310>/SinCos' */
  1.0,                                 /* '<S310>/SinCos' */
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

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S166>/Math Function' */
  1.0F,                                /* '<S166>/Sum of Elements' */
  1.0F,                                /* '<S166>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S166>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S166>/Switch' */

  { 0.0F, 1.0F },                      /* '<S166>/Divide' */

  { 0.0F, 0.0F, 1.0F },                /* '<S221>/Vector Concatenate3' */
  0.616850317F,                        /* '<S162>/Square' */
  0.645964146F,                        /* '<S162>/Multiply' */
  -1.04719758F,                        /* '<S162>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S301>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S302>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S298>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S294>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S232>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S234>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S323>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S325>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S394>/Math Function' */
  1.0F,                                /* '<S394>/Sum of Elements' */
  1.0F,                                /* '<S394>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S394>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S394>/Switch' */

  { 0.0F, 1.0F },                      /* '<S394>/Divide' */

  { 0.0F, 0.0F, 1.0F },                /* '<S445>/Vector Concatenate3' */
  0.616850317F,                        /* '<S390>/Square' */
  0.645964146F,                        /* '<S390>/Multiply' */
  -1.04719758F,                        /* '<S390>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S377>/Vector Concatenate3' */
  0.122499995F,                        /* '<S373>/Square' */
  1.20123494F,                         /* '<S373>/Multiply' */
  -9.806F,                             /* '<S373>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S455>/Vector Concatenate3' */
  0.122499995F,                        /* '<S451>/Square' */
  1.20123494F,                         /* '<S451>/Multiply' */
  -9.806F,                             /* '<S451>/Gain4' */
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
  3U,                                  /* '<S326>/Data Type Conversion' */
  6U,                                  /* '<S326>/Data Type Conversion1' */
  5U,                                  /* '<S326>/Data Type Conversion2' */
  3U,                                  /* '<S328>/Data Type Conversion' */
  16U,                                 /* '<S328>/Data Type Conversion1' */
  5U,                                  /* '<S328>/Data Type Conversion2' */
  3U,                                  /* '<S327>/Data Type Conversion' */
  15U,                                 /* '<S327>/Data Type Conversion1' */
  5U,                                  /* '<S327>/Data Type Conversion2' */
  3U,                                  /* '<S329>/Data Type Conversion' */
  17U,                                 /* '<S329>/Data Type Conversion1' */
  5U,                                  /* '<S329>/Data Type Conversion2' */
  2U,                                  /* '<S33>/Data Type Conversion2' */
  2U,                                  /* '<S33>/Data Type Conversion1' */
  1U,                                  /* '<S32>/Data Type Conversion' */
  1U,                                  /* '<S32>/Data Type Conversion1' */

  /* Start of '<S5>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S461>/Sum' */
    0.0066943799901413165,             /* '<S461>/Multiply3' */
    0.99330562000985867                /* '<S461>/Sum4' */
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

  /* Start of '<S191>/Move Control' */
  {
    0.00250000018F,                    /* '<S202>/Square' */
    0.14709F,                          /* '<S202>/Multiply' */
    -58.836F                           /* '<S202>/Gain4' */
  }
  ,

  /* End of '<S191>/Move Control' */

  /* Start of '<S191>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S198>/Vector Concatenate3' */
  }
  ,

  /* End of '<S191>/Hold Control' */

  /* Start of '<S181>/Move Control' */
  {
    0.00250000018F,                    /* '<S189>/Square' */
    0.196120009F,                      /* '<S189>/Multiply' */
    -78.448F                           /* '<S189>/Gain4' */
  }
  ,

  /* End of '<S181>/Move Control' */

  /* Start of '<S37>/Unknown' */
  {
    1U,                                /* '<S330>/Data Type Conversion' */
    1U                                 /* '<S330>/Data Type Conversion1' */
  }
  ,

  /* End of '<S37>/Unknown' */

  /* Start of '<S356>/Move Control' */
  {
    0.00250000018F,                    /* '<S367>/Square' */
    0.14709F,                          /* '<S367>/Multiply' */
    -58.836F                           /* '<S367>/Gain4' */
  }
  ,

  /* End of '<S356>/Move Control' */

  /* Start of '<S356>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S363>/Vector Concatenate3' */
  }
  ,

  /* End of '<S356>/Hold Control' */

  /* Start of '<S344>/Move Control' */
  {
    0.0004F,                           /* '<S354>/Square' */
    0.00628318498F,                    /* '<S354>/Multiply' */
    -15.707963F                        /* '<S354>/Gain4' */
  }
  ,

  /* End of '<S344>/Move Control' */

  /* Start of '<S334>/Move Control' */
  {
    0.00250000018F,                    /* '<S342>/Square' */
    0.196120009F,                      /* '<S342>/Multiply' */
    -78.448F                           /* '<S342>/Gain4' */
  }
  ,

  /* End of '<S334>/Move Control' */

  /* Start of '<S415>/Move Control' */
  {
    0.00250000018F,                    /* '<S426>/Square' */
    0.14709F,                          /* '<S426>/Multiply' */
    -58.836F                           /* '<S426>/Gain4' */
  }
  ,

  /* End of '<S415>/Move Control' */

  /* Start of '<S415>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S422>/Vector Concatenate3' */
  }
  ,

  /* End of '<S415>/Hold Control' */

  /* Start of '<S405>/Move Control' */
  {
    0.00250000018F,                    /* '<S413>/Square' */
    0.196120009F,                      /* '<S413>/Multiply' */
    -78.448F                           /* '<S413>/Gain4' */
  }
  /* End of '<S405>/Move Control' */
};

/* Constant parameters (default storage) */
const ConstP_FMS_T FMS_ConstP = {
  /* Pooled Parameter (Expression: [4,4,2])
   * Referenced by:
   *   '<S287>/Saturation1'
   *   '<S289>/Saturation'
   *   '<S290>/Saturation1'
   */
  { 4.0F, 4.0F, 2.0F },

  /* Pooled Parameter (Expression: [-4,-4,-2])
   * Referenced by:
   *   '<S287>/Saturation1'
   *   '<S289>/Saturation'
   *   '<S290>/Saturation1'
   */
  { -4.0F, -4.0F, -2.0F }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
