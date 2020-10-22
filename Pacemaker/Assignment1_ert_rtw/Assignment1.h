/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Assignment1.h
 *
 * Code generated for Simulink model 'Assignment1'.
 *
 * Model version                  : 1.43
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu Oct 22 18:37:16 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Assignment1_h_
#define RTW_HEADER_Assignment1_h_
#include <stddef.h>
#ifndef Assignment1_COMMON_INCLUDES_
# define Assignment1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_PWM.h"
#include "MW_digitalIO.h"
#endif                                 /* Assignment1_COMMON_INCLUDES_ */

#include "Assignment1_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  int8_T PACING_REF_PWM;               /* '<Root>/PACING' */
  boolean_T PACE_CHARGE_CTRL;          /* '<Root>/PACING' */
  boolean_T ATR_GND_CTRL;              /* '<Root>/PACING' */
  boolean_T VENT_GND_CTRL;             /* '<Root>/PACING' */
  boolean_T PACE_GND_CTRL;             /* '<Root>/PACING' */
  boolean_T Z_ATR_CTRL;                /* '<Root>/PACING' */
  boolean_T Z_VENT_CTRL;               /* '<Root>/PACING' */
} B_Assignment1_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_DigitalWrite_Assi_T obj; /* '<Root>/Digital Write' */
  freedomk64f_DigitalWrite_Assi_T obj_n;/* '<Root>/Digital Write1' */
  freedomk64f_DigitalWrite_Assi_T obj_no;/* '<Root>/Digital Write10' */
  freedomk64f_DigitalWrite_Assi_T obj_j;/* '<Root>/Digital Write2' */
  freedomk64f_DigitalWrite_Assi_T obj_m;/* '<Root>/Digital Write3' */
  freedomk64f_DigitalWrite_Assi_T obj_i;/* '<Root>/Digital Write4' */
  freedomk64f_DigitalWrite_Assi_T obj_nv;/* '<Root>/Digital Write5' */
  freedomk64f_DigitalWrite_Assi_T obj_l;/* '<Root>/Digital Write6' */
  freedomk64f_DigitalWrite_Assi_T obj_k;/* '<Root>/Digital Write7' */
  freedomk64f_DigitalWrite_Assi_T obj_e;/* '<Root>/Digital Write9' */
  freedomk64f_PWMOutput_Assignm_T obj_b;/* '<Root>/PWM Output' */
  uint16_T temporalCounter_i1;         /* '<Root>/PACING' */
  uint8_T is_active_c3_Assignment1;    /* '<Root>/PACING' */
  uint8_T is_c3_Assignment1;           /* '<Root>/PACING' */
} DW_Assignment1_T;

/* Real-time Model Data Structure */
struct tag_RTM_Assignment1_T {
  const char_T *errorStatus;
};

/* Block signals (default storage) */
extern B_Assignment1_T Assignment1_B;

/* Block states (default storage) */
extern DW_Assignment1_T Assignment1_DW;

/* Model entry point functions */
extern void Assignment1_initialize(void);
extern void Assignment1_step(void);
extern void Assignment1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Assignment1_T *const Assignment1_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
 * Block '<Root>/Scope10' : Unused code path elimination
 * Block '<Root>/Scope2' : Unused code path elimination
 * Block '<Root>/Scope3' : Unused code path elimination
 * Block '<Root>/Scope4' : Unused code path elimination
 * Block '<Root>/Scope5' : Unused code path elimination
 * Block '<Root>/Scope6' : Unused code path elimination
 * Block '<Root>/Scope7' : Unused code path elimination
 * Block '<Root>/Scope8' : Unused code path elimination
 * Block '<Root>/Scope9' : Unused code path elimination
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
 * '<Root>' : 'Assignment1'
 * '<S1>'   : 'Assignment1/PACING'
 */
#endif                                 /* RTW_HEADER_Assignment1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
