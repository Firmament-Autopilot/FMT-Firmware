/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2570
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Sep 23 16:28:48 2025
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
  1.9966471893352524,                  /* '<S633>/Sum' */
  0.0066943799901413165,               /* '<S633>/Multiply3' */
  0.99330562000985867,                 /* '<S633>/Sum4' */
  0.0,                                 /* '<S632>/deg2rad2' */
  0.0,                                 /* '<S635>/SinCos' */
  1.0,                                 /* '<S635>/SinCos' */

  { 0.0F, 0.0F, 1.0F },                /* '<S15>/Vector Concatenate3' */
  0.0100000007F,                       /* '<S436>/Square' */
  0.392240018F,                        /* '<S436>/Multiply' */
  -39.224F,                            /* '<S436>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S430>/Vector Concatenate3' */
  0.0016F,                             /* '<S382>/Square' */
  0.0201061927F,                       /* '<S382>/Multiply' */
  -12.566371F,                         /* '<S382>/Gain4' */
  0.0016F,                             /* '<S381>/Square' */
  0.0201061927F,                       /* '<S381>/Multiply' */
  -12.566371F,                         /* '<S381>/Gain4' */
  0.0016F,                             /* '<S448>/Square' */
  0.0201061927F,                       /* '<S448>/Multiply' */
  -12.566371F,                         /* '<S448>/Gain4' */
  0.0016F,                             /* '<S447>/Square' */
  0.0201061927F,                       /* '<S447>/Multiply' */
  -12.566371F,                         /* '<S447>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S543>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S483>/Math Function' */
  1.0F,                                /* '<S483>/Sum of Elements' */
  1.0F,                                /* '<S483>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S483>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S483>/Switch' */

  { 0.0F, 1.0F },                      /* '<S483>/Divide' */
  0.616850317F,                        /* '<S479>/Square' */
  0.484473109F,                        /* '<S479>/Multiply' */
  -0.785398185F,                       /* '<S479>/Gain4' */
  0.00250000018F,                      /* '<S524>/Square' */
  0.14709F,                            /* '<S524>/Multiply' */
  -58.836F,                            /* '<S524>/Gain4' */
  0.00250000018F,                      /* '<S511>/Square' */
  0.196120009F,                        /* '<S511>/Multiply' */
  -78.448F,                            /* '<S511>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S619>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S623>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S627>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S626>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S556>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S558>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S649>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S651>/Vector Concatenate3' */
  0.616850317F,                        /* '<S690>/Square' */
  0.484473109F,                        /* '<S690>/Multiply' */
  -0.785398185F,                       /* '<S690>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S783>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S730>/Math Function' */
  1.0F,                                /* '<S730>/Sum of Elements' */
  1.0F,                                /* '<S730>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S730>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S730>/Switch' */

  { 0.0F, 1.0F },                      /* '<S730>/Divide' */
  0.616850317F,                        /* '<S726>/Square' */
  0.645964146F,                        /* '<S726>/Multiply' */
  -1.04719758F,                        /* '<S726>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S713>/Vector Concatenate3' */
  0.122499995F,                        /* '<S709>/Square' */
  1.20123494F,                         /* '<S709>/Multiply' */
  -9.806F,                             /* '<S709>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S794>/Vector Concatenate3' */
  0.122499995F,                        /* '<S790>/Square' */
  1.20123494F,                         /* '<S790>/Multiply' */
  -9.806F,                             /* '<S790>/Gain4' */

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

  { 0.0F, 0.0F, 1.0F },                /* '<S227>/Vector Concatenate3' */
  0.00250000018F,                      /* '<S175>/Square' */
  0.196120009F,                        /* '<S175>/Multiply' */
  -78.448F,                            /* '<S175>/Gain4' */
  0.00250000018F,                      /* '<S233>/Square' */
  0.0980600044F,                       /* '<S233>/Multiply' */
  -39.224F,                            /* '<S233>/Gain4' */
  0.00250000018F,                      /* '<S232>/Square' */
  0.0073545007F,                       /* '<S232>/Multiply' */
  -2.9418F,                            /* '<S232>/Gain4' */
  0.0004F,                             /* '<S180>/Square' */
  0.00628318498F,                      /* '<S180>/Multiply' */
  -15.707963F,                         /* '<S180>/Gain4' */
  0.00250000018F,                      /* '<S147>/Square' */
  0.196120009F,                        /* '<S147>/Multiply' */
  -78.448F,                            /* '<S147>/Gain4' */
  0.00250000018F,                      /* '<S160>/Square' */
  0.0980600044F,                       /* '<S160>/Multiply' */
  -39.224F,                            /* '<S160>/Gain4' */
  0.00250000018F,                      /* '<S161>/Square' */
  0.0073545007F,                       /* '<S161>/Multiply' */
  -2.9418F,                            /* '<S161>/Gain4' */
  0.0004F,                             /* '<S155>/Square' */
  0.00628318498F,                      /* '<S155>/Multiply' */
  -15.707963F,                         /* '<S155>/Gain4' */
  0.0016F,                             /* '<S152>/Square' */
  0.0201061927F,                       /* '<S152>/Multiply' */
  -12.566371F,                         /* '<S152>/Gain4' */
  0.0016F,                             /* '<S241>/Square' */
  0.0201061927F,                       /* '<S241>/Multiply' */
  -12.566371F,                         /* '<S241>/Gain4' */
  0.0004F,                             /* '<S245>/Square' */
  0.00628318498F,                      /* '<S245>/Multiply' */
  -15.707963F,                         /* '<S245>/Gain4' */
  0.0016F,                             /* '<S242>/Square' */
  0.0201061927F,                       /* '<S242>/Multiply' */
  -12.566371F,                         /* '<S242>/Gain4' */
  0.00250000018F,                      /* '<S261>/Square' */
  0.0980600044F,                       /* '<S261>/Multiply' */
  -39.224F,                            /* '<S261>/Gain4' */
  0.00250000018F,                      /* '<S260>/Square' */
  0.0073545007F,                       /* '<S260>/Multiply' */
  -2.9418F,                            /* '<S260>/Gain4' */
  1U,                                  /* '<S352>/Data Type Conversion' */
  12U,                                 /* '<S352>/Data Type Conversion1' */
  3U,                                  /* '<S357>/Data Type Conversion' */
  10U,                                 /* '<S357>/Data Type Conversion1' */
  5U,                                  /* '<S357>/Data Type Conversion2' */
  3U,                                  /* '<S356>/Data Type Conversion1' */
  9U,                                  /* '<S356>/Data Type Conversion2' */
  4U,                                  /* '<S356>/Data Type Conversion3' */
  3U,                                  /* '<S358>/Data Type Conversion' */
  8U,                                  /* '<S358>/Data Type Conversion1' */
  3U,                                  /* '<S358>/Data Type Conversion2' */
  3U,                                  /* '<S355>/Data Type Conversion' */
  7U,                                  /* '<S355>/Data Type Conversion1' */
  2U,                                  /* '<S355>/Data Type Conversion2' */
  3U,                                  /* '<S466>/Data Type Conversion' */
  4U,                                  /* '<S466>/Data Type Conversion1' */
  5U,                                  /* '<S466>/Data Type Conversion2' */
  3U,                                  /* '<S463>/Data Type Conversion' */
  3U,                                  /* '<S463>/Data Type Conversion1' */
  6U,                                  /* '<S463>/Data Type Conversion2' */
  3U,                                  /* '<S652>/Data Type Conversion' */
  6U,                                  /* '<S652>/Data Type Conversion1' */
  5U,                                  /* '<S652>/Data Type Conversion2' */
  3U,                                  /* '<S654>/Data Type Conversion' */
  16U,                                 /* '<S654>/Data Type Conversion1' */
  5U,                                  /* '<S654>/Data Type Conversion2' */
  3U,                                  /* '<S653>/Data Type Conversion' */
  15U,                                 /* '<S653>/Data Type Conversion1' */
  5U,                                  /* '<S653>/Data Type Conversion2' */
  3U,                                  /* '<S655>/Data Type Conversion' */
  17U,                                 /* '<S655>/Data Type Conversion1' */
  5U,                                  /* '<S655>/Data Type Conversion2' */
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
  3U,                                  /* '<S250>/Data Type Conversion' */
  4U,                                  /* '<S250>/Data Type Conversion1' */
  5U,                                  /* '<S250>/Data Type Conversion2' */
  1U,                                  /* '<S247>/Data Type Conversion' */
  3U,                                  /* '<S247>/Data Type Conversion1' */
  3U,                                  /* '<S283>/Data Type Conversion' */
  6U,                                  /* '<S283>/Data Type Conversion1' */
  5U,                                  /* '<S283>/Data Type Conversion2' */
  3U,                                  /* '<S285>/Data Type Conversion' */
  16U,                                 /* '<S285>/Data Type Conversion1' */
  5U,                                  /* '<S285>/Data Type Conversion2' */
  3U,                                  /* '<S284>/Data Type Conversion' */
  15U,                                 /* '<S284>/Data Type Conversion1' */
  5U,                                  /* '<S284>/Data Type Conversion2' */
  3U,                                  /* '<S286>/Data Type Conversion' */
  17U,                                 /* '<S286>/Data Type Conversion1' */
  5U,                                  /* '<S286>/Data Type Conversion2' */
  2U,                                  /* '<S47>/Data Type Conversion2' */
  2U,                                  /* '<S47>/Data Type Conversion1' */
  1U,                                  /* '<S46>/Data Type Conversion' */
  1U,                                  /* '<S46>/Data Type Conversion1' */

  /* Start of '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S809>/Sum' */
    0.0066943799901413165,             /* '<S809>/Multiply3' */
    0.99330562000985867                /* '<S809>/Sum4' */
  }
  ,

  /* End of '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */

  /* Start of '<S6>/Vehicle.WaypointAngle' */
  {
    { 0.0F, 1.0F },                    /* synthesized block */

    { 0.0F, 1.0F },                    /* '<S823>/Math Function' */
    1.0F,                              /* '<S823>/Sum of Elements' */
    1.0F,                              /* '<S823>/Math Function1' */

    { 0.0F, 0.0F },                    /* '<S823>/Product' */

    { 0.0F, 1.0F, 1.0F },              /* '<S823>/Switch' */

    { 0.0F, 1.0F }                     /* '<S823>/Divide' */
  }
  ,

  /* End of '<S6>/Vehicle.WaypointAngle' */

  /* Start of '<S50>/Unknown' */
  {
    1U,                                /* '<S354>/Data Type Conversion' */
    1U                                 /* '<S354>/Data Type Conversion1' */
  }
  ,

  /* End of '<S50>/Unknown' */

  /* Start of '<S350>/Unknown' */
  {
    1U,                                /* '<S359>/Data Type Conversion' */
    1U                                 /* '<S359>/Data Type Conversion1' */
  }
  ,

  /* End of '<S350>/Unknown' */

  /* Start of '<S411>/Move Control' */
  {
    0.0004F,                           /* '<S421>/Square' */
    0.00628318498F,                    /* '<S421>/Multiply' */
    -15.707963F                        /* '<S421>/Gain4' */
  }
  ,

  /* End of '<S411>/Move Control' */

  /* Start of '<S383>/Move Control' */
  {
    0.0004F,                           /* '<S393>/Square' */
    0.00628318498F,                    /* '<S393>/Multiply' */
    -15.707963F                        /* '<S393>/Gain4' */
  }
  ,

  /* End of '<S383>/Move Control' */

  /* Start of '<S449>/Move Control' */
  {
    0.0004F,                           /* '<S459>/Square' */
    0.00628318498F,                    /* '<S459>/Multiply' */
    -15.707963F                        /* '<S459>/Gain4' */
  }
  ,

  /* End of '<S449>/Move Control' */

  /* Start of '<S351>/Unknown' */
  {
    1U,                                /* '<S464>/Data Type Conversion' */
    1U                                 /* '<S464>/Data Type Conversion1' */
  }
  ,

  /* End of '<S351>/Unknown' */

  /* Start of '<S513>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S520>/Vector Concatenate3' */
  }
  ,

  /* End of '<S513>/Hold Control' */

  /* Start of '<S353>/Unknown' */
  {
    1U,                                /* '<S656>/Data Type Conversion' */
    1U                                 /* '<S656>/Data Type Conversion1' */
  }
  ,

  /* End of '<S353>/Unknown' */

  /* Start of '<S692>/Move Control' */
  {
    0.00250000018F,                    /* '<S703>/Square' */
    0.14709F,                          /* '<S703>/Multiply' */
    -58.836F                           /* '<S703>/Gain4' */
  }
  ,

  /* End of '<S692>/Move Control' */

  /* Start of '<S692>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S699>/Vector Concatenate3' */
  }
  ,

  /* End of '<S692>/Hold Control' */

  /* Start of '<S671>/Move Control' */
  {
    0.0004F,                           /* '<S682>/Square' */
    0.00628318498F,                    /* '<S682>/Multiply' */
    -15.707963F                        /* '<S682>/Gain4' */
  }
  ,

  /* End of '<S671>/Move Control' */

  /* Start of '<S660>/Move Control' */
  {
    0.00250000018F,                    /* '<S668>/Square' */
    0.196120009F,                      /* '<S668>/Multiply' */
    -78.448F                           /* '<S668>/Gain4' */
  }
  ,

  /* End of '<S660>/Move Control' */

  /* Start of '<S753>/Move Control' */
  {
    0.00250000018F,                    /* '<S764>/Square' */
    0.14709F,                          /* '<S764>/Multiply' */
    -58.836F                           /* '<S764>/Gain4' */
  }
  ,

  /* End of '<S753>/Move Control' */

  /* Start of '<S753>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S760>/Vector Concatenate3' */
  }
  ,

  /* End of '<S753>/Hold Control' */

  /* Start of '<S743>/Move Control' */
  {
    0.00250000018F,                    /* '<S751>/Square' */
    0.196120009F,                      /* '<S751>/Multiply' */
    -78.448F                           /* '<S751>/Gain4' */
  }
  ,

  /* End of '<S743>/Move Control' */

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

  /* Start of '<S181>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F },              /* '<S215>/Vector Concatenate3' */
    0.0F                               /* '<S217>/Constant' */
  }
  ,

  /* End of '<S181>/Hold Control' */

  /* Start of '<S166>/Move Control' */
  {
    0.00250000018F,                    /* '<S174>/Square' */
    0.196120009F,                      /* '<S174>/Multiply' */
    -78.448F                           /* '<S174>/Gain4' */
  }
  ,

  /* End of '<S166>/Move Control' */

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
    1U,                                /* '<S248>/Data Type Conversion' */
    1U                                 /* '<S248>/Data Type Conversion1' */
  }
  ,

  /* End of '<S126>/Unknown' */

  /* Start of '<S128>/Unknown' */
  {
    1U,                                /* '<S287>/Data Type Conversion' */
    1U                                 /* '<S287>/Data Type Conversion1' */
  }
  /* End of '<S128>/Unknown' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
