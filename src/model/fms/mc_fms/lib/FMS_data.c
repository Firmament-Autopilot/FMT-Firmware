/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2403
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Sep 25 08:52:15 2026
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
  1.9966471893352524,                  /* '<S336>/Sum' */
  0.0066943799901413165,               /* '<S336>/Multiply3' */
  0.99330562000985867,                 /* '<S336>/Sum4' */
  0.0,                                 /* '<S335>/deg2rad2' */
  0.0,                                 /* '<S338>/SinCos' */
  1.0,                                 /* '<S338>/SinCos' */
  0.00250000018F,                      /* '<S122>/Square' */

  { 0.0F, 0.0F, 1.0F },                /* '<S115>/Vector Concatenate3' */
  0.0016F,                             /* '<S69>/Square' */
  0.0016F,                             /* '<S70>/Square' */
  0.0016F,                             /* '<S136>/Square' */
  0.0016F,                             /* '<S137>/Square' */

  { 0.0F, 0.0F, 1.0F },                /* '<S237>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S187>/Vector Concatenate3' */
  0.616850317F,                        /* '<S166>/Square' */
  0.645964146F,                        /* '<S166>/Multiply' */
  -1.04719758F,                        /* '<S166>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S318>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S322>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S330>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S327>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S326>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S253>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S255>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S352>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S354>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S487>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S423>/Math Function' */
  1.0F,                                /* '<S423>/Sum of Elements' */
  1.0F,                                /* '<S423>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S423>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S423>/Switch' */

  { 0.0F, 1.0F },                      /* '<S423>/Divide' */
  0.616850317F,                        /* '<S419>/Square' */
  0.645964146F,                        /* '<S419>/Multiply' */
  -1.04719758F,                        /* '<S419>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S406>/Vector Concatenate3' */
  0.122499995F,                        /* '<S402>/Square' */
  1.20123494F,                         /* '<S402>/Multiply' */
  -9.806F,                             /* '<S402>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S501>/Vector Concatenate3' */
  0.122499995F,                        /* '<S497>/Square' */
  1.20123494F,                         /* '<S497>/Multiply' */
  -9.806F,                             /* '<S497>/Gain4' */
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
  3U,                                  /* '<S355>/Data Type Conversion' */
  6U,                                  /* '<S355>/Data Type Conversion1' */
  5U,                                  /* '<S355>/Data Type Conversion2' */
  3U,                                  /* '<S357>/Data Type Conversion' */
  16U,                                 /* '<S357>/Data Type Conversion1' */
  5U,                                  /* '<S357>/Data Type Conversion2' */
  3U,                                  /* '<S356>/Data Type Conversion' */
  15U,                                 /* '<S356>/Data Type Conversion1' */
  5U,                                  /* '<S356>/Data Type Conversion2' */
  3U,                                  /* '<S358>/Data Type Conversion' */
  17U,                                 /* '<S358>/Data Type Conversion1' */
  5U,                                  /* '<S358>/Data Type Conversion2' */
  2U,                                  /* '<S35>/Data Type Conversion2' */
  2U,                                  /* '<S35>/Data Type Conversion1' */
  1U,                                  /* '<S34>/Data Type Conversion' */
  1U,                                  /* '<S34>/Data Type Conversion1' */

  /* Start of '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S509>/Sum' */
    0.0066943799901413165,             /* '<S509>/Multiply3' */
    0.99330562000985867                /* '<S509>/Sum4' */
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
    1U,                                /* '<S359>/Data Type Conversion' */
    1U                                 /* '<S359>/Data Type Conversion1' */
  }
  ,

  /* End of '<S39>/Unknown' */

  /* Start of '<S385>/Move Control' */
  {
    0.00250000018F,                    /* '<S396>/Square' */
    0.14709F,                          /* '<S396>/Multiply' */
    -58.836F                           /* '<S396>/Gain4' */
  }
  ,

  /* End of '<S385>/Move Control' */

  /* Start of '<S385>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S392>/Vector Concatenate3' */
  }
  ,

  /* End of '<S385>/Hold Control' */

  /* Start of '<S373>/Move Control' */
  {
    0.0004F,                           /* '<S383>/Square' */
    0.00628318498F,                    /* '<S383>/Multiply' */
    -15.707963F                        /* '<S383>/Gain4' */
  }
  ,

  /* End of '<S373>/Move Control' */

  /* Start of '<S363>/Move Control' */
  {
    0.00250000018F,                    /* '<S371>/Square' */
    0.196120009F,                      /* '<S371>/Multiply' */
    -78.448F                           /* '<S371>/Gain4' */
  }
  ,

  /* End of '<S363>/Move Control' */

  /* Start of '<S451>/Move Control' */
  {
    0.00250000018F,                    /* '<S462>/Square' */
    0.14709F,                          /* '<S462>/Multiply' */
    -58.836F                           /* '<S462>/Gain4' */
  }
  ,

  /* End of '<S451>/Move Control' */

  /* Start of '<S451>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S458>/Vector Concatenate3' */
  }
  ,

  /* End of '<S451>/Hold Control' */

  /* Start of '<S441>/Move Control' */
  {
    0.00250000018F,                    /* '<S449>/Square' */
    0.196120009F,                      /* '<S449>/Multiply' */
    -78.448F                           /* '<S449>/Gain4' */
  }
  /* End of '<S441>/Move Control' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
