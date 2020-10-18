#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "Pacemaker_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#ifndef SS_INT64
#define SS_INT64  19
#endif
#ifndef SS_UINT64
#define SS_UINT64  20
#endif
#else
#include "builtin_typeid_types.h"
#include "Pacemaker.h"
#include "Pacemaker_capi.h"
#include "Pacemaker_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 1 , TARGET_STRING (
"Pacemaker/Chart" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 1 , 0 ,
TARGET_STRING ( "Pacemaker/Chart/is_active_c2_Pacemaker" ) , TARGET_STRING (
"is_active_c2_Pacemaker" ) , 0 , 1 , 0 , 0 , 0 } , { 2 , 0 , TARGET_STRING (
"Pacemaker/Chart/is_c2_Pacemaker" ) , TARGET_STRING ( "is_c2_Pacemaker" ) , 0
, 2 , 0 , 0 , 0 } , { 3 , 0 , TARGET_STRING (
"Pacemaker/Chart/Sense.is_Sense" ) , TARGET_STRING ( "is_Sense" ) , 0 , 2 , 0
, 0 , 0 } , { 4 , 0 , TARGET_STRING (
"Pacemaker/Chart/Sense.Inhibit.is_Inhibit" ) , TARGET_STRING ( "is_Inhibit" )
, 0 , 2 , 0 , 0 , 0 } , { 5 , 0 , TARGET_STRING (
"Pacemaker/Chart/Pace.is_Pace" ) , TARGET_STRING ( "is_Pace" ) , 0 , 2 , 0 ,
0 , 0 } , { 6 , 0 , TARGET_STRING ( "Pacemaker/Constant" ) , TARGET_STRING (
"" ) , 0 , 3 , 0 , 0 , 1 } , { 7 , 0 , TARGET_STRING ( "Pacemaker/Constant1"
) , TARGET_STRING ( "" ) , 0 , 4 , 0 , 0 , 1 } , { 8 , 0 , TARGET_STRING (
"Pacemaker/Constant2" ) , TARGET_STRING ( "" ) , 0 , 5 , 0 , 0 , 1 } , { 9 ,
0 , TARGET_STRING ( "Pacemaker/Constant3" ) , TARGET_STRING ( "" ) , 0 , 2 ,
0 , 0 , 1 } , { 10 , 0 , TARGET_STRING ( "Pacemaker/Constant4" ) ,
TARGET_STRING ( "" ) , 0 , 2 , 0 , 0 , 1 } , { 11 , 0 , TARGET_STRING (
"Pacemaker/Constant5" ) , TARGET_STRING ( "" ) , 0 , 2 , 0 , 0 , 1 } , { 12 ,
0 , TARGET_STRING ( "Pacemaker/Constant6" ) , TARGET_STRING ( "" ) , 0 , 2 ,
0 , 0 , 1 } , { 13 , 0 , TARGET_STRING ( "Pacemaker/Constant7" ) ,
TARGET_STRING ( "" ) , 0 , 2 , 0 , 0 , 1 } , { 14 , 0 , TARGET_STRING (
"Pacemaker/Subsystem1/Gain" ) , TARGET_STRING ( "" ) , 0 , 6 , 0 , 1 , 1 } ,
{ 15 , 0 , TARGET_STRING ( "Pacemaker/Subsystem1/Gain1" ) , TARGET_STRING (
"" ) , 0 , 6 , 0 , 1 , 1 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 ,
0 } } ; static const rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 16 ,
TARGET_STRING ( "Pacemaker/Constant" ) , TARGET_STRING ( "Value" ) , 3 , 0 ,
0 } , { 17 , TARGET_STRING ( "Pacemaker/Constant1" ) , TARGET_STRING (
"Value" ) , 4 , 0 , 0 } , { 18 , TARGET_STRING ( "Pacemaker/Constant2" ) ,
TARGET_STRING ( "Value" ) , 5 , 0 , 0 } , { 19 , TARGET_STRING (
"Pacemaker/Constant3" ) , TARGET_STRING ( "Value" ) , 2 , 0 , 0 } , { 20 ,
TARGET_STRING ( "Pacemaker/Constant4" ) , TARGET_STRING ( "Value" ) , 2 , 0 ,
0 } , { 21 , TARGET_STRING ( "Pacemaker/Constant5" ) , TARGET_STRING (
"Value" ) , 2 , 0 , 0 } , { 22 , TARGET_STRING ( "Pacemaker/Constant6" ) ,
TARGET_STRING ( "Value" ) , 2 , 0 , 0 } , { 23 , TARGET_STRING (
"Pacemaker/Constant7" ) , TARGET_STRING ( "Value" ) , 2 , 0 , 0 } , { 24 ,
TARGET_STRING ( "Pacemaker/Subsystem1/Gain" ) , TARGET_STRING ( "Gain" ) , 2
, 0 , 2 } , { 25 , TARGET_STRING ( "Pacemaker/Subsystem1/Gain1" ) ,
TARGET_STRING ( "Gain" ) , 2 , 0 , 2 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 ,
0 } } ; static const rtwCAPI_ModelParameters rtModelParameters [ ] = { { 0 ,
( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . fe5eov4z2i , & rtDW . chlmxpvaee
, & rtDW . gbjg1dvsj1 , & rtDW . f1t32ta12k , & rtDW . cdkqznoziq , & rtDW .
ogo32fugqm , & rtB . opb340v0ul , & rtB . h3ny4b2egu , & rtB . bfzr1arjyc , &
rtB . o0nlqgyufw , & rtB . e0j1qe0ix5 , & rtB . aa1ioimd1n , & rtB .
biqqudbwrg , & rtB . jureihrddk , & rtB . o0hmegtn4n , & rtB . gtopblewy3 , &
rtP . Constant_Value , & rtP . Constant1_Value , & rtP . Constant2_Value , &
rtP . Constant3_Value , & rtP . Constant4_Value , & rtP . Constant5_Value , &
rtP . Constant6_Value , & rtP . Constant7_Value , & rtP . Gain_Gain , & rtP .
Gain1_Gain , } ; static int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { {
"unsigned char" , "boolean_T" , 0 , 0 , sizeof ( boolean_T ) , SS_BOOLEAN , 0
, 0 , 0 } , { "unsigned char" , "uint8_T" , 0 , 0 , sizeof ( uint8_T ) ,
SS_UINT8 , 0 , 0 , 0 } , { "unsigned int" , "uint32_T" , 0 , 0 , sizeof (
uint32_T ) , SS_UINT32 , 0 , 0 , 0 } , { "numeric" , "ChamberPaced" , 0 , 0 ,
sizeof ( ChamberPaced ) , SS_ENUM_TYPE , 0 , 0 , SS_INT32 } , { "numeric" ,
"ChamberSensed" , 0 , 0 , sizeof ( ChamberSensed ) , SS_ENUM_TYPE , 0 , 0 ,
SS_INT32 } , { "numeric" , "Activity" , 0 , 0 , sizeof ( Activity ) ,
SS_ENUM_TYPE , 0 , 0 , SS_INT32 } , { "numeric" , "uint64_T" , 0 , 0 , sizeof
( uint64_T ) , SS_UINT64 , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } } ; static const uint_T rtDimensionArray [ ] = {
1 , 1 } ; static const real_T rtcapiStoredFloats [ ] = { 0.001 , 0.0 , 1.0 }
; static const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , { ( const void * ) & rtcapiStoredFloats
[ 2 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] ,
rtwCAPI_FIX_UNIFORM_SCALING , 64 , - 16 , 0 } , { ( const void * ) &
rtcapiStoredFloats [ 2 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] ,
rtwCAPI_FIX_UNIFORM_SCALING , 32 , - 16 , 0 } } ; static const
rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , 0 ,
0 } , { ( NULL ) , ( NULL ) , 1 , 0 } } ; static
rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 16 , ( NULL )
, 0 , ( NULL ) , 0 } , { rtBlockParameters , 10 , rtModelParameters , 0 } , {
( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap
, rtSampleTimeMap , rtDimensionArray } , "float" , { 1642484882U , 565623278U
, 2783770519U , 3169405728U } , ( NULL ) , 0 , 0 } ; const
rtwCAPI_ModelMappingStaticInfo * Pacemaker_GetCAPIStaticMap ( void ) { return
& mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void Pacemaker_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void Pacemaker_host_InitializeDataMapInfo ( Pacemaker_host_DataMapInfo_T *
dataMap , const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
