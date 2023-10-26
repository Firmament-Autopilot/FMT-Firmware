/*
 * File: Plant.c
 *
 * Code generated for Simulink model 'Plant'.
 *
 * Model version                  : 1.80
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Oct 26 08:28:27 2023
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
struct_jgVLU9PsiazymsYzo6u6IH PLANT_EXPORT = {
  2U,

  { 70, 105, 120, 119, 105, 110, 103, 32, 118, 49, 46, 48, 46, 48, 0 }
} ;                                    /* Variable: PLANT_EXPORT
                                        * Referenced by:
                                        *   '<S43>/dt'
                                        *   '<S122>/dt'
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

  /* S-Function (sdsprandsrc2): '<S136>/Random Source' */
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

  /* End of S-Function (sdsprandsrc2): '<S136>/Random Source' */
}

void RandSrcInitState_GZ(const uint32_T seed[], uint32_T state[], int32_T nChans)
{
  int32_T i;
  int32_T tmp;

  /* InitializeConditions for S-Function (sdsprandsrc2): '<S136>/Random Source' */
  /* RandSrcInitState_GZ */
  for (i = 0; i < nChans; i++) {
    tmp = i << 1;
    state[tmp] = 362436069U;
    state[tmp + 1] = seed[i] == 0U ? 521288629U : seed[i];
  }

  /* End of InitializeConditions for S-Function (sdsprandsrc2): '<S136>/Random Source' */
}

void RandSrcInitState_U_32(const uint32_T seed[], real32_T state[], int32_T
  nChans)
{
  int32_T i;
  uint32_T j;
  int32_T k;
  int32_T n;
  real32_T d;

  /* InitializeConditions for S-Function (sdsprandsrc2): '<S145>/Random Source' */
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

  /* End of InitializeConditions for S-Function (sdsprandsrc2): '<S145>/Random Source' */
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

  /* InitializeConditions for S-Function (sdsprandsrc2): '<S145>/Random Source' */
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

  /* End of InitializeConditions for S-Function (sdsprandsrc2): '<S145>/Random Source' */
}

void RandSrcCreateSeeds_32(uint32_T initSeed, uint32_T seedArray[], int32_T
  numSeeds)
{
  real32_T state[35];
  real32_T tmp;
  real32_T min;
  real32_T max;
  int32_T i;

  /* InitializeConditions for S-Function (sdsprandsrc2): '<S145>/Random Source' */
  /* RandSrcCreateSeeds_32 */
  min = 0.0F;
  max = 1.0F;
  RandSrcInitState_U_32(&initSeed, state, 1);
  for (i = 0; i < numSeeds; i++) {
    RandSrc_U_R(&tmp, &min, 1, &max, 1, state, 1, 1);
    seedArray[i] = (uint32_T)(tmp * 2.14748365E+9F);
  }

  /* End of InitializeConditions for S-Function (sdsprandsrc2): '<S145>/Random Source' */
}

/* Model step function */
void Plant_step(void)
{
  real32_T rtb_Plant_States_vel_x_O;
  real32_T rtb_Plant_States_vel_y_O;
  real32_T rtb_Plant_States_vel_z_O;
  real32_T rtb_Va_B[3];
  real32_T rtb_Gain_kz;
  real32_T rtb_Add_p;
  real32_T rtb_MathFunction1_k;
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
  real32_T rtb_Add_i[3];
  real32_T rtb_VectorConcatenate_f[9];
  real32_T rtb_MathFunction[3];
  real32_T rtb_Sum_jq[3];
  real32_T rtb_Divide_g[4];
  real32_T rtb_MathFunction_m[3];
  boolean_T rtb_Compare_c;
  boolean_T rtb_FixPtRelationalOperator;
  real32_T rtb_MatrixConcatenate4[16];
  real32_T rtb_Sum_fw[3];
  real32_T rtb_MatrixConcatenate1[9];
  real32_T rtb_Sum_c4;
  AirSpeed_Bus rtb_BusAssignment_f;
  Barometer_Bus rtb_BusAssignment_c;
  GPS_uBlox_Bus rtb_BusAssignment_e;
  real32_T rtb_VectorConcatenate_on[3];
  real32_T rtb_VectorConcatenate_d[9];
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
  real32_T rtb_MatrixConcatenate4_0[4];
  real32_T rtb_Square_l;
  real32_T rtb_MathFunction_k;
  real32_T rtb_Multiply4;
  real32_T rtb_Switch_idx_3;
  real32_T rtb_Switch_idx_2;
  real32_T rtb_Switch_idx_1;
  real32_T rtb_Switch_idx_0;
  real_T rtb_Divide_e_idx_1;
  real32_T rtb_Sum1_dw_idx_2;
  real32_T rtb_Sum1_dw_idx_0;
  real32_T rtb_Sum_i_idx_2;
  real32_T rtb_Multiply4_idx_1;
  real32_T rtb_Multiply4_idx_0;
  int32_T rtb_Saturation1_m_idx_1;
  uint16_T tmp_1;
  real32_T tmp_2;
  real32_T rtb_Divide_k_idx_0;
  real32_T rtb_Divide_k_idx_2;
  real32_T rtb_Divide_k_idx_3;
  real32_T rtb_Add_j0_tmp;
  real32_T rtb_Gain_e_tmp;
  real32_T rtb_Gain_e_tmp_0;
  real32_T rtb_Gain_e_tmp_1;
  real32_T rtb_Add_j0_tmp_0;

  /* Delay: '<Root>/Delay' */
  rtb_Plant_States_vel_x_O = Plant_Y.Plant_States.vel_x_O;
  rtb_Plant_States_vel_y_O = Plant_Y.Plant_States.vel_y_O;
  rtb_Plant_States_vel_z_O = Plant_Y.Plant_States.vel_z_O;
  for (i = 0; i < 9; i++) {
    rtb_VectorConcatenate_d[i] = Plant_Y.Extended_States.M_BO[i];
  }

  /* Outputs for Atomic SubSystem: '<Root>/Actuators' */
  for (i = 0; i < 3; i++) {
    /* Product: '<S10>/Multiply' */
    rtb_Sum1_dw_idx_0 = rtb_VectorConcatenate_d[i + 6] *
      rtb_Plant_States_vel_z_O + (rtb_VectorConcatenate_d[i + 3] *
      rtb_Plant_States_vel_y_O + rtb_VectorConcatenate_d[i] *
      rtb_Plant_States_vel_x_O);

    /* Math: '<S42>/Square' */
    rtb_Square_b[i] = rtb_Sum1_dw_idx_0 * rtb_Sum1_dw_idx_0;

    /* Product: '<S10>/Multiply' */
    rtb_Va_B[i] = rtb_Sum1_dw_idx_0;
  }

  /* Product: '<S41>/Divide' incorporates:
   *  Saturate: '<S41>/Saturation'
   *  Sqrt: '<S42>/Sqrt'
   *  Sum: '<S42>/Sum of Elements'
   */
  rtb_Add_p = rtb_Va_B[1] / fmaxf(sqrtf((rtb_Square_b[0] + rtb_Square_b[1]) +
    rtb_Square_b[2]), 0.1F);

  /* DataTypeConversion: '<S8>/Data Type Conversion2' incorporates:
   *  Product: '<S40>/Divide'
   *  Saturate: '<S40>/Saturation'
   *  Trigonometry: '<S40>/Atan'
   */
  rtb_DataTypeConversion2[0] = atanf(rtb_Va_B[2] / fmaxf(rtb_Va_B[0], 0.1F));

  /* Trigonometry: '<S41>/Asin' */
  if (rtb_Add_p > 1.0F) {
    rtb_Add_p = 1.0F;
  } else {
    if (rtb_Add_p < -1.0F) {
      rtb_Add_p = -1.0F;
    }
  }

  /* DataTypeConversion: '<S8>/Data Type Conversion2' incorporates:
   *  Trigonometry: '<S41>/Asin'
   */
  rtb_DataTypeConversion2[1] = asinf(rtb_Add_p);

  /* DataTypeConversion: '<S8>/Data Type Conversion' incorporates:
   *  Bias: '<S18>/Bias'
   *  DataTypeConversion: '<S18>/Data Type Conversion'
   *  Gain: '<S18>/Gain2'
   *  Inport: '<Root>/Control_Out'
   */
  rtb_Divide_e_idx_1 = ((real32_T)Plant_U.Control_Out.actuator_cmd[4] + -1500.0F)
    * 0.0010471975F;

  /* Gain: '<S24>/Gain2' incorporates:
   *  Bias: '<S17>/Bias'
   *  DataTypeConversion: '<S17>/Data Type Conversion'
   *  DataTypeConversion: '<S8>/Data Type Conversion'
   *  Gain: '<S17>/Gain2'
   *  Inport: '<Root>/Control_Out'
   */
  rtb_TrigonometricFunction2 = -(real_T)(((real32_T)
    Plant_U.Control_Out.actuator_cmd[2] + -1500.0F) * 0.0010471975F);

  /* Lookup2D: '<S24>/CD' */
  rtb_SumofElements = rt_Lookup2D_Normal(Plant_ConstP.pooled5, 7,
    Plant_ConstP.pooled6, 6, Plant_ConstP.CD_Table, rtb_TrigonometricFunction2,
    rtb_DataTypeConversion2[0]);

  /* Lookup2D: '<S24>/CY' */
  /*
   * About '<S24>/CY':
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

  /* Sum: '<S20>/Sum1' incorporates:
   *  Lookup2D: '<S24>/Cl'
   */
  rtb_Sum1[3] = rt_Lookup2D_Normal(Plant_ConstP.pooled5, 7, Plant_ConstP.pooled6,
    6, Plant_ConstP.Cl_Table, rtb_TrigonometricFunction2,
    rtb_DataTypeConversion2[0]);

  /* Lookup2D: '<S24>/Cn' */
  rtb_TrigonometricFunction2 = rt_Lookup2D_Normal(Plant_ConstP.pooled5, 7,
    Plant_ConstP.pooled6, 6, Plant_ConstP.Cn_Table, rtb_TrigonometricFunction2,
    rtb_DataTypeConversion2[0]);

  /* Lookup2D: '<S25>/CD' incorporates:
   *  Gain: '<S25>/Gain1'
   */
  rtb_Cm = rt_Lookup2D_Normal(Plant_ConstP.pooled5, 7, Plant_ConstP.pooled6, 6,
    Plant_ConstP.CD_Table_e, -rtb_Divide_e_idx_1, rtb_DataTypeConversion2[0]);

  /* Sum: '<S20>/Sum1' incorporates:
   *  Gain: '<S25>/Gain1'
   *  Lookup2D: '<S25>/CL'
   */
  rtb_Sum1[1] = rt_Lookup2D_Normal(Plant_ConstP.pooled5, 7, Plant_ConstP.pooled6,
    6, Plant_ConstP.CL_Table, -rtb_Divide_e_idx_1, rtb_DataTypeConversion2[0]);

  /* Lookup2D: '<S25>/Cm' incorporates:
   *  Gain: '<S25>/Gain1'
   */
  rtb_CYr = rt_Lookup2D_Normal(Plant_ConstP.pooled5, 7, Plant_ConstP.pooled6, 6,
    Plant_ConstP.Cm_Table, -rtb_Divide_e_idx_1, rtb_DataTypeConversion2[0]);

  /* Gain: '<S26>/Gain' incorporates:
   *  Bias: '<S19>/Bias'
   *  DataTypeConversion: '<S19>/Data Type Conversion'
   *  DataTypeConversion: '<S8>/Data Type Conversion'
   *  Gain: '<S19>/Gain2'
   *  Inport: '<Root>/Control_Out'
   */
  rtb_Divide_e_idx_1 = -(real_T)(((real32_T)Plant_U.Control_Out.actuator_cmd[5]
    + -1500.0F) * 0.0010471975F);

  /* Lookup2D: '<S26>/CD_dr' */
  rtb_Cl_zA = rt_Lookup2D_Normal(Plant_ConstP.pooled8, 9, Plant_ConstP.pooled6,
    6, Plant_ConstP.CD_dr_Table, rtb_Divide_e_idx_1, rtb_DataTypeConversion2[0]);

  /* Lookup2D: '<S26>/CY_dr' */
  rtb_Cl_yA = rt_Lookup2D_Normal(Plant_ConstP.pooled8, 9, Plant_ConstP.pooled6,
    6, Plant_ConstP.CY_dr_Table, rtb_Divide_e_idx_1, rtb_DataTypeConversion2[0]);

  /* Lookup2D: '<S26>/Cm_dr' */
  /*
   * About '<S26>/Cm_dr':
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

  /* Lookup2D: '<S26>/Cn_dr' */
  rtb_Divide_e_idx_1 = rt_Lookup2D_Normal(Plant_ConstP.pooled8, 9,
    Plant_ConstP.pooled6, 6, Plant_ConstP.Cn_dr_Table, rtb_Divide_e_idx_1,
    rtb_DataTypeConversion2[0]);

  /* Sum: '<S20>/Sum1' */
  rtb_Sum1[0] = (rtb_SumofElements + rtb_Cm) + rtb_Cl_zA;
  rtb_Sum1[2] = rtb_SumofElements1 + rtb_Cl_yA;
  rtb_Sum1[4] = rtb_CYr + rtb_Cl_xA;
  rtb_Sum1[5] = rtb_TrigonometricFunction2 + rtb_Divide_e_idx_1;

  /* Lookup2D: '<S21>/CY_basic' */
  rtb_Cl_xA = rt_Lookup2D_Normal(Plant_ConstP.pooled9, 7, Plant_ConstP.pooled6,
    6, Plant_ConstP.CY_basic_Table, rtb_DataTypeConversion2[1],
    rtb_DataTypeConversion2[0]);

  /* Lookup2D: '<S21>/Cn_basic' */
  /*
   * About '<S21>/Cn_basic':
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

  /* Lookup: '<S21>/CL_basic' */
  rtb_Divide_e_idx_1 = rt_Lookup(Plant_ConstP.pooled10, 23,
    rtb_DataTypeConversion2[0], Plant_ConstP.CL_basic_YData);

  /* Sum: '<S21>/Sum' incorporates:
   *  Lookup2D: '<S21>/CL_beta'
   */
  rtb_Divide_e_idx_1 += rt_Lookup2D_Normal(Plant_ConstP.pooled9, 7,
    Plant_ConstP.pooled6, 6, Plant_ConstP.CL_beta_Table,
    rtb_DataTypeConversion2[1], rtb_DataTypeConversion2[0]);

  /* Sum: '<S21>/Sum1' incorporates:
   *  Lookup: '<S21>/CD_basic'
   *  Lookup2D: '<S21>/CD_beta'
   */
  rtb_CYr = rt_Lookup(Plant_ConstP.pooled10, 23, rtb_DataTypeConversion2[0],
                      Plant_ConstP.CD_basic_YData) + rt_Lookup2D_Normal
    (Plant_ConstP.pooled9, 7, Plant_ConstP.pooled6, 6,
     Plant_ConstP.CD_beta_Table, rtb_DataTypeConversion2[1],
     rtb_DataTypeConversion2[0]);

  /* Sum: '<S21>/Sum2' incorporates:
   *  Lookup: '<S21>/Cm_basic'
   *  Lookup2D: '<S21>/Cm_beta'
   */
  rtb_Cm = rt_Lookup(Plant_ConstP.pooled10, 23, rtb_DataTypeConversion2[0],
                     Plant_ConstP.Cm_basic_YData) + rt_Lookup2D_Normal
    (Plant_ConstP.pooled9, 7, Plant_ConstP.pooled6, 6,
     Plant_ConstP.Cm_beta_Table, rtb_DataTypeConversion2[1],
     rtb_DataTypeConversion2[0]);

  /* Lookup: '<S27>/Cnp' */
  rtb_TrigonometricFunction2 = rt_Lookup(Plant_ConstP.pooled11, 5,
    rtb_DataTypeConversion2[0], Plant_ConstP.Cnp_YData);

  /* Saturate: '<S16>/Saturation' incorporates:
   *  Gain: '<S16>/Gain'
   */
  rtb_Gain_kz = fmaxf(2.0F * rtb_Va_B[0], 0.1F);

  /* Product: '<S16>/Product1' incorporates:
   *  Constant: '<S16>/b'
   *  Delay: '<Root>/Delay'
   *  Product: '<S16>/Product2'
   */
  rtb_Sum1_dw_idx_0 = 1.0F / rtb_Gain_kz * 2.3F;
  rtb_Add_p = rtb_Sum1_dw_idx_0 * Plant_Y.Plant_States.rot_x_B;

  /* Product: '<S16>/Product4' incorporates:
   *  Constant: '<S16>/c'
   *  Delay: '<Root>/Delay'
   */
  rtb_MathFunction1_k = 1.0F / rtb_Gain_kz * 0.32F *
    Plant_Y.Plant_States.rot_y_B;

  /* Product: '<S16>/Product2' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_Gain_kz = rtb_Sum1_dw_idx_0 * Plant_Y.Plant_States.rot_z_B;

  /* Lookup: '<S27>/CYp' */
  rtb_SumofElements = rt_Lookup(Plant_ConstP.pooled11, 5,
    rtb_DataTypeConversion2[0], Plant_ConstP.CYp_YData);

  /* Lookup: '<S27>/Clp' */
  rtb_SumofElements1 = rt_Lookup(Plant_ConstP.pooled11, 5,
    rtb_DataTypeConversion2[0], Plant_ConstP.Clp_YData);

  /* Product: '<S23>/p1' incorporates:
   *  Constant: '<S27>/CDp'
   *  Constant: '<S27>/CLp'
   *  Constant: '<S27>/Cmp'
   *  DataTypeConversion: '<S8>/Data Type Conversion1'
   *  Lookup: '<S27>/CYp'
   *  Lookup: '<S27>/Clp'
   */
  rtb_Sum_nr[0] = 0.0;
  rtb_Sum_nr[1] = 0.0;
  rtb_Sum_nr[2] = rtb_SumofElements * rtb_Add_p;
  rtb_Sum_nr[3] = rtb_SumofElements1 * rtb_Add_p;
  rtb_Sum_nr[4] = 0.0;
  rtb_Sum_nr[5] = rtb_TrigonometricFunction2 * rtb_Add_p;

  /* Lookup: '<S29>/Cnr' */
  rtb_TrigonometricFunction2 = rt_Lookup(Plant_ConstP.pooled11, 5,
    rtb_DataTypeConversion2[0], Plant_ConstP.Cnr_YData);

  /* Lookup: '<S28>/CLq' */
  rtb_SumofElements = rt_Lookup(Plant_ConstP.pooled11, 5,
    rtb_DataTypeConversion2[0], Plant_ConstP.CLq_YData);

  /* Lookup: '<S28>/Cmq' */
  rtb_SumofElements1 = rt_Lookup(Plant_ConstP.pooled11, 5,
    rtb_DataTypeConversion2[0], Plant_ConstP.Cmq_YData);

  /* Product: '<S23>/q1' incorporates:
   *  Constant: '<S28>/CDq'
   *  Constant: '<S28>/CYq'
   *  Constant: '<S28>/Clq'
   *  Constant: '<S28>/Cnq'
   *  DataTypeConversion: '<S8>/Data Type Conversion1'
   *  Lookup: '<S28>/CLq'
   *  Lookup: '<S28>/Cmq'
   */
  tmp[0] = 0.0;
  tmp[1] = rtb_SumofElements * rtb_MathFunction1_k;
  tmp[2] = 0.0;
  tmp[3] = 0.0;
  tmp[4] = rtb_SumofElements1 * rtb_MathFunction1_k;
  tmp[5] = 0.0;

  /* Lookup: '<S29>/CYr' */
  rtb_SumofElements = rt_Lookup(Plant_ConstP.pooled11, 5,
    rtb_DataTypeConversion2[0], Plant_ConstP.CYr_YData);

  /* Lookup: '<S29>/Clr' */
  rtb_SumofElements1 = rt_Lookup(Plant_ConstP.pooled11, 5,
    rtb_DataTypeConversion2[0], Plant_ConstP.Clr_YData);

  /* Product: '<S23>/r1' incorporates:
   *  Constant: '<S29>/CDr'
   *  Constant: '<S29>/CLr'
   *  Constant: '<S29>/Cmr'
   *  DataTypeConversion: '<S8>/Data Type Conversion1'
   *  Lookup: '<S29>/CYr'
   *  Lookup: '<S29>/Clr'
   */
  tmp_0[0] = 0.0;
  tmp_0[1] = 0.0;
  tmp_0[2] = rtb_SumofElements * rtb_Gain_kz;
  tmp_0[3] = rtb_SumofElements1 * rtb_Gain_kz;
  tmp_0[4] = 0.0;
  tmp_0[5] = rtb_TrigonometricFunction2 * rtb_Gain_kz;

  /* Lookup2D: '<S21>/Cl_basic' */
  rtb_SumofElements = rt_Lookup2D_Normal(Plant_ConstP.pooled9, 7,
    Plant_ConstP.pooled6, 6, Plant_ConstP.Cl_basic_Table,
    rtb_DataTypeConversion2[1], rtb_DataTypeConversion2[0]);

  /* Sum: '<S13>/Sum' incorporates:
   *  Lookup2D: '<S21>/Cl_basic'
   */
  rtb_CD_0[0] = rtb_CYr;
  rtb_CD_0[1] = rtb_Divide_e_idx_1;
  rtb_CD_0[2] = rtb_Cl_xA;
  rtb_CD_0[3] = rtb_SumofElements;
  rtb_CD_0[4] = rtb_Cm;
  rtb_CD_0[5] = rtb_Cl_zA;
  for (i = 0; i < 6; i++) {
    /* Sum: '<S23>/Add' incorporates:
     *  Sum: '<S13>/Sum'
     */
    rtb_Sum_nr[i] = (((rtb_Sum_nr[i] + tmp[i]) + tmp_0[i]) + rtb_CD_0[i]) +
      rtb_Sum1[i];
  }

  /* Fcn: '<S22>/Cl_xA' incorporates:
   *  Fcn: '<S22>/Cl_zA'
   */
  rtb_SumofElements1 = -rtb_Sum_nr[0] * cos(rtb_DataTypeConversion2[1]);
  rtb_SumofElements = sin(rtb_DataTypeConversion2[0]);
  rtb_TrigonometricFunction2 = cos(rtb_DataTypeConversion2[0]);
  rtb_Cl_xA = rtb_SumofElements1 * rtb_TrigonometricFunction2 + rtb_Sum_nr[1] *
    rtb_SumofElements;

  /* Fcn: '<S22>/Cl_zA' */
  rtb_Cl_zA = rtb_SumofElements1 * rtb_SumofElements - rtb_Sum_nr[1] *
    rtb_TrigonometricFunction2;

  /* Gain: '<S14>/reference area' incorporates:
   *  Gain: '<S15>/Gain'
   *  Math: '<S15>/Square'
   */
  rtb_Gain_kz = rtb_Va_B[0] * rtb_Va_B[0] * 0.645F * 0.736F;

  /* Product: '<S14>/Product' incorporates:
   *  DataTypeConversion: '<S8>/Data Type Conversion4'
   *  Fcn: '<S22>/Cl_yA'
   */
  rtb_Square_o5[0] = rtb_Gain_kz * (real32_T)rtb_Cl_xA;
  rtb_Square_o5[1] = (real32_T)(-rtb_Sum_nr[0] * sin(rtb_DataTypeConversion2[1])
    + rtb_Sum_nr[2]) * rtb_Gain_kz;
  rtb_Square_o5[2] = rtb_Gain_kz * (real32_T)rtb_Cl_zA;

  /* Sum: '<S1>/Sum1' incorporates:
   *  Constant: '<S39>/cT'
   *  DiscreteIntegrator: '<S36>/Discrete-Time Integrator'
   *  Math: '<S39>/Square'
   *  Product: '<S39>/Multiply'
   *  Sum: '<S35>/Sum of Elements'
   */
  rtb_Sum1_a[0] = ((real32_T)(Plant_DW.DiscreteTimeIntegrator_DSTATE_p[0] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_p[0] * 2.478E-5) + (real32_T)
                   (Plant_DW.DiscreteTimeIntegrator_DSTATE_p[1] *
                    Plant_DW.DiscreteTimeIntegrator_DSTATE_p[1] * 2.478E-5)) +
    rtb_Square_o5[0];
  rtb_Sum1_a[1] = rtb_Square_o5[1];
  rtb_Sum1_a[2] = rtb_Square_o5[2];

  /* Sum: '<S14>/Sum1' incorporates:
   *  DataTypeConversion: '<S8>/Data Type Conversion4'
   *  Gain: '<S14>/reference length'
   *  Product: '<S14>/Product3'
   *  Product: '<S32>/Multiply'
   *  Product: '<S32>/Multiply1'
   *  Product: '<S32>/Multiply2'
   *  Product: '<S33>/Multiply3'
   *  Product: '<S33>/Multiply4'
   *  Product: '<S33>/Multiply5'
   *  Sum: '<S31>/Sum'
   */
  rtb_Sum1_dw_idx_0 = (rtb_Square_o5[1] * Plant_ConstB.Sum_k[2] - rtb_Square_o5
                       [2] * Plant_ConstB.Sum_k[1]) + 2.3F * rtb_Gain_kz *
    (real32_T)rtb_Sum_nr[3];
  rtb_MathFunction1_k = (rtb_Square_o5[2] * Plant_ConstB.Sum_k[0] -
    rtb_Square_o5[0] * Plant_ConstB.Sum_k[2]) + 0.32F * rtb_Gain_kz * (real32_T)
    rtb_Sum_nr[4];
  rtb_Sum1_dw_idx_2 = (rtb_Square_o5[0] * Plant_ConstB.Sum_k[1] - rtb_Square_o5
                       [1] * Plant_ConstB.Sum_k[0]) + 2.3F * rtb_Gain_kz *
    (real32_T)rtb_Sum_nr[5];

  /* Saturate: '<S34>/Saturation' incorporates:
   *  Inport: '<Root>/Control_Out'
   */
  if (Plant_U.Control_Out.actuator_cmd[0] > 2000) {
    tmp_1 = 2000U;
  } else if (Plant_U.Control_Out.actuator_cmd[0] < 1000) {
    tmp_1 = 1000U;
  } else {
    tmp_1 = Plant_U.Control_Out.actuator_cmd[0];
  }

  /* Gain: '<S34>/Gain' incorporates:
   *  Sum: '<S34>/Subtract'
   */
  rtb_Switch_idx_1 = ((real32_T)tmp_1 - 1000.0F) * 0.000999987125F;

  /* RelationalOperator: '<S38>/Compare' incorporates:
   *  Constant: '<S38>/Constant'
   */
  rtb_Compare_c = (rtb_Switch_idx_1 > 0.1F);

  /* Sum: '<S37>/Add' incorporates:
   *  Constant: '<S37>/Constant1'
   *  Gain: '<S37>/Gain1'
   */
  rtb_Switch_idx_1 = 718.078F * rtb_Switch_idx_1 + 88.448F;

  /* Update for DiscreteIntegrator: '<S36>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S36>/Gain'
   *  Product: '<S37>/Multiply'
   *  Saturate: '<S37>/Saturation1'
   *  Sum: '<S36>/Subtract'
   */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_p[0] += ((rtb_Compare_c ?
    rtb_Switch_idx_1 : 0.0F) - Plant_DW.DiscreteTimeIntegrator_DSTATE_p[0]) *
    50.0F * 0.002F;

  /* Saturate: '<S34>/Saturation' incorporates:
   *  Inport: '<Root>/Control_Out'
   */
  if (Plant_U.Control_Out.actuator_cmd[1] > 2000) {
    tmp_1 = 2000U;
  } else if (Plant_U.Control_Out.actuator_cmd[1] < 1000) {
    tmp_1 = 1000U;
  } else {
    tmp_1 = Plant_U.Control_Out.actuator_cmd[1];
  }

  /* Gain: '<S34>/Gain' incorporates:
   *  Sum: '<S34>/Subtract'
   */
  rtb_Switch_idx_1 = ((real32_T)tmp_1 - 1000.0F) * 0.000999987125F;

  /* RelationalOperator: '<S38>/Compare' incorporates:
   *  Constant: '<S38>/Constant'
   */
  rtb_Compare_c = (rtb_Switch_idx_1 > 0.1F);

  /* Sum: '<S37>/Add' incorporates:
   *  Constant: '<S37>/Constant1'
   *  Gain: '<S37>/Gain1'
   */
  rtb_Switch_idx_1 = 718.078F * rtb_Switch_idx_1 + 88.448F;

  /* Update for DiscreteIntegrator: '<S36>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S36>/Gain'
   *  Product: '<S37>/Multiply'
   *  Saturate: '<S37>/Saturation1'
   *  Sum: '<S36>/Subtract'
   */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_p[1] += ((rtb_Compare_c ?
    rtb_Switch_idx_1 : 0.0F) - Plant_DW.DiscreteTimeIntegrator_DSTATE_p[1]) *
    50.0F * 0.002F;

  /* End of Outputs for SubSystem: '<Root>/Actuators' */

  /* Outputs for Atomic SubSystem: '<Root>/Environment1' */
  /* Trigonometry: '<S74>/Trigonometric Function1' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S73>/Gain'
   *  Trigonometry: '<S74>/Trigonometric Function3'
   */
  rtb_Switch_idx_1 = arm_cos_f32(-Plant_Y.Plant_States.psi);
  rtb_VectorConcatenate_f[0] = rtb_Switch_idx_1;

  /* Trigonometry: '<S74>/Trigonometric Function' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S73>/Gain'
   *  Trigonometry: '<S74>/Trigonometric Function2'
   */
  rtb_Switch_idx_2 = arm_sin_f32(-Plant_Y.Plant_States.psi);
  rtb_VectorConcatenate_f[1] = rtb_Switch_idx_2;

  /* SignalConversion: '<S74>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S74>/Constant3'
   */
  rtb_VectorConcatenate_f[2] = 0.0F;

  /* Gain: '<S74>/Gain' */
  rtb_VectorConcatenate_f[3] = -rtb_Switch_idx_2;

  /* Trigonometry: '<S74>/Trigonometric Function3' */
  rtb_VectorConcatenate_f[4] = rtb_Switch_idx_1;

  /* SignalConversion: '<S74>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S74>/Constant4'
   */
  rtb_VectorConcatenate_f[5] = 0.0F;

  /* SignalConversion: '<S74>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_f[6] = Plant_ConstB.VectorConcatenate3_h[0];

  /* Sum: '<S64>/Sum' incorporates:
   *  Inport: '<Root>/Environment_Info'
   */
  rtb_Switch_idx_1 = Plant_U.Environment_Info.hit_point[0] -
    Plant_U.Environment_Info.hit_location[0];

  /* SignalConversion: '<S74>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_f[7] = Plant_ConstB.VectorConcatenate3_h[1];

  /* Sum: '<S64>/Sum' incorporates:
   *  Inport: '<Root>/Environment_Info'
   */
  rtb_Switch_idx_2 = Plant_U.Environment_Info.hit_point[1] -
    Plant_U.Environment_Info.hit_location[1];

  /* SignalConversion: '<S74>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_f[8] = Plant_ConstB.VectorConcatenate3_h[2];

  /* Sum: '<S64>/Sum' incorporates:
   *  Inport: '<Root>/Environment_Info'
   */
  rtb_Switch_idx_3 = Plant_U.Environment_Info.hit_point[2] -
    Plant_U.Environment_Info.hit_location[2];
  for (i = 0; i < 3; i++) {
    /* Product: '<S64>/Multiply2' */
    rtb_Switch_idx_0 = rtb_VectorConcatenate_d[i + 6] * rtb_Switch_idx_3 +
      (rtb_VectorConcatenate_d[i + 3] * rtb_Switch_idx_2 +
       rtb_VectorConcatenate_d[i] * rtb_Switch_idx_1);

    /* Math: '<S79>/Math Function' */
    rtb_MathFunction[i] = rtb_Switch_idx_0 * rtb_Switch_idx_0;

    /* Product: '<S64>/Multiply2' */
    rtb_Square_b[i] = rtb_Switch_idx_0;
  }

  /* Sum: '<S79>/Sum of Elements' */
  rtb_Gain_kz = (rtb_MathFunction[0] + rtb_MathFunction[1]) + rtb_MathFunction[2];

  /* Math: '<S79>/Math Function1' incorporates:
   *  Sum: '<S79>/Sum of Elements'
   *
   * About '<S79>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Gain_kz < 0.0F) {
    rtb_Gain_kz = -sqrtf(fabsf(rtb_Gain_kz));
  } else {
    rtb_Gain_kz = sqrtf(rtb_Gain_kz);
  }

  /* End of Math: '<S79>/Math Function1' */

  /* Switch: '<S79>/Switch' incorporates:
   *  Constant: '<S79>/Constant'
   *  Product: '<S79>/Product'
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

  /* End of Switch: '<S79>/Switch' */
  for (i = 0; i < 3; i++) {
    /* Product: '<S79>/Divide' */
    rtb_Add_i[i] = rtb_Divide_g[i] / rtb_Divide_g[3];

    /* Product: '<S64>/Multiply1' */
    rtb_Sum_jq[i] = rtb_VectorConcatenate_d[i + 6] * rtb_Plant_States_vel_z_O +
      (rtb_VectorConcatenate_d[i + 3] * rtb_Plant_States_vel_y_O +
       rtb_VectorConcatenate_d[i] * rtb_Plant_States_vel_x_O);
  }

  /* Product: '<S85>/Multiply' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_Square_b[0] = Plant_Y.Plant_States.rot_y_B * rtb_Add_i[2];

  /* Product: '<S85>/Multiply1' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_Square_b[1] = Plant_Y.Plant_States.rot_z_B * rtb_Add_i[0];

  /* Product: '<S85>/Multiply2' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_Square_b[2] = Plant_Y.Plant_States.rot_x_B * rtb_Add_i[1];

  /* Product: '<S86>/Multiply3' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_VectorConcatenate_on[0] = Plant_Y.Plant_States.rot_z_B * rtb_Add_i[1];

  /* Product: '<S86>/Multiply4' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_VectorConcatenate_on[1] = Plant_Y.Plant_States.rot_x_B * rtb_Add_i[2];

  /* Product: '<S86>/Multiply5' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_VectorConcatenate_on[2] = Plant_Y.Plant_States.rot_y_B * rtb_Add_i[0];

  /* DotProduct: '<S77>/Dot Product' */
  rtb_Switch_idx_0 = 0.0F;
  for (i = 0; i < 3; i++) {
    /* Sum: '<S78>/Sum1' incorporates:
     *  Sum: '<S82>/Sum'
     */
    rtb_Switch_idx_1 = (rtb_Square_b[i] - rtb_VectorConcatenate_on[i]) +
      rtb_Sum_jq[i];

    /* Product: '<S64>/Multiply' incorporates:
     *  Inport: '<Root>/Environment_Info'
     */
    rtb_Switch_idx_3 = rtb_VectorConcatenate_d[i + 6] *
      Plant_U.Environment_Info.hit_normal[2] + (rtb_VectorConcatenate_d[i + 3] *
      Plant_U.Environment_Info.hit_normal[1] + rtb_VectorConcatenate_d[i] *
      Plant_U.Environment_Info.hit_normal[0]);

    /* DotProduct: '<S77>/Dot Product' */
    rtb_Switch_idx_0 += rtb_Switch_idx_1 * rtb_Switch_idx_3;

    /* Sum: '<S78>/Sum1' */
    rtb_Square_b[i] = rtb_Switch_idx_1;

    /* Product: '<S64>/Multiply' incorporates:
     *  Product: '<S70>/Multiply'
     */
    rtb_VectorConcatenate_on[i] = rtb_Switch_idx_3;
  }

  /* Sum: '<S77>/Sum' incorporates:
   *  DotProduct: '<S77>/Dot Product'
   *  Product: '<S64>/Multiply'
   *  Product: '<S77>/Multiply'
   */
  rtb_Switch_idx_2 = rtb_Square_b[0] - rtb_Switch_idx_0 *
    rtb_VectorConcatenate_on[0];

  /* Math: '<S81>/Math Function' */
  rtb_MathFunction_m[0] = rtb_Switch_idx_2 * rtb_Switch_idx_2;

  /* Sum: '<S77>/Sum' incorporates:
   *  DotProduct: '<S77>/Dot Product'
   *  Product: '<S64>/Multiply'
   *  Product: '<S77>/Multiply'
   */
  rtb_MathFunction[0] = rtb_Switch_idx_2;
  rtb_Switch_idx_2 = rtb_Square_b[1] - rtb_Switch_idx_0 *
    rtb_VectorConcatenate_on[1];

  /* Math: '<S81>/Math Function' */
  rtb_MathFunction_m[1] = rtb_Switch_idx_2 * rtb_Switch_idx_2;

  /* Sum: '<S77>/Sum' incorporates:
   *  DotProduct: '<S77>/Dot Product'
   *  Product: '<S64>/Multiply'
   *  Product: '<S77>/Multiply'
   */
  rtb_MathFunction[1] = rtb_Switch_idx_2;
  rtb_Switch_idx_2 = rtb_Square_b[2] - rtb_Switch_idx_0 *
    rtb_VectorConcatenate_on[2];

  /* Sum: '<S81>/Sum of Elements' incorporates:
   *  Math: '<S81>/Math Function'
   */
  rtb_Gain_kz = (rtb_MathFunction_m[0] + rtb_MathFunction_m[1]) +
    rtb_Switch_idx_2 * rtb_Switch_idx_2;

  /* Math: '<S81>/Math Function1' incorporates:
   *  Sum: '<S81>/Sum of Elements'
   *
   * About '<S81>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Gain_kz < 0.0F) {
    rtb_Gain_kz = -sqrtf(fabsf(rtb_Gain_kz));
  } else {
    rtb_Gain_kz = sqrtf(rtb_Gain_kz);
  }

  /* End of Math: '<S81>/Math Function1' */

  /* Switch: '<S81>/Switch' incorporates:
   *  Constant: '<S81>/Constant'
   *  Product: '<S81>/Product'
   */
  if (rtb_Gain_kz > 0.0F) {
    rtb_Switch_idx_0 = rtb_MathFunction[0];
    rtb_Switch_idx_1 = rtb_MathFunction[1];
    rtb_Switch_idx_3 = rtb_Gain_kz;
  } else {
    rtb_Switch_idx_0 = 0.0F;
    rtb_Switch_idx_1 = 0.0F;
    rtb_Switch_idx_2 = 0.0F;
    rtb_Switch_idx_3 = 1.0F;
  }

  /* End of Switch: '<S81>/Switch' */

  /* Sqrt: '<S80>/Sqrt' incorporates:
   *  Math: '<S80>/Square'
   *  Product: '<S64>/Multiply'
   *  Sum: '<S80>/Sum of Elements'
   */
  rtb_Gain_kz = sqrtf((rtb_VectorConcatenate_on[0] * rtb_VectorConcatenate_on[0]
                       + rtb_VectorConcatenate_on[1] * rtb_VectorConcatenate_on
                       [1]) + rtb_VectorConcatenate_on[2] *
                      rtb_VectorConcatenate_on[2]);

  /* Product: '<S77>/Multiply3' incorporates:
   *  Product: '<S81>/Divide'
   */
  rtb_MathFunction_k = rtb_Switch_idx_0 / rtb_Switch_idx_3 * rtb_Gain_kz;

  /* DotProduct: '<S77>/Dot Product2' */
  rtb_Switch_idx_0 = rtb_Square_b[0] * rtb_MathFunction_k;

  /* Product: '<S77>/Multiply3' incorporates:
   *  Product: '<S81>/Divide'
   */
  rtb_MathFunction_m[0] = rtb_MathFunction_k;
  rtb_MathFunction_k = rtb_Switch_idx_1 / rtb_Switch_idx_3 * rtb_Gain_kz;

  /* DotProduct: '<S77>/Dot Product2' */
  rtb_Switch_idx_0 += rtb_Square_b[1] * rtb_MathFunction_k;

  /* Product: '<S77>/Multiply3' incorporates:
   *  Product: '<S81>/Divide'
   */
  rtb_MathFunction_m[1] = rtb_MathFunction_k;
  rtb_MathFunction_k = rtb_Switch_idx_2 / rtb_Switch_idx_3 * rtb_Gain_kz;

  /* DotProduct: '<S77>/Dot Product2' */
  rtb_Switch_idx_0 += rtb_Square_b[2] * rtb_MathFunction_k;

  /* Gain: '<S77>/Gain3' incorporates:
   *  Constant: '<S77>/Constant'
   *  DotProduct: '<S77>/Dot Product2'
   *  Product: '<S77>/Divide'
   */
  rtb_Switch_idx_1 = rtb_Switch_idx_0 / 0.01F * -3.0F;

  /* Product: '<S77>/Multiply4' */
  rtb_Multiply4_idx_0 = rtb_Switch_idx_1 * rtb_MathFunction_m[0];
  rtb_Multiply4_idx_1 = rtb_Switch_idx_1 * rtb_MathFunction_m[1];

  /* RelationalOperator: '<S75>/Compare' incorporates:
   *  Constant: '<S75>/Constant'
   *  DotProduct: '<S64>/Dot Product2'
   *  Product: '<S64>/Multiply'
   */
  rtb_Compare_c = ((rtb_VectorConcatenate_on[0] * rtb_Sum_jq[0] +
                    rtb_VectorConcatenate_on[1] * rtb_Sum_jq[1]) +
                   rtb_VectorConcatenate_on[2] * rtb_Sum_jq[2] < 0.0F);

  /* Product: '<S87>/Multiply' incorporates:
   *  Product: '<S64>/Multiply'
   */
  rtb_MathFunction_m[0] = rtb_Add_i[1] * rtb_VectorConcatenate_on[2];

  /* Product: '<S87>/Multiply1' incorporates:
   *  Product: '<S64>/Multiply'
   */
  rtb_MathFunction_m[1] = rtb_Add_i[2] * rtb_VectorConcatenate_on[0];

  /* Product: '<S87>/Multiply2' incorporates:
   *  Product: '<S64>/Multiply'
   */
  rtb_MathFunction_m[2] = rtb_Add_i[0] * rtb_VectorConcatenate_on[1];

  /* Sum: '<S83>/Sum' incorporates:
   *  Product: '<S64>/Multiply'
   *  Product: '<S88>/Multiply3'
   *  Product: '<S88>/Multiply4'
   *  Product: '<S88>/Multiply5'
   */
  rtb_MathFunction_m[0] -= rtb_Add_i[2] * rtb_VectorConcatenate_on[1];
  rtb_MathFunction_m[1] -= rtb_Add_i[0] * rtb_VectorConcatenate_on[2];
  rtb_MathFunction_m[2] -= rtb_Add_i[1] * rtb_VectorConcatenate_on[0];

  /* Product: '<S78>/Divide2' incorporates:
   *  Constant: '<S78>/Inertia_Matrix'
   */
  rt_mldivide_U1f3x3_U2f3_Yf3x1(Plant_ConstP.pooled32, rtb_MathFunction_m,
    rtb_Sum_jq);

  /* Product: '<S89>/Multiply' */
  rtb_MathFunction[0] = rtb_Sum_jq[1] * rtb_Add_i[2];

  /* Product: '<S89>/Multiply1' */
  rtb_MathFunction[1] = rtb_Sum_jq[2] * rtb_Add_i[0];

  /* Product: '<S89>/Multiply2' */
  rtb_MathFunction[2] = rtb_Sum_jq[0] * rtb_Add_i[1];

  /* Sum: '<S84>/Sum' incorporates:
   *  Product: '<S90>/Multiply3'
   */
  rtb_Switch_idx_2 = rtb_MathFunction[0] - rtb_Sum_jq[2] * rtb_Add_i[1];

  /* DotProduct: '<S78>/Dot Product1' incorporates:
   *  Product: '<S64>/Multiply'
   */
  rtb_Switch_idx_0 = rtb_Switch_idx_2 * rtb_VectorConcatenate_on[0];

  /* Sum: '<S84>/Sum' incorporates:
   *  Product: '<S90>/Multiply4'
   */
  rtb_MathFunction[0] = rtb_Switch_idx_2;
  rtb_Switch_idx_2 = rtb_MathFunction[1] - rtb_Sum_jq[0] * rtb_Add_i[2];

  /* DotProduct: '<S78>/Dot Product1' incorporates:
   *  Product: '<S64>/Multiply'
   */
  rtb_Switch_idx_0 += rtb_Switch_idx_2 * rtb_VectorConcatenate_on[1];

  /* Sum: '<S84>/Sum' incorporates:
   *  Product: '<S90>/Multiply5'
   */
  rtb_MathFunction[1] = rtb_Switch_idx_2;
  rtb_Switch_idx_2 = rtb_MathFunction[2] - rtb_Sum_jq[1] * rtb_Add_i[0];

  /* DotProduct: '<S78>/Dot Product1' incorporates:
   *  Product: '<S64>/Multiply'
   */
  rtb_Switch_idx_0 += rtb_Switch_idx_2 * rtb_VectorConcatenate_on[2];

  /* Sum: '<S84>/Sum' */
  rtb_MathFunction[2] = rtb_Switch_idx_2;

  /* Product: '<S78>/Divide1' incorporates:
   *  Abs: '<S78>/Abs'
   *  Constant: '<S78>/mass_inv'
   *  Constant: '<S78>/period'
   *  DotProduct: '<S78>/Dot Product'
   *  DotProduct: '<S78>/Dot Product1'
   *  Gain: '<S78>/Gain'
   *  Product: '<S64>/Multiply'
   *  Product: '<S78>/Divide'
   *  Product: '<S78>/Multiply3'
   *  Sum: '<S78>/Add1'
   */
  rtb_Gain_kz = fabsf(-(((rtb_Square_b[0] * rtb_VectorConcatenate_on[0] +
    rtb_Square_b[1] * rtb_VectorConcatenate_on[1]) + rtb_Square_b[2] *
    rtb_VectorConcatenate_on[2]) * Plant_ConstB.Add_o) * (1.0F /
    (rtb_Switch_idx_0 + 0.333333343F))) / 0.002F;

  /* Sum: '<S64>/Sum1' incorporates:
   *  Product: '<S64>/Multiply'
   *  Product: '<S64>/Multiply7'
   *  Product: '<S77>/Multiply4'
   *  Product: '<S78>/Multiply4'
   */
  rtb_Multiply4_idx_0 += rtb_Compare_c ? rtb_Gain_kz * rtb_VectorConcatenate_on
    [0] : 0.0F;
  rtb_Multiply4_idx_1 += rtb_Compare_c ? rtb_Gain_kz * rtb_VectorConcatenate_on
    [1] : 0.0F;
  rtb_Multiply4 = rtb_Switch_idx_1 * rtb_MathFunction_k + (rtb_Compare_c ?
    rtb_Gain_kz * rtb_VectorConcatenate_on[2] : 0.0F);

  /* RelationalOperator: '<S91>/Compare' incorporates:
   *  Constant: '<S91>/Constant'
   *  Delay: '<Root>/Delay'
   */
  rtb_Compare_c = (Plant_Y.Plant_States.h_R < 0.0F);

  /* Switch: '<S69>/Switch2' incorporates:
   *  Gain: '<S92>/Gain5'
   *  Gain: '<S92>/Gain6'
   *  Product: '<S92>/Multiply'
   *  SignalConversion: '<S92>/TmpSignal ConversionAtMultiplyInport2'
   */
  if (rtb_Compare_c) {
    /* Switch: '<S92>/Switch1' incorporates:
     *  Constant: '<S92>/mg'
     *  Constant: '<S94>/Constant'
     *  Delay: '<Root>/Delay'
     *  Gain: '<S92>/Gain'
     *  RelationalOperator: '<S94>/Compare'
     *  Sum: '<S92>/Add'
     */
    if (Plant_Y.Plant_States.h_R <= -0.05F) {
      /* Switch: '<S92>/Switch3' incorporates:
       *  Constant: '<S92>/mg'
       *  Constant: '<S95>/Constant'
       *  Gain: '<S92>/Gain1'
       *  Gain: '<S92>/Gain2'
       *  Gain: '<S92>/Gain4'
       *  RelationalOperator: '<S95>/Compare'
       *  Sum: '<S92>/Add1'
       *  Sum: '<S92>/Add2'
       */
      if (Plant_Y.Plant_States.h_R <= -0.1F) {
        rtb_Switch_idx_1 = (Plant_Y.Plant_States.h_R - 29.418F) - 50.0F *
          Plant_Y.Plant_States.vel_z_O;
      } else {
        rtb_Switch_idx_1 = (0.5F * Plant_Y.Plant_States.h_R - 29.418F) - 20.0F *
          Plant_Y.Plant_States.vel_z_O;
      }

      /* End of Switch: '<S92>/Switch3' */
    } else {
      rtb_Switch_idx_1 = -29.418F - 10.0F * Plant_Y.Plant_States.vel_z_O;
    }

    /* End of Switch: '<S92>/Switch1' */
    for (i = 0; i < 3; i++) {
      rtb_Square_o5[i] = rtb_VectorConcatenate_d[i + 6] * rtb_Switch_idx_1 +
        (rtb_VectorConcatenate_d[i + 3] * -rtb_Plant_States_vel_y_O +
         rtb_VectorConcatenate_d[i] * -rtb_Plant_States_vel_x_O);
    }
  } else {
    rtb_Square_o5[0] = 0.0F;
    rtb_Square_o5[1] = 0.0F;
    rtb_Square_o5[2] = 0.0F;
  }

  /* End of Switch: '<S69>/Switch2' */
  for (i = 0; i < 3; i++) {
    /* Product: '<S72>/Multiply' */
    rtb_Switch_idx_1 = rtb_VectorConcatenate_f[i + 6] * rtb_Plant_States_vel_z_O
      + (rtb_VectorConcatenate_f[i + 3] * rtb_Plant_States_vel_y_O +
         rtb_VectorConcatenate_f[i] * rtb_Plant_States_vel_x_O);

    /* Signum: '<S72>/Sign1' */
    if (rtb_Switch_idx_1 < 0.0F) {
      rtb_Switch_idx_2 = -1.0F;
    } else if (rtb_Switch_idx_1 > 0.0F) {
      rtb_Switch_idx_2 = 1.0F;
    } else {
      rtb_Switch_idx_2 = rtb_Switch_idx_1;
    }

    /* End of Signum: '<S72>/Sign1' */

    /* Gain: '<S72>/Gain' incorporates:
     *  Math: '<S72>/Square1'
     *  Product: '<S72>/Multiply5'
     */
    rtb_Square_b[i] = rtb_Switch_idx_1 * rtb_Switch_idx_1 * rtb_Switch_idx_2 *
      -0.02F;
  }

  /* Product: '<S72>/Multiply1' incorporates:
   *  Math: '<S72>/Square'
   */
  for (i = 0; i < 3; i++) {
    rtb_Add_i[i] = rtb_VectorConcatenate_f[3 * i + 2] * rtb_Square_b[2] +
      (rtb_VectorConcatenate_f[3 * i + 1] * rtb_Square_b[1] +
       rtb_VectorConcatenate_f[3 * i] * rtb_Square_b[0]);
  }

  /* End of Product: '<S72>/Multiply1' */

  /* DotProduct: '<S70>/Dot Product' */
  rtb_Square_l = 0.0F;
  for (i = 0; i < 3; i++) {
    /* Product: '<S72>/Multiply2' */
    rtb_Switch_idx_1 = rtb_VectorConcatenate_d[i + 6];

    /* Sum: '<S5>/Add2' incorporates:
     *  Inport: '<Root>/Environment_Info'
     *  Product: '<S68>/Multiply3'
     *  Product: '<S72>/Multiply2'
     */
    rtb_Switch_idx_1 = (((Plant_U.Environment_Info.force[i] + rtb_Square_o5[i])
                         + (rtb_Switch_idx_1 * rtb_Add_i[2] +
      (rtb_VectorConcatenate_d[i + 3] * rtb_Add_i[1] + rtb_VectorConcatenate_d[i]
       * rtb_Add_i[0]))) + rtb_Switch_idx_1 * 29.43F) + rtb_Sum1_a[i];

    /* DotProduct: '<S70>/Dot Product' incorporates:
     *  Product: '<S70>/Multiply'
     */
    rtb_Square_l += rtb_Switch_idx_1 * rtb_VectorConcatenate_on[i];

    /* Sum: '<S5>/Add2' */
    rtb_Square_o5[i] = rtb_Switch_idx_1;
  }

  /* Product: '<S70>/Multiply1' incorporates:
   *  Constant: '<S96>/Constant'
   *  DotProduct: '<S70>/Dot Product'
   *  RelationalOperator: '<S96>/Compare'
   */
  rtb_Switch_idx_1 = rtb_Square_l < 0.0F ? rtb_Square_l : 0.0F;

  /* Sum: '<S5>/Add' incorporates:
   *  Product: '<S70>/Multiply'
   *  Product: '<S70>/Multiply1'
   *  Sum: '<S70>/Sum'
   */
  rtb_Multiply4_idx_0 += rtb_Square_o5[0] - rtb_Switch_idx_1 *
    rtb_VectorConcatenate_on[0];
  rtb_Multiply4_idx_1 += rtb_Square_o5[1] - rtb_Switch_idx_1 *
    rtb_VectorConcatenate_on[1];
  rtb_Multiply4 += rtb_Square_o5[2] - rtb_Switch_idx_1 *
    rtb_VectorConcatenate_on[2];

  /* Switch: '<S69>/Switch1' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S93>/Gain1'
   *  Gain: '<S93>/Gain2'
   *  Gain: '<S93>/Gain3'
   *  Sum: '<S93>/Subtract'
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

  /* End of Switch: '<S69>/Switch1' */

  /* Signum: '<S72>/Sign' incorporates:
   *  Delay: '<Root>/Delay'
   */
  if (Plant_Y.Plant_States.rot_x_B < 0.0F) {
    rtb_Gain_kz = -1.0F;
  } else if (Plant_Y.Plant_States.rot_x_B > 0.0F) {
    rtb_Gain_kz = 1.0F;
  } else {
    rtb_Gain_kz = Plant_Y.Plant_States.rot_x_B;
  }

  /* Outputs for Atomic SubSystem: '<Root>/Actuators' */
  /* Sum: '<S5>/Add3' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S72>/Gain1'
   *  Inport: '<Root>/Environment_Info'
   *  Math: '<S72>/Square2'
   *  Product: '<S72>/Multiply3'
   *  Sum: '<S1>/Sum'
   */
  rtb_Square_o5[0] = Plant_Y.Plant_States.rot_x_B * Plant_Y.Plant_States.rot_x_B
    * rtb_Gain_kz * -0.005F + ((rtb_Sum1_dw_idx_0 +
    Plant_U.Environment_Info.torque[0]) + rtb_Square_o5[0]);

  /* End of Outputs for SubSystem: '<Root>/Actuators' */

  /* Signum: '<S72>/Sign' incorporates:
   *  Delay: '<Root>/Delay'
   */
  if (Plant_Y.Plant_States.rot_y_B < 0.0F) {
    rtb_Gain_kz = -1.0F;
  } else if (Plant_Y.Plant_States.rot_y_B > 0.0F) {
    rtb_Gain_kz = 1.0F;
  } else {
    rtb_Gain_kz = Plant_Y.Plant_States.rot_y_B;
  }

  /* Outputs for Atomic SubSystem: '<Root>/Actuators' */
  /* Sum: '<S5>/Add3' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S72>/Gain1'
   *  Inport: '<Root>/Environment_Info'
   *  Math: '<S72>/Square2'
   *  Product: '<S72>/Multiply3'
   *  Sum: '<S1>/Sum'
   */
  rtb_Square_o5[1] = Plant_Y.Plant_States.rot_y_B * Plant_Y.Plant_States.rot_y_B
    * rtb_Gain_kz * -0.005F + ((rtb_MathFunction1_k +
    Plant_U.Environment_Info.torque[1]) + rtb_Square_o5[1]);

  /* End of Outputs for SubSystem: '<Root>/Actuators' */

  /* Signum: '<S72>/Sign' incorporates:
   *  Delay: '<Root>/Delay'
   */
  if (Plant_Y.Plant_States.rot_z_B < 0.0F) {
    rtb_Gain_kz = -1.0F;
  } else if (Plant_Y.Plant_States.rot_z_B > 0.0F) {
    rtb_Gain_kz = 1.0F;
  } else {
    rtb_Gain_kz = Plant_Y.Plant_States.rot_z_B;
  }

  /* Outputs for Atomic SubSystem: '<Root>/Actuators' */
  /* Sum: '<S5>/Add3' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S72>/Gain1'
   *  Inport: '<Root>/Environment_Info'
   *  Math: '<S72>/Square2'
   *  Product: '<S72>/Multiply3'
   *  Sum: '<S1>/Sum'
   */
  rtb_Square_l = Plant_Y.Plant_States.rot_z_B * Plant_Y.Plant_States.rot_z_B *
    rtb_Gain_kz * -0.005F + ((rtb_Sum1_dw_idx_2 +
    Plant_U.Environment_Info.torque[2]) + rtb_Square_o5[2]);

  /* End of Outputs for SubSystem: '<Root>/Actuators' */

  /* Sum: '<S5>/Add1' incorporates:
   *  Product: '<S64>/Multiply6'
   */
  rtb_MathFunction_m[0] = rtb_Square_o5[0];
  rtb_MathFunction_m[1] = rtb_Square_o5[1];

  /* RelationalOperator: '<S65>/Compare' incorporates:
   *  Constant: '<S65>/Constant'
   *  Inport: '<Root>/Environment_Info'
   *  Math: '<S71>/Square'
   *  Sqrt: '<S71>/Sqrt'
   *  Sum: '<S71>/Sum of Elements'
   */
  rtb_Compare_c = (sqrtf((Plant_U.Environment_Info.hit_normal[0] *
    Plant_U.Environment_Info.hit_normal[0] +
    Plant_U.Environment_Info.hit_normal[1] *
    Plant_U.Environment_Info.hit_normal[1]) +
    Plant_U.Environment_Info.hit_normal[2] *
    Plant_U.Environment_Info.hit_normal[2]) > 0.0F);

  /* RelationalOperator: '<S66>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S66>/Delay Input1'
   *
   * Block description for '<S66>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_FixPtRelationalOperator = ((int32_T)rtb_Compare_c > (int32_T)
    Plant_DW.DelayInput1_DSTATE);

  /* Update for UnitDelay: '<S66>/Delay Input1'
   *
   * Block description for '<S66>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Plant_DW.DelayInput1_DSTATE = rtb_Compare_c;

  /* End of Outputs for SubSystem: '<Root>/Environment1' */

  /* Outputs for Atomic SubSystem: '<Root>/Kinematic_Equation' */
  /* DiscreteIntegrator: '<S101>/Discrete-Time Integrator' */
  if (Plant_DW.DiscreteTimeIntegrator_PrevRese != 0) {
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[0] = Plant_ConstB.quat0[0];
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[1] = Plant_ConstB.quat0[1];
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[2] = Plant_ConstB.quat0[2];
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[3] = Plant_ConstB.quat0[3];
  }

  rtb_Switch_idx_0 = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[0];
  rtb_Switch_idx_1 = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[1];
  rtb_Switch_idx_2 = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[2];
  rtb_Switch_idx_3 = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[3];

  /* Sqrt: '<S105>/Sqrt' incorporates:
   *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator'
   *  Math: '<S105>/Square'
   *  Sqrt: '<S116>/Sqrt'
   *  Sqrt: '<S121>/Sqrt'
   *  Sum: '<S105>/Sum of Elements'
   */
  rtb_Sum1_dw_idx_0 = sqrtf(((Plant_DW.DiscreteTimeIntegrator_DSTATE_k[0] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[0] +
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[1] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[1]) +
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[2] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[2]) +
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[3] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[3]);

  /* Product: '<S104>/Divide' incorporates:
   *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator'
   *  Sqrt: '<S105>/Sqrt'
   */
  rtb_Plant_States_vel_x_O = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[0] /
    rtb_Sum1_dw_idx_0;
  rtb_Plant_States_vel_y_O = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[1] /
    rtb_Sum1_dw_idx_0;
  rtb_Plant_States_vel_z_O = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[2] /
    rtb_Sum1_dw_idx_0;
  rtb_MathFunction_k = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[3] /
    rtb_Sum1_dw_idx_0;

  /* SignalConversion: '<S106>/ConcatBufferAtMatrix ConcatenateIn1' incorporates:
   *  Constant: '<S106>/Constant'
   */
  rtb_MatrixConcatenate4[0] = 0.0F;

  /* DiscreteIntegrator: '<S97>/Discrete-Time Integrator' */
  if (Plant_DW.DiscreteTimeIntegrator_PrevRe_p != 0) {
    Plant_DW.DiscreteTimeIntegrator_DSTATE_i[0] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_i[1] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_i[2] = 0.0F;
  }

  rtb_Square_o5[0] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[0];
  rtb_Square_o5[1] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[1];
  rtb_Square_o5[2] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[2];

  /* SignalConversion: '<S106>/ConcatBufferAtMatrix ConcatenateIn2' incorporates:
   *  DiscreteIntegrator: '<S97>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[1] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[0];

  /* SignalConversion: '<S106>/ConcatBufferAtMatrix ConcatenateIn3' incorporates:
   *  DiscreteIntegrator: '<S97>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[2] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[1];

  /* SignalConversion: '<S106>/ConcatBufferAtMatrix ConcatenateIn4' incorporates:
   *  DiscreteIntegrator: '<S97>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[3] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[2];

  /* Gain: '<S106>/Gain1' incorporates:
   *  DiscreteIntegrator: '<S97>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[4] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_i[0];

  /* SignalConversion: '<S106>/ConcatBufferAtMatrix Concatenate1In2' incorporates:
   *  Constant: '<S106>/Constant1'
   */
  rtb_MatrixConcatenate4[5] = 0.0F;

  /* Gain: '<S106>/Gain2' incorporates:
   *  DiscreteIntegrator: '<S97>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[6] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_i[2];

  /* SignalConversion: '<S106>/ConcatBufferAtMatrix Concatenate1In4' incorporates:
   *  DiscreteIntegrator: '<S97>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[7] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[1];

  /* Gain: '<S106>/Gain3' incorporates:
   *  DiscreteIntegrator: '<S97>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[8] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_i[1];

  /* SignalConversion: '<S106>/ConcatBufferAtMatrix Concatenate2In2' incorporates:
   *  DiscreteIntegrator: '<S97>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[9] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[2];

  /* SignalConversion: '<S106>/ConcatBufferAtMatrix Concatenate2In3' incorporates:
   *  Constant: '<S106>/Constant2'
   */
  rtb_MatrixConcatenate4[10] = 0.0F;

  /* Gain: '<S106>/Gain4' incorporates:
   *  DiscreteIntegrator: '<S97>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[11] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_i[0];

  /* Gain: '<S106>/Gain6' incorporates:
   *  DiscreteIntegrator: '<S97>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[12] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_i[2];

  /* Gain: '<S106>/Gain7' incorporates:
   *  DiscreteIntegrator: '<S97>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[13] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_i[1];

  /* SignalConversion: '<S106>/ConcatBufferAtMatrix Concatenate3In3' incorporates:
   *  DiscreteIntegrator: '<S97>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[14] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[0];

  /* SignalConversion: '<S106>/ConcatBufferAtMatrix Concatenate3In4' incorporates:
   *  Constant: '<S106>/Constant3'
   */
  rtb_MatrixConcatenate4[15] = 0.0F;

  /* Product: '<S112>/Divide' incorporates:
   *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator'
   */
  rtb_Gain_kz = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[0] / rtb_Sum1_dw_idx_0;
  rtb_Gain_e_tmp_0 = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[1] /
    rtb_Sum1_dw_idx_0;
  tmp_2 = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[2] / rtb_Sum1_dw_idx_0;
  rtb_Gain_e_tmp_1 = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[3] /
    rtb_Sum1_dw_idx_0;

  /* Product: '<S117>/Divide' incorporates:
   *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator'
   */
  rtb_Divide_k_idx_0 = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[0] /
    rtb_Sum1_dw_idx_0;
  rtb_Sum_c4 = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[1] / rtb_Sum1_dw_idx_0;
  rtb_Divide_k_idx_2 = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[2] /
    rtb_Sum1_dw_idx_0;
  rtb_Divide_k_idx_3 = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[3] /
    rtb_Sum1_dw_idx_0;

  /* Product: '<S97>/Multiply' incorporates:
   *  Constant: '<S97>/Inertia_Matrix'
   *  DiscreteIntegrator: '<S97>/Discrete-Time Integrator'
   */
  for (i = 0; i < 3; i++) {
    rtb_Add_i[i] = Plant_ConstP.pooled32[i + 6] *
      Plant_DW.DiscreteTimeIntegrator_DSTATE_i[2] + (Plant_ConstP.pooled32[i + 3]
      * Plant_DW.DiscreteTimeIntegrator_DSTATE_i[1] + Plant_ConstP.pooled32[i] *
      Plant_DW.DiscreteTimeIntegrator_DSTATE_i[0]);
  }

  /* End of Product: '<S97>/Multiply' */

  /* Product: '<S102>/Multiply' incorporates:
   *  DiscreteIntegrator: '<S97>/Discrete-Time Integrator'
   */
  rtb_Sum_fw[0] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[1] * rtb_Add_i[2];

  /* Product: '<S102>/Multiply1' incorporates:
   *  DiscreteIntegrator: '<S97>/Discrete-Time Integrator'
   */
  rtb_Sum_fw[1] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[2] * rtb_Add_i[0];

  /* Product: '<S102>/Multiply2' incorporates:
   *  DiscreteIntegrator: '<S97>/Discrete-Time Integrator'
   */
  rtb_Sum_fw[2] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[0] * rtb_Add_i[1];

  /* Product: '<S103>/Multiply3' incorporates:
   *  DiscreteIntegrator: '<S97>/Discrete-Time Integrator'
   */
  rtb_Sum_jq[0] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[2] * rtb_Add_i[1];

  /* Product: '<S103>/Multiply4' incorporates:
   *  DiscreteIntegrator: '<S97>/Discrete-Time Integrator'
   */
  rtb_Sum_jq[1] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[0] * rtb_Add_i[2];

  /* Product: '<S103>/Multiply5' incorporates:
   *  DiscreteIntegrator: '<S97>/Discrete-Time Integrator'
   */
  rtb_Sum_jq[2] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[1] * rtb_Add_i[0];

  /* DiscreteIntegrator: '<S98>/Discrete-Time Integrator' */
  if (rtb_FixPtRelationalOperator || (Plant_DW.DiscreteTimeIntegrator_PrevRe_g
       != 0)) {
    Plant_DW.DiscreteTimeIntegrator_DSTATE_b[0] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_b[1] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_b[2] = 0.0F;
  }

  /* Product: '<S115>/Product3' incorporates:
   *  Product: '<S112>/Divide'
   *  Product: '<S113>/Product6'
   */
  rtb_Sum1_dw_idx_0 = tmp_2 * tmp_2;

  /* Product: '<S115>/Product6' incorporates:
   *  Product: '<S112>/Divide'
   *  Product: '<S113>/Product9'
   */
  rtb_Sum_i_idx_2 = rtb_Gain_e_tmp_0 * rtb_Gain_e_tmp_1;

  /* Product: '<S115>/Product7' incorporates:
   *  Product: '<S112>/Divide'
   *  Product: '<S113>/Product2'
   */
  rtb_Add_j0_tmp = rtb_Gain_kz * tmp_2;

  /* Sum: '<S115>/Sum2' incorporates:
   *  Constant: '<S115>/Constant'
   *  Product: '<S112>/Divide'
   *  Product: '<S115>/Product2'
   *  Sum: '<S114>/Sum1'
   */
  rtb_MathFunction1_k = 0.5F - rtb_Gain_e_tmp_0 * rtb_Gain_e_tmp_0;

  /* Product: '<S115>/Product1' incorporates:
   *  Product: '<S112>/Divide'
   *  Product: '<S114>/Product2'
   */
  rtb_Sum1_dw_idx_2 = rtb_Gain_kz * rtb_Gain_e_tmp_0;

  /* Product: '<S115>/Product9' incorporates:
   *  Product: '<S112>/Divide'
   *  Product: '<S114>/Product3'
   */
  rtb_Add_j0_tmp_0 = tmp_2 * rtb_Gain_e_tmp_1;

  /* Sum: '<S115>/Sum' incorporates:
   *  DiscreteIntegrator: '<S98>/Discrete-Time Integrator'
   *  Gain: '<S115>/Gain1'
   *  Gain: '<S115>/Gain2'
   *  Gain: '<S115>/Gain3'
   *  Product: '<S115>/Product1'
   *  Product: '<S115>/Product3'
   *  Product: '<S115>/Product4'
   *  Product: '<S115>/Product5'
   *  Product: '<S115>/Product6'
   *  Product: '<S115>/Product7'
   *  Product: '<S115>/Product8'
   *  Product: '<S115>/Product9'
   *  Sum: '<S115>/Sum1'
   *  Sum: '<S115>/Sum2'
   *  Sum: '<S115>/Sum3'
   */
  rtb_Add_p = ((rtb_Sum_i_idx_2 + rtb_Add_j0_tmp) * 2.0F *
               Plant_DW.DiscreteTimeIntegrator_DSTATE_b[0] + (rtb_Add_j0_tmp_0 -
    rtb_Sum1_dw_idx_2) * 2.0F * Plant_DW.DiscreteTimeIntegrator_DSTATE_b[1]) +
    (rtb_MathFunction1_k - rtb_Sum1_dw_idx_0) * 2.0F *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_b[2];

  /* Product: '<S113>/Product7' incorporates:
   *  Product: '<S112>/Divide'
   *  Product: '<S114>/Product9'
   */
  rtb_Gain_e_tmp = rtb_Gain_e_tmp_1 * rtb_Gain_e_tmp_1;

  /* Product: '<S113>/Product' incorporates:
   *  Product: '<S112>/Divide'
   *  Product: '<S114>/Product6'
   */
  rtb_Gain_e_tmp_0 *= tmp_2;

  /* Product: '<S113>/Product1' incorporates:
   *  Product: '<S112>/Divide'
   *  Product: '<S114>/Product7'
   */
  rtb_Gain_e_tmp_1 *= rtb_Gain_kz;

  /* Sum: '<S113>/Sum' incorporates:
   *  Constant: '<S113>/Constant'
   *  DiscreteIntegrator: '<S98>/Discrete-Time Integrator'
   *  Gain: '<S113>/Gain'
   *  Gain: '<S113>/Gain2'
   *  Gain: '<S113>/Gain3'
   *  Product: '<S113>/Product'
   *  Product: '<S113>/Product1'
   *  Product: '<S113>/Product4'
   *  Product: '<S113>/Product5'
   *  Product: '<S113>/Product7'
   *  Product: '<S113>/Product8'
   *  Sum: '<S113>/Sum1'
   *  Sum: '<S113>/Sum2'
   *  Sum: '<S113>/Sum3'
   */
  rtb_Gain_kz = (((0.5F - rtb_Sum1_dw_idx_0) - rtb_Gain_e_tmp) * 2.0F *
                 Plant_DW.DiscreteTimeIntegrator_DSTATE_b[0] + (rtb_Gain_e_tmp_0
    + rtb_Gain_e_tmp_1) * 2.0F * Plant_DW.DiscreteTimeIntegrator_DSTATE_b[1]) +
    (rtb_Sum_i_idx_2 - rtb_Add_j0_tmp) * 2.0F *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_b[2];

  /* Product: '<S110>/Multiply1' incorporates:
   *  DiscreteIntegrator: '<S97>/Discrete-Time Integrator'
   */
  rtb_Add_i[1] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[2] * rtb_Gain_kz;

  /* Product: '<S111>/Multiply5' incorporates:
   *  DiscreteIntegrator: '<S97>/Discrete-Time Integrator'
   */
  rtb_Sum_i_idx_2 = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[1] * rtb_Gain_kz;

  /* Sum: '<S114>/Sum' incorporates:
   *  DiscreteIntegrator: '<S98>/Discrete-Time Integrator'
   *  Gain: '<S114>/Gain1'
   *  Gain: '<S114>/Gain2'
   *  Gain: '<S114>/Gain3'
   *  Product: '<S114>/Product4'
   *  Product: '<S114>/Product5'
   *  Product: '<S114>/Product8'
   *  Sum: '<S114>/Sum1'
   *  Sum: '<S114>/Sum2'
   *  Sum: '<S114>/Sum3'
   */
  rtb_Gain_kz = ((rtb_MathFunction1_k - rtb_Gain_e_tmp) * 2.0F *
                 Plant_DW.DiscreteTimeIntegrator_DSTATE_b[1] + (rtb_Gain_e_tmp_0
    - rtb_Gain_e_tmp_1) * 2.0F * Plant_DW.DiscreteTimeIntegrator_DSTATE_b[0]) +
    (rtb_Sum1_dw_idx_2 + rtb_Add_j0_tmp_0) * 2.0F *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_b[2];

  /* DiscreteIntegrator: '<S98>/Discrete-Time Integrator' */
  rtb_Sum1_dw_idx_0 = Plant_DW.DiscreteTimeIntegrator_DSTATE_b[0];

  /* Sum: '<S97>/Sum' incorporates:
   *  Sum: '<S99>/Sum'
   */
  rtb_Sum_jq[0] = rtb_MathFunction_m[0] - (rtb_Sum_fw[0] - rtb_Sum_jq[0]);

  /* Sum: '<S98>/Sum' incorporates:
   *  Constant: '<S98>/mass'
   *  DiscreteIntegrator: '<S97>/Discrete-Time Integrator'
   *  Product: '<S110>/Multiply'
   *  Product: '<S111>/Multiply3'
   *  Product: '<S98>/Divide'
   *  Sum: '<S107>/Sum'
   */
  rtb_Multiply4_idx_0 = rtb_Multiply4_idx_0 / 3.0F -
    (Plant_DW.DiscreteTimeIntegrator_DSTATE_i[1] * rtb_Add_p -
     Plant_DW.DiscreteTimeIntegrator_DSTATE_i[2] * rtb_Gain_kz);

  /* DiscreteIntegrator: '<S98>/Discrete-Time Integrator' */
  rtb_MathFunction1_k = Plant_DW.DiscreteTimeIntegrator_DSTATE_b[1];

  /* Sum: '<S97>/Sum' incorporates:
   *  Sum: '<S99>/Sum'
   */
  rtb_Sum_jq[1] = rtb_MathFunction_m[1] - (rtb_Sum_fw[1] - rtb_Sum_jq[1]);

  /* Sum: '<S98>/Sum' incorporates:
   *  Constant: '<S98>/mass'
   *  DiscreteIntegrator: '<S97>/Discrete-Time Integrator'
   *  Product: '<S111>/Multiply4'
   *  Product: '<S98>/Divide'
   *  Sum: '<S107>/Sum'
   */
  rtb_Add_p = rtb_Multiply4_idx_1 / 3.0F - (rtb_Add_i[1] -
    Plant_DW.DiscreteTimeIntegrator_DSTATE_i[0] * rtb_Add_p);

  /* DiscreteIntegrator: '<S98>/Discrete-Time Integrator' */
  rtb_Sum1_dw_idx_2 = Plant_DW.DiscreteTimeIntegrator_DSTATE_b[2];

  /* Sum: '<S98>/Sum' incorporates:
   *  Constant: '<S98>/mass'
   *  DiscreteIntegrator: '<S97>/Discrete-Time Integrator'
   *  Product: '<S110>/Multiply2'
   *  Product: '<S98>/Divide'
   *  Sum: '<S107>/Sum'
   */
  rtb_Multiply4 = rtb_Multiply4 / 3.0F -
    (Plant_DW.DiscreteTimeIntegrator_DSTATE_i[0] * rtb_Gain_kz - rtb_Sum_i_idx_2);

  /* Sum: '<S97>/Sum' incorporates:
   *  Sum: '<S99>/Sum'
   */
  rtb_Sum_jq[2] = rtb_Square_l - (rtb_Sum_fw[2] - rtb_Sum_jq[2]);

  /* Product: '<S118>/Product7' incorporates:
   *  Product: '<S117>/Divide'
   *  Product: '<S119>/Product7'
   */
  rtb_Gain_e_tmp = rtb_Divide_k_idx_3 * rtb_Divide_k_idx_3;

  /* Product: '<S118>/Product' incorporates:
   *  Product: '<S117>/Divide'
   *  Product: '<S119>/Product'
   */
  rtb_Sum_i_idx_2 = rtb_Sum_c4 * rtb_Divide_k_idx_2;

  /* Product: '<S118>/Product1' incorporates:
   *  Product: '<S117>/Divide'
   *  Product: '<S119>/Product1'
   */
  rtb_Add_j0_tmp = rtb_Divide_k_idx_0 * rtb_Divide_k_idx_3;

  /* Product: '<S118>/Product2' incorporates:
   *  Product: '<S117>/Divide'
   *  Product: '<S120>/Product9'
   */
  rtb_Gain_kz = rtb_Sum_c4 * rtb_Divide_k_idx_3;

  /* Product: '<S118>/Product3' incorporates:
   *  Product: '<S117>/Divide'
   *  Product: '<S120>/Product1'
   */
  rtb_Square_l = rtb_Divide_k_idx_0 * rtb_Divide_k_idx_2;

  /* Product: '<S118>/Product6' incorporates:
   *  Product: '<S117>/Divide'
   *  Product: '<S120>/Product7'
   */
  rtb_Add_j0_tmp_0 = rtb_Divide_k_idx_2 * rtb_Divide_k_idx_2;

  /* Sum: '<S118>/Sum' incorporates:
   *  Constant: '<S118>/Constant'
   *  Gain: '<S118>/Gain'
   *  Gain: '<S118>/Gain1'
   *  Gain: '<S118>/Gain2'
   *  Product: '<S118>/Product'
   *  Product: '<S118>/Product1'
   *  Product: '<S118>/Product2'
   *  Product: '<S118>/Product3'
   *  Product: '<S118>/Product4'
   *  Product: '<S118>/Product5'
   *  Product: '<S118>/Product6'
   *  Product: '<S118>/Product7'
   *  Product: '<S118>/Product8'
   *  Sum: '<S118>/Sum1'
   *  Sum: '<S118>/Sum2'
   *  Sum: '<S118>/Sum3'
   */
  rtb_Multiply4_idx_1 = (((0.5F - rtb_Add_j0_tmp_0) - rtb_Gain_e_tmp) * 2.0F *
    rtb_Multiply4_idx_0 + (rtb_Sum_i_idx_2 - rtb_Add_j0_tmp) * 2.0F * rtb_Add_p)
    + (rtb_Gain_kz + rtb_Square_l) * 2.0F * rtb_Multiply4;

  /* Product: '<S119>/Product2' incorporates:
   *  Product: '<S117>/Divide'
   *  Product: '<S120>/Product2'
   */
  rtb_Divide_k_idx_0 *= rtb_Sum_c4;

  /* Product: '<S119>/Product3' incorporates:
   *  Product: '<S117>/Divide'
   *  Product: '<S120>/Product3'
   */
  rtb_Divide_k_idx_2 *= rtb_Divide_k_idx_3;

  /* Sum: '<S119>/Sum3' incorporates:
   *  Constant: '<S119>/Constant'
   *  Product: '<S117>/Divide'
   *  Product: '<S119>/Product6'
   *  Sum: '<S120>/Sum3'
   */
  rtb_Divide_k_idx_3 = 0.5F - rtb_Sum_c4 * rtb_Sum_c4;

  /* Sum: '<S119>/Sum' incorporates:
   *  Gain: '<S119>/Gain'
   *  Gain: '<S119>/Gain1'
   *  Gain: '<S119>/Gain2'
   *  Product: '<S119>/Product2'
   *  Product: '<S119>/Product3'
   *  Product: '<S119>/Product4'
   *  Product: '<S119>/Product5'
   *  Product: '<S119>/Product8'
   *  Sum: '<S119>/Sum1'
   *  Sum: '<S119>/Sum2'
   *  Sum: '<S119>/Sum3'
   */
  rtb_Sum_c4 = ((rtb_Divide_k_idx_3 - rtb_Gain_e_tmp) * 2.0F * rtb_Add_p +
                (rtb_Sum_i_idx_2 + rtb_Add_j0_tmp) * 2.0F * rtb_Multiply4_idx_0)
    + (rtb_Divide_k_idx_2 - rtb_Divide_k_idx_0) * 2.0F * rtb_Multiply4;

  /* Sum: '<S120>/Sum' incorporates:
   *  Gain: '<S120>/Gain1'
   *  Gain: '<S120>/Gain2'
   *  Gain: '<S120>/Gain3'
   *  Product: '<S120>/Product4'
   *  Product: '<S120>/Product5'
   *  Product: '<S120>/Product8'
   *  Sum: '<S120>/Sum1'
   *  Sum: '<S120>/Sum2'
   *  Sum: '<S120>/Sum3'
   */
  rtb_Multiply4_idx_0 = ((rtb_Gain_kz - rtb_Square_l) * 2.0F *
    rtb_Multiply4_idx_0 + (rtb_Divide_k_idx_0 + rtb_Divide_k_idx_2) * 2.0F *
    rtb_Add_p) + (rtb_Divide_k_idx_3 - rtb_Add_j0_tmp_0) * 2.0F * rtb_Multiply4;

  /* Math: '<S100>/Square1' incorporates:
   *  Product: '<S104>/Divide'
   */
  rtb_Add_p = rtb_Plant_States_vel_z_O * rtb_Plant_States_vel_z_O;

  /* Product: '<S100>/Multiply6' incorporates:
   *  Constant: '<S100>/Constant'
   *  Product: '<S100>/Multiply4'
   *  Product: '<S100>/Multiply5'
   *  Product: '<S104>/Divide'
   *  Sum: '<S100>/Subtract'
   */
  rtb_Multiply4 = (rtb_Plant_States_vel_x_O * rtb_Plant_States_vel_z_O -
                   rtb_MathFunction_k * rtb_Plant_States_vel_y_O) * 2.0F;

  /* DiscreteIntegrator: '<S98>/Discrete-Time Integrator1' */
  if (Plant_DW.DiscreteTimeIntegrator1_PrevRes != 0) {
    Plant_DW.DiscreteTimeIntegrator1_DSTATE[0] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator1_DSTATE[1] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator1_DSTATE[2] = 0.0F;
  }

  rtb_Sum1_a[0] = Plant_DW.DiscreteTimeIntegrator1_DSTATE[0];
  rtb_Sum1_a[1] = Plant_DW.DiscreteTimeIntegrator1_DSTATE[1];
  rtb_Sum1_a[2] = Plant_DW.DiscreteTimeIntegrator1_DSTATE[2];

  /* End of DiscreteIntegrator: '<S98>/Discrete-Time Integrator1' */

  /* Product: '<S101>/Multiply' incorporates:
   *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator'
   */
  for (i = 0; i < 4; i++) {
    rtb_Divide_k_idx_2 = rtb_MatrixConcatenate4[i + 12] *
      Plant_DW.DiscreteTimeIntegrator_DSTATE_k[3] + (rtb_MatrixConcatenate4[i +
      8] * Plant_DW.DiscreteTimeIntegrator_DSTATE_k[2] +
      (rtb_MatrixConcatenate4[i + 4] * Plant_DW.DiscreteTimeIntegrator_DSTATE_k
       [1] + rtb_MatrixConcatenate4[i] *
       Plant_DW.DiscreteTimeIntegrator_DSTATE_k[0]));
    rtb_MatrixConcatenate4_0[i] = rtb_Divide_k_idx_2;
  }

  /* End of Product: '<S101>/Multiply' */

  /* Update for DiscreteIntegrator: '<S101>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S101>/Gain'
   */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_k[0] += 0.5F *
    rtb_MatrixConcatenate4_0[0] * 0.002F;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_k[1] += 0.5F *
    rtb_MatrixConcatenate4_0[1] * 0.002F;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_k[2] += 0.5F *
    rtb_MatrixConcatenate4_0[2] * 0.002F;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_k[3] += 0.5F *
    rtb_MatrixConcatenate4_0[3] * 0.002F;
  Plant_DW.DiscreteTimeIntegrator_PrevRese = 0;

  /* Product: '<S97>/Divide' incorporates:
   *  Constant: '<S97>/Inertia_Matrix'
   */
  rt_mldivide_U1f3x3_U2f3_Yf3x1(Plant_ConstP.pooled32, rtb_Sum_jq, rtb_Square_b);

  /* Update for DiscreteIntegrator: '<S97>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_PrevRe_p = 0;

  /* Update for DiscreteIntegrator: '<S98>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_PrevRe_g = (int8_T)rtb_FixPtRelationalOperator;

  /* Update for DiscreteIntegrator: '<S97>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_i[0] += 0.002F * rtb_Square_b[0];

  /* Update for DiscreteIntegrator: '<S98>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_b[0] += 0.002F * rtb_Multiply4_idx_1;

  /* Update for DiscreteIntegrator: '<S98>/Discrete-Time Integrator1' */
  Plant_DW.DiscreteTimeIntegrator1_DSTATE[0] += 0.002F * rtb_Sum1_dw_idx_0;

  /* Update for DiscreteIntegrator: '<S97>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_i[1] += 0.002F * rtb_Square_b[1];

  /* Update for DiscreteIntegrator: '<S98>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_b[1] += 0.002F * rtb_Sum_c4;

  /* Update for DiscreteIntegrator: '<S98>/Discrete-Time Integrator1' */
  Plant_DW.DiscreteTimeIntegrator1_DSTATE[1] += 0.002F * rtb_MathFunction1_k;

  /* Update for DiscreteIntegrator: '<S97>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_i[2] += 0.002F * rtb_Square_b[2];

  /* Update for DiscreteIntegrator: '<S98>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_b[2] += 0.002F * rtb_Multiply4_idx_0;

  /* Update for DiscreteIntegrator: '<S98>/Discrete-Time Integrator1' */
  Plant_DW.DiscreteTimeIntegrator1_DSTATE[2] += 0.002F * rtb_Sum1_dw_idx_2;
  Plant_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* End of Outputs for SubSystem: '<Root>/Kinematic_Equation' */

  /* Outputs for Atomic SubSystem: '<Root>/Bus_Constructor' */
  /* Sqrt: '<S50>/Sqrt' incorporates:
   *  Math: '<S50>/Square'
   *  Sum: '<S50>/Sum of Elements'
   */
  rtb_Gain_kz = sqrtf(((rtb_Switch_idx_0 * rtb_Switch_idx_0 + rtb_Switch_idx_1 *
                        rtb_Switch_idx_1) + rtb_Switch_idx_2 * rtb_Switch_idx_2)
                      + rtb_Switch_idx_3 * rtb_Switch_idx_3);

  /* Product: '<S46>/Divide' */
  rtb_Divide_g[0] = rtb_Switch_idx_0 / rtb_Gain_kz;
  rtb_Divide_g[1] = rtb_Switch_idx_1 / rtb_Gain_kz;
  rtb_Divide_g[2] = rtb_Switch_idx_2 / rtb_Gain_kz;
  rtb_Divide_g[3] = rtb_Switch_idx_3 / rtb_Gain_kz;

  /* Math: '<S47>/Square' incorporates:
   *  Math: '<S48>/Square'
   *  Math: '<S49>/Square'
   */
  rtb_Divide_k_idx_2 = rtb_Divide_g[0] * rtb_Divide_g[0];

  /* Math: '<S47>/Square2' incorporates:
   *  Math: '<S48>/Square2'
   *  Math: '<S49>/Square2'
   */
  rtb_Divide_k_idx_3 = rtb_Divide_g[2] * rtb_Divide_g[2];

  /* Math: '<S47>/Square1' incorporates:
   *  Math: '<S48>/Square1'
   *  Math: '<S49>/Square1'
   */
  rtb_Divide_k_idx_0 = rtb_Divide_g[1] * rtb_Divide_g[1];

  /* Math: '<S47>/Square3' incorporates:
   *  Math: '<S48>/Square3'
   *  Math: '<S49>/Square3'
   */
  rtb_Gain_kz = rtb_Divide_g[3] * rtb_Divide_g[3];

  /* Sum: '<S47>/Subtract' incorporates:
   *  Math: '<S47>/Square'
   *  Math: '<S47>/Square1'
   *  Math: '<S47>/Square2'
   *  Math: '<S47>/Square3'
   *  Sum: '<S47>/Add'
   *  Sum: '<S47>/Add1'
   */
  rtb_MatrixConcatenate1[0] = (rtb_Divide_k_idx_2 + rtb_Divide_k_idx_0) -
    (rtb_Divide_k_idx_3 + rtb_Gain_kz);

  /* Product: '<S47>/Multiply' incorporates:
   *  Product: '<S48>/Multiply'
   */
  rtb_Square_l = rtb_Divide_g[1] * rtb_Divide_g[2];

  /* Product: '<S47>/Multiply1' incorporates:
   *  Product: '<S48>/Multiply1'
   */
  rtb_Add_j0_tmp_0 = rtb_Divide_g[0] * rtb_Divide_g[3];

  /* Gain: '<S47>/Gain' incorporates:
   *  Product: '<S47>/Multiply'
   *  Product: '<S47>/Multiply1'
   *  Sum: '<S47>/Subtract1'
   */
  rtb_MatrixConcatenate1[1] = (rtb_Square_l - rtb_Add_j0_tmp_0) * 2.0F;

  /* Product: '<S47>/Multiply2' incorporates:
   *  Product: '<S49>/Multiply'
   */
  rtb_Gain_e_tmp = rtb_Divide_g[1] * rtb_Divide_g[3];

  /* Product: '<S47>/Multiply3' incorporates:
   *  Product: '<S49>/Multiply1'
   */
  rtb_Sum_i_idx_2 = rtb_Divide_g[0] * rtb_Divide_g[2];

  /* Gain: '<S47>/Gain1' incorporates:
   *  Product: '<S47>/Multiply2'
   *  Product: '<S47>/Multiply3'
   *  Sum: '<S47>/Add2'
   */
  rtb_MatrixConcatenate1[2] = (rtb_Gain_e_tmp + rtb_Sum_i_idx_2) * 2.0F;

  /* Gain: '<S48>/Gain' incorporates:
   *  Sum: '<S48>/Add3'
   */
  rtb_MatrixConcatenate1[3] = (rtb_Square_l + rtb_Add_j0_tmp_0) * 2.0F;

  /* Sum: '<S48>/Subtract' incorporates:
   *  Sum: '<S48>/Add'
   *  Sum: '<S48>/Add1'
   */
  rtb_MatrixConcatenate1[4] = (rtb_Divide_k_idx_2 + rtb_Divide_k_idx_3) -
    (rtb_Divide_k_idx_0 + rtb_Gain_kz);

  /* Product: '<S48>/Multiply2' incorporates:
   *  Product: '<S49>/Multiply2'
   */
  rtb_Square_l = rtb_Divide_g[2] * rtb_Divide_g[3];

  /* Product: '<S48>/Multiply3' incorporates:
   *  Product: '<S49>/Multiply3'
   */
  rtb_Add_j0_tmp_0 = rtb_Divide_g[0] * rtb_Divide_g[1];

  /* Gain: '<S48>/Gain1' incorporates:
   *  Product: '<S48>/Multiply2'
   *  Product: '<S48>/Multiply3'
   *  Sum: '<S48>/Subtract1'
   */
  rtb_MatrixConcatenate1[5] = (rtb_Square_l - rtb_Add_j0_tmp_0) * 2.0F;

  /* Gain: '<S49>/Gain' incorporates:
   *  Sum: '<S49>/Subtract2'
   */
  rtb_MatrixConcatenate1[6] = (rtb_Gain_e_tmp - rtb_Sum_i_idx_2) * 2.0F;

  /* Gain: '<S49>/Gain1' incorporates:
   *  Sum: '<S49>/Add2'
   */
  rtb_MatrixConcatenate1[7] = (rtb_Square_l + rtb_Add_j0_tmp_0) * 2.0F;

  /* Sum: '<S49>/Subtract' incorporates:
   *  Sum: '<S49>/Add'
   *  Sum: '<S49>/Add1'
   */
  rtb_MatrixConcatenate1[8] = (rtb_Divide_k_idx_2 + rtb_Gain_kz) -
    (rtb_Divide_k_idx_0 + rtb_Divide_k_idx_3);

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

  Plant_Y.Extended_States.quat[0] = rtb_Switch_idx_0;
  Plant_Y.Extended_States.quat[1] = rtb_Switch_idx_1;
  Plant_Y.Extended_States.quat[2] = rtb_Switch_idx_2;
  Plant_Y.Extended_States.quat[3] = rtb_Switch_idx_3;
  Plant_Y.Extended_States.Va = rtb_Va_B[0];

  /* End of BusAssignment: '<S2>/Bus Assignment2' */

  /* BusAssignment: '<S2>/Bus Assignment1' incorporates:
   *  BusAssignment: '<S2>/Bus Assignment'
   *  Constant: '<S2>/Constant'
   *  Delay: '<Root>/Delay'
   */
  Plant_Y.Plant_States = Plant_rtZPlant_States_Bus;

  /* Outputs for Atomic SubSystem: '<Root>/Kinematic_Equation' */
  /* BusAssignment: '<S2>/Bus Assignment' incorporates:
   *  BusAssignment: '<S2>/Bus Assignment1'
   *  Constant: '<S100>/Constant'
   *  Constant: '<S100>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Math: '<S100>/Square'
   *  Product: '<S100>/Multiply'
   *  Product: '<S100>/Multiply1'
   *  Product: '<S100>/Multiply2'
   *  Product: '<S100>/Multiply3'
   *  Product: '<S104>/Divide'
   *  Sum: '<S100>/Add'
   *  Sum: '<S100>/Add1'
   *  Sum: '<S100>/Subtract2'
   *  Trigonometry: '<S100>/Atan2'
   */
  Plant_Y.Plant_States.phi = atan2f((rtb_Plant_States_vel_x_O *
    rtb_Plant_States_vel_y_O + rtb_Plant_States_vel_z_O * rtb_MathFunction_k) *
    2.0F, 1.0F - (rtb_Plant_States_vel_y_O * rtb_Plant_States_vel_y_O +
                  rtb_Add_p) * 2.0F);

  /* End of Outputs for SubSystem: '<Root>/Bus_Constructor' */

  /* Saturate: '<S100>/Saturation' */
  if (rtb_Multiply4 > 1.0F) {
    rtb_Multiply4 = 1.0F;
  } else {
    if (rtb_Multiply4 < -1.0F) {
      rtb_Multiply4 = -1.0F;
    }
  }

  /* End of Saturate: '<S100>/Saturation' */

  /* Outputs for Atomic SubSystem: '<Root>/Bus_Constructor' */
  /* BusAssignment: '<S2>/Bus Assignment' incorporates:
   *  BusAssignment: '<S2>/Bus Assignment1'
   *  Constant: '<S100>/Constant'
   *  Constant: '<S100>/Constant1'
   *  Delay: '<Root>/Delay'
   *  Math: '<S100>/Square2'
   *  Product: '<S100>/Multiply10'
   *  Product: '<S100>/Multiply7'
   *  Product: '<S100>/Multiply8'
   *  Product: '<S100>/Multiply9'
   *  Product: '<S104>/Divide'
   *  Sum: '<S100>/Add2'
   *  Sum: '<S100>/Add3'
   *  Sum: '<S100>/Subtract1'
   *  Trigonometry: '<S100>/Asin'
   *  Trigonometry: '<S100>/Atan1'
   */
  Plant_Y.Plant_States.theta = asinf(rtb_Multiply4);
  Plant_Y.Plant_States.psi = atan2f((rtb_Plant_States_vel_x_O *
    rtb_MathFunction_k + rtb_Plant_States_vel_y_O * rtb_Plant_States_vel_z_O) *
    2.0F, 1.0F - (rtb_MathFunction_k * rtb_MathFunction_k + rtb_Add_p) * 2.0F);

  /* End of Outputs for SubSystem: '<Root>/Kinematic_Equation' */
  Plant_Y.Plant_States.rot_x_B = rtb_Square_o5[0];
  Plant_Y.Plant_States.rot_y_B = rtb_Square_o5[1];
  Plant_Y.Plant_States.rot_z_B = rtb_Square_o5[2];
  Plant_Y.Plant_States.acc_x_O = rtb_Multiply4_idx_1;
  Plant_Y.Plant_States.acc_y_O = rtb_Sum_c4;
  Plant_Y.Plant_States.acc_z_O = rtb_Multiply4_idx_0;
  Plant_Y.Plant_States.vel_x_O = rtb_Sum1_dw_idx_0;
  Plant_Y.Plant_States.vel_y_O = rtb_MathFunction1_k;
  Plant_Y.Plant_States.vel_z_O = rtb_Sum1_dw_idx_2;

  /* Trigonometry: '<S51>/Trigonometric Function1' incorporates:
   *  Delay: '<S45>/Delay1'
   *  Trigonometry: '<S51>/Trigonometric Function2'
   */
  rtb_TrigonometricFunction2 = cos(Plant_DW.Delay1_DSTATE[0]);

  /* Trigonometry: '<S51>/Trigonometric Function' incorporates:
   *  Delay: '<S45>/Delay1'
   */
  rtb_SumofElements = sin(Plant_DW.Delay1_DSTATE[0]);

  /* Sum: '<S51>/Subtract' incorporates:
   *  Constant: '<S51>/c'
   *  Math: '<S51>/u^2'
   *  Product: '<S51>/Product'
   */
  rtb_SumofElements = 1.0 - rtb_SumofElements * rtb_SumofElements *
    Plant_ConstB.Product1;

  /* Math: '<S51>/sqrt'
   *
   * About '<S51>/sqrt':
   *  Operator: sqrt
   */
  if (rtb_SumofElements < 0.0) {
    rtb_SumofElements = -sqrt(fabs(rtb_SumofElements));
  } else {
    rtb_SumofElements = sqrt(rtb_SumofElements);
  }

  /* End of Math: '<S51>/sqrt' */

  /* Product: '<S51>/Divide' incorporates:
   *  Constant: '<S51>/earth_radius'
   */
  rtb_SumofElements = 6.378137E+6 / rtb_SumofElements;

  /* Product: '<S51>/Product3' incorporates:
   *  Constant: '<S51>/constant2'
   *  Math: '<S51>/u^1'
   *  Product: '<S51>/Product2'
   *  Sum: '<S51>/Subtract2'
   *  Trigonometry: '<S51>/Trigonometric Function1'
   */
  rtb_SumofElements1 = (1.0 - rtb_TrigonometricFunction2 *
                        rtb_TrigonometricFunction2 * Plant_ConstB.Product1) *
    rtb_SumofElements;

  /* Sum: '<S51>/Add' incorporates:
   *  Delay: '<S45>/Delay1'
   */
  rtb_SumofElements1 += Plant_DW.Delay1_DSTATE[2];

  /* Sum: '<S51>/Add1' incorporates:
   *  Delay: '<S45>/Delay1'
   */
  rtb_SumofElements += Plant_DW.Delay1_DSTATE[2];

  /* Product: '<S51>/Product4' */
  rtb_SumofElements *= rtb_TrigonometricFunction2;

  /* BusAssignment: '<S2>/Bus Assignment1' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S2>/Gain'
   */
  Plant_Y.Plant_States.x_R = rtb_Sum1_a[0];
  Plant_Y.Plant_States.y_R = rtb_Sum1_a[1];
  Plant_Y.Plant_States.h_R = -rtb_Sum1_a[2];

  /* Signum: '<S52>/Sign' */
  if (rtb_SumofElements1 < 0.0) {
    rtb_Cl_xA = -1.0;
    rtb_TrigonometricFunction2 = -1.0;
  } else if (rtb_SumofElements1 > 0.0) {
    rtb_Cl_xA = 1.0;
    rtb_TrigonometricFunction2 = 1.0;
  } else {
    rtb_Cl_xA = rtb_SumofElements1;
    rtb_TrigonometricFunction2 = rtb_SumofElements1;
  }

  /* Switch: '<S52>/Switch' incorporates:
   *  Constant: '<S52>/Constant'
   */
  if (rtb_TrigonometricFunction2 == 0.0) {
    rtb_Cl_xA = 1.0;
  }

  /* Abs: '<S52>/Abs' */
  rtb_SumofElements1 = fabs(rtb_SumofElements1);

  /* Saturate: '<S52>/Saturation' */
  if (rtb_SumofElements1 > 1.0E+8) {
    rtb_SumofElements1 = 1.0E+8;
  } else {
    if (rtb_SumofElements1 < 1.0E-6) {
      rtb_SumofElements1 = 1.0E-6;
    }
  }

  /* Sum: '<S45>/Add' incorporates:
   *  Abs: '<S52>/Abs'
   *  DataTypeConversion: '<S45>/Data Type Conversion'
   *  Delay: '<S45>/Delay'
   *  Delay: '<S45>/Delay1'
   *  Product: '<S45>/Divide'
   *  Product: '<S52>/Product'
   *  Sum: '<S45>/Subtract'
   */
  Plant_DW.Delay1_DSTATE[0] += 1.0 / (rtb_SumofElements1 * rtb_Cl_xA) *
    (rtb_Sum1_a[0] - Plant_DW.Delay_DSTATE_f[0]);

  /* Update for Delay: '<S45>/Delay' incorporates:
   *  DataTypeConversion: '<S45>/Data Type Conversion'
   */
  Plant_DW.Delay_DSTATE_f[0] = rtb_Sum1_a[0];

  /* Signum: '<S52>/Sign' */
  if (rtb_SumofElements < 0.0) {
    rtb_Cl_xA = -1.0;
    rtb_SumofElements1 = -1.0;
  } else if (rtb_SumofElements > 0.0) {
    rtb_Cl_xA = 1.0;
    rtb_SumofElements1 = 1.0;
  } else {
    rtb_Cl_xA = rtb_SumofElements;
    rtb_SumofElements1 = rtb_SumofElements;
  }

  /* Switch: '<S52>/Switch' incorporates:
   *  Constant: '<S52>/Constant'
   */
  if (rtb_SumofElements1 == 0.0) {
    rtb_Cl_xA = 1.0;
  }

  /* Abs: '<S52>/Abs' */
  rtb_SumofElements1 = fabs(rtb_SumofElements);

  /* Saturate: '<S52>/Saturation' */
  if (rtb_SumofElements1 > 1.0E+8) {
    rtb_SumofElements1 = 1.0E+8;
  } else {
    if (rtb_SumofElements1 < 1.0E-6) {
      rtb_SumofElements1 = 1.0E-6;
    }
  }

  /* Sum: '<S45>/Add' incorporates:
   *  Abs: '<S52>/Abs'
   *  DataTypeConversion: '<S45>/Data Type Conversion'
   *  Delay: '<S45>/Delay'
   *  Delay: '<S45>/Delay1'
   *  Product: '<S45>/Divide'
   *  Product: '<S52>/Product'
   *  Sum: '<S45>/Subtract'
   */
  Plant_DW.Delay1_DSTATE[1] += 1.0 / (rtb_SumofElements1 * rtb_Cl_xA) *
    (rtb_Sum1_a[1] - Plant_DW.Delay_DSTATE_f[1]);

  /* Update for Delay: '<S45>/Delay' incorporates:
   *  DataTypeConversion: '<S45>/Data Type Conversion'
   */
  Plant_DW.Delay_DSTATE_f[1] = rtb_Sum1_a[1];

  /* Sum: '<S45>/Add' incorporates:
   *  Abs: '<S52>/Abs'
   *  DataTypeConversion: '<S45>/Data Type Conversion'
   *  Delay: '<S45>/Delay'
   *  Delay: '<S45>/Delay1'
   *  Product: '<S45>/Divide'
   *  Sum: '<S45>/Subtract'
   */
  Plant_DW.Delay1_DSTATE[2] += -(rtb_Sum1_a[2] - Plant_DW.Delay_DSTATE_f[2]);

  /* Update for Delay: '<S45>/Delay' incorporates:
   *  DataTypeConversion: '<S45>/Data Type Conversion'
   */
  Plant_DW.Delay_DSTATE_f[2] = rtb_Sum1_a[2];

  /* BusAssignment: '<S2>/Bus Assignment1' incorporates:
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant2'
   *  Constant: '<S2>/Constant3'
   *  Delay: '<Root>/Delay'
   *  Delay: '<S43>/Delay'
   *  Delay: '<S45>/Delay1'
   */
  Plant_Y.Plant_States.lat = Plant_DW.Delay1_DSTATE[0];
  Plant_Y.Plant_States.lon = Plant_DW.Delay1_DSTATE[1];
  Plant_Y.Plant_States.alt = Plant_DW.Delay1_DSTATE[2];
  Plant_Y.Plant_States.lat_0 = 0.65673;
  Plant_Y.Plant_States.lon_0 = -2.1361;
  Plant_Y.Plant_States.alt_0 = 4.5;
  Plant_Y.Plant_States.timestamp = Plant_DW.Delay_DSTATE_h;

  /* Sum: '<S43>/Sum' incorporates:
   *  Constant: '<S43>/dt'
   *  Delay: '<S43>/Delay'
   */
  Plant_DW.Delay_DSTATE_h += PLANT_EXPORT.period;

  /* End of Outputs for SubSystem: '<Root>/Bus_Constructor' */

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_Model' */
  /* Outputs for Atomic SubSystem: '<S7>/Sensor_Airspeed' */
  /* BusAssignment: '<S129>/Bus Assignment' incorporates:
   *  Constant: '<S129>/Constant'
   *  Delay: '<Root>/Delay'
   *  Gain: '<S128>/Gain'
   *  Math: '<S128>/Square'
   *  Memory: '<S122>/Memory1'
   */
  rtb_BusAssignment_f = Plant_rtZAirSpeed_Bus;
  rtb_BusAssignment_f.timestamp = Plant_DW.Memory1_PreviousInput;
  rtb_BusAssignment_f.diff_pressure = Plant_Y.Extended_States.Va *
    Plant_Y.Extended_States.Va * 0.6125F;

  /* RateTransition: '<S129>/Rate Transition' */
  if (Plant_M->Timing.TaskCounters.TID[1] == 0) {
    Plant_B.RateTransition_e = rtb_BusAssignment_f;
  }

  /* End of RateTransition: '<S129>/Rate Transition' */
  /* End of Outputs for SubSystem: '<S7>/Sensor_Airspeed' */

  /* Outputs for Atomic SubSystem: '<S7>/Sensor_Barometer' */
  /* Saturate: '<S134>/Limit  altitude  to troposhere' incorporates:
   *  DataTypeConversion: '<S132>/Data Type Conversion'
   *  Delay: '<Root>/Delay'
   */
  if ((real32_T)Plant_Y.Plant_States.alt > 11000.0F) {
    rtb_Gain_kz = 11000.0F;
  } else if ((real32_T)Plant_Y.Plant_States.alt < 0.0F) {
    rtb_Gain_kz = 0.0F;
  } else {
    rtb_Gain_kz = (real32_T)Plant_Y.Plant_States.alt;
  }

  /* End of Saturate: '<S134>/Limit  altitude  to troposhere' */

  /* Sum: '<S134>/Sum1' incorporates:
   *  Constant: '<S134>/Sea Level  Temperature'
   *  Gain: '<S134>/Lapse Rate'
   */
  rtb_Sum1_dw_idx_0 = 288.15F - 0.0065F * rtb_Gain_kz;

  /* Sum: '<S134>/Sum' incorporates:
   *  Constant: '<S134>/Altitude of Troposphere'
   *  DataTypeConversion: '<S132>/Data Type Conversion'
   *  Delay: '<Root>/Delay'
   */
  rtb_MathFunction1_k = 11000.0F - (real32_T)Plant_Y.Plant_States.alt;

  /* Saturate: '<S134>/Limit  altitude  to Stratosphere' incorporates:
   *  Constant: '<S134>/Altitude of Troposphere'
   *  DataTypeConversion: '<S132>/Data Type Conversion'
   *  Delay: '<Root>/Delay'
   *  Sum: '<S134>/Sum'
   */
  if (11000.0F - (real32_T)Plant_Y.Plant_States.alt > 0.0F) {
    rtb_MathFunction1_k = 0.0F;
  } else {
    if (11000.0F - (real32_T)Plant_Y.Plant_States.alt < -9000.0F) {
      rtb_MathFunction1_k = -9000.0F;
    }
  }

  /* End of Saturate: '<S134>/Limit  altitude  to Stratosphere' */

  /* Product: '<S134>/Product2' incorporates:
   *  Constant: '<S134>/Constant'
   *  Gain: '<S134>/1//T0'
   *  Gain: '<S134>/P0'
   *  Gain: '<S134>/g//R'
   *  Math: '<S134>/(T//T0)^(g//LR) '
   *  Math: '<S134>/Stratosphere Model'
   *  Product: '<S134>/Product1'
   *
   * About '<S134>/Stratosphere Model':
   *  Operator: exp
   */
  rtb_Sum1_dw_idx_2 = powf(0.00347041478F * rtb_Sum1_dw_idx_0, 5.25587559F) *
    101325.0F * expf(1.0F / rtb_Sum1_dw_idx_0 * (0.0341631919F *
    rtb_MathFunction1_k));

  /* S-Function (sdsprandsrc2): '<S136>/Random Source' */
  RandSrc_GZ_R(&rtb_MathFunction1_k, &Plant_ConstP.pooled27, 1,
               &Plant_ConstP.pooled37, 1, Plant_DW.RandomSource_STATE_DWORK_fn,
               1, 1);

  /* BusAssignment: '<S131>/Bus Assignment' incorporates:
   *  Constant: '<S131>/Constant2'
   *  DataTypeConversion: '<S131>/Data Type Conversion1'
   *  Memory: '<S122>/Memory1'
   *  Saturate: '<S133>/Saturation'
   *  Sum: '<S131>/Sum1'
   *  Sum: '<S133>/Add'
   */
  rtb_BusAssignment_c.timestamp = Plant_DW.Memory1_PreviousInput;
  rtb_BusAssignment_c.pressure = rtb_Sum1_dw_idx_2 + rtb_MathFunction1_k;
  rtb_BusAssignment_c.temperature = (real32_T)(rtb_Sum1_dw_idx_0 - 273.15);

  /* RateTransition: '<S131>/Rate Transition' */
  if (Plant_M->Timing.TaskCounters.TID[2] == 0) {
    Plant_B.RateTransition_p = rtb_BusAssignment_c;
  }

  /* End of RateTransition: '<S131>/Rate Transition' */
  /* End of Outputs for SubSystem: '<S7>/Sensor_Barometer' */

  /* Outputs for Atomic SubSystem: '<S7>/Sensor_GPS' */
  /* Trigonometry: '<S149>/Sin' incorporates:
   *  Delay: '<S142>/Delay'
   */
  rtb_SumofElements = sin(Plant_DW.Delay_DSTATE[0]);

  /* Math: '<S149>/Square1' */
  rtb_SumofElements *= rtb_SumofElements;

  /* Product: '<S149>/Multiply1' incorporates:
   *  Product: '<S149>/Multiply'
   */
  rtb_Cl_xA = Plant_ConstB.ff * rtb_SumofElements;

  /* Product: '<S149>/Divide' incorporates:
   *  Constant: '<S149>/Constant'
   *  Constant: '<S149>/R'
   *  Sqrt: '<S149>/Sqrt'
   *  Sum: '<S149>/Sum1'
   */
  rtb_SumofElements = 6.378137E+6 / sqrt(1.0 - rtb_Cl_xA);

  /* Trigonometry: '<S149>/Cos' incorporates:
   *  Delay: '<S142>/Delay'
   */
  rtb_SumofElements1 = cos(Plant_DW.Delay_DSTATE[0]);

  /* S-Function (sdsprandsrc2): '<S145>/Random Source' */
  RandSrc_GZ_R(rtb_RandomSource, &Plant_ConstP.pooled27, 1,
               Plant_ConstP.RandomSource_VarianceRTP, 3,
               Plant_DW.RandomSource_STATE_DWORK_f2, 3, 1);

  /* Sum: '<S143>/Sum2' incorporates:
   *  Constant: '<S149>/Constant1'
   *  Delay: '<S142>/Delay'
   *  Product: '<S146>/Divide2'
   *  Product: '<S149>/Multiply1'
   *  Product: '<S149>/Multiply2'
   *  Product: '<S149>/Product3'
   *  Sum: '<S149>/Sum2'
   */
  rtb_Cl_xA = rtb_RandomSource[0] / (1.0 / (1.0 - rtb_Cl_xA) * Plant_ConstB.Sum4
    * rtb_SumofElements) + Plant_DW.Delay_DSTATE[0];
  rtb_TrigonometricFunction2 = rtb_RandomSource[1] / (rtb_SumofElements *
    rtb_SumofElements1) + Plant_DW.Delay_DSTATE[1];
  rtb_Cm = rtb_RandomSource[2] / -1.0 + Plant_DW.Delay_DSTATE[2];

  /* S-Function (sdsprandsrc2): '<S145>/Random Source1' */
  RandSrc_GZ_R(rtb_RandomSource1, &Plant_ConstP.pooled27, 1,
               Plant_ConstP.RandomSource1_VarianceRTP, 3,
               Plant_DW.RandomSource1_STATE_DWORK, 3, 1);

  /* Sum: '<S143>/Sum1' incorporates:
   *  Delay: '<S142>/Delay1'
   */
  rtb_Va_B[0] = rtb_RandomSource1[0] + Plant_DW.Delay1_DSTATE_j[0];
  rtb_Va_B[1] = rtb_RandomSource1[1] + Plant_DW.Delay1_DSTATE_j[1];
  rtb_Va_B[2] = rtb_RandomSource1[2] + Plant_DW.Delay1_DSTATE_j[2];

  /* DiscreteFir: '<S148>/Discrete FIR Filter' */
  rtb_VectorConcatenate_on[0] = rtb_Va_B[0] * 0.5F +
    Plant_DW.DiscreteFIRFilter_states_i[0] * 0.5F;
  rtb_VectorConcatenate_on[1] = rtb_Va_B[1] * 0.5F +
    Plant_DW.DiscreteFIRFilter_states_i[1] * 0.5F;

  /* Gain: '<S137>/Gain6' incorporates:
   *  Math: '<S144>/Math Function'
   *  Product: '<S144>/Matrix Multiply'
   *  Sqrt: '<S144>/Sqrt'
   *  Switch: '<S144>/Switch'
   */
  rtb_SumofElements = fmod(floor(sqrtf(rtb_RandomSource[0] * rtb_RandomSource[0]
    + rtb_RandomSource[1] * rtb_RandomSource[1]) * 1000.0), 4.294967296E+9);

  /* Gain: '<S137>/Gain4' incorporates:
   *  DiscreteFir: '<S147>/Discrete FIR Filter'
   */
  rtb_SumofElements1 = fmod(floor((rtb_Cm * 0.5 +
    Plant_DW.DiscreteFIRFilter_states[2] * 0.5) * 1000.0), 4.294967296E+9);
  i = rtb_SumofElements1 < 0.0 ? -(int32_T)(uint32_T)-rtb_SumofElements1 :
    (int32_T)(uint32_T)rtb_SumofElements1;

  /* Gain: '<S137>/Gain5' incorporates:
   *  Math: '<S144>/Math Function2'
   *  Product: '<S144>/Matrix Multiply2'
   *  Sqrt: '<S144>/Sqrt2'
   *  Switch: '<S144>/Switch1'
   */
  rtb_SumofElements1 = fmod(floor(sqrtf(rtb_RandomSource[2] * rtb_RandomSource[2])
    * 1000.0), 4.294967296E+9);

  /* BusAssignment: '<S137>/Bus Assignment' incorporates:
   *  Constant: '<S137>/Constant10'
   *  Constant: '<S137>/Constant11'
   *  Constant: '<S137>/Constant12'
   *  Constant: '<S137>/Constant2'
   *  Constant: '<S137>/Constant3'
   *  Constant: '<S137>/Constant4'
   *  Constant: '<S137>/Constant5'
   *  Constant: '<S137>/Constant6'
   *  Constant: '<S137>/Constant7'
   *  Constant: '<S137>/Constant8'
   *  Constant: '<S137>/Constant9'
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
  rtb_BusAssignment_e.fixType = Plant_ConstB.DataTypeConversion;
  rtb_BusAssignment_e.flags = 0U;
  rtb_BusAssignment_e.reserved1 = 0U;
  rtb_BusAssignment_e.numSV = Plant_ConstB.DataTypeConversion1;

  /* Gain: '<S137>/Gain' incorporates:
   *  DiscreteFir: '<S147>/Discrete FIR Filter'
   *  Gain: '<S137>/Gain2'
   */
  rtb_Divide_e_idx_1 = fmod(floor((rtb_Cl_xA * 0.5 +
    Plant_DW.DiscreteFIRFilter_states[0] * 0.5) * 57.295779513082323 * 1.0E+7),
    4.294967296E+9);

  /* BusAssignment: '<S137>/Bus Assignment' incorporates:
   *  Gain: '<S137>/Gain'
   */
  rtb_BusAssignment_e.lon = rtb_Divide_e_idx_1 < 0.0 ? -(int32_T)(uint32_T)
    -rtb_Divide_e_idx_1 : (int32_T)(uint32_T)rtb_Divide_e_idx_1;

  /* Gain: '<S137>/Gain1' incorporates:
   *  DiscreteFir: '<S147>/Discrete FIR Filter'
   *  Gain: '<S137>/Gain3'
   */
  rtb_Divide_e_idx_1 = fmod(floor((rtb_TrigonometricFunction2 * 0.5 +
    Plant_DW.DiscreteFIRFilter_states[1] * 0.5) * 57.295779513082323 * 1.0E+7),
    4.294967296E+9);

  /* BusAssignment: '<S137>/Bus Assignment' incorporates:
   *  Gain: '<S137>/Gain1'
   *  Gain: '<S137>/Gain5'
   *  Gain: '<S137>/Gain6'
   */
  rtb_BusAssignment_e.lat = rtb_Divide_e_idx_1 < 0.0 ? -(int32_T)(uint32_T)
    -rtb_Divide_e_idx_1 : (int32_T)(uint32_T)rtb_Divide_e_idx_1;
  rtb_BusAssignment_e.height = i;
  rtb_BusAssignment_e.hMSL = i;
  rtb_BusAssignment_e.hAcc = rtb_SumofElements < 0.0 ? (uint32_T)-(int32_T)
    (uint32_T)-rtb_SumofElements : (uint32_T)rtb_SumofElements;
  rtb_BusAssignment_e.vAcc = rtb_SumofElements1 < 0.0 ? (uint32_T)-(int32_T)
    (uint32_T)-rtb_SumofElements1 : (uint32_T)rtb_SumofElements1;

  /* Gain: '<S137>/Gain7' */
  rtb_Gain_kz = fmodf(floorf(1000.0F * rtb_VectorConcatenate_on[0]),
                      4.2949673E+9F);

  /* BusAssignment: '<S137>/Bus Assignment' incorporates:
   *  Gain: '<S137>/Gain7'
   */
  rtb_BusAssignment_e.velN = rtb_Gain_kz < 0.0F ? -(int32_T)(uint32_T)
    -rtb_Gain_kz : (int32_T)(uint32_T)rtb_Gain_kz;

  /* Gain: '<S137>/Gain8' */
  rtb_Gain_kz = fmodf(floorf(1000.0F * rtb_VectorConcatenate_on[1]),
                      4.2949673E+9F);

  /* BusAssignment: '<S137>/Bus Assignment' incorporates:
   *  Gain: '<S137>/Gain8'
   */
  rtb_BusAssignment_e.velE = rtb_Gain_kz < 0.0F ? -(int32_T)(uint32_T)
    -rtb_Gain_kz : (int32_T)(uint32_T)rtb_Gain_kz;

  /* Gain: '<S137>/Gain9' incorporates:
   *  DiscreteFir: '<S148>/Discrete FIR Filter'
   */
  rtb_Gain_kz = fmodf(floorf((rtb_Va_B[2] * 0.5F +
    Plant_DW.DiscreteFIRFilter_states_i[2] * 0.5F) * 1000.0F), 4.2949673E+9F);

  /* BusAssignment: '<S137>/Bus Assignment' incorporates:
   *  Constant: '<S137>/Constant15'
   *  Gain: '<S137>/Gain11'
   *  Gain: '<S137>/Gain9'
   *  Math: '<S139>/Math Function'
   *  Math: '<S139>/Math Function1'
   *  Saturate: '<S139>/Saturation'
   *  Sqrt: '<S139>/Sqrt'
   *  Sum: '<S139>/Add'
   */
  rtb_BusAssignment_e.velD = rtb_Gain_kz < 0.0F ? -(int32_T)(uint32_T)
    -rtb_Gain_kz : (int32_T)(uint32_T)rtb_Gain_kz;
  rtb_BusAssignment_e.gSpeed = (int32_T)(uint32_T)fmodf(floorf(sqrtf(fmaxf
    (rtb_VectorConcatenate_on[0] * rtb_VectorConcatenate_on[0] +
     rtb_VectorConcatenate_on[1] * rtb_VectorConcatenate_on[1], 0.0F)) * 1000.0F),
    4.2949673E+9F);
  rtb_BusAssignment_e.heading = 0;

  /* Gain: '<S137>/Gain10' incorporates:
   *  Math: '<S144>/Math Function1'
   *  Product: '<S144>/Matrix Multiply1'
   *  Sqrt: '<S144>/Sqrt1'
   *  Switch: '<S144>/Switch2'
   */
  rtb_SumofElements = fmod(floor(sqrtf((rtb_RandomSource1[0] *
    rtb_RandomSource1[0] + rtb_RandomSource1[1] * rtb_RandomSource1[1]) +
    rtb_RandomSource1[2] * rtb_RandomSource1[2]) * 1000.0), 4.294967296E+9);

  /* BusAssignment: '<S137>/Bus Assignment' incorporates:
   *  Constant: '<S137>/Constant14'
   *  Constant: '<S137>/Constant16'
   *  Constant: '<S137>/Constant17'
   *  Gain: '<S137>/Gain10'
   *  Memory: '<S122>/Memory1'
   */
  rtb_BusAssignment_e.sAcc = rtb_SumofElements < 0.0 ? (uint32_T)-(int32_T)
    (uint32_T)-rtb_SumofElements : (uint32_T)rtb_SumofElements;
  rtb_BusAssignment_e.headingAcc = 0U;
  rtb_BusAssignment_e.pDOP = 0U;
  rtb_BusAssignment_e.reserved2 = 0U;
  rtb_BusAssignment_e.timestamp = Plant_DW.Memory1_PreviousInput;

  /* RateTransition: '<S137>/Rate Transition' */
  if (Plant_M->Timing.TaskCounters.TID[3] == 0) {
    Plant_B.RateTransition = rtb_BusAssignment_e;
  }

  /* End of RateTransition: '<S137>/Rate Transition' */

  /* Update for Delay: '<S142>/Delay' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S142>/ConcatBufferAtVector ConcatenateIn1'
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

  /* Update for DiscreteFir: '<S147>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states[0] = rtb_Cl_xA;

  /* Update for Delay: '<S142>/Delay' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S142>/ConcatBufferAtVector ConcatenateIn2'
   */
  Plant_DW.Delay_DSTATE[223] = Plant_Y.Plant_States.lat;

  /* Update for DiscreteFir: '<S147>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states[1] = rtb_TrigonometricFunction2;

  /* Update for Delay: '<S142>/Delay' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S142>/ConcatBufferAtVector ConcatenateIn3'
   */
  Plant_DW.Delay_DSTATE[224] = Plant_Y.Plant_States.alt;

  /* Update for DiscreteFir: '<S147>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states[2] = rtb_Cm;

  /* Update for Delay: '<S142>/Delay1' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S142>/ConcatBufferAtVector Concatenate1In1'
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

  /* Update for DiscreteFir: '<S148>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states_i[0] = rtb_Va_B[0];

  /* Update for Delay: '<S142>/Delay1' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S142>/ConcatBufferAtVector Concatenate1In2'
   */
  Plant_DW.Delay1_DSTATE_j[148] = Plant_Y.Plant_States.vel_y_O;

  /* Update for DiscreteFir: '<S148>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states_i[1] = rtb_Va_B[1];

  /* Update for Delay: '<S142>/Delay1' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S142>/ConcatBufferAtVector Concatenate1In3'
   */
  Plant_DW.Delay1_DSTATE_j[149] = Plant_Y.Plant_States.vel_z_O;

  /* Update for DiscreteFir: '<S148>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states_i[2] = rtb_Va_B[2];

  /* End of Outputs for SubSystem: '<S7>/Sensor_GPS' */

  /* Outputs for Atomic SubSystem: '<S7>/Sensor_IMU' */
  /* Outputs for Atomic SubSystem: '<S154>/Vibration_Model' */
  /* Outputs for Atomic SubSystem: '<S165>/Vibration_Model' */
  /* Product: '<S171>/Divide2' incorporates:
   *  Constant: '<S171>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Product: '<S160>/Divide2'
   */
  rtb_Cl_xA = Plant_Y.Extended_States.prop_vel[0] / 1047.1975511965977;

  /* End of Outputs for SubSystem: '<S154>/Vibration_Model' */

  /* Math: '<S171>/u^2' */
  rtb_TrigonometricFunction2 = rtb_Cl_xA * rtb_Cl_xA;

  /* Product: '<S167>/Product2' incorporates:
   *  DiscreteIntegrator: '<S167>/Discrete-Time Integrator'
   *  Trigonometry: '<S167>/Trigonometric Function2'
   */
  rtb_SumofElements1 = arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[0]) *
    rtb_TrigonometricFunction2;

  /* Math: '<S171>/u^2' incorporates:
   *  DiscreteIntegrator: '<S167>/Discrete-Time Integrator'
   *  Product: '<S167>/Product1'
   *  Trigonometry: '<S167>/Trigonometric Function1'
   */
  rtb_Cm = arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[0]) *
    rtb_TrigonometricFunction2;

  /* Product: '<S171>/Divide2' incorporates:
   *  Constant: '<S171>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Product: '<S160>/Divide2'
   */
  rtb_Divide_e_idx_1 = rtb_Cl_xA;

  /* Outputs for Atomic SubSystem: '<S154>/Vibration_Model' */
  rtb_Cl_xA = Plant_Y.Extended_States.prop_vel[1] / 1047.1975511965977;

  /* End of Outputs for SubSystem: '<S154>/Vibration_Model' */

  /* Math: '<S171>/u^2' */
  rtb_TrigonometricFunction2 = rtb_Cl_xA * rtb_Cl_xA;

  /* Product: '<S167>/Product2' incorporates:
   *  DiscreteIntegrator: '<S167>/Discrete-Time Integrator'
   *  Trigonometry: '<S167>/Trigonometric Function2'
   */
  rtb_SumofElements = arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[1]) *
    rtb_TrigonometricFunction2;

  /* Math: '<S171>/u^2' incorporates:
   *  DiscreteIntegrator: '<S167>/Discrete-Time Integrator'
   *  Product: '<S167>/Product1'
   *  Trigonometry: '<S167>/Trigonometric Function1'
   */
  rtb_Cl_zA = arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[1]) *
    rtb_TrigonometricFunction2;

  /* Product: '<S171>/Divide2' incorporates:
   *  Constant: '<S171>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Product: '<S160>/Divide2'
   */
  rtb_CYr = rtb_Cl_xA;

  /* Outputs for Atomic SubSystem: '<S154>/Vibration_Model' */
  rtb_Cl_xA = Plant_Y.Extended_States.prop_vel[2] / 1047.1975511965977;

  /* End of Outputs for SubSystem: '<S154>/Vibration_Model' */

  /* Math: '<S171>/u^2' */
  rtb_TrigonometricFunction2 = rtb_Cl_xA * rtb_Cl_xA;

  /* Product: '<S171>/Divide2' incorporates:
   *  Constant: '<S171>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Product: '<S160>/Divide2'
   */
  rtb_Cl_yA = rtb_Cl_xA;

  /* Outputs for Atomic SubSystem: '<S154>/Vibration_Model' */
  rtb_Cl_xA = Plant_Y.Extended_States.prop_vel[3] / 1047.1975511965977;

  /* Math: '<S171>/u^2' incorporates:
   *  Math: '<S160>/u^2'
   */
  rtb_Cl_xA *= rtb_Cl_xA;

  /* End of Outputs for SubSystem: '<S154>/Vibration_Model' */

  /* Sum: '<S167>/Sum of Elements' incorporates:
   *  DiscreteIntegrator: '<S167>/Discrete-Time Integrator'
   *  Math: '<S171>/u^2'
   *  Product: '<S167>/Product2'
   *  Trigonometry: '<S167>/Trigonometric Function2'
   */
  rtb_SumofElements1 = ((rtb_SumofElements1 + rtb_SumofElements) + arm_sin_f32
                        (Plant_DW.DiscreteTimeIntegrator_DSTATE[2]) *
                        rtb_TrigonometricFunction2) + arm_sin_f32
    (Plant_DW.DiscreteTimeIntegrator_DSTATE[3]) * rtb_Cl_xA;

  /* Sum: '<S167>/Sum of Elements1' incorporates:
   *  DiscreteIntegrator: '<S167>/Discrete-Time Integrator'
   *  Math: '<S171>/u^2'
   *  Product: '<S167>/Product1'
   *  Trigonometry: '<S167>/Trigonometric Function1'
   */
  rtb_SumofElements = ((rtb_Cm + rtb_Cl_zA) + arm_cos_f32
                       (Plant_DW.DiscreteTimeIntegrator_DSTATE[2]) *
                       rtb_TrigonometricFunction2) + arm_cos_f32
    (Plant_DW.DiscreteTimeIntegrator_DSTATE[3]) * rtb_Cl_xA;

  /* Outputs for Atomic SubSystem: '<S154>/Vibration_Model' */
  /* Update for DiscreteIntegrator: '<S167>/Discrete-Time Integrator' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S156>/Discrete-Time Integrator'
   */
  rtb_Sum1_dw_idx_0 = 0.002F * Plant_Y.Extended_States.prop_vel[0];

  /* End of Outputs for SubSystem: '<S154>/Vibration_Model' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE[0] += rtb_Sum1_dw_idx_0;

  /* End of Outputs for SubSystem: '<S165>/Vibration_Model' */
  /* End of Outputs for SubSystem: '<S7>/Sensor_IMU' */
  /* End of Outputs for SubSystem: '<Root>/Sensor_Model' */
  rtb_Switch_idx_0 = rtb_Sum1_dw_idx_0;

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_Model' */
  /* Outputs for Atomic SubSystem: '<S7>/Sensor_IMU' */
  /* Outputs for Atomic SubSystem: '<S154>/Vibration_Model' */
  /* Outputs for Atomic SubSystem: '<S165>/Vibration_Model' */
  /* Update for DiscreteIntegrator: '<S167>/Discrete-Time Integrator' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S156>/Discrete-Time Integrator'
   */
  rtb_Sum1_dw_idx_0 = 0.002F * Plant_Y.Extended_States.prop_vel[1];

  /* End of Outputs for SubSystem: '<S154>/Vibration_Model' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE[1] += rtb_Sum1_dw_idx_0;

  /* End of Outputs for SubSystem: '<S165>/Vibration_Model' */
  /* End of Outputs for SubSystem: '<S7>/Sensor_IMU' */
  /* End of Outputs for SubSystem: '<Root>/Sensor_Model' */
  rtb_Switch_idx_1 = rtb_Sum1_dw_idx_0;

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_Model' */
  /* Outputs for Atomic SubSystem: '<S7>/Sensor_IMU' */
  /* Outputs for Atomic SubSystem: '<S154>/Vibration_Model' */
  /* Outputs for Atomic SubSystem: '<S165>/Vibration_Model' */
  /* Update for DiscreteIntegrator: '<S167>/Discrete-Time Integrator' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S156>/Discrete-Time Integrator'
   */
  rtb_Sum1_dw_idx_0 = 0.002F * Plant_Y.Extended_States.prop_vel[2];

  /* End of Outputs for SubSystem: '<S154>/Vibration_Model' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE[2] += rtb_Sum1_dw_idx_0;

  /* End of Outputs for SubSystem: '<S165>/Vibration_Model' */
  /* End of Outputs for SubSystem: '<S7>/Sensor_IMU' */
  /* End of Outputs for SubSystem: '<Root>/Sensor_Model' */
  rtb_Switch_idx_2 = rtb_Sum1_dw_idx_0;

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_Model' */
  /* Outputs for Atomic SubSystem: '<S7>/Sensor_IMU' */
  /* Outputs for Atomic SubSystem: '<S154>/Vibration_Model' */
  /* Outputs for Atomic SubSystem: '<S165>/Vibration_Model' */
  /* Update for DiscreteIntegrator: '<S167>/Discrete-Time Integrator' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S156>/Discrete-Time Integrator'
   */
  rtb_Sum1_dw_idx_0 = 0.002F * Plant_Y.Extended_States.prop_vel[3];

  /* End of Outputs for SubSystem: '<S154>/Vibration_Model' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE[3] += rtb_Sum1_dw_idx_0;

  /* Switch: '<S165>/Switch' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S167>/Gain2'
   *  Gain: '<S167>/Gain4'
   *  Product: '<S167>/Divide'
   *  SignalConversion: '<S167>/ConcatBufferAtVector ConcatenateIn1'
   *  SignalConversion: '<S169>/ConcatBufferAtVector ConcatenateIn1'
   *  SignalConversion: '<S169>/ConcatBufferAtVector ConcatenateIn2'
   *  SignalConversion: '<S169>/ConcatBufferAtVector ConcatenateIn3'
   *  Sum: '<S165>/Sum'
   *  Sum: '<S167>/Sum'
   *  Sum: '<S167>/Sum of Elements1'
   */
  rtb_VectorConcatenate_on[0] = (real32_T)(rtb_SumofElements1 / 4.0 * 0.5 +
    Plant_Y.Plant_States.rot_x_B);
  rtb_VectorConcatenate_on[1] = (real32_T)(rtb_SumofElements / 4.0 * 0.5 +
    Plant_Y.Plant_States.rot_y_B);
  rtb_Switch_idx_3 = (real32_T)((rtb_SumofElements1 + rtb_SumofElements) * 0.5 /
    4.0 * 0.5 + Plant_Y.Plant_States.rot_z_B);

  /* End of Outputs for SubSystem: '<S165>/Vibration_Model' */

  /* Sum: '<S173>/Sum' incorporates:
   *  Product: '<S173>/Product'
   */
  for (i = 0; i < 3; i++) {
    rtb_RandomSource[i] = (Plant_ConstB.Add_k[i + 3] * rtb_VectorConcatenate_on
      [1] + Plant_ConstB.Add_k[i] * rtb_VectorConcatenate_on[0]) +
      Plant_ConstB.Add_k[i + 6] * rtb_Switch_idx_3;
  }

  /* End of Sum: '<S173>/Sum' */

  /* DiscreteIntegrator: '<S172>/Discrete-Time Integrator5' */
  if (Plant_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[0] = rtb_RandomSource[0];
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[1] = rtb_RandomSource[1];
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[2] = rtb_RandomSource[2];
  }

  /* S-Function (sdsprandsrc2): '<S163>/Random Source' */
  RandSrc_GZ_R(rtb_MathFunction, &Plant_ConstP.pooled27, 1,
               Plant_ConstP.RandomSource_VarianceRTP_h, 3,
               Plant_DW.RandomSource_STATE_DWORK_f, 3, 1);

  /* S-Function (sdsprandsrc2): '<S174>/Random Source' */
  RandSrc_GZ_R(rtb_Sum_fw, &Plant_ConstP.pooled27, 1,
               Plant_ConstP.RandomSource_VarianceRTP_o, 3,
               Plant_DW.RandomSource_STATE_DWORK_p, 3, 1);

  /* Saturate: '<S166>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S172>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[0] > 34.9065857F) {
    rtb_Gain_kz = 34.9065857F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[0] < -34.9065857F) {
    rtb_Gain_kz = -34.9065857F;
  } else {
    rtb_Gain_kz = Plant_DW.DiscreteTimeIntegrator5_DSTATE[0];
  }

  /* Sum: '<S166>/Sum' */
  rtb_Add_i[0] = rtb_Gain_kz + rtb_Sum_fw[0];

  /* Saturate: '<S166>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S172>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[1] > 34.9065857F) {
    rtb_Gain_kz = 34.9065857F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[1] < -34.9065857F) {
    rtb_Gain_kz = -34.9065857F;
  } else {
    rtb_Gain_kz = Plant_DW.DiscreteTimeIntegrator5_DSTATE[1];
  }

  /* Sum: '<S166>/Sum' */
  rtb_Add_i[1] = rtb_Gain_kz + rtb_Sum_fw[1];

  /* Saturate: '<S166>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S172>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[2] > 34.9065857F) {
    rtb_Gain_kz = 34.9065857F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[2] < -34.9065857F) {
    rtb_Gain_kz = -34.9065857F;
  } else {
    rtb_Gain_kz = Plant_DW.DiscreteTimeIntegrator5_DSTATE[2];
  }

  /* Sum: '<S166>/Sum' */
  rtb_Add_i[2] = rtb_Gain_kz + rtb_Sum_fw[2];

  /* Outputs for Atomic SubSystem: '<S154>/Vibration_Model' */
  /* Math: '<S160>/u^2' incorporates:
   *  Product: '<S160>/Divide2'
   */
  rtb_TrigonometricFunction2 = rtb_Divide_e_idx_1 * rtb_Divide_e_idx_1;

  /* Product: '<S156>/Product2' incorporates:
   *  DiscreteIntegrator: '<S156>/Discrete-Time Integrator'
   *  Trigonometry: '<S156>/Trigonometric Function2'
   */
  rtb_SumofElements1 = arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_f[0]) *
    rtb_TrigonometricFunction2;

  /* Math: '<S160>/u^2' incorporates:
   *  DiscreteIntegrator: '<S156>/Discrete-Time Integrator'
   *  Product: '<S156>/Product1'
   *  Product: '<S160>/Divide2'
   *  Trigonometry: '<S156>/Trigonometric Function1'
   */
  rtb_Cm = arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_f[0]) *
    rtb_TrigonometricFunction2;
  rtb_TrigonometricFunction2 = rtb_CYr * rtb_CYr;

  /* Product: '<S156>/Product2' incorporates:
   *  DiscreteIntegrator: '<S156>/Discrete-Time Integrator'
   *  Trigonometry: '<S156>/Trigonometric Function2'
   */
  rtb_SumofElements = arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_f[1]) *
    rtb_TrigonometricFunction2;

  /* Math: '<S160>/u^2' incorporates:
   *  DiscreteIntegrator: '<S156>/Discrete-Time Integrator'
   *  Product: '<S156>/Product1'
   *  Product: '<S160>/Divide2'
   *  Trigonometry: '<S156>/Trigonometric Function1'
   */
  rtb_Cl_zA = arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_f[1]) *
    rtb_TrigonometricFunction2;
  rtb_TrigonometricFunction2 = rtb_Cl_yA * rtb_Cl_yA;

  /* Sum: '<S156>/Sum of Elements' incorporates:
   *  DiscreteIntegrator: '<S156>/Discrete-Time Integrator'
   *  Product: '<S156>/Product2'
   *  Trigonometry: '<S156>/Trigonometric Function2'
   */
  rtb_SumofElements = ((rtb_SumofElements1 + rtb_SumofElements) + arm_sin_f32
                       (Plant_DW.DiscreteTimeIntegrator_DSTATE_f[2]) *
                       rtb_TrigonometricFunction2) + arm_sin_f32
    (Plant_DW.DiscreteTimeIntegrator_DSTATE_f[3]) * rtb_Cl_xA;

  /* SignalConversion: '<S156>/ConcatBufferAtVector ConcatenateIn1' incorporates:
   *  Sum: '<S156>/Sum of Elements'
   */
  rtb_Divide2[0] = rtb_SumofElements;

  /* Sum: '<S156>/Sum of Elements1' incorporates:
   *  DiscreteIntegrator: '<S156>/Discrete-Time Integrator'
   *  Product: '<S156>/Product1'
   *  Trigonometry: '<S156>/Trigonometric Function1'
   */
  rtb_SumofElements1 = ((rtb_Cm + rtb_Cl_zA) + arm_cos_f32
                        (Plant_DW.DiscreteTimeIntegrator_DSTATE_f[2]) *
                        rtb_TrigonometricFunction2) + arm_cos_f32
    (Plant_DW.DiscreteTimeIntegrator_DSTATE_f[3]) * rtb_Cl_xA;

  /* SignalConversion: '<S156>/ConcatBufferAtVector ConcatenateIn2' */
  rtb_Divide2[1] = rtb_SumofElements1;

  /* Gain: '<S156>/Gain2' incorporates:
   *  Sum: '<S156>/Sum'
   *  Sum: '<S156>/Sum of Elements'
   */
  rtb_Divide2[2] = (rtb_SumofElements + rtb_SumofElements1) * 0.5;

  /* Update for DiscreteIntegrator: '<S156>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_f[0] += rtb_Switch_idx_0;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_f[1] += rtb_Switch_idx_1;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_f[2] += rtb_Switch_idx_2;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_f[3] += rtb_Sum1_dw_idx_0;

  /* End of Outputs for SubSystem: '<S154>/Vibration_Model' */

  /* Switch: '<S154>/Switch' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S156>/Gain4'
   *  Product: '<S156>/Divide'
   *  Product: '<S158>/Product1'
   *  SignalConversion: '<S158>/ConcatBufferAtVector Concatenate1In1'
   *  SignalConversion: '<S158>/ConcatBufferAtVector Concatenate1In2'
   *  SignalConversion: '<S158>/ConcatBufferAtVector Concatenate1In3'
   *  Sum: '<S154>/Sum'
   *  Sum: '<S158>/Sum'
   */
  for (i = 0; i < 3; i++) {
    /* Outputs for Atomic SubSystem: '<S154>/Vibration_Model' */
    rtb_Sum_fw[i] = (real32_T)(((Plant_Y.Extended_States.M_BO[i + 3] *
      Plant_Y.Plant_States.acc_y_O + Plant_Y.Extended_States.M_BO[i] *
      Plant_Y.Plant_States.acc_x_O) + Plant_Y.Extended_States.M_BO[i + 6] *
      (Plant_Y.Plant_States.acc_z_O - 9.80665F)) + rtb_Divide2[i] / 4.0 *
      Plant_ConstP.Gain4_Gain[i]);

    /* End of Outputs for SubSystem: '<S154>/Vibration_Model' */
  }

  /* End of Switch: '<S154>/Switch' */

  /* Sum: '<S162>/Sum' incorporates:
   *  Product: '<S162>/Product'
   */
  for (i = 0; i < 3; i++) {
    rtb_RandomSource1[i] = (Plant_ConstB.Add_g[i + 3] * rtb_Sum_fw[1] +
      Plant_ConstB.Add_g[i] * rtb_Sum_fw[0]) + Plant_ConstB.Add_g[i + 6] *
      rtb_Sum_fw[2];
  }

  /* End of Sum: '<S162>/Sum' */

  /* DiscreteIntegrator: '<S161>/Discrete-Time Integrator5' */
  if (Plant_DW.DiscreteTimeIntegrator5_IC_LO_g != 0) {
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[0] = rtb_RandomSource1[0];
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[1] = rtb_RandomSource1[1];
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[2] = rtb_RandomSource1[2];
  }

  /* Outport: '<Root>/IMU' incorporates:
   *  BusAssignment: '<S151>/Bus Assignment'
   *  Memory: '<S122>/Memory1'
   */
  Plant_Y.IMU.timestamp = Plant_DW.Memory1_PreviousInput;
  Plant_Y.IMU.gyr_x = rtb_Add_i[0];
  Plant_Y.IMU.gyr_y = rtb_Add_i[1];
  Plant_Y.IMU.gyr_z = rtb_Add_i[2];

  /* Update for DiscreteIntegrator: '<S172>/Discrete-Time Integrator5' */
  Plant_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;

  /* Update for DiscreteIntegrator: '<S161>/Discrete-Time Integrator5' */
  Plant_DW.DiscreteTimeIntegrator5_IC_LO_g = 0U;

  /* End of Outputs for SubSystem: '<S7>/Sensor_IMU' */

  /* Outputs for Atomic SubSystem: '<S7>/Sensor_MAG' */
  /* Gain: '<S180>/rad_to_index' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S180>/TmpSignal ConversionAtrad_to_indexInport1'
   */
  rtb_SumofElements = fmod(floor(5.7295779513082321 * Plant_Y.Plant_States.lat),
    4.294967296E+9);

  /* Sum: '<S180>/Add' incorporates:
   *  Gain: '<S180>/rad_to_index'
   */
  i = (rtb_SumofElements < 0.0 ? -(int32_T)(uint32_T)-rtb_SumofElements :
       (int32_T)(uint32_T)rtb_SumofElements) + 8;

  /* Saturate: '<S180>/Saturation1' */
  if (i > 16) {
    i = 16;
  } else {
    if (i < 0) {
      i = 0;
    }
  }

  /* Gain: '<S180>/rad_to_index' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S180>/TmpSignal ConversionAtrad_to_indexInport1'
   */
  rtb_SumofElements = fmod(floor(5.7295779513082321 * Plant_Y.Plant_States.lon),
    4.294967296E+9);

  /* Sum: '<S180>/Add' incorporates:
   *  Gain: '<S180>/rad_to_index'
   */
  rtb_Saturation1_m_idx_1 = (rtb_SumofElements < 0.0 ? -(int32_T)(uint32_T)
    -rtb_SumofElements : (int32_T)(uint32_T)rtb_SumofElements) + 18;

  /* Saturate: '<S180>/Saturation1' */
  if (rtb_Saturation1_m_idx_1 > 36) {
    rtb_Saturation1_m_idx_1 = 36;
  } else {
    if (rtb_Saturation1_m_idx_1 < 0) {
      rtb_Saturation1_m_idx_1 = 0;
    }
  }

  /* LookupNDDirect: '<S180>/Declination_Lookup_Table' incorporates:
   *  LookupNDDirect: '<S180>/Inclination_Lookup_Table'
   *  LookupNDDirect: '<S180>/Magnitude_Lookup_Table'
   *
   * About '<S180>/Declination_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   *
   * About '<S180>/Inclination_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   *
   * About '<S180>/Magnitude_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  i += rtb_Saturation1_m_idx_1 * 17;

  /* Gain: '<S181>/Gain1' incorporates:
   *  LookupNDDirect: '<S180>/Declination_Lookup_Table'
   *
   * About '<S180>/Declination_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  rtb_Sum1_dw_idx_0 = Plant_ConstP.Declination_Lookup_Table_table[i] *
    0.0174532924F;

  /* Trigonometry: '<S183>/Trigonometric Function1' incorporates:
   *  Trigonometry: '<S183>/Trigonometric Function3'
   */
  rtb_Switch_idx_1 = arm_cos_f32(rtb_Sum1_dw_idx_0);
  rtb_VectorConcatenate_f[0] = rtb_Switch_idx_1;

  /* Trigonometry: '<S183>/Trigonometric Function' incorporates:
   *  Trigonometry: '<S183>/Trigonometric Function2'
   */
  rtb_Switch_idx_2 = arm_sin_f32(rtb_Sum1_dw_idx_0);
  rtb_VectorConcatenate_f[1] = rtb_Switch_idx_2;

  /* SignalConversion: '<S183>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S183>/Constant3'
   */
  rtb_VectorConcatenate_f[2] = 0.0F;

  /* Gain: '<S183>/Gain' */
  rtb_VectorConcatenate_f[3] = -rtb_Switch_idx_2;

  /* Trigonometry: '<S183>/Trigonometric Function3' */
  rtb_VectorConcatenate_f[4] = rtb_Switch_idx_1;

  /* SignalConversion: '<S183>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S183>/Constant4'
   */
  rtb_VectorConcatenate_f[5] = 0.0F;

  /* Gain: '<S181>/Gain' incorporates:
   *  LookupNDDirect: '<S180>/Inclination_Lookup_Table'
   *
   * About '<S180>/Inclination_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  rtb_Sum1_dw_idx_0 = Plant_ConstP.Inclination_Lookup_Table_table[i] *
    -0.0174532924F;

  /* Trigonometry: '<S182>/Trigonometric Function3' incorporates:
   *  Trigonometry: '<S182>/Trigonometric Function1'
   */
  rtb_Switch_idx_1 = arm_cos_f32(rtb_Sum1_dw_idx_0);
  rtb_VectorConcatenate_d[0] = rtb_Switch_idx_1;

  /* SignalConversion: '<S182>/ConcatBufferAtVector Concatenate2In2' incorporates:
   *  Constant: '<S182>/Constant4'
   */
  rtb_VectorConcatenate_d[1] = 0.0F;

  /* Trigonometry: '<S182>/Trigonometric Function2' incorporates:
   *  Trigonometry: '<S182>/Trigonometric Function'
   */
  rtb_Switch_idx_2 = arm_sin_f32(rtb_Sum1_dw_idx_0);

  /* Gain: '<S182>/Gain' incorporates:
   *  Trigonometry: '<S182>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_d[2] = -rtb_Switch_idx_2;

  /* End of Outputs for SubSystem: '<S7>/Sensor_MAG' */

  /* Outputs for Atomic SubSystem: '<S7>/Sensor_IMU' */
  /* Saturate: '<S155>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S161>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[0] > 78.4532F) {
    rtb_Sum1_dw_idx_0 = 78.4532F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[0] < -78.4532F) {
    rtb_Sum1_dw_idx_0 = -78.4532F;
  } else {
    rtb_Sum1_dw_idx_0 = Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[0];
  }

  /* Update for DiscreteIntegrator: '<S172>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S172>/Gain'
   *  Sum: '<S172>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTATE[0] += (rtb_RandomSource[0] -
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 314.159271F * 0.002F;

  /* Update for DiscreteIntegrator: '<S161>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S161>/Gain'
   *  Sum: '<S161>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[0] += (rtb_RandomSource1[0] -
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[0]) * 314.159271F * 0.002F;

  /* End of Outputs for SubSystem: '<S7>/Sensor_IMU' */

  /* Outputs for Atomic SubSystem: '<S7>/Sensor_MAG' */
  /* SignalConversion: '<S183>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_f[6] = Plant_ConstB.VectorConcatenate3[0];

  /* SignalConversion: '<S182>/ConcatBufferAtVector ConcatenateIn2' */
  rtb_VectorConcatenate_d[3] = Plant_ConstB.VectorConcatenate3_e[0];

  /* End of Outputs for SubSystem: '<S7>/Sensor_MAG' */

  /* Outputs for Atomic SubSystem: '<S7>/Sensor_IMU' */
  /* Saturate: '<S155>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S161>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[1] > 78.4532F) {
    rtb_MathFunction1_k = 78.4532F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[1] < -78.4532F) {
    rtb_MathFunction1_k = -78.4532F;
  } else {
    rtb_MathFunction1_k = Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[1];
  }

  /* Update for DiscreteIntegrator: '<S172>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S172>/Gain'
   *  Sum: '<S172>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTATE[1] += (rtb_RandomSource[1] -
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 314.159271F * 0.002F;

  /* Update for DiscreteIntegrator: '<S161>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S161>/Gain'
   *  Sum: '<S161>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[1] += (rtb_RandomSource1[1] -
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[1]) * 314.159271F * 0.002F;

  /* End of Outputs for SubSystem: '<S7>/Sensor_IMU' */

  /* Outputs for Atomic SubSystem: '<S7>/Sensor_MAG' */
  /* SignalConversion: '<S183>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_f[7] = Plant_ConstB.VectorConcatenate3[1];

  /* SignalConversion: '<S182>/ConcatBufferAtVector ConcatenateIn2' */
  rtb_VectorConcatenate_d[4] = Plant_ConstB.VectorConcatenate3_e[1];

  /* End of Outputs for SubSystem: '<S7>/Sensor_MAG' */

  /* Outputs for Atomic SubSystem: '<S7>/Sensor_IMU' */
  /* Saturate: '<S155>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S161>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[2] > 78.4532F) {
    rtb_Sum1_dw_idx_2 = 78.4532F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[2] < -78.4532F) {
    rtb_Sum1_dw_idx_2 = -78.4532F;
  } else {
    rtb_Sum1_dw_idx_2 = Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[2];
  }

  /* Update for DiscreteIntegrator: '<S172>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S172>/Gain'
   *  Sum: '<S172>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTATE[2] += (rtb_RandomSource[2] -
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 314.159271F * 0.002F;

  /* Update for DiscreteIntegrator: '<S161>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S161>/Gain'
   *  Sum: '<S161>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[2] += (rtb_RandomSource1[2] -
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[2]) * 314.159271F * 0.002F;

  /* End of Outputs for SubSystem: '<S7>/Sensor_IMU' */

  /* Outputs for Atomic SubSystem: '<S7>/Sensor_MAG' */
  /* SignalConversion: '<S183>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_f[8] = Plant_ConstB.VectorConcatenate3[2];

  /* SignalConversion: '<S182>/ConcatBufferAtVector ConcatenateIn2' */
  rtb_VectorConcatenate_d[5] = Plant_ConstB.VectorConcatenate3_e[2];

  /* Trigonometry: '<S182>/Trigonometric Function' */
  rtb_VectorConcatenate_d[6] = rtb_Switch_idx_2;

  /* SignalConversion: '<S182>/ConcatBufferAtVector Concatenate1In2' incorporates:
   *  Constant: '<S182>/Constant3'
   */
  rtb_VectorConcatenate_d[7] = 0.0F;

  /* Trigonometry: '<S182>/Trigonometric Function1' */
  rtb_VectorConcatenate_d[8] = rtb_Switch_idx_1;

  /* Gain: '<S181>/toGauss' incorporates:
   *  LookupNDDirect: '<S180>/Magnitude_Lookup_Table'
   *
   * About '<S180>/Magnitude_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  rtb_Switch_idx_1 = Plant_ConstP.Magnitude_Lookup_Table_table[i] * 0.01F;

  /* Product: '<S181>/Multiply1' incorporates:
   *  Product: '<S181>/Multiply'
   */
  for (i = 0; i < 3; i++) {
    rtb_Va_B[i] = rtb_VectorConcatenate_d[i] * rtb_Switch_idx_1;
  }

  /* End of Product: '<S181>/Multiply1' */

  /* Product: '<S181>/Multiply2' */
  for (i = 0; i < 3; i++) {
    rtb_Add_i[i] = rtb_VectorConcatenate_f[i + 6] * rtb_Va_B[2] +
      (rtb_VectorConcatenate_f[i + 3] * rtb_Va_B[1] + rtb_VectorConcatenate_f[i]
       * rtb_Va_B[0]);
  }

  /* End of Product: '<S181>/Multiply2' */

  /* Product: '<S178>/Product' incorporates:
   *  Delay: '<Root>/Delay'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_on[i] = Plant_Y.Extended_States.M_BO[i + 6] *
      rtb_Add_i[2] + (Plant_Y.Extended_States.M_BO[i + 3] * rtb_Add_i[1] +
                      Plant_Y.Extended_States.M_BO[i] * rtb_Add_i[0]);
  }

  /* End of Product: '<S178>/Product' */
  for (i = 0; i < 3; i++) {
    /* Sum: '<S184>/Sum' incorporates:
     *  Product: '<S184>/Product'
     */
    rtb_Gain_kz = (Plant_ConstB.Add[i + 3] * rtb_VectorConcatenate_on[1] +
                   Plant_ConstB.Add[i] * rtb_VectorConcatenate_on[0]) +
      Plant_ConstB.Add[i + 6] * rtb_VectorConcatenate_on[2];

    /* Saturate: '<S179>/Saturation' incorporates:
     *  Sum: '<S184>/Sum'
     */
    if (rtb_Gain_kz > 4.0F) {
      rtb_Add_i[i] = 4.0F;
    } else if (rtb_Gain_kz < -4.0F) {
      rtb_Add_i[i] = -4.0F;
    } else {
      rtb_Add_i[i] = rtb_Gain_kz;
    }

    /* End of Saturate: '<S179>/Saturation' */
  }

  /* S-Function (sdsprandsrc2): '<S185>/Random Source' */
  RandSrc_GZ_R(rtb_VectorConcatenate_on, &Plant_ConstP.pooled27, 1,
               Plant_ConstP.RandomSource_VarianceRTP_om, 3,
               Plant_DW.RandomSource_STATE_DWORK, 3, 1);

  /* Sum: '<S179>/Add' */
  rtb_Add_i[0] += rtb_VectorConcatenate_on[0];
  rtb_Add_i[1] += rtb_VectorConcatenate_on[1];

  /* BusAssignment: '<S175>/Bus Assignment' incorporates:
   *  Memory: '<S122>/Memory1'
   *  Sum: '<S179>/Add'
   */
  rtb_BusAssignment_j.timestamp = Plant_DW.Memory1_PreviousInput;
  rtb_BusAssignment_j.mag_x = rtb_Add_i[0];
  rtb_BusAssignment_j.mag_y = rtb_Add_i[1];
  rtb_BusAssignment_j.mag_z = rtb_Add_i[2] + rtb_VectorConcatenate_on[2];

  /* RateTransition: '<S175>/Rate Transition' */
  if (Plant_M->Timing.TaskCounters.TID[2] == 0) {
    Plant_B.RateTransition_l = rtb_BusAssignment_j;
  }

  /* End of RateTransition: '<S175>/Rate Transition' */
  /* End of Outputs for SubSystem: '<S7>/Sensor_MAG' */

  /* Update for Memory: '<S122>/Memory1' incorporates:
   *  Constant: '<S122>/dt'
   *  Sum: '<S122>/Sum'
   */
  Plant_DW.Memory1_PreviousInput += PLANT_EXPORT.period;

  /* Outputs for Atomic SubSystem: '<S7>/Sensor_IMU' */
  /* Outport: '<Root>/IMU' incorporates:
   *  Sum: '<S155>/Sum'
   */
  Plant_Y.IMU.acc_x = rtb_Sum1_dw_idx_0 + rtb_MathFunction[0];
  Plant_Y.IMU.acc_y = rtb_MathFunction1_k + rtb_MathFunction[1];
  Plant_Y.IMU.acc_z = rtb_Sum1_dw_idx_2 + rtb_MathFunction[2];

  /* End of Outputs for SubSystem: '<S7>/Sensor_IMU' */
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
    /* InitializeConditions for DiscreteIntegrator: '<S101>/Discrete-Time Integrator' */
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[0] = Plant_ConstB.quat0[0];
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[1] = Plant_ConstB.quat0[1];
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[2] = Plant_ConstB.quat0[2];
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[3] = Plant_ConstB.quat0[3];
    Plant_DW.DiscreteTimeIntegrator_PrevRese = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S97>/Discrete-Time Integrator' */
    Plant_DW.DiscreteTimeIntegrator_PrevRe_p = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S98>/Discrete-Time Integrator' */
    Plant_DW.DiscreteTimeIntegrator_PrevRe_g = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S98>/Discrete-Time Integrator1' */
    Plant_DW.DiscreteTimeIntegrator1_PrevRes = 0;

    /* End of SystemInitialize for SubSystem: '<Root>/Kinematic_Equation' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Bus_Constructor' */
    /* InitializeConditions for Delay: '<S45>/Delay1' */
    Plant_DW.Delay1_DSTATE[0] = 0.65673;
    Plant_DW.Delay1_DSTATE[1] = -2.1361;
    Plant_DW.Delay1_DSTATE[2] = 4.5;

    /* End of SystemInitialize for SubSystem: '<Root>/Bus_Constructor' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Sensor_Model' */
    /* SystemInitialize for Atomic SubSystem: '<S7>/Sensor_Barometer' */
    /* InitializeConditions for S-Function (sdsprandsrc2): '<S136>/Random Source' */
    RandomSource_SEED_DWORK_n = 91337U;
    RandSrcInitState_GZ(&RandomSource_SEED_DWORK_n,
                        Plant_DW.RandomSource_STATE_DWORK_fn, 1);

    /* End of SystemInitialize for SubSystem: '<S7>/Sensor_Barometer' */

    /* SystemInitialize for Atomic SubSystem: '<S7>/Sensor_GPS' */
    /* InitializeConditions for S-Function (sdsprandsrc2): '<S145>/Random Source' */
    RandSrcCreateSeeds_32(63235U, Plant_DW.RandomSource_SEED_DWORK_a, 3);
    RandSrcInitState_GZ(Plant_DW.RandomSource_SEED_DWORK_a,
                        Plant_DW.RandomSource_STATE_DWORK_f2, 3);

    /* InitializeConditions for DiscreteFir: '<S147>/Discrete FIR Filter' */
    Plant_DW.DiscreteFIRFilter_states[0] = 0.0;
    Plant_DW.DiscreteFIRFilter_states[1] = 0.0;
    Plant_DW.DiscreteFIRFilter_states[2] = 0.0;

    /* InitializeConditions for S-Function (sdsprandsrc2): '<S145>/Random Source1' */
    RandSrcCreateSeeds_32(9754U, Plant_DW.RandomSource1_SEED_DWORK, 3);
    RandSrcInitState_GZ(Plant_DW.RandomSource1_SEED_DWORK,
                        Plant_DW.RandomSource1_STATE_DWORK, 3);

    /* InitializeConditions for DiscreteFir: '<S148>/Discrete FIR Filter' */
    Plant_DW.DiscreteFIRFilter_states_i[0] = 0.0F;
    Plant_DW.DiscreteFIRFilter_states_i[1] = 0.0F;
    Plant_DW.DiscreteFIRFilter_states_i[2] = 0.0F;

    /* End of SystemInitialize for SubSystem: '<S7>/Sensor_GPS' */

    /* SystemInitialize for Atomic SubSystem: '<S7>/Sensor_IMU' */
    /* InitializeConditions for DiscreteIntegrator: '<S172>/Discrete-Time Integrator5' */
    Plant_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

    /* InitializeConditions for S-Function (sdsprandsrc2): '<S163>/Random Source' */
    RandSrcCreateSeeds_32(90579U, Plant_DW.RandomSource_SEED_DWORK_h, 3);
    RandSrcInitState_GZ(Plant_DW.RandomSource_SEED_DWORK_h,
                        Plant_DW.RandomSource_STATE_DWORK_f, 3);

    /* InitializeConditions for S-Function (sdsprandsrc2): '<S174>/Random Source' */
    RandSrcCreateSeeds_32(81472U, Plant_DW.RandomSource_SEED_DWORK_e, 3);
    RandSrcInitState_GZ(Plant_DW.RandomSource_SEED_DWORK_e,
                        Plant_DW.RandomSource_STATE_DWORK_p, 3);

    /* InitializeConditions for DiscreteIntegrator: '<S161>/Discrete-Time Integrator5' */
    Plant_DW.DiscreteTimeIntegrator5_IC_LO_g = 1U;

    /* End of SystemInitialize for SubSystem: '<S7>/Sensor_IMU' */

    /* SystemInitialize for Atomic SubSystem: '<S7>/Sensor_MAG' */
    /* InitializeConditions for S-Function (sdsprandsrc2): '<S185>/Random Source' */
    RandSrcCreateSeeds_32(12698U, Plant_DW.RandomSource_SEED_DWORK, 3);
    RandSrcInitState_GZ(Plant_DW.RandomSource_SEED_DWORK,
                        Plant_DW.RandomSource_STATE_DWORK, 3);

    /* End of SystemInitialize for SubSystem: '<S7>/Sensor_MAG' */
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
