#ifndef __c14_FSAC2021_V1_h__
#define __c14_FSAC2021_V1_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc14_FSAC2021_V1InstanceStruct
#define typedef_SFc14_FSAC2021_V1InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c14_sfEvent;
  uint8_T c14_tp_Pre_Operation_Mode;
  uint8_T c14_tp_Init;
  uint8_T c14_tp_Move;
  uint8_T c14_tp_Goto;
  uint8_T c14_tp_Origin_Pos_Set;
  uint8_T c14_tp_Origin_Aciton_Move;
  uint8_T c14_tp_Motor_Enable;
  uint8_T c14_tp_First;
  uint8_T c14_tp_Second;
  uint8_T c14_tp_Motor_Move;
  uint8_T c14_tp_Move_Position_Set;
  uint8_T c14_tp_Aciton_Move;
  uint8_T c14_tp_Wait;
  uint8_T c14_tp_Motor_Stanby;
  uint8_T c14_tp_Encoder1;
  boolean_T c14_isStable;
  uint8_T c14_is_active_c14_FSAC2021_V1;
  uint8_T c14_is_c14_FSAC2021_V1;
  uint8_T c14_is_Move;
  uint8_T c14_is_Goto;
  uint8_T c14_is_Motor_Enable;
  uint8_T c14_is_Motor_Move;
  uint8_T c14_is_Motor_Stanby;
  uint8_T c14_temporalCounter_i1;
  uint32_T c14_presentTicks;
  uint32_T c14_elapsedTicks;
  uint32_T c14_previousTicks;
  uint8_T c14_doSetSimStateSideEffects;
  const mxArray *c14_setSimStateSideEffectsInfo;
} SFc14_FSAC2021_V1InstanceStruct;

#endif                                 /*typedef_SFc14_FSAC2021_V1InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c14_FSAC2021_V1_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c14_FSAC2021_V1_get_check_sum(mxArray *plhs[]);
extern void c14_FSAC2021_V1_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
