/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2533
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Sep 15 11:08:00 2025
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
  1.9966471893352524,                  /* '<S579>/Sum' */
  0.0066943799901413165,               /* '<S579>/Multiply3' */
  0.99330562000985867,                 /* '<S579>/Sum4' */
  0.0,                                 /* '<S578>/deg2rad2' */
  0.0,                                 /* '<S581>/SinCos' */
  1.0,                                 /* '<S581>/SinCos' */
  0.0100000007F,                       /* '<S382>/Square' */
  0.392240018F,                        /* '<S382>/Multiply' */
  -39.224F,                            /* '<S382>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S376>/Vector Concatenate3' */
  0.0016F,                             /* '<S328>/Square' */
  0.0201061927F,                       /* '<S328>/Multiply' */
  -12.566371F,                         /* '<S328>/Gain4' */
  0.0016F,                             /* '<S327>/Square' */
  0.0201061927F,                       /* '<S327>/Multiply' */
  -12.566371F,                         /* '<S327>/Gain4' */
  0.0016F,                             /* '<S394>/Square' */
  0.0201061927F,                       /* '<S394>/Multiply' */
  -12.566371F,                         /* '<S394>/Gain4' */
  0.0016F,                             /* '<S393>/Square' */
  0.0201061927F,                       /* '<S393>/Multiply' */
  -12.566371F,                         /* '<S393>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S489>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S429>/Math Function' */
  1.0F,                                /* '<S429>/Sum of Elements' */
  1.0F,                                /* '<S429>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S429>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S429>/Switch' */

  { 0.0F, 1.0F },                      /* '<S429>/Divide' */
  0.616850317F,                        /* '<S425>/Square' */
  0.484473109F,                        /* '<S425>/Multiply' */
  -0.785398185F,                       /* '<S425>/Gain4' */
  0.00250000018F,                      /* '<S470>/Square' */
  0.14709F,                            /* '<S470>/Multiply' */
  -58.836F,                            /* '<S470>/Gain4' */
  0.00250000018F,                      /* '<S457>/Square' */
  0.196120009F,                        /* '<S457>/Multiply' */
  -78.448F,                            /* '<S457>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S565>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S569>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S573>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S572>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S502>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S504>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S595>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S597>/Vector Concatenate3' */
  0.616850317F,                        /* '<S636>/Square' */
  0.484473109F,                        /* '<S636>/Multiply' */
  -0.785398185F,                       /* '<S636>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S729>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S676>/Math Function' */
  1.0F,                                /* '<S676>/Sum of Elements' */
  1.0F,                                /* '<S676>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S676>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S676>/Switch' */

  { 0.0F, 1.0F },                      /* '<S676>/Divide' */
  0.616850317F,                        /* '<S672>/Square' */
  0.645964146F,                        /* '<S672>/Multiply' */
  -1.04719758F,                        /* '<S672>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S659>/Vector Concatenate3' */
  0.122499995F,                        /* '<S655>/Square' */
  1.20123494F,                         /* '<S655>/Multiply' */
  -9.806F,                             /* '<S655>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S740>/Vector Concatenate3' */
  0.122499995F,                        /* '<S736>/Square' */
  1.20123494F,                         /* '<S736>/Multiply' */
  -9.806F,                             /* '<S736>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S75>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S80>/Vector Concatenate3' */
  0.0F,                                /* '<S82>/Constant' */

  { 0.0F, 0.0F, 1.0F },                /* '<S181>/Vector Concatenate3' */
  0.00250000018F,                      /* '<S184>/Square' */
  0.196120009F,                        /* '<S184>/Multiply' */
  -78.448F,                            /* '<S184>/Gain4' */
  0.0004F,                             /* '<S134>/Square' */
  0.00628318498F,                      /* '<S134>/Multiply' */
  -15.707963F,                         /* '<S134>/Gain4' */
  0.00250000018F,                      /* '<S176>/Square' */
  0.14709F,                            /* '<S176>/Multiply' */
  -58.836F,                            /* '<S176>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S169>/Vector Concatenate3' */
  0.0F,                                /* '<S171>/Constant' */
  0.0016F,                             /* '<S111>/Square' */
  0.0201061927F,                       /* '<S111>/Multiply' */
  -12.566371F,                         /* '<S111>/Gain4' */
  0.00250000018F,                      /* '<S116>/Square' */
  0.196120009F,                        /* '<S116>/Multiply' */
  -78.448F,                            /* '<S116>/Gain4' */
  0.0004F,                             /* '<S114>/Square' */
  0.00628318498F,                      /* '<S114>/Multiply' */
  -15.707963F,                         /* '<S114>/Gain4' */
  0.0016F,                             /* '<S192>/Square' */
  0.0201061927F,                       /* '<S192>/Multiply' */
  -12.566371F,                         /* '<S192>/Gain4' */
  0.0004F,                             /* '<S196>/Square' */
  0.00628318498F,                      /* '<S196>/Multiply' */
  -15.707963F,                         /* '<S196>/Gain4' */
  0.0016F,                             /* '<S193>/Square' */
  0.0201061927F,                       /* '<S193>/Multiply' */
  -12.566371F,                         /* '<S193>/Gain4' */
  1U,                                  /* '<S298>/Data Type Conversion' */
  12U,                                 /* '<S298>/Data Type Conversion1' */
  3U,                                  /* '<S303>/Data Type Conversion' */
  10U,                                 /* '<S303>/Data Type Conversion1' */
  5U,                                  /* '<S303>/Data Type Conversion2' */
  3U,                                  /* '<S302>/Data Type Conversion1' */
  9U,                                  /* '<S302>/Data Type Conversion2' */
  4U,                                  /* '<S302>/Data Type Conversion3' */
  3U,                                  /* '<S304>/Data Type Conversion' */
  8U,                                  /* '<S304>/Data Type Conversion1' */
  3U,                                  /* '<S304>/Data Type Conversion2' */
  3U,                                  /* '<S301>/Data Type Conversion' */
  7U,                                  /* '<S301>/Data Type Conversion1' */
  2U,                                  /* '<S301>/Data Type Conversion2' */
  3U,                                  /* '<S412>/Data Type Conversion' */
  4U,                                  /* '<S412>/Data Type Conversion1' */
  5U,                                  /* '<S412>/Data Type Conversion2' */
  3U,                                  /* '<S409>/Data Type Conversion' */
  3U,                                  /* '<S409>/Data Type Conversion1' */
  6U,                                  /* '<S409>/Data Type Conversion2' */
  3U,                                  /* '<S598>/Data Type Conversion' */
  6U,                                  /* '<S598>/Data Type Conversion1' */
  5U,                                  /* '<S598>/Data Type Conversion2' */
  3U,                                  /* '<S600>/Data Type Conversion' */
  16U,                                 /* '<S600>/Data Type Conversion1' */
  5U,                                  /* '<S600>/Data Type Conversion2' */
  3U,                                  /* '<S599>/Data Type Conversion' */
  15U,                                 /* '<S599>/Data Type Conversion1' */
  5U,                                  /* '<S599>/Data Type Conversion2' */
  3U,                                  /* '<S601>/Data Type Conversion' */
  17U,                                 /* '<S601>/Data Type Conversion1' */
  5U,                                  /* '<S601>/Data Type Conversion2' */
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
  3U,                                  /* '<S201>/Data Type Conversion' */
  4U,                                  /* '<S201>/Data Type Conversion1' */
  5U,                                  /* '<S201>/Data Type Conversion2' */
  1U,                                  /* '<S198>/Data Type Conversion' */
  3U,                                  /* '<S198>/Data Type Conversion1' */
  3U,                                  /* '<S229>/Data Type Conversion' */
  6U,                                  /* '<S229>/Data Type Conversion1' */
  5U,                                  /* '<S229>/Data Type Conversion2' */
  3U,                                  /* '<S231>/Data Type Conversion' */
  16U,                                 /* '<S231>/Data Type Conversion1' */
  5U,                                  /* '<S231>/Data Type Conversion2' */
  3U,                                  /* '<S230>/Data Type Conversion' */
  15U,                                 /* '<S230>/Data Type Conversion1' */
  5U,                                  /* '<S230>/Data Type Conversion2' */
  3U,                                  /* '<S232>/Data Type Conversion' */
  17U,                                 /* '<S232>/Data Type Conversion1' */
  5U,                                  /* '<S232>/Data Type Conversion2' */
  2U,                                  /* '<S44>/Data Type Conversion2' */
  2U,                                  /* '<S44>/Data Type Conversion1' */
  1U,                                  /* '<S43>/Data Type Conversion' */
  1U,                                  /* '<S43>/Data Type Conversion1' */

  /* Start of '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S755>/Sum' */
    0.0066943799901413165,             /* '<S755>/Multiply3' */
    0.99330562000985867                /* '<S755>/Sum4' */
  }
  ,

  /* End of '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */

  /* Start of '<S6>/Vehicle.WaypointAngle' */
  {
    { 0.0F, 1.0F },                    /* synthesized block */

    { 0.0F, 1.0F },                    /* '<S769>/Math Function' */
    1.0F,                              /* '<S769>/Sum of Elements' */
    1.0F,                              /* '<S769>/Math Function1' */

    { 0.0F, 0.0F },                    /* '<S769>/Product' */

    { 0.0F, 1.0F, 1.0F },              /* '<S769>/Switch' */

    { 0.0F, 1.0F }                     /* '<S769>/Divide' */
  }
  ,

  /* End of '<S6>/Vehicle.WaypointAngle' */

  /* Start of '<S47>/Unknown' */
  {
    1U,                                /* '<S300>/Data Type Conversion' */
    1U                                 /* '<S300>/Data Type Conversion1' */
  }
  ,

  /* End of '<S47>/Unknown' */

  /* Start of '<S296>/Unknown' */
  {
    1U,                                /* '<S305>/Data Type Conversion' */
    1U                                 /* '<S305>/Data Type Conversion1' */
  }
  ,

  /* End of '<S296>/Unknown' */

  /* Start of '<S357>/Move Control' */
  {
    0.0004F,                           /* '<S367>/Square' */
    0.00628318498F,                    /* '<S367>/Multiply' */
    -15.707963F                        /* '<S367>/Gain4' */
  }
  ,

  /* End of '<S357>/Move Control' */

  /* Start of '<S329>/Move Control' */
  {
    0.0004F,                           /* '<S339>/Square' */
    0.00628318498F,                    /* '<S339>/Multiply' */
    -15.707963F                        /* '<S339>/Gain4' */
  }
  ,

  /* End of '<S329>/Move Control' */

  /* Start of '<S395>/Move Control' */
  {
    0.0004F,                           /* '<S405>/Square' */
    0.00628318498F,                    /* '<S405>/Multiply' */
    -15.707963F                        /* '<S405>/Gain4' */
  }
  ,

  /* End of '<S395>/Move Control' */

  /* Start of '<S297>/Unknown' */
  {
    1U,                                /* '<S410>/Data Type Conversion' */
    1U                                 /* '<S410>/Data Type Conversion1' */
  }
  ,

  /* End of '<S297>/Unknown' */

  /* Start of '<S459>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S466>/Vector Concatenate3' */
  }
  ,

  /* End of '<S459>/Hold Control' */

  /* Start of '<S299>/Unknown' */
  {
    1U,                                /* '<S602>/Data Type Conversion' */
    1U                                 /* '<S602>/Data Type Conversion1' */
  }
  ,

  /* End of '<S299>/Unknown' */

  /* Start of '<S638>/Move Control' */
  {
    0.00250000018F,                    /* '<S649>/Square' */
    0.14709F,                          /* '<S649>/Multiply' */
    -58.836F                           /* '<S649>/Gain4' */
  }
  ,

  /* End of '<S638>/Move Control' */

  /* Start of '<S638>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S645>/Vector Concatenate3' */
  }
  ,

  /* End of '<S638>/Hold Control' */

  /* Start of '<S617>/Move Control' */
  {
    0.0004F,                           /* '<S628>/Square' */
    0.00628318498F,                    /* '<S628>/Multiply' */
    -15.707963F                        /* '<S628>/Gain4' */
  }
  ,

  /* End of '<S617>/Move Control' */

  /* Start of '<S606>/Move Control' */
  {
    0.00250000018F,                    /* '<S614>/Square' */
    0.196120009F,                      /* '<S614>/Multiply' */
    -78.448F                           /* '<S614>/Gain4' */
  }
  ,

  /* End of '<S606>/Move Control' */

  /* Start of '<S699>/Move Control' */
  {
    0.00250000018F,                    /* '<S710>/Square' */
    0.14709F,                          /* '<S710>/Multiply' */
    -58.836F                           /* '<S710>/Gain4' */
  }
  ,

  /* End of '<S699>/Move Control' */

  /* Start of '<S699>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S706>/Vector Concatenate3' */
  }
  ,

  /* End of '<S699>/Hold Control' */

  /* Start of '<S689>/Move Control' */
  {
    0.00250000018F,                    /* '<S697>/Square' */
    0.196120009F,                      /* '<S697>/Multiply' */
    -78.448F                           /* '<S697>/Gain4' */
  }
  ,

  /* End of '<S689>/Move Control' */

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

  /* Start of '<S121>/Move Control' */
  {
    0.00250000018F,                    /* '<S129>/Square' */
    0.196120009F,                      /* '<S129>/Multiply' */
    -78.448F                           /* '<S129>/Gain4' */
  }
  ,

  /* End of '<S121>/Move Control' */

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
    1U,                                /* '<S199>/Data Type Conversion' */
    1U                                 /* '<S199>/Data Type Conversion1' */
  }
  ,

  /* End of '<S86>/Unknown' */

  /* Start of '<S88>/Unknown' */
  {
    1U,                                /* '<S233>/Data Type Conversion' */
    1U                                 /* '<S233>/Data Type Conversion1' */
  }
  /* End of '<S88>/Unknown' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
