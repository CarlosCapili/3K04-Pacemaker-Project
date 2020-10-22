/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: light_with_sence.c
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

#include "light_with_sence.h"
#include "light_with_sence_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define light_with_sence_IN_state      ((uint8_T)1U)
#define light_with_sence_IN_state1     ((uint8_T)2U)

/* Block states (default storage) */
DW_light_with_sence_T light_with_sence_DW;

/* Real-time model */
RT_MODEL_light_with_sence_T light_with_sence_M_;
RT_MODEL_light_with_sence_T *const light_with_sence_M = &light_with_sence_M_;

/* Forward declaration for local functions */
static void light_wi_SystemCore_release_iku(const
  freedomk64f_DigitalRead_light_T *obj);
static void light_wit_SystemCore_delete_iku(const
  freedomk64f_DigitalRead_light_T *obj);
static void matlabCodegenHandle_matlabC_iku(freedomk64f_DigitalRead_light_T *obj);
static void light_with_s_SystemCore_release(const
  freedomk64f_DigitalWrite_ligh_T *obj);
static void light_with_se_SystemCore_delete(const
  freedomk64f_DigitalWrite_ligh_T *obj);
static void matlabCodegenHandle_matlabCodeg(freedomk64f_DigitalWrite_ligh_T *obj);
static void light_with_SystemCore_release_i(const
  freedomk64f_PWMOutput_light_w_T *obj);
static void light_with__SystemCore_delete_i(const
  freedomk64f_PWMOutput_light_w_T *obj);
static void matlabCodegenHandle_matlabCod_i(freedomk64f_PWMOutput_light_w_T *obj);
static void light_wi_SystemCore_release_iku(const
  freedomk64f_DigitalRead_light_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void light_wit_SystemCore_delete_iku(const
  freedomk64f_DigitalRead_light_T *obj)
{
  light_wi_SystemCore_release_iku(obj);
}

static void matlabCodegenHandle_matlabC_iku(freedomk64f_DigitalRead_light_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    light_wit_SystemCore_delete_iku(obj);
  }
}

static void light_with_s_SystemCore_release(const
  freedomk64f_DigitalWrite_ligh_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void light_with_se_SystemCore_delete(const
  freedomk64f_DigitalWrite_ligh_T *obj)
{
  light_with_s_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(freedomk64f_DigitalWrite_ligh_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    light_with_se_SystemCore_delete(obj);
  }
}

static void light_with_SystemCore_release_i(const
  freedomk64f_PWMOutput_light_w_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_PWM_Stop(obj->MW_PWM_HANDLE);
    MW_PWM_Close(obj->MW_PWM_HANDLE);
  }
}

static void light_with__SystemCore_delete_i(const
  freedomk64f_PWMOutput_light_w_T *obj)
{
  light_with_SystemCore_release_i(obj);
}

static void matlabCodegenHandle_matlabCod_i(freedomk64f_PWMOutput_light_w_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    light_with__SystemCore_delete_i(obj);
  }
}

/* Model step function */
void light_with_sence_step(void)
{
  boolean_T rtb_DigitalRead_0;
  boolean_T rtb_data1;

  /* MATLABSystem: '<Root>/Digital Read' */
  if (light_with_sence_DW.obj.SampleTime !=
      light_with_sence_P.DigitalRead_SampleTime) {
    light_with_sence_DW.obj.SampleTime =
      light_with_sence_P.DigitalRead_SampleTime;
  }

  rtb_DigitalRead_0 = MW_digitalIO_read
    (light_with_sence_DW.obj.MW_DIGITALIO_HANDLE);

  /* Chart: '<Root>/Chart' incorporates:
   *  MATLABSystem: '<Root>/Digital Read'
   */
  if (light_with_sence_DW.temporalCounter_i1 < 127U) {
    light_with_sence_DW.temporalCounter_i1++;
  }

  if (light_with_sence_DW.is_active_c3_light_with_sence == 0U) {
    light_with_sence_DW.is_active_c3_light_with_sence = 1U;
    light_with_sence_DW.is_c3_light_with_sence = light_with_sence_IN_state;
    rtb_data1 = false;
  } else if (light_with_sence_DW.is_c3_light_with_sence ==
             light_with_sence_IN_state) {
    rtb_data1 = false;
    if (rtb_DigitalRead_0) {
      light_with_sence_DW.is_c3_light_with_sence = light_with_sence_IN_state1;
      light_with_sence_DW.temporalCounter_i1 = 0U;
      rtb_data1 = true;
    }
  } else {
    /* case IN_state1: */
    rtb_data1 = true;
    if (light_with_sence_DW.temporalCounter_i1 >= 100U) {
      light_with_sence_DW.is_c3_light_with_sence = light_with_sence_IN_state;
      rtb_data1 = false;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* MATLABSystem: '<Root>/Digital Write1' */
  MW_digitalIO_write(light_with_sence_DW.obj_n.MW_DIGITALIO_HANDLE, rtb_data1);

  /* MATLABSystem: '<Root>/PWM Output' incorporates:
   *  Constant: '<Root>/Constant'
   */
  MW_PWM_SetDutyCycle(light_with_sence_DW.obj_j.MW_PWM_HANDLE,
                      light_with_sence_P.Constant_Value);

  /* MATLABSystem: '<Root>/Digital Write2' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  MW_digitalIO_write(light_with_sence_DW.obj_i.MW_DIGITALIO_HANDLE,
                     light_with_sence_P.Constant1_Value != 0.0);
}

/* Model initialize function */
void light_with_sence_initialize(void)
{
  {
    freedomk64f_DigitalRead_light_T *obj;
    freedomk64f_DigitalWrite_ligh_T *obj_0;
    freedomk64f_PWMOutput_light_w_T *obj_1;

    /* Start for MATLABSystem: '<Root>/Digital Read' */
    light_with_sence_DW.obj.matlabCodegenIsDeleted = true;
    light_with_sence_DW.obj.isInitialized = 0;
    light_with_sence_DW.obj.SampleTime = -1.0;
    light_with_sence_DW.obj.matlabCodegenIsDeleted = false;
    light_with_sence_DW.obj.SampleTime =
      light_with_sence_P.DigitalRead_SampleTime;
    obj = &light_with_sence_DW.obj;
    light_with_sence_DW.obj.isSetupComplete = false;
    light_with_sence_DW.obj.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    light_with_sence_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write1' */
    light_with_sence_DW.obj_n.matlabCodegenIsDeleted = true;
    light_with_sence_DW.obj_n.isInitialized = 0;
    light_with_sence_DW.obj_n.matlabCodegenIsDeleted = false;
    obj_0 = &light_with_sence_DW.obj_n;
    light_with_sence_DW.obj_n.isSetupComplete = false;
    light_with_sence_DW.obj_n.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(42U, 1);
    light_with_sence_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM Output' */
    light_with_sence_DW.obj_j.matlabCodegenIsDeleted = true;
    light_with_sence_DW.obj_j.isInitialized = 0;
    light_with_sence_DW.obj_j.matlabCodegenIsDeleted = false;
    obj_1 = &light_with_sence_DW.obj_j;
    light_with_sence_DW.obj_j.isSetupComplete = false;
    light_with_sence_DW.obj_j.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(light_with_sence_DW.obj_j.MW_PWM_HANDLE);
    light_with_sence_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write2' */
    light_with_sence_DW.obj_i.matlabCodegenIsDeleted = true;
    light_with_sence_DW.obj_i.isInitialized = 0;
    light_with_sence_DW.obj_i.matlabCodegenIsDeleted = false;
    obj_0 = &light_with_sence_DW.obj_i;
    light_with_sence_DW.obj_i.isSetupComplete = false;
    light_with_sence_DW.obj_i.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    light_with_sence_DW.obj_i.isSetupComplete = true;
  }
}

/* Model terminate function */
void light_with_sence_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Read' */
  matlabCodegenHandle_matlabC_iku(&light_with_sence_DW.obj);

  /* Terminate for MATLABSystem: '<Root>/Digital Write1' */
  matlabCodegenHandle_matlabCodeg(&light_with_sence_DW.obj_n);

  /* Terminate for MATLABSystem: '<Root>/PWM Output' */
  matlabCodegenHandle_matlabCod_i(&light_with_sence_DW.obj_j);

  /* Terminate for MATLABSystem: '<Root>/Digital Write2' */
  matlabCodegenHandle_matlabCodeg(&light_with_sence_DW.obj_i);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
