/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2226
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Aug  4 11:22:09 2025
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
  1.9966471893352524,                  /* '<S330>/Sum' */
  0.0066943799901413165,               /* '<S330>/Multiply3' */
  0.99330562000985867,                 /* '<S330>/Sum4' */
  0.0,                                 /* '<S329>/deg2rad2' */
  0.0,                                 /* '<S332>/SinCos' */
  1.0,                                 /* '<S332>/SinCos' */
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

  { 0.0F, 0.0F, 1.0F },                /* '<S314>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S318>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S324>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S322>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S321>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S250>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S252>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S346>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S348>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S477>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S417>/Math Function' */
  1.0F,                                /* '<S417>/Sum of Elements' */
  1.0F,                                /* '<S417>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S417>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S417>/Switch' */

  { 0.0F, 1.0F },                      /* '<S417>/Divide' */
  0.616850317F,                        /* '<S413>/Square' */
  0.645964146F,                        /* '<S413>/Multiply' */
  -1.04719758F,                        /* '<S413>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S400>/Vector Concatenate3' */
  0.122499995F,                        /* '<S396>/Square' */
  1.20123494F,                         /* '<S396>/Multiply' */
  -9.806F,                             /* '<S396>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S488>/Vector Concatenate3' */
  0.122499995F,                        /* '<S484>/Square' */
  1.20123494F,                         /* '<S484>/Multiply' */
  -9.806F,                             /* '<S484>/Gain4' */
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
  3U,                                  /* '<S349>/Data Type Conversion' */
  6U,                                  /* '<S349>/Data Type Conversion1' */
  5U,                                  /* '<S349>/Data Type Conversion2' */
  3U,                                  /* '<S351>/Data Type Conversion' */
  16U,                                 /* '<S351>/Data Type Conversion1' */
  5U,                                  /* '<S351>/Data Type Conversion2' */
  3U,                                  /* '<S350>/Data Type Conversion' */
  15U,                                 /* '<S350>/Data Type Conversion1' */
  5U,                                  /* '<S350>/Data Type Conversion2' */
  3U,                                  /* '<S352>/Data Type Conversion' */
  17U,                                 /* '<S352>/Data Type Conversion1' */
  5U,                                  /* '<S352>/Data Type Conversion2' */
  2U,                                  /* '<S35>/Data Type Conversion2' */
  2U,                                  /* '<S35>/Data Type Conversion1' */
  1U,                                  /* '<S34>/Data Type Conversion' */
  1U,                                  /* '<S34>/Data Type Conversion1' */

  /* Start of '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S495>/Sum' */
    0.0066943799901413165,             /* '<S495>/Multiply3' */
    0.99330562000985867                /* '<S495>/Sum4' */
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
    1U,                                /* '<S353>/Data Type Conversion' */
    1U                                 /* '<S353>/Data Type Conversion1' */
  }
  ,

  /* End of '<S39>/Unknown' */

  /* Start of '<S379>/Move Control' */
  {
    0.00250000018F,                    /* '<S390>/Square' */
    0.14709F,                          /* '<S390>/Multiply' */
    -58.836F                           /* '<S390>/Gain4' */
  }
  ,

  /* End of '<S379>/Move Control' */

  /* Start of '<S379>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S386>/Vector Concatenate3' */
  }
  ,

  /* End of '<S379>/Hold Control' */

  /* Start of '<S367>/Move Control' */
  {
    0.0004F,                           /* '<S377>/Square' */
    0.00628318498F,                    /* '<S377>/Multiply' */
    -15.707963F                        /* '<S377>/Gain4' */
  }
  ,

  /* End of '<S367>/Move Control' */

  /* Start of '<S357>/Move Control' */
  {
    0.00250000018F,                    /* '<S365>/Square' */
    0.196120009F,                      /* '<S365>/Multiply' */
    -78.448F                           /* '<S365>/Gain4' */
  }
  ,

  /* End of '<S357>/Move Control' */

  /* Start of '<S447>/Move Control' */
  {
    0.00250000018F,                    /* '<S458>/Square' */
    0.14709F,                          /* '<S458>/Multiply' */
    -58.836F                           /* '<S458>/Gain4' */
  }
  ,

  /* End of '<S447>/Move Control' */

  /* Start of '<S447>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S454>/Vector Concatenate3' */
  }
  ,

  /* End of '<S447>/Hold Control' */

  /* Start of '<S437>/Move Control' */
  {
    0.00250000018F,                    /* '<S445>/Square' */
    0.196120009F,                      /* '<S445>/Multiply' */
    -78.448F                           /* '<S445>/Gain4' */
  }
  /* End of '<S437>/Move Control' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
