/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2127
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat May  4 16:24:12 2024
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
  1.9966471893352524,                  /* '<S262>/Sum' */
  0.0066943799901413165,               /* '<S262>/Multiply3' */
  0.99330562000985867,                 /* '<S262>/Sum4' */
  0.0,                                 /* '<S261>/deg2rad2' */
  0.0,                                 /* '<S264>/SinCos' */
  1.0,                                 /* '<S264>/SinCos' */

  { 0.0F, 0.0F, 1.0F },                /* '<S76>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S174>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S114>/Math Function' */
  1.0F,                                /* '<S114>/Sum of Elements' */
  1.0F,                                /* '<S114>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S114>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S114>/Switch' */

  { 0.0F, 1.0F },                      /* '<S114>/Divide' */
  0.616850317F,                        /* '<S110>/Square' */
  0.645964146F,                        /* '<S110>/Multiply' */
  -1.04719758F,                        /* '<S110>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S255>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S256>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S252>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S248>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S186>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S188>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S277>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S279>/Vector Concatenate3' */
  0.0004F,                             /* '<S308>/Square' */
  0.00628318498F,                      /* '<S308>/Multiply' */
  -15.707963F,                         /* '<S308>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S408>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S348>/Math Function' */
  1.0F,                                /* '<S348>/Sum of Elements' */
  1.0F,                                /* '<S348>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S348>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S348>/Switch' */

  { 0.0F, 1.0F },                      /* '<S348>/Divide' */
  0.616850317F,                        /* '<S344>/Square' */
  0.645964146F,                        /* '<S344>/Multiply' */
  -1.04719758F,                        /* '<S344>/Gain4' */
  0.00250000018F,                      /* '<S389>/Square' */
  0.14709F,                            /* '<S389>/Multiply' */
  -58.836F,                            /* '<S389>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S331>/Vector Concatenate3' */
  0.122499995F,                        /* '<S327>/Square' */
  1.20123494F,                         /* '<S327>/Multiply' */
  -9.806F,                             /* '<S327>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S419>/Vector Concatenate3' */
  0.122499995F,                        /* '<S415>/Square' */
  1.20123494F,                         /* '<S415>/Multiply' */
  -9.806F,                             /* '<S415>/Gain4' */
  1U,                                  /* '<S35>/Data Type Conversion' */
  12U,                                 /* '<S35>/Data Type Conversion1' */
  3U,                                  /* '<S39>/Data Type Conversion' */
  10U,                                 /* '<S39>/Data Type Conversion1' */
  5U,                                  /* '<S39>/Data Type Conversion2' */
  3U,                                  /* '<S38>/Data Type Conversion1' */
  9U,                                  /* '<S38>/Data Type Conversion2' */
  4U,                                  /* '<S38>/Data Type Conversion3' */
  3U,                                  /* '<S40>/Data Type Conversion' */
  8U,                                  /* '<S40>/Data Type Conversion1' */
  3U,                                  /* '<S40>/Data Type Conversion2' */
  3U,                                  /* '<S97>/Data Type Conversion' */
  4U,                                  /* '<S97>/Data Type Conversion1' */
  5U,                                  /* '<S97>/Data Type Conversion2' */
  3U,                                  /* '<S94>/Data Type Conversion' */
  3U,                                  /* '<S94>/Data Type Conversion1' */
  6U,                                  /* '<S94>/Data Type Conversion2' */
  3U,                                  /* '<S280>/Data Type Conversion' */
  6U,                                  /* '<S280>/Data Type Conversion1' */
  5U,                                  /* '<S280>/Data Type Conversion2' */
  3U,                                  /* '<S282>/Data Type Conversion' */
  16U,                                 /* '<S282>/Data Type Conversion1' */
  5U,                                  /* '<S282>/Data Type Conversion2' */
  3U,                                  /* '<S281>/Data Type Conversion' */
  15U,                                 /* '<S281>/Data Type Conversion1' */
  5U,                                  /* '<S281>/Data Type Conversion2' */
  3U,                                  /* '<S283>/Data Type Conversion' */
  17U,                                 /* '<S283>/Data Type Conversion1' */
  5U,                                  /* '<S283>/Data Type Conversion2' */
  2U,                                  /* '<S32>/Data Type Conversion2' */
  2U,                                  /* '<S32>/Data Type Conversion1' */
  1U,                                  /* '<S31>/Data Type Conversion' */
  1U,                                  /* '<S31>/Data Type Conversion1' */

  /* Start of '<S5>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S425>/Sum' */
    0.0066943799901413165,             /* '<S425>/Multiply3' */
    0.99330562000985867                /* '<S425>/Sum4' */
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
    1U,                                /* '<S41>/Data Type Conversion' */
    1U                                 /* '<S41>/Data Type Conversion1' */
  }
  ,

  /* End of '<S33>/Unknown' */

  /* Start of '<S34>/Unknown' */
  {
    1U,                                /* '<S95>/Data Type Conversion' */
    1U                                 /* '<S95>/Data Type Conversion1' */
  }
  ,

  /* End of '<S34>/Unknown' */

  /* Start of '<S144>/Move Control' */
  {
    0.00250000018F,                    /* '<S155>/Square' */
    0.14709F,                          /* '<S155>/Multiply' */
    -58.836F                           /* '<S155>/Gain4' */
  }
  ,

  /* End of '<S144>/Move Control' */

  /* Start of '<S144>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S151>/Vector Concatenate3' */
  }
  ,

  /* End of '<S144>/Hold Control' */

  /* Start of '<S134>/Move Control' */
  {
    0.00250000018F,                    /* '<S142>/Square' */
    0.196120009F,                      /* '<S142>/Multiply' */
    -78.448F                           /* '<S142>/Gain4' */
  }
  ,

  /* End of '<S134>/Move Control' */

  /* Start of '<S36>/Unknown' */
  {
    1U,                                /* '<S284>/Data Type Conversion' */
    1U                                 /* '<S284>/Data Type Conversion1' */
  }
  ,

  /* End of '<S36>/Unknown' */

  /* Start of '<S310>/Move Control' */
  {
    0.00250000018F,                    /* '<S321>/Square' */
    0.14709F,                          /* '<S321>/Multiply' */
    -58.836F                           /* '<S321>/Gain4' */
  }
  ,

  /* End of '<S310>/Move Control' */

  /* Start of '<S310>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S317>/Vector Concatenate3' */
  }
  ,

  /* End of '<S310>/Hold Control' */

  /* Start of '<S288>/Move Control' */
  {
    0.00250000018F,                    /* '<S296>/Square' */
    0.196120009F,                      /* '<S296>/Multiply' */
    -78.448F                           /* '<S296>/Gain4' */
  }
  ,

  /* End of '<S288>/Move Control' */

  /* Start of '<S378>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S385>/Vector Concatenate3' */
  }
  ,

  /* End of '<S378>/Hold Control' */

  /* Start of '<S368>/Move Control' */
  {
    0.00250000018F,                    /* '<S376>/Square' */
    0.196120009F,                      /* '<S376>/Multiply' */
    -78.448F                           /* '<S376>/Gain4' */
  }
  /* End of '<S368>/Move Control' */
};

/* Constant parameters (default storage) */
const ConstP_FMS_T FMS_ConstP = {
  /* Pooled Parameter (Expression: [4,4,2])
   * Referenced by:
   *   '<S241>/Saturation1'
   *   '<S243>/Saturation'
   *   '<S244>/Saturation1'
   */
  { 4.0F, 4.0F, 2.0F },

  /* Pooled Parameter (Expression: [-4,-4,-2])
   * Referenced by:
   *   '<S241>/Saturation1'
   *   '<S243>/Saturation'
   *   '<S244>/Saturation1'
   */
  { -4.0F, -4.0F, -2.0F }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
