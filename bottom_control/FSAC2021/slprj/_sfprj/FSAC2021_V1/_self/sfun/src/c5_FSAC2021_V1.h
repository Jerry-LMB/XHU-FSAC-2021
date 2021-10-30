#ifndef __c5_FSAC2021_V1_h__
#define __c5_FSAC2021_V1_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc5_FSAC2021_V1InstanceStruct
#define typedef_SFc5_FSAC2021_V1InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c5_sfEvent;
  uint8_T c5_tp_Task;
  uint8_T c5_tp_init;
  uint8_T c5_tp_Manul;
  uint8_T c5_tp_Driverless;
  boolean_T c5_isStable;
  uint8_T c5_is_active_c5_FSAC2021_V1;
  uint8_T c5_is_c5_FSAC2021_V1;
  uint8_T c5_doSetSimStateSideEffects;
  const mxArray *c5_setSimStateSideEffectsInfo;
} SFc5_FSAC2021_V1InstanceStruct;

#endif                                 /*typedef_SFc5_FSAC2021_V1InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c5_FSAC2021_V1_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c5_FSAC2021_V1_get_check_sum(mxArray *plhs[]);
extern void c5_FSAC2021_V1_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
