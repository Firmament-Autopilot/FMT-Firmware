/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1691
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Apr 20 08:42:43 2022
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
  0.0016F,                             /* '<S51>/Square' */
  0.0201061927F,                       /* '<S51>/Multiply' */
  -12.566371F,                         /* '<S51>/Gain4' */
  0.0016F,                             /* '<S52>/Square' */
  0.0201061927F,                       /* '<S52>/Multiply' */
  -12.566371F,                         /* '<S52>/Gain4' */
  0.0016F,                             /* '<S115>/Square' */
  0.0201061927F,                       /* '<S115>/Multiply' */
  -12.566371F,                         /* '<S115>/Gain4' */
  0.0016F,                             /* '<S116>/Square' */
  0.0201061927F,                       /* '<S116>/Multiply' */
  -12.566371F,                         /* '<S116>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S202>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S149>/Math Function' */
  1.0F,                                /* '<S149>/Sum of Elements' */
  1.0F,                                /* '<S149>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S149>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S149>/Switch' */

  { 0.0F, 1.0F },                      /* '<S149>/Divide' */
  0.616850317F,                        /* '<S145>/Square' */
  0.645964146F,                        /* '<S145>/Multiply' */
  -1.04719758F,                        /* '<S145>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S316>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S267>/Math Function' */
  1.0F,                                /* '<S267>/Sum of Elements' */
  1.0F,                                /* '<S267>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S267>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S267>/Switch' */

  { 0.0F, 1.0F },                      /* '<S267>/Divide' */
  0.616850317F,                        /* '<S263>/Square' */
  0.645964146F,                        /* '<S263>/Multiply' */
  -1.04719758F,                        /* '<S263>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S250>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S324>/Vector Concatenate3' */
  1U,                                  /* '<S23>/Data Type Conversion' */
  12U,                                 /* '<S23>/Data Type Conversion1' */
  3U,                                  /* '<S28>/Data Type Conversion' */
  10U,                                 /* '<S28>/Data Type Conversion1' */
  5U,                                  /* '<S28>/Data Type Conversion2' */
  3U,                                  /* '<S27>/Data Type Conversion1' */
  9U,                                  /* '<S27>/Data Type Conversion2' */
  4U,                                  /* '<S27>/Data Type Conversion3' */
  3U,                                  /* '<S29>/Data Type Conversion' */
  8U,                                  /* '<S29>/Data Type Conversion1' */
  3U,                                  /* '<S29>/Data Type Conversion2' */
  3U,                                  /* '<S26>/Data Type Conversion' */
  7U,                                  /* '<S26>/Data Type Conversion1' */
  2U,                                  /* '<S26>/Data Type Conversion2' */
  3U,                                  /* '<S130>/Data Type Conversion' */
  4U,                                  /* '<S130>/Data Type Conversion1' */
  5U,                                  /* '<S130>/Data Type Conversion2' */
  1U,                                  /* '<S131>/Data Type Conversion' */
  3U,                                  /* '<S131>/Data Type Conversion1' */
  3U,                                  /* '<S203>/Data Type Conversion' */
  6U,                                  /* '<S203>/Data Type Conversion1' */
  5U,                                  /* '<S203>/Data Type Conversion2' */
  3U,                                  /* '<S205>/Data Type Conversion' */
  16U,                                 /* '<S205>/Data Type Conversion1' */
  5U,                                  /* '<S205>/Data Type Conversion2' */
  3U,                                  /* '<S204>/Data Type Conversion' */
  15U,                                 /* '<S204>/Data Type Conversion1' */
  5U,                                  /* '<S204>/Data Type Conversion2' */
  3U,                                  /* '<S206>/Data Type Conversion' */
  17U,                                 /* '<S206>/Data Type Conversion1' */
  5U,                                  /* '<S206>/Data Type Conversion2' */
  2U,                                  /* '<S19>/Data Type Conversion2' */
  2U,                                  /* '<S19>/Data Type Conversion1' */

  /* Start of '<S4>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S329>/Sum' */
    0.0066943799901413165,             /* '<S329>/Multiply3' */
    0.99330562000985867                /* '<S329>/Sum4' */
  }
  ,

  /* End of '<S4>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */

  /* Start of '<S17>/Unknown' */
  {
    1U,                                /* '<S25>/Data Type Conversion' */
    1U                                 /* '<S25>/Data Type Conversion1' */
  }
  ,

  /* End of '<S17>/Unknown' */

  /* Start of '<S21>/Unknown' */
  {
    1U,                                /* '<S30>/Data Type Conversion' */
    1U                                 /* '<S30>/Data Type Conversion1' */
  }
  ,

  /* End of '<S21>/Unknown' */

  /* Start of '<S93>/Move Control' */
  {
    0.00250000018F,                    /* '<S104>/Square' */
    0.14709F,                          /* '<S104>/Multiply' */
    -58.836F                           /* '<S104>/Gain4' */
  }
  ,

  /* End of '<S93>/Move Control' */

  /* Start of '<S93>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S100>/Vector Concatenate3' */
  }
  ,

  /* End of '<S93>/Hold Control' */

  /* Start of '<S80>/Move Control' */
  {
    0.0004F,                           /* '<S90>/Square' */
    0.00628318498F,                    /* '<S90>/Multiply' */
    -15.707963F                        /* '<S90>/Gain4' */
  }
  ,

  /* End of '<S80>/Move Control' */

  /* Start of '<S69>/Move Control' */
  {
    0.00250000018F,                    /* '<S77>/Square' */
    0.196120009F,                      /* '<S77>/Multiply' */
    -78.448F                           /* '<S77>/Gain4' */
  }
  ,

  /* End of '<S69>/Move Control' */

  /* Start of '<S53>/Move Control' */
  {
    0.0004F,                           /* '<S63>/Square' */
    0.00628318498F,                    /* '<S63>/Multiply' */
    -15.707963F                        /* '<S63>/Gain4' */
  }
  ,

  /* End of '<S53>/Move Control' */

  /* Start of '<S36>/Move Control' */
  {
    0.00250000018F,                    /* '<S44>/Square' */
    0.196120009F,                      /* '<S44>/Multiply' */
    -78.448F                           /* '<S44>/Gain4' */
  }
  ,

  /* End of '<S36>/Move Control' */

  /* Start of '<S117>/Move Control' */
  {
    0.0004F,                           /* '<S127>/Square' */
    0.00628318498F,                    /* '<S127>/Multiply' */
    -15.707963F                        /* '<S127>/Gain4' */
  }
  ,

  /* End of '<S117>/Move Control' */

  /* Start of '<S22>/Unknown' */
  {
    1U,                                /* '<S132>/Data Type Conversion' */
    1U                                 /* '<S132>/Data Type Conversion1' */
  }
  ,

  /* End of '<S22>/Unknown' */

  /* Start of '<S173>/Move Control' */
  {
    0.00250000018F,                    /* '<S184>/Square' */
    0.14709F,                          /* '<S184>/Multiply' */
    -58.836F                           /* '<S184>/Gain4' */
  }
  ,

  /* End of '<S173>/Move Control' */

  /* Start of '<S173>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S180>/Vector Concatenate3' */
  }
  ,

  /* End of '<S173>/Hold Control' */

  /* Start of '<S163>/Move Control' */
  {
    0.00250000018F,                    /* '<S171>/Square' */
    0.196120009F,                      /* '<S171>/Multiply' */
    -78.448F                           /* '<S171>/Gain4' */
  }
  ,

  /* End of '<S163>/Move Control' */

  /* Start of '<S24>/Unknown' */
  {
    1U,                                /* '<S207>/Data Type Conversion' */
    1U                                 /* '<S207>/Data Type Conversion1' */
  }
  ,

  /* End of '<S24>/Unknown' */

  /* Start of '<S233>/Move Control' */
  {
    0.00250000018F,                    /* '<S244>/Square' */
    0.14709F,                          /* '<S244>/Multiply' */
    -58.836F                           /* '<S244>/Gain4' */
  }
  ,

  /* End of '<S233>/Move Control' */

  /* Start of '<S233>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S240>/Vector Concatenate3' */
  }
  ,

  /* End of '<S233>/Hold Control' */

  /* Start of '<S221>/Move Control' */
  {
    0.0004F,                           /* '<S231>/Square' */
    0.00628318498F,                    /* '<S231>/Multiply' */
    -15.707963F                        /* '<S231>/Gain4' */
  }
  ,

  /* End of '<S221>/Move Control' */

  /* Start of '<S211>/Move Control' */
  {
    0.00250000018F,                    /* '<S219>/Square' */
    0.196120009F,                      /* '<S219>/Multiply' */
    -78.448F                           /* '<S219>/Gain4' */
  }
  ,

  /* End of '<S211>/Move Control' */

  /* Start of '<S287>/Move Control' */
  {
    0.00250000018F,                    /* '<S298>/Square' */
    0.14709F,                          /* '<S298>/Multiply' */
    -58.836F                           /* '<S298>/Gain4' */
  }
  ,

  /* End of '<S287>/Move Control' */

  /* Start of '<S287>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S294>/Vector Concatenate3' */
  }
  ,

  /* End of '<S287>/Hold Control' */

  /* Start of '<S277>/Move Control' */
  {
    0.00250000018F,                    /* '<S285>/Square' */
    0.196120009F,                      /* '<S285>/Multiply' */
    -78.448F                           /* '<S285>/Gain4' */
  }
  ,

  /* End of '<S277>/Move Control' */

  /* Start of '<S2>/Disarm' */
  {
    1U,                                /* '<S18>/Data Type Conversion' */
    1U                                 /* '<S18>/Data Type Conversion1' */
  }
  /* End of '<S2>/Disarm' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
