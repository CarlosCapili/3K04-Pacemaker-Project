/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Pacemaker.c
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

#include "Pacemaker.h"
#include "Pacemaker_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define Pacemaker_CALL_EVENT           (-1)
#define Pacemaker_IN_Atrium            ((uint8_T)1U)
#define Pacemaker_IN_Charging          ((uint8_T)1U)
#define Pacemaker_IN_Default           ((uint8_T)2U)
#define Pacemaker_IN_Discharging       ((uint8_T)2U)
#define Pacemaker_IN_INIT              ((uint8_T)1U)
#define Pacemaker_IN_Inhibit           ((uint8_T)1U)
#define Pacemaker_IN_NO_ACTIVE_CHILD   ((uint8_T)0U)
#define Pacemaker_IN_None              ((uint8_T)2U)
#define Pacemaker_IN_Pace              ((uint8_T)2U)
#define Pacemaker_IN_Sense             ((uint8_T)3U)
#define Pacemaker_IN_Ventricular       ((uint8_T)3U)
#define Pacemaker_IN_test              ((uint8_T)4U)
#define Pacemaker_event_chargePace     (0)
#define Pacemaker_event_dischargePace  (1)
#define Pacemaker_event_paceEnd        (2)
#define Pacemaker_event_paceStart      (3)

/* Block signals (default storage) */
B_Pacemaker_T Pacemaker_B;

/* Block states (default storage) */
DW_Pacemaker_T Pacemaker_DW;

/* Real-time model */
RT_MODEL_Pacemaker_T Pacemaker_M_;
RT_MODEL_Pacemaker_T *const Pacemaker_M = &Pacemaker_M_;

/* Forward declaration for local functions */
static void Pacemaker_broadcast_paceEnd(void);
static void Pacemaker_broadcast_chargePace(void);
static void Pacema_enter_atomic_Discharging(void);
static void Pacemaker_c2_Pacemaker(void);
static void Pacemaker_SystemCore_release(const freedomk64f_DigitalRead_Pacem_T
  *obj);
static void Pacemaker_SystemCore_delete(const freedomk64f_DigitalRead_Pacem_T
  *obj);
static void matlabCodegenHandle_matlabCodeg(freedomk64f_DigitalRead_Pacem_T *obj);
static void Pacemaker_SystemCore_release_j0(const
  freedomk64f_DigitalWrite_Pace_T *obj);
static void Pacemaker_SystemCore_delete_j0(const freedomk64f_DigitalWrite_Pace_T
  *obj);
static void matlabCodegenHandle_matlabCo_j0(freedomk64f_DigitalWrite_Pace_T *obj);

/* Function for Chart: '<Root>/Chart' */
static void Pacemaker_broadcast_paceEnd(void)
{
  int32_T b_previousEvent;
  b_previousEvent = Pacemaker_DW.sfEvent;
  Pacemaker_DW.sfEvent = Pacemaker_event_paceEnd;

  /* Chart: '<Root>/Chart' */
  Pacemaker_c2_Pacemaker();
  Pacemaker_DW.sfEvent = b_previousEvent;
}

/* Function for Chart: '<Root>/Chart' */
static void Pacemaker_broadcast_chargePace(void)
{
  int32_T b_previousEvent;
  b_previousEvent = Pacemaker_DW.sfEvent;
  Pacemaker_DW.sfEvent = Pacemaker_event_chargePace;

  /* Chart: '<Root>/Chart' */
  Pacemaker_c2_Pacemaker();
  Pacemaker_DW.sfEvent = b_previousEvent;
}

/* Function for Chart: '<Root>/Chart' */
static void Pacema_enter_atomic_Discharging(void)
{
  Pacemaker_B.R_LED = false;
  if (Pacemaker_DW.temporalCounter_i1 >= 200U) {
    Pacemaker_broadcast_chargePace();
  }
}

/* Function for Chart: '<Root>/Chart' */
static void Pacemaker_c2_Pacemaker(void)
{
  /* Chart: '<Root>/Chart' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   */
  if (Pacemaker_DW.is_active_c2_Pacemaker == 0U) {
    Pacemaker_DW.is_active_c2_Pacemaker = 1U;
    Pacemaker_DW.is_c2_Pacemaker = Pacemaker_IN_INIT;
    Pacemaker_B.senseSwitch = true;
  } else {
    switch (Pacemaker_DW.is_c2_Pacemaker) {
     case Pacemaker_IN_INIT:
      Pacemaker_DW.is_c2_Pacemaker = Pacemaker_IN_Sense;
      if (Pacemaker_P.Constant2_Value == INHIBITED_A) {
        Pacemaker_DW.is_Sense = Pacemaker_IN_Inhibit;
        Pacemaker_DW.is_Inhibit = Pacemaker_IN_Default;
        Pacemaker_B.B_LED = false;
      } else {
        Pacemaker_DW.is_Sense = Pacemaker_IN_None;
      }
      break;

     case Pacemaker_IN_Pace:
      if (Pacemaker_DW.sfEvent == Pacemaker_event_paceEnd) {
        Pacemaker_DW.is_Pace = Pacemaker_IN_NO_ACTIVE_CHILD;
        Pacemaker_DW.is_c2_Pacemaker = Pacemaker_IN_Sense;
        if (Pacemaker_P.Constant2_Value == INHIBITED_A) {
          Pacemaker_DW.is_Sense = Pacemaker_IN_Inhibit;
          Pacemaker_DW.is_Inhibit = Pacemaker_IN_Default;
          Pacemaker_B.B_LED = false;
        } else {
          Pacemaker_DW.is_Sense = Pacemaker_IN_None;
        }
      } else {
        switch (Pacemaker_DW.is_Pace) {
         case Pacemaker_IN_Charging:
          if (Pacemaker_DW.sfEvent == Pacemaker_event_dischargePace) {
            Pacemaker_DW.is_Pace = Pacemaker_IN_Discharging;
            Pacemaker_DW.temporalCounter_i1 = 0U;
            Pacema_enter_atomic_Discharging();
          } else {
            Pacemaker_B.R_LED = true;
            if (Pacemaker_DW.temporalCounter_i1 >= 200U) {
              Pacemaker_broadcast_paceEnd();
            }
          }
          break;

         case Pacemaker_IN_Discharging:
          if (Pacemaker_DW.sfEvent == Pacemaker_event_chargePace) {
            Pacemaker_DW.is_Pace = Pacemaker_IN_Charging;
            Pacemaker_DW.temporalCounter_i1 = 0U;
            Pacemaker_B.R_LED = true;
            if (Pacemaker_DW.temporalCounter_i1 >= 200U) {
              Pacemaker_broadcast_paceEnd();
            }
          } else {
            Pacemaker_B.R_LED = false;
            if (Pacemaker_DW.temporalCounter_i1 >= 200U) {
              Pacemaker_broadcast_chargePace();
            }
          }
          break;
        }
      }
      break;

     case Pacemaker_IN_Sense:
      if (Pacemaker_DW.sfEvent == Pacemaker_event_paceStart) {
        Pacemaker_DW.is_Inhibit = Pacemaker_IN_NO_ACTIVE_CHILD;
        Pacemaker_DW.is_Sense = Pacemaker_IN_NO_ACTIVE_CHILD;
        Pacemaker_DW.is_c2_Pacemaker = Pacemaker_IN_Pace;
        Pacemaker_DW.is_Pace = Pacemaker_IN_Discharging;
        Pacemaker_DW.temporalCounter_i1 = 0U;
        Pacema_enter_atomic_Discharging();
      } else {
        if (Pacemaker_DW.is_Sense == Pacemaker_IN_Inhibit) {
          switch (Pacemaker_DW.is_Inhibit) {
           case Pacemaker_IN_Atrium:
            if (Pacemaker_B.DigitalRead) {
              Pacemaker_DW.is_Inhibit = Pacemaker_IN_test;
              Pacemaker_DW.temporalCounter_i1 = 0U;
              Pacemaker_B.B_LED = true;
              Pacemaker_B.R_LED = true;
            }
            break;

           case Pacemaker_IN_Default:
            switch (Pacemaker_P.Constant1_Value_f) {
             case ATRIUM_S:
              Pacemaker_DW.is_Inhibit = Pacemaker_IN_Atrium;
              Pacemaker_B.B_LED = false;
              break;

             case VENTRICLE_S:
              Pacemaker_DW.is_Inhibit = Pacemaker_IN_Ventricular;
              break;

             default:
              Pacemaker_B.B_LED = false;
              break;
            }
            break;

           case Pacemaker_IN_Ventricular:
            break;

           case Pacemaker_IN_test:
            if (Pacemaker_DW.temporalCounter_i1 >= 200U) {
              Pacemaker_DW.is_Inhibit = Pacemaker_IN_Atrium;
              Pacemaker_B.B_LED = false;
            }
            break;
          }
        }
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */
}

static void Pacemaker_SystemCore_release(const freedomk64f_DigitalRead_Pacem_T
  *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void Pacemaker_SystemCore_delete(const freedomk64f_DigitalRead_Pacem_T
  *obj)
{
  Pacemaker_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(freedomk64f_DigitalRead_Pacem_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Pacemaker_SystemCore_delete(obj);
  }
}

static void Pacemaker_SystemCore_release_j0(const
  freedomk64f_DigitalWrite_Pace_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void Pacemaker_SystemCore_delete_j0(const freedomk64f_DigitalWrite_Pace_T
  *obj)
{
  Pacemaker_SystemCore_release_j0(obj);
}

static void matlabCodegenHandle_matlabCo_j0(freedomk64f_DigitalWrite_Pace_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Pacemaker_SystemCore_delete_j0(obj);
  }
}

/* Model step function */
void Pacemaker_step(void)
{
  real_T rtb_Switch1;

  /* MATLABSystem: '<S2>/Digital Read' */
  if (Pacemaker_DW.obj.SampleTime != Pacemaker_P.DigitalRead_SampleTime) {
    Pacemaker_DW.obj.SampleTime = Pacemaker_P.DigitalRead_SampleTime;
  }

  Pacemaker_B.DigitalRead = MW_digitalIO_read
    (Pacemaker_DW.obj.MW_DIGITALIO_HANDLE);

  /* End of MATLABSystem: '<S2>/Digital Read' */

  /* MATLABSystem: '<S2>/Digital Read1' */
  if (Pacemaker_DW.obj_n.SampleTime != Pacemaker_P.DigitalRead1_SampleTime) {
    Pacemaker_DW.obj_n.SampleTime = Pacemaker_P.DigitalRead1_SampleTime;
  }

  MW_digitalIO_read(Pacemaker_DW.obj_n.MW_DIGITALIO_HANDLE);

  /* End of MATLABSystem: '<S2>/Digital Read1' */

  /* Chart: '<Root>/Chart' */
  if (Pacemaker_DW.temporalCounter_i1 < 255U) {
    Pacemaker_DW.temporalCounter_i1++;
  }

  Pacemaker_DW.sfEvent = Pacemaker_CALL_EVENT;
  Pacemaker_c2_Pacemaker();

  /* End of Chart: '<Root>/Chart' */

  /* MATLABSystem: '<S3>/Digital Write' */
  MW_digitalIO_write(Pacemaker_DW.obj_o.MW_DIGITALIO_HANDLE, Pacemaker_B.R_LED);

  /* MATLABSystem: '<S3>/Digital Write4' */
  MW_digitalIO_write(Pacemaker_DW.obj_p.MW_DIGITALIO_HANDLE, Pacemaker_B.B_LED);

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S3>/Constant'
   */
  if (Pacemaker_B.senseSwitch) {
    rtb_Switch1 = Pacemaker_P.Constant_Value;
  } else {
    rtb_Switch1 = 0.0;
  }

  /* End of Switch: '<S3>/Switch' */

  /* MATLABSystem: '<S3>/Digital Write1' */
  MW_digitalIO_write(Pacemaker_DW.obj_nc.MW_DIGITALIO_HANDLE, rtb_Switch1 != 0.0);

  /* Switch: '<S3>/Switch1' incorporates:
   *  Constant: '<S3>/Constant1'
   */
  if (Pacemaker_B.senseSwitch) {
    rtb_Switch1 = Pacemaker_P.Constant1_Value;
  } else {
    rtb_Switch1 = 0.0;
  }

  /* End of Switch: '<S3>/Switch1' */

  /* MATLABSystem: '<S3>/Digital Write2' */
  MW_digitalIO_write(Pacemaker_DW.obj_e.MW_DIGITALIO_HANDLE, rtb_Switch1 != 0.0);

  /* MATLABSystem: '<S3>/Digital Write3' */
  MW_digitalIO_write(Pacemaker_DW.obj_pz.MW_DIGITALIO_HANDLE, rtb_Switch1 != 0.0);
}

/* Model initialize function */
void Pacemaker_initialize(void)
{
  {
    freedomk64f_DigitalRead_Pacem_T *obj;
    freedomk64f_DigitalWrite_Pace_T *obj_0;

    /* SystemInitialize for Chart: '<Root>/Chart' */
    Pacemaker_DW.sfEvent = Pacemaker_CALL_EVENT;

    /* Start for MATLABSystem: '<S2>/Digital Read' */
    Pacemaker_DW.obj.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj.isInitialized = 0;
    Pacemaker_DW.obj.SampleTime = -1.0;
    Pacemaker_DW.obj.matlabCodegenIsDeleted = false;
    Pacemaker_DW.obj.SampleTime = Pacemaker_P.DigitalRead_SampleTime;
    obj = &Pacemaker_DW.obj;
    Pacemaker_DW.obj.isSetupComplete = false;
    Pacemaker_DW.obj.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    Pacemaker_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Read1' */
    Pacemaker_DW.obj_n.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_n.isInitialized = 0;
    Pacemaker_DW.obj_n.SampleTime = -1.0;
    Pacemaker_DW.obj_n.matlabCodegenIsDeleted = false;
    Pacemaker_DW.obj_n.SampleTime = Pacemaker_P.DigitalRead1_SampleTime;
    obj = &Pacemaker_DW.obj_n;
    Pacemaker_DW.obj_n.isSetupComplete = false;
    Pacemaker_DW.obj_n.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    Pacemaker_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write' */
    Pacemaker_DW.obj_o.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_o.isInitialized = 0;
    Pacemaker_DW.obj_o.matlabCodegenIsDeleted = false;
    obj_0 = &Pacemaker_DW.obj_o;
    Pacemaker_DW.obj_o.isSetupComplete = false;
    Pacemaker_DW.obj_o.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(42U, 1);
    Pacemaker_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write4' */
    Pacemaker_DW.obj_p.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_p.isInitialized = 0;
    Pacemaker_DW.obj_p.matlabCodegenIsDeleted = false;
    obj_0 = &Pacemaker_DW.obj_p;
    Pacemaker_DW.obj_p.isSetupComplete = false;
    Pacemaker_DW.obj_p.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(44U, 1);
    Pacemaker_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write1' */
    Pacemaker_DW.obj_nc.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_nc.isInitialized = 0;
    Pacemaker_DW.obj_nc.matlabCodegenIsDeleted = false;
    obj_0 = &Pacemaker_DW.obj_nc;
    Pacemaker_DW.obj_nc.isSetupComplete = false;
    Pacemaker_DW.obj_nc.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    Pacemaker_DW.obj_nc.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write2' */
    Pacemaker_DW.obj_e.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_e.isInitialized = 0;
    Pacemaker_DW.obj_e.matlabCodegenIsDeleted = false;
    obj_0 = &Pacemaker_DW.obj_e;
    Pacemaker_DW.obj_e.isSetupComplete = false;
    Pacemaker_DW.obj_e.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(3U, 1);
    Pacemaker_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write3' */
    Pacemaker_DW.obj_pz.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_pz.isInitialized = 0;
    Pacemaker_DW.obj_pz.matlabCodegenIsDeleted = false;
    obj_0 = &Pacemaker_DW.obj_pz;
    Pacemaker_DW.obj_pz.isSetupComplete = false;
    Pacemaker_DW.obj_pz.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(6U, 1);
    Pacemaker_DW.obj_pz.isSetupComplete = true;
  }
}

/* Model terminate function */
void Pacemaker_terminate(void)
{
  /* Terminate for MATLABSystem: '<S2>/Digital Read' */
  matlabCodegenHandle_matlabCodeg(&Pacemaker_DW.obj);

  /* Terminate for MATLABSystem: '<S2>/Digital Read1' */
  matlabCodegenHandle_matlabCodeg(&Pacemaker_DW.obj_n);

  /* Terminate for MATLABSystem: '<S3>/Digital Write' */
  matlabCodegenHandle_matlabCo_j0(&Pacemaker_DW.obj_o);

  /* Terminate for MATLABSystem: '<S3>/Digital Write4' */
  matlabCodegenHandle_matlabCo_j0(&Pacemaker_DW.obj_p);

  /* Terminate for MATLABSystem: '<S3>/Digital Write1' */
  matlabCodegenHandle_matlabCo_j0(&Pacemaker_DW.obj_nc);

  /* Terminate for MATLABSystem: '<S3>/Digital Write2' */
  matlabCodegenHandle_matlabCo_j0(&Pacemaker_DW.obj_e);

  /* Terminate for MATLABSystem: '<S3>/Digital Write3' */
  matlabCodegenHandle_matlabCo_j0(&Pacemaker_DW.obj_pz);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
