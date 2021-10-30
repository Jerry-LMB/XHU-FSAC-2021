/* Include files */

#include <stddef.h>
#include "blas.h"
#include "FSAC2021_V1_Running_sfun.h"
#include "c9_FSAC2021_V1_Running.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "FSAC2021_V1_Running_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c9_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c9_IN_IN                       ((uint8_T)1U)
#define c9_IN_end                      ((uint8_T)2U)
#define c9_IN_init                     ((uint8_T)3U)
#define c9_IN_Move                     ((uint8_T)1U)
#define c9_IN_Second                   ((uint8_T)2U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c9_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c9_e_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_f_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_g_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_h_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_i_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c9_j_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c9_dataWrittenToVector[3];

/* Function Declarations */
static void initialize_c9_FSAC2021_V1_Running
  (SFc9_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void initialize_params_c9_FSAC2021_V1_Running
  (SFc9_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void enable_c9_FSAC2021_V1_Running(SFc9_FSAC2021_V1_RunningInstanceStruct
  *chartInstance);
static void disable_c9_FSAC2021_V1_Running
  (SFc9_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void c9_update_debugger_state_c9_FSAC2021_V1_Running
  (SFc9_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c9_FSAC2021_V1_Running
  (SFc9_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void set_sim_state_c9_FSAC2021_V1_Running
  (SFc9_FSAC2021_V1_RunningInstanceStruct *chartInstance, const mxArray *c9_st);
static void c9_set_sim_state_side_effects_c9_FSAC2021_V1_Running
  (SFc9_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void finalize_c9_FSAC2021_V1_Running
  (SFc9_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void sf_gateway_c9_FSAC2021_V1_Running
  (SFc9_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void c9_chartstep_c9_FSAC2021_V1_Running
  (SFc9_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void initSimStructsc9_FSAC2021_V1_Running
  (SFc9_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void c9_exit_internal_IN(SFc9_FSAC2021_V1_RunningInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber, uint32_T c9_instanceNumber);
static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData);
static real_T c9_emlrt_marshallIn(SFc9_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c9_nargout, const char_T *c9_identifier);
static real_T c9_b_emlrt_marshallIn(SFc9_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static boolean_T c9_c_emlrt_marshallIn(SFc9_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static int32_T c9_d_emlrt_marshallIn(SFc9_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static uint8_T c9_e_emlrt_marshallIn(SFc9_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c9_b_tp_init, const char_T *c9_identifier);
static uint8_T c9_f_emlrt_marshallIn(SFc9_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static uint16_T c9_g_emlrt_marshallIn(SFc9_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c9_b_temporalCounter_i1, const char_T
  *c9_identifier);
static uint16_T c9_h_emlrt_marshallIn(SFc9_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static uint32_T c9_i_emlrt_marshallIn(SFc9_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c9_b_previousTicks, const char_T *c9_identifier);
static uint32_T c9_j_emlrt_marshallIn(SFc9_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static const mxArray *c9_k_emlrt_marshallIn
  (SFc9_FSAC2021_V1_RunningInstanceStruct *chartInstance, const mxArray
   *c9_b_setSimStateSideEffectsInfo, const char_T *c9_identifier);
static const mxArray *c9_l_emlrt_marshallIn
  (SFc9_FSAC2021_V1_RunningInstanceStruct *chartInstance, const mxArray *c9_u,
   const emlrtMsgIdentifier *c9_parentId);
static void c9_updateDataWrittenToVector(SFc9_FSAC2021_V1_RunningInstanceStruct *
  chartInstance, uint32_T c9_vectorIndex);
static void c9_errorIfDataNotWrittenToFcn(SFc9_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, uint32_T c9_vectorIndex, uint32_T c9_dataNumber);
static void init_dsm_address_info(SFc9_FSAC2021_V1_RunningInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c9_FSAC2021_V1_Running
  (SFc9_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  chartInstance->c9_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c9_doSetSimStateSideEffects = 0U;
  chartInstance->c9_setSimStateSideEffectsInfo = NULL;
  chartInstance->c9_is_IN = c9_IN_NO_ACTIVE_CHILD;
  chartInstance->c9_tp_IN = 0U;
  chartInstance->c9_temporalCounter_i1 = 0U;
  chartInstance->c9_tp_Move = 0U;
  chartInstance->c9_tp_Second = 0U;
  chartInstance->c9_tp_end = 0U;
  chartInstance->c9_tp_init = 0U;
  chartInstance->c9_is_active_c9_FSAC2021_V1_Running = 0U;
  chartInstance->c9_is_c9_FSAC2021_V1_Running = c9_IN_NO_ACTIVE_CHILD;
  chartInstance->c9_presentTicks = 0U;
  chartInstance->c9_elapsedTicks = 0U;
  chartInstance->c9_previousTicks = 0U;
}

static void initialize_params_c9_FSAC2021_V1_Running
  (SFc9_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c9_FSAC2021_V1_Running(SFc9_FSAC2021_V1_RunningInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c9_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.05
    + 0.5);
  chartInstance->c9_previousTicks = chartInstance->c9_presentTicks;
}

static void disable_c9_FSAC2021_V1_Running
  (SFc9_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c9_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.05
    + 0.5);
  chartInstance->c9_elapsedTicks = chartInstance->c9_presentTicks -
    chartInstance->c9_previousTicks;
  chartInstance->c9_previousTicks = chartInstance->c9_presentTicks;
  if ((uint32_T)chartInstance->c9_temporalCounter_i1 +
      chartInstance->c9_elapsedTicks <= 1023U) {
    chartInstance->c9_temporalCounter_i1 = (uint16_T)((uint32_T)
      chartInstance->c9_temporalCounter_i1 + chartInstance->c9_elapsedTicks);
  } else {
    chartInstance->c9_temporalCounter_i1 = 1023U;
  }
}

static void c9_update_debugger_state_c9_FSAC2021_V1_Running
  (SFc9_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  uint32_T c9_prevAniVal;
  c9_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c9_is_active_c9_FSAC2021_V1_Running == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 8U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_c9_FSAC2021_V1_Running == c9_IN_init) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_c9_FSAC2021_V1_Running == c9_IN_IN) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_IN == c9_IN_Second) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_IN == c9_IN_Move) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c9_sfEvent);
  }

  if (chartInstance->c9_is_c9_FSAC2021_V1_Running == c9_IN_end) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
  }

  _SFD_SET_ANIMATION(c9_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c9_FSAC2021_V1_Running
  (SFc9_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  const mxArray *c9_st;
  const mxArray *c9_y = NULL;
  real_T c9_hoistedGlobal;
  real_T c9_u;
  const mxArray *c9_b_y = NULL;
  uint8_T c9_b_hoistedGlobal;
  uint8_T c9_b_u;
  const mxArray *c9_c_y = NULL;
  real_T c9_c_hoistedGlobal;
  real_T c9_c_u;
  const mxArray *c9_d_y = NULL;
  uint8_T c9_d_hoistedGlobal;
  uint8_T c9_d_u;
  const mxArray *c9_e_y = NULL;
  uint8_T c9_e_hoistedGlobal;
  uint8_T c9_e_u;
  const mxArray *c9_f_y = NULL;
  uint8_T c9_f_hoistedGlobal;
  uint8_T c9_f_u;
  const mxArray *c9_g_y = NULL;
  uint16_T c9_g_hoistedGlobal;
  uint16_T c9_g_u;
  const mxArray *c9_h_y = NULL;
  uint32_T c9_h_hoistedGlobal;
  uint32_T c9_h_u;
  const mxArray *c9_i_y = NULL;
  real_T *c9_ACC;
  uint8_T *c9_Mission_Flag;
  real_T *c9_SteerCmd;
  c9_ACC = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c9_SteerCmd = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_Mission_Flag = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c9_st = NULL;
  c9_st = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createcellmatrix(8, 1), false);
  c9_hoistedGlobal = *c9_ACC;
  c9_u = c9_hoistedGlobal;
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 0, c9_b_y);
  c9_b_hoistedGlobal = *c9_Mission_Flag;
  c9_b_u = c9_b_hoistedGlobal;
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", &c9_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 1, c9_c_y);
  c9_c_hoistedGlobal = *c9_SteerCmd;
  c9_c_u = c9_c_hoistedGlobal;
  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", &c9_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 2, c9_d_y);
  c9_d_hoistedGlobal = chartInstance->c9_is_active_c9_FSAC2021_V1_Running;
  c9_d_u = c9_d_hoistedGlobal;
  c9_e_y = NULL;
  sf_mex_assign(&c9_e_y, sf_mex_create("y", &c9_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 3, c9_e_y);
  c9_e_hoistedGlobal = chartInstance->c9_is_c9_FSAC2021_V1_Running;
  c9_e_u = c9_e_hoistedGlobal;
  c9_f_y = NULL;
  sf_mex_assign(&c9_f_y, sf_mex_create("y", &c9_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 4, c9_f_y);
  c9_f_hoistedGlobal = chartInstance->c9_is_IN;
  c9_f_u = c9_f_hoistedGlobal;
  c9_g_y = NULL;
  sf_mex_assign(&c9_g_y, sf_mex_create("y", &c9_f_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 5, c9_g_y);
  c9_g_hoistedGlobal = chartInstance->c9_temporalCounter_i1;
  c9_g_u = c9_g_hoistedGlobal;
  c9_h_y = NULL;
  sf_mex_assign(&c9_h_y, sf_mex_create("y", &c9_g_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 6, c9_h_y);
  c9_h_hoistedGlobal = chartInstance->c9_previousTicks;
  c9_h_u = c9_h_hoistedGlobal;
  c9_i_y = NULL;
  sf_mex_assign(&c9_i_y, sf_mex_create("y", &c9_h_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 7, c9_i_y);
  sf_mex_assign(&c9_st, c9_y, false);
  return c9_st;
}

static void set_sim_state_c9_FSAC2021_V1_Running
  (SFc9_FSAC2021_V1_RunningInstanceStruct *chartInstance, const mxArray *c9_st)
{
  const mxArray *c9_u;
  real_T *c9_ACC;
  uint8_T *c9_Mission_Flag;
  real_T *c9_SteerCmd;
  c9_ACC = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c9_SteerCmd = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_Mission_Flag = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c9_u = sf_mex_dup(c9_st);
  *c9_ACC = c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 0)),
    "ACC");
  *c9_Mission_Flag = c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 1)), "Mission_Flag");
  *c9_SteerCmd = c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c9_u, 2)), "SteerCmd");
  chartInstance->c9_is_active_c9_FSAC2021_V1_Running = c9_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 3)),
     "is_active_c9_FSAC2021_V1_Running");
  chartInstance->c9_is_c9_FSAC2021_V1_Running = c9_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 4)),
     "is_c9_FSAC2021_V1_Running");
  chartInstance->c9_is_IN = c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 5)), "is_IN");
  chartInstance->c9_temporalCounter_i1 = c9_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 6)), "temporalCounter_i1");
  chartInstance->c9_previousTicks = c9_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 7)), "previousTicks");
  sf_mex_assign(&chartInstance->c9_setSimStateSideEffectsInfo,
                c9_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c9_u, 8)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c9_u);
  chartInstance->c9_doSetSimStateSideEffects = 1U;
  c9_update_debugger_state_c9_FSAC2021_V1_Running(chartInstance);
  sf_mex_destroy(&c9_st);
}

static void c9_set_sim_state_side_effects_c9_FSAC2021_V1_Running
  (SFc9_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  if (chartInstance->c9_doSetSimStateSideEffects != 0) {
    if (chartInstance->c9_is_c9_FSAC2021_V1_Running == c9_IN_IN) {
      chartInstance->c9_tp_IN = 1U;
      if (sf_mex_sub(chartInstance->c9_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 2) == 0.0) {
        chartInstance->c9_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c9_tp_IN = 0U;
    }

    if (chartInstance->c9_is_IN == c9_IN_Move) {
      chartInstance->c9_tp_Move = 1U;
    } else {
      chartInstance->c9_tp_Move = 0U;
    }

    if (chartInstance->c9_is_IN == c9_IN_Second) {
      chartInstance->c9_tp_Second = 1U;
    } else {
      chartInstance->c9_tp_Second = 0U;
    }

    if (chartInstance->c9_is_c9_FSAC2021_V1_Running == c9_IN_end) {
      chartInstance->c9_tp_end = 1U;
    } else {
      chartInstance->c9_tp_end = 0U;
    }

    if (chartInstance->c9_is_c9_FSAC2021_V1_Running == c9_IN_init) {
      chartInstance->c9_tp_init = 1U;
    } else {
      chartInstance->c9_tp_init = 0U;
    }

    chartInstance->c9_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c9_FSAC2021_V1_Running
  (SFc9_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c9_setSimStateSideEffectsInfo);
}

static void sf_gateway_c9_FSAC2021_V1_Running
  (SFc9_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  uint8_T *c9_Mission_Flag;
  real_T *c9_SteerCmd;
  real_T *c9_ACC;
  c9_ACC = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c9_SteerCmd = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_Mission_Flag = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c9_set_sim_state_side_effects_c9_FSAC2021_V1_Running(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c9_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.05
    + 0.5);
  chartInstance->c9_elapsedTicks = chartInstance->c9_presentTicks -
    chartInstance->c9_previousTicks;
  chartInstance->c9_previousTicks = chartInstance->c9_presentTicks;
  if ((uint32_T)chartInstance->c9_temporalCounter_i1 +
      chartInstance->c9_elapsedTicks <= 1023U) {
    chartInstance->c9_temporalCounter_i1 = (uint16_T)((uint32_T)
      chartInstance->c9_temporalCounter_i1 + chartInstance->c9_elapsedTicks);
  } else {
    chartInstance->c9_temporalCounter_i1 = 1023U;
  }

  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*c9_Mission_Flag, 0U);
  _SFD_DATA_RANGE_CHECK(*c9_SteerCmd, 1U);
  _SFD_DATA_RANGE_CHECK(*c9_ACC, 2U);
  chartInstance->c9_sfEvent = CALL_EVENT;
  c9_chartstep_c9_FSAC2021_V1_Running(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_FSAC2021_V1_RunningMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c9_chartstep_c9_FSAC2021_V1_Running
  (SFc9_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  uint32_T c9_debug_family_var_map[2];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 0.0;
  uint32_T c9_b_debug_family_var_map[3];
  real_T c9_b_nargin = 0.0;
  real_T c9_b_nargout = 1.0;
  boolean_T c9_out;
  real_T c9_c_nargin = 0.0;
  real_T c9_c_nargout = 0.0;
  real_T c9_d_nargin = 0.0;
  real_T c9_d_nargout = 1.0;
  boolean_T c9_b_out;
  real_T c9_e_nargin = 0.0;
  real_T c9_e_nargout = 0.0;
  real_T c9_f_nargin = 0.0;
  real_T c9_f_nargout = 1.0;
  boolean_T c9_c_out;
  real_T c9_g_nargin = 0.0;
  real_T c9_g_nargout = 0.0;
  real_T *c9_SteerCmd;
  real_T *c9_ACC;
  uint8_T *c9_Mission_Flag;
  c9_ACC = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c9_SteerCmd = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_Mission_Flag = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
  if (chartInstance->c9_is_active_c9_FSAC2021_V1_Running == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
    chartInstance->c9_is_active_c9_FSAC2021_V1_Running = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c9_sfEvent);
    chartInstance->c9_is_c9_FSAC2021_V1_Running = c9_IN_init;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c9_sfEvent);
    chartInstance->c9_tp_init = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_debug_family_names,
      c9_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_sf_marshallOut,
      c9_sf_marshallIn);
    *c9_SteerCmd = 0.0;
    c9_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_DATA_RANGE_CHECK(*c9_SteerCmd, 1U);
    *c9_ACC = 200.0;
    c9_updateDataWrittenToVector(chartInstance, 2U);
    _SFD_DATA_RANGE_CHECK(*c9_ACC, 2U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    switch (chartInstance->c9_is_c9_FSAC2021_V1_Running) {
     case c9_IN_IN:
      CV_CHART_EVAL(8, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                   chartInstance->c9_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_g_debug_family_names,
        c9_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargin, 0U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_nargout, 1U, c9_sf_marshallOut,
        c9_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_out, 2U, c9_b_sf_marshallOut,
        c9_b_sf_marshallIn);
      c9_out = CV_EML_IF(3, 0, 0, chartInstance->c9_temporalCounter_i1 >= 540);
      _SFD_SYMBOL_SCOPE_POP();
      if (c9_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
        c9_exit_internal_IN(chartInstance);
        chartInstance->c9_tp_IN = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c9_sfEvent);
        chartInstance->c9_is_c9_FSAC2021_V1_Running = c9_IN_end;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c9_sfEvent);
        chartInstance->c9_tp_end = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_d_debug_family_names,
          c9_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargin, 0U, c9_sf_marshallOut,
          c9_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_nargout, 1U,
          c9_sf_marshallOut, c9_sf_marshallIn);
        *c9_ACC = 0.0;
        c9_updateDataWrittenToVector(chartInstance, 2U);
        _SFD_DATA_RANGE_CHECK(*c9_ACC, 2U);
        *c9_SteerCmd = 0.0;
        c9_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_DATA_RANGE_CHECK(*c9_SteerCmd, 1U);
        *c9_Mission_Flag = 1U;
        c9_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK((real_T)*c9_Mission_Flag, 0U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                     chartInstance->c9_sfEvent);
        switch (chartInstance->c9_is_IN) {
         case c9_IN_Move:
          CV_STATE_EVAL(0, 0, 1);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U,
                       chartInstance->c9_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_e_debug_family_names,
            c9_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_nargin, 0U,
            c9_sf_marshallOut, c9_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_d_nargout, 1U,
            c9_sf_marshallOut, c9_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b_out, 2U,
            c9_b_sf_marshallOut, c9_b_sf_marshallIn);
          c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 1U);
          c9_b_out = CV_EML_IF(0, 0, 0, *c9_SteerCmd >= 110.0);
          _SFD_SYMBOL_SCOPE_POP();
          if (c9_b_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c9_sfEvent);
            chartInstance->c9_tp_Move = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c9_sfEvent);
            chartInstance->c9_is_IN = c9_IN_Second;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c9_sfEvent);
            chartInstance->c9_tp_Second = 1U;
          } else {
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                         chartInstance->c9_sfEvent);
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_c_debug_family_names,
              c9_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_nargin, 0U,
              c9_sf_marshallOut, c9_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_e_nargout, 1U,
              c9_sf_marshallOut, c9_sf_marshallIn);
            c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 1U);
            *c9_SteerCmd += 4.5;
            c9_updateDataWrittenToVector(chartInstance, 1U);
            _SFD_DATA_RANGE_CHECK(*c9_SteerCmd, 1U);
            _SFD_SYMBOL_SCOPE_POP();
          }

          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c9_sfEvent);
          break;

         case c9_IN_Second:
          CV_STATE_EVAL(0, 0, 2);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                       chartInstance->c9_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_f_debug_family_names,
            c9_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f_nargin, 0U,
            c9_sf_marshallOut, c9_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_f_nargout, 1U,
            c9_sf_marshallOut, c9_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c_out, 2U,
            c9_b_sf_marshallOut, c9_b_sf_marshallIn);
          c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 1U);
          c9_c_out = CV_EML_IF(1, 0, 0, *c9_SteerCmd <= -110.0);
          _SFD_SYMBOL_SCOPE_POP();
          if (c9_c_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c9_sfEvent);
            chartInstance->c9_tp_Second = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c9_sfEvent);
            chartInstance->c9_is_IN = c9_IN_Move;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c9_sfEvent);
            chartInstance->c9_tp_Move = 1U;
          } else {
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                         chartInstance->c9_sfEvent);
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c9_b_debug_family_names,
              c9_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_g_nargin, 0U,
              c9_sf_marshallOut, c9_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_g_nargout, 1U,
              c9_sf_marshallOut, c9_sf_marshallIn);
            c9_errorIfDataNotWrittenToFcn(chartInstance, 1U, 1U);
            *c9_SteerCmd -= 4.5;
            c9_updateDataWrittenToVector(chartInstance, 1U);
            _SFD_DATA_RANGE_CHECK(*c9_SteerCmd, 1U);
            _SFD_SYMBOL_SCOPE_POP();
          }

          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c9_sfEvent);
          break;

         default:
          CV_STATE_EVAL(0, 0, 0);
          chartInstance->c9_is_IN = c9_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c9_sfEvent);
          break;
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c9_sfEvent);
      break;

     case c9_IN_end:
      CV_CHART_EVAL(8, 0, 2);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                   chartInstance->c9_sfEvent);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c9_sfEvent);
      break;

     case c9_IN_init:
      CV_CHART_EVAL(8, 0, 3);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_init = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c9_sfEvent);
      chartInstance->c9_is_c9_FSAC2021_V1_Running = c9_IN_IN;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c9_sfEvent);
      chartInstance->c9_temporalCounter_i1 = 0U;
      chartInstance->c9_tp_IN = 1U;
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c9_sfEvent);
      chartInstance->c9_is_IN = c9_IN_Move;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c9_sfEvent);
      chartInstance->c9_tp_Move = 1U;
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c9_sfEvent);
      break;

     default:
      CV_CHART_EVAL(8, 0, 0);
      chartInstance->c9_is_c9_FSAC2021_V1_Running = c9_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c9_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
}

static void initSimStructsc9_FSAC2021_V1_Running
  (SFc9_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c9_exit_internal_IN(SFc9_FSAC2021_V1_RunningInstanceStruct
  *chartInstance)
{
  switch (chartInstance->c9_is_IN) {
   case c9_IN_Move:
    CV_STATE_EVAL(0, 1, 1);
    chartInstance->c9_tp_Move = 0U;
    chartInstance->c9_is_IN = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c9_sfEvent);
    break;

   case c9_IN_Second:
    CV_STATE_EVAL(0, 1, 2);
    chartInstance->c9_tp_Second = 0U;
    chartInstance->c9_is_IN = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c9_sfEvent);
    break;

   default:
    CV_STATE_EVAL(0, 1, 0);
    chartInstance->c9_is_IN = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c9_sfEvent);
    break;
  }
}

static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber, uint32_T c9_instanceNumber)
{
  (void)c9_machineNumber;
  (void)c9_chartNumber;
  (void)c9_instanceNumber;
}

static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  real_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  chartInstance = (SFc9_FSAC2021_V1_RunningInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(real_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static real_T c9_emlrt_marshallIn(SFc9_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c9_nargout, const char_T *c9_identifier)
{
  real_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_nargout), &c9_thisId);
  sf_mex_destroy(&c9_nargout);
  return c9_y;
}

static real_T c9_b_emlrt_marshallIn(SFc9_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  real_T c9_y;
  real_T c9_d0;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_d0, 1, 0, 0U, 0, 0U, 0);
  c9_y = c9_d0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_nargout;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y;
  SFc9_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  chartInstance = (SFc9_FSAC2021_V1_RunningInstanceStruct *)chartInstanceVoid;
  c9_nargout = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_nargout), &c9_thisId);
  sf_mex_destroy(&c9_nargout);
  *(real_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  boolean_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  chartInstance = (SFc9_FSAC2021_V1_RunningInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(boolean_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static boolean_T c9_c_emlrt_marshallIn(SFc9_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  boolean_T c9_y;
  boolean_T c9_b0;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_b0, 1, 11, 0U, 0, 0U, 0);
  c9_y = c9_b0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_sf_internal_predicateOutput;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  boolean_T c9_y;
  SFc9_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  chartInstance = (SFc9_FSAC2021_V1_RunningInstanceStruct *)chartInstanceVoid;
  c9_sf_internal_predicateOutput = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_sf_internal_predicateOutput), &c9_thisId);
  sf_mex_destroy(&c9_sf_internal_predicateOutput);
  *(boolean_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

const mxArray *sf_c9_FSAC2021_V1_Running_get_eml_resolved_functions_info(void)
{
  const mxArray *c9_nameCaptureInfo = NULL;
  c9_nameCaptureInfo = NULL;
  sf_mex_assign(&c9_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c9_nameCaptureInfo;
}

static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  chartInstance = (SFc9_FSAC2021_V1_RunningInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(int32_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static int32_T c9_d_emlrt_marshallIn(SFc9_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  int32_T c9_y;
  int32_T c9_i0;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_i0, 1, 6, 0U, 0, 0U, 0);
  c9_y = c9_i0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_sfEvent;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  int32_T c9_y;
  SFc9_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  chartInstance = (SFc9_FSAC2021_V1_RunningInstanceStruct *)chartInstanceVoid;
  c9_b_sfEvent = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_sfEvent),
    &c9_thisId);
  sf_mex_destroy(&c9_b_sfEvent);
  *(int32_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  uint8_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  chartInstance = (SFc9_FSAC2021_V1_RunningInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(uint8_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static uint8_T c9_e_emlrt_marshallIn(SFc9_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c9_b_tp_init, const char_T *c9_identifier)
{
  uint8_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_tp_init),
    &c9_thisId);
  sf_mex_destroy(&c9_b_tp_init);
  return c9_y;
}

static uint8_T c9_f_emlrt_marshallIn(SFc9_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint8_T c9_y;
  uint8_T c9_u0;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u0, 1, 3, 0U, 0, 0U, 0);
  c9_y = c9_u0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_tp_init;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  uint8_T c9_y;
  SFc9_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  chartInstance = (SFc9_FSAC2021_V1_RunningInstanceStruct *)chartInstanceVoid;
  c9_b_tp_init = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_tp_init),
    &c9_thisId);
  sf_mex_destroy(&c9_b_tp_init);
  *(uint8_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static uint16_T c9_g_emlrt_marshallIn(SFc9_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c9_b_temporalCounter_i1, const char_T
  *c9_identifier)
{
  uint16_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_temporalCounter_i1),
    &c9_thisId);
  sf_mex_destroy(&c9_b_temporalCounter_i1);
  return c9_y;
}

static uint16_T c9_h_emlrt_marshallIn(SFc9_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint16_T c9_y;
  uint16_T c9_u1;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u1, 1, 5, 0U, 0, 0U, 0);
  c9_y = c9_u1;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static uint32_T c9_i_emlrt_marshallIn(SFc9_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c9_b_previousTicks, const char_T *c9_identifier)
{
  uint32_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_previousTicks),
    &c9_thisId);
  sf_mex_destroy(&c9_b_previousTicks);
  return c9_y;
}

static uint32_T c9_j_emlrt_marshallIn(SFc9_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint32_T c9_y;
  uint32_T c9_u2;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u2, 1, 7, 0U, 0, 0U, 0);
  c9_y = c9_u2;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static const mxArray *c9_k_emlrt_marshallIn
  (SFc9_FSAC2021_V1_RunningInstanceStruct *chartInstance, const mxArray
   *c9_b_setSimStateSideEffectsInfo, const char_T *c9_identifier)
{
  const mxArray *c9_y = NULL;
  emlrtMsgIdentifier c9_thisId;
  c9_y = NULL;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  sf_mex_assign(&c9_y, c9_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_b_setSimStateSideEffectsInfo), &c9_thisId), false);
  sf_mex_destroy(&c9_b_setSimStateSideEffectsInfo);
  return c9_y;
}

static const mxArray *c9_l_emlrt_marshallIn
  (SFc9_FSAC2021_V1_RunningInstanceStruct *chartInstance, const mxArray *c9_u,
   const emlrtMsgIdentifier *c9_parentId)
{
  const mxArray *c9_y = NULL;
  (void)chartInstance;
  (void)c9_parentId;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_duplicatearraysafe(&c9_u), false);
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_updateDataWrittenToVector(SFc9_FSAC2021_V1_RunningInstanceStruct *
  chartInstance, uint32_T c9_vectorIndex)
{
  (void)chartInstance;
  c9_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c9_vectorIndex, 0, 2, 1, 0)] = true;
}

static void c9_errorIfDataNotWrittenToFcn(SFc9_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, uint32_T c9_vectorIndex, uint32_T c9_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c9_dataNumber, c9_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c9_vectorIndex, 0, 2, 1,
    0)]);
}

static void init_dsm_address_info(SFc9_FSAC2021_V1_RunningInstanceStruct
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

void sf_c9_FSAC2021_V1_Running_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(914928895U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(373832236U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2639233275U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1334127256U);
}

mxArray *sf_c9_FSAC2021_V1_Running_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("467Zgn3wZzxSbQd3dHF8qE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c9_FSAC2021_V1_Running_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c9_FSAC2021_V1_Running_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c9_FSAC2021_V1_Running(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x8'type','srcId','name','auxInfo'{{M[1],M[38],T\"ACC\",},{M[1],M[13],T\"Mission_Flag\",},{M[1],M[14],T\"SteerCmd\",},{M[8],M[0],T\"is_active_c9_FSAC2021_V1_Running\",},{M[9],M[0],T\"is_c9_FSAC2021_V1_Running\",},{M[9],M[30],T\"is_IN\",},{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"at\",M[30],M[1]}}},{M[13],M[0],T\"previousTicks\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 8, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_FSAC2021_V1_Running_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc9_FSAC2021_V1_RunningInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc9_FSAC2021_V1_RunningInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _FSAC2021_V1_RunningMachineNumber_,
           9,
           5,
           6,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"Mission_Flag");
          _SFD_SET_DATA_PROPS(1,2,0,1,"SteerCmd");
          _SFD_SET_DATA_PROPS(2,2,0,1,"ACC");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_CH_SUBSTATE_COUNT(3);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,3);
          _SFD_CH_SUBSTATE_INDEX(2,4);
          _SFD_ST_SUBSTATE_COUNT(0,2);
          _SFD_ST_SUBSTATE_INDEX(0,0,1);
          _SFD_ST_SUBSTATE_INDEX(0,1,2);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
        }

        _SFD_CV_INIT_CHART(3,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,2,1,1,0,0,NULL,NULL);
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

        {
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(0,0,0,1,14,1,14);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,17,1,17);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,1,14,1,14);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_d_sf_marshallOut,(MexInFcnForType)c9_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);

        {
          uint8_T *c9_Mission_Flag;
          real_T *c9_SteerCmd;
          real_T *c9_ACC;
          c9_ACC = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c9_SteerCmd = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c9_Mission_Flag = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c9_Mission_Flag);
          _SFD_SET_DATA_VALUE_PTR(1U, c9_SteerCmd);
          _SFD_SET_DATA_VALUE_PTR(2U, c9_ACC);
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
  return "SrRP4KwcHDQlV67bbDVQjF";
}

static void sf_opaque_initialize_c9_FSAC2021_V1_Running(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc9_FSAC2021_V1_RunningInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c9_FSAC2021_V1_Running
    ((SFc9_FSAC2021_V1_RunningInstanceStruct*) chartInstanceVar);
  initialize_c9_FSAC2021_V1_Running((SFc9_FSAC2021_V1_RunningInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c9_FSAC2021_V1_Running(void *chartInstanceVar)
{
  enable_c9_FSAC2021_V1_Running((SFc9_FSAC2021_V1_RunningInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c9_FSAC2021_V1_Running(void *chartInstanceVar)
{
  disable_c9_FSAC2021_V1_Running((SFc9_FSAC2021_V1_RunningInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c9_FSAC2021_V1_Running(void *chartInstanceVar)
{
  sf_gateway_c9_FSAC2021_V1_Running((SFc9_FSAC2021_V1_RunningInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c9_FSAC2021_V1_Running(SimStruct*
  S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c9_FSAC2021_V1_Running
    ((SFc9_FSAC2021_V1_RunningInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c9_FSAC2021_V1_Running();/* state var info */
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

extern void sf_internal_set_sim_state_c9_FSAC2021_V1_Running(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c9_FSAC2021_V1_Running();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c9_FSAC2021_V1_Running((SFc9_FSAC2021_V1_RunningInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c9_FSAC2021_V1_Running(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c9_FSAC2021_V1_Running(S);
}

static void sf_opaque_set_sim_state_c9_FSAC2021_V1_Running(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c9_FSAC2021_V1_Running(S, st);
}

static void sf_opaque_terminate_c9_FSAC2021_V1_Running(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc9_FSAC2021_V1_RunningInstanceStruct*) chartInstanceVar
      )->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_FSAC2021_V1_Running_optimization_info();
    }

    finalize_c9_FSAC2021_V1_Running((SFc9_FSAC2021_V1_RunningInstanceStruct*)
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
  initSimStructsc9_FSAC2021_V1_Running((SFc9_FSAC2021_V1_RunningInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c9_FSAC2021_V1_Running(SimStruct *S)
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
    initialize_params_c9_FSAC2021_V1_Running
      ((SFc9_FSAC2021_V1_RunningInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c9_FSAC2021_V1_Running(SimStruct *S)
{
  ssSetNeedAbsoluteTime(S,1);
  ssSetModelReferenceSampleTimeDisallowInheritance(S);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_FSAC2021_V1_Running_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,9);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,9,"RTWCG"));
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,9,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,9);
    if (chartIsInlinable) {
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,9,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,9);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1240119165U));
  ssSetChecksum1(S,(3899206204U));
  ssSetChecksum2(S,(2834996787U));
  ssSetChecksum3(S,(1695499763U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c9_FSAC2021_V1_Running(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c9_FSAC2021_V1_Running(SimStruct *S)
{
  SFc9_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc9_FSAC2021_V1_RunningInstanceStruct *)utMalloc(sizeof
    (SFc9_FSAC2021_V1_RunningInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc9_FSAC2021_V1_RunningInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c9_FSAC2021_V1_Running;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c9_FSAC2021_V1_Running;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c9_FSAC2021_V1_Running;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c9_FSAC2021_V1_Running;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c9_FSAC2021_V1_Running;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c9_FSAC2021_V1_Running;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c9_FSAC2021_V1_Running;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c9_FSAC2021_V1_Running;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c9_FSAC2021_V1_Running;
  chartInstance->chartInfo.mdlStart = mdlStart_c9_FSAC2021_V1_Running;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c9_FSAC2021_V1_Running;
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

void c9_FSAC2021_V1_Running_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c9_FSAC2021_V1_Running(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_FSAC2021_V1_Running(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_FSAC2021_V1_Running(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_FSAC2021_V1_Running_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
