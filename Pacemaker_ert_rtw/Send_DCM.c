/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Send_DCM.c
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

#include "Send_DCM.h"

/* Include model header file for global data */
#include "Pacemaker.h"
#include "Pacemaker_private.h"

/* Forward declaration for local functions */
static void Pacemaker_SystemCore_setup(freedomk64f_SCIWrite_Pacemake_T *obj);
static void Pacemaker_SystemCore_release(const freedomk64f_SCIWrite_Pacemake_T
  *obj);
static void Pacemaker_SystemCore_delete(const freedomk64f_SCIWrite_Pacemake_T
  *obj);
static void matlabCodegenHandle_matlabCodeg(freedomk64f_SCIWrite_Pacemake_T *obj);
static void Pacemaker_SystemCore_setup(freedomk64f_SCIWrite_Pacemake_T *obj)
{
  uint32_T RxPinLoc;
  uint32_T SCIModuleLoc;
  MW_SCI_StopBits_Type StopBitsValue;
  MW_SCI_Parity_Type ParityValue;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  RxPinLoc = MW_UNDEFINED_VALUE;
  SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&SCIModuleLoc, false, RxPinLoc, 10U);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue, StopBitsValue);
  obj->isSetupComplete = true;
}

static void Pacemaker_SystemCore_release(const freedomk64f_SCIWrite_Pacemake_T
  *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_SCI_Close(obj->MW_SCIHANDLE);
  }
}

static void Pacemaker_SystemCore_delete(const freedomk64f_SCIWrite_Pacemake_T
  *obj)
{
  Pacemaker_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(freedomk64f_SCIWrite_Pacemake_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Pacemaker_SystemCore_delete(obj);
  }
}

/* System initialize for Simulink Function: '<Root>/Serial transmit' */
void Send_DCM_Init(void)
{
  /* Start for MATLABSystem: '<S7>/Serial Transmit' */
  Pacemaker_DW.obj_g.isInitialized = 0;
  Pacemaker_DW.obj_g.matlabCodegenIsDeleted = false;
  Pacemaker_SystemCore_setup(&Pacemaker_DW.obj_g);
}

/* Output and update for Simulink Function: '<Root>/Serial transmit' */
void Send_DCM(void)
{
  uint8_T status;
  int32_T i;

  /* SignalConversion generated from: '<S7>/AtrialAmp' */
  Pacemaker_B.AtrialAmp = Pacemaker_B.AtrialAmp_j;

  /* SignalConversion generated from: '<S7>/AtrialPulseWidth' */
  Pacemaker_B.AtrialPulseWidth = Pacemaker_B.AtrialPulseWidth_e;

  /* SignalConversion generated from: '<S7>/AtrialSensitivity' */
  Pacemaker_B.AtrialSensitivity = Pacemaker_B.AtrialSensitivity_e;

  /* SignalConversion generated from: '<S7>/VentricularAmp' */
  Pacemaker_B.VentricularAmp = Pacemaker_B.VentricularAmp_b;

  /* SignalConversion generated from: '<S7>/VentricularPulseWidth' */
  Pacemaker_B.VentricularPulseWidth = Pacemaker_B.VentricularPulseWidth_m;

  /* SignalConversion generated from: '<S7>/VentricularSensitivity' */
  Pacemaker_B.VentricularSensitivity = Pacemaker_B.VentricularSensitivity_i;

  /* SignalConversion generated from: '<S7>/VRP' */
  Pacemaker_B.VRP = Pacemaker_B.VRP_j;

  /* SignalConversion generated from: '<S7>/ARP' */
  Pacemaker_B.ARP = Pacemaker_B.ARP_b;

  /* SignalConversion generated from: '<S7>/PVARP' */
  Pacemaker_B.PVARP = Pacemaker_B.PVARP_c;

  /* SignalConversion generated from: '<S7>/FixAVDelay' */
  Pacemaker_B.FixAVDelay = Pacemaker_B.FixAVDelay_e;

  /* SignalConversion generated from: '<S7>/AtrSignalArr' */
  memcpy(&Pacemaker_B.TmpLatchAtAtrSignalArrOutport1[0],
         &Pacemaker_B.TappedDelay[0], 25U * sizeof(real32_T));

  /* SignalConversion generated from: '<S7>/VentSignalArr' */
  memcpy(&Pacemaker_B.TmpLatchAtVentSignalArrOutport1[0],
         &Pacemaker_B.TappedDelay1[0], 25U * sizeof(real32_T));

  /* S-Function (any2byte): '<S7>/Byte Pack1' */

  /* Pack: <S7>/Byte Pack1 */
  (void) memcpy(&Pacemaker_B.BytePack1[0], &Pacemaker_B.AtrialAmp,
                4);

  /* S-Function (any2byte): '<S7>/Byte Pack2' */

  /* Pack: <S7>/Byte Pack2 */
  (void) memcpy(&Pacemaker_B.BytePack2[0], &Pacemaker_B.AtrialPulseWidth,
                4);

  /* S-Function (any2byte): '<S7>/Byte Pack3' */

  /* Pack: <S7>/Byte Pack3 */
  (void) memcpy(&Pacemaker_B.BytePack3[0], &Pacemaker_B.AtrialSensitivity,
                4);

  /* S-Function (any2byte): '<S7>/Byte Pack4' */

  /* Pack: <S7>/Byte Pack4 */
  (void) memcpy(&Pacemaker_B.BytePack4[0], &Pacemaker_B.VentricularAmp,
                4);

  /* S-Function (any2byte): '<S7>/Byte Pack8' */

  /* Pack: <S7>/Byte Pack8 */
  (void) memcpy(&Pacemaker_B.BytePack8[0], &Pacemaker_B.VentricularPulseWidth,
                4);

  /* S-Function (any2byte): '<S7>/Byte Pack9' */

  /* Pack: <S7>/Byte Pack9 */
  (void) memcpy(&Pacemaker_B.BytePack9[0], &Pacemaker_B.VentricularSensitivity,
                4);

  /* S-Function (any2byte): '<S7>/Byte Pack' */

  /* Pack: <S7>/Byte Pack */
  (void) memcpy(&Pacemaker_B.BytePack[0], &Pacemaker_B.VRP,
                2);

  /* S-Function (any2byte): '<S7>/Byte Pack5' */

  /* Pack: <S7>/Byte Pack5 */
  (void) memcpy(&Pacemaker_B.BytePack5[0], &Pacemaker_B.ARP,
                2);

  /* S-Function (any2byte): '<S7>/Byte Pack6' */

  /* Pack: <S7>/Byte Pack6 */
  (void) memcpy(&Pacemaker_B.BytePack6[0], &Pacemaker_B.PVARP,
                2);

  /* S-Function (any2byte): '<S7>/Byte Pack7' */

  /* Pack: <S7>/Byte Pack7 */
  (void) memcpy(&Pacemaker_B.BytePack7[0], &Pacemaker_B.FixAVDelay,
                2);

  /* S-Function (any2byte): '<S7>/Byte Pack10' */

  /* Pack: <S7>/Byte Pack10 */
  (void) memcpy(&Pacemaker_B.BytePack10[0],
                &Pacemaker_B.TmpLatchAtAtrSignalArrOutport1[0],
                100);

  /* S-Function (any2byte): '<S7>/Byte Pack11' */

  /* Pack: <S7>/Byte Pack11 */
  (void) memcpy(&Pacemaker_B.BytePack11[0],
                &Pacemaker_B.TmpLatchAtVentSignalArrOutport1[0],
                100);

  /* Switch: '<S7>/Switch' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/Constant1'
   *  Constant: '<S7>/Constant2'
   *  SignalConversion generated from: '<S7>/ActivityThreshold'
   *  SignalConversion generated from: '<S7>/LRL'
   *  SignalConversion generated from: '<S7>/MaxSensorRate'
   *  SignalConversion generated from: '<S7>/Mode'
   *  SignalConversion generated from: '<S7>/ReactionTime'
   *  SignalConversion generated from: '<S7>/RecoveryTime'
   *  SignalConversion generated from: '<S7>/ResponseFactor'
   *  SignalConversion generated from: '<S7>/Type'
   *  SignalConversion generated from: '<S7>/URL'
   */
  if (Pacemaker_B.Type > Pacemaker_P.Switch_Threshold) {
    Pacemaker_B.Switch[0] = Pacemaker_P.Constant_Value;
    Pacemaker_B.Switch[1] = Pacemaker_B.Mode;
    Pacemaker_B.Switch[2] = Pacemaker_B.LRL;
    Pacemaker_B.Switch[3] = Pacemaker_B.URL;
    Pacemaker_B.Switch[4] = Pacemaker_B.BytePack1[0];
    Pacemaker_B.Switch[8] = Pacemaker_B.BytePack2[0];
    Pacemaker_B.Switch[12] = Pacemaker_B.BytePack3[0];
    Pacemaker_B.Switch[16] = Pacemaker_B.BytePack4[0];
    Pacemaker_B.Switch[20] = Pacemaker_B.BytePack8[0];
    Pacemaker_B.Switch[24] = Pacemaker_B.BytePack9[0];
    Pacemaker_B.Switch[5] = Pacemaker_B.BytePack1[1];
    Pacemaker_B.Switch[9] = Pacemaker_B.BytePack2[1];
    Pacemaker_B.Switch[13] = Pacemaker_B.BytePack3[1];
    Pacemaker_B.Switch[17] = Pacemaker_B.BytePack4[1];
    Pacemaker_B.Switch[21] = Pacemaker_B.BytePack8[1];
    Pacemaker_B.Switch[25] = Pacemaker_B.BytePack9[1];
    Pacemaker_B.Switch[6] = Pacemaker_B.BytePack1[2];
    Pacemaker_B.Switch[10] = Pacemaker_B.BytePack2[2];
    Pacemaker_B.Switch[14] = Pacemaker_B.BytePack3[2];
    Pacemaker_B.Switch[18] = Pacemaker_B.BytePack4[2];
    Pacemaker_B.Switch[22] = Pacemaker_B.BytePack8[2];
    Pacemaker_B.Switch[26] = Pacemaker_B.BytePack9[2];
    Pacemaker_B.Switch[7] = Pacemaker_B.BytePack1[3];
    Pacemaker_B.Switch[11] = Pacemaker_B.BytePack2[3];
    Pacemaker_B.Switch[15] = Pacemaker_B.BytePack3[3];
    Pacemaker_B.Switch[19] = Pacemaker_B.BytePack4[3];
    Pacemaker_B.Switch[23] = Pacemaker_B.BytePack8[3];
    Pacemaker_B.Switch[27] = Pacemaker_B.BytePack9[3];
    Pacemaker_B.Switch[28] = Pacemaker_B.BytePack[0];
    Pacemaker_B.Switch[30] = Pacemaker_B.BytePack5[0];
    Pacemaker_B.Switch[32] = Pacemaker_B.BytePack6[0];
    Pacemaker_B.Switch[34] = Pacemaker_B.BytePack7[0];
    Pacemaker_B.Switch[29] = Pacemaker_B.BytePack[1];
    Pacemaker_B.Switch[31] = Pacemaker_B.BytePack5[1];
    Pacemaker_B.Switch[33] = Pacemaker_B.BytePack6[1];
    Pacemaker_B.Switch[35] = Pacemaker_B.BytePack7[1];
    Pacemaker_B.Switch[36] = Pacemaker_B.MaxSensorRate;
    Pacemaker_B.Switch[37] = Pacemaker_B.ReactionTime;
    Pacemaker_B.Switch[38] = Pacemaker_B.ResponseFactor;
    Pacemaker_B.Switch[39] = Pacemaker_B.RecoveryTime;
    Pacemaker_B.Switch[40] = Pacemaker_B.ActivityThreshold;
  } else {
    Pacemaker_B.Switch[0] = Pacemaker_P.Constant1_Value;
    Pacemaker_B.Switch[1] = Pacemaker_B.BytePack10[0];
    Pacemaker_B.Switch[2] = Pacemaker_B.BytePack10[1];
    Pacemaker_B.Switch[3] = Pacemaker_B.BytePack10[2];
    Pacemaker_B.Switch[4] = Pacemaker_B.BytePack10[3];
    Pacemaker_B.Switch[8] = Pacemaker_B.BytePack10[7];
    Pacemaker_B.Switch[12] = Pacemaker_B.BytePack10[11];
    Pacemaker_B.Switch[16] = Pacemaker_B.BytePack10[15];
    Pacemaker_B.Switch[20] = Pacemaker_B.BytePack10[19];
    Pacemaker_B.Switch[24] = Pacemaker_B.BytePack10[23];
    Pacemaker_B.Switch[5] = Pacemaker_B.BytePack10[4];
    Pacemaker_B.Switch[9] = Pacemaker_B.BytePack10[8];
    Pacemaker_B.Switch[13] = Pacemaker_B.BytePack10[12];
    Pacemaker_B.Switch[17] = Pacemaker_B.BytePack10[16];
    Pacemaker_B.Switch[21] = Pacemaker_B.BytePack10[20];
    Pacemaker_B.Switch[25] = Pacemaker_B.BytePack10[24];
    Pacemaker_B.Switch[6] = Pacemaker_B.BytePack10[5];
    Pacemaker_B.Switch[10] = Pacemaker_B.BytePack10[9];
    Pacemaker_B.Switch[14] = Pacemaker_B.BytePack10[13];
    Pacemaker_B.Switch[18] = Pacemaker_B.BytePack10[17];
    Pacemaker_B.Switch[22] = Pacemaker_B.BytePack10[21];
    Pacemaker_B.Switch[26] = Pacemaker_B.BytePack10[25];
    Pacemaker_B.Switch[7] = Pacemaker_B.BytePack10[6];
    Pacemaker_B.Switch[11] = Pacemaker_B.BytePack10[10];
    Pacemaker_B.Switch[15] = Pacemaker_B.BytePack10[14];
    Pacemaker_B.Switch[19] = Pacemaker_B.BytePack10[18];
    Pacemaker_B.Switch[23] = Pacemaker_B.BytePack10[22];
    Pacemaker_B.Switch[27] = Pacemaker_B.BytePack10[26];
    Pacemaker_B.Switch[28] = Pacemaker_B.BytePack10[27];
    Pacemaker_B.Switch[30] = Pacemaker_B.BytePack10[29];
    Pacemaker_B.Switch[32] = Pacemaker_B.BytePack10[31];
    Pacemaker_B.Switch[34] = Pacemaker_B.BytePack10[33];
    Pacemaker_B.Switch[29] = Pacemaker_B.BytePack10[28];
    Pacemaker_B.Switch[31] = Pacemaker_B.BytePack10[30];
    Pacemaker_B.Switch[33] = Pacemaker_B.BytePack10[32];
    Pacemaker_B.Switch[35] = Pacemaker_B.BytePack10[34];
    Pacemaker_B.Switch[36] = Pacemaker_B.BytePack10[35];
    Pacemaker_B.Switch[37] = Pacemaker_B.BytePack10[36];
    Pacemaker_B.Switch[38] = Pacemaker_B.BytePack10[37];
    Pacemaker_B.Switch[39] = Pacemaker_B.BytePack10[38];
    Pacemaker_B.Switch[40] = Pacemaker_B.BytePack10[39];
  }

  for (i = 0; i < 60; i++) {
    if (Pacemaker_B.Type > Pacemaker_P.Switch_Threshold) {
      Pacemaker_B.Switch[i + 41] = Pacemaker_P.Constant2_Value_j[i];
    } else {
      Pacemaker_B.Switch[i + 41] = Pacemaker_B.BytePack10[i + 40];
    }
  }

  if (Pacemaker_B.Type > Pacemaker_P.Switch_Threshold) {
    memcpy(&Pacemaker_B.Switch[101], &Pacemaker_P.Constant2_Value_j[60], 100U *
           sizeof(uint8_T));
  } else {
    memcpy(&Pacemaker_B.Switch[101], &Pacemaker_B.BytePack11[0], 100U * sizeof
           (uint8_T));
  }

  /* End of Switch: '<S7>/Switch' */

  /* MATLABSystem: '<S7>/Serial Transmit' */
  status = 1U;
  while (status != 0) {
    memcpy((void *)&Pacemaker_B.TxDataLocChar[0], (void *)&Pacemaker_B.Switch[0],
           (uint32_T)((size_t)201 * sizeof(uint8_T)));
    status = MW_SCI_Transmit(Pacemaker_DW.obj_g.MW_SCIHANDLE,
      Pacemaker_B.TxDataLocChar, 201U);
  }

  /* End of MATLABSystem: '<S7>/Serial Transmit' */
}

/* Termination for Simulink Function: '<Root>/Serial transmit' */
void Send_DCM_Term(void)
{
  /* Terminate for MATLABSystem: '<S7>/Serial Transmit' */
  matlabCodegenHandle_matlabCodeg(&Pacemaker_DW.obj_g);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
