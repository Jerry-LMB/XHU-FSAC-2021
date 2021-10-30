#ifndef __c23_FSAC2021_V1_h__
#define __c23_FSAC2021_V1_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc23_FSAC2021_V1InstanceStruct
#define typedef_SFc23_FSAC2021_V1InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c23_sfEvent;
  uint8_T c23_tp_Action;
  uint8_T c23_tp_Init;
  uint8_T c23_tp_Action1;
  boolean_T c23_isStable;
  uint8_T c23_is_active_c23_FSAC2021_V1;
  uint8_T c23_is_c23_FSAC2021_V1;
  uint8_T c23_temporalCounter_i1;
  uint32_T c23_presentTicks;
  uint32_T c23_elapsedTicks;
  uint32_T c23_previousTicks;
  uint8_T c23_doSetSimStateSideEffects;
  const mxArray *c23_setSimStateSideEffectsInfo;
} SFc23_FSAC2021_V1InstanceStruct;

#endif                                 /*typedef_SFc23_FSAC2021_V1InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c23_FSAC2021_V1_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c23_FSAC2021_V1_get_check_sum(mxArray *plhs[]);
extern void c23_FSAC2021_V1_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
