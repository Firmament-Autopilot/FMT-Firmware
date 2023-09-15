/*
 * File: Plant.c
 *
 * Code generated for Simulink model 'Plant'.
 *
 * Model version                  : 1.872
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Sep 15 08:53:34 2023
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
struct_zjTVXoT1Wcig2PfNqPD1gB PLANT_EXPORT = {
  2U,

  { 77, 117, 108, 116, 105, 99, 111, 112, 116, 101, 114, 32, 118, 49, 46, 48, 46,
    48, 0 }
} ;                                    /* Variable: PLANT_EXPORT
                                        * Referenced by:
                                        *   '<S21>/dt'
                                        *   '<S86>/dt'
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

  /* S-Function (sdsprandsrc2): '<S97>/Random Source' */
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

  /* End of S-Function (sdsprandsrc2): '<S97>/Random Source' */
}

void RandSrcInitState_GZ(const uint32_T seed[], uint32_T state[], int32_T nChans)
{
  int32_T i;
  int32_T tmp;

  /* InitializeConditions for S-Function (sdsprandsrc2): '<S97>/Random Source' */
  /* RandSrcInitState_GZ */
  for (i = 0; i < nChans; i++) {
    tmp = i << 1;
    state[tmp] = 362436069U;
    state[tmp + 1] = seed[i] == 0U ? 521288629U : seed[i];
  }

  /* End of InitializeConditions for S-Function (sdsprandsrc2): '<S97>/Random Source' */
}

void RandSrcInitState_U_32(const uint32_T seed[], real32_T state[], int32_T
  nChans)
{
  int32_T i;
  uint32_T j;
  int32_T k;
  int32_T n;
  real32_T d;

  /* InitializeConditions for S-Function (sdsprandsrc2): '<S106>/Random Source' */
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

  /* End of InitializeConditions for S-Function (sdsprandsrc2): '<S106>/Random Source' */
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

  /* InitializeConditions for S-Function (sdsprandsrc2): '<S106>/Random Source' */
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

  /* End of InitializeConditions for S-Function (sdsprandsrc2): '<S106>/Random Source' */
}

void RandSrcCreateSeeds_32(uint32_T initSeed, uint32_T seedArray[], int32_T
  numSeeds)
{
  real32_T state[35];
  real32_T tmp;
  real32_T min;
  real32_T max;
  int32_T i;

  /* InitializeConditions for S-Function (sdsprandsrc2): '<S106>/Random Source' */
  /* RandSrcCreateSeeds_32 */
  min = 0.0F;
  max = 1.0F;
  RandSrcInitState_U_32(&initSeed, state, 1);
  for (i = 0; i < numSeeds; i++) {
    RandSrc_U_R(&tmp, &min, 1, &max, 1, state, 1, 1);
    seedArray[i] = (uint32_T)(tmp * 2.14748365E+9F);
  }

  /* End of InitializeConditions for S-Function (sdsprandsrc2): '<S106>/Random Source' */
}

/* Model step function */
void Plant_step(void)
{
  real32_T rtb_Gain_g2;
  real32_T rtb_Add_la[3];
  real32_T rtb_Sum_hq[3];
  real32_T rtb_VectorConcatenate1_d[3];
  real32_T rtb_VectorConcatenate_f[9];
  real32_T rtb_Switch[6];
  real32_T rtb_Sum_c[3];
  real32_T rtb_MatrixConcatenate4[16];
  real32_T rtb_Sum_d[3];
  real32_T rtb_MatrixConcatenate1_p[9];
  real32_T rtb_Sum_c0;
  real32_T rtb_Sum_i;
  real32_T rtb_Sum_nb;
  real_T rtb_SumofElements;
  real_T rtb_SumofElements1;
  real_T rtb_Divide2[3];
  Barometer_Bus rtb_BusAssignment_i;
  GPS_uBlox_Bus rtb_BusAssignment_dk;
  real32_T rtb_VectorConcatenate_k[9];
  MAG_Bus rtb_BusAssignment_o;
  real32_T rtb_Divide2_b[3];
  real32_T rtb_MathFunction_h[3];
  real32_T rtb_RandomSource[3];
  real32_T rtb_Switch1[3];
  real32_T rtb_Switch2[3];
  real32_T rtb_RandomSource1[3];
  real32_T rtb_RandomSource_f[3];
  int32_T i;
  real32_T rtb_MatrixConcatenate4_0[4];
  boolean_T rtb_Compare_j;
  real_T rtb_Product1;
  real32_T rtb_DiscreteTimeIntegrator_l_id;
  real32_T rtb_DiscreteTimeIntegrator_l__0;
  real32_T rtb_DiscreteTimeIntegrator_l__1;
  real32_T rtb_DiscreteTimeIntegrator_l__2;
  real_T rtb_Product1_idx_1;
  real_T rtb_Product1_idx_0;
  real_T rtb_Product2_g_idx_1;
  real_T rtb_Product1_tmp_idx_2;
  real_T Sum2_idx_2;
  real_T Sum2_idx_0;
  real32_T rtb_Subtract_k_idx_3;
  real32_T rtb_Subtract_k_idx_2;
  real32_T rtb_Subtract_k_idx_1;
  real32_T rtb_Subtract_k_idx_0;
  real32_T rtb_Divide_n_idx_2;
  real32_T rtb_Divide_n_idx_1;
  real32_T rtb_Divide_n_idx_0;
  real32_T rtb_TrigonometricFunction1_idx_;
  real32_T rtb_TrigonometricFunction1_id_0;
  real32_T rtb_TrigonometricFunction1_id_1;
  int32_T rtb_Saturation1_idx_1;
  real32_T u0;
  real32_T u0_0;
  real32_T u0_1;
  uint16_T tmp;
  real32_T rtb_Divide_k_idx_0;
  real32_T rtb_Divide_k_idx_1;
  real32_T rtb_Divide_k_idx_2;
  real32_T rtb_Divide_k_idx_3;
  real32_T rtb_Add_e_tmp;
  real32_T rtb_Add_e_tmp_0;
  real32_T rtb_Gain_d_tmp;

  /* Delay: '<Root>/Delay' */
  rtb_Subtract_k_idx_0 = Plant_Y.Plant_States.vel_y_O;
  rtb_Subtract_k_idx_1 = Plant_Y.Plant_States.vel_z_O;
  for (i = 0; i < 9; i++) {
    rtb_VectorConcatenate_k[i] = Plant_Y.Extended_States.M_BO[i];
  }

  /* Outputs for Atomic SubSystem: '<Root>/Actuators' */
  /* Saturate: '<S9>/Saturation' incorporates:
   *  Inport: '<Root>/Control_Out'
   */
  if (Plant_U.Control_Out.actuator_cmd[0] > 2000) {
    tmp = 2000U;
  } else if (Plant_U.Control_Out.actuator_cmd[0] < 1000) {
    tmp = 1000U;
  } else {
    tmp = Plant_U.Control_Out.actuator_cmd[0];
  }

  /* Gain: '<S9>/Gain' incorporates:
   *  Sum: '<S9>/Subtract'
   */
  rtb_Subtract_k_idx_3 = ((real32_T)tmp - 1000.0F) * 0.000999987125F;

  /* RelationalOperator: '<S14>/Compare' incorporates:
   *  Constant: '<S14>/Constant'
   */
  rtb_Compare_j = (rtb_Subtract_k_idx_3 > 0.1F);

  /* Sum: '<S13>/Add' incorporates:
   *  Constant: '<S13>/Constant1'
   *  Gain: '<S13>/Gain1'
   */
  rtb_Subtract_k_idx_3 = 718.078F * rtb_Subtract_k_idx_3 + 88.448F;

  /* DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */
  rtb_DiscreteTimeIntegrator_l__2 = Plant_DW.DiscreteTimeIntegrator_DSTATE_n[0];

  /* Product: '<S13>/Multiply' */
  u0_1 = rtb_Compare_j ? rtb_Subtract_k_idx_3 : 0.0F;

  /* Math: '<S15>/Square' incorporates:
   *  DiscreteIntegrator: '<S12>/Discrete-Time Integrator'
   *  Math: '<S17>/Square'
   */
  rtb_Subtract_k_idx_2 = Plant_DW.DiscreteTimeIntegrator_DSTATE_n[0] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_n[0];

  /* Gain: '<S9>/Gain' incorporates:
   *  Constant: '<S15>/cT'
   *  Product: '<S15>/Multiply'
   */
  rtb_Divide_n_idx_0 = (real32_T)(rtb_Subtract_k_idx_2 * 1.239E-5);

  /* Math: '<S15>/Square' */
  rtb_TrigonometricFunction1_id_1 = rtb_Subtract_k_idx_2;

  /* Saturate: '<S9>/Saturation' incorporates:
   *  Inport: '<Root>/Control_Out'
   */
  if (Plant_U.Control_Out.actuator_cmd[1] > 2000) {
    tmp = 2000U;
  } else if (Plant_U.Control_Out.actuator_cmd[1] < 1000) {
    tmp = 1000U;
  } else {
    tmp = Plant_U.Control_Out.actuator_cmd[1];
  }

  /* Gain: '<S9>/Gain' incorporates:
   *  Sum: '<S9>/Subtract'
   */
  rtb_Subtract_k_idx_3 = ((real32_T)tmp - 1000.0F) * 0.000999987125F;

  /* RelationalOperator: '<S14>/Compare' incorporates:
   *  Constant: '<S14>/Constant'
   */
  rtb_Compare_j = (rtb_Subtract_k_idx_3 > 0.1F);

  /* Sum: '<S13>/Add' incorporates:
   *  Constant: '<S13>/Constant1'
   *  Gain: '<S13>/Gain1'
   */
  rtb_Subtract_k_idx_3 = 718.078F * rtb_Subtract_k_idx_3 + 88.448F;

  /* DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */
  rtb_DiscreteTimeIntegrator_l__1 = Plant_DW.DiscreteTimeIntegrator_DSTATE_n[1];

  /* Product: '<S13>/Multiply' */
  u0_0 = rtb_Compare_j ? rtb_Subtract_k_idx_3 : 0.0F;

  /* Math: '<S15>/Square' incorporates:
   *  DiscreteIntegrator: '<S12>/Discrete-Time Integrator'
   *  Math: '<S17>/Square'
   */
  rtb_Subtract_k_idx_2 = Plant_DW.DiscreteTimeIntegrator_DSTATE_n[1] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_n[1];

  /* Gain: '<S9>/Gain' incorporates:
   *  Constant: '<S15>/cT'
   *  Product: '<S15>/Multiply'
   */
  rtb_Divide_n_idx_1 = (real32_T)(rtb_Subtract_k_idx_2 * 1.239E-5);

  /* Math: '<S15>/Square' */
  rtb_TrigonometricFunction1_id_0 = rtb_Subtract_k_idx_2;

  /* Saturate: '<S9>/Saturation' incorporates:
   *  Inport: '<Root>/Control_Out'
   */
  if (Plant_U.Control_Out.actuator_cmd[2] > 2000) {
    tmp = 2000U;
  } else if (Plant_U.Control_Out.actuator_cmd[2] < 1000) {
    tmp = 1000U;
  } else {
    tmp = Plant_U.Control_Out.actuator_cmd[2];
  }

  /* Gain: '<S9>/Gain' incorporates:
   *  Sum: '<S9>/Subtract'
   */
  rtb_Subtract_k_idx_3 = ((real32_T)tmp - 1000.0F) * 0.000999987125F;

  /* RelationalOperator: '<S14>/Compare' incorporates:
   *  Constant: '<S14>/Constant'
   */
  rtb_Compare_j = (rtb_Subtract_k_idx_3 > 0.1F);

  /* Sum: '<S13>/Add' incorporates:
   *  Constant: '<S13>/Constant1'
   *  Gain: '<S13>/Gain1'
   */
  rtb_Subtract_k_idx_3 = 718.078F * rtb_Subtract_k_idx_3 + 88.448F;

  /* DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */
  rtb_DiscreteTimeIntegrator_l__0 = Plant_DW.DiscreteTimeIntegrator_DSTATE_n[2];

  /* Product: '<S13>/Multiply' */
  u0 = rtb_Compare_j ? rtb_Subtract_k_idx_3 : 0.0F;

  /* Math: '<S15>/Square' incorporates:
   *  DiscreteIntegrator: '<S12>/Discrete-Time Integrator'
   *  Math: '<S17>/Square'
   */
  rtb_Subtract_k_idx_2 = Plant_DW.DiscreteTimeIntegrator_DSTATE_n[2] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_n[2];

  /* Gain: '<S9>/Gain' incorporates:
   *  Constant: '<S15>/cT'
   *  Product: '<S15>/Multiply'
   */
  rtb_Divide_n_idx_2 = (real32_T)(rtb_Subtract_k_idx_2 * 1.239E-5);

  /* Math: '<S15>/Square' */
  rtb_TrigonometricFunction1_idx_ = rtb_Subtract_k_idx_2;

  /* Saturate: '<S9>/Saturation' incorporates:
   *  Inport: '<Root>/Control_Out'
   */
  if (Plant_U.Control_Out.actuator_cmd[3] > 2000) {
    tmp = 2000U;
  } else if (Plant_U.Control_Out.actuator_cmd[3] < 1000) {
    tmp = 1000U;
  } else {
    tmp = Plant_U.Control_Out.actuator_cmd[3];
  }

  /* Gain: '<S9>/Gain' incorporates:
   *  Sum: '<S9>/Subtract'
   */
  rtb_Subtract_k_idx_3 = ((real32_T)tmp - 1000.0F) * 0.000999987125F;

  /* RelationalOperator: '<S14>/Compare' incorporates:
   *  Constant: '<S14>/Constant'
   */
  rtb_Compare_j = (rtb_Subtract_k_idx_3 > 0.1F);

  /* Sum: '<S13>/Add' incorporates:
   *  Constant: '<S13>/Constant1'
   *  Gain: '<S13>/Gain1'
   */
  rtb_Subtract_k_idx_3 = 718.078F * rtb_Subtract_k_idx_3 + 88.448F;

  /* DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */
  rtb_DiscreteTimeIntegrator_l_id = Plant_DW.DiscreteTimeIntegrator_DSTATE_n[3];

  /* Math: '<S15>/Square' incorporates:
   *  DiscreteIntegrator: '<S12>/Discrete-Time Integrator'
   *  Math: '<S17>/Square'
   */
  rtb_Subtract_k_idx_2 = Plant_DW.DiscreteTimeIntegrator_DSTATE_n[3] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_n[3];

  /* Sum: '<S16>/Add' incorporates:
   *  DiscreteIntegrator: '<S12>/Discrete-Time Integrator'
   */
  rtb_Gain_g2 = ((Plant_DW.DiscreteTimeIntegrator_DSTATE_n[2] -
                  Plant_DW.DiscreteTimeIntegrator_DSTATE_n[0]) -
                 Plant_DW.DiscreteTimeIntegrator_DSTATE_n[1]) +
    Plant_DW.DiscreteTimeIntegrator_DSTATE_n[3];

  /* Product: '<S19>/Multiply' */
  rtb_Sum_hq[0] = 0.0F;

  /* Product: '<S19>/Multiply1' incorporates:
   *  Delay: '<Root>/Delay'
   *  Product: '<S16>/Multiply'
   */
  rtb_Sum_hq[1] = rtb_Gain_g2 * Plant_Y.Plant_States.rot_x_B * 0.0001287F;

  /* Product: '<S19>/Multiply2' */
  rtb_Sum_hq[2] = 0.0F;

  /* Product: '<S20>/Multiply3' incorporates:
   *  Delay: '<Root>/Delay'
   *  Product: '<S16>/Multiply'
   */
  rtb_VectorConcatenate1_d[0] = rtb_Gain_g2 * Plant_Y.Plant_States.rot_y_B *
    0.0001287F;

  /* Product: '<S20>/Multiply4' */
  rtb_VectorConcatenate1_d[1] = 0.0F;

  /* Product: '<S20>/Multiply5' */
  rtb_VectorConcatenate1_d[2] = 0.0F;

  /* Sum: '<S11>/Sum' incorporates:
   *  Constant: '<S17>/X_Frame_CM'
   *  Math: '<S17>/Square'
   *  Product: '<S17>/Multiply'
   *  Sum: '<S18>/Sum'
   */
  for (i = 0; i < 3; i++) {
    rtb_Sum_c[i] = (((Plant_ConstP.X_Frame_CM_Value[i + 3] *
                      rtb_TrigonometricFunction1_id_0 +
                      Plant_ConstP.X_Frame_CM_Value[i] *
                      rtb_TrigonometricFunction1_id_1) +
                     Plant_ConstP.X_Frame_CM_Value[i + 6] *
                     rtb_TrigonometricFunction1_idx_) +
                    Plant_ConstP.X_Frame_CM_Value[i + 9] * rtb_Subtract_k_idx_2)
      + (rtb_Sum_hq[i] - rtb_VectorConcatenate1_d[i]);
  }

  /* End of Sum: '<S11>/Sum' */

  /* Update for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S12>/Gain'
   *  Saturate: '<S13>/Saturation1'
   *  Sum: '<S12>/Subtract'
   */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_n[0] += (u0_1 -
    Plant_DW.DiscreteTimeIntegrator_DSTATE_n[0]) * 50.0F * 0.002F;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_n[1] += (u0_0 -
    Plant_DW.DiscreteTimeIntegrator_DSTATE_n[1]) * 50.0F * 0.002F;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_n[2] += (u0 -
    Plant_DW.DiscreteTimeIntegrator_DSTATE_n[2]) * 50.0F * 0.002F;

  /* Sum: '<S10>/Sum of Elements' incorporates:
   *  Constant: '<S15>/cT'
   *  Product: '<S15>/Multiply'
   */
  rtb_Subtract_k_idx_2 = ((rtb_Divide_n_idx_0 + rtb_Divide_n_idx_1) +
    rtb_Divide_n_idx_2) + (real32_T)(rtb_Subtract_k_idx_2 * 1.239E-5);

  /* Update for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S12>/Gain'
   *  Product: '<S13>/Multiply'
   *  Sum: '<S12>/Subtract'
   */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_n[3] += ((rtb_Compare_j ?
    rtb_Subtract_k_idx_3 : 0.0F) - Plant_DW.DiscreteTimeIntegrator_DSTATE_n[3]) *
    50.0F * 0.002F;

  /* End of Outputs for SubSystem: '<Root>/Actuators' */

  /* Outputs for Atomic SubSystem: '<Root>/Environment' */
  /* Trigonometry: '<S37>/Trigonometric Function1' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S36>/Gain'
   *  Trigonometry: '<S37>/Trigonometric Function3'
   */
  rtb_Divide_n_idx_1 = arm_cos_f32(-Plant_Y.Plant_States.psi);
  rtb_VectorConcatenate_f[0] = rtb_Divide_n_idx_1;

  /* Trigonometry: '<S37>/Trigonometric Function' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S36>/Gain'
   *  Trigonometry: '<S37>/Trigonometric Function2'
   */
  rtb_Divide_n_idx_2 = arm_sin_f32(-Plant_Y.Plant_States.psi);
  rtb_VectorConcatenate_f[1] = rtb_Divide_n_idx_2;

  /* SignalConversion: '<S37>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S37>/Constant3'
   */
  rtb_VectorConcatenate_f[2] = 0.0F;

  /* Gain: '<S37>/Gain' */
  rtb_VectorConcatenate_f[3] = -rtb_Divide_n_idx_2;

  /* Trigonometry: '<S37>/Trigonometric Function3' */
  rtb_VectorConcatenate_f[4] = rtb_Divide_n_idx_1;

  /* SignalConversion: '<S37>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S37>/Constant4'
   */
  rtb_VectorConcatenate_f[5] = 0.0F;

  /* SignalConversion: '<S37>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_f[6] = Plant_ConstB.VectorConcatenate3_e[0];
  rtb_VectorConcatenate_f[7] = Plant_ConstB.VectorConcatenate3_e[1];
  rtb_VectorConcatenate_f[8] = Plant_ConstB.VectorConcatenate3_e[2];

  /* Switch: '<S38>/Switch' incorporates:
   *  Constant: '<S38>/Constant'
   *  Delay: '<S38>/Delay'
   *  Inport: '<Root>/Environment_Info'
   *  RelationalOperator: '<S41>/FixPt Relational Operator'
   *  UnitDelay: '<S41>/Delay Input1'
   *
   * Block description for '<S41>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (Plant_U.Environment_Info.timestamp > Plant_DW.DelayInput1_DSTATE) {
    Plant_DW.Delay_DSTATE_p = 1U;
  }

  /* End of Switch: '<S38>/Switch' */

  /* Switch: '<S33>/Switch' incorporates:
   *  Constant: '<S56>/Constant'
   *  Delay: '<Root>/Delay'
   *  Delay: '<S38>/Delay'
   *  Product: '<S42>/Multiply4'
   *  Product: '<S48>/Divide'
   *  Product: '<S52>/Multiply3'
   *  Product: '<S52>/Multiply4'
   *  Product: '<S52>/Multiply5'
   *  RelationalOperator: '<S56>/Compare'
   *  Sum: '<S45>/Sum'
   *  Switch: '<S55>/Switch1'
   *  Switch: '<S55>/Switch2'
   */
  if (Plant_DW.Delay_DSTATE_p > 0) {
    /* Sum: '<S42>/Sum' incorporates:
     *  Delay: '<Root>/Delay'
     *  Gain: '<S42>/Gain1'
     */
    rtb_VectorConcatenate1_d[0] = Plant_Y.Plant_States.x_R;
    rtb_VectorConcatenate1_d[1] = Plant_Y.Plant_States.y_R;
    rtb_VectorConcatenate1_d[2] = -Plant_Y.Plant_States.h_R;
    for (i = 0; i < 3; i++) {
      /* Sum: '<S42>/Sum' incorporates:
       *  Inport: '<Root>/Environment_Info'
       */
      rtb_MathFunction_h[i] = Plant_U.Environment_Info.hit_position[i] -
        rtb_VectorConcatenate1_d[i];
      rtb_Sum_hq[i] = rtb_VectorConcatenate_k[i + 6] *
        Plant_U.Environment_Info.hit_normal[2] + (rtb_VectorConcatenate_k[i + 3]
        * Plant_U.Environment_Info.hit_normal[1] + rtb_VectorConcatenate_k[i] *
        Plant_U.Environment_Info.hit_normal[0]);
    }

    for (i = 0; i < 3; i++) {
      rtb_Divide_n_idx_1 = rtb_VectorConcatenate_k[i + 6] * rtb_MathFunction_h[2]
        + (rtb_VectorConcatenate_k[i + 3] * rtb_MathFunction_h[1] +
           rtb_VectorConcatenate_k[i] * rtb_MathFunction_h[0]);

      /* Math: '<S47>/Math Function' incorporates:
       *  Product: '<S42>/Multiply2'
       */
      rtb_Switch2[i] = rtb_Divide_n_idx_1 * rtb_Divide_n_idx_1;
      rtb_Switch1[i] = rtb_Divide_n_idx_1;
    }

    /* Sum: '<S47>/Sum of Elements' incorporates:
     *  Inport: '<Root>/Environment_Info'
     *  Product: '<S42>/Multiply'
     *  Product: '<S42>/Multiply2'
     */
    rtb_Divide_n_idx_1 = (rtb_Switch2[0] + rtb_Switch2[1]) + rtb_Switch2[2];

    /* Math: '<S47>/Math Function1' incorporates:
     *  Sum: '<S47>/Sum of Elements'
     *
     * About '<S47>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_Divide_n_idx_1 < 0.0F) {
      rtb_Gain_g2 = -sqrtf(fabsf(rtb_Divide_n_idx_1));
    } else {
      rtb_Gain_g2 = sqrtf(rtb_Divide_n_idx_1);
    }

    /* End of Math: '<S47>/Math Function1' */

    /* Switch: '<S47>/Switch' incorporates:
     *  Constant: '<S47>/Constant'
     *  Product: '<S47>/Product'
     */
    if (rtb_Gain_g2 > 0.0F) {
      rtb_Divide_n_idx_0 = rtb_Switch1[0];
      rtb_Divide_n_idx_1 = rtb_Switch1[1];
      rtb_Divide_n_idx_2 = rtb_Switch1[2];
    } else {
      rtb_Divide_n_idx_0 = 0.0F;
      rtb_Divide_n_idx_1 = 0.0F;
      rtb_Divide_n_idx_2 = 0.0F;
      rtb_Gain_g2 = 1.0F;
    }

    /* End of Switch: '<S47>/Switch' */

    /* Product: '<S47>/Divide' */
    rtb_Switch1[0] = rtb_Divide_n_idx_0 / rtb_Gain_g2;
    rtb_Switch1[1] = rtb_Divide_n_idx_1 / rtb_Gain_g2;
    rtb_Switch1[2] = rtb_Divide_n_idx_2 / rtb_Gain_g2;

    /* Product: '<S50>/Multiply5' incorporates:
     *  Delay: '<Root>/Delay'
     */
    rtb_Switch2[2] = Plant_Y.Plant_States.rot_y_B * rtb_Switch1[0];

    /* Product: '<S50>/Multiply4' incorporates:
     *  Delay: '<Root>/Delay'
     */
    rtb_Switch2[1] = Plant_Y.Plant_States.rot_x_B * rtb_Switch1[2];

    /* Product: '<S50>/Multiply3' incorporates:
     *  Delay: '<Root>/Delay'
     */
    rtb_Switch2[0] = Plant_Y.Plant_States.rot_z_B * rtb_Switch1[1];

    /* Product: '<S49>/Multiply2' incorporates:
     *  Delay: '<Root>/Delay'
     */
    rtb_Divide2_b[2] = Plant_Y.Plant_States.rot_x_B * rtb_Switch1[1];

    /* Product: '<S49>/Multiply1' incorporates:
     *  Delay: '<Root>/Delay'
     */
    rtb_Divide2_b[1] = Plant_Y.Plant_States.rot_z_B * rtb_Switch1[0];

    /* Product: '<S49>/Multiply' incorporates:
     *  Delay: '<Root>/Delay'
     */
    rtb_Divide2_b[0] = Plant_Y.Plant_States.rot_y_B * rtb_Switch1[2];
    for (i = 0; i < 3; i++) {
      /* Math: '<S48>/Math Function' incorporates:
       *  Product: '<S42>/Multiply'
       */
      rtb_MathFunction_h[i] = rtb_Sum_hq[i] * rtb_Sum_hq[i];
      rtb_Divide2_b[i] = ((rtb_VectorConcatenate_k[i + 3] * rtb_Subtract_k_idx_0
                           + rtb_VectorConcatenate_k[i] *
                           Plant_Y.Plant_States.vel_x_O) +
                          rtb_VectorConcatenate_k[i + 6] * rtb_Subtract_k_idx_1)
        + (rtb_Divide2_b[i] - rtb_Switch2[i]);
    }

    /* Sum: '<S48>/Sum of Elements' incorporates:
     *  Delay: '<Root>/Delay'
     *  Product: '<S42>/Multiply1'
     *  Sum: '<S42>/Sum1'
     *  Sum: '<S44>/Sum'
     */
    rtb_Divide_n_idx_1 = (rtb_MathFunction_h[0] + rtb_MathFunction_h[1]) +
      rtb_MathFunction_h[2];

    /* Math: '<S48>/Math Function1' incorporates:
     *  Sum: '<S48>/Sum of Elements'
     *
     * About '<S48>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_Divide_n_idx_1 < 0.0F) {
      rtb_Gain_g2 = -sqrtf(fabsf(rtb_Divide_n_idx_1));
    } else {
      rtb_Gain_g2 = sqrtf(rtb_Divide_n_idx_1);
    }

    /* End of Math: '<S48>/Math Function1' */

    /* Switch: '<S48>/Switch' incorporates:
     *  Constant: '<S48>/Constant'
     *  Product: '<S42>/Multiply'
     *  Product: '<S48>/Product'
     */
    if (rtb_Gain_g2 > 0.0F) {
      rtb_Divide_n_idx_0 = rtb_Sum_hq[0];
      rtb_Divide_n_idx_1 = rtb_Sum_hq[1];
      rtb_Divide_n_idx_2 = rtb_Sum_hq[2];
    } else {
      rtb_Divide_n_idx_0 = 0.0F;
      rtb_Divide_n_idx_1 = 0.0F;
      rtb_Divide_n_idx_2 = 0.0F;
      rtb_Gain_g2 = 1.0F;
    }

    /* End of Switch: '<S48>/Switch' */

    /* Product: '<S48>/Divide' */
    rtb_TrigonometricFunction1_idx_ = rtb_Divide_n_idx_0 / rtb_Gain_g2;

    /* DotProduct: '<S42>/Dot Product' */
    rtb_Divide_n_idx_0 = rtb_Divide2_b[0] * rtb_TrigonometricFunction1_idx_;
    rtb_Sum_hq[0] = rtb_TrigonometricFunction1_idx_;

    /* Product: '<S48>/Divide' */
    rtb_TrigonometricFunction1_idx_ = rtb_Divide_n_idx_1 / rtb_Gain_g2;

    /* DotProduct: '<S42>/Dot Product' */
    rtb_Divide_n_idx_0 += rtb_Divide2_b[1] * rtb_TrigonometricFunction1_idx_;
    rtb_Sum_hq[1] = rtb_TrigonometricFunction1_idx_;

    /* Product: '<S48>/Divide' */
    rtb_TrigonometricFunction1_idx_ = rtb_Divide_n_idx_2 / rtb_Gain_g2;

    /* DotProduct: '<S42>/Dot Product' */
    rtb_Divide_n_idx_0 += rtb_Divide2_b[2] * rtb_TrigonometricFunction1_idx_;

    /* Product: '<S51>/Multiply2' */
    rtb_Switch2[2] = rtb_Switch1[0] * rtb_Sum_hq[1];

    /* Product: '<S51>/Multiply1' */
    rtb_Switch2[1] = rtb_Switch1[2] * rtb_Sum_hq[0];

    /* Product: '<S51>/Multiply' */
    rtb_Switch2[0] = rtb_Switch1[1] * rtb_TrigonometricFunction1_idx_;
    rtb_Switch2[0] -= rtb_Switch1[2] * rtb_Sum_hq[1];
    rtb_Switch2[1] -= rtb_Switch1[0] * rtb_TrigonometricFunction1_idx_;
    rtb_Switch2[2] -= rtb_Switch1[1] * rtb_Sum_hq[0];

    /* Product: '<S42>/Divide2' incorporates:
     *  Constant: '<S42>/Inertia_Matrix'
     *  Product: '<S52>/Multiply3'
     *  Product: '<S52>/Multiply4'
     *  Product: '<S52>/Multiply5'
     *  Sum: '<S45>/Sum'
     */
    rt_mldivide_U1f3x3_U2f3x1_Yf3x1(Plant_ConstP.pooled22, rtb_Switch2,
      rtb_Divide2_b);

    /* Product: '<S42>/Divide1' incorporates:
     *  Abs: '<S42>/Abs'
     *  Constant: '<S42>/mass_inv'
     *  Constant: '<S42>/period'
     *  DotProduct: '<S42>/Dot Product'
     *  DotProduct: '<S42>/Dot Product1'
     *  Gain: '<S42>/Gain'
     *  Product: '<S42>/Divide'
     *  Product: '<S42>/Multiply3'
     *  Product: '<S53>/Multiply'
     *  Product: '<S53>/Multiply1'
     *  Product: '<S53>/Multiply2'
     *  Product: '<S54>/Multiply3'
     *  Product: '<S54>/Multiply4'
     *  Product: '<S54>/Multiply5'
     *  Sum: '<S42>/Add1'
     *  Sum: '<S46>/Sum'
     */
    rtb_Gain_g2 = fabsf(1.0F / ((((rtb_Divide2_b[1] * rtb_Switch1[2] -
      rtb_Divide2_b[2] * rtb_Switch1[1]) * rtb_Sum_hq[0] + (rtb_Divide2_b[2] *
      rtb_Switch1[0] - rtb_Divide2_b[0] * rtb_Switch1[2]) * rtb_Sum_hq[1]) +
      (rtb_Divide2_b[0] * rtb_Switch1[1] - rtb_Divide2_b[1] * rtb_Switch1[0]) *
      rtb_TrigonometricFunction1_idx_) + 1.12866819F) * -(rtb_Divide_n_idx_0 *
      Plant_ConstB.Add_n)) / 0.0167F;

    /* Gain: '<S43>/Gain' */
    rtb_Switch[0] = 0.0F;
    rtb_Switch[3] = rtb_Gain_g2 * rtb_Sum_hq[0];

    /* Gain: '<S43>/Gain' incorporates:
     *  Product: '<S42>/Multiply4'
     */
    rtb_Switch[1] = 0.0F;
    rtb_Switch[4] = rtb_Gain_g2 * rtb_Sum_hq[1];

    /* Gain: '<S43>/Gain' incorporates:
     *  Product: '<S42>/Multiply4'
     */
    rtb_Switch[2] = 0.0F;
    rtb_Switch[5] = rtb_Gain_g2 * rtb_TrigonometricFunction1_idx_;
  } else {
    if (Plant_Y.Plant_States.h_R < 0.0F) {
      /* Switch: '<S55>/Switch1' incorporates:
       *  Delay: '<Root>/Delay'
       *  Gain: '<S58>/Gain1'
       *  Gain: '<S58>/Gain2'
       *  Gain: '<S58>/Gain3'
       *  Sum: '<S58>/Subtract'
       */
      rtb_Switch1[0] = ((0.0F - 30.0F * Plant_Y.Plant_States.phi) - 5.0F *
                        Plant_Y.Plant_States.rot_x_B) * 0.289603859F;
      rtb_Switch1[1] = ((0.0F - 30.0F * Plant_Y.Plant_States.theta) - 5.0F *
                        Plant_Y.Plant_States.rot_y_B) * 0.289603859F;
      rtb_Switch1[2] = (0.0F - 5.0F * Plant_Y.Plant_States.rot_z_B) *
        0.289603859F;

      /* Switch: '<S57>/Switch1' incorporates:
       *  Constant: '<S57>/mg'
       *  Constant: '<S59>/Constant'
       *  Delay: '<Root>/Delay'
       *  Gain: '<S57>/Gain'
       *  RelationalOperator: '<S59>/Compare'
       *  Sum: '<S57>/Add'
       *  Switch: '<S55>/Switch2'
       */
      if (Plant_Y.Plant_States.h_R <= -0.05F) {
        /* Switch: '<S57>/Switch3' incorporates:
         *  Constant: '<S57>/mg'
         *  Constant: '<S60>/Constant'
         *  Gain: '<S57>/Gain1'
         *  Gain: '<S57>/Gain2'
         *  Gain: '<S57>/Gain4'
         *  RelationalOperator: '<S60>/Compare'
         *  Sum: '<S57>/Add1'
         *  Sum: '<S57>/Add2'
         */
        if (Plant_Y.Plant_States.h_R <= -0.1F) {
          rtb_Divide_n_idx_1 = (Plant_Y.Plant_States.h_R - 8.68811607F) - 50.0F *
            Plant_Y.Plant_States.vel_z_O;
        } else {
          rtb_Divide_n_idx_1 = (0.5F * Plant_Y.Plant_States.h_R - 8.68811607F) -
            20.0F * Plant_Y.Plant_States.vel_z_O;
        }

        /* End of Switch: '<S57>/Switch3' */
      } else {
        rtb_Divide_n_idx_1 = -8.68811607F - 10.0F * Plant_Y.Plant_States.vel_z_O;
      }

      /* End of Switch: '<S57>/Switch1' */

      /* SignalConversion: '<S57>/TmpSignal ConversionAtMultiplyInport2' incorporates:
       *  Delay: '<Root>/Delay'
       *  Gain: '<S57>/Gain5'
       *  Gain: '<S57>/Gain6'
       *  Switch: '<S55>/Switch2'
       */
      rtb_Divide_n_idx_2 = -50.0F * Plant_Y.Plant_States.vel_x_O;
      rtb_Divide_n_idx_0 = -50.0F * Plant_Y.Plant_States.vel_y_O;

      /* Switch: '<S55>/Switch2' incorporates:
       *  Product: '<S57>/Multiply'
       *  SignalConversion: '<S57>/TmpSignal ConversionAtMultiplyInport2'
       */
      for (i = 0; i < 3; i++) {
        rtb_Switch2[i] = rtb_VectorConcatenate_k[i + 6] * rtb_Divide_n_idx_1 +
          (rtb_VectorConcatenate_k[i + 3] * rtb_Divide_n_idx_0 +
           rtb_VectorConcatenate_k[i] * rtb_Divide_n_idx_2);
      }
    } else {
      /* Switch: '<S55>/Switch1' */
      rtb_Switch1[0] = 0.0F;

      /* Switch: '<S55>/Switch2' */
      rtb_Switch2[0] = 0.0F;

      /* Switch: '<S55>/Switch1' */
      rtb_Switch1[1] = 0.0F;

      /* Switch: '<S55>/Switch2' */
      rtb_Switch2[1] = 0.0F;

      /* Switch: '<S55>/Switch1' */
      rtb_Switch1[2] = 0.0F;

      /* Switch: '<S55>/Switch2' */
      rtb_Switch2[2] = 0.0F;
    }

    rtb_Switch[0] = rtb_Switch1[0];
    rtb_Switch[3] = rtb_Switch2[0];
    rtb_Switch[1] = rtb_Switch1[1];
    rtb_Switch[4] = rtb_Switch2[1];
    rtb_Switch[2] = rtb_Switch1[2];
    rtb_Switch[5] = rtb_Switch2[2];
  }

  /* End of Switch: '<S33>/Switch' */

  /* Sum: '<S4>/Sum' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/Constant1'
   *  Gain: '<S10>/Gain'
   *  Sum: '<S10>/Sum of Elements'
   */
  rtb_VectorConcatenate1_d[0] = 0.0F;
  rtb_VectorConcatenate1_d[1] = 0.0F;

  /* Outputs for Atomic SubSystem: '<Root>/Actuators' */
  rtb_VectorConcatenate1_d[2] = -rtb_Subtract_k_idx_2;

  /* End of Outputs for SubSystem: '<Root>/Actuators' */
  for (i = 0; i < 3; i++) {
    /* Gain: '<S35>/Gain' incorporates:
     *  Delay: '<Root>/Delay'
     *  Product: '<S35>/Multiply'
     */
    rtb_MathFunction_h[i] = -0.15F * (rtb_VectorConcatenate_f[i + 6] *
      rtb_Subtract_k_idx_1 + (rtb_VectorConcatenate_f[i + 3] *
      rtb_Subtract_k_idx_0 + rtb_VectorConcatenate_f[i] *
      Plant_Y.Plant_States.vel_x_O));

    /* Product: '<S34>/Multiply3' */
    rtb_Switch2[i] = rtb_VectorConcatenate_k[i + 6] * 8.69166F;
  }

  /* Product: '<S35>/Multiply1' incorporates:
   *  Math: '<S35>/Square'
   */
  for (i = 0; i < 3; i++) {
    rtb_Add_la[i] = rtb_VectorConcatenate_f[3 * i + 2] * rtb_MathFunction_h[2] +
      (rtb_VectorConcatenate_f[3 * i + 1] * rtb_MathFunction_h[1] +
       rtb_VectorConcatenate_f[3 * i] * rtb_MathFunction_h[0]);
  }

  /* End of Product: '<S35>/Multiply1' */
  for (i = 0; i < 3; i++) {
    /* Sum: '<S4>/Sum' incorporates:
     *  Product: '<S35>/Multiply2'
     *  Product: '<S4>/Multiply2'
     */
    rtb_Divide_n_idx_1 = rtb_VectorConcatenate_k[i + 3];
    rtb_Divide_n_idx_2 = rtb_VectorConcatenate_k[i + 6];
    rtb_TrigonometricFunction1_idx_ = ((rtb_Divide_n_idx_1 * rtb_Add_la[1] +
      rtb_VectorConcatenate_k[i] * rtb_Add_la[0]) + rtb_Divide_n_idx_2 *
      rtb_Add_la[2]) + (rtb_Switch2[i] + rtb_VectorConcatenate1_d[i]);

    /* Sum: '<S4>/Add' incorporates:
     *  Constant: '<S32>/Constant'
     *  Inport: '<Root>/Environment_Info'
     *  Product: '<S4>/Multiply'
     *  Product: '<S4>/Multiply1'
     *  Product: '<S4>/Multiply2'
     *  RelationalOperator: '<S32>/Compare'
     */
    rtb_MathFunction_h[i] = (rtb_TrigonometricFunction1_idx_ *
      (rtb_Divide_n_idx_2 * Plant_U.Environment_Info.hit_normal[2] +
       (rtb_Divide_n_idx_1 * Plant_U.Environment_Info.hit_normal[1] +
        rtb_VectorConcatenate_k[i] * Plant_U.Environment_Info.hit_normal[0])) >=
      0.0F ? rtb_TrigonometricFunction1_idx_ : 0.0F) + rtb_Switch[3 + i];
  }

  /* Update for UnitDelay: '<S41>/Delay Input1' incorporates:
   *  Inport: '<Root>/Environment_Info'
   *
   * Block description for '<S41>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Plant_DW.DelayInput1_DSTATE = Plant_U.Environment_Info.timestamp;

  /* End of Outputs for SubSystem: '<Root>/Environment' */

  /* Outputs for Atomic SubSystem: '<Root>/Kinematic_Equation' */
  /* DiscreteIntegrator: '<S65>/Discrete-Time Integrator' */
  if (Plant_DW.DiscreteTimeIntegrator_PrevRese != 0) {
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[0] = Plant_ConstB.quat0[0];
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[1] = Plant_ConstB.quat0[1];
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[2] = Plant_ConstB.quat0[2];
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[3] = Plant_ConstB.quat0[3];
  }

  rtb_Subtract_k_idx_0 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[0];
  rtb_Subtract_k_idx_1 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[1];
  rtb_Subtract_k_idx_2 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[2];
  rtb_Subtract_k_idx_3 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[3];

  /* SignalConversion: '<S70>/ConcatBufferAtMatrix ConcatenateIn1' incorporates:
   *  Constant: '<S70>/Constant'
   */
  rtb_MatrixConcatenate4[0] = 0.0F;

  /* DiscreteIntegrator: '<S61>/Discrete-Time Integrator' */
  if (Plant_DW.DiscreteTimeIntegrator_PrevRe_d != 0) {
    Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2] = 0.0F;
  }

  rtb_Switch1[0] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0];
  rtb_Switch1[1] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1];
  rtb_Switch1[2] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2];

  /* SignalConversion: '<S70>/ConcatBufferAtMatrix ConcatenateIn2' incorporates:
   *  DiscreteIntegrator: '<S61>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[1] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0];

  /* SignalConversion: '<S70>/ConcatBufferAtMatrix ConcatenateIn3' incorporates:
   *  DiscreteIntegrator: '<S61>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[2] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1];

  /* SignalConversion: '<S70>/ConcatBufferAtMatrix ConcatenateIn4' incorporates:
   *  DiscreteIntegrator: '<S61>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[3] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2];

  /* Gain: '<S70>/Gain1' incorporates:
   *  DiscreteIntegrator: '<S61>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[4] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0];

  /* SignalConversion: '<S70>/ConcatBufferAtMatrix Concatenate1In2' incorporates:
   *  Constant: '<S70>/Constant1'
   */
  rtb_MatrixConcatenate4[5] = 0.0F;

  /* Gain: '<S70>/Gain2' incorporates:
   *  DiscreteIntegrator: '<S61>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[6] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2];

  /* SignalConversion: '<S70>/ConcatBufferAtMatrix Concatenate1In4' incorporates:
   *  DiscreteIntegrator: '<S61>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[7] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1];

  /* Gain: '<S70>/Gain3' incorporates:
   *  DiscreteIntegrator: '<S61>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[8] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1];

  /* SignalConversion: '<S70>/ConcatBufferAtMatrix Concatenate2In2' incorporates:
   *  DiscreteIntegrator: '<S61>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[9] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2];

  /* SignalConversion: '<S70>/ConcatBufferAtMatrix Concatenate2In3' incorporates:
   *  Constant: '<S70>/Constant2'
   */
  rtb_MatrixConcatenate4[10] = 0.0F;

  /* Gain: '<S70>/Gain4' incorporates:
   *  DiscreteIntegrator: '<S61>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[11] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0];

  /* Gain: '<S70>/Gain6' incorporates:
   *  DiscreteIntegrator: '<S61>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[12] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2];

  /* Gain: '<S70>/Gain7' incorporates:
   *  DiscreteIntegrator: '<S61>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[13] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1];

  /* SignalConversion: '<S70>/ConcatBufferAtMatrix Concatenate3In3' incorporates:
   *  DiscreteIntegrator: '<S61>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[14] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0];

  /* SignalConversion: '<S70>/ConcatBufferAtMatrix Concatenate3In4' incorporates:
   *  Constant: '<S70>/Constant3'
   */
  rtb_MatrixConcatenate4[15] = 0.0F;

  /* Sqrt: '<S69>/Sqrt' incorporates:
   *  DiscreteIntegrator: '<S65>/Discrete-Time Integrator'
   *  Math: '<S69>/Square'
   *  Sqrt: '<S80>/Sqrt'
   *  Sqrt: '<S85>/Sqrt'
   *  Sum: '<S69>/Sum of Elements'
   */
  rtb_Gain_g2 = sqrtf(((Plant_DW.DiscreteTimeIntegrator_DSTATE_d[0] *
                        Plant_DW.DiscreteTimeIntegrator_DSTATE_d[0] +
                        Plant_DW.DiscreteTimeIntegrator_DSTATE_d[1] *
                        Plant_DW.DiscreteTimeIntegrator_DSTATE_d[1]) +
                       Plant_DW.DiscreteTimeIntegrator_DSTATE_d[2] *
                       Plant_DW.DiscreteTimeIntegrator_DSTATE_d[2]) +
                      Plant_DW.DiscreteTimeIntegrator_DSTATE_d[3] *
                      Plant_DW.DiscreteTimeIntegrator_DSTATE_d[3]);

  /* Product: '<S68>/Divide' incorporates:
   *  DiscreteIntegrator: '<S65>/Discrete-Time Integrator'
   *  Sqrt: '<S69>/Sqrt'
   */
  rtb_TrigonometricFunction1_id_1 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[0] /
    rtb_Gain_g2;
  u0_0 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[1] / rtb_Gain_g2;
  rtb_TrigonometricFunction1_id_0 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[2] /
    rtb_Gain_g2;
  u0 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[3] / rtb_Gain_g2;

  /* Product: '<S76>/Divide' incorporates:
   *  DiscreteIntegrator: '<S65>/Discrete-Time Integrator'
   */
  rtb_Divide_k_idx_0 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[0] / rtb_Gain_g2;
  rtb_Divide_k_idx_1 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[1] / rtb_Gain_g2;
  rtb_Divide_k_idx_2 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[2] / rtb_Gain_g2;
  rtb_Divide_k_idx_3 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[3] / rtb_Gain_g2;

  /* Product: '<S81>/Divide' incorporates:
   *  DiscreteIntegrator: '<S65>/Discrete-Time Integrator'
   */
  rtb_Divide_n_idx_0 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[0] / rtb_Gain_g2;
  rtb_Divide_n_idx_1 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[1] / rtb_Gain_g2;
  rtb_Divide_n_idx_2 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[2] / rtb_Gain_g2;
  u0_1 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[3] / rtb_Gain_g2;

  /* Product: '<S61>/Multiply' incorporates:
   *  Constant: '<S61>/Inertia_Matrix'
   *  DiscreteIntegrator: '<S61>/Discrete-Time Integrator'
   */
  for (i = 0; i < 3; i++) {
    rtb_Add_la[i] = Plant_ConstP.pooled22[i + 6] *
      Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2] + (Plant_ConstP.pooled22[i + 3]
      * Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1] + Plant_ConstP.pooled22[i] *
      Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0]);
  }

  /* End of Product: '<S61>/Multiply' */

  /* Product: '<S66>/Multiply' incorporates:
   *  DiscreteIntegrator: '<S61>/Discrete-Time Integrator'
   */
  rtb_Sum_d[0] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1] * rtb_Add_la[2];

  /* Product: '<S66>/Multiply1' incorporates:
   *  DiscreteIntegrator: '<S61>/Discrete-Time Integrator'
   */
  rtb_Sum_d[1] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2] * rtb_Add_la[0];

  /* Product: '<S66>/Multiply2' incorporates:
   *  DiscreteIntegrator: '<S61>/Discrete-Time Integrator'
   */
  rtb_Sum_d[2] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0] * rtb_Add_la[1];

  /* Product: '<S67>/Multiply3' incorporates:
   *  DiscreteIntegrator: '<S61>/Discrete-Time Integrator'
   */
  rtb_Switch2[0] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2] * rtb_Add_la[1];

  /* Product: '<S67>/Multiply4' incorporates:
   *  DiscreteIntegrator: '<S61>/Discrete-Time Integrator'
   */
  rtb_Switch2[1] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0] * rtb_Add_la[2];

  /* Product: '<S67>/Multiply5' incorporates:
   *  DiscreteIntegrator: '<S61>/Discrete-Time Integrator'
   */
  rtb_Switch2[2] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1] * rtb_Add_la[0];

  /* DiscreteIntegrator: '<S62>/Discrete-Time Integrator' */
  if (Plant_DW.DiscreteTimeIntegrator_PrevRe_k != 0) {
    Plant_DW.DiscreteTimeIntegrator_DSTATE_f[0] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_f[1] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_f[2] = 0.0F;
  }

  /* Product: '<S79>/Product3' incorporates:
   *  Product: '<S76>/Divide'
   *  Product: '<S77>/Product6'
   */
  rtb_Gain_g2 = rtb_Divide_k_idx_2 * rtb_Divide_k_idx_2;

  /* Product: '<S79>/Product6' incorporates:
   *  Product: '<S76>/Divide'
   *  Product: '<S77>/Product9'
   */
  rtb_Add_e_tmp = rtb_Divide_k_idx_1 * rtb_Divide_k_idx_3;

  /* Product: '<S79>/Product7' incorporates:
   *  Product: '<S76>/Divide'
   *  Product: '<S77>/Product2'
   */
  rtb_Add_e_tmp_0 = rtb_Divide_k_idx_0 * rtb_Divide_k_idx_2;

  /* Sum: '<S79>/Sum2' incorporates:
   *  Constant: '<S79>/Constant'
   *  Product: '<S76>/Divide'
   *  Product: '<S79>/Product2'
   *  Sum: '<S78>/Sum1'
   */
  rtb_Sum_c0 = 0.5F - rtb_Divide_k_idx_1 * rtb_Divide_k_idx_1;

  /* Product: '<S79>/Product1' incorporates:
   *  Product: '<S76>/Divide'
   *  Product: '<S78>/Product2'
   */
  rtb_Sum_i = rtb_Divide_k_idx_0 * rtb_Divide_k_idx_1;

  /* Product: '<S79>/Product9' incorporates:
   *  Product: '<S76>/Divide'
   *  Product: '<S78>/Product3'
   */
  rtb_Sum_nb = rtb_Divide_k_idx_2 * rtb_Divide_k_idx_3;

  /* Sum: '<S79>/Sum' incorporates:
   *  DiscreteIntegrator: '<S62>/Discrete-Time Integrator'
   *  Gain: '<S79>/Gain1'
   *  Gain: '<S79>/Gain2'
   *  Gain: '<S79>/Gain3'
   *  Product: '<S79>/Product1'
   *  Product: '<S79>/Product3'
   *  Product: '<S79>/Product4'
   *  Product: '<S79>/Product5'
   *  Product: '<S79>/Product6'
   *  Product: '<S79>/Product7'
   *  Product: '<S79>/Product8'
   *  Product: '<S79>/Product9'
   *  Sum: '<S79>/Sum1'
   *  Sum: '<S79>/Sum2'
   *  Sum: '<S79>/Sum3'
   */
  rtb_TrigonometricFunction1_idx_ = ((rtb_Add_e_tmp + rtb_Add_e_tmp_0) * 2.0F *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_f[0] + (rtb_Sum_nb - rtb_Sum_i) *
    2.0F * Plant_DW.DiscreteTimeIntegrator_DSTATE_f[1]) + (rtb_Sum_c0 -
    rtb_Gain_g2) * 2.0F * Plant_DW.DiscreteTimeIntegrator_DSTATE_f[2];

  /* Product: '<S77>/Product7' incorporates:
   *  Product: '<S76>/Divide'
   *  Product: '<S78>/Product9'
   */
  rtb_Gain_d_tmp = rtb_Divide_k_idx_3 * rtb_Divide_k_idx_3;

  /* Product: '<S77>/Product' incorporates:
   *  Product: '<S76>/Divide'
   *  Product: '<S78>/Product6'
   */
  rtb_Divide_k_idx_1 *= rtb_Divide_k_idx_2;

  /* Product: '<S77>/Product1' incorporates:
   *  Product: '<S76>/Divide'
   *  Product: '<S78>/Product7'
   */
  rtb_Divide_k_idx_0 *= rtb_Divide_k_idx_3;

  /* Sum: '<S77>/Sum' incorporates:
   *  Constant: '<S77>/Constant'
   *  DiscreteIntegrator: '<S62>/Discrete-Time Integrator'
   *  Gain: '<S77>/Gain'
   *  Gain: '<S77>/Gain2'
   *  Gain: '<S77>/Gain3'
   *  Product: '<S77>/Product'
   *  Product: '<S77>/Product1'
   *  Product: '<S77>/Product4'
   *  Product: '<S77>/Product5'
   *  Product: '<S77>/Product7'
   *  Product: '<S77>/Product8'
   *  Sum: '<S77>/Sum1'
   *  Sum: '<S77>/Sum2'
   *  Sum: '<S77>/Sum3'
   */
  rtb_Gain_g2 = (((0.5F - rtb_Gain_g2) - rtb_Gain_d_tmp) * 2.0F *
                 Plant_DW.DiscreteTimeIntegrator_DSTATE_f[0] +
                 (rtb_Divide_k_idx_1 + rtb_Divide_k_idx_0) * 2.0F *
                 Plant_DW.DiscreteTimeIntegrator_DSTATE_f[1]) + (rtb_Add_e_tmp -
    rtb_Add_e_tmp_0) * 2.0F * Plant_DW.DiscreteTimeIntegrator_DSTATE_f[2];

  /* Product: '<S74>/Multiply1' incorporates:
   *  DiscreteIntegrator: '<S61>/Discrete-Time Integrator'
   */
  rtb_Add_la[1] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2] * rtb_Gain_g2;

  /* Product: '<S75>/Multiply5' incorporates:
   *  DiscreteIntegrator: '<S61>/Discrete-Time Integrator'
   */
  rtb_Sum_hq[2] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1] * rtb_Gain_g2;

  /* Sum: '<S78>/Sum' incorporates:
   *  DiscreteIntegrator: '<S62>/Discrete-Time Integrator'
   *  Gain: '<S78>/Gain1'
   *  Gain: '<S78>/Gain2'
   *  Gain: '<S78>/Gain3'
   *  Product: '<S78>/Product4'
   *  Product: '<S78>/Product5'
   *  Product: '<S78>/Product8'
   *  Sum: '<S78>/Sum1'
   *  Sum: '<S78>/Sum2'
   *  Sum: '<S78>/Sum3'
   */
  rtb_Gain_g2 = ((rtb_Sum_c0 - rtb_Gain_d_tmp) * 2.0F *
                 Plant_DW.DiscreteTimeIntegrator_DSTATE_f[1] +
                 (rtb_Divide_k_idx_1 - rtb_Divide_k_idx_0) * 2.0F *
                 Plant_DW.DiscreteTimeIntegrator_DSTATE_f[0]) + (rtb_Sum_i +
    rtb_Sum_nb) * 2.0F * Plant_DW.DiscreteTimeIntegrator_DSTATE_f[2];

  /* DiscreteIntegrator: '<S62>/Discrete-Time Integrator' */
  rtb_Divide2_b[0] = Plant_DW.DiscreteTimeIntegrator_DSTATE_f[0];

  /* Outputs for Atomic SubSystem: '<Root>/Environment' */
  /* Sum: '<S61>/Sum' incorporates:
   *  Sum: '<S4>/Add1'
   *  Sum: '<S63>/Sum'
   */
  rtb_Switch2[0] = (rtb_Sum_c[0] + rtb_Switch[0]) - (rtb_Sum_d[0] - rtb_Switch2
    [0]);

  /* End of Outputs for SubSystem: '<Root>/Environment' */

  /* Sum: '<S62>/Sum' incorporates:
   *  Constant: '<S62>/mass'
   *  DiscreteIntegrator: '<S61>/Discrete-Time Integrator'
   *  Product: '<S62>/Divide'
   *  Product: '<S74>/Multiply'
   *  Product: '<S75>/Multiply3'
   *  Sum: '<S71>/Sum'
   */
  rtb_Sum_hq[0] = rtb_MathFunction_h[0] / 0.886F -
    (Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1] *
     rtb_TrigonometricFunction1_idx_ - Plant_DW.DiscreteTimeIntegrator_DSTATE_e
     [2] * rtb_Gain_g2);

  /* DiscreteIntegrator: '<S62>/Discrete-Time Integrator' */
  rtb_Divide2_b[1] = Plant_DW.DiscreteTimeIntegrator_DSTATE_f[1];

  /* Outputs for Atomic SubSystem: '<Root>/Environment' */
  /* Sum: '<S61>/Sum' incorporates:
   *  Sum: '<S4>/Add1'
   *  Sum: '<S63>/Sum'
   */
  rtb_Switch2[1] = (rtb_Sum_c[1] + rtb_Switch[1]) - (rtb_Sum_d[1] - rtb_Switch2
    [1]);

  /* End of Outputs for SubSystem: '<Root>/Environment' */

  /* Sum: '<S62>/Sum' incorporates:
   *  Constant: '<S62>/mass'
   *  DiscreteIntegrator: '<S61>/Discrete-Time Integrator'
   *  Product: '<S62>/Divide'
   *  Product: '<S75>/Multiply4'
   *  Sum: '<S71>/Sum'
   */
  rtb_Sum_hq[1] = rtb_MathFunction_h[1] / 0.886F - (rtb_Add_la[1] -
    Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0] *
    rtb_TrigonometricFunction1_idx_);

  /* DiscreteIntegrator: '<S62>/Discrete-Time Integrator' */
  rtb_Divide2_b[2] = Plant_DW.DiscreteTimeIntegrator_DSTATE_f[2];

  /* Sum: '<S62>/Sum' incorporates:
   *  Constant: '<S62>/mass'
   *  DiscreteIntegrator: '<S61>/Discrete-Time Integrator'
   *  Product: '<S62>/Divide'
   *  Product: '<S74>/Multiply2'
   *  Sum: '<S71>/Sum'
   */
  rtb_TrigonometricFunction1_idx_ = rtb_MathFunction_h[2] / 0.886F -
    (Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0] * rtb_Gain_g2 - rtb_Sum_hq[2]);

  /* Outputs for Atomic SubSystem: '<Root>/Environment' */
  /* Sum: '<S61>/Sum' incorporates:
   *  Sum: '<S4>/Add1'
   *  Sum: '<S63>/Sum'
   */
  rtb_Switch2[2] = (rtb_Sum_c[2] + rtb_Switch[2]) - (rtb_Sum_d[2] - rtb_Switch2
    [2]);

  /* End of Outputs for SubSystem: '<Root>/Environment' */

  /* Sum: '<S82>/Sum' incorporates:
   *  Constant: '<S82>/Constant'
   *  Gain: '<S82>/Gain'
   *  Gain: '<S82>/Gain1'
   *  Gain: '<S82>/Gain2'
   *  Product: '<S81>/Divide'
   *  Product: '<S82>/Product'
   *  Product: '<S82>/Product1'
   *  Product: '<S82>/Product2'
   *  Product: '<S82>/Product3'
   *  Product: '<S82>/Product4'
   *  Product: '<S82>/Product5'
   *  Product: '<S82>/Product6'
   *  Product: '<S82>/Product7'
   *  Product: '<S82>/Product8'
   *  Sum: '<S82>/Sum1'
   *  Sum: '<S82>/Sum2'
   *  Sum: '<S82>/Sum3'
   */
  rtb_Sum_c0 = (((0.5F - rtb_Divide_n_idx_2 * rtb_Divide_n_idx_2) - u0_1 * u0_1)
                * 2.0F * rtb_Sum_hq[0] + (rtb_Divide_n_idx_1 *
    rtb_Divide_n_idx_2 - rtb_Divide_n_idx_0 * u0_1) * 2.0F * rtb_Sum_hq[1]) +
    (rtb_Divide_n_idx_1 * u0_1 + rtb_Divide_n_idx_0 * rtb_Divide_n_idx_2) * 2.0F
    * rtb_TrigonometricFunction1_idx_;

  /* Sum: '<S83>/Sum' incorporates:
   *  Constant: '<S83>/Constant'
   *  Gain: '<S83>/Gain'
   *  Gain: '<S83>/Gain1'
   *  Gain: '<S83>/Gain2'
   *  Product: '<S81>/Divide'
   *  Product: '<S83>/Product'
   *  Product: '<S83>/Product1'
   *  Product: '<S83>/Product2'
   *  Product: '<S83>/Product3'
   *  Product: '<S83>/Product4'
   *  Product: '<S83>/Product5'
   *  Product: '<S83>/Product6'
   *  Product: '<S83>/Product7'
   *  Product: '<S83>/Product8'
   *  Sum: '<S83>/Sum1'
   *  Sum: '<S83>/Sum2'
   *  Sum: '<S83>/Sum3'
   */
  rtb_Sum_i = (((0.5F - rtb_Divide_n_idx_1 * rtb_Divide_n_idx_1) - u0_1 * u0_1) *
               2.0F * rtb_Sum_hq[1] + (rtb_Divide_n_idx_1 * rtb_Divide_n_idx_2 +
    rtb_Divide_n_idx_0 * u0_1) * 2.0F * rtb_Sum_hq[0]) + (rtb_Divide_n_idx_2 *
    u0_1 - rtb_Divide_n_idx_0 * rtb_Divide_n_idx_1) * 2.0F *
    rtb_TrigonometricFunction1_idx_;

  /* Sum: '<S84>/Sum' incorporates:
   *  Constant: '<S84>/Constant'
   *  Gain: '<S84>/Gain1'
   *  Gain: '<S84>/Gain2'
   *  Gain: '<S84>/Gain3'
   *  Product: '<S81>/Divide'
   *  Product: '<S84>/Product1'
   *  Product: '<S84>/Product2'
   *  Product: '<S84>/Product3'
   *  Product: '<S84>/Product4'
   *  Product: '<S84>/Product5'
   *  Product: '<S84>/Product6'
   *  Product: '<S84>/Product7'
   *  Product: '<S84>/Product8'
   *  Product: '<S84>/Product9'
   *  Sum: '<S84>/Sum1'
   *  Sum: '<S84>/Sum2'
   *  Sum: '<S84>/Sum3'
   */
  rtb_Sum_nb = ((rtb_Divide_n_idx_1 * u0_1 - rtb_Divide_n_idx_0 *
                 rtb_Divide_n_idx_2) * 2.0F * rtb_Sum_hq[0] +
                (rtb_Divide_n_idx_0 * rtb_Divide_n_idx_1 + rtb_Divide_n_idx_2 *
                 u0_1) * 2.0F * rtb_Sum_hq[1]) + ((0.5F - rtb_Divide_n_idx_1 *
    rtb_Divide_n_idx_1) - rtb_Divide_n_idx_2 * rtb_Divide_n_idx_2) * 2.0F *
    rtb_TrigonometricFunction1_idx_;

  /* Math: '<S64>/Square1' incorporates:
   *  Product: '<S68>/Divide'
   */
  rtb_TrigonometricFunction1_idx_ = rtb_TrigonometricFunction1_id_0 *
    rtb_TrigonometricFunction1_id_0;

  /* Product: '<S64>/Multiply6' incorporates:
   *  Constant: '<S64>/Constant'
   *  Product: '<S64>/Multiply4'
   *  Product: '<S64>/Multiply5'
   *  Product: '<S68>/Divide'
   *  Sum: '<S64>/Subtract'
   */
  u0_1 = (rtb_TrigonometricFunction1_id_1 * rtb_TrigonometricFunction1_id_0 - u0
          * u0_0) * 2.0F;

  /* DiscreteIntegrator: '<S62>/Discrete-Time Integrator1' */
  if (Plant_DW.DiscreteTimeIntegrator1_PrevRes != 0) {
    Plant_DW.DiscreteTimeIntegrator1_DSTATE[0] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator1_DSTATE[1] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator1_DSTATE[2] = 0.0F;
  }

  rtb_Add_la[0] = Plant_DW.DiscreteTimeIntegrator1_DSTATE[0];
  rtb_Add_la[1] = Plant_DW.DiscreteTimeIntegrator1_DSTATE[1];
  rtb_Add_la[2] = Plant_DW.DiscreteTimeIntegrator1_DSTATE[2];

  /* End of DiscreteIntegrator: '<S62>/Discrete-Time Integrator1' */

  /* Product: '<S65>/Multiply' incorporates:
   *  DiscreteIntegrator: '<S65>/Discrete-Time Integrator'
   */
  for (i = 0; i < 4; i++) {
    rtb_Divide_n_idx_1 = rtb_MatrixConcatenate4[i + 12] *
      Plant_DW.DiscreteTimeIntegrator_DSTATE_d[3] + (rtb_MatrixConcatenate4[i +
      8] * Plant_DW.DiscreteTimeIntegrator_DSTATE_d[2] +
      (rtb_MatrixConcatenate4[i + 4] * Plant_DW.DiscreteTimeIntegrator_DSTATE_d
       [1] + rtb_MatrixConcatenate4[i] *
       Plant_DW.DiscreteTimeIntegrator_DSTATE_d[0]));
    rtb_MatrixConcatenate4_0[i] = rtb_Divide_n_idx_1;
  }

  /* End of Product: '<S65>/Multiply' */

  /* Update for DiscreteIntegrator: '<S65>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S65>/Gain'
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

  /* Product: '<S61>/Divide' incorporates:
   *  Constant: '<S61>/Inertia_Matrix'
   */
  rt_mldivide_U1f3x3_U2f3x1_Yf3x1(Plant_ConstP.pooled22, rtb_Switch2,
    rtb_VectorConcatenate1_d);

  /* Update for DiscreteIntegrator: '<S61>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_PrevRe_d = 0;

  /* Update for DiscreteIntegrator: '<S62>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_PrevRe_k = 0;

  /* Update for DiscreteIntegrator: '<S61>/Discrete-Time Integrator' incorporates:
   *  Product: '<S61>/Divide'
   */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0] += 0.002F *
    rtb_VectorConcatenate1_d[0];

  /* Update for DiscreteIntegrator: '<S62>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_f[0] += 0.002F * rtb_Sum_c0;

  /* Update for DiscreteIntegrator: '<S62>/Discrete-Time Integrator1' */
  Plant_DW.DiscreteTimeIntegrator1_DSTATE[0] += 0.002F * rtb_Divide2_b[0];

  /* Update for DiscreteIntegrator: '<S61>/Discrete-Time Integrator' incorporates:
   *  Product: '<S61>/Divide'
   */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1] += 0.002F *
    rtb_VectorConcatenate1_d[1];

  /* Update for DiscreteIntegrator: '<S62>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_f[1] += 0.002F * rtb_Sum_i;

  /* Update for DiscreteIntegrator: '<S62>/Discrete-Time Integrator1' */
  Plant_DW.DiscreteTimeIntegrator1_DSTATE[1] += 0.002F * rtb_Divide2_b[1];

  /* Update for DiscreteIntegrator: '<S61>/Discrete-Time Integrator' incorporates:
   *  Product: '<S61>/Divide'
   */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2] += 0.002F *
    rtb_VectorConcatenate1_d[2];

  /* Update for DiscreteIntegrator: '<S62>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_f[2] += 0.002F * rtb_Sum_nb;

  /* Update for DiscreteIntegrator: '<S62>/Discrete-Time Integrator1' */
  Plant_DW.DiscreteTimeIntegrator1_DSTATE[2] += 0.002F * rtb_Divide2_b[2];
  Plant_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* End of Outputs for SubSystem: '<Root>/Kinematic_Equation' */

  /* Outputs for Atomic SubSystem: '<Root>/Bus_Constructor' */
  /* Sqrt: '<S28>/Sqrt' incorporates:
   *  Math: '<S28>/Square'
   *  Sum: '<S28>/Sum of Elements'
   */
  rtb_Gain_g2 = sqrtf(((rtb_Subtract_k_idx_0 * rtb_Subtract_k_idx_0 +
                        rtb_Subtract_k_idx_1 * rtb_Subtract_k_idx_1) +
                       rtb_Subtract_k_idx_2 * rtb_Subtract_k_idx_2) +
                      rtb_Subtract_k_idx_3 * rtb_Subtract_k_idx_3);

  /* Product: '<S24>/Divide' */
  rtb_Divide_n_idx_0 = rtb_Subtract_k_idx_0 / rtb_Gain_g2;
  rtb_Divide_n_idx_1 = rtb_Subtract_k_idx_1 / rtb_Gain_g2;
  rtb_Divide_n_idx_2 = rtb_Subtract_k_idx_2 / rtb_Gain_g2;
  rtb_Gain_g2 = rtb_Subtract_k_idx_3 / rtb_Gain_g2;

  /* Math: '<S25>/Square' incorporates:
   *  Math: '<S26>/Square'
   *  Math: '<S27>/Square'
   */
  rtb_Gain_d_tmp = rtb_Divide_n_idx_0 * rtb_Divide_n_idx_0;

  /* Sum: '<S25>/Subtract' incorporates:
   *  Math: '<S25>/Square'
   *  Math: '<S25>/Square1'
   *  Math: '<S25>/Square2'
   *  Math: '<S25>/Square3'
   *  Sum: '<S25>/Add'
   *  Sum: '<S25>/Add1'
   */
  rtb_MatrixConcatenate1_p[0] = (rtb_Gain_d_tmp + rtb_Divide_n_idx_1 *
    rtb_Divide_n_idx_1) - (rtb_Divide_n_idx_2 * rtb_Divide_n_idx_2 + rtb_Gain_g2
    * rtb_Gain_g2);

  /* Gain: '<S25>/Gain' incorporates:
   *  Product: '<S25>/Multiply'
   *  Product: '<S25>/Multiply1'
   *  Sum: '<S25>/Subtract1'
   */
  rtb_MatrixConcatenate1_p[1] = (rtb_Divide_n_idx_1 * rtb_Divide_n_idx_2 -
    rtb_Divide_n_idx_0 * rtb_Gain_g2) * 2.0F;

  /* Gain: '<S25>/Gain1' incorporates:
   *  Product: '<S25>/Multiply2'
   *  Product: '<S25>/Multiply3'
   *  Sum: '<S25>/Add2'
   */
  rtb_MatrixConcatenate1_p[2] = (rtb_Divide_n_idx_1 * rtb_Gain_g2 +
    rtb_Divide_n_idx_0 * rtb_Divide_n_idx_2) * 2.0F;

  /* Gain: '<S26>/Gain' incorporates:
   *  Product: '<S26>/Multiply'
   *  Product: '<S26>/Multiply1'
   *  Sum: '<S26>/Add3'
   */
  rtb_MatrixConcatenate1_p[3] = (rtb_Divide_n_idx_1 * rtb_Divide_n_idx_2 +
    rtb_Divide_n_idx_0 * rtb_Gain_g2) * 2.0F;

  /* Sum: '<S26>/Subtract' incorporates:
   *  Math: '<S26>/Square1'
   *  Math: '<S26>/Square2'
   *  Math: '<S26>/Square3'
   *  Sum: '<S26>/Add'
   *  Sum: '<S26>/Add1'
   */
  rtb_MatrixConcatenate1_p[4] = (rtb_Gain_d_tmp + rtb_Divide_n_idx_2 *
    rtb_Divide_n_idx_2) - (rtb_Divide_n_idx_1 * rtb_Divide_n_idx_1 + rtb_Gain_g2
    * rtb_Gain_g2);

  /* Gain: '<S26>/Gain1' incorporates:
   *  Product: '<S26>/Multiply2'
   *  Product: '<S26>/Multiply3'
   *  Sum: '<S26>/Subtract1'
   */
  rtb_MatrixConcatenate1_p[5] = (rtb_Divide_n_idx_2 * rtb_Gain_g2 -
    rtb_Divide_n_idx_0 * rtb_Divide_n_idx_1) * 2.0F;

  /* Gain: '<S27>/Gain' incorporates:
   *  Product: '<S27>/Multiply'
   *  Product: '<S27>/Multiply1'
   *  Sum: '<S27>/Subtract2'
   */
  rtb_MatrixConcatenate1_p[6] = (rtb_Divide_n_idx_1 * rtb_Gain_g2 -
    rtb_Divide_n_idx_0 * rtb_Divide_n_idx_2) * 2.0F;

  /* Gain: '<S27>/Gain1' incorporates:
   *  Product: '<S27>/Multiply2'
   *  Product: '<S27>/Multiply3'
   *  Sum: '<S27>/Add2'
   */
  rtb_MatrixConcatenate1_p[7] = (rtb_Divide_n_idx_2 * rtb_Gain_g2 +
    rtb_Divide_n_idx_0 * rtb_Divide_n_idx_1) * 2.0F;

  /* Sum: '<S27>/Subtract' incorporates:
   *  Math: '<S27>/Square1'
   *  Math: '<S27>/Square2'
   *  Math: '<S27>/Square3'
   *  Sum: '<S27>/Add'
   *  Sum: '<S27>/Add1'
   */
  rtb_MatrixConcatenate1_p[8] = (rtb_Gain_d_tmp + rtb_Gain_g2 * rtb_Gain_g2) -
    (rtb_Divide_n_idx_1 * rtb_Divide_n_idx_1 + rtb_Divide_n_idx_2 *
     rtb_Divide_n_idx_2);

  /* Math: '<S2>/Square' */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_f[3 * i] = rtb_MatrixConcatenate1_p[i];
    rtb_VectorConcatenate_f[1 + 3 * i] = rtb_MatrixConcatenate1_p[i + 3];
    rtb_VectorConcatenate_f[2 + 3 * i] = rtb_MatrixConcatenate1_p[i + 6];
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
  Plant_Y.Extended_States.prop_vel[0] = rtb_DiscreteTimeIntegrator_l__2;
  Plant_Y.Extended_States.prop_vel[4] = 0.0F;
  Plant_Y.Extended_States.prop_vel[1] = rtb_DiscreteTimeIntegrator_l__1;
  Plant_Y.Extended_States.prop_vel[5] = 0.0F;
  Plant_Y.Extended_States.prop_vel[2] = rtb_DiscreteTimeIntegrator_l__0;
  Plant_Y.Extended_States.prop_vel[6] = 0.0F;
  Plant_Y.Extended_States.prop_vel[3] = rtb_DiscreteTimeIntegrator_l_id;
  Plant_Y.Extended_States.prop_vel[7] = 0.0F;
  for (i = 0; i < 9; i++) {
    Plant_Y.Extended_States.M_BO[i] = rtb_MatrixConcatenate1_p[i];
    Plant_Y.Extended_States.M_OB[i] = rtb_VectorConcatenate_f[i];
  }

  Plant_Y.Extended_States.quat[0] = rtb_Subtract_k_idx_0;
  Plant_Y.Extended_States.quat[1] = rtb_Subtract_k_idx_1;
  Plant_Y.Extended_States.quat[2] = rtb_Subtract_k_idx_2;
  Plant_Y.Extended_States.quat[3] = rtb_Subtract_k_idx_3;

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
   *  Constant: '<S64>/Constant'
   *  Constant: '<S64>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Math: '<S64>/Square'
   *  Product: '<S64>/Multiply'
   *  Product: '<S64>/Multiply1'
   *  Product: '<S64>/Multiply2'
   *  Product: '<S64>/Multiply3'
   *  Product: '<S68>/Divide'
   *  Sum: '<S64>/Add'
   *  Sum: '<S64>/Add1'
   *  Sum: '<S64>/Subtract2'
   *  Trigonometry: '<S64>/Atan2'
   */
  Plant_Y.Plant_States.phi = atan2f((rtb_TrigonometricFunction1_id_1 * u0_0 +
    rtb_TrigonometricFunction1_id_0 * u0) * 2.0F, 1.0F - (u0_0 * u0_0 +
    rtb_TrigonometricFunction1_idx_) * 2.0F);

  /* End of Outputs for SubSystem: '<Root>/Bus_Constructor' */

  /* Saturate: '<S64>/Saturation' */
  if (u0_1 > 1.0F) {
    u0_1 = 1.0F;
  } else {
    if (u0_1 < -1.0F) {
      u0_1 = -1.0F;
    }
  }

  /* End of Saturate: '<S64>/Saturation' */

  /* Outputs for Atomic SubSystem: '<Root>/Bus_Constructor' */
  /* BusAssignment: '<S2>/Bus Assignment' incorporates:
   *  BusAssignment: '<S2>/Bus Assignment1'
   *  Constant: '<S64>/Constant'
   *  Constant: '<S64>/Constant1'
   *  Delay: '<Root>/Delay'
   *  Math: '<S64>/Square2'
   *  Product: '<S64>/Multiply10'
   *  Product: '<S64>/Multiply7'
   *  Product: '<S64>/Multiply8'
   *  Product: '<S64>/Multiply9'
   *  Product: '<S68>/Divide'
   *  Sum: '<S64>/Add2'
   *  Sum: '<S64>/Add3'
   *  Sum: '<S64>/Subtract1'
   *  Trigonometry: '<S64>/Asin'
   *  Trigonometry: '<S64>/Atan1'
   */
  Plant_Y.Plant_States.theta = asinf(u0_1);
  Plant_Y.Plant_States.psi = atan2f((rtb_TrigonometricFunction1_id_1 * u0 + u0_0
    * rtb_TrigonometricFunction1_id_0) * 2.0F, 1.0F - (u0 * u0 +
    rtb_TrigonometricFunction1_idx_) * 2.0F);

  /* End of Outputs for SubSystem: '<Root>/Kinematic_Equation' */
  Plant_Y.Plant_States.rot_x_B = rtb_Switch1[0];
  Plant_Y.Plant_States.rot_y_B = rtb_Switch1[1];
  Plant_Y.Plant_States.rot_z_B = rtb_Switch1[2];
  Plant_Y.Plant_States.acc_x_O = rtb_Sum_c0;
  Plant_Y.Plant_States.acc_y_O = rtb_Sum_i;
  Plant_Y.Plant_States.acc_z_O = rtb_Sum_nb;
  Plant_Y.Plant_States.vel_x_O = rtb_Divide2_b[0];
  Plant_Y.Plant_States.vel_y_O = rtb_Divide2_b[1];
  Plant_Y.Plant_States.vel_z_O = rtb_Divide2_b[2];

  /* Trigonometry: '<S29>/Trigonometric Function1' incorporates:
   *  Delay: '<S23>/Delay1'
   *  Trigonometry: '<S29>/Trigonometric Function2'
   */
  Sum2_idx_0 = cos(Plant_DW.Delay1_DSTATE[0]);

  /* Trigonometry: '<S29>/Trigonometric Function' incorporates:
   *  Delay: '<S23>/Delay1'
   */
  rtb_SumofElements = sin(Plant_DW.Delay1_DSTATE[0]);

  /* Sum: '<S29>/Subtract' incorporates:
   *  Constant: '<S29>/c'
   *  Math: '<S29>/u^2'
   *  Product: '<S29>/Product'
   */
  rtb_SumofElements = 1.0 - rtb_SumofElements * rtb_SumofElements *
    Plant_ConstB.Product1;

  /* Math: '<S29>/sqrt'
   *
   * About '<S29>/sqrt':
   *  Operator: sqrt
   */
  if (rtb_SumofElements < 0.0) {
    rtb_SumofElements = -sqrt(fabs(rtb_SumofElements));
  } else {
    rtb_SumofElements = sqrt(rtb_SumofElements);
  }

  /* End of Math: '<S29>/sqrt' */

  /* Product: '<S29>/Divide' incorporates:
   *  Constant: '<S29>/earth_radius'
   */
  rtb_SumofElements = 6.378137E+6 / rtb_SumofElements;

  /* Sum: '<S29>/Add' incorporates:
   *  Constant: '<S29>/constant2'
   *  Delay: '<S23>/Delay1'
   *  Math: '<S29>/u^1'
   *  Product: '<S29>/Product2'
   *  Product: '<S29>/Product3'
   *  Sum: '<S29>/Subtract2'
   *  Trigonometry: '<S29>/Trigonometric Function1'
   */
  rtb_SumofElements1 = (1.0 - Sum2_idx_0 * Sum2_idx_0 * Plant_ConstB.Product1) *
    rtb_SumofElements + Plant_DW.Delay1_DSTATE[2];

  /* Sum: '<S29>/Add1' incorporates:
   *  Delay: '<S23>/Delay1'
   */
  rtb_SumofElements += Plant_DW.Delay1_DSTATE[2];

  /* Product: '<S29>/Product4' */
  rtb_SumofElements *= Sum2_idx_0;

  /* BusAssignment: '<S2>/Bus Assignment1' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S2>/Gain'
   */
  Plant_Y.Plant_States.x_R = rtb_Add_la[0];
  Plant_Y.Plant_States.y_R = rtb_Add_la[1];
  Plant_Y.Plant_States.h_R = -rtb_Add_la[2];

  /* Signum: '<S30>/Sign' */
  if (rtb_SumofElements1 < 0.0) {
    Sum2_idx_0 = -1.0;
    Sum2_idx_2 = -1.0;
  } else if (rtb_SumofElements1 > 0.0) {
    Sum2_idx_0 = 1.0;
    Sum2_idx_2 = 1.0;
  } else {
    Sum2_idx_0 = rtb_SumofElements1;
    Sum2_idx_2 = rtb_SumofElements1;
  }

  /* Switch: '<S30>/Switch' incorporates:
   *  Constant: '<S30>/Constant'
   */
  if (Sum2_idx_2 == 0.0) {
    Sum2_idx_0 = 1.0;
  }

  /* Abs: '<S30>/Abs' */
  rtb_SumofElements1 = fabs(rtb_SumofElements1);

  /* Saturate: '<S30>/Saturation' */
  if (rtb_SumofElements1 > 1.0E+8) {
    rtb_SumofElements1 = 1.0E+8;
  } else {
    if (rtb_SumofElements1 < 1.0E-6) {
      rtb_SumofElements1 = 1.0E-6;
    }
  }

  /* Sum: '<S23>/Add' incorporates:
   *  Abs: '<S30>/Abs'
   *  DataTypeConversion: '<S23>/Data Type Conversion'
   *  Delay: '<S23>/Delay'
   *  Delay: '<S23>/Delay1'
   *  Product: '<S23>/Divide'
   *  Product: '<S30>/Product'
   *  Sum: '<S23>/Subtract'
   */
  Plant_DW.Delay1_DSTATE[0] += 1.0 / (rtb_SumofElements1 * Sum2_idx_0) *
    (rtb_Add_la[0] - Plant_DW.Delay_DSTATE_a[0]);

  /* Update for Delay: '<S23>/Delay' incorporates:
   *  DataTypeConversion: '<S23>/Data Type Conversion'
   */
  Plant_DW.Delay_DSTATE_a[0] = rtb_Add_la[0];

  /* Signum: '<S30>/Sign' */
  if (rtb_SumofElements < 0.0) {
    Sum2_idx_0 = -1.0;
    rtb_SumofElements1 = -1.0;
  } else if (rtb_SumofElements > 0.0) {
    Sum2_idx_0 = 1.0;
    rtb_SumofElements1 = 1.0;
  } else {
    Sum2_idx_0 = rtb_SumofElements;
    rtb_SumofElements1 = rtb_SumofElements;
  }

  /* Switch: '<S30>/Switch' incorporates:
   *  Constant: '<S30>/Constant'
   */
  if (rtb_SumofElements1 == 0.0) {
    Sum2_idx_0 = 1.0;
  }

  /* Abs: '<S30>/Abs' */
  rtb_SumofElements1 = fabs(rtb_SumofElements);

  /* Saturate: '<S30>/Saturation' */
  if (rtb_SumofElements1 > 1.0E+8) {
    rtb_SumofElements1 = 1.0E+8;
  } else {
    if (rtb_SumofElements1 < 1.0E-6) {
      rtb_SumofElements1 = 1.0E-6;
    }
  }

  /* Sum: '<S23>/Add' incorporates:
   *  Abs: '<S30>/Abs'
   *  DataTypeConversion: '<S23>/Data Type Conversion'
   *  Delay: '<S23>/Delay'
   *  Delay: '<S23>/Delay1'
   *  Product: '<S23>/Divide'
   *  Product: '<S30>/Product'
   *  Sum: '<S23>/Subtract'
   */
  Plant_DW.Delay1_DSTATE[1] += 1.0 / (rtb_SumofElements1 * Sum2_idx_0) *
    (rtb_Add_la[1] - Plant_DW.Delay_DSTATE_a[1]);

  /* Update for Delay: '<S23>/Delay' incorporates:
   *  DataTypeConversion: '<S23>/Data Type Conversion'
   */
  Plant_DW.Delay_DSTATE_a[1] = rtb_Add_la[1];

  /* Sum: '<S23>/Add' incorporates:
   *  Abs: '<S30>/Abs'
   *  DataTypeConversion: '<S23>/Data Type Conversion'
   *  Delay: '<S23>/Delay'
   *  Delay: '<S23>/Delay1'
   *  Product: '<S23>/Divide'
   *  Sum: '<S23>/Subtract'
   */
  Plant_DW.Delay1_DSTATE[2] += -(rtb_Add_la[2] - Plant_DW.Delay_DSTATE_a[2]);

  /* Update for Delay: '<S23>/Delay' incorporates:
   *  DataTypeConversion: '<S23>/Data Type Conversion'
   */
  Plant_DW.Delay_DSTATE_a[2] = rtb_Add_la[2];

  /* BusAssignment: '<S2>/Bus Assignment1' incorporates:
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant2'
   *  Constant: '<S2>/Constant3'
   *  Delay: '<Root>/Delay'
   *  Delay: '<S21>/Delay'
   *  Delay: '<S23>/Delay1'
   */
  Plant_Y.Plant_States.lat = Plant_DW.Delay1_DSTATE[0];
  Plant_Y.Plant_States.lon = Plant_DW.Delay1_DSTATE[1];
  Plant_Y.Plant_States.alt = Plant_DW.Delay1_DSTATE[2];
  Plant_Y.Plant_States.lat_0 = 0.65673;
  Plant_Y.Plant_States.lon_0 = -2.1361;
  Plant_Y.Plant_States.alt_0 = 4.5;
  Plant_Y.Plant_States.timestamp = Plant_DW.Delay_DSTATE_c;

  /* Sum: '<S21>/Sum' incorporates:
   *  Constant: '<S21>/dt'
   *  Delay: '<S21>/Delay'
   */
  Plant_DW.Delay_DSTATE_c += PLANT_EXPORT.period;

  /* End of Outputs for SubSystem: '<Root>/Bus_Constructor' */

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_Model' */
  /* Outputs for Atomic SubSystem: '<S6>/Sensor_Barometer' */
  /* Saturate: '<S95>/Limit  altitude  to troposhere' incorporates:
   *  DataTypeConversion: '<S93>/Data Type Conversion'
   *  Delay: '<Root>/Delay'
   */
  if ((real32_T)Plant_Y.Plant_States.alt > 11000.0F) {
    rtb_Subtract_k_idx_2 = 11000.0F;
  } else if ((real32_T)Plant_Y.Plant_States.alt < 0.0F) {
    rtb_Subtract_k_idx_2 = 0.0F;
  } else {
    rtb_Subtract_k_idx_2 = (real32_T)Plant_Y.Plant_States.alt;
  }

  /* End of Saturate: '<S95>/Limit  altitude  to troposhere' */

  /* Sum: '<S95>/Sum1' incorporates:
   *  Constant: '<S95>/Sea Level  Temperature'
   *  Gain: '<S95>/Lapse Rate'
   */
  rtb_DiscreteTimeIntegrator_l__2 = 288.15F - 0.0065F * rtb_Subtract_k_idx_2;

  /* Sum: '<S95>/Sum' incorporates:
   *  Constant: '<S95>/Altitude of Troposphere'
   *  DataTypeConversion: '<S93>/Data Type Conversion'
   *  Delay: '<Root>/Delay'
   */
  rtb_DiscreteTimeIntegrator_l__1 = 11000.0F - (real32_T)
    Plant_Y.Plant_States.alt;

  /* Saturate: '<S95>/Limit  altitude  to Stratosphere' incorporates:
   *  Constant: '<S95>/Altitude of Troposphere'
   *  DataTypeConversion: '<S93>/Data Type Conversion'
   *  Delay: '<Root>/Delay'
   *  Sum: '<S95>/Sum'
   */
  if (11000.0F - (real32_T)Plant_Y.Plant_States.alt > 0.0F) {
    rtb_DiscreteTimeIntegrator_l__1 = 0.0F;
  } else {
    if (11000.0F - (real32_T)Plant_Y.Plant_States.alt < -9000.0F) {
      rtb_DiscreteTimeIntegrator_l__1 = -9000.0F;
    }
  }

  /* End of Saturate: '<S95>/Limit  altitude  to Stratosphere' */

  /* Product: '<S95>/Product2' incorporates:
   *  Constant: '<S95>/Constant'
   *  Gain: '<S95>/1//T0'
   *  Gain: '<S95>/P0'
   *  Gain: '<S95>/g//R'
   *  Math: '<S95>/(T//T0)^(g//LR) '
   *  Math: '<S95>/Stratosphere Model'
   *  Product: '<S95>/Product1'
   *
   * About '<S95>/Stratosphere Model':
   *  Operator: exp
   */
  rtb_DiscreteTimeIntegrator_l__0 = powf(0.00347041478F *
    rtb_DiscreteTimeIntegrator_l__2, 5.25587559F) * 101325.0F * expf(1.0F /
    rtb_DiscreteTimeIntegrator_l__2 * (0.0341631919F *
    rtb_DiscreteTimeIntegrator_l__1));

  /* S-Function (sdsprandsrc2): '<S97>/Random Source' */
  RandSrc_GZ_R(&rtb_DiscreteTimeIntegrator_l__1, &Plant_ConstP.pooled14, 1,
               &Plant_ConstP.pooled26, 1, Plant_DW.RandomSource_STATE_DWORK_b, 1,
               1);

  /* BusAssignment: '<S92>/Bus Assignment' incorporates:
   *  Constant: '<S92>/Constant2'
   *  DataTypeConversion: '<S92>/Data Type Conversion1'
   *  Memory: '<S86>/Memory1'
   *  Saturate: '<S94>/Saturation'
   *  Sum: '<S92>/Sum1'
   *  Sum: '<S94>/Add'
   */
  rtb_BusAssignment_i.timestamp = Plant_DW.Memory1_PreviousInput;
  rtb_BusAssignment_i.pressure = rtb_DiscreteTimeIntegrator_l__0 +
    rtb_DiscreteTimeIntegrator_l__1;
  rtb_BusAssignment_i.temperature = (real32_T)(rtb_DiscreteTimeIntegrator_l__2 -
    273.15);

  /* RateTransition: '<S92>/Rate Transition' */
  if (Plant_M->Timing.TaskCounters.TID[1] == 0) {
    Plant_B.RateTransition_m = rtb_BusAssignment_i;
  }

  /* End of RateTransition: '<S92>/Rate Transition' */
  /* End of Outputs for SubSystem: '<S6>/Sensor_Barometer' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_GPS' */
  /* Trigonometry: '<S110>/Sin' incorporates:
   *  Delay: '<S103>/Delay'
   */
  rtb_SumofElements = sin(Plant_DW.Delay_DSTATE[0]);

  /* Math: '<S110>/Square1' */
  rtb_SumofElements *= rtb_SumofElements;

  /* Product: '<S110>/Multiply1' incorporates:
   *  Product: '<S110>/Multiply'
   */
  Sum2_idx_0 = Plant_ConstB.ff * rtb_SumofElements;

  /* Product: '<S110>/Divide' incorporates:
   *  Constant: '<S110>/Constant'
   *  Constant: '<S110>/R'
   *  Sqrt: '<S110>/Sqrt'
   *  Sum: '<S110>/Sum1'
   */
  rtb_SumofElements = 6.378137E+6 / sqrt(1.0 - Sum2_idx_0);

  /* S-Function (sdsprandsrc2): '<S106>/Random Source' */
  RandSrc_GZ_R(rtb_RandomSource, &Plant_ConstP.pooled14, 1,
               Plant_ConstP.RandomSource_VarianceRTP, 3,
               Plant_DW.RandomSource_STATE_DWORK_l, 3, 1);

  /* Sum: '<S104>/Sum2' incorporates:
   *  Constant: '<S110>/Constant1'
   *  Delay: '<S103>/Delay'
   *  Product: '<S107>/Divide2'
   *  Product: '<S110>/Multiply1'
   *  Product: '<S110>/Multiply2'
   *  Product: '<S110>/Product3'
   *  Sum: '<S110>/Sum2'
   *  Trigonometry: '<S110>/Cos'
   */
  Sum2_idx_0 = rtb_RandomSource[0] / (1.0 / (1.0 - Sum2_idx_0) *
    Plant_ConstB.Sum4 * rtb_SumofElements) + Plant_DW.Delay_DSTATE[0];
  rtb_SumofElements1 = rtb_RandomSource[1] / (rtb_SumofElements * cos
    (Plant_DW.Delay_DSTATE[0])) + Plant_DW.Delay_DSTATE[1];
  Sum2_idx_2 = rtb_RandomSource[2] / -1.0 + Plant_DW.Delay_DSTATE[2];

  /* S-Function (sdsprandsrc2): '<S106>/Random Source1' */
  RandSrc_GZ_R(rtb_RandomSource1, &Plant_ConstP.pooled14, 1,
               Plant_ConstP.RandomSource1_VarianceRTP, 3,
               Plant_DW.RandomSource1_STATE_DWORK, 3, 1);

  /* Sum: '<S104>/Sum1' incorporates:
   *  Delay: '<S103>/Delay1'
   */
  rtb_Add_la[0] = rtb_RandomSource1[0] + Plant_DW.Delay1_DSTATE_a[0];
  rtb_Add_la[1] = rtb_RandomSource1[1] + Plant_DW.Delay1_DSTATE_a[1];
  rtb_Add_la[2] = rtb_RandomSource1[2] + Plant_DW.Delay1_DSTATE_a[2];

  /* DiscreteFir: '<S109>/Discrete FIR Filter' */
  rtb_Sum_c[0] = rtb_Add_la[0] * 0.5F + Plant_DW.DiscreteFIRFilter_states_f[0] *
    0.5F;
  rtb_Sum_c[1] = rtb_Add_la[1] * 0.5F + Plant_DW.DiscreteFIRFilter_states_f[1] *
    0.5F;

  /* Gain: '<S98>/Gain6' incorporates:
   *  Math: '<S105>/Math Function'
   *  Product: '<S105>/Matrix Multiply'
   *  Sqrt: '<S105>/Sqrt'
   *  Switch: '<S105>/Switch'
   */
  rtb_SumofElements = fmod(floor(sqrtf(rtb_RandomSource[0] * rtb_RandomSource[0]
    + rtb_RandomSource[1] * rtb_RandomSource[1]) * 1000.0), 4.294967296E+9);

  /* Gain: '<S98>/Gain4' incorporates:
   *  DiscreteFir: '<S108>/Discrete FIR Filter'
   */
  rtb_Product1 = fmod(floor((Sum2_idx_2 * 0.5 +
    Plant_DW.DiscreteFIRFilter_states[2] * 0.5) * 1000.0), 4.294967296E+9);
  i = rtb_Product1 < 0.0 ? -(int32_T)(uint32_T)-rtb_Product1 : (int32_T)
    (uint32_T)rtb_Product1;

  /* Gain: '<S98>/Gain5' incorporates:
   *  Math: '<S105>/Math Function2'
   *  Product: '<S105>/Matrix Multiply2'
   *  Sqrt: '<S105>/Sqrt2'
   *  Switch: '<S105>/Switch1'
   */
  rtb_Product1 = fmod(floor(sqrtf(rtb_RandomSource[2] * rtb_RandomSource[2]) *
    1000.0), 4.294967296E+9);

  /* BusAssignment: '<S98>/Bus Assignment' incorporates:
   *  Constant: '<S98>/Constant10'
   *  Constant: '<S98>/Constant11'
   *  Constant: '<S98>/Constant12'
   *  Constant: '<S98>/Constant2'
   *  Constant: '<S98>/Constant3'
   *  Constant: '<S98>/Constant4'
   *  Constant: '<S98>/Constant5'
   *  Constant: '<S98>/Constant6'
   *  Constant: '<S98>/Constant7'
   *  Constant: '<S98>/Constant8'
   *  Constant: '<S98>/Constant9'
   */
  rtb_BusAssignment_dk.iTOW = 1U;
  rtb_BusAssignment_dk.year = 2020U;
  rtb_BusAssignment_dk.month = 1U;
  rtb_BusAssignment_dk.day = 1U;
  rtb_BusAssignment_dk.hour = 0U;
  rtb_BusAssignment_dk.min = 0U;
  rtb_BusAssignment_dk.sec = 0U;
  rtb_BusAssignment_dk.valid = 1U;
  rtb_BusAssignment_dk.tAcc = 0U;
  rtb_BusAssignment_dk.nano = 0;
  rtb_BusAssignment_dk.fixType = Plant_ConstB.DataTypeConversion;
  rtb_BusAssignment_dk.flags = 0U;
  rtb_BusAssignment_dk.reserved1 = 0U;
  rtb_BusAssignment_dk.numSV = Plant_ConstB.DataTypeConversion1;

  /* Gain: '<S98>/Gain' incorporates:
   *  DiscreteFir: '<S108>/Discrete FIR Filter'
   *  Gain: '<S98>/Gain2'
   */
  rtb_Product1_tmp_idx_2 = fmod(floor((Sum2_idx_0 * 0.5 +
    Plant_DW.DiscreteFIRFilter_states[0] * 0.5) * 57.295779513082323 * 1.0E+7),
    4.294967296E+9);

  /* BusAssignment: '<S98>/Bus Assignment' incorporates:
   *  Gain: '<S98>/Gain'
   */
  rtb_BusAssignment_dk.lon = rtb_Product1_tmp_idx_2 < 0.0 ? -(int32_T)(uint32_T)
    -rtb_Product1_tmp_idx_2 : (int32_T)(uint32_T)rtb_Product1_tmp_idx_2;

  /* Gain: '<S98>/Gain1' incorporates:
   *  DiscreteFir: '<S108>/Discrete FIR Filter'
   *  Gain: '<S98>/Gain3'
   */
  rtb_Product1_tmp_idx_2 = fmod(floor((rtb_SumofElements1 * 0.5 +
    Plant_DW.DiscreteFIRFilter_states[1] * 0.5) * 57.295779513082323 * 1.0E+7),
    4.294967296E+9);

  /* BusAssignment: '<S98>/Bus Assignment' incorporates:
   *  Gain: '<S98>/Gain1'
   *  Gain: '<S98>/Gain5'
   *  Gain: '<S98>/Gain6'
   */
  rtb_BusAssignment_dk.lat = rtb_Product1_tmp_idx_2 < 0.0 ? -(int32_T)(uint32_T)
    -rtb_Product1_tmp_idx_2 : (int32_T)(uint32_T)rtb_Product1_tmp_idx_2;
  rtb_BusAssignment_dk.height = i;
  rtb_BusAssignment_dk.hMSL = i;
  rtb_BusAssignment_dk.hAcc = rtb_SumofElements < 0.0 ? (uint32_T)-(int32_T)
    (uint32_T)-rtb_SumofElements : (uint32_T)rtb_SumofElements;
  rtb_BusAssignment_dk.vAcc = rtb_Product1 < 0.0 ? (uint32_T)-(int32_T)(uint32_T)
    -rtb_Product1 : (uint32_T)rtb_Product1;

  /* Gain: '<S98>/Gain7' */
  rtb_Subtract_k_idx_2 = fmodf(floorf(1000.0F * rtb_Sum_c[0]), 4.2949673E+9F);

  /* BusAssignment: '<S98>/Bus Assignment' incorporates:
   *  Gain: '<S98>/Gain7'
   */
  rtb_BusAssignment_dk.velN = rtb_Subtract_k_idx_2 < 0.0F ? -(int32_T)(uint32_T)
    -rtb_Subtract_k_idx_2 : (int32_T)(uint32_T)rtb_Subtract_k_idx_2;

  /* Gain: '<S98>/Gain8' */
  rtb_Subtract_k_idx_2 = fmodf(floorf(1000.0F * rtb_Sum_c[1]), 4.2949673E+9F);

  /* BusAssignment: '<S98>/Bus Assignment' incorporates:
   *  Gain: '<S98>/Gain8'
   */
  rtb_BusAssignment_dk.velE = rtb_Subtract_k_idx_2 < 0.0F ? -(int32_T)(uint32_T)
    -rtb_Subtract_k_idx_2 : (int32_T)(uint32_T)rtb_Subtract_k_idx_2;

  /* Gain: '<S98>/Gain9' incorporates:
   *  DiscreteFir: '<S109>/Discrete FIR Filter'
   */
  rtb_Subtract_k_idx_2 = fmodf(floorf((rtb_Add_la[2] * 0.5F +
    Plant_DW.DiscreteFIRFilter_states_f[2] * 0.5F) * 1000.0F), 4.2949673E+9F);

  /* BusAssignment: '<S98>/Bus Assignment' incorporates:
   *  Constant: '<S98>/Constant15'
   *  Gain: '<S98>/Gain11'
   *  Gain: '<S98>/Gain9'
   *  Math: '<S100>/Math Function'
   *  Math: '<S100>/Math Function1'
   *  Saturate: '<S100>/Saturation'
   *  Sqrt: '<S100>/Sqrt'
   *  Sum: '<S100>/Add'
   */
  rtb_BusAssignment_dk.velD = rtb_Subtract_k_idx_2 < 0.0F ? -(int32_T)(uint32_T)
    -rtb_Subtract_k_idx_2 : (int32_T)(uint32_T)rtb_Subtract_k_idx_2;
  rtb_BusAssignment_dk.gSpeed = (int32_T)(uint32_T)fmodf(floorf(sqrtf(fmaxf
    (rtb_Sum_c[0] * rtb_Sum_c[0] + rtb_Sum_c[1] * rtb_Sum_c[1], 0.0F)) * 1000.0F),
    4.2949673E+9F);
  rtb_BusAssignment_dk.heading = 0;

  /* Gain: '<S98>/Gain10' incorporates:
   *  Math: '<S105>/Math Function1'
   *  Product: '<S105>/Matrix Multiply1'
   *  Sqrt: '<S105>/Sqrt1'
   *  Switch: '<S105>/Switch2'
   */
  rtb_SumofElements = fmod(floor(sqrtf((rtb_RandomSource1[0] *
    rtb_RandomSource1[0] + rtb_RandomSource1[1] * rtb_RandomSource1[1]) +
    rtb_RandomSource1[2] * rtb_RandomSource1[2]) * 1000.0), 4.294967296E+9);

  /* BusAssignment: '<S98>/Bus Assignment' incorporates:
   *  Constant: '<S98>/Constant14'
   *  Constant: '<S98>/Constant16'
   *  Constant: '<S98>/Constant17'
   *  Gain: '<S98>/Gain10'
   *  Memory: '<S86>/Memory1'
   */
  rtb_BusAssignment_dk.sAcc = rtb_SumofElements < 0.0 ? (uint32_T)-(int32_T)
    (uint32_T)-rtb_SumofElements : (uint32_T)rtb_SumofElements;
  rtb_BusAssignment_dk.headingAcc = 0U;
  rtb_BusAssignment_dk.pDOP = 0U;
  rtb_BusAssignment_dk.reserved2 = 0U;
  rtb_BusAssignment_dk.timestamp = Plant_DW.Memory1_PreviousInput;

  /* RateTransition: '<S98>/Rate Transition' */
  if (Plant_M->Timing.TaskCounters.TID[2] == 0) {
    Plant_B.RateTransition = rtb_BusAssignment_dk;
  }

  /* End of RateTransition: '<S98>/Rate Transition' */

  /* Update for Delay: '<S103>/Delay' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S103>/ConcatBufferAtVector ConcatenateIn1'
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

  /* Update for DiscreteFir: '<S108>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states[0] = Sum2_idx_0;

  /* Update for Delay: '<S103>/Delay' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S103>/ConcatBufferAtVector ConcatenateIn2'
   */
  Plant_DW.Delay_DSTATE[223] = Plant_Y.Plant_States.lat;

  /* Update for DiscreteFir: '<S108>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states[1] = rtb_SumofElements1;

  /* Update for Delay: '<S103>/Delay' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S103>/ConcatBufferAtVector ConcatenateIn3'
   */
  Plant_DW.Delay_DSTATE[224] = Plant_Y.Plant_States.alt;

  /* Update for DiscreteFir: '<S108>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states[2] = Sum2_idx_2;

  /* Update for Delay: '<S103>/Delay1' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S103>/ConcatBufferAtVector Concatenate1In1'
   */
  for (i = 0; i < 49; i++) {
    rtb_Saturation1_idx_1 = (i + 1) * 3;
    Plant_DW.Delay1_DSTATE_a[i * 3] =
      Plant_DW.Delay1_DSTATE_a[rtb_Saturation1_idx_1];
    Plant_DW.Delay1_DSTATE_a[i * 3 + 1] =
      Plant_DW.Delay1_DSTATE_a[rtb_Saturation1_idx_1 + 1];
    Plant_DW.Delay1_DSTATE_a[i * 3 + 2] =
      Plant_DW.Delay1_DSTATE_a[rtb_Saturation1_idx_1 + 2];
  }

  /* Update states */
  Plant_DW.Delay1_DSTATE_a[147] = Plant_Y.Plant_States.vel_x_O;

  /* Update for DiscreteFir: '<S109>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states_f[0] = rtb_Add_la[0];

  /* Update for Delay: '<S103>/Delay1' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S103>/ConcatBufferAtVector Concatenate1In2'
   */
  Plant_DW.Delay1_DSTATE_a[148] = Plant_Y.Plant_States.vel_y_O;

  /* Update for DiscreteFir: '<S109>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states_f[1] = rtb_Add_la[1];

  /* Update for Delay: '<S103>/Delay1' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S103>/ConcatBufferAtVector Concatenate1In3'
   */
  Plant_DW.Delay1_DSTATE_a[149] = Plant_Y.Plant_States.vel_z_O;

  /* Update for DiscreteFir: '<S109>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states_f[2] = rtb_Add_la[2];

  /* End of Outputs for SubSystem: '<S6>/Sensor_GPS' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_IMU' */
  /* Outputs for Atomic SubSystem: '<S115>/Vibration_Model' */
  /* Outputs for Atomic SubSystem: '<S126>/Vibration_Model' */
  /* Product: '<S132>/Divide2' incorporates:
   *  Constant: '<S132>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Product: '<S121>/Divide2'
   */
  Sum2_idx_0 = Plant_Y.Extended_States.prop_vel[0] / 1047.1975511965977;

  /* End of Outputs for SubSystem: '<S115>/Vibration_Model' */

  /* Math: '<S132>/u^2' */
  rtb_Product1 = Sum2_idx_0 * Sum2_idx_0;

  /* Product: '<S128>/Product2' incorporates:
   *  DiscreteIntegrator: '<S128>/Discrete-Time Integrator'
   *  Trigonometry: '<S128>/Trigonometric Function2'
   */
  rtb_SumofElements = arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[0]) *
    rtb_Product1;

  /* Math: '<S132>/u^2' incorporates:
   *  DiscreteIntegrator: '<S128>/Discrete-Time Integrator'
   *  Product: '<S128>/Product1'
   *  Trigonometry: '<S128>/Trigonometric Function1'
   */
  rtb_Product1_idx_0 = arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[0]) *
    rtb_Product1;

  /* Product: '<S132>/Divide2' incorporates:
   *  Constant: '<S132>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Product: '<S121>/Divide2'
   */
  rtb_SumofElements1 = Sum2_idx_0;

  /* Outputs for Atomic SubSystem: '<S115>/Vibration_Model' */
  Sum2_idx_0 = Plant_Y.Extended_States.prop_vel[1] / 1047.1975511965977;

  /* End of Outputs for SubSystem: '<S115>/Vibration_Model' */

  /* Math: '<S132>/u^2' */
  rtb_Product1 = Sum2_idx_0 * Sum2_idx_0;

  /* Product: '<S128>/Product2' incorporates:
   *  DiscreteIntegrator: '<S128>/Discrete-Time Integrator'
   *  Trigonometry: '<S128>/Trigonometric Function2'
   */
  rtb_Product2_g_idx_1 = arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[1]) *
    rtb_Product1;

  /* Math: '<S132>/u^2' incorporates:
   *  DiscreteIntegrator: '<S128>/Discrete-Time Integrator'
   *  Product: '<S128>/Product1'
   *  Trigonometry: '<S128>/Trigonometric Function1'
   */
  rtb_Product1_idx_1 = arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[1]) *
    rtb_Product1;

  /* Product: '<S132>/Divide2' incorporates:
   *  Constant: '<S132>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Product: '<S121>/Divide2'
   */
  Sum2_idx_2 = Sum2_idx_0;

  /* Outputs for Atomic SubSystem: '<S115>/Vibration_Model' */
  Sum2_idx_0 = Plant_Y.Extended_States.prop_vel[2] / 1047.1975511965977;

  /* End of Outputs for SubSystem: '<S115>/Vibration_Model' */

  /* Math: '<S132>/u^2' */
  rtb_Product1 = Sum2_idx_0 * Sum2_idx_0;

  /* Product: '<S132>/Divide2' incorporates:
   *  Constant: '<S132>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Product: '<S121>/Divide2'
   */
  rtb_Product1_tmp_idx_2 = Sum2_idx_0;

  /* Outputs for Atomic SubSystem: '<S115>/Vibration_Model' */
  Sum2_idx_0 = Plant_Y.Extended_States.prop_vel[3] / 1047.1975511965977;

  /* Math: '<S132>/u^2' incorporates:
   *  Math: '<S121>/u^2'
   */
  Sum2_idx_0 *= Sum2_idx_0;

  /* End of Outputs for SubSystem: '<S115>/Vibration_Model' */

  /* Sum: '<S128>/Sum of Elements' incorporates:
   *  DiscreteIntegrator: '<S128>/Discrete-Time Integrator'
   *  Math: '<S132>/u^2'
   *  Product: '<S128>/Product2'
   *  Trigonometry: '<S128>/Trigonometric Function2'
   */
  rtb_SumofElements = ((rtb_SumofElements + rtb_Product2_g_idx_1) + arm_sin_f32
                       (Plant_DW.DiscreteTimeIntegrator_DSTATE[2]) *
                       rtb_Product1) + arm_sin_f32
    (Plant_DW.DiscreteTimeIntegrator_DSTATE[3]) * Sum2_idx_0;

  /* Sum: '<S128>/Sum of Elements1' incorporates:
   *  DiscreteIntegrator: '<S128>/Discrete-Time Integrator'
   *  Math: '<S132>/u^2'
   *  Product: '<S128>/Product1'
   *  Trigonometry: '<S128>/Trigonometric Function1'
   */
  rtb_Product1 = ((rtb_Product1_idx_0 + rtb_Product1_idx_1) + arm_cos_f32
                  (Plant_DW.DiscreteTimeIntegrator_DSTATE[2]) * rtb_Product1) +
    arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[3]) * Sum2_idx_0;

  /* Outputs for Atomic SubSystem: '<S115>/Vibration_Model' */
  /* Update for DiscreteIntegrator: '<S128>/Discrete-Time Integrator' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S117>/Discrete-Time Integrator'
   */
  rtb_DiscreteTimeIntegrator_l_id = 0.002F * Plant_Y.Extended_States.prop_vel[0];

  /* End of Outputs for SubSystem: '<S115>/Vibration_Model' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE[0] += rtb_DiscreteTimeIntegrator_l_id;

  /* End of Outputs for SubSystem: '<S126>/Vibration_Model' */
  /* End of Outputs for SubSystem: '<S6>/Sensor_IMU' */
  /* End of Outputs for SubSystem: '<Root>/Sensor_Model' */
  rtb_DiscreteTimeIntegrator_l__2 = rtb_DiscreteTimeIntegrator_l_id;

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_Model' */
  /* Outputs for Atomic SubSystem: '<S6>/Sensor_IMU' */
  /* Outputs for Atomic SubSystem: '<S115>/Vibration_Model' */
  /* Outputs for Atomic SubSystem: '<S126>/Vibration_Model' */
  /* Update for DiscreteIntegrator: '<S128>/Discrete-Time Integrator' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S117>/Discrete-Time Integrator'
   */
  rtb_DiscreteTimeIntegrator_l_id = 0.002F * Plant_Y.Extended_States.prop_vel[1];

  /* End of Outputs for SubSystem: '<S115>/Vibration_Model' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE[1] += rtb_DiscreteTimeIntegrator_l_id;

  /* End of Outputs for SubSystem: '<S126>/Vibration_Model' */
  /* End of Outputs for SubSystem: '<S6>/Sensor_IMU' */
  /* End of Outputs for SubSystem: '<Root>/Sensor_Model' */
  rtb_DiscreteTimeIntegrator_l__1 = rtb_DiscreteTimeIntegrator_l_id;

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_Model' */
  /* Outputs for Atomic SubSystem: '<S6>/Sensor_IMU' */
  /* Outputs for Atomic SubSystem: '<S115>/Vibration_Model' */
  /* Outputs for Atomic SubSystem: '<S126>/Vibration_Model' */
  /* Update for DiscreteIntegrator: '<S128>/Discrete-Time Integrator' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S117>/Discrete-Time Integrator'
   */
  rtb_DiscreteTimeIntegrator_l_id = 0.002F * Plant_Y.Extended_States.prop_vel[2];

  /* End of Outputs for SubSystem: '<S115>/Vibration_Model' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE[2] += rtb_DiscreteTimeIntegrator_l_id;

  /* End of Outputs for SubSystem: '<S126>/Vibration_Model' */
  /* End of Outputs for SubSystem: '<S6>/Sensor_IMU' */
  /* End of Outputs for SubSystem: '<Root>/Sensor_Model' */
  rtb_DiscreteTimeIntegrator_l__0 = rtb_DiscreteTimeIntegrator_l_id;

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_Model' */
  /* Outputs for Atomic SubSystem: '<S6>/Sensor_IMU' */
  /* Outputs for Atomic SubSystem: '<S115>/Vibration_Model' */
  /* Outputs for Atomic SubSystem: '<S126>/Vibration_Model' */
  /* Update for DiscreteIntegrator: '<S128>/Discrete-Time Integrator' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S117>/Discrete-Time Integrator'
   */
  rtb_DiscreteTimeIntegrator_l_id = 0.002F * Plant_Y.Extended_States.prop_vel[3];

  /* End of Outputs for SubSystem: '<S115>/Vibration_Model' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE[3] += rtb_DiscreteTimeIntegrator_l_id;

  /* Switch: '<S126>/Switch' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S128>/Gain2'
   *  Gain: '<S128>/Gain4'
   *  Product: '<S128>/Divide'
   *  SignalConversion: '<S130>/ConcatBufferAtVector ConcatenateIn1'
   *  SignalConversion: '<S130>/ConcatBufferAtVector ConcatenateIn2'
   *  SignalConversion: '<S130>/ConcatBufferAtVector ConcatenateIn3'
   *  Sum: '<S126>/Sum'
   *  Sum: '<S128>/Sum'
   *  Sum: '<S128>/Sum of Elements'
   *  Sum: '<S128>/Sum of Elements1'
   */
  rtb_Sum_c[0] = (real32_T)(rtb_SumofElements / 4.0 * 0.5 +
    Plant_Y.Plant_States.rot_x_B);
  rtb_Sum_c[1] = (real32_T)(rtb_Product1 / 4.0 * 0.5 +
    Plant_Y.Plant_States.rot_y_B);
  rtb_Divide_n_idx_1 = (real32_T)((rtb_SumofElements + rtb_Product1) * 0.5 / 4.0
    * 0.5 + Plant_Y.Plant_States.rot_z_B);

  /* End of Outputs for SubSystem: '<S126>/Vibration_Model' */

  /* Sum: '<S134>/Sum' incorporates:
   *  Product: '<S134>/Product'
   */
  for (i = 0; i < 3; i++) {
    rtb_RandomSource[i] = (Plant_ConstB.Add_g[i + 3] * rtb_Sum_c[1] +
      Plant_ConstB.Add_g[i] * rtb_Sum_c[0]) + Plant_ConstB.Add_g[i + 6] *
      rtb_Divide_n_idx_1;
  }

  /* End of Sum: '<S134>/Sum' */

  /* DiscreteIntegrator: '<S133>/Discrete-Time Integrator5' */
  if (Plant_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[0] = rtb_RandomSource[0];
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[1] = rtb_RandomSource[1];
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[2] = rtb_RandomSource[2];
  }

  /* S-Function (sdsprandsrc2): '<S124>/Random Source' */
  RandSrc_GZ_R(rtb_RandomSource_f, &Plant_ConstP.pooled14, 1,
               Plant_ConstP.RandomSource_VarianceRTP_f, 3,
               Plant_DW.RandomSource_STATE_DWORK_k, 3, 1);

  /* S-Function (sdsprandsrc2): '<S135>/Random Source' */
  RandSrc_GZ_R(rtb_Sum_d, &Plant_ConstP.pooled14, 1,
               Plant_ConstP.RandomSource_VarianceRTP_b, 3,
               Plant_DW.RandomSource_STATE_DWORK_h, 3, 1);

  /* Saturate: '<S127>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S133>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[0] > 34.9065857F) {
    rtb_Subtract_k_idx_2 = 34.9065857F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[0] < -34.9065857F) {
    rtb_Subtract_k_idx_2 = -34.9065857F;
  } else {
    rtb_Subtract_k_idx_2 = Plant_DW.DiscreteTimeIntegrator5_DSTATE[0];
  }

  /* Sum: '<S127>/Sum' */
  rtb_Add_la[0] = rtb_Subtract_k_idx_2 + rtb_Sum_d[0];

  /* Saturate: '<S127>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S133>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[1] > 34.9065857F) {
    rtb_Subtract_k_idx_2 = 34.9065857F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[1] < -34.9065857F) {
    rtb_Subtract_k_idx_2 = -34.9065857F;
  } else {
    rtb_Subtract_k_idx_2 = Plant_DW.DiscreteTimeIntegrator5_DSTATE[1];
  }

  /* Sum: '<S127>/Sum' */
  rtb_Add_la[1] = rtb_Subtract_k_idx_2 + rtb_Sum_d[1];

  /* Saturate: '<S127>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S133>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[2] > 34.9065857F) {
    rtb_Subtract_k_idx_2 = 34.9065857F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[2] < -34.9065857F) {
    rtb_Subtract_k_idx_2 = -34.9065857F;
  } else {
    rtb_Subtract_k_idx_2 = Plant_DW.DiscreteTimeIntegrator5_DSTATE[2];
  }

  /* Sum: '<S127>/Sum' */
  rtb_Add_la[2] = rtb_Subtract_k_idx_2 + rtb_Sum_d[2];

  /* Outputs for Atomic SubSystem: '<S115>/Vibration_Model' */
  /* Math: '<S121>/u^2' incorporates:
   *  Product: '<S121>/Divide2'
   */
  rtb_Product1 = rtb_SumofElements1 * rtb_SumofElements1;

  /* Product: '<S117>/Product2' incorporates:
   *  DiscreteIntegrator: '<S117>/Discrete-Time Integrator'
   *  Trigonometry: '<S117>/Trigonometric Function2'
   */
  rtb_SumofElements = arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_p[0]) *
    rtb_Product1;

  /* Math: '<S121>/u^2' incorporates:
   *  DiscreteIntegrator: '<S117>/Discrete-Time Integrator'
   *  Product: '<S117>/Product1'
   *  Product: '<S121>/Divide2'
   *  Trigonometry: '<S117>/Trigonometric Function1'
   */
  rtb_Product1_idx_0 = arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_p[0]) *
    rtb_Product1;
  rtb_Product1 = Sum2_idx_2 * Sum2_idx_2;

  /* Product: '<S117>/Product2' incorporates:
   *  DiscreteIntegrator: '<S117>/Discrete-Time Integrator'
   *  Trigonometry: '<S117>/Trigonometric Function2'
   */
  rtb_Product2_g_idx_1 = arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_p[1])
    * rtb_Product1;

  /* Math: '<S121>/u^2' incorporates:
   *  DiscreteIntegrator: '<S117>/Discrete-Time Integrator'
   *  Product: '<S117>/Product1'
   *  Product: '<S121>/Divide2'
   *  Trigonometry: '<S117>/Trigonometric Function1'
   */
  rtb_Product1_idx_1 = arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_p[1]) *
    rtb_Product1;
  rtb_Product1 = rtb_Product1_tmp_idx_2 * rtb_Product1_tmp_idx_2;

  /* Sum: '<S117>/Sum of Elements' incorporates:
   *  DiscreteIntegrator: '<S117>/Discrete-Time Integrator'
   *  Product: '<S117>/Product2'
   *  Trigonometry: '<S117>/Trigonometric Function2'
   */
  rtb_SumofElements = ((rtb_SumofElements + rtb_Product2_g_idx_1) + arm_sin_f32
                       (Plant_DW.DiscreteTimeIntegrator_DSTATE_p[2]) *
                       rtb_Product1) + arm_sin_f32
    (Plant_DW.DiscreteTimeIntegrator_DSTATE_p[3]) * Sum2_idx_0;

  /* SignalConversion: '<S117>/ConcatBufferAtVector ConcatenateIn1' incorporates:
   *  Sum: '<S117>/Sum of Elements'
   */
  rtb_Divide2[0] = rtb_SumofElements;

  /* Sum: '<S117>/Sum of Elements1' incorporates:
   *  DiscreteIntegrator: '<S117>/Discrete-Time Integrator'
   *  Product: '<S117>/Product1'
   *  Trigonometry: '<S117>/Trigonometric Function1'
   */
  rtb_Product1 = ((rtb_Product1_idx_0 + rtb_Product1_idx_1) + arm_cos_f32
                  (Plant_DW.DiscreteTimeIntegrator_DSTATE_p[2]) * rtb_Product1)
    + arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_p[3]) * Sum2_idx_0;

  /* SignalConversion: '<S117>/ConcatBufferAtVector ConcatenateIn2' incorporates:
   *  Sum: '<S117>/Sum of Elements1'
   */
  rtb_Divide2[1] = rtb_Product1;

  /* Gain: '<S117>/Gain2' incorporates:
   *  Sum: '<S117>/Sum'
   *  Sum: '<S117>/Sum of Elements'
   *  Sum: '<S117>/Sum of Elements1'
   */
  rtb_Divide2[2] = (rtb_SumofElements + rtb_Product1) * 0.5;

  /* Update for DiscreteIntegrator: '<S117>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_p[0] += rtb_DiscreteTimeIntegrator_l__2;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_p[1] += rtb_DiscreteTimeIntegrator_l__1;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_p[2] += rtb_DiscreteTimeIntegrator_l__0;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_p[3] += rtb_DiscreteTimeIntegrator_l_id;

  /* End of Outputs for SubSystem: '<S115>/Vibration_Model' */

  /* Switch: '<S115>/Switch' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S117>/Gain4'
   *  Product: '<S117>/Divide'
   *  Product: '<S119>/Product1'
   *  SignalConversion: '<S119>/ConcatBufferAtVector Concatenate1In1'
   *  SignalConversion: '<S119>/ConcatBufferAtVector Concatenate1In2'
   *  SignalConversion: '<S119>/ConcatBufferAtVector Concatenate1In3'
   *  Sum: '<S115>/Sum'
   *  Sum: '<S119>/Sum'
   */
  for (i = 0; i < 3; i++) {
    /* Outputs for Atomic SubSystem: '<S115>/Vibration_Model' */
    rtb_Sum_d[i] = (real32_T)(((Plant_Y.Extended_States.M_BO[i + 3] *
      Plant_Y.Plant_States.acc_y_O + Plant_Y.Extended_States.M_BO[i] *
      Plant_Y.Plant_States.acc_x_O) + Plant_Y.Extended_States.M_BO[i + 6] *
      (Plant_Y.Plant_States.acc_z_O - 9.80665F)) + rtb_Divide2[i] / 4.0 *
      Plant_ConstP.Gain4_Gain[i]);

    /* End of Outputs for SubSystem: '<S115>/Vibration_Model' */
  }

  /* End of Switch: '<S115>/Switch' */

  /* Sum: '<S123>/Sum' incorporates:
   *  Product: '<S123>/Product'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate1_d[i] = (Plant_ConstB.Add_m[i + 3] * rtb_Sum_d[1] +
      Plant_ConstB.Add_m[i] * rtb_Sum_d[0]) + Plant_ConstB.Add_m[i + 6] *
      rtb_Sum_d[2];
  }

  /* End of Sum: '<S123>/Sum' */

  /* DiscreteIntegrator: '<S122>/Discrete-Time Integrator5' */
  if (Plant_DW.DiscreteTimeIntegrator5_IC_LO_j != 0) {
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[0] = rtb_VectorConcatenate1_d[0];
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[1] = rtb_VectorConcatenate1_d[1];
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[2] = rtb_VectorConcatenate1_d[2];
  }

  /* Outport: '<Root>/IMU' incorporates:
   *  BusAssignment: '<S112>/Bus Assignment'
   *  Memory: '<S86>/Memory1'
   */
  Plant_Y.IMU.timestamp = Plant_DW.Memory1_PreviousInput;
  Plant_Y.IMU.gyr_x = rtb_Add_la[0];
  Plant_Y.IMU.gyr_y = rtb_Add_la[1];
  Plant_Y.IMU.gyr_z = rtb_Add_la[2];

  /* Update for DiscreteIntegrator: '<S133>/Discrete-Time Integrator5' */
  Plant_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;

  /* Update for DiscreteIntegrator: '<S122>/Discrete-Time Integrator5' */
  Plant_DW.DiscreteTimeIntegrator5_IC_LO_j = 0U;

  /* End of Outputs for SubSystem: '<S6>/Sensor_IMU' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_MAG' */
  /* Gain: '<S141>/rad_to_index' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S141>/TmpSignal ConversionAtrad_to_indexInport1'
   */
  rtb_SumofElements = fmod(floor(5.7295779513082321 * Plant_Y.Plant_States.lat),
    4.294967296E+9);

  /* Sum: '<S141>/Add' incorporates:
   *  Gain: '<S141>/rad_to_index'
   */
  i = (rtb_SumofElements < 0.0 ? -(int32_T)(uint32_T)-rtb_SumofElements :
       (int32_T)(uint32_T)rtb_SumofElements) + 8;

  /* Saturate: '<S141>/Saturation1' */
  if (i > 16) {
    i = 16;
  } else {
    if (i < 0) {
      i = 0;
    }
  }

  /* Gain: '<S141>/rad_to_index' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S141>/TmpSignal ConversionAtrad_to_indexInport1'
   */
  rtb_SumofElements = fmod(floor(5.7295779513082321 * Plant_Y.Plant_States.lon),
    4.294967296E+9);

  /* Sum: '<S141>/Add' incorporates:
   *  Gain: '<S141>/rad_to_index'
   */
  rtb_Saturation1_idx_1 = (rtb_SumofElements < 0.0 ? -(int32_T)(uint32_T)
    -rtb_SumofElements : (int32_T)(uint32_T)rtb_SumofElements) + 18;

  /* Saturate: '<S141>/Saturation1' */
  if (rtb_Saturation1_idx_1 > 36) {
    rtb_Saturation1_idx_1 = 36;
  } else {
    if (rtb_Saturation1_idx_1 < 0) {
      rtb_Saturation1_idx_1 = 0;
    }
  }

  /* LookupNDDirect: '<S141>/Declination_Lookup_Table' incorporates:
   *  LookupNDDirect: '<S141>/Inclination_Lookup_Table'
   *  LookupNDDirect: '<S141>/Magnitude_Lookup_Table'
   *
   * About '<S141>/Declination_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   *
   * About '<S141>/Inclination_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   *
   * About '<S141>/Magnitude_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  i += rtb_Saturation1_idx_1 * 17;

  /* Gain: '<S142>/Gain1' incorporates:
   *  LookupNDDirect: '<S141>/Declination_Lookup_Table'
   *
   * About '<S141>/Declination_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  rtb_DiscreteTimeIntegrator_l__2 =
    Plant_ConstP.Declination_Lookup_Table_table[i] * 0.0174532924F;

  /* Trigonometry: '<S144>/Trigonometric Function1' incorporates:
   *  Trigonometry: '<S144>/Trigonometric Function3'
   */
  rtb_Divide_n_idx_1 = arm_cos_f32(rtb_DiscreteTimeIntegrator_l__2);
  rtb_VectorConcatenate_f[0] = rtb_Divide_n_idx_1;

  /* Trigonometry: '<S144>/Trigonometric Function' incorporates:
   *  Trigonometry: '<S144>/Trigonometric Function2'
   */
  rtb_Divide_n_idx_2 = arm_sin_f32(rtb_DiscreteTimeIntegrator_l__2);
  rtb_VectorConcatenate_f[1] = rtb_Divide_n_idx_2;

  /* SignalConversion: '<S144>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S144>/Constant3'
   */
  rtb_VectorConcatenate_f[2] = 0.0F;

  /* Gain: '<S144>/Gain' */
  rtb_VectorConcatenate_f[3] = -rtb_Divide_n_idx_2;

  /* Trigonometry: '<S144>/Trigonometric Function3' */
  rtb_VectorConcatenate_f[4] = rtb_Divide_n_idx_1;

  /* SignalConversion: '<S144>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S144>/Constant4'
   */
  rtb_VectorConcatenate_f[5] = 0.0F;

  /* Gain: '<S142>/Gain' incorporates:
   *  LookupNDDirect: '<S141>/Inclination_Lookup_Table'
   *
   * About '<S141>/Inclination_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  rtb_DiscreteTimeIntegrator_l__2 =
    Plant_ConstP.Inclination_Lookup_Table_table[i] * -0.0174532924F;

  /* Trigonometry: '<S143>/Trigonometric Function3' incorporates:
   *  Trigonometry: '<S143>/Trigonometric Function1'
   */
  rtb_DiscreteTimeIntegrator_l_id = arm_cos_f32(rtb_DiscreteTimeIntegrator_l__2);
  rtb_VectorConcatenate_k[0] = rtb_DiscreteTimeIntegrator_l_id;

  /* SignalConversion: '<S143>/ConcatBufferAtVector Concatenate2In2' incorporates:
   *  Constant: '<S143>/Constant4'
   */
  rtb_VectorConcatenate_k[1] = 0.0F;

  /* Trigonometry: '<S143>/Trigonometric Function2' incorporates:
   *  Trigonometry: '<S143>/Trigonometric Function'
   */
  rtb_Divide_n_idx_1 = arm_sin_f32(rtb_DiscreteTimeIntegrator_l__2);

  /* Gain: '<S143>/Gain' incorporates:
   *  Trigonometry: '<S143>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_k[2] = -rtb_Divide_n_idx_1;

  /* End of Outputs for SubSystem: '<S6>/Sensor_MAG' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_IMU' */
  /* Saturate: '<S116>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S122>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[0] > 78.4532F) {
    rtb_DiscreteTimeIntegrator_l__2 = 78.4532F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[0] < -78.4532F) {
    rtb_DiscreteTimeIntegrator_l__2 = -78.4532F;
  } else {
    rtb_DiscreteTimeIntegrator_l__2 = Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[0];
  }

  /* Update for DiscreteIntegrator: '<S133>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S133>/Gain'
   *  Sum: '<S133>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTATE[0] += (rtb_RandomSource[0] -
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 314.159271F * 0.002F;

  /* Update for DiscreteIntegrator: '<S122>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S122>/Gain'
   *  Sum: '<S122>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[0] += (rtb_VectorConcatenate1_d[0] -
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[0]) * 314.159271F * 0.002F;

  /* End of Outputs for SubSystem: '<S6>/Sensor_IMU' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_MAG' */
  /* SignalConversion: '<S144>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_f[6] = Plant_ConstB.VectorConcatenate3[0];

  /* SignalConversion: '<S143>/ConcatBufferAtVector ConcatenateIn2' */
  rtb_VectorConcatenate_k[3] = Plant_ConstB.VectorConcatenate3_a[0];

  /* End of Outputs for SubSystem: '<S6>/Sensor_MAG' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_IMU' */
  /* Saturate: '<S116>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S122>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[1] > 78.4532F) {
    rtb_DiscreteTimeIntegrator_l__1 = 78.4532F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[1] < -78.4532F) {
    rtb_DiscreteTimeIntegrator_l__1 = -78.4532F;
  } else {
    rtb_DiscreteTimeIntegrator_l__1 = Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[1];
  }

  /* Update for DiscreteIntegrator: '<S133>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S133>/Gain'
   *  Sum: '<S133>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTATE[1] += (rtb_RandomSource[1] -
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 314.159271F * 0.002F;

  /* Update for DiscreteIntegrator: '<S122>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S122>/Gain'
   *  Sum: '<S122>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[1] += (rtb_VectorConcatenate1_d[1] -
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[1]) * 314.159271F * 0.002F;

  /* End of Outputs for SubSystem: '<S6>/Sensor_IMU' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_MAG' */
  /* SignalConversion: '<S144>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_f[7] = Plant_ConstB.VectorConcatenate3[1];

  /* SignalConversion: '<S143>/ConcatBufferAtVector ConcatenateIn2' */
  rtb_VectorConcatenate_k[4] = Plant_ConstB.VectorConcatenate3_a[1];

  /* End of Outputs for SubSystem: '<S6>/Sensor_MAG' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_IMU' */
  /* Saturate: '<S116>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S122>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[2] > 78.4532F) {
    rtb_DiscreteTimeIntegrator_l__0 = 78.4532F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[2] < -78.4532F) {
    rtb_DiscreteTimeIntegrator_l__0 = -78.4532F;
  } else {
    rtb_DiscreteTimeIntegrator_l__0 = Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[2];
  }

  /* Update for DiscreteIntegrator: '<S133>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S133>/Gain'
   *  Sum: '<S133>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTATE[2] += (rtb_RandomSource[2] -
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 314.159271F * 0.002F;

  /* Update for DiscreteIntegrator: '<S122>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S122>/Gain'
   *  Sum: '<S122>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[2] += (rtb_VectorConcatenate1_d[2] -
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[2]) * 314.159271F * 0.002F;

  /* End of Outputs for SubSystem: '<S6>/Sensor_IMU' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_MAG' */
  /* SignalConversion: '<S144>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_f[8] = Plant_ConstB.VectorConcatenate3[2];

  /* SignalConversion: '<S143>/ConcatBufferAtVector ConcatenateIn2' */
  rtb_VectorConcatenate_k[5] = Plant_ConstB.VectorConcatenate3_a[2];

  /* Trigonometry: '<S143>/Trigonometric Function' */
  rtb_VectorConcatenate_k[6] = rtb_Divide_n_idx_1;

  /* SignalConversion: '<S143>/ConcatBufferAtVector Concatenate1In2' incorporates:
   *  Constant: '<S143>/Constant3'
   */
  rtb_VectorConcatenate_k[7] = 0.0F;

  /* Trigonometry: '<S143>/Trigonometric Function1' */
  rtb_VectorConcatenate_k[8] = rtb_DiscreteTimeIntegrator_l_id;

  /* Gain: '<S142>/toGauss' incorporates:
   *  LookupNDDirect: '<S141>/Magnitude_Lookup_Table'
   *
   * About '<S141>/Magnitude_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  rtb_DiscreteTimeIntegrator_l_id = Plant_ConstP.Magnitude_Lookup_Table_table[i]
    * 0.01F;

  /* Product: '<S142>/Multiply1' incorporates:
   *  Product: '<S142>/Multiply'
   */
  for (i = 0; i < 3; i++) {
    rtb_Switch2[i] = rtb_VectorConcatenate_k[i] *
      rtb_DiscreteTimeIntegrator_l_id;
  }

  /* End of Product: '<S142>/Multiply1' */

  /* Product: '<S142>/Multiply2' */
  for (i = 0; i < 3; i++) {
    rtb_Add_la[i] = rtb_VectorConcatenate_f[i + 6] * rtb_Switch2[2] +
      (rtb_VectorConcatenate_f[i + 3] * rtb_Switch2[1] +
       rtb_VectorConcatenate_f[i] * rtb_Switch2[0]);
  }

  /* End of Product: '<S142>/Multiply2' */

  /* Product: '<S139>/Product' incorporates:
   *  Delay: '<Root>/Delay'
   */
  for (i = 0; i < 3; i++) {
    rtb_Sum_c[i] = Plant_Y.Extended_States.M_BO[i + 6] * rtb_Add_la[2] +
      (Plant_Y.Extended_States.M_BO[i + 3] * rtb_Add_la[1] +
       Plant_Y.Extended_States.M_BO[i] * rtb_Add_la[0]);
  }

  /* End of Product: '<S139>/Product' */
  for (i = 0; i < 3; i++) {
    /* Sum: '<S145>/Sum' incorporates:
     *  Product: '<S145>/Product'
     */
    rtb_Subtract_k_idx_2 = (Plant_ConstB.Add[i + 3] * rtb_Sum_c[1] +
      Plant_ConstB.Add[i] * rtb_Sum_c[0]) + Plant_ConstB.Add[i + 6] * rtb_Sum_c
      [2];

    /* Saturate: '<S140>/Saturation' incorporates:
     *  Sum: '<S145>/Sum'
     */
    if (rtb_Subtract_k_idx_2 > 4.0F) {
      rtb_Add_la[i] = 4.0F;
    } else if (rtb_Subtract_k_idx_2 < -4.0F) {
      rtb_Add_la[i] = -4.0F;
    } else {
      rtb_Add_la[i] = rtb_Subtract_k_idx_2;
    }

    /* End of Saturate: '<S140>/Saturation' */
  }

  /* S-Function (sdsprandsrc2): '<S146>/Random Source' */
  RandSrc_GZ_R(rtb_Sum_c, &Plant_ConstP.pooled14, 1,
               Plant_ConstP.RandomSource_VarianceRTP_a, 3,
               Plant_DW.RandomSource_STATE_DWORK, 3, 1);

  /* Sum: '<S140>/Add' */
  rtb_Add_la[0] += rtb_Sum_c[0];
  rtb_Add_la[1] += rtb_Sum_c[1];

  /* BusAssignment: '<S136>/Bus Assignment' incorporates:
   *  Memory: '<S86>/Memory1'
   *  Sum: '<S140>/Add'
   */
  rtb_BusAssignment_o.timestamp = Plant_DW.Memory1_PreviousInput;
  rtb_BusAssignment_o.mag_x = rtb_Add_la[0];
  rtb_BusAssignment_o.mag_y = rtb_Add_la[1];
  rtb_BusAssignment_o.mag_z = rtb_Add_la[2] + rtb_Sum_c[2];

  /* RateTransition: '<S136>/Rate Transition' */
  if (Plant_M->Timing.TaskCounters.TID[1] == 0) {
    Plant_B.RateTransition_b = rtb_BusAssignment_o;
  }

  /* End of RateTransition: '<S136>/Rate Transition' */
  /* End of Outputs for SubSystem: '<S6>/Sensor_MAG' */

  /* Update for Memory: '<S86>/Memory1' incorporates:
   *  Constant: '<S86>/dt'
   *  Sum: '<S86>/Sum'
   */
  Plant_DW.Memory1_PreviousInput += PLANT_EXPORT.period;

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_IMU' */
  /* Outport: '<Root>/IMU' incorporates:
   *  Sum: '<S116>/Sum'
   */
  Plant_Y.IMU.acc_x = rtb_DiscreteTimeIntegrator_l__2 + rtb_RandomSource_f[0];
  Plant_Y.IMU.acc_y = rtb_DiscreteTimeIntegrator_l__1 + rtb_RandomSource_f[1];
  Plant_Y.IMU.acc_z = rtb_DiscreteTimeIntegrator_l__0 + rtb_RandomSource_f[2];

  /* End of Outputs for SubSystem: '<S6>/Sensor_IMU' */
  /* End of Outputs for SubSystem: '<Root>/Sensor_Model' */
  if (Plant_M->Timing.TaskCounters.TID[1] == 0) {
    /* Outport: '<Root>/MAG' */
    Plant_Y.MAG = Plant_B.RateTransition_b;

    /* Outport: '<Root>/Barometer' */
    Plant_Y.Barometer = Plant_B.RateTransition_m;
  }

  if (Plant_M->Timing.TaskCounters.TID[2] == 0) {
    /* Outport: '<Root>/GPS' */
    Plant_Y.GPS = Plant_B.RateTransition;
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
    uint32_T RandomSource_SEED_DWORK_k;

    /* ConstCode for Outport: '<Root>/Airspeed' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    Plant_Y.Airspeed = Plant_rtZAirSpeed_Bus;

    /* SystemInitialize for Atomic SubSystem: '<Root>/Kinematic_Equation' */
    /* InitializeConditions for DiscreteIntegrator: '<S65>/Discrete-Time Integrator' */
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[0] = Plant_ConstB.quat0[0];
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[1] = Plant_ConstB.quat0[1];
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[2] = Plant_ConstB.quat0[2];
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[3] = Plant_ConstB.quat0[3];
    Plant_DW.DiscreteTimeIntegrator_PrevRese = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S61>/Discrete-Time Integrator' */
    Plant_DW.DiscreteTimeIntegrator_PrevRe_d = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S62>/Discrete-Time Integrator' */
    Plant_DW.DiscreteTimeIntegrator_PrevRe_k = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S62>/Discrete-Time Integrator1' */
    Plant_DW.DiscreteTimeIntegrator1_PrevRes = 0;

    /* End of SystemInitialize for SubSystem: '<Root>/Kinematic_Equation' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Bus_Constructor' */
    /* InitializeConditions for Delay: '<S23>/Delay1' */
    Plant_DW.Delay1_DSTATE[0] = 0.65673;
    Plant_DW.Delay1_DSTATE[1] = -2.1361;
    Plant_DW.Delay1_DSTATE[2] = 4.5;

    /* End of SystemInitialize for SubSystem: '<Root>/Bus_Constructor' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Sensor_Model' */
    /* SystemInitialize for Atomic SubSystem: '<S6>/Sensor_Barometer' */
    /* InitializeConditions for S-Function (sdsprandsrc2): '<S97>/Random Source' */
    RandomSource_SEED_DWORK_k = 91337U;
    RandSrcInitState_GZ(&RandomSource_SEED_DWORK_k,
                        Plant_DW.RandomSource_STATE_DWORK_b, 1);

    /* End of SystemInitialize for SubSystem: '<S6>/Sensor_Barometer' */

    /* SystemInitialize for Atomic SubSystem: '<S6>/Sensor_GPS' */
    /* InitializeConditions for S-Function (sdsprandsrc2): '<S106>/Random Source' */
    RandSrcCreateSeeds_32(63235U, Plant_DW.RandomSource_SEED_DWORK_m, 3);
    RandSrcInitState_GZ(Plant_DW.RandomSource_SEED_DWORK_m,
                        Plant_DW.RandomSource_STATE_DWORK_l, 3);

    /* InitializeConditions for DiscreteFir: '<S108>/Discrete FIR Filter' */
    Plant_DW.DiscreteFIRFilter_states[0] = 0.0;
    Plant_DW.DiscreteFIRFilter_states[1] = 0.0;
    Plant_DW.DiscreteFIRFilter_states[2] = 0.0;

    /* InitializeConditions for S-Function (sdsprandsrc2): '<S106>/Random Source1' */
    RandSrcCreateSeeds_32(9754U, Plant_DW.RandomSource1_SEED_DWORK, 3);
    RandSrcInitState_GZ(Plant_DW.RandomSource1_SEED_DWORK,
                        Plant_DW.RandomSource1_STATE_DWORK, 3);

    /* InitializeConditions for DiscreteFir: '<S109>/Discrete FIR Filter' */
    Plant_DW.DiscreteFIRFilter_states_f[0] = 0.0F;
    Plant_DW.DiscreteFIRFilter_states_f[1] = 0.0F;
    Plant_DW.DiscreteFIRFilter_states_f[2] = 0.0F;

    /* End of SystemInitialize for SubSystem: '<S6>/Sensor_GPS' */

    /* SystemInitialize for Atomic SubSystem: '<S6>/Sensor_IMU' */
    /* InitializeConditions for DiscreteIntegrator: '<S133>/Discrete-Time Integrator5' */
    Plant_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

    /* InitializeConditions for S-Function (sdsprandsrc2): '<S124>/Random Source' */
    RandSrcCreateSeeds_32(90579U, Plant_DW.RandomSource_SEED_DWORK_f, 3);
    RandSrcInitState_GZ(Plant_DW.RandomSource_SEED_DWORK_f,
                        Plant_DW.RandomSource_STATE_DWORK_k, 3);

    /* InitializeConditions for S-Function (sdsprandsrc2): '<S135>/Random Source' */
    RandSrcCreateSeeds_32(81472U, Plant_DW.RandomSource_SEED_DWORK_n, 3);
    RandSrcInitState_GZ(Plant_DW.RandomSource_SEED_DWORK_n,
                        Plant_DW.RandomSource_STATE_DWORK_h, 3);

    /* InitializeConditions for DiscreteIntegrator: '<S122>/Discrete-Time Integrator5' */
    Plant_DW.DiscreteTimeIntegrator5_IC_LO_j = 1U;

    /* End of SystemInitialize for SubSystem: '<S6>/Sensor_IMU' */

    /* SystemInitialize for Atomic SubSystem: '<S6>/Sensor_MAG' */
    /* InitializeConditions for S-Function (sdsprandsrc2): '<S146>/Random Source' */
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
