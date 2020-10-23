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
 * C/C++ source code generated on : Thu Oct 22 20:26:34 2020
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
#define Pacemaker_IN_Discharging       (2U)
#define Pacemaker_IN_INIT              (1U)
#define Pacemaker_IN_Inhibit           (1U)
#define Pacemaker_IN_None              (2U)
#define Pacemaker_IN_Pace              (2U)
#define Pacemaker_IN_Sense             (3U)
#define Pacemaker_IN_Ventricular       (3U)
#define Pacemaker_IN_test              (4U)
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
static void Pacemaker_SystemCore_release_j(const freedomk64f_DigitalRead_Pacem_T
  *obj);
static void Pacemaker_SystemCore_delete_j(const freedomk64f_DigitalRead_Pacem_T *
  obj);
static void matlabCodegenHandle_matlabCod_j(freedomk64f_DigitalRead_Pacem_T *obj);
static void Pacema_SystemCore_release_j04js(const
  freedomk64f_DigitalWrite_Pace_T *obj);
static void Pacemak_SystemCore_delete_j04js(const
  freedomk64f_DigitalWrite_Pace_T *obj);
static void matlabCodegenHandle_matla_j04js(freedomk64f_DigitalWrite_Pace_T *obj);
static void Pacemake_SystemCore_release_j04(const
  freedomk64f_PWMOutput_Pacemak_T *obj);
static void Pacemaker_SystemCore_delete_j04(const
  freedomk64f_PWMOutput_Pacemak_T *obj);
static void matlabCodegenHandle_matlabC_j04(freedomk64f_PWMOutput_Pacemak_T *obj);
static void Pacemaker_SystemCore_release(const freedomk64f_PushButton_Pacema_T
  *obj);
static void Pacemaker_SystemCore_delete(const freedomk64f_PushButton_Pacema_T
  *obj);
static void matlabCodegenHandle_matlabCodeg(freedomk64f_PushButton_Pacema_T *obj);
void uMultiWordMul(const uint32_T u1[], int32_T n1, const uint32_T u2[], int32_T
                   n2, uint32_T y[], int32_T n)
{
  int32_T i;
  int32_T j;
  int32_T k;
  int32_T ni;
  uint32_T u1i;
  uint32_T yk;
  uint32_T a1;
  uint32_T a0;
  uint32_T b1;
  uint32_T w10;
  uint32_T w01;
  uint32_T cb;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0U;
  }

  for (i = 0; i < n1; i++) {
    cb = 0U;
    u1i = u1[i];
    a1 = u1i >> 16U;
    a0 = u1i & 65535U;
    ni = n - i;
    ni = n2 <= ni ? n2 : ni;
    k = i;
    for (j = 0; j < ni; j++) {
      u1i = u2[j];
      b1 = u1i >> 16U;
      u1i &= 65535U;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk = y[k] + cb;
      cb = (uint32_T)(yk < cb);
      u1i *= a0;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w10 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w01 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      y[k] = yk;
      cb += w10 >> 16U;
      cb += w01 >> 16U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
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
  /* Chart: '<Root>/Chart' */
  if (Pacemaker_DW.is_active_c2_Pacemaker == 0U) {
    Pacemaker_DW.is_active_c2_Pacemaker = 1U;
    Pacemaker_DW.is_c2_Pacemaker = Pacemaker_IN_INIT;
    Pacemaker_B.senseSwitch = true;
  } else {
    switch (Pacemaker_DW.is_c2_Pacemaker) {
     case Pacemaker_IN_INIT:
      Pacemaker_DW.is_c2_Pacemaker = Pacemaker_IN_Sense;
      if (Pacemaker_B.Constant2 == INHIBITED_A) {
        Pacemaker_DW.is_Sense = Pacemaker_IN_Inhibit;
        Pacemaker_DW.is_Inhibit = Pacemaker_IN_Default;
        Pacemaker_B.B_LED = false;
      } else {
        Pacemaker_DW.is_Sense = Pacemaker_IN_None;
      }
      break;

     case Pacemaker_IN_Pace:
      if (Pacemaker_DW.sfEvent == Pacemaker_event_paceEnd) {
        Pacemaker_DW.is_Pace = 0U;
        Pacemaker_DW.is_c2_Pacemaker = Pacemaker_IN_Sense;
        if (Pacemaker_B.Constant2 == INHIBITED_A) {
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
        Pacemaker_DW.is_Inhibit = 0U;
        Pacemaker_DW.is_Sense = 0U;
        Pacemaker_DW.is_c2_Pacemaker = Pacemaker_IN_Pace;
        Pacemaker_DW.is_Pace = Pacemaker_IN_Discharging;
        Pacemaker_DW.temporalCounter_i1 = 0U;
        Pacema_enter_atomic_Discharging();
      } else {
        if (Pacemaker_DW.is_Sense == Pacemaker_IN_Inhibit) {
          switch (Pacemaker_DW.is_Inhibit) {
           case Pacemaker_IN_Atrium:
            if (Pacemaker_B.DataTypeConversion) {
              Pacemaker_DW.is_Inhibit = Pacemaker_IN_test;
              Pacemaker_DW.temporalCounter_i1 = 0U;
              Pacemaker_B.B_LED = true;
              Pacemaker_B.R_LED = true;
            } else {
              Pacemaker_B.B_LED = false;
            }
            break;

           case Pacemaker_IN_Default:
            switch (Pacemaker_B.Constant1) {
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
            } else {
              Pacemaker_B.B_LED = true;
              Pacemaker_B.R_LED = true;
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

static void Pacemaker_SystemCore_release_j(const freedomk64f_DigitalRead_Pacem_T
  *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void Pacemaker_SystemCore_delete_j(const freedomk64f_DigitalRead_Pacem_T *
  obj)
{
  Pacemaker_SystemCore_release_j(obj);
}

static void matlabCodegenHandle_matlabCod_j(freedomk64f_DigitalRead_Pacem_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Pacemaker_SystemCore_delete_j(obj);
  }
}

static void Pacema_SystemCore_release_j04js(const
  freedomk64f_DigitalWrite_Pace_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void Pacemak_SystemCore_delete_j04js(const
  freedomk64f_DigitalWrite_Pace_T *obj)
{
  Pacema_SystemCore_release_j04js(obj);
}

static void matlabCodegenHandle_matla_j04js(freedomk64f_DigitalWrite_Pace_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Pacemak_SystemCore_delete_j04js(obj);
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

static void Pacemaker_SystemCore_release(const freedomk64f_PushButton_Pacema_T
  *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void Pacemaker_SystemCore_delete(const freedomk64f_PushButton_Pacema_T
  *obj)
{
  Pacemaker_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(freedomk64f_PushButton_Pacema_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Pacemaker_SystemCore_delete(obj);
  }
}

/* Model step function */
void Pacemaker_step(void)
{
  real_T rtb_Switch1;
  uint32_T tmp;

  /* MATLABSystem: '<S2>/Digital Read' */
  if (Pacemaker_DW.obj.SampleTime != Pacemaker_P.DigitalRead_SampleTime) {
    Pacemaker_DW.obj.SampleTime = Pacemaker_P.DigitalRead_SampleTime;
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  MATLABSystem: '<S2>/Digital Read'
   */
  Pacemaker_B.DataTypeConversion = MW_digitalIO_read
    (Pacemaker_DW.obj.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<S2>/Digital Read1' */
  if (Pacemaker_DW.obj_n.SampleTime != Pacemaker_P.DigitalRead1_SampleTime) {
    Pacemaker_DW.obj_n.SampleTime = Pacemaker_P.DigitalRead1_SampleTime;
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion1' incorporates:
   *  MATLABSystem: '<S2>/Digital Read1'
   */
  Pacemaker_B.DataTypeConversion1 = MW_digitalIO_read
    (Pacemaker_DW.obj_n.MW_DIGITALIO_HANDLE);

  /* Constant: '<Root>/Constant' */
  Pacemaker_B.Constant = Pacemaker_P.Constant_Value_m;

  /* Constant: '<Root>/Constant1' */
  Pacemaker_B.Constant1 = Pacemaker_P.Constant1_Value_f;

  /* Constant: '<Root>/Constant2' */
  Pacemaker_B.Constant2 = Pacemaker_P.Constant2_Value;

  /* Constant: '<Root>/Constant3' */
  Pacemaker_B.Constant3 = Pacemaker_P.Constant3_Value;

  /* Constant: '<Root>/Constant4' */
  Pacemaker_B.Constant4 = Pacemaker_P.Constant4_Value;

  /* Constant: '<Root>/Constant5' */
  Pacemaker_B.Constant5 = Pacemaker_P.Constant5_Value;

  /* Gain: '<S4>/Gain' incorporates:
   *  Math: '<S4>/Math Function'
   *
   * About '<S4>/Math Function':
   *  Operator: reciprocal
   */
  tmp = Pacemaker_B.Constant5 == 0U ? MAX_uint32_T : 1U / Pacemaker_B.Constant5;
  uMultiWordMul(&Pacemaker_P.Gain_Gain, 1, &tmp, 1, &Pacemaker_B.Gain.chunks[0U],
                2);

  /* Constant: '<Root>/Constant6' */
  Pacemaker_B.Constant6 = Pacemaker_P.Constant6_Value;

  /* Gain: '<S4>/Gain1' incorporates:
   *  Math: '<S4>/Math Function1'
   *
   * About '<S4>/Math Function1':
   *  Operator: reciprocal
   */
  tmp = Pacemaker_B.Constant6 == 0U ? MAX_uint32_T : 1U / Pacemaker_B.Constant6;
  uMultiWordMul(&Pacemaker_P.Gain1_Gain, 1, &tmp, 1, &Pacemaker_B.Gain1.chunks
                [0U], 2);

  /* Constant: '<Root>/Constant7' */
  Pacemaker_B.Constant7 = Pacemaker_P.Constant7_Value;

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

  /* MATLABSystem: '<S3>/FRONTEND_CTRL' */
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

  /* MATLABSystem: '<S3>/PWM Output' */
  MW_PWM_SetDutyCycle(Pacemaker_DW.obj_l.MW_PWM_HANDLE, rtb_Switch1);

  /* MATLABSystem: '<S3>/PWM Output2' */
  MW_PWM_SetDutyCycle(Pacemaker_DW.obj_n0.MW_PWM_HANDLE, rtb_Switch1);

  /* MATLABSystem: '<S2>/Push Button' */
  if (Pacemaker_DW.obj_c.SampleTime != Pacemaker_P.PushButton_SampleTime) {
    Pacemaker_DW.obj_c.SampleTime = Pacemaker_P.PushButton_SampleTime;
  }

  MW_digitalIO_read(Pacemaker_DW.obj_c.MW_DIGITALIO_HANDLE);

  /* End of MATLABSystem: '<S2>/Push Button' */

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
  rtmSetTFinal(Pacemaker_M, 4.0);
  Pacemaker_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  Pacemaker_M->Sizes.checksums[0] = (770752021U);
  Pacemaker_M->Sizes.checksums[1] = (3365778784U);
  Pacemaker_M->Sizes.checksums[2] = (1398685200U);
  Pacemaker_M->Sizes.checksums[3] = (22624107U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[12];
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
    dtInfo.numDataTypes = 37;
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
    freedomk64f_PushButton_Pacema_T *obj_2;

    /* Start for Constant: '<Root>/Constant' */
    Pacemaker_B.Constant = Pacemaker_P.Constant_Value_m;

    /* Start for Constant: '<Root>/Constant1' */
    Pacemaker_B.Constant1 = Pacemaker_P.Constant1_Value_f;

    /* Start for Constant: '<Root>/Constant2' */
    Pacemaker_B.Constant2 = Pacemaker_P.Constant2_Value;

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

    /* Start for MATLABSystem: '<S3>/FRONTEND_CTRL' */
    Pacemaker_DW.obj_nc.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_nc.isInitialized = 0;
    Pacemaker_DW.obj_nc.matlabCodegenIsDeleted = false;
    obj_0 = &Pacemaker_DW.obj_nc;
    Pacemaker_DW.obj_nc.isSetupComplete = false;
    Pacemaker_DW.obj_nc.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    Pacemaker_DW.obj_nc.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PWM Output' */
    Pacemaker_DW.obj_l.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_l.isInitialized = 0;
    Pacemaker_DW.obj_l.matlabCodegenIsDeleted = false;
    obj_1 = &Pacemaker_DW.obj_l;
    Pacemaker_DW.obj_l.isSetupComplete = false;
    Pacemaker_DW.obj_l.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
    MW_PWM_Start(Pacemaker_DW.obj_l.MW_PWM_HANDLE);
    Pacemaker_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PWM Output2' */
    Pacemaker_DW.obj_n0.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_n0.isInitialized = 0;
    Pacemaker_DW.obj_n0.matlabCodegenIsDeleted = false;
    obj_1 = &Pacemaker_DW.obj_n0;
    Pacemaker_DW.obj_n0.isSetupComplete = false;
    Pacemaker_DW.obj_n0.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(Pacemaker_DW.obj_n0.MW_PWM_HANDLE);
    Pacemaker_DW.obj_n0.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Push Button' */
    Pacemaker_DW.obj_c.matlabCodegenIsDeleted = true;
    Pacemaker_DW.obj_c.isInitialized = 0;
    Pacemaker_DW.obj_c.SampleTime = -1.0;
    Pacemaker_DW.obj_c.matlabCodegenIsDeleted = false;
    Pacemaker_DW.obj_c.SampleTime = Pacemaker_P.PushButton_SampleTime;
    obj_2 = &Pacemaker_DW.obj_c;
    Pacemaker_DW.obj_c.isSetupComplete = false;
    Pacemaker_DW.obj_c.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(45U, 0);
    Pacemaker_DW.obj_c.isSetupComplete = true;
  }
}

/* Model terminate function */
void Pacemaker_terminate(void)
{
  /* Terminate for MATLABSystem: '<S2>/Digital Read' */
  matlabCodegenHandle_matlabCod_j(&Pacemaker_DW.obj);

  /* Terminate for MATLABSystem: '<S2>/Digital Read1' */
  matlabCodegenHandle_matlabCod_j(&Pacemaker_DW.obj_n);

  /* Terminate for MATLABSystem: '<S3>/Digital Write' */
  matlabCodegenHandle_matla_j04js(&Pacemaker_DW.obj_o);

  /* Terminate for MATLABSystem: '<S3>/Digital Write4' */
  matlabCodegenHandle_matla_j04js(&Pacemaker_DW.obj_p);

  /* Terminate for MATLABSystem: '<S3>/FRONTEND_CTRL' */
  matlabCodegenHandle_matla_j04js(&Pacemaker_DW.obj_nc);

  /* Terminate for MATLABSystem: '<S3>/PWM Output' */
  matlabCodegenHandle_matlabC_j04(&Pacemaker_DW.obj_l);

  /* Terminate for MATLABSystem: '<S3>/PWM Output2' */
  matlabCodegenHandle_matlabC_j04(&Pacemaker_DW.obj_n0);

  /* Terminate for MATLABSystem: '<S2>/Push Button' */
  matlabCodegenHandle_matlabCodeg(&Pacemaker_DW.obj_c);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
