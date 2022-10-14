/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1871
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Oct 14 08:38:55 2022
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
  0.0016F,                             /* '<S57>/Square' */
  0.0201061927F,                       /* '<S57>/Multiply' */
  -12.566371F,                         /* '<S57>/Gain4' */
  0.0016F,                             /* '<S58>/Square' */
  0.0201061927F,                       /* '<S58>/Multiply' */
  -12.566371F,                         /* '<S58>/Gain4' */
  0.0016F,                             /* '<S121>/Square' */
  0.0201061927F,                       /* '<S121>/Multiply' */
  -12.566371F,                         /* '<S121>/Gain4' */
  0.0016F,                             /* '<S122>/Square' */
  0.0201061927F,                       /* '<S122>/Multiply' */
  -12.566371F,                         /* '<S122>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S211>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S157>/Math Function' */
  1.0F,                                /* '<S157>/Sum of Elements' */
  1.0F,                                /* '<S157>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S157>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S157>/Switch' */

  { 0.0F, 1.0F },                      /* '<S157>/Divide' */
  0.616850317F,                        /* '<S153>/Square' */
  0.645964146F,                        /* '<S153>/Multiply' */
  -1.04719758F,                        /* '<S153>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S287>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S291>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S290>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S284>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S222>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S224>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S298>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S300>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S415>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S365>/Math Function' */
  1.0F,                                /* '<S365>/Sum of Elements' */
  1.0F,                                /* '<S365>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S365>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S365>/Switch' */

  { 0.0F, 1.0F },                      /* '<S365>/Divide' */
  0.616850317F,                        /* '<S361>/Square' */
  0.645964146F,                        /* '<S361>/Multiply' */
  -1.04719758F,                        /* '<S361>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S348>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S423>/Vector Concatenate3' */
  1U,                                  /* '<S29>/Data Type Conversion' */
  12U,                                 /* '<S29>/Data Type Conversion1' */
  3U,                                  /* '<S34>/Data Type Conversion' */
  10U,                                 /* '<S34>/Data Type Conversion1' */
  5U,                                  /* '<S34>/Data Type Conversion2' */
  3U,                                  /* '<S33>/Data Type Conversion1' */
  9U,                                  /* '<S33>/Data Type Conversion2' */
  4U,                                  /* '<S33>/Data Type Conversion3' */
  3U,                                  /* '<S35>/Data Type Conversion' */
  8U,                                  /* '<S35>/Data Type Conversion1' */
  3U,                                  /* '<S35>/Data Type Conversion2' */
  3U,                                  /* '<S32>/Data Type Conversion' */
  7U,                                  /* '<S32>/Data Type Conversion1' */
  2U,                                  /* '<S32>/Data Type Conversion2' */
  3U,                                  /* '<S140>/Data Type Conversion' */
  4U,                                  /* '<S140>/Data Type Conversion1' */
  5U,                                  /* '<S140>/Data Type Conversion2' */
  3U,                                  /* '<S137>/Data Type Conversion' */
  3U,                                  /* '<S137>/Data Type Conversion1' */
  6U,                                  /* '<S137>/Data Type Conversion2' */
  3U,                                  /* '<S301>/Data Type Conversion' */
  6U,                                  /* '<S301>/Data Type Conversion1' */
  5U,                                  /* '<S301>/Data Type Conversion2' */
  3U,                                  /* '<S303>/Data Type Conversion' */
  16U,                                 /* '<S303>/Data Type Conversion1' */
  5U,                                  /* '<S303>/Data Type Conversion2' */
  3U,                                  /* '<S302>/Data Type Conversion' */
  15U,                                 /* '<S302>/Data Type Conversion1' */
  5U,                                  /* '<S302>/Data Type Conversion2' */
  3U,                                  /* '<S304>/Data Type Conversion' */
  17U,                                 /* '<S304>/Data Type Conversion1' */
  5U,                                  /* '<S304>/Data Type Conversion2' */
  2U,                                  /* '<S26>/Data Type Conversion2' */
  2U,                                  /* '<S26>/Data Type Conversion1' */

  /* Start of '<S4>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S429>/Sum' */
    0.0066943799901413165,             /* '<S429>/Multiply3' */
    0.99330562000985867                /* '<S429>/Sum4' */
  }
  ,

  /* End of '<S4>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */

  /* Start of '<S23>/Unknown' */
  {
    1U,                                /* '<S31>/Data Type Conversion' */
    1U                                 /* '<S31>/Data Type Conversion1' */
  }
  ,

  /* End of '<S23>/Unknown' */

  /* Start of '<S27>/Unknown' */
  {
    1U,                                /* '<S36>/Data Type Conversion' */
    1U                                 /* '<S36>/Data Type Conversion1' */
  }
  ,

  /* End of '<S27>/Unknown' */

  /* Start of '<S99>/Move Control' */
  {
    0.00250000018F,                    /* '<S110>/Square' */
    0.14709F,                          /* '<S110>/Multiply' */
    -58.836F                           /* '<S110>/Gain4' */
  }
  ,

  /* End of '<S99>/Move Control' */

  /* Start of '<S99>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S106>/Vector Concatenate3' */
  }
  ,

  /* End of '<S99>/Hold Control' */

  /* Start of '<S86>/Move Control' */
  {
    0.0004F,                           /* '<S96>/Square' */
    0.00628318498F,                    /* '<S96>/Multiply' */
    -15.707963F                        /* '<S96>/Gain4' */
  }
  ,

  /* End of '<S86>/Move Control' */

  /* Start of '<S75>/Move Control' */
  {
    0.00250000018F,                    /* '<S83>/Square' */
    0.196120009F,                      /* '<S83>/Multiply' */
    -78.448F                           /* '<S83>/Gain4' */
  }
  ,

  /* End of '<S75>/Move Control' */

  /* Start of '<S59>/Move Control' */
  {
    0.0004F,                           /* '<S69>/Square' */
    0.00628318498F,                    /* '<S69>/Multiply' */
    -15.707963F                        /* '<S69>/Gain4' */
  }
  ,

  /* End of '<S59>/Move Control' */

  /* Start of '<S42>/Move Control' */
  {
    0.00250000018F,                    /* '<S50>/Square' */
    0.196120009F,                      /* '<S50>/Multiply' */
    -78.448F                           /* '<S50>/Gain4' */
  }
  ,

  /* End of '<S42>/Move Control' */

  /* Start of '<S123>/Move Control' */
  {
    0.0004F,                           /* '<S133>/Square' */
    0.00628318498F,                    /* '<S133>/Multiply' */
    -15.707963F                        /* '<S133>/Gain4' */
  }
  ,

  /* End of '<S123>/Move Control' */

  /* Start of '<S28>/Unknown' */
  {
    1U,                                /* '<S138>/Data Type Conversion' */
    1U                                 /* '<S138>/Data Type Conversion1' */
  }
  ,

  /* End of '<S28>/Unknown' */

  /* Start of '<S181>/Move Control' */
  {
    0.00250000018F,                    /* '<S192>/Square' */
    0.14709F,                          /* '<S192>/Multiply' */
    -58.836F                           /* '<S192>/Gain4' */
  }
  ,

  /* End of '<S181>/Move Control' */

  /* Start of '<S181>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S188>/Vector Concatenate3' */
  }
  ,

  /* End of '<S181>/Hold Control' */

  /* Start of '<S171>/Move Control' */
  {
    0.00250000018F,                    /* '<S179>/Square' */
    0.196120009F,                      /* '<S179>/Multiply' */
    -78.448F                           /* '<S179>/Gain4' */
  }
  ,

  /* End of '<S171>/Move Control' */

  /* Start of '<S30>/Unknown' */
  {
    1U,                                /* '<S305>/Data Type Conversion' */
    1U                                 /* '<S305>/Data Type Conversion1' */
  }
  ,

  /* End of '<S30>/Unknown' */

  /* Start of '<S331>/Move Control' */
  {
    0.00250000018F,                    /* '<S342>/Square' */
    0.14709F,                          /* '<S342>/Multiply' */
    -58.836F                           /* '<S342>/Gain4' */
  }
  ,

  /* End of '<S331>/Move Control' */

  /* Start of '<S331>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S338>/Vector Concatenate3' */
  }
  ,

  /* End of '<S331>/Hold Control' */

  /* Start of '<S319>/Move Control' */
  {
    0.0004F,                           /* '<S329>/Square' */
    0.00628318498F,                    /* '<S329>/Multiply' */
    -15.707963F                        /* '<S329>/Gain4' */
  }
  ,

  /* End of '<S319>/Move Control' */

  /* Start of '<S309>/Move Control' */
  {
    0.00250000018F,                    /* '<S317>/Square' */
    0.196120009F,                      /* '<S317>/Multiply' */
    -78.448F                           /* '<S317>/Gain4' */
  }
  ,

  /* End of '<S309>/Move Control' */

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

  /* Start of '<S375>/Move Control' */
  {
    0.00250000018F,                    /* '<S383>/Square' */
    0.196120009F,                      /* '<S383>/Multiply' */
    -78.448F                           /* '<S383>/Gain4' */
  }
  ,

  /* End of '<S375>/Move Control' */

  /* Start of '<S21>/Disarm' */
  {
    1U,                                /* '<S25>/Data Type Conversion' */
    1U                                 /* '<S25>/Data Type Conversion1' */
  }
  /* End of '<S21>/Disarm' */
};

/* Constant parameters (default storage) */
const ConstP_FMS_T FMS_ConstP = {
  /* Pooled Parameter (Expression: [4,4,2])
   * Referenced by:
   *   '<S277>/Saturation1'
   *   '<S281>/Saturation'
   *   '<S282>/Saturation1'
   */
  { 4.0F, 4.0F, 2.0F },

  /* Pooled Parameter (Expression: [-4,-4,-2])
   * Referenced by:
   *   '<S277>/Saturation1'
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
