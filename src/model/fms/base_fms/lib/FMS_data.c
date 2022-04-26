/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1722
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Apr 26 07:59:10 2022
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

  { 0.0F, 0.0F, 1.0F },                /* '<S203>/Vector Concatenate3' */

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

  { 0.0F, 0.0F, 1.0F },                /* '<S318>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S268>/Math Function' */
  1.0F,                                /* '<S268>/Sum of Elements' */
  1.0F,                                /* '<S268>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S268>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S268>/Switch' */

  { 0.0F, 1.0F },                      /* '<S268>/Divide' */
  0.616850317F,                        /* '<S264>/Square' */
  0.645964146F,                        /* '<S264>/Multiply' */
  -1.04719758F,                        /* '<S264>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S251>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S326>/Vector Concatenate3' */
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
  3U,                                  /* '<S204>/Data Type Conversion' */
  6U,                                  /* '<S204>/Data Type Conversion1' */
  5U,                                  /* '<S204>/Data Type Conversion2' */
  3U,                                  /* '<S206>/Data Type Conversion' */
  16U,                                 /* '<S206>/Data Type Conversion1' */
  5U,                                  /* '<S206>/Data Type Conversion2' */
  3U,                                  /* '<S205>/Data Type Conversion' */
  15U,                                 /* '<S205>/Data Type Conversion1' */
  5U,                                  /* '<S205>/Data Type Conversion2' */
  3U,                                  /* '<S207>/Data Type Conversion' */
  17U,                                 /* '<S207>/Data Type Conversion1' */
  5U,                                  /* '<S207>/Data Type Conversion2' */
  2U,                                  /* '<S19>/Data Type Conversion2' */
  2U,                                  /* '<S19>/Data Type Conversion1' */

  /* Start of '<S4>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S331>/Sum' */
    0.0066943799901413165,             /* '<S331>/Multiply3' */
    0.99330562000985867                /* '<S331>/Sum4' */
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
    1U,                                /* '<S208>/Data Type Conversion' */
    1U                                 /* '<S208>/Data Type Conversion1' */
  }
  ,

  /* End of '<S24>/Unknown' */

  /* Start of '<S234>/Move Control' */
  {
    0.00250000018F,                    /* '<S245>/Square' */
    0.14709F,                          /* '<S245>/Multiply' */
    -58.836F                           /* '<S245>/Gain4' */
  }
  ,

  /* End of '<S234>/Move Control' */

  /* Start of '<S234>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S241>/Vector Concatenate3' */
  }
  ,

  /* End of '<S234>/Hold Control' */

  /* Start of '<S222>/Move Control' */
  {
    0.0004F,                           /* '<S232>/Square' */
    0.00628318498F,                    /* '<S232>/Multiply' */
    -15.707963F                        /* '<S232>/Gain4' */
  }
  ,

  /* End of '<S222>/Move Control' */

  /* Start of '<S212>/Move Control' */
  {
    0.00250000018F,                    /* '<S220>/Square' */
    0.196120009F,                      /* '<S220>/Multiply' */
    -78.448F                           /* '<S220>/Gain4' */
  }
  ,

  /* End of '<S212>/Move Control' */

  /* Start of '<S288>/Move Control' */
  {
    0.00250000018F,                    /* '<S299>/Square' */
    0.14709F,                          /* '<S299>/Multiply' */
    -58.836F                           /* '<S299>/Gain4' */
  }
  ,

  /* End of '<S288>/Move Control' */

  /* Start of '<S288>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S295>/Vector Concatenate3' */
  }
  ,

  /* End of '<S288>/Hold Control' */

  /* Start of '<S278>/Move Control' */
  {
    0.00250000018F,                    /* '<S286>/Square' */
    0.196120009F,                      /* '<S286>/Multiply' */
    -78.448F                           /* '<S286>/Gain4' */
  }
  ,

  /* End of '<S278>/Move Control' */

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
