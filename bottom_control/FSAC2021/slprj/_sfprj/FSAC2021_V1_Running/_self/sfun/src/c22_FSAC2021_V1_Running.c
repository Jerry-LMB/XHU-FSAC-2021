/* Include files */

#include <stddef.h>
#include "blas.h"
#include "FSAC2021_V1_Running_sfun.h"
#include "c22_FSAC2021_V1_Running.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "FSAC2021_V1_Running_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c22_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c22_IN_Idle                    ((uint8_T)1U)
#define c22_IN_RunMode                 ((uint8_T)2U)
#define c22_IN_BackOrigin              ((uint8_T)1U)
#define c22_IN_Init                    ((uint8_T)2U)
#define c22_IN_Move                    ((uint8_T)3U)
#define c22_IN_Tozeros                 ((uint8_T)4U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;

/* Function Declarations */
static void initialize_c22_FSAC2021_V1_Running
  (SFc22_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void initialize_params_c22_FSAC2021_V1_Running
  (SFc22_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void enable_c22_FSAC2021_V1_Running
  (SFc22_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void disable_c22_FSAC2021_V1_Running
  (SFc22_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void c22_update_debugger_state_c22_FSAC2021_V1_Running
  (SFc22_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c22_FSAC2021_V1_Running
  (SFc22_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void set_sim_state_c22_FSAC2021_V1_Running
  (SFc22_FSAC2021_V1_RunningInstanceStruct *chartInstance, const mxArray *c22_st);
static void c22_set_sim_state_side_effects_c22_FSAC2021_V1_Running
  (SFc22_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void finalize_c22_FSAC2021_V1_Running
  (SFc22_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void sf_gateway_c22_FSAC2021_V1_Running
  (SFc22_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void initSimStructsc22_FSAC2021_V1_Running
  (SFc22_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c22_machineNumber, uint32_T
  c22_chartNumber, uint32_T c22_instanceNumber);
static const mxArray *c22_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData);
static int32_T c22_emlrt_marshallIn(SFc22_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId);
static void c22_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData);
static const mxArray *c22_b_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData);
static uint8_T c22_b_emlrt_marshallIn(SFc22_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c22_b_tp_RunMode, const char_T *c22_identifier);
static uint8_T c22_c_emlrt_marshallIn(SFc22_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId);
static void c22_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData);
static const mxArray *c22_c_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData);
static real32_T c22_d_emlrt_marshallIn(SFc22_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId);
static void c22_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData);
static const mxArray *c22_d_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData);
static uint32_T c22_e_emlrt_marshallIn(SFc22_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c22_b_previousTicks, const char_T
  *c22_identifier);
static uint32_T c22_f_emlrt_marshallIn(SFc22_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId);
static const mxArray *c22_g_emlrt_marshallIn
  (SFc22_FSAC2021_V1_RunningInstanceStruct *chartInstance, const mxArray
   *c22_b_setSimStateSideEffectsInfo, const char_T *c22_identifier);
static const mxArray *c22_h_emlrt_marshallIn
  (SFc22_FSAC2021_V1_RunningInstanceStruct *chartInstance, const mxArray *c22_u,
   const emlrtMsgIdentifier *c22_parentId);
static void init_dsm_address_info(SFc22_FSAC2021_V1_RunningInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c22_FSAC2021_V1_Running
  (SFc22_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  uint8_T *c22_Allow_Ctrl_Flg;
  uint8_T *c22_Brk_Ctrl_State;
  c22_Brk_Ctrl_State = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c22_Allow_Ctrl_Flg = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c22_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c22_doSetSimStateSideEffects = 0U;
  chartInstance->c22_setSimStateSideEffectsInfo = NULL;
  chartInstance->c22_tp_Idle = 0U;
  chartInstance->c22_is_RunMode = c22_IN_NO_ACTIVE_CHILD;
  chartInstance->c22_tp_RunMode = 0U;
  chartInstance->c22_tp_BackOrigin = 0U;
  chartInstance->c22_tp_Init = 0U;
  chartInstance->c22_tp_Move = 0U;
  chartInstance->c22_tp_Tozeros = 0U;
  chartInstance->c22_temporalCounter_i1 = 0U;
  chartInstance->c22_is_active_c22_FSAC2021_V1_Running = 0U;
  chartInstance->c22_is_c22_FSAC2021_V1_Running = c22_IN_NO_ACTIVE_CHILD;
  if (!(sf_get_output_port_reusable(chartInstance->S, 1) != 0)) {
    *c22_Allow_Ctrl_Flg = 0U;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 2) != 0)) {
    *c22_Brk_Ctrl_State = 0U;
  }

  chartInstance->c22_presentTicks = 0U;
  chartInstance->c22_elapsedTicks = 0U;
  chartInstance->c22_previousTicks = 0U;
}

static void initialize_params_c22_FSAC2021_V1_Running
  (SFc22_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  real_T c22_d0;
  real_T c22_d1;
  real_T c22_d2;
  real_T c22_d3;
  real_T c22_d4;
  real_T c22_d5;
  sf_mex_import_named("BRK_DISPSENS_LOWLIMIT", sf_mex_get_sfun_param
                      (chartInstance->S, 0, 0), &c22_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c22_BRK_DISPSENS_LOWLIMIT = (real32_T)c22_d0;
  sf_mex_import_named("ENABLE", sf_mex_get_sfun_param(chartInstance->S, 5, 0),
                      &c22_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c22_ENABLE = (uint8_T)c22_d1;
  sf_mex_import_named("BRK_ENGAGED", sf_mex_get_sfun_param(chartInstance->S, 1,
    0), &c22_d2, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c22_BRK_ENGAGED = (uint8_T)c22_d2;
  sf_mex_import_named("BRK_TOZERO", sf_mex_get_sfun_param(chartInstance->S, 3, 0),
                      &c22_d3, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c22_BRK_TOZERO = (uint8_T)c22_d3;
  sf_mex_import_named("BRK_MOVE", sf_mex_get_sfun_param(chartInstance->S, 2, 0),
                      &c22_d4, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c22_BRK_MOVE = (uint8_T)c22_d4;
  sf_mex_import_named("DISABLE", sf_mex_get_sfun_param(chartInstance->S, 4, 0),
                      &c22_d5, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c22_DISABLE = (uint8_T)c22_d5;
}

static void enable_c22_FSAC2021_V1_Running
  (SFc22_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_enable(chartInstance->S, 0, "Brk_Mtr_BackOrigin", 0);
  sf_call_output_fcn_enable(chartInstance->S, 1, "Brk_Mtr_Enable", 0);
  chartInstance->c22_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ /
    0.05 + 0.5);
  chartInstance->c22_previousTicks = chartInstance->c22_presentTicks;
}

static void disable_c22_FSAC2021_V1_Running
  (SFc22_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c22_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ /
    0.05 + 0.5);
  chartInstance->c22_elapsedTicks = chartInstance->c22_presentTicks -
    chartInstance->c22_previousTicks;
  chartInstance->c22_previousTicks = chartInstance->c22_presentTicks;
  if ((uint32_T)chartInstance->c22_temporalCounter_i1 +
      chartInstance->c22_elapsedTicks <= 15U) {
    chartInstance->c22_temporalCounter_i1 = (uint8_T)((uint32_T)
      chartInstance->c22_temporalCounter_i1 + chartInstance->c22_elapsedTicks);
  } else {
    chartInstance->c22_temporalCounter_i1 = 15U;
  }

  sf_call_output_fcn_disable(chartInstance->S, 0, "Brk_Mtr_BackOrigin", 0);
  sf_call_output_fcn_disable(chartInstance->S, 1, "Brk_Mtr_Enable", 0);
}

static void c22_update_debugger_state_c22_FSAC2021_V1_Running
  (SFc22_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  uint32_T c22_prevAniVal;
  c22_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c22_is_active_c22_FSAC2021_V1_Running == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 21U, chartInstance->c22_sfEvent);
  }

  if (chartInstance->c22_is_c22_FSAC2021_V1_Running == c22_IN_RunMode) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c22_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c22_sfEvent);
  }

  if (chartInstance->c22_is_RunMode == c22_IN_Init) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c22_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c22_sfEvent);
  }

  if (chartInstance->c22_is_RunMode == c22_IN_BackOrigin) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c22_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c22_sfEvent);
  }

  if (chartInstance->c22_is_RunMode == c22_IN_Tozeros) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c22_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c22_sfEvent);
  }

  if (chartInstance->c22_is_RunMode == c22_IN_Move) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c22_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c22_sfEvent);
  }

  if (chartInstance->c22_is_c22_FSAC2021_V1_Running == c22_IN_Idle) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c22_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c22_sfEvent);
  }

  _SFD_SET_ANIMATION(c22_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c22_FSAC2021_V1_Running
  (SFc22_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  const mxArray *c22_st;
  const mxArray *c22_y = NULL;
  uint8_T c22_hoistedGlobal;
  uint8_T c22_u;
  const mxArray *c22_b_y = NULL;
  uint8_T c22_b_hoistedGlobal;
  uint8_T c22_b_u;
  const mxArray *c22_c_y = NULL;
  uint8_T c22_c_hoistedGlobal;
  uint8_T c22_c_u;
  const mxArray *c22_d_y = NULL;
  uint8_T c22_d_hoistedGlobal;
  uint8_T c22_d_u;
  const mxArray *c22_e_y = NULL;
  uint8_T c22_e_hoistedGlobal;
  uint8_T c22_e_u;
  const mxArray *c22_f_y = NULL;
  uint8_T c22_f_hoistedGlobal;
  uint8_T c22_f_u;
  const mxArray *c22_g_y = NULL;
  uint32_T c22_g_hoistedGlobal;
  uint32_T c22_g_u;
  const mxArray *c22_h_y = NULL;
  uint8_T *c22_Allow_Ctrl_Flg;
  uint8_T *c22_Brk_Ctrl_State;
  c22_Brk_Ctrl_State = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c22_Allow_Ctrl_Flg = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c22_st = NULL;
  c22_st = NULL;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_createcellmatrix(7, 1), false);
  c22_hoistedGlobal = *c22_Allow_Ctrl_Flg;
  c22_u = c22_hoistedGlobal;
  c22_b_y = NULL;
  sf_mex_assign(&c22_b_y, sf_mex_create("y", &c22_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c22_y, 0, c22_b_y);
  c22_b_hoistedGlobal = *c22_Brk_Ctrl_State;
  c22_b_u = c22_b_hoistedGlobal;
  c22_c_y = NULL;
  sf_mex_assign(&c22_c_y, sf_mex_create("y", &c22_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c22_y, 1, c22_c_y);
  c22_c_hoistedGlobal = chartInstance->c22_is_active_c22_FSAC2021_V1_Running;
  c22_c_u = c22_c_hoistedGlobal;
  c22_d_y = NULL;
  sf_mex_assign(&c22_d_y, sf_mex_create("y", &c22_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c22_y, 2, c22_d_y);
  c22_d_hoistedGlobal = chartInstance->c22_is_c22_FSAC2021_V1_Running;
  c22_d_u = c22_d_hoistedGlobal;
  c22_e_y = NULL;
  sf_mex_assign(&c22_e_y, sf_mex_create("y", &c22_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c22_y, 3, c22_e_y);
  c22_e_hoistedGlobal = chartInstance->c22_is_RunMode;
  c22_e_u = c22_e_hoistedGlobal;
  c22_f_y = NULL;
  sf_mex_assign(&c22_f_y, sf_mex_create("y", &c22_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c22_y, 4, c22_f_y);
  c22_f_hoistedGlobal = chartInstance->c22_temporalCounter_i1;
  c22_f_u = c22_f_hoistedGlobal;
  c22_g_y = NULL;
  sf_mex_assign(&c22_g_y, sf_mex_create("y", &c22_f_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c22_y, 5, c22_g_y);
  c22_g_hoistedGlobal = chartInstance->c22_previousTicks;
  c22_g_u = c22_g_hoistedGlobal;
  c22_h_y = NULL;
  sf_mex_assign(&c22_h_y, sf_mex_create("y", &c22_g_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c22_y, 6, c22_h_y);
  sf_mex_assign(&c22_st, c22_y, false);
  return c22_st;
}

static void set_sim_state_c22_FSAC2021_V1_Running
  (SFc22_FSAC2021_V1_RunningInstanceStruct *chartInstance, const mxArray *c22_st)
{
  const mxArray *c22_u;
  uint8_T *c22_Allow_Ctrl_Flg;
  uint8_T *c22_Brk_Ctrl_State;
  c22_Brk_Ctrl_State = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c22_Allow_Ctrl_Flg = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c22_u = sf_mex_dup(c22_st);
  *c22_Allow_Ctrl_Flg = c22_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c22_u, 0)), "Allow_Ctrl_Flg");
  *c22_Brk_Ctrl_State = c22_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c22_u, 1)), "Brk_Ctrl_State");
  chartInstance->c22_is_active_c22_FSAC2021_V1_Running = c22_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c22_u, 2)),
     "is_active_c22_FSAC2021_V1_Running");
  chartInstance->c22_is_c22_FSAC2021_V1_Running = c22_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c22_u, 3)),
     "is_c22_FSAC2021_V1_Running");
  chartInstance->c22_is_RunMode = c22_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c22_u, 4)), "is_RunMode");
  chartInstance->c22_temporalCounter_i1 = c22_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c22_u, 5)), "temporalCounter_i1");
  chartInstance->c22_previousTicks = c22_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c22_u, 6)), "previousTicks");
  sf_mex_assign(&chartInstance->c22_setSimStateSideEffectsInfo,
                c22_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c22_u, 7)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c22_u);
  chartInstance->c22_doSetSimStateSideEffects = 1U;
  c22_update_debugger_state_c22_FSAC2021_V1_Running(chartInstance);
  sf_mex_destroy(&c22_st);
}

static void c22_set_sim_state_side_effects_c22_FSAC2021_V1_Running
  (SFc22_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  if (chartInstance->c22_doSetSimStateSideEffects != 0) {
    if (chartInstance->c22_is_c22_FSAC2021_V1_Running == c22_IN_Idle) {
      chartInstance->c22_tp_Idle = 1U;
    } else {
      chartInstance->c22_tp_Idle = 0U;
    }

    if (chartInstance->c22_is_c22_FSAC2021_V1_Running == c22_IN_RunMode) {
      chartInstance->c22_tp_RunMode = 1U;
    } else {
      chartInstance->c22_tp_RunMode = 0U;
    }

    if (chartInstance->c22_is_RunMode == c22_IN_BackOrigin) {
      chartInstance->c22_tp_BackOrigin = 1U;
    } else {
      chartInstance->c22_tp_BackOrigin = 0U;
    }

    if (chartInstance->c22_is_RunMode == c22_IN_Init) {
      chartInstance->c22_tp_Init = 1U;
    } else {
      chartInstance->c22_tp_Init = 0U;
    }

    if (chartInstance->c22_is_RunMode == c22_IN_Move) {
      chartInstance->c22_tp_Move = 1U;
    } else {
      chartInstance->c22_tp_Move = 0U;
    }

    if (chartInstance->c22_is_RunMode == c22_IN_Tozeros) {
      chartInstance->c22_tp_Tozeros = 1U;
      if (sf_mex_sub(chartInstance->c22_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 7) == 0.0) {
        chartInstance->c22_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c22_tp_Tozeros = 0U;
    }

    chartInstance->c22_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c22_FSAC2021_V1_Running
  (SFc22_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c22_setSimStateSideEffectsInfo);
}

static void sf_gateway_c22_FSAC2021_V1_Running
  (SFc22_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  boolean_T c22_out;
  boolean_T c22_temp;
  boolean_T c22_b_out;
  boolean_T c22_b_temp;
  boolean_T c22_c_out;
  uint8_T *c22_Brk_Mtr_Enable_Flg;
  uint8_T *c22_Allow_Ctrl_Flg;
  uint8_T *c22_Brk_Ctrl_State;
  uint8_T *c22_ASSI_State;
  real_T *c22_Brk_Mtr_Origin_Flag;
  c22_Brk_Mtr_Origin_Flag = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c22_ASSI_State = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c22_Brk_Ctrl_State = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c22_Allow_Ctrl_Flg = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c22_Brk_Mtr_Enable_Flg = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c22_set_sim_state_side_effects_c22_FSAC2021_V1_Running(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c22_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ /
    0.05 + 0.5);
  chartInstance->c22_elapsedTicks = chartInstance->c22_presentTicks -
    chartInstance->c22_previousTicks;
  chartInstance->c22_previousTicks = chartInstance->c22_presentTicks;
  if ((uint32_T)chartInstance->c22_temporalCounter_i1 +
      chartInstance->c22_elapsedTicks <= 15U) {
    chartInstance->c22_temporalCounter_i1 = (uint8_T)((uint32_T)
      chartInstance->c22_temporalCounter_i1 + chartInstance->c22_elapsedTicks);
  } else {
    chartInstance->c22_temporalCounter_i1 = 15U;
  }

  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 21U, chartInstance->c22_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*c22_Brk_Mtr_Enable_Flg, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c22_BRK_DISPSENS_LOWLIMIT, 1U);
  _SFD_DATA_RANGE_CHECK((real_T)*c22_Allow_Ctrl_Flg, 2U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c22_ENABLE, 3U);
  _SFD_DATA_RANGE_CHECK((real_T)*c22_Brk_Ctrl_State, 4U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c22_BRK_ENGAGED, 5U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c22_BRK_TOZERO, 6U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c22_BRK_MOVE, 7U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c22_DISABLE, 8U);
  _SFD_DATA_RANGE_CHECK((real_T)*c22_ASSI_State, 9U);
  _SFD_DATA_RANGE_CHECK(*c22_Brk_Mtr_Origin_Flag, 10U);
  chartInstance->c22_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 21U, chartInstance->c22_sfEvent);
  if (chartInstance->c22_is_active_c22_FSAC2021_V1_Running == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 21U, chartInstance->c22_sfEvent);
    chartInstance->c22_is_active_c22_FSAC2021_V1_Running = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 21U, chartInstance->c22_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c22_sfEvent);
    chartInstance->c22_is_c22_FSAC2021_V1_Running = c22_IN_Idle;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c22_sfEvent);
    chartInstance->c22_tp_Idle = 1U;
  } else {
    switch (chartInstance->c22_is_c22_FSAC2021_V1_Running) {
     case c22_IN_Idle:
      CV_CHART_EVAL(21, 0, 1);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c22_sfEvent);
      chartInstance->c22_tp_Idle = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c22_sfEvent);
      chartInstance->c22_is_c22_FSAC2021_V1_Running = c22_IN_RunMode;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c22_sfEvent);
      chartInstance->c22_tp_RunMode = 1U;
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c22_sfEvent);
      chartInstance->c22_is_RunMode = c22_IN_Init;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c22_sfEvent);
      chartInstance->c22_tp_Init = 1U;
      sf_call_output_fcn_call(chartInstance->S, 1, "Brk_Mtr_Enable", 0);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c22_sfEvent);
      break;

     case c22_IN_RunMode:
      CV_CHART_EVAL(21, 0, 2);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                   chartInstance->c22_sfEvent);
      switch (chartInstance->c22_is_RunMode) {
       case c22_IN_BackOrigin:
        CV_STATE_EVAL(1, 0, 1);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                     chartInstance->c22_sfEvent);
        c22_out = (CV_TRANSITION_EVAL(4U, (int32_T)_SFD_CCP_CALL(4U, 0,
          *c22_ASSI_State == 3 != 0U, chartInstance->c22_sfEvent)) != 0);
        if (c22_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c22_sfEvent);
          chartInstance->c22_tp_BackOrigin = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c22_sfEvent);
          chartInstance->c22_is_RunMode = c22_IN_Tozeros;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c22_sfEvent);
          chartInstance->c22_temporalCounter_i1 = 0U;
          chartInstance->c22_tp_Tozeros = 1U;
          *c22_Brk_Ctrl_State = 2U;
          _SFD_DATA_RANGE_CHECK((real_T)*c22_Brk_Ctrl_State, 4U);
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                       chartInstance->c22_sfEvent);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c22_sfEvent);
        break;

       case c22_IN_Init:
        CV_STATE_EVAL(1, 0, 2);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U,
                     chartInstance->c22_sfEvent);
        c22_temp = (_SFD_CCP_CALL(0U, 0, *c22_Brk_Mtr_Enable_Flg != 0U,
          chartInstance->c22_sfEvent) != 0);
        if (c22_temp) {
          c22_temp = (_SFD_CCP_CALL(0U, 1, *c22_ASSI_State == 2 != 0U,
            chartInstance->c22_sfEvent) != 0);
        }

        c22_b_out = (CV_TRANSITION_EVAL(0U, (int32_T)c22_temp) != 0);
        if (c22_b_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c22_sfEvent);
          chartInstance->c22_tp_Init = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c22_sfEvent);
          chartInstance->c22_is_RunMode = c22_IN_BackOrigin;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c22_sfEvent);
          chartInstance->c22_tp_BackOrigin = 1U;
          sf_call_output_fcn_call(chartInstance->S, 0, "Brk_Mtr_BackOrigin", 0);
          *c22_Brk_Ctrl_State = 1U;
          _SFD_DATA_RANGE_CHECK((real_T)*c22_Brk_Ctrl_State, 4U);
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                       chartInstance->c22_sfEvent);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c22_sfEvent);
        break;

       case c22_IN_Move:
        CV_STATE_EVAL(1, 0, 3);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                     chartInstance->c22_sfEvent);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c22_sfEvent);
        break;

       case c22_IN_Tozeros:
        CV_STATE_EVAL(1, 0, 4);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                     chartInstance->c22_sfEvent);
        c22_b_temp = (_SFD_CCP_CALL(5U, 0, 1 != 0U, chartInstance->c22_sfEvent)
                      != 0);
        if (c22_b_temp) {
          c22_b_temp = (_SFD_CCP_CALL(5U, 1,
            chartInstance->c22_temporalCounter_i1 >= 10U != 0U,
            chartInstance->c22_sfEvent) != 0);
        }

        c22_c_out = (CV_TRANSITION_EVAL(5U, (int32_T)c22_b_temp) != 0);
        if (c22_c_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c22_sfEvent);
          chartInstance->c22_tp_Tozeros = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c22_sfEvent);
          chartInstance->c22_is_RunMode = c22_IN_Move;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c22_sfEvent);
          chartInstance->c22_tp_Move = 1U;
          *c22_Allow_Ctrl_Flg = chartInstance->c22_ENABLE;
          _SFD_DATA_RANGE_CHECK((real_T)*c22_Allow_Ctrl_Flg, 2U);
          *c22_Brk_Ctrl_State = chartInstance->c22_BRK_MOVE;
          _SFD_DATA_RANGE_CHECK((real_T)*c22_Brk_Ctrl_State, 4U);
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                       chartInstance->c22_sfEvent);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c22_sfEvent);
        break;

       default:
        CV_STATE_EVAL(1, 0, 0);
        chartInstance->c22_is_RunMode = c22_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c22_sfEvent);
        break;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c22_sfEvent);
      break;

     default:
      CV_CHART_EVAL(21, 0, 0);
      chartInstance->c22_is_c22_FSAC2021_V1_Running = c22_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c22_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 21U, chartInstance->c22_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_FSAC2021_V1_RunningMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc22_FSAC2021_V1_Running
  (SFc22_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c22_machineNumber, uint32_T
  c22_chartNumber, uint32_T c22_instanceNumber)
{
  (void)c22_machineNumber;
  (void)c22_chartNumber;
  (void)c22_instanceNumber;
}

const mxArray *sf_c22_FSAC2021_V1_Running_get_eml_resolved_functions_info(void)
{
  const mxArray *c22_nameCaptureInfo = NULL;
  c22_nameCaptureInfo = NULL;
  sf_mex_assign(&c22_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c22_nameCaptureInfo;
}

static const mxArray *c22_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData)
{
  const mxArray *c22_mxArrayOutData = NULL;
  int32_T c22_u;
  const mxArray *c22_y = NULL;
  SFc22_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  chartInstance = (SFc22_FSAC2021_V1_RunningInstanceStruct *)chartInstanceVoid;
  c22_mxArrayOutData = NULL;
  c22_u = *(int32_T *)c22_inData;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", &c22_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c22_mxArrayOutData, c22_y, false);
  return c22_mxArrayOutData;
}

static int32_T c22_emlrt_marshallIn(SFc22_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId)
{
  int32_T c22_y;
  int32_T c22_i0;
  (void)chartInstance;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_u), &c22_i0, 1, 6, 0U, 0, 0U, 0);
  c22_y = c22_i0;
  sf_mex_destroy(&c22_u);
  return c22_y;
}

static void c22_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData)
{
  const mxArray *c22_b_sfEvent;
  const char_T *c22_identifier;
  emlrtMsgIdentifier c22_thisId;
  int32_T c22_y;
  SFc22_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  chartInstance = (SFc22_FSAC2021_V1_RunningInstanceStruct *)chartInstanceVoid;
  c22_b_sfEvent = sf_mex_dup(c22_mxArrayInData);
  c22_identifier = c22_varName;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_y = c22_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_b_sfEvent),
    &c22_thisId);
  sf_mex_destroy(&c22_b_sfEvent);
  *(int32_T *)c22_outData = c22_y;
  sf_mex_destroy(&c22_mxArrayInData);
}

static const mxArray *c22_b_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData)
{
  const mxArray *c22_mxArrayOutData = NULL;
  uint8_T c22_u;
  const mxArray *c22_y = NULL;
  SFc22_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  chartInstance = (SFc22_FSAC2021_V1_RunningInstanceStruct *)chartInstanceVoid;
  c22_mxArrayOutData = NULL;
  c22_u = *(uint8_T *)c22_inData;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", &c22_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c22_mxArrayOutData, c22_y, false);
  return c22_mxArrayOutData;
}

static uint8_T c22_b_emlrt_marshallIn(SFc22_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c22_b_tp_RunMode, const char_T *c22_identifier)
{
  uint8_T c22_y;
  emlrtMsgIdentifier c22_thisId;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_y = c22_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_b_tp_RunMode),
    &c22_thisId);
  sf_mex_destroy(&c22_b_tp_RunMode);
  return c22_y;
}

static uint8_T c22_c_emlrt_marshallIn(SFc22_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId)
{
  uint8_T c22_y;
  uint8_T c22_u0;
  (void)chartInstance;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_u), &c22_u0, 1, 3, 0U, 0, 0U, 0);
  c22_y = c22_u0;
  sf_mex_destroy(&c22_u);
  return c22_y;
}

static void c22_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData)
{
  const mxArray *c22_b_tp_RunMode;
  const char_T *c22_identifier;
  emlrtMsgIdentifier c22_thisId;
  uint8_T c22_y;
  SFc22_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  chartInstance = (SFc22_FSAC2021_V1_RunningInstanceStruct *)chartInstanceVoid;
  c22_b_tp_RunMode = sf_mex_dup(c22_mxArrayInData);
  c22_identifier = c22_varName;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_y = c22_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_b_tp_RunMode),
    &c22_thisId);
  sf_mex_destroy(&c22_b_tp_RunMode);
  *(uint8_T *)c22_outData = c22_y;
  sf_mex_destroy(&c22_mxArrayInData);
}

static const mxArray *c22_c_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData)
{
  const mxArray *c22_mxArrayOutData = NULL;
  real32_T c22_u;
  const mxArray *c22_y = NULL;
  SFc22_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  chartInstance = (SFc22_FSAC2021_V1_RunningInstanceStruct *)chartInstanceVoid;
  c22_mxArrayOutData = NULL;
  c22_u = *(real32_T *)c22_inData;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", &c22_u, 1, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c22_mxArrayOutData, c22_y, false);
  return c22_mxArrayOutData;
}

static real32_T c22_d_emlrt_marshallIn(SFc22_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId)
{
  real32_T c22_y;
  real32_T c22_f0;
  (void)chartInstance;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_u), &c22_f0, 1, 1, 0U, 0, 0U, 0);
  c22_y = c22_f0;
  sf_mex_destroy(&c22_u);
  return c22_y;
}

static void c22_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData)
{
  const mxArray *c22_b_BRK_DISPSENS_LOWLIMIT;
  const char_T *c22_identifier;
  emlrtMsgIdentifier c22_thisId;
  real32_T c22_y;
  SFc22_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  chartInstance = (SFc22_FSAC2021_V1_RunningInstanceStruct *)chartInstanceVoid;
  c22_b_BRK_DISPSENS_LOWLIMIT = sf_mex_dup(c22_mxArrayInData);
  c22_identifier = c22_varName;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_y = c22_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c22_b_BRK_DISPSENS_LOWLIMIT), &c22_thisId);
  sf_mex_destroy(&c22_b_BRK_DISPSENS_LOWLIMIT);
  *(real32_T *)c22_outData = c22_y;
  sf_mex_destroy(&c22_mxArrayInData);
}

static const mxArray *c22_d_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData)
{
  const mxArray *c22_mxArrayOutData = NULL;
  real_T c22_u;
  const mxArray *c22_y = NULL;
  SFc22_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  chartInstance = (SFc22_FSAC2021_V1_RunningInstanceStruct *)chartInstanceVoid;
  c22_mxArrayOutData = NULL;
  c22_u = *(real_T *)c22_inData;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", &c22_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c22_mxArrayOutData, c22_y, false);
  return c22_mxArrayOutData;
}

static uint32_T c22_e_emlrt_marshallIn(SFc22_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c22_b_previousTicks, const char_T
  *c22_identifier)
{
  uint32_T c22_y;
  emlrtMsgIdentifier c22_thisId;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_y = c22_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_b_previousTicks),
    &c22_thisId);
  sf_mex_destroy(&c22_b_previousTicks);
  return c22_y;
}

static uint32_T c22_f_emlrt_marshallIn(SFc22_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId)
{
  uint32_T c22_y;
  uint32_T c22_u1;
  (void)chartInstance;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_u), &c22_u1, 1, 7, 0U, 0, 0U, 0);
  c22_y = c22_u1;
  sf_mex_destroy(&c22_u);
  return c22_y;
}

static const mxArray *c22_g_emlrt_marshallIn
  (SFc22_FSAC2021_V1_RunningInstanceStruct *chartInstance, const mxArray
   *c22_b_setSimStateSideEffectsInfo, const char_T *c22_identifier)
{
  const mxArray *c22_y = NULL;
  emlrtMsgIdentifier c22_thisId;
  c22_y = NULL;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  sf_mex_assign(&c22_y, c22_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c22_b_setSimStateSideEffectsInfo), &c22_thisId), false);
  sf_mex_destroy(&c22_b_setSimStateSideEffectsInfo);
  return c22_y;
}

static const mxArray *c22_h_emlrt_marshallIn
  (SFc22_FSAC2021_V1_RunningInstanceStruct *chartInstance, const mxArray *c22_u,
   const emlrtMsgIdentifier *c22_parentId)
{
  const mxArray *c22_y = NULL;
  (void)chartInstance;
  (void)c22_parentId;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_duplicatearraysafe(&c22_u), false);
  sf_mex_destroy(&c22_u);
  return c22_y;
}

static void init_dsm_address_info(SFc22_FSAC2021_V1_RunningInstanceStruct
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

void sf_c22_FSAC2021_V1_Running_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3407541929U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4275291723U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(932835982U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2422096650U);
}

mxArray *sf_c22_FSAC2021_V1_Running_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("mKB5bNzSs5apYeQkXXX8KF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c22_FSAC2021_V1_Running_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c22_FSAC2021_V1_Running_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c22_FSAC2021_V1_Running(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[1],M[54],T\"Allow_Ctrl_Flg\",},{M[1],M[57],T\"Brk_Ctrl_State\",},{M[8],M[0],T\"is_active_c22_FSAC2021_V1_Running\",},{M[9],M[0],T\"is_c22_FSAC2021_V1_Running\",},{M[9],M[9],T\"is_RunMode\",},{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"at\",M[88],M[1]}}},{M[13],M[0],T\"previousTicks\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c22_FSAC2021_V1_Running_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc22_FSAC2021_V1_RunningInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc22_FSAC2021_V1_RunningInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _FSAC2021_V1_RunningMachineNumber_,
           22,
           6,
           6,
           0,
           11,
           2,
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
            2,
            2,
            2);
          _SFD_SET_DATA_PROPS(0,1,1,0,"Brk_Mtr_Enable_Flg");
          _SFD_SET_DATA_PROPS(1,10,0,0,"BRK_DISPSENS_LOWLIMIT");
          _SFD_SET_DATA_PROPS(2,2,0,1,"Allow_Ctrl_Flg");
          _SFD_SET_DATA_PROPS(3,10,0,0,"ENABLE");
          _SFD_SET_DATA_PROPS(4,2,0,1,"Brk_Ctrl_State");
          _SFD_SET_DATA_PROPS(5,10,0,0,"BRK_ENGAGED");
          _SFD_SET_DATA_PROPS(6,10,0,0,"BRK_TOZERO");
          _SFD_SET_DATA_PROPS(7,10,0,0,"BRK_MOVE");
          _SFD_SET_DATA_PROPS(8,10,0,0,"DISABLE");
          _SFD_SET_DATA_PROPS(9,1,1,0,"ASSI_State");
          _SFD_SET_DATA_PROPS(10,1,1,0,"Brk_Mtr_Origin_Flag");
          _SFD_EVENT_SCOPE(0,2);
          _SFD_EVENT_SCOPE(1,2);
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_CH_SUBSTATE_COUNT(2);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,4);
          _SFD_ST_SUBSTATE_INDEX(1,0,2);
          _SFD_ST_SUBSTATE_INDEX(1,1,3);
          _SFD_ST_SUBSTATE_INDEX(1,2,4);
          _SFD_ST_SUBSTATE_INDEX(1,3,5);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
        }

        _SFD_CV_INIT_CHART(2,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,4,1,0,0,0,NULL,NULL);
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

        {
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1, 23 };

          static unsigned int sEndGuardMap[] = { 19, 38 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(0,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 14 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(4,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 10, 0 };

          static unsigned int sEndGuardMap[] = { 13, 14 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(5,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c22_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c22_c_sf_marshallOut,(MexInFcnForType)
          c22_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c22_b_sf_marshallOut,(MexInFcnForType)
          c22_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c22_b_sf_marshallOut,(MexInFcnForType)
          c22_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c22_b_sf_marshallOut,(MexInFcnForType)
          c22_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c22_b_sf_marshallOut,(MexInFcnForType)
          c22_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c22_b_sf_marshallOut,(MexInFcnForType)
          c22_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c22_b_sf_marshallOut,(MexInFcnForType)
          c22_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c22_b_sf_marshallOut,(MexInFcnForType)
          c22_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c22_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c22_d_sf_marshallOut,(MexInFcnForType)NULL);

        {
          uint8_T *c22_Brk_Mtr_Enable_Flg;
          uint8_T *c22_Allow_Ctrl_Flg;
          uint8_T *c22_Brk_Ctrl_State;
          uint8_T *c22_ASSI_State;
          real_T *c22_Brk_Mtr_Origin_Flag;
          c22_Brk_Mtr_Origin_Flag = (real_T *)ssGetInputPortSignal
            (chartInstance->S, 2);
          c22_ASSI_State = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c22_Brk_Ctrl_State = (uint8_T *)ssGetOutputPortSignal(chartInstance->S,
            2);
          c22_Allow_Ctrl_Flg = (uint8_T *)ssGetOutputPortSignal(chartInstance->S,
            1);
          c22_Brk_Mtr_Enable_Flg = (uint8_T *)ssGetInputPortSignal
            (chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c22_Brk_Mtr_Enable_Flg);
          _SFD_SET_DATA_VALUE_PTR(1U, &chartInstance->c22_BRK_DISPSENS_LOWLIMIT);
          _SFD_SET_DATA_VALUE_PTR(2U, c22_Allow_Ctrl_Flg);
          _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c22_ENABLE);
          _SFD_SET_DATA_VALUE_PTR(4U, c22_Brk_Ctrl_State);
          _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance->c22_BRK_ENGAGED);
          _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance->c22_BRK_TOZERO);
          _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c22_BRK_MOVE);
          _SFD_SET_DATA_VALUE_PTR(8U, &chartInstance->c22_DISABLE);
          _SFD_SET_DATA_VALUE_PTR(9U, c22_ASSI_State);
          _SFD_SET_DATA_VALUE_PTR(10U, c22_Brk_Mtr_Origin_Flag);
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
  return "LNXSeAJLsAyxPauR01AHXC";
}

static void sf_opaque_initialize_c22_FSAC2021_V1_Running(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc22_FSAC2021_V1_RunningInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c22_FSAC2021_V1_Running
    ((SFc22_FSAC2021_V1_RunningInstanceStruct*) chartInstanceVar);
  initialize_c22_FSAC2021_V1_Running((SFc22_FSAC2021_V1_RunningInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c22_FSAC2021_V1_Running(void *chartInstanceVar)
{
  enable_c22_FSAC2021_V1_Running((SFc22_FSAC2021_V1_RunningInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c22_FSAC2021_V1_Running(void *chartInstanceVar)
{
  disable_c22_FSAC2021_V1_Running((SFc22_FSAC2021_V1_RunningInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c22_FSAC2021_V1_Running(void *chartInstanceVar)
{
  sf_gateway_c22_FSAC2021_V1_Running((SFc22_FSAC2021_V1_RunningInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c22_FSAC2021_V1_Running
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c22_FSAC2021_V1_Running
    ((SFc22_FSAC2021_V1_RunningInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c22_FSAC2021_V1_Running();/* state var info */
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

extern void sf_internal_set_sim_state_c22_FSAC2021_V1_Running(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c22_FSAC2021_V1_Running();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c22_FSAC2021_V1_Running((SFc22_FSAC2021_V1_RunningInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c22_FSAC2021_V1_Running(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c22_FSAC2021_V1_Running(S);
}

static void sf_opaque_set_sim_state_c22_FSAC2021_V1_Running(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c22_FSAC2021_V1_Running(S, st);
}

static void sf_opaque_terminate_c22_FSAC2021_V1_Running(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc22_FSAC2021_V1_RunningInstanceStruct*) chartInstanceVar
      )->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_FSAC2021_V1_Running_optimization_info();
    }

    finalize_c22_FSAC2021_V1_Running((SFc22_FSAC2021_V1_RunningInstanceStruct*)
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
  initSimStructsc22_FSAC2021_V1_Running((SFc22_FSAC2021_V1_RunningInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c22_FSAC2021_V1_Running(SimStruct *S)
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
    initialize_params_c22_FSAC2021_V1_Running
      ((SFc22_FSAC2021_V1_RunningInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c22_FSAC2021_V1_Running(SimStruct *S)
{
  /* Actual parameters from chart:
     BRK_DISPSENS_LOWLIMIT BRK_ENGAGED BRK_MOVE BRK_TOZERO DISABLE ENABLE
   */
  const char_T *rtParamNames[] = { "BRK_DISPSENS_LOWLIMIT", "BRK_ENGAGED",
    "BRK_MOVE", "BRK_TOZERO", "DISABLE", "ENABLE" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for BRK_DISPSENS_LOWLIMIT*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_SINGLE);

  /* registration for BRK_ENGAGED*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_UINT8);

  /* registration for BRK_MOVE*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_UINT8);

  /* registration for BRK_TOZERO*/
  ssRegDlgParamAsRunTimeParam(S, 3, 3, rtParamNames[3], SS_UINT8);

  /* registration for DISABLE*/
  ssRegDlgParamAsRunTimeParam(S, 4, 4, rtParamNames[4], SS_UINT8);

  /* registration for ENABLE*/
  ssRegDlgParamAsRunTimeParam(S, 5, 5, rtParamNames[5], SS_UINT8);
  ssSetNeedAbsoluteTime(S,1);
  ssSetModelReferenceSampleTimeDisallowInheritance(S);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_FSAC2021_V1_Running_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      22);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,22,"RTWCG"));
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,22,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,22);
    sf_mark_output_events_with_multiple_callers(S,sf_get_instance_specialization
      (),infoStruct,22,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,22,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,22,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,22);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1777894393U));
  ssSetChecksum1(S,(1824182910U));
  ssSetChecksum2(S,(2017019162U));
  ssSetChecksum3(S,(956464528U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c22_FSAC2021_V1_Running(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c22_FSAC2021_V1_Running(SimStruct *S)
{
  SFc22_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc22_FSAC2021_V1_RunningInstanceStruct *)utMalloc(sizeof
    (SFc22_FSAC2021_V1_RunningInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc22_FSAC2021_V1_RunningInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c22_FSAC2021_V1_Running;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c22_FSAC2021_V1_Running;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c22_FSAC2021_V1_Running;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c22_FSAC2021_V1_Running;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c22_FSAC2021_V1_Running;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c22_FSAC2021_V1_Running;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c22_FSAC2021_V1_Running;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c22_FSAC2021_V1_Running;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c22_FSAC2021_V1_Running;
  chartInstance->chartInfo.mdlStart = mdlStart_c22_FSAC2021_V1_Running;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c22_FSAC2021_V1_Running;
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

void c22_FSAC2021_V1_Running_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c22_FSAC2021_V1_Running(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c22_FSAC2021_V1_Running(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c22_FSAC2021_V1_Running(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c22_FSAC2021_V1_Running_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
