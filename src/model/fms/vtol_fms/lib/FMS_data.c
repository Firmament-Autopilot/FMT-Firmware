/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2144
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Jul 24 10:37:11 2024
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
  1.9966471893352524,                  /* '<S502>/Sum' */
  0.0066943799901413165,               /* '<S502>/Multiply3' */
  0.99330562000985867,                 /* '<S502>/Sum4' */
  0.0,                                 /* '<S501>/deg2rad2' */
  0.0,                                 /* '<S504>/SinCos' */
  1.0,                                 /* '<S504>/SinCos' */

  { 0.0F, 0.0F, 1.0F },                /* '<S114>/Vector Concatenate3' */
  0.0004F,                             /* '<S84>/Square' */
  0.00628318498F,                      /* '<S84>/Multiply' */
  -15.707963F,                         /* '<S84>/Gain4' */
  0.00250000018F,                      /* '<S110>/Square' */
  0.14709F,                            /* '<S110>/Multiply' */
  -58.836F,                            /* '<S110>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S107>/Vector Concatenate3' */
  0.0004F,                             /* '<S66>/Square' */
  0.00628318498F,                      /* '<S66>/Multiply' */
  -15.707963F,                         /* '<S66>/Gain4' */
  0.0016F,                             /* '<S63>/Square' */
  0.0201061927F,                       /* '<S63>/Multiply' */
  -12.566371F,                         /* '<S63>/Gain4' */
  0.0016F,                             /* '<S122>/Square' */
  0.0201061927F,                       /* '<S122>/Multiply' */
  -12.566371F,                         /* '<S122>/Gain4' */
  0.0004F,                             /* '<S126>/Square' */
  0.00628318498F,                      /* '<S126>/Multiply' */
  -15.707963F,                         /* '<S126>/Gain4' */
  0.0016F,                             /* '<S123>/Square' */
  0.0201061927F,                       /* '<S123>/Multiply' */
  -12.566371F,                         /* '<S123>/Gain4' */
  0.00250000018F,                      /* '<S310>/Square' */
  0.14709F,                            /* '<S310>/Multiply' */
  -58.836F,                            /* '<S310>/Gain4' */
  0.0016F,                             /* '<S255>/Square' */
  0.0201061927F,                       /* '<S255>/Multiply' */
  -12.566371F,                         /* '<S255>/Gain4' */
  0.0016F,                             /* '<S254>/Square' */
  0.0201061927F,                       /* '<S254>/Multiply' */
  -12.566371F,                         /* '<S254>/Gain4' */
  0.0016F,                             /* '<S322>/Square' */
  0.0201061927F,                       /* '<S322>/Multiply' */
  -12.566371F,                         /* '<S322>/Gain4' */
  0.0016F,                             /* '<S321>/Square' */
  0.0201061927F,                       /* '<S321>/Multiply' */
  -12.566371F,                         /* '<S321>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S414>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S357>/Math Function' */
  1.0F,                                /* '<S357>/Sum of Elements' */
  1.0F,                                /* '<S357>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S357>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S357>/Switch' */

  { 0.0F, 1.0F },                      /* '<S357>/Divide' */
  0.616850317F,                        /* '<S353>/Square' */
  0.645964146F,                        /* '<S353>/Multiply' */
  -1.04719758F,                        /* '<S353>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S495>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S496>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S492>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S488>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S426>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S428>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S517>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S519>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S641>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S588>/Math Function' */
  1.0F,                                /* '<S588>/Sum of Elements' */
  1.0F,                                /* '<S588>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S588>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S588>/Switch' */

  { 0.0F, 1.0F },                      /* '<S588>/Divide' */
  0.616850317F,                        /* '<S584>/Square' */
  0.645964146F,                        /* '<S584>/Multiply' */
  -1.04719758F,                        /* '<S584>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S571>/Vector Concatenate3' */
  0.122499995F,                        /* '<S567>/Square' */
  1.20123494F,                         /* '<S567>/Multiply' */
  -9.806F,                             /* '<S567>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S652>/Vector Concatenate3' */
  0.122499995F,                        /* '<S648>/Square' */
  1.20123494F,                         /* '<S648>/Multiply' */
  -9.806F,                             /* '<S648>/Gain4' */
  3U,                                  /* '<S39>/Data Type Conversion' */
  12U,                                 /* '<S39>/Data Type Conversion1' */
  1U,                                  /* '<S39>/Data Type Conversion2' */
  3U,                                  /* '<S43>/Data Type Conversion' */
  10U,                                 /* '<S43>/Data Type Conversion1' */
  5U,                                  /* '<S43>/Data Type Conversion2' */
  3U,                                  /* '<S42>/Data Type Conversion1' */
  9U,                                  /* '<S42>/Data Type Conversion2' */
  4U,                                  /* '<S42>/Data Type Conversion3' */
  3U,                                  /* '<S44>/Data Type Conversion' */
  8U,                                  /* '<S44>/Data Type Conversion1' */
  3U,                                  /* '<S44>/Data Type Conversion2' */
  3U,                                  /* '<S131>/Data Type Conversion' */
  4U,                                  /* '<S131>/Data Type Conversion1' */
  5U,                                  /* '<S131>/Data Type Conversion2' */
  1U,                                  /* '<S128>/Data Type Conversion' */
  3U,                                  /* '<S128>/Data Type Conversion1' */
  3U,                                  /* '<S156>/Data Type Conversion' */
  6U,                                  /* '<S156>/Data Type Conversion1' */
  5U,                                  /* '<S156>/Data Type Conversion2' */
  3U,                                  /* '<S158>/Data Type Conversion' */
  16U,                                 /* '<S158>/Data Type Conversion1' */
  5U,                                  /* '<S158>/Data Type Conversion2' */
  3U,                                  /* '<S157>/Data Type Conversion' */
  15U,                                 /* '<S157>/Data Type Conversion1' */
  5U,                                  /* '<S157>/Data Type Conversion2' */
  3U,                                  /* '<S159>/Data Type Conversion' */
  17U,                                 /* '<S159>/Data Type Conversion1' */
  5U,                                  /* '<S159>/Data Type Conversion2' */
  1U,                                  /* '<S225>/Data Type Conversion' */
  12U,                                 /* '<S225>/Data Type Conversion1' */
  3U,                                  /* '<S230>/Data Type Conversion' */
  10U,                                 /* '<S230>/Data Type Conversion1' */
  5U,                                  /* '<S230>/Data Type Conversion2' */
  3U,                                  /* '<S229>/Data Type Conversion1' */
  9U,                                  /* '<S229>/Data Type Conversion2' */
  4U,                                  /* '<S229>/Data Type Conversion3' */
  3U,                                  /* '<S231>/Data Type Conversion' */
  8U,                                  /* '<S231>/Data Type Conversion1' */
  3U,                                  /* '<S231>/Data Type Conversion2' */
  3U,                                  /* '<S228>/Data Type Conversion' */
  7U,                                  /* '<S228>/Data Type Conversion1' */
  2U,                                  /* '<S228>/Data Type Conversion2' */
  3U,                                  /* '<S340>/Data Type Conversion' */
  4U,                                  /* '<S340>/Data Type Conversion1' */
  5U,                                  /* '<S340>/Data Type Conversion2' */
  3U,                                  /* '<S337>/Data Type Conversion' */
  3U,                                  /* '<S337>/Data Type Conversion1' */
  6U,                                  /* '<S337>/Data Type Conversion2' */
  3U,                                  /* '<S520>/Data Type Conversion' */
  6U,                                  /* '<S520>/Data Type Conversion1' */
  5U,                                  /* '<S520>/Data Type Conversion2' */
  3U,                                  /* '<S522>/Data Type Conversion' */
  16U,                                 /* '<S522>/Data Type Conversion1' */
  5U,                                  /* '<S522>/Data Type Conversion2' */
  3U,                                  /* '<S521>/Data Type Conversion' */
  15U,                                 /* '<S521>/Data Type Conversion1' */
  5U,                                  /* '<S521>/Data Type Conversion2' */
  3U,                                  /* '<S523>/Data Type Conversion' */
  17U,                                 /* '<S523>/Data Type Conversion1' */
  5U,                                  /* '<S523>/Data Type Conversion2' */
  2U,                                  /* '<S34>/Data Type Conversion2' */
  2U,                                  /* '<S34>/Data Type Conversion1' */
  1U,                                  /* '<S33>/Data Type Conversion' */
  1U,                                  /* '<S33>/Data Type Conversion1' */
  1,                                   /* '<S678>/Compare' */

  /* Start of '<S5>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S658>/Sum' */
    0.0066943799901413165,             /* '<S658>/Multiply3' */
    0.99330562000985867                /* '<S658>/Sum4' */
  }
  ,

  /* End of '<S5>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */

  /* Start of '<S35>/Unknown' */
  {
    1U,                                /* '<S41>/Data Type Conversion' */
    1U                                 /* '<S41>/Data Type Conversion1' */
  }
  ,

  /* End of '<S35>/Unknown' */

  /* Start of '<S37>/Unknown' */
  {
    1U,                                /* '<S45>/Data Type Conversion' */
    1U                                 /* '<S45>/Data Type Conversion1' */
  }
  ,

  /* End of '<S37>/Unknown' */

  /* Start of '<S71>/Move Control' */
  {
    0.00250000018F,                    /* '<S79>/Square' */
    0.196120009F,                      /* '<S79>/Multiply' */
    -78.448F                           /* '<S79>/Gain4' */
  }
  ,

  /* End of '<S71>/Move Control' */

  /* Start of '<S50>/Move Control' */
  {
    0.00250000018F,                    /* '<S58>/Square' */
    0.196120009F,                      /* '<S58>/Multiply' */
    -78.448F                           /* '<S58>/Gain4' */
  }
  ,

  /* End of '<S50>/Move Control' */

  /* Start of '<S38>/Unknown' */
  {
    1U,                                /* '<S129>/Data Type Conversion' */
    1U                                 /* '<S129>/Data Type Conversion1' */
  }
  ,

  /* End of '<S38>/Unknown' */

  /* Start of '<S40>/Unknown' */
  {
    1U,                                /* '<S160>/Data Type Conversion' */
    1U                                 /* '<S160>/Data Type Conversion1' */
  }
  ,

  /* End of '<S40>/Unknown' */

  /* Start of '<S36>/Unknown' */
  {
    1U,                                /* '<S227>/Data Type Conversion' */
    1U                                 /* '<S227>/Data Type Conversion1' */
  }
  ,

  /* End of '<S36>/Unknown' */

  /* Start of '<S223>/Unknown' */
  {
    1U,                                /* '<S232>/Data Type Conversion' */
    1U                                 /* '<S232>/Data Type Conversion1' */
  }
  ,

  /* End of '<S223>/Unknown' */

  /* Start of '<S297>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S304>/Vector Concatenate3' */
  }
  ,

  /* End of '<S297>/Hold Control' */

  /* Start of '<S284>/Move Control' */
  {
    0.0004F,                           /* '<S294>/Square' */
    0.00628318498F,                    /* '<S294>/Multiply' */
    -15.707963F                        /* '<S294>/Gain4' */
  }
  ,

  /* End of '<S284>/Move Control' */

  /* Start of '<S256>/Move Control' */
  {
    0.0004F,                           /* '<S266>/Square' */
    0.00628318498F,                    /* '<S266>/Multiply' */
    -15.707963F                        /* '<S266>/Gain4' */
  }
  ,

  /* End of '<S256>/Move Control' */

  /* Start of '<S323>/Move Control' */
  {
    0.0004F,                           /* '<S333>/Square' */
    0.00628318498F,                    /* '<S333>/Multiply' */
    -15.707963F                        /* '<S333>/Gain4' */
  }
  ,

  /* End of '<S323>/Move Control' */

  /* Start of '<S224>/Unknown' */
  {
    1U,                                /* '<S338>/Data Type Conversion' */
    1U                                 /* '<S338>/Data Type Conversion1' */
  }
  ,

  /* End of '<S224>/Unknown' */

  /* Start of '<S384>/Move Control' */
  {
    0.00250000018F,                    /* '<S395>/Square' */
    0.14709F,                          /* '<S395>/Multiply' */
    -58.836F                           /* '<S395>/Gain4' */
  }
  ,

  /* End of '<S384>/Move Control' */

  /* Start of '<S384>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S391>/Vector Concatenate3' */
  }
  ,

  /* End of '<S384>/Hold Control' */

  /* Start of '<S374>/Move Control' */
  {
    0.00250000018F,                    /* '<S382>/Square' */
    0.196120009F,                      /* '<S382>/Multiply' */
    -78.448F                           /* '<S382>/Gain4' */
  }
  ,

  /* End of '<S374>/Move Control' */

  /* Start of '<S226>/Unknown' */
  {
    1U,                                /* '<S524>/Data Type Conversion' */
    1U                                 /* '<S524>/Data Type Conversion1' */
  }
  ,

  /* End of '<S226>/Unknown' */

  /* Start of '<S550>/Move Control' */
  {
    0.00250000018F,                    /* '<S561>/Square' */
    0.14709F,                          /* '<S561>/Multiply' */
    -58.836F                           /* '<S561>/Gain4' */
  }
  ,

  /* End of '<S550>/Move Control' */

  /* Start of '<S550>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S557>/Vector Concatenate3' */
  }
  ,

  /* End of '<S550>/Hold Control' */

  /* Start of '<S538>/Move Control' */
  {
    0.0004F,                           /* '<S548>/Square' */
    0.00628318498F,                    /* '<S548>/Multiply' */
    -15.707963F                        /* '<S548>/Gain4' */
  }
  ,

  /* End of '<S538>/Move Control' */

  /* Start of '<S528>/Move Control' */
  {
    0.00250000018F,                    /* '<S536>/Square' */
    0.196120009F,                      /* '<S536>/Multiply' */
    -78.448F                           /* '<S536>/Gain4' */
  }
  ,

  /* End of '<S528>/Move Control' */

  /* Start of '<S611>/Move Control' */
  {
    0.00250000018F,                    /* '<S622>/Square' */
    0.14709F,                          /* '<S622>/Multiply' */
    -58.836F                           /* '<S622>/Gain4' */
  }
  ,

  /* End of '<S611>/Move Control' */

  /* Start of '<S611>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S618>/Vector Concatenate3' */
  }
  ,

  /* End of '<S611>/Hold Control' */

  /* Start of '<S601>/Move Control' */
  {
    0.00250000018F,                    /* '<S609>/Square' */
    0.196120009F,                      /* '<S609>/Multiply' */
    -78.448F                           /* '<S609>/Gain4' */
  }
  /* End of '<S601>/Move Control' */
};

/* Constant parameters (default storage) */
const ConstP_FMS_T FMS_ConstP = {
  /* Pooled Parameter (Expression: [4,4,2])
   * Referenced by:
   *   '<S481>/Saturation1'
   *   '<S483>/Saturation'
   *   '<S484>/Saturation1'
   */
  { 4.0F, 4.0F, 2.0F },

  /* Pooled Parameter (Expression: [-4,-4,-2])
   * Referenced by:
   *   '<S481>/Saturation1'
   *   '<S483>/Saturation'
   *   '<S484>/Saturation1'
   */
  { -4.0F, -4.0F, -2.0F }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
