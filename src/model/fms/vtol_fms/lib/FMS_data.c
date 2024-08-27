/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2217
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Aug 27 10:00:27 2024
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
  1.9966471893352524,                  /* '<S530>/Sum' */
  0.0066943799901413165,               /* '<S530>/Multiply3' */
  0.99330562000985867,                 /* '<S530>/Sum4' */
  0.0,                                 /* '<S529>/deg2rad2' */
  0.0,                                 /* '<S532>/SinCos' */
  1.0,                                 /* '<S532>/SinCos' */
  0.00250000018F,                      /* '<S338>/Square' */
  0.14709F,                            /* '<S338>/Multiply' */
  -58.836F,                            /* '<S338>/Gain4' */
  0.0016F,                             /* '<S283>/Square' */
  0.0201061927F,                       /* '<S283>/Multiply' */
  -12.566371F,                         /* '<S283>/Gain4' */
  0.0016F,                             /* '<S282>/Square' */
  0.0201061927F,                       /* '<S282>/Multiply' */
  -12.566371F,                         /* '<S282>/Gain4' */
  0.0016F,                             /* '<S350>/Square' */
  0.0201061927F,                       /* '<S350>/Multiply' */
  -12.566371F,                         /* '<S350>/Gain4' */
  0.0016F,                             /* '<S349>/Square' */
  0.0201061927F,                       /* '<S349>/Multiply' */
  -12.566371F,                         /* '<S349>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S442>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S385>/Math Function' */
  1.0F,                                /* '<S385>/Sum of Elements' */
  1.0F,                                /* '<S385>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S385>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S385>/Switch' */

  { 0.0F, 1.0F },                      /* '<S385>/Divide' */
  0.616850317F,                        /* '<S381>/Square' */
  0.645964146F,                        /* '<S381>/Multiply' */
  -1.04719758F,                        /* '<S381>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S523>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S524>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S520>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S516>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S454>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S456>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S545>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S547>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S669>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S616>/Math Function' */
  1.0F,                                /* '<S616>/Sum of Elements' */
  1.0F,                                /* '<S616>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S616>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S616>/Switch' */

  { 0.0F, 1.0F },                      /* '<S616>/Divide' */
  0.616850317F,                        /* '<S612>/Square' */
  0.645964146F,                        /* '<S612>/Multiply' */
  -1.04719758F,                        /* '<S612>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S599>/Vector Concatenate3' */
  0.122499995F,                        /* '<S595>/Square' */
  1.20123494F,                         /* '<S595>/Multiply' */
  -9.806F,                             /* '<S595>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S680>/Vector Concatenate3' */
  0.122499995F,                        /* '<S676>/Square' */
  1.20123494F,                         /* '<S676>/Multiply' */
  -9.806F,                             /* '<S676>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S53>/Vector Concatenate3' */
  0.0F,                                /* '<S55>/Constant' */

  { 0.0F, 0.0F, 1.0F },                /* '<S142>/Vector Concatenate3' */
  0.0004F,                             /* '<S105>/Square' */
  0.00628318498F,                      /* '<S105>/Multiply' */
  -15.707963F,                         /* '<S105>/Gain4' */
  0.00250000018F,                      /* '<S138>/Square' */
  0.14709F,                            /* '<S138>/Multiply' */
  -58.836F,                            /* '<S138>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S135>/Vector Concatenate3' */
  0.0004F,                             /* '<S87>/Square' */
  0.00628318498F,                      /* '<S87>/Multiply' */
  -15.707963F,                         /* '<S87>/Gain4' */
  0.0016F,                             /* '<S84>/Square' */
  0.0201061927F,                       /* '<S84>/Multiply' */
  -12.566371F,                         /* '<S84>/Gain4' */
  0.0016F,                             /* '<S150>/Square' */
  0.0201061927F,                       /* '<S150>/Multiply' */
  -12.566371F,                         /* '<S150>/Gain4' */
  0.0004F,                             /* '<S154>/Square' */
  0.00628318498F,                      /* '<S154>/Multiply' */
  -15.707963F,                         /* '<S154>/Gain4' */
  0.0016F,                             /* '<S151>/Square' */
  0.0201061927F,                       /* '<S151>/Multiply' */
  -12.566371F,                         /* '<S151>/Gain4' */
  1U,                                  /* '<S253>/Data Type Conversion' */
  12U,                                 /* '<S253>/Data Type Conversion1' */
  3U,                                  /* '<S258>/Data Type Conversion' */
  10U,                                 /* '<S258>/Data Type Conversion1' */
  5U,                                  /* '<S258>/Data Type Conversion2' */
  3U,                                  /* '<S257>/Data Type Conversion1' */
  9U,                                  /* '<S257>/Data Type Conversion2' */
  4U,                                  /* '<S257>/Data Type Conversion3' */
  3U,                                  /* '<S259>/Data Type Conversion' */
  8U,                                  /* '<S259>/Data Type Conversion1' */
  3U,                                  /* '<S259>/Data Type Conversion2' */
  3U,                                  /* '<S256>/Data Type Conversion' */
  7U,                                  /* '<S256>/Data Type Conversion1' */
  2U,                                  /* '<S256>/Data Type Conversion2' */
  3U,                                  /* '<S368>/Data Type Conversion' */
  4U,                                  /* '<S368>/Data Type Conversion1' */
  5U,                                  /* '<S368>/Data Type Conversion2' */
  3U,                                  /* '<S365>/Data Type Conversion' */
  3U,                                  /* '<S365>/Data Type Conversion1' */
  6U,                                  /* '<S365>/Data Type Conversion2' */
  3U,                                  /* '<S548>/Data Type Conversion' */
  6U,                                  /* '<S548>/Data Type Conversion1' */
  5U,                                  /* '<S548>/Data Type Conversion2' */
  3U,                                  /* '<S550>/Data Type Conversion' */
  16U,                                 /* '<S550>/Data Type Conversion1' */
  5U,                                  /* '<S550>/Data Type Conversion2' */
  3U,                                  /* '<S549>/Data Type Conversion' */
  15U,                                 /* '<S549>/Data Type Conversion1' */
  5U,                                  /* '<S549>/Data Type Conversion2' */
  3U,                                  /* '<S551>/Data Type Conversion' */
  17U,                                 /* '<S551>/Data Type Conversion1' */
  5U,                                  /* '<S551>/Data Type Conversion2' */
  3U,                                  /* '<S45>/Data Type Conversion1' */
  10U,                                 /* '<S45>/Data Type Conversion2' */
  5U,                                  /* '<S45>/Data Type Conversion3' */
  3U,                                  /* '<S60>/Data Type Conversion' */
  12U,                                 /* '<S60>/Data Type Conversion1' */
  1U,                                  /* '<S60>/Data Type Conversion2' */
  3U,                                  /* '<S64>/Data Type Conversion' */
  10U,                                 /* '<S64>/Data Type Conversion1' */
  5U,                                  /* '<S64>/Data Type Conversion2' */
  3U,                                  /* '<S63>/Data Type Conversion1' */
  9U,                                  /* '<S63>/Data Type Conversion2' */
  4U,                                  /* '<S63>/Data Type Conversion3' */
  3U,                                  /* '<S65>/Data Type Conversion' */
  8U,                                  /* '<S65>/Data Type Conversion1' */
  3U,                                  /* '<S65>/Data Type Conversion2' */
  3U,                                  /* '<S159>/Data Type Conversion' */
  4U,                                  /* '<S159>/Data Type Conversion1' */
  5U,                                  /* '<S159>/Data Type Conversion2' */
  1U,                                  /* '<S156>/Data Type Conversion' */
  3U,                                  /* '<S156>/Data Type Conversion1' */
  3U,                                  /* '<S184>/Data Type Conversion' */
  6U,                                  /* '<S184>/Data Type Conversion1' */
  5U,                                  /* '<S184>/Data Type Conversion2' */
  3U,                                  /* '<S186>/Data Type Conversion' */
  16U,                                 /* '<S186>/Data Type Conversion1' */
  5U,                                  /* '<S186>/Data Type Conversion2' */
  3U,                                  /* '<S185>/Data Type Conversion' */
  15U,                                 /* '<S185>/Data Type Conversion1' */
  5U,                                  /* '<S185>/Data Type Conversion2' */
  3U,                                  /* '<S187>/Data Type Conversion' */
  17U,                                 /* '<S187>/Data Type Conversion1' */
  5U,                                  /* '<S187>/Data Type Conversion2' */
  2U,                                  /* '<S44>/Data Type Conversion2' */
  2U,                                  /* '<S44>/Data Type Conversion1' */
  1U,                                  /* '<S43>/Data Type Conversion' */
  1U,                                  /* '<S43>/Data Type Conversion1' */

  /* Start of '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S686>/Sum' */
    0.0066943799901413165,             /* '<S686>/Multiply3' */
    0.99330562000985867                /* '<S686>/Sum4' */
  }
  ,

  /* End of '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */

  /* Start of '<S47>/Unknown' */
  {
    1U,                                /* '<S255>/Data Type Conversion' */
    1U                                 /* '<S255>/Data Type Conversion1' */
  }
  ,

  /* End of '<S47>/Unknown' */

  /* Start of '<S251>/Unknown' */
  {
    1U,                                /* '<S260>/Data Type Conversion' */
    1U                                 /* '<S260>/Data Type Conversion1' */
  }
  ,

  /* End of '<S251>/Unknown' */

  /* Start of '<S325>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S332>/Vector Concatenate3' */
  }
  ,

  /* End of '<S325>/Hold Control' */

  /* Start of '<S312>/Move Control' */
  {
    0.0004F,                           /* '<S322>/Square' */
    0.00628318498F,                    /* '<S322>/Multiply' */
    -15.707963F                        /* '<S322>/Gain4' */
  }
  ,

  /* End of '<S312>/Move Control' */

  /* Start of '<S284>/Move Control' */
  {
    0.0004F,                           /* '<S294>/Square' */
    0.00628318498F,                    /* '<S294>/Multiply' */
    -15.707963F                        /* '<S294>/Gain4' */
  }
  ,

  /* End of '<S284>/Move Control' */

  /* Start of '<S351>/Move Control' */
  {
    0.0004F,                           /* '<S361>/Square' */
    0.00628318498F,                    /* '<S361>/Multiply' */
    -15.707963F                        /* '<S361>/Gain4' */
  }
  ,

  /* End of '<S351>/Move Control' */

  /* Start of '<S252>/Unknown' */
  {
    1U,                                /* '<S366>/Data Type Conversion' */
    1U                                 /* '<S366>/Data Type Conversion1' */
  }
  ,

  /* End of '<S252>/Unknown' */

  /* Start of '<S412>/Move Control' */
  {
    0.00250000018F,                    /* '<S423>/Square' */
    0.14709F,                          /* '<S423>/Multiply' */
    -58.836F                           /* '<S423>/Gain4' */
  }
  ,

  /* End of '<S412>/Move Control' */

  /* Start of '<S412>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S419>/Vector Concatenate3' */
  }
  ,

  /* End of '<S412>/Hold Control' */

  /* Start of '<S402>/Move Control' */
  {
    0.00250000018F,                    /* '<S410>/Square' */
    0.196120009F,                      /* '<S410>/Multiply' */
    -78.448F                           /* '<S410>/Gain4' */
  }
  ,

  /* End of '<S402>/Move Control' */

  /* Start of '<S254>/Unknown' */
  {
    1U,                                /* '<S552>/Data Type Conversion' */
    1U                                 /* '<S552>/Data Type Conversion1' */
  }
  ,

  /* End of '<S254>/Unknown' */

  /* Start of '<S578>/Move Control' */
  {
    0.00250000018F,                    /* '<S589>/Square' */
    0.14709F,                          /* '<S589>/Multiply' */
    -58.836F                           /* '<S589>/Gain4' */
  }
  ,

  /* End of '<S578>/Move Control' */

  /* Start of '<S578>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S585>/Vector Concatenate3' */
  }
  ,

  /* End of '<S578>/Hold Control' */

  /* Start of '<S566>/Move Control' */
  {
    0.0004F,                           /* '<S576>/Square' */
    0.00628318498F,                    /* '<S576>/Multiply' */
    -15.707963F                        /* '<S576>/Gain4' */
  }
  ,

  /* End of '<S566>/Move Control' */

  /* Start of '<S556>/Move Control' */
  {
    0.00250000018F,                    /* '<S564>/Square' */
    0.196120009F,                      /* '<S564>/Multiply' */
    -78.448F                           /* '<S564>/Gain4' */
  }
  ,

  /* End of '<S556>/Move Control' */

  /* Start of '<S639>/Move Control' */
  {
    0.00250000018F,                    /* '<S650>/Square' */
    0.14709F,                          /* '<S650>/Multiply' */
    -58.836F                           /* '<S650>/Gain4' */
  }
  ,

  /* End of '<S639>/Move Control' */

  /* Start of '<S639>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S646>/Vector Concatenate3' */
  }
  ,

  /* End of '<S639>/Hold Control' */

  /* Start of '<S629>/Move Control' */
  {
    0.00250000018F,                    /* '<S637>/Square' */
    0.196120009F,                      /* '<S637>/Multiply' */
    -78.448F                           /* '<S637>/Gain4' */
  }
  ,

  /* End of '<S629>/Move Control' */

  /* Start of '<S46>/Unknown' */
  {
    1U,                                /* '<S62>/Data Type Conversion' */
    1U                                 /* '<S62>/Data Type Conversion1' */
  }
  ,

  /* End of '<S46>/Unknown' */

  /* Start of '<S58>/Unknown' */
  {
    1U,                                /* '<S66>/Data Type Conversion' */
    1U                                 /* '<S66>/Data Type Conversion1' */
  }
  ,

  /* End of '<S58>/Unknown' */

  /* Start of '<S92>/Move Control' */
  {
    0.00250000018F,                    /* '<S100>/Square' */
    0.196120009F,                      /* '<S100>/Multiply' */
    -78.448F                           /* '<S100>/Gain4' */
  }
  ,

  /* End of '<S92>/Move Control' */

  /* Start of '<S71>/Move Control' */
  {
    0.00250000018F,                    /* '<S79>/Square' */
    0.196120009F,                      /* '<S79>/Multiply' */
    -78.448F                           /* '<S79>/Gain4' */
  }
  ,

  /* End of '<S71>/Move Control' */

  /* Start of '<S59>/Unknown' */
  {
    1U,                                /* '<S157>/Data Type Conversion' */
    1U                                 /* '<S157>/Data Type Conversion1' */
  }
  ,

  /* End of '<S59>/Unknown' */

  /* Start of '<S61>/Unknown' */
  {
    1U,                                /* '<S188>/Data Type Conversion' */
    1U                                 /* '<S188>/Data Type Conversion1' */
  }
  /* End of '<S61>/Unknown' */
};

/* Constant parameters (default storage) */
const ConstP_FMS_T FMS_ConstP = {
  /* Pooled Parameter (Expression: [4,4,2])
   * Referenced by:
   *   '<S509>/Saturation1'
   *   '<S511>/Saturation'
   *   '<S512>/Saturation1'
   */
  { 4.0F, 4.0F, 2.0F },

  /* Pooled Parameter (Expression: [-4,-4,-2])
   * Referenced by:
   *   '<S509>/Saturation1'
   *   '<S511>/Saturation'
   *   '<S512>/Saturation1'
   */
  { -4.0F, -4.0F, -2.0F }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
