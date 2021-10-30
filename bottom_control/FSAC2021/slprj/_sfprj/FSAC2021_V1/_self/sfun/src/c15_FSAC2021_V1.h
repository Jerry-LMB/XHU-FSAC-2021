#ifndef __c15_FSAC2021_V1_h__
#define __c15_FSAC2021_V1_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc15_FSAC2021_V1InstanceStruct
#define typedef_SFc15_FSAC2021_V1InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c15_sfEvent;
  uint8_T c15_tp_Normal;
  uint8_T c15_tp_Off;
  uint8_T c15_tp_ON;
  uint8_T c15_tp_On;
  boolean_T c15_isStable;
  uint8_T c15_is_active_c15_FSAC2021_V1;
  uint8_T c15_is_c15_FSAC2021_V1;
  uint8_T c15_temporalCounter_i1;
  uint32_T c15_presentTicks;
  uint32_T c15_elapsedTicks;
  uint32_T c15_previousTicks;
  uint8_T c15_doSetSimStateSideEffects;
  const mxArray *c15_setSimStateSideEffectsInfo;
} SFc15_FSAC2021_V1InstanceStruct;

#endif                                 /*typedef_SFc15_FSAC2021_V1InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c15_FSAC2021_V1_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c15_FSAC2021_V1_get_check_sum(mxArray *plhs[]);
extern void c15_FSAC2021_V1_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
