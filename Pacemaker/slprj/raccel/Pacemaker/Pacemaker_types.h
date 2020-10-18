#ifndef RTW_HEADER_Pacemaker_types_h_
#define RTW_HEADER_Pacemaker_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#ifndef DEFINED_TYPEDEF_FOR_ChamberPaced_
#define DEFINED_TYPEDEF_FOR_ChamberPaced_
typedef enum { ChamberPaced_ATRIUM = 0 , ChamberPaced_VENTRICLE ,
ChamberPaced_DUAL , ChamberPaced_NONE } ChamberPaced ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_ChamberSensed_
#define DEFINED_TYPEDEF_FOR_ChamberSensed_
typedef enum { ChamberSensed_ATRIUM = 0 , ChamberSensed_VENTRICLE ,
ChamberSensed_DUAL , ChamberSensed_NONE } ChamberSensed ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_Activity_
#define DEFINED_TYPEDEF_FOR_Activity_
typedef enum { Activity_TRIGGERED = 0 , Activity_INHIBITED , Activity_DUAL ,
Activity_NONE } Activity ;
#endif
#ifndef SS_INT64
#define SS_INT64  19
#endif
#ifndef SS_UINT64
#define SS_UINT64  20
#endif
typedef struct P_ P ;
#endif
