/*
 * File: Plant.c
 *
 * Code generated for Simulink model 'Plant'.
 *
 * Model version                  : 1.70
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Mar 13 16:31:08 2023
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

  { 70, 105, 120, 119, 105, 110, 103, 32, 118, 48, 46, 48, 46, 49, 0 }
} ;                                    /* Variable: PLANT_EXPORT
                                        * Referenced by:
                                        *   '<S42>/dt'
                                        *   '<S89>/dt'
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
const Control_Out_Bus Plant_rtZControl_Out_Bus = { 0U,/* timestamp */
  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }/* actuator_cmd */
};

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

void rt_mldivide_U1f3x3_U2f3x1_Yf3x1(const real32_T u0[9], const real32_T u1[3],
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

  /* S-Function (sdsprandsrc2): '<S103>/Random Source' */
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

  /* End of S-Function (sdsprandsrc2): '<S103>/Random Source' */
}

void RandSrcInitState_GZ(const uint32_T seed[], uint32_T state[], int32_T nChans)
{
  int32_T i;
  int32_T tmp;

  /* InitializeConditions for S-Function (sdsprandsrc2): '<S103>/Random Source' */
  /* RandSrcInitState_GZ */
  for (i = 0; i < nChans; i++) {
    tmp = i << 1;
    state[tmp] = 362436069U;
    state[tmp + 1] = seed[i] == 0U ? 521288629U : seed[i];
  }

  /* End of InitializeConditions for S-Function (sdsprandsrc2): '<S103>/Random Source' */
}

void RandSrcInitState_U_32(const uint32_T seed[], real32_T state[], int32_T
  nChans)
{
  int32_T i;
  uint32_T j;
  int32_T k;
  int32_T n;
  real32_T d;

  /* InitializeConditions for S-Function (sdsprandsrc2): '<S112>/Random Source' */
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

  /* End of InitializeConditions for S-Function (sdsprandsrc2): '<S112>/Random Source' */
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

  /* InitializeConditions for S-Function (sdsprandsrc2): '<S112>/Random Source' */
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

  /* End of InitializeConditions for S-Function (sdsprandsrc2): '<S112>/Random Source' */
}

void RandSrcCreateSeeds_32(uint32_T initSeed, uint32_T seedArray[], int32_T
  numSeeds)
{
  real32_T state[35];
  real32_T tmp;
  real32_T min;
  real32_T max;
  int32_T i;

  /* InitializeConditions for S-Function (sdsprandsrc2): '<S112>/Random Source' */
  /* RandSrcCreateSeeds_32 */
  min = 0.0F;
  max = 1.0F;
  RandSrcInitState_U_32(&initSeed, state, 1);
  for (i = 0; i < numSeeds; i++) {
    RandSrc_U_R(&tmp, &min, 1, &max, 1, state, 1, 1);
    seedArray[i] = (uint32_T)(tmp * 2.14748365E+9F);
  }

  /* End of InitializeConditions for S-Function (sdsprandsrc2): '<S112>/Random Source' */
}

/* Model step function */
void Plant_step(void)
{
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
  real32_T rtb_Sum_an[3];
  real32_T rtb_Sum_l[3];
  boolean_T rtb_Compare;
  real32_T rtb_Add_i[3];
  real32_T rtb_MatrixConcatenate4[16];
  real32_T rtb_VectorConcatenate_f[9];
  real32_T rtb_Sum_fe;
  AirSpeed_Bus rtb_BusAssignment_f;
  Barometer_Bus rtb_BusAssignment_c;
  GPS_uBlox_Bus rtb_BusAssignment_e;
  real32_T rtb_VectorConcatenate_n[9];
  MAG_Bus rtb_BusAssignment_j;
  real32_T rtb_RandomSource[3];
  real32_T rtb_Square_d[3];
  real32_T rtb_RandomSource1[3];
  real32_T rtb_RandomSource_a[3];
  real_T rtb_DataTypeConversion2[2];
  int32_T i;
  real32_T tmp[3];
  real_T tmp_0[6];
  real_T tmp_1[6];
  real_T rtb_CD_0[6];
  real32_T rtb_MatrixConcatenate4_0[4];
  real32_T rtb_Sum1_e;
  real32_T rtb_DiscreteTimeIntegrator_idx_;
  real32_T rtb_DiscreteTimeIntegrator_id_0;
  real32_T rtb_DiscreteTimeIntegrator_id_1;
  real_T rtb_Divide_e_idx_1;
  real32_T rtb_TrigonometricFunction1_idx_;
  real32_T rtb_TrigonometricFunction1_id_0;
  real32_T rtb_Sum1_f_idx_2;
  real32_T rtb_Sum1_f_idx_1;
  real32_T rtb_Sum1_f_idx_0;
  real32_T rtb_Add_a_idx_2;
  real32_T rtb_Add_a_idx_1;
  real32_T rtb_Sum1_dw_idx_1;
  real32_T rtb_Add_a_idx_0;
  real32_T rtb_Sum1_dw_idx_0;
  real32_T rtb_DiscreteTimeIntegrator5_idx;
  real32_T rtb_DiscreteTimeIntegrator5_i_0;
  real32_T rtb_DiscreteTimeIntegrator5_i_1;
  int32_T rtb_Saturation1_m_idx_1;
  uint16_T tmp_2;
  real32_T rtb_TrigonometricFunction1_id_1;
  real32_T rtb_Divide_o_idx_0;
  real32_T rtb_TrigonometricFunction1_id_2;
  real32_T rtb_Divide_o_idx_1;
  real32_T rtb_TrigonometricFunction1_id_3;
  real32_T rtb_Divide_o_idx_2;
  real32_T rtb_TrigonometricFunction1_id_4;
  real32_T rtb_Divide_o_idx_3;
  real32_T rtb_Divide_k_idx_1;
  real32_T rtb_Add_j0_tmp;
  real32_T rtb_Gain_e_tmp;
  real32_T rtb_Add_j0_tmp_0;

  /* Delay: '<Root>/Delay' */
  rtb_DiscreteTimeIntegrator_id_1 = Plant_Y.Plant_States.vel_x_O;
  rtb_DiscreteTimeIntegrator_id_0 = Plant_Y.Plant_States.vel_y_O;
  for (i = 0; i < 9; i++) {
    rtb_VectorConcatenate_f[i] = Plant_Y.Extended_States.M_BO[i];
  }

  /* Outputs for Atomic SubSystem: '<Root>/Actuators' */
  for (i = 0; i < 3; i++) {
    /* Product: '<S9>/Multiply' incorporates:
     *  Delay: '<Root>/Delay'
     */
    rtb_Add_p = rtb_VectorConcatenate_f[i + 6] * Plant_Y.Plant_States.vel_z_O +
      (rtb_VectorConcatenate_f[i + 3] * rtb_DiscreteTimeIntegrator_id_0 +
       rtb_VectorConcatenate_f[i] * rtb_DiscreteTimeIntegrator_id_1);

    /* Math: '<S41>/Square' */
    rtb_Square_d[i] = rtb_Add_p * rtb_Add_p;

    /* Product: '<S9>/Multiply' */
    rtb_Va_B[i] = rtb_Add_p;
  }

  /* Product: '<S40>/Divide' incorporates:
   *  Saturate: '<S40>/Saturation'
   *  Sqrt: '<S41>/Sqrt'
   *  Sum: '<S41>/Sum of Elements'
   */
  rtb_Add_p = rtb_Va_B[1] / fmaxf(sqrtf((rtb_Square_d[0] + rtb_Square_d[1]) +
    rtb_Square_d[2]), 0.1F);

  /* DataTypeConversion: '<S7>/Data Type Conversion2' incorporates:
   *  Product: '<S39>/Divide'
   *  Saturate: '<S39>/Saturation'
   *  Trigonometry: '<S39>/Atan'
   */
  rtb_DataTypeConversion2[0] = atanf(rtb_Va_B[2] / fmaxf(rtb_Va_B[0], 0.1F));

  /* Trigonometry: '<S40>/Asin' */
  if (rtb_Add_p > 1.0F) {
    rtb_Add_p = 1.0F;
  } else {
    if (rtb_Add_p < -1.0F) {
      rtb_Add_p = -1.0F;
    }
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion2' incorporates:
   *  Trigonometry: '<S40>/Asin'
   */
  rtb_DataTypeConversion2[1] = asinf(rtb_Add_p);

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
  rtb_Sum1_f_idx_0 = 1.0F / rtb_Gain_kz * 2.3F;
  rtb_Add_p = rtb_Sum1_f_idx_0 * Plant_Y.Plant_States.rot_x_B;

  /* Product: '<S15>/Product4' incorporates:
   *  Constant: '<S15>/c'
   *  Delay: '<Root>/Delay'
   */
  rtb_MathFunction1_k = 1.0F / rtb_Gain_kz * 0.32F *
    Plant_Y.Plant_States.rot_y_B;

  /* Product: '<S15>/Product2' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_Gain_kz = rtb_Sum1_f_idx_0 * Plant_Y.Plant_States.rot_z_B;

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
  rtb_Sum_nr[2] = rtb_SumofElements * rtb_Add_p;
  rtb_Sum_nr[3] = rtb_SumofElements1 * rtb_Add_p;
  rtb_Sum_nr[4] = 0.0;
  rtb_Sum_nr[5] = rtb_TrigonometricFunction2 * rtb_Add_p;

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
  tmp_0[0] = 0.0;
  tmp_0[1] = rtb_SumofElements * rtb_MathFunction1_k;
  tmp_0[2] = 0.0;
  tmp_0[3] = 0.0;
  tmp_0[4] = rtb_SumofElements1 * rtb_MathFunction1_k;
  tmp_0[5] = 0.0;

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
  tmp_1[0] = 0.0;
  tmp_1[1] = 0.0;
  tmp_1[2] = rtb_SumofElements * rtb_Gain_kz;
  tmp_1[3] = rtb_SumofElements1 * rtb_Gain_kz;
  tmp_1[4] = 0.0;
  tmp_1[5] = rtb_TrigonometricFunction2 * rtb_Gain_kz;

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
    rtb_Sum_nr[i] = (((rtb_Sum_nr[i] + tmp_0[i]) + tmp_1[i]) + rtb_CD_0[i]) +
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
  rtb_Sum_an[0] = rtb_Gain_kz * (real32_T)rtb_Cl_xA;
  rtb_Sum_an[1] = (real32_T)(-rtb_Sum_nr[0] * sin(rtb_DataTypeConversion2[1]) +
    rtb_Sum_nr[2]) * rtb_Gain_kz;
  rtb_Sum_an[2] = rtb_Gain_kz * (real32_T)rtb_Cl_zA;

  /* Sum: '<S1>/Sum1' incorporates:
   *  Constant: '<S38>/cT'
   *  DiscreteIntegrator: '<S35>/Discrete-Time Integrator'
   *  Math: '<S38>/Square'
   *  Product: '<S38>/Multiply'
   *  Sum: '<S34>/Sum of Elements'
   */
  rtb_Sum1_f_idx_0 = ((real32_T)(Plant_DW.DiscreteTimeIntegrator_DSTATE_p[0] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_p[0] * 2.478E-5) + (real32_T)
                      (Plant_DW.DiscreteTimeIntegrator_DSTATE_p[1] *
                       Plant_DW.DiscreteTimeIntegrator_DSTATE_p[1] * 2.478E-5))
    + rtb_Sum_an[0];
  rtb_Sum1_f_idx_1 = rtb_Sum_an[1];
  rtb_Sum1_f_idx_2 = rtb_Sum_an[2];

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
  rtb_Sum1_dw_idx_0 = (Plant_ConstB.Sum_k[1] * rtb_Sum_an[2] -
                       Plant_ConstB.Sum_k[2] * rtb_Sum_an[1]) + 2.3F *
    rtb_Gain_kz * (real32_T)rtb_Sum_nr[3];
  rtb_Sum1_dw_idx_1 = (Plant_ConstB.Sum_k[2] * rtb_Sum_an[0] -
                       Plant_ConstB.Sum_k[0] * rtb_Sum_an[2]) + 0.32F *
    rtb_Gain_kz * (real32_T)rtb_Sum_nr[4];
  rtb_MathFunction1_k = (Plant_ConstB.Sum_k[0] * rtb_Sum_an[1] -
    Plant_ConstB.Sum_k[1] * rtb_Sum_an[0]) + 2.3F * rtb_Gain_kz * (real32_T)
    rtb_Sum_nr[5];

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
  rtb_Add_p = ((real32_T)tmp_2 - 1000.0F) * 0.000999987125F;

  /* RelationalOperator: '<S37>/Compare' incorporates:
   *  Constant: '<S37>/Constant'
   */
  rtb_Compare = (rtb_Add_p > 0.1F);

  /* Sum: '<S36>/Add' incorporates:
   *  Constant: '<S36>/Constant1'
   *  Gain: '<S36>/Gain1'
   */
  rtb_Add_p = 718.078F * rtb_Add_p + 88.448F;

  /* Update for DiscreteIntegrator: '<S35>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S35>/Gain'
   *  Product: '<S36>/Multiply'
   *  Saturate: '<S36>/Saturation1'
   *  Sum: '<S35>/Subtract'
   */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_p[0] += ((rtb_Compare ? rtb_Add_p :
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
  rtb_Add_p = ((real32_T)tmp_2 - 1000.0F) * 0.000999987125F;

  /* RelationalOperator: '<S37>/Compare' incorporates:
   *  Constant: '<S37>/Constant'
   */
  rtb_Compare = (rtb_Add_p > 0.1F);

  /* Sum: '<S36>/Add' incorporates:
   *  Constant: '<S36>/Constant1'
   *  Gain: '<S36>/Gain1'
   */
  rtb_Add_p = 718.078F * rtb_Add_p + 88.448F;

  /* Update for DiscreteIntegrator: '<S35>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S35>/Gain'
   *  Product: '<S36>/Multiply'
   *  Saturate: '<S36>/Saturation1'
   *  Sum: '<S35>/Subtract'
   */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_p[1] += ((rtb_Compare ? rtb_Add_p :
    0.0F) - Plant_DW.DiscreteTimeIntegrator_DSTATE_p[1]) * 50.0F * 0.002F;

  /* End of Outputs for SubSystem: '<Root>/Actuators' */

  /* Outputs for Atomic SubSystem: '<Root>/Environment' */
  /* RelationalOperator: '<S59>/Compare' incorporates:
   *  Constant: '<S59>/Constant'
   *  Delay: '<Root>/Delay'
   */
  rtb_Compare = (Plant_Y.Plant_States.h_R < 0.0F);

  /* Switch: '<S54>/Switch2' incorporates:
   *  Gain: '<S60>/Gain5'
   *  Gain: '<S60>/Gain6'
   *  Product: '<S60>/Multiply'
   *  SignalConversion: '<S60>/TmpSignal ConversionAtMultiplyInport2'
   */
  if (rtb_Compare) {
    /* Switch: '<S60>/Switch1' incorporates:
     *  Constant: '<S60>/mg'
     *  Constant: '<S62>/Constant'
     *  Delay: '<Root>/Delay'
     *  Gain: '<S60>/Gain'
     *  RelationalOperator: '<S62>/Compare'
     *  Sum: '<S60>/Add'
     */
    if (Plant_Y.Plant_States.h_R <= -0.05F) {
      /* Switch: '<S60>/Switch3' incorporates:
       *  Constant: '<S60>/mg'
       *  Constant: '<S63>/Constant'
       *  Gain: '<S60>/Gain1'
       *  Gain: '<S60>/Gain2'
       *  Gain: '<S60>/Gain4'
       *  RelationalOperator: '<S63>/Compare'
       *  Sum: '<S60>/Add1'
       *  Sum: '<S60>/Add2'
       */
      if (Plant_Y.Plant_States.h_R <= -0.1F) {
        rtb_Add_p = (Plant_Y.Plant_States.h_R - 29.418F) - 50.0F *
          Plant_Y.Plant_States.vel_z_O;
      } else {
        rtb_Add_p = (0.5F * Plant_Y.Plant_States.h_R - 29.418F) - 20.0F *
          Plant_Y.Plant_States.vel_z_O;
      }

      /* End of Switch: '<S60>/Switch3' */
    } else {
      rtb_Add_p = -29.418F - 10.0F * Plant_Y.Plant_States.vel_z_O;
    }

    /* End of Switch: '<S60>/Switch1' */
    for (i = 0; i < 3; i++) {
      rtb_Sum_an[i] = rtb_VectorConcatenate_f[i + 6] * rtb_Add_p +
        (rtb_VectorConcatenate_f[i + 3] * -rtb_DiscreteTimeIntegrator_id_0 +
         rtb_VectorConcatenate_f[i] * -rtb_DiscreteTimeIntegrator_id_1);
    }
  } else {
    rtb_Sum_an[0] = 0.0F;
    rtb_Sum_an[1] = 0.0F;
    rtb_Sum_an[2] = 0.0F;
  }

  /* End of Switch: '<S54>/Switch2' */

  /* Product: '<S53>/Multiply3' */
  for (i = 0; i < 3; i++) {
    rtb_Square_d[i] = rtb_VectorConcatenate_f[i + 6] * 29.43F;
  }

  /* End of Product: '<S53>/Multiply3' */

  /* Sum: '<S4>/Add' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S55>/Gain'
   *  Math: '<S55>/Square'
   *  Sum: '<S4>/Sum'
   */
  rtb_Add_a_idx_0 = (Plant_Y.Extended_States.Va * Plant_Y.Extended_States.Va *
                     -0.05F + rtb_Sum1_f_idx_0) + (rtb_Sum_an[0] + rtb_Square_d
    [0]);
  rtb_Add_a_idx_1 = (rtb_Sum_an[1] + rtb_Square_d[1]) + rtb_Sum1_f_idx_1;
  rtb_Add_a_idx_2 = (rtb_Sum_an[2] + rtb_Square_d[2]) + rtb_Sum1_f_idx_2;

  /* Switch: '<S54>/Switch1' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S61>/Gain1'
   *  Gain: '<S61>/Gain2'
   *  Gain: '<S61>/Gain3'
   *  Sum: '<S61>/Subtract'
   */
  if (rtb_Compare) {
    rtb_Sum_an[0] = ((0.0F - 30.0F * Plant_Y.Plant_States.phi) - 5.0F *
                     Plant_Y.Plant_States.rot_x_B) * 0.9806F;
    rtb_Sum_an[1] = ((0.0F - 30.0F * Plant_Y.Plant_States.theta) - 5.0F *
                     Plant_Y.Plant_States.rot_y_B) * 0.9806F;
    rtb_Sum_an[2] = (0.0F - 5.0F * Plant_Y.Plant_States.rot_z_B) * 0.9806F;
  } else {
    rtb_Sum_an[0] = 0.0F;
    rtb_Sum_an[1] = 0.0F;
    rtb_Sum_an[2] = 0.0F;
  }

  /* End of Switch: '<S54>/Switch1' */

  /* Outputs for Atomic SubSystem: '<Root>/Actuators' */
  /* Sum: '<S4>/Add1' incorporates:
   *  Product: '<S57>/Multiply2'
   *  Product: '<S58>/Multiply4'
   *  Sum: '<S1>/Sum'
   *  Sum: '<S56>/Sum'
   */
  rtb_Sum1_dw_idx_0 += rtb_Sum_an[0];
  rtb_Sum1_dw_idx_1 = (0.0F - 0.1F * rtb_Square_d[2]) + (rtb_Sum1_dw_idx_1 +
    rtb_Sum_an[1]);
  rtb_Sum1_e = (rtb_MathFunction1_k + rtb_Sum_an[2]) + 0.1F * rtb_Square_d[1];

  /* End of Outputs for SubSystem: '<Root>/Actuators' */
  /* End of Outputs for SubSystem: '<Root>/Environment' */

  /* Outputs for Atomic SubSystem: '<Root>/Kinematic_Equation' */
  /* DiscreteIntegrator: '<S68>/Discrete-Time Integrator' */
  if (Plant_DW.DiscreteTimeIntegrator_PrevRese != 0) {
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[0] = Plant_ConstB.quat0[0];
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[1] = Plant_ConstB.quat0[1];
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[2] = Plant_ConstB.quat0[2];
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[3] = Plant_ConstB.quat0[3];
  }

  rtb_DiscreteTimeIntegrator_id_1 = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[0];
  rtb_DiscreteTimeIntegrator_id_0 = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[1];
  rtb_MathFunction1_k = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[2];
  rtb_DiscreteTimeIntegrator_idx_ = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[3];

  /* SignalConversion: '<S73>/ConcatBufferAtMatrix ConcatenateIn1' incorporates:
   *  Constant: '<S73>/Constant'
   */
  rtb_MatrixConcatenate4[0] = 0.0F;

  /* DiscreteIntegrator: '<S64>/Discrete-Time Integrator' */
  if (Plant_DW.DiscreteTimeIntegrator_PrevRe_p != 0) {
    Plant_DW.DiscreteTimeIntegrator_DSTATE_i[0] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_i[1] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_i[2] = 0.0F;
  }

  rtb_DiscreteTimeIntegrator5_i_1 = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[0];
  rtb_DiscreteTimeIntegrator5_i_0 = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[1];
  rtb_DiscreteTimeIntegrator5_idx = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[2];

  /* SignalConversion: '<S73>/ConcatBufferAtMatrix ConcatenateIn2' incorporates:
   *  DiscreteIntegrator: '<S64>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[1] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[0];

  /* SignalConversion: '<S73>/ConcatBufferAtMatrix ConcatenateIn3' incorporates:
   *  DiscreteIntegrator: '<S64>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[2] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[1];

  /* SignalConversion: '<S73>/ConcatBufferAtMatrix ConcatenateIn4' incorporates:
   *  DiscreteIntegrator: '<S64>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[3] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[2];

  /* Gain: '<S73>/Gain1' incorporates:
   *  DiscreteIntegrator: '<S64>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[4] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_i[0];

  /* SignalConversion: '<S73>/ConcatBufferAtMatrix Concatenate1In2' incorporates:
   *  Constant: '<S73>/Constant1'
   */
  rtb_MatrixConcatenate4[5] = 0.0F;

  /* Gain: '<S73>/Gain2' incorporates:
   *  DiscreteIntegrator: '<S64>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[6] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_i[2];

  /* SignalConversion: '<S73>/ConcatBufferAtMatrix Concatenate1In4' incorporates:
   *  DiscreteIntegrator: '<S64>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[7] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[1];

  /* Gain: '<S73>/Gain3' incorporates:
   *  DiscreteIntegrator: '<S64>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[8] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_i[1];

  /* SignalConversion: '<S73>/ConcatBufferAtMatrix Concatenate2In2' incorporates:
   *  DiscreteIntegrator: '<S64>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[9] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[2];

  /* SignalConversion: '<S73>/ConcatBufferAtMatrix Concatenate2In3' incorporates:
   *  Constant: '<S73>/Constant2'
   */
  rtb_MatrixConcatenate4[10] = 0.0F;

  /* Gain: '<S73>/Gain4' incorporates:
   *  DiscreteIntegrator: '<S64>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[11] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_i[0];

  /* Gain: '<S73>/Gain6' incorporates:
   *  DiscreteIntegrator: '<S64>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[12] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_i[2];

  /* Gain: '<S73>/Gain7' incorporates:
   *  DiscreteIntegrator: '<S64>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[13] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_i[1];

  /* SignalConversion: '<S73>/ConcatBufferAtMatrix Concatenate3In3' incorporates:
   *  DiscreteIntegrator: '<S64>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[14] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[0];

  /* SignalConversion: '<S73>/ConcatBufferAtMatrix Concatenate3In4' incorporates:
   *  Constant: '<S73>/Constant3'
   */
  rtb_MatrixConcatenate4[15] = 0.0F;

  /* Sqrt: '<S72>/Sqrt' incorporates:
   *  DiscreteIntegrator: '<S68>/Discrete-Time Integrator'
   *  Math: '<S72>/Square'
   *  Sqrt: '<S83>/Sqrt'
   *  Sqrt: '<S88>/Sqrt'
   *  Sum: '<S72>/Sum of Elements'
   */
  rtb_Sum1_f_idx_0 = sqrtf(((Plant_DW.DiscreteTimeIntegrator_DSTATE_k[0] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[0] +
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[1] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[1]) +
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[2] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[2]) +
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[3] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[3]);

  /* Product: '<S71>/Divide' incorporates:
   *  DiscreteIntegrator: '<S68>/Discrete-Time Integrator'
   *  Sqrt: '<S72>/Sqrt'
   */
  rtb_TrigonometricFunction1_id_1 = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[0] /
    rtb_Sum1_f_idx_0;
  rtb_TrigonometricFunction1_id_2 = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[1] /
    rtb_Sum1_f_idx_0;
  rtb_TrigonometricFunction1_id_3 = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[2] /
    rtb_Sum1_f_idx_0;
  rtb_TrigonometricFunction1_id_4 = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[3] /
    rtb_Sum1_f_idx_0;

  /* Product: '<S79>/Divide' incorporates:
   *  DiscreteIntegrator: '<S68>/Discrete-Time Integrator'
   */
  rtb_Divide_o_idx_0 = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[0] /
    rtb_Sum1_f_idx_0;
  rtb_Divide_o_idx_1 = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[1] /
    rtb_Sum1_f_idx_0;
  rtb_Divide_o_idx_2 = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[2] /
    rtb_Sum1_f_idx_0;
  rtb_Divide_o_idx_3 = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[3] /
    rtb_Sum1_f_idx_0;

  /* Product: '<S84>/Divide' incorporates:
   *  DiscreteIntegrator: '<S68>/Discrete-Time Integrator'
   */
  rtb_Sum_fe = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[0] / rtb_Sum1_f_idx_0;
  rtb_Divide_k_idx_1 = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[1] /
    rtb_Sum1_f_idx_0;
  rtb_TrigonometricFunction1_id_0 = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[2] /
    rtb_Sum1_f_idx_0;
  rtb_TrigonometricFunction1_idx_ = Plant_DW.DiscreteTimeIntegrator_DSTATE_k[3] /
    rtb_Sum1_f_idx_0;

  /* Product: '<S64>/Multiply' incorporates:
   *  Constant: '<S64>/Inertia_Matrix'
   *  DiscreteIntegrator: '<S64>/Discrete-Time Integrator'
   */
  for (i = 0; i < 3; i++) {
    rtb_Add_i[i] = Plant_ConstP.Inertia_Matrix_Value[i + 6] *
      Plant_DW.DiscreteTimeIntegrator_DSTATE_i[2] +
      (Plant_ConstP.Inertia_Matrix_Value[i + 3] *
       Plant_DW.DiscreteTimeIntegrator_DSTATE_i[1] +
       Plant_ConstP.Inertia_Matrix_Value[i] *
       Plant_DW.DiscreteTimeIntegrator_DSTATE_i[0]);
  }

  /* End of Product: '<S64>/Multiply' */

  /* Product: '<S69>/Multiply' incorporates:
   *  DiscreteIntegrator: '<S64>/Discrete-Time Integrator'
   */
  rtb_Sum_l[0] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[1] * rtb_Add_i[2];

  /* Product: '<S69>/Multiply1' incorporates:
   *  DiscreteIntegrator: '<S64>/Discrete-Time Integrator'
   */
  rtb_Sum_l[1] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[2] * rtb_Add_i[0];

  /* Product: '<S69>/Multiply2' incorporates:
   *  DiscreteIntegrator: '<S64>/Discrete-Time Integrator'
   */
  rtb_Sum_l[2] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[0] * rtb_Add_i[1];

  /* Product: '<S70>/Multiply3' incorporates:
   *  DiscreteIntegrator: '<S64>/Discrete-Time Integrator'
   */
  rtb_Square_d[0] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[2] * rtb_Add_i[1];

  /* Product: '<S70>/Multiply4' incorporates:
   *  DiscreteIntegrator: '<S64>/Discrete-Time Integrator'
   */
  rtb_Square_d[1] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[0] * rtb_Add_i[2];

  /* Product: '<S70>/Multiply5' incorporates:
   *  DiscreteIntegrator: '<S64>/Discrete-Time Integrator'
   */
  rtb_Square_d[2] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[1] * rtb_Add_i[0];

  /* DiscreteIntegrator: '<S65>/Discrete-Time Integrator' */
  if (Plant_DW.DiscreteTimeIntegrator_PrevRe_g != 0) {
    Plant_DW.DiscreteTimeIntegrator_DSTATE_b[0] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_b[1] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_b[2] = 0.0F;
  }

  /* Product: '<S82>/Product3' incorporates:
   *  Product: '<S79>/Divide'
   *  Product: '<S80>/Product6'
   */
  rtb_Sum1_f_idx_0 = rtb_Divide_o_idx_2 * rtb_Divide_o_idx_2;

  /* Product: '<S82>/Product6' incorporates:
   *  Product: '<S79>/Divide'
   *  Product: '<S80>/Product9'
   */
  rtb_Gain_kz = rtb_Divide_o_idx_1 * rtb_Divide_o_idx_3;

  /* Product: '<S82>/Product7' incorporates:
   *  Product: '<S79>/Divide'
   *  Product: '<S80>/Product2'
   */
  rtb_Add_j0_tmp = rtb_Divide_o_idx_0 * rtb_Divide_o_idx_2;

  /* Sum: '<S82>/Sum2' incorporates:
   *  Constant: '<S82>/Constant'
   *  Product: '<S79>/Divide'
   *  Product: '<S82>/Product2'
   *  Sum: '<S81>/Sum1'
   */
  rtb_Sum1_f_idx_1 = 0.5F - rtb_Divide_o_idx_1 * rtb_Divide_o_idx_1;

  /* Product: '<S82>/Product1' incorporates:
   *  Product: '<S79>/Divide'
   *  Product: '<S81>/Product2'
   */
  rtb_Sum1_f_idx_2 = rtb_Divide_o_idx_0 * rtb_Divide_o_idx_1;

  /* Product: '<S82>/Product9' incorporates:
   *  Product: '<S79>/Divide'
   *  Product: '<S81>/Product3'
   */
  rtb_Add_j0_tmp_0 = rtb_Divide_o_idx_2 * rtb_Divide_o_idx_3;

  /* Sum: '<S82>/Sum' incorporates:
   *  DiscreteIntegrator: '<S65>/Discrete-Time Integrator'
   *  Gain: '<S82>/Gain1'
   *  Gain: '<S82>/Gain2'
   *  Gain: '<S82>/Gain3'
   *  Product: '<S82>/Product1'
   *  Product: '<S82>/Product3'
   *  Product: '<S82>/Product4'
   *  Product: '<S82>/Product5'
   *  Product: '<S82>/Product6'
   *  Product: '<S82>/Product7'
   *  Product: '<S82>/Product8'
   *  Product: '<S82>/Product9'
   *  Sum: '<S82>/Sum1'
   *  Sum: '<S82>/Sum2'
   *  Sum: '<S82>/Sum3'
   */
  rtb_Add_p = ((rtb_Gain_kz + rtb_Add_j0_tmp) * 2.0F *
               Plant_DW.DiscreteTimeIntegrator_DSTATE_b[0] + (rtb_Add_j0_tmp_0 -
    rtb_Sum1_f_idx_2) * 2.0F * Plant_DW.DiscreteTimeIntegrator_DSTATE_b[1]) +
    (rtb_Sum1_f_idx_1 - rtb_Sum1_f_idx_0) * 2.0F *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_b[2];

  /* Product: '<S80>/Product7' incorporates:
   *  Product: '<S79>/Divide'
   *  Product: '<S81>/Product9'
   */
  rtb_Gain_e_tmp = rtb_Divide_o_idx_3 * rtb_Divide_o_idx_3;

  /* Product: '<S80>/Product' incorporates:
   *  Product: '<S79>/Divide'
   *  Product: '<S81>/Product6'
   */
  rtb_Divide_o_idx_1 *= rtb_Divide_o_idx_2;

  /* Product: '<S80>/Product1' incorporates:
   *  Product: '<S79>/Divide'
   *  Product: '<S81>/Product7'
   */
  rtb_Divide_o_idx_0 *= rtb_Divide_o_idx_3;

  /* Sum: '<S80>/Sum' incorporates:
   *  Constant: '<S80>/Constant'
   *  DiscreteIntegrator: '<S65>/Discrete-Time Integrator'
   *  Gain: '<S80>/Gain'
   *  Gain: '<S80>/Gain2'
   *  Gain: '<S80>/Gain3'
   *  Product: '<S80>/Product'
   *  Product: '<S80>/Product1'
   *  Product: '<S80>/Product4'
   *  Product: '<S80>/Product5'
   *  Product: '<S80>/Product7'
   *  Product: '<S80>/Product8'
   *  Sum: '<S80>/Sum1'
   *  Sum: '<S80>/Sum2'
   *  Sum: '<S80>/Sum3'
   */
  rtb_Gain_kz = (((0.5F - rtb_Sum1_f_idx_0) - rtb_Gain_e_tmp) * 2.0F *
                 Plant_DW.DiscreteTimeIntegrator_DSTATE_b[0] +
                 (rtb_Divide_o_idx_1 + rtb_Divide_o_idx_0) * 2.0F *
                 Plant_DW.DiscreteTimeIntegrator_DSTATE_b[1]) + (rtb_Gain_kz -
    rtb_Add_j0_tmp) * 2.0F * Plant_DW.DiscreteTimeIntegrator_DSTATE_b[2];

  /* Product: '<S77>/Multiply1' incorporates:
   *  DiscreteIntegrator: '<S64>/Discrete-Time Integrator'
   */
  rtb_Add_i[1] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[2] * rtb_Gain_kz;

  /* Product: '<S78>/Multiply5' incorporates:
   *  DiscreteIntegrator: '<S64>/Discrete-Time Integrator'
   */
  rtb_Sum_an[2] = Plant_DW.DiscreteTimeIntegrator_DSTATE_i[1] * rtb_Gain_kz;

  /* Sum: '<S81>/Sum' incorporates:
   *  DiscreteIntegrator: '<S65>/Discrete-Time Integrator'
   *  Gain: '<S81>/Gain1'
   *  Gain: '<S81>/Gain2'
   *  Gain: '<S81>/Gain3'
   *  Product: '<S81>/Product4'
   *  Product: '<S81>/Product5'
   *  Product: '<S81>/Product8'
   *  Sum: '<S81>/Sum1'
   *  Sum: '<S81>/Sum2'
   *  Sum: '<S81>/Sum3'
   */
  rtb_Gain_kz = ((rtb_Sum1_f_idx_1 - rtb_Gain_e_tmp) * 2.0F *
                 Plant_DW.DiscreteTimeIntegrator_DSTATE_b[1] +
                 (rtb_Divide_o_idx_1 - rtb_Divide_o_idx_0) * 2.0F *
                 Plant_DW.DiscreteTimeIntegrator_DSTATE_b[0]) +
    (rtb_Sum1_f_idx_2 + rtb_Add_j0_tmp_0) * 2.0F *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_b[2];

  /* DiscreteIntegrator: '<S65>/Discrete-Time Integrator' */
  rtb_Sum1_f_idx_0 = Plant_DW.DiscreteTimeIntegrator_DSTATE_b[0];

  /* Sum: '<S64>/Sum' incorporates:
   *  Sum: '<S66>/Sum'
   */
  rtb_Square_d[0] = rtb_Sum1_dw_idx_0 - (rtb_Sum_l[0] - rtb_Square_d[0]);

  /* Sum: '<S65>/Sum' incorporates:
   *  Constant: '<S65>/mass'
   *  DiscreteIntegrator: '<S64>/Discrete-Time Integrator'
   *  Product: '<S65>/Divide'
   *  Product: '<S77>/Multiply'
   *  Product: '<S78>/Multiply3'
   *  Sum: '<S74>/Sum'
   */
  rtb_Sum_an[0] = rtb_Add_a_idx_0 / 3.0F -
    (Plant_DW.DiscreteTimeIntegrator_DSTATE_i[1] * rtb_Add_p -
     Plant_DW.DiscreteTimeIntegrator_DSTATE_i[2] * rtb_Gain_kz);

  /* DiscreteIntegrator: '<S65>/Discrete-Time Integrator' */
  rtb_Sum1_f_idx_1 = Plant_DW.DiscreteTimeIntegrator_DSTATE_b[1];

  /* Sum: '<S64>/Sum' incorporates:
   *  Sum: '<S66>/Sum'
   */
  rtb_Square_d[1] = rtb_Sum1_dw_idx_1 - (rtb_Sum_l[1] - rtb_Square_d[1]);

  /* Sum: '<S65>/Sum' incorporates:
   *  Constant: '<S65>/mass'
   *  DiscreteIntegrator: '<S64>/Discrete-Time Integrator'
   *  Product: '<S65>/Divide'
   *  Product: '<S78>/Multiply4'
   *  Sum: '<S74>/Sum'
   */
  rtb_Sum_an[1] = rtb_Add_a_idx_1 / 3.0F - (rtb_Add_i[1] -
    Plant_DW.DiscreteTimeIntegrator_DSTATE_i[0] * rtb_Add_p);

  /* DiscreteIntegrator: '<S65>/Discrete-Time Integrator' */
  rtb_Sum1_f_idx_2 = Plant_DW.DiscreteTimeIntegrator_DSTATE_b[2];

  /* Sum: '<S65>/Sum' incorporates:
   *  Constant: '<S65>/mass'
   *  DiscreteIntegrator: '<S64>/Discrete-Time Integrator'
   *  Product: '<S65>/Divide'
   *  Product: '<S77>/Multiply2'
   *  Sum: '<S74>/Sum'
   */
  rtb_Add_p = rtb_Add_a_idx_2 / 3.0F -
    (Plant_DW.DiscreteTimeIntegrator_DSTATE_i[0] * rtb_Gain_kz - rtb_Sum_an[2]);

  /* Sum: '<S64>/Sum' incorporates:
   *  Sum: '<S66>/Sum'
   */
  rtb_Square_d[2] = rtb_Sum1_e - (rtb_Sum_l[2] - rtb_Square_d[2]);

  /* Sum: '<S85>/Sum' incorporates:
   *  Constant: '<S85>/Constant'
   *  Gain: '<S85>/Gain'
   *  Gain: '<S85>/Gain1'
   *  Gain: '<S85>/Gain2'
   *  Product: '<S84>/Divide'
   *  Product: '<S85>/Product'
   *  Product: '<S85>/Product1'
   *  Product: '<S85>/Product2'
   *  Product: '<S85>/Product3'
   *  Product: '<S85>/Product4'
   *  Product: '<S85>/Product5'
   *  Product: '<S85>/Product6'
   *  Product: '<S85>/Product7'
   *  Product: '<S85>/Product8'
   *  Sum: '<S85>/Sum1'
   *  Sum: '<S85>/Sum2'
   *  Sum: '<S85>/Sum3'
   */
  rtb_Sum1_dw_idx_0 = (((0.5F - rtb_TrigonometricFunction1_id_0 *
    rtb_TrigonometricFunction1_id_0) - rtb_TrigonometricFunction1_idx_ *
                        rtb_TrigonometricFunction1_idx_) * 2.0F * rtb_Sum_an[0]
                       + (rtb_Divide_k_idx_1 * rtb_TrigonometricFunction1_id_0 -
    rtb_Sum_fe * rtb_TrigonometricFunction1_idx_) * 2.0F * rtb_Sum_an[1]) +
    (rtb_Divide_k_idx_1 * rtb_TrigonometricFunction1_idx_ + rtb_Sum_fe *
     rtb_TrigonometricFunction1_id_0) * 2.0F * rtb_Add_p;

  /* Sum: '<S86>/Sum' incorporates:
   *  Constant: '<S86>/Constant'
   *  Gain: '<S86>/Gain'
   *  Gain: '<S86>/Gain1'
   *  Gain: '<S86>/Gain2'
   *  Product: '<S84>/Divide'
   *  Product: '<S86>/Product'
   *  Product: '<S86>/Product1'
   *  Product: '<S86>/Product2'
   *  Product: '<S86>/Product3'
   *  Product: '<S86>/Product4'
   *  Product: '<S86>/Product5'
   *  Product: '<S86>/Product6'
   *  Product: '<S86>/Product7'
   *  Product: '<S86>/Product8'
   *  Sum: '<S86>/Sum1'
   *  Sum: '<S86>/Sum2'
   *  Sum: '<S86>/Sum3'
   */
  rtb_Sum1_dw_idx_1 = (((0.5F - rtb_Divide_k_idx_1 * rtb_Divide_k_idx_1) -
                        rtb_TrigonometricFunction1_idx_ *
                        rtb_TrigonometricFunction1_idx_) * 2.0F * rtb_Sum_an[1]
                       + (rtb_Divide_k_idx_1 * rtb_TrigonometricFunction1_id_0 +
    rtb_Sum_fe * rtb_TrigonometricFunction1_idx_) * 2.0F * rtb_Sum_an[0]) +
    (rtb_TrigonometricFunction1_id_0 * rtb_TrigonometricFunction1_idx_ -
     rtb_Sum_fe * rtb_Divide_k_idx_1) * 2.0F * rtb_Add_p;

  /* Sum: '<S87>/Sum' incorporates:
   *  Constant: '<S87>/Constant'
   *  Gain: '<S87>/Gain1'
   *  Gain: '<S87>/Gain2'
   *  Gain: '<S87>/Gain3'
   *  Product: '<S84>/Divide'
   *  Product: '<S87>/Product1'
   *  Product: '<S87>/Product2'
   *  Product: '<S87>/Product3'
   *  Product: '<S87>/Product4'
   *  Product: '<S87>/Product5'
   *  Product: '<S87>/Product6'
   *  Product: '<S87>/Product7'
   *  Product: '<S87>/Product8'
   *  Product: '<S87>/Product9'
   *  Sum: '<S87>/Sum1'
   *  Sum: '<S87>/Sum2'
   *  Sum: '<S87>/Sum3'
   */
  rtb_Sum_fe = ((rtb_Divide_k_idx_1 * rtb_TrigonometricFunction1_idx_ -
                 rtb_Sum_fe * rtb_TrigonometricFunction1_id_0) * 2.0F *
                rtb_Sum_an[0] + (rtb_Sum_fe * rtb_Divide_k_idx_1 +
    rtb_TrigonometricFunction1_id_0 * rtb_TrigonometricFunction1_idx_) * 2.0F *
                rtb_Sum_an[1]) + ((0.5F - rtb_Divide_k_idx_1 *
    rtb_Divide_k_idx_1) - rtb_TrigonometricFunction1_id_0 *
    rtb_TrigonometricFunction1_id_0) * 2.0F * rtb_Add_p;

  /* Math: '<S67>/Square1' incorporates:
   *  Product: '<S71>/Divide'
   */
  rtb_Add_p = rtb_TrigonometricFunction1_id_3 * rtb_TrigonometricFunction1_id_3;

  /* Product: '<S67>/Multiply6' incorporates:
   *  Constant: '<S67>/Constant'
   *  Product: '<S67>/Multiply4'
   *  Product: '<S67>/Multiply5'
   *  Product: '<S71>/Divide'
   *  Sum: '<S67>/Subtract'
   */
  rtb_Divide_k_idx_1 = (rtb_TrigonometricFunction1_id_1 *
                        rtb_TrigonometricFunction1_id_3 -
                        rtb_TrigonometricFunction1_id_4 *
                        rtb_TrigonometricFunction1_id_2) * 2.0F;

  /* DiscreteIntegrator: '<S65>/Discrete-Time Integrator1' */
  if (Plant_DW.DiscreteTimeIntegrator1_PrevRes != 0) {
    Plant_DW.DiscreteTimeIntegrator1_DSTATE[0] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator1_DSTATE[1] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator1_DSTATE[2] = 0.0F;
  }

  rtb_Sum_an[0] = Plant_DW.DiscreteTimeIntegrator1_DSTATE[0];
  rtb_Sum_an[1] = Plant_DW.DiscreteTimeIntegrator1_DSTATE[1];
  rtb_Sum_an[2] = Plant_DW.DiscreteTimeIntegrator1_DSTATE[2];

  /* End of DiscreteIntegrator: '<S65>/Discrete-Time Integrator1' */

  /* Product: '<S68>/Multiply' incorporates:
   *  DiscreteIntegrator: '<S68>/Discrete-Time Integrator'
   */
  for (i = 0; i < 4; i++) {
    rtb_Gain_kz = rtb_MatrixConcatenate4[i + 12] *
      Plant_DW.DiscreteTimeIntegrator_DSTATE_k[3] + (rtb_MatrixConcatenate4[i +
      8] * Plant_DW.DiscreteTimeIntegrator_DSTATE_k[2] +
      (rtb_MatrixConcatenate4[i + 4] * Plant_DW.DiscreteTimeIntegrator_DSTATE_k
       [1] + rtb_MatrixConcatenate4[i] *
       Plant_DW.DiscreteTimeIntegrator_DSTATE_k[0]));
    rtb_MatrixConcatenate4_0[i] = rtb_Gain_kz;
  }

  /* End of Product: '<S68>/Multiply' */

  /* Update for DiscreteIntegrator: '<S68>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S68>/Gain'
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

  /* Product: '<S64>/Divide' incorporates:
   *  Constant: '<S64>/Inertia_Matrix'
   */
  rt_mldivide_U1f3x3_U2f3x1_Yf3x1(Plant_ConstP.Inertia_Matrix_Value,
    rtb_Square_d, tmp);

  /* Update for DiscreteIntegrator: '<S64>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_PrevRe_p = 0;

  /* Update for DiscreteIntegrator: '<S65>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_PrevRe_g = 0;

  /* Update for DiscreteIntegrator: '<S64>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_i[0] += 0.002F * tmp[0];

  /* Update for DiscreteIntegrator: '<S65>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_b[0] += 0.002F * rtb_Sum1_dw_idx_0;

  /* Update for DiscreteIntegrator: '<S65>/Discrete-Time Integrator1' */
  Plant_DW.DiscreteTimeIntegrator1_DSTATE[0] += 0.002F * rtb_Sum1_f_idx_0;

  /* Update for DiscreteIntegrator: '<S64>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_i[1] += 0.002F * tmp[1];

  /* Update for DiscreteIntegrator: '<S65>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_b[1] += 0.002F * rtb_Sum1_dw_idx_1;

  /* Update for DiscreteIntegrator: '<S65>/Discrete-Time Integrator1' */
  Plant_DW.DiscreteTimeIntegrator1_DSTATE[1] += 0.002F * rtb_Sum1_f_idx_1;

  /* Update for DiscreteIntegrator: '<S64>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_i[2] += 0.002F * tmp[2];

  /* Update for DiscreteIntegrator: '<S65>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_b[2] += 0.002F * rtb_Sum_fe;

  /* Update for DiscreteIntegrator: '<S65>/Discrete-Time Integrator1' */
  Plant_DW.DiscreteTimeIntegrator1_DSTATE[2] += 0.002F * rtb_Sum1_f_idx_2;
  Plant_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* End of Outputs for SubSystem: '<Root>/Kinematic_Equation' */

  /* Outputs for Atomic SubSystem: '<Root>/Bus_Constructor' */
  /* Sqrt: '<S49>/Sqrt' incorporates:
   *  Math: '<S49>/Square'
   *  Sum: '<S49>/Sum of Elements'
   */
  rtb_Gain_kz = sqrtf(((rtb_DiscreteTimeIntegrator_id_1 *
                        rtb_DiscreteTimeIntegrator_id_1 +
                        rtb_DiscreteTimeIntegrator_id_0 *
                        rtb_DiscreteTimeIntegrator_id_0) + rtb_MathFunction1_k *
                       rtb_MathFunction1_k) + rtb_DiscreteTimeIntegrator_idx_ *
                      rtb_DiscreteTimeIntegrator_idx_);

  /* Product: '<S45>/Divide' */
  rtb_TrigonometricFunction1_id_0 = rtb_DiscreteTimeIntegrator_id_1 /
    rtb_Gain_kz;
  rtb_TrigonometricFunction1_idx_ = rtb_DiscreteTimeIntegrator_id_0 /
    rtb_Gain_kz;
  rtb_Add_a_idx_0 = rtb_MathFunction1_k / rtb_Gain_kz;
  rtb_Add_a_idx_1 = rtb_DiscreteTimeIntegrator_idx_ / rtb_Gain_kz;

  /* Math: '<S46>/Square' incorporates:
   *  Math: '<S47>/Square'
   *  Math: '<S48>/Square'
   */
  rtb_Gain_kz = rtb_TrigonometricFunction1_id_0 *
    rtb_TrigonometricFunction1_id_0;

  /* Sum: '<S46>/Subtract' incorporates:
   *  Math: '<S46>/Square'
   *  Math: '<S46>/Square1'
   *  Math: '<S46>/Square2'
   *  Math: '<S46>/Square3'
   *  Sum: '<S46>/Add'
   *  Sum: '<S46>/Add1'
   */
  rtb_VectorConcatenate_f[0] = (rtb_Gain_kz + rtb_TrigonometricFunction1_idx_ *
    rtb_TrigonometricFunction1_idx_) - (rtb_Add_a_idx_0 * rtb_Add_a_idx_0 +
    rtb_Add_a_idx_1 * rtb_Add_a_idx_1);

  /* Gain: '<S46>/Gain' incorporates:
   *  Product: '<S46>/Multiply'
   *  Product: '<S46>/Multiply1'
   *  Sum: '<S46>/Subtract1'
   */
  rtb_VectorConcatenate_f[1] = (rtb_TrigonometricFunction1_idx_ *
    rtb_Add_a_idx_0 - rtb_TrigonometricFunction1_id_0 * rtb_Add_a_idx_1) * 2.0F;

  /* Gain: '<S46>/Gain1' incorporates:
   *  Product: '<S46>/Multiply2'
   *  Product: '<S46>/Multiply3'
   *  Sum: '<S46>/Add2'
   */
  rtb_VectorConcatenate_f[2] = (rtb_TrigonometricFunction1_idx_ *
    rtb_Add_a_idx_1 + rtb_TrigonometricFunction1_id_0 * rtb_Add_a_idx_0) * 2.0F;

  /* Gain: '<S47>/Gain' incorporates:
   *  Product: '<S47>/Multiply'
   *  Product: '<S47>/Multiply1'
   *  Sum: '<S47>/Add3'
   */
  rtb_VectorConcatenate_f[3] = (rtb_TrigonometricFunction1_idx_ *
    rtb_Add_a_idx_0 + rtb_TrigonometricFunction1_id_0 * rtb_Add_a_idx_1) * 2.0F;

  /* Sum: '<S47>/Subtract' incorporates:
   *  Math: '<S47>/Square1'
   *  Math: '<S47>/Square2'
   *  Math: '<S47>/Square3'
   *  Sum: '<S47>/Add'
   *  Sum: '<S47>/Add1'
   */
  rtb_VectorConcatenate_f[4] = (rtb_Gain_kz + rtb_Add_a_idx_0 * rtb_Add_a_idx_0)
    - (rtb_TrigonometricFunction1_idx_ * rtb_TrigonometricFunction1_idx_ +
       rtb_Add_a_idx_1 * rtb_Add_a_idx_1);

  /* Gain: '<S47>/Gain1' incorporates:
   *  Product: '<S47>/Multiply2'
   *  Product: '<S47>/Multiply3'
   *  Sum: '<S47>/Subtract1'
   */
  rtb_VectorConcatenate_f[5] = (rtb_Add_a_idx_0 * rtb_Add_a_idx_1 -
    rtb_TrigonometricFunction1_id_0 * rtb_TrigonometricFunction1_idx_) * 2.0F;

  /* Gain: '<S48>/Gain' incorporates:
   *  Product: '<S48>/Multiply'
   *  Product: '<S48>/Multiply1'
   *  Sum: '<S48>/Subtract2'
   */
  rtb_VectorConcatenate_f[6] = (rtb_TrigonometricFunction1_idx_ *
    rtb_Add_a_idx_1 - rtb_TrigonometricFunction1_id_0 * rtb_Add_a_idx_0) * 2.0F;

  /* Gain: '<S48>/Gain1' incorporates:
   *  Product: '<S48>/Multiply2'
   *  Product: '<S48>/Multiply3'
   *  Sum: '<S48>/Add2'
   */
  rtb_VectorConcatenate_f[7] = (rtb_Add_a_idx_0 * rtb_Add_a_idx_1 +
    rtb_TrigonometricFunction1_id_0 * rtb_TrigonometricFunction1_idx_) * 2.0F;

  /* Sum: '<S48>/Subtract' incorporates:
   *  Math: '<S48>/Square1'
   *  Math: '<S48>/Square2'
   *  Math: '<S48>/Square3'
   *  Sum: '<S48>/Add'
   *  Sum: '<S48>/Add1'
   */
  rtb_VectorConcatenate_f[8] = (rtb_Gain_kz + rtb_Add_a_idx_1 * rtb_Add_a_idx_1)
    - (rtb_TrigonometricFunction1_idx_ * rtb_TrigonometricFunction1_idx_ +
       rtb_Add_a_idx_0 * rtb_Add_a_idx_0);

  /* BusAssignment: '<S2>/Bus Assignment2' incorporates:
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S2>/Constant5'
   *  Delay: '<Root>/Delay'
   *  Math: '<S2>/Square'
   *  SignalConversion: '<S2>/TmpHiddenBufferAtBus Assignment2Inport1'
   */
  Plant_Y.Extended_States = Plant_rtZExtended_States_Bus;
  Plant_Y.Extended_States.temprature = 25.0F;
  for (i = 0; i < 8; i++) {
    Plant_Y.Extended_States.prop_vel[i] = 0.0F;
  }

  for (i = 0; i < 9; i++) {
    Plant_Y.Extended_States.M_BO[i] = rtb_VectorConcatenate_f[i];
  }

  for (i = 0; i < 3; i++) {
    Plant_Y.Extended_States.M_OB[3 * i] = rtb_VectorConcatenate_f[i];
    Plant_Y.Extended_States.M_OB[1 + 3 * i] = rtb_VectorConcatenate_f[i + 3];
    Plant_Y.Extended_States.M_OB[2 + 3 * i] = rtb_VectorConcatenate_f[i + 6];
  }

  Plant_Y.Extended_States.quat[0] = rtb_DiscreteTimeIntegrator_id_1;
  Plant_Y.Extended_States.quat[1] = rtb_DiscreteTimeIntegrator_id_0;
  Plant_Y.Extended_States.quat[2] = rtb_MathFunction1_k;
  Plant_Y.Extended_States.quat[3] = rtb_DiscreteTimeIntegrator_idx_;
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
   *  Constant: '<S67>/Constant'
   *  Constant: '<S67>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Math: '<S67>/Square'
   *  Product: '<S67>/Multiply'
   *  Product: '<S67>/Multiply1'
   *  Product: '<S67>/Multiply2'
   *  Product: '<S67>/Multiply3'
   *  Product: '<S71>/Divide'
   *  Sum: '<S67>/Add'
   *  Sum: '<S67>/Add1'
   *  Sum: '<S67>/Subtract2'
   *  Trigonometry: '<S67>/Atan2'
   */
  Plant_Y.Plant_States.phi = atan2f((rtb_TrigonometricFunction1_id_1 *
    rtb_TrigonometricFunction1_id_2 + rtb_TrigonometricFunction1_id_3 *
    rtb_TrigonometricFunction1_id_4) * 2.0F, 1.0F - 2.0F *
    (rtb_TrigonometricFunction1_id_2 * rtb_TrigonometricFunction1_id_2 +
     rtb_Add_p));

  /* End of Outputs for SubSystem: '<Root>/Bus_Constructor' */

  /* Saturate: '<S67>/Saturation' */
  if (rtb_Divide_k_idx_1 > 1.0F) {
    rtb_Divide_k_idx_1 = 1.0F;
  } else {
    if (rtb_Divide_k_idx_1 < -1.0F) {
      rtb_Divide_k_idx_1 = -1.0F;
    }
  }

  /* End of Saturate: '<S67>/Saturation' */

  /* Outputs for Atomic SubSystem: '<Root>/Bus_Constructor' */
  /* BusAssignment: '<S2>/Bus Assignment' incorporates:
   *  BusAssignment: '<S2>/Bus Assignment1'
   *  Constant: '<S67>/Constant'
   *  Constant: '<S67>/Constant1'
   *  Delay: '<Root>/Delay'
   *  Math: '<S67>/Square2'
   *  Product: '<S67>/Multiply10'
   *  Product: '<S67>/Multiply7'
   *  Product: '<S67>/Multiply8'
   *  Product: '<S67>/Multiply9'
   *  Product: '<S71>/Divide'
   *  Sum: '<S67>/Add2'
   *  Sum: '<S67>/Add3'
   *  Sum: '<S67>/Subtract1'
   *  Trigonometry: '<S67>/Asin'
   *  Trigonometry: '<S67>/Atan1'
   */
  Plant_Y.Plant_States.theta = asinf(rtb_Divide_k_idx_1);
  Plant_Y.Plant_States.psi = atan2f((rtb_TrigonometricFunction1_id_1 *
    rtb_TrigonometricFunction1_id_4 + rtb_TrigonometricFunction1_id_2 *
    rtb_TrigonometricFunction1_id_3) * 2.0F, 1.0F - 2.0F *
    (rtb_TrigonometricFunction1_id_4 * rtb_TrigonometricFunction1_id_4 +
     rtb_Add_p));

  /* End of Outputs for SubSystem: '<Root>/Kinematic_Equation' */
  Plant_Y.Plant_States.rot_x_B = rtb_DiscreteTimeIntegrator5_i_1;
  Plant_Y.Plant_States.rot_y_B = rtb_DiscreteTimeIntegrator5_i_0;
  Plant_Y.Plant_States.rot_z_B = rtb_DiscreteTimeIntegrator5_idx;
  Plant_Y.Plant_States.acc_x_O = rtb_Sum1_dw_idx_0;
  Plant_Y.Plant_States.acc_y_O = rtb_Sum1_dw_idx_1;
  Plant_Y.Plant_States.acc_z_O = rtb_Sum_fe;
  Plant_Y.Plant_States.vel_x_O = rtb_Sum1_f_idx_0;
  Plant_Y.Plant_States.vel_y_O = rtb_Sum1_f_idx_1;
  Plant_Y.Plant_States.vel_z_O = rtb_Sum1_f_idx_2;

  /* Trigonometry: '<S50>/Trigonometric Function1' incorporates:
   *  Delay: '<S44>/Delay1'
   *  Trigonometry: '<S50>/Trigonometric Function2'
   */
  rtb_TrigonometricFunction2 = cos(Plant_DW.Delay1_DSTATE[0]);

  /* Trigonometry: '<S50>/Trigonometric Function' incorporates:
   *  Delay: '<S44>/Delay1'
   */
  rtb_SumofElements = sin(Plant_DW.Delay1_DSTATE[0]);

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
  rtb_SumofElements1 += Plant_DW.Delay1_DSTATE[2];

  /* Sum: '<S50>/Add1' incorporates:
   *  Delay: '<S44>/Delay1'
   */
  rtb_SumofElements += Plant_DW.Delay1_DSTATE[2];

  /* Product: '<S50>/Product4' */
  rtb_SumofElements *= rtb_TrigonometricFunction2;

  /* BusAssignment: '<S2>/Bus Assignment1' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S2>/Gain'
   */
  Plant_Y.Plant_States.x_R = rtb_Sum_an[0];
  Plant_Y.Plant_States.y_R = rtb_Sum_an[1];
  Plant_Y.Plant_States.h_R = -rtb_Sum_an[2];

  /* Signum: '<S51>/Sign' */
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

  /* Switch: '<S51>/Switch' incorporates:
   *  Constant: '<S51>/Constant'
   */
  if (rtb_TrigonometricFunction2 == 0.0) {
    rtb_Cl_xA = 1.0;
  }

  /* Abs: '<S51>/Abs' */
  rtb_SumofElements1 = fabs(rtb_SumofElements1);

  /* Saturate: '<S51>/Saturation' */
  if (rtb_SumofElements1 > 1.0E+8) {
    rtb_SumofElements1 = 1.0E+8;
  } else {
    if (rtb_SumofElements1 < 1.0E-6) {
      rtb_SumofElements1 = 1.0E-6;
    }
  }

  /* Sum: '<S44>/Add' incorporates:
   *  Abs: '<S51>/Abs'
   *  DataTypeConversion: '<S44>/Data Type Conversion'
   *  Delay: '<S44>/Delay'
   *  Delay: '<S44>/Delay1'
   *  Product: '<S44>/Divide'
   *  Product: '<S51>/Product'
   *  Sum: '<S44>/Subtract'
   */
  Plant_DW.Delay1_DSTATE[0] += 1.0 / (rtb_SumofElements1 * rtb_Cl_xA) *
    (rtb_Sum_an[0] - Plant_DW.Delay_DSTATE_f[0]);

  /* Update for Delay: '<S44>/Delay' incorporates:
   *  DataTypeConversion: '<S44>/Data Type Conversion'
   */
  Plant_DW.Delay_DSTATE_f[0] = rtb_Sum_an[0];

  /* Signum: '<S51>/Sign' */
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

  /* Switch: '<S51>/Switch' incorporates:
   *  Constant: '<S51>/Constant'
   */
  if (rtb_SumofElements1 == 0.0) {
    rtb_Cl_xA = 1.0;
  }

  /* Abs: '<S51>/Abs' */
  rtb_SumofElements1 = fabs(rtb_SumofElements);

  /* Saturate: '<S51>/Saturation' */
  if (rtb_SumofElements1 > 1.0E+8) {
    rtb_SumofElements1 = 1.0E+8;
  } else {
    if (rtb_SumofElements1 < 1.0E-6) {
      rtb_SumofElements1 = 1.0E-6;
    }
  }

  /* Sum: '<S44>/Add' incorporates:
   *  Abs: '<S51>/Abs'
   *  DataTypeConversion: '<S44>/Data Type Conversion'
   *  Delay: '<S44>/Delay'
   *  Delay: '<S44>/Delay1'
   *  Product: '<S44>/Divide'
   *  Product: '<S51>/Product'
   *  Sum: '<S44>/Subtract'
   */
  Plant_DW.Delay1_DSTATE[1] += 1.0 / (rtb_SumofElements1 * rtb_Cl_xA) *
    (rtb_Sum_an[1] - Plant_DW.Delay_DSTATE_f[1]);

  /* Update for Delay: '<S44>/Delay' incorporates:
   *  DataTypeConversion: '<S44>/Data Type Conversion'
   */
  Plant_DW.Delay_DSTATE_f[1] = rtb_Sum_an[1];

  /* Sum: '<S44>/Add' incorporates:
   *  Abs: '<S51>/Abs'
   *  DataTypeConversion: '<S44>/Data Type Conversion'
   *  Delay: '<S44>/Delay'
   *  Delay: '<S44>/Delay1'
   *  Product: '<S44>/Divide'
   *  Sum: '<S44>/Subtract'
   */
  Plant_DW.Delay1_DSTATE[2] += -(rtb_Sum_an[2] - Plant_DW.Delay_DSTATE_f[2]);

  /* Update for Delay: '<S44>/Delay' incorporates:
   *  DataTypeConversion: '<S44>/Data Type Conversion'
   */
  Plant_DW.Delay_DSTATE_f[2] = rtb_Sum_an[2];

  /* BusAssignment: '<S2>/Bus Assignment1' incorporates:
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant2'
   *  Constant: '<S2>/Constant3'
   *  Delay: '<Root>/Delay'
   *  Delay: '<S42>/Delay'
   *  Delay: '<S44>/Delay1'
   */
  Plant_Y.Plant_States.lat = Plant_DW.Delay1_DSTATE[0];
  Plant_Y.Plant_States.lon = Plant_DW.Delay1_DSTATE[1];
  Plant_Y.Plant_States.alt = Plant_DW.Delay1_DSTATE[2];
  Plant_Y.Plant_States.lat_0 = 0.65673;
  Plant_Y.Plant_States.lon_0 = -2.1361;
  Plant_Y.Plant_States.alt_0 = 4.5;
  Plant_Y.Plant_States.timestamp = Plant_DW.Delay_DSTATE_h;

  /* Sum: '<S42>/Sum' incorporates:
   *  Constant: '<S42>/dt'
   *  Delay: '<S42>/Delay'
   */
  Plant_DW.Delay_DSTATE_h += PLANT_EXPORT.period;

  /* End of Outputs for SubSystem: '<Root>/Bus_Constructor' */

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_Model' */
  /* Outputs for Atomic SubSystem: '<S6>/Sensor_Airspeed' */
  /* BusAssignment: '<S96>/Bus Assignment' incorporates:
   *  Constant: '<S96>/Constant'
   *  Delay: '<Root>/Delay'
   *  Gain: '<S95>/Gain'
   *  Math: '<S95>/Square'
   *  Memory: '<S89>/Memory1'
   */
  rtb_BusAssignment_f = Plant_rtZAirSpeed_Bus;
  rtb_BusAssignment_f.timestamp = Plant_DW.Memory1_PreviousInput;
  rtb_BusAssignment_f.diff_pressure = Plant_Y.Extended_States.Va *
    Plant_Y.Extended_States.Va * 0.6125F;

  /* RateTransition: '<S96>/Rate Transition' */
  if (Plant_M->Timing.TaskCounters.TID[1] == 0) {
    Plant_B.RateTransition_e = rtb_BusAssignment_f;
  }

  /* End of RateTransition: '<S96>/Rate Transition' */
  /* End of Outputs for SubSystem: '<S6>/Sensor_Airspeed' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_Barometer' */
  /* Saturate: '<S101>/Limit  altitude  to troposhere' incorporates:
   *  DataTypeConversion: '<S99>/Data Type Conversion'
   *  Delay: '<Root>/Delay'
   */
  if ((real32_T)Plant_Y.Plant_States.alt > 11000.0F) {
    rtb_Add_p = 11000.0F;
  } else if ((real32_T)Plant_Y.Plant_States.alt < 0.0F) {
    rtb_Add_p = 0.0F;
  } else {
    rtb_Add_p = (real32_T)Plant_Y.Plant_States.alt;
  }

  /* End of Saturate: '<S101>/Limit  altitude  to troposhere' */

  /* Sum: '<S101>/Sum1' incorporates:
   *  Constant: '<S101>/Sea Level  Temperature'
   *  Gain: '<S101>/Lapse Rate'
   */
  rtb_DiscreteTimeIntegrator_id_1 = 288.15F - 0.0065F * rtb_Add_p;

  /* Sum: '<S101>/Sum' incorporates:
   *  Constant: '<S101>/Altitude of Troposphere'
   *  DataTypeConversion: '<S99>/Data Type Conversion'
   *  Delay: '<Root>/Delay'
   */
  rtb_MathFunction1_k = 11000.0F - (real32_T)Plant_Y.Plant_States.alt;

  /* Saturate: '<S101>/Limit  altitude  to Stratosphere' incorporates:
   *  Constant: '<S101>/Altitude of Troposphere'
   *  DataTypeConversion: '<S99>/Data Type Conversion'
   *  Delay: '<Root>/Delay'
   *  Sum: '<S101>/Sum'
   */
  if (11000.0F - (real32_T)Plant_Y.Plant_States.alt > 0.0F) {
    rtb_MathFunction1_k = 0.0F;
  } else {
    if (11000.0F - (real32_T)Plant_Y.Plant_States.alt < -9000.0F) {
      rtb_MathFunction1_k = -9000.0F;
    }
  }

  /* End of Saturate: '<S101>/Limit  altitude  to Stratosphere' */

  /* Product: '<S101>/Product2' incorporates:
   *  Constant: '<S101>/Constant'
   *  Gain: '<S101>/1//T0'
   *  Gain: '<S101>/P0'
   *  Gain: '<S101>/g//R'
   *  Math: '<S101>/(T//T0)^(g//LR) '
   *  Math: '<S101>/Stratosphere Model'
   *  Product: '<S101>/Product1'
   *
   * About '<S101>/Stratosphere Model':
   *  Operator: exp
   */
  rtb_DiscreteTimeIntegrator_id_0 = powf(0.00347041478F *
    rtb_DiscreteTimeIntegrator_id_1, 5.25587559F) * 101325.0F * expf(1.0F /
    rtb_DiscreteTimeIntegrator_id_1 * (0.0341631919F * rtb_MathFunction1_k));

  /* S-Function (sdsprandsrc2): '<S103>/Random Source' */
  RandSrc_GZ_R(&rtb_MathFunction1_k, &Plant_ConstP.pooled27, 1,
               &Plant_ConstP.pooled36, 1, Plant_DW.RandomSource_STATE_DWORK_fn,
               1, 1);

  /* BusAssignment: '<S98>/Bus Assignment' incorporates:
   *  Constant: '<S98>/Constant2'
   *  DataTypeConversion: '<S98>/Data Type Conversion1'
   *  Memory: '<S89>/Memory1'
   *  Saturate: '<S100>/Saturation'
   *  Sum: '<S100>/Add'
   *  Sum: '<S98>/Sum1'
   */
  rtb_BusAssignment_c.timestamp = Plant_DW.Memory1_PreviousInput;
  rtb_BusAssignment_c.pressure = rtb_DiscreteTimeIntegrator_id_0 +
    rtb_MathFunction1_k;
  rtb_BusAssignment_c.temperature = (real32_T)(rtb_DiscreteTimeIntegrator_id_1 -
    273.15);

  /* RateTransition: '<S98>/Rate Transition' */
  if (Plant_M->Timing.TaskCounters.TID[2] == 0) {
    Plant_B.RateTransition_p = rtb_BusAssignment_c;
  }

  /* End of RateTransition: '<S98>/Rate Transition' */
  /* End of Outputs for SubSystem: '<S6>/Sensor_Barometer' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_GPS' */
  /* Trigonometry: '<S116>/Sin' incorporates:
   *  Delay: '<S109>/Delay'
   */
  rtb_SumofElements = sin(Plant_DW.Delay_DSTATE[0]);

  /* Math: '<S116>/Square1' */
  rtb_SumofElements *= rtb_SumofElements;

  /* Product: '<S116>/Multiply1' incorporates:
   *  Product: '<S116>/Multiply'
   */
  rtb_Cl_xA = Plant_ConstB.ff * rtb_SumofElements;

  /* Product: '<S116>/Divide' incorporates:
   *  Constant: '<S116>/Constant'
   *  Constant: '<S116>/R'
   *  Sqrt: '<S116>/Sqrt'
   *  Sum: '<S116>/Sum1'
   */
  rtb_SumofElements = 6.378137E+6 / sqrt(1.0 - rtb_Cl_xA);

  /* Trigonometry: '<S116>/Cos' incorporates:
   *  Delay: '<S109>/Delay'
   */
  rtb_SumofElements1 = cos(Plant_DW.Delay_DSTATE[0]);

  /* S-Function (sdsprandsrc2): '<S112>/Random Source' */
  RandSrc_GZ_R(rtb_RandomSource, &Plant_ConstP.pooled27, 1,
               Plant_ConstP.RandomSource_VarianceRTP, 3,
               Plant_DW.RandomSource_STATE_DWORK_f2, 3, 1);

  /* Sum: '<S110>/Sum2' incorporates:
   *  Constant: '<S116>/Constant1'
   *  Delay: '<S109>/Delay'
   *  Product: '<S113>/Divide2'
   *  Product: '<S116>/Multiply1'
   *  Product: '<S116>/Multiply2'
   *  Product: '<S116>/Product3'
   *  Sum: '<S116>/Sum2'
   */
  rtb_Cl_xA = rtb_RandomSource[0] / (1.0 / (1.0 - rtb_Cl_xA) * Plant_ConstB.Sum4
    * rtb_SumofElements) + Plant_DW.Delay_DSTATE[0];
  rtb_TrigonometricFunction2 = rtb_RandomSource[1] / (rtb_SumofElements *
    rtb_SumofElements1) + Plant_DW.Delay_DSTATE[1];
  rtb_Cm = rtb_RandomSource[2] / -1.0 + Plant_DW.Delay_DSTATE[2];

  /* S-Function (sdsprandsrc2): '<S112>/Random Source1' */
  RandSrc_GZ_R(rtb_RandomSource1, &Plant_ConstP.pooled27, 1,
               Plant_ConstP.RandomSource1_VarianceRTP, 3,
               Plant_DW.RandomSource1_STATE_DWORK, 3, 1);

  /* Sum: '<S110>/Sum1' incorporates:
   *  Delay: '<S109>/Delay1'
   */
  rtb_Add_i[0] = rtb_RandomSource1[0] + Plant_DW.Delay1_DSTATE_j[0];
  rtb_Add_i[1] = rtb_RandomSource1[1] + Plant_DW.Delay1_DSTATE_j[1];
  rtb_Add_i[2] = rtb_RandomSource1[2] + Plant_DW.Delay1_DSTATE_j[2];

  /* DiscreteFir: '<S115>/Discrete FIR Filter' */
  rtb_Va_B[0] = rtb_Add_i[0] * 0.5F + Plant_DW.DiscreteFIRFilter_states_i[0] *
    0.5F;
  rtb_Va_B[1] = rtb_Add_i[1] * 0.5F + Plant_DW.DiscreteFIRFilter_states_i[1] *
    0.5F;

  /* Gain: '<S104>/Gain6' incorporates:
   *  Math: '<S111>/Math Function'
   *  Product: '<S111>/Matrix Multiply'
   *  Sqrt: '<S111>/Sqrt'
   *  Switch: '<S111>/Switch'
   */
  rtb_SumofElements = fmod(floor(sqrtf(rtb_RandomSource[0] * rtb_RandomSource[0]
    + rtb_RandomSource[1] * rtb_RandomSource[1]) * 1000.0), 4.294967296E+9);

  /* Gain: '<S104>/Gain4' incorporates:
   *  DiscreteFir: '<S114>/Discrete FIR Filter'
   */
  rtb_SumofElements1 = fmod(floor((rtb_Cm * 0.5 +
    Plant_DW.DiscreteFIRFilter_states[2] * 0.5) * 1000.0), 4.294967296E+9);
  i = rtb_SumofElements1 < 0.0 ? -(int32_T)(uint32_T)-rtb_SumofElements1 :
    (int32_T)(uint32_T)rtb_SumofElements1;

  /* Gain: '<S104>/Gain5' incorporates:
   *  Math: '<S111>/Math Function2'
   *  Product: '<S111>/Matrix Multiply2'
   *  Sqrt: '<S111>/Sqrt2'
   *  Switch: '<S111>/Switch1'
   */
  rtb_SumofElements1 = fmod(floor(sqrtf(rtb_RandomSource[2] * rtb_RandomSource[2])
    * 1000.0), 4.294967296E+9);

  /* BusAssignment: '<S104>/Bus Assignment' incorporates:
   *  Constant: '<S104>/Constant10'
   *  Constant: '<S104>/Constant11'
   *  Constant: '<S104>/Constant12'
   *  Constant: '<S104>/Constant2'
   *  Constant: '<S104>/Constant3'
   *  Constant: '<S104>/Constant4'
   *  Constant: '<S104>/Constant5'
   *  Constant: '<S104>/Constant6'
   *  Constant: '<S104>/Constant7'
   *  Constant: '<S104>/Constant8'
   *  Constant: '<S104>/Constant9'
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

  /* Gain: '<S104>/Gain' incorporates:
   *  DiscreteFir: '<S114>/Discrete FIR Filter'
   *  Gain: '<S104>/Gain2'
   */
  rtb_Divide_e_idx_1 = fmod(floor((rtb_Cl_xA * 0.5 +
    Plant_DW.DiscreteFIRFilter_states[0] * 0.5) * 57.295779513082323 * 1.0E+7),
    4.294967296E+9);

  /* BusAssignment: '<S104>/Bus Assignment' incorporates:
   *  Gain: '<S104>/Gain'
   */
  rtb_BusAssignment_e.lon = rtb_Divide_e_idx_1 < 0.0 ? -(int32_T)(uint32_T)
    -rtb_Divide_e_idx_1 : (int32_T)(uint32_T)rtb_Divide_e_idx_1;

  /* Gain: '<S104>/Gain1' incorporates:
   *  DiscreteFir: '<S114>/Discrete FIR Filter'
   *  Gain: '<S104>/Gain3'
   */
  rtb_Divide_e_idx_1 = fmod(floor((rtb_TrigonometricFunction2 * 0.5 +
    Plant_DW.DiscreteFIRFilter_states[1] * 0.5) * 57.295779513082323 * 1.0E+7),
    4.294967296E+9);

  /* BusAssignment: '<S104>/Bus Assignment' incorporates:
   *  Gain: '<S104>/Gain1'
   *  Gain: '<S104>/Gain5'
   *  Gain: '<S104>/Gain6'
   */
  rtb_BusAssignment_e.lat = rtb_Divide_e_idx_1 < 0.0 ? -(int32_T)(uint32_T)
    -rtb_Divide_e_idx_1 : (int32_T)(uint32_T)rtb_Divide_e_idx_1;
  rtb_BusAssignment_e.height = i;
  rtb_BusAssignment_e.hMSL = i;
  rtb_BusAssignment_e.hAcc = rtb_SumofElements < 0.0 ? (uint32_T)-(int32_T)
    (uint32_T)-rtb_SumofElements : (uint32_T)rtb_SumofElements;
  rtb_BusAssignment_e.vAcc = rtb_SumofElements1 < 0.0 ? (uint32_T)-(int32_T)
    (uint32_T)-rtb_SumofElements1 : (uint32_T)rtb_SumofElements1;

  /* Gain: '<S104>/Gain7' */
  rtb_Add_p = fmodf(floorf(1000.0F * rtb_Va_B[0]), 4.2949673E+9F);

  /* BusAssignment: '<S104>/Bus Assignment' incorporates:
   *  Gain: '<S104>/Gain7'
   */
  rtb_BusAssignment_e.velN = rtb_Add_p < 0.0F ? -(int32_T)(uint32_T)-rtb_Add_p :
    (int32_T)(uint32_T)rtb_Add_p;

  /* Gain: '<S104>/Gain8' */
  rtb_Add_p = fmodf(floorf(1000.0F * rtb_Va_B[1]), 4.2949673E+9F);

  /* BusAssignment: '<S104>/Bus Assignment' incorporates:
   *  Gain: '<S104>/Gain8'
   */
  rtb_BusAssignment_e.velE = rtb_Add_p < 0.0F ? -(int32_T)(uint32_T)-rtb_Add_p :
    (int32_T)(uint32_T)rtb_Add_p;

  /* Gain: '<S104>/Gain9' incorporates:
   *  DiscreteFir: '<S115>/Discrete FIR Filter'
   */
  rtb_Add_p = fmodf(floorf((rtb_Add_i[2] * 0.5F +
    Plant_DW.DiscreteFIRFilter_states_i[2] * 0.5F) * 1000.0F), 4.2949673E+9F);

  /* BusAssignment: '<S104>/Bus Assignment' incorporates:
   *  Constant: '<S104>/Constant15'
   *  Gain: '<S104>/Gain11'
   *  Gain: '<S104>/Gain9'
   *  Math: '<S106>/Math Function'
   *  Math: '<S106>/Math Function1'
   *  Saturate: '<S106>/Saturation'
   *  Sqrt: '<S106>/Sqrt'
   *  Sum: '<S106>/Add'
   */
  rtb_BusAssignment_e.velD = rtb_Add_p < 0.0F ? -(int32_T)(uint32_T)-rtb_Add_p :
    (int32_T)(uint32_T)rtb_Add_p;
  rtb_BusAssignment_e.gSpeed = (int32_T)(uint32_T)fmodf(floorf(sqrtf(fmaxf
    (rtb_Va_B[0] * rtb_Va_B[0] + rtb_Va_B[1] * rtb_Va_B[1], 0.0F)) * 1000.0F),
    4.2949673E+9F);
  rtb_BusAssignment_e.heading = 0;

  /* Gain: '<S104>/Gain10' incorporates:
   *  Math: '<S111>/Math Function1'
   *  Product: '<S111>/Matrix Multiply1'
   *  Sqrt: '<S111>/Sqrt1'
   *  Switch: '<S111>/Switch2'
   */
  rtb_SumofElements = fmod(floor(sqrtf((rtb_RandomSource1[0] *
    rtb_RandomSource1[0] + rtb_RandomSource1[1] * rtb_RandomSource1[1]) +
    rtb_RandomSource1[2] * rtb_RandomSource1[2]) * 1000.0), 4.294967296E+9);

  /* BusAssignment: '<S104>/Bus Assignment' incorporates:
   *  Constant: '<S104>/Constant14'
   *  Constant: '<S104>/Constant16'
   *  Constant: '<S104>/Constant17'
   *  Gain: '<S104>/Gain10'
   *  Memory: '<S89>/Memory1'
   */
  rtb_BusAssignment_e.sAcc = rtb_SumofElements < 0.0 ? (uint32_T)-(int32_T)
    (uint32_T)-rtb_SumofElements : (uint32_T)rtb_SumofElements;
  rtb_BusAssignment_e.headingAcc = 0U;
  rtb_BusAssignment_e.pDOP = 0U;
  rtb_BusAssignment_e.reserved2 = 0U;
  rtb_BusAssignment_e.timestamp = Plant_DW.Memory1_PreviousInput;

  /* RateTransition: '<S104>/Rate Transition' */
  if (Plant_M->Timing.TaskCounters.TID[3] == 0) {
    Plant_B.RateTransition = rtb_BusAssignment_e;
  }

  /* End of RateTransition: '<S104>/Rate Transition' */

  /* Update for Delay: '<S109>/Delay' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S109>/ConcatBufferAtVector ConcatenateIn1'
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

  /* Update for DiscreteFir: '<S114>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states[0] = rtb_Cl_xA;

  /* Update for Delay: '<S109>/Delay' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S109>/ConcatBufferAtVector ConcatenateIn2'
   */
  Plant_DW.Delay_DSTATE[223] = Plant_Y.Plant_States.lat;

  /* Update for DiscreteFir: '<S114>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states[1] = rtb_TrigonometricFunction2;

  /* Update for Delay: '<S109>/Delay' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S109>/ConcatBufferAtVector ConcatenateIn3'
   */
  Plant_DW.Delay_DSTATE[224] = Plant_Y.Plant_States.alt;

  /* Update for DiscreteFir: '<S114>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states[2] = rtb_Cm;

  /* Update for Delay: '<S109>/Delay1' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S109>/ConcatBufferAtVector Concatenate1In1'
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

  /* Update for DiscreteFir: '<S115>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states_i[0] = rtb_Add_i[0];

  /* Update for Delay: '<S109>/Delay1' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S109>/ConcatBufferAtVector Concatenate1In2'
   */
  Plant_DW.Delay1_DSTATE_j[148] = Plant_Y.Plant_States.vel_y_O;

  /* Update for DiscreteFir: '<S115>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states_i[1] = rtb_Add_i[1];

  /* Update for Delay: '<S109>/Delay1' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S109>/ConcatBufferAtVector Concatenate1In3'
   */
  Plant_DW.Delay1_DSTATE_j[149] = Plant_Y.Plant_States.vel_z_O;

  /* Update for DiscreteFir: '<S115>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states_i[2] = rtb_Add_i[2];

  /* End of Outputs for SubSystem: '<S6>/Sensor_GPS' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_IMU' */
  /* Outputs for Atomic SubSystem: '<S121>/Vibration_Model' */
  /* Outputs for Atomic SubSystem: '<S132>/Vibration_Model' */
  /* Product: '<S138>/Divide2' incorporates:
   *  Constant: '<S138>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Product: '<S127>/Divide2'
   */
  rtb_Cl_xA = Plant_Y.Extended_States.prop_vel[0] / 1047.1975511965977;

  /* End of Outputs for SubSystem: '<S121>/Vibration_Model' */

  /* Math: '<S138>/u^2' */
  rtb_TrigonometricFunction2 = rtb_Cl_xA * rtb_Cl_xA;

  /* Product: '<S134>/Product2' incorporates:
   *  DiscreteIntegrator: '<S134>/Discrete-Time Integrator'
   *  Trigonometry: '<S134>/Trigonometric Function2'
   */
  rtb_SumofElements1 = arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[0]) *
    rtb_TrigonometricFunction2;

  /* Math: '<S138>/u^2' incorporates:
   *  DiscreteIntegrator: '<S134>/Discrete-Time Integrator'
   *  Product: '<S134>/Product1'
   *  Trigonometry: '<S134>/Trigonometric Function1'
   */
  rtb_Cm = arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[0]) *
    rtb_TrigonometricFunction2;

  /* Product: '<S138>/Divide2' incorporates:
   *  Constant: '<S138>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Product: '<S127>/Divide2'
   */
  rtb_Divide_e_idx_1 = rtb_Cl_xA;

  /* Outputs for Atomic SubSystem: '<S121>/Vibration_Model' */
  rtb_Cl_xA = Plant_Y.Extended_States.prop_vel[1] / 1047.1975511965977;

  /* End of Outputs for SubSystem: '<S121>/Vibration_Model' */

  /* Math: '<S138>/u^2' */
  rtb_TrigonometricFunction2 = rtb_Cl_xA * rtb_Cl_xA;

  /* Product: '<S134>/Product2' incorporates:
   *  DiscreteIntegrator: '<S134>/Discrete-Time Integrator'
   *  Trigonometry: '<S134>/Trigonometric Function2'
   */
  rtb_SumofElements = arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[1]) *
    rtb_TrigonometricFunction2;

  /* Math: '<S138>/u^2' incorporates:
   *  DiscreteIntegrator: '<S134>/Discrete-Time Integrator'
   *  Product: '<S134>/Product1'
   *  Trigonometry: '<S134>/Trigonometric Function1'
   */
  rtb_Cl_zA = arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[1]) *
    rtb_TrigonometricFunction2;

  /* Product: '<S138>/Divide2' incorporates:
   *  Constant: '<S138>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Product: '<S127>/Divide2'
   */
  rtb_CYr = rtb_Cl_xA;

  /* Outputs for Atomic SubSystem: '<S121>/Vibration_Model' */
  rtb_Cl_xA = Plant_Y.Extended_States.prop_vel[2] / 1047.1975511965977;

  /* End of Outputs for SubSystem: '<S121>/Vibration_Model' */

  /* Math: '<S138>/u^2' */
  rtb_TrigonometricFunction2 = rtb_Cl_xA * rtb_Cl_xA;

  /* Product: '<S138>/Divide2' incorporates:
   *  Constant: '<S138>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Product: '<S127>/Divide2'
   */
  rtb_Cl_yA = rtb_Cl_xA;

  /* Outputs for Atomic SubSystem: '<S121>/Vibration_Model' */
  rtb_Cl_xA = Plant_Y.Extended_States.prop_vel[3] / 1047.1975511965977;

  /* Math: '<S138>/u^2' incorporates:
   *  Math: '<S127>/u^2'
   */
  rtb_Cl_xA *= rtb_Cl_xA;

  /* End of Outputs for SubSystem: '<S121>/Vibration_Model' */

  /* Sum: '<S134>/Sum of Elements' incorporates:
   *  DiscreteIntegrator: '<S134>/Discrete-Time Integrator'
   *  Math: '<S138>/u^2'
   *  Product: '<S134>/Product2'
   *  Trigonometry: '<S134>/Trigonometric Function2'
   */
  rtb_SumofElements1 = ((rtb_SumofElements1 + rtb_SumofElements) + arm_sin_f32
                        (Plant_DW.DiscreteTimeIntegrator_DSTATE[2]) *
                        rtb_TrigonometricFunction2) + arm_sin_f32
    (Plant_DW.DiscreteTimeIntegrator_DSTATE[3]) * rtb_Cl_xA;

  /* Sum: '<S134>/Sum of Elements1' incorporates:
   *  DiscreteIntegrator: '<S134>/Discrete-Time Integrator'
   *  Math: '<S138>/u^2'
   *  Product: '<S134>/Product1'
   *  Trigonometry: '<S134>/Trigonometric Function1'
   */
  rtb_SumofElements = ((rtb_Cm + rtb_Cl_zA) + arm_cos_f32
                       (Plant_DW.DiscreteTimeIntegrator_DSTATE[2]) *
                       rtb_TrigonometricFunction2) + arm_cos_f32
    (Plant_DW.DiscreteTimeIntegrator_DSTATE[3]) * rtb_Cl_xA;

  /* Outputs for Atomic SubSystem: '<S121>/Vibration_Model' */
  /* Update for DiscreteIntegrator: '<S134>/Discrete-Time Integrator' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S123>/Discrete-Time Integrator'
   */
  rtb_DiscreteTimeIntegrator_idx_ = 0.002F * Plant_Y.Extended_States.prop_vel[0];

  /* End of Outputs for SubSystem: '<S121>/Vibration_Model' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE[0] += rtb_DiscreteTimeIntegrator_idx_;

  /* End of Outputs for SubSystem: '<S132>/Vibration_Model' */
  /* End of Outputs for SubSystem: '<S6>/Sensor_IMU' */
  /* End of Outputs for SubSystem: '<Root>/Sensor_Model' */
  rtb_DiscreteTimeIntegrator_id_1 = rtb_DiscreteTimeIntegrator_idx_;

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_Model' */
  /* Outputs for Atomic SubSystem: '<S6>/Sensor_IMU' */
  /* Outputs for Atomic SubSystem: '<S121>/Vibration_Model' */
  /* Outputs for Atomic SubSystem: '<S132>/Vibration_Model' */
  /* Update for DiscreteIntegrator: '<S134>/Discrete-Time Integrator' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S123>/Discrete-Time Integrator'
   */
  rtb_DiscreteTimeIntegrator_idx_ = 0.002F * Plant_Y.Extended_States.prop_vel[1];

  /* End of Outputs for SubSystem: '<S121>/Vibration_Model' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE[1] += rtb_DiscreteTimeIntegrator_idx_;

  /* End of Outputs for SubSystem: '<S132>/Vibration_Model' */
  /* End of Outputs for SubSystem: '<S6>/Sensor_IMU' */
  /* End of Outputs for SubSystem: '<Root>/Sensor_Model' */
  rtb_DiscreteTimeIntegrator_id_0 = rtb_DiscreteTimeIntegrator_idx_;

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_Model' */
  /* Outputs for Atomic SubSystem: '<S6>/Sensor_IMU' */
  /* Outputs for Atomic SubSystem: '<S121>/Vibration_Model' */
  /* Outputs for Atomic SubSystem: '<S132>/Vibration_Model' */
  /* Update for DiscreteIntegrator: '<S134>/Discrete-Time Integrator' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S123>/Discrete-Time Integrator'
   */
  rtb_DiscreteTimeIntegrator_idx_ = 0.002F * Plant_Y.Extended_States.prop_vel[2];

  /* End of Outputs for SubSystem: '<S121>/Vibration_Model' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE[2] += rtb_DiscreteTimeIntegrator_idx_;

  /* End of Outputs for SubSystem: '<S132>/Vibration_Model' */
  /* End of Outputs for SubSystem: '<S6>/Sensor_IMU' */
  /* End of Outputs for SubSystem: '<Root>/Sensor_Model' */
  rtb_MathFunction1_k = rtb_DiscreteTimeIntegrator_idx_;

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_Model' */
  /* Outputs for Atomic SubSystem: '<S6>/Sensor_IMU' */
  /* Outputs for Atomic SubSystem: '<S121>/Vibration_Model' */
  /* Outputs for Atomic SubSystem: '<S132>/Vibration_Model' */
  /* Update for DiscreteIntegrator: '<S134>/Discrete-Time Integrator' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S123>/Discrete-Time Integrator'
   */
  rtb_DiscreteTimeIntegrator_idx_ = 0.002F * Plant_Y.Extended_States.prop_vel[3];

  /* End of Outputs for SubSystem: '<S121>/Vibration_Model' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE[3] += rtb_DiscreteTimeIntegrator_idx_;

  /* Switch: '<S132>/Switch' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S134>/Gain2'
   *  Gain: '<S134>/Gain4'
   *  Product: '<S134>/Divide'
   *  SignalConversion: '<S134>/ConcatBufferAtVector ConcatenateIn1'
   *  SignalConversion: '<S136>/ConcatBufferAtVector ConcatenateIn1'
   *  SignalConversion: '<S136>/ConcatBufferAtVector ConcatenateIn2'
   *  SignalConversion: '<S136>/ConcatBufferAtVector ConcatenateIn3'
   *  Sum: '<S132>/Sum'
   *  Sum: '<S134>/Sum'
   *  Sum: '<S134>/Sum of Elements1'
   */
  rtb_Va_B[0] = (real32_T)(rtb_SumofElements1 / 4.0 * 0.5 +
    Plant_Y.Plant_States.rot_x_B);
  rtb_Va_B[1] = (real32_T)(rtb_SumofElements / 4.0 * 0.5 +
    Plant_Y.Plant_States.rot_y_B);
  rtb_Add_p = (real32_T)((rtb_SumofElements1 + rtb_SumofElements) * 0.5 / 4.0 *
    0.5 + Plant_Y.Plant_States.rot_z_B);

  /* End of Outputs for SubSystem: '<S132>/Vibration_Model' */

  /* Sum: '<S140>/Sum' incorporates:
   *  Product: '<S140>/Product'
   */
  for (i = 0; i < 3; i++) {
    rtb_RandomSource[i] = (Plant_ConstB.Add_k[i + 3] * rtb_Va_B[1] +
      Plant_ConstB.Add_k[i] * rtb_Va_B[0]) + Plant_ConstB.Add_k[i + 6] *
      rtb_Add_p;
  }

  /* End of Sum: '<S140>/Sum' */

  /* DiscreteIntegrator: '<S139>/Discrete-Time Integrator5' */
  if (Plant_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[0] = rtb_RandomSource[0];
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[1] = rtb_RandomSource[1];
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[2] = rtb_RandomSource[2];
  }

  /* S-Function (sdsprandsrc2): '<S130>/Random Source' */
  RandSrc_GZ_R(rtb_RandomSource_a, &Plant_ConstP.pooled27, 1,
               Plant_ConstP.RandomSource_VarianceRTP_h, 3,
               Plant_DW.RandomSource_STATE_DWORK_f, 3, 1);

  /* S-Function (sdsprandsrc2): '<S141>/Random Source' */
  RandSrc_GZ_R(rtb_Sum_l, &Plant_ConstP.pooled27, 1,
               Plant_ConstP.RandomSource_VarianceRTP_o, 3,
               Plant_DW.RandomSource_STATE_DWORK_p, 3, 1);

  /* Saturate: '<S133>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S139>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[0] > 34.9065857F) {
    rtb_Add_p = 34.9065857F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[0] < -34.9065857F) {
    rtb_Add_p = -34.9065857F;
  } else {
    rtb_Add_p = Plant_DW.DiscreteTimeIntegrator5_DSTATE[0];
  }

  /* Sum: '<S133>/Sum' */
  rtb_Add_i[0] = rtb_Add_p + rtb_Sum_l[0];

  /* Saturate: '<S133>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S139>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[1] > 34.9065857F) {
    rtb_Add_p = 34.9065857F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[1] < -34.9065857F) {
    rtb_Add_p = -34.9065857F;
  } else {
    rtb_Add_p = Plant_DW.DiscreteTimeIntegrator5_DSTATE[1];
  }

  /* Sum: '<S133>/Sum' */
  rtb_Add_i[1] = rtb_Add_p + rtb_Sum_l[1];

  /* Saturate: '<S133>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S139>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[2] > 34.9065857F) {
    rtb_Add_p = 34.9065857F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[2] < -34.9065857F) {
    rtb_Add_p = -34.9065857F;
  } else {
    rtb_Add_p = Plant_DW.DiscreteTimeIntegrator5_DSTATE[2];
  }

  /* Sum: '<S133>/Sum' */
  rtb_Add_i[2] = rtb_Add_p + rtb_Sum_l[2];

  /* Outputs for Atomic SubSystem: '<S121>/Vibration_Model' */
  /* Math: '<S127>/u^2' incorporates:
   *  Product: '<S127>/Divide2'
   */
  rtb_TrigonometricFunction2 = rtb_Divide_e_idx_1 * rtb_Divide_e_idx_1;

  /* Product: '<S123>/Product2' incorporates:
   *  DiscreteIntegrator: '<S123>/Discrete-Time Integrator'
   *  Trigonometry: '<S123>/Trigonometric Function2'
   */
  rtb_SumofElements1 = arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_f[0]) *
    rtb_TrigonometricFunction2;

  /* Math: '<S127>/u^2' incorporates:
   *  DiscreteIntegrator: '<S123>/Discrete-Time Integrator'
   *  Product: '<S123>/Product1'
   *  Product: '<S127>/Divide2'
   *  Trigonometry: '<S123>/Trigonometric Function1'
   */
  rtb_Cm = arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_f[0]) *
    rtb_TrigonometricFunction2;
  rtb_TrigonometricFunction2 = rtb_CYr * rtb_CYr;

  /* Product: '<S123>/Product2' incorporates:
   *  DiscreteIntegrator: '<S123>/Discrete-Time Integrator'
   *  Trigonometry: '<S123>/Trigonometric Function2'
   */
  rtb_SumofElements = arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_f[1]) *
    rtb_TrigonometricFunction2;

  /* Math: '<S127>/u^2' incorporates:
   *  DiscreteIntegrator: '<S123>/Discrete-Time Integrator'
   *  Product: '<S123>/Product1'
   *  Product: '<S127>/Divide2'
   *  Trigonometry: '<S123>/Trigonometric Function1'
   */
  rtb_Cl_zA = arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_f[1]) *
    rtb_TrigonometricFunction2;
  rtb_TrigonometricFunction2 = rtb_Cl_yA * rtb_Cl_yA;

  /* Sum: '<S123>/Sum of Elements' incorporates:
   *  DiscreteIntegrator: '<S123>/Discrete-Time Integrator'
   *  Product: '<S123>/Product2'
   *  Trigonometry: '<S123>/Trigonometric Function2'
   */
  rtb_SumofElements = ((rtb_SumofElements1 + rtb_SumofElements) + arm_sin_f32
                       (Plant_DW.DiscreteTimeIntegrator_DSTATE_f[2]) *
                       rtb_TrigonometricFunction2) + arm_sin_f32
    (Plant_DW.DiscreteTimeIntegrator_DSTATE_f[3]) * rtb_Cl_xA;

  /* SignalConversion: '<S123>/ConcatBufferAtVector ConcatenateIn1' incorporates:
   *  Sum: '<S123>/Sum of Elements'
   */
  rtb_Divide2[0] = rtb_SumofElements;

  /* Sum: '<S123>/Sum of Elements1' incorporates:
   *  DiscreteIntegrator: '<S123>/Discrete-Time Integrator'
   *  Product: '<S123>/Product1'
   *  Trigonometry: '<S123>/Trigonometric Function1'
   */
  rtb_SumofElements1 = ((rtb_Cm + rtb_Cl_zA) + arm_cos_f32
                        (Plant_DW.DiscreteTimeIntegrator_DSTATE_f[2]) *
                        rtb_TrigonometricFunction2) + arm_cos_f32
    (Plant_DW.DiscreteTimeIntegrator_DSTATE_f[3]) * rtb_Cl_xA;

  /* SignalConversion: '<S123>/ConcatBufferAtVector ConcatenateIn2' */
  rtb_Divide2[1] = rtb_SumofElements1;

  /* Gain: '<S123>/Gain2' incorporates:
   *  Sum: '<S123>/Sum'
   *  Sum: '<S123>/Sum of Elements'
   */
  rtb_Divide2[2] = (rtb_SumofElements + rtb_SumofElements1) * 0.5;

  /* Update for DiscreteIntegrator: '<S123>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_f[0] += rtb_DiscreteTimeIntegrator_id_1;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_f[1] += rtb_DiscreteTimeIntegrator_id_0;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_f[2] += rtb_MathFunction1_k;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_f[3] += rtb_DiscreteTimeIntegrator_idx_;

  /* End of Outputs for SubSystem: '<S121>/Vibration_Model' */

  /* Switch: '<S121>/Switch' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S123>/Gain4'
   *  Product: '<S123>/Divide'
   *  Product: '<S125>/Product1'
   *  SignalConversion: '<S125>/ConcatBufferAtVector Concatenate1In1'
   *  SignalConversion: '<S125>/ConcatBufferAtVector Concatenate1In2'
   *  SignalConversion: '<S125>/ConcatBufferAtVector Concatenate1In3'
   *  Sum: '<S121>/Sum'
   *  Sum: '<S125>/Sum'
   */
  for (i = 0; i < 3; i++) {
    /* Outputs for Atomic SubSystem: '<S121>/Vibration_Model' */
    rtb_Sum_l[i] = (real32_T)(((Plant_Y.Extended_States.M_BO[i + 3] *
      Plant_Y.Plant_States.acc_y_O + Plant_Y.Extended_States.M_BO[i] *
      Plant_Y.Plant_States.acc_x_O) + Plant_Y.Extended_States.M_BO[i + 6] *
      (Plant_Y.Plant_States.acc_z_O - 9.80665F)) + rtb_Divide2[i] / 4.0 *
      Plant_ConstP.Gain4_Gain[i]);

    /* End of Outputs for SubSystem: '<S121>/Vibration_Model' */
  }

  /* End of Switch: '<S121>/Switch' */

  /* Sum: '<S129>/Sum' incorporates:
   *  Product: '<S129>/Product'
   */
  for (i = 0; i < 3; i++) {
    rtb_RandomSource1[i] = (Plant_ConstB.Add_g[i + 3] * rtb_Sum_l[1] +
      Plant_ConstB.Add_g[i] * rtb_Sum_l[0]) + Plant_ConstB.Add_g[i + 6] *
      rtb_Sum_l[2];
  }

  /* End of Sum: '<S129>/Sum' */

  /* DiscreteIntegrator: '<S128>/Discrete-Time Integrator5' */
  if (Plant_DW.DiscreteTimeIntegrator5_IC_LO_g != 0) {
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[0] = rtb_RandomSource1[0];
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[1] = rtb_RandomSource1[1];
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[2] = rtb_RandomSource1[2];
  }

  /* Outport: '<Root>/IMU' incorporates:
   *  BusAssignment: '<S118>/Bus Assignment'
   *  Memory: '<S89>/Memory1'
   */
  Plant_Y.IMU.timestamp = Plant_DW.Memory1_PreviousInput;
  Plant_Y.IMU.gyr_x = rtb_Add_i[0];
  Plant_Y.IMU.gyr_y = rtb_Add_i[1];
  Plant_Y.IMU.gyr_z = rtb_Add_i[2];

  /* Update for DiscreteIntegrator: '<S139>/Discrete-Time Integrator5' */
  Plant_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;

  /* Update for DiscreteIntegrator: '<S128>/Discrete-Time Integrator5' */
  Plant_DW.DiscreteTimeIntegrator5_IC_LO_g = 0U;

  /* End of Outputs for SubSystem: '<S6>/Sensor_IMU' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_MAG' */
  /* Gain: '<S147>/rad_to_index' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S147>/TmpSignal ConversionAtrad_to_indexInport1'
   */
  rtb_SumofElements = fmod(floor(5.7295779513082321 * Plant_Y.Plant_States.lat),
    4.294967296E+9);

  /* Sum: '<S147>/Add' incorporates:
   *  Gain: '<S147>/rad_to_index'
   */
  i = (rtb_SumofElements < 0.0 ? -(int32_T)(uint32_T)-rtb_SumofElements :
       (int32_T)(uint32_T)rtb_SumofElements) + 8;

  /* Saturate: '<S147>/Saturation1' */
  if (i > 16) {
    i = 16;
  } else {
    if (i < 0) {
      i = 0;
    }
  }

  /* Gain: '<S147>/rad_to_index' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S147>/TmpSignal ConversionAtrad_to_indexInport1'
   */
  rtb_SumofElements = fmod(floor(5.7295779513082321 * Plant_Y.Plant_States.lon),
    4.294967296E+9);

  /* Sum: '<S147>/Add' incorporates:
   *  Gain: '<S147>/rad_to_index'
   */
  rtb_Saturation1_m_idx_1 = (rtb_SumofElements < 0.0 ? -(int32_T)(uint32_T)
    -rtb_SumofElements : (int32_T)(uint32_T)rtb_SumofElements) + 18;

  /* Saturate: '<S147>/Saturation1' */
  if (rtb_Saturation1_m_idx_1 > 36) {
    rtb_Saturation1_m_idx_1 = 36;
  } else {
    if (rtb_Saturation1_m_idx_1 < 0) {
      rtb_Saturation1_m_idx_1 = 0;
    }
  }

  /* LookupNDDirect: '<S147>/Declination_Lookup_Table' incorporates:
   *  LookupNDDirect: '<S147>/Inclination_Lookup_Table'
   *  LookupNDDirect: '<S147>/Magnitude_Lookup_Table'
   *
   * About '<S147>/Declination_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   *
   * About '<S147>/Inclination_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   *
   * About '<S147>/Magnitude_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  i += rtb_Saturation1_m_idx_1 * 17;

  /* Gain: '<S148>/Gain1' incorporates:
   *  LookupNDDirect: '<S147>/Declination_Lookup_Table'
   *
   * About '<S147>/Declination_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  rtb_DiscreteTimeIntegrator_id_1 =
    Plant_ConstP.Declination_Lookup_Table_table[i] * 0.0174532924F;

  /* Trigonometry: '<S150>/Trigonometric Function1' incorporates:
   *  Trigonometry: '<S150>/Trigonometric Function3'
   */
  rtb_Gain_kz = arm_cos_f32(rtb_DiscreteTimeIntegrator_id_1);
  rtb_VectorConcatenate_f[0] = rtb_Gain_kz;

  /* Trigonometry: '<S150>/Trigonometric Function' incorporates:
   *  Trigonometry: '<S150>/Trigonometric Function2'
   */
  rtb_DiscreteTimeIntegrator_id_1 = arm_sin_f32(rtb_DiscreteTimeIntegrator_id_1);
  rtb_VectorConcatenate_f[1] = rtb_DiscreteTimeIntegrator_id_1;

  /* SignalConversion: '<S150>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S150>/Constant3'
   */
  rtb_VectorConcatenate_f[2] = 0.0F;

  /* Gain: '<S150>/Gain' */
  rtb_VectorConcatenate_f[3] = -rtb_DiscreteTimeIntegrator_id_1;

  /* Trigonometry: '<S150>/Trigonometric Function3' */
  rtb_VectorConcatenate_f[4] = rtb_Gain_kz;

  /* SignalConversion: '<S150>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S150>/Constant4'
   */
  rtb_VectorConcatenate_f[5] = 0.0F;

  /* Gain: '<S148>/Gain' incorporates:
   *  LookupNDDirect: '<S147>/Inclination_Lookup_Table'
   *
   * About '<S147>/Inclination_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  rtb_DiscreteTimeIntegrator_id_1 =
    Plant_ConstP.Inclination_Lookup_Table_table[i] * -0.0174532924F;

  /* Trigonometry: '<S149>/Trigonometric Function3' incorporates:
   *  Trigonometry: '<S149>/Trigonometric Function1'
   */
  rtb_Add_p = arm_cos_f32(rtb_DiscreteTimeIntegrator_id_1);
  rtb_VectorConcatenate_n[0] = rtb_Add_p;

  /* SignalConversion: '<S149>/ConcatBufferAtVector Concatenate2In2' incorporates:
   *  Constant: '<S149>/Constant4'
   */
  rtb_VectorConcatenate_n[1] = 0.0F;

  /* Trigonometry: '<S149>/Trigonometric Function2' incorporates:
   *  Trigonometry: '<S149>/Trigonometric Function'
   */
  rtb_DiscreteTimeIntegrator_idx_ = arm_sin_f32(rtb_DiscreteTimeIntegrator_id_1);

  /* Gain: '<S149>/Gain' incorporates:
   *  Trigonometry: '<S149>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_n[2] = -rtb_DiscreteTimeIntegrator_idx_;

  /* End of Outputs for SubSystem: '<S6>/Sensor_MAG' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_IMU' */
  /* Saturate: '<S122>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S128>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[0] > 78.4532F) {
    rtb_DiscreteTimeIntegrator_id_1 = 78.4532F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[0] < -78.4532F) {
    rtb_DiscreteTimeIntegrator_id_1 = -78.4532F;
  } else {
    rtb_DiscreteTimeIntegrator_id_1 = Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[0];
  }

  /* Update for DiscreteIntegrator: '<S139>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S139>/Gain'
   *  Sum: '<S139>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTATE[0] += (rtb_RandomSource[0] -
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 314.159271F * 0.002F;

  /* Update for DiscreteIntegrator: '<S128>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S128>/Gain'
   *  Sum: '<S128>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[0] += (rtb_RandomSource1[0] -
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[0]) * 314.159271F * 0.002F;

  /* End of Outputs for SubSystem: '<S6>/Sensor_IMU' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_MAG' */
  /* SignalConversion: '<S150>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_f[6] = Plant_ConstB.VectorConcatenate3[0];

  /* SignalConversion: '<S149>/ConcatBufferAtVector ConcatenateIn2' */
  rtb_VectorConcatenate_n[3] = Plant_ConstB.VectorConcatenate3_e[0];

  /* End of Outputs for SubSystem: '<S6>/Sensor_MAG' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_IMU' */
  /* Saturate: '<S122>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S128>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[1] > 78.4532F) {
    rtb_DiscreteTimeIntegrator_id_0 = 78.4532F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[1] < -78.4532F) {
    rtb_DiscreteTimeIntegrator_id_0 = -78.4532F;
  } else {
    rtb_DiscreteTimeIntegrator_id_0 = Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[1];
  }

  /* Update for DiscreteIntegrator: '<S139>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S139>/Gain'
   *  Sum: '<S139>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTATE[1] += (rtb_RandomSource[1] -
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 314.159271F * 0.002F;

  /* Update for DiscreteIntegrator: '<S128>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S128>/Gain'
   *  Sum: '<S128>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[1] += (rtb_RandomSource1[1] -
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[1]) * 314.159271F * 0.002F;

  /* End of Outputs for SubSystem: '<S6>/Sensor_IMU' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_MAG' */
  /* SignalConversion: '<S150>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_f[7] = Plant_ConstB.VectorConcatenate3[1];

  /* SignalConversion: '<S149>/ConcatBufferAtVector ConcatenateIn2' */
  rtb_VectorConcatenate_n[4] = Plant_ConstB.VectorConcatenate3_e[1];

  /* End of Outputs for SubSystem: '<S6>/Sensor_MAG' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_IMU' */
  /* Saturate: '<S122>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S128>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[2] > 78.4532F) {
    rtb_MathFunction1_k = 78.4532F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[2] < -78.4532F) {
    rtb_MathFunction1_k = -78.4532F;
  } else {
    rtb_MathFunction1_k = Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[2];
  }

  /* Update for DiscreteIntegrator: '<S139>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S139>/Gain'
   *  Sum: '<S139>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTATE[2] += (rtb_RandomSource[2] -
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 314.159271F * 0.002F;

  /* Update for DiscreteIntegrator: '<S128>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S128>/Gain'
   *  Sum: '<S128>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[2] += (rtb_RandomSource1[2] -
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_g[2]) * 314.159271F * 0.002F;

  /* End of Outputs for SubSystem: '<S6>/Sensor_IMU' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_MAG' */
  /* SignalConversion: '<S150>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_f[8] = Plant_ConstB.VectorConcatenate3[2];

  /* SignalConversion: '<S149>/ConcatBufferAtVector ConcatenateIn2' */
  rtb_VectorConcatenate_n[5] = Plant_ConstB.VectorConcatenate3_e[2];

  /* Trigonometry: '<S149>/Trigonometric Function' */
  rtb_VectorConcatenate_n[6] = rtb_DiscreteTimeIntegrator_idx_;

  /* SignalConversion: '<S149>/ConcatBufferAtVector Concatenate1In2' incorporates:
   *  Constant: '<S149>/Constant3'
   */
  rtb_VectorConcatenate_n[7] = 0.0F;

  /* Trigonometry: '<S149>/Trigonometric Function1' */
  rtb_VectorConcatenate_n[8] = rtb_Add_p;

  /* Gain: '<S148>/toGauss' incorporates:
   *  LookupNDDirect: '<S147>/Magnitude_Lookup_Table'
   *
   * About '<S147>/Magnitude_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  rtb_Add_p = Plant_ConstP.Magnitude_Lookup_Table_table[i] * 0.01F;

  /* Product: '<S148>/Multiply1' incorporates:
   *  Product: '<S148>/Multiply'
   */
  for (i = 0; i < 3; i++) {
    rtb_Va_B[i] = rtb_VectorConcatenate_n[i] * rtb_Add_p;
  }

  /* End of Product: '<S148>/Multiply1' */

  /* Product: '<S148>/Multiply2' */
  for (i = 0; i < 3; i++) {
    rtb_Square_d[i] = rtb_VectorConcatenate_f[i + 6] * rtb_Va_B[2] +
      (rtb_VectorConcatenate_f[i + 3] * rtb_Va_B[1] + rtb_VectorConcatenate_f[i]
       * rtb_Va_B[0]);
  }

  /* End of Product: '<S148>/Multiply2' */

  /* Product: '<S145>/Product' incorporates:
   *  Delay: '<Root>/Delay'
   */
  for (i = 0; i < 3; i++) {
    rtb_Va_B[i] = Plant_Y.Extended_States.M_BO[i + 6] * rtb_Square_d[2] +
      (Plant_Y.Extended_States.M_BO[i + 3] * rtb_Square_d[1] +
       Plant_Y.Extended_States.M_BO[i] * rtb_Square_d[0]);
  }

  /* End of Product: '<S145>/Product' */
  for (i = 0; i < 3; i++) {
    /* Sum: '<S151>/Sum' incorporates:
     *  Product: '<S151>/Product'
     */
    rtb_Add_p = (Plant_ConstB.Add[i + 3] * rtb_Va_B[1] + Plant_ConstB.Add[i] *
                 rtb_Va_B[0]) + Plant_ConstB.Add[i + 6] * rtb_Va_B[2];

    /* Saturate: '<S146>/Saturation' incorporates:
     *  Sum: '<S151>/Sum'
     */
    if (rtb_Add_p > 4.0F) {
      rtb_Add_i[i] = 4.0F;
    } else if (rtb_Add_p < -4.0F) {
      rtb_Add_i[i] = -4.0F;
    } else {
      rtb_Add_i[i] = rtb_Add_p;
    }

    /* End of Saturate: '<S146>/Saturation' */
  }

  /* S-Function (sdsprandsrc2): '<S152>/Random Source' */
  RandSrc_GZ_R(rtb_Va_B, &Plant_ConstP.pooled27, 1,
               Plant_ConstP.RandomSource_VarianceRTP_om, 3,
               Plant_DW.RandomSource_STATE_DWORK, 3, 1);

  /* Sum: '<S146>/Add' */
  rtb_Add_i[0] += rtb_Va_B[0];
  rtb_Add_i[1] += rtb_Va_B[1];

  /* BusAssignment: '<S142>/Bus Assignment' incorporates:
   *  Memory: '<S89>/Memory1'
   *  Sum: '<S146>/Add'
   */
  rtb_BusAssignment_j.timestamp = Plant_DW.Memory1_PreviousInput;
  rtb_BusAssignment_j.mag_x = rtb_Add_i[0];
  rtb_BusAssignment_j.mag_y = rtb_Add_i[1];
  rtb_BusAssignment_j.mag_z = rtb_Add_i[2] + rtb_Va_B[2];

  /* RateTransition: '<S142>/Rate Transition' */
  if (Plant_M->Timing.TaskCounters.TID[2] == 0) {
    Plant_B.RateTransition_l = rtb_BusAssignment_j;
  }

  /* End of RateTransition: '<S142>/Rate Transition' */
  /* End of Outputs for SubSystem: '<S6>/Sensor_MAG' */

  /* Update for Memory: '<S89>/Memory1' incorporates:
   *  Constant: '<S89>/dt'
   *  Sum: '<S89>/Sum'
   */
  Plant_DW.Memory1_PreviousInput += PLANT_EXPORT.period;

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_IMU' */
  /* Outport: '<Root>/IMU' incorporates:
   *  Sum: '<S122>/Sum'
   */
  Plant_Y.IMU.acc_x = rtb_DiscreteTimeIntegrator_id_1 + rtb_RandomSource_a[0];
  Plant_Y.IMU.acc_y = rtb_DiscreteTimeIntegrator_id_0 + rtb_RandomSource_a[1];
  Plant_Y.IMU.acc_z = rtb_MathFunction1_k + rtb_RandomSource_a[2];

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
  Plant_U.Control_Out = Plant_rtZControl_Out_Bus;

  /* external outputs */
  (void) memset((void *)&Plant_Y, 0,
                sizeof(ExtY_Plant_T));

  {
    uint32_T RandomSource_SEED_DWORK_n;

    /* SystemInitialize for Atomic SubSystem: '<Root>/Kinematic_Equation' */
    /* InitializeConditions for DiscreteIntegrator: '<S68>/Discrete-Time Integrator' */
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[0] = Plant_ConstB.quat0[0];
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[1] = Plant_ConstB.quat0[1];
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[2] = Plant_ConstB.quat0[2];
    Plant_DW.DiscreteTimeIntegrator_DSTATE_k[3] = Plant_ConstB.quat0[3];
    Plant_DW.DiscreteTimeIntegrator_PrevRese = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S64>/Discrete-Time Integrator' */
    Plant_DW.DiscreteTimeIntegrator_PrevRe_p = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S65>/Discrete-Time Integrator' */
    Plant_DW.DiscreteTimeIntegrator_PrevRe_g = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S65>/Discrete-Time Integrator1' */
    Plant_DW.DiscreteTimeIntegrator1_PrevRes = 0;

    /* End of SystemInitialize for SubSystem: '<Root>/Kinematic_Equation' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Bus_Constructor' */
    /* InitializeConditions for Delay: '<S44>/Delay1' */
    Plant_DW.Delay1_DSTATE[0] = 0.65673;
    Plant_DW.Delay1_DSTATE[1] = -2.1361;
    Plant_DW.Delay1_DSTATE[2] = 4.5;

    /* End of SystemInitialize for SubSystem: '<Root>/Bus_Constructor' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Sensor_Model' */
    /* SystemInitialize for Atomic SubSystem: '<S6>/Sensor_Barometer' */
    /* InitializeConditions for S-Function (sdsprandsrc2): '<S103>/Random Source' */
    RandomSource_SEED_DWORK_n = 91337U;
    RandSrcInitState_GZ(&RandomSource_SEED_DWORK_n,
                        Plant_DW.RandomSource_STATE_DWORK_fn, 1);

    /* End of SystemInitialize for SubSystem: '<S6>/Sensor_Barometer' */

    /* SystemInitialize for Atomic SubSystem: '<S6>/Sensor_GPS' */
    /* InitializeConditions for S-Function (sdsprandsrc2): '<S112>/Random Source' */
    RandSrcCreateSeeds_32(63235U, Plant_DW.RandomSource_SEED_DWORK_a, 3);
    RandSrcInitState_GZ(Plant_DW.RandomSource_SEED_DWORK_a,
                        Plant_DW.RandomSource_STATE_DWORK_f2, 3);

    /* InitializeConditions for DiscreteFir: '<S114>/Discrete FIR Filter' */
    Plant_DW.DiscreteFIRFilter_states[0] = 0.0;
    Plant_DW.DiscreteFIRFilter_states[1] = 0.0;
    Plant_DW.DiscreteFIRFilter_states[2] = 0.0;

    /* InitializeConditions for S-Function (sdsprandsrc2): '<S112>/Random Source1' */
    RandSrcCreateSeeds_32(9754U, Plant_DW.RandomSource1_SEED_DWORK, 3);
    RandSrcInitState_GZ(Plant_DW.RandomSource1_SEED_DWORK,
                        Plant_DW.RandomSource1_STATE_DWORK, 3);

    /* InitializeConditions for DiscreteFir: '<S115>/Discrete FIR Filter' */
    Plant_DW.DiscreteFIRFilter_states_i[0] = 0.0F;
    Plant_DW.DiscreteFIRFilter_states_i[1] = 0.0F;
    Plant_DW.DiscreteFIRFilter_states_i[2] = 0.0F;

    /* End of SystemInitialize for SubSystem: '<S6>/Sensor_GPS' */

    /* SystemInitialize for Atomic SubSystem: '<S6>/Sensor_IMU' */
    /* InitializeConditions for DiscreteIntegrator: '<S139>/Discrete-Time Integrator5' */
    Plant_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

    /* InitializeConditions for S-Function (sdsprandsrc2): '<S130>/Random Source' */
    RandSrcCreateSeeds_32(90579U, Plant_DW.RandomSource_SEED_DWORK_h, 3);
    RandSrcInitState_GZ(Plant_DW.RandomSource_SEED_DWORK_h,
                        Plant_DW.RandomSource_STATE_DWORK_f, 3);

    /* InitializeConditions for S-Function (sdsprandsrc2): '<S141>/Random Source' */
    RandSrcCreateSeeds_32(81472U, Plant_DW.RandomSource_SEED_DWORK_e, 3);
    RandSrcInitState_GZ(Plant_DW.RandomSource_SEED_DWORK_e,
                        Plant_DW.RandomSource_STATE_DWORK_p, 3);

    /* InitializeConditions for DiscreteIntegrator: '<S128>/Discrete-Time Integrator5' */
    Plant_DW.DiscreteTimeIntegrator5_IC_LO_g = 1U;

    /* End of SystemInitialize for SubSystem: '<S6>/Sensor_IMU' */

    /* SystemInitialize for Atomic SubSystem: '<S6>/Sensor_MAG' */
    /* InitializeConditions for S-Function (sdsprandsrc2): '<S152>/Random Source' */
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
