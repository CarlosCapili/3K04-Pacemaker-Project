/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Pacemaker.c
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

#include "Pacemaker.h"
#include "Pacemaker_private.h"
#include "rt_roundd_snf.h"
#include "rt_roundf_snf.h"

/* Named constants for Chart: '<Root>/Chart' */
#define Pacemaker_CALL_EVENT           (-1)
#define Pacemaker_IN_Atrium            ((uint8_T)1U)
#define Pacemaker_IN_Charging          ((uint8_T)1U)
#define Pacemaker_IN_Default           ((uint8_T)2U)
#define Pacemaker_IN_Default_d         ((uint8_T)1U)
#define Pacemaker_IN_Discharging       ((uint8_T)2U)
#define Pacemaker_IN_INIT              ((uint8_T)1U)
#define Pacemaker_IN_Inhibited         ((uint8_T)2U)
#define Pacemaker_IN_InhibitedSense    ((uint8_T)2U)
#define Pacemaker_IN_Inhibited_ARP     ((uint8_T)3U)
#define Pacemaker_IN_Inhibited_VRP     ((uint8_T)3U)
#define Pacemaker_IN_NO_ACTIVE_CHILD   ((uint8_T)0U)
#define Pacemaker_IN_None              ((uint8_T)4U)
#define Pacemaker_IN_Pace              ((uint8_T)2U)
#define Pacemaker_IN_PaceSend          ((uint8_T)5U)
#define Pacemaker_IN_Sense             ((uint8_T)3U)
#define Pacemaker_IN_Tiggered          ((uint8_T)6U)
#define Pacemaker_IN_Ventricle         ((uint8_T)3U)
#define Pacemaker_IN_paceAtr           ((uint8_T)3U)
#define Pacemaker_IN_paceVent          ((uint8_T)4U)
#define Pacemaker_event_V_PaceBypass   (3)
#define Pacemaker_event_Vent_Bypass    (5)
#define Pacemaker_event_paceEnd        (8)
#define Pacemaker_event_paceStart      (9)

/* Named constants for Chart: '<Root>/SerialReceive' */
#define Pacemaker_IN_Init              ((uint8_T)1U)
#define Pacemaker_IN_SettingParameters ((uint8_T)2U)
#define Pacemaker_IN_Standby           ((uint8_T)3U)

/* Block signals (default storage) */
B_Pacemaker_T Pacemaker_B;

/* Block states (default storage) */
DW_Pacemaker_T Pacemaker_DW;

/* Real-time model */
RT_MODEL_Pacemaker_T Pacemaker_M_;
RT_MODEL_Pacemaker_T *const Pacemaker_M = &Pacemaker_M_;

/* Forward declaration for local functions */
static void Pacemaker_broadcast_paceEnd(void);
static void Pacemaker_enter_atomic_Charging(void);
static void Pacemaker_broadcast_paceStart(void);
static void Pacemaker_enter_atomic_PaceSend(void);
static real_T Pacemaker_ventSense(ChamberPaced a, ChamberSensed b);
static real_T Pacemaker_atrSense(ChamberPaced a, ChamberSensed b);
static void Pacemak_enter_atomic_PaceSend_p(void);
static void Pacemaker_Sense(void);
static void Pacemaker_c2_Pacemaker(void);
static void Pacemaker_SystemCore_release_j(const freedomk64f_SCIRead_Pacemaker_T
  *obj);
static void Pacemaker_SystemCore_delete_j(const freedomk64f_SCIRead_Pacemaker_T *
  obj);
static void matlabCodegenHandle_matlabCod_j(freedomk64f_SCIRead_Pacemaker_T *obj);
static void Pacemaker_SystemCore_release_j0(const
  freedomk64f_DigitalRead_Pacem_T *obj);
static void Pacemaker_SystemCore_delete_j0(const freedomk64f_DigitalRead_Pacem_T
  *obj);
static void matlabCodegenHandle_matlabCo_j0(freedomk64f_DigitalRead_Pacem_T *obj);
static void Pacemak_SystemCore_release_j04j(const
  freedomk64f_DigitalWrite_Pace_T *obj);
static void Pacemake_SystemCore_delete_j04j(const
  freedomk64f_DigitalWrite_Pace_T *obj);
static void matlabCodegenHandle_matlab_j04j(freedomk64f_DigitalWrite_Pace_T *obj);
static void Pacema_SystemCore_release_j04js(const
  freedomk64f_PWMOutput_Pacemak_T *obj);
static void Pacemak_SystemCore_delete_j04js(const
  freedomk64f_PWMOutput_Pacemak_T *obj);
static void matlabCodegenHandle_matla_j04js(freedomk64f_PWMOutput_Pacemak_T *obj);
static void Pacemaker_SystemCore_setup_j(freedomk64f_SCIRead_Pacemaker_T *obj);

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
static void Pacemaker_enter_atomic_Charging(void)
{
  Pacemaker_B.PACE_GND_CTRL = true;
  Pacemaker_B.VENT_PACE_CTRL = false;
  Pacemaker_B.ATR_PACE_CTRL = false;
  if (Pacemaker_DW.ActiveChamber == 1.0) {
    Pacemaker_B.ATR_GND_CTRL = true;
    Pacemaker_B.VENT_GND_CTRL = false;
  } else {
    Pacemaker_B.ATR_GND_CTRL = false;
    Pacemaker_B.VENT_GND_CTRL = true;
  }

  Pacemaker_B.PACING_REF_PWM = (uint32_T)rt_roundd_snf((real_T)
    Pacemaker_B.DataTypeConversion4 / 5.0);
  Pacemaker_B.PACE_CHARGE_CTRL = true;
  Pacemaker_broadcast_paceEnd();
}

/* Function for Chart: '<Root>/Chart' */
static void Pacemaker_broadcast_paceStart(void)
{
  int32_T b_previousEvent;
  b_previousEvent = Pacemaker_DW.sfEvent;
  Pacemaker_DW.sfEvent = Pacemaker_event_paceStart;

  /* Chart: '<Root>/Chart' */
  Pacemaker_c2_Pacemaker();
  Pacemaker_DW.sfEvent = b_previousEvent;
}

/* Function for Chart: '<Root>/Chart' */
static void Pacemaker_enter_atomic_PaceSend(void)
{
  Pacemaker_broadcast_paceStart();
}

/* Function for Chart: '<Root>/Chart' */
static real_T Pacemaker_ventSense(ChamberPaced a, ChamberSensed b)
{
  real_T v;
  if (a == VENTRICLE_P) {
    v = 1.0;
  } else {
    v = (b == VENTRICLE_S);
  }

  return v;
}

/* Function for Chart: '<Root>/Chart' */
static real_T Pacemaker_atrSense(ChamberPaced a, ChamberSensed b)
{
  real_T v;
  switch (a) {
   case ATRIUM_P:
    v = 1.0;
    break;

   case DUAL_P:
    v = 1.0;
    break;

   default:
    switch (b) {
     case ATRIUM_S:
      v = 1.0;
      break;

     case DUAL_S:
      v = 1.0;
      break;

     default:
      v = 0.0;
      break;
    }
    break;
  }

  return v;
}

/* Function for Chart: '<Root>/Chart' */
static void Pacemak_enter_atomic_PaceSend_p(void)
{
  Pacemaker_broadcast_paceStart();
}

/* Function for Chart: '<Root>/Chart' */
static void Pacemaker_Sense(void)
{
  uint32_T qY;
  if (Pacemaker_DW.sfEvent == Pacemaker_event_paceStart) {
    Pacemaker_DW.is_Atrium = Pacemaker_IN_NO_ACTIVE_CHILD;
    Pacemaker_DW.is_Ventricle = Pacemaker_IN_NO_ACTIVE_CHILD;
    Pacemaker_DW.is_Sense = Pacemaker_IN_NO_ACTIVE_CHILD;
    Pacemaker_DW.is_c2_Pacemaker = Pacemaker_IN_Pace;
    Pacemaker_DW.is_Pace = Pacemaker_IN_Discharging;
    Pacemaker_B.PACE_CHARGE_CTRL = false;
    Pacemaker_B.PACE_GND_CTRL = true;
    Pacemaker_B.ATR_GND_CTRL = false;
    Pacemaker_B.VENT_GND_CTRL = false;
  } else {
    switch (Pacemaker_DW.is_Sense) {
     case Pacemaker_IN_Atrium:
      if (Pacemaker_DW.sfEvent == Pacemaker_event_V_PaceBypass) {
        Pacemaker_DW.is_Atrium = Pacemaker_IN_NO_ACTIVE_CHILD;
        Pacemaker_DW.is_Sense = Pacemaker_IN_Ventricle;
        Pacemaker_DW.is_Ventricle = Pacemaker_IN_Default_d;
        Pacemaker_DW.ActiveChamber = 2.0;
      } else {
        switch (Pacemaker_DW.is_Atrium) {
         case Pacemaker_IN_Default_d:
          switch (Pacemaker_B.y3) {
           case DUAL_A:
            Pacemaker_DW.is_Atrium = Pacemaker_IN_Tiggered;
            break;

           case NONE_A:
            Pacemaker_DW.is_Atrium = Pacemaker_IN_None;
            Pacemaker_DW.temporalCounter_i1 = 0U;
            break;

           case INHIBITED_A:
            Pacemaker_DW.is_Atrium = Pacemaker_IN_Inhibited_ARP;
            Pacemaker_DW.temporalCounter_i1 = 0U;
            break;

           default:
            Pacemaker_DW.ActiveChamber = 1.0;
            break;
          }
          break;

         case Pacemaker_IN_InhibitedSense:
          qY = (uint32_T)Pacemaker_B.DataTypeConversion1 - /*MW:OvSatOk*/
            Pacemaker_B.ARP_j;
          if (qY > Pacemaker_B.DataTypeConversion1) {
            qY = 0U;
          }

          qY += 10U;
          if (qY > 65535U) {
            qY = 65535U;
          }

          if (Pacemaker_DW.temporalCounter_i1 >= qY) {
            Pacemaker_DW.is_Atrium = Pacemaker_IN_PaceSend;
            Pacemaker_enter_atomic_PaceSend();
          } else {
            if (Pacemaker_B.ATR_CMP_DETECT) {
              Pacemaker_DW.is_Atrium = Pacemaker_IN_NO_ACTIVE_CHILD;
              Pacemaker_DW.is_Sense = Pacemaker_IN_Default;
            }
          }
          break;

         case Pacemaker_IN_Inhibited_ARP:
          qY = (uint32_T)Pacemaker_B.ARP_j - /*MW:OvSatOk*/
            Pacemaker_B.DataTypeConversion5;
          if (qY > Pacemaker_B.ARP_j) {
            qY = 0U;
          }

          if (Pacemaker_DW.temporalCounter_i1 >= qY) {
            Pacemaker_DW.is_Atrium = Pacemaker_IN_InhibitedSense;
            Pacemaker_DW.temporalCounter_i1 = 0U;
          }
          break;

         case Pacemaker_IN_None:
          if (Pacemaker_DW.temporalCounter_i1 >= Pacemaker_B.DataTypeConversion1)
          {
            Pacemaker_DW.is_Atrium = Pacemaker_IN_PaceSend;
            Pacemaker_enter_atomic_PaceSend();
          }
          break;

         case Pacemaker_IN_PaceSend:
          Pacemaker_broadcast_paceStart();
          break;

         case Pacemaker_IN_Tiggered:
          break;
        }
      }
      break;

     case Pacemaker_IN_Default:
      if (Pacemaker_ventSense(Pacemaker_B.y1, Pacemaker_B.y2) == 1.0) {
        Pacemaker_DW.is_Sense = Pacemaker_IN_Ventricle;
        Pacemaker_DW.is_Ventricle = Pacemaker_IN_Default_d;
        Pacemaker_DW.ActiveChamber = 2.0;
      } else {
        if (Pacemaker_atrSense(Pacemaker_B.y1, Pacemaker_B.y2) == 1.0) {
          Pacemaker_DW.is_Sense = Pacemaker_IN_Atrium;
          Pacemaker_DW.is_Atrium = Pacemaker_IN_Default_d;
          Pacemaker_DW.ActiveChamber = 1.0;
        }
      }
      break;

     case Pacemaker_IN_Ventricle:
      switch (Pacemaker_DW.is_Ventricle) {
       case Pacemaker_IN_Default_d:
        switch (Pacemaker_B.y3) {
         case INHIBITED_A:
          Pacemaker_DW.is_Ventricle = Pacemaker_IN_Inhibited_VRP;
          Pacemaker_DW.temporalCounter_i1 = 0U;
          break;

         case NONE_A:
          Pacemaker_DW.is_Ventricle = Pacemaker_IN_None;
          Pacemaker_DW.temporalCounter_i1 = 0U;
          break;

         default:
          Pacemaker_DW.ActiveChamber = 2.0;
          break;
        }
        break;

       case Pacemaker_IN_Inhibited:
        qY = (uint32_T)Pacemaker_B.DataTypeConversion1 - /*MW:OvSatOk*/
          Pacemaker_B.VRP_g;
        if (qY > Pacemaker_B.DataTypeConversion1) {
          qY = 0U;
        }

        qY += 12U;
        if (qY > 65535U) {
          qY = 65535U;
        }

        if (Pacemaker_DW.temporalCounter_i1 >= qY) {
          Pacemaker_DW.is_Ventricle = Pacemaker_IN_PaceSend;
          Pacemak_enter_atomic_PaceSend_p();
        } else {
          if (Pacemaker_B.VENT_CMP_DETECT) {
            Pacemaker_DW.is_Ventricle = Pacemaker_IN_NO_ACTIVE_CHILD;
            Pacemaker_DW.is_Sense = Pacemaker_IN_Default;
          }
        }
        break;

       case Pacemaker_IN_Inhibited_VRP:
        qY = (uint32_T)Pacemaker_B.VRP_g - /*MW:OvSatOk*/
          Pacemaker_B.DataTypeConversion5;
        if (qY > Pacemaker_B.VRP_g) {
          qY = 0U;
        }

        if (Pacemaker_DW.temporalCounter_i1 >= qY) {
          Pacemaker_DW.is_Ventricle = Pacemaker_IN_Inhibited;
          Pacemaker_DW.temporalCounter_i1 = 0U;
        }
        break;

       case Pacemaker_IN_None:
        qY = (uint32_T)Pacemaker_B.DataTypeConversion1 - /*MW:OvSatOk*/
          Pacemaker_B.DataTypeConversion5;
        if (qY > Pacemaker_B.DataTypeConversion1) {
          qY = 0U;
        }

        if (Pacemaker_DW.temporalCounter_i1 >= qY) {
          Pacemaker_DW.is_Ventricle = Pacemaker_IN_PaceSend;
          Pacemak_enter_atomic_PaceSend_p();
        }
        break;

       case Pacemaker_IN_PaceSend:
        Pacemaker_broadcast_paceStart();
        break;
      }
      break;
    }
  }
}

/* Function for Chart: '<Root>/Chart' */
static void Pacemaker_c2_Pacemaker(void)
{
  /* Chart: '<Root>/Chart' */
  if (Pacemaker_DW.is_active_c2_Pacemaker == 0U) {
    Pacemaker_DW.is_active_c2_Pacemaker = 1U;
    Pacemaker_DW.is_c2_Pacemaker = Pacemaker_IN_INIT;
    Pacemaker_B.Z_ATR_CTRL = false;
    Pacemaker_B.Z_VENT_CTRL = false;
    Pacemaker_B.PACING_REF_PWM = (uint32_T)rt_roundd_snf((real_T)
      Pacemaker_B.DataTypeConversion4 / 5.0);
    Pacemaker_B.ATR_PACE_CTRL = false;
    Pacemaker_B.VENT_PACE_CTRL = false;
    Pacemaker_B.PACE_GND_CTRL = true;
    Pacemaker_B.ATR_GND_CTRL = false;
    Pacemaker_B.VENT_GND_CTRL = false;
    Pacemaker_B.PACE_CHARGE_CTRL = true;
    Pacemaker_B.R_LED = false;
    Pacemaker_B.B_LED = false;
  } else {
    switch (Pacemaker_DW.is_c2_Pacemaker) {
     case Pacemaker_IN_INIT:
      Pacemaker_DW.is_c2_Pacemaker = Pacemaker_IN_Sense;
      Pacemaker_DW.is_Sense = Pacemaker_IN_Default;
      break;

     case Pacemaker_IN_Pace:
      switch (Pacemaker_DW.sfEvent) {
       case Pacemaker_event_paceEnd:
        Pacemaker_DW.is_Pace = Pacemaker_IN_NO_ACTIVE_CHILD;
        Pacemaker_DW.is_c2_Pacemaker = Pacemaker_IN_Sense;
        Pacemaker_DW.is_Sense = Pacemaker_IN_Default;
        break;

       case Pacemaker_event_Vent_Bypass:
        Pacemaker_DW.is_Pace = Pacemaker_IN_NO_ACTIVE_CHILD;
        Pacemaker_DW.is_c2_Pacemaker = Pacemaker_IN_Sense;
        Pacemaker_DW.is_Sense = Pacemaker_IN_Ventricle;
        Pacemaker_DW.is_Ventricle = Pacemaker_IN_Default_d;
        Pacemaker_DW.ActiveChamber = 2.0;
        break;

       default:
        switch (Pacemaker_DW.is_Pace) {
         case Pacemaker_IN_Charging:
          Pacemaker_B.PACE_GND_CTRL = true;
          Pacemaker_B.VENT_PACE_CTRL = false;
          Pacemaker_B.ATR_PACE_CTRL = false;
          if (Pacemaker_DW.ActiveChamber == 1.0) {
            Pacemaker_B.ATR_GND_CTRL = true;
            Pacemaker_B.VENT_GND_CTRL = false;
          } else {
            Pacemaker_B.ATR_GND_CTRL = false;
            Pacemaker_B.VENT_GND_CTRL = true;
          }

          Pacemaker_B.PACING_REF_PWM = (uint32_T)rt_roundd_snf((real_T)
            Pacemaker_B.DataTypeConversion4 / 5.0);
          Pacemaker_B.PACE_CHARGE_CTRL = true;
          Pacemaker_broadcast_paceEnd();
          break;

         case Pacemaker_IN_Discharging:
          if (Pacemaker_DW.ActiveChamber == 1.0) {
            Pacemaker_DW.is_Pace = Pacemaker_IN_paceAtr;
            Pacemaker_DW.temporalCounter_i1 = 0U;
            Pacemaker_B.ATR_PACE_CTRL = true;
          } else if (Pacemaker_DW.ActiveChamber == 2.0) {
            Pacemaker_DW.is_Pace = Pacemaker_IN_paceVent;
            Pacemaker_DW.temporalCounter_i1 = 0U;
            Pacemaker_B.VENT_PACE_CTRL = true;
          } else {
            Pacemaker_B.PACE_CHARGE_CTRL = false;
            Pacemaker_B.PACE_GND_CTRL = true;
            Pacemaker_B.ATR_GND_CTRL = false;
            Pacemaker_B.VENT_GND_CTRL = false;
          }
          break;

         case Pacemaker_IN_paceAtr:
          if (Pacemaker_DW.temporalCounter_i1 >= Pacemaker_B.DataTypeConversion5)
          {
            Pacemaker_DW.is_Pace = Pacemaker_IN_Charging;
            Pacemaker_enter_atomic_Charging();
          } else {
            Pacemaker_B.ATR_PACE_CTRL = true;
          }
          break;

         case Pacemaker_IN_paceVent:
          if (Pacemaker_DW.temporalCounter_i1 >= Pacemaker_B.DataTypeConversion5)
          {
            Pacemaker_DW.is_Pace = Pacemaker_IN_Charging;
            Pacemaker_enter_atomic_Charging();
          } else {
            Pacemaker_B.VENT_PACE_CTRL = true;
          }
          break;
        }
        break;
      }
      break;

     case Pacemaker_IN_Sense:
      Pacemaker_Sense();
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */
}

static void Pacemaker_SystemCore_release_j(const freedomk64f_SCIRead_Pacemaker_T
  *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_SCI_Close(obj->MW_SCIHANDLE);
  }
}

static void Pacemaker_SystemCore_delete_j(const freedomk64f_SCIRead_Pacemaker_T *
  obj)
{
  Pacemaker_SystemCore_release_j(obj);
}

static void matlabCodegenHandle_matlabCod_j(freedomk64f_SCIRead_Pacemaker_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Pacemaker_SystemCore_delete_j(obj);
  }
}

static void Pacemaker_SystemCore_release_j0(const
  freedomk64f_DigitalRead_Pacem_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void Pacemaker_SystemCore_delete_j0(const freedomk64f_DigitalRead_Pacem_T
  *obj)
{
  Pacemaker_SystemCore_release_j0(obj);
}

static void matlabCodegenHandle_matlabCo_j0(freedomk64f_DigitalRead_Pacem_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Pacemaker_SystemCore_delete_j0(obj);
  }
}

static void Pacemak_SystemCore_release_j04j(const
  freedomk64f_DigitalWrite_Pace_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void Pacemake_SystemCore_delete_j04j(const
  freedomk64f_DigitalWrite_Pace_T *obj)
{
  Pacemak_SystemCore_release_j04j(obj);
}

static void matlabCodegenHandle_matlab_j04j(freedomk64f_DigitalWrite_Pace_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Pacemake_SystemCore_delete_j04j(obj);
  }
}

static void Pacema_SystemCore_release_j04js(const
  freedomk64f_PWMOutput_Pacemak_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_PWM_Stop(obj->MW_PWM_HANDLE);
    MW_PWM_Close(obj->MW_PWM_HANDLE);
  }
}

static void Pacemak_SystemCore_delete_j04js(const
  freedomk64f_PWMOutput_Pacemak_T *obj)
{
  Pacema_SystemCore_release_j04js(obj);
}

static void matlabCodegenHandle_matla_j04js(freedomk64f_PWMOutput_Pacemak_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Pacemak_SystemCore_delete_j04js(obj);
  }
}

static void Pacemaker_SystemCore_setup_j(freedomk64f_SCIRead_Pacemaker_T *obj)
{
  MW_SCI_Parity_Type ParityValue;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  Pacemaker_B.TxPinLoc = MW_UNDEFINED_VALUE;
  Pacemaker_B.SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&Pacemaker_B.SCIModuleLoc, false, 10U,
    Pacemaker_B.TxPinLoc);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  Pacemaker_B.StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue,
                        Pacemaker_B.StopBitsValue);
  obj->isSetupComplete = true;
}

/* Model step function */
void Pacemaker_step(void)
{
  uint8_T status;
  real_T tmp;
  real32_T v;

  /* MATLABSystem: '<Root>/Serial Receive' */
  if (Pacemaker_DW.obj_d.SampleTime != Pacemaker_P.SerialReceive_SampleTime) {
    Pacemaker_DW.obj_d.SampleTime = Pacemaker_P.SerialReceive_SampleTime;
  }

  status = MW_SCI_Receive(Pacemaker_DW.obj_d.MW_SCIHANDLE,
    Pacemaker_B.RxDataLocChar, 39U);
  memcpy((void *)&Pacemaker_B.RxData[0], (void *)&Pacemaker_B.RxDataLocChar[0],
         (uint32_T)((size_t)39 * sizeof(uint8_T)));

  /* Chart: '<Root>/SerialReceive' incorporates:
   *  MATLABSystem: '<Root>/Serial Receive'
   */
  if (Pacemaker_DW.is_active_c3_Pacemaker == 0U) {
    Pacemaker_DW.is_active_c3_Pacemaker = 1U;
    Pacemaker_DW.is_c3_Pacemaker = Pacemaker_IN_Init;
    Pacemaker_B.Mode = 0U;
    Pacemaker_B.LRL = 60U;
    Pacemaker_B.URL = 80U;
    Pacemaker_B.AtrialAmp_g = 4.0F;
    Pacemaker_B.AtrialPulseWidth_a = 10.0F;
    Pacemaker_B.VentricularAmp_o = 4.0F;
    Pacemaker_B.VentricularPulseWidth_i = 10.0F;
    Pacemaker_B.VRP_g = 200U;
    Pacemaker_B.ARP_j = 200U;
    Pacemaker_B.PVARP_m = 200U;
    Pacemaker_B.FixAVDelay_e = 40U;
    Pacemaker_B.MaxSensorRate = 120U;
    Pacemaker_B.ReactionTime = 30U;
    Pacemaker_B.ResponseFactor = 8U;
    Pacemaker_B.RecoveryTime = 5U;
    Pacemaker_B.AtrialSensitivity_d = 60.0F;
    Pacemaker_B.VentricularSensitivity_j = 60.0F;
  } else {
    switch (Pacemaker_DW.is_c3_Pacemaker) {
     case Pacemaker_IN_Init:
      Pacemaker_DW.is_c3_Pacemaker = Pacemaker_IN_Standby;
      break;

     case Pacemaker_IN_SettingParameters:
      Pacemaker_DW.is_c3_Pacemaker = Pacemaker_IN_Standby;
      break;

     default:
      /* case IN_Standby: */
      if (status == 0) {
        Pacemaker_DW.is_c3_Pacemaker = Pacemaker_IN_SettingParameters;
        Pacemaker_B.Mode = Pacemaker_B.RxData[0];
        Pacemaker_B.LRL = Pacemaker_B.RxData[1];
        Pacemaker_B.URL = Pacemaker_B.RxData[2];
        memcpy((void *)&Pacemaker_B.AtrialAmp_g, (void *)&Pacemaker_B.RxData[3],
               (uint32_T)((size_t)1 * sizeof(real32_T)));
        memcpy((void *)&Pacemaker_B.AtrialPulseWidth_a, (void *)
               &Pacemaker_B.RxData[7], (uint32_T)((size_t)1 * sizeof(real32_T)));
        memcpy((void *)&Pacemaker_B.VentricularAmp_o, (void *)
               &Pacemaker_B.RxData[11], (uint32_T)((size_t)1 * sizeof(real32_T)));
        memcpy((void *)&Pacemaker_B.VentricularPulseWidth_i, (void *)
               &Pacemaker_B.RxData[15], (uint32_T)((size_t)1 * sizeof(real32_T)));
        memcpy((void *)&Pacemaker_B.VRP_g, (void *)&Pacemaker_B.RxData[19],
               (uint32_T)((size_t)1 * sizeof(uint16_T)));
        memcpy((void *)&Pacemaker_B.ARP_j, (void *)&Pacemaker_B.RxData[21],
               (uint32_T)((size_t)1 * sizeof(uint16_T)));
        memcpy((void *)&Pacemaker_B.PVARP_m, (void *)&Pacemaker_B.RxData[23],
               (uint32_T)((size_t)1 * sizeof(uint16_T)));
        memcpy((void *)&Pacemaker_B.FixAVDelay_e, (void *)&Pacemaker_B.RxData[25],
               (uint32_T)((size_t)1 * sizeof(uint16_T)));
        Pacemaker_B.MaxSensorRate = Pacemaker_B.RxData[27];
        Pacemaker_B.ReactionTime = Pacemaker_B.RxData[28];
        Pacemaker_B.ResponseFactor = Pacemaker_B.RxData[29];
        Pacemaker_B.RecoveryTime = Pacemaker_B.RxData[30];
        memcpy((void *)&Pacemaker_B.AtrialSensitivity_d, (void *)
               &Pacemaker_B.RxData[31], (uint32_T)((size_t)1 * sizeof(real32_T)));
        memcpy((void *)&Pacemaker_B.VentricularSensitivity_j, (void *)
               &Pacemaker_B.RxData[35], (uint32_T)((size_t)1 * sizeof(real32_T)));
        send_params();
      }
      break;
    }
  }

  /* End of Chart: '<Root>/SerialReceive' */

  /* MATLAB Function: '<S4>/MATLAB Function1' */
  Pacemaker_B.y1 = ATRIUM_P;
  Pacemaker_B.y2 = ATRIUM_S;
  if (Pacemaker_B.Mode < 10) {
    Pacemaker_B.y1 = ATRIUM_P;
  } else if (Pacemaker_B.Mode < 20) {
    Pacemaker_B.y1 = VENTRICLE_P;
  } else {
    if (Pacemaker_B.Mode < 30) {
      Pacemaker_B.y1 = DUAL_P;
    }
  }

  if ((uint8_T)((uint32_T)Pacemaker_B.Mode - (int32_T)(Pacemaker_B.Mode / 5U) *
                5) == 1) {
    if (Pacemaker_B.Mode < 10) {
      Pacemaker_B.y2 = ATRIUM_S;
    } else {
      if (Pacemaker_B.Mode < 20) {
        Pacemaker_B.y2 = VENTRICLE_S;
      }
    }

    Pacemaker_B.y3 = INHIBITED_A;
  } else {
    Pacemaker_B.y2 = NONE_S;
    Pacemaker_B.y3 = NONE_A;
  }

  /* End of MATLAB Function: '<S4>/MATLAB Function1' */

  /* MATLABSystem: '<S2>/ATR_CMP_DETECT' */
  if (Pacemaker_DW.obj.SampleTime != Pacemaker_P.ATR_CMP_DETECT_SampleTime) {
    Pacemaker_DW.obj.SampleTime = Pacemaker_P.ATR_CMP_DETECT_SampleTime;
  }

  Pacemaker_B.ATR_CMP_DETECT = MW_digitalIO_read
    (Pacemaker_DW.obj.MW_DIGITALIO_HANDLE);

  /* End of MATLABSystem: '<S2>/ATR_CMP_DETECT' */

  /* MATLABSystem: '<S2>/VENT_CMP_DETECT' */
  if (Pacemaker_DW.obj_l.SampleTime != Pacemaker_P.VENT_CMP_DETECT_SampleTime) {
    Pacemaker_DW.obj_l.SampleTime = Pacemaker_P.VENT_CMP_DETECT_SampleTime;
  }

  Pacemaker_B.VENT_CMP_DETECT = MW_digitalIO_read
    (Pacemaker_DW.obj_l.MW_DIGITALIO_HANDLE);

  /* End of MATLABSystem: '<S2>/VENT_CMP_DETECT' */

  /* DataTypeConversion: '<S4>/Data Type Conversion5' */
  v = (real32_T)fabs(Pacemaker_B.AtrialPulseWidth_a);
  if (v < 8.388608E+6F) {
    if (v >= 0.5F) {
      v = (real32_T)floor(Pacemaker_B.AtrialPulseWidth_a + 0.5F);
    } else {
      v = Pacemaker_B.AtrialPulseWidth_a * 0.0F;
    }
  } else {
    v = Pacemaker_B.AtrialPulseWidth_a;
  }

  if (rtIsNaNF(v) || rtIsInfF(v)) {
    v = 0.0F;
  } else {
    v = (real32_T)fmod(v, 65536.0);
  }

  Pacemaker_B.DataTypeConversion5 = (uint16_T)(v < 0.0F ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-v : (int32_T)(uint16_T)v);

  /* End of DataTypeConversion: '<S4>/Data Type Conversion5' */

  /* DataTypeConversion: '<S4>/Data Type Conversion4' incorporates:
   *  Gain: '<S4>/Gain2'
   */
  v = rt_roundf_snf(Pacemaker_P.Gain2_Gain * Pacemaker_B.AtrialAmp_g);
  if (rtIsNaNF(v) || rtIsInfF(v)) {
    v = 0.0F;
  } else {
    v = (real32_T)fmod(v, 4.294967296E+9);
  }

  Pacemaker_B.DataTypeConversion4 = v < 0.0F ? (uint32_T)-(int32_T)(uint32_T)-v :
    (uint32_T)v;

  /* End of DataTypeConversion: '<S4>/Data Type Conversion4' */

  /* DataTypeConversion: '<S4>/Data Type Conversion1' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion'
   *  Gain: '<S4>/Gain'
   *  Math: '<S4>/Math Function'
   *
   * About '<S4>/Math Function':
   *  Operator: reciprocal
   */
  tmp = floor(1.0 / (real_T)Pacemaker_B.LRL * Pacemaker_P.Gain_Gain);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  Pacemaker_B.DataTypeConversion1 = (uint16_T)(tmp < 0.0 ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);

  /* End of DataTypeConversion: '<S4>/Data Type Conversion1' */

  /* Chart: '<Root>/Chart' */
  if (Pacemaker_DW.temporalCounter_i1 < MAX_uint32_T) {
    Pacemaker_DW.temporalCounter_i1++;
  }

  Pacemaker_DW.sfEvent = Pacemaker_CALL_EVENT;
  Pacemaker_c2_Pacemaker();

  /* End of Chart: '<Root>/Chart' */

  /* MATLABSystem: '<S3>/Z_ATR_CTRLOUT' */
  MW_digitalIO_write(Pacemaker_DW.obj_a.MW_DIGITALIO_HANDLE,
                     Pacemaker_B.Z_ATR_CTRL);

  /* MATLABSystem: '<S3>/PACING_REF_PWMOUT' */
  MW_PWM_SetDutyCycle(Pacemaker_DW.obj_m.MW_PWM_HANDLE, (real_T)
                      Pacemaker_B.PACING_REF_PWM);

  /* MATLABSystem: '<S3>/Z_VENT_CTRLOUT' */
  MW_digitalIO_write(Pacemaker_DW.obj_j.MW_DIGITALIO_HANDLE,
                     Pacemaker_B.Z_VENT_CTRL);

  /* MATLABSystem: '<S3>/ATR_PACE_CTRLOUT' */
  MW_digitalIO_write(Pacemaker_DW.obj_m1.MW_DIGITALIO_HANDLE,
                     Pacemaker_B.ATR_PACE_CTRL);

  /* MATLABSystem: '<S3>/VENT_PACE_CTRLOUT' */
  MW_digitalIO_write(Pacemaker_DW.obj_ac.MW_DIGITALIO_HANDLE,
                     Pacemaker_B.VENT_PACE_CTRL);

  /* MATLABSystem: '<S3>/PACE_GND_CTRLOUT' */
  MW_digitalIO_write(Pacemaker_DW.obj_b.MW_DIGITALIO_HANDLE,
                     Pacemaker_B.PACE_GND_CTRL);

  /* MATLABSystem: '<S3>/ATR_GND_CTRLOUT' */
  MW_digitalIO_write(Pacemaker_DW.obj_o.MW_DIGITALIO_HANDLE,
                     Pacemaker_B.ATR_GND_CTRL);

  /* MATLABSystem: '<S3>/VENT_GND_CTRLOUT' */
  MW_digitalIO_write(Pacemaker_DW.obj_bs.MW_DIGITALIO_HANDLE,
                     Pacemaker_B.VENT_GND_CTRL);

  /* MATLABSystem: '<S3>/PACE_CHARGE_CTRLOUT' */
  MW_digitalIO_write(Pacemaker_DW.obj_h.MW_DIGITALIO_HANDLE,
                     Pacemaker_B.PACE_CHARGE_CTRL);

  /* MATLABSystem: '<S3>/R_LEDOUT' */
  MW_digitalIO_write(Pacemaker_DW.obj_e.MW_DIGITALIO_HANDLE, Pacemaker_B.R_LED);

  /* MATLABSystem: '<S3>/B_LEDOUT' */
  MW_digitalIO_write(Pacemaker_DW.obj_c.MW_DIGITALIO_HANDLE, Pacemaker_B.B_LED);

  /* MATLABSystem: '<S3>/ATR_CMP_REF_PWM' */
  MW_PWM_SetDutyCycle(Pacemaker_DW.obj_lh.MW_PWM_HANDLE, (real_T)
                      Pacemaker_B.AtrialSensitivity_d);

  /* MATLABSystem: '<S3>/VENT_CMP_REF_PWM' */
  MW_PWM_SetDutyCycle(Pacemaker_DW.obj_dw.MW_PWM_HANDLE, (real_T)
                      Pacemaker_B.VentricularSensitivity_j);

  /* MATLABSystem: '<S3>/FRONTEND_CTRL1' incorporates:
   *  Constant: '<S3>/Constant2'
   */
  MW_digitalIO_write(Pacemaker_DW.obj_p.MW_DIGITALIO_HANDLE,
                     Pacemaker_P.Constant2_Value != 0.0);
}

/* Model initialize function */
void Pacemaker_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    freedomk64f_DigitalRead_Pacem_T *obj;
    freedomk64f_DigitalWrite_Pace_T *obj_0;
    freedomk64f_PWMOutput_Pacemak_T *obj_1;

    /* SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<Root>/Parameters echo' incorporates:
     *  SubSystem: '<Root>/Parameters echo'
     */
    send_params_Init();

    /* End of SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<Root>/Parameters echo' */

    /* SystemInitialize for Chart: '<Root>/Chart' */
    Pacemaker_DW.sfEvent = Pacemaker_CALL_EVENT;

    /* Start for MATLABSystem: '<Root>/Serial Receive' */
    Pacemaker_DW.obj_d.isInitialized = 0;
    Pacemaker_DW.obj_d.matlabCodegenIsDeleted = false;
    Pacemaker_DW.obj_d.SampleTime = Pacemaker_P.SerialReceive_SampleTime;
    Pacemaker_SystemCore_setup_j(&Pacemaker_DW.obj_d);

    /* Start for MATLABSystem: '<S2>/ATR_CMP_DETECT' */
    Pacemaker_DW.obj.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj.isInitialized = 0;
    Pacemaker_DW.obj.SampleTime = -1.0;
    Pacemaker_DW.obj.matlabCodegenIsDeleted = false;
    Pacemaker_DW.obj.SampleTime = Pacemaker_P.ATR_CMP_DETECT_SampleTime;
    obj = &Pacemaker_DW.obj;
    Pacemaker_DW.obj.isSetupComplete = false;
    Pacemaker_DW.obj.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    Pacemaker_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/VENT_CMP_DETECT' */
    Pacemaker_DW.obj_l.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_l.isInitialized = 0;
    Pacemaker_DW.obj_l.SampleTime = -1.0;
    Pacemaker_DW.obj_l.matlabCodegenIsDeleted = false;
    Pacemaker_DW.obj_l.SampleTime = Pacemaker_P.VENT_CMP_DETECT_SampleTime;
    obj = &Pacemaker_DW.obj_l;
    Pacemaker_DW.obj_l.isSetupComplete = false;
    Pacemaker_DW.obj_l.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    Pacemaker_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Z_ATR_CTRLOUT' */
    Pacemaker_DW.obj_a.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_a.isInitialized = 0;
    Pacemaker_DW.obj_a.matlabCodegenIsDeleted = false;
    obj_0 = &Pacemaker_DW.obj_a;
    Pacemaker_DW.obj_a.isSetupComplete = false;
    Pacemaker_DW.obj_a.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    Pacemaker_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PACING_REF_PWMOUT' */
    Pacemaker_DW.obj_m.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_m.isInitialized = 0;
    Pacemaker_DW.obj_m.matlabCodegenIsDeleted = false;
    obj_1 = &Pacemaker_DW.obj_m;
    Pacemaker_DW.obj_m.isSetupComplete = false;
    Pacemaker_DW.obj_m.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(Pacemaker_DW.obj_m.MW_PWM_HANDLE);
    Pacemaker_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Z_VENT_CTRLOUT' */
    Pacemaker_DW.obj_j.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_j.isInitialized = 0;
    Pacemaker_DW.obj_j.matlabCodegenIsDeleted = false;
    obj_0 = &Pacemaker_DW.obj_j;
    Pacemaker_DW.obj_j.isSetupComplete = false;
    Pacemaker_DW.obj_j.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    Pacemaker_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/ATR_PACE_CTRLOUT' */
    Pacemaker_DW.obj_m1.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_m1.isInitialized = 0;
    Pacemaker_DW.obj_m1.matlabCodegenIsDeleted = false;
    obj_0 = &Pacemaker_DW.obj_m1;
    Pacemaker_DW.obj_m1.isSetupComplete = false;
    Pacemaker_DW.obj_m1.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    Pacemaker_DW.obj_m1.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/VENT_PACE_CTRLOUT' */
    Pacemaker_DW.obj_ac.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_ac.isInitialized = 0;
    Pacemaker_DW.obj_ac.matlabCodegenIsDeleted = false;
    obj_0 = &Pacemaker_DW.obj_ac;
    Pacemaker_DW.obj_ac.isSetupComplete = false;
    Pacemaker_DW.obj_ac.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    Pacemaker_DW.obj_ac.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PACE_GND_CTRLOUT' */
    Pacemaker_DW.obj_b.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_b.isInitialized = 0;
    Pacemaker_DW.obj_b.matlabCodegenIsDeleted = false;
    obj_0 = &Pacemaker_DW.obj_b;
    Pacemaker_DW.obj_b.isSetupComplete = false;
    Pacemaker_DW.obj_b.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    Pacemaker_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/ATR_GND_CTRLOUT' */
    Pacemaker_DW.obj_o.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_o.isInitialized = 0;
    Pacemaker_DW.obj_o.matlabCodegenIsDeleted = false;
    obj_0 = &Pacemaker_DW.obj_o;
    Pacemaker_DW.obj_o.isSetupComplete = false;
    Pacemaker_DW.obj_o.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    Pacemaker_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/VENT_GND_CTRLOUT' */
    Pacemaker_DW.obj_bs.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_bs.isInitialized = 0;
    Pacemaker_DW.obj_bs.matlabCodegenIsDeleted = false;
    obj_0 = &Pacemaker_DW.obj_bs;
    Pacemaker_DW.obj_bs.isSetupComplete = false;
    Pacemaker_DW.obj_bs.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    Pacemaker_DW.obj_bs.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PACE_CHARGE_CTRLOUT' */
    Pacemaker_DW.obj_h.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_h.isInitialized = 0;
    Pacemaker_DW.obj_h.matlabCodegenIsDeleted = false;
    obj_0 = &Pacemaker_DW.obj_h;
    Pacemaker_DW.obj_h.isSetupComplete = false;
    Pacemaker_DW.obj_h.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    Pacemaker_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/R_LEDOUT' */
    Pacemaker_DW.obj_e.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_e.isInitialized = 0;
    Pacemaker_DW.obj_e.matlabCodegenIsDeleted = false;
    obj_0 = &Pacemaker_DW.obj_e;
    Pacemaker_DW.obj_e.isSetupComplete = false;
    Pacemaker_DW.obj_e.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(42U, 1);
    Pacemaker_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/B_LEDOUT' */
    Pacemaker_DW.obj_c.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_c.isInitialized = 0;
    Pacemaker_DW.obj_c.matlabCodegenIsDeleted = false;
    obj_0 = &Pacemaker_DW.obj_c;
    Pacemaker_DW.obj_c.isSetupComplete = false;
    Pacemaker_DW.obj_c.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(44U, 1);
    Pacemaker_DW.obj_c.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/ATR_CMP_REF_PWM' */
    Pacemaker_DW.obj_lh.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_lh.isInitialized = 0;
    Pacemaker_DW.obj_lh.matlabCodegenIsDeleted = false;
    obj_1 = &Pacemaker_DW.obj_lh;
    Pacemaker_DW.obj_lh.isSetupComplete = false;
    Pacemaker_DW.obj_lh.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(Pacemaker_DW.obj_lh.MW_PWM_HANDLE);
    Pacemaker_DW.obj_lh.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/VENT_CMP_REF_PWM' */
    Pacemaker_DW.obj_dw.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_dw.isInitialized = 0;
    Pacemaker_DW.obj_dw.matlabCodegenIsDeleted = false;
    obj_1 = &Pacemaker_DW.obj_dw;
    Pacemaker_DW.obj_dw.isSetupComplete = false;
    Pacemaker_DW.obj_dw.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
    MW_PWM_Start(Pacemaker_DW.obj_dw.MW_PWM_HANDLE);
    Pacemaker_DW.obj_dw.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/FRONTEND_CTRL1' */
    Pacemaker_DW.obj_p.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_p.isInitialized = 0;
    Pacemaker_DW.obj_p.matlabCodegenIsDeleted = false;
    obj_0 = &Pacemaker_DW.obj_p;
    Pacemaker_DW.obj_p.isSetupComplete = false;
    Pacemaker_DW.obj_p.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    Pacemaker_DW.obj_p.isSetupComplete = true;
  }
}

/* Model terminate function */
void Pacemaker_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Serial Receive' */
  matlabCodegenHandle_matlabCod_j(&Pacemaker_DW.obj_d);

  /* Terminate for S-Function (sfun_private_function_caller) generated from: '<Root>/Parameters echo' incorporates:
   *  SubSystem: '<Root>/Parameters echo'
   */
  send_params_Term();

  /* End of Terminate for S-Function (sfun_private_function_caller) generated from: '<Root>/Parameters echo' */

  /* Terminate for MATLABSystem: '<S2>/ATR_CMP_DETECT' */
  matlabCodegenHandle_matlabCo_j0(&Pacemaker_DW.obj);

  /* Terminate for MATLABSystem: '<S2>/VENT_CMP_DETECT' */
  matlabCodegenHandle_matlabCo_j0(&Pacemaker_DW.obj_l);

  /* Terminate for MATLABSystem: '<S3>/Z_ATR_CTRLOUT' */
  matlabCodegenHandle_matlab_j04j(&Pacemaker_DW.obj_a);

  /* Terminate for MATLABSystem: '<S3>/PACING_REF_PWMOUT' */
  matlabCodegenHandle_matla_j04js(&Pacemaker_DW.obj_m);

  /* Terminate for MATLABSystem: '<S3>/Z_VENT_CTRLOUT' */
  matlabCodegenHandle_matlab_j04j(&Pacemaker_DW.obj_j);

  /* Terminate for MATLABSystem: '<S3>/ATR_PACE_CTRLOUT' */
  matlabCodegenHandle_matlab_j04j(&Pacemaker_DW.obj_m1);

  /* Terminate for MATLABSystem: '<S3>/VENT_PACE_CTRLOUT' */
  matlabCodegenHandle_matlab_j04j(&Pacemaker_DW.obj_ac);

  /* Terminate for MATLABSystem: '<S3>/PACE_GND_CTRLOUT' */
  matlabCodegenHandle_matlab_j04j(&Pacemaker_DW.obj_b);

  /* Terminate for MATLABSystem: '<S3>/ATR_GND_CTRLOUT' */
  matlabCodegenHandle_matlab_j04j(&Pacemaker_DW.obj_o);

  /* Terminate for MATLABSystem: '<S3>/VENT_GND_CTRLOUT' */
  matlabCodegenHandle_matlab_j04j(&Pacemaker_DW.obj_bs);

  /* Terminate for MATLABSystem: '<S3>/PACE_CHARGE_CTRLOUT' */
  matlabCodegenHandle_matlab_j04j(&Pacemaker_DW.obj_h);

  /* Terminate for MATLABSystem: '<S3>/R_LEDOUT' */
  matlabCodegenHandle_matlab_j04j(&Pacemaker_DW.obj_e);

  /* Terminate for MATLABSystem: '<S3>/B_LEDOUT' */
  matlabCodegenHandle_matlab_j04j(&Pacemaker_DW.obj_c);

  /* Terminate for MATLABSystem: '<S3>/ATR_CMP_REF_PWM' */
  matlabCodegenHandle_matla_j04js(&Pacemaker_DW.obj_lh);

  /* Terminate for MATLABSystem: '<S3>/VENT_CMP_REF_PWM' */
  matlabCodegenHandle_matla_j04js(&Pacemaker_DW.obj_dw);

  /* Terminate for MATLABSystem: '<S3>/FRONTEND_CTRL1' */
  matlabCodegenHandle_matlab_j04j(&Pacemaker_DW.obj_p);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
