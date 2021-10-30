/* Include files */

#include <stddef.h>
#include "blas.h"
#include "FSAC2021_V1_sfun.h"
#include "c3_FSAC2021_V1.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "FSAC2021_V1_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c3_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c3_IN_AS_Driving               ((uint8_T)1U)
#define c3_IN_AS_Emergency             ((uint8_T)2U)
#define c3_IN_AS_Finished              ((uint8_T)3U)
#define c3_IN_AS_Off                   ((uint8_T)4U)
#define c3_IN_AS_Ready                 ((uint8_T)5U)
#define c3_IN_Manual_Driving           ((uint8_T)6U)
#define c3_IN_Init                     ((uint8_T)1U)
#define c3_IN_Origin                   ((uint8_T)2U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;

/* Function Declarations */
static void initialize_c3_FSAC2021_V1(SFc3_FSAC2021_V1InstanceStruct
  *chartInstance);
static void initialize_params_c3_FSAC2021_V1(SFc3_FSAC2021_V1InstanceStruct
  *chartInstance);
static void enable_c3_FSAC2021_V1(SFc3_FSAC2021_V1InstanceStruct *chartInstance);
static void disable_c3_FSAC2021_V1(SFc3_FSAC2021_V1InstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_FSAC2021_V1
  (SFc3_FSAC2021_V1InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_FSAC2021_V1
  (SFc3_FSAC2021_V1InstanceStruct *chartInstance);
static void set_sim_state_c3_FSAC2021_V1(SFc3_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c3_st);
static void c3_set_sim_state_side_effects_c3_FSAC2021_V1
  (SFc3_FSAC2021_V1InstanceStruct *chartInstance);
static void finalize_c3_FSAC2021_V1(SFc3_FSAC2021_V1InstanceStruct
  *chartInstance);
static void sf_gateway_c3_FSAC2021_V1(SFc3_FSAC2021_V1InstanceStruct
  *chartInstance);
static void c3_chartstep_c3_FSAC2021_V1(SFc3_FSAC2021_V1InstanceStruct
  *chartInstance);
static void initSimStructsc3_FSAC2021_V1(SFc3_FSAC2021_V1InstanceStruct
  *chartInstance);
static void c3_exit_internal_AS_Ready(SFc3_FSAC2021_V1InstanceStruct
  *chartInstance);
static void c3_AS_Driving(SFc3_FSAC2021_V1InstanceStruct *chartInstance);
static void c3_AS_Finished(SFc3_FSAC2021_V1InstanceStruct *chartInstance);
static void c3_AS_Emergency(SFc3_FSAC2021_V1InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static int32_T c3_emlrt_marshallIn(SFc3_FSAC2021_V1InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static uint8_T c3_b_emlrt_marshallIn(SFc3_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c3_b_tp_Manual_Driving, const char_T
  *c3_identifier);
static uint8_T c3_c_emlrt_marshallIn(SFc3_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static uint32_T c3_d_emlrt_marshallIn(SFc3_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c3_b_previousTicks, const char_T *c3_identifier);
static uint32_T c3_e_emlrt_marshallIn(SFc3_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static const mxArray *c3_f_emlrt_marshallIn(SFc3_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c3_b_setSimStateSideEffectsInfo, const char_T
  *c3_identifier);
static const mxArray *c3_g_emlrt_marshallIn(SFc3_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_FSAC2021_V1InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_FSAC2021_V1(SFc3_FSAC2021_V1InstanceStruct
  *chartInstance)
{
  uint8_T *c3_Blue_Light;
  uint8_T *c3_Yellow_Light;
  uint8_T *c3_Buzzer;
  uint8_T *c3_Safety_Circuit_Relay;
  uint8_T *c3_ASSI_State;
  uint8_T *c3_R2D;
  c3_R2D = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c3_ASSI_State = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c3_Safety_Circuit_Relay = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_Buzzer = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_Yellow_Light = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_Blue_Light = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_doSetSimStateSideEffects = 0U;
  chartInstance->c3_setSimStateSideEffectsInfo = NULL;
  chartInstance->c3_tp_AS_Driving = 0U;
  chartInstance->c3_tp_AS_Emergency = 0U;
  chartInstance->c3_tp_AS_Finished = 0U;
  chartInstance->c3_tp_AS_Off = 0U;
  chartInstance->c3_is_AS_Ready = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_tp_AS_Ready = 0U;
  chartInstance->c3_tp_Init = 0U;
  chartInstance->c3_tp_Origin = 0U;
  chartInstance->c3_temporalCounter_i1 = 0U;
  chartInstance->c3_tp_Manual_Driving = 0U;
  chartInstance->c3_is_active_c3_FSAC2021_V1 = 0U;
  chartInstance->c3_is_c3_FSAC2021_V1 = c3_IN_NO_ACTIVE_CHILD;
  if (!(sf_get_output_port_reusable(chartInstance->S, 1) != 0)) {
    *c3_Blue_Light = 0U;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 2) != 0)) {
    *c3_Yellow_Light = 0U;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 3) != 0)) {
    *c3_Buzzer = 0U;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 4) != 0)) {
    *c3_Safety_Circuit_Relay = 0U;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 5) != 0)) {
    *c3_ASSI_State = 0U;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 6) != 0)) {
    *c3_R2D = 0U;
  }

  chartInstance->c3_presentTicks = 0U;
  chartInstance->c3_elapsedTicks = 0U;
  chartInstance->c3_previousTicks = 0U;
}

static void initialize_params_c3_FSAC2021_V1(SFc3_FSAC2021_V1InstanceStruct
  *chartInstance)
{
  real_T c3_d0;
  real_T c3_d1;
  real_T c3_d2;
  real_T c3_d3;
  real_T c3_d4;
  real_T c3_d5;
  real_T c3_d6;
  real_T c3_d7;
  real_T c3_d8;
  real_T c3_d9;
  real_T c3_d10;
  real_T c3_d11;
  real_T c3_d12;
  real_T c3_d13;
  real_T c3_d14;
  real_T c3_d15;
  real_T c3_d16;
  real_T c3_d17;
  sf_mex_import_named("ON", sf_mex_get_sfun_param(chartInstance->S, 16, 0),
                      &c3_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_ON = (uint8_T)c3_d0;
  sf_mex_import_named("OFF", sf_mex_get_sfun_param(chartInstance->S, 15, 0),
                      &c3_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_OFF = (uint8_T)c3_d1;
  sf_mex_import_named("ENABLE", sf_mex_get_sfun_param(chartInstance->S, 12, 0),
                      &c3_d2, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_ENABLE = (uint8_T)c3_d2;
  sf_mex_import_named("DISABLE", sf_mex_get_sfun_param(chartInstance->S, 8, 0),
                      &c3_d3, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_DISABLE = (uint8_T)c3_d3;
  sf_mex_import_named("AS_OFF", sf_mex_get_sfun_param(chartInstance->S, 3, 0),
                      &c3_d4, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_AS_OFF = (uint8_T)c3_d4;
  sf_mex_import_named("AS_READY", sf_mex_get_sfun_param(chartInstance->S, 4, 0),
                      &c3_d5, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_AS_READY = (uint8_T)c3_d5;
  sf_mex_import_named("AS_DRIVING", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c3_d6, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_AS_DRIVING = (uint8_T)c3_d6;
  sf_mex_import_named("AS_FINISH", sf_mex_get_sfun_param(chartInstance->S, 2, 0),
                      &c3_d7, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_AS_FINISH = (uint8_T)c3_d7;
  sf_mex_import_named("AS_EMERGENCY", sf_mex_get_sfun_param(chartInstance->S, 1,
    0), &c3_d8, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_AS_EMERGENCY = (uint8_T)c3_d8;
  sf_mex_import_named("BLINK", sf_mex_get_sfun_param(chartInstance->S, 5, 0),
                      &c3_d9, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_BLINK = (uint8_T)c3_d9;
  sf_mex_import_named("EBS_DISABLE", sf_mex_get_sfun_param(chartInstance->S, 10,
    0), &c3_d10, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_EBS_DISABLE = (uint8_T)c3_d10;
  sf_mex_import_named("EBS_ARMED", sf_mex_get_sfun_param(chartInstance->S, 9, 0),
                      &c3_d11, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_EBS_ARMED = (uint8_T)c3_d11;
  sf_mex_import_named("EBS_ENABLE", sf_mex_get_sfun_param(chartInstance->S, 11,
    0), &c3_d12, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_EBS_ENABLE = (uint8_T)c3_d12;
  sf_mex_import_named("MANUAL_DRIVING", sf_mex_get_sfun_param(chartInstance->S,
    13, 0), &c3_d13, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_MANUAL_DRIVING = (uint8_T)c3_d13;
  sf_mex_import_named("MANUAL_MODE", sf_mex_get_sfun_param(chartInstance->S, 14,
    0), &c3_d14, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_MANUAL_MODE = (uint8_T)c3_d14;
  sf_mex_import_named("BUZZER_START", sf_mex_get_sfun_param(chartInstance->S, 7,
    0), &c3_d15, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_BUZZER_START = (uint8_T)c3_d15;
  sf_mex_import_named("BUZZER_EBS", sf_mex_get_sfun_param(chartInstance->S, 6, 0),
                      &c3_d16, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_BUZZER_EBS = (uint8_T)c3_d16;
  sf_mex_import_named("TRACKDRIVE", sf_mex_get_sfun_param(chartInstance->S, 17,
    0), &c3_d17, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_TRACKDRIVE = (uint8_T)c3_d17;
}

static void enable_c3_FSAC2021_V1(SFc3_FSAC2021_V1InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_enable(chartInstance->S, 0, "Manual_R2D_Detect", 0);
  sf_call_output_fcn_enable(chartInstance->S, 1, "Visuality_Check", 0);
  chartInstance->c3_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.05
    + 0.5);
  chartInstance->c3_previousTicks = chartInstance->c3_presentTicks;
}

static void disable_c3_FSAC2021_V1(SFc3_FSAC2021_V1InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.05
    + 0.5);
  chartInstance->c3_elapsedTicks = chartInstance->c3_presentTicks -
    chartInstance->c3_previousTicks;
  chartInstance->c3_previousTicks = chartInstance->c3_presentTicks;
  if ((uint32_T)chartInstance->c3_temporalCounter_i1 +
      chartInstance->c3_elapsedTicks <= 127U) {
    chartInstance->c3_temporalCounter_i1 = (uint8_T)((uint32_T)
      chartInstance->c3_temporalCounter_i1 + chartInstance->c3_elapsedTicks);
  } else {
    chartInstance->c3_temporalCounter_i1 = 127U;
  }

  sf_call_output_fcn_disable(chartInstance->S, 0, "Manual_R2D_Detect", 0);
  sf_call_output_fcn_disable(chartInstance->S, 1, "Visuality_Check", 0);
}

static void c3_update_debugger_state_c3_FSAC2021_V1
  (SFc3_FSAC2021_V1InstanceStruct *chartInstance)
{
  uint32_T c3_prevAniVal;
  c3_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c3_is_active_c3_FSAC2021_V1 == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_FSAC2021_V1 == c3_IN_Manual_Driving) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_FSAC2021_V1 == c3_IN_AS_Off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_FSAC2021_V1 == c3_IN_AS_Ready) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_AS_Ready == c3_IN_Init) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_AS_Ready == c3_IN_Origin) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_FSAC2021_V1 == c3_IN_AS_Driving) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_FSAC2021_V1 == c3_IN_AS_Finished) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_FSAC2021_V1 == c3_IN_AS_Emergency) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  }

  _SFD_SET_ANIMATION(c3_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c3_FSAC2021_V1
  (SFc3_FSAC2021_V1InstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  uint8_T c3_hoistedGlobal;
  uint8_T c3_u;
  const mxArray *c3_b_y = NULL;
  uint8_T c3_b_hoistedGlobal;
  uint8_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  uint8_T c3_c_hoistedGlobal;
  uint8_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  uint8_T c3_d_hoistedGlobal;
  uint8_T c3_d_u;
  const mxArray *c3_e_y = NULL;
  uint8_T c3_e_hoistedGlobal;
  uint8_T c3_e_u;
  const mxArray *c3_f_y = NULL;
  uint8_T c3_f_hoistedGlobal;
  uint8_T c3_f_u;
  const mxArray *c3_g_y = NULL;
  uint8_T c3_g_hoistedGlobal;
  uint8_T c3_g_u;
  const mxArray *c3_h_y = NULL;
  uint8_T c3_h_hoistedGlobal;
  uint8_T c3_h_u;
  const mxArray *c3_i_y = NULL;
  uint8_T c3_i_hoistedGlobal;
  uint8_T c3_i_u;
  const mxArray *c3_j_y = NULL;
  uint8_T c3_j_hoistedGlobal;
  uint8_T c3_j_u;
  const mxArray *c3_k_y = NULL;
  uint32_T c3_k_hoistedGlobal;
  uint32_T c3_k_u;
  const mxArray *c3_l_y = NULL;
  uint8_T *c3_ASSI_State;
  uint8_T *c3_Blue_Light;
  uint8_T *c3_Buzzer;
  uint8_T *c3_R2D;
  uint8_T *c3_Safety_Circuit_Relay;
  uint8_T *c3_Yellow_Light;
  c3_R2D = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c3_ASSI_State = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c3_Safety_Circuit_Relay = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_Buzzer = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_Yellow_Light = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_Blue_Light = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(11, 1), false);
  c3_hoistedGlobal = *c3_ASSI_State;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = *c3_Blue_Light;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = *c3_Buzzer;
  c3_c_u = c3_c_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_d_hoistedGlobal = *c3_R2D;
  c3_d_u = c3_d_hoistedGlobal;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 3, c3_e_y);
  c3_e_hoistedGlobal = *c3_Safety_Circuit_Relay;
  c3_e_u = c3_e_hoistedGlobal;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 4, c3_f_y);
  c3_f_hoistedGlobal = *c3_Yellow_Light;
  c3_f_u = c3_f_hoistedGlobal;
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", &c3_f_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 5, c3_g_y);
  c3_g_hoistedGlobal = chartInstance->c3_is_active_c3_FSAC2021_V1;
  c3_g_u = c3_g_hoistedGlobal;
  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y", &c3_g_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 6, c3_h_y);
  c3_h_hoistedGlobal = chartInstance->c3_is_c3_FSAC2021_V1;
  c3_h_u = c3_h_hoistedGlobal;
  c3_i_y = NULL;
  sf_mex_assign(&c3_i_y, sf_mex_create("y", &c3_h_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 7, c3_i_y);
  c3_i_hoistedGlobal = chartInstance->c3_is_AS_Ready;
  c3_i_u = c3_i_hoistedGlobal;
  c3_j_y = NULL;
  sf_mex_assign(&c3_j_y, sf_mex_create("y", &c3_i_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 8, c3_j_y);
  c3_j_hoistedGlobal = chartInstance->c3_temporalCounter_i1;
  c3_j_u = c3_j_hoistedGlobal;
  c3_k_y = NULL;
  sf_mex_assign(&c3_k_y, sf_mex_create("y", &c3_j_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 9, c3_k_y);
  c3_k_hoistedGlobal = chartInstance->c3_previousTicks;
  c3_k_u = c3_k_hoistedGlobal;
  c3_l_y = NULL;
  sf_mex_assign(&c3_l_y, sf_mex_create("y", &c3_k_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 10, c3_l_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_FSAC2021_V1(SFc3_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  uint8_T *c3_ASSI_State;
  uint8_T *c3_Blue_Light;
  uint8_T *c3_Buzzer;
  uint8_T *c3_R2D;
  uint8_T *c3_Safety_Circuit_Relay;
  uint8_T *c3_Yellow_Light;
  c3_R2D = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c3_ASSI_State = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c3_Safety_Circuit_Relay = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_Buzzer = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_Yellow_Light = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_Blue_Light = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_u = sf_mex_dup(c3_st);
  *c3_ASSI_State = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 0)), "ASSI_State");
  *c3_Blue_Light = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 1)), "Blue_Light");
  *c3_Buzzer = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 2)), "Buzzer");
  *c3_R2D = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u,
    3)), "R2D");
  *c3_Safety_Circuit_Relay = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 4)), "Safety_Circuit_Relay");
  *c3_Yellow_Light = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 5)), "Yellow_Light");
  chartInstance->c3_is_active_c3_FSAC2021_V1 = c3_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 6)),
     "is_active_c3_FSAC2021_V1");
  chartInstance->c3_is_c3_FSAC2021_V1 = c3_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 7)), "is_c3_FSAC2021_V1");
  chartInstance->c3_is_AS_Ready = c3_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 8)), "is_AS_Ready");
  chartInstance->c3_temporalCounter_i1 = c3_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 9)), "temporalCounter_i1");
  chartInstance->c3_previousTicks = c3_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 10)), "previousTicks");
  sf_mex_assign(&chartInstance->c3_setSimStateSideEffectsInfo,
                c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 11)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c3_u);
  chartInstance->c3_doSetSimStateSideEffects = 1U;
  c3_update_debugger_state_c3_FSAC2021_V1(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void c3_set_sim_state_side_effects_c3_FSAC2021_V1
  (SFc3_FSAC2021_V1InstanceStruct *chartInstance)
{
  if (chartInstance->c3_doSetSimStateSideEffects != 0) {
    if (chartInstance->c3_is_c3_FSAC2021_V1 == c3_IN_AS_Driving) {
      chartInstance->c3_tp_AS_Driving = 1U;
    } else {
      chartInstance->c3_tp_AS_Driving = 0U;
    }

    if (chartInstance->c3_is_c3_FSAC2021_V1 == c3_IN_AS_Emergency) {
      chartInstance->c3_tp_AS_Emergency = 1U;
    } else {
      chartInstance->c3_tp_AS_Emergency = 0U;
    }

    if (chartInstance->c3_is_c3_FSAC2021_V1 == c3_IN_AS_Finished) {
      chartInstance->c3_tp_AS_Finished = 1U;
    } else {
      chartInstance->c3_tp_AS_Finished = 0U;
    }

    if (chartInstance->c3_is_c3_FSAC2021_V1 == c3_IN_AS_Off) {
      chartInstance->c3_tp_AS_Off = 1U;
    } else {
      chartInstance->c3_tp_AS_Off = 0U;
    }

    if (chartInstance->c3_is_c3_FSAC2021_V1 == c3_IN_AS_Ready) {
      chartInstance->c3_tp_AS_Ready = 1U;
    } else {
      chartInstance->c3_tp_AS_Ready = 0U;
    }

    if (chartInstance->c3_is_AS_Ready == c3_IN_Init) {
      chartInstance->c3_tp_Init = 1U;
    } else {
      chartInstance->c3_tp_Init = 0U;
    }

    if (chartInstance->c3_is_AS_Ready == c3_IN_Origin) {
      chartInstance->c3_tp_Origin = 1U;
      if (sf_mex_sub(chartInstance->c3_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 8) == 0.0) {
        chartInstance->c3_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c3_tp_Origin = 0U;
    }

    if (chartInstance->c3_is_c3_FSAC2021_V1 == c3_IN_Manual_Driving) {
      chartInstance->c3_tp_Manual_Driving = 1U;
    } else {
      chartInstance->c3_tp_Manual_Driving = 0U;
    }

    chartInstance->c3_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c3_FSAC2021_V1(SFc3_FSAC2021_V1InstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c3_setSimStateSideEffectsInfo);
}

static void sf_gateway_c3_FSAC2021_V1(SFc3_FSAC2021_V1InstanceStruct
  *chartInstance)
{
  uint8_T *c3_Blue_Light;
  uint8_T *c3_Yellow_Light;
  uint8_T *c3_Buzzer;
  uint8_T *c3_TS_Flag;
  uint8_T *c3_EBS_Flag;
  uint8_T *c3_Safety_Circuit_Relay;
  uint8_T *c3_ASSI_State;
  real32_T *c3_Veh_Spd;
  uint8_T *c3_ASMS;
  uint8_T *c3_R2D;
  uint8_T *c3_LVMS;
  uint8_T *c3_AMI_State;
  uint8_T *c3_Res_EBS;
  uint8_T *c3_Res_GO;
  uint8_T *c3_START_Flag;
  uint8_T *c3_Misson_Finished;
  uint8_T *c3_Buzzer_Overflag;
  boolean_T *c3_Brake_Trigeer;
  real_T *c3_Origin_Flag;
  c3_Origin_Flag = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
  c3_Brake_Trigeer = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c3_Buzzer_Overflag = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c3_Misson_Finished = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c3_START_Flag = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c3_Res_GO = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c3_Res_EBS = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c3_AMI_State = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c3_LVMS = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c3_R2D = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c3_ASMS = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_Veh_Spd = (real32_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_ASSI_State = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c3_Safety_Circuit_Relay = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_EBS_Flag = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_TS_Flag = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c3_Buzzer = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_Yellow_Light = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_Blue_Light = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_set_sim_state_side_effects_c3_FSAC2021_V1(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.05
    + 0.5);
  chartInstance->c3_elapsedTicks = chartInstance->c3_presentTicks -
    chartInstance->c3_previousTicks;
  chartInstance->c3_previousTicks = chartInstance->c3_presentTicks;
  if ((uint32_T)chartInstance->c3_temporalCounter_i1 +
      chartInstance->c3_elapsedTicks <= 127U) {
    chartInstance->c3_temporalCounter_i1 = (uint8_T)((uint32_T)
      chartInstance->c3_temporalCounter_i1 + chartInstance->c3_elapsedTicks);
  } else {
    chartInstance->c3_temporalCounter_i1 = 127U;
  }

  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*c3_Blue_Light, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)*c3_Yellow_Light, 1U);
  _SFD_DATA_RANGE_CHECK((real_T)*c3_Buzzer, 2U);
  _SFD_DATA_RANGE_CHECK((real_T)*c3_TS_Flag, 3U);
  _SFD_DATA_RANGE_CHECK((real_T)*c3_EBS_Flag, 4U);
  _SFD_DATA_RANGE_CHECK((real_T)*c3_Safety_Circuit_Relay, 5U);
  _SFD_DATA_RANGE_CHECK((real_T)*c3_ASSI_State, 6U);
  _SFD_DATA_RANGE_CHECK((real_T)*c3_Veh_Spd, 7U);
  _SFD_DATA_RANGE_CHECK((real_T)*c3_ASMS, 8U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_ON, 9U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_OFF, 10U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_ENABLE, 11U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_DISABLE, 12U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_AS_OFF, 13U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_AS_READY, 14U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_AS_DRIVING, 15U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_AS_FINISH, 16U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_AS_EMERGENCY, 17U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_BLINK, 18U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_EBS_DISABLE, 19U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_EBS_ARMED, 20U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_EBS_ENABLE, 21U);
  _SFD_DATA_RANGE_CHECK((real_T)*c3_R2D, 22U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_MANUAL_DRIVING, 23U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_MANUAL_MODE, 24U);
  _SFD_DATA_RANGE_CHECK((real_T)*c3_LVMS, 25U);
  _SFD_DATA_RANGE_CHECK((real_T)*c3_AMI_State, 26U);
  _SFD_DATA_RANGE_CHECK((real_T)*c3_Res_EBS, 27U);
  _SFD_DATA_RANGE_CHECK((real_T)*c3_Res_GO, 28U);
  _SFD_DATA_RANGE_CHECK((real_T)*c3_START_Flag, 29U);
  _SFD_DATA_RANGE_CHECK((real_T)*c3_Misson_Finished, 30U);
  _SFD_DATA_RANGE_CHECK((real_T)*c3_Buzzer_Overflag, 31U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_BUZZER_START, 32U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_BUZZER_EBS, 33U);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_TRACKDRIVE, 34U);
  _SFD_DATA_RANGE_CHECK((real_T)*c3_Brake_Trigeer, 35U);
  _SFD_DATA_RANGE_CHECK(*c3_Origin_Flag, 36U);
  chartInstance->c3_sfEvent = CALL_EVENT;
  c3_chartstep_c3_FSAC2021_V1(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_FSAC2021_V1MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c3_chartstep_c3_FSAC2021_V1(SFc3_FSAC2021_V1InstanceStruct
  *chartInstance)
{
  boolean_T c3_temp;
  boolean_T c3_b_temp;
  boolean_T c3_c_temp;
  boolean_T c3_d_temp;
  boolean_T c3_out;
  boolean_T c3_e_temp;
  boolean_T c3_f_temp;
  boolean_T c3_g_temp;
  boolean_T c3_h_temp;
  boolean_T c3_i_temp;
  boolean_T c3_b_out;
  boolean_T c3_c_out;
  boolean_T c3_d_out;
  boolean_T c3_j_temp;
  boolean_T c3_e_out;
  boolean_T c3_f_out;
  boolean_T c3_g_out;
  uint8_T *c3_AMI_State;
  uint8_T *c3_TS_Flag;
  uint8_T *c3_ASMS;
  uint8_T *c3_START_Flag;
  boolean_T *c3_Brake_Trigeer;
  uint8_T *c3_LVMS;
  uint8_T *c3_EBS_Flag;
  uint8_T *c3_ASSI_State;
  uint8_T *c3_R2D;
  uint8_T *c3_Buzzer;
  real_T *c3_Origin_Flag;
  uint8_T *c3_Yellow_Light;
  uint8_T *c3_Blue_Light;
  uint8_T *c3_Res_GO;
  boolean_T guard1 = false;
  c3_Origin_Flag = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
  c3_Brake_Trigeer = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c3_START_Flag = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c3_Res_GO = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c3_AMI_State = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c3_LVMS = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c3_R2D = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c3_ASMS = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_ASSI_State = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c3_EBS_Flag = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_TS_Flag = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c3_Buzzer = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_Yellow_Light = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_Blue_Light = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  if (chartInstance->c3_is_active_c3_FSAC2021_V1 == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_active_c3_FSAC2021_V1 = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_c3_FSAC2021_V1 = c3_IN_AS_Off;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_AS_Off = 1U;
    *c3_ASSI_State = chartInstance->c3_AS_OFF;
    _SFD_DATA_RANGE_CHECK((real_T)*c3_ASSI_State, 6U);
    *c3_Blue_Light = chartInstance->c3_OFF;
    _SFD_DATA_RANGE_CHECK((real_T)*c3_Blue_Light, 0U);
    *c3_Yellow_Light = chartInstance->c3_OFF;
    _SFD_DATA_RANGE_CHECK((real_T)*c3_Yellow_Light, 1U);
  } else {
    switch (chartInstance->c3_is_c3_FSAC2021_V1) {
     case c3_IN_AS_Driving:
      CV_CHART_EVAL(2, 0, 1);
      c3_AS_Driving(chartInstance);
      break;

     case c3_IN_AS_Emergency:
      CV_CHART_EVAL(2, 0, 2);
      c3_AS_Emergency(chartInstance);
      break;

     case c3_IN_AS_Finished:
      CV_CHART_EVAL(2, 0, 3);
      c3_AS_Finished(chartInstance);
      break;

     case c3_IN_AS_Off:
      CV_CHART_EVAL(2, 0, 4);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                   chartInstance->c3_sfEvent);
      c3_temp = (_SFD_CCP_CALL(7U, 0, *c3_AMI_State ==
                  chartInstance->c3_MANUAL_MODE != 0U, chartInstance->c3_sfEvent)
                 != 0);
      if (c3_temp) {
        c3_temp = (_SFD_CCP_CALL(7U, 1, *c3_TS_Flag != 0U,
                    chartInstance->c3_sfEvent) != 0);
      }

      c3_b_temp = c3_temp;
      if (c3_b_temp) {
        c3_b_temp = !(_SFD_CCP_CALL(7U, 2, *c3_ASMS != 0U,
          chartInstance->c3_sfEvent) != 0);
      }

      c3_c_temp = c3_b_temp;
      if (c3_c_temp) {
        c3_c_temp = (_SFD_CCP_CALL(7U, 3, *c3_START_Flag != 0U,
          chartInstance->c3_sfEvent) != 0);
      }

      c3_d_temp = c3_c_temp;
      if (c3_d_temp) {
        c3_d_temp = (_SFD_CCP_CALL(7U, 4, *c3_Brake_Trigeer != 0U,
          chartInstance->c3_sfEvent) != 0);
      }

      c3_out = (CV_TRANSITION_EVAL(7U, (int32_T)c3_d_temp) != 0);
      if (c3_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_AS_Off = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_c3_FSAC2021_V1 = c3_IN_Manual_Driving;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_Manual_Driving = 1U;
        *c3_R2D = chartInstance->c3_ON;
        _SFD_DATA_RANGE_CHECK((real_T)*c3_R2D, 22U);
        *c3_Buzzer = chartInstance->c3_BUZZER_START;
        _SFD_DATA_RANGE_CHECK((real_T)*c3_Buzzer, 2U);
        *c3_ASSI_State = chartInstance->c3_MANUAL_DRIVING;
        _SFD_DATA_RANGE_CHECK((real_T)*c3_ASSI_State, 6U);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U,
                     chartInstance->c3_sfEvent);
        c3_e_temp = (_SFD_CCP_CALL(0U, 0, *c3_LVMS != 0U,
          chartInstance->c3_sfEvent) != 0);
        if (c3_e_temp) {
          c3_e_temp = (_SFD_CCP_CALL(0U, 1, *c3_ASMS != 0U,
            chartInstance->c3_sfEvent) != 0);
        }

        c3_f_temp = c3_e_temp;
        if (c3_f_temp) {
          c3_f_temp = (_SFD_CCP_CALL(0U, 2, *c3_TS_Flag != 0U,
            chartInstance->c3_sfEvent) != 0);
        }

        c3_g_temp = c3_f_temp;
        if (c3_g_temp) {
          c3_g_temp = (_SFD_CCP_CALL(0U, 3, *c3_AMI_State != 0 != 0U,
            chartInstance->c3_sfEvent) != 0);
        }

        c3_h_temp = c3_g_temp;
        if (c3_h_temp) {
          c3_h_temp = (_SFD_CCP_CALL(0U, 4, *c3_AMI_State !=
            chartInstance->c3_MANUAL_MODE != 0U, chartInstance->c3_sfEvent) != 0);
        }

        c3_i_temp = c3_h_temp;
        if (c3_i_temp) {
          c3_i_temp = (_SFD_CCP_CALL(0U, 5, *c3_EBS_Flag ==
            chartInstance->c3_EBS_ARMED != 0U, chartInstance->c3_sfEvent) != 0);
        }

        c3_b_out = (CV_TRANSITION_EVAL(0U, (int32_T)c3_i_temp) != 0);
        if (c3_b_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_AS_Off = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
          chartInstance->c3_is_c3_FSAC2021_V1 = c3_IN_AS_Ready;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_AS_Ready = 1U;
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c3_sfEvent);
          chartInstance->c3_is_AS_Ready = c3_IN_Init;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
          chartInstance->c3_tp_Init = 1U;
          *c3_ASSI_State = chartInstance->c3_AS_READY;
          _SFD_DATA_RANGE_CHECK((real_T)*c3_ASSI_State, 6U);
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                       chartInstance->c3_sfEvent);
          sf_call_output_fcn_call(chartInstance->S, 0, "Manual_R2D_Detect", 0);
          sf_call_output_fcn_call(chartInstance->S, 1, "Visuality_Check", 0);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c3_sfEvent);
      break;

     case c3_IN_AS_Ready:
      CV_CHART_EVAL(2, 0, 5);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c3_sfEvent);
      c3_c_out = (CV_TRANSITION_EVAL(1U, !(_SFD_CCP_CALL(1U, 0, *c3_ASMS != 0U,
        chartInstance->c3_sfEvent) != 0)) != 0);
      guard1 = false;
      if (c3_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
        c3_exit_internal_AS_Ready(chartInstance);
        chartInstance->c3_tp_AS_Ready = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_c3_FSAC2021_V1 = c3_IN_AS_Off;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_AS_Off = 1U;
        *c3_ASSI_State = chartInstance->c3_AS_OFF;
        _SFD_DATA_RANGE_CHECK((real_T)*c3_ASSI_State, 6U);
        *c3_Blue_Light = chartInstance->c3_OFF;
        _SFD_DATA_RANGE_CHECK((real_T)*c3_Blue_Light, 0U);
        *c3_Yellow_Light = chartInstance->c3_OFF;
        _SFD_DATA_RANGE_CHECK((real_T)*c3_Yellow_Light, 1U);
        guard1 = true;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                     chartInstance->c3_sfEvent);
        switch (chartInstance->c3_is_AS_Ready) {
         case c3_IN_Init:
          CV_STATE_EVAL(4, 0, 1);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 15U,
                       chartInstance->c3_sfEvent);
          c3_d_out = (CV_TRANSITION_EVAL(15U, (int32_T)_SFD_CCP_CALL(15U, 0,
            *c3_Origin_Flag == 1.0 != 0U, chartInstance->c3_sfEvent)) != 0);
          if (c3_d_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c3_sfEvent);
            chartInstance->c3_tp_Init = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
            chartInstance->c3_is_AS_Ready = c3_IN_Origin;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
            chartInstance->c3_temporalCounter_i1 = 0U;
            chartInstance->c3_tp_Origin = 1U;
            *c3_Yellow_Light = chartInstance->c3_ON;
            _SFD_DATA_RANGE_CHECK((real_T)*c3_Yellow_Light, 1U);
            *c3_Blue_Light = chartInstance->c3_OFF;
            _SFD_DATA_RANGE_CHECK((real_T)*c3_Blue_Light, 0U);
          } else {
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                         chartInstance->c3_sfEvent);
          }

          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c3_sfEvent);
          guard1 = true;
          break;

         case c3_IN_Origin:
          CV_STATE_EVAL(4, 0, 2);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                       chartInstance->c3_sfEvent);
          c3_j_temp = (_SFD_CCP_CALL(2U, 0, chartInstance->c3_temporalCounter_i1
            >= 100U != 0U, chartInstance->c3_sfEvent) != 0);
          if (c3_j_temp) {
            c3_j_temp = (_SFD_CCP_CALL(2U, 1, *c3_Res_GO != 0U,
              chartInstance->c3_sfEvent) != 0);
          }

          c3_e_out = (CV_TRANSITION_EVAL(2U, (int32_T)c3_j_temp) != 0);
          if (c3_e_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
            chartInstance->c3_tp_Origin = 0U;
            chartInstance->c3_is_AS_Ready = c3_IN_NO_ACTIVE_CHILD;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
            chartInstance->c3_tp_AS_Ready = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
            chartInstance->c3_is_c3_FSAC2021_V1 = c3_IN_AS_Driving;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
            chartInstance->c3_tp_AS_Driving = 1U;
            *c3_R2D = chartInstance->c3_ON;
            _SFD_DATA_RANGE_CHECK((real_T)*c3_R2D, 22U);
            *c3_ASSI_State = chartInstance->c3_AS_DRIVING;
            _SFD_DATA_RANGE_CHECK((real_T)*c3_ASSI_State, 6U);
            *c3_Yellow_Light = chartInstance->c3_BLINK;
            _SFD_DATA_RANGE_CHECK((real_T)*c3_Yellow_Light, 1U);
            *c3_Blue_Light = chartInstance->c3_OFF;
            _SFD_DATA_RANGE_CHECK((real_T)*c3_Blue_Light, 0U);
            *c3_Buzzer = chartInstance->c3_BUZZER_START;
            _SFD_DATA_RANGE_CHECK((real_T)*c3_Buzzer, 2U);
          } else {
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U,
                         chartInstance->c3_sfEvent);
            c3_f_out = (CV_TRANSITION_EVAL(10U, (int32_T)_SFD_CCP_CALL(10U, 0,
              *c3_EBS_Flag == chartInstance->c3_EBS_ENABLE != 0U,
              chartInstance->c3_sfEvent)) != 0);
            if (c3_f_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c3_sfEvent);
              chartInstance->c3_tp_Origin = 0U;
              chartInstance->c3_is_AS_Ready = c3_IN_NO_ACTIVE_CHILD;
              _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
              chartInstance->c3_tp_AS_Ready = 0U;
              _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
              chartInstance->c3_is_c3_FSAC2021_V1 = c3_IN_AS_Emergency;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
              chartInstance->c3_tp_AS_Emergency = 1U;
              *c3_ASSI_State = chartInstance->c3_AS_EMERGENCY;
              _SFD_DATA_RANGE_CHECK((real_T)*c3_ASSI_State, 6U);
              *c3_R2D = chartInstance->c3_OFF;
              _SFD_DATA_RANGE_CHECK((real_T)*c3_R2D, 22U);
              *c3_Yellow_Light = chartInstance->c3_OFF;
              _SFD_DATA_RANGE_CHECK((real_T)*c3_Yellow_Light, 1U);
              *c3_Blue_Light = chartInstance->c3_BLINK;
              _SFD_DATA_RANGE_CHECK((real_T)*c3_Blue_Light, 0U);
              *c3_Buzzer = chartInstance->c3_BUZZER_EBS;
              _SFD_DATA_RANGE_CHECK((real_T)*c3_Buzzer, 2U);
            } else {
              _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                           chartInstance->c3_sfEvent);
            }
          }

          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c3_sfEvent);
          if (chartInstance->c3_is_c3_FSAC2021_V1 != c3_IN_AS_Ready) {
          } else {
            guard1 = true;
          }
          break;

         default:
          CV_STATE_EVAL(4, 0, 0);
          chartInstance->c3_is_AS_Ready = c3_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
          guard1 = true;
          break;
        }
      }

      if (guard1 == true) {
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c3_sfEvent);
      }
      break;

     case c3_IN_Manual_Driving:
      CV_CHART_EVAL(2, 0, 6);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U,
                   chartInstance->c3_sfEvent);
      c3_g_out = (CV_TRANSITION_EVAL(8U, !(_SFD_CCP_CALL(8U, 0, *c3_TS_Flag !=
        0U, chartInstance->c3_sfEvent) != 0)) != 0);
      if (c3_g_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_Manual_Driving = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c3_sfEvent);
        chartInstance->c3_is_c3_FSAC2021_V1 = c3_IN_AS_Off;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
        chartInstance->c3_tp_AS_Off = 1U;
        *c3_ASSI_State = chartInstance->c3_AS_OFF;
        _SFD_DATA_RANGE_CHECK((real_T)*c3_ASSI_State, 6U);
        *c3_Blue_Light = chartInstance->c3_OFF;
        _SFD_DATA_RANGE_CHECK((real_T)*c3_Blue_Light, 0U);
        *c3_Yellow_Light = chartInstance->c3_OFF;
        _SFD_DATA_RANGE_CHECK((real_T)*c3_Yellow_Light, 1U);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U,
                     chartInstance->c3_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c3_sfEvent);
      break;

     default:
      CV_CHART_EVAL(2, 0, 0);
      chartInstance->c3_is_c3_FSAC2021_V1 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
}

static void initSimStructsc3_FSAC2021_V1(SFc3_FSAC2021_V1InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c3_exit_internal_AS_Ready(SFc3_FSAC2021_V1InstanceStruct
  *chartInstance)
{
  switch (chartInstance->c3_is_AS_Ready) {
   case c3_IN_Init:
    CV_STATE_EVAL(4, 1, 1);
    chartInstance->c3_tp_Init = 0U;
    chartInstance->c3_is_AS_Ready = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
    break;

   case c3_IN_Origin:
    CV_STATE_EVAL(4, 1, 2);
    chartInstance->c3_tp_Origin = 0U;
    chartInstance->c3_is_AS_Ready = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(4, 1, 0);
    chartInstance->c3_is_AS_Ready = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
    break;
  }
}

static void c3_AS_Driving(SFc3_FSAC2021_V1InstanceStruct *chartInstance)
{
  boolean_T c3_temp;
  boolean_T c3_out;
  boolean_T c3_b_out;
  real32_T *c3_Veh_Spd;
  uint8_T *c3_Misson_Finished;
  uint8_T *c3_EBS_Flag;
  uint8_T *c3_ASSI_State;
  uint8_T *c3_R2D;
  uint8_T *c3_Yellow_Light;
  uint8_T *c3_Blue_Light;
  uint8_T *c3_Buzzer;
  uint8_T *c3_Safety_Circuit_Relay;
  c3_Misson_Finished = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c3_R2D = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c3_Veh_Spd = (real32_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_ASSI_State = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c3_Safety_Circuit_Relay = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_EBS_Flag = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_Buzzer = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_Yellow_Light = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_Blue_Light = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U, chartInstance->c3_sfEvent);
  c3_temp = (_SFD_CCP_CALL(3U, 0, *c3_Veh_Spd <= 1.0F != 0U,
              chartInstance->c3_sfEvent) != 0);
  if (c3_temp) {
    c3_temp = (_SFD_CCP_CALL(3U, 1, *c3_Misson_Finished != 0U,
                chartInstance->c3_sfEvent) != 0);
  }

  c3_out = (CV_TRANSITION_EVAL(3U, (int32_T)c3_temp) != 0);
  if (c3_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_AS_Driving = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_c3_FSAC2021_V1 = c3_IN_AS_Finished;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_AS_Finished = 1U;
    *c3_ASSI_State = chartInstance->c3_AS_FINISH;
    _SFD_DATA_RANGE_CHECK((real_T)*c3_ASSI_State, 6U);
    *c3_R2D = chartInstance->c3_OFF;
    _SFD_DATA_RANGE_CHECK((real_T)*c3_R2D, 22U);
    *c3_Safety_Circuit_Relay = chartInstance->c3_ON;
    _SFD_DATA_RANGE_CHECK((real_T)*c3_Safety_Circuit_Relay, 5U);
    *c3_Blue_Light = chartInstance->c3_ON;
    _SFD_DATA_RANGE_CHECK((real_T)*c3_Blue_Light, 0U);
    *c3_Yellow_Light = chartInstance->c3_OFF;
    _SFD_DATA_RANGE_CHECK((real_T)*c3_Yellow_Light, 1U);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U, chartInstance->c3_sfEvent);
    c3_b_out = (CV_TRANSITION_EVAL(4U, (int32_T)_SFD_CCP_CALL(4U, 0,
      *c3_EBS_Flag == chartInstance->c3_EBS_ENABLE != 0U,
      chartInstance->c3_sfEvent)) != 0);
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_AS_Driving = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_c3_FSAC2021_V1 = c3_IN_AS_Emergency;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_AS_Emergency = 1U;
      *c3_ASSI_State = chartInstance->c3_AS_EMERGENCY;
      _SFD_DATA_RANGE_CHECK((real_T)*c3_ASSI_State, 6U);
      *c3_R2D = chartInstance->c3_OFF;
      _SFD_DATA_RANGE_CHECK((real_T)*c3_R2D, 22U);
      *c3_Yellow_Light = chartInstance->c3_OFF;
      _SFD_DATA_RANGE_CHECK((real_T)*c3_Yellow_Light, 1U);
      *c3_Blue_Light = chartInstance->c3_BLINK;
      _SFD_DATA_RANGE_CHECK((real_T)*c3_Blue_Light, 0U);
      *c3_Buzzer = chartInstance->c3_BUZZER_EBS;
      _SFD_DATA_RANGE_CHECK((real_T)*c3_Buzzer, 2U);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                   chartInstance->c3_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
}

static void c3_AS_Finished(SFc3_FSAC2021_V1InstanceStruct *chartInstance)
{
  boolean_T c3_out;
  boolean_T c3_b_out;
  uint8_T *c3_Res_EBS;
  uint8_T *c3_ASMS;
  uint8_T *c3_ASSI_State;
  uint8_T *c3_Blue_Light;
  uint8_T *c3_Yellow_Light;
  uint8_T *c3_R2D;
  uint8_T *c3_Buzzer;
  c3_Res_EBS = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c3_R2D = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c3_ASMS = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_ASSI_State = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c3_Buzzer = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_Yellow_Light = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_Blue_Light = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U, chartInstance->c3_sfEvent);
  c3_out = (CV_TRANSITION_EVAL(5U, (int32_T)_SFD_CCP_CALL(5U, 0, *c3_Res_EBS !=
              0U, chartInstance->c3_sfEvent)) != 0);
  if (c3_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_AS_Finished = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_c3_FSAC2021_V1 = c3_IN_AS_Emergency;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_AS_Emergency = 1U;
    *c3_ASSI_State = chartInstance->c3_AS_EMERGENCY;
    _SFD_DATA_RANGE_CHECK((real_T)*c3_ASSI_State, 6U);
    *c3_R2D = chartInstance->c3_OFF;
    _SFD_DATA_RANGE_CHECK((real_T)*c3_R2D, 22U);
    *c3_Yellow_Light = chartInstance->c3_OFF;
    _SFD_DATA_RANGE_CHECK((real_T)*c3_Yellow_Light, 1U);
    *c3_Blue_Light = chartInstance->c3_BLINK;
    _SFD_DATA_RANGE_CHECK((real_T)*c3_Blue_Light, 0U);
    *c3_Buzzer = chartInstance->c3_BUZZER_EBS;
    _SFD_DATA_RANGE_CHECK((real_T)*c3_Buzzer, 2U);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c3_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U, chartInstance->c3_sfEvent);
    c3_b_out = (CV_TRANSITION_EVAL(6U, !(_SFD_CCP_CALL(6U, 0, *c3_ASMS != 0U,
      chartInstance->c3_sfEvent) != 0)) != 0);
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_AS_Finished = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
      chartInstance->c3_is_c3_FSAC2021_V1 = c3_IN_AS_Off;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
      chartInstance->c3_tp_AS_Off = 1U;
      *c3_ASSI_State = chartInstance->c3_AS_OFF;
      _SFD_DATA_RANGE_CHECK((real_T)*c3_ASSI_State, 6U);
      *c3_Blue_Light = chartInstance->c3_OFF;
      _SFD_DATA_RANGE_CHECK((real_T)*c3_Blue_Light, 0U);
      *c3_Yellow_Light = chartInstance->c3_OFF;
      _SFD_DATA_RANGE_CHECK((real_T)*c3_Yellow_Light, 1U);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                   chartInstance->c3_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
}

static void c3_AS_Emergency(SFc3_FSAC2021_V1InstanceStruct *chartInstance)
{
  boolean_T c3_temp;
  boolean_T c3_b_temp;
  boolean_T c3_out;
  uint8_T *c3_ASMS;
  uint8_T *c3_Buzzer_Overflag;
  uint8_T *c3_EBS_Flag;
  uint8_T *c3_ASSI_State;
  uint8_T *c3_Blue_Light;
  uint8_T *c3_Yellow_Light;
  c3_Buzzer_Overflag = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c3_ASMS = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_ASSI_State = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c3_EBS_Flag = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_Yellow_Light = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_Blue_Light = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U, chartInstance->c3_sfEvent);
  c3_temp = !(_SFD_CCP_CALL(9U, 0, *c3_ASMS != 0U, chartInstance->c3_sfEvent) !=
              0);
  if (c3_temp) {
    c3_temp = (_SFD_CCP_CALL(9U, 1, *c3_Buzzer_Overflag != 0U,
                chartInstance->c3_sfEvent) != 0);
  }

  c3_b_temp = c3_temp;
  if (c3_b_temp) {
    c3_b_temp = (_SFD_CCP_CALL(9U, 2, *c3_EBS_Flag ==
      chartInstance->c3_EBS_DISABLE != 0U, chartInstance->c3_sfEvent) != 0);
  }

  c3_out = (CV_TRANSITION_EVAL(9U, (int32_T)c3_b_temp) != 0);
  if (c3_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_AS_Emergency = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_c3_FSAC2021_V1 = c3_IN_AS_Off;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_AS_Off = 1U;
    *c3_ASSI_State = chartInstance->c3_AS_OFF;
    _SFD_DATA_RANGE_CHECK((real_T)*c3_ASSI_State, 6U);
    *c3_Blue_Light = chartInstance->c3_OFF;
    _SFD_DATA_RANGE_CHECK((real_T)*c3_Blue_Light, 0U);
    *c3_Yellow_Light = chartInstance->c3_OFF;
    _SFD_DATA_RANGE_CHECK((real_T)*c3_Yellow_Light, 1U);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber)
{
  (void)c3_machineNumber;
  (void)c3_chartNumber;
  (void)c3_instanceNumber;
}

const mxArray *sf_c3_FSAC2021_V1_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c3_nameCaptureInfo;
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_FSAC2021_V1InstanceStruct *chartInstance;
  chartInstance = (SFc3_FSAC2021_V1InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_emlrt_marshallIn(SFc3_FSAC2021_V1InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i0, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_FSAC2021_V1InstanceStruct *chartInstance;
  chartInstance = (SFc3_FSAC2021_V1InstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent), &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  uint8_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_FSAC2021_V1InstanceStruct *chartInstance;
  chartInstance = (SFc3_FSAC2021_V1InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(uint8_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static uint8_T c3_b_emlrt_marshallIn(SFc3_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c3_b_tp_Manual_Driving, const char_T
  *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tp_Manual_Driving),
    &c3_thisId);
  sf_mex_destroy(&c3_b_tp_Manual_Driving);
  return c3_y;
}

static uint8_T c3_c_emlrt_marshallIn(SFc3_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_tp_Manual_Driving;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  uint8_T c3_y;
  SFc3_FSAC2021_V1InstanceStruct *chartInstance;
  chartInstance = (SFc3_FSAC2021_V1InstanceStruct *)chartInstanceVoid;
  c3_b_tp_Manual_Driving = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tp_Manual_Driving),
    &c3_thisId);
  sf_mex_destroy(&c3_b_tp_Manual_Driving);
  *(uint8_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_FSAC2021_V1InstanceStruct *chartInstance;
  chartInstance = (SFc3_FSAC2021_V1InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 1, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  boolean_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_FSAC2021_V1InstanceStruct *chartInstance;
  chartInstance = (SFc3_FSAC2021_V1InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(boolean_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_FSAC2021_V1InstanceStruct *chartInstance;
  chartInstance = (SFc3_FSAC2021_V1InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static uint32_T c3_d_emlrt_marshallIn(SFc3_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c3_b_previousTicks, const char_T *c3_identifier)
{
  uint32_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_previousTicks),
    &c3_thisId);
  sf_mex_destroy(&c3_b_previousTicks);
  return c3_y;
}

static uint32_T c3_e_emlrt_marshallIn(SFc3_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint32_T c3_y;
  uint32_T c3_u1;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u1, 1, 7, 0U, 0, 0U, 0);
  c3_y = c3_u1;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static const mxArray *c3_f_emlrt_marshallIn(SFc3_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c3_b_setSimStateSideEffectsInfo, const char_T
  *c3_identifier)
{
  const mxArray *c3_y = NULL;
  emlrtMsgIdentifier c3_thisId;
  c3_y = NULL;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  sf_mex_assign(&c3_y, c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_setSimStateSideEffectsInfo), &c3_thisId), false);
  sf_mex_destroy(&c3_b_setSimStateSideEffectsInfo);
  return c3_y;
}

static const mxArray *c3_g_emlrt_marshallIn(SFc3_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  (void)c3_parentId;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_duplicatearraysafe(&c3_u), false);
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info(SFc3_FSAC2021_V1InstanceStruct *chartInstance)
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

void sf_c3_FSAC2021_V1_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(965122455U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(961414688U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3695621074U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1800655189U);
}

mxArray *sf_c3_FSAC2021_V1_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("xMBsDxROtszYGkxtpMCclC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,13,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,12,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,12,"type",mxType);
    }

    mxSetField(mxData,12,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,18,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,12,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,12,"type",mxType);
    }

    mxSetField(mxData,12,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,13,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,13,"type",mxType);
    }

    mxSetField(mxData,13,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,14,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,14,"type",mxType);
    }

    mxSetField(mxData,14,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,15,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,15,"type",mxType);
    }

    mxSetField(mxData,15,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,16,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,16,"type",mxType);
    }

    mxSetField(mxData,16,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,17,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,17,"type",mxType);
    }

    mxSetField(mxData,17,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_FSAC2021_V1_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_FSAC2021_V1_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c3_FSAC2021_V1(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[25],T\"ASSI_State\",},{M[1],M[24],T\"Blue_Light\",},{M[1],M[26],T\"Buzzer\",},{M[1],M[61],T\"R2D\",},{M[1],M[21],T\"Safety_Circuit_Relay\",},{M[1],M[22],T\"Yellow_Light\",},{M[8],M[0],T\"is_active_c3_FSAC2021_V1\",},{M[9],M[0],T\"is_c3_FSAC2021_V1\",},{M[9],M[3],T\"is_AS_Ready\",},{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"at\",M[93],M[1]}}}}",
    "100 S'type','srcId','name','auxInfo'{{M[13],M[0],T\"previousTicks\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 11, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_FSAC2021_V1_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_FSAC2021_V1InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc3_FSAC2021_V1InstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _FSAC2021_V1MachineNumber_,
           3,
           8,
           17,
           0,
           37,
           2,
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
            2,
            2,
            2);
          _SFD_SET_DATA_PROPS(0,2,0,1,"Blue_Light");
          _SFD_SET_DATA_PROPS(1,2,0,1,"Yellow_Light");
          _SFD_SET_DATA_PROPS(2,2,0,1,"Buzzer");
          _SFD_SET_DATA_PROPS(3,1,1,0,"TS_Flag");
          _SFD_SET_DATA_PROPS(4,1,1,0,"EBS_Flag");
          _SFD_SET_DATA_PROPS(5,2,0,1,"Safety_Circuit_Relay");
          _SFD_SET_DATA_PROPS(6,2,0,1,"ASSI_State");
          _SFD_SET_DATA_PROPS(7,1,1,0,"Veh_Spd");
          _SFD_SET_DATA_PROPS(8,1,1,0,"ASMS");
          _SFD_SET_DATA_PROPS(9,10,0,0,"ON");
          _SFD_SET_DATA_PROPS(10,10,0,0,"OFF");
          _SFD_SET_DATA_PROPS(11,10,0,0,"ENABLE");
          _SFD_SET_DATA_PROPS(12,10,0,0,"DISABLE");
          _SFD_SET_DATA_PROPS(13,10,0,0,"AS_OFF");
          _SFD_SET_DATA_PROPS(14,10,0,0,"AS_READY");
          _SFD_SET_DATA_PROPS(15,10,0,0,"AS_DRIVING");
          _SFD_SET_DATA_PROPS(16,10,0,0,"AS_FINISH");
          _SFD_SET_DATA_PROPS(17,10,0,0,"AS_EMERGENCY");
          _SFD_SET_DATA_PROPS(18,10,0,0,"BLINK");
          _SFD_SET_DATA_PROPS(19,10,0,0,"EBS_DISABLE");
          _SFD_SET_DATA_PROPS(20,10,0,0,"EBS_ARMED");
          _SFD_SET_DATA_PROPS(21,10,0,0,"EBS_ENABLE");
          _SFD_SET_DATA_PROPS(22,2,0,1,"R2D");
          _SFD_SET_DATA_PROPS(23,10,0,0,"MANUAL_DRIVING");
          _SFD_SET_DATA_PROPS(24,10,0,0,"MANUAL_MODE");
          _SFD_SET_DATA_PROPS(25,1,1,0,"LVMS");
          _SFD_SET_DATA_PROPS(26,1,1,0,"AMI_State");
          _SFD_SET_DATA_PROPS(27,1,1,0,"Res_EBS");
          _SFD_SET_DATA_PROPS(28,1,1,0,"Res_GO");
          _SFD_SET_DATA_PROPS(29,1,1,0,"START_Flag");
          _SFD_SET_DATA_PROPS(30,1,1,0,"Misson_Finished");
          _SFD_SET_DATA_PROPS(31,1,1,0,"Buzzer_Overflag");
          _SFD_SET_DATA_PROPS(32,10,0,0,"BUZZER_START");
          _SFD_SET_DATA_PROPS(33,10,0,0,"BUZZER_EBS");
          _SFD_SET_DATA_PROPS(34,10,0,0,"TRACKDRIVE");
          _SFD_SET_DATA_PROPS(35,1,1,0,"Brake_Trigeer");
          _SFD_SET_DATA_PROPS(36,1,1,0,"Origin_Flag");
          _SFD_EVENT_SCOPE(0,2);
          _SFD_EVENT_SCOPE(1,2);
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(7,0,0);
          _SFD_CH_SUBSTATE_COUNT(6);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,2);
          _SFD_CH_SUBSTATE_INDEX(3,3);
          _SFD_CH_SUBSTATE_INDEX(4,4);
          _SFD_CH_SUBSTATE_INDEX(5,7);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,2);
          _SFD_ST_SUBSTATE_INDEX(4,0,5);
          _SFD_ST_SUBSTATE_INDEX(4,1,6);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
          _SFD_ST_SUBSTATE_COUNT(7,0);
        }

        _SFD_CV_INIT_CHART(6,1,0,0);

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

        {
          _SFD_CV_INIT_STATE(4,2,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(6,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(7,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 17 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(15,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1, 7, 15, 25, 46, 76 };

          static unsigned int sEndGuardMap[] = { 5, 11, 22, 39, 70, 95 };

          static int sPostFixPredicateTree[] = { 0, 1, -3, 2, -3, 3, -3, 4, -3,
            5, -3 };

          _SFD_CV_INIT_TRANS(0,6,&(sStartGuardMap[0]),&(sEndGuardMap[0]),11,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 2 };

          static unsigned int sEndGuardMap[] = { 6 };

          static int sPostFixPredicateTree[] = { 0, -1 };

          _SFD_CV_INIT_TRANS(1,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),2,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 17 };

          static unsigned int sEndGuardMap[] = { 13, 23 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(2,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 31, 45, 51, 63 };

          static unsigned int sEndGuardMap[] = { 25, 38, 49, 61, 76 };

          static int sPostFixPredicateTree[] = { 0, 1, -3, 2, -1, -3, 3, -3, 4,
            -3 };

          _SFD_CV_INIT_TRANS(7,5,&(sStartGuardMap[0]),&(sEndGuardMap[0]),10,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 21 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(10,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 21 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(4,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1, 20 };

          static unsigned int sEndGuardMap[] = { 13, 35 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(3,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 3 };

          static unsigned int sEndGuardMap[] = { 10 };

          static int sPostFixPredicateTree[] = { 0, -1 };

          _SFD_CV_INIT_TRANS(8,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),2,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 2 };

          static unsigned int sEndGuardMap[] = { 9 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(5,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 2, 9, 31 };

          static unsigned int sEndGuardMap[] = { 6, 24, 53 };

          static int sPostFixPredicateTree[] = { 0, -1, 1, -3, 2, -3 };

          _SFD_CV_INIT_TRANS(9,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),6,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 2 };

          static unsigned int sEndGuardMap[] = { 6 };

          static int sPostFixPredicateTree[] = { 0, -1 };

          _SFD_CV_INIT_TRANS(6,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),2,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(24,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(25,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(26,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(27,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(28,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(29,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(30,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(31,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(32,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(33,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(34,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(35,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(36,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_e_sf_marshallOut,(MexInFcnForType)NULL);

        {
          uint8_T *c3_Blue_Light;
          uint8_T *c3_Yellow_Light;
          uint8_T *c3_Buzzer;
          uint8_T *c3_TS_Flag;
          uint8_T *c3_EBS_Flag;
          uint8_T *c3_Safety_Circuit_Relay;
          uint8_T *c3_ASSI_State;
          real32_T *c3_Veh_Spd;
          uint8_T *c3_ASMS;
          uint8_T *c3_R2D;
          uint8_T *c3_LVMS;
          uint8_T *c3_AMI_State;
          uint8_T *c3_Res_EBS;
          uint8_T *c3_Res_GO;
          uint8_T *c3_START_Flag;
          uint8_T *c3_Misson_Finished;
          uint8_T *c3_Buzzer_Overflag;
          boolean_T *c3_Brake_Trigeer;
          real_T *c3_Origin_Flag;
          c3_Origin_Flag = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
          c3_Brake_Trigeer = (boolean_T *)ssGetInputPortSignal(chartInstance->S,
            11);
          c3_Buzzer_Overflag = (uint8_T *)ssGetInputPortSignal(chartInstance->S,
            10);
          c3_Misson_Finished = (uint8_T *)ssGetInputPortSignal(chartInstance->S,
            9);
          c3_START_Flag = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 8);
          c3_Res_GO = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c3_Res_EBS = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c3_AMI_State = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c3_LVMS = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c3_R2D = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 6);
          c3_ASMS = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c3_Veh_Spd = (real32_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c3_ASSI_State = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c3_Safety_Circuit_Relay = (uint8_T *)ssGetOutputPortSignal
            (chartInstance->S, 4);
          c3_EBS_Flag = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c3_TS_Flag = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c3_Buzzer = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c3_Yellow_Light = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c3_Blue_Light = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_Blue_Light);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_Yellow_Light);
          _SFD_SET_DATA_VALUE_PTR(2U, c3_Buzzer);
          _SFD_SET_DATA_VALUE_PTR(3U, c3_TS_Flag);
          _SFD_SET_DATA_VALUE_PTR(4U, c3_EBS_Flag);
          _SFD_SET_DATA_VALUE_PTR(5U, c3_Safety_Circuit_Relay);
          _SFD_SET_DATA_VALUE_PTR(6U, c3_ASSI_State);
          _SFD_SET_DATA_VALUE_PTR(7U, c3_Veh_Spd);
          _SFD_SET_DATA_VALUE_PTR(8U, c3_ASMS);
          _SFD_SET_DATA_VALUE_PTR(9U, &chartInstance->c3_ON);
          _SFD_SET_DATA_VALUE_PTR(10U, &chartInstance->c3_OFF);
          _SFD_SET_DATA_VALUE_PTR(11U, &chartInstance->c3_ENABLE);
          _SFD_SET_DATA_VALUE_PTR(12U, &chartInstance->c3_DISABLE);
          _SFD_SET_DATA_VALUE_PTR(13U, &chartInstance->c3_AS_OFF);
          _SFD_SET_DATA_VALUE_PTR(14U, &chartInstance->c3_AS_READY);
          _SFD_SET_DATA_VALUE_PTR(15U, &chartInstance->c3_AS_DRIVING);
          _SFD_SET_DATA_VALUE_PTR(16U, &chartInstance->c3_AS_FINISH);
          _SFD_SET_DATA_VALUE_PTR(17U, &chartInstance->c3_AS_EMERGENCY);
          _SFD_SET_DATA_VALUE_PTR(18U, &chartInstance->c3_BLINK);
          _SFD_SET_DATA_VALUE_PTR(19U, &chartInstance->c3_EBS_DISABLE);
          _SFD_SET_DATA_VALUE_PTR(20U, &chartInstance->c3_EBS_ARMED);
          _SFD_SET_DATA_VALUE_PTR(21U, &chartInstance->c3_EBS_ENABLE);
          _SFD_SET_DATA_VALUE_PTR(22U, c3_R2D);
          _SFD_SET_DATA_VALUE_PTR(23U, &chartInstance->c3_MANUAL_DRIVING);
          _SFD_SET_DATA_VALUE_PTR(24U, &chartInstance->c3_MANUAL_MODE);
          _SFD_SET_DATA_VALUE_PTR(25U, c3_LVMS);
          _SFD_SET_DATA_VALUE_PTR(26U, c3_AMI_State);
          _SFD_SET_DATA_VALUE_PTR(27U, c3_Res_EBS);
          _SFD_SET_DATA_VALUE_PTR(28U, c3_Res_GO);
          _SFD_SET_DATA_VALUE_PTR(29U, c3_START_Flag);
          _SFD_SET_DATA_VALUE_PTR(30U, c3_Misson_Finished);
          _SFD_SET_DATA_VALUE_PTR(31U, c3_Buzzer_Overflag);
          _SFD_SET_DATA_VALUE_PTR(32U, &chartInstance->c3_BUZZER_START);
          _SFD_SET_DATA_VALUE_PTR(33U, &chartInstance->c3_BUZZER_EBS);
          _SFD_SET_DATA_VALUE_PTR(34U, &chartInstance->c3_TRACKDRIVE);
          _SFD_SET_DATA_VALUE_PTR(35U, c3_Brake_Trigeer);
          _SFD_SET_DATA_VALUE_PTR(36U, c3_Origin_Flag);
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
  return "dORW6LmAxggYvxbc1KkaqB";
}

static void sf_opaque_initialize_c3_FSAC2021_V1(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_FSAC2021_V1InstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c3_FSAC2021_V1((SFc3_FSAC2021_V1InstanceStruct*)
    chartInstanceVar);
  initialize_c3_FSAC2021_V1((SFc3_FSAC2021_V1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_FSAC2021_V1(void *chartInstanceVar)
{
  enable_c3_FSAC2021_V1((SFc3_FSAC2021_V1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_FSAC2021_V1(void *chartInstanceVar)
{
  disable_c3_FSAC2021_V1((SFc3_FSAC2021_V1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_FSAC2021_V1(void *chartInstanceVar)
{
  sf_gateway_c3_FSAC2021_V1((SFc3_FSAC2021_V1InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_FSAC2021_V1(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_FSAC2021_V1
    ((SFc3_FSAC2021_V1InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_FSAC2021_V1();/* state var info */
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

extern void sf_internal_set_sim_state_c3_FSAC2021_V1(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c3_FSAC2021_V1();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_FSAC2021_V1((SFc3_FSAC2021_V1InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_FSAC2021_V1(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_FSAC2021_V1(S);
}

static void sf_opaque_set_sim_state_c3_FSAC2021_V1(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c3_FSAC2021_V1(S, st);
}

static void sf_opaque_terminate_c3_FSAC2021_V1(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_FSAC2021_V1InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_FSAC2021_V1_optimization_info();
    }

    finalize_c3_FSAC2021_V1((SFc3_FSAC2021_V1InstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_FSAC2021_V1((SFc3_FSAC2021_V1InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_FSAC2021_V1(SimStruct *S)
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
    initialize_params_c3_FSAC2021_V1((SFc3_FSAC2021_V1InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_FSAC2021_V1(SimStruct *S)
{
  /* Actual parameters from chart:
     AS_DRIVING AS_EMERGENCY AS_FINISH AS_OFF AS_READY BLINK BUZZER_EBS BUZZER_START DISABLE EBS_ARMED EBS_DISABLE EBS_ENABLE ENABLE MANUAL_DRIVING MANUAL_MODE OFF ON TRACKDRIVE
   */
  const char_T *rtParamNames[] = { "AS_DRIVING", "AS_EMERGENCY", "AS_FINISH",
    "AS_OFF", "AS_READY", "BLINK", "BUZZER_EBS", "BUZZER_START", "DISABLE",
    "EBS_ARMED", "EBS_DISABLE", "EBS_ENABLE", "ENABLE", "MANUAL_DRIVING",
    "MANUAL_MODE", "OFF", "ON", "TRACKDRIVE" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for AS_DRIVING*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_UINT8);

  /* registration for AS_EMERGENCY*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_UINT8);

  /* registration for AS_FINISH*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_UINT8);

  /* registration for AS_OFF*/
  ssRegDlgParamAsRunTimeParam(S, 3, 3, rtParamNames[3], SS_UINT8);

  /* registration for AS_READY*/
  ssRegDlgParamAsRunTimeParam(S, 4, 4, rtParamNames[4], SS_UINT8);

  /* registration for BLINK*/
  ssRegDlgParamAsRunTimeParam(S, 5, 5, rtParamNames[5], SS_UINT8);

  /* registration for BUZZER_EBS*/
  ssRegDlgParamAsRunTimeParam(S, 6, 6, rtParamNames[6], SS_UINT8);

  /* registration for BUZZER_START*/
  ssRegDlgParamAsRunTimeParam(S, 7, 7, rtParamNames[7], SS_UINT8);

  /* registration for DISABLE*/
  ssRegDlgParamAsRunTimeParam(S, 8, 8, rtParamNames[8], SS_UINT8);

  /* registration for EBS_ARMED*/
  ssRegDlgParamAsRunTimeParam(S, 9, 9, rtParamNames[9], SS_UINT8);

  /* registration for EBS_DISABLE*/
  ssRegDlgParamAsRunTimeParam(S, 10, 10, rtParamNames[10], SS_UINT8);

  /* registration for EBS_ENABLE*/
  ssRegDlgParamAsRunTimeParam(S, 11, 11, rtParamNames[11], SS_UINT8);

  /* registration for ENABLE*/
  ssRegDlgParamAsRunTimeParam(S, 12, 12, rtParamNames[12], SS_UINT8);

  /* registration for MANUAL_DRIVING*/
  ssRegDlgParamAsRunTimeParam(S, 13, 13, rtParamNames[13], SS_UINT8);

  /* registration for MANUAL_MODE*/
  ssRegDlgParamAsRunTimeParam(S, 14, 14, rtParamNames[14], SS_UINT8);

  /* registration for OFF*/
  ssRegDlgParamAsRunTimeParam(S, 15, 15, rtParamNames[15], SS_UINT8);

  /* registration for ON*/
  ssRegDlgParamAsRunTimeParam(S, 16, 16, rtParamNames[16], SS_UINT8);

  /* registration for TRACKDRIVE*/
  ssRegDlgParamAsRunTimeParam(S, 17, 17, rtParamNames[17], SS_UINT8);
  ssSetNeedAbsoluteTime(S,1);
  ssSetModelReferenceSampleTimeDisallowInheritance(S);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_FSAC2021_V1_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,3,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,3);
    sf_mark_output_events_with_multiple_callers(S,sf_get_instance_specialization
      (),infoStruct,3,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 10, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 11, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 12, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,13);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,6);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=6; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 13; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4130813789U));
  ssSetChecksum1(S,(403514903U));
  ssSetChecksum2(S,(1041771918U));
  ssSetChecksum3(S,(4213301618U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_FSAC2021_V1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c3_FSAC2021_V1(SimStruct *S)
{
  SFc3_FSAC2021_V1InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc3_FSAC2021_V1InstanceStruct *)utMalloc(sizeof
    (SFc3_FSAC2021_V1InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_FSAC2021_V1InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_FSAC2021_V1;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c3_FSAC2021_V1;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_FSAC2021_V1;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_FSAC2021_V1;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_FSAC2021_V1;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_FSAC2021_V1;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_FSAC2021_V1;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_FSAC2021_V1;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_FSAC2021_V1;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_FSAC2021_V1;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_FSAC2021_V1;
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

void c3_FSAC2021_V1_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_FSAC2021_V1(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_FSAC2021_V1(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_FSAC2021_V1(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_FSAC2021_V1_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
