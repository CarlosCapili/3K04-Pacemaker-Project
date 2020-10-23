/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Pacemaker.h
 *
 * Code generated for Simulink model 'Pacemaker'.
 *
 * Model version                  : 1.26
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Fri Oct 23 09:09:05 2020
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
#include "MW_PWM.h"
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
  real_T PACING_REF_PWM;               /* '<Root>/Chart' */
  boolean_T ATR_CMP_DETECT;            /* '<S2>/ATR_CMP_DETECT' */
  boolean_T VENT_CMP_DETECT;           /* '<S2>/VENT_CMP_DETECT' */
  boolean_T Z_ATR_CTRL;                /* '<Root>/Chart' */
  boolean_T Z_VENT_CTRL;               /* '<Root>/Chart' */
  boolean_T ATR_PACE_CTRL;             /* '<Root>/Chart' */
  boolean_T VENT_PACE_CTRL;            /* '<Root>/Chart' */
  boolean_T PACE_GND_CTRL;             /* '<Root>/Chart' */
  boolean_T ATR_GND_CTRL;              /* '<Root>/Chart' */
  boolean_T VENT_GND_CTRL;             /* '<Root>/Chart' */
  boolean_T PACE_CHARGE_CTRL;          /* '<Root>/Chart' */
  boolean_T R_LED;                     /* '<Root>/Chart' */
  boolean_T B_LED;                     /* '<Root>/Chart' */
} B_Pacemaker_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_DigitalRead_Pacem_T obj; /* '<S2>/ATR_CMP_DETECT' */
  freedomk64f_DigitalRead_Pacem_T obj_n;/* '<S2>/VENT_CMP_DETECT' */
  freedomk64f_PWMOutput_Pacemak_T obj_e;/* '<S3>/PACING_REF_PWMOUT' */
  freedomk64f_PWMOutput_Pacemak_T obj_l;/* '<S3>/ATR_CMP_REF_PWM' */
  freedomk64f_PWMOutput_Pacemak_T obj_n0;/* '<S3>/VENT_CMP_REF_PWM' */
  freedomk64f_DigitalWrite_Pace_T obj_p;/* '<S3>/Z_ATR_CTRLOUT' */
  freedomk64f_DigitalWrite_Pace_T obj_o;/* '<S3>/Z_VENT_CTRLOUT' */
  freedomk64f_DigitalWrite_Pace_T obj_nt;/* '<S3>/ATR_PACE_CTRLOUT' */
  freedomk64f_DigitalWrite_Pace_T obj_b;/* '<S3>/VENT_PACE_CTRLOUT' */
  freedomk64f_DigitalWrite_Pace_T obj_j;/* '<S3>/PACE_GND_CTRLOUT' */
  freedomk64f_DigitalWrite_Pace_T obj_ju;/* '<S3>/ATR_GND_CTRLOUT' */
  freedomk64f_DigitalWrite_Pace_T obj_jq;/* '<S3>/VENT_GND_CTRLOUT' */
  freedomk64f_DigitalWrite_Pace_T obj_a;/* '<S3>/PACE_CHARGE_CTRLOUT' */
  freedomk64f_DigitalWrite_Pace_T obj_pp;/* '<S3>/R_LEDOUT' */
  freedomk64f_DigitalWrite_Pace_T obj_py;/* '<S3>/B_LEDOUT' */
  freedomk64f_DigitalWrite_Pace_T obj_pu;/* '<S3>/FRONTEND_CTRL1' */
  int32_T sfEvent;                     /* '<Root>/Chart' */
  uint16_T temporalCounter_i1;         /* '<Root>/Chart' */
  uint8_T is_active_c2_Pacemaker;      /* '<Root>/Chart' */
  uint8_T is_c2_Pacemaker;             /* '<Root>/Chart' */
  uint8_T is_Sense;                    /* '<Root>/Chart' */
  uint8_T is_Default;                  /* '<Root>/Chart' */
  uint8_T is_Atrium;                   /* '<Root>/Chart' */
  uint8_T is_Ventricle;                /* '<Root>/Chart' */
  uint8_T is_Pace;                     /* '<Root>/Chart' */
} DW_Pacemaker_T;

/* Parameters (default storage) */
struct P_Pacemaker_T_ {
  real_T VENT_CMP_DETECT_SampleTime;   /* Expression: SampleTime
                                        * Referenced by: '<S2>/VENT_CMP_DETECT'
                                        */
  real_T ATR_CMP_DETECT_SampleTime;    /* Expression: SampleTime
                                        * Referenced by: '<S2>/ATR_CMP_DETECT'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S3>/Constant2'
                                        */
  Activity Constant_Value;             /* Expression: Activity.INHIBITED_A
                                        * Referenced by: '<Root>/Constant'
                                        */
  Adaptive Constant1_Value;            /* Expression: Adaptive.NONE_AD
                                        * Referenced by: '<Root>/Constant1'
                                        */
  ChamberPaced Constant11_Value;       /* Expression: ChamberPaced.VENTRICLE_P
                                        * Referenced by: '<Root>/Constant11'
                                        */
  ChamberSensed Constant9_Value;       /* Expression: ChamberSensed.VENTRICLE_S
                                        * Referenced by: '<Root>/Constant9'
                                        */
  uint32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S4>/Gain'
                                        */
  uint32_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S4>/Gain1'
                                        */
  uint32_T Constant10_Value;           /* Computed Parameter: Constant10_Value
                                        * Referenced by: '<Root>/Constant10'
                                        */
  uint32_T Constant2_Value_h;          /* Computed Parameter: Constant2_Value_h
                                        * Referenced by: '<Root>/Constant2'
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
  uint32_T Constant8_Value;            /* Computed Parameter: Constant8_Value
                                        * Referenced by: '<Root>/Constant8'
                                        */
  uint32_T Constant12_Value;           /* Computed Parameter: Constant12_Value
                                        * Referenced by: '<Root>/Constant12'
                                        */
  uint32_T Constant13_Value;           /* Computed Parameter: Constant13_Value
                                        * Referenced by: '<Root>/Constant13'
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
