/* Include files */

#include <stddef.h>
#include "blas.h"
#include "FSAC2021_V1_sfun.h"
#include "c23_FSAC2021_V1.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "FSAC2021_V1_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c23_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c23_IN_Action                  ((uint8_T)1U)
#define c23_IN_Action1                 ((uint8_T)2U)
#define c23_IN_Init                    ((uint8_T)3U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c23_debug_family_names[2] = { "nargin", "nargout" };

static const char * c23_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c23_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c23_d_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c23_e_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c23_f_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c23_g_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c23_h_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c23_i_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c23_dataWrittenToVector[1];

/* Function Declarations */
static void initialize_c23_FSAC2021_V1(SFc23_FSAC2021_V1InstanceStruct
  *chartInstance);
static void initialize_params_c23_FSAC2021_V1(SFc23_FSAC2021_V1InstanceStruct
  *chartInstance);
static void enable_c23_FSAC2021_V1(SFc23_FSAC2021_V1InstanceStruct
  *chartInstance);
static void disable_c23_FSAC2021_V1(SFc23_FSAC2021_V1InstanceStruct
  *chartInstance);
static void c23_update_debugger_state_c23_FSAC2021_V1
  (SFc23_FSAC2021_V1InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c23_FSAC2021_V1
  (SFc23_FSAC2021_V1InstanceStruct *chartInstance);
static void set_sim_state_c23_FSAC2021_V1(SFc23_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c23_st);
static void c23_set_sim_state_side_effects_c23_FSAC2021_V1
  (SFc23_FSAC2021_V1InstanceStruct *chartInstance);
static void finalize_c23_FSAC2021_V1(SFc23_FSAC2021_V1InstanceStruct
  *chartInstance);
static void sf_gateway_c23_FSAC2021_V1(SFc23_FSAC2021_V1InstanceStruct
  *chartInstance);
static void c23_chartstep_c23_FSAC2021_V1(SFc23_FSAC2021_V1InstanceStruct
  *chartInstance);
static void initSimStructsc23_FSAC2021_V1(SFc23_FSAC2021_V1InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c23_machineNumber, uint32_T
  c23_chartNumber, uint32_T c23_instanceNumber);
static const mxArray *c23_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static real_T c23_emlrt_marshallIn(SFc23_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c23_nargout, const char_T *c23_identifier);
static real_T c23_b_emlrt_marshallIn(SFc23_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void c23_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static const mxArray *c23_b_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static boolean_T c23_c_emlrt_marshallIn(SFc23_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void c23_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static const mxArray *c23_c_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static int32_T c23_d_emlrt_marshallIn(SFc23_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void c23_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static const mxArray *c23_d_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static uint8_T c23_e_emlrt_marshallIn(SFc23_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c23_b_tp_Action, const char_T *c23_identifier);
static uint8_T c23_f_emlrt_marshallIn(SFc23_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void c23_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static const mxArray *c23_e_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static uint32_T c23_g_emlrt_marshallIn(SFc23_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c23_b_previousTicks, const char_T
  *c23_identifier);
static uint32_T c23_h_emlrt_marshallIn(SFc23_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static const mxArray *c23_i_emlrt_marshallIn(SFc23_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c23_b_setSimStateSideEffectsInfo, const char_T *
  c23_identifier);
static const mxArray *c23_j_emlrt_marshallIn(SFc23_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void c23_updateDataWrittenToVector(SFc23_FSAC2021_V1InstanceStruct
  *chartInstance, uint32_T c23_vectorIndex);
static void init_dsm_address_info(SFc23_FSAC2021_V1InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c23_FSAC2021_V1(SFc23_FSAC2021_V1InstanceStruct
  *chartInstance)
{
  chartInstance->c23_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c23_doSetSimStateSideEffects = 0U;
  chartInstance->c23_setSimStateSideEffectsInfo = NULL;
  chartInstance->c23_tp_Action = 0U;
  chartInstance->c23_tp_Action1 = 0U;
  chartInstance->c23_temporalCounter_i1 = 0U;
  chartInstance->c23_tp_Init = 0U;
  chartInstance->c23_temporalCounter_i1 = 0U;
  chartInstance->c23_is_active_c23_FSAC2021_V1 = 0U;
  chartInstance->c23_is_c23_FSAC2021_V1 = c23_IN_NO_ACTIVE_CHILD;
  chartInstance->c23_presentTicks = 0U;
  chartInstance->c23_elapsedTicks = 0U;
  chartInstance->c23_previousTicks = 0U;
}

static void initialize_params_c23_FSAC2021_V1(SFc23_FSAC2021_V1InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c23_FSAC2021_V1(SFc23_FSAC2021_V1InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c23_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.1
    + 0.5);
  chartInstance->c23_previousTicks = chartInstance->c23_presentTicks;
}

static void disable_c23_FSAC2021_V1(SFc23_FSAC2021_V1InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c23_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.1
    + 0.5);
  chartInstance->c23_elapsedTicks = chartInstance->c23_presentTicks -
    chartInstance->c23_previousTicks;
  chartInstance->c23_previousTicks = chartInstance->c23_presentTicks;
  if ((uint32_T)chartInstance->c23_temporalCounter_i1 +
      chartInstance->c23_elapsedTicks <= 7U) {
    chartInstance->c23_temporalCounter_i1 = (uint8_T)((uint32_T)
      chartInstance->c23_temporalCounter_i1 + chartInstance->c23_elapsedTicks);
  } else {
    chartInstance->c23_temporalCounter_i1 = 7U;
  }
}

static void c23_update_debugger_state_c23_FSAC2021_V1
  (SFc23_FSAC2021_V1InstanceStruct *chartInstance)
{
  uint32_T c23_prevAniVal;
  c23_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c23_is_active_c23_FSAC2021_V1 == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 22U, chartInstance->c23_sfEvent);
  }

  if (chartInstance->c23_is_c23_FSAC2021_V1 == c23_IN_Action) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c23_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c23_sfEvent);
  }

  if (chartInstance->c23_is_c23_FSAC2021_V1 == c23_IN_Init) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c23_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c23_sfEvent);
  }

  if (chartInstance->c23_is_c23_FSAC2021_V1 == c23_IN_Action1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c23_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c23_sfEvent);
  }

  _SFD_SET_ANIMATION(c23_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c23_FSAC2021_V1
  (SFc23_FSAC2021_V1InstanceStruct *chartInstance)
{
  const mxArray *c23_st;
  const mxArray *c23_y = NULL;
  real_T c23_hoistedGlobal;
  real_T c23_u;
  const mxArray *c23_b_y = NULL;
  uint8_T c23_b_hoistedGlobal;
  uint8_T c23_b_u;
  const mxArray *c23_c_y = NULL;
  uint8_T c23_c_hoistedGlobal;
  uint8_T c23_c_u;
  const mxArray *c23_d_y = NULL;
  uint8_T c23_d_hoistedGlobal;
  uint8_T c23_d_u;
  const mxArray *c23_e_y = NULL;
  uint32_T c23_e_hoistedGlobal;
  uint32_T c23_e_u;
  const mxArray *c23_f_y = NULL;
  real_T *c23_Acc_Flag;
  c23_Acc_Flag = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c23_st = NULL;
  c23_st = NULL;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_createcellmatrix(5, 1), false);
  c23_hoistedGlobal = *c23_Acc_Flag;
  c23_u = c23_hoistedGlobal;
  c23_b_y = NULL;
  sf_mex_assign(&c23_b_y, sf_mex_create("y", &c23_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c23_y, 0, c23_b_y);
  c23_b_hoistedGlobal = chartInstance->c23_is_active_c23_FSAC2021_V1;
  c23_b_u = c23_b_hoistedGlobal;
  c23_c_y = NULL;
  sf_mex_assign(&c23_c_y, sf_mex_create("y", &c23_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c23_y, 1, c23_c_y);
  c23_c_hoistedGlobal = chartInstance->c23_is_c23_FSAC2021_V1;
  c23_c_u = c23_c_hoistedGlobal;
  c23_d_y = NULL;
  sf_mex_assign(&c23_d_y, sf_mex_create("y", &c23_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c23_y, 2, c23_d_y);
  c23_d_hoistedGlobal = chartInstance->c23_temporalCounter_i1;
  c23_d_u = c23_d_hoistedGlobal;
  c23_e_y = NULL;
  sf_mex_assign(&c23_e_y, sf_mex_create("y", &c23_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c23_y, 3, c23_e_y);
  c23_e_hoistedGlobal = chartInstance->c23_previousTicks;
  c23_e_u = c23_e_hoistedGlobal;
  c23_f_y = NULL;
  sf_mex_assign(&c23_f_y, sf_mex_create("y", &c23_e_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c23_y, 4, c23_f_y);
  sf_mex_assign(&c23_st, c23_y, false);
  return c23_st;
}

static void set_sim_state_c23_FSAC2021_V1(SFc23_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c23_st)
{
  const mxArray *c23_u;
  real_T *c23_Acc_Flag;
  c23_Acc_Flag = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c23_u = sf_mex_dup(c23_st);
  *c23_Acc_Flag = c23_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c23_u, 0)), "Acc_Flag");
  chartInstance->c23_is_active_c23_FSAC2021_V1 = c23_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c23_u, 1)),
     "is_active_c23_FSAC2021_V1");
  chartInstance->c23_is_c23_FSAC2021_V1 = c23_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c23_u, 2)), "is_c23_FSAC2021_V1");
  chartInstance->c23_temporalCounter_i1 = c23_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c23_u, 3)), "temporalCounter_i1");
  chartInstance->c23_previousTicks = c23_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c23_u, 4)), "previousTicks");
  sf_mex_assign(&chartInstance->c23_setSimStateSideEffectsInfo,
                c23_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c23_u, 5)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c23_u);
  chartInstance->c23_doSetSimStateSideEffects = 1U;
  c23_update_debugger_state_c23_FSAC2021_V1(chartInstance);
  sf_mex_destroy(&c23_st);
}

static void c23_set_sim_state_side_effects_c23_FSAC2021_V1
  (SFc23_FSAC2021_V1InstanceStruct *chartInstance)
{
  if (chartInstance->c23_doSetSimStateSideEffects != 0) {
    if (chartInstance->c23_is_c23_FSAC2021_V1 == c23_IN_Action) {
      chartInstance->c23_tp_Action = 1U;
    } else {
      chartInstance->c23_tp_Action = 0U;
    }

    if (chartInstance->c23_is_c23_FSAC2021_V1 == c23_IN_Action1) {
      chartInstance->c23_tp_Action1 = 1U;
      if (sf_mex_sub(chartInstance->c23_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 3) == 0.0) {
        chartInstance->c23_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c23_tp_Action1 = 0U;
    }

    if (chartInstance->c23_is_c23_FSAC2021_V1 == c23_IN_Init) {
      chartInstance->c23_tp_Init = 1U;
      if (sf_mex_sub(chartInstance->c23_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 4) == 0.0) {
        chartInstance->c23_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c23_tp_Init = 0U;
    }

    chartInstance->c23_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c23_FSAC2021_V1(SFc23_FSAC2021_V1InstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c23_setSimStateSideEffectsInfo);
}

static void sf_gateway_c23_FSAC2021_V1(SFc23_FSAC2021_V1InstanceStruct
  *chartInstance)
{
  uint16_T *c23_liquid_presuress;
  real_T *c23_Acc;
  real_T *c23_Acc_Flag;
  c23_Acc_Flag = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c23_Acc = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c23_liquid_presuress = (uint16_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c23_set_sim_state_side_effects_c23_FSAC2021_V1(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c23_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.1
    + 0.5);
  chartInstance->c23_elapsedTicks = chartInstance->c23_presentTicks -
    chartInstance->c23_previousTicks;
  chartInstance->c23_previousTicks = chartInstance->c23_presentTicks;
  if ((uint32_T)chartInstance->c23_temporalCounter_i1 +
      chartInstance->c23_elapsedTicks <= 7U) {
    chartInstance->c23_temporalCounter_i1 = (uint8_T)((uint32_T)
      chartInstance->c23_temporalCounter_i1 + chartInstance->c23_elapsedTicks);
  } else {
    chartInstance->c23_temporalCounter_i1 = 7U;
  }

  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 22U, chartInstance->c23_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*c23_liquid_presuress, 0U);
  _SFD_DATA_RANGE_CHECK(*c23_Acc, 1U);
  _SFD_DATA_RANGE_CHECK(*c23_Acc_Flag, 2U);
  chartInstance->c23_sfEvent = CALL_EVENT;
  c23_chartstep_c23_FSAC2021_V1(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_FSAC2021_V1MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c23_chartstep_c23_FSAC2021_V1(SFc23_FSAC2021_V1InstanceStruct
  *chartInstance)
{
  uint32_T c23_debug_family_var_map[2];
  real_T c23_nargin = 0.0;
  real_T c23_nargout = 0.0;
  uint32_T c23_b_debug_family_var_map[3];
  real_T c23_b_nargin = 0.0;
  real_T c23_b_nargout = 1.0;
  boolean_T c23_out;
  real_T c23_c_nargin = 0.0;
  real_T c23_c_nargout = 0.0;
  real_T c23_d_nargin = 0.0;
  real_T c23_d_nargout = 1.0;
  boolean_T c23_b_out;
  real_T c23_e_nargin = 0.0;
  real_T c23_e_nargout = 0.0;
  real_T c23_f_nargin = 0.0;
  real_T c23_f_nargout = 1.0;
  boolean_T c23_c_out;
  real_T c23_g_nargin = 0.0;
  real_T c23_g_nargout = 0.0;
  real_T *c23_Acc;
  real_T *c23_Acc_Flag;
  uint16_T *c23_liquid_presuress;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  c23_Acc_Flag = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c23_Acc = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c23_liquid_presuress = (uint16_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 22U, chartInstance->c23_sfEvent);
  if (chartInstance->c23_is_active_c23_FSAC2021_V1 == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 22U, chartInstance->c23_sfEvent);
    chartInstance->c23_is_active_c23_FSAC2021_V1 = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 22U, chartInstance->c23_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c23_sfEvent);
    chartInstance->c23_is_c23_FSAC2021_V1 = c23_IN_Init;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c23_sfEvent);
    chartInstance->c23_temporalCounter_i1 = 0U;
    chartInstance->c23_tp_Init = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c23_b_debug_family_names,
      c23_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_nargin, 0U, c23_sf_marshallOut,
      c23_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_nargout, 1U, c23_sf_marshallOut,
      c23_sf_marshallIn);
    *c23_Acc_Flag = 0.0;
    c23_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*c23_Acc_Flag, 2U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    switch (chartInstance->c23_is_c23_FSAC2021_V1) {
     case c23_IN_Action:
      CV_CHART_EVAL(22, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                   chartInstance->c23_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c23_f_debug_family_names,
        c23_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_b_nargin, 0U, c23_sf_marshallOut,
        c23_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_b_nargout, 1U,
        c23_sf_marshallOut, c23_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_out, 2U, c23_b_sf_marshallOut,
        c23_b_sf_marshallIn);
      c23_out = CV_EML_IF(2, 0, 0, *c23_Acc <= 5.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c23_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c23_sfEvent);
        chartInstance->c23_tp_Action = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c23_sfEvent);
        chartInstance->c23_is_c23_FSAC2021_V1 = c23_IN_Action1;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c23_sfEvent);
        chartInstance->c23_temporalCounter_i1 = 0U;
        chartInstance->c23_tp_Action1 = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c23_c_debug_family_names,
          c23_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_c_nargin, 0U,
          c23_sf_marshallOut, c23_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_c_nargout, 1U,
          c23_sf_marshallOut, c23_sf_marshallIn);
        *c23_Acc_Flag = 0.0;
        c23_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(*c23_Acc_Flag, 2U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                     chartInstance->c23_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c23_sfEvent);
      break;

     case c23_IN_Action1:
      CV_CHART_EVAL(22, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                   chartInstance->c23_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c23_e_debug_family_names,
        c23_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_d_nargin, 0U, c23_sf_marshallOut,
        c23_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_d_nargout, 1U,
        c23_sf_marshallOut, c23_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_b_out, 2U, c23_b_sf_marshallOut,
        c23_b_sf_marshallIn);
      guard3 = false;
      guard4 = false;
      if (CV_EML_COND(3, 0, 0, (real_T)*c23_liquid_presuress > 200.0)) {
        if (CV_EML_COND(3, 0, 1, *c23_Acc >= 25.0)) {
          if (CV_EML_COND(3, 0, 2, chartInstance->c23_temporalCounter_i1 >= 5))
          {
            CV_EML_MCDC(3, 0, 0, true);
            CV_EML_IF(3, 0, 0, true);
            c23_b_out = true;
          } else {
            guard3 = true;
          }
        } else {
          guard4 = true;
        }
      } else {
        guard4 = true;
      }

      if (guard4 == true) {
        guard3 = true;
      }

      if (guard3 == true) {
        CV_EML_MCDC(3, 0, 0, false);
        CV_EML_IF(3, 0, 0, false);
        c23_b_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c23_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c23_sfEvent);
        chartInstance->c23_tp_Action1 = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c23_sfEvent);
        chartInstance->c23_is_c23_FSAC2021_V1 = c23_IN_Action;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c23_sfEvent);
        chartInstance->c23_tp_Action = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c23_debug_family_names,
          c23_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_e_nargin, 0U,
          c23_sf_marshallOut, c23_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_e_nargout, 1U,
          c23_sf_marshallOut, c23_sf_marshallIn);
        *c23_Acc_Flag = 1.0;
        c23_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(*c23_Acc_Flag, 2U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                     chartInstance->c23_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c23_sfEvent);
      break;

     case c23_IN_Init:
      CV_CHART_EVAL(22, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c23_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c23_d_debug_family_names,
        c23_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_f_nargin, 0U, c23_sf_marshallOut,
        c23_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_f_nargout, 1U,
        c23_sf_marshallOut, c23_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_c_out, 2U, c23_b_sf_marshallOut,
        c23_b_sf_marshallIn);
      guard1 = false;
      guard2 = false;
      if (CV_EML_COND(1, 0, 0, (real_T)*c23_liquid_presuress > 200.0)) {
        if (CV_EML_COND(1, 0, 1, *c23_Acc >= 25.0)) {
          if (CV_EML_COND(1, 0, 2, chartInstance->c23_temporalCounter_i1 >= 5))
          {
            CV_EML_MCDC(1, 0, 0, true);
            CV_EML_IF(1, 0, 0, true);
            c23_c_out = true;
          } else {
            guard1 = true;
          }
        } else {
          guard2 = true;
        }
      } else {
        guard2 = true;
      }

      if (guard2 == true) {
        guard1 = true;
      }

      if (guard1 == true) {
        CV_EML_MCDC(1, 0, 0, false);
        CV_EML_IF(1, 0, 0, false);
        c23_c_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c23_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c23_sfEvent);
        chartInstance->c23_tp_Init = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c23_sfEvent);
        chartInstance->c23_is_c23_FSAC2021_V1 = c23_IN_Action;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c23_sfEvent);
        chartInstance->c23_tp_Action = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c23_debug_family_names,
          c23_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_g_nargin, 0U,
          c23_sf_marshallOut, c23_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_g_nargout, 1U,
          c23_sf_marshallOut, c23_sf_marshallIn);
        *c23_Acc_Flag = 1.0;
        c23_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(*c23_Acc_Flag, 2U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                     chartInstance->c23_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c23_sfEvent);
      break;

     default:
      CV_CHART_EVAL(22, 0, 0);
      chartInstance->c23_is_c23_FSAC2021_V1 = c23_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c23_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 22U, chartInstance->c23_sfEvent);
}

static void initSimStructsc23_FSAC2021_V1(SFc23_FSAC2021_V1InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c23_machineNumber, uint32_T
  c23_chartNumber, uint32_T c23_instanceNumber)
{
  (void)c23_machineNumber;
  (void)c23_chartNumber;
  (void)c23_instanceNumber;
}

static const mxArray *c23_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  real_T c23_u;
  const mxArray *c23_y = NULL;
  SFc23_FSAC2021_V1InstanceStruct *chartInstance;
  chartInstance = (SFc23_FSAC2021_V1InstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u = *(real_T *)c23_inData;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static real_T c23_emlrt_marshallIn(SFc23_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c23_nargout, const char_T *c23_identifier)
{
  real_T c23_y;
  emlrtMsgIdentifier c23_thisId;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_nargout),
    &c23_thisId);
  sf_mex_destroy(&c23_nargout);
  return c23_y;
}

static real_T c23_b_emlrt_marshallIn(SFc23_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  real_T c23_y;
  real_T c23_d0;
  (void)chartInstance;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_d0, 1, 0, 0U, 0, 0U, 0);
  c23_y = c23_d0;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void c23_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_nargout;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  real_T c23_y;
  SFc23_FSAC2021_V1InstanceStruct *chartInstance;
  chartInstance = (SFc23_FSAC2021_V1InstanceStruct *)chartInstanceVoid;
  c23_nargout = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_nargout),
    &c23_thisId);
  sf_mex_destroy(&c23_nargout);
  *(real_T *)c23_outData = c23_y;
  sf_mex_destroy(&c23_mxArrayInData);
}

static const mxArray *c23_b_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  boolean_T c23_u;
  const mxArray *c23_y = NULL;
  SFc23_FSAC2021_V1InstanceStruct *chartInstance;
  chartInstance = (SFc23_FSAC2021_V1InstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u = *(boolean_T *)c23_inData;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static boolean_T c23_c_emlrt_marshallIn(SFc23_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  boolean_T c23_y;
  boolean_T c23_b0;
  (void)chartInstance;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_b0, 1, 11, 0U, 0, 0U, 0);
  c23_y = c23_b0;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void c23_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_sf_internal_predicateOutput;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  boolean_T c23_y;
  SFc23_FSAC2021_V1InstanceStruct *chartInstance;
  chartInstance = (SFc23_FSAC2021_V1InstanceStruct *)chartInstanceVoid;
  c23_sf_internal_predicateOutput = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c23_sf_internal_predicateOutput), &c23_thisId);
  sf_mex_destroy(&c23_sf_internal_predicateOutput);
  *(boolean_T *)c23_outData = c23_y;
  sf_mex_destroy(&c23_mxArrayInData);
}

const mxArray *sf_c23_FSAC2021_V1_get_eml_resolved_functions_info(void)
{
  const mxArray *c23_nameCaptureInfo = NULL;
  c23_nameCaptureInfo = NULL;
  sf_mex_assign(&c23_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c23_nameCaptureInfo;
}

static const mxArray *c23_c_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  int32_T c23_u;
  const mxArray *c23_y = NULL;
  SFc23_FSAC2021_V1InstanceStruct *chartInstance;
  chartInstance = (SFc23_FSAC2021_V1InstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u = *(int32_T *)c23_inData;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static int32_T c23_d_emlrt_marshallIn(SFc23_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  int32_T c23_y;
  int32_T c23_i0;
  (void)chartInstance;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_i0, 1, 6, 0U, 0, 0U, 0);
  c23_y = c23_i0;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void c23_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_b_sfEvent;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  int32_T c23_y;
  SFc23_FSAC2021_V1InstanceStruct *chartInstance;
  chartInstance = (SFc23_FSAC2021_V1InstanceStruct *)chartInstanceVoid;
  c23_b_sfEvent = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_sfEvent),
    &c23_thisId);
  sf_mex_destroy(&c23_b_sfEvent);
  *(int32_T *)c23_outData = c23_y;
  sf_mex_destroy(&c23_mxArrayInData);
}

static const mxArray *c23_d_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  uint8_T c23_u;
  const mxArray *c23_y = NULL;
  SFc23_FSAC2021_V1InstanceStruct *chartInstance;
  chartInstance = (SFc23_FSAC2021_V1InstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u = *(uint8_T *)c23_inData;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static uint8_T c23_e_emlrt_marshallIn(SFc23_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c23_b_tp_Action, const char_T *c23_identifier)
{
  uint8_T c23_y;
  emlrtMsgIdentifier c23_thisId;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_tp_Action),
    &c23_thisId);
  sf_mex_destroy(&c23_b_tp_Action);
  return c23_y;
}

static uint8_T c23_f_emlrt_marshallIn(SFc23_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  uint8_T c23_y;
  uint8_T c23_u0;
  (void)chartInstance;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_u0, 1, 3, 0U, 0, 0U, 0);
  c23_y = c23_u0;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void c23_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_b_tp_Action;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  uint8_T c23_y;
  SFc23_FSAC2021_V1InstanceStruct *chartInstance;
  chartInstance = (SFc23_FSAC2021_V1InstanceStruct *)chartInstanceVoid;
  c23_b_tp_Action = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_tp_Action),
    &c23_thisId);
  sf_mex_destroy(&c23_b_tp_Action);
  *(uint8_T *)c23_outData = c23_y;
  sf_mex_destroy(&c23_mxArrayInData);
}

static const mxArray *c23_e_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  uint16_T c23_u;
  const mxArray *c23_y = NULL;
  SFc23_FSAC2021_V1InstanceStruct *chartInstance;
  chartInstance = (SFc23_FSAC2021_V1InstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u = *(uint16_T *)c23_inData;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static uint32_T c23_g_emlrt_marshallIn(SFc23_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c23_b_previousTicks, const char_T
  *c23_identifier)
{
  uint32_T c23_y;
  emlrtMsgIdentifier c23_thisId;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_previousTicks),
    &c23_thisId);
  sf_mex_destroy(&c23_b_previousTicks);
  return c23_y;
}

static uint32_T c23_h_emlrt_marshallIn(SFc23_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  uint32_T c23_y;
  uint32_T c23_u1;
  (void)chartInstance;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_u1, 1, 7, 0U, 0, 0U, 0);
  c23_y = c23_u1;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static const mxArray *c23_i_emlrt_marshallIn(SFc23_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c23_b_setSimStateSideEffectsInfo, const char_T *
  c23_identifier)
{
  const mxArray *c23_y = NULL;
  emlrtMsgIdentifier c23_thisId;
  c23_y = NULL;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  sf_mex_assign(&c23_y, c23_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c23_b_setSimStateSideEffectsInfo), &c23_thisId), false);
  sf_mex_destroy(&c23_b_setSimStateSideEffectsInfo);
  return c23_y;
}

static const mxArray *c23_j_emlrt_marshallIn(SFc23_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  const mxArray *c23_y = NULL;
  (void)chartInstance;
  (void)c23_parentId;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_duplicatearraysafe(&c23_u), false);
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void c23_updateDataWrittenToVector(SFc23_FSAC2021_V1InstanceStruct
  *chartInstance, uint32_T c23_vectorIndex)
{
  (void)chartInstance;
  c23_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c23_vectorIndex, 0, 0, 1, 0)] = true;
}

static void init_dsm_address_info(SFc23_FSAC2021_V1InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c23_FSAC2021_V1_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2302241799U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(152496908U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(55457266U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2717104343U);
}

mxArray *sf_c23_FSAC2021_V1_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("BrPw5yRiu12tzVLTKyjZaE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c23_FSAC2021_V1_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c23_FSAC2021_V1_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c23_FSAC2021_V1(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[9],T\"Acc_Flag\",},{M[8],M[0],T\"is_active_c23_FSAC2021_V1\",},{M[9],M[0],T\"is_c23_FSAC2021_V1\",},{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"at\",M1x2[1 5],M[1]}}},{M[13],M[0],T\"previousTicks\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c23_FSAC2021_V1_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc23_FSAC2021_V1InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc23_FSAC2021_V1InstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _FSAC2021_V1MachineNumber_,
           23,
           3,
           4,
           0,
           3,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_FSAC2021_V1MachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_FSAC2021_V1MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _FSAC2021_V1MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"liquid_presuress");
          _SFD_SET_DATA_PROPS(1,1,1,0,"Acc");
          _SFD_SET_DATA_PROPS(2,2,0,1,"Acc_Flag");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_CH_SUBSTATE_COUNT(3);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,2);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
        }

        _SFD_CV_INIT_CHART(3,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,3,1);
        _SFD_CV_INIT_EML_IF(1,0,0,1,55,1,48);

        {
          static int condStart[] = { 1, 27, 40 };

          static int condEnd[] = { 23, 36, 55 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_EML_MCDC(1,0,0,1,55,3,0,&(condStart[0]),&(condEnd[0]),5,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,3,1);
        _SFD_CV_INIT_EML_IF(3,0,0,1,55,1,48);

        {
          static int condStart[] = { 1, 27, 40 };

          static int condEnd[] = { 23, 36, 55 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_EML_MCDC(3,0,0,1,55,3,0,&(condStart[0]),&(condEnd[0]),5,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,1,9,1,9);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_sf_marshallOut,(MexInFcnForType)c23_sf_marshallIn);

        {
          uint16_T *c23_liquid_presuress;
          real_T *c23_Acc;
          real_T *c23_Acc_Flag;
          c23_Acc_Flag = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c23_Acc = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c23_liquid_presuress = (uint16_T *)ssGetInputPortSignal
            (chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c23_liquid_presuress);
          _SFD_SET_DATA_VALUE_PTR(1U, c23_Acc);
          _SFD_SET_DATA_VALUE_PTR(2U, c23_Acc_Flag);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _FSAC2021_V1MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "yMFKeI2tUPUa2M35sqrc1B";
}

static void sf_opaque_initialize_c23_FSAC2021_V1(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc23_FSAC2021_V1InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c23_FSAC2021_V1((SFc23_FSAC2021_V1InstanceStruct*)
    chartInstanceVar);
  initialize_c23_FSAC2021_V1((SFc23_FSAC2021_V1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c23_FSAC2021_V1(void *chartInstanceVar)
{
  enable_c23_FSAC2021_V1((SFc23_FSAC2021_V1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c23_FSAC2021_V1(void *chartInstanceVar)
{
  disable_c23_FSAC2021_V1((SFc23_FSAC2021_V1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c23_FSAC2021_V1(void *chartInstanceVar)
{
  sf_gateway_c23_FSAC2021_V1((SFc23_FSAC2021_V1InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c23_FSAC2021_V1(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c23_FSAC2021_V1
    ((SFc23_FSAC2021_V1InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c23_FSAC2021_V1();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c23_FSAC2021_V1(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c23_FSAC2021_V1();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c23_FSAC2021_V1((SFc23_FSAC2021_V1InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c23_FSAC2021_V1(SimStruct* S)
{
  return sf_internal_get_sim_state_c23_FSAC2021_V1(S);
}

static void sf_opaque_set_sim_state_c23_FSAC2021_V1(SimStruct* S, const mxArray *
  st)
{
  sf_internal_set_sim_state_c23_FSAC2021_V1(S, st);
}

static void sf_opaque_terminate_c23_FSAC2021_V1(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc23_FSAC2021_V1InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_FSAC2021_V1_optimization_info();
    }

    finalize_c23_FSAC2021_V1((SFc23_FSAC2021_V1InstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc23_FSAC2021_V1((SFc23_FSAC2021_V1InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c23_FSAC2021_V1(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c23_FSAC2021_V1((SFc23_FSAC2021_V1InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c23_FSAC2021_V1(SimStruct *S)
{
  ssSetNeedAbsoluteTime(S,1);
  ssSetModelReferenceSampleTimeDisallowInheritance(S);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_FSAC2021_V1_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      23);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,23,"RTWCG"));
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,23,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,23);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,23,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,23,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,23);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(635778154U));
  ssSetChecksum1(S,(2802760174U));
  ssSetChecksum2(S,(1386963809U));
  ssSetChecksum3(S,(814907718U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c23_FSAC2021_V1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c23_FSAC2021_V1(SimStruct *S)
{
  SFc23_FSAC2021_V1InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc23_FSAC2021_V1InstanceStruct *)utMalloc(sizeof
    (SFc23_FSAC2021_V1InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc23_FSAC2021_V1InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c23_FSAC2021_V1;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c23_FSAC2021_V1;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c23_FSAC2021_V1;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c23_FSAC2021_V1;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c23_FSAC2021_V1;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c23_FSAC2021_V1;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c23_FSAC2021_V1;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c23_FSAC2021_V1;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c23_FSAC2021_V1;
  chartInstance->chartInfo.mdlStart = mdlStart_c23_FSAC2021_V1;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c23_FSAC2021_V1;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c23_FSAC2021_V1_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c23_FSAC2021_V1(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c23_FSAC2021_V1(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c23_FSAC2021_V1(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c23_FSAC2021_V1_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
