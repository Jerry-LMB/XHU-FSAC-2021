#ifndef __c3_FSAC2021_V1_Running_h__
#define __c3_FSAC2021_V1_Running_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_FSAC2021_V1_RunningInstanceStruct
#define typedef_SFc3_FSAC2021_V1_RunningInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  uint8_T c3_tp_AS_Driving;
  uint8_T c3_tp_AS_Off;
  uint8_T c3_tp_AS_Ready;
  uint8_T c3_tp_Manual_Driving;
  uint8_T c3_tp_AS_Emergency;
  uint8_T c3_tp_AS_Finished;
  boolean_T c3_isStable;
  uint8_T c3_is_active_c3_FSAC2021_V1_Running;
  uint8_T c3_is_c3_FSAC2021_V1_Running;
  uint8_T c3_ON;
  uint8_T c3_OFF;
  uint8_T c3_ENABLE;
  uint8_T c3_DISABLE;
  uint8_T c3_AS_OFF;
  uint8_T c3_AS_READY;
  uint8_T c3_AS_DRIVING;
  uint8_T c3_AS_FINISH;
  uint8_T c3_AS_EMERGENCY;
  uint8_T c3_BLINK;
  uint8_T c3_EBS_DISABLE;
  uint8_T c3_EBS_ARMED;
  uint8_T c3_EBS_ENABLE;
  uint8_T c3_MANUAL_DRIVING;
  uint8_T c3_MANUAL_MODE;
  uint8_T c3_BUZZER_START;
  uint8_T c3_BUZZER_EBS;
  uint8_T c3_TRACKDRIVE;
  uint8_T c3_temporalCounter_i1;
  uint32_T c3_presentTicks;
  uint32_T c3_elapsedTicks;
  uint32_T c3_previousTicks;
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
} SFc3_FSAC2021_V1_RunningInstanceStruct;

#endif                                 /*typedef_SFc3_FSAC2021_V1_RunningInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_FSAC2021_V1_Running_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c3_FSAC2021_V1_Running_get_check_sum(mxArray *plhs[]);
extern void c3_FSAC2021_V1_Running_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
