/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2243
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Sep 22 16:56:06 2025
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
  1.9966471893352524,                  /* '<S328>/Sum' */
  0.0066943799901413165,               /* '<S328>/Multiply3' */
  0.99330562000985867,                 /* '<S328>/Sum4' */
  0.0,                                 /* '<S327>/deg2rad2' */
  0.0,                                 /* '<S330>/SinCos' */
  1.0,                                 /* '<S330>/SinCos' */
  0.00250000018F,                      /* '<S122>/Square' */

  { 0.0F, 0.0F, 1.0F },                /* '<S115>/Vector Concatenate3' */
  0.0016F,                             /* '<S69>/Square' */
  0.0016F,                             /* '<S70>/Square' */
  0.0016F,                             /* '<S136>/Square' */
  0.0016F,                             /* '<S137>/Square' */

  { 0.0F, 0.0F, 1.0F },                /* '<S231>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S171>/Math Function' */
  1.0F,                                /* '<S171>/Sum of Elements' */
  1.0F,                                /* '<S171>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S171>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S171>/Switch' */

  { 0.0F, 1.0F },                      /* '<S171>/Divide' */
  0.616850317F,                        /* '<S167>/Square' */
  0.645964146F,                        /* '<S167>/Multiply' */
  -1.04719758F,                        /* '<S167>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S310>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S315>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S319>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S318>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S244>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S246>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S344>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S346>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S475>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S415>/Math Function' */
  1.0F,                                /* '<S415>/Sum of Elements' */
  1.0F,                                /* '<S415>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S415>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S415>/Switch' */

  { 0.0F, 1.0F },                      /* '<S415>/Divide' */
  0.616850317F,                        /* '<S411>/Square' */
  0.645964146F,                        /* '<S411>/Multiply' */
  -1.04719758F,                        /* '<S411>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S398>/Vector Concatenate3' */
  0.122499995F,                        /* '<S394>/Square' */
  1.20123494F,                         /* '<S394>/Multiply' */
  -9.806F,                             /* '<S394>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S486>/Vector Concatenate3' */
  0.122499995F,                        /* '<S482>/Square' */
  1.20123494F,                         /* '<S482>/Multiply' */
  -9.806F,                             /* '<S482>/Gain4' */
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
  3U,                                  /* '<S154>/Data Type Conversion' */
  4U,                                  /* '<S154>/Data Type Conversion1' */
  5U,                                  /* '<S154>/Data Type Conversion2' */
  3U,                                  /* '<S151>/Data Type Conversion' */
  3U,                                  /* '<S151>/Data Type Conversion1' */
  6U,                                  /* '<S151>/Data Type Conversion2' */
  3U,                                  /* '<S347>/Data Type Conversion' */
  6U,                                  /* '<S347>/Data Type Conversion1' */
  5U,                                  /* '<S347>/Data Type Conversion2' */
  3U,                                  /* '<S349>/Data Type Conversion' */
  16U,                                 /* '<S349>/Data Type Conversion1' */
  5U,                                  /* '<S349>/Data Type Conversion2' */
  3U,                                  /* '<S348>/Data Type Conversion' */
  15U,                                 /* '<S348>/Data Type Conversion1' */
  5U,                                  /* '<S348>/Data Type Conversion2' */
  3U,                                  /* '<S350>/Data Type Conversion' */
  17U,                                 /* '<S350>/Data Type Conversion1' */
  5U,                                  /* '<S350>/Data Type Conversion2' */
  2U,                                  /* '<S35>/Data Type Conversion2' */
  2U,                                  /* '<S35>/Data Type Conversion1' */
  1U,                                  /* '<S34>/Data Type Conversion' */
  1U,                                  /* '<S34>/Data Type Conversion1' */

  /* Start of '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S493>/Sum' */
    0.0066943799901413165,             /* '<S493>/Multiply3' */
    0.99330562000985867                /* '<S493>/Sum4' */
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

  /* Start of '<S97>/Move Control' */
  {
    0.0004F,                           /* '<S106>/Square' */
    0.00628318498F,                    /* '<S106>/Multiply' */
    -15.707963F                        /* '<S106>/Gain4' */
  }
  ,

  /* End of '<S97>/Move Control' */

  /* Start of '<S71>/Move Control' */
  {
    0.0004F,                           /* '<S80>/Square' */
    0.00628318498F,                    /* '<S80>/Multiply' */
    -15.707963F                        /* '<S80>/Gain4' */
  }
  ,

  /* End of '<S71>/Move Control' */

  /* Start of '<S138>/Move Control' */
  {
    0.0004F,                           /* '<S147>/Square' */
    0.00628318498F,                    /* '<S147>/Multiply' */
    -15.707963F                        /* '<S147>/Gain4' */
  }
  ,

  /* End of '<S138>/Move Control' */

  /* Start of '<S37>/Unknown' */
  {
    1U,                                /* '<S152>/Data Type Conversion' */
    1U                                 /* '<S152>/Data Type Conversion1' */
  }
  ,

  /* End of '<S37>/Unknown' */

  /* Start of '<S201>/Move Control' */
  {
    0.00250000018F,                    /* '<S212>/Square' */
    0.14709F,                          /* '<S212>/Multiply' */
    -58.836F                           /* '<S212>/Gain4' */
  }
  ,

  /* End of '<S201>/Move Control' */

  /* Start of '<S201>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S208>/Vector Concatenate3' */
  }
  ,

  /* End of '<S201>/Hold Control' */

  /* Start of '<S191>/Move Control' */
  {
    0.00250000018F,                    /* '<S199>/Square' */
    0.196120009F,                      /* '<S199>/Multiply' */
    -78.448F                           /* '<S199>/Gain4' */
  }
  ,

  /* End of '<S191>/Move Control' */

  /* Start of '<S39>/Unknown' */
  {
    1U,                                /* '<S351>/Data Type Conversion' */
    1U                                 /* '<S351>/Data Type Conversion1' */
  }
  ,

  /* End of '<S39>/Unknown' */

  /* Start of '<S377>/Move Control' */
  {
    0.00250000018F,                    /* '<S388>/Square' */
    0.14709F,                          /* '<S388>/Multiply' */
    -58.836F                           /* '<S388>/Gain4' */
  }
  ,

  /* End of '<S377>/Move Control' */

  /* Start of '<S377>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S384>/Vector Concatenate3' */
  }
  ,

  /* End of '<S377>/Hold Control' */

  /* Start of '<S365>/Move Control' */
  {
    0.0004F,                           /* '<S375>/Square' */
    0.00628318498F,                    /* '<S375>/Multiply' */
    -15.707963F                        /* '<S375>/Gain4' */
  }
  ,

  /* End of '<S365>/Move Control' */

  /* Start of '<S355>/Move Control' */
  {
    0.00250000018F,                    /* '<S363>/Square' */
    0.196120009F,                      /* '<S363>/Multiply' */
    -78.448F                           /* '<S363>/Gain4' */
  }
  ,

  /* End of '<S355>/Move Control' */

  /* Start of '<S445>/Move Control' */
  {
    0.00250000018F,                    /* '<S456>/Square' */
    0.14709F,                          /* '<S456>/Multiply' */
    -58.836F                           /* '<S456>/Gain4' */
  }
  ,

  /* End of '<S445>/Move Control' */

  /* Start of '<S445>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S452>/Vector Concatenate3' */
  }
  ,

  /* End of '<S445>/Hold Control' */

  /* Start of '<S435>/Move Control' */
  {
    0.00250000018F,                    /* '<S443>/Square' */
    0.196120009F,                      /* '<S443>/Multiply' */
    -78.448F                           /* '<S443>/Gain4' */
  }
  /* End of '<S435>/Move Control' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
