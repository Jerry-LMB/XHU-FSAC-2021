#ifndef __c22_FSAC2021_826_h__
#define __c22_FSAC2021_826_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc22_FSAC2021_826InstanceStruct
#define typedef_SFc22_FSAC2021_826InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c22_sfEvent;
  uint8_T c22_tp_Idle;
  uint8_T c22_tp_RunMode;
  uint8_T c22_tp_Init;
  uint8_T c22_tp_Stop;
  uint8_T c22_tp_BackOrigin;
  uint8_T c22_tp_BRK_ENGAGED;
  uint8_T c22_tp_Move;
  uint8_T c22_tp_Back;
  boolean_T c22_isStable;
  uint8_T c22_is_active_c22_FSAC2021_826;
  uint8_T c22_is_c22_FSAC2021_826;
  uint8_T c22_is_RunMode;
  real32_T c22_BRK_DISPSENS_LOWLIMIT;
  uint8_T c22_ENABLE;
  uint8_T c22_BRK_ENGAGED;
  uint8_T c22_BRK_TOZERO;
  uint8_T c22_BRK_MOVE;
  uint8_T c22_DISABLE;
  uint8_T c22_temporalCounter_i1;
  uint32_T c22_presentTicks;
  uint32_T c22_elapsedTicks;
  uint32_T c22_previousTicks;
  uint8_T c22_doSetSimStateSideEffects;
  const mxArray *c22_setSimStateSideEffectsInfo;
} SFc22_FSAC2021_826InstanceStruct;

#endif                                 /*typedef_SFc22_FSAC2021_826InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c22_FSAC2021_826_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c22_FSAC2021_826_get_check_sum(mxArray *plhs[]);
extern void c22_FSAC2021_826_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
