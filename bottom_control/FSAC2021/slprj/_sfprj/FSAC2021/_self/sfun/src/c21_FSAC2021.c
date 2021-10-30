/* Include files */

#include <stddef.h>
#include "blas.h"
#include "FSAC2021_sfun.h"
#include "c21_FSAC2021.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "FSAC2021_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c21_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c21_IN_Normal                  ((uint8_T)1U)
#define c21_IN_ON                      ((uint8_T)2U)
#define c21_IN_Off                     ((uint8_T)3U)
#define c21_IN_On                      ((uint8_T)4U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c21_debug_family_names[2] = { "nargin", "nargout" };

static const char * c21_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c21_c_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c21_d_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c21_e_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c21_f_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c21_g_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c21_h_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c21_i_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c21_j_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c21_dataWrittenToVector[1];

/* Function Declarations */
static void initialize_c21_FSAC2021(SFc21_FSAC2021InstanceStruct *chartInstance);
static void initialize_params_c21_FSAC2021(SFc21_FSAC2021InstanceStruct
  *chartInstance);
static void enable_c21_FSAC2021(SFc21_FSAC2021InstanceStruct *chartInstance);
static void disable_c21_FSAC2021(SFc21_FSAC2021InstanceStruct *chartInstance);
static void c21_update_debugger_state_c21_FSAC2021(SFc21_FSAC2021InstanceStruct *
  chartInstance);
static const mxArray *get_sim_state_c21_FSAC2021(SFc21_FSAC2021InstanceStruct
  *chartInstance);
static void set_sim_state_c21_FSAC2021(SFc21_FSAC2021InstanceStruct
  *chartInstance, const mxArray *c21_st);
static void c21_set_sim_state_side_effects_c21_FSAC2021
  (SFc21_FSAC2021InstanceStruct *chartInstance);
static void finalize_c21_FSAC2021(SFc21_FSAC2021InstanceStruct *chartInstance);
static void sf_gateway_c21_FSAC2021(SFc21_FSAC2021InstanceStruct *chartInstance);
static void c21_chartstep_c21_FSAC2021(SFc21_FSAC2021InstanceStruct
  *chartInstance);
static void initSimStructsc21_FSAC2021(SFc21_FSAC2021InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c21_machineNumber, uint32_T
  c21_chartNumber, uint32_T c21_instanceNumber);
static const mxArray *c21_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData);
static real_T c21_emlrt_marshallIn(SFc21_FSAC2021InstanceStruct *chartInstance,
  const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId);
static void c21_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData);
static const mxArray *c21_b_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData);
static boolean_T c21_b_emlrt_marshallIn(SFc21_FSAC2021InstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId);
static void c21_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData);
static const mxArray *c21_c_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData);
static int32_T c21_c_emlrt_marshallIn(SFc21_FSAC2021InstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId);
static void c21_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData);
static const mxArray *c21_d_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData);
static uint8_T c21_d_emlrt_marshallIn(SFc21_FSAC2021InstanceStruct
  *chartInstance, const mxArray *c21_b_tp_Normal, const char_T *c21_identifier);
static uint8_T c21_e_emlrt_marshallIn(SFc21_FSAC2021InstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId);
static void c21_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData);
static uint32_T c21_f_emlrt_marshallIn(SFc21_FSAC2021InstanceStruct
  *chartInstance, const mxArray *c21_b_previousTicks, const char_T
  *c21_identifier);
static uint32_T c21_g_emlrt_marshallIn(SFc21_FSAC2021InstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId);
static const mxArray *c21_h_emlrt_marshallIn(SFc21_FSAC2021InstanceStruct
  *chartInstance, const mxArray *c21_b_setSimStateSideEffectsInfo, const char_T *
  c21_identifier);
static const mxArray *c21_i_emlrt_marshallIn(SFc21_FSAC2021InstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId);
static void c21_updateDataWrittenToVector(SFc21_FSAC2021InstanceStruct
  *chartInstance, uint32_T c21_vectorIndex);
static void init_dsm_address_info(SFc21_FSAC2021InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c21_FSAC2021(SFc21_FSAC2021InstanceStruct *chartInstance)
{
  chartInstance->c21_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c21_doSetSimStateSideEffects = 0U;
  chartInstance->c21_setSimStateSideEffectsInfo = NULL;
  chartInstance->c21_tp_Normal = 0U;
  chartInstance->c21_tp_ON = 0U;
  chartInstance->c21_temporalCounter_i1 = 0U;
  chartInstance->c21_tp_Off = 0U;
  chartInstance->c21_tp_On = 0U;
  chartInstance->c21_is_active_c21_FSAC2021 = 0U;
  chartInstance->c21_is_c21_FSAC2021 = c21_IN_NO_ACTIVE_CHILD;
  chartInstance->c21_presentTicks = 0U;
  chartInstance->c21_elapsedTicks = 0U;
  chartInstance->c21_previousTicks = 0U;
}

static void initialize_params_c21_FSAC2021(SFc21_FSAC2021InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c21_FSAC2021(SFc21_FSAC2021InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c21_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.1
    + 0.5);
  chartInstance->c21_previousTicks = chartInstance->c21_presentTicks;
}

static void disable_c21_FSAC2021(SFc21_FSAC2021InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c21_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.1
    + 0.5);
  chartInstance->c21_elapsedTicks = chartInstance->c21_presentTicks -
    chartInstance->c21_previousTicks;
  chartInstance->c21_previousTicks = chartInstance->c21_presentTicks;
  if ((uint32_T)chartInstance->c21_temporalCounter_i1 +
      chartInstance->c21_elapsedTicks <= 31U) {
    chartInstance->c21_temporalCounter_i1 = (uint8_T)((uint32_T)
      chartInstance->c21_temporalCounter_i1 + chartInstance->c21_elapsedTicks);
  } else {
    chartInstance->c21_temporalCounter_i1 = 31U;
  }
}

static void c21_update_debugger_state_c21_FSAC2021(SFc21_FSAC2021InstanceStruct *
  chartInstance)
{
  uint32_T c21_prevAniVal;
  c21_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c21_is_active_c21_FSAC2021 == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 19U, chartInstance->c21_sfEvent);
  }

  if (chartInstance->c21_is_c21_FSAC2021 == c21_IN_Normal) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c21_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c21_sfEvent);
  }

  if (chartInstance->c21_is_c21_FSAC2021 == c21_IN_Off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c21_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c21_sfEvent);
  }

  if (chartInstance->c21_is_c21_FSAC2021 == c21_IN_ON) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c21_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c21_sfEvent);
  }

  if (chartInstance->c21_is_c21_FSAC2021 == c21_IN_On) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c21_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c21_sfEvent);
  }

  _SFD_SET_ANIMATION(c21_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c21_FSAC2021(SFc21_FSAC2021InstanceStruct
  *chartInstance)
{
  const mxArray *c21_st;
  const mxArray *c21_y = NULL;
  uint8_T c21_hoistedGlobal;
  uint8_T c21_u;
  const mxArray *c21_b_y = NULL;
  uint8_T c21_b_hoistedGlobal;
  uint8_T c21_b_u;
  const mxArray *c21_c_y = NULL;
  uint8_T c21_c_hoistedGlobal;
  uint8_T c21_c_u;
  const mxArray *c21_d_y = NULL;
  uint8_T c21_d_hoistedGlobal;
  uint8_T c21_d_u;
  const mxArray *c21_e_y = NULL;
  uint32_T c21_e_hoistedGlobal;
  uint32_T c21_e_u;
  const mxArray *c21_f_y = NULL;
  uint8_T *c21_Output;
  c21_Output = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c21_st = NULL;
  c21_st = NULL;
  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_createcellmatrix(5, 1), false);
  c21_hoistedGlobal = *c21_Output;
  c21_u = c21_hoistedGlobal;
  c21_b_y = NULL;
  sf_mex_assign(&c21_b_y, sf_mex_create("y", &c21_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c21_y, 0, c21_b_y);
  c21_b_hoistedGlobal = chartInstance->c21_is_active_c21_FSAC2021;
  c21_b_u = c21_b_hoistedGlobal;
  c21_c_y = NULL;
  sf_mex_assign(&c21_c_y, sf_mex_create("y", &c21_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c21_y, 1, c21_c_y);
  c21_c_hoistedGlobal = chartInstance->c21_is_c21_FSAC2021;
  c21_c_u = c21_c_hoistedGlobal;
  c21_d_y = NULL;
  sf_mex_assign(&c21_d_y, sf_mex_create("y", &c21_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c21_y, 2, c21_d_y);
  c21_d_hoistedGlobal = chartInstance->c21_temporalCounter_i1;
  c21_d_u = c21_d_hoistedGlobal;
  c21_e_y = NULL;
  sf_mex_assign(&c21_e_y, sf_mex_create("y", &c21_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c21_y, 3, c21_e_y);
  c21_e_hoistedGlobal = chartInstance->c21_previousTicks;
  c21_e_u = c21_e_hoistedGlobal;
  c21_f_y = NULL;
  sf_mex_assign(&c21_f_y, sf_mex_create("y", &c21_e_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c21_y, 4, c21_f_y);
  sf_mex_assign(&c21_st, c21_y, false);
  return c21_st;
}

static void set_sim_state_c21_FSAC2021(SFc21_FSAC2021InstanceStruct
  *chartInstance, const mxArray *c21_st)
{
  const mxArray *c21_u;
  uint8_T *c21_Output;
  c21_Output = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c21_u = sf_mex_dup(c21_st);
  *c21_Output = c21_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c21_u, 0)), "Output");
  chartInstance->c21_is_active_c21_FSAC2021 = c21_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c21_u, 1)),
     "is_active_c21_FSAC2021");
  chartInstance->c21_is_c21_FSAC2021 = c21_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c21_u, 2)), "is_c21_FSAC2021");
  chartInstance->c21_temporalCounter_i1 = c21_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c21_u, 3)), "temporalCounter_i1");
  chartInstance->c21_previousTicks = c21_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c21_u, 4)), "previousTicks");
  sf_mex_assign(&chartInstance->c21_setSimStateSideEffectsInfo,
                c21_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c21_u, 5)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c21_u);
  chartInstance->c21_doSetSimStateSideEffects = 1U;
  c21_update_debugger_state_c21_FSAC2021(chartInstance);
  sf_mex_destroy(&c21_st);
}

static void c21_set_sim_state_side_effects_c21_FSAC2021
  (SFc21_FSAC2021InstanceStruct *chartInstance)
{
  if (chartInstance->c21_doSetSimStateSideEffects != 0) {
    if (chartInstance->c21_is_c21_FSAC2021 == c21_IN_Normal) {
      chartInstance->c21_tp_Normal = 1U;
    } else {
      chartInstance->c21_tp_Normal = 0U;
    }

    if (chartInstance->c21_is_c21_FSAC2021 == c21_IN_ON) {
      chartInstance->c21_tp_ON = 1U;
      if (sf_mex_sub(chartInstance->c21_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 3) == 0.0) {
        chartInstance->c21_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c21_tp_ON = 0U;
    }

    if (chartInstance->c21_is_c21_FSAC2021 == c21_IN_Off) {
      chartInstance->c21_tp_Off = 1U;
    } else {
      chartInstance->c21_tp_Off = 0U;
    }

    if (chartInstance->c21_is_c21_FSAC2021 == c21_IN_On) {
      chartInstance->c21_tp_On = 1U;
    } else {
      chartInstance->c21_tp_On = 0U;
    }

    chartInstance->c21_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c21_FSAC2021(SFc21_FSAC2021InstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c21_setSimStateSideEffectsInfo);
}

static void sf_gateway_c21_FSAC2021(SFc21_FSAC2021InstanceStruct *chartInstance)
{
  uint8_T *c21_Input;
  uint8_T *c21_Output;
  c21_Output = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c21_Input = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c21_set_sim_state_side_effects_c21_FSAC2021(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c21_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.1
    + 0.5);
  chartInstance->c21_elapsedTicks = chartInstance->c21_presentTicks -
    chartInstance->c21_previousTicks;
  chartInstance->c21_previousTicks = chartInstance->c21_presentTicks;
  if ((uint32_T)chartInstance->c21_temporalCounter_i1 +
      chartInstance->c21_elapsedTicks <= 31U) {
    chartInstance->c21_temporalCounter_i1 = (uint8_T)((uint32_T)
      chartInstance->c21_temporalCounter_i1 + chartInstance->c21_elapsedTicks);
  } else {
    chartInstance->c21_temporalCounter_i1 = 31U;
  }

  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 19U, chartInstance->c21_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*c21_Input, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)*c21_Output, 1U);
  chartInstance->c21_sfEvent = CALL_EVENT;
  c21_chartstep_c21_FSAC2021(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_FSAC2021MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c21_chartstep_c21_FSAC2021(SFc21_FSAC2021InstanceStruct
  *chartInstance)
{
  uint32_T c21_debug_family_var_map[2];
  real_T c21_nargin = 0.0;
  real_T c21_nargout = 0.0;
  uint32_T c21_b_debug_family_var_map[3];
  real_T c21_b_nargin = 0.0;
  real_T c21_b_nargout = 1.0;
  boolean_T c21_out;
  real_T c21_c_nargin = 0.0;
  real_T c21_c_nargout = 1.0;
  boolean_T c21_b_out;
  real_T c21_d_nargin = 0.0;
  real_T c21_d_nargout = 1.0;
  boolean_T c21_c_out;
  real_T c21_e_nargin = 0.0;
  real_T c21_e_nargout = 0.0;
  real_T c21_f_nargin = 0.0;
  real_T c21_f_nargout = 1.0;
  boolean_T c21_d_out;
  uint8_T *c21_Input;
  uint8_T *c21_Output;
  c21_Output = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c21_Input = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 19U, chartInstance->c21_sfEvent);
  if (chartInstance->c21_is_active_c21_FSAC2021 == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 19U, chartInstance->c21_sfEvent);
    chartInstance->c21_is_active_c21_FSAC2021 = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c21_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c21_sfEvent);
    chartInstance->c21_is_c21_FSAC2021 = c21_IN_Normal;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c21_sfEvent);
    chartInstance->c21_tp_Normal = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c21_debug_family_names,
      c21_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_nargin, 0U, c21_sf_marshallOut,
      c21_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_nargout, 1U, c21_sf_marshallOut,
      c21_sf_marshallIn);
    *c21_Output = 1U;
    c21_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK((real_T)*c21_Output, 1U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    switch (chartInstance->c21_is_c21_FSAC2021) {
     case c21_IN_Normal:
      CV_CHART_EVAL(19, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U,
                   chartInstance->c21_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c21_c_debug_family_names,
        c21_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_b_nargin, 0U, c21_sf_marshallOut,
        c21_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_b_nargout, 1U,
        c21_sf_marshallOut, c21_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_out, 2U, c21_b_sf_marshallOut,
        c21_b_sf_marshallIn);
      c21_out = CV_EML_IF(0, 0, 0, (real_T)*c21_Input == 0.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c21_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c21_sfEvent);
        chartInstance->c21_tp_Normal = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c21_sfEvent);
        chartInstance->c21_is_c21_FSAC2021 = c21_IN_ON;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c21_sfEvent);
        chartInstance->c21_temporalCounter_i1 = 0U;
        chartInstance->c21_tp_ON = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                     chartInstance->c21_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c21_sfEvent);
      break;

     case c21_IN_ON:
      CV_CHART_EVAL(19, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c21_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c21_d_debug_family_names,
        c21_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_c_nargin, 0U, c21_sf_marshallOut,
        c21_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_c_nargout, 1U,
        c21_sf_marshallOut, c21_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_b_out, 2U, c21_b_sf_marshallOut,
        c21_b_sf_marshallIn);
      c21_b_out = CV_EML_IF(1, 0, 0, *c21_Input == 1);
      _SFD_SYMBOL_SCOPE_POP();
      if (c21_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c21_sfEvent);
        chartInstance->c21_tp_ON = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c21_sfEvent);
        chartInstance->c21_is_c21_FSAC2021 = c21_IN_Off;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c21_sfEvent);
        chartInstance->c21_tp_Off = 1U;
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                     chartInstance->c21_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c21_f_debug_family_names,
          c21_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_d_nargin, 0U,
          c21_sf_marshallOut, c21_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_d_nargout, 1U,
          c21_sf_marshallOut, c21_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_c_out, 2U,
          c21_b_sf_marshallOut, c21_b_sf_marshallIn);
        c21_c_out = CV_EML_IF(3, 0, 0, chartInstance->c21_temporalCounter_i1 >=
                              20);
        _SFD_SYMBOL_SCOPE_POP();
        if (c21_c_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c21_sfEvent);
          chartInstance->c21_tp_ON = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c21_sfEvent);
          chartInstance->c21_is_c21_FSAC2021 = c21_IN_On;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c21_sfEvent);
          chartInstance->c21_tp_On = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c21_b_debug_family_names,
            c21_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_e_nargin, 0U,
            c21_sf_marshallOut, c21_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_e_nargout, 1U,
            c21_sf_marshallOut, c21_sf_marshallIn);
          *c21_Output = 0U;
          c21_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_DATA_RANGE_CHECK((real_T)*c21_Output, 1U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                       chartInstance->c21_sfEvent);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c21_sfEvent);
      break;

     case c21_IN_Off:
      CV_CHART_EVAL(19, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                   chartInstance->c21_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c21_e_debug_family_names,
        c21_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_f_nargin, 0U, c21_sf_marshallOut,
        c21_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_f_nargout, 1U,
        c21_sf_marshallOut, c21_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_d_out, 2U, c21_b_sf_marshallOut,
        c21_b_sf_marshallIn);
      c21_d_out = CV_EML_IF(2, 0, 0, *c21_Input == 0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c21_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c21_sfEvent);
        chartInstance->c21_tp_Off = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c21_sfEvent);
        chartInstance->c21_is_c21_FSAC2021 = c21_IN_ON;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c21_sfEvent);
        chartInstance->c21_temporalCounter_i1 = 0U;
        chartInstance->c21_tp_ON = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                     chartInstance->c21_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c21_sfEvent);
      break;

     case c21_IN_On:
      CV_CHART_EVAL(19, 0, 4);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                   chartInstance->c21_sfEvent);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c21_sfEvent);
      break;

     default:
      CV_CHART_EVAL(19, 0, 0);
      chartInstance->c21_is_c21_FSAC2021 = c21_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c21_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c21_sfEvent);
}

static void initSimStructsc21_FSAC2021(SFc21_FSAC2021InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c21_machineNumber, uint32_T
  c21_chartNumber, uint32_T c21_instanceNumber)
{
  (void)c21_machineNumber;
  (void)c21_chartNumber;
  (void)c21_instanceNumber;
}

static const mxArray *c21_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData)
{
  const mxArray *c21_mxArrayOutData = NULL;
  real_T c21_u;
  const mxArray *c21_y = NULL;
  SFc21_FSAC2021InstanceStruct *chartInstance;
  chartInstance = (SFc21_FSAC2021InstanceStruct *)chartInstanceVoid;
  c21_mxArrayOutData = NULL;
  c21_u = *(real_T *)c21_inData;
  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", &c21_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c21_mxArrayOutData, c21_y, false);
  return c21_mxArrayOutData;
}

static real_T c21_emlrt_marshallIn(SFc21_FSAC2021InstanceStruct *chartInstance,
  const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId)
{
  real_T c21_y;
  real_T c21_d0;
  (void)chartInstance;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), &c21_d0, 1, 0, 0U, 0, 0U, 0);
  c21_y = c21_d0;
  sf_mex_destroy(&c21_u);
  return c21_y;
}

static void c21_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData)
{
  const mxArray *c21_nargout;
  const char_T *c21_identifier;
  emlrtMsgIdentifier c21_thisId;
  real_T c21_y;
  SFc21_FSAC2021InstanceStruct *chartInstance;
  chartInstance = (SFc21_FSAC2021InstanceStruct *)chartInstanceVoid;
  c21_nargout = sf_mex_dup(c21_mxArrayInData);
  c21_identifier = c21_varName;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_y = c21_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_nargout),
    &c21_thisId);
  sf_mex_destroy(&c21_nargout);
  *(real_T *)c21_outData = c21_y;
  sf_mex_destroy(&c21_mxArrayInData);
}

static const mxArray *c21_b_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData)
{
  const mxArray *c21_mxArrayOutData = NULL;
  boolean_T c21_u;
  const mxArray *c21_y = NULL;
  SFc21_FSAC2021InstanceStruct *chartInstance;
  chartInstance = (SFc21_FSAC2021InstanceStruct *)chartInstanceVoid;
  c21_mxArrayOutData = NULL;
  c21_u = *(boolean_T *)c21_inData;
  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", &c21_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c21_mxArrayOutData, c21_y, false);
  return c21_mxArrayOutData;
}

static boolean_T c21_b_emlrt_marshallIn(SFc21_FSAC2021InstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId)
{
  boolean_T c21_y;
  boolean_T c21_b0;
  (void)chartInstance;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), &c21_b0, 1, 11, 0U, 0, 0U, 0);
  c21_y = c21_b0;
  sf_mex_destroy(&c21_u);
  return c21_y;
}

static void c21_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData)
{
  const mxArray *c21_sf_internal_predicateOutput;
  const char_T *c21_identifier;
  emlrtMsgIdentifier c21_thisId;
  boolean_T c21_y;
  SFc21_FSAC2021InstanceStruct *chartInstance;
  chartInstance = (SFc21_FSAC2021InstanceStruct *)chartInstanceVoid;
  c21_sf_internal_predicateOutput = sf_mex_dup(c21_mxArrayInData);
  c21_identifier = c21_varName;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_y = c21_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c21_sf_internal_predicateOutput), &c21_thisId);
  sf_mex_destroy(&c21_sf_internal_predicateOutput);
  *(boolean_T *)c21_outData = c21_y;
  sf_mex_destroy(&c21_mxArrayInData);
}

const mxArray *sf_c21_FSAC2021_get_eml_resolved_functions_info(void)
{
  const mxArray *c21_nameCaptureInfo = NULL;
  c21_nameCaptureInfo = NULL;
  sf_mex_assign(&c21_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c21_nameCaptureInfo;
}

static const mxArray *c21_c_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData)
{
  const mxArray *c21_mxArrayOutData = NULL;
  int32_T c21_u;
  const mxArray *c21_y = NULL;
  SFc21_FSAC2021InstanceStruct *chartInstance;
  chartInstance = (SFc21_FSAC2021InstanceStruct *)chartInstanceVoid;
  c21_mxArrayOutData = NULL;
  c21_u = *(int32_T *)c21_inData;
  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", &c21_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c21_mxArrayOutData, c21_y, false);
  return c21_mxArrayOutData;
}

static int32_T c21_c_emlrt_marshallIn(SFc21_FSAC2021InstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId)
{
  int32_T c21_y;
  int32_T c21_i0;
  (void)chartInstance;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), &c21_i0, 1, 6, 0U, 0, 0U, 0);
  c21_y = c21_i0;
  sf_mex_destroy(&c21_u);
  return c21_y;
}

static void c21_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData)
{
  const mxArray *c21_b_sfEvent;
  const char_T *c21_identifier;
  emlrtMsgIdentifier c21_thisId;
  int32_T c21_y;
  SFc21_FSAC2021InstanceStruct *chartInstance;
  chartInstance = (SFc21_FSAC2021InstanceStruct *)chartInstanceVoid;
  c21_b_sfEvent = sf_mex_dup(c21_mxArrayInData);
  c21_identifier = c21_varName;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_y = c21_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_b_sfEvent),
    &c21_thisId);
  sf_mex_destroy(&c21_b_sfEvent);
  *(int32_T *)c21_outData = c21_y;
  sf_mex_destroy(&c21_mxArrayInData);
}

static const mxArray *c21_d_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData)
{
  const mxArray *c21_mxArrayOutData = NULL;
  uint8_T c21_u;
  const mxArray *c21_y = NULL;
  SFc21_FSAC2021InstanceStruct *chartInstance;
  chartInstance = (SFc21_FSAC2021InstanceStruct *)chartInstanceVoid;
  c21_mxArrayOutData = NULL;
  c21_u = *(uint8_T *)c21_inData;
  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", &c21_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c21_mxArrayOutData, c21_y, false);
  return c21_mxArrayOutData;
}

static uint8_T c21_d_emlrt_marshallIn(SFc21_FSAC2021InstanceStruct
  *chartInstance, const mxArray *c21_b_tp_Normal, const char_T *c21_identifier)
{
  uint8_T c21_y;
  emlrtMsgIdentifier c21_thisId;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_y = c21_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_b_tp_Normal),
    &c21_thisId);
  sf_mex_destroy(&c21_b_tp_Normal);
  return c21_y;
}

static uint8_T c21_e_emlrt_marshallIn(SFc21_FSAC2021InstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId)
{
  uint8_T c21_y;
  uint8_T c21_u0;
  (void)chartInstance;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), &c21_u0, 1, 3, 0U, 0, 0U, 0);
  c21_y = c21_u0;
  sf_mex_destroy(&c21_u);
  return c21_y;
}

static void c21_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData)
{
  const mxArray *c21_b_tp_Normal;
  const char_T *c21_identifier;
  emlrtMsgIdentifier c21_thisId;
  uint8_T c21_y;
  SFc21_FSAC2021InstanceStruct *chartInstance;
  chartInstance = (SFc21_FSAC2021InstanceStruct *)chartInstanceVoid;
  c21_b_tp_Normal = sf_mex_dup(c21_mxArrayInData);
  c21_identifier = c21_varName;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_y = c21_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_b_tp_Normal),
    &c21_thisId);
  sf_mex_destroy(&c21_b_tp_Normal);
  *(uint8_T *)c21_outData = c21_y;
  sf_mex_destroy(&c21_mxArrayInData);
}

static uint32_T c21_f_emlrt_marshallIn(SFc21_FSAC2021InstanceStruct
  *chartInstance, const mxArray *c21_b_previousTicks, const char_T
  *c21_identifier)
{
  uint32_T c21_y;
  emlrtMsgIdentifier c21_thisId;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_y = c21_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_b_previousTicks),
    &c21_thisId);
  sf_mex_destroy(&c21_b_previousTicks);
  return c21_y;
}

static uint32_T c21_g_emlrt_marshallIn(SFc21_FSAC2021InstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId)
{
  uint32_T c21_y;
  uint32_T c21_u1;
  (void)chartInstance;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), &c21_u1, 1, 7, 0U, 0, 0U, 0);
  c21_y = c21_u1;
  sf_mex_destroy(&c21_u);
  return c21_y;
}

static const mxArray *c21_h_emlrt_marshallIn(SFc21_FSAC2021InstanceStruct
  *chartInstance, const mxArray *c21_b_setSimStateSideEffectsInfo, const char_T *
  c21_identifier)
{
  const mxArray *c21_y = NULL;
  emlrtMsgIdentifier c21_thisId;
  c21_y = NULL;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  sf_mex_assign(&c21_y, c21_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c21_b_setSimStateSideEffectsInfo), &c21_thisId), false);
  sf_mex_destroy(&c21_b_setSimStateSideEffectsInfo);
  return c21_y;
}

static const mxArray *c21_i_emlrt_marshallIn(SFc21_FSAC2021InstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId)
{
  const mxArray *c21_y = NULL;
  (void)chartInstance;
  (void)c21_parentId;
  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_duplicatearraysafe(&c21_u), false);
  sf_mex_destroy(&c21_u);
  return c21_y;
}

static void c21_updateDataWrittenToVector(SFc21_FSAC2021InstanceStruct
  *chartInstance, uint32_T c21_vectorIndex)
{
  (void)chartInstance;
  c21_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c21_vectorIndex, 0, 0, 1, 0)] = true;
}

static void init_dsm_address_info(SFc21_FSAC2021InstanceStruct *chartInstance)
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

void sf_c21_FSAC2021_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3993920617U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1940535110U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3179758537U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1550378918U);
}

mxArray *sf_c21_FSAC2021_get_autoinheritance_info(void)
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

mxArray *sf_c21_FSAC2021_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c21_FSAC2021_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c21_FSAC2021(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[24],T\"Output\",},{M[8],M[0],T\"is_active_c21_FSAC2021\",},{M[9],M[0],T\"is_c21_FSAC2021\",},{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"at\",M[14],M[1]}}},{M[13],M[0],T\"previousTicks\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c21_FSAC2021_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc21_FSAC2021InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc21_FSAC2021InstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _FSAC2021MachineNumber_,
           21,
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
          (MexFcnForType)c21_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c21_d_sf_marshallOut,(MexInFcnForType)
          c21_d_sf_marshallIn);

        {
          uint8_T *c21_Input;
          uint8_T *c21_Output;
          c21_Output = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c21_Input = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c21_Input);
          _SFD_SET_DATA_VALUE_PTR(1U, c21_Output);
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
  return "5TaKXVZMXHAVXfL3a1vRTG";
}

static void sf_opaque_initialize_c21_FSAC2021(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc21_FSAC2021InstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c21_FSAC2021((SFc21_FSAC2021InstanceStruct*)
    chartInstanceVar);
  initialize_c21_FSAC2021((SFc21_FSAC2021InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c21_FSAC2021(void *chartInstanceVar)
{
  enable_c21_FSAC2021((SFc21_FSAC2021InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c21_FSAC2021(void *chartInstanceVar)
{
  disable_c21_FSAC2021((SFc21_FSAC2021InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c21_FSAC2021(void *chartInstanceVar)
{
  sf_gateway_c21_FSAC2021((SFc21_FSAC2021InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c21_FSAC2021(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c21_FSAC2021((SFc21_FSAC2021InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c21_FSAC2021();/* state var info */
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

extern void sf_internal_set_sim_state_c21_FSAC2021(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c21_FSAC2021();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c21_FSAC2021((SFc21_FSAC2021InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c21_FSAC2021(SimStruct* S)
{
  return sf_internal_get_sim_state_c21_FSAC2021(S);
}

static void sf_opaque_set_sim_state_c21_FSAC2021(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c21_FSAC2021(S, st);
}

static void sf_opaque_terminate_c21_FSAC2021(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc21_FSAC2021InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_FSAC2021_optimization_info();
    }

    finalize_c21_FSAC2021((SFc21_FSAC2021InstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc21_FSAC2021((SFc21_FSAC2021InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c21_FSAC2021(SimStruct *S)
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
    initialize_params_c21_FSAC2021((SFc21_FSAC2021InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c21_FSAC2021(SimStruct *S)
{
  ssSetNeedAbsoluteTime(S,1);
  ssSetModelReferenceSampleTimeDisallowInheritance(S);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_FSAC2021_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      21);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,21,"RTWCG"));
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,21,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,21);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,21,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,21,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,21);
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

static void mdlRTW_c21_FSAC2021(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c21_FSAC2021(SimStruct *S)
{
  SFc21_FSAC2021InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc21_FSAC2021InstanceStruct *)utMalloc(sizeof
    (SFc21_FSAC2021InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc21_FSAC2021InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c21_FSAC2021;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c21_FSAC2021;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c21_FSAC2021;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c21_FSAC2021;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c21_FSAC2021;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c21_FSAC2021;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c21_FSAC2021;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c21_FSAC2021;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c21_FSAC2021;
  chartInstance->chartInfo.mdlStart = mdlStart_c21_FSAC2021;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c21_FSAC2021;
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

void c21_FSAC2021_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c21_FSAC2021(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c21_FSAC2021(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c21_FSAC2021(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c21_FSAC2021_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
