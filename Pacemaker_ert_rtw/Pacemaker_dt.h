/*
 * Pacemaker_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Pacemaker".
 *
 * Model version              : 1.14
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Thu Oct 22 20:26:34 2020
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
  sizeof(ChamberPaced),
  sizeof(ChamberSensed),
  sizeof(Activity),
  sizeof(uint32_T),
  sizeof(uint64m_T),
  sizeof(freedomk64f_DigitalRead_Pacem_T),
  sizeof(freedomk64f_PushButton_Pacema_T),
  sizeof(freedomk64f_DigitalWrite_Pace_T),
  sizeof(freedomk64f_PWMOutput_Pacemak_T),
  sizeof(int64m_T),
  sizeof(uint64m_T),
  sizeof(int96m_T),
  sizeof(uint96m_T),
  sizeof(int128m_T),
  sizeof(uint128m_T),
  sizeof(int160m_T),
  sizeof(uint160m_T),
  sizeof(int192m_T),
  sizeof(uint192m_T),
  sizeof(int224m_T),
  sizeof(uint224m_T),
  sizeof(int256m_T),
  sizeof(uint256m_T)
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
  "ChamberPaced",
  "ChamberSensed",
  "Activity",
  "uint32_T",
  "uint64m_T",
  "freedomk64f_DigitalRead_Pacem_T",
  "freedomk64f_PushButton_Pacema_T",
  "freedomk64f_DigitalWrite_Pace_T",
  "freedomk64f_PWMOutput_Pacemak_T",
  "int64m_T",
  "uint64m_T",
  "int96m_T",
  "uint96m_T",
  "int128m_T",
  "uint128m_T",
  "int160m_T",
  "uint160m_T",
  "int192m_T",
  "uint192m_T",
  "int224m_T",
  "uint224m_T",
  "int256m_T",
  "uint256m_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Pacemaker_B.Gain), 18, 0, 2 },

  { (char_T *)(&Pacemaker_B.Constant3), 7, 0, 5 },

  { (char_T *)(&Pacemaker_B.Constant1), 15, 0, 1 },

  { (char_T *)(&Pacemaker_B.Constant), 14, 0, 1 },

  { (char_T *)(&Pacemaker_B.Constant2), 16, 0, 1 },

  { (char_T *)(&Pacemaker_B.DataTypeConversion), 8, 0, 5 }
  ,

  { (char_T *)(&Pacemaker_DW.obj), 19, 0, 2 },

  { (char_T *)(&Pacemaker_DW.obj_c), 20, 0, 1 },

  { (char_T *)(&Pacemaker_DW.obj_o), 21, 0, 3 },

  { (char_T *)(&Pacemaker_DW.obj_l), 22, 0, 2 },

  { (char_T *)(&Pacemaker_DW.Scope_PWORK.LoggedData), 11, 0, 2 },

  { (char_T *)(&Pacemaker_DW.sfEvent), 6, 0, 1 },

  { (char_T *)(&Pacemaker_DW.is_c2_Pacemaker), 7, 0, 4 },

  { (char_T *)(&Pacemaker_DW.is_active_c2_Pacemaker), 3, 0, 2 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  14U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Pacemaker_P.PushButton_SampleTime), 0, 0, 5 },

  { (char_T *)(&Pacemaker_P.Constant2_Value), 16, 0, 1 },

  { (char_T *)(&Pacemaker_P.Constant_Value_m), 14, 0, 1 },

  { (char_T *)(&Pacemaker_P.Constant1_Value_f), 15, 0, 1 },

  { (char_T *)(&Pacemaker_P.Gain_Gain), 17, 0, 7 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  5U,
  rtPTransitions
};

/* [EOF] Pacemaker_dt.h */
