/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sersin.c
 *
 * Code generated for Simulink model 'sersin'.
 *
 * Model version                  : 1.74
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 19 2015)
 * C/C++ source code generated on : Thu Sep 17 17:36:16 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "sersin.h"
#include "sersin_private.h"

/* Block signals (auto storage) */
B_sersin_T sersin_B;

/* Real-time model */
RT_MODEL_sersin_T sersin_M_;
RT_MODEL_sersin_T *const sersin_M = &sersin_M_;
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0UL]) {
    iLeft = 0UL;
    frac = (u0 - bp0[0UL]) / (bp0[1UL] - bp0[0UL]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1UL;
    iLeft = 0UL;
    iRght = maxIndex;
    while (iRght - iLeft > 1UL) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1UL;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1UL] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1UL;
    frac = (u0 - bp0[maxIndex - 1UL]) / (bp0[maxIndex] - bp0[maxIndex - 1UL]);
  }

  /* Interpolation 1-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  return (table[iLeft + 1UL] - table[iLeft]) * frac + table[iLeft];
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T u1_0;
  if (!((!rtIsNaN(u0)) && (!rtIsInf(u0)) && ((!rtIsNaN(u1)) && (!rtIsInf(u1)))))
  {
    y = (rtNaN);
  } else {
    if (u1 < 0.0) {
      u1_0 = ceil(u1);
    } else {
      u1_0 = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != u1_0)) {
      u1_0 = u0 / u1;
      if (fabs(u1_0 - rt_roundd_snf(u1_0)) <= DBL_EPSILON * fabs(u1_0)) {
        y = 0.0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

/* Model output function */
void sersin_output(void)
{
  /* local block i/o variables */
  real_T rtb_Clock;
  real_T rtb_Bias2;
  real_T rtb_LookUpTable1;
  real_T rtb_LookUpTable1_i;
  real_T rtb_LookUpTable1_m;
  real_T rtb_LookUpTable1_h;

  /* Clock: '<Root>/Clock' */
  rtb_Clock = sersin_M->Timing.t[0];

  /* Clock: '<S7>/Clock' */
  rtb_Bias2 = sersin_M->Timing.t[0];

  /* Sum: '<S7>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S7>/startTime'
   */
  rtb_Bias2 -= (0.0);

  /* Math: '<S7>/Math Function' incorporates:
   *  Constant: '<S7>/Constant'
   */
  rtb_Bias2 = rt_remd_snf(rtb_Bias2, sersin_P.Constant_Value_g);

  /* Lookup_n-D: '<S7>/Look-Up Table1' */
  rtb_LookUpTable1 = look1_binlxpw(rtb_Bias2, sersin_P.LookUpTable1_bp01Data,
    sersin_P.RepeatingSequence2_rep_seq_y, 9UL);

  /* Clock: '<S6>/Clock' */
  rtb_Bias2 = sersin_M->Timing.t[0];

  /* Sum: '<S6>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S6>/startTime'
   */
  rtb_Bias2 -= (0.0);

  /* Math: '<S6>/Math Function' incorporates:
   *  Constant: '<S6>/Constant'
   */
  rtb_Bias2 = rt_remd_snf(rtb_Bias2, sersin_P.Constant_Value_b);

  /* Lookup_n-D: '<S6>/Look-Up Table1' */
  rtb_LookUpTable1_i = look1_binlxpw(rtb_Bias2, sersin_P.LookUpTable1_bp01Data_j,
    sersin_P.RepeatingSequence1_rep_seq_y, 15UL);

  /* Clock: '<S4>/Clock' */
  rtb_Bias2 = sersin_M->Timing.t[0];

  /* Sum: '<S4>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S4>/startTime'
   */
  rtb_Bias2 -= (0.0);

  /* Math: '<S4>/Math Function' incorporates:
   *  Constant: '<S4>/Constant'
   */
  rtb_Bias2 = rt_remd_snf(rtb_Bias2, sersin_P.Constant_Value_fw);

  /* Lookup_n-D: '<S4>/Look-Up Table1' */
  rtb_LookUpTable1_m = look1_binlxpw(rtb_Bias2, sersin_P.LookUpTable1_bp01Data_i,
    sersin_P.RepeatingSequence1_rep_seq_y_h, 16UL);

  /* Clock: '<S5>/Clock' */
  rtb_Bias2 = sersin_M->Timing.t[0];

  /* Sum: '<S5>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S5>/startTime'
   */
  rtb_Bias2 -= (0.0);

  /* Math: '<S5>/Math Function' incorporates:
   *  Constant: '<S5>/Constant'
   */
  rtb_Bias2 = rt_remd_snf(rtb_Bias2, sersin_P.Constant_Value_bc);

  /* Lookup_n-D: '<S5>/Look-Up Table1' */
  rtb_LookUpTable1_h = look1_binlxpw(rtb_Bias2, sersin_P.LookUpTable1_bp01Data_h,
    sersin_P.RepeatingSequence2_rep_seq_y_o, 17UL);

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<S1>/Constant'
   *  Switch: '<Root>/Switch'
   */
  if (rtb_Clock > sersin_P.Switch1_Threshold) {
    rtb_LookUpTable1_m = sersin_P.Constant_Value[0];
    rtb_LookUpTable1_h = sersin_P.Constant_Value[1];
    rtb_LookUpTable1 = sersin_P.Constant_Value[2];
  } else if (rtb_Clock > sersin_P.Switch_Threshold) {
    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<S2>/Constant'
     */
    rtb_LookUpTable1_m = rtb_LookUpTable1;
    rtb_LookUpTable1_h = rtb_LookUpTable1_i;
    rtb_LookUpTable1 = sersin_P.Constant_Value_f;
  } else {
    rtb_LookUpTable1 = sersin_P.Constant_Value_o;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Saturate: '<S3>/Saturation' */
  if (rtb_LookUpTable1_m > sersin_P.Saturation_UpperSat) {
    rtb_LookUpTable1_m = sersin_P.Saturation_UpperSat;
  } else {
    if (rtb_LookUpTable1_m < sersin_P.Saturation_LowerSat) {
      rtb_LookUpTable1_m = sersin_P.Saturation_LowerSat;
    }
  }

  /* Bias: '<S3>/Bias' incorporates:
   *  Gain: '<S3>/Gain'
   *  Saturate: '<S3>/Saturation'
   *  UnaryMinus: '<S3>/Unary Minus'
   */
  rtb_Bias2 = sersin_P.Gain_Gain * -rtb_LookUpTable1_m + sersin_P.Bias_Bias;

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  if (rtb_Bias2 < 256.0) {
    if (rtb_Bias2 >= 0.0) {
      sersin_B.DataTypeConversion = (uint8_T)rtb_Bias2;
    } else {
      sersin_B.DataTypeConversion = 0U;
    }
  } else {
    sersin_B.DataTypeConversion = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S9>/Data Type Conversion' */

  /* S-Function (arduinoservowrite_sfcn): '<S9>/Servo Write' */
  MW_servoWrite(sersin_P.ServoWrite_p1, sersin_B.DataTypeConversion);

  /* Saturate: '<S3>/Saturation1' */
  if (rtb_LookUpTable1_h > sersin_P.Saturation1_UpperSat) {
    rtb_LookUpTable1_h = sersin_P.Saturation1_UpperSat;
  } else {
    if (rtb_LookUpTable1_h < sersin_P.Saturation1_LowerSat) {
      rtb_LookUpTable1_h = sersin_P.Saturation1_LowerSat;
    }
  }

  /* Bias: '<S3>/Bias1' incorporates:
   *  Gain: '<S3>/Gain1'
   *  Gain: '<S3>/Gain3'
   *  Saturate: '<S3>/Saturation1'
   */
  rtb_Bias2 = sersin_P.Gain3_Gain * rtb_LookUpTable1_h * sersin_P.Gain1_Gain +
    sersin_P.Bias1_Bias;

  /* DataTypeConversion: '<S10>/Data Type Conversion' */
  if (rtb_Bias2 < 256.0) {
    if (rtb_Bias2 >= 0.0) {
      sersin_B.DataTypeConversion_e = (uint8_T)rtb_Bias2;
    } else {
      sersin_B.DataTypeConversion_e = 0U;
    }
  } else {
    sersin_B.DataTypeConversion_e = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S10>/Data Type Conversion' */

  /* S-Function (arduinoservowrite_sfcn): '<S10>/Servo Write' */
  MW_servoWrite(sersin_P.ServoWrite_p1_e, sersin_B.DataTypeConversion_e);

  /* Saturate: '<S3>/Saturation2' */
  if (rtb_LookUpTable1 > sersin_P.Saturation2_UpperSat) {
    rtb_LookUpTable1 = sersin_P.Saturation2_UpperSat;
  } else {
    if (rtb_LookUpTable1 < sersin_P.Saturation2_LowerSat) {
      rtb_LookUpTable1 = sersin_P.Saturation2_LowerSat;
    }
  }

  /* Bias: '<S3>/Bias2' incorporates:
   *  Gain: '<S3>/Gain2'
   *  Gain: '<S3>/Gain4'
   *  Saturate: '<S3>/Saturation2'
   */
  rtb_Bias2 = sersin_P.Gain4_Gain * rtb_LookUpTable1 * sersin_P.Gain2_Gain +
    sersin_P.Bias2_Bias;

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  if (rtb_Bias2 < 256.0) {
    if (rtb_Bias2 >= 0.0) {
      sersin_B.DataTypeConversion_c = (uint8_T)rtb_Bias2;
    } else {
      sersin_B.DataTypeConversion_c = 0U;
    }
  } else {
    sersin_B.DataTypeConversion_c = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S11>/Data Type Conversion' */

  /* S-Function (arduinoservowrite_sfcn): '<S11>/Servo Write' */
  MW_servoWrite(sersin_P.ServoWrite_p1_d, sersin_B.DataTypeConversion_c);
}

/* Model update function */
void sersin_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  sersin_M->Timing.t[0] =
    (++sersin_M->Timing.clockTick0) * sersin_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    sersin_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void sersin_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)sersin_M, 0,
                sizeof(RT_MODEL_sersin_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&sersin_M->solverInfo, &sersin_M->Timing.simTimeStep);
    rtsiSetTPtr(&sersin_M->solverInfo, &rtmGetTPtr(sersin_M));
    rtsiSetStepSizePtr(&sersin_M->solverInfo, &sersin_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&sersin_M->solverInfo, ((const char_T **)
      (&rtmGetErrorStatus(sersin_M))));
    rtsiSetRTModelPtr(&sersin_M->solverInfo, sersin_M);
  }

  rtsiSetSimTimeStep(&sersin_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&sersin_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(sersin_M, &sersin_M->Timing.tArray[0]);
  sersin_M->Timing.stepSize0 = 0.01;

  /* block I/O */
  (void) memset(((void *) &sersin_B), 0,
                sizeof(B_sersin_T));

  /* Start for S-Function (arduinoservowrite_sfcn): '<S9>/Servo Write' */
  MW_servoAttach(sersin_P.ServoWrite_p1, sersin_P.ServoWrite_pinNumber);

  /* Start for S-Function (arduinoservowrite_sfcn): '<S10>/Servo Write' */
  MW_servoAttach(sersin_P.ServoWrite_p1_e, sersin_P.ServoWrite_pinNumber_f);

  /* Start for S-Function (arduinoservowrite_sfcn): '<S11>/Servo Write' */
  MW_servoAttach(sersin_P.ServoWrite_p1_d, sersin_P.ServoWrite_pinNumber_n);
}

/* Model terminate function */
void sersin_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
