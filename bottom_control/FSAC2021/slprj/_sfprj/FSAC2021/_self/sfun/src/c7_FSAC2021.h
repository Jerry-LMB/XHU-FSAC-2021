#ifndef __c7_FSAC2021_h__
#define __c7_FSAC2021_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc7_FSAC2021InstanceStruct
#define typedef_SFc7_FSAC2021InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c7_sfEvent;
  uint8_T c7_tp_Start_Horn_ON;
  uint8_T c7_tp_Start_Horn_OFF;
  boolean_T c7_isStable;
  uint8_T c7_is_active_c7_FSAC2021;
  uint8_T c7_is_c7_FSAC2021;
  uint8_T c7_OFF;
  uint8_T c7_ON;
  uint8_T c7_temporalCounter_i1;
  uint32_T c7_presentTicks;
  uint32_T c7_elapsedTicks;
  uint32_T c7_previousTicks;
  uint8_T c7_doSetSimStateSideEffects;
  const mxArray *c7_setSimStateSideEffectsInfo;
} SFc7_FSAC2021InstanceStruct;

#endif                                 /*typedef_SFc7_FSAC2021InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c7_FSAC2021_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c7_FSAC2021_get_check_sum(mxArray *plhs[]);
extern void c7_FSAC2021_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
