/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Assignment1.c
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

#include "Assignment1.h"
#include "Assignment1_private.h"

/* Named constants for Chart: '<Root>/PACING' */
#define Assignm_IN_ChargeDischargeState ((uint8_T)2U)
#define Assignment1_IN_Atrium_Pacing   ((uint8_T)1U)
#define Assignment1_IN_Discharge       ((uint8_T)3U)

/* Block signals (default storage) */
B_Assignment1_T Assignment1_B;

/* Block states (default storage) */
DW_Assignment1_T Assignment1_DW;

/* Real-time model */
RT_MODEL_Assignment1_T Assignment1_M_;
RT_MODEL_Assignment1_T *const Assignment1_M = &Assignment1_M_;

/* Forward declaration for local functions */
static void Assignment_SystemCore_release_j(const
  freedomk64f_DigitalWrite_Assi_T *obj);
static void Assignment1_SystemCore_delete_j(const
  freedomk64f_DigitalWrite_Assi_T *obj);
static void matlabCodegenHandle_matlabCod_j(freedomk64f_DigitalWrite_Assi_T *obj);
static void Assignment1_SystemCore_release(const freedomk64f_PWMOutput_Assignm_T
  *obj);
static void Assignment1_SystemCore_delete(const freedomk64f_PWMOutput_Assignm_T *
  obj);
static void matlabCodegenHandle_matlabCodeg(freedomk64f_PWMOutput_Assignm_T *obj);
static void Assignment_SystemCore_release_j(const
  freedomk64f_DigitalWrite_Assi_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void Assignment1_SystemCore_delete_j(const
  freedomk64f_DigitalWrite_Assi_T *obj)
{
  Assignment_SystemCore_release_j(obj);
}

static void matlabCodegenHandle_matlabCod_j(freedomk64f_DigitalWrite_Assi_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Assignment1_SystemCore_delete_j(obj);
  }
}

static void Assignment1_SystemCore_release(const freedomk64f_PWMOutput_Assignm_T
  *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_PWM_Stop(obj->MW_PWM_HANDLE);
    MW_PWM_Close(obj->MW_PWM_HANDLE);
  }
}

static void Assignment1_SystemCore_delete(const freedomk64f_PWMOutput_Assignm_T *
  obj)
{
  Assignment1_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(freedomk64f_PWMOutput_Assignm_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Assignment1_SystemCore_delete(obj);
  }
}

/* Model step function */
void Assignment1_step(void)
{
  boolean_T rtb_LED_BLUE;
  boolean_T rtb_LED_RED;
  boolean_T rtb_ATR_PACE_CTRL;

  /* Chart: '<Root>/PACING' */
  if (Assignment1_DW.temporalCounter_i1 < 511U) {
    Assignment1_DW.temporalCounter_i1++;
  }

  if (Assignment1_DW.is_active_c3_Assignment1 == 0U) {
    Assignment1_DW.is_active_c3_Assignment1 = 1U;
    Assignment1_DW.is_c3_Assignment1 = Assignm_IN_ChargeDischargeState;
    Assignment1_DW.temporalCounter_i1 = 0U;
    rtb_ATR_PACE_CTRL = false;
    Assignment1_B.PACING_REF_PWM = 80;
    Assignment1_B.PACE_CHARGE_CTRL = true;
    rtb_LED_RED = true;
    rtb_LED_BLUE = false;
  } else {
    switch (Assignment1_DW.is_c3_Assignment1) {
     case Assignment1_IN_Atrium_Pacing:
      if (Assignment1_DW.temporalCounter_i1 >= 400U) {
        Assignment1_DW.is_c3_Assignment1 = Assignment1_IN_Discharge;
        Assignment1_DW.temporalCounter_i1 = 0U;
        Assignment1_B.PACE_GND_CTRL = true;
        Assignment1_B.Z_ATR_CTRL = false;
        Assignment1_B.Z_VENT_CTRL = false;
        rtb_ATR_PACE_CTRL = false;
        Assignment1_B.ATR_GND_CTRL = true;
        Assignment1_B.VENT_GND_CTRL = false;
        rtb_LED_RED = true;
        rtb_LED_BLUE = true;
      } else {
        Assignment1_B.PACE_CHARGE_CTRL = false;
        Assignment1_B.PACE_GND_CTRL = true;
        rtb_ATR_PACE_CTRL = true;
        Assignment1_B.ATR_GND_CTRL = false;
        Assignment1_B.Z_ATR_CTRL = false;
        Assignment1_B.Z_VENT_CTRL = false;
        Assignment1_B.VENT_GND_CTRL = false;
        rtb_LED_RED = false;
        rtb_LED_BLUE = true;
      }
      break;

     case Assignm_IN_ChargeDischargeState:
      if (Assignment1_DW.temporalCounter_i1 >= 500U) {
        Assignment1_DW.is_c3_Assignment1 = Assignment1_IN_Atrium_Pacing;
        Assignment1_DW.temporalCounter_i1 = 0U;
        Assignment1_B.PACE_CHARGE_CTRL = false;
        Assignment1_B.PACE_GND_CTRL = true;
        rtb_ATR_PACE_CTRL = true;
        Assignment1_B.ATR_GND_CTRL = false;
        Assignment1_B.Z_ATR_CTRL = false;
        Assignment1_B.Z_VENT_CTRL = false;
        Assignment1_B.VENT_GND_CTRL = false;
        rtb_LED_RED = false;
        rtb_LED_BLUE = true;
      } else {
        rtb_ATR_PACE_CTRL = false;
        Assignment1_B.PACING_REF_PWM = 80;
        Assignment1_B.PACE_CHARGE_CTRL = true;
        rtb_LED_RED = true;
        rtb_LED_BLUE = false;
      }
      break;

     default:
      /* case IN_Discharge: */
      if (Assignment1_DW.temporalCounter_i1 >= 100U) {
        Assignment1_DW.is_c3_Assignment1 = Assignm_IN_ChargeDischargeState;
        Assignment1_DW.temporalCounter_i1 = 0U;
        rtb_ATR_PACE_CTRL = false;
        Assignment1_B.PACING_REF_PWM = 80;
        Assignment1_B.PACE_CHARGE_CTRL = true;
        rtb_LED_RED = true;
        rtb_LED_BLUE = false;
      } else {
        Assignment1_B.PACE_GND_CTRL = true;
        Assignment1_B.Z_ATR_CTRL = false;
        Assignment1_B.Z_VENT_CTRL = false;
        rtb_ATR_PACE_CTRL = false;
        Assignment1_B.ATR_GND_CTRL = true;
        Assignment1_B.VENT_GND_CTRL = false;
        rtb_LED_RED = true;
        rtb_LED_BLUE = true;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/PACING' */

  /* MATLABSystem: '<Root>/Digital Write' */
  MW_digitalIO_write(Assignment1_DW.obj.MW_DIGITALIO_HANDLE,
                     Assignment1_B.PACE_CHARGE_CTRL);

  /* MATLABSystem: '<Root>/Digital Write1' */
  MW_digitalIO_write(Assignment1_DW.obj_n.MW_DIGITALIO_HANDLE, rtb_ATR_PACE_CTRL);

  /* MATLABSystem: '<Root>/Digital Write10' */
  MW_digitalIO_write(Assignment1_DW.obj_no.MW_DIGITALIO_HANDLE, rtb_LED_RED);

  /* MATLABSystem: '<Root>/Digital Write2' */
  MW_digitalIO_write(Assignment1_DW.obj_j.MW_DIGITALIO_HANDLE, false);

  /* MATLABSystem: '<Root>/Digital Write3' */
  MW_digitalIO_write(Assignment1_DW.obj_m.MW_DIGITALIO_HANDLE,
                     Assignment1_B.ATR_GND_CTRL);

  /* MATLABSystem: '<Root>/Digital Write4' */
  MW_digitalIO_write(Assignment1_DW.obj_i.MW_DIGITALIO_HANDLE,
                     Assignment1_B.VENT_GND_CTRL);

  /* MATLABSystem: '<Root>/Digital Write5' */
  MW_digitalIO_write(Assignment1_DW.obj_nv.MW_DIGITALIO_HANDLE,
                     Assignment1_B.PACE_GND_CTRL);

  /* MATLABSystem: '<Root>/Digital Write6' */
  MW_digitalIO_write(Assignment1_DW.obj_l.MW_DIGITALIO_HANDLE,
                     Assignment1_B.Z_ATR_CTRL);

  /* MATLABSystem: '<Root>/Digital Write7' */
  MW_digitalIO_write(Assignment1_DW.obj_k.MW_DIGITALIO_HANDLE,
                     Assignment1_B.Z_VENT_CTRL);

  /* MATLABSystem: '<Root>/Digital Write9' */
  MW_digitalIO_write(Assignment1_DW.obj_e.MW_DIGITALIO_HANDLE, rtb_LED_BLUE);

  /* MATLABSystem: '<Root>/PWM Output' */
  MW_PWM_SetDutyCycle(Assignment1_DW.obj_b.MW_PWM_HANDLE, (real_T)
                      Assignment1_B.PACING_REF_PWM);
}

/* Model initialize function */
void Assignment1_initialize(void)
{
  {
    freedomk64f_DigitalWrite_Assi_T *obj;
    freedomk64f_PWMOutput_Assignm_T *obj_0;

    /* Start for MATLABSystem: '<Root>/Digital Write' */
    Assignment1_DW.obj.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj.isInitialized = 0;
    Assignment1_DW.obj.matlabCodegenIsDeleted = false;
    obj = &Assignment1_DW.obj;
    Assignment1_DW.obj.isSetupComplete = false;
    Assignment1_DW.obj.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    Assignment1_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write1' */
    Assignment1_DW.obj_n.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_n.isInitialized = 0;
    Assignment1_DW.obj_n.matlabCodegenIsDeleted = false;
    obj = &Assignment1_DW.obj_n;
    Assignment1_DW.obj_n.isSetupComplete = false;
    Assignment1_DW.obj_n.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    Assignment1_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write10' */
    Assignment1_DW.obj_no.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_no.isInitialized = 0;
    Assignment1_DW.obj_no.matlabCodegenIsDeleted = false;
    obj = &Assignment1_DW.obj_no;
    Assignment1_DW.obj_no.isSetupComplete = false;
    Assignment1_DW.obj_no.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(42U, 1);
    Assignment1_DW.obj_no.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write2' */
    Assignment1_DW.obj_j.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_j.isInitialized = 0;
    Assignment1_DW.obj_j.matlabCodegenIsDeleted = false;
    obj = &Assignment1_DW.obj_j;
    Assignment1_DW.obj_j.isSetupComplete = false;
    Assignment1_DW.obj_j.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    Assignment1_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write3' */
    Assignment1_DW.obj_m.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_m.isInitialized = 0;
    Assignment1_DW.obj_m.matlabCodegenIsDeleted = false;
    obj = &Assignment1_DW.obj_m;
    Assignment1_DW.obj_m.isSetupComplete = false;
    Assignment1_DW.obj_m.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    Assignment1_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write4' */
    Assignment1_DW.obj_i.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_i.isInitialized = 0;
    Assignment1_DW.obj_i.matlabCodegenIsDeleted = false;
    obj = &Assignment1_DW.obj_i;
    Assignment1_DW.obj_i.isSetupComplete = false;
    Assignment1_DW.obj_i.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    Assignment1_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write5' */
    Assignment1_DW.obj_nv.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_nv.isInitialized = 0;
    Assignment1_DW.obj_nv.matlabCodegenIsDeleted = false;
    obj = &Assignment1_DW.obj_nv;
    Assignment1_DW.obj_nv.isSetupComplete = false;
    Assignment1_DW.obj_nv.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    Assignment1_DW.obj_nv.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write6' */
    Assignment1_DW.obj_l.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_l.isInitialized = 0;
    Assignment1_DW.obj_l.matlabCodegenIsDeleted = false;
    obj = &Assignment1_DW.obj_l;
    Assignment1_DW.obj_l.isSetupComplete = false;
    Assignment1_DW.obj_l.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    Assignment1_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write7' */
    Assignment1_DW.obj_k.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_k.isInitialized = 0;
    Assignment1_DW.obj_k.matlabCodegenIsDeleted = false;
    obj = &Assignment1_DW.obj_k;
    Assignment1_DW.obj_k.isSetupComplete = false;
    Assignment1_DW.obj_k.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    Assignment1_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write9' */
    Assignment1_DW.obj_e.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_e.isInitialized = 0;
    Assignment1_DW.obj_e.matlabCodegenIsDeleted = false;
    obj = &Assignment1_DW.obj_e;
    Assignment1_DW.obj_e.isSetupComplete = false;
    Assignment1_DW.obj_e.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(44U, 1);
    Assignment1_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM Output' */
    Assignment1_DW.obj_b.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_b.isInitialized = 0;
    Assignment1_DW.obj_b.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_DW.obj_b;
    Assignment1_DW.obj_b.isSetupComplete = false;
    Assignment1_DW.obj_b.isInitialized = 1;
    obj_0->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(Assignment1_DW.obj_b.MW_PWM_HANDLE);
    Assignment1_DW.obj_b.isSetupComplete = true;
  }
}

/* Model terminate function */
void Assignment1_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Write' */
  matlabCodegenHandle_matlabCod_j(&Assignment1_DW.obj);

  /* Terminate for MATLABSystem: '<Root>/Digital Write1' */
  matlabCodegenHandle_matlabCod_j(&Assignment1_DW.obj_n);

  /* Terminate for MATLABSystem: '<Root>/Digital Write10' */
  matlabCodegenHandle_matlabCod_j(&Assignment1_DW.obj_no);

  /* Terminate for MATLABSystem: '<Root>/Digital Write2' */
  matlabCodegenHandle_matlabCod_j(&Assignment1_DW.obj_j);

  /* Terminate for MATLABSystem: '<Root>/Digital Write3' */
  matlabCodegenHandle_matlabCod_j(&Assignment1_DW.obj_m);

  /* Terminate for MATLABSystem: '<Root>/Digital Write4' */
  matlabCodegenHandle_matlabCod_j(&Assignment1_DW.obj_i);

  /* Terminate for MATLABSystem: '<Root>/Digital Write5' */
  matlabCodegenHandle_matlabCod_j(&Assignment1_DW.obj_nv);

  /* Terminate for MATLABSystem: '<Root>/Digital Write6' */
  matlabCodegenHandle_matlabCod_j(&Assignment1_DW.obj_l);

  /* Terminate for MATLABSystem: '<Root>/Digital Write7' */
  matlabCodegenHandle_matlabCod_j(&Assignment1_DW.obj_k);

  /* Terminate for MATLABSystem: '<Root>/Digital Write9' */
  matlabCodegenHandle_matlabCod_j(&Assignment1_DW.obj_e);

  /* Terminate for MATLABSystem: '<Root>/PWM Output' */
  matlabCodegenHandle_matlabCodeg(&Assignment1_DW.obj_b);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
