/* Include files */

#include <stddef.h>
#include "blas.h"
#include "FSAC2021_V1_Running_sfun.h"
#include "c13_FSAC2021_V1_Running.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "FSAC2021_V1_Running_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c13_debug_family_names[9] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "aVarTruthTableCondition_3", "nargin", "nargout",
  "Gas_1_Flag", "Gas_2_Flag", "Liquid_Flag", "EBS_Status" };

/* Function Declarations */
static void initialize_c13_FSAC2021_V1_Running
  (SFc13_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void initialize_params_c13_FSAC2021_V1_Running
  (SFc13_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void enable_c13_FSAC2021_V1_Running
  (SFc13_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void disable_c13_FSAC2021_V1_Running
  (SFc13_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void c13_update_debugger_state_c13_FSAC2021_V1_Running
  (SFc13_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c13_FSAC2021_V1_Running
  (SFc13_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void set_sim_state_c13_FSAC2021_V1_Running
  (SFc13_FSAC2021_V1_RunningInstanceStruct *chartInstance, const mxArray *c13_st);
static void finalize_c13_FSAC2021_V1_Running
  (SFc13_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void sf_gateway_c13_FSAC2021_V1_Running
  (SFc13_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void initSimStructsc13_FSAC2021_V1_Running
  (SFc13_FSAC2021_V1_RunningInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c13_machineNumber, uint32_T
  c13_chartNumber, uint32_T c13_instanceNumber);
static const mxArray *c13_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static uint8_T c13_emlrt_marshallIn(SFc13_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c13_EBS_Status, const char_T *c13_identifier);
static uint8_T c13_b_emlrt_marshallIn(SFc13_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_b_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static const mxArray *c13_c_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static real_T c13_c_emlrt_marshallIn(SFc13_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static boolean_T c13_d_emlrt_marshallIn(SFc13_FSAC2021_V1_RunningInstanceStruct *
  chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_d_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static int32_T c13_e_emlrt_marshallIn(SFc13_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static void init_dsm_address_info(SFc13_FSAC2021_V1_RunningInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c13_FSAC2021_V1_Running
  (SFc13_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  chartInstance->c13_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c13_is_active_c13_FSAC2021_V1_Running = 0U;
}

static void initialize_params_c13_FSAC2021_V1_Running
  (SFc13_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c13_FSAC2021_V1_Running
  (SFc13_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c13_FSAC2021_V1_Running
  (SFc13_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c13_update_debugger_state_c13_FSAC2021_V1_Running
  (SFc13_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c13_FSAC2021_V1_Running
  (SFc13_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  const mxArray *c13_st;
  const mxArray *c13_y = NULL;
  uint8_T c13_hoistedGlobal;
  uint8_T c13_u;
  const mxArray *c13_b_y = NULL;
  uint8_T c13_b_hoistedGlobal;
  uint8_T c13_b_u;
  const mxArray *c13_c_y = NULL;
  uint8_T *c13_EBS_Status;
  c13_EBS_Status = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c13_st = NULL;
  c13_st = NULL;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_createcellmatrix(2, 1), false);
  c13_hoistedGlobal = *c13_EBS_Status;
  c13_u = c13_hoistedGlobal;
  c13_b_y = NULL;
  sf_mex_assign(&c13_b_y, sf_mex_create("y", &c13_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c13_y, 0, c13_b_y);
  c13_b_hoistedGlobal = chartInstance->c13_is_active_c13_FSAC2021_V1_Running;
  c13_b_u = c13_b_hoistedGlobal;
  c13_c_y = NULL;
  sf_mex_assign(&c13_c_y, sf_mex_create("y", &c13_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c13_y, 1, c13_c_y);
  sf_mex_assign(&c13_st, c13_y, false);
  return c13_st;
}

static void set_sim_state_c13_FSAC2021_V1_Running
  (SFc13_FSAC2021_V1_RunningInstanceStruct *chartInstance, const mxArray *c13_st)
{
  const mxArray *c13_u;
  uint8_T *c13_EBS_Status;
  c13_EBS_Status = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c13_doneDoubleBufferReInit = true;
  c13_u = sf_mex_dup(c13_st);
  *c13_EBS_Status = c13_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c13_u, 0)), "EBS_Status");
  chartInstance->c13_is_active_c13_FSAC2021_V1_Running = c13_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c13_u, 1)),
     "is_active_c13_FSAC2021_V1_Running");
  sf_mex_destroy(&c13_u);
  c13_update_debugger_state_c13_FSAC2021_V1_Running(chartInstance);
  sf_mex_destroy(&c13_st);
}

static void finalize_c13_FSAC2021_V1_Running
  (SFc13_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c13_FSAC2021_V1_Running
  (SFc13_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  boolean_T c13_hoistedGlobal;
  boolean_T c13_b_hoistedGlobal;
  boolean_T c13_c_hoistedGlobal;
  boolean_T c13_Gas_1_Flag;
  boolean_T c13_Gas_2_Flag;
  boolean_T c13_Liquid_Flag;
  uint32_T c13_debug_family_var_map[9];
  boolean_T c13_aVarTruthTableCondition_1;
  boolean_T c13_aVarTruthTableCondition_2;
  boolean_T c13_aVarTruthTableCondition_3;
  real_T c13_nargin = 3.0;
  real_T c13_nargout = 1.0;
  uint8_T c13_EBS_Status;
  uint8_T c13_u;
  const mxArray *c13_y = NULL;
  uint8_T c13_b_u;
  const mxArray *c13_b_y = NULL;
  uint8_T c13_c_u;
  const mxArray *c13_c_y = NULL;
  uint8_T c13_d_u;
  const mxArray *c13_d_y = NULL;
  boolean_T *c13_b_Gas_1_Flag;
  boolean_T *c13_b_Gas_2_Flag;
  boolean_T *c13_b_Liquid_Flag;
  uint8_T *c13_b_EBS_Status;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  c13_b_EBS_Status = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c13_b_Liquid_Flag = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c13_b_Gas_2_Flag = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c13_b_Gas_1_Flag = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 12U, chartInstance->c13_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*c13_b_Gas_1_Flag, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)*c13_b_Gas_2_Flag, 1U);
  _SFD_DATA_RANGE_CHECK((real_T)*c13_b_Liquid_Flag, 2U);
  chartInstance->c13_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 12U, chartInstance->c13_sfEvent);
  c13_hoistedGlobal = *c13_b_Gas_1_Flag;
  c13_b_hoistedGlobal = *c13_b_Gas_2_Flag;
  c13_c_hoistedGlobal = *c13_b_Liquid_Flag;
  c13_Gas_1_Flag = c13_hoistedGlobal;
  c13_Gas_2_Flag = c13_b_hoistedGlobal;
  c13_Liquid_Flag = c13_c_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c13_debug_family_names,
    c13_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_aVarTruthTableCondition_1, 0U,
    c13_b_sf_marshallOut, c13_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_aVarTruthTableCondition_2, 1U,
    c13_b_sf_marshallOut, c13_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_aVarTruthTableCondition_3, 2U,
    c13_b_sf_marshallOut, c13_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargin, 3U, c13_c_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargout, 4U, c13_c_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c13_Gas_1_Flag, 5U, c13_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c13_Gas_2_Flag, 6U, c13_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c13_Liquid_Flag, 7U, c13_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_EBS_Status, 8U, c13_sf_marshallOut,
    c13_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 3);
  c13_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 4);
  c13_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 5);
  c13_aVarTruthTableCondition_3 = false;
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 10);
  c13_aVarTruthTableCondition_1 = ((real_T)c13_Gas_1_Flag == 0.0);
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 14);
  c13_aVarTruthTableCondition_2 = ((real_T)c13_Gas_2_Flag == 0.0);
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 18);
  c13_aVarTruthTableCondition_3 = ((real_T)c13_Liquid_Flag == 0.0);
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 20);
  guard1 = false;
  if (CV_EML_COND(0, 1, 0, c13_aVarTruthTableCondition_1)) {
    if (CV_EML_COND(0, 1, 1, c13_aVarTruthTableCondition_2)) {
      CV_EML_MCDC(0, 1, 0, true);
      CV_EML_IF(0, 1, 0, true);
      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 21);
      CV_EML_FCN(0, 1);
      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 34);
      c13_EBS_Status = 0U;
      sf_mex_printf("%s =\\n", "EBS_Status");
      c13_u = c13_EBS_Status;
      c13_y = NULL;
      sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 3, 0U, 0U, 0U, 0), false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c13_y);
      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, -34);
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(0, 1, 0, false);
    CV_EML_IF(0, 1, 0, false);
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 22);
    guard2 = false;
    if (!CV_EML_COND(0, 1, 2, c13_aVarTruthTableCondition_1)) {
      if (CV_EML_COND(0, 1, 3, c13_aVarTruthTableCondition_2)) {
        CV_EML_MCDC(0, 1, 1, true);
        CV_EML_IF(0, 1, 1, true);
        _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 23);
        CV_EML_FCN(0, 2);
        _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 40);
        c13_EBS_Status = 1U;
        sf_mex_printf("%s =\\n", "EBS_Status");
        c13_b_u = c13_EBS_Status;
        c13_b_y = NULL;
        sf_mex_assign(&c13_b_y, sf_mex_create("y", &c13_b_u, 3, 0U, 0U, 0U, 0),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c13_b_y);
        _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, -40);
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2 == true) {
      CV_EML_MCDC(0, 1, 1, false);
      CV_EML_IF(0, 1, 1, false);
      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 24);
      guard3 = false;
      guard4 = false;
      if (!CV_EML_COND(0, 1, 4, c13_aVarTruthTableCondition_1)) {
        if (!CV_EML_COND(0, 1, 5, c13_aVarTruthTableCondition_2)) {
          if (!CV_EML_COND(0, 1, 6, c13_aVarTruthTableCondition_3)) {
            CV_EML_MCDC(0, 1, 2, true);
            CV_EML_IF(0, 1, 2, true);
            _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 25);
            CV_EML_FCN(0, 3);
            _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 46);
            c13_EBS_Status = 2U;
            sf_mex_printf("%s =\\n", "EBS_Status");
            c13_c_u = c13_EBS_Status;
            c13_c_y = NULL;
            sf_mex_assign(&c13_c_y, sf_mex_create("y", &c13_c_u, 3, 0U, 0U, 0U,
              0), false);
            sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                              c13_c_y);
            _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, -46);
          } else {
            guard3 = true;
          }
        } else {
          guard4 = true;
        }
      } else {
        guard4 = true;
      }

      if (guard4 == true) {
        guard3 = true;
      }

      if (guard3 == true) {
        CV_EML_MCDC(0, 1, 2, false);
        CV_EML_IF(0, 1, 2, false);
        _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 27);
        CV_EML_FCN(0, 4);
        _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 52);
        c13_EBS_Status = 3U;
        sf_mex_printf("%s =\\n", "EBS_Status");
        c13_d_u = c13_EBS_Status;
        c13_d_y = NULL;
        sf_mex_assign(&c13_d_y, sf_mex_create("y", &c13_d_u, 3, 0U, 0U, 0U, 0),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c13_d_y);
        _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, -52);
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, -27);
  _SFD_SYMBOL_SCOPE_POP();
  *c13_b_EBS_Status = c13_EBS_Status;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c13_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_FSAC2021_V1_RunningMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK((real_T)*c13_b_EBS_Status, 3U);
}

static void initSimStructsc13_FSAC2021_V1_Running
  (SFc13_FSAC2021_V1_RunningInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c13_machineNumber, uint32_T
  c13_chartNumber, uint32_T c13_instanceNumber)
{
  (void)c13_machineNumber;
  (void)c13_chartNumber;
  (void)c13_instanceNumber;
}

static const mxArray *c13_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  uint8_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  chartInstance = (SFc13_FSAC2021_V1_RunningInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(uint8_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

static uint8_T c13_emlrt_marshallIn(SFc13_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c13_EBS_Status, const char_T *c13_identifier)
{
  uint8_T c13_y;
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_EBS_Status),
    &c13_thisId);
  sf_mex_destroy(&c13_EBS_Status);
  return c13_y;
}

static uint8_T c13_b_emlrt_marshallIn(SFc13_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  uint8_T c13_y;
  uint8_T c13_u0;
  (void)chartInstance;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_u0, 1, 3, 0U, 0, 0U, 0);
  c13_y = c13_u0;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_EBS_Status;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  uint8_T c13_y;
  SFc13_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  chartInstance = (SFc13_FSAC2021_V1_RunningInstanceStruct *)chartInstanceVoid;
  c13_EBS_Status = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_EBS_Status),
    &c13_thisId);
  sf_mex_destroy(&c13_EBS_Status);
  *(uint8_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_b_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  boolean_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  chartInstance = (SFc13_FSAC2021_V1_RunningInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(boolean_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

static const mxArray *c13_c_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  real_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  chartInstance = (SFc13_FSAC2021_V1_RunningInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(real_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

static real_T c13_c_emlrt_marshallIn(SFc13_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  real_T c13_y;
  real_T c13_d0;
  (void)chartInstance;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_d0, 1, 0, 0U, 0, 0U, 0);
  c13_y = c13_d0;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_nargout;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y;
  SFc13_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  chartInstance = (SFc13_FSAC2021_V1_RunningInstanceStruct *)chartInstanceVoid;
  c13_nargout = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_nargout),
    &c13_thisId);
  sf_mex_destroy(&c13_nargout);
  *(real_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static boolean_T c13_d_emlrt_marshallIn(SFc13_FSAC2021_V1_RunningInstanceStruct *
  chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  boolean_T c13_y;
  boolean_T c13_b0;
  (void)chartInstance;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_b0, 1, 11, 0U, 0, 0U, 0);
  c13_y = c13_b0;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_aVarTruthTableCondition_3;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  boolean_T c13_y;
  SFc13_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  chartInstance = (SFc13_FSAC2021_V1_RunningInstanceStruct *)chartInstanceVoid;
  c13_aVarTruthTableCondition_3 = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c13_aVarTruthTableCondition_3), &c13_thisId);
  sf_mex_destroy(&c13_aVarTruthTableCondition_3);
  *(boolean_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

const mxArray *sf_c13_FSAC2021_V1_Running_get_eml_resolved_functions_info(void)
{
  const mxArray *c13_nameCaptureInfo = NULL;
  c13_nameCaptureInfo = NULL;
  sf_mex_assign(&c13_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c13_nameCaptureInfo;
}

static const mxArray *c13_d_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  int32_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  chartInstance = (SFc13_FSAC2021_V1_RunningInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(int32_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

static int32_T c13_e_emlrt_marshallIn(SFc13_FSAC2021_V1_RunningInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  int32_T c13_y;
  int32_T c13_i0;
  (void)chartInstance;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_i0, 1, 6, 0U, 0, 0U, 0);
  c13_y = c13_i0;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_b_sfEvent;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  int32_T c13_y;
  SFc13_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  chartInstance = (SFc13_FSAC2021_V1_RunningInstanceStruct *)chartInstanceVoid;
  c13_b_sfEvent = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_sfEvent),
    &c13_thisId);
  sf_mex_destroy(&c13_b_sfEvent);
  *(int32_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static void init_dsm_address_info(SFc13_FSAC2021_V1_RunningInstanceStruct
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

void sf_c13_FSAC2021_V1_Running_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2800090424U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3755509894U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1550353924U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(940463587U);
}

mxArray *sf_c13_FSAC2021_V1_Running_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("DSFaNirOrgxguCdKDYcmWH");
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
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

mxArray *sf_c13_FSAC2021_V1_Running_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c13_FSAC2021_V1_Running_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c13_FSAC2021_V1_Running(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[7],T\"EBS_Status\",},{M[8],M[0],T\"is_active_c13_FSAC2021_V1_Running\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c13_FSAC2021_V1_Running_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc13_FSAC2021_V1_RunningInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc13_FSAC2021_V1_RunningInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _FSAC2021_V1_RunningMachineNumber_,
           13,
           1,
           1,
           0,
           4,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"Gas_1_Flag");
          _SFD_SET_DATA_PROPS(1,1,1,0,"Gas_2_Flag");
          _SFD_SET_DATA_PROPS(2,1,1,0,"Liquid_Flag");
          _SFD_SET_DATA_PROPS(3,2,0,1,"EBS_Status");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,5,3,0,0,0,0,0,7,3);
        _SFD_CV_INIT_EML_FCN(0,0,"tt_blk_kernel",0,-1,662);
        _SFD_CV_INIT_EML_FCN(0,1,"A1",662,-1,715);
        _SFD_CV_INIT_EML_FCN(0,2,"A2",715,-1,766);
        _SFD_CV_INIT_EML_FCN(0,3,"A3",766,-1,818);
        _SFD_CV_INIT_EML_FCN(0,4,"A4",818,-1,863);
        _SFD_CV_INIT_EML_IF(0,1,0,381,440,451,660);
        _SFD_CV_INIT_EML_IF(0,1,1,451,515,526,660);
        _SFD_CV_INIT_EML_IF(0,1,2,526,621,632,660);

        {
          static int condStart[] = { 385, 414 };

          static int condEnd[] = { 410, 439 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,385,439,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 460, 489 };

          static int condEnd[] = { 485, 514 };

          static int pfixExpr[] = { 0, -1, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,459,514,2,2,&(condStart[0]),&(condEnd[0]),
                                4,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 535, 565, 595 };

          static int condEnd[] = { 560, 590, 620 };

          static int pfixExpr[] = { 0, -1, 1, -1, -3, 2, -1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,2,534,620,3,4,&(condStart[0]),&(condEnd[0]),
                                8,&(pfixExpr[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_sf_marshallOut,(MexInFcnForType)c13_sf_marshallIn);

        {
          boolean_T *c13_Gas_1_Flag;
          boolean_T *c13_Gas_2_Flag;
          boolean_T *c13_Liquid_Flag;
          uint8_T *c13_EBS_Status;
          c13_EBS_Status = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c13_Liquid_Flag = (boolean_T *)ssGetInputPortSignal(chartInstance->S,
            2);
          c13_Gas_2_Flag = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c13_Gas_1_Flag = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c13_Gas_1_Flag);
          _SFD_SET_DATA_VALUE_PTR(1U, c13_Gas_2_Flag);
          _SFD_SET_DATA_VALUE_PTR(2U, c13_Liquid_Flag);
          _SFD_SET_DATA_VALUE_PTR(3U, c13_EBS_Status);
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
  return "oRm7tqBreQg8m7iMyAC33F";
}

static void sf_opaque_initialize_c13_FSAC2021_V1_Running(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc13_FSAC2021_V1_RunningInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c13_FSAC2021_V1_Running
    ((SFc13_FSAC2021_V1_RunningInstanceStruct*) chartInstanceVar);
  initialize_c13_FSAC2021_V1_Running((SFc13_FSAC2021_V1_RunningInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c13_FSAC2021_V1_Running(void *chartInstanceVar)
{
  enable_c13_FSAC2021_V1_Running((SFc13_FSAC2021_V1_RunningInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c13_FSAC2021_V1_Running(void *chartInstanceVar)
{
  disable_c13_FSAC2021_V1_Running((SFc13_FSAC2021_V1_RunningInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c13_FSAC2021_V1_Running(void *chartInstanceVar)
{
  sf_gateway_c13_FSAC2021_V1_Running((SFc13_FSAC2021_V1_RunningInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c13_FSAC2021_V1_Running
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c13_FSAC2021_V1_Running
    ((SFc13_FSAC2021_V1_RunningInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c13_FSAC2021_V1_Running();/* state var info */
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

extern void sf_internal_set_sim_state_c13_FSAC2021_V1_Running(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c13_FSAC2021_V1_Running();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c13_FSAC2021_V1_Running((SFc13_FSAC2021_V1_RunningInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c13_FSAC2021_V1_Running(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c13_FSAC2021_V1_Running(S);
}

static void sf_opaque_set_sim_state_c13_FSAC2021_V1_Running(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c13_FSAC2021_V1_Running(S, st);
}

static void sf_opaque_terminate_c13_FSAC2021_V1_Running(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc13_FSAC2021_V1_RunningInstanceStruct*) chartInstanceVar
      )->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_FSAC2021_V1_Running_optimization_info();
    }

    finalize_c13_FSAC2021_V1_Running((SFc13_FSAC2021_V1_RunningInstanceStruct*)
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
  initSimStructsc13_FSAC2021_V1_Running((SFc13_FSAC2021_V1_RunningInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c13_FSAC2021_V1_Running(SimStruct *S)
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
    initialize_params_c13_FSAC2021_V1_Running
      ((SFc13_FSAC2021_V1_RunningInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c13_FSAC2021_V1_Running(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_FSAC2021_V1_Running_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      13);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,13,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,13,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,13);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,13,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,13,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,13);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2380662386U));
  ssSetChecksum1(S,(886508537U));
  ssSetChecksum2(S,(4062642260U));
  ssSetChecksum3(S,(1778735292U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c13_FSAC2021_V1_Running(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Truth Table");
  }
}

static void mdlStart_c13_FSAC2021_V1_Running(SimStruct *S)
{
  SFc13_FSAC2021_V1_RunningInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc13_FSAC2021_V1_RunningInstanceStruct *)utMalloc(sizeof
    (SFc13_FSAC2021_V1_RunningInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc13_FSAC2021_V1_RunningInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c13_FSAC2021_V1_Running;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c13_FSAC2021_V1_Running;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c13_FSAC2021_V1_Running;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c13_FSAC2021_V1_Running;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c13_FSAC2021_V1_Running;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c13_FSAC2021_V1_Running;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c13_FSAC2021_V1_Running;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c13_FSAC2021_V1_Running;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c13_FSAC2021_V1_Running;
  chartInstance->chartInfo.mdlStart = mdlStart_c13_FSAC2021_V1_Running;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c13_FSAC2021_V1_Running;
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

void c13_FSAC2021_V1_Running_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c13_FSAC2021_V1_Running(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c13_FSAC2021_V1_Running(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c13_FSAC2021_V1_Running(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c13_FSAC2021_V1_Running_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
