/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1752
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Aug  6 09:30:23 2022
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
  0.0016F,                             /* '<S52>/Square' */
  0.0201061927F,                       /* '<S52>/Multiply' */
  -12.566371F,                         /* '<S52>/Gain4' */
  0.0016F,                             /* '<S53>/Square' */
  0.0201061927F,                       /* '<S53>/Multiply' */
  -12.566371F,                         /* '<S53>/Gain4' */
  0.0016F,                             /* '<S116>/Square' */
  0.0201061927F,                       /* '<S116>/Multiply' */
  -12.566371F,                         /* '<S116>/Gain4' */
  0.0016F,                             /* '<S117>/Square' */
  0.0201061927F,                       /* '<S117>/Multiply' */
  -12.566371F,                         /* '<S117>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S206>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S152>/Math Function' */
  1.0F,                                /* '<S152>/Sum of Elements' */
  1.0F,                                /* '<S152>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S152>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S152>/Switch' */

  { 0.0F, 1.0F },                      /* '<S152>/Divide' */
  0.616850317F,                        /* '<S148>/Square' */
  0.645964146F,                        /* '<S148>/Multiply' */
  -1.04719758F,                        /* '<S148>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S321>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S271>/Math Function' */
  1.0F,                                /* '<S271>/Sum of Elements' */
  1.0F,                                /* '<S271>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S271>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S271>/Switch' */

  { 0.0F, 1.0F },                      /* '<S271>/Divide' */
  0.616850317F,                        /* '<S267>/Square' */
  0.645964146F,                        /* '<S267>/Multiply' */
  -1.04719758F,                        /* '<S267>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S254>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S329>/Vector Concatenate3' */
  1U,                                  /* '<S24>/Data Type Conversion' */
  12U,                                 /* '<S24>/Data Type Conversion1' */
  3U,                                  /* '<S29>/Data Type Conversion' */
  10U,                                 /* '<S29>/Data Type Conversion1' */
  5U,                                  /* '<S29>/Data Type Conversion2' */
  3U,                                  /* '<S28>/Data Type Conversion1' */
  9U,                                  /* '<S28>/Data Type Conversion2' */
  4U,                                  /* '<S28>/Data Type Conversion3' */
  3U,                                  /* '<S30>/Data Type Conversion' */
  8U,                                  /* '<S30>/Data Type Conversion1' */
  3U,                                  /* '<S30>/Data Type Conversion2' */
  3U,                                  /* '<S27>/Data Type Conversion' */
  7U,                                  /* '<S27>/Data Type Conversion1' */
  2U,                                  /* '<S27>/Data Type Conversion2' */
  3U,                                  /* '<S135>/Data Type Conversion' */
  4U,                                  /* '<S135>/Data Type Conversion1' */
  5U,                                  /* '<S135>/Data Type Conversion2' */
  1U,                                  /* '<S132>/Data Type Conversion' */
  3U,                                  /* '<S132>/Data Type Conversion1' */
  3U,                                  /* '<S207>/Data Type Conversion' */
  6U,                                  /* '<S207>/Data Type Conversion1' */
  5U,                                  /* '<S207>/Data Type Conversion2' */
  3U,                                  /* '<S209>/Data Type Conversion' */
  16U,                                 /* '<S209>/Data Type Conversion1' */
  5U,                                  /* '<S209>/Data Type Conversion2' */
  3U,                                  /* '<S208>/Data Type Conversion' */
  15U,                                 /* '<S208>/Data Type Conversion1' */
  5U,                                  /* '<S208>/Data Type Conversion2' */
  3U,                                  /* '<S210>/Data Type Conversion' */
  17U,                                 /* '<S210>/Data Type Conversion1' */
  5U,                                  /* '<S210>/Data Type Conversion2' */
  2U,                                  /* '<S21>/Data Type Conversion2' */
  2U,                                  /* '<S21>/Data Type Conversion1' */

  /* Start of '<S3>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S335>/Sum' */
    0.0066943799901413165,             /* '<S335>/Multiply3' */
    0.99330562000985867                /* '<S335>/Sum4' */
  }
  ,

  /* End of '<S3>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */

  /* Start of '<S18>/Unknown' */
  {
    1U,                                /* '<S26>/Data Type Conversion' */
    1U                                 /* '<S26>/Data Type Conversion1' */
  }
  ,

  /* End of '<S18>/Unknown' */

  /* Start of '<S22>/Unknown' */
  {
    1U,                                /* '<S31>/Data Type Conversion' */
    1U                                 /* '<S31>/Data Type Conversion1' */
  }
  ,

  /* End of '<S22>/Unknown' */

  /* Start of '<S94>/Move Control' */
  {
    0.00250000018F,                    /* '<S105>/Square' */
    0.14709F,                          /* '<S105>/Multiply' */
    -58.836F                           /* '<S105>/Gain4' */
  }
  ,

  /* End of '<S94>/Move Control' */

  /* Start of '<S94>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S101>/Vector Concatenate3' */
  }
  ,

  /* End of '<S94>/Hold Control' */

  /* Start of '<S81>/Move Control' */
  {
    0.0004F,                           /* '<S91>/Square' */
    0.00628318498F,                    /* '<S91>/Multiply' */
    -15.707963F                        /* '<S91>/Gain4' */
  }
  ,

  /* End of '<S81>/Move Control' */

  /* Start of '<S70>/Move Control' */
  {
    0.00250000018F,                    /* '<S78>/Square' */
    0.196120009F,                      /* '<S78>/Multiply' */
    -78.448F                           /* '<S78>/Gain4' */
  }
  ,

  /* End of '<S70>/Move Control' */

  /* Start of '<S54>/Move Control' */
  {
    0.0004F,                           /* '<S64>/Square' */
    0.00628318498F,                    /* '<S64>/Multiply' */
    -15.707963F                        /* '<S64>/Gain4' */
  }
  ,

  /* End of '<S54>/Move Control' */

  /* Start of '<S37>/Move Control' */
  {
    0.00250000018F,                    /* '<S45>/Square' */
    0.196120009F,                      /* '<S45>/Multiply' */
    -78.448F                           /* '<S45>/Gain4' */
  }
  ,

  /* End of '<S37>/Move Control' */

  /* Start of '<S118>/Move Control' */
  {
    0.0004F,                           /* '<S128>/Square' */
    0.00628318498F,                    /* '<S128>/Multiply' */
    -15.707963F                        /* '<S128>/Gain4' */
  }
  ,

  /* End of '<S118>/Move Control' */

  /* Start of '<S23>/Unknown' */
  {
    1U,                                /* '<S133>/Data Type Conversion' */
    1U                                 /* '<S133>/Data Type Conversion1' */
  }
  ,

  /* End of '<S23>/Unknown' */

  /* Start of '<S176>/Move Control' */
  {
    0.00250000018F,                    /* '<S187>/Square' */
    0.14709F,                          /* '<S187>/Multiply' */
    -58.836F                           /* '<S187>/Gain4' */
  }
  ,

  /* End of '<S176>/Move Control' */

  /* Start of '<S176>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S183>/Vector Concatenate3' */
  }
  ,

  /* End of '<S176>/Hold Control' */

  /* Start of '<S166>/Move Control' */
  {
    0.00250000018F,                    /* '<S174>/Square' */
    0.196120009F,                      /* '<S174>/Multiply' */
    -78.448F                           /* '<S174>/Gain4' */
  }
  ,

  /* End of '<S166>/Move Control' */

  /* Start of '<S25>/Unknown' */
  {
    1U,                                /* '<S211>/Data Type Conversion' */
    1U                                 /* '<S211>/Data Type Conversion1' */
  }
  ,

  /* End of '<S25>/Unknown' */

  /* Start of '<S237>/Move Control' */
  {
    0.00250000018F,                    /* '<S248>/Square' */
    0.14709F,                          /* '<S248>/Multiply' */
    -58.836F                           /* '<S248>/Gain4' */
  }
  ,

  /* End of '<S237>/Move Control' */

  /* Start of '<S237>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S244>/Vector Concatenate3' */
  }
  ,

  /* End of '<S237>/Hold Control' */

  /* Start of '<S225>/Move Control' */
  {
    0.0004F,                           /* '<S235>/Square' */
    0.00628318498F,                    /* '<S235>/Multiply' */
    -15.707963F                        /* '<S235>/Gain4' */
  }
  ,

  /* End of '<S225>/Move Control' */

  /* Start of '<S215>/Move Control' */
  {
    0.00250000018F,                    /* '<S223>/Square' */
    0.196120009F,                      /* '<S223>/Multiply' */
    -78.448F                           /* '<S223>/Gain4' */
  }
  ,

  /* End of '<S215>/Move Control' */

  /* Start of '<S291>/Move Control' */
  {
    0.00250000018F,                    /* '<S302>/Square' */
    0.14709F,                          /* '<S302>/Multiply' */
    -58.836F                           /* '<S302>/Gain4' */
  }
  ,

  /* End of '<S291>/Move Control' */

  /* Start of '<S291>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S298>/Vector Concatenate3' */
  }
  ,

  /* End of '<S291>/Hold Control' */

  /* Start of '<S281>/Move Control' */
  {
    0.00250000018F,                    /* '<S289>/Square' */
    0.196120009F,                      /* '<S289>/Multiply' */
    -78.448F                           /* '<S289>/Gain4' */
  }
  ,

  /* End of '<S281>/Move Control' */

  /* Start of '<S16>/Disarm' */
  {
    1U,                                /* '<S20>/Data Type Conversion' */
    1U                                 /* '<S20>/Data Type Conversion1' */
  }
  /* End of '<S16>/Disarm' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
