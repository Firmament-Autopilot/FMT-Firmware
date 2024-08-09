/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2161
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Aug  6 13:42:57 2024
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
  1.9966471893352524,                  /* '<S503>/Sum' */
  0.0066943799901413165,               /* '<S503>/Multiply3' */
  0.99330562000985867,                 /* '<S503>/Sum4' */
  0.0,                                 /* '<S502>/deg2rad2' */
  0.0,                                 /* '<S505>/SinCos' */
  1.0,                                 /* '<S505>/SinCos' */
  0.00250000018F,                      /* '<S311>/Square' */
  0.14709F,                            /* '<S311>/Multiply' */
  -58.836F,                            /* '<S311>/Gain4' */
  0.0016F,                             /* '<S256>/Square' */
  0.0201061927F,                       /* '<S256>/Multiply' */
  -12.566371F,                         /* '<S256>/Gain4' */
  0.0016F,                             /* '<S255>/Square' */
  0.0201061927F,                       /* '<S255>/Multiply' */
  -12.566371F,                         /* '<S255>/Gain4' */
  0.0016F,                             /* '<S323>/Square' */
  0.0201061927F,                       /* '<S323>/Multiply' */
  -12.566371F,                         /* '<S323>/Gain4' */
  0.0016F,                             /* '<S322>/Square' */
  0.0201061927F,                       /* '<S322>/Multiply' */
  -12.566371F,                         /* '<S322>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S415>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S358>/Math Function' */
  1.0F,                                /* '<S358>/Sum of Elements' */
  1.0F,                                /* '<S358>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S358>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S358>/Switch' */

  { 0.0F, 1.0F },                      /* '<S358>/Divide' */
  0.616850317F,                        /* '<S354>/Square' */
  0.645964146F,                        /* '<S354>/Multiply' */
  -1.04719758F,                        /* '<S354>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S496>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S497>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S493>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S489>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S427>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S429>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S518>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S520>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S642>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S589>/Math Function' */
  1.0F,                                /* '<S589>/Sum of Elements' */
  1.0F,                                /* '<S589>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S589>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S589>/Switch' */

  { 0.0F, 1.0F },                      /* '<S589>/Divide' */
  0.616850317F,                        /* '<S585>/Square' */
  0.645964146F,                        /* '<S585>/Multiply' */
  -1.04719758F,                        /* '<S585>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S572>/Vector Concatenate3' */
  0.122499995F,                        /* '<S568>/Square' */
  1.20123494F,                         /* '<S568>/Multiply' */
  -9.806F,                             /* '<S568>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S653>/Vector Concatenate3' */
  0.122499995F,                        /* '<S649>/Square' */
  1.20123494F,                         /* '<S649>/Multiply' */
  -9.806F,                             /* '<S649>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S115>/Vector Concatenate3' */
  0.0004F,                             /* '<S85>/Square' */
  0.00628318498F,                      /* '<S85>/Multiply' */
  -15.707963F,                         /* '<S85>/Gain4' */
  0.00250000018F,                      /* '<S111>/Square' */
  0.14709F,                            /* '<S111>/Multiply' */
  -58.836F,                            /* '<S111>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S108>/Vector Concatenate3' */
  0.0004F,                             /* '<S67>/Square' */
  0.00628318498F,                      /* '<S67>/Multiply' */
  -15.707963F,                         /* '<S67>/Gain4' */
  0.0016F,                             /* '<S64>/Square' */
  0.0201061927F,                       /* '<S64>/Multiply' */
  -12.566371F,                         /* '<S64>/Gain4' */
  0.0016F,                             /* '<S123>/Square' */
  0.0201061927F,                       /* '<S123>/Multiply' */
  -12.566371F,                         /* '<S123>/Gain4' */
  0.0004F,                             /* '<S127>/Square' */
  0.00628318498F,                      /* '<S127>/Multiply' */
  -15.707963F,                         /* '<S127>/Gain4' */
  0.0016F,                             /* '<S124>/Square' */
  0.0201061927F,                       /* '<S124>/Multiply' */
  -12.566371F,                         /* '<S124>/Gain4' */
  1U,                                  /* '<S226>/Data Type Conversion' */
  12U,                                 /* '<S226>/Data Type Conversion1' */
  3U,                                  /* '<S231>/Data Type Conversion' */
  10U,                                 /* '<S231>/Data Type Conversion1' */
  5U,                                  /* '<S231>/Data Type Conversion2' */
  3U,                                  /* '<S230>/Data Type Conversion1' */
  9U,                                  /* '<S230>/Data Type Conversion2' */
  4U,                                  /* '<S230>/Data Type Conversion3' */
  3U,                                  /* '<S232>/Data Type Conversion' */
  8U,                                  /* '<S232>/Data Type Conversion1' */
  3U,                                  /* '<S232>/Data Type Conversion2' */
  3U,                                  /* '<S229>/Data Type Conversion' */
  7U,                                  /* '<S229>/Data Type Conversion1' */
  2U,                                  /* '<S229>/Data Type Conversion2' */
  3U,                                  /* '<S341>/Data Type Conversion' */
  4U,                                  /* '<S341>/Data Type Conversion1' */
  5U,                                  /* '<S341>/Data Type Conversion2' */
  3U,                                  /* '<S338>/Data Type Conversion' */
  3U,                                  /* '<S338>/Data Type Conversion1' */
  6U,                                  /* '<S338>/Data Type Conversion2' */
  3U,                                  /* '<S521>/Data Type Conversion' */
  6U,                                  /* '<S521>/Data Type Conversion1' */
  5U,                                  /* '<S521>/Data Type Conversion2' */
  3U,                                  /* '<S523>/Data Type Conversion' */
  16U,                                 /* '<S523>/Data Type Conversion1' */
  5U,                                  /* '<S523>/Data Type Conversion2' */
  3U,                                  /* '<S522>/Data Type Conversion' */
  15U,                                 /* '<S522>/Data Type Conversion1' */
  5U,                                  /* '<S522>/Data Type Conversion2' */
  3U,                                  /* '<S524>/Data Type Conversion' */
  17U,                                 /* '<S524>/Data Type Conversion1' */
  5U,                                  /* '<S524>/Data Type Conversion2' */
  3U,                                  /* '<S35>/Data Type Conversion1' */
  9U,                                  /* '<S35>/Data Type Conversion2' */
  4U,                                  /* '<S35>/Data Type Conversion3' */
  3U,                                  /* '<S40>/Data Type Conversion' */
  12U,                                 /* '<S40>/Data Type Conversion1' */
  1U,                                  /* '<S40>/Data Type Conversion2' */
  3U,                                  /* '<S44>/Data Type Conversion' */
  10U,                                 /* '<S44>/Data Type Conversion1' */
  5U,                                  /* '<S44>/Data Type Conversion2' */
  3U,                                  /* '<S43>/Data Type Conversion1' */
  9U,                                  /* '<S43>/Data Type Conversion2' */
  4U,                                  /* '<S43>/Data Type Conversion3' */
  3U,                                  /* '<S45>/Data Type Conversion' */
  8U,                                  /* '<S45>/Data Type Conversion1' */
  3U,                                  /* '<S45>/Data Type Conversion2' */
  3U,                                  /* '<S132>/Data Type Conversion' */
  4U,                                  /* '<S132>/Data Type Conversion1' */
  5U,                                  /* '<S132>/Data Type Conversion2' */
  1U,                                  /* '<S129>/Data Type Conversion' */
  3U,                                  /* '<S129>/Data Type Conversion1' */
  3U,                                  /* '<S157>/Data Type Conversion' */
  6U,                                  /* '<S157>/Data Type Conversion1' */
  5U,                                  /* '<S157>/Data Type Conversion2' */
  3U,                                  /* '<S159>/Data Type Conversion' */
  16U,                                 /* '<S159>/Data Type Conversion1' */
  5U,                                  /* '<S159>/Data Type Conversion2' */
  3U,                                  /* '<S158>/Data Type Conversion' */
  15U,                                 /* '<S158>/Data Type Conversion1' */
  5U,                                  /* '<S158>/Data Type Conversion2' */
  3U,                                  /* '<S160>/Data Type Conversion' */
  17U,                                 /* '<S160>/Data Type Conversion1' */
  5U,                                  /* '<S160>/Data Type Conversion2' */
  2U,                                  /* '<S34>/Data Type Conversion2' */
  2U,                                  /* '<S34>/Data Type Conversion1' */
  1U,                                  /* '<S33>/Data Type Conversion' */
  1U,                                  /* '<S33>/Data Type Conversion1' */

  /* Start of '<S5>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S659>/Sum' */
    0.0066943799901413165,             /* '<S659>/Multiply3' */
    0.99330562000985867                /* '<S659>/Sum4' */
  }
  ,

  /* End of '<S5>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */

  /* Start of '<S37>/Unknown' */
  {
    1U,                                /* '<S228>/Data Type Conversion' */
    1U                                 /* '<S228>/Data Type Conversion1' */
  }
  ,

  /* End of '<S37>/Unknown' */

  /* Start of '<S224>/Unknown' */
  {
    1U,                                /* '<S233>/Data Type Conversion' */
    1U                                 /* '<S233>/Data Type Conversion1' */
  }
  ,

  /* End of '<S224>/Unknown' */

  /* Start of '<S298>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S305>/Vector Concatenate3' */
  }
  ,

  /* End of '<S298>/Hold Control' */

  /* Start of '<S285>/Move Control' */
  {
    0.0004F,                           /* '<S295>/Square' */
    0.00628318498F,                    /* '<S295>/Multiply' */
    -15.707963F                        /* '<S295>/Gain4' */
  }
  ,

  /* End of '<S285>/Move Control' */

  /* Start of '<S257>/Move Control' */
  {
    0.0004F,                           /* '<S267>/Square' */
    0.00628318498F,                    /* '<S267>/Multiply' */
    -15.707963F                        /* '<S267>/Gain4' */
  }
  ,

  /* End of '<S257>/Move Control' */

  /* Start of '<S324>/Move Control' */
  {
    0.0004F,                           /* '<S334>/Square' */
    0.00628318498F,                    /* '<S334>/Multiply' */
    -15.707963F                        /* '<S334>/Gain4' */
  }
  ,

  /* End of '<S324>/Move Control' */

  /* Start of '<S225>/Unknown' */
  {
    1U,                                /* '<S339>/Data Type Conversion' */
    1U                                 /* '<S339>/Data Type Conversion1' */
  }
  ,

  /* End of '<S225>/Unknown' */

  /* Start of '<S385>/Move Control' */
  {
    0.00250000018F,                    /* '<S396>/Square' */
    0.14709F,                          /* '<S396>/Multiply' */
    -58.836F                           /* '<S396>/Gain4' */
  }
  ,

  /* End of '<S385>/Move Control' */

  /* Start of '<S385>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S392>/Vector Concatenate3' */
  }
  ,

  /* End of '<S385>/Hold Control' */

  /* Start of '<S375>/Move Control' */
  {
    0.00250000018F,                    /* '<S383>/Square' */
    0.196120009F,                      /* '<S383>/Multiply' */
    -78.448F                           /* '<S383>/Gain4' */
  }
  ,

  /* End of '<S375>/Move Control' */

  /* Start of '<S227>/Unknown' */
  {
    1U,                                /* '<S525>/Data Type Conversion' */
    1U                                 /* '<S525>/Data Type Conversion1' */
  }
  ,

  /* End of '<S227>/Unknown' */

  /* Start of '<S551>/Move Control' */
  {
    0.00250000018F,                    /* '<S562>/Square' */
    0.14709F,                          /* '<S562>/Multiply' */
    -58.836F                           /* '<S562>/Gain4' */
  }
  ,

  /* End of '<S551>/Move Control' */

  /* Start of '<S551>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S558>/Vector Concatenate3' */
  }
  ,

  /* End of '<S551>/Hold Control' */

  /* Start of '<S539>/Move Control' */
  {
    0.0004F,                           /* '<S549>/Square' */
    0.00628318498F,                    /* '<S549>/Multiply' */
    -15.707963F                        /* '<S549>/Gain4' */
  }
  ,

  /* End of '<S539>/Move Control' */

  /* Start of '<S529>/Move Control' */
  {
    0.00250000018F,                    /* '<S537>/Square' */
    0.196120009F,                      /* '<S537>/Multiply' */
    -78.448F                           /* '<S537>/Gain4' */
  }
  ,

  /* End of '<S529>/Move Control' */

  /* Start of '<S612>/Move Control' */
  {
    0.00250000018F,                    /* '<S623>/Square' */
    0.14709F,                          /* '<S623>/Multiply' */
    -58.836F                           /* '<S623>/Gain4' */
  }
  ,

  /* End of '<S612>/Move Control' */

  /* Start of '<S612>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S619>/Vector Concatenate3' */
  }
  ,

  /* End of '<S612>/Hold Control' */

  /* Start of '<S602>/Move Control' */
  {
    0.00250000018F,                    /* '<S610>/Square' */
    0.196120009F,                      /* '<S610>/Multiply' */
    -78.448F                           /* '<S610>/Gain4' */
  }
  ,

  /* End of '<S602>/Move Control' */

  /* Start of '<S36>/Unknown' */
  {
    1U,                                /* '<S42>/Data Type Conversion' */
    1U                                 /* '<S42>/Data Type Conversion1' */
  }
  ,

  /* End of '<S36>/Unknown' */

  /* Start of '<S38>/Unknown' */
  {
    1U,                                /* '<S46>/Data Type Conversion' */
    1U                                 /* '<S46>/Data Type Conversion1' */
  }
  ,

  /* End of '<S38>/Unknown' */

  /* Start of '<S72>/Move Control' */
  {
    0.00250000018F,                    /* '<S80>/Square' */
    0.196120009F,                      /* '<S80>/Multiply' */
    -78.448F                           /* '<S80>/Gain4' */
  }
  ,

  /* End of '<S72>/Move Control' */

  /* Start of '<S51>/Move Control' */
  {
    0.00250000018F,                    /* '<S59>/Square' */
    0.196120009F,                      /* '<S59>/Multiply' */
    -78.448F                           /* '<S59>/Gain4' */
  }
  ,

  /* End of '<S51>/Move Control' */

  /* Start of '<S39>/Unknown' */
  {
    1U,                                /* '<S130>/Data Type Conversion' */
    1U                                 /* '<S130>/Data Type Conversion1' */
  }
  ,

  /* End of '<S39>/Unknown' */

  /* Start of '<S41>/Unknown' */
  {
    1U,                                /* '<S161>/Data Type Conversion' */
    1U                                 /* '<S161>/Data Type Conversion1' */
  }
  /* End of '<S41>/Unknown' */
};

/* Constant parameters (default storage) */
const ConstP_FMS_T FMS_ConstP = {
  /* Pooled Parameter (Expression: [4,4,2])
   * Referenced by:
   *   '<S482>/Saturation1'
   *   '<S484>/Saturation'
   *   '<S485>/Saturation1'
   */
  { 4.0F, 4.0F, 2.0F },

  /* Pooled Parameter (Expression: [-4,-4,-2])
   * Referenced by:
   *   '<S482>/Saturation1'
   *   '<S484>/Saturation'
   *   '<S485>/Saturation1'
   */
  { -4.0F, -4.0F, -2.0F }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
