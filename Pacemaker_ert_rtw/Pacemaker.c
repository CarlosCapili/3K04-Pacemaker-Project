/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Pacemaker.c
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
#define Pacemaker_event_paceEnd        (8)
#define Pacemaker_event_paceStart      (9)

/* Named constants for Chart: '<S5>/Chart' */
#define Pacemaker_IN_IncreaseHeartRate ((uint8_T)1U)
#define Pacemaker_IN_Inital            ((uint8_T)2U)
#define Pacemaker_IN_NoActivity        ((uint8_T)3U)
#define Pacemaker_IN_ReturnToLowerRate ((uint8_T)4U)
#define Pacemaker_IN_SenseActivity     ((uint8_T)5U)
#define Pacemaker_IN_SensorRateAchieved ((uint8_T)6U)

/* Named constants for Chart: '<Root>/Serial Communication' */
#define Pacemaker_IN_Init              ((uint8_T)1U)
#define Pacemaker_IN_Reset             ((uint8_T)2U)
#define Pacemaker_IN_SettingParameters ((uint8_T)3U)
#define Pacemaker_IN_Standby           ((uint8_T)4U)

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
static real_T Pacemaker_dualSense(ChamberPaced a, ChamberSensed b);
static void Pacemaker_broadcast_paceStart(void);
static void Pacemak_enter_atomic_PaceSend_p(void);
static real_T Pacemaker_ventSense(ChamberPaced a, ChamberSensed b);
static real_T Pacemaker_atrSense(ChamberPaced a, ChamberSensed b);
static void Pacemaker_enter_atomic_PaceSend(void);
static void Pacemaker_Sense(void);
static void Pacemaker_c2_Pacemaker(void);
static void Pacemaker_SystemCore_release_j(const freedomk64f_SCIRead_Pacemaker_T
  *obj);
static void Pacemaker_SystemCore_delete_j(const freedomk64f_SCIRead_Pacemaker_T *
  obj);
static void matlabCodegenHandle_matlabCod_j(freedomk64f_SCIRead_Pacemaker_T *obj);
static void Pacemak_SystemCore_release_j04j(const
  freedomk64f_AnalogInput_Pacem_T *obj);
static void Pacemake_SystemCore_delete_j04j(const
  freedomk64f_AnalogInput_Pacem_T *obj);
static void matlabCodegenHandle_matlab_j04j(freedomk64f_AnalogInput_Pacem_T *obj);
static void Pacemaker_SystemCore_release_j0(const
  freedomk64f_DigitalRead_Pacem_T *obj);
static void Pacemaker_SystemCore_delete_j0(const freedomk64f_DigitalRead_Pacem_T
  *obj);
static void matlabCodegenHandle_matlabCo_j0(freedomk64f_DigitalRead_Pacem_T *obj);
static void P_SystemCore_rele_f(const freedomk64f_fxos8700_Pacemake_T *obj);
static void P_SystemCore_dele_f(const freedomk64f_fxos8700_Pacemake_T *obj);
static void Pacemaker_matlabCodegenHa_f(freedomk64f_fxos8700_Pacemake_T *obj);
static void P_SystemCore_rele_g(b_freedomk64f_I2CMasterWrite__T *obj);
static void P_SystemCore_dele_g(b_freedomk64f_I2CMasterWrite__T *obj);
static void Pacemaker_matlabCodegenHa_g(b_freedomk64f_I2CMasterWrite__T *obj);
static void Pacem_SystemCore_release_j04jso(const
  freedomk64f_DigitalWrite_Pace_T *obj);
static void Pacema_SystemCore_delete_j04jso(const
  freedomk64f_DigitalWrite_Pace_T *obj);
static void matlabCodegenHandle_matl_j04jso(freedomk64f_DigitalWrite_Pace_T *obj);
static void Pace_SystemCore_release_j04jsox(const
  freedomk64f_PWMOutput_Pacemak_T *obj);
static void Pacem_SystemCore_delete_j04jsox(const
  freedomk64f_PWMOutput_Pacemak_T *obj);
static void matlabCodegenHandle_mat_j04jsox(freedomk64f_PWMOutput_Pacemak_T *obj);
static void Pacemaker_SystemCore_setup_j(freedomk64f_SCIRead_Pacemaker_T *obj);
static void Pacemaker_SystemCore_setup_j0(freedomk64f_fxos8700_Pacemake_T *obj);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Pacemaker_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Pacemaker_M, 1));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Pacemaker_M->Timing.TaskCounters.TID[1])++;
  if ((Pacemaker_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.002s, 0.0s] */
    Pacemaker_M->Timing.TaskCounters.TID[1] = 0;
  }
}

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
    Pacemaker_DW.pulseAmp / 5.0);
  Pacemaker_B.PACE_CHARGE_CTRL = true;
  Pacemaker_broadcast_paceEnd();
}

/* Function for Chart: '<Root>/Chart' */
static real_T Pacemaker_dualSense(ChamberPaced a, ChamberSensed b)
{
  real_T v;
  if (a == DUAL_P) {
    v = 1.0;
  } else {
    v = (b == DUAL_S);
  }

  return v;
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
static void Pacemak_enter_atomic_PaceSend_p(void)
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
static void Pacemaker_enter_atomic_PaceSend(void)
{
  Pacemaker_broadcast_paceStart();
}

/* Function for Chart: '<Root>/Chart' */
static void Pacemaker_Sense(void)
{
  uint32_T qY;
  uint32_T tmp;
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
      switch (Pacemaker_DW.is_Atrium) {
       case Pacemaker_IN_Default_d:
        switch (Pacemaker_B.y3) {
         case DUAL_A:
          Pacemaker_DW.is_Atrium = Pacemaker_IN_Tiggered;
          break;

         case NONE_A:
          Pacemaker_DW.is_Atrium = Pacemaker_IN_None;
          Pacemaker_DW.temporalCounter_i1_p = 0U;
          break;

         case INHIBITED_A:
          Pacemaker_DW.is_Atrium = Pacemaker_IN_Inhibited_ARP;
          Pacemaker_DW.temporalCounter_i1_p = 0U;
          break;

         default:
          Pacemaker_DW.ActiveChamber = 1.0;
          Pacemaker_DW.pulseWidth = Pacemaker_B.DataTypeConversion5;
          Pacemaker_DW.pulseAmp = Pacemaker_B.DataTypeConversion4;
          break;
        }
        break;

       case Pacemaker_IN_InhibitedSense:
        qY = (uint32_T)Pacemaker_B.DataTypeConversion3 - /*MW:OvSatOk*/
          Pacemaker_B.ARP_b;
        if (qY > Pacemaker_B.DataTypeConversion3) {
          qY = 0U;
        }

        tmp = qY + 10U;
        if (tmp > 65535U) {
          tmp = 65535U;
        }

        if ((Pacemaker_DW.temporalCounter_i1_p << 1) >= tmp) {
          Pacemaker_DW.is_Atrium = Pacemaker_IN_PaceSend;
          Pacemak_enter_atomic_PaceSend_p();
        } else {
          if (Pacemaker_B.ATR_CMP_DETECT) {
            Pacemaker_DW.is_Atrium = Pacemaker_IN_NO_ACTIVE_CHILD;
            Pacemaker_DW.is_Sense = Pacemaker_IN_Default;
          }
        }
        break;

       case Pacemaker_IN_Inhibited_ARP:
        qY = (uint32_T)Pacemaker_B.ARP_b - /*MW:OvSatOk*/
          Pacemaker_DW.pulseWidth;
        if (qY > Pacemaker_B.ARP_b) {
          qY = 0U;
        }

        if ((Pacemaker_DW.temporalCounter_i1_p << 1) >= qY) {
          Pacemaker_DW.is_Atrium = Pacemaker_IN_InhibitedSense;
          Pacemaker_DW.temporalCounter_i1_p = 0U;
        }
        break;

       case Pacemaker_IN_None:
        if ((Pacemaker_DW.temporalCounter_i1_p << 1) >=
            Pacemaker_B.DataTypeConversion3) {
          Pacemaker_DW.is_Atrium = Pacemaker_IN_PaceSend;
          Pacemak_enter_atomic_PaceSend_p();
        }
        break;

       case Pacemaker_IN_PaceSend:
        Pacemaker_broadcast_paceStart();
        break;

       case Pacemaker_IN_Tiggered:
        break;
      }
      break;

     case Pacemaker_IN_Default:
      if (Pacemaker_ventSense(Pacemaker_B.y1, Pacemaker_B.y2) == 1.0) {
        Pacemaker_DW.is_Sense = Pacemaker_IN_Ventricle;
        Pacemaker_DW.is_Ventricle = Pacemaker_IN_Default_d;
        Pacemaker_DW.ActiveChamber = 2.0;
        Pacemaker_DW.pulseWidth = Pacemaker_B.DataTypeConversion7;
        Pacemaker_DW.pulseAmp = Pacemaker_B.DataTypeConversion6;
      } else {
        if (Pacemaker_atrSense(Pacemaker_B.y1, Pacemaker_B.y2) == 1.0) {
          Pacemaker_DW.is_Sense = Pacemaker_IN_Atrium;
          Pacemaker_DW.is_Atrium = Pacemaker_IN_Default_d;
          Pacemaker_DW.ActiveChamber = 1.0;
          Pacemaker_DW.pulseWidth = Pacemaker_B.DataTypeConversion5;
          Pacemaker_DW.pulseAmp = Pacemaker_B.DataTypeConversion4;
        }
      }
      break;

     case Pacemaker_IN_Ventricle:
      switch (Pacemaker_DW.is_Ventricle) {
       case Pacemaker_IN_Default_d:
        switch (Pacemaker_B.y3) {
         case INHIBITED_A:
          Pacemaker_DW.is_Ventricle = Pacemaker_IN_Inhibited_VRP;
          Pacemaker_DW.temporalCounter_i1_p = 0U;
          break;

         case NONE_A:
          Pacemaker_DW.is_Ventricle = Pacemaker_IN_None;
          Pacemaker_DW.temporalCounter_i1_p = 0U;
          break;

         default:
          Pacemaker_DW.ActiveChamber = 2.0;
          Pacemaker_DW.pulseWidth = Pacemaker_B.DataTypeConversion7;
          Pacemaker_DW.pulseAmp = Pacemaker_B.DataTypeConversion6;
          break;
        }
        break;

       case Pacemaker_IN_Inhibited:
        qY = (uint32_T)Pacemaker_B.DataTypeConversion3 - /*MW:OvSatOk*/
          Pacemaker_B.VRP_j;
        if (qY > Pacemaker_B.DataTypeConversion3) {
          qY = 0U;
        }

        tmp = qY + 12U;
        if (tmp > 65535U) {
          tmp = 65535U;
        }

        if ((Pacemaker_DW.temporalCounter_i1_p << 1) >= tmp) {
          Pacemaker_DW.is_Ventricle = Pacemaker_IN_PaceSend;
          Pacemaker_enter_atomic_PaceSend();
        } else {
          if (Pacemaker_B.VENT_CMP_DETECT) {
            Pacemaker_DW.is_Ventricle = Pacemaker_IN_NO_ACTIVE_CHILD;
            Pacemaker_DW.is_Sense = Pacemaker_IN_Default;
          }
        }
        break;

       case Pacemaker_IN_Inhibited_VRP:
        qY = (uint32_T)Pacemaker_B.VRP_j - /*MW:OvSatOk*/
          Pacemaker_DW.pulseWidth;
        if (qY > Pacemaker_B.VRP_j) {
          qY = 0U;
        }

        if ((Pacemaker_DW.temporalCounter_i1_p << 1) >= qY) {
          Pacemaker_DW.is_Ventricle = Pacemaker_IN_Inhibited;
          Pacemaker_DW.temporalCounter_i1_p = 0U;
        }
        break;

       case Pacemaker_IN_None:
        qY = (uint32_T)Pacemaker_B.DataTypeConversion3 - /*MW:OvSatOk*/
          Pacemaker_DW.pulseWidth;
        if (qY > Pacemaker_B.DataTypeConversion3) {
          qY = 0U;
        }

        tmp = Pacemaker_DW.temporalCounter_i1_p << 1;
        if (((tmp >= Pacemaker_B.FixAVDelay_e) && (Pacemaker_dualSense
              (Pacemaker_B.y1, Pacemaker_B.y2) != 0.0)) || (tmp >= qY)) {
          Pacemaker_DW.is_Ventricle = Pacemaker_IN_PaceSend;
          Pacemaker_enter_atomic_PaceSend();
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
    if (Pacemaker_B.y1 == VENTRICLE_P) {
      Pacemaker_DW.pulseAmp = Pacemaker_B.DataTypeConversion6;
    } else {
      Pacemaker_DW.pulseAmp = Pacemaker_B.DataTypeConversion4;
    }

    Pacemaker_B.PACING_REF_PWM = (uint32_T)rt_roundd_snf((real_T)
      Pacemaker_DW.pulseAmp / 5.0);
    Pacemaker_B.ATR_PACE_CTRL = false;
    Pacemaker_B.VENT_PACE_CTRL = false;
    Pacemaker_B.PACE_GND_CTRL = true;
    Pacemaker_B.ATR_GND_CTRL = false;
    Pacemaker_B.VENT_GND_CTRL = false;
    Pacemaker_B.PACE_CHARGE_CTRL = true;
    Pacemaker_B.R_LED_l = false;
    Pacemaker_B.B_LED_h = false;
  } else {
    switch (Pacemaker_DW.is_c2_Pacemaker) {
     case Pacemaker_IN_INIT:
      Pacemaker_DW.is_c2_Pacemaker = Pacemaker_IN_Sense;
      Pacemaker_DW.is_Sense = Pacemaker_IN_Default;
      break;

     case Pacemaker_IN_Pace:
      if (Pacemaker_DW.sfEvent == Pacemaker_event_paceEnd) {
        if ((Pacemaker_dualSense(Pacemaker_B.y1, Pacemaker_B.y2) != 0.0) &&
            (Pacemaker_DW.ActiveChamber == 1.0)) {
          Pacemaker_DW.is_Pace = Pacemaker_IN_NO_ACTIVE_CHILD;
          Pacemaker_DW.is_c2_Pacemaker = Pacemaker_IN_Sense;
          Pacemaker_DW.is_Sense = Pacemaker_IN_Ventricle;
          Pacemaker_DW.is_Ventricle = Pacemaker_IN_Default_d;
          Pacemaker_DW.ActiveChamber = 2.0;
          Pacemaker_DW.pulseWidth = Pacemaker_B.DataTypeConversion7;
          Pacemaker_DW.pulseAmp = Pacemaker_B.DataTypeConversion6;
        } else {
          Pacemaker_DW.is_Pace = Pacemaker_IN_NO_ACTIVE_CHILD;
          Pacemaker_DW.is_c2_Pacemaker = Pacemaker_IN_Sense;
          Pacemaker_DW.is_Sense = Pacemaker_IN_Default;
        }
      } else {
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
            Pacemaker_DW.pulseAmp / 5.0);
          Pacemaker_B.PACE_CHARGE_CTRL = true;
          Pacemaker_broadcast_paceEnd();
          break;

         case Pacemaker_IN_Discharging:
          if (Pacemaker_DW.ActiveChamber == 1.0) {
            Pacemaker_DW.is_Pace = Pacemaker_IN_paceAtr;
            Pacemaker_DW.temporalCounter_i1_p = 0U;
            Pacemaker_B.ATR_PACE_CTRL = true;
          } else if (Pacemaker_DW.ActiveChamber == 2.0) {
            Pacemaker_DW.is_Pace = Pacemaker_IN_paceVent;
            Pacemaker_DW.temporalCounter_i1_p = 0U;
            Pacemaker_B.VENT_PACE_CTRL = true;
          } else {
            Pacemaker_B.PACE_CHARGE_CTRL = false;
            Pacemaker_B.PACE_GND_CTRL = true;
            Pacemaker_B.ATR_GND_CTRL = false;
            Pacemaker_B.VENT_GND_CTRL = false;
          }
          break;

         case Pacemaker_IN_paceAtr:
          if ((Pacemaker_DW.temporalCounter_i1_p << 1) >=
              Pacemaker_DW.pulseWidth) {
            Pacemaker_DW.is_Pace = Pacemaker_IN_Charging;
            Pacemaker_enter_atomic_Charging();
          } else {
            Pacemaker_B.ATR_PACE_CTRL = true;
          }
          break;

         case Pacemaker_IN_paceVent:
          if ((Pacemaker_DW.temporalCounter_i1_p << 1) >=
              Pacemaker_DW.pulseWidth) {
            Pacemaker_DW.is_Pace = Pacemaker_IN_Charging;
            Pacemaker_enter_atomic_Charging();
          } else {
            Pacemaker_B.VENT_PACE_CTRL = true;
          }
          break;
        }
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

static void Pacemak_SystemCore_release_j04j(const
  freedomk64f_AnalogInput_Pacem_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_AnalogIn_Stop(obj->MW_ANALOGIN_HANDLE);
    MW_AnalogIn_Close(obj->MW_ANALOGIN_HANDLE);
  }
}

static void Pacemake_SystemCore_delete_j04j(const
  freedomk64f_AnalogInput_Pacem_T *obj)
{
  Pacemak_SystemCore_release_j04j(obj);
}

static void matlabCodegenHandle_matlab_j04j(freedomk64f_AnalogInput_Pacem_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Pacemake_SystemCore_delete_j04j(obj);
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

static void P_SystemCore_rele_f(const freedomk64f_fxos8700_Pacemake_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_I2C_Close(obj->i2cobj.MW_I2C_HANDLE);
  }
}

static void P_SystemCore_dele_f(const freedomk64f_fxos8700_Pacemake_T *obj)
{
  P_SystemCore_rele_f(obj);
}

static void Pacemaker_matlabCodegenHa_f(freedomk64f_fxos8700_Pacemake_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    P_SystemCore_dele_f(obj);
  }
}

static void P_SystemCore_rele_g(b_freedomk64f_I2CMasterWrite__T *obj)
{
  if (obj->isInitialized == 1) {
    obj->isInitialized = 2;
  }
}

static void P_SystemCore_dele_g(b_freedomk64f_I2CMasterWrite__T *obj)
{
  P_SystemCore_rele_g(obj);
}

static void Pacemaker_matlabCodegenHa_g(b_freedomk64f_I2CMasterWrite__T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    P_SystemCore_dele_g(obj);
  }
}

static void Pacem_SystemCore_release_j04jso(const
  freedomk64f_DigitalWrite_Pace_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void Pacema_SystemCore_delete_j04jso(const
  freedomk64f_DigitalWrite_Pace_T *obj)
{
  Pacem_SystemCore_release_j04jso(obj);
}

static void matlabCodegenHandle_matl_j04jso(freedomk64f_DigitalWrite_Pace_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Pacema_SystemCore_delete_j04jso(obj);
  }
}

static void Pace_SystemCore_release_j04jsox(const
  freedomk64f_PWMOutput_Pacemak_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_PWM_Stop(obj->MW_PWM_HANDLE);
    MW_PWM_Close(obj->MW_PWM_HANDLE);
  }
}

static void Pacem_SystemCore_delete_j04jsox(const
  freedomk64f_PWMOutput_Pacemak_T *obj)
{
  Pace_SystemCore_release_j04jsox(obj);
}

static void matlabCodegenHandle_mat_j04jsox(freedomk64f_PWMOutput_Pacemak_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Pacem_SystemCore_delete_j04jsox(obj);
  }
}

static void Pacemaker_SystemCore_setup_j(freedomk64f_SCIRead_Pacemaker_T *obj)
{
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  Pacemaker_B.TxPinLoc = MW_UNDEFINED_VALUE;
  Pacemaker_B.SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&Pacemaker_B.SCIModuleLoc, false, 10U,
    Pacemaker_B.TxPinLoc);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  Pacemaker_B.StopBitsValue = MW_SCI_STOPBITS_1;
  Pacemaker_B.ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, Pacemaker_B.ParityValue,
                        Pacemaker_B.StopBitsValue);
  obj->isSetupComplete = true;
}

static void Pacemaker_SystemCore_setup_j0(freedomk64f_fxos8700_Pacemake_T *obj)
{
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  Pacemaker_B.ModeType = MW_I2C_MASTER;
  Pacemaker_B.i2cname = 0;
  obj->i2cobj.MW_I2C_HANDLE = MW_I2C_Open(Pacemaker_B.i2cname,
    Pacemaker_B.ModeType);
  obj->i2cobj.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cobj.MW_I2C_HANDLE, obj->i2cobj.BusSpeed);
  Pacemaker_B.b_SwappedDataBytes[0] = 43U;
  Pacemaker_B.b_SwappedDataBytes[1] = 64U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
                     Pacemaker_B.b_SwappedDataBytes, 2U, false, false);
  OSA_TimeDelay(500U);
  Pacemaker_B.status = 42U;
  Pacemaker_B.status = MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
    &Pacemaker_B.status, 1U, true, false);
  if (0 == Pacemaker_B.status) {
    MW_I2C_MasterRead(obj->i2cobj.MW_I2C_HANDLE, 29U, &Pacemaker_B.status, 1U,
                      false, true);
    memcpy((void *)&Pacemaker_B.b_RegisterValue, (void *)&Pacemaker_B.status,
           (uint32_T)((size_t)1 * sizeof(uint8_T)));
  } else {
    Pacemaker_B.b_RegisterValue = 0U;
  }

  Pacemaker_B.b_SwappedDataBytes[0] = 42U;
  Pacemaker_B.b_SwappedDataBytes[1] = (uint8_T)(Pacemaker_B.b_RegisterValue &
    254);
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
                     Pacemaker_B.b_SwappedDataBytes, 2U, false, false);
  Pacemaker_B.b_SwappedDataBytes[0] = 14U;
  Pacemaker_B.b_SwappedDataBytes[1] = 1U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
                     Pacemaker_B.b_SwappedDataBytes, 2U, false, false);
  Pacemaker_B.b_SwappedDataBytes[0] = 91U;
  Pacemaker_B.b_SwappedDataBytes[1] = 0U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
                     Pacemaker_B.b_SwappedDataBytes, 2U, false, false);
  Pacemaker_B.b_SwappedDataBytes[0] = 42U;
  Pacemaker_B.b_SwappedDataBytes[1] = 1U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
                     Pacemaker_B.b_SwappedDataBytes, 2U, false, false);
  obj->isSetupComplete = true;
}

/* Model step function for TID0 */
void Pacemaker_step0(void)             /* Sample time: [0.001s, 0.0s] */
{
  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void Pacemaker_step1(void)             /* Sample time: [0.002s, 0.0s] */
{
  uint8_T status;
  int16_T b_output[3];
  uint8_T output_raw[6];
  uint8_T y[2];
  uint8_T b_x[2];
  int32_T rtb_CastToDouble;
  real_T rtb_FXOS87006AxesSensor_idx_0;
  real_T rtb_FXOS87006AxesSensor_idx_1;
  real32_T v;

  /* MATLABSystem: '<Root>/Serial Receive' */
  if (Pacemaker_DW.obj_d.SampleTime != Pacemaker_P.SerialReceive_SampleTime) {
    Pacemaker_DW.obj_d.SampleTime = Pacemaker_P.SerialReceive_SampleTime;
  }

  status = MW_SCI_Receive(Pacemaker_DW.obj_d.MW_SCIHANDLE,
    Pacemaker_B.RxDataLocChar, 40U);
  memcpy((void *)&Pacemaker_B.RxData[0], (void *)&Pacemaker_B.RxDataLocChar[0],
         (uint32_T)((size_t)40 * sizeof(uint8_T)));

  /* MATLABSystem: '<S2>/AtrSignalIn' */
  if (Pacemaker_DW.obj_f.SampleTime != Pacemaker_P.AtrSignalIn_SampleTime) {
    Pacemaker_DW.obj_f.SampleTime = Pacemaker_P.AtrSignalIn_SampleTime;
  }

  MW_AnalogIn_Start(Pacemaker_DW.obj_f.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(Pacemaker_DW.obj_f.MW_ANALOGIN_HANDLE,
    &Pacemaker_B.SquareRoot, 7);

  /* Gain: '<S2>/Gain' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion3'
   *  MATLABSystem: '<S2>/AtrSignalIn'
   */
  Pacemaker_B.Gain = Pacemaker_P.Gain_Gain * (real32_T)Pacemaker_B.SquareRoot;

  /* S-Function (sfix_udelay): '<S2>/Tapped Delay' */
  memcpy(&Pacemaker_B.TappedDelay[0], &Pacemaker_DW.TappedDelay_X[0], 24U *
         sizeof(real32_T));
  Pacemaker_B.TappedDelay[24] = Pacemaker_B.Gain;

  /* MATLABSystem: '<S2>/VentSignalIn' */
  if (Pacemaker_DW.obj_e.SampleTime != Pacemaker_P.VentSignalIn_SampleTime) {
    Pacemaker_DW.obj_e.SampleTime = Pacemaker_P.VentSignalIn_SampleTime;
  }

  MW_AnalogIn_Start(Pacemaker_DW.obj_e.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(Pacemaker_DW.obj_e.MW_ANALOGIN_HANDLE,
    &Pacemaker_B.SquareRoot, 7);

  /* Gain: '<S2>/Gain1' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion2'
   *  MATLABSystem: '<S2>/VentSignalIn'
   */
  Pacemaker_B.Gain1 = Pacemaker_P.Gain1_Gain_j * (real32_T)
    Pacemaker_B.SquareRoot;

  /* S-Function (sfix_udelay): '<S2>/Tapped Delay1' */
  memcpy(&Pacemaker_B.TappedDelay1[0], &Pacemaker_DW.TappedDelay1_X[0], 24U *
         sizeof(real32_T));
  Pacemaker_B.TappedDelay1[24] = Pacemaker_B.Gain1;

  /* Chart: '<Root>/Serial Communication' incorporates:
   *  MATLABSystem: '<Root>/Serial Receive'
   */
  if (Pacemaker_DW.is_active_c3_Pacemaker == 0U) {
    Pacemaker_DW.is_active_c3_Pacemaker = 1U;
    Pacemaker_DW.is_c3_Pacemaker = Pacemaker_IN_Init;
    Pacemaker_B.B_LED = true;
    Pacemaker_B.Mode = 0U;
    Pacemaker_B.LRL = 20U;
    Pacemaker_B.URL = 80U;
    Pacemaker_B.AtrialAmp_j = 5.0F;
    Pacemaker_B.AtrialPulseWidth_e = 10.0F;
    Pacemaker_B.VentricularAmp_b = 4.0F;
    Pacemaker_B.VentricularPulseWidth_m = 10.0F;
    Pacemaker_B.VRP_j = 200U;
    Pacemaker_B.ARP_b = 200U;
    Pacemaker_B.PVARP_c = 200U;
    Pacemaker_B.FixAVDelay_e = 40U;
    Pacemaker_B.MaxSensorRate = 120U;
    Pacemaker_B.ReactionTime = 30U;
    Pacemaker_B.ResponseFactor = 16U;
    Pacemaker_B.RecoveryTime = 5U;
    Pacemaker_B.AtrialSensitivity_e = 60.0F;
    Pacemaker_B.VentricularSensitivity_i = 60.0F;
    Pacemaker_B.ActivityThreshold = 1U;
  } else {
    switch (Pacemaker_DW.is_c3_Pacemaker) {
     case Pacemaker_IN_Init:
      Pacemaker_DW.is_c3_Pacemaker = Pacemaker_IN_Standby;
      Pacemaker_B.R_LED = false;
      Pacemaker_B.B_LED = false;
      Pacemaker_B.G_LED = true;
      break;

     case Pacemaker_IN_Reset:
      Pacemaker_DW.is_c3_Pacemaker = Pacemaker_IN_Standby;
      Pacemaker_B.R_LED = false;
      Pacemaker_B.B_LED = false;
      Pacemaker_B.G_LED = true;
      break;

     case Pacemaker_IN_SettingParameters:
      Pacemaker_DW.is_c3_Pacemaker = Pacemaker_IN_Standby;
      Pacemaker_B.R_LED = false;
      Pacemaker_B.B_LED = false;
      Pacemaker_B.G_LED = true;
      break;

     default:
      /* case IN_Standby: */
      if (status == 0) {
        if (Pacemaker_B.RxData[0] == 85) {
          Pacemaker_DW.is_c3_Pacemaker = Pacemaker_IN_Reset;
          Pacemaker_B.Type = 0U;
          Send_DCM();
        } else {
          Pacemaker_DW.is_c3_Pacemaker = Pacemaker_IN_SettingParameters;
          Pacemaker_B.Type = 1U;
          Pacemaker_B.Mode = Pacemaker_B.RxData[0];
          Pacemaker_B.LRL = Pacemaker_B.RxData[1];
          Pacemaker_B.URL = Pacemaker_B.RxData[2];
          memcpy((void *)&Pacemaker_B.AtrialAmp_j, (void *)&Pacemaker_B.RxData[3],
                 (uint32_T)((size_t)1 * sizeof(real32_T)));
          memcpy((void *)&Pacemaker_B.AtrialPulseWidth_e, (void *)
                 &Pacemaker_B.RxData[7], (uint32_T)((size_t)1 * sizeof(real32_T)));
          memcpy((void *)&Pacemaker_B.AtrialSensitivity_e, (void *)
                 &Pacemaker_B.RxData[11], (uint32_T)((size_t)1 * sizeof(real32_T)));
          memcpy((void *)&Pacemaker_B.VentricularAmp_b, (void *)
                 &Pacemaker_B.RxData[15], (uint32_T)((size_t)1 * sizeof(real32_T)));
          memcpy((void *)&Pacemaker_B.VentricularPulseWidth_m, (void *)
                 &Pacemaker_B.RxData[19], (uint32_T)((size_t)1 * sizeof(real32_T)));
          memcpy((void *)&Pacemaker_B.VentricularSensitivity_i, (void *)
                 &Pacemaker_B.RxData[23], (uint32_T)((size_t)1 * sizeof(real32_T)));
          memcpy((void *)&Pacemaker_B.VRP_j, (void *)&Pacemaker_B.RxData[27],
                 (uint32_T)((size_t)1 * sizeof(uint16_T)));
          memcpy((void *)&Pacemaker_B.ARP_b, (void *)&Pacemaker_B.RxData[29],
                 (uint32_T)((size_t)1 * sizeof(uint16_T)));
          memcpy((void *)&Pacemaker_B.PVARP_c, (void *)&Pacemaker_B.RxData[31],
                 (uint32_T)((size_t)1 * sizeof(uint16_T)));
          memcpy((void *)&Pacemaker_B.FixAVDelay_e, (void *)&Pacemaker_B.RxData
                 [33], (uint32_T)((size_t)1 * sizeof(uint16_T)));
          Pacemaker_B.MaxSensorRate = Pacemaker_B.RxData[35];
          Pacemaker_B.ReactionTime = Pacemaker_B.RxData[36];
          Pacemaker_B.ResponseFactor = Pacemaker_B.RxData[37];
          Pacemaker_B.RecoveryTime = Pacemaker_B.RxData[38];
          Pacemaker_B.ActivityThreshold = Pacemaker_B.RxData[39];
          Send_DCM();
        }
      } else {
        Pacemaker_B.R_LED = false;
        Pacemaker_B.B_LED = false;
        Pacemaker_B.G_LED = true;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Serial Communication' */

  /* MATLABSystem: '<S2>/ATR_CMP_DETECT' */
  if (Pacemaker_DW.obj_h.SampleTime != Pacemaker_P.ATR_CMP_DETECT_SampleTime) {
    Pacemaker_DW.obj_h.SampleTime = Pacemaker_P.ATR_CMP_DETECT_SampleTime;
  }

  Pacemaker_B.ATR_CMP_DETECT = MW_digitalIO_read
    (Pacemaker_DW.obj_h.MW_DIGITALIO_HANDLE);

  /* End of MATLABSystem: '<S2>/ATR_CMP_DETECT' */

  /* MATLABSystem: '<S2>/VENT_CMP_DETECT' */
  if (Pacemaker_DW.obj_l.SampleTime != Pacemaker_P.VENT_CMP_DETECT_SampleTime) {
    Pacemaker_DW.obj_l.SampleTime = Pacemaker_P.VENT_CMP_DETECT_SampleTime;
  }

  Pacemaker_B.VENT_CMP_DETECT = MW_digitalIO_read
    (Pacemaker_DW.obj_l.MW_DIGITALIO_HANDLE);

  /* End of MATLABSystem: '<S2>/VENT_CMP_DETECT' */

  /* MATLAB Function: '<S4>/MATLAB Function1' */
  Pacemaker_B.y1 = ATRIUM_P;
  Pacemaker_B.y2 = NONE_S;
  Pacemaker_B.y3 = NONE_A;
  switch (Pacemaker_B.Mode) {
   case 0:
    Pacemaker_B.y1 = ATRIUM_P;
    Pacemaker_B.y2 = NONE_S;
    Pacemaker_B.y3 = NONE_A;
    break;

   case 1:
    Pacemaker_B.y1 = ATRIUM_P;
    Pacemaker_B.y2 = ATRIUM_S;
    Pacemaker_B.y3 = INHIBITED_A;
    break;

   case 2:
    Pacemaker_B.y1 = ATRIUM_P;
    Pacemaker_B.y2 = NONE_S;
    Pacemaker_B.y3 = NONE_A;
    break;

   case 3:
    Pacemaker_B.y1 = ATRIUM_P;
    Pacemaker_B.y2 = ATRIUM_S;
    Pacemaker_B.y3 = INHIBITED_A;
    break;

   case 4:
    Pacemaker_B.y1 = VENTRICLE_P;
    Pacemaker_B.y2 = NONE_S;
    Pacemaker_B.y3 = NONE_A;
    break;

   case 5:
    Pacemaker_B.y1 = VENTRICLE_P;
    Pacemaker_B.y2 = VENTRICLE_S;
    Pacemaker_B.y3 = INHIBITED_A;
    break;

   case 6:
    Pacemaker_B.y1 = VENTRICLE_P;
    Pacemaker_B.y2 = NONE_S;
    Pacemaker_B.y3 = NONE_A;
    break;

   case 7:
    Pacemaker_B.y1 = VENTRICLE_P;
    Pacemaker_B.y2 = VENTRICLE_S;
    Pacemaker_B.y3 = INHIBITED_A;
    break;

   case 8:
    Pacemaker_B.y1 = DUAL_P;
    Pacemaker_B.y2 = NONE_S;
    Pacemaker_B.y3 = NONE_A;
    break;

   case 9:
    Pacemaker_B.y1 = DUAL_P;
    Pacemaker_B.y2 = NONE_S;
    Pacemaker_B.y3 = NONE_A;
    break;

   case 10:
    Pacemaker_B.y1 = DUAL_P;
    Pacemaker_B.y2 = DUAL_S;
    Pacemaker_B.y3 = DUAL_A;
    break;
  }

  /* End of MATLAB Function: '<S4>/MATLAB Function1' */

  /* DataTypeConversion: '<S4>/Data Type Conversion5' */
  v = (real32_T)fabs(Pacemaker_B.AtrialPulseWidth_e);
  if (v < 8.388608E+6F) {
    if (v >= 0.5F) {
      v = (real32_T)floor(Pacemaker_B.AtrialPulseWidth_e + 0.5F);
    } else {
      v = Pacemaker_B.AtrialPulseWidth_e * 0.0F;
    }
  } else {
    v = Pacemaker_B.AtrialPulseWidth_e;
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
  v = rt_roundf_snf(Pacemaker_P.Gain2_Gain * Pacemaker_B.AtrialAmp_j);
  if (rtIsNaNF(v) || rtIsInfF(v)) {
    v = 0.0F;
  } else {
    v = (real32_T)fmod(v, 4.294967296E+9);
  }

  Pacemaker_B.DataTypeConversion4 = v < 0.0F ? (uint32_T)-(int32_T)(uint32_T)-v :
    (uint32_T)v;

  /* End of DataTypeConversion: '<S4>/Data Type Conversion4' */

  /* MATLABSystem: '<S5>/FXOS8700 6-Axes Sensor' incorporates:
   *  Math: '<S5>/Square'
   */
  if (Pacemaker_DW.obj.SampleTime != Pacemaker_P.FXOS87006AxesSensor_SampleTime)
  {
    Pacemaker_DW.obj.SampleTime = Pacemaker_P.FXOS87006AxesSensor_SampleTime;
  }

  status = 1U;
  status = MW_I2C_MasterWrite(Pacemaker_DW.obj.i2cobj.MW_I2C_HANDLE, 29U,
    &status, 1U, true, false);
  if (0 == status) {
    MW_I2C_MasterRead(Pacemaker_DW.obj.i2cobj.MW_I2C_HANDLE, 29U, output_raw, 6U,
                      false, true);
    memcpy((void *)&b_output[0], (void *)&output_raw[0], (uint32_T)((size_t)3 *
            sizeof(int16_T)));
    memcpy((void *)&y[0], (void *)&b_output[0], (uint32_T)((size_t)2 * sizeof
            (uint8_T)));
    b_x[0] = y[1];
    b_x[1] = y[0];
    memcpy((void *)&b_output[0], (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
            (int16_T)));
    memcpy((void *)&y[0], (void *)&b_output[1], (uint32_T)((size_t)2 * sizeof
            (uint8_T)));
    b_x[0] = y[1];
    b_x[1] = y[0];
    memcpy((void *)&b_output[1], (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
            (int16_T)));
    memcpy((void *)&y[0], (void *)&b_output[2], (uint32_T)((size_t)2 * sizeof
            (uint8_T)));
    b_x[0] = y[1];
    b_x[1] = y[0];
    memcpy((void *)&b_output[2], (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
            (int16_T)));
  } else {
    b_output[0] = 0;
    b_output[1] = 0;
    b_output[2] = 0;
  }

  Pacemaker_B.SquareRoot = (real_T)(int16_T)(b_output[0] >> 2) * 2.0 * 0.244 /
    1000.0;
  rtb_FXOS87006AxesSensor_idx_0 = Pacemaker_B.SquareRoot *
    Pacemaker_B.SquareRoot;
  Pacemaker_B.SquareRoot = (real_T)(int16_T)(b_output[1] >> 2) * 2.0 * 0.244 /
    1000.0;
  rtb_FXOS87006AxesSensor_idx_1 = Pacemaker_B.SquareRoot *
    Pacemaker_B.SquareRoot;
  Pacemaker_B.SquareRoot = (real_T)(int16_T)(b_output[2] >> 2) * 2.0 * 0.244 /
    1000.0;

  /* End of MATLABSystem: '<S5>/FXOS8700 6-Axes Sensor' */

  /* Math: '<S5>/Square' */
  Pacemaker_B.SquareRoot *= Pacemaker_B.SquareRoot;

  /* Sqrt: '<S5>/Square Root' incorporates:
   *  Sum: '<S5>/Sum of Elements'
   */
  Pacemaker_B.SquareRoot = sqrt((rtb_FXOS87006AxesSensor_idx_0 +
    rtb_FXOS87006AxesSensor_idx_1) + Pacemaker_B.SquareRoot);

  /* Chart: '<S5>/Chart1' */
  if (Pacemaker_DW.temporalCounter_i1_pu < 7U) {
    Pacemaker_DW.temporalCounter_i1_pu++;
  }

  if (Pacemaker_DW.is_active_c5_Pacemaker == 0U) {
    Pacemaker_DW.is_active_c5_Pacemaker = 1U;
    Pacemaker_DW.temporalCounter_i1_pu = 0U;
    memcpy(&Pacemaker_B.dv[0], &Pacemaker_B.Activity_h[0], 49U * sizeof(real_T));
    memcpy(&Pacemaker_B.Activity_h[1], &Pacemaker_B.dv[0], 49U * sizeof(real_T));
    Pacemaker_B.Activity_h[0] = Pacemaker_B.SquareRoot;
  } else if (Pacemaker_DW.temporalCounter_i1_pu >= 5U) {
    Pacemaker_DW.temporalCounter_i1_pu = 0U;
    memcpy(&Pacemaker_B.dv[0], &Pacemaker_B.Activity_h[0], 49U * sizeof(real_T));
    memcpy(&Pacemaker_B.Activity_h[1], &Pacemaker_B.dv[0], 49U * sizeof(real_T));
    Pacemaker_B.Activity_h[0] = Pacemaker_B.SquareRoot;
  } else {
    memcpy(&Pacemaker_B.dv[0], &Pacemaker_B.Activity_h[0], 49U * sizeof(real_T));
    memcpy(&Pacemaker_B.Activity_h[1], &Pacemaker_B.dv[0], 49U * sizeof(real_T));
    Pacemaker_B.Activity_h[0] = Pacemaker_B.SquareRoot;
  }

  /* End of Chart: '<S5>/Chart1' */

  /* MinMax: '<S5>/Max' */
  Pacemaker_B.SquareRoot = Pacemaker_B.Activity_h[0];

  /* MinMax: '<S5>/Max1' */
  rtb_FXOS87006AxesSensor_idx_0 = Pacemaker_B.Activity_h[0];
  for (rtb_CastToDouble = 0; rtb_CastToDouble < 49; rtb_CastToDouble++) {
    /* MinMax: '<S5>/Max' incorporates:
     *  MinMax: '<S5>/Max1'
     */
    rtb_FXOS87006AxesSensor_idx_1 = Pacemaker_B.Activity_h[rtb_CastToDouble + 1];
    if ((!(Pacemaker_B.SquareRoot > rtb_FXOS87006AxesSensor_idx_1)) && (!rtIsNaN
         (rtb_FXOS87006AxesSensor_idx_1))) {
      Pacemaker_B.SquareRoot = rtb_FXOS87006AxesSensor_idx_1;
    }

    /* MinMax: '<S5>/Max1' */
    if ((!(rtb_FXOS87006AxesSensor_idx_0 < rtb_FXOS87006AxesSensor_idx_1)) &&
        (!rtIsNaN(rtb_FXOS87006AxesSensor_idx_1))) {
      rtb_FXOS87006AxesSensor_idx_0 = rtb_FXOS87006AxesSensor_idx_1;
    }
  }

  /* Sum: '<S5>/Subtract' incorporates:
   *  MinMax: '<S5>/Max'
   *  MinMax: '<S5>/Max1'
   */
  rtb_FXOS87006AxesSensor_idx_0 = Pacemaker_B.SquareRoot -
    rtb_FXOS87006AxesSensor_idx_0;

  /* Sum: '<S5>/Sum' incorporates:
   *  Gain: '<S5>/Gain'
   *  Product: '<S5>/Divide'
   */
  Pacemaker_B.SquareRoot = (real_T)(Pacemaker_P.Gain_Gain_k *
    Pacemaker_B.ResponseFactor) * 0.015625 * rtb_FXOS87006AxesSensor_idx_0 +
    (real_T)Pacemaker_B.LRL;

  /* MinMax: '<S5>/Min' */
  if (!(Pacemaker_B.SquareRoot < Pacemaker_B.MaxSensorRate)) {
    Pacemaker_B.SquareRoot = Pacemaker_B.MaxSensorRate;
  }

  /* End of MinMax: '<S5>/Min' */

  /* Sum: '<S5>/MaxSensorRate - lowerRate' */
  status = (uint8_T)(Pacemaker_B.MaxSensorRate - Pacemaker_B.LRL);

  /* DataTypeConversion: '<S5>/Cast To Double' incorporates:
   *  Product: '<S5>/accelSlope'
   */
  rtb_CastToDouble = (uint8_T)(Pacemaker_B.ReactionTime == 0U ? MAX_uint32_T :
    (uint32_T)status / Pacemaker_B.ReactionTime);

  /* Sum: '<S5>/Sum1' incorporates:
   *  Gain: '<S5>/scaleDown'
   */
  rtb_FXOS87006AxesSensor_idx_0 -= (real_T)(Pacemaker_P.scaleDown_Gain *
    Pacemaker_B.ActivityThreshold) * 0.00390625;

  /* Chart: '<S5>/Chart' incorporates:
   *  DataTypeConversion: '<S5>/Cast To Double2'
   *  DataTypeConversion: '<S5>/Cast To Double3'
   *  Product: '<S5>/decelSlope'
   */
  if (Pacemaker_DW.temporalCounter_i1 < MAX_uint32_T) {
    Pacemaker_DW.temporalCounter_i1++;
  }

  if (Pacemaker_DW.is_active_c4_Pacemaker == 0U) {
    Pacemaker_DW.is_active_c4_Pacemaker = 1U;
    Pacemaker_DW.is_c4_Pacemaker = Pacemaker_IN_Inital;
    Pacemaker_B.HeartRate = Pacemaker_B.LRL;
    Pacemaker_DW.activityTime = 0.0;
    Pacemaker_DW.noActivityTime = 0.0;
    Pacemaker_B.BLUE_LED = false;
  } else {
    switch (Pacemaker_DW.is_c4_Pacemaker) {
     case Pacemaker_IN_IncreaseHeartRate:
      Pacemaker_DW.noActivityTime = 0.0;
      if (Pacemaker_DW.temporalCounter_i1 >= (uint32_T)ceil(60.0 /
           Pacemaker_B.HeartRate * 500.0)) {
        Pacemaker_DW.activityTime = (real_T)Pacemaker_DW.temporalCounter_i1 *
          0.002;
        Pacemaker_DW.is_c4_Pacemaker = Pacemaker_IN_SenseActivity;
        Pacemaker_B.BLUE_LED = false;
      }
      break;

     case Pacemaker_IN_Inital:
      Pacemaker_DW.is_c4_Pacemaker = Pacemaker_IN_SenseActivity;
      Pacemaker_B.BLUE_LED = false;
      break;

     case Pacemaker_IN_NoActivity:
      Pacemaker_DW.activityTime = 0.0;
      if (Pacemaker_DW.temporalCounter_i1 >= (uint32_T)ceil(60.0 /
           Pacemaker_B.HeartRate * 500.0)) {
        Pacemaker_DW.noActivityTime = (real_T)Pacemaker_DW.temporalCounter_i1 *
          0.002;
        Pacemaker_DW.is_c4_Pacemaker = Pacemaker_IN_SenseActivity;
        Pacemaker_B.BLUE_LED = false;
      }
      break;

     case Pacemaker_IN_ReturnToLowerRate:
      if (Pacemaker_DW.temporalCounter_i1 >= (uint32_T)ceil(60.0 /
           Pacemaker_B.HeartRate * 500.0)) {
        Pacemaker_DW.noActivityTime = (real_T)Pacemaker_DW.temporalCounter_i1 *
          0.002;
        Pacemaker_DW.is_c4_Pacemaker = Pacemaker_IN_SenseActivity;
        Pacemaker_B.BLUE_LED = false;
      }
      break;

     case Pacemaker_IN_SenseActivity:
      if (rtb_FXOS87006AxesSensor_idx_0 <= 0.0) {
        Pacemaker_B.SquareRoot = (real_T)(uint8_T)(Pacemaker_B.RecoveryTime ==
          0U ? MAX_uint32_T : (uint32_T)status / Pacemaker_B.RecoveryTime) /
          60.0;
        if (Pacemaker_B.HeartRate - Pacemaker_B.SquareRoot *
            Pacemaker_DW.noActivityTime <= Pacemaker_B.LRL) {
          Pacemaker_DW.is_c4_Pacemaker = Pacemaker_IN_ReturnToLowerRate;
          Pacemaker_DW.temporalCounter_i1 = 0U;
          Pacemaker_B.HeartRate = Pacemaker_B.LRL;
        } else {
          Pacemaker_DW.is_c4_Pacemaker = Pacemaker_IN_NoActivity;
          Pacemaker_DW.temporalCounter_i1 = 0U;
          Pacemaker_B.HeartRate -= Pacemaker_B.SquareRoot *
            Pacemaker_DW.noActivityTime;
        }
      } else if (rtb_FXOS87006AxesSensor_idx_0 > 0.0) {
        if ((real_T)rtb_CastToDouble * Pacemaker_DW.activityTime +
            Pacemaker_B.HeartRate >= Pacemaker_B.SquareRoot) {
          Pacemaker_DW.is_c4_Pacemaker = Pacemaker_IN_SensorRateAchieved;
          Pacemaker_DW.temporalCounter_i1 = 0U;
          Pacemaker_B.HeartRate = Pacemaker_B.SquareRoot;
        } else {
          Pacemaker_B.BLUE_LED = true;
          Pacemaker_DW.is_c4_Pacemaker = Pacemaker_IN_IncreaseHeartRate;
          Pacemaker_DW.temporalCounter_i1 = 0U;
          Pacemaker_B.HeartRate += (real_T)rtb_CastToDouble *
            Pacemaker_DW.activityTime;
        }
      } else {
        Pacemaker_B.BLUE_LED = false;
      }
      break;

     default:
      /* case IN_SensorRateAchieved: */
      if (Pacemaker_DW.temporalCounter_i1 >= (uint32_T)ceil(60.0 /
           Pacemaker_B.HeartRate * 500.0)) {
        Pacemaker_DW.activityTime = (real_T)Pacemaker_DW.temporalCounter_i1 *
          0.002;
        Pacemaker_DW.is_c4_Pacemaker = Pacemaker_IN_SenseActivity;
        Pacemaker_B.BLUE_LED = false;
      }
      break;
    }
  }

  /* End of Chart: '<S5>/Chart' */

  /* DataTypeConversion: '<S5>/Data Type Conversion3' incorporates:
   *  Gain: '<S5>/Gain1'
   *  Math: '<S5>/Math Function1'
   *
   * About '<S5>/Math Function1':
   *  Operator: reciprocal
   */
  Pacemaker_B.SquareRoot = floor(1.0 / Pacemaker_B.HeartRate *
    Pacemaker_P.Gain1_Gain);
  if (rtIsNaN(Pacemaker_B.SquareRoot) || rtIsInf(Pacemaker_B.SquareRoot)) {
    Pacemaker_B.SquareRoot = 0.0;
  } else {
    Pacemaker_B.SquareRoot = fmod(Pacemaker_B.SquareRoot, 65536.0);
  }

  Pacemaker_B.DataTypeConversion3 = (uint16_T)(Pacemaker_B.SquareRoot < 0.0 ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-Pacemaker_B.SquareRoot : (int32_T)
    (uint16_T)Pacemaker_B.SquareRoot);

  /* End of DataTypeConversion: '<S5>/Data Type Conversion3' */

  /* DataTypeConversion: '<S4>/Data Type Conversion6' incorporates:
   *  Gain: '<S4>/Gain3'
   */
  v = rt_roundf_snf(Pacemaker_P.Gain3_Gain * Pacemaker_B.VentricularAmp_b);
  if (rtIsNaNF(v) || rtIsInfF(v)) {
    v = 0.0F;
  } else {
    v = (real32_T)fmod(v, 4.294967296E+9);
  }

  Pacemaker_B.DataTypeConversion6 = v < 0.0F ? (uint32_T)-(int32_T)(uint32_T)-v :
    (uint32_T)v;

  /* End of DataTypeConversion: '<S4>/Data Type Conversion6' */

  /* DataTypeConversion: '<S4>/Data Type Conversion7' */
  v = (real32_T)fabs(Pacemaker_B.VentricularPulseWidth_m);
  if (v < 8.388608E+6F) {
    if (v >= 0.5F) {
      v = (real32_T)floor(Pacemaker_B.VentricularPulseWidth_m + 0.5F);
    } else {
      v = Pacemaker_B.VentricularPulseWidth_m * 0.0F;
    }
  } else {
    v = Pacemaker_B.VentricularPulseWidth_m;
  }

  if (rtIsNaNF(v) || rtIsInfF(v)) {
    v = 0.0F;
  } else {
    v = (real32_T)fmod(v, 65536.0);
  }

  Pacemaker_B.DataTypeConversion7 = (uint16_T)(v < 0.0F ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-v : (int32_T)(uint16_T)v);

  /* End of DataTypeConversion: '<S4>/Data Type Conversion7' */

  /* Chart: '<Root>/Chart' */
  if (Pacemaker_DW.temporalCounter_i1_p < MAX_uint32_T) {
    Pacemaker_DW.temporalCounter_i1_p++;
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
  MW_digitalIO_write(Pacemaker_DW.obj_h5.MW_DIGITALIO_HANDLE,
                     Pacemaker_B.PACE_CHARGE_CTRL);

  /* MATLABSystem: '<S3>/R_LEDOUT' incorporates:
   *  Logic: '<Root>/OR'
   */
  MW_digitalIO_write(Pacemaker_DW.obj_ev.MW_DIGITALIO_HANDLE,
                     Pacemaker_B.R_LED_l || Pacemaker_B.R_LED);

  /* MATLABSystem: '<S3>/B_LEDOUT' incorporates:
   *  Logic: '<Root>/OR1'
   */
  MW_digitalIO_write(Pacemaker_DW.obj_c.MW_DIGITALIO_HANDLE, Pacemaker_B.B_LED_h
                     || Pacemaker_B.B_LED || Pacemaker_B.BLUE_LED);

  /* MATLABSystem: '<S3>/B_LEDOUT1' */
  MW_digitalIO_write(Pacemaker_DW.obj_k.MW_DIGITALIO_HANDLE, Pacemaker_B.G_LED);

  /* MATLABSystem: '<S3>/ATR_CMP_REF_PWM' */
  MW_PWM_SetDutyCycle(Pacemaker_DW.obj_lh.MW_PWM_HANDLE, (real_T)
                      Pacemaker_B.AtrialSensitivity_e);

  /* MATLABSystem: '<S3>/VENT_CMP_REF_PWM' */
  MW_PWM_SetDutyCycle(Pacemaker_DW.obj_dw.MW_PWM_HANDLE, (real_T)
                      Pacemaker_B.VentricularSensitivity_i);

  /* MATLABSystem: '<S3>/FRONTEND_CTRL1' incorporates:
   *  Constant: '<S3>/Constant2'
   */
  MW_digitalIO_write(Pacemaker_DW.obj_p.MW_DIGITALIO_HANDLE,
                     Pacemaker_P.Constant2_Value != 0.0);
  for (rtb_CastToDouble = 0; rtb_CastToDouble < 23; rtb_CastToDouble++) {
    /* Update for S-Function (sfix_udelay): '<S2>/Tapped Delay' */
    Pacemaker_DW.TappedDelay_X[rtb_CastToDouble] =
      Pacemaker_DW.TappedDelay_X[rtb_CastToDouble + 1];

    /* Update for S-Function (sfix_udelay): '<S2>/Tapped Delay1' */
    Pacemaker_DW.TappedDelay1_X[rtb_CastToDouble] =
      Pacemaker_DW.TappedDelay1_X[rtb_CastToDouble + 1];
  }

  /* Update for S-Function (sfix_udelay): '<S2>/Tapped Delay' */
  Pacemaker_DW.TappedDelay_X[23] = Pacemaker_B.Gain;

  /* Update for S-Function (sfix_udelay): '<S2>/Tapped Delay1' */
  Pacemaker_DW.TappedDelay1_X[23] = Pacemaker_B.Gain1;
}

/* Model step wrapper function for compatibility with a static main program */
void Pacemaker_step(int_T tid)
{
  switch (tid) {
   case 0 :
    Pacemaker_step0();
    break;

   case 1 :
    Pacemaker_step1();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void Pacemaker_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    freedomk64f_AnalogInput_Pacem_T *obj;
    freedomk64f_DigitalRead_Pacem_T *obj_0;
    freedomk64f_fxos8700_Pacemake_T *obj_1;
    freedomk64f_DigitalWrite_Pace_T *obj_2;
    freedomk64f_PWMOutput_Pacemak_T *obj_3;
    for (Pacemaker_B.i = 0; Pacemaker_B.i < 24; Pacemaker_B.i++) {
      /* InitializeConditions for S-Function (sfix_udelay): '<S2>/Tapped Delay' */
      Pacemaker_DW.TappedDelay_X[Pacemaker_B.i] = Pacemaker_P.TappedDelay_vinit;

      /* InitializeConditions for S-Function (sfix_udelay): '<S2>/Tapped Delay1' */
      Pacemaker_DW.TappedDelay1_X[Pacemaker_B.i] =
        Pacemaker_P.TappedDelay1_vinit;
    }

    /* SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<Root>/Serial transmit' incorporates:
     *  SubSystem: '<Root>/Serial transmit'
     */
    Send_DCM_Init();

    /* End of SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<Root>/Serial transmit' */

    /* SystemInitialize for Chart: '<Root>/Chart' */
    Pacemaker_DW.sfEvent = Pacemaker_CALL_EVENT;

    /* Start for MATLABSystem: '<Root>/Serial Receive' */
    Pacemaker_DW.obj_d.isInitialized = 0;
    Pacemaker_DW.obj_d.matlabCodegenIsDeleted = false;
    Pacemaker_DW.obj_d.SampleTime = Pacemaker_P.SerialReceive_SampleTime;
    Pacemaker_SystemCore_setup_j(&Pacemaker_DW.obj_d);

    /* Start for MATLABSystem: '<S2>/AtrSignalIn' */
    Pacemaker_DW.obj_f.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_f.isInitialized = 0;
    Pacemaker_DW.obj_f.SampleTime = -1.0;
    Pacemaker_DW.obj_f.matlabCodegenIsDeleted = false;
    Pacemaker_DW.obj_f.SampleTime = Pacemaker_P.AtrSignalIn_SampleTime;
    obj = &Pacemaker_DW.obj_f;
    Pacemaker_DW.obj_f.isSetupComplete = false;
    Pacemaker_DW.obj_f.isInitialized = 1;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(16U);
    Pacemaker_B.trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(Pacemaker_DW.obj_f.MW_ANALOGIN_HANDLE,
      Pacemaker_B.trigger_val, 0U);
    Pacemaker_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/VentSignalIn' */
    Pacemaker_DW.obj_e.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_e.isInitialized = 0;
    Pacemaker_DW.obj_e.SampleTime = -1.0;
    Pacemaker_DW.obj_e.matlabCodegenIsDeleted = false;
    Pacemaker_DW.obj_e.SampleTime = Pacemaker_P.VentSignalIn_SampleTime;
    obj = &Pacemaker_DW.obj_e;
    Pacemaker_DW.obj_e.isSetupComplete = false;
    Pacemaker_DW.obj_e.isInitialized = 1;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(17U);
    Pacemaker_B.trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(Pacemaker_DW.obj_e.MW_ANALOGIN_HANDLE,
      Pacemaker_B.trigger_val, 0U);
    Pacemaker_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/ATR_CMP_DETECT' */
    Pacemaker_DW.obj_h.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_h.isInitialized = 0;
    Pacemaker_DW.obj_h.SampleTime = -1.0;
    Pacemaker_DW.obj_h.matlabCodegenIsDeleted = false;
    Pacemaker_DW.obj_h.SampleTime = Pacemaker_P.ATR_CMP_DETECT_SampleTime;
    obj_0 = &Pacemaker_DW.obj_h;
    Pacemaker_DW.obj_h.isSetupComplete = false;
    Pacemaker_DW.obj_h.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    Pacemaker_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/VENT_CMP_DETECT' */
    Pacemaker_DW.obj_l.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_l.isInitialized = 0;
    Pacemaker_DW.obj_l.SampleTime = -1.0;
    Pacemaker_DW.obj_l.matlabCodegenIsDeleted = false;
    Pacemaker_DW.obj_l.SampleTime = Pacemaker_P.VENT_CMP_DETECT_SampleTime;
    obj_0 = &Pacemaker_DW.obj_l;
    Pacemaker_DW.obj_l.isSetupComplete = false;
    Pacemaker_DW.obj_l.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    Pacemaker_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/FXOS8700 6-Axes Sensor' */
    Pacemaker_DW.obj.i2cobj.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj.matlabCodegenIsDeleted = true;
    obj_1 = &Pacemaker_DW.obj;
    Pacemaker_DW.obj.isInitialized = 0;
    Pacemaker_DW.obj.SampleTime = -1.0;
    obj_1->i2cobj.isInitialized = 0;
    obj_1->i2cobj.matlabCodegenIsDeleted = false;
    Pacemaker_DW.obj.matlabCodegenIsDeleted = false;
    Pacemaker_DW.obj.SampleTime = Pacemaker_P.FXOS87006AxesSensor_SampleTime;
    Pacemaker_SystemCore_setup_j0(&Pacemaker_DW.obj);

    /* Start for MATLABSystem: '<S3>/Z_ATR_CTRLOUT' */
    Pacemaker_DW.obj_a.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_a.isInitialized = 0;
    Pacemaker_DW.obj_a.matlabCodegenIsDeleted = false;
    obj_2 = &Pacemaker_DW.obj_a;
    Pacemaker_DW.obj_a.isSetupComplete = false;
    Pacemaker_DW.obj_a.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    Pacemaker_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PACING_REF_PWMOUT' */
    Pacemaker_DW.obj_m.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_m.isInitialized = 0;
    Pacemaker_DW.obj_m.matlabCodegenIsDeleted = false;
    obj_3 = &Pacemaker_DW.obj_m;
    Pacemaker_DW.obj_m.isSetupComplete = false;
    Pacemaker_DW.obj_m.isInitialized = 1;
    obj_3->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(Pacemaker_DW.obj_m.MW_PWM_HANDLE);
    Pacemaker_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Z_VENT_CTRLOUT' */
    Pacemaker_DW.obj_j.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_j.isInitialized = 0;
    Pacemaker_DW.obj_j.matlabCodegenIsDeleted = false;
    obj_2 = &Pacemaker_DW.obj_j;
    Pacemaker_DW.obj_j.isSetupComplete = false;
    Pacemaker_DW.obj_j.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    Pacemaker_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/ATR_PACE_CTRLOUT' */
    Pacemaker_DW.obj_m1.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_m1.isInitialized = 0;
    Pacemaker_DW.obj_m1.matlabCodegenIsDeleted = false;
    obj_2 = &Pacemaker_DW.obj_m1;
    Pacemaker_DW.obj_m1.isSetupComplete = false;
    Pacemaker_DW.obj_m1.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    Pacemaker_DW.obj_m1.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/VENT_PACE_CTRLOUT' */
    Pacemaker_DW.obj_ac.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_ac.isInitialized = 0;
    Pacemaker_DW.obj_ac.matlabCodegenIsDeleted = false;
    obj_2 = &Pacemaker_DW.obj_ac;
    Pacemaker_DW.obj_ac.isSetupComplete = false;
    Pacemaker_DW.obj_ac.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    Pacemaker_DW.obj_ac.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PACE_GND_CTRLOUT' */
    Pacemaker_DW.obj_b.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_b.isInitialized = 0;
    Pacemaker_DW.obj_b.matlabCodegenIsDeleted = false;
    obj_2 = &Pacemaker_DW.obj_b;
    Pacemaker_DW.obj_b.isSetupComplete = false;
    Pacemaker_DW.obj_b.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    Pacemaker_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/ATR_GND_CTRLOUT' */
    Pacemaker_DW.obj_o.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_o.isInitialized = 0;
    Pacemaker_DW.obj_o.matlabCodegenIsDeleted = false;
    obj_2 = &Pacemaker_DW.obj_o;
    Pacemaker_DW.obj_o.isSetupComplete = false;
    Pacemaker_DW.obj_o.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    Pacemaker_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/VENT_GND_CTRLOUT' */
    Pacemaker_DW.obj_bs.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_bs.isInitialized = 0;
    Pacemaker_DW.obj_bs.matlabCodegenIsDeleted = false;
    obj_2 = &Pacemaker_DW.obj_bs;
    Pacemaker_DW.obj_bs.isSetupComplete = false;
    Pacemaker_DW.obj_bs.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    Pacemaker_DW.obj_bs.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PACE_CHARGE_CTRLOUT' */
    Pacemaker_DW.obj_h5.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_h5.isInitialized = 0;
    Pacemaker_DW.obj_h5.matlabCodegenIsDeleted = false;
    obj_2 = &Pacemaker_DW.obj_h5;
    Pacemaker_DW.obj_h5.isSetupComplete = false;
    Pacemaker_DW.obj_h5.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    Pacemaker_DW.obj_h5.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/R_LEDOUT' */
    Pacemaker_DW.obj_ev.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_ev.isInitialized = 0;
    Pacemaker_DW.obj_ev.matlabCodegenIsDeleted = false;
    obj_2 = &Pacemaker_DW.obj_ev;
    Pacemaker_DW.obj_ev.isSetupComplete = false;
    Pacemaker_DW.obj_ev.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(42U, 1);
    Pacemaker_DW.obj_ev.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/B_LEDOUT' */
    Pacemaker_DW.obj_c.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_c.isInitialized = 0;
    Pacemaker_DW.obj_c.matlabCodegenIsDeleted = false;
    obj_2 = &Pacemaker_DW.obj_c;
    Pacemaker_DW.obj_c.isSetupComplete = false;
    Pacemaker_DW.obj_c.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(44U, 1);
    Pacemaker_DW.obj_c.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/B_LEDOUT1' */
    Pacemaker_DW.obj_k.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_k.isInitialized = 0;
    Pacemaker_DW.obj_k.matlabCodegenIsDeleted = false;
    obj_2 = &Pacemaker_DW.obj_k;
    Pacemaker_DW.obj_k.isSetupComplete = false;
    Pacemaker_DW.obj_k.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(43U, 1);
    Pacemaker_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/ATR_CMP_REF_PWM' */
    Pacemaker_DW.obj_lh.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_lh.isInitialized = 0;
    Pacemaker_DW.obj_lh.matlabCodegenIsDeleted = false;
    obj_3 = &Pacemaker_DW.obj_lh;
    Pacemaker_DW.obj_lh.isSetupComplete = false;
    Pacemaker_DW.obj_lh.isInitialized = 1;
    obj_3->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(Pacemaker_DW.obj_lh.MW_PWM_HANDLE);
    Pacemaker_DW.obj_lh.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/VENT_CMP_REF_PWM' */
    Pacemaker_DW.obj_dw.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_dw.isInitialized = 0;
    Pacemaker_DW.obj_dw.matlabCodegenIsDeleted = false;
    obj_3 = &Pacemaker_DW.obj_dw;
    Pacemaker_DW.obj_dw.isSetupComplete = false;
    Pacemaker_DW.obj_dw.isInitialized = 1;
    obj_3->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
    MW_PWM_Start(Pacemaker_DW.obj_dw.MW_PWM_HANDLE);
    Pacemaker_DW.obj_dw.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/FRONTEND_CTRL1' */
    Pacemaker_DW.obj_p.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_p.isInitialized = 0;
    Pacemaker_DW.obj_p.matlabCodegenIsDeleted = false;
    obj_2 = &Pacemaker_DW.obj_p;
    Pacemaker_DW.obj_p.isSetupComplete = false;
    Pacemaker_DW.obj_p.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    Pacemaker_DW.obj_p.isSetupComplete = true;
  }
}

/* Model terminate function */
void Pacemaker_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Serial Receive' */
  matlabCodegenHandle_matlabCod_j(&Pacemaker_DW.obj_d);

  /* Terminate for MATLABSystem: '<S2>/AtrSignalIn' */
  matlabCodegenHandle_matlab_j04j(&Pacemaker_DW.obj_f);

  /* Terminate for MATLABSystem: '<S2>/VentSignalIn' */
  matlabCodegenHandle_matlab_j04j(&Pacemaker_DW.obj_e);

  /* Terminate for S-Function (sfun_private_function_caller) generated from: '<Root>/Serial transmit' incorporates:
   *  SubSystem: '<Root>/Serial transmit'
   */
  Send_DCM_Term();

  /* End of Terminate for S-Function (sfun_private_function_caller) generated from: '<Root>/Serial transmit' */

  /* Terminate for MATLABSystem: '<S2>/ATR_CMP_DETECT' */
  matlabCodegenHandle_matlabCo_j0(&Pacemaker_DW.obj_h);

  /* Terminate for MATLABSystem: '<S2>/VENT_CMP_DETECT' */
  matlabCodegenHandle_matlabCo_j0(&Pacemaker_DW.obj_l);

  /* Terminate for MATLABSystem: '<S5>/FXOS8700 6-Axes Sensor' */
  Pacemaker_matlabCodegenHa_f(&Pacemaker_DW.obj);
  Pacemaker_matlabCodegenHa_g(&Pacemaker_DW.obj.i2cobj);

  /* Terminate for MATLABSystem: '<S3>/Z_ATR_CTRLOUT' */
  matlabCodegenHandle_matl_j04jso(&Pacemaker_DW.obj_a);

  /* Terminate for MATLABSystem: '<S3>/PACING_REF_PWMOUT' */
  matlabCodegenHandle_mat_j04jsox(&Pacemaker_DW.obj_m);

  /* Terminate for MATLABSystem: '<S3>/Z_VENT_CTRLOUT' */
  matlabCodegenHandle_matl_j04jso(&Pacemaker_DW.obj_j);

  /* Terminate for MATLABSystem: '<S3>/ATR_PACE_CTRLOUT' */
  matlabCodegenHandle_matl_j04jso(&Pacemaker_DW.obj_m1);

  /* Terminate for MATLABSystem: '<S3>/VENT_PACE_CTRLOUT' */
  matlabCodegenHandle_matl_j04jso(&Pacemaker_DW.obj_ac);

  /* Terminate for MATLABSystem: '<S3>/PACE_GND_CTRLOUT' */
  matlabCodegenHandle_matl_j04jso(&Pacemaker_DW.obj_b);

  /* Terminate for MATLABSystem: '<S3>/ATR_GND_CTRLOUT' */
  matlabCodegenHandle_matl_j04jso(&Pacemaker_DW.obj_o);

  /* Terminate for MATLABSystem: '<S3>/VENT_GND_CTRLOUT' */
  matlabCodegenHandle_matl_j04jso(&Pacemaker_DW.obj_bs);

  /* Terminate for MATLABSystem: '<S3>/PACE_CHARGE_CTRLOUT' */
  matlabCodegenHandle_matl_j04jso(&Pacemaker_DW.obj_h5);

  /* Terminate for MATLABSystem: '<S3>/R_LEDOUT' */
  matlabCodegenHandle_matl_j04jso(&Pacemaker_DW.obj_ev);

  /* Terminate for MATLABSystem: '<S3>/B_LEDOUT' */
  matlabCodegenHandle_matl_j04jso(&Pacemaker_DW.obj_c);

  /* Terminate for MATLABSystem: '<S3>/B_LEDOUT1' */
  matlabCodegenHandle_matl_j04jso(&Pacemaker_DW.obj_k);

  /* Terminate for MATLABSystem: '<S3>/ATR_CMP_REF_PWM' */
  matlabCodegenHandle_mat_j04jsox(&Pacemaker_DW.obj_lh);

  /* Terminate for MATLABSystem: '<S3>/VENT_CMP_REF_PWM' */
  matlabCodegenHandle_mat_j04jsox(&Pacemaker_DW.obj_dw);

  /* Terminate for MATLABSystem: '<S3>/FRONTEND_CTRL1' */
  matlabCodegenHandle_matl_j04jso(&Pacemaker_DW.obj_p);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
