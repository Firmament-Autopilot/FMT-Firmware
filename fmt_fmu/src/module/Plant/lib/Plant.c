/*
 * File: Plant.c
 *
 * Code generated for Simulink model 'Plant'.
 *
 * Model version                  : 1.515
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Aug 14 23:04:43 2020
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
  0.0,                                 /* lon */
  0.0,                                 /* lat */
  0.0,                                 /* alt */
  0.0,                                 /* lon_ref */
  0.0,                                 /* lat_ref */
  0.0                                  /* alt_ref */
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
  /* M_OB */
} ;                                    /* Extended_States_Bus ground */

/* Exported block parameters */
struct_4XfCoaAMTej5uH3d8u88xB PLANT_EXPORT = {
  2U
} ;                                    /* Variable: PLANT_EXPORT
                                        * Referenced by:
                                        *   '<S22>/dt'
                                        *   '<S52>/dt'
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
  if ((Plant_M->Timing.TaskCounters.TID[1]) > 4) {/* Sample time: [0.01s, 0.0s] */
    Plant_M->Timing.TaskCounters.TID[1] = 0;
  }

  (Plant_M->Timing.TaskCounters.TID[2])++;
  if ((Plant_M->Timing.TaskCounters.TID[2]) > 49) {/* Sample time: [0.1s, 0.0s] */
    Plant_M->Timing.TaskCounters.TID[2] = 0;
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

  /* S-Function (sdsprandsrc2): '<S59>/Random Source' */
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

  /* End of S-Function (sdsprandsrc2): '<S59>/Random Source' */
}

void RandSrcInitState_GZ(const uint32_T seed[], uint32_T state[], int32_T nChans)
{
  int32_T i;
  int32_T tmp;

  /* InitializeConditions for S-Function (sdsprandsrc2): '<S59>/Random Source' */
  /* RandSrcInitState_GZ */
  for (i = 0; i < nChans; i++) {
    tmp = i << 1;
    state[tmp] = 362436069U;
    state[tmp + 1] = seed[i] == 0U ? 521288629U : seed[i];
  }

  /* End of InitializeConditions for S-Function (sdsprandsrc2): '<S59>/Random Source' */
}

void RandSrcInitState_U_32(const uint32_T seed[], real32_T state[], int32_T
  nChans)
{
  int32_T i;
  uint32_T j;
  int32_T k;
  int32_T n;
  real32_T d;

  /* InitializeConditions for S-Function (sdsprandsrc2): '<S69>/Random Source' */
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

  /* End of InitializeConditions for S-Function (sdsprandsrc2): '<S69>/Random Source' */
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

  /* InitializeConditions for S-Function (sdsprandsrc2): '<S69>/Random Source' */
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

  /* End of InitializeConditions for S-Function (sdsprandsrc2): '<S69>/Random Source' */
}

void RandSrcCreateSeeds_32(uint32_T initSeed, uint32_T seedArray[], int32_T
  numSeeds)
{
  real32_T state[35];
  real32_T tmp;
  real32_T min;
  real32_T max;
  int32_T i;

  /* InitializeConditions for S-Function (sdsprandsrc2): '<S69>/Random Source' */
  /* RandSrcCreateSeeds_32 */
  min = 0.0F;
  max = 1.0F;
  RandSrcInitState_U_32(&initSeed, state, 1);
  for (i = 0; i < numSeeds; i++) {
    RandSrc_U_R(&tmp, &min, 1, &max, 1, state, 1, 1);
    seedArray[i] = (uint32_T)(tmp * 2.14748365E+9F);
  }

  /* End of InitializeConditions for S-Function (sdsprandsrc2): '<S69>/Random Source' */
}

/* Model step function */
void Plant_step(void)
{
  real32_T denAccum;
  real32_T rtb_Gain_h;
  real32_T rtb_Square[9];
  real32_T rtb_Product11;
  real32_T rtb_integrate1[3];
  real32_T rtb_Add_la[3];
  boolean_T rtb_Compare;
  real32_T rtb_MatrixConcatenate4[16];
  real32_T rtb_Switch[3];
  real32_T rtb_Add_e;
  real32_T rtb_MathFunction1_c;
  real32_T rtb_DataTypeConversion_f;
  real32_T rtb_Product1_i;
  real32_T rtb_Subtract_j;
  real32_T rtb_VectorConcatenate_jq[9];
  real32_T rtb_Sum_a;
  real32_T rtb_Sum_i;
  real_T rtb_SumofElements;
  real_T rtb_Gain6;
  real_T rtb_Divide2[3];
  Barometer_Bus rtb_BusAssignment_i;
  int32_T rtb_Saturation2;
  GPS_uBlox_Bus rtb_BusAssignment_dk;
  real32_T rtb_VectorConcatenate_d[3];
  real32_T rtb_VectorConcatenate_m[9];
  MAG_Bus rtb_BusAssignment_o;
  real32_T rtb_RandomSource[3];
  real32_T rtb_Add_j[3];
  real32_T rtb_Add1_c[3];
  real32_T rtb_RandomSource1[3];
  real32_T rtb_integrate[3];
  int32_T i;
  real32_T rtb_VectorConcatenate_b5[3];
  real32_T rtb_Square_0[3];
  real32_T rtb_MatrixConcatenate4_0[4];
  real_T rtb_Product1_idx_2;
  real_T rtb_Product2_f_idx_3;
  real_T rtb_Product2_f_idx_2;
  real_T rtb_Product2_f_idx_1;
  real_T rtb_DataTypeConversion_idx_0;
  real_T Sum2_idx_1;
  real32_T rtb_Square_n_idx_3;
  real32_T rtb_Square_n_idx_2;
  real32_T rtb_Square_n_idx_1;
  real32_T rtb_Square_n_idx_0;
  real32_T rtb_Multiply_g_idx_2;
  real32_T rtb_Multiply_g_idx_1;
  real32_T rtb_Multiply_g_idx_0;
  real32_T rtb_vel_O_mDs_idx_2;
  real32_T rtb_vel_O_mDs_idx_0;
  real32_T tmp;
  real32_T DiscreteFilter_tmp_idx_2;
  real32_T DiscreteFilter_tmp_idx_1;
  uint16_T tmp_0;
  real32_T rtb_Sum_eh_tmp;
  real32_T rtb_Sum_eh_tmp_0;
  real32_T rtb_Sum_eh_tmp_1;
  real32_T rtb_Sum_eh_tmp_2;
  real32_T rtb_Sum_eh_tmp_3;
  real32_T rtb_Add_e_tmp;
  real32_T rtb_Add_e_tmp_0;

  /* Delay: '<Root>/Delay' */
  for (i = 0; i < 9; i++) {
    rtb_VectorConcatenate_m[i] = Plant_Y.Extended_States.M_BO[i];
  }

  /* Outputs for Atomic SubSystem: '<Root>/Actuators' */
  /* Trigonometry: '<S9>/TrigoFcn1' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_Gain_h = arm_cos_f32(Plant_Y.Plant_States.psi);

  /* SignalConversion: '<S9>/ConcatBufferAtVecConcentateIn1' */
  rtb_Square[0] = rtb_Gain_h;

  /* Trigonometry: '<S9>/TrigoFcn' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_Product11 = arm_sin_f32(Plant_Y.Plant_States.psi);

  /* Gain: '<S9>/Gain' */
  rtb_Square[1] = -rtb_Product11;

  /* SignalConversion: '<S9>/ConcatBufferAtVecConcentateIn3' incorporates:
   *  Constant: '<S9>/Constant1'
   */
  rtb_Square[2] = 0.0F;

  /* SignalConversion: '<S9>/ConcatBufferAtVecConcentate2In1' */
  rtb_Square[3] = rtb_Product11;

  /* SignalConversion: '<S9>/ConcatBufferAtVecConcentate2In2' */
  rtb_Square[4] = rtb_Gain_h;

  /* SignalConversion: '<S9>/ConcatBufferAtVecConcentate2In3' incorporates:
   *  Constant: '<S9>/Constant1'
   */
  rtb_Square[5] = 0.0F;

  /* SignalConversion: '<S9>/ConcatBufferAtVecConcentate1In3' */
  rtb_Square[6] = Plant_ConstB.VecConcentate3[0];
  rtb_Square[7] = Plant_ConstB.VecConcentate3[1];
  rtb_Square[8] = Plant_ConstB.VecConcentate3[2];

  /* Saturate: '<S14>/Saturation' incorporates:
   *  Inport: '<Root>/Control_Out'
   */
  if (Plant_U.Control_Out.actuator_cmd[0] > 2000) {
    tmp_0 = 2000U;
  } else if (Plant_U.Control_Out.actuator_cmd[0] < 1000) {
    tmp_0 = 1000U;
  } else {
    tmp_0 = Plant_U.Control_Out.actuator_cmd[0];
  }

  /* Gain: '<S14>/Gain' incorporates:
   *  Sum: '<S14>/Subtract'
   */
  rtb_vel_O_mDs_idx_0 = ((real32_T)tmp_0 - 1000.0F) * 0.000999987125F;

  /* DiscreteFilter: '<S10>/Discrete Filter' incorporates:
   *  Constant: '<S13>/Constant1'
   *  Constant: '<S15>/Constant'
   *  Gain: '<S13>/Gain1'
   *  Product: '<S13>/Multiply'
   *  RelationalOperator: '<S15>/Compare'
   *  Saturate: '<S13>/Saturation1'
   *  Sum: '<S13>/Add'
   */
  denAccum = (rtb_vel_O_mDs_idx_0 > 0.1F ? 718.078F * rtb_vel_O_mDs_idx_0 +
              88.448F : 0.0F) - 0.02F * Plant_DW.DiscreteFilter_states[0];

  /* Math: '<S16>/Square' incorporates:
   *  DiscreteFilter: '<S10>/Discrete Filter'
   *  Math: '<S18>/Square'
   */
  rtb_vel_O_mDs_idx_0 = denAccum * denAccum;

  /* Product: '<S16>/Multiply' incorporates:
   *  Constant: '<S16>/cT'
   */
  rtb_Multiply_g_idx_0 = (real32_T)(rtb_vel_O_mDs_idx_0 * 1.105E-5);

  /* Gain: '<S14>/Gain' */
  rtb_Square_n_idx_0 = rtb_vel_O_mDs_idx_0;

  /* DiscreteFilter: '<S10>/Discrete Filter' */
  rtb_Product11 = denAccum;

  /* Saturate: '<S14>/Saturation' incorporates:
   *  Inport: '<Root>/Control_Out'
   */
  if (Plant_U.Control_Out.actuator_cmd[1] > 2000) {
    tmp_0 = 2000U;
  } else if (Plant_U.Control_Out.actuator_cmd[1] < 1000) {
    tmp_0 = 1000U;
  } else {
    tmp_0 = Plant_U.Control_Out.actuator_cmd[1];
  }

  /* Gain: '<S14>/Gain' incorporates:
   *  Sum: '<S14>/Subtract'
   */
  rtb_vel_O_mDs_idx_0 = ((real32_T)tmp_0 - 1000.0F) * 0.000999987125F;

  /* DiscreteFilter: '<S10>/Discrete Filter' incorporates:
   *  Constant: '<S13>/Constant1'
   *  Constant: '<S15>/Constant'
   *  Gain: '<S13>/Gain1'
   *  Product: '<S13>/Multiply'
   *  RelationalOperator: '<S15>/Compare'
   *  Saturate: '<S13>/Saturation1'
   *  Sum: '<S13>/Add'
   */
  denAccum = (rtb_vel_O_mDs_idx_0 > 0.1F ? 718.078F * rtb_vel_O_mDs_idx_0 +
              88.448F : 0.0F) - 0.02F * Plant_DW.DiscreteFilter_states[1];

  /* Math: '<S16>/Square' incorporates:
   *  DiscreteFilter: '<S10>/Discrete Filter'
   *  Math: '<S18>/Square'
   */
  rtb_vel_O_mDs_idx_0 = denAccum * denAccum;

  /* Product: '<S16>/Multiply' incorporates:
   *  Constant: '<S16>/cT'
   */
  rtb_Multiply_g_idx_1 = (real32_T)(rtb_vel_O_mDs_idx_0 * 1.105E-5);

  /* Gain: '<S14>/Gain' */
  rtb_Square_n_idx_1 = rtb_vel_O_mDs_idx_0;

  /* DiscreteFilter: '<S10>/Discrete Filter' */
  DiscreteFilter_tmp_idx_1 = denAccum;

  /* Saturate: '<S14>/Saturation' incorporates:
   *  Inport: '<Root>/Control_Out'
   */
  if (Plant_U.Control_Out.actuator_cmd[2] > 2000) {
    tmp_0 = 2000U;
  } else if (Plant_U.Control_Out.actuator_cmd[2] < 1000) {
    tmp_0 = 1000U;
  } else {
    tmp_0 = Plant_U.Control_Out.actuator_cmd[2];
  }

  /* Gain: '<S14>/Gain' incorporates:
   *  Sum: '<S14>/Subtract'
   */
  rtb_vel_O_mDs_idx_0 = ((real32_T)tmp_0 - 1000.0F) * 0.000999987125F;

  /* DiscreteFilter: '<S10>/Discrete Filter' incorporates:
   *  Constant: '<S13>/Constant1'
   *  Constant: '<S15>/Constant'
   *  Gain: '<S13>/Gain1'
   *  Product: '<S13>/Multiply'
   *  RelationalOperator: '<S15>/Compare'
   *  Saturate: '<S13>/Saturation1'
   *  Sum: '<S13>/Add'
   */
  denAccum = (rtb_vel_O_mDs_idx_0 > 0.1F ? 718.078F * rtb_vel_O_mDs_idx_0 +
              88.448F : 0.0F) - 0.02F * Plant_DW.DiscreteFilter_states[2];

  /* Math: '<S16>/Square' incorporates:
   *  DiscreteFilter: '<S10>/Discrete Filter'
   *  Math: '<S18>/Square'
   */
  rtb_vel_O_mDs_idx_0 = denAccum * denAccum;

  /* Product: '<S16>/Multiply' incorporates:
   *  Constant: '<S16>/cT'
   */
  rtb_Multiply_g_idx_2 = (real32_T)(rtb_vel_O_mDs_idx_0 * 1.105E-5);

  /* Gain: '<S14>/Gain' */
  rtb_Square_n_idx_2 = rtb_vel_O_mDs_idx_0;

  /* DiscreteFilter: '<S10>/Discrete Filter' */
  DiscreteFilter_tmp_idx_2 = denAccum;

  /* Saturate: '<S14>/Saturation' incorporates:
   *  Inport: '<Root>/Control_Out'
   */
  if (Plant_U.Control_Out.actuator_cmd[3] > 2000) {
    tmp_0 = 2000U;
  } else if (Plant_U.Control_Out.actuator_cmd[3] < 1000) {
    tmp_0 = 1000U;
  } else {
    tmp_0 = Plant_U.Control_Out.actuator_cmd[3];
  }

  /* Gain: '<S14>/Gain' incorporates:
   *  Sum: '<S14>/Subtract'
   */
  rtb_vel_O_mDs_idx_0 = ((real32_T)tmp_0 - 1000.0F) * 0.000999987125F;

  /* DiscreteFilter: '<S10>/Discrete Filter' incorporates:
   *  Constant: '<S13>/Constant1'
   *  Constant: '<S15>/Constant'
   *  Gain: '<S13>/Gain1'
   *  Product: '<S13>/Multiply'
   *  RelationalOperator: '<S15>/Compare'
   *  Saturate: '<S13>/Saturation1'
   *  Sum: '<S13>/Add'
   */
  denAccum = (rtb_vel_O_mDs_idx_0 > 0.1F ? 718.078F * rtb_vel_O_mDs_idx_0 +
              88.448F : 0.0F) - 0.02F * Plant_DW.DiscreteFilter_states[3];

  /* Math: '<S16>/Square' incorporates:
   *  DiscreteFilter: '<S10>/Discrete Filter'
   *  Math: '<S18>/Square'
   */
  rtb_vel_O_mDs_idx_0 = denAccum * denAccum;

  /* Sum: '<S17>/Add' incorporates:
   *  DiscreteFilter: '<S10>/Discrete Filter'
   */
  rtb_Gain_h = ((DiscreteFilter_tmp_idx_2 - rtb_Product11) -
                DiscreteFilter_tmp_idx_1) + denAccum;

  /* Product: '<S20>/Multiply' */
  rtb_VectorConcatenate_d[0] = 0.0F;

  /* Product: '<S20>/Multiply1' incorporates:
   *  Delay: '<Root>/Delay'
   *  Product: '<S17>/Multiply'
   */
  rtb_VectorConcatenate_d[1] = rtb_Gain_h * Plant_Y.Plant_States.rot_x_B *
    0.0001287F;

  /* Product: '<S20>/Multiply2' */
  rtb_VectorConcatenate_d[2] = 0.0F;

  /* Product: '<S21>/Multiply' incorporates:
   *  Delay: '<Root>/Delay'
   *  Product: '<S17>/Multiply'
   */
  rtb_Add_la[0] = rtb_Gain_h * Plant_Y.Plant_States.rot_y_B * 0.0001287F;

  /* Product: '<S21>/Multiply1' */
  rtb_Add_la[1] = 0.0F;

  /* Product: '<S21>/Multiply2' */
  rtb_Add_la[2] = 0.0F;

  /* Update for DiscreteFilter: '<S10>/Discrete Filter' */
  Plant_DW.DiscreteFilter_states[0] = rtb_Product11;
  Plant_DW.DiscreteFilter_states[1] = DiscreteFilter_tmp_idx_1;
  Plant_DW.DiscreteFilter_states[2] = DiscreteFilter_tmp_idx_2;
  Plant_DW.DiscreteFilter_states[3] = denAccum;

  /* End of Outputs for SubSystem: '<Root>/Actuators' */

  /* Outputs for Atomic SubSystem: '<Root>/Environment' */
  /* RelationalOperator: '<S29>/Compare' incorporates:
   *  Constant: '<S29>/Constant'
   *  Delay: '<Root>/Delay'
   */
  rtb_Compare = (Plant_Y.Plant_States.h_R <= 0.0F);

  /* Switch: '<S28>/Switch2' incorporates:
   *  Product: '<S30>/Multiply'
   *  SignalConversion: '<S30>/TmpSignal ConversionAtMultiplyInport2'
   */
  if (rtb_Compare) {
    /* Switch: '<S30>/Switch1' incorporates:
     *  Constant: '<S30>/mg'
     *  Constant: '<S32>/Constant'
     *  Delay: '<Root>/Delay'
     *  Gain: '<S30>/Gain'
     *  RelationalOperator: '<S32>/Compare'
     *  Sum: '<S30>/Add'
     */
    if (Plant_Y.Plant_States.h_R <= -0.05F) {
      /* Switch: '<S30>/Switch3' incorporates:
       *  Constant: '<S30>/mg'
       *  Constant: '<S33>/Constant'
       *  Gain: '<S30>/Gain1'
       *  Gain: '<S30>/Gain2'
       *  Gain: '<S30>/Gain4'
       *  RelationalOperator: '<S33>/Compare'
       *  Sum: '<S30>/Add1'
       *  Sum: '<S30>/Add2'
       */
      if (Plant_Y.Plant_States.h_R <= -0.1F) {
        rtb_Gain_h = (Plant_Y.Plant_States.h_R - 13.7284F) - 50.0F *
          Plant_Y.Plant_States.vel_z_O;
      } else {
        rtb_Gain_h = (0.5F * Plant_Y.Plant_States.h_R - 13.7284F) - 20.0F *
          Plant_Y.Plant_States.vel_z_O;
      }

      /* End of Switch: '<S30>/Switch3' */
    } else {
      rtb_Gain_h = -13.7284F - 10.0F * Plant_Y.Plant_States.vel_z_O;
    }

    /* End of Switch: '<S30>/Switch1' */

    /* SignalConversion: '<S30>/TmpSignal ConversionAtMultiplyInport2' incorporates:
     *  Delay: '<Root>/Delay'
     *  Gain: '<S30>/Gain5'
     *  Gain: '<S30>/Gain6'
     */
    rtb_vel_O_mDs_idx_2 = -50.0F * Plant_Y.Plant_States.vel_x_O;
    tmp = -50.0F * Plant_Y.Plant_States.vel_y_O;
    for (i = 0; i < 3; i++) {
      rtb_Switch[i] = rtb_VectorConcatenate_m[i + 6] * rtb_Gain_h +
        (rtb_VectorConcatenate_m[i + 3] * tmp + rtb_VectorConcatenate_m[i] *
         rtb_vel_O_mDs_idx_2);
    }
  } else {
    rtb_Switch[0] = 0.0F;
    rtb_Switch[1] = 0.0F;
    rtb_Switch[2] = 0.0F;
  }

  /* End of Switch: '<S28>/Switch2' */

  /* Outputs for Atomic SubSystem: '<Root>/Actuators' */
  for (i = 0; i < 3; i++) {
    /* Gain: '<S8>/Gain' incorporates:
     *  Delay: '<Root>/Delay'
     *  Product: '<S8>/Multiply'
     */
    rtb_Add1_c[i] = -0.15F * (rtb_Square[i + 6] * Plant_Y.Plant_States.vel_z_O +
      (rtb_Square[i + 3] * Plant_Y.Plant_States.vel_y_O + rtb_Square[i] *
       Plant_Y.Plant_States.vel_x_O));

    /* Product: '<S27>/Multiply3' */
    rtb_VectorConcatenate_b5[i] = rtb_VectorConcatenate_m[i + 6] * 13.734F;
  }

  /* End of Outputs for SubSystem: '<Root>/Environment' */

  /* Product: '<S8>/Multiply1' incorporates:
   *  Math: '<S8>/Square'
   */
  for (i = 0; i < 3; i++) {
    rtb_Square_0[i] = rtb_Square[3 * i + 2] * rtb_Add1_c[2] + (rtb_Square[3 * i
      + 1] * rtb_Add1_c[1] + rtb_Square[3 * i] * rtb_Add1_c[0]);
  }

  /* End of Product: '<S8>/Multiply1' */

  /* Sum: '<S1>/Sum' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S11>/Constant1'
   *  Constant: '<S16>/cT'
   *  Gain: '<S11>/Gain'
   *  Product: '<S16>/Multiply'
   *  Sum: '<S11>/Sum of Elements'
   */
  rtb_Add1_c[0] = 0.0F;
  rtb_Add1_c[1] = 0.0F;
  rtb_Add1_c[2] = -(((rtb_Multiply_g_idx_0 + rtb_Multiply_g_idx_1) +
                     rtb_Multiply_g_idx_2) + (real32_T)(rtb_vel_O_mDs_idx_0 *
    1.105E-5));

  /* Outputs for Atomic SubSystem: '<Root>/Environment' */
  for (i = 0; i < 3; i++) {
    /* Sum: '<S3>/Add' incorporates:
     *  Product: '<S8>/Multiply2'
     *  Sum: '<S1>/Sum'
     */
    rtb_Add_j[i] = (rtb_Switch[i] + rtb_VectorConcatenate_b5[i]) + (rtb_Add1_c[i]
      + (rtb_VectorConcatenate_m[i + 6] * rtb_Square_0[2] +
         (rtb_VectorConcatenate_m[i + 3] * rtb_Square_0[1] +
          rtb_VectorConcatenate_m[i] * rtb_Square_0[0])));
  }

  /* End of Outputs for SubSystem: '<Root>/Actuators' */

  /* Switch: '<S28>/Switch1' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S31>/Gain'
   *  Gain: '<S31>/Gain1'
   *  Sum: '<S31>/Subtract'
   */
  if (rtb_Compare) {
    rtb_Switch[0] = (0.0F - 200.0F * Plant_Y.Extended_States.quat[1]) - 10.0F *
      Plant_Y.Plant_States.rot_x_B;
    rtb_Switch[1] = (0.0F - 200.0F * Plant_Y.Extended_States.quat[2]) - 10.0F *
      Plant_Y.Plant_States.rot_y_B;
    rtb_Switch[2] = 0.0F - 10.0F * Plant_Y.Plant_States.rot_z_B;
  } else {
    rtb_Switch[0] = 0.0F;
    rtb_Switch[1] = 0.0F;
    rtb_Switch[2] = 0.0F;
  }

  /* End of Switch: '<S28>/Switch1' */

  /* Outputs for Atomic SubSystem: '<Root>/Actuators' */
  for (i = 0; i < 3; i++) {
    /* Sum: '<S3>/Add1' incorporates:
     *  Constant: '<S18>/X_Frame'
     *  Math: '<S18>/Square'
     *  Product: '<S18>/Multiply'
     *  Sum: '<S12>/Sum'
     *  Sum: '<S19>/Sum'
     */
    rtb_Add1_c[i] = ((((Plant_ConstP.X_Frame_Value[i + 3] * rtb_Square_n_idx_1 +
                        Plant_ConstP.X_Frame_Value[i] * rtb_Square_n_idx_0) +
                       Plant_ConstP.X_Frame_Value[i + 6] * rtb_Square_n_idx_2) +
                      Plant_ConstP.X_Frame_Value[i + 9] * rtb_vel_O_mDs_idx_0) +
                     (rtb_VectorConcatenate_d[i] - rtb_Add_la[i])) +
      rtb_Switch[i];
  }

  /* End of Outputs for SubSystem: '<Root>/Actuators' */
  /* End of Outputs for SubSystem: '<Root>/Environment' */

  /* Outputs for Atomic SubSystem: '<Root>/Kinematic_Equation' */
  /* DiscreteIntegrator: '<S36>/Discrete-Time Integrator' */
  if (Plant_DW.DiscreteTimeIntegrator_PrevRese != 0) {
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[0] = Plant_ConstB.Constant1[0];
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[1] = Plant_ConstB.Constant1[1];
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[2] = Plant_ConstB.Constant1[2];
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[3] = Plant_ConstB.Constant1[3];
  }

  rtb_Square_n_idx_0 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[0];
  rtb_Square_n_idx_1 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[1];
  rtb_Square_n_idx_2 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[2];
  rtb_Square_n_idx_3 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[3];

  /* SignalConversion: '<S39>/ConcatBufferAtMatrix ConcatenateIn1' incorporates:
   *  Constant: '<S39>/Constant'
   */
  rtb_MatrixConcatenate4[0] = 0.0F;

  /* DiscreteIntegrator: '<S34>/Discrete-Time Integrator' */
  if (Plant_DW.DiscreteTimeIntegrator_PrevRe_d != 0) {
    Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2] = 0.0F;
  }

  /* SignalConversion: '<S39>/ConcatBufferAtMatrix ConcatenateIn2' incorporates:
   *  DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[1] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0];

  /* SignalConversion: '<S39>/ConcatBufferAtMatrix ConcatenateIn3' incorporates:
   *  DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[2] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1];

  /* SignalConversion: '<S39>/ConcatBufferAtMatrix ConcatenateIn4' incorporates:
   *  DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[3] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2];

  /* Gain: '<S39>/Gain1' incorporates:
   *  DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[4] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0];

  /* SignalConversion: '<S39>/ConcatBufferAtMatrix Concatenate1In2' incorporates:
   *  Constant: '<S39>/Constant1'
   */
  rtb_MatrixConcatenate4[5] = 0.0F;

  /* Gain: '<S39>/Gain2' incorporates:
   *  DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[6] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2];

  /* SignalConversion: '<S39>/ConcatBufferAtMatrix Concatenate1In4' incorporates:
   *  DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[7] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1];

  /* Gain: '<S39>/Gain3' incorporates:
   *  DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[8] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1];

  /* SignalConversion: '<S39>/ConcatBufferAtMatrix Concatenate2In2' incorporates:
   *  DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[9] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2];

  /* SignalConversion: '<S39>/ConcatBufferAtMatrix Concatenate2In3' incorporates:
   *  Constant: '<S39>/Constant2'
   */
  rtb_MatrixConcatenate4[10] = 0.0F;

  /* Gain: '<S39>/Gain4' incorporates:
   *  DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[11] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0];

  /* Gain: '<S39>/Gain6' incorporates:
   *  DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[12] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2];

  /* Gain: '<S39>/Gain7' incorporates:
   *  DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[13] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1];

  /* SignalConversion: '<S39>/ConcatBufferAtMatrix Concatenate3In3' incorporates:
   *  DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[14] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0];

  /* SignalConversion: '<S39>/ConcatBufferAtMatrix Concatenate3In4' incorporates:
   *  Constant: '<S39>/Constant3'
   */
  rtb_MatrixConcatenate4[15] = 0.0F;
  for (i = 0; i < 3; i++) {
    /* DiscreteIntegrator: '<S34>/Discrete-Time Integrator' */
    rtb_VectorConcatenate_d[i] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[i];

    /* Product: '<S34>/Multiply' incorporates:
     *  Constant: '<S34>/Inertia_Matrix'
     *  DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
     */
    rtb_Switch[i] = Plant_ConstP.Inertia_Matrix_Value[i + 6] *
      Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2] +
      (Plant_ConstP.Inertia_Matrix_Value[i + 3] *
       Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1] +
       Plant_ConstP.Inertia_Matrix_Value[i] *
       Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0]);
  }

  /* Product: '<S40>/Multiply' incorporates:
   *  DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
   */
  rtb_Add_la[0] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1] * rtb_Switch[2];

  /* Product: '<S40>/Multiply1' incorporates:
   *  DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
   */
  rtb_Add_la[1] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2] * rtb_Switch[0];

  /* Product: '<S40>/Multiply2' incorporates:
   *  DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
   */
  rtb_Add_la[2] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0] * rtb_Switch[1];

  /* Product: '<S41>/Multiply' incorporates:
   *  DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
   */
  rtb_Multiply_g_idx_2 = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2] *
    rtb_Switch[1];

  /* Product: '<S41>/Multiply1' incorporates:
   *  DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
   */
  rtb_Multiply_g_idx_0 = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0] *
    rtb_Switch[2];

  /* Product: '<S41>/Multiply2' incorporates:
   *  DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
   */
  rtb_Multiply_g_idx_1 = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1] *
    rtb_Switch[0];

  /* DiscreteIntegrator: '<S35>/Discrete-Time Integrator' */
  if (Plant_DW.DiscreteTimeIntegrator_PrevRe_k != 0) {
    Plant_DW.DiscreteTimeIntegrator_DSTATE_f[0] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_f[1] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_f[2] = 0.0F;
  }

  /* Product: '<S50>/Multiply' incorporates:
   *  DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S35>/Discrete-Time Integrator'
   */
  rtb_integrate1[0] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_f[2];

  /* Product: '<S50>/Multiply1' incorporates:
   *  DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S35>/Discrete-Time Integrator'
   */
  rtb_integrate1[1] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_f[0];

  /* Product: '<S50>/Multiply2' incorporates:
   *  DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S35>/Discrete-Time Integrator'
   */
  rtb_integrate1[2] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_f[1];

  /* DiscreteIntegrator: '<S35>/Discrete-Time Integrator' */
  rtb_vel_O_mDs_idx_0 = Plant_DW.DiscreteTimeIntegrator_DSTATE_f[0];

  /* Sum: '<S35>/Sum' incorporates:
   *  Constant: '<S35>/mass'
   *  DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S35>/Discrete-Time Integrator'
   *  Product: '<S35>/Divide'
   *  Product: '<S51>/Multiply'
   *  Sum: '<S43>/Sum'
   */
  rtb_Switch[0] = rtb_Add_j[0] / 1.4F - (rtb_integrate1[0] -
    Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_f[1]);

  /* DiscreteIntegrator: '<S35>/Discrete-Time Integrator' */
  rtb_Gain_h = Plant_DW.DiscreteTimeIntegrator_DSTATE_f[1];

  /* Sum: '<S35>/Sum' incorporates:
   *  Constant: '<S35>/mass'
   *  DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S35>/Discrete-Time Integrator'
   *  Product: '<S35>/Divide'
   *  Product: '<S51>/Multiply1'
   *  Sum: '<S43>/Sum'
   */
  rtb_Switch[1] = rtb_Add_j[1] / 1.4F - (rtb_integrate1[1] -
    Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_f[2]);

  /* DiscreteIntegrator: '<S35>/Discrete-Time Integrator' */
  rtb_vel_O_mDs_idx_2 = Plant_DW.DiscreteTimeIntegrator_DSTATE_f[2];

  /* Sum: '<S35>/Sum' incorporates:
   *  Constant: '<S35>/mass'
   *  DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S35>/Discrete-Time Integrator'
   *  Product: '<S35>/Divide'
   *  Product: '<S51>/Multiply2'
   *  Sum: '<S43>/Sum'
   */
  rtb_Switch[2] = rtb_Add_j[2] / 1.4F - (rtb_integrate1[2] -
    Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_f[0]);

  /* Product: '<S49>/Product2' incorporates:
   *  DiscreteIntegrator: '<S36>/Discrete-Time Integrator'
   *  Math: '<S38>/Square1'
   */
  tmp = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[2] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[2];

  /* Product: '<S49>/Product1' incorporates:
   *  DiscreteIntegrator: '<S36>/Discrete-Time Integrator'
   *  Math: '<S38>/Square'
   */
  rtb_Add_e_tmp = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[1] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[1];

  /* Product: '<S49>/Product3' incorporates:
   *  DiscreteIntegrator: '<S36>/Discrete-Time Integrator'
   *  Math: '<S38>/Square2'
   */
  rtb_Add_e_tmp_0 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[3] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[3];

  /* Sqrt: '<S48>/sqrt' incorporates:
   *  DiscreteIntegrator: '<S36>/Discrete-Time Integrator'
   *  Product: '<S49>/Product'
   *  Product: '<S49>/Product1'
   *  Product: '<S49>/Product2'
   *  Product: '<S49>/Product3'
   *  Sum: '<S49>/Sum'
   */
  rtb_Add_e = sqrtf(((Plant_DW.DiscreteTimeIntegrator_DSTATE_d[0] *
                      Plant_DW.DiscreteTimeIntegrator_DSTATE_d[0] +
                      rtb_Add_e_tmp) + tmp) + rtb_Add_e_tmp_0);

  /* Product: '<S47>/Product1' incorporates:
   *  DiscreteIntegrator: '<S36>/Discrete-Time Integrator'
   */
  rtb_Product1_i = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[1] / rtb_Add_e;

  /* Product: '<S47>/Product2' incorporates:
   *  DiscreteIntegrator: '<S36>/Discrete-Time Integrator'
   */
  rtb_MathFunction1_c = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[2] / rtb_Add_e;

  /* Product: '<S47>/Product' incorporates:
   *  DiscreteIntegrator: '<S36>/Discrete-Time Integrator'
   */
  rtb_DataTypeConversion_f = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[0] /
    rtb_Add_e;

  /* Product: '<S47>/Product3' incorporates:
   *  DiscreteIntegrator: '<S36>/Discrete-Time Integrator'
   */
  rtb_Add_e = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[3] / rtb_Add_e;

  /* Product: '<S44>/Product7' incorporates:
   *  Product: '<S45>/Product7'
   */
  rtb_Sum_eh_tmp = rtb_Add_e * rtb_Add_e;

  /* Product: '<S44>/Product' incorporates:
   *  Product: '<S45>/Product'
   */
  rtb_Sum_eh_tmp_0 = rtb_Product1_i * rtb_MathFunction1_c;

  /* Product: '<S44>/Product1' incorporates:
   *  Product: '<S45>/Product1'
   */
  rtb_Sum_eh_tmp_1 = rtb_DataTypeConversion_f * rtb_Add_e;

  /* Product: '<S44>/Product2' incorporates:
   *  Product: '<S46>/Product9'
   */
  rtb_Sum_eh_tmp_2 = rtb_Product1_i * rtb_Add_e;

  /* Product: '<S44>/Product3' incorporates:
   *  Product: '<S46>/Product1'
   */
  rtb_Sum_i = rtb_DataTypeConversion_f * rtb_MathFunction1_c;

  /* Product: '<S44>/Product6' incorporates:
   *  Product: '<S46>/Product7'
   */
  rtb_Sum_eh_tmp_3 = rtb_MathFunction1_c * rtb_MathFunction1_c;

  /* Sum: '<S44>/Sum' incorporates:
   *  Constant: '<S44>/Constant'
   *  Gain: '<S44>/Gain'
   *  Gain: '<S44>/Gain1'
   *  Gain: '<S44>/Gain2'
   *  Product: '<S44>/Product'
   *  Product: '<S44>/Product1'
   *  Product: '<S44>/Product2'
   *  Product: '<S44>/Product3'
   *  Product: '<S44>/Product4'
   *  Product: '<S44>/Product5'
   *  Product: '<S44>/Product6'
   *  Product: '<S44>/Product7'
   *  Product: '<S44>/Product8'
   *  Sum: '<S44>/Sum1'
   *  Sum: '<S44>/Sum2'
   *  Sum: '<S44>/Sum3'
   */
  rtb_Sum_a = (((0.5F - rtb_Sum_eh_tmp_3) - rtb_Sum_eh_tmp) * 2.0F * rtb_Switch
               [0] + (rtb_Sum_eh_tmp_0 - rtb_Sum_eh_tmp_1) * 2.0F * rtb_Switch[1])
    + (rtb_Sum_eh_tmp_2 + rtb_Sum_i) * 2.0F * rtb_Switch[2];

  /* Product: '<S45>/Product2' incorporates:
   *  Product: '<S46>/Product2'
   */
  rtb_Subtract_j = rtb_DataTypeConversion_f * rtb_Product1_i;

  /* Product: '<S45>/Product3' incorporates:
   *  Product: '<S46>/Product3'
   */
  rtb_MathFunction1_c *= rtb_Add_e;

  /* Sum: '<S45>/Sum3' incorporates:
   *  Constant: '<S45>/Constant'
   *  Product: '<S45>/Product6'
   *  Sum: '<S46>/Sum3'
   */
  rtb_Product1_i = 0.5F - rtb_Product1_i * rtb_Product1_i;

  /* Sum: '<S45>/Sum' incorporates:
   *  Gain: '<S45>/Gain'
   *  Gain: '<S45>/Gain1'
   *  Gain: '<S45>/Gain2'
   *  Product: '<S45>/Product2'
   *  Product: '<S45>/Product3'
   *  Product: '<S45>/Product4'
   *  Product: '<S45>/Product5'
   *  Product: '<S45>/Product8'
   *  Sum: '<S45>/Sum1'
   *  Sum: '<S45>/Sum2'
   *  Sum: '<S45>/Sum3'
   */
  rtb_DataTypeConversion_f = ((rtb_Product1_i - rtb_Sum_eh_tmp) * 2.0F *
    rtb_Switch[1] + (rtb_Sum_eh_tmp_0 + rtb_Sum_eh_tmp_1) * 2.0F * rtb_Switch[0])
    + (rtb_MathFunction1_c - rtb_Subtract_j) * 2.0F * rtb_Switch[2];

  /* Sum: '<S46>/Sum' incorporates:
   *  Gain: '<S46>/Gain1'
   *  Gain: '<S46>/Gain2'
   *  Gain: '<S46>/Gain3'
   *  Product: '<S46>/Product4'
   *  Product: '<S46>/Product5'
   *  Product: '<S46>/Product8'
   *  Sum: '<S46>/Sum1'
   *  Sum: '<S46>/Sum2'
   *  Sum: '<S46>/Sum3'
   */
  rtb_Sum_i = ((rtb_Sum_eh_tmp_2 - rtb_Sum_i) * 2.0F * rtb_Switch[0] +
               (rtb_Subtract_j + rtb_MathFunction1_c) * 2.0F * rtb_Switch[1]) +
    (rtb_Product1_i - rtb_Sum_eh_tmp_3) * 2.0F * rtb_Switch[2];

  /* Product: '<S38>/Multiply2' incorporates:
   *  DiscreteIntegrator: '<S36>/Discrete-Time Integrator'
   */
  rtb_Sum_eh_tmp_0 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[2] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[3];

  /* Product: '<S38>/Multiply1' incorporates:
   *  DiscreteIntegrator: '<S36>/Discrete-Time Integrator'
   */
  rtb_Sum_eh_tmp_1 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[0] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[1];

  /* Product: '<S38>/Multiply8' incorporates:
   *  DiscreteIntegrator: '<S36>/Discrete-Time Integrator'
   */
  rtb_Sum_eh_tmp_3 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[1] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[2];

  /* Product: '<S38>/Multiply7' incorporates:
   *  DiscreteIntegrator: '<S36>/Discrete-Time Integrator'
   */
  rtb_Sum_eh_tmp = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[0] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[3];

  /* Sum: '<S38>/Subtract' incorporates:
   *  DiscreteIntegrator: '<S36>/Discrete-Time Integrator'
   *  Product: '<S38>/Multiply4'
   *  Product: '<S38>/Multiply5'
   */
  rtb_Subtract_j = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[0] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[2] -
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[3] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[1];

  /* DiscreteIntegrator: '<S35>/Discrete-Time Integrator1' */
  if (Plant_DW.DiscreteTimeIntegrator1_PrevRes != 0) {
    Plant_DW.DiscreteTimeIntegrator1_DSTATE[0] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator1_DSTATE[1] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator1_DSTATE[2] = 0.0F;
  }

  rtb_Switch[0] = Plant_DW.DiscreteTimeIntegrator1_DSTATE[0];
  rtb_Switch[1] = Plant_DW.DiscreteTimeIntegrator1_DSTATE[1];
  rtb_Switch[2] = Plant_DW.DiscreteTimeIntegrator1_DSTATE[2];

  /* End of DiscreteIntegrator: '<S35>/Discrete-Time Integrator1' */

  /* Product: '<S36>/Multiply' incorporates:
   *  DiscreteIntegrator: '<S36>/Discrete-Time Integrator'
   */
  for (i = 0; i < 4; i++) {
    rtb_Sum_eh_tmp_2 = rtb_MatrixConcatenate4[i + 12] *
      Plant_DW.DiscreteTimeIntegrator_DSTATE_d[3] + (rtb_MatrixConcatenate4[i +
      8] * Plant_DW.DiscreteTimeIntegrator_DSTATE_d[2] +
      (rtb_MatrixConcatenate4[i + 4] * Plant_DW.DiscreteTimeIntegrator_DSTATE_d
       [1] + rtb_MatrixConcatenate4[i] *
       Plant_DW.DiscreteTimeIntegrator_DSTATE_d[0]));
    rtb_MatrixConcatenate4_0[i] = rtb_Sum_eh_tmp_2;
  }

  /* End of Product: '<S36>/Multiply' */

  /* Update for DiscreteIntegrator: '<S36>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S36>/Gain'
   */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_d[0] += 0.5F *
    rtb_MatrixConcatenate4_0[0] * 0.002F;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_d[1] += 0.5F *
    rtb_MatrixConcatenate4_0[1] * 0.002F;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_d[2] += 0.5F *
    rtb_MatrixConcatenate4_0[2] * 0.002F;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_d[3] += 0.5F *
    rtb_MatrixConcatenate4_0[3] * 0.002F;
  Plant_DW.DiscreteTimeIntegrator_PrevRese = 0;

  /* Sum: '<S34>/Sum' incorporates:
   *  Sum: '<S37>/Sum'
   */
  rtb_Add_j[0] = rtb_Add1_c[0] - (rtb_Add_la[0] - rtb_Multiply_g_idx_2);
  rtb_Add_j[1] = rtb_Add1_c[1] - (rtb_Add_la[1] - rtb_Multiply_g_idx_0);
  rtb_Add_j[2] = rtb_Add1_c[2] - (rtb_Add_la[2] - rtb_Multiply_g_idx_1);

  /* Product: '<S34>/Divide' incorporates:
   *  Constant: '<S34>/Inertia_Matrix'
   */
  rt_mldivide_U1f3x3_U2f3x1_Yf3x1(Plant_ConstP.Inertia_Matrix_Value, rtb_Add_j,
    rtb_Add1_c);

  /* Update for DiscreteIntegrator: '<S34>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_PrevRe_d = 0;

  /* Update for DiscreteIntegrator: '<S35>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_PrevRe_k = 0;

  /* Update for DiscreteIntegrator: '<S34>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0] += 0.002F * rtb_Add1_c[0];

  /* Update for DiscreteIntegrator: '<S35>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_f[0] += 0.002F * rtb_Sum_a;

  /* Update for DiscreteIntegrator: '<S35>/Discrete-Time Integrator1' */
  Plant_DW.DiscreteTimeIntegrator1_DSTATE[0] += 0.002F * rtb_vel_O_mDs_idx_0;

  /* Update for DiscreteIntegrator: '<S34>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1] += 0.002F * rtb_Add1_c[1];

  /* Update for DiscreteIntegrator: '<S35>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_f[1] += 0.002F *
    rtb_DataTypeConversion_f;

  /* Update for DiscreteIntegrator: '<S35>/Discrete-Time Integrator1' */
  Plant_DW.DiscreteTimeIntegrator1_DSTATE[1] += 0.002F * rtb_Gain_h;

  /* Update for DiscreteIntegrator: '<S34>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2] += 0.002F * rtb_Add1_c[2];

  /* Update for DiscreteIntegrator: '<S35>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_f[2] += 0.002F * rtb_Sum_i;

  /* Update for DiscreteIntegrator: '<S35>/Discrete-Time Integrator1' */
  Plant_DW.DiscreteTimeIntegrator1_DSTATE[2] += 0.002F * rtb_vel_O_mDs_idx_2;
  Plant_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* End of Outputs for SubSystem: '<Root>/Kinematic_Equation' */

  /* Outputs for Atomic SubSystem: '<Root>/Bus_Assignment' */
  /* Product: '<S23>/Product' */
  rtb_Multiply_g_idx_0 = rtb_Square_n_idx_0 * rtb_Square_n_idx_0;
  rtb_Multiply_g_idx_1 = rtb_Square_n_idx_1 * rtb_Square_n_idx_1;
  rtb_Multiply_g_idx_2 = rtb_Square_n_idx_2 * rtb_Square_n_idx_2;
  rtb_Product1_i = rtb_Square_n_idx_3 * rtb_Square_n_idx_3;

  /* Sum: '<S23>/Add' incorporates:
   *  Product: '<S23>/Product'
   */
  rtb_VectorConcatenate_jq[0] = ((rtb_Multiply_g_idx_0 + rtb_Multiply_g_idx_1) -
    rtb_Multiply_g_idx_2) - rtb_Product1_i;

  /* Gain: '<S23>/Gain' incorporates:
   *  Product: '<S23>/Product1'
   *  Product: '<S23>/Product2'
   *  Sum: '<S23>/Add1'
   */
  rtb_VectorConcatenate_jq[1] = (rtb_Square_n_idx_1 * rtb_Square_n_idx_2 +
    rtb_Square_n_idx_0 * rtb_Square_n_idx_3) * 2.0F;

  /* Product: '<S23>/Product3' incorporates:
   *  Product: '<S23>/Product9'
   */
  rtb_Sum_eh_tmp_2 = rtb_Square_n_idx_1 * rtb_Square_n_idx_3;

  /* Gain: '<S23>/Gain1' incorporates:
   *  Product: '<S23>/Product3'
   *  Product: '<S23>/Product4'
   *  Sum: '<S23>/Add2'
   */
  rtb_VectorConcatenate_jq[2] = (rtb_Sum_eh_tmp_2 - rtb_Square_n_idx_0 *
    rtb_Square_n_idx_2) * 2.0F;

  /* Gain: '<S23>/Gain2' incorporates:
   *  Product: '<S23>/Product5'
   *  Product: '<S23>/Product6'
   *  Sum: '<S23>/Add3'
   */
  rtb_VectorConcatenate_jq[3] = (rtb_Square_n_idx_1 * rtb_Square_n_idx_2 -
    rtb_Square_n_idx_0 * rtb_Square_n_idx_3) * 2.0F;

  /* Sum: '<S23>/Add5' incorporates:
   *  Product: '<S23>/Product'
   *  Sum: '<S23>/Add8'
   */
  rtb_Multiply_g_idx_0 -= rtb_Multiply_g_idx_1;
  rtb_VectorConcatenate_jq[4] = (rtb_Multiply_g_idx_0 + rtb_Multiply_g_idx_2) -
    rtb_Product1_i;

  /* Gain: '<S23>/Gain3' incorporates:
   *  Product: '<S23>/Product7'
   *  Product: '<S23>/Product8'
   *  Sum: '<S23>/Add4'
   */
  rtb_VectorConcatenate_jq[5] = (rtb_Square_n_idx_2 * rtb_Square_n_idx_3 +
    rtb_Square_n_idx_0 * rtb_Square_n_idx_1) * 2.0F;

  /* Gain: '<S23>/Gain4' incorporates:
   *  Product: '<S23>/Product10'
   *  Sum: '<S23>/Add6'
   */
  rtb_VectorConcatenate_jq[6] = (rtb_Sum_eh_tmp_2 + rtb_Square_n_idx_0 *
    rtb_Square_n_idx_2) * 2.0F;

  /* Gain: '<S23>/Gain5' incorporates:
   *  Product: '<S23>/Product11'
   *  Product: '<S23>/Product12'
   *  Sum: '<S23>/Add7'
   */
  rtb_VectorConcatenate_jq[7] = (rtb_Square_n_idx_2 * rtb_Square_n_idx_3 -
    rtb_Square_n_idx_0 * rtb_Square_n_idx_1) * 2.0F;

  /* Sum: '<S23>/Add8' incorporates:
   *  Product: '<S23>/Product'
   */
  rtb_VectorConcatenate_jq[8] = (rtb_Multiply_g_idx_0 - rtb_Multiply_g_idx_2) +
    rtb_Product1_i;

  /* BusAssignment: '<S2>/Bus Assignment2' incorporates:
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S2>/Constant5'
   *  Delay: '<Root>/Delay'
   *  DiscreteFilter: '<S10>/Discrete Filter'
   *  Math: '<S2>/Square'
   *  SignalConversion: '<S2>/TmpHiddenBufferAtBus Assignment2Inport1'
   */
  Plant_Y.Extended_States = Plant_rtZExtended_States_Bus;
  Plant_Y.Extended_States.temprature = 25.0F;
  Plant_Y.Extended_States.prop_vel[0] = rtb_Product11;
  Plant_Y.Extended_States.prop_vel[4] = 0.0F;
  Plant_Y.Extended_States.prop_vel[1] = DiscreteFilter_tmp_idx_1;
  Plant_Y.Extended_States.prop_vel[5] = 0.0F;
  Plant_Y.Extended_States.prop_vel[2] = DiscreteFilter_tmp_idx_2;
  Plant_Y.Extended_States.prop_vel[6] = 0.0F;

  /* Outputs for Atomic SubSystem: '<Root>/Actuators' */
  Plant_Y.Extended_States.prop_vel[3] = denAccum;

  /* End of Outputs for SubSystem: '<Root>/Actuators' */
  Plant_Y.Extended_States.prop_vel[7] = 0.0F;
  for (i = 0; i < 3; i++) {
    Plant_Y.Extended_States.M_BO[3 * i] = rtb_VectorConcatenate_jq[i];
    Plant_Y.Extended_States.M_BO[1 + 3 * i] = rtb_VectorConcatenate_jq[i + 3];
    Plant_Y.Extended_States.M_BO[2 + 3 * i] = rtb_VectorConcatenate_jq[i + 6];
  }

  for (i = 0; i < 9; i++) {
    Plant_Y.Extended_States.M_OB[i] = rtb_VectorConcatenate_jq[i];
  }

  Plant_Y.Extended_States.quat[0] = rtb_Square_n_idx_0;
  Plant_Y.Extended_States.quat[1] = rtb_Square_n_idx_1;
  Plant_Y.Extended_States.quat[2] = rtb_Square_n_idx_2;
  Plant_Y.Extended_States.quat[3] = rtb_Square_n_idx_3;

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
   *  Constant: '<S38>/Constant'
   *  Constant: '<S38>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Product: '<S38>/Multiply'
   *  Product: '<S38>/Multiply1'
   *  Product: '<S38>/Multiply2'
   *  Product: '<S38>/Multiply3'
   *  Sum: '<S38>/Add'
   *  Sum: '<S38>/Add1'
   *  Sum: '<S38>/Subtract2'
   *  Trigonometry: '<S38>/Atan2'
   */
  Plant_Y.Plant_States.phi = atan2f((rtb_Sum_eh_tmp_1 + rtb_Sum_eh_tmp_0) * 2.0F,
    1.0F - 2.0F * (rtb_Add_e_tmp + tmp));

  /* End of Outputs for SubSystem: '<Root>/Bus_Assignment' */

  /* Product: '<S38>/Multiply6' incorporates:
   *  Constant: '<S38>/Constant'
   */
  denAccum = 2.0F * rtb_Subtract_j;

  /* Saturate: '<S38>/Saturation' */
  if (denAccum > 1.0F) {
    denAccum = 1.0F;
  } else {
    if (denAccum < -1.0F) {
      denAccum = -1.0F;
    }
  }

  /* End of Saturate: '<S38>/Saturation' */

  /* Outputs for Atomic SubSystem: '<Root>/Bus_Assignment' */
  /* BusAssignment: '<S2>/Bus Assignment' incorporates:
   *  BusAssignment: '<S2>/Bus Assignment1'
   *  Constant: '<S38>/Constant'
   *  Constant: '<S38>/Constant1'
   *  Delay: '<Root>/Delay'
   *  Product: '<S38>/Multiply10'
   *  Product: '<S38>/Multiply7'
   *  Product: '<S38>/Multiply8'
   *  Product: '<S38>/Multiply9'
   *  Sum: '<S38>/Add2'
   *  Sum: '<S38>/Add3'
   *  Sum: '<S38>/Subtract1'
   *  Trigonometry: '<S38>/Asin'
   *  Trigonometry: '<S38>/Atan1'
   */
  Plant_Y.Plant_States.theta = asinf(denAccum);
  Plant_Y.Plant_States.psi = atan2f((rtb_Sum_eh_tmp + rtb_Sum_eh_tmp_3) * 2.0F,
    1.0F - 2.0F * (rtb_Add_e_tmp_0 + tmp));

  /* End of Outputs for SubSystem: '<Root>/Kinematic_Equation' */
  Plant_Y.Plant_States.rot_x_B = rtb_VectorConcatenate_d[0];
  Plant_Y.Plant_States.rot_y_B = rtb_VectorConcatenate_d[1];
  Plant_Y.Plant_States.rot_z_B = rtb_VectorConcatenate_d[2];
  Plant_Y.Plant_States.acc_x_O = rtb_Sum_a;
  Plant_Y.Plant_States.acc_y_O = rtb_DataTypeConversion_f;
  Plant_Y.Plant_States.acc_z_O = rtb_Sum_i;
  Plant_Y.Plant_States.vel_x_O = rtb_vel_O_mDs_idx_0;
  Plant_Y.Plant_States.vel_y_O = rtb_Gain_h;
  Plant_Y.Plant_States.vel_z_O = rtb_vel_O_mDs_idx_2;

  /* Trigonometry: '<S25>/Trigonometric Function1' incorporates:
   *  Delay: '<S24>/Delay1'
   *  Trigonometry: '<S25>/Trigonometric Function2'
   */
  Sum2_idx_1 = cos(Plant_DW.Delay1_DSTATE[0]);

  /* Trigonometry: '<S25>/Trigonometric Function' incorporates:
   *  Delay: '<S24>/Delay1'
   */
  rtb_SumofElements = sin(Plant_DW.Delay1_DSTATE[0]);

  /* Sum: '<S25>/Subtract' incorporates:
   *  Constant: '<S25>/a1'
   *  Math: '<S25>/u^2'
   *  Product: '<S25>/Product'
   */
  rtb_SumofElements = 1.0 - rtb_SumofElements * rtb_SumofElements *
    Plant_ConstB.e_2_g;

  /* Math: '<S25>/sqrt'
   *
   * About '<S25>/sqrt':
   *  Operator: sqrt
   */
  if (rtb_SumofElements < 0.0) {
    rtb_SumofElements = -sqrt(fabs(rtb_SumofElements));
  } else {
    rtb_SumofElements = sqrt(rtb_SumofElements);
  }

  /* End of Math: '<S25>/sqrt' */

  /* Product: '<S25>/Divide' incorporates:
   *  Constant: '<S25>/a'
   */
  rtb_SumofElements = 6.378137E+6 / rtb_SumofElements;

  /* Sum: '<S25>/Add' incorporates:
   *  Constant: '<S25>/constant2'
   *  Delay: '<S24>/Delay1'
   *  Math: '<S25>/u^1'
   *  Product: '<S25>/Product2'
   *  Product: '<S25>/Product3'
   *  Sum: '<S25>/Subtract2'
   *  Trigonometry: '<S25>/Trigonometric Function1'
   */
  rtb_Gain6 = (1.0 - Sum2_idx_1 * Sum2_idx_1 * Plant_ConstB.e_2_g) *
    rtb_SumofElements + Plant_DW.Delay1_DSTATE[2];

  /* Sum: '<S25>/Add1' incorporates:
   *  Delay: '<S24>/Delay1'
   */
  rtb_SumofElements += Plant_DW.Delay1_DSTATE[2];

  /* Product: '<S25>/Product4' */
  rtb_SumofElements *= Sum2_idx_1;

  /* BusAssignment: '<S2>/Bus Assignment1' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S2>/Gain'
   */
  Plant_Y.Plant_States.x_R = rtb_Switch[0];
  Plant_Y.Plant_States.y_R = rtb_Switch[1];
  Plant_Y.Plant_States.h_R = -rtb_Switch[2];

  /* Signum: '<S26>/Sign' */
  if (rtb_Gain6 < 0.0) {
    rtb_DataTypeConversion_idx_0 = -1.0;
    Sum2_idx_1 = -1.0;
  } else if (rtb_Gain6 > 0.0) {
    rtb_DataTypeConversion_idx_0 = 1.0;
    Sum2_idx_1 = 1.0;
  } else {
    rtb_DataTypeConversion_idx_0 = rtb_Gain6;
    Sum2_idx_1 = rtb_Gain6;
  }

  /* Switch: '<S26>/Switch' incorporates:
   *  Constant: '<S26>/Constant'
   */
  if (Sum2_idx_1 == 0.0) {
    rtb_DataTypeConversion_idx_0 = 1.0;
  }

  /* Abs: '<S26>/Abs' */
  Sum2_idx_1 = fabs(rtb_Gain6);

  /* Saturate: '<S26>/Saturation' */
  if (Sum2_idx_1 > 1.0E+8) {
    Sum2_idx_1 = 1.0E+8;
  } else {
    if (Sum2_idx_1 < 1.0E-6) {
      Sum2_idx_1 = 1.0E-6;
    }
  }

  /* Sum: '<S24>/Add' incorporates:
   *  Abs: '<S26>/Abs'
   *  DataTypeConversion: '<S24>/Data Type Conversion'
   *  Delay: '<S24>/Delay'
   *  Delay: '<S24>/Delay1'
   *  Product: '<S24>/Divide'
   *  Product: '<S26>/Product'
   *  Sum: '<S24>/Subtract'
   */
  Plant_DW.Delay1_DSTATE[0] += 1.0 / (Sum2_idx_1 * rtb_DataTypeConversion_idx_0)
    * (rtb_Switch[0] - Plant_DW.Delay_DSTATE_a[0]);

  /* Update for Delay: '<S24>/Delay' incorporates:
   *  DataTypeConversion: '<S24>/Data Type Conversion'
   */
  Plant_DW.Delay_DSTATE_a[0] = rtb_Switch[0];

  /* Signum: '<S26>/Sign' */
  if (rtb_SumofElements < 0.0) {
    rtb_DataTypeConversion_idx_0 = -1.0;
    Sum2_idx_1 = -1.0;
  } else if (rtb_SumofElements > 0.0) {
    rtb_DataTypeConversion_idx_0 = 1.0;
    Sum2_idx_1 = 1.0;
  } else {
    rtb_DataTypeConversion_idx_0 = rtb_SumofElements;
    Sum2_idx_1 = rtb_SumofElements;
  }

  /* Switch: '<S26>/Switch' incorporates:
   *  Constant: '<S26>/Constant'
   */
  if (Sum2_idx_1 == 0.0) {
    rtb_DataTypeConversion_idx_0 = 1.0;
  }

  /* Abs: '<S26>/Abs' */
  Sum2_idx_1 = fabs(rtb_SumofElements);

  /* Saturate: '<S26>/Saturation' */
  if (Sum2_idx_1 > 1.0E+8) {
    Sum2_idx_1 = 1.0E+8;
  } else {
    if (Sum2_idx_1 < 1.0E-6) {
      Sum2_idx_1 = 1.0E-6;
    }
  }

  /* Sum: '<S24>/Add' incorporates:
   *  Abs: '<S26>/Abs'
   *  DataTypeConversion: '<S24>/Data Type Conversion'
   *  Delay: '<S24>/Delay'
   *  Delay: '<S24>/Delay1'
   *  Product: '<S24>/Divide'
   *  Product: '<S26>/Product'
   *  Sum: '<S24>/Subtract'
   */
  Plant_DW.Delay1_DSTATE[1] += 1.0 / (Sum2_idx_1 * rtb_DataTypeConversion_idx_0)
    * (rtb_Switch[1] - Plant_DW.Delay_DSTATE_a[1]);

  /* Update for Delay: '<S24>/Delay' incorporates:
   *  DataTypeConversion: '<S24>/Data Type Conversion'
   */
  Plant_DW.Delay_DSTATE_a[1] = rtb_Switch[1];

  /* Sum: '<S24>/Add' incorporates:
   *  Abs: '<S26>/Abs'
   *  DataTypeConversion: '<S24>/Data Type Conversion'
   *  Delay: '<S24>/Delay'
   *  Delay: '<S24>/Delay1'
   *  Product: '<S24>/Divide'
   *  Sum: '<S24>/Subtract'
   */
  Plant_DW.Delay1_DSTATE[2] += -(rtb_Switch[2] - Plant_DW.Delay_DSTATE_a[2]);

  /* Update for Delay: '<S24>/Delay' incorporates:
   *  DataTypeConversion: '<S24>/Data Type Conversion'
   */
  Plant_DW.Delay_DSTATE_a[2] = rtb_Switch[2];

  /* BusAssignment: '<S2>/Bus Assignment1' incorporates:
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant2'
   *  Constant: '<S2>/Constant3'
   *  Delay: '<Root>/Delay'
   *  Delay: '<S24>/Delay1'
   *  Memory: '<S22>/Memory1'
   */
  Plant_Y.Plant_States.lat = Plant_DW.Delay1_DSTATE[0];
  Plant_Y.Plant_States.lon = Plant_DW.Delay1_DSTATE[1];
  Plant_Y.Plant_States.alt = Plant_DW.Delay1_DSTATE[2];
  Plant_Y.Plant_States.lon_ref = 0.20214403396598327;
  Plant_Y.Plant_States.lat_ref = 0.84011598077672256;
  Plant_Y.Plant_States.alt_ref = 200.0;
  Plant_Y.Plant_States.timestamp = Plant_DW.Memory1_PreviousInput_o;

  /* Update for Memory: '<S22>/Memory1' incorporates:
   *  Constant: '<S22>/dt'
   *  Sum: '<S22>/Sum'
   */
  Plant_DW.Memory1_PreviousInput_o += PLANT_EXPORT.period;

  /* End of Outputs for SubSystem: '<Root>/Bus_Assignment' */

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_Model' */
  /* Outputs for Atomic SubSystem: '<S5>/Sensor_Baro' */
  /* Saturate: '<S60>/Limit  altitude  to troposhere' incorporates:
   *  DataTypeConversion: '<S58>/Data Type Conversion'
   *  Delay: '<Root>/Delay'
   */
  if ((real32_T)Plant_Y.Plant_States.alt > 11000.0F) {
    rtb_Gain_h = 11000.0F;
  } else if ((real32_T)Plant_Y.Plant_States.alt < 0.0F) {
    rtb_Gain_h = 0.0F;
  } else {
    rtb_Gain_h = (real32_T)Plant_Y.Plant_States.alt;
  }

  /* End of Saturate: '<S60>/Limit  altitude  to troposhere' */

  /* Sum: '<S60>/Sum1' incorporates:
   *  Constant: '<S60>/Sea Level  Temperature'
   *  Gain: '<S60>/Lapse Rate'
   */
  rtb_DataTypeConversion_f = 288.15F - 0.0065F * rtb_Gain_h;

  /* Sum: '<S60>/Sum' incorporates:
   *  Constant: '<S60>/Altitude of Troposphere'
   *  DataTypeConversion: '<S58>/Data Type Conversion'
   *  Delay: '<Root>/Delay'
   */
  rtb_MathFunction1_c = 11000.0F - (real32_T)Plant_Y.Plant_States.alt;

  /* Saturate: '<S60>/Limit  altitude  to Stratosphere' incorporates:
   *  Constant: '<S60>/Altitude of Troposphere'
   *  DataTypeConversion: '<S58>/Data Type Conversion'
   *  Delay: '<Root>/Delay'
   *  Sum: '<S60>/Sum'
   */
  if (11000.0F - (real32_T)Plant_Y.Plant_States.alt > 0.0F) {
    rtb_MathFunction1_c = 0.0F;
  } else {
    if (11000.0F - (real32_T)Plant_Y.Plant_States.alt < -9000.0F) {
      rtb_MathFunction1_c = -9000.0F;
    }
  }

  /* End of Saturate: '<S60>/Limit  altitude  to Stratosphere' */

  /* Product: '<S60>/Product2' incorporates:
   *  Constant: '<S60>/Constant'
   *  Gain: '<S60>/1//T0'
   *  Gain: '<S60>/P0'
   *  Gain: '<S60>/g//R'
   *  Math: '<S60>/(T//T0)^(g//LR) '
   *  Math: '<S60>/Stratosphere Model'
   *  Product: '<S60>/Product1'
   *
   * About '<S60>/Stratosphere Model':
   *  Operator: exp
   */
  rtb_Product11 = powf(0.00347041478F * rtb_DataTypeConversion_f, 5.25587559F) *
    101325.0F * expf(1.0F / rtb_DataTypeConversion_f * (0.0341631919F *
    rtb_MathFunction1_c));

  /* S-Function (sdsprandsrc2): '<S59>/Random Source' */
  RandSrc_GZ_R(&rtb_MathFunction1_c, &Plant_ConstP.pooled19, 1,
               &Plant_ConstP.pooled29, 1, Plant_DW.RandomSource_STATE_DWORK_b, 1,
               1);

  /* BusAssignment: '<S57>/Bus Assignment' incorporates:
   *  Constant: '<S57>/Constant2'
   *  DataTypeConversion: '<S57>/Data Type Conversion1'
   *  Memory: '<S52>/Memory1'
   *  Saturate: '<S59>/Saturation'
   *  Sum: '<S57>/Sum1'
   *  Sum: '<S59>/Add'
   */
  rtb_BusAssignment_i.timestamp = Plant_DW.Memory1_PreviousInput;
  rtb_BusAssignment_i.pressure = rtb_Product11 + rtb_MathFunction1_c;
  rtb_BusAssignment_i.temperature = (real32_T)(rtb_DataTypeConversion_f - 273.15);

  /* RateTransition: '<S57>/Rate Transition' */
  if (Plant_M->Timing.TaskCounters.TID[1] == 0) {
    Plant_B.RateTransition_m = rtb_BusAssignment_i;
  }

  /* End of RateTransition: '<S57>/Rate Transition' */
  /* End of Outputs for SubSystem: '<S5>/Sensor_Baro' */

  /* Outputs for Atomic SubSystem: '<S5>/Sensor_GPS' */
  /* Trigonometry: '<S78>/Trigonometric Function1' incorporates:
   *  Delay: '<S64>/Delay'
   *  Trigonometry: '<S78>/Trigonometric Function2'
   */
  Sum2_idx_1 = cos(Plant_DW.Delay_DSTATE[0]);

  /* Trigonometry: '<S78>/Trigonometric Function' incorporates:
   *  Delay: '<S64>/Delay'
   */
  rtb_SumofElements = sin(Plant_DW.Delay_DSTATE[0]);

  /* Product: '<S78>/Divide' incorporates:
   *  Constant: '<S78>/Constant1'
   *  Constant: '<S78>/Constant3'
   *  Math: '<S78>/u^2'
   *  Product: '<S78>/Product'
   *  Sqrt: '<S78>/sqrt'
   *  Sum: '<S78>/Subtract'
   */
  rtb_SumofElements = 6.378137E+6 / sqrt(1.0 - rtb_SumofElements *
    rtb_SumofElements * Plant_ConstB.e_2);

  /* Sum: '<S78>/Add' incorporates:
   *  Constant: '<S78>/constant2'
   *  Delay: '<S64>/Delay'
   *  Math: '<S78>/u^1'
   *  Product: '<S78>/Product2'
   *  Product: '<S78>/Product3'
   *  Sum: '<S78>/Subtract2'
   *  Trigonometry: '<S78>/Trigonometric Function1'
   */
  rtb_DataTypeConversion_idx_0 = (1.0 - Sum2_idx_1 * Sum2_idx_1 *
    Plant_ConstB.e_2) * rtb_SumofElements + Plant_DW.Delay_DSTATE[2];

  /* Sum: '<S78>/Add1' incorporates:
   *  Delay: '<S64>/Delay'
   */
  rtb_SumofElements += Plant_DW.Delay_DSTATE[2];

  /* S-Function (sdsprandsrc2): '<S69>/Random Source' */
  RandSrc_GZ_R(rtb_RandomSource, &Plant_ConstP.pooled19, 1,
               Plant_ConstP.RandomSource_VarianceRTP, 3,
               Plant_DW.RandomSource_STATE_DWORK_l, 3, 1);

  /* Sum: '<S65>/Sum2' incorporates:
   *  Delay: '<S64>/Delay'
   *  Product: '<S72>/Divide2'
   *  Product: '<S78>/Product4'
   */
  rtb_DataTypeConversion_idx_0 = rtb_RandomSource[0] /
    rtb_DataTypeConversion_idx_0 + Plant_DW.Delay_DSTATE[0];
  Sum2_idx_1 = rtb_RandomSource[1] / (rtb_SumofElements * Sum2_idx_1) +
    Plant_DW.Delay_DSTATE[1];
  rtb_Gain6 = rtb_RandomSource[2] / -1.0 + Plant_DW.Delay_DSTATE[2];

  /* S-Function (sdsprandsrc2): '<S69>/Random Source1' */
  RandSrc_GZ_R(rtb_RandomSource1, &Plant_ConstP.pooled19, 1,
               Plant_ConstP.RandomSource1_VarianceRTP, 3,
               Plant_DW.RandomSource1_STATE_DWORK, 3, 1);

  /* Sum: '<S65>/Sum1' incorporates:
   *  Delay: '<S64>/Delay1'
   */
  rtb_Multiply_g_idx_2 = rtb_RandomSource1[0] + Plant_DW.Delay1_DSTATE_a[0];
  rtb_Multiply_g_idx_0 = rtb_RandomSource1[1] + Plant_DW.Delay1_DSTATE_a[1];
  rtb_Multiply_g_idx_1 = rtb_RandomSource1[2] + Plant_DW.Delay1_DSTATE_a[2];

  /* DiscreteFir: '<S74>/Discrete FIR Filter' */
  rtb_Switch[0] = rtb_Multiply_g_idx_2 * 0.5F +
    Plant_DW.DiscreteFIRFilter_states_f[0] * 0.5F;
  rtb_Switch[1] = rtb_Multiply_g_idx_0 * 0.5F +
    Plant_DW.DiscreteFIRFilter_states_f[1] * 0.5F;

  /* Gain: '<S63>/Gain6' incorporates:
   *  Math: '<S68>/Math Function'
   *  Product: '<S68>/Matrix Multiply'
   *  Sqrt: '<S68>/Sqrt'
   *  Switch: '<S75>/Switch'
   */
  rtb_SumofElements = fmod(floor(sqrtf(rtb_RandomSource[0] * rtb_RandomSource[0]
    + rtb_RandomSource[1] * rtb_RandomSource[1]) * 1000.0), 4.294967296E+9);

  /* Gain: '<S63>/Gain4' incorporates:
   *  DiscreteFir: '<S73>/Discrete FIR Filter'
   */
  rtb_Product1_idx_2 = fmod(floor((rtb_Gain6 * 0.5 +
    Plant_DW.DiscreteFIRFilter_states[2] * 0.5) * 1000.0), 4.294967296E+9);
  i = rtb_Product1_idx_2 < 0.0 ? -(int32_T)(uint32_T)-rtb_Product1_idx_2 :
    (int32_T)(uint32_T)rtb_Product1_idx_2;

  /* Gain: '<S63>/Gain5' incorporates:
   *  Math: '<S68>/Math Function2'
   *  Product: '<S68>/Matrix Multiply2'
   *  Sqrt: '<S68>/Sqrt2'
   *  Switch: '<S76>/Switch'
   */
  rtb_Product1_idx_2 = fmod(floor(sqrtf(rtb_RandomSource[2] * rtb_RandomSource[2])
    * 1000.0), 4.294967296E+9);

  /* BusAssignment: '<S63>/Bus Assignment' incorporates:
   *  Constant: '<S63>/Constant10'
   *  Constant: '<S63>/Constant11'
   *  Constant: '<S63>/Constant12'
   *  Constant: '<S63>/Constant2'
   *  Constant: '<S63>/Constant3'
   *  Constant: '<S63>/Constant4'
   *  Constant: '<S63>/Constant5'
   *  Constant: '<S63>/Constant6'
   *  Constant: '<S63>/Constant7'
   *  Constant: '<S63>/Constant8'
   *  Constant: '<S63>/Constant9'
   */
  rtb_BusAssignment_dk.iTOW = 1U;
  rtb_BusAssignment_dk.year = 2018U;
  rtb_BusAssignment_dk.month = 13U;
  rtb_BusAssignment_dk.day = 32U;
  rtb_BusAssignment_dk.hour = 25U;
  rtb_BusAssignment_dk.min = 61U;
  rtb_BusAssignment_dk.sec = 61U;
  rtb_BusAssignment_dk.valid = 7U;
  rtb_BusAssignment_dk.tAcc = 0U;
  rtb_BusAssignment_dk.nano = 0;
  rtb_BusAssignment_dk.fixType = Plant_ConstB.DataTypeConversion;
  rtb_BusAssignment_dk.flags = 0U;
  rtb_BusAssignment_dk.reserved1 = 0U;
  rtb_BusAssignment_dk.numSV = Plant_ConstB.DataTypeConversion1;

  /* Gain: '<S63>/Gain' incorporates:
   *  DiscreteFir: '<S73>/Discrete FIR Filter'
   *  Gain: '<S63>/Gain2'
   */
  rtb_Product2_f_idx_1 = fmod(floor((rtb_DataTypeConversion_idx_0 * 0.5 +
    Plant_DW.DiscreteFIRFilter_states[0] * 0.5) * 57.295779513082323 * 1.0E+7),
    4.294967296E+9);

  /* BusAssignment: '<S63>/Bus Assignment' incorporates:
   *  Gain: '<S63>/Gain'
   */
  rtb_BusAssignment_dk.lon = rtb_Product2_f_idx_1 < 0.0 ? -(int32_T)(uint32_T)
    -rtb_Product2_f_idx_1 : (int32_T)(uint32_T)rtb_Product2_f_idx_1;

  /* Gain: '<S63>/Gain1' incorporates:
   *  DiscreteFir: '<S73>/Discrete FIR Filter'
   *  Gain: '<S63>/Gain3'
   */
  rtb_Product2_f_idx_1 = fmod(floor((Sum2_idx_1 * 0.5 +
    Plant_DW.DiscreteFIRFilter_states[1] * 0.5) * 57.295779513082323 * 1.0E+7),
    4.294967296E+9);

  /* BusAssignment: '<S63>/Bus Assignment' incorporates:
   *  Gain: '<S63>/Gain1'
   *  Gain: '<S63>/Gain5'
   *  Gain: '<S63>/Gain6'
   */
  rtb_BusAssignment_dk.lat = rtb_Product2_f_idx_1 < 0.0 ? -(int32_T)(uint32_T)
    -rtb_Product2_f_idx_1 : (int32_T)(uint32_T)rtb_Product2_f_idx_1;
  rtb_BusAssignment_dk.height = i;
  rtb_BusAssignment_dk.hMSL = i;
  rtb_BusAssignment_dk.hAcc = rtb_SumofElements < 0.0 ? (uint32_T)-(int32_T)
    (uint32_T)-rtb_SumofElements : (uint32_T)rtb_SumofElements;
  rtb_BusAssignment_dk.vAcc = rtb_Product1_idx_2 < 0.0 ? (uint32_T)-(int32_T)
    (uint32_T)-rtb_Product1_idx_2 : (uint32_T)rtb_Product1_idx_2;

  /* Gain: '<S63>/Gain7' */
  rtb_Gain_h = fmodf(floorf(1000.0F * rtb_Switch[0]), 4.2949673E+9F);

  /* BusAssignment: '<S63>/Bus Assignment' incorporates:
   *  Gain: '<S63>/Gain7'
   */
  rtb_BusAssignment_dk.velN = rtb_Gain_h < 0.0F ? -(int32_T)(uint32_T)
    -rtb_Gain_h : (int32_T)(uint32_T)rtb_Gain_h;

  /* Gain: '<S63>/Gain8' */
  rtb_Gain_h = fmodf(floorf(1000.0F * rtb_Switch[1]), 4.2949673E+9F);

  /* BusAssignment: '<S63>/Bus Assignment' incorporates:
   *  Gain: '<S63>/Gain8'
   */
  rtb_BusAssignment_dk.velE = rtb_Gain_h < 0.0F ? -(int32_T)(uint32_T)
    -rtb_Gain_h : (int32_T)(uint32_T)rtb_Gain_h;

  /* Gain: '<S63>/Gain9' incorporates:
   *  DiscreteFir: '<S74>/Discrete FIR Filter'
   */
  rtb_Gain_h = fmodf(floorf((rtb_Multiply_g_idx_1 * 0.5F +
    Plant_DW.DiscreteFIRFilter_states_f[2] * 0.5F) * 1000.0F), 4.2949673E+9F);

  /* BusAssignment: '<S63>/Bus Assignment' incorporates:
   *  Constant: '<S63>/Constant15'
   *  Gain: '<S63>/Gain11'
   *  Gain: '<S63>/Gain9'
   *  Math: '<S67>/Math Function'
   *  Math: '<S67>/Math Function1'
   *  Saturate: '<S67>/Saturation'
   *  Sqrt: '<S67>/Sqrt'
   *  Sum: '<S67>/Add'
   */
  rtb_BusAssignment_dk.velD = rtb_Gain_h < 0.0F ? -(int32_T)(uint32_T)
    -rtb_Gain_h : (int32_T)(uint32_T)rtb_Gain_h;
  rtb_BusAssignment_dk.gSpeed = (int32_T)(uint32_T)fmodf(floorf(sqrtf(fmaxf
    (rtb_Switch[0] * rtb_Switch[0] + rtb_Switch[1] * rtb_Switch[1], 0.0F)) *
    1000.0F), 4.2949673E+9F);
  rtb_BusAssignment_dk.headMot = 0;

  /* Gain: '<S63>/Gain10' incorporates:
   *  Math: '<S68>/Math Function1'
   *  Product: '<S68>/Matrix Multiply1'
   *  Sqrt: '<S68>/Sqrt1'
   *  Switch: '<S77>/Switch'
   */
  rtb_SumofElements = fmod(floor(sqrtf((rtb_RandomSource1[0] *
    rtb_RandomSource1[0] + rtb_RandomSource1[1] * rtb_RandomSource1[1]) +
    rtb_RandomSource1[2] * rtb_RandomSource1[2]) * 1000.0), 4.294967296E+9);

  /* BusAssignment: '<S63>/Bus Assignment' incorporates:
   *  Constant: '<S63>/Constant14'
   *  Constant: '<S63>/Constant16'
   *  Constant: '<S63>/Constant17'
   *  Gain: '<S63>/Gain10'
   *  Memory: '<S52>/Memory1'
   */
  rtb_BusAssignment_dk.sAcc = rtb_SumofElements < 0.0 ? (uint32_T)-(int32_T)
    (uint32_T)-rtb_SumofElements : (uint32_T)rtb_SumofElements;
  rtb_BusAssignment_dk.headAcc = 0U;
  rtb_BusAssignment_dk.pDOP = 0U;
  rtb_BusAssignment_dk.reserved2 = 0U;
  rtb_BusAssignment_dk.timestamp = Plant_DW.Memory1_PreviousInput;

  /* RateTransition: '<S63>/Rate Transition' */
  if (Plant_M->Timing.TaskCounters.TID[2] == 0) {
    Plant_B.RateTransition = rtb_BusAssignment_dk;
  }

  /* End of RateTransition: '<S63>/Rate Transition' */

  /* Update for Delay: '<S64>/Delay' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S64>/ConcatBufferAtVector ConcatenateIn1'
   */
  for (i = 0; i < 74; i++) {
    rtb_Saturation2 = (i + 1) * 3;
    Plant_DW.Delay_DSTATE[i * 3] = Plant_DW.Delay_DSTATE[rtb_Saturation2];
    Plant_DW.Delay_DSTATE[i * 3 + 1] = Plant_DW.Delay_DSTATE[rtb_Saturation2 + 1];
    Plant_DW.Delay_DSTATE[i * 3 + 2] = Plant_DW.Delay_DSTATE[rtb_Saturation2 + 2];
  }

  /* Update states */
  Plant_DW.Delay_DSTATE[222] = Plant_Y.Plant_States.lon;

  /* Update for DiscreteFir: '<S73>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states[0] = rtb_DataTypeConversion_idx_0;

  /* Update for Delay: '<S64>/Delay' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S64>/ConcatBufferAtVector ConcatenateIn2'
   */
  Plant_DW.Delay_DSTATE[223] = Plant_Y.Plant_States.lat;

  /* Update for DiscreteFir: '<S73>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states[1] = Sum2_idx_1;

  /* Update for Delay: '<S64>/Delay' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S64>/ConcatBufferAtVector ConcatenateIn3'
   */
  Plant_DW.Delay_DSTATE[224] = Plant_Y.Plant_States.alt;

  /* Update for DiscreteFir: '<S73>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states[2] = rtb_Gain6;

  /* Update for Delay: '<S64>/Delay1' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S64>/ConcatBufferAtVector Concatenate1In1'
   */
  for (i = 0; i < 49; i++) {
    rtb_Saturation2 = (i + 1) * 3;
    Plant_DW.Delay1_DSTATE_a[i * 3] = Plant_DW.Delay1_DSTATE_a[rtb_Saturation2];
    Plant_DW.Delay1_DSTATE_a[i * 3 + 1] =
      Plant_DW.Delay1_DSTATE_a[rtb_Saturation2 + 1];
    Plant_DW.Delay1_DSTATE_a[i * 3 + 2] =
      Plant_DW.Delay1_DSTATE_a[rtb_Saturation2 + 2];
  }

  /* Update states */
  Plant_DW.Delay1_DSTATE_a[147] = Plant_Y.Plant_States.vel_x_O;

  /* Update for DiscreteFir: '<S74>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states_f[0] = rtb_Multiply_g_idx_2;

  /* Update for Delay: '<S64>/Delay1' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S64>/ConcatBufferAtVector Concatenate1In2'
   */
  Plant_DW.Delay1_DSTATE_a[148] = Plant_Y.Plant_States.vel_y_O;

  /* Update for DiscreteFir: '<S74>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states_f[1] = rtb_Multiply_g_idx_0;

  /* Update for Delay: '<S64>/Delay1' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S64>/ConcatBufferAtVector Concatenate1In3'
   */
  Plant_DW.Delay1_DSTATE_a[149] = Plant_Y.Plant_States.vel_z_O;

  /* Update for DiscreteFir: '<S74>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states_f[2] = rtb_Multiply_g_idx_1;

  /* End of Outputs for SubSystem: '<S5>/Sensor_GPS' */

  /* Outputs for Atomic SubSystem: '<S5>/Sensor_IMU' */
  /* Outputs for Atomic SubSystem: '<S99>/Vibration_Model' */
  /* Product: '<S106>/Divide2' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_DataTypeConversion_idx_0 = Plant_Y.Extended_States.prop_vel[0] /
    Plant_ConstB.Divide1[0];

  /* Math: '<S106>/u^2' */
  rtb_DataTypeConversion_idx_0 *= rtb_DataTypeConversion_idx_0;

  /* Product: '<S102>/Product2' incorporates:
   *  DiscreteIntegrator: '<S102>/Discrete-Time Integrator'
   *  Trigonometry: '<S102>/Trigonometric Function2'
   */
  rtb_SumofElements = arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[0]) *
    rtb_DataTypeConversion_idx_0;

  /* Product: '<S106>/Divide2' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S102>/Discrete-Time Integrator'
   *  Product: '<S102>/Product1'
   *  Trigonometry: '<S102>/Trigonometric Function1'
   */
  Sum2_idx_1 = arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[0]) *
    rtb_DataTypeConversion_idx_0;
  rtb_DataTypeConversion_idx_0 = Plant_Y.Extended_States.prop_vel[1] /
    Plant_ConstB.Divide1[1];

  /* Math: '<S106>/u^2' */
  rtb_DataTypeConversion_idx_0 *= rtb_DataTypeConversion_idx_0;

  /* Product: '<S102>/Product2' incorporates:
   *  DiscreteIntegrator: '<S102>/Discrete-Time Integrator'
   *  Trigonometry: '<S102>/Trigonometric Function2'
   */
  rtb_Product2_f_idx_1 = arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[1]) *
    rtb_DataTypeConversion_idx_0;

  /* Product: '<S106>/Divide2' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S102>/Discrete-Time Integrator'
   *  Product: '<S102>/Product1'
   *  Trigonometry: '<S102>/Trigonometric Function1'
   */
  rtb_Gain6 = arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[1]) *
    rtb_DataTypeConversion_idx_0;
  rtb_DataTypeConversion_idx_0 = Plant_Y.Extended_States.prop_vel[2] /
    Plant_ConstB.Divide1[2];

  /* Math: '<S106>/u^2' */
  rtb_DataTypeConversion_idx_0 *= rtb_DataTypeConversion_idx_0;

  /* Product: '<S102>/Product2' incorporates:
   *  DiscreteIntegrator: '<S102>/Discrete-Time Integrator'
   *  Trigonometry: '<S102>/Trigonometric Function2'
   */
  rtb_Product2_f_idx_2 = arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[2]) *
    rtb_DataTypeConversion_idx_0;

  /* Product: '<S106>/Divide2' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S102>/Discrete-Time Integrator'
   *  Product: '<S102>/Product1'
   *  Trigonometry: '<S102>/Trigonometric Function1'
   */
  rtb_Product1_idx_2 = arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[2]) *
    rtb_DataTypeConversion_idx_0;
  rtb_DataTypeConversion_idx_0 = Plant_Y.Extended_States.prop_vel[3] /
    Plant_ConstB.Divide1[3];

  /* Math: '<S106>/u^2' */
  rtb_DataTypeConversion_idx_0 *= rtb_DataTypeConversion_idx_0;

  /* Product: '<S102>/Product2' incorporates:
   *  DiscreteIntegrator: '<S102>/Discrete-Time Integrator'
   *  Trigonometry: '<S102>/Trigonometric Function2'
   */
  rtb_Product2_f_idx_3 = arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[3]) *
    rtb_DataTypeConversion_idx_0;

  /* Product: '<S102>/Product1' incorporates:
   *  DiscreteIntegrator: '<S102>/Discrete-Time Integrator'
   *  Trigonometry: '<S102>/Trigonometric Function1'
   */
  rtb_DataTypeConversion_idx_0 *= arm_cos_f32
    (Plant_DW.DiscreteTimeIntegrator_DSTATE[3]);

  /* Sum: '<S102>/Sum of Elements' */
  rtb_SumofElements = ((rtb_SumofElements + rtb_Product2_f_idx_1) +
                       rtb_Product2_f_idx_2) + rtb_Product2_f_idx_3;

  /* Sum: '<S102>/Sum of Elements1' */
  rtb_Product1_idx_2 = ((Sum2_idx_1 + rtb_Gain6) + rtb_Product1_idx_2) +
    rtb_DataTypeConversion_idx_0;

  /* Outputs for Atomic SubSystem: '<S83>/Vibration_Model' */
  /* Update for DiscreteIntegrator: '<S102>/Discrete-Time Integrator' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S87>/Discrete-Time Integrator'
   */
  rtb_vel_O_mDs_idx_2 = 0.002F * Plant_Y.Extended_States.prop_vel[0];

  /* End of Outputs for SubSystem: '<S83>/Vibration_Model' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE[0] += rtb_vel_O_mDs_idx_2;

  /* End of Outputs for SubSystem: '<S99>/Vibration_Model' */
  /* End of Outputs for SubSystem: '<S5>/Sensor_IMU' */
  /* End of Outputs for SubSystem: '<Root>/Sensor_Model' */
  rtb_Product11 = rtb_vel_O_mDs_idx_2;

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_Model' */
  /* Outputs for Atomic SubSystem: '<S5>/Sensor_IMU' */
  /* Outputs for Atomic SubSystem: '<S83>/Vibration_Model' */
  /* Outputs for Atomic SubSystem: '<S99>/Vibration_Model' */
  /* Update for DiscreteIntegrator: '<S102>/Discrete-Time Integrator' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S87>/Discrete-Time Integrator'
   */
  rtb_vel_O_mDs_idx_2 = 0.002F * Plant_Y.Extended_States.prop_vel[1];

  /* End of Outputs for SubSystem: '<S83>/Vibration_Model' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE[1] += rtb_vel_O_mDs_idx_2;

  /* End of Outputs for SubSystem: '<S99>/Vibration_Model' */
  /* End of Outputs for SubSystem: '<S5>/Sensor_IMU' */
  /* End of Outputs for SubSystem: '<Root>/Sensor_Model' */
  DiscreteFilter_tmp_idx_1 = rtb_vel_O_mDs_idx_2;

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_Model' */
  /* Outputs for Atomic SubSystem: '<S5>/Sensor_IMU' */
  /* Outputs for Atomic SubSystem: '<S83>/Vibration_Model' */
  /* Outputs for Atomic SubSystem: '<S99>/Vibration_Model' */
  /* Update for DiscreteIntegrator: '<S102>/Discrete-Time Integrator' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S87>/Discrete-Time Integrator'
   */
  rtb_vel_O_mDs_idx_2 = 0.002F * Plant_Y.Extended_States.prop_vel[2];

  /* End of Outputs for SubSystem: '<S83>/Vibration_Model' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE[2] += rtb_vel_O_mDs_idx_2;

  /* End of Outputs for SubSystem: '<S99>/Vibration_Model' */
  /* End of Outputs for SubSystem: '<S5>/Sensor_IMU' */
  /* End of Outputs for SubSystem: '<Root>/Sensor_Model' */
  DiscreteFilter_tmp_idx_2 = rtb_vel_O_mDs_idx_2;

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_Model' */
  /* Outputs for Atomic SubSystem: '<S5>/Sensor_IMU' */
  /* Outputs for Atomic SubSystem: '<S83>/Vibration_Model' */
  /* Outputs for Atomic SubSystem: '<S99>/Vibration_Model' */
  /* Update for DiscreteIntegrator: '<S102>/Discrete-Time Integrator' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S87>/Discrete-Time Integrator'
   */
  rtb_vel_O_mDs_idx_2 = 0.002F * Plant_Y.Extended_States.prop_vel[3];

  /* End of Outputs for SubSystem: '<S83>/Vibration_Model' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE[3] += rtb_vel_O_mDs_idx_2;

  /* Switch: '<S101>/Switch' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S102>/Gain2'
   *  Gain: '<S102>/Gain4'
   *  Product: '<S102>/Divide'
   *  SignalConversion: '<S104>/ConcatBufferAtVector ConcatenateIn1'
   *  SignalConversion: '<S104>/ConcatBufferAtVector ConcatenateIn2'
   *  SignalConversion: '<S104>/ConcatBufferAtVector ConcatenateIn3'
   *  Sum: '<S102>/Add'
   *  Sum: '<S102>/Sum of Elements'
   *  Sum: '<S102>/Sum of Elements1'
   *  Sum: '<S99>/Sum'
   */
  rtb_VectorConcatenate_d[0] = (real32_T)(rtb_SumofElements / 4.0 * 0.5 +
    Plant_Y.Plant_States.rot_x_B);
  rtb_VectorConcatenate_d[1] = (real32_T)(rtb_Product1_idx_2 / 4.0 * 0.5 +
    Plant_Y.Plant_States.rot_y_B);
  rtb_Square_n_idx_0 = (real32_T)((rtb_SumofElements + rtb_Product1_idx_2) * 0.5
    / 4.0 * 0.5 + Plant_Y.Plant_States.rot_z_B);

  /* End of Outputs for SubSystem: '<S99>/Vibration_Model' */

  /* Sum: '<S107>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S107>/integrate'
   *  DiscreteIntegrator: '<S107>/integrate1'
   */
  rtb_RandomSource[0] = Plant_DW.integrate_DSTATE[0] -
    Plant_DW.integrate1_DSTATE[0];
  rtb_RandomSource[1] = Plant_DW.integrate_DSTATE[1] -
    Plant_DW.integrate1_DSTATE[1];
  rtb_RandomSource[2] = Plant_DW.integrate_DSTATE[2] -
    Plant_DW.integrate1_DSTATE[2];

  /* S-Function (sdsprandsrc2): '<S93>/Random Source' */
  RandSrc_GZ_R(rtb_integrate, &Plant_ConstP.pooled19, 1,
               Plant_ConstP.RandomSource_VarianceRTP_f, 3,
               Plant_DW.RandomSource_STATE_DWORK_k, 3, 1);

  /* S-Function (sdsprandsrc2): '<S110>/Random Source' */
  RandSrc_GZ_R(rtb_integrate1, &Plant_ConstP.pooled19, 1,
               Plant_ConstP.RandomSource_VarianceRTP_b, 3,
               Plant_DW.RandomSource_STATE_DWORK_h, 3, 1);

  /* Saturate: '<S84>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S90>/integrate1'
   */
  if (Plant_DW.integrate1_DSTATE_g[0] > 78.4532F) {
    rtb_Square_n_idx_1 = 78.4532F;
  } else if (Plant_DW.integrate1_DSTATE_g[0] < -78.4532F) {
    rtb_Square_n_idx_1 = -78.4532F;
  } else {
    rtb_Square_n_idx_1 = Plant_DW.integrate1_DSTATE_g[0];
  }

  /* Saturate: '<S100>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S107>/integrate1'
   */
  if (Plant_DW.integrate1_DSTATE[0] > 34.9065857F) {
    rtb_Gain_h = 34.9065857F;
  } else if (Plant_DW.integrate1_DSTATE[0] < -34.9065857F) {
    rtb_Gain_h = -34.9065857F;
  } else {
    rtb_Gain_h = Plant_DW.integrate1_DSTATE[0];
  }

  /* Sum: '<S100>/Sum' incorporates:
   *  DiscreteIntegrator: '<S107>/integrate1'
   */
  rtb_integrate1[0] += rtb_Gain_h;

  /* Saturate: '<S84>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S90>/integrate1'
   */
  if (Plant_DW.integrate1_DSTATE_g[1] > 78.4532F) {
    rtb_Square_n_idx_2 = 78.4532F;
  } else if (Plant_DW.integrate1_DSTATE_g[1] < -78.4532F) {
    rtb_Square_n_idx_2 = -78.4532F;
  } else {
    rtb_Square_n_idx_2 = Plant_DW.integrate1_DSTATE_g[1];
  }

  /* Saturate: '<S100>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S107>/integrate1'
   */
  if (Plant_DW.integrate1_DSTATE[1] > 34.9065857F) {
    rtb_Gain_h = 34.9065857F;
  } else if (Plant_DW.integrate1_DSTATE[1] < -34.9065857F) {
    rtb_Gain_h = -34.9065857F;
  } else {
    rtb_Gain_h = Plant_DW.integrate1_DSTATE[1];
  }

  /* Sum: '<S100>/Sum' incorporates:
   *  DiscreteIntegrator: '<S107>/integrate1'
   */
  rtb_integrate1[1] += rtb_Gain_h;

  /* DiscreteIntegrator: '<S107>/integrate1' */
  denAccum = Plant_DW.integrate1_DSTATE[2];

  /* Saturate: '<S84>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S90>/integrate1'
   */
  if (Plant_DW.integrate1_DSTATE_g[2] > 78.4532F) {
    rtb_vel_O_mDs_idx_0 = 78.4532F;
  } else if (Plant_DW.integrate1_DSTATE_g[2] < -78.4532F) {
    rtb_vel_O_mDs_idx_0 = -78.4532F;
  } else {
    rtb_vel_O_mDs_idx_0 = Plant_DW.integrate1_DSTATE_g[2];
  }

  /* Outputs for Atomic SubSystem: '<S83>/Vibration_Model' */
  /* Product: '<S87>/Divide2' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_DataTypeConversion_idx_0 = Plant_Y.Extended_States.prop_vel[0] /
    Plant_ConstB.Divide1_f[0];

  /* Math: '<S87>/u^2' */
  rtb_DataTypeConversion_idx_0 *= rtb_DataTypeConversion_idx_0;

  /* Product: '<S87>/Product2' incorporates:
   *  DiscreteIntegrator: '<S87>/Discrete-Time Integrator'
   *  Trigonometry: '<S87>/Trigonometric Function2'
   */
  rtb_SumofElements = arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_p[0]) *
    rtb_DataTypeConversion_idx_0;

  /* Product: '<S87>/Divide2' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S87>/Discrete-Time Integrator'
   *  Product: '<S87>/Product1'
   *  Trigonometry: '<S87>/Trigonometric Function1'
   */
  Sum2_idx_1 = arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_p[0]) *
    rtb_DataTypeConversion_idx_0;
  rtb_DataTypeConversion_idx_0 = Plant_Y.Extended_States.prop_vel[1] /
    Plant_ConstB.Divide1_f[1];

  /* Math: '<S87>/u^2' */
  rtb_DataTypeConversion_idx_0 *= rtb_DataTypeConversion_idx_0;

  /* Product: '<S87>/Product2' incorporates:
   *  DiscreteIntegrator: '<S87>/Discrete-Time Integrator'
   *  Trigonometry: '<S87>/Trigonometric Function2'
   */
  rtb_Product2_f_idx_1 = arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_p[1])
    * rtb_DataTypeConversion_idx_0;

  /* Product: '<S87>/Divide2' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S87>/Discrete-Time Integrator'
   *  Product: '<S87>/Product1'
   *  Trigonometry: '<S87>/Trigonometric Function1'
   */
  rtb_Gain6 = arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_p[1]) *
    rtb_DataTypeConversion_idx_0;
  rtb_DataTypeConversion_idx_0 = Plant_Y.Extended_States.prop_vel[2] /
    Plant_ConstB.Divide1_f[2];

  /* Math: '<S87>/u^2' */
  rtb_DataTypeConversion_idx_0 *= rtb_DataTypeConversion_idx_0;

  /* Product: '<S87>/Product2' incorporates:
   *  DiscreteIntegrator: '<S87>/Discrete-Time Integrator'
   *  Trigonometry: '<S87>/Trigonometric Function2'
   */
  rtb_Product2_f_idx_2 = arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_p[2])
    * rtb_DataTypeConversion_idx_0;

  /* Product: '<S87>/Divide2' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S87>/Discrete-Time Integrator'
   *  Product: '<S87>/Product1'
   *  Trigonometry: '<S87>/Trigonometric Function1'
   */
  rtb_Product1_idx_2 = arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_p[2]) *
    rtb_DataTypeConversion_idx_0;
  rtb_DataTypeConversion_idx_0 = Plant_Y.Extended_States.prop_vel[3] /
    Plant_ConstB.Divide1_f[3];

  /* Math: '<S87>/u^2' */
  rtb_DataTypeConversion_idx_0 *= rtb_DataTypeConversion_idx_0;

  /* Product: '<S87>/Product2' incorporates:
   *  DiscreteIntegrator: '<S87>/Discrete-Time Integrator'
   *  Trigonometry: '<S87>/Trigonometric Function2'
   */
  rtb_Product2_f_idx_3 = arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_p[3])
    * rtb_DataTypeConversion_idx_0;

  /* Product: '<S87>/Product1' incorporates:
   *  DiscreteIntegrator: '<S87>/Discrete-Time Integrator'
   *  Trigonometry: '<S87>/Trigonometric Function1'
   */
  rtb_DataTypeConversion_idx_0 *= arm_cos_f32
    (Plant_DW.DiscreteTimeIntegrator_DSTATE_p[3]);

  /* Sum: '<S87>/Sum of Elements' */
  rtb_SumofElements = ((rtb_SumofElements + rtb_Product2_f_idx_1) +
                       rtb_Product2_f_idx_2) + rtb_Product2_f_idx_3;

  /* SignalConversion: '<S87>/ConcatBufferAtVector ConcatenateIn1' incorporates:
   *  Sum: '<S87>/Sum of Elements'
   */
  rtb_Divide2[0] = rtb_SumofElements;

  /* Sum: '<S87>/Sum of Elements1' */
  rtb_Product1_idx_2 = ((Sum2_idx_1 + rtb_Gain6) + rtb_Product1_idx_2) +
    rtb_DataTypeConversion_idx_0;

  /* SignalConversion: '<S87>/ConcatBufferAtVector ConcatenateIn2' incorporates:
   *  Sum: '<S87>/Sum of Elements1'
   */
  rtb_Divide2[1] = rtb_Product1_idx_2;

  /* Gain: '<S87>/Gain2' incorporates:
   *  Sum: '<S87>/Add'
   *  Sum: '<S87>/Sum of Elements'
   *  Sum: '<S87>/Sum of Elements1'
   */
  rtb_Divide2[2] = (rtb_SumofElements + rtb_Product1_idx_2) * 0.5;

  /* Update for DiscreteIntegrator: '<S87>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_p[0] += rtb_Product11;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_p[1] += DiscreteFilter_tmp_idx_1;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_p[2] += DiscreteFilter_tmp_idx_2;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_p[3] += rtb_vel_O_mDs_idx_2;

  /* End of Outputs for SubSystem: '<S83>/Vibration_Model' */

  /* Switch: '<S85>/Switch' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S87>/Gain4'
   *  Product: '<S86>/Product1'
   *  Product: '<S87>/Divide'
   *  SignalConversion: '<S86>/ConcatBufferAtVector Concatenate1In1'
   *  SignalConversion: '<S86>/ConcatBufferAtVector Concatenate1In2'
   *  SignalConversion: '<S86>/ConcatBufferAtVector Concatenate1In3'
   *  Sum: '<S83>/Sum1'
   *  Sum: '<S86>/Sum'
   */
  for (i = 0; i < 3; i++) {
    /* Outputs for Atomic SubSystem: '<S83>/Vibration_Model' */
    rtb_Switch[i] = (real32_T)(((Plant_Y.Extended_States.M_BO[i + 3] *
      Plant_Y.Plant_States.acc_y_O + Plant_Y.Extended_States.M_BO[i] *
      Plant_Y.Plant_States.acc_x_O) + Plant_Y.Extended_States.M_BO[i + 6] *
      (Plant_Y.Plant_States.acc_z_O - 9.80665F)) + rtb_Divide2[i] / 4.0 *
      Plant_ConstP.Gain4_Gain[i]);

    /* End of Outputs for SubSystem: '<S83>/Vibration_Model' */
  }

  /* End of Switch: '<S85>/Switch' */

  /* Outport: '<Root>/IMU' incorporates:
   *  BusAssignment: '<S80>/Bus Assignment'
   *  Memory: '<S52>/Memory1'
   */
  Plant_Y.IMU.timestamp = Plant_DW.Memory1_PreviousInput;

  /* End of Outputs for SubSystem: '<S5>/Sensor_IMU' */

  /* Outputs for Atomic SubSystem: '<S5>/Sensor_MAG' */
  /* DataTypeConversion: '<S117>/Data Type Conversion1' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S117>/Gain'
   */
  rtb_SumofElements = fmod(trunc(5.7295779513082321 * Plant_Y.Plant_States.lat),
    4.294967296E+9);

  /* Sum: '<S117>/Sum' incorporates:
   *  Constant: '<S117>/offset_lat'
   *  DataTypeConversion: '<S117>/Data Type Conversion1'
   */
  i = (rtb_SumofElements < 0.0 ? -(int32_T)(uint32_T)-rtb_SumofElements :
       (int32_T)(uint32_T)rtb_SumofElements) + 8;

  /* Saturate: '<S117>/Saturation1' */
  if (i > 16) {
    i = 16;
  } else {
    if (i < 0) {
      i = 0;
    }
  }

  /* End of Saturate: '<S117>/Saturation1' */

  /* DataTypeConversion: '<S117>/Data Type Conversion2' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S117>/Gain6'
   */
  rtb_SumofElements = fmod(trunc(5.7295779513082321 * Plant_Y.Plant_States.lon),
    4.294967296E+9);

  /* Sum: '<S117>/Sum1' incorporates:
   *  Constant: '<S117>/offset_lon'
   *  DataTypeConversion: '<S117>/Data Type Conversion2'
   */
  rtb_Saturation2 = (rtb_SumofElements < 0.0 ? -(int32_T)(uint32_T)
                     -rtb_SumofElements : (int32_T)(uint32_T)rtb_SumofElements)
    + 18;

  /* Saturate: '<S117>/Saturation2' */
  if (rtb_Saturation2 > 36) {
    rtb_Saturation2 = 36;
  } else {
    if (rtb_Saturation2 < 0) {
      rtb_Saturation2 = 0;
    }
  }

  /* End of Saturate: '<S117>/Saturation2' */

  /* LookupNDDirect: '<S117>/Declination Lookup' incorporates:
   *  LookupNDDirect: '<S117>/Inclination Lookup'
   *  LookupNDDirect: '<S117>/Magnitude Lookup'
   *
   * About '<S117>/Declination Lookup':
   *  2-dimensional Direct Look-Up returning a Scalar,
   *
   * About '<S117>/Inclination Lookup':
   *  2-dimensional Direct Look-Up returning a Scalar,
   *
   * About '<S117>/Magnitude Lookup':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  i += rtb_Saturation2 * 17;

  /* Gain: '<S116>/Gain1' incorporates:
   *  DataTypeConversion: '<S117>/Data Type Conversion3'
   *  LookupNDDirect: '<S117>/Declination Lookup'
   *
   * About '<S117>/Declination Lookup':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  rtb_DataTypeConversion_f = (real32_T)Plant_ConstP.DeclinationLookup_table[i] *
    0.0174532924F;

  /* Trigonometry: '<S119>/Trigonometric Function1' incorporates:
   *  Trigonometry: '<S119>/Trigonometric Function3'
   */
  rtb_Sum_eh_tmp_2 = arm_cos_f32(rtb_DataTypeConversion_f);
  rtb_VectorConcatenate_jq[0] = rtb_Sum_eh_tmp_2;

  /* Trigonometry: '<S119>/Trigonometric Function' incorporates:
   *  Trigonometry: '<S119>/Trigonometric Function2'
   */
  rtb_Multiply_g_idx_0 = arm_sin_f32(rtb_DataTypeConversion_f);
  rtb_VectorConcatenate_jq[1] = rtb_Multiply_g_idx_0;

  /* SignalConversion: '<S119>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S119>/Constant3'
   */
  rtb_VectorConcatenate_jq[2] = 0.0F;

  /* Gain: '<S119>/Gain' */
  rtb_VectorConcatenate_jq[3] = -rtb_Multiply_g_idx_0;

  /* Trigonometry: '<S119>/Trigonometric Function3' */
  rtb_VectorConcatenate_jq[4] = rtb_Sum_eh_tmp_2;

  /* SignalConversion: '<S119>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S119>/Constant4'
   */
  rtb_VectorConcatenate_jq[5] = 0.0F;

  /* Gain: '<S116>/Gain' incorporates:
   *  DataTypeConversion: '<S117>/Data Type Conversion4'
   *  LookupNDDirect: '<S117>/Inclination Lookup'
   *
   * About '<S117>/Inclination Lookup':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  rtb_DataTypeConversion_f = (real32_T)Plant_ConstP.InclinationLookup_table[i] *
    -0.0174532924F;

  /* Trigonometry: '<S118>/Trigonometric Function1' incorporates:
   *  Trigonometry: '<S118>/Trigonometric Function3'
   */
  rtb_Product11 = arm_cos_f32(rtb_DataTypeConversion_f);
  rtb_VectorConcatenate_m[0] = rtb_Product11;

  /* SignalConversion: '<S118>/ConcatBufferAtVector Concatenate1In2' incorporates:
   *  Constant: '<S118>/Constant3'
   */
  rtb_VectorConcatenate_m[1] = 0.0F;

  /* Trigonometry: '<S118>/Trigonometric Function' incorporates:
   *  Trigonometry: '<S118>/Trigonometric Function2'
   */
  DiscreteFilter_tmp_idx_1 = arm_sin_f32(rtb_DataTypeConversion_f);

  /* Gain: '<S118>/Gain1' incorporates:
   *  Trigonometry: '<S118>/Trigonometric Function'
   */
  rtb_VectorConcatenate_m[2] = -DiscreteFilter_tmp_idx_1;

  /* Trigonometry: '<S118>/Trigonometric Function2' */
  rtb_VectorConcatenate_m[6] = DiscreteFilter_tmp_idx_1;

  /* SignalConversion: '<S118>/ConcatBufferAtVector Concatenate2In2' incorporates:
   *  Constant: '<S118>/Constant4'
   */
  rtb_VectorConcatenate_m[7] = 0.0F;

  /* Trigonometry: '<S118>/Trigonometric Function3' */
  rtb_VectorConcatenate_m[8] = rtb_Product11;

  /* Gain: '<S116>/Gain2' incorporates:
   *  DataTypeConversion: '<S117>/Data Type Conversion'
   *  LookupNDDirect: '<S117>/Magnitude Lookup'
   *
   * About '<S117>/Magnitude Lookup':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  rtb_Product11 = (real32_T)Plant_ConstP.MagnitudeLookup_table[i] * 0.01F;

  /* Outputs for Atomic SubSystem: '<S5>/Sensor_IMU' */
  for (i = 0; i < 3; i++) {
    /* Update for DiscreteIntegrator: '<S107>/integrate' incorporates:
     *  Constant: '<S107>/Constant'
     *  Product: '<S107>/Product'
     *  Product: '<S109>/Product'
     *  Sum: '<S107>/Sum'
     */
    Plant_DW.integrate_DSTATE[i] += (((Plant_ConstB.Add_g[i + 3] *
      rtb_VectorConcatenate_d[1] + Plant_ConstB.Add_g[i] *
      rtb_VectorConcatenate_d[0]) + Plant_ConstB.Add_g[i + 6] *
      rtb_Square_n_idx_0) - Plant_DW.integrate_DSTATE[i]) * 314.159271F * 0.002F;

    /* Update for DiscreteIntegrator: '<S107>/integrate1' incorporates:
     *  Constant: '<S107>/Constant'
     *  Product: '<S107>/Product1'
     */
    Plant_DW.integrate1_DSTATE[i] += 314.159271F * rtb_RandomSource[i] * 0.002F;

    /* Update for DiscreteIntegrator: '<S90>/integrate1' incorporates:
     *  Constant: '<S90>/Constant'
     *  DiscreteIntegrator: '<S90>/integrate'
     *  Product: '<S90>/Product1'
     *  Sum: '<S90>/Sum1'
     */
    Plant_DW.integrate1_DSTATE_g[i] += (Plant_DW.integrate_DSTATE_k[i] -
      Plant_DW.integrate1_DSTATE_g[i]) * 314.159271F * 0.002F;

    /* Update for DiscreteIntegrator: '<S90>/integrate' incorporates:
     *  Constant: '<S90>/Constant'
     *  Product: '<S90>/Product'
     *  Product: '<S92>/Product'
     *  Sum: '<S90>/Sum'
     */
    Plant_DW.integrate_DSTATE_k[i] += (((Plant_ConstB.Add_m[i + 3] * rtb_Switch
      [1] + Plant_ConstB.Add_m[i] * rtb_Switch[0]) + Plant_ConstB.Add_m[i + 6] *
      rtb_Switch[2]) - Plant_DW.integrate_DSTATE_k[i]) * 314.159271F * 0.002F;

    /* SignalConversion: '<S119>/ConcatBufferAtVector ConcatenateIn3' */
    rtb_VectorConcatenate_jq[i + 6] = Plant_ConstB.VectorConcatenate3[i];

    /* SignalConversion: '<S118>/ConcatBufferAtVector ConcatenateIn2' */
    rtb_VectorConcatenate_m[i + 3] = Plant_ConstB.VectorConcatenate3_l[i];

    /* Product: '<S116>/Multiply1' incorporates:
     *  Product: '<S116>/Multiply'
     */
    rtb_VectorConcatenate_b5[i] = rtb_VectorConcatenate_m[i] * rtb_Product11;
  }

  /* End of Outputs for SubSystem: '<S5>/Sensor_IMU' */

  /* Product: '<S116>/Multiply2' */
  for (i = 0; i < 3; i++) {
    rtb_Add_la[i] = rtb_VectorConcatenate_jq[i + 6] * rtb_VectorConcatenate_b5[2]
      + (rtb_VectorConcatenate_jq[i + 3] * rtb_VectorConcatenate_b5[1] +
         rtb_VectorConcatenate_jq[i] * rtb_VectorConcatenate_b5[0]);
  }

  /* End of Product: '<S116>/Multiply2' */

  /* Product: '<S114>/Product' incorporates:
   *  Delay: '<Root>/Delay'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_d[i] = Plant_Y.Extended_States.M_BO[i + 6] *
      rtb_Add_la[2] + (Plant_Y.Extended_States.M_BO[i + 3] * rtb_Add_la[1] +
                       Plant_Y.Extended_States.M_BO[i] * rtb_Add_la[0]);
  }

  /* End of Product: '<S114>/Product' */
  for (i = 0; i < 3; i++) {
    /* Sum: '<S121>/Sum' incorporates:
     *  Product: '<S121>/Product'
     */
    rtb_Gain_h = (Plant_ConstB.Add[i + 3] * rtb_VectorConcatenate_d[1] +
                  Plant_ConstB.Add[i] * rtb_VectorConcatenate_d[0]) +
      Plant_ConstB.Add[i + 6] * rtb_VectorConcatenate_d[2];

    /* Saturate: '<S115>/Saturation' incorporates:
     *  Sum: '<S121>/Sum'
     */
    if (rtb_Gain_h > 4.0F) {
      rtb_Add_la[i] = 4.0F;
    } else if (rtb_Gain_h < -4.0F) {
      rtb_Add_la[i] = -4.0F;
    } else {
      rtb_Add_la[i] = rtb_Gain_h;
    }

    /* End of Saturate: '<S115>/Saturation' */
  }

  /* S-Function (sdsprandsrc2): '<S122>/Random Source' */
  RandSrc_GZ_R(rtb_VectorConcatenate_d, &Plant_ConstP.pooled19, 1,
               Plant_ConstP.RandomSource_VarianceRTP_a, 3,
               Plant_DW.RandomSource_STATE_DWORK, 3, 1);

  /* Sum: '<S115>/Add' */
  rtb_Add_la[0] += rtb_VectorConcatenate_d[0];
  rtb_Add_la[1] += rtb_VectorConcatenate_d[1];

  /* BusAssignment: '<S111>/Bus Assignment' incorporates:
   *  Memory: '<S52>/Memory1'
   *  Sum: '<S115>/Add'
   */
  rtb_BusAssignment_o.timestamp = Plant_DW.Memory1_PreviousInput;
  rtb_BusAssignment_o.mag_x = rtb_Add_la[0];
  rtb_BusAssignment_o.mag_y = rtb_Add_la[1];
  rtb_BusAssignment_o.mag_z = rtb_Add_la[2] + rtb_VectorConcatenate_d[2];

  /* RateTransition: '<S111>/Rate Transition' */
  if (Plant_M->Timing.TaskCounters.TID[1] == 0) {
    Plant_B.RateTransition_b = rtb_BusAssignment_o;
  }

  /* End of RateTransition: '<S111>/Rate Transition' */
  /* End of Outputs for SubSystem: '<S5>/Sensor_MAG' */

  /* Update for Memory: '<S52>/Memory1' incorporates:
   *  Constant: '<S52>/dt'
   *  Sum: '<S52>/Sum'
   */
  Plant_DW.Memory1_PreviousInput += PLANT_EXPORT.period;

  /* Outputs for Atomic SubSystem: '<S5>/Sensor_IMU' */
  /* Outport: '<Root>/IMU' incorporates:
   *  BusAssignment: '<S80>/Bus Assignment'
   */
  Plant_Y.IMU.gyr_x = rtb_integrate1[0];
  Plant_Y.IMU.gyr_y = rtb_integrate1[1];

  /* Saturate: '<S100>/Saturation' */
  if (denAccum > 34.9065857F) {
    denAccum = 34.9065857F;
  } else {
    if (denAccum < -34.9065857F) {
      denAccum = -34.9065857F;
    }
  }

  /* Outport: '<Root>/IMU' incorporates:
   *  DiscreteIntegrator: '<S107>/integrate1'
   *  Sum: '<S100>/Sum'
   *  Sum: '<S84>/Sum'
   */
  Plant_Y.IMU.gyr_z = denAccum + rtb_integrate1[2];
  Plant_Y.IMU.acc_x = rtb_Square_n_idx_1 + rtb_integrate[0];
  Plant_Y.IMU.acc_y = rtb_Square_n_idx_2 + rtb_integrate[1];
  Plant_Y.IMU.acc_z = rtb_vel_O_mDs_idx_0 + rtb_integrate[2];

  /* End of Outputs for SubSystem: '<S5>/Sensor_IMU' */
  /* End of Outputs for SubSystem: '<Root>/Sensor_Model' */
  if (Plant_M->Timing.TaskCounters.TID[1] == 0) {
    /* Outport: '<Root>/MAG' */
    Plant_Y.MAG = Plant_B.RateTransition_b;

    /* Outport: '<Root>/Barometer' */
    Plant_Y.Barometer = Plant_B.RateTransition_m;
  }

  if (Plant_M->Timing.TaskCounters.TID[2] == 0) {
    /* Outport: '<Root>/GPS_uBlox' */
    Plant_Y.GPS_uBlox = Plant_B.RateTransition;
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
    uint32_T RandomSource_SEED_DWORK_k;

    /* SystemInitialize for Atomic SubSystem: '<Root>/Kinematic_Equation' */
    /* InitializeConditions for DiscreteIntegrator: '<S36>/Discrete-Time Integrator' */
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[0] = Plant_ConstB.Constant1[0];
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[1] = Plant_ConstB.Constant1[1];
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[2] = Plant_ConstB.Constant1[2];
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[3] = Plant_ConstB.Constant1[3];
    Plant_DW.DiscreteTimeIntegrator_PrevRese = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S34>/Discrete-Time Integrator' */
    Plant_DW.DiscreteTimeIntegrator_PrevRe_d = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S35>/Discrete-Time Integrator' */
    Plant_DW.DiscreteTimeIntegrator_PrevRe_k = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S35>/Discrete-Time Integrator1' */
    Plant_DW.DiscreteTimeIntegrator1_PrevRes = 0;

    /* End of SystemInitialize for SubSystem: '<Root>/Kinematic_Equation' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Sensor_Model' */
    /* SystemInitialize for Atomic SubSystem: '<S5>/Sensor_Baro' */
    /* InitializeConditions for S-Function (sdsprandsrc2): '<S59>/Random Source' */
    RandomSource_SEED_DWORK_k = 91337U;
    RandSrcInitState_GZ(&RandomSource_SEED_DWORK_k,
                        Plant_DW.RandomSource_STATE_DWORK_b, 1);

    /* End of SystemInitialize for SubSystem: '<S5>/Sensor_Baro' */

    /* SystemInitialize for Atomic SubSystem: '<S5>/Sensor_GPS' */
    /* InitializeConditions for S-Function (sdsprandsrc2): '<S69>/Random Source' */
    RandSrcCreateSeeds_32(63235U, Plant_DW.RandomSource_SEED_DWORK_m, 3);
    RandSrcInitState_GZ(Plant_DW.RandomSource_SEED_DWORK_m,
                        Plant_DW.RandomSource_STATE_DWORK_l, 3);

    /* InitializeConditions for DiscreteFir: '<S73>/Discrete FIR Filter' */
    Plant_DW.DiscreteFIRFilter_states[0] = 0.0;
    Plant_DW.DiscreteFIRFilter_states[1] = 0.0;
    Plant_DW.DiscreteFIRFilter_states[2] = 0.0;

    /* InitializeConditions for S-Function (sdsprandsrc2): '<S69>/Random Source1' */
    RandSrcCreateSeeds_32(9754U, Plant_DW.RandomSource1_SEED_DWORK, 3);
    RandSrcInitState_GZ(Plant_DW.RandomSource1_SEED_DWORK,
                        Plant_DW.RandomSource1_STATE_DWORK, 3);

    /* InitializeConditions for DiscreteFir: '<S74>/Discrete FIR Filter' */
    Plant_DW.DiscreteFIRFilter_states_f[0] = 0.0F;
    Plant_DW.DiscreteFIRFilter_states_f[1] = 0.0F;
    Plant_DW.DiscreteFIRFilter_states_f[2] = 0.0F;

    /* End of SystemInitialize for SubSystem: '<S5>/Sensor_GPS' */

    /* SystemInitialize for Atomic SubSystem: '<S5>/Sensor_IMU' */
    /* InitializeConditions for S-Function (sdsprandsrc2): '<S93>/Random Source' */
    RandSrcCreateSeeds_32(90579U, Plant_DW.RandomSource_SEED_DWORK_f, 3);
    RandSrcInitState_GZ(Plant_DW.RandomSource_SEED_DWORK_f,
                        Plant_DW.RandomSource_STATE_DWORK_k, 3);

    /* InitializeConditions for S-Function (sdsprandsrc2): '<S110>/Random Source' */
    RandSrcCreateSeeds_32(81472U, Plant_DW.RandomSource_SEED_DWORK_n, 3);
    RandSrcInitState_GZ(Plant_DW.RandomSource_SEED_DWORK_n,
                        Plant_DW.RandomSource_STATE_DWORK_h, 3);

    /* End of SystemInitialize for SubSystem: '<S5>/Sensor_IMU' */

    /* SystemInitialize for Atomic SubSystem: '<S5>/Sensor_MAG' */
    /* InitializeConditions for S-Function (sdsprandsrc2): '<S122>/Random Source' */
    RandSrcCreateSeeds_32(12698U, Plant_DW.RandomSource_SEED_DWORK, 3);
    RandSrcInitState_GZ(Plant_DW.RandomSource_SEED_DWORK,
                        Plant_DW.RandomSource_STATE_DWORK, 3);

    /* End of SystemInitialize for SubSystem: '<S5>/Sensor_MAG' */
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
