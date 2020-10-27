/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Pacemaker_data.c
 *
 * Code generated for Simulink model 'Pacemaker'.
 *
 * Model version                  : 1.66
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Oct 27 05:45:09 2020
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
  /* Expression: SampleTime
   * Referenced by: '<S2>/VENT_CMP_DETECT'
   */
  -1.0,

  /* Expression: SampleTime
   * Referenced by: '<S2>/ATR_CMP_DETECT'
   */
  -1.0,

  /* Expression: 60000
   * Referenced by: '<S4>/Gain'
   */
  60000.0,

  /* Expression: 60000
   * Referenced by: '<S4>/Gain1'
   */
  60000.0,

  /* Expression: 1
   * Referenced by: '<S3>/Constant2'
   */
  1.0,

  /* Expression: Activity.INHIBITED_A
   * Referenced by: '<Root>/Constant'
   */
  INHIBITED_A,

  /* Expression: Adaptive.NONE_AD
   * Referenced by: '<Root>/Constant1'
   */
  NONE_AD,

  /* Expression: ChamberPaced.ATRIUM_P
   * Referenced by: '<Root>/Constant11'
   */
  ATRIUM_P,

  /* Expression: ChamberSensed.ATRIUM_S
   * Referenced by: '<Root>/Constant9'
   */
  ATRIUM_S,

  /* Computed Parameter: Constant10_Value
   * Referenced by: '<Root>/Constant10'
   */
  1U,

  /* Computed Parameter: Constant2_Value_h
   * Referenced by: '<Root>/Constant2'
   */
  10U,

  /* Computed Parameter: Constant3_Value
   * Referenced by: '<Root>/Constant3'
   */
  5U,

  /* Computed Parameter: Constant4_Value
   * Referenced by: '<Root>/Constant4'
   */
  60U,

  /* Computed Parameter: Constant5_Value
   * Referenced by: '<Root>/Constant5'
   */
  80U,

  /* Computed Parameter: Constant6_Value
   * Referenced by: '<Root>/Constant6'
   */
  1U,

  /* Computed Parameter: Constant7_Value
   * Referenced by: '<Root>/Constant7'
   */
  1U,

  /* Computed Parameter: Constant8_Value
   * Referenced by: '<Root>/Constant8'
   */
  1U,

  /* Computed Parameter: Constant12_Value
   * Referenced by: '<Root>/Constant12'
   */
  60U,

  /* Computed Parameter: Constant13_Value
   * Referenced by: '<Root>/Constant13'
   */
  60U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
