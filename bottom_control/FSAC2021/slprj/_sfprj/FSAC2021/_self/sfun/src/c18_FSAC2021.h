#ifndef __c18_FSAC2021_h__
#define __c18_FSAC2021_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc18_FSAC2021InstanceStruct
#define typedef_SFc18_FSAC2021InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c18_sfEvent;
  uint8_T c18_tp_On;
  uint8_T c18_tp_Off;
  uint8_T c18_tp_Wait;
  boolean_T c18_isStable;
  uint8_T c18_is_active_c18_FSAC2021;
  uint8_T c18_is_c18_FSAC2021;
  uint8_T c18_temporalCounter_i1;
  uint32_T c18_presentTicks;
  uint32_T c18_elapsedTicks;
  uint32_T c18_previousTicks;
  uint8_T c18_doSetSimStateSideEffects;
  const mxArray *c18_setSimStateSideEffectsInfo;
} SFc18_FSAC2021InstanceStruct;

#endif                                 /*typedef_SFc18_FSAC2021InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c18_FSAC2021_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c18_FSAC2021_get_check_sum(mxArray *plhs[]);
extern void c18_FSAC2021_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
