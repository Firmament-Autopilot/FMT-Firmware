/*
 * File: rtGetNaN.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 13-Apr-2020 15:45:11
 */

/*
 * Abstract:
 *       MATLAB for code generation function to initialize non-finite, NaN
 */
#include "rtGetNaN.h"

/* Function: rtGetNaN ==================================================
 * Abstract:
 * Initialize rtNaN needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
real_T rtGetNaN_(void)
{
    real_T nan = 0.0;
    uint16_T one = 1U;
    enum {
        LittleEndian,
        BigEndian
    } machByteOrder
        = (*((uint8_T*)&one) == 1U) ? LittleEndian : BigEndian;

    switch (machByteOrder) {
    case LittleEndian: {
        union {
            LittleEndianIEEEDouble bitVal;
            real_T fltVal;
        } tmpVal;

        tmpVal.bitVal.words.wordH = 0xFFF80000U;
        tmpVal.bitVal.words.wordL = 0x00000000U;
        nan = tmpVal.fltVal;
        break;
    }

    case BigEndian: {
        union {
            BigEndianIEEEDouble bitVal;
            real_T fltVal;
        } tmpVal;

        tmpVal.bitVal.words.wordH = 0x7FFFFFFFU;
        tmpVal.bitVal.words.wordL = 0xFFFFFFFFU;
        nan = tmpVal.fltVal;
        break;
    }
    }

    return nan;
}

/* Function: rtGetNaNF ==================================================
 * Abstract:
 * Initialize rtNaNF needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetNaNF_(void)
{
    IEEESingle nanF = { { 0 } };

    uint16_T one = 1U;
    enum {
        LittleEndian,
        BigEndian
    } machByteOrder
        = (*((uint8_T*)&one) == 1U) ? LittleEndian : BigEndian;

    switch (machByteOrder) {
    case LittleEndian: {
        nanF.wordL.wordLuint = 0xFFC00000U;
        break;
    }

    case BigEndian: {
        nanF.wordL.wordLuint = 0x7FFFFFFFU;
        break;
    }
    }

    return nanF.wordL.wordLreal;
}

/*
 * File trailer for rtGetNaN.c
 *
 * [EOF]
 */
