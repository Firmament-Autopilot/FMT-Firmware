/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1932
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri May 12 16:41:44 2023
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
  1.9966471893352524,                  /* '<S304>/Sum' */
  0.0066943799901413165,               /* '<S304>/Multiply3' */
  0.99330562000985867,                 /* '<S304>/Sum4' */
  0.0,                                 /* '<S303>/deg2rad2' */
  0.0,                                 /* '<S306>/SinCos' */
  1.0,                                 /* '<S306>/SinCos' */
  0.0016F,                             /* '<S59>/Square' */
  0.0201061927F,                       /* '<S59>/Multiply' */
  -12.566371F,                         /* '<S59>/Gain4' */
  0.0016F,                             /* '<S60>/Square' */
  0.0201061927F,                       /* '<S60>/Multiply' */
  -12.566371F,                         /* '<S60>/Gain4' */
  0.0016F,                             /* '<S127>/Square' */
  0.0201061927F,                       /* '<S127>/Multiply' */
  -12.566371F,                         /* '<S127>/Gain4' */
  0.0016F,                             /* '<S128>/Square' */
  0.0201061927F,                       /* '<S128>/Multiply' */
  -12.566371F,                         /* '<S128>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S217>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S163>/Math Function' */
  1.0F,                                /* '<S163>/Sum of Elements' */
  1.0F,                                /* '<S163>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S163>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S163>/Switch' */

  { 0.0F, 1.0F },                      /* '<S163>/Divide' */
  0.616850317F,                        /* '<S159>/Square' */
  0.645964146F,                        /* '<S159>/Multiply' */
  -1.04719758F,                        /* '<S159>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S297>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S298>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S294>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S290>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S228>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S230>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S319>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S321>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S437>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S387>/Math Function' */
  1.0F,                                /* '<S387>/Sum of Elements' */
  1.0F,                                /* '<S387>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S387>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S387>/Switch' */

  { 0.0F, 1.0F },                      /* '<S387>/Divide' */
  0.616850317F,                        /* '<S383>/Square' */
  0.645964146F,                        /* '<S383>/Multiply' */
  -1.04719758F,                        /* '<S383>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S370>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S445>/Vector Concatenate3' */
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
  3U,                                  /* '<S146>/Data Type Conversion' */
  4U,                                  /* '<S146>/Data Type Conversion1' */
  5U,                                  /* '<S146>/Data Type Conversion2' */
  3U,                                  /* '<S143>/Data Type Conversion' */
  3U,                                  /* '<S143>/Data Type Conversion1' */
  6U,                                  /* '<S143>/Data Type Conversion2' */
  3U,                                  /* '<S322>/Data Type Conversion' */
  6U,                                  /* '<S322>/Data Type Conversion1' */
  5U,                                  /* '<S322>/Data Type Conversion2' */
  3U,                                  /* '<S324>/Data Type Conversion' */
  16U,                                 /* '<S324>/Data Type Conversion1' */
  5U,                                  /* '<S324>/Data Type Conversion2' */
  3U,                                  /* '<S323>/Data Type Conversion' */
  15U,                                 /* '<S323>/Data Type Conversion1' */
  5U,                                  /* '<S323>/Data Type Conversion2' */
  3U,                                  /* '<S325>/Data Type Conversion' */
  17U,                                 /* '<S325>/Data Type Conversion1' */
  5U,                                  /* '<S325>/Data Type Conversion2' */
  2U,                                  /* '<S28>/Data Type Conversion2' */
  2U,                                  /* '<S28>/Data Type Conversion1' */

  /* Start of '<S4>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S451>/Sum' */
    0.0066943799901413165,             /* '<S451>/Multiply3' */
    0.99330562000985867                /* '<S451>/Sum4' */
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

  /* Start of '<S105>/Move Control' */
  {
    0.00250000018F,                    /* '<S116>/Square' */
    0.14709F,                          /* '<S116>/Multiply' */
    -58.836F                           /* '<S116>/Gain4' */
  }
  ,

  /* End of '<S105>/Move Control' */

  /* Start of '<S105>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S112>/Vector Concatenate3' */
  }
  ,

  /* End of '<S105>/Hold Control' */

  /* Start of '<S92>/Move Control' */
  {
    0.0004F,                           /* '<S102>/Square' */
    0.00628318498F,                    /* '<S102>/Multiply' */
    -15.707963F                        /* '<S102>/Gain4' */
  }
  ,

  /* End of '<S92>/Move Control' */

  /* Start of '<S61>/Move Control' */
  {
    0.0004F,                           /* '<S71>/Square' */
    0.00628318498F,                    /* '<S71>/Multiply' */
    -15.707963F                        /* '<S71>/Gain4' */
  }
  ,

  /* End of '<S61>/Move Control' */

  /* Start of '<S129>/Move Control' */
  {
    0.0004F,                           /* '<S139>/Square' */
    0.00628318498F,                    /* '<S139>/Multiply' */
    -15.707963F                        /* '<S139>/Gain4' */
  }
  ,

  /* End of '<S129>/Move Control' */

  /* Start of '<S30>/Unknown' */
  {
    1U,                                /* '<S144>/Data Type Conversion' */
    1U                                 /* '<S144>/Data Type Conversion1' */
  }
  ,

  /* End of '<S30>/Unknown' */

  /* Start of '<S187>/Move Control' */
  {
    0.00250000018F,                    /* '<S198>/Square' */
    0.14709F,                          /* '<S198>/Multiply' */
    -58.836F                           /* '<S198>/Gain4' */
  }
  ,

  /* End of '<S187>/Move Control' */

  /* Start of '<S187>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S194>/Vector Concatenate3' */
  }
  ,

  /* End of '<S187>/Hold Control' */

  /* Start of '<S177>/Move Control' */
  {
    0.00250000018F,                    /* '<S185>/Square' */
    0.196120009F,                      /* '<S185>/Multiply' */
    -78.448F                           /* '<S185>/Gain4' */
  }
  ,

  /* End of '<S177>/Move Control' */

  /* Start of '<S32>/Unknown' */
  {
    1U,                                /* '<S326>/Data Type Conversion' */
    1U                                 /* '<S326>/Data Type Conversion1' */
  }
  ,

  /* End of '<S32>/Unknown' */

  /* Start of '<S352>/Move Control' */
  {
    0.00250000018F,                    /* '<S363>/Square' */
    0.14709F,                          /* '<S363>/Multiply' */
    -58.836F                           /* '<S363>/Gain4' */
  }
  ,

  /* End of '<S352>/Move Control' */

  /* Start of '<S352>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S359>/Vector Concatenate3' */
  }
  ,

  /* End of '<S352>/Hold Control' */

  /* Start of '<S340>/Move Control' */
  {
    0.0004F,                           /* '<S350>/Square' */
    0.00628318498F,                    /* '<S350>/Multiply' */
    -15.707963F                        /* '<S350>/Gain4' */
  }
  ,

  /* End of '<S340>/Move Control' */

  /* Start of '<S330>/Move Control' */
  {
    0.00250000018F,                    /* '<S338>/Square' */
    0.196120009F,                      /* '<S338>/Multiply' */
    -78.448F                           /* '<S338>/Gain4' */
  }
  ,

  /* End of '<S330>/Move Control' */

  /* Start of '<S407>/Move Control' */
  {
    0.00250000018F,                    /* '<S418>/Square' */
    0.14709F,                          /* '<S418>/Multiply' */
    -58.836F                           /* '<S418>/Gain4' */
  }
  ,

  /* End of '<S407>/Move Control' */

  /* Start of '<S407>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S414>/Vector Concatenate3' */
  }
  ,

  /* End of '<S407>/Hold Control' */

  /* Start of '<S397>/Move Control' */
  {
    0.00250000018F,                    /* '<S405>/Square' */
    0.196120009F,                      /* '<S405>/Multiply' */
    -78.448F                           /* '<S405>/Gain4' */
  }
  ,

  /* End of '<S397>/Move Control' */

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
   *   '<S283>/Saturation1'
   *   '<S285>/Saturation'
   *   '<S286>/Saturation1'
   */
  { 4.0F, 4.0F, 2.0F },

  /* Pooled Parameter (Expression: [-4,-4,-2])
   * Referenced by:
   *   '<S283>/Saturation1'
   *   '<S285>/Saturation'
   *   '<S286>/Saturation1'
   */
  { -4.0F, -4.0F, -2.0F }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
