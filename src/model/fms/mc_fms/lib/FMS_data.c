/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2108
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Jun 15 10:50:29 2024
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
  1.9966471893352524,                  /* '<S315>/Sum' */
  0.0066943799901413165,               /* '<S315>/Multiply3' */
  0.99330562000985867,                 /* '<S315>/Sum4' */
  0.0,                                 /* '<S314>/deg2rad2' */
  0.0,                                 /* '<S317>/SinCos' */
  1.0,                                 /* '<S317>/SinCos' */
  0.00250000018F,                      /* '<S120>/Square' */
  0.14709F,                            /* '<S120>/Multiply' */
  -58.836F,                            /* '<S120>/Gain4' */
  0.0016F,                             /* '<S66>/Square' */
  0.0201061927F,                       /* '<S66>/Multiply' */
  -12.566371F,                         /* '<S66>/Gain4' */
  0.0016F,                             /* '<S65>/Square' */
  0.0201061927F,                       /* '<S65>/Multiply' */
  -12.566371F,                         /* '<S65>/Gain4' */
  0.0016F,                             /* '<S132>/Square' */
  0.0201061927F,                       /* '<S132>/Multiply' */
  -12.566371F,                         /* '<S132>/Gain4' */
  0.0016F,                             /* '<S131>/Square' */
  0.0201061927F,                       /* '<S131>/Multiply' */
  -12.566371F,                         /* '<S131>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S227>/Vector Concatenate3' */

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

  { 0.0F, 0.0F, 1.0F },                /* '<S308>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S309>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S305>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S301>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S239>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S241>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S330>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S332>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S461>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S401>/Math Function' */
  1.0F,                                /* '<S401>/Sum of Elements' */
  1.0F,                                /* '<S401>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S401>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S401>/Switch' */

  { 0.0F, 1.0F },                      /* '<S401>/Divide' */
  0.616850317F,                        /* '<S397>/Square' */
  0.645964146F,                        /* '<S397>/Multiply' */
  -1.04719758F,                        /* '<S397>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S384>/Vector Concatenate3' */
  0.122499995F,                        /* '<S380>/Square' */
  1.20123494F,                         /* '<S380>/Multiply' */
  -9.806F,                             /* '<S380>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S472>/Vector Concatenate3' */
  0.122499995F,                        /* '<S468>/Square' */
  1.20123494F,                         /* '<S468>/Multiply' */
  -9.806F,                             /* '<S468>/Gain4' */
  1U,                                  /* '<S36>/Data Type Conversion' */
  12U,                                 /* '<S36>/Data Type Conversion1' */
  3U,                                  /* '<S41>/Data Type Conversion' */
  10U,                                 /* '<S41>/Data Type Conversion1' */
  5U,                                  /* '<S41>/Data Type Conversion2' */
  3U,                                  /* '<S40>/Data Type Conversion1' */
  9U,                                  /* '<S40>/Data Type Conversion2' */
  4U,                                  /* '<S40>/Data Type Conversion3' */
  3U,                                  /* '<S42>/Data Type Conversion' */
  8U,                                  /* '<S42>/Data Type Conversion1' */
  3U,                                  /* '<S42>/Data Type Conversion2' */
  3U,                                  /* '<S39>/Data Type Conversion' */
  7U,                                  /* '<S39>/Data Type Conversion1' */
  2U,                                  /* '<S39>/Data Type Conversion2' */
  3U,                                  /* '<S150>/Data Type Conversion' */
  4U,                                  /* '<S150>/Data Type Conversion1' */
  5U,                                  /* '<S150>/Data Type Conversion2' */
  3U,                                  /* '<S147>/Data Type Conversion' */
  3U,                                  /* '<S147>/Data Type Conversion1' */
  6U,                                  /* '<S147>/Data Type Conversion2' */
  3U,                                  /* '<S333>/Data Type Conversion' */
  6U,                                  /* '<S333>/Data Type Conversion1' */
  5U,                                  /* '<S333>/Data Type Conversion2' */
  3U,                                  /* '<S335>/Data Type Conversion' */
  16U,                                 /* '<S335>/Data Type Conversion1' */
  5U,                                  /* '<S335>/Data Type Conversion2' */
  3U,                                  /* '<S334>/Data Type Conversion' */
  15U,                                 /* '<S334>/Data Type Conversion1' */
  5U,                                  /* '<S334>/Data Type Conversion2' */
  3U,                                  /* '<S336>/Data Type Conversion' */
  17U,                                 /* '<S336>/Data Type Conversion1' */
  5U,                                  /* '<S336>/Data Type Conversion2' */
  2U,                                  /* '<S33>/Data Type Conversion2' */
  2U,                                  /* '<S33>/Data Type Conversion1' */
  1U,                                  /* '<S32>/Data Type Conversion' */
  1U,                                  /* '<S32>/Data Type Conversion1' */

  /* Start of '<S5>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S478>/Sum' */
    0.0066943799901413165,             /* '<S478>/Multiply3' */
    0.99330562000985867                /* '<S478>/Sum4' */
  }
  ,

  /* End of '<S5>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */

  /* Start of '<S30>/Unknown' */
  {
    1U,                                /* '<S38>/Data Type Conversion' */
    1U                                 /* '<S38>/Data Type Conversion1' */
  }
  ,

  /* End of '<S30>/Unknown' */

  /* Start of '<S34>/Unknown' */
  {
    1U,                                /* '<S43>/Data Type Conversion' */
    1U                                 /* '<S43>/Data Type Conversion1' */
  }
  ,

  /* End of '<S34>/Unknown' */

  /* Start of '<S108>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S115>/Vector Concatenate3' */
  }
  ,

  /* End of '<S108>/Hold Control' */

  /* Start of '<S95>/Move Control' */
  {
    0.0004F,                           /* '<S105>/Square' */
    0.00628318498F,                    /* '<S105>/Multiply' */
    -15.707963F                        /* '<S105>/Gain4' */
  }
  ,

  /* End of '<S95>/Move Control' */

  /* Start of '<S67>/Move Control' */
  {
    0.0004F,                           /* '<S77>/Square' */
    0.00628318498F,                    /* '<S77>/Multiply' */
    -15.707963F                        /* '<S77>/Gain4' */
  }
  ,

  /* End of '<S67>/Move Control' */

  /* Start of '<S133>/Move Control' */
  {
    0.0004F,                           /* '<S143>/Square' */
    0.00628318498F,                    /* '<S143>/Multiply' */
    -15.707963F                        /* '<S143>/Gain4' */
  }
  ,

  /* End of '<S133>/Move Control' */

  /* Start of '<S35>/Unknown' */
  {
    1U,                                /* '<S148>/Data Type Conversion' */
    1U                                 /* '<S148>/Data Type Conversion1' */
  }
  ,

  /* End of '<S35>/Unknown' */

  /* Start of '<S197>/Move Control' */
  {
    0.00250000018F,                    /* '<S208>/Square' */
    0.14709F,                          /* '<S208>/Multiply' */
    -58.836F                           /* '<S208>/Gain4' */
  }
  ,

  /* End of '<S197>/Move Control' */

  /* Start of '<S197>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S204>/Vector Concatenate3' */
  }
  ,

  /* End of '<S197>/Hold Control' */

  /* Start of '<S187>/Move Control' */
  {
    0.00250000018F,                    /* '<S195>/Square' */
    0.196120009F,                      /* '<S195>/Multiply' */
    -78.448F                           /* '<S195>/Gain4' */
  }
  ,

  /* End of '<S187>/Move Control' */

  /* Start of '<S37>/Unknown' */
  {
    1U,                                /* '<S337>/Data Type Conversion' */
    1U                                 /* '<S337>/Data Type Conversion1' */
  }
  ,

  /* End of '<S37>/Unknown' */

  /* Start of '<S363>/Move Control' */
  {
    0.00250000018F,                    /* '<S374>/Square' */
    0.14709F,                          /* '<S374>/Multiply' */
    -58.836F                           /* '<S374>/Gain4' */
  }
  ,

  /* End of '<S363>/Move Control' */

  /* Start of '<S363>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S370>/Vector Concatenate3' */
  }
  ,

  /* End of '<S363>/Hold Control' */

  /* Start of '<S351>/Move Control' */
  {
    0.0004F,                           /* '<S361>/Square' */
    0.00628318498F,                    /* '<S361>/Multiply' */
    -15.707963F                        /* '<S361>/Gain4' */
  }
  ,

  /* End of '<S351>/Move Control' */

  /* Start of '<S341>/Move Control' */
  {
    0.00250000018F,                    /* '<S349>/Square' */
    0.196120009F,                      /* '<S349>/Multiply' */
    -78.448F                           /* '<S349>/Gain4' */
  }
  ,

  /* End of '<S341>/Move Control' */

  /* Start of '<S431>/Move Control' */
  {
    0.00250000018F,                    /* '<S442>/Square' */
    0.14709F,                          /* '<S442>/Multiply' */
    -58.836F                           /* '<S442>/Gain4' */
  }
  ,

  /* End of '<S431>/Move Control' */

  /* Start of '<S431>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S438>/Vector Concatenate3' */
  }
  ,

  /* End of '<S431>/Hold Control' */

  /* Start of '<S421>/Move Control' */
  {
    0.00250000018F,                    /* '<S429>/Square' */
    0.196120009F,                      /* '<S429>/Multiply' */
    -78.448F                           /* '<S429>/Gain4' */
  }
  /* End of '<S421>/Move Control' */
};

/* Constant parameters (default storage) */
const ConstP_FMS_T FMS_ConstP = {
  /* Pooled Parameter (Expression: [4,4,2])
   * Referenced by:
   *   '<S294>/Saturation1'
   *   '<S296>/Saturation'
   *   '<S297>/Saturation1'
   */
  { 4.0F, 4.0F, 2.0F },

  /* Pooled Parameter (Expression: [-4,-4,-2])
   * Referenced by:
   *   '<S294>/Saturation1'
   *   '<S296>/Saturation'
   *   '<S297>/Saturation1'
   */
  { -4.0F, -4.0F, -2.0F }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
