/* Include files */

#include <stddef.h>
#include "blas.h"
#include "FSAC2021_826_sfun.h"
#include "c11_FSAC2021_826.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "FSAC2021_826_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c11_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c11_IN_Normal                  ((uint8_T)1U)
#define c11_IN_ON                      ((uint8_T)2U)
#define c11_IN_Off                     ((uint8_T)3U)
#define c11_IN_On                      ((uint8_T)4U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c11_debug_family_names[2] = { "nargin", "nargout" };

static const char * c11_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c11_c_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_d_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_e_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_f_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_g_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_h_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_i_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c11_j_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c11_dataWrittenToVector[1];

/* Function Declarations */
static void initialize_c11_FSAC2021_826(SFc11_FSAC2021_826InstanceStruct
  *chartInstance);
static void initialize_params_c11_FSAC2021_826(SFc11_FSAC2021_826InstanceStruct *
  chartInstance);
static void enable_c11_FSAC2021_826(SFc11_FSAC2021_826InstanceStruct
  *chartInstance);
static void disable_c11_FSAC2021_826(SFc11_FSAC2021_826InstanceStruct
  *chartInstance);
static void c11_update_debugger_state_c11_FSAC2021_826
  (SFc11_FSAC2021_826InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c11_FSAC2021_826
  (SFc11_FSAC2021_826InstanceStruct *chartInstance);
static void set_sim_state_c11_FSAC2021_826(SFc11_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c11_st);
static void c11_set_sim_state_side_effects_c11_FSAC2021_826
  (SFc11_FSAC2021_826InstanceStruct *chartInstance);
static void finalize_c11_FSAC2021_826(SFc11_FSAC2021_826InstanceStruct
  *chartInstance);
static void sf_gateway_c11_FSAC2021_826(SFc11_FSAC2021_826InstanceStruct
  *chartInstance);
static void c11_chartstep_c11_FSAC2021_826(SFc11_FSAC2021_826InstanceStruct
  *chartInstance);
static void initSimStructsc11_FSAC2021_826(SFc11_FSAC2021_826InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber, uint32_T c11_instanceNumber);
static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static real_T c11_emlrt_marshallIn(SFc11_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static boolean_T c11_b_emlrt_marshallIn(SFc11_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static int32_T c11_c_emlrt_marshallIn(SFc11_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static uint8_T c11_d_emlrt_marshallIn(SFc11_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c11_b_tp_Normal, const char_T *c11_identifier);
static uint8_T c11_e_emlrt_marshallIn(SFc11_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static uint32_T c11_f_emlrt_marshallIn(SFc11_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c11_b_previousTicks, const char_T
  *c11_identifier);
static uint32_T c11_g_emlrt_marshallIn(SFc11_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static const mxArray *c11_h_emlrt_marshallIn(SFc11_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c11_b_setSimStateSideEffectsInfo, const char_T *
  c11_identifier);
static const mxArray *c11_i_emlrt_marshallIn(SFc11_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_updateDataWrittenToVector(SFc11_FSAC2021_826InstanceStruct
  *chartInstance, uint32_T c11_vectorIndex);
static void init_dsm_address_info(SFc11_FSAC2021_826InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c11_FSAC2021_826(SFc11_FSAC2021_826InstanceStruct
  *chartInstance)
{
  chartInstance->c11_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c11_doSetSimStateSideEffects = 0U;
  chartInstance->c11_setSimStateSideEffectsInfo = NULL;
  chartInstance->c11_tp_Normal = 0U;
  chartInstance->c11_tp_ON = 0U;
  chartInstance->c11_temporalCounter_i1 = 0U;
  chartInstance->c11_tp_Off = 0U;
  chartInstance->c11_tp_On = 0U;
  chartInstance->c11_is_active_c11_FSAC2021_826 = 0U;
  chartInstance->c11_is_c11_FSAC2021_826 = c11_IN_NO_ACTIVE_CHILD;
  chartInstance->c11_presentTicks = 0U;
  chartInstance->c11_elapsedTicks = 0U;
  chartInstance->c11_previousTicks = 0U;
}

static void initialize_params_c11_FSAC2021_826(SFc11_FSAC2021_826InstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c11_FSAC2021_826(SFc11_FSAC2021_826InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c11_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.1
    + 0.5);
  chartInstance->c11_previousTicks = chartInstance->c11_presentTicks;
}

static void disable_c11_FSAC2021_826(SFc11_FSAC2021_826InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c11_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.1
    + 0.5);
  chartInstance->c11_elapsedTicks = chartInstance->c11_presentTicks -
    chartInstance->c11_previousTicks;
  chartInstance->c11_previousTicks = chartInstance->c11_presentTicks;
  if ((uint32_T)chartInstance->c11_temporalCounter_i1 +
      chartInstance->c11_elapsedTicks <= 31U) {
    chartInstance->c11_temporalCounter_i1 = (uint8_T)((uint32_T)
      chartInstance->c11_temporalCounter_i1 + chartInstance->c11_elapsedTicks);
  } else {
    chartInstance->c11_temporalCounter_i1 = 31U;
  }
}

static void c11_update_debugger_state_c11_FSAC2021_826
  (SFc11_FSAC2021_826InstanceStruct *chartInstance)
{
  uint32_T c11_prevAniVal;
  c11_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c11_is_active_c11_FSAC2021_826 == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 9U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_c11_FSAC2021_826 == c11_IN_Normal) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_c11_FSAC2021_826 == c11_IN_Off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_c11_FSAC2021_826 == c11_IN_ON) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
  }

  if (chartInstance->c11_is_c11_FSAC2021_826 == c11_IN_On) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
  }

  _SFD_SET_ANIMATION(c11_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c11_FSAC2021_826
  (SFc11_FSAC2021_826InstanceStruct *chartInstance)
{
  const mxArray *c11_st;
  const mxArray *c11_y = NULL;
  uint8_T c11_hoistedGlobal;
  uint8_T c11_u;
  const mxArray *c11_b_y = NULL;
  uint8_T c11_b_hoistedGlobal;
  uint8_T c11_b_u;
  const mxArray *c11_c_y = NULL;
  uint8_T c11_c_hoistedGlobal;
  uint8_T c11_c_u;
  const mxArray *c11_d_y = NULL;
  uint8_T c11_d_hoistedGlobal;
  uint8_T c11_d_u;
  const mxArray *c11_e_y = NULL;
  uint32_T c11_e_hoistedGlobal;
  uint32_T c11_e_u;
  const mxArray *c11_f_y = NULL;
  uint8_T *c11_Output;
  c11_Output = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c11_st = NULL;
  c11_st = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_createcellmatrix(5, 1), false);
  c11_hoistedGlobal = *c11_Output;
  c11_u = c11_hoistedGlobal;
  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 0, c11_b_y);
  c11_b_hoistedGlobal = chartInstance->c11_is_active_c11_FSAC2021_826;
  c11_b_u = c11_b_hoistedGlobal;
  c11_c_y = NULL;
  sf_mex_assign(&c11_c_y, sf_mex_create("y", &c11_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 1, c11_c_y);
  c11_c_hoistedGlobal = chartInstance->c11_is_c11_FSAC2021_826;
  c11_c_u = c11_c_hoistedGlobal;
  c11_d_y = NULL;
  sf_mex_assign(&c11_d_y, sf_mex_create("y", &c11_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 2, c11_d_y);
  c11_d_hoistedGlobal = chartInstance->c11_temporalCounter_i1;
  c11_d_u = c11_d_hoistedGlobal;
  c11_e_y = NULL;
  sf_mex_assign(&c11_e_y, sf_mex_create("y", &c11_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 3, c11_e_y);
  c11_e_hoistedGlobal = chartInstance->c11_previousTicks;
  c11_e_u = c11_e_hoistedGlobal;
  c11_f_y = NULL;
  sf_mex_assign(&c11_f_y, sf_mex_create("y", &c11_e_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 4, c11_f_y);
  sf_mex_assign(&c11_st, c11_y, false);
  return c11_st;
}

static void set_sim_state_c11_FSAC2021_826(SFc11_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c11_st)
{
  const mxArray *c11_u;
  uint8_T *c11_Output;
  c11_Output = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c11_u = sf_mex_dup(c11_st);
  *c11_Output = c11_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c11_u, 0)), "Output");
  chartInstance->c11_is_active_c11_FSAC2021_826 = c11_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 1)),
     "is_active_c11_FSAC2021_826");
  chartInstance->c11_is_c11_FSAC2021_826 = c11_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c11_u, 2)), "is_c11_FSAC2021_826");
  chartInstance->c11_temporalCounter_i1 = c11_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c11_u, 3)), "temporalCounter_i1");
  chartInstance->c11_previousTicks = c11_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c11_u, 4)), "previousTicks");
  sf_mex_assign(&chartInstance->c11_setSimStateSideEffectsInfo,
                c11_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c11_u, 5)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c11_u);
  chartInstance->c11_doSetSimStateSideEffects = 1U;
  c11_update_debugger_state_c11_FSAC2021_826(chartInstance);
  sf_mex_destroy(&c11_st);
}

static void c11_set_sim_state_side_effects_c11_FSAC2021_826
  (SFc11_FSAC2021_826InstanceStruct *chartInstance)
{
  if (chartInstance->c11_doSetSimStateSideEffects != 0) {
    if (chartInstance->c11_is_c11_FSAC2021_826 == c11_IN_Normal) {
      chartInstance->c11_tp_Normal = 1U;
    } else {
      chartInstance->c11_tp_Normal = 0U;
    }

    if (chartInstance->c11_is_c11_FSAC2021_826 == c11_IN_ON) {
      chartInstance->c11_tp_ON = 1U;
      if (sf_mex_sub(chartInstance->c11_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 3) == 0.0) {
        chartInstance->c11_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c11_tp_ON = 0U;
    }

    if (chartInstance->c11_is_c11_FSAC2021_826 == c11_IN_Off) {
      chartInstance->c11_tp_Off = 1U;
    } else {
      chartInstance->c11_tp_Off = 0U;
    }

    if (chartInstance->c11_is_c11_FSAC2021_826 == c11_IN_On) {
      chartInstance->c11_tp_On = 1U;
    } else {
      chartInstance->c11_tp_On = 0U;
    }

    chartInstance->c11_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c11_FSAC2021_826(SFc11_FSAC2021_826InstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c11_setSimStateSideEffectsInfo);
}

static void sf_gateway_c11_FSAC2021_826(SFc11_FSAC2021_826InstanceStruct
  *chartInstance)
{
  uint8_T *c11_Input;
  uint8_T *c11_Output;
  c11_Output = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c11_Input = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c11_set_sim_state_side_effects_c11_FSAC2021_826(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c11_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.1
    + 0.5);
  chartInstance->c11_elapsedTicks = chartInstance->c11_presentTicks -
    chartInstance->c11_previousTicks;
  chartInstance->c11_previousTicks = chartInstance->c11_presentTicks;
  if ((uint32_T)chartInstance->c11_temporalCounter_i1 +
      chartInstance->c11_elapsedTicks <= 31U) {
    chartInstance->c11_temporalCounter_i1 = (uint8_T)((uint32_T)
      chartInstance->c11_temporalCounter_i1 + chartInstance->c11_elapsedTicks);
  } else {
    chartInstance->c11_temporalCounter_i1 = 31U;
  }

  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 9U, chartInstance->c11_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*c11_Input, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)*c11_Output, 1U);
  chartInstance->c11_sfEvent = CALL_EVENT;
  c11_chartstep_c11_FSAC2021_826(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_FSAC2021_826MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c11_chartstep_c11_FSAC2021_826(SFc11_FSAC2021_826InstanceStruct
  *chartInstance)
{
  uint32_T c11_debug_family_var_map[2];
  real_T c11_nargin = 0.0;
  real_T c11_nargout = 0.0;
  uint32_T c11_b_debug_family_var_map[3];
  real_T c11_b_nargin = 0.0;
  real_T c11_b_nargout = 1.0;
  boolean_T c11_out;
  real_T c11_c_nargin = 0.0;
  real_T c11_c_nargout = 1.0;
  boolean_T c11_b_out;
  real_T c11_d_nargin = 0.0;
  real_T c11_d_nargout = 1.0;
  boolean_T c11_c_out;
  real_T c11_e_nargin = 0.0;
  real_T c11_e_nargout = 0.0;
  real_T c11_f_nargin = 0.0;
  real_T c11_f_nargout = 1.0;
  boolean_T c11_d_out;
  uint8_T *c11_Input;
  uint8_T *c11_Output;
  c11_Output = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c11_Input = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c11_sfEvent);
  if (chartInstance->c11_is_active_c11_FSAC2021_826 == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 9U, chartInstance->c11_sfEvent);
    chartInstance->c11_is_active_c11_FSAC2021_826 = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c11_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c11_sfEvent);
    chartInstance->c11_is_c11_FSAC2021_826 = c11_IN_Normal;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
    chartInstance->c11_tp_Normal = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c11_debug_family_names,
      c11_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 0U, c11_sf_marshallOut,
      c11_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 1U, c11_sf_marshallOut,
      c11_sf_marshallIn);
    *c11_Output = 1U;
    c11_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK((real_T)*c11_Output, 1U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    switch (chartInstance->c11_is_c11_FSAC2021_826) {
     case c11_IN_Normal:
      CV_CHART_EVAL(9, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U,
                   chartInstance->c11_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_c_debug_family_names,
        c11_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_nargin, 0U, c11_sf_marshallOut,
        c11_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_nargout, 1U,
        c11_sf_marshallOut, c11_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_out, 2U, c11_b_sf_marshallOut,
        c11_b_sf_marshallIn);
      c11_out = CV_EML_IF(0, 0, 0, (real_T)*c11_Input == 0.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c11_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
        chartInstance->c11_tp_Normal = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
        chartInstance->c11_is_c11_FSAC2021_826 = c11_IN_ON;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
        chartInstance->c11_temporalCounter_i1 = 0U;
        chartInstance->c11_tp_ON = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                     chartInstance->c11_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c11_sfEvent);
      break;

     case c11_IN_ON:
      CV_CHART_EVAL(9, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c11_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_d_debug_family_names,
        c11_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_c_nargin, 0U, c11_sf_marshallOut,
        c11_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_c_nargout, 1U,
        c11_sf_marshallOut, c11_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_out, 2U, c11_b_sf_marshallOut,
        c11_b_sf_marshallIn);
      c11_b_out = CV_EML_IF(1, 0, 0, *c11_Input == 1);
      _SFD_SYMBOL_SCOPE_POP();
      if (c11_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
        chartInstance->c11_tp_ON = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
        chartInstance->c11_is_c11_FSAC2021_826 = c11_IN_Off;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c11_sfEvent);
        chartInstance->c11_tp_Off = 1U;
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                     chartInstance->c11_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_f_debug_family_names,
          c11_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_d_nargin, 0U,
          c11_sf_marshallOut, c11_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_d_nargout, 1U,
          c11_sf_marshallOut, c11_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_c_out, 2U,
          c11_b_sf_marshallOut, c11_b_sf_marshallIn);
        c11_c_out = CV_EML_IF(3, 0, 0, chartInstance->c11_temporalCounter_i1 >=
                              20);
        _SFD_SYMBOL_SCOPE_POP();
        if (c11_c_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
          chartInstance->c11_tp_ON = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
          chartInstance->c11_is_c11_FSAC2021_826 = c11_IN_On;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c11_sfEvent);
          chartInstance->c11_tp_On = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c11_b_debug_family_names,
            c11_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_e_nargin, 0U,
            c11_sf_marshallOut, c11_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_e_nargout, 1U,
            c11_sf_marshallOut, c11_sf_marshallIn);
          *c11_Output = 0U;
          c11_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_DATA_RANGE_CHECK((real_T)*c11_Output, 1U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                       chartInstance->c11_sfEvent);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c11_sfEvent);
      break;

     case c11_IN_Off:
      CV_CHART_EVAL(9, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                   chartInstance->c11_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c11_e_debug_family_names,
        c11_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_f_nargin, 0U, c11_sf_marshallOut,
        c11_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_f_nargout, 1U,
        c11_sf_marshallOut, c11_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_d_out, 2U, c11_b_sf_marshallOut,
        c11_b_sf_marshallIn);
      c11_d_out = CV_EML_IF(2, 0, 0, *c11_Input == 0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c11_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c11_sfEvent);
        chartInstance->c11_tp_Off = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c11_sfEvent);
        chartInstance->c11_is_c11_FSAC2021_826 = c11_IN_ON;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c11_sfEvent);
        chartInstance->c11_temporalCounter_i1 = 0U;
        chartInstance->c11_tp_ON = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                     chartInstance->c11_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c11_sfEvent);
      break;

     case c11_IN_On:
      CV_CHART_EVAL(9, 0, 4);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                   chartInstance->c11_sfEvent);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c11_sfEvent);
      break;

     default:
      CV_CHART_EVAL(9, 0, 0);
      chartInstance->c11_is_c11_FSAC2021_826 = c11_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c11_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c11_sfEvent);
}

static void initSimStructsc11_FSAC2021_826(SFc11_FSAC2021_826InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber, uint32_T c11_instanceNumber)
{
  (void)c11_machineNumber;
  (void)c11_chartNumber;
  (void)c11_instanceNumber;
}

static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  real_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_FSAC2021_826InstanceStruct *chartInstance;
  chartInstance = (SFc11_FSAC2021_826InstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(real_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static real_T c11_emlrt_marshallIn(SFc11_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  real_T c11_y;
  real_T c11_d0;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_d0, 1, 0, 0U, 0, 0U, 0);
  c11_y = c11_d0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_nargout;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y;
  SFc11_FSAC2021_826InstanceStruct *chartInstance;
  chartInstance = (SFc11_FSAC2021_826InstanceStruct *)chartInstanceVoid;
  c11_nargout = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_nargout),
    &c11_thisId);
  sf_mex_destroy(&c11_nargout);
  *(real_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  boolean_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_FSAC2021_826InstanceStruct *chartInstance;
  chartInstance = (SFc11_FSAC2021_826InstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(boolean_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static boolean_T c11_b_emlrt_marshallIn(SFc11_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  boolean_T c11_y;
  boolean_T c11_b0;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_b0, 1, 11, 0U, 0, 0U, 0);
  c11_y = c11_b0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_sf_internal_predicateOutput;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  boolean_T c11_y;
  SFc11_FSAC2021_826InstanceStruct *chartInstance;
  chartInstance = (SFc11_FSAC2021_826InstanceStruct *)chartInstanceVoid;
  c11_sf_internal_predicateOutput = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_sf_internal_predicateOutput), &c11_thisId);
  sf_mex_destroy(&c11_sf_internal_predicateOutput);
  *(boolean_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

const mxArray *sf_c11_FSAC2021_826_get_eml_resolved_functions_info(void)
{
  const mxArray *c11_nameCaptureInfo = NULL;
  c11_nameCaptureInfo = NULL;
  sf_mex_assign(&c11_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c11_nameCaptureInfo;
}

static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_FSAC2021_826InstanceStruct *chartInstance;
  chartInstance = (SFc11_FSAC2021_826InstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(int32_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static int32_T c11_c_emlrt_marshallIn(SFc11_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  int32_T c11_y;
  int32_T c11_i0;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_i0, 1, 6, 0U, 0, 0U, 0);
  c11_y = c11_i0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_sfEvent;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  int32_T c11_y;
  SFc11_FSAC2021_826InstanceStruct *chartInstance;
  chartInstance = (SFc11_FSAC2021_826InstanceStruct *)chartInstanceVoid;
  c11_b_sfEvent = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_sfEvent),
    &c11_thisId);
  sf_mex_destroy(&c11_b_sfEvent);
  *(int32_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  uint8_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_FSAC2021_826InstanceStruct *chartInstance;
  chartInstance = (SFc11_FSAC2021_826InstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(uint8_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static uint8_T c11_d_emlrt_marshallIn(SFc11_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c11_b_tp_Normal, const char_T *c11_identifier)
{
  uint8_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_tp_Normal),
    &c11_thisId);
  sf_mex_destroy(&c11_b_tp_Normal);
  return c11_y;
}

static uint8_T c11_e_emlrt_marshallIn(SFc11_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  uint8_T c11_y;
  uint8_T c11_u0;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_u0, 1, 3, 0U, 0, 0U, 0);
  c11_y = c11_u0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_tp_Normal;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  uint8_T c11_y;
  SFc11_FSAC2021_826InstanceStruct *chartInstance;
  chartInstance = (SFc11_FSAC2021_826InstanceStruct *)chartInstanceVoid;
  c11_b_tp_Normal = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_tp_Normal),
    &c11_thisId);
  sf_mex_destroy(&c11_b_tp_Normal);
  *(uint8_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static uint32_T c11_f_emlrt_marshallIn(SFc11_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c11_b_previousTicks, const char_T
  *c11_identifier)
{
  uint32_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_previousTicks),
    &c11_thisId);
  sf_mex_destroy(&c11_b_previousTicks);
  return c11_y;
}

static uint32_T c11_g_emlrt_marshallIn(SFc11_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  uint32_T c11_y;
  uint32_T c11_u1;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_u1, 1, 7, 0U, 0, 0U, 0);
  c11_y = c11_u1;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static const mxArray *c11_h_emlrt_marshallIn(SFc11_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c11_b_setSimStateSideEffectsInfo, const char_T *
  c11_identifier)
{
  const mxArray *c11_y = NULL;
  emlrtMsgIdentifier c11_thisId;
  c11_y = NULL;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  sf_mex_assign(&c11_y, c11_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_b_setSimStateSideEffectsInfo), &c11_thisId), false);
  sf_mex_destroy(&c11_b_setSimStateSideEffectsInfo);
  return c11_y;
}

static const mxArray *c11_i_emlrt_marshallIn(SFc11_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  const mxArray *c11_y = NULL;
  (void)chartInstance;
  (void)c11_parentId;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_duplicatearraysafe(&c11_u), false);
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_updateDataWrittenToVector(SFc11_FSAC2021_826InstanceStruct
  *chartInstance, uint32_T c11_vectorIndex)
{
  (void)chartInstance;
  c11_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c11_vectorIndex, 0, 0, 1, 0)] = true;
}

static void init_dsm_address_info(SFc11_FSAC2021_826InstanceStruct
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

void sf_c11_FSAC2021_826_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3993920617U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1940535110U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3179758537U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1550378918U);
}

mxArray *sf_c11_FSAC2021_826_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("1ReNGHeUGL9IdCn9rC8caC");
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

mxArray *sf_c11_FSAC2021_826_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c11_FSAC2021_826_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c11_FSAC2021_826(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[24],T\"Output\",},{M[8],M[0],T\"is_active_c11_FSAC2021_826\",},{M[9],M[0],T\"is_c11_FSAC2021_826\",},{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"at\",M[14],M[1]}}},{M[13],M[0],T\"previousTicks\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c11_FSAC2021_826_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc11_FSAC2021_826InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc11_FSAC2021_826InstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _FSAC2021_826MachineNumber_,
           11,
           4,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"Input");
          _SFD_SET_DATA_PROPS(1,2,0,1,"Output");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_CH_SUBSTATE_COUNT(4);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,2);
          _SFD_CH_SUBSTATE_INDEX(3,3);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
        }

        _SFD_CV_INIT_CHART(4,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(0,0,0,1,11,1,11);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,18,1,18);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,1,18,1,18);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,0,12,0,12);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_d_sf_marshallOut,(MexInFcnForType)
          c11_d_sf_marshallIn);

        {
          uint8_T *c11_Input;
          uint8_T *c11_Output;
          c11_Output = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c11_Input = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c11_Input);
          _SFD_SET_DATA_VALUE_PTR(1U, c11_Output);
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
  return "5TaKXVZMXHAVXfL3a1vRTG";
}

static void sf_opaque_initialize_c11_FSAC2021_826(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc11_FSAC2021_826InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c11_FSAC2021_826((SFc11_FSAC2021_826InstanceStruct*)
    chartInstanceVar);
  initialize_c11_FSAC2021_826((SFc11_FSAC2021_826InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c11_FSAC2021_826(void *chartInstanceVar)
{
  enable_c11_FSAC2021_826((SFc11_FSAC2021_826InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c11_FSAC2021_826(void *chartInstanceVar)
{
  disable_c11_FSAC2021_826((SFc11_FSAC2021_826InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c11_FSAC2021_826(void *chartInstanceVar)
{
  sf_gateway_c11_FSAC2021_826((SFc11_FSAC2021_826InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c11_FSAC2021_826(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c11_FSAC2021_826
    ((SFc11_FSAC2021_826InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c11_FSAC2021_826();/* state var info */
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

extern void sf_internal_set_sim_state_c11_FSAC2021_826(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c11_FSAC2021_826();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c11_FSAC2021_826((SFc11_FSAC2021_826InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c11_FSAC2021_826(SimStruct* S)
{
  return sf_internal_get_sim_state_c11_FSAC2021_826(S);
}

static void sf_opaque_set_sim_state_c11_FSAC2021_826(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c11_FSAC2021_826(S, st);
}

static void sf_opaque_terminate_c11_FSAC2021_826(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc11_FSAC2021_826InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_FSAC2021_826_optimization_info();
    }

    finalize_c11_FSAC2021_826((SFc11_FSAC2021_826InstanceStruct*)
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
  initSimStructsc11_FSAC2021_826((SFc11_FSAC2021_826InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c11_FSAC2021_826(SimStruct *S)
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
    initialize_params_c11_FSAC2021_826((SFc11_FSAC2021_826InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c11_FSAC2021_826(SimStruct *S)
{
  ssSetNeedAbsoluteTime(S,1);
  ssSetModelReferenceSampleTimeDisallowInheritance(S);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_FSAC2021_826_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      11);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,11,"RTWCG"));
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,11,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,11);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,11,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,11,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,11);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1013809829U));
  ssSetChecksum1(S,(299400360U));
  ssSetChecksum2(S,(425601745U));
  ssSetChecksum3(S,(2907167312U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c11_FSAC2021_826(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c11_FSAC2021_826(SimStruct *S)
{
  SFc11_FSAC2021_826InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc11_FSAC2021_826InstanceStruct *)utMalloc(sizeof
    (SFc11_FSAC2021_826InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc11_FSAC2021_826InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c11_FSAC2021_826;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c11_FSAC2021_826;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c11_FSAC2021_826;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c11_FSAC2021_826;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c11_FSAC2021_826;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c11_FSAC2021_826;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c11_FSAC2021_826;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c11_FSAC2021_826;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c11_FSAC2021_826;
  chartInstance->chartInfo.mdlStart = mdlStart_c11_FSAC2021_826;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c11_FSAC2021_826;
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

void c11_FSAC2021_826_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c11_FSAC2021_826(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c11_FSAC2021_826(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c11_FSAC2021_826(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c11_FSAC2021_826_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
