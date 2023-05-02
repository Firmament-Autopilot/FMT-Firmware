/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1916
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue May  2 16:59:34 2023
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
  1.9966471893352524,                  /* '<S300>/Sum' */
  0.0066943799901413165,               /* '<S300>/Multiply3' */
  0.99330562000985867,                 /* '<S300>/Sum4' */
  0.0,                                 /* '<S299>/deg2rad2' */
  0.0,                                 /* '<S302>/SinCos' */
  1.0,                                 /* '<S302>/SinCos' */
  0.0016F,                             /* '<S59>/Square' */
  0.0201061927F,                       /* '<S59>/Multiply' */
  -12.566371F,                         /* '<S59>/Gain4' */
  0.0016F,                             /* '<S60>/Square' */
  0.0201061927F,                       /* '<S60>/Multiply' */
  -12.566371F,                         /* '<S60>/Gain4' */
  0.0016F,                             /* '<S123>/Square' */
  0.0201061927F,                       /* '<S123>/Multiply' */
  -12.566371F,                         /* '<S123>/Gain4' */
  0.0016F,                             /* '<S124>/Square' */
  0.0201061927F,                       /* '<S124>/Multiply' */
  -12.566371F,                         /* '<S124>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S213>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S159>/Math Function' */
  1.0F,                                /* '<S159>/Sum of Elements' */
  1.0F,                                /* '<S159>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S159>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S159>/Switch' */

  { 0.0F, 1.0F },                      /* '<S159>/Divide' */
  0.616850317F,                        /* '<S155>/Square' */
  0.645964146F,                        /* '<S155>/Multiply' */
  -1.04719758F,                        /* '<S155>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S293>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S294>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S290>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S286>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S224>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S226>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S315>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S317>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S432>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S382>/Math Function' */
  1.0F,                                /* '<S382>/Sum of Elements' */
  1.0F,                                /* '<S382>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S382>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S382>/Switch' */

  { 0.0F, 1.0F },                      /* '<S382>/Divide' */
  0.616850317F,                        /* '<S378>/Square' */
  0.645964146F,                        /* '<S378>/Multiply' */
  -1.04719758F,                        /* '<S378>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S365>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S440>/Vector Concatenate3' */
  1U,                                  /* '<S31>/Data Type Conversion' */
  12U,                                 /* '<S31>/Data Type Conversion1' */
  3U,                                  /* '<S36>/Data Type Conversion' */
  10U,                                 /* '<S36>/Data Type Conversion1' */
  5U,                                  /* '<S36>/Data Type Conversion2' */
  3U,                                  /* '<S35>/Data Type Conversion1' */
  9U,                                  /* '<S35>/Data Type Conversion2' */
  4U,                                  /* '<S35>/Data Type Conversion3' */
  3U,                                  /* '<S37>/Data Type Conversion' */
  8U,                                  /* '<S37>/Data Type Conversion1' */
  3U,                                  /* '<S37>/Data Type Conversion2' */
  3U,                                  /* '<S34>/Data Type Conversion' */
  7U,                                  /* '<S34>/Data Type Conversion1' */
  2U,                                  /* '<S34>/Data Type Conversion2' */
  3U,                                  /* '<S142>/Data Type Conversion' */
  4U,                                  /* '<S142>/Data Type Conversion1' */
  5U,                                  /* '<S142>/Data Type Conversion2' */
  3U,                                  /* '<S139>/Data Type Conversion' */
  3U,                                  /* '<S139>/Data Type Conversion1' */
  6U,                                  /* '<S139>/Data Type Conversion2' */
  3U,                                  /* '<S318>/Data Type Conversion' */
  6U,                                  /* '<S318>/Data Type Conversion1' */
  5U,                                  /* '<S318>/Data Type Conversion2' */
  3U,                                  /* '<S320>/Data Type Conversion' */
  16U,                                 /* '<S320>/Data Type Conversion1' */
  5U,                                  /* '<S320>/Data Type Conversion2' */
  3U,                                  /* '<S319>/Data Type Conversion' */
  15U,                                 /* '<S319>/Data Type Conversion1' */
  5U,                                  /* '<S319>/Data Type Conversion2' */
  3U,                                  /* '<S321>/Data Type Conversion' */
  17U,                                 /* '<S321>/Data Type Conversion1' */
  5U,                                  /* '<S321>/Data Type Conversion2' */
  2U,                                  /* '<S28>/Data Type Conversion2' */
  2U,                                  /* '<S28>/Data Type Conversion1' */

  /* Start of '<S4>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S446>/Sum' */
    0.0066943799901413165,             /* '<S446>/Multiply3' */
    0.99330562000985867                /* '<S446>/Sum4' */
  }
  ,

  /* End of '<S4>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */

  /* Start of '<S25>/Unknown' */
  {
    1U,                                /* '<S33>/Data Type Conversion' */
    1U                                 /* '<S33>/Data Type Conversion1' */
  }
  ,

  /* End of '<S25>/Unknown' */

  /* Start of '<S29>/Unknown' */
  {
    1U,                                /* '<S38>/Data Type Conversion' */
    1U                                 /* '<S38>/Data Type Conversion1' */
  }
  ,

  /* End of '<S29>/Unknown' */

  /* Start of '<S101>/Move Control' */
  {
    0.00250000018F,                    /* '<S112>/Square' */
    0.14709F,                          /* '<S112>/Multiply' */
    -58.836F                           /* '<S112>/Gain4' */
  }
  ,

  /* End of '<S101>/Move Control' */

  /* Start of '<S101>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S108>/Vector Concatenate3' */
  }
  ,

  /* End of '<S101>/Hold Control' */

  /* Start of '<S88>/Move Control' */
  {
    0.0004F,                           /* '<S98>/Square' */
    0.00628318498F,                    /* '<S98>/Multiply' */
    -15.707963F                        /* '<S98>/Gain4' */
  }
  ,

  /* End of '<S88>/Move Control' */

  /* Start of '<S77>/Move Control' */
  {
    0.00250000018F,                    /* '<S85>/Square' */
    0.196120009F,                      /* '<S85>/Multiply' */
    -78.448F                           /* '<S85>/Gain4' */
  }
  ,

  /* End of '<S77>/Move Control' */

  /* Start of '<S61>/Move Control' */
  {
    0.0004F,                           /* '<S71>/Square' */
    0.00628318498F,                    /* '<S71>/Multiply' */
    -15.707963F                        /* '<S71>/Gain4' */
  }
  ,

  /* End of '<S61>/Move Control' */

  /* Start of '<S44>/Move Control' */
  {
    0.00250000018F,                    /* '<S52>/Square' */
    0.196120009F,                      /* '<S52>/Multiply' */
    -78.448F                           /* '<S52>/Gain4' */
  }
  ,

  /* End of '<S44>/Move Control' */

  /* Start of '<S125>/Move Control' */
  {
    0.0004F,                           /* '<S135>/Square' */
    0.00628318498F,                    /* '<S135>/Multiply' */
    -15.707963F                        /* '<S135>/Gain4' */
  }
  ,

  /* End of '<S125>/Move Control' */

  /* Start of '<S30>/Unknown' */
  {
    1U,                                /* '<S140>/Data Type Conversion' */
    1U                                 /* '<S140>/Data Type Conversion1' */
  }
  ,

  /* End of '<S30>/Unknown' */

  /* Start of '<S183>/Move Control' */
  {
    0.00250000018F,                    /* '<S194>/Square' */
    0.14709F,                          /* '<S194>/Multiply' */
    -58.836F                           /* '<S194>/Gain4' */
  }
  ,

  /* End of '<S183>/Move Control' */

  /* Start of '<S183>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S190>/Vector Concatenate3' */
  }
  ,

  /* End of '<S183>/Hold Control' */

  /* Start of '<S173>/Move Control' */
  {
    0.00250000018F,                    /* '<S181>/Square' */
    0.196120009F,                      /* '<S181>/Multiply' */
    -78.448F                           /* '<S181>/Gain4' */
  }
  ,

  /* End of '<S173>/Move Control' */

  /* Start of '<S32>/Unknown' */
  {
    1U,                                /* '<S322>/Data Type Conversion' */
    1U                                 /* '<S322>/Data Type Conversion1' */
  }
  ,

  /* End of '<S32>/Unknown' */

  /* Start of '<S348>/Move Control' */
  {
    0.00250000018F,                    /* '<S359>/Square' */
    0.14709F,                          /* '<S359>/Multiply' */
    -58.836F                           /* '<S359>/Gain4' */
  }
  ,

  /* End of '<S348>/Move Control' */

  /* Start of '<S348>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S355>/Vector Concatenate3' */
  }
  ,

  /* End of '<S348>/Hold Control' */

  /* Start of '<S336>/Move Control' */
  {
    0.0004F,                           /* '<S346>/Square' */
    0.00628318498F,                    /* '<S346>/Multiply' */
    -15.707963F                        /* '<S346>/Gain4' */
  }
  ,

  /* End of '<S336>/Move Control' */

  /* Start of '<S326>/Move Control' */
  {
    0.00250000018F,                    /* '<S334>/Square' */
    0.196120009F,                      /* '<S334>/Multiply' */
    -78.448F                           /* '<S334>/Gain4' */
  }
  ,

  /* End of '<S326>/Move Control' */

  /* Start of '<S402>/Move Control' */
  {
    0.00250000018F,                    /* '<S413>/Square' */
    0.14709F,                          /* '<S413>/Multiply' */
    -58.836F                           /* '<S413>/Gain4' */
  }
  ,

  /* End of '<S402>/Move Control' */

  /* Start of '<S402>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S409>/Vector Concatenate3' */
  }
  ,

  /* End of '<S402>/Hold Control' */

  /* Start of '<S392>/Move Control' */
  {
    0.00250000018F,                    /* '<S400>/Square' */
    0.196120009F,                      /* '<S400>/Multiply' */
    -78.448F                           /* '<S400>/Gain4' */
  }
  ,

  /* End of '<S392>/Move Control' */

  /* Start of '<S23>/Disarm' */
  {
    1U,                                /* '<S27>/Data Type Conversion' */
    1U                                 /* '<S27>/Data Type Conversion1' */
  }
  /* End of '<S23>/Disarm' */
};

/* Constant parameters (default storage) */
const ConstP_FMS_T FMS_ConstP = {
  /* Pooled Parameter (Expression: [4,4,2])
   * Referenced by:
   *   '<S279>/Saturation1'
   *   '<S281>/Saturation'
   *   '<S282>/Saturation1'
   */
  { 4.0F, 4.0F, 2.0F },

  /* Pooled Parameter (Expression: [-4,-4,-2])
   * Referenced by:
   *   '<S279>/Saturation1'
   *   '<S281>/Saturation'
   *   '<S282>/Saturation1'
   */
  { -4.0F, -4.0F, -2.0F }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
