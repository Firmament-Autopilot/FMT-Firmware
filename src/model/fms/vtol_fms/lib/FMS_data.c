/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2244
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Jul 11 10:13:10 2025
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
  1.9966471893352524,                  /* '<S534>/Sum' */
  0.0066943799901413165,               /* '<S534>/Multiply3' */
  0.99330562000985867,                 /* '<S534>/Sum4' */
  0.0,                                 /* '<S533>/deg2rad2' */
  0.0,                                 /* '<S536>/SinCos' */
  1.0,                                 /* '<S536>/SinCos' */
  0.00250000018F,                      /* '<S340>/Square' */
  0.14709F,                            /* '<S340>/Multiply' */
  -58.836F,                            /* '<S340>/Gain4' */
  0.0016F,                             /* '<S285>/Square' */
  0.0201061927F,                       /* '<S285>/Multiply' */
  -12.566371F,                         /* '<S285>/Gain4' */
  0.0016F,                             /* '<S284>/Square' */
  0.0201061927F,                       /* '<S284>/Multiply' */
  -12.566371F,                         /* '<S284>/Gain4' */
  0.0016F,                             /* '<S352>/Square' */
  0.0201061927F,                       /* '<S352>/Multiply' */
  -12.566371F,                         /* '<S352>/Gain4' */
  0.0016F,                             /* '<S351>/Square' */
  0.0201061927F,                       /* '<S351>/Multiply' */
  -12.566371F,                         /* '<S351>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S444>/Vector Concatenate3' */

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

  { 0.0F, 0.0F, 1.0F },                /* '<S520>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S524>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S528>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S527>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S457>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S459>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S550>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S552>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S674>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S621>/Math Function' */
  1.0F,                                /* '<S621>/Sum of Elements' */
  1.0F,                                /* '<S621>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S621>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S621>/Switch' */

  { 0.0F, 1.0F },                      /* '<S621>/Divide' */
  0.616850317F,                        /* '<S617>/Square' */
  0.645964146F,                        /* '<S617>/Multiply' */
  -1.04719758F,                        /* '<S617>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S604>/Vector Concatenate3' */
  0.122499995F,                        /* '<S600>/Square' */
  1.20123494F,                         /* '<S600>/Multiply' */
  -9.806F,                             /* '<S600>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S685>/Vector Concatenate3' */
  0.122499995F,                        /* '<S681>/Square' */
  1.20123494F,                         /* '<S681>/Multiply' */
  -9.806F,                             /* '<S681>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S54>/Vector Concatenate3' */
  0.0F,                                /* '<S56>/Constant' */

  { 0.0F, 0.0F, 1.0F },                /* '<S144>/Vector Concatenate3' */
  0.0004F,                             /* '<S106>/Square' */
  0.00628318498F,                      /* '<S106>/Multiply' */
  -15.707963F,                         /* '<S106>/Gain4' */
  0.00250000018F,                      /* '<S139>/Square' */
  0.14709F,                            /* '<S139>/Multiply' */
  -58.836F,                            /* '<S139>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S136>/Vector Concatenate3' */
  0.0004F,                             /* '<S88>/Square' */
  0.00628318498F,                      /* '<S88>/Multiply' */
  -15.707963F,                         /* '<S88>/Gain4' */
  0.0016F,                             /* '<S85>/Square' */
  0.0201061927F,                       /* '<S85>/Multiply' */
  -12.566371F,                         /* '<S85>/Gain4' */
  0.0016F,                             /* '<S152>/Square' */
  0.0201061927F,                       /* '<S152>/Multiply' */
  -12.566371F,                         /* '<S152>/Gain4' */
  0.0004F,                             /* '<S156>/Square' */
  0.00628318498F,                      /* '<S156>/Multiply' */
  -15.707963F,                         /* '<S156>/Gain4' */
  0.0016F,                             /* '<S153>/Square' */
  0.0201061927F,                       /* '<S153>/Multiply' */
  -12.566371F,                         /* '<S153>/Gain4' */
  1U,                                  /* '<S255>/Data Type Conversion' */
  12U,                                 /* '<S255>/Data Type Conversion1' */
  3U,                                  /* '<S260>/Data Type Conversion' */
  10U,                                 /* '<S260>/Data Type Conversion1' */
  5U,                                  /* '<S260>/Data Type Conversion2' */
  3U,                                  /* '<S259>/Data Type Conversion1' */
  9U,                                  /* '<S259>/Data Type Conversion2' */
  4U,                                  /* '<S259>/Data Type Conversion3' */
  3U,                                  /* '<S261>/Data Type Conversion' */
  8U,                                  /* '<S261>/Data Type Conversion1' */
  3U,                                  /* '<S261>/Data Type Conversion2' */
  3U,                                  /* '<S258>/Data Type Conversion' */
  7U,                                  /* '<S258>/Data Type Conversion1' */
  2U,                                  /* '<S258>/Data Type Conversion2' */
  3U,                                  /* '<S370>/Data Type Conversion' */
  4U,                                  /* '<S370>/Data Type Conversion1' */
  5U,                                  /* '<S370>/Data Type Conversion2' */
  3U,                                  /* '<S367>/Data Type Conversion' */
  3U,                                  /* '<S367>/Data Type Conversion1' */
  6U,                                  /* '<S367>/Data Type Conversion2' */
  3U,                                  /* '<S553>/Data Type Conversion' */
  6U,                                  /* '<S553>/Data Type Conversion1' */
  5U,                                  /* '<S553>/Data Type Conversion2' */
  3U,                                  /* '<S555>/Data Type Conversion' */
  16U,                                 /* '<S555>/Data Type Conversion1' */
  5U,                                  /* '<S555>/Data Type Conversion2' */
  3U,                                  /* '<S554>/Data Type Conversion' */
  15U,                                 /* '<S554>/Data Type Conversion1' */
  5U,                                  /* '<S554>/Data Type Conversion2' */
  3U,                                  /* '<S556>/Data Type Conversion' */
  17U,                                 /* '<S556>/Data Type Conversion1' */
  5U,                                  /* '<S556>/Data Type Conversion2' */
  3U,                                  /* '<S46>/Data Type Conversion1' */
  10U,                                 /* '<S46>/Data Type Conversion2' */
  5U,                                  /* '<S46>/Data Type Conversion3' */
  3U,                                  /* '<S61>/Data Type Conversion' */
  12U,                                 /* '<S61>/Data Type Conversion1' */
  1U,                                  /* '<S61>/Data Type Conversion2' */
  3U,                                  /* '<S65>/Data Type Conversion' */
  10U,                                 /* '<S65>/Data Type Conversion1' */
  5U,                                  /* '<S65>/Data Type Conversion2' */
  3U,                                  /* '<S64>/Data Type Conversion1' */
  9U,                                  /* '<S64>/Data Type Conversion2' */
  4U,                                  /* '<S64>/Data Type Conversion3' */
  3U,                                  /* '<S66>/Data Type Conversion' */
  8U,                                  /* '<S66>/Data Type Conversion1' */
  3U,                                  /* '<S66>/Data Type Conversion2' */
  3U,                                  /* '<S161>/Data Type Conversion' */
  4U,                                  /* '<S161>/Data Type Conversion1' */
  5U,                                  /* '<S161>/Data Type Conversion2' */
  1U,                                  /* '<S158>/Data Type Conversion' */
  3U,                                  /* '<S158>/Data Type Conversion1' */
  3U,                                  /* '<S186>/Data Type Conversion' */
  6U,                                  /* '<S186>/Data Type Conversion1' */
  5U,                                  /* '<S186>/Data Type Conversion2' */
  3U,                                  /* '<S188>/Data Type Conversion' */
  16U,                                 /* '<S188>/Data Type Conversion1' */
  5U,                                  /* '<S188>/Data Type Conversion2' */
  3U,                                  /* '<S187>/Data Type Conversion' */
  15U,                                 /* '<S187>/Data Type Conversion1' */
  5U,                                  /* '<S187>/Data Type Conversion2' */
  3U,                                  /* '<S189>/Data Type Conversion' */
  17U,                                 /* '<S189>/Data Type Conversion1' */
  5U,                                  /* '<S189>/Data Type Conversion2' */
  2U,                                  /* '<S45>/Data Type Conversion2' */
  2U,                                  /* '<S45>/Data Type Conversion1' */
  1U,                                  /* '<S44>/Data Type Conversion' */
  1U,                                  /* '<S44>/Data Type Conversion1' */

  /* Start of '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S691>/Sum' */
    0.0066943799901413165,             /* '<S691>/Multiply3' */
    0.99330562000985867                /* '<S691>/Sum4' */
  }
  ,

  /* End of '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */

  /* Start of '<S48>/Unknown' */
  {
    1U,                                /* '<S257>/Data Type Conversion' */
    1U                                 /* '<S257>/Data Type Conversion1' */
  }
  ,

  /* End of '<S48>/Unknown' */

  /* Start of '<S253>/Unknown' */
  {
    1U,                                /* '<S262>/Data Type Conversion' */
    1U                                 /* '<S262>/Data Type Conversion1' */
  }
  ,

  /* End of '<S253>/Unknown' */

  /* Start of '<S327>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S334>/Vector Concatenate3' */
  }
  ,

  /* End of '<S327>/Hold Control' */

  /* Start of '<S314>/Move Control' */
  {
    0.0004F,                           /* '<S324>/Square' */
    0.00628318498F,                    /* '<S324>/Multiply' */
    -15.707963F                        /* '<S324>/Gain4' */
  }
  ,

  /* End of '<S314>/Move Control' */

  /* Start of '<S286>/Move Control' */
  {
    0.0004F,                           /* '<S296>/Square' */
    0.00628318498F,                    /* '<S296>/Multiply' */
    -15.707963F                        /* '<S296>/Gain4' */
  }
  ,

  /* End of '<S286>/Move Control' */

  /* Start of '<S353>/Move Control' */
  {
    0.0004F,                           /* '<S363>/Square' */
    0.00628318498F,                    /* '<S363>/Multiply' */
    -15.707963F                        /* '<S363>/Gain4' */
  }
  ,

  /* End of '<S353>/Move Control' */

  /* Start of '<S254>/Unknown' */
  {
    1U,                                /* '<S368>/Data Type Conversion' */
    1U                                 /* '<S368>/Data Type Conversion1' */
  }
  ,

  /* End of '<S254>/Unknown' */

  /* Start of '<S414>/Move Control' */
  {
    0.00250000018F,                    /* '<S425>/Square' */
    0.14709F,                          /* '<S425>/Multiply' */
    -58.836F                           /* '<S425>/Gain4' */
  }
  ,

  /* End of '<S414>/Move Control' */

  /* Start of '<S414>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S421>/Vector Concatenate3' */
  }
  ,

  /* End of '<S414>/Hold Control' */

  /* Start of '<S404>/Move Control' */
  {
    0.00250000018F,                    /* '<S412>/Square' */
    0.196120009F,                      /* '<S412>/Multiply' */
    -78.448F                           /* '<S412>/Gain4' */
  }
  ,

  /* End of '<S404>/Move Control' */

  /* Start of '<S256>/Unknown' */
  {
    1U,                                /* '<S557>/Data Type Conversion' */
    1U                                 /* '<S557>/Data Type Conversion1' */
  }
  ,

  /* End of '<S256>/Unknown' */

  /* Start of '<S583>/Move Control' */
  {
    0.00250000018F,                    /* '<S594>/Square' */
    0.14709F,                          /* '<S594>/Multiply' */
    -58.836F                           /* '<S594>/Gain4' */
  }
  ,

  /* End of '<S583>/Move Control' */

  /* Start of '<S583>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S590>/Vector Concatenate3' */
  }
  ,

  /* End of '<S583>/Hold Control' */

  /* Start of '<S571>/Move Control' */
  {
    0.0004F,                           /* '<S581>/Square' */
    0.00628318498F,                    /* '<S581>/Multiply' */
    -15.707963F                        /* '<S581>/Gain4' */
  }
  ,

  /* End of '<S571>/Move Control' */

  /* Start of '<S561>/Move Control' */
  {
    0.00250000018F,                    /* '<S569>/Square' */
    0.196120009F,                      /* '<S569>/Multiply' */
    -78.448F                           /* '<S569>/Gain4' */
  }
  ,

  /* End of '<S561>/Move Control' */

  /* Start of '<S644>/Move Control' */
  {
    0.00250000018F,                    /* '<S655>/Square' */
    0.14709F,                          /* '<S655>/Multiply' */
    -58.836F                           /* '<S655>/Gain4' */
  }
  ,

  /* End of '<S644>/Move Control' */

  /* Start of '<S644>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S651>/Vector Concatenate3' */
  }
  ,

  /* End of '<S644>/Hold Control' */

  /* Start of '<S634>/Move Control' */
  {
    0.00250000018F,                    /* '<S642>/Square' */
    0.196120009F,                      /* '<S642>/Multiply' */
    -78.448F                           /* '<S642>/Gain4' */
  }
  ,

  /* End of '<S634>/Move Control' */

  /* Start of '<S47>/Unknown' */
  {
    1U,                                /* '<S63>/Data Type Conversion' */
    1U                                 /* '<S63>/Data Type Conversion1' */
  }
  ,

  /* End of '<S47>/Unknown' */

  /* Start of '<S59>/Unknown' */
  {
    1U,                                /* '<S67>/Data Type Conversion' */
    1U                                 /* '<S67>/Data Type Conversion1' */
  }
  ,

  /* End of '<S59>/Unknown' */

  /* Start of '<S93>/Move Control' */
  {
    0.00250000018F,                    /* '<S101>/Square' */
    0.196120009F,                      /* '<S101>/Multiply' */
    -78.448F                           /* '<S101>/Gain4' */
  }
  ,

  /* End of '<S93>/Move Control' */

  /* Start of '<S72>/Move Control' */
  {
    0.00250000018F,                    /* '<S80>/Square' */
    0.196120009F,                      /* '<S80>/Multiply' */
    -78.448F                           /* '<S80>/Gain4' */
  }
  ,

  /* End of '<S72>/Move Control' */

  /* Start of '<S60>/Unknown' */
  {
    1U,                                /* '<S159>/Data Type Conversion' */
    1U                                 /* '<S159>/Data Type Conversion1' */
  }
  ,

  /* End of '<S60>/Unknown' */

  /* Start of '<S62>/Unknown' */
  {
    1U,                                /* '<S190>/Data Type Conversion' */
    1U                                 /* '<S190>/Data Type Conversion1' */
  }
  /* End of '<S62>/Unknown' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
