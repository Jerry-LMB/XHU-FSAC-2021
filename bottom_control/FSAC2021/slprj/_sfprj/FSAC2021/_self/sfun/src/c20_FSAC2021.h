#ifndef __c20_FSAC2021_h__
#define __c20_FSAC2021_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc20_FSAC2021InstanceStruct
#define typedef_SFc20_FSAC2021InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c20_sfEvent;
  uint8_T c20_tp_Normal;
  uint8_T c20_tp_Off;
  uint8_T c20_tp_ON;
  uint8_T c20_tp_On;
  boolean_T c20_isStable;
  uint8_T c20_is_active_c20_FSAC2021;
  uint8_T c20_is_c20_FSAC2021;
  uint8_T c20_temporalCounter_i1;
  uint32_T c20_presentTicks;
  uint32_T c20_elapsedTicks;
  uint32_T c20_previousTicks;
  uint8_T c20_doSetSimStateSideEffects;
  const mxArray *c20_setSimStateSideEffectsInfo;
} SFc20_FSAC2021InstanceStruct;

#endif                                 /*typedef_SFc20_FSAC2021InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c20_FSAC2021_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c20_FSAC2021_get_check_sum(mxArray *plhs[]);
extern void c20_FSAC2021_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
