/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2590
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Sep 30 15:12:37 2025
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
  1.9966471893352524,                  /* '<S623>/Sum' */
  0.0066943799901413165,               /* '<S623>/Multiply3' */
  0.99330562000985867,                 /* '<S623>/Sum4' */
  0.0,                                 /* '<S622>/deg2rad2' */
  0.0,                                 /* '<S625>/SinCos' */
  1.0,                                 /* '<S625>/SinCos' */

  { 0.0F, 0.0F, 1.0F },                /* '<S15>/Vector Concatenate3' */
  0.0100000007F,                       /* '<S426>/Square' */
  0.392240018F,                        /* '<S426>/Multiply' */
  -39.224F,                            /* '<S426>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S420>/Vector Concatenate3' */
  0.0016F,                             /* '<S372>/Square' */
  0.0201061927F,                       /* '<S372>/Multiply' */
  -12.566371F,                         /* '<S372>/Gain4' */
  0.0016F,                             /* '<S371>/Square' */
  0.0201061927F,                       /* '<S371>/Multiply' */
  -12.566371F,                         /* '<S371>/Gain4' */
  0.0016F,                             /* '<S438>/Square' */
  0.0201061927F,                       /* '<S438>/Multiply' */
  -12.566371F,                         /* '<S438>/Gain4' */
  0.0016F,                             /* '<S437>/Square' */
  0.0201061927F,                       /* '<S437>/Multiply' */
  -12.566371F,                         /* '<S437>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S533>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S473>/Math Function' */
  1.0F,                                /* '<S473>/Sum of Elements' */
  1.0F,                                /* '<S473>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S473>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S473>/Switch' */

  { 0.0F, 1.0F },                      /* '<S473>/Divide' */
  0.616850317F,                        /* '<S469>/Square' */
  0.484473109F,                        /* '<S469>/Multiply' */
  -0.785398185F,                       /* '<S469>/Gain4' */
  0.00250000018F,                      /* '<S514>/Square' */
  0.14709F,                            /* '<S514>/Multiply' */
  -58.836F,                            /* '<S514>/Gain4' */
  0.00250000018F,                      /* '<S501>/Square' */
  0.196120009F,                        /* '<S501>/Multiply' */
  -78.448F,                            /* '<S501>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S609>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S613>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S617>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S616>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S546>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S548>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S639>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S641>/Vector Concatenate3' */
  0.616850317F,                        /* '<S680>/Square' */
  0.484473109F,                        /* '<S680>/Multiply' */
  -0.785398185F,                       /* '<S680>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S773>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S720>/Math Function' */
  1.0F,                                /* '<S720>/Sum of Elements' */
  1.0F,                                /* '<S720>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S720>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S720>/Switch' */

  { 0.0F, 1.0F },                      /* '<S720>/Divide' */
  0.616850317F,                        /* '<S716>/Square' */
  0.645964146F,                        /* '<S716>/Multiply' */
  -1.04719758F,                        /* '<S716>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S703>/Vector Concatenate3' */
  0.122499995F,                        /* '<S699>/Square' */
  1.20123494F,                         /* '<S699>/Multiply' */
  -9.806F,                             /* '<S699>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S784>/Vector Concatenate3' */
  0.122499995F,                        /* '<S780>/Square' */
  1.20123494F,                         /* '<S780>/Multiply' */
  -9.806F,                             /* '<S780>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S100>/Vector Concatenate3' */
  0.0004F,                             /* '<S123>/Square' */
  0.00628318498F,                      /* '<S123>/Multiply' */
  -15.707963F,                         /* '<S123>/Gain4' */
  0.0100000007F,                       /* '<S124>/Square' */
  0.392240018F,                        /* '<S124>/Multiply' */
  -39.224F,                            /* '<S124>/Gain4' */
  0.0100000007F,                       /* '<S122>/Square' */
  0.392240018F,                        /* '<S122>/Multiply' */
  -39.224F,                            /* '<S122>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S223>/Vector Concatenate3' */
  0.00250000018F,                      /* '<S172>/Square' */
  0.196120009F,                        /* '<S172>/Multiply' */
  -78.448F,                            /* '<S172>/Gain4' */
  0.00250000018F,                      /* '<S226>/Square' */
  0.196120009F,                        /* '<S226>/Multiply' */
  -78.448F,                            /* '<S226>/Gain4' */
  0.0004F,                             /* '<S177>/Square' */
  0.00628318498F,                      /* '<S177>/Multiply' */
  -15.707963F,                         /* '<S177>/Gain4' */
  0.00250000018F,                      /* '<S147>/Square' */
  0.196120009F,                        /* '<S147>/Multiply' */
  -78.448F,                            /* '<S147>/Gain4' */
  0.00250000018F,                      /* '<S158>/Square' */
  0.196120009F,                        /* '<S158>/Multiply' */
  -78.448F,                            /* '<S158>/Gain4' */
  0.0004F,                             /* '<S155>/Square' */
  0.00628318498F,                      /* '<S155>/Multiply' */
  -15.707963F,                         /* '<S155>/Gain4' */
  0.0016F,                             /* '<S152>/Square' */
  0.0201061927F,                       /* '<S152>/Multiply' */
  -12.566371F,                         /* '<S152>/Gain4' */
  0.0016F,                             /* '<S234>/Square' */
  0.0201061927F,                       /* '<S234>/Multiply' */
  -12.566371F,                         /* '<S234>/Gain4' */
  0.0004F,                             /* '<S238>/Square' */
  0.00628318498F,                      /* '<S238>/Multiply' */
  -15.707963F,                         /* '<S238>/Gain4' */
  0.0016F,                             /* '<S235>/Square' */
  0.0201061927F,                       /* '<S235>/Multiply' */
  -12.566371F,                         /* '<S235>/Gain4' */
  0.00250000018F,                      /* '<S251>/Square' */
  0.196120009F,                        /* '<S251>/Multiply' */
  -78.448F,                            /* '<S251>/Gain4' */
  1U,                                  /* '<S342>/Data Type Conversion' */
  12U,                                 /* '<S342>/Data Type Conversion1' */
  3U,                                  /* '<S347>/Data Type Conversion' */
  10U,                                 /* '<S347>/Data Type Conversion1' */
  5U,                                  /* '<S347>/Data Type Conversion2' */
  3U,                                  /* '<S346>/Data Type Conversion1' */
  9U,                                  /* '<S346>/Data Type Conversion2' */
  4U,                                  /* '<S346>/Data Type Conversion3' */
  3U,                                  /* '<S348>/Data Type Conversion' */
  8U,                                  /* '<S348>/Data Type Conversion1' */
  3U,                                  /* '<S348>/Data Type Conversion2' */
  3U,                                  /* '<S345>/Data Type Conversion' */
  7U,                                  /* '<S345>/Data Type Conversion1' */
  2U,                                  /* '<S345>/Data Type Conversion2' */
  3U,                                  /* '<S456>/Data Type Conversion' */
  4U,                                  /* '<S456>/Data Type Conversion1' */
  5U,                                  /* '<S456>/Data Type Conversion2' */
  3U,                                  /* '<S453>/Data Type Conversion' */
  3U,                                  /* '<S453>/Data Type Conversion1' */
  6U,                                  /* '<S453>/Data Type Conversion2' */
  3U,                                  /* '<S642>/Data Type Conversion' */
  6U,                                  /* '<S642>/Data Type Conversion1' */
  5U,                                  /* '<S642>/Data Type Conversion2' */
  3U,                                  /* '<S644>/Data Type Conversion' */
  16U,                                 /* '<S644>/Data Type Conversion1' */
  5U,                                  /* '<S644>/Data Type Conversion2' */
  3U,                                  /* '<S643>/Data Type Conversion' */
  15U,                                 /* '<S643>/Data Type Conversion1' */
  5U,                                  /* '<S643>/Data Type Conversion2' */
  3U,                                  /* '<S645>/Data Type Conversion' */
  17U,                                 /* '<S645>/Data Type Conversion1' */
  5U,                                  /* '<S645>/Data Type Conversion2' */
  3U,                                  /* '<S48>/Data Type Conversion1' */
  6U,                                  /* '<S48>/Data Type Conversion2' */
  5U,                                  /* '<S48>/Data Type Conversion3' */
  3U,                                  /* '<S127>/Data Type Conversion' */
  12U,                                 /* '<S127>/Data Type Conversion1' */
  1U,                                  /* '<S127>/Data Type Conversion2' */
  3U,                                  /* '<S131>/Data Type Conversion' */
  10U,                                 /* '<S131>/Data Type Conversion1' */
  5U,                                  /* '<S131>/Data Type Conversion2' */
  3U,                                  /* '<S130>/Data Type Conversion1' */
  9U,                                  /* '<S130>/Data Type Conversion2' */
  4U,                                  /* '<S130>/Data Type Conversion3' */
  3U,                                  /* '<S132>/Data Type Conversion' */
  8U,                                  /* '<S132>/Data Type Conversion1' */
  3U,                                  /* '<S132>/Data Type Conversion2' */
  3U,                                  /* '<S243>/Data Type Conversion' */
  4U,                                  /* '<S243>/Data Type Conversion1' */
  5U,                                  /* '<S243>/Data Type Conversion2' */
  1U,                                  /* '<S240>/Data Type Conversion' */
  3U,                                  /* '<S240>/Data Type Conversion1' */
  3U,                                  /* '<S273>/Data Type Conversion' */
  6U,                                  /* '<S273>/Data Type Conversion1' */
  5U,                                  /* '<S273>/Data Type Conversion2' */
  3U,                                  /* '<S275>/Data Type Conversion' */
  16U,                                 /* '<S275>/Data Type Conversion1' */
  5U,                                  /* '<S275>/Data Type Conversion2' */
  3U,                                  /* '<S274>/Data Type Conversion' */
  15U,                                 /* '<S274>/Data Type Conversion1' */
  5U,                                  /* '<S274>/Data Type Conversion2' */
  3U,                                  /* '<S276>/Data Type Conversion' */
  17U,                                 /* '<S276>/Data Type Conversion1' */
  5U,                                  /* '<S276>/Data Type Conversion2' */
  2U,                                  /* '<S47>/Data Type Conversion2' */
  2U,                                  /* '<S47>/Data Type Conversion1' */
  1U,                                  /* '<S46>/Data Type Conversion' */
  1U,                                  /* '<S46>/Data Type Conversion1' */

  /* Start of '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S799>/Sum' */
    0.0066943799901413165,             /* '<S799>/Multiply3' */
    0.99330562000985867                /* '<S799>/Sum4' */
  }
  ,

  /* End of '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */

  /* Start of '<S6>/Vehicle.WaypointAngle' */
  {
    { 0.0F, 1.0F },                    /* synthesized block */

    { 0.0F, 1.0F },                    /* '<S813>/Math Function' */
    1.0F,                              /* '<S813>/Sum of Elements' */
    1.0F,                              /* '<S813>/Math Function1' */

    { 0.0F, 0.0F },                    /* '<S813>/Product' */

    { 0.0F, 1.0F, 1.0F },              /* '<S813>/Switch' */

    { 0.0F, 1.0F }                     /* '<S813>/Divide' */
  }
  ,

  /* End of '<S6>/Vehicle.WaypointAngle' */

  /* Start of '<S50>/Unknown' */
  {
    1U,                                /* '<S344>/Data Type Conversion' */
    1U                                 /* '<S344>/Data Type Conversion1' */
  }
  ,

  /* End of '<S50>/Unknown' */

  /* Start of '<S340>/Unknown' */
  {
    1U,                                /* '<S349>/Data Type Conversion' */
    1U                                 /* '<S349>/Data Type Conversion1' */
  }
  ,

  /* End of '<S340>/Unknown' */

  /* Start of '<S401>/Move Control' */
  {
    0.0004F,                           /* '<S411>/Square' */
    0.00628318498F,                    /* '<S411>/Multiply' */
    -15.707963F                        /* '<S411>/Gain4' */
  }
  ,

  /* End of '<S401>/Move Control' */

  /* Start of '<S373>/Move Control' */
  {
    0.0004F,                           /* '<S383>/Square' */
    0.00628318498F,                    /* '<S383>/Multiply' */
    -15.707963F                        /* '<S383>/Gain4' */
  }
  ,

  /* End of '<S373>/Move Control' */

  /* Start of '<S439>/Move Control' */
  {
    0.0004F,                           /* '<S449>/Square' */
    0.00628318498F,                    /* '<S449>/Multiply' */
    -15.707963F                        /* '<S449>/Gain4' */
  }
  ,

  /* End of '<S439>/Move Control' */

  /* Start of '<S341>/Unknown' */
  {
    1U,                                /* '<S454>/Data Type Conversion' */
    1U                                 /* '<S454>/Data Type Conversion1' */
  }
  ,

  /* End of '<S341>/Unknown' */

  /* Start of '<S503>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S510>/Vector Concatenate3' */
  }
  ,

  /* End of '<S503>/Hold Control' */

  /* Start of '<S343>/Unknown' */
  {
    1U,                                /* '<S646>/Data Type Conversion' */
    1U                                 /* '<S646>/Data Type Conversion1' */
  }
  ,

  /* End of '<S343>/Unknown' */

  /* Start of '<S682>/Move Control' */
  {
    0.00250000018F,                    /* '<S693>/Square' */
    0.14709F,                          /* '<S693>/Multiply' */
    -58.836F                           /* '<S693>/Gain4' */
  }
  ,

  /* End of '<S682>/Move Control' */

  /* Start of '<S682>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S689>/Vector Concatenate3' */
  }
  ,

  /* End of '<S682>/Hold Control' */

  /* Start of '<S661>/Move Control' */
  {
    0.0004F,                           /* '<S672>/Square' */
    0.00628318498F,                    /* '<S672>/Multiply' */
    -15.707963F                        /* '<S672>/Gain4' */
  }
  ,

  /* End of '<S661>/Move Control' */

  /* Start of '<S650>/Move Control' */
  {
    0.00250000018F,                    /* '<S658>/Square' */
    0.196120009F,                      /* '<S658>/Multiply' */
    -78.448F                           /* '<S658>/Gain4' */
  }
  ,

  /* End of '<S650>/Move Control' */

  /* Start of '<S743>/Move Control' */
  {
    0.00250000018F,                    /* '<S754>/Square' */
    0.14709F,                          /* '<S754>/Multiply' */
    -58.836F                           /* '<S754>/Gain4' */
  }
  ,

  /* End of '<S743>/Move Control' */

  /* Start of '<S743>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S750>/Vector Concatenate3' */
  }
  ,

  /* End of '<S743>/Hold Control' */

  /* Start of '<S733>/Move Control' */
  {
    0.00250000018F,                    /* '<S741>/Square' */
    0.196120009F,                      /* '<S741>/Multiply' */
    -78.448F                           /* '<S741>/Gain4' */
  }
  ,

  /* End of '<S733>/Move Control' */

  /* Start of '<S54>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F },              /* '<S88>/Vector Concatenate3' */
    0.0F                               /* '<S90>/Constant' */
  }
  ,

  /* End of '<S54>/Hold Control' */

  /* Start of '<S49>/Unknown' */
  {
    1U,                                /* '<S129>/Data Type Conversion' */
    1U                                 /* '<S129>/Data Type Conversion1' */
  }
  ,

  /* End of '<S49>/Unknown' */

  /* Start of '<S125>/Unknown' */
  {
    1U,                                /* '<S133>/Data Type Conversion' */
    1U                                 /* '<S133>/Data Type Conversion1' */
  }
  ,

  /* End of '<S125>/Unknown' */

  /* Start of '<S178>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F },              /* '<S211>/Vector Concatenate3' */
    0.0F                               /* '<S213>/Constant' */
  }
  ,

  /* End of '<S178>/Hold Control' */

  /* Start of '<S163>/Move Control' */
  {
    0.00250000018F,                    /* '<S171>/Square' */
    0.196120009F,                      /* '<S171>/Multiply' */
    -78.448F                           /* '<S171>/Gain4' */
  }
  ,

  /* End of '<S163>/Move Control' */

  /* Start of '<S138>/Move Control' */
  {
    0.00250000018F,                    /* '<S146>/Square' */
    0.196120009F,                      /* '<S146>/Multiply' */
    -78.448F                           /* '<S146>/Gain4' */
  }
  ,

  /* End of '<S138>/Move Control' */

  /* Start of '<S126>/Unknown' */
  {
    1U,                                /* '<S241>/Data Type Conversion' */
    1U                                 /* '<S241>/Data Type Conversion1' */
  }
  ,

  /* End of '<S126>/Unknown' */

  /* Start of '<S128>/Unknown' */
  {
    1U,                                /* '<S277>/Data Type Conversion' */
    1U                                 /* '<S277>/Data Type Conversion1' */
  }
  /* End of '<S128>/Unknown' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
