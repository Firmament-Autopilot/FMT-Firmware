/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.1971
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Jul  8 09:55:29 2023
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
  1.9966471893352524,                  /* '<S309>/Sum' */
  0.0066943799901413165,               /* '<S309>/Multiply3' */
  0.99330562000985867,                 /* '<S309>/Sum4' */
  0.0,                                 /* '<S308>/deg2rad2' */
  0.0,                                 /* '<S311>/SinCos' */
  1.0,                                 /* '<S311>/SinCos' */
  0.0016F,                             /* '<S64>/Square' */
  0.0201061927F,                       /* '<S64>/Multiply' */
  -12.566371F,                         /* '<S64>/Gain4' */
  0.0016F,                             /* '<S65>/Square' */
  0.0201061927F,                       /* '<S65>/Multiply' */
  -12.566371F,                         /* '<S65>/Gain4' */
  0.0016F,                             /* '<S132>/Square' */
  0.0201061927F,                       /* '<S132>/Multiply' */
  -12.566371F,                         /* '<S132>/Gain4' */
  0.0016F,                             /* '<S133>/Square' */
  0.0201061927F,                       /* '<S133>/Multiply' */
  -12.566371F,                         /* '<S133>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S222>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S168>/Math Function' */
  1.0F,                                /* '<S168>/Sum of Elements' */
  1.0F,                                /* '<S168>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S168>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S168>/Switch' */

  { 0.0F, 1.0F },                      /* '<S168>/Divide' */
  0.616850317F,                        /* '<S164>/Square' */
  0.645964146F,                        /* '<S164>/Multiply' */
  -1.04719758F,                        /* '<S164>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S302>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S303>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S299>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S295>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S233>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S235>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S324>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S326>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S442>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S392>/Math Function' */
  1.0F,                                /* '<S392>/Sum of Elements' */
  1.0F,                                /* '<S392>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S392>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S392>/Switch' */

  { 0.0F, 1.0F },                      /* '<S392>/Divide' */
  0.616850317F,                        /* '<S388>/Square' */
  0.645964146F,                        /* '<S388>/Multiply' */
  -1.04719758F,                        /* '<S388>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S375>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S452>/Vector Concatenate3' */
  0.09F,                               /* '<S448>/Square' */
  0.88254F,                            /* '<S448>/Multiply' */
  -9.806F,                             /* '<S448>/Gain4' */
  1U,                                  /* '<S36>/Data Type Conversion' */
  12U,                                 /* '<S36>/Data Type Conversion1' */
  3U,                                  /* '<S41>/Data Type Conversion' */
  10U,                                 /* '<S41>/Data Type Conversion1' */
  5U,                                  /* '<S41>/Data Type Conversion2' */
  3U,                                  /* '<S40>/Data Type Conversion1' */
  9U,                                  /* '<S40>/Data Type Conversion2' */
  4U,                                  /* '<S40>/Data Type Conversion3' */
  3U,                                  /* '<S42>/Data Type Conversion' */
  8U,                                  /* '<S42>/Data Type Conversion1' */
  3U,                                  /* '<S42>/Data Type Conversion2' */
  3U,                                  /* '<S39>/Data Type Conversion' */
  7U,                                  /* '<S39>/Data Type Conversion1' */
  2U,                                  /* '<S39>/Data Type Conversion2' */
  3U,                                  /* '<S151>/Data Type Conversion' */
  4U,                                  /* '<S151>/Data Type Conversion1' */
  5U,                                  /* '<S151>/Data Type Conversion2' */
  3U,                                  /* '<S148>/Data Type Conversion' */
  3U,                                  /* '<S148>/Data Type Conversion1' */
  6U,                                  /* '<S148>/Data Type Conversion2' */
  3U,                                  /* '<S327>/Data Type Conversion' */
  6U,                                  /* '<S327>/Data Type Conversion1' */
  5U,                                  /* '<S327>/Data Type Conversion2' */
  3U,                                  /* '<S329>/Data Type Conversion' */
  16U,                                 /* '<S329>/Data Type Conversion1' */
  5U,                                  /* '<S329>/Data Type Conversion2' */
  3U,                                  /* '<S328>/Data Type Conversion' */
  15U,                                 /* '<S328>/Data Type Conversion1' */
  5U,                                  /* '<S328>/Data Type Conversion2' */
  3U,                                  /* '<S330>/Data Type Conversion' */
  17U,                                 /* '<S330>/Data Type Conversion1' */
  5U,                                  /* '<S330>/Data Type Conversion2' */
  2U,                                  /* '<S33>/Data Type Conversion2' */
  2U,                                  /* '<S33>/Data Type Conversion1' */
  1U,                                  /* '<S32>/Data Type Conversion' */
  1U,                                  /* '<S32>/Data Type Conversion1' */

  /* Start of '<S5>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S458>/Sum' */
    0.0066943799901413165,             /* '<S458>/Multiply3' */
    0.99330562000985867                /* '<S458>/Sum4' */
  }
  ,

  /* End of '<S5>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */

  /* Start of '<S30>/Unknown' */
  {
    1U,                                /* '<S38>/Data Type Conversion' */
    1U                                 /* '<S38>/Data Type Conversion1' */
  }
  ,

  /* End of '<S30>/Unknown' */

  /* Start of '<S34>/Unknown' */
  {
    1U,                                /* '<S43>/Data Type Conversion' */
    1U                                 /* '<S43>/Data Type Conversion1' */
  }
  ,

  /* End of '<S34>/Unknown' */

  /* Start of '<S110>/Move Control' */
  {
    0.00250000018F,                    /* '<S121>/Square' */
    0.14709F,                          /* '<S121>/Multiply' */
    -58.836F                           /* '<S121>/Gain4' */
  }
  ,

  /* End of '<S110>/Move Control' */

  /* Start of '<S110>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S117>/Vector Concatenate3' */
  }
  ,

  /* End of '<S110>/Hold Control' */

  /* Start of '<S97>/Move Control' */
  {
    0.0004F,                           /* '<S107>/Square' */
    0.00628318498F,                    /* '<S107>/Multiply' */
    -15.707963F                        /* '<S107>/Gain4' */
  }
  ,

  /* End of '<S97>/Move Control' */

  /* Start of '<S66>/Move Control' */
  {
    0.0004F,                           /* '<S76>/Square' */
    0.00628318498F,                    /* '<S76>/Multiply' */
    -15.707963F                        /* '<S76>/Gain4' */
  }
  ,

  /* End of '<S66>/Move Control' */

  /* Start of '<S134>/Move Control' */
  {
    0.0004F,                           /* '<S144>/Square' */
    0.00628318498F,                    /* '<S144>/Multiply' */
    -15.707963F                        /* '<S144>/Gain4' */
  }
  ,

  /* End of '<S134>/Move Control' */

  /* Start of '<S35>/Unknown' */
  {
    1U,                                /* '<S149>/Data Type Conversion' */
    1U                                 /* '<S149>/Data Type Conversion1' */
  }
  ,

  /* End of '<S35>/Unknown' */

  /* Start of '<S192>/Move Control' */
  {
    0.00250000018F,                    /* '<S203>/Square' */
    0.14709F,                          /* '<S203>/Multiply' */
    -58.836F                           /* '<S203>/Gain4' */
  }
  ,

  /* End of '<S192>/Move Control' */

  /* Start of '<S192>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S199>/Vector Concatenate3' */
  }
  ,

  /* End of '<S192>/Hold Control' */

  /* Start of '<S182>/Move Control' */
  {
    0.00250000018F,                    /* '<S190>/Square' */
    0.196120009F,                      /* '<S190>/Multiply' */
    -78.448F                           /* '<S190>/Gain4' */
  }
  ,

  /* End of '<S182>/Move Control' */

  /* Start of '<S37>/Unknown' */
  {
    1U,                                /* '<S331>/Data Type Conversion' */
    1U                                 /* '<S331>/Data Type Conversion1' */
  }
  ,

  /* End of '<S37>/Unknown' */

  /* Start of '<S357>/Move Control' */
  {
    0.00250000018F,                    /* '<S368>/Square' */
    0.14709F,                          /* '<S368>/Multiply' */
    -58.836F                           /* '<S368>/Gain4' */
  }
  ,

  /* End of '<S357>/Move Control' */

  /* Start of '<S357>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S364>/Vector Concatenate3' */
  }
  ,

  /* End of '<S357>/Hold Control' */

  /* Start of '<S345>/Move Control' */
  {
    0.0004F,                           /* '<S355>/Square' */
    0.00628318498F,                    /* '<S355>/Multiply' */
    -15.707963F                        /* '<S355>/Gain4' */
  }
  ,

  /* End of '<S345>/Move Control' */

  /* Start of '<S335>/Move Control' */
  {
    0.00250000018F,                    /* '<S343>/Square' */
    0.196120009F,                      /* '<S343>/Multiply' */
    -78.448F                           /* '<S343>/Gain4' */
  }
  ,

  /* End of '<S335>/Move Control' */

  /* Start of '<S412>/Move Control' */
  {
    0.00250000018F,                    /* '<S423>/Square' */
    0.14709F,                          /* '<S423>/Multiply' */
    -58.836F                           /* '<S423>/Gain4' */
  }
  ,

  /* End of '<S412>/Move Control' */

  /* Start of '<S412>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S419>/Vector Concatenate3' */
  }
  ,

  /* End of '<S412>/Hold Control' */

  /* Start of '<S402>/Move Control' */
  {
    0.00250000018F,                    /* '<S410>/Square' */
    0.196120009F,                      /* '<S410>/Multiply' */
    -78.448F                           /* '<S410>/Gain4' */
  }
  /* End of '<S402>/Move Control' */
};

/* Constant parameters (default storage) */
const ConstP_FMS_T FMS_ConstP = {
  /* Pooled Parameter (Expression: [4,4,2])
   * Referenced by:
   *   '<S288>/Saturation1'
   *   '<S290>/Saturation'
   *   '<S291>/Saturation1'
   */
  { 4.0F, 4.0F, 2.0F },

  /* Pooled Parameter (Expression: [-4,-4,-2])
   * Referenced by:
   *   '<S288>/Saturation1'
   *   '<S290>/Saturation'
   *   '<S291>/Saturation1'
   */
  { -4.0F, -4.0F, -2.0F }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
