/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2520
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Sep  2 10:30:08 2025
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
  1.9966471893352524,                  /* '<S578>/Sum' */
  0.0066943799901413165,               /* '<S578>/Multiply3' */
  0.99330562000985867,                 /* '<S578>/Sum4' */
  0.0,                                 /* '<S577>/deg2rad2' */
  0.0,                                 /* '<S580>/SinCos' */
  1.0,                                 /* '<S580>/SinCos' */
  0.0100000007F,                       /* '<S381>/Square' */
  0.392240018F,                        /* '<S381>/Multiply' */
  -39.224F,                            /* '<S381>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S375>/Vector Concatenate3' */
  0.0016F,                             /* '<S327>/Square' */
  0.0201061927F,                       /* '<S327>/Multiply' */
  -12.566371F,                         /* '<S327>/Gain4' */
  0.0016F,                             /* '<S326>/Square' */
  0.0201061927F,                       /* '<S326>/Multiply' */
  -12.566371F,                         /* '<S326>/Gain4' */
  0.0016F,                             /* '<S393>/Square' */
  0.0201061927F,                       /* '<S393>/Multiply' */
  -12.566371F,                         /* '<S393>/Gain4' */
  0.0016F,                             /* '<S392>/Square' */
  0.0201061927F,                       /* '<S392>/Multiply' */
  -12.566371F,                         /* '<S392>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S488>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S428>/Math Function' */
  1.0F,                                /* '<S428>/Sum of Elements' */
  1.0F,                                /* '<S428>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S428>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S428>/Switch' */

  { 0.0F, 1.0F },                      /* '<S428>/Divide' */
  0.616850317F,                        /* '<S424>/Square' */
  0.484473109F,                        /* '<S424>/Multiply' */
  -0.785398185F,                       /* '<S424>/Gain4' */
  0.00250000018F,                      /* '<S469>/Square' */
  0.14709F,                            /* '<S469>/Multiply' */
  -58.836F,                            /* '<S469>/Gain4' */
  0.00250000018F,                      /* '<S456>/Square' */
  0.196120009F,                        /* '<S456>/Multiply' */
  -78.448F,                            /* '<S456>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S564>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S568>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S572>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S571>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S501>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S503>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S594>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S596>/Vector Concatenate3' */
  0.616850317F,                        /* '<S635>/Square' */
  0.484473109F,                        /* '<S635>/Multiply' */
  -0.785398185F,                       /* '<S635>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S728>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S675>/Math Function' */
  1.0F,                                /* '<S675>/Sum of Elements' */
  1.0F,                                /* '<S675>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S675>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S675>/Switch' */

  { 0.0F, 1.0F },                      /* '<S675>/Divide' */
  0.616850317F,                        /* '<S671>/Square' */
  0.645964146F,                        /* '<S671>/Multiply' */
  -1.04719758F,                        /* '<S671>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S658>/Vector Concatenate3' */
  0.122499995F,                        /* '<S654>/Square' */
  1.20123494F,                         /* '<S654>/Multiply' */
  -9.806F,                             /* '<S654>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S739>/Vector Concatenate3' */
  0.122499995F,                        /* '<S735>/Square' */
  1.20123494F,                         /* '<S735>/Multiply' */
  -9.806F,                             /* '<S735>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S75>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S80>/Vector Concatenate3' */
  0.0F,                                /* '<S82>/Constant' */

  { 0.0F, 0.0F, 1.0F },                /* '<S181>/Vector Concatenate3' */
  0.00250000018F,                      /* '<S183>/Square' */
  0.196120009F,                        /* '<S183>/Multiply' */
  -78.448F,                            /* '<S183>/Gain4' */
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
  0.0016F,                             /* '<S191>/Square' */
  0.0201061927F,                       /* '<S191>/Multiply' */
  -12.566371F,                         /* '<S191>/Gain4' */
  0.0004F,                             /* '<S195>/Square' */
  0.00628318498F,                      /* '<S195>/Multiply' */
  -15.707963F,                         /* '<S195>/Gain4' */
  0.0016F,                             /* '<S192>/Square' */
  0.0201061927F,                       /* '<S192>/Multiply' */
  -12.566371F,                         /* '<S192>/Gain4' */
  1U,                                  /* '<S297>/Data Type Conversion' */
  12U,                                 /* '<S297>/Data Type Conversion1' */
  3U,                                  /* '<S302>/Data Type Conversion' */
  10U,                                 /* '<S302>/Data Type Conversion1' */
  5U,                                  /* '<S302>/Data Type Conversion2' */
  3U,                                  /* '<S301>/Data Type Conversion1' */
  9U,                                  /* '<S301>/Data Type Conversion2' */
  4U,                                  /* '<S301>/Data Type Conversion3' */
  3U,                                  /* '<S303>/Data Type Conversion' */
  8U,                                  /* '<S303>/Data Type Conversion1' */
  3U,                                  /* '<S303>/Data Type Conversion2' */
  3U,                                  /* '<S300>/Data Type Conversion' */
  7U,                                  /* '<S300>/Data Type Conversion1' */
  2U,                                  /* '<S300>/Data Type Conversion2' */
  3U,                                  /* '<S411>/Data Type Conversion' */
  4U,                                  /* '<S411>/Data Type Conversion1' */
  5U,                                  /* '<S411>/Data Type Conversion2' */
  3U,                                  /* '<S408>/Data Type Conversion' */
  3U,                                  /* '<S408>/Data Type Conversion1' */
  6U,                                  /* '<S408>/Data Type Conversion2' */
  3U,                                  /* '<S597>/Data Type Conversion' */
  6U,                                  /* '<S597>/Data Type Conversion1' */
  5U,                                  /* '<S597>/Data Type Conversion2' */
  3U,                                  /* '<S599>/Data Type Conversion' */
  16U,                                 /* '<S599>/Data Type Conversion1' */
  5U,                                  /* '<S599>/Data Type Conversion2' */
  3U,                                  /* '<S598>/Data Type Conversion' */
  15U,                                 /* '<S598>/Data Type Conversion1' */
  5U,                                  /* '<S598>/Data Type Conversion2' */
  3U,                                  /* '<S600>/Data Type Conversion' */
  17U,                                 /* '<S600>/Data Type Conversion1' */
  5U,                                  /* '<S600>/Data Type Conversion2' */
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
  3U,                                  /* '<S200>/Data Type Conversion' */
  4U,                                  /* '<S200>/Data Type Conversion1' */
  5U,                                  /* '<S200>/Data Type Conversion2' */
  1U,                                  /* '<S197>/Data Type Conversion' */
  3U,                                  /* '<S197>/Data Type Conversion1' */
  3U,                                  /* '<S228>/Data Type Conversion' */
  6U,                                  /* '<S228>/Data Type Conversion1' */
  5U,                                  /* '<S228>/Data Type Conversion2' */
  3U,                                  /* '<S230>/Data Type Conversion' */
  16U,                                 /* '<S230>/Data Type Conversion1' */
  5U,                                  /* '<S230>/Data Type Conversion2' */
  3U,                                  /* '<S229>/Data Type Conversion' */
  15U,                                 /* '<S229>/Data Type Conversion1' */
  5U,                                  /* '<S229>/Data Type Conversion2' */
  3U,                                  /* '<S231>/Data Type Conversion' */
  17U,                                 /* '<S231>/Data Type Conversion1' */
  5U,                                  /* '<S231>/Data Type Conversion2' */
  2U,                                  /* '<S44>/Data Type Conversion2' */
  2U,                                  /* '<S44>/Data Type Conversion1' */
  1U,                                  /* '<S43>/Data Type Conversion' */
  1U,                                  /* '<S43>/Data Type Conversion1' */

  /* Start of '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S754>/Sum' */
    0.0066943799901413165,             /* '<S754>/Multiply3' */
    0.99330562000985867                /* '<S754>/Sum4' */
  }
  ,

  /* End of '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */

  /* Start of '<S6>/Vehicle.WaypointAngle' */
  {
    { 0.0F, 1.0F },                    /* synthesized block */

    { 0.0F, 1.0F },                    /* '<S768>/Math Function' */
    1.0F,                              /* '<S768>/Sum of Elements' */
    1.0F,                              /* '<S768>/Math Function1' */

    { 0.0F, 0.0F },                    /* '<S768>/Product' */

    { 0.0F, 1.0F, 1.0F },              /* '<S768>/Switch' */

    { 0.0F, 1.0F }                     /* '<S768>/Divide' */
  }
  ,

  /* End of '<S6>/Vehicle.WaypointAngle' */

  /* Start of '<S47>/Unknown' */
  {
    1U,                                /* '<S299>/Data Type Conversion' */
    1U                                 /* '<S299>/Data Type Conversion1' */
  }
  ,

  /* End of '<S47>/Unknown' */

  /* Start of '<S295>/Unknown' */
  {
    1U,                                /* '<S304>/Data Type Conversion' */
    1U                                 /* '<S304>/Data Type Conversion1' */
  }
  ,

  /* End of '<S295>/Unknown' */

  /* Start of '<S356>/Move Control' */
  {
    0.0004F,                           /* '<S366>/Square' */
    0.00628318498F,                    /* '<S366>/Multiply' */
    -15.707963F                        /* '<S366>/Gain4' */
  }
  ,

  /* End of '<S356>/Move Control' */

  /* Start of '<S328>/Move Control' */
  {
    0.0004F,                           /* '<S338>/Square' */
    0.00628318498F,                    /* '<S338>/Multiply' */
    -15.707963F                        /* '<S338>/Gain4' */
  }
  ,

  /* End of '<S328>/Move Control' */

  /* Start of '<S394>/Move Control' */
  {
    0.0004F,                           /* '<S404>/Square' */
    0.00628318498F,                    /* '<S404>/Multiply' */
    -15.707963F                        /* '<S404>/Gain4' */
  }
  ,

  /* End of '<S394>/Move Control' */

  /* Start of '<S296>/Unknown' */
  {
    1U,                                /* '<S409>/Data Type Conversion' */
    1U                                 /* '<S409>/Data Type Conversion1' */
  }
  ,

  /* End of '<S296>/Unknown' */

  /* Start of '<S458>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S465>/Vector Concatenate3' */
  }
  ,

  /* End of '<S458>/Hold Control' */

  /* Start of '<S298>/Unknown' */
  {
    1U,                                /* '<S601>/Data Type Conversion' */
    1U                                 /* '<S601>/Data Type Conversion1' */
  }
  ,

  /* End of '<S298>/Unknown' */

  /* Start of '<S637>/Move Control' */
  {
    0.00250000018F,                    /* '<S648>/Square' */
    0.14709F,                          /* '<S648>/Multiply' */
    -58.836F                           /* '<S648>/Gain4' */
  }
  ,

  /* End of '<S637>/Move Control' */

  /* Start of '<S637>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S644>/Vector Concatenate3' */
  }
  ,

  /* End of '<S637>/Hold Control' */

  /* Start of '<S616>/Move Control' */
  {
    0.0004F,                           /* '<S627>/Square' */
    0.00628318498F,                    /* '<S627>/Multiply' */
    -15.707963F                        /* '<S627>/Gain4' */
  }
  ,

  /* End of '<S616>/Move Control' */

  /* Start of '<S605>/Move Control' */
  {
    0.00250000018F,                    /* '<S613>/Square' */
    0.196120009F,                      /* '<S613>/Multiply' */
    -78.448F                           /* '<S613>/Gain4' */
  }
  ,

  /* End of '<S605>/Move Control' */

  /* Start of '<S698>/Move Control' */
  {
    0.00250000018F,                    /* '<S709>/Square' */
    0.14709F,                          /* '<S709>/Multiply' */
    -58.836F                           /* '<S709>/Gain4' */
  }
  ,

  /* End of '<S698>/Move Control' */

  /* Start of '<S698>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S705>/Vector Concatenate3' */
  }
  ,

  /* End of '<S698>/Hold Control' */

  /* Start of '<S688>/Move Control' */
  {
    0.00250000018F,                    /* '<S696>/Square' */
    0.196120009F,                      /* '<S696>/Multiply' */
    -78.448F                           /* '<S696>/Gain4' */
  }
  ,

  /* End of '<S688>/Move Control' */

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
    1U,                                /* '<S198>/Data Type Conversion' */
    1U                                 /* '<S198>/Data Type Conversion1' */
  }
  ,

  /* End of '<S86>/Unknown' */

  /* Start of '<S88>/Unknown' */
  {
    1U,                                /* '<S232>/Data Type Conversion' */
    1U                                 /* '<S232>/Data Type Conversion1' */
  }
  /* End of '<S88>/Unknown' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
