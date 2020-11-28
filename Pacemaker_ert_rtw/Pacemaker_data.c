/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Pacemaker_data.c
 *
 * Code generated for Simulink model 'Pacemaker'.
 *
 * Model version                  : 1.75
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sat Nov 28 14:29:25 2020
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
  /* Mask Parameter: TappedDelay_vinit
   * Referenced by: '<S2>/Tapped Delay'
   */
  0.0F,

  /* Mask Parameter: TappedDelay1_vinit
   * Referenced by: '<S2>/Tapped Delay1'
   */
  0.0F,

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

  /* Expression: SampleTime
   * Referenced by: '<S2>/VentSignalIn'
   */
  -1.0,

  /* Expression: SampleTime
   * Referenced by: '<S2>/AtrSignalIn'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S5>/FXOS8700 6-Axes Sensor'
   */
  -1.0,

  /* Expression: 60000
   * Referenced by: '<S5>/Gain1'
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

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S2>/Gain'
   */
  3.3F,

  /* Computed Parameter: Gain1_Gain_j
   * Referenced by: '<S2>/Gain1'
   */
  3.3F,

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<S4>/Gain2'
   */
  100.0F,

  /* Computed Parameter: Gain3_Gain
   * Referenced by: '<S4>/Gain3'
   */
  100.0F,

  /* Computed Parameter: Gain_Gain_k
   * Referenced by: '<S5>/Gain'
   */
  192U,

  /* Computed Parameter: scaleDown_Gain
   * Referenced by: '<S5>/scaleDown'
   */
  128U,

  /* Computed Parameter: Constant1_Value
   * Referenced by: '<S7>/Constant1'
   */
  0U,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S7>/Constant'
   */
  1U,

  /* Computed Parameter: Constant2_Value_j
   * Referenced by: '<S7>/Constant2'
   */
  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },

  /* Computed Parameter: Switch_Threshold
   * Referenced by: '<S7>/Switch'
   */
  0U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
