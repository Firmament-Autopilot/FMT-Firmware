/*
 * File: FMS_data.c
 *
 * Code generated for Simulink model 'FMS'.
 *
 * Model version                  : 1.2224
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Jun  6 14:31:03 2025
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
  1.9966471893352524,                  /* '<S532>/Sum' */
  0.0066943799901413165,               /* '<S532>/Multiply3' */
  0.99330562000985867,                 /* '<S532>/Sum4' */
  0.0,                                 /* '<S531>/deg2rad2' */
  0.0,                                 /* '<S534>/SinCos' */
  1.0,                                 /* '<S534>/SinCos' */
  0.00250000018F,                      /* '<S338>/Square' */
  0.14709F,                            /* '<S338>/Multiply' */
  -58.836F,                            /* '<S338>/Gain4' */
  0.0016F,                             /* '<S283>/Square' */
  0.0201061927F,                       /* '<S283>/Multiply' */
  -12.566371F,                         /* '<S283>/Gain4' */
  0.0016F,                             /* '<S282>/Square' */
  0.0201061927F,                       /* '<S282>/Multiply' */
  -12.566371F,                         /* '<S282>/Gain4' */
  0.0016F,                             /* '<S350>/Square' */
  0.0201061927F,                       /* '<S350>/Multiply' */
  -12.566371F,                         /* '<S350>/Gain4' */
  0.0016F,                             /* '<S349>/Square' */
  0.0201061927F,                       /* '<S349>/Multiply' */
  -12.566371F,                         /* '<S349>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S442>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S385>/Math Function' */
  1.0F,                                /* '<S385>/Sum of Elements' */
  1.0F,                                /* '<S385>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S385>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S385>/Switch' */

  { 0.0F, 1.0F },                      /* '<S385>/Divide' */
  0.616850317F,                        /* '<S381>/Square' */
  0.645964146F,                        /* '<S381>/Multiply' */
  -1.04719758F,                        /* '<S381>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S518>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S522>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S526>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S525>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S455>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S457>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S548>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S550>/Vector Concatenate3' */

  { 0.0F, 0.0F, 1.0F },                /* '<S672>/Vector Concatenate3' */

  { 0.0F, 1.0F },                      /* synthesized block */

  { 0.0F, 1.0F },                      /* '<S619>/Math Function' */
  1.0F,                                /* '<S619>/Sum of Elements' */
  1.0F,                                /* '<S619>/Math Function1' */

  { 0.0F, 0.0F },                      /* '<S619>/Product' */

  { 0.0F, 1.0F, 1.0F },                /* '<S619>/Switch' */

  { 0.0F, 1.0F },                      /* '<S619>/Divide' */
  0.616850317F,                        /* '<S615>/Square' */
  0.645964146F,                        /* '<S615>/Multiply' */
  -1.04719758F,                        /* '<S615>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S602>/Vector Concatenate3' */
  0.122499995F,                        /* '<S598>/Square' */
  1.20123494F,                         /* '<S598>/Multiply' */
  -9.806F,                             /* '<S598>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S683>/Vector Concatenate3' */
  0.122499995F,                        /* '<S679>/Square' */
  1.20123494F,                         /* '<S679>/Multiply' */
  -9.806F,                             /* '<S679>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S53>/Vector Concatenate3' */
  0.0F,                                /* '<S55>/Constant' */

  { 0.0F, 0.0F, 1.0F },                /* '<S142>/Vector Concatenate3' */
  0.0004F,                             /* '<S105>/Square' */
  0.00628318498F,                      /* '<S105>/Multiply' */
  -15.707963F,                         /* '<S105>/Gain4' */
  0.00250000018F,                      /* '<S138>/Square' */
  0.14709F,                            /* '<S138>/Multiply' */
  -58.836F,                            /* '<S138>/Gain4' */

  { 0.0F, 0.0F, 1.0F },                /* '<S135>/Vector Concatenate3' */
  0.0004F,                             /* '<S87>/Square' */
  0.00628318498F,                      /* '<S87>/Multiply' */
  -15.707963F,                         /* '<S87>/Gain4' */
  0.0016F,                             /* '<S84>/Square' */
  0.0201061927F,                       /* '<S84>/Multiply' */
  -12.566371F,                         /* '<S84>/Gain4' */
  0.0016F,                             /* '<S150>/Square' */
  0.0201061927F,                       /* '<S150>/Multiply' */
  -12.566371F,                         /* '<S150>/Gain4' */
  0.0004F,                             /* '<S154>/Square' */
  0.00628318498F,                      /* '<S154>/Multiply' */
  -15.707963F,                         /* '<S154>/Gain4' */
  0.0016F,                             /* '<S151>/Square' */
  0.0201061927F,                       /* '<S151>/Multiply' */
  -12.566371F,                         /* '<S151>/Gain4' */
  1U,                                  /* '<S253>/Data Type Conversion' */
  12U,                                 /* '<S253>/Data Type Conversion1' */
  3U,                                  /* '<S258>/Data Type Conversion' */
  10U,                                 /* '<S258>/Data Type Conversion1' */
  5U,                                  /* '<S258>/Data Type Conversion2' */
  3U,                                  /* '<S257>/Data Type Conversion1' */
  9U,                                  /* '<S257>/Data Type Conversion2' */
  4U,                                  /* '<S257>/Data Type Conversion3' */
  3U,                                  /* '<S259>/Data Type Conversion' */
  8U,                                  /* '<S259>/Data Type Conversion1' */
  3U,                                  /* '<S259>/Data Type Conversion2' */
  3U,                                  /* '<S256>/Data Type Conversion' */
  7U,                                  /* '<S256>/Data Type Conversion1' */
  2U,                                  /* '<S256>/Data Type Conversion2' */
  3U,                                  /* '<S368>/Data Type Conversion' */
  4U,                                  /* '<S368>/Data Type Conversion1' */
  5U,                                  /* '<S368>/Data Type Conversion2' */
  3U,                                  /* '<S365>/Data Type Conversion' */
  3U,                                  /* '<S365>/Data Type Conversion1' */
  6U,                                  /* '<S365>/Data Type Conversion2' */
  3U,                                  /* '<S551>/Data Type Conversion' */
  6U,                                  /* '<S551>/Data Type Conversion1' */
  5U,                                  /* '<S551>/Data Type Conversion2' */
  3U,                                  /* '<S553>/Data Type Conversion' */
  16U,                                 /* '<S553>/Data Type Conversion1' */
  5U,                                  /* '<S553>/Data Type Conversion2' */
  3U,                                  /* '<S552>/Data Type Conversion' */
  15U,                                 /* '<S552>/Data Type Conversion1' */
  5U,                                  /* '<S552>/Data Type Conversion2' */
  3U,                                  /* '<S554>/Data Type Conversion' */
  17U,                                 /* '<S554>/Data Type Conversion1' */
  5U,                                  /* '<S554>/Data Type Conversion2' */
  3U,                                  /* '<S45>/Data Type Conversion1' */
  10U,                                 /* '<S45>/Data Type Conversion2' */
  5U,                                  /* '<S45>/Data Type Conversion3' */
  3U,                                  /* '<S60>/Data Type Conversion' */
  12U,                                 /* '<S60>/Data Type Conversion1' */
  1U,                                  /* '<S60>/Data Type Conversion2' */
  3U,                                  /* '<S64>/Data Type Conversion' */
  10U,                                 /* '<S64>/Data Type Conversion1' */
  5U,                                  /* '<S64>/Data Type Conversion2' */
  3U,                                  /* '<S63>/Data Type Conversion1' */
  9U,                                  /* '<S63>/Data Type Conversion2' */
  4U,                                  /* '<S63>/Data Type Conversion3' */
  3U,                                  /* '<S65>/Data Type Conversion' */
  8U,                                  /* '<S65>/Data Type Conversion1' */
  3U,                                  /* '<S65>/Data Type Conversion2' */
  3U,                                  /* '<S159>/Data Type Conversion' */
  4U,                                  /* '<S159>/Data Type Conversion1' */
  5U,                                  /* '<S159>/Data Type Conversion2' */
  1U,                                  /* '<S156>/Data Type Conversion' */
  3U,                                  /* '<S156>/Data Type Conversion1' */
  3U,                                  /* '<S184>/Data Type Conversion' */
  6U,                                  /* '<S184>/Data Type Conversion1' */
  5U,                                  /* '<S184>/Data Type Conversion2' */
  3U,                                  /* '<S186>/Data Type Conversion' */
  16U,                                 /* '<S186>/Data Type Conversion1' */
  5U,                                  /* '<S186>/Data Type Conversion2' */
  3U,                                  /* '<S185>/Data Type Conversion' */
  15U,                                 /* '<S185>/Data Type Conversion1' */
  5U,                                  /* '<S185>/Data Type Conversion2' */
  3U,                                  /* '<S187>/Data Type Conversion' */
  17U,                                 /* '<S187>/Data Type Conversion1' */
  5U,                                  /* '<S187>/Data Type Conversion2' */
  2U,                                  /* '<S44>/Data Type Conversion2' */
  2U,                                  /* '<S44>/Data Type Conversion1' */
  1U,                                  /* '<S43>/Data Type Conversion' */
  1U,                                  /* '<S43>/Data Type Conversion1' */

  /* Start of '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */
  {
    1.9966471893352524,                /* '<S689>/Sum' */
    0.0066943799901413165,             /* '<S689>/Multiply3' */
    0.99330562000985867                /* '<S689>/Sum4' */
  }
  ,

  /* End of '<S6>/Vehicle.Arm.Auto.Mission.LLA2FLAT' */

  /* Start of '<S47>/Unknown' */
  {
    1U,                                /* '<S255>/Data Type Conversion' */
    1U                                 /* '<S255>/Data Type Conversion1' */
  }
  ,

  /* End of '<S47>/Unknown' */

  /* Start of '<S251>/Unknown' */
  {
    1U,                                /* '<S260>/Data Type Conversion' */
    1U                                 /* '<S260>/Data Type Conversion1' */
  }
  ,

  /* End of '<S251>/Unknown' */

  /* Start of '<S325>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S332>/Vector Concatenate3' */
  }
  ,

  /* End of '<S325>/Hold Control' */

  /* Start of '<S312>/Move Control' */
  {
    0.0004F,                           /* '<S322>/Square' */
    0.00628318498F,                    /* '<S322>/Multiply' */
    -15.707963F                        /* '<S322>/Gain4' */
  }
  ,

  /* End of '<S312>/Move Control' */

  /* Start of '<S284>/Move Control' */
  {
    0.0004F,                           /* '<S294>/Square' */
    0.00628318498F,                    /* '<S294>/Multiply' */
    -15.707963F                        /* '<S294>/Gain4' */
  }
  ,

  /* End of '<S284>/Move Control' */

  /* Start of '<S351>/Move Control' */
  {
    0.0004F,                           /* '<S361>/Square' */
    0.00628318498F,                    /* '<S361>/Multiply' */
    -15.707963F                        /* '<S361>/Gain4' */
  }
  ,

  /* End of '<S351>/Move Control' */

  /* Start of '<S252>/Unknown' */
  {
    1U,                                /* '<S366>/Data Type Conversion' */
    1U                                 /* '<S366>/Data Type Conversion1' */
  }
  ,

  /* End of '<S252>/Unknown' */

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
  ,

  /* End of '<S402>/Move Control' */

  /* Start of '<S254>/Unknown' */
  {
    1U,                                /* '<S555>/Data Type Conversion' */
    1U                                 /* '<S555>/Data Type Conversion1' */
  }
  ,

  /* End of '<S254>/Unknown' */

  /* Start of '<S581>/Move Control' */
  {
    0.00250000018F,                    /* '<S592>/Square' */
    0.14709F,                          /* '<S592>/Multiply' */
    -58.836F                           /* '<S592>/Gain4' */
  }
  ,

  /* End of '<S581>/Move Control' */

  /* Start of '<S581>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S588>/Vector Concatenate3' */
  }
  ,

  /* End of '<S581>/Hold Control' */

  /* Start of '<S569>/Move Control' */
  {
    0.0004F,                           /* '<S579>/Square' */
    0.00628318498F,                    /* '<S579>/Multiply' */
    -15.707963F                        /* '<S579>/Gain4' */
  }
  ,

  /* End of '<S569>/Move Control' */

  /* Start of '<S559>/Move Control' */
  {
    0.00250000018F,                    /* '<S567>/Square' */
    0.196120009F,                      /* '<S567>/Multiply' */
    -78.448F                           /* '<S567>/Gain4' */
  }
  ,

  /* End of '<S559>/Move Control' */

  /* Start of '<S642>/Move Control' */
  {
    0.00250000018F,                    /* '<S653>/Square' */
    0.14709F,                          /* '<S653>/Multiply' */
    -58.836F                           /* '<S653>/Gain4' */
  }
  ,

  /* End of '<S642>/Move Control' */

  /* Start of '<S642>/Hold Control' */
  {
    { 0.0F, 0.0F, 1.0F }               /* '<S649>/Vector Concatenate3' */
  }
  ,

  /* End of '<S642>/Hold Control' */

  /* Start of '<S632>/Move Control' */
  {
    0.00250000018F,                    /* '<S640>/Square' */
    0.196120009F,                      /* '<S640>/Multiply' */
    -78.448F                           /* '<S640>/Gain4' */
  }
  ,

  /* End of '<S632>/Move Control' */

  /* Start of '<S46>/Unknown' */
  {
    1U,                                /* '<S62>/Data Type Conversion' */
    1U                                 /* '<S62>/Data Type Conversion1' */
  }
  ,

  /* End of '<S46>/Unknown' */

  /* Start of '<S58>/Unknown' */
  {
    1U,                                /* '<S66>/Data Type Conversion' */
    1U                                 /* '<S66>/Data Type Conversion1' */
  }
  ,

  /* End of '<S58>/Unknown' */

  /* Start of '<S92>/Move Control' */
  {
    0.00250000018F,                    /* '<S100>/Square' */
    0.196120009F,                      /* '<S100>/Multiply' */
    -78.448F                           /* '<S100>/Gain4' */
  }
  ,

  /* End of '<S92>/Move Control' */

  /* Start of '<S71>/Move Control' */
  {
    0.00250000018F,                    /* '<S79>/Square' */
    0.196120009F,                      /* '<S79>/Multiply' */
    -78.448F                           /* '<S79>/Gain4' */
  }
  ,

  /* End of '<S71>/Move Control' */

  /* Start of '<S59>/Unknown' */
  {
    1U,                                /* '<S157>/Data Type Conversion' */
    1U                                 /* '<S157>/Data Type Conversion1' */
  }
  ,

  /* End of '<S59>/Unknown' */

  /* Start of '<S61>/Unknown' */
  {
    1U,                                /* '<S188>/Data Type Conversion' */
    1U                                 /* '<S188>/Data Type Conversion1' */
  }
  /* End of '<S61>/Unknown' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
