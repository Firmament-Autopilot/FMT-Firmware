/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2597
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Dec 22 15:58:58 2025
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
  1.9966471893352524,                  /* '<S607>/Sum' */
  0.0066943799901413165,               /* '<S607>/Multiply3' */
  0.99330562000985867,                 /* '<S607>/Sum4' */
  0.0,                                 /* '<S606>/deg2rad2' */
  0.0,                                 /* '<S609>/SinCos' */
  1.0,                                 /* '<S609>/SinCos' */

  { 0.0F, 0.0F, 1.0F },                /* '<S15>/Vector Concatenate3' */
  0.0100000007F,                       /* '<S410>/Square' */
  0.392240018F,                        /* '<S410>/Multiply' */
  -39.224F,                            /* '<S410>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S404>/Vector Concatenate3' */
  0.0016F,                             /* '<S356>/Square' */
  0.0201061927F,                       /* '<S356>/Multiply' */
  -12.566371F,                         /* '<S356>/Gain4' */
  0.0016F,                             /* '<S355>/Square' */
  0.0201061927F,                       /* '<S355>/Multiply' */
  -12.566371F,                         /* '<S355>/Gain4' */
  0.0016F,                             /* '<S422>/Square' */
  0.0201061927F,                       /* '<S422>/Multiply' */
  -12.566371F,                         /* '<S422>/Gain4' */
  0.0016F,                             /* '<S421>/Square' */
  0.0201061927F,                       /* '<S421>/Multiply' */
  -12.566371F,                         /* '<S421>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S517>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S457>/Math Function' */
  1.0F,                                /* '<S457>/Sum of Elements' */
  1.0F,                                /* '<S457>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S457>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S457>/Switch' */

  { 0.0F, 1.0F },                      /* '<S457>/Divide' */
  0.616850317F,                        /* '<S453>/Square' */
  0.484473109F,                        /* '<S453>/Multiply' */
  -0.785398185F,                       /* '<S453>/Gain4' */
  0.00250000018F,                      /* '<S498>/Square' */
  0.14709F,                            /* '<S498>/Multiply' */
  -58.836F,                            /* '<S498>/Gain4' */
  0.00250000018F,                      /* '<S485>/Square' */
  0.196120009F,                        /* '<S485>/Multiply' */
  -78.448F,                            /* '<S485>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S593>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S597>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S601>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S600>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S530>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S532>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S623>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S625>/Vector Concatenate3' */
  0.616850317F,                        /* '<S664>/Square' */
  0.484473109F,                        /* '<S664>/Multiply' */
  -0.785398185F,                       /* '<S664>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S757>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S704>/Math Function' */
  1.0F,                                /* '<S704>/Sum of Elements' */
  1.0F,                                /* '<S704>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S704>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S704>/Switch' */

  { 0.0F, 1.0F },                      /* '<S704>/Divide' */
  0.616850317F,                        /* '<S700>/Square' */
  0.645964146F,                        /* '<S700>/Multiply' */
  -1.04719758F,                        /* '<S700>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S687>/Vector Concatenate3' */
  0.122499995F,                        /* '<S683>/Square' */
  1.20123494F,                         /* '<S683>/Multiply' */
  -9.806F,                             /* '<S683>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S768>/Vector Concatenate3' */
  0.122499995F,                        /* '<S764>/Square' */
  1.20123494F,                         /* '<S764>/Multiply' */
  -9.806F,                             /* '<S764>/Gain4' */

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

  { 0.0F, 0.0F, 1.0F },                /* '<S207>/Vector Concatenate3' */
  0.00250000018F,                      /* '<S156>/Square' */
  0.196120009F,                        /* '<S156>/Multiply' */
  -78.448F,                            /* '<S156>/Gain4' */
  0.00250000018F,                      /* '<S210>/Square' */
  0.196120009F,                        /* '<S210>/Multiply' */
  -78.448F,                            /* '<S210>/Gain4' */
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
  0.0016F,                             /* '<S218>/Square' */
  0.0201061927F,                       /* '<S218>/Multiply' */
  -12.566371F,                         /* '<S218>/Gain4' */
  0.0004F,                             /* '<S222>/Square' */
  0.00628318498F,                      /* '<S222>/Multiply' */
  -15.707963F,                         /* '<S222>/Gain4' */
  0.0016F,                             /* '<S219>/Square' */
  0.0201061927F,                       /* '<S219>/Multiply' */
  -12.566371F,                         /* '<S219>/Gain4' */
  0.00250000018F,                      /* '<S235>/Square' */
  0.196120009F,                        /* '<S235>/Multiply' */
  -78.448F,                            /* '<S235>/Gain4' */
  1U,                                  /* '<S326>/Data Type Conversion' */
  12U,                                 /* '<S326>/Data Type Conversion1' */
  3U,                                  /* '<S331>/Data Type Conversion' */
  10U,                                 /* '<S331>/Data Type Conversion1' */
  5U,                                  /* '<S331>/Data Type Conversion2' */
  3U,                                  /* '<S330>/Data Type Conversion1' */
  9U,                                  /* '<S330>/Data Type Conversion2' */
  4U,                                  /* '<S330>/Data Type Conversion3' */
  3U,                                  /* '<S332>/Data Type Conversion' */
  8U,                                  /* '<S332>/Data Type Conversion1' */
  3U,                                  /* '<S332>/Data Type Conversion2' */
  3U,                                  /* '<S329>/Data Type Conversion' */
  7U,                                  /* '<S329>/Data Type Conversion1' */
  2U,                                  /* '<S329>/Data Type Conversion2' */
  3U,                                  /* '<S440>/Data Type Conversion' */
  4U,                                  /* '<S440>/Data Type Conversion1' */
  5U,                                  /* '<S440>/Data Type Conversion2' */
  3U,                                  /* '<S437>/Data Type Conversion' */
  3U,                                  /* '<S437>/Data Type Conversion1' */
  6U,                                  /* '<S437>/Data Type Conversion2' */
  3U,                                  /* '<S626>/Data Type Conversion' */
  6U,                                  /* '<S626>/Data Type Conversion1' */
  5U,                                  /* '<S626>/Data Type Conversion2' */
  3U,                                  /* '<S628>/Data Type Conversion' */
  16U,                                 /* '<S628>/Data Type Conversion1' */
  5U,                                  /* '<S628>/Data Type Conversion2' */
  3U,                                  /* '<S627>/Data Type Conversion' */
  15U,                                 /* '<S627>/Data Type Conversion1' */
  5U,                                  /* '<S627>/Data Type Conversion2' */
  3U,                                  /* '<S629>/Data Type Conversion' */
  17U,                                 /* '<S629>/Data Type Conversion1' */
  5U,                                  /* '<S629>/Data Type Conversion2' */
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
  3U,                                  /* '<S227>/Data Type Conversion' */
  4U,                                  /* '<S227>/Data Type Conversion1' */
  5U,                                  /* '<S227>/Data Type Conversion2' */
  1U,                                  /* '<S224>/Data Type Conversion' */
  3U,                                  /* '<S224>/Data Type Conversion1' */
  3U,                                  /* '<S257>/Data Type Conversion' */
  6U,                                  /* '<S257>/Data Type Conversion1' */
  5U,                                  /* '<S257>/Data Type Conversion2' */
  3U,                                  /* '<S259>/Data Type Conversion' */
  16U,                                 /* '<S259>/Data Type Conversion1' */
  5U,                                  /* '<S259>/Data Type Conversion2' */
  3U,                                  /* '<S258>/Data Type Conversion' */
  15U,                                 /* '<S258>/Data Type Conversion1' */
  5U,                                  /* '<S258>/Data Type Conversion2' */
  3U,                                  /* '<S260>/Data Type Conversion' */
  17U,                                 /* '<S260>/Data Type Conversion1' */
  5U,                                  /* '<S260>/Data Type Conversion2' */
  2U,                                  /* '<S47>/Data Type Conversion2' */
  2U,                                  /* '<S47>/Data Type Conversion1' */
  1U,                                  /* '<S46>/Data Type Conversion' */
  1U,                                  /* '<S46>/Data Type Conversion1' */

  /* Start of '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S783>/Sum' */
    0.0066943799901413165,             /* '<S783>/Multiply3' */
    0.99330562000985867                /* '<S783>/Sum4' */
  }
  ,

  /* End of '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */

  /* Start of '<S6>/Vehicle.WaypointAngle' */
  {
    { 0.0F, 1.0F },                    /* synthesized block */

    { 0.0F, 1.0F },                    /* '<S797>/Math Function' */
    1.0F,                              /* '<S797>/Sum of Elements' */
    1.0F,                              /* '<S797>/Math Function1' */

    { 0.0F, 0.0F },                    /* '<S797>/Product' */

    { 0.0F, 1.0F, 1.0F },              /* '<S797>/Switch' */

    { 0.0F, 1.0F }                     /* '<S797>/Divide' */
  }
  ,

  /* End of '<S6>/Vehicle.WaypointAngle' */

  /* Start of '<S50>/Unknown' */
  {
    1U,                                /* '<S328>/Data Type Conversion' */
    1U                                 /* '<S328>/Data Type Conversion1' */
  }
  ,

  /* End of '<S50>/Unknown' */

  /* Start of '<S324>/Unknown' */
  {
    1U,                                /* '<S333>/Data Type Conversion' */
    1U                                 /* '<S333>/Data Type Conversion1' */
  }
  ,

  /* End of '<S324>/Unknown' */

  /* Start of '<S385>/Move Control' */
  {
    0.0004F,                           /* '<S395>/Square' */
    0.00628318498F,                    /* '<S395>/Multiply' */
    -15.707963F                        /* '<S395>/Gain4' */
  }
  ,

  /* End of '<S385>/Move Control' */

  /* Start of '<S357>/Move Control' */
  {
    0.0004F,                           /* '<S367>/Square' */
    0.00628318498F,                    /* '<S367>/Multiply' */
    -15.707963F                        /* '<S367>/Gain4' */
  }
  ,

  /* End of '<S357>/Move Control' */

  /* Start of '<S423>/Move Control' */
  {
    0.0004F,                           /* '<S433>/Square' */
    0.00628318498F,                    /* '<S433>/Multiply' */
    -15.707963F                        /* '<S433>/Gain4' */
  }
  ,

  /* End of '<S423>/Move Control' */

  /* Start of '<S325>/Unknown' */
  {
    1U,                                /* '<S438>/Data Type Conversion' */
    1U                                 /* '<S438>/Data Type Conversion1' */
  }
  ,

  /* End of '<S325>/Unknown' */

  /* Start of '<S487>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S494>/Vector Concatenate3' */
  }
  ,

  /* End of '<S487>/Hold Control' */

  /* Start of '<S327>/Unknown' */
  {
    1U,                                /* '<S630>/Data Type Conversion' */
    1U                                 /* '<S630>/Data Type Conversion1' */
  }
  ,

  /* End of '<S327>/Unknown' */

  /* Start of '<S666>/Move Control' */
  {
    0.00250000018F,                    /* '<S677>/Square' */
    0.14709F,                          /* '<S677>/Multiply' */
    -58.836F                           /* '<S677>/Gain4' */
  }
  ,

  /* End of '<S666>/Move Control' */

  /* Start of '<S666>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S673>/Vector Concatenate3' */
  }
  ,

  /* End of '<S666>/Hold Control' */

  /* Start of '<S645>/Move Control' */
  {
    0.0004F,                           /* '<S656>/Square' */
    0.00628318498F,                    /* '<S656>/Multiply' */
    -15.707963F                        /* '<S656>/Gain4' */
  }
  ,

  /* End of '<S645>/Move Control' */

  /* Start of '<S634>/Move Control' */
  {
    0.00250000018F,                    /* '<S642>/Square' */
    0.196120009F,                      /* '<S642>/Multiply' */
    -78.448F                           /* '<S642>/Gain4' */
  }
  ,

  /* End of '<S634>/Move Control' */

  /* Start of '<S727>/Move Control' */
  {
    0.00250000018F,                    /* '<S738>/Square' */
    0.14709F,                          /* '<S738>/Multiply' */
    -58.836F                           /* '<S738>/Gain4' */
  }
  ,

  /* End of '<S727>/Move Control' */

  /* Start of '<S727>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S734>/Vector Concatenate3' */
  }
  ,

  /* End of '<S727>/Hold Control' */

  /* Start of '<S717>/Move Control' */
  {
    0.00250000018F,                    /* '<S725>/Square' */
    0.196120009F,                      /* '<S725>/Multiply' */
    -78.448F                           /* '<S725>/Gain4' */
  }
  ,

  /* End of '<S717>/Move Control' */

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
    { 0.0F, 0.0F, 1.0F },              /* '<S195>/Vector Concatenate3' */
    0.0F                               /* '<S197>/Constant' */
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
    1U,                                /* '<S225>/Data Type Conversion' */
    1U                                 /* '<S225>/Data Type Conversion1' */
  }
  ,

  /* End of '<S110>/Unknown' */

  /* Start of '<S112>/Unknown' */
  {
    1U,                                /* '<S261>/Data Type Conversion' */
    1U                                 /* '<S261>/Data Type Conversion1' */
  }
  /* End of '<S112>/Unknown' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
