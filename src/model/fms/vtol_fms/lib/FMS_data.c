/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2602
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Nov 16 10:22:39 2026
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
  1.9966471893352524,                  /* '<S613>/Sum' */
  0.0066943799901413165,               /* '<S613>/Multiply3' */
  0.99330562000985867,                 /* '<S613>/Sum4' */
  0.0,                                 /* '<S612>/deg2rad2' */
  0.0,                                 /* '<S615>/SinCos' */
  1.0,                                 /* '<S615>/SinCos' */

  { 0.0F, 0.0F, 1.0F },                /* '<S15>/Vector Concatenate3' */
  0.0100000007F,                       /* '<S411>/Square' */
  0.392240018F,                        /* '<S411>/Multiply' */
  -39.224F,                            /* '<S411>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S405>/Vector Concatenate3' */
  0.0016F,                             /* '<S357>/Square' */
  0.0201061927F,                       /* '<S357>/Multiply' */
  -12.566371F,                         /* '<S357>/Gain4' */
  0.0016F,                             /* '<S356>/Square' */
  0.0201061927F,                       /* '<S356>/Multiply' */
  -12.566371F,                         /* '<S356>/Gain4' */
  0.0016F,                             /* '<S423>/Square' */
  0.0201061927F,                       /* '<S423>/Multiply' */
  -12.566371F,                         /* '<S423>/Gain4' */
  0.0016F,                             /* '<S422>/Square' */
  0.0201061927F,                       /* '<S422>/Multiply' */
  -12.566371F,                         /* '<S422>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S523>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S458>/Math Function' */
  1.0F,                                /* '<S458>/Sum of Elements' */
  1.0F,                                /* '<S458>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S458>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S458>/Switch' */

  { 0.0F, 1.0F },                      /* '<S458>/Divide' */
  0.616850317F,                        /* '<S454>/Square' */
  0.484473109F,                        /* '<S454>/Multiply' */
  -0.785398185F,                       /* '<S454>/Gain4' */
  0.00250000018F,                      /* '<S499>/Square' */
  0.14709F,                            /* '<S499>/Multiply' */
  -58.836F,                            /* '<S499>/Gain4' */
  0.00250000018F,                      /* '<S486>/Square' */
  0.196120009F,                        /* '<S486>/Multiply' */
  -78.448F,                            /* '<S486>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S599>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S603>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S607>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S606>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S536>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S538>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S629>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S631>/Vector Concatenate3' */
  0.616850317F,                        /* '<S670>/Square' */
  0.484473109F,                        /* '<S670>/Multiply' */
  -0.785398185F,                       /* '<S670>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S768>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S710>/Math Function' */
  1.0F,                                /* '<S710>/Sum of Elements' */
  1.0F,                                /* '<S710>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S710>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S710>/Switch' */

  { 0.0F, 1.0F },                      /* '<S710>/Divide' */
  0.616850317F,                        /* '<S706>/Square' */
  0.645964146F,                        /* '<S706>/Multiply' */
  -1.04719758F,                        /* '<S706>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S693>/Vector Concatenate3' */
  0.122499995F,                        /* '<S689>/Square' */
  1.20123494F,                         /* '<S689>/Multiply' */
  -9.806F,                             /* '<S689>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S779>/Vector Concatenate3' */
  0.122499995F,                        /* '<S775>/Square' */
  1.20123494F,                         /* '<S775>/Multiply' */
  -9.806F,                             /* '<S775>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S99>/Vector Concatenate3' */
  0.0004F,                             /* '<S107>/Square' */
  0.00628318498F,                      /* '<S107>/Multiply' */
  -15.707963F,                         /* '<S107>/Gain4' */
  0.0100000007F,                       /* '<S108>/Square' */
  0.392240018F,                        /* '<S108>/Multiply' */
  -39.224F,                            /* '<S108>/Gain4' */
  0.0100000007F,                       /* '<S106>/Square' */
  0.392240018F,                        /* '<S106>/Multiply' */
  -39.224F,                            /* '<S106>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S208>/Vector Concatenate3' */
  0.00250000018F,                      /* '<S156>/Square' */
  0.196120009F,                        /* '<S156>/Multiply' */
  -78.448F,                            /* '<S156>/Gain4' */
  0.00250000018F,                      /* '<S211>/Square' */
  0.196120009F,                        /* '<S211>/Multiply' */
  -78.448F,                            /* '<S211>/Gain4' */
  0.0004F,                             /* '<S161>/Square' */
  0.00628318498F,                      /* '<S161>/Multiply' */
  -15.707963F,                         /* '<S161>/Gain4' */
  0.00250000018F,                      /* '<S131>/Square' */
  0.196120009F,                        /* '<S131>/Multiply' */
  -78.448F,                            /* '<S131>/Gain4' */
  0.00250000018F,                      /* '<S142>/Square' */
  0.196120009F,                        /* '<S142>/Multiply' */
  -78.448F,                            /* '<S142>/Gain4' */
  0.0004F,                             /* '<S139>/Square' */
  0.00628318498F,                      /* '<S139>/Multiply' */
  -15.707963F,                         /* '<S139>/Gain4' */
  0.0016F,                             /* '<S136>/Square' */
  0.0201061927F,                       /* '<S136>/Multiply' */
  -12.566371F,                         /* '<S136>/Gain4' */
  0.0016F,                             /* '<S219>/Square' */
  0.0201061927F,                       /* '<S219>/Multiply' */
  -12.566371F,                         /* '<S219>/Gain4' */
  0.0004F,                             /* '<S223>/Square' */
  0.00628318498F,                      /* '<S223>/Multiply' */
  -15.707963F,                         /* '<S223>/Gain4' */
  0.0016F,                             /* '<S220>/Square' */
  0.0201061927F,                       /* '<S220>/Multiply' */
  -12.566371F,                         /* '<S220>/Gain4' */
  0.00250000018F,                      /* '<S236>/Square' */
  0.196120009F,                        /* '<S236>/Multiply' */
  -78.448F,                            /* '<S236>/Gain4' */
  1U,                                  /* '<S327>/Data Type Conversion' */
  12U,                                 /* '<S327>/Data Type Conversion1' */
  3U,                                  /* '<S332>/Data Type Conversion' */
  10U,                                 /* '<S332>/Data Type Conversion1' */
  5U,                                  /* '<S332>/Data Type Conversion2' */
  3U,                                  /* '<S331>/Data Type Conversion1' */
  9U,                                  /* '<S331>/Data Type Conversion2' */
  4U,                                  /* '<S331>/Data Type Conversion3' */
  3U,                                  /* '<S333>/Data Type Conversion' */
  8U,                                  /* '<S333>/Data Type Conversion1' */
  3U,                                  /* '<S333>/Data Type Conversion2' */
  3U,                                  /* '<S330>/Data Type Conversion' */
  7U,                                  /* '<S330>/Data Type Conversion1' */
  2U,                                  /* '<S330>/Data Type Conversion2' */
  3U,                                  /* '<S441>/Data Type Conversion' */
  4U,                                  /* '<S441>/Data Type Conversion1' */
  5U,                                  /* '<S441>/Data Type Conversion2' */
  3U,                                  /* '<S438>/Data Type Conversion' */
  3U,                                  /* '<S438>/Data Type Conversion1' */
  6U,                                  /* '<S438>/Data Type Conversion2' */
  3U,                                  /* '<S632>/Data Type Conversion' */
  6U,                                  /* '<S632>/Data Type Conversion1' */
  5U,                                  /* '<S632>/Data Type Conversion2' */
  3U,                                  /* '<S634>/Data Type Conversion' */
  16U,                                 /* '<S634>/Data Type Conversion1' */
  5U,                                  /* '<S634>/Data Type Conversion2' */
  3U,                                  /* '<S633>/Data Type Conversion' */
  15U,                                 /* '<S633>/Data Type Conversion1' */
  5U,                                  /* '<S633>/Data Type Conversion2' */
  3U,                                  /* '<S635>/Data Type Conversion' */
  17U,                                 /* '<S635>/Data Type Conversion1' */
  5U,                                  /* '<S635>/Data Type Conversion2' */
  3U,                                  /* '<S48>/Data Type Conversion1' */
  6U,                                  /* '<S48>/Data Type Conversion2' */
  5U,                                  /* '<S48>/Data Type Conversion3' */
  3U,                                  /* '<S111>/Data Type Conversion' */
  12U,                                 /* '<S111>/Data Type Conversion1' */
  1U,                                  /* '<S111>/Data Type Conversion2' */
  3U,                                  /* '<S115>/Data Type Conversion' */
  10U,                                 /* '<S115>/Data Type Conversion1' */
  5U,                                  /* '<S115>/Data Type Conversion2' */
  3U,                                  /* '<S114>/Data Type Conversion1' */
  9U,                                  /* '<S114>/Data Type Conversion2' */
  4U,                                  /* '<S114>/Data Type Conversion3' */
  3U,                                  /* '<S116>/Data Type Conversion' */
  8U,                                  /* '<S116>/Data Type Conversion1' */
  3U,                                  /* '<S116>/Data Type Conversion2' */
  3U,                                  /* '<S228>/Data Type Conversion' */
  4U,                                  /* '<S228>/Data Type Conversion1' */
  5U,                                  /* '<S228>/Data Type Conversion2' */
  1U,                                  /* '<S225>/Data Type Conversion' */
  3U,                                  /* '<S225>/Data Type Conversion1' */
  3U,                                  /* '<S258>/Data Type Conversion' */
  6U,                                  /* '<S258>/Data Type Conversion1' */
  5U,                                  /* '<S258>/Data Type Conversion2' */
  3U,                                  /* '<S260>/Data Type Conversion' */
  16U,                                 /* '<S260>/Data Type Conversion1' */
  5U,                                  /* '<S260>/Data Type Conversion2' */
  3U,                                  /* '<S259>/Data Type Conversion' */
  15U,                                 /* '<S259>/Data Type Conversion1' */
  5U,                                  /* '<S259>/Data Type Conversion2' */
  3U,                                  /* '<S261>/Data Type Conversion' */
  17U,                                 /* '<S261>/Data Type Conversion1' */
  5U,                                  /* '<S261>/Data Type Conversion2' */
  2U,                                  /* '<S47>/Data Type Conversion2' */
  2U,                                  /* '<S47>/Data Type Conversion1' */
  1U,                                  /* '<S46>/Data Type Conversion' */
  1U,                                  /* '<S46>/Data Type Conversion1' */

  /* Start of '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S794>/Sum' */
    0.0066943799901413165,             /* '<S794>/Multiply3' */
    0.99330562000985867                /* '<S794>/Sum4' */
  }
  ,

  /* End of '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */

  /* Start of '<S6>/Vehicle.WaypointAngle' */
  {
    { 0.0F, 1.0F },                    /* synthesized block */

    { 0.0F, 1.0F },                    /* '<S808>/Math Function' */
    1.0F,                              /* '<S808>/Sum of Elements' */
    1.0F,                              /* '<S808>/Math Function1' */

    { 0.0F, 0.0F },                    /* '<S808>/Product' */

    { 0.0F, 1.0F, 1.0F },              /* '<S808>/Switch' */

    { 0.0F, 1.0F }                     /* '<S808>/Divide' */
  }
  ,

  /* End of '<S6>/Vehicle.WaypointAngle' */

  /* Start of '<S50>/Unknown' */
  {
    1U,                                /* '<S329>/Data Type Conversion' */
    1U                                 /* '<S329>/Data Type Conversion1' */
  }
  ,

  /* End of '<S50>/Unknown' */

  /* Start of '<S325>/Unknown' */
  {
    1U,                                /* '<S334>/Data Type Conversion' */
    1U                                 /* '<S334>/Data Type Conversion1' */
  }
  ,

  /* End of '<S325>/Unknown' */

  /* Start of '<S386>/Move Control' */
  {
    0.0004F,                           /* '<S396>/Square' */
    0.00628318498F,                    /* '<S396>/Multiply' */
    -15.707963F                        /* '<S396>/Gain4' */
  }
  ,

  /* End of '<S386>/Move Control' */

  /* Start of '<S358>/Move Control' */
  {
    0.0004F,                           /* '<S368>/Square' */
    0.00628318498F,                    /* '<S368>/Multiply' */
    -15.707963F                        /* '<S368>/Gain4' */
  }
  ,

  /* End of '<S358>/Move Control' */

  /* Start of '<S424>/Move Control' */
  {
    0.0004F,                           /* '<S434>/Square' */
    0.00628318498F,                    /* '<S434>/Multiply' */
    -15.707963F                        /* '<S434>/Gain4' */
  }
  ,

  /* End of '<S424>/Move Control' */

  /* Start of '<S326>/Unknown' */
  {
    1U,                                /* '<S439>/Data Type Conversion' */
    1U                                 /* '<S439>/Data Type Conversion1' */
  }
  ,

  /* End of '<S326>/Unknown' */

  /* Start of '<S488>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S495>/Vector Concatenate3' */
  }
  ,

  /* End of '<S488>/Hold Control' */

  /* Start of '<S328>/Unknown' */
  {
    1U,                                /* '<S636>/Data Type Conversion' */
    1U                                 /* '<S636>/Data Type Conversion1' */
  }
  ,

  /* End of '<S328>/Unknown' */

  /* Start of '<S672>/Move Control' */
  {
    0.00250000018F,                    /* '<S683>/Square' */
    0.14709F,                          /* '<S683>/Multiply' */
    -58.836F                           /* '<S683>/Gain4' */
  }
  ,

  /* End of '<S672>/Move Control' */

  /* Start of '<S672>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S679>/Vector Concatenate3' */
  }
  ,

  /* End of '<S672>/Hold Control' */

  /* Start of '<S651>/Move Control' */
  {
    0.0004F,                           /* '<S662>/Square' */
    0.00628318498F,                    /* '<S662>/Multiply' */
    -15.707963F                        /* '<S662>/Gain4' */
  }
  ,

  /* End of '<S651>/Move Control' */

  /* Start of '<S640>/Move Control' */
  {
    0.00250000018F,                    /* '<S648>/Square' */
    0.196120009F,                      /* '<S648>/Multiply' */
    -78.448F                           /* '<S648>/Gain4' */
  }
  ,

  /* End of '<S640>/Move Control' */

  /* Start of '<S733>/Move Control' */
  {
    0.00250000018F,                    /* '<S744>/Square' */
    0.14709F,                          /* '<S744>/Multiply' */
    -58.836F                           /* '<S744>/Gain4' */
  }
  ,

  /* End of '<S733>/Move Control' */

  /* Start of '<S733>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S740>/Vector Concatenate3' */
  }
  ,

  /* End of '<S733>/Hold Control' */

  /* Start of '<S723>/Move Control' */
  {
    0.00250000018F,                    /* '<S731>/Square' */
    0.196120009F,                      /* '<S731>/Multiply' */
    -78.448F                           /* '<S731>/Gain4' */
  }
  ,

  /* End of '<S723>/Move Control' */

  /* Start of '<S53>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F },              /* '<S87>/Vector Concatenate3' */
    0.0F                               /* '<S89>/Constant' */
  }
  ,

  /* End of '<S53>/Hold Control' */

  /* Start of '<S49>/Unknown' */
  {
    1U,                                /* '<S113>/Data Type Conversion' */
    1U                                 /* '<S113>/Data Type Conversion1' */
  }
  ,

  /* End of '<S49>/Unknown' */

  /* Start of '<S109>/Unknown' */
  {
    1U,                                /* '<S117>/Data Type Conversion' */
    1U                                 /* '<S117>/Data Type Conversion1' */
  }
  ,

  /* End of '<S109>/Unknown' */

  /* Start of '<S162>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F },              /* '<S196>/Vector Concatenate3' */
    0.0F                               /* '<S198>/Constant' */
  }
  ,

  /* End of '<S162>/Hold Control' */

  /* Start of '<S147>/Move Control' */
  {
    0.00250000018F,                    /* '<S155>/Square' */
    0.196120009F,                      /* '<S155>/Multiply' */
    -78.448F                           /* '<S155>/Gain4' */
  }
  ,

  /* End of '<S147>/Move Control' */

  /* Start of '<S122>/Move Control' */
  {
    0.00250000018F,                    /* '<S130>/Square' */
    0.196120009F,                      /* '<S130>/Multiply' */
    -78.448F                           /* '<S130>/Gain4' */
  }
  ,

  /* End of '<S122>/Move Control' */

  /* Start of '<S110>/Unknown' */
  {
    1U,                                /* '<S226>/Data Type Conversion' */
    1U                                 /* '<S226>/Data Type Conversion1' */
  }
  ,

  /* End of '<S110>/Unknown' */

  /* Start of '<S112>/Unknown' */
  {
    1U,                                /* '<S262>/Data Type Conversion' */
    1U                                 /* '<S262>/Data Type Conversion1' */
  }
  /* End of '<S112>/Unknown' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
