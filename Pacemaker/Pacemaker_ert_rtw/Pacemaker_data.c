/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Pacemaker_data.c
 *
 * Code generated for Simulink model 'Pacemaker'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sat Nov 14 20:43:41 2020
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
  /* Expression: -1
   * Referenced by: '<Root>/Serial Receive'
   */
  -1.0,

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

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<S4>/Gain2'
   */
  100.0F
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
