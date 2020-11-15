/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Pacemaker.h
 *
 * Code generated for Simulink model 'Pacemaker'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sat Nov 14 20:43:41 2020
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
#include "MW_PWM.h"
#endif                                 /* Pacemaker_COMMON_INCLUDES_ */

#include "Pacemaker_types.h"

/* Child system includes */
#include "send_params_private.h"
#include "send_params.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  uint8_T TxDataLocChar[39];
  uint8_T RxData[39];
  uint8_T RxDataLocChar[39];
  uint32_T TxPinLoc;
  uint32_T SCIModuleLoc;
  MW_SCI_StopBits_Type StopBitsValue;
  uint32_T DataTypeConversion4;        /* '<S4>/Data Type Conversion4' */
  uint32_T PACING_REF_PWM;             /* '<Root>/Chart' */
  real32_T AtrialAmp;
  real32_T AtrialPulseWidth;
  real32_T VentricularAmp;
  real32_T VentricularPulseWidth;
  real32_T AtrialSensitivity;
  real32_T VentricularSensitivity;
  real32_T AtrialAmp_g;                /* '<Root>/SerialReceive' */
  real32_T AtrialPulseWidth_a;         /* '<Root>/SerialReceive' */
  real32_T VentricularAmp_o;           /* '<Root>/SerialReceive' */
  real32_T VentricularPulseWidth_i;    /* '<Root>/SerialReceive' */
  real32_T AtrialSensitivity_d;        /* '<Root>/SerialReceive' */
  real32_T VentricularSensitivity_j;   /* '<Root>/SerialReceive' */
  ChamberSensed y2;                    /* '<S4>/MATLAB Function1' */
  ChamberPaced y1;                     /* '<S4>/MATLAB Function1' */
  Activity y3;                         /* '<S4>/MATLAB Function1' */
  uint16_T DataTypeConversion5;        /* '<S4>/Data Type Conversion5' */
  uint16_T DataTypeConversion1;        /* '<S4>/Data Type Conversion1' */
  uint16_T VRP;
  uint16_T ARP;
  uint16_T PVARP;
  uint16_T FixAVDelay;
  uint16_T VRP_g;                      /* '<Root>/SerialReceive' */
  uint16_T ARP_j;                      /* '<Root>/SerialReceive' */
  uint16_T PVARP_m;                    /* '<Root>/SerialReceive' */
  uint16_T FixAVDelay_e;               /* '<Root>/SerialReceive' */
  uint8_T BytePack1[4];                /* '<S5>/Byte Pack1' */
  uint8_T BytePack2[4];                /* '<S5>/Byte Pack2' */
  uint8_T BytePack3[4];                /* '<S5>/Byte Pack3' */
  uint8_T BytePack4[4];                /* '<S5>/Byte Pack4' */
  uint8_T BytePack[2];                 /* '<S5>/Byte Pack' */
  uint8_T BytePack5[2];                /* '<S5>/Byte Pack5' */
  uint8_T BytePack6[2];                /* '<S5>/Byte Pack6' */
  uint8_T BytePack7[2];                /* '<S5>/Byte Pack7' */
  uint8_T BytePack8[4];                /* '<S5>/Byte Pack8' */
  uint8_T BytePack9[4];                /* '<S5>/Byte Pack9' */
  uint8_T Mode;                        /* '<Root>/SerialReceive' */
  uint8_T LRL;                         /* '<Root>/SerialReceive' */
  uint8_T URL;                         /* '<Root>/SerialReceive' */
  uint8_T MaxSensorRate;               /* '<Root>/SerialReceive' */
  uint8_T ReactionTime;                /* '<Root>/SerialReceive' */
  uint8_T ResponseFactor;              /* '<Root>/SerialReceive' */
  uint8_T RecoveryTime;                /* '<Root>/SerialReceive' */
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
  freedomk64f_DigitalRead_Pacem_T obj_l;/* '<S2>/VENT_CMP_DETECT' */
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
  freedomk64f_DigitalWrite_Pace_T obj_h;/* '<S3>/PACE_CHARGE_CTRLOUT' */
  freedomk64f_DigitalWrite_Pace_T obj_e;/* '<S3>/R_LEDOUT' */
  freedomk64f_DigitalWrite_Pace_T obj_c;/* '<S3>/B_LEDOUT' */
  freedomk64f_DigitalWrite_Pace_T obj_p;/* '<S3>/FRONTEND_CTRL1' */
  freedomk64f_SCIWrite_Pacemake_T obj_ej;/* '<S5>/Serial Transmit' */
  real_T ActiveChamber;                /* '<Root>/Chart' */
  int32_T sfEvent;                     /* '<Root>/Chart' */
  uint32_T temporalCounter_i1;         /* '<Root>/Chart' */
  uint8_T is_active_c3_Pacemaker;      /* '<Root>/SerialReceive' */
  uint8_T is_c3_Pacemaker;             /* '<Root>/SerialReceive' */
  uint8_T is_active_c2_Pacemaker;      /* '<Root>/Chart' */
  uint8_T is_c2_Pacemaker;             /* '<Root>/Chart' */
  uint8_T is_Sense;                    /* '<Root>/Chart' */
  uint8_T is_Atrium;                   /* '<Root>/Chart' */
  uint8_T is_Ventricle;                /* '<Root>/Chart' */
  uint8_T is_Pace;                     /* '<Root>/Chart' */
} DW_Pacemaker_T;

/* Parameters (default storage) */
struct P_Pacemaker_T_ {
  real_T SerialReceive_SampleTime;     /* Expression: -1
                                        * Referenced by: '<Root>/Serial Receive'
                                        */
  real_T VENT_CMP_DETECT_SampleTime;   /* Expression: SampleTime
                                        * Referenced by: '<S2>/VENT_CMP_DETECT'
                                        */
  real_T ATR_CMP_DETECT_SampleTime;    /* Expression: SampleTime
                                        * Referenced by: '<S2>/ATR_CMP_DETECT'
                                        */
  real_T Gain_Gain;                    /* Expression: 60000
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 60000
                                        * Referenced by: '<S4>/Gain1'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S3>/Constant2'
                                        */
  real32_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S4>/Gain2'
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
 * '<S4>'   : 'Pacemaker/Parameters'
 * '<S5>'   : 'Pacemaker/Parameters echo'
 * '<S6>'   : 'Pacemaker/SerialReceive'
 * '<S7>'   : 'Pacemaker/Parameters/MATLAB Function1'
 */
#endif                                 /* RTW_HEADER_Pacemaker_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
