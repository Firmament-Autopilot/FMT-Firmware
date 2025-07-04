/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2197
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Jul  4 09:55:30 2025
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
  1.9966471893352524,                  /* '<S327>/Sum' */
  0.0066943799901413165,               /* '<S327>/Multiply3' */
  0.99330562000985867,                 /* '<S327>/Sum4' */
  0.0,                                 /* '<S326>/deg2rad2' */
  0.0,                                 /* '<S329>/SinCos' */
  1.0,                                 /* '<S329>/SinCos' */
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

  { 0.0F, 0.0F, 1.0F },                /* '<S313>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S317>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S321>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S320>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S250>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S252>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S343>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S345>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S474>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S414>/Math Function' */
  1.0F,                                /* '<S414>/Sum of Elements' */
  1.0F,                                /* '<S414>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S414>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S414>/Switch' */

  { 0.0F, 1.0F },                      /* '<S414>/Divide' */
  0.616850317F,                        /* '<S410>/Square' */
  0.645964146F,                        /* '<S410>/Multiply' */
  -1.04719758F,                        /* '<S410>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S397>/Vector Concatenate3' */
  0.122499995F,                        /* '<S393>/Square' */
  1.20123494F,                         /* '<S393>/Multiply' */
  -9.806F,                             /* '<S393>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S485>/Vector Concatenate3' */
  0.122499995F,                        /* '<S481>/Square' */
  1.20123494F,                         /* '<S481>/Multiply' */
  -9.806F,                             /* '<S481>/Gain4' */
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
  3U,                                  /* '<S346>/Data Type Conversion' */
  6U,                                  /* '<S346>/Data Type Conversion1' */
  5U,                                  /* '<S346>/Data Type Conversion2' */
  3U,                                  /* '<S348>/Data Type Conversion' */
  16U,                                 /* '<S348>/Data Type Conversion1' */
  5U,                                  /* '<S348>/Data Type Conversion2' */
  3U,                                  /* '<S347>/Data Type Conversion' */
  15U,                                 /* '<S347>/Data Type Conversion1' */
  5U,                                  /* '<S347>/Data Type Conversion2' */
  3U,                                  /* '<S349>/Data Type Conversion' */
  17U,                                 /* '<S349>/Data Type Conversion1' */
  5U,                                  /* '<S349>/Data Type Conversion2' */
  2U,                                  /* '<S35>/Data Type Conversion2' */
  2U,                                  /* '<S35>/Data Type Conversion1' */
  1U,                                  /* '<S34>/Data Type Conversion' */
  1U,                                  /* '<S34>/Data Type Conversion1' */

  /* Start of '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S492>/Sum' */
    0.0066943799901413165,             /* '<S492>/Multiply3' */
    0.99330562000985867                /* '<S492>/Sum4' */
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
    1U,                                /* '<S350>/Data Type Conversion' */
    1U                                 /* '<S350>/Data Type Conversion1' */
  }
  ,

  /* End of '<S39>/Unknown' */

  /* Start of '<S376>/Move Control' */
  {
    0.00250000018F,                    /* '<S387>/Square' */
    0.14709F,                          /* '<S387>/Multiply' */
    -58.836F                           /* '<S387>/Gain4' */
  }
  ,

  /* End of '<S376>/Move Control' */

  /* Start of '<S376>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S383>/Vector Concatenate3' */
  }
  ,

  /* End of '<S376>/Hold Control' */

  /* Start of '<S364>/Move Control' */
  {
    0.0004F,                           /* '<S374>/Square' */
    0.00628318498F,                    /* '<S374>/Multiply' */
    -15.707963F                        /* '<S374>/Gain4' */
  }
  ,

  /* End of '<S364>/Move Control' */

  /* Start of '<S354>/Move Control' */
  {
    0.00250000018F,                    /* '<S362>/Square' */
    0.196120009F,                      /* '<S362>/Multiply' */
    -78.448F                           /* '<S362>/Gain4' */
  }
  ,

  /* End of '<S354>/Move Control' */

  /* Start of '<S444>/Move Control' */
  {
    0.00250000018F,                    /* '<S455>/Square' */
    0.14709F,                          /* '<S455>/Multiply' */
    -58.836F                           /* '<S455>/Gain4' */
  }
  ,

  /* End of '<S444>/Move Control' */

  /* Start of '<S444>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S451>/Vector Concatenate3' */
  }
  ,

  /* End of '<S444>/Hold Control' */

  /* Start of '<S434>/Move Control' */
  {
    0.00250000018F,                    /* '<S442>/Square' */
    0.196120009F,                      /* '<S442>/Multiply' */
    -78.448F                           /* '<S442>/Gain4' */
  }
  /* End of '<S434>/Move Control' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
