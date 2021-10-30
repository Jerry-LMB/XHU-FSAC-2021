#ifndef __c9_FSAC2021_V1_Running_h__
#define __c9_FSAC2021_V1_Running_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc9_FSAC2021_V1_RunningInstanceStruct
#define typedef_SFc9_FSAC2021_V1_RunningInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c9_sfEvent;
  uint8_T c9_tp_init;
  uint8_T c9_tp_IN;
  uint8_T c9_tp_Second;
  uint8_T c9_tp_Move;
  uint8_T c9_tp_end;
  boolean_T c9_isStable;
  uint8_T c9_is_active_c9_FSAC2021_V1_Running;
  uint8_T c9_is_c9_FSAC2021_V1_Running;
  uint8_T c9_is_IN;
  uint16_T c9_temporalCounter_i1;
  uint32_T c9_presentTicks;
  uint32_T c9_elapsedTicks;
  uint32_T c9_previousTicks;
  uint8_T c9_doSetSimStateSideEffects;
  const mxArray *c9_setSimStateSideEffectsInfo;
} SFc9_FSAC2021_V1_RunningInstanceStruct;

#endif                                 /*typedef_SFc9_FSAC2021_V1_RunningInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c9_FSAC2021_V1_Running_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c9_FSAC2021_V1_Running_get_check_sum(mxArray *plhs[]);
extern void c9_FSAC2021_V1_Running_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
