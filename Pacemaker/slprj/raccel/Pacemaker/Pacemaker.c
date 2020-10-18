#include "rt_logging_mmi.h"
#include "Pacemaker_capi.h"
#include <math.h>
#include "Pacemaker.h"
#include "Pacemaker_private.h"
#include "Pacemaker_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; extern boolean_T
gblExtModeStartPktReceived ; void raccelForceExtModeShutdown ( ) { if ( !
gblExtModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 1 , & stopRequested ) ; }
rtExtModeShutdown ( 1 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 2 ; const char_T
* gbl_raccel_Version = "9.3 (R2020a) 18-Nov-2019" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const char * gblSlvrJacPatternFileName =
"slprj\\raccel\\Pacemaker\\Pacemaker_Jpattern.mat" ; const int_T
gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern void * gblAperiodicPartitionHitTimes ; const int_T
gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [ ] = { - 1 }
; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ; int_T enableFcnCallFlag [ ] = { 1 , 1 } ; const char *
raccelLoadInputsAndAperiodicHitTimes ( const char * inportFileName , int *
matFileFormat ) { return rt_RapidReadInportsMatFile ( inportFileName ,
matFileFormat , 1 ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#define bttpbq3yq4 (2U)
#define c21dalb4as (3U)
#define cxmf4p3ivl (1)
#define e0yzqe1fjf (3)
#define f4oxwgwiiy (3U)
#define g3ka44lo5t (2U)
#define kelv2e3pyq (1U)
#define m5x0ghjbfo (0)
#define ma4o1zj1pg (3U)
#define mapscepnn4 (1U)
#define mjg5wcnrkp (1U)
#define plaxfbznyr (-1)
#define pmknwvyfat (2)
#define po4fb34ev1 (1U)
#define po4fb34ev1v (2U)
#define pri0tpyeuj (2U)
B rtB ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS = &
model_S ; static void didjzccete ( void ) ; static void ginjtwhs4e ( void ) ;
static void o3nhjss0wh ( void ) ; static void dhp4hv3zns ( void ) ; static
void ebxtcmtgmo ( void ) ; static void didjzccete ( void ) { int32_T
b_previousEvent ; b_previousEvent = rtDW . c5bkqgcrxz ; rtDW . c5bkqgcrxz =
cxmf4p3ivl ; ebxtcmtgmo ( ) ; rtDW . c5bkqgcrxz = b_previousEvent ; } static
void ginjtwhs4e ( void ) { int32_T b_previousEvent ; b_previousEvent = rtDW .
c5bkqgcrxz ; rtDW . c5bkqgcrxz = pmknwvyfat ; ebxtcmtgmo ( ) ; rtDW .
c5bkqgcrxz = b_previousEvent ; } static void o3nhjss0wh ( void ) { rtB .
fe5eov4z2i = true ; if ( rtDW . noyy3zzbdv >= 200U ) { didjzccete ( ) ; } }
static void dhp4hv3zns ( void ) { int32_T b_previousEvent ; b_previousEvent =
rtDW . c5bkqgcrxz ; rtDW . c5bkqgcrxz = e0yzqe1fjf ; ebxtcmtgmo ( ) ; rtDW .
c5bkqgcrxz = b_previousEvent ; } static void ebxtcmtgmo ( void ) { if ( rtDW
. chlmxpvaee == 0U ) { rtDW . chlmxpvaee = 1U ; rtDW . gbjg1dvsj1 =
mapscepnn4 ; } else { switch ( rtDW . gbjg1dvsj1 ) { case mapscepnn4 : rtDW .
gbjg1dvsj1 = f4oxwgwiiy ; rtDW . f1t32ta12k = po4fb34ev1 ; break ; case
bttpbq3yq4 : if ( rtDW . c5bkqgcrxz == pmknwvyfat ) { rtDW . ogo32fugqm = 0U
; rtDW . gbjg1dvsj1 = f4oxwgwiiy ; rtDW . f1t32ta12k = po4fb34ev1 ; } else {
switch ( rtDW . ogo32fugqm ) { case kelv2e3pyq : if ( rtDW . c5bkqgcrxz ==
m5x0ghjbfo ) { rtDW . ogo32fugqm = pri0tpyeuj ; rtDW . noyy3zzbdv = 0U ; rtB
. fe5eov4z2i = false ; if ( rtDW . noyy3zzbdv >= 200U ) { ginjtwhs4e ( ) ; }
} else { rtB . fe5eov4z2i = true ; if ( rtDW . noyy3zzbdv >= 200U ) {
didjzccete ( ) ; } } break ; case pri0tpyeuj : if ( rtDW . c5bkqgcrxz ==
cxmf4p3ivl ) { rtDW . ogo32fugqm = kelv2e3pyq ; rtDW . noyy3zzbdv = 0U ;
o3nhjss0wh ( ) ; } else { rtB . fe5eov4z2i = false ; if ( rtDW . noyy3zzbdv
>= 200U ) { ginjtwhs4e ( ) ; } } break ; default : rtDW . ogo32fugqm = 0U ;
break ; } } break ; case f4oxwgwiiy : if ( rtDW . c5bkqgcrxz == e0yzqe1fjf )
{ rtDW . cdkqznoziq = 0U ; rtDW . f1t32ta12k = 0U ; rtDW . gbjg1dvsj1 =
bttpbq3yq4 ; rtDW . ogo32fugqm = kelv2e3pyq ; rtDW . noyy3zzbdv = 0U ;
o3nhjss0wh ( ) ; } else { switch ( rtDW . f1t32ta12k ) { case po4fb34ev1 : if
( rtB . bfzr1arjyc == Activity_NONE ) { rtDW . f1t32ta12k = c21dalb4as ; rtDW
. noyy3zzbdv = 0U ; if ( rtDW . noyy3zzbdv >= 200U ) { dhp4hv3zns ( ) ; } }
else { if ( rtB . bfzr1arjyc == Activity_INHIBITED ) { rtDW . f1t32ta12k =
g3ka44lo5t ; rtDW . cdkqznoziq = po4fb34ev1v ; } } break ; case g3ka44lo5t :
switch ( rtDW . cdkqznoziq ) { case mjg5wcnrkp : case ma4o1zj1pg : break ;
case po4fb34ev1v : if ( rtB . h3ny4b2egu == ChamberSensed_ATRIUM ) { rtDW .
cdkqznoziq = mjg5wcnrkp ; } else { if ( rtB . h3ny4b2egu ==
ChamberSensed_VENTRICLE ) { rtDW . cdkqznoziq = ma4o1zj1pg ; } } break ;
default : rtDW . cdkqznoziq = 0U ; break ; } break ; case c21dalb4as : if (
rtDW . noyy3zzbdv >= 200U ) { dhp4hv3zns ( ) ; } break ; default : rtDW .
f1t32ta12k = 0U ; break ; } } break ; default : rtDW . gbjg1dvsj1 = 0U ;
break ; } } } void MdlInitialize ( void ) { rtDW . c5bkqgcrxz = plaxfbznyr ;
rtDW . ogo32fugqm = 0U ; rtDW . f1t32ta12k = 0U ; rtDW . cdkqznoziq = 0U ;
rtDW . noyy3zzbdv = 0U ; rtDW . chlmxpvaee = 0U ; rtDW . gbjg1dvsj1 = 0U ; }
void MdlStart ( void ) { { void * * slioCatalogueAddr = rt_slioCatalogueAddr
( ) ; void * r2 = ( NULL ) ; void * * pOSigstreamManagerAddr = ( NULL ) ;
const int maxErrorBufferSize = 16384 ; char errMsgCreatingOSigstreamManager [
16384 ] ; bool errorCreatingOSigstreamManager = false ; const char *
errorAddingR2SharedResource = ( NULL ) ; * slioCatalogueAddr =
rtwGetNewSlioCatalogue ( rt_GetMatSigLogSelectorFileName ( ) ) ;
errorAddingR2SharedResource = rtwAddR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) , 1 ) ; if (
errorAddingR2SharedResource != ( NULL ) ) { rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = ( NULL ) ; ssSetErrorStatus ( rtS
, errorAddingR2SharedResource ) ; return ; } r2 = rtwGetR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ) ;
pOSigstreamManagerAddr = rt_GetOSigstreamManagerAddr ( ) ;
errorCreatingOSigstreamManager = rtwOSigstreamManagerCreateInstance (
rt_GetMatSigLogSelectorFileName ( ) , r2 , pOSigstreamManagerAddr ,
errMsgCreatingOSigstreamManager , maxErrorBufferSize ) ; if (
errorCreatingOSigstreamManager ) { * pOSigstreamManagerAddr = ( NULL ) ;
ssSetErrorStatus ( rtS , errMsgCreatingOSigstreamManager ) ; return ; } } {
bool externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( ) ; rtwISigstreamManagerGetInputIsInDatasetFormat (
pISigstreamManager , & externalInputIsInDatasetFormat ) ; if (
externalInputIsInDatasetFormat ) { } } rtB . opb340v0ul = rtP .
Constant_Value ; rtB . h3ny4b2egu = rtP . Constant1_Value ; rtB . bfzr1arjyc
= rtP . Constant2_Value ; rtB . o0nlqgyufw = rtP . Constant3_Value ; rtB .
e0j1qe0ix5 = rtP . Constant4_Value ; rtB . aa1ioimd1n = rtP . Constant5_Value
; rtB . biqqudbwrg = rtP . Constant6_Value ; rtB . jureihrddk = rtP .
Constant7_Value ; MdlInitialize ( ) ; } void MdlOutputs ( int_T tid ) { if (
rtDW . noyy3zzbdv < 255U ) { rtDW . noyy3zzbdv ++ ; } rtDW . c5bkqgcrxz =
plaxfbznyr ; ebxtcmtgmo ( ) ; UNUSED_PARAMETER ( tid ) ; } void
MdlOutputsTID1 ( int_T tid ) { rtB . opb340v0ul = rtP . Constant_Value ; rtB
. h3ny4b2egu = rtP . Constant1_Value ; rtB . bfzr1arjyc = rtP .
Constant2_Value ; rtB . o0nlqgyufw = rtP . Constant3_Value ; rtB . e0j1qe0ix5
= rtP . Constant4_Value ; rtB . aa1ioimd1n = rtP . Constant5_Value ; rtB .
o0hmegtn4n = ( uint64_T ) ( rtB . aa1ioimd1n == 0U ? MAX_uint32_T : 1U / rtB
. aa1ioimd1n ) * rtP . Gain_Gain ; rtB . biqqudbwrg = rtP . Constant6_Value ;
rtB . gtopblewy3 = ( uint64_T ) ( rtB . biqqudbwrg == 0U ? MAX_uint32_T : 1U
/ rtB . biqqudbwrg ) * rtP . Gain1_Gain ; rtB . jureihrddk = rtP .
Constant7_Value ; UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID1 ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlTerminate ( void ) { if (
rt_slioCatalogue ( ) != ( NULL ) ) { void * * slioCatalogueAddr =
rt_slioCatalogueAddr ( ) ; rtwSaveDatasetsToMatFile (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ,
rt_GetMatSigstreamLoggingFileName ( ) ) ; rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = NULL ; } } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 0 ) ; ssSetNumY (
rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ;
ssSetNumSampleTimes ( rtS , 1 ) ; ssSetNumBlocks ( rtS , 15 ) ;
ssSetNumBlockIO ( rtS , 11 ) ; ssSetNumBlockParams ( rtS , 10 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.001 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; } void raccel_set_checksum ( ) {
ssSetChecksumVal ( rtS , 0 , 1642484882U ) ; ssSetChecksumVal ( rtS , 1 ,
565623278U ) ; ssSetChecksumVal ( rtS , 2 , 2783770519U ) ; ssSetChecksumVal
( rtS , 3 , 3169405728U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo
; ( void ) memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void )
memset ( ( char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; { rtB . o0hmegtn4n = ( 0ULL ) ; rtB . gtopblewy3 = ( 0ULL ) ; rtB .
h3ny4b2egu = ChamberSensed_ATRIUM ; rtB . opb340v0ul = ChamberPaced_ATRIUM ;
rtB . bfzr1arjyc = Activity_TRIGGERED ; } } { void * dwork = ( void * ) &
rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork , 0 , sizeof
( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T *
) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS , & dtInfo
) ; dtInfo . numDataTypes = 21 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [
0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . BTransTable
= & rtBTransTable ; dtInfo . PTransTable = & rtPTransTable ; dtInfo .
dataTypeInfoTable = rtDataTypeInfoTable ; } Pacemaker_InitializeDataMapInfo (
) ; ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS )
; ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"Pacemaker" ) ; ssSetPath ( rtS , "Pacemaker" ) ; ssSetTStart ( rtS , 0.0 ) ;
ssSetTFinal ( rtS , 4.0 ) ; ssSetStepSize ( rtS , 0.001 ) ;
ssSetFixedStepSize ( rtS , 0.001 ) ; { static RTWLogInfo rt_DataLoggingInfo ;
rt_DataLoggingInfo . loggingInterval = NULL ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ;
rtliSetLogX ( ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo
( rtS ) , "none" ) ; rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ;
rtliSetLogMaxRows ( ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation (
ssGetRTWLogInfo ( rtS ) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" )
; rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
ssSolverInfo slvrInfo ; ssSetSolverInfo ( rtS , & slvrInfo ) ;
ssSetSolverName ( rtS , "FixedStepDiscrete" ) ; ssSetVariableStepSolver ( rtS
, 0 ) ; ssSetSolverConsistencyChecking ( rtS , 0 ) ;
ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ; ssSetSolverRobustResetMethod (
rtS , 0 ) ; ssSetSolverStateProjection ( rtS , 0 ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetTNextTid ( rtS , INT_MIN ) ;
ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 0 ) ; } ssSetChecksumVal ( rtS , 0 ,
1642484882U ) ; ssSetChecksumVal ( rtS , 1 , 565623278U ) ; ssSetChecksumVal
( rtS , 2 , 2783770519U ) ; ssSetChecksumVal ( rtS , 3 , 3169405728U ) ; {
static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static
RTWExtModeInfo rt_ExtModeInfo ; static const sysRanDType * systemRan [ 2 ] ;
gblRTWExtModeInfo = & rt_ExtModeInfo ; ssSetRTWExtModeInfo ( rtS , &
rt_ExtModeInfo ) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo ,
systemRan ) ; systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = &
rtAlwaysEnabled ; rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) ,
& ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo
( rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS
) , ssGetTPtr ( rtS ) ) ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 1 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID1 ( tid ) ; }
