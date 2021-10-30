/* Include files */

#include <stddef.h>
#include "blas.h"
#include "FSAC2021_V1_Running_sfun.h"
#include "c20_FSAC2021_V1_Running.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "FSAC2021_V1_Running_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c20_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c20_IN_Normal                  ((uint8_T)1U)
#define c20_IN_ON                      ((uint8_T)2U)
#define c20_IN_Off                     ((uint8_T)3U)
#define c20_IN_On                      ((uint8_T)4U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c20_debug_family_names[2] = { "nargin", "nargout" };

static const char * c20_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c20_c_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_d_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_e_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_f_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_g_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_h_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_i_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_j_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c20_dataWrittenToVector[1];

/* Function Declarations */
static void initialize_c20_FSAC2021_V1_Running
  (SFc20_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void initialize_params_c20_FSAC2021_V1_Running
  (SFc20_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void enable_c20_FSAC2021_V1_Running
  (SFc20_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void disable_c20_FSAC2021_V1_Running
  (SFc20_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void c20_update_debugger_state_c20_FSAC2021_V1_Running
  (SFc20_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c20_FSAC2021_V1_Running
  (SFc20_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void set_sim_state_c20_FSAC2021_V1_Running
  (SFc20_FSAC2021_V1_RunningInstanceStruct *chartInstance, const mxArray *c20_st);
static void c20_set_sim_state_side_effects_c20_FSAC2021_V1_Running
  (SFc20_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void finalize_c20_FSAC2021_V1_Running
  (SFc20_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void sf_gateway_c20_FSAC2021_V1_Running
  (SFc20_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void c20_chartstep_c20_FSAC2021_V1_Running
  (SFc20_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void initSimStructsc20_FSAC2021_V1_Running
  (SFc20_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c20_machineNumber, uint32_T
  c20_chartNumber, uint32_T c20_instanceNumber);
static const mxArray *c20_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static real_T c20_emlrt_marshallIn(SFc20_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_b_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static boolean_T c20_b_emlrt_marshallIn(SFc20_FSAC2021_V1_RunningInstanceStruct *
  chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_c_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static int32_T c20_c_emlrt_marshallIn(SFc20_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_d_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static uint8_T c20_d_emlrt_marshallIn(SFc20_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c20_b_tp_Normal, const char_T *c20_identifier);
static uint8_T c20_e_emlrt_marshallIn(SFc20_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static uint32_T c20_f_emlrt_marshallIn(SFc20_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c20_b_previousTicks, const char_T
  *c20_identifier);
static uint32_T c20_g_emlrt_marshallIn(SFc20_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static const mxArray *c20_h_emlrt_marshallIn
  (SFc20_FSAC2021_V1_RunningInstanceStruct *chartInstance, const mxArray
   *c20_b_setSimStateSideEffectsInfo, const char_T *c20_identifier);
static const mxArray *c20_i_emlrt_marshallIn
  (SFc20_FSAC2021_V1_RunningInstanceStruct *chartInstance, const mxArray *c20_u,
   const emlrtMsgIdentifier *c20_parentId);
static void c20_updateDataWrittenToVector
  (SFc20_FSAC2021_V1_RunningInstanceStruct *chartInstance, uint32_T
   c20_vectorIndex);
static void init_dsm_address_info(SFc20_FSAC2021_V1_RunningInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c20_FSAC2021_V1_Running
  (SFc20_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  chartInstance->c20_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c20_doSetSimStateSideEffects = 0U;
  chartInstance->c20_setSimStateSideEffectsInfo = NULL;
  chartInstance->c20_tp_Normal = 0U;
  chartInstance->c20_tp_ON = 0U;
  chartInstance->c20_temporalCounter_i1 = 0U;
  chartInstance->c20_tp_Off = 0U;
  chartInstance->c20_tp_On = 0U;
  chartInstance->c20_is_active_c20_FSAC2021_V1_Running = 0U;
  chartInstance->c20_is_c20_FSAC2021_V1_Running = c20_IN_NO_ACTIVE_CHILD;
  chartInstance->c20_presentTicks = 0U;
  chartInstance->c20_elapsedTicks = 0U;
  chartInstance->c20_previousTicks = 0U;
}

static void initialize_params_c20_FSAC2021_V1_Running
  (SFc20_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c20_FSAC2021_V1_Running
  (SFc20_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c20_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.1
    + 0.5);
  chartInstance->c20_previousTicks = chartInstance->c20_presentTicks;
}

static void disable_c20_FSAC2021_V1_Running
  (SFc20_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c20_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.1
    + 0.5);
  chartInstance->c20_elapsedTicks = chartInstance->c20_presentTicks -
    chartInstance->c20_previousTicks;
  chartInstance->c20_previousTicks = chartInstance->c20_presentTicks;
  if ((uint32_T)chartInstance->c20_temporalCounter_i1 +
      chartInstance->c20_elapsedTicks <= 31U) {
    chartInstance->c20_temporalCounter_i1 = (uint8_T)((uint32_T)
      chartInstance->c20_temporalCounter_i1 + chartInstance->c20_elapsedTicks);
  } else {
    chartInstance->c20_temporalCounter_i1 = 31U;
  }
}

static void c20_update_debugger_state_c20_FSAC2021_V1_Running
  (SFc20_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  uint32_T c20_prevAniVal;
  c20_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c20_is_active_c20_FSAC2021_V1_Running == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 19U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_c20_FSAC2021_V1_Running == c20_IN_Normal) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_c20_FSAC2021_V1_Running == c20_IN_Off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_c20_FSAC2021_V1_Running == c20_IN_ON) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c20_sfEvent);
  }

  if (chartInstance->c20_is_c20_FSAC2021_V1_Running == c20_IN_On) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c20_sfEvent);
  }

  _SFD_SET_ANIMATION(c20_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c20_FSAC2021_V1_Running
  (SFc20_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  const mxArray *c20_st;
  const mxArray *c20_y = NULL;
  uint8_T c20_hoistedGlobal;
  uint8_T c20_u;
  const mxArray *c20_b_y = NULL;
  uint8_T c20_b_hoistedGlobal;
  uint8_T c20_b_u;
  const mxArray *c20_c_y = NULL;
  uint8_T c20_c_hoistedGlobal;
  uint8_T c20_c_u;
  const mxArray *c20_d_y = NULL;
  uint8_T c20_d_hoistedGlobal;
  uint8_T c20_d_u;
  const mxArray *c20_e_y = NULL;
  uint32_T c20_e_hoistedGlobal;
  uint32_T c20_e_u;
  const mxArray *c20_f_y = NULL;
  uint8_T *c20_Output;
  c20_Output = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c20_st = NULL;
  c20_st = NULL;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_createcellmatrix(5, 1), false);
  c20_hoistedGlobal = *c20_Output;
  c20_u = c20_hoistedGlobal;
  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", &c20_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 0, c20_b_y);
  c20_b_hoistedGlobal = chartInstance->c20_is_active_c20_FSAC2021_V1_Running;
  c20_b_u = c20_b_hoistedGlobal;
  c20_c_y = NULL;
  sf_mex_assign(&c20_c_y, sf_mex_create("y", &c20_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 1, c20_c_y);
  c20_c_hoistedGlobal = chartInstance->c20_is_c20_FSAC2021_V1_Running;
  c20_c_u = c20_c_hoistedGlobal;
  c20_d_y = NULL;
  sf_mex_assign(&c20_d_y, sf_mex_create("y", &c20_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 2, c20_d_y);
  c20_d_hoistedGlobal = chartInstance->c20_temporalCounter_i1;
  c20_d_u = c20_d_hoistedGlobal;
  c20_e_y = NULL;
  sf_mex_assign(&c20_e_y, sf_mex_create("y", &c20_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 3, c20_e_y);
  c20_e_hoistedGlobal = chartInstance->c20_previousTicks;
  c20_e_u = c20_e_hoistedGlobal;
  c20_f_y = NULL;
  sf_mex_assign(&c20_f_y, sf_mex_create("y", &c20_e_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 4, c20_f_y);
  sf_mex_assign(&c20_st, c20_y, false);
  return c20_st;
}

static void set_sim_state_c20_FSAC2021_V1_Running
  (SFc20_FSAC2021_V1_RunningInstanceStruct *chartInstance, const mxArray *c20_st)
{
  const mxArray *c20_u;
  uint8_T *c20_Output;
  c20_Output = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c20_u = sf_mex_dup(c20_st);
  *c20_Output = c20_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c20_u, 0)), "Output");
  chartInstance->c20_is_active_c20_FSAC2021_V1_Running = c20_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c20_u, 1)),
     "is_active_c20_FSAC2021_V1_Running");
  chartInstance->c20_is_c20_FSAC2021_V1_Running = c20_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c20_u, 2)),
     "is_c20_FSAC2021_V1_Running");
  chartInstance->c20_temporalCounter_i1 = c20_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c20_u, 3)), "temporalCounter_i1");
  chartInstance->c20_previousTicks = c20_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c20_u, 4)), "previousTicks");
  sf_mex_assign(&chartInstance->c20_setSimStateSideEffectsInfo,
                c20_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c20_u, 5)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c20_u);
  chartInstance->c20_doSetSimStateSideEffects = 1U;
  c20_update_debugger_state_c20_FSAC2021_V1_Running(chartInstance);
  sf_mex_destroy(&c20_st);
}

static void c20_set_sim_state_side_effects_c20_FSAC2021_V1_Running
  (SFc20_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  if (chartInstance->c20_doSetSimStateSideEffects != 0) {
    if (chartInstance->c20_is_c20_FSAC2021_V1_Running == c20_IN_Normal) {
      chartInstance->c20_tp_Normal = 1U;
    } else {
      chartInstance->c20_tp_Normal = 0U;
    }

    if (chartInstance->c20_is_c20_FSAC2021_V1_Running == c20_IN_ON) {
      chartInstance->c20_tp_ON = 1U;
      if (sf_mex_sub(chartInstance->c20_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 3) == 0.0) {
        chartInstance->c20_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c20_tp_ON = 0U;
    }

    if (chartInstance->c20_is_c20_FSAC2021_V1_Running == c20_IN_Off) {
      chartInstance->c20_tp_Off = 1U;
    } else {
      chartInstance->c20_tp_Off = 0U;
    }

    if (chartInstance->c20_is_c20_FSAC2021_V1_Running == c20_IN_On) {
      chartInstance->c20_tp_On = 1U;
    } else {
      chartInstance->c20_tp_On = 0U;
    }

    chartInstance->c20_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c20_FSAC2021_V1_Running
  (SFc20_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c20_setSimStateSideEffectsInfo);
}

static void sf_gateway_c20_FSAC2021_V1_Running
  (SFc20_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  uint8_T *c20_Input;
  uint8_T *c20_Output;
  c20_Output = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c20_Input = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c20_set_sim_state_side_effects_c20_FSAC2021_V1_Running(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c20_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.1
    + 0.5);
  chartInstance->c20_elapsedTicks = chartInstance->c20_presentTicks -
    chartInstance->c20_previousTicks;
  chartInstance->c20_previousTicks = chartInstance->c20_presentTicks;
  if ((uint32_T)chartInstance->c20_temporalCounter_i1 +
      chartInstance->c20_elapsedTicks <= 31U) {
    chartInstance->c20_temporalCounter_i1 = (uint8_T)((uint32_T)
      chartInstance->c20_temporalCounter_i1 + chartInstance->c20_elapsedTicks);
  } else {
    chartInstance->c20_temporalCounter_i1 = 31U;
  }

  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 19U, chartInstance->c20_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*c20_Input, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)*c20_Output, 1U);
  chartInstance->c20_sfEvent = CALL_EVENT;
  c20_chartstep_c20_FSAC2021_V1_Running(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_FSAC2021_V1_RunningMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c20_chartstep_c20_FSAC2021_V1_Running
  (SFc20_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  uint32_T c20_debug_family_var_map[2];
  real_T c20_nargin = 0.0;
  real_T c20_nargout = 0.0;
  uint32_T c20_b_debug_family_var_map[3];
  real_T c20_b_nargin = 0.0;
  real_T c20_b_nargout = 1.0;
  boolean_T c20_out;
  real_T c20_c_nargin = 0.0;
  real_T c20_c_nargout = 1.0;
  boolean_T c20_b_out;
  real_T c20_d_nargin = 0.0;
  real_T c20_d_nargout = 1.0;
  boolean_T c20_c_out;
  real_T c20_e_nargin = 0.0;
  real_T c20_e_nargout = 0.0;
  real_T c20_f_nargin = 0.0;
  real_T c20_f_nargout = 1.0;
  boolean_T c20_d_out;
  uint8_T *c20_Input;
  uint8_T *c20_Output;
  c20_Output = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c20_Input = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 19U, chartInstance->c20_sfEvent);
  if (chartInstance->c20_is_active_c20_FSAC2021_V1_Running == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 19U, chartInstance->c20_sfEvent);
    chartInstance->c20_is_active_c20_FSAC2021_V1_Running = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c20_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c20_sfEvent);
    chartInstance->c20_is_c20_FSAC2021_V1_Running = c20_IN_Normal;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c20_sfEvent);
    chartInstance->c20_tp_Normal = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c20_debug_family_names,
      c20_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 0U, c20_sf_marshallOut,
      c20_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 1U, c20_sf_marshallOut,
      c20_sf_marshallIn);
    *c20_Output = 1U;
    c20_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK((real_T)*c20_Output, 1U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    switch (chartInstance->c20_is_c20_FSAC2021_V1_Running) {
     case c20_IN_Normal:
      CV_CHART_EVAL(19, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U,
                   chartInstance->c20_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_c_debug_family_names,
        c20_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_nargin, 0U, c20_sf_marshallOut,
        c20_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_nargout, 1U,
        c20_sf_marshallOut, c20_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_out, 2U, c20_b_sf_marshallOut,
        c20_b_sf_marshallIn);
      c20_out = CV_EML_IF(0, 0, 0, (real_T)*c20_Input == 0.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c20_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c20_sfEvent);
        chartInstance->c20_tp_Normal = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c20_sfEvent);
        chartInstance->c20_is_c20_FSAC2021_V1_Running = c20_IN_ON;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c20_sfEvent);
        chartInstance->c20_temporalCounter_i1 = 0U;
        chartInstance->c20_tp_ON = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                     chartInstance->c20_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c20_sfEvent);
      break;

     case c20_IN_ON:
      CV_CHART_EVAL(19, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c20_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_d_debug_family_names,
        c20_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_c_nargin, 0U, c20_sf_marshallOut,
        c20_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_c_nargout, 1U,
        c20_sf_marshallOut, c20_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_out, 2U, c20_b_sf_marshallOut,
        c20_b_sf_marshallIn);
      c20_b_out = CV_EML_IF(1, 0, 0, *c20_Input == 1);
      _SFD_SYMBOL_SCOPE_POP();
      if (c20_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c20_sfEvent);
        chartInstance->c20_tp_ON = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c20_sfEvent);
        chartInstance->c20_is_c20_FSAC2021_V1_Running = c20_IN_Off;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c20_sfEvent);
        chartInstance->c20_tp_Off = 1U;
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                     chartInstance->c20_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_f_debug_family_names,
          c20_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_d_nargin, 0U,
          c20_sf_marshallOut, c20_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_d_nargout, 1U,
          c20_sf_marshallOut, c20_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_c_out, 2U,
          c20_b_sf_marshallOut, c20_b_sf_marshallIn);
        c20_c_out = CV_EML_IF(3, 0, 0, chartInstance->c20_temporalCounter_i1 >=
                              20);
        _SFD_SYMBOL_SCOPE_POP();
        if (c20_c_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c20_sfEvent);
          chartInstance->c20_tp_ON = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c20_sfEvent);
          chartInstance->c20_is_c20_FSAC2021_V1_Running = c20_IN_On;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c20_sfEvent);
          chartInstance->c20_tp_On = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c20_b_debug_family_names,
            c20_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_e_nargin, 0U,
            c20_sf_marshallOut, c20_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_e_nargout, 1U,
            c20_sf_marshallOut, c20_sf_marshallIn);
          *c20_Output = 0U;
          c20_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_DATA_RANGE_CHECK((real_T)*c20_Output, 1U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                       chartInstance->c20_sfEvent);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c20_sfEvent);
      break;

     case c20_IN_Off:
      CV_CHART_EVAL(19, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                   chartInstance->c20_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_e_debug_family_names,
        c20_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_f_nargin, 0U, c20_sf_marshallOut,
        c20_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_f_nargout, 1U,
        c20_sf_marshallOut, c20_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_d_out, 2U, c20_b_sf_marshallOut,
        c20_b_sf_marshallIn);
      c20_d_out = CV_EML_IF(2, 0, 0, *c20_Input == 0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c20_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c20_sfEvent);
        chartInstance->c20_tp_Off = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c20_sfEvent);
        chartInstance->c20_is_c20_FSAC2021_V1_Running = c20_IN_ON;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c20_sfEvent);
        chartInstance->c20_temporalCounter_i1 = 0U;
        chartInstance->c20_tp_ON = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                     chartInstance->c20_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c20_sfEvent);
      break;

     case c20_IN_On:
      CV_CHART_EVAL(19, 0, 4);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                   chartInstance->c20_sfEvent);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c20_sfEvent);
      break;

     default:
      CV_CHART_EVAL(19, 0, 0);
      chartInstance->c20_is_c20_FSAC2021_V1_Running = c20_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c20_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c20_sfEvent);
}

static void initSimStructsc20_FSAC2021_V1_Running
  (SFc20_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c20_machineNumber, uint32_T
  c20_chartNumber, uint32_T c20_instanceNumber)
{
  (void)c20_machineNumber;
  (void)c20_chartNumber;
  (void)c20_instanceNumber;
}

static const mxArray *c20_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  real_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  chartInstance = (SFc20_FSAC2021_V1_RunningInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(real_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static real_T c20_emlrt_marshallIn(SFc20_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  real_T c20_y;
  real_T c20_d0;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_d0, 1, 0, 0U, 0, 0U, 0);
  c20_y = c20_d0;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_nargout;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  real_T c20_y;
  SFc20_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  chartInstance = (SFc20_FSAC2021_V1_RunningInstanceStruct *)chartInstanceVoid;
  c20_nargout = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_nargout),
    &c20_thisId);
  sf_mex_destroy(&c20_nargout);
  *(real_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_b_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  boolean_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  chartInstance = (SFc20_FSAC2021_V1_RunningInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(boolean_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static boolean_T c20_b_emlrt_marshallIn(SFc20_FSAC2021_V1_RunningInstanceStruct *
  chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  boolean_T c20_y;
  boolean_T c20_b0;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_b0, 1, 11, 0U, 0, 0U, 0);
  c20_y = c20_b0;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_sf_internal_predicateOutput;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  boolean_T c20_y;
  SFc20_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  chartInstance = (SFc20_FSAC2021_V1_RunningInstanceStruct *)chartInstanceVoid;
  c20_sf_internal_predicateOutput = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c20_sf_internal_predicateOutput), &c20_thisId);
  sf_mex_destroy(&c20_sf_internal_predicateOutput);
  *(boolean_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

const mxArray *sf_c20_FSAC2021_V1_Running_get_eml_resolved_functions_info(void)
{
  const mxArray *c20_nameCaptureInfo = NULL;
  c20_nameCaptureInfo = NULL;
  sf_mex_assign(&c20_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c20_nameCaptureInfo;
}

static const mxArray *c20_c_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  chartInstance = (SFc20_FSAC2021_V1_RunningInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(int32_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static int32_T c20_c_emlrt_marshallIn(SFc20_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  int32_T c20_y;
  int32_T c20_i0;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_i0, 1, 6, 0U, 0, 0U, 0);
  c20_y = c20_i0;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_b_sfEvent;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  int32_T c20_y;
  SFc20_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  chartInstance = (SFc20_FSAC2021_V1_RunningInstanceStruct *)chartInstanceVoid;
  c20_b_sfEvent = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_b_sfEvent),
    &c20_thisId);
  sf_mex_destroy(&c20_b_sfEvent);
  *(int32_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_d_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  uint8_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  chartInstance = (SFc20_FSAC2021_V1_RunningInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(uint8_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static uint8_T c20_d_emlrt_marshallIn(SFc20_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c20_b_tp_Normal, const char_T *c20_identifier)
{
  uint8_T c20_y;
  emlrtMsgIdentifier c20_thisId;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_b_tp_Normal),
    &c20_thisId);
  sf_mex_destroy(&c20_b_tp_Normal);
  return c20_y;
}

static uint8_T c20_e_emlrt_marshallIn(SFc20_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  uint8_T c20_y;
  uint8_T c20_u0;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_u0, 1, 3, 0U, 0, 0U, 0);
  c20_y = c20_u0;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_b_tp_Normal;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  uint8_T c20_y;
  SFc20_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  chartInstance = (SFc20_FSAC2021_V1_RunningInstanceStruct *)chartInstanceVoid;
  c20_b_tp_Normal = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_b_tp_Normal),
    &c20_thisId);
  sf_mex_destroy(&c20_b_tp_Normal);
  *(uint8_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

static uint32_T c20_f_emlrt_marshallIn(SFc20_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c20_b_previousTicks, const char_T
  *c20_identifier)
{
  uint32_T c20_y;
  emlrtMsgIdentifier c20_thisId;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_b_previousTicks),
    &c20_thisId);
  sf_mex_destroy(&c20_b_previousTicks);
  return c20_y;
}

static uint32_T c20_g_emlrt_marshallIn(SFc20_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  uint32_T c20_y;
  uint32_T c20_u1;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_u1, 1, 7, 0U, 0, 0U, 0);
  c20_y = c20_u1;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static const mxArray *c20_h_emlrt_marshallIn
  (SFc20_FSAC2021_V1_RunningInstanceStruct *chartInstance, const mxArray
   *c20_b_setSimStateSideEffectsInfo, const char_T *c20_identifier)
{
  const mxArray *c20_y = NULL;
  emlrtMsgIdentifier c20_thisId;
  c20_y = NULL;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  sf_mex_assign(&c20_y, c20_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c20_b_setSimStateSideEffectsInfo), &c20_thisId), false);
  sf_mex_destroy(&c20_b_setSimStateSideEffectsInfo);
  return c20_y;
}

static const mxArray *c20_i_emlrt_marshallIn
  (SFc20_FSAC2021_V1_RunningInstanceStruct *chartInstance, const mxArray *c20_u,
   const emlrtMsgIdentifier *c20_parentId)
{
  const mxArray *c20_y = NULL;
  (void)chartInstance;
  (void)c20_parentId;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_duplicatearraysafe(&c20_u), false);
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_updateDataWrittenToVector
  (SFc20_FSAC2021_V1_RunningInstanceStruct *chartInstance, uint32_T
   c20_vectorIndex)
{
  (void)chartInstance;
  c20_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c20_vectorIndex, 0, 0, 1, 0)] = true;
}

static void init_dsm_address_info(SFc20_FSAC2021_V1_RunningInstanceStruct
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

void sf_c20_FSAC2021_V1_Running_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3993920617U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1940535110U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3179758537U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1550378918U);
}

mxArray *sf_c20_FSAC2021_V1_Running_get_autoinheritance_info(void)
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

mxArray *sf_c20_FSAC2021_V1_Running_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c20_FSAC2021_V1_Running_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c20_FSAC2021_V1_Running(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[24],T\"Output\",},{M[8],M[0],T\"is_active_c20_FSAC2021_V1_Running\",},{M[9],M[0],T\"is_c20_FSAC2021_V1_Running\",},{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"at\",M[14],M[1]}}},{M[13],M[0],T\"previousTicks\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c20_FSAC2021_V1_Running_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc20_FSAC2021_V1_RunningInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc20_FSAC2021_V1_RunningInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _FSAC2021_V1_RunningMachineNumber_,
           20,
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
        init_script_number_translation(_FSAC2021_V1_RunningMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_FSAC2021_V1_RunningMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _FSAC2021_V1_RunningMachineNumber_,
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
          (MexFcnForType)c20_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_d_sf_marshallOut,(MexInFcnForType)
          c20_d_sf_marshallIn);

        {
          uint8_T *c20_Input;
          uint8_T *c20_Output;
          c20_Output = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c20_Input = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c20_Input);
          _SFD_SET_DATA_VALUE_PTR(1U, c20_Output);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _FSAC2021_V1_RunningMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "5TaKXVZMXHAVXfL3a1vRTG";
}

static void sf_opaque_initialize_c20_FSAC2021_V1_Running(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc20_FSAC2021_V1_RunningInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c20_FSAC2021_V1_Running
    ((SFc20_FSAC2021_V1_RunningInstanceStruct*) chartInstanceVar);
  initialize_c20_FSAC2021_V1_Running((SFc20_FSAC2021_V1_RunningInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c20_FSAC2021_V1_Running(void *chartInstanceVar)
{
  enable_c20_FSAC2021_V1_Running((SFc20_FSAC2021_V1_RunningInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c20_FSAC2021_V1_Running(void *chartInstanceVar)
{
  disable_c20_FSAC2021_V1_Running((SFc20_FSAC2021_V1_RunningInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c20_FSAC2021_V1_Running(void *chartInstanceVar)
{
  sf_gateway_c20_FSAC2021_V1_Running((SFc20_FSAC2021_V1_RunningInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c20_FSAC2021_V1_Running
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c20_FSAC2021_V1_Running
    ((SFc20_FSAC2021_V1_RunningInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c20_FSAC2021_V1_Running();/* state var info */
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

extern void sf_internal_set_sim_state_c20_FSAC2021_V1_Running(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c20_FSAC2021_V1_Running();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c20_FSAC2021_V1_Running((SFc20_FSAC2021_V1_RunningInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c20_FSAC2021_V1_Running(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c20_FSAC2021_V1_Running(S);
}

static void sf_opaque_set_sim_state_c20_FSAC2021_V1_Running(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c20_FSAC2021_V1_Running(S, st);
}

static void sf_opaque_terminate_c20_FSAC2021_V1_Running(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc20_FSAC2021_V1_RunningInstanceStruct*) chartInstanceVar
      )->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_FSAC2021_V1_Running_optimization_info();
    }

    finalize_c20_FSAC2021_V1_Running((SFc20_FSAC2021_V1_RunningInstanceStruct*)
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
  initSimStructsc20_FSAC2021_V1_Running((SFc20_FSAC2021_V1_RunningInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c20_FSAC2021_V1_Running(SimStruct *S)
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
    initialize_params_c20_FSAC2021_V1_Running
      ((SFc20_FSAC2021_V1_RunningInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c20_FSAC2021_V1_Running(SimStruct *S)
{
  ssSetNeedAbsoluteTime(S,1);
  ssSetModelReferenceSampleTimeDisallowInheritance(S);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_FSAC2021_V1_Running_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      20);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,20,"RTWCG"));
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,20,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,20);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,20,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,20,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,20);
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

static void mdlRTW_c20_FSAC2021_V1_Running(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c20_FSAC2021_V1_Running(SimStruct *S)
{
  SFc20_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc20_FSAC2021_V1_RunningInstanceStruct *)utMalloc(sizeof
    (SFc20_FSAC2021_V1_RunningInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc20_FSAC2021_V1_RunningInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c20_FSAC2021_V1_Running;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c20_FSAC2021_V1_Running;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c20_FSAC2021_V1_Running;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c20_FSAC2021_V1_Running;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c20_FSAC2021_V1_Running;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c20_FSAC2021_V1_Running;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c20_FSAC2021_V1_Running;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c20_FSAC2021_V1_Running;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c20_FSAC2021_V1_Running;
  chartInstance->chartInfo.mdlStart = mdlStart_c20_FSAC2021_V1_Running;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c20_FSAC2021_V1_Running;
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

void c20_FSAC2021_V1_Running_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c20_FSAC2021_V1_Running(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c20_FSAC2021_V1_Running(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c20_FSAC2021_V1_Running(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c20_FSAC2021_V1_Running_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
