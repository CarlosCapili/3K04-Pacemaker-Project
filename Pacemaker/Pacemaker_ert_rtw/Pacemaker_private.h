/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Pacemaker_private.h
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

#ifndef RTW_HEADER_Pacemaker_private_h_
#define RTW_HEADER_Pacemaker_private_h_
#include "rtwtypes.h"

extern real_T rt_roundd_snf(real_T u);
extern void mul_wide_u32(uint32_T in0, uint32_T in1, uint32_T *ptrOutBitsHi,
  uint32_T *ptrOutBitsLo);
extern uint32_T mul_u32_sat(uint32_T a, uint32_T b);

#endif                                 /* RTW_HEADER_Pacemaker_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
