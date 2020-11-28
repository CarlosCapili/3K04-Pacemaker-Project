/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Pacemaker.h
 *
 * Code generated for Simulink model 'Pacemaker'.
 *
 * Model version                  : 1.76
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sat Nov 28 14:35:24 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Pacemaker_h_
#define RTW_HEADER_Pacemaker_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef Pacemaker_COMMON_INCLUDES_
# define Pacemaker_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_SCI.h"
#include "MW_digitalIO.h"
#include "MW_AnalogIn.h"
#include "MW_PWM.h"
#include "MW_I2C.h"
#endif                                 /* Pacemaker_COMMON_INCLUDES_ */

#include "Pacemaker_types.h"

/* Child system includes */
#include "Send_DCM_private.h"
#include "Send_DCM.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Activity_h[50];               /* '<S5>/Chart1' */
  real_T dv[49];
  uint8_T TxDataLocChar[201];
  uint8_T Switch[201];                 /* '<S7>/Switch' */
  real32_T TappedDelay1[25];           /* '<S2>/Tapped Delay1' */
  uint8_T RxData[40];
  uint8_T RxDataLocChar[40];
  MW_AnalogIn_TriggerSource_Type trigger_val;
  uint32_T TxPinLoc;
  uint32_T SCIModuleLoc;
  MW_SCI_StopBits_Type StopBitsValue;
  MW_SCI_Parity_Type ParityValue;
  MW_I2C_Mode_Type ModeType;
  uint32_T i2cname;
  real_T HeartRate;                    /* '<S5>/Chart' */
  real_T SquareRoot;                   /* '<S5>/Square Root' */
  real32_T AtrialAmp;
  real32_T AtrialPulseWidth;
  real32_T AtrialSensitivity;
  real32_T VentricularAmp;
  real32_T VentricularPulseWidth;
  real32_T VentricularSensitivity;
  real32_T TmpLatchAtAtrSignalArrOutport1[25];
  real32_T TmpLatchAtVentSignalArrOutport1[25];
  real32_T AtrialAmp_j;                /* '<Root>/Serial Communication' */
  real32_T AtrialPulseWidth_e;         /* '<Root>/Serial Communication' */
  real32_T VentricularAmp_b;           /* '<Root>/Serial Communication' */
  real32_T VentricularPulseWidth_m;    /* '<Root>/Serial Communication' */
  real32_T AtrialSensitivity_e;        /* '<Root>/Serial Communication' */
  real32_T VentricularSensitivity_i;   /* '<Root>/Serial Communication' */
  int32_T i;
  uint32_T DataTypeConversion4;        /* '<S4>/Data Type Conversion4' */
  uint32_T DataTypeConversion6;        /* '<S4>/Data Type Conversion6' */
  uint32_T PACING_REF_PWM;             /* '<Root>/Chart' */
  real32_T Gain;                       /* '<S2>/Gain' */
  real32_T TappedDelay[25];            /* '<S2>/Tapped Delay' */
  real32_T Gain1;                      /* '<S2>/Gain1' */
  ChamberSensed y2;                    /* '<S4>/MATLAB Function1' */
  ChamberPaced y1;                     /* '<S4>/MATLAB Function1' */
  Activity y3;                         /* '<S4>/MATLAB Function1' */
  uint16_T DataTypeConversion5;        /* '<S4>/Data Type Conversion5' */
  uint16_T DataTypeConversion3;        /* '<S5>/Data Type Conversion3' */
  uint16_T DataTypeConversion7;        /* '<S4>/Data Type Conversion7' */
  uint16_T VRP;
  uint16_T ARP;
  uint16_T PVARP;
  uint16_T FixAVDelay;
  uint16_T VRP_j;                      /* '<Root>/Serial Communication' */
  uint16_T ARP_b;                      /* '<Root>/Serial Communication' */
  uint16_T PVARP_c;                    /* '<Root>/Serial Communication' */
  uint16_T FixAVDelay_e;               /* '<Root>/Serial Communication' */
  uint8_T BytePack1[4];                /* '<S7>/Byte Pack1' */
  uint8_T BytePack2[4];                /* '<S7>/Byte Pack2' */
  uint8_T BytePack3[4];                /* '<S7>/Byte Pack3' */
  uint8_T BytePack4[4];                /* '<S7>/Byte Pack4' */
  uint8_T BytePack8[4];                /* '<S7>/Byte Pack8' */
  uint8_T BytePack9[4];                /* '<S7>/Byte Pack9' */
  uint8_T BytePack[2];                 /* '<S7>/Byte Pack' */
  uint8_T BytePack5[2];                /* '<S7>/Byte Pack5' */
  uint8_T BytePack6[2];                /* '<S7>/Byte Pack6' */
  uint8_T BytePack7[2];                /* '<S7>/Byte Pack7' */
  uint8_T BytePack10[100];             /* '<S7>/Byte Pack10' */
  uint8_T BytePack11[100];             /* '<S7>/Byte Pack11' */
  uint8_T b_SwappedDataBytes[2];
  uint8_T Mode;                        /* '<Root>/Serial Communication' */
  uint8_T LRL;                         /* '<Root>/Serial Communication' */
  uint8_T URL;                         /* '<Root>/Serial Communication' */
  uint8_T MaxSensorRate;               /* '<Root>/Serial Communication' */
  uint8_T ReactionTime;                /* '<Root>/Serial Communication' */
  uint8_T ResponseFactor;              /* '<Root>/Serial Communication' */
  uint8_T RecoveryTime;                /* '<Root>/Serial Communication' */
  uint8_T ActivityThreshold;           /* '<Root>/Serial Communication' */
  uint8_T Type;                        /* '<Root>/Serial Communication' */
  uint8_T b_RegisterValue;
  uint8_T status;
  boolean_T B_LED;                     /* '<Root>/Serial Communication' */
  boolean_T R_LED;                     /* '<Root>/Serial Communication' */
  boolean_T G_LED;                     /* '<Root>/Serial Communication' */
  boolean_T BLUE_LED;                  /* '<S5>/Chart' */
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
  boolean_T R_LED_l;                   /* '<Root>/Chart' */
  boolean_T B_LED_h;                   /* '<Root>/Chart' */
} B_Pacemaker_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_fxos8700_Pacemake_T obj; /* '<S5>/FXOS8700 6-Axes Sensor' */
  freedomk64f_DigitalRead_Pacem_T obj_h;/* '<S2>/ATR_CMP_DETECT' */
  freedomk64f_DigitalRead_Pacem_T obj_l;/* '<S2>/VENT_CMP_DETECT' */
  freedomk64f_AnalogInput_Pacem_T obj_f;/* '<S2>/AtrSignalIn' */
  freedomk64f_AnalogInput_Pacem_T obj_e;/* '<S2>/VentSignalIn' */
  freedomk64f_SCIRead_Pacemaker_T obj_d;/* '<Root>/Serial Receive' */
  freedomk64f_PWMOutput_Pacemak_T obj_m;/* '<S3>/PACING_REF_PWMOUT' */
  freedomk64f_PWMOutput_Pacemak_T obj_lh;/* '<S3>/ATR_CMP_REF_PWM' */
  freedomk64f_PWMOutput_Pacemak_T obj_dw;/* '<S3>/VENT_CMP_REF_PWM' */
  freedomk64f_DigitalWrite_Pace_T obj_a;/* '<S3>/Z_ATR_CTRLOUT' */
  freedomk64f_DigitalWrite_Pace_T obj_j;/* '<S3>/Z_VENT_CTRLOUT' */
  freedomk64f_DigitalWrite_Pace_T obj_m1;/* '<S3>/ATR_PACE_CTRLOUT' */
  freedomk64f_DigitalWrite_Pace_T obj_ac;/* '<S3>/VENT_PACE_CTRLOUT' */
  freedomk64f_DigitalWrite_Pace_T obj_b;/* '<S3>/PACE_GND_CTRLOUT' */
  freedomk64f_DigitalWrite_Pace_T obj_o;/* '<S3>/ATR_GND_CTRLOUT' */
  freedomk64f_DigitalWrite_Pace_T obj_bs;/* '<S3>/VENT_GND_CTRLOUT' */
  freedomk64f_DigitalWrite_Pace_T obj_h5;/* '<S3>/PACE_CHARGE_CTRLOUT' */
  freedomk64f_DigitalWrite_Pace_T obj_ev;/* '<S3>/R_LEDOUT' */
  freedomk64f_DigitalWrite_Pace_T obj_c;/* '<S3>/B_LEDOUT' */
  freedomk64f_DigitalWrite_Pace_T obj_k;/* '<S3>/B_LEDOUT1' */
  freedomk64f_DigitalWrite_Pace_T obj_p;/* '<S3>/FRONTEND_CTRL1' */
  freedomk64f_SCIWrite_Pacemake_T obj_g;/* '<S7>/Serial Transmit' */
  real_T activityTime;                 /* '<S5>/Chart' */
  real_T noActivityTime;               /* '<S5>/Chart' */
  real_T ActiveChamber;                /* '<Root>/Chart' */
  real32_T TappedDelay_X[24];          /* '<S2>/Tapped Delay' */
  real32_T TappedDelay1_X[24];         /* '<S2>/Tapped Delay1' */
  int32_T sfEvent;                     /* '<Root>/Chart' */
  uint32_T temporalCounter_i1;         /* '<S5>/Chart' */
  uint32_T pulseAmp;                   /* '<Root>/Chart' */
  uint32_T temporalCounter_i1_p;       /* '<Root>/Chart' */
  uint16_T pulseWidth;                 /* '<Root>/Chart' */
  uint8_T is_active_c3_Pacemaker;      /* '<Root>/Serial Communication' */
  uint8_T is_c3_Pacemaker;             /* '<Root>/Serial Communication' */
  uint8_T is_active_c5_Pacemaker;      /* '<S5>/Chart1' */
  uint8_T temporalCounter_i1_pu;       /* '<S5>/Chart1' */
  uint8_T is_active_c4_Pacemaker;      /* '<S5>/Chart' */
  uint8_T is_c4_Pacemaker;             /* '<S5>/Chart' */
  uint8_T is_active_c2_Pacemaker;      /* '<Root>/Chart' */
  uint8_T is_c2_Pacemaker;             /* '<Root>/Chart' */
  uint8_T is_Sense;                    /* '<Root>/Chart' */
  uint8_T is_Ventricle;                /* '<Root>/Chart' */
  uint8_T is_Atrium;                   /* '<Root>/Chart' */
  uint8_T is_Pace;                     /* '<Root>/Chart' */
} DW_Pacemaker_T;

/* Parameters (default storage) */
struct P_Pacemaker_T_ {
  real32_T TappedDelay_vinit;          /* Mask Parameter: TappedDelay_vinit
                                        * Referenced by: '<S2>/Tapped Delay'
                                        */
  real32_T TappedDelay1_vinit;         /* Mask Parameter: TappedDelay1_vinit
                                        * Referenced by: '<S2>/Tapped Delay1'
                                        */
  real_T SerialReceive_SampleTime;     /* Expression: -1
                                        * Referenced by: '<Root>/Serial Receive'
                                        */
  real_T VENT_CMP_DETECT_SampleTime;   /* Expression: SampleTime
                                        * Referenced by: '<S2>/VENT_CMP_DETECT'
                                        */
  real_T ATR_CMP_DETECT_SampleTime;    /* Expression: SampleTime
                                        * Referenced by: '<S2>/ATR_CMP_DETECT'
                                        */
  real_T VentSignalIn_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<S2>/VentSignalIn'
                                        */
  real_T AtrSignalIn_SampleTime;       /* Expression: SampleTime
                                        * Referenced by: '<S2>/AtrSignalIn'
                                        */
  real_T FXOS87006AxesSensor_SampleTime;/* Expression: -1
                                         * Referenced by: '<S5>/FXOS8700 6-Axes Sensor'
                                         */
  real_T Gain1_Gain;                   /* Expression: 60000
                                        * Referenced by: '<S5>/Gain1'
                                        */
  real_T Gain1_Gain_c;                 /* Expression: 60000
                                        * Referenced by: '<S4>/Gain1'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S3>/Constant2'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S2>/Gain'
                                        */
  real32_T Gain1_Gain_j;               /* Computed Parameter: Gain1_Gain_j
                                        * Referenced by: '<S2>/Gain1'
                                        */
  real32_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S4>/Gain2'
                                        */
  real32_T Gain3_Gain;                 /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S4>/Gain3'
                                        */
  uint8_T Gain_Gain_k;                 /* Computed Parameter: Gain_Gain_k
                                        * Referenced by: '<S5>/Gain'
                                        */
  uint8_T scaleDown_Gain;              /* Computed Parameter: scaleDown_Gain
                                        * Referenced by: '<S5>/scaleDown'
                                        */
  uint8_T Constant1_Value;             /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S7>/Constant1'
                                        */
  uint8_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S7>/Constant'
                                        */
  uint8_T Constant2_Value_j[160];      /* Computed Parameter: Constant2_Value_j
                                        * Referenced by: '<S7>/Constant2'
                                        */
  uint8_T Switch_Threshold;            /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S7>/Switch'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Pacemaker_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Pacemaker_T Pacemaker_P;

/* Block signals (default storage) */
extern B_Pacemaker_T Pacemaker_B;

/* Block states (default storage) */
extern DW_Pacemaker_T Pacemaker_DW;

/* External function called from main */
extern void Pacemaker_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void Pacemaker_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void Pacemaker_initialize(void);
extern void Pacemaker_step(int_T tid);
extern void Pacemaker_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Pacemaker_T *const Pacemaker_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Data Type Conversion' : Unused code path elimination
 * Block '<S4>/Data Type Conversion1' : Unused code path elimination
 * Block '<S4>/Gain' : Unused code path elimination
 * Block '<S4>/Math Function' : Unused code path elimination
 * Block '<S2>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S5>/Cast To Double1' : Eliminate redundant data type conversion
 * Block '<S5>/Data Type Conversion2' : Eliminate redundant data type conversion
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
 * '<S4>'   : 'Pacemaker/Parameters'
 * '<S5>'   : 'Pacemaker/Rate Adaptive'
 * '<S6>'   : 'Pacemaker/Serial Communication'
 * '<S7>'   : 'Pacemaker/Serial transmit'
 * '<S8>'   : 'Pacemaker/Parameters/MATLAB Function1'
 * '<S9>'   : 'Pacemaker/Rate Adaptive/Chart'
 * '<S10>'  : 'Pacemaker/Rate Adaptive/Chart1'
 */
#endif                                 /* RTW_HEADER_Pacemaker_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
