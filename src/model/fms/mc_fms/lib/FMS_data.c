/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2168
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu May 29 15:07:12 2025
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
  1.9966471893352524,                  /* '<S326>/Sum' */
  0.0066943799901413165,               /* '<S326>/Multiply3' */
  0.99330562000985867,                 /* '<S326>/Sum4' */
  0.0,                                 /* '<S325>/deg2rad2' */
  0.0,                                 /* '<S328>/SinCos' */
  1.0,                                 /* '<S328>/SinCos' */
  0.0001F,                             /* '<S127>/Square' */
  0.0016F,                             /* '<S70>/Square' */
  0.0016F,                             /* '<S71>/Square' */
  0.0016F,                             /* '<S141>/Square' */
  0.0016F,                             /* '<S142>/Square' */

  { 0.0F, 0.0F, 1.0F },                /* '<S237>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S177>/Math Function' */
  1.0F,                                /* '<S177>/Sum of Elements' */
  1.0F,                                /* '<S177>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S177>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S177>/Switch' */

  { 0.0F, 1.0F },                      /* '<S177>/Divide' */
  0.616850317F,                        /* '<S173>/Square' */
  0.645964146F,                        /* '<S173>/Multiply' */
  -1.04719758F,                        /* '<S173>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S319>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S320>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S316>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S312>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S249>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S251>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S341>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S343>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S472>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S412>/Math Function' */
  1.0F,                                /* '<S412>/Sum of Elements' */
  1.0F,                                /* '<S412>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S412>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S412>/Switch' */

  { 0.0F, 1.0F },                      /* '<S412>/Divide' */
  0.616850317F,                        /* '<S408>/Square' */
  0.645964146F,                        /* '<S408>/Multiply' */
  -1.04719758F,                        /* '<S408>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S395>/Vector Concatenate3' */
  0.122499995F,                        /* '<S391>/Square' */
  1.20123494F,                         /* '<S391>/Multiply' */
  -9.806F,                             /* '<S391>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S483>/Vector Concatenate3' */
  0.122499995F,                        /* '<S479>/Square' */
  1.20123494F,                         /* '<S479>/Multiply' */
  -9.806F,                             /* '<S479>/Gain4' */
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
  3U,                                  /* '<S160>/Data Type Conversion' */
  4U,                                  /* '<S160>/Data Type Conversion1' */
  5U,                                  /* '<S160>/Data Type Conversion2' */
  3U,                                  /* '<S157>/Data Type Conversion' */
  3U,                                  /* '<S157>/Data Type Conversion1' */
  6U,                                  /* '<S157>/Data Type Conversion2' */
  3U,                                  /* '<S344>/Data Type Conversion' */
  6U,                                  /* '<S344>/Data Type Conversion1' */
  5U,                                  /* '<S344>/Data Type Conversion2' */
  3U,                                  /* '<S346>/Data Type Conversion' */
  16U,                                 /* '<S346>/Data Type Conversion1' */
  5U,                                  /* '<S346>/Data Type Conversion2' */
  3U,                                  /* '<S345>/Data Type Conversion' */
  15U,                                 /* '<S345>/Data Type Conversion1' */
  5U,                                  /* '<S345>/Data Type Conversion2' */
  3U,                                  /* '<S347>/Data Type Conversion' */
  17U,                                 /* '<S347>/Data Type Conversion1' */
  5U,                                  /* '<S347>/Data Type Conversion2' */
  2U,                                  /* '<S35>/Data Type Conversion2' */
  2U,                                  /* '<S35>/Data Type Conversion1' */
  1U,                                  /* '<S34>/Data Type Conversion' */
  1U,                                  /* '<S34>/Data Type Conversion1' */

  /* Start of '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S490>/Sum' */
    0.0066943799901413165,             /* '<S490>/Multiply3' */
    0.99330562000985867                /* '<S490>/Sum4' */
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

  /* Start of '<S113>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S120>/Vector Concatenate3' */
  }
  ,

  /* End of '<S113>/Hold Control' */

  /* Start of '<S100>/Move Control' */
  {
    0.0004F,                           /* '<S110>/Square' */
    0.00628318498F,                    /* '<S110>/Multiply' */
    -15.707963F                        /* '<S110>/Gain4' */
  }
  ,

  /* End of '<S100>/Move Control' */

  /* Start of '<S72>/Move Control' */
  {
    0.0004F,                           /* '<S82>/Square' */
    0.00628318498F,                    /* '<S82>/Multiply' */
    -15.707963F                        /* '<S82>/Gain4' */
  }
  ,

  /* End of '<S72>/Move Control' */

  /* Start of '<S143>/Move Control' */
  {
    0.0004F,                           /* '<S153>/Square' */
    0.00628318498F,                    /* '<S153>/Multiply' */
    -15.707963F                        /* '<S153>/Gain4' */
  }
  ,

  /* End of '<S143>/Move Control' */

  /* Start of '<S37>/Unknown' */
  {
    1U,                                /* '<S158>/Data Type Conversion' */
    1U                                 /* '<S158>/Data Type Conversion1' */
  }
  ,

  /* End of '<S37>/Unknown' */

  /* Start of '<S207>/Move Control' */
  {
    0.00250000018F,                    /* '<S218>/Square' */
    0.14709F,                          /* '<S218>/Multiply' */
    -58.836F                           /* '<S218>/Gain4' */
  }
  ,

  /* End of '<S207>/Move Control' */

  /* Start of '<S207>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S214>/Vector Concatenate3' */
  }
  ,

  /* End of '<S207>/Hold Control' */

  /* Start of '<S197>/Move Control' */
  {
    0.00250000018F,                    /* '<S205>/Square' */
    0.196120009F,                      /* '<S205>/Multiply' */
    -78.448F                           /* '<S205>/Gain4' */
  }
  ,

  /* End of '<S197>/Move Control' */

  /* Start of '<S39>/Unknown' */
  {
    1U,                                /* '<S348>/Data Type Conversion' */
    1U                                 /* '<S348>/Data Type Conversion1' */
  }
  ,

  /* End of '<S39>/Unknown' */

  /* Start of '<S374>/Move Control' */
  {
    0.00250000018F,                    /* '<S385>/Square' */
    0.14709F,                          /* '<S385>/Multiply' */
    -58.836F                           /* '<S385>/Gain4' */
  }
  ,

  /* End of '<S374>/Move Control' */

  /* Start of '<S374>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S381>/Vector Concatenate3' */
  }
  ,

  /* End of '<S374>/Hold Control' */

  /* Start of '<S362>/Move Control' */
  {
    0.0004F,                           /* '<S372>/Square' */
    0.00628318498F,                    /* '<S372>/Multiply' */
    -15.707963F                        /* '<S372>/Gain4' */
  }
  ,

  /* End of '<S362>/Move Control' */

  /* Start of '<S352>/Move Control' */
  {
    0.00250000018F,                    /* '<S360>/Square' */
    0.196120009F,                      /* '<S360>/Multiply' */
    -78.448F                           /* '<S360>/Gain4' */
  }
  ,

  /* End of '<S352>/Move Control' */

  /* Start of '<S442>/Move Control' */
  {
    0.00250000018F,                    /* '<S453>/Square' */
    0.14709F,                          /* '<S453>/Multiply' */
    -58.836F                           /* '<S453>/Gain4' */
  }
  ,

  /* End of '<S442>/Move Control' */

  /* Start of '<S442>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S449>/Vector Concatenate3' */
  }
  ,

  /* End of '<S442>/Hold Control' */

  /* Start of '<S432>/Move Control' */
  {
    0.00250000018F,                    /* '<S440>/Square' */
    0.196120009F,                      /* '<S440>/Multiply' */
    -78.448F                           /* '<S440>/Gain4' */
  }
  /* End of '<S432>/Move Control' */
};

/* Constant parameters (default storage) */
const ConstP_FMS_T FMS_ConstP = {
  /* Pooled Parameter (Expression: [4,4,2])
   * Referenced by:
   *   '<S305>/Saturation1'
   *   '<S307>/Saturation'
   *   '<S308>/Saturation1'
   */
  { 4.0F, 4.0F, 2.0F },

  /* Pooled Parameter (Expression: [-4,-4,-2])
   * Referenced by:
   *   '<S305>/Saturation1'
   *   '<S307>/Saturation'
   *   '<S308>/Saturation1'
   */
  { -4.0F, -4.0F, -2.0F }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
