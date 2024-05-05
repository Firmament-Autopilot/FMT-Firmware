/*
 * File: Plant.c
 *
 * Code generated for Simulink model 'Plant'.
 *
 * Model version                  : 1.92
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sun May  5 13:48:06 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Plant.h"
#include "Plant_private.h"

const Plant_States_Bus Plant_rtZPlant_States_Bus = {
  0U,                                  /* timestamp */
  0.0F,                                /* phi */
  0.0F,                                /* theta */
  0.0F,                                /* psi */
  0.0F,                                /* rot_x_B */
  0.0F,                                /* rot_y_B */
  0.0F,                                /* rot_z_B */
  0.0F,                                /* acc_x_O */
  0.0F,                                /* acc_y_O */
  0.0F,                                /* acc_z_O */
  0.0F,                                /* vel_x_O */
  0.0F,                                /* vel_y_O */
  0.0F,                                /* vel_z_O */
  0.0F,                                /* x_R */
  0.0F,                                /* y_R */
  0.0F,                                /* h_R */
  0.0,                                 /* lat */
  0.0,                                 /* lon */
  0.0,                                 /* alt */
  0.0,                                 /* lat_0 */
  0.0,                                 /* lon_0 */
  0.0                                  /* alt_0 */
} ;                                    /* Plant_States_Bus ground */

const Extended_States_Bus Plant_rtZExtended_States_Bus = {
  0.0F,                                /* temprature */

  {
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
  ,                                    /* prop_vel */

  {
    0.0F, 0.0F, 0.0F, 0.0F }
  ,                                    /* quat */

  {
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
  ,                                    /* M_BO */

  {
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
  ,                                    /* M_OB */
  0.0F                                 /* Va */
} ;                                    /* Extended_States_Bus ground */

const AirSpeed_Bus Plant_rtZAirSpeed_Bus = {
  0U,                                  /* timestamp */
  0.0F,                                /* diff_pressure */
  0.0F                                 /* temperature */
} ;                                    /* AirSpeed_Bus ground */

/* Exported block parameters */
struct_3bORdf2BsPDFMyyhwl9bpH PLANT_PARAM = {
  0.65673,
  -2.1361,
  4.5
} ;                                    /* Variable: PLANT_PARAM
                                        * Referenced by:
                                        *   '<S2>/Constant1'
                                        *   '<S2>/Constant2'
                                        *   '<S2>/Constant3'
                                        *   '<S44>/Constant1'
                                        *   '<S44>/Constant2'
                                        *   '<S44>/Constant3'
                                        */

struct_jgVLU9PsiazymsYzo6u6IH PLANT_EXPORT = {
  2U,

  { 70, 105, 120, 119, 105, 110, 103, 32, 118, 49, 46, 48, 46, 48, 0 }
} ;                                    /* Variable: PLANT_EXPORT
                                        * Referenced by:
                                        *   '<S42>/dt'
                                        *   '<S118>/dt'
                                        */

/* Block signals (default storage) */
B_Plant_T Plant_B;

/* Block states (default storage) */
DW_Plant_T Plant_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Plant_T Plant_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Plant_T Plant_Y;

/* Real-time model */
RT_MODEL_Plant_T Plant_M_;
RT_MODEL_Plant_T *const Plant_M = &Plant_M_;
static void rate_scheduler(void);

/* Lookup Binary Search Utility BINARYSEARCH_real_T */
void BINARYSEARCH_real_T(uint32_T *piLeft, uint32_T *piRght, real_T u, const
  real_T *pData, uint32_T iHi)
{
  /* Find the location of current input value in the data table. */
  *piLeft = 0U;
  *piRght = iHi;
  if (u <= pData[0] ) {
    /* Less than or equal to the smallest point in the table. */
    *piRght = 0U;
  } else if (u >= pData[iHi] ) {
    /* Greater than or equal to the largest point in the table. */
    *piLeft = iHi;
  } else {
    uint32_T i;

    /* Do a binary search. */
    while (( *piRght - *piLeft ) > 1U ) {
      /* Get the average of the left and right indices using to Floor rounding. */
      i = (*piLeft + *piRght) >> 1;

      /* Move either the right index or the left index so that */
      /*  LeftDataPoint <= CurrentValue < RightDataPoint */
      if (u < pData[i] ) {
        *piRght = i;
      } else {
        *piLeft = i;
      }
    }
  }
}

/* Lookup 2D Lookup Utility Look2D_real_T_real_T_real_T */
void Look2D_real_T_real_T_real_T(real_T *pY, const real_T *pYData, real_T u0,
  const real_T *pU0Data, uint32_T iHiU0, real_T u1, const real_T *pU1Data,
  uint32_T iHiU1)
{
  uint32_T iLeftU0, iRghtU0, iLeftU1, iRghtU1;
  BINARYSEARCH_real_T( &(iLeftU0), &(iRghtU0), u0, pU0Data, iHiU0);
  BINARYSEARCH_real_T( &(iLeftU1), &(iRghtU1), u1, pU1Data, iHiU1);

  {
    real_T u0Left = pU0Data[iLeftU0];
    real_T u0Rght = pU0Data[iRghtU0];
    real_T u1Left = pU1Data[iLeftU1];
    real_T u1Rght = pU1Data[iRghtU1];
    real_T yTemp;
    real_T yLeftLeft;
    real_T yLeftRght;
    real_T yRghtLeft;
    real_T yRghtRght;
    real_T u1Lambda;
    real_T u0Lambda;
    if (u1Rght > u1Left ) {
      real_T num;
      real_T den;
      den = u1Rght;
      den -= u1Left;
      num = u1;
      num -= u1Left;
      u1Lambda = num / den;
    } else {
      u1Lambda = 0.0;
    }

    if (u0Rght > u0Left ) {
      real_T num;
      real_T den;
      den = u0Rght;
      den -= u0Left;
      num = u0;
      num -= u0Left;
      u0Lambda = num / den;
    } else {
      u0Lambda = 0.0;
    }

    iHiU0++;
    iLeftU1 *= iHiU0;
    iRghtU1 *= iHiU0;
    yRghtLeft = pYData[(iRghtU0+iLeftU1)];
    yRghtRght = pYData[(iRghtU0+iRghtU1)];
    yLeftLeft = pYData[(iLeftU0+iLeftU1)];
    yLeftRght = pYData[(iLeftU0+iRghtU1)];

    /* Interpolate along U1 variable
     *    with the u0 variable locked on the left u0
     */
    {
      real_T yLeftCast;
      real_T yRghtCast;
      yLeftCast = yLeftLeft;
      yRghtCast = yLeftRght;
      yLeftCast += u1Lambda * ( yRghtCast - yLeftCast );
      (*pY) = yLeftCast;
    }

    /* Interpolate along U1 variable
     *    with the u0 variable locked on the right u0
     */
    {
      real_T yLeftCast;
      real_T yRghtCast;
      yLeftCast = yRghtLeft;
      yRghtCast = yRghtRght;
      yLeftCast += u1Lambda * ( yRghtCast - yLeftCast );
      yTemp = yLeftCast;
    }

    /*
     * Interpolate along u0 variable
     *    with the u1 variable locked on its interpolated value
     */
    {
      real_T yLeftCast;
      real_T yRghtCast;
      yLeftCast = (*pY);
      yRghtCast = yTemp;
      yLeftCast += u0Lambda * ( yRghtCast - yLeftCast );
      (*pY) = yLeftCast;
    }
  }
}

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Plant_M->Timing.TaskCounters.TID[1])++;
  if ((Plant_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.004s, 0.0s] */
    Plant_M->Timing.TaskCounters.TID[1] = 0;
  }

  (Plant_M->Timing.TaskCounters.TID[2])++;
  if ((Plant_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.01s, 0.0s] */
    Plant_M->Timing.TaskCounters.TID[2] = 0;
  }

  (Plant_M->Timing.TaskCounters.TID[3])++;
  if ((Plant_M->Timing.TaskCounters.TID[3]) > 49) {/* Sample time: [0.1s, 0.0s] */
    Plant_M->Timing.TaskCounters.TID[3] = 0;
  }
}

void rt_mldivide_U1f3x3_U2f3_Yf3x1(const real32_T u0[9], const real32_T u1[3],
  real32_T y[3])
{
  real32_T A[9];
  int32_T r1;
  int32_T r2;
  int32_T r3;
  real32_T maxval;
  real32_T a21;
  int32_T rtemp;
  for (r1 = 0; r1 < 9; r1++) {
    A[r1] = u0[r1];
  }

  r1 = 0;
  r2 = 1;
  r3 = 2;
  maxval = fabsf(u0[0]);
  a21 = fabsf(u0[1]);
  if (a21 > maxval) {
    maxval = a21;
    r1 = 1;
    r2 = 0;
  }

  if (fabsf(u0[2]) > maxval) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }

  A[r2] = u0[r2] / u0[r1];
  A[r3] /= A[r1];
  A[3 + r2] -= A[3 + r1] * A[r2];
  A[3 + r3] -= A[3 + r1] * A[r3];
  A[6 + r2] -= A[6 + r1] * A[r2];
  A[6 + r3] -= A[6 + r1] * A[r3];
  if (fabsf(A[3 + r3]) > fabsf(A[3 + r2])) {
    rtemp = r2 + 1;
    r2 = r3;
    r3 = rtemp - 1;
  }

  A[3 + r3] /= A[3 + r2];
  A[6 + r3] -= A[3 + r3] * A[6 + r2];
  y[1] = u1[r2] - u1[r1] * A[r2];
  y[2] = (u1[r3] - u1[r1] * A[r3]) - A[3 + r3] * y[1];
  y[2] /= A[6 + r3];
  y[0] = u1[r1] - A[6 + r1] * y[2];
  y[1] -= A[6 + r2] * y[2];
  y[1] /= A[3 + r2];
  y[0] -= A[3 + r1] * y[1];
  y[0] /= A[r1];
}

void RandSrc_GZ_R(real32_T y[], const real32_T mean[], int32_T meanLen, const
                  real32_T xstd[], int32_T xstdLen, uint32_T state[], int32_T
                  nChans, int32_T nSamps)
{
  int32_T i;
  int32_T j;
  real32_T r;
  real32_T x;
  real32_T s;
  real32_T y_0;
  int32_T chan;
  real32_T std;
  uint32_T icng;
  uint32_T jsr;
  int32_T samp;
  static const real32_T vt[65] = { 0.340945F, 0.45731461F, 0.539779305F,
    0.606242716F, 0.663169086F, 0.713697493F, 0.759612501F, 0.80203563F,
    0.841722727F, 0.879210174F, 0.914894819F, 0.949079096F, 0.98200053F,
    1.01384926F, 1.04478097F, 1.07492542F, 1.10439169F, 1.13327384F, 1.16165304F,
    1.18960094F, 1.21718144F, 1.24445164F, 1.27146351F, 1.29826498F, 1.32490075F,
    1.35141253F, 1.37783992F, 1.40422106F, 1.43059289F, 1.45699155F, 1.48345268F,
    1.51001215F, 1.53670609F, 1.56357121F, 1.59064543F, 1.61796796F, 1.64558017F,
    1.67352545F, 1.7018503F, 1.73060453F, 1.75984216F, 1.78962231F, 1.82001F,
    1.85107696F, 1.88290441F, 1.91558313F, 1.9492166F, 1.98392391F, 2.0198431F,
    2.05713558F, 2.09599304F, 2.13664508F, 2.17937136F, 2.22451758F, 2.27251863F,
    2.32393384F, 2.37950087F, 2.44022179F, 2.50751162F, 2.58346581F, 2.67139149F,
    2.77699423F, 2.77699423F, 2.77699423F, 2.77699423F };

  int32_T icng_tmp;
  int32_T jsr_tmp;

  /* S-Function (sdsprandsrc2): '<S132>/Random Source' */
  /* RandSrc_GZ_R */
  for (chan = 0; chan < nChans; chan++) {
    std = xstd[xstdLen > 1 ? chan : 0];
    icng_tmp = chan << 1;
    icng = state[icng_tmp];
    jsr_tmp = icng_tmp + 1;
    jsr = state[jsr_tmp];
    for (samp = 0; samp < nSamps; samp++) {
      icng = 69069U * icng + 1234567U;
      jsr ^= jsr << 13;
      jsr ^= jsr >> 17;
      jsr ^= jsr << 5;
      i = (int32_T)(icng + jsr);
      j = (i & 63) + 1;
      r = (real32_T)i * 4.65661287E-10F * vt[j];
      if (fabsf(r) > vt[j - 1]) {
        x = (fabsf(r) - vt[j - 1]) / (vt[j] - vt[j - 1]);
        icng = 69069U * icng + 1234567U;
        jsr ^= jsr << 13;
        jsr ^= jsr >> 17;
        jsr ^= jsr << 5;
        y_0 = (real32_T)(int32_T)(icng + jsr) * 2.32830644E-10F + 0.5F;
        s = x + y_0;
        if (s > 1.30119801F) {
          r = r < 0.0F ? 0.487899214F * x - 0.487899214F : 0.487899214F -
            0.487899214F * x;
        } else {
          if (s > 0.96892792F) {
            x = 0.487899214F - 0.487899214F * x;
            if (y_0 > 12.6770601F - expf(-0.5F * x * x) * 12.3758602F) {
              r = r < 0.0F ? -x : x;
            } else {
              if (expf(-0.5F * vt[j] * vt[j]) + y_0 * 0.0195830297F / vt[j] >
                  expf(-0.5F * r * r)) {
                do {
                  icng = 69069U * icng + 1234567U;
                  jsr ^= jsr << 13;
                  jsr ^= jsr >> 17;
                  jsr ^= jsr << 5;
                  x = logf((real32_T)(int32_T)(icng + jsr) * 2.32830644E-10F +
                           0.5F) / 2.77699399F;
                  icng = 69069U * icng + 1234567U;
                  jsr ^= jsr << 13;
                  jsr ^= jsr >> 17;
                  jsr ^= jsr << 5;
                } while (logf((real32_T)(int32_T)(icng + jsr) * 2.32830644E-10F
                              + 0.5F) * -2.0F <= x * x);

                r = r < 0.0F ? x - 2.77699399F : 2.77699399F - x;
              }
            }
          }
        }
      }

      y[chan * nSamps + samp] = mean[meanLen > 1 ? chan : 0] + std * r;
    }

    state[icng_tmp] = icng;
    state[jsr_tmp] = jsr;
  }

  /* End of S-Function (sdsprandsrc2): '<S132>/Random Source' */
}

void RandSrcInitState_GZ(const uint32_T seed[], uint32_T state[], int32_T nChans)
{
  int32_T i;
  int32_T tmp;

  /* InitializeConditions for S-Function (sdsprandsrc2): '<S132>/Random Source' */
  /* RandSrcInitState_GZ */
  for (i = 0; i < nChans; i++) {
    tmp = i << 1;
    state[tmp] = 362436069U;
    state[tmp + 1] = seed[i] == 0U ? 521288629U : seed[i];
  }

  /* End of InitializeConditions for S-Function (sdsprandsrc2): '<S132>/Random Source' */
}

void RandSrcInitState_U_32(const uint32_T seed[], real32_T state[], int32_T
  nChans)
{
  int32_T i;
  uint32_T j;
  int32_T k;
  int32_T n;
  real32_T d;

  /* InitializeConditions for S-Function (sdsprandsrc2): '<S141>/Random Source' */
  /* RandSrcInitState_U_32 */
  for (i = 0; i < nChans; i++) {
    j = seed[i] != 0U ? seed[i] : 2147483648U;
    state[35 * i + 34] = (real32_T)j;
    for (k = 0; k < 32; k++) {
      d = 0.0F;
      for (n = 0; n < 24; n++) {
        j ^= j << 13;
        j ^= j >> 17;
        j ^= j << 5;
        d = (real32_T)((int32_T)(j >> 19) & 1) + (d + d);
      }

      state[35 * i + k] = ldexpf(d, -24);
    }

    state[35 * i + 32] = 0.0F;
    state[35 * i + 33] = 0.0F;
  }

  /* End of InitializeConditions for S-Function (sdsprandsrc2): '<S141>/Random Source' */
}

void RandSrc_U_R(real32_T y[], const real32_T minVec[], int32_T minLen, const
                 real32_T maxVec[], int32_T maxLen, real32_T state[], int32_T
                 nChans, int32_T nSamps)
{
  int32_T chan;
  real32_T min;
  real32_T scale;
  int32_T samps;
  real32_T d;
  int32_T i;
  uint32_T j;
  int32_T ii;
  int32_T i_tmp;
  int32_T j_tmp;
  int32_T d_tmp;

  /* InitializeConditions for S-Function (sdsprandsrc2): '<S141>/Random Source' */
  /* RandSrc_U_R */
  for (chan = 0; chan < nChans; chan++) {
    min = minVec[minLen > 1 ? chan : 0];
    scale = maxVec[maxLen > 1 ? chan : 0] - min;
    i_tmp = chan * 35 + 33;
    i = (int32_T)((uint32_T)state[i_tmp] & 31U);
    j_tmp = chan * 35 + 34;
    j = (uint32_T)state[j_tmp];
    for (samps = 0; samps < nSamps; samps++) {
      /* "Subtract with borrow" generator */
      d = state[((i + 20) & 31) + chan * 35];
      d -= state[((i + 5) & 31) + chan * 35];
      d_tmp = chan * 35 + 32;
      d -= state[d_tmp];
      if (d >= 0.0F) {
        state[d_tmp] = 0.0F;
      } else {
        d++;

        /* set 1 in LSB */
        state[d_tmp] = 5.96046448E-8F;
      }

      state[chan * 35 + i] = d;
      i = (i + 1) & 31;

      /* XOR with shift register sequence */
      memcpy(&ii, &d, sizeof(real32_T));
      j ^= j << 13;
      j ^= j >> 17;
      j ^= j << 5;
      ii ^= j & 8388607U;
      memcpy(&d, &ii, sizeof(real32_T));
      y[chan * nSamps + samps] = scale * d + min;
    }

    state[i_tmp] = (real32_T)i;
    state[j_tmp] = (real32_T)j;
  }

  /* End of InitializeConditions for S-Function (sdsprandsrc2): '<S141>/Random Source' */
}

void RandSrcCreateSeeds_32(uint32_T initSeed, uint32_T seedArray[], int32_T
  numSeeds)
{
  real32_T state[35];
  real32_T tmp;
  real32_T min;
  real32_T max;
  int32_T i;

  /* InitializeConditions for S-Function (sdsprandsrc2): '<S141>/Random Source' */
  /* RandSrcCreateSeeds_32 */
  min = 0.0F;
  max = 1.0F;
  RandSrcInitState_U_32(&initSeed, state, 1);
  for (i = 0; i < numSeeds; i++) {
    RandSrc_U_R(&tmp, &min, 1, &max, 1, state, 1, 1);
    seedArray[i] = (uint32_T)(tmp * 2.14748365E+9F);
  }

  /* End of InitializeConditions for S-Function (sdsprandsrc2): '<S141>/Random Source' */
}

/* Model step function */
void Plant_step(void)
{
  real32_T rtb_Va_B[3];
  real32_T rtb_Gain_kz;
  real32_T rtb_Square2_b;
  real32_T rtb_Product8;
  real_T rtb_TrigonometricFunction2;
  real_T rtb_SumofElements;
  real_T rtb_SumofElements1;
  real_T rtb_CYr;
  real_T rtb_Cm;
  real_T rtb_Cl_zA;
  real_T rtb_Cl_yA;
  real_T rtb_Cl_xA;
  real_T rtb_Divide2[3];
  real_T rtb_Sum_nr[6];
  real_T rtb_Sum1[6];
  real32_T rtb_Square_o5[3];
  real32_T rtb_Add_m[3];
  real32_T rtb_VectorConcatenate_f[9];
  real32_T rtb_Sum_po[3];
  real32_T rtb_Divide_g[4];
  real32_T rtb_Sum_kn[3];
  real32_T rtb_MathFunction_m[3];
  real32_T rtb_Gain3;
  boolean_T rtb_Compare_c;
  boolean_T rtb_Compare;
  real32_T rtb_Add_ow;
  real32_T rtb_MathFunction1_k;
  real32_T rtb_MatrixConcatenate4[16];
  real32_T rtb_Sum_c[3];
  boolean_T rtb_FixPtRelationalOperator_k;
  real32_T rtb_MatrixConcatenate1[9];
  real32_T rtb_Sum_b0;
  AirSpeed_Bus rtb_BusAssignment_f;
  Barometer_Bus rtb_BusAssignment_c;
  GPS_uBlox_Bus rtb_BusAssignment_e;
  real32_T rtb_VectorConcatenate_j[3];
  real32_T rtb_VectorConcatenate_m1[9];
  real32_T rtb_magnitude_gauss;
  MAG_Bus rtb_BusAssignment_j;
  real32_T rtb_RandomSource[3];
  real32_T rtb_Sum1_a[3];
  real32_T rtb_Square_b[3];
  real32_T rtb_RandomSource1[3];
  real_T rtb_DataTypeConversion2[2];
  int32_T i;
  real_T tmp[6];
  real_T tmp_0[6];
  real_T rtb_CD_0[6];
  real32_T tmp_1[3];
  real32_T rtb_Square_l;
  real32_T rtb_Switch_idx_3;
  real32_T rtb_Switch_idx_2;
  real32_T rtb_Switch_idx_1;
  real32_T rtb_Switch_idx_0;
  real_T rtb_Divide_e_idx_1;
  real32_T rtb_Square_idx_2;
  real32_T rtb_Sum1_dw_idx_2;
  real32_T rtb_Sum1_dw_idx_0;
  real32_T rtb_Sum_ah_idx_2;
  real32_T rtb_Multiply4_k_idx_1;
  real32_T rtb_Multiply4_k_idx_0;
  int32_T rtb_Saturation1_m_idx_1;
  uint16_T tmp_2;
  real32_T rtb_Gain_e_tmp;
  real32_T rtb_Divide_h_idx_0;
  real32_T rtb_Divide_h_idx_1;
  real32_T rtb_Divide_h_idx_2;
  real32_T rtb_Divide_h_idx_3;
  real32_T rtb_Gain_e_tmp_0;
  real32_T rtb_Gain_e_tmp_1;
  real32_T rtb_Gain_e_tmp_2;
  real32_T rtb_Gain_e_tmp_3;
  real32_T rtb_Gain_e_tmp_4;
  real32_T rtb_Gain_e_tmp_5;
  real32_T rtb_Gain_e_tmp_6;
  real32_T rtb_Sum_l_tmp;

  /* Delay: '<Root>/Delay' */
  rtb_magnitude_gauss = Plant_Y.Plant_States.vel_x_O;
  rtb_Add_ow = Plant_Y.Plant_States.vel_y_O;
  rtb_MathFunction1_k = Plant_Y.Plant_States.vel_z_O;
  for (i = 0; i < 9; i++) {
    rtb_VectorConcatenate_m1[i] = Plant_Y.Extended_States.M_BO[i];
  }

  /* Outputs for Atomic SubSystem: '<Root>/Actuators' */
  for (i = 0; i < 3; i++) {
    /* Product: '<S9>/Multiply' */
    rtb_Sum1_dw_idx_0 = rtb_VectorConcatenate_m1[i + 6] * rtb_MathFunction1_k +
      (rtb_VectorConcatenate_m1[i + 3] * rtb_Add_ow + rtb_VectorConcatenate_m1[i]
       * rtb_magnitude_gauss);

    /* Math: '<S41>/Square' */
    rtb_Square_b[i] = rtb_Sum1_dw_idx_0 * rtb_Sum1_dw_idx_0;

    /* Product: '<S9>/Multiply' */
    rtb_Va_B[i] = rtb_Sum1_dw_idx_0;
  }

  /* Product: '<S40>/Divide' incorporates:
   *  Saturate: '<S40>/Saturation'
   *  Sqrt: '<S41>/Sqrt'
   *  Sum: '<S41>/Sum of Elements'
   */
  rtb_Square2_b = rtb_Va_B[1] / fmaxf(sqrtf((rtb_Square_b[0] + rtb_Square_b[1])
    + rtb_Square_b[2]), 0.1F);

  /* DataTypeConversion: '<S7>/Data Type Conversion2' incorporates:
   *  Product: '<S39>/Divide'
   *  Saturate: '<S39>/Saturation'
   *  Trigonometry: '<S39>/Atan'
   */
  rtb_DataTypeConversion2[0] = atanf(rtb_Va_B[2] / fmaxf(rtb_Va_B[0], 0.1F));

  /* Trigonometry: '<S40>/Asin' */
  if (rtb_Square2_b > 1.0F) {
    rtb_Square2_b = 1.0F;
  } else {
    if (rtb_Square2_b < -1.0F) {
      rtb_Square2_b = -1.0F;
    }
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion2' incorporates:
   *  Trigonometry: '<S40>/Asin'
   */
  rtb_DataTypeConversion2[1] = asinf(rtb_Square2_b);

  /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
   *  Bias: '<S17>/Bias'
   *  DataTypeConversion: '<S17>/Data Type Conversion'
   *  Gain: '<S17>/Gain2'
   *  Inport: '<Root>/Control_Out'
   */
  rtb_Divide_e_idx_1 = ((real32_T)Plant_U.Control_Out.actuator_cmd[4] + -1500.0F)
    * 0.0010471975F;

  /* Gain: '<S23>/Gain2' incorporates:
   *  Bias: '<S16>/Bias'
   *  DataTypeConversion: '<S16>/Data Type Conversion'
   *  DataTypeConversion: '<S7>/Data Type Conversion'
   *  Gain: '<S16>/Gain2'
   *  Inport: '<Root>/Control_Out'
   */
  rtb_TrigonometricFunction2 = -(real_T)(((real32_T)
    Plant_U.Control_Out.actuator_cmd[2] + -1500.0F) * 0.0010471975F);

  /* Lookup2D: '<S23>/CD' */
  rtb_SumofElements = rt_Lookup2D_Normal(Plant_ConstP.pooled5, 7,
    Plant_ConstP.pooled6, 6, Plant_ConstP.CD_Table, rtb_TrigonometricFunction2,
    rtb_DataTypeConversion2[0]);

  /* Lookup2D: '<S23>/CY' */
  /*
   * About '<S23>/CY':
   * Input0  Data Type:  Floating Point real_T
   * Input1  Data Type:  Floating Point real_T
   * Output0 Data Type:  Floating Point real_T
   * Lookup Method: Linear_Endpoint
   *
   * Row Data    parameter uses the same data type and scaling as Input0
   * Column Data parameter uses the same data type and scaling as Input1
   * Table Data  parameter uses the same data type and scaling as Output0
   */
  Look2D_real_T_real_T_real_T( &(rtb_SumofElements1), Plant_ConstP.CY_Table,
    rtb_TrigonometricFunction2, Plant_ConstP.pooled5, 6U,
    rtb_DataTypeConversion2[0], Plant_ConstP.pooled6, 5U);

  /* Sum: '<S19>/Sum1' incorporates:
   *  Lookup2D: '<S23>/Cl'
   */
  rtb_Sum1[3] = rt_Lookup2D_Normal(Plant_ConstP.pooled5, 7, Plant_ConstP.pooled6,
    6, Plant_ConstP.Cl_Table, rtb_TrigonometricFunction2,
    rtb_DataTypeConversion2[0]);

  /* Lookup2D: '<S23>/Cn' */
  rtb_TrigonometricFunction2 = rt_Lookup2D_Normal(Plant_ConstP.pooled5, 7,
    Plant_ConstP.pooled6, 6, Plant_ConstP.Cn_Table, rtb_TrigonometricFunction2,
    rtb_DataTypeConversion2[0]);

  /* Lookup2D: '<S24>/CD' incorporates:
   *  Gain: '<S24>/Gain1'
   */
  rtb_Cm = rt_Lookup2D_Normal(Plant_ConstP.pooled5, 7, Plant_ConstP.pooled6, 6,
    Plant_ConstP.CD_Table_e, -rtb_Divide_e_idx_1, rtb_DataTypeConversion2[0]);

  /* Sum: '<S19>/Sum1' incorporates:
   *  Gain: '<S24>/Gain1'
   *  Lookup2D: '<S24>/CL'
   */
  rtb_Sum1[1] = rt_Lookup2D_Normal(Plant_ConstP.pooled5, 7, Plant_ConstP.pooled6,
    6, Plant_ConstP.CL_Table, -rtb_Divide_e_idx_1, rtb_DataTypeConversion2[0]);

  /* Lookup2D: '<S24>/Cm' incorporates:
   *  Gain: '<S24>/Gain1'
   */
  rtb_CYr = rt_Lookup2D_Normal(Plant_ConstP.pooled5, 7, Plant_ConstP.pooled6, 6,
    Plant_ConstP.Cm_Table, -rtb_Divide_e_idx_1, rtb_DataTypeConversion2[0]);

  /* Gain: '<S25>/Gain' incorporates:
   *  Bias: '<S18>/Bias'
   *  DataTypeConversion: '<S18>/Data Type Conversion'
   *  DataTypeConversion: '<S7>/Data Type Conversion'
   *  Gain: '<S18>/Gain2'
   *  Inport: '<Root>/Control_Out'
   */
  rtb_Divide_e_idx_1 = -(real_T)(((real32_T)Plant_U.Control_Out.actuator_cmd[5]
    + -1500.0F) * 0.0010471975F);

  /* Lookup2D: '<S25>/CD_dr' */
  rtb_Cl_zA = rt_Lookup2D_Normal(Plant_ConstP.pooled8, 9, Plant_ConstP.pooled6,
    6, Plant_ConstP.CD_dr_Table, rtb_Divide_e_idx_1, rtb_DataTypeConversion2[0]);

  /* Lookup2D: '<S25>/CY_dr' */
  rtb_Cl_yA = rt_Lookup2D_Normal(Plant_ConstP.pooled8, 9, Plant_ConstP.pooled6,
    6, Plant_ConstP.CY_dr_Table, rtb_Divide_e_idx_1, rtb_DataTypeConversion2[0]);

  /* Lookup2D: '<S25>/Cm_dr' */
  /*
   * About '<S25>/Cm_dr':
   * Input0  Data Type:  Floating Point real_T
   * Input1  Data Type:  Floating Point real_T
   * Output0 Data Type:  Floating Point real_T
   * Lookup Method: Linear_Endpoint
   *
   * Row Data    parameter uses the same data type and scaling as Input0
   * Column Data parameter uses the same data type and scaling as Input1
   * Table Data  parameter uses the same data type and scaling as Output0
   */
  Look2D_real_T_real_T_real_T( &(rtb_Cl_xA), Plant_ConstP.Cm_dr_Table,
    rtb_Divide_e_idx_1, Plant_ConstP.pooled8, 8U, rtb_Divide_e_idx_1,
    Plant_ConstP.pooled6, 5U);

  /* Lookup2D: '<S25>/Cn_dr' */
  rtb_Divide_e_idx_1 = rt_Lookup2D_Normal(Plant_ConstP.pooled8, 9,
    Plant_ConstP.pooled6, 6, Plant_ConstP.Cn_dr_Table, rtb_Divide_e_idx_1,
    rtb_DataTypeConversion2[0]);

  /* Sum: '<S19>/Sum1' */
  rtb_Sum1[0] = (rtb_SumofElements + rtb_Cm) + rtb_Cl_zA;
  rtb_Sum1[2] = rtb_SumofElements1 + rtb_Cl_yA;
  rtb_Sum1[4] = rtb_CYr + rtb_Cl_xA;
  rtb_Sum1[5] = rtb_TrigonometricFunction2 + rtb_Divide_e_idx_1;

  /* Lookup2D: '<S20>/CY_basic' */
  rtb_Cl_xA = rt_Lookup2D_Normal(Plant_ConstP.pooled9, 7, Plant_ConstP.pooled6,
    6, Plant_ConstP.CY_basic_Table, rtb_DataTypeConversion2[1],
    rtb_DataTypeConversion2[0]);

  /* Lookup2D: '<S20>/Cn_basic' */
  /*
   * About '<S20>/Cn_basic':
   * Input0  Data Type:  Floating Point real_T
   * Input1  Data Type:  Floating Point real_T
   * Output0 Data Type:  Floating Point real_T
   * Lookup Method: Linear_Endpoint
   *
   * Row Data    parameter uses the same data type and scaling as Input0
   * Column Data parameter uses the same data type and scaling as Input1
   * Table Data  parameter uses the same data type and scaling as Output0
   */
  Look2D_real_T_real_T_real_T( &(rtb_Cl_zA), Plant_ConstP.Cn_basic_Table,
    rtb_DataTypeConversion2[1], Plant_ConstP.pooled9, 6U,
    rtb_DataTypeConversion2[0], Plant_ConstP.pooled6, 5U);

  /* Lookup: '<S20>/CL_basic' */
  rtb_Divide_e_idx_1 = rt_Lookup(Plant_ConstP.pooled10, 23,
    rtb_DataTypeConversion2[0], Plant_ConstP.CL_basic_YData);

  /* Sum: '<S20>/Sum' incorporates:
   *  Lookup2D: '<S20>/CL_beta'
   */
  rtb_Divide_e_idx_1 += rt_Lookup2D_Normal(Plant_ConstP.pooled9, 7,
    Plant_ConstP.pooled6, 6, Plant_ConstP.CL_beta_Table,
    rtb_DataTypeConversion2[1], rtb_DataTypeConversion2[0]);

  /* Sum: '<S20>/Sum1' incorporates:
   *  Lookup: '<S20>/CD_basic'
   *  Lookup2D: '<S20>/CD_beta'
   */
  rtb_CYr = rt_Lookup(Plant_ConstP.pooled10, 23, rtb_DataTypeConversion2[0],
                      Plant_ConstP.CD_basic_YData) + rt_Lookup2D_Normal
    (Plant_ConstP.pooled9, 7, Plant_ConstP.pooled6, 6,
     Plant_ConstP.CD_beta_Table, rtb_DataTypeConversion2[1],
     rtb_DataTypeConversion2[0]);

  /* Sum: '<S20>/Sum2' incorporates:
   *  Lookup: '<S20>/Cm_basic'
   *  Lookup2D: '<S20>/Cm_beta'
   */
  rtb_Cm = rt_Lookup(Plant_ConstP.pooled10, 23, rtb_DataTypeConversion2[0],
                     Plant_ConstP.Cm_basic_YData) + rt_Lookup2D_Normal
    (Plant_ConstP.pooled9, 7, Plant_ConstP.pooled6, 6,
     Plant_ConstP.Cm_beta_Table, rtb_DataTypeConversion2[1],
     rtb_DataTypeConversion2[0]);

  /* Lookup: '<S26>/Cnp' */
  rtb_TrigonometricFunction2 = rt_Lookup(Plant_ConstP.pooled11, 5,
    rtb_DataTypeConversion2[0], Plant_ConstP.Cnp_YData);

  /* Saturate: '<S15>/Saturation' incorporates:
   *  Gain: '<S15>/Gain'
   */
  rtb_Gain_kz = fmaxf(2.0F * rtb_Va_B[0], 0.1F);

  /* Product: '<S15>/Product1' incorporates:
   *  Constant: '<S15>/b'
   *  Delay: '<Root>/Delay'
   *  Product: '<S15>/Product2'
   */
  rtb_Sum1_dw_idx_0 = 1.0F / rtb_Gain_kz * 2.3F;
  rtb_Square2_b = rtb_Sum1_dw_idx_0 * Plant_Y.Plant_States.rot_x_B;

  /* Product: '<S15>/Product4' incorporates:
   *  Constant: '<S15>/c'
   *  Delay: '<Root>/Delay'
   */
  rtb_Product8 = 1.0F / rtb_Gain_kz * 0.32F * Plant_Y.Plant_States.rot_y_B;

  /* Product: '<S15>/Product2' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_Gain_kz = rtb_Sum1_dw_idx_0 * Plant_Y.Plant_States.rot_z_B;

  /* Lookup: '<S26>/CYp' */
  rtb_SumofElements = rt_Lookup(Plant_ConstP.pooled11, 5,
    rtb_DataTypeConversion2[0], Plant_ConstP.CYp_YData);

  /* Lookup: '<S26>/Clp' */
  rtb_SumofElements1 = rt_Lookup(Plant_ConstP.pooled11, 5,
    rtb_DataTypeConversion2[0], Plant_ConstP.Clp_YData);

  /* Product: '<S22>/p1' incorporates:
   *  Constant: '<S26>/CDp'
   *  Constant: '<S26>/CLp'
   *  Constant: '<S26>/Cmp'
   *  DataTypeConversion: '<S7>/Data Type Conversion1'
   *  Lookup: '<S26>/CYp'
   *  Lookup: '<S26>/Clp'
   */
  rtb_Sum_nr[0] = 0.0;
  rtb_Sum_nr[1] = 0.0;
  rtb_Sum_nr[2] = rtb_SumofElements * rtb_Square2_b;
  rtb_Sum_nr[3] = rtb_SumofElements1 * rtb_Square2_b;
  rtb_Sum_nr[4] = 0.0;
  rtb_Sum_nr[5] = rtb_TrigonometricFunction2 * rtb_Square2_b;

  /* Lookup: '<S28>/Cnr' */
  rtb_TrigonometricFunction2 = rt_Lookup(Plant_ConstP.pooled11, 5,
    rtb_DataTypeConversion2[0], Plant_ConstP.Cnr_YData);

  /* Lookup: '<S27>/CLq' */
  rtb_SumofElements = rt_Lookup(Plant_ConstP.pooled11, 5,
    rtb_DataTypeConversion2[0], Plant_ConstP.CLq_YData);

  /* Lookup: '<S27>/Cmq' */
  rtb_SumofElements1 = rt_Lookup(Plant_ConstP.pooled11, 5,
    rtb_DataTypeConversion2[0], Plant_ConstP.Cmq_YData);

  /* Product: '<S22>/q1' incorporates:
   *  Constant: '<S27>/CDq'
   *  Constant: '<S27>/CYq'
   *  Constant: '<S27>/Clq'
   *  Constant: '<S27>/Cnq'
   *  DataTypeConversion: '<S7>/Data Type Conversion1'
   *  Lookup: '<S27>/CLq'
   *  Lookup: '<S27>/Cmq'
   */
  tmp[0] = 0.0;
  tmp[1] = rtb_SumofElements * rtb_Product8;
  tmp[2] = 0.0;
  tmp[3] = 0.0;
  tmp[4] = rtb_SumofElements1 * rtb_Product8;
  tmp[5] = 0.0;

  /* Lookup: '<S28>/CYr' */
  rtb_SumofElements = rt_Lookup(Plant_ConstP.pooled11, 5,
    rtb_DataTypeConversion2[0], Plant_ConstP.CYr_YData);

  /* Lookup: '<S28>/Clr' */
  rtb_SumofElements1 = rt_Lookup(Plant_ConstP.pooled11, 5,
    rtb_DataTypeConversion2[0], Plant_ConstP.Clr_YData);

  /* Product: '<S22>/r1' incorporates:
   *  Constant: '<S28>/CDr'
   *  Constant: '<S28>/CLr'
   *  Constant: '<S28>/Cmr'
   *  DataTypeConversion: '<S7>/Data Type Conversion1'
   *  Lookup: '<S28>/CYr'
   *  Lookup: '<S28>/Clr'
   */
  tmp_0[0] = 0.0;
  tmp_0[1] = 0.0;
  tmp_0[2] = rtb_SumofElements * rtb_Gain_kz;
  tmp_0[3] = rtb_SumofElements1 * rtb_Gain_kz;
  tmp_0[4] = 0.0;
  tmp_0[5] = rtb_TrigonometricFunction2 * rtb_Gain_kz;

  /* Lookup2D: '<S20>/Cl_basic' */
  rtb_SumofElements = rt_Lookup2D_Normal(Plant_ConstP.pooled9, 7,
    Plant_ConstP.pooled6, 6, Plant_ConstP.Cl_basic_Table,
    rtb_DataTypeConversion2[1], rtb_DataTypeConversion2[0]);

  /* Sum: '<S12>/Sum' incorporates:
   *  Lookup2D: '<S20>/Cl_basic'
   */
  rtb_CD_0[0] = rtb_CYr;
  rtb_CD_0[1] = rtb_Divide_e_idx_1;
  rtb_CD_0[2] = rtb_Cl_xA;
  rtb_CD_0[3] = rtb_SumofElements;
  rtb_CD_0[4] = rtb_Cm;
  rtb_CD_0[5] = rtb_Cl_zA;
  for (i = 0; i < 6; i++) {
    /* Sum: '<S22>/Add' incorporates:
     *  Sum: '<S12>/Sum'
     */
    rtb_Sum_nr[i] = (((rtb_Sum_nr[i] + tmp[i]) + tmp_0[i]) + rtb_CD_0[i]) +
      rtb_Sum1[i];
  }

  /* Fcn: '<S21>/Cl_xA' incorporates:
   *  Fcn: '<S21>/Cl_zA'
   */
  rtb_SumofElements1 = -rtb_Sum_nr[0] * cos(rtb_DataTypeConversion2[1]);
  rtb_SumofElements = sin(rtb_DataTypeConversion2[0]);
  rtb_TrigonometricFunction2 = cos(rtb_DataTypeConversion2[0]);
  rtb_Cl_xA = rtb_SumofElements1 * rtb_TrigonometricFunction2 + rtb_Sum_nr[1] *
    rtb_SumofElements;

  /* Fcn: '<S21>/Cl_zA' */
  rtb_Cl_zA = rtb_SumofElements1 * rtb_SumofElements - rtb_Sum_nr[1] *
    rtb_TrigonometricFunction2;

  /* Gain: '<S13>/reference area' incorporates:
   *  Gain: '<S14>/Gain'
   *  Math: '<S14>/Square'
   */
  rtb_Gain_kz = rtb_Va_B[0] * rtb_Va_B[0] * 0.645F * 0.736F;

  /* Product: '<S13>/Product' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion4'
   *  Fcn: '<S21>/Cl_yA'
   */
  rtb_Square_o5[0] = rtb_Gain_kz * (real32_T)rtb_Cl_xA;
  rtb_Square_o5[1] = (real32_T)(-rtb_Sum_nr[0] * sin(rtb_DataTypeConversion2[1])
    + rtb_Sum_nr[2]) * rtb_Gain_kz;
  rtb_Square_o5[2] = rtb_Gain_kz * (real32_T)rtb_Cl_zA;

  /* Sum: '<S1>/Sum1' incorporates:
   *  Constant: '<S38>/cT'
   *  DiscreteIntegrator: '<S35>/Discrete-Time Integrator'
   *  Math: '<S38>/Square'
   *  Product: '<S38>/Multiply'
   *  Sum: '<S34>/Sum of Elements'
   */
  rtb_Sum1_a[0] = ((real32_T)(Plant_DW.DiscreteTimeIntegrator_DSTATE_p[0] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_p[0] * 2.478E-5) + (real32_T)
                   (Plant_DW.DiscreteTimeIntegrator_DSTATE_p[1] *
                    Plant_DW.DiscreteTimeIntegrator_DSTATE_p[1] * 2.478E-5)) +
    rtb_Square_o5[0];
  rtb_Sum1_a[1] = rtb_Square_o5[1];
  rtb_Sum1_a[2] = rtb_Square_o5[2];

  /* Sum: '<S13>/Sum1' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion4'
   *  Gain: '<S13>/reference length'
   *  Product: '<S13>/Product3'
   *  Product: '<S31>/Multiply'
   *  Product: '<S31>/Multiply1'
   *  Product: '<S31>/Multiply2'
   *  Product: '<S32>/Multiply3'
   *  Product: '<S32>/Multiply4'
   *  Product: '<S32>/Multiply5'
   *  Sum: '<S30>/Sum'
   */
  rtb_Sum1_dw_idx_0 = (rtb_Square_o5[1] * Plant_ConstB.Sum_k[2] - rtb_Square_o5
                       [2] * Plant_ConstB.Sum_k[1]) + 2.3F * rtb_Gain_kz *
    (real32_T)rtb_Sum_nr[3];
  rtb_Product8 = (rtb_Square_o5[2] * Plant_ConstB.Sum_k[0] - rtb_Square_o5[0] *
                  Plant_ConstB.Sum_k[2]) + 0.32F * rtb_Gain_kz * (real32_T)
    rtb_Sum_nr[4];
  rtb_Sum1_dw_idx_2 = (rtb_Square_o5[0] * Plant_ConstB.Sum_k[1] - rtb_Square_o5
                       [1] * Plant_ConstB.Sum_k[0]) + 2.3F * rtb_Gain_kz *
    (real32_T)rtb_Sum_nr[5];

  /* Saturate: '<S33>/Saturation' incorporates:
   *  Inport: '<Root>/Control_Out'
   */
  if (Plant_U.Control_Out.actuator_cmd[0] > 2000) {
    tmp_2 = 2000U;
  } else if (Plant_U.Control_Out.actuator_cmd[0] < 1000) {
    tmp_2 = 1000U;
  } else {
    tmp_2 = Plant_U.Control_Out.actuator_cmd[0];
  }

  /* Gain: '<S33>/Gain' incorporates:
   *  Sum: '<S33>/Subtract'
   */
  rtb_Gain3 = ((real32_T)tmp_2 - 1000.0F) * 0.000999987125F;

  /* RelationalOperator: '<S37>/Compare' incorporates:
   *  Constant: '<S37>/Constant'
   */
  rtb_Compare_c = (rtb_Gain3 > 0.1F);

  /* Sum: '<S36>/Add' incorporates:
   *  Constant: '<S36>/Constant1'
   *  Gain: '<S36>/Gain1'
   */
  rtb_Gain3 = 718.078F * rtb_Gain3 + 88.448F;

  /* Update for DiscreteIntegrator: '<S35>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S35>/Gain'
   *  Product: '<S36>/Multiply'
   *  Saturate: '<S36>/Saturation1'
   *  Sum: '<S35>/Subtract'
   */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_p[0] += ((rtb_Compare_c ? rtb_Gain3 :
    0.0F) - Plant_DW.DiscreteTimeIntegrator_DSTATE_p[0]) * 50.0F * 0.002F;

  /* Saturate: '<S33>/Saturation' incorporates:
   *  Inport: '<Root>/Control_Out'
   */
  if (Plant_U.Control_Out.actuator_cmd[1] > 2000) {
    tmp_2 = 2000U;
  } else if (Plant_U.Control_Out.actuator_cmd[1] < 1000) {
    tmp_2 = 1000U;
  } else {
    tmp_2 = Plant_U.Control_Out.actuator_cmd[1];
  }

  /* Gain: '<S33>/Gain' incorporates:
   *  Sum: '<S33>/Subtract'
   */
  rtb_Gain3 = ((real32_T)tmp_2 - 1000.0F) * 0.000999987125F;

  /* RelationalOperator: '<S37>/Compare' incorporates:
   *  Constant: '<S37>/Constant'
   */
  rtb_Compare_c = (rtb_Gain3 > 0.1F);

  /* Sum: '<S36>/Add' incorporates:
   *  Constant: '<S36>/Constant1'
   *  Gain: '<S36>/Gain1'
   */
  rtb_Gain3 = 718.078F * rtb_Gain3 + 88.448F;

  /* Update for DiscreteIntegrator: '<S35>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S35>/Gain'
   *  Product: '<S36>/Multiply'
   *  Saturate: '<S36>/Saturation1'
   *  Sum: '<S35>/Subtract'
   */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_p[1] += ((rtb_Compare_c ? rtb_Gain3 :
    0.0F) - Plant_DW.DiscreteTimeIntegrator_DSTATE_p[1]) * 50.0F * 0.002F;

  /* End of Outputs for SubSystem: '<Root>/Actuators' */

  /* Outputs for Atomic SubSystem: '<Root>/Environment' */
  /* Trigonometry: '<S63>/Trigonometric Function1' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S62>/Gain'
   *  Trigonometry: '<S63>/Trigonometric Function3'
   */
  rtb_Gain3 = arm_cos_f32(-Plant_Y.Plant_States.psi);
  rtb_VectorConcatenate_f[0] = rtb_Gain3;

  /* Trigonometry: '<S63>/Trigonometric Function' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S62>/Gain'
   *  Trigonometry: '<S63>/Trigonometric Function2'
   */
  rtb_Square_idx_2 = arm_sin_f32(-Plant_Y.Plant_States.psi);
  rtb_VectorConcatenate_f[1] = rtb_Square_idx_2;

  /* SignalConversion: '<S63>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S63>/Constant3'
   */
  rtb_VectorConcatenate_f[2] = 0.0F;

  /* Gain: '<S63>/Gain' */
  rtb_VectorConcatenate_f[3] = -rtb_Square_idx_2;

  /* Trigonometry: '<S63>/Trigonometric Function3' */
  rtb_VectorConcatenate_f[4] = rtb_Gain3;

  /* SignalConversion: '<S63>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S63>/Constant4'
   */
  rtb_VectorConcatenate_f[5] = 0.0F;

  /* SignalConversion: '<S63>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_f[6] = Plant_ConstB.VectorConcatenate3_h[0];

  /* Sum: '<S53>/Sum' incorporates:
   *  Inport: '<Root>/Environment_Info'
   */
  rtb_Square_idx_2 = Plant_U.Environment_Info.hit_point[0] -
    Plant_U.Environment_Info.hit_location[0];

  /* SignalConversion: '<S63>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_f[7] = Plant_ConstB.VectorConcatenate3_h[1];

  /* Sum: '<S53>/Sum' incorporates:
   *  Inport: '<Root>/Environment_Info'
   */
  rtb_Multiply4_k_idx_1 = Plant_U.Environment_Info.hit_point[1] -
    Plant_U.Environment_Info.hit_location[1];

  /* SignalConversion: '<S63>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_f[8] = Plant_ConstB.VectorConcatenate3_h[2];

  /* Sum: '<S53>/Sum' incorporates:
   *  Inport: '<Root>/Environment_Info'
   */
  rtb_Multiply4_k_idx_0 = Plant_U.Environment_Info.hit_point[2] -
    Plant_U.Environment_Info.hit_location[2];
  for (i = 0; i < 3; i++) {
    /* Product: '<S53>/Multiply2' */
    rtb_Gain3 = rtb_VectorConcatenate_m1[i + 6] * rtb_Multiply4_k_idx_0 +
      (rtb_VectorConcatenate_m1[i + 3] * rtb_Multiply4_k_idx_1 +
       rtb_VectorConcatenate_m1[i] * rtb_Square_idx_2);

    /* Math: '<S68>/Math Function' */
    rtb_Add_m[i] = rtb_Gain3 * rtb_Gain3;

    /* Product: '<S53>/Multiply2' */
    rtb_Square_b[i] = rtb_Gain3;
  }

  /* Sum: '<S68>/Sum of Elements' */
  rtb_Switch_idx_3 = (rtb_Add_m[0] + rtb_Add_m[1]) + rtb_Add_m[2];

  /* Math: '<S68>/Math Function1' incorporates:
   *  Sum: '<S68>/Sum of Elements'
   *
   * About '<S68>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Switch_idx_3 < 0.0F) {
    rtb_Gain_kz = -sqrtf(fabsf(rtb_Switch_idx_3));
  } else {
    rtb_Gain_kz = sqrtf(rtb_Switch_idx_3);
  }

  /* End of Math: '<S68>/Math Function1' */

  /* Switch: '<S68>/Switch' incorporates:
   *  Constant: '<S68>/Constant'
   *  Product: '<S68>/Product'
   */
  if (rtb_Gain_kz > 0.0F) {
    rtb_Divide_g[0] = rtb_Square_b[0];
    rtb_Divide_g[1] = rtb_Square_b[1];
    rtb_Divide_g[2] = rtb_Square_b[2];
    rtb_Divide_g[3] = rtb_Gain_kz;
  } else {
    rtb_Divide_g[0] = 0.0F;
    rtb_Divide_g[1] = 0.0F;
    rtb_Divide_g[2] = 0.0F;
    rtb_Divide_g[3] = 1.0F;
  }

  /* End of Switch: '<S68>/Switch' */
  for (i = 0; i < 3; i++) {
    /* Product: '<S68>/Divide' */
    rtb_Add_m[i] = rtb_Divide_g[i] / rtb_Divide_g[3];

    /* Product: '<S53>/Multiply1' */
    rtb_Sum_po[i] = rtb_VectorConcatenate_m1[i + 6] * rtb_MathFunction1_k +
      (rtb_VectorConcatenate_m1[i + 3] * rtb_Add_ow + rtb_VectorConcatenate_m1[i]
       * rtb_magnitude_gauss);
  }

  /* Product: '<S74>/Multiply' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_Square_b[0] = Plant_Y.Plant_States.rot_y_B * rtb_Add_m[2];

  /* Product: '<S74>/Multiply1' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_Square_b[1] = Plant_Y.Plant_States.rot_z_B * rtb_Add_m[0];

  /* Product: '<S74>/Multiply2' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_Square_b[2] = Plant_Y.Plant_States.rot_x_B * rtb_Add_m[1];

  /* Product: '<S75>/Multiply3' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_VectorConcatenate_j[0] = Plant_Y.Plant_States.rot_z_B * rtb_Add_m[1];

  /* Product: '<S75>/Multiply4' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_VectorConcatenate_j[1] = Plant_Y.Plant_States.rot_x_B * rtb_Add_m[2];

  /* Product: '<S75>/Multiply5' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_VectorConcatenate_j[2] = Plant_Y.Plant_States.rot_y_B * rtb_Add_m[0];

  /* DotProduct: '<S66>/Dot Product' */
  rtb_Gain3 = 0.0F;
  for (i = 0; i < 3; i++) {
    /* Sum: '<S67>/Sum1' incorporates:
     *  Sum: '<S71>/Sum'
     */
    rtb_Multiply4_k_idx_1 = (rtb_Square_b[i] - rtb_VectorConcatenate_j[i]) +
      rtb_Sum_po[i];

    /* Product: '<S53>/Multiply' incorporates:
     *  Inport: '<Root>/Environment_Info'
     */
    rtb_Square_idx_2 = rtb_VectorConcatenate_m1[i + 6] *
      Plant_U.Environment_Info.hit_normal[2] + (rtb_VectorConcatenate_m1[i + 3] *
      Plant_U.Environment_Info.hit_normal[1] + rtb_VectorConcatenate_m1[i] *
      Plant_U.Environment_Info.hit_normal[0]);

    /* DotProduct: '<S66>/Dot Product' */
    rtb_Gain3 += rtb_Multiply4_k_idx_1 * rtb_Square_idx_2;

    /* Sum: '<S67>/Sum1' */
    rtb_Square_b[i] = rtb_Multiply4_k_idx_1;

    /* Product: '<S53>/Multiply' incorporates:
     *  Product: '<S59>/Multiply'
     */
    rtb_VectorConcatenate_j[i] = rtb_Square_idx_2;
  }

  /* Sum: '<S66>/Sum' incorporates:
   *  DotProduct: '<S66>/Dot Product'
   *  Product: '<S53>/Multiply'
   *  Product: '<S66>/Multiply'
   */
  rtb_Switch_idx_2 = rtb_Square_b[0] - rtb_Gain3 * rtb_VectorConcatenate_j[0];

  /* Math: '<S70>/Math Function' */
  rtb_MathFunction_m[0] = rtb_Switch_idx_2 * rtb_Switch_idx_2;

  /* Sum: '<S66>/Sum' incorporates:
   *  DotProduct: '<S66>/Dot Product'
   *  Product: '<S53>/Multiply'
   *  Product: '<S66>/Multiply'
   */
  rtb_Sum_kn[0] = rtb_Switch_idx_2;
  rtb_Switch_idx_2 = rtb_Square_b[1] - rtb_Gain3 * rtb_VectorConcatenate_j[1];

  /* Math: '<S70>/Math Function' */
  rtb_MathFunction_m[1] = rtb_Switch_idx_2 * rtb_Switch_idx_2;

  /* Sum: '<S66>/Sum' incorporates:
   *  DotProduct: '<S66>/Dot Product'
   *  Product: '<S53>/Multiply'
   *  Product: '<S66>/Multiply'
   */
  rtb_Sum_kn[1] = rtb_Switch_idx_2;
  rtb_Switch_idx_2 = rtb_Square_b[2] - rtb_Gain3 * rtb_VectorConcatenate_j[2];

  /* Sum: '<S70>/Sum of Elements' incorporates:
   *  Math: '<S70>/Math Function'
   */
  rtb_Switch_idx_3 = (rtb_MathFunction_m[0] + rtb_MathFunction_m[1]) +
    rtb_Switch_idx_2 * rtb_Switch_idx_2;

  /* Math: '<S70>/Math Function1' incorporates:
   *  Sum: '<S70>/Sum of Elements'
   *
   * About '<S70>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Switch_idx_3 < 0.0F) {
    rtb_Gain_kz = -sqrtf(fabsf(rtb_Switch_idx_3));
  } else {
    rtb_Gain_kz = sqrtf(rtb_Switch_idx_3);
  }

  /* End of Math: '<S70>/Math Function1' */

  /* Switch: '<S70>/Switch' incorporates:
   *  Constant: '<S70>/Constant'
   *  Product: '<S70>/Product'
   */
  if (rtb_Gain_kz > 0.0F) {
    rtb_Switch_idx_0 = rtb_Sum_kn[0];
    rtb_Switch_idx_1 = rtb_Sum_kn[1];
    rtb_Switch_idx_3 = rtb_Gain_kz;
  } else {
    rtb_Switch_idx_0 = 0.0F;
    rtb_Switch_idx_1 = 0.0F;
    rtb_Switch_idx_2 = 0.0F;
    rtb_Switch_idx_3 = 1.0F;
  }

  /* End of Switch: '<S70>/Switch' */

  /* Sqrt: '<S69>/Sqrt' incorporates:
   *  Math: '<S69>/Square'
   *  Product: '<S53>/Multiply'
   *  Sum: '<S69>/Sum of Elements'
   */
  rtb_Gain_kz = sqrtf((rtb_VectorConcatenate_j[0] * rtb_VectorConcatenate_j[0] +
                       rtb_VectorConcatenate_j[1] * rtb_VectorConcatenate_j[1])
                      + rtb_VectorConcatenate_j[2] * rtb_VectorConcatenate_j[2]);

  /* Product: '<S66>/Multiply3' incorporates:
   *  Product: '<S70>/Divide'
   */
  rtb_Square_idx_2 = rtb_Switch_idx_0 / rtb_Switch_idx_3 * rtb_Gain_kz;

  /* DotProduct: '<S66>/Dot Product2' */
  rtb_Gain3 = rtb_Square_b[0] * rtb_Square_idx_2;

  /* Product: '<S66>/Multiply3' incorporates:
   *  Product: '<S70>/Divide'
   */
  rtb_MathFunction_m[0] = rtb_Square_idx_2;
  rtb_Square_idx_2 = rtb_Switch_idx_1 / rtb_Switch_idx_3 * rtb_Gain_kz;

  /* DotProduct: '<S66>/Dot Product2' */
  rtb_Gain3 += rtb_Square_b[1] * rtb_Square_idx_2;

  /* Product: '<S66>/Multiply3' incorporates:
   *  Product: '<S70>/Divide'
   */
  rtb_MathFunction_m[1] = rtb_Square_idx_2;
  rtb_Square_idx_2 = rtb_Switch_idx_2 / rtb_Switch_idx_3 * rtb_Gain_kz;

  /* DotProduct: '<S66>/Dot Product2' */
  rtb_Gain3 += rtb_Square_b[2] * rtb_Square_idx_2;

  /* Gain: '<S66>/Gain3' incorporates:
   *  Constant: '<S66>/Constant'
   *  DotProduct: '<S66>/Dot Product2'
   *  Product: '<S66>/Divide'
   */
  rtb_Gain3 = rtb_Gain3 / 0.01F * -3.0F;

  /* Product: '<S66>/Multiply4' */
  rtb_Multiply4_k_idx_0 = rtb_Gain3 * rtb_MathFunction_m[0];
  rtb_Multiply4_k_idx_1 = rtb_Gain3 * rtb_MathFunction_m[1];

  /* RelationalOperator: '<S64>/Compare' incorporates:
   *  Constant: '<S64>/Constant'
   *  DotProduct: '<S53>/Dot Product2'
   *  Product: '<S53>/Multiply'
   */
  rtb_Compare_c = ((rtb_VectorConcatenate_j[0] * rtb_Sum_po[0] +
                    rtb_VectorConcatenate_j[1] * rtb_Sum_po[1]) +
                   rtb_VectorConcatenate_j[2] * rtb_Sum_po[2] < 0.0F);

  /* Product: '<S76>/Multiply' incorporates:
   *  Product: '<S53>/Multiply'
   */
  rtb_MathFunction_m[0] = rtb_Add_m[1] * rtb_VectorConcatenate_j[2];

  /* Product: '<S76>/Multiply1' incorporates:
   *  Product: '<S53>/Multiply'
   */
  rtb_MathFunction_m[1] = rtb_Add_m[2] * rtb_VectorConcatenate_j[0];

  /* Product: '<S76>/Multiply2' incorporates:
   *  Product: '<S53>/Multiply'
   */
  rtb_MathFunction_m[2] = rtb_Add_m[0] * rtb_VectorConcatenate_j[1];

  /* Sum: '<S72>/Sum' incorporates:
   *  Product: '<S53>/Multiply'
   *  Product: '<S77>/Multiply3'
   *  Product: '<S77>/Multiply4'
   *  Product: '<S77>/Multiply5'
   */
  rtb_MathFunction_m[0] -= rtb_Add_m[2] * rtb_VectorConcatenate_j[1];
  rtb_MathFunction_m[1] -= rtb_Add_m[0] * rtb_VectorConcatenate_j[2];
  rtb_MathFunction_m[2] -= rtb_Add_m[1] * rtb_VectorConcatenate_j[0];

  /* Product: '<S67>/Divide2' incorporates:
   *  Constant: '<S67>/Inertia_Matrix'
   */
  rt_mldivide_U1f3x3_U2f3_Yf3x1(Plant_ConstP.pooled33, rtb_MathFunction_m,
    rtb_Sum_po);

  /* Product: '<S78>/Multiply' */
  rtb_Sum_kn[0] = rtb_Sum_po[1] * rtb_Add_m[2];

  /* Product: '<S78>/Multiply1' */
  rtb_Sum_kn[1] = rtb_Sum_po[2] * rtb_Add_m[0];

  /* Product: '<S78>/Multiply2' */
  rtb_Sum_kn[2] = rtb_Sum_po[0] * rtb_Add_m[1];

  /* Sum: '<S73>/Sum' incorporates:
   *  Product: '<S79>/Multiply3'
   */
  rtb_Switch_idx_0 = rtb_Sum_kn[0] - rtb_Sum_po[2] * rtb_Add_m[1];

  /* DotProduct: '<S67>/Dot Product1' incorporates:
   *  Product: '<S53>/Multiply'
   */
  rtb_Switch_idx_1 = rtb_Switch_idx_0 * rtb_VectorConcatenate_j[0];

  /* Sum: '<S73>/Sum' incorporates:
   *  Product: '<S79>/Multiply4'
   */
  rtb_Sum_kn[0] = rtb_Switch_idx_0;
  rtb_Switch_idx_0 = rtb_Sum_kn[1] - rtb_Sum_po[0] * rtb_Add_m[2];

  /* DotProduct: '<S67>/Dot Product1' incorporates:
   *  Product: '<S53>/Multiply'
   */
  rtb_Switch_idx_1 += rtb_Switch_idx_0 * rtb_VectorConcatenate_j[1];

  /* Sum: '<S73>/Sum' incorporates:
   *  Product: '<S79>/Multiply5'
   */
  rtb_Sum_kn[1] = rtb_Switch_idx_0;
  rtb_Switch_idx_0 = rtb_Sum_kn[2] - rtb_Sum_po[1] * rtb_Add_m[0];

  /* DotProduct: '<S67>/Dot Product1' incorporates:
   *  Product: '<S53>/Multiply'
   */
  rtb_Switch_idx_1 += rtb_Switch_idx_0 * rtb_VectorConcatenate_j[2];

  /* Sum: '<S73>/Sum' */
  rtb_Sum_kn[2] = rtb_Switch_idx_0;

  /* Product: '<S67>/Divide1' incorporates:
   *  Abs: '<S67>/Abs'
   *  Constant: '<S67>/mass_inv'
   *  Constant: '<S67>/period'
   *  DotProduct: '<S67>/Dot Product'
   *  DotProduct: '<S67>/Dot Product1'
   *  Gain: '<S67>/Gain'
   *  Product: '<S53>/Multiply'
   *  Product: '<S67>/Divide'
   *  Product: '<S67>/Multiply3'
   *  Sum: '<S67>/Add1'
   */
  rtb_Gain_kz = fabsf(-(((rtb_Square_b[0] * rtb_VectorConcatenate_j[0] +
    rtb_Square_b[1] * rtb_VectorConcatenate_j[1]) + rtb_Square_b[2] *
    rtb_VectorConcatenate_j[2]) * Plant_ConstB.Add_o) * (1.0F /
    (rtb_Switch_idx_1 + 0.333333343F))) / 0.002F;

  /* Sum: '<S53>/Sum1' incorporates:
   *  Product: '<S53>/Multiply'
   *  Product: '<S53>/Multiply7'
   *  Product: '<S66>/Multiply4'
   *  Product: '<S67>/Multiply4'
   */
  rtb_Multiply4_k_idx_0 += rtb_Compare_c ? rtb_Gain_kz *
    rtb_VectorConcatenate_j[0] : 0.0F;
  rtb_Multiply4_k_idx_1 += rtb_Compare_c ? rtb_Gain_kz *
    rtb_VectorConcatenate_j[1] : 0.0F;
  rtb_Sum_b0 = rtb_Gain3 * rtb_Square_idx_2 + (rtb_Compare_c ? rtb_Gain_kz *
    rtb_VectorConcatenate_j[2] : 0.0F);

  /* RelationalOperator: '<S80>/Compare' incorporates:
   *  Constant: '<S80>/Constant'
   *  Delay: '<Root>/Delay'
   */
  rtb_Compare_c = (Plant_Y.Plant_States.h_R < 0.0F);

  /* Switch: '<S58>/Switch2' incorporates:
   *  Gain: '<S81>/Gain5'
   *  Gain: '<S81>/Gain6'
   *  Product: '<S81>/Multiply'
   *  SignalConversion: '<S81>/TmpSignal ConversionAtMultiplyInport2'
   */
  if (rtb_Compare_c) {
    /* Switch: '<S81>/Switch1' incorporates:
     *  Constant: '<S81>/mg'
     *  Constant: '<S83>/Constant'
     *  Delay: '<Root>/Delay'
     *  Gain: '<S81>/Gain'
     *  RelationalOperator: '<S83>/Compare'
     *  Sum: '<S81>/Add'
     */
    if (Plant_Y.Plant_States.h_R <= -0.01F) {
      /* Switch: '<S81>/Switch3' incorporates:
       *  Constant: '<S81>/mg'
       *  Constant: '<S84>/Constant'
       *  Gain: '<S81>/Gain1'
       *  Gain: '<S81>/Gain2'
       *  Gain: '<S81>/Gain3'
       *  Gain: '<S81>/Gain4'
       *  RelationalOperator: '<S84>/Compare'
       *  Sum: '<S81>/Add1'
       *  Sum: '<S81>/Add2'
       */
      if (Plant_Y.Plant_States.h_R <= -0.1F) {
        rtb_Gain3 = (50.0F * Plant_Y.Plant_States.h_R - 29.418F) - 100.0F *
          Plant_Y.Plant_States.vel_z_O;
      } else {
        rtb_Gain3 = (30.0F * Plant_Y.Plant_States.h_R - 29.418F) - 50.0F *
          Plant_Y.Plant_States.vel_z_O;
      }

      /* End of Switch: '<S81>/Switch3' */
    } else {
      rtb_Gain3 = -29.418F - 25.0F * Plant_Y.Plant_States.vel_z_O;
    }

    /* End of Switch: '<S81>/Switch1' */
    for (i = 0; i < 3; i++) {
      rtb_Square_o5[i] = rtb_VectorConcatenate_m1[i + 6] * rtb_Gain3 +
        (rtb_VectorConcatenate_m1[i + 3] * -rtb_Add_ow +
         rtb_VectorConcatenate_m1[i] * -rtb_magnitude_gauss);
    }
  } else {
    rtb_Square_o5[0] = 0.0F;
    rtb_Square_o5[1] = 0.0F;
    rtb_Square_o5[2] = 0.0F;
  }

  /* End of Switch: '<S58>/Switch2' */
  for (i = 0; i < 3; i++) {
    /* Product: '<S61>/Multiply' */
    rtb_Gain3 = rtb_VectorConcatenate_f[i + 6] * rtb_MathFunction1_k +
      (rtb_VectorConcatenate_f[i + 3] * rtb_Add_ow + rtb_VectorConcatenate_f[i] *
       rtb_magnitude_gauss);

    /* Signum: '<S61>/Sign1' */
    if (rtb_Gain3 < 0.0F) {
      rtb_Square_idx_2 = -1.0F;
    } else if (rtb_Gain3 > 0.0F) {
      rtb_Square_idx_2 = 1.0F;
    } else {
      rtb_Square_idx_2 = rtb_Gain3;
    }

    /* End of Signum: '<S61>/Sign1' */

    /* Gain: '<S61>/Gain' incorporates:
     *  Math: '<S61>/Square1'
     *  Product: '<S61>/Multiply5'
     */
    tmp_1[i] = rtb_Gain3 * rtb_Gain3 * rtb_Square_idx_2 * -0.02F;
  }

  /* Product: '<S61>/Multiply1' incorporates:
   *  Math: '<S61>/Square'
   */
  for (i = 0; i < 3; i++) {
    rtb_Add_m[i] = rtb_VectorConcatenate_f[3 * i + 2] * tmp_1[2] +
      (rtb_VectorConcatenate_f[3 * i + 1] * tmp_1[1] + rtb_VectorConcatenate_f[3
       * i] * tmp_1[0]);
  }

  /* End of Product: '<S61>/Multiply1' */

  /* DotProduct: '<S59>/Dot Product' */
  rtb_Square_l = 0.0F;
  for (i = 0; i < 3; i++) {
    /* Product: '<S61>/Multiply2' */
    rtb_magnitude_gauss = rtb_VectorConcatenate_m1[i + 6];

    /* Sum: '<S4>/Add2' incorporates:
     *  Inport: '<Root>/Environment_Info'
     *  Product: '<S57>/Multiply3'
     *  Product: '<S61>/Multiply2'
     */
    rtb_magnitude_gauss = (((Plant_U.Environment_Info.force[i] + rtb_Square_o5[i])
      + (rtb_magnitude_gauss * rtb_Add_m[2] + (rtb_VectorConcatenate_m1[i + 3] *
      rtb_Add_m[1] + rtb_VectorConcatenate_m1[i] * rtb_Add_m[0]))) +
      rtb_magnitude_gauss * 29.43F) + rtb_Sum1_a[i];

    /* DotProduct: '<S59>/Dot Product' incorporates:
     *  Product: '<S59>/Multiply'
     */
    rtb_Square_l += rtb_magnitude_gauss * rtb_VectorConcatenate_j[i];

    /* Sum: '<S4>/Add2' */
    rtb_Square_o5[i] = rtb_magnitude_gauss;
  }

  /* Product: '<S59>/Multiply1' incorporates:
   *  Constant: '<S85>/Constant'
   *  DotProduct: '<S59>/Dot Product'
   *  RelationalOperator: '<S85>/Compare'
   */
  rtb_magnitude_gauss = rtb_Square_l < 0.0F ? rtb_Square_l : 0.0F;

  /* Sum: '<S4>/Add' incorporates:
   *  Product: '<S59>/Multiply'
   *  Product: '<S59>/Multiply1'
   *  Sum: '<S59>/Sum'
   */
  rtb_Multiply4_k_idx_0 += rtb_Square_o5[0] - rtb_magnitude_gauss *
    rtb_VectorConcatenate_j[0];
  rtb_Multiply4_k_idx_1 += rtb_Square_o5[1] - rtb_magnitude_gauss *
    rtb_VectorConcatenate_j[1];
  rtb_Sum_b0 += rtb_Square_o5[2] - rtb_magnitude_gauss *
    rtb_VectorConcatenate_j[2];

  /* Switch: '<S58>/Switch1' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S82>/Gain1'
   *  Gain: '<S82>/Gain2'
   *  Gain: '<S82>/Gain3'
   *  Sum: '<S82>/Subtract'
   */
  if (rtb_Compare_c) {
    rtb_Square_o5[0] = ((0.0F - 30.0F * Plant_Y.Plant_States.phi) - 5.0F *
                        Plant_Y.Plant_States.rot_x_B) * 0.9806F;
    rtb_Square_o5[1] = ((0.0F - 30.0F * Plant_Y.Plant_States.theta) - 5.0F *
                        Plant_Y.Plant_States.rot_y_B) * 0.9806F;
    rtb_Square_o5[2] = (0.0F - 5.0F * Plant_Y.Plant_States.rot_z_B) * 0.9806F;
  } else {
    rtb_Square_o5[0] = 0.0F;
    rtb_Square_o5[1] = 0.0F;
    rtb_Square_o5[2] = 0.0F;
  }

  /* End of Switch: '<S58>/Switch1' */

  /* Signum: '<S61>/Sign' incorporates:
   *  Delay: '<Root>/Delay'
   */
  if (Plant_Y.Plant_States.rot_x_B < 0.0F) {
    rtb_Switch_idx_3 = -1.0F;
  } else if (Plant_Y.Plant_States.rot_x_B > 0.0F) {
    rtb_Switch_idx_3 = 1.0F;
  } else {
    rtb_Switch_idx_3 = Plant_Y.Plant_States.rot_x_B;
  }

  /* Outputs for Atomic SubSystem: '<Root>/Actuators' */
  /* Sum: '<S4>/Add3' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S61>/Gain1'
   *  Inport: '<Root>/Environment_Info'
   *  Math: '<S61>/Square2'
   *  Product: '<S61>/Multiply3'
   *  Sum: '<S1>/Sum'
   */
  rtb_Square_o5[0] = Plant_Y.Plant_States.rot_x_B * Plant_Y.Plant_States.rot_x_B
    * rtb_Switch_idx_3 * -0.005F + ((rtb_Sum1_dw_idx_0 +
    Plant_U.Environment_Info.torque[0]) + rtb_Square_o5[0]);

  /* End of Outputs for SubSystem: '<Root>/Actuators' */

  /* Signum: '<S61>/Sign' incorporates:
   *  Delay: '<Root>/Delay'
   */
  if (Plant_Y.Plant_States.rot_y_B < 0.0F) {
    rtb_Switch_idx_3 = -1.0F;
  } else if (Plant_Y.Plant_States.rot_y_B > 0.0F) {
    rtb_Switch_idx_3 = 1.0F;
  } else {
    rtb_Switch_idx_3 = Plant_Y.Plant_States.rot_y_B;
  }

  /* Outputs for Atomic SubSystem: '<Root>/Actuators' */
  /* Sum: '<S4>/Add3' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S61>/Gain1'
   *  Inport: '<Root>/Environment_Info'
   *  Math: '<S61>/Square2'
   *  Product: '<S61>/Multiply3'
   *  Sum: '<S1>/Sum'
   */
  rtb_Square_o5[1] = Plant_Y.Plant_States.rot_y_B * Plant_Y.Plant_States.rot_y_B
    * rtb_Switch_idx_3 * -0.005F + ((rtb_Product8 +
    Plant_U.Environment_Info.torque[1]) + rtb_Square_o5[1]);

  /* End of Outputs for SubSystem: '<Root>/Actuators' */

  /* Signum: '<S61>/Sign' incorporates:
   *  Delay: '<Root>/Delay'
   */
  if (Plant_Y.Plant_States.rot_z_B < 0.0F) {
    rtb_Switch_idx_3 = -1.0F;
  } else if (Plant_Y.Plant_States.rot_z_B > 0.0F) {
    rtb_Switch_idx_3 = 1.0F;
  } else {
    rtb_Switch_idx_3 = Plant_Y.Plant_States.rot_z_B;
  }

  /* Outputs for Atomic SubSystem: '<Root>/Actuators' */
  /* Sum: '<S4>/Add3' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S61>/Gain1'
   *  Inport: '<Root>/Environment_Info'
   *  Math: '<S61>/Square2'
   *  Product: '<S61>/Multiply3'
   *  Sum: '<S1>/Sum'
   */
  rtb_Square_l = Plant_Y.Plant_States.rot_z_B * Plant_Y.Plant_States.rot_z_B *
    rtb_Switch_idx_3 * -0.005F + ((rtb_Sum1_dw_idx_2 +
    Plant_U.Environment_Info.torque[2]) + rtb_Square_o5[2]);

  /* End of Outputs for SubSystem: '<Root>/Actuators' */

  /* Sum: '<S4>/Add1' incorporates:
   *  Product: '<S53>/Multiply6'
   */
  rtb_MathFunction_m[0] = rtb_Square_o5[0];
  rtb_MathFunction_m[1] = rtb_Square_o5[1];

  /* End of Outputs for SubSystem: '<Root>/Environment' */

  /* Outputs for Atomic SubSystem: '<Root>/Kinematic_Equation' */
  /* Gain: '<S90>/Gain' incorporates:
   *  Inport: '<Root>/States_Init'
   */
  rtb_Square_b[0] = 0.5F * Plant_U.States_Init.euler[0];
  rtb_Square_b[1] = 0.5F * Plant_U.States_Init.euler[1];
  rtb_Square_b[2] = 0.5F * Plant_U.States_Init.euler[2];

  /* End of Outputs for SubSystem: '<Root>/Kinematic_Equation' */

  /* Outputs for Atomic SubSystem: '<Root>/Environment' */
  /* RelationalOperator: '<S54>/Compare' incorporates:
   *  Constant: '<S54>/Constant'
   *  Inport: '<Root>/Environment_Info'
   *  Math: '<S60>/Square'
   *  Sqrt: '<S60>/Sqrt'
   *  Sum: '<S60>/Sum of Elements'
   */
  rtb_Compare = (sqrtf((Plant_U.Environment_Info.hit_normal[0] *
                        Plant_U.Environment_Info.hit_normal[0] +
                        Plant_U.Environment_Info.hit_normal[1] *
                        Plant_U.Environment_Info.hit_normal[1]) +
                       Plant_U.Environment_Info.hit_normal[2] *
                       Plant_U.Environment_Info.hit_normal[2]) > 0.0F);

  /* RelationalOperator: '<S55>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S55>/Delay Input1'
   *
   * Block description for '<S55>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_Compare_c = ((int32_T)rtb_Compare > (int32_T)Plant_DW.DelayInput1_DSTATE_b);

  /* Update for UnitDelay: '<S55>/Delay Input1'
   *
   * Block description for '<S55>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Plant_DW.DelayInput1_DSTATE_b = rtb_Compare;

  /* End of Outputs for SubSystem: '<Root>/Environment' */

  /* Outputs for Atomic SubSystem: '<Root>/Kinematic_Equation' */
  /* Trigonometry: '<S90>/Cos' */
  rtb_Add_ow = arm_cos_f32(rtb_Square_b[0]);

  /* Trigonometry: '<S90>/Cos1' */
  rtb_MathFunction1_k = arm_cos_f32(rtb_Square_b[1]);

  /* Trigonometry: '<S90>/Cos2' */
  rtb_Sum1_dw_idx_0 = arm_cos_f32(rtb_Square_b[2]);

  /* Trigonometry: '<S90>/Sin' */
  rtb_Product8 = arm_sin_f32(rtb_Square_b[0]);

  /* Trigonometry: '<S90>/Sin1' */
  rtb_Square2_b = arm_sin_f32(rtb_Square_b[1]);

  /* Trigonometry: '<S90>/Sin2' */
  rtb_Gain_kz = arm_sin_f32(rtb_Square_b[2]);

  /* Product: '<S90>/Multiply' incorporates:
   *  Product: '<S90>/Multiply6'
   */
  rtb_magnitude_gauss = rtb_Add_ow * rtb_MathFunction1_k;

  /* Product: '<S90>/Multiply1' incorporates:
   *  Product: '<S90>/Multiply7'
   */
  rtb_Sum1_dw_idx_2 = rtb_Product8 * rtb_Square2_b;

  /* SignalConversion: '<S96>/TmpSignal ConversionAtSquareInport1' incorporates:
   *  Product: '<S90>/Multiply'
   *  Product: '<S90>/Multiply1'
   *  Sum: '<S90>/Add'
   */
  rtb_Switch_idx_0 = rtb_magnitude_gauss * rtb_Sum1_dw_idx_0 + rtb_Sum1_dw_idx_2
    * rtb_Gain_kz;

  /* Product: '<S90>/Multiply3' incorporates:
   *  Product: '<S90>/Multiply4'
   */
  rtb_Add_ow *= rtb_Square2_b;

  /* Product: '<S90>/Multiply2' incorporates:
   *  Product: '<S90>/Multiply5'
   */
  rtb_Product8 *= rtb_MathFunction1_k;

  /* SignalConversion: '<S96>/TmpSignal ConversionAtSquareInport1' incorporates:
   *  Product: '<S90>/Multiply2'
   *  Product: '<S90>/Multiply3'
   *  Product: '<S90>/Multiply4'
   *  Product: '<S90>/Multiply5'
   *  Product: '<S90>/Multiply6'
   *  Product: '<S90>/Multiply7'
   *  Sum: '<S90>/Add1'
   *  Sum: '<S90>/Subtract'
   *  Sum: '<S90>/Subtract1'
   */
  rtb_Switch_idx_1 = rtb_Product8 * rtb_Sum1_dw_idx_0 - rtb_Add_ow * rtb_Gain_kz;
  rtb_Switch_idx_2 = rtb_Add_ow * rtb_Sum1_dw_idx_0 + rtb_Product8 * rtb_Gain_kz;
  rtb_Switch_idx_3 = rtb_magnitude_gauss * rtb_Gain_kz - rtb_Sum1_dw_idx_2 *
    rtb_Sum1_dw_idx_0;

  /* Sqrt: '<S96>/Sqrt' incorporates:
   *  Math: '<S96>/Square'
   *  Sum: '<S96>/Sum of Elements'
   */
  rtb_Gain_kz = sqrtf(((rtb_Switch_idx_0 * rtb_Switch_idx_0 + rtb_Switch_idx_1 *
                        rtb_Switch_idx_1) + rtb_Switch_idx_2 * rtb_Switch_idx_2)
                      + rtb_Switch_idx_3 * rtb_Switch_idx_3);

  /* Product: '<S95>/Divide' */
  rtb_Sum1_dw_idx_0 = rtb_Switch_idx_0 / rtb_Gain_kz;

  /* Math: '<S101>/Square' */
  rtb_MathFunction1_k = rtb_Sum1_dw_idx_0 * rtb_Sum1_dw_idx_0;

  /* Product: '<S95>/Divide' */
  rtb_Switch_idx_0 = rtb_Sum1_dw_idx_0;
  rtb_Sum1_dw_idx_0 = rtb_Switch_idx_1 / rtb_Gain_kz;

  /* Math: '<S101>/Square' */
  rtb_Gain3 = rtb_Sum1_dw_idx_0 * rtb_Sum1_dw_idx_0;

  /* Product: '<S95>/Divide' */
  rtb_Switch_idx_1 = rtb_Sum1_dw_idx_0;
  rtb_Sum1_dw_idx_0 = rtb_Switch_idx_2 / rtb_Gain_kz;

  /* Math: '<S101>/Square' */
  rtb_Square_idx_2 = rtb_Sum1_dw_idx_0 * rtb_Sum1_dw_idx_0;

  /* Product: '<S95>/Divide' */
  rtb_Switch_idx_2 = rtb_Sum1_dw_idx_0;
  rtb_Sum1_dw_idx_0 = rtb_Switch_idx_3 / rtb_Gain_kz;

  /* Sqrt: '<S101>/Sqrt' incorporates:
   *  Math: '<S101>/Square'
   *  Sum: '<S101>/Sum of Elements'
   */
  rtb_Gain_kz = sqrtf(((rtb_MathFunction1_k + rtb_Gain3) + rtb_Square_idx_2) +
                      rtb_Sum1_dw_idx_0 * rtb_Sum1_dw_idx_0);

  /* Product: '<S99>/Divide' */
  rtb_Switch_idx_0 /= rtb_Gain_kz;
  rtb_Switch_idx_1 /= rtb_Gain_kz;
  rtb_Switch_idx_2 /= rtb_Gain_kz;
  rtb_Sum1_dw_idx_0 /= rtb_Gain_kz;

  /* RelationalOperator: '<S89>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/States_Init'
   *  UnitDelay: '<S89>/Delay Input1'
   *
   * Block description for '<S89>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_Compare = (Plant_U.States_Init.timestamp != Plant_DW.DelayInput1_DSTATE);

  /* DiscreteIntegrator: '<S92>/Discrete-Time Integrator' */
  if (Plant_DW.DiscreteTimeIntegrator_IC_LOADI != 0) {
    Plant_DW.DiscreteTimeIntegrator_DSTATE_j[0] = rtb_Switch_idx_0;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_j[1] = rtb_Switch_idx_1;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_j[2] = rtb_Switch_idx_2;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_j[3] = rtb_Sum1_dw_idx_0;
  }

  if (rtb_Compare || (Plant_DW.DiscreteTimeIntegrator_PrevRese != 0)) {
    Plant_DW.DiscreteTimeIntegrator_DSTATE_j[0] = rtb_Switch_idx_0;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_j[1] = rtb_Switch_idx_1;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_j[2] = rtb_Switch_idx_2;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_j[3] = rtb_Sum1_dw_idx_0;
  }

  rtb_MathFunction1_k = Plant_DW.DiscreteTimeIntegrator_DSTATE_j[0];
  rtb_Gain3 = Plant_DW.DiscreteTimeIntegrator_DSTATE_j[1];
  rtb_Square_idx_2 = Plant_DW.DiscreteTimeIntegrator_DSTATE_j[2];
  rtb_Switch_idx_0 = Plant_DW.DiscreteTimeIntegrator_DSTATE_j[3];

  /* SignalConversion: '<S100>/ConcatBufferAtMatrix ConcatenateIn1' incorporates:
   *  Constant: '<S100>/Constant'
   */
  rtb_MatrixConcatenate4[0] = 0.0F;

  /* DiscreteIntegrator: '<S86>/Discrete-Time Integrator' incorporates:
   *  Logic: '<S86>/Logical Operator'
   */
  if (rtb_Compare || (Plant_DW.DiscreteTimeIntegrator_PrevRe_g != 0)) {
    Plant_DW.DiscreteTimeIntegrator_DSTATE_l[0] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_l[1] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_l[2] = 0.0F;
  }

  rtb_Square_o5[0] = Plant_DW.DiscreteTimeIntegrator_DSTATE_l[0];
  rtb_Square_o5[1] = Plant_DW.DiscreteTimeIntegrator_DSTATE_l[1];
  rtb_Square_o5[2] = Plant_DW.DiscreteTimeIntegrator_DSTATE_l[2];

  /* SignalConversion: '<S100>/ConcatBufferAtMatrix ConcatenateIn2' incorporates:
   *  DiscreteIntegrator: '<S86>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[1] = Plant_DW.DiscreteTimeIntegrator_DSTATE_l[0];

  /* SignalConversion: '<S100>/ConcatBufferAtMatrix ConcatenateIn3' incorporates:
   *  DiscreteIntegrator: '<S86>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[2] = Plant_DW.DiscreteTimeIntegrator_DSTATE_l[1];

  /* SignalConversion: '<S100>/ConcatBufferAtMatrix ConcatenateIn4' incorporates:
   *  DiscreteIntegrator: '<S86>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[3] = Plant_DW.DiscreteTimeIntegrator_DSTATE_l[2];

  /* Gain: '<S100>/Gain1' incorporates:
   *  DiscreteIntegrator: '<S86>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[4] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_l[0];

  /* SignalConversion: '<S100>/ConcatBufferAtMatrix Concatenate1In2' incorporates:
   *  Constant: '<S100>/Constant1'
   */
  rtb_MatrixConcatenate4[5] = 0.0F;

  /* Gain: '<S100>/Gain2' incorporates:
   *  DiscreteIntegrator: '<S86>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[6] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_l[2];

  /* SignalConversion: '<S100>/ConcatBufferAtMatrix Concatenate1In4' incorporates:
   *  DiscreteIntegrator: '<S86>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[7] = Plant_DW.DiscreteTimeIntegrator_DSTATE_l[1];

  /* Gain: '<S100>/Gain3' incorporates:
   *  DiscreteIntegrator: '<S86>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[8] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_l[1];

  /* SignalConversion: '<S100>/ConcatBufferAtMatrix Concatenate2In2' incorporates:
   *  DiscreteIntegrator: '<S86>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[9] = Plant_DW.DiscreteTimeIntegrator_DSTATE_l[2];

  /* SignalConversion: '<S100>/ConcatBufferAtMatrix Concatenate2In3' incorporates:
   *  Constant: '<S100>/Constant2'
   */
  rtb_MatrixConcatenate4[10] = 0.0F;

  /* Gain: '<S100>/Gain4' incorporates:
   *  DiscreteIntegrator: '<S86>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[11] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_l[0];

  /* Gain: '<S100>/Gain6' incorporates:
   *  DiscreteIntegrator: '<S86>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[12] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_l[2];

  /* Gain: '<S100>/Gain7' incorporates:
   *  DiscreteIntegrator: '<S86>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[13] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_l[1];

  /* SignalConversion: '<S100>/ConcatBufferAtMatrix Concatenate3In3' incorporates:
   *  DiscreteIntegrator: '<S86>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[14] = Plant_DW.DiscreteTimeIntegrator_DSTATE_l[0];

  /* SignalConversion: '<S100>/ConcatBufferAtMatrix Concatenate3In4' incorporates:
   *  Constant: '<S100>/Constant3'
   */
  rtb_MatrixConcatenate4[15] = 0.0F;

  /* Sqrt: '<S98>/Sqrt' incorporates:
   *  DiscreteIntegrator: '<S92>/Discrete-Time Integrator'
   *  Math: '<S98>/Square'
   *  Sqrt: '<S112>/Sqrt'
   *  Sqrt: '<S117>/Sqrt'
   *  Sum: '<S98>/Sum of Elements'
   */
  rtb_Gain_e_tmp = sqrtf(((Plant_DW.DiscreteTimeIntegrator_DSTATE_j[0] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_j[0] +
    Plant_DW.DiscreteTimeIntegrator_DSTATE_j[1] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_j[1]) +
    Plant_DW.DiscreteTimeIntegrator_DSTATE_j[2] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_j[2]) +
    Plant_DW.DiscreteTimeIntegrator_DSTATE_j[3] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_j[3]);

  /* Product: '<S97>/Divide' incorporates:
   *  DiscreteIntegrator: '<S92>/Discrete-Time Integrator'
   *  Sqrt: '<S98>/Sqrt'
   */
  rtb_magnitude_gauss = Plant_DW.DiscreteTimeIntegrator_DSTATE_j[0] /
    rtb_Gain_e_tmp;
  rtb_Add_ow = Plant_DW.DiscreteTimeIntegrator_DSTATE_j[1] / rtb_Gain_e_tmp;
  rtb_Switch_idx_1 = Plant_DW.DiscreteTimeIntegrator_DSTATE_j[2] /
    rtb_Gain_e_tmp;
  rtb_Switch_idx_2 = Plant_DW.DiscreteTimeIntegrator_DSTATE_j[3] /
    rtb_Gain_e_tmp;

  /* Product: '<S108>/Divide' incorporates:
   *  DiscreteIntegrator: '<S92>/Discrete-Time Integrator'
   */
  rtb_Switch_idx_3 = Plant_DW.DiscreteTimeIntegrator_DSTATE_j[0] /
    rtb_Gain_e_tmp;
  rtb_Gain_e_tmp_4 = Plant_DW.DiscreteTimeIntegrator_DSTATE_j[1] /
    rtb_Gain_e_tmp;
  rtb_Sum_l_tmp = Plant_DW.DiscreteTimeIntegrator_DSTATE_j[2] / rtb_Gain_e_tmp;
  rtb_Sum_ah_idx_2 = Plant_DW.DiscreteTimeIntegrator_DSTATE_j[3] /
    rtb_Gain_e_tmp;

  /* Product: '<S113>/Divide' incorporates:
   *  DiscreteIntegrator: '<S92>/Discrete-Time Integrator'
   */
  rtb_Divide_h_idx_0 = Plant_DW.DiscreteTimeIntegrator_DSTATE_j[0] /
    rtb_Gain_e_tmp;
  rtb_Divide_h_idx_1 = Plant_DW.DiscreteTimeIntegrator_DSTATE_j[1] /
    rtb_Gain_e_tmp;
  rtb_Divide_h_idx_2 = Plant_DW.DiscreteTimeIntegrator_DSTATE_j[2] /
    rtb_Gain_e_tmp;
  rtb_Divide_h_idx_3 = Plant_DW.DiscreteTimeIntegrator_DSTATE_j[3] /
    rtb_Gain_e_tmp;

  /* Product: '<S86>/Multiply' incorporates:
   *  Constant: '<S86>/Inertia_Matrix'
   *  DiscreteIntegrator: '<S86>/Discrete-Time Integrator'
   */
  for (i = 0; i < 3; i++) {
    rtb_Add_m[i] = Plant_ConstP.pooled33[i + 6] *
      Plant_DW.DiscreteTimeIntegrator_DSTATE_l[2] + (Plant_ConstP.pooled33[i + 3]
      * Plant_DW.DiscreteTimeIntegrator_DSTATE_l[1] + Plant_ConstP.pooled33[i] *
      Plant_DW.DiscreteTimeIntegrator_DSTATE_l[0]);
  }

  /* End of Product: '<S86>/Multiply' */

  /* Product: '<S93>/Multiply' incorporates:
   *  DiscreteIntegrator: '<S86>/Discrete-Time Integrator'
   */
  rtb_Sum_c[0] = Plant_DW.DiscreteTimeIntegrator_DSTATE_l[1] * rtb_Add_m[2];

  /* Product: '<S93>/Multiply1' incorporates:
   *  DiscreteIntegrator: '<S86>/Discrete-Time Integrator'
   */
  rtb_Sum_c[1] = Plant_DW.DiscreteTimeIntegrator_DSTATE_l[2] * rtb_Add_m[0];

  /* Product: '<S93>/Multiply2' incorporates:
   *  DiscreteIntegrator: '<S86>/Discrete-Time Integrator'
   */
  rtb_Sum_c[2] = Plant_DW.DiscreteTimeIntegrator_DSTATE_l[0] * rtb_Add_m[1];

  /* Product: '<S94>/Multiply3' incorporates:
   *  DiscreteIntegrator: '<S86>/Discrete-Time Integrator'
   */
  rtb_Sum_po[0] = Plant_DW.DiscreteTimeIntegrator_DSTATE_l[2] * rtb_Add_m[1];

  /* Product: '<S94>/Multiply4' incorporates:
   *  DiscreteIntegrator: '<S86>/Discrete-Time Integrator'
   */
  rtb_Sum_po[1] = Plant_DW.DiscreteTimeIntegrator_DSTATE_l[0] * rtb_Add_m[2];

  /* Product: '<S94>/Multiply5' incorporates:
   *  DiscreteIntegrator: '<S86>/Discrete-Time Integrator'
   */
  rtb_Sum_po[2] = Plant_DW.DiscreteTimeIntegrator_DSTATE_l[1] * rtb_Add_m[0];

  /* RelationalOperator: '<S103>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/States_Init'
   *  UnitDelay: '<S103>/Delay Input1'
   *
   * Block description for '<S103>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_FixPtRelationalOperator_k = (Plant_U.States_Init.timestamp !=
    Plant_DW.DelayInput1_DSTATE_g);

  /* Logic: '<S87>/Logical Operator' */
  rtb_Compare_c = (rtb_Compare_c || rtb_FixPtRelationalOperator_k);

  /* DiscreteIntegrator: '<S87>/Discrete-Time Integrator' */
  if (rtb_Compare_c || (Plant_DW.DiscreteTimeIntegrator_PrevRe_d != 0)) {
    Plant_DW.DiscreteTimeIntegrator_DSTATE_n[0] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_n[1] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_n[2] = 0.0F;
  }

  rtb_Sum1_dw_idx_0 = Plant_DW.DiscreteTimeIntegrator_DSTATE_n[0];
  rtb_Product8 = Plant_DW.DiscreteTimeIntegrator_DSTATE_n[1];
  rtb_Sum1_dw_idx_2 = Plant_DW.DiscreteTimeIntegrator_DSTATE_n[2];

  /* Product: '<S111>/Product3' incorporates:
   *  Product: '<S108>/Divide'
   *  Product: '<S109>/Product6'
   */
  rtb_Gain_e_tmp = rtb_Sum_l_tmp * rtb_Sum_l_tmp;

  /* Product: '<S111>/Product6' incorporates:
   *  Product: '<S108>/Divide'
   *  Product: '<S109>/Product9'
   */
  rtb_Gain_e_tmp_0 = rtb_Gain_e_tmp_4 * rtb_Sum_ah_idx_2;

  /* Product: '<S111>/Product7' incorporates:
   *  Product: '<S108>/Divide'
   *  Product: '<S109>/Product2'
   */
  rtb_Gain_e_tmp_1 = rtb_Switch_idx_3 * rtb_Sum_l_tmp;

  /* Sum: '<S111>/Sum2' incorporates:
   *  Constant: '<S111>/Constant'
   *  Product: '<S108>/Divide'
   *  Product: '<S111>/Product2'
   *  Sum: '<S110>/Sum1'
   */
  rtb_Gain_e_tmp_2 = 0.5F - rtb_Gain_e_tmp_4 * rtb_Gain_e_tmp_4;

  /* Product: '<S111>/Product1' incorporates:
   *  Product: '<S108>/Divide'
   *  Product: '<S110>/Product2'
   */
  rtb_Gain_e_tmp_5 = rtb_Switch_idx_3 * rtb_Gain_e_tmp_4;

  /* Product: '<S111>/Product9' incorporates:
   *  Product: '<S108>/Divide'
   *  Product: '<S110>/Product3'
   */
  rtb_Gain_e_tmp_6 = rtb_Sum_l_tmp * rtb_Sum_ah_idx_2;

  /* Sum: '<S111>/Sum' incorporates:
   *  DiscreteIntegrator: '<S87>/Discrete-Time Integrator'
   *  Gain: '<S111>/Gain1'
   *  Gain: '<S111>/Gain2'
   *  Gain: '<S111>/Gain3'
   *  Product: '<S111>/Product1'
   *  Product: '<S111>/Product3'
   *  Product: '<S111>/Product4'
   *  Product: '<S111>/Product5'
   *  Product: '<S111>/Product6'
   *  Product: '<S111>/Product7'
   *  Product: '<S111>/Product8'
   *  Product: '<S111>/Product9'
   *  Sum: '<S111>/Sum1'
   *  Sum: '<S111>/Sum2'
   *  Sum: '<S111>/Sum3'
   */
  rtb_Gain_kz = ((rtb_Gain_e_tmp_0 + rtb_Gain_e_tmp_1) * 2.0F *
                 Plant_DW.DiscreteTimeIntegrator_DSTATE_n[0] + (rtb_Gain_e_tmp_6
    - rtb_Gain_e_tmp_5) * 2.0F * Plant_DW.DiscreteTimeIntegrator_DSTATE_n[1]) +
    (rtb_Gain_e_tmp_2 - rtb_Gain_e_tmp) * 2.0F *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_n[2];

  /* Product: '<S106>/Multiply' incorporates:
   *  DiscreteIntegrator: '<S86>/Discrete-Time Integrator'
   */
  rtb_Add_m[0] = Plant_DW.DiscreteTimeIntegrator_DSTATE_l[1] * rtb_Gain_kz;

  /* Product: '<S107>/Multiply4' incorporates:
   *  DiscreteIntegrator: '<S86>/Discrete-Time Integrator'
   */
  rtb_Square2_b = Plant_DW.DiscreteTimeIntegrator_DSTATE_l[0] * rtb_Gain_kz;

  /* DiscreteIntegrator: '<S87>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/States_Init'
   */
  if (Plant_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
    Plant_DW.DiscreteTimeIntegrator1_DSTATE[0] = Plant_U.States_Init.pos[0];
    Plant_DW.DiscreteTimeIntegrator1_DSTATE[1] = Plant_U.States_Init.pos[1];
    Plant_DW.DiscreteTimeIntegrator1_DSTATE[2] = Plant_U.States_Init.pos[2];
  }

  if (rtb_FixPtRelationalOperator_k || (Plant_DW.DiscreteTimeIntegrator1_PrevRes
       != 0)) {
    Plant_DW.DiscreteTimeIntegrator1_DSTATE[0] = Plant_U.States_Init.pos[0];
    Plant_DW.DiscreteTimeIntegrator1_DSTATE[1] = Plant_U.States_Init.pos[1];
    Plant_DW.DiscreteTimeIntegrator1_DSTATE[2] = Plant_U.States_Init.pos[2];
  }

  /* Product: '<S109>/Product7' incorporates:
   *  Product: '<S108>/Divide'
   *  Product: '<S110>/Product9'
   */
  rtb_Gain_e_tmp_3 = rtb_Sum_ah_idx_2 * rtb_Sum_ah_idx_2;

  /* Product: '<S109>/Product' incorporates:
   *  Product: '<S108>/Divide'
   *  Product: '<S110>/Product6'
   */
  rtb_Gain_e_tmp_4 *= rtb_Sum_l_tmp;

  /* Product: '<S109>/Product1' incorporates:
   *  Product: '<S108>/Divide'
   *  Product: '<S110>/Product7'
   */
  rtb_Switch_idx_3 *= rtb_Sum_ah_idx_2;

  /* Sum: '<S109>/Sum' incorporates:
   *  Constant: '<S109>/Constant'
   *  DiscreteIntegrator: '<S87>/Discrete-Time Integrator'
   *  Gain: '<S109>/Gain'
   *  Gain: '<S109>/Gain2'
   *  Gain: '<S109>/Gain3'
   *  Product: '<S109>/Product'
   *  Product: '<S109>/Product1'
   *  Product: '<S109>/Product4'
   *  Product: '<S109>/Product5'
   *  Product: '<S109>/Product7'
   *  Product: '<S109>/Product8'
   *  Sum: '<S109>/Sum1'
   *  Sum: '<S109>/Sum2'
   *  Sum: '<S109>/Sum3'
   */
  rtb_Gain_kz = (((0.5F - rtb_Gain_e_tmp) - rtb_Gain_e_tmp_3) * 2.0F *
                 Plant_DW.DiscreteTimeIntegrator_DSTATE_n[0] + (rtb_Gain_e_tmp_4
    + rtb_Switch_idx_3) * 2.0F * Plant_DW.DiscreteTimeIntegrator_DSTATE_n[1]) +
    (rtb_Gain_e_tmp_0 - rtb_Gain_e_tmp_1) * 2.0F *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_n[2];

  /* Product: '<S106>/Multiply1' incorporates:
   *  DiscreteIntegrator: '<S86>/Discrete-Time Integrator'
   */
  rtb_Add_m[1] = Plant_DW.DiscreteTimeIntegrator_DSTATE_l[2] * rtb_Gain_kz;

  /* Product: '<S107>/Multiply5' incorporates:
   *  DiscreteIntegrator: '<S86>/Discrete-Time Integrator'
   */
  rtb_Sum_ah_idx_2 = Plant_DW.DiscreteTimeIntegrator_DSTATE_l[1] * rtb_Gain_kz;

  /* Sum: '<S110>/Sum' incorporates:
   *  DiscreteIntegrator: '<S87>/Discrete-Time Integrator'
   *  Gain: '<S110>/Gain1'
   *  Gain: '<S110>/Gain2'
   *  Gain: '<S110>/Gain3'
   *  Product: '<S110>/Product4'
   *  Product: '<S110>/Product5'
   *  Product: '<S110>/Product8'
   *  Sum: '<S110>/Sum1'
   *  Sum: '<S110>/Sum2'
   *  Sum: '<S110>/Sum3'
   */
  rtb_Gain_kz = ((rtb_Gain_e_tmp_2 - rtb_Gain_e_tmp_3) * 2.0F *
                 Plant_DW.DiscreteTimeIntegrator_DSTATE_n[1] + (rtb_Gain_e_tmp_4
    - rtb_Switch_idx_3) * 2.0F * Plant_DW.DiscreteTimeIntegrator_DSTATE_n[0]) +
    (rtb_Gain_e_tmp_5 + rtb_Gain_e_tmp_6) * 2.0F *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_n[2];

  /* DiscreteIntegrator: '<S87>/Discrete-Time Integrator1' */
  rtb_Sum1_a[0] = Plant_DW.DiscreteTimeIntegrator1_DSTATE[0];

  /* Sum: '<S86>/Sum' incorporates:
   *  Sum: '<S88>/Sum'
   */
  rtb_Sum_po[0] = rtb_MathFunction_m[0] - (rtb_Sum_c[0] - rtb_Sum_po[0]);

  /* Sum: '<S87>/Sum' incorporates:
   *  Constant: '<S87>/mass'
   *  DiscreteIntegrator: '<S86>/Discrete-Time Integrator'
   *  Product: '<S107>/Multiply3'
   *  Product: '<S87>/Divide'
   *  Sum: '<S102>/Sum'
   */
  rtb_Switch_idx_3 = rtb_Multiply4_k_idx_0 / 3.0F - (rtb_Add_m[0] -
    Plant_DW.DiscreteTimeIntegrator_DSTATE_l[2] * rtb_Gain_kz);

  /* DiscreteIntegrator: '<S87>/Discrete-Time Integrator1' */
  rtb_Sum1_a[1] = Plant_DW.DiscreteTimeIntegrator1_DSTATE[1];

  /* Sum: '<S86>/Sum' incorporates:
   *  Sum: '<S88>/Sum'
   */
  rtb_Sum_po[1] = rtb_MathFunction_m[1] - (rtb_Sum_c[1] - rtb_Sum_po[1]);

  /* Sum: '<S87>/Sum' incorporates:
   *  Constant: '<S87>/mass'
   *  Product: '<S87>/Divide'
   *  Sum: '<S102>/Sum'
   */
  rtb_Square2_b = rtb_Multiply4_k_idx_1 / 3.0F - (rtb_Add_m[1] - rtb_Square2_b);

  /* DiscreteIntegrator: '<S87>/Discrete-Time Integrator1' */
  rtb_Sum1_a[2] = Plant_DW.DiscreteTimeIntegrator1_DSTATE[2];

  /* Sum: '<S87>/Sum' incorporates:
   *  Constant: '<S87>/mass'
   *  DiscreteIntegrator: '<S86>/Discrete-Time Integrator'
   *  Product: '<S106>/Multiply2'
   *  Product: '<S87>/Divide'
   *  Sum: '<S102>/Sum'
   */
  rtb_Gain_kz = rtb_Sum_b0 / 3.0F - (Plant_DW.DiscreteTimeIntegrator_DSTATE_l[0]
    * rtb_Gain_kz - rtb_Sum_ah_idx_2);

  /* Sum: '<S86>/Sum' incorporates:
   *  Sum: '<S88>/Sum'
   */
  rtb_Sum_po[2] = rtb_Square_l - (rtb_Sum_c[2] - rtb_Sum_po[2]);

  /* Product: '<S114>/Product7' incorporates:
   *  Product: '<S113>/Divide'
   *  Product: '<S115>/Product7'
   */
  rtb_Multiply4_k_idx_0 = rtb_Divide_h_idx_3 * rtb_Divide_h_idx_3;

  /* Product: '<S114>/Product' incorporates:
   *  Product: '<S113>/Divide'
   *  Product: '<S115>/Product'
   */
  rtb_Gain_e_tmp_4 = rtb_Divide_h_idx_1 * rtb_Divide_h_idx_2;

  /* Product: '<S114>/Product1' incorporates:
   *  Product: '<S113>/Divide'
   *  Product: '<S115>/Product1'
   */
  rtb_Sum_l_tmp = rtb_Divide_h_idx_0 * rtb_Divide_h_idx_3;

  /* Product: '<S114>/Product2' incorporates:
   *  Product: '<S113>/Divide'
   *  Product: '<S116>/Product9'
   */
  rtb_Sum_b0 = rtb_Divide_h_idx_1 * rtb_Divide_h_idx_3;

  /* Product: '<S114>/Product3' incorporates:
   *  Product: '<S113>/Divide'
   *  Product: '<S116>/Product1'
   */
  rtb_Square_l = rtb_Divide_h_idx_0 * rtb_Divide_h_idx_2;

  /* Product: '<S114>/Product6' incorporates:
   *  Product: '<S113>/Divide'
   *  Product: '<S116>/Product7'
   */
  rtb_Sum_ah_idx_2 = rtb_Divide_h_idx_2 * rtb_Divide_h_idx_2;

  /* Sum: '<S114>/Sum' incorporates:
   *  Constant: '<S114>/Constant'
   *  Gain: '<S114>/Gain'
   *  Gain: '<S114>/Gain1'
   *  Gain: '<S114>/Gain2'
   *  Product: '<S114>/Product'
   *  Product: '<S114>/Product1'
   *  Product: '<S114>/Product2'
   *  Product: '<S114>/Product3'
   *  Product: '<S114>/Product4'
   *  Product: '<S114>/Product5'
   *  Product: '<S114>/Product6'
   *  Product: '<S114>/Product7'
   *  Product: '<S114>/Product8'
   *  Sum: '<S114>/Sum1'
   *  Sum: '<S114>/Sum2'
   *  Sum: '<S114>/Sum3'
   */
  rtb_Multiply4_k_idx_1 = (((0.5F - rtb_Sum_ah_idx_2) - rtb_Multiply4_k_idx_0) *
    2.0F * rtb_Switch_idx_3 + (rtb_Gain_e_tmp_4 - rtb_Sum_l_tmp) * 2.0F *
    rtb_Square2_b) + (rtb_Sum_b0 + rtb_Square_l) * 2.0F * rtb_Gain_kz;

  /* Product: '<S115>/Product2' incorporates:
   *  Product: '<S113>/Divide'
   *  Product: '<S116>/Product2'
   */
  rtb_Divide_h_idx_0 *= rtb_Divide_h_idx_1;

  /* Product: '<S115>/Product3' incorporates:
   *  Product: '<S113>/Divide'
   *  Product: '<S116>/Product3'
   */
  rtb_Divide_h_idx_2 *= rtb_Divide_h_idx_3;

  /* Sum: '<S115>/Sum3' incorporates:
   *  Constant: '<S115>/Constant'
   *  Product: '<S113>/Divide'
   *  Product: '<S115>/Product6'
   *  Sum: '<S116>/Sum3'
   */
  rtb_Divide_h_idx_1 = 0.5F - rtb_Divide_h_idx_1 * rtb_Divide_h_idx_1;

  /* Sum: '<S115>/Sum' incorporates:
   *  Gain: '<S115>/Gain'
   *  Gain: '<S115>/Gain1'
   *  Gain: '<S115>/Gain2'
   *  Product: '<S115>/Product2'
   *  Product: '<S115>/Product3'
   *  Product: '<S115>/Product4'
   *  Product: '<S115>/Product5'
   *  Product: '<S115>/Product8'
   *  Sum: '<S115>/Sum1'
   *  Sum: '<S115>/Sum2'
   *  Sum: '<S115>/Sum3'
   */
  rtb_Multiply4_k_idx_0 = ((rtb_Divide_h_idx_1 - rtb_Multiply4_k_idx_0) * 2.0F *
    rtb_Square2_b + (rtb_Gain_e_tmp_4 + rtb_Sum_l_tmp) * 2.0F * rtb_Switch_idx_3)
    + (rtb_Divide_h_idx_2 - rtb_Divide_h_idx_0) * 2.0F * rtb_Gain_kz;

  /* Sum: '<S116>/Sum' incorporates:
   *  Gain: '<S116>/Gain1'
   *  Gain: '<S116>/Gain2'
   *  Gain: '<S116>/Gain3'
   *  Product: '<S116>/Product4'
   *  Product: '<S116>/Product5'
   *  Product: '<S116>/Product8'
   *  Sum: '<S116>/Sum1'
   *  Sum: '<S116>/Sum2'
   *  Sum: '<S116>/Sum3'
   */
  rtb_Sum_b0 = ((rtb_Sum_b0 - rtb_Square_l) * 2.0F * rtb_Switch_idx_3 +
                (rtb_Divide_h_idx_0 + rtb_Divide_h_idx_2) * 2.0F * rtb_Square2_b)
    + (rtb_Divide_h_idx_1 - rtb_Sum_ah_idx_2) * 2.0F * rtb_Gain_kz;

  /* Math: '<S91>/Square1' incorporates:
   *  Product: '<S97>/Divide'
   */
  rtb_Square2_b = rtb_Switch_idx_1 * rtb_Switch_idx_1;

  /* Product: '<S91>/Multiply6' incorporates:
   *  Constant: '<S91>/Constant'
   *  Product: '<S91>/Multiply4'
   *  Product: '<S91>/Multiply5'
   *  Product: '<S97>/Divide'
   *  Sum: '<S91>/Subtract'
   */
  rtb_Square_l = (rtb_magnitude_gauss * rtb_Switch_idx_1 - rtb_Switch_idx_2 *
                  rtb_Add_ow) * 2.0F;

  /* Update for UnitDelay: '<S89>/Delay Input1' incorporates:
   *  Inport: '<Root>/States_Init'
   *
   * Block description for '<S89>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Plant_DW.DelayInput1_DSTATE = Plant_U.States_Init.timestamp;

  /* Update for DiscreteIntegrator: '<S92>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_IC_LOADI = 0U;

  /* Product: '<S92>/Multiply' incorporates:
   *  DiscreteIntegrator: '<S92>/Discrete-Time Integrator'
   */
  for (i = 0; i < 4; i++) {
    rtb_Gain_kz = rtb_MatrixConcatenate4[i + 12] *
      Plant_DW.DiscreteTimeIntegrator_DSTATE_j[3] + (rtb_MatrixConcatenate4[i +
      8] * Plant_DW.DiscreteTimeIntegrator_DSTATE_j[2] +
      (rtb_MatrixConcatenate4[i + 4] * Plant_DW.DiscreteTimeIntegrator_DSTATE_j
       [1] + rtb_MatrixConcatenate4[i] *
       Plant_DW.DiscreteTimeIntegrator_DSTATE_j[0]));
    rtb_Divide_g[i] = rtb_Gain_kz;
  }

  /* End of Product: '<S92>/Multiply' */

  /* Update for DiscreteIntegrator: '<S92>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S92>/Gain'
   */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_j[0] += 0.5F * rtb_Divide_g[0] * 0.002F;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_j[1] += 0.5F * rtb_Divide_g[1] * 0.002F;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_j[2] += 0.5F * rtb_Divide_g[2] * 0.002F;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_j[3] += 0.5F * rtb_Divide_g[3] * 0.002F;
  Plant_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)rtb_Compare;

  /* Product: '<S86>/Divide' incorporates:
   *  Constant: '<S86>/Inertia_Matrix'
   */
  rt_mldivide_U1f3x3_U2f3_Yf3x1(Plant_ConstP.pooled33, rtb_Sum_po, tmp_1);

  /* Update for DiscreteIntegrator: '<S86>/Discrete-Time Integrator' incorporates:
   *  Logic: '<S86>/Logical Operator'
   */
  Plant_DW.DiscreteTimeIntegrator_PrevRe_g = (int8_T)rtb_Compare;

  /* Update for UnitDelay: '<S103>/Delay Input1' incorporates:
   *  Inport: '<Root>/States_Init'
   *
   * Block description for '<S103>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Plant_DW.DelayInput1_DSTATE_g = Plant_U.States_Init.timestamp;

  /* Update for DiscreteIntegrator: '<S87>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_PrevRe_d = (int8_T)rtb_Compare_c;

  /* Update for DiscreteIntegrator: '<S87>/Discrete-Time Integrator1' */
  Plant_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;

  /* Update for DiscreteIntegrator: '<S86>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_l[0] += 0.002F * tmp_1[0];

  /* Update for DiscreteIntegrator: '<S87>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_n[0] += 0.002F * rtb_Multiply4_k_idx_1;

  /* Update for DiscreteIntegrator: '<S87>/Discrete-Time Integrator1' */
  Plant_DW.DiscreteTimeIntegrator1_DSTATE[0] += 0.002F * rtb_Sum1_dw_idx_0;

  /* Update for DiscreteIntegrator: '<S86>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_l[1] += 0.002F * tmp_1[1];

  /* Update for DiscreteIntegrator: '<S87>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_n[1] += 0.002F * rtb_Multiply4_k_idx_0;

  /* Update for DiscreteIntegrator: '<S87>/Discrete-Time Integrator1' */
  Plant_DW.DiscreteTimeIntegrator1_DSTATE[1] += 0.002F * rtb_Product8;

  /* Update for DiscreteIntegrator: '<S86>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_l[2] += 0.002F * tmp_1[2];

  /* Update for DiscreteIntegrator: '<S87>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_n[2] += 0.002F * rtb_Sum_b0;

  /* Update for DiscreteIntegrator: '<S87>/Discrete-Time Integrator1' */
  Plant_DW.DiscreteTimeIntegrator1_DSTATE[2] += 0.002F * rtb_Sum1_dw_idx_2;
  Plant_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
    rtb_FixPtRelationalOperator_k;

  /* End of Outputs for SubSystem: '<Root>/Kinematic_Equation' */

  /* Outputs for Atomic SubSystem: '<Root>/Bus_Constructor' */
  /* Sqrt: '<S49>/Sqrt' incorporates:
   *  Math: '<S49>/Square'
   *  Sum: '<S49>/Sum of Elements'
   */
  rtb_Gain_kz = sqrtf(((rtb_MathFunction1_k * rtb_MathFunction1_k + rtb_Gain3 *
                        rtb_Gain3) + rtb_Square_idx_2 * rtb_Square_idx_2) +
                      rtb_Switch_idx_0 * rtb_Switch_idx_0);

  /* Product: '<S45>/Divide' */
  rtb_Switch_idx_3 = rtb_MathFunction1_k / rtb_Gain_kz;
  rtb_Gain_e_tmp_4 = rtb_Gain3 / rtb_Gain_kz;
  rtb_Sum_l_tmp = rtb_Square_idx_2 / rtb_Gain_kz;
  rtb_Sum_ah_idx_2 = rtb_Switch_idx_0 / rtb_Gain_kz;

  /* Math: '<S46>/Square' incorporates:
   *  Math: '<S47>/Square'
   *  Math: '<S48>/Square'
   *  Product: '<S45>/Divide'
   */
  rtb_Gain_kz = rtb_Switch_idx_3 * rtb_Switch_idx_3;

  /* Math: '<S46>/Square2' incorporates:
   *  Math: '<S47>/Square2'
   *  Math: '<S48>/Square2'
   *  Product: '<S45>/Divide'
   */
  rtb_Divide_h_idx_1 = rtb_Sum_l_tmp * rtb_Sum_l_tmp;

  /* Math: '<S46>/Square1' incorporates:
   *  Math: '<S47>/Square1'
   *  Math: '<S48>/Square1'
   *  Product: '<S45>/Divide'
   */
  rtb_Divide_h_idx_2 = rtb_Gain_e_tmp_4 * rtb_Gain_e_tmp_4;

  /* Math: '<S46>/Square3' incorporates:
   *  Math: '<S47>/Square3'
   *  Math: '<S48>/Square3'
   *  Product: '<S45>/Divide'
   */
  rtb_Divide_h_idx_3 = rtb_Sum_ah_idx_2 * rtb_Sum_ah_idx_2;

  /* Sum: '<S46>/Subtract' incorporates:
   *  Math: '<S46>/Square'
   *  Math: '<S46>/Square1'
   *  Math: '<S46>/Square2'
   *  Math: '<S46>/Square3'
   *  Sum: '<S46>/Add'
   *  Sum: '<S46>/Add1'
   */
  rtb_MatrixConcatenate1[0] = (rtb_Gain_kz + rtb_Divide_h_idx_2) -
    (rtb_Divide_h_idx_1 + rtb_Divide_h_idx_3);

  /* Product: '<S46>/Multiply' incorporates:
   *  Product: '<S45>/Divide'
   *  Product: '<S47>/Multiply'
   */
  rtb_Divide_h_idx_0 = rtb_Gain_e_tmp_4 * rtb_Sum_l_tmp;

  /* Product: '<S46>/Multiply1' incorporates:
   *  Product: '<S45>/Divide'
   *  Product: '<S47>/Multiply1'
   */
  rtb_Gain_e_tmp_2 = rtb_Switch_idx_3 * rtb_Sum_ah_idx_2;

  /* Gain: '<S46>/Gain' incorporates:
   *  Product: '<S46>/Multiply'
   *  Product: '<S46>/Multiply1'
   *  Sum: '<S46>/Subtract1'
   */
  rtb_MatrixConcatenate1[1] = (rtb_Divide_h_idx_0 - rtb_Gain_e_tmp_2) * 2.0F;

  /* Product: '<S46>/Multiply2' incorporates:
   *  Product: '<S45>/Divide'
   *  Product: '<S48>/Multiply'
   */
  rtb_Gain_e_tmp_5 = rtb_Gain_e_tmp_4 * rtb_Sum_ah_idx_2;

  /* Product: '<S46>/Multiply3' incorporates:
   *  Product: '<S45>/Divide'
   *  Product: '<S48>/Multiply1'
   */
  rtb_Gain_e_tmp_6 = rtb_Switch_idx_3 * rtb_Sum_l_tmp;

  /* Gain: '<S46>/Gain1' incorporates:
   *  Product: '<S46>/Multiply2'
   *  Product: '<S46>/Multiply3'
   *  Sum: '<S46>/Add2'
   */
  rtb_MatrixConcatenate1[2] = (rtb_Gain_e_tmp_5 + rtb_Gain_e_tmp_6) * 2.0F;

  /* Gain: '<S47>/Gain' incorporates:
   *  Sum: '<S47>/Add3'
   */
  rtb_MatrixConcatenate1[3] = (rtb_Divide_h_idx_0 + rtb_Gain_e_tmp_2) * 2.0F;

  /* Sum: '<S47>/Subtract' incorporates:
   *  Sum: '<S47>/Add'
   *  Sum: '<S47>/Add1'
   */
  rtb_MatrixConcatenate1[4] = (rtb_Gain_kz + rtb_Divide_h_idx_1) -
    (rtb_Divide_h_idx_2 + rtb_Divide_h_idx_3);

  /* Product: '<S47>/Multiply2' incorporates:
   *  Product: '<S45>/Divide'
   *  Product: '<S48>/Multiply2'
   */
  rtb_Divide_h_idx_0 = rtb_Sum_l_tmp * rtb_Sum_ah_idx_2;

  /* Product: '<S47>/Multiply3' incorporates:
   *  Product: '<S45>/Divide'
   *  Product: '<S48>/Multiply3'
   */
  rtb_Gain_e_tmp_2 = rtb_Switch_idx_3 * rtb_Gain_e_tmp_4;

  /* Gain: '<S47>/Gain1' incorporates:
   *  Product: '<S47>/Multiply2'
   *  Product: '<S47>/Multiply3'
   *  Sum: '<S47>/Subtract1'
   */
  rtb_MatrixConcatenate1[5] = (rtb_Divide_h_idx_0 - rtb_Gain_e_tmp_2) * 2.0F;

  /* Gain: '<S48>/Gain' incorporates:
   *  Sum: '<S48>/Subtract2'
   */
  rtb_MatrixConcatenate1[6] = (rtb_Gain_e_tmp_5 - rtb_Gain_e_tmp_6) * 2.0F;

  /* Gain: '<S48>/Gain1' incorporates:
   *  Sum: '<S48>/Add2'
   */
  rtb_MatrixConcatenate1[7] = (rtb_Divide_h_idx_0 + rtb_Gain_e_tmp_2) * 2.0F;

  /* Sum: '<S48>/Subtract' incorporates:
   *  Sum: '<S48>/Add'
   *  Sum: '<S48>/Add1'
   */
  rtb_MatrixConcatenate1[8] = (rtb_Gain_kz + rtb_Divide_h_idx_3) -
    (rtb_Divide_h_idx_2 + rtb_Divide_h_idx_1);

  /* Math: '<S2>/Square' */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_f[3 * i] = rtb_MatrixConcatenate1[i];
    rtb_VectorConcatenate_f[1 + 3 * i] = rtb_MatrixConcatenate1[i + 3];
    rtb_VectorConcatenate_f[2 + 3 * i] = rtb_MatrixConcatenate1[i + 6];
  }

  /* End of Math: '<S2>/Square' */

  /* BusAssignment: '<S2>/Bus Assignment2' incorporates:
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S2>/Constant5'
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S2>/TmpHiddenBufferAtBus Assignment2Inport1'
   */
  Plant_Y.Extended_States = Plant_rtZExtended_States_Bus;
  Plant_Y.Extended_States.temprature = 25.0F;
  for (i = 0; i < 8; i++) {
    Plant_Y.Extended_States.prop_vel[i] = 0.0F;
  }

  for (i = 0; i < 9; i++) {
    Plant_Y.Extended_States.M_BO[i] = rtb_MatrixConcatenate1[i];
    Plant_Y.Extended_States.M_OB[i] = rtb_VectorConcatenate_f[i];
  }

  Plant_Y.Extended_States.quat[0] = rtb_MathFunction1_k;
  Plant_Y.Extended_States.quat[1] = rtb_Gain3;
  Plant_Y.Extended_States.quat[2] = rtb_Square_idx_2;
  Plant_Y.Extended_States.quat[3] = rtb_Switch_idx_0;
  Plant_Y.Extended_States.Va = rtb_Va_B[0];

  /* End of BusAssignment: '<S2>/Bus Assignment2' */

  /* Delay: '<S44>/Delay1' incorporates:
   *  Constant: '<S44>/Constant1'
   *  Constant: '<S44>/Constant2'
   *  Constant: '<S44>/Constant3'
   *  SignalConversion: '<S44>/TmpSignal ConversionAtDelay1Inport2'
   */
  if (Plant_DW.icLoad != 0) {
    Plant_DW.Delay1_DSTATE_c[0] = PLANT_PARAM.LAT_0;
    Plant_DW.Delay1_DSTATE_c[1] = PLANT_PARAM.LON_0;
    Plant_DW.Delay1_DSTATE_c[2] = PLANT_PARAM.ALT_0;
  }

  /* Trigonometry: '<S50>/Trigonometric Function1' incorporates:
   *  Delay: '<S44>/Delay1'
   *  Trigonometry: '<S50>/Trigonometric Function2'
   */
  rtb_TrigonometricFunction2 = cos(Plant_DW.Delay1_DSTATE_c[0]);

  /* Trigonometry: '<S50>/Trigonometric Function' incorporates:
   *  Delay: '<S44>/Delay1'
   */
  rtb_SumofElements = sin(Plant_DW.Delay1_DSTATE_c[0]);

  /* Sum: '<S50>/Subtract' incorporates:
   *  Constant: '<S50>/c'
   *  Math: '<S50>/u^2'
   *  Product: '<S50>/Product'
   */
  rtb_SumofElements = 1.0 - rtb_SumofElements * rtb_SumofElements *
    Plant_ConstB.Product1;

  /* Math: '<S50>/sqrt'
   *
   * About '<S50>/sqrt':
   *  Operator: sqrt
   */
  if (rtb_SumofElements < 0.0) {
    rtb_SumofElements = -sqrt(fabs(rtb_SumofElements));
  } else {
    rtb_SumofElements = sqrt(rtb_SumofElements);
  }

  /* End of Math: '<S50>/sqrt' */

  /* Product: '<S50>/Divide' incorporates:
   *  Constant: '<S50>/earth_radius'
   */
  rtb_SumofElements = 6.378137E+6 / rtb_SumofElements;

  /* Product: '<S50>/Product3' incorporates:
   *  Constant: '<S50>/constant2'
   *  Math: '<S50>/u^1'
   *  Product: '<S50>/Product2'
   *  Sum: '<S50>/Subtract2'
   *  Trigonometry: '<S50>/Trigonometric Function1'
   */
  rtb_SumofElements1 = (1.0 - rtb_TrigonometricFunction2 *
                        rtb_TrigonometricFunction2 * Plant_ConstB.Product1) *
    rtb_SumofElements;

  /* Sum: '<S50>/Add' incorporates:
   *  Delay: '<S44>/Delay1'
   */
  rtb_SumofElements1 += Plant_DW.Delay1_DSTATE_c[2];

  /* Sum: '<S50>/Add1' incorporates:
   *  Delay: '<S44>/Delay1'
   */
  rtb_SumofElements += Plant_DW.Delay1_DSTATE_c[2];

  /* Product: '<S50>/Product4' */
  rtb_SumofElements *= rtb_TrigonometricFunction2;

  /* Signum: '<S51>/Sign' */
  if (rtb_SumofElements1 < 0.0) {
    /* Switch: '<S51>/Switch' */
    rtb_Divide2[0] = -1.0;
    rtb_Cl_xA = -1.0;
  } else if (rtb_SumofElements1 > 0.0) {
    /* Switch: '<S51>/Switch' */
    rtb_Divide2[0] = 1.0;
    rtb_Cl_xA = 1.0;
  } else {
    /* Switch: '<S51>/Switch' */
    rtb_Divide2[0] = rtb_SumofElements1;
    rtb_Cl_xA = rtb_SumofElements1;
  }

  /* Switch: '<S51>/Switch' incorporates:
   *  Constant: '<S51>/Constant'
   */
  if (rtb_Cl_xA == 0.0) {
    rtb_Divide2[0] = 1.0;
  }

  /* Signum: '<S51>/Sign' */
  if (rtb_SumofElements < 0.0) {
    rtb_Cl_xA = -1.0;
    rtb_TrigonometricFunction2 = -1.0;
  } else if (rtb_SumofElements > 0.0) {
    rtb_Cl_xA = 1.0;
    rtb_TrigonometricFunction2 = 1.0;
  } else {
    rtb_Cl_xA = rtb_SumofElements;
    rtb_TrigonometricFunction2 = rtb_SumofElements;
  }

  /* Switch: '<S51>/Switch' incorporates:
   *  Constant: '<S51>/Constant'
   */
  if (rtb_TrigonometricFunction2 == 0.0) {
    rtb_Cl_xA = 1.0;
  }

  /* BusAssignment: '<S2>/Bus Assignment1' incorporates:
   *  BusAssignment: '<S2>/Bus Assignment'
   *  Constant: '<S2>/Constant'
   *  Delay: '<Root>/Delay'
   */
  Plant_Y.Plant_States = Plant_rtZPlant_States_Bus;

  /* Outputs for Atomic SubSystem: '<Root>/Kinematic_Equation' */
  /* BusAssignment: '<S2>/Bus Assignment' incorporates:
   *  BusAssignment: '<S2>/Bus Assignment1'
   *  Constant: '<S91>/Constant'
   *  Constant: '<S91>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Math: '<S91>/Square'
   *  Product: '<S91>/Multiply'
   *  Product: '<S91>/Multiply1'
   *  Product: '<S91>/Multiply2'
   *  Product: '<S91>/Multiply3'
   *  Product: '<S97>/Divide'
   *  Sum: '<S91>/Add'
   *  Sum: '<S91>/Add1'
   *  Sum: '<S91>/Subtract2'
   *  Trigonometry: '<S91>/Atan2'
   */
  Plant_Y.Plant_States.phi = atan2f((rtb_magnitude_gauss * rtb_Add_ow +
    rtb_Switch_idx_1 * rtb_Switch_idx_2) * 2.0F, 1.0F - (rtb_Add_ow * rtb_Add_ow
    + rtb_Square2_b) * 2.0F);

  /* End of Outputs for SubSystem: '<Root>/Bus_Constructor' */

  /* Saturate: '<S91>/Saturation' */
  if (rtb_Square_l > 1.0F) {
    rtb_Square_l = 1.0F;
  } else {
    if (rtb_Square_l < -1.0F) {
      rtb_Square_l = -1.0F;
    }
  }

  /* End of Saturate: '<S91>/Saturation' */

  /* Outputs for Atomic SubSystem: '<Root>/Bus_Constructor' */
  /* BusAssignment: '<S2>/Bus Assignment' incorporates:
   *  BusAssignment: '<S2>/Bus Assignment1'
   *  Constant: '<S91>/Constant'
   *  Constant: '<S91>/Constant1'
   *  Delay: '<Root>/Delay'
   *  Math: '<S91>/Square2'
   *  Product: '<S91>/Multiply10'
   *  Product: '<S91>/Multiply7'
   *  Product: '<S91>/Multiply8'
   *  Product: '<S91>/Multiply9'
   *  Product: '<S97>/Divide'
   *  Sum: '<S91>/Add2'
   *  Sum: '<S91>/Add3'
   *  Sum: '<S91>/Subtract1'
   *  Trigonometry: '<S91>/Asin'
   *  Trigonometry: '<S91>/Atan1'
   */
  Plant_Y.Plant_States.theta = asinf(rtb_Square_l);
  Plant_Y.Plant_States.psi = atan2f((rtb_magnitude_gauss * rtb_Switch_idx_2 +
    rtb_Add_ow * rtb_Switch_idx_1) * 2.0F, 1.0F - (rtb_Switch_idx_2 *
    rtb_Switch_idx_2 + rtb_Square2_b) * 2.0F);

  /* End of Outputs for SubSystem: '<Root>/Kinematic_Equation' */
  Plant_Y.Plant_States.rot_x_B = rtb_Square_o5[0];
  Plant_Y.Plant_States.rot_y_B = rtb_Square_o5[1];
  Plant_Y.Plant_States.rot_z_B = rtb_Square_o5[2];
  Plant_Y.Plant_States.acc_x_O = rtb_Multiply4_k_idx_1;
  Plant_Y.Plant_States.acc_y_O = rtb_Multiply4_k_idx_0;
  Plant_Y.Plant_States.acc_z_O = rtb_Sum_b0;
  Plant_Y.Plant_States.vel_x_O = rtb_Sum1_dw_idx_0;
  Plant_Y.Plant_States.vel_y_O = rtb_Product8;
  Plant_Y.Plant_States.vel_z_O = rtb_Sum1_dw_idx_2;

  /* Abs: '<S51>/Abs' */
  rtb_TrigonometricFunction2 = fabs(rtb_SumofElements1);

  /* Saturate: '<S51>/Saturation' */
  if (rtb_TrigonometricFunction2 > 1.0E+8) {
    rtb_TrigonometricFunction2 = 1.0E+8;
  } else {
    if (rtb_TrigonometricFunction2 < 1.0E-6) {
      rtb_TrigonometricFunction2 = 1.0E-6;
    }
  }

  /* Sum: '<S44>/Add' incorporates:
   *  DataTypeConversion: '<S44>/Data Type Conversion'
   *  Delay: '<S44>/Delay'
   *  Delay: '<S44>/Delay1'
   *  Product: '<S44>/Divide'
   *  Product: '<S51>/Product'
   *  Sum: '<S44>/Subtract'
   */
  rtb_SumofElements1 = 1.0 / (rtb_TrigonometricFunction2 * rtb_Divide2[0]) *
    (rtb_Sum1_a[0] - Plant_DW.Delay_DSTATE_f[0]) + Plant_DW.Delay1_DSTATE_c[0];

  /* Abs: '<S51>/Abs' */
  rtb_TrigonometricFunction2 = fabs(rtb_SumofElements);

  /* Saturate: '<S51>/Saturation' */
  if (rtb_TrigonometricFunction2 > 1.0E+8) {
    rtb_TrigonometricFunction2 = 1.0E+8;
  } else {
    if (rtb_TrigonometricFunction2 < 1.0E-6) {
      rtb_TrigonometricFunction2 = 1.0E-6;
    }
  }

  /* Sum: '<S44>/Add' incorporates:
   *  DataTypeConversion: '<S44>/Data Type Conversion'
   *  Delay: '<S44>/Delay'
   *  Delay: '<S44>/Delay1'
   *  Product: '<S44>/Divide'
   *  Product: '<S51>/Product'
   *  Sum: '<S44>/Subtract'
   */
  rtb_SumofElements = 1.0 / (rtb_TrigonometricFunction2 * rtb_Cl_xA) *
    (rtb_Sum1_a[1] - Plant_DW.Delay_DSTATE_f[1]) + Plant_DW.Delay1_DSTATE_c[1];
  rtb_Cl_xA = -(rtb_Sum1_a[2] - Plant_DW.Delay_DSTATE_f[2]) +
    Plant_DW.Delay1_DSTATE_c[2];

  /* BusAssignment: '<S2>/Bus Assignment1' incorporates:
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant2'
   *  Constant: '<S2>/Constant3'
   *  Delay: '<Root>/Delay'
   *  Delay: '<S42>/Delay'
   *  Gain: '<S2>/Gain'
   */
  Plant_Y.Plant_States.x_R = rtb_Sum1_a[0];
  Plant_Y.Plant_States.y_R = rtb_Sum1_a[1];
  Plant_Y.Plant_States.h_R = -rtb_Sum1_a[2];
  Plant_Y.Plant_States.lat = rtb_SumofElements1;
  Plant_Y.Plant_States.lon = rtb_SumofElements;
  Plant_Y.Plant_States.alt = rtb_Cl_xA;
  Plant_Y.Plant_States.lat_0 = PLANT_PARAM.LAT_0;
  Plant_Y.Plant_States.lon_0 = PLANT_PARAM.LON_0;
  Plant_Y.Plant_States.alt_0 = PLANT_PARAM.ALT_0;
  Plant_Y.Plant_States.timestamp = Plant_DW.Delay_DSTATE_h;

  /* Sum: '<S42>/Sum' incorporates:
   *  Constant: '<S42>/dt'
   *  Delay: '<S42>/Delay'
   */
  Plant_DW.Delay_DSTATE_h += PLANT_EXPORT.period;

  /* Update for Delay: '<S44>/Delay1' */
  Plant_DW.icLoad = 0U;

  /* Update for Delay: '<S44>/Delay' incorporates:
   *  DataTypeConversion: '<S44>/Data Type Conversion'
   */
  Plant_DW.Delay_DSTATE_f[0] = rtb_Sum1_a[0];

  /* Update for Delay: '<S44>/Delay1' */
  Plant_DW.Delay1_DSTATE_c[0] = rtb_SumofElements1;

  /* Update for Delay: '<S44>/Delay' incorporates:
   *  DataTypeConversion: '<S44>/Data Type Conversion'
   */
  Plant_DW.Delay_DSTATE_f[1] = rtb_Sum1_a[1];

  /* Update for Delay: '<S44>/Delay1' */
  Plant_DW.Delay1_DSTATE_c[1] = rtb_SumofElements;

  /* Update for Delay: '<S44>/Delay' incorporates:
   *  DataTypeConversion: '<S44>/Data Type Conversion'
   */
  Plant_DW.Delay_DSTATE_f[2] = rtb_Sum1_a[2];

  /* Update for Delay: '<S44>/Delay1' */
  Plant_DW.Delay1_DSTATE_c[2] = rtb_Cl_xA;

  /* End of Outputs for SubSystem: '<Root>/Bus_Constructor' */

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_Model' */
  /* Outputs for Atomic SubSystem: '<S6>/Sensor_Airspeed' */
  /* BusAssignment: '<S125>/Bus Assignment' incorporates:
   *  Constant: '<S125>/Constant'
   *  Delay: '<Root>/Delay'
   *  Gain: '<S124>/Gain'
   *  Math: '<S124>/Square'
   *  Memory: '<S118>/Memory1'
   */
  rtb_BusAssignment_f = Plant_rtZAirSpeed_Bus;
  rtb_BusAssignment_f.timestamp = Plant_DW.Memory1_PreviousInput;
  rtb_BusAssignment_f.diff_pressure = Plant_Y.Extended_States.Va *
    Plant_Y.Extended_States.Va * 0.6125F;

  /* RateTransition: '<S125>/Rate Transition' */
  if (Plant_M->Timing.TaskCounters.TID[1] == 0) {
    Plant_B.RateTransition_e = rtb_BusAssignment_f;
  }

  /* End of RateTransition: '<S125>/Rate Transition' */
  /* End of Outputs for SubSystem: '<S6>/Sensor_Airspeed' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_Barometer' */
  /* Saturate: '<S130>/Limit  altitude  to troposhere' incorporates:
   *  DataTypeConversion: '<S128>/Data Type Conversion'
   *  Delay: '<Root>/Delay'
   */
  if ((real32_T)Plant_Y.Plant_States.alt > 11000.0F) {
    rtb_Switch_idx_3 = 11000.0F;
  } else if ((real32_T)Plant_Y.Plant_States.alt < 0.0F) {
    rtb_Switch_idx_3 = 0.0F;
  } else {
    rtb_Switch_idx_3 = (real32_T)Plant_Y.Plant_States.alt;
  }

  /* End of Saturate: '<S130>/Limit  altitude  to troposhere' */

  /* Sum: '<S130>/Sum1' incorporates:
   *  Constant: '<S130>/Sea Level  Temperature'
   *  Gain: '<S130>/Lapse Rate'
   */
  rtb_Sum1_dw_idx_0 = 288.15F - 0.0065F * rtb_Switch_idx_3;

  /* Sum: '<S130>/Sum' incorporates:
   *  Constant: '<S130>/Altitude of Troposphere'
   *  DataTypeConversion: '<S128>/Data Type Conversion'
   *  Delay: '<Root>/Delay'
   */
  rtb_MathFunction1_k = 11000.0F - (real32_T)Plant_Y.Plant_States.alt;

  /* Saturate: '<S130>/Limit  altitude  to Stratosphere' incorporates:
   *  Constant: '<S130>/Altitude of Troposphere'
   *  DataTypeConversion: '<S128>/Data Type Conversion'
   *  Delay: '<Root>/Delay'
   *  Sum: '<S130>/Sum'
   */
  if (11000.0F - (real32_T)Plant_Y.Plant_States.alt > 0.0F) {
    rtb_MathFunction1_k = 0.0F;
  } else {
    if (11000.0F - (real32_T)Plant_Y.Plant_States.alt < -9000.0F) {
      rtb_MathFunction1_k = -9000.0F;
    }
  }

  /* End of Saturate: '<S130>/Limit  altitude  to Stratosphere' */

  /* Product: '<S130>/Product2' incorporates:
   *  Constant: '<S130>/Constant'
   *  Gain: '<S130>/1//T0'
   *  Gain: '<S130>/P0'
   *  Gain: '<S130>/g//R'
   *  Math: '<S130>/(T//T0)^(g//LR) '
   *  Math: '<S130>/Stratosphere Model'
   *  Product: '<S130>/Product1'
   *
   * About '<S130>/Stratosphere Model':
   *  Operator: exp
   */
  rtb_Product8 = powf(0.00347041478F * rtb_Sum1_dw_idx_0, 5.25587559F) *
    101325.0F * expf(1.0F / rtb_Sum1_dw_idx_0 * (0.0341631919F *
    rtb_MathFunction1_k));

  /* S-Function (sdsprandsrc2): '<S132>/Random Source' */
  RandSrc_GZ_R(&rtb_MathFunction1_k, &Plant_ConstP.pooled27, 1,
               &Plant_ConstP.pooled38, 1, Plant_DW.RandomSource_STATE_DWORK_fn,
               1, 1);

  /* BusAssignment: '<S127>/Bus Assignment' incorporates:
   *  Constant: '<S127>/Constant2'
   *  DataTypeConversion: '<S127>/Data Type Conversion1'
   *  Memory: '<S118>/Memory1'
   *  Saturate: '<S129>/Saturation'
   *  Sum: '<S127>/Sum1'
   *  Sum: '<S129>/Add'
   */
  rtb_BusAssignment_c.timestamp = Plant_DW.Memory1_PreviousInput;
  rtb_BusAssignment_c.pressure = rtb_Product8 + rtb_MathFunction1_k;
  rtb_BusAssignment_c.temperature = (real32_T)(rtb_Sum1_dw_idx_0 - 273.15);

  /* RateTransition: '<S127>/Rate Transition' */
  if (Plant_M->Timing.TaskCounters.TID[2] == 0) {
    Plant_B.RateTransition_p = rtb_BusAssignment_c;
  }

  /* End of RateTransition: '<S127>/Rate Transition' */
  /* End of Outputs for SubSystem: '<S6>/Sensor_Barometer' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_GPS' */
  /* Trigonometry: '<S145>/Sin' incorporates:
   *  Delay: '<S138>/Delay'
   */
  rtb_SumofElements = sin(Plant_DW.Delay_DSTATE[0]);

  /* Math: '<S145>/Square1' */
  rtb_SumofElements *= rtb_SumofElements;

  /* Product: '<S145>/Multiply1' incorporates:
   *  Product: '<S145>/Multiply'
   */
  rtb_Cl_xA = Plant_ConstB.ff * rtb_SumofElements;

  /* Product: '<S145>/Divide' incorporates:
   *  Constant: '<S145>/Constant'
   *  Constant: '<S145>/R'
   *  Sqrt: '<S145>/Sqrt'
   *  Sum: '<S145>/Sum1'
   */
  rtb_SumofElements = 6.378137E+6 / sqrt(1.0 - rtb_Cl_xA);

  /* Trigonometry: '<S145>/Cos' incorporates:
   *  Delay: '<S138>/Delay'
   */
  rtb_SumofElements1 = cos(Plant_DW.Delay_DSTATE[0]);

  /* S-Function (sdsprandsrc2): '<S141>/Random Source' */
  RandSrc_GZ_R(rtb_RandomSource, &Plant_ConstP.pooled27, 1,
               Plant_ConstP.RandomSource_VarianceRTP, 3,
               Plant_DW.RandomSource_STATE_DWORK_f2, 3, 1);

  /* Sum: '<S139>/Sum2' incorporates:
   *  Constant: '<S145>/Constant1'
   *  Delay: '<S138>/Delay'
   *  Product: '<S142>/Divide2'
   *  Product: '<S145>/Multiply1'
   *  Product: '<S145>/Multiply2'
   *  Product: '<S145>/Product3'
   *  Sum: '<S145>/Sum2'
   */
  rtb_Cl_xA = rtb_RandomSource[0] / (1.0 / (1.0 - rtb_Cl_xA) * Plant_ConstB.Sum4
    * rtb_SumofElements) + Plant_DW.Delay_DSTATE[0];
  rtb_TrigonometricFunction2 = rtb_RandomSource[1] / (rtb_SumofElements *
    rtb_SumofElements1) + Plant_DW.Delay_DSTATE[1];
  rtb_Cm = rtb_RandomSource[2] / -1.0 + Plant_DW.Delay_DSTATE[2];

  /* S-Function (sdsprandsrc2): '<S141>/Random Source1' */
  RandSrc_GZ_R(rtb_RandomSource1, &Plant_ConstP.pooled27, 1,
               Plant_ConstP.RandomSource1_VarianceRTP, 3,
               Plant_DW.RandomSource1_STATE_DWORK, 3, 1);

  /* Sum: '<S139>/Sum1' incorporates:
   *  Delay: '<S138>/Delay1'
   */
  rtb_Va_B[0] = rtb_RandomSource1[0] + Plant_DW.Delay1_DSTATE_j[0];
  rtb_Va_B[1] = rtb_RandomSource1[1] + Plant_DW.Delay1_DSTATE_j[1];
  rtb_Va_B[2] = rtb_RandomSource1[2] + Plant_DW.Delay1_DSTATE_j[2];

  /* DiscreteFir: '<S144>/Discrete FIR Filter' */
  rtb_VectorConcatenate_j[0] = rtb_Va_B[0] * 0.5F +
    Plant_DW.DiscreteFIRFilter_states_i[0] * 0.5F;
  rtb_VectorConcatenate_j[1] = rtb_Va_B[1] * 0.5F +
    Plant_DW.DiscreteFIRFilter_states_i[1] * 0.5F;

  /* Gain: '<S133>/Gain6' incorporates:
   *  Math: '<S140>/Math Function'
   *  Product: '<S140>/Matrix Multiply'
   *  Sqrt: '<S140>/Sqrt'
   *  Switch: '<S140>/Switch'
   */
  rtb_SumofElements = fmod(floor(sqrtf(rtb_RandomSource[0] * rtb_RandomSource[0]
    + rtb_RandomSource[1] * rtb_RandomSource[1]) * 1000.0), 4.294967296E+9);

  /* DataTypeConversion: '<S133>/Data Type Conversion' incorporates:
   *  Delay: '<S139>/Delay1'
   */
  rtb_SumofElements1 = fmod(floor(Plant_DW.Delay1_DSTATE[0]), 256.0);

  /* Gain: '<S133>/Gain4' incorporates:
   *  DiscreteFir: '<S143>/Discrete FIR Filter'
   */
  rtb_Divide_e_idx_1 = fmod(floor((rtb_Cm * 0.5 +
    Plant_DW.DiscreteFIRFilter_states[2] * 0.5) * 1000.0), 4.294967296E+9);
  i = rtb_Divide_e_idx_1 < 0.0 ? -(int32_T)(uint32_T)-rtb_Divide_e_idx_1 :
    (int32_T)(uint32_T)rtb_Divide_e_idx_1;

  /* Gain: '<S133>/Gain5' incorporates:
   *  Math: '<S140>/Math Function2'
   *  Product: '<S140>/Matrix Multiply2'
   *  Sqrt: '<S140>/Sqrt2'
   *  Switch: '<S140>/Switch1'
   */
  rtb_Divide_e_idx_1 = fmod(floor(sqrtf(rtb_RandomSource[2] * rtb_RandomSource[2])
    * 1000.0), 4.294967296E+9);

  /* BusAssignment: '<S133>/Bus Assignment' incorporates:
   *  Constant: '<S133>/Constant10'
   *  Constant: '<S133>/Constant11'
   *  Constant: '<S133>/Constant12'
   *  Constant: '<S133>/Constant2'
   *  Constant: '<S133>/Constant3'
   *  Constant: '<S133>/Constant4'
   *  Constant: '<S133>/Constant5'
   *  Constant: '<S133>/Constant6'
   *  Constant: '<S133>/Constant7'
   *  Constant: '<S133>/Constant8'
   *  Constant: '<S133>/Constant9'
   *  DataTypeConversion: '<S133>/Data Type Conversion'
   */
  rtb_BusAssignment_e.iTOW = 1U;
  rtb_BusAssignment_e.year = 2020U;
  rtb_BusAssignment_e.month = 1U;
  rtb_BusAssignment_e.day = 1U;
  rtb_BusAssignment_e.hour = 0U;
  rtb_BusAssignment_e.min = 0U;
  rtb_BusAssignment_e.sec = 0U;
  rtb_BusAssignment_e.valid = 1U;
  rtb_BusAssignment_e.tAcc = 0U;
  rtb_BusAssignment_e.nano = 0;
  rtb_BusAssignment_e.fixType = (uint8_T)(rtb_SumofElements1 < 0.0 ? (int32_T)
    (uint8_T)-(int8_T)(uint8_T)-rtb_SumofElements1 : (int32_T)(uint8_T)
    rtb_SumofElements1);
  rtb_BusAssignment_e.flags = 0U;
  rtb_BusAssignment_e.reserved1 = 0U;

  /* DataTypeConversion: '<S133>/Data Type Conversion1' incorporates:
   *  Delay: '<S139>/Delay'
   */
  rtb_SumofElements1 = fmod(floor(Plant_DW.Delay_DSTATE_b[0]), 256.0);

  /* BusAssignment: '<S133>/Bus Assignment' incorporates:
   *  DataTypeConversion: '<S133>/Data Type Conversion1'
   */
  rtb_BusAssignment_e.numSV = (uint8_T)(rtb_SumofElements1 < 0.0 ? (int32_T)
    (uint8_T)-(int8_T)(uint8_T)-rtb_SumofElements1 : (int32_T)(uint8_T)
    rtb_SumofElements1);

  /* Gain: '<S133>/Gain' incorporates:
   *  DiscreteFir: '<S143>/Discrete FIR Filter'
   *  Gain: '<S133>/Gain2'
   */
  rtb_SumofElements1 = fmod(floor((rtb_Cl_xA * 0.5 +
    Plant_DW.DiscreteFIRFilter_states[0] * 0.5) * 57.295779513082323 * 1.0E+7),
    4.294967296E+9);

  /* BusAssignment: '<S133>/Bus Assignment' incorporates:
   *  Gain: '<S133>/Gain'
   */
  rtb_BusAssignment_e.lon = rtb_SumofElements1 < 0.0 ? -(int32_T)(uint32_T)
    -rtb_SumofElements1 : (int32_T)(uint32_T)rtb_SumofElements1;

  /* Gain: '<S133>/Gain1' incorporates:
   *  DiscreteFir: '<S143>/Discrete FIR Filter'
   *  Gain: '<S133>/Gain3'
   */
  rtb_SumofElements1 = fmod(floor((rtb_TrigonometricFunction2 * 0.5 +
    Plant_DW.DiscreteFIRFilter_states[1] * 0.5) * 57.295779513082323 * 1.0E+7),
    4.294967296E+9);

  /* BusAssignment: '<S133>/Bus Assignment' incorporates:
   *  Gain: '<S133>/Gain1'
   *  Gain: '<S133>/Gain5'
   *  Gain: '<S133>/Gain6'
   */
  rtb_BusAssignment_e.lat = rtb_SumofElements1 < 0.0 ? -(int32_T)(uint32_T)
    -rtb_SumofElements1 : (int32_T)(uint32_T)rtb_SumofElements1;
  rtb_BusAssignment_e.height = i;
  rtb_BusAssignment_e.hMSL = i;
  rtb_BusAssignment_e.hAcc = rtb_SumofElements < 0.0 ? (uint32_T)-(int32_T)
    (uint32_T)-rtb_SumofElements : (uint32_T)rtb_SumofElements;
  rtb_BusAssignment_e.vAcc = rtb_Divide_e_idx_1 < 0.0 ? (uint32_T)-(int32_T)
    (uint32_T)-rtb_Divide_e_idx_1 : (uint32_T)rtb_Divide_e_idx_1;

  /* Gain: '<S133>/Gain7' */
  rtb_Switch_idx_3 = fmodf(floorf(1000.0F * rtb_VectorConcatenate_j[0]),
    4.2949673E+9F);

  /* BusAssignment: '<S133>/Bus Assignment' incorporates:
   *  Gain: '<S133>/Gain7'
   */
  rtb_BusAssignment_e.velN = rtb_Switch_idx_3 < 0.0F ? -(int32_T)(uint32_T)
    -rtb_Switch_idx_3 : (int32_T)(uint32_T)rtb_Switch_idx_3;

  /* Gain: '<S133>/Gain8' */
  rtb_Switch_idx_3 = fmodf(floorf(1000.0F * rtb_VectorConcatenate_j[1]),
    4.2949673E+9F);

  /* BusAssignment: '<S133>/Bus Assignment' incorporates:
   *  Gain: '<S133>/Gain8'
   */
  rtb_BusAssignment_e.velE = rtb_Switch_idx_3 < 0.0F ? -(int32_T)(uint32_T)
    -rtb_Switch_idx_3 : (int32_T)(uint32_T)rtb_Switch_idx_3;

  /* Gain: '<S133>/Gain9' incorporates:
   *  DiscreteFir: '<S144>/Discrete FIR Filter'
   */
  rtb_Switch_idx_3 = fmodf(floorf((rtb_Va_B[2] * 0.5F +
    Plant_DW.DiscreteFIRFilter_states_i[2] * 0.5F) * 1000.0F), 4.2949673E+9F);

  /* BusAssignment: '<S133>/Bus Assignment' incorporates:
   *  Constant: '<S133>/Constant15'
   *  Gain: '<S133>/Gain11'
   *  Gain: '<S133>/Gain9'
   *  Math: '<S135>/Math Function'
   *  Math: '<S135>/Math Function1'
   *  Saturate: '<S135>/Saturation'
   *  Sqrt: '<S135>/Sqrt'
   *  Sum: '<S135>/Add'
   */
  rtb_BusAssignment_e.velD = rtb_Switch_idx_3 < 0.0F ? -(int32_T)(uint32_T)
    -rtb_Switch_idx_3 : (int32_T)(uint32_T)rtb_Switch_idx_3;
  rtb_BusAssignment_e.gSpeed = (int32_T)(uint32_T)fmodf(floorf(sqrtf(fmaxf
    (rtb_VectorConcatenate_j[0] * rtb_VectorConcatenate_j[0] +
     rtb_VectorConcatenate_j[1] * rtb_VectorConcatenate_j[1], 0.0F)) * 1000.0F),
    4.2949673E+9F);
  rtb_BusAssignment_e.heading = 0;

  /* Gain: '<S133>/Gain10' incorporates:
   *  Math: '<S140>/Math Function1'
   *  Product: '<S140>/Matrix Multiply1'
   *  Sqrt: '<S140>/Sqrt1'
   *  Switch: '<S140>/Switch2'
   */
  rtb_SumofElements = fmod(floor(sqrtf((rtb_RandomSource1[0] *
    rtb_RandomSource1[0] + rtb_RandomSource1[1] * rtb_RandomSource1[1]) +
    rtb_RandomSource1[2] * rtb_RandomSource1[2]) * 1000.0), 4.294967296E+9);

  /* BusAssignment: '<S133>/Bus Assignment' incorporates:
   *  Constant: '<S133>/Constant14'
   *  Constant: '<S133>/Constant16'
   *  Constant: '<S133>/Constant17'
   *  Gain: '<S133>/Gain10'
   *  Memory: '<S118>/Memory1'
   */
  rtb_BusAssignment_e.sAcc = rtb_SumofElements < 0.0 ? (uint32_T)-(int32_T)
    (uint32_T)-rtb_SumofElements : (uint32_T)rtb_SumofElements;
  rtb_BusAssignment_e.headingAcc = 0U;
  rtb_BusAssignment_e.pDOP = 0U;
  rtb_BusAssignment_e.reserved2 = 0U;
  rtb_BusAssignment_e.timestamp = Plant_DW.Memory1_PreviousInput;

  /* RateTransition: '<S133>/Rate Transition' */
  if (Plant_M->Timing.TaskCounters.TID[3] == 0) {
    Plant_B.RateTransition = rtb_BusAssignment_e;
  }

  /* End of RateTransition: '<S133>/Rate Transition' */

  /* Update for Delay: '<S138>/Delay' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S138>/ConcatBufferAtVector ConcatenateIn1'
   */
  for (i = 0; i < 74; i++) {
    rtb_Saturation1_m_idx_1 = (i + 1) * 3;
    Plant_DW.Delay_DSTATE[i * 3] = Plant_DW.Delay_DSTATE[rtb_Saturation1_m_idx_1];
    Plant_DW.Delay_DSTATE[i * 3 + 1] =
      Plant_DW.Delay_DSTATE[rtb_Saturation1_m_idx_1 + 1];
    Plant_DW.Delay_DSTATE[i * 3 + 2] =
      Plant_DW.Delay_DSTATE[rtb_Saturation1_m_idx_1 + 2];
  }

  /* Update states */
  Plant_DW.Delay_DSTATE[222] = Plant_Y.Plant_States.lon;

  /* Update for DiscreteFir: '<S143>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states[0] = rtb_Cl_xA;

  /* Update for Delay: '<S138>/Delay' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S138>/ConcatBufferAtVector ConcatenateIn2'
   */
  Plant_DW.Delay_DSTATE[223] = Plant_Y.Plant_States.lat;

  /* Update for DiscreteFir: '<S143>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states[1] = rtb_TrigonometricFunction2;

  /* Update for Delay: '<S138>/Delay' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S138>/ConcatBufferAtVector ConcatenateIn3'
   */
  Plant_DW.Delay_DSTATE[224] = Plant_Y.Plant_States.alt;

  /* Update for DiscreteFir: '<S143>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states[2] = rtb_Cm;

  /* Update for Delay: '<S138>/Delay1' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S138>/ConcatBufferAtVector Concatenate1In1'
   */
  for (i = 0; i < 49; i++) {
    rtb_Saturation1_m_idx_1 = (i + 1) * 3;
    Plant_DW.Delay1_DSTATE_j[i * 3] =
      Plant_DW.Delay1_DSTATE_j[rtb_Saturation1_m_idx_1];
    Plant_DW.Delay1_DSTATE_j[i * 3 + 1] =
      Plant_DW.Delay1_DSTATE_j[rtb_Saturation1_m_idx_1 + 1];
    Plant_DW.Delay1_DSTATE_j[i * 3 + 2] =
      Plant_DW.Delay1_DSTATE_j[rtb_Saturation1_m_idx_1 + 2];
  }

  /* Update states */
  Plant_DW.Delay1_DSTATE_j[147] = Plant_Y.Plant_States.vel_x_O;

  /* Update for DiscreteFir: '<S144>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states_i[0] = rtb_Va_B[0];

  /* Update for Delay: '<S138>/Delay1' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S138>/ConcatBufferAtVector Concatenate1In2'
   */
  Plant_DW.Delay1_DSTATE_j[148] = Plant_Y.Plant_States.vel_y_O;

  /* Update for DiscreteFir: '<S144>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states_i[1] = rtb_Va_B[1];

  /* Update for Delay: '<S138>/Delay1' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S138>/ConcatBufferAtVector Concatenate1In3'
   */
  Plant_DW.Delay1_DSTATE_j[149] = Plant_Y.Plant_States.vel_z_O;

  /* Update for DiscreteFir: '<S144>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states_i[2] = rtb_Va_B[2];
  for (i = 0; i < 249; i++) {
    /* Update for Delay: '<S139>/Delay1' */
    Plant_DW.Delay1_DSTATE[i] = Plant_DW.Delay1_DSTATE[i + 1];

    /* Update for Delay: '<S139>/Delay' */
    Plant_DW.Delay_DSTATE_b[i] = Plant_DW.Delay_DSTATE_b[i + 1];
  }

  /* Update for Delay: '<S139>/Delay1' incorporates:
   *  Constant: '<S139>/Constant2'
   */
  Plant_DW.Delay1_DSTATE[249] = 3.0;

  /* Update for Delay: '<S139>/Delay' incorporates:
   *  Constant: '<S139>/Constant1'
   */
  Plant_DW.Delay_DSTATE_b[249] = 16.0;

  /* End of Outputs for SubSystem: '<S6>/Sensor_GPS' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_IMU' */
  /* Outputs for Atomic SubSystem: '<S150>/Vibration_Model' */
  /* Outputs for Atomic SubSystem: '<S161>/Vibration_Model' */
  /* Product: '<S167>/Divide2' incorporates:
   *  Constant: '<S167>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Product: '<S156>/Divide2'
   */
  rtb_Cl_xA = Plant_Y.Extended_States.prop_vel[0] / 1047.1975511965977;

  /* End of Outputs for SubSystem: '<S150>/Vibration_Model' */

  /* Math: '<S167>/u^2' */
  rtb_TrigonometricFunction2 = rtb_Cl_xA * rtb_Cl_xA;

  /* Product: '<S163>/Product2' incorporates:
   *  DiscreteIntegrator: '<S163>/Discrete-Time Integrator'
   *  Trigonometry: '<S163>/Trigonometric Function2'
   */
  rtb_SumofElements1 = arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[0]) *
    rtb_TrigonometricFunction2;

  /* Math: '<S167>/u^2' incorporates:
   *  DiscreteIntegrator: '<S163>/Discrete-Time Integrator'
   *  Product: '<S163>/Product1'
   *  Trigonometry: '<S163>/Trigonometric Function1'
   */
  rtb_Cm = arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[0]) *
    rtb_TrigonometricFunction2;

  /* Product: '<S167>/Divide2' incorporates:
   *  Constant: '<S167>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Product: '<S156>/Divide2'
   */
  rtb_Divide_e_idx_1 = rtb_Cl_xA;

  /* Outputs for Atomic SubSystem: '<S150>/Vibration_Model' */
  rtb_Cl_xA = Plant_Y.Extended_States.prop_vel[1] / 1047.1975511965977;

  /* End of Outputs for SubSystem: '<S150>/Vibration_Model' */

  /* Math: '<S167>/u^2' */
  rtb_TrigonometricFunction2 = rtb_Cl_xA * rtb_Cl_xA;

  /* Product: '<S163>/Product2' incorporates:
   *  DiscreteIntegrator: '<S163>/Discrete-Time Integrator'
   *  Trigonometry: '<S163>/Trigonometric Function2'
   */
  rtb_SumofElements = arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[1]) *
    rtb_TrigonometricFunction2;

  /* Math: '<S167>/u^2' incorporates:
   *  DiscreteIntegrator: '<S163>/Discrete-Time Integrator'
   *  Product: '<S163>/Product1'
   *  Trigonometry: '<S163>/Trigonometric Function1'
   */
  rtb_Cl_zA = arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[1]) *
    rtb_TrigonometricFunction2;

  /* Product: '<S167>/Divide2' incorporates:
   *  Constant: '<S167>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Product: '<S156>/Divide2'
   */
  rtb_CYr = rtb_Cl_xA;

  /* Outputs for Atomic SubSystem: '<S150>/Vibration_Model' */
  rtb_Cl_xA = Plant_Y.Extended_States.prop_vel[2] / 1047.1975511965977;

  /* End of Outputs for SubSystem: '<S150>/Vibration_Model' */

  /* Math: '<S167>/u^2' */
  rtb_TrigonometricFunction2 = rtb_Cl_xA * rtb_Cl_xA;

  /* Product: '<S167>/Divide2' incorporates:
   *  Constant: '<S167>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Product: '<S156>/Divide2'
   */
  rtb_Cl_yA = rtb_Cl_xA;

  /* Outputs for Atomic SubSystem: '<S150>/Vibration_Model' */
  rtb_Cl_xA = Plant_Y.Extended_States.prop_vel[3] / 1047.1975511965977;

  /* Math: '<S167>/u^2' incorporates:
   *  Math: '<S156>/u^2'
   */
  rtb_Cl_xA *= rtb_Cl_xA;

  /* End of Outputs for SubSystem: '<S150>/Vibration_Model' */

  /* Sum: '<S163>/Sum of Elements' incorporates:
   *  DiscreteIntegrator: '<S163>/Discrete-Time Integrator'
   *  Math: '<S167>/u^2'
   *  Product: '<S163>/Product2'
   *  Trigonometry: '<S163>/Trigonometric Function2'
   */
  rtb_SumofElements1 = ((rtb_SumofElements1 + rtb_SumofElements) + arm_sin_f32
                        (Plant_DW.DiscreteTimeIntegrator_DSTATE[2]) *
                        rtb_TrigonometricFunction2) + arm_sin_f32
    (Plant_DW.DiscreteTimeIntegrator_DSTATE[3]) * rtb_Cl_xA;

  /* Sum: '<S163>/Sum of Elements1' incorporates:
   *  DiscreteIntegrator: '<S163>/Discrete-Time Integrator'
   *  Math: '<S167>/u^2'
   *  Product: '<S163>/Product1'
   *  Trigonometry: '<S163>/Trigonometric Function1'
   */
  rtb_SumofElements = ((rtb_Cm + rtb_Cl_zA) + arm_cos_f32
                       (Plant_DW.DiscreteTimeIntegrator_DSTATE[2]) *
                       rtb_TrigonometricFunction2) + arm_cos_f32
    (Plant_DW.DiscreteTimeIntegrator_DSTATE[3]) * rtb_Cl_xA;

  /* Outputs for Atomic SubSystem: '<S150>/Vibration_Model' */
  /* Update for DiscreteIntegrator: '<S163>/Discrete-Time Integrator' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S152>/Discrete-Time Integrator'
   */
  rtb_Sum1_dw_idx_0 = 0.002F * Plant_Y.Extended_States.prop_vel[0];

  /* End of Outputs for SubSystem: '<S150>/Vibration_Model' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE[0] += rtb_Sum1_dw_idx_0;

  /* End of Outputs for SubSystem: '<S161>/Vibration_Model' */
  /* End of Outputs for SubSystem: '<S6>/Sensor_IMU' */
  /* End of Outputs for SubSystem: '<Root>/Sensor_Model' */
  rtb_Switch_idx_0 = rtb_Sum1_dw_idx_0;

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_Model' */
  /* Outputs for Atomic SubSystem: '<S6>/Sensor_IMU' */
  /* Outputs for Atomic SubSystem: '<S150>/Vibration_Model' */
  /* Outputs for Atomic SubSystem: '<S161>/Vibration_Model' */
  /* Update for DiscreteIntegrator: '<S163>/Discrete-Time Integrator' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S152>/Discrete-Time Integrator'
   */
  rtb_Sum1_dw_idx_0 = 0.002F * Plant_Y.Extended_States.prop_vel[1];

  /* End of Outputs for SubSystem: '<S150>/Vibration_Model' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE[1] += rtb_Sum1_dw_idx_0;

  /* End of Outputs for SubSystem: '<S161>/Vibration_Model' */
  /* End of Outputs for SubSystem: '<S6>/Sensor_IMU' */
  /* End of Outputs for SubSystem: '<Root>/Sensor_Model' */
  rtb_Switch_idx_1 = rtb_Sum1_dw_idx_0;

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_Model' */
  /* Outputs for Atomic SubSystem: '<S6>/Sensor_IMU' */
  /* Outputs for Atomic SubSystem: '<S150>/Vibration_Model' */
  /* Outputs for Atomic SubSystem: '<S161>/Vibration_Model' */
  /* Update for DiscreteIntegrator: '<S163>/Discrete-Time Integrator' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S152>/Discrete-Time Integrator'
   */
  rtb_Sum1_dw_idx_0 = 0.002F * Plant_Y.Extended_States.prop_vel[2];

  /* End of Outputs for SubSystem: '<S150>/Vibration_Model' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE[2] += rtb_Sum1_dw_idx_0;

  /* End of Outputs for SubSystem: '<S161>/Vibration_Model' */
  /* End of Outputs for SubSystem: '<S6>/Sensor_IMU' */
  /* End of Outputs for SubSystem: '<Root>/Sensor_Model' */
  rtb_Switch_idx_2 = rtb_Sum1_dw_idx_0;

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_Model' */
  /* Outputs for Atomic SubSystem: '<S6>/Sensor_IMU' */
  /* Outputs for Atomic SubSystem: '<S150>/Vibration_Model' */
  /* Outputs for Atomic SubSystem: '<S161>/Vibration_Model' */
  /* Update for DiscreteIntegrator: '<S163>/Discrete-Time Integrator' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S152>/Discrete-Time Integrator'
   */
  rtb_Sum1_dw_idx_0 = 0.002F * Plant_Y.Extended_States.prop_vel[3];

  /* End of Outputs for SubSystem: '<S150>/Vibration_Model' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE[3] += rtb_Sum1_dw_idx_0;

  /* Switch: '<S161>/Switch' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S163>/Gain2'
   *  Gain: '<S163>/Gain4'
   *  Product: '<S163>/Divide'
   *  SignalConversion: '<S163>/ConcatBufferAtVector ConcatenateIn1'
   *  SignalConversion: '<S165>/ConcatBufferAtVector ConcatenateIn1'
   *  SignalConversion: '<S165>/ConcatBufferAtVector ConcatenateIn2'
   *  SignalConversion: '<S165>/ConcatBufferAtVector ConcatenateIn3'
   *  Sum: '<S161>/Sum'
   *  Sum: '<S163>/Sum'
   *  Sum: '<S163>/Sum of Elements1'
   */
  rtb_VectorConcatenate_j[0] = (real32_T)(rtb_SumofElements1 / 4.0 * 0.5 +
    Plant_Y.Plant_States.rot_x_B);
  rtb_VectorConcatenate_j[1] = (real32_T)(rtb_SumofElements / 4.0 * 0.5 +
    Plant_Y.Plant_States.rot_y_B);
  rtb_Square_idx_2 = (real32_T)((rtb_SumofElements1 + rtb_SumofElements) * 0.5 /
    4.0 * 0.5 + Plant_Y.Plant_States.rot_z_B);

  /* End of Outputs for SubSystem: '<S161>/Vibration_Model' */

  /* Sum: '<S169>/Sum' incorporates:
   *  Product: '<S169>/Product'
   */
  for (i = 0; i < 3; i++) {
    rtb_RandomSource[i] = (Plant_ConstB.Add_k[i + 3] * rtb_VectorConcatenate_j[1]
      + Plant_ConstB.Add_k[i] * rtb_VectorConcatenate_j[0]) +
      Plant_ConstB.Add_k[i + 6] * rtb_Square_idx_2;
  }

  /* End of Sum: '<S169>/Sum' */

  /* DiscreteIntegrator: '<S168>/Discrete-Time Integrator5' */
  if (Plant_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[0] = rtb_RandomSource[0];
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[1] = rtb_RandomSource[1];
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[2] = rtb_RandomSource[2];
  }

  /* S-Function (sdsprandsrc2): '<S159>/Random Source' */
  RandSrc_GZ_R(rtb_Sum_kn, &Plant_ConstP.pooled27, 1,
               Plant_ConstP.RandomSource_VarianceRTP_h, 3,
               Plant_DW.RandomSource_STATE_DWORK_f, 3, 1);

  /* S-Function (sdsprandsrc2): '<S170>/Random Source' */
  RandSrc_GZ_R(rtb_Sum_c, &Plant_ConstP.pooled27, 1,
               Plant_ConstP.RandomSource_VarianceRTP_o, 3,
               Plant_DW.RandomSource_STATE_DWORK_p, 3, 1);

  /* Saturate: '<S162>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S168>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[0] > 34.9065857F) {
    rtb_Switch_idx_3 = 34.9065857F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[0] < -34.9065857F) {
    rtb_Switch_idx_3 = -34.9065857F;
  } else {
    rtb_Switch_idx_3 = Plant_DW.DiscreteTimeIntegrator5_DSTATE[0];
  }

  /* Sum: '<S162>/Sum' */
  rtb_Add_m[0] = rtb_Switch_idx_3 + rtb_Sum_c[0];

  /* Saturate: '<S162>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S168>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[1] > 34.9065857F) {
    rtb_Switch_idx_3 = 34.9065857F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[1] < -34.9065857F) {
    rtb_Switch_idx_3 = -34.9065857F;
  } else {
    rtb_Switch_idx_3 = Plant_DW.DiscreteTimeIntegrator5_DSTATE[1];
  }

  /* Sum: '<S162>/Sum' */
  rtb_Add_m[1] = rtb_Switch_idx_3 + rtb_Sum_c[1];

  /* Saturate: '<S162>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S168>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[2] > 34.9065857F) {
    rtb_Switch_idx_3 = 34.9065857F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[2] < -34.9065857F) {
    rtb_Switch_idx_3 = -34.9065857F;
  } else {
    rtb_Switch_idx_3 = Plant_DW.DiscreteTimeIntegrator5_DSTATE[2];
  }

  /* Sum: '<S162>/Sum' */
  rtb_Add_m[2] = rtb_Switch_idx_3 + rtb_Sum_c[2];

  /* Outputs for Atomic SubSystem: '<S150>/Vibration_Model' */
  /* Math: '<S156>/u^2' incorporates:
   *  Product: '<S156>/Divide2'
   */
  rtb_TrigonometricFunction2 = rtb_Divide_e_idx_1 * rtb_Divide_e_idx_1;

  /* Product: '<S152>/Product2' incorporates:
   *  DiscreteIntegrator: '<S152>/Discrete-Time Integrator'
   *  Trigonometry: '<S152>/Trigonometric Function2'
   */
  rtb_SumofElements1 = arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_f[0]) *
    rtb_TrigonometricFunction2;

  /* Math: '<S156>/u^2' incorporates:
   *  DiscreteIntegrator: '<S152>/Discrete-Time Integrator'
   *  Product: '<S152>/Product1'
   *  Product: '<S156>/Divide2'
   *  Trigonometry: '<S152>/Trigonometric Function1'
   */
  rtb_Cm = arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_f[0]) *
    rtb_TrigonometricFunction2;
  rtb_TrigonometricFunction2 = rtb_CYr * rtb_CYr;

  /* Product: '<S152>/Product2' incorporates:
   *  DiscreteIntegrator: '<S152>/Discrete-Time Integrator'
   *  Trigonometry: '<S152>/Trigonometric Function2'
   */
  rtb_SumofElements = arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_f[1]) *
    rtb_TrigonometricFunction2;

  /* Math: '<S156>/u^2' incorporates:
   *  DiscreteIntegrator: '<S152>/Discrete-Time Integrator'
   *  Product: '<S152>/Product1'
   *  Product: '<S156>/Divide2'
   *  Trigonometry: '<S152>/Trigonometric Function1'
   */
  rtb_Cl_zA = arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_f[1]) *
    rtb_TrigonometricFunction2;
  rtb_TrigonometricFunction2 = rtb_Cl_yA * rtb_Cl_yA;

  /* Sum: '<S152>/Sum of Elements' incorporates:
   *  DiscreteIntegrator: '<S152>/Discrete-Time Integrator'
   *  Product: '<S152>/Product2'
   *  Trigonometry: '<S152>/Trigonometric Function2'
   */
  rtb_SumofElements = ((rtb_SumofElements1 + rtb_SumofElements) + arm_sin_f32
                       (Plant_DW.DiscreteTimeIntegrator_DSTATE_f[2]) *
                       rtb_TrigonometricFunction2) + arm_sin_f32
    (Plant_DW.DiscreteTimeIntegrator_DSTATE_f[3]) * rtb_Cl_xA;

  /* SignalConversion: '<S152>/ConcatBufferAtVector ConcatenateIn1' incorporates:
   *  Sum: '<S152>/Sum of Elements'
   */
  rtb_Divide2[0] = rtb_SumofElements;

  /* Sum: '<S152>/Sum of Elements1' incorporates:
   *  DiscreteIntegrator: '<S152>/Discrete-Time Integrator'
   *  Product: '<S152>/Product1'
   *  Trigonometry: '<S152>/Trigonometric Function1'
   */
  rtb_SumofElements1 = ((rtb_Cm + rtb_Cl_zA) + arm_cos_f32
                        (Plant_DW.DiscreteTimeIntegrator_DSTATE_f[2]) *
                        rtb_TrigonometricFunction2) + arm_cos_f32
    (Plant_DW.DiscreteTimeIntegrator_DSTATE_f[3]) * rtb_Cl_xA;

  /* SignalConversion: '<S152>/ConcatBufferAtVector ConcatenateIn2' */
  rtb_Divide2[1] = rtb_SumofElements1;

  /* Gain: '<S152>/Gain2' incorporates:
   *  Sum: '<S152>/Sum'
   *  Sum: '<S152>/Sum of Elements'
   */
  rtb_Divide2[2] = (rtb_SumofElements + rtb_SumofElements1) * 0.5;

  /* Update for DiscreteIntegrator: '<S152>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_f[0] += rtb_Switch_idx_0;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_f[1] += rtb_Switch_idx_1;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_f[2] += rtb_Switch_idx_2;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_f[3] += rtb_Sum1_dw_idx_0;

  /* End of Outputs for SubSystem: '<S150>/Vibration_Model' */

  /* Switch: '<S150>/Switch' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S152>/Gain4'
   *  Product: '<S152>/Divide'
   *  Product: '<S154>/Product1'
   *  SignalConversion: '<S154>/ConcatBufferAtVector Concatenate1In1'
   *  SignalConversion: '<S154>/ConcatBufferAtVector Concatenate1In2'
   *  SignalConversion: '<S154>/ConcatBufferAtVector Concatenate1In3'
   *  Sum: '<S150>/Sum'
   *  Sum: '<S154>/Sum'
   */
  for (i = 0; i < 3; i++) {
    /* Outputs for Atomic SubSystem: '<S150>/Vibration_Model' */
    rtb_Sum_c[i] = (real32_T)(((Plant_Y.Extended_States.M_BO[i + 3] *
      Plant_Y.Plant_States.acc_y_O + Plant_Y.Extended_States.M_BO[i] *
      Plant_Y.Plant_States.acc_x_O) + Plant_Y.Extended_States.M_BO[i + 6] *
      (Plant_Y.Plant_States.acc_z_O - 9.80665F)) + rtb_Divide2[i] / 4.0 *
      Plant_ConstP.Gain4_Gain[i]);

    /* End of Outputs for SubSystem: '<S150>/Vibration_Model' */
  }

  /* End of Switch: '<S150>/Switch' */

  /* Sum: '<S158>/Sum' incorporates:
   *  Product: '<S158>/Product'
   */
  for (i = 0; i < 3; i++) {
    rtb_RandomSource1[i] = (Plant_ConstB.Add_g[i + 3] * rtb_Sum_c[1] +
      Plant_ConstB.Add_g[i] * rtb_Sum_c[0]) + Plant_ConstB.Add_g[i + 6] *
      rtb_Sum_c[2];
  }

  /* End of Sum: '<S158>/Sum' */

  /* DiscreteIntegrator: '<S157>/Discrete-Time Integrator5' */
  if (Plant_DW.DiscreteTimeIntegrator5_IC_LO_g != 0) {
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[0] = rtb_RandomSource1[0];
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[1] = rtb_RandomSource1[1];
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[2] = rtb_RandomSource1[2];
  }

  /* Outport: '<Root>/IMU' incorporates:
   *  BusAssignment: '<S147>/Bus Assignment'
   *  Memory: '<S118>/Memory1'
   */
  Plant_Y.IMU.timestamp = Plant_DW.Memory1_PreviousInput;
  Plant_Y.IMU.gyr_x = rtb_Add_m[0];
  Plant_Y.IMU.gyr_y = rtb_Add_m[1];
  Plant_Y.IMU.gyr_z = rtb_Add_m[2];

  /* Update for DiscreteIntegrator: '<S168>/Discrete-Time Integrator5' */
  Plant_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;

  /* Update for DiscreteIntegrator: '<S157>/Discrete-Time Integrator5' */
  Plant_DW.DiscreteTimeIntegrator5_IC_LO_g = 0U;

  /* End of Outputs for SubSystem: '<S6>/Sensor_IMU' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_MAG' */
  /* Gain: '<S176>/rad_to_index' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S176>/TmpSignal ConversionAtrad_to_indexInport1'
   */
  rtb_SumofElements = fmod(floor(5.7295779513082321 * Plant_Y.Plant_States.lat),
    4.294967296E+9);

  /* Sum: '<S176>/Add' incorporates:
   *  Gain: '<S176>/rad_to_index'
   */
  i = (rtb_SumofElements < 0.0 ? -(int32_T)(uint32_T)-rtb_SumofElements :
       (int32_T)(uint32_T)rtb_SumofElements) + 8;

  /* Saturate: '<S176>/Saturation1' */
  if (i > 16) {
    i = 16;
  } else {
    if (i < 0) {
      i = 0;
    }
  }

  /* Gain: '<S176>/rad_to_index' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S176>/TmpSignal ConversionAtrad_to_indexInport1'
   */
  rtb_SumofElements = fmod(floor(5.7295779513082321 * Plant_Y.Plant_States.lon),
    4.294967296E+9);

  /* Sum: '<S176>/Add' incorporates:
   *  Gain: '<S176>/rad_to_index'
   */
  rtb_Saturation1_m_idx_1 = (rtb_SumofElements < 0.0 ? -(int32_T)(uint32_T)
    -rtb_SumofElements : (int32_T)(uint32_T)rtb_SumofElements) + 18;

  /* Saturate: '<S176>/Saturation1' */
  if (rtb_Saturation1_m_idx_1 > 36) {
    rtb_Saturation1_m_idx_1 = 36;
  } else {
    if (rtb_Saturation1_m_idx_1 < 0) {
      rtb_Saturation1_m_idx_1 = 0;
    }
  }

  /* LookupNDDirect: '<S176>/Declination_Lookup_Table' incorporates:
   *  LookupNDDirect: '<S176>/Inclination_Lookup_Table'
   *  LookupNDDirect: '<S176>/Magnitude_Lookup_Table'
   *
   * About '<S176>/Declination_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   *
   * About '<S176>/Inclination_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   *
   * About '<S176>/Magnitude_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  i += rtb_Saturation1_m_idx_1 * 17;

  /* Gain: '<S177>/Gain1' incorporates:
   *  LookupNDDirect: '<S176>/Declination_Lookup_Table'
   *
   * About '<S176>/Declination_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  rtb_Sum1_dw_idx_0 = Plant_ConstP.Declination_Lookup_Table_table[i] *
    0.0174532924F;

  /* Trigonometry: '<S179>/Trigonometric Function1' incorporates:
   *  Trigonometry: '<S179>/Trigonometric Function3'
   */
  rtb_Gain3 = arm_cos_f32(rtb_Sum1_dw_idx_0);
  rtb_VectorConcatenate_f[0] = rtb_Gain3;

  /* Trigonometry: '<S179>/Trigonometric Function' incorporates:
   *  Trigonometry: '<S179>/Trigonometric Function2'
   */
  rtb_Square_idx_2 = arm_sin_f32(rtb_Sum1_dw_idx_0);
  rtb_VectorConcatenate_f[1] = rtb_Square_idx_2;

  /* SignalConversion: '<S179>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S179>/Constant3'
   */
  rtb_VectorConcatenate_f[2] = 0.0F;

  /* Gain: '<S179>/Gain' */
  rtb_VectorConcatenate_f[3] = -rtb_Square_idx_2;

  /* Trigonometry: '<S179>/Trigonometric Function3' */
  rtb_VectorConcatenate_f[4] = rtb_Gain3;

  /* SignalConversion: '<S179>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S179>/Constant4'
   */
  rtb_VectorConcatenate_f[5] = 0.0F;

  /* Gain: '<S177>/Gain' incorporates:
   *  LookupNDDirect: '<S176>/Inclination_Lookup_Table'
   *
   * About '<S176>/Inclination_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  rtb_Sum1_dw_idx_0 = Plant_ConstP.Inclination_Lookup_Table_table[i] *
    -0.0174532924F;

  /* Trigonometry: '<S178>/Trigonometric Function3' incorporates:
   *  Trigonometry: '<S178>/Trigonometric Function1'
   */
  rtb_magnitude_gauss = arm_cos_f32(rtb_Sum1_dw_idx_0);
  rtb_VectorConcatenate_m1[0] = rtb_magnitude_gauss;

  /* SignalConversion: '<S178>/ConcatBufferAtVector Concatenate2In2' incorporates:
   *  Constant: '<S178>/Constant4'
   */
  rtb_VectorConcatenate_m1[1] = 0.0F;

  /* Trigonometry: '<S178>/Trigonometric Function2' incorporates:
   *  Trigonometry: '<S178>/Trigonometric Function'
   */
  rtb_Add_ow = arm_sin_f32(rtb_Sum1_dw_idx_0);

  /* Gain: '<S178>/Gain' incorporates:
   *  Trigonometry: '<S178>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_m1[2] = -rtb_Add_ow;

  /* End of Outputs for SubSystem: '<S6>/Sensor_MAG' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_IMU' */
  /* Saturate: '<S151>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S157>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[0] > 78.4532F) {
    rtb_Sum1_dw_idx_0 = 78.4532F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[0] < -78.4532F) {
    rtb_Sum1_dw_idx_0 = -78.4532F;
  } else {
    rtb_Sum1_dw_idx_0 = Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[0];
  }

  /* Update for DiscreteIntegrator: '<S168>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S168>/Gain'
   *  Sum: '<S168>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTATE[0] += (rtb_RandomSource[0] -
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 314.159271F * 0.002F;

  /* Update for DiscreteIntegrator: '<S157>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S157>/Gain'
   *  Sum: '<S157>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[0] += (rtb_RandomSource1[0] -
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[0]) * 314.159271F * 0.002F;

  /* End of Outputs for SubSystem: '<S6>/Sensor_IMU' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_MAG' */
  /* SignalConversion: '<S179>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_f[6] = Plant_ConstB.VectorConcatenate3[0];

  /* SignalConversion: '<S178>/ConcatBufferAtVector ConcatenateIn2' */
  rtb_VectorConcatenate_m1[3] = Plant_ConstB.VectorConcatenate3_e[0];

  /* End of Outputs for SubSystem: '<S6>/Sensor_MAG' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_IMU' */
  /* Saturate: '<S151>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S157>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[1] > 78.4532F) {
    rtb_Product8 = 78.4532F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[1] < -78.4532F) {
    rtb_Product8 = -78.4532F;
  } else {
    rtb_Product8 = Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[1];
  }

  /* Update for DiscreteIntegrator: '<S168>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S168>/Gain'
   *  Sum: '<S168>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTATE[1] += (rtb_RandomSource[1] -
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 314.159271F * 0.002F;

  /* Update for DiscreteIntegrator: '<S157>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S157>/Gain'
   *  Sum: '<S157>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[1] += (rtb_RandomSource1[1] -
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[1]) * 314.159271F * 0.002F;

  /* End of Outputs for SubSystem: '<S6>/Sensor_IMU' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_MAG' */
  /* SignalConversion: '<S179>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_f[7] = Plant_ConstB.VectorConcatenate3[1];

  /* SignalConversion: '<S178>/ConcatBufferAtVector ConcatenateIn2' */
  rtb_VectorConcatenate_m1[4] = Plant_ConstB.VectorConcatenate3_e[1];

  /* End of Outputs for SubSystem: '<S6>/Sensor_MAG' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_IMU' */
  /* Saturate: '<S151>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S157>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[2] > 78.4532F) {
    rtb_Sum1_dw_idx_2 = 78.4532F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[2] < -78.4532F) {
    rtb_Sum1_dw_idx_2 = -78.4532F;
  } else {
    rtb_Sum1_dw_idx_2 = Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[2];
  }

  /* Update for DiscreteIntegrator: '<S168>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S168>/Gain'
   *  Sum: '<S168>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTATE[2] += (rtb_RandomSource[2] -
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 314.159271F * 0.002F;

  /* Update for DiscreteIntegrator: '<S157>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S157>/Gain'
   *  Sum: '<S157>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[2] += (rtb_RandomSource1[2] -
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[2]) * 314.159271F * 0.002F;

  /* End of Outputs for SubSystem: '<S6>/Sensor_IMU' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_MAG' */
  /* SignalConversion: '<S179>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_f[8] = Plant_ConstB.VectorConcatenate3[2];

  /* SignalConversion: '<S178>/ConcatBufferAtVector ConcatenateIn2' */
  rtb_VectorConcatenate_m1[5] = Plant_ConstB.VectorConcatenate3_e[2];

  /* Trigonometry: '<S178>/Trigonometric Function' */
  rtb_VectorConcatenate_m1[6] = rtb_Add_ow;

  /* SignalConversion: '<S178>/ConcatBufferAtVector Concatenate1In2' incorporates:
   *  Constant: '<S178>/Constant3'
   */
  rtb_VectorConcatenate_m1[7] = 0.0F;

  /* Trigonometry: '<S178>/Trigonometric Function1' */
  rtb_VectorConcatenate_m1[8] = rtb_magnitude_gauss;

  /* Gain: '<S177>/toGauss' incorporates:
   *  LookupNDDirect: '<S176>/Magnitude_Lookup_Table'
   *
   * About '<S176>/Magnitude_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  rtb_magnitude_gauss = Plant_ConstP.Magnitude_Lookup_Table_table[i] * 0.01F;

  /* Product: '<S177>/Multiply1' incorporates:
   *  Product: '<S177>/Multiply'
   */
  for (i = 0; i < 3; i++) {
    rtb_Va_B[i] = rtb_VectorConcatenate_m1[i] * rtb_magnitude_gauss;
  }

  /* End of Product: '<S177>/Multiply1' */

  /* Product: '<S177>/Multiply2' */
  for (i = 0; i < 3; i++) {
    rtb_Add_m[i] = rtb_VectorConcatenate_f[i + 6] * rtb_Va_B[2] +
      (rtb_VectorConcatenate_f[i + 3] * rtb_Va_B[1] + rtb_VectorConcatenate_f[i]
       * rtb_Va_B[0]);
  }

  /* End of Product: '<S177>/Multiply2' */

  /* Product: '<S174>/Product' incorporates:
   *  Delay: '<Root>/Delay'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_j[i] = Plant_Y.Extended_States.M_BO[i + 6] *
      rtb_Add_m[2] + (Plant_Y.Extended_States.M_BO[i + 3] * rtb_Add_m[1] +
                      Plant_Y.Extended_States.M_BO[i] * rtb_Add_m[0]);
  }

  /* End of Product: '<S174>/Product' */
  for (i = 0; i < 3; i++) {
    /* Sum: '<S180>/Sum' incorporates:
     *  Product: '<S180>/Product'
     */
    rtb_Switch_idx_3 = (Plant_ConstB.Add[i + 3] * rtb_VectorConcatenate_j[1] +
                        Plant_ConstB.Add[i] * rtb_VectorConcatenate_j[0]) +
      Plant_ConstB.Add[i + 6] * rtb_VectorConcatenate_j[2];

    /* Saturate: '<S175>/Saturation' incorporates:
     *  Sum: '<S180>/Sum'
     */
    if (rtb_Switch_idx_3 > 4.0F) {
      rtb_Add_m[i] = 4.0F;
    } else if (rtb_Switch_idx_3 < -4.0F) {
      rtb_Add_m[i] = -4.0F;
    } else {
      rtb_Add_m[i] = rtb_Switch_idx_3;
    }

    /* End of Saturate: '<S175>/Saturation' */
  }

  /* S-Function (sdsprandsrc2): '<S181>/Random Source' */
  RandSrc_GZ_R(rtb_VectorConcatenate_j, &Plant_ConstP.pooled27, 1,
               Plant_ConstP.RandomSource_VarianceRTP_om, 3,
               Plant_DW.RandomSource_STATE_DWORK, 3, 1);

  /* Sum: '<S175>/Add' */
  rtb_Add_m[0] += rtb_VectorConcatenate_j[0];
  rtb_Add_m[1] += rtb_VectorConcatenate_j[1];

  /* BusAssignment: '<S171>/Bus Assignment' incorporates:
   *  Memory: '<S118>/Memory1'
   *  Sum: '<S175>/Add'
   */
  rtb_BusAssignment_j.timestamp = Plant_DW.Memory1_PreviousInput;
  rtb_BusAssignment_j.mag_x = rtb_Add_m[0];
  rtb_BusAssignment_j.mag_y = rtb_Add_m[1];
  rtb_BusAssignment_j.mag_z = rtb_Add_m[2] + rtb_VectorConcatenate_j[2];

  /* RateTransition: '<S171>/Rate Transition' */
  if (Plant_M->Timing.TaskCounters.TID[2] == 0) {
    Plant_B.RateTransition_l = rtb_BusAssignment_j;
  }

  /* End of RateTransition: '<S171>/Rate Transition' */
  /* End of Outputs for SubSystem: '<S6>/Sensor_MAG' */

  /* Update for Memory: '<S118>/Memory1' incorporates:
   *  Constant: '<S118>/dt'
   *  Sum: '<S118>/Sum'
   */
  Plant_DW.Memory1_PreviousInput += PLANT_EXPORT.period;

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_IMU' */
  /* Outport: '<Root>/IMU' incorporates:
   *  Sum: '<S151>/Sum'
   */
  Plant_Y.IMU.acc_x = rtb_Sum1_dw_idx_0 + rtb_Sum_kn[0];
  Plant_Y.IMU.acc_y = rtb_Product8 + rtb_Sum_kn[1];
  Plant_Y.IMU.acc_z = rtb_Sum1_dw_idx_2 + rtb_Sum_kn[2];

  /* End of Outputs for SubSystem: '<S6>/Sensor_IMU' */
  /* End of Outputs for SubSystem: '<Root>/Sensor_Model' */
  if (Plant_M->Timing.TaskCounters.TID[2] == 0) {
    /* Outport: '<Root>/MAG' */
    Plant_Y.MAG = Plant_B.RateTransition_l;

    /* Outport: '<Root>/Barometer' */
    Plant_Y.Barometer = Plant_B.RateTransition_p;
  }

  if (Plant_M->Timing.TaskCounters.TID[3] == 0) {
    /* Outport: '<Root>/GPS' */
    Plant_Y.GPS = Plant_B.RateTransition;
  }

  if (Plant_M->Timing.TaskCounters.TID[1] == 0) {
    /* Outport: '<Root>/Airspeed' */
    Plant_Y.Airspeed = Plant_B.RateTransition_e;
  }

  rate_scheduler();
}

/* Model initialize function */
void Plant_init(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Plant_M, 0,
                sizeof(RT_MODEL_Plant_T));

  /* block I/O */
  (void) memset(((void *) &Plant_B), 0,
                sizeof(B_Plant_T));

  /* states (dwork) */
  (void) memset((void *)&Plant_DW, 0,
                sizeof(DW_Plant_T));

  /* external inputs */
  (void)memset(&Plant_U, 0, sizeof(ExtU_Plant_T));

  /* external outputs */
  (void) memset((void *)&Plant_Y, 0,
                sizeof(ExtY_Plant_T));

  {
    uint32_T RandomSource_SEED_DWORK_n;

    /* SystemInitialize for Atomic SubSystem: '<Root>/Kinematic_Equation' */
    /* InitializeConditions for DiscreteIntegrator: '<S92>/Discrete-Time Integrator' */
    Plant_DW.DiscreteTimeIntegrator_IC_LOADI = 1U;
    Plant_DW.DiscreteTimeIntegrator_PrevRese = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S86>/Discrete-Time Integrator' */
    Plant_DW.DiscreteTimeIntegrator_PrevRe_g = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S87>/Discrete-Time Integrator' */
    Plant_DW.DiscreteTimeIntegrator_PrevRe_d = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S87>/Discrete-Time Integrator1' */
    Plant_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
    Plant_DW.DiscreteTimeIntegrator1_PrevRes = 0;

    /* End of SystemInitialize for SubSystem: '<Root>/Kinematic_Equation' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Bus_Constructor' */
    /* InitializeConditions for Delay: '<S44>/Delay1' */
    Plant_DW.icLoad = 1U;

    /* End of SystemInitialize for SubSystem: '<Root>/Bus_Constructor' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Sensor_Model' */
    /* SystemInitialize for Atomic SubSystem: '<S6>/Sensor_Barometer' */
    /* InitializeConditions for S-Function (sdsprandsrc2): '<S132>/Random Source' */
    RandomSource_SEED_DWORK_n = 91337U;
    RandSrcInitState_GZ(&RandomSource_SEED_DWORK_n,
                        Plant_DW.RandomSource_STATE_DWORK_fn, 1);

    /* End of SystemInitialize for SubSystem: '<S6>/Sensor_Barometer' */

    /* SystemInitialize for Atomic SubSystem: '<S6>/Sensor_GPS' */
    /* InitializeConditions for S-Function (sdsprandsrc2): '<S141>/Random Source' */
    RandSrcCreateSeeds_32(63235U, Plant_DW.RandomSource_SEED_DWORK_a, 3);
    RandSrcInitState_GZ(Plant_DW.RandomSource_SEED_DWORK_a,
                        Plant_DW.RandomSource_STATE_DWORK_f2, 3);

    /* InitializeConditions for DiscreteFir: '<S143>/Discrete FIR Filter' */
    Plant_DW.DiscreteFIRFilter_states[0] = 0.0;
    Plant_DW.DiscreteFIRFilter_states[1] = 0.0;
    Plant_DW.DiscreteFIRFilter_states[2] = 0.0;

    /* InitializeConditions for S-Function (sdsprandsrc2): '<S141>/Random Source1' */
    RandSrcCreateSeeds_32(9754U, Plant_DW.RandomSource1_SEED_DWORK, 3);
    RandSrcInitState_GZ(Plant_DW.RandomSource1_SEED_DWORK,
                        Plant_DW.RandomSource1_STATE_DWORK, 3);

    /* InitializeConditions for DiscreteFir: '<S144>/Discrete FIR Filter' */
    Plant_DW.DiscreteFIRFilter_states_i[0] = 0.0F;
    Plant_DW.DiscreteFIRFilter_states_i[1] = 0.0F;
    Plant_DW.DiscreteFIRFilter_states_i[2] = 0.0F;

    /* End of SystemInitialize for SubSystem: '<S6>/Sensor_GPS' */

    /* SystemInitialize for Atomic SubSystem: '<S6>/Sensor_IMU' */
    /* InitializeConditions for DiscreteIntegrator: '<S168>/Discrete-Time Integrator5' */
    Plant_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

    /* InitializeConditions for S-Function (sdsprandsrc2): '<S159>/Random Source' */
    RandSrcCreateSeeds_32(90579U, Plant_DW.RandomSource_SEED_DWORK_h, 3);
    RandSrcInitState_GZ(Plant_DW.RandomSource_SEED_DWORK_h,
                        Plant_DW.RandomSource_STATE_DWORK_f, 3);

    /* InitializeConditions for S-Function (sdsprandsrc2): '<S170>/Random Source' */
    RandSrcCreateSeeds_32(81472U, Plant_DW.RandomSource_SEED_DWORK_e, 3);
    RandSrcInitState_GZ(Plant_DW.RandomSource_SEED_DWORK_e,
                        Plant_DW.RandomSource_STATE_DWORK_p, 3);

    /* InitializeConditions for DiscreteIntegrator: '<S157>/Discrete-Time Integrator5' */
    Plant_DW.DiscreteTimeIntegrator5_IC_LO_g = 1U;

    /* End of SystemInitialize for SubSystem: '<S6>/Sensor_IMU' */

    /* SystemInitialize for Atomic SubSystem: '<S6>/Sensor_MAG' */
    /* InitializeConditions for S-Function (sdsprandsrc2): '<S181>/Random Source' */
    RandSrcCreateSeeds_32(12698U, Plant_DW.RandomSource_SEED_DWORK, 3);
    RandSrcInitState_GZ(Plant_DW.RandomSource_SEED_DWORK,
                        Plant_DW.RandomSource_STATE_DWORK, 3);

    /* End of SystemInitialize for SubSystem: '<S6>/Sensor_MAG' */
    /* End of SystemInitialize for SubSystem: '<Root>/Sensor_Model' */
  }
}

/* Model terminate function */
void Plant_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
