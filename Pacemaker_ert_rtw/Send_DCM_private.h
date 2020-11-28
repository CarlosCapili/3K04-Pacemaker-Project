/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Send_DCM_private.h
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

#ifndef RTW_HEADER_Send_DCM_private_h_
#define RTW_HEADER_Send_DCM_private_h_
#include <string.h>
#ifndef Pacemaker_COMMON_INCLUDES_
# define Pacemaker_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_SCI.h"
#include "MW_digitalIO.h"
#include "MW_AnalogIn.h"
#include "MW_PWM.h"
#include "MW_I2C.h"
#endif                                 /* Pacemaker_COMMON_INCLUDES_ */

extern void Send_DCM_Init(void);
extern void Send_DCM_Term(void);

#endif                                 /* RTW_HEADER_Send_DCM_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
