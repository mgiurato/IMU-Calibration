/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sersin.h
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

#ifndef RTW_HEADER_sersin_h_
#define RTW_HEADER_sersin_h_
#include <float.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef sersin_COMMON_INCLUDES_
# define sersin_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_servowrite_lct.h"
#endif                                 /* sersin_COMMON_INCLUDES_ */

#include "sersin_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

/* Block signals (auto storage) */
typedef struct {
  uint8_T DataTypeConversion;          /* '<S9>/Data Type Conversion' */
  uint8_T DataTypeConversion_e;        /* '<S10>/Data Type Conversion' */
  uint8_T DataTypeConversion_c;        /* '<S11>/Data Type Conversion' */
} B_sersin_T;

/* Parameters (auto storage) */
struct P_sersin_T_ {
  real_T RepeatingSequence2_rep_seq_y[10];/* Mask Parameter: RepeatingSequence2_rep_seq_y
                                           * Referenced by: '<S7>/Look-Up Table1'
                                           */
  real_T RepeatingSequence1_rep_seq_y[16];/* Mask Parameter: RepeatingSequence1_rep_seq_y
                                           * Referenced by: '<S6>/Look-Up Table1'
                                           */
  real_T RepeatingSequence1_rep_seq_y_h[17];/* Mask Parameter: RepeatingSequence1_rep_seq_y_h
                                             * Referenced by: '<S4>/Look-Up Table1'
                                             */
  real_T RepeatingSequence2_rep_seq_y_o[18];/* Mask Parameter: RepeatingSequence2_rep_seq_y_o
                                             * Referenced by: '<S5>/Look-Up Table1'
                                             */
  uint32_T ServoWrite_pinNumber;       /* Mask Parameter: ServoWrite_pinNumber
                                        * Referenced by: '<S9>/Servo Write'
                                        */
  uint32_T ServoWrite_pinNumber_f;     /* Mask Parameter: ServoWrite_pinNumber_f
                                        * Referenced by: '<S10>/Servo Write'
                                        */
  uint32_T ServoWrite_pinNumber_n;     /* Mask Parameter: ServoWrite_pinNumber_n
                                        * Referenced by: '<S11>/Servo Write'
                                        */
  real_T Switch_Threshold;             /* Expression: 72
                                        * Referenced by: '<Root>/Switch'
                                        */
  real_T Constant_Value[3];            /* Expression: [0 0 0]
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant_Value_g;             /* Expression: period
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T LookUpTable1_bp01Data[10];    /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S7>/Look-Up Table1'
                                        */
  real_T Constant_Value_b;             /* Expression: period
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_j[16];  /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S6>/Look-Up Table1'
                                        */
  real_T Constant_Value_f;             /* Expression: 0
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Constant_Value_fw;            /* Expression: period
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_i[17];  /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S4>/Look-Up Table1'
                                        */
  real_T Constant_Value_bc;            /* Expression: period
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_h[18];  /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S5>/Look-Up Table1'
                                        */
  real_T Constant_Value_o;             /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Switch1_Threshold;            /* Expression: 100
                                        * Referenced by: '<Root>/Switch1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 90
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -90
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Gain_Gain;                    /* Expression: (130-25)/180
                                        * Referenced by: '<S3>/Gain'
                                        */
  real_T Bias_Bias;                    /* Expression: 90
                                        * Referenced by: '<S3>/Bias'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 180
                                        * Referenced by: '<S3>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -180
                                        * Referenced by: '<S3>/Saturation1'
                                        */
  real_T Gain3_Gain;                   /* Expression: (130-25)/180
                                        * Referenced by: '<S3>/Gain3'
                                        */
  real_T Gain1_Gain;                   /* Expression: 52/103
                                        * Referenced by: '<S3>/Gain1'
                                        */
  real_T Bias1_Bias;                   /* Expression: 89
                                        * Referenced by: '<S3>/Bias1'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 180
                                        * Referenced by: '<S3>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: -180
                                        * Referenced by: '<S3>/Saturation2'
                                        */
  real_T Gain4_Gain;                   /* Expression: (115-35)/180
                                        * Referenced by: '<S3>/Gain4'
                                        */
  real_T Gain2_Gain;                   /* Expression: 59/94
                                        * Referenced by: '<S3>/Gain2'
                                        */
  real_T Bias2_Bias;                   /* Expression: 90
                                        * Referenced by: '<S3>/Bias2'
                                        */
  uint8_T ServoWrite_p1;               /* Computed Parameter: ServoWrite_p1
                                        * Referenced by: '<S9>/Servo Write'
                                        */
  uint8_T ServoWrite_p1_e;             /* Computed Parameter: ServoWrite_p1_e
                                        * Referenced by: '<S10>/Servo Write'
                                        */
  uint8_T ServoWrite_p1_d;             /* Computed Parameter: ServoWrite_p1_d
                                        * Referenced by: '<S11>/Servo Write'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_sersin_T {
  const char_T * volatile errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_sersin_T sersin_P;

/* Block signals (auto storage) */
extern B_sersin_T sersin_B;

/* Model entry point functions */
extern void sersin_initialize(void);
extern void sersin_output(void);
extern void sersin_update(void);
extern void sersin_terminate(void);

/* Real-time Model object */
extern RT_MODEL_sersin_T *const sersin_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'sersin'
 * '<S1>'   : 'sersin/Accelerometer Magnetometer'
 * '<S2>'   : 'sersin/Gyroscope'
 * '<S3>'   : 'sersin/Subsystem'
 * '<S4>'   : 'sersin/Accelerometer Magnetometer/Repeating Sequence1'
 * '<S5>'   : 'sersin/Accelerometer Magnetometer/Repeating Sequence2'
 * '<S6>'   : 'sersin/Gyroscope/Repeating Sequence1'
 * '<S7>'   : 'sersin/Gyroscope/Repeating Sequence2'
 * '<S8>'   : 'sersin/Gyroscope/Repeating Sequence3'
 * '<S9>'   : 'sersin/Subsystem/Standard Servo Write'
 * '<S10>'  : 'sersin/Subsystem/Standard Servo Write1'
 * '<S11>'  : 'sersin/Subsystem/Standard Servo Write2'
 */
#endif                                 /* RTW_HEADER_sersin_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
