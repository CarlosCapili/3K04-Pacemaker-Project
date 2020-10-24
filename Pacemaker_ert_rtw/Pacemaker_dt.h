/*
 * Pacemaker_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Pacemaker".
 *
 * Model version              : 1.51
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Sat Oct 24 18:08:40 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(Activity),
  sizeof(Adaptive),
  sizeof(ChamberPaced),
  sizeof(ChamberSensed),
  sizeof(freedomk64f_DigitalRead_Pacem_T),
  sizeof(freedomk64f_PWMOutput_Pacemak_T),
  sizeof(freedomk64f_DigitalWrite_Pace_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "Activity",
  "Adaptive",
  "ChamberPaced",
  "ChamberSensed",
  "freedomk64f_DigitalRead_Pacem_T",
  "freedomk64f_PWMOutput_Pacemak_T",
  "freedomk64f_DigitalWrite_Pace_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Pacemaker_B.Constant10), 7, 0, 11 },

  { (char_T *)(&Pacemaker_B.Constant9), 17, 0, 1 },

  { (char_T *)(&Pacemaker_B.Constant11), 16, 0, 1 },

  { (char_T *)(&Pacemaker_B.Constant1), 15, 0, 1 },

  { (char_T *)(&Pacemaker_B.Constant), 14, 0, 1 },

  { (char_T *)(&Pacemaker_B.DataTypeConversion), 8, 0, 12 }
  ,

  { (char_T *)(&Pacemaker_DW.obj), 18, 0, 2 },

  { (char_T *)(&Pacemaker_DW.obj_e), 19, 0, 3 },

  { (char_T *)(&Pacemaker_DW.obj_p), 20, 0, 11 },

  { (char_T *)(&Pacemaker_DW.ActiveChamber), 0, 0, 2 },

  { (char_T *)(&Pacemaker_DW.Scope_PWORK.LoggedData), 11, 0, 1 },

  { (char_T *)(&Pacemaker_DW.sfEvent), 6, 0, 1 },

  { (char_T *)(&Pacemaker_DW.is_c2_Pacemaker), 7, 0, 6 },

  { (char_T *)(&Pacemaker_DW.is_active_c2_Pacemaker), 3, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  14U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Pacemaker_P.VENT_CMP_DETECT_SampleTime), 0, 0, 5 },

  { (char_T *)(&Pacemaker_P.Constant_Value), 14, 0, 1 },

  { (char_T *)(&Pacemaker_P.Constant1_Value), 15, 0, 1 },

  { (char_T *)(&Pacemaker_P.Constant11_Value), 16, 0, 1 },

  { (char_T *)(&Pacemaker_P.Constant9_Value), 17, 0, 1 },

  { (char_T *)(&Pacemaker_P.Constant10_Value), 7, 0, 10 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  6U,
  rtPTransitions
};

/* [EOF] Pacemaker_dt.h */
