/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1643
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Mar 17 07:58:12 2022
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
  0.0016F,                             /* '<S52>/Square' */
  0.0201061927F,                       /* '<S52>/Multiply' */
  -12.566371F,                         /* '<S52>/Gain4' */
  0.0016F,                             /* '<S53>/Square' */
  0.0201061927F,                       /* '<S53>/Multiply' */
  -12.566371F,                         /* '<S53>/Gain4' */
  0.0016F,                             /* '<S116>/Square' */
  0.0201061927F,                       /* '<S116>/Multiply' */
  -12.566371F,                         /* '<S116>/Gain4' */
  0.0016F,                             /* '<S117>/Square' */
  0.0201061927F,                       /* '<S117>/Multiply' */
  -12.566371F,                         /* '<S117>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S203>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S150>/Math Function' */
  1.0F,                                /* '<S150>/Sum of Elements' */
  1.0F,                                /* '<S150>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S150>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S150>/Switch' */

  { 0.0F, 1.0F },                      /* '<S150>/Divide' */
  1.0F,                                /* '<S146>/Square' */
  0.785398185F,                        /* '<S146>/Multiply' */
  -0.785398185F,                       /* '<S146>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S317>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S268>/Math Function' */
  1.0F,                                /* '<S268>/Sum of Elements' */
  1.0F,                                /* '<S268>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S268>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S268>/Switch' */

  { 0.0F, 1.0F },                      /* '<S268>/Divide' */
  1.0F,                                /* '<S264>/Square' */
  0.785398185F,                        /* '<S264>/Multiply' */
  -0.785398185F,                       /* '<S264>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S251>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S325>/Vector Concatenate3' */
  1U,                                  /* '<S24>/Data Type Conversion' */
  12U,                                 /* '<S24>/Data Type Conversion1' */
  3U,                                  /* '<S29>/Data Type Conversion' */
  10U,                                 /* '<S29>/Data Type Conversion1' */
  5U,                                  /* '<S29>/Data Type Conversion2' */
  3U,                                  /* '<S28>/Data Type Conversion1' */
  9U,                                  /* '<S28>/Data Type Conversion2' */
  4U,                                  /* '<S28>/Data Type Conversion3' */
  3U,                                  /* '<S30>/Data Type Conversion' */
  8U,                                  /* '<S30>/Data Type Conversion1' */
  3U,                                  /* '<S30>/Data Type Conversion2' */
  3U,                                  /* '<S27>/Data Type Conversion' */
  7U,                                  /* '<S27>/Data Type Conversion1' */
  2U,                                  /* '<S27>/Data Type Conversion2' */
  3U,                                  /* '<S131>/Data Type Conversion' */
  4U,                                  /* '<S131>/Data Type Conversion1' */
  5U,                                  /* '<S131>/Data Type Conversion2' */
  1U,                                  /* '<S132>/Data Type Conversion' */
  3U,                                  /* '<S132>/Data Type Conversion1' */
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
  2U,                                  /* '<S20>/Data Type Conversion2' */
  2U,                                  /* '<S20>/Data Type Conversion1' */

  /* Start of '<S4>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S329>/Sum' */
    0.0066943799901413165,             /* '<S329>/Multiply3' */
    0.99330562000985867                /* '<S329>/Sum4' */
  }
  ,

  /* End of '<S4>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */

  /* Start of '<S18>/Unknown' */
  {
    1U,                                /* '<S26>/Data Type Conversion' */
    1U                                 /* '<S26>/Data Type Conversion1' */
  }
  ,

  /* End of '<S18>/Unknown' */

  /* Start of '<S22>/Unknown' */
  {
    1U,                                /* '<S31>/Data Type Conversion' */
    1U                                 /* '<S31>/Data Type Conversion1' */
  }
  ,

  /* End of '<S22>/Unknown' */

  /* Start of '<S94>/Move Control' */
  {
    0.00250000018F,                    /* '<S105>/Square' */
    0.14709F,                          /* '<S105>/Multiply' */
    -58.836F                           /* '<S105>/Gain4' */
  }
  ,

  /* End of '<S94>/Move Control' */

  /* Start of '<S94>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S101>/Vector Concatenate3' */
  }
  ,

  /* End of '<S94>/Hold Control' */

  /* Start of '<S81>/Move Control' */
  {
    0.0004F,                           /* '<S91>/Square' */
    0.00628318498F,                    /* '<S91>/Multiply' */
    -15.707963F                        /* '<S91>/Gain4' */
  }
  ,

  /* End of '<S81>/Move Control' */

  /* Start of '<S70>/Move Control' */
  {
    0.00250000018F,                    /* '<S78>/Square' */
    0.196120009F,                      /* '<S78>/Multiply' */
    -78.448F                           /* '<S78>/Gain4' */
  }
  ,

  /* End of '<S70>/Move Control' */

  /* Start of '<S54>/Move Control' */
  {
    0.0004F,                           /* '<S64>/Square' */
    0.00628318498F,                    /* '<S64>/Multiply' */
    -15.707963F                        /* '<S64>/Gain4' */
  }
  ,

  /* End of '<S54>/Move Control' */

  /* Start of '<S37>/Move Control' */
  {
    0.00250000018F,                    /* '<S45>/Square' */
    0.196120009F,                      /* '<S45>/Multiply' */
    -78.448F                           /* '<S45>/Gain4' */
  }
  ,

  /* End of '<S37>/Move Control' */

  /* Start of '<S118>/Move Control' */
  {
    0.0004F,                           /* '<S128>/Square' */
    0.00628318498F,                    /* '<S128>/Multiply' */
    -15.707963F                        /* '<S128>/Gain4' */
  }
  ,

  /* End of '<S118>/Move Control' */

  /* Start of '<S23>/Unknown' */
  {
    1U,                                /* '<S133>/Data Type Conversion' */
    1U                                 /* '<S133>/Data Type Conversion1' */
  }
  ,

  /* End of '<S23>/Unknown' */

  /* Start of '<S174>/Move Control' */
  {
    0.00250000018F,                    /* '<S185>/Square' */
    0.14709F,                          /* '<S185>/Multiply' */
    -58.836F                           /* '<S185>/Gain4' */
  }
  ,

  /* End of '<S174>/Move Control' */

  /* Start of '<S174>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S181>/Vector Concatenate3' */
  }
  ,

  /* End of '<S174>/Hold Control' */

  /* Start of '<S164>/Move Control' */
  {
    0.00250000018F,                    /* '<S172>/Square' */
    0.196120009F,                      /* '<S172>/Multiply' */
    -78.448F                           /* '<S172>/Gain4' */
  }
  ,

  /* End of '<S164>/Move Control' */

  /* Start of '<S25>/Unknown' */
  {
    1U,                                /* '<S208>/Data Type Conversion' */
    1U                                 /* '<S208>/Data Type Conversion1' */
  }
  ,

  /* End of '<S25>/Unknown' */

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
    1U,                                /* '<S19>/Data Type Conversion' */
    1U                                 /* '<S19>/Data Type Conversion1' */
  }
  /* End of '<S2>/Disarm' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
