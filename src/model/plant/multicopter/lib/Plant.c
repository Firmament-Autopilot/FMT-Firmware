/*
 * File: Plant.c
 *
 * Code generated for Simulink model 'Plant'.
 *
 * Model version                  : 1.757
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Mar 22 16:06:12 2022
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
  /* M_OB */
} ;                                    /* Extended_States_Bus ground */

/* Exported block parameters */
struct_zjTVXoT1Wcig2PfNqPD1gB PLANT_EXPORT = {
  2U,

  { 77, 117, 108, 116, 105, 99, 111, 112, 116, 101, 114, 32, 118, 48, 46, 50, 46,
    49, 0 }
} ;                                    /* Variable: PLANT_EXPORT
                                        * Referenced by:
                                        *   '<S19>/dt'
                                        *   '<S65>/dt'
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

  /* S-Function (sdsprandsrc2): '<S76>/Random Source' */
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

  /* End of S-Function (sdsprandsrc2): '<S76>/Random Source' */
}

void RandSrcInitState_GZ(const uint32_T seed[], uint32_T state[], int32_T nChans)
{
  int32_T i;
  int32_T tmp;

  /* InitializeConditions for S-Function (sdsprandsrc2): '<S76>/Random Source' */
  /* RandSrcInitState_GZ */
  for (i = 0; i < nChans; i++) {
    tmp = i << 1;
    state[tmp] = 362436069U;
    state[tmp + 1] = seed[i] == 0U ? 521288629U : seed[i];
  }

  /* End of InitializeConditions for S-Function (sdsprandsrc2): '<S76>/Random Source' */
}

void RandSrcInitState_U_32(const uint32_T seed[], real32_T state[], int32_T
  nChans)
{
  int32_T i;
  uint32_T j;
  int32_T k;
  int32_T n;
  real32_T d;

  /* InitializeConditions for S-Function (sdsprandsrc2): '<S85>/Random Source' */
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

  /* End of InitializeConditions for S-Function (sdsprandsrc2): '<S85>/Random Source' */
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

  /* InitializeConditions for S-Function (sdsprandsrc2): '<S85>/Random Source' */
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

  /* End of InitializeConditions for S-Function (sdsprandsrc2): '<S85>/Random Source' */
}

void RandSrcCreateSeeds_32(uint32_T initSeed, uint32_T seedArray[], int32_T
  numSeeds)
{
  real32_T state[35];
  real32_T tmp;
  real32_T min;
  real32_T max;
  int32_T i;

  /* InitializeConditions for S-Function (sdsprandsrc2): '<S85>/Random Source' */
  /* RandSrcCreateSeeds_32 */
  min = 0.0F;
  max = 1.0F;
  RandSrcInitState_U_32(&initSeed, state, 1);
  for (i = 0; i < numSeeds; i++) {
    RandSrc_U_R(&tmp, &min, 1, &max, 1, state, 1, 1);
    seedArray[i] = (uint32_T)(tmp * 2.14748365E+9F);
  }

  /* End of InitializeConditions for S-Function (sdsprandsrc2): '<S85>/Random Source' */
}

/* Model step function */
void Plant_step(void)
{
  real32_T rtb_Sum_hq[3];
  real32_T rtb_Gain_h;
  real32_T rtb_Sum_b[3];
  real32_T rtb_Add_la[3];
  real32_T rtb_VectorConcatenate1_d[3];
  real32_T rtb_VectorConcatenate_f[9];
  boolean_T rtb_Compare;
  real32_T rtb_MatrixConcatenate4[16];
  real32_T rtb_Add_e;
  real32_T rtb_Sum_d[3];
  real32_T rtb_MatrixConcatenate1[9];
  real32_T rtb_Sum_c0;
  real32_T rtb_Sum_i;
  real_T rtb_SumofElements;
  real_T rtb_SumofElements1;
  real_T rtb_Divide2[3];
  Barometer_Bus rtb_BusAssignment_i;
  GPS_uBlox_Bus rtb_BusAssignment_dk;
  real32_T rtb_VectorConcatenate_k[9];
  MAG_Bus rtb_BusAssignment_o;
  real32_T rtb_Switch1;
  real32_T rtb_RandomSource[3];
  real32_T rtb_Add_lr[3];
  real32_T rtb_Add1_c[3];
  real32_T rtb_RandomSource1[3];
  real32_T rtb_RandomSource_f[3];
  int32_T i;
  real32_T tmp[3];
  real32_T rtb_VectorConcatenate_l[3];
  real32_T rtb_MatrixConcatenate4_0[4];
  real32_T rtb_Divide_g;
  real_T rtb_Product1;
  real_T rtb_Product1_idx_1;
  real_T rtb_Product1_idx_0;
  real_T rtb_Product2_g_idx_1;
  real_T rtb_Product1_tmp_idx_2;
  real_T Sum2_idx_2;
  real_T Sum2_idx_0;
  real32_T rtb_Saturation1_idx_3;
  real32_T rtb_Saturation1_idx_2;
  real32_T rtb_Saturation1_idx_1;
  real32_T rtb_Saturation1_idx_0;
  real32_T rtb_vel_O_mPs_idx_2;
  real32_T rtb_vel_O_mPs_idx_1;
  real32_T rtb_vel_O_mPs_idx_0;
  real32_T rtb_Divide_f_idx_2;
  real32_T rtb_Divide_f_idx_1;
  real32_T rtb_Divide_f_idx_0;
  real32_T rtb_omega_B_radPs_idx_2;
  real32_T rtb_omega_B_radPs_idx_1;
  real32_T Rotor_Delay_tmp_idx_2;
  real32_T Rotor_Delay_tmp_idx_1;
  real32_T Rotor_Delay_tmp_idx_0;
  int32_T rtb_Saturation1_o_idx_1;
  uint16_T tmp_0;
  real32_T rtb_TrigonometricFunction1_idx_;
  real32_T rtb_Divide_n_idx_0;
  real32_T rtb_TrigonometricFunction1_id_0;
  real32_T rtb_Divide_n_idx_1;
  real32_T rtb_TrigonometricFunction1_id_1;
  real32_T rtb_Divide_n_idx_2;
  real32_T rtb_TrigonometricFunction1_id_2;
  real32_T rtb_Divide_f_idx_3;
  real32_T rtb_Add_e_tmp;
  real32_T rtb_Add_e_tmp_0;

  /* Delay: '<Root>/Delay' */
  for (i = 0; i < 9; i++) {
    rtb_VectorConcatenate_k[i] = Plant_Y.Extended_States.M_BO[i];
  }

  /* Outputs for Atomic SubSystem: '<Root>/Actuators' */
  /* Saturate: '<S8>/Saturation' incorporates:
   *  Inport: '<Root>/Control_Out'
   */
  if (Plant_U.Control_Out.actuator_cmd[0] > 2000) {
    tmp_0 = 2000U;
  } else if (Plant_U.Control_Out.actuator_cmd[0] < 1000) {
    tmp_0 = 1000U;
  } else {
    tmp_0 = Plant_U.Control_Out.actuator_cmd[0];
  }

  /* Gain: '<S8>/Gain' incorporates:
   *  Sum: '<S8>/Subtract'
   */
  rtb_Divide_g = ((real32_T)tmp_0 - 1000.0F) * 0.000999987125F;

  /* RelationalOperator: '<S12>/Compare' incorporates:
   *  Constant: '<S12>/Constant'
   */
  rtb_Compare = (rtb_Divide_g > 0.1F);

  /* Sum: '<S11>/Add' incorporates:
   *  Constant: '<S11>/Constant1'
   *  Gain: '<S11>/Gain1'
   */
  rtb_Divide_g = 718.078F * rtb_Divide_g + 88.448F;

  /* DiscreteFilter: '<S8>/Rotor_Delay' incorporates:
   *  Product: '<S11>/Multiply'
   */
  rtb_Divide_g = (rtb_Compare ? rtb_Divide_g : 0.0F) - 0.02F *
    Plant_DW.Rotor_Delay_states[0];

  /* Math: '<S13>/Square' incorporates:
   *  DiscreteFilter: '<S8>/Rotor_Delay'
   *  Math: '<S15>/Square'
   */
  rtb_Saturation1_idx_3 = rtb_Divide_g * rtb_Divide_g;

  /* Product: '<S13>/Multiply' incorporates:
   *  Constant: '<S13>/cT'
   */
  rtb_Divide_f_idx_0 = (real32_T)(rtb_Saturation1_idx_3 * 1.239E-5);

  /* Saturate: '<S11>/Saturation1' */
  rtb_Saturation1_idx_0 = rtb_Saturation1_idx_3;

  /* DiscreteFilter: '<S8>/Rotor_Delay' */
  Rotor_Delay_tmp_idx_0 = rtb_Divide_g;

  /* Saturate: '<S8>/Saturation' incorporates:
   *  Inport: '<Root>/Control_Out'
   */
  if (Plant_U.Control_Out.actuator_cmd[1] > 2000) {
    tmp_0 = 2000U;
  } else if (Plant_U.Control_Out.actuator_cmd[1] < 1000) {
    tmp_0 = 1000U;
  } else {
    tmp_0 = Plant_U.Control_Out.actuator_cmd[1];
  }

  /* Gain: '<S8>/Gain' incorporates:
   *  Sum: '<S8>/Subtract'
   */
  rtb_Divide_g = ((real32_T)tmp_0 - 1000.0F) * 0.000999987125F;

  /* RelationalOperator: '<S12>/Compare' incorporates:
   *  Constant: '<S12>/Constant'
   */
  rtb_Compare = (rtb_Divide_g > 0.1F);

  /* Sum: '<S11>/Add' incorporates:
   *  Constant: '<S11>/Constant1'
   *  Gain: '<S11>/Gain1'
   */
  rtb_Divide_g = 718.078F * rtb_Divide_g + 88.448F;

  /* DiscreteFilter: '<S8>/Rotor_Delay' incorporates:
   *  Product: '<S11>/Multiply'
   */
  rtb_Divide_g = (rtb_Compare ? rtb_Divide_g : 0.0F) - 0.02F *
    Plant_DW.Rotor_Delay_states[1];

  /* Math: '<S13>/Square' incorporates:
   *  DiscreteFilter: '<S8>/Rotor_Delay'
   *  Math: '<S15>/Square'
   */
  rtb_Saturation1_idx_3 = rtb_Divide_g * rtb_Divide_g;

  /* Product: '<S13>/Multiply' incorporates:
   *  Constant: '<S13>/cT'
   */
  rtb_Divide_f_idx_1 = (real32_T)(rtb_Saturation1_idx_3 * 1.239E-5);

  /* Saturate: '<S11>/Saturation1' */
  rtb_Saturation1_idx_1 = rtb_Saturation1_idx_3;

  /* DiscreteFilter: '<S8>/Rotor_Delay' */
  Rotor_Delay_tmp_idx_1 = rtb_Divide_g;

  /* Saturate: '<S8>/Saturation' incorporates:
   *  Inport: '<Root>/Control_Out'
   */
  if (Plant_U.Control_Out.actuator_cmd[2] > 2000) {
    tmp_0 = 2000U;
  } else if (Plant_U.Control_Out.actuator_cmd[2] < 1000) {
    tmp_0 = 1000U;
  } else {
    tmp_0 = Plant_U.Control_Out.actuator_cmd[2];
  }

  /* Gain: '<S8>/Gain' incorporates:
   *  Sum: '<S8>/Subtract'
   */
  rtb_Divide_g = ((real32_T)tmp_0 - 1000.0F) * 0.000999987125F;

  /* RelationalOperator: '<S12>/Compare' incorporates:
   *  Constant: '<S12>/Constant'
   */
  rtb_Compare = (rtb_Divide_g > 0.1F);

  /* Sum: '<S11>/Add' incorporates:
   *  Constant: '<S11>/Constant1'
   *  Gain: '<S11>/Gain1'
   */
  rtb_Divide_g = 718.078F * rtb_Divide_g + 88.448F;

  /* DiscreteFilter: '<S8>/Rotor_Delay' incorporates:
   *  Product: '<S11>/Multiply'
   */
  rtb_Divide_g = (rtb_Compare ? rtb_Divide_g : 0.0F) - 0.02F *
    Plant_DW.Rotor_Delay_states[2];

  /* Math: '<S13>/Square' incorporates:
   *  DiscreteFilter: '<S8>/Rotor_Delay'
   *  Math: '<S15>/Square'
   */
  rtb_Saturation1_idx_3 = rtb_Divide_g * rtb_Divide_g;

  /* Product: '<S13>/Multiply' incorporates:
   *  Constant: '<S13>/cT'
   */
  rtb_Divide_f_idx_2 = (real32_T)(rtb_Saturation1_idx_3 * 1.239E-5);

  /* Saturate: '<S11>/Saturation1' */
  rtb_Saturation1_idx_2 = rtb_Saturation1_idx_3;

  /* DiscreteFilter: '<S8>/Rotor_Delay' */
  Rotor_Delay_tmp_idx_2 = rtb_Divide_g;

  /* Saturate: '<S8>/Saturation' incorporates:
   *  Inport: '<Root>/Control_Out'
   */
  if (Plant_U.Control_Out.actuator_cmd[3] > 2000) {
    tmp_0 = 2000U;
  } else if (Plant_U.Control_Out.actuator_cmd[3] < 1000) {
    tmp_0 = 1000U;
  } else {
    tmp_0 = Plant_U.Control_Out.actuator_cmd[3];
  }

  /* Gain: '<S8>/Gain' incorporates:
   *  Sum: '<S8>/Subtract'
   */
  rtb_Divide_g = ((real32_T)tmp_0 - 1000.0F) * 0.000999987125F;

  /* RelationalOperator: '<S12>/Compare' incorporates:
   *  Constant: '<S12>/Constant'
   */
  rtb_Compare = (rtb_Divide_g > 0.1F);

  /* Sum: '<S11>/Add' incorporates:
   *  Constant: '<S11>/Constant1'
   *  Gain: '<S11>/Gain1'
   */
  rtb_Divide_g = 718.078F * rtb_Divide_g + 88.448F;

  /* DiscreteFilter: '<S8>/Rotor_Delay' incorporates:
   *  Product: '<S11>/Multiply'
   */
  rtb_Divide_g = (rtb_Compare ? rtb_Divide_g : 0.0F) - 0.02F *
    Plant_DW.Rotor_Delay_states[3];

  /* Math: '<S13>/Square' incorporates:
   *  DiscreteFilter: '<S8>/Rotor_Delay'
   *  Math: '<S15>/Square'
   */
  rtb_Saturation1_idx_3 = rtb_Divide_g * rtb_Divide_g;

  /* Sum: '<S14>/Add' incorporates:
   *  DiscreteFilter: '<S8>/Rotor_Delay'
   */
  rtb_Gain_h = ((Rotor_Delay_tmp_idx_2 - Rotor_Delay_tmp_idx_0) -
                Rotor_Delay_tmp_idx_1) + rtb_Divide_g;

  /* Product: '<S17>/Multiply' */
  rtb_Add_la[0] = 0.0F;

  /* Product: '<S17>/Multiply1' incorporates:
   *  Delay: '<Root>/Delay'
   *  Product: '<S14>/Multiply'
   */
  rtb_Add_la[1] = rtb_Gain_h * Plant_Y.Plant_States.rot_x_B * 0.0001287F;

  /* Product: '<S17>/Multiply2' */
  rtb_Add_la[2] = 0.0F;

  /* Product: '<S18>/Multiply3' incorporates:
   *  Delay: '<Root>/Delay'
   *  Product: '<S14>/Multiply'
   */
  rtb_VectorConcatenate1_d[0] = rtb_Gain_h * Plant_Y.Plant_States.rot_y_B *
    0.0001287F;

  /* Product: '<S18>/Multiply4' */
  rtb_VectorConcatenate1_d[1] = 0.0F;

  /* Product: '<S18>/Multiply5' */
  rtb_VectorConcatenate1_d[2] = 0.0F;

  /* Update for DiscreteFilter: '<S8>/Rotor_Delay' */
  Plant_DW.Rotor_Delay_states[0] = Rotor_Delay_tmp_idx_0;
  Plant_DW.Rotor_Delay_states[1] = Rotor_Delay_tmp_idx_1;
  Plant_DW.Rotor_Delay_states[2] = Rotor_Delay_tmp_idx_2;
  Plant_DW.Rotor_Delay_states[3] = rtb_Divide_g;

  /* End of Outputs for SubSystem: '<Root>/Actuators' */

  /* Outputs for Atomic SubSystem: '<Root>/Environment' */
  /* Trigonometry: '<S34>/Trigonometric Function1' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S33>/Gain'
   *  Trigonometry: '<S34>/Trigonometric Function3'
   */
  rtb_Switch1 = arm_cos_f32(-Plant_Y.Plant_States.psi);
  rtb_VectorConcatenate_f[0] = rtb_Switch1;

  /* Trigonometry: '<S34>/Trigonometric Function' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S33>/Gain'
   *  Trigonometry: '<S34>/Trigonometric Function2'
   */
  rtb_omega_B_radPs_idx_1 = arm_sin_f32(-Plant_Y.Plant_States.psi);
  rtb_VectorConcatenate_f[1] = rtb_omega_B_radPs_idx_1;

  /* SignalConversion: '<S34>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S34>/Constant3'
   */
  rtb_VectorConcatenate_f[2] = 0.0F;

  /* Gain: '<S34>/Gain' */
  rtb_VectorConcatenate_f[3] = -rtb_omega_B_radPs_idx_1;

  /* Trigonometry: '<S34>/Trigonometric Function3' */
  rtb_VectorConcatenate_f[4] = rtb_Switch1;

  /* SignalConversion: '<S34>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S34>/Constant4'
   */
  rtb_VectorConcatenate_f[5] = 0.0F;

  /* SignalConversion: '<S34>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_f[6] = Plant_ConstB.VectorConcatenate3_e[0];
  rtb_VectorConcatenate_f[7] = Plant_ConstB.VectorConcatenate3_e[1];
  rtb_VectorConcatenate_f[8] = Plant_ConstB.VectorConcatenate3_e[2];

  /* RelationalOperator: '<S35>/Compare' incorporates:
   *  Constant: '<S35>/Constant'
   *  Delay: '<Root>/Delay'
   */
  rtb_Compare = (Plant_Y.Plant_States.h_R < 0.0F);

  /* Switch: '<S31>/Switch2' incorporates:
   *  Product: '<S36>/Multiply'
   *  SignalConversion: '<S36>/TmpSignal ConversionAtMultiplyInport2'
   */
  if (rtb_Compare) {
    /* Switch: '<S36>/Switch1' incorporates:
     *  Constant: '<S36>/mg'
     *  Constant: '<S38>/Constant'
     *  Delay: '<Root>/Delay'
     *  Gain: '<S36>/Gain'
     *  RelationalOperator: '<S38>/Compare'
     *  Sum: '<S36>/Add'
     */
    if (Plant_Y.Plant_States.h_R <= -0.05F) {
      /* Switch: '<S36>/Switch3' incorporates:
       *  Constant: '<S36>/mg'
       *  Constant: '<S39>/Constant'
       *  Gain: '<S36>/Gain1'
       *  Gain: '<S36>/Gain2'
       *  Gain: '<S36>/Gain4'
       *  RelationalOperator: '<S39>/Compare'
       *  Sum: '<S36>/Add1'
       *  Sum: '<S36>/Add2'
       */
      if (Plant_Y.Plant_States.h_R <= -0.1F) {
        rtb_Switch1 = (Plant_Y.Plant_States.h_R - 8.68811607F) - 50.0F *
          Plant_Y.Plant_States.vel_z_O;
      } else {
        rtb_Switch1 = (0.5F * Plant_Y.Plant_States.h_R - 8.68811607F) - 20.0F *
          Plant_Y.Plant_States.vel_z_O;
      }

      /* End of Switch: '<S36>/Switch3' */
    } else {
      rtb_Switch1 = -8.68811607F - 10.0F * Plant_Y.Plant_States.vel_z_O;
    }

    /* End of Switch: '<S36>/Switch1' */

    /* SignalConversion: '<S36>/TmpSignal ConversionAtMultiplyInport2' incorporates:
     *  Delay: '<Root>/Delay'
     *  Gain: '<S36>/Gain5'
     *  Gain: '<S36>/Gain6'
     */
    rtb_omega_B_radPs_idx_1 = -50.0F * Plant_Y.Plant_States.vel_x_O;
    rtb_omega_B_radPs_idx_2 = -50.0F * Plant_Y.Plant_States.vel_y_O;
    for (i = 0; i < 3; i++) {
      rtb_Sum_hq[i] = rtb_VectorConcatenate_k[i + 6] * rtb_Switch1 +
        (rtb_VectorConcatenate_k[i + 3] * rtb_omega_B_radPs_idx_2 +
         rtb_VectorConcatenate_k[i] * rtb_omega_B_radPs_idx_1);
    }
  } else {
    rtb_Sum_hq[0] = 0.0F;
    rtb_Sum_hq[1] = 0.0F;
    rtb_Sum_hq[2] = 0.0F;
  }

  /* End of Switch: '<S31>/Switch2' */
  for (i = 0; i < 3; i++) {
    /* Gain: '<S32>/Gain' incorporates:
     *  Delay: '<Root>/Delay'
     *  Product: '<S32>/Multiply'
     */
    tmp[i] = -0.15F * (rtb_VectorConcatenate_f[i + 6] *
                       Plant_Y.Plant_States.vel_z_O + (rtb_VectorConcatenate_f[i
      + 3] * Plant_Y.Plant_States.vel_y_O + rtb_VectorConcatenate_f[i] *
      Plant_Y.Plant_States.vel_x_O));

    /* Product: '<S30>/Multiply3' */
    rtb_Add1_c[i] = rtb_VectorConcatenate_k[i + 6] * 8.69166F;
  }

  /* Product: '<S32>/Multiply1' incorporates:
   *  Math: '<S32>/Square'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_l[i] = rtb_VectorConcatenate_f[3 * i + 2] * tmp[2] +
      (rtb_VectorConcatenate_f[3 * i + 1] * tmp[1] + rtb_VectorConcatenate_f[3 *
       i] * tmp[0]);
  }

  /* End of Product: '<S32>/Multiply1' */

  /* Sum: '<S3>/Sum' incorporates:
   *  Constant: '<S13>/cT'
   *  Constant: '<S9>/Constant'
   *  Constant: '<S9>/Constant1'
   *  Gain: '<S9>/Gain'
   *  Product: '<S13>/Multiply'
   *  Sum: '<S9>/Sum of Elements'
   */
  tmp[0] = 0.0F;
  tmp[1] = 0.0F;

  /* Outputs for Atomic SubSystem: '<Root>/Actuators' */
  tmp[2] = -(((rtb_Divide_f_idx_0 + rtb_Divide_f_idx_1) + rtb_Divide_f_idx_2) +
             (real32_T)(rtb_Saturation1_idx_3 * 1.239E-5));

  /* End of Outputs for SubSystem: '<Root>/Actuators' */
  for (i = 0; i < 3; i++) {
    /* Sum: '<S3>/Add' incorporates:
     *  Product: '<S32>/Multiply2'
     *  Sum: '<S3>/Sum'
     */
    rtb_Add_lr[i] = (rtb_Sum_hq[i] + rtb_Add1_c[i]) + (tmp[i] +
      (rtb_VectorConcatenate_k[i + 6] * rtb_VectorConcatenate_l[2] +
       (rtb_VectorConcatenate_k[i + 3] * rtb_VectorConcatenate_l[1] +
        rtb_VectorConcatenate_k[i] * rtb_VectorConcatenate_l[0])));
  }

  /* Switch: '<S31>/Switch1' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S37>/Gain1'
   *  Gain: '<S37>/Gain2'
   *  Gain: '<S37>/Gain3'
   *  Sum: '<S37>/Subtract'
   */
  if (rtb_Compare) {
    rtb_Sum_hq[0] = ((0.0F - 30.0F * Plant_Y.Plant_States.phi) - 5.0F *
                     Plant_Y.Plant_States.rot_x_B) * 0.289603859F;
    rtb_Sum_hq[1] = ((0.0F - 30.0F * Plant_Y.Plant_States.theta) - 5.0F *
                     Plant_Y.Plant_States.rot_y_B) * 0.289603859F;
    rtb_Sum_hq[2] = (0.0F - 5.0F * Plant_Y.Plant_States.rot_z_B) * 0.289603859F;
  } else {
    rtb_Sum_hq[0] = 0.0F;
    rtb_Sum_hq[1] = 0.0F;
    rtb_Sum_hq[2] = 0.0F;
  }

  /* End of Switch: '<S31>/Switch1' */

  /* Outputs for Atomic SubSystem: '<Root>/Actuators' */
  for (i = 0; i < 3; i++) {
    /* Sum: '<S3>/Add1' incorporates:
     *  Constant: '<S15>/X_Frame_CM'
     *  Math: '<S15>/Square'
     *  Product: '<S15>/Multiply'
     *  Sum: '<S10>/Sum'
     *  Sum: '<S16>/Sum'
     */
    rtb_Add1_c[i] = ((((Plant_ConstP.X_Frame_CM_Value[i + 3] *
                        rtb_Saturation1_idx_1 + Plant_ConstP.X_Frame_CM_Value[i]
                        * rtb_Saturation1_idx_0) +
                       Plant_ConstP.X_Frame_CM_Value[i + 6] *
                       rtb_Saturation1_idx_2) + Plant_ConstP.X_Frame_CM_Value[i
                      + 9] * rtb_Saturation1_idx_3) + (rtb_Add_la[i] -
      rtb_VectorConcatenate1_d[i])) + rtb_Sum_hq[i];
  }

  /* End of Outputs for SubSystem: '<Root>/Actuators' */
  /* End of Outputs for SubSystem: '<Root>/Environment' */

  /* Outputs for Atomic SubSystem: '<Root>/Kinematic_Equation' */
  /* DiscreteIntegrator: '<S44>/Discrete-Time Integrator' */
  if (Plant_DW.DiscreteTimeIntegrator_PrevRese != 0) {
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[0] = Plant_ConstB.quat0[0];
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[1] = Plant_ConstB.quat0[1];
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[2] = Plant_ConstB.quat0[2];
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[3] = Plant_ConstB.quat0[3];
  }

  rtb_Saturation1_idx_0 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[0];
  rtb_Saturation1_idx_1 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[1];
  rtb_Saturation1_idx_2 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[2];
  rtb_Saturation1_idx_3 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[3];

  /* SignalConversion: '<S49>/ConcatBufferAtMatrix ConcatenateIn1' incorporates:
   *  Constant: '<S49>/Constant'
   */
  rtb_MatrixConcatenate4[0] = 0.0F;

  /* DiscreteIntegrator: '<S40>/Discrete-Time Integrator' */
  if (Plant_DW.DiscreteTimeIntegrator_PrevRe_d != 0) {
    Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2] = 0.0F;
  }

  rtb_Switch1 = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0];
  rtb_omega_B_radPs_idx_1 = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1];
  rtb_omega_B_radPs_idx_2 = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2];

  /* SignalConversion: '<S49>/ConcatBufferAtMatrix ConcatenateIn2' incorporates:
   *  DiscreteIntegrator: '<S40>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[1] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0];

  /* SignalConversion: '<S49>/ConcatBufferAtMatrix ConcatenateIn3' incorporates:
   *  DiscreteIntegrator: '<S40>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[2] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1];

  /* SignalConversion: '<S49>/ConcatBufferAtMatrix ConcatenateIn4' incorporates:
   *  DiscreteIntegrator: '<S40>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[3] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2];

  /* Gain: '<S49>/Gain1' incorporates:
   *  DiscreteIntegrator: '<S40>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[4] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0];

  /* SignalConversion: '<S49>/ConcatBufferAtMatrix Concatenate1In2' incorporates:
   *  Constant: '<S49>/Constant1'
   */
  rtb_MatrixConcatenate4[5] = 0.0F;

  /* Gain: '<S49>/Gain2' incorporates:
   *  DiscreteIntegrator: '<S40>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[6] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2];

  /* SignalConversion: '<S49>/ConcatBufferAtMatrix Concatenate1In4' incorporates:
   *  DiscreteIntegrator: '<S40>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[7] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1];

  /* Gain: '<S49>/Gain3' incorporates:
   *  DiscreteIntegrator: '<S40>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[8] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1];

  /* SignalConversion: '<S49>/ConcatBufferAtMatrix Concatenate2In2' incorporates:
   *  DiscreteIntegrator: '<S40>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[9] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2];

  /* SignalConversion: '<S49>/ConcatBufferAtMatrix Concatenate2In3' incorporates:
   *  Constant: '<S49>/Constant2'
   */
  rtb_MatrixConcatenate4[10] = 0.0F;

  /* Gain: '<S49>/Gain4' incorporates:
   *  DiscreteIntegrator: '<S40>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[11] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0];

  /* Gain: '<S49>/Gain6' incorporates:
   *  DiscreteIntegrator: '<S40>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[12] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2];

  /* Gain: '<S49>/Gain7' incorporates:
   *  DiscreteIntegrator: '<S40>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[13] = -Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1];

  /* SignalConversion: '<S49>/ConcatBufferAtMatrix Concatenate3In3' incorporates:
   *  DiscreteIntegrator: '<S40>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[14] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0];

  /* SignalConversion: '<S49>/ConcatBufferAtMatrix Concatenate3In4' incorporates:
   *  Constant: '<S49>/Constant3'
   */
  rtb_MatrixConcatenate4[15] = 0.0F;

  /* Sqrt: '<S48>/Sqrt' incorporates:
   *  DiscreteIntegrator: '<S44>/Discrete-Time Integrator'
   *  Math: '<S48>/Square'
   *  Sqrt: '<S59>/Sqrt'
   *  Sqrt: '<S64>/Sqrt'
   *  Sum: '<S48>/Sum of Elements'
   */
  rtb_Sum_i = sqrtf(((Plant_DW.DiscreteTimeIntegrator_DSTATE_d[0] *
                      Plant_DW.DiscreteTimeIntegrator_DSTATE_d[0] +
                      Plant_DW.DiscreteTimeIntegrator_DSTATE_d[1] *
                      Plant_DW.DiscreteTimeIntegrator_DSTATE_d[1]) +
                     Plant_DW.DiscreteTimeIntegrator_DSTATE_d[2] *
                     Plant_DW.DiscreteTimeIntegrator_DSTATE_d[2]) +
                    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[3] *
                    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[3]);

  /* Product: '<S47>/Divide' incorporates:
   *  DiscreteIntegrator: '<S44>/Discrete-Time Integrator'
   *  Sqrt: '<S48>/Sqrt'
   */
  rtb_TrigonometricFunction1_idx_ = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[0] /
    rtb_Sum_i;
  rtb_TrigonometricFunction1_id_0 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[1] /
    rtb_Sum_i;
  rtb_TrigonometricFunction1_id_1 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[2] /
    rtb_Sum_i;
  rtb_TrigonometricFunction1_id_2 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[3] /
    rtb_Sum_i;

  /* Product: '<S55>/Divide' incorporates:
   *  DiscreteIntegrator: '<S44>/Discrete-Time Integrator'
   */
  rtb_Divide_n_idx_0 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[0] / rtb_Sum_i;
  rtb_Divide_n_idx_1 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[1] / rtb_Sum_i;
  rtb_Divide_n_idx_2 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[2] / rtb_Sum_i;
  rtb_Gain_h = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[3] / rtb_Sum_i;

  /* Product: '<S60>/Divide' incorporates:
   *  DiscreteIntegrator: '<S44>/Discrete-Time Integrator'
   */
  rtb_Divide_f_idx_0 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[0] / rtb_Sum_i;
  rtb_Divide_f_idx_1 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[1] / rtb_Sum_i;
  rtb_Divide_f_idx_2 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[2] / rtb_Sum_i;
  rtb_Divide_f_idx_3 = Plant_DW.DiscreteTimeIntegrator_DSTATE_d[3] / rtb_Sum_i;

  /* Product: '<S40>/Multiply' incorporates:
   *  Constant: '<S40>/Inertia_Matrix'
   *  DiscreteIntegrator: '<S40>/Discrete-Time Integrator'
   */
  for (i = 0; i < 3; i++) {
    rtb_Add_la[i] = Plant_ConstP.Inertia_Matrix_Value[i + 6] *
      Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2] +
      (Plant_ConstP.Inertia_Matrix_Value[i + 3] *
       Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1] +
       Plant_ConstP.Inertia_Matrix_Value[i] *
       Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0]);
  }

  /* End of Product: '<S40>/Multiply' */

  /* Product: '<S45>/Multiply' incorporates:
   *  DiscreteIntegrator: '<S40>/Discrete-Time Integrator'
   */
  rtb_Sum_d[0] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1] * rtb_Add_la[2];

  /* Product: '<S45>/Multiply1' incorporates:
   *  DiscreteIntegrator: '<S40>/Discrete-Time Integrator'
   */
  rtb_Sum_d[1] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2] * rtb_Add_la[0];

  /* Product: '<S45>/Multiply2' incorporates:
   *  DiscreteIntegrator: '<S40>/Discrete-Time Integrator'
   */
  rtb_Sum_d[2] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0] * rtb_Add_la[1];

  /* Product: '<S46>/Multiply3' incorporates:
   *  DiscreteIntegrator: '<S40>/Discrete-Time Integrator'
   */
  rtb_Sum_b[0] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2] * rtb_Add_la[1];

  /* Product: '<S46>/Multiply4' incorporates:
   *  DiscreteIntegrator: '<S40>/Discrete-Time Integrator'
   */
  rtb_Sum_b[1] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0] * rtb_Add_la[2];

  /* Product: '<S46>/Multiply5' incorporates:
   *  DiscreteIntegrator: '<S40>/Discrete-Time Integrator'
   */
  rtb_Sum_b[2] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1] * rtb_Add_la[0];

  /* DiscreteIntegrator: '<S41>/Discrete-Time Integrator' */
  if (Plant_DW.DiscreteTimeIntegrator_PrevRe_k != 0) {
    Plant_DW.DiscreteTimeIntegrator_DSTATE_f[0] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_f[1] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_f[2] = 0.0F;
  }

  /* Product: '<S58>/Product3' incorporates:
   *  Product: '<S55>/Divide'
   *  Product: '<S56>/Product6'
   */
  rtb_Sum_i = rtb_Divide_n_idx_2 * rtb_Divide_n_idx_2;

  /* Product: '<S58>/Product6' incorporates:
   *  Product: '<S55>/Divide'
   *  Product: '<S56>/Product9'
   */
  rtb_Add_e_tmp = rtb_Divide_n_idx_1 * rtb_Gain_h;

  /* Product: '<S58>/Product7' incorporates:
   *  Product: '<S55>/Divide'
   *  Product: '<S56>/Product2'
   */
  rtb_Add_e_tmp_0 = rtb_Divide_n_idx_0 * rtb_Divide_n_idx_2;

  /* Product: '<S58>/Product2' incorporates:
   *  Product: '<S55>/Divide'
   */
  rtb_vel_O_mPs_idx_0 = rtb_Divide_n_idx_1 * rtb_Divide_n_idx_1;

  /* Product: '<S58>/Product1' incorporates:
   *  Product: '<S55>/Divide'
   *  Product: '<S57>/Product2'
   */
  rtb_vel_O_mPs_idx_1 = rtb_Divide_n_idx_0 * rtb_Divide_n_idx_1;

  /* Product: '<S58>/Product9' incorporates:
   *  Product: '<S55>/Divide'
   *  Product: '<S57>/Product3'
   */
  rtb_vel_O_mPs_idx_2 = rtb_Divide_n_idx_2 * rtb_Gain_h;

  /* Sum: '<S58>/Sum' incorporates:
   *  Constant: '<S58>/Constant'
   *  DiscreteIntegrator: '<S41>/Discrete-Time Integrator'
   *  Gain: '<S58>/Gain1'
   *  Gain: '<S58>/Gain2'
   *  Gain: '<S58>/Gain3'
   *  Product: '<S58>/Product1'
   *  Product: '<S58>/Product2'
   *  Product: '<S58>/Product3'
   *  Product: '<S58>/Product4'
   *  Product: '<S58>/Product5'
   *  Product: '<S58>/Product6'
   *  Product: '<S58>/Product7'
   *  Product: '<S58>/Product8'
   *  Product: '<S58>/Product9'
   *  Sum: '<S58>/Sum1'
   *  Sum: '<S58>/Sum2'
   *  Sum: '<S58>/Sum3'
   */
  rtb_Add_e = ((rtb_Add_e_tmp + rtb_Add_e_tmp_0) * 2.0F *
               Plant_DW.DiscreteTimeIntegrator_DSTATE_f[0] +
               (rtb_vel_O_mPs_idx_2 - rtb_vel_O_mPs_idx_1) * 2.0F *
               Plant_DW.DiscreteTimeIntegrator_DSTATE_f[1]) + ((0.5F -
    rtb_vel_O_mPs_idx_0) - rtb_Sum_i) * 2.0F *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_f[2];

  /* Product: '<S56>/Product7' incorporates:
   *  Product: '<S55>/Divide'
   *  Product: '<S57>/Product9'
   */
  rtb_Sum_c0 = rtb_Gain_h * rtb_Gain_h;

  /* Product: '<S56>/Product' incorporates:
   *  Product: '<S55>/Divide'
   *  Product: '<S57>/Product6'
   */
  rtb_Divide_n_idx_1 *= rtb_Divide_n_idx_2;

  /* Product: '<S56>/Product1' incorporates:
   *  Product: '<S55>/Divide'
   *  Product: '<S57>/Product7'
   */
  rtb_Divide_n_idx_0 *= rtb_Gain_h;

  /* Sum: '<S56>/Sum' incorporates:
   *  Constant: '<S56>/Constant'
   *  DiscreteIntegrator: '<S41>/Discrete-Time Integrator'
   *  Gain: '<S56>/Gain'
   *  Gain: '<S56>/Gain2'
   *  Gain: '<S56>/Gain3'
   *  Product: '<S56>/Product'
   *  Product: '<S56>/Product1'
   *  Product: '<S56>/Product4'
   *  Product: '<S56>/Product5'
   *  Product: '<S56>/Product7'
   *  Product: '<S56>/Product8'
   *  Sum: '<S56>/Sum1'
   *  Sum: '<S56>/Sum2'
   *  Sum: '<S56>/Sum3'
   */
  rtb_Gain_h = (((0.5F - rtb_Sum_i) - rtb_Sum_c0) * 2.0F *
                Plant_DW.DiscreteTimeIntegrator_DSTATE_f[0] +
                (rtb_Divide_n_idx_1 + rtb_Divide_n_idx_0) * 2.0F *
                Plant_DW.DiscreteTimeIntegrator_DSTATE_f[1]) + (rtb_Add_e_tmp -
    rtb_Add_e_tmp_0) * 2.0F * Plant_DW.DiscreteTimeIntegrator_DSTATE_f[2];

  /* Product: '<S53>/Multiply1' incorporates:
   *  DiscreteIntegrator: '<S40>/Discrete-Time Integrator'
   */
  rtb_Add_la[1] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2] * rtb_Gain_h;

  /* Product: '<S54>/Multiply5' incorporates:
   *  DiscreteIntegrator: '<S40>/Discrete-Time Integrator'
   */
  rtb_Sum_hq[2] = Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1] * rtb_Gain_h;

  /* Sum: '<S57>/Sum' incorporates:
   *  Constant: '<S58>/Constant'
   *  DiscreteIntegrator: '<S41>/Discrete-Time Integrator'
   *  Gain: '<S57>/Gain1'
   *  Gain: '<S57>/Gain2'
   *  Gain: '<S57>/Gain3'
   *  Product: '<S57>/Product4'
   *  Product: '<S57>/Product5'
   *  Product: '<S57>/Product8'
   *  Product: '<S58>/Product2'
   *  Sum: '<S57>/Sum1'
   *  Sum: '<S57>/Sum2'
   *  Sum: '<S57>/Sum3'
   *  Sum: '<S58>/Sum2'
   */
  rtb_Gain_h = (((0.5F - rtb_vel_O_mPs_idx_0) - rtb_Sum_c0) * 2.0F *
                Plant_DW.DiscreteTimeIntegrator_DSTATE_f[1] +
                (rtb_Divide_n_idx_1 - rtb_Divide_n_idx_0) * 2.0F *
                Plant_DW.DiscreteTimeIntegrator_DSTATE_f[0]) +
    (rtb_vel_O_mPs_idx_1 + rtb_vel_O_mPs_idx_2) * 2.0F *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_f[2];

  /* DiscreteIntegrator: '<S41>/Discrete-Time Integrator' */
  rtb_vel_O_mPs_idx_0 = Plant_DW.DiscreteTimeIntegrator_DSTATE_f[0];

  /* Sum: '<S40>/Sum' incorporates:
   *  Sum: '<S42>/Sum'
   */
  rtb_Sum_b[0] = rtb_Add1_c[0] - (rtb_Sum_d[0] - rtb_Sum_b[0]);

  /* Sum: '<S41>/Sum' incorporates:
   *  Constant: '<S41>/mass'
   *  DiscreteIntegrator: '<S40>/Discrete-Time Integrator'
   *  Product: '<S41>/Divide'
   *  Product: '<S53>/Multiply'
   *  Product: '<S54>/Multiply3'
   *  Sum: '<S50>/Sum'
   */
  rtb_Sum_hq[0] = rtb_Add_lr[0] / 0.886F -
    (Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1] * rtb_Add_e -
     Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2] * rtb_Gain_h);

  /* DiscreteIntegrator: '<S41>/Discrete-Time Integrator' */
  rtb_vel_O_mPs_idx_1 = Plant_DW.DiscreteTimeIntegrator_DSTATE_f[1];

  /* Sum: '<S40>/Sum' incorporates:
   *  Sum: '<S42>/Sum'
   */
  rtb_Sum_b[1] = rtb_Add1_c[1] - (rtb_Sum_d[1] - rtb_Sum_b[1]);

  /* Sum: '<S41>/Sum' incorporates:
   *  Constant: '<S41>/mass'
   *  DiscreteIntegrator: '<S40>/Discrete-Time Integrator'
   *  Product: '<S41>/Divide'
   *  Product: '<S54>/Multiply4'
   *  Sum: '<S50>/Sum'
   */
  rtb_Sum_hq[1] = rtb_Add_lr[1] / 0.886F - (rtb_Add_la[1] -
    Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0] * rtb_Add_e);

  /* DiscreteIntegrator: '<S41>/Discrete-Time Integrator' */
  rtb_vel_O_mPs_idx_2 = Plant_DW.DiscreteTimeIntegrator_DSTATE_f[2];

  /* Sum: '<S41>/Sum' incorporates:
   *  Constant: '<S41>/mass'
   *  DiscreteIntegrator: '<S40>/Discrete-Time Integrator'
   *  Product: '<S41>/Divide'
   *  Product: '<S53>/Multiply2'
   *  Sum: '<S50>/Sum'
   */
  rtb_Add_e = rtb_Add_lr[2] / 0.886F -
    (Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0] * rtb_Gain_h - rtb_Sum_hq[2]);

  /* Sum: '<S40>/Sum' incorporates:
   *  Sum: '<S42>/Sum'
   */
  rtb_Sum_b[2] = rtb_Add1_c[2] - (rtb_Sum_d[2] - rtb_Sum_b[2]);

  /* Sum: '<S61>/Sum' incorporates:
   *  Constant: '<S61>/Constant'
   *  Gain: '<S61>/Gain'
   *  Gain: '<S61>/Gain1'
   *  Gain: '<S61>/Gain2'
   *  Product: '<S60>/Divide'
   *  Product: '<S61>/Product'
   *  Product: '<S61>/Product1'
   *  Product: '<S61>/Product2'
   *  Product: '<S61>/Product3'
   *  Product: '<S61>/Product4'
   *  Product: '<S61>/Product5'
   *  Product: '<S61>/Product6'
   *  Product: '<S61>/Product7'
   *  Product: '<S61>/Product8'
   *  Sum: '<S61>/Sum1'
   *  Sum: '<S61>/Sum2'
   *  Sum: '<S61>/Sum3'
   */
  rtb_Sum_c0 = (((0.5F - rtb_Divide_f_idx_2 * rtb_Divide_f_idx_2) -
                 rtb_Divide_f_idx_3 * rtb_Divide_f_idx_3) * 2.0F * rtb_Sum_hq[0]
                + (rtb_Divide_f_idx_1 * rtb_Divide_f_idx_2 - rtb_Divide_f_idx_0 *
                   rtb_Divide_f_idx_3) * 2.0F * rtb_Sum_hq[1]) +
    (rtb_Divide_f_idx_1 * rtb_Divide_f_idx_3 + rtb_Divide_f_idx_0 *
     rtb_Divide_f_idx_2) * 2.0F * rtb_Add_e;

  /* Sum: '<S62>/Sum' incorporates:
   *  Constant: '<S62>/Constant'
   *  Gain: '<S62>/Gain'
   *  Gain: '<S62>/Gain1'
   *  Gain: '<S62>/Gain2'
   *  Product: '<S60>/Divide'
   *  Product: '<S62>/Product'
   *  Product: '<S62>/Product1'
   *  Product: '<S62>/Product2'
   *  Product: '<S62>/Product3'
   *  Product: '<S62>/Product4'
   *  Product: '<S62>/Product5'
   *  Product: '<S62>/Product6'
   *  Product: '<S62>/Product7'
   *  Product: '<S62>/Product8'
   *  Sum: '<S62>/Sum1'
   *  Sum: '<S62>/Sum2'
   *  Sum: '<S62>/Sum3'
   */
  rtb_Sum_i = (((0.5F - rtb_Divide_f_idx_1 * rtb_Divide_f_idx_1) -
                rtb_Divide_f_idx_3 * rtb_Divide_f_idx_3) * 2.0F * rtb_Sum_hq[1]
               + (rtb_Divide_f_idx_1 * rtb_Divide_f_idx_2 + rtb_Divide_f_idx_0 *
                  rtb_Divide_f_idx_3) * 2.0F * rtb_Sum_hq[0]) +
    (rtb_Divide_f_idx_2 * rtb_Divide_f_idx_3 - rtb_Divide_f_idx_0 *
     rtb_Divide_f_idx_1) * 2.0F * rtb_Add_e;

  /* Sum: '<S63>/Sum' incorporates:
   *  Constant: '<S63>/Constant'
   *  Gain: '<S63>/Gain1'
   *  Gain: '<S63>/Gain2'
   *  Gain: '<S63>/Gain3'
   *  Product: '<S60>/Divide'
   *  Product: '<S63>/Product1'
   *  Product: '<S63>/Product2'
   *  Product: '<S63>/Product3'
   *  Product: '<S63>/Product4'
   *  Product: '<S63>/Product5'
   *  Product: '<S63>/Product6'
   *  Product: '<S63>/Product7'
   *  Product: '<S63>/Product8'
   *  Product: '<S63>/Product9'
   *  Sum: '<S63>/Sum1'
   *  Sum: '<S63>/Sum2'
   *  Sum: '<S63>/Sum3'
   */
  rtb_Divide_f_idx_0 = ((rtb_Divide_f_idx_1 * rtb_Divide_f_idx_3 -
    rtb_Divide_f_idx_0 * rtb_Divide_f_idx_2) * 2.0F * rtb_Sum_hq[0] +
                        (rtb_Divide_f_idx_0 * rtb_Divide_f_idx_1 +
    rtb_Divide_f_idx_2 * rtb_Divide_f_idx_3) * 2.0F * rtb_Sum_hq[1]) + ((0.5F -
    rtb_Divide_f_idx_1 * rtb_Divide_f_idx_1) - rtb_Divide_f_idx_2 *
    rtb_Divide_f_idx_2) * 2.0F * rtb_Add_e;

  /* Math: '<S43>/Square1' incorporates:
   *  Product: '<S47>/Divide'
   */
  rtb_Add_e = rtb_TrigonometricFunction1_id_1 * rtb_TrigonometricFunction1_id_1;

  /* Product: '<S43>/Multiply6' incorporates:
   *  Constant: '<S43>/Constant'
   *  Product: '<S43>/Multiply4'
   *  Product: '<S43>/Multiply5'
   *  Product: '<S47>/Divide'
   *  Sum: '<S43>/Subtract'
   */
  rtb_Divide_f_idx_1 = (rtb_TrigonometricFunction1_idx_ *
                        rtb_TrigonometricFunction1_id_1 -
                        rtb_TrigonometricFunction1_id_2 *
                        rtb_TrigonometricFunction1_id_0) * 2.0F;

  /* DiscreteIntegrator: '<S41>/Discrete-Time Integrator1' */
  if (Plant_DW.DiscreteTimeIntegrator1_PrevRes != 0) {
    Plant_DW.DiscreteTimeIntegrator1_DSTATE[0] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator1_DSTATE[1] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator1_DSTATE[2] = 0.0F;
  }

  rtb_Sum_hq[0] = Plant_DW.DiscreteTimeIntegrator1_DSTATE[0];
  rtb_Sum_hq[1] = Plant_DW.DiscreteTimeIntegrator1_DSTATE[1];
  rtb_Sum_hq[2] = Plant_DW.DiscreteTimeIntegrator1_DSTATE[2];

  /* End of DiscreteIntegrator: '<S41>/Discrete-Time Integrator1' */

  /* Product: '<S44>/Multiply' incorporates:
   *  DiscreteIntegrator: '<S44>/Discrete-Time Integrator'
   */
  for (i = 0; i < 4; i++) {
    rtb_Divide_f_idx_2 = rtb_MatrixConcatenate4[i + 12] *
      Plant_DW.DiscreteTimeIntegrator_DSTATE_d[3] + (rtb_MatrixConcatenate4[i +
      8] * Plant_DW.DiscreteTimeIntegrator_DSTATE_d[2] +
      (rtb_MatrixConcatenate4[i + 4] * Plant_DW.DiscreteTimeIntegrator_DSTATE_d
       [1] + rtb_MatrixConcatenate4[i] *
       Plant_DW.DiscreteTimeIntegrator_DSTATE_d[0]));
    rtb_MatrixConcatenate4_0[i] = rtb_Divide_f_idx_2;
  }

  /* End of Product: '<S44>/Multiply' */

  /* Update for DiscreteIntegrator: '<S44>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S44>/Gain'
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

  /* Product: '<S40>/Divide' incorporates:
   *  Constant: '<S40>/Inertia_Matrix'
   */
  rt_mldivide_U1f3x3_U2f3x1_Yf3x1(Plant_ConstP.Inertia_Matrix_Value, rtb_Sum_b,
    tmp);

  /* Update for DiscreteIntegrator: '<S40>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_PrevRe_d = 0;

  /* Update for DiscreteIntegrator: '<S41>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_PrevRe_k = 0;

  /* Update for DiscreteIntegrator: '<S40>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_e[0] += 0.002F * tmp[0];

  /* Update for DiscreteIntegrator: '<S41>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_f[0] += 0.002F * rtb_Sum_c0;

  /* Update for DiscreteIntegrator: '<S41>/Discrete-Time Integrator1' */
  Plant_DW.DiscreteTimeIntegrator1_DSTATE[0] += 0.002F * rtb_vel_O_mPs_idx_0;

  /* Update for DiscreteIntegrator: '<S40>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_e[1] += 0.002F * tmp[1];

  /* Update for DiscreteIntegrator: '<S41>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_f[1] += 0.002F * rtb_Sum_i;

  /* Update for DiscreteIntegrator: '<S41>/Discrete-Time Integrator1' */
  Plant_DW.DiscreteTimeIntegrator1_DSTATE[1] += 0.002F * rtb_vel_O_mPs_idx_1;

  /* Update for DiscreteIntegrator: '<S40>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_e[2] += 0.002F * tmp[2];

  /* Update for DiscreteIntegrator: '<S41>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_f[2] += 0.002F * rtb_Divide_f_idx_0;

  /* Update for DiscreteIntegrator: '<S41>/Discrete-Time Integrator1' */
  Plant_DW.DiscreteTimeIntegrator1_DSTATE[2] += 0.002F * rtb_vel_O_mPs_idx_2;
  Plant_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* End of Outputs for SubSystem: '<Root>/Kinematic_Equation' */

  /* Outputs for Atomic SubSystem: '<Root>/Bus_Constructor' */
  /* Sqrt: '<S26>/Sqrt' incorporates:
   *  Math: '<S26>/Square'
   *  Sum: '<S26>/Sum of Elements'
   */
  rtb_Gain_h = sqrtf(((rtb_Saturation1_idx_0 * rtb_Saturation1_idx_0 +
                       rtb_Saturation1_idx_1 * rtb_Saturation1_idx_1) +
                      rtb_Saturation1_idx_2 * rtb_Saturation1_idx_2) +
                     rtb_Saturation1_idx_3 * rtb_Saturation1_idx_3);

  /* Product: '<S22>/Divide' */
  rtb_Divide_n_idx_0 = rtb_Saturation1_idx_0 / rtb_Gain_h;
  rtb_Divide_n_idx_1 = rtb_Saturation1_idx_1 / rtb_Gain_h;
  rtb_Divide_n_idx_2 = rtb_Saturation1_idx_2 / rtb_Gain_h;
  rtb_Gain_h = rtb_Saturation1_idx_3 / rtb_Gain_h;

  /* Math: '<S23>/Square' incorporates:
   *  Math: '<S24>/Square'
   *  Math: '<S25>/Square'
   */
  rtb_Divide_f_idx_2 = rtb_Divide_n_idx_0 * rtb_Divide_n_idx_0;

  /* Sum: '<S23>/Subtract' incorporates:
   *  Math: '<S23>/Square'
   *  Math: '<S23>/Square1'
   *  Math: '<S23>/Square2'
   *  Math: '<S23>/Square3'
   *  Sum: '<S23>/Add'
   *  Sum: '<S23>/Add1'
   */
  rtb_MatrixConcatenate1[0] = (rtb_Divide_f_idx_2 + rtb_Divide_n_idx_1 *
    rtb_Divide_n_idx_1) - (rtb_Divide_n_idx_2 * rtb_Divide_n_idx_2 + rtb_Gain_h *
    rtb_Gain_h);

  /* Gain: '<S23>/Gain' incorporates:
   *  Product: '<S23>/Multiply'
   *  Product: '<S23>/Multiply1'
   *  Sum: '<S23>/Subtract1'
   */
  rtb_MatrixConcatenate1[1] = (rtb_Divide_n_idx_1 * rtb_Divide_n_idx_2 -
    rtb_Divide_n_idx_0 * rtb_Gain_h) * 2.0F;

  /* Gain: '<S23>/Gain1' incorporates:
   *  Product: '<S23>/Multiply2'
   *  Product: '<S23>/Multiply3'
   *  Sum: '<S23>/Add2'
   */
  rtb_MatrixConcatenate1[2] = (rtb_Divide_n_idx_1 * rtb_Gain_h +
    rtb_Divide_n_idx_0 * rtb_Divide_n_idx_2) * 2.0F;

  /* Gain: '<S24>/Gain' incorporates:
   *  Product: '<S24>/Multiply'
   *  Product: '<S24>/Multiply1'
   *  Sum: '<S24>/Add3'
   */
  rtb_MatrixConcatenate1[3] = (rtb_Divide_n_idx_1 * rtb_Divide_n_idx_2 +
    rtb_Divide_n_idx_0 * rtb_Gain_h) * 2.0F;

  /* Sum: '<S24>/Subtract' incorporates:
   *  Math: '<S24>/Square1'
   *  Math: '<S24>/Square2'
   *  Math: '<S24>/Square3'
   *  Sum: '<S24>/Add'
   *  Sum: '<S24>/Add1'
   */
  rtb_MatrixConcatenate1[4] = (rtb_Divide_f_idx_2 + rtb_Divide_n_idx_2 *
    rtb_Divide_n_idx_2) - (rtb_Divide_n_idx_1 * rtb_Divide_n_idx_1 + rtb_Gain_h *
    rtb_Gain_h);

  /* Gain: '<S24>/Gain1' incorporates:
   *  Product: '<S24>/Multiply2'
   *  Product: '<S24>/Multiply3'
   *  Sum: '<S24>/Subtract1'
   */
  rtb_MatrixConcatenate1[5] = (rtb_Divide_n_idx_2 * rtb_Gain_h -
    rtb_Divide_n_idx_0 * rtb_Divide_n_idx_1) * 2.0F;

  /* Gain: '<S25>/Gain' incorporates:
   *  Product: '<S25>/Multiply'
   *  Product: '<S25>/Multiply1'
   *  Sum: '<S25>/Subtract2'
   */
  rtb_MatrixConcatenate1[6] = (rtb_Divide_n_idx_1 * rtb_Gain_h -
    rtb_Divide_n_idx_0 * rtb_Divide_n_idx_2) * 2.0F;

  /* Gain: '<S25>/Gain1' incorporates:
   *  Product: '<S25>/Multiply2'
   *  Product: '<S25>/Multiply3'
   *  Sum: '<S25>/Add2'
   */
  rtb_MatrixConcatenate1[7] = (rtb_Divide_n_idx_2 * rtb_Gain_h +
    rtb_Divide_n_idx_0 * rtb_Divide_n_idx_1) * 2.0F;

  /* Sum: '<S25>/Subtract' incorporates:
   *  Math: '<S25>/Square1'
   *  Math: '<S25>/Square2'
   *  Math: '<S25>/Square3'
   *  Sum: '<S25>/Add'
   *  Sum: '<S25>/Add1'
   */
  rtb_MatrixConcatenate1[8] = (rtb_Divide_f_idx_2 + rtb_Gain_h * rtb_Gain_h) -
    (rtb_Divide_n_idx_1 * rtb_Divide_n_idx_1 + rtb_Divide_n_idx_2 *
     rtb_Divide_n_idx_2);

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
   *  DiscreteFilter: '<S8>/Rotor_Delay'
   *  SignalConversion: '<S2>/TmpHiddenBufferAtBus Assignment2Inport1'
   */
  Plant_Y.Extended_States = Plant_rtZExtended_States_Bus;
  Plant_Y.Extended_States.temprature = 25.0F;
  Plant_Y.Extended_States.prop_vel[0] = Rotor_Delay_tmp_idx_0;
  Plant_Y.Extended_States.prop_vel[4] = 0.0F;
  Plant_Y.Extended_States.prop_vel[1] = Rotor_Delay_tmp_idx_1;
  Plant_Y.Extended_States.prop_vel[5] = 0.0F;
  Plant_Y.Extended_States.prop_vel[2] = Rotor_Delay_tmp_idx_2;
  Plant_Y.Extended_States.prop_vel[6] = 0.0F;

  /* Outputs for Atomic SubSystem: '<Root>/Actuators' */
  Plant_Y.Extended_States.prop_vel[3] = rtb_Divide_g;

  /* End of Outputs for SubSystem: '<Root>/Actuators' */
  Plant_Y.Extended_States.prop_vel[7] = 0.0F;
  for (i = 0; i < 9; i++) {
    Plant_Y.Extended_States.M_BO[i] = rtb_MatrixConcatenate1[i];
    Plant_Y.Extended_States.M_OB[i] = rtb_VectorConcatenate_f[i];
  }

  Plant_Y.Extended_States.quat[0] = rtb_Saturation1_idx_0;
  Plant_Y.Extended_States.quat[1] = rtb_Saturation1_idx_1;
  Plant_Y.Extended_States.quat[2] = rtb_Saturation1_idx_2;
  Plant_Y.Extended_States.quat[3] = rtb_Saturation1_idx_3;

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
   *  Constant: '<S43>/Constant'
   *  Constant: '<S43>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Math: '<S43>/Square'
   *  Product: '<S43>/Multiply'
   *  Product: '<S43>/Multiply1'
   *  Product: '<S43>/Multiply2'
   *  Product: '<S43>/Multiply3'
   *  Product: '<S47>/Divide'
   *  Sum: '<S43>/Add'
   *  Sum: '<S43>/Add1'
   *  Sum: '<S43>/Subtract2'
   *  Trigonometry: '<S43>/Atan2'
   */
  Plant_Y.Plant_States.phi = atan2f((rtb_TrigonometricFunction1_idx_ *
    rtb_TrigonometricFunction1_id_0 + rtb_TrigonometricFunction1_id_1 *
    rtb_TrigonometricFunction1_id_2) * 2.0F, 1.0F -
    (rtb_TrigonometricFunction1_id_0 * rtb_TrigonometricFunction1_id_0 +
     rtb_Add_e) * 2.0F);

  /* End of Outputs for SubSystem: '<Root>/Bus_Constructor' */

  /* Saturate: '<S43>/Saturation' */
  if (rtb_Divide_f_idx_1 > 1.0F) {
    rtb_Divide_f_idx_1 = 1.0F;
  } else {
    if (rtb_Divide_f_idx_1 < -1.0F) {
      rtb_Divide_f_idx_1 = -1.0F;
    }
  }

  /* End of Saturate: '<S43>/Saturation' */

  /* Outputs for Atomic SubSystem: '<Root>/Bus_Constructor' */
  /* BusAssignment: '<S2>/Bus Assignment' incorporates:
   *  BusAssignment: '<S2>/Bus Assignment1'
   *  Constant: '<S43>/Constant'
   *  Constant: '<S43>/Constant1'
   *  Delay: '<Root>/Delay'
   *  Math: '<S43>/Square2'
   *  Product: '<S43>/Multiply10'
   *  Product: '<S43>/Multiply7'
   *  Product: '<S43>/Multiply8'
   *  Product: '<S43>/Multiply9'
   *  Product: '<S47>/Divide'
   *  Sum: '<S43>/Add2'
   *  Sum: '<S43>/Add3'
   *  Sum: '<S43>/Subtract1'
   *  Trigonometry: '<S43>/Asin'
   *  Trigonometry: '<S43>/Atan1'
   */
  Plant_Y.Plant_States.theta = asinf(rtb_Divide_f_idx_1);
  Plant_Y.Plant_States.psi = atan2f((rtb_TrigonometricFunction1_idx_ *
    rtb_TrigonometricFunction1_id_2 + rtb_TrigonometricFunction1_id_0 *
    rtb_TrigonometricFunction1_id_1) * 2.0F, 1.0F -
    (rtb_TrigonometricFunction1_id_2 * rtb_TrigonometricFunction1_id_2 +
     rtb_Add_e) * 2.0F);

  /* End of Outputs for SubSystem: '<Root>/Kinematic_Equation' */
  Plant_Y.Plant_States.rot_x_B = rtb_Switch1;
  Plant_Y.Plant_States.rot_y_B = rtb_omega_B_radPs_idx_1;
  Plant_Y.Plant_States.rot_z_B = rtb_omega_B_radPs_idx_2;
  Plant_Y.Plant_States.acc_x_O = rtb_Sum_c0;
  Plant_Y.Plant_States.acc_y_O = rtb_Sum_i;
  Plant_Y.Plant_States.acc_z_O = rtb_Divide_f_idx_0;
  Plant_Y.Plant_States.vel_x_O = rtb_vel_O_mPs_idx_0;
  Plant_Y.Plant_States.vel_y_O = rtb_vel_O_mPs_idx_1;
  Plant_Y.Plant_States.vel_z_O = rtb_vel_O_mPs_idx_2;

  /* Trigonometry: '<S27>/Trigonometric Function1' incorporates:
   *  Delay: '<S21>/Delay1'
   *  Trigonometry: '<S27>/Trigonometric Function2'
   */
  Sum2_idx_0 = cos(Plant_DW.Delay1_DSTATE[0]);

  /* Trigonometry: '<S27>/Trigonometric Function' incorporates:
   *  Delay: '<S21>/Delay1'
   */
  rtb_SumofElements = sin(Plant_DW.Delay1_DSTATE[0]);

  /* Sum: '<S27>/Subtract' incorporates:
   *  Constant: '<S27>/c'
   *  Math: '<S27>/u^2'
   *  Product: '<S27>/Product'
   */
  rtb_SumofElements = 1.0 - rtb_SumofElements * rtb_SumofElements *
    Plant_ConstB.Product1;

  /* Math: '<S27>/sqrt'
   *
   * About '<S27>/sqrt':
   *  Operator: sqrt
   */
  if (rtb_SumofElements < 0.0) {
    rtb_SumofElements = -sqrt(fabs(rtb_SumofElements));
  } else {
    rtb_SumofElements = sqrt(rtb_SumofElements);
  }

  /* End of Math: '<S27>/sqrt' */

  /* Product: '<S27>/Divide' incorporates:
   *  Constant: '<S27>/earth_radius'
   */
  rtb_SumofElements = 6.378137E+6 / rtb_SumofElements;

  /* Sum: '<S27>/Add' incorporates:
   *  Constant: '<S27>/constant2'
   *  Delay: '<S21>/Delay1'
   *  Math: '<S27>/u^1'
   *  Product: '<S27>/Product2'
   *  Product: '<S27>/Product3'
   *  Sum: '<S27>/Subtract2'
   *  Trigonometry: '<S27>/Trigonometric Function1'
   */
  rtb_SumofElements1 = (1.0 - Sum2_idx_0 * Sum2_idx_0 * Plant_ConstB.Product1) *
    rtb_SumofElements + Plant_DW.Delay1_DSTATE[2];

  /* Sum: '<S27>/Add1' incorporates:
   *  Delay: '<S21>/Delay1'
   */
  rtb_SumofElements += Plant_DW.Delay1_DSTATE[2];

  /* Product: '<S27>/Product4' */
  rtb_SumofElements *= Sum2_idx_0;

  /* BusAssignment: '<S2>/Bus Assignment1' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S2>/Gain'
   */
  Plant_Y.Plant_States.x_R = rtb_Sum_hq[0];
  Plant_Y.Plant_States.y_R = rtb_Sum_hq[1];
  Plant_Y.Plant_States.h_R = -rtb_Sum_hq[2];

  /* Signum: '<S28>/Sign' */
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

  /* Switch: '<S28>/Switch' incorporates:
   *  Constant: '<S28>/Constant'
   */
  if (Sum2_idx_2 == 0.0) {
    Sum2_idx_0 = 1.0;
  }

  /* Abs: '<S28>/Abs' */
  rtb_SumofElements1 = fabs(rtb_SumofElements1);

  /* Saturate: '<S28>/Saturation' */
  if (rtb_SumofElements1 > 1.0E+8) {
    rtb_SumofElements1 = 1.0E+8;
  } else {
    if (rtb_SumofElements1 < 1.0E-6) {
      rtb_SumofElements1 = 1.0E-6;
    }
  }

  /* Sum: '<S21>/Add' incorporates:
   *  Abs: '<S28>/Abs'
   *  DataTypeConversion: '<S21>/Data Type Conversion'
   *  Delay: '<S21>/Delay'
   *  Delay: '<S21>/Delay1'
   *  Product: '<S21>/Divide'
   *  Product: '<S28>/Product'
   *  Sum: '<S21>/Subtract'
   */
  Plant_DW.Delay1_DSTATE[0] += 1.0 / (rtb_SumofElements1 * Sum2_idx_0) *
    (rtb_Sum_hq[0] - Plant_DW.Delay_DSTATE_a[0]);

  /* Update for Delay: '<S21>/Delay' incorporates:
   *  DataTypeConversion: '<S21>/Data Type Conversion'
   */
  Plant_DW.Delay_DSTATE_a[0] = rtb_Sum_hq[0];

  /* Signum: '<S28>/Sign' */
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

  /* Switch: '<S28>/Switch' incorporates:
   *  Constant: '<S28>/Constant'
   */
  if (rtb_SumofElements1 == 0.0) {
    Sum2_idx_0 = 1.0;
  }

  /* Abs: '<S28>/Abs' */
  rtb_SumofElements1 = fabs(rtb_SumofElements);

  /* Saturate: '<S28>/Saturation' */
  if (rtb_SumofElements1 > 1.0E+8) {
    rtb_SumofElements1 = 1.0E+8;
  } else {
    if (rtb_SumofElements1 < 1.0E-6) {
      rtb_SumofElements1 = 1.0E-6;
    }
  }

  /* Sum: '<S21>/Add' incorporates:
   *  Abs: '<S28>/Abs'
   *  DataTypeConversion: '<S21>/Data Type Conversion'
   *  Delay: '<S21>/Delay'
   *  Delay: '<S21>/Delay1'
   *  Product: '<S21>/Divide'
   *  Product: '<S28>/Product'
   *  Sum: '<S21>/Subtract'
   */
  Plant_DW.Delay1_DSTATE[1] += 1.0 / (rtb_SumofElements1 * Sum2_idx_0) *
    (rtb_Sum_hq[1] - Plant_DW.Delay_DSTATE_a[1]);

  /* Update for Delay: '<S21>/Delay' incorporates:
   *  DataTypeConversion: '<S21>/Data Type Conversion'
   */
  Plant_DW.Delay_DSTATE_a[1] = rtb_Sum_hq[1];

  /* Sum: '<S21>/Add' incorporates:
   *  Abs: '<S28>/Abs'
   *  DataTypeConversion: '<S21>/Data Type Conversion'
   *  Delay: '<S21>/Delay'
   *  Delay: '<S21>/Delay1'
   *  Product: '<S21>/Divide'
   *  Sum: '<S21>/Subtract'
   */
  Plant_DW.Delay1_DSTATE[2] += -(rtb_Sum_hq[2] - Plant_DW.Delay_DSTATE_a[2]);

  /* Update for Delay: '<S21>/Delay' incorporates:
   *  DataTypeConversion: '<S21>/Data Type Conversion'
   */
  Plant_DW.Delay_DSTATE_a[2] = rtb_Sum_hq[2];

  /* BusAssignment: '<S2>/Bus Assignment1' incorporates:
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant2'
   *  Constant: '<S2>/Constant3'
   *  Delay: '<Root>/Delay'
   *  Delay: '<S19>/Delay'
   *  Delay: '<S21>/Delay1'
   */
  Plant_Y.Plant_States.lat = Plant_DW.Delay1_DSTATE[0];
  Plant_Y.Plant_States.lon = Plant_DW.Delay1_DSTATE[1];
  Plant_Y.Plant_States.alt = Plant_DW.Delay1_DSTATE[2];
  Plant_Y.Plant_States.lat_0 = 0.65673;
  Plant_Y.Plant_States.lon_0 = -2.1361;
  Plant_Y.Plant_States.alt_0 = 4.5;
  Plant_Y.Plant_States.timestamp = Plant_DW.Delay_DSTATE_c;

  /* Sum: '<S19>/Sum' incorporates:
   *  Constant: '<S19>/dt'
   *  Delay: '<S19>/Delay'
   */
  Plant_DW.Delay_DSTATE_c += PLANT_EXPORT.period;

  /* End of Outputs for SubSystem: '<Root>/Bus_Constructor' */

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_Model' */
  /* Outputs for Atomic SubSystem: '<S5>/Sensor_Barometer' */
  /* Saturate: '<S74>/Limit  altitude  to troposhere' incorporates:
   *  DataTypeConversion: '<S72>/Data Type Conversion'
   *  Delay: '<Root>/Delay'
   */
  if ((real32_T)Plant_Y.Plant_States.alt > 11000.0F) {
    rtb_Saturation1_idx_0 = 11000.0F;
  } else if ((real32_T)Plant_Y.Plant_States.alt < 0.0F) {
    rtb_Saturation1_idx_0 = 0.0F;
  } else {
    rtb_Saturation1_idx_0 = (real32_T)Plant_Y.Plant_States.alt;
  }

  /* End of Saturate: '<S74>/Limit  altitude  to troposhere' */

  /* Sum: '<S74>/Sum1' incorporates:
   *  Constant: '<S74>/Sea Level  Temperature'
   *  Gain: '<S74>/Lapse Rate'
   */
  Rotor_Delay_tmp_idx_0 = 288.15F - 0.0065F * rtb_Saturation1_idx_0;

  /* Sum: '<S74>/Sum' incorporates:
   *  Constant: '<S74>/Altitude of Troposphere'
   *  DataTypeConversion: '<S72>/Data Type Conversion'
   *  Delay: '<Root>/Delay'
   */
  Rotor_Delay_tmp_idx_1 = 11000.0F - (real32_T)Plant_Y.Plant_States.alt;

  /* Saturate: '<S74>/Limit  altitude  to Stratosphere' incorporates:
   *  Constant: '<S74>/Altitude of Troposphere'
   *  DataTypeConversion: '<S72>/Data Type Conversion'
   *  Delay: '<Root>/Delay'
   *  Sum: '<S74>/Sum'
   */
  if (11000.0F - (real32_T)Plant_Y.Plant_States.alt > 0.0F) {
    Rotor_Delay_tmp_idx_1 = 0.0F;
  } else {
    if (11000.0F - (real32_T)Plant_Y.Plant_States.alt < -9000.0F) {
      Rotor_Delay_tmp_idx_1 = -9000.0F;
    }
  }

  /* End of Saturate: '<S74>/Limit  altitude  to Stratosphere' */

  /* Product: '<S74>/Product2' incorporates:
   *  Constant: '<S74>/Constant'
   *  Gain: '<S74>/1//T0'
   *  Gain: '<S74>/P0'
   *  Gain: '<S74>/g//R'
   *  Math: '<S74>/(T//T0)^(g//LR) '
   *  Math: '<S74>/Stratosphere Model'
   *  Product: '<S74>/Product1'
   *
   * About '<S74>/Stratosphere Model':
   *  Operator: exp
   */
  Rotor_Delay_tmp_idx_2 = powf(0.00347041478F * Rotor_Delay_tmp_idx_0,
    5.25587559F) * 101325.0F * expf(1.0F / Rotor_Delay_tmp_idx_0 *
    (0.0341631919F * Rotor_Delay_tmp_idx_1));

  /* S-Function (sdsprandsrc2): '<S76>/Random Source' */
  RandSrc_GZ_R(&Rotor_Delay_tmp_idx_1, &Plant_ConstP.pooled14, 1,
               &Plant_ConstP.pooled24, 1, Plant_DW.RandomSource_STATE_DWORK_b, 1,
               1);

  /* BusAssignment: '<S71>/Bus Assignment' incorporates:
   *  Constant: '<S71>/Constant2'
   *  DataTypeConversion: '<S71>/Data Type Conversion1'
   *  Memory: '<S65>/Memory1'
   *  Saturate: '<S73>/Saturation'
   *  Sum: '<S71>/Sum1'
   *  Sum: '<S73>/Add'
   */
  rtb_BusAssignment_i.timestamp = Plant_DW.Memory1_PreviousInput;
  rtb_BusAssignment_i.pressure = Rotor_Delay_tmp_idx_2 + Rotor_Delay_tmp_idx_1;
  rtb_BusAssignment_i.temperature = (real32_T)(Rotor_Delay_tmp_idx_0 - 273.15);

  /* RateTransition: '<S71>/Rate Transition' */
  if (Plant_M->Timing.TaskCounters.TID[1] == 0) {
    Plant_B.RateTransition_m = rtb_BusAssignment_i;
  }

  /* End of RateTransition: '<S71>/Rate Transition' */
  /* End of Outputs for SubSystem: '<S5>/Sensor_Barometer' */

  /* Outputs for Atomic SubSystem: '<S5>/Sensor_GPS' */
  /* Trigonometry: '<S89>/Sin' incorporates:
   *  Delay: '<S82>/Delay'
   */
  rtb_SumofElements = sin(Plant_DW.Delay_DSTATE[0]);

  /* Math: '<S89>/Square1' */
  rtb_SumofElements *= rtb_SumofElements;

  /* Product: '<S89>/Multiply1' incorporates:
   *  Product: '<S89>/Multiply'
   */
  Sum2_idx_0 = Plant_ConstB.ff * rtb_SumofElements;

  /* Product: '<S89>/Divide' incorporates:
   *  Constant: '<S89>/Constant'
   *  Constant: '<S89>/R'
   *  Sqrt: '<S89>/Sqrt'
   *  Sum: '<S89>/Sum1'
   */
  rtb_SumofElements = 6.378137E+6 / sqrt(1.0 - Sum2_idx_0);

  /* S-Function (sdsprandsrc2): '<S85>/Random Source' */
  RandSrc_GZ_R(rtb_RandomSource, &Plant_ConstP.pooled14, 1,
               Plant_ConstP.RandomSource_VarianceRTP, 3,
               Plant_DW.RandomSource_STATE_DWORK_l, 3, 1);

  /* Sum: '<S83>/Sum2' incorporates:
   *  Constant: '<S89>/Constant1'
   *  Delay: '<S82>/Delay'
   *  Product: '<S86>/Divide2'
   *  Product: '<S89>/Multiply1'
   *  Product: '<S89>/Multiply2'
   *  Product: '<S89>/Product3'
   *  Sum: '<S89>/Sum2'
   *  Trigonometry: '<S89>/Cos'
   */
  Sum2_idx_0 = rtb_RandomSource[0] / (1.0 / (1.0 - Sum2_idx_0) *
    Plant_ConstB.Sum4 * rtb_SumofElements) + Plant_DW.Delay_DSTATE[0];
  rtb_SumofElements1 = rtb_RandomSource[1] / (rtb_SumofElements * cos
    (Plant_DW.Delay_DSTATE[0])) + Plant_DW.Delay_DSTATE[1];
  Sum2_idx_2 = rtb_RandomSource[2] / -1.0 + Plant_DW.Delay_DSTATE[2];

  /* S-Function (sdsprandsrc2): '<S85>/Random Source1' */
  RandSrc_GZ_R(rtb_RandomSource1, &Plant_ConstP.pooled14, 1,
               Plant_ConstP.RandomSource1_VarianceRTP, 3,
               Plant_DW.RandomSource1_STATE_DWORK, 3, 1);

  /* Sum: '<S83>/Sum1' incorporates:
   *  Delay: '<S82>/Delay1'
   */
  rtb_Add_la[0] = rtb_RandomSource1[0] + Plant_DW.Delay1_DSTATE_a[0];
  rtb_Add_la[1] = rtb_RandomSource1[1] + Plant_DW.Delay1_DSTATE_a[1];
  rtb_Add_la[2] = rtb_RandomSource1[2] + Plant_DW.Delay1_DSTATE_a[2];

  /* DiscreteFir: '<S88>/Discrete FIR Filter' */
  rtb_Sum_b[0] = rtb_Add_la[0] * 0.5F + Plant_DW.DiscreteFIRFilter_states_f[0] *
    0.5F;
  rtb_Sum_b[1] = rtb_Add_la[1] * 0.5F + Plant_DW.DiscreteFIRFilter_states_f[1] *
    0.5F;

  /* Gain: '<S77>/Gain6' incorporates:
   *  Math: '<S84>/Math Function'
   *  Product: '<S84>/Matrix Multiply'
   *  Sqrt: '<S84>/Sqrt'
   *  Switch: '<S84>/Switch'
   */
  rtb_SumofElements = fmod(floor(sqrtf(rtb_RandomSource[0] * rtb_RandomSource[0]
    + rtb_RandomSource[1] * rtb_RandomSource[1]) * 1000.0), 4.294967296E+9);

  /* Gain: '<S77>/Gain4' incorporates:
   *  DiscreteFir: '<S87>/Discrete FIR Filter'
   */
  rtb_Product1 = fmod(floor((Sum2_idx_2 * 0.5 +
    Plant_DW.DiscreteFIRFilter_states[2] * 0.5) * 1000.0), 4.294967296E+9);
  i = rtb_Product1 < 0.0 ? -(int32_T)(uint32_T)-rtb_Product1 : (int32_T)
    (uint32_T)rtb_Product1;

  /* Gain: '<S77>/Gain5' incorporates:
   *  Math: '<S84>/Math Function2'
   *  Product: '<S84>/Matrix Multiply2'
   *  Sqrt: '<S84>/Sqrt2'
   *  Switch: '<S84>/Switch1'
   */
  rtb_Product1 = fmod(floor(sqrtf(rtb_RandomSource[2] * rtb_RandomSource[2]) *
    1000.0), 4.294967296E+9);

  /* BusAssignment: '<S77>/Bus Assignment' incorporates:
   *  Constant: '<S77>/Constant10'
   *  Constant: '<S77>/Constant11'
   *  Constant: '<S77>/Constant12'
   *  Constant: '<S77>/Constant2'
   *  Constant: '<S77>/Constant3'
   *  Constant: '<S77>/Constant4'
   *  Constant: '<S77>/Constant5'
   *  Constant: '<S77>/Constant6'
   *  Constant: '<S77>/Constant7'
   *  Constant: '<S77>/Constant8'
   *  Constant: '<S77>/Constant9'
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

  /* Gain: '<S77>/Gain' incorporates:
   *  DiscreteFir: '<S87>/Discrete FIR Filter'
   *  Gain: '<S77>/Gain2'
   */
  rtb_Product1_tmp_idx_2 = fmod(floor((Sum2_idx_0 * 0.5 +
    Plant_DW.DiscreteFIRFilter_states[0] * 0.5) * 57.295779513082323 * 1.0E+7),
    4.294967296E+9);

  /* BusAssignment: '<S77>/Bus Assignment' incorporates:
   *  Gain: '<S77>/Gain'
   */
  rtb_BusAssignment_dk.lon = rtb_Product1_tmp_idx_2 < 0.0 ? -(int32_T)(uint32_T)
    -rtb_Product1_tmp_idx_2 : (int32_T)(uint32_T)rtb_Product1_tmp_idx_2;

  /* Gain: '<S77>/Gain1' incorporates:
   *  DiscreteFir: '<S87>/Discrete FIR Filter'
   *  Gain: '<S77>/Gain3'
   */
  rtb_Product1_tmp_idx_2 = fmod(floor((rtb_SumofElements1 * 0.5 +
    Plant_DW.DiscreteFIRFilter_states[1] * 0.5) * 57.295779513082323 * 1.0E+7),
    4.294967296E+9);

  /* BusAssignment: '<S77>/Bus Assignment' incorporates:
   *  Gain: '<S77>/Gain1'
   *  Gain: '<S77>/Gain5'
   *  Gain: '<S77>/Gain6'
   */
  rtb_BusAssignment_dk.lat = rtb_Product1_tmp_idx_2 < 0.0 ? -(int32_T)(uint32_T)
    -rtb_Product1_tmp_idx_2 : (int32_T)(uint32_T)rtb_Product1_tmp_idx_2;
  rtb_BusAssignment_dk.height = i;
  rtb_BusAssignment_dk.hMSL = i;
  rtb_BusAssignment_dk.hAcc = rtb_SumofElements < 0.0 ? (uint32_T)-(int32_T)
    (uint32_T)-rtb_SumofElements : (uint32_T)rtb_SumofElements;
  rtb_BusAssignment_dk.vAcc = rtb_Product1 < 0.0 ? (uint32_T)-(int32_T)(uint32_T)
    -rtb_Product1 : (uint32_T)rtb_Product1;

  /* Gain: '<S77>/Gain7' */
  rtb_Saturation1_idx_0 = fmodf(floorf(1000.0F * rtb_Sum_b[0]), 4.2949673E+9F);

  /* BusAssignment: '<S77>/Bus Assignment' incorporates:
   *  Gain: '<S77>/Gain7'
   */
  rtb_BusAssignment_dk.velN = rtb_Saturation1_idx_0 < 0.0F ? -(int32_T)(uint32_T)
    -rtb_Saturation1_idx_0 : (int32_T)(uint32_T)rtb_Saturation1_idx_0;

  /* Gain: '<S77>/Gain8' */
  rtb_Saturation1_idx_0 = fmodf(floorf(1000.0F * rtb_Sum_b[1]), 4.2949673E+9F);

  /* BusAssignment: '<S77>/Bus Assignment' incorporates:
   *  Gain: '<S77>/Gain8'
   */
  rtb_BusAssignment_dk.velE = rtb_Saturation1_idx_0 < 0.0F ? -(int32_T)(uint32_T)
    -rtb_Saturation1_idx_0 : (int32_T)(uint32_T)rtb_Saturation1_idx_0;

  /* Gain: '<S77>/Gain9' incorporates:
   *  DiscreteFir: '<S88>/Discrete FIR Filter'
   */
  rtb_Saturation1_idx_0 = fmodf(floorf((rtb_Add_la[2] * 0.5F +
    Plant_DW.DiscreteFIRFilter_states_f[2] * 0.5F) * 1000.0F), 4.2949673E+9F);

  /* BusAssignment: '<S77>/Bus Assignment' incorporates:
   *  Constant: '<S77>/Constant15'
   *  Gain: '<S77>/Gain11'
   *  Gain: '<S77>/Gain9'
   *  Math: '<S79>/Math Function'
   *  Math: '<S79>/Math Function1'
   *  Saturate: '<S79>/Saturation'
   *  Sqrt: '<S79>/Sqrt'
   *  Sum: '<S79>/Add'
   */
  rtb_BusAssignment_dk.velD = rtb_Saturation1_idx_0 < 0.0F ? -(int32_T)(uint32_T)
    -rtb_Saturation1_idx_0 : (int32_T)(uint32_T)rtb_Saturation1_idx_0;
  rtb_BusAssignment_dk.gSpeed = (int32_T)(uint32_T)fmodf(floorf(sqrtf(fmaxf
    (rtb_Sum_b[0] * rtb_Sum_b[0] + rtb_Sum_b[1] * rtb_Sum_b[1], 0.0F)) * 1000.0F),
    4.2949673E+9F);
  rtb_BusAssignment_dk.heading = 0;

  /* Gain: '<S77>/Gain10' incorporates:
   *  Math: '<S84>/Math Function1'
   *  Product: '<S84>/Matrix Multiply1'
   *  Sqrt: '<S84>/Sqrt1'
   *  Switch: '<S84>/Switch2'
   */
  rtb_SumofElements = fmod(floor(sqrtf((rtb_RandomSource1[0] *
    rtb_RandomSource1[0] + rtb_RandomSource1[1] * rtb_RandomSource1[1]) +
    rtb_RandomSource1[2] * rtb_RandomSource1[2]) * 1000.0), 4.294967296E+9);

  /* BusAssignment: '<S77>/Bus Assignment' incorporates:
   *  Constant: '<S77>/Constant14'
   *  Constant: '<S77>/Constant16'
   *  Constant: '<S77>/Constant17'
   *  Gain: '<S77>/Gain10'
   *  Memory: '<S65>/Memory1'
   */
  rtb_BusAssignment_dk.sAcc = rtb_SumofElements < 0.0 ? (uint32_T)-(int32_T)
    (uint32_T)-rtb_SumofElements : (uint32_T)rtb_SumofElements;
  rtb_BusAssignment_dk.headingAcc = 0U;
  rtb_BusAssignment_dk.pDOP = 0U;
  rtb_BusAssignment_dk.reserved2 = 0U;
  rtb_BusAssignment_dk.timestamp = Plant_DW.Memory1_PreviousInput;

  /* RateTransition: '<S77>/Rate Transition' */
  if (Plant_M->Timing.TaskCounters.TID[2] == 0) {
    Plant_B.RateTransition = rtb_BusAssignment_dk;
  }

  /* End of RateTransition: '<S77>/Rate Transition' */

  /* Update for Delay: '<S82>/Delay' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S82>/ConcatBufferAtVector ConcatenateIn1'
   */
  for (i = 0; i < 74; i++) {
    rtb_Saturation1_o_idx_1 = (i + 1) * 3;
    Plant_DW.Delay_DSTATE[i * 3] = Plant_DW.Delay_DSTATE[rtb_Saturation1_o_idx_1];
    Plant_DW.Delay_DSTATE[i * 3 + 1] =
      Plant_DW.Delay_DSTATE[rtb_Saturation1_o_idx_1 + 1];
    Plant_DW.Delay_DSTATE[i * 3 + 2] =
      Plant_DW.Delay_DSTATE[rtb_Saturation1_o_idx_1 + 2];
  }

  /* Update states */
  Plant_DW.Delay_DSTATE[222] = Plant_Y.Plant_States.lon;

  /* Update for DiscreteFir: '<S87>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states[0] = Sum2_idx_0;

  /* Update for Delay: '<S82>/Delay' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S82>/ConcatBufferAtVector ConcatenateIn2'
   */
  Plant_DW.Delay_DSTATE[223] = Plant_Y.Plant_States.lat;

  /* Update for DiscreteFir: '<S87>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states[1] = rtb_SumofElements1;

  /* Update for Delay: '<S82>/Delay' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S82>/ConcatBufferAtVector ConcatenateIn3'
   */
  Plant_DW.Delay_DSTATE[224] = Plant_Y.Plant_States.alt;

  /* Update for DiscreteFir: '<S87>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states[2] = Sum2_idx_2;

  /* Update for Delay: '<S82>/Delay1' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S82>/ConcatBufferAtVector Concatenate1In1'
   */
  for (i = 0; i < 49; i++) {
    rtb_Saturation1_o_idx_1 = (i + 1) * 3;
    Plant_DW.Delay1_DSTATE_a[i * 3] =
      Plant_DW.Delay1_DSTATE_a[rtb_Saturation1_o_idx_1];
    Plant_DW.Delay1_DSTATE_a[i * 3 + 1] =
      Plant_DW.Delay1_DSTATE_a[rtb_Saturation1_o_idx_1 + 1];
    Plant_DW.Delay1_DSTATE_a[i * 3 + 2] =
      Plant_DW.Delay1_DSTATE_a[rtb_Saturation1_o_idx_1 + 2];
  }

  /* Update states */
  Plant_DW.Delay1_DSTATE_a[147] = Plant_Y.Plant_States.vel_x_O;

  /* Update for DiscreteFir: '<S88>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states_f[0] = rtb_Add_la[0];

  /* Update for Delay: '<S82>/Delay1' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S82>/ConcatBufferAtVector Concatenate1In2'
   */
  Plant_DW.Delay1_DSTATE_a[148] = Plant_Y.Plant_States.vel_y_O;

  /* Update for DiscreteFir: '<S88>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states_f[1] = rtb_Add_la[1];

  /* Update for Delay: '<S82>/Delay1' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S82>/ConcatBufferAtVector Concatenate1In3'
   */
  Plant_DW.Delay1_DSTATE_a[149] = Plant_Y.Plant_States.vel_z_O;

  /* Update for DiscreteFir: '<S88>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states_f[2] = rtb_Add_la[2];

  /* End of Outputs for SubSystem: '<S5>/Sensor_GPS' */

  /* Outputs for Atomic SubSystem: '<S5>/Sensor_IMU' */
  /* Outputs for Atomic SubSystem: '<S94>/Vibration_Model' */
  /* Outputs for Atomic SubSystem: '<S105>/Vibration_Model' */
  /* Product: '<S111>/Divide2' incorporates:
   *  Constant: '<S111>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Product: '<S100>/Divide2'
   */
  Sum2_idx_0 = Plant_Y.Extended_States.prop_vel[0] / 1047.1975511965977;

  /* End of Outputs for SubSystem: '<S94>/Vibration_Model' */

  /* Math: '<S111>/u^2' */
  rtb_Product1 = Sum2_idx_0 * Sum2_idx_0;

  /* Product: '<S107>/Product2' incorporates:
   *  DiscreteIntegrator: '<S107>/Discrete-Time Integrator'
   *  Trigonometry: '<S107>/Trigonometric Function2'
   */
  rtb_SumofElements = arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[0]) *
    rtb_Product1;

  /* Math: '<S111>/u^2' incorporates:
   *  DiscreteIntegrator: '<S107>/Discrete-Time Integrator'
   *  Product: '<S107>/Product1'
   *  Trigonometry: '<S107>/Trigonometric Function1'
   */
  rtb_Product1_idx_0 = arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[0]) *
    rtb_Product1;

  /* Product: '<S111>/Divide2' incorporates:
   *  Constant: '<S111>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Product: '<S100>/Divide2'
   */
  rtb_SumofElements1 = Sum2_idx_0;

  /* Outputs for Atomic SubSystem: '<S94>/Vibration_Model' */
  Sum2_idx_0 = Plant_Y.Extended_States.prop_vel[1] / 1047.1975511965977;

  /* End of Outputs for SubSystem: '<S94>/Vibration_Model' */

  /* Math: '<S111>/u^2' */
  rtb_Product1 = Sum2_idx_0 * Sum2_idx_0;

  /* Product: '<S107>/Product2' incorporates:
   *  DiscreteIntegrator: '<S107>/Discrete-Time Integrator'
   *  Trigonometry: '<S107>/Trigonometric Function2'
   */
  rtb_Product2_g_idx_1 = arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[1]) *
    rtb_Product1;

  /* Math: '<S111>/u^2' incorporates:
   *  DiscreteIntegrator: '<S107>/Discrete-Time Integrator'
   *  Product: '<S107>/Product1'
   *  Trigonometry: '<S107>/Trigonometric Function1'
   */
  rtb_Product1_idx_1 = arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[1]) *
    rtb_Product1;

  /* Product: '<S111>/Divide2' incorporates:
   *  Constant: '<S111>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Product: '<S100>/Divide2'
   */
  Sum2_idx_2 = Sum2_idx_0;

  /* Outputs for Atomic SubSystem: '<S94>/Vibration_Model' */
  Sum2_idx_0 = Plant_Y.Extended_States.prop_vel[2] / 1047.1975511965977;

  /* End of Outputs for SubSystem: '<S94>/Vibration_Model' */

  /* Math: '<S111>/u^2' */
  rtb_Product1 = Sum2_idx_0 * Sum2_idx_0;

  /* Product: '<S111>/Divide2' incorporates:
   *  Constant: '<S111>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Product: '<S100>/Divide2'
   */
  rtb_Product1_tmp_idx_2 = Sum2_idx_0;

  /* Outputs for Atomic SubSystem: '<S94>/Vibration_Model' */
  Sum2_idx_0 = Plant_Y.Extended_States.prop_vel[3] / 1047.1975511965977;

  /* Math: '<S111>/u^2' incorporates:
   *  Math: '<S100>/u^2'
   */
  Sum2_idx_0 *= Sum2_idx_0;

  /* End of Outputs for SubSystem: '<S94>/Vibration_Model' */

  /* Sum: '<S107>/Sum of Elements' incorporates:
   *  DiscreteIntegrator: '<S107>/Discrete-Time Integrator'
   *  Math: '<S111>/u^2'
   *  Product: '<S107>/Product2'
   *  Trigonometry: '<S107>/Trigonometric Function2'
   */
  rtb_SumofElements = ((rtb_SumofElements + rtb_Product2_g_idx_1) + arm_sin_f32
                       (Plant_DW.DiscreteTimeIntegrator_DSTATE[2]) *
                       rtb_Product1) + arm_sin_f32
    (Plant_DW.DiscreteTimeIntegrator_DSTATE[3]) * Sum2_idx_0;

  /* Sum: '<S107>/Sum of Elements1' incorporates:
   *  DiscreteIntegrator: '<S107>/Discrete-Time Integrator'
   *  Math: '<S111>/u^2'
   *  Product: '<S107>/Product1'
   *  Trigonometry: '<S107>/Trigonometric Function1'
   */
  rtb_Product1 = ((rtb_Product1_idx_0 + rtb_Product1_idx_1) + arm_cos_f32
                  (Plant_DW.DiscreteTimeIntegrator_DSTATE[2]) * rtb_Product1) +
    arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[3]) * Sum2_idx_0;

  /* Outputs for Atomic SubSystem: '<S94>/Vibration_Model' */
  /* Update for DiscreteIntegrator: '<S107>/Discrete-Time Integrator' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S96>/Discrete-Time Integrator'
   */
  rtb_Saturation1_idx_1 = 0.002F * Plant_Y.Extended_States.prop_vel[0];

  /* End of Outputs for SubSystem: '<S94>/Vibration_Model' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE[0] += rtb_Saturation1_idx_1;

  /* End of Outputs for SubSystem: '<S105>/Vibration_Model' */
  /* End of Outputs for SubSystem: '<S5>/Sensor_IMU' */
  /* End of Outputs for SubSystem: '<Root>/Sensor_Model' */
  Rotor_Delay_tmp_idx_0 = rtb_Saturation1_idx_1;

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_Model' */
  /* Outputs for Atomic SubSystem: '<S5>/Sensor_IMU' */
  /* Outputs for Atomic SubSystem: '<S94>/Vibration_Model' */
  /* Outputs for Atomic SubSystem: '<S105>/Vibration_Model' */
  /* Update for DiscreteIntegrator: '<S107>/Discrete-Time Integrator' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S96>/Discrete-Time Integrator'
   */
  rtb_Saturation1_idx_1 = 0.002F * Plant_Y.Extended_States.prop_vel[1];

  /* End of Outputs for SubSystem: '<S94>/Vibration_Model' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE[1] += rtb_Saturation1_idx_1;

  /* End of Outputs for SubSystem: '<S105>/Vibration_Model' */
  /* End of Outputs for SubSystem: '<S5>/Sensor_IMU' */
  /* End of Outputs for SubSystem: '<Root>/Sensor_Model' */
  Rotor_Delay_tmp_idx_1 = rtb_Saturation1_idx_1;

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_Model' */
  /* Outputs for Atomic SubSystem: '<S5>/Sensor_IMU' */
  /* Outputs for Atomic SubSystem: '<S94>/Vibration_Model' */
  /* Outputs for Atomic SubSystem: '<S105>/Vibration_Model' */
  /* Update for DiscreteIntegrator: '<S107>/Discrete-Time Integrator' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S96>/Discrete-Time Integrator'
   */
  rtb_Saturation1_idx_1 = 0.002F * Plant_Y.Extended_States.prop_vel[2];

  /* End of Outputs for SubSystem: '<S94>/Vibration_Model' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE[2] += rtb_Saturation1_idx_1;

  /* End of Outputs for SubSystem: '<S105>/Vibration_Model' */
  /* End of Outputs for SubSystem: '<S5>/Sensor_IMU' */
  /* End of Outputs for SubSystem: '<Root>/Sensor_Model' */
  Rotor_Delay_tmp_idx_2 = rtb_Saturation1_idx_1;

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_Model' */
  /* Outputs for Atomic SubSystem: '<S5>/Sensor_IMU' */
  /* Outputs for Atomic SubSystem: '<S94>/Vibration_Model' */
  /* Outputs for Atomic SubSystem: '<S105>/Vibration_Model' */
  /* Update for DiscreteIntegrator: '<S107>/Discrete-Time Integrator' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S96>/Discrete-Time Integrator'
   */
  rtb_Saturation1_idx_1 = 0.002F * Plant_Y.Extended_States.prop_vel[3];

  /* End of Outputs for SubSystem: '<S94>/Vibration_Model' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE[3] += rtb_Saturation1_idx_1;

  /* Switch: '<S105>/Switch' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S107>/Gain2'
   *  Gain: '<S107>/Gain4'
   *  Product: '<S107>/Divide'
   *  SignalConversion: '<S109>/ConcatBufferAtVector ConcatenateIn1'
   *  SignalConversion: '<S109>/ConcatBufferAtVector ConcatenateIn2'
   *  SignalConversion: '<S109>/ConcatBufferAtVector ConcatenateIn3'
   *  Sum: '<S105>/Sum'
   *  Sum: '<S107>/Sum'
   *  Sum: '<S107>/Sum of Elements'
   *  Sum: '<S107>/Sum of Elements1'
   */
  rtb_Sum_b[0] = (real32_T)(rtb_SumofElements / 4.0 * 0.5 +
    Plant_Y.Plant_States.rot_x_B);
  rtb_Sum_b[1] = (real32_T)(rtb_Product1 / 4.0 * 0.5 +
    Plant_Y.Plant_States.rot_y_B);
  rtb_Saturation1_idx_0 = (real32_T)((rtb_SumofElements + rtb_Product1) * 0.5 /
    4.0 * 0.5 + Plant_Y.Plant_States.rot_z_B);

  /* End of Outputs for SubSystem: '<S105>/Vibration_Model' */

  /* Sum: '<S113>/Sum' incorporates:
   *  Product: '<S113>/Product'
   */
  for (i = 0; i < 3; i++) {
    rtb_RandomSource[i] = (Plant_ConstB.Add_g[i + 3] * rtb_Sum_b[1] +
      Plant_ConstB.Add_g[i] * rtb_Sum_b[0]) + Plant_ConstB.Add_g[i + 6] *
      rtb_Saturation1_idx_0;
  }

  /* End of Sum: '<S113>/Sum' */

  /* DiscreteIntegrator: '<S112>/Discrete-Time Integrator5' */
  if (Plant_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[0] = rtb_RandomSource[0];
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[1] = rtb_RandomSource[1];
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[2] = rtb_RandomSource[2];
  }

  /* S-Function (sdsprandsrc2): '<S103>/Random Source' */
  RandSrc_GZ_R(rtb_RandomSource_f, &Plant_ConstP.pooled14, 1,
               Plant_ConstP.RandomSource_VarianceRTP_f, 3,
               Plant_DW.RandomSource_STATE_DWORK_k, 3, 1);

  /* S-Function (sdsprandsrc2): '<S114>/Random Source' */
  RandSrc_GZ_R(rtb_Sum_d, &Plant_ConstP.pooled14, 1,
               Plant_ConstP.RandomSource_VarianceRTP_b, 3,
               Plant_DW.RandomSource_STATE_DWORK_h, 3, 1);

  /* Saturate: '<S106>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S112>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[0] > 34.9065857F) {
    rtb_Saturation1_idx_0 = 34.9065857F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[0] < -34.9065857F) {
    rtb_Saturation1_idx_0 = -34.9065857F;
  } else {
    rtb_Saturation1_idx_0 = Plant_DW.DiscreteTimeIntegrator5_DSTATE[0];
  }

  /* Sum: '<S106>/Sum' */
  rtb_Add_la[0] = rtb_Saturation1_idx_0 + rtb_Sum_d[0];

  /* Saturate: '<S106>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S112>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[1] > 34.9065857F) {
    rtb_Saturation1_idx_0 = 34.9065857F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[1] < -34.9065857F) {
    rtb_Saturation1_idx_0 = -34.9065857F;
  } else {
    rtb_Saturation1_idx_0 = Plant_DW.DiscreteTimeIntegrator5_DSTATE[1];
  }

  /* Sum: '<S106>/Sum' */
  rtb_Add_la[1] = rtb_Saturation1_idx_0 + rtb_Sum_d[1];

  /* Saturate: '<S106>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S112>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[2] > 34.9065857F) {
    rtb_Saturation1_idx_0 = 34.9065857F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[2] < -34.9065857F) {
    rtb_Saturation1_idx_0 = -34.9065857F;
  } else {
    rtb_Saturation1_idx_0 = Plant_DW.DiscreteTimeIntegrator5_DSTATE[2];
  }

  /* Sum: '<S106>/Sum' */
  rtb_Add_la[2] = rtb_Saturation1_idx_0 + rtb_Sum_d[2];

  /* Outputs for Atomic SubSystem: '<S94>/Vibration_Model' */
  /* Math: '<S100>/u^2' incorporates:
   *  Product: '<S100>/Divide2'
   */
  rtb_Product1 = rtb_SumofElements1 * rtb_SumofElements1;

  /* Product: '<S96>/Product2' incorporates:
   *  DiscreteIntegrator: '<S96>/Discrete-Time Integrator'
   *  Trigonometry: '<S96>/Trigonometric Function2'
   */
  rtb_SumofElements = arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_p[0]) *
    rtb_Product1;

  /* Math: '<S100>/u^2' incorporates:
   *  DiscreteIntegrator: '<S96>/Discrete-Time Integrator'
   *  Product: '<S100>/Divide2'
   *  Product: '<S96>/Product1'
   *  Trigonometry: '<S96>/Trigonometric Function1'
   */
  rtb_Product1_idx_0 = arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_p[0]) *
    rtb_Product1;
  rtb_Product1 = Sum2_idx_2 * Sum2_idx_2;

  /* Product: '<S96>/Product2' incorporates:
   *  DiscreteIntegrator: '<S96>/Discrete-Time Integrator'
   *  Trigonometry: '<S96>/Trigonometric Function2'
   */
  rtb_Product2_g_idx_1 = arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_p[1])
    * rtb_Product1;

  /* Math: '<S100>/u^2' incorporates:
   *  DiscreteIntegrator: '<S96>/Discrete-Time Integrator'
   *  Product: '<S100>/Divide2'
   *  Product: '<S96>/Product1'
   *  Trigonometry: '<S96>/Trigonometric Function1'
   */
  rtb_Product1_idx_1 = arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_p[1]) *
    rtb_Product1;
  rtb_Product1 = rtb_Product1_tmp_idx_2 * rtb_Product1_tmp_idx_2;

  /* Sum: '<S96>/Sum of Elements' incorporates:
   *  DiscreteIntegrator: '<S96>/Discrete-Time Integrator'
   *  Product: '<S96>/Product2'
   *  Trigonometry: '<S96>/Trigonometric Function2'
   */
  rtb_SumofElements = ((rtb_SumofElements + rtb_Product2_g_idx_1) + arm_sin_f32
                       (Plant_DW.DiscreteTimeIntegrator_DSTATE_p[2]) *
                       rtb_Product1) + arm_sin_f32
    (Plant_DW.DiscreteTimeIntegrator_DSTATE_p[3]) * Sum2_idx_0;

  /* SignalConversion: '<S96>/ConcatBufferAtVector ConcatenateIn1' incorporates:
   *  Sum: '<S96>/Sum of Elements'
   */
  rtb_Divide2[0] = rtb_SumofElements;

  /* Sum: '<S96>/Sum of Elements1' incorporates:
   *  DiscreteIntegrator: '<S96>/Discrete-Time Integrator'
   *  Product: '<S96>/Product1'
   *  Trigonometry: '<S96>/Trigonometric Function1'
   */
  rtb_Product1 = ((rtb_Product1_idx_0 + rtb_Product1_idx_1) + arm_cos_f32
                  (Plant_DW.DiscreteTimeIntegrator_DSTATE_p[2]) * rtb_Product1)
    + arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_p[3]) * Sum2_idx_0;

  /* SignalConversion: '<S96>/ConcatBufferAtVector ConcatenateIn2' incorporates:
   *  Sum: '<S96>/Sum of Elements1'
   */
  rtb_Divide2[1] = rtb_Product1;

  /* Gain: '<S96>/Gain2' incorporates:
   *  Sum: '<S96>/Sum'
   *  Sum: '<S96>/Sum of Elements'
   *  Sum: '<S96>/Sum of Elements1'
   */
  rtb_Divide2[2] = (rtb_SumofElements + rtb_Product1) * 0.5;

  /* Update for DiscreteIntegrator: '<S96>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_p[0] += Rotor_Delay_tmp_idx_0;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_p[1] += Rotor_Delay_tmp_idx_1;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_p[2] += Rotor_Delay_tmp_idx_2;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_p[3] += rtb_Saturation1_idx_1;

  /* End of Outputs for SubSystem: '<S94>/Vibration_Model' */

  /* Switch: '<S94>/Switch' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S96>/Gain4'
   *  Product: '<S96>/Divide'
   *  Product: '<S98>/Product1'
   *  SignalConversion: '<S98>/ConcatBufferAtVector Concatenate1In1'
   *  SignalConversion: '<S98>/ConcatBufferAtVector Concatenate1In2'
   *  SignalConversion: '<S98>/ConcatBufferAtVector Concatenate1In3'
   *  Sum: '<S94>/Sum'
   *  Sum: '<S98>/Sum'
   */
  for (i = 0; i < 3; i++) {
    /* Outputs for Atomic SubSystem: '<S94>/Vibration_Model' */
    rtb_Sum_d[i] = (real32_T)(((Plant_Y.Extended_States.M_BO[i + 3] *
      Plant_Y.Plant_States.acc_y_O + Plant_Y.Extended_States.M_BO[i] *
      Plant_Y.Plant_States.acc_x_O) + Plant_Y.Extended_States.M_BO[i + 6] *
      (Plant_Y.Plant_States.acc_z_O - 9.80665F)) + rtb_Divide2[i] / 4.0 *
      Plant_ConstP.Gain4_Gain[i]);

    /* End of Outputs for SubSystem: '<S94>/Vibration_Model' */
  }

  /* End of Switch: '<S94>/Switch' */

  /* Sum: '<S102>/Sum' incorporates:
   *  Product: '<S102>/Product'
   */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate1_d[i] = (Plant_ConstB.Add_m[i + 3] * rtb_Sum_d[1] +
      Plant_ConstB.Add_m[i] * rtb_Sum_d[0]) + Plant_ConstB.Add_m[i + 6] *
      rtb_Sum_d[2];
  }

  /* End of Sum: '<S102>/Sum' */

  /* DiscreteIntegrator: '<S101>/Discrete-Time Integrator5' */
  if (Plant_DW.DiscreteTimeIntegrator5_IC_LO_j != 0) {
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[0] = rtb_VectorConcatenate1_d[0];
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[1] = rtb_VectorConcatenate1_d[1];
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[2] = rtb_VectorConcatenate1_d[2];
  }

  /* Outport: '<Root>/IMU' incorporates:
   *  BusAssignment: '<S91>/Bus Assignment'
   *  Memory: '<S65>/Memory1'
   */
  Plant_Y.IMU.timestamp = Plant_DW.Memory1_PreviousInput;
  Plant_Y.IMU.gyr_x = rtb_Add_la[0];
  Plant_Y.IMU.gyr_y = rtb_Add_la[1];
  Plant_Y.IMU.gyr_z = rtb_Add_la[2];

  /* Update for DiscreteIntegrator: '<S112>/Discrete-Time Integrator5' */
  Plant_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;

  /* Update for DiscreteIntegrator: '<S101>/Discrete-Time Integrator5' */
  Plant_DW.DiscreteTimeIntegrator5_IC_LO_j = 0U;

  /* End of Outputs for SubSystem: '<S5>/Sensor_IMU' */

  /* Outputs for Atomic SubSystem: '<S5>/Sensor_MAG' */
  /* Gain: '<S120>/rad_to_index' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S120>/TmpSignal ConversionAtrad_to_indexInport1'
   */
  rtb_SumofElements = fmod(floor(5.7295779513082321 * Plant_Y.Plant_States.lat),
    4.294967296E+9);

  /* Sum: '<S120>/Add' incorporates:
   *  Gain: '<S120>/rad_to_index'
   */
  i = (rtb_SumofElements < 0.0 ? -(int32_T)(uint32_T)-rtb_SumofElements :
       (int32_T)(uint32_T)rtb_SumofElements) + 8;

  /* Saturate: '<S120>/Saturation1' */
  if (i > 16) {
    i = 16;
  } else {
    if (i < 0) {
      i = 0;
    }
  }

  /* Gain: '<S120>/rad_to_index' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S120>/TmpSignal ConversionAtrad_to_indexInport1'
   */
  rtb_SumofElements = fmod(floor(5.7295779513082321 * Plant_Y.Plant_States.lon),
    4.294967296E+9);

  /* Sum: '<S120>/Add' incorporates:
   *  Gain: '<S120>/rad_to_index'
   */
  rtb_Saturation1_o_idx_1 = (rtb_SumofElements < 0.0 ? -(int32_T)(uint32_T)
    -rtb_SumofElements : (int32_T)(uint32_T)rtb_SumofElements) + 18;

  /* Saturate: '<S120>/Saturation1' */
  if (rtb_Saturation1_o_idx_1 > 36) {
    rtb_Saturation1_o_idx_1 = 36;
  } else {
    if (rtb_Saturation1_o_idx_1 < 0) {
      rtb_Saturation1_o_idx_1 = 0;
    }
  }

  /* LookupNDDirect: '<S120>/Declination_Lookup_Table' incorporates:
   *  LookupNDDirect: '<S120>/Inclination_Lookup_Table'
   *  LookupNDDirect: '<S120>/Magnitude_Lookup_Table'
   *
   * About '<S120>/Declination_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   *
   * About '<S120>/Inclination_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   *
   * About '<S120>/Magnitude_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  i += rtb_Saturation1_o_idx_1 * 17;

  /* Gain: '<S121>/Gain1' incorporates:
   *  LookupNDDirect: '<S120>/Declination_Lookup_Table'
   *
   * About '<S120>/Declination_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  Rotor_Delay_tmp_idx_0 = Plant_ConstP.Declination_Lookup_Table_table[i] *
    0.0174532924F;

  /* Trigonometry: '<S123>/Trigonometric Function1' incorporates:
   *  Trigonometry: '<S123>/Trigonometric Function3'
   */
  rtb_Switch1 = arm_cos_f32(Rotor_Delay_tmp_idx_0);
  rtb_VectorConcatenate_f[0] = rtb_Switch1;

  /* Trigonometry: '<S123>/Trigonometric Function' incorporates:
   *  Trigonometry: '<S123>/Trigonometric Function2'
   */
  rtb_omega_B_radPs_idx_1 = arm_sin_f32(Rotor_Delay_tmp_idx_0);
  rtb_VectorConcatenate_f[1] = rtb_omega_B_radPs_idx_1;

  /* SignalConversion: '<S123>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S123>/Constant3'
   */
  rtb_VectorConcatenate_f[2] = 0.0F;

  /* Gain: '<S123>/Gain' */
  rtb_VectorConcatenate_f[3] = -rtb_omega_B_radPs_idx_1;

  /* Trigonometry: '<S123>/Trigonometric Function3' */
  rtb_VectorConcatenate_f[4] = rtb_Switch1;

  /* SignalConversion: '<S123>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S123>/Constant4'
   */
  rtb_VectorConcatenate_f[5] = 0.0F;

  /* Gain: '<S121>/Gain' incorporates:
   *  LookupNDDirect: '<S120>/Inclination_Lookup_Table'
   *
   * About '<S120>/Inclination_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  Rotor_Delay_tmp_idx_0 = Plant_ConstP.Inclination_Lookup_Table_table[i] *
    -0.0174532924F;

  /* Trigonometry: '<S122>/Trigonometric Function3' incorporates:
   *  Trigonometry: '<S122>/Trigonometric Function1'
   */
  rtb_Saturation1_idx_0 = arm_cos_f32(Rotor_Delay_tmp_idx_0);
  rtb_VectorConcatenate_k[0] = rtb_Saturation1_idx_0;

  /* SignalConversion: '<S122>/ConcatBufferAtVector Concatenate2In2' incorporates:
   *  Constant: '<S122>/Constant4'
   */
  rtb_VectorConcatenate_k[1] = 0.0F;

  /* Trigonometry: '<S122>/Trigonometric Function2' incorporates:
   *  Trigonometry: '<S122>/Trigonometric Function'
   */
  rtb_Saturation1_idx_1 = arm_sin_f32(Rotor_Delay_tmp_idx_0);

  /* Gain: '<S122>/Gain' incorporates:
   *  Trigonometry: '<S122>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_k[2] = -rtb_Saturation1_idx_1;

  /* End of Outputs for SubSystem: '<S5>/Sensor_MAG' */

  /* Outputs for Atomic SubSystem: '<S5>/Sensor_IMU' */
  /* Saturate: '<S95>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[0] > 78.4532F) {
    Rotor_Delay_tmp_idx_0 = 78.4532F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[0] < -78.4532F) {
    Rotor_Delay_tmp_idx_0 = -78.4532F;
  } else {
    Rotor_Delay_tmp_idx_0 = Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[0];
  }

  /* Update for DiscreteIntegrator: '<S112>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S112>/Gain'
   *  Sum: '<S112>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTATE[0] += (rtb_RandomSource[0] -
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 314.159271F * 0.002F;

  /* Update for DiscreteIntegrator: '<S101>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S101>/Gain'
   *  Sum: '<S101>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[0] += (rtb_VectorConcatenate1_d[0] -
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[0]) * 314.159271F * 0.002F;

  /* End of Outputs for SubSystem: '<S5>/Sensor_IMU' */

  /* Outputs for Atomic SubSystem: '<S5>/Sensor_MAG' */
  /* SignalConversion: '<S123>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_f[6] = Plant_ConstB.VectorConcatenate3[0];

  /* SignalConversion: '<S122>/ConcatBufferAtVector ConcatenateIn2' */
  rtb_VectorConcatenate_k[3] = Plant_ConstB.VectorConcatenate3_a[0];

  /* End of Outputs for SubSystem: '<S5>/Sensor_MAG' */

  /* Outputs for Atomic SubSystem: '<S5>/Sensor_IMU' */
  /* Saturate: '<S95>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[1] > 78.4532F) {
    Rotor_Delay_tmp_idx_1 = 78.4532F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[1] < -78.4532F) {
    Rotor_Delay_tmp_idx_1 = -78.4532F;
  } else {
    Rotor_Delay_tmp_idx_1 = Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[1];
  }

  /* Update for DiscreteIntegrator: '<S112>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S112>/Gain'
   *  Sum: '<S112>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTATE[1] += (rtb_RandomSource[1] -
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 314.159271F * 0.002F;

  /* Update for DiscreteIntegrator: '<S101>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S101>/Gain'
   *  Sum: '<S101>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[1] += (rtb_VectorConcatenate1_d[1] -
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[1]) * 314.159271F * 0.002F;

  /* End of Outputs for SubSystem: '<S5>/Sensor_IMU' */

  /* Outputs for Atomic SubSystem: '<S5>/Sensor_MAG' */
  /* SignalConversion: '<S123>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_f[7] = Plant_ConstB.VectorConcatenate3[1];

  /* SignalConversion: '<S122>/ConcatBufferAtVector ConcatenateIn2' */
  rtb_VectorConcatenate_k[4] = Plant_ConstB.VectorConcatenate3_a[1];

  /* End of Outputs for SubSystem: '<S5>/Sensor_MAG' */

  /* Outputs for Atomic SubSystem: '<S5>/Sensor_IMU' */
  /* Saturate: '<S95>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S101>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[2] > 78.4532F) {
    Rotor_Delay_tmp_idx_2 = 78.4532F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[2] < -78.4532F) {
    Rotor_Delay_tmp_idx_2 = -78.4532F;
  } else {
    Rotor_Delay_tmp_idx_2 = Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[2];
  }

  /* Update for DiscreteIntegrator: '<S112>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S112>/Gain'
   *  Sum: '<S112>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTATE[2] += (rtb_RandomSource[2] -
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 314.159271F * 0.002F;

  /* Update for DiscreteIntegrator: '<S101>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S101>/Gain'
   *  Sum: '<S101>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[2] += (rtb_VectorConcatenate1_d[2] -
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[2]) * 314.159271F * 0.002F;

  /* End of Outputs for SubSystem: '<S5>/Sensor_IMU' */

  /* Outputs for Atomic SubSystem: '<S5>/Sensor_MAG' */
  /* SignalConversion: '<S123>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_f[8] = Plant_ConstB.VectorConcatenate3[2];

  /* SignalConversion: '<S122>/ConcatBufferAtVector ConcatenateIn2' */
  rtb_VectorConcatenate_k[5] = Plant_ConstB.VectorConcatenate3_a[2];

  /* Trigonometry: '<S122>/Trigonometric Function' */
  rtb_VectorConcatenate_k[6] = rtb_Saturation1_idx_1;

  /* SignalConversion: '<S122>/ConcatBufferAtVector Concatenate1In2' incorporates:
   *  Constant: '<S122>/Constant3'
   */
  rtb_VectorConcatenate_k[7] = 0.0F;

  /* Trigonometry: '<S122>/Trigonometric Function1' */
  rtb_VectorConcatenate_k[8] = rtb_Saturation1_idx_0;

  /* Gain: '<S121>/toGauss' incorporates:
   *  LookupNDDirect: '<S120>/Magnitude_Lookup_Table'
   *
   * About '<S120>/Magnitude_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  rtb_Saturation1_idx_0 = Plant_ConstP.Magnitude_Lookup_Table_table[i] * 0.01F;

  /* Product: '<S121>/Multiply1' incorporates:
   *  Product: '<S121>/Multiply'
   */
  for (i = 0; i < 3; i++) {
    rtb_Add1_c[i] = rtb_VectorConcatenate_k[i] * rtb_Saturation1_idx_0;
  }

  /* End of Product: '<S121>/Multiply1' */

  /* Product: '<S121>/Multiply2' */
  for (i = 0; i < 3; i++) {
    rtb_VectorConcatenate_l[i] = rtb_VectorConcatenate_f[i + 6] * rtb_Add1_c[2]
      + (rtb_VectorConcatenate_f[i + 3] * rtb_Add1_c[1] +
         rtb_VectorConcatenate_f[i] * rtb_Add1_c[0]);
  }

  /* End of Product: '<S121>/Multiply2' */

  /* Product: '<S118>/Product' incorporates:
   *  Delay: '<Root>/Delay'
   */
  for (i = 0; i < 3; i++) {
    rtb_Sum_b[i] = Plant_Y.Extended_States.M_BO[i + 6] *
      rtb_VectorConcatenate_l[2] + (Plant_Y.Extended_States.M_BO[i + 3] *
      rtb_VectorConcatenate_l[1] + Plant_Y.Extended_States.M_BO[i] *
      rtb_VectorConcatenate_l[0]);
  }

  /* End of Product: '<S118>/Product' */
  for (i = 0; i < 3; i++) {
    /* Sum: '<S124>/Sum' incorporates:
     *  Product: '<S124>/Product'
     */
    rtb_Saturation1_idx_0 = (Plant_ConstB.Add[i + 3] * rtb_Sum_b[1] +
      Plant_ConstB.Add[i] * rtb_Sum_b[0]) + Plant_ConstB.Add[i + 6] * rtb_Sum_b
      [2];

    /* Saturate: '<S119>/Saturation' incorporates:
     *  Sum: '<S124>/Sum'
     */
    if (rtb_Saturation1_idx_0 > 4.0F) {
      rtb_Add_la[i] = 4.0F;
    } else if (rtb_Saturation1_idx_0 < -4.0F) {
      rtb_Add_la[i] = -4.0F;
    } else {
      rtb_Add_la[i] = rtb_Saturation1_idx_0;
    }

    /* End of Saturate: '<S119>/Saturation' */
  }

  /* S-Function (sdsprandsrc2): '<S125>/Random Source' */
  RandSrc_GZ_R(rtb_Sum_b, &Plant_ConstP.pooled14, 1,
               Plant_ConstP.RandomSource_VarianceRTP_a, 3,
               Plant_DW.RandomSource_STATE_DWORK, 3, 1);

  /* Sum: '<S119>/Add' */
  rtb_Add_la[0] += rtb_Sum_b[0];
  rtb_Add_la[1] += rtb_Sum_b[1];

  /* BusAssignment: '<S115>/Bus Assignment' incorporates:
   *  Memory: '<S65>/Memory1'
   *  Sum: '<S119>/Add'
   */
  rtb_BusAssignment_o.timestamp = Plant_DW.Memory1_PreviousInput;
  rtb_BusAssignment_o.mag_x = rtb_Add_la[0];
  rtb_BusAssignment_o.mag_y = rtb_Add_la[1];
  rtb_BusAssignment_o.mag_z = rtb_Add_la[2] + rtb_Sum_b[2];

  /* RateTransition: '<S115>/Rate Transition' */
  if (Plant_M->Timing.TaskCounters.TID[1] == 0) {
    Plant_B.RateTransition_b = rtb_BusAssignment_o;
  }

  /* End of RateTransition: '<S115>/Rate Transition' */
  /* End of Outputs for SubSystem: '<S5>/Sensor_MAG' */

  /* Update for Memory: '<S65>/Memory1' incorporates:
   *  Constant: '<S65>/dt'
   *  Sum: '<S65>/Sum'
   */
  Plant_DW.Memory1_PreviousInput += PLANT_EXPORT.period;

  /* Outputs for Atomic SubSystem: '<S5>/Sensor_IMU' */
  /* Outport: '<Root>/IMU' incorporates:
   *  Sum: '<S95>/Sum'
   */
  Plant_Y.IMU.acc_x = Rotor_Delay_tmp_idx_0 + rtb_RandomSource_f[0];
  Plant_Y.IMU.acc_y = Rotor_Delay_tmp_idx_1 + rtb_RandomSource_f[1];
  Plant_Y.IMU.acc_z = Rotor_Delay_tmp_idx_2 + rtb_RandomSource_f[2];

  /* End of Outputs for SubSystem: '<S5>/Sensor_IMU' */
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
  Plant_U.Control_Out = Plant_rtZControl_Out_Bus;

  /* external outputs */
  (void) memset((void *)&Plant_Y, 0,
                sizeof(ExtY_Plant_T));

  {
    uint32_T RandomSource_SEED_DWORK_k;

    /* SystemInitialize for Atomic SubSystem: '<Root>/Kinematic_Equation' */
    /* InitializeConditions for DiscreteIntegrator: '<S44>/Discrete-Time Integrator' */
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[0] = Plant_ConstB.quat0[0];
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[1] = Plant_ConstB.quat0[1];
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[2] = Plant_ConstB.quat0[2];
    Plant_DW.DiscreteTimeIntegrator_DSTATE_d[3] = Plant_ConstB.quat0[3];
    Plant_DW.DiscreteTimeIntegrator_PrevRese = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S40>/Discrete-Time Integrator' */
    Plant_DW.DiscreteTimeIntegrator_PrevRe_d = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S41>/Discrete-Time Integrator' */
    Plant_DW.DiscreteTimeIntegrator_PrevRe_k = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S41>/Discrete-Time Integrator1' */
    Plant_DW.DiscreteTimeIntegrator1_PrevRes = 0;

    /* End of SystemInitialize for SubSystem: '<Root>/Kinematic_Equation' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Bus_Constructor' */
    /* InitializeConditions for Delay: '<S21>/Delay1' */
    Plant_DW.Delay1_DSTATE[0] = 0.65673;
    Plant_DW.Delay1_DSTATE[1] = -2.1361;
    Plant_DW.Delay1_DSTATE[2] = 4.5;

    /* End of SystemInitialize for SubSystem: '<Root>/Bus_Constructor' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Sensor_Model' */
    /* SystemInitialize for Atomic SubSystem: '<S5>/Sensor_Barometer' */
    /* InitializeConditions for S-Function (sdsprandsrc2): '<S76>/Random Source' */
    RandomSource_SEED_DWORK_k = 91337U;
    RandSrcInitState_GZ(&RandomSource_SEED_DWORK_k,
                        Plant_DW.RandomSource_STATE_DWORK_b, 1);

    /* End of SystemInitialize for SubSystem: '<S5>/Sensor_Barometer' */

    /* SystemInitialize for Atomic SubSystem: '<S5>/Sensor_GPS' */
    /* InitializeConditions for S-Function (sdsprandsrc2): '<S85>/Random Source' */
    RandSrcCreateSeeds_32(63235U, Plant_DW.RandomSource_SEED_DWORK_m, 3);
    RandSrcInitState_GZ(Plant_DW.RandomSource_SEED_DWORK_m,
                        Plant_DW.RandomSource_STATE_DWORK_l, 3);

    /* InitializeConditions for DiscreteFir: '<S87>/Discrete FIR Filter' */
    Plant_DW.DiscreteFIRFilter_states[0] = 0.0;
    Plant_DW.DiscreteFIRFilter_states[1] = 0.0;
    Plant_DW.DiscreteFIRFilter_states[2] = 0.0;

    /* InitializeConditions for S-Function (sdsprandsrc2): '<S85>/Random Source1' */
    RandSrcCreateSeeds_32(9754U, Plant_DW.RandomSource1_SEED_DWORK, 3);
    RandSrcInitState_GZ(Plant_DW.RandomSource1_SEED_DWORK,
                        Plant_DW.RandomSource1_STATE_DWORK, 3);

    /* InitializeConditions for DiscreteFir: '<S88>/Discrete FIR Filter' */
    Plant_DW.DiscreteFIRFilter_states_f[0] = 0.0F;
    Plant_DW.DiscreteFIRFilter_states_f[1] = 0.0F;
    Plant_DW.DiscreteFIRFilter_states_f[2] = 0.0F;

    /* End of SystemInitialize for SubSystem: '<S5>/Sensor_GPS' */

    /* SystemInitialize for Atomic SubSystem: '<S5>/Sensor_IMU' */
    /* InitializeConditions for DiscreteIntegrator: '<S112>/Discrete-Time Integrator5' */
    Plant_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

    /* InitializeConditions for S-Function (sdsprandsrc2): '<S103>/Random Source' */
    RandSrcCreateSeeds_32(90579U, Plant_DW.RandomSource_SEED_DWORK_f, 3);
    RandSrcInitState_GZ(Plant_DW.RandomSource_SEED_DWORK_f,
                        Plant_DW.RandomSource_STATE_DWORK_k, 3);

    /* InitializeConditions for S-Function (sdsprandsrc2): '<S114>/Random Source' */
    RandSrcCreateSeeds_32(81472U, Plant_DW.RandomSource_SEED_DWORK_n, 3);
    RandSrcInitState_GZ(Plant_DW.RandomSource_SEED_DWORK_n,
                        Plant_DW.RandomSource_STATE_DWORK_h, 3);

    /* InitializeConditions for DiscreteIntegrator: '<S101>/Discrete-Time Integrator5' */
    Plant_DW.DiscreteTimeIntegrator5_IC_LO_j = 1U;

    /* End of SystemInitialize for SubSystem: '<S5>/Sensor_IMU' */

    /* SystemInitialize for Atomic SubSystem: '<S5>/Sensor_MAG' */
    /* InitializeConditions for S-Function (sdsprandsrc2): '<S125>/Random Source' */
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
