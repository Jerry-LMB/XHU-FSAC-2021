#ifndef __c8_FSAC2021_V1_h__
#define __c8_FSAC2021_V1_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc8_FSAC2021_V1InstanceStruct
#define typedef_SFc8_FSAC2021_V1InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c8_sfEvent;
  uint8_T c8_tp_Horn;
  uint8_T c8_tp_EBS_Horn_ON;
  uint8_T c8_tp_EBS_Horn_ON1;
  uint8_T c8_tp_EBS_Horn_OFF;
  boolean_T c8_isStable;
  uint8_T c8_is_active_c8_FSAC2021_V1;
  uint8_T c8_is_c8_FSAC2021_V1;
  uint8_T c8_is_Horn;
  uint8_T c8_OFF;
  uint8_T c8_ON;
  uint8_T c8_ENABLE;
  uint8_T c8_temporalCounter_i1;
  uint8_T c8_temporalCounter_i2;
  uint32_T c8_presentTicks;
  uint32_T c8_elapsedTicks;
  uint32_T c8_previousTicks;
  uint8_T c8_doSetSimStateSideEffects;
  const mxArray *c8_setSimStateSideEffectsInfo;
} SFc8_FSAC2021_V1InstanceStruct;

#endif                                 /*typedef_SFc8_FSAC2021_V1InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c8_FSAC2021_V1_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c8_FSAC2021_V1_get_check_sum(mxArray *plhs[]);
extern void c8_FSAC2021_V1_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
