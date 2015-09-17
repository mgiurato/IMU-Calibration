/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sersin_data.c
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

/* Block parameters (auto storage) */
P_sersin_T sersin_P = {
  /*  Mask Parameter: RepeatingSequence2_rep_seq_y
   * Referenced by: '<S7>/Look-Up Table1'
   */
  { 90.0, 90.0, -90.0, -90.0, 0.0, 0.0, 90.0, 90.0, 0.0, 0.0 },

  /*  Mask Parameter: RepeatingSequence1_rep_seq_y
   * Referenced by: '<S6>/Look-Up Table1'
   */
  { -180.0, -180.0, 0.0, 0.0, -90.0, -90.0, 90.0, 90.0, 0.0, 0.0, -90.0, -90.0,
    90.0, 90.0, 0.0, 0.0 },

  /*  Mask Parameter: RepeatingSequence1_rep_seq_y_h
   * Referenced by: '<S4>/Look-Up Table1'
   */
  { -90.0, -90.0, -45.0, -45.0, 0.0, 0.0, 45.0, 45.0, 90.0, 90.0, 45.0, 45.0,
    0.0, 0.0, -45.0, -45.0, -90.0 },

  /*  Mask Parameter: RepeatingSequence2_rep_seq_y_o
   * Referenced by: '<S5>/Look-Up Table1'
   */
  { 180.0, 180.0, 135.0, 135.0, 90.0, 90.0, 45.0, 45.0, 0.0, 0.0, -45.0, -45.0,
    -90.0, -90.0, -135.0, -135.0, -180.0, -180.0 },
  9U,                                  /* Mask Parameter: ServoWrite_pinNumber
                                        * Referenced by: '<S9>/Servo Write'
                                        */
  10U,                                 /* Mask Parameter: ServoWrite_pinNumber_f
                                        * Referenced by: '<S10>/Servo Write'
                                        */
  11U,                                 /* Mask Parameter: ServoWrite_pinNumber_n
                                        * Referenced by: '<S11>/Servo Write'
                                        */
  72.0,                                /* Expression: 72
                                        * Referenced by: '<Root>/Switch'
                                        */

  /*  Expression: [0 0 0]
   * Referenced by: '<Root>/Constant'
   */
  { 0.0, 0.0, 0.0 },
  100.0,                               /* Expression: period
                                        * Referenced by: '<S7>/Constant'
                                        */

  /*  Expression: rep_seq_t - min(rep_seq_t)
   * Referenced by: '<S7>/Look-Up Table1'
   */
  { 0.0, 76.0, 77.0, 78.0, 79.0, 90.0, 91.0, 96.0, 97.0, 100.0 },
  100.0,                               /* Expression: period
                                        * Referenced by: '<S6>/Constant'
                                        */

  /*  Expression: rep_seq_t - min(rep_seq_t)
   * Referenced by: '<S6>/Look-Up Table1'
   */
  { 0.0, 73.0, 75.0, 80.0, 82.0, 84.0, 85.0, 87.0, 89.0, 90.0, 91.0, 93.0, 94.0,
    96.0, 97.0, 100.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Constant'
                                        */
  16.0,                                /* Expression: period
                                        * Referenced by: '<S4>/Constant'
                                        */

  /*  Expression: rep_seq_t - min(rep_seq_t)
   * Referenced by: '<S4>/Look-Up Table1'
   */
  { 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0,
    14.0, 15.0, 16.0 },
  72.0,                                /* Expression: period
                                        * Referenced by: '<S5>/Constant'
                                        */

  /*  Expression: rep_seq_t - min(rep_seq_t)
   * Referenced by: '<S5>/Look-Up Table1'
   */
  { 0.0, 7.0, 8.0, 15.0, 16.0, 23.0, 24.0, 31.0, 32.0, 39.0, 40.0, 47.0, 48.0,
    55.0, 56.0, 63.0, 64.0, 72.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<Root>/Switch1'
                                        */
  90.0,                                /* Expression: 90
                                        * Referenced by: '<S3>/Saturation'
                                        */
  -90.0,                               /* Expression: -90
                                        * Referenced by: '<S3>/Saturation'
                                        */
  0.58333333333333337,                 /* Expression: (130-25)/180
                                        * Referenced by: '<S3>/Gain'
                                        */
  90.0,                                /* Expression: 90
                                        * Referenced by: '<S3>/Bias'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S3>/Saturation1'
                                        */
  -180.0,                              /* Expression: -180
                                        * Referenced by: '<S3>/Saturation1'
                                        */
  0.58333333333333337,                 /* Expression: (130-25)/180
                                        * Referenced by: '<S3>/Gain3'
                                        */
  0.50485436893203883,                 /* Expression: 52/103
                                        * Referenced by: '<S3>/Gain1'
                                        */
  89.0,                                /* Expression: 89
                                        * Referenced by: '<S3>/Bias1'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<S3>/Saturation2'
                                        */
  -180.0,                              /* Expression: -180
                                        * Referenced by: '<S3>/Saturation2'
                                        */
  0.44444444444444442,                 /* Expression: (115-35)/180
                                        * Referenced by: '<S3>/Gain4'
                                        */
  0.62765957446808507,                 /* Expression: 59/94
                                        * Referenced by: '<S3>/Gain2'
                                        */
  90.0,                                /* Expression: 90
                                        * Referenced by: '<S3>/Bias2'
                                        */
  0U,                                  /* Computed Parameter: ServoWrite_p1
                                        * Referenced by: '<S9>/Servo Write'
                                        */
  1U,                                  /* Computed Parameter: ServoWrite_p1_e
                                        * Referenced by: '<S10>/Servo Write'
                                        */
  2U                                   /* Computed Parameter: ServoWrite_p1_d
                                        * Referenced by: '<S11>/Servo Write'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
