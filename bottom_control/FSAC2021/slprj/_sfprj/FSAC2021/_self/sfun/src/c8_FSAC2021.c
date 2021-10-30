/* Include files */

#include <stddef.h>
#include "blas.h"
#include "FSAC2021_sfun.h"
#include "c8_FSAC2021.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "FSAC2021_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c8_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c8_IN_EBS_Horn_OFF             ((uint8_T)1U)
#define c8_IN_Horn                     ((uint8_T)2U)
#define c8_IN_EBS_Horn_ON              ((uint8_T)1U)
#define c8_IN_EBS_Horn_ON1             ((uint8_T)2U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;

/* Function Declarations */
static void initialize_c8_FSAC2021(SFc8_FSAC2021InstanceStruct *chartInstance);
static void initialize_params_c8_FSAC2021(SFc8_FSAC2021InstanceStruct
  *chartInstance);
static void enable_c8_FSAC2021(SFc8_FSAC2021InstanceStruct *chartInstance);
static void disable_c8_FSAC2021(SFc8_FSAC2021InstanceStruct *chartInstance);
static void c8_update_debugger_state_c8_FSAC2021(SFc8_FSAC2021InstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c8_FSAC2021(SFc8_FSAC2021InstanceStruct
  *chartInstance);
static void set_sim_state_c8_FSAC2021(SFc8_FSAC2021InstanceStruct *chartInstance,
  const mxArray *c8_st);
static void c8_set_sim_state_side_effects_c8_FSAC2021
  (SFc8_FSAC2021InstanceStruct *chartInstance);
static void finalize_c8_FSAC2021(SFc8_FSAC2021InstanceStruct *chartInstance);
static void sf_gateway_c8_FSAC2021(SFc8_FSAC2021InstanceStruct *chartInstance);
static void initSimStructsc8_FSAC2021(SFc8_FSAC2021InstanceStruct *chartInstance);
static void c8_exit_internal_Horn(SFc8_FSAC2021InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber, uint32_T c8_instanceNumber);
static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData);
static int32_T c8_emlrt_marshallIn(SFc8_FSAC2021InstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static uint8_T c8_b_emlrt_marshallIn(SFc8_FSAC2021InstanceStruct *chartInstance,
  const mxArray *c8_b_tp_Horn, const char_T *c8_identifier);
static uint8_T c8_c_emlrt_marshallIn(SFc8_FSAC2021InstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static uint32_T c8_d_emlrt_marshallIn(SFc8_FSAC2021InstanceStruct *chartInstance,
  const mxArray *c8_b_previousTicks, const char_T *c8_identifier);
static uint32_T c8_e_emlrt_marshallIn(SFc8_FSAC2021InstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static const mxArray *c8_f_emlrt_marshallIn(SFc8_FSAC2021InstanceStruct
  *chartInstance, const mxArray *c8_b_setSimStateSideEffectsInfo, const char_T
  *c8_identifier);
static const mxArray *c8_g_emlrt_marshallIn(SFc8_FSAC2021InstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void init_dsm_address_info(SFc8_FSAC2021InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c8_FSAC2021(SFc8_FSAC2021InstanceStruct *chartInstance)
{
  uint8_T *c8_Buzzer_Pin;
  uint8_T *c8_Buzzer_Overflag;
  c8_Buzzer_Overflag = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c8_Buzzer_Pin = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c8_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c8_doSetSimStateSideEffects = 0U;
  chartInstance->c8_setSimStateSideEffectsInfo = NULL;
  chartInstance->c8_tp_EBS_Horn_OFF = 0U;
  chartInstance->c8_is_Horn = c8_IN_NO_ACTIVE_CHILD;
  chartInstance->c8_tp_Horn = 0U;
  chartInstance->c8_temporalCounter_i2 = 0U;
  chartInstance->c8_tp_EBS_Horn_ON = 0U;
  chartInstance->c8_temporalCounter_i1 = 0U;
  chartInstance->c8_tp_EBS_Horn_ON1 = 0U;
  chartInstance->c8_temporalCounter_i1 = 0U;
  chartInstance->c8_is_active_c8_FSAC2021 = 0U;
  chartInstance->c8_is_c8_FSAC2021 = c8_IN_NO_ACTIVE_CHILD;
  if (!(sf_get_output_port_reusable(chartInstance->S, 1) != 0)) {
    *c8_Buzzer_Pin = 0U;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 2) != 0)) {
    *c8_Buzzer_Overflag = 0U;
  }

  chartInstance->c8_presentTicks = 0U;
  chartInstance->c8_elapsedTicks = 0U;
  chartInstance->c8_previousTicks = 0U;
}

static void initialize_params_c8_FSAC2021(SFc8_FSAC2021InstanceStruct
  *chartInstance)
{
  real_T c8_d0;
  real_T c8_d1;
  real_T c8_d2;
  sf_mex_import_named("OFF", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      &c8_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c8_OFF = (uint8_T)c8_d0;
  sf_mex_import_named("ON", sf_mex_get_sfun_param(chartInstance->S, 2, 0),
                      &c8_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c8_ON = (uint8_T)c8_d1;
  sf_mex_import_named("ENABLE", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c8_d2, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c8_ENABLE = (uint8_T)c8_d2;
}

static void enable_c8_FSAC2021(SFc8_FSAC2021InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c8_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.2
    + 0.5);
  chartInstance->c8_previousTicks = chartInstance->c8_presentTicks;
}

static void disable_c8_FSAC2021(SFc8_FSAC2021InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c8_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.2
    + 0.5);
  chartInstance->c8_elapsedTicks = chartInstance->c8_presentTicks -
    chartInstance->c8_previousTicks;
  chartInstance->c8_previousTicks = chartInstance->c8_presentTicks;
  if ((uint32_T)chartInstance->c8_temporalCounter_i1 +
      chartInstance->c8_elapsedTicks <= 3U) {
    chartInstance->c8_temporalCounter_i1 = (uint8_T)((uint32_T)
      chartInstance->c8_temporalCounter_i1 + chartInstance->c8_elapsedTicks);
  } else {
    chartInstance->c8_temporalCounter_i1 = 3U;
  }

  if ((uint32_T)chartInstance->c8_temporalCounter_i2 +
      chartInstance->c8_elapsedTicks <= 63U) {
    chartInstance->c8_temporalCounter_i2 = (uint8_T)((uint32_T)
      chartInstance->c8_temporalCounter_i2 + chartInstance->c8_elapsedTicks);
  } else {
    chartInstance->c8_temporalCounter_i2 = 63U;
  }
}

static void c8_update_debugger_state_c8_FSAC2021(SFc8_FSAC2021InstanceStruct
  *chartInstance)
{
  uint32_T c8_prevAniVal;
  c8_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c8_is_active_c8_FSAC2021 == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 6U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_FSAC2021 == c8_IN_Horn) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_Horn == c8_IN_EBS_Horn_ON) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_Horn == c8_IN_EBS_Horn_ON1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c8_sfEvent);
  }

  if (chartInstance->c8_is_c8_FSAC2021 == c8_IN_EBS_Horn_OFF) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
  }

  _SFD_SET_ANIMATION(c8_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c8_FSAC2021(SFc8_FSAC2021InstanceStruct
  *chartInstance)
{
  const mxArray *c8_st;
  const mxArray *c8_y = NULL;
  uint8_T c8_hoistedGlobal;
  uint8_T c8_u;
  const mxArray *c8_b_y = NULL;
  uint8_T c8_b_hoistedGlobal;
  uint8_T c8_b_u;
  const mxArray *c8_c_y = NULL;
  uint8_T c8_c_hoistedGlobal;
  uint8_T c8_c_u;
  const mxArray *c8_d_y = NULL;
  uint8_T c8_d_hoistedGlobal;
  uint8_T c8_d_u;
  const mxArray *c8_e_y = NULL;
  uint8_T c8_e_hoistedGlobal;
  uint8_T c8_e_u;
  const mxArray *c8_f_y = NULL;
  uint8_T c8_f_hoistedGlobal;
  uint8_T c8_f_u;
  const mxArray *c8_g_y = NULL;
  uint8_T c8_g_hoistedGlobal;
  uint8_T c8_g_u;
  const mxArray *c8_h_y = NULL;
  uint32_T c8_h_hoistedGlobal;
  uint32_T c8_h_u;
  const mxArray *c8_i_y = NULL;
  uint8_T *c8_Buzzer_Overflag;
  uint8_T *c8_Buzzer_Pin;
  c8_Buzzer_Overflag = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c8_Buzzer_Pin = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c8_st = NULL;
  c8_st = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_createcellmatrix(8, 1), false);
  c8_hoistedGlobal = *c8_Buzzer_Overflag;
  c8_u = c8_hoistedGlobal;
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 0, c8_b_y);
  c8_b_hoistedGlobal = *c8_Buzzer_Pin;
  c8_b_u = c8_b_hoistedGlobal;
  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_create("y", &c8_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 1, c8_c_y);
  c8_c_hoistedGlobal = chartInstance->c8_is_active_c8_FSAC2021;
  c8_c_u = c8_c_hoistedGlobal;
  c8_d_y = NULL;
  sf_mex_assign(&c8_d_y, sf_mex_create("y", &c8_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 2, c8_d_y);
  c8_d_hoistedGlobal = chartInstance->c8_is_c8_FSAC2021;
  c8_d_u = c8_d_hoistedGlobal;
  c8_e_y = NULL;
  sf_mex_assign(&c8_e_y, sf_mex_create("y", &c8_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 3, c8_e_y);
  c8_e_hoistedGlobal = chartInstance->c8_is_Horn;
  c8_e_u = c8_e_hoistedGlobal;
  c8_f_y = NULL;
  sf_mex_assign(&c8_f_y, sf_mex_create("y", &c8_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 4, c8_f_y);
  c8_f_hoistedGlobal = chartInstance->c8_temporalCounter_i2;
  c8_f_u = c8_f_hoistedGlobal;
  c8_g_y = NULL;
  sf_mex_assign(&c8_g_y, sf_mex_create("y", &c8_f_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 5, c8_g_y);
  c8_g_hoistedGlobal = chartInstance->c8_temporalCounter_i1;
  c8_g_u = c8_g_hoistedGlobal;
  c8_h_y = NULL;
  sf_mex_assign(&c8_h_y, sf_mex_create("y", &c8_g_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 6, c8_h_y);
  c8_h_hoistedGlobal = chartInstance->c8_previousTicks;
  c8_h_u = c8_h_hoistedGlobal;
  c8_i_y = NULL;
  sf_mex_assign(&c8_i_y, sf_mex_create("y", &c8_h_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 7, c8_i_y);
  sf_mex_assign(&c8_st, c8_y, false);
  return c8_st;
}

static void set_sim_state_c8_FSAC2021(SFc8_FSAC2021InstanceStruct *chartInstance,
  const mxArray *c8_st)
{
  const mxArray *c8_u;
  uint8_T *c8_Buzzer_Overflag;
  uint8_T *c8_Buzzer_Pin;
  c8_Buzzer_Overflag = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c8_Buzzer_Pin = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c8_u = sf_mex_dup(c8_st);
  *c8_Buzzer_Overflag = c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c8_u, 0)), "Buzzer_Overflag");
  *c8_Buzzer_Pin = c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c8_u, 1)), "Buzzer_Pin");
  chartInstance->c8_is_active_c8_FSAC2021 = c8_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c8_u, 2)), "is_active_c8_FSAC2021");
  chartInstance->c8_is_c8_FSAC2021 = c8_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c8_u, 3)), "is_c8_FSAC2021");
  chartInstance->c8_is_Horn = c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c8_u, 4)), "is_Horn");
  chartInstance->c8_temporalCounter_i2 = c8_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c8_u, 5)), "temporalCounter_i2");
  chartInstance->c8_temporalCounter_i1 = c8_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c8_u, 6)), "temporalCounter_i1");
  chartInstance->c8_previousTicks = c8_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c8_u, 7)), "previousTicks");
  sf_mex_assign(&chartInstance->c8_setSimStateSideEffectsInfo,
                c8_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c8_u, 8)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c8_u);
  chartInstance->c8_doSetSimStateSideEffects = 1U;
  c8_update_debugger_state_c8_FSAC2021(chartInstance);
  sf_mex_destroy(&c8_st);
}

static void c8_set_sim_state_side_effects_c8_FSAC2021
  (SFc8_FSAC2021InstanceStruct *chartInstance)
{
  if (chartInstance->c8_doSetSimStateSideEffects != 0) {
    if (chartInstance->c8_is_c8_FSAC2021 == c8_IN_EBS_Horn_OFF) {
      chartInstance->c8_tp_EBS_Horn_OFF = 1U;
    } else {
      chartInstance->c8_tp_EBS_Horn_OFF = 0U;
    }

    if (chartInstance->c8_is_c8_FSAC2021 == c8_IN_Horn) {
      chartInstance->c8_tp_Horn = 1U;
      if (sf_mex_sub(chartInstance->c8_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 3) == 0.0) {
        chartInstance->c8_temporalCounter_i2 = 0U;
      }
    } else {
      chartInstance->c8_tp_Horn = 0U;
    }

    if (chartInstance->c8_is_Horn == c8_IN_EBS_Horn_ON) {
      chartInstance->c8_tp_EBS_Horn_ON = 1U;
      if (sf_mex_sub(chartInstance->c8_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 4) == 0.0) {
        chartInstance->c8_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c8_tp_EBS_Horn_ON = 0U;
    }

    if (chartInstance->c8_is_Horn == c8_IN_EBS_Horn_ON1) {
      chartInstance->c8_tp_EBS_Horn_ON1 = 1U;
      if (sf_mex_sub(chartInstance->c8_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 5) == 0.0) {
        chartInstance->c8_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c8_tp_EBS_Horn_ON1 = 0U;
    }

    chartInstance->c8_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c8_FSAC2021(SFc8_FSAC2021InstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c8_setSimStateSideEffectsInfo);
}

static void sf_gateway_c8_FSAC2021(SFc8_FSAC2021InstanceStruct *chartInstance)
{
  boolean_T c8_out;
  uint8_T c8_u0;
  boolean_T c8_b_out;
  boolean_T c8_c_out;
  uint8_T *c8_Buzzer_Pin;
  uint8_T *c8_Buzzer_Overflag;
  c8_Buzzer_Overflag = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c8_Buzzer_Pin = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c8_set_sim_state_side_effects_c8_FSAC2021(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c8_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.2
    + 0.5);
  chartInstance->c8_elapsedTicks = chartInstance->c8_presentTicks -
    chartInstance->c8_previousTicks;
  chartInstance->c8_previousTicks = chartInstance->c8_presentTicks;
  if ((uint32_T)chartInstance->c8_temporalCounter_i1 +
      chartInstance->c8_elapsedTicks <= 3U) {
    chartInstance->c8_temporalCounter_i1 = (uint8_T)((uint32_T)
      chartInstance->c8_temporalCounter_i1 + chartInstance->c8_elapsedTicks);
  } else {
    chartInstance->c8_temporalCounter_i1 = 3U;
  }

  if ((uint32_T)chartInstance->c8_temporalCounter_i2 +
      chartInstance->c8_elapsedTicks <= 63U) {
    chartInstance->c8_temporalCounter_i2 = (uint8_T)((uint32_T)
      chartInstance->c8_temporalCounter_i2 + chartInstance->c8_elapsedTicks);
  } else {
    chartInstance->c8_temporalCounter_i2 = 63U;
  }

  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 6U, chartInstance->c8_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*c8_Buzzer_Pin, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c8_OFF, 1U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c8_ON, 2U);
  _SFD_DATA_RANGE_CHECK((real_T)*c8_Buzzer_Overflag, 3U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c8_ENABLE, 4U);
  chartInstance->c8_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c8_sfEvent);
  if (chartInstance->c8_is_active_c8_FSAC2021 == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 6U, chartInstance->c8_sfEvent);
    chartInstance->c8_is_active_c8_FSAC2021 = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c8_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c8_sfEvent);
    chartInstance->c8_is_c8_FSAC2021 = c8_IN_Horn;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
    chartInstance->c8_temporalCounter_i2 = 0U;
    chartInstance->c8_tp_Horn = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
    chartInstance->c8_is_Horn = c8_IN_EBS_Horn_ON;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c8_sfEvent);
    chartInstance->c8_temporalCounter_i1 = 0U;
    chartInstance->c8_tp_EBS_Horn_ON = 1U;
    *c8_Buzzer_Pin = chartInstance->c8_ON;
    _SFD_DATA_RANGE_CHECK((real_T)*c8_Buzzer_Pin, 0U);
  } else {
    switch (chartInstance->c8_is_c8_FSAC2021) {
     case c8_IN_EBS_Horn_OFF:
      CV_CHART_EVAL(6, 0, 1);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                   chartInstance->c8_sfEvent);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c8_sfEvent);
      break;

     case c8_IN_Horn:
      CV_CHART_EVAL(6, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                   chartInstance->c8_sfEvent);
      c8_out = (CV_TRANSITION_EVAL(3U, (int32_T)_SFD_CCP_CALL(3U, 0,
                  chartInstance->c8_temporalCounter_i2 >= 45U != 0U,
                  chartInstance->c8_sfEvent)) != 0);
      if (c8_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c8_sfEvent);
        c8_exit_internal_Horn(chartInstance);
        chartInstance->c8_tp_Horn = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
        chartInstance->c8_is_c8_FSAC2021 = c8_IN_EBS_Horn_OFF;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
        chartInstance->c8_tp_EBS_Horn_OFF = 1U;
        *c8_Buzzer_Pin = chartInstance->c8_OFF;
        _SFD_DATA_RANGE_CHECK((real_T)*c8_Buzzer_Pin, 0U);
        *c8_Buzzer_Overflag = chartInstance->c8_ENABLE;
        _SFD_DATA_RANGE_CHECK((real_T)*c8_Buzzer_Overflag, 3U);
        c8_u0 = *c8_Buzzer_Overflag;
        sf_mex_printf("%s =\\n", "Buzzer_Overflag");
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 9, c8_u0);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                     chartInstance->c8_sfEvent);
        switch (chartInstance->c8_is_Horn) {
         case c8_IN_EBS_Horn_ON:
          CV_STATE_EVAL(1, 0, 1);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                       chartInstance->c8_sfEvent);
          c8_b_out = (CV_TRANSITION_EVAL(1U, (int32_T)_SFD_CCP_CALL(1U, 0,
            chartInstance->c8_temporalCounter_i1 >= 1U != 0U,
            chartInstance->c8_sfEvent)) != 0);
          if (c8_b_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c8_sfEvent);
            chartInstance->c8_tp_EBS_Horn_ON = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c8_sfEvent);
            chartInstance->c8_is_Horn = c8_IN_EBS_Horn_ON1;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c8_sfEvent);
            chartInstance->c8_temporalCounter_i1 = 0U;
            chartInstance->c8_tp_EBS_Horn_ON1 = 1U;
            *c8_Buzzer_Pin = chartInstance->c8_OFF;
            _SFD_DATA_RANGE_CHECK((real_T)*c8_Buzzer_Pin, 0U);
          } else {
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                         chartInstance->c8_sfEvent);
          }

          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c8_sfEvent);
          break;

         case c8_IN_EBS_Horn_ON1:
          CV_STATE_EVAL(1, 0, 2);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                       chartInstance->c8_sfEvent);
          c8_c_out = (CV_TRANSITION_EVAL(2U, (int32_T)_SFD_CCP_CALL(2U, 0,
            chartInstance->c8_temporalCounter_i1 >= 1U != 0U,
            chartInstance->c8_sfEvent)) != 0);
          if (c8_c_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c8_sfEvent);
            chartInstance->c8_tp_EBS_Horn_ON1 = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c8_sfEvent);
            chartInstance->c8_is_Horn = c8_IN_EBS_Horn_ON;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c8_sfEvent);
            chartInstance->c8_temporalCounter_i1 = 0U;
            chartInstance->c8_tp_EBS_Horn_ON = 1U;
            *c8_Buzzer_Pin = chartInstance->c8_ON;
            _SFD_DATA_RANGE_CHECK((real_T)*c8_Buzzer_Pin, 0U);
          } else {
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                         chartInstance->c8_sfEvent);
          }

          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c8_sfEvent);
          break;

         default:
          CV_STATE_EVAL(1, 0, 0);
          chartInstance->c8_is_Horn = c8_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c8_sfEvent);
          break;
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c8_sfEvent);
      break;

     default:
      CV_CHART_EVAL(6, 0, 0);
      chartInstance->c8_is_c8_FSAC2021 = c8_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c8_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c8_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_FSAC2021MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc8_FSAC2021(SFc8_FSAC2021InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c8_exit_internal_Horn(SFc8_FSAC2021InstanceStruct *chartInstance)
{
  switch (chartInstance->c8_is_Horn) {
   case c8_IN_EBS_Horn_ON:
    CV_STATE_EVAL(1, 1, 1);
    chartInstance->c8_tp_EBS_Horn_ON = 0U;
    chartInstance->c8_is_Horn = c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c8_sfEvent);
    break;

   case c8_IN_EBS_Horn_ON1:
    CV_STATE_EVAL(1, 1, 2);
    chartInstance->c8_tp_EBS_Horn_ON1 = 0U;
    chartInstance->c8_is_Horn = c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c8_sfEvent);
    break;

   default:
    CV_STATE_EVAL(1, 1, 0);
    chartInstance->c8_is_Horn = c8_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c8_sfEvent);
    break;
  }
}

static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber, uint32_T c8_instanceNumber)
{
  (void)c8_machineNumber;
  (void)c8_chartNumber;
  (void)c8_instanceNumber;
}

const mxArray *sf_c8_FSAC2021_get_eml_resolved_functions_info(void)
{
  const mxArray *c8_nameCaptureInfo = NULL;
  c8_nameCaptureInfo = NULL;
  sf_mex_assign(&c8_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c8_nameCaptureInfo;
}

static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_FSAC2021InstanceStruct *chartInstance;
  chartInstance = (SFc8_FSAC2021InstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(int32_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static int32_T c8_emlrt_marshallIn(SFc8_FSAC2021InstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  int32_T c8_y;
  int32_T c8_i0;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_i0, 1, 6, 0U, 0, 0U, 0);
  c8_y = c8_i0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_sfEvent;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  int32_T c8_y;
  SFc8_FSAC2021InstanceStruct *chartInstance;
  chartInstance = (SFc8_FSAC2021InstanceStruct *)chartInstanceVoid;
  c8_b_sfEvent = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_sfEvent), &c8_thisId);
  sf_mex_destroy(&c8_b_sfEvent);
  *(int32_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  uint8_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_FSAC2021InstanceStruct *chartInstance;
  chartInstance = (SFc8_FSAC2021InstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(uint8_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static uint8_T c8_b_emlrt_marshallIn(SFc8_FSAC2021InstanceStruct *chartInstance,
  const mxArray *c8_b_tp_Horn, const char_T *c8_identifier)
{
  uint8_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_tp_Horn),
    &c8_thisId);
  sf_mex_destroy(&c8_b_tp_Horn);
  return c8_y;
}

static uint8_T c8_c_emlrt_marshallIn(SFc8_FSAC2021InstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  uint8_T c8_y;
  uint8_T c8_u1;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_u1, 1, 3, 0U, 0, 0U, 0);
  c8_y = c8_u1;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_tp_Horn;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  uint8_T c8_y;
  SFc8_FSAC2021InstanceStruct *chartInstance;
  chartInstance = (SFc8_FSAC2021InstanceStruct *)chartInstanceVoid;
  c8_b_tp_Horn = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_tp_Horn),
    &c8_thisId);
  sf_mex_destroy(&c8_b_tp_Horn);
  *(uint8_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static uint32_T c8_d_emlrt_marshallIn(SFc8_FSAC2021InstanceStruct *chartInstance,
  const mxArray *c8_b_previousTicks, const char_T *c8_identifier)
{
  uint32_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_previousTicks),
    &c8_thisId);
  sf_mex_destroy(&c8_b_previousTicks);
  return c8_y;
}

static uint32_T c8_e_emlrt_marshallIn(SFc8_FSAC2021InstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  uint32_T c8_y;
  uint32_T c8_u2;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_u2, 1, 7, 0U, 0, 0U, 0);
  c8_y = c8_u2;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static const mxArray *c8_f_emlrt_marshallIn(SFc8_FSAC2021InstanceStruct
  *chartInstance, const mxArray *c8_b_setSimStateSideEffectsInfo, const char_T
  *c8_identifier)
{
  const mxArray *c8_y = NULL;
  emlrtMsgIdentifier c8_thisId;
  c8_y = NULL;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  sf_mex_assign(&c8_y, c8_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_b_setSimStateSideEffectsInfo), &c8_thisId), false);
  sf_mex_destroy(&c8_b_setSimStateSideEffectsInfo);
  return c8_y;
}

static const mxArray *c8_g_emlrt_marshallIn(SFc8_FSAC2021InstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  const mxArray *c8_y = NULL;
  (void)chartInstance;
  (void)c8_parentId;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_duplicatearraysafe(&c8_u), false);
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void init_dsm_address_info(SFc8_FSAC2021InstanceStruct *chartInstance)
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

void sf_c8_FSAC2021_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(196460243U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3046715564U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2776145079U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3007429820U);
}

mxArray *sf_c8_FSAC2021_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("vUOgDv1e48JpUl3q1jt0cG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxCreateDoubleMatrix(0,0,mxREAL));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
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

mxArray *sf_c8_FSAC2021_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c8_FSAC2021_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c8_FSAC2021(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x8'type','srcId','name','auxInfo'{{M[1],M[9],T\"Buzzer_Overflag\",},{M[1],M[5],T\"Buzzer_Pin\",},{M[8],M[0],T\"is_active_c8_FSAC2021\",},{M[9],M[0],T\"is_c8_FSAC2021\",},{M[9],M[14],T\"is_Horn\",},{M[11],M[0],T\"temporalCounter_i2\",S'et','os','ct'{{T\"at\",M[14],M[1]}}},{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"at\",M1x2[11 3],M[1]}}},{M[13],M[0],T\"previousTicks\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 8, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c8_FSAC2021_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc8_FSAC2021InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc8_FSAC2021InstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _FSAC2021MachineNumber_,
           8,
           4,
           5,
           0,
           5,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"Buzzer_Pin");
          _SFD_SET_DATA_PROPS(1,10,0,0,"OFF");
          _SFD_SET_DATA_PROPS(2,10,0,0,"ON");
          _SFD_SET_DATA_PROPS(3,2,0,1,"Buzzer_Overflag");
          _SFD_SET_DATA_PROPS(4,10,0,0,"ENABLE");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_CH_SUBSTATE_COUNT(2);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,2);
          _SFD_ST_SUBSTATE_INDEX(1,0,2);
          _SFD_ST_SUBSTATE_INDEX(1,1,3);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
        }

        _SFD_CV_INIT_CHART(2,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,2,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 16 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(2,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 16 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(1,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(3,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)c8_b_sf_marshallIn);

        {
          uint8_T *c8_Buzzer_Pin;
          uint8_T *c8_Buzzer_Overflag;
          c8_Buzzer_Overflag = (uint8_T *)ssGetOutputPortSignal(chartInstance->S,
            2);
          c8_Buzzer_Pin = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c8_Buzzer_Pin);
          _SFD_SET_DATA_VALUE_PTR(1U, &chartInstance->c8_OFF);
          _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c8_ON);
          _SFD_SET_DATA_VALUE_PTR(3U, c8_Buzzer_Overflag);
          _SFD_SET_DATA_VALUE_PTR(4U, &chartInstance->c8_ENABLE);
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
  return "GolpyT5se4FAc5g7OYMdlE";
}

static void sf_opaque_initialize_c8_FSAC2021(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc8_FSAC2021InstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c8_FSAC2021((SFc8_FSAC2021InstanceStruct*) chartInstanceVar);
  initialize_c8_FSAC2021((SFc8_FSAC2021InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c8_FSAC2021(void *chartInstanceVar)
{
  enable_c8_FSAC2021((SFc8_FSAC2021InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c8_FSAC2021(void *chartInstanceVar)
{
  disable_c8_FSAC2021((SFc8_FSAC2021InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c8_FSAC2021(void *chartInstanceVar)
{
  sf_gateway_c8_FSAC2021((SFc8_FSAC2021InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c8_FSAC2021(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c8_FSAC2021((SFc8_FSAC2021InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c8_FSAC2021();/* state var info */
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

extern void sf_internal_set_sim_state_c8_FSAC2021(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c8_FSAC2021();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c8_FSAC2021((SFc8_FSAC2021InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c8_FSAC2021(SimStruct* S)
{
  return sf_internal_get_sim_state_c8_FSAC2021(S);
}

static void sf_opaque_set_sim_state_c8_FSAC2021(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c8_FSAC2021(S, st);
}

static void sf_opaque_terminate_c8_FSAC2021(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc8_FSAC2021InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_FSAC2021_optimization_info();
    }

    finalize_c8_FSAC2021((SFc8_FSAC2021InstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc8_FSAC2021((SFc8_FSAC2021InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c8_FSAC2021(SimStruct *S)
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
    initialize_params_c8_FSAC2021((SFc8_FSAC2021InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c8_FSAC2021(SimStruct *S)
{
  /* Actual parameters from chart:
     ENABLE OFF ON
   */
  const char_T *rtParamNames[] = { "ENABLE", "OFF", "ON" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for ENABLE*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_UINT8);

  /* registration for OFF*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_UINT8);

  /* registration for ON*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_UINT8);
  ssSetNeedAbsoluteTime(S,1);
  ssSetModelReferenceSampleTimeDisallowInheritance(S);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_FSAC2021_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,8);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,8,"RTWCG"));
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,8,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,8);
    if (chartIsInlinable) {
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,8,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,8);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2733220681U));
  ssSetChecksum1(S,(1610380087U));
  ssSetChecksum2(S,(378132511U));
  ssSetChecksum3(S,(990216716U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c8_FSAC2021(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c8_FSAC2021(SimStruct *S)
{
  SFc8_FSAC2021InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc8_FSAC2021InstanceStruct *)utMalloc(sizeof
    (SFc8_FSAC2021InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc8_FSAC2021InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c8_FSAC2021;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c8_FSAC2021;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c8_FSAC2021;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c8_FSAC2021;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c8_FSAC2021;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c8_FSAC2021;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c8_FSAC2021;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c8_FSAC2021;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c8_FSAC2021;
  chartInstance->chartInfo.mdlStart = mdlStart_c8_FSAC2021;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c8_FSAC2021;
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

void c8_FSAC2021_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_FSAC2021(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_FSAC2021(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_FSAC2021(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_FSAC2021_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
