/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Pacemaker.c
 *
 * Code generated for Simulink model 'Pacemaker'.
 *
 * Model version                  : 1.51
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sat Oct 24 18:06:56 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Pacemaker.h"
#include "Pacemaker_private.h"
#include "Pacemaker_dt.h"

/* Named constants for Chart: '<Root>/Chart' */
#define Pacemaker_CALL_EVENT           (-1)
#define Pacemaker_IN_Atrium            (1U)
#define Pacemaker_IN_Charging          (1U)
#define Pacemaker_IN_Default           (2U)
#define Pacemaker_IN_Default_l         (1U)
#define Pacemaker_IN_Discharging       (2U)
#define Pacemaker_IN_INIT              (1U)
#define Pacemaker_IN_Inhibited         (2U)
#define Pacemaker_IN_None              (3U)
#define Pacemaker_IN_Pace              (2U)
#define Pacemaker_IN_Sense             (3U)
#define Pacemaker_IN_Tiggered          (4U)
#define Pacemaker_IN_Ventricle         (3U)
#define Pacemaker_event_A_Loop         (0)
#define Pacemaker_event_AtrSense       (1)
#define Pacemaker_event_V_Loop         (2)
#define Pacemaker_event_V_PaceBypass   (3)
#define Pacemaker_event_VentSense      (4)
#define Pacemaker_event_Vent_Bypass    (5)
#define Pacemaker_event_chargePace     (6)
#define Pacemaker_event_dischargePace  (7)
#define Pacemaker_event_paceEnd        (8)
#define Pacemaker_event_paceStart      (9)

/* Block signals (default storage) */
B_Pacemaker_T Pacemaker_B;

/* Block states (default storage) */
DW_Pacemaker_T Pacemaker_DW;

/* Real-time model */
RT_MODEL_Pacemaker_T Pacemaker_M_;
RT_MODEL_Pacemaker_T *const Pacemaker_M = &Pacemaker_M_;

/* Forward declaration for local functions */
static void Pacemaker_broadcast_VentSense(void);
static void Pacemaker_broadcast_AtrSense(void);
static void Pacemaker_enter_atomic_Default(void);
static void Pacemaker_enter_internal_Sense(void);
static void Pacemak_broadcast_dischargePace(void);
static void Pacemaker_broadcast_chargePace(void);
static void Pacemaker_broadcast_paceEnd(void);
static void Pacema_enter_atomic_Discharging(void);
static void Pacemaker_broadcast_A_Loop(void);
static void Pacemaker_broadcast_paceStart(void);
static void Pacemaker_broadcast_V_Loop(void);
static void Pacemaker_Sense(void);
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
static void Pacemake_SystemCore_release_j04(const
  freedomk64f_PWMOutput_Pacemak_T *obj);
static void Pacemaker_SystemCore_delete_j04(const
  freedomk64f_PWMOutput_Pacemak_T *obj);
static void matlabCodegenHandle_matlabC_j04(freedomk64f_PWMOutput_Pacemak_T *obj);
void mul_wide_u32(uint32_T in0, uint32_T in1, uint32_T *ptrOutBitsHi, uint32_T
                  *ptrOutBitsLo)
{
  uint32_T outBitsLo;
  uint32_T in0Lo;
  uint32_T in0Hi;
  uint32_T in1Lo;
  uint32_T in1Hi;
  uint32_T productHiLo;
  uint32_T productLoHi;
  in0Hi = in0 >> 16U;
  in0Lo = in0 & 65535U;
  in1Hi = in1 >> 16U;
  in1Lo = in1 & 65535U;
  productHiLo = in0Hi * in1Lo;
  productLoHi = in0Lo * in1Hi;
  in0Lo *= in1Lo;
  in1Lo = 0U;
  outBitsLo = (productLoHi << /*MW:OvBitwiseOk*/ 16U) + /*MW:OvCarryOk*/ in0Lo;
  if (outBitsLo < in0Lo) {
    in1Lo = 1U;
  }

  in0Lo = outBitsLo;
  outBitsLo += /*MW:OvCarryOk*/ productHiLo << /*MW:OvBitwiseOk*/ 16U;
  if (outBitsLo < in0Lo) {
    in1Lo++;
  }

  *ptrOutBitsHi = (((productLoHi >> 16U) + (productHiLo >> 16U)) + in0Hi * in1Hi)
    + in1Lo;
  *ptrOutBitsLo = outBitsLo;
}

uint32_T mul_u32_sat(uint32_T a, uint32_T b)
{
  uint32_T result;
  uint32_T u32_chi;
  mul_wide_u32(a, b, &u32_chi, &result);
  if (u32_chi) {
    result = MAX_uint32_T;
  }

  return result;
}

/* Function for Chart: '<Root>/Chart' */
static void Pacemaker_broadcast_VentSense(void)
{
  int32_T b_previousEvent;
  b_previousEvent = Pacemaker_DW.sfEvent;
  Pacemaker_DW.sfEvent = Pacemaker_event_VentSense;

  /* Chart: '<Root>/Chart' */
  Pacemaker_c2_Pacemaker();
  Pacemaker_DW.sfEvent = b_previousEvent;
}

/* Function for Chart: '<Root>/Chart' */
static void Pacemaker_broadcast_AtrSense(void)
{
  int32_T b_previousEvent;
  b_previousEvent = Pacemaker_DW.sfEvent;
  Pacemaker_DW.sfEvent = Pacemaker_event_AtrSense;

  /* Chart: '<Root>/Chart' */
  Pacemaker_c2_Pacemaker();
  Pacemaker_DW.sfEvent = b_previousEvent;
}

/* Function for Chart: '<Root>/Chart' */
static void Pacemaker_enter_atomic_Default(void)
{
  Pacemaker_B.R_LED = false;
  switch (Pacemaker_B.Constant11) {
   case ATRIUM_P:
    Pacemaker_broadcast_AtrSense();
    break;

   case DUAL_P:
    Pacemaker_broadcast_AtrSense();
    break;

   default:
    switch (Pacemaker_B.Constant9) {
     case ATRIUM_S:
      Pacemaker_broadcast_AtrSense();
      break;

     case DUAL_S:
      Pacemaker_broadcast_AtrSense();
      break;

     default:
      if (Pacemaker_B.Constant11 == VENTRICLE_P) {
        Pacemaker_broadcast_VentSense();
      } else {
        if (Pacemaker_B.Constant9 == VENTRICLE_S) {
          Pacemaker_broadcast_VentSense();
        }
      }
      break;
    }
    break;
  }
}

/* Function for Chart: '<Root>/Chart' */
static void Pacemaker_enter_internal_Sense(void)
{
  Pacemaker_DW.is_Sense = Pacemaker_IN_Default;
  Pacemaker_enter_atomic_Default();
}

/* Function for Chart: '<Root>/Chart' */
static void Pacemak_broadcast_dischargePace(void)
{
  int32_T b_previousEvent;
  b_previousEvent = Pacemaker_DW.sfEvent;
  Pacemaker_DW.sfEvent = Pacemaker_event_dischargePace;

  /* Chart: '<Root>/Chart' */
  Pacemaker_c2_Pacemaker();
  Pacemaker_DW.sfEvent = b_previousEvent;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
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
static void Pacema_enter_atomic_Discharging(void)
{
  Pacemaker_B.R_LED = false;
  Pacemaker_B.ATR_PACE_CTRL = false;
  Pacemaker_B.VENT_PACE_CTRL = false;
  if (Pacemaker_DW.sfEvent == Pacemaker_event_dischargePace) {
    Pacemaker_B.PACE_GND_CTRL = true;
    Pacemaker_B.Z_ATR_CTRL = false;
    Pacemaker_B.Z_VENT_CTRL = false;
    if (Pacemaker_DW.ActiveChamber == 1.0) {
      Pacemaker_B.ATR_GND_CTRL = true;
      Pacemaker_B.VENT_GND_CTRL = false;
    } else {
      Pacemaker_B.ATR_GND_CTRL = false;
      Pacemaker_B.VENT_GND_CTRL = true;
    }

    Pacemaker_broadcast_paceEnd();
  } else {
    Pacemaker_B.PACING_REF_PWM = mul_u32_sat((uint32_T)rt_roundd_snf((real_T)
      Pacemaker_B.Constant3 / 5.0), 100U);
    Pacemaker_B.PACE_CHARGE_CTRL = true;
    if (Pacemaker_DW.temporalCounter_i1 >= 100U) {
      Pacemaker_broadcast_chargePace();
    }
  }
}

/* Function for Chart: '<Root>/Chart' */
static void Pacemaker_broadcast_A_Loop(void)
{
  int32_T b_previousEvent;
  b_previousEvent = Pacemaker_DW.sfEvent;
  Pacemaker_DW.sfEvent = Pacemaker_event_A_Loop;

  /* Chart: '<Root>/Chart' */
  Pacemaker_c2_Pacemaker();
  Pacemaker_DW.sfEvent = b_previousEvent;
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
static void Pacemaker_broadcast_V_Loop(void)
{
  int32_T b_previousEvent;
  b_previousEvent = Pacemaker_DW.sfEvent;
  Pacemaker_DW.sfEvent = Pacemaker_event_V_Loop;

  /* Chart: '<Root>/Chart' */
  Pacemaker_c2_Pacemaker();
  Pacemaker_DW.sfEvent = b_previousEvent;
}

/* Function for Chart: '<Root>/Chart' */
static void Pacemaker_Sense(void)
{
  uint32_T qY;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  if (Pacemaker_DW.sfEvent == Pacemaker_event_paceStart) {
    Pacemaker_DW.is_Atrium = 0U;
    Pacemaker_DW.is_Ventricle = 0U;
    Pacemaker_DW.is_Sense = 0U;
    Pacemaker_DW.is_c2_Pacemaker = Pacemaker_IN_Pace;
    Pacemaker_DW.is_Pace = Pacemaker_IN_Discharging;
    Pacemaker_DW.temporalCounter_i1 = 0U;
    Pacema_enter_atomic_Discharging();
  } else {
    guard1 = false;
    guard2 = false;
    guard3 = false;
    guard4 = false;
    switch (Pacemaker_DW.is_Sense) {
     case Pacemaker_IN_Atrium:
      if (Pacemaker_DW.sfEvent == Pacemaker_event_V_PaceBypass) {
        Pacemaker_DW.is_Atrium = 0U;
        Pacemaker_DW.is_Sense = Pacemaker_IN_Ventricle;
        Pacemaker_DW.is_Ventricle = Pacemaker_IN_Default_l;
        Pacemaker_DW.ActiveChamber = 2.0;
      } else if (Pacemaker_DW.sfEvent == Pacemaker_event_A_Loop) {
        Pacemaker_DW.is_Atrium = 0U;
        Pacemaker_DW.is_Sense = Pacemaker_IN_Default;
        Pacemaker_enter_atomic_Default();
      } else {
        switch (Pacemaker_DW.is_Atrium) {
         case Pacemaker_IN_Default_l:
          if (Pacemaker_B.Constant == DUAL_A) {
            Pacemaker_DW.is_Atrium = Pacemaker_IN_Tiggered;
          } else if (Pacemaker_B.Constant == NONE_A) {
            Pacemaker_DW.is_Atrium = Pacemaker_IN_None;
            Pacemaker_DW.temporalCounter_i1 = 0U;
            qY = Pacemaker_B.Constant2 + /*MW:OvSatOk*/ 100U;
            if (qY < Pacemaker_B.Constant2) {
              qY = MAX_uint32_T;
            }

            qY = Pacemaker_B.DataTypeConversion1 - /*MW:OvSatOk*/ qY;
            if (qY > Pacemaker_B.DataTypeConversion1) {
              qY = 0U;
            }

            if (Pacemaker_DW.temporalCounter_i1 >= qY) {
              Pacemaker_broadcast_paceStart();
            }
          } else if (Pacemaker_B.Constant == INHIBITED_A) {
            Pacemaker_DW.is_Atrium = Pacemaker_IN_Inhibited;
            Pacemaker_DW.temporalCounter_i1 = 0U;
            if (Pacemaker_B.DataTypeConversion) {
              Pacemaker_broadcast_A_Loop();
              if (Pacemaker_DW.is_Atrium != Pacemaker_IN_Inhibited) {
              } else {
                guard2 = true;
              }
            } else {
              guard2 = true;
            }
          } else {
            Pacemaker_DW.ActiveChamber = 1.0;
          }
          break;

         case Pacemaker_IN_Inhibited:
          if (Pacemaker_B.DataTypeConversion) {
            Pacemaker_broadcast_A_Loop();
            if (Pacemaker_DW.is_Atrium != Pacemaker_IN_Inhibited) {
            } else {
              guard3 = true;
            }
          } else {
            guard3 = true;
          }
          break;

         case Pacemaker_IN_None:
          qY = Pacemaker_B.Constant2 + /*MW:OvSatOk*/ 100U;
          if (qY < Pacemaker_B.Constant2) {
            qY = MAX_uint32_T;
          }

          qY = Pacemaker_B.DataTypeConversion1 - /*MW:OvSatOk*/ qY;
          if (qY > Pacemaker_B.DataTypeConversion1) {
            qY = 0U;
          }

          if (Pacemaker_DW.temporalCounter_i1 >= qY) {
            Pacemaker_broadcast_paceStart();
          }
          break;

         case Pacemaker_IN_Tiggered:
          break;
        }
      }
      break;

     case Pacemaker_IN_Default:
      switch (Pacemaker_DW.sfEvent) {
       case Pacemaker_event_VentSense:
        Pacemaker_DW.is_Sense = Pacemaker_IN_Ventricle;
        Pacemaker_DW.is_Ventricle = Pacemaker_IN_Default_l;
        Pacemaker_DW.ActiveChamber = 2.0;
        break;

       case Pacemaker_event_AtrSense:
        Pacemaker_DW.is_Sense = Pacemaker_IN_Atrium;
        Pacemaker_DW.is_Atrium = Pacemaker_IN_Default_l;
        Pacemaker_DW.ActiveChamber = 1.0;
        break;

       default:
        Pacemaker_B.R_LED = false;
        switch (Pacemaker_B.Constant11) {
         case ATRIUM_P:
          Pacemaker_broadcast_AtrSense();
          break;

         case DUAL_P:
          Pacemaker_broadcast_AtrSense();
          break;

         default:
          switch (Pacemaker_B.Constant9) {
           case ATRIUM_S:
            Pacemaker_broadcast_AtrSense();
            break;

           case DUAL_S:
            Pacemaker_broadcast_AtrSense();
            break;

           default:
            if (Pacemaker_B.Constant11 == VENTRICLE_P) {
              Pacemaker_broadcast_VentSense();
            } else {
              if (Pacemaker_B.Constant9 == VENTRICLE_S) {
                Pacemaker_broadcast_VentSense();
              }
            }
            break;
          }
          break;
        }
        break;
      }
      break;

     case Pacemaker_IN_Ventricle:
      if (Pacemaker_DW.sfEvent == Pacemaker_event_V_Loop) {
        Pacemaker_DW.is_Ventricle = 0U;
        Pacemaker_DW.is_Sense = Pacemaker_IN_Default;
        Pacemaker_enter_atomic_Default();
      } else {
        switch (Pacemaker_DW.is_Ventricle) {
         case Pacemaker_IN_Default_l:
          if (Pacemaker_B.Constant == INHIBITED_A) {
            Pacemaker_DW.is_Ventricle = Pacemaker_IN_Inhibited;
            Pacemaker_DW.temporalCounter_i1 = 0U;
            if (Pacemaker_B.DataTypeConversion1_d) {
              Pacemaker_broadcast_V_Loop();
              if (Pacemaker_DW.is_Ventricle != Pacemaker_IN_Inhibited) {
              } else {
                guard1 = true;
              }
            } else {
              guard1 = true;
            }
          } else if (Pacemaker_B.Constant == NONE_A) {
            Pacemaker_DW.is_Ventricle = Pacemaker_IN_None;
            Pacemaker_DW.temporalCounter_i1 = 0U;
            Pacemaker_B.B_LED = true;
            qY = Pacemaker_B.Constant2 + /*MW:OvSatOk*/ 100U;
            if (qY < Pacemaker_B.Constant2) {
              qY = MAX_uint32_T;
            }

            qY = Pacemaker_B.DataTypeConversion1 - /*MW:OvSatOk*/ qY;
            if (qY > Pacemaker_B.DataTypeConversion1) {
              qY = 0U;
            }

            if (Pacemaker_DW.temporalCounter_i1 >= qY) {
              Pacemaker_broadcast_paceStart();
            }
          } else {
            Pacemaker_DW.ActiveChamber = 2.0;
          }
          break;

         case Pacemaker_IN_Inhibited:
          if (Pacemaker_B.DataTypeConversion1_d) {
            Pacemaker_broadcast_V_Loop();
            if (Pacemaker_DW.is_Ventricle != Pacemaker_IN_Inhibited) {
            } else {
              guard4 = true;
            }
          } else {
            guard4 = true;
          }
          break;

         case Pacemaker_IN_None:
          Pacemaker_B.B_LED = true;
          qY = Pacemaker_B.Constant2 + /*MW:OvSatOk*/ 100U;
          if (qY < Pacemaker_B.Constant2) {
            qY = MAX_uint32_T;
          }

          qY = Pacemaker_B.DataTypeConversion1 - /*MW:OvSatOk*/ qY;
          if (qY > Pacemaker_B.DataTypeConversion1) {
            qY = 0U;
          }

          if (Pacemaker_DW.temporalCounter_i1 >= qY) {
            Pacemaker_broadcast_paceStart();
          }
          break;
        }
      }
      break;
    }

    if (guard4) {
      if (Pacemaker_DW.temporalCounter_i1 >= 1000U) {
        Pacemaker_broadcast_paceStart();
      }
    }

    if (guard3) {
      if (Pacemaker_DW.temporalCounter_i1 >= 1000U) {
        Pacemaker_broadcast_paceStart();
      }
    }

    if (guard2) {
      if (Pacemaker_DW.temporalCounter_i1 >= 1000U) {
        Pacemaker_broadcast_paceStart();
      }
    }

    if (guard1) {
      if (Pacemaker_DW.temporalCounter_i1 >= 1000U) {
        Pacemaker_broadcast_paceStart();
      }
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
    Pacemaker_B.PACING_REF_PWM = 0U;
    Pacemaker_B.Z_VENT_CTRL = false;
    Pacemaker_B.ATR_PACE_CTRL = false;
    Pacemaker_B.VENT_PACE_CTRL = false;
    Pacemaker_B.PACE_GND_CTRL = false;
    Pacemaker_B.ATR_GND_CTRL = false;
    Pacemaker_B.VENT_GND_CTRL = false;
    Pacemaker_B.PACE_CHARGE_CTRL = false;
  } else {
    switch (Pacemaker_DW.is_c2_Pacemaker) {
     case Pacemaker_IN_INIT:
      Pacemaker_DW.is_c2_Pacemaker = Pacemaker_IN_Sense;
      Pacemaker_enter_internal_Sense();
      break;

     case Pacemaker_IN_Pace:
      switch (Pacemaker_DW.sfEvent) {
       case Pacemaker_event_paceEnd:
        Pacemaker_DW.is_Pace = 0U;
        Pacemaker_DW.is_c2_Pacemaker = Pacemaker_IN_Sense;
        Pacemaker_enter_internal_Sense();
        break;

       case Pacemaker_event_Vent_Bypass:
        Pacemaker_DW.is_Pace = 0U;
        Pacemaker_DW.is_c2_Pacemaker = Pacemaker_IN_Sense;
        Pacemaker_DW.is_Sense = Pacemaker_IN_Ventricle;
        Pacemaker_DW.is_Ventricle = Pacemaker_IN_Default_l;
        Pacemaker_DW.ActiveChamber = 2.0;
        break;

       default:
        switch (Pacemaker_DW.is_Pace) {
         case Pacemaker_IN_Charging:
          if (Pacemaker_DW.sfEvent == Pacemaker_event_dischargePace) {
            Pacemaker_DW.is_Pace = Pacemaker_IN_Discharging;
            Pacemaker_DW.temporalCounter_i1 = 0U;
            Pacema_enter_atomic_Discharging();
          } else {
            Pacemaker_B.R_LED = true;
            Pacemaker_B.PACE_CHARGE_CTRL = false;
            Pacemaker_B.PACE_GND_CTRL = true;
            if (Pacemaker_DW.ActiveChamber == 1.0) {
              Pacemaker_B.ATR_PACE_CTRL = true;
              Pacemaker_B.VENT_PACE_CTRL = false;
            } else {
              Pacemaker_B.ATR_PACE_CTRL = false;
              Pacemaker_B.VENT_PACE_CTRL = true;
            }

            Pacemaker_B.ATR_GND_CTRL = false;
            Pacemaker_B.Z_ATR_CTRL = false;
            Pacemaker_B.Z_VENT_CTRL = false;
            Pacemaker_B.VENT_GND_CTRL = false;
            if (Pacemaker_DW.temporalCounter_i1 >= Pacemaker_B.Constant2) {
              Pacemak_broadcast_dischargePace();
            }
          }
          break;

         case Pacemaker_IN_Discharging:
          if (Pacemaker_DW.sfEvent == Pacemaker_event_chargePace) {
            Pacemaker_DW.is_Pace = Pacemaker_IN_Charging;
            Pacemaker_DW.temporalCounter_i1 = 0U;
            Pacemaker_B.R_LED = true;
            Pacemaker_B.PACE_CHARGE_CTRL = false;
            Pacemaker_B.PACE_GND_CTRL = true;
            if (Pacemaker_DW.ActiveChamber == 1.0) {
              Pacemaker_B.ATR_PACE_CTRL = true;
              Pacemaker_B.VENT_PACE_CTRL = false;
            } else {
              Pacemaker_B.ATR_PACE_CTRL = false;
              Pacemaker_B.VENT_PACE_CTRL = true;
            }

            Pacemaker_B.ATR_GND_CTRL = false;
            Pacemaker_B.Z_ATR_CTRL = false;
            Pacemaker_B.Z_VENT_CTRL = false;
            Pacemaker_B.VENT_GND_CTRL = false;
            if (Pacemaker_DW.temporalCounter_i1 >= Pacemaker_B.Constant2) {
              Pacemak_broadcast_dischargePace();
            }
          } else {
            Pacemaker_B.R_LED = false;
            Pacemaker_B.ATR_PACE_CTRL = false;
            Pacemaker_B.VENT_PACE_CTRL = false;
            if (Pacemaker_DW.sfEvent == Pacemaker_event_dischargePace) {
              Pacemaker_B.PACE_GND_CTRL = true;
              Pacemaker_B.Z_ATR_CTRL = false;
              Pacemaker_B.Z_VENT_CTRL = false;
              if (Pacemaker_DW.ActiveChamber == 1.0) {
                Pacemaker_B.ATR_GND_CTRL = true;
                Pacemaker_B.VENT_GND_CTRL = false;
              } else {
                Pacemaker_B.ATR_GND_CTRL = false;
                Pacemaker_B.VENT_GND_CTRL = true;
              }

              Pacemaker_broadcast_paceEnd();
            } else {
              Pacemaker_B.PACING_REF_PWM = mul_u32_sat((uint32_T)rt_roundd_snf
                ((real_T)Pacemaker_B.Constant3 / 5.0), 100U);
              Pacemaker_B.PACE_CHARGE_CTRL = true;
              if (Pacemaker_DW.temporalCounter_i1 >= 100U) {
                Pacemaker_broadcast_chargePace();
              }
            }
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

static void Pacemake_SystemCore_release_j04(const
  freedomk64f_PWMOutput_Pacemak_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_PWM_Stop(obj->MW_PWM_HANDLE);
    MW_PWM_Close(obj->MW_PWM_HANDLE);
  }
}

static void Pacemaker_SystemCore_delete_j04(const
  freedomk64f_PWMOutput_Pacemak_T *obj)
{
  Pacemake_SystemCore_release_j04(obj);
}

static void matlabCodegenHandle_matlabC_j04(freedomk64f_PWMOutput_Pacemak_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Pacemaker_SystemCore_delete_j04(obj);
  }
}

/* Model step function */
void Pacemaker_step(void)
{
  real_T tmp;

  /* Constant: '<Root>/Constant10' */
  Pacemaker_B.Constant10 = Pacemaker_P.Constant10_Value;

  /* MATLABSystem: '<S2>/ATR_CMP_DETECT' */
  if (Pacemaker_DW.obj.SampleTime != Pacemaker_P.ATR_CMP_DETECT_SampleTime) {
    Pacemaker_DW.obj.SampleTime = Pacemaker_P.ATR_CMP_DETECT_SampleTime;
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  MATLABSystem: '<S2>/ATR_CMP_DETECT'
   */
  Pacemaker_B.DataTypeConversion = MW_digitalIO_read
    (Pacemaker_DW.obj.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<S2>/VENT_CMP_DETECT' */
  if (Pacemaker_DW.obj_n.SampleTime != Pacemaker_P.VENT_CMP_DETECT_SampleTime) {
    Pacemaker_DW.obj_n.SampleTime = Pacemaker_P.VENT_CMP_DETECT_SampleTime;
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion1' incorporates:
   *  MATLABSystem: '<S2>/VENT_CMP_DETECT'
   */
  Pacemaker_B.DataTypeConversion1_d = MW_digitalIO_read
    (Pacemaker_DW.obj_n.MW_DIGITALIO_HANDLE);

  /* Constant: '<Root>/Constant11' */
  Pacemaker_B.Constant11 = Pacemaker_P.Constant11_Value;

  /* Constant: '<Root>/Constant1' */
  Pacemaker_B.Constant1 = Pacemaker_P.Constant1_Value;

  /* Constant: '<Root>/Constant9' */
  Pacemaker_B.Constant9 = Pacemaker_P.Constant9_Value;

  /* Constant: '<Root>/Constant' */
  Pacemaker_B.Constant = Pacemaker_P.Constant_Value;

  /* Constant: '<Root>/Constant2' */
  Pacemaker_B.Constant2 = Pacemaker_P.Constant2_Value_h;

  /* Constant: '<Root>/Constant3' */
  Pacemaker_B.Constant3 = Pacemaker_P.Constant3_Value;

  /* Constant: '<Root>/Constant4' */
  Pacemaker_B.Constant4 = Pacemaker_P.Constant4_Value;

  /* DataTypeConversion: '<S4>/Data Type Conversion1' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion'
   *  Gain: '<S4>/Gain'
   *  Math: '<S4>/Math Function'
   *
   * About '<S4>/Math Function':
   *  Operator: reciprocal
   */
  tmp = floor(1.0 / (real_T)Pacemaker_B.Constant4 * Pacemaker_P.Gain_Gain);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  Pacemaker_B.DataTypeConversion1 = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)
    -tmp : (uint32_T)tmp;

  /* End of DataTypeConversion: '<S4>/Data Type Conversion1' */

  /* Constant: '<Root>/Constant5' */
  Pacemaker_B.Constant5 = Pacemaker_P.Constant5_Value;

  /* DataTypeConversion: '<S4>/Data Type Conversion3' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion2'
   *  Gain: '<S4>/Gain1'
   *  Math: '<S4>/Math Function1'
   *
   * About '<S4>/Math Function1':
   *  Operator: reciprocal
   */
  tmp = floor(1.0 / (real_T)Pacemaker_B.Constant5 * Pacemaker_P.Gain1_Gain);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  Pacemaker_B.DataTypeConversion3 = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)
    -tmp : (uint32_T)tmp;

  /* End of DataTypeConversion: '<S4>/Data Type Conversion3' */

  /* Constant: '<Root>/Constant6' */
  Pacemaker_B.Constant6 = Pacemaker_P.Constant6_Value;

  /* Constant: '<Root>/Constant7' */
  Pacemaker_B.Constant7 = Pacemaker_P.Constant7_Value;

  /* Constant: '<Root>/Constant8' */
  Pacemaker_B.Constant8 = Pacemaker_P.Constant8_Value;

  /* Chart: '<Root>/Chart' */
  if (Pacemaker_DW.temporalCounter_i1 < MAX_uint32_T) {
    Pacemaker_DW.temporalCounter_i1++;
  }

  Pacemaker_DW.sfEvent = Pacemaker_CALL_EVENT;
  Pacemaker_c2_Pacemaker();

  /* End of Chart: '<Root>/Chart' */

  /* MATLABSystem: '<S3>/Z_ATR_CTRLOUT' */
  MW_digitalIO_write(Pacemaker_DW.obj_p.MW_DIGITALIO_HANDLE,
                     Pacemaker_B.Z_ATR_CTRL);

  /* MATLABSystem: '<S3>/PACING_REF_PWMOUT' */
  MW_PWM_SetDutyCycle(Pacemaker_DW.obj_e.MW_PWM_HANDLE, (real_T)
                      Pacemaker_B.PACING_REF_PWM);

  /* MATLABSystem: '<S3>/Z_VENT_CTRLOUT' */
  MW_digitalIO_write(Pacemaker_DW.obj_o.MW_DIGITALIO_HANDLE,
                     Pacemaker_B.Z_VENT_CTRL);

  /* MATLABSystem: '<S3>/ATR_PACE_CTRLOUT' */
  MW_digitalIO_write(Pacemaker_DW.obj_nt.MW_DIGITALIO_HANDLE,
                     Pacemaker_B.ATR_PACE_CTRL);

  /* MATLABSystem: '<S3>/VENT_PACE_CTRLOUT' */
  MW_digitalIO_write(Pacemaker_DW.obj_b.MW_DIGITALIO_HANDLE,
                     Pacemaker_B.VENT_PACE_CTRL);

  /* MATLABSystem: '<S3>/PACE_GND_CTRLOUT' */
  MW_digitalIO_write(Pacemaker_DW.obj_j.MW_DIGITALIO_HANDLE,
                     Pacemaker_B.PACE_GND_CTRL);

  /* MATLABSystem: '<S3>/ATR_GND_CTRLOUT' */
  MW_digitalIO_write(Pacemaker_DW.obj_ju.MW_DIGITALIO_HANDLE,
                     Pacemaker_B.ATR_GND_CTRL);

  /* MATLABSystem: '<S3>/VENT_GND_CTRLOUT' */
  MW_digitalIO_write(Pacemaker_DW.obj_jq.MW_DIGITALIO_HANDLE,
                     Pacemaker_B.VENT_GND_CTRL);

  /* MATLABSystem: '<S3>/PACE_CHARGE_CTRLOUT' */
  MW_digitalIO_write(Pacemaker_DW.obj_a.MW_DIGITALIO_HANDLE,
                     Pacemaker_B.PACE_CHARGE_CTRL);

  /* MATLABSystem: '<S3>/R_LEDOUT' */
  MW_digitalIO_write(Pacemaker_DW.obj_pp.MW_DIGITALIO_HANDLE, Pacemaker_B.R_LED);

  /* MATLABSystem: '<S3>/B_LEDOUT' */
  MW_digitalIO_write(Pacemaker_DW.obj_py.MW_DIGITALIO_HANDLE, Pacemaker_B.B_LED);

  /* MATLABSystem: '<S3>/ATR_CMP_REF_PWM' incorporates:
   *  Constant: '<Root>/Constant12'
   */
  MW_PWM_SetDutyCycle(Pacemaker_DW.obj_l.MW_PWM_HANDLE, (real_T)
                      Pacemaker_P.Constant12_Value);

  /* MATLABSystem: '<S3>/VENT_CMP_REF_PWM' incorporates:
   *  Constant: '<Root>/Constant13'
   */
  MW_PWM_SetDutyCycle(Pacemaker_DW.obj_n0.MW_PWM_HANDLE, (real_T)
                      Pacemaker_P.Constant13_Value);

  /* MATLABSystem: '<S3>/FRONTEND_CTRL1' incorporates:
   *  Constant: '<S3>/Constant2'
   */
  MW_digitalIO_write(Pacemaker_DW.obj_pu.MW_DIGITALIO_HANDLE,
                     Pacemaker_P.Constant2_Value != 0.0);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.001s, 0.0s] */
    rtExtModeUpload(0, (real_T)Pacemaker_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.001s, 0.0s] */
    if ((rtmGetTFinal(Pacemaker_M)!=-1) &&
        !((rtmGetTFinal(Pacemaker_M)-Pacemaker_M->Timing.taskTime0) >
          Pacemaker_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Pacemaker_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Pacemaker_M)) {
      rtmSetErrorStatus(Pacemaker_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Pacemaker_M->Timing.taskTime0 =
    ((time_T)(++Pacemaker_M->Timing.clockTick0)) * Pacemaker_M->Timing.stepSize0;
}

/* Model initialize function */
void Pacemaker_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(Pacemaker_M, 4.0);
  Pacemaker_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  Pacemaker_M->Sizes.checksums[0] = (2523432935U);
  Pacemaker_M->Sizes.checksums[1] = (161058225U);
  Pacemaker_M->Sizes.checksums[2] = (1548817963U);
  Pacemaker_M->Sizes.checksums[3] = (1647936038U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[18];
    Pacemaker_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Pacemaker_M->extModeInfo,
      &Pacemaker_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Pacemaker_M->extModeInfo, Pacemaker_M->Sizes.checksums);
    rteiSetTPtr(Pacemaker_M->extModeInfo, rtmGetTPtr(Pacemaker_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Pacemaker_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    freedomk64f_DigitalRead_Pacem_T *obj;
    freedomk64f_DigitalWrite_Pace_T *obj_0;
    freedomk64f_PWMOutput_Pacemak_T *obj_1;

    /* Start for Constant: '<Root>/Constant10' */
    Pacemaker_B.Constant10 = Pacemaker_P.Constant10_Value;

    /* Start for Constant: '<Root>/Constant11' */
    Pacemaker_B.Constant11 = Pacemaker_P.Constant11_Value;

    /* Start for Constant: '<Root>/Constant1' */
    Pacemaker_B.Constant1 = Pacemaker_P.Constant1_Value;

    /* Start for Constant: '<Root>/Constant9' */
    Pacemaker_B.Constant9 = Pacemaker_P.Constant9_Value;

    /* Start for Constant: '<Root>/Constant' */
    Pacemaker_B.Constant = Pacemaker_P.Constant_Value;

    /* Start for Constant: '<Root>/Constant2' */
    Pacemaker_B.Constant2 = Pacemaker_P.Constant2_Value_h;

    /* Start for Constant: '<Root>/Constant3' */
    Pacemaker_B.Constant3 = Pacemaker_P.Constant3_Value;

    /* Start for Constant: '<Root>/Constant4' */
    Pacemaker_B.Constant4 = Pacemaker_P.Constant4_Value;

    /* Start for Constant: '<Root>/Constant5' */
    Pacemaker_B.Constant5 = Pacemaker_P.Constant5_Value;

    /* Start for Constant: '<Root>/Constant6' */
    Pacemaker_B.Constant6 = Pacemaker_P.Constant6_Value;

    /* Start for Constant: '<Root>/Constant7' */
    Pacemaker_B.Constant7 = Pacemaker_P.Constant7_Value;

    /* Start for Constant: '<Root>/Constant8' */
    Pacemaker_B.Constant8 = Pacemaker_P.Constant8_Value;

    /* SystemInitialize for Chart: '<Root>/Chart' */
    Pacemaker_DW.sfEvent = Pacemaker_CALL_EVENT;

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
    Pacemaker_DW.obj_n.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_n.isInitialized = 0;
    Pacemaker_DW.obj_n.SampleTime = -1.0;
    Pacemaker_DW.obj_n.matlabCodegenIsDeleted = false;
    Pacemaker_DW.obj_n.SampleTime = Pacemaker_P.VENT_CMP_DETECT_SampleTime;
    obj = &Pacemaker_DW.obj_n;
    Pacemaker_DW.obj_n.isSetupComplete = false;
    Pacemaker_DW.obj_n.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    Pacemaker_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Z_ATR_CTRLOUT' */
    Pacemaker_DW.obj_p.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_p.isInitialized = 0;
    Pacemaker_DW.obj_p.matlabCodegenIsDeleted = false;
    obj_0 = &Pacemaker_DW.obj_p;
    Pacemaker_DW.obj_p.isSetupComplete = false;
    Pacemaker_DW.obj_p.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    Pacemaker_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PACING_REF_PWMOUT' */
    Pacemaker_DW.obj_e.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_e.isInitialized = 0;
    Pacemaker_DW.obj_e.matlabCodegenIsDeleted = false;
    obj_1 = &Pacemaker_DW.obj_e;
    Pacemaker_DW.obj_e.isSetupComplete = false;
    Pacemaker_DW.obj_e.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(Pacemaker_DW.obj_e.MW_PWM_HANDLE);
    Pacemaker_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Z_VENT_CTRLOUT' */
    Pacemaker_DW.obj_o.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_o.isInitialized = 0;
    Pacemaker_DW.obj_o.matlabCodegenIsDeleted = false;
    obj_0 = &Pacemaker_DW.obj_o;
    Pacemaker_DW.obj_o.isSetupComplete = false;
    Pacemaker_DW.obj_o.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    Pacemaker_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/ATR_PACE_CTRLOUT' */
    Pacemaker_DW.obj_nt.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_nt.isInitialized = 0;
    Pacemaker_DW.obj_nt.matlabCodegenIsDeleted = false;
    obj_0 = &Pacemaker_DW.obj_nt;
    Pacemaker_DW.obj_nt.isSetupComplete = false;
    Pacemaker_DW.obj_nt.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    Pacemaker_DW.obj_nt.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/VENT_PACE_CTRLOUT' */
    Pacemaker_DW.obj_b.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_b.isInitialized = 0;
    Pacemaker_DW.obj_b.matlabCodegenIsDeleted = false;
    obj_0 = &Pacemaker_DW.obj_b;
    Pacemaker_DW.obj_b.isSetupComplete = false;
    Pacemaker_DW.obj_b.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    Pacemaker_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PACE_GND_CTRLOUT' */
    Pacemaker_DW.obj_j.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_j.isInitialized = 0;
    Pacemaker_DW.obj_j.matlabCodegenIsDeleted = false;
    obj_0 = &Pacemaker_DW.obj_j;
    Pacemaker_DW.obj_j.isSetupComplete = false;
    Pacemaker_DW.obj_j.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    Pacemaker_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/ATR_GND_CTRLOUT' */
    Pacemaker_DW.obj_ju.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_ju.isInitialized = 0;
    Pacemaker_DW.obj_ju.matlabCodegenIsDeleted = false;
    obj_0 = &Pacemaker_DW.obj_ju;
    Pacemaker_DW.obj_ju.isSetupComplete = false;
    Pacemaker_DW.obj_ju.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    Pacemaker_DW.obj_ju.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/VENT_GND_CTRLOUT' */
    Pacemaker_DW.obj_jq.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_jq.isInitialized = 0;
    Pacemaker_DW.obj_jq.matlabCodegenIsDeleted = false;
    obj_0 = &Pacemaker_DW.obj_jq;
    Pacemaker_DW.obj_jq.isSetupComplete = false;
    Pacemaker_DW.obj_jq.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    Pacemaker_DW.obj_jq.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PACE_CHARGE_CTRLOUT' */
    Pacemaker_DW.obj_a.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_a.isInitialized = 0;
    Pacemaker_DW.obj_a.matlabCodegenIsDeleted = false;
    obj_0 = &Pacemaker_DW.obj_a;
    Pacemaker_DW.obj_a.isSetupComplete = false;
    Pacemaker_DW.obj_a.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    Pacemaker_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/R_LEDOUT' */
    Pacemaker_DW.obj_pp.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_pp.isInitialized = 0;
    Pacemaker_DW.obj_pp.matlabCodegenIsDeleted = false;
    obj_0 = &Pacemaker_DW.obj_pp;
    Pacemaker_DW.obj_pp.isSetupComplete = false;
    Pacemaker_DW.obj_pp.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(42U, 1);
    Pacemaker_DW.obj_pp.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/B_LEDOUT' */
    Pacemaker_DW.obj_py.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_py.isInitialized = 0;
    Pacemaker_DW.obj_py.matlabCodegenIsDeleted = false;
    obj_0 = &Pacemaker_DW.obj_py;
    Pacemaker_DW.obj_py.isSetupComplete = false;
    Pacemaker_DW.obj_py.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(44U, 1);
    Pacemaker_DW.obj_py.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/ATR_CMP_REF_PWM' */
    Pacemaker_DW.obj_l.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_l.isInitialized = 0;
    Pacemaker_DW.obj_l.matlabCodegenIsDeleted = false;
    obj_1 = &Pacemaker_DW.obj_l;
    Pacemaker_DW.obj_l.isSetupComplete = false;
    Pacemaker_DW.obj_l.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(Pacemaker_DW.obj_l.MW_PWM_HANDLE);
    Pacemaker_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/VENT_CMP_REF_PWM' */
    Pacemaker_DW.obj_n0.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_n0.isInitialized = 0;
    Pacemaker_DW.obj_n0.matlabCodegenIsDeleted = false;
    obj_1 = &Pacemaker_DW.obj_n0;
    Pacemaker_DW.obj_n0.isSetupComplete = false;
    Pacemaker_DW.obj_n0.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
    MW_PWM_Start(Pacemaker_DW.obj_n0.MW_PWM_HANDLE);
    Pacemaker_DW.obj_n0.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/FRONTEND_CTRL1' */
    Pacemaker_DW.obj_pu.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_pu.isInitialized = 0;
    Pacemaker_DW.obj_pu.matlabCodegenIsDeleted = false;
    obj_0 = &Pacemaker_DW.obj_pu;
    Pacemaker_DW.obj_pu.isSetupComplete = false;
    Pacemaker_DW.obj_pu.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    Pacemaker_DW.obj_pu.isSetupComplete = true;
  }
}

/* Model terminate function */
void Pacemaker_terminate(void)
{
  /* Terminate for MATLABSystem: '<S2>/ATR_CMP_DETECT' */
  matlabCodegenHandle_matlabCodeg(&Pacemaker_DW.obj);

  /* Terminate for MATLABSystem: '<S2>/VENT_CMP_DETECT' */
  matlabCodegenHandle_matlabCodeg(&Pacemaker_DW.obj_n);

  /* Terminate for MATLABSystem: '<S3>/Z_ATR_CTRLOUT' */
  matlabCodegenHandle_matlabCo_j0(&Pacemaker_DW.obj_p);

  /* Terminate for MATLABSystem: '<S3>/PACING_REF_PWMOUT' */
  matlabCodegenHandle_matlabC_j04(&Pacemaker_DW.obj_e);

  /* Terminate for MATLABSystem: '<S3>/Z_VENT_CTRLOUT' */
  matlabCodegenHandle_matlabCo_j0(&Pacemaker_DW.obj_o);

  /* Terminate for MATLABSystem: '<S3>/ATR_PACE_CTRLOUT' */
  matlabCodegenHandle_matlabCo_j0(&Pacemaker_DW.obj_nt);

  /* Terminate for MATLABSystem: '<S3>/VENT_PACE_CTRLOUT' */
  matlabCodegenHandle_matlabCo_j0(&Pacemaker_DW.obj_b);

  /* Terminate for MATLABSystem: '<S3>/PACE_GND_CTRLOUT' */
  matlabCodegenHandle_matlabCo_j0(&Pacemaker_DW.obj_j);

  /* Terminate for MATLABSystem: '<S3>/ATR_GND_CTRLOUT' */
  matlabCodegenHandle_matlabCo_j0(&Pacemaker_DW.obj_ju);

  /* Terminate for MATLABSystem: '<S3>/VENT_GND_CTRLOUT' */
  matlabCodegenHandle_matlabCo_j0(&Pacemaker_DW.obj_jq);

  /* Terminate for MATLABSystem: '<S3>/PACE_CHARGE_CTRLOUT' */
  matlabCodegenHandle_matlabCo_j0(&Pacemaker_DW.obj_a);

  /* Terminate for MATLABSystem: '<S3>/R_LEDOUT' */
  matlabCodegenHandle_matlabCo_j0(&Pacemaker_DW.obj_pp);

  /* Terminate for MATLABSystem: '<S3>/B_LEDOUT' */
  matlabCodegenHandle_matlabCo_j0(&Pacemaker_DW.obj_py);

  /* Terminate for MATLABSystem: '<S3>/ATR_CMP_REF_PWM' */
  matlabCodegenHandle_matlabC_j04(&Pacemaker_DW.obj_l);

  /* Terminate for MATLABSystem: '<S3>/VENT_CMP_REF_PWM' */
  matlabCodegenHandle_matlabC_j04(&Pacemaker_DW.obj_n0);

  /* Terminate for MATLABSystem: '<S3>/FRONTEND_CTRL1' */
  matlabCodegenHandle_matlabCo_j0(&Pacemaker_DW.obj_pu);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
