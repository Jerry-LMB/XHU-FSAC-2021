#ifndef __c2_FSAC2021_V1_h__
#define __c2_FSAC2021_V1_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc2_FSAC2021_V1InstanceStruct
#define typedef_SFc2_FSAC2021_V1InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  uint8_T c2_tp_Visuality_On;
  uint8_T c2_tp_Visuality_Off;
  boolean_T c2_isStable;
  uint8_T c2_is_active_c2_FSAC2021_V1;
  uint8_T c2_is_c2_FSAC2021_V1;
  uint8_T c2_temporalCounter_i1;
  uint32_T c2_presentTicks;
  uint32_T c2_elapsedTicks;
  uint32_T c2_previousTicks;
  uint8_T c2_doSetSimStateSideEffects;
  const mxArray *c2_setSimStateSideEffectsInfo;
} SFc2_FSAC2021_V1InstanceStruct;

#endif                                 /*typedef_SFc2_FSAC2021_V1InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_FSAC2021_V1_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_FSAC2021_V1_get_check_sum(mxArray *plhs[]);
extern void c2_FSAC2021_V1_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
