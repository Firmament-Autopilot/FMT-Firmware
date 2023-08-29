/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2022
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Aug 29 14:19:44 2023
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
  1.9966471893352524,                  /* '<S307>/Sum' */
  0.0066943799901413165,               /* '<S307>/Multiply3' */
  0.99330562000985867,                 /* '<S307>/Sum4' */
  0.0,                                 /* '<S306>/deg2rad2' */
  0.0,                                 /* '<S309>/SinCos' */
  1.0,                                 /* '<S309>/SinCos' */
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

  { 0.0F, 0.0F, 1.0F },                /* '<S220>/Vector Concatenate3' */

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

  { 0.0F, 0.0F, 1.0F },                /* '<S300>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S301>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S297>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S293>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S231>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S233>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S322>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S324>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S443>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S393>/Math Function' */
  1.0F,                                /* '<S393>/Sum of Elements' */
  1.0F,                                /* '<S393>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S393>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S393>/Switch' */

  { 0.0F, 1.0F },                      /* '<S393>/Divide' */
  0.616850317F,                        /* '<S389>/Square' */
  0.645964146F,                        /* '<S389>/Multiply' */
  -1.04719758F,                        /* '<S389>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S376>/Vector Concatenate3' */
  0.122499995F,                        /* '<S372>/Square' */
  1.20123494F,                         /* '<S372>/Multiply' */
  -9.806F,                             /* '<S372>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S453>/Vector Concatenate3' */
  0.122499995F,                        /* '<S449>/Square' */
  1.20123494F,                         /* '<S449>/Multiply' */
  -9.806F,                             /* '<S449>/Gain4' */
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
  3U,                                  /* '<S325>/Data Type Conversion' */
  6U,                                  /* '<S325>/Data Type Conversion1' */
  5U,                                  /* '<S325>/Data Type Conversion2' */
  3U,                                  /* '<S327>/Data Type Conversion' */
  16U,                                 /* '<S327>/Data Type Conversion1' */
  5U,                                  /* '<S327>/Data Type Conversion2' */
  3U,                                  /* '<S326>/Data Type Conversion' */
  15U,                                 /* '<S326>/Data Type Conversion1' */
  5U,                                  /* '<S326>/Data Type Conversion2' */
  3U,                                  /* '<S328>/Data Type Conversion' */
  17U,                                 /* '<S328>/Data Type Conversion1' */
  5U,                                  /* '<S328>/Data Type Conversion2' */
  2U,                                  /* '<S33>/Data Type Conversion2' */
  2U,                                  /* '<S33>/Data Type Conversion1' */
  1U,                                  /* '<S32>/Data Type Conversion' */
  1U,                                  /* '<S32>/Data Type Conversion1' */

  /* Start of '<S5>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S459>/Sum' */
    0.0066943799901413165,             /* '<S459>/Multiply3' */
    0.99330562000985867                /* '<S459>/Sum4' */
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

  /* Start of '<S190>/Move Control' */
  {
    0.00250000018F,                    /* '<S201>/Square' */
    0.14709F,                          /* '<S201>/Multiply' */
    -58.836F                           /* '<S201>/Gain4' */
  }
  ,

  /* End of '<S190>/Move Control' */

  /* Start of '<S190>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S197>/Vector Concatenate3' */
  }
  ,

  /* End of '<S190>/Hold Control' */

  /* Start of '<S180>/Move Control' */
  {
    0.00250000018F,                    /* '<S188>/Square' */
    0.196120009F,                      /* '<S188>/Multiply' */
    -78.448F                           /* '<S188>/Gain4' */
  }
  ,

  /* End of '<S180>/Move Control' */

  /* Start of '<S37>/Unknown' */
  {
    1U,                                /* '<S329>/Data Type Conversion' */
    1U                                 /* '<S329>/Data Type Conversion1' */
  }
  ,

  /* End of '<S37>/Unknown' */

  /* Start of '<S355>/Move Control' */
  {
    0.00250000018F,                    /* '<S366>/Square' */
    0.14709F,                          /* '<S366>/Multiply' */
    -58.836F                           /* '<S366>/Gain4' */
  }
  ,

  /* End of '<S355>/Move Control' */

  /* Start of '<S355>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S362>/Vector Concatenate3' */
  }
  ,

  /* End of '<S355>/Hold Control' */

  /* Start of '<S343>/Move Control' */
  {
    0.0004F,                           /* '<S353>/Square' */
    0.00628318498F,                    /* '<S353>/Multiply' */
    -15.707963F                        /* '<S353>/Gain4' */
  }
  ,

  /* End of '<S343>/Move Control' */

  /* Start of '<S333>/Move Control' */
  {
    0.00250000018F,                    /* '<S341>/Square' */
    0.196120009F,                      /* '<S341>/Multiply' */
    -78.448F                           /* '<S341>/Gain4' */
  }
  ,

  /* End of '<S333>/Move Control' */

  /* Start of '<S413>/Move Control' */
  {
    0.00250000018F,                    /* '<S424>/Square' */
    0.14709F,                          /* '<S424>/Multiply' */
    -58.836F                           /* '<S424>/Gain4' */
  }
  ,

  /* End of '<S413>/Move Control' */

  /* Start of '<S413>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S420>/Vector Concatenate3' */
  }
  ,

  /* End of '<S413>/Hold Control' */

  /* Start of '<S403>/Move Control' */
  {
    0.00250000018F,                    /* '<S411>/Square' */
    0.196120009F,                      /* '<S411>/Multiply' */
    -78.448F                           /* '<S411>/Gain4' */
  }
  /* End of '<S403>/Move Control' */
};

/* Constant parameters (default storage) */
const ConstP_FMS_T FMS_ConstP = {
  /* Pooled Parameter (Expression: [4,4,2])
   * Referenced by:
   *   '<S286>/Saturation1'
   *   '<S288>/Saturation'
   *   '<S289>/Saturation1'
   */
  { 4.0F, 4.0F, 2.0F },

  /* Pooled Parameter (Expression: [-4,-4,-2])
   * Referenced by:
   *   '<S286>/Saturation1'
   *   '<S288>/Saturation'
   *   '<S289>/Saturation1'
   */
  { -4.0F, -4.0F, -2.0F }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
