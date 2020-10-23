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
 * C/C++ source code generated on : Thu Oct 22 20:26:34 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Pacemaker_h_
#define RTW_HEADER_Pacemaker_h_
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef Pacemaker_COMMON_INCLUDES_
# define Pacemaker_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#endif                                 /* Pacemaker_COMMON_INCLUDES_ */

#include "Pacemaker_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  uint64m_T Gain;                      /* '<S4>/Gain' */
  uint64m_T Gain1;                     /* '<S4>/Gain1' */
  uint32_T Constant3;                  /* '<Root>/Constant3' */
  uint32_T Constant4;                  /* '<Root>/Constant4' */
  uint32_T Constant5;                  /* '<Root>/Constant5' */
  uint32_T Constant6;                  /* '<Root>/Constant6' */
  uint32_T Constant7;                  /* '<Root>/Constant7' */
  ChamberSensed Constant1;             /* '<Root>/Constant1' */
  ChamberPaced Constant;               /* '<Root>/Constant' */
  Activity Constant2;                  /* '<Root>/Constant2' */
  boolean_T DataTypeConversion;        /* '<S2>/Data Type Conversion' */
  boolean_T DataTypeConversion1;       /* '<S2>/Data Type Conversion1' */
  boolean_T R_LED;                     /* '<Root>/Chart' */
  boolean_T B_LED;                     /* '<Root>/Chart' */
  boolean_T senseSwitch;               /* '<Root>/Chart' */
} B_Pacemaker_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_DigitalRead_Pacem_T obj; /* '<S2>/Digital Read' */
  freedomk64f_DigitalRead_Pacem_T obj_n;/* '<S2>/Digital Read1' */
  freedomk64f_PushButton_Pacema_T obj_c;/* '<S2>/Push Button' */
  freedomk64f_DigitalWrite_Pace_T obj_o;/* '<S3>/Digital Write' */
  freedomk64f_DigitalWrite_Pace_T obj_p;/* '<S3>/Digital Write4' */
  freedomk64f_DigitalWrite_Pace_T obj_nc;/* '<S3>/FRONTEND_CTRL' */
  freedomk64f_PWMOutput_Pacemak_T obj_l;/* '<S3>/PWM Output' */
  freedomk64f_PWMOutput_Pacemak_T obj_n0;/* '<S3>/PWM Output2' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  int32_T sfEvent;                     /* '<Root>/Chart' */
  uint32_T is_c2_Pacemaker;            /* '<Root>/Chart' */
  uint32_T is_Sense;                   /* '<Root>/Chart' */
  uint32_T is_Inhibit;                 /* '<Root>/Chart' */
  uint32_T is_Pace;                    /* '<Root>/Chart' */
  uint8_T is_active_c2_Pacemaker;      /* '<Root>/Chart' */
  uint8_T temporalCounter_i1;          /* '<Root>/Chart' */
} DW_Pacemaker_T;

/* Parameters (default storage) */
struct P_Pacemaker_T_ {
  real_T PushButton_SampleTime;        /* Expression: SampleTime1
                                        * Referenced by: '<S2>/Push Button'
                                        */
  real_T DigitalRead1_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<S2>/Digital Read1'
                                        */
  real_T DigitalRead_SampleTime;       /* Expression: SampleTime
                                        * Referenced by: '<S2>/Digital Read'
                                        */
  real_T Constant1_Value;              /* Expression: 60
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
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
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
