/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2238
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Sep  2 17:03:41 2025
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
  1.9966471893352524,                  /* '<S329>/Sum' */
  0.0066943799901413165,               /* '<S329>/Multiply3' */
  0.99330562000985867,                 /* '<S329>/Sum4' */
  0.0,                                 /* '<S328>/deg2rad2' */
  0.0,                                 /* '<S331>/SinCos' */
  1.0,                                 /* '<S331>/SinCos' */
  0.00250000018F,                      /* '<S126>/Square' */

  { 0.0F, 0.0F, 1.0F },                /* '<S119>/Vector Concatenate3' */
  0.0016F,                             /* '<S70>/Square' */
  0.0016F,                             /* '<S71>/Square' */
  0.0016F,                             /* '<S140>/Square' */
  0.0016F,                             /* '<S141>/Square' */

  { 0.0F, 0.0F, 1.0F },                /* '<S236>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S176>/Math Function' */
  1.0F,                                /* '<S176>/Sum of Elements' */
  1.0F,                                /* '<S176>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S176>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S176>/Switch' */

  { 0.0F, 1.0F },                      /* '<S176>/Divide' */
  0.616850317F,                        /* '<S172>/Square' */
  0.645964146F,                        /* '<S172>/Multiply' */
  -1.04719758F,                        /* '<S172>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S313>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S317>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S323>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S321>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S320>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S249>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S251>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S345>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S347>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S476>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S416>/Math Function' */
  1.0F,                                /* '<S416>/Sum of Elements' */
  1.0F,                                /* '<S416>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S416>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S416>/Switch' */

  { 0.0F, 1.0F },                      /* '<S416>/Divide' */
  0.616850317F,                        /* '<S412>/Square' */
  0.645964146F,                        /* '<S412>/Multiply' */
  -1.04719758F,                        /* '<S412>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S399>/Vector Concatenate3' */
  0.122499995F,                        /* '<S395>/Square' */
  1.20123494F,                         /* '<S395>/Multiply' */
  -9.806F,                             /* '<S395>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S487>/Vector Concatenate3' */
  0.122499995F,                        /* '<S483>/Square' */
  1.20123494F,                         /* '<S483>/Multiply' */
  -9.806F,                             /* '<S483>/Gain4' */
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
  3U,                                  /* '<S159>/Data Type Conversion' */
  4U,                                  /* '<S159>/Data Type Conversion1' */
  5U,                                  /* '<S159>/Data Type Conversion2' */
  3U,                                  /* '<S156>/Data Type Conversion' */
  3U,                                  /* '<S156>/Data Type Conversion1' */
  6U,                                  /* '<S156>/Data Type Conversion2' */
  3U,                                  /* '<S348>/Data Type Conversion' */
  6U,                                  /* '<S348>/Data Type Conversion1' */
  5U,                                  /* '<S348>/Data Type Conversion2' */
  3U,                                  /* '<S350>/Data Type Conversion' */
  16U,                                 /* '<S350>/Data Type Conversion1' */
  5U,                                  /* '<S350>/Data Type Conversion2' */
  3U,                                  /* '<S349>/Data Type Conversion' */
  15U,                                 /* '<S349>/Data Type Conversion1' */
  5U,                                  /* '<S349>/Data Type Conversion2' */
  3U,                                  /* '<S351>/Data Type Conversion' */
  17U,                                 /* '<S351>/Data Type Conversion1' */
  5U,                                  /* '<S351>/Data Type Conversion2' */
  2U,                                  /* '<S35>/Data Type Conversion2' */
  2U,                                  /* '<S35>/Data Type Conversion1' */
  1U,                                  /* '<S34>/Data Type Conversion' */
  1U,                                  /* '<S34>/Data Type Conversion1' */

  /* Start of '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S494>/Sum' */
    0.0066943799901413165,             /* '<S494>/Multiply3' */
    0.99330562000985867                /* '<S494>/Sum4' */
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

  /* Start of '<S142>/Move Control' */
  {
    0.0004F,                           /* '<S152>/Square' */
    0.00628318498F,                    /* '<S152>/Multiply' */
    -15.707963F                        /* '<S152>/Gain4' */
  }
  ,

  /* End of '<S142>/Move Control' */

  /* Start of '<S37>/Unknown' */
  {
    1U,                                /* '<S157>/Data Type Conversion' */
    1U                                 /* '<S157>/Data Type Conversion1' */
  }
  ,

  /* End of '<S37>/Unknown' */

  /* Start of '<S206>/Move Control' */
  {
    0.00250000018F,                    /* '<S217>/Square' */
    0.14709F,                          /* '<S217>/Multiply' */
    -58.836F                           /* '<S217>/Gain4' */
  }
  ,

  /* End of '<S206>/Move Control' */

  /* Start of '<S206>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S213>/Vector Concatenate3' */
  }
  ,

  /* End of '<S206>/Hold Control' */

  /* Start of '<S196>/Move Control' */
  {
    0.00250000018F,                    /* '<S204>/Square' */
    0.196120009F,                      /* '<S204>/Multiply' */
    -78.448F                           /* '<S204>/Gain4' */
  }
  ,

  /* End of '<S196>/Move Control' */

  /* Start of '<S39>/Unknown' */
  {
    1U,                                /* '<S352>/Data Type Conversion' */
    1U                                 /* '<S352>/Data Type Conversion1' */
  }
  ,

  /* End of '<S39>/Unknown' */

  /* Start of '<S378>/Move Control' */
  {
    0.00250000018F,                    /* '<S389>/Square' */
    0.14709F,                          /* '<S389>/Multiply' */
    -58.836F                           /* '<S389>/Gain4' */
  }
  ,

  /* End of '<S378>/Move Control' */

  /* Start of '<S378>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S385>/Vector Concatenate3' */
  }
  ,

  /* End of '<S378>/Hold Control' */

  /* Start of '<S366>/Move Control' */
  {
    0.0004F,                           /* '<S376>/Square' */
    0.00628318498F,                    /* '<S376>/Multiply' */
    -15.707963F                        /* '<S376>/Gain4' */
  }
  ,

  /* End of '<S366>/Move Control' */

  /* Start of '<S356>/Move Control' */
  {
    0.00250000018F,                    /* '<S364>/Square' */
    0.196120009F,                      /* '<S364>/Multiply' */
    -78.448F                           /* '<S364>/Gain4' */
  }
  ,

  /* End of '<S356>/Move Control' */

  /* Start of '<S446>/Move Control' */
  {
    0.00250000018F,                    /* '<S457>/Square' */
    0.14709F,                          /* '<S457>/Multiply' */
    -58.836F                           /* '<S457>/Gain4' */
  }
  ,

  /* End of '<S446>/Move Control' */

  /* Start of '<S446>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S453>/Vector Concatenate3' */
  }
  ,

  /* End of '<S446>/Hold Control' */

  /* Start of '<S436>/Move Control' */
  {
    0.00250000018F,                    /* '<S444>/Square' */
    0.196120009F,                      /* '<S444>/Multiply' */
    -78.448F                           /* '<S444>/Gain4' */
  }
  /* End of '<S436>/Move Control' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
