/* Include files */

#include <stddef.h>
#include "blas.h"
#include "FSAC2021_826_sfun.h"
#include "c18_FSAC2021_826.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "FSAC2021_826_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c18_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c18_IN_Off                     ((uint8_T)1U)
#define c18_IN_On                      ((uint8_T)2U)
#define c18_IN_Wait                    ((uint8_T)3U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c18_debug_family_names[2] = { "nargin", "nargout" };

static const char * c18_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c18_c_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c18_d_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c18_e_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c18_f_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c18_g_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c18_h_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c18_i_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c18_j_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c18_dataWrittenToVector[1];

/* Function Declarations */
static void initialize_c18_FSAC2021_826(SFc18_FSAC2021_826InstanceStruct
  *chartInstance);
static void initialize_params_c18_FSAC2021_826(SFc18_FSAC2021_826InstanceStruct *
  chartInstance);
static void enable_c18_FSAC2021_826(SFc18_FSAC2021_826InstanceStruct
  *chartInstance);
static void disable_c18_FSAC2021_826(SFc18_FSAC2021_826InstanceStruct
  *chartInstance);
static void c18_update_debugger_state_c18_FSAC2021_826
  (SFc18_FSAC2021_826InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c18_FSAC2021_826
  (SFc18_FSAC2021_826InstanceStruct *chartInstance);
static void set_sim_state_c18_FSAC2021_826(SFc18_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c18_st);
static void c18_set_sim_state_side_effects_c18_FSAC2021_826
  (SFc18_FSAC2021_826InstanceStruct *chartInstance);
static void finalize_c18_FSAC2021_826(SFc18_FSAC2021_826InstanceStruct
  *chartInstance);
static void sf_gateway_c18_FSAC2021_826(SFc18_FSAC2021_826InstanceStruct
  *chartInstance);
static void c18_chartstep_c18_FSAC2021_826(SFc18_FSAC2021_826InstanceStruct
  *chartInstance);
static void initSimStructsc18_FSAC2021_826(SFc18_FSAC2021_826InstanceStruct
  *chartInstance);
static void c18_enter_atomic_Off(SFc18_FSAC2021_826InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c18_machineNumber, uint32_T
  c18_chartNumber, uint32_T c18_instanceNumber);
static const mxArray *c18_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static real_T c18_emlrt_marshallIn(SFc18_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId);
static void c18_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData);
static const mxArray *c18_b_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static boolean_T c18_b_emlrt_marshallIn(SFc18_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId);
static void c18_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData);
static const mxArray *c18_c_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static int32_T c18_c_emlrt_marshallIn(SFc18_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId);
static void c18_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData);
static const mxArray *c18_d_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static uint8_T c18_d_emlrt_marshallIn(SFc18_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c18_b_tp_On, const char_T *c18_identifier);
static uint8_T c18_e_emlrt_marshallIn(SFc18_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId);
static void c18_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData);
static uint32_T c18_f_emlrt_marshallIn(SFc18_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c18_b_previousTicks, const char_T
  *c18_identifier);
static uint32_T c18_g_emlrt_marshallIn(SFc18_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId);
static const mxArray *c18_h_emlrt_marshallIn(SFc18_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c18_b_setSimStateSideEffectsInfo, const char_T *
  c18_identifier);
static const mxArray *c18_i_emlrt_marshallIn(SFc18_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId);
static void c18_updateDataWrittenToVector(SFc18_FSAC2021_826InstanceStruct
  *chartInstance, uint32_T c18_vectorIndex);
static void c18_errorIfDataNotWrittenToFcn(SFc18_FSAC2021_826InstanceStruct
  *chartInstance, uint32_T c18_vectorIndex, uint32_T c18_dataNumber);
static void init_dsm_address_info(SFc18_FSAC2021_826InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c18_FSAC2021_826(SFc18_FSAC2021_826InstanceStruct
  *chartInstance)
{
  chartInstance->c18_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c18_doSetSimStateSideEffects = 0U;
  chartInstance->c18_setSimStateSideEffectsInfo = NULL;
  chartInstance->c18_tp_Off = 0U;
  chartInstance->c18_tp_On = 0U;
  chartInstance->c18_tp_Wait = 0U;
  chartInstance->c18_temporalCounter_i1 = 0U;
  chartInstance->c18_is_active_c18_FSAC2021_826 = 0U;
  chartInstance->c18_is_c18_FSAC2021_826 = c18_IN_NO_ACTIVE_CHILD;
  chartInstance->c18_presentTicks = 0U;
  chartInstance->c18_elapsedTicks = 0U;
  chartInstance->c18_previousTicks = 0U;
}

static void initialize_params_c18_FSAC2021_826(SFc18_FSAC2021_826InstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c18_FSAC2021_826(SFc18_FSAC2021_826InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c18_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.1
    + 0.5);
  chartInstance->c18_previousTicks = chartInstance->c18_presentTicks;
}

static void disable_c18_FSAC2021_826(SFc18_FSAC2021_826InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c18_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.1
    + 0.5);
  chartInstance->c18_elapsedTicks = chartInstance->c18_presentTicks -
    chartInstance->c18_previousTicks;
  chartInstance->c18_previousTicks = chartInstance->c18_presentTicks;
  if ((uint32_T)chartInstance->c18_temporalCounter_i1 +
      chartInstance->c18_elapsedTicks <= 31U) {
    chartInstance->c18_temporalCounter_i1 = (uint8_T)((uint32_T)
      chartInstance->c18_temporalCounter_i1 + chartInstance->c18_elapsedTicks);
  } else {
    chartInstance->c18_temporalCounter_i1 = 31U;
  }
}

static void c18_update_debugger_state_c18_FSAC2021_826
  (SFc18_FSAC2021_826InstanceStruct *chartInstance)
{
  uint32_T c18_prevAniVal;
  c18_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c18_is_active_c18_FSAC2021_826 == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 16U, chartInstance->c18_sfEvent);
  }

  if (chartInstance->c18_is_c18_FSAC2021_826 == c18_IN_On) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c18_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c18_sfEvent);
  }

  if (chartInstance->c18_is_c18_FSAC2021_826 == c18_IN_Off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c18_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c18_sfEvent);
  }

  if (chartInstance->c18_is_c18_FSAC2021_826 == c18_IN_Wait) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c18_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c18_sfEvent);
  }

  _SFD_SET_ANIMATION(c18_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c18_FSAC2021_826
  (SFc18_FSAC2021_826InstanceStruct *chartInstance)
{
  const mxArray *c18_st;
  const mxArray *c18_y = NULL;
  uint8_T c18_hoistedGlobal;
  uint8_T c18_u;
  const mxArray *c18_b_y = NULL;
  uint8_T c18_b_hoistedGlobal;
  uint8_T c18_b_u;
  const mxArray *c18_c_y = NULL;
  uint8_T c18_c_hoistedGlobal;
  uint8_T c18_c_u;
  const mxArray *c18_d_y = NULL;
  uint8_T c18_d_hoistedGlobal;
  uint8_T c18_d_u;
  const mxArray *c18_e_y = NULL;
  uint32_T c18_e_hoistedGlobal;
  uint32_T c18_e_u;
  const mxArray *c18_f_y = NULL;
  uint8_T *c18_Debounce;
  c18_Debounce = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c18_st = NULL;
  c18_st = NULL;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_createcellmatrix(5, 1), false);
  c18_hoistedGlobal = *c18_Debounce;
  c18_u = c18_hoistedGlobal;
  c18_b_y = NULL;
  sf_mex_assign(&c18_b_y, sf_mex_create("y", &c18_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c18_y, 0, c18_b_y);
  c18_b_hoistedGlobal = chartInstance->c18_is_active_c18_FSAC2021_826;
  c18_b_u = c18_b_hoistedGlobal;
  c18_c_y = NULL;
  sf_mex_assign(&c18_c_y, sf_mex_create("y", &c18_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c18_y, 1, c18_c_y);
  c18_c_hoistedGlobal = chartInstance->c18_is_c18_FSAC2021_826;
  c18_c_u = c18_c_hoistedGlobal;
  c18_d_y = NULL;
  sf_mex_assign(&c18_d_y, sf_mex_create("y", &c18_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c18_y, 2, c18_d_y);
  c18_d_hoistedGlobal = chartInstance->c18_temporalCounter_i1;
  c18_d_u = c18_d_hoistedGlobal;
  c18_e_y = NULL;
  sf_mex_assign(&c18_e_y, sf_mex_create("y", &c18_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c18_y, 3, c18_e_y);
  c18_e_hoistedGlobal = chartInstance->c18_previousTicks;
  c18_e_u = c18_e_hoistedGlobal;
  c18_f_y = NULL;
  sf_mex_assign(&c18_f_y, sf_mex_create("y", &c18_e_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c18_y, 4, c18_f_y);
  sf_mex_assign(&c18_st, c18_y, false);
  return c18_st;
}

static void set_sim_state_c18_FSAC2021_826(SFc18_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c18_st)
{
  const mxArray *c18_u;
  uint8_T *c18_Debounce;
  c18_Debounce = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c18_u = sf_mex_dup(c18_st);
  *c18_Debounce = c18_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c18_u, 0)), "Debounce");
  chartInstance->c18_is_active_c18_FSAC2021_826 = c18_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c18_u, 1)),
     "is_active_c18_FSAC2021_826");
  chartInstance->c18_is_c18_FSAC2021_826 = c18_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c18_u, 2)), "is_c18_FSAC2021_826");
  chartInstance->c18_temporalCounter_i1 = c18_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c18_u, 3)), "temporalCounter_i1");
  chartInstance->c18_previousTicks = c18_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c18_u, 4)), "previousTicks");
  sf_mex_assign(&chartInstance->c18_setSimStateSideEffectsInfo,
                c18_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c18_u, 5)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c18_u);
  chartInstance->c18_doSetSimStateSideEffects = 1U;
  c18_update_debugger_state_c18_FSAC2021_826(chartInstance);
  sf_mex_destroy(&c18_st);
}

static void c18_set_sim_state_side_effects_c18_FSAC2021_826
  (SFc18_FSAC2021_826InstanceStruct *chartInstance)
{
  if (chartInstance->c18_doSetSimStateSideEffects != 0) {
    if (chartInstance->c18_is_c18_FSAC2021_826 == c18_IN_Off) {
      chartInstance->c18_tp_Off = 1U;
    } else {
      chartInstance->c18_tp_Off = 0U;
    }

    if (chartInstance->c18_is_c18_FSAC2021_826 == c18_IN_On) {
      chartInstance->c18_tp_On = 1U;
    } else {
      chartInstance->c18_tp_On = 0U;
    }

    if (chartInstance->c18_is_c18_FSAC2021_826 == c18_IN_Wait) {
      chartInstance->c18_tp_Wait = 1U;
      if (sf_mex_sub(chartInstance->c18_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 4) == 0.0) {
        chartInstance->c18_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c18_tp_Wait = 0U;
    }

    chartInstance->c18_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c18_FSAC2021_826(SFc18_FSAC2021_826InstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c18_setSimStateSideEffectsInfo);
}

static void sf_gateway_c18_FSAC2021_826(SFc18_FSAC2021_826InstanceStruct
  *chartInstance)
{
  uint8_T *c18_Non_Debounce;
  uint8_T *c18_Debounce;
  c18_Debounce = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c18_Non_Debounce = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c18_set_sim_state_side_effects_c18_FSAC2021_826(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c18_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.1
    + 0.5);
  chartInstance->c18_elapsedTicks = chartInstance->c18_presentTicks -
    chartInstance->c18_previousTicks;
  chartInstance->c18_previousTicks = chartInstance->c18_presentTicks;
  if ((uint32_T)chartInstance->c18_temporalCounter_i1 +
      chartInstance->c18_elapsedTicks <= 31U) {
    chartInstance->c18_temporalCounter_i1 = (uint8_T)((uint32_T)
      chartInstance->c18_temporalCounter_i1 + chartInstance->c18_elapsedTicks);
  } else {
    chartInstance->c18_temporalCounter_i1 = 31U;
  }

  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 16U, chartInstance->c18_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*c18_Non_Debounce, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)*c18_Debounce, 1U);
  chartInstance->c18_sfEvent = CALL_EVENT;
  c18_chartstep_c18_FSAC2021_826(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_FSAC2021_826MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c18_chartstep_c18_FSAC2021_826(SFc18_FSAC2021_826InstanceStruct
  *chartInstance)
{
  uint32_T c18_debug_family_var_map[3];
  real_T c18_nargin = 0.0;
  real_T c18_nargout = 1.0;
  boolean_T c18_out;
  real_T c18_b_nargin = 0.0;
  real_T c18_b_nargout = 1.0;
  boolean_T c18_b_out;
  real_T c18_c_nargin = 0.0;
  real_T c18_c_nargout = 1.0;
  boolean_T c18_c_out;
  real_T c18_d_nargin = 0.0;
  real_T c18_d_nargout = 1.0;
  boolean_T c18_d_out;
  uint32_T c18_b_debug_family_var_map[2];
  real_T c18_e_nargin = 0.0;
  real_T c18_e_nargout = 0.0;
  uint8_T c18_hoistedGlobal;
  uint8_T c18_u;
  const mxArray *c18_y = NULL;
  uint8_T *c18_Non_Debounce;
  uint8_T *c18_Debounce;
  c18_Debounce = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c18_Non_Debounce = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 16U, chartInstance->c18_sfEvent);
  if (chartInstance->c18_is_active_c18_FSAC2021_826 == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 16U, chartInstance->c18_sfEvent);
    chartInstance->c18_is_active_c18_FSAC2021_826 = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c18_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c18_sfEvent);
    chartInstance->c18_is_c18_FSAC2021_826 = c18_IN_Off;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c18_sfEvent);
    chartInstance->c18_tp_Off = 1U;
    c18_enter_atomic_Off(chartInstance);
  } else {
    switch (chartInstance->c18_is_c18_FSAC2021_826) {
     case c18_IN_Off:
      CV_CHART_EVAL(16, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c18_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c18_f_debug_family_names,
        c18_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_nargin, 0U, c18_sf_marshallOut,
        c18_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_nargout, 1U, c18_sf_marshallOut,
        c18_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_out, 2U, c18_b_sf_marshallOut,
        c18_b_sf_marshallIn);
      c18_out = CV_EML_IF(1, 0, 0, (real_T)*c18_Non_Debounce > 0.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c18_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c18_sfEvent);
        chartInstance->c18_tp_Off = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c18_sfEvent);
        chartInstance->c18_is_c18_FSAC2021_826 = c18_IN_Wait;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c18_sfEvent);
        chartInstance->c18_temporalCounter_i1 = 0U;
        chartInstance->c18_tp_Wait = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                     chartInstance->c18_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c18_sfEvent);
      break;

     case c18_IN_On:
      CV_CHART_EVAL(16, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                   chartInstance->c18_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c18_c_debug_family_names,
        c18_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_b_nargin, 0U, c18_sf_marshallOut,
        c18_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_b_nargout, 1U,
        c18_sf_marshallOut, c18_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_b_out, 2U, c18_b_sf_marshallOut,
        c18_b_sf_marshallIn);
      c18_b_out = CV_EML_IF(3, 0, 0, (real_T)*c18_Non_Debounce == 0.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c18_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c18_sfEvent);
        chartInstance->c18_tp_On = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c18_sfEvent);
        chartInstance->c18_is_c18_FSAC2021_826 = c18_IN_Off;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c18_sfEvent);
        chartInstance->c18_tp_Off = 1U;
        c18_enter_atomic_Off(chartInstance);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                     chartInstance->c18_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c18_sfEvent);
      break;

     case c18_IN_Wait:
      CV_CHART_EVAL(16, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                   chartInstance->c18_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c18_e_debug_family_names,
        c18_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_c_nargin, 0U, c18_sf_marshallOut,
        c18_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_c_nargout, 1U,
        c18_sf_marshallOut, c18_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_c_out, 2U, c18_b_sf_marshallOut,
        c18_b_sf_marshallIn);
      c18_c_out = CV_EML_IF(4, 0, 0, (real_T)*c18_Non_Debounce == 0.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c18_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c18_sfEvent);
        chartInstance->c18_tp_Wait = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c18_sfEvent);
        chartInstance->c18_is_c18_FSAC2021_826 = c18_IN_Off;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c18_sfEvent);
        chartInstance->c18_tp_Off = 1U;
        c18_enter_atomic_Off(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                     chartInstance->c18_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c18_d_debug_family_names,
          c18_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_d_nargin, 0U,
          c18_sf_marshallOut, c18_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_d_nargout, 1U,
          c18_sf_marshallOut, c18_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_d_out, 2U,
          c18_b_sf_marshallOut, c18_b_sf_marshallIn);
        c18_d_out = CV_EML_IF(2, 0, 0, chartInstance->c18_temporalCounter_i1 >=
                              20);
        _SFD_SYMBOL_SCOPE_POP();
        if (c18_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c18_sfEvent);
          chartInstance->c18_tp_Wait = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c18_sfEvent);
          chartInstance->c18_is_c18_FSAC2021_826 = c18_IN_On;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c18_sfEvent);
          chartInstance->c18_tp_On = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c18_debug_family_names,
            c18_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_e_nargin, 0U,
            c18_sf_marshallOut, c18_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_e_nargout, 1U,
            c18_sf_marshallOut, c18_sf_marshallIn);
          *c18_Debounce = 1U;
          c18_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_DATA_RANGE_CHECK((real_T)*c18_Debounce, 1U);
          c18_errorIfDataNotWrittenToFcn(chartInstance, 0U, 1U);
          sf_mex_printf("%s =\\n", "Debounce");
          c18_hoistedGlobal = *c18_Debounce;
          c18_u = c18_hoistedGlobal;
          c18_y = NULL;
          sf_mex_assign(&c18_y, sf_mex_create("y", &c18_u, 3, 0U, 0U, 0U, 0),
                        false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c18_y);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                       chartInstance->c18_sfEvent);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c18_sfEvent);
      break;

     default:
      CV_CHART_EVAL(16, 0, 0);
      chartInstance->c18_is_c18_FSAC2021_826 = c18_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c18_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c18_sfEvent);
}

static void initSimStructsc18_FSAC2021_826(SFc18_FSAC2021_826InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c18_enter_atomic_Off(SFc18_FSAC2021_826InstanceStruct *chartInstance)
{
  uint32_T c18_debug_family_var_map[2];
  real_T c18_nargin = 0.0;
  real_T c18_nargout = 0.0;
  uint8_T c18_hoistedGlobal;
  uint8_T c18_u;
  const mxArray *c18_y = NULL;
  uint8_T *c18_Debounce;
  c18_Debounce = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c18_b_debug_family_names,
    c18_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_nargin, 0U, c18_sf_marshallOut,
    c18_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_nargout, 1U, c18_sf_marshallOut,
    c18_sf_marshallIn);
  *c18_Debounce = 0U;
  c18_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)*c18_Debounce, 1U);
  c18_errorIfDataNotWrittenToFcn(chartInstance, 0U, 1U);
  sf_mex_printf("%s =\\n", "Debounce");
  c18_hoistedGlobal = *c18_Debounce;
  c18_u = c18_hoistedGlobal;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", &c18_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c18_y);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c18_machineNumber, uint32_T
  c18_chartNumber, uint32_T c18_instanceNumber)
{
  (void)c18_machineNumber;
  (void)c18_chartNumber;
  (void)c18_instanceNumber;
}

static const mxArray *c18_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  real_T c18_u;
  const mxArray *c18_y = NULL;
  SFc18_FSAC2021_826InstanceStruct *chartInstance;
  chartInstance = (SFc18_FSAC2021_826InstanceStruct *)chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  c18_u = *(real_T *)c18_inData;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", &c18_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, false);
  return c18_mxArrayOutData;
}

static real_T c18_emlrt_marshallIn(SFc18_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId)
{
  real_T c18_y;
  real_T c18_d0;
  (void)chartInstance;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), &c18_d0, 1, 0, 0U, 0, 0U, 0);
  c18_y = c18_d0;
  sf_mex_destroy(&c18_u);
  return c18_y;
}

static void c18_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData)
{
  const mxArray *c18_nargout;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  real_T c18_y;
  SFc18_FSAC2021_826InstanceStruct *chartInstance;
  chartInstance = (SFc18_FSAC2021_826InstanceStruct *)chartInstanceVoid;
  c18_nargout = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_y = c18_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_nargout),
    &c18_thisId);
  sf_mex_destroy(&c18_nargout);
  *(real_T *)c18_outData = c18_y;
  sf_mex_destroy(&c18_mxArrayInData);
}

static const mxArray *c18_b_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  boolean_T c18_u;
  const mxArray *c18_y = NULL;
  SFc18_FSAC2021_826InstanceStruct *chartInstance;
  chartInstance = (SFc18_FSAC2021_826InstanceStruct *)chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  c18_u = *(boolean_T *)c18_inData;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", &c18_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, false);
  return c18_mxArrayOutData;
}

static boolean_T c18_b_emlrt_marshallIn(SFc18_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId)
{
  boolean_T c18_y;
  boolean_T c18_b0;
  (void)chartInstance;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), &c18_b0, 1, 11, 0U, 0, 0U, 0);
  c18_y = c18_b0;
  sf_mex_destroy(&c18_u);
  return c18_y;
}

static void c18_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData)
{
  const mxArray *c18_sf_internal_predicateOutput;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  boolean_T c18_y;
  SFc18_FSAC2021_826InstanceStruct *chartInstance;
  chartInstance = (SFc18_FSAC2021_826InstanceStruct *)chartInstanceVoid;
  c18_sf_internal_predicateOutput = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_y = c18_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c18_sf_internal_predicateOutput), &c18_thisId);
  sf_mex_destroy(&c18_sf_internal_predicateOutput);
  *(boolean_T *)c18_outData = c18_y;
  sf_mex_destroy(&c18_mxArrayInData);
}

const mxArray *sf_c18_FSAC2021_826_get_eml_resolved_functions_info(void)
{
  const mxArray *c18_nameCaptureInfo = NULL;
  c18_nameCaptureInfo = NULL;
  sf_mex_assign(&c18_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c18_nameCaptureInfo;
}

static const mxArray *c18_c_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  int32_T c18_u;
  const mxArray *c18_y = NULL;
  SFc18_FSAC2021_826InstanceStruct *chartInstance;
  chartInstance = (SFc18_FSAC2021_826InstanceStruct *)chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  c18_u = *(int32_T *)c18_inData;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", &c18_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, false);
  return c18_mxArrayOutData;
}

static int32_T c18_c_emlrt_marshallIn(SFc18_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId)
{
  int32_T c18_y;
  int32_T c18_i0;
  (void)chartInstance;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), &c18_i0, 1, 6, 0U, 0, 0U, 0);
  c18_y = c18_i0;
  sf_mex_destroy(&c18_u);
  return c18_y;
}

static void c18_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData)
{
  const mxArray *c18_b_sfEvent;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  int32_T c18_y;
  SFc18_FSAC2021_826InstanceStruct *chartInstance;
  chartInstance = (SFc18_FSAC2021_826InstanceStruct *)chartInstanceVoid;
  c18_b_sfEvent = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_y = c18_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_b_sfEvent),
    &c18_thisId);
  sf_mex_destroy(&c18_b_sfEvent);
  *(int32_T *)c18_outData = c18_y;
  sf_mex_destroy(&c18_mxArrayInData);
}

static const mxArray *c18_d_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  uint8_T c18_u;
  const mxArray *c18_y = NULL;
  SFc18_FSAC2021_826InstanceStruct *chartInstance;
  chartInstance = (SFc18_FSAC2021_826InstanceStruct *)chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  c18_u = *(uint8_T *)c18_inData;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", &c18_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, false);
  return c18_mxArrayOutData;
}

static uint8_T c18_d_emlrt_marshallIn(SFc18_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c18_b_tp_On, const char_T *c18_identifier)
{
  uint8_T c18_y;
  emlrtMsgIdentifier c18_thisId;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_y = c18_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_b_tp_On),
    &c18_thisId);
  sf_mex_destroy(&c18_b_tp_On);
  return c18_y;
}

static uint8_T c18_e_emlrt_marshallIn(SFc18_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId)
{
  uint8_T c18_y;
  uint8_T c18_u0;
  (void)chartInstance;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), &c18_u0, 1, 3, 0U, 0, 0U, 0);
  c18_y = c18_u0;
  sf_mex_destroy(&c18_u);
  return c18_y;
}

static void c18_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData)
{
  const mxArray *c18_b_tp_On;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  uint8_T c18_y;
  SFc18_FSAC2021_826InstanceStruct *chartInstance;
  chartInstance = (SFc18_FSAC2021_826InstanceStruct *)chartInstanceVoid;
  c18_b_tp_On = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_y = c18_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_b_tp_On),
    &c18_thisId);
  sf_mex_destroy(&c18_b_tp_On);
  *(uint8_T *)c18_outData = c18_y;
  sf_mex_destroy(&c18_mxArrayInData);
}

static uint32_T c18_f_emlrt_marshallIn(SFc18_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c18_b_previousTicks, const char_T
  *c18_identifier)
{
  uint32_T c18_y;
  emlrtMsgIdentifier c18_thisId;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_y = c18_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_b_previousTicks),
    &c18_thisId);
  sf_mex_destroy(&c18_b_previousTicks);
  return c18_y;
}

static uint32_T c18_g_emlrt_marshallIn(SFc18_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId)
{
  uint32_T c18_y;
  uint32_T c18_u1;
  (void)chartInstance;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), &c18_u1, 1, 7, 0U, 0, 0U, 0);
  c18_y = c18_u1;
  sf_mex_destroy(&c18_u);
  return c18_y;
}

static const mxArray *c18_h_emlrt_marshallIn(SFc18_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c18_b_setSimStateSideEffectsInfo, const char_T *
  c18_identifier)
{
  const mxArray *c18_y = NULL;
  emlrtMsgIdentifier c18_thisId;
  c18_y = NULL;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  sf_mex_assign(&c18_y, c18_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c18_b_setSimStateSideEffectsInfo), &c18_thisId), false);
  sf_mex_destroy(&c18_b_setSimStateSideEffectsInfo);
  return c18_y;
}

static const mxArray *c18_i_emlrt_marshallIn(SFc18_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId)
{
  const mxArray *c18_y = NULL;
  (void)chartInstance;
  (void)c18_parentId;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_duplicatearraysafe(&c18_u), false);
  sf_mex_destroy(&c18_u);
  return c18_y;
}

static void c18_updateDataWrittenToVector(SFc18_FSAC2021_826InstanceStruct
  *chartInstance, uint32_T c18_vectorIndex)
{
  (void)chartInstance;
  c18_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c18_vectorIndex, 0, 0, 1, 0)] = true;
}

static void c18_errorIfDataNotWrittenToFcn(SFc18_FSAC2021_826InstanceStruct
  *chartInstance, uint32_T c18_vectorIndex, uint32_T c18_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c18_dataNumber, c18_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c18_vectorIndex, 0, 0, 1,
    0)]);
}

static void init_dsm_address_info(SFc18_FSAC2021_826InstanceStruct
  *chartInstance)
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

void sf_c18_FSAC2021_826_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3502708200U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(939042697U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4038701491U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3451515868U);
}

mxArray *sf_c18_FSAC2021_826_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("2ZXH1t66nvRSsgszLXdg6C");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
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

mxArray *sf_c18_FSAC2021_826_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c18_FSAC2021_826_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c18_FSAC2021_826(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[2],T\"Debounce\",},{M[8],M[0],T\"is_active_c18_FSAC2021_826\",},{M[9],M[0],T\"is_c18_FSAC2021_826\",},{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"at\",M[6],M[1]}}},{M[13],M[0],T\"previousTicks\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c18_FSAC2021_826_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc18_FSAC2021_826InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc18_FSAC2021_826InstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _FSAC2021_826MachineNumber_,
           18,
           3,
           5,
           0,
           2,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_FSAC2021_826MachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_FSAC2021_826MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _FSAC2021_826MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"Non_Debounce");
          _SFD_SET_DATA_PROPS(1,2,0,1,"Debounce");
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
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,1,16,1,16);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,1,13,1,13);
        _SFD_CV_INIT_EML(4,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(4,0,0,1,16,1,16);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,15,1,15);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c18_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c18_d_sf_marshallOut,(MexInFcnForType)
          c18_d_sf_marshallIn);

        {
          uint8_T *c18_Non_Debounce;
          uint8_T *c18_Debounce;
          c18_Debounce = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c18_Non_Debounce = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c18_Non_Debounce);
          _SFD_SET_DATA_VALUE_PTR(1U, c18_Debounce);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _FSAC2021_826MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "oX1LV5YRVpM59C5TKqiu7B";
}

static void sf_opaque_initialize_c18_FSAC2021_826(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc18_FSAC2021_826InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c18_FSAC2021_826((SFc18_FSAC2021_826InstanceStruct*)
    chartInstanceVar);
  initialize_c18_FSAC2021_826((SFc18_FSAC2021_826InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c18_FSAC2021_826(void *chartInstanceVar)
{
  enable_c18_FSAC2021_826((SFc18_FSAC2021_826InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c18_FSAC2021_826(void *chartInstanceVar)
{
  disable_c18_FSAC2021_826((SFc18_FSAC2021_826InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c18_FSAC2021_826(void *chartInstanceVar)
{
  sf_gateway_c18_FSAC2021_826((SFc18_FSAC2021_826InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c18_FSAC2021_826(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c18_FSAC2021_826
    ((SFc18_FSAC2021_826InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c18_FSAC2021_826();/* state var info */
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

extern void sf_internal_set_sim_state_c18_FSAC2021_826(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c18_FSAC2021_826();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c18_FSAC2021_826((SFc18_FSAC2021_826InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c18_FSAC2021_826(SimStruct* S)
{
  return sf_internal_get_sim_state_c18_FSAC2021_826(S);
}

static void sf_opaque_set_sim_state_c18_FSAC2021_826(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c18_FSAC2021_826(S, st);
}

static void sf_opaque_terminate_c18_FSAC2021_826(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc18_FSAC2021_826InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_FSAC2021_826_optimization_info();
    }

    finalize_c18_FSAC2021_826((SFc18_FSAC2021_826InstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc18_FSAC2021_826((SFc18_FSAC2021_826InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c18_FSAC2021_826(SimStruct *S)
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
    initialize_params_c18_FSAC2021_826((SFc18_FSAC2021_826InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c18_FSAC2021_826(SimStruct *S)
{
  ssSetNeedAbsoluteTime(S,1);
  ssSetModelReferenceSampleTimeDisallowInheritance(S);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_FSAC2021_826_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      18);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,18,"RTWCG"));
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,18,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,18);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,18,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,18,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,18);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1602075610U));
  ssSetChecksum1(S,(166154906U));
  ssSetChecksum2(S,(3918732378U));
  ssSetChecksum3(S,(2984626124U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c18_FSAC2021_826(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c18_FSAC2021_826(SimStruct *S)
{
  SFc18_FSAC2021_826InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc18_FSAC2021_826InstanceStruct *)utMalloc(sizeof
    (SFc18_FSAC2021_826InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc18_FSAC2021_826InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c18_FSAC2021_826;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c18_FSAC2021_826;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c18_FSAC2021_826;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c18_FSAC2021_826;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c18_FSAC2021_826;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c18_FSAC2021_826;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c18_FSAC2021_826;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c18_FSAC2021_826;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c18_FSAC2021_826;
  chartInstance->chartInfo.mdlStart = mdlStart_c18_FSAC2021_826;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c18_FSAC2021_826;
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

void c18_FSAC2021_826_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c18_FSAC2021_826(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c18_FSAC2021_826(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c18_FSAC2021_826(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c18_FSAC2021_826_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
