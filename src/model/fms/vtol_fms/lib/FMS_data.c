/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2556
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Sep 22 10:24:41 2025
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
  1.9966471893352524,                  /* '<S619>/Sum' */
  0.0066943799901413165,               /* '<S619>/Multiply3' */
  0.99330562000985867,                 /* '<S619>/Sum4' */
  0.0,                                 /* '<S618>/deg2rad2' */
  0.0,                                 /* '<S621>/SinCos' */
  1.0,                                 /* '<S621>/SinCos' */

  { 0.0F, 0.0F, 1.0F },                /* '<S15>/Vector Concatenate3' */
  0.0100000007F,                       /* '<S422>/Square' */
  0.392240018F,                        /* '<S422>/Multiply' */
  -39.224F,                            /* '<S422>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S416>/Vector Concatenate3' */
  0.0016F,                             /* '<S368>/Square' */
  0.0201061927F,                       /* '<S368>/Multiply' */
  -12.566371F,                         /* '<S368>/Gain4' */
  0.0016F,                             /* '<S367>/Square' */
  0.0201061927F,                       /* '<S367>/Multiply' */
  -12.566371F,                         /* '<S367>/Gain4' */
  0.0016F,                             /* '<S434>/Square' */
  0.0201061927F,                       /* '<S434>/Multiply' */
  -12.566371F,                         /* '<S434>/Gain4' */
  0.0016F,                             /* '<S433>/Square' */
  0.0201061927F,                       /* '<S433>/Multiply' */
  -12.566371F,                         /* '<S433>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S529>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S469>/Math Function' */
  1.0F,                                /* '<S469>/Sum of Elements' */
  1.0F,                                /* '<S469>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S469>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S469>/Switch' */

  { 0.0F, 1.0F },                      /* '<S469>/Divide' */
  0.616850317F,                        /* '<S465>/Square' */
  0.484473109F,                        /* '<S465>/Multiply' */
  -0.785398185F,                       /* '<S465>/Gain4' */
  0.00250000018F,                      /* '<S510>/Square' */
  0.14709F,                            /* '<S510>/Multiply' */
  -58.836F,                            /* '<S510>/Gain4' */
  0.00250000018F,                      /* '<S497>/Square' */
  0.196120009F,                        /* '<S497>/Multiply' */
  -78.448F,                            /* '<S497>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S605>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S609>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S613>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S612>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S542>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S544>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S635>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S637>/Vector Concatenate3' */
  0.616850317F,                        /* '<S676>/Square' */
  0.484473109F,                        /* '<S676>/Multiply' */
  -0.785398185F,                       /* '<S676>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S769>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S716>/Math Function' */
  1.0F,                                /* '<S716>/Sum of Elements' */
  1.0F,                                /* '<S716>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S716>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S716>/Switch' */

  { 0.0F, 1.0F },                      /* '<S716>/Divide' */
  0.616850317F,                        /* '<S712>/Square' */
  0.645964146F,                        /* '<S712>/Multiply' */
  -1.04719758F,                        /* '<S712>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S699>/Vector Concatenate3' */
  0.122499995F,                        /* '<S695>/Square' */
  1.20123494F,                         /* '<S695>/Multiply' */
  -9.806F,                             /* '<S695>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S780>/Vector Concatenate3' */
  0.122499995F,                        /* '<S776>/Square' */
  1.20123494F,                         /* '<S776>/Multiply' */
  -9.806F,                             /* '<S776>/Gain4' */

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

  { 0.0F, 0.0F, 1.0F },                /* '<S221>/Vector Concatenate3' */
  0.00250000018F,                      /* '<S224>/Square' */
  0.196120009F,                        /* '<S224>/Multiply' */
  -78.448F,                            /* '<S224>/Gain4' */
  0.0004F,                             /* '<S174>/Square' */
  0.00628318498F,                      /* '<S174>/Multiply' */
  -15.707963F,                         /* '<S174>/Gain4' */
  0.0016F,                             /* '<S151>/Square' */
  0.0201061927F,                       /* '<S151>/Multiply' */
  -12.566371F,                         /* '<S151>/Gain4' */
  0.00250000018F,                      /* '<S156>/Square' */
  0.196120009F,                        /* '<S156>/Multiply' */
  -78.448F,                            /* '<S156>/Gain4' */
  0.0004F,                             /* '<S154>/Square' */
  0.00628318498F,                      /* '<S154>/Multiply' */
  -15.707963F,                         /* '<S154>/Gain4' */
  0.0016F,                             /* '<S232>/Square' */
  0.0201061927F,                       /* '<S232>/Multiply' */
  -12.566371F,                         /* '<S232>/Gain4' */
  0.0004F,                             /* '<S236>/Square' */
  0.00628318498F,                      /* '<S236>/Multiply' */
  -15.707963F,                         /* '<S236>/Gain4' */
  0.0016F,                             /* '<S233>/Square' */
  0.0201061927F,                       /* '<S233>/Multiply' */
  -12.566371F,                         /* '<S233>/Gain4' */
  1U,                                  /* '<S338>/Data Type Conversion' */
  12U,                                 /* '<S338>/Data Type Conversion1' */
  3U,                                  /* '<S343>/Data Type Conversion' */
  10U,                                 /* '<S343>/Data Type Conversion1' */
  5U,                                  /* '<S343>/Data Type Conversion2' */
  3U,                                  /* '<S342>/Data Type Conversion1' */
  9U,                                  /* '<S342>/Data Type Conversion2' */
  4U,                                  /* '<S342>/Data Type Conversion3' */
  3U,                                  /* '<S344>/Data Type Conversion' */
  8U,                                  /* '<S344>/Data Type Conversion1' */
  3U,                                  /* '<S344>/Data Type Conversion2' */
  3U,                                  /* '<S341>/Data Type Conversion' */
  7U,                                  /* '<S341>/Data Type Conversion1' */
  2U,                                  /* '<S341>/Data Type Conversion2' */
  3U,                                  /* '<S452>/Data Type Conversion' */
  4U,                                  /* '<S452>/Data Type Conversion1' */
  5U,                                  /* '<S452>/Data Type Conversion2' */
  3U,                                  /* '<S449>/Data Type Conversion' */
  3U,                                  /* '<S449>/Data Type Conversion1' */
  6U,                                  /* '<S449>/Data Type Conversion2' */
  3U,                                  /* '<S638>/Data Type Conversion' */
  6U,                                  /* '<S638>/Data Type Conversion1' */
  5U,                                  /* '<S638>/Data Type Conversion2' */
  3U,                                  /* '<S640>/Data Type Conversion' */
  16U,                                 /* '<S640>/Data Type Conversion1' */
  5U,                                  /* '<S640>/Data Type Conversion2' */
  3U,                                  /* '<S639>/Data Type Conversion' */
  15U,                                 /* '<S639>/Data Type Conversion1' */
  5U,                                  /* '<S639>/Data Type Conversion2' */
  3U,                                  /* '<S641>/Data Type Conversion' */
  17U,                                 /* '<S641>/Data Type Conversion1' */
  5U,                                  /* '<S641>/Data Type Conversion2' */
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
  3U,                                  /* '<S241>/Data Type Conversion' */
  4U,                                  /* '<S241>/Data Type Conversion1' */
  5U,                                  /* '<S241>/Data Type Conversion2' */
  1U,                                  /* '<S238>/Data Type Conversion' */
  3U,                                  /* '<S238>/Data Type Conversion1' */
  3U,                                  /* '<S269>/Data Type Conversion' */
  6U,                                  /* '<S269>/Data Type Conversion1' */
  5U,                                  /* '<S269>/Data Type Conversion2' */
  3U,                                  /* '<S271>/Data Type Conversion' */
  16U,                                 /* '<S271>/Data Type Conversion1' */
  5U,                                  /* '<S271>/Data Type Conversion2' */
  3U,                                  /* '<S270>/Data Type Conversion' */
  15U,                                 /* '<S270>/Data Type Conversion1' */
  5U,                                  /* '<S270>/Data Type Conversion2' */
  3U,                                  /* '<S272>/Data Type Conversion' */
  17U,                                 /* '<S272>/Data Type Conversion1' */
  5U,                                  /* '<S272>/Data Type Conversion2' */
  2U,                                  /* '<S47>/Data Type Conversion2' */
  2U,                                  /* '<S47>/Data Type Conversion1' */
  1U,                                  /* '<S46>/Data Type Conversion' */
  1U,                                  /* '<S46>/Data Type Conversion1' */

  /* Start of '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S795>/Sum' */
    0.0066943799901413165,             /* '<S795>/Multiply3' */
    0.99330562000985867                /* '<S795>/Sum4' */
  }
  ,

  /* End of '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */

  /* Start of '<S6>/Vehicle.WaypointAngle' */
  {
    { 0.0F, 1.0F },                    /* synthesized block */

    { 0.0F, 1.0F },                    /* '<S809>/Math Function' */
    1.0F,                              /* '<S809>/Sum of Elements' */
    1.0F,                              /* '<S809>/Math Function1' */

    { 0.0F, 0.0F },                    /* '<S809>/Product' */

    { 0.0F, 1.0F, 1.0F },              /* '<S809>/Switch' */

    { 0.0F, 1.0F }                     /* '<S809>/Divide' */
  }
  ,

  /* End of '<S6>/Vehicle.WaypointAngle' */

  /* Start of '<S50>/Unknown' */
  {
    1U,                                /* '<S340>/Data Type Conversion' */
    1U                                 /* '<S340>/Data Type Conversion1' */
  }
  ,

  /* End of '<S50>/Unknown' */

  /* Start of '<S336>/Unknown' */
  {
    1U,                                /* '<S345>/Data Type Conversion' */
    1U                                 /* '<S345>/Data Type Conversion1' */
  }
  ,

  /* End of '<S336>/Unknown' */

  /* Start of '<S397>/Move Control' */
  {
    0.0004F,                           /* '<S407>/Square' */
    0.00628318498F,                    /* '<S407>/Multiply' */
    -15.707963F                        /* '<S407>/Gain4' */
  }
  ,

  /* End of '<S397>/Move Control' */

  /* Start of '<S369>/Move Control' */
  {
    0.0004F,                           /* '<S379>/Square' */
    0.00628318498F,                    /* '<S379>/Multiply' */
    -15.707963F                        /* '<S379>/Gain4' */
  }
  ,

  /* End of '<S369>/Move Control' */

  /* Start of '<S435>/Move Control' */
  {
    0.0004F,                           /* '<S445>/Square' */
    0.00628318498F,                    /* '<S445>/Multiply' */
    -15.707963F                        /* '<S445>/Gain4' */
  }
  ,

  /* End of '<S435>/Move Control' */

  /* Start of '<S337>/Unknown' */
  {
    1U,                                /* '<S450>/Data Type Conversion' */
    1U                                 /* '<S450>/Data Type Conversion1' */
  }
  ,

  /* End of '<S337>/Unknown' */

  /* Start of '<S499>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S506>/Vector Concatenate3' */
  }
  ,

  /* End of '<S499>/Hold Control' */

  /* Start of '<S339>/Unknown' */
  {
    1U,                                /* '<S642>/Data Type Conversion' */
    1U                                 /* '<S642>/Data Type Conversion1' */
  }
  ,

  /* End of '<S339>/Unknown' */

  /* Start of '<S678>/Move Control' */
  {
    0.00250000018F,                    /* '<S689>/Square' */
    0.14709F,                          /* '<S689>/Multiply' */
    -58.836F                           /* '<S689>/Gain4' */
  }
  ,

  /* End of '<S678>/Move Control' */

  /* Start of '<S678>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S685>/Vector Concatenate3' */
  }
  ,

  /* End of '<S678>/Hold Control' */

  /* Start of '<S657>/Move Control' */
  {
    0.0004F,                           /* '<S668>/Square' */
    0.00628318498F,                    /* '<S668>/Multiply' */
    -15.707963F                        /* '<S668>/Gain4' */
  }
  ,

  /* End of '<S657>/Move Control' */

  /* Start of '<S646>/Move Control' */
  {
    0.00250000018F,                    /* '<S654>/Square' */
    0.196120009F,                      /* '<S654>/Multiply' */
    -78.448F                           /* '<S654>/Gain4' */
  }
  ,

  /* End of '<S646>/Move Control' */

  /* Start of '<S739>/Move Control' */
  {
    0.00250000018F,                    /* '<S750>/Square' */
    0.14709F,                          /* '<S750>/Multiply' */
    -58.836F                           /* '<S750>/Gain4' */
  }
  ,

  /* End of '<S739>/Move Control' */

  /* Start of '<S739>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S746>/Vector Concatenate3' */
  }
  ,

  /* End of '<S739>/Hold Control' */

  /* Start of '<S729>/Move Control' */
  {
    0.00250000018F,                    /* '<S737>/Square' */
    0.196120009F,                      /* '<S737>/Multiply' */
    -78.448F                           /* '<S737>/Gain4' */
  }
  ,

  /* End of '<S729>/Move Control' */

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

  /* Start of '<S175>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F },              /* '<S209>/Vector Concatenate3' */
    0.0F                               /* '<S211>/Constant' */
  }
  ,

  /* End of '<S175>/Hold Control' */

  /* Start of '<S161>/Move Control' */
  {
    0.00250000018F,                    /* '<S169>/Square' */
    0.196120009F,                      /* '<S169>/Multiply' */
    -78.448F                           /* '<S169>/Gain4' */
  }
  ,

  /* End of '<S161>/Move Control' */

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
    1U,                                /* '<S239>/Data Type Conversion' */
    1U                                 /* '<S239>/Data Type Conversion1' */
  }
  ,

  /* End of '<S126>/Unknown' */

  /* Start of '<S128>/Unknown' */
  {
    1U,                                /* '<S273>/Data Type Conversion' */
    1U                                 /* '<S273>/Data Type Conversion1' */
  }
  /* End of '<S128>/Unknown' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
