/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Pacemaker_types.h
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

#ifndef RTW_HEADER_Pacemaker_types_h_
#define RTW_HEADER_Pacemaker_types_h_
#include "rtwtypes.h"

/* Model Code Variants */
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

/* Custom Type definition for MATLABSystem: '<S7>/Serial Transmit' */
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

#ifndef struct_tag_WltE1qT51p3S2KRQQd2Zd
#define struct_tag_WltE1qT51p3S2KRQQd2Zd

struct tag_WltE1qT51p3S2KRQQd2Zd
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_Pacema_T Hw;
  MW_Handle_Type MW_SCIHANDLE;
};

#endif                                 /*struct_tag_WltE1qT51p3S2KRQQd2Zd*/

#ifndef typedef_freedomk64f_SCIWrite_Pacemake_T
#define typedef_freedomk64f_SCIWrite_Pacemake_T

typedef struct tag_WltE1qT51p3S2KRQQd2Zd freedomk64f_SCIWrite_Pacemake_T;

#endif                               /*typedef_freedomk64f_SCIWrite_Pacemake_T*/

/* Custom Type definition for MATLABSystem: '<S5>/FXOS8700 6-Axes Sensor' */
#include "MW_I2C.h"
#ifndef struct_tag_79weVYaslRFZRGk3pNTXC
#define struct_tag_79weVYaslRFZRGk3pNTXC

struct tag_79weVYaslRFZRGk3pNTXC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_Pacema_T Hw;
  MW_Handle_Type MW_SCIHANDLE;
  real_T SampleTime;
};

#endif                                 /*struct_tag_79weVYaslRFZRGk3pNTXC*/

#ifndef typedef_freedomk64f_SCIRead_Pacemaker_T
#define typedef_freedomk64f_SCIRead_Pacemaker_T

typedef struct tag_79weVYaslRFZRGk3pNTXC freedomk64f_SCIRead_Pacemaker_T;

#endif                               /*typedef_freedomk64f_SCIRead_Pacemaker_T*/

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

#ifndef struct_tag_Wwo3lHKnvPcvz2YX38S3zB
#define struct_tag_Wwo3lHKnvPcvz2YX38S3zB

struct tag_Wwo3lHKnvPcvz2YX38S3zB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_Pacema_T Hw;
  MW_Handle_Type MW_ANALOGIN_HANDLE;
  real_T SampleTime;
};

#endif                                 /*struct_tag_Wwo3lHKnvPcvz2YX38S3zB*/

#ifndef typedef_freedomk64f_AnalogInput_Pacem_T
#define typedef_freedomk64f_AnalogInput_Pacem_T

typedef struct tag_Wwo3lHKnvPcvz2YX38S3zB freedomk64f_AnalogInput_Pacem_T;

#endif                               /*typedef_freedomk64f_AnalogInput_Pacem_T*/

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

#ifndef struct_tag_dJFZzmsGU3XebjMxPxDlh
#define struct_tag_dJFZzmsGU3XebjMxPxDlh

struct tag_dJFZzmsGU3XebjMxPxDlh
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  b_freedomk64f_Hardware_Pacema_T Hw;
  uint32_T BusSpeed;
  MW_Handle_Type MW_I2C_HANDLE;
};

#endif                                 /*struct_tag_dJFZzmsGU3XebjMxPxDlh*/

#ifndef typedef_b_freedomk64f_I2CMasterWrite__T
#define typedef_b_freedomk64f_I2CMasterWrite__T

typedef struct tag_dJFZzmsGU3XebjMxPxDlh b_freedomk64f_I2CMasterWrite__T;

#endif                               /*typedef_b_freedomk64f_I2CMasterWrite__T*/

#ifndef struct_tag_IfyqWdTTOITb2iei5A9qmC
#define struct_tag_IfyqWdTTOITb2iei5A9qmC

struct tag_IfyqWdTTOITb2iei5A9qmC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T SampleTime;
  b_freedomk64f_I2CMasterWrite__T i2cobj;
};

#endif                                 /*struct_tag_IfyqWdTTOITb2iei5A9qmC*/

#ifndef typedef_freedomk64f_fxos8700_Pacemake_T
#define typedef_freedomk64f_fxos8700_Pacemake_T

typedef struct tag_IfyqWdTTOITb2iei5A9qmC freedomk64f_fxos8700_Pacemake_T;

#endif                               /*typedef_freedomk64f_fxos8700_Pacemake_T*/

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
