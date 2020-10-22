/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Pacemaker.h
 *
 * Code generated for Simulink model 'Pacemaker'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu Oct 22 19:30:57 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Pacemaker_h_
#define RTW_HEADER_Pacemaker_h_
#include <stddef.h>
#ifndef Pacemaker_COMMON_INCLUDES_
# define Pacemaker_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_digitalIO.h"
#endif                                 /* Pacemaker_COMMON_INCLUDES_ */

#include "Pacemaker_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  boolean_T DigitalRead;               /* '<S2>/Digital Read' */
  boolean_T R_LED;                     /* '<Root>/Chart' */
  boolean_T B_LED;                     /* '<Root>/Chart' */
  boolean_T senseSwitch;               /* '<Root>/Chart' */
} B_Pacemaker_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_DigitalRead_Pacem_T obj; /* '<S2>/Digital Read' */
  freedomk64f_DigitalRead_Pacem_T obj_n;/* '<S2>/Digital Read1' */
  freedomk64f_DigitalWrite_Pace_T obj_o;/* '<S3>/Digital Write' */
  freedomk64f_DigitalWrite_Pace_T obj_p;/* '<S3>/Digital Write4' */
  freedomk64f_DigitalWrite_Pace_T obj_nc;/* '<S3>/Digital Write1' */
  freedomk64f_DigitalWrite_Pace_T obj_e;/* '<S3>/Digital Write2' */
  freedomk64f_DigitalWrite_Pace_T obj_pz;/* '<S3>/Digital Write3' */
  int32_T sfEvent;                     /* '<Root>/Chart' */
  uint8_T is_active_c2_Pacemaker;      /* '<Root>/Chart' */
  uint8_T is_c2_Pacemaker;             /* '<Root>/Chart' */
  uint8_T is_Sense;                    /* '<Root>/Chart' */
  uint8_T is_Inhibit;                  /* '<Root>/Chart' */
  uint8_T is_Pace;                     /* '<Root>/Chart' */
  uint8_T temporalCounter_i1;          /* '<Root>/Chart' */
} DW_Pacemaker_T;

/* Parameters (default storage) */
struct P_Pacemaker_T_ {
  real_T DigitalRead1_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<S2>/Digital Read1'
                                        */
  real_T DigitalRead_SampleTime;       /* Expression: SampleTime
                                        * Referenced by: '<S2>/Digital Read'
                                        */
  real_T Constant1_Value;              /* Expression: 20
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S3>/Constant'
                                        */
  Activity Constant2_Value;            /* Expression: Activity.INHIBITED_A
                                        * Referenced by: '<Root>/Constant2'
                                        */
  ChamberPaced Constant_Value_m;       /* Expression: ChamberPaced.ATRIUM_P
                                        * Referenced by: '<Root>/Constant'
                                        */
  ChamberSensed Constant1_Value_f;     /* Expression: ChamberSensed.ATRIUM_S
                                        * Referenced by: '<Root>/Constant1'
                                        */
  uint32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S4>/Gain'
                                        */
  uint32_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S4>/Gain1'
                                        */
  uint32_T Constant3_Value;            /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<Root>/Constant3'
                                        */
  uint32_T Constant4_Value;            /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<Root>/Constant4'
                                        */
  uint32_T Constant5_Value;            /* Computed Parameter: Constant5_Value
                                        * Referenced by: '<Root>/Constant5'
                                        */
  uint32_T Constant6_Value;            /* Computed Parameter: Constant6_Value
                                        * Referenced by: '<Root>/Constant6'
                                        */
  uint32_T Constant7_Value;            /* Computed Parameter: Constant7_Value
                                        * Referenced by: '<Root>/Constant7'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Pacemaker_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_Pacemaker_T Pacemaker_P;

/* Block signals (default storage) */
extern B_Pacemaker_T Pacemaker_B;

/* Block states (default storage) */
extern DW_Pacemaker_T Pacemaker_DW;

/* Model entry point functions */
extern void Pacemaker_initialize(void);
extern void Pacemaker_step(void);
extern void Pacemaker_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Pacemaker_T *const Pacemaker_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion1' : Eliminate redundant data type conversion
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
 * '<Root>' : 'Pacemaker'
 * '<S1>'   : 'Pacemaker/Chart'
 * '<S2>'   : 'Pacemaker/Hardware Input '
 * '<S3>'   : 'Pacemaker/Hardware output'
 * '<S4>'   : 'Pacemaker/Subsystem1'
 */
#endif                                 /* RTW_HEADER_Pacemaker_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
