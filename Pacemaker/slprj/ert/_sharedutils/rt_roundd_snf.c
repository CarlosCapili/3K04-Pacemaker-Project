/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: rt_roundd_snf.c
 *
 * Code generated for Simulink model 'Pacemaker'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sat Nov 14 20:43:41 2020
 */

#include "rtwtypes.h"
#include <math.h>
#include "rt_roundd_snf.h"

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

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
