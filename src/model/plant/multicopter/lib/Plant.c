/*
 * File: Plant.c
 *
 * Code generated for Simulink model 'Plant'.
 *
 * Model version                  : 1.1197
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Apr  6 18:01:02 2024
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
                                        *   '<S23>/Constant1'
                                        *   '<S23>/Constant2'
                                        *   '<S23>/Constant3'
                                        */

struct_zjTVXoT1Wcig2PfNqPD1gB PLANT_EXPORT = {
  2U,

  { 77, 117, 108, 116, 105, 99, 111, 112, 116, 101, 114, 32, 118, 49, 46, 48, 46,
    48, 0 }
} ;                                    /* Variable: PLANT_EXPORT
                                        * Referenced by:
                                        *   '<S21>/dt'
                                        *   '<S97>/dt'
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

  /* S-Function (sdsprandsrc2): '<S108>/Random Source' */
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

  /* End of S-Function (sdsprandsrc2): '<S108>/Random Source' */
}

void RandSrcInitState_GZ(const uint32_T seed[], uint32_T state[], int32_T nChans)
{
  int32_T i;
  int32_T tmp;

  /* InitializeConditions for S-Function (sdsprandsrc2): '<S108>/Random Source' */
  /* RandSrcInitState_GZ */
  for (i = 0; i < nChans; i++) {
    tmp = i << 1;
    state[tmp] = 362436069U;
    state[tmp + 1] = seed[i] == 0U ? 521288629U : seed[i];
  }

  /* End of InitializeConditions for S-Function (sdsprandsrc2): '<S108>/Random Source' */
}

void RandSrcInitState_U_32(const uint32_T seed[], real32_T state[], int32_T
  nChans)
{
  int32_T i;
  uint32_T j;
  int32_T k;
  int32_T n;
  real32_T d;

  /* InitializeConditions for S-Function (sdsprandsrc2): '<S117>/Random Source' */
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

  /* End of InitializeConditions for S-Function (sdsprandsrc2): '<S117>/Random Source' */
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

  /* InitializeConditions for S-Function (sdsprandsrc2): '<S117>/Random Source' */
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

  /* End of InitializeConditions for S-Function (sdsprandsrc2): '<S117>/Random Source' */
}

void RandSrcCreateSeeds_32(uint32_T initSeed, uint32_T seedArray[], int32_T
  numSeeds)
{
  real32_T state[35];
  real32_T tmp;
  real32_T min;
  real32_T max;
  int32_T i;

  /* InitializeConditions for S-Function (sdsprandsrc2): '<S117>/Random Source' */
  /* RandSrcCreateSeeds_32 */
  min = 0.0F;
  max = 1.0F;
  RandSrcInitState_U_32(&initSeed, state, 1);
  for (i = 0; i < numSeeds; i++) {
    RandSrc_U_R(&tmp, &min, 1, &max, 1, state, 1, 1);
    seedArray[i] = (uint32_T)(tmp * 2.14748365E+9F);
  }

  /* End of InitializeConditions for S-Function (sdsprandsrc2): '<S117>/Random Source' */
}

/* Model step function */
void Plant_step(void)
{
  real32_T rtb_Divide_g[4];
  real32_T rtb_Square_h[3];
  real32_T rtb_Gain_h;
  real32_T rtb_Multiply5_i[3];
  real32_T rtb_Sum_hq[3];
  real32_T rtb_Sum_b[3];
  real32_T rtb_VectorConcatenate_f[9];
  real32_T rtb_Multiply2_p[3];
  real32_T rtb_MathFunction[3];
  real32_T rtb_Add_la[3];
  real32_T rtb_Sum_p[3];
  real32_T rtb_Add_e;
  real32_T rtb_MathFunction1_c;
  real32_T rtb_Product8;
  real32_T rtb_MatrixConcatenate4[16];
  real32_T rtb_Sum_mo[3];
  real32_T rtb_DiscreteTimeIntegrator1[3];
  real32_T rtb_MatrixConcatenate1[9];
  real_T rtb_DataTypeConversion[3];
  real_T rtb_SumofElements;
  real_T rtb_SumofElements1;
  Barometer_Bus rtb_BusAssignment_i;
  GPS_uBlox_Bus rtb_BusAssignment_dk;
  real32_T rtb_VectorConcatenate_k[9];
  MAG_Bus rtb_BusAssignment_o;
  real32_T rtb_RandomSource[3];
  real32_T rtb_RandomSource1[3];
  int32_T i;
  real32_T tmp[3];
  real32_T rtb_Square_g;
  real32_T rtb_Switch;
  real32_T rtb_Multiply4_b;
  real_T rtb_Product1;
  real32_T rtb_DiscreteTimeIntegrator_l_id;
  boolean_T rtb_Compare_o_idx_3;
  real32_T rtb_DiscreteTimeIntegrator_l__0;
  boolean_T rtb_Compare_o_idx_2;
  real32_T rtb_DiscreteTimeIntegrator_l__1;
  boolean_T rtb_Compare_o_idx_1;
  real32_T rtb_DiscreteTimeIntegrator_l__2;
  boolean_T rtb_Compare_o_idx_0;
  real_T rtb_Product1_idx_1;
  real_T rtb_Product1_idx_0;
  real_T rtb_Product2_g_idx_1;
  real_T rtb_Divide2_idx_1;
  real_T rtb_Divide2_idx_0;
  real_T rtb_Add_idx_1;
  real32_T rtb_Multiply4_i_idx_1;
  real32_T rtb_Multiply4_i_idx_0;
  real32_T rtb_Divide_f_idx_2;
  real32_T rtb_Divide_f_idx_1;
  real32_T rtb_Divide_f_idx_0;
  real32_T rtb_Switch_idx_3;
  real32_T rtb_Switch_idx_2;
  real32_T rtb_Switch_idx_1;
  real32_T rtb_Switch_idx_0;
  int32_T rtb_Saturation1_idx_1;
  uint16_T tmp_0;
  real32_T rtb_Gain_d_tmp;
  real32_T rtb_Divide_f_idx_3;
  real32_T rtb_Gain_d_tmp_0;
  real32_T rtb_Gain_d_tmp_1;
  real32_T rtb_Gain_d_tmp_2;
  real32_T rtb_Gain_d_tmp_3;
  real32_T rtb_Gain_d_tmp_4;
  real32_T rtb_Gain_d_tmp_5;
  real32_T rtb_Gain_d_tmp_6;
  real32_T rtb_Gain_d_tmp_7;
  real32_T rtb_Sum_i_tmp;
  real32_T rtb_Sum_mx_tmp;

  /* Delay: '<Root>/Delay' */
  rtb_Add_e = Plant_Y.Plant_States.vel_x_O;
  rtb_MathFunction1_c = Plant_Y.Plant_States.vel_y_O;
  rtb_Product8 = Plant_Y.Plant_States.vel_z_O;
  for (i = 0; i < 9; i++) {
    rtb_VectorConcatenate_k[i] = Plant_Y.Extended_States.M_BO[i];
  }

  /* Outputs for Atomic SubSystem: '<Root>/Actuators' */
  /* Saturate: '<S9>/Saturation' incorporates:
   *  Inport: '<Root>/Control_Out'
   */
  if (Plant_U.Control_Out.actuator_cmd[0] > 2000) {
    tmp_0 = 2000U;
  } else if (Plant_U.Control_Out.actuator_cmd[0] < 1000) {
    tmp_0 = 1000U;
  } else {
    tmp_0 = Plant_U.Control_Out.actuator_cmd[0];
  }

  /* Gain: '<S9>/Gain' incorporates:
   *  Sum: '<S9>/Subtract'
   */
  rtb_Multiply4_i_idx_0 = ((real32_T)tmp_0 - 1000.0F) * 0.000999987125F;

  /* RelationalOperator: '<S14>/Compare' incorporates:
   *  Constant: '<S14>/Constant'
   */
  rtb_Compare_o_idx_0 = (rtb_Multiply4_i_idx_0 > 0.1F);

  /* Gain: '<S9>/Gain' incorporates:
   *  Constant: '<S13>/Constant1'
   *  Gain: '<S13>/Gain1'
   *  Sum: '<S13>/Add'
   */
  rtb_Divide_g[0] = 718.078F * rtb_Multiply4_i_idx_0 + 88.448F;

  /* DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */
  rtb_DiscreteTimeIntegrator_l__2 = Plant_DW.DiscreteTimeIntegrator_DSTATE_n[0];

  /* Math: '<S15>/Square' incorporates:
   *  DiscreteIntegrator: '<S12>/Discrete-Time Integrator'
   *  Math: '<S17>/Square'
   */
  rtb_Switch = Plant_DW.DiscreteTimeIntegrator_DSTATE_n[0] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_n[0];

  /* Product: '<S15>/Multiply' incorporates:
   *  Constant: '<S15>/cT'
   */
  rtb_Divide_f_idx_0 = (real32_T)(rtb_Switch * 1.239E-5);

  /* Math: '<S15>/Square' */
  rtb_Switch_idx_0 = rtb_Switch;

  /* Saturate: '<S9>/Saturation' incorporates:
   *  Inport: '<Root>/Control_Out'
   */
  if (Plant_U.Control_Out.actuator_cmd[1] > 2000) {
    tmp_0 = 2000U;
  } else if (Plant_U.Control_Out.actuator_cmd[1] < 1000) {
    tmp_0 = 1000U;
  } else {
    tmp_0 = Plant_U.Control_Out.actuator_cmd[1];
  }

  /* Gain: '<S9>/Gain' incorporates:
   *  Sum: '<S9>/Subtract'
   */
  rtb_Multiply4_i_idx_0 = ((real32_T)tmp_0 - 1000.0F) * 0.000999987125F;

  /* RelationalOperator: '<S14>/Compare' incorporates:
   *  Constant: '<S14>/Constant'
   */
  rtb_Compare_o_idx_1 = (rtb_Multiply4_i_idx_0 > 0.1F);

  /* Gain: '<S9>/Gain' incorporates:
   *  Constant: '<S13>/Constant1'
   *  Gain: '<S13>/Gain1'
   *  Sum: '<S13>/Add'
   */
  rtb_Divide_g[1] = 718.078F * rtb_Multiply4_i_idx_0 + 88.448F;

  /* DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */
  rtb_DiscreteTimeIntegrator_l__1 = Plant_DW.DiscreteTimeIntegrator_DSTATE_n[1];

  /* Math: '<S15>/Square' incorporates:
   *  DiscreteIntegrator: '<S12>/Discrete-Time Integrator'
   *  Math: '<S17>/Square'
   */
  rtb_Switch = Plant_DW.DiscreteTimeIntegrator_DSTATE_n[1] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_n[1];

  /* Product: '<S15>/Multiply' incorporates:
   *  Constant: '<S15>/cT'
   */
  rtb_Divide_f_idx_1 = (real32_T)(rtb_Switch * 1.239E-5);

  /* Math: '<S15>/Square' */
  rtb_Switch_idx_1 = rtb_Switch;

  /* Saturate: '<S9>/Saturation' incorporates:
   *  Inport: '<Root>/Control_Out'
   */
  if (Plant_U.Control_Out.actuator_cmd[2] > 2000) {
    tmp_0 = 2000U;
  } else if (Plant_U.Control_Out.actuator_cmd[2] < 1000) {
    tmp_0 = 1000U;
  } else {
    tmp_0 = Plant_U.Control_Out.actuator_cmd[2];
  }

  /* Gain: '<S9>/Gain' incorporates:
   *  Sum: '<S9>/Subtract'
   */
  rtb_Multiply4_i_idx_0 = ((real32_T)tmp_0 - 1000.0F) * 0.000999987125F;

  /* RelationalOperator: '<S14>/Compare' incorporates:
   *  Constant: '<S14>/Constant'
   */
  rtb_Compare_o_idx_2 = (rtb_Multiply4_i_idx_0 > 0.1F);

  /* Gain: '<S9>/Gain' incorporates:
   *  Constant: '<S13>/Constant1'
   *  Gain: '<S13>/Gain1'
   *  Sum: '<S13>/Add'
   */
  rtb_Divide_g[2] = 718.078F * rtb_Multiply4_i_idx_0 + 88.448F;

  /* DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */
  rtb_DiscreteTimeIntegrator_l__0 = Plant_DW.DiscreteTimeIntegrator_DSTATE_n[2];

  /* Math: '<S15>/Square' incorporates:
   *  DiscreteIntegrator: '<S12>/Discrete-Time Integrator'
   *  Math: '<S17>/Square'
   */
  rtb_Switch = Plant_DW.DiscreteTimeIntegrator_DSTATE_n[2] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_n[2];

  /* Product: '<S15>/Multiply' incorporates:
   *  Constant: '<S15>/cT'
   */
  rtb_Divide_f_idx_2 = (real32_T)(rtb_Switch * 1.239E-5);

  /* Math: '<S15>/Square' */
  rtb_Switch_idx_2 = rtb_Switch;

  /* Saturate: '<S9>/Saturation' incorporates:
   *  Inport: '<Root>/Control_Out'
   */
  if (Plant_U.Control_Out.actuator_cmd[3] > 2000) {
    tmp_0 = 2000U;
  } else if (Plant_U.Control_Out.actuator_cmd[3] < 1000) {
    tmp_0 = 1000U;
  } else {
    tmp_0 = Plant_U.Control_Out.actuator_cmd[3];
  }

  /* Gain: '<S9>/Gain' incorporates:
   *  Sum: '<S9>/Subtract'
   */
  rtb_Multiply4_i_idx_0 = ((real32_T)tmp_0 - 1000.0F) * 0.000999987125F;

  /* RelationalOperator: '<S14>/Compare' incorporates:
   *  Constant: '<S14>/Constant'
   */
  rtb_Compare_o_idx_3 = (rtb_Multiply4_i_idx_0 > 0.1F);

  /* Sum: '<S13>/Add' incorporates:
   *  Constant: '<S13>/Constant1'
   *  Gain: '<S13>/Gain1'
   */
  rtb_Multiply4_i_idx_0 = 718.078F * rtb_Multiply4_i_idx_0 + 88.448F;

  /* DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */
  rtb_DiscreteTimeIntegrator_l_id = Plant_DW.DiscreteTimeIntegrator_DSTATE_n[3];

  /* Math: '<S15>/Square' incorporates:
   *  DiscreteIntegrator: '<S12>/Discrete-Time Integrator'
   *  Math: '<S17>/Square'
   */
  rtb_Switch = Plant_DW.DiscreteTimeIntegrator_DSTATE_n[3] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_n[3];

  /* Sum: '<S16>/Add' incorporates:
   *  DiscreteIntegrator: '<S12>/Discrete-Time Integrator'
   */
  rtb_Gain_h = ((Plant_DW.DiscreteTimeIntegrator_DSTATE_n[2] -
                 Plant_DW.DiscreteTimeIntegrator_DSTATE_n[0]) -
                Plant_DW.DiscreteTimeIntegrator_DSTATE_n[1]) +
    Plant_DW.DiscreteTimeIntegrator_DSTATE_n[3];

  /* Product: '<S19>/Multiply' */
  rtb_Sum_hq[0] = 0.0F;

  /* Product: '<S19>/Multiply1' incorporates:
   *  Delay: '<Root>/Delay'
   *  Product: '<S16>/Multiply'
   */
  rtb_Sum_hq[1] = rtb_Gain_h * Plant_Y.Plant_States.rot_x_B * 0.0001287F;

  /* Product: '<S19>/Multiply2' */
  rtb_Sum_hq[2] = 0.0F;

  /* Product: '<S20>/Multiply3' incorporates:
   *  Delay: '<Root>/Delay'
   *  Product: '<S16>/Multiply'
   */
  rtb_Sum_b[0] = rtb_Gain_h * Plant_Y.Plant_States.rot_y_B * 0.0001287F;

  /* Product: '<S20>/Multiply4' */
  rtb_Sum_b[1] = 0.0F;

  /* Product: '<S20>/Multiply5' */
  rtb_Sum_b[2] = 0.0F;

  /* Update for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S12>/Gain'
   *  Product: '<S13>/Multiply'
   *  Saturate: '<S13>/Saturation1'
   *  Sum: '<S12>/Subtract'
   */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_n[0] += ((rtb_Compare_o_idx_0 ?
    rtb_Divide_g[0] : 0.0F) - Plant_DW.DiscreteTimeIntegrator_DSTATE_n[0]) *
    50.0F * 0.002F;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_n[1] += ((rtb_Compare_o_idx_1 ?
    rtb_Divide_g[1] : 0.0F) - Plant_DW.DiscreteTimeIntegrator_DSTATE_n[1]) *
    50.0F * 0.002F;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_n[2] += ((rtb_Compare_o_idx_2 ?
    rtb_Divide_g[2] : 0.0F) - Plant_DW.DiscreteTimeIntegrator_DSTATE_n[2]) *
    50.0F * 0.002F;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_n[3] += ((rtb_Compare_o_idx_3 ?
    rtb_Multiply4_i_idx_0 : 0.0F) - Plant_DW.DiscreteTimeIntegrator_DSTATE_n[3])
    * 50.0F * 0.002F;

  /* End of Outputs for SubSystem: '<Root>/Actuators' */

  /* Outputs for Atomic SubSystem: '<Root>/Environment' */
  /* Trigonometry: '<S42>/Trigonometric Function1' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S41>/Gain'
   *  Trigonometry: '<S42>/Trigonometric Function3'
   */
  rtb_Multiply4_i_idx_0 = arm_cos_f32(-Plant_Y.Plant_States.psi);
  rtb_VectorConcatenate_f[0] = rtb_Multiply4_i_idx_0;

  /* Trigonometry: '<S42>/Trigonometric Function' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S41>/Gain'
   *  Trigonometry: '<S42>/Trigonometric Function2'
   */
  rtb_Multiply4_i_idx_1 = arm_sin_f32(-Plant_Y.Plant_States.psi);
  rtb_VectorConcatenate_f[1] = rtb_Multiply4_i_idx_1;

  /* SignalConversion: '<S42>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S42>/Constant3'
   */
  rtb_VectorConcatenate_f[2] = 0.0F;

  /* Gain: '<S42>/Gain' */
  rtb_VectorConcatenate_f[3] = -rtb_Multiply4_i_idx_1;

  /* Trigonometry: '<S42>/Trigonometric Function3' */
  rtb_VectorConcatenate_f[4] = rtb_Multiply4_i_idx_0;

  /* SignalConversion: '<S42>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S42>/Constant4'
   */
  rtb_VectorConcatenate_f[5] = 0.0F;

  /* SignalConversion: '<S42>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_f[6] = Plant_ConstB.VectorConcatenate3_e[0];

  /* Sum: '<S32>/Sum' incorporates:
   *  Inport: '<Root>/Environment_Info'
   */
  rtb_Switch_idx_3 = Plant_U.Environment_Info.hit_point[0] -
    Plant_U.Environment_Info.hit_location[0];

  /* SignalConversion: '<S42>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_f[7] = Plant_ConstB.VectorConcatenate3_e[1];

  /* Sum: '<S32>/Sum' incorporates:
   *  Inport: '<Root>/Environment_Info'
   */
  rtb_Gain_h = Plant_U.Environment_Info.hit_point[1] -
    Plant_U.Environment_Info.hit_location[1];

  /* SignalConversion: '<S42>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_f[8] = Plant_ConstB.VectorConcatenate3_e[2];

  /* Sum: '<S32>/Sum' incorporates:
   *  Inport: '<Root>/Environment_Info'
   */
  rtb_Multiply4_i_idx_1 = Plant_U.Environment_Info.hit_point[2] -
    Plant_U.Environment_Info.hit_location[2];

  /* Outputs for Atomic SubSystem: '<Root>/Actuators' */
  for (i = 0; i < 3; i++) {
    /* Sum: '<S11>/Sum' incorporates:
     *  Constant: '<S17>/X_Frame_CM'
     *  Math: '<S17>/Square'
     *  Product: '<S17>/Multiply'
     *  Sum: '<S18>/Sum'
     */
    rtb_Sum_p[i] = (((Plant_ConstP.X_Frame_CM_Value[i + 3] * rtb_Switch_idx_1 +
                      Plant_ConstP.X_Frame_CM_Value[i] * rtb_Switch_idx_0) +
                     Plant_ConstP.X_Frame_CM_Value[i + 6] * rtb_Switch_idx_2) +
                    Plant_ConstP.X_Frame_CM_Value[i + 9] * rtb_Switch) +
      (rtb_Sum_hq[i] - rtb_Sum_b[i]);

    /* Product: '<S32>/Multiply2' */
    rtb_Multiply4_i_idx_0 = rtb_VectorConcatenate_k[i + 6] *
      rtb_Multiply4_i_idx_1 + (rtb_VectorConcatenate_k[i + 3] * rtb_Gain_h +
      rtb_VectorConcatenate_k[i] * rtb_Switch_idx_3);

    /* Math: '<S47>/Math Function' */
    rtb_MathFunction[i] = rtb_Multiply4_i_idx_0 * rtb_Multiply4_i_idx_0;

    /* Product: '<S32>/Multiply2' */
    rtb_Multiply2_p[i] = rtb_Multiply4_i_idx_0;
  }

  /* End of Outputs for SubSystem: '<Root>/Actuators' */

  /* Sum: '<S47>/Sum of Elements' */
  rtb_Gain_d_tmp_5 = (rtb_MathFunction[0] + rtb_MathFunction[1]) +
    rtb_MathFunction[2];

  /* Math: '<S47>/Math Function1' incorporates:
   *  Sum: '<S47>/Sum of Elements'
   *
   * About '<S47>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Gain_d_tmp_5 < 0.0F) {
    rtb_Gain_h = -sqrtf(fabsf(rtb_Gain_d_tmp_5));
  } else {
    rtb_Gain_h = sqrtf(rtb_Gain_d_tmp_5);
  }

  /* End of Math: '<S47>/Math Function1' */

  /* Switch: '<S47>/Switch' incorporates:
   *  Constant: '<S47>/Constant'
   *  Product: '<S47>/Product'
   */
  if (rtb_Gain_h > 0.0F) {
    rtb_Divide_g[0] = rtb_Multiply2_p[0];
    rtb_Divide_g[1] = rtb_Multiply2_p[1];
    rtb_Divide_g[2] = rtb_Multiply2_p[2];
    rtb_Divide_g[3] = rtb_Gain_h;
  } else {
    rtb_Divide_g[0] = 0.0F;
    rtb_Divide_g[1] = 0.0F;
    rtb_Divide_g[2] = 0.0F;
    rtb_Divide_g[3] = 1.0F;
  }

  /* End of Switch: '<S47>/Switch' */
  for (i = 0; i < 3; i++) {
    /* Product: '<S47>/Divide' */
    rtb_Add_la[i] = rtb_Divide_g[i] / rtb_Divide_g[3];

    /* Product: '<S32>/Multiply1' */
    rtb_Sum_b[i] = rtb_VectorConcatenate_k[i + 6] * rtb_Product8 +
      (rtb_VectorConcatenate_k[i + 3] * rtb_MathFunction1_c +
       rtb_VectorConcatenate_k[i] * rtb_Add_e);
  }

  /* Product: '<S53>/Multiply' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_Multiply2_p[0] = Plant_Y.Plant_States.rot_y_B * rtb_Add_la[2];

  /* Product: '<S53>/Multiply1' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_Multiply2_p[1] = Plant_Y.Plant_States.rot_z_B * rtb_Add_la[0];

  /* Product: '<S53>/Multiply2' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_Multiply2_p[2] = Plant_Y.Plant_States.rot_x_B * rtb_Add_la[1];

  /* Product: '<S54>/Multiply3' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_Multiply5_i[0] = Plant_Y.Plant_States.rot_z_B * rtb_Add_la[1];

  /* Product: '<S54>/Multiply4' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_Multiply5_i[1] = Plant_Y.Plant_States.rot_x_B * rtb_Add_la[2];

  /* Product: '<S54>/Multiply5' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_Multiply5_i[2] = Plant_Y.Plant_States.rot_y_B * rtb_Add_la[0];

  /* DotProduct: '<S45>/Dot Product' */
  rtb_Multiply4_i_idx_0 = 0.0F;
  for (i = 0; i < 3; i++) {
    /* Sum: '<S46>/Sum1' incorporates:
     *  Sum: '<S50>/Sum'
     */
    rtb_Multiply4_i_idx_1 = (rtb_Multiply2_p[i] - rtb_Multiply5_i[i]) +
      rtb_Sum_b[i];

    /* Product: '<S32>/Multiply' incorporates:
     *  Inport: '<Root>/Environment_Info'
     */
    rtb_Switch_idx_0 = rtb_VectorConcatenate_k[i + 6] *
      Plant_U.Environment_Info.hit_normal[2] + (rtb_VectorConcatenate_k[i + 3] *
      Plant_U.Environment_Info.hit_normal[1] + rtb_VectorConcatenate_k[i] *
      Plant_U.Environment_Info.hit_normal[0]);

    /* DotProduct: '<S45>/Dot Product' */
    rtb_Multiply4_i_idx_0 += rtb_Multiply4_i_idx_1 * rtb_Switch_idx_0;

    /* Sum: '<S46>/Sum1' */
    rtb_Multiply2_p[i] = rtb_Multiply4_i_idx_1;

    /* Product: '<S32>/Multiply' incorporates:
     *  Product: '<S38>/Multiply'
     */
    rtb_DiscreteTimeIntegrator1[i] = rtb_Switch_idx_0;
  }

  /* Sum: '<S45>/Sum' incorporates:
   *  DotProduct: '<S45>/Dot Product'
   *  Product: '<S32>/Multiply'
   *  Product: '<S45>/Multiply'
   */
  rtb_Switch_idx_2 = rtb_Multiply2_p[0] - rtb_Multiply4_i_idx_0 *
    rtb_DiscreteTimeIntegrator1[0];

  /* Math: '<S49>/Math Function' */
  rtb_Multiply5_i[0] = rtb_Switch_idx_2 * rtb_Switch_idx_2;

  /* Sum: '<S45>/Sum' incorporates:
   *  DotProduct: '<S45>/Dot Product'
   *  Product: '<S32>/Multiply'
   *  Product: '<S45>/Multiply'
   */
  rtb_MathFunction[0] = rtb_Switch_idx_2;
  rtb_Switch_idx_2 = rtb_Multiply2_p[1] - rtb_Multiply4_i_idx_0 *
    rtb_DiscreteTimeIntegrator1[1];

  /* Math: '<S49>/Math Function' */
  rtb_Multiply5_i[1] = rtb_Switch_idx_2 * rtb_Switch_idx_2;

  /* Sum: '<S45>/Sum' incorporates:
   *  DotProduct: '<S45>/Dot Product'
   *  Product: '<S32>/Multiply'
   *  Product: '<S45>/Multiply'
   */
  rtb_MathFunction[1] = rtb_Switch_idx_2;
  rtb_Switch_idx_2 = rtb_Multiply2_p[2] - rtb_Multiply4_i_idx_0 *
    rtb_DiscreteTimeIntegrator1[2];

  /* Sum: '<S49>/Sum of Elements' incorporates:
   *  Math: '<S49>/Math Function'
   */
  rtb_Gain_d_tmp_5 = (rtb_Multiply5_i[0] + rtb_Multiply5_i[1]) +
    rtb_Switch_idx_2 * rtb_Switch_idx_2;

  /* Math: '<S49>/Math Function1' incorporates:
   *  Sum: '<S49>/Sum of Elements'
   *
   * About '<S49>/Math Function1':
   *  Operator: sqrt
   */
  if (rtb_Gain_d_tmp_5 < 0.0F) {
    rtb_Gain_h = -sqrtf(fabsf(rtb_Gain_d_tmp_5));
  } else {
    rtb_Gain_h = sqrtf(rtb_Gain_d_tmp_5);
  }

  /* End of Math: '<S49>/Math Function1' */

  /* Switch: '<S49>/Switch' incorporates:
   *  Constant: '<S49>/Constant'
   *  Product: '<S49>/Product'
   */
  if (rtb_Gain_h > 0.0F) {
    rtb_Switch_idx_0 = rtb_MathFunction[0];
    rtb_Switch_idx_1 = rtb_MathFunction[1];
    rtb_Switch_idx_3 = rtb_Gain_h;
  } else {
    rtb_Switch_idx_0 = 0.0F;
    rtb_Switch_idx_1 = 0.0F;
    rtb_Switch_idx_2 = 0.0F;
    rtb_Switch_idx_3 = 1.0F;
  }

  /* End of Switch: '<S49>/Switch' */

  /* Sqrt: '<S48>/Sqrt' incorporates:
   *  Math: '<S48>/Square'
   *  Product: '<S32>/Multiply'
   *  Sum: '<S48>/Sum of Elements'
   */
  rtb_Gain_h = sqrtf((rtb_DiscreteTimeIntegrator1[0] *
                      rtb_DiscreteTimeIntegrator1[0] +
                      rtb_DiscreteTimeIntegrator1[1] *
                      rtb_DiscreteTimeIntegrator1[1]) +
                     rtb_DiscreteTimeIntegrator1[2] *
                     rtb_DiscreteTimeIntegrator1[2]);

  /* Product: '<S45>/Multiply3' incorporates:
   *  Product: '<S49>/Divide'
   */
  rtb_Switch_idx_0 = rtb_Switch_idx_0 / rtb_Switch_idx_3 * rtb_Gain_h;

  /* DotProduct: '<S45>/Dot Product2' */
  rtb_Multiply4_i_idx_0 = rtb_Multiply2_p[0] * rtb_Switch_idx_0;

  /* Product: '<S45>/Multiply3' incorporates:
   *  Product: '<S49>/Divide'
   */
  rtb_Multiply5_i[0] = rtb_Switch_idx_0;
  rtb_Switch_idx_0 = rtb_Switch_idx_1 / rtb_Switch_idx_3 * rtb_Gain_h;

  /* DotProduct: '<S45>/Dot Product2' */
  rtb_Multiply4_i_idx_0 += rtb_Multiply2_p[1] * rtb_Switch_idx_0;

  /* Product: '<S45>/Multiply3' incorporates:
   *  Product: '<S49>/Divide'
   */
  rtb_Multiply5_i[1] = rtb_Switch_idx_0;
  rtb_Switch_idx_0 = rtb_Switch_idx_2 / rtb_Switch_idx_3 * rtb_Gain_h;

  /* DotProduct: '<S45>/Dot Product2' */
  rtb_Multiply4_i_idx_0 += rtb_Multiply2_p[2] * rtb_Switch_idx_0;

  /* Gain: '<S45>/Gain3' incorporates:
   *  Constant: '<S45>/Constant'
   *  DotProduct: '<S45>/Dot Product2'
   *  Product: '<S45>/Divide'
   */
  rtb_Switch_idx_1 = rtb_Multiply4_i_idx_0 / 0.01F * -0.886F;

  /* Product: '<S45>/Multiply4' */
  rtb_Multiply4_i_idx_0 = rtb_Switch_idx_1 * rtb_Multiply5_i[0];
  rtb_Multiply4_i_idx_1 = rtb_Switch_idx_1 * rtb_Multiply5_i[1];

  /* RelationalOperator: '<S43>/Compare' incorporates:
   *  Constant: '<S43>/Constant'
   *  DotProduct: '<S32>/Dot Product2'
   *  Product: '<S32>/Multiply'
   */
  rtb_Compare_o_idx_0 = ((rtb_DiscreteTimeIntegrator1[0] * rtb_Sum_b[0] +
    rtb_DiscreteTimeIntegrator1[1] * rtb_Sum_b[1]) +
    rtb_DiscreteTimeIntegrator1[2] * rtb_Sum_b[2] < 0.0F);

  /* Product: '<S55>/Multiply' incorporates:
   *  Product: '<S32>/Multiply'
   */
  rtb_Multiply5_i[0] = rtb_Add_la[1] * rtb_DiscreteTimeIntegrator1[2];

  /* Product: '<S55>/Multiply1' incorporates:
   *  Product: '<S32>/Multiply'
   */
  rtb_Multiply5_i[1] = rtb_Add_la[2] * rtb_DiscreteTimeIntegrator1[0];

  /* Product: '<S55>/Multiply2' incorporates:
   *  Product: '<S32>/Multiply'
   */
  rtb_Multiply5_i[2] = rtb_Add_la[0] * rtb_DiscreteTimeIntegrator1[1];

  /* Sum: '<S51>/Sum' incorporates:
   *  Product: '<S32>/Multiply'
   *  Product: '<S56>/Multiply3'
   *  Product: '<S56>/Multiply4'
   *  Product: '<S56>/Multiply5'
   */
  rtb_Multiply5_i[0] -= rtb_Add_la[2] * rtb_DiscreteTimeIntegrator1[1];
  rtb_Multiply5_i[1] -= rtb_Add_la[0] * rtb_DiscreteTimeIntegrator1[2];
  rtb_Multiply5_i[2] -= rtb_Add_la[1] * rtb_DiscreteTimeIntegrator1[0];

  /* Product: '<S46>/Divide2' incorporates:
   *  Constant: '<S46>/Inertia_Matrix'
   */
  rt_mldivide_U1f3x3_U2f3_Yf3x1(Plant_ConstP.pooled23, rtb_Multiply5_i,
    rtb_Sum_b);

  /* Product: '<S57>/Multiply' */
  rtb_MathFunction[0] = rtb_Sum_b[1] * rtb_Add_la[2];

  /* Product: '<S57>/Multiply1' */
  rtb_MathFunction[1] = rtb_Sum_b[2] * rtb_Add_la[0];

  /* Product: '<S57>/Multiply2' */
  rtb_MathFunction[2] = rtb_Sum_b[0] * rtb_Add_la[1];

  /* Sum: '<S52>/Sum' incorporates:
   *  Product: '<S58>/Multiply3'
   */
  rtb_Switch_idx_2 = rtb_MathFunction[0] - rtb_Sum_b[2] * rtb_Add_la[1];

  /* DotProduct: '<S46>/Dot Product1' incorporates:
   *  Product: '<S32>/Multiply'
   */
  rtb_Switch_idx_3 = rtb_Switch_idx_2 * rtb_DiscreteTimeIntegrator1[0];

  /* Sum: '<S52>/Sum' incorporates:
   *  Product: '<S58>/Multiply4'
   */
  rtb_MathFunction[0] = rtb_Switch_idx_2;
  rtb_Switch_idx_2 = rtb_MathFunction[1] - rtb_Sum_b[0] * rtb_Add_la[2];

  /* DotProduct: '<S46>/Dot Product1' incorporates:
   *  Product: '<S32>/Multiply'
   */
  rtb_Switch_idx_3 += rtb_Switch_idx_2 * rtb_DiscreteTimeIntegrator1[1];

  /* Sum: '<S52>/Sum' incorporates:
   *  Product: '<S58>/Multiply5'
   */
  rtb_MathFunction[1] = rtb_Switch_idx_2;
  rtb_Switch_idx_2 = rtb_MathFunction[2] - rtb_Sum_b[1] * rtb_Add_la[0];

  /* DotProduct: '<S46>/Dot Product1' incorporates:
   *  Product: '<S32>/Multiply'
   */
  rtb_Switch_idx_3 += rtb_Switch_idx_2 * rtb_DiscreteTimeIntegrator1[2];

  /* Sum: '<S52>/Sum' */
  rtb_MathFunction[2] = rtb_Switch_idx_2;

  /* Product: '<S46>/Divide1' incorporates:
   *  Abs: '<S46>/Abs'
   *  Constant: '<S46>/mass_inv'
   *  Constant: '<S46>/period'
   *  DotProduct: '<S46>/Dot Product'
   *  DotProduct: '<S46>/Dot Product1'
   *  Gain: '<S46>/Gain'
   *  Product: '<S32>/Multiply'
   *  Product: '<S46>/Divide'
   *  Product: '<S46>/Multiply3'
   *  Sum: '<S46>/Add1'
   */
  rtb_Gain_h = fabsf(-(((rtb_Multiply2_p[0] * rtb_DiscreteTimeIntegrator1[0] +
    rtb_Multiply2_p[1] * rtb_DiscreteTimeIntegrator1[1]) + rtb_Multiply2_p[2] *
                        rtb_DiscreteTimeIntegrator1[2]) * Plant_ConstB.Add_k) *
                     (1.0F / (rtb_Switch_idx_3 + 1.12866819F))) / 0.002F;

  /* Sum: '<S32>/Sum1' incorporates:
   *  Product: '<S32>/Multiply'
   *  Product: '<S32>/Multiply7'
   *  Product: '<S45>/Multiply4'
   *  Product: '<S46>/Multiply4'
   */
  rtb_Multiply4_i_idx_0 += rtb_Compare_o_idx_0 ? rtb_Gain_h *
    rtb_DiscreteTimeIntegrator1[0] : 0.0F;
  rtb_Multiply4_i_idx_1 += rtb_Compare_o_idx_0 ? rtb_Gain_h *
    rtb_DiscreteTimeIntegrator1[1] : 0.0F;
  rtb_Multiply4_b = rtb_Switch_idx_1 * rtb_Switch_idx_0 + (rtb_Compare_o_idx_0 ?
    rtb_Gain_h * rtb_DiscreteTimeIntegrator1[2] : 0.0F);

  /* RelationalOperator: '<S59>/Compare' incorporates:
   *  Constant: '<S59>/Constant'
   *  Delay: '<Root>/Delay'
   */
  rtb_Compare_o_idx_0 = (Plant_Y.Plant_States.h_R < 0.0F);

  /* Switch: '<S37>/Switch2' incorporates:
   *  Product: '<S60>/Multiply'
   *  SignalConversion: '<S60>/TmpSignal ConversionAtMultiplyInport2'
   */
  if (rtb_Compare_o_idx_0) {
    /* Switch: '<S60>/Switch1' incorporates:
     *  Constant: '<S60>/mg'
     *  Constant: '<S62>/Constant'
     *  Delay: '<Root>/Delay'
     *  Gain: '<S60>/Gain'
     *  RelationalOperator: '<S62>/Compare'
     *  Sum: '<S60>/Add'
     */
    if (Plant_Y.Plant_States.h_R <= -0.01F) {
      /* Switch: '<S60>/Switch3' incorporates:
       *  Constant: '<S60>/mg'
       *  Constant: '<S63>/Constant'
       *  Gain: '<S60>/Gain1'
       *  Gain: '<S60>/Gain2'
       *  Gain: '<S60>/Gain3'
       *  Gain: '<S60>/Gain4'
       *  RelationalOperator: '<S63>/Compare'
       *  Sum: '<S60>/Add1'
       *  Sum: '<S60>/Add2'
       */
      if (Plant_Y.Plant_States.h_R <= -0.1F) {
        rtb_Switch_idx_0 = (50.0F * Plant_Y.Plant_States.h_R - 8.68811607F) -
          100.0F * Plant_Y.Plant_States.vel_z_O;
      } else {
        rtb_Switch_idx_0 = (30.0F * Plant_Y.Plant_States.h_R - 8.68811607F) -
          50.0F * Plant_Y.Plant_States.vel_z_O;
      }

      /* End of Switch: '<S60>/Switch3' */
    } else {
      rtb_Switch_idx_0 = -8.68811607F - 25.0F * Plant_Y.Plant_States.vel_z_O;
    }

    /* End of Switch: '<S60>/Switch1' */

    /* SignalConversion: '<S60>/TmpSignal ConversionAtMultiplyInport2' incorporates:
     *  Delay: '<Root>/Delay'
     *  Gain: '<S60>/Gain5'
     *  Gain: '<S60>/Gain6'
     */
    rtb_Switch_idx_3 = -50.0F * Plant_Y.Plant_States.vel_x_O;
    rtb_Gain_h = -50.0F * Plant_Y.Plant_States.vel_y_O;
    for (i = 0; i < 3; i++) {
      rtb_Square_h[i] = rtb_VectorConcatenate_k[i + 6] * rtb_Switch_idx_0 +
        (rtb_VectorConcatenate_k[i + 3] * rtb_Gain_h + rtb_VectorConcatenate_k[i]
         * rtb_Switch_idx_3);
    }
  } else {
    rtb_Square_h[0] = 0.0F;
    rtb_Square_h[1] = 0.0F;
    rtb_Square_h[2] = 0.0F;
  }

  /* End of Switch: '<S37>/Switch2' */
  for (i = 0; i < 3; i++) {
    /* Product: '<S40>/Multiply' */
    rtb_Switch_idx_0 = rtb_VectorConcatenate_f[i + 6] * rtb_Product8 +
      (rtb_VectorConcatenate_f[i + 3] * rtb_MathFunction1_c +
       rtb_VectorConcatenate_f[i] * rtb_Add_e);

    /* Signum: '<S40>/Sign1' */
    if (rtb_Switch_idx_0 < 0.0F) {
      rtb_Switch_idx_1 = -1.0F;
    } else if (rtb_Switch_idx_0 > 0.0F) {
      rtb_Switch_idx_1 = 1.0F;
    } else {
      rtb_Switch_idx_1 = rtb_Switch_idx_0;
    }

    /* End of Signum: '<S40>/Sign1' */

    /* Gain: '<S40>/Gain' incorporates:
     *  Math: '<S40>/Square1'
     *  Product: '<S40>/Multiply5'
     */
    tmp[i] = rtb_Switch_idx_0 * rtb_Switch_idx_0 * rtb_Switch_idx_1 * -0.02F;
  }

  /* Product: '<S40>/Multiply1' incorporates:
   *  Math: '<S40>/Square'
   */
  for (i = 0; i < 3; i++) {
    rtb_Add_la[i] = rtb_VectorConcatenate_f[3 * i + 2] * tmp[2] +
      (rtb_VectorConcatenate_f[3 * i + 1] * tmp[1] + rtb_VectorConcatenate_f[3 *
       i] * tmp[0]);
  }

  /* End of Product: '<S40>/Multiply1' */

  /* Sum: '<S4>/Add2' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/Constant1'
   *  Constant: '<S15>/cT'
   *  Gain: '<S10>/Gain'
   *  Product: '<S15>/Multiply'
   *  Sum: '<S10>/Sum of Elements'
   */
  tmp[0] = 0.0F;
  tmp[1] = 0.0F;

  /* Outputs for Atomic SubSystem: '<Root>/Actuators' */
  tmp[2] = -(((rtb_Divide_f_idx_0 + rtb_Divide_f_idx_1) + rtb_Divide_f_idx_2) +
             (real32_T)(rtb_Switch * 1.239E-5));

  /* End of Outputs for SubSystem: '<Root>/Actuators' */

  /* DotProduct: '<S38>/Dot Product' */
  rtb_Square_g = 0.0F;
  for (i = 0; i < 3; i++) {
    /* Product: '<S40>/Multiply2' */
    rtb_Divide_f_idx_1 = rtb_VectorConcatenate_k[i + 6];

    /* Sum: '<S4>/Add2' incorporates:
     *  Inport: '<Root>/Environment_Info'
     *  Product: '<S36>/Multiply3'
     *  Product: '<S40>/Multiply2'
     */
    rtb_Divide_f_idx_1 = (((Plant_U.Environment_Info.force[i] + rtb_Square_h[i])
      + (rtb_Divide_f_idx_1 * rtb_Add_la[2] + (rtb_VectorConcatenate_k[i + 3] *
      rtb_Add_la[1] + rtb_VectorConcatenate_k[i] * rtb_Add_la[0]))) +
                          rtb_Divide_f_idx_1 * 8.69166F) + tmp[i];

    /* DotProduct: '<S38>/Dot Product' incorporates:
     *  Product: '<S38>/Multiply'
     */
    rtb_Square_g += rtb_Divide_f_idx_1 * rtb_DiscreteTimeIntegrator1[i];

    /* Sum: '<S4>/Add2' */
    rtb_Square_h[i] = rtb_Divide_f_idx_1;
  }

  /* Product: '<S38>/Multiply1' incorporates:
   *  Constant: '<S64>/Constant'
   *  DotProduct: '<S38>/Dot Product'
   *  RelationalOperator: '<S64>/Compare'
   */
  rtb_Divide_f_idx_1 = rtb_Square_g < 0.0F ? rtb_Square_g : 0.0F;

  /* Sum: '<S4>/Add' incorporates:
   *  Product: '<S38>/Multiply'
   *  Product: '<S38>/Multiply1'
   *  Sum: '<S38>/Sum'
   */
  rtb_Multiply4_i_idx_0 += rtb_Square_h[0] - rtb_Divide_f_idx_1 *
    rtb_DiscreteTimeIntegrator1[0];
  rtb_Multiply4_i_idx_1 += rtb_Square_h[1] - rtb_Divide_f_idx_1 *
    rtb_DiscreteTimeIntegrator1[1];
  rtb_Multiply4_b += rtb_Square_h[2] - rtb_Divide_f_idx_1 *
    rtb_DiscreteTimeIntegrator1[2];

  /* Switch: '<S37>/Switch1' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S61>/Gain1'
   *  Gain: '<S61>/Gain2'
   *  Gain: '<S61>/Gain3'
   *  Sum: '<S61>/Subtract'
   */
  if (rtb_Compare_o_idx_0) {
    rtb_Square_h[0] = ((0.0F - 30.0F * Plant_Y.Plant_States.phi) - 5.0F *
                       Plant_Y.Plant_States.rot_x_B) * 0.289603859F;
    rtb_Square_h[1] = ((0.0F - 30.0F * Plant_Y.Plant_States.theta) - 5.0F *
                       Plant_Y.Plant_States.rot_y_B) * 0.289603859F;
    rtb_Square_h[2] = (0.0F - 5.0F * Plant_Y.Plant_States.rot_z_B) *
      0.289603859F;
  } else {
    rtb_Square_h[0] = 0.0F;
    rtb_Square_h[1] = 0.0F;
    rtb_Square_h[2] = 0.0F;
  }

  /* End of Switch: '<S37>/Switch1' */

  /* Signum: '<S40>/Sign' incorporates:
   *  Delay: '<Root>/Delay'
   */
  if (Plant_Y.Plant_States.rot_x_B < 0.0F) {
    rtb_Gain_d_tmp_5 = -1.0F;
  } else if (Plant_Y.Plant_States.rot_x_B > 0.0F) {
    rtb_Gain_d_tmp_5 = 1.0F;
  } else {
    rtb_Gain_d_tmp_5 = Plant_Y.Plant_States.rot_x_B;
  }

  /* Sum: '<S4>/Add3' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S40>/Gain1'
   *  Inport: '<Root>/Environment_Info'
   *  Math: '<S40>/Square2'
   *  Product: '<S40>/Multiply3'
   */
  rtb_Square_h[0] = Plant_Y.Plant_States.rot_x_B * Plant_Y.Plant_States.rot_x_B *
    rtb_Gain_d_tmp_5 * -0.005F + ((rtb_Sum_p[0] +
    Plant_U.Environment_Info.torque[0]) + rtb_Square_h[0]);

  /* Signum: '<S40>/Sign' incorporates:
   *  Delay: '<Root>/Delay'
   */
  if (Plant_Y.Plant_States.rot_y_B < 0.0F) {
    rtb_Gain_d_tmp_5 = -1.0F;
  } else if (Plant_Y.Plant_States.rot_y_B > 0.0F) {
    rtb_Gain_d_tmp_5 = 1.0F;
  } else {
    rtb_Gain_d_tmp_5 = Plant_Y.Plant_States.rot_y_B;
  }

  /* Sum: '<S4>/Add3' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S40>/Gain1'
   *  Inport: '<Root>/Environment_Info'
   *  Math: '<S40>/Square2'
   *  Product: '<S40>/Multiply3'
   */
  rtb_Square_h[1] = Plant_Y.Plant_States.rot_y_B * Plant_Y.Plant_States.rot_y_B *
    rtb_Gain_d_tmp_5 * -0.005F + ((rtb_Sum_p[1] +
    Plant_U.Environment_Info.torque[1]) + rtb_Square_h[1]);

  /* Signum: '<S40>/Sign' incorporates:
   *  Delay: '<Root>/Delay'
   */
  if (Plant_Y.Plant_States.rot_z_B < 0.0F) {
    rtb_Gain_d_tmp_5 = -1.0F;
  } else if (Plant_Y.Plant_States.rot_z_B > 0.0F) {
    rtb_Gain_d_tmp_5 = 1.0F;
  } else {
    rtb_Gain_d_tmp_5 = Plant_Y.Plant_States.rot_z_B;
  }

  /* Sum: '<S4>/Add3' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S40>/Gain1'
   *  Inport: '<Root>/Environment_Info'
   *  Math: '<S40>/Square2'
   *  Product: '<S40>/Multiply3'
   */
  rtb_Square_g = Plant_Y.Plant_States.rot_z_B * Plant_Y.Plant_States.rot_z_B *
    rtb_Gain_d_tmp_5 * -0.005F + ((rtb_Sum_p[2] +
    Plant_U.Environment_Info.torque[2]) + rtb_Square_h[2]);

  /* Sum: '<S4>/Add1' incorporates:
   *  Product: '<S32>/Multiply6'
   */
  rtb_Multiply5_i[0] = rtb_Square_h[0];
  rtb_Multiply5_i[1] = rtb_Square_h[1];

  /* End of Outputs for SubSystem: '<Root>/Environment' */

  /* Outputs for Atomic SubSystem: '<Root>/Kinematic_Equation' */
  /* Gain: '<S69>/Gain' incorporates:
   *  Inport: '<Root>/States_Init'
   */
  rtb_Multiply2_p[0] = 0.5F * Plant_U.States_Init.euler[0];
  rtb_Multiply2_p[1] = 0.5F * Plant_U.States_Init.euler[1];
  rtb_Multiply2_p[2] = 0.5F * Plant_U.States_Init.euler[2];

  /* End of Outputs for SubSystem: '<Root>/Kinematic_Equation' */

  /* Outputs for Atomic SubSystem: '<Root>/Environment' */
  /* RelationalOperator: '<S33>/Compare' incorporates:
   *  Constant: '<S33>/Constant'
   *  Inport: '<Root>/Environment_Info'
   *  Math: '<S39>/Square'
   *  Sqrt: '<S39>/Sqrt'
   *  Sum: '<S39>/Sum of Elements'
   */
  rtb_Compare_o_idx_1 = (sqrtf((Plant_U.Environment_Info.hit_normal[0] *
    Plant_U.Environment_Info.hit_normal[0] +
    Plant_U.Environment_Info.hit_normal[1] *
    Plant_U.Environment_Info.hit_normal[1]) +
    Plant_U.Environment_Info.hit_normal[2] *
    Plant_U.Environment_Info.hit_normal[2]) > 0.0F);

  /* RelationalOperator: '<S34>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S34>/Delay Input1'
   *
   * Block description for '<S34>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_Compare_o_idx_0 = ((int32_T)rtb_Compare_o_idx_1 > (int32_T)
    Plant_DW.DelayInput1_DSTATE_l);

  /* Update for UnitDelay: '<S34>/Delay Input1'
   *
   * Block description for '<S34>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Plant_DW.DelayInput1_DSTATE_l = rtb_Compare_o_idx_1;

  /* End of Outputs for SubSystem: '<Root>/Environment' */

  /* Outputs for Atomic SubSystem: '<Root>/Kinematic_Equation' */
  /* Trigonometry: '<S69>/Cos' */
  rtb_Add_e = arm_cos_f32(rtb_Multiply2_p[0]);

  /* Trigonometry: '<S69>/Cos1' */
  rtb_MathFunction1_c = arm_cos_f32(rtb_Multiply2_p[1]);

  /* Trigonometry: '<S69>/Cos2' */
  rtb_Divide_f_idx_2 = arm_cos_f32(rtb_Multiply2_p[2]);

  /* Trigonometry: '<S69>/Sin' */
  rtb_Product8 = arm_sin_f32(rtb_Multiply2_p[0]);

  /* Trigonometry: '<S69>/Sin1' */
  rtb_Divide_f_idx_1 = arm_sin_f32(rtb_Multiply2_p[1]);

  /* Trigonometry: '<S69>/Sin2' */
  rtb_Gain_h = arm_sin_f32(rtb_Multiply2_p[2]);

  /* Product: '<S69>/Multiply' incorporates:
   *  Product: '<S69>/Multiply6'
   */
  rtb_Switch = rtb_Add_e * rtb_MathFunction1_c;

  /* Product: '<S69>/Multiply1' incorporates:
   *  Product: '<S69>/Multiply7'
   */
  rtb_Divide_f_idx_0 = rtb_Product8 * rtb_Divide_f_idx_1;

  /* SignalConversion: '<S75>/TmpSignal ConversionAtSquareInport1' incorporates:
   *  Product: '<S69>/Multiply'
   *  Product: '<S69>/Multiply1'
   *  Sum: '<S69>/Add'
   */
  rtb_Switch_idx_0 = rtb_Switch * rtb_Divide_f_idx_2 + rtb_Divide_f_idx_0 *
    rtb_Gain_h;

  /* Product: '<S69>/Multiply3' incorporates:
   *  Product: '<S69>/Multiply4'
   */
  rtb_Add_e *= rtb_Divide_f_idx_1;

  /* Product: '<S69>/Multiply2' incorporates:
   *  Product: '<S69>/Multiply5'
   */
  rtb_Divide_f_idx_1 = rtb_Product8 * rtb_MathFunction1_c;

  /* SignalConversion: '<S75>/TmpSignal ConversionAtSquareInport1' incorporates:
   *  Product: '<S69>/Multiply2'
   *  Product: '<S69>/Multiply3'
   *  Product: '<S69>/Multiply4'
   *  Product: '<S69>/Multiply5'
   *  Product: '<S69>/Multiply6'
   *  Product: '<S69>/Multiply7'
   *  Sum: '<S69>/Add1'
   *  Sum: '<S69>/Subtract'
   *  Sum: '<S69>/Subtract1'
   */
  rtb_Switch_idx_1 = rtb_Divide_f_idx_1 * rtb_Divide_f_idx_2 - rtb_Add_e *
    rtb_Gain_h;
  rtb_Switch_idx_2 = rtb_Add_e * rtb_Divide_f_idx_2 + rtb_Divide_f_idx_1 *
    rtb_Gain_h;
  rtb_Switch_idx_3 = rtb_Switch * rtb_Gain_h - rtb_Divide_f_idx_0 *
    rtb_Divide_f_idx_2;

  /* Sqrt: '<S75>/Sqrt' incorporates:
   *  Math: '<S75>/Square'
   *  Sum: '<S75>/Sum of Elements'
   */
  rtb_Gain_h = sqrtf(((rtb_Switch_idx_0 * rtb_Switch_idx_0 + rtb_Switch_idx_1 *
                       rtb_Switch_idx_1) + rtb_Switch_idx_2 * rtb_Switch_idx_2)
                     + rtb_Switch_idx_3 * rtb_Switch_idx_3);

  /* Product: '<S74>/Divide' */
  rtb_Switch = rtb_Switch_idx_0 / rtb_Gain_h;

  /* Math: '<S80>/Square' */
  rtb_Divide_g[0] = rtb_Switch * rtb_Switch;

  /* Product: '<S74>/Divide' */
  rtb_Switch_idx_0 = rtb_Switch;
  rtb_Switch = rtb_Switch_idx_1 / rtb_Gain_h;

  /* Math: '<S80>/Square' */
  rtb_Divide_g[1] = rtb_Switch * rtb_Switch;

  /* Product: '<S74>/Divide' */
  rtb_Switch_idx_1 = rtb_Switch;
  rtb_Switch = rtb_Switch_idx_2 / rtb_Gain_h;

  /* Math: '<S80>/Square' */
  rtb_Divide_g[2] = rtb_Switch * rtb_Switch;

  /* Product: '<S74>/Divide' */
  rtb_Switch_idx_2 = rtb_Switch;
  rtb_Switch = rtb_Switch_idx_3 / rtb_Gain_h;

  /* Sqrt: '<S80>/Sqrt' incorporates:
   *  Math: '<S80>/Square'
   *  Sum: '<S80>/Sum of Elements'
   */
  rtb_Gain_h = sqrtf(((rtb_Divide_g[0] + rtb_Divide_g[1]) + rtb_Divide_g[2]) +
                     rtb_Switch * rtb_Switch);

  /* Product: '<S78>/Divide' */
  rtb_Switch_idx_0 /= rtb_Gain_h;
  rtb_Switch_idx_1 /= rtb_Gain_h;
  rtb_Switch_idx_2 /= rtb_Gain_h;
  rtb_Switch /= rtb_Gain_h;

  /* RelationalOperator: '<S68>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/States_Init'
   *  UnitDelay: '<S68>/Delay Input1'
   *
   * Block description for '<S68>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_Compare_o_idx_1 = (Plant_U.States_Init.timestamp !=
    Plant_DW.DelayInput1_DSTATE);

  /* DiscreteIntegrator: '<S71>/Discrete-Time Integrator' */
  if (Plant_DW.DiscreteTimeIntegrator_IC_LOADI != 0) {
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[0] = rtb_Switch_idx_0;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[1] = rtb_Switch_idx_1;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[2] = rtb_Switch_idx_2;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[3] = rtb_Switch;
  }

  if (rtb_Compare_o_idx_1 || (Plant_DW.DiscreteTimeIntegrator_PrevRese != 0)) {
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[0] = rtb_Switch_idx_0;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[1] = rtb_Switch_idx_1;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[2] = rtb_Switch_idx_2;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[3] = rtb_Switch;
  }

  rtb_MathFunction1_c = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[0];
  rtb_Product8 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[1];
  rtb_Switch_idx_0 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[2];
  rtb_Switch_idx_1 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[3];

  /* SignalConversion: '<S79>/ConcatBufferAtMatrix ConcatenateIn1' incorporates:
   *  Constant: '<S79>/Constant'
   */
  rtb_MatrixConcatenate4[0] = 0.0F;

  /* Logic: '<S65>/Logical Operator' */
  rtb_Compare_o_idx_2 = (rtb_Compare_o_idx_0 || rtb_Compare_o_idx_1);

  /* DiscreteIntegrator: '<S65>/Discrete-Time Integrator' */
  if (rtb_Compare_o_idx_2 || (Plant_DW.DiscreteTimeIntegrator_PrevRe_d != 0)) {
    Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2] = 0.0F;
  }

  rtb_Sum_p[0] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0];
  rtb_Sum_p[1] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1];
  rtb_Sum_p[2] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2];

  /* SignalConversion: '<S79>/ConcatBufferAtMatrix ConcatenateIn2' incorporates:
   *  DiscreteIntegrator: '<S65>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[1] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0];

  /* SignalConversion: '<S79>/ConcatBufferAtMatrix ConcatenateIn3' incorporates:
   *  DiscreteIntegrator: '<S65>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[2] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1];

  /* SignalConversion: '<S79>/ConcatBufferAtMatrix ConcatenateIn4' incorporates:
   *  DiscreteIntegrator: '<S65>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[3] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2];

  /* Gain: '<S79>/Gain1' incorporates:
   *  DiscreteIntegrator: '<S65>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[4] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0];

  /* SignalConversion: '<S79>/ConcatBufferAtMatrix Concatenate1In2' incorporates:
   *  Constant: '<S79>/Constant1'
   */
  rtb_MatrixConcatenate4[5] = 0.0F;

  /* Gain: '<S79>/Gain2' incorporates:
   *  DiscreteIntegrator: '<S65>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[6] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2];

  /* SignalConversion: '<S79>/ConcatBufferAtMatrix Concatenate1In4' incorporates:
   *  DiscreteIntegrator: '<S65>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[7] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1];

  /* Gain: '<S79>/Gain3' incorporates:
   *  DiscreteIntegrator: '<S65>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[8] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1];

  /* SignalConversion: '<S79>/ConcatBufferAtMatrix Concatenate2In2' incorporates:
   *  DiscreteIntegrator: '<S65>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[9] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2];

  /* SignalConversion: '<S79>/ConcatBufferAtMatrix Concatenate2In3' incorporates:
   *  Constant: '<S79>/Constant2'
   */
  rtb_MatrixConcatenate4[10] = 0.0F;

  /* Gain: '<S79>/Gain4' incorporates:
   *  DiscreteIntegrator: '<S65>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[11] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0];

  /* Gain: '<S79>/Gain6' incorporates:
   *  DiscreteIntegrator: '<S65>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[12] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2];

  /* Gain: '<S79>/Gain7' incorporates:
   *  DiscreteIntegrator: '<S65>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[13] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1];

  /* SignalConversion: '<S79>/ConcatBufferAtMatrix Concatenate3In3' incorporates:
   *  DiscreteIntegrator: '<S65>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[14] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0];

  /* SignalConversion: '<S79>/ConcatBufferAtMatrix Concatenate3In4' incorporates:
   *  Constant: '<S79>/Constant3'
   */
  rtb_MatrixConcatenate4[15] = 0.0F;

  /* Sqrt: '<S77>/Sqrt' incorporates:
   *  DiscreteIntegrator: '<S71>/Discrete-Time Integrator'
   *  Math: '<S77>/Square'
   *  Sqrt: '<S91>/Sqrt'
   *  Sqrt: '<S96>/Sqrt'
   *  Sum: '<S77>/Sum of Elements'
   */
  rtb_Gain_d_tmp = sqrtf(((Plant_DW.DiscreteTimeIntegrator_DSTATE_d[0] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[0] +
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[1] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[1]) +
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[2] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[2]) +
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[3] *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[3]);

  /* Product: '<S76>/Divide' incorporates:
   *  DiscreteIntegrator: '<S71>/Discrete-Time Integrator'
   *  Sqrt: '<S77>/Sqrt'
   */
  rtb_Switch = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[0] / rtb_Gain_d_tmp;
  rtb_Add_e = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[1] / rtb_Gain_d_tmp;
  rtb_Switch_idx_2 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[2] /
    rtb_Gain_d_tmp;
  rtb_Switch_idx_3 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[3] /
    rtb_Gain_d_tmp;

  /* Product: '<S87>/Divide' incorporates:
   *  DiscreteIntegrator: '<S71>/Discrete-Time Integrator'
   */
  rtb_Gain_d_tmp_5 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[0] /
    rtb_Gain_d_tmp;
  rtb_Gain_d_tmp_4 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[1] /
    rtb_Gain_d_tmp;
  rtb_Sum_mx_tmp = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[2] / rtb_Gain_d_tmp;
  rtb_Sum_i_tmp = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[3] / rtb_Gain_d_tmp;

  /* Product: '<S92>/Divide' incorporates:
   *  DiscreteIntegrator: '<S71>/Discrete-Time Integrator'
   */
  rtb_Divide_f_idx_0 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[0] /
    rtb_Gain_d_tmp;
  rtb_Divide_f_idx_1 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[1] /
    rtb_Gain_d_tmp;
  rtb_Divide_f_idx_2 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[2] /
    rtb_Gain_d_tmp;
  rtb_Divide_f_idx_3 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[3] /
    rtb_Gain_d_tmp;

  /* Product: '<S65>/Multiply' incorporates:
   *  Constant: '<S65>/Inertia_Matrix'
   *  DiscreteIntegrator: '<S65>/Discrete-Time Integrator'
   */
  for (i = 0; i < 3; i++) {
    rtb_Add_la[i] = Plant_ConstP.pooled23[i + 6] *
      Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2] + (Plant_ConstP.pooled23[i + 3]
      * Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1] + Plant_ConstP.pooled23[i] *
      Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0]);
  }

  /* End of Product: '<S65>/Multiply' */

  /* Product: '<S72>/Multiply' incorporates:
   *  DiscreteIntegrator: '<S65>/Discrete-Time Integrator'
   */
  rtb_Sum_mo[0] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1] * rtb_Add_la[2];

  /* Product: '<S72>/Multiply1' incorporates:
   *  DiscreteIntegrator: '<S65>/Discrete-Time Integrator'
   */
  rtb_Sum_mo[1] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2] * rtb_Add_la[0];

  /* Product: '<S72>/Multiply2' incorporates:
   *  DiscreteIntegrator: '<S65>/Discrete-Time Integrator'
   */
  rtb_Sum_mo[2] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0] * rtb_Add_la[1];

  /* Product: '<S73>/Multiply3' incorporates:
   *  DiscreteIntegrator: '<S65>/Discrete-Time Integrator'
   */
  rtb_Sum_b[0] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2] * rtb_Add_la[1];

  /* Product: '<S73>/Multiply4' incorporates:
   *  DiscreteIntegrator: '<S65>/Discrete-Time Integrator'
   */
  rtb_Sum_b[1] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0] * rtb_Add_la[2];

  /* Product: '<S73>/Multiply5' incorporates:
   *  DiscreteIntegrator: '<S65>/Discrete-Time Integrator'
   */
  rtb_Sum_b[2] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1] * rtb_Add_la[0];

  /* RelationalOperator: '<S82>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/States_Init'
   *  UnitDelay: '<S82>/Delay Input1'
   *
   * Block description for '<S82>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_Compare_o_idx_3 = (Plant_U.States_Init.timestamp !=
    Plant_DW.DelayInput1_DSTATE_f);

  /* Logic: '<S66>/Logical Operator' */
  rtb_Compare_o_idx_0 = (rtb_Compare_o_idx_0 || rtb_Compare_o_idx_3);

  /* DiscreteIntegrator: '<S66>/Discrete-Time Integrator' */
  if (rtb_Compare_o_idx_0 || (Plant_DW.DiscreteTimeIntegrator_PrevRe_k != 0)) {
    Plant_DW.DiscreteTimeIntegrator_DSTATE_f[0] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_f[1] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_f[2] = 0.0F;
  }

  rtb_Square_h[0] = Plant_DW.DiscreteTimeIntegrator_DSTATE_f[0];
  rtb_Square_h[1] = Plant_DW.DiscreteTimeIntegrator_DSTATE_f[1];
  rtb_Square_h[2] = Plant_DW.DiscreteTimeIntegrator_DSTATE_f[2];

  /* Product: '<S90>/Product3' incorporates:
   *  Product: '<S87>/Divide'
   *  Product: '<S88>/Product6'
   */
  rtb_Gain_d_tmp = rtb_Sum_mx_tmp * rtb_Sum_mx_tmp;

  /* Product: '<S90>/Product6' incorporates:
   *  Product: '<S87>/Divide'
   *  Product: '<S88>/Product9'
   */
  rtb_Gain_d_tmp_0 = rtb_Gain_d_tmp_4 * rtb_Sum_i_tmp;

  /* Product: '<S90>/Product7' incorporates:
   *  Product: '<S87>/Divide'
   *  Product: '<S88>/Product2'
   */
  rtb_Gain_d_tmp_1 = rtb_Gain_d_tmp_5 * rtb_Sum_mx_tmp;

  /* Sum: '<S90>/Sum2' incorporates:
   *  Constant: '<S90>/Constant'
   *  Product: '<S87>/Divide'
   *  Product: '<S90>/Product2'
   *  Sum: '<S89>/Sum1'
   */
  rtb_Gain_d_tmp_2 = 0.5F - rtb_Gain_d_tmp_4 * rtb_Gain_d_tmp_4;

  /* Product: '<S90>/Product1' incorporates:
   *  Product: '<S87>/Divide'
   *  Product: '<S89>/Product2'
   */
  rtb_Gain_d_tmp_6 = rtb_Gain_d_tmp_5 * rtb_Gain_d_tmp_4;

  /* Product: '<S90>/Product9' incorporates:
   *  Product: '<S87>/Divide'
   *  Product: '<S89>/Product3'
   */
  rtb_Gain_d_tmp_7 = rtb_Sum_mx_tmp * rtb_Sum_i_tmp;

  /* Sum: '<S90>/Sum' incorporates:
   *  DiscreteIntegrator: '<S66>/Discrete-Time Integrator'
   *  Gain: '<S90>/Gain1'
   *  Gain: '<S90>/Gain2'
   *  Gain: '<S90>/Gain3'
   *  Product: '<S90>/Product1'
   *  Product: '<S90>/Product3'
   *  Product: '<S90>/Product4'
   *  Product: '<S90>/Product5'
   *  Product: '<S90>/Product6'
   *  Product: '<S90>/Product7'
   *  Product: '<S90>/Product8'
   *  Product: '<S90>/Product9'
   *  Sum: '<S90>/Sum1'
   *  Sum: '<S90>/Sum2'
   *  Sum: '<S90>/Sum3'
   */
  rtb_Gain_h = ((rtb_Gain_d_tmp_0 + rtb_Gain_d_tmp_1) * 2.0F *
                Plant_DW.DiscreteTimeIntegrator_DSTATE_f[0] + (rtb_Gain_d_tmp_7
    - rtb_Gain_d_tmp_6) * 2.0F * Plant_DW.DiscreteTimeIntegrator_DSTATE_f[1]) +
    (rtb_Gain_d_tmp_2 - rtb_Gain_d_tmp) * 2.0F *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_f[2];

  /* Product: '<S85>/Multiply' incorporates:
   *  DiscreteIntegrator: '<S65>/Discrete-Time Integrator'
   */
  rtb_Add_la[0] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1] * rtb_Gain_h;

  /* Product: '<S86>/Multiply4' incorporates:
   *  DiscreteIntegrator: '<S65>/Discrete-Time Integrator'
   */
  rtb_Sum_hq[1] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0] * rtb_Gain_h;

  /* DiscreteIntegrator: '<S66>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/States_Init'
   */
  if (Plant_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
    Plant_DW.DiscreteTimeIntegrator1_DSTATE[0] = Plant_U.States_Init.pos[0];
    Plant_DW.DiscreteTimeIntegrator1_DSTATE[1] = Plant_U.States_Init.pos[1];
    Plant_DW.DiscreteTimeIntegrator1_DSTATE[2] = Plant_U.States_Init.pos[2];
  }

  if (rtb_Compare_o_idx_3 || (Plant_DW.DiscreteTimeIntegrator1_PrevRes != 0)) {
    Plant_DW.DiscreteTimeIntegrator1_DSTATE[0] = Plant_U.States_Init.pos[0];
    Plant_DW.DiscreteTimeIntegrator1_DSTATE[1] = Plant_U.States_Init.pos[1];
    Plant_DW.DiscreteTimeIntegrator1_DSTATE[2] = Plant_U.States_Init.pos[2];
  }

  /* Product: '<S88>/Product7' incorporates:
   *  Product: '<S87>/Divide'
   *  Product: '<S89>/Product9'
   */
  rtb_Gain_d_tmp_3 = rtb_Sum_i_tmp * rtb_Sum_i_tmp;

  /* Product: '<S88>/Product' incorporates:
   *  Product: '<S87>/Divide'
   *  Product: '<S89>/Product6'
   */
  rtb_Gain_d_tmp_4 *= rtb_Sum_mx_tmp;

  /* Product: '<S88>/Product1' incorporates:
   *  Product: '<S87>/Divide'
   *  Product: '<S89>/Product7'
   */
  rtb_Gain_d_tmp_5 *= rtb_Sum_i_tmp;

  /* Sum: '<S88>/Sum' incorporates:
   *  Constant: '<S88>/Constant'
   *  DiscreteIntegrator: '<S66>/Discrete-Time Integrator'
   *  Gain: '<S88>/Gain'
   *  Gain: '<S88>/Gain2'
   *  Gain: '<S88>/Gain3'
   *  Product: '<S88>/Product'
   *  Product: '<S88>/Product1'
   *  Product: '<S88>/Product4'
   *  Product: '<S88>/Product5'
   *  Product: '<S88>/Product7'
   *  Product: '<S88>/Product8'
   *  Sum: '<S88>/Sum1'
   *  Sum: '<S88>/Sum2'
   *  Sum: '<S88>/Sum3'
   */
  rtb_Gain_h = (((0.5F - rtb_Gain_d_tmp) - rtb_Gain_d_tmp_3) * 2.0F *
                Plant_DW.DiscreteTimeIntegrator_DSTATE_f[0] + (rtb_Gain_d_tmp_4
    + rtb_Gain_d_tmp_5) * 2.0F * Plant_DW.DiscreteTimeIntegrator_DSTATE_f[1]) +
    (rtb_Gain_d_tmp_0 - rtb_Gain_d_tmp_1) * 2.0F *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_f[2];

  /* Product: '<S85>/Multiply1' incorporates:
   *  DiscreteIntegrator: '<S65>/Discrete-Time Integrator'
   */
  rtb_Add_la[1] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2] * rtb_Gain_h;

  /* Product: '<S86>/Multiply5' incorporates:
   *  DiscreteIntegrator: '<S65>/Discrete-Time Integrator'
   */
  rtb_Sum_hq[2] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1] * rtb_Gain_h;

  /* Sum: '<S89>/Sum' incorporates:
   *  DiscreteIntegrator: '<S66>/Discrete-Time Integrator'
   *  Gain: '<S89>/Gain1'
   *  Gain: '<S89>/Gain2'
   *  Gain: '<S89>/Gain3'
   *  Product: '<S89>/Product4'
   *  Product: '<S89>/Product5'
   *  Product: '<S89>/Product8'
   *  Sum: '<S89>/Sum1'
   *  Sum: '<S89>/Sum2'
   *  Sum: '<S89>/Sum3'
   */
  rtb_Gain_h = ((rtb_Gain_d_tmp_2 - rtb_Gain_d_tmp_3) * 2.0F *
                Plant_DW.DiscreteTimeIntegrator_DSTATE_f[1] + (rtb_Gain_d_tmp_4
    - rtb_Gain_d_tmp_5) * 2.0F * Plant_DW.DiscreteTimeIntegrator_DSTATE_f[0]) +
    (rtb_Gain_d_tmp_6 + rtb_Gain_d_tmp_7) * 2.0F *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_f[2];

  /* DiscreteIntegrator: '<S66>/Discrete-Time Integrator1' */
  rtb_DiscreteTimeIntegrator1[0] = Plant_DW.DiscreteTimeIntegrator1_DSTATE[0];

  /* Sum: '<S65>/Sum' incorporates:
   *  Sum: '<S67>/Sum'
   */
  rtb_Sum_b[0] = rtb_Multiply5_i[0] - (rtb_Sum_mo[0] - rtb_Sum_b[0]);

  /* Sum: '<S66>/Sum' incorporates:
   *  Constant: '<S66>/mass'
   *  DiscreteIntegrator: '<S65>/Discrete-Time Integrator'
   *  Product: '<S66>/Divide'
   *  Product: '<S86>/Multiply3'
   *  Sum: '<S81>/Sum'
   */
  rtb_Sum_hq[0] = rtb_Multiply4_i_idx_0 / 0.886F - (rtb_Add_la[0] -
    Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2] * rtb_Gain_h);

  /* DiscreteIntegrator: '<S66>/Discrete-Time Integrator1' */
  rtb_DiscreteTimeIntegrator1[1] = Plant_DW.DiscreteTimeIntegrator1_DSTATE[1];

  /* Sum: '<S65>/Sum' incorporates:
   *  Sum: '<S67>/Sum'
   */
  rtb_Sum_b[1] = rtb_Multiply5_i[1] - (rtb_Sum_mo[1] - rtb_Sum_b[1]);

  /* Sum: '<S66>/Sum' incorporates:
   *  Constant: '<S66>/mass'
   *  Product: '<S66>/Divide'
   *  Sum: '<S81>/Sum'
   */
  rtb_Sum_hq[1] = rtb_Multiply4_i_idx_1 / 0.886F - (rtb_Add_la[1] - rtb_Sum_hq[1]);

  /* DiscreteIntegrator: '<S66>/Discrete-Time Integrator1' */
  rtb_DiscreteTimeIntegrator1[2] = Plant_DW.DiscreteTimeIntegrator1_DSTATE[2];

  /* Sum: '<S66>/Sum' incorporates:
   *  Constant: '<S66>/mass'
   *  DiscreteIntegrator: '<S65>/Discrete-Time Integrator'
   *  Product: '<S66>/Divide'
   *  Product: '<S85>/Multiply2'
   *  Sum: '<S81>/Sum'
   */
  rtb_Multiply4_i_idx_1 = rtb_Multiply4_b / 0.886F -
    (Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0] * rtb_Gain_h - rtb_Sum_hq[2]);

  /* Sum: '<S65>/Sum' incorporates:
   *  Sum: '<S67>/Sum'
   */
  rtb_Sum_b[2] = rtb_Square_g - (rtb_Sum_mo[2] - rtb_Sum_b[2]);

  /* Product: '<S93>/Product7' incorporates:
   *  Product: '<S92>/Divide'
   *  Product: '<S94>/Product7'
   */
  rtb_Square_g = rtb_Divide_f_idx_3 * rtb_Divide_f_idx_3;

  /* Product: '<S93>/Product' incorporates:
   *  Product: '<S92>/Divide'
   *  Product: '<S94>/Product'
   */
  rtb_Sum_i_tmp = rtb_Divide_f_idx_1 * rtb_Divide_f_idx_2;

  /* Product: '<S93>/Product1' incorporates:
   *  Product: '<S92>/Divide'
   *  Product: '<S94>/Product1'
   */
  rtb_Gain_d_tmp_4 = rtb_Divide_f_idx_0 * rtb_Divide_f_idx_3;

  /* Product: '<S93>/Product2' incorporates:
   *  Product: '<S92>/Divide'
   *  Product: '<S95>/Product9'
   */
  rtb_Gain_h = rtb_Divide_f_idx_1 * rtb_Divide_f_idx_3;

  /* Product: '<S93>/Product3' incorporates:
   *  Product: '<S92>/Divide'
   *  Product: '<S95>/Product1'
   */
  rtb_Multiply4_b = rtb_Divide_f_idx_0 * rtb_Divide_f_idx_2;

  /* Product: '<S93>/Product6' incorporates:
   *  Product: '<S92>/Divide'
   *  Product: '<S95>/Product7'
   */
  rtb_Gain_d_tmp_5 = rtb_Divide_f_idx_2 * rtb_Divide_f_idx_2;

  /* Sum: '<S93>/Sum' incorporates:
   *  Constant: '<S93>/Constant'
   *  Gain: '<S93>/Gain'
   *  Gain: '<S93>/Gain1'
   *  Gain: '<S93>/Gain2'
   *  Product: '<S93>/Product'
   *  Product: '<S93>/Product1'
   *  Product: '<S93>/Product2'
   *  Product: '<S93>/Product3'
   *  Product: '<S93>/Product4'
   *  Product: '<S93>/Product5'
   *  Product: '<S93>/Product6'
   *  Product: '<S93>/Product7'
   *  Product: '<S93>/Product8'
   *  Sum: '<S93>/Sum1'
   *  Sum: '<S93>/Sum2'
   *  Sum: '<S93>/Sum3'
   */
  rtb_Multiply4_i_idx_0 = (((0.5F - rtb_Gain_d_tmp_5) - rtb_Square_g) * 2.0F *
    rtb_Sum_hq[0] + (rtb_Sum_i_tmp - rtb_Gain_d_tmp_4) * 2.0F * rtb_Sum_hq[1]) +
    (rtb_Gain_h + rtb_Multiply4_b) * 2.0F * rtb_Multiply4_i_idx_1;

  /* Product: '<S94>/Product2' incorporates:
   *  Product: '<S92>/Divide'
   *  Product: '<S95>/Product2'
   */
  rtb_Divide_f_idx_0 *= rtb_Divide_f_idx_1;

  /* Product: '<S94>/Product3' incorporates:
   *  Product: '<S92>/Divide'
   *  Product: '<S95>/Product3'
   */
  rtb_Sum_mx_tmp = rtb_Divide_f_idx_2 * rtb_Divide_f_idx_3;

  /* Sum: '<S94>/Sum3' incorporates:
   *  Constant: '<S94>/Constant'
   *  Product: '<S92>/Divide'
   *  Product: '<S94>/Product6'
   *  Sum: '<S95>/Sum3'
   */
  rtb_Divide_f_idx_1 = 0.5F - rtb_Divide_f_idx_1 * rtb_Divide_f_idx_1;

  /* Sum: '<S94>/Sum' incorporates:
   *  Gain: '<S94>/Gain'
   *  Gain: '<S94>/Gain1'
   *  Gain: '<S94>/Gain2'
   *  Product: '<S94>/Product2'
   *  Product: '<S94>/Product3'
   *  Product: '<S94>/Product4'
   *  Product: '<S94>/Product5'
   *  Product: '<S94>/Product8'
   *  Sum: '<S94>/Sum1'
   *  Sum: '<S94>/Sum2'
   *  Sum: '<S94>/Sum3'
   */
  rtb_Divide_f_idx_2 = ((rtb_Divide_f_idx_1 - rtb_Square_g) * 2.0F * rtb_Sum_hq
                        [1] + (rtb_Sum_i_tmp + rtb_Gain_d_tmp_4) * 2.0F *
                        rtb_Sum_hq[0]) + (rtb_Sum_mx_tmp - rtb_Divide_f_idx_0) *
    2.0F * rtb_Multiply4_i_idx_1;

  /* Sum: '<S95>/Sum' incorporates:
   *  Gain: '<S95>/Gain1'
   *  Gain: '<S95>/Gain2'
   *  Gain: '<S95>/Gain3'
   *  Product: '<S95>/Product4'
   *  Product: '<S95>/Product5'
   *  Product: '<S95>/Product8'
   *  Sum: '<S95>/Sum1'
   *  Sum: '<S95>/Sum2'
   *  Sum: '<S95>/Sum3'
   */
  rtb_Divide_f_idx_0 = ((rtb_Gain_h - rtb_Multiply4_b) * 2.0F * rtb_Sum_hq[0] +
                        (rtb_Divide_f_idx_0 + rtb_Sum_mx_tmp) * 2.0F *
                        rtb_Sum_hq[1]) + (rtb_Divide_f_idx_1 - rtb_Gain_d_tmp_5)
    * 2.0F * rtb_Multiply4_i_idx_1;

  /* Math: '<S70>/Square1' incorporates:
   *  Product: '<S76>/Divide'
   */
  rtb_Divide_f_idx_1 = rtb_Switch_idx_2 * rtb_Switch_idx_2;

  /* Product: '<S70>/Multiply6' incorporates:
   *  Constant: '<S70>/Constant'
   *  Product: '<S70>/Multiply4'
   *  Product: '<S70>/Multiply5'
   *  Product: '<S76>/Divide'
   *  Sum: '<S70>/Subtract'
   */
  rtb_Multiply4_i_idx_1 = (rtb_Switch * rtb_Switch_idx_2 - rtb_Switch_idx_3 *
    rtb_Add_e) * 2.0F;

  /* Update for UnitDelay: '<S68>/Delay Input1' incorporates:
   *  Inport: '<Root>/States_Init'
   *
   * Block description for '<S68>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Plant_DW.DelayInput1_DSTATE = Plant_U.States_Init.timestamp;

  /* Update for DiscreteIntegrator: '<S71>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_IC_LOADI = 0U;

  /* Product: '<S71>/Multiply' incorporates:
   *  DiscreteIntegrator: '<S71>/Discrete-Time Integrator'
   */
  for (i = 0; i < 4; i++) {
    rtb_Gain_h = rtb_MatrixConcatenate4[i + 12] *
      Plant_DW.DiscreteTimeIntegrator_DSTATE_d[3] + (rtb_MatrixConcatenate4[i +
      8] * Plant_DW.DiscreteTimeIntegrator_DSTATE_d[2] +
      (rtb_MatrixConcatenate4[i + 4] * Plant_DW.DiscreteTimeIntegrator_DSTATE_d
       [1] + rtb_MatrixConcatenate4[i] *
       Plant_DW.DiscreteTimeIntegrator_DSTATE_d[0]));
    rtb_Divide_g[i] = rtb_Gain_h;
  }

  /* End of Product: '<S71>/Multiply' */

  /* Update for DiscreteIntegrator: '<S71>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S71>/Gain'
   */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_d[0] += 0.5F * rtb_Divide_g[0] * 0.002F;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_d[1] += 0.5F * rtb_Divide_g[1] * 0.002F;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_d[2] += 0.5F * rtb_Divide_g[2] * 0.002F;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_d[3] += 0.5F * rtb_Divide_g[3] * 0.002F;
  Plant_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)rtb_Compare_o_idx_1;

  /* Product: '<S65>/Divide' incorporates:
   *  Constant: '<S65>/Inertia_Matrix'
   */
  rt_mldivide_U1f3x3_U2f3_Yf3x1(Plant_ConstP.pooled23, rtb_Sum_b, tmp);

  /* Update for DiscreteIntegrator: '<S65>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_PrevRe_d = (int8_T)rtb_Compare_o_idx_2;

  /* Update for UnitDelay: '<S82>/Delay Input1' incorporates:
   *  Inport: '<Root>/States_Init'
   *
   * Block description for '<S82>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Plant_DW.DelayInput1_DSTATE_f = Plant_U.States_Init.timestamp;

  /* Update for DiscreteIntegrator: '<S66>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_PrevRe_k = (int8_T)rtb_Compare_o_idx_0;

  /* Update for DiscreteIntegrator: '<S66>/Discrete-Time Integrator1' */
  Plant_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;

  /* Update for DiscreteIntegrator: '<S65>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0] += 0.002F * tmp[0];

  /* Update for DiscreteIntegrator: '<S66>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_f[0] += 0.002F * rtb_Multiply4_i_idx_0;

  /* Update for DiscreteIntegrator: '<S66>/Discrete-Time Integrator1' */
  Plant_DW.DiscreteTimeIntegrator1_DSTATE[0] += 0.002F * rtb_Square_h[0];

  /* Update for DiscreteIntegrator: '<S65>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1] += 0.002F * tmp[1];

  /* Update for DiscreteIntegrator: '<S66>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_f[1] += 0.002F * rtb_Divide_f_idx_2;

  /* Update for DiscreteIntegrator: '<S66>/Discrete-Time Integrator1' */
  Plant_DW.DiscreteTimeIntegrator1_DSTATE[1] += 0.002F * rtb_Square_h[1];

  /* Update for DiscreteIntegrator: '<S65>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2] += 0.002F * tmp[2];

  /* Update for DiscreteIntegrator: '<S66>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_f[2] += 0.002F * rtb_Divide_f_idx_0;

  /* Update for DiscreteIntegrator: '<S66>/Discrete-Time Integrator1' */
  Plant_DW.DiscreteTimeIntegrator1_DSTATE[2] += 0.002F * rtb_Square_h[2];
  Plant_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)rtb_Compare_o_idx_3;

  /* End of Outputs for SubSystem: '<Root>/Kinematic_Equation' */

  /* Outputs for Atomic SubSystem: '<Root>/Bus_Constructor' */
  /* Sqrt: '<S28>/Sqrt' incorporates:
   *  Math: '<S28>/Square'
   *  Sum: '<S28>/Sum of Elements'
   */
  rtb_Gain_h = sqrtf(((rtb_MathFunction1_c * rtb_MathFunction1_c + rtb_Product8 *
                       rtb_Product8) + rtb_Switch_idx_0 * rtb_Switch_idx_0) +
                     rtb_Switch_idx_1 * rtb_Switch_idx_1);

  /* Product: '<S24>/Divide' */
  rtb_Gain_d_tmp_5 = rtb_MathFunction1_c / rtb_Gain_h;
  rtb_Gain_d_tmp_4 = rtb_Product8 / rtb_Gain_h;
  rtb_Sum_mx_tmp = rtb_Switch_idx_0 / rtb_Gain_h;
  rtb_Sum_i_tmp = rtb_Switch_idx_1 / rtb_Gain_h;

  /* Math: '<S25>/Square' incorporates:
   *  Math: '<S26>/Square'
   *  Math: '<S27>/Square'
   *  Product: '<S24>/Divide'
   */
  rtb_Gain_h = rtb_Gain_d_tmp_5 * rtb_Gain_d_tmp_5;

  /* Math: '<S25>/Square2' incorporates:
   *  Math: '<S26>/Square2'
   *  Math: '<S27>/Square2'
   *  Product: '<S24>/Divide'
   */
  rtb_Multiply4_b = rtb_Sum_mx_tmp * rtb_Sum_mx_tmp;

  /* Math: '<S25>/Square1' incorporates:
   *  Math: '<S26>/Square1'
   *  Math: '<S27>/Square1'
   *  Product: '<S24>/Divide'
   */
  rtb_Square_g = rtb_Gain_d_tmp_4 * rtb_Gain_d_tmp_4;

  /* Math: '<S25>/Square3' incorporates:
   *  Math: '<S26>/Square3'
   *  Math: '<S27>/Square3'
   *  Product: '<S24>/Divide'
   */
  rtb_Divide_f_idx_3 = rtb_Sum_i_tmp * rtb_Sum_i_tmp;

  /* Sum: '<S25>/Subtract' incorporates:
   *  Math: '<S25>/Square'
   *  Math: '<S25>/Square1'
   *  Math: '<S25>/Square2'
   *  Math: '<S25>/Square3'
   *  Sum: '<S25>/Add'
   *  Sum: '<S25>/Add1'
   */
  rtb_MatrixConcatenate1[0] = (rtb_Gain_h + rtb_Square_g) - (rtb_Multiply4_b +
    rtb_Divide_f_idx_3);

  /* Product: '<S25>/Multiply' incorporates:
   *  Product: '<S24>/Divide'
   *  Product: '<S26>/Multiply'
   */
  rtb_Gain_d_tmp = rtb_Gain_d_tmp_4 * rtb_Sum_mx_tmp;

  /* Product: '<S25>/Multiply1' incorporates:
   *  Product: '<S24>/Divide'
   *  Product: '<S26>/Multiply1'
   */
  rtb_Gain_d_tmp_0 = rtb_Gain_d_tmp_5 * rtb_Sum_i_tmp;

  /* Gain: '<S25>/Gain' incorporates:
   *  Product: '<S25>/Multiply'
   *  Product: '<S25>/Multiply1'
   *  Sum: '<S25>/Subtract1'
   */
  rtb_MatrixConcatenate1[1] = (rtb_Gain_d_tmp - rtb_Gain_d_tmp_0) * 2.0F;

  /* Product: '<S25>/Multiply2' incorporates:
   *  Product: '<S24>/Divide'
   *  Product: '<S27>/Multiply'
   */
  rtb_Gain_d_tmp_1 = rtb_Gain_d_tmp_4 * rtb_Sum_i_tmp;

  /* Product: '<S25>/Multiply3' incorporates:
   *  Product: '<S24>/Divide'
   *  Product: '<S27>/Multiply1'
   */
  rtb_Gain_d_tmp_2 = rtb_Gain_d_tmp_5 * rtb_Sum_mx_tmp;

  /* Gain: '<S25>/Gain1' incorporates:
   *  Product: '<S25>/Multiply2'
   *  Product: '<S25>/Multiply3'
   *  Sum: '<S25>/Add2'
   */
  rtb_MatrixConcatenate1[2] = (rtb_Gain_d_tmp_1 + rtb_Gain_d_tmp_2) * 2.0F;

  /* Gain: '<S26>/Gain' incorporates:
   *  Sum: '<S26>/Add3'
   */
  rtb_MatrixConcatenate1[3] = (rtb_Gain_d_tmp + rtb_Gain_d_tmp_0) * 2.0F;

  /* Sum: '<S26>/Subtract' incorporates:
   *  Sum: '<S26>/Add'
   *  Sum: '<S26>/Add1'
   */
  rtb_MatrixConcatenate1[4] = (rtb_Gain_h + rtb_Multiply4_b) - (rtb_Square_g +
    rtb_Divide_f_idx_3);

  /* Product: '<S26>/Multiply2' incorporates:
   *  Product: '<S24>/Divide'
   *  Product: '<S27>/Multiply2'
   */
  rtb_Gain_d_tmp = rtb_Sum_mx_tmp * rtb_Sum_i_tmp;

  /* Product: '<S26>/Multiply3' incorporates:
   *  Product: '<S24>/Divide'
   *  Product: '<S27>/Multiply3'
   */
  rtb_Gain_d_tmp_0 = rtb_Gain_d_tmp_5 * rtb_Gain_d_tmp_4;

  /* Gain: '<S26>/Gain1' incorporates:
   *  Product: '<S26>/Multiply2'
   *  Product: '<S26>/Multiply3'
   *  Sum: '<S26>/Subtract1'
   */
  rtb_MatrixConcatenate1[5] = (rtb_Gain_d_tmp - rtb_Gain_d_tmp_0) * 2.0F;

  /* Gain: '<S27>/Gain' incorporates:
   *  Sum: '<S27>/Subtract2'
   */
  rtb_MatrixConcatenate1[6] = (rtb_Gain_d_tmp_1 - rtb_Gain_d_tmp_2) * 2.0F;

  /* Gain: '<S27>/Gain1' incorporates:
   *  Sum: '<S27>/Add2'
   */
  rtb_MatrixConcatenate1[7] = (rtb_Gain_d_tmp + rtb_Gain_d_tmp_0) * 2.0F;

  /* Sum: '<S27>/Subtract' incorporates:
   *  Sum: '<S27>/Add'
   *  Sum: '<S27>/Add1'
   */
  rtb_MatrixConcatenate1[8] = (rtb_Gain_h + rtb_Divide_f_idx_3) - (rtb_Square_g
    + rtb_Multiply4_b);

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
  Plant_Y.Extended_States.prop_vel[0] = rtb_DiscreteTimeIntegrator_l__2;
  Plant_Y.Extended_States.prop_vel[4] = 0.0F;
  Plant_Y.Extended_States.prop_vel[1] = rtb_DiscreteTimeIntegrator_l__1;
  Plant_Y.Extended_States.prop_vel[5] = 0.0F;
  Plant_Y.Extended_States.prop_vel[2] = rtb_DiscreteTimeIntegrator_l__0;
  Plant_Y.Extended_States.prop_vel[6] = 0.0F;
  Plant_Y.Extended_States.prop_vel[3] = rtb_DiscreteTimeIntegrator_l_id;
  Plant_Y.Extended_States.prop_vel[7] = 0.0F;
  for (i = 0; i < 9; i++) {
    Plant_Y.Extended_States.M_BO[i] = rtb_MatrixConcatenate1[i];
    Plant_Y.Extended_States.M_OB[i] = rtb_VectorConcatenate_f[i];
  }

  Plant_Y.Extended_States.quat[0] = rtb_MathFunction1_c;
  Plant_Y.Extended_States.quat[1] = rtb_Product8;
  Plant_Y.Extended_States.quat[2] = rtb_Switch_idx_0;
  Plant_Y.Extended_States.quat[3] = rtb_Switch_idx_1;

  /* End of BusAssignment: '<S2>/Bus Assignment2' */

  /* Delay: '<S23>/Delay1' incorporates:
   *  Constant: '<S23>/Constant1'
   *  Constant: '<S23>/Constant2'
   *  Constant: '<S23>/Constant3'
   *  SignalConversion: '<S23>/TmpSignal ConversionAtDelay1Inport2'
   */
  if (Plant_DW.icLoad != 0) {
    Plant_DW.Delay1_DSTATE_n[0] = PLANT_PARAM.LAT_0;
    Plant_DW.Delay1_DSTATE_n[1] = PLANT_PARAM.LON_0;
    Plant_DW.Delay1_DSTATE_n[2] = PLANT_PARAM.ALT_0;
  }

  /* Trigonometry: '<S29>/Trigonometric Function1' incorporates:
   *  Delay: '<S23>/Delay1'
   *  Trigonometry: '<S29>/Trigonometric Function2'
   */
  rtb_Add_idx_1 = cos(Plant_DW.Delay1_DSTATE_n[0]);

  /* Trigonometry: '<S29>/Trigonometric Function' incorporates:
   *  Delay: '<S23>/Delay1'
   */
  rtb_SumofElements = sin(Plant_DW.Delay1_DSTATE_n[0]);

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
  rtb_SumofElements1 = (1.0 - rtb_Add_idx_1 * rtb_Add_idx_1 *
                        Plant_ConstB.Product1) * rtb_SumofElements +
    Plant_DW.Delay1_DSTATE_n[2];

  /* Sum: '<S29>/Add1' incorporates:
   *  Delay: '<S23>/Delay1'
   */
  rtb_SumofElements += Plant_DW.Delay1_DSTATE_n[2];

  /* Product: '<S29>/Product4' */
  rtb_SumofElements *= rtb_Add_idx_1;

  /* Signum: '<S30>/Sign' */
  if (rtb_SumofElements1 < 0.0) {
    rtb_Divide2_idx_0 = -1.0;
  } else if (rtb_SumofElements1 > 0.0) {
    rtb_Divide2_idx_0 = 1.0;
  } else {
    rtb_Divide2_idx_0 = rtb_SumofElements1;
  }

  if (rtb_SumofElements < 0.0) {
    rtb_Divide2_idx_1 = -1.0;
  } else if (rtb_SumofElements > 0.0) {
    rtb_Divide2_idx_1 = 1.0;
  } else {
    rtb_Divide2_idx_1 = rtb_SumofElements;
  }

  /* End of Signum: '<S30>/Sign' */

  /* Switch: '<S30>/Switch' incorporates:
   *  Constant: '<S30>/Constant'
   */
  rtb_Add_idx_1 = rtb_Divide2_idx_0;
  if (rtb_Divide2_idx_0 == 0.0) {
    rtb_Add_idx_1 = 1.0;
  }

  rtb_Divide2_idx_0 = rtb_Add_idx_1;
  rtb_Add_idx_1 = rtb_Divide2_idx_1;
  if (rtb_Divide2_idx_1 == 0.0) {
    rtb_Add_idx_1 = 1.0;
  }

  /* End of Switch: '<S30>/Switch' */

  /* BusAssignment: '<S2>/Bus Assignment1' incorporates:
   *  BusAssignment: '<S2>/Bus Assignment'
   *  Constant: '<S2>/Constant'
   *  Delay: '<Root>/Delay'
   */
  Plant_Y.Plant_States = Plant_rtZPlant_States_Bus;

  /* Outputs for Atomic SubSystem: '<Root>/Kinematic_Equation' */
  /* BusAssignment: '<S2>/Bus Assignment' incorporates:
   *  BusAssignment: '<S2>/Bus Assignment1'
   *  Constant: '<S70>/Constant'
   *  Constant: '<S70>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Math: '<S70>/Square'
   *  Product: '<S70>/Multiply'
   *  Product: '<S70>/Multiply1'
   *  Product: '<S70>/Multiply2'
   *  Product: '<S70>/Multiply3'
   *  Product: '<S76>/Divide'
   *  Sum: '<S70>/Add'
   *  Sum: '<S70>/Add1'
   *  Sum: '<S70>/Subtract2'
   *  Trigonometry: '<S70>/Atan2'
   */
  Plant_Y.Plant_States.phi = atan2f((rtb_Switch * rtb_Add_e + rtb_Switch_idx_2 *
    rtb_Switch_idx_3) * 2.0F, 1.0F - (rtb_Add_e * rtb_Add_e + rtb_Divide_f_idx_1)
    * 2.0F);

  /* End of Outputs for SubSystem: '<Root>/Bus_Constructor' */

  /* Saturate: '<S70>/Saturation' */
  if (rtb_Multiply4_i_idx_1 > 1.0F) {
    rtb_Multiply4_i_idx_1 = 1.0F;
  } else {
    if (rtb_Multiply4_i_idx_1 < -1.0F) {
      rtb_Multiply4_i_idx_1 = -1.0F;
    }
  }

  /* End of Saturate: '<S70>/Saturation' */

  /* Outputs for Atomic SubSystem: '<Root>/Bus_Constructor' */
  /* BusAssignment: '<S2>/Bus Assignment' incorporates:
   *  BusAssignment: '<S2>/Bus Assignment1'
   *  Constant: '<S70>/Constant'
   *  Constant: '<S70>/Constant1'
   *  Delay: '<Root>/Delay'
   *  Math: '<S70>/Square2'
   *  Product: '<S70>/Multiply10'
   *  Product: '<S70>/Multiply7'
   *  Product: '<S70>/Multiply8'
   *  Product: '<S70>/Multiply9'
   *  Product: '<S76>/Divide'
   *  Sum: '<S70>/Add2'
   *  Sum: '<S70>/Add3'
   *  Sum: '<S70>/Subtract1'
   *  Trigonometry: '<S70>/Asin'
   *  Trigonometry: '<S70>/Atan1'
   */
  Plant_Y.Plant_States.theta = asinf(rtb_Multiply4_i_idx_1);
  Plant_Y.Plant_States.psi = atan2f((rtb_Switch * rtb_Switch_idx_3 + rtb_Add_e *
    rtb_Switch_idx_2) * 2.0F, 1.0F - (rtb_Switch_idx_3 * rtb_Switch_idx_3 +
    rtb_Divide_f_idx_1) * 2.0F);

  /* End of Outputs for SubSystem: '<Root>/Kinematic_Equation' */
  Plant_Y.Plant_States.rot_x_B = rtb_Sum_p[0];
  Plant_Y.Plant_States.rot_y_B = rtb_Sum_p[1];
  Plant_Y.Plant_States.rot_z_B = rtb_Sum_p[2];
  Plant_Y.Plant_States.acc_x_O = rtb_Multiply4_i_idx_0;
  Plant_Y.Plant_States.acc_y_O = rtb_Divide_f_idx_2;
  Plant_Y.Plant_States.acc_z_O = rtb_Divide_f_idx_0;
  Plant_Y.Plant_States.vel_x_O = rtb_Square_h[0];
  Plant_Y.Plant_States.vel_y_O = rtb_Square_h[1];
  Plant_Y.Plant_States.vel_z_O = rtb_Square_h[2];

  /* Abs: '<S30>/Abs' */
  rtb_Divide2_idx_1 = fabs(rtb_SumofElements1);

  /* Saturate: '<S30>/Saturation' */
  if (rtb_Divide2_idx_1 > 1.0E+8) {
    rtb_Divide2_idx_1 = 1.0E+8;
  } else {
    if (rtb_Divide2_idx_1 < 1.0E-6) {
      rtb_Divide2_idx_1 = 1.0E-6;
    }
  }

  /* Sum: '<S23>/Add' incorporates:
   *  DataTypeConversion: '<S23>/Data Type Conversion'
   *  Delay: '<S23>/Delay'
   *  Delay: '<S23>/Delay1'
   *  Product: '<S23>/Divide'
   *  Product: '<S30>/Product'
   *  Sum: '<S23>/Subtract'
   */
  rtb_SumofElements1 = 1.0 / (rtb_Divide2_idx_1 * rtb_Divide2_idx_0) *
    (rtb_DiscreteTimeIntegrator1[0] - Plant_DW.Delay_DSTATE_a[0]) +
    Plant_DW.Delay1_DSTATE_n[0];

  /* Abs: '<S30>/Abs' */
  rtb_Divide2_idx_1 = fabs(rtb_SumofElements);

  /* Saturate: '<S30>/Saturation' */
  if (rtb_Divide2_idx_1 > 1.0E+8) {
    rtb_Divide2_idx_1 = 1.0E+8;
  } else {
    if (rtb_Divide2_idx_1 < 1.0E-6) {
      rtb_Divide2_idx_1 = 1.0E-6;
    }
  }

  /* Sum: '<S23>/Add' incorporates:
   *  DataTypeConversion: '<S23>/Data Type Conversion'
   *  Delay: '<S23>/Delay'
   *  Delay: '<S23>/Delay1'
   *  Product: '<S23>/Divide'
   *  Product: '<S30>/Product'
   *  Sum: '<S23>/Subtract'
   */
  rtb_Add_idx_1 = 1.0 / (rtb_Divide2_idx_1 * rtb_Add_idx_1) *
    (rtb_DiscreteTimeIntegrator1[1] - Plant_DW.Delay_DSTATE_a[1]) +
    Plant_DW.Delay1_DSTATE_n[1];
  rtb_Divide2_idx_0 = -(rtb_DiscreteTimeIntegrator1[2] -
                        Plant_DW.Delay_DSTATE_a[2]) + Plant_DW.Delay1_DSTATE_n[2];

  /* BusAssignment: '<S2>/Bus Assignment1' incorporates:
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant2'
   *  Constant: '<S2>/Constant3'
   *  Delay: '<Root>/Delay'
   *  Delay: '<S21>/Delay'
   *  Gain: '<S2>/Gain'
   */
  Plant_Y.Plant_States.x_R = rtb_DiscreteTimeIntegrator1[0];
  Plant_Y.Plant_States.y_R = rtb_DiscreteTimeIntegrator1[1];
  Plant_Y.Plant_States.h_R = -rtb_DiscreteTimeIntegrator1[2];
  Plant_Y.Plant_States.lat = rtb_SumofElements1;
  Plant_Y.Plant_States.lon = rtb_Add_idx_1;
  Plant_Y.Plant_States.alt = rtb_Divide2_idx_0;
  Plant_Y.Plant_States.lat_0 = PLANT_PARAM.LAT_0;
  Plant_Y.Plant_States.lon_0 = PLANT_PARAM.LON_0;
  Plant_Y.Plant_States.alt_0 = PLANT_PARAM.ALT_0;
  Plant_Y.Plant_States.timestamp = Plant_DW.Delay_DSTATE_c;

  /* Sum: '<S21>/Sum' incorporates:
   *  Constant: '<S21>/dt'
   *  Delay: '<S21>/Delay'
   */
  Plant_DW.Delay_DSTATE_c += PLANT_EXPORT.period;

  /* Update for Delay: '<S23>/Delay1' */
  Plant_DW.icLoad = 0U;

  /* Update for Delay: '<S23>/Delay' incorporates:
   *  DataTypeConversion: '<S23>/Data Type Conversion'
   */
  Plant_DW.Delay_DSTATE_a[0] = rtb_DiscreteTimeIntegrator1[0];

  /* Update for Delay: '<S23>/Delay1' */
  Plant_DW.Delay1_DSTATE_n[0] = rtb_SumofElements1;

  /* Update for Delay: '<S23>/Delay' incorporates:
   *  DataTypeConversion: '<S23>/Data Type Conversion'
   */
  Plant_DW.Delay_DSTATE_a[1] = rtb_DiscreteTimeIntegrator1[1];

  /* Update for Delay: '<S23>/Delay1' */
  Plant_DW.Delay1_DSTATE_n[1] = rtb_Add_idx_1;

  /* Update for Delay: '<S23>/Delay' incorporates:
   *  DataTypeConversion: '<S23>/Data Type Conversion'
   */
  Plant_DW.Delay_DSTATE_a[2] = rtb_DiscreteTimeIntegrator1[2];

  /* Update for Delay: '<S23>/Delay1' */
  Plant_DW.Delay1_DSTATE_n[2] = rtb_Divide2_idx_0;

  /* End of Outputs for SubSystem: '<Root>/Bus_Constructor' */

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_Model' */
  /* Outputs for Atomic SubSystem: '<S6>/Sensor_Barometer' */
  /* Saturate: '<S106>/Limit  altitude  to troposhere' incorporates:
   *  DataTypeConversion: '<S104>/Data Type Conversion'
   *  Delay: '<Root>/Delay'
   */
  if ((real32_T)Plant_Y.Plant_States.alt > 11000.0F) {
    rtb_Gain_d_tmp_5 = 11000.0F;
  } else if ((real32_T)Plant_Y.Plant_States.alt < 0.0F) {
    rtb_Gain_d_tmp_5 = 0.0F;
  } else {
    rtb_Gain_d_tmp_5 = (real32_T)Plant_Y.Plant_States.alt;
  }

  /* End of Saturate: '<S106>/Limit  altitude  to troposhere' */

  /* Sum: '<S106>/Sum1' incorporates:
   *  Constant: '<S106>/Sea Level  Temperature'
   *  Gain: '<S106>/Lapse Rate'
   */
  rtb_Divide_f_idx_2 = 288.15F - 0.0065F * rtb_Gain_d_tmp_5;

  /* Sum: '<S106>/Sum' incorporates:
   *  Constant: '<S106>/Altitude of Troposphere'
   *  DataTypeConversion: '<S104>/Data Type Conversion'
   *  Delay: '<Root>/Delay'
   */
  rtb_MathFunction1_c = 11000.0F - (real32_T)Plant_Y.Plant_States.alt;

  /* Saturate: '<S106>/Limit  altitude  to Stratosphere' incorporates:
   *  Constant: '<S106>/Altitude of Troposphere'
   *  DataTypeConversion: '<S104>/Data Type Conversion'
   *  Delay: '<Root>/Delay'
   *  Sum: '<S106>/Sum'
   */
  if (11000.0F - (real32_T)Plant_Y.Plant_States.alt > 0.0F) {
    rtb_MathFunction1_c = 0.0F;
  } else {
    if (11000.0F - (real32_T)Plant_Y.Plant_States.alt < -9000.0F) {
      rtb_MathFunction1_c = -9000.0F;
    }
  }

  /* End of Saturate: '<S106>/Limit  altitude  to Stratosphere' */

  /* Product: '<S106>/Product2' incorporates:
   *  Constant: '<S106>/Constant'
   *  Gain: '<S106>/1//T0'
   *  Gain: '<S106>/P0'
   *  Gain: '<S106>/g//R'
   *  Math: '<S106>/(T//T0)^(g//LR) '
   *  Math: '<S106>/Stratosphere Model'
   *  Product: '<S106>/Product1'
   *
   * About '<S106>/Stratosphere Model':
   *  Operator: exp
   */
  rtb_DiscreteTimeIntegrator_l__2 = powf(0.00347041478F * rtb_Divide_f_idx_2,
    5.25587559F) * 101325.0F * expf(1.0F / rtb_Divide_f_idx_2 * (0.0341631919F *
    rtb_MathFunction1_c));

  /* S-Function (sdsprandsrc2): '<S108>/Random Source' */
  RandSrc_GZ_R(&rtb_MathFunction1_c, &Plant_ConstP.pooled14, 1,
               &Plant_ConstP.pooled29, 1, Plant_DW.RandomSource_STATE_DWORK_b, 1,
               1);

  /* BusAssignment: '<S103>/Bus Assignment' incorporates:
   *  Constant: '<S103>/Constant2'
   *  DataTypeConversion: '<S103>/Data Type Conversion1'
   *  Memory: '<S97>/Memory1'
   *  Saturate: '<S105>/Saturation'
   *  Sum: '<S103>/Sum1'
   *  Sum: '<S105>/Add'
   */
  rtb_BusAssignment_i.timestamp = Plant_DW.Memory1_PreviousInput;
  rtb_BusAssignment_i.pressure = rtb_DiscreteTimeIntegrator_l__2 +
    rtb_MathFunction1_c;
  rtb_BusAssignment_i.temperature = (real32_T)(rtb_Divide_f_idx_2 - 273.15);

  /* RateTransition: '<S103>/Rate Transition' */
  if (Plant_M->Timing.TaskCounters.TID[1] == 0) {
    Plant_B.RateTransition_m = rtb_BusAssignment_i;
  }

  /* End of RateTransition: '<S103>/Rate Transition' */
  /* End of Outputs for SubSystem: '<S6>/Sensor_Barometer' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_GPS' */
  /* Trigonometry: '<S121>/Sin' incorporates:
   *  Delay: '<S114>/Delay'
   */
  rtb_SumofElements = sin(Plant_DW.Delay_DSTATE[0]);

  /* Math: '<S121>/Square1' */
  rtb_SumofElements *= rtb_SumofElements;

  /* Product: '<S121>/Multiply1' incorporates:
   *  Product: '<S121>/Multiply'
   */
  rtb_SumofElements1 = Plant_ConstB.ff * rtb_SumofElements;

  /* Product: '<S121>/Divide' incorporates:
   *  Constant: '<S121>/Constant'
   *  Constant: '<S121>/R'
   *  Sqrt: '<S121>/Sqrt'
   *  Sum: '<S121>/Sum1'
   */
  rtb_SumofElements = 6.378137E+6 / sqrt(1.0 - rtb_SumofElements1);

  /* S-Function (sdsprandsrc2): '<S117>/Random Source' */
  RandSrc_GZ_R(rtb_RandomSource, &Plant_ConstP.pooled14, 1,
               Plant_ConstP.RandomSource_VarianceRTP, 3,
               Plant_DW.RandomSource_STATE_DWORK_l, 3, 1);

  /* Sum: '<S115>/Sum2' incorporates:
   *  Constant: '<S121>/Constant1'
   *  Delay: '<S114>/Delay'
   *  Product: '<S118>/Divide2'
   *  Product: '<S121>/Multiply1'
   *  Product: '<S121>/Multiply2'
   *  Product: '<S121>/Product3'
   *  Sum: '<S121>/Sum2'
   *  Trigonometry: '<S121>/Cos'
   */
  rtb_SumofElements1 = rtb_RandomSource[0] / (1.0 / (1.0 - rtb_SumofElements1) *
    Plant_ConstB.Sum4 * rtb_SumofElements) + Plant_DW.Delay_DSTATE[0];
  rtb_Add_idx_1 = rtb_RandomSource[1] / (rtb_SumofElements * cos
    (Plant_DW.Delay_DSTATE[0])) + Plant_DW.Delay_DSTATE[1];
  rtb_Divide2_idx_0 = rtb_RandomSource[2] / -1.0 + Plant_DW.Delay_DSTATE[2];

  /* S-Function (sdsprandsrc2): '<S117>/Random Source1' */
  RandSrc_GZ_R(rtb_RandomSource1, &Plant_ConstP.pooled14, 1,
               Plant_ConstP.RandomSource1_VarianceRTP, 3,
               Plant_DW.RandomSource1_STATE_DWORK, 3, 1);

  /* Sum: '<S115>/Sum1' incorporates:
   *  Delay: '<S114>/Delay1'
   */
  rtb_Sum_b[0] = rtb_RandomSource1[0] + Plant_DW.Delay1_DSTATE_a[0];
  rtb_Sum_b[1] = rtb_RandomSource1[1] + Plant_DW.Delay1_DSTATE_a[1];
  rtb_Sum_b[2] = rtb_RandomSource1[2] + Plant_DW.Delay1_DSTATE_a[2];

  /* DiscreteFir: '<S120>/Discrete FIR Filter' */
  rtb_Multiply5_i[0] = rtb_Sum_b[0] * 0.5F +
    Plant_DW.DiscreteFIRFilter_states_f[0] * 0.5F;
  rtb_Multiply5_i[1] = rtb_Sum_b[1] * 0.5F +
    Plant_DW.DiscreteFIRFilter_states_f[1] * 0.5F;

  /* Gain: '<S109>/Gain6' incorporates:
   *  Math: '<S116>/Math Function'
   *  Product: '<S116>/Matrix Multiply'
   *  Sqrt: '<S116>/Sqrt'
   *  Switch: '<S116>/Switch'
   */
  rtb_SumofElements = fmod(floor(sqrtf(rtb_RandomSource[0] * rtb_RandomSource[0]
    + rtb_RandomSource[1] * rtb_RandomSource[1]) * 1000.0), 4.294967296E+9);

  /* DataTypeConversion: '<S109>/Data Type Conversion' incorporates:
   *  Delay: '<S115>/Delay1'
   */
  rtb_Product1 = fmod(floor(Plant_DW.Delay1_DSTATE[0]), 256.0);

  /* Gain: '<S109>/Gain4' incorporates:
   *  DiscreteFir: '<S119>/Discrete FIR Filter'
   */
  rtb_Divide2_idx_1 = fmod(floor((rtb_Divide2_idx_0 * 0.5 +
    Plant_DW.DiscreteFIRFilter_states[2] * 0.5) * 1000.0), 4.294967296E+9);
  i = rtb_Divide2_idx_1 < 0.0 ? -(int32_T)(uint32_T)-rtb_Divide2_idx_1 :
    (int32_T)(uint32_T)rtb_Divide2_idx_1;

  /* Gain: '<S109>/Gain5' incorporates:
   *  Math: '<S116>/Math Function2'
   *  Product: '<S116>/Matrix Multiply2'
   *  Sqrt: '<S116>/Sqrt2'
   *  Switch: '<S116>/Switch1'
   */
  rtb_Divide2_idx_1 = fmod(floor(sqrtf(rtb_RandomSource[2] * rtb_RandomSource[2])
    * 1000.0), 4.294967296E+9);

  /* BusAssignment: '<S109>/Bus Assignment' incorporates:
   *  Constant: '<S109>/Constant10'
   *  Constant: '<S109>/Constant11'
   *  Constant: '<S109>/Constant12'
   *  Constant: '<S109>/Constant2'
   *  Constant: '<S109>/Constant3'
   *  Constant: '<S109>/Constant4'
   *  Constant: '<S109>/Constant5'
   *  Constant: '<S109>/Constant6'
   *  Constant: '<S109>/Constant7'
   *  Constant: '<S109>/Constant8'
   *  Constant: '<S109>/Constant9'
   *  DataTypeConversion: '<S109>/Data Type Conversion'
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
  rtb_BusAssignment_dk.fixType = (uint8_T)(rtb_Product1 < 0.0 ? (int32_T)
    (uint8_T)-(int8_T)(uint8_T)-rtb_Product1 : (int32_T)(uint8_T)rtb_Product1);
  rtb_BusAssignment_dk.flags = 0U;
  rtb_BusAssignment_dk.reserved1 = 0U;

  /* DataTypeConversion: '<S109>/Data Type Conversion1' incorporates:
   *  Delay: '<S115>/Delay'
   */
  rtb_Product1 = fmod(floor(Plant_DW.Delay_DSTATE_i[0]), 256.0);

  /* BusAssignment: '<S109>/Bus Assignment' incorporates:
   *  DataTypeConversion: '<S109>/Data Type Conversion1'
   */
  rtb_BusAssignment_dk.numSV = (uint8_T)(rtb_Product1 < 0.0 ? (int32_T)(uint8_T)
    -(int8_T)(uint8_T)-rtb_Product1 : (int32_T)(uint8_T)rtb_Product1);

  /* Gain: '<S109>/Gain' incorporates:
   *  DiscreteFir: '<S119>/Discrete FIR Filter'
   *  Gain: '<S109>/Gain2'
   */
  rtb_Product1 = fmod(floor((rtb_SumofElements1 * 0.5 +
    Plant_DW.DiscreteFIRFilter_states[0] * 0.5) * 57.295779513082323 * 1.0E+7),
                      4.294967296E+9);

  /* BusAssignment: '<S109>/Bus Assignment' incorporates:
   *  Gain: '<S109>/Gain'
   */
  rtb_BusAssignment_dk.lon = rtb_Product1 < 0.0 ? -(int32_T)(uint32_T)
    -rtb_Product1 : (int32_T)(uint32_T)rtb_Product1;

  /* Gain: '<S109>/Gain1' incorporates:
   *  DiscreteFir: '<S119>/Discrete FIR Filter'
   *  Gain: '<S109>/Gain3'
   */
  rtb_Product1 = fmod(floor((rtb_Add_idx_1 * 0.5 +
    Plant_DW.DiscreteFIRFilter_states[1] * 0.5) * 57.295779513082323 * 1.0E+7),
                      4.294967296E+9);

  /* BusAssignment: '<S109>/Bus Assignment' incorporates:
   *  Gain: '<S109>/Gain1'
   *  Gain: '<S109>/Gain5'
   *  Gain: '<S109>/Gain6'
   */
  rtb_BusAssignment_dk.lat = rtb_Product1 < 0.0 ? -(int32_T)(uint32_T)
    -rtb_Product1 : (int32_T)(uint32_T)rtb_Product1;
  rtb_BusAssignment_dk.height = i;
  rtb_BusAssignment_dk.hMSL = i;
  rtb_BusAssignment_dk.hAcc = rtb_SumofElements < 0.0 ? (uint32_T)-(int32_T)
    (uint32_T)-rtb_SumofElements : (uint32_T)rtb_SumofElements;
  rtb_BusAssignment_dk.vAcc = rtb_Divide2_idx_1 < 0.0 ? (uint32_T)-(int32_T)
    (uint32_T)-rtb_Divide2_idx_1 : (uint32_T)rtb_Divide2_idx_1;

  /* Gain: '<S109>/Gain7' */
  rtb_Gain_d_tmp_5 = fmodf(floorf(1000.0F * rtb_Multiply5_i[0]), 4.2949673E+9F);

  /* BusAssignment: '<S109>/Bus Assignment' incorporates:
   *  Gain: '<S109>/Gain7'
   */
  rtb_BusAssignment_dk.velN = rtb_Gain_d_tmp_5 < 0.0F ? -(int32_T)(uint32_T)
    -rtb_Gain_d_tmp_5 : (int32_T)(uint32_T)rtb_Gain_d_tmp_5;

  /* Gain: '<S109>/Gain8' */
  rtb_Gain_d_tmp_5 = fmodf(floorf(1000.0F * rtb_Multiply5_i[1]), 4.2949673E+9F);

  /* BusAssignment: '<S109>/Bus Assignment' incorporates:
   *  Gain: '<S109>/Gain8'
   */
  rtb_BusAssignment_dk.velE = rtb_Gain_d_tmp_5 < 0.0F ? -(int32_T)(uint32_T)
    -rtb_Gain_d_tmp_5 : (int32_T)(uint32_T)rtb_Gain_d_tmp_5;

  /* Gain: '<S109>/Gain9' incorporates:
   *  DiscreteFir: '<S120>/Discrete FIR Filter'
   */
  rtb_Gain_d_tmp_5 = fmodf(floorf((rtb_Sum_b[2] * 0.5F +
    Plant_DW.DiscreteFIRFilter_states_f[2] * 0.5F) * 1000.0F), 4.2949673E+9F);

  /* BusAssignment: '<S109>/Bus Assignment' incorporates:
   *  Constant: '<S109>/Constant15'
   *  Gain: '<S109>/Gain11'
   *  Gain: '<S109>/Gain9'
   *  Math: '<S111>/Math Function'
   *  Math: '<S111>/Math Function1'
   *  Saturate: '<S111>/Saturation'
   *  Sqrt: '<S111>/Sqrt'
   *  Sum: '<S111>/Add'
   */
  rtb_BusAssignment_dk.velD = rtb_Gain_d_tmp_5 < 0.0F ? -(int32_T)(uint32_T)
    -rtb_Gain_d_tmp_5 : (int32_T)(uint32_T)rtb_Gain_d_tmp_5;
  rtb_BusAssignment_dk.gSpeed = (int32_T)(uint32_T)fmodf(floorf(sqrtf(fmaxf
    (rtb_Multiply5_i[0] * rtb_Multiply5_i[0] + rtb_Multiply5_i[1] *
     rtb_Multiply5_i[1], 0.0F)) * 1000.0F), 4.2949673E+9F);
  rtb_BusAssignment_dk.heading = 0;

  /* Gain: '<S109>/Gain10' incorporates:
   *  Math: '<S116>/Math Function1'
   *  Product: '<S116>/Matrix Multiply1'
   *  Sqrt: '<S116>/Sqrt1'
   *  Switch: '<S116>/Switch2'
   */
  rtb_SumofElements = fmod(floor(sqrtf((rtb_RandomSource1[0] *
    rtb_RandomSource1[0] + rtb_RandomSource1[1] * rtb_RandomSource1[1]) +
    rtb_RandomSource1[2] * rtb_RandomSource1[2]) * 1000.0), 4.294967296E+9);

  /* BusAssignment: '<S109>/Bus Assignment' incorporates:
   *  Constant: '<S109>/Constant14'
   *  Constant: '<S109>/Constant16'
   *  Constant: '<S109>/Constant17'
   *  Gain: '<S109>/Gain10'
   *  Memory: '<S97>/Memory1'
   */
  rtb_BusAssignment_dk.sAcc = rtb_SumofElements < 0.0 ? (uint32_T)-(int32_T)
    (uint32_T)-rtb_SumofElements : (uint32_T)rtb_SumofElements;
  rtb_BusAssignment_dk.headingAcc = 0U;
  rtb_BusAssignment_dk.pDOP = 0U;
  rtb_BusAssignment_dk.reserved2 = 0U;
  rtb_BusAssignment_dk.timestamp = Plant_DW.Memory1_PreviousInput;

  /* RateTransition: '<S109>/Rate Transition' */
  if (Plant_M->Timing.TaskCounters.TID[2] == 0) {
    Plant_B.RateTransition = rtb_BusAssignment_dk;
  }

  /* End of RateTransition: '<S109>/Rate Transition' */

  /* Update for Delay: '<S114>/Delay' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S114>/ConcatBufferAtVector ConcatenateIn1'
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

  /* Update for DiscreteFir: '<S119>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states[0] = rtb_SumofElements1;

  /* Update for Delay: '<S114>/Delay' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S114>/ConcatBufferAtVector ConcatenateIn2'
   */
  Plant_DW.Delay_DSTATE[223] = Plant_Y.Plant_States.lat;

  /* Update for DiscreteFir: '<S119>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states[1] = rtb_Add_idx_1;

  /* Update for Delay: '<S114>/Delay' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S114>/ConcatBufferAtVector ConcatenateIn3'
   */
  Plant_DW.Delay_DSTATE[224] = Plant_Y.Plant_States.alt;

  /* Update for DiscreteFir: '<S119>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states[2] = rtb_Divide2_idx_0;

  /* Update for Delay: '<S114>/Delay1' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S114>/ConcatBufferAtVector Concatenate1In1'
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

  /* Update for DiscreteFir: '<S120>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states_f[0] = rtb_Sum_b[0];

  /* Update for Delay: '<S114>/Delay1' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S114>/ConcatBufferAtVector Concatenate1In2'
   */
  Plant_DW.Delay1_DSTATE_a[148] = Plant_Y.Plant_States.vel_y_O;

  /* Update for DiscreteFir: '<S120>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states_f[1] = rtb_Sum_b[1];

  /* Update for Delay: '<S114>/Delay1' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S114>/ConcatBufferAtVector Concatenate1In3'
   */
  Plant_DW.Delay1_DSTATE_a[149] = Plant_Y.Plant_States.vel_z_O;

  /* Update for DiscreteFir: '<S120>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states_f[2] = rtb_Sum_b[2];
  for (i = 0; i < 249; i++) {
    /* Update for Delay: '<S115>/Delay1' */
    Plant_DW.Delay1_DSTATE[i] = Plant_DW.Delay1_DSTATE[i + 1];

    /* Update for Delay: '<S115>/Delay' */
    Plant_DW.Delay_DSTATE_i[i] = Plant_DW.Delay_DSTATE_i[i + 1];
  }

  /* Update for Delay: '<S115>/Delay1' incorporates:
   *  Constant: '<S115>/Constant2'
   */
  Plant_DW.Delay1_DSTATE[249] = 3.0;

  /* Update for Delay: '<S115>/Delay' incorporates:
   *  Constant: '<S115>/Constant1'
   */
  Plant_DW.Delay_DSTATE_i[249] = 16.0;

  /* End of Outputs for SubSystem: '<S6>/Sensor_GPS' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_IMU' */
  /* Outputs for Atomic SubSystem: '<S126>/Vibration_Model' */
  /* Outputs for Atomic SubSystem: '<S137>/Vibration_Model' */
  /* Product: '<S143>/Divide2' incorporates:
   *  Constant: '<S143>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Product: '<S132>/Divide2'
   */
  rtb_SumofElements1 = Plant_Y.Extended_States.prop_vel[0] / 1047.1975511965977;

  /* End of Outputs for SubSystem: '<S126>/Vibration_Model' */

  /* Math: '<S143>/u^2' */
  rtb_Product1 = rtb_SumofElements1 * rtb_SumofElements1;

  /* Product: '<S139>/Product2' incorporates:
   *  DiscreteIntegrator: '<S139>/Discrete-Time Integrator'
   *  Trigonometry: '<S139>/Trigonometric Function2'
   */
  rtb_SumofElements = arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[0]) *
    rtb_Product1;

  /* Math: '<S143>/u^2' incorporates:
   *  DiscreteIntegrator: '<S139>/Discrete-Time Integrator'
   *  Product: '<S139>/Product1'
   *  Trigonometry: '<S139>/Trigonometric Function1'
   */
  rtb_Product1_idx_0 = arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[0]) *
    rtb_Product1;

  /* Product: '<S143>/Divide2' incorporates:
   *  Constant: '<S143>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Product: '<S132>/Divide2'
   */
  rtb_Add_idx_1 = rtb_SumofElements1;

  /* Outputs for Atomic SubSystem: '<S126>/Vibration_Model' */
  rtb_SumofElements1 = Plant_Y.Extended_States.prop_vel[1] / 1047.1975511965977;

  /* End of Outputs for SubSystem: '<S126>/Vibration_Model' */

  /* Math: '<S143>/u^2' */
  rtb_Product1 = rtb_SumofElements1 * rtb_SumofElements1;

  /* Product: '<S139>/Product2' incorporates:
   *  DiscreteIntegrator: '<S139>/Discrete-Time Integrator'
   *  Trigonometry: '<S139>/Trigonometric Function2'
   */
  rtb_Product2_g_idx_1 = arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[1]) *
    rtb_Product1;

  /* Math: '<S143>/u^2' incorporates:
   *  DiscreteIntegrator: '<S139>/Discrete-Time Integrator'
   *  Product: '<S139>/Product1'
   *  Trigonometry: '<S139>/Trigonometric Function1'
   */
  rtb_Product1_idx_1 = arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[1]) *
    rtb_Product1;

  /* Product: '<S143>/Divide2' incorporates:
   *  Constant: '<S143>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Product: '<S132>/Divide2'
   */
  rtb_Divide2_idx_0 = rtb_SumofElements1;

  /* Outputs for Atomic SubSystem: '<S126>/Vibration_Model' */
  rtb_SumofElements1 = Plant_Y.Extended_States.prop_vel[2] / 1047.1975511965977;

  /* End of Outputs for SubSystem: '<S126>/Vibration_Model' */

  /* Math: '<S143>/u^2' */
  rtb_Product1 = rtb_SumofElements1 * rtb_SumofElements1;

  /* Product: '<S143>/Divide2' incorporates:
   *  Constant: '<S143>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Product: '<S132>/Divide2'
   */
  rtb_Divide2_idx_1 = rtb_SumofElements1;

  /* Outputs for Atomic SubSystem: '<S126>/Vibration_Model' */
  rtb_SumofElements1 = Plant_Y.Extended_States.prop_vel[3] / 1047.1975511965977;

  /* Math: '<S143>/u^2' incorporates:
   *  Math: '<S132>/u^2'
   */
  rtb_SumofElements1 *= rtb_SumofElements1;

  /* End of Outputs for SubSystem: '<S126>/Vibration_Model' */

  /* Sum: '<S139>/Sum of Elements' incorporates:
   *  DiscreteIntegrator: '<S139>/Discrete-Time Integrator'
   *  Math: '<S143>/u^2'
   *  Product: '<S139>/Product2'
   *  Trigonometry: '<S139>/Trigonometric Function2'
   */
  rtb_SumofElements = ((rtb_SumofElements + rtb_Product2_g_idx_1) + arm_sin_f32
                       (Plant_DW.DiscreteTimeIntegrator_DSTATE[2]) *
                       rtb_Product1) + arm_sin_f32
    (Plant_DW.DiscreteTimeIntegrator_DSTATE[3]) * rtb_SumofElements1;

  /* Sum: '<S139>/Sum of Elements1' incorporates:
   *  DiscreteIntegrator: '<S139>/Discrete-Time Integrator'
   *  Math: '<S143>/u^2'
   *  Product: '<S139>/Product1'
   *  Trigonometry: '<S139>/Trigonometric Function1'
   */
  rtb_Product1 = ((rtb_Product1_idx_0 + rtb_Product1_idx_1) + arm_cos_f32
                  (Plant_DW.DiscreteTimeIntegrator_DSTATE[2]) * rtb_Product1) +
    arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[3]) * rtb_SumofElements1;

  /* Outputs for Atomic SubSystem: '<S126>/Vibration_Model' */
  /* Update for DiscreteIntegrator: '<S139>/Discrete-Time Integrator' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S128>/Discrete-Time Integrator'
   */
  rtb_DiscreteTimeIntegrator_l_id = 0.002F * Plant_Y.Extended_States.prop_vel[0];

  /* End of Outputs for SubSystem: '<S126>/Vibration_Model' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE[0] += rtb_DiscreteTimeIntegrator_l_id;

  /* End of Outputs for SubSystem: '<S137>/Vibration_Model' */
  /* End of Outputs for SubSystem: '<S6>/Sensor_IMU' */
  /* End of Outputs for SubSystem: '<Root>/Sensor_Model' */
  rtb_DiscreteTimeIntegrator_l__2 = rtb_DiscreteTimeIntegrator_l_id;

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_Model' */
  /* Outputs for Atomic SubSystem: '<S6>/Sensor_IMU' */
  /* Outputs for Atomic SubSystem: '<S126>/Vibration_Model' */
  /* Outputs for Atomic SubSystem: '<S137>/Vibration_Model' */
  /* Update for DiscreteIntegrator: '<S139>/Discrete-Time Integrator' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S128>/Discrete-Time Integrator'
   */
  rtb_DiscreteTimeIntegrator_l_id = 0.002F * Plant_Y.Extended_States.prop_vel[1];

  /* End of Outputs for SubSystem: '<S126>/Vibration_Model' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE[1] += rtb_DiscreteTimeIntegrator_l_id;

  /* End of Outputs for SubSystem: '<S137>/Vibration_Model' */
  /* End of Outputs for SubSystem: '<S6>/Sensor_IMU' */
  /* End of Outputs for SubSystem: '<Root>/Sensor_Model' */
  rtb_DiscreteTimeIntegrator_l__1 = rtb_DiscreteTimeIntegrator_l_id;

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_Model' */
  /* Outputs for Atomic SubSystem: '<S6>/Sensor_IMU' */
  /* Outputs for Atomic SubSystem: '<S126>/Vibration_Model' */
  /* Outputs for Atomic SubSystem: '<S137>/Vibration_Model' */
  /* Update for DiscreteIntegrator: '<S139>/Discrete-Time Integrator' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S128>/Discrete-Time Integrator'
   */
  rtb_DiscreteTimeIntegrator_l_id = 0.002F * Plant_Y.Extended_States.prop_vel[2];

  /* End of Outputs for SubSystem: '<S126>/Vibration_Model' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE[2] += rtb_DiscreteTimeIntegrator_l_id;

  /* End of Outputs for SubSystem: '<S137>/Vibration_Model' */
  /* End of Outputs for SubSystem: '<S6>/Sensor_IMU' */
  /* End of Outputs for SubSystem: '<Root>/Sensor_Model' */
  rtb_DiscreteTimeIntegrator_l__0 = rtb_DiscreteTimeIntegrator_l_id;

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_Model' */
  /* Outputs for Atomic SubSystem: '<S6>/Sensor_IMU' */
  /* Outputs for Atomic SubSystem: '<S126>/Vibration_Model' */
  /* Outputs for Atomic SubSystem: '<S137>/Vibration_Model' */
  /* Update for DiscreteIntegrator: '<S139>/Discrete-Time Integrator' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S128>/Discrete-Time Integrator'
   */
  rtb_DiscreteTimeIntegrator_l_id = 0.002F * Plant_Y.Extended_States.prop_vel[3];

  /* End of Outputs for SubSystem: '<S126>/Vibration_Model' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE[3] += rtb_DiscreteTimeIntegrator_l_id;

  /* Switch: '<S137>/Switch' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S139>/Gain2'
   *  Gain: '<S139>/Gain4'
   *  Product: '<S139>/Divide'
   *  SignalConversion: '<S141>/ConcatBufferAtVector ConcatenateIn1'
   *  SignalConversion: '<S141>/ConcatBufferAtVector ConcatenateIn2'
   *  SignalConversion: '<S141>/ConcatBufferAtVector ConcatenateIn3'
   *  Sum: '<S137>/Sum'
   *  Sum: '<S139>/Sum'
   *  Sum: '<S139>/Sum of Elements'
   *  Sum: '<S139>/Sum of Elements1'
   */
  rtb_Multiply5_i[0] = (real32_T)(rtb_SumofElements / 4.0 * 0.5 +
    Plant_Y.Plant_States.rot_x_B);
  rtb_Multiply5_i[1] = (real32_T)(rtb_Product1 / 4.0 * 0.5 +
    Plant_Y.Plant_States.rot_y_B);
  rtb_Switch_idx_0 = (real32_T)((rtb_SumofElements + rtb_Product1) * 0.5 / 4.0 *
    0.5 + Plant_Y.Plant_States.rot_z_B);

  /* End of Outputs for SubSystem: '<S137>/Vibration_Model' */

  /* Sum: '<S145>/Sum' incorporates:
   *  Product: '<S145>/Product'
   */
  for (i = 0; i < 3; i++) {
    rtb_RandomSource[i] = (Plant_ConstB.Add_g[i + 3] * rtb_Multiply5_i[1] +
      Plant_ConstB.Add_g[i] * rtb_Multiply5_i[0]) + Plant_ConstB.Add_g[i + 6] *
      rtb_Switch_idx_0;
  }

  /* End of Sum: '<S145>/Sum' */

  /* DiscreteIntegrator: '<S144>/Discrete-Time Integrator5' */
  if (Plant_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[0] = rtb_RandomSource[0];
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[1] = rtb_RandomSource[1];
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[2] = rtb_RandomSource[2];
  }

  /* S-Function (sdsprandsrc2): '<S135>/Random Source' */
  RandSrc_GZ_R(rtb_MathFunction, &Plant_ConstP.pooled14, 1,
               Plant_ConstP.RandomSource_VarianceRTP_f, 3,
               Plant_DW.RandomSource_STATE_DWORK_k, 3, 1);

  /* S-Function (sdsprandsrc2): '<S146>/Random Source' */
  RandSrc_GZ_R(rtb_Sum_mo, &Plant_ConstP.pooled14, 1,
               Plant_ConstP.RandomSource_VarianceRTP_b, 3,
               Plant_DW.RandomSource_STATE_DWORK_h, 3, 1);

  /* Saturate: '<S138>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S144>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[0] > 34.9065857F) {
    rtb_Gain_d_tmp_5 = 34.9065857F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[0] < -34.9065857F) {
    rtb_Gain_d_tmp_5 = -34.9065857F;
  } else {
    rtb_Gain_d_tmp_5 = Plant_DW.DiscreteTimeIntegrator5_DSTATE[0];
  }

  /* Sum: '<S138>/Sum' */
  rtb_Add_la[0] = rtb_Gain_d_tmp_5 + rtb_Sum_mo[0];

  /* Saturate: '<S138>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S144>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[1] > 34.9065857F) {
    rtb_Gain_d_tmp_5 = 34.9065857F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[1] < -34.9065857F) {
    rtb_Gain_d_tmp_5 = -34.9065857F;
  } else {
    rtb_Gain_d_tmp_5 = Plant_DW.DiscreteTimeIntegrator5_DSTATE[1];
  }

  /* Sum: '<S138>/Sum' */
  rtb_Add_la[1] = rtb_Gain_d_tmp_5 + rtb_Sum_mo[1];

  /* Saturate: '<S138>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S144>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[2] > 34.9065857F) {
    rtb_Gain_d_tmp_5 = 34.9065857F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[2] < -34.9065857F) {
    rtb_Gain_d_tmp_5 = -34.9065857F;
  } else {
    rtb_Gain_d_tmp_5 = Plant_DW.DiscreteTimeIntegrator5_DSTATE[2];
  }

  /* Sum: '<S138>/Sum' */
  rtb_Add_la[2] = rtb_Gain_d_tmp_5 + rtb_Sum_mo[2];

  /* Outputs for Atomic SubSystem: '<S126>/Vibration_Model' */
  /* Math: '<S132>/u^2' incorporates:
   *  Product: '<S132>/Divide2'
   */
  rtb_Product1 = rtb_Add_idx_1 * rtb_Add_idx_1;

  /* Product: '<S128>/Product2' incorporates:
   *  DiscreteIntegrator: '<S128>/Discrete-Time Integrator'
   *  Trigonometry: '<S128>/Trigonometric Function2'
   */
  rtb_SumofElements = arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_p[0]) *
    rtb_Product1;

  /* Math: '<S132>/u^2' incorporates:
   *  DiscreteIntegrator: '<S128>/Discrete-Time Integrator'
   *  Product: '<S128>/Product1'
   *  Product: '<S132>/Divide2'
   *  Trigonometry: '<S128>/Trigonometric Function1'
   */
  rtb_Product1_idx_0 = arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_p[0]) *
    rtb_Product1;
  rtb_Product1 = rtb_Divide2_idx_0 * rtb_Divide2_idx_0;

  /* Product: '<S128>/Product2' incorporates:
   *  DiscreteIntegrator: '<S128>/Discrete-Time Integrator'
   *  Trigonometry: '<S128>/Trigonometric Function2'
   */
  rtb_Product2_g_idx_1 = arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_p[1])
    * rtb_Product1;

  /* Math: '<S132>/u^2' incorporates:
   *  DiscreteIntegrator: '<S128>/Discrete-Time Integrator'
   *  Product: '<S128>/Product1'
   *  Product: '<S132>/Divide2'
   *  Trigonometry: '<S128>/Trigonometric Function1'
   */
  rtb_Product1_idx_1 = arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_p[1]) *
    rtb_Product1;
  rtb_Product1 = rtb_Divide2_idx_1 * rtb_Divide2_idx_1;

  /* Sum: '<S128>/Sum of Elements' incorporates:
   *  DiscreteIntegrator: '<S128>/Discrete-Time Integrator'
   *  Product: '<S128>/Product2'
   *  Trigonometry: '<S128>/Trigonometric Function2'
   */
  rtb_SumofElements = ((rtb_SumofElements + rtb_Product2_g_idx_1) + arm_sin_f32
                       (Plant_DW.DiscreteTimeIntegrator_DSTATE_p[2]) *
                       rtb_Product1) + arm_sin_f32
    (Plant_DW.DiscreteTimeIntegrator_DSTATE_p[3]) * rtb_SumofElements1;

  /* SignalConversion: '<S128>/ConcatBufferAtVector ConcatenateIn1' incorporates:
   *  Sum: '<S128>/Sum of Elements'
   */
  rtb_DataTypeConversion[0] = rtb_SumofElements;

  /* Sum: '<S128>/Sum of Elements1' incorporates:
   *  DiscreteIntegrator: '<S128>/Discrete-Time Integrator'
   *  Product: '<S128>/Product1'
   *  Trigonometry: '<S128>/Trigonometric Function1'
   */
  rtb_Product1 = ((rtb_Product1_idx_0 + rtb_Product1_idx_1) + arm_cos_f32
                  (Plant_DW.DiscreteTimeIntegrator_DSTATE_p[2]) * rtb_Product1)
    + arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_p[3]) *
    rtb_SumofElements1;

  /* SignalConversion: '<S128>/ConcatBufferAtVector ConcatenateIn2' incorporates:
   *  Sum: '<S128>/Sum of Elements1'
   */
  rtb_DataTypeConversion[1] = rtb_Product1;

  /* Gain: '<S128>/Gain2' incorporates:
   *  Sum: '<S128>/Sum'
   *  Sum: '<S128>/Sum of Elements'
   *  Sum: '<S128>/Sum of Elements1'
   */
  rtb_DataTypeConversion[2] = (rtb_SumofElements + rtb_Product1) * 0.5;

  /* Update for DiscreteIntegrator: '<S128>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_p[0] += rtb_DiscreteTimeIntegrator_l__2;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_p[1] += rtb_DiscreteTimeIntegrator_l__1;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_p[2] += rtb_DiscreteTimeIntegrator_l__0;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_p[3] += rtb_DiscreteTimeIntegrator_l_id;

  /* End of Outputs for SubSystem: '<S126>/Vibration_Model' */

  /* Switch: '<S126>/Switch' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S128>/Gain4'
   *  Product: '<S128>/Divide'
   *  Product: '<S130>/Product1'
   *  SignalConversion: '<S130>/ConcatBufferAtVector Concatenate1In1'
   *  SignalConversion: '<S130>/ConcatBufferAtVector Concatenate1In2'
   *  SignalConversion: '<S130>/ConcatBufferAtVector Concatenate1In3'
   *  Sum: '<S126>/Sum'
   *  Sum: '<S130>/Sum'
   */
  for (i = 0; i < 3; i++) {
    /* Outputs for Atomic SubSystem: '<S126>/Vibration_Model' */
    rtb_Sum_mo[i] = (real32_T)(((Plant_Y.Extended_States.M_BO[i + 3] *
      Plant_Y.Plant_States.acc_y_O + Plant_Y.Extended_States.M_BO[i] *
      Plant_Y.Plant_States.acc_x_O) + Plant_Y.Extended_States.M_BO[i + 6] *
      (Plant_Y.Plant_States.acc_z_O - 9.80665F)) + rtb_DataTypeConversion[i] /
      4.0 * Plant_ConstP.Gain4_Gain[i]);

    /* End of Outputs for SubSystem: '<S126>/Vibration_Model' */
  }

  /* End of Switch: '<S126>/Switch' */

  /* Sum: '<S134>/Sum' incorporates:
   *  Product: '<S134>/Product'
   */
  for (i = 0; i < 3; i++) {
    rtb_Multiply2_p[i] = (Plant_ConstB.Add_m[i + 3] * rtb_Sum_mo[1] +
                          Plant_ConstB.Add_m[i] * rtb_Sum_mo[0]) +
      Plant_ConstB.Add_m[i + 6] * rtb_Sum_mo[2];
  }

  /* End of Sum: '<S134>/Sum' */

  /* DiscreteIntegrator: '<S133>/Discrete-Time Integrator5' */
  if (Plant_DW.DiscreteTimeIntegrator5_IC_LO_j != 0) {
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[0] = rtb_Multiply2_p[0];
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[1] = rtb_Multiply2_p[1];
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[2] = rtb_Multiply2_p[2];
  }

  /* Outport: '<Root>/IMU' incorporates:
   *  BusAssignment: '<S123>/Bus Assignment'
   *  Memory: '<S97>/Memory1'
   */
  Plant_Y.IMU.timestamp = Plant_DW.Memory1_PreviousInput;
  Plant_Y.IMU.gyr_x = rtb_Add_la[0];
  Plant_Y.IMU.gyr_y = rtb_Add_la[1];
  Plant_Y.IMU.gyr_z = rtb_Add_la[2];

  /* Update for DiscreteIntegrator: '<S144>/Discrete-Time Integrator5' */
  Plant_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;

  /* Update for DiscreteIntegrator: '<S133>/Discrete-Time Integrator5' */
  Plant_DW.DiscreteTimeIntegrator5_IC_LO_j = 0U;

  /* End of Outputs for SubSystem: '<S6>/Sensor_IMU' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_MAG' */
  /* Gain: '<S152>/rad_to_index' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S152>/TmpSignal ConversionAtrad_to_indexInport1'
   */
  rtb_SumofElements = fmod(floor(5.7295779513082321 * Plant_Y.Plant_States.lat),
    4.294967296E+9);

  /* Sum: '<S152>/Add' incorporates:
   *  Gain: '<S152>/rad_to_index'
   */
  i = (rtb_SumofElements < 0.0 ? -(int32_T)(uint32_T)-rtb_SumofElements :
       (int32_T)(uint32_T)rtb_SumofElements) + 8;

  /* Saturate: '<S152>/Saturation1' */
  if (i > 16) {
    i = 16;
  } else {
    if (i < 0) {
      i = 0;
    }
  }

  /* Gain: '<S152>/rad_to_index' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S152>/TmpSignal ConversionAtrad_to_indexInport1'
   */
  rtb_SumofElements = fmod(floor(5.7295779513082321 * Plant_Y.Plant_States.lon),
    4.294967296E+9);

  /* Sum: '<S152>/Add' incorporates:
   *  Gain: '<S152>/rad_to_index'
   */
  rtb_Saturation1_idx_1 = (rtb_SumofElements < 0.0 ? -(int32_T)(uint32_T)
    -rtb_SumofElements : (int32_T)(uint32_T)rtb_SumofElements) + 18;

  /* Saturate: '<S152>/Saturation1' */
  if (rtb_Saturation1_idx_1 > 36) {
    rtb_Saturation1_idx_1 = 36;
  } else {
    if (rtb_Saturation1_idx_1 < 0) {
      rtb_Saturation1_idx_1 = 0;
    }
  }

  /* LookupNDDirect: '<S152>/Declination_Lookup_Table' incorporates:
   *  LookupNDDirect: '<S152>/Inclination_Lookup_Table'
   *  LookupNDDirect: '<S152>/Magnitude_Lookup_Table'
   *
   * About '<S152>/Declination_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   *
   * About '<S152>/Inclination_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   *
   * About '<S152>/Magnitude_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  i += rtb_Saturation1_idx_1 * 17;

  /* Gain: '<S153>/Gain1' incorporates:
   *  LookupNDDirect: '<S152>/Declination_Lookup_Table'
   *
   * About '<S152>/Declination_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  rtb_Divide_f_idx_2 = Plant_ConstP.Declination_Lookup_Table_table[i] *
    0.0174532924F;

  /* Trigonometry: '<S155>/Trigonometric Function1' incorporates:
   *  Trigonometry: '<S155>/Trigonometric Function3'
   */
  rtb_Multiply4_i_idx_0 = arm_cos_f32(rtb_Divide_f_idx_2);
  rtb_VectorConcatenate_f[0] = rtb_Multiply4_i_idx_0;

  /* Trigonometry: '<S155>/Trigonometric Function' incorporates:
   *  Trigonometry: '<S155>/Trigonometric Function2'
   */
  rtb_Multiply4_i_idx_1 = arm_sin_f32(rtb_Divide_f_idx_2);
  rtb_VectorConcatenate_f[1] = rtb_Multiply4_i_idx_1;

  /* SignalConversion: '<S155>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S155>/Constant3'
   */
  rtb_VectorConcatenate_f[2] = 0.0F;

  /* Gain: '<S155>/Gain' */
  rtb_VectorConcatenate_f[3] = -rtb_Multiply4_i_idx_1;

  /* Trigonometry: '<S155>/Trigonometric Function3' */
  rtb_VectorConcatenate_f[4] = rtb_Multiply4_i_idx_0;

  /* SignalConversion: '<S155>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S155>/Constant4'
   */
  rtb_VectorConcatenate_f[5] = 0.0F;

  /* Gain: '<S153>/Gain' incorporates:
   *  LookupNDDirect: '<S152>/Inclination_Lookup_Table'
   *
   * About '<S152>/Inclination_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  rtb_Divide_f_idx_2 = Plant_ConstP.Inclination_Lookup_Table_table[i] *
    -0.0174532924F;

  /* Trigonometry: '<S154>/Trigonometric Function3' incorporates:
   *  Trigonometry: '<S154>/Trigonometric Function1'
   */
  rtb_DiscreteTimeIntegrator_l_id = arm_cos_f32(rtb_Divide_f_idx_2);
  rtb_VectorConcatenate_k[0] = rtb_DiscreteTimeIntegrator_l_id;

  /* SignalConversion: '<S154>/ConcatBufferAtVector Concatenate2In2' incorporates:
   *  Constant: '<S154>/Constant4'
   */
  rtb_VectorConcatenate_k[1] = 0.0F;

  /* Trigonometry: '<S154>/Trigonometric Function2' incorporates:
   *  Trigonometry: '<S154>/Trigonometric Function'
   */
  rtb_Divide_f_idx_1 = arm_sin_f32(rtb_Divide_f_idx_2);

  /* Gain: '<S154>/Gain' incorporates:
   *  Trigonometry: '<S154>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_k[2] = -rtb_Divide_f_idx_1;

  /* End of Outputs for SubSystem: '<S6>/Sensor_MAG' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_IMU' */
  /* Saturate: '<S127>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S133>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[0] > 78.4532F) {
    rtb_DiscreteTimeIntegrator_l__2 = 78.4532F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[0] < -78.4532F) {
    rtb_DiscreteTimeIntegrator_l__2 = -78.4532F;
  } else {
    rtb_DiscreteTimeIntegrator_l__2 = Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[0];
  }

  /* Update for DiscreteIntegrator: '<S144>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S144>/Gain'
   *  Sum: '<S144>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTATE[0] += (rtb_RandomSource[0] -
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 314.159271F * 0.002F;

  /* Update for DiscreteIntegrator: '<S133>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S133>/Gain'
   *  Sum: '<S133>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[0] += (rtb_Multiply2_p[0] -
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[0]) * 314.159271F * 0.002F;

  /* End of Outputs for SubSystem: '<S6>/Sensor_IMU' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_MAG' */
  /* SignalConversion: '<S155>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_f[6] = Plant_ConstB.VectorConcatenate3[0];

  /* SignalConversion: '<S154>/ConcatBufferAtVector ConcatenateIn2' */
  rtb_VectorConcatenate_k[3] = Plant_ConstB.VectorConcatenate3_a[0];

  /* End of Outputs for SubSystem: '<S6>/Sensor_MAG' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_IMU' */
  /* Saturate: '<S127>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S133>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[1] > 78.4532F) {
    rtb_DiscreteTimeIntegrator_l__1 = 78.4532F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[1] < -78.4532F) {
    rtb_DiscreteTimeIntegrator_l__1 = -78.4532F;
  } else {
    rtb_DiscreteTimeIntegrator_l__1 = Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[1];
  }

  /* Update for DiscreteIntegrator: '<S144>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S144>/Gain'
   *  Sum: '<S144>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTATE[1] += (rtb_RandomSource[1] -
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 314.159271F * 0.002F;

  /* Update for DiscreteIntegrator: '<S133>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S133>/Gain'
   *  Sum: '<S133>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[1] += (rtb_Multiply2_p[1] -
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[1]) * 314.159271F * 0.002F;

  /* End of Outputs for SubSystem: '<S6>/Sensor_IMU' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_MAG' */
  /* SignalConversion: '<S155>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_f[7] = Plant_ConstB.VectorConcatenate3[1];

  /* SignalConversion: '<S154>/ConcatBufferAtVector ConcatenateIn2' */
  rtb_VectorConcatenate_k[4] = Plant_ConstB.VectorConcatenate3_a[1];

  /* End of Outputs for SubSystem: '<S6>/Sensor_MAG' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_IMU' */
  /* Saturate: '<S127>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S133>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[2] > 78.4532F) {
    rtb_DiscreteTimeIntegrator_l__0 = 78.4532F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[2] < -78.4532F) {
    rtb_DiscreteTimeIntegrator_l__0 = -78.4532F;
  } else {
    rtb_DiscreteTimeIntegrator_l__0 = Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[2];
  }

  /* Update for DiscreteIntegrator: '<S144>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S144>/Gain'
   *  Sum: '<S144>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTATE[2] += (rtb_RandomSource[2] -
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 314.159271F * 0.002F;

  /* Update for DiscreteIntegrator: '<S133>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S133>/Gain'
   *  Sum: '<S133>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[2] += (rtb_Multiply2_p[2] -
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[2]) * 314.159271F * 0.002F;

  /* End of Outputs for SubSystem: '<S6>/Sensor_IMU' */

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_MAG' */
  /* SignalConversion: '<S155>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_f[8] = Plant_ConstB.VectorConcatenate3[2];

  /* SignalConversion: '<S154>/ConcatBufferAtVector ConcatenateIn2' */
  rtb_VectorConcatenate_k[5] = Plant_ConstB.VectorConcatenate3_a[2];

  /* Trigonometry: '<S154>/Trigonometric Function' */
  rtb_VectorConcatenate_k[6] = rtb_Divide_f_idx_1;

  /* SignalConversion: '<S154>/ConcatBufferAtVector Concatenate1In2' incorporates:
   *  Constant: '<S154>/Constant3'
   */
  rtb_VectorConcatenate_k[7] = 0.0F;

  /* Trigonometry: '<S154>/Trigonometric Function1' */
  rtb_VectorConcatenate_k[8] = rtb_DiscreteTimeIntegrator_l_id;

  /* Gain: '<S153>/toGauss' incorporates:
   *  LookupNDDirect: '<S152>/Magnitude_Lookup_Table'
   *
   * About '<S152>/Magnitude_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  rtb_DiscreteTimeIntegrator_l_id = Plant_ConstP.Magnitude_Lookup_Table_table[i]
    * 0.01F;

  /* Product: '<S153>/Multiply1' incorporates:
   *  Product: '<S153>/Multiply'
   */
  for (i = 0; i < 3; i++) {
    rtb_Sum_hq[i] = rtb_VectorConcatenate_k[i] * rtb_DiscreteTimeIntegrator_l_id;
  }

  /* End of Product: '<S153>/Multiply1' */

  /* Product: '<S153>/Multiply2' */
  for (i = 0; i < 3; i++) {
    rtb_Add_la[i] = rtb_VectorConcatenate_f[i + 6] * rtb_Sum_hq[2] +
      (rtb_VectorConcatenate_f[i + 3] * rtb_Sum_hq[1] +
       rtb_VectorConcatenate_f[i] * rtb_Sum_hq[0]);
  }

  /* End of Product: '<S153>/Multiply2' */

  /* Product: '<S150>/Product' incorporates:
   *  Delay: '<Root>/Delay'
   */
  for (i = 0; i < 3; i++) {
    rtb_Multiply5_i[i] = Plant_Y.Extended_States.M_BO[i + 6] * rtb_Add_la[2] +
      (Plant_Y.Extended_States.M_BO[i + 3] * rtb_Add_la[1] +
       Plant_Y.Extended_States.M_BO[i] * rtb_Add_la[0]);
  }

  /* End of Product: '<S150>/Product' */
  for (i = 0; i < 3; i++) {
    /* Sum: '<S156>/Sum' incorporates:
     *  Product: '<S156>/Product'
     */
    rtb_Gain_d_tmp_5 = (Plant_ConstB.Add[i + 3] * rtb_Multiply5_i[1] +
                        Plant_ConstB.Add[i] * rtb_Multiply5_i[0]) +
      Plant_ConstB.Add[i + 6] * rtb_Multiply5_i[2];

    /* Saturate: '<S151>/Saturation' incorporates:
     *  Sum: '<S156>/Sum'
     */
    if (rtb_Gain_d_tmp_5 > 4.0F) {
      rtb_Add_la[i] = 4.0F;
    } else if (rtb_Gain_d_tmp_5 < -4.0F) {
      rtb_Add_la[i] = -4.0F;
    } else {
      rtb_Add_la[i] = rtb_Gain_d_tmp_5;
    }

    /* End of Saturate: '<S151>/Saturation' */
  }

  /* S-Function (sdsprandsrc2): '<S157>/Random Source' */
  RandSrc_GZ_R(rtb_Multiply5_i, &Plant_ConstP.pooled14, 1,
               Plant_ConstP.RandomSource_VarianceRTP_a, 3,
               Plant_DW.RandomSource_STATE_DWORK, 3, 1);

  /* Sum: '<S151>/Add' */
  rtb_Add_la[0] += rtb_Multiply5_i[0];
  rtb_Add_la[1] += rtb_Multiply5_i[1];

  /* BusAssignment: '<S147>/Bus Assignment' incorporates:
   *  Memory: '<S97>/Memory1'
   *  Sum: '<S151>/Add'
   */
  rtb_BusAssignment_o.timestamp = Plant_DW.Memory1_PreviousInput;
  rtb_BusAssignment_o.mag_x = rtb_Add_la[0];
  rtb_BusAssignment_o.mag_y = rtb_Add_la[1];
  rtb_BusAssignment_o.mag_z = rtb_Add_la[2] + rtb_Multiply5_i[2];

  /* RateTransition: '<S147>/Rate Transition' */
  if (Plant_M->Timing.TaskCounters.TID[1] == 0) {
    Plant_B.RateTransition_b = rtb_BusAssignment_o;
  }

  /* End of RateTransition: '<S147>/Rate Transition' */
  /* End of Outputs for SubSystem: '<S6>/Sensor_MAG' */

  /* Update for Memory: '<S97>/Memory1' incorporates:
   *  Constant: '<S97>/dt'
   *  Sum: '<S97>/Sum'
   */
  Plant_DW.Memory1_PreviousInput += PLANT_EXPORT.period;

  /* Outputs for Atomic SubSystem: '<S6>/Sensor_IMU' */
  /* Outport: '<Root>/IMU' incorporates:
   *  Sum: '<S127>/Sum'
   */
  Plant_Y.IMU.acc_x = rtb_DiscreteTimeIntegrator_l__2 + rtb_MathFunction[0];
  Plant_Y.IMU.acc_y = rtb_DiscreteTimeIntegrator_l__1 + rtb_MathFunction[1];
  Plant_Y.IMU.acc_z = rtb_DiscreteTimeIntegrator_l__0 + rtb_MathFunction[2];

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
    /* InitializeConditions for DiscreteIntegrator: '<S71>/Discrete-Time Integrator' */
    Plant_DW.DiscreteTimeIntegrator_IC_LOADI = 1U;
    Plant_DW.DiscreteTimeIntegrator_PrevRese = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S65>/Discrete-Time Integrator' */
    Plant_DW.DiscreteTimeIntegrator_PrevRe_d = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S66>/Discrete-Time Integrator' */
    Plant_DW.DiscreteTimeIntegrator_PrevRe_k = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S66>/Discrete-Time Integrator1' */
    Plant_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
    Plant_DW.DiscreteTimeIntegrator1_PrevRes = 0;

    /* End of SystemInitialize for SubSystem: '<Root>/Kinematic_Equation' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Bus_Constructor' */
    /* InitializeConditions for Delay: '<S23>/Delay1' */
    Plant_DW.icLoad = 1U;

    /* End of SystemInitialize for SubSystem: '<Root>/Bus_Constructor' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Sensor_Model' */
    /* SystemInitialize for Atomic SubSystem: '<S6>/Sensor_Barometer' */
    /* InitializeConditions for S-Function (sdsprandsrc2): '<S108>/Random Source' */
    RandomSource_SEED_DWORK_k = 91337U;
    RandSrcInitState_GZ(&RandomSource_SEED_DWORK_k,
                        Plant_DW.RandomSource_STATE_DWORK_b, 1);

    /* End of SystemInitialize for SubSystem: '<S6>/Sensor_Barometer' */

    /* SystemInitialize for Atomic SubSystem: '<S6>/Sensor_GPS' */
    /* InitializeConditions for S-Function (sdsprandsrc2): '<S117>/Random Source' */
    RandSrcCreateSeeds_32(63235U, Plant_DW.RandomSource_SEED_DWORK_m, 3);
    RandSrcInitState_GZ(Plant_DW.RandomSource_SEED_DWORK_m,
                        Plant_DW.RandomSource_STATE_DWORK_l, 3);

    /* InitializeConditions for DiscreteFir: '<S119>/Discrete FIR Filter' */
    Plant_DW.DiscreteFIRFilter_states[0] = 0.0;
    Plant_DW.DiscreteFIRFilter_states[1] = 0.0;
    Plant_DW.DiscreteFIRFilter_states[2] = 0.0;

    /* InitializeConditions for S-Function (sdsprandsrc2): '<S117>/Random Source1' */
    RandSrcCreateSeeds_32(9754U, Plant_DW.RandomSource1_SEED_DWORK, 3);
    RandSrcInitState_GZ(Plant_DW.RandomSource1_SEED_DWORK,
                        Plant_DW.RandomSource1_STATE_DWORK, 3);

    /* InitializeConditions for DiscreteFir: '<S120>/Discrete FIR Filter' */
    Plant_DW.DiscreteFIRFilter_states_f[0] = 0.0F;
    Plant_DW.DiscreteFIRFilter_states_f[1] = 0.0F;
    Plant_DW.DiscreteFIRFilter_states_f[2] = 0.0F;

    /* End of SystemInitialize for SubSystem: '<S6>/Sensor_GPS' */

    /* SystemInitialize for Atomic SubSystem: '<S6>/Sensor_IMU' */
    /* InitializeConditions for DiscreteIntegrator: '<S144>/Discrete-Time Integrator5' */
    Plant_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

    /* InitializeConditions for S-Function (sdsprandsrc2): '<S135>/Random Source' */
    RandSrcCreateSeeds_32(90579U, Plant_DW.RandomSource_SEED_DWORK_f, 3);
    RandSrcInitState_GZ(Plant_DW.RandomSource_SEED_DWORK_f,
                        Plant_DW.RandomSource_STATE_DWORK_k, 3);

    /* InitializeConditions for S-Function (sdsprandsrc2): '<S146>/Random Source' */
    RandSrcCreateSeeds_32(81472U, Plant_DW.RandomSource_SEED_DWORK_n, 3);
    RandSrcInitState_GZ(Plant_DW.RandomSource_SEED_DWORK_n,
                        Plant_DW.RandomSource_STATE_DWORK_h, 3);

    /* InitializeConditions for DiscreteIntegrator: '<S133>/Discrete-Time Integrator5' */
    Plant_DW.DiscreteTimeIntegrator5_IC_LO_j = 1U;

    /* End of SystemInitialize for SubSystem: '<S6>/Sensor_IMU' */

    /* SystemInitialize for Atomic SubSystem: '<S6>/Sensor_MAG' */
    /* InitializeConditions for S-Function (sdsprandsrc2): '<S157>/Random Source' */
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
