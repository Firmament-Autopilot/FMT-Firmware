/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2119
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sun Mar  2 09:27:32 2025
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
  1.9966471893352524,                  /* '<S324>/Sum' */
  0.0066943799901413165,               /* '<S324>/Multiply3' */
  0.99330562000985867,                 /* '<S324>/Sum4' */
  0.0,                                 /* '<S323>/deg2rad2' */
  0.0,                                 /* '<S326>/SinCos' */
  1.0,                                 /* '<S326>/SinCos' */
  0.00250000018F,                      /* '<S125>/Square' */
  0.14709F,                            /* '<S125>/Multiply' */
  -58.836F,                            /* '<S125>/Gain4' */
  0.0016F,                             /* '<S68>/Square' */
  0.0201061927F,                       /* '<S68>/Multiply' */
  -12.566371F,                         /* '<S68>/Gain4' */
  0.0016F,                             /* '<S69>/Square' */
  0.0201061927F,                       /* '<S69>/Multiply' */
  -12.566371F,                         /* '<S69>/Gain4' */
  0.0016F,                             /* '<S139>/Square' */
  0.0201061927F,                       /* '<S139>/Multiply' */
  -12.566371F,                         /* '<S139>/Gain4' */
  0.0016F,                             /* '<S140>/Square' */
  0.0201061927F,                       /* '<S140>/Multiply' */
  -12.566371F,                         /* '<S140>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S235>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S175>/Math Function' */
  1.0F,                                /* '<S175>/Sum of Elements' */
  1.0F,                                /* '<S175>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S175>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S175>/Switch' */

  { 0.0F, 1.0F },                      /* '<S175>/Divide' */
  0.616850317F,                        /* '<S171>/Square' */
  0.645964146F,                        /* '<S171>/Multiply' */
  -1.04719758F,                        /* '<S171>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S317>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S318>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S314>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S310>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S247>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S249>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S339>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S341>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S470>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S410>/Math Function' */
  1.0F,                                /* '<S410>/Sum of Elements' */
  1.0F,                                /* '<S410>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S410>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S410>/Switch' */

  { 0.0F, 1.0F },                      /* '<S410>/Divide' */
  0.616850317F,                        /* '<S406>/Square' */
  0.645964146F,                        /* '<S406>/Multiply' */
  -1.04719758F,                        /* '<S406>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S393>/Vector Concatenate3' */
  0.122499995F,                        /* '<S389>/Square' */
  1.20123494F,                         /* '<S389>/Multiply' */
  -9.806F,                             /* '<S389>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S481>/Vector Concatenate3' */
  0.122499995F,                        /* '<S477>/Square' */
  1.20123494F,                         /* '<S477>/Multiply' */
  -9.806F,                             /* '<S477>/Gain4' */
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
  3U,                                  /* '<S158>/Data Type Conversion' */
  4U,                                  /* '<S158>/Data Type Conversion1' */
  5U,                                  /* '<S158>/Data Type Conversion2' */
  3U,                                  /* '<S155>/Data Type Conversion' */
  3U,                                  /* '<S155>/Data Type Conversion1' */
  6U,                                  /* '<S155>/Data Type Conversion2' */
  3U,                                  /* '<S342>/Data Type Conversion' */
  6U,                                  /* '<S342>/Data Type Conversion1' */
  5U,                                  /* '<S342>/Data Type Conversion2' */
  3U,                                  /* '<S344>/Data Type Conversion' */
  16U,                                 /* '<S344>/Data Type Conversion1' */
  5U,                                  /* '<S344>/Data Type Conversion2' */
  3U,                                  /* '<S343>/Data Type Conversion' */
  15U,                                 /* '<S343>/Data Type Conversion1' */
  5U,                                  /* '<S343>/Data Type Conversion2' */
  3U,                                  /* '<S345>/Data Type Conversion' */
  17U,                                 /* '<S345>/Data Type Conversion1' */
  5U,                                  /* '<S345>/Data Type Conversion2' */
  2U,                                  /* '<S33>/Data Type Conversion2' */
  2U,                                  /* '<S33>/Data Type Conversion1' */
  1U,                                  /* '<S32>/Data Type Conversion' */
  1U,                                  /* '<S32>/Data Type Conversion1' */

  /* Start of '<S5>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S487>/Sum' */
    0.0066943799901413165,             /* '<S487>/Multiply3' */
    0.99330562000985867                /* '<S487>/Sum4' */
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

  /* Start of '<S111>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S118>/Vector Concatenate3' */
  }
  ,

  /* End of '<S111>/Hold Control' */

  /* Start of '<S98>/Move Control' */
  {
    0.0004F,                           /* '<S108>/Square' */
    0.00628318498F,                    /* '<S108>/Multiply' */
    -15.707963F                        /* '<S108>/Gain4' */
  }
  ,

  /* End of '<S98>/Move Control' */

  /* Start of '<S70>/Move Control' */
  {
    0.0004F,                           /* '<S80>/Square' */
    0.00628318498F,                    /* '<S80>/Multiply' */
    -15.707963F                        /* '<S80>/Gain4' */
  }
  ,

  /* End of '<S70>/Move Control' */

  /* Start of '<S141>/Move Control' */
  {
    0.0004F,                           /* '<S151>/Square' */
    0.00628318498F,                    /* '<S151>/Multiply' */
    -15.707963F                        /* '<S151>/Gain4' */
  }
  ,

  /* End of '<S141>/Move Control' */

  /* Start of '<S35>/Unknown' */
  {
    1U,                                /* '<S156>/Data Type Conversion' */
    1U                                 /* '<S156>/Data Type Conversion1' */
  }
  ,

  /* End of '<S35>/Unknown' */

  /* Start of '<S205>/Move Control' */
  {
    0.00250000018F,                    /* '<S216>/Square' */
    0.14709F,                          /* '<S216>/Multiply' */
    -58.836F                           /* '<S216>/Gain4' */
  }
  ,

  /* End of '<S205>/Move Control' */

  /* Start of '<S205>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S212>/Vector Concatenate3' */
  }
  ,

  /* End of '<S205>/Hold Control' */

  /* Start of '<S195>/Move Control' */
  {
    0.00250000018F,                    /* '<S203>/Square' */
    0.196120009F,                      /* '<S203>/Multiply' */
    -78.448F                           /* '<S203>/Gain4' */
  }
  ,

  /* End of '<S195>/Move Control' */

  /* Start of '<S37>/Unknown' */
  {
    1U,                                /* '<S346>/Data Type Conversion' */
    1U                                 /* '<S346>/Data Type Conversion1' */
  }
  ,

  /* End of '<S37>/Unknown' */

  /* Start of '<S372>/Move Control' */
  {
    0.00250000018F,                    /* '<S383>/Square' */
    0.14709F,                          /* '<S383>/Multiply' */
    -58.836F                           /* '<S383>/Gain4' */
  }
  ,

  /* End of '<S372>/Move Control' */

  /* Start of '<S372>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S379>/Vector Concatenate3' */
  }
  ,

  /* End of '<S372>/Hold Control' */

  /* Start of '<S360>/Move Control' */
  {
    0.0004F,                           /* '<S370>/Square' */
    0.00628318498F,                    /* '<S370>/Multiply' */
    -15.707963F                        /* '<S370>/Gain4' */
  }
  ,

  /* End of '<S360>/Move Control' */

  /* Start of '<S350>/Move Control' */
  {
    0.00250000018F,                    /* '<S358>/Square' */
    0.196120009F,                      /* '<S358>/Multiply' */
    -78.448F                           /* '<S358>/Gain4' */
  }
  ,

  /* End of '<S350>/Move Control' */

  /* Start of '<S440>/Move Control' */
  {
    0.00250000018F,                    /* '<S451>/Square' */
    0.14709F,                          /* '<S451>/Multiply' */
    -58.836F                           /* '<S451>/Gain4' */
  }
  ,

  /* End of '<S440>/Move Control' */

  /* Start of '<S440>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S447>/Vector Concatenate3' */
  }
  ,

  /* End of '<S440>/Hold Control' */

  /* Start of '<S430>/Move Control' */
  {
    0.00250000018F,                    /* '<S438>/Square' */
    0.196120009F,                      /* '<S438>/Multiply' */
    -78.448F                           /* '<S438>/Gain4' */
  }
  /* End of '<S430>/Move Control' */
};

/* Constant parameters (default storage) */
const ConstP_FMS_T FMS_ConstP = {
  /* Pooled Parameter (Expression: [4,4,2])
   * Referenced by:
   *   '<S303>/Saturation1'
   *   '<S305>/Saturation'
   *   '<S306>/Saturation1'
   */
  { 4.0F, 4.0F, 2.0F },

  /* Pooled Parameter (Expression: [-4,-4,-2])
   * Referenced by:
   *   '<S303>/Saturation1'
   *   '<S305>/Saturation'
   *   '<S306>/Saturation1'
   */
  { -4.0F, -4.0F, -2.0F }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
