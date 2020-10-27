/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Pacemaker_types.h
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

#ifndef RTW_HEADER_Pacemaker_types_h_
#define RTW_HEADER_Pacemaker_types_h_
#include "rtwtypes.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_Activity_
#define DEFINED_TYPEDEF_FOR_Activity_

typedef enum {
  TRIGGERED_A = 0,                     /* Default value */
  INHIBITED_A,
  DUAL_A,
  NONE_A
} Activity;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Adaptive_
#define DEFINED_TYPEDEF_FOR_Adaptive_

typedef enum {
  NONE_AD = 0,                         /* Default value */
  RATE_AD
} Adaptive;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ChamberPaced_
#define DEFINED_TYPEDEF_FOR_ChamberPaced_

typedef enum {
  ATRIUM_P = 0,                        /* Default value */
  VENTRICLE_P,
  DUAL_P,
  NONE_P
} ChamberPaced;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ChamberSensed_
#define DEFINED_TYPEDEF_FOR_ChamberSensed_

typedef enum {
  ATRIUM_S = 0,                        /* Default value */
  VENTRICLE_S,
  DUAL_S,
  NONE_S
} ChamberSensed;

#endif

/* Custom Type definition for MATLABSystem: '<S3>/Z_ATR_CTRLOUT' */
#include "MW_SVD.h"
#ifndef struct_tag_bvK2L41g8z1P0jzpdjsJhE
#define struct_tag_bvK2L41g8z1P0jzpdjsJhE

struct tag_bvK2L41g8z1P0jzpdjsJhE
{
  int32_T __dummy;
};

#endif                                 /*struct_tag_bvK2L41g8z1P0jzpdjsJhE*/

#ifndef typedef_b_freedomk64f_Hardware_Pacema_T
#define typedef_b_freedomk64f_Hardware_Pacema_T

typedef struct tag_bvK2L41g8z1P0jzpdjsJhE b_freedomk64f_Hardware_Pacema_T;

#endif                               /*typedef_b_freedomk64f_Hardware_Pacema_T*/

#ifndef struct_tag_gY1zYXXyNHJpvdqiHJr34G
#define struct_tag_gY1zYXXyNHJpvdqiHJr34G

struct tag_gY1zYXXyNHJpvdqiHJr34G
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_Pacema_T Hw;
  MW_Handle_Type MW_DIGITALIO_HANDLE;
  real_T SampleTime;
};

#endif                                 /*struct_tag_gY1zYXXyNHJpvdqiHJr34G*/

#ifndef typedef_freedomk64f_DigitalRead_Pacem_T
#define typedef_freedomk64f_DigitalRead_Pacem_T

typedef struct tag_gY1zYXXyNHJpvdqiHJr34G freedomk64f_DigitalRead_Pacem_T;

#endif                               /*typedef_freedomk64f_DigitalRead_Pacem_T*/

#ifndef struct_tag_62aCTDKRGQaAsT8vVipI2D
#define struct_tag_62aCTDKRGQaAsT8vVipI2D

struct tag_62aCTDKRGQaAsT8vVipI2D
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_Pacema_T Hw;
  MW_Handle_Type MW_DIGITALIO_HANDLE;
};

#endif                                 /*struct_tag_62aCTDKRGQaAsT8vVipI2D*/

#ifndef typedef_freedomk64f_DigitalWrite_Pace_T
#define typedef_freedomk64f_DigitalWrite_Pace_T

typedef struct tag_62aCTDKRGQaAsT8vVipI2D freedomk64f_DigitalWrite_Pace_T;

#endif                               /*typedef_freedomk64f_DigitalWrite_Pace_T*/

#ifndef struct_tag_asB9FwAteE1VObOuq1LwyE
#define struct_tag_asB9FwAteE1VObOuq1LwyE

struct tag_asB9FwAteE1VObOuq1LwyE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_Pacema_T Hw;
  MW_Handle_Type MW_PWM_HANDLE;
};

#endif                                 /*struct_tag_asB9FwAteE1VObOuq1LwyE*/

#ifndef typedef_freedomk64f_PWMOutput_Pacemak_T
#define typedef_freedomk64f_PWMOutput_Pacemak_T

typedef struct tag_asB9FwAteE1VObOuq1LwyE freedomk64f_PWMOutput_Pacemak_T;

#endif                               /*typedef_freedomk64f_PWMOutput_Pacemak_T*/

/* Parameters (default storage) */
typedef struct P_Pacemaker_T_ P_Pacemaker_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Pacemaker_T RT_MODEL_Pacemaker_T;

#endif                                 /* RTW_HEADER_Pacemaker_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
