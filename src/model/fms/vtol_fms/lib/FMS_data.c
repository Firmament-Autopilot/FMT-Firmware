/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2472
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Jul 30 16:19:08 2025
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
  1.9966471893352524,                  /* '<S576>/Sum' */
  0.0066943799901413165,               /* '<S576>/Multiply3' */
  0.99330562000985867,                 /* '<S576>/Sum4' */
  0.0,                                 /* '<S575>/deg2rad2' */
  0.0,                                 /* '<S578>/SinCos' */
  1.0,                                 /* '<S578>/SinCos' */
  0.00250000018F,                      /* '<S379>/Square' */
  0.14709F,                            /* '<S379>/Multiply' */
  -58.836F,                            /* '<S379>/Gain4' */
  0.0016F,                             /* '<S324>/Square' */
  0.0201061927F,                       /* '<S324>/Multiply' */
  -12.566371F,                         /* '<S324>/Gain4' */
  0.0016F,                             /* '<S323>/Square' */
  0.0201061927F,                       /* '<S323>/Multiply' */
  -12.566371F,                         /* '<S323>/Gain4' */
  0.0016F,                             /* '<S391>/Square' */
  0.0201061927F,                       /* '<S391>/Multiply' */
  -12.566371F,                         /* '<S391>/Gain4' */
  0.0016F,                             /* '<S390>/Square' */
  0.0201061927F,                       /* '<S390>/Multiply' */
  -12.566371F,                         /* '<S390>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S486>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S426>/Math Function' */
  1.0F,                                /* '<S426>/Sum of Elements' */
  1.0F,                                /* '<S426>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S426>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S426>/Switch' */

  { 0.0F, 1.0F },                      /* '<S426>/Divide' */
  0.616850317F,                        /* '<S422>/Square' */
  0.484473109F,                        /* '<S422>/Multiply' */
  -0.785398185F,                       /* '<S422>/Gain4' */
  0.00250000018F,                      /* '<S467>/Square' */
  0.14709F,                            /* '<S467>/Multiply' */
  -58.836F,                            /* '<S467>/Gain4' */
  0.00250000018F,                      /* '<S454>/Square' */
  0.196120009F,                        /* '<S454>/Multiply' */
  -78.448F,                            /* '<S454>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S562>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S566>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S570>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S569>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S499>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S501>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S592>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S594>/Vector Concatenate3' */
  0.616850317F,                        /* '<S633>/Square' */
  0.484473109F,                        /* '<S633>/Multiply' */
  -0.785398185F,                       /* '<S633>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S726>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S673>/Math Function' */
  1.0F,                                /* '<S673>/Sum of Elements' */
  1.0F,                                /* '<S673>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S673>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S673>/Switch' */

  { 0.0F, 1.0F },                      /* '<S673>/Divide' */
  0.616850317F,                        /* '<S669>/Square' */
  0.645964146F,                        /* '<S669>/Multiply' */
  -1.04719758F,                        /* '<S669>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S656>/Vector Concatenate3' */
  0.122499995F,                        /* '<S652>/Square' */
  1.20123494F,                         /* '<S652>/Multiply' */
  -9.806F,                             /* '<S652>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S737>/Vector Concatenate3' */
  0.122499995F,                        /* '<S733>/Square' */
  1.20123494F,                         /* '<S733>/Multiply' */
  -9.806F,                             /* '<S733>/Gain4' */

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
  3U,                                  /* '<S409>/Data Type Conversion' */
  4U,                                  /* '<S409>/Data Type Conversion1' */
  5U,                                  /* '<S409>/Data Type Conversion2' */
  3U,                                  /* '<S406>/Data Type Conversion' */
  3U,                                  /* '<S406>/Data Type Conversion1' */
  6U,                                  /* '<S406>/Data Type Conversion2' */
  3U,                                  /* '<S595>/Data Type Conversion' */
  6U,                                  /* '<S595>/Data Type Conversion1' */
  5U,                                  /* '<S595>/Data Type Conversion2' */
  3U,                                  /* '<S597>/Data Type Conversion' */
  16U,                                 /* '<S597>/Data Type Conversion1' */
  5U,                                  /* '<S597>/Data Type Conversion2' */
  3U,                                  /* '<S596>/Data Type Conversion' */
  15U,                                 /* '<S596>/Data Type Conversion1' */
  5U,                                  /* '<S596>/Data Type Conversion2' */
  3U,                                  /* '<S598>/Data Type Conversion' */
  17U,                                 /* '<S598>/Data Type Conversion1' */
  5U,                                  /* '<S598>/Data Type Conversion2' */
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
    1.9966471893352524,                /* '<S748>/Sum' */
    0.0066943799901413165,             /* '<S748>/Multiply3' */
    0.99330562000985867                /* '<S748>/Sum4' */
  }
  ,

  /* End of '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */

  /* Start of '<S6>/Vehicle.WaypointAngle' */
  {
    { 0.0F, 1.0F },                    /* synthesized block */

    { 0.0F, 1.0F },                    /* '<S762>/Math Function' */
    1.0F,                              /* '<S762>/Sum of Elements' */
    1.0F,                              /* '<S762>/Math Function1' */

    { 0.0F, 0.0F },                    /* '<S762>/Product' */

    { 0.0F, 1.0F, 1.0F },              /* '<S762>/Switch' */

    { 0.0F, 1.0F }                     /* '<S762>/Divide' */
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

  /* Start of '<S366>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S373>/Vector Concatenate3' */
  }
  ,

  /* End of '<S366>/Hold Control' */

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

  /* Start of '<S392>/Move Control' */
  {
    0.0004F,                           /* '<S402>/Square' */
    0.00628318498F,                    /* '<S402>/Multiply' */
    -15.707963F                        /* '<S402>/Gain4' */
  }
  ,

  /* End of '<S392>/Move Control' */

  /* Start of '<S293>/Unknown' */
  {
    1U,                                /* '<S407>/Data Type Conversion' */
    1U                                 /* '<S407>/Data Type Conversion1' */
  }
  ,

  /* End of '<S293>/Unknown' */

  /* Start of '<S456>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S463>/Vector Concatenate3' */
  }
  ,

  /* End of '<S456>/Hold Control' */

  /* Start of '<S295>/Unknown' */
  {
    1U,                                /* '<S599>/Data Type Conversion' */
    1U                                 /* '<S599>/Data Type Conversion1' */
  }
  ,

  /* End of '<S295>/Unknown' */

  /* Start of '<S635>/Move Control' */
  {
    0.00250000018F,                    /* '<S646>/Square' */
    0.14709F,                          /* '<S646>/Multiply' */
    -58.836F                           /* '<S646>/Gain4' */
  }
  ,

  /* End of '<S635>/Move Control' */

  /* Start of '<S635>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S642>/Vector Concatenate3' */
  }
  ,

  /* End of '<S635>/Hold Control' */

  /* Start of '<S614>/Move Control' */
  {
    0.0004F,                           /* '<S625>/Square' */
    0.00628318498F,                    /* '<S625>/Multiply' */
    -15.707963F                        /* '<S625>/Gain4' */
  }
  ,

  /* End of '<S614>/Move Control' */

  /* Start of '<S603>/Move Control' */
  {
    0.00250000018F,                    /* '<S611>/Square' */
    0.196120009F,                      /* '<S611>/Multiply' */
    -78.448F                           /* '<S611>/Gain4' */
  }
  ,

  /* End of '<S603>/Move Control' */

  /* Start of '<S696>/Move Control' */
  {
    0.00250000018F,                    /* '<S707>/Square' */
    0.14709F,                          /* '<S707>/Multiply' */
    -58.836F                           /* '<S707>/Gain4' */
  }
  ,

  /* End of '<S696>/Move Control' */

  /* Start of '<S696>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S703>/Vector Concatenate3' */
  }
  ,

  /* End of '<S696>/Hold Control' */

  /* Start of '<S686>/Move Control' */
  {
    0.00250000018F,                    /* '<S694>/Square' */
    0.196120009F,                      /* '<S694>/Multiply' */
    -78.448F                           /* '<S694>/Gain4' */
  }
  ,

  /* End of '<S686>/Move Control' */

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
