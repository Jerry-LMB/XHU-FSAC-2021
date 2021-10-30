/* Include files */

#include <stddef.h>
#include "blas.h"
#include "FSAC2021_V1_Running_sfun.h"
#include "c2_FSAC2021_V1_Running.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "FSAC2021_V1_Running_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c2_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c2_IN_Visuality_Off            ((uint8_T)1U)
#define c2_IN_Visuality_On             ((uint8_T)2U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;

/* Function Declarations */
static void initialize_c2_FSAC2021_V1_Running
  (SFc2_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void initialize_params_c2_FSAC2021_V1_Running
  (SFc2_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void enable_c2_FSAC2021_V1_Running(SFc2_FSAC2021_V1_RunningInstanceStruct
  *chartInstance);
static void disable_c2_FSAC2021_V1_Running
  (SFc2_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_FSAC2021_V1_Running
  (SFc2_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_FSAC2021_V1_Running
  (SFc2_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void set_sim_state_c2_FSAC2021_V1_Running
  (SFc2_FSAC2021_V1_RunningInstanceStruct *chartInstance, const mxArray *c2_st);
static void c2_set_sim_state_side_effects_c2_FSAC2021_V1_Running
  (SFc2_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void finalize_c2_FSAC2021_V1_Running
  (SFc2_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void sf_gateway_c2_FSAC2021_V1_Running
  (SFc2_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void initSimStructsc2_FSAC2021_V1_Running
  (SFc2_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static int32_T c2_emlrt_marshallIn(SFc2_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static uint8_T c2_b_emlrt_marshallIn(SFc2_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c2_b_tp_Visuality_On, const char_T
  *c2_identifier);
static uint8_T c2_c_emlrt_marshallIn(SFc2_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_d_emlrt_marshallIn(SFc2_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c2_Visual_Lights, const char_T *c2_identifier,
  uint8_T c2_y[3]);
static void c2_e_emlrt_marshallIn(SFc2_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  uint8_T c2_y[3]);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint32_T c2_f_emlrt_marshallIn(SFc2_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c2_b_previousTicks, const char_T *c2_identifier);
static uint32_T c2_g_emlrt_marshallIn(SFc2_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static const mxArray *c2_h_emlrt_marshallIn
  (SFc2_FSAC2021_V1_RunningInstanceStruct *chartInstance, const mxArray
   *c2_b_setSimStateSideEffectsInfo, const char_T *c2_identifier);
static const mxArray *c2_i_emlrt_marshallIn
  (SFc2_FSAC2021_V1_RunningInstanceStruct *chartInstance, const mxArray *c2_u,
   const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_FSAC2021_V1_RunningInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_FSAC2021_V1_Running
  (SFc2_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  int32_T c2_i0;
  uint8_T *c2_Visual_Flag;
  uint8_T (*c2_Visual_Lights)[3];
  c2_Visual_Flag = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_Visual_Lights = (uint8_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_doSetSimStateSideEffects = 0U;
  chartInstance->c2_setSimStateSideEffectsInfo = NULL;
  chartInstance->c2_tp_Visuality_Off = 0U;
  chartInstance->c2_tp_Visuality_On = 0U;
  chartInstance->c2_temporalCounter_i1 = 0U;
  chartInstance->c2_is_active_c2_FSAC2021_V1_Running = 0U;
  chartInstance->c2_is_c2_FSAC2021_V1_Running = c2_IN_NO_ACTIVE_CHILD;
  if (!(sf_get_output_port_reusable(chartInstance->S, 1) != 0)) {
    for (c2_i0 = 0; c2_i0 < 3; c2_i0++) {
      (*c2_Visual_Lights)[c2_i0] = 0U;
    }
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 2) != 0)) {
    *c2_Visual_Flag = 0U;
  }

  chartInstance->c2_presentTicks = 0U;
  chartInstance->c2_elapsedTicks = 0U;
  chartInstance->c2_previousTicks = 0U;
}

static void initialize_params_c2_FSAC2021_V1_Running
  (SFc2_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c2_FSAC2021_V1_Running(SFc2_FSAC2021_V1_RunningInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.05
    + 0.5);
  chartInstance->c2_previousTicks = chartInstance->c2_presentTicks;
}

static void disable_c2_FSAC2021_V1_Running
  (SFc2_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.05
    + 0.5);
  chartInstance->c2_elapsedTicks = chartInstance->c2_presentTicks -
    chartInstance->c2_previousTicks;
  chartInstance->c2_previousTicks = chartInstance->c2_presentTicks;
  if ((uint32_T)chartInstance->c2_temporalCounter_i1 +
      chartInstance->c2_elapsedTicks <= 63U) {
    chartInstance->c2_temporalCounter_i1 = (uint8_T)((uint32_T)
      chartInstance->c2_temporalCounter_i1 + chartInstance->c2_elapsedTicks);
  } else {
    chartInstance->c2_temporalCounter_i1 = 63U;
  }
}

static void c2_update_debugger_state_c2_FSAC2021_V1_Running
  (SFc2_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  uint32_T c2_prevAniVal;
  c2_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c2_is_active_c2_FSAC2021_V1_Running == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_FSAC2021_V1_Running == c2_IN_Visuality_On) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_FSAC2021_V1_Running == c2_IN_Visuality_Off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  }

  _SFD_SET_ANIMATION(c2_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c2_FSAC2021_V1_Running
  (SFc2_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_u;
  const mxArray *c2_b_y = NULL;
  int32_T c2_i1;
  uint8_T c2_b_u[3];
  const mxArray *c2_c_y = NULL;
  uint8_T c2_b_hoistedGlobal;
  uint8_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  uint8_T c2_c_hoistedGlobal;
  uint8_T c2_d_u;
  const mxArray *c2_e_y = NULL;
  uint8_T c2_d_hoistedGlobal;
  uint8_T c2_e_u;
  const mxArray *c2_f_y = NULL;
  uint32_T c2_e_hoistedGlobal;
  uint32_T c2_f_u;
  const mxArray *c2_g_y = NULL;
  uint8_T *c2_Visual_Flag;
  uint8_T (*c2_Visual_Lights)[3];
  c2_Visual_Flag = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_Visual_Lights = (uint8_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellmatrix(6, 1), false);
  c2_hoistedGlobal = *c2_Visual_Flag;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  for (c2_i1 = 0; c2_i1 < 3; c2_i1++) {
    c2_b_u[c2_i1] = (*c2_Visual_Lights)[c2_i1];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_b_u, 3, 0U, 1U, 0U, 1, 3), false);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_b_hoistedGlobal = chartInstance->c2_is_active_c2_FSAC2021_V1_Running;
  c2_c_u = c2_b_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_c_hoistedGlobal = chartInstance->c2_is_c2_FSAC2021_V1_Running;
  c2_d_u = c2_c_hoistedGlobal;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 3, c2_e_y);
  c2_d_hoistedGlobal = chartInstance->c2_temporalCounter_i1;
  c2_e_u = c2_d_hoistedGlobal;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 4, c2_f_y);
  c2_e_hoistedGlobal = chartInstance->c2_previousTicks;
  c2_f_u = c2_e_hoistedGlobal;
  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_f_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 5, c2_g_y);
  sf_mex_assign(&c2_st, c2_y, false);
  return c2_st;
}

static void set_sim_state_c2_FSAC2021_V1_Running
  (SFc2_FSAC2021_V1_RunningInstanceStruct *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  uint8_T c2_uv0[3];
  int32_T c2_i2;
  uint8_T *c2_Visual_Flag;
  uint8_T (*c2_Visual_Lights)[3];
  c2_Visual_Flag = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_Visual_Lights = (uint8_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_u = sf_mex_dup(c2_st);
  *c2_Visual_Flag = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 0)), "Visual_Flag");
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
                        "Visual_Lights", c2_uv0);
  for (c2_i2 = 0; c2_i2 < 3; c2_i2++) {
    (*c2_Visual_Lights)[c2_i2] = c2_uv0[c2_i2];
  }

  chartInstance->c2_is_active_c2_FSAC2021_V1_Running = c2_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 2)),
     "is_active_c2_FSAC2021_V1_Running");
  chartInstance->c2_is_c2_FSAC2021_V1_Running = c2_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 3)),
     "is_c2_FSAC2021_V1_Running");
  chartInstance->c2_temporalCounter_i1 = c2_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 4)), "temporalCounter_i1");
  chartInstance->c2_previousTicks = c2_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 5)), "previousTicks");
  sf_mex_assign(&chartInstance->c2_setSimStateSideEffectsInfo,
                c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 6)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c2_u);
  chartInstance->c2_doSetSimStateSideEffects = 1U;
  c2_update_debugger_state_c2_FSAC2021_V1_Running(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void c2_set_sim_state_side_effects_c2_FSAC2021_V1_Running
  (SFc2_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  if (chartInstance->c2_doSetSimStateSideEffects != 0) {
    if (chartInstance->c2_is_c2_FSAC2021_V1_Running == c2_IN_Visuality_Off) {
      chartInstance->c2_tp_Visuality_Off = 1U;
    } else {
      chartInstance->c2_tp_Visuality_Off = 0U;
    }

    if (chartInstance->c2_is_c2_FSAC2021_V1_Running == c2_IN_Visuality_On) {
      chartInstance->c2_tp_Visuality_On = 1U;
      if (sf_mex_sub(chartInstance->c2_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 3) == 0.0) {
        chartInstance->c2_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c2_tp_Visuality_On = 0U;
    }

    chartInstance->c2_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c2_FSAC2021_V1_Running
  (SFc2_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c2_setSimStateSideEffectsInfo);
}

static void sf_gateway_c2_FSAC2021_V1_Running
  (SFc2_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  boolean_T c2_out;
  int32_T c2_i6;
  int32_T c2_i7;
  uint8_T *c2_Visual_Flag;
  uint8_T (*c2_Visual_Lights)[3];
  c2_Visual_Flag = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_Visual_Lights = (uint8_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_set_sim_state_side_effects_c2_FSAC2021_V1_Running(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.05
    + 0.5);
  chartInstance->c2_elapsedTicks = chartInstance->c2_presentTicks -
    chartInstance->c2_previousTicks;
  chartInstance->c2_previousTicks = chartInstance->c2_presentTicks;
  if ((uint32_T)chartInstance->c2_temporalCounter_i1 +
      chartInstance->c2_elapsedTicks <= 63U) {
    chartInstance->c2_temporalCounter_i1 = (uint8_T)((uint32_T)
      chartInstance->c2_temporalCounter_i1 + chartInstance->c2_elapsedTicks);
  } else {
    chartInstance->c2_temporalCounter_i1 = 63U;
  }

  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  for (c2_i3 = 0; c2_i3 < 3; c2_i3++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c2_Visual_Lights)[c2_i3], 0U);
  }

  _SFD_DATA_RANGE_CHECK((real_T)*c2_Visual_Flag, 1U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  if (chartInstance->c2_is_active_c2_FSAC2021_V1_Running == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_active_c2_FSAC2021_V1_Running = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_FSAC2021_V1_Running = c2_IN_Visuality_On;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
    chartInstance->c2_temporalCounter_i1 = 0U;
    chartInstance->c2_tp_Visuality_On = 1U;
    for (c2_i4 = 0; c2_i4 < 3; c2_i4++) {
      (*c2_Visual_Lights)[c2_i4] = 1U;
    }

    for (c2_i5 = 0; c2_i5 < 3; c2_i5++) {
      _SFD_DATA_RANGE_CHECK((real_T)(*c2_Visual_Lights)[c2_i5], 0U);
    }

    *c2_Visual_Flag = 1U;
    _SFD_DATA_RANGE_CHECK((real_T)*c2_Visual_Flag, 1U);
  } else {
    switch (chartInstance->c2_is_c2_FSAC2021_V1_Running) {
     case c2_IN_Visuality_Off:
      CV_CHART_EVAL(1, 0, 1);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                   chartInstance->c2_sfEvent);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
      break;

     case c2_IN_Visuality_On:
      CV_CHART_EVAL(1, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c2_sfEvent);
      c2_out = (CV_TRANSITION_EVAL(1U, (int32_T)_SFD_CCP_CALL(1U, 0,
                  chartInstance->c2_temporalCounter_i1 >= 40U != 0U,
                  chartInstance->c2_sfEvent)) != 0);
      if (c2_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_Visuality_On = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
        chartInstance->c2_is_c2_FSAC2021_V1_Running = c2_IN_Visuality_Off;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_Visuality_Off = 1U;
        for (c2_i6 = 0; c2_i6 < 3; c2_i6++) {
          (*c2_Visual_Lights)[c2_i6] = 0U;
        }

        for (c2_i7 = 0; c2_i7 < 3; c2_i7++) {
          _SFD_DATA_RANGE_CHECK((real_T)(*c2_Visual_Lights)[c2_i7], 0U);
        }

        *c2_Visual_Flag = 0U;
        _SFD_DATA_RANGE_CHECK((real_T)*c2_Visual_Flag, 1U);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                     chartInstance->c2_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
      break;

     default:
      CV_CHART_EVAL(1, 0, 0);
      chartInstance->c2_is_c2_FSAC2021_V1_Running = c2_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_FSAC2021_V1_RunningMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc2_FSAC2021_V1_Running
  (SFc2_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber)
{
  (void)c2_machineNumber;
  (void)c2_chartNumber;
  (void)c2_instanceNumber;
}

const mxArray *sf_c2_FSAC2021_V1_Running_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  chartInstance = (SFc2_FSAC2021_V1_RunningInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static int32_T c2_emlrt_marshallIn(SFc2_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i8;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i8, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i8;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  chartInstance = (SFc2_FSAC2021_V1_RunningInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent), &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  uint8_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  chartInstance = (SFc2_FSAC2021_V1_RunningInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(uint8_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static uint8_T c2_b_emlrt_marshallIn(SFc2_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c2_b_tp_Visuality_On, const char_T
  *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_tp_Visuality_On),
    &c2_thisId);
  sf_mex_destroy(&c2_b_tp_Visuality_On);
  return c2_y;
}

static uint8_T c2_c_emlrt_marshallIn(SFc2_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_tp_Visuality_On;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  uint8_T c2_y;
  SFc2_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  chartInstance = (SFc2_FSAC2021_V1_RunningInstanceStruct *)chartInstanceVoid;
  c2_b_tp_Visuality_On = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_tp_Visuality_On),
    &c2_thisId);
  sf_mex_destroy(&c2_b_tp_Visuality_On);
  *(uint8_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i9;
  uint8_T c2_b_inData[3];
  int32_T c2_i10;
  uint8_T c2_u[3];
  const mxArray *c2_y = NULL;
  SFc2_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  chartInstance = (SFc2_FSAC2021_V1_RunningInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i9 = 0; c2_i9 < 3; c2_i9++) {
    c2_b_inData[c2_i9] = (*(uint8_T (*)[3])c2_inData)[c2_i9];
  }

  for (c2_i10 = 0; c2_i10 < 3; c2_i10++) {
    c2_u[c2_i10] = c2_b_inData[c2_i10];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 3, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_d_emlrt_marshallIn(SFc2_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c2_Visual_Lights, const char_T *c2_identifier,
  uint8_T c2_y[3])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Visual_Lights), &c2_thisId,
                        c2_y);
  sf_mex_destroy(&c2_Visual_Lights);
}

static void c2_e_emlrt_marshallIn(SFc2_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  uint8_T c2_y[3])
{
  uint8_T c2_uv1[3];
  int32_T c2_i11;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_uv1, 1, 3, 0U, 1, 0U, 1, 3);
  for (c2_i11 = 0; c2_i11 < 3; c2_i11++) {
    c2_y[c2_i11] = c2_uv1[c2_i11];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_Visual_Lights;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  uint8_T c2_y[3];
  int32_T c2_i12;
  SFc2_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  chartInstance = (SFc2_FSAC2021_V1_RunningInstanceStruct *)chartInstanceVoid;
  c2_Visual_Lights = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Visual_Lights), &c2_thisId,
                        c2_y);
  sf_mex_destroy(&c2_Visual_Lights);
  for (c2_i12 = 0; c2_i12 < 3; c2_i12++) {
    (*(uint8_T (*)[3])c2_outData)[c2_i12] = c2_y[c2_i12];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static uint32_T c2_f_emlrt_marshallIn(SFc2_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c2_b_previousTicks, const char_T *c2_identifier)
{
  uint32_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_previousTicks),
    &c2_thisId);
  sf_mex_destroy(&c2_b_previousTicks);
  return c2_y;
}

static uint32_T c2_g_emlrt_marshallIn(SFc2_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint32_T c2_y;
  uint32_T c2_u1;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u1, 1, 7, 0U, 0, 0U, 0);
  c2_y = c2_u1;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static const mxArray *c2_h_emlrt_marshallIn
  (SFc2_FSAC2021_V1_RunningInstanceStruct *chartInstance, const mxArray
   *c2_b_setSimStateSideEffectsInfo, const char_T *c2_identifier)
{
  const mxArray *c2_y = NULL;
  emlrtMsgIdentifier c2_thisId;
  c2_y = NULL;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  sf_mex_assign(&c2_y, c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_setSimStateSideEffectsInfo), &c2_thisId), false);
  sf_mex_destroy(&c2_b_setSimStateSideEffectsInfo);
  return c2_y;
}

static const mxArray *c2_i_emlrt_marshallIn
  (SFc2_FSAC2021_V1_RunningInstanceStruct *chartInstance, const mxArray *c2_u,
   const emlrtMsgIdentifier *c2_parentId)
{
  const mxArray *c2_y = NULL;
  (void)chartInstance;
  (void)c2_parentId;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_duplicatearraysafe(&c2_u), false);
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_FSAC2021_V1_RunningInstanceStruct
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

void sf_c2_FSAC2021_V1_Running_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2324400080U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3666540579U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3842977375U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3224569418U);
}

mxArray *sf_c2_FSAC2021_V1_Running_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("JlIZvTgRIdDHqIDzRhzFsH");
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

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
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

mxArray *sf_c2_FSAC2021_V1_Running_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c2_FSAC2021_V1_Running_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c2_FSAC2021_V1_Running(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x6'type','srcId','name','auxInfo'{{M[1],M[6],T\"Visual_Flag\",},{M[1],M[5],T\"Visual_Lights\",},{M[8],M[0],T\"is_active_c2_FSAC2021_V1_Running\",},{M[9],M[0],T\"is_c2_FSAC2021_V1_Running\",},{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"at\",M[1],M[1]}}},{M[13],M[0],T\"previousTicks\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 6, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_FSAC2021_V1_Running_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_FSAC2021_V1_RunningInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc2_FSAC2021_V1_RunningInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _FSAC2021_V1_RunningMachineNumber_,
           2,
           2,
           2,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"Visual_Lights");
          _SFD_SET_DATA_PROPS(1,2,0,1,"Visual_Flag");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_CH_SUBSTATE_COUNT(2);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
        }

        _SFD_CV_INIT_CHART(2,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(1,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)
            c2_c_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);

        {
          uint8_T *c2_Visual_Flag;
          uint8_T (*c2_Visual_Lights)[3];
          c2_Visual_Flag = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c2_Visual_Lights = (uint8_T (*)[3])ssGetOutputPortSignal
            (chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c2_Visual_Lights);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_Visual_Flag);
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
  return "O1ktSB9SXC4Xynft1iF3yD";
}

static void sf_opaque_initialize_c2_FSAC2021_V1_Running(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_FSAC2021_V1_RunningInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_FSAC2021_V1_Running
    ((SFc2_FSAC2021_V1_RunningInstanceStruct*) chartInstanceVar);
  initialize_c2_FSAC2021_V1_Running((SFc2_FSAC2021_V1_RunningInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_FSAC2021_V1_Running(void *chartInstanceVar)
{
  enable_c2_FSAC2021_V1_Running((SFc2_FSAC2021_V1_RunningInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c2_FSAC2021_V1_Running(void *chartInstanceVar)
{
  disable_c2_FSAC2021_V1_Running((SFc2_FSAC2021_V1_RunningInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_FSAC2021_V1_Running(void *chartInstanceVar)
{
  sf_gateway_c2_FSAC2021_V1_Running((SFc2_FSAC2021_V1_RunningInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_FSAC2021_V1_Running(SimStruct*
  S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_FSAC2021_V1_Running
    ((SFc2_FSAC2021_V1_RunningInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_FSAC2021_V1_Running();/* state var info */
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

extern void sf_internal_set_sim_state_c2_FSAC2021_V1_Running(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c2_FSAC2021_V1_Running();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_FSAC2021_V1_Running((SFc2_FSAC2021_V1_RunningInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_FSAC2021_V1_Running(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c2_FSAC2021_V1_Running(S);
}

static void sf_opaque_set_sim_state_c2_FSAC2021_V1_Running(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c2_FSAC2021_V1_Running(S, st);
}

static void sf_opaque_terminate_c2_FSAC2021_V1_Running(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_FSAC2021_V1_RunningInstanceStruct*) chartInstanceVar
      )->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_FSAC2021_V1_Running_optimization_info();
    }

    finalize_c2_FSAC2021_V1_Running((SFc2_FSAC2021_V1_RunningInstanceStruct*)
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
  initSimStructsc2_FSAC2021_V1_Running((SFc2_FSAC2021_V1_RunningInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_FSAC2021_V1_Running(SimStruct *S)
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
    initialize_params_c2_FSAC2021_V1_Running
      ((SFc2_FSAC2021_V1_RunningInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_FSAC2021_V1_Running(SimStruct *S)
{
  ssSetNeedAbsoluteTime(S,1);
  ssSetModelReferenceSampleTimeDisallowInheritance(S);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_FSAC2021_V1_Running_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,2,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2810242058U));
  ssSetChecksum1(S,(3923959336U));
  ssSetChecksum2(S,(3444506537U));
  ssSetChecksum3(S,(940912595U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_FSAC2021_V1_Running(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c2_FSAC2021_V1_Running(SimStruct *S)
{
  SFc2_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc2_FSAC2021_V1_RunningInstanceStruct *)utMalloc(sizeof
    (SFc2_FSAC2021_V1_RunningInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_FSAC2021_V1_RunningInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_FSAC2021_V1_Running;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_FSAC2021_V1_Running;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_FSAC2021_V1_Running;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_FSAC2021_V1_Running;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_FSAC2021_V1_Running;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_FSAC2021_V1_Running;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_FSAC2021_V1_Running;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_FSAC2021_V1_Running;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_FSAC2021_V1_Running;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_FSAC2021_V1_Running;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_FSAC2021_V1_Running;
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

void c2_FSAC2021_V1_Running_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_FSAC2021_V1_Running(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_FSAC2021_V1_Running(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_FSAC2021_V1_Running(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_FSAC2021_V1_Running_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
