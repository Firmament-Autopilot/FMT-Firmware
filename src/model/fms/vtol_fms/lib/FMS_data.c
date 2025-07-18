/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2259
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Jul 18 10:38:22 2025
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
  1.9966471893352524,                  /* '<S536>/Sum' */
  0.0066943799901413165,               /* '<S536>/Multiply3' */
  0.99330562000985867,                 /* '<S536>/Sum4' */
  0.0,                                 /* '<S535>/deg2rad2' */
  0.0,                                 /* '<S538>/SinCos' */
  1.0,                                 /* '<S538>/SinCos' */
  0.00250000018F,                      /* '<S342>/Square' */
  0.14709F,                            /* '<S342>/Multiply' */
  -58.836F,                            /* '<S342>/Gain4' */
  0.0016F,                             /* '<S287>/Square' */
  0.0201061927F,                       /* '<S287>/Multiply' */
  -12.566371F,                         /* '<S287>/Gain4' */
  0.0016F,                             /* '<S286>/Square' */
  0.0201061927F,                       /* '<S286>/Multiply' */
  -12.566371F,                         /* '<S286>/Gain4' */
  0.0016F,                             /* '<S354>/Square' */
  0.0201061927F,                       /* '<S354>/Multiply' */
  -12.566371F,                         /* '<S354>/Gain4' */
  0.0016F,                             /* '<S353>/Square' */
  0.0201061927F,                       /* '<S353>/Multiply' */
  -12.566371F,                         /* '<S353>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S446>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S389>/Math Function' */
  1.0F,                                /* '<S389>/Sum of Elements' */
  1.0F,                                /* '<S389>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S389>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S389>/Switch' */

  { 0.0F, 1.0F },                      /* '<S389>/Divide' */
  0.616850317F,                        /* '<S385>/Square' */
  0.645964146F,                        /* '<S385>/Multiply' */
  -1.04719758F,                        /* '<S385>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S522>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S526>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S530>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S529>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S459>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S461>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S552>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S554>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S676>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S623>/Math Function' */
  1.0F,                                /* '<S623>/Sum of Elements' */
  1.0F,                                /* '<S623>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S623>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S623>/Switch' */

  { 0.0F, 1.0F },                      /* '<S623>/Divide' */
  0.616850317F,                        /* '<S619>/Square' */
  0.645964146F,                        /* '<S619>/Multiply' */
  -1.04719758F,                        /* '<S619>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S606>/Vector Concatenate3' */
  0.122499995F,                        /* '<S602>/Square' */
  1.20123494F,                         /* '<S602>/Multiply' */
  -9.806F,                             /* '<S602>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S687>/Vector Concatenate3' */
  0.122499995F,                        /* '<S683>/Square' */
  1.20123494F,                         /* '<S683>/Multiply' */
  -9.806F,                             /* '<S683>/Gain4' */

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
  1U,                                  /* '<S257>/Data Type Conversion' */
  12U,                                 /* '<S257>/Data Type Conversion1' */
  3U,                                  /* '<S262>/Data Type Conversion' */
  10U,                                 /* '<S262>/Data Type Conversion1' */
  5U,                                  /* '<S262>/Data Type Conversion2' */
  3U,                                  /* '<S261>/Data Type Conversion1' */
  9U,                                  /* '<S261>/Data Type Conversion2' */
  4U,                                  /* '<S261>/Data Type Conversion3' */
  3U,                                  /* '<S263>/Data Type Conversion' */
  8U,                                  /* '<S263>/Data Type Conversion1' */
  3U,                                  /* '<S263>/Data Type Conversion2' */
  3U,                                  /* '<S260>/Data Type Conversion' */
  7U,                                  /* '<S260>/Data Type Conversion1' */
  2U,                                  /* '<S260>/Data Type Conversion2' */
  3U,                                  /* '<S372>/Data Type Conversion' */
  4U,                                  /* '<S372>/Data Type Conversion1' */
  5U,                                  /* '<S372>/Data Type Conversion2' */
  3U,                                  /* '<S369>/Data Type Conversion' */
  3U,                                  /* '<S369>/Data Type Conversion1' */
  6U,                                  /* '<S369>/Data Type Conversion2' */
  3U,                                  /* '<S555>/Data Type Conversion' */
  6U,                                  /* '<S555>/Data Type Conversion1' */
  5U,                                  /* '<S555>/Data Type Conversion2' */
  3U,                                  /* '<S557>/Data Type Conversion' */
  16U,                                 /* '<S557>/Data Type Conversion1' */
  5U,                                  /* '<S557>/Data Type Conversion2' */
  3U,                                  /* '<S556>/Data Type Conversion' */
  15U,                                 /* '<S556>/Data Type Conversion1' */
  5U,                                  /* '<S556>/Data Type Conversion2' */
  3U,                                  /* '<S558>/Data Type Conversion' */
  17U,                                 /* '<S558>/Data Type Conversion1' */
  5U,                                  /* '<S558>/Data Type Conversion2' */
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
  3U,                                  /* '<S188>/Data Type Conversion' */
  6U,                                  /* '<S188>/Data Type Conversion1' */
  5U,                                  /* '<S188>/Data Type Conversion2' */
  3U,                                  /* '<S190>/Data Type Conversion' */
  16U,                                 /* '<S190>/Data Type Conversion1' */
  5U,                                  /* '<S190>/Data Type Conversion2' */
  3U,                                  /* '<S189>/Data Type Conversion' */
  15U,                                 /* '<S189>/Data Type Conversion1' */
  5U,                                  /* '<S189>/Data Type Conversion2' */
  3U,                                  /* '<S191>/Data Type Conversion' */
  17U,                                 /* '<S191>/Data Type Conversion1' */
  5U,                                  /* '<S191>/Data Type Conversion2' */
  2U,                                  /* '<S45>/Data Type Conversion2' */
  2U,                                  /* '<S45>/Data Type Conversion1' */
  1U,                                  /* '<S44>/Data Type Conversion' */
  1U,                                  /* '<S44>/Data Type Conversion1' */

  /* Start of '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S694>/Sum' */
    0.0066943799901413165,             /* '<S694>/Multiply3' */
    0.99330562000985867                /* '<S694>/Sum4' */
  }
  ,

  /* End of '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */

  /* Start of '<S48>/Unknown' */
  {
    1U,                                /* '<S259>/Data Type Conversion' */
    1U                                 /* '<S259>/Data Type Conversion1' */
  }
  ,

  /* End of '<S48>/Unknown' */

  /* Start of '<S255>/Unknown' */
  {
    1U,                                /* '<S264>/Data Type Conversion' */
    1U                                 /* '<S264>/Data Type Conversion1' */
  }
  ,

  /* End of '<S255>/Unknown' */

  /* Start of '<S329>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S336>/Vector Concatenate3' */
  }
  ,

  /* End of '<S329>/Hold Control' */

  /* Start of '<S316>/Move Control' */
  {
    0.0004F,                           /* '<S326>/Square' */
    0.00628318498F,                    /* '<S326>/Multiply' */
    -15.707963F                        /* '<S326>/Gain4' */
  }
  ,

  /* End of '<S316>/Move Control' */

  /* Start of '<S288>/Move Control' */
  {
    0.0004F,                           /* '<S298>/Square' */
    0.00628318498F,                    /* '<S298>/Multiply' */
    -15.707963F                        /* '<S298>/Gain4' */
  }
  ,

  /* End of '<S288>/Move Control' */

  /* Start of '<S355>/Move Control' */
  {
    0.0004F,                           /* '<S365>/Square' */
    0.00628318498F,                    /* '<S365>/Multiply' */
    -15.707963F                        /* '<S365>/Gain4' */
  }
  ,

  /* End of '<S355>/Move Control' */

  /* Start of '<S256>/Unknown' */
  {
    1U,                                /* '<S370>/Data Type Conversion' */
    1U                                 /* '<S370>/Data Type Conversion1' */
  }
  ,

  /* End of '<S256>/Unknown' */

  /* Start of '<S416>/Move Control' */
  {
    0.00250000018F,                    /* '<S427>/Square' */
    0.14709F,                          /* '<S427>/Multiply' */
    -58.836F                           /* '<S427>/Gain4' */
  }
  ,

  /* End of '<S416>/Move Control' */

  /* Start of '<S416>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S423>/Vector Concatenate3' */
  }
  ,

  /* End of '<S416>/Hold Control' */

  /* Start of '<S406>/Move Control' */
  {
    0.00250000018F,                    /* '<S414>/Square' */
    0.196120009F,                      /* '<S414>/Multiply' */
    -78.448F                           /* '<S414>/Gain4' */
  }
  ,

  /* End of '<S406>/Move Control' */

  /* Start of '<S258>/Unknown' */
  {
    1U,                                /* '<S559>/Data Type Conversion' */
    1U                                 /* '<S559>/Data Type Conversion1' */
  }
  ,

  /* End of '<S258>/Unknown' */

  /* Start of '<S585>/Move Control' */
  {
    0.00250000018F,                    /* '<S596>/Square' */
    0.14709F,                          /* '<S596>/Multiply' */
    -58.836F                           /* '<S596>/Gain4' */
  }
  ,

  /* End of '<S585>/Move Control' */

  /* Start of '<S585>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S592>/Vector Concatenate3' */
  }
  ,

  /* End of '<S585>/Hold Control' */

  /* Start of '<S573>/Move Control' */
  {
    0.0004F,                           /* '<S583>/Square' */
    0.00628318498F,                    /* '<S583>/Multiply' */
    -15.707963F                        /* '<S583>/Gain4' */
  }
  ,

  /* End of '<S573>/Move Control' */

  /* Start of '<S563>/Move Control' */
  {
    0.00250000018F,                    /* '<S571>/Square' */
    0.196120009F,                      /* '<S571>/Multiply' */
    -78.448F                           /* '<S571>/Gain4' */
  }
  ,

  /* End of '<S563>/Move Control' */

  /* Start of '<S646>/Move Control' */
  {
    0.00250000018F,                    /* '<S657>/Square' */
    0.14709F,                          /* '<S657>/Multiply' */
    -58.836F                           /* '<S657>/Gain4' */
  }
  ,

  /* End of '<S646>/Move Control' */

  /* Start of '<S646>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S653>/Vector Concatenate3' */
  }
  ,

  /* End of '<S646>/Hold Control' */

  /* Start of '<S636>/Move Control' */
  {
    0.00250000018F,                    /* '<S644>/Square' */
    0.196120009F,                      /* '<S644>/Multiply' */
    -78.448F                           /* '<S644>/Gain4' */
  }
  ,

  /* End of '<S636>/Move Control' */

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
    1U,                                /* '<S192>/Data Type Conversion' */
    1U                                 /* '<S192>/Data Type Conversion1' */
  }
  /* End of '<S62>/Unknown' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
