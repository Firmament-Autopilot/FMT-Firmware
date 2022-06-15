/*
 * File: rtGetInf.c
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 13-Apr-2020 15:45:11
 */

/*
 * Abstract:
 *       MATLAB for code generation function to initialize non-finite, Inf and MinusInf
 */
#include "rtGetInf.h"

/* Function: rtGetInf ==================================================
 * Abstract:
 * Initialize rtInf needed by the generated code.
 */
real_T rtGetInf_(void)
{
    real_T inf = 0.0;
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

        tmpVal.bitVal.words.wordH = 0x7FF00000U;
        tmpVal.bitVal.words.wordL = 0x00000000U;
        inf = tmpVal.fltVal;
        break;
    }

    case BigEndian: {
        union {
            BigEndianIEEEDouble bitVal;
            real_T fltVal;
        } tmpVal;

        tmpVal.bitVal.words.wordH = 0x7FF00000U;
        tmpVal.bitVal.words.wordL = 0x00000000U;
        inf = tmpVal.fltVal;
        break;
    }
    }

    return inf;
}

/* Function: rtGetInfF ==================================================
 * Abstract:
 * Initialize rtInfF needed by the generated code.
 */
real32_T rtGetInfF_(void)
{
    IEEESingle infF;
    infF.wordL.wordLuint = 0x7F800000U;
    return infF.wordL.wordLreal;
}

/* Function: rtGetMinusInf ==================================================
 * Abstract:
 * Initialize rtMinusInf needed by the generated code.
 */
real_T rtGetMinusInf_(void)
{
    real_T minf = 0.0;
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

        tmpVal.bitVal.words.wordH = 0xFFF00000U;
        tmpVal.bitVal.words.wordL = 0x00000000U;
        minf = tmpVal.fltVal;
        break;
    }

    case BigEndian: {
        union {
            BigEndianIEEEDouble bitVal;
            real_T fltVal;
        } tmpVal;

        tmpVal.bitVal.words.wordH = 0xFFF00000U;
        tmpVal.bitVal.words.wordL = 0x00000000U;
        minf = tmpVal.fltVal;
        break;
    }
    }

    return minf;
}

/* Function: rtGetMinusInfF ==================================================
 * Abstract:
 * Initialize rtMinusInfF needed by the generated code.
 */
real32_T rtGetMinusInfF_(void)
{
    IEEESingle minfF;
    minfF.wordL.wordLuint = 0xFF800000U;
    return minfF.wordL.wordLreal;
}

/*
 * File trailer for rtGetInf.c
 *
 * [EOF]
 */
