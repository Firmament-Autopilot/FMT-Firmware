/*
 * File: rt_nonfinite.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 13-Apr-2020 15:45:11
 */

/*
 * Abstract:
 *      MATLAB for code generation function to initialize non-finites,
 *      (Inf, NaN and -Inf).
 */
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"

real_T   rtInf;
real_T   rtMinusInf;
real_T   rtNaN;
real32_T rtInfF;
real32_T rtMinusInfF;
real32_T rtNaNF;

/* Function: rt_InitInfAndNaN ==================================================
 * Abstract:
 * Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 * generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */
void rt_InitInfAndNaN_(size_t realSize)
{
    (void)realSize;
    rtNaN       = rtGetNaN_();
    rtNaNF      = rtGetNaNF_();
    rtInf       = rtGetInf_();
    rtInfF      = rtGetInfF_();
    rtMinusInf  = rtGetMinusInf_();
    rtMinusInfF = rtGetMinusInfF_();
}

/* Function: rtIsInf ==================================================
 * Abstract:
 * Test if value is infinite
 */
boolean_T rtIsInf_(real_T value)
{
    return ((value == rtInf || value == rtMinusInf) ? 1U : 0U);
}

/* Function: rtIsInfF =================================================
 * Abstract:
 * Test if single-precision value is infinite
 */
boolean_T rtIsInfF_(real32_T value)
{
    return (((value) == rtInfF || (value) == rtMinusInfF) ? 1U : 0U);
}

/* Function: rtIsNaN ==================================================
 * Abstract:
 * Test if value is not a number
 */
boolean_T rtIsNaN_(real_T value)
{
    return (value != value) ? 1U : 0U;
}

/* Function: rtIsNaNF =================================================
 * Abstract:
 * Test if single-precision value is not a number
 */
boolean_T rtIsNaNF_(real32_T value)
{
    return (value != value) ? 1U : 0U;
}

/*
 * File trailer for rt_nonfinite.c
 *
 * [EOF]
 */
