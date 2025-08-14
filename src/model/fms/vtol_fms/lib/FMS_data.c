/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2493
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Aug 13 14:20:11 2025
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
  1.9966471893352524,                  /* '<S575>/Sum' */
  0.0066943799901413165,               /* '<S575>/Multiply3' */
  0.99330562000985867,                 /* '<S575>/Sum4' */
  0.0,                                 /* '<S574>/deg2rad2' */
  0.0,                                 /* '<S577>/SinCos' */
  1.0,                                 /* '<S577>/SinCos' */
  0.0100000007F,                       /* '<S378>/Square' */
  0.392240018F,                        /* '<S378>/Multiply' */
  -39.224F,                            /* '<S378>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S372>/Vector Concatenate3' */
  0.0016F,                             /* '<S324>/Square' */
  0.0201061927F,                       /* '<S324>/Multiply' */
  -12.566371F,                         /* '<S324>/Gain4' */
  0.0016F,                             /* '<S323>/Square' */
  0.0201061927F,                       /* '<S323>/Multiply' */
  -12.566371F,                         /* '<S323>/Gain4' */
  0.0016F,                             /* '<S390>/Square' */
  0.0201061927F,                       /* '<S390>/Multiply' */
  -12.566371F,                         /* '<S390>/Gain4' */
  0.0016F,                             /* '<S389>/Square' */
  0.0201061927F,                       /* '<S389>/Multiply' */
  -12.566371F,                         /* '<S389>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S485>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S425>/Math Function' */
  1.0F,                                /* '<S425>/Sum of Elements' */
  1.0F,                                /* '<S425>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S425>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S425>/Switch' */

  { 0.0F, 1.0F },                      /* '<S425>/Divide' */
  0.616850317F,                        /* '<S421>/Square' */
  0.484473109F,                        /* '<S421>/Multiply' */
  -0.785398185F,                       /* '<S421>/Gain4' */
  0.00250000018F,                      /* '<S466>/Square' */
  0.14709F,                            /* '<S466>/Multiply' */
  -58.836F,                            /* '<S466>/Gain4' */
  0.00250000018F,                      /* '<S453>/Square' */
  0.196120009F,                        /* '<S453>/Multiply' */
  -78.448F,                            /* '<S453>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S561>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S565>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S569>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S568>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S498>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S500>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S591>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S593>/Vector Concatenate3' */
  0.616850317F,                        /* '<S632>/Square' */
  0.484473109F,                        /* '<S632>/Multiply' */
  -0.785398185F,                       /* '<S632>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S725>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S672>/Math Function' */
  1.0F,                                /* '<S672>/Sum of Elements' */
  1.0F,                                /* '<S672>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S672>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S672>/Switch' */

  { 0.0F, 1.0F },                      /* '<S672>/Divide' */
  0.616850317F,                        /* '<S668>/Square' */
  0.645964146F,                        /* '<S668>/Multiply' */
  -1.04719758F,                        /* '<S668>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S655>/Vector Concatenate3' */
  0.122499995F,                        /* '<S651>/Square' */
  1.20123494F,                         /* '<S651>/Multiply' */
  -9.806F,                             /* '<S651>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S736>/Vector Concatenate3' */
  0.122499995F,                        /* '<S732>/Square' */
  1.20123494F,                         /* '<S732>/Multiply' */
  -9.806F,                             /* '<S732>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S75>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S80>/Vector Concatenate3' */
  0.0F,                                /* '<S82>/Constant' */

  { 0.0F, 0.0F, 1.0F },                /* '<S180>/Vector Concatenate3' */
  0.0004F,                             /* '<S132>/Square' */
  0.00628318498F,                      /* '<S132>/Multiply' */
  -15.707963F,                         /* '<S132>/Gain4' */
  0.00250000018F,                      /* '<S175>/Square' */
  0.14709F,                            /* '<S175>/Multiply' */
  -58.836F,                            /* '<S175>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S168>/Vector Concatenate3' */
  0.0F,                                /* '<S170>/Constant' */

  { 0.0F, 0.0F, 1.0F },                /* '<S163>/Vector Concatenate3' */
  0.0004F,                             /* '<S114>/Square' */
  0.00628318498F,                      /* '<S114>/Multiply' */
  -15.707963F,                         /* '<S114>/Gain4' */
  0.0016F,                             /* '<S111>/Square' */
  0.0201061927F,                       /* '<S111>/Multiply' */
  -12.566371F,                         /* '<S111>/Gain4' */
  0.0016F,                             /* '<S188>/Square' */
  0.0201061927F,                       /* '<S188>/Multiply' */
  -12.566371F,                         /* '<S188>/Gain4' */
  0.0004F,                             /* '<S192>/Square' */
  0.00628318498F,                      /* '<S192>/Multiply' */
  -15.707963F,                         /* '<S192>/Gain4' */
  0.0016F,                             /* '<S189>/Square' */
  0.0201061927F,                       /* '<S189>/Multiply' */
  -12.566371F,                         /* '<S189>/Gain4' */
  1U,                                  /* '<S294>/Data Type Conversion' */
  12U,                                 /* '<S294>/Data Type Conversion1' */
  3U,                                  /* '<S299>/Data Type Conversion' */
  10U,                                 /* '<S299>/Data Type Conversion1' */
  5U,                                  /* '<S299>/Data Type Conversion2' */
  3U,                                  /* '<S298>/Data Type Conversion1' */
  9U,                                  /* '<S298>/Data Type Conversion2' */
  4U,                                  /* '<S298>/Data Type Conversion3' */
  3U,                                  /* '<S300>/Data Type Conversion' */
  8U,                                  /* '<S300>/Data Type Conversion1' */
  3U,                                  /* '<S300>/Data Type Conversion2' */
  3U,                                  /* '<S297>/Data Type Conversion' */
  7U,                                  /* '<S297>/Data Type Conversion1' */
  2U,                                  /* '<S297>/Data Type Conversion2' */
  3U,                                  /* '<S408>/Data Type Conversion' */
  4U,                                  /* '<S408>/Data Type Conversion1' */
  5U,                                  /* '<S408>/Data Type Conversion2' */
  3U,                                  /* '<S405>/Data Type Conversion' */
  3U,                                  /* '<S405>/Data Type Conversion1' */
  6U,                                  /* '<S405>/Data Type Conversion2' */
  3U,                                  /* '<S594>/Data Type Conversion' */
  6U,                                  /* '<S594>/Data Type Conversion1' */
  5U,                                  /* '<S594>/Data Type Conversion2' */
  3U,                                  /* '<S596>/Data Type Conversion' */
  16U,                                 /* '<S596>/Data Type Conversion1' */
  5U,                                  /* '<S596>/Data Type Conversion2' */
  3U,                                  /* '<S595>/Data Type Conversion' */
  15U,                                 /* '<S595>/Data Type Conversion1' */
  5U,                                  /* '<S595>/Data Type Conversion2' */
  3U,                                  /* '<S597>/Data Type Conversion' */
  17U,                                 /* '<S597>/Data Type Conversion1' */
  5U,                                  /* '<S597>/Data Type Conversion2' */
  3U,                                  /* '<S45>/Data Type Conversion1' */
  6U,                                  /* '<S45>/Data Type Conversion2' */
  5U,                                  /* '<S45>/Data Type Conversion3' */
  3U,                                  /* '<S87>/Data Type Conversion' */
  12U,                                 /* '<S87>/Data Type Conversion1' */
  1U,                                  /* '<S87>/Data Type Conversion2' */
  3U,                                  /* '<S91>/Data Type Conversion' */
  10U,                                 /* '<S91>/Data Type Conversion1' */
  5U,                                  /* '<S91>/Data Type Conversion2' */
  3U,                                  /* '<S90>/Data Type Conversion1' */
  9U,                                  /* '<S90>/Data Type Conversion2' */
  4U,                                  /* '<S90>/Data Type Conversion3' */
  3U,                                  /* '<S92>/Data Type Conversion' */
  8U,                                  /* '<S92>/Data Type Conversion1' */
  3U,                                  /* '<S92>/Data Type Conversion2' */
  3U,                                  /* '<S197>/Data Type Conversion' */
  4U,                                  /* '<S197>/Data Type Conversion1' */
  5U,                                  /* '<S197>/Data Type Conversion2' */
  1U,                                  /* '<S194>/Data Type Conversion' */
  3U,                                  /* '<S194>/Data Type Conversion1' */
  3U,                                  /* '<S225>/Data Type Conversion' */
  6U,                                  /* '<S225>/Data Type Conversion1' */
  5U,                                  /* '<S225>/Data Type Conversion2' */
  3U,                                  /* '<S227>/Data Type Conversion' */
  16U,                                 /* '<S227>/Data Type Conversion1' */
  5U,                                  /* '<S227>/Data Type Conversion2' */
  3U,                                  /* '<S226>/Data Type Conversion' */
  15U,                                 /* '<S226>/Data Type Conversion1' */
  5U,                                  /* '<S226>/Data Type Conversion2' */
  3U,                                  /* '<S228>/Data Type Conversion' */
  17U,                                 /* '<S228>/Data Type Conversion1' */
  5U,                                  /* '<S228>/Data Type Conversion2' */
  2U,                                  /* '<S44>/Data Type Conversion2' */
  2U,                                  /* '<S44>/Data Type Conversion1' */
  1U,                                  /* '<S43>/Data Type Conversion' */
  1U,                                  /* '<S43>/Data Type Conversion1' */

  /* Start of '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S749>/Sum' */
    0.0066943799901413165,             /* '<S749>/Multiply3' */
    0.99330562000985867                /* '<S749>/Sum4' */
  }
  ,

  /* End of '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */

  /* Start of '<S6>/Vehicle.WaypointAngle' */
  {
    { 0.0F, 1.0F },                    /* synthesized block */

    { 0.0F, 1.0F },                    /* '<S763>/Math Function' */
    1.0F,                              /* '<S763>/Sum of Elements' */
    1.0F,                              /* '<S763>/Math Function1' */

    { 0.0F, 0.0F },                    /* '<S763>/Product' */

    { 0.0F, 1.0F, 1.0F },              /* '<S763>/Switch' */

    { 0.0F, 1.0F }                     /* '<S763>/Divide' */
  }
  ,

  /* End of '<S6>/Vehicle.WaypointAngle' */

  /* Start of '<S47>/Unknown' */
  {
    1U,                                /* '<S296>/Data Type Conversion' */
    1U                                 /* '<S296>/Data Type Conversion1' */
  }
  ,

  /* End of '<S47>/Unknown' */

  /* Start of '<S292>/Unknown' */
  {
    1U,                                /* '<S301>/Data Type Conversion' */
    1U                                 /* '<S301>/Data Type Conversion1' */
  }
  ,

  /* End of '<S292>/Unknown' */

  /* Start of '<S353>/Move Control' */
  {
    0.0004F,                           /* '<S363>/Square' */
    0.00628318498F,                    /* '<S363>/Multiply' */
    -15.707963F                        /* '<S363>/Gain4' */
  }
  ,

  /* End of '<S353>/Move Control' */

  /* Start of '<S325>/Move Control' */
  {
    0.0004F,                           /* '<S335>/Square' */
    0.00628318498F,                    /* '<S335>/Multiply' */
    -15.707963F                        /* '<S335>/Gain4' */
  }
  ,

  /* End of '<S325>/Move Control' */

  /* Start of '<S391>/Move Control' */
  {
    0.0004F,                           /* '<S401>/Square' */
    0.00628318498F,                    /* '<S401>/Multiply' */
    -15.707963F                        /* '<S401>/Gain4' */
  }
  ,

  /* End of '<S391>/Move Control' */

  /* Start of '<S293>/Unknown' */
  {
    1U,                                /* '<S406>/Data Type Conversion' */
    1U                                 /* '<S406>/Data Type Conversion1' */
  }
  ,

  /* End of '<S293>/Unknown' */

  /* Start of '<S455>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S462>/Vector Concatenate3' */
  }
  ,

  /* End of '<S455>/Hold Control' */

  /* Start of '<S295>/Unknown' */
  {
    1U,                                /* '<S598>/Data Type Conversion' */
    1U                                 /* '<S598>/Data Type Conversion1' */
  }
  ,

  /* End of '<S295>/Unknown' */

  /* Start of '<S634>/Move Control' */
  {
    0.00250000018F,                    /* '<S645>/Square' */
    0.14709F,                          /* '<S645>/Multiply' */
    -58.836F                           /* '<S645>/Gain4' */
  }
  ,

  /* End of '<S634>/Move Control' */

  /* Start of '<S634>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S641>/Vector Concatenate3' */
  }
  ,

  /* End of '<S634>/Hold Control' */

  /* Start of '<S613>/Move Control' */
  {
    0.0004F,                           /* '<S624>/Square' */
    0.00628318498F,                    /* '<S624>/Multiply' */
    -15.707963F                        /* '<S624>/Gain4' */
  }
  ,

  /* End of '<S613>/Move Control' */

  /* Start of '<S602>/Move Control' */
  {
    0.00250000018F,                    /* '<S610>/Square' */
    0.196120009F,                      /* '<S610>/Multiply' */
    -78.448F                           /* '<S610>/Gain4' */
  }
  ,

  /* End of '<S602>/Move Control' */

  /* Start of '<S695>/Move Control' */
  {
    0.00250000018F,                    /* '<S706>/Square' */
    0.14709F,                          /* '<S706>/Multiply' */
    -58.836F                           /* '<S706>/Gain4' */
  }
  ,

  /* End of '<S695>/Move Control' */

  /* Start of '<S695>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S702>/Vector Concatenate3' */
  }
  ,

  /* End of '<S695>/Hold Control' */

  /* Start of '<S685>/Move Control' */
  {
    0.00250000018F,                    /* '<S693>/Square' */
    0.196120009F,                      /* '<S693>/Multiply' */
    -78.448F                           /* '<S693>/Gain4' */
  }
  ,

  /* End of '<S685>/Move Control' */

  /* Start of '<S46>/Unknown' */
  {
    1U,                                /* '<S89>/Data Type Conversion' */
    1U                                 /* '<S89>/Data Type Conversion1' */
  }
  ,

  /* End of '<S46>/Unknown' */

  /* Start of '<S85>/Unknown' */
  {
    1U,                                /* '<S93>/Data Type Conversion' */
    1U                                 /* '<S93>/Data Type Conversion1' */
  }
  ,

  /* End of '<S85>/Unknown' */

  /* Start of '<S119>/Move Control' */
  {
    0.00250000018F,                    /* '<S127>/Square' */
    0.196120009F,                      /* '<S127>/Multiply' */
    -78.448F                           /* '<S127>/Gain4' */
  }
  ,

  /* End of '<S119>/Move Control' */

  /* Start of '<S98>/Move Control' */
  {
    0.00250000018F,                    /* '<S106>/Square' */
    0.196120009F,                      /* '<S106>/Multiply' */
    -78.448F                           /* '<S106>/Gain4' */
  }
  ,

  /* End of '<S98>/Move Control' */

  /* Start of '<S86>/Unknown' */
  {
    1U,                                /* '<S195>/Data Type Conversion' */
    1U                                 /* '<S195>/Data Type Conversion1' */
  }
  ,

  /* End of '<S86>/Unknown' */

  /* Start of '<S88>/Unknown' */
  {
    1U,                                /* '<S229>/Data Type Conversion' */
    1U                                 /* '<S229>/Data Type Conversion1' */
  }
  /* End of '<S88>/Unknown' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
