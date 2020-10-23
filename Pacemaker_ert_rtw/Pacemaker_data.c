/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Pacemaker_data.c
 *
 * Code generated for Simulink model 'Pacemaker'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu Oct 22 20:26:34 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Pacemaker.h"
#include "Pacemaker_private.h"

/* Block parameters (default storage) */
P_Pacemaker_T Pacemaker_P = {
  /* Expression: SampleTime1
   * Referenced by: '<S2>/Push Button'
   */
  -1.0,

  /* Expression: SampleTime
   * Referenced by: '<S2>/Digital Read1'
   */
  -1.0,

  /* Expression: SampleTime
   * Referenced by: '<S2>/Digital Read'
   */
  -1.0,

  /* Expression: 60
   * Referenced by: '<S3>/Constant1'
   */
  60.0,

  /* Expression: 1
   * Referenced by: '<S3>/Constant'
   */
  1.0,

  /* Expression: Activity.INHIBITED_A
   * Referenced by: '<Root>/Constant2'
   */
  INHIBITED_A,

  /* Expression: ChamberPaced.ATRIUM_P
   * Referenced by: '<Root>/Constant'
   */
  ATRIUM_P,

  /* Expression: ChamberSensed.ATRIUM_S
   * Referenced by: '<Root>/Constant1'
   */
  ATRIUM_S,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S4>/Gain'
   */
  3932160000U,

  /* Computed Parameter: Gain1_Gain
   * Referenced by: '<S4>/Gain1'
   */
  3932160000U,

  /* Computed Parameter: Constant3_Value
   * Referenced by: '<Root>/Constant3'
   */
  1U,

  /* Computed Parameter: Constant4_Value
   * Referenced by: '<Root>/Constant4'
   */
  1U,

  /* Computed Parameter: Constant5_Value
   * Referenced by: '<Root>/Constant5'
   */
  1000U,

  /* Computed Parameter: Constant6_Value
   * Referenced by: '<Root>/Constant6'
   */
  500U,

  /* Computed Parameter: Constant7_Value
   * Referenced by: '<Root>/Constant7'
   */
  1U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
