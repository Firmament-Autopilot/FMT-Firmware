/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1952
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat May 13 10:18:22 2023
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
  1.9966471893352524,                  /* '<S308>/Sum' */
  0.0066943799901413165,               /* '<S308>/Multiply3' */
  0.99330562000985867,                 /* '<S308>/Sum4' */
  0.0,                                 /* '<S307>/deg2rad2' */
  0.0,                                 /* '<S310>/SinCos' */
  1.0,                                 /* '<S310>/SinCos' */
  0.0016F,                             /* '<S63>/Square' */
  0.0201061927F,                       /* '<S63>/Multiply' */
  -12.566371F,                         /* '<S63>/Gain4' */
  0.0016F,                             /* '<S64>/Square' */
  0.0201061927F,                       /* '<S64>/Multiply' */
  -12.566371F,                         /* '<S64>/Gain4' */
  0.0016F,                             /* '<S131>/Square' */
  0.0201061927F,                       /* '<S131>/Multiply' */
  -12.566371F,                         /* '<S131>/Gain4' */
  0.0016F,                             /* '<S132>/Square' */
  0.0201061927F,                       /* '<S132>/Multiply' */
  -12.566371F,                         /* '<S132>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S221>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S167>/Math Function' */
  1.0F,                                /* '<S167>/Sum of Elements' */
  1.0F,                                /* '<S167>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S167>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S167>/Switch' */

  { 0.0F, 1.0F },                      /* '<S167>/Divide' */
  0.616850317F,                        /* '<S163>/Square' */
  0.645964146F,                        /* '<S163>/Multiply' */
  -1.04719758F,                        /* '<S163>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S301>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S302>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S298>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S294>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S232>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S234>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S323>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S325>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S441>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S391>/Math Function' */
  1.0F,                                /* '<S391>/Sum of Elements' */
  1.0F,                                /* '<S391>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S391>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S391>/Switch' */

  { 0.0F, 1.0F },                      /* '<S391>/Divide' */
  0.616850317F,                        /* '<S387>/Square' */
  0.645964146F,                        /* '<S387>/Multiply' */
  -1.04719758F,                        /* '<S387>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S374>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S449>/Vector Concatenate3' */
  1U,                                  /* '<S35>/Data Type Conversion' */
  12U,                                 /* '<S35>/Data Type Conversion1' */
  3U,                                  /* '<S40>/Data Type Conversion' */
  10U,                                 /* '<S40>/Data Type Conversion1' */
  5U,                                  /* '<S40>/Data Type Conversion2' */
  3U,                                  /* '<S39>/Data Type Conversion1' */
  9U,                                  /* '<S39>/Data Type Conversion2' */
  4U,                                  /* '<S39>/Data Type Conversion3' */
  3U,                                  /* '<S41>/Data Type Conversion' */
  8U,                                  /* '<S41>/Data Type Conversion1' */
  3U,                                  /* '<S41>/Data Type Conversion2' */
  3U,                                  /* '<S38>/Data Type Conversion' */
  7U,                                  /* '<S38>/Data Type Conversion1' */
  2U,                                  /* '<S38>/Data Type Conversion2' */
  3U,                                  /* '<S150>/Data Type Conversion' */
  4U,                                  /* '<S150>/Data Type Conversion1' */
  5U,                                  /* '<S150>/Data Type Conversion2' */
  3U,                                  /* '<S147>/Data Type Conversion' */
  3U,                                  /* '<S147>/Data Type Conversion1' */
  6U,                                  /* '<S147>/Data Type Conversion2' */
  3U,                                  /* '<S326>/Data Type Conversion' */
  6U,                                  /* '<S326>/Data Type Conversion1' */
  5U,                                  /* '<S326>/Data Type Conversion2' */
  3U,                                  /* '<S328>/Data Type Conversion' */
  16U,                                 /* '<S328>/Data Type Conversion1' */
  5U,                                  /* '<S328>/Data Type Conversion2' */
  3U,                                  /* '<S327>/Data Type Conversion' */
  15U,                                 /* '<S327>/Data Type Conversion1' */
  5U,                                  /* '<S327>/Data Type Conversion2' */
  3U,                                  /* '<S329>/Data Type Conversion' */
  17U,                                 /* '<S329>/Data Type Conversion1' */
  5U,                                  /* '<S329>/Data Type Conversion2' */
  2U,                                  /* '<S32>/Data Type Conversion2' */
  2U,                                  /* '<S32>/Data Type Conversion1' */

  /* Start of '<S5>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S455>/Sum' */
    0.0066943799901413165,             /* '<S455>/Multiply3' */
    0.99330562000985867                /* '<S455>/Sum4' */
  }
  ,

  /* End of '<S5>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */

  /* Start of '<S29>/Unknown' */
  {
    1U,                                /* '<S37>/Data Type Conversion' */
    1U                                 /* '<S37>/Data Type Conversion1' */
  }
  ,

  /* End of '<S29>/Unknown' */

  /* Start of '<S33>/Unknown' */
  {
    1U,                                /* '<S42>/Data Type Conversion' */
    1U                                 /* '<S42>/Data Type Conversion1' */
  }
  ,

  /* End of '<S33>/Unknown' */

  /* Start of '<S109>/Move Control' */
  {
    0.00250000018F,                    /* '<S120>/Square' */
    0.14709F,                          /* '<S120>/Multiply' */
    -58.836F                           /* '<S120>/Gain4' */
  }
  ,

  /* End of '<S109>/Move Control' */

  /* Start of '<S109>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S116>/Vector Concatenate3' */
  }
  ,

  /* End of '<S109>/Hold Control' */

  /* Start of '<S96>/Move Control' */
  {
    0.0004F,                           /* '<S106>/Square' */
    0.00628318498F,                    /* '<S106>/Multiply' */
    -15.707963F                        /* '<S106>/Gain4' */
  }
  ,

  /* End of '<S96>/Move Control' */

  /* Start of '<S65>/Move Control' */
  {
    0.0004F,                           /* '<S75>/Square' */
    0.00628318498F,                    /* '<S75>/Multiply' */
    -15.707963F                        /* '<S75>/Gain4' */
  }
  ,

  /* End of '<S65>/Move Control' */

  /* Start of '<S133>/Move Control' */
  {
    0.0004F,                           /* '<S143>/Square' */
    0.00628318498F,                    /* '<S143>/Multiply' */
    -15.707963F                        /* '<S143>/Gain4' */
  }
  ,

  /* End of '<S133>/Move Control' */

  /* Start of '<S34>/Unknown' */
  {
    1U,                                /* '<S148>/Data Type Conversion' */
    1U                                 /* '<S148>/Data Type Conversion1' */
  }
  ,

  /* End of '<S34>/Unknown' */

  /* Start of '<S191>/Move Control' */
  {
    0.00250000018F,                    /* '<S202>/Square' */
    0.14709F,                          /* '<S202>/Multiply' */
    -58.836F                           /* '<S202>/Gain4' */
  }
  ,

  /* End of '<S191>/Move Control' */

  /* Start of '<S191>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S198>/Vector Concatenate3' */
  }
  ,

  /* End of '<S191>/Hold Control' */

  /* Start of '<S181>/Move Control' */
  {
    0.00250000018F,                    /* '<S189>/Square' */
    0.196120009F,                      /* '<S189>/Multiply' */
    -78.448F                           /* '<S189>/Gain4' */
  }
  ,

  /* End of '<S181>/Move Control' */

  /* Start of '<S36>/Unknown' */
  {
    1U,                                /* '<S330>/Data Type Conversion' */
    1U                                 /* '<S330>/Data Type Conversion1' */
  }
  ,

  /* End of '<S36>/Unknown' */

  /* Start of '<S356>/Move Control' */
  {
    0.00250000018F,                    /* '<S367>/Square' */
    0.14709F,                          /* '<S367>/Multiply' */
    -58.836F                           /* '<S367>/Gain4' */
  }
  ,

  /* End of '<S356>/Move Control' */

  /* Start of '<S356>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S363>/Vector Concatenate3' */
  }
  ,

  /* End of '<S356>/Hold Control' */

  /* Start of '<S344>/Move Control' */
  {
    0.0004F,                           /* '<S354>/Square' */
    0.00628318498F,                    /* '<S354>/Multiply' */
    -15.707963F                        /* '<S354>/Gain4' */
  }
  ,

  /* End of '<S344>/Move Control' */

  /* Start of '<S334>/Move Control' */
  {
    0.00250000018F,                    /* '<S342>/Square' */
    0.196120009F,                      /* '<S342>/Multiply' */
    -78.448F                           /* '<S342>/Gain4' */
  }
  ,

  /* End of '<S334>/Move Control' */

  /* Start of '<S411>/Move Control' */
  {
    0.00250000018F,                    /* '<S422>/Square' */
    0.14709F,                          /* '<S422>/Multiply' */
    -58.836F                           /* '<S422>/Gain4' */
  }
  ,

  /* End of '<S411>/Move Control' */

  /* Start of '<S411>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S418>/Vector Concatenate3' */
  }
  ,

  /* End of '<S411>/Hold Control' */

  /* Start of '<S401>/Move Control' */
  {
    0.00250000018F,                    /* '<S409>/Square' */
    0.196120009F,                      /* '<S409>/Multiply' */
    -78.448F                           /* '<S409>/Gain4' */
  }
  ,

  /* End of '<S401>/Move Control' */

  /* Start of '<S27>/Disarm' */
  {
    1U,                                /* '<S31>/Data Type Conversion' */
    1U                                 /* '<S31>/Data Type Conversion1' */
  }
  /* End of '<S27>/Disarm' */
};

/* Constant parameters (default storage) */
const ConstP_FMS_T FMS_ConstP = {
  /* Pooled Parameter (Expression: [4,4,2])
   * Referenced by:
   *   '<S287>/Saturation1'
   *   '<S289>/Saturation'
   *   '<S290>/Saturation1'
   */
  { 4.0F, 4.0F, 2.0F },

  /* Pooled Parameter (Expression: [-4,-4,-2])
   * Referenced by:
   *   '<S287>/Saturation1'
   *   '<S289>/Saturation'
   *   '<S290>/Saturation1'
   */
  { -4.0F, -4.0F, -2.0F }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
