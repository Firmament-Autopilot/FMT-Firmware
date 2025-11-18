/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2247
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Nov 18 15:56:22 2025
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
  1.9966471893352524,                  /* '<S324>/Sum' */
  0.0066943799901413165,               /* '<S324>/Multiply3' */
  0.99330562000985867,                 /* '<S324>/Sum4' */
  0.0,                                 /* '<S323>/deg2rad2' */
  0.0,                                 /* '<S326>/SinCos' */
  1.0,                                 /* '<S326>/SinCos' */
  0.00250000018F,                      /* '<S122>/Square' */

  { 0.0F, 0.0F, 1.0F },                /* '<S115>/Vector Concatenate3' */
  0.0016F,                             /* '<S69>/Square' */
  0.0016F,                             /* '<S70>/Square' */
  0.0016F,                             /* '<S136>/Square' */
  0.0016F,                             /* '<S137>/Square' */

  { 0.0F, 0.0F, 1.0F },                /* '<S231>/Vector Concatenate3' */

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

  { 0.0F, 0.0F, 1.0F },                /* '<S310>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S314>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S318>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S317>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S244>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S246>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S340>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S342>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S471>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S411>/Math Function' */
  1.0F,                                /* '<S411>/Sum of Elements' */
  1.0F,                                /* '<S411>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S411>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S411>/Switch' */

  { 0.0F, 1.0F },                      /* '<S411>/Divide' */
  0.616850317F,                        /* '<S407>/Square' */
  0.645964146F,                        /* '<S407>/Multiply' */
  -1.04719758F,                        /* '<S407>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S394>/Vector Concatenate3' */
  0.122499995F,                        /* '<S390>/Square' */
  1.20123494F,                         /* '<S390>/Multiply' */
  -9.806F,                             /* '<S390>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S482>/Vector Concatenate3' */
  0.122499995F,                        /* '<S478>/Square' */
  1.20123494F,                         /* '<S478>/Multiply' */
  -9.806F,                             /* '<S478>/Gain4' */
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
  3U,                                  /* '<S343>/Data Type Conversion' */
  6U,                                  /* '<S343>/Data Type Conversion1' */
  5U,                                  /* '<S343>/Data Type Conversion2' */
  3U,                                  /* '<S345>/Data Type Conversion' */
  16U,                                 /* '<S345>/Data Type Conversion1' */
  5U,                                  /* '<S345>/Data Type Conversion2' */
  3U,                                  /* '<S344>/Data Type Conversion' */
  15U,                                 /* '<S344>/Data Type Conversion1' */
  5U,                                  /* '<S344>/Data Type Conversion2' */
  3U,                                  /* '<S346>/Data Type Conversion' */
  17U,                                 /* '<S346>/Data Type Conversion1' */
  5U,                                  /* '<S346>/Data Type Conversion2' */
  2U,                                  /* '<S35>/Data Type Conversion2' */
  2U,                                  /* '<S35>/Data Type Conversion1' */
  1U,                                  /* '<S34>/Data Type Conversion' */
  1U,                                  /* '<S34>/Data Type Conversion1' */

  /* Start of '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S489>/Sum' */
    0.0066943799901413165,             /* '<S489>/Multiply3' */
    0.99330562000985867                /* '<S489>/Sum4' */
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

  /* Start of '<S201>/Move Control' */
  {
    0.00250000018F,                    /* '<S212>/Square' */
    0.14709F,                          /* '<S212>/Multiply' */
    -58.836F                           /* '<S212>/Gain4' */
  }
  ,

  /* End of '<S201>/Move Control' */

  /* Start of '<S201>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S208>/Vector Concatenate3' */
  }
  ,

  /* End of '<S201>/Hold Control' */

  /* Start of '<S191>/Move Control' */
  {
    0.00250000018F,                    /* '<S199>/Square' */
    0.196120009F,                      /* '<S199>/Multiply' */
    -78.448F                           /* '<S199>/Gain4' */
  }
  ,

  /* End of '<S191>/Move Control' */

  /* Start of '<S39>/Unknown' */
  {
    1U,                                /* '<S347>/Data Type Conversion' */
    1U                                 /* '<S347>/Data Type Conversion1' */
  }
  ,

  /* End of '<S39>/Unknown' */

  /* Start of '<S373>/Move Control' */
  {
    0.00250000018F,                    /* '<S384>/Square' */
    0.14709F,                          /* '<S384>/Multiply' */
    -58.836F                           /* '<S384>/Gain4' */
  }
  ,

  /* End of '<S373>/Move Control' */

  /* Start of '<S373>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S380>/Vector Concatenate3' */
  }
  ,

  /* End of '<S373>/Hold Control' */

  /* Start of '<S361>/Move Control' */
  {
    0.0004F,                           /* '<S371>/Square' */
    0.00628318498F,                    /* '<S371>/Multiply' */
    -15.707963F                        /* '<S371>/Gain4' */
  }
  ,

  /* End of '<S361>/Move Control' */

  /* Start of '<S351>/Move Control' */
  {
    0.00250000018F,                    /* '<S359>/Square' */
    0.196120009F,                      /* '<S359>/Multiply' */
    -78.448F                           /* '<S359>/Gain4' */
  }
  ,

  /* End of '<S351>/Move Control' */

  /* Start of '<S441>/Move Control' */
  {
    0.00250000018F,                    /* '<S452>/Square' */
    0.14709F,                          /* '<S452>/Multiply' */
    -58.836F                           /* '<S452>/Gain4' */
  }
  ,

  /* End of '<S441>/Move Control' */

  /* Start of '<S441>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S448>/Vector Concatenate3' */
  }
  ,

  /* End of '<S441>/Hold Control' */

  /* Start of '<S431>/Move Control' */
  {
    0.00250000018F,                    /* '<S439>/Square' */
    0.196120009F,                      /* '<S439>/Multiply' */
    -78.448F                           /* '<S439>/Gain4' */
  }
  /* End of '<S431>/Move Control' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
