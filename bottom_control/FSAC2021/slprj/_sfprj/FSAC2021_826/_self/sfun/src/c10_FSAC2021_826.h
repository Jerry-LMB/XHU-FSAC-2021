#ifndef __c10_FSAC2021_826_h__
#define __c10_FSAC2021_826_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc10_FSAC2021_826InstanceStruct
#define typedef_SFc10_FSAC2021_826InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c10_sfEvent;
  uint8_T c10_tp_Normal;
  uint8_T c10_tp_Off;
  uint8_T c10_tp_ON;
  uint8_T c10_tp_On;
  boolean_T c10_isStable;
  uint8_T c10_is_active_c10_FSAC2021_826;
  uint8_T c10_is_c10_FSAC2021_826;
  uint8_T c10_temporalCounter_i1;
  uint32_T c10_presentTicks;
  uint32_T c10_elapsedTicks;
  uint32_T c10_previousTicks;
  uint8_T c10_doSetSimStateSideEffects;
  const mxArray *c10_setSimStateSideEffectsInfo;
} SFc10_FSAC2021_826InstanceStruct;

#endif                                 /*typedef_SFc10_FSAC2021_826InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c10_FSAC2021_826_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c10_FSAC2021_826_get_check_sum(mxArray *plhs[]);
extern void c10_FSAC2021_826_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
