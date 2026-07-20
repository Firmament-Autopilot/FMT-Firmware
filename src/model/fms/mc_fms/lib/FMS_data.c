/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2338
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Jul 20 15:54:09 2026
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
  1.9966471893352524,                  /* '<S375>/Sum' */
  0.0066943799901413165,               /* '<S375>/Multiply3' */
  0.99330562000985867,                 /* '<S375>/Sum4' */
  0.0,                                 /* '<S374>/deg2rad2' */
  0.0,                                 /* '<S377>/SinCos' */
  1.0,                                 /* '<S377>/SinCos' */
  0.00250000018F,                      /* '<S166>/Square' */
  0.0016F,                             /* '<S71>/Square' */
  0.0016F,                             /* '<S72>/Square' */
  0.0016F,                             /* '<S138>/Square' */
  0.0016F,                             /* '<S139>/Square' */

  { 0.0F, 0.0F, 1.0F },                /* '<S285>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S219>/Math Function' */
  1.0F,                                /* '<S219>/Sum of Elements' */
  1.0F,                                /* '<S219>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S219>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S219>/Switch' */

  { 0.0F, 1.0F },                      /* '<S219>/Divide' */
  0.616850317F,                        /* '<S215>/Square' */
  0.645964146F,                        /* '<S215>/Multiply' */
  -1.04719758F,                        /* '<S215>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S361>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S365>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S369>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S368>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S298>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S300>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S391>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S393>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S528>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S462>/Math Function' */
  1.0F,                                /* '<S462>/Sum of Elements' */
  1.0F,                                /* '<S462>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S462>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S462>/Switch' */

  { 0.0F, 1.0F },                      /* '<S462>/Divide' */
  0.616850317F,                        /* '<S458>/Square' */
  0.645964146F,                        /* '<S458>/Multiply' */
  -1.04719758F,                        /* '<S458>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S445>/Vector Concatenate3' */
  0.122499995F,                        /* '<S441>/Square' */
  1.20123494F,                         /* '<S441>/Multiply' */
  -9.806F,                             /* '<S441>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S539>/Vector Concatenate3' */
  0.122499995F,                        /* '<S535>/Square' */
  1.20123494F,                         /* '<S535>/Multiply' */
  -9.806F,                             /* '<S535>/Gain4' */
  1U,                                  /* '<S39>/Data Type Conversion' */
  13U,                                 /* '<S39>/Data Type Conversion1' */
  3U,                                  /* '<S46>/Data Type Conversion' */
  11U,                                 /* '<S46>/Data Type Conversion1' */
  5U,                                  /* '<S46>/Data Type Conversion2' */
  3U,                                  /* '<S44>/Data Type Conversion' */
  10U,                                 /* '<S44>/Data Type Conversion1' */
  5U,                                  /* '<S44>/Data Type Conversion2' */
  3U,                                  /* '<S43>/Data Type Conversion1' */
  9U,                                  /* '<S43>/Data Type Conversion2' */
  4U,                                  /* '<S43>/Data Type Conversion3' */
  3U,                                  /* '<S45>/Data Type Conversion' */
  8U,                                  /* '<S45>/Data Type Conversion1' */
  3U,                                  /* '<S45>/Data Type Conversion2' */
  3U,                                  /* '<S42>/Data Type Conversion' */
  7U,                                  /* '<S42>/Data Type Conversion1' */
  2U,                                  /* '<S42>/Data Type Conversion2' */
  3U,                                  /* '<S202>/Data Type Conversion' */
  4U,                                  /* '<S202>/Data Type Conversion1' */
  5U,                                  /* '<S202>/Data Type Conversion2' */
  3U,                                  /* '<S199>/Data Type Conversion' */
  3U,                                  /* '<S199>/Data Type Conversion1' */
  6U,                                  /* '<S199>/Data Type Conversion2' */
  3U,                                  /* '<S394>/Data Type Conversion' */
  6U,                                  /* '<S394>/Data Type Conversion1' */
  5U,                                  /* '<S394>/Data Type Conversion2' */
  3U,                                  /* '<S396>/Data Type Conversion' */
  17U,                                 /* '<S396>/Data Type Conversion1' */
  5U,                                  /* '<S396>/Data Type Conversion2' */
  3U,                                  /* '<S395>/Data Type Conversion' */
  16U,                                 /* '<S395>/Data Type Conversion1' */
  5U,                                  /* '<S395>/Data Type Conversion2' */
  3U,                                  /* '<S397>/Data Type Conversion' */
  18U,                                 /* '<S397>/Data Type Conversion1' */
  5U,                                  /* '<S397>/Data Type Conversion2' */
  2U,                                  /* '<S36>/Data Type Conversion2' */
  2U,                                  /* '<S36>/Data Type Conversion1' */
  1U,                                  /* '<S35>/Data Type Conversion' */
  1U,                                  /* '<S35>/Data Type Conversion1' */

  /* Start of '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S546>/Sum' */
    0.0066943799901413165,             /* '<S546>/Multiply3' */
    0.99330562000985867                /* '<S546>/Sum4' */
  }
  ,

  /* End of '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */

  /* Start of '<S33>/Unknown' */
  {
    1U,                                /* '<S41>/Data Type Conversion' */
    1U                                 /* '<S41>/Data Type Conversion1' */
  }
  ,

  /* End of '<S33>/Unknown' */

  /* Start of '<S37>/Unknown' */
  {
    1U,                                /* '<S47>/Data Type Conversion' */
    1U                                 /* '<S47>/Data Type Conversion1' */
  }
  ,

  /* End of '<S37>/Unknown' */

  /* Start of '<S181>/Move Control' */
  {
    0.00250000018F                     /* '<S194>/Square' */
  }
  ,

  /* End of '<S181>/Move Control' */

  /* Start of '<S181>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S187>/Vector Concatenate3' */
  }
  ,

  /* End of '<S181>/Hold Control' */

  /* Start of '<S169>/Move Control' */
  {
    0.0004F,                           /* '<S178>/Square' */
    0.00628318498F,                    /* '<S178>/Multiply' */
    -15.707963F                        /* '<S178>/Gain4' */
  }
  ,

  /* End of '<S169>/Move Control' */

  /* Start of '<S111>/Move Control' */
  {
    0.00250000018F                     /* '<S124>/Square' */
  }
  ,

  /* End of '<S111>/Move Control' */

  /* Start of '<S111>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S117>/Vector Concatenate3' */
  }
  ,

  /* End of '<S111>/Hold Control' */

  /* Start of '<S99>/Move Control' */
  {
    0.0004F,                           /* '<S108>/Square' */
    0.00628318498F,                    /* '<S108>/Multiply' */
    -15.707963F                        /* '<S108>/Gain4' */
  }
  ,

  /* End of '<S99>/Move Control' */

  /* Start of '<S73>/Move Control' */
  {
    0.0004F,                           /* '<S82>/Square' */
    0.00628318498F,                    /* '<S82>/Multiply' */
    -15.707963F                        /* '<S82>/Gain4' */
  }
  ,

  /* End of '<S73>/Move Control' */

  /* Start of '<S140>/Move Control' */
  {
    0.0004F,                           /* '<S149>/Square' */
    0.00628318498F,                    /* '<S149>/Multiply' */
    -15.707963F                        /* '<S149>/Gain4' */
  }
  ,

  /* End of '<S140>/Move Control' */

  /* Start of '<S38>/Unknown' */
  {
    1U,                                /* '<S200>/Data Type Conversion' */
    1U                                 /* '<S200>/Data Type Conversion1' */
  }
  ,

  /* End of '<S38>/Unknown' */

  /* Start of '<S249>/Move Control' */
  {
    0.00250000018F,                    /* '<S260>/Square' */
    0.14709F,                          /* '<S260>/Multiply' */
    -58.836F                           /* '<S260>/Gain4' */
  }
  ,

  /* End of '<S249>/Move Control' */

  /* Start of '<S249>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S256>/Vector Concatenate3' */
  }
  ,

  /* End of '<S249>/Hold Control' */

  /* Start of '<S239>/Move Control' */
  {
    0.00250000018F,                    /* '<S247>/Square' */
    0.196120009F,                      /* '<S247>/Multiply' */
    -78.448F                           /* '<S247>/Gain4' */
  }
  ,

  /* End of '<S239>/Move Control' */

  /* Start of '<S40>/Unknown' */
  {
    1U,                                /* '<S398>/Data Type Conversion' */
    1U                                 /* '<S398>/Data Type Conversion1' */
  }
  ,

  /* End of '<S40>/Unknown' */

  /* Start of '<S424>/Move Control' */
  {
    0.00250000018F,                    /* '<S435>/Square' */
    0.14709F,                          /* '<S435>/Multiply' */
    -58.836F                           /* '<S435>/Gain4' */
  }
  ,

  /* End of '<S424>/Move Control' */

  /* Start of '<S424>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S431>/Vector Concatenate3' */
  }
  ,

  /* End of '<S424>/Hold Control' */

  /* Start of '<S412>/Move Control' */
  {
    0.0004F,                           /* '<S422>/Square' */
    0.00628318498F,                    /* '<S422>/Multiply' */
    -15.707963F                        /* '<S422>/Gain4' */
  }
  ,

  /* End of '<S412>/Move Control' */

  /* Start of '<S402>/Move Control' */
  {
    0.00250000018F,                    /* '<S410>/Square' */
    0.196120009F,                      /* '<S410>/Multiply' */
    -78.448F                           /* '<S410>/Gain4' */
  }
  ,

  /* End of '<S402>/Move Control' */

  /* Start of '<S492>/Move Control' */
  {
    0.00250000018F,                    /* '<S503>/Square' */
    0.14709F,                          /* '<S503>/Multiply' */
    -58.836F                           /* '<S503>/Gain4' */
  }
  ,

  /* End of '<S492>/Move Control' */

  /* Start of '<S492>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S499>/Vector Concatenate3' */
  }
  ,

  /* End of '<S492>/Hold Control' */

  /* Start of '<S482>/Move Control' */
  {
    0.00250000018F,                    /* '<S490>/Square' */
    0.196120009F,                      /* '<S490>/Multiply' */
    -78.448F                           /* '<S490>/Gain4' */
  }
  /* End of '<S482>/Move Control' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
