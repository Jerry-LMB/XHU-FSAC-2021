#ifndef __c4_FSAC2021_826_h__
#define __c4_FSAC2021_826_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc4_FSAC2021_826InstanceStruct
#define typedef_SFc4_FSAC2021_826InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  uint8_T c4_tp_Normal;
  uint8_T c4_tp_Off;
  uint8_T c4_tp_ON;
  uint8_T c4_tp_On;
  boolean_T c4_isStable;
  uint8_T c4_is_active_c4_FSAC2021_826;
  uint8_T c4_is_c4_FSAC2021_826;
  uint8_T c4_temporalCounter_i1;
  uint32_T c4_presentTicks;
  uint32_T c4_elapsedTicks;
  uint32_T c4_previousTicks;
  uint8_T c4_doSetSimStateSideEffects;
  const mxArray *c4_setSimStateSideEffectsInfo;
} SFc4_FSAC2021_826InstanceStruct;

#endif                                 /*typedef_SFc4_FSAC2021_826InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c4_FSAC2021_826_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_FSAC2021_826_get_check_sum(mxArray *plhs[]);
extern void c4_FSAC2021_826_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
