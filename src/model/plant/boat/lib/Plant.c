/*
 * File: Plant.c
 *
 * Code generated for Simulink model 'Plant'.
 *
 * Model version                  : 1.1287
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Jun  6 14:12:08 2025
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
  0.6578,
  -2.1347,
  0.0
} ;                                    /* Variable: PLANT_PARAM
                                        * Referenced by:
                                        *   '<S2>/Constant1'
                                        *   '<S2>/Constant2'
                                        *   '<S2>/Constant3'
                                        *   '<S10>/Constant1'
                                        *   '<S10>/Constant2'
                                        *   '<S10>/Constant3'
                                        */

struct_AjtFzZRX3GJyUtRZj0A4oG PLANT_EXPORT = {
  2U,

  { 66, 111, 97, 116, 32, 118, 49, 46, 48, 46, 48, 0 }
} ;                                    /* Variable: PLANT_EXPORT
                                        * Referenced by:
                                        *   '<S8>/dt'
                                        *   '<S53>/dt'
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

  /* S-Function (sdsprandsrc2): '<S64>/Random Source' */
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

  /* End of S-Function (sdsprandsrc2): '<S64>/Random Source' */
}

void RandSrcInitState_GZ(const uint32_T seed[], uint32_T state[], int32_T nChans)
{
  int32_T i;
  int32_T tmp;

  /* InitializeConditions for S-Function (sdsprandsrc2): '<S64>/Random Source' */
  /* RandSrcInitState_GZ */
  for (i = 0; i < nChans; i++) {
    tmp = i << 1;
    state[tmp] = 362436069U;
    state[tmp + 1] = seed[i] == 0U ? 521288629U : seed[i];
  }

  /* End of InitializeConditions for S-Function (sdsprandsrc2): '<S64>/Random Source' */
}

void RandSrcInitState_U_32(const uint32_T seed[], real32_T state[], int32_T
  nChans)
{
  int32_T i;
  uint32_T j;
  int32_T k;
  int32_T n;
  real32_T d;

  /* InitializeConditions for S-Function (sdsprandsrc2): '<S73>/Random Source' */
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

  /* End of InitializeConditions for S-Function (sdsprandsrc2): '<S73>/Random Source' */
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

  /* InitializeConditions for S-Function (sdsprandsrc2): '<S73>/Random Source' */
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

  /* End of InitializeConditions for S-Function (sdsprandsrc2): '<S73>/Random Source' */
}

void RandSrcCreateSeeds_32(uint32_T initSeed, uint32_T seedArray[], int32_T
  numSeeds)
{
  real32_T state[35];
  real32_T tmp;
  real32_T min;
  real32_T max;
  int32_T i;

  /* InitializeConditions for S-Function (sdsprandsrc2): '<S73>/Random Source' */
  /* RandSrcCreateSeeds_32 */
  min = 0.0F;
  max = 1.0F;
  RandSrcInitState_U_32(&initSeed, state, 1);
  for (i = 0; i < numSeeds; i++) {
    RandSrc_U_R(&tmp, &min, 1, &max, 1, state, 1, 1);
    seedArray[i] = (uint32_T)(tmp * 2.14748365E+9F);
  }

  /* End of InitializeConditions for S-Function (sdsprandsrc2): '<S73>/Random Source' */
}

/* Model step function */
void Plant_step(void)
{
  real32_T rtb_Gain_g2;
  real32_T rtb_Square2;
  real32_T rtb_Product8;
  real32_T rtb_Sum_nh[3];
  real32_T rtb_Add_c;
  real32_T rtb_MathFunction1_c;
  real32_T rtb_Magnitude_Lookup_Table;
  boolean_T rtb_FixPtRelationalOperator;
  real32_T rtb_MatrixConcatenate4[16];
  real32_T rtb_Add_jo[3];
  real32_T rtb_Sum_b[3];
  boolean_T rtb_FixPtRelationalOperator_c;
  real32_T rtb_VectorConcatenate_f[9];
  real_T rtb_DataTypeConversion[3];
  real_T rtb_SumofElements;
  real_T rtb_SumofElements1;
  real32_T rtb_Sum_jo;
  real32_T rtb_Product2_e;
  Barometer_Bus rtb_BusAssignment_i;
  GPS_uBlox_Bus rtb_BusAssignment_dk;
  real32_T rtb_VectorConcatenate_k[9];
  MAG_Bus rtb_BusAssignment_o;
  real32_T rtb_RandomSource[3];
  real32_T rtb_act_force[3];
  real32_T rtb_RandomSource1[3];
  real32_T rtb_RandomSource_f[3];
  int32_T i;
  real32_T rtb_MatrixConcatenate4_0[4];
  real_T rtb_Product1;
  real32_T rtb_TrigonometricFunction1_idx_;
  real32_T rtb_TrigonometricFunction1_id_0;
  real32_T rtb_TrigonometricFunction1_id_1;
  real32_T rtb_TrigonometricFunction1_id_2;
  real_T rtb_Product1_idx_1;
  real_T rtb_Product1_idx_0;
  real_T rtb_Product2_g_idx_1;
  real_T rtb_Divide2_idx_1;
  real_T rtb_Divide2_idx_0;
  real_T rtb_Add_idx_1;
  real32_T rtb_DiscreteTimeIntegrator1_idx;
  real32_T rtb_Square_idx_1;
  real32_T rtb_vel_O_mPs_idx_2;
  real32_T rtb_vel_O_mPs_idx_1;
  real32_T rtb_vel_O_mPs_idx_0;
  real32_T rtb_Sum_n3_idx_2;
  real32_T rtb_torque_B_Nm_idx_2;
  real32_T rtb_force_B_N_idx_1;
  real32_T rtb_Sum_n3_idx_0;
  real32_T rtb_force_B_N_idx_0;
  real32_T rtb_omega_B_radPs_idx_2;
  real32_T rtb_omega_B_radPs_idx_1;
  real32_T rtb_omega_B_radPs_idx_0;
  int32_T rtb_Saturation1_idx_1;
  real32_T rtb_Divide_o_idx_0;
  real32_T rtb_Divide_o_idx_1;
  real32_T rtb_TrigonometricFunction1_id_3;
  real32_T rtb_Divide_o_idx_2;
  real32_T rtb_TrigonometricFunction1_id_4;
  real32_T rtb_Divide_o_idx_3;
  real32_T rtb_Gain_d_tmp;
  real32_T rtb_Gain_d_tmp_0;
  real32_T rtb_Gain_d_tmp_1;

  /* Outputs for Atomic SubSystem: '<Root>/Actuators' */
  /* Bias: '<S7>/Bias' incorporates:
   *  Gain: '<S7>/Gain'
   *  Inport: '<Root>/Control_Out'
   */
  rtb_Gain_g2 = 0.180000305F * (real32_T)Plant_U.Control_Out.actuator_cmd[1] +
    -270.0F;

  /* DeadZone: '<S7>/Dead Zone' */
  if (rtb_Gain_g2 > 2.0F) {
    rtb_Gain_g2 -= 2.0F;
  } else if (rtb_Gain_g2 >= -2.0F) {
    rtb_Gain_g2 = 0.0F;
  } else {
    rtb_Gain_g2 -= -2.0F;
  }

  /* End of DeadZone: '<S7>/Dead Zone' */

  /* Saturate: '<S7>/Saturation' */
  if (rtb_Gain_g2 > 90.0F) {
    rtb_Gain_g2 = 90.0F;
  } else {
    if (rtb_Gain_g2 < -90.0F) {
      rtb_Gain_g2 = -90.0F;
    }
  }

  /* End of Saturate: '<S7>/Saturation' */

  /* Gain: '<S7>/Deg2Rad' */
  rtb_Gain_g2 *= 0.0174532924F;

  /* Bias: '<S6>/Bias' incorporates:
   *  Gain: '<S6>/Gain'
   *  Inport: '<Root>/Control_Out'
   */
  rtb_Square2 = 0.0403995514F * (real32_T)Plant_U.Control_Out.actuator_cmd[0] +
    -60.6F;

  /* DeadZone: '<S6>/Dead Zone' */
  if (rtb_Square2 > 1.0F) {
    rtb_Square2--;
  } else if (rtb_Square2 >= -1.0F) {
    rtb_Square2 = 0.0F;
  } else {
    rtb_Square2++;
  }

  /* End of DeadZone: '<S6>/Dead Zone' */

  /* Product: '<S1>/Multiply' incorporates:
   *  Trigonometry: '<S1>/Cos'
   */
  rtb_Product8 = rtb_Square2 * arm_cos_f32(rtb_Gain_g2);

  /* Product: '<S1>/Multiply1' incorporates:
   *  Trigonometry: '<S1>/Cos1'
   */
  rtb_Square2 *= arm_sin_f32(rtb_Gain_g2);

  /* Reshape: '<S1>/Reshape' */
  rtb_act_force[1] = rtb_Square2;

  /* Gain: '<S1>/d' */
  rtb_Square2 *= 0.25F;

  /* Outputs for Atomic SubSystem: '<Root>/Environment' */
  /* Sum: '<S3>/Sum' incorporates:
   *  Abs: '<S20>/Abs2'
   *  Constant: '<S20>/Constant4'
   *  Delay: '<Root>/Delay'
   *  Product: '<S20>/Multiply6'
   *  Reshape: '<S1>/Reshape1'
   *  Sum: '<S20>/Sum2'
   */
  rtb_torque_B_Nm_idx_2 = (-4.0F - fabsf(Plant_Y.Plant_States.rot_z_B)) *
    Plant_Y.Plant_States.rot_z_B + rtb_Square2;

  /* End of Outputs for SubSystem: '<Root>/Actuators' */

  /* Product: '<S18>/Multiply' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S18>/TmpSignal ConversionAtMultiplyInport2'
   */
  for (i = 0; i < 3; i++) {
    rtb_Sum_nh[i] = Plant_Y.Extended_States.M_BO[i + 6] *
      Plant_Y.Plant_States.vel_z_O + (Plant_Y.Extended_States.M_BO[i + 3] *
      Plant_Y.Plant_States.vel_y_O + Plant_Y.Extended_States.M_BO[i] *
      Plant_Y.Plant_States.vel_x_O);
  }

  /* End of Product: '<S18>/Multiply' */

  /* Outputs for Atomic SubSystem: '<Root>/Actuators' */
  /* Sum: '<S3>/Sum1' incorporates:
   *  Abs: '<S19>/Abs'
   *  Abs: '<S19>/Abs1'
   *  Constant: '<S19>/Constant'
   *  Constant: '<S19>/Constant1'
   *  Constant: '<S19>/Constant2'
   *  Constant: '<S19>/Constant3'
   *  Delay: '<Root>/Delay'
   *  Gain: '<S19>/Gain'
   *  Gain: '<S19>/Gain1'
   *  Product: '<S19>/Multiply'
   *  Product: '<S19>/Multiply1'
   *  Product: '<S19>/Multiply2'
   *  Product: '<S19>/Multiply3'
   *  Product: '<S19>/Multiply4'
   *  Product: '<S19>/Multiply5'
   *  Reshape: '<S1>/Reshape'
   *  Sum: '<S19>/Sum'
   *  Sum: '<S19>/Sum1'
   *  Sum: '<S19>/Sum2'
   *  Sum: '<S19>/Sum3'
   */
  rtb_force_B_N_idx_0 = ((-1.0F - 0.5F * fabsf(rtb_Sum_nh[0])) * rtb_Sum_nh[0] -
    Plant_Y.Plant_States.rot_z_B * rtb_Sum_nh[1] * 3.4418F) + rtb_Product8;

  /* End of Outputs for SubSystem: '<Root>/Actuators' */
  rtb_force_B_N_idx_1 = ((-10.0F - 5.0F * fabsf(rtb_Sum_nh[1])) * rtb_Sum_nh[1]
    + Plant_Y.Plant_States.rot_z_B * rtb_Sum_nh[0] * 2.1512F) + rtb_act_force[1];

  /* End of Outputs for SubSystem: '<Root>/Environment' */

  /* Outputs for Atomic SubSystem: '<Root>/Kinematic_Equation' */
  /* Gain: '<S25>/Gain' incorporates:
   *  Inport: '<Root>/States_Init'
   */
  rtb_act_force[0] = 0.5F * Plant_U.States_Init.euler[0];
  rtb_act_force[1] = 0.5F * Plant_U.States_Init.euler[1];
  rtb_act_force[2] = 0.5F * Plant_U.States_Init.euler[2];

  /* Trigonometry: '<S25>/Cos' */
  rtb_Add_c = arm_cos_f32(rtb_act_force[0]);

  /* Trigonometry: '<S25>/Cos1' */
  rtb_MathFunction1_c = arm_cos_f32(rtb_act_force[1]);

  /* Trigonometry: '<S25>/Cos2' */
  rtb_Magnitude_Lookup_Table = arm_cos_f32(rtb_act_force[2]);

  /* Trigonometry: '<S25>/Sin' */
  rtb_Product8 = arm_sin_f32(rtb_act_force[0]);

  /* Trigonometry: '<S25>/Sin1' */
  rtb_Square2 = arm_sin_f32(rtb_act_force[1]);

  /* Trigonometry: '<S25>/Sin2' */
  rtb_Gain_g2 = arm_sin_f32(rtb_act_force[2]);

  /* Product: '<S25>/Multiply' incorporates:
   *  Product: '<S25>/Multiply6'
   */
  rtb_Product2_e = rtb_Add_c * rtb_MathFunction1_c;

  /* Product: '<S25>/Multiply1' incorporates:
   *  Product: '<S25>/Multiply7'
   */
  rtb_Square_idx_1 = rtb_Product8 * rtb_Square2;

  /* SignalConversion: '<S31>/TmpSignal ConversionAtSquareInport1' incorporates:
   *  Product: '<S25>/Multiply'
   *  Product: '<S25>/Multiply1'
   *  Sum: '<S25>/Add'
   */
  rtb_TrigonometricFunction1_id_2 = rtb_Product2_e * rtb_Magnitude_Lookup_Table
    + rtb_Square_idx_1 * rtb_Gain_g2;

  /* Product: '<S25>/Multiply3' incorporates:
   *  Product: '<S25>/Multiply4'
   */
  rtb_Add_c *= rtb_Square2;

  /* Product: '<S25>/Multiply2' incorporates:
   *  Product: '<S25>/Multiply5'
   */
  rtb_MathFunction1_c *= rtb_Product8;

  /* SignalConversion: '<S31>/TmpSignal ConversionAtSquareInport1' incorporates:
   *  Product: '<S25>/Multiply2'
   *  Product: '<S25>/Multiply3'
   *  Product: '<S25>/Multiply4'
   *  Product: '<S25>/Multiply5'
   *  Product: '<S25>/Multiply6'
   *  Product: '<S25>/Multiply7'
   *  Sum: '<S25>/Add1'
   *  Sum: '<S25>/Subtract'
   *  Sum: '<S25>/Subtract1'
   */
  rtb_TrigonometricFunction1_id_1 = rtb_MathFunction1_c *
    rtb_Magnitude_Lookup_Table - rtb_Add_c * rtb_Gain_g2;
  rtb_TrigonometricFunction1_id_0 = rtb_Add_c * rtb_Magnitude_Lookup_Table +
    rtb_MathFunction1_c * rtb_Gain_g2;
  rtb_TrigonometricFunction1_idx_ = rtb_Product2_e * rtb_Gain_g2 -
    rtb_Square_idx_1 * rtb_Magnitude_Lookup_Table;

  /* Sqrt: '<S31>/Sqrt' incorporates:
   *  Math: '<S31>/Square'
   *  Sum: '<S31>/Sum of Elements'
   */
  rtb_Gain_g2 = sqrtf(((rtb_TrigonometricFunction1_id_2 *
                        rtb_TrigonometricFunction1_id_2 +
                        rtb_TrigonometricFunction1_id_1 *
                        rtb_TrigonometricFunction1_id_1) +
                       rtb_TrigonometricFunction1_id_0 *
                       rtb_TrigonometricFunction1_id_0) +
                      rtb_TrigonometricFunction1_idx_ *
                      rtb_TrigonometricFunction1_idx_);

  /* Product: '<S30>/Divide' */
  rtb_Product2_e = rtb_TrigonometricFunction1_id_2 / rtb_Gain_g2;

  /* Math: '<S36>/Square' */
  rtb_Magnitude_Lookup_Table = rtb_Product2_e * rtb_Product2_e;

  /* Product: '<S30>/Divide' */
  rtb_TrigonometricFunction1_id_2 = rtb_Product2_e;
  rtb_Product2_e = rtb_TrigonometricFunction1_id_1 / rtb_Gain_g2;

  /* Math: '<S36>/Square' */
  rtb_Square_idx_1 = rtb_Product2_e * rtb_Product2_e;

  /* Product: '<S30>/Divide' */
  rtb_TrigonometricFunction1_id_1 = rtb_Product2_e;
  rtb_Product2_e = rtb_TrigonometricFunction1_id_0 / rtb_Gain_g2;

  /* Math: '<S36>/Square' */
  rtb_MathFunction1_c = rtb_Product2_e * rtb_Product2_e;

  /* Product: '<S30>/Divide' */
  rtb_TrigonometricFunction1_id_0 = rtb_Product2_e;
  rtb_Product2_e = rtb_TrigonometricFunction1_idx_ / rtb_Gain_g2;

  /* Sqrt: '<S36>/Sqrt' incorporates:
   *  Math: '<S36>/Square'
   *  Sum: '<S36>/Sum of Elements'
   */
  rtb_Gain_g2 = sqrtf(((rtb_Magnitude_Lookup_Table + rtb_Square_idx_1) +
                       rtb_MathFunction1_c) + rtb_Product2_e * rtb_Product2_e);

  /* Product: '<S34>/Divide' */
  rtb_TrigonometricFunction1_id_2 /= rtb_Gain_g2;
  rtb_TrigonometricFunction1_id_1 /= rtb_Gain_g2;
  rtb_TrigonometricFunction1_id_0 /= rtb_Gain_g2;
  rtb_Product2_e /= rtb_Gain_g2;

  /* RelationalOperator: '<S24>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/States_Init'
   *  UnitDelay: '<S24>/Delay Input1'
   *
   * Block description for '<S24>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_FixPtRelationalOperator = (Plant_U.States_Init.timestamp !=
    Plant_DW.DelayInput1_DSTATE);

  /* DiscreteIntegrator: '<S27>/Discrete-Time Integrator' */
  if (Plant_DW.DiscreteTimeIntegrator_IC_LOADI != 0) {
    Plant_DW.DiscreteTimeIntegrator_DSTAT_p4[0] =
      rtb_TrigonometricFunction1_id_2;
    Plant_DW.DiscreteTimeIntegrator_DSTAT_p4[1] =
      rtb_TrigonometricFunction1_id_1;
    Plant_DW.DiscreteTimeIntegrator_DSTAT_p4[2] =
      rtb_TrigonometricFunction1_id_0;
    Plant_DW.DiscreteTimeIntegrator_DSTAT_p4[3] = rtb_Product2_e;
  }

  if (rtb_FixPtRelationalOperator || (Plant_DW.DiscreteTimeIntegrator_PrevRese
       != 0)) {
    Plant_DW.DiscreteTimeIntegrator_DSTAT_p4[0] =
      rtb_TrigonometricFunction1_id_2;
    Plant_DW.DiscreteTimeIntegrator_DSTAT_p4[1] =
      rtb_TrigonometricFunction1_id_1;
    Plant_DW.DiscreteTimeIntegrator_DSTAT_p4[2] =
      rtb_TrigonometricFunction1_id_0;
    Plant_DW.DiscreteTimeIntegrator_DSTAT_p4[3] = rtb_Product2_e;
  }

  rtb_Magnitude_Lookup_Table = Plant_DW.DiscreteTimeIntegrator_DSTAT_p4[0];
  rtb_Square_idx_1 = Plant_DW.DiscreteTimeIntegrator_DSTAT_p4[1];
  rtb_MathFunction1_c = Plant_DW.DiscreteTimeIntegrator_DSTAT_p4[2];
  rtb_Product8 = Plant_DW.DiscreteTimeIntegrator_DSTAT_p4[3];

  /* SignalConversion: '<S35>/ConcatBufferAtMatrix ConcatenateIn1' incorporates:
   *  Constant: '<S35>/Constant'
   */
  rtb_MatrixConcatenate4[0] = 0.0F;

  /* DiscreteIntegrator: '<S21>/Discrete-Time Integrator' incorporates:
   *  Logic: '<S21>/Logical Operator'
   */
  if (rtb_FixPtRelationalOperator || (Plant_DW.DiscreteTimeIntegrator_PrevRe_c
       != 0)) {
    Plant_DW.DiscreteTimeIntegrator_DSTAT_p2[0] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator_DSTAT_p2[1] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator_DSTAT_p2[2] = 0.0F;
  }

  rtb_omega_B_radPs_idx_0 = Plant_DW.DiscreteTimeIntegrator_DSTAT_p2[0];
  rtb_omega_B_radPs_idx_1 = Plant_DW.DiscreteTimeIntegrator_DSTAT_p2[1];
  rtb_omega_B_radPs_idx_2 = Plant_DW.DiscreteTimeIntegrator_DSTAT_p2[2];

  /* SignalConversion: '<S35>/ConcatBufferAtMatrix ConcatenateIn2' incorporates:
   *  DiscreteIntegrator: '<S21>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[1] = Plant_DW.DiscreteTimeIntegrator_DSTAT_p2[0];

  /* SignalConversion: '<S35>/ConcatBufferAtMatrix ConcatenateIn3' incorporates:
   *  DiscreteIntegrator: '<S21>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[2] = Plant_DW.DiscreteTimeIntegrator_DSTAT_p2[1];

  /* SignalConversion: '<S35>/ConcatBufferAtMatrix ConcatenateIn4' incorporates:
   *  DiscreteIntegrator: '<S21>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[3] = Plant_DW.DiscreteTimeIntegrator_DSTAT_p2[2];

  /* Gain: '<S35>/Gain1' incorporates:
   *  DiscreteIntegrator: '<S21>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[4] = -Plant_DW.DiscreteTimeIntegrator_DSTAT_p2[0];

  /* SignalConversion: '<S35>/ConcatBufferAtMatrix Concatenate1In2' incorporates:
   *  Constant: '<S35>/Constant1'
   */
  rtb_MatrixConcatenate4[5] = 0.0F;

  /* Gain: '<S35>/Gain2' incorporates:
   *  DiscreteIntegrator: '<S21>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[6] = -Plant_DW.DiscreteTimeIntegrator_DSTAT_p2[2];

  /* SignalConversion: '<S35>/ConcatBufferAtMatrix Concatenate1In4' incorporates:
   *  DiscreteIntegrator: '<S21>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[7] = Plant_DW.DiscreteTimeIntegrator_DSTAT_p2[1];

  /* Gain: '<S35>/Gain3' incorporates:
   *  DiscreteIntegrator: '<S21>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[8] = -Plant_DW.DiscreteTimeIntegrator_DSTAT_p2[1];

  /* SignalConversion: '<S35>/ConcatBufferAtMatrix Concatenate2In2' incorporates:
   *  DiscreteIntegrator: '<S21>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[9] = Plant_DW.DiscreteTimeIntegrator_DSTAT_p2[2];

  /* SignalConversion: '<S35>/ConcatBufferAtMatrix Concatenate2In3' incorporates:
   *  Constant: '<S35>/Constant2'
   */
  rtb_MatrixConcatenate4[10] = 0.0F;

  /* Gain: '<S35>/Gain4' incorporates:
   *  DiscreteIntegrator: '<S21>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[11] = -Plant_DW.DiscreteTimeIntegrator_DSTAT_p2[0];

  /* Gain: '<S35>/Gain6' incorporates:
   *  DiscreteIntegrator: '<S21>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[12] = -Plant_DW.DiscreteTimeIntegrator_DSTAT_p2[2];

  /* Gain: '<S35>/Gain7' incorporates:
   *  DiscreteIntegrator: '<S21>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[13] = -Plant_DW.DiscreteTimeIntegrator_DSTAT_p2[1];

  /* SignalConversion: '<S35>/ConcatBufferAtMatrix Concatenate3In3' incorporates:
   *  DiscreteIntegrator: '<S21>/Discrete-Time Integrator'
   */
  rtb_MatrixConcatenate4[14] = Plant_DW.DiscreteTimeIntegrator_DSTAT_p2[0];

  /* SignalConversion: '<S35>/ConcatBufferAtMatrix Concatenate3In4' incorporates:
   *  Constant: '<S35>/Constant3'
   */
  rtb_MatrixConcatenate4[15] = 0.0F;

  /* Sqrt: '<S33>/Sqrt' incorporates:
   *  DiscreteIntegrator: '<S27>/Discrete-Time Integrator'
   *  Math: '<S33>/Square'
   *  Sqrt: '<S47>/Sqrt'
   *  Sqrt: '<S52>/Sqrt'
   *  Sum: '<S33>/Sum of Elements'
   */
  rtb_Sum_n3_idx_2 = sqrtf(((Plant_DW.DiscreteTimeIntegrator_DSTAT_p4[0] *
    Plant_DW.DiscreteTimeIntegrator_DSTAT_p4[0] +
    Plant_DW.DiscreteTimeIntegrator_DSTAT_p4[1] *
    Plant_DW.DiscreteTimeIntegrator_DSTAT_p4[1]) +
    Plant_DW.DiscreteTimeIntegrator_DSTAT_p4[2] *
    Plant_DW.DiscreteTimeIntegrator_DSTAT_p4[2]) +
    Plant_DW.DiscreteTimeIntegrator_DSTAT_p4[3] *
    Plant_DW.DiscreteTimeIntegrator_DSTAT_p4[3]);

  /* Product: '<S32>/Divide' incorporates:
   *  DiscreteIntegrator: '<S27>/Discrete-Time Integrator'
   *  Sqrt: '<S33>/Sqrt'
   */
  rtb_Product2_e = Plant_DW.DiscreteTimeIntegrator_DSTAT_p4[0] /
    rtb_Sum_n3_idx_2;
  rtb_Add_c = Plant_DW.DiscreteTimeIntegrator_DSTAT_p4[1] / rtb_Sum_n3_idx_2;
  rtb_TrigonometricFunction1_id_3 = Plant_DW.DiscreteTimeIntegrator_DSTAT_p4[2] /
    rtb_Sum_n3_idx_2;
  rtb_TrigonometricFunction1_id_4 = Plant_DW.DiscreteTimeIntegrator_DSTAT_p4[3] /
    rtb_Sum_n3_idx_2;

  /* Product: '<S43>/Divide' incorporates:
   *  DiscreteIntegrator: '<S27>/Discrete-Time Integrator'
   */
  rtb_Divide_o_idx_0 = Plant_DW.DiscreteTimeIntegrator_DSTAT_p4[0] /
    rtb_Sum_n3_idx_2;
  rtb_Divide_o_idx_1 = Plant_DW.DiscreteTimeIntegrator_DSTAT_p4[1] /
    rtb_Sum_n3_idx_2;
  rtb_Divide_o_idx_2 = Plant_DW.DiscreteTimeIntegrator_DSTAT_p4[2] /
    rtb_Sum_n3_idx_2;
  rtb_Divide_o_idx_3 = Plant_DW.DiscreteTimeIntegrator_DSTAT_p4[3] /
    rtb_Sum_n3_idx_2;

  /* Product: '<S48>/Divide' incorporates:
   *  DiscreteIntegrator: '<S27>/Discrete-Time Integrator'
   */
  rtb_TrigonometricFunction1_id_2 = Plant_DW.DiscreteTimeIntegrator_DSTAT_p4[0] /
    rtb_Sum_n3_idx_2;
  rtb_Square2 = Plant_DW.DiscreteTimeIntegrator_DSTAT_p4[1] / rtb_Sum_n3_idx_2;
  rtb_TrigonometricFunction1_id_1 = Plant_DW.DiscreteTimeIntegrator_DSTAT_p4[2] /
    rtb_Sum_n3_idx_2;
  rtb_TrigonometricFunction1_id_0 = Plant_DW.DiscreteTimeIntegrator_DSTAT_p4[3] /
    rtb_Sum_n3_idx_2;

  /* Product: '<S21>/Multiply' incorporates:
   *  Constant: '<S21>/Inertia_Matrix'
   *  DiscreteIntegrator: '<S21>/Discrete-Time Integrator'
   */
  for (i = 0; i < 3; i++) {
    rtb_Add_jo[i] = Plant_ConstP.Inertia_Matrix_Value[i + 6] *
      Plant_DW.DiscreteTimeIntegrator_DSTAT_p2[2] +
      (Plant_ConstP.Inertia_Matrix_Value[i + 3] *
       Plant_DW.DiscreteTimeIntegrator_DSTAT_p2[1] +
       Plant_ConstP.Inertia_Matrix_Value[i] *
       Plant_DW.DiscreteTimeIntegrator_DSTAT_p2[0]);
  }

  /* End of Product: '<S21>/Multiply' */

  /* Product: '<S28>/Multiply' incorporates:
   *  DiscreteIntegrator: '<S21>/Discrete-Time Integrator'
   */
  rtb_Sum_b[0] = Plant_DW.DiscreteTimeIntegrator_DSTAT_p2[1] * rtb_Add_jo[2];

  /* Product: '<S28>/Multiply1' incorporates:
   *  DiscreteIntegrator: '<S21>/Discrete-Time Integrator'
   */
  rtb_Sum_b[1] = Plant_DW.DiscreteTimeIntegrator_DSTAT_p2[2] * rtb_Add_jo[0];

  /* Product: '<S28>/Multiply2' incorporates:
   *  DiscreteIntegrator: '<S21>/Discrete-Time Integrator'
   */
  rtb_Sum_b[2] = Plant_DW.DiscreteTimeIntegrator_DSTAT_p2[0] * rtb_Add_jo[1];

  /* Product: '<S29>/Multiply3' incorporates:
   *  DiscreteIntegrator: '<S21>/Discrete-Time Integrator'
   */
  rtb_Sum_nh[0] = Plant_DW.DiscreteTimeIntegrator_DSTAT_p2[2] * rtb_Add_jo[1];

  /* Product: '<S29>/Multiply4' incorporates:
   *  DiscreteIntegrator: '<S21>/Discrete-Time Integrator'
   */
  rtb_Sum_nh[1] = Plant_DW.DiscreteTimeIntegrator_DSTAT_p2[0] * rtb_Add_jo[2];

  /* Product: '<S29>/Multiply5' incorporates:
   *  DiscreteIntegrator: '<S21>/Discrete-Time Integrator'
   */
  rtb_Sum_nh[2] = Plant_DW.DiscreteTimeIntegrator_DSTAT_p2[1] * rtb_Add_jo[0];

  /* RelationalOperator: '<S38>/FixPt Relational Operator' incorporates:
   *  Inport: '<Root>/States_Init'
   *  UnitDelay: '<S38>/Delay Input1'
   *
   * Block description for '<S38>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_FixPtRelationalOperator_c = (Plant_U.States_Init.timestamp !=
    Plant_DW.DelayInput1_DSTATE_j);

  /* DiscreteIntegrator: '<S22>/Discrete-Time Integrator' incorporates:
   *  Logic: '<S22>/Logical Operator'
   */
  if (rtb_FixPtRelationalOperator_c || (Plant_DW.DiscreteTimeIntegrator_PrevRe_p
       != 0)) {
    Plant_DW.DiscreteTimeIntegrator_DSTATE_a[0] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_a[1] = 0.0F;
    Plant_DW.DiscreteTimeIntegrator_DSTATE_a[2] = 0.0F;
  }

  rtb_vel_O_mPs_idx_0 = Plant_DW.DiscreteTimeIntegrator_DSTATE_a[0];
  rtb_vel_O_mPs_idx_1 = Plant_DW.DiscreteTimeIntegrator_DSTATE_a[1];
  rtb_vel_O_mPs_idx_2 = Plant_DW.DiscreteTimeIntegrator_DSTATE_a[2];

  /* Product: '<S46>/Product3' incorporates:
   *  Product: '<S43>/Divide'
   *  Product: '<S44>/Product6'
   */
  rtb_Sum_n3_idx_2 = rtb_Divide_o_idx_2 * rtb_Divide_o_idx_2;

  /* Product: '<S46>/Product6' incorporates:
   *  Product: '<S43>/Divide'
   *  Product: '<S44>/Product9'
   */
  rtb_Gain_d_tmp = rtb_Divide_o_idx_1 * rtb_Divide_o_idx_3;

  /* Product: '<S46>/Product7' incorporates:
   *  Product: '<S43>/Divide'
   *  Product: '<S44>/Product2'
   */
  rtb_Gain_d_tmp_0 = rtb_Divide_o_idx_0 * rtb_Divide_o_idx_2;

  /* Sum: '<S46>/Sum2' incorporates:
   *  Constant: '<S46>/Constant'
   *  Product: '<S43>/Divide'
   *  Product: '<S46>/Product2'
   *  Sum: '<S45>/Sum1'
   */
  rtb_DiscreteTimeIntegrator1_idx = 0.5F - rtb_Divide_o_idx_1 *
    rtb_Divide_o_idx_1;

  /* Product: '<S46>/Product1' incorporates:
   *  Product: '<S43>/Divide'
   *  Product: '<S45>/Product2'
   */
  rtb_Sum_jo = rtb_Divide_o_idx_0 * rtb_Divide_o_idx_1;

  /* Product: '<S46>/Product9' incorporates:
   *  Product: '<S43>/Divide'
   *  Product: '<S45>/Product3'
   */
  rtb_Sum_n3_idx_0 = rtb_Divide_o_idx_2 * rtb_Divide_o_idx_3;

  /* Sum: '<S46>/Sum' incorporates:
   *  DiscreteIntegrator: '<S22>/Discrete-Time Integrator'
   *  Gain: '<S46>/Gain1'
   *  Gain: '<S46>/Gain2'
   *  Gain: '<S46>/Gain3'
   *  Product: '<S46>/Product1'
   *  Product: '<S46>/Product3'
   *  Product: '<S46>/Product4'
   *  Product: '<S46>/Product5'
   *  Product: '<S46>/Product6'
   *  Product: '<S46>/Product7'
   *  Product: '<S46>/Product8'
   *  Product: '<S46>/Product9'
   *  Sum: '<S46>/Sum1'
   *  Sum: '<S46>/Sum2'
   *  Sum: '<S46>/Sum3'
   */
  rtb_Gain_g2 = ((rtb_Gain_d_tmp + rtb_Gain_d_tmp_0) * 2.0F *
                 Plant_DW.DiscreteTimeIntegrator_DSTATE_a[0] + (rtb_Sum_n3_idx_0
    - rtb_Sum_jo) * 2.0F * Plant_DW.DiscreteTimeIntegrator_DSTATE_a[1]) +
    (rtb_DiscreteTimeIntegrator1_idx - rtb_Sum_n3_idx_2) * 2.0F *
    Plant_DW.DiscreteTimeIntegrator_DSTATE_a[2];

  /* Product: '<S41>/Multiply' incorporates:
   *  DiscreteIntegrator: '<S21>/Discrete-Time Integrator'
   */
  rtb_Add_jo[0] = Plant_DW.DiscreteTimeIntegrator_DSTAT_p2[1] * rtb_Gain_g2;

  /* Product: '<S42>/Multiply4' incorporates:
   *  DiscreteIntegrator: '<S21>/Discrete-Time Integrator'
   */
  rtb_TrigonometricFunction1_idx_ = Plant_DW.DiscreteTimeIntegrator_DSTAT_p2[0] *
    rtb_Gain_g2;

  /* DiscreteIntegrator: '<S22>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/States_Init'
   */
  if (Plant_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
    Plant_DW.DiscreteTimeIntegrator1_DSTATE[0] = Plant_U.States_Init.pos[0];
    Plant_DW.DiscreteTimeIntegrator1_DSTATE[1] = Plant_U.States_Init.pos[1];
    Plant_DW.DiscreteTimeIntegrator1_DSTATE[2] = Plant_U.States_Init.pos[2];
  }

  if (rtb_FixPtRelationalOperator_c || (Plant_DW.DiscreteTimeIntegrator1_PrevRes
       != 0)) {
    Plant_DW.DiscreteTimeIntegrator1_DSTATE[0] = Plant_U.States_Init.pos[0];
    Plant_DW.DiscreteTimeIntegrator1_DSTATE[1] = Plant_U.States_Init.pos[1];
    Plant_DW.DiscreteTimeIntegrator1_DSTATE[2] = Plant_U.States_Init.pos[2];
  }

  /* Product: '<S44>/Product7' incorporates:
   *  Product: '<S43>/Divide'
   *  Product: '<S45>/Product9'
   */
  rtb_Gain_d_tmp_1 = rtb_Divide_o_idx_3 * rtb_Divide_o_idx_3;

  /* Product: '<S44>/Product' incorporates:
   *  Product: '<S43>/Divide'
   *  Product: '<S45>/Product6'
   */
  rtb_Divide_o_idx_1 *= rtb_Divide_o_idx_2;

  /* Product: '<S44>/Product1' incorporates:
   *  Product: '<S43>/Divide'
   *  Product: '<S45>/Product7'
   */
  rtb_Divide_o_idx_0 *= rtb_Divide_o_idx_3;

  /* Sum: '<S44>/Sum' incorporates:
   *  Constant: '<S44>/Constant'
   *  DiscreteIntegrator: '<S22>/Discrete-Time Integrator'
   *  Gain: '<S44>/Gain'
   *  Gain: '<S44>/Gain2'
   *  Gain: '<S44>/Gain3'
   *  Product: '<S44>/Product'
   *  Product: '<S44>/Product1'
   *  Product: '<S44>/Product4'
   *  Product: '<S44>/Product5'
   *  Product: '<S44>/Product7'
   *  Product: '<S44>/Product8'
   *  Sum: '<S44>/Sum1'
   *  Sum: '<S44>/Sum2'
   *  Sum: '<S44>/Sum3'
   */
  rtb_Gain_g2 = (((0.5F - rtb_Sum_n3_idx_2) - rtb_Gain_d_tmp_1) * 2.0F *
                 Plant_DW.DiscreteTimeIntegrator_DSTATE_a[0] +
                 (rtb_Divide_o_idx_1 + rtb_Divide_o_idx_0) * 2.0F *
                 Plant_DW.DiscreteTimeIntegrator_DSTATE_a[1]) + (rtb_Gain_d_tmp
    - rtb_Gain_d_tmp_0) * 2.0F * Plant_DW.DiscreteTimeIntegrator_DSTATE_a[2];

  /* Product: '<S41>/Multiply1' incorporates:
   *  DiscreteIntegrator: '<S21>/Discrete-Time Integrator'
   */
  rtb_Add_jo[1] = Plant_DW.DiscreteTimeIntegrator_DSTAT_p2[2] * rtb_Gain_g2;

  /* Product: '<S42>/Multiply5' incorporates:
   *  DiscreteIntegrator: '<S21>/Discrete-Time Integrator'
   */
  rtb_Sum_n3_idx_2 = Plant_DW.DiscreteTimeIntegrator_DSTAT_p2[1] * rtb_Gain_g2;

  /* Sum: '<S45>/Sum' incorporates:
   *  DiscreteIntegrator: '<S22>/Discrete-Time Integrator'
   *  Gain: '<S45>/Gain1'
   *  Gain: '<S45>/Gain2'
   *  Gain: '<S45>/Gain3'
   *  Product: '<S45>/Product4'
   *  Product: '<S45>/Product5'
   *  Product: '<S45>/Product8'
   *  Sum: '<S45>/Sum1'
   *  Sum: '<S45>/Sum2'
   *  Sum: '<S45>/Sum3'
   */
  rtb_Gain_g2 = ((rtb_DiscreteTimeIntegrator1_idx - rtb_Gain_d_tmp_1) * 2.0F *
                 Plant_DW.DiscreteTimeIntegrator_DSTATE_a[1] +
                 (rtb_Divide_o_idx_1 - rtb_Divide_o_idx_0) * 2.0F *
                 Plant_DW.DiscreteTimeIntegrator_DSTATE_a[0]) + (rtb_Sum_jo +
    rtb_Sum_n3_idx_0) * 2.0F * Plant_DW.DiscreteTimeIntegrator_DSTATE_a[2];

  /* DiscreteIntegrator: '<S22>/Discrete-Time Integrator1' */
  rtb_DiscreteTimeIntegrator1_idx = Plant_DW.DiscreteTimeIntegrator1_DSTATE[0];

  /* Sum: '<S21>/Sum' incorporates:
   *  Sum: '<S23>/Sum'
   */
  rtb_Sum_nh[0] = 0.0F - (rtb_Sum_b[0] - rtb_Sum_nh[0]);

  /* Sum: '<S22>/Sum' incorporates:
   *  DiscreteIntegrator: '<S21>/Discrete-Time Integrator'
   *  Product: '<S22>/Divide'
   *  Product: '<S42>/Multiply3'
   *  Sum: '<S37>/Sum'
   */
  rtb_Sum_n3_idx_0 = rtb_force_B_N_idx_0 - (rtb_Add_jo[0] -
    Plant_DW.DiscreteTimeIntegrator_DSTAT_p2[2] * rtb_Gain_g2);

  /* DiscreteIntegrator: '<S22>/Discrete-Time Integrator1' */
  rtb_force_B_N_idx_0 = Plant_DW.DiscreteTimeIntegrator1_DSTATE[1];

  /* Sum: '<S21>/Sum' incorporates:
   *  Sum: '<S23>/Sum'
   */
  rtb_Sum_nh[1] = 0.0F - (rtb_Sum_b[1] - rtb_Sum_nh[1]);

  /* Sum: '<S22>/Sum' incorporates:
   *  Product: '<S22>/Divide'
   *  Sum: '<S37>/Sum'
   */
  rtb_TrigonometricFunction1_idx_ = rtb_force_B_N_idx_1 - (rtb_Add_jo[1] -
    rtb_TrigonometricFunction1_idx_);

  /* DiscreteIntegrator: '<S22>/Discrete-Time Integrator1' */
  rtb_force_B_N_idx_1 = Plant_DW.DiscreteTimeIntegrator1_DSTATE[2];

  /* Sum: '<S22>/Sum' incorporates:
   *  DiscreteIntegrator: '<S21>/Discrete-Time Integrator'
   *  Product: '<S22>/Divide'
   *  Product: '<S41>/Multiply2'
   *  Sum: '<S37>/Sum'
   */
  rtb_Gain_g2 = 0.0F - (Plant_DW.DiscreteTimeIntegrator_DSTAT_p2[0] *
                        rtb_Gain_g2 - rtb_Sum_n3_idx_2);

  /* Sum: '<S21>/Sum' incorporates:
   *  Sum: '<S23>/Sum'
   */
  rtb_Sum_nh[2] = rtb_torque_B_Nm_idx_2 - (rtb_Sum_b[2] - rtb_Sum_nh[2]);

  /* Sum: '<S49>/Sum' incorporates:
   *  Constant: '<S49>/Constant'
   *  Gain: '<S49>/Gain'
   *  Gain: '<S49>/Gain1'
   *  Gain: '<S49>/Gain2'
   *  Product: '<S48>/Divide'
   *  Product: '<S49>/Product'
   *  Product: '<S49>/Product1'
   *  Product: '<S49>/Product2'
   *  Product: '<S49>/Product3'
   *  Product: '<S49>/Product4'
   *  Product: '<S49>/Product5'
   *  Product: '<S49>/Product6'
   *  Product: '<S49>/Product7'
   *  Product: '<S49>/Product8'
   *  Sum: '<S49>/Sum1'
   *  Sum: '<S49>/Sum2'
   *  Sum: '<S49>/Sum3'
   */
  rtb_torque_B_Nm_idx_2 = (((0.5F - rtb_TrigonometricFunction1_id_1 *
    rtb_TrigonometricFunction1_id_1) - rtb_TrigonometricFunction1_id_0 *
    rtb_TrigonometricFunction1_id_0) * 2.0F * rtb_Sum_n3_idx_0 + (rtb_Square2 *
    rtb_TrigonometricFunction1_id_1 - rtb_TrigonometricFunction1_id_2 *
    rtb_TrigonometricFunction1_id_0) * 2.0F * rtb_TrigonometricFunction1_idx_) +
    (rtb_Square2 * rtb_TrigonometricFunction1_id_0 +
     rtb_TrigonometricFunction1_id_2 * rtb_TrigonometricFunction1_id_1) * 2.0F *
    rtb_Gain_g2;

  /* Sum: '<S50>/Sum' incorporates:
   *  Constant: '<S50>/Constant'
   *  Gain: '<S50>/Gain'
   *  Gain: '<S50>/Gain1'
   *  Gain: '<S50>/Gain2'
   *  Product: '<S48>/Divide'
   *  Product: '<S50>/Product'
   *  Product: '<S50>/Product1'
   *  Product: '<S50>/Product2'
   *  Product: '<S50>/Product3'
   *  Product: '<S50>/Product4'
   *  Product: '<S50>/Product5'
   *  Product: '<S50>/Product6'
   *  Product: '<S50>/Product7'
   *  Product: '<S50>/Product8'
   *  Sum: '<S50>/Sum1'
   *  Sum: '<S50>/Sum2'
   *  Sum: '<S50>/Sum3'
   */
  rtb_Sum_jo = (((0.5F - rtb_Square2 * rtb_Square2) -
                 rtb_TrigonometricFunction1_id_0 *
                 rtb_TrigonometricFunction1_id_0) * 2.0F *
                rtb_TrigonometricFunction1_idx_ + (rtb_Square2 *
    rtb_TrigonometricFunction1_id_1 + rtb_TrigonometricFunction1_id_2 *
    rtb_TrigonometricFunction1_id_0) * 2.0F * rtb_Sum_n3_idx_0) +
    (rtb_TrigonometricFunction1_id_1 * rtb_TrigonometricFunction1_id_0 -
     rtb_TrigonometricFunction1_id_2 * rtb_Square2) * 2.0F * rtb_Gain_g2;

  /* Sum: '<S51>/Sum' incorporates:
   *  Constant: '<S51>/Constant'
   *  Gain: '<S51>/Gain1'
   *  Gain: '<S51>/Gain2'
   *  Gain: '<S51>/Gain3'
   *  Product: '<S48>/Divide'
   *  Product: '<S51>/Product1'
   *  Product: '<S51>/Product2'
   *  Product: '<S51>/Product3'
   *  Product: '<S51>/Product4'
   *  Product: '<S51>/Product5'
   *  Product: '<S51>/Product6'
   *  Product: '<S51>/Product7'
   *  Product: '<S51>/Product8'
   *  Product: '<S51>/Product9'
   *  Sum: '<S51>/Sum1'
   *  Sum: '<S51>/Sum2'
   *  Sum: '<S51>/Sum3'
   */
  rtb_Sum_n3_idx_0 = ((rtb_Square2 * rtb_TrigonometricFunction1_id_0 -
                       rtb_TrigonometricFunction1_id_2 *
                       rtb_TrigonometricFunction1_id_1) * 2.0F *
                      rtb_Sum_n3_idx_0 + (rtb_TrigonometricFunction1_id_2 *
    rtb_Square2 + rtb_TrigonometricFunction1_id_1 *
    rtb_TrigonometricFunction1_id_0) * 2.0F * rtb_TrigonometricFunction1_idx_) +
    ((0.5F - rtb_Square2 * rtb_Square2) - rtb_TrigonometricFunction1_id_1 *
     rtb_TrigonometricFunction1_id_1) * 2.0F * rtb_Gain_g2;

  /* Math: '<S26>/Square1' incorporates:
   *  Product: '<S32>/Divide'
   */
  rtb_Square2 = rtb_TrigonometricFunction1_id_3 *
    rtb_TrigonometricFunction1_id_3;

  /* Product: '<S26>/Multiply6' incorporates:
   *  Constant: '<S26>/Constant'
   *  Product: '<S26>/Multiply4'
   *  Product: '<S26>/Multiply5'
   *  Product: '<S32>/Divide'
   *  Sum: '<S26>/Subtract'
   */
  rtb_Gain_d_tmp_1 = (rtb_Product2_e * rtb_TrigonometricFunction1_id_3 -
                      rtb_TrigonometricFunction1_id_4 * rtb_Add_c) * 2.0F;

  /* Update for UnitDelay: '<S24>/Delay Input1' incorporates:
   *  Inport: '<Root>/States_Init'
   *
   * Block description for '<S24>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Plant_DW.DelayInput1_DSTATE = Plant_U.States_Init.timestamp;

  /* Update for DiscreteIntegrator: '<S27>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_IC_LOADI = 0U;

  /* Product: '<S27>/Multiply' incorporates:
   *  DiscreteIntegrator: '<S27>/Discrete-Time Integrator'
   */
  for (i = 0; i < 4; i++) {
    rtb_Gain_g2 = rtb_MatrixConcatenate4[i + 12] *
      Plant_DW.DiscreteTimeIntegrator_DSTAT_p4[3] + (rtb_MatrixConcatenate4[i +
      8] * Plant_DW.DiscreteTimeIntegrator_DSTAT_p4[2] +
      (rtb_MatrixConcatenate4[i + 4] * Plant_DW.DiscreteTimeIntegrator_DSTAT_p4
       [1] + rtb_MatrixConcatenate4[i] *
       Plant_DW.DiscreteTimeIntegrator_DSTAT_p4[0]));
    rtb_MatrixConcatenate4_0[i] = rtb_Gain_g2;
  }

  /* End of Product: '<S27>/Multiply' */

  /* Update for DiscreteIntegrator: '<S27>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S27>/Gain'
   */
  Plant_DW.DiscreteTimeIntegrator_DSTAT_p4[0] += 0.5F *
    rtb_MatrixConcatenate4_0[0] * 0.002F;
  Plant_DW.DiscreteTimeIntegrator_DSTAT_p4[1] += 0.5F *
    rtb_MatrixConcatenate4_0[1] * 0.002F;
  Plant_DW.DiscreteTimeIntegrator_DSTAT_p4[2] += 0.5F *
    rtb_MatrixConcatenate4_0[2] * 0.002F;
  Plant_DW.DiscreteTimeIntegrator_DSTAT_p4[3] += 0.5F *
    rtb_MatrixConcatenate4_0[3] * 0.002F;
  Plant_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)rtb_FixPtRelationalOperator;

  /* Product: '<S21>/Divide' incorporates:
   *  Constant: '<S21>/Inertia_Matrix'
   */
  rt_mldivide_U1f3x3_U2f3x1_Yf3x1(Plant_ConstP.Inertia_Matrix_Value, rtb_Sum_nh,
    rtb_act_force);

  /* Update for DiscreteIntegrator: '<S21>/Discrete-Time Integrator' incorporates:
   *  Logic: '<S21>/Logical Operator'
   */
  Plant_DW.DiscreteTimeIntegrator_PrevRe_c = (int8_T)rtb_FixPtRelationalOperator;

  /* Update for UnitDelay: '<S38>/Delay Input1' incorporates:
   *  Inport: '<Root>/States_Init'
   *
   * Block description for '<S38>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Plant_DW.DelayInput1_DSTATE_j = Plant_U.States_Init.timestamp;

  /* Update for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' incorporates:
   *  Logic: '<S22>/Logical Operator'
   */
  Plant_DW.DiscreteTimeIntegrator_PrevRe_p = (int8_T)
    rtb_FixPtRelationalOperator_c;

  /* Update for DiscreteIntegrator: '<S22>/Discrete-Time Integrator1' */
  Plant_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;

  /* Update for DiscreteIntegrator: '<S21>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTAT_p2[0] += 0.002F * rtb_act_force[0];

  /* Update for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_a[0] += 0.002F * rtb_torque_B_Nm_idx_2;

  /* Update for DiscreteIntegrator: '<S22>/Discrete-Time Integrator1' */
  Plant_DW.DiscreteTimeIntegrator1_DSTATE[0] += 0.002F * rtb_vel_O_mPs_idx_0;

  /* Update for DiscreteIntegrator: '<S21>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTAT_p2[1] += 0.002F * rtb_act_force[1];

  /* Update for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_a[1] += 0.002F * rtb_Sum_jo;

  /* Update for DiscreteIntegrator: '<S22>/Discrete-Time Integrator1' */
  Plant_DW.DiscreteTimeIntegrator1_DSTATE[1] += 0.002F * rtb_vel_O_mPs_idx_1;

  /* Update for DiscreteIntegrator: '<S21>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTAT_p2[2] += 0.002F * rtb_act_force[2];

  /* Update for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_a[2] += 0.002F * rtb_Sum_n3_idx_0;

  /* Update for DiscreteIntegrator: '<S22>/Discrete-Time Integrator1' */
  Plant_DW.DiscreteTimeIntegrator1_DSTATE[2] += 0.002F * rtb_vel_O_mPs_idx_2;
  Plant_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
    rtb_FixPtRelationalOperator_c;

  /* End of Outputs for SubSystem: '<Root>/Kinematic_Equation' */

  /* Outputs for Atomic SubSystem: '<Root>/Bus_Constructor' */
  /* Sqrt: '<S15>/Sqrt' incorporates:
   *  Math: '<S15>/Square'
   *  Sum: '<S15>/Sum of Elements'
   */
  rtb_Gain_g2 = sqrtf(((rtb_Magnitude_Lookup_Table * rtb_Magnitude_Lookup_Table
                        + rtb_Square_idx_1 * rtb_Square_idx_1) +
                       rtb_MathFunction1_c * rtb_MathFunction1_c) + rtb_Product8
                      * rtb_Product8);

  /* Product: '<S11>/Divide' */
  rtb_TrigonometricFunction1_id_2 = rtb_Magnitude_Lookup_Table / rtb_Gain_g2;
  rtb_TrigonometricFunction1_id_1 = rtb_Square_idx_1 / rtb_Gain_g2;
  rtb_TrigonometricFunction1_id_0 = rtb_MathFunction1_c / rtb_Gain_g2;
  rtb_TrigonometricFunction1_idx_ = rtb_Product8 / rtb_Gain_g2;

  /* Math: '<S12>/Square' incorporates:
   *  Math: '<S13>/Square'
   *  Math: '<S14>/Square'
   *  Product: '<S11>/Divide'
   */
  rtb_Gain_g2 = rtb_TrigonometricFunction1_id_2 *
    rtb_TrigonometricFunction1_id_2;

  /* Sum: '<S12>/Subtract' incorporates:
   *  Math: '<S12>/Square'
   *  Math: '<S12>/Square1'
   *  Math: '<S12>/Square2'
   *  Math: '<S12>/Square3'
   *  Product: '<S11>/Divide'
   *  Sum: '<S12>/Add'
   *  Sum: '<S12>/Add1'
   */
  rtb_VectorConcatenate_f[0] = (rtb_Gain_g2 + rtb_TrigonometricFunction1_id_1 *
    rtb_TrigonometricFunction1_id_1) - (rtb_TrigonometricFunction1_id_0 *
    rtb_TrigonometricFunction1_id_0 + rtb_TrigonometricFunction1_idx_ *
    rtb_TrigonometricFunction1_idx_);

  /* Gain: '<S12>/Gain' incorporates:
   *  Product: '<S11>/Divide'
   *  Product: '<S12>/Multiply'
   *  Product: '<S12>/Multiply1'
   *  Sum: '<S12>/Subtract1'
   */
  rtb_VectorConcatenate_f[1] = (rtb_TrigonometricFunction1_id_1 *
    rtb_TrigonometricFunction1_id_0 - rtb_TrigonometricFunction1_id_2 *
    rtb_TrigonometricFunction1_idx_) * 2.0F;

  /* Gain: '<S12>/Gain1' incorporates:
   *  Product: '<S11>/Divide'
   *  Product: '<S12>/Multiply2'
   *  Product: '<S12>/Multiply3'
   *  Sum: '<S12>/Add2'
   */
  rtb_VectorConcatenate_f[2] = (rtb_TrigonometricFunction1_id_1 *
    rtb_TrigonometricFunction1_idx_ + rtb_TrigonometricFunction1_id_2 *
    rtb_TrigonometricFunction1_id_0) * 2.0F;

  /* Gain: '<S13>/Gain' incorporates:
   *  Product: '<S11>/Divide'
   *  Product: '<S13>/Multiply'
   *  Product: '<S13>/Multiply1'
   *  Sum: '<S13>/Add3'
   */
  rtb_VectorConcatenate_f[3] = (rtb_TrigonometricFunction1_id_1 *
    rtb_TrigonometricFunction1_id_0 + rtb_TrigonometricFunction1_id_2 *
    rtb_TrigonometricFunction1_idx_) * 2.0F;

  /* Sum: '<S13>/Subtract' incorporates:
   *  Math: '<S13>/Square1'
   *  Math: '<S13>/Square2'
   *  Math: '<S13>/Square3'
   *  Product: '<S11>/Divide'
   *  Sum: '<S13>/Add'
   *  Sum: '<S13>/Add1'
   */
  rtb_VectorConcatenate_f[4] = (rtb_Gain_g2 + rtb_TrigonometricFunction1_id_0 *
    rtb_TrigonometricFunction1_id_0) - (rtb_TrigonometricFunction1_id_1 *
    rtb_TrigonometricFunction1_id_1 + rtb_TrigonometricFunction1_idx_ *
    rtb_TrigonometricFunction1_idx_);

  /* Gain: '<S13>/Gain1' incorporates:
   *  Product: '<S11>/Divide'
   *  Product: '<S13>/Multiply2'
   *  Product: '<S13>/Multiply3'
   *  Sum: '<S13>/Subtract1'
   */
  rtb_VectorConcatenate_f[5] = (rtb_TrigonometricFunction1_id_0 *
    rtb_TrigonometricFunction1_idx_ - rtb_TrigonometricFunction1_id_2 *
    rtb_TrigonometricFunction1_id_1) * 2.0F;

  /* Gain: '<S14>/Gain' incorporates:
   *  Product: '<S11>/Divide'
   *  Product: '<S14>/Multiply'
   *  Product: '<S14>/Multiply1'
   *  Sum: '<S14>/Subtract2'
   */
  rtb_VectorConcatenate_f[6] = (rtb_TrigonometricFunction1_id_1 *
    rtb_TrigonometricFunction1_idx_ - rtb_TrigonometricFunction1_id_2 *
    rtb_TrigonometricFunction1_id_0) * 2.0F;

  /* Gain: '<S14>/Gain1' incorporates:
   *  Product: '<S11>/Divide'
   *  Product: '<S14>/Multiply2'
   *  Product: '<S14>/Multiply3'
   *  Sum: '<S14>/Add2'
   */
  rtb_VectorConcatenate_f[7] = (rtb_TrigonometricFunction1_id_0 *
    rtb_TrigonometricFunction1_idx_ + rtb_TrigonometricFunction1_id_2 *
    rtb_TrigonometricFunction1_id_1) * 2.0F;

  /* Sum: '<S14>/Subtract' incorporates:
   *  Math: '<S14>/Square1'
   *  Math: '<S14>/Square2'
   *  Math: '<S14>/Square3'
   *  Product: '<S11>/Divide'
   *  Sum: '<S14>/Add'
   *  Sum: '<S14>/Add1'
   */
  rtb_VectorConcatenate_f[8] = (rtb_Gain_g2 + rtb_TrigonometricFunction1_idx_ *
    rtb_TrigonometricFunction1_idx_) - (rtb_TrigonometricFunction1_id_1 *
    rtb_TrigonometricFunction1_id_1 + rtb_TrigonometricFunction1_id_0 *
    rtb_TrigonometricFunction1_id_0);

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

  Plant_Y.Extended_States.quat[0] = rtb_Magnitude_Lookup_Table;
  Plant_Y.Extended_States.quat[1] = rtb_Square_idx_1;
  Plant_Y.Extended_States.quat[2] = rtb_MathFunction1_c;
  Plant_Y.Extended_States.quat[3] = rtb_Product8;

  /* End of BusAssignment: '<S2>/Bus Assignment2' */

  /* Delay: '<S10>/Delay1' incorporates:
   *  Constant: '<S10>/Constant1'
   *  Constant: '<S10>/Constant2'
   *  Constant: '<S10>/Constant3'
   *  SignalConversion: '<S10>/TmpSignal ConversionAtDelay1Inport2'
   */
  if (Plant_DW.icLoad != 0) {
    Plant_DW.Delay1_DSTATE_n[0] = PLANT_PARAM.LAT_0;
    Plant_DW.Delay1_DSTATE_n[1] = PLANT_PARAM.LON_0;
    Plant_DW.Delay1_DSTATE_n[2] = PLANT_PARAM.ALT_0;
  }

  /* Trigonometry: '<S16>/Trigonometric Function1' incorporates:
   *  Delay: '<S10>/Delay1'
   *  Trigonometry: '<S16>/Trigonometric Function2'
   */
  rtb_Add_idx_1 = cos(Plant_DW.Delay1_DSTATE_n[0]);

  /* Trigonometry: '<S16>/Trigonometric Function' incorporates:
   *  Delay: '<S10>/Delay1'
   */
  rtb_SumofElements = sin(Plant_DW.Delay1_DSTATE_n[0]);

  /* Sum: '<S16>/Subtract' incorporates:
   *  Constant: '<S16>/c'
   *  Math: '<S16>/u^2'
   *  Product: '<S16>/Product'
   */
  rtb_SumofElements = 1.0 - rtb_SumofElements * rtb_SumofElements *
    Plant_ConstB.Product1;

  /* Math: '<S16>/sqrt'
   *
   * About '<S16>/sqrt':
   *  Operator: sqrt
   */
  if (rtb_SumofElements < 0.0) {
    rtb_SumofElements = -sqrt(fabs(rtb_SumofElements));
  } else {
    rtb_SumofElements = sqrt(rtb_SumofElements);
  }

  /* End of Math: '<S16>/sqrt' */

  /* Product: '<S16>/Divide' incorporates:
   *  Constant: '<S16>/earth_radius'
   */
  rtb_SumofElements = 6.378137E+6 / rtb_SumofElements;

  /* Sum: '<S16>/Add' incorporates:
   *  Constant: '<S16>/constant2'
   *  Delay: '<S10>/Delay1'
   *  Math: '<S16>/u^1'
   *  Product: '<S16>/Product2'
   *  Product: '<S16>/Product3'
   *  Sum: '<S16>/Subtract2'
   *  Trigonometry: '<S16>/Trigonometric Function1'
   */
  rtb_SumofElements1 = (1.0 - rtb_Add_idx_1 * rtb_Add_idx_1 *
                        Plant_ConstB.Product1) * rtb_SumofElements +
    Plant_DW.Delay1_DSTATE_n[2];

  /* Sum: '<S16>/Add1' incorporates:
   *  Delay: '<S10>/Delay1'
   */
  rtb_SumofElements += Plant_DW.Delay1_DSTATE_n[2];

  /* Product: '<S16>/Product4' */
  rtb_SumofElements *= rtb_Add_idx_1;

  /* Signum: '<S17>/Sign' */
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

  /* End of Signum: '<S17>/Sign' */

  /* Switch: '<S17>/Switch' incorporates:
   *  Constant: '<S17>/Constant'
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

  /* End of Switch: '<S17>/Switch' */

  /* BusAssignment: '<S2>/Bus Assignment1' incorporates:
   *  BusAssignment: '<S2>/Bus Assignment'
   *  Constant: '<S2>/Constant'
   *  Delay: '<Root>/Delay'
   */
  Plant_Y.Plant_States = Plant_rtZPlant_States_Bus;

  /* Outputs for Atomic SubSystem: '<Root>/Kinematic_Equation' */
  /* BusAssignment: '<S2>/Bus Assignment' incorporates:
   *  BusAssignment: '<S2>/Bus Assignment1'
   *  Constant: '<S26>/Constant'
   *  Constant: '<S26>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Math: '<S26>/Square'
   *  Product: '<S26>/Multiply'
   *  Product: '<S26>/Multiply1'
   *  Product: '<S26>/Multiply2'
   *  Product: '<S26>/Multiply3'
   *  Product: '<S32>/Divide'
   *  Sum: '<S26>/Add'
   *  Sum: '<S26>/Add1'
   *  Sum: '<S26>/Subtract2'
   *  Trigonometry: '<S26>/Atan2'
   */
  Plant_Y.Plant_States.phi = atan2f((rtb_Product2_e * rtb_Add_c +
    rtb_TrigonometricFunction1_id_3 * rtb_TrigonometricFunction1_id_4) * 2.0F,
    1.0F - 2.0F * (rtb_Add_c * rtb_Add_c + rtb_Square2));

  /* End of Outputs for SubSystem: '<Root>/Bus_Constructor' */

  /* Saturate: '<S26>/Saturation' */
  if (rtb_Gain_d_tmp_1 > 1.0F) {
    rtb_Gain_d_tmp_1 = 1.0F;
  } else {
    if (rtb_Gain_d_tmp_1 < -1.0F) {
      rtb_Gain_d_tmp_1 = -1.0F;
    }
  }

  /* End of Saturate: '<S26>/Saturation' */

  /* Outputs for Atomic SubSystem: '<Root>/Bus_Constructor' */
  /* BusAssignment: '<S2>/Bus Assignment' incorporates:
   *  BusAssignment: '<S2>/Bus Assignment1'
   *  Constant: '<S26>/Constant'
   *  Constant: '<S26>/Constant1'
   *  Delay: '<Root>/Delay'
   *  Math: '<S26>/Square2'
   *  Product: '<S26>/Multiply10'
   *  Product: '<S26>/Multiply7'
   *  Product: '<S26>/Multiply8'
   *  Product: '<S26>/Multiply9'
   *  Product: '<S32>/Divide'
   *  Sum: '<S26>/Add2'
   *  Sum: '<S26>/Add3'
   *  Sum: '<S26>/Subtract1'
   *  Trigonometry: '<S26>/Asin'
   *  Trigonometry: '<S26>/Atan1'
   */
  Plant_Y.Plant_States.theta = asinf(rtb_Gain_d_tmp_1);
  Plant_Y.Plant_States.psi = atan2f((rtb_Product2_e *
    rtb_TrigonometricFunction1_id_4 + rtb_Add_c *
    rtb_TrigonometricFunction1_id_3) * 2.0F, 1.0F - 2.0F *
    (rtb_TrigonometricFunction1_id_4 * rtb_TrigonometricFunction1_id_4 +
     rtb_Square2));

  /* End of Outputs for SubSystem: '<Root>/Kinematic_Equation' */
  Plant_Y.Plant_States.rot_x_B = rtb_omega_B_radPs_idx_0;
  Plant_Y.Plant_States.rot_y_B = rtb_omega_B_radPs_idx_1;
  Plant_Y.Plant_States.rot_z_B = rtb_omega_B_radPs_idx_2;
  Plant_Y.Plant_States.acc_x_O = rtb_torque_B_Nm_idx_2;
  Plant_Y.Plant_States.acc_y_O = rtb_Sum_jo;
  Plant_Y.Plant_States.acc_z_O = rtb_Sum_n3_idx_0;
  Plant_Y.Plant_States.vel_x_O = rtb_vel_O_mPs_idx_0;
  Plant_Y.Plant_States.vel_y_O = rtb_vel_O_mPs_idx_1;
  Plant_Y.Plant_States.vel_z_O = rtb_vel_O_mPs_idx_2;

  /* Abs: '<S17>/Abs' */
  rtb_Divide2_idx_1 = fabs(rtb_SumofElements1);

  /* Saturate: '<S17>/Saturation' */
  if (rtb_Divide2_idx_1 > 1.0E+8) {
    rtb_Divide2_idx_1 = 1.0E+8;
  } else {
    if (rtb_Divide2_idx_1 < 1.0E-6) {
      rtb_Divide2_idx_1 = 1.0E-6;
    }
  }

  /* Sum: '<S10>/Add' incorporates:
   *  DataTypeConversion: '<S10>/Data Type Conversion'
   *  Delay: '<S10>/Delay'
   *  Delay: '<S10>/Delay1'
   *  Product: '<S10>/Divide'
   *  Product: '<S17>/Product'
   *  Sum: '<S10>/Subtract'
   */
  rtb_SumofElements1 = 1.0 / (rtb_Divide2_idx_1 * rtb_Divide2_idx_0) *
    (rtb_DiscreteTimeIntegrator1_idx - Plant_DW.Delay_DSTATE_a[0]) +
    Plant_DW.Delay1_DSTATE_n[0];

  /* Abs: '<S17>/Abs' */
  rtb_Divide2_idx_1 = fabs(rtb_SumofElements);

  /* Saturate: '<S17>/Saturation' */
  if (rtb_Divide2_idx_1 > 1.0E+8) {
    rtb_Divide2_idx_1 = 1.0E+8;
  } else {
    if (rtb_Divide2_idx_1 < 1.0E-6) {
      rtb_Divide2_idx_1 = 1.0E-6;
    }
  }

  /* Sum: '<S10>/Add' incorporates:
   *  DataTypeConversion: '<S10>/Data Type Conversion'
   *  Delay: '<S10>/Delay'
   *  Delay: '<S10>/Delay1'
   *  Product: '<S10>/Divide'
   *  Product: '<S17>/Product'
   *  Sum: '<S10>/Subtract'
   */
  rtb_Add_idx_1 = 1.0 / (rtb_Divide2_idx_1 * rtb_Add_idx_1) *
    (rtb_force_B_N_idx_0 - Plant_DW.Delay_DSTATE_a[1]) +
    Plant_DW.Delay1_DSTATE_n[1];
  rtb_Divide2_idx_0 = -(rtb_force_B_N_idx_1 - Plant_DW.Delay_DSTATE_a[2]) +
    Plant_DW.Delay1_DSTATE_n[2];

  /* BusAssignment: '<S2>/Bus Assignment1' incorporates:
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant2'
   *  Constant: '<S2>/Constant3'
   *  Delay: '<Root>/Delay'
   *  Delay: '<S8>/Delay'
   *  Gain: '<S2>/Gain'
   */
  Plant_Y.Plant_States.x_R = rtb_DiscreteTimeIntegrator1_idx;
  Plant_Y.Plant_States.y_R = rtb_force_B_N_idx_0;
  Plant_Y.Plant_States.h_R = -rtb_force_B_N_idx_1;
  Plant_Y.Plant_States.lat = rtb_SumofElements1;
  Plant_Y.Plant_States.lon = rtb_Add_idx_1;
  Plant_Y.Plant_States.alt = rtb_Divide2_idx_0;
  Plant_Y.Plant_States.lat_0 = PLANT_PARAM.LAT_0;
  Plant_Y.Plant_States.lon_0 = PLANT_PARAM.LON_0;
  Plant_Y.Plant_States.alt_0 = PLANT_PARAM.ALT_0;
  Plant_Y.Plant_States.timestamp = Plant_DW.Delay_DSTATE_c;

  /* Sum: '<S8>/Sum' incorporates:
   *  Constant: '<S8>/dt'
   *  Delay: '<S8>/Delay'
   */
  Plant_DW.Delay_DSTATE_c += PLANT_EXPORT.period;

  /* Update for Delay: '<S10>/Delay1' */
  Plant_DW.icLoad = 0U;

  /* Update for Delay: '<S10>/Delay' incorporates:
   *  DataTypeConversion: '<S10>/Data Type Conversion'
   */
  Plant_DW.Delay_DSTATE_a[0] = rtb_DiscreteTimeIntegrator1_idx;

  /* Update for Delay: '<S10>/Delay1' */
  Plant_DW.Delay1_DSTATE_n[0] = rtb_SumofElements1;

  /* Update for Delay: '<S10>/Delay' incorporates:
   *  DataTypeConversion: '<S10>/Data Type Conversion'
   */
  Plant_DW.Delay_DSTATE_a[1] = rtb_force_B_N_idx_0;

  /* Update for Delay: '<S10>/Delay1' */
  Plant_DW.Delay1_DSTATE_n[1] = rtb_Add_idx_1;

  /* Update for Delay: '<S10>/Delay' incorporates:
   *  DataTypeConversion: '<S10>/Data Type Conversion'
   */
  Plant_DW.Delay_DSTATE_a[2] = rtb_force_B_N_idx_1;

  /* Update for Delay: '<S10>/Delay1' */
  Plant_DW.Delay1_DSTATE_n[2] = rtb_Divide2_idx_0;

  /* End of Outputs for SubSystem: '<Root>/Bus_Constructor' */

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_Model' */
  /* Outputs for Atomic SubSystem: '<S5>/Sensor_Barometer' */
  /* Saturate: '<S62>/Limit  altitude  to troposhere' incorporates:
   *  DataTypeConversion: '<S60>/Data Type Conversion'
   *  Delay: '<Root>/Delay'
   */
  if ((real32_T)Plant_Y.Plant_States.alt > 11000.0F) {
    rtb_Add_c = 11000.0F;
  } else if ((real32_T)Plant_Y.Plant_States.alt < 0.0F) {
    rtb_Add_c = 0.0F;
  } else {
    rtb_Add_c = (real32_T)Plant_Y.Plant_States.alt;
  }

  /* End of Saturate: '<S62>/Limit  altitude  to troposhere' */

  /* Sum: '<S62>/Sum1' incorporates:
   *  Constant: '<S62>/Sea Level  Temperature'
   *  Gain: '<S62>/Lapse Rate'
   */
  rtb_Magnitude_Lookup_Table = 288.15F - 0.0065F * rtb_Add_c;

  /* Sum: '<S62>/Sum' incorporates:
   *  Constant: '<S62>/Altitude of Troposphere'
   *  DataTypeConversion: '<S60>/Data Type Conversion'
   *  Delay: '<Root>/Delay'
   */
  rtb_MathFunction1_c = 11000.0F - (real32_T)Plant_Y.Plant_States.alt;

  /* Saturate: '<S62>/Limit  altitude  to Stratosphere' incorporates:
   *  Constant: '<S62>/Altitude of Troposphere'
   *  DataTypeConversion: '<S60>/Data Type Conversion'
   *  Delay: '<Root>/Delay'
   *  Sum: '<S62>/Sum'
   */
  if (11000.0F - (real32_T)Plant_Y.Plant_States.alt > 0.0F) {
    rtb_MathFunction1_c = 0.0F;
  } else {
    if (11000.0F - (real32_T)Plant_Y.Plant_States.alt < -9000.0F) {
      rtb_MathFunction1_c = -9000.0F;
    }
  }

  /* End of Saturate: '<S62>/Limit  altitude  to Stratosphere' */

  /* Product: '<S62>/Product2' incorporates:
   *  Constant: '<S62>/Constant'
   *  Gain: '<S62>/1//T0'
   *  Gain: '<S62>/P0'
   *  Gain: '<S62>/g//R'
   *  Math: '<S62>/(T//T0)^(g//LR) '
   *  Math: '<S62>/Stratosphere Model'
   *  Product: '<S62>/Product1'
   *
   * About '<S62>/Stratosphere Model':
   *  Operator: exp
   */
  rtb_Product2_e = powf(0.00347041478F * rtb_Magnitude_Lookup_Table, 5.25587559F)
    * 101325.0F * expf(1.0F / rtb_Magnitude_Lookup_Table * (0.0341631919F *
    rtb_MathFunction1_c));

  /* S-Function (sdsprandsrc2): '<S64>/Random Source' */
  RandSrc_GZ_R(&rtb_MathFunction1_c, &Plant_ConstP.pooled14, 1,
               &Plant_ConstP.pooled19, 1, Plant_DW.RandomSource_STATE_DWORK_b, 1,
               1);

  /* BusAssignment: '<S59>/Bus Assignment' incorporates:
   *  Constant: '<S59>/Constant2'
   *  DataTypeConversion: '<S59>/Data Type Conversion1'
   *  Memory: '<S53>/Memory1'
   *  Saturate: '<S61>/Saturation'
   *  Sum: '<S59>/Sum1'
   *  Sum: '<S61>/Add'
   */
  rtb_BusAssignment_i.timestamp = Plant_DW.Memory1_PreviousInput;
  rtb_BusAssignment_i.pressure = rtb_Product2_e + rtb_MathFunction1_c;
  rtb_BusAssignment_i.temperature = (real32_T)(rtb_Magnitude_Lookup_Table -
    273.15);

  /* RateTransition: '<S59>/Rate Transition' */
  if (Plant_M->Timing.TaskCounters.TID[1] == 0) {
    Plant_B.RateTransition_m = rtb_BusAssignment_i;
  }

  /* End of RateTransition: '<S59>/Rate Transition' */
  /* End of Outputs for SubSystem: '<S5>/Sensor_Barometer' */

  /* Outputs for Atomic SubSystem: '<S5>/Sensor_GPS' */
  /* Trigonometry: '<S77>/Sin' incorporates:
   *  Delay: '<S70>/Delay'
   */
  rtb_SumofElements = sin(Plant_DW.Delay_DSTATE[0]);

  /* Math: '<S77>/Square1' */
  rtb_SumofElements *= rtb_SumofElements;

  /* Product: '<S77>/Multiply1' incorporates:
   *  Product: '<S77>/Multiply'
   */
  rtb_SumofElements1 = Plant_ConstB.ff * rtb_SumofElements;

  /* Product: '<S77>/Divide' incorporates:
   *  Constant: '<S77>/Constant'
   *  Constant: '<S77>/R'
   *  Sqrt: '<S77>/Sqrt'
   *  Sum: '<S77>/Sum1'
   */
  rtb_SumofElements = 6.378137E+6 / sqrt(1.0 - rtb_SumofElements1);

  /* S-Function (sdsprandsrc2): '<S73>/Random Source' */
  RandSrc_GZ_R(rtb_RandomSource, &Plant_ConstP.pooled14, 1,
               Plant_ConstP.RandomSource_VarianceRTP, 3,
               Plant_DW.RandomSource_STATE_DWORK_l, 3, 1);

  /* Sum: '<S71>/Sum2' incorporates:
   *  Constant: '<S77>/Constant1'
   *  Delay: '<S70>/Delay'
   *  Product: '<S74>/Divide2'
   *  Product: '<S77>/Multiply1'
   *  Product: '<S77>/Multiply2'
   *  Product: '<S77>/Product3'
   *  Sum: '<S77>/Sum2'
   *  Trigonometry: '<S77>/Cos'
   */
  rtb_SumofElements1 = rtb_RandomSource[0] / (1.0 / (1.0 - rtb_SumofElements1) *
    Plant_ConstB.Sum4 * rtb_SumofElements) + Plant_DW.Delay_DSTATE[0];
  rtb_Add_idx_1 = rtb_RandomSource[1] / (rtb_SumofElements * cos
    (Plant_DW.Delay_DSTATE[0])) + Plant_DW.Delay_DSTATE[1];
  rtb_Divide2_idx_0 = rtb_RandomSource[2] / -1.0 + Plant_DW.Delay_DSTATE[2];

  /* S-Function (sdsprandsrc2): '<S73>/Random Source1' */
  RandSrc_GZ_R(rtb_RandomSource1, &Plant_ConstP.pooled14, 1,
               Plant_ConstP.RandomSource1_VarianceRTP, 3,
               Plant_DW.RandomSource1_STATE_DWORK, 3, 1);

  /* Sum: '<S71>/Sum1' incorporates:
   *  Delay: '<S70>/Delay1'
   */
  rtb_Add_jo[0] = rtb_RandomSource1[0] + Plant_DW.Delay1_DSTATE_a[0];
  rtb_Add_jo[1] = rtb_RandomSource1[1] + Plant_DW.Delay1_DSTATE_a[1];
  rtb_Add_jo[2] = rtb_RandomSource1[2] + Plant_DW.Delay1_DSTATE_a[2];

  /* DiscreteFir: '<S76>/Discrete FIR Filter' */
  rtb_Sum_nh[0] = rtb_Add_jo[0] * 0.5F + Plant_DW.DiscreteFIRFilter_states_f[0] *
    0.5F;
  rtb_Sum_nh[1] = rtb_Add_jo[1] * 0.5F + Plant_DW.DiscreteFIRFilter_states_f[1] *
    0.5F;

  /* Gain: '<S65>/Gain6' incorporates:
   *  Math: '<S72>/Math Function'
   *  Product: '<S72>/Matrix Multiply'
   *  Sqrt: '<S72>/Sqrt'
   *  Switch: '<S72>/Switch'
   */
  rtb_SumofElements = fmod(floor(sqrtf(rtb_RandomSource[0] * rtb_RandomSource[0]
    + rtb_RandomSource[1] * rtb_RandomSource[1]) * 1000.0), 4.294967296E+9);

  /* DataTypeConversion: '<S65>/Data Type Conversion' incorporates:
   *  Delay: '<S71>/Delay1'
   */
  rtb_Product1 = fmod(floor(Plant_DW.Delay1_DSTATE[0]), 256.0);

  /* Gain: '<S65>/Gain4' incorporates:
   *  DiscreteFir: '<S75>/Discrete FIR Filter'
   */
  rtb_Divide2_idx_1 = fmod(floor((rtb_Divide2_idx_0 * 0.5 +
    Plant_DW.DiscreteFIRFilter_states[2] * 0.5) * 1000.0), 4.294967296E+9);
  i = rtb_Divide2_idx_1 < 0.0 ? -(int32_T)(uint32_T)-rtb_Divide2_idx_1 :
    (int32_T)(uint32_T)rtb_Divide2_idx_1;

  /* Gain: '<S65>/Gain5' incorporates:
   *  Math: '<S72>/Math Function2'
   *  Product: '<S72>/Matrix Multiply2'
   *  Sqrt: '<S72>/Sqrt2'
   *  Switch: '<S72>/Switch1'
   */
  rtb_Divide2_idx_1 = fmod(floor(sqrtf(rtb_RandomSource[2] * rtb_RandomSource[2])
    * 1000.0), 4.294967296E+9);

  /* BusAssignment: '<S65>/Bus Assignment' incorporates:
   *  Constant: '<S65>/Constant10'
   *  Constant: '<S65>/Constant11'
   *  Constant: '<S65>/Constant12'
   *  Constant: '<S65>/Constant2'
   *  Constant: '<S65>/Constant3'
   *  Constant: '<S65>/Constant4'
   *  Constant: '<S65>/Constant5'
   *  Constant: '<S65>/Constant6'
   *  Constant: '<S65>/Constant7'
   *  Constant: '<S65>/Constant8'
   *  Constant: '<S65>/Constant9'
   *  DataTypeConversion: '<S65>/Data Type Conversion'
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

  /* DataTypeConversion: '<S65>/Data Type Conversion1' incorporates:
   *  Delay: '<S71>/Delay'
   */
  rtb_Product1 = fmod(floor(Plant_DW.Delay_DSTATE_i[0]), 256.0);

  /* BusAssignment: '<S65>/Bus Assignment' incorporates:
   *  DataTypeConversion: '<S65>/Data Type Conversion1'
   */
  rtb_BusAssignment_dk.numSV = (uint8_T)(rtb_Product1 < 0.0 ? (int32_T)(uint8_T)
    -(int8_T)(uint8_T)-rtb_Product1 : (int32_T)(uint8_T)rtb_Product1);

  /* Gain: '<S65>/Gain' incorporates:
   *  DiscreteFir: '<S75>/Discrete FIR Filter'
   *  Gain: '<S65>/Gain2'
   */
  rtb_Product1 = fmod(floor((rtb_SumofElements1 * 0.5 +
    Plant_DW.DiscreteFIRFilter_states[0] * 0.5) * 57.295779513082323 * 1.0E+7),
                      4.294967296E+9);

  /* BusAssignment: '<S65>/Bus Assignment' incorporates:
   *  Gain: '<S65>/Gain'
   */
  rtb_BusAssignment_dk.lon = rtb_Product1 < 0.0 ? -(int32_T)(uint32_T)
    -rtb_Product1 : (int32_T)(uint32_T)rtb_Product1;

  /* Gain: '<S65>/Gain1' incorporates:
   *  DiscreteFir: '<S75>/Discrete FIR Filter'
   *  Gain: '<S65>/Gain3'
   */
  rtb_Product1 = fmod(floor((rtb_Add_idx_1 * 0.5 +
    Plant_DW.DiscreteFIRFilter_states[1] * 0.5) * 57.295779513082323 * 1.0E+7),
                      4.294967296E+9);

  /* BusAssignment: '<S65>/Bus Assignment' incorporates:
   *  Gain: '<S65>/Gain1'
   *  Gain: '<S65>/Gain5'
   *  Gain: '<S65>/Gain6'
   */
  rtb_BusAssignment_dk.lat = rtb_Product1 < 0.0 ? -(int32_T)(uint32_T)
    -rtb_Product1 : (int32_T)(uint32_T)rtb_Product1;
  rtb_BusAssignment_dk.height = i;
  rtb_BusAssignment_dk.hMSL = i;
  rtb_BusAssignment_dk.hAcc = rtb_SumofElements < 0.0 ? (uint32_T)-(int32_T)
    (uint32_T)-rtb_SumofElements : (uint32_T)rtb_SumofElements;
  rtb_BusAssignment_dk.vAcc = rtb_Divide2_idx_1 < 0.0 ? (uint32_T)-(int32_T)
    (uint32_T)-rtb_Divide2_idx_1 : (uint32_T)rtb_Divide2_idx_1;

  /* Gain: '<S65>/Gain7' */
  rtb_Add_c = fmodf(floorf(1000.0F * rtb_Sum_nh[0]), 4.2949673E+9F);

  /* BusAssignment: '<S65>/Bus Assignment' incorporates:
   *  Gain: '<S65>/Gain7'
   */
  rtb_BusAssignment_dk.velN = rtb_Add_c < 0.0F ? -(int32_T)(uint32_T)-rtb_Add_c :
    (int32_T)(uint32_T)rtb_Add_c;

  /* Gain: '<S65>/Gain8' */
  rtb_Add_c = fmodf(floorf(1000.0F * rtb_Sum_nh[1]), 4.2949673E+9F);

  /* BusAssignment: '<S65>/Bus Assignment' incorporates:
   *  Gain: '<S65>/Gain8'
   */
  rtb_BusAssignment_dk.velE = rtb_Add_c < 0.0F ? -(int32_T)(uint32_T)-rtb_Add_c :
    (int32_T)(uint32_T)rtb_Add_c;

  /* Gain: '<S65>/Gain9' incorporates:
   *  DiscreteFir: '<S76>/Discrete FIR Filter'
   */
  rtb_Add_c = fmodf(floorf((rtb_Add_jo[2] * 0.5F +
    Plant_DW.DiscreteFIRFilter_states_f[2] * 0.5F) * 1000.0F), 4.2949673E+9F);

  /* BusAssignment: '<S65>/Bus Assignment' incorporates:
   *  Constant: '<S65>/Constant15'
   *  Gain: '<S65>/Gain11'
   *  Gain: '<S65>/Gain9'
   *  Math: '<S67>/Math Function'
   *  Math: '<S67>/Math Function1'
   *  Saturate: '<S67>/Saturation'
   *  Sqrt: '<S67>/Sqrt'
   *  Sum: '<S67>/Add'
   */
  rtb_BusAssignment_dk.velD = rtb_Add_c < 0.0F ? -(int32_T)(uint32_T)-rtb_Add_c :
    (int32_T)(uint32_T)rtb_Add_c;
  rtb_BusAssignment_dk.gSpeed = (int32_T)(uint32_T)fmodf(floorf(sqrtf(fmaxf
    (rtb_Sum_nh[0] * rtb_Sum_nh[0] + rtb_Sum_nh[1] * rtb_Sum_nh[1], 0.0F)) *
    1000.0F), 4.2949673E+9F);
  rtb_BusAssignment_dk.heading = 0;

  /* Gain: '<S65>/Gain10' incorporates:
   *  Math: '<S72>/Math Function1'
   *  Product: '<S72>/Matrix Multiply1'
   *  Sqrt: '<S72>/Sqrt1'
   *  Switch: '<S72>/Switch2'
   */
  rtb_SumofElements = fmod(floor(sqrtf((rtb_RandomSource1[0] *
    rtb_RandomSource1[0] + rtb_RandomSource1[1] * rtb_RandomSource1[1]) +
    rtb_RandomSource1[2] * rtb_RandomSource1[2]) * 1000.0), 4.294967296E+9);

  /* BusAssignment: '<S65>/Bus Assignment' incorporates:
   *  Constant: '<S65>/Constant14'
   *  Constant: '<S65>/Constant16'
   *  Constant: '<S65>/Constant17'
   *  Gain: '<S65>/Gain10'
   *  Memory: '<S53>/Memory1'
   */
  rtb_BusAssignment_dk.sAcc = rtb_SumofElements < 0.0 ? (uint32_T)-(int32_T)
    (uint32_T)-rtb_SumofElements : (uint32_T)rtb_SumofElements;
  rtb_BusAssignment_dk.headingAcc = 0U;
  rtb_BusAssignment_dk.pDOP = 0U;
  rtb_BusAssignment_dk.reserved2 = 0U;
  rtb_BusAssignment_dk.timestamp = Plant_DW.Memory1_PreviousInput;

  /* RateTransition: '<S65>/Rate Transition' */
  if (Plant_M->Timing.TaskCounters.TID[2] == 0) {
    Plant_B.RateTransition = rtb_BusAssignment_dk;
  }

  /* End of RateTransition: '<S65>/Rate Transition' */

  /* Update for Delay: '<S70>/Delay' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S70>/ConcatBufferAtVector ConcatenateIn1'
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

  /* Update for DiscreteFir: '<S75>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states[0] = rtb_SumofElements1;

  /* Update for Delay: '<S70>/Delay' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S70>/ConcatBufferAtVector ConcatenateIn2'
   */
  Plant_DW.Delay_DSTATE[223] = Plant_Y.Plant_States.lat;

  /* Update for DiscreteFir: '<S75>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states[1] = rtb_Add_idx_1;

  /* Update for Delay: '<S70>/Delay' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S70>/ConcatBufferAtVector ConcatenateIn3'
   */
  Plant_DW.Delay_DSTATE[224] = Plant_Y.Plant_States.alt;

  /* Update for DiscreteFir: '<S75>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states[2] = rtb_Divide2_idx_0;

  /* Update for Delay: '<S70>/Delay1' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S70>/ConcatBufferAtVector Concatenate1In1'
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

  /* Update for DiscreteFir: '<S76>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states_f[0] = rtb_Add_jo[0];

  /* Update for Delay: '<S70>/Delay1' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S70>/ConcatBufferAtVector Concatenate1In2'
   */
  Plant_DW.Delay1_DSTATE_a[148] = Plant_Y.Plant_States.vel_y_O;

  /* Update for DiscreteFir: '<S76>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states_f[1] = rtb_Add_jo[1];

  /* Update for Delay: '<S70>/Delay1' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S70>/ConcatBufferAtVector Concatenate1In3'
   */
  Plant_DW.Delay1_DSTATE_a[149] = Plant_Y.Plant_States.vel_z_O;

  /* Update for DiscreteFir: '<S76>/Discrete FIR Filter' */
  Plant_DW.DiscreteFIRFilter_states_f[2] = rtb_Add_jo[2];
  for (i = 0; i < 249; i++) {
    /* Update for Delay: '<S71>/Delay1' */
    Plant_DW.Delay1_DSTATE[i] = Plant_DW.Delay1_DSTATE[i + 1];

    /* Update for Delay: '<S71>/Delay' */
    Plant_DW.Delay_DSTATE_i[i] = Plant_DW.Delay_DSTATE_i[i + 1];
  }

  /* Update for Delay: '<S71>/Delay1' incorporates:
   *  Constant: '<S71>/Constant2'
   */
  Plant_DW.Delay1_DSTATE[249] = 3.0;

  /* Update for Delay: '<S71>/Delay' incorporates:
   *  Constant: '<S71>/Constant1'
   */
  Plant_DW.Delay_DSTATE_i[249] = 16.0;

  /* End of Outputs for SubSystem: '<S5>/Sensor_GPS' */

  /* Outputs for Atomic SubSystem: '<S5>/Sensor_IMU' */
  /* Outputs for Atomic SubSystem: '<S82>/Vibration_Model' */
  /* Outputs for Atomic SubSystem: '<S93>/Vibration_Model' */
  /* Product: '<S99>/Divide2' incorporates:
   *  Constant: '<S99>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Product: '<S88>/Divide2'
   */
  rtb_SumofElements1 = Plant_Y.Extended_States.prop_vel[0] / 1047.1975511965977;

  /* End of Outputs for SubSystem: '<S82>/Vibration_Model' */

  /* Math: '<S99>/u^2' */
  rtb_Product1 = rtb_SumofElements1 * rtb_SumofElements1;

  /* Product: '<S95>/Product2' incorporates:
   *  DiscreteIntegrator: '<S95>/Discrete-Time Integrator'
   *  Trigonometry: '<S95>/Trigonometric Function2'
   */
  rtb_SumofElements = arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[0]) *
    rtb_Product1;

  /* Math: '<S99>/u^2' incorporates:
   *  DiscreteIntegrator: '<S95>/Discrete-Time Integrator'
   *  Product: '<S95>/Product1'
   *  Trigonometry: '<S95>/Trigonometric Function1'
   */
  rtb_Product1_idx_0 = arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[0]) *
    rtb_Product1;

  /* Product: '<S99>/Divide2' incorporates:
   *  Constant: '<S99>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Product: '<S88>/Divide2'
   */
  rtb_Add_idx_1 = rtb_SumofElements1;

  /* Outputs for Atomic SubSystem: '<S82>/Vibration_Model' */
  rtb_SumofElements1 = Plant_Y.Extended_States.prop_vel[1] / 1047.1975511965977;

  /* End of Outputs for SubSystem: '<S82>/Vibration_Model' */

  /* Math: '<S99>/u^2' */
  rtb_Product1 = rtb_SumofElements1 * rtb_SumofElements1;

  /* Product: '<S95>/Product2' incorporates:
   *  DiscreteIntegrator: '<S95>/Discrete-Time Integrator'
   *  Trigonometry: '<S95>/Trigonometric Function2'
   */
  rtb_Product2_g_idx_1 = arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[1]) *
    rtb_Product1;

  /* Math: '<S99>/u^2' incorporates:
   *  DiscreteIntegrator: '<S95>/Discrete-Time Integrator'
   *  Product: '<S95>/Product1'
   *  Trigonometry: '<S95>/Trigonometric Function1'
   */
  rtb_Product1_idx_1 = arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[1]) *
    rtb_Product1;

  /* Product: '<S99>/Divide2' incorporates:
   *  Constant: '<S99>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Product: '<S88>/Divide2'
   */
  rtb_Divide2_idx_0 = rtb_SumofElements1;

  /* Outputs for Atomic SubSystem: '<S82>/Vibration_Model' */
  rtb_SumofElements1 = Plant_Y.Extended_States.prop_vel[2] / 1047.1975511965977;

  /* End of Outputs for SubSystem: '<S82>/Vibration_Model' */

  /* Math: '<S99>/u^2' */
  rtb_Product1 = rtb_SumofElements1 * rtb_SumofElements1;

  /* Product: '<S99>/Divide2' incorporates:
   *  Constant: '<S99>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Product: '<S88>/Divide2'
   */
  rtb_Divide2_idx_1 = rtb_SumofElements1;

  /* Outputs for Atomic SubSystem: '<S82>/Vibration_Model' */
  rtb_SumofElements1 = Plant_Y.Extended_States.prop_vel[3] / 1047.1975511965977;

  /* Math: '<S99>/u^2' incorporates:
   *  Math: '<S88>/u^2'
   */
  rtb_SumofElements1 *= rtb_SumofElements1;

  /* End of Outputs for SubSystem: '<S82>/Vibration_Model' */

  /* Sum: '<S95>/Sum of Elements' incorporates:
   *  DiscreteIntegrator: '<S95>/Discrete-Time Integrator'
   *  Math: '<S99>/u^2'
   *  Product: '<S95>/Product2'
   *  Trigonometry: '<S95>/Trigonometric Function2'
   */
  rtb_SumofElements = ((rtb_SumofElements + rtb_Product2_g_idx_1) + arm_sin_f32
                       (Plant_DW.DiscreteTimeIntegrator_DSTATE[2]) *
                       rtb_Product1) + arm_sin_f32
    (Plant_DW.DiscreteTimeIntegrator_DSTATE[3]) * rtb_SumofElements1;

  /* Sum: '<S95>/Sum of Elements1' incorporates:
   *  DiscreteIntegrator: '<S95>/Discrete-Time Integrator'
   *  Math: '<S99>/u^2'
   *  Product: '<S95>/Product1'
   *  Trigonometry: '<S95>/Trigonometric Function1'
   */
  rtb_Product1 = ((rtb_Product1_idx_0 + rtb_Product1_idx_1) + arm_cos_f32
                  (Plant_DW.DiscreteTimeIntegrator_DSTATE[2]) * rtb_Product1) +
    arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE[3]) * rtb_SumofElements1;

  /* Outputs for Atomic SubSystem: '<S82>/Vibration_Model' */
  /* Update for DiscreteIntegrator: '<S95>/Discrete-Time Integrator' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S84>/Discrete-Time Integrator'
   */
  rtb_Product2_e = 0.002F * Plant_Y.Extended_States.prop_vel[0];

  /* End of Outputs for SubSystem: '<S82>/Vibration_Model' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE[0] += rtb_Product2_e;

  /* End of Outputs for SubSystem: '<S93>/Vibration_Model' */
  /* End of Outputs for SubSystem: '<S5>/Sensor_IMU' */
  /* End of Outputs for SubSystem: '<Root>/Sensor_Model' */
  rtb_TrigonometricFunction1_id_2 = rtb_Product2_e;

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_Model' */
  /* Outputs for Atomic SubSystem: '<S5>/Sensor_IMU' */
  /* Outputs for Atomic SubSystem: '<S82>/Vibration_Model' */
  /* Outputs for Atomic SubSystem: '<S93>/Vibration_Model' */
  /* Update for DiscreteIntegrator: '<S95>/Discrete-Time Integrator' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S84>/Discrete-Time Integrator'
   */
  rtb_Product2_e = 0.002F * Plant_Y.Extended_States.prop_vel[1];

  /* End of Outputs for SubSystem: '<S82>/Vibration_Model' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE[1] += rtb_Product2_e;

  /* End of Outputs for SubSystem: '<S93>/Vibration_Model' */
  /* End of Outputs for SubSystem: '<S5>/Sensor_IMU' */
  /* End of Outputs for SubSystem: '<Root>/Sensor_Model' */
  rtb_TrigonometricFunction1_id_1 = rtb_Product2_e;

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_Model' */
  /* Outputs for Atomic SubSystem: '<S5>/Sensor_IMU' */
  /* Outputs for Atomic SubSystem: '<S82>/Vibration_Model' */
  /* Outputs for Atomic SubSystem: '<S93>/Vibration_Model' */
  /* Update for DiscreteIntegrator: '<S95>/Discrete-Time Integrator' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S84>/Discrete-Time Integrator'
   */
  rtb_Product2_e = 0.002F * Plant_Y.Extended_States.prop_vel[2];

  /* End of Outputs for SubSystem: '<S82>/Vibration_Model' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE[2] += rtb_Product2_e;

  /* End of Outputs for SubSystem: '<S93>/Vibration_Model' */
  /* End of Outputs for SubSystem: '<S5>/Sensor_IMU' */
  /* End of Outputs for SubSystem: '<Root>/Sensor_Model' */
  rtb_TrigonometricFunction1_id_0 = rtb_Product2_e;

  /* Outputs for Atomic SubSystem: '<Root>/Sensor_Model' */
  /* Outputs for Atomic SubSystem: '<S5>/Sensor_IMU' */
  /* Outputs for Atomic SubSystem: '<S82>/Vibration_Model' */
  /* Outputs for Atomic SubSystem: '<S93>/Vibration_Model' */
  /* Update for DiscreteIntegrator: '<S95>/Discrete-Time Integrator' incorporates:
   *  Delay: '<Root>/Delay'
   *  DiscreteIntegrator: '<S84>/Discrete-Time Integrator'
   */
  rtb_Product2_e = 0.002F * Plant_Y.Extended_States.prop_vel[3];

  /* End of Outputs for SubSystem: '<S82>/Vibration_Model' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE[3] += rtb_Product2_e;

  /* Switch: '<S93>/Switch' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S95>/Gain2'
   *  Gain: '<S95>/Gain4'
   *  Product: '<S95>/Divide'
   *  SignalConversion: '<S97>/ConcatBufferAtVector ConcatenateIn1'
   *  SignalConversion: '<S97>/ConcatBufferAtVector ConcatenateIn2'
   *  SignalConversion: '<S97>/ConcatBufferAtVector ConcatenateIn3'
   *  Sum: '<S93>/Sum'
   *  Sum: '<S95>/Sum'
   *  Sum: '<S95>/Sum of Elements'
   *  Sum: '<S95>/Sum of Elements1'
   */
  rtb_Sum_nh[0] = (real32_T)(rtb_SumofElements / 4.0 * 0.5 +
    Plant_Y.Plant_States.rot_x_B);
  rtb_Sum_nh[1] = (real32_T)(rtb_Product1 / 4.0 * 0.5 +
    Plant_Y.Plant_States.rot_y_B);
  rtb_Add_c = (real32_T)((rtb_SumofElements + rtb_Product1) * 0.5 / 4.0 * 0.5 +
    Plant_Y.Plant_States.rot_z_B);

  /* End of Outputs for SubSystem: '<S93>/Vibration_Model' */

  /* Sum: '<S101>/Sum' incorporates:
   *  Product: '<S101>/Product'
   */
  for (i = 0; i < 3; i++) {
    rtb_RandomSource[i] = (Plant_ConstB.Add_g[i + 3] * rtb_Sum_nh[1] +
      Plant_ConstB.Add_g[i] * rtb_Sum_nh[0]) + Plant_ConstB.Add_g[i + 6] *
      rtb_Add_c;
  }

  /* End of Sum: '<S101>/Sum' */

  /* DiscreteIntegrator: '<S100>/Discrete-Time Integrator5' */
  if (Plant_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[0] = rtb_RandomSource[0];
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[1] = rtb_RandomSource[1];
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[2] = rtb_RandomSource[2];
  }

  /* S-Function (sdsprandsrc2): '<S91>/Random Source' */
  RandSrc_GZ_R(rtb_RandomSource_f, &Plant_ConstP.pooled14, 1,
               Plant_ConstP.RandomSource_VarianceRTP_f, 3,
               Plant_DW.RandomSource_STATE_DWORK_k, 3, 1);

  /* S-Function (sdsprandsrc2): '<S102>/Random Source' */
  RandSrc_GZ_R(rtb_Sum_b, &Plant_ConstP.pooled14, 1,
               Plant_ConstP.RandomSource_VarianceRTP_b, 3,
               Plant_DW.RandomSource_STATE_DWORK_h, 3, 1);

  /* Saturate: '<S94>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S100>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[0] > 34.9065857F) {
    rtb_Add_c = 34.9065857F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[0] < -34.9065857F) {
    rtb_Add_c = -34.9065857F;
  } else {
    rtb_Add_c = Plant_DW.DiscreteTimeIntegrator5_DSTATE[0];
  }

  /* Sum: '<S94>/Sum' */
  rtb_Add_jo[0] = rtb_Add_c + rtb_Sum_b[0];

  /* Saturate: '<S94>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S100>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[1] > 34.9065857F) {
    rtb_Add_c = 34.9065857F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[1] < -34.9065857F) {
    rtb_Add_c = -34.9065857F;
  } else {
    rtb_Add_c = Plant_DW.DiscreteTimeIntegrator5_DSTATE[1];
  }

  /* Sum: '<S94>/Sum' */
  rtb_Add_jo[1] = rtb_Add_c + rtb_Sum_b[1];

  /* Saturate: '<S94>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S100>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[2] > 34.9065857F) {
    rtb_Add_c = 34.9065857F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTATE[2] < -34.9065857F) {
    rtb_Add_c = -34.9065857F;
  } else {
    rtb_Add_c = Plant_DW.DiscreteTimeIntegrator5_DSTATE[2];
  }

  /* Sum: '<S94>/Sum' */
  rtb_Add_jo[2] = rtb_Add_c + rtb_Sum_b[2];

  /* Outputs for Atomic SubSystem: '<S82>/Vibration_Model' */
  /* Math: '<S88>/u^2' incorporates:
   *  Product: '<S88>/Divide2'
   */
  rtb_Product1 = rtb_Add_idx_1 * rtb_Add_idx_1;

  /* Product: '<S84>/Product2' incorporates:
   *  DiscreteIntegrator: '<S84>/Discrete-Time Integrator'
   *  Trigonometry: '<S84>/Trigonometric Function2'
   */
  rtb_SumofElements = arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_p[0]) *
    rtb_Product1;

  /* Math: '<S88>/u^2' incorporates:
   *  DiscreteIntegrator: '<S84>/Discrete-Time Integrator'
   *  Product: '<S84>/Product1'
   *  Product: '<S88>/Divide2'
   *  Trigonometry: '<S84>/Trigonometric Function1'
   */
  rtb_Product1_idx_0 = arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_p[0]) *
    rtb_Product1;
  rtb_Product1 = rtb_Divide2_idx_0 * rtb_Divide2_idx_0;

  /* Product: '<S84>/Product2' incorporates:
   *  DiscreteIntegrator: '<S84>/Discrete-Time Integrator'
   *  Trigonometry: '<S84>/Trigonometric Function2'
   */
  rtb_Product2_g_idx_1 = arm_sin_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_p[1])
    * rtb_Product1;

  /* Math: '<S88>/u^2' incorporates:
   *  DiscreteIntegrator: '<S84>/Discrete-Time Integrator'
   *  Product: '<S84>/Product1'
   *  Product: '<S88>/Divide2'
   *  Trigonometry: '<S84>/Trigonometric Function1'
   */
  rtb_Product1_idx_1 = arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_p[1]) *
    rtb_Product1;
  rtb_Product1 = rtb_Divide2_idx_1 * rtb_Divide2_idx_1;

  /* Sum: '<S84>/Sum of Elements' incorporates:
   *  DiscreteIntegrator: '<S84>/Discrete-Time Integrator'
   *  Product: '<S84>/Product2'
   *  Trigonometry: '<S84>/Trigonometric Function2'
   */
  rtb_SumofElements = ((rtb_SumofElements + rtb_Product2_g_idx_1) + arm_sin_f32
                       (Plant_DW.DiscreteTimeIntegrator_DSTATE_p[2]) *
                       rtb_Product1) + arm_sin_f32
    (Plant_DW.DiscreteTimeIntegrator_DSTATE_p[3]) * rtb_SumofElements1;

  /* SignalConversion: '<S84>/ConcatBufferAtVector ConcatenateIn1' incorporates:
   *  Sum: '<S84>/Sum of Elements'
   */
  rtb_DataTypeConversion[0] = rtb_SumofElements;

  /* Sum: '<S84>/Sum of Elements1' incorporates:
   *  DiscreteIntegrator: '<S84>/Discrete-Time Integrator'
   *  Product: '<S84>/Product1'
   *  Trigonometry: '<S84>/Trigonometric Function1'
   */
  rtb_Product1 = ((rtb_Product1_idx_0 + rtb_Product1_idx_1) + arm_cos_f32
                  (Plant_DW.DiscreteTimeIntegrator_DSTATE_p[2]) * rtb_Product1)
    + arm_cos_f32(Plant_DW.DiscreteTimeIntegrator_DSTATE_p[3]) *
    rtb_SumofElements1;

  /* SignalConversion: '<S84>/ConcatBufferAtVector ConcatenateIn2' incorporates:
   *  Sum: '<S84>/Sum of Elements1'
   */
  rtb_DataTypeConversion[1] = rtb_Product1;

  /* Gain: '<S84>/Gain2' incorporates:
   *  Sum: '<S84>/Sum'
   *  Sum: '<S84>/Sum of Elements'
   *  Sum: '<S84>/Sum of Elements1'
   */
  rtb_DataTypeConversion[2] = (rtb_SumofElements + rtb_Product1) * 0.5;

  /* Update for DiscreteIntegrator: '<S84>/Discrete-Time Integrator' */
  Plant_DW.DiscreteTimeIntegrator_DSTATE_p[0] += rtb_TrigonometricFunction1_id_2;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_p[1] += rtb_TrigonometricFunction1_id_1;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_p[2] += rtb_TrigonometricFunction1_id_0;
  Plant_DW.DiscreteTimeIntegrator_DSTATE_p[3] += rtb_Product2_e;

  /* End of Outputs for SubSystem: '<S82>/Vibration_Model' */

  /* Switch: '<S82>/Switch' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<S84>/Gain4'
   *  Product: '<S84>/Divide'
   *  Product: '<S86>/Product1'
   *  SignalConversion: '<S86>/ConcatBufferAtVector Concatenate1In1'
   *  SignalConversion: '<S86>/ConcatBufferAtVector Concatenate1In2'
   *  SignalConversion: '<S86>/ConcatBufferAtVector Concatenate1In3'
   *  Sum: '<S82>/Sum'
   *  Sum: '<S86>/Sum'
   */
  for (i = 0; i < 3; i++) {
    /* Outputs for Atomic SubSystem: '<S82>/Vibration_Model' */
    rtb_Sum_b[i] = (real32_T)(((Plant_Y.Extended_States.M_BO[i + 3] *
      Plant_Y.Plant_States.acc_y_O + Plant_Y.Extended_States.M_BO[i] *
      Plant_Y.Plant_States.acc_x_O) + Plant_Y.Extended_States.M_BO[i + 6] *
      (Plant_Y.Plant_States.acc_z_O - 9.80665F)) + rtb_DataTypeConversion[i] /
      4.0 * Plant_ConstP.Gain4_Gain[i]);

    /* End of Outputs for SubSystem: '<S82>/Vibration_Model' */
  }

  /* End of Switch: '<S82>/Switch' */

  /* Sum: '<S90>/Sum' incorporates:
   *  Product: '<S90>/Product'
   */
  for (i = 0; i < 3; i++) {
    rtb_act_force[i] = (Plant_ConstB.Add_m[i + 3] * rtb_Sum_b[1] +
                        Plant_ConstB.Add_m[i] * rtb_Sum_b[0]) +
      Plant_ConstB.Add_m[i + 6] * rtb_Sum_b[2];
  }

  /* End of Sum: '<S90>/Sum' */

  /* DiscreteIntegrator: '<S89>/Discrete-Time Integrator5' */
  if (Plant_DW.DiscreteTimeIntegrator5_IC_LO_j != 0) {
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[0] = rtb_act_force[0];
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[1] = rtb_act_force[1];
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[2] = rtb_act_force[2];
  }

  /* Outport: '<Root>/IMU' incorporates:
   *  BusAssignment: '<S79>/Bus Assignment'
   *  Memory: '<S53>/Memory1'
   */
  Plant_Y.IMU.timestamp = Plant_DW.Memory1_PreviousInput;
  Plant_Y.IMU.gyr_x = rtb_Add_jo[0];
  Plant_Y.IMU.gyr_y = rtb_Add_jo[1];
  Plant_Y.IMU.gyr_z = rtb_Add_jo[2];

  /* Update for DiscreteIntegrator: '<S100>/Discrete-Time Integrator5' */
  Plant_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;

  /* Update for DiscreteIntegrator: '<S89>/Discrete-Time Integrator5' */
  Plant_DW.DiscreteTimeIntegrator5_IC_LO_j = 0U;

  /* End of Outputs for SubSystem: '<S5>/Sensor_IMU' */

  /* Outputs for Atomic SubSystem: '<S5>/Sensor_MAG' */
  /* Gain: '<S108>/rad_to_index' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S108>/TmpSignal ConversionAtrad_to_indexInport1'
   */
  rtb_SumofElements = fmod(floor(5.7295779513082321 * Plant_Y.Plant_States.lat),
    4.294967296E+9);

  /* Sum: '<S108>/Add' incorporates:
   *  Gain: '<S108>/rad_to_index'
   */
  i = (rtb_SumofElements < 0.0 ? -(int32_T)(uint32_T)-rtb_SumofElements :
       (int32_T)(uint32_T)rtb_SumofElements) + 8;

  /* Saturate: '<S108>/Saturation1' */
  if (i > 16) {
    i = 16;
  } else {
    if (i < 0) {
      i = 0;
    }
  }

  /* Gain: '<S108>/rad_to_index' incorporates:
   *  Delay: '<Root>/Delay'
   *  SignalConversion: '<S108>/TmpSignal ConversionAtrad_to_indexInport1'
   */
  rtb_SumofElements = fmod(floor(5.7295779513082321 * Plant_Y.Plant_States.lon),
    4.294967296E+9);

  /* Sum: '<S108>/Add' incorporates:
   *  Gain: '<S108>/rad_to_index'
   */
  rtb_Saturation1_idx_1 = (rtb_SumofElements < 0.0 ? -(int32_T)(uint32_T)
    -rtb_SumofElements : (int32_T)(uint32_T)rtb_SumofElements) + 18;

  /* Saturate: '<S108>/Saturation1' */
  if (rtb_Saturation1_idx_1 > 36) {
    rtb_Saturation1_idx_1 = 36;
  } else {
    if (rtb_Saturation1_idx_1 < 0) {
      rtb_Saturation1_idx_1 = 0;
    }
  }

  /* LookupNDDirect: '<S108>/Declination_Lookup_Table' incorporates:
   *  LookupNDDirect: '<S108>/Inclination_Lookup_Table'
   *  LookupNDDirect: '<S108>/Magnitude_Lookup_Table'
   *
   * About '<S108>/Declination_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   *
   * About '<S108>/Inclination_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   *
   * About '<S108>/Magnitude_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  i += rtb_Saturation1_idx_1 * 17;

  /* Gain: '<S109>/Gain1' incorporates:
   *  LookupNDDirect: '<S108>/Declination_Lookup_Table'
   *
   * About '<S108>/Declination_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  rtb_Magnitude_Lookup_Table = Plant_ConstP.Declination_Lookup_Table_table[i] *
    0.0174532924F;

  /* Trigonometry: '<S111>/Trigonometric Function1' incorporates:
   *  Trigonometry: '<S111>/Trigonometric Function3'
   */
  rtb_Gain_g2 = arm_cos_f32(rtb_Magnitude_Lookup_Table);
  rtb_VectorConcatenate_f[0] = rtb_Gain_g2;

  /* Trigonometry: '<S111>/Trigonometric Function' incorporates:
   *  Trigonometry: '<S111>/Trigonometric Function2'
   */
  rtb_Product2_e = arm_sin_f32(rtb_Magnitude_Lookup_Table);
  rtb_VectorConcatenate_f[1] = rtb_Product2_e;

  /* SignalConversion: '<S111>/ConcatBufferAtVector Concatenate1In3' incorporates:
   *  Constant: '<S111>/Constant3'
   */
  rtb_VectorConcatenate_f[2] = 0.0F;

  /* Gain: '<S111>/Gain' */
  rtb_VectorConcatenate_f[3] = -rtb_Product2_e;

  /* Trigonometry: '<S111>/Trigonometric Function3' */
  rtb_VectorConcatenate_f[4] = rtb_Gain_g2;

  /* SignalConversion: '<S111>/ConcatBufferAtVector Concatenate2In3' incorporates:
   *  Constant: '<S111>/Constant4'
   */
  rtb_VectorConcatenate_f[5] = 0.0F;

  /* Gain: '<S109>/Gain' incorporates:
   *  LookupNDDirect: '<S108>/Inclination_Lookup_Table'
   *
   * About '<S108>/Inclination_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  rtb_Magnitude_Lookup_Table = Plant_ConstP.Inclination_Lookup_Table_table[i] *
    -0.0174532924F;

  /* Trigonometry: '<S110>/Trigonometric Function3' incorporates:
   *  Trigonometry: '<S110>/Trigonometric Function1'
   */
  rtb_Add_c = arm_cos_f32(rtb_Magnitude_Lookup_Table);
  rtb_VectorConcatenate_k[0] = rtb_Add_c;

  /* SignalConversion: '<S110>/ConcatBufferAtVector Concatenate2In2' incorporates:
   *  Constant: '<S110>/Constant4'
   */
  rtb_VectorConcatenate_k[1] = 0.0F;

  /* Trigonometry: '<S110>/Trigonometric Function2' incorporates:
   *  Trigonometry: '<S110>/Trigonometric Function'
   */
  rtb_Magnitude_Lookup_Table = arm_sin_f32(rtb_Magnitude_Lookup_Table);

  /* Gain: '<S110>/Gain' incorporates:
   *  Trigonometry: '<S110>/Trigonometric Function2'
   */
  rtb_VectorConcatenate_k[2] = -rtb_Magnitude_Lookup_Table;

  /* End of Outputs for SubSystem: '<S5>/Sensor_MAG' */

  /* Outputs for Atomic SubSystem: '<S5>/Sensor_IMU' */
  /* Saturate: '<S83>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S89>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[0] > 78.4532F) {
    rtb_Product2_e = 78.4532F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[0] < -78.4532F) {
    rtb_Product2_e = -78.4532F;
  } else {
    rtb_Product2_e = Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[0];
  }

  /* Update for DiscreteIntegrator: '<S100>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S100>/Gain'
   *  Sum: '<S100>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTATE[0] += (rtb_RandomSource[0] -
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[0]) * 314.159271F * 0.002F;

  /* Update for DiscreteIntegrator: '<S89>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S89>/Gain'
   *  Sum: '<S89>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[0] += (rtb_act_force[0] -
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[0]) * 314.159271F * 0.002F;

  /* End of Outputs for SubSystem: '<S5>/Sensor_IMU' */

  /* Outputs for Atomic SubSystem: '<S5>/Sensor_MAG' */
  /* SignalConversion: '<S111>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_f[6] = Plant_ConstB.VectorConcatenate3[0];

  /* SignalConversion: '<S110>/ConcatBufferAtVector ConcatenateIn2' */
  rtb_VectorConcatenate_k[3] = Plant_ConstB.VectorConcatenate3_a[0];

  /* End of Outputs for SubSystem: '<S5>/Sensor_MAG' */

  /* Outputs for Atomic SubSystem: '<S5>/Sensor_IMU' */
  /* Saturate: '<S83>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S89>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[1] > 78.4532F) {
    rtb_Gain_g2 = 78.4532F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[1] < -78.4532F) {
    rtb_Gain_g2 = -78.4532F;
  } else {
    rtb_Gain_g2 = Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[1];
  }

  /* Update for DiscreteIntegrator: '<S100>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S100>/Gain'
   *  Sum: '<S100>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTATE[1] += (rtb_RandomSource[1] -
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[1]) * 314.159271F * 0.002F;

  /* Update for DiscreteIntegrator: '<S89>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S89>/Gain'
   *  Sum: '<S89>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[1] += (rtb_act_force[1] -
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[1]) * 314.159271F * 0.002F;

  /* End of Outputs for SubSystem: '<S5>/Sensor_IMU' */

  /* Outputs for Atomic SubSystem: '<S5>/Sensor_MAG' */
  /* SignalConversion: '<S111>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_f[7] = Plant_ConstB.VectorConcatenate3[1];

  /* SignalConversion: '<S110>/ConcatBufferAtVector ConcatenateIn2' */
  rtb_VectorConcatenate_k[4] = Plant_ConstB.VectorConcatenate3_a[1];

  /* End of Outputs for SubSystem: '<S5>/Sensor_MAG' */

  /* Outputs for Atomic SubSystem: '<S5>/Sensor_IMU' */
  /* Saturate: '<S83>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S89>/Discrete-Time Integrator5'
   */
  if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[2] > 78.4532F) {
    rtb_torque_B_Nm_idx_2 = 78.4532F;
  } else if (Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[2] < -78.4532F) {
    rtb_torque_B_Nm_idx_2 = -78.4532F;
  } else {
    rtb_torque_B_Nm_idx_2 = Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[2];
  }

  /* Update for DiscreteIntegrator: '<S100>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S100>/Gain'
   *  Sum: '<S100>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTATE[2] += (rtb_RandomSource[2] -
    Plant_DW.DiscreteTimeIntegrator5_DSTATE[2]) * 314.159271F * 0.002F;

  /* Update for DiscreteIntegrator: '<S89>/Discrete-Time Integrator5' incorporates:
   *  Gain: '<S89>/Gain'
   *  Sum: '<S89>/Sum5'
   */
  Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[2] += (rtb_act_force[2] -
    Plant_DW.DiscreteTimeIntegrator5_DSTAT_c[2]) * 314.159271F * 0.002F;

  /* End of Outputs for SubSystem: '<S5>/Sensor_IMU' */

  /* Outputs for Atomic SubSystem: '<S5>/Sensor_MAG' */
  /* SignalConversion: '<S111>/ConcatBufferAtVector ConcatenateIn3' */
  rtb_VectorConcatenate_f[8] = Plant_ConstB.VectorConcatenate3[2];

  /* SignalConversion: '<S110>/ConcatBufferAtVector ConcatenateIn2' */
  rtb_VectorConcatenate_k[5] = Plant_ConstB.VectorConcatenate3_a[2];

  /* Trigonometry: '<S110>/Trigonometric Function' */
  rtb_VectorConcatenate_k[6] = rtb_Magnitude_Lookup_Table;

  /* SignalConversion: '<S110>/ConcatBufferAtVector Concatenate1In2' incorporates:
   *  Constant: '<S110>/Constant3'
   */
  rtb_VectorConcatenate_k[7] = 0.0F;

  /* Trigonometry: '<S110>/Trigonometric Function1' */
  rtb_VectorConcatenate_k[8] = rtb_Add_c;

  /* Gain: '<S109>/toGauss' incorporates:
   *  LookupNDDirect: '<S108>/Magnitude_Lookup_Table'
   *
   * About '<S108>/Magnitude_Lookup_Table':
   *  2-dimensional Direct Look-Up returning a Scalar,
   */
  rtb_Add_c = Plant_ConstP.Magnitude_Lookup_Table_table[i] * 0.01F;

  /* Product: '<S109>/Multiply1' incorporates:
   *  Product: '<S109>/Multiply'
   */
  for (i = 0; i < 3; i++) {
    rtb_Sum_nh[i] = rtb_VectorConcatenate_k[i] * rtb_Add_c;
  }

  /* End of Product: '<S109>/Multiply1' */

  /* Product: '<S109>/Multiply2' */
  for (i = 0; i < 3; i++) {
    rtb_Add_jo[i] = rtb_VectorConcatenate_f[i + 6] * rtb_Sum_nh[2] +
      (rtb_VectorConcatenate_f[i + 3] * rtb_Sum_nh[1] +
       rtb_VectorConcatenate_f[i] * rtb_Sum_nh[0]);
  }

  /* End of Product: '<S109>/Multiply2' */

  /* Product: '<S106>/Product' incorporates:
   *  Delay: '<Root>/Delay'
   */
  for (i = 0; i < 3; i++) {
    rtb_Sum_nh[i] = Plant_Y.Extended_States.M_BO[i + 6] * rtb_Add_jo[2] +
      (Plant_Y.Extended_States.M_BO[i + 3] * rtb_Add_jo[1] +
       Plant_Y.Extended_States.M_BO[i] * rtb_Add_jo[0]);
  }

  /* End of Product: '<S106>/Product' */
  for (i = 0; i < 3; i++) {
    /* Sum: '<S112>/Sum' incorporates:
     *  Product: '<S112>/Product'
     */
    rtb_Add_c = (Plant_ConstB.Add[i + 3] * rtb_Sum_nh[1] + Plant_ConstB.Add[i] *
                 rtb_Sum_nh[0]) + Plant_ConstB.Add[i + 6] * rtb_Sum_nh[2];

    /* Saturate: '<S107>/Saturation' incorporates:
     *  Sum: '<S112>/Sum'
     */
    if (rtb_Add_c > 4.0F) {
      rtb_Add_jo[i] = 4.0F;
    } else if (rtb_Add_c < -4.0F) {
      rtb_Add_jo[i] = -4.0F;
    } else {
      rtb_Add_jo[i] = rtb_Add_c;
    }

    /* End of Saturate: '<S107>/Saturation' */
  }

  /* S-Function (sdsprandsrc2): '<S113>/Random Source' */
  RandSrc_GZ_R(rtb_Sum_nh, &Plant_ConstP.pooled14, 1,
               Plant_ConstP.RandomSource_VarianceRTP_a, 3,
               Plant_DW.RandomSource_STATE_DWORK, 3, 1);

  /* Sum: '<S107>/Add' */
  rtb_Add_jo[0] += rtb_Sum_nh[0];
  rtb_Add_jo[1] += rtb_Sum_nh[1];

  /* BusAssignment: '<S103>/Bus Assignment' incorporates:
   *  Memory: '<S53>/Memory1'
   *  Sum: '<S107>/Add'
   */
  rtb_BusAssignment_o.timestamp = Plant_DW.Memory1_PreviousInput;
  rtb_BusAssignment_o.mag_x = rtb_Add_jo[0];
  rtb_BusAssignment_o.mag_y = rtb_Add_jo[1];
  rtb_BusAssignment_o.mag_z = rtb_Add_jo[2] + rtb_Sum_nh[2];

  /* RateTransition: '<S103>/Rate Transition' */
  if (Plant_M->Timing.TaskCounters.TID[1] == 0) {
    Plant_B.RateTransition_b = rtb_BusAssignment_o;
  }

  /* End of RateTransition: '<S103>/Rate Transition' */
  /* End of Outputs for SubSystem: '<S5>/Sensor_MAG' */

  /* Update for Memory: '<S53>/Memory1' incorporates:
   *  Constant: '<S53>/dt'
   *  Sum: '<S53>/Sum'
   */
  Plant_DW.Memory1_PreviousInput += PLANT_EXPORT.period;

  /* Outputs for Atomic SubSystem: '<S5>/Sensor_IMU' */
  /* Outport: '<Root>/IMU' incorporates:
   *  Sum: '<S83>/Sum'
   */
  Plant_Y.IMU.acc_x = rtb_Product2_e + rtb_RandomSource_f[0];
  Plant_Y.IMU.acc_y = rtb_Gain_g2 + rtb_RandomSource_f[1];
  Plant_Y.IMU.acc_z = rtb_torque_B_Nm_idx_2 + rtb_RandomSource_f[2];

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
    /* InitializeConditions for DiscreteIntegrator: '<S27>/Discrete-Time Integrator' */
    Plant_DW.DiscreteTimeIntegrator_IC_LOADI = 1U;
    Plant_DW.DiscreteTimeIntegrator_PrevRese = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S21>/Discrete-Time Integrator' */
    Plant_DW.DiscreteTimeIntegrator_PrevRe_c = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' */
    Plant_DW.DiscreteTimeIntegrator_PrevRe_p = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S22>/Discrete-Time Integrator1' */
    Plant_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
    Plant_DW.DiscreteTimeIntegrator1_PrevRes = 0;

    /* End of SystemInitialize for SubSystem: '<Root>/Kinematic_Equation' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Bus_Constructor' */
    /* InitializeConditions for Delay: '<S10>/Delay1' */
    Plant_DW.icLoad = 1U;

    /* End of SystemInitialize for SubSystem: '<Root>/Bus_Constructor' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Sensor_Model' */
    /* SystemInitialize for Atomic SubSystem: '<S5>/Sensor_Barometer' */
    /* InitializeConditions for S-Function (sdsprandsrc2): '<S64>/Random Source' */
    RandomSource_SEED_DWORK_k = 91337U;
    RandSrcInitState_GZ(&RandomSource_SEED_DWORK_k,
                        Plant_DW.RandomSource_STATE_DWORK_b, 1);

    /* End of SystemInitialize for SubSystem: '<S5>/Sensor_Barometer' */

    /* SystemInitialize for Atomic SubSystem: '<S5>/Sensor_GPS' */
    /* InitializeConditions for S-Function (sdsprandsrc2): '<S73>/Random Source' */
    RandSrcCreateSeeds_32(63235U, Plant_DW.RandomSource_SEED_DWORK_m, 3);
    RandSrcInitState_GZ(Plant_DW.RandomSource_SEED_DWORK_m,
                        Plant_DW.RandomSource_STATE_DWORK_l, 3);

    /* InitializeConditions for DiscreteFir: '<S75>/Discrete FIR Filter' */
    Plant_DW.DiscreteFIRFilter_states[0] = 0.0;
    Plant_DW.DiscreteFIRFilter_states[1] = 0.0;
    Plant_DW.DiscreteFIRFilter_states[2] = 0.0;

    /* InitializeConditions for S-Function (sdsprandsrc2): '<S73>/Random Source1' */
    RandSrcCreateSeeds_32(9754U, Plant_DW.RandomSource1_SEED_DWORK, 3);
    RandSrcInitState_GZ(Plant_DW.RandomSource1_SEED_DWORK,
                        Plant_DW.RandomSource1_STATE_DWORK, 3);

    /* InitializeConditions for DiscreteFir: '<S76>/Discrete FIR Filter' */
    Plant_DW.DiscreteFIRFilter_states_f[0] = 0.0F;
    Plant_DW.DiscreteFIRFilter_states_f[1] = 0.0F;
    Plant_DW.DiscreteFIRFilter_states_f[2] = 0.0F;

    /* End of SystemInitialize for SubSystem: '<S5>/Sensor_GPS' */

    /* SystemInitialize for Atomic SubSystem: '<S5>/Sensor_IMU' */
    /* InitializeConditions for DiscreteIntegrator: '<S100>/Discrete-Time Integrator5' */
    Plant_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;

    /* InitializeConditions for S-Function (sdsprandsrc2): '<S91>/Random Source' */
    RandSrcCreateSeeds_32(90579U, Plant_DW.RandomSource_SEED_DWORK_f, 3);
    RandSrcInitState_GZ(Plant_DW.RandomSource_SEED_DWORK_f,
                        Plant_DW.RandomSource_STATE_DWORK_k, 3);

    /* InitializeConditions for S-Function (sdsprandsrc2): '<S102>/Random Source' */
    RandSrcCreateSeeds_32(81472U, Plant_DW.RandomSource_SEED_DWORK_n, 3);
    RandSrcInitState_GZ(Plant_DW.RandomSource_SEED_DWORK_n,
                        Plant_DW.RandomSource_STATE_DWORK_h, 3);

    /* InitializeConditions for DiscreteIntegrator: '<S89>/Discrete-Time Integrator5' */
    Plant_DW.DiscreteTimeIntegrator5_IC_LO_j = 1U;

    /* End of SystemInitialize for SubSystem: '<S5>/Sensor_IMU' */

    /* SystemInitialize for Atomic SubSystem: '<S5>/Sensor_MAG' */
    /* InitializeConditions for S-Function (sdsprandsrc2): '<S113>/Random Source' */
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
