/*
 * File: Plant.c
 *
 * Code generated for Simulink model 'Plant'.
 *
 * Model version                  : 1.127
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Dec 22 16:53:37 2025
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
struct_AjtFzZRX3GJyUtRZj0A4oG PLANT_EXPORT = {
  2U,

  { 86, 84, 79, 76, 32, 118, 49, 46, 48, 46, 48, 0 }
} ;                                    /* Variable: PLANT_EXPORT
                                        * Referenced by:
                                        *   '<S57>/dt'
                                        *   '<S126>/dt'
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

  /* S-Function (sdsprandsrc2): '<S140>/Random Source' */
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

  /* End of S-Function (sdsprandsrc2): '<S140>/Random Source' */
}

void RandSrcInitState_GZ(const uint32_T seed[], uint32_T state[], int32_T nChans)
{
  int32_T i;
  int32_T tmp;

  /* InitializeConditions for S-Function (sdsprandsrc2): '<S140>/Random Source' */
  /* RandSrcInitState_GZ */
  for (i = 0; i < nChans; i++) {
    tmp = i << 1;
    state[tmp] = 362436069U;
    state[tmp + 1] = seed[i] == 0U ? 521288629U : seed[i];
  }

  /* End of InitializeConditions for S-Function (sdsprandsrc2): '<S140>/Random Source' */
}

void RandSrcInitState_U_32(const uint32_T seed[], real32_T state[], int32_T
  nChans)
{
  int32_T i;
  uint32_T j;
  int32_T k;
  int32_T n;
  real32_T d;

  /* InitializeConditions for S-Function (sdsprandsrc2): '<S149>/Random Source' */
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

  /* End of InitializeConditions for S-Function (sdsprandsrc2): '<S149>/Random Source' */
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

  /* InitializeConditions for S-Function (sdsprandsrc2): '<S149>/Random Source' */
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

  /* End of InitializeConditions for S-Function (sdsprandsrc2): '<S149>/Random Source' */
}

void RandSrcCreateSeeds_32(uint32_T initSeed, uint32_T seedArray[], int32_T
  numSeeds)
{
  real32_T state[35];
  real32_T tmp;
  real32_T min;
  real32_T max;
  int32_T i;

  /* InitializeConditions for S-Function (sdsprandsrc2): '<S149>/Random Source' */
  /* RandSrcCreateSeeds_32 */
  min = 0.0F;
  max = 1.0F;
  RandSrcInitState_U_32(&initSeed, state, 1);
  for (i = 0; i < numSeeds; i++) {
    RandSrc_U_R(&tmp, &min, 1, &max, 1, state, 1, 1);
    seedArray[i] = (uint32_T)(tmp * 2.14748365E+9F);
  }

  /* End of InitializeConditions for S-Function (sdsprandsrc2): '<S149>/Random Source' */
}

/* Model step function */
void Plant_step(void)
{
  real32_T rtb_Plant_States_vel_y_O;
  real32_T rtb_Plant_States_vel_z_O;
  real32_T rtb_Multiply5_j[3];
  real32_T rtb_Gain_kz;
  real32_T rtb_Add_ps;
  real32_T rtb_MathFunction1_k;
  real_T rtb_TrigonometricFunction2;
  real_T rtb_SumofElements;
  real_T rtb_SumofElements1;
  real_T rtb_Cnr;
  real_T rtb_Cm;
  real_T rtb_Cl_zA;
  real_T rtb_Cl_yA;
  real_T rtb_Cl_xA;
  real32_T rtb_Saturation;
  real_T rtb_Divide2[3];
  real_T rtb_Add_d[6];
  real_T rtb_q1[6];
  real_T rtb_Sum1[6];
  real32_T rtb_DataTypeConversion4[6];
  real32_T rtb_Sum_mj[3];
  real32_T rtb_Sum_jq[3];
  real32_T rtb_Add_hg[3];
  real32_T rtb_Square_o5[3];
  real32_T rtb_Sum_i[3];
  real32_T rtb_VectorConcatenate_f[9];
  real32_T rtb_MathFunction[3];
  real32_T rtb_Divide_g[4];
  real32_T rtb_MatrixConcatenate4[16];
  real32_T rtb_Sum_ok[3];
  real32_T rtb_MatrixConcatenate1[9];
  AirSpeed_Bus rtb_BusAssignment_f;
  Barometer_Bus rtb_BusAssignment_c;
  GPS_uBlox_Bus rtb_BusAssignment_e;
  real32_T rtb_VectorConcatenate_n[9];
  MAG_Bus rtb_BusAssignment_j;
  real32_T rtb_RandomSource[3];
  real32_T rtb_Sum1_a[3];
  real32_T rtb_Square_b[3];
  real32_T rtb_RandomSource1[3];
  real_T rtb_DataTypeConversion2[2];
  real32_T rtb_RandomSource_l_tmp[3];
  int32_T i;
  real_T rtb_CD_0[6];
  real32_T rtb_MatrixConcatenate4_0[4];
  real32_T rtb_Square_l;
  real32_T rtb_Divide_ld;
  real32_T rtb_Multiply4;
  boolean_T rtb_Compare_h_idx_3;
  real32_T rtb_Divide_k_idx_2;
  boolean_T rtb_Compare_h_idx_2;
  real32_T rtb_Divide_k_idx_1;
  boolean_T rtb_Compare_h_idx_1;
  real32_T rtb_Divide_k_idx_0;
  boolean_T rtb_Compare_h_idx_0;
  real_T rtb_Divide_e_idx_1;
  real32_T rtb_DiscreteTimeIntegrator_idx_;
  real32_T rtb_DiscreteTimeIntegrator_id_0;
  real32_T rtb_DiscreteTimeIntegrator_id_1;
  real32_T rtb_Multiply4_idx_1;
  real32_T rtb_Multiply_g2_idx_2;
  real32_T rtb_Multiply_g2_idx_1;
  int32_T rtb_Saturation1_idx_1;
  uint16_T tmp;
  real32_T rtb_Multiply5_c;
  real32_T rtb_Add_j_tmp;
  real32_T tmp_0;
  real32_T rtb_Add_j_tmp_0;
  real32_T rtb_Add_j_tmp_1;
  real32_T rtb_Add_j_tmp_2;
  real32_T rtb_Gain_e_tmp;
  real32_T rtb_Gain_e_tmp_0;
  real32_T rtb_Gain_e_tmp_1;
  real32_T rtb_Add_j_tmp_3;
  real32_T rtb_Add_j_tmp_4;

  /* Delay: '<Root>/Delay' */
  rtb_DiscreteTimeIntegrator_idx_ = Plant_Y.Plant_States.vel_x_O;
  rtb_Plant_States_vel_y_O = Plant_Y.Plant_States.vel_y_O;
  rtb_Plant_States_vel_z_O = Plant_Y.Plant_States.vel_z_O;
  for (i = 0; i < 9; i++) {
    rtb_VectorConcatenate_n[i] = Plant_Y.Extended_States.M_BO[i];
  }

  /* Outputs for Atomic SubSystem: '<Root>/Actuators' */
  for (i = 0; i < 3; i++) {
    /* Product: '<S11>/Multiply' */
    rtb_Multiply5_c = rtb_VectorConcatenate_n[i + 6] * rtb_Plant_States_vel_z_O
      + (rtb_VectorConcatenate_n[i + 3] * rtb_Plant_States_vel_y_O +
         rtb_VectorConcatenate_n[i] * rtb_DiscreteTimeIntegrator_idx_);

    /* Math: '<S56>/Square' */
    rtb_Square_b[i] = rtb_Multiply5_c * rtb_Multiply5_c;

    /* Product: '<S11>/Multiply' */
    rtb_Multiply5_j[i] = rtb_Multiply5_c;
  }

  /* Product: '<S55>/Divide' incorporates:
   *  Saturate: '<S55>/Saturation'
   *  Sqrt: '<S56>/Sqrt'
   *  Sum: '<S56>/Sum of Elements'
   */
  rtb_Add_ps = rtb_Multiply5_j[1] / fmaxf(sqrtf((rtb_Square_b[0] + rtb_Square_b
    [1]) + rtb_Square_b[2]), 0.1F);

  /* DataTypeConversion: '<S7>/Data Type Conversion2' incorporates:
   *  Product: '<S54>/Divide'
   *  Saturate: '<S54>/Saturation'
   *  Trigonometry: '<S54>/Atan'
   */
  rtb_DataTypeConversion2[0] = atanf(rtb_Multiply5_j[2] / fmaxf(rtb_Multiply5_j
    [0], 0.1F));

  /* Trigonometry: '<S55>/Asin' */
  if (rtb_Add_ps > 1.0F) {
    rtb_Add_ps = 1.0F;
  } else {
    if (rtb_Add_ps < -1.0F) {
      rtb_Add_ps = -1.0F;
    }
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion2' incorporates:
   *  Trigonometry: '<S55>/Asin'
   */
  rtb_DataTypeConversion2[1] = asinf(rtb_Add_ps);

  /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
   *  Bias: '<S19>/Bias'
   *  DataTypeConversion: '<S19>/Data Type Conversion'
   *  Gain: '<S19>/Gain2'
   *  Inport: '<Root>/Control_Out'
   */
  rtb_Divide_e_idx_1 = ((real32_T)Plant_U.Control_Out.actuator_cmd[7] + -1500.0F)
    * 0.0010471975F;

  /* Gain: '<S26>/Gain2' incorporates:
   *  Bias: '<S18>/Bias'
   *  DataTypeConversion: '<S18>/Data Type Conversion'
   *  DataTypeConversion: '<S7>/Data Type Conversion'
   *  Gain: '<S18>/Gain2'
   *  Inport: '<Root>/Control_Out'
   */
  rtb_TrigonometricFunction2 = -(real_T)(((real32_T)
    Plant_U.Control_Out.actuator_cmd[5] + -1500.0F) * 0.0010471975F);

  /* Lookup2D: '<S26>/CD' */
  rtb_SumofElements = rt_Lookup2D_Normal(Plant_ConstP.pooled5, 7,
    Plant_ConstP.pooled6, 6, Plant_ConstP.CD_Table, rtb_TrigonometricFunction2,
    rtb_DataTypeConversion2[0]);

  /* Lookup2D: '<S26>/CY' */
  /*
   * About '<S26>/CY':
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

  /* Sum: '<S21>/Sum1' incorporates:
   *  Lookup2D: '<S26>/Cl'
   */
  rtb_Sum1[3] = rt_Lookup2D_Normal(Plant_ConstP.pooled5, 7, Plant_ConstP.pooled6,
    6, Plant_ConstP.Cl_Table, rtb_TrigonometricFunction2,
    rtb_DataTypeConversion2[0]);

  /* Lookup2D: '<S26>/Cn' */
  rtb_TrigonometricFunction2 = rt_Lookup2D_Normal(Plant_ConstP.pooled5, 7,
    Plant_ConstP.pooled6, 6, Plant_ConstP.Cn_Table, rtb_TrigonometricFunction2,
    rtb_DataTypeConversion2[0]);

  /* Lookup2D: '<S27>/CD' incorporates:
   *  Gain: '<S27>/Gain1'
   */
  rtb_Cm = rt_Lookup2D_Normal(Plant_ConstP.pooled5, 7, Plant_ConstP.pooled6, 6,
    Plant_ConstP.CD_Table_e, -rtb_Divide_e_idx_1, rtb_DataTypeConversion2[0]);

  /* Sum: '<S21>/Sum1' incorporates:
   *  Gain: '<S27>/Gain1'
   *  Lookup2D: '<S27>/CL'
   */
  rtb_Sum1[1] = rt_Lookup2D_Normal(Plant_ConstP.pooled5, 7, Plant_ConstP.pooled6,
    6, Plant_ConstP.CL_Table, -rtb_Divide_e_idx_1, rtb_DataTypeConversion2[0]);

  /* Lookup2D: '<S27>/Cm' incorporates:
   *  Gain: '<S27>/Gain1'
   */
  rtb_Cnr = rt_Lookup2D_Normal(Plant_ConstP.pooled5, 7, Plant_ConstP.pooled6, 6,
    Plant_ConstP.Cm_Table, -rtb_Divide_e_idx_1, rtb_DataTypeConversion2[0]);

  /* Gain: '<S28>/Gain' incorporates:
   *  Bias: '<S20>/Bias'
   *  DataTypeConversion: '<S20>/Data Type Conversion'
   *  DataTypeConversion: '<S7>/Data Type Conversion'
   *  Gain: '<S20>/Gain2'
   *  Inport: '<Root>/Control_Out'
   */
  rtb_Divide_e_idx_1 = -(real_T)(((real32_T)Plant_U.Control_Out.actuator_cmd[8]
    + -1500.0F) * 0.0010471975F);

  /* Lookup2D: '<S28>/CD_dr' */
  rtb_Cl_zA = rt_Lookup2D_Normal(Plant_ConstP.pooled8, 9, Plant_ConstP.pooled6,
    6, Plant_ConstP.CD_dr_Table, rtb_Divide_e_idx_1, rtb_DataTypeConversion2[0]);

  /* Lookup2D: '<S28>/CY_dr' */
  rtb_Cl_yA = rt_Lookup2D_Normal(Plant_ConstP.pooled8, 9, Plant_ConstP.pooled6,
    6, Plant_ConstP.CY_dr_Table, rtb_Divide_e_idx_1, rtb_DataTypeConversion2[0]);

  /* Lookup2D: '<S28>/Cm_dr' */
  /*
   * About '<S28>/Cm_dr':
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

  /* Lookup2D: '<S28>/Cn_dr' */
  rtb_Divide_e_idx_1 = rt_Lookup2D_Normal(Plant_ConstP.pooled8, 9,
    Plant_ConstP.pooled6, 6, Plant_ConstP.Cn_dr_Table, rtb_Divide_e_idx_1,
    rtb_DataTypeConversion2[0]);

  /* Sum: '<S21>/Sum1' */
  rtb_Sum1[0] = (rtb_SumofElements + rtb_Cm) + rtb_Cl_zA;
  rtb_Sum1[2] = rtb_SumofElements1 + rtb_Cl_yA;
  rtb_Sum1[4] = rtb_Cnr + rtb_Cl_xA;
  rtb_Sum1[5] = rtb_TrigonometricFunction2 + rtb_Divide_e_idx_1;

  /* Lookup2D: '<S22>/CY_basic' */
  rtb_Cl_xA = rt_Lookup2D_Normal(Plant_ConstP.pooled9, 7, Plant_ConstP.pooled6,
    6, Plant_ConstP.CY_basic_Table, rtb_DataTypeConversion2[1],
    rtb_DataTypeConversion2[0]);

  /* Lookup2D: '<S22>/Cn_basic' */
  /*
   * About '<S22>/Cn_basic':
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

  /* Lookup: '<S22>/CL_basic' */
  rtb_Divide_e_idx_1 = rt_Lookup(Plant_ConstP.pooled10, 23,
    rtb_DataTypeConversion2[0], Plant_ConstP.CL_basic_YData);

  /* Sum: '<S22>/Sum' incorporates:
   *  Lookup2D: '<S22>/CL_beta'
   */
  rtb_Divide_e_idx_1 += rt_Lookup2D_Normal(Plant_ConstP.pooled9, 7,
    Plant_ConstP.pooled6, 6, Plant_ConstP.CL_beta_Table,
    rtb_DataTypeConversion2[1], rtb_DataTypeConversion2[0]);

  /* Sum: '<S22>/Sum1' incorporates:
   *  Lookup: '<S22>/CD_basic'
   *  Lookup2D: '<S22>/CD_beta'
   */
  rtb_Cl_yA = rt_Lookup(Plant_ConstP.pooled10, 23, rtb_DataTypeConversion2[0],
                        Plant_ConstP.CD_basic_YData) + rt_Lookup2D_Normal
    (Plant_ConstP.pooled9, 7, Plant_ConstP.pooled6, 6,
     Plant_ConstP.CD_beta_Table, rtb_DataTypeConversion2[1],
     rtb_DataTypeConversion2[0]);

  /* Sum: '<S22>/Sum2' incorporates:
   *  Lookup: '<S22>/Cm_basic'
   *  Lookup2D: '<S22>/Cm_beta'
   */
  rtb_Cm = rt_Lookup(Plant_ConstP.pooled10, 23, rtb_DataTypeConversion2[0],
                     Plant_ConstP.Cm_basic_YData) + rt_Lookup2D_Normal
    (Plant_ConstP.pooled9, 7, Plant_ConstP.pooled6, 6,
     Plant_ConstP.Cm_beta_Table, rtb_DataTypeConversion2[1],
     rtb_DataTypeConversion2[0]);

  /* Saturate: '<S25>/Saturation' */
  if (rtb_DataTypeConversion2[0] > 0.26179938779914941) {
    rtb_Cnr = 0.26179938779914941;
  } else if (rtb_DataTypeConversion2[0] < -0.26179938779914941) {
    rtb_Cnr = -0.26179938779914941;
  } else {
    rtb_Cnr = rtb_DataTypeConversion2[0];
  }

  /* End of Saturate: '<S25>/Saturation' */

  /* Lookup: '<S29>/Clp' */
  rtb_TrigonometricFunction2 = rt_Lookup(Plant_ConstP.pooled11, 5, rtb_Cnr,
    Plant_ConstP.Clp_YData);

  /* Saturate: '<S11>/Saturation' */
  if (rtb_Multiply5_j[0] > 1000.0F) {
    rtb_Saturation = 1000.0F;
  } else if (rtb_Multiply5_j[0] < 0.0F) {
    rtb_Saturation = 0.0F;
  } else {
    rtb_Saturation = rtb_Multiply5_j[0];
  }

  /* End of Saturate: '<S11>/Saturation' */

  /* Saturate: '<S17>/Saturation' incorporates:
   *  Gain: '<S17>/Gain'
   */
  rtb_Gain_kz = fmaxf(2.0F * rtb_Saturation, 0.1F);

  /* Product: '<S17>/Product1' incorporates:
   *  Constant: '<S17>/b'
   *  Delay: '<Root>/Delay'
   *  Product: '<S17>/Product2'
   */
  rtb_Add_j_tmp = 1.0F / rtb_Gain_kz * 2.3F;
  rtb_Add_ps = rtb_Add_j_tmp * Plant_Y.Plant_States.rot_x_B;

  /* Product: '<S17>/Product4' incorporates:
   *  Constant: '<S17>/c'
   *  Delay: '<Root>/Delay'
   */
  rtb_MathFunction1_k = 1.0F / rtb_Gain_kz * 0.32F *
    Plant_Y.Plant_States.rot_y_B;

  /* Product: '<S17>/Product2' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_Gain_kz = rtb_Add_j_tmp * Plant_Y.Plant_States.rot_z_B;

  /* Lookup: '<S29>/CYp' */
  rtb_SumofElements = rt_Lookup(Plant_ConstP.pooled11, 5, rtb_Cnr,
    Plant_ConstP.CYp_YData);

  /* Lookup: '<S29>/Cnp' */
  rtb_SumofElements1 = rt_Lookup(Plant_ConstP.pooled11, 5, rtb_Cnr,
    Plant_ConstP.Cnp_YData);

  /* Product: '<S25>/p1' incorporates:
   *  Constant: '<S29>/CDp'
   *  Constant: '<S29>/CLp'
   *  Constant: '<S29>/Cmp'
   *  DataTypeConversion: '<S7>/Data Type Conversion1'
   *  Lookup: '<S29>/CYp'
   *  Lookup: '<S29>/Cnp'
   */
  rtb_Add_d[0] = 0.0;
  rtb_Add_d[1] = 0.0;
  rtb_Add_d[2] = rtb_SumofElements * rtb_Add_ps;
  rtb_Add_d[3] = rtb_TrigonometricFunction2 * rtb_Add_ps;
  rtb_Add_d[4] = 0.0;
  rtb_Add_d[5] = rtb_SumofElements1 * rtb_Add_ps;

  /* Lookup: '<S30>/Cmq' */
  rtb_TrigonometricFunction2 = rt_Lookup(Plant_ConstP.pooled11, 5, rtb_Cnr,
    Plant_ConstP.Cmq_YData);

  /* Lookup: '<S30>/CLq' */
  rtb_SumofElements = rt_Lookup(Plant_ConstP.pooled11, 5, rtb_Cnr,
    Plant_ConstP.CLq_YData);

  /* Product: '<S25>/q1' incorporates:
   *  Constant: '<S30>/CDq'
   *  Constant: '<S30>/CYq'
   *  Constant: '<S30>/Clq'
   *  Constant: '<S30>/Cnq'
   *  DataTypeConversion: '<S7>/Data Type Conversion1'
   *  Lookup: '<S30>/CLq'
   */
  rtb_q1[0] = 0.0;
  rtb_q1[1] = rtb_SumofElements * rtb_MathFunction1_k;
  rtb_q1[2] = 0.0;
  rtb_q1[3] = 0.0;
  rtb_q1[4] = rtb_TrigonometricFunction2 * rtb_MathFunction1_k;
  rtb_q1[5] = 0.0;

  /* Lookup: '<S31>/CYr' */
  rtb_SumofElements1 = rt_Lookup(Plant_ConstP.pooled11, 5, rtb_Cnr,
    Plant_ConstP.CYr_YData);

  /* Lookup: '<S31>/Clr' */
  rtb_TrigonometricFunction2 = rt_Lookup(Plant_ConstP.pooled11, 5, rtb_Cnr,
    Plant_ConstP.Clr_YData);

  /* Lookup: '<S31>/Cnr' */
  rtb_Cnr = rt_Lookup(Plant_ConstP.pooled11, 5, rtb_Cnr, Plant_ConstP.Cnr_YData);

  /* Product: '<S25>/r1' incorporates:
   *  Constant: '<S31>/CDr'
   *  Constant: '<S31>/CLr'
   *  Constant: '<S31>/Cmr'
   *  DataTypeConversion: '<S7>/Data Type Conversion1'
   */
  rtb_CD_0[0] = 0.0;
  rtb_CD_0[1] = 0.0;
  rtb_CD_0[2] = rtb_SumofElements1 * rtb_Gain_kz;
  rtb_CD_0[3] = rtb_TrigonometricFunction2 * rtb_Gain_kz;
  rtb_CD_0[4] = 0.0;
  rtb_CD_0[5] = rtb_Cnr * rtb_Gain_kz;

  /* Sum: '<S25>/Add' */
  for (i = 0; i < 6; i++) {
    rtb_Add_d[i] = (rtb_Add_d[i] + rtb_q1[i]) + rtb_CD_0[i];
  }

  /* End of Sum: '<S25>/Add' */

  /* Switch: '<S23>/Switch' incorporates:
   *  Abs: '<S23>/Abs'
   *  Product: '<S23>/Multiply'
   *  Sum: '<S14>/Sum'
   */
  if (rtb_Saturation >= 10.0F) {
    /* Lookup2D: '<S22>/Cl_basic' */
    rtb_SumofElements = rt_Lookup2D_Normal(Plant_ConstP.pooled9, 7,
      Plant_ConstP.pooled6, 6, Plant_ConstP.Cl_basic_Table,
      rtb_DataTypeConversion2[1], rtb_DataTypeConversion2[0]);

    /* Sum: '<S14>/Sum' incorporates:
     *  Lookup2D: '<S22>/Cl_basic'
     */
    rtb_CD_0[0] = rtb_Cl_yA;
    rtb_CD_0[1] = rtb_Divide_e_idx_1;
    rtb_CD_0[2] = rtb_Cl_xA;
    rtb_CD_0[3] = rtb_SumofElements;
    rtb_CD_0[4] = rtb_Cm;
    rtb_CD_0[5] = rtb_Cl_zA;
    for (i = 0; i < 6; i++) {
      rtb_q1[i] = (rtb_CD_0[i] + rtb_Add_d[i]) + rtb_Sum1[i];
    }
  } else {
    /* Product: '<S23>/Divide' incorporates:
     *  Constant: '<S23>/Constant'
     */
    rtb_SumofElements1 = rtb_Saturation / 10.0;

    /* Math: '<S23>/Square' */
    rtb_SumofElements1 *= rtb_SumofElements1;

    /* Lookup2D: '<S22>/Cl_basic' */
    rtb_SumofElements = rt_Lookup2D_Normal(Plant_ConstP.pooled9, 7,
      Plant_ConstP.pooled6, 6, Plant_ConstP.Cl_basic_Table,
      rtb_DataTypeConversion2[1], rtb_DataTypeConversion2[0]);

    /* Sum: '<S14>/Sum' incorporates:
     *  Lookup2D: '<S22>/Cl_basic'
     */
    rtb_CD_0[0] = rtb_Cl_yA;
    rtb_CD_0[1] = rtb_Divide_e_idx_1;
    rtb_CD_0[2] = rtb_Cl_xA;
    rtb_CD_0[3] = rtb_SumofElements;
    rtb_CD_0[4] = rtb_Cm;
    rtb_CD_0[5] = rtb_Cl_zA;
    for (i = 0; i < 6; i++) {
      rtb_q1[i] = ((rtb_CD_0[i] + rtb_Add_d[i]) + rtb_Sum1[i]) *
        rtb_SumofElements1;
    }
  }

  /* End of Switch: '<S23>/Switch' */

  /* Fcn: '<S24>/Cl_xA' incorporates:
   *  Fcn: '<S24>/Cl_zA'
   */
  rtb_SumofElements1 = -rtb_q1[0] * cos(rtb_DataTypeConversion2[1]);
  rtb_SumofElements = sin(rtb_DataTypeConversion2[0]);
  rtb_Cm = cos(rtb_DataTypeConversion2[0]);
  rtb_Cl_xA = rtb_SumofElements1 * rtb_Cm + rtb_q1[1] * rtb_SumofElements;

  /* Fcn: '<S24>/Cl_zA' */
  rtb_Cl_zA = rtb_SumofElements1 * rtb_SumofElements - rtb_q1[1] * rtb_Cm;

  /* DataTypeConversion: '<S7>/Data Type Conversion4' incorporates:
   *  Fcn: '<S24>/Cl_yA'
   */
  rtb_DataTypeConversion4[0] = (real32_T)rtb_Cl_xA;
  rtb_DataTypeConversion4[3] = (real32_T)rtb_q1[3];
  rtb_DataTypeConversion4[4] = (real32_T)rtb_q1[4];
  rtb_DataTypeConversion4[5] = (real32_T)rtb_q1[5];
  rtb_DataTypeConversion4[1] = (real32_T)(-rtb_q1[0] * sin
    (rtb_DataTypeConversion2[1]) + rtb_q1[2]);
  rtb_DataTypeConversion4[2] = (real32_T)rtb_Cl_zA;

  /* Saturate: '<S42>/Saturation' incorporates:
   *  Inport: '<Root>/Control_Out'
   */
  if (Plant_U.Control_Out.actuator_cmd[0] > 2000) {
    tmp = 2000U;
  } else if (Plant_U.Control_Out.actuator_cmd[0] < 1000) {
    tmp = 1000U;
  } else {
    tmp = Plant_U.Control_Out.actuator_cmd[0];
  }

  /* Gain: '<S42>/Gain' incorporates:
   *  Sum: '<S42>/Subtract'
   */
  rtb_Divide_ld = ((real32_T)tmp - 1000.0F) * 0.000999987125F;

  /* RelationalOperator: '<S47>/Compare' incorporates:
   *  Constant: '<S47>/Constant'
   */
  rtb_Compare_h_idx_0 = (rtb_Divide_ld > 0.1F);

  /* Gain: '<S42>/Gain' incorporates:
   *  Constant: '<S46>/Constant1'
   *  Gain: '<S46>/Gain1'
   *  Sum: '<S46>/Add'
   */
  rtb_Divide_k_idx_0 = 718.078F * rtb_Divide_ld + 88.448F;

  /* Math: '<S48>/Square' incorporates:
   *  DiscreteIntegrator: '<S45>/Discrete-Time Integrator'
   *  Math: '<S50>/Square'
   */
  rtb_Multiply5_c = Plant_DW.DiscreteTimeIntegrator_DSTAT_ky[0] *
    Plant_DW.DiscreteTimeIntegrator_DSTAT_ky[0];

  /* Product: '<S48>/Multiply' incorporates:
   *  Constant: '<S48>/cT'
   */
  rtb_Add_ps = (real32_T)(rtb_Multiply5_c * 4.195E-5);

  /* Math: '<S48>/Square' */
  rtb_MathFunction1_k = rtb_Multiply5_c;

  /* Saturate: '<S42>/Saturation' incorporates:
   *  Inport: '<Root>/Control_Out'
   */
  if (Plant_U.Control_Out.actuator_cmd[1] > 2000) {
    tmp = 2000U;
  } else if (Plant_U.Control_Out.actuator_cmd[1] < 1000) {
    tmp = 1000U;
  } else {
    tmp = Plant_U.Control_Out.actuator_cmd[1];
  }

  /* Gain: '<S42>/Gain' incorporates:
   *  Sum: '<S42>/Subtract'
   */
  rtb_Divide_ld = ((real32_T)tmp - 1000.0F) * 0.000999987125F;

  /* RelationalOperator: '<S47>/Compare' incorporates:
   *  Constant: '<S47>/Constant'
   */
  rtb_Compare_h_idx_1 = (rtb_Divide_ld > 0.1F);

  /* Gain: '<S42>/Gain' incorporates:
   *  Constant: '<S46>/Constant1'
   *  Gain: '<S46>/Gain1'
   *  Sum: '<S46>/Add'
   */
  rtb_Divide_k_idx_1 = 718.078F * rtb_Divide_ld + 88.448F;

  /* Math: '<S48>/Square' incorporates:
   *  DiscreteIntegrator: '<S45>/Discrete-Time Integrator'
   *  Math: '<S50>/Square'
   */
  rtb_Multiply5_c = Plant_DW.DiscreteTimeIntegrator_DSTAT_ky[1] *
    Plant_DW.DiscreteTimeIntegrator_DSTAT_ky[1];

  /* Product: '<S48>/Multiply' incorporates:
   *  Constant: '<S48>/cT'
   */
  rtb_Multiply_g2_idx_1 = (real32_T)(rtb_Multiply5_c * 4.195E-5);

  /* Math: '<S48>/Square' */
  rtb_DiscreteTimeIntegrator_id_1 = rtb_Multiply5_c;

  /* Saturate: '<S42>/Saturation' incorporates:
   *  Inport: '<Root>/Control_Out'
   */
  if (Plant_U.Control_Out.actuator_cmd[2] > 2000) {
    tmp = 2000U;
  } else if (Plant_U.Control_Out.actuator_cmd[2] < 1000) {
    tmp = 1000U;
  } else {
    tmp = Plant_U.Control_Out.actuator_cmd[2];
  }

  /* Gain: '<S42>/Gain' incorporates:
   *  Sum: '<S42>/Subtract'
   */
  rtb_Divide_ld = ((real32_T)tmp - 1000.0F) * 0.000999987125F;

  /* RelationalOperator: '<S47>/Compare' incorporates:
   *  Constant: '<S47>/Constant'
   */
  rtb_Compare_h_idx_2 = (rtb_Divide_ld > 0.1F);

  /* Gain: '<S42>/Gain' incorporates:
   *  Constant: '<S46>/Constant1'
   *  Gain: '<S46>/Gain1'
   *  Sum: '<S46>/Add'
   */
  rtb_Divide_k_idx_2 = 718.078F * rtb_Divide_ld + 88.448F;

  /* Math: '<S48>/Square' incorporates:
   *  DiscreteIntegrator: '<S45>/Discrete-Time Integrator'
   *  Math: '<S50>/Square'
   */
  rtb_Multiply5_c = Plant_DW.DiscreteTimeIntegrator_DSTAT_ky[2] *
    Plant_DW.DiscreteTimeIntegrator_DSTAT_ky[2];

  /* Product: '<S48>/Multiply' incorporates:
   *  Constant: '<S48>/cT'
   */
  rtb_Multiply_g2_idx_2 = (real32_T)(rtb_Multiply5_c * 4.195E-5);

  /* Math: '<S48>/Square' */
  rtb_DiscreteTimeIntegrator_id_0 = rtb_Multiply5_c;

  /* Saturate: '<S42>/Saturation' incorporates:
   *  Inport: '<Root>/Control_Out'
   */
  if (Plant_U.Control_Out.actuator_cmd[3] > 2000) {
    tmp = 2000U;
  } else if (Plant_U.Control_Out.actuator_cmd[3] < 1000) {
    tmp = 1000U;
  } else {
    tmp = Plant_U.Control_Out.actuator_cmd[3];
  }

  /* Gain: '<S42>/Gain' incorporates:
   *  Sum: '<S42>/Subtract'
   */
  rtb_Divide_ld = ((real32_T)tmp - 1000.0F) * 0.000999987125F;

  /* RelationalOperator: '<S47>/Compare' incorporates:
   *  Constant: '<S47>/Constant'
   */
  rtb_Compare_h_idx_3 = (rtb_Divide_ld > 0.1F);

  /* Sum: '<S46>/Add' incorporates:
   *  Constant: '<S46>/Constant1'
   *  Gain: '<S46>/Gain1'
   */
  rtb_Divide_ld = 718.078F * rtb_Divide_ld + 88.448F;

  /* Math: '<S48>/Square' incorporates:
   *  DiscreteIntegrator: '<S45>/Discrete-Time Integrator'
   *  Math: '<S50>/Square'
   */
  rtb_Multiply5_c = Plant_DW.DiscreteTimeIntegrator_DSTAT_ky[3] *
    Plant_DW.DiscreteTimeIntegrator_DSTAT_ky[3];

  /* Sum: '<S49>/Add' incorporates:
   *  DiscreteIntegrator: '<S45>/Discrete-Time Integrator'
   */
  rtb_Gain_kz = ((Plant_DW.DiscreteTimeIntegrator_DSTAT_ky[2] -
                  Plant_DW.DiscreteTimeIntegrator_DSTAT_ky[0]) -
                 Plant_DW.DiscreteTimeIntegrator_DSTAT_ky[1]) +
    Plant_DW.DiscreteTimeIntegrator_DSTAT_ky[3];

  /* Product: '<S52>/Multiply' */
  rtb_Add_hg[0] = 0.0F;

  /* Product: '<S52>/Multiply1' incorporates:
   *  Delay: '<Root>/Delay'
   *  Product: '<S49>/Multiply'
   */
  rtb_Add_hg[1] = rtb_Gain_kz * Plant_Y.Plant_States.rot_x_B * 0.0001287F;

  /* Product: '<S52>/Multiply2' */
  rtb_Add_hg[2] = 0.0F;

  /* Product: '<S53>/Multiply3' incorporates:
   *  Delay: '<Root>/Delay'
   *  Product: '<S49>/Multiply'
   */
  rtb_Square_o5[0] = rtb_Gain_kz * Plant_Y.Plant_States.rot_y_B * 0.0001287F;

  /* Product: '<S53>/Multiply4' */
  rtb_Square_o5[1] = 0.0F;

  /* Product: '<S53>/Multiply5' */
  rtb_Square_o5[2] = 0.0F;

  /* Gain: '<S15>/reference area' incorporates:
   *  Gain: '<S16>/Gain'
   *  Math: '<S16>/Square'
   */
  rtb_Gain_kz = rtb_Saturation * rtb_Saturation * 0.645F * 0.736F;
  for (i = 0; i < 3; i++) {
    /* Sum: '<S44>/Sum' incorporates:
     *  Constant: '<S50>/X_Frame_CM'
     *  Math: '<S50>/Square'
     *  Product: '<S50>/Multiply'
     *  Sum: '<S51>/Sum'
     */
    rtb_Sum_i[i] = (((Plant_ConstP.X_Frame_CM_Value[i + 3] *
                      rtb_DiscreteTimeIntegrator_id_1 +
                      Plant_ConstP.X_Frame_CM_Value[i] * rtb_MathFunction1_k) +
                     Plant_ConstP.X_Frame_CM_Value[i + 6] *
                     rtb_DiscreteTimeIntegrator_id_0) +
                    Plant_ConstP.X_Frame_CM_Value[i + 9] * rtb_Multiply5_c) +
      (rtb_Add_hg[i] - rtb_Square_o5[i]);

    /* Product: '<S15>/Product' */
    rtb_Sum_mj[i] = rtb_Gain_kz * rtb_DataTypeConversion4[i];
  }

  /* Sum: '<S15>/Sum1' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion4'
   *  Gain: '<S15>/reference length'
   *  Product: '<S15>/Product3'
   *  Product: '<S34>/Multiply'
   *  Product: '<S34>/Multiply1'
   *  Product: '<S34>/Multiply2'
   *  Product: '<S35>/Multiply3'
   *  Product: '<S35>/Multiply4'
   *  Product: '<S35>/Multiply5'
   *  Sum: '<S33>/Sum'
   */
  rtb_MathFunction1_k = 2.3F * rtb_Gain_kz * (real32_T)rtb_q1[3] + (rtb_Sum_mj[1]
    * Plant_ConstB.Sum_k[2] - rtb_Sum_mj[2] * Plant_ConstB.Sum_k[1]);
  rtb_DiscreteTimeIntegrator_id_1 = 0.32F * rtb_Gain_kz * (real32_T)rtb_q1[4] +
    (rtb_Sum_mj[2] * Plant_ConstB.Sum_k[0] - rtb_Sum_mj[0] * Plant_ConstB.Sum_k
     [2]);
  rtb_DiscreteTimeIntegrator_id_0 = 2.3F * rtb_Gain_kz * (real32_T)rtb_q1[5] +
    (rtb_Sum_mj[0] * Plant_ConstB.Sum_k[1] - rtb_Sum_mj[1] * Plant_ConstB.Sum_k
     [0]);

  /* Update for DiscreteIntegrator: '<S45>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S45>/Gain'
   *  Product: '<S46>/Multiply'
   *  Saturate: '<S46>/Saturation1'
   *  Sum: '<S45>/Subtract'
   */
  Plant_DW.DiscreteTimeIntegrator_DSTAT_ky[0] += ((rtb_Compare_h_idx_0 ?
    rtb_Divide_k_idx_0 : 0.0F) - Plant_DW.DiscreteTimeIntegrator_DSTAT_ky[0]) *
    50.0F * 0.002F;
  Plant_DW.DiscreteTimeIntegrator_DSTAT_ky[1] += ((rtb_Compare_h_idx_1 ?
    rtb_Divide_k_idx_1 : 0.0F) - Plant_DW.DiscreteTimeIntegrator_DSTAT_ky[1]) *
    50.0F * 0.002F;
  Plant_DW.DiscreteTimeIntegrator_DSTAT_ky[2] += ((rtb_Compare_h_idx_2 ?
    rtb_Divide_k_idx_2 : 0.0F) - Plant_DW.DiscreteTimeIntegrator_DSTAT_ky[2]) *
    50.0F * 0.002F;
  Plant_DW.DiscreteTimeIntegrator_DSTAT_ky[3] += ((rtb_Compare_h_idx_3 ?
    rtb_Divide_ld : 0.0F) - Plant_DW.DiscreteTimeIntegrator_DSTAT_ky[3]) * 50.0F
    * 0.002F;

  /* Sum: '<S1>/Sum1' incorporates:
   *  Constant: '<S41>/cT'
   *  Constant: '<S48>/cT'
   *  DiscreteIntegrator: '<S38>/Discrete-Time Integrator'
   *  Gain: '<S43>/Gain'
   *  Math: '<S41>/Square'
   *  Product: '<S41>/Multiply'
   *  Product: '<S48>/Multiply'
   *  Sum: '<S43>/Sum of Elements'
   */
  rtb_Sum1_a[0] = (real32_T)(Plant_DW.DiscreteTimeIntegrator_DSTATE_p *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_p * 4.951E-5) + rtb_Sum_mj[0];
  rtb_Sum1_a[1] = rtb_Sum_mj[1];
  rtb_Sum1_a[2] = -(((rtb_Add_ps + rtb_Multiply_g2_idx_1) +
                     rtb_Multiply_g2_idx_2) + (real32_T)(rtb_Multiply5_c *
    4.195E-5)) + rtb_Sum_mj[2];

  /* Saturate: '<S36>/Saturation' incorporates:
   *  Inport: '<Root>/Control_Out'
   */
  if (Plant_U.Control_Out.actuator_cmd[4] > 2000) {
    tmp = 2000U;
  } else if (Plant_U.Control_Out.actuator_cmd[4] < 1000) {
    tmp = 1000U;
  } else {
    tmp = Plant_U.Control_Out.actuator_cmd[4];
  }

  /* End of Saturate: '<S36>/Saturation' */

  /* Gain: '<S36>/Gain' incorporates:
   *  Sum: '<S36>/Subtract'
   */
  rtb_Add_ps = ((real32_T)tmp - 1000.0F) * 0.000999987125F;

  /* RelationalOperator: '<S40>/Compare' incorporates:
   *  Constant: '<S40>/Constant'
   */
  rtb_Compare_h_idx_0 = (rtb_Add_ps > 0.1F);

  /* Sum: '<S39>/Add' incorporates:
   *  Constant: '<S39>/Constant1'
   *  Gain: '<S39>/Gain1'
   */
  rtb_Add_ps = 718.078F * rtb_Add_ps + 88.448F;

  /* Update for DiscreteIntegrator: '<S38>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S38>/Gain'
   *  Product: '<S39>/Multiply'
   *  Sum: '<S38>/Subtract'
   */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_p += ((rtb_Compare_h_idx_0 ? rtb_Add_ps
    : 0.0F) - Plant_DW.DiscreteTimeIntegrator_DSTATE_p) * 50.0F * 0.002F;

  /* End of Outputs for SubSystem: '<Root>/Actuators' */

  /* Outputs for Atomic SubSystem: '<Root>/Environment' */
  /* Trigonometry: '<S78>/Trigonometric Function1' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S77>/Gain'
   *  Trigonometry: '<S78>/Trigonometric Function3'
   */
  rtb_Divide_k_idx_1 = arm_cos_f32(-Plant_Y.Plant_States.psi);
  rtb_VectorConcatenate_f[0] = rtb_Divide_k_idx_1;

  /* Trigonometry: '<S78>/Trigonometric Function' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S77>/Gain'
   *  Trigonometry: '<S78>/Trigonometric Function2'
   */
  rtb_Divide_ld = arm_sin_f32(-Plant_Y.Plant_States.psi);
  rtb_VectorConcatenate_f[1] = rtb_Divide_ld;

  /* SignalConversion: '<S78>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S78>/Constant3'
   */
  rtb_VectorConcatenate_f[2] = 0.0F;

  /* Gain: '<S78>/Gain' */
  rtb_VectorConcatenate_f[3] = -rtb_Divide_ld;

  /* Trigonometry: '<S78>/Trigonometric Function3' */
  rtb_VectorConcatenate_f[4] = rtb_Divide_k_idx_1;

  /* SignalConversion: '<S78>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S78>/Constant4'
   */
  rtb_VectorConcatenate_f[5] = 0.0F;

  /* SignalConversion: '<S78>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_f[6] = Plant_ConstB.VectorConcatenate3_h[0];

  /* Sum: '<S68>/Sum' incorporates:
   *  Inport: '<Root>/Environment_Info'
   */
  rtb_Divide_k_idx_1 = Plant_U.Environment_Info.hit_point[0] -
    Plant_U.Environment_Info.hit_location[0];

  /* SignalConversion: '<S78>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_f[7] = Plant_ConstB.VectorConcatenate3_h[1];

  /* Sum: '<S68>/Sum' incorporates:
   *  Inport: '<Root>/Environment_Info'
   */
  rtb_Multiply5_c = Plant_U.Environment_Info.hit_point[1] -
    Plant_U.Environment_Info.hit_location[1];

  /* SignalConversion: '<S78>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_f[8] = Plant_ConstB.VectorConcatenate3_h[2];

  /* Sum: '<S68>/Sum' incorporates:
   *  Inport: '<Root>/Environment_Info'
   */
  rtb_Divide_k_idx_2 = Plant_U.Environment_Info.hit_point[2] -
    Plant_U.Environment_Info.hit_location[2];
  for (i = 0; i < 3; i++) {
    /* Product: '<S68>/Multiply2' */
    rtb_Divide_ld = rtb_VectorConcatenate_n[i + 6] * rtb_Divide_k_idx_2 +
      (rtb_VectorConcatenate_n[i + 3] * rtb_Multiply5_c +
       rtb_VectorConcatenate_n[i] * rtb_Divide_k_idx_1);

    /* Math: '<S83>/Math Function' */
    rtb_MathFunction[i] = rtb_Divide_ld * rtb_Divide_ld;

    /* Product: '<S68>/Multiply2' */
    rtb_Square_b[i] = rtb_Divide_ld;
  }

  /* Sum: '<S83>/Sum of Elements' */
  rtb_Gain_kz = (rtb_MathFunction[0] + rtb_MathFunction[1]) + rtb_MathFunction[2];

  /* Math: '<S83>/Math Function1' incorporates:
   *  Sum: '<S83>/Sum of Elements'
   *
   * About '<S83>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Gain_kz < 0.0F) {
    rtb_Gain_kz = -sqrtf(fabsf(rtb_Gain_kz));
  } else {
    rtb_Gain_kz = sqrtf(rtb_Gain_kz);
  }

  /* End of Math: '<S83>/Math Function1' */

  /* Switch: '<S83>/Switch' incorporates:
   *  Constant: '<S83>/Constant'
   *  Product: '<S83>/Product'
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

  /* End of Switch: '<S83>/Switch' */
  for (i = 0; i < 3; i++) {
    /* Product: '<S83>/Divide' */
    rtb_Add_hg[i] = rtb_Divide_g[i] / rtb_Divide_g[3];

    /* Product: '<S68>/Multiply1' */
    rtb_Sum_jq[i] = rtb_VectorConcatenate_n[i + 6] * rtb_Plant_States_vel_z_O +
      (rtb_VectorConcatenate_n[i + 3] * rtb_Plant_States_vel_y_O +
       rtb_VectorConcatenate_n[i] * rtb_DiscreteTimeIntegrator_idx_);
  }

  /* Product: '<S89>/Multiply' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_Square_b[0] = Plant_Y.Plant_States.rot_y_B * rtb_Add_hg[2];

  /* Product: '<S89>/Multiply1' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_Square_b[1] = Plant_Y.Plant_States.rot_z_B * rtb_Add_hg[0];

  /* Product: '<S89>/Multiply2' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_Square_b[2] = Plant_Y.Plant_States.rot_x_B * rtb_Add_hg[1];

  /* Product: '<S90>/Multiply3' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_Multiply5_j[0] = Plant_Y.Plant_States.rot_z_B * rtb_Add_hg[1];

  /* Product: '<S90>/Multiply4' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_Multiply5_j[1] = Plant_Y.Plant_States.rot_x_B * rtb_Add_hg[2];

  /* Product: '<S90>/Multiply5' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_Multiply5_j[2] = Plant_Y.Plant_States.rot_y_B * rtb_Add_hg[0];

  /* DotProduct: '<S81>/Dot Product' */
  rtb_Divide_ld = 0.0F;
  for (i = 0; i < 3; i++) {
    /* Sum: '<S82>/Sum1' incorporates:
     *  Sum: '<S86>/Sum'
     */
    rtb_Divide_k_idx_1 = (rtb_Square_b[i] - rtb_Multiply5_j[i]) + rtb_Sum_jq[i];

    /* Product: '<S68>/Multiply' incorporates:
     *  Inport: '<Root>/Environment_Info'
     */
    rtb_Multiply5_c = rtb_VectorConcatenate_n[i + 6] *
      Plant_U.Environment_Info.hit_normal[2] + (rtb_VectorConcatenate_n[i + 3] *
      Plant_U.Environment_Info.hit_normal[1] + rtb_VectorConcatenate_n[i] *
      Plant_U.Environment_Info.hit_normal[0]);

    /* DotProduct: '<S81>/Dot Product' */
    rtb_Divide_ld += rtb_Divide_k_idx_1 * rtb_Multiply5_c;

    /* Sum: '<S82>/Sum1' */
    rtb_Square_b[i] = rtb_Divide_k_idx_1;

    /* Product: '<S68>/Multiply' incorporates:
     *  Product: '<S74>/Multiply'
     */
    rtb_RandomSource_l_tmp[i] = rtb_Multiply5_c;
  }

  /* Sum: '<S81>/Sum' incorporates:
   *  DotProduct: '<S81>/Dot Product'
   *  Product: '<S68>/Multiply'
   *  Product: '<S81>/Multiply'
   */
  rtb_Divide_k_idx_2 = rtb_Square_b[0] - rtb_Divide_ld * rtb_RandomSource_l_tmp
    [0];

  /* Math: '<S85>/Math Function' */
  rtb_Multiply5_j[0] = rtb_Divide_k_idx_2 * rtb_Divide_k_idx_2;

  /* Sum: '<S81>/Sum' incorporates:
   *  DotProduct: '<S81>/Dot Product'
   *  Product: '<S68>/Multiply'
   *  Product: '<S81>/Multiply'
   */
  rtb_MathFunction[0] = rtb_Divide_k_idx_2;
  rtb_Divide_k_idx_2 = rtb_Square_b[1] - rtb_Divide_ld * rtb_RandomSource_l_tmp
    [1];

  /* Math: '<S85>/Math Function' */
  rtb_Multiply5_j[1] = rtb_Divide_k_idx_2 * rtb_Divide_k_idx_2;

  /* Sum: '<S81>/Sum' incorporates:
   *  DotProduct: '<S81>/Dot Product'
   *  Product: '<S68>/Multiply'
   *  Product: '<S81>/Multiply'
   */
  rtb_MathFunction[1] = rtb_Divide_k_idx_2;
  rtb_Divide_k_idx_2 = rtb_Square_b[2] - rtb_Divide_ld * rtb_RandomSource_l_tmp
    [2];

  /* Sum: '<S85>/Sum of Elements' incorporates:
   *  Math: '<S85>/Math Function'
   */
  rtb_Gain_kz = (rtb_Multiply5_j[0] + rtb_Multiply5_j[1]) + rtb_Divide_k_idx_2 *
    rtb_Divide_k_idx_2;

  /* Math: '<S85>/Math Function1' incorporates:
   *  Sum: '<S85>/Sum of Elements'
   *
   * About '<S85>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Gain_kz < 0.0F) {
    rtb_Gain_kz = -sqrtf(fabsf(rtb_Gain_kz));
  } else {
    rtb_Gain_kz = sqrtf(rtb_Gain_kz);
  }

  /* End of Math: '<S85>/Math Function1' */

  /* Switch: '<S85>/Switch' incorporates:
   *  Constant: '<S85>/Constant'
   *  Product: '<S85>/Product'
   */
  if (rtb_Gain_kz > 0.0F) {
    rtb_Divide_k_idx_0 = rtb_MathFunction[0];
    rtb_Divide_k_idx_1 = rtb_MathFunction[1];
    rtb_Multiply_g2_idx_1 = rtb_Gain_kz;
  } else {
    rtb_Divide_k_idx_0 = 0.0F;
    rtb_Divide_k_idx_1 = 0.0F;
    rtb_Divide_k_idx_2 = 0.0F;
    rtb_Multiply_g2_idx_1 = 1.0F;
  }

  /* End of Switch: '<S85>/Switch' */

  /* Sqrt: '<S84>/Sqrt' incorporates:
   *  Math: '<S84>/Square'
   *  Product: '<S68>/Multiply'
   *  Sum: '<S84>/Sum of Elements'
   */
  rtb_Gain_kz = sqrtf((rtb_RandomSource_l_tmp[0] * rtb_RandomSource_l_tmp[0] +
                       rtb_RandomSource_l_tmp[1] * rtb_RandomSource_l_tmp[1]) +
                      rtb_RandomSource_l_tmp[2] * rtb_RandomSource_l_tmp[2]);

  /* Product: '<S81>/Multiply3' incorporates:
   *  Product: '<S85>/Divide'
   */
  rtb_Multiply5_c = rtb_Divide_k_idx_0 / rtb_Multiply_g2_idx_1 * rtb_Gain_kz;

  /* DotProduct: '<S81>/Dot Product2' */
  rtb_Divide_ld = rtb_Square_b[0] * rtb_Multiply5_c;

  /* Product: '<S81>/Multiply3' incorporates:
   *  Product: '<S85>/Divide'
   */
  rtb_Multiply5_j[0] = rtb_Multiply5_c;
  rtb_Multiply5_c = rtb_Divide_k_idx_1 / rtb_Multiply_g2_idx_1 * rtb_Gain_kz;

  /* DotProduct: '<S81>/Dot Product2' */
  rtb_Divide_ld += rtb_Square_b[1] * rtb_Multiply5_c;

  /* Product: '<S81>/Multiply3' incorporates:
   *  Product: '<S85>/Divide'
   */
  rtb_Multiply5_j[1] = rtb_Multiply5_c;
  rtb_Multiply5_c = rtb_Divide_k_idx_2 / rtb_Multiply_g2_idx_1 * rtb_Gain_kz;

  /* DotProduct: '<S81>/Dot Product2' */
  rtb_Divide_ld += rtb_Square_b[2] * rtb_Multiply5_c;

  /* Gain: '<S81>/Gain3' incorporates:
   *  Constant: '<S81>/Constant'
   *  DotProduct: '<S81>/Dot Product2'
   *  Product: '<S81>/Divide'
   */
  rtb_Divide_k_idx_1 = rtb_Divide_ld / 0.01F * -3.0F;

  /* Product: '<S81>/Multiply4' */
  rtb_Multiply_g2_idx_2 = rtb_Divide_k_idx_1 * rtb_Multiply5_j[0];
  rtb_Multiply4_idx_1 = rtb_Divide_k_idx_1 * rtb_Multiply5_j[1];

  /* RelationalOperator: '<S79>/Compare' incorporates:
   *  Constant: '<S79>/Constant'
   *  DotProduct: '<S68>/Dot Product2'
   *  Product: '<S68>/Multiply'
   */
  rtb_Compare_h_idx_0 = ((rtb_RandomSource_l_tmp[0] * rtb_Sum_jq[0] +
    rtb_RandomSource_l_tmp[1] * rtb_Sum_jq[1]) + rtb_RandomSource_l_tmp[2] *
    rtb_Sum_jq[2] < 0.0F);

  /* Product: '<S91>/Multiply' incorporates:
   *  Product: '<S68>/Multiply'
   */
  rtb_Multiply5_j[0] = rtb_Add_hg[1] * rtb_RandomSource_l_tmp[2];

  /* Product: '<S91>/Multiply1' incorporates:
   *  Product: '<S68>/Multiply'
   */
  rtb_Multiply5_j[1] = rtb_Add_hg[2] * rtb_RandomSource_l_tmp[0];

  /* Product: '<S91>/Multiply2' incorporates:
   *  Product: '<S68>/Multiply'
   */
  rtb_Multiply5_j[2] = rtb_Add_hg[0] * rtb_RandomSource_l_tmp[1];

  /* Sum: '<S87>/Sum' incorporates:
   *  Product: '<S68>/Multiply'
   *  Product: '<S92>/Multiply3'
   *  Product: '<S92>/Multiply4'
   *  Product: '<S92>/Multiply5'
   */
  rtb_Multiply5_j[0] -= rtb_Add_hg[2] * rtb_RandomSource_l_tmp[1];
  rtb_Multiply5_j[1] -= rtb_Add_hg[0] * rtb_RandomSource_l_tmp[2];
  rtb_Multiply5_j[2] -= rtb_Add_hg[1] * rtb_RandomSource_l_tmp[0];

  /* Product: '<S82>/Divide2' incorporates:
   *  Constant: '<S82>/Inertia_Matrix'
   */
  rt_mldivide_U1f3x3_U2f3_Yf3x1(Plant_ConstP.pooled36, rtb_Multiply5_j,
    rtb_Sum_jq);

  /* Product: '<S93>/Multiply' */
  rtb_MathFunction[0] = rtb_Sum_jq[1] * rtb_Add_hg[2];

  /* Product: '<S93>/Multiply1' */
  rtb_MathFunction[1] = rtb_Sum_jq[2] * rtb_Add_hg[0];

  /* Product: '<S93>/Multiply2' */
  rtb_MathFunction[2] = rtb_Sum_jq[0] * rtb_Add_hg[1];

  /* Sum: '<S88>/Sum' incorporates:
   *  Product: '<S94>/Multiply3'
   */
  rtb_Divide_ld = rtb_MathFunction[0] - rtb_Sum_jq[2] * rtb_Add_hg[1];

  /* DotProduct: '<S82>/Dot Product1' incorporates:
   *  Product: '<S68>/Multiply'
   */
  rtb_Divide_k_idx_2 = rtb_Divide_ld * rtb_RandomSource_l_tmp[0];

  /* Sum: '<S88>/Sum' incorporates:
   *  Product: '<S94>/Multiply4'
   */
  rtb_MathFunction[0] = rtb_Divide_ld;
  rtb_Divide_ld = rtb_MathFunction[1] - rtb_Sum_jq[0] * rtb_Add_hg[2];

  /* DotProduct: '<S82>/Dot Product1' incorporates:
   *  Product: '<S68>/Multiply'
   */
  rtb_Divide_k_idx_2 += rtb_Divide_ld * rtb_RandomSource_l_tmp[1];

  /* Sum: '<S88>/Sum' incorporates:
   *  Product: '<S94>/Multiply5'
   */
  rtb_MathFunction[1] = rtb_Divide_ld;
  rtb_Divide_ld = rtb_MathFunction[2] - rtb_Sum_jq[1] * rtb_Add_hg[0];

  /* DotProduct: '<S82>/Dot Product1' incorporates:
   *  Product: '<S68>/Multiply'
   */
  rtb_Divide_k_idx_2 += rtb_Divide_ld * rtb_RandomSource_l_tmp[2];

  /* Sum: '<S88>/Sum' */
  rtb_MathFunction[2] = rtb_Divide_ld;

  /* Product: '<S82>/Divide1' incorporates:
   *  Abs: '<S82>/Abs'
   *  Constant: '<S82>/mass_inv'
   *  Constant: '<S82>/period'
   *  DotProduct: '<S82>/Dot Product'
   *  DotProduct: '<S82>/Dot Product1'
   *  Gain: '<S82>/Gain'
   *  Product: '<S68>/Multiply'
   *  Product: '<S82>/Divide'
   *  Product: '<S82>/Multiply3'
   *  Sum: '<S82>/Add1'
   */
  rtb_Gain_kz = fabsf(-(((rtb_Square_b[0] * rtb_RandomSource_l_tmp[0] +
    rtb_Square_b[1] * rtb_RandomSource_l_tmp[1]) + rtb_Square_b[2] *
    rtb_RandomSource_l_tmp[2]) * Plant_ConstB.Add_o) * (1.0F /
    (rtb_Divide_k_idx_2 + 0.333333343F))) / 0.002F;

  /* Sum: '<S68>/Sum1' incorporates:
   *  Product: '<S68>/Multiply'
   *  Product: '<S68>/Multiply7'
   *  Product: '<S81>/Multiply4'
   *  Product: '<S82>/Multiply4'
   */
  rtb_Multiply_g2_idx_2 += rtb_Compare_h_idx_0 ? rtb_Gain_kz *
    rtb_RandomSource_l_tmp[0] : 0.0F;
  rtb_Multiply4_idx_1 += rtb_Compare_h_idx_0 ? rtb_Gain_kz *
    rtb_RandomSource_l_tmp[1] : 0.0F;
  rtb_Multiply4 = rtb_Divide_k_idx_1 * rtb_Multiply5_c + (rtb_Compare_h_idx_0 ?
    rtb_Gain_kz * rtb_RandomSource_l_tmp[2] : 0.0F);

  /* RelationalOperator: '<S95>/Compare' incorporates:
   *  Constant: '<S95>/Constant'
   *  Delay: '<Root>/Delay'
   */
  rtb_Compare_h_idx_0 = (Plant_Y.Plant_States.h_R < 0.0F);

  /* Switch: '<S73>/Switch2' incorporates:
   *  Gain: '<S96>/Gain5'
   *  Gain: '<S96>/Gain6'
   *  Product: '<S96>/Multiply'
   *  SignalConversion: '<S96>/TmpSignal ConversionAtMultiplyInport2'
   */
  if (rtb_Compare_h_idx_0) {
    /* Switch: '<S96>/Switch1' incorporates:
     *  Constant: '<S96>/mg'
     *  Constant: '<S98>/Constant'
     *  Delay: '<Root>/Delay'
     *  Gain: '<S96>/Gain'
     *  RelationalOperator: '<S98>/Compare'
     *  Sum: '<S96>/Add'
     */
    if (Plant_Y.Plant_States.h_R <= -0.05F) {
      /* Switch: '<S96>/Switch3' incorporates:
       *  Constant: '<S96>/mg'
       *  Constant: '<S99>/Constant'
       *  Gain: '<S96>/Gain1'
       *  Gain: '<S96>/Gain2'
       *  Gain: '<S96>/Gain3'
       *  Gain: '<S96>/Gain4'
       *  RelationalOperator: '<S99>/Compare'
       *  Sum: '<S96>/Add1'
       *  Sum: '<S96>/Add2'
       */
      if (Plant_Y.Plant_States.h_R <= -0.1F) {
        rtb_Divide_k_idx_1 = (3.0F * Plant_Y.Plant_States.h_R - 29.418F) -
          100.0F * Plant_Y.Plant_States.vel_z_O;
      } else {
        rtb_Divide_k_idx_1 = (1.5F * Plant_Y.Plant_States.h_R - 29.418F) - 50.0F
          * Plant_Y.Plant_States.vel_z_O;
      }

      /* End of Switch: '<S96>/Switch3' */
    } else {
      rtb_Divide_k_idx_1 = -29.418F - 50.0F * Plant_Y.Plant_States.vel_z_O;
    }

    /* End of Switch: '<S96>/Switch1' */
    for (i = 0; i < 3; i++) {
      rtb_Square_o5[i] = rtb_VectorConcatenate_n[i + 6] * rtb_Divide_k_idx_1 +
        (rtb_VectorConcatenate_n[i + 3] * -rtb_Plant_States_vel_y_O +
         rtb_VectorConcatenate_n[i] * -rtb_DiscreteTimeIntegrator_idx_);
    }
  } else {
    rtb_Square_o5[0] = 0.0F;
    rtb_Square_o5[1] = 0.0F;
    rtb_Square_o5[2] = 0.0F;
  }

  /* End of Switch: '<S73>/Switch2' */
  for (i = 0; i < 3; i++) {
    /* Product: '<S76>/Multiply' */
    rtb_Divide_k_idx_1 = rtb_VectorConcatenate_f[i + 6] *
      rtb_Plant_States_vel_z_O + (rtb_VectorConcatenate_f[i + 3] *
      rtb_Plant_States_vel_y_O + rtb_VectorConcatenate_f[i] *
      rtb_DiscreteTimeIntegrator_idx_);

    /* Signum: '<S76>/Sign1' */
    if (rtb_Divide_k_idx_1 < 0.0F) {
      rtb_Divide_ld = -1.0F;
    } else if (rtb_Divide_k_idx_1 > 0.0F) {
      rtb_Divide_ld = 1.0F;
    } else {
      rtb_Divide_ld = rtb_Divide_k_idx_1;
    }

    /* End of Signum: '<S76>/Sign1' */

    /* Gain: '<S76>/Gain' incorporates:
     *  Math: '<S76>/Square1'
     *  Product: '<S76>/Multiply5'
     */
    rtb_Square_b[i] = rtb_Divide_k_idx_1 * rtb_Divide_k_idx_1 * rtb_Divide_ld *
      -0.02F;
  }

  /* Product: '<S76>/Multiply1' incorporates:
   *  Math: '<S76>/Square'
   */
  for (i = 0; i < 3; i++) {
    rtb_Add_hg[i] = rtb_VectorConcatenate_f[3 * i + 2] * rtb_Square_b[2] +
      (rtb_VectorConcatenate_f[3 * i + 1] * rtb_Square_b[1] +
       rtb_VectorConcatenate_f[3 * i] * rtb_Square_b[0]);
  }

  /* End of Product: '<S76>/Multiply1' */

  /* DotProduct: '<S74>/Dot Product' */
  rtb_Square_l = 0.0F;
  for (i = 0; i < 3; i++) {
    /* Product: '<S76>/Multiply2' */
    rtb_Divide_k_idx_1 = rtb_VectorConcatenate_n[i + 6];

    /* Sum: '<S4>/Add2' incorporates:
     *  Inport: '<Root>/Environment_Info'
     *  Product: '<S72>/Multiply3'
     *  Product: '<S76>/Multiply2'
     */
    rtb_Divide_k_idx_1 = (((Plant_U.Environment_Info.force[i] + rtb_Square_o5[i])
      + (rtb_Divide_k_idx_1 * rtb_Add_hg[2] + (rtb_VectorConcatenate_n[i + 3] *
      rtb_Add_hg[1] + rtb_VectorConcatenate_n[i] * rtb_Add_hg[0]))) +
                          rtb_Divide_k_idx_1 * 29.43F) + rtb_Sum1_a[i];

    /* DotProduct: '<S74>/Dot Product' incorporates:
     *  Product: '<S74>/Multiply'
     */
    rtb_Square_l += rtb_Divide_k_idx_1 * rtb_RandomSource_l_tmp[i];

    /* Sum: '<S4>/Add2' */
    rtb_Square_o5[i] = rtb_Divide_k_idx_1;
  }

  /* Product: '<S74>/Multiply1' incorporates:
   *  Constant: '<S100>/Constant'
   *  DotProduct: '<S74>/Dot Product'
   *  RelationalOperator: '<S100>/Compare'
   */
  rtb_Divide_k_idx_1 = rtb_Square_l < 0.0F ? rtb_Square_l : 0.0F;

  /* Sum: '<S4>/Add' incorporates:
   *  Product: '<S74>/Multiply'
   *  Product: '<S74>/Multiply1'
   *  Sum: '<S74>/Sum'
   */
  rtb_Multiply_g2_idx_2 += rtb_Square_o5[0] - rtb_Divide_k_idx_1 *
    rtb_RandomSource_l_tmp[0];
  rtb_Multiply4_idx_1 += rtb_Square_o5[1] - rtb_Divide_k_idx_1 *
    rtb_RandomSource_l_tmp[1];
  rtb_Multiply4 += rtb_Square_o5[2] - rtb_Divide_k_idx_1 *
    rtb_RandomSource_l_tmp[2];

  /* Switch: '<S73>/Switch1' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S97>/Gain1'
   *  Gain: '<S97>/Gain2'
   *  Gain: '<S97>/Gain3'
   *  Sum: '<S97>/Subtract'
   */
  if (rtb_Compare_h_idx_0) {
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

  /* End of Switch: '<S73>/Switch1' */

  /* Signum: '<S76>/Sign' incorporates:
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
  /* Sum: '<S4>/Add3' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S76>/Gain1'
   *  Inport: '<Root>/Environment_Info'
   *  Math: '<S76>/Square2'
   *  Product: '<S76>/Multiply3'
   *  Sum: '<S1>/Sum'
   */
  rtb_Square_o5[0] = (((rtb_MathFunction1_k + rtb_Sum_i[0]) +
                       Plant_U.Environment_Info.torque[0]) + rtb_Square_o5[0]) +
    Plant_Y.Plant_States.rot_x_B * Plant_Y.Plant_States.rot_x_B * rtb_Gain_kz *
    -0.005F;

  /* End of Outputs for SubSystem: '<Root>/Actuators' */

  /* Signum: '<S76>/Sign' incorporates:
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
  /* Sum: '<S4>/Add3' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S76>/Gain1'
   *  Inport: '<Root>/Environment_Info'
   *  Math: '<S76>/Square2'
   *  Product: '<S76>/Multiply3'
   *  Sum: '<S1>/Sum'
   */
  rtb_Square_o5[1] = (((rtb_DiscreteTimeIntegrator_id_1 + rtb_Sum_i[1]) +
                       Plant_U.Environment_Info.torque[1]) + rtb_Square_o5[1]) +
    Plant_Y.Plant_States.rot_y_B * Plant_Y.Plant_States.rot_y_B * rtb_Gain_kz *
    -0.005F;

  /* End of Outputs for SubSystem: '<Root>/Actuators' */

  /* Signum: '<S76>/Sign' incorporates:
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
  /* Sum: '<S4>/Add3' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S76>/Gain1'
   *  Inport: '<Root>/Environment_Info'
   *  Math: '<S76>/Square2'
   *  Product: '<S76>/Multiply3'
   *  Sum: '<S1>/Sum'
   */
  rtb_Square_l = (((rtb_DiscreteTimeIntegrator_id_0 + rtb_Sum_i[2]) +
                   Plant_U.Environment_Info.torque[2]) + rtb_Square_o5[2]) +
    Plant_Y.Plant_States.rot_z_B * Plant_Y.Plant_States.rot_z_B * rtb_Gain_kz *
    -0.005F;

  /* End of Outputs for SubSystem: '<Root>/Actuators' */

  /* Sum: '<S4>/Add1' incorporates:
   *  Product: '<S68>/Multiply6'
   */
  rtb_Multiply5_j[0] = rtb_Square_o5[0];
  rtb_Multiply5_j[1] = rtb_Square_o5[1];

  /* RelationalOperator: '<S69>/Compare' incorporates:
   *  Constant: '<S69>/Constant'
   *  Inport: '<Root>/Environment_Info'
   *  Math: '<S75>/Square'
   *  Sqrt: '<S75>/Sqrt'
   *  Sum: '<S75>/Sum of Elements'
   */
  rtb_Compare_h_idx_0 = (sqrtf((Plant_U.Environment_Info.hit_normal[0] *
    Plant_U.Environment_Info.hit_normal[0] +
    Plant_U.Environment_Info.hit_normal[1] *
    Plant_U.Environment_Info.hit_normal[1]) +
    Plant_U.Environment_Info.hit_normal[2] *
    Plant_U.Environment_Info.hit_normal[2]) > 0.0F);

  /* RelationalOperator: '<S70>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S70>/Delay Input1'
   *
   * Block description for '<S70>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_Compare_h_idx_1 = ((int32_T)rtb_Compare_h_idx_0 > (int32_T)
    Plant_DW.DelayInput1_DSTATE);

  /* Update for UnitDelay: '<S70>/Delay Input1'
   *
   * Block description for '<S70>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Plant_DW.DelayInput1_DSTATE = rtb_Compare_h_idx_0;

  /* End of Outputs for SubSystem: '<Root>/Environment' */

  /* Outputs for Atomic SubSystem: '<Root>/Kinematic_Equation' */
  /* DiscreteIntegrator: '<S105>/Discrete-Time Integrator' */
  if (Plant_DW.DiscreteTimeIntegrator_PrevRese != 0) {
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[0] = Plant_ConstB.quat0[0];
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[1] = Plant_ConstB.quat0[1];
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[2] = Plant_ConstB.quat0[2];
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[3] = Plant_ConstB.quat0[3];
  }

  rtb_MathFunction1_k = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[0];
  rtb_DiscreteTimeIntegrator_id_1 = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[1];
  rtb_DiscreteTimeIntegrator_id_0 = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[2];
  rtb_DiscreteTimeIntegrator_idx_ = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[3];

  /* Sqrt: '<S109>/Sqrt' incorporates:
   *  DiscreteIntegrator: '<S105>/Discrete-Time Integrator'
   *  Math: '<S109>/Square'
   *  Sqrt: '<S120>/Sqrt'
   *  Sqrt: '<S125>/Sqrt'
   *  Sum: '<S109>/Sum of Elements'
   */
  rtb_Add_j_tmp = sqrtf(((Plant_DW.DiscreteTimeIntegrator_DSTATE_k[0] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[0] +
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[1] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[1]) +
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[2] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[2]) +
                        Plant_DW.DiscreteTimeIntegrator_DSTATE_k[3] *
                        Plant_DW.DiscreteTimeIntegrator_DSTATE_k[3]);

  /* Product: '<S108>/Divide' incorporates:
   *  DiscreteIntegrator: '<S105>/Discrete-Time Integrator'
   *  Sqrt: '<S109>/Sqrt'
   */
  rtb_Plant_States_vel_y_O = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[0] /
    rtb_Add_j_tmp;
  rtb_Plant_States_vel_z_O = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[1] /
    rtb_Add_j_tmp;
  rtb_Divide_ld = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[2] / rtb_Add_j_tmp;
  rtb_Multiply5_c = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[3] / rtb_Add_j_tmp;

  /* SignalConversion: '<S110>/ConcatBufferAtMatrix ConcatenateIn1' incorporates:
   *  Constant: '<S110>/Constant'
   */
  rtb_MatrixConcatenate4[0] = 0.0F;

  /* DiscreteIntegrator: '<S101>/Discrete-Time Integrator' */
  if (Plant_DW.DiscreteTimeIntegrator_PrevRe_p != 0) {
    Plant_DW.DiscreteTimeIntegrator_DSTATE_i[0] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_i[1] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_i[2] = 0.0F;
  }

  rtb_Square_o5[0] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[0];
  rtb_Square_o5[1] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[1];
  rtb_Square_o5[2] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[2];

  /* SignalConversion: '<S110>/ConcatBufferAtMatrix ConcatenateIn2' incorporates:
   *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[1] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[0];

  /* SignalConversion: '<S110>/ConcatBufferAtMatrix ConcatenateIn3' incorporates:
   *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[2] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[1];

  /* SignalConversion: '<S110>/ConcatBufferAtMatrix ConcatenateIn4' incorporates:
   *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[3] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[2];

  /* Gain: '<S110>/Gain1' incorporates:
   *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[4] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_i[0];

  /* SignalConversion: '<S110>/ConcatBufferAtMatrix Concatenate1In2' incorporates:
   *  Constant: '<S110>/Constant1'
   */
  rtb_MatrixConcatenate4[5] = 0.0F;

  /* Gain: '<S110>/Gain2' incorporates:
   *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[6] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_i[2];

  /* SignalConversion: '<S110>/ConcatBufferAtMatrix Concatenate1In4' incorporates:
   *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[7] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[1];

  /* Gain: '<S110>/Gain3' incorporates:
   *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[8] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_i[1];

  /* SignalConversion: '<S110>/ConcatBufferAtMatrix Concatenate2In2' incorporates:
   *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[9] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[2];

  /* SignalConversion: '<S110>/ConcatBufferAtMatrix Concatenate2In3' incorporates:
   *  Constant: '<S110>/Constant2'
   */
  rtb_MatrixConcatenate4[10] = 0.0F;

  /* Gain: '<S110>/Gain4' incorporates:
   *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[11] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_i[0];

  /* Gain: '<S110>/Gain6' incorporates:
   *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[12] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_i[2];

  /* Gain: '<S110>/Gain7' incorporates:
   *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[13] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_i[1];

  /* SignalConversion: '<S110>/ConcatBufferAtMatrix Concatenate3In3' incorporates:
   *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[14] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[0];

  /* SignalConversion: '<S110>/ConcatBufferAtMatrix Concatenate3In4' incorporates:
   *  Constant: '<S110>/Constant3'
   */
  rtb_MatrixConcatenate4[15] = 0.0F;

  /* Product: '<S116>/Divide' incorporates:
   *  DiscreteIntegrator: '<S105>/Discrete-Time Integrator'
   */
  rtb_Gain_kz = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[0] / rtb_Add_j_tmp;
  rtb_Gain_e_tmp_0 = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[1] / rtb_Add_j_tmp;
  tmp_0 = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[2] / rtb_Add_j_tmp;
  rtb_Gain_e_tmp_1 = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[3] / rtb_Add_j_tmp;

  /* Product: '<S121>/Divide' incorporates:
   *  DiscreteIntegrator: '<S105>/Discrete-Time Integrator'
   */
  rtb_Divide_k_idx_0 = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[0] /
    rtb_Add_j_tmp;
  rtb_Divide_k_idx_1 = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[1] /
    rtb_Add_j_tmp;
  rtb_Divide_k_idx_2 = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[2] /
    rtb_Add_j_tmp;
  rtb_Multiply_g2_idx_1 = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[3] /
    rtb_Add_j_tmp;

  /* Product: '<S101>/Multiply' incorporates:
   *  Constant: '<S101>/Inertia_Matrix'
   *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator'
   */
  for (i = 0; i < 3; i++) {
    rtb_Add_hg[i] = Plant_ConstP.pooled36[i + 6] *
      Plant_DW.DiscreteTimeIntegrator_DSTATE_i[2] + (Plant_ConstP.pooled36[i + 3]
      * Plant_DW.DiscreteTimeIntegrator_DSTATE_i[1] + Plant_ConstP.pooled36[i] *
      Plant_DW.DiscreteTimeIntegrator_DSTATE_i[0]);
  }

  /* End of Product: '<S101>/Multiply' */

  /* Product: '<S106>/Multiply' incorporates:
   *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator'
   */
  rtb_Sum_ok[0] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[1] * rtb_Add_hg[2];

  /* Product: '<S106>/Multiply1' incorporates:
   *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator'
   */
  rtb_Sum_ok[1] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[2] * rtb_Add_hg[0];

  /* Product: '<S106>/Multiply2' incorporates:
   *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator'
   */
  rtb_Sum_ok[2] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[0] * rtb_Add_hg[1];

  /* Product: '<S107>/Multiply3' incorporates:
   *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator'
   */
  rtb_Sum_jq[0] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[2] * rtb_Add_hg[1];

  /* Product: '<S107>/Multiply4' incorporates:
   *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator'
   */
  rtb_Sum_jq[1] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[0] * rtb_Add_hg[2];

  /* Product: '<S107>/Multiply5' incorporates:
   *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator'
   */
  rtb_Sum_jq[2] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[1] * rtb_Add_hg[0];

  /* DiscreteIntegrator: '<S102>/Discrete-Time Integrator' */
  if (rtb_Compare_h_idx_1 || (Plant_DW.DiscreteTimeIntegrator_PrevRe_g != 0)) {
    Plant_DW.DiscreteTimeIntegrator_DSTATE_b[0] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_b[1] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_b[2] = 0.0F;
  }

  /* Product: '<S119>/Product3' incorporates:
   *  Product: '<S116>/Divide'
   *  Product: '<S117>/Product6'
   */
  rtb_Add_j_tmp = tmp_0 * tmp_0;

  /* Product: '<S119>/Product6' incorporates:
   *  Product: '<S116>/Divide'
   *  Product: '<S117>/Product9'
   */
  rtb_Add_j_tmp_0 = rtb_Gain_e_tmp_0 * rtb_Gain_e_tmp_1;

  /* Product: '<S119>/Product7' incorporates:
   *  Product: '<S116>/Divide'
   *  Product: '<S117>/Product2'
   */
  rtb_Add_j_tmp_1 = rtb_Gain_kz * tmp_0;

  /* Sum: '<S119>/Sum2' incorporates:
   *  Constant: '<S119>/Constant'
   *  Product: '<S116>/Divide'
   *  Product: '<S119>/Product2'
   *  Sum: '<S118>/Sum1'
   */
  rtb_Add_j_tmp_2 = 0.5F - rtb_Gain_e_tmp_0 * rtb_Gain_e_tmp_0;

  /* Product: '<S119>/Product1' incorporates:
   *  Product: '<S116>/Divide'
   *  Product: '<S118>/Product2'
   */
  rtb_Add_j_tmp_3 = rtb_Gain_kz * rtb_Gain_e_tmp_0;

  /* Product: '<S119>/Product9' incorporates:
   *  Product: '<S116>/Divide'
   *  Product: '<S118>/Product3'
   */
  rtb_Add_j_tmp_4 = tmp_0 * rtb_Gain_e_tmp_1;

  /* Sum: '<S119>/Sum' incorporates:
   *  DiscreteIntegrator: '<S102>/Discrete-Time Integrator'
   *  Gain: '<S119>/Gain1'
   *  Gain: '<S119>/Gain2'
   *  Gain: '<S119>/Gain3'
   *  Product: '<S119>/Product1'
   *  Product: '<S119>/Product3'
   *  Product: '<S119>/Product4'
   *  Product: '<S119>/Product5'
   *  Product: '<S119>/Product6'
   *  Product: '<S119>/Product7'
   *  Product: '<S119>/Product8'
   *  Product: '<S119>/Product9'
   *  Sum: '<S119>/Sum1'
   *  Sum: '<S119>/Sum2'
   *  Sum: '<S119>/Sum3'
   */
  rtb_Add_ps = ((rtb_Add_j_tmp_0 + rtb_Add_j_tmp_1) * 2.0F *
                Plant_DW.DiscreteTimeIntegrator_DSTATE_b[0] + (rtb_Add_j_tmp_4 -
    rtb_Add_j_tmp_3) * 2.0F * Plant_DW.DiscreteTimeIntegrator_DSTATE_b[1]) +
    (rtb_Add_j_tmp_2 - rtb_Add_j_tmp) * 2.0F *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_b[2];

  /* Product: '<S117>/Product7' incorporates:
   *  Product: '<S116>/Divide'
   *  Product: '<S118>/Product9'
   */
  rtb_Gain_e_tmp = rtb_Gain_e_tmp_1 * rtb_Gain_e_tmp_1;

  /* Product: '<S117>/Product' incorporates:
   *  Product: '<S116>/Divide'
   *  Product: '<S118>/Product6'
   */
  rtb_Gain_e_tmp_0 *= tmp_0;

  /* Product: '<S117>/Product1' incorporates:
   *  Product: '<S116>/Divide'
   *  Product: '<S118>/Product7'
   */
  rtb_Gain_e_tmp_1 *= rtb_Gain_kz;

  /* Sum: '<S117>/Sum' incorporates:
   *  Constant: '<S117>/Constant'
   *  DiscreteIntegrator: '<S102>/Discrete-Time Integrator'
   *  Gain: '<S117>/Gain'
   *  Gain: '<S117>/Gain2'
   *  Gain: '<S117>/Gain3'
   *  Product: '<S117>/Product'
   *  Product: '<S117>/Product1'
   *  Product: '<S117>/Product4'
   *  Product: '<S117>/Product5'
   *  Product: '<S117>/Product7'
   *  Product: '<S117>/Product8'
   *  Sum: '<S117>/Sum1'
   *  Sum: '<S117>/Sum2'
   *  Sum: '<S117>/Sum3'
   */
  rtb_Gain_kz = (((0.5F - rtb_Add_j_tmp) - rtb_Gain_e_tmp) * 2.0F *
                 Plant_DW.DiscreteTimeIntegrator_DSTATE_b[0] + (rtb_Gain_e_tmp_0
    + rtb_Gain_e_tmp_1) * 2.0F * Plant_DW.DiscreteTimeIntegrator_DSTATE_b[1]) +
    (rtb_Add_j_tmp_0 - rtb_Add_j_tmp_1) * 2.0F *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_b[2];

  /* Product: '<S114>/Multiply1' incorporates:
   *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator'
   */
  rtb_Add_hg[1] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[2] * rtb_Gain_kz;

  /* Product: '<S115>/Multiply5' incorporates:
   *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator'
   */
  rtb_Sum_mj[2] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[1] * rtb_Gain_kz;

  /* Sum: '<S118>/Sum' incorporates:
   *  DiscreteIntegrator: '<S102>/Discrete-Time Integrator'
   *  Gain: '<S118>/Gain1'
   *  Gain: '<S118>/Gain2'
   *  Gain: '<S118>/Gain3'
   *  Product: '<S118>/Product4'
   *  Product: '<S118>/Product5'
   *  Product: '<S118>/Product8'
   *  Sum: '<S118>/Sum1'
   *  Sum: '<S118>/Sum2'
   *  Sum: '<S118>/Sum3'
   */
  rtb_Gain_kz = ((rtb_Add_j_tmp_2 - rtb_Gain_e_tmp) * 2.0F *
                 Plant_DW.DiscreteTimeIntegrator_DSTATE_b[1] + (rtb_Gain_e_tmp_0
    - rtb_Gain_e_tmp_1) * 2.0F * Plant_DW.DiscreteTimeIntegrator_DSTATE_b[0]) +
    (rtb_Add_j_tmp_3 + rtb_Add_j_tmp_4) * 2.0F *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_b[2];

  /* DiscreteIntegrator: '<S102>/Discrete-Time Integrator' */
  rtb_Sum_i[0] = Plant_DW.DiscreteTimeIntegrator_DSTATE_b[0];

  /* Sum: '<S101>/Sum' incorporates:
   *  Sum: '<S103>/Sum'
   */
  rtb_Sum_jq[0] = rtb_Multiply5_j[0] - (rtb_Sum_ok[0] - rtb_Sum_jq[0]);

  /* Sum: '<S102>/Sum' incorporates:
   *  Constant: '<S102>/mass'
   *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator'
   *  Product: '<S102>/Divide'
   *  Product: '<S114>/Multiply'
   *  Product: '<S115>/Multiply3'
   *  Sum: '<S111>/Sum'
   */
  rtb_Sum_mj[0] = rtb_Multiply_g2_idx_2 / 3.0F -
    (Plant_DW.DiscreteTimeIntegrator_DSTATE_i[1] * rtb_Add_ps -
     Plant_DW.DiscreteTimeIntegrator_DSTATE_i[2] * rtb_Gain_kz);

  /* DiscreteIntegrator: '<S102>/Discrete-Time Integrator' */
  rtb_Sum_i[1] = Plant_DW.DiscreteTimeIntegrator_DSTATE_b[1];

  /* Sum: '<S101>/Sum' incorporates:
   *  Sum: '<S103>/Sum'
   */
  rtb_Sum_jq[1] = rtb_Multiply5_j[1] - (rtb_Sum_ok[1] - rtb_Sum_jq[1]);

  /* Sum: '<S102>/Sum' incorporates:
   *  Constant: '<S102>/mass'
   *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator'
   *  Product: '<S102>/Divide'
   *  Product: '<S115>/Multiply4'
   *  Sum: '<S111>/Sum'
   */
  rtb_Sum_mj[1] = rtb_Multiply4_idx_1 / 3.0F - (rtb_Add_hg[1] -
    Plant_DW.DiscreteTimeIntegrator_DSTATE_i[0] * rtb_Add_ps);

  /* DiscreteIntegrator: '<S102>/Discrete-Time Integrator' */
  rtb_Sum_i[2] = Plant_DW.DiscreteTimeIntegrator_DSTATE_b[2];

  /* Sum: '<S102>/Sum' incorporates:
   *  Constant: '<S102>/mass'
   *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator'
   *  Product: '<S102>/Divide'
   *  Product: '<S114>/Multiply2'
   *  Sum: '<S111>/Sum'
   */
  rtb_Add_ps = rtb_Multiply4 / 3.0F - (Plant_DW.DiscreteTimeIntegrator_DSTATE_i
    [0] * rtb_Gain_kz - rtb_Sum_mj[2]);

  /* Sum: '<S101>/Sum' incorporates:
   *  Sum: '<S103>/Sum'
   */
  rtb_Sum_jq[2] = rtb_Square_l - (rtb_Sum_ok[2] - rtb_Sum_jq[2]);

  /* Product: '<S122>/Product7' incorporates:
   *  Product: '<S121>/Divide'
   *  Product: '<S123>/Product7'
   */
  rtb_Square_l = rtb_Multiply_g2_idx_1 * rtb_Multiply_g2_idx_1;

  /* Product: '<S122>/Product' incorporates:
   *  Product: '<S121>/Divide'
   *  Product: '<S123>/Product'
   */
  rtb_Add_j_tmp = rtb_Divide_k_idx_1 * rtb_Divide_k_idx_2;

  /* Product: '<S122>/Product1' incorporates:
   *  Product: '<S121>/Divide'
   *  Product: '<S123>/Product1'
   */
  rtb_Add_j_tmp_2 = rtb_Divide_k_idx_0 * rtb_Multiply_g2_idx_1;

  /* Product: '<S122>/Product2' incorporates:
   *  Product: '<S121>/Divide'
   *  Product: '<S124>/Product9'
   */
  rtb_Multiply4_idx_1 = rtb_Divide_k_idx_1 * rtb_Multiply_g2_idx_1;

  /* Product: '<S122>/Product3' incorporates:
   *  Product: '<S121>/Divide'
   *  Product: '<S124>/Product1'
   */
  rtb_Gain_kz = rtb_Divide_k_idx_0 * rtb_Divide_k_idx_2;

  /* Product: '<S122>/Product6' incorporates:
   *  Product: '<S121>/Divide'
   *  Product: '<S124>/Product7'
   */
  rtb_Multiply4 = rtb_Divide_k_idx_2 * rtb_Divide_k_idx_2;

  /* Sum: '<S122>/Sum' incorporates:
   *  Constant: '<S122>/Constant'
   *  Gain: '<S122>/Gain'
   *  Gain: '<S122>/Gain1'
   *  Gain: '<S122>/Gain2'
   *  Product: '<S122>/Product'
   *  Product: '<S122>/Product1'
   *  Product: '<S122>/Product2'
   *  Product: '<S122>/Product3'
   *  Product: '<S122>/Product4'
   *  Product: '<S122>/Product5'
   *  Product: '<S122>/Product6'
   *  Product: '<S122>/Product7'
   *  Product: '<S122>/Product8'
   *  Sum: '<S122>/Sum1'
   *  Sum: '<S122>/Sum2'
   *  Sum: '<S122>/Sum3'
   */
  rtb_Multiply_g2_idx_2 = (((0.5F - rtb_Multiply4) - rtb_Square_l) * 2.0F *
    rtb_Sum_mj[0] + (rtb_Add_j_tmp - rtb_Add_j_tmp_2) * 2.0F * rtb_Sum_mj[1]) +
    (rtb_Multiply4_idx_1 + rtb_Gain_kz) * 2.0F * rtb_Add_ps;

  /* Product: '<S123>/Product2' incorporates:
   *  Product: '<S121>/Divide'
   *  Product: '<S124>/Product2'
   */
  rtb_Divide_k_idx_0 *= rtb_Divide_k_idx_1;

  /* Product: '<S123>/Product3' incorporates:
   *  Product: '<S121>/Divide'
   *  Product: '<S124>/Product3'
   */
  rtb_Divide_k_idx_2 *= rtb_Multiply_g2_idx_1;

  /* Sum: '<S123>/Sum3' incorporates:
   *  Constant: '<S123>/Constant'
   *  Product: '<S121>/Divide'
   *  Product: '<S123>/Product6'
   *  Sum: '<S124>/Sum3'
   */
  rtb_Multiply_g2_idx_1 = 0.5F - rtb_Divide_k_idx_1 * rtb_Divide_k_idx_1;

  /* Sum: '<S123>/Sum' incorporates:
   *  Gain: '<S123>/Gain'
   *  Gain: '<S123>/Gain1'
   *  Gain: '<S123>/Gain2'
   *  Product: '<S123>/Product2'
   *  Product: '<S123>/Product3'
   *  Product: '<S123>/Product4'
   *  Product: '<S123>/Product5'
   *  Product: '<S123>/Product8'
   *  Sum: '<S123>/Sum1'
   *  Sum: '<S123>/Sum2'
   *  Sum: '<S123>/Sum3'
   */
  rtb_Divide_k_idx_1 = ((rtb_Multiply_g2_idx_1 - rtb_Square_l) * 2.0F *
                        rtb_Sum_mj[1] + (rtb_Add_j_tmp + rtb_Add_j_tmp_2) * 2.0F
                        * rtb_Sum_mj[0]) + (rtb_Divide_k_idx_2 -
    rtb_Divide_k_idx_0) * 2.0F * rtb_Add_ps;

  /* Sum: '<S124>/Sum' incorporates:
   *  Gain: '<S124>/Gain1'
   *  Gain: '<S124>/Gain2'
   *  Gain: '<S124>/Gain3'
   *  Product: '<S124>/Product4'
   *  Product: '<S124>/Product5'
   *  Product: '<S124>/Product8'
   *  Sum: '<S124>/Sum1'
   *  Sum: '<S124>/Sum2'
   *  Sum: '<S124>/Sum3'
   */
  rtb_Divide_k_idx_2 = ((rtb_Multiply4_idx_1 - rtb_Gain_kz) * 2.0F * rtb_Sum_mj
                        [0] + (rtb_Divide_k_idx_0 + rtb_Divide_k_idx_2) * 2.0F *
                        rtb_Sum_mj[1]) + (rtb_Multiply_g2_idx_1 - rtb_Multiply4)
    * 2.0F * rtb_Add_ps;

  /* Math: '<S104>/Square1' incorporates:
   *  Product: '<S108>/Divide'
   */
  rtb_Add_ps = rtb_Divide_ld * rtb_Divide_ld;

  /* Product: '<S104>/Multiply6' incorporates:
   *  Constant: '<S104>/Constant'
   *  Product: '<S104>/Multiply4'
   *  Product: '<S104>/Multiply5'
   *  Product: '<S108>/Divide'
   *  Sum: '<S104>/Subtract'
   */
  rtb_Divide_k_idx_0 = (rtb_Plant_States_vel_y_O * rtb_Divide_ld -
                        rtb_Multiply5_c * rtb_Plant_States_vel_z_O) * 2.0F;

  /* DiscreteIntegrator: '<S102>/Discrete-Time Integrator1' */
  if (Plant_DW.DiscreteTimeIntegrator1_PrevRes != 0) {
    Plant_DW.DiscreteTimeIntegrator1_DSTATE[0] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator1_DSTATE[1] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator1_DSTATE[2] = 0.0F;
  }

  rtb_Sum_mj[0] = Plant_DW.DiscreteTimeIntegrator1_DSTATE[0];
  rtb_Sum_mj[1] = Plant_DW.DiscreteTimeIntegrator1_DSTATE[1];
  rtb_Sum_mj[2] = Plant_DW.DiscreteTimeIntegrator1_DSTATE[2];

  /* End of DiscreteIntegrator: '<S102>/Discrete-Time Integrator1' */

  /* Product: '<S105>/Multiply' incorporates:
   *  DiscreteIntegrator: '<S105>/Discrete-Time Integrator'
   */
  for (i = 0; i < 4; i++) {
    rtb_Multiply_g2_idx_1 = rtb_MatrixConcatenate4[i + 12] *
      Plant_DW.DiscreteTimeIntegrator_DSTATE_k[3] + (rtb_MatrixConcatenate4[i +
      8] * Plant_DW.DiscreteTimeIntegrator_DSTATE_k[2] +
      (rtb_MatrixConcatenate4[i + 4] * Plant_DW.DiscreteTimeIntegrator_DSTATE_k
       [1] + rtb_MatrixConcatenate4[i] *
       Plant_DW.DiscreteTimeIntegrator_DSTATE_k[0]));
    rtb_MatrixConcatenate4_0[i] = rtb_Multiply_g2_idx_1;
  }

  /* End of Product: '<S105>/Multiply' */

  /* Update for DiscreteIntegrator: '<S105>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S105>/Gain'
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

  /* Product: '<S101>/Divide' incorporates:
   *  Constant: '<S101>/Inertia_Matrix'
   */
  rt_mldivide_U1f3x3_U2f3_Yf3x1(Plant_ConstP.pooled36, rtb_Sum_jq, rtb_Square_b);

  /* Update for DiscreteIntegrator: '<S101>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_PrevRe_p = 0;

  /* Update for DiscreteIntegrator: '<S102>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_PrevRe_g = (int8_T)rtb_Compare_h_idx_1;

  /* Update for DiscreteIntegrator: '<S101>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_i[0] += 0.002F * rtb_Square_b[0];

  /* Update for DiscreteIntegrator: '<S102>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_b[0] += 0.002F * rtb_Multiply_g2_idx_2;

  /* Update for DiscreteIntegrator: '<S102>/Discrete-Time Integrator1' */
  Plant_DW.DiscreteTimeIntegrator1_DSTATE[0] += 0.002F * rtb_Sum_i[0];

  /* Update for DiscreteIntegrator: '<S101>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_i[1] += 0.002F * rtb_Square_b[1];

  /* Update for DiscreteIntegrator: '<S102>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_b[1] += 0.002F * rtb_Divide_k_idx_1;

  /* Update for DiscreteIntegrator: '<S102>/Discrete-Time Integrator1' */
  Plant_DW.DiscreteTimeIntegrator1_DSTATE[1] += 0.002F * rtb_Sum_i[1];

  /* Update for DiscreteIntegrator: '<S101>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_i[2] += 0.002F * rtb_Square_b[2];

  /* Update for DiscreteIntegrator: '<S102>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_b[2] += 0.002F * rtb_Divide_k_idx_2;

  /* Update for DiscreteIntegrator: '<S102>/Discrete-Time Integrator1' */
  Plant_DW.DiscreteTimeIntegrator1_DSTATE[2] += 0.002F * rtb_Sum_i[2];
  Plant_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* End of Outputs for SubSystem: '<Root>/Kinematic_Equation' */

  /* Outputs for Atomic SubSystem: '<Root>/Bus_Constructor' */
  /* Sqrt: '<S64>/Sqrt' incorporates:
   *  Math: '<S64>/Square'
   *  Sum: '<S64>/Sum of Elements'
   */
  rtb_Gain_kz = sqrtf(((rtb_MathFunction1_k * rtb_MathFunction1_k +
                        rtb_DiscreteTimeIntegrator_id_1 *
                        rtb_DiscreteTimeIntegrator_id_1) +
                       rtb_DiscreteTimeIntegrator_id_0 *
                       rtb_DiscreteTimeIntegrator_id_0) +
                      rtb_DiscreteTimeIntegrator_idx_ *
                      rtb_DiscreteTimeIntegrator_idx_);

  /* Product: '<S60>/Divide' */
  rtb_Divide_g[0] = rtb_MathFunction1_k / rtb_Gain_kz;
  rtb_Divide_g[1] = rtb_DiscreteTimeIntegrator_id_1 / rtb_Gain_kz;
  rtb_Divide_g[2] = rtb_DiscreteTimeIntegrator_id_0 / rtb_Gain_kz;
  rtb_Divide_g[3] = rtb_DiscreteTimeIntegrator_idx_ / rtb_Gain_kz;

  /* Math: '<S61>/Square' incorporates:
   *  Math: '<S62>/Square'
   *  Math: '<S63>/Square'
   */
  rtb_Multiply_g2_idx_1 = rtb_Divide_g[0] * rtb_Divide_g[0];

  /* Math: '<S61>/Square2' incorporates:
   *  Math: '<S62>/Square2'
   *  Math: '<S63>/Square2'
   */
  rtb_Multiply4_idx_1 = rtb_Divide_g[2] * rtb_Divide_g[2];

  /* Math: '<S61>/Square1' incorporates:
   *  Math: '<S62>/Square1'
   *  Math: '<S63>/Square1'
   */
  rtb_Gain_kz = rtb_Divide_g[1] * rtb_Divide_g[1];

  /* Math: '<S61>/Square3' incorporates:
   *  Math: '<S62>/Square3'
   *  Math: '<S63>/Square3'
   */
  rtb_Multiply4 = rtb_Divide_g[3] * rtb_Divide_g[3];

  /* Sum: '<S61>/Subtract' incorporates:
   *  Math: '<S61>/Square'
   *  Math: '<S61>/Square1'
   *  Math: '<S61>/Square2'
   *  Math: '<S61>/Square3'
   *  Sum: '<S61>/Add'
   *  Sum: '<S61>/Add1'
   */
  rtb_MatrixConcatenate1[0] = (rtb_Multiply_g2_idx_1 + rtb_Gain_kz) -
    (rtb_Multiply4_idx_1 + rtb_Multiply4);

  /* Product: '<S61>/Multiply' incorporates:
   *  Product: '<S62>/Multiply'
   */
  rtb_Square_l = rtb_Divide_g[1] * rtb_Divide_g[2];

  /* Product: '<S61>/Multiply1' incorporates:
   *  Product: '<S62>/Multiply1'
   */
  rtb_Add_j_tmp = rtb_Divide_g[0] * rtb_Divide_g[3];

  /* Gain: '<S61>/Gain' incorporates:
   *  Product: '<S61>/Multiply'
   *  Product: '<S61>/Multiply1'
   *  Sum: '<S61>/Subtract1'
   */
  rtb_MatrixConcatenate1[1] = (rtb_Square_l - rtb_Add_j_tmp) * 2.0F;

  /* Product: '<S61>/Multiply2' incorporates:
   *  Product: '<S63>/Multiply'
   */
  rtb_Add_j_tmp_2 = rtb_Divide_g[1] * rtb_Divide_g[3];

  /* Product: '<S61>/Multiply3' incorporates:
   *  Product: '<S63>/Multiply1'
   */
  rtb_Add_j_tmp_3 = rtb_Divide_g[0] * rtb_Divide_g[2];

  /* Gain: '<S61>/Gain1' incorporates:
   *  Product: '<S61>/Multiply2'
   *  Product: '<S61>/Multiply3'
   *  Sum: '<S61>/Add2'
   */
  rtb_MatrixConcatenate1[2] = (rtb_Add_j_tmp_2 + rtb_Add_j_tmp_3) * 2.0F;

  /* Gain: '<S62>/Gain' incorporates:
   *  Sum: '<S62>/Add3'
   */
  rtb_MatrixConcatenate1[3] = (rtb_Square_l + rtb_Add_j_tmp) * 2.0F;

  /* Sum: '<S62>/Subtract' incorporates:
   *  Sum: '<S62>/Add'
   *  Sum: '<S62>/Add1'
   */
  rtb_MatrixConcatenate1[4] = (rtb_Multiply_g2_idx_1 + rtb_Multiply4_idx_1) -
    (rtb_Gain_kz + rtb_Multiply4);

  /* Product: '<S62>/Multiply2' incorporates:
   *  Product: '<S63>/Multiply2'
   */
  rtb_Square_l = rtb_Divide_g[2] * rtb_Divide_g[3];

  /* Product: '<S62>/Multiply3' incorporates:
   *  Product: '<S63>/Multiply3'
   */
  rtb_Add_j_tmp = rtb_Divide_g[0] * rtb_Divide_g[1];

  /* Gain: '<S62>/Gain1' incorporates:
   *  Product: '<S62>/Multiply2'
   *  Product: '<S62>/Multiply3'
   *  Sum: '<S62>/Subtract1'
   */
  rtb_MatrixConcatenate1[5] = (rtb_Square_l - rtb_Add_j_tmp) * 2.0F;

  /* Gain: '<S63>/Gain' incorporates:
   *  Sum: '<S63>/Subtract2'
   */
  rtb_MatrixConcatenate1[6] = (rtb_Add_j_tmp_2 - rtb_Add_j_tmp_3) * 2.0F;

  /* Gain: '<S63>/Gain1' incorporates:
   *  Sum: '<S63>/Add2'
   */
  rtb_MatrixConcatenate1[7] = (rtb_Square_l + rtb_Add_j_tmp) * 2.0F;

  /* Sum: '<S63>/Subtract' incorporates:
   *  Sum: '<S63>/Add'
   *  Sum: '<S63>/Add1'
   */
  rtb_MatrixConcatenate1[8] = (rtb_Multiply_g2_idx_1 + rtb_Multiply4) -
    (rtb_Gain_kz + rtb_Multiply4_idx_1);

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
  for (i = 0; i < 9; i++) {
    Plant_Y.Extended_States.M_BO[i] = rtb_MatrixConcatenate1[i];
    Plant_Y.Extended_States.M_OB[i] = rtb_VectorConcatenate_f[i];
  }

  Plant_Y.Extended_States.quat[0] = rtb_MathFunction1_k;
  Plant_Y.Extended_States.quat[1] = rtb_DiscreteTimeIntegrator_id_1;
  Plant_Y.Extended_States.quat[2] = rtb_DiscreteTimeIntegrator_id_0;
  Plant_Y.Extended_States.quat[3] = rtb_DiscreteTimeIntegrator_idx_;
  Plant_Y.Extended_States.Va = rtb_Saturation;

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
   *  Constant: '<S104>/Constant'
   *  Constant: '<S104>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Math: '<S104>/Square'
   *  Product: '<S104>/Multiply'
   *  Product: '<S104>/Multiply1'
   *  Product: '<S104>/Multiply2'
   *  Product: '<S104>/Multiply3'
   *  Product: '<S108>/Divide'
   *  Sum: '<S104>/Add'
   *  Sum: '<S104>/Add1'
   *  Sum: '<S104>/Subtract2'
   *  Trigonometry: '<S104>/Atan2'
   */
  Plant_Y.Plant_States.phi = atan2f((rtb_Plant_States_vel_y_O *
    rtb_Plant_States_vel_z_O + rtb_Divide_ld * rtb_Multiply5_c) * 2.0F, 1.0F -
    (rtb_Plant_States_vel_z_O * rtb_Plant_States_vel_z_O + rtb_Add_ps) * 2.0F);

  /* End of Outputs for SubSystem: '<Root>/Bus_Constructor' */

  /* Saturate: '<S104>/Saturation' */
  if (rtb_Divide_k_idx_0 > 1.0F) {
    rtb_Divide_k_idx_0 = 1.0F;
  } else {
    if (rtb_Divide_k_idx_0 < -1.0F) {
      rtb_Divide_k_idx_0 = -1.0F;
    }
  }

  /* End of Saturate: '<S104>/Saturation' */

  /* Outputs for Atomic SubSystem: '<Root>/Bus_Constructor' */
  /* BusAssignment: '<S2>/Bus Assignment' incorporates:
   *  BusAssignment: '<S2>/Bus Assignment1'
   *  Constant: '<S104>/Constant'
   *  Constant: '<S104>/Constant1'
   *  Delay: '<Root>/Delay'
   *  Math: '<S104>/Square2'
   *  Product: '<S104>/Multiply10'
   *  Product: '<S104>/Multiply7'
   *  Product: '<S104>/Multiply8'
   *  Product: '<S104>/Multiply9'
   *  Product: '<S108>/Divide'
   *  Sum: '<S104>/Add2'
   *  Sum: '<S104>/Add3'
   *  Sum: '<S104>/Subtract1'
   *  Trigonometry: '<S104>/Asin'
   *  Trigonometry: '<S104>/Atan1'
   */
  Plant_Y.Plant_States.theta = asinf(rtb_Divide_k_idx_0);
  Plant_Y.Plant_States.psi = atan2f((rtb_Plant_States_vel_y_O * rtb_Multiply5_c
    + rtb_Plant_States_vel_z_O * rtb_Divide_ld) * 2.0F, 1.0F - (rtb_Multiply5_c *
    rtb_Multiply5_c + rtb_Add_ps) * 2.0F);

  /* End of Outputs for SubSystem: '<Root>/Kinematic_Equation' */
  Plant_Y.Plant_States.rot_x_B = rtb_Square_o5[0];
  Plant_Y.Plant_States.rot_y_B = rtb_Square_o5[1];
  Plant_Y.Plant_States.rot_z_B = rtb_Square_o5[2];
  Plant_Y.Plant_States.acc_x_O = rtb_Multiply_g2_idx_2;
  Plant_Y.Plant_States.acc_y_O = rtb_Divide_k_idx_1;
  Plant_Y.Plant_States.acc_z_O = rtb_Divide_k_idx_2;
  Plant_Y.Plant_States.vel_x_O = rtb_Sum_i[0];
  Plant_Y.Plant_States.vel_y_O = rtb_Sum_i[1];
  Plant_Y.Plant_States.vel_z_O = rtb_Sum_i[2];

  /* Trigonometry: '<S65>/Trigonometric Function1' incorporates:
   *  Delay: '<S59>/Delay1'
   *  Trigonometry: '<S65>/Trigonometric Function2'
   */
  rtb_TrigonometricFunction2 = cos(Plant_DW.Delay1_DSTATE_c[0]);

  /* Trigonometry: '<S65>/Trigonometric Function' incorporates:
   *  Delay: '<S59>/Delay1'
   */
  rtb_SumofElements = sin(Plant_DW.Delay1_DSTATE_c[0]);

  /* Sum: '<S65>/Subtract' incorporates:
   *  Constant: '<S65>/c'
   *  Math: '<S65>/u^2'
   *  Product: '<S65>/Product'
   */
  rtb_SumofElements = 1.0 - rtb_SumofElements * rtb_SumofElements *
    Plant_ConstB.Product1;

  /* Math: '<S65>/sqrt'
   *
   * About '<S65>/sqrt':
   *  Operator: sqrt
   */
  if (rtb_SumofElements < 0.0) {
    rtb_SumofElements = -sqrt(fabs(rtb_SumofElements));
  } else {
    rtb_SumofElements = sqrt(rtb_SumofElements);
  }

  /* End of Math: '<S65>/sqrt' */

  /* Product: '<S65>/Divide' incorporates:
   *  Constant: '<S65>/earth_radius'
   */
  rtb_SumofElements = 6.378137E+6 / rtb_SumofElements;

  /* Product: '<S65>/Product3' incorporates:
   *  Constant: '<S65>/constant2'
   *  Math: '<S65>/u^1'
   *  Product: '<S65>/Product2'
   *  Sum: '<S65>/Subtract2'
   *  Trigonometry: '<S65>/Trigonometric Function1'
   */
  rtb_SumofElements1 = (1.0 - rtb_TrigonometricFunction2 *
                        rtb_TrigonometricFunction2 * Plant_ConstB.Product1) *
    rtb_SumofElements;

  /* Sum: '<S65>/Add' incorporates:
   *  Delay: '<S59>/Delay1'
   */
  rtb_SumofElements1 += Plant_DW.Delay1_DSTATE_c[2];

  /* Sum: '<S65>/Add1' incorporates:
   *  Delay: '<S59>/Delay1'
   */
  rtb_SumofElements += Plant_DW.Delay1_DSTATE_c[2];

  /* Product: '<S65>/Product4' */
  rtb_SumofElements *= rtb_TrigonometricFunction2;

  /* BusAssignment: '<S2>/Bus Assignment1' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S2>/Gain'
   */
  Plant_Y.Plant_States.x_R = rtb_Sum_mj[0];
  Plant_Y.Plant_States.y_R = rtb_Sum_mj[1];
  Plant_Y.Plant_States.h_R = -rtb_Sum_mj[2];

  /* Signum: '<S66>/Sign' */
  if (rtb_SumofElements1 < 0.0) {
    rtb_Cl_xA = -1.0;
    rtb_Cm = -1.0;
  } else if (rtb_SumofElements1 > 0.0) {
    rtb_Cl_xA = 1.0;
    rtb_Cm = 1.0;
  } else {
    rtb_Cl_xA = rtb_SumofElements1;
    rtb_Cm = rtb_SumofElements1;
  }

  /* Switch: '<S66>/Switch' incorporates:
   *  Constant: '<S66>/Constant'
   */
  if (rtb_Cm == 0.0) {
    rtb_Cl_xA = 1.0;
  }

  /* Abs: '<S66>/Abs' */
  rtb_SumofElements1 = fabs(rtb_SumofElements1);

  /* Saturate: '<S66>/Saturation' */
  if (rtb_SumofElements1 > 1.0E+8) {
    rtb_SumofElements1 = 1.0E+8;
  } else {
    if (rtb_SumofElements1 < 1.0E-6) {
      rtb_SumofElements1 = 1.0E-6;
    }
  }

  /* Sum: '<S59>/Add' incorporates:
   *  Abs: '<S66>/Abs'
   *  DataTypeConversion: '<S59>/Data Type Conversion'
   *  Delay: '<S59>/Delay'
   *  Delay: '<S59>/Delay1'
   *  Product: '<S59>/Divide'
   *  Product: '<S66>/Product'
   *  Sum: '<S59>/Subtract'
   */
  Plant_DW.Delay1_DSTATE_c[0] += 1.0 / (rtb_SumofElements1 * rtb_Cl_xA) *
    (rtb_Sum_mj[0] - Plant_DW.Delay_DSTATE_f[0]);

  /* Update for Delay: '<S59>/Delay' incorporates:
   *  DataTypeConversion: '<S59>/Data Type Conversion'
   */
  Plant_DW.Delay_DSTATE_f[0] = rtb_Sum_mj[0];

  /* Signum: '<S66>/Sign' */
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

  /* Switch: '<S66>/Switch' incorporates:
   *  Constant: '<S66>/Constant'
   */
  if (rtb_SumofElements1 == 0.0) {
    rtb_Cl_xA = 1.0;
  }

  /* Abs: '<S66>/Abs' */
  rtb_SumofElements1 = fabs(rtb_SumofElements);

  /* Saturate: '<S66>/Saturation' */
  if (rtb_SumofElements1 > 1.0E+8) {
    rtb_SumofElements1 = 1.0E+8;
  } else {
    if (rtb_SumofElements1 < 1.0E-6) {
      rtb_SumofElements1 = 1.0E-6;
    }
  }

  /* Sum: '<S59>/Add' incorporates:
   *  Abs: '<S66>/Abs'
   *  DataTypeConversion: '<S59>/Data Type Conversion'
   *  Delay: '<S59>/Delay'
   *  Delay: '<S59>/Delay1'
   *  Product: '<S59>/Divide'
   *  Product: '<S66>/Product'
   *  Sum: '<S59>/Subtract'
   */
  Plant_DW.Delay1_DSTATE_c[1] += 1.0 / (rtb_SumofElements1 * rtb_Cl_xA) *
    (rtb_Sum_mj[1] - Plant_DW.Delay_DSTATE_f[1]);

  /* Update for Delay: '<S59>/Delay' incorporates:
   *  DataTypeConversion: '<S59>/Data Type Conversion'
   */
  Plant_DW.Delay_DSTATE_f[1] = rtb_Sum_mj[1];

  /* Sum: '<S59>/Add' incorporates:
   *  Abs: '<S66>/Abs'
   *  DataTypeConversion: '<S59>/Data Type Conversion'
   *  Delay: '<S59>/Delay'
   *  Delay: '<S59>/Delay1'
   *  Product: '<S59>/Divide'
   *  Sum: '<S59>/Subtract'
   */
  Plant_DW.Delay1_DSTATE_c[2] += -(rtb_Sum_mj[2] - Plant_DW.Delay_DSTATE_f[2]);

  /* Update for Delay: '<S59>/Delay' incorporates:
   *  DataTypeConversion: '<S59>/Data Type Conversion'
   */
  Plant_DW.Delay_DSTATE_f[2] = rtb_Sum_mj[2];

  /* BusAssignment: '<S2>/Bus Assignment1' incorporates:
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant2'
   *  Constant: '<S2>/Constant3'
   *  Delay: '<Root>/Delay'
   *  Delay: '<S57>/Delay'
   *  Delay: '<S59>/Delay1'
   */
  Plant_Y.Plant_States.lat = Plant_DW.Delay1_DSTATE_c[0];
  Plant_Y.Plant_States.lon = Plant_DW.Delay1_DSTATE_c[1];
  Plant_Y.Plant_States.alt = Plant_DW.Delay1_DSTATE_c[2];
  Plant_Y.Plant_States.lat_0 = 0.65673;
  Plant_Y.Plant_States.lon_0 = -2.1361;
  Plant_Y.Plant_States.alt_0 = 4.5;
  Plant_Y.Plant_States.timestamp = Plant_DW.Delay_DSTATE_h;

  /* Sum: '<S57>/Sum' incorporates:
   *  Constant: '<S57>/dt'
   *  Delay: '<S57>/Delay'
   */
  Plant_DW.Delay_DSTATE_h += PLANT_EXPORT.period;

  /* End of Outputs for SubSystem: '<Root>/Bus_Constructor' */

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_Model' */
  /* Outputs for Atomic SubSystem: '<S6>/Sensor_Airspeed' */
  /* BusAssignment: '<S133>/Bus Assignment' incorporates:
   *  Constant: '<S133>/Constant'
   *  Delay: '<Root>/Delay'
   *  Gain: '<S132>/Gain'
   *  Math: '<S132>/Square'
   *  Memory: '<S126>/Memory1'
   */
  rtb_BusAssignment_f = Plant_rtZAirSpeed_Bus;
  rtb_BusAssignment_f.timestamp = Plant_DW.Memory1_PreviousInput;
  rtb_BusAssignment_f.diff_pressure = Plant_Y.Extended_States.Va *
    Plant_Y.Extended_States.Va * 0.6125F;

  /* RateTransition: '<S133>/Rate Transition' */
  if (Plant_M->Timing.TaskCounters.TID[1] == 0) {
    Plant_B.RateTransition_e = rtb_BusAssignment_f;
  }

  /* End of RateTransition: '<S133>/Rate Transition' */
  /* End of Outputs for SubSystem: '<S6>/Sensor_Airspeed' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_Barometer' */
  /* Saturate: '<S138>/Limit  altitude  to troposhere' incorporates:
   *  DataTypeConversion: '<S136>/Data Type Conversion'
   *  Delay: '<Root>/Delay'
   */
  if ((real32_T)Plant_Y.Plant_States.alt > 11000.0F) {
    rtb_Gain_kz = 11000.0F;
  } else if ((real32_T)Plant_Y.Plant_States.alt < 0.0F) {
    rtb_Gain_kz = 0.0F;
  } else {
    rtb_Gain_kz = (real32_T)Plant_Y.Plant_States.alt;
  }

  /* End of Saturate: '<S138>/Limit  altitude  to troposhere' */

  /* Sum: '<S138>/Sum1' incorporates:
   *  Constant: '<S138>/Sea Level  Temperature'
   *  Gain: '<S138>/Lapse Rate'
   */
  rtb_Saturation = 288.15F - 0.0065F * rtb_Gain_kz;

  /* Sum: '<S138>/Sum' incorporates:
   *  Constant: '<S138>/Altitude of Troposphere'
   *  DataTypeConversion: '<S136>/Data Type Conversion'
   *  Delay: '<Root>/Delay'
   */
  rtb_MathFunction1_k = 11000.0F - (real32_T)Plant_Y.Plant_States.alt;

  /* Saturate: '<S138>/Limit  altitude  to Stratosphere' incorporates:
   *  Constant: '<S138>/Altitude of Troposphere'
   *  DataTypeConversion: '<S136>/Data Type Conversion'
   *  Delay: '<Root>/Delay'
   *  Sum: '<S138>/Sum'
   */
  if (11000.0F - (real32_T)Plant_Y.Plant_States.alt > 0.0F) {
    rtb_MathFunction1_k = 0.0F;
  } else {
    if (11000.0F - (real32_T)Plant_Y.Plant_States.alt < -9000.0F) {
      rtb_MathFunction1_k = -9000.0F;
    }
  }

  /* End of Saturate: '<S138>/Limit  altitude  to Stratosphere' */

  /* Product: '<S138>/Product2' incorporates:
   *  Constant: '<S138>/Constant'
   *  Gain: '<S138>/1//T0'
   *  Gain: '<S138>/P0'
   *  Gain: '<S138>/g//R'
   *  Math: '<S138>/(T//T0)^(g//LR) '
   *  Math: '<S138>/Stratosphere Model'
   *  Product: '<S138>/Product1'
   *
   * About '<S138>/Stratosphere Model':
   *  Operator: exp
   */
  rtb_DiscreteTimeIntegrator_id_1 = powf(0.00347041478F * rtb_Saturation,
    5.25587559F) * 101325.0F * expf(1.0F / rtb_Saturation * (0.0341631919F *
    rtb_MathFunction1_k));

  /* S-Function (sdsprandsrc2): '<S140>/Random Source' */
  RandSrc_GZ_R(&rtb_MathFunction1_k, &Plant_ConstP.pooled26, 1,
               &Plant_ConstP.pooled41, 1, Plant_DW.RandomSource_STATE_DWORK_fn,
               1, 1);

  /* BusAssignment: '<S135>/Bus Assignment' incorporates:
   *  Constant: '<S135>/Constant2'
   *  DataTypeConversion: '<S135>/Data Type Conversion1'
   *  Memory: '<S126>/Memory1'
   *  Saturate: '<S137>/Saturation'
   *  Sum: '<S135>/Sum1'
   *  Sum: '<S137>/Add'
   */
  rtb_BusAssignment_c.timestamp = Plant_DW.Memory1_PreviousInput;
  rtb_BusAssignment_c.pressure = rtb_DiscreteTimeIntegrator_id_1 +
    rtb_MathFunction1_k;
  rtb_BusAssignment_c.temperature = (real32_T)(rtb_Saturation - 273.15);

  /* RateTransition: '<S135>/Rate Transition' */
  if (Plant_M->Timing.TaskCounters.TID[2] == 0) {
    Plant_B.RateTransition_p = rtb_BusAssignment_c;
  }

  /* End of RateTransition: '<S135>/Rate Transition' */
  /* End of Outputs for SubSystem: '<S6>/Sensor_Barometer' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_GPS' */
  /* Trigonometry: '<S153>/Sin' incorporates:
   *  Delay: '<S146>/Delay'
   */
  rtb_SumofElements = sin(Plant_DW.Delay_DSTATE[0]);

  /* Math: '<S153>/Square1' */
  rtb_SumofElements *= rtb_SumofElements;

  /* Product: '<S153>/Multiply1' incorporates:
   *  Product: '<S153>/Multiply'
   */
  rtb_Cl_xA = Plant_ConstB.ff * rtb_SumofElements;

  /* Product: '<S153>/Divide' incorporates:
   *  Constant: '<S153>/Constant'
   *  Constant: '<S153>/R'
   *  Sqrt: '<S153>/Sqrt'
   *  Sum: '<S153>/Sum1'
   */
  rtb_SumofElements = 6.378137E+6 / sqrt(1.0 - rtb_Cl_xA);

  /* Trigonometry: '<S153>/Cos' incorporates:
   *  Delay: '<S146>/Delay'
   */
  rtb_SumofElements1 = cos(Plant_DW.Delay_DSTATE[0]);

  /* S-Function (sdsprandsrc2): '<S149>/Random Source' */
  RandSrc_GZ_R(rtb_RandomSource, &Plant_ConstP.pooled26, 1,
               Plant_ConstP.RandomSource_VarianceRTP, 3,
               Plant_DW.RandomSource_STATE_DWORK_f2, 3, 1);

  /* Sum: '<S147>/Sum2' incorporates:
   *  Constant: '<S153>/Constant1'
   *  Delay: '<S146>/Delay'
   *  Product: '<S150>/Divide2'
   *  Product: '<S153>/Multiply1'
   *  Product: '<S153>/Multiply2'
   *  Product: '<S153>/Product3'
   *  Sum: '<S153>/Sum2'
   */
  rtb_Cl_xA = rtb_RandomSource[0] / (1.0 / (1.0 - rtb_Cl_xA) * Plant_ConstB.Sum4
    * rtb_SumofElements) + Plant_DW.Delay_DSTATE[0];
  rtb_Cm = rtb_RandomSource[1] / (rtb_SumofElements * rtb_SumofElements1) +
    Plant_DW.Delay_DSTATE[1];
  rtb_Divide_e_idx_1 = rtb_RandomSource[2] / -1.0 + Plant_DW.Delay_DSTATE[2];

  /* S-Function (sdsprandsrc2): '<S149>/Random Source1' */
  RandSrc_GZ_R(rtb_RandomSource1, &Plant_ConstP.pooled26, 1,
               Plant_ConstP.RandomSource1_VarianceRTP, 3,
               Plant_DW.RandomSource1_STATE_DWORK, 3, 1);

  /* Sum: '<S147>/Sum1' incorporates:
   *  Delay: '<S146>/Delay1'
   */
  rtb_Sum_jq[0] = rtb_RandomSource1[0] + Plant_DW.Delay1_DSTATE_j[0];
  rtb_Sum_jq[1] = rtb_RandomSource1[1] + Plant_DW.Delay1_DSTATE_j[1];
  rtb_Sum_jq[2] = rtb_RandomSource1[2] + Plant_DW.Delay1_DSTATE_j[2];

  /* DiscreteFir: '<S152>/Discrete FIR Filter' */
  rtb_Multiply5_j[0] = rtb_Sum_jq[0] * 0.5F +
    Plant_DW.DiscreteFIRFilter_states_i[0] * 0.5F;
  rtb_Multiply5_j[1] = rtb_Sum_jq[1] * 0.5F +
    Plant_DW.DiscreteFIRFilter_states_i[1] * 0.5F;

  /* Gain: '<S141>/Gain6' incorporates:
   *  Math: '<S148>/Math Function'
   *  Product: '<S148>/Matrix Multiply'
   *  Sqrt: '<S148>/Sqrt'
   *  Switch: '<S148>/Switch'
   */
  rtb_SumofElements = fmod(floor(sqrtf(rtb_RandomSource[0] * rtb_RandomSource[0]
    + rtb_RandomSource[1] * rtb_RandomSource[1]) * 1000.0), 4.294967296E+9);

  /* DataTypeConversion: '<S141>/Data Type Conversion' incorporates:
   *  Delay: '<S147>/Delay1'
   */
  rtb_SumofElements1 = fmod(floor(Plant_DW.Delay1_DSTATE[0]), 256.0);

  /* Gain: '<S141>/Gain4' incorporates:
   *  DiscreteFir: '<S151>/Discrete FIR Filter'
   */
  rtb_Cl_zA = fmod(floor((rtb_Divide_e_idx_1 * 0.5 +
    Plant_DW.DiscreteFIRFilter_states[2] * 0.5) * 1000.0), 4.294967296E+9);
  i = rtb_Cl_zA < 0.0 ? -(int32_T)(uint32_T)-rtb_Cl_zA : (int32_T)(uint32_T)
    rtb_Cl_zA;

  /* Gain: '<S141>/Gain5' incorporates:
   *  Math: '<S148>/Math Function2'
   *  Product: '<S148>/Matrix Multiply2'
   *  Sqrt: '<S148>/Sqrt2'
   *  Switch: '<S148>/Switch1'
   */
  rtb_Cl_zA = fmod(floor(sqrtf(rtb_RandomSource[2] * rtb_RandomSource[2]) *
    1000.0), 4.294967296E+9);

  /* BusAssignment: '<S141>/Bus Assignment' incorporates:
   *  Constant: '<S141>/Constant10'
   *  Constant: '<S141>/Constant11'
   *  Constant: '<S141>/Constant12'
   *  Constant: '<S141>/Constant2'
   *  Constant: '<S141>/Constant3'
   *  Constant: '<S141>/Constant4'
   *  Constant: '<S141>/Constant5'
   *  Constant: '<S141>/Constant6'
   *  Constant: '<S141>/Constant7'
   *  Constant: '<S141>/Constant8'
   *  Constant: '<S141>/Constant9'
   *  DataTypeConversion: '<S141>/Data Type Conversion'
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

  /* DataTypeConversion: '<S141>/Data Type Conversion1' incorporates:
   *  Delay: '<S147>/Delay'
   */
  rtb_SumofElements1 = fmod(floor(Plant_DW.Delay_DSTATE_b[0]), 256.0);

  /* BusAssignment: '<S141>/Bus Assignment' incorporates:
   *  DataTypeConversion: '<S141>/Data Type Conversion1'
   */
  rtb_BusAssignment_e.numSV = (uint8_T)(rtb_SumofElements1 < 0.0 ? (int32_T)
    (uint8_T)-(int8_T)(uint8_T)-rtb_SumofElements1 : (int32_T)(uint8_T)
    rtb_SumofElements1);

  /* Gain: '<S141>/Gain' incorporates:
   *  DiscreteFir: '<S151>/Discrete FIR Filter'
   *  Gain: '<S141>/Gain2'
   */
  rtb_SumofElements1 = fmod(floor((rtb_Cl_xA * 0.5 +
    Plant_DW.DiscreteFIRFilter_states[0] * 0.5) * 57.295779513082323 * 1.0E+7),
    4.294967296E+9);

  /* BusAssignment: '<S141>/Bus Assignment' incorporates:
   *  Gain: '<S141>/Gain'
   */
  rtb_BusAssignment_e.lon = rtb_SumofElements1 < 0.0 ? -(int32_T)(uint32_T)
    -rtb_SumofElements1 : (int32_T)(uint32_T)rtb_SumofElements1;

  /* Gain: '<S141>/Gain1' incorporates:
   *  DiscreteFir: '<S151>/Discrete FIR Filter'
   *  Gain: '<S141>/Gain3'
   */
  rtb_SumofElements1 = fmod(floor((rtb_Cm * 0.5 +
    Plant_DW.DiscreteFIRFilter_states[1] * 0.5) * 57.295779513082323 * 1.0E+7),
    4.294967296E+9);

  /* BusAssignment: '<S141>/Bus Assignment' incorporates:
   *  Gain: '<S141>/Gain1'
   *  Gain: '<S141>/Gain5'
   *  Gain: '<S141>/Gain6'
   */
  rtb_BusAssignment_e.lat = rtb_SumofElements1 < 0.0 ? -(int32_T)(uint32_T)
    -rtb_SumofElements1 : (int32_T)(uint32_T)rtb_SumofElements1;
  rtb_BusAssignment_e.height = i;
  rtb_BusAssignment_e.hMSL = i;
  rtb_BusAssignment_e.hAcc = rtb_SumofElements < 0.0 ? (uint32_T)-(int32_T)
    (uint32_T)-rtb_SumofElements : (uint32_T)rtb_SumofElements;
  rtb_BusAssignment_e.vAcc = rtb_Cl_zA < 0.0 ? (uint32_T)-(int32_T)(uint32_T)
    -rtb_Cl_zA : (uint32_T)rtb_Cl_zA;

  /* Gain: '<S141>/Gain7' */
  rtb_Gain_kz = fmodf(floorf(1000.0F * rtb_Multiply5_j[0]), 4.2949673E+9F);

  /* BusAssignment: '<S141>/Bus Assignment' incorporates:
   *  Gain: '<S141>/Gain7'
   */
  rtb_BusAssignment_e.velN = rtb_Gain_kz < 0.0F ? -(int32_T)(uint32_T)
    -rtb_Gain_kz : (int32_T)(uint32_T)rtb_Gain_kz;

  /* Gain: '<S141>/Gain8' */
  rtb_Gain_kz = fmodf(floorf(1000.0F * rtb_Multiply5_j[1]), 4.2949673E+9F);

  /* BusAssignment: '<S141>/Bus Assignment' incorporates:
   *  Gain: '<S141>/Gain8'
   */
  rtb_BusAssignment_e.velE = rtb_Gain_kz < 0.0F ? -(int32_T)(uint32_T)
    -rtb_Gain_kz : (int32_T)(uint32_T)rtb_Gain_kz;

  /* Gain: '<S141>/Gain9' incorporates:
   *  DiscreteFir: '<S152>/Discrete FIR Filter'
   */
  rtb_Gain_kz = fmodf(floorf((rtb_Sum_jq[2] * 0.5F +
    Plant_DW.DiscreteFIRFilter_states_i[2] * 0.5F) * 1000.0F), 4.2949673E+9F);

  /* BusAssignment: '<S141>/Bus Assignment' incorporates:
   *  Constant: '<S141>/Constant15'
   *  Gain: '<S141>/Gain11'
   *  Gain: '<S141>/Gain9'
   *  Math: '<S143>/Math Function'
   *  Math: '<S143>/Math Function1'
   *  Saturate: '<S143>/Saturation'
   *  Sqrt: '<S143>/Sqrt'
   *  Sum: '<S143>/Add'
   */
  rtb_BusAssignment_e.velD = rtb_Gain_kz < 0.0F ? -(int32_T)(uint32_T)
    -rtb_Gain_kz : (int32_T)(uint32_T)rtb_Gain_kz;
  rtb_BusAssignment_e.gSpeed = (int32_T)(uint32_T)fmodf(floorf(sqrtf(fmaxf
    (rtb_Multiply5_j[0] * rtb_Multiply5_j[0] + rtb_Multiply5_j[1] *
     rtb_Multiply5_j[1], 0.0F)) * 1000.0F), 4.2949673E+9F);
  rtb_BusAssignment_e.heading = 0;

  /* Gain: '<S141>/Gain10' incorporates:
   *  Math: '<S148>/Math Function1'
   *  Product: '<S148>/Matrix Multiply1'
   *  Sqrt: '<S148>/Sqrt1'
   *  Switch: '<S148>/Switch2'
   */
  rtb_SumofElements = fmod(floor(sqrtf((rtb_RandomSource1[0] *
    rtb_RandomSource1[0] + rtb_RandomSource1[1] * rtb_RandomSource1[1]) +
    rtb_RandomSource1[2] * rtb_RandomSource1[2]) * 1000.0), 4.294967296E+9);

  /* BusAssignment: '<S141>/Bus Assignment' incorporates:
   *  Constant: '<S141>/Constant14'
   *  Constant: '<S141>/Constant16'
   *  Constant: '<S141>/Constant17'
   *  Gain: '<S141>/Gain10'
   *  Memory: '<S126>/Memory1'
   */
  rtb_BusAssignment_e.sAcc = rtb_SumofElements < 0.0 ? (uint32_T)-(int32_T)
    (uint32_T)-rtb_SumofElements : (uint32_T)rtb_SumofElements;
  rtb_BusAssignment_e.headingAcc = 0U;
  rtb_BusAssignment_e.pDOP = 0U;
  rtb_BusAssignment_e.reserved2 = 0U;
  rtb_BusAssignment_e.timestamp = Plant_DW.Memory1_PreviousInput;

  /* RateTransition: '<S141>/Rate Transition' */
  if (Plant_M->Timing.TaskCounters.TID[3] == 0) {
    Plant_B.RateTransition = rtb_BusAssignment_e;
  }

  /* End of RateTransition: '<S141>/Rate Transition' */

  /* Update for Delay: '<S146>/Delay' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S146>/ConcatBufferAtVector ConcatenateIn1'
   */
  for (i = 0; i < 74; i++) {
    rtb_Saturation1_idx_1 = (i + 1) * 3;
    Plant_DW.Delay_DSTATE[i * 3] = Plant_DW.Delay_DSTATE[rtb_Saturation1_idx_1];
    Plant_DW.Delay_DSTATE[i * 3 + 1] =
      Plant_DW.Delay_DSTATE[rtb_Saturation1_idx_1 + 1];
    Plant_DW.Delay_DSTATE[i * 3 + 2] =
      Plant_DW.Delay_DSTATE[rtb_Saturation1_idx_1 + 2];
  }

  /* Update states */
  Plant_DW.Delay_DSTATE[222] = Plant_Y.Plant_States.lon;

  /* Update for DiscreteFir: '<S151>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states[0] = rtb_Cl_xA;

  /* Update for Delay: '<S146>/Delay' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S146>/ConcatBufferAtVector ConcatenateIn2'
   */
  Plant_DW.Delay_DSTATE[223] = Plant_Y.Plant_States.lat;

  /* Update for DiscreteFir: '<S151>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states[1] = rtb_Cm;

  /* Update for Delay: '<S146>/Delay' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S146>/ConcatBufferAtVector ConcatenateIn3'
   */
  Plant_DW.Delay_DSTATE[224] = Plant_Y.Plant_States.alt;

  /* Update for DiscreteFir: '<S151>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states[2] = rtb_Divide_e_idx_1;

  /* Update for Delay: '<S146>/Delay1' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S146>/ConcatBufferAtVector Concatenate1In1'
   */
  for (i = 0; i < 49; i++) {
    rtb_Saturation1_idx_1 = (i + 1) * 3;
    Plant_DW.Delay1_DSTATE_j[i * 3] =
      Plant_DW.Delay1_DSTATE_j[rtb_Saturation1_idx_1];
    Plant_DW.Delay1_DSTATE_j[i * 3 + 1] =
      Plant_DW.Delay1_DSTATE_j[rtb_Saturation1_idx_1 + 1];
    Plant_DW.Delay1_DSTATE_j[i * 3 + 2] =
      Plant_DW.Delay1_DSTATE_j[rtb_Saturation1_idx_1 + 2];
  }

  /* Update states */
  Plant_DW.Delay1_DSTATE_j[147] = Plant_Y.Plant_States.vel_x_O;

  /* Update for DiscreteFir: '<S152>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states_i[0] = rtb_Sum_jq[0];

  /* Update for Delay: '<S146>/Delay1' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S146>/ConcatBufferAtVector Concatenate1In2'
   */
  Plant_DW.Delay1_DSTATE_j[148] = Plant_Y.Plant_States.vel_y_O;

  /* Update for DiscreteFir: '<S152>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states_i[1] = rtb_Sum_jq[1];

  /* Update for Delay: '<S146>/Delay1' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S146>/ConcatBufferAtVector Concatenate1In3'
   */
  Plant_DW.Delay1_DSTATE_j[149] = Plant_Y.Plant_States.vel_z_O;

  /* Update for DiscreteFir: '<S152>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states_i[2] = rtb_Sum_jq[2];
  for (i = 0; i < 249; i++) {
    /* Update for Delay: '<S147>/Delay1' */
    Plant_DW.Delay1_DSTATE[i] = Plant_DW.Delay1_DSTATE[i + 1];

    /* Update for Delay: '<S147>/Delay' */
    Plant_DW.Delay_DSTATE_b[i] = Plant_DW.Delay_DSTATE_b[i + 1];
  }

  /* Update for Delay: '<S147>/Delay1' incorporates:
   *  Constant: '<S147>/Constant2'
   */
  Plant_DW.Delay1_DSTATE[249] = 3.0;

  /* Update for Delay: '<S147>/Delay' incorporates:
   *  Constant: '<S147>/Constant1'
   */
  Plant_DW.Delay_DSTATE_b[249] = 16.0;

  /* End of Outputs for SubSystem: '<S6>/Sensor_GPS' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_IMU' */
  /* Outputs for Atomic SubSystem: '<S158>/Vibration_Model' */
  /* Outputs for Atomic SubSystem: '<S169>/Vibration_Model' */
  /* Product: '<S175>/Divide2' incorporates:
   *  Constant: '<S175>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Product: '<S164>/Divide2'
   */
  rtb_Cl_xA = Plant_Y.Extended_States.prop_vel[0] / 1047.1975511965977;

  /* End of Outputs for SubSystem: '<S158>/Vibration_Model' */

  /* Math: '<S175>/u^2' */
  rtb_Cm = rtb_Cl_xA * rtb_Cl_xA;

  /* Product: '<S171>/Product2' incorporates:
   *  DiscreteIntegrator: '<S171>/Discrete-Time Integrator'
   *  Trigonometry: '<S171>/Trigonometric Function2'
   */
  rtb_SumofElements1 = arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[0]) *
    rtb_Cm;

  /* Math: '<S175>/u^2' incorporates:
   *  DiscreteIntegrator: '<S171>/Discrete-Time Integrator'
   *  Product: '<S171>/Product1'
   *  Trigonometry: '<S171>/Trigonometric Function1'
   */
  rtb_Divide_e_idx_1 = arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[0]) *
    rtb_Cm;

  /* Product: '<S175>/Divide2' incorporates:
   *  Constant: '<S175>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Product: '<S164>/Divide2'
   */
  rtb_Cl_zA = rtb_Cl_xA;

  /* Outputs for Atomic SubSystem: '<S158>/Vibration_Model' */
  rtb_Cl_xA = Plant_Y.Extended_States.prop_vel[1] / 1047.1975511965977;

  /* End of Outputs for SubSystem: '<S158>/Vibration_Model' */

  /* Math: '<S175>/u^2' */
  rtb_Cm = rtb_Cl_xA * rtb_Cl_xA;

  /* Product: '<S171>/Product2' incorporates:
   *  DiscreteIntegrator: '<S171>/Discrete-Time Integrator'
   *  Trigonometry: '<S171>/Trigonometric Function2'
   */
  rtb_SumofElements = arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[1]) *
    rtb_Cm;

  /* Math: '<S175>/u^2' incorporates:
   *  DiscreteIntegrator: '<S171>/Discrete-Time Integrator'
   *  Product: '<S171>/Product1'
   *  Trigonometry: '<S171>/Trigonometric Function1'
   */
  rtb_TrigonometricFunction2 = arm_cos_f32
    (Plant_DW.DiscreteTimeIntegrator_DSTATE[1]) * rtb_Cm;

  /* Product: '<S175>/Divide2' incorporates:
   *  Constant: '<S175>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Product: '<S164>/Divide2'
   */
  rtb_Cnr = rtb_Cl_xA;

  /* Outputs for Atomic SubSystem: '<S158>/Vibration_Model' */
  rtb_Cl_xA = Plant_Y.Extended_States.prop_vel[2] / 1047.1975511965977;

  /* End of Outputs for SubSystem: '<S158>/Vibration_Model' */

  /* Math: '<S175>/u^2' */
  rtb_Cm = rtb_Cl_xA * rtb_Cl_xA;

  /* Product: '<S175>/Divide2' incorporates:
   *  Constant: '<S175>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Product: '<S164>/Divide2'
   */
  rtb_Cl_yA = rtb_Cl_xA;

  /* Outputs for Atomic SubSystem: '<S158>/Vibration_Model' */
  rtb_Cl_xA = Plant_Y.Extended_States.prop_vel[3] / 1047.1975511965977;

  /* Math: '<S175>/u^2' incorporates:
   *  Math: '<S164>/u^2'
   */
  rtb_Cl_xA *= rtb_Cl_xA;

  /* End of Outputs for SubSystem: '<S158>/Vibration_Model' */

  /* Sum: '<S171>/Sum of Elements' incorporates:
   *  DiscreteIntegrator: '<S171>/Discrete-Time Integrator'
   *  Math: '<S175>/u^2'
   *  Product: '<S171>/Product2'
   *  Trigonometry: '<S171>/Trigonometric Function2'
   */
  rtb_SumofElements1 = ((rtb_SumofElements1 + rtb_SumofElements) + arm_sin_f32
                        (Plant_DW.DiscreteTimeIntegrator_DSTATE[2]) * rtb_Cm) +
    arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[3]) * rtb_Cl_xA;

  /* Sum: '<S171>/Sum of Elements1' incorporates:
   *  DiscreteIntegrator: '<S171>/Discrete-Time Integrator'
   *  Math: '<S175>/u^2'
   *  Product: '<S171>/Product1'
   *  Trigonometry: '<S171>/Trigonometric Function1'
   */
  rtb_SumofElements = ((rtb_Divide_e_idx_1 + rtb_TrigonometricFunction2) +
                       arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[2]) *
                       rtb_Cm) + arm_cos_f32
    (Plant_DW.DiscreteTimeIntegrator_DSTATE[3]) * rtb_Cl_xA;

  /* Outputs for Atomic SubSystem: '<S158>/Vibration_Model' */
  /* Update for DiscreteIntegrator: '<S171>/Discrete-Time Integrator' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S160>/Discrete-Time Integrator'
   */
  rtb_Divide_ld = 0.002F * Plant_Y.Extended_States.prop_vel[0];

  /* End of Outputs for SubSystem: '<S158>/Vibration_Model' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE[0] += rtb_Divide_ld;

  /* End of Outputs for SubSystem: '<S169>/Vibration_Model' */
  /* End of Outputs for SubSystem: '<S6>/Sensor_IMU' */
  /* End of Outputs for SubSystem: '<Root>/Sensor_Model' */
  rtb_Divide_k_idx_0 = rtb_Divide_ld;

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_Model' */
  /* Outputs for Atomic SubSystem: '<S6>/Sensor_IMU' */
  /* Outputs for Atomic SubSystem: '<S158>/Vibration_Model' */
  /* Outputs for Atomic SubSystem: '<S169>/Vibration_Model' */
  /* Update for DiscreteIntegrator: '<S171>/Discrete-Time Integrator' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S160>/Discrete-Time Integrator'
   */
  rtb_Divide_ld = 0.002F * Plant_Y.Extended_States.prop_vel[1];

  /* End of Outputs for SubSystem: '<S158>/Vibration_Model' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE[1] += rtb_Divide_ld;

  /* End of Outputs for SubSystem: '<S169>/Vibration_Model' */
  /* End of Outputs for SubSystem: '<S6>/Sensor_IMU' */
  /* End of Outputs for SubSystem: '<Root>/Sensor_Model' */
  rtb_Divide_k_idx_1 = rtb_Divide_ld;

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_Model' */
  /* Outputs for Atomic SubSystem: '<S6>/Sensor_IMU' */
  /* Outputs for Atomic SubSystem: '<S158>/Vibration_Model' */
  /* Outputs for Atomic SubSystem: '<S169>/Vibration_Model' */
  /* Update for DiscreteIntegrator: '<S171>/Discrete-Time Integrator' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S160>/Discrete-Time Integrator'
   */
  rtb_Divide_ld = 0.002F * Plant_Y.Extended_States.prop_vel[2];

  /* End of Outputs for SubSystem: '<S158>/Vibration_Model' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE[2] += rtb_Divide_ld;

  /* End of Outputs for SubSystem: '<S169>/Vibration_Model' */
  /* End of Outputs for SubSystem: '<S6>/Sensor_IMU' */
  /* End of Outputs for SubSystem: '<Root>/Sensor_Model' */
  rtb_Divide_k_idx_2 = rtb_Divide_ld;

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_Model' */
  /* Outputs for Atomic SubSystem: '<S6>/Sensor_IMU' */
  /* Outputs for Atomic SubSystem: '<S158>/Vibration_Model' */
  /* Outputs for Atomic SubSystem: '<S169>/Vibration_Model' */
  /* Update for DiscreteIntegrator: '<S171>/Discrete-Time Integrator' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S160>/Discrete-Time Integrator'
   */
  rtb_Divide_ld = 0.002F * Plant_Y.Extended_States.prop_vel[3];

  /* End of Outputs for SubSystem: '<S158>/Vibration_Model' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE[3] += rtb_Divide_ld;

  /* Switch: '<S169>/Switch' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S171>/Gain2'
   *  Gain: '<S171>/Gain4'
   *  Product: '<S171>/Divide'
   *  SignalConversion: '<S171>/ConcatBufferAtVector ConcatenateIn1'
   *  SignalConversion: '<S173>/ConcatBufferAtVector ConcatenateIn1'
   *  SignalConversion: '<S173>/ConcatBufferAtVector ConcatenateIn2'
   *  SignalConversion: '<S173>/ConcatBufferAtVector ConcatenateIn3'
   *  Sum: '<S169>/Sum'
   *  Sum: '<S171>/Sum'
   *  Sum: '<S171>/Sum of Elements1'
   */
  rtb_Multiply5_j[0] = (real32_T)(rtb_SumofElements1 / 4.0 * 0.5 +
    Plant_Y.Plant_States.rot_x_B);
  rtb_Multiply5_j[1] = (real32_T)(rtb_SumofElements / 4.0 * 0.5 +
    Plant_Y.Plant_States.rot_y_B);
  rtb_Multiply5_c = (real32_T)((rtb_SumofElements1 + rtb_SumofElements) * 0.5 /
    4.0 * 0.5 + Plant_Y.Plant_States.rot_z_B);

  /* End of Outputs for SubSystem: '<S169>/Vibration_Model' */

  /* Sum: '<S177>/Sum' incorporates:
   *  Product: '<S177>/Product'
   */
  for (i = 0; i < 3; i++) {
    rtb_RandomSource[i] = (Plant_ConstB.Add_k[i + 3] * rtb_Multiply5_j[1] +
      Plant_ConstB.Add_k[i] * rtb_Multiply5_j[0]) + Plant_ConstB.Add_k[i + 6] *
      rtb_Multiply5_c;
  }

  /* End of Sum: '<S177>/Sum' */

  /* DiscreteIntegrator: '<S176>/Discrete-Time Integrator5' */
  if (Plant_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[0] = rtb_RandomSource[0];
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[1] = rtb_RandomSource[1];
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[2] = rtb_RandomSource[2];
  }

  /* S-Function (sdsprandsrc2): '<S167>/Random Source' */
  RandSrc_GZ_R(rtb_MathFunction, &Plant_ConstP.pooled26, 1,
               Plant_ConstP.RandomSource_VarianceRTP_h, 3,
               Plant_DW.RandomSource_STATE_DWORK_f, 3, 1);

  /* S-Function (sdsprandsrc2): '<S178>/Random Source' */
  RandSrc_GZ_R(rtb_Sum_ok, &Plant_ConstP.pooled26, 1,
               Plant_ConstP.RandomSource_VarianceRTP_o, 3,
               Plant_DW.RandomSource_STATE_DWORK_p, 3, 1);

  /* Saturate: '<S170>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S176>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[0] > 34.9065857F) {
    rtb_Gain_kz = 34.9065857F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[0] < -34.9065857F) {
    rtb_Gain_kz = -34.9065857F;
  } else {
    rtb_Gain_kz = Plant_DW.DiscreteTimeIntegrator5_DSTATE[0];
  }

  /* Sum: '<S170>/Sum' */
  rtb_Add_hg[0] = rtb_Gain_kz + rtb_Sum_ok[0];

  /* Saturate: '<S170>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S176>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[1] > 34.9065857F) {
    rtb_Gain_kz = 34.9065857F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[1] < -34.9065857F) {
    rtb_Gain_kz = -34.9065857F;
  } else {
    rtb_Gain_kz = Plant_DW.DiscreteTimeIntegrator5_DSTATE[1];
  }

  /* Sum: '<S170>/Sum' */
  rtb_Add_hg[1] = rtb_Gain_kz + rtb_Sum_ok[1];

  /* Saturate: '<S170>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S176>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[2] > 34.9065857F) {
    rtb_Gain_kz = 34.9065857F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[2] < -34.9065857F) {
    rtb_Gain_kz = -34.9065857F;
  } else {
    rtb_Gain_kz = Plant_DW.DiscreteTimeIntegrator5_DSTATE[2];
  }

  /* Sum: '<S170>/Sum' */
  rtb_Add_hg[2] = rtb_Gain_kz + rtb_Sum_ok[2];

  /* Outputs for Atomic SubSystem: '<S158>/Vibration_Model' */
  /* Math: '<S164>/u^2' incorporates:
   *  Product: '<S164>/Divide2'
   */
  rtb_Cm = rtb_Cl_zA * rtb_Cl_zA;

  /* Product: '<S160>/Product2' incorporates:
   *  DiscreteIntegrator: '<S160>/Discrete-Time Integrator'
   *  Trigonometry: '<S160>/Trigonometric Function2'
   */
  rtb_SumofElements1 = arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_f[0]) *
    rtb_Cm;

  /* Math: '<S164>/u^2' incorporates:
   *  DiscreteIntegrator: '<S160>/Discrete-Time Integrator'
   *  Product: '<S160>/Product1'
   *  Product: '<S164>/Divide2'
   *  Trigonometry: '<S160>/Trigonometric Function1'
   */
  rtb_Divide_e_idx_1 = arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_f[0]) *
    rtb_Cm;
  rtb_Cm = rtb_Cnr * rtb_Cnr;

  /* Product: '<S160>/Product2' incorporates:
   *  DiscreteIntegrator: '<S160>/Discrete-Time Integrator'
   *  Trigonometry: '<S160>/Trigonometric Function2'
   */
  rtb_SumofElements = arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_f[1]) *
    rtb_Cm;

  /* Math: '<S164>/u^2' incorporates:
   *  DiscreteIntegrator: '<S160>/Discrete-Time Integrator'
   *  Product: '<S160>/Product1'
   *  Product: '<S164>/Divide2'
   *  Trigonometry: '<S160>/Trigonometric Function1'
   */
  rtb_TrigonometricFunction2 = arm_cos_f32
    (Plant_DW.DiscreteTimeIntegrator_DSTATE_f[1]) * rtb_Cm;
  rtb_Cm = rtb_Cl_yA * rtb_Cl_yA;

  /* Sum: '<S160>/Sum of Elements' incorporates:
   *  DiscreteIntegrator: '<S160>/Discrete-Time Integrator'
   *  Product: '<S160>/Product2'
   *  Trigonometry: '<S160>/Trigonometric Function2'
   */
  rtb_SumofElements = ((rtb_SumofElements1 + rtb_SumofElements) + arm_sin_f32
                       (Plant_DW.DiscreteTimeIntegrator_DSTATE_f[2]) * rtb_Cm) +
    arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_f[3]) * rtb_Cl_xA;

  /* SignalConversion: '<S160>/ConcatBufferAtVector ConcatenateIn1' incorporates:
   *  Sum: '<S160>/Sum of Elements'
   */
  rtb_Divide2[0] = rtb_SumofElements;

  /* Sum: '<S160>/Sum of Elements1' incorporates:
   *  DiscreteIntegrator: '<S160>/Discrete-Time Integrator'
   *  Product: '<S160>/Product1'
   *  Trigonometry: '<S160>/Trigonometric Function1'
   */
  rtb_SumofElements1 = ((rtb_Divide_e_idx_1 + rtb_TrigonometricFunction2) +
                        arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_f[2])
                        * rtb_Cm) + arm_cos_f32
    (Plant_DW.DiscreteTimeIntegrator_DSTATE_f[3]) * rtb_Cl_xA;

  /* SignalConversion: '<S160>/ConcatBufferAtVector ConcatenateIn2' */
  rtb_Divide2[1] = rtb_SumofElements1;

  /* Gain: '<S160>/Gain2' incorporates:
   *  Sum: '<S160>/Sum'
   *  Sum: '<S160>/Sum of Elements'
   */
  rtb_Divide2[2] = (rtb_SumofElements + rtb_SumofElements1) * 0.5;

  /* Update for DiscreteIntegrator: '<S160>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_f[0] += rtb_Divide_k_idx_0;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_f[1] += rtb_Divide_k_idx_1;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_f[2] += rtb_Divide_k_idx_2;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_f[3] += rtb_Divide_ld;

  /* End of Outputs for SubSystem: '<S158>/Vibration_Model' */

  /* Switch: '<S158>/Switch' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S160>/Gain4'
   *  Product: '<S160>/Divide'
   *  Product: '<S162>/Product1'
   *  SignalConversion: '<S162>/ConcatBufferAtVector Concatenate1In1'
   *  SignalConversion: '<S162>/ConcatBufferAtVector Concatenate1In2'
   *  SignalConversion: '<S162>/ConcatBufferAtVector Concatenate1In3'
   *  Sum: '<S158>/Sum'
   *  Sum: '<S162>/Sum'
   */
  for (i = 0; i < 3; i++) {
    /* Outputs for Atomic SubSystem: '<S158>/Vibration_Model' */
    rtb_Sum_ok[i] = (real32_T)(((Plant_Y.Extended_States.M_BO[i + 3] *
      Plant_Y.Plant_States.acc_y_O + Plant_Y.Extended_States.M_BO[i] *
      Plant_Y.Plant_States.acc_x_O) + Plant_Y.Extended_States.M_BO[i + 6] *
      (Plant_Y.Plant_States.acc_z_O - 9.80665F)) + rtb_Divide2[i] / 4.0 *
      Plant_ConstP.Gain4_Gain[i]);

    /* End of Outputs for SubSystem: '<S158>/Vibration_Model' */
  }

  /* End of Switch: '<S158>/Switch' */

  /* Sum: '<S166>/Sum' incorporates:
   *  Product: '<S166>/Product'
   */
  for (i = 0; i < 3; i++) {
    rtb_RandomSource1[i] = (Plant_ConstB.Add_g[i + 3] * rtb_Sum_ok[1] +
      Plant_ConstB.Add_g[i] * rtb_Sum_ok[0]) + Plant_ConstB.Add_g[i + 6] *
      rtb_Sum_ok[2];
  }

  /* End of Sum: '<S166>/Sum' */

  /* DiscreteIntegrator: '<S165>/Discrete-Time Integrator5' */
  if (Plant_DW.DiscreteTimeIntegrator5_IC_LO_g != 0) {
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[0] = rtb_RandomSource1[0];
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[1] = rtb_RandomSource1[1];
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[2] = rtb_RandomSource1[2];
  }

  /* Outport: '<Root>/IMU' incorporates:
   *  BusAssignment: '<S155>/Bus Assignment'
   *  Memory: '<S126>/Memory1'
   */
  Plant_Y.IMU.timestamp = Plant_DW.Memory1_PreviousInput;
  Plant_Y.IMU.gyr_x = rtb_Add_hg[0];
  Plant_Y.IMU.gyr_y = rtb_Add_hg[1];
  Plant_Y.IMU.gyr_z = rtb_Add_hg[2];

  /* Update for DiscreteIntegrator: '<S176>/Discrete-Time Integrator5' */
  Plant_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;

  /* Update for DiscreteIntegrator: '<S165>/Discrete-Time Integrator5' */
  Plant_DW.DiscreteTimeIntegrator5_IC_LO_g = 0U;

  /* End of Outputs for SubSystem: '<S6>/Sensor_IMU' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_MAG' */
  /* Gain: '<S184>/rad_to_index' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S184>/TmpSignal ConversionAtrad_to_indexInport1'
   */
  rtb_SumofElements = fmod(floor(5.7295779513082321 * Plant_Y.Plant_States.lat),
    4.294967296E+9);

  /* Sum: '<S184>/Add' incorporates:
   *  Gain: '<S184>/rad_to_index'
   */
  i = (rtb_SumofElements < 0.0 ? -(int32_T)(uint32_T)-rtb_SumofElements :
       (int32_T)(uint32_T)rtb_SumofElements) + 8;

  /* Saturate: '<S184>/Saturation1' */
  if (i > 16) {
    i = 16;
  } else {
    if (i < 0) {
      i = 0;
    }
  }

  /* Gain: '<S184>/rad_to_index' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S184>/TmpSignal ConversionAtrad_to_indexInport1'
   */
  rtb_SumofElements = fmod(floor(5.7295779513082321 * Plant_Y.Plant_States.lon),
    4.294967296E+9);

  /* Sum: '<S184>/Add' incorporates:
   *  Gain: '<S184>/rad_to_index'
   */
  rtb_Saturation1_idx_1 = (rtb_SumofElements < 0.0 ? -(int32_T)(uint32_T)
    -rtb_SumofElements : (int32_T)(uint32_T)rtb_SumofElements) + 18;

  /* Saturate: '<S184>/Saturation1' */
  if (rtb_Saturation1_idx_1 > 36) {
    rtb_Saturation1_idx_1 = 36;
  } else {
    if (rtb_Saturation1_idx_1 < 0) {
      rtb_Saturation1_idx_1 = 0;
    }
  }

  /* LookupNDDirect: '<S184>/Declination_Lookup_Table' incorporates:
   *  LookupNDDirect: '<S184>/Inclination_Lookup_Table'
   *  LookupNDDirect: '<S184>/Magnitude_Lookup_Table'
   *
   * About '<S184>/Declination_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   *
   * About '<S184>/Inclination_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   *
   * About '<S184>/Magnitude_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  i += rtb_Saturation1_idx_1 * 17;

  /* Gain: '<S185>/Gain1' incorporates:
   *  LookupNDDirect: '<S184>/Declination_Lookup_Table'
   *
   * About '<S184>/Declination_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  rtb_Saturation = Plant_ConstP.Declination_Lookup_Table_table[i] *
    0.0174532924F;

  /* Trigonometry: '<S187>/Trigonometric Function1' incorporates:
   *  Trigonometry: '<S187>/Trigonometric Function3'
   */
  rtb_Divide_k_idx_1 = arm_cos_f32(rtb_Saturation);
  rtb_VectorConcatenate_f[0] = rtb_Divide_k_idx_1;

  /* Trigonometry: '<S187>/Trigonometric Function' incorporates:
   *  Trigonometry: '<S187>/Trigonometric Function2'
   */
  rtb_Divide_ld = arm_sin_f32(rtb_Saturation);
  rtb_VectorConcatenate_f[1] = rtb_Divide_ld;

  /* SignalConversion: '<S187>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S187>/Constant3'
   */
  rtb_VectorConcatenate_f[2] = 0.0F;

  /* Gain: '<S187>/Gain' */
  rtb_VectorConcatenate_f[3] = -rtb_Divide_ld;

  /* Trigonometry: '<S187>/Trigonometric Function3' */
  rtb_VectorConcatenate_f[4] = rtb_Divide_k_idx_1;

  /* SignalConversion: '<S187>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S187>/Constant4'
   */
  rtb_VectorConcatenate_f[5] = 0.0F;

  /* Gain: '<S185>/Gain' incorporates:
   *  LookupNDDirect: '<S184>/Inclination_Lookup_Table'
   *
   * About '<S184>/Inclination_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  rtb_Saturation = Plant_ConstP.Inclination_Lookup_Table_table[i] *
    -0.0174532924F;

  /* Trigonometry: '<S186>/Trigonometric Function3' incorporates:
   *  Trigonometry: '<S186>/Trigonometric Function1'
   */
  rtb_DiscreteTimeIntegrator_id_0 = arm_cos_f32(rtb_Saturation);
  rtb_VectorConcatenate_n[0] = rtb_DiscreteTimeIntegrator_id_0;

  /* SignalConversion: '<S186>/ConcatBufferAtVector Concatenate2In2' incorporates:
   *  Constant: '<S186>/Constant4'
   */
  rtb_VectorConcatenate_n[1] = 0.0F;

  /* Trigonometry: '<S186>/Trigonometric Function2' incorporates:
   *  Trigonometry: '<S186>/Trigonometric Function'
   */
  rtb_Divide_k_idx_1 = arm_sin_f32(rtb_Saturation);

  /* Gain: '<S186>/Gain' incorporates:
   *  Trigonometry: '<S186>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_n[2] = -rtb_Divide_k_idx_1;

  /* End of Outputs for SubSystem: '<S6>/Sensor_MAG' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_IMU' */
  /* Saturate: '<S159>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S165>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[0] > 78.4532F) {
    rtb_Saturation = 78.4532F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[0] < -78.4532F) {
    rtb_Saturation = -78.4532F;
  } else {
    rtb_Saturation = Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[0];
  }

  /* Update for DiscreteIntegrator: '<S176>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S176>/Gain'
   *  Sum: '<S176>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTATE[0] += (rtb_RandomSource[0] -
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 314.159271F * 0.002F;

  /* Update for DiscreteIntegrator: '<S165>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S165>/Gain'
   *  Sum: '<S165>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[0] += (rtb_RandomSource1[0] -
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[0]) * 314.159271F * 0.002F;

  /* End of Outputs for SubSystem: '<S6>/Sensor_IMU' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_MAG' */
  /* SignalConversion: '<S187>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_f[6] = Plant_ConstB.VectorConcatenate3[0];

  /* SignalConversion: '<S186>/ConcatBufferAtVector ConcatenateIn2' */
  rtb_VectorConcatenate_n[3] = Plant_ConstB.VectorConcatenate3_e[0];

  /* End of Outputs for SubSystem: '<S6>/Sensor_MAG' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_IMU' */
  /* Saturate: '<S159>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S165>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[1] > 78.4532F) {
    rtb_MathFunction1_k = 78.4532F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[1] < -78.4532F) {
    rtb_MathFunction1_k = -78.4532F;
  } else {
    rtb_MathFunction1_k = Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[1];
  }

  /* Update for DiscreteIntegrator: '<S176>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S176>/Gain'
   *  Sum: '<S176>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTATE[1] += (rtb_RandomSource[1] -
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 314.159271F * 0.002F;

  /* Update for DiscreteIntegrator: '<S165>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S165>/Gain'
   *  Sum: '<S165>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[1] += (rtb_RandomSource1[1] -
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[1]) * 314.159271F * 0.002F;

  /* End of Outputs for SubSystem: '<S6>/Sensor_IMU' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_MAG' */
  /* SignalConversion: '<S187>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_f[7] = Plant_ConstB.VectorConcatenate3[1];

  /* SignalConversion: '<S186>/ConcatBufferAtVector ConcatenateIn2' */
  rtb_VectorConcatenate_n[4] = Plant_ConstB.VectorConcatenate3_e[1];

  /* End of Outputs for SubSystem: '<S6>/Sensor_MAG' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_IMU' */
  /* Saturate: '<S159>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S165>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[2] > 78.4532F) {
    rtb_DiscreteTimeIntegrator_id_1 = 78.4532F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[2] < -78.4532F) {
    rtb_DiscreteTimeIntegrator_id_1 = -78.4532F;
  } else {
    rtb_DiscreteTimeIntegrator_id_1 = Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[2];
  }

  /* Update for DiscreteIntegrator: '<S176>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S176>/Gain'
   *  Sum: '<S176>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTATE[2] += (rtb_RandomSource[2] -
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 314.159271F * 0.002F;

  /* Update for DiscreteIntegrator: '<S165>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S165>/Gain'
   *  Sum: '<S165>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[2] += (rtb_RandomSource1[2] -
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[2]) * 314.159271F * 0.002F;

  /* End of Outputs for SubSystem: '<S6>/Sensor_IMU' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_MAG' */
  /* SignalConversion: '<S187>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_f[8] = Plant_ConstB.VectorConcatenate3[2];

  /* SignalConversion: '<S186>/ConcatBufferAtVector ConcatenateIn2' */
  rtb_VectorConcatenate_n[5] = Plant_ConstB.VectorConcatenate3_e[2];

  /* Trigonometry: '<S186>/Trigonometric Function' */
  rtb_VectorConcatenate_n[6] = rtb_Divide_k_idx_1;

  /* SignalConversion: '<S186>/ConcatBufferAtVector Concatenate1In2' incorporates:
   *  Constant: '<S186>/Constant3'
   */
  rtb_VectorConcatenate_n[7] = 0.0F;

  /* Trigonometry: '<S186>/Trigonometric Function1' */
  rtb_VectorConcatenate_n[8] = rtb_DiscreteTimeIntegrator_id_0;

  /* Gain: '<S185>/toGauss' incorporates:
   *  LookupNDDirect: '<S184>/Magnitude_Lookup_Table'
   *
   * About '<S184>/Magnitude_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  rtb_DiscreteTimeIntegrator_id_0 = Plant_ConstP.Magnitude_Lookup_Table_table[i]
    * 0.01F;

  /* Product: '<S185>/Multiply1' incorporates:
   *  Product: '<S185>/Multiply'
   */
  for (i = 0; i < 3; i++) {
    rtb_Multiply5_j[i] = rtb_VectorConcatenate_n[i] *
      rtb_DiscreteTimeIntegrator_id_0;
  }

  /* End of Product: '<S185>/Multiply1' */

  /* Product: '<S185>/Multiply2' */
  for (i = 0; i < 3; i++) {
    rtb_Add_hg[i] = rtb_VectorConcatenate_f[i + 6] * rtb_Multiply5_j[2] +
      (rtb_VectorConcatenate_f[i + 3] * rtb_Multiply5_j[1] +
       rtb_VectorConcatenate_f[i] * rtb_Multiply5_j[0]);
  }

  /* End of Product: '<S185>/Multiply2' */

  /* Product: '<S182>/Product' incorporates:
   *  Delay: '<Root>/Delay'
   */
  for (i = 0; i < 3; i++) {
    rtb_Multiply5_j[i] = Plant_Y.Extended_States.M_BO[i + 6] * rtb_Add_hg[2] +
      (Plant_Y.Extended_States.M_BO[i + 3] * rtb_Add_hg[1] +
       Plant_Y.Extended_States.M_BO[i] * rtb_Add_hg[0]);
  }

  /* End of Product: '<S182>/Product' */
  for (i = 0; i < 3; i++) {
    /* Sum: '<S188>/Sum' incorporates:
     *  Product: '<S188>/Product'
     */
    rtb_Gain_kz = (Plant_ConstB.Add[i + 3] * rtb_Multiply5_j[1] +
                   Plant_ConstB.Add[i] * rtb_Multiply5_j[0]) +
      Plant_ConstB.Add[i + 6] * rtb_Multiply5_j[2];

    /* Saturate: '<S183>/Saturation' incorporates:
     *  Sum: '<S188>/Sum'
     */
    if (rtb_Gain_kz > 4.0F) {
      rtb_Add_hg[i] = 4.0F;
    } else if (rtb_Gain_kz < -4.0F) {
      rtb_Add_hg[i] = -4.0F;
    } else {
      rtb_Add_hg[i] = rtb_Gain_kz;
    }

    /* End of Saturate: '<S183>/Saturation' */
  }

  /* S-Function (sdsprandsrc2): '<S189>/Random Source' */
  RandSrc_GZ_R(rtb_Multiply5_j, &Plant_ConstP.pooled26, 1,
               Plant_ConstP.RandomSource_VarianceRTP_om, 3,
               Plant_DW.RandomSource_STATE_DWORK, 3, 1);

  /* Sum: '<S183>/Add' */
  rtb_Add_hg[0] += rtb_Multiply5_j[0];
  rtb_Add_hg[1] += rtb_Multiply5_j[1];

  /* BusAssignment: '<S179>/Bus Assignment' incorporates:
   *  Memory: '<S126>/Memory1'
   *  Sum: '<S183>/Add'
   */
  rtb_BusAssignment_j.timestamp = Plant_DW.Memory1_PreviousInput;
  rtb_BusAssignment_j.mag_x = rtb_Add_hg[0];
  rtb_BusAssignment_j.mag_y = rtb_Add_hg[1];
  rtb_BusAssignment_j.mag_z = rtb_Add_hg[2] + rtb_Multiply5_j[2];

  /* RateTransition: '<S179>/Rate Transition' */
  if (Plant_M->Timing.TaskCounters.TID[2] == 0) {
    Plant_B.RateTransition_l = rtb_BusAssignment_j;
  }

  /* End of RateTransition: '<S179>/Rate Transition' */
  /* End of Outputs for SubSystem: '<S6>/Sensor_MAG' */

  /* Update for Memory: '<S126>/Memory1' incorporates:
   *  Constant: '<S126>/dt'
   *  Sum: '<S126>/Sum'
   */
  Plant_DW.Memory1_PreviousInput += PLANT_EXPORT.period;

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_IMU' */
  /* Outport: '<Root>/IMU' incorporates:
   *  Sum: '<S159>/Sum'
   */
  Plant_Y.IMU.acc_x = rtb_Saturation + rtb_MathFunction[0];
  Plant_Y.IMU.acc_y = rtb_MathFunction1_k + rtb_MathFunction[1];
  Plant_Y.IMU.acc_z = rtb_DiscreteTimeIntegrator_id_1 + rtb_MathFunction[2];

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
    /* InitializeConditions for DiscreteIntegrator: '<S105>/Discrete-Time Integrator' */
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[0] = Plant_ConstB.quat0[0];
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[1] = Plant_ConstB.quat0[1];
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[2] = Plant_ConstB.quat0[2];
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[3] = Plant_ConstB.quat0[3];
    Plant_DW.DiscreteTimeIntegrator_PrevRese = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S101>/Discrete-Time Integrator' */
    Plant_DW.DiscreteTimeIntegrator_PrevRe_p = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S102>/Discrete-Time Integrator' */
    Plant_DW.DiscreteTimeIntegrator_PrevRe_g = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S102>/Discrete-Time Integrator1' */
    Plant_DW.DiscreteTimeIntegrator1_PrevRes = 0;

    /* End of SystemInitialize for SubSystem: '<Root>/Kinematic_Equation' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Bus_Constructor' */
    /* InitializeConditions for Delay: '<S59>/Delay1' */
    Plant_DW.Delay1_DSTATE_c[0] = 0.65673;
    Plant_DW.Delay1_DSTATE_c[1] = -2.1361;
    Plant_DW.Delay1_DSTATE_c[2] = 4.5;

    /* End of SystemInitialize for SubSystem: '<Root>/Bus_Constructor' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Sensor_Model' */
    /* SystemInitialize for Atomic SubSystem: '<S6>/Sensor_Barometer' */
    /* InitializeConditions for S-Function (sdsprandsrc2): '<S140>/Random Source' */
    RandomSource_SEED_DWORK_n = 91337U;
    RandSrcInitState_GZ(&RandomSource_SEED_DWORK_n,
                        Plant_DW.RandomSource_STATE_DWORK_fn, 1);

    /* End of SystemInitialize for SubSystem: '<S6>/Sensor_Barometer' */

    /* SystemInitialize for Atomic SubSystem: '<S6>/Sensor_GPS' */
    /* InitializeConditions for S-Function (sdsprandsrc2): '<S149>/Random Source' */
    RandSrcCreateSeeds_32(63235U, Plant_DW.RandomSource_SEED_DWORK_a, 3);
    RandSrcInitState_GZ(Plant_DW.RandomSource_SEED_DWORK_a,
                        Plant_DW.RandomSource_STATE_DWORK_f2, 3);

    /* InitializeConditions for DiscreteFir: '<S151>/Discrete FIR Filter' */
    Plant_DW.DiscreteFIRFilter_states[0] = 0.0;
    Plant_DW.DiscreteFIRFilter_states[1] = 0.0;
    Plant_DW.DiscreteFIRFilter_states[2] = 0.0;

    /* InitializeConditions for S-Function (sdsprandsrc2): '<S149>/Random Source1' */
    RandSrcCreateSeeds_32(9754U, Plant_DW.RandomSource1_SEED_DWORK, 3);
    RandSrcInitState_GZ(Plant_DW.RandomSource1_SEED_DWORK,
                        Plant_DW.RandomSource1_STATE_DWORK, 3);

    /* InitializeConditions for DiscreteFir: '<S152>/Discrete FIR Filter' */
    Plant_DW.DiscreteFIRFilter_states_i[0] = 0.0F;
    Plant_DW.DiscreteFIRFilter_states_i[1] = 0.0F;
    Plant_DW.DiscreteFIRFilter_states_i[2] = 0.0F;

    /* End of SystemInitialize for SubSystem: '<S6>/Sensor_GPS' */

    /* SystemInitialize for Atomic SubSystem: '<S6>/Sensor_IMU' */
    /* InitializeConditions for DiscreteIntegrator: '<S176>/Discrete-Time Integrator5' */
    Plant_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

    /* InitializeConditions for S-Function (sdsprandsrc2): '<S167>/Random Source' */
    RandSrcCreateSeeds_32(90579U, Plant_DW.RandomSource_SEED_DWORK_h, 3);
    RandSrcInitState_GZ(Plant_DW.RandomSource_SEED_DWORK_h,
                        Plant_DW.RandomSource_STATE_DWORK_f, 3);

    /* InitializeConditions for S-Function (sdsprandsrc2): '<S178>/Random Source' */
    RandSrcCreateSeeds_32(81472U, Plant_DW.RandomSource_SEED_DWORK_e, 3);
    RandSrcInitState_GZ(Plant_DW.RandomSource_SEED_DWORK_e,
                        Plant_DW.RandomSource_STATE_DWORK_p, 3);

    /* InitializeConditions for DiscreteIntegrator: '<S165>/Discrete-Time Integrator5' */
    Plant_DW.DiscreteTimeIntegrator5_IC_LO_g = 1U;

    /* End of SystemInitialize for SubSystem: '<S6>/Sensor_IMU' */

    /* SystemInitialize for Atomic SubSystem: '<S6>/Sensor_MAG' */
    /* InitializeConditions for S-Function (sdsprandsrc2): '<S189>/Random Source' */
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
