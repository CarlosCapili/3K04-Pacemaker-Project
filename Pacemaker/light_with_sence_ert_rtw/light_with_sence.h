/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: light_with_sence.h
 *
 * Code generated for Simulink model 'light_with_sence'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu Oct 22 19:26:08 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_light_with_sence_h_
#define RTW_HEADER_light_with_sence_h_
#include <stddef.h>
#ifndef light_with_sence_COMMON_INCLUDES_
# define light_with_sence_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#endif                                 /* light_with_sence_COMMON_INCLUDES_ */

#include "light_with_sence_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_DigitalRead_light_T obj; /* '<Root>/Digital Read' */
  freedomk64f_DigitalWrite_ligh_T obj_n;/* '<Root>/Digital Write1' */
  freedomk64f_DigitalWrite_ligh_T obj_i;/* '<Root>/Digital Write2' */
  freedomk64f_PWMOutput_light_w_T obj_j;/* '<Root>/PWM Output' */
  uint8_T is_active_c3_light_with_sence;/* '<Root>/Chart' */
  uint8_T is_c3_light_with_sence;      /* '<Root>/Chart' */
  uint8_T temporalCounter_i1;          /* '<Root>/Chart' */
} DW_light_with_sence_T;

/* Parameters (default storage) */
struct P_light_with_sence_T_ {
  real_T DigitalRead_SampleTime;       /* Expression: SampleTime
                                        * Referenced by: '<Root>/Digital Read'
                                        */
  real_T Constant_Value;               /* Expression: 60
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_light_with_sence_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_light_with_sence_T light_with_sence_P;

/* Block states (default storage) */
extern DW_light_with_sence_T light_with_sence_DW;

/* Model entry point functions */
extern void light_with_sence_initialize(void);
extern void light_with_sence_step(void);
extern void light_with_sence_terminate(void);

/* Real-time Model object */
extern RT_MODEL_light_with_sence_T *const light_with_sence_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Data Type Conversion' : Eliminate redundant data type conversion
 */

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
 * '<Root>' : 'light_with_sence'
 * '<S1>'   : 'light_with_sence/Chart'
 */
#endif                                 /* RTW_HEADER_light_with_sence_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
