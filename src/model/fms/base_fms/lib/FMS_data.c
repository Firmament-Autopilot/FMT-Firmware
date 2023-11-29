/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2077
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Nov 29 09:57:09 2023
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
  1.9966471893352524,                  /* '<S311>/Sum' */
  0.0066943799901413165,               /* '<S311>/Multiply3' */
  0.99330562000985867,                 /* '<S311>/Sum4' */
  0.0,                                 /* '<S310>/deg2rad2' */
  0.0,                                 /* '<S313>/SinCos' */
  1.0,                                 /* '<S313>/SinCos' */
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

  { 0.0F, 0.0F, 1.0F },                /* '<S223>/Vector Concatenate3' */

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

  { 0.0F, 0.0F, 1.0F },                /* '<S304>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S305>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S301>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S297>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S235>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S237>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S326>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S328>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S450>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S397>/Math Function' */
  1.0F,                                /* '<S397>/Sum of Elements' */
  1.0F,                                /* '<S397>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S397>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S397>/Switch' */

  { 0.0F, 1.0F },                      /* '<S397>/Divide' */
  0.616850317F,                        /* '<S393>/Square' */
  0.645964146F,                        /* '<S393>/Multiply' */
  -1.04719758F,                        /* '<S393>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S380>/Vector Concatenate3' */
  0.122499995F,                        /* '<S376>/Square' */
  1.20123494F,                         /* '<S376>/Multiply' */
  -9.806F,                             /* '<S376>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S461>/Vector Concatenate3' */
  0.122499995F,                        /* '<S457>/Square' */
  1.20123494F,                         /* '<S457>/Multiply' */
  -9.806F,                             /* '<S457>/Gain4' */
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
  3U,                                  /* '<S329>/Data Type Conversion' */
  6U,                                  /* '<S329>/Data Type Conversion1' */
  5U,                                  /* '<S329>/Data Type Conversion2' */
  3U,                                  /* '<S331>/Data Type Conversion' */
  16U,                                 /* '<S331>/Data Type Conversion1' */
  5U,                                  /* '<S331>/Data Type Conversion2' */
  3U,                                  /* '<S330>/Data Type Conversion' */
  15U,                                 /* '<S330>/Data Type Conversion1' */
  5U,                                  /* '<S330>/Data Type Conversion2' */
  3U,                                  /* '<S332>/Data Type Conversion' */
  17U,                                 /* '<S332>/Data Type Conversion1' */
  5U,                                  /* '<S332>/Data Type Conversion2' */
  2U,                                  /* '<S33>/Data Type Conversion2' */
  2U,                                  /* '<S33>/Data Type Conversion1' */
  1U,                                  /* '<S32>/Data Type Conversion' */
  1U,                                  /* '<S32>/Data Type Conversion1' */

  /* Start of '<S5>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S467>/Sum' */
    0.0066943799901413165,             /* '<S467>/Multiply3' */
    0.99330562000985867                /* '<S467>/Sum4' */
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

  /* Start of '<S193>/Move Control' */
  {
    0.00250000018F,                    /* '<S204>/Square' */
    0.14709F,                          /* '<S204>/Multiply' */
    -58.836F                           /* '<S204>/Gain4' */
  }
  ,

  /* End of '<S193>/Move Control' */

  /* Start of '<S193>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S200>/Vector Concatenate3' */
  }
  ,

  /* End of '<S193>/Hold Control' */

  /* Start of '<S183>/Move Control' */
  {
    0.00250000018F,                    /* '<S191>/Square' */
    0.196120009F,                      /* '<S191>/Multiply' */
    -78.448F                           /* '<S191>/Gain4' */
  }
  ,

  /* End of '<S183>/Move Control' */

  /* Start of '<S37>/Unknown' */
  {
    1U,                                /* '<S333>/Data Type Conversion' */
    1U                                 /* '<S333>/Data Type Conversion1' */
  }
  ,

  /* End of '<S37>/Unknown' */

  /* Start of '<S359>/Move Control' */
  {
    0.00250000018F,                    /* '<S370>/Square' */
    0.14709F,                          /* '<S370>/Multiply' */
    -58.836F                           /* '<S370>/Gain4' */
  }
  ,

  /* End of '<S359>/Move Control' */

  /* Start of '<S359>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S366>/Vector Concatenate3' */
  }
  ,

  /* End of '<S359>/Hold Control' */

  /* Start of '<S347>/Move Control' */
  {
    0.0004F,                           /* '<S357>/Square' */
    0.00628318498F,                    /* '<S357>/Multiply' */
    -15.707963F                        /* '<S357>/Gain4' */
  }
  ,

  /* End of '<S347>/Move Control' */

  /* Start of '<S337>/Move Control' */
  {
    0.00250000018F,                    /* '<S345>/Square' */
    0.196120009F,                      /* '<S345>/Multiply' */
    -78.448F                           /* '<S345>/Gain4' */
  }
  ,

  /* End of '<S337>/Move Control' */

  /* Start of '<S420>/Move Control' */
  {
    0.00250000018F,                    /* '<S431>/Square' */
    0.14709F,                          /* '<S431>/Multiply' */
    -58.836F                           /* '<S431>/Gain4' */
  }
  ,

  /* End of '<S420>/Move Control' */

  /* Start of '<S420>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S427>/Vector Concatenate3' */
  }
  ,

  /* End of '<S420>/Hold Control' */

  /* Start of '<S410>/Move Control' */
  {
    0.00250000018F,                    /* '<S418>/Square' */
    0.196120009F,                      /* '<S418>/Multiply' */
    -78.448F                           /* '<S418>/Gain4' */
  }
  /* End of '<S410>/Move Control' */
};

/* Constant parameters (default storage) */
const ConstP_FMS_T FMS_ConstP = {
  /* Pooled Parameter (Expression: [4,4,2])
   * Referenced by:
   *   '<S290>/Saturation1'
   *   '<S292>/Saturation'
   *   '<S293>/Saturation1'
   */
  { 4.0F, 4.0F, 2.0F },

  /* Pooled Parameter (Expression: [-4,-4,-2])
   * Referenced by:
   *   '<S290>/Saturation1'
   *   '<S292>/Saturation'
   *   '<S293>/Saturation1'
   */
  { -4.0F, -4.0F, -2.0F }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
