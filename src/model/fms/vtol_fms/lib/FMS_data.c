/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2548
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Sep 17 08:37:35 2025
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
  0.0100000007F,                       /* '<S416>/Square' */
  0.392240018F,                        /* '<S416>/Multiply' */
  -39.224F,                            /* '<S416>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S410>/Vector Concatenate3' */
  0.0016F,                             /* '<S362>/Square' */
  0.0201061927F,                       /* '<S362>/Multiply' */
  -12.566371F,                         /* '<S362>/Gain4' */
  0.0016F,                             /* '<S361>/Square' */
  0.0201061927F,                       /* '<S361>/Multiply' */
  -12.566371F,                         /* '<S361>/Gain4' */
  0.0016F,                             /* '<S428>/Square' */
  0.0201061927F,                       /* '<S428>/Multiply' */
  -12.566371F,                         /* '<S428>/Gain4' */
  0.0016F,                             /* '<S427>/Square' */
  0.0201061927F,                       /* '<S427>/Multiply' */
  -12.566371F,                         /* '<S427>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S523>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S463>/Math Function' */
  1.0F,                                /* '<S463>/Sum of Elements' */
  1.0F,                                /* '<S463>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S463>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S463>/Switch' */

  { 0.0F, 1.0F },                      /* '<S463>/Divide' */
  0.616850317F,                        /* '<S459>/Square' */
  0.484473109F,                        /* '<S459>/Multiply' */
  -0.785398185F,                       /* '<S459>/Gain4' */
  0.00250000018F,                      /* '<S504>/Square' */
  0.14709F,                            /* '<S504>/Multiply' */
  -58.836F,                            /* '<S504>/Gain4' */
  0.00250000018F,                      /* '<S491>/Square' */
  0.196120009F,                        /* '<S491>/Multiply' */
  -78.448F,                            /* '<S491>/Gain4' */

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

  { 0.0F, 0.0F, 1.0F },                /* '<S763>/Vector Concatenate3' */

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

  { 0.0F, 0.0F, 1.0F },                /* '<S774>/Vector Concatenate3' */
  0.122499995F,                        /* '<S770>/Square' */
  1.20123494F,                         /* '<S770>/Multiply' */
  -9.806F,                             /* '<S770>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S100>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S215>/Vector Concatenate3' */
  0.00250000018F,                      /* '<S218>/Square' */
  0.196120009F,                        /* '<S218>/Multiply' */
  -78.448F,                            /* '<S218>/Gain4' */
  0.0004F,                             /* '<S168>/Square' */
  0.00628318498F,                      /* '<S168>/Multiply' */
  -15.707963F,                         /* '<S168>/Gain4' */
  0.0016F,                             /* '<S145>/Square' */
  0.0201061927F,                       /* '<S145>/Multiply' */
  -12.566371F,                         /* '<S145>/Gain4' */
  0.00250000018F,                      /* '<S150>/Square' */
  0.196120009F,                        /* '<S150>/Multiply' */
  -78.448F,                            /* '<S150>/Gain4' */
  0.0004F,                             /* '<S148>/Square' */
  0.00628318498F,                      /* '<S148>/Multiply' */
  -15.707963F,                         /* '<S148>/Gain4' */
  0.0016F,                             /* '<S226>/Square' */
  0.0201061927F,                       /* '<S226>/Multiply' */
  -12.566371F,                         /* '<S226>/Gain4' */
  0.0004F,                             /* '<S230>/Square' */
  0.00628318498F,                      /* '<S230>/Multiply' */
  -15.707963F,                         /* '<S230>/Gain4' */
  0.0016F,                             /* '<S227>/Square' */
  0.0201061927F,                       /* '<S227>/Multiply' */
  -12.566371F,                         /* '<S227>/Gain4' */
  1U,                                  /* '<S332>/Data Type Conversion' */
  12U,                                 /* '<S332>/Data Type Conversion1' */
  3U,                                  /* '<S337>/Data Type Conversion' */
  10U,                                 /* '<S337>/Data Type Conversion1' */
  5U,                                  /* '<S337>/Data Type Conversion2' */
  3U,                                  /* '<S336>/Data Type Conversion1' */
  9U,                                  /* '<S336>/Data Type Conversion2' */
  4U,                                  /* '<S336>/Data Type Conversion3' */
  3U,                                  /* '<S338>/Data Type Conversion' */
  8U,                                  /* '<S338>/Data Type Conversion1' */
  3U,                                  /* '<S338>/Data Type Conversion2' */
  3U,                                  /* '<S335>/Data Type Conversion' */
  7U,                                  /* '<S335>/Data Type Conversion1' */
  2U,                                  /* '<S335>/Data Type Conversion2' */
  3U,                                  /* '<S446>/Data Type Conversion' */
  4U,                                  /* '<S446>/Data Type Conversion1' */
  5U,                                  /* '<S446>/Data Type Conversion2' */
  3U,                                  /* '<S443>/Data Type Conversion' */
  3U,                                  /* '<S443>/Data Type Conversion1' */
  6U,                                  /* '<S443>/Data Type Conversion2' */
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
  3U,                                  /* '<S121>/Data Type Conversion' */
  12U,                                 /* '<S121>/Data Type Conversion1' */
  1U,                                  /* '<S121>/Data Type Conversion2' */
  3U,                                  /* '<S125>/Data Type Conversion' */
  10U,                                 /* '<S125>/Data Type Conversion1' */
  5U,                                  /* '<S125>/Data Type Conversion2' */
  3U,                                  /* '<S124>/Data Type Conversion1' */
  9U,                                  /* '<S124>/Data Type Conversion2' */
  4U,                                  /* '<S124>/Data Type Conversion3' */
  3U,                                  /* '<S126>/Data Type Conversion' */
  8U,                                  /* '<S126>/Data Type Conversion1' */
  3U,                                  /* '<S126>/Data Type Conversion2' */
  3U,                                  /* '<S235>/Data Type Conversion' */
  4U,                                  /* '<S235>/Data Type Conversion1' */
  5U,                                  /* '<S235>/Data Type Conversion2' */
  1U,                                  /* '<S232>/Data Type Conversion' */
  3U,                                  /* '<S232>/Data Type Conversion1' */
  3U,                                  /* '<S263>/Data Type Conversion' */
  6U,                                  /* '<S263>/Data Type Conversion1' */
  5U,                                  /* '<S263>/Data Type Conversion2' */
  3U,                                  /* '<S265>/Data Type Conversion' */
  16U,                                 /* '<S265>/Data Type Conversion1' */
  5U,                                  /* '<S265>/Data Type Conversion2' */
  3U,                                  /* '<S264>/Data Type Conversion' */
  15U,                                 /* '<S264>/Data Type Conversion1' */
  5U,                                  /* '<S264>/Data Type Conversion2' */
  3U,                                  /* '<S266>/Data Type Conversion' */
  17U,                                 /* '<S266>/Data Type Conversion1' */
  5U,                                  /* '<S266>/Data Type Conversion2' */
  2U,                                  /* '<S47>/Data Type Conversion2' */
  2U,                                  /* '<S47>/Data Type Conversion1' */
  1U,                                  /* '<S46>/Data Type Conversion' */
  1U,                                  /* '<S46>/Data Type Conversion1' */

  /* Start of '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S789>/Sum' */
    0.0066943799901413165,             /* '<S789>/Multiply3' */
    0.99330562000985867                /* '<S789>/Sum4' */
  }
  ,

  /* End of '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */

  /* Start of '<S6>/Vehicle.WaypointAngle' */
  {
    { 0.0F, 1.0F },                    /* synthesized block */

    { 0.0F, 1.0F },                    /* '<S803>/Math Function' */
    1.0F,                              /* '<S803>/Sum of Elements' */
    1.0F,                              /* '<S803>/Math Function1' */

    { 0.0F, 0.0F },                    /* '<S803>/Product' */

    { 0.0F, 1.0F, 1.0F },              /* '<S803>/Switch' */

    { 0.0F, 1.0F }                     /* '<S803>/Divide' */
  }
  ,

  /* End of '<S6>/Vehicle.WaypointAngle' */

  /* Start of '<S50>/Unknown' */
  {
    1U,                                /* '<S334>/Data Type Conversion' */
    1U                                 /* '<S334>/Data Type Conversion1' */
  }
  ,

  /* End of '<S50>/Unknown' */

  /* Start of '<S330>/Unknown' */
  {
    1U,                                /* '<S339>/Data Type Conversion' */
    1U                                 /* '<S339>/Data Type Conversion1' */
  }
  ,

  /* End of '<S330>/Unknown' */

  /* Start of '<S391>/Move Control' */
  {
    0.0004F,                           /* '<S401>/Square' */
    0.00628318498F,                    /* '<S401>/Multiply' */
    -15.707963F                        /* '<S401>/Gain4' */
  }
  ,

  /* End of '<S391>/Move Control' */

  /* Start of '<S363>/Move Control' */
  {
    0.0004F,                           /* '<S373>/Square' */
    0.00628318498F,                    /* '<S373>/Multiply' */
    -15.707963F                        /* '<S373>/Gain4' */
  }
  ,

  /* End of '<S363>/Move Control' */

  /* Start of '<S429>/Move Control' */
  {
    0.0004F,                           /* '<S439>/Square' */
    0.00628318498F,                    /* '<S439>/Multiply' */
    -15.707963F                        /* '<S439>/Gain4' */
  }
  ,

  /* End of '<S429>/Move Control' */

  /* Start of '<S331>/Unknown' */
  {
    1U,                                /* '<S444>/Data Type Conversion' */
    1U                                 /* '<S444>/Data Type Conversion1' */
  }
  ,

  /* End of '<S331>/Unknown' */

  /* Start of '<S493>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S500>/Vector Concatenate3' */
  }
  ,

  /* End of '<S493>/Hold Control' */

  /* Start of '<S333>/Unknown' */
  {
    1U,                                /* '<S636>/Data Type Conversion' */
    1U                                 /* '<S636>/Data Type Conversion1' */
  }
  ,

  /* End of '<S333>/Unknown' */

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

  /* Start of '<S54>/Move Control' */
  {
    0.00250000018F,                    /* '<S95>/Square' */
    0.14709F,                          /* '<S95>/Multiply' */
    -58.836F                           /* '<S95>/Gain4' */
  }
  ,

  /* End of '<S54>/Move Control' */

  /* Start of '<S54>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F },              /* '<S88>/Vector Concatenate3' */
    0.0F                               /* '<S90>/Constant' */
  }
  ,

  /* End of '<S54>/Hold Control' */

  /* Start of '<S49>/Unknown' */
  {
    1U,                                /* '<S123>/Data Type Conversion' */
    1U                                 /* '<S123>/Data Type Conversion1' */
  }
  ,

  /* End of '<S49>/Unknown' */

  /* Start of '<S119>/Unknown' */
  {
    1U,                                /* '<S127>/Data Type Conversion' */
    1U                                 /* '<S127>/Data Type Conversion1' */
  }
  ,

  /* End of '<S119>/Unknown' */

  /* Start of '<S169>/Move Control' */
  {
    0.00250000018F,                    /* '<S210>/Square' */
    0.14709F,                          /* '<S210>/Multiply' */
    -58.836F                           /* '<S210>/Gain4' */
  }
  ,

  /* End of '<S169>/Move Control' */

  /* Start of '<S169>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F },              /* '<S203>/Vector Concatenate3' */
    0.0F                               /* '<S205>/Constant' */
  }
  ,

  /* End of '<S169>/Hold Control' */

  /* Start of '<S155>/Move Control' */
  {
    0.00250000018F,                    /* '<S163>/Square' */
    0.196120009F,                      /* '<S163>/Multiply' */
    -78.448F                           /* '<S163>/Gain4' */
  }
  ,

  /* End of '<S155>/Move Control' */

  /* Start of '<S132>/Move Control' */
  {
    0.00250000018F,                    /* '<S140>/Square' */
    0.196120009F,                      /* '<S140>/Multiply' */
    -78.448F                           /* '<S140>/Gain4' */
  }
  ,

  /* End of '<S132>/Move Control' */

  /* Start of '<S120>/Unknown' */
  {
    1U,                                /* '<S233>/Data Type Conversion' */
    1U                                 /* '<S233>/Data Type Conversion1' */
  }
  ,

  /* End of '<S120>/Unknown' */

  /* Start of '<S122>/Unknown' */
  {
    1U,                                /* '<S267>/Data Type Conversion' */
    1U                                 /* '<S267>/Data Type Conversion1' */
  }
  /* End of '<S122>/Unknown' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
