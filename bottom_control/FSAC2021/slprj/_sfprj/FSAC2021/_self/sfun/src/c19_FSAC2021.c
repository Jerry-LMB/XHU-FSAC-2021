/* Include files */

#include <stddef.h>
#include "blas.h"
#include "FSAC2021_sfun.h"
#include "c19_FSAC2021.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "FSAC2021_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c19_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c19_IN_Off                     ((uint8_T)1U)
#define c19_IN_On                      ((uint8_T)2U)
#define c19_IN_Wait                    ((uint8_T)3U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c19_debug_family_names[2] = { "nargin", "nargout" };

static const char * c19_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c19_c_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c19_d_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c19_e_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c19_f_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c19_g_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c19_h_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c19_i_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c19_j_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c19_dataWrittenToVector[1];

/* Function Declarations */
static void initialize_c19_FSAC2021(SFc19_FSAC2021InstanceStruct *chartInstance);
static void initialize_params_c19_FSAC2021(SFc19_FSAC2021InstanceStruct
  *chartInstance);
static void enable_c19_FSAC2021(SFc19_FSAC2021InstanceStruct *chartInstance);
static void disable_c19_FSAC2021(SFc19_FSAC2021InstanceStruct *chartInstance);
static void c19_update_debugger_state_c19_FSAC2021(SFc19_FSAC2021InstanceStruct *
  chartInstance);
static const mxArray *get_sim_state_c19_FSAC2021(SFc19_FSAC2021InstanceStruct
  *chartInstance);
static void set_sim_state_c19_FSAC2021(SFc19_FSAC2021InstanceStruct
  *chartInstance, const mxArray *c19_st);
static void c19_set_sim_state_side_effects_c19_FSAC2021
  (SFc19_FSAC2021InstanceStruct *chartInstance);
static void finalize_c19_FSAC2021(SFc19_FSAC2021InstanceStruct *chartInstance);
static void sf_gateway_c19_FSAC2021(SFc19_FSAC2021InstanceStruct *chartInstance);
static void c19_chartstep_c19_FSAC2021(SFc19_FSAC2021InstanceStruct
  *chartInstance);
static void initSimStructsc19_FSAC2021(SFc19_FSAC2021InstanceStruct
  *chartInstance);
static void c19_enter_atomic_Off(SFc19_FSAC2021InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c19_machineNumber, uint32_T
  c19_chartNumber, uint32_T c19_instanceNumber);
static const mxArray *c19_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static real_T c19_emlrt_marshallIn(SFc19_FSAC2021InstanceStruct *chartInstance,
  const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void c19_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static const mxArray *c19_b_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static boolean_T c19_b_emlrt_marshallIn(SFc19_FSAC2021InstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void c19_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static const mxArray *c19_c_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static int32_T c19_c_emlrt_marshallIn(SFc19_FSAC2021InstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void c19_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static const mxArray *c19_d_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static uint8_T c19_d_emlrt_marshallIn(SFc19_FSAC2021InstanceStruct
  *chartInstance, const mxArray *c19_b_tp_On, const char_T *c19_identifier);
static uint8_T c19_e_emlrt_marshallIn(SFc19_FSAC2021InstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void c19_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static uint32_T c19_f_emlrt_marshallIn(SFc19_FSAC2021InstanceStruct
  *chartInstance, const mxArray *c19_b_previousTicks, const char_T
  *c19_identifier);
static uint32_T c19_g_emlrt_marshallIn(SFc19_FSAC2021InstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static const mxArray *c19_h_emlrt_marshallIn(SFc19_FSAC2021InstanceStruct
  *chartInstance, const mxArray *c19_b_setSimStateSideEffectsInfo, const char_T *
  c19_identifier);
static const mxArray *c19_i_emlrt_marshallIn(SFc19_FSAC2021InstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void c19_updateDataWrittenToVector(SFc19_FSAC2021InstanceStruct
  *chartInstance, uint32_T c19_vectorIndex);
static void c19_errorIfDataNotWrittenToFcn(SFc19_FSAC2021InstanceStruct
  *chartInstance, uint32_T c19_vectorIndex, uint32_T c19_dataNumber);
static void init_dsm_address_info(SFc19_FSAC2021InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c19_FSAC2021(SFc19_FSAC2021InstanceStruct *chartInstance)
{
  chartInstance->c19_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c19_doSetSimStateSideEffects = 0U;
  chartInstance->c19_setSimStateSideEffectsInfo = NULL;
  chartInstance->c19_tp_Off = 0U;
  chartInstance->c19_tp_On = 0U;
  chartInstance->c19_tp_Wait = 0U;
  chartInstance->c19_temporalCounter_i1 = 0U;
  chartInstance->c19_is_active_c19_FSAC2021 = 0U;
  chartInstance->c19_is_c19_FSAC2021 = c19_IN_NO_ACTIVE_CHILD;
  chartInstance->c19_presentTicks = 0U;
  chartInstance->c19_elapsedTicks = 0U;
  chartInstance->c19_previousTicks = 0U;
}

static void initialize_params_c19_FSAC2021(SFc19_FSAC2021InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c19_FSAC2021(SFc19_FSAC2021InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c19_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.1
    + 0.5);
  chartInstance->c19_previousTicks = chartInstance->c19_presentTicks;
}

static void disable_c19_FSAC2021(SFc19_FSAC2021InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c19_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.1
    + 0.5);
  chartInstance->c19_elapsedTicks = chartInstance->c19_presentTicks -
    chartInstance->c19_previousTicks;
  chartInstance->c19_previousTicks = chartInstance->c19_presentTicks;
  if ((uint32_T)chartInstance->c19_temporalCounter_i1 +
      chartInstance->c19_elapsedTicks <= 31U) {
    chartInstance->c19_temporalCounter_i1 = (uint8_T)((uint32_T)
      chartInstance->c19_temporalCounter_i1 + chartInstance->c19_elapsedTicks);
  } else {
    chartInstance->c19_temporalCounter_i1 = 31U;
  }
}

static void c19_update_debugger_state_c19_FSAC2021(SFc19_FSAC2021InstanceStruct *
  chartInstance)
{
  uint32_T c19_prevAniVal;
  c19_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c19_is_active_c19_FSAC2021 == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 17U, chartInstance->c19_sfEvent);
  }

  if (chartInstance->c19_is_c19_FSAC2021 == c19_IN_On) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c19_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c19_sfEvent);
  }

  if (chartInstance->c19_is_c19_FSAC2021 == c19_IN_Off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c19_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c19_sfEvent);
  }

  if (chartInstance->c19_is_c19_FSAC2021 == c19_IN_Wait) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c19_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c19_sfEvent);
  }

  _SFD_SET_ANIMATION(c19_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c19_FSAC2021(SFc19_FSAC2021InstanceStruct
  *chartInstance)
{
  const mxArray *c19_st;
  const mxArray *c19_y = NULL;
  uint8_T c19_hoistedGlobal;
  uint8_T c19_u;
  const mxArray *c19_b_y = NULL;
  uint8_T c19_b_hoistedGlobal;
  uint8_T c19_b_u;
  const mxArray *c19_c_y = NULL;
  uint8_T c19_c_hoistedGlobal;
  uint8_T c19_c_u;
  const mxArray *c19_d_y = NULL;
  uint8_T c19_d_hoistedGlobal;
  uint8_T c19_d_u;
  const mxArray *c19_e_y = NULL;
  uint32_T c19_e_hoistedGlobal;
  uint32_T c19_e_u;
  const mxArray *c19_f_y = NULL;
  uint8_T *c19_Debounce;
  c19_Debounce = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c19_st = NULL;
  c19_st = NULL;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_createcellmatrix(5, 1), false);
  c19_hoistedGlobal = *c19_Debounce;
  c19_u = c19_hoistedGlobal;
  c19_b_y = NULL;
  sf_mex_assign(&c19_b_y, sf_mex_create("y", &c19_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c19_y, 0, c19_b_y);
  c19_b_hoistedGlobal = chartInstance->c19_is_active_c19_FSAC2021;
  c19_b_u = c19_b_hoistedGlobal;
  c19_c_y = NULL;
  sf_mex_assign(&c19_c_y, sf_mex_create("y", &c19_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c19_y, 1, c19_c_y);
  c19_c_hoistedGlobal = chartInstance->c19_is_c19_FSAC2021;
  c19_c_u = c19_c_hoistedGlobal;
  c19_d_y = NULL;
  sf_mex_assign(&c19_d_y, sf_mex_create("y", &c19_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c19_y, 2, c19_d_y);
  c19_d_hoistedGlobal = chartInstance->c19_temporalCounter_i1;
  c19_d_u = c19_d_hoistedGlobal;
  c19_e_y = NULL;
  sf_mex_assign(&c19_e_y, sf_mex_create("y", &c19_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c19_y, 3, c19_e_y);
  c19_e_hoistedGlobal = chartInstance->c19_previousTicks;
  c19_e_u = c19_e_hoistedGlobal;
  c19_f_y = NULL;
  sf_mex_assign(&c19_f_y, sf_mex_create("y", &c19_e_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c19_y, 4, c19_f_y);
  sf_mex_assign(&c19_st, c19_y, false);
  return c19_st;
}

static void set_sim_state_c19_FSAC2021(SFc19_FSAC2021InstanceStruct
  *chartInstance, const mxArray *c19_st)
{
  const mxArray *c19_u;
  uint8_T *c19_Debounce;
  c19_Debounce = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c19_u = sf_mex_dup(c19_st);
  *c19_Debounce = c19_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c19_u, 0)), "Debounce");
  chartInstance->c19_is_active_c19_FSAC2021 = c19_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c19_u, 1)),
     "is_active_c19_FSAC2021");
  chartInstance->c19_is_c19_FSAC2021 = c19_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c19_u, 2)), "is_c19_FSAC2021");
  chartInstance->c19_temporalCounter_i1 = c19_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c19_u, 3)), "temporalCounter_i1");
  chartInstance->c19_previousTicks = c19_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c19_u, 4)), "previousTicks");
  sf_mex_assign(&chartInstance->c19_setSimStateSideEffectsInfo,
                c19_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c19_u, 5)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c19_u);
  chartInstance->c19_doSetSimStateSideEffects = 1U;
  c19_update_debugger_state_c19_FSAC2021(chartInstance);
  sf_mex_destroy(&c19_st);
}

static void c19_set_sim_state_side_effects_c19_FSAC2021
  (SFc19_FSAC2021InstanceStruct *chartInstance)
{
  if (chartInstance->c19_doSetSimStateSideEffects != 0) {
    if (chartInstance->c19_is_c19_FSAC2021 == c19_IN_Off) {
      chartInstance->c19_tp_Off = 1U;
    } else {
      chartInstance->c19_tp_Off = 0U;
    }

    if (chartInstance->c19_is_c19_FSAC2021 == c19_IN_On) {
      chartInstance->c19_tp_On = 1U;
    } else {
      chartInstance->c19_tp_On = 0U;
    }

    if (chartInstance->c19_is_c19_FSAC2021 == c19_IN_Wait) {
      chartInstance->c19_tp_Wait = 1U;
      if (sf_mex_sub(chartInstance->c19_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 4) == 0.0) {
        chartInstance->c19_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c19_tp_Wait = 0U;
    }

    chartInstance->c19_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c19_FSAC2021(SFc19_FSAC2021InstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c19_setSimStateSideEffectsInfo);
}

static void sf_gateway_c19_FSAC2021(SFc19_FSAC2021InstanceStruct *chartInstance)
{
  uint8_T *c19_Non_Debounce;
  uint8_T *c19_Debounce;
  c19_Debounce = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c19_Non_Debounce = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c19_set_sim_state_side_effects_c19_FSAC2021(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c19_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.1
    + 0.5);
  chartInstance->c19_elapsedTicks = chartInstance->c19_presentTicks -
    chartInstance->c19_previousTicks;
  chartInstance->c19_previousTicks = chartInstance->c19_presentTicks;
  if ((uint32_T)chartInstance->c19_temporalCounter_i1 +
      chartInstance->c19_elapsedTicks <= 31U) {
    chartInstance->c19_temporalCounter_i1 = (uint8_T)((uint32_T)
      chartInstance->c19_temporalCounter_i1 + chartInstance->c19_elapsedTicks);
  } else {
    chartInstance->c19_temporalCounter_i1 = 31U;
  }

  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 17U, chartInstance->c19_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*c19_Non_Debounce, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)*c19_Debounce, 1U);
  chartInstance->c19_sfEvent = CALL_EVENT;
  c19_chartstep_c19_FSAC2021(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_FSAC2021MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c19_chartstep_c19_FSAC2021(SFc19_FSAC2021InstanceStruct
  *chartInstance)
{
  uint32_T c19_debug_family_var_map[3];
  real_T c19_nargin = 0.0;
  real_T c19_nargout = 1.0;
  boolean_T c19_out;
  real_T c19_b_nargin = 0.0;
  real_T c19_b_nargout = 1.0;
  boolean_T c19_b_out;
  real_T c19_c_nargin = 0.0;
  real_T c19_c_nargout = 1.0;
  boolean_T c19_c_out;
  real_T c19_d_nargin = 0.0;
  real_T c19_d_nargout = 1.0;
  boolean_T c19_d_out;
  uint32_T c19_b_debug_family_var_map[2];
  real_T c19_e_nargin = 0.0;
  real_T c19_e_nargout = 0.0;
  uint8_T c19_hoistedGlobal;
  uint8_T c19_u;
  const mxArray *c19_y = NULL;
  uint8_T *c19_Non_Debounce;
  uint8_T *c19_Debounce;
  c19_Debounce = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c19_Non_Debounce = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 17U, chartInstance->c19_sfEvent);
  if (chartInstance->c19_is_active_c19_FSAC2021 == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 17U, chartInstance->c19_sfEvent);
    chartInstance->c19_is_active_c19_FSAC2021 = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, chartInstance->c19_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c19_sfEvent);
    chartInstance->c19_is_c19_FSAC2021 = c19_IN_Off;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c19_sfEvent);
    chartInstance->c19_tp_Off = 1U;
    c19_enter_atomic_Off(chartInstance);
  } else {
    switch (chartInstance->c19_is_c19_FSAC2021) {
     case c19_IN_Off:
      CV_CHART_EVAL(17, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c19_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c19_f_debug_family_names,
        c19_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_nargin, 0U, c19_sf_marshallOut,
        c19_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_nargout, 1U, c19_sf_marshallOut,
        c19_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_out, 2U, c19_b_sf_marshallOut,
        c19_b_sf_marshallIn);
      c19_out = CV_EML_IF(1, 0, 0, (real_T)*c19_Non_Debounce > 0.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c19_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c19_sfEvent);
        chartInstance->c19_tp_Off = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c19_sfEvent);
        chartInstance->c19_is_c19_FSAC2021 = c19_IN_Wait;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c19_sfEvent);
        chartInstance->c19_temporalCounter_i1 = 0U;
        chartInstance->c19_tp_Wait = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                     chartInstance->c19_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c19_sfEvent);
      break;

     case c19_IN_On:
      CV_CHART_EVAL(17, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                   chartInstance->c19_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c19_c_debug_family_names,
        c19_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_b_nargin, 0U, c19_sf_marshallOut,
        c19_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_b_nargout, 1U,
        c19_sf_marshallOut, c19_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_b_out, 2U, c19_b_sf_marshallOut,
        c19_b_sf_marshallIn);
      c19_b_out = CV_EML_IF(3, 0, 0, (real_T)*c19_Non_Debounce == 0.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c19_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c19_sfEvent);
        chartInstance->c19_tp_On = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c19_sfEvent);
        chartInstance->c19_is_c19_FSAC2021 = c19_IN_Off;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c19_sfEvent);
        chartInstance->c19_tp_Off = 1U;
        c19_enter_atomic_Off(chartInstance);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                     chartInstance->c19_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c19_sfEvent);
      break;

     case c19_IN_Wait:
      CV_CHART_EVAL(17, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                   chartInstance->c19_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c19_e_debug_family_names,
        c19_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_c_nargin, 0U, c19_sf_marshallOut,
        c19_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_c_nargout, 1U,
        c19_sf_marshallOut, c19_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_c_out, 2U, c19_b_sf_marshallOut,
        c19_b_sf_marshallIn);
      c19_c_out = CV_EML_IF(4, 0, 0, (real_T)*c19_Non_Debounce == 0.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c19_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c19_sfEvent);
        chartInstance->c19_tp_Wait = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c19_sfEvent);
        chartInstance->c19_is_c19_FSAC2021 = c19_IN_Off;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c19_sfEvent);
        chartInstance->c19_tp_Off = 1U;
        c19_enter_atomic_Off(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                     chartInstance->c19_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c19_d_debug_family_names,
          c19_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_d_nargin, 0U,
          c19_sf_marshallOut, c19_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_d_nargout, 1U,
          c19_sf_marshallOut, c19_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_d_out, 2U,
          c19_b_sf_marshallOut, c19_b_sf_marshallIn);
        c19_d_out = CV_EML_IF(2, 0, 0, chartInstance->c19_temporalCounter_i1 >=
                              20);
        _SFD_SYMBOL_SCOPE_POP();
        if (c19_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c19_sfEvent);
          chartInstance->c19_tp_Wait = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c19_sfEvent);
          chartInstance->c19_is_c19_FSAC2021 = c19_IN_On;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c19_sfEvent);
          chartInstance->c19_tp_On = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c19_debug_family_names,
            c19_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_e_nargin, 0U,
            c19_sf_marshallOut, c19_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_e_nargout, 1U,
            c19_sf_marshallOut, c19_sf_marshallIn);
          *c19_Debounce = 1U;
          c19_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_DATA_RANGE_CHECK((real_T)*c19_Debounce, 1U);
          c19_errorIfDataNotWrittenToFcn(chartInstance, 0U, 1U);
          sf_mex_printf("%s =\\n", "Debounce");
          c19_hoistedGlobal = *c19_Debounce;
          c19_u = c19_hoistedGlobal;
          c19_y = NULL;
          sf_mex_assign(&c19_y, sf_mex_create("y", &c19_u, 3, 0U, 0U, 0U, 0),
                        false);
          sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                            c19_y);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                       chartInstance->c19_sfEvent);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c19_sfEvent);
      break;

     default:
      CV_CHART_EVAL(17, 0, 0);
      chartInstance->c19_is_c19_FSAC2021 = c19_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c19_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, chartInstance->c19_sfEvent);
}

static void initSimStructsc19_FSAC2021(SFc19_FSAC2021InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c19_enter_atomic_Off(SFc19_FSAC2021InstanceStruct *chartInstance)
{
  uint32_T c19_debug_family_var_map[2];
  real_T c19_nargin = 0.0;
  real_T c19_nargout = 0.0;
  uint8_T c19_hoistedGlobal;
  uint8_T c19_u;
  const mxArray *c19_y = NULL;
  uint8_T *c19_Debounce;
  c19_Debounce = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c19_b_debug_family_names,
    c19_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_nargin, 0U, c19_sf_marshallOut,
    c19_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_nargout, 1U, c19_sf_marshallOut,
    c19_sf_marshallIn);
  *c19_Debounce = 0U;
  c19_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)*c19_Debounce, 1U);
  c19_errorIfDataNotWrittenToFcn(chartInstance, 0U, 1U);
  sf_mex_printf("%s =\\n", "Debounce");
  c19_hoistedGlobal = *c19_Debounce;
  c19_u = c19_hoistedGlobal;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", &c19_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c19_y);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c19_machineNumber, uint32_T
  c19_chartNumber, uint32_T c19_instanceNumber)
{
  (void)c19_machineNumber;
  (void)c19_chartNumber;
  (void)c19_instanceNumber;
}

static const mxArray *c19_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  real_T c19_u;
  const mxArray *c19_y = NULL;
  SFc19_FSAC2021InstanceStruct *chartInstance;
  chartInstance = (SFc19_FSAC2021InstanceStruct *)chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_u = *(real_T *)c19_inData;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", &c19_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static real_T c19_emlrt_marshallIn(SFc19_FSAC2021InstanceStruct *chartInstance,
  const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  real_T c19_y;
  real_T c19_d0;
  (void)chartInstance;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_d0, 1, 0, 0U, 0, 0U, 0);
  c19_y = c19_d0;
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void c19_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_nargout;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  real_T c19_y;
  SFc19_FSAC2021InstanceStruct *chartInstance;
  chartInstance = (SFc19_FSAC2021InstanceStruct *)chartInstanceVoid;
  c19_nargout = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_nargout),
    &c19_thisId);
  sf_mex_destroy(&c19_nargout);
  *(real_T *)c19_outData = c19_y;
  sf_mex_destroy(&c19_mxArrayInData);
}

static const mxArray *c19_b_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  boolean_T c19_u;
  const mxArray *c19_y = NULL;
  SFc19_FSAC2021InstanceStruct *chartInstance;
  chartInstance = (SFc19_FSAC2021InstanceStruct *)chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_u = *(boolean_T *)c19_inData;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", &c19_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static boolean_T c19_b_emlrt_marshallIn(SFc19_FSAC2021InstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  boolean_T c19_y;
  boolean_T c19_b0;
  (void)chartInstance;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_b0, 1, 11, 0U, 0, 0U, 0);
  c19_y = c19_b0;
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void c19_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_sf_internal_predicateOutput;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  boolean_T c19_y;
  SFc19_FSAC2021InstanceStruct *chartInstance;
  chartInstance = (SFc19_FSAC2021InstanceStruct *)chartInstanceVoid;
  c19_sf_internal_predicateOutput = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c19_sf_internal_predicateOutput), &c19_thisId);
  sf_mex_destroy(&c19_sf_internal_predicateOutput);
  *(boolean_T *)c19_outData = c19_y;
  sf_mex_destroy(&c19_mxArrayInData);
}

const mxArray *sf_c19_FSAC2021_get_eml_resolved_functions_info(void)
{
  const mxArray *c19_nameCaptureInfo = NULL;
  c19_nameCaptureInfo = NULL;
  sf_mex_assign(&c19_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c19_nameCaptureInfo;
}

static const mxArray *c19_c_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  int32_T c19_u;
  const mxArray *c19_y = NULL;
  SFc19_FSAC2021InstanceStruct *chartInstance;
  chartInstance = (SFc19_FSAC2021InstanceStruct *)chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_u = *(int32_T *)c19_inData;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", &c19_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static int32_T c19_c_emlrt_marshallIn(SFc19_FSAC2021InstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  int32_T c19_y;
  int32_T c19_i0;
  (void)chartInstance;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_i0, 1, 6, 0U, 0, 0U, 0);
  c19_y = c19_i0;
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void c19_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_b_sfEvent;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  int32_T c19_y;
  SFc19_FSAC2021InstanceStruct *chartInstance;
  chartInstance = (SFc19_FSAC2021InstanceStruct *)chartInstanceVoid;
  c19_b_sfEvent = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_b_sfEvent),
    &c19_thisId);
  sf_mex_destroy(&c19_b_sfEvent);
  *(int32_T *)c19_outData = c19_y;
  sf_mex_destroy(&c19_mxArrayInData);
}

static const mxArray *c19_d_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  uint8_T c19_u;
  const mxArray *c19_y = NULL;
  SFc19_FSAC2021InstanceStruct *chartInstance;
  chartInstance = (SFc19_FSAC2021InstanceStruct *)chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_u = *(uint8_T *)c19_inData;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", &c19_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, false);
  return c19_mxArrayOutData;
}

static uint8_T c19_d_emlrt_marshallIn(SFc19_FSAC2021InstanceStruct
  *chartInstance, const mxArray *c19_b_tp_On, const char_T *c19_identifier)
{
  uint8_T c19_y;
  emlrtMsgIdentifier c19_thisId;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_b_tp_On),
    &c19_thisId);
  sf_mex_destroy(&c19_b_tp_On);
  return c19_y;
}

static uint8_T c19_e_emlrt_marshallIn(SFc19_FSAC2021InstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  uint8_T c19_y;
  uint8_T c19_u0;
  (void)chartInstance;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_u0, 1, 3, 0U, 0, 0U, 0);
  c19_y = c19_u0;
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void c19_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_b_tp_On;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  uint8_T c19_y;
  SFc19_FSAC2021InstanceStruct *chartInstance;
  chartInstance = (SFc19_FSAC2021InstanceStruct *)chartInstanceVoid;
  c19_b_tp_On = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_b_tp_On),
    &c19_thisId);
  sf_mex_destroy(&c19_b_tp_On);
  *(uint8_T *)c19_outData = c19_y;
  sf_mex_destroy(&c19_mxArrayInData);
}

static uint32_T c19_f_emlrt_marshallIn(SFc19_FSAC2021InstanceStruct
  *chartInstance, const mxArray *c19_b_previousTicks, const char_T
  *c19_identifier)
{
  uint32_T c19_y;
  emlrtMsgIdentifier c19_thisId;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_b_previousTicks),
    &c19_thisId);
  sf_mex_destroy(&c19_b_previousTicks);
  return c19_y;
}

static uint32_T c19_g_emlrt_marshallIn(SFc19_FSAC2021InstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  uint32_T c19_y;
  uint32_T c19_u1;
  (void)chartInstance;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_u1, 1, 7, 0U, 0, 0U, 0);
  c19_y = c19_u1;
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static const mxArray *c19_h_emlrt_marshallIn(SFc19_FSAC2021InstanceStruct
  *chartInstance, const mxArray *c19_b_setSimStateSideEffectsInfo, const char_T *
  c19_identifier)
{
  const mxArray *c19_y = NULL;
  emlrtMsgIdentifier c19_thisId;
  c19_y = NULL;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  sf_mex_assign(&c19_y, c19_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c19_b_setSimStateSideEffectsInfo), &c19_thisId), false);
  sf_mex_destroy(&c19_b_setSimStateSideEffectsInfo);
  return c19_y;
}

static const mxArray *c19_i_emlrt_marshallIn(SFc19_FSAC2021InstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  const mxArray *c19_y = NULL;
  (void)chartInstance;
  (void)c19_parentId;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_duplicatearraysafe(&c19_u), false);
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void c19_updateDataWrittenToVector(SFc19_FSAC2021InstanceStruct
  *chartInstance, uint32_T c19_vectorIndex)
{
  (void)chartInstance;
  c19_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c19_vectorIndex, 0, 0, 1, 0)] = true;
}

static void c19_errorIfDataNotWrittenToFcn(SFc19_FSAC2021InstanceStruct
  *chartInstance, uint32_T c19_vectorIndex, uint32_T c19_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c19_dataNumber, c19_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c19_vectorIndex, 0, 0, 1,
    0)]);
}

static void init_dsm_address_info(SFc19_FSAC2021InstanceStruct *chartInstance)
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

void sf_c19_FSAC2021_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3502708200U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(939042697U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4038701491U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3451515868U);
}

mxArray *sf_c19_FSAC2021_get_autoinheritance_info(void)
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

mxArray *sf_c19_FSAC2021_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c19_FSAC2021_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c19_FSAC2021(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[2],T\"Debounce\",},{M[8],M[0],T\"is_active_c19_FSAC2021\",},{M[9],M[0],T\"is_c19_FSAC2021\",},{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"at\",M[6],M[1]}}},{M[13],M[0],T\"previousTicks\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c19_FSAC2021_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc19_FSAC2021InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc19_FSAC2021InstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _FSAC2021MachineNumber_,
           19,
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
        init_script_number_translation(_FSAC2021MachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_FSAC2021MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _FSAC2021MachineNumber_,
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
          (MexFcnForType)c19_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_d_sf_marshallOut,(MexInFcnForType)
          c19_d_sf_marshallIn);

        {
          uint8_T *c19_Non_Debounce;
          uint8_T *c19_Debounce;
          c19_Debounce = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c19_Non_Debounce = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c19_Non_Debounce);
          _SFD_SET_DATA_VALUE_PTR(1U, c19_Debounce);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _FSAC2021MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "oX1LV5YRVpM59C5TKqiu7B";
}

static void sf_opaque_initialize_c19_FSAC2021(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc19_FSAC2021InstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c19_FSAC2021((SFc19_FSAC2021InstanceStruct*)
    chartInstanceVar);
  initialize_c19_FSAC2021((SFc19_FSAC2021InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c19_FSAC2021(void *chartInstanceVar)
{
  enable_c19_FSAC2021((SFc19_FSAC2021InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c19_FSAC2021(void *chartInstanceVar)
{
  disable_c19_FSAC2021((SFc19_FSAC2021InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c19_FSAC2021(void *chartInstanceVar)
{
  sf_gateway_c19_FSAC2021((SFc19_FSAC2021InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c19_FSAC2021(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c19_FSAC2021((SFc19_FSAC2021InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c19_FSAC2021();/* state var info */
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

extern void sf_internal_set_sim_state_c19_FSAC2021(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c19_FSAC2021();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c19_FSAC2021((SFc19_FSAC2021InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c19_FSAC2021(SimStruct* S)
{
  return sf_internal_get_sim_state_c19_FSAC2021(S);
}

static void sf_opaque_set_sim_state_c19_FSAC2021(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c19_FSAC2021(S, st);
}

static void sf_opaque_terminate_c19_FSAC2021(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc19_FSAC2021InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_FSAC2021_optimization_info();
    }

    finalize_c19_FSAC2021((SFc19_FSAC2021InstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc19_FSAC2021((SFc19_FSAC2021InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c19_FSAC2021(SimStruct *S)
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
    initialize_params_c19_FSAC2021((SFc19_FSAC2021InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c19_FSAC2021(SimStruct *S)
{
  ssSetNeedAbsoluteTime(S,1);
  ssSetModelReferenceSampleTimeDisallowInheritance(S);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_FSAC2021_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      19);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,19,"RTWCG"));
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,19,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,19);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,19,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,19,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,19);
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

static void mdlRTW_c19_FSAC2021(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c19_FSAC2021(SimStruct *S)
{
  SFc19_FSAC2021InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc19_FSAC2021InstanceStruct *)utMalloc(sizeof
    (SFc19_FSAC2021InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc19_FSAC2021InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c19_FSAC2021;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c19_FSAC2021;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c19_FSAC2021;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c19_FSAC2021;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c19_FSAC2021;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c19_FSAC2021;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c19_FSAC2021;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c19_FSAC2021;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c19_FSAC2021;
  chartInstance->chartInfo.mdlStart = mdlStart_c19_FSAC2021;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c19_FSAC2021;
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

void c19_FSAC2021_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c19_FSAC2021(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c19_FSAC2021(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c19_FSAC2021(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c19_FSAC2021_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
