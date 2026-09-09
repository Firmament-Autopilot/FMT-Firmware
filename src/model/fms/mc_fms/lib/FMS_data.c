/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2335
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sun Sep  6 10:46:31 2026
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
  1.9966471893352524,                  /* '<S334>/Sum' */
  0.0066943799901413165,               /* '<S334>/Multiply3' */
  0.99330562000985867,                 /* '<S334>/Sum4' */
  0.0,                                 /* '<S333>/deg2rad2' */
  0.0,                                 /* '<S336>/SinCos' */
  1.0,                                 /* '<S336>/SinCos' */
  0.00250000018F,                      /* '<S122>/Square' */

  { 0.0F, 0.0F, 1.0F },                /* '<S115>/Vector Concatenate3' */
  0.0016F,                             /* '<S69>/Square' */
  0.0016F,                             /* '<S70>/Square' */
  0.0016F,                             /* '<S136>/Square' */
  0.0016F,                             /* '<S137>/Square' */

  { 0.0F, 0.0F, 1.0F },                /* '<S235>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S171>/Math Function' */
  1.0F,                                /* '<S171>/Sum of Elements' */
  1.0F,                                /* '<S171>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S171>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S171>/Switch' */

  { 0.0F, 1.0F },                      /* '<S171>/Divide' */
  0.616850317F,                        /* '<S167>/Square' */
  0.645964146F,                        /* '<S167>/Multiply' */
  -1.04719758F,                        /* '<S167>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S316>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S320>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S328>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S325>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S324>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S251>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S253>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S350>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S352>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S485>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S421>/Math Function' */
  1.0F,                                /* '<S421>/Sum of Elements' */
  1.0F,                                /* '<S421>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S421>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S421>/Switch' */

  { 0.0F, 1.0F },                      /* '<S421>/Divide' */
  0.616850317F,                        /* '<S417>/Square' */
  0.645964146F,                        /* '<S417>/Multiply' */
  -1.04719758F,                        /* '<S417>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S404>/Vector Concatenate3' */
  0.122499995F,                        /* '<S400>/Square' */
  1.20123494F,                         /* '<S400>/Multiply' */
  -9.806F,                             /* '<S400>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S499>/Vector Concatenate3' */
  0.122499995F,                        /* '<S495>/Square' */
  1.20123494F,                         /* '<S495>/Multiply' */
  -9.806F,                             /* '<S495>/Gain4' */
  1U,                                  /* '<S38>/Data Type Conversion' */
  12U,                                 /* '<S38>/Data Type Conversion1' */
  3U,                                  /* '<S43>/Data Type Conversion' */
  10U,                                 /* '<S43>/Data Type Conversion1' */
  5U,                                  /* '<S43>/Data Type Conversion2' */
  3U,                                  /* '<S42>/Data Type Conversion1' */
  9U,                                  /* '<S42>/Data Type Conversion2' */
  4U,                                  /* '<S42>/Data Type Conversion3' */
  3U,                                  /* '<S44>/Data Type Conversion' */
  8U,                                  /* '<S44>/Data Type Conversion1' */
  3U,                                  /* '<S44>/Data Type Conversion2' */
  3U,                                  /* '<S41>/Data Type Conversion' */
  7U,                                  /* '<S41>/Data Type Conversion1' */
  2U,                                  /* '<S41>/Data Type Conversion2' */
  3U,                                  /* '<S154>/Data Type Conversion' */
  4U,                                  /* '<S154>/Data Type Conversion1' */
  5U,                                  /* '<S154>/Data Type Conversion2' */
  3U,                                  /* '<S151>/Data Type Conversion' */
  3U,                                  /* '<S151>/Data Type Conversion1' */
  6U,                                  /* '<S151>/Data Type Conversion2' */
  3U,                                  /* '<S353>/Data Type Conversion' */
  6U,                                  /* '<S353>/Data Type Conversion1' */
  5U,                                  /* '<S353>/Data Type Conversion2' */
  3U,                                  /* '<S355>/Data Type Conversion' */
  16U,                                 /* '<S355>/Data Type Conversion1' */
  5U,                                  /* '<S355>/Data Type Conversion2' */
  3U,                                  /* '<S354>/Data Type Conversion' */
  15U,                                 /* '<S354>/Data Type Conversion1' */
  5U,                                  /* '<S354>/Data Type Conversion2' */
  3U,                                  /* '<S356>/Data Type Conversion' */
  17U,                                 /* '<S356>/Data Type Conversion1' */
  5U,                                  /* '<S356>/Data Type Conversion2' */
  2U,                                  /* '<S35>/Data Type Conversion2' */
  2U,                                  /* '<S35>/Data Type Conversion1' */
  1U,                                  /* '<S34>/Data Type Conversion' */
  1U,                                  /* '<S34>/Data Type Conversion1' */

  /* Start of '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S506>/Sum' */
    0.0066943799901413165,             /* '<S506>/Multiply3' */
    0.99330562000985867                /* '<S506>/Sum4' */
  }
  ,

  /* End of '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */

  /* Start of '<S32>/Unknown' */
  {
    1U,                                /* '<S40>/Data Type Conversion' */
    1U                                 /* '<S40>/Data Type Conversion1' */
  }
  ,

  /* End of '<S32>/Unknown' */

  /* Start of '<S36>/Unknown' */
  {
    1U,                                /* '<S45>/Data Type Conversion' */
    1U                                 /* '<S45>/Data Type Conversion1' */
  }
  ,

  /* End of '<S36>/Unknown' */

  /* Start of '<S97>/Move Control' */
  {
    0.0004F,                           /* '<S106>/Square' */
    0.00628318498F,                    /* '<S106>/Multiply' */
    -15.707963F                        /* '<S106>/Gain4' */
  }
  ,

  /* End of '<S97>/Move Control' */

  /* Start of '<S71>/Move Control' */
  {
    0.0004F,                           /* '<S80>/Square' */
    0.00628318498F,                    /* '<S80>/Multiply' */
    -15.707963F                        /* '<S80>/Gain4' */
  }
  ,

  /* End of '<S71>/Move Control' */

  /* Start of '<S138>/Move Control' */
  {
    0.0004F,                           /* '<S147>/Square' */
    0.00628318498F,                    /* '<S147>/Multiply' */
    -15.707963F                        /* '<S147>/Gain4' */
  }
  ,

  /* End of '<S138>/Move Control' */

  /* Start of '<S37>/Unknown' */
  {
    1U,                                /* '<S152>/Data Type Conversion' */
    1U                                 /* '<S152>/Data Type Conversion1' */
  }
  ,

  /* End of '<S37>/Unknown' */

  /* Start of '<S199>/Move Control' */
  {
    0.00250000018F,                    /* '<S210>/Square' */
    0.14709F,                          /* '<S210>/Multiply' */
    -58.836F                           /* '<S210>/Gain4' */
  }
  ,

  /* End of '<S199>/Move Control' */

  /* Start of '<S199>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S206>/Vector Concatenate3' */
  }
  ,

  /* End of '<S199>/Hold Control' */

  /* Start of '<S189>/Move Control' */
  {
    0.00250000018F,                    /* '<S197>/Square' */
    0.196120009F,                      /* '<S197>/Multiply' */
    -78.448F                           /* '<S197>/Gain4' */
  }
  ,

  /* End of '<S189>/Move Control' */

  /* Start of '<S39>/Unknown' */
  {
    1U,                                /* '<S357>/Data Type Conversion' */
    1U                                 /* '<S357>/Data Type Conversion1' */
  }
  ,

  /* End of '<S39>/Unknown' */

  /* Start of '<S383>/Move Control' */
  {
    0.00250000018F,                    /* '<S394>/Square' */
    0.14709F,                          /* '<S394>/Multiply' */
    -58.836F                           /* '<S394>/Gain4' */
  }
  ,

  /* End of '<S383>/Move Control' */

  /* Start of '<S383>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S390>/Vector Concatenate3' */
  }
  ,

  /* End of '<S383>/Hold Control' */

  /* Start of '<S371>/Move Control' */
  {
    0.0004F,                           /* '<S381>/Square' */
    0.00628318498F,                    /* '<S381>/Multiply' */
    -15.707963F                        /* '<S381>/Gain4' */
  }
  ,

  /* End of '<S371>/Move Control' */

  /* Start of '<S361>/Move Control' */
  {
    0.00250000018F,                    /* '<S369>/Square' */
    0.196120009F,                      /* '<S369>/Multiply' */
    -78.448F                           /* '<S369>/Gain4' */
  }
  ,

  /* End of '<S361>/Move Control' */

  /* Start of '<S449>/Move Control' */
  {
    0.00250000018F,                    /* '<S460>/Square' */
    0.14709F,                          /* '<S460>/Multiply' */
    -58.836F                           /* '<S460>/Gain4' */
  }
  ,

  /* End of '<S449>/Move Control' */

  /* Start of '<S449>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S456>/Vector Concatenate3' */
  }
  ,

  /* End of '<S449>/Hold Control' */

  /* Start of '<S439>/Move Control' */
  {
    0.00250000018F,                    /* '<S447>/Square' */
    0.196120009F,                      /* '<S447>/Multiply' */
    -78.448F                           /* '<S447>/Gain4' */
  }
  /* End of '<S439>/Move Control' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
