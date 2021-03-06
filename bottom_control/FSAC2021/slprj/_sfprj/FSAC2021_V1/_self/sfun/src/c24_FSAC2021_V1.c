/* Include files */

#include <stddef.h>
#include "blas.h"
#include "FSAC2021_V1_sfun.h"
#include "c24_FSAC2021_V1.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "FSAC2021_V1_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c24_debug_family_names[6] = { "nargin", "nargout", "LVMS",
  "ASMS", "ASSI_State", "Relay_48V" };

/* Function Declarations */
static void initialize_c24_FSAC2021_V1(SFc24_FSAC2021_V1InstanceStruct
  *chartInstance);
static void initialize_params_c24_FSAC2021_V1(SFc24_FSAC2021_V1InstanceStruct
  *chartInstance);
static void enable_c24_FSAC2021_V1(SFc24_FSAC2021_V1InstanceStruct
  *chartInstance);
static void disable_c24_FSAC2021_V1(SFc24_FSAC2021_V1InstanceStruct
  *chartInstance);
static void c24_update_debugger_state_c24_FSAC2021_V1
  (SFc24_FSAC2021_V1InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c24_FSAC2021_V1
  (SFc24_FSAC2021_V1InstanceStruct *chartInstance);
static void set_sim_state_c24_FSAC2021_V1(SFc24_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c24_st);
static void finalize_c24_FSAC2021_V1(SFc24_FSAC2021_V1InstanceStruct
  *chartInstance);
static void sf_gateway_c24_FSAC2021_V1(SFc24_FSAC2021_V1InstanceStruct
  *chartInstance);
static void initSimStructsc24_FSAC2021_V1(SFc24_FSAC2021_V1InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c24_machineNumber, uint32_T
  c24_chartNumber, uint32_T c24_instanceNumber);
static const mxArray *c24_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static real_T c24_emlrt_marshallIn(SFc24_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c24_Relay_48V, const char_T *c24_identifier);
static real_T c24_b_emlrt_marshallIn(SFc24_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId);
static void c24_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static const mxArray *c24_b_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static const mxArray *c24_c_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static int32_T c24_c_emlrt_marshallIn(SFc24_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId);
static void c24_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static uint8_T c24_d_emlrt_marshallIn(SFc24_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c24_b_is_active_c24_FSAC2021_V1, const char_T
  *c24_identifier);
static uint8_T c24_e_emlrt_marshallIn(SFc24_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId);
static void init_dsm_address_info(SFc24_FSAC2021_V1InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c24_FSAC2021_V1(SFc24_FSAC2021_V1InstanceStruct
  *chartInstance)
{
  chartInstance->c24_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c24_is_active_c24_FSAC2021_V1 = 0U;
}

static void initialize_params_c24_FSAC2021_V1(SFc24_FSAC2021_V1InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c24_FSAC2021_V1(SFc24_FSAC2021_V1InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c24_FSAC2021_V1(SFc24_FSAC2021_V1InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c24_update_debugger_state_c24_FSAC2021_V1
  (SFc24_FSAC2021_V1InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c24_FSAC2021_V1
  (SFc24_FSAC2021_V1InstanceStruct *chartInstance)
{
  const mxArray *c24_st;
  const mxArray *c24_y = NULL;
  real_T c24_hoistedGlobal;
  real_T c24_u;
  const mxArray *c24_b_y = NULL;
  uint8_T c24_b_hoistedGlobal;
  uint8_T c24_b_u;
  const mxArray *c24_c_y = NULL;
  real_T *c24_Relay_48V;
  c24_Relay_48V = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c24_st = NULL;
  c24_st = NULL;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_createcellmatrix(2, 1), false);
  c24_hoistedGlobal = *c24_Relay_48V;
  c24_u = c24_hoistedGlobal;
  c24_b_y = NULL;
  sf_mex_assign(&c24_b_y, sf_mex_create("y", &c24_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c24_y, 0, c24_b_y);
  c24_b_hoistedGlobal = chartInstance->c24_is_active_c24_FSAC2021_V1;
  c24_b_u = c24_b_hoistedGlobal;
  c24_c_y = NULL;
  sf_mex_assign(&c24_c_y, sf_mex_create("y", &c24_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c24_y, 1, c24_c_y);
  sf_mex_assign(&c24_st, c24_y, false);
  return c24_st;
}

static void set_sim_state_c24_FSAC2021_V1(SFc24_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c24_st)
{
  const mxArray *c24_u;
  real_T *c24_Relay_48V;
  c24_Relay_48V = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c24_doneDoubleBufferReInit = true;
  c24_u = sf_mex_dup(c24_st);
  *c24_Relay_48V = c24_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c24_u, 0)), "Relay_48V");
  chartInstance->c24_is_active_c24_FSAC2021_V1 = c24_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c24_u, 1)),
     "is_active_c24_FSAC2021_V1");
  sf_mex_destroy(&c24_u);
  c24_update_debugger_state_c24_FSAC2021_V1(chartInstance);
  sf_mex_destroy(&c24_st);
}

static void finalize_c24_FSAC2021_V1(SFc24_FSAC2021_V1InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c24_FSAC2021_V1(SFc24_FSAC2021_V1InstanceStruct
  *chartInstance)
{
  uint8_T c24_hoistedGlobal;
  uint8_T c24_b_hoistedGlobal;
  uint8_T c24_c_hoistedGlobal;
  uint8_T c24_LVMS;
  uint8_T c24_ASMS;
  uint8_T c24_ASSI_State;
  uint32_T c24_debug_family_var_map[6];
  real_T c24_nargin = 3.0;
  real_T c24_nargout = 1.0;
  real_T c24_Relay_48V;
  uint8_T *c24_b_LVMS;
  real_T *c24_b_Relay_48V;
  uint8_T *c24_b_ASMS;
  uint8_T *c24_b_ASSI_State;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  c24_b_ASSI_State = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c24_b_ASMS = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c24_b_Relay_48V = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c24_b_LVMS = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 18U, chartInstance->c24_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*c24_b_LVMS, 0U);
  chartInstance->c24_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 18U, chartInstance->c24_sfEvent);
  c24_hoistedGlobal = *c24_b_LVMS;
  c24_b_hoistedGlobal = *c24_b_ASMS;
  c24_c_hoistedGlobal = *c24_b_ASSI_State;
  c24_LVMS = c24_hoistedGlobal;
  c24_ASMS = c24_b_hoistedGlobal;
  c24_ASSI_State = c24_c_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c24_debug_family_names,
    c24_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c24_nargin, 0U, c24_sf_marshallOut,
    c24_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c24_nargout, 1U, c24_sf_marshallOut,
    c24_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c24_LVMS, 2U, c24_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c24_ASMS, 3U, c24_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c24_ASSI_State, 4U, c24_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c24_Relay_48V, 5U, c24_sf_marshallOut,
    c24_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 3);
  c24_Relay_48V = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 4);
  guard1 = false;
  if (CV_EML_COND(0, 1, 0, (real_T)c24_LVMS == 1.0)) {
    if (CV_EML_COND(0, 1, 1, (real_T)c24_ASMS == 1.0)) {
      CV_EML_MCDC(0, 1, 0, true);
      CV_EML_IF(0, 1, 0, true);
      _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 5);
      c24_Relay_48V = 1.0;
      _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 6);
      guard2 = false;
      guard3 = false;
      guard4 = false;
      if (CV_EML_COND(0, 1, 2, (real_T)c24_LVMS == 0.0)) {
        guard4 = true;
      } else if (CV_EML_COND(0, 1, 3, (real_T)c24_ASMS == 0.0)) {
        guard4 = true;
      } else if (CV_EML_COND(0, 1, 4, (real_T)c24_ASSI_State == 0.0)) {
        guard3 = true;
      } else if (CV_EML_COND(0, 1, 5, (real_T)c24_ASSI_State == 4.0)) {
        guard2 = true;
      } else {
        CV_EML_MCDC(0, 1, 1, false);
        CV_EML_IF(0, 1, 1, false);
      }

      if (guard4 == true) {
        guard3 = true;
      }

      if (guard3 == true) {
        guard2 = true;
      }

      if (guard2 == true) {
        CV_EML_MCDC(0, 1, 1, true);
        CV_EML_IF(0, 1, 1, true);
        _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 7);
        c24_Relay_48V = 0.0;
      }
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(0, 1, 0, false);
    CV_EML_IF(0, 1, 0, false);
  }

  _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, -7);
  _SFD_SYMBOL_SCOPE_POP();
  *c24_b_Relay_48V = c24_Relay_48V;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 18U, chartInstance->c24_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_FSAC2021_V1MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c24_b_Relay_48V, 1U);
  _SFD_DATA_RANGE_CHECK((real_T)*c24_b_ASMS, 2U);
  _SFD_DATA_RANGE_CHECK((real_T)*c24_b_ASSI_State, 3U);
}

static void initSimStructsc24_FSAC2021_V1(SFc24_FSAC2021_V1InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c24_machineNumber, uint32_T
  c24_chartNumber, uint32_T c24_instanceNumber)
{
  (void)c24_machineNumber;
  (void)c24_chartNumber;
  (void)c24_instanceNumber;
}

static const mxArray *c24_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  real_T c24_u;
  const mxArray *c24_y = NULL;
  SFc24_FSAC2021_V1InstanceStruct *chartInstance;
  chartInstance = (SFc24_FSAC2021_V1InstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  c24_u = *(real_T *)c24_inData;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", &c24_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, false);
  return c24_mxArrayOutData;
}

static real_T c24_emlrt_marshallIn(SFc24_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c24_Relay_48V, const char_T *c24_identifier)
{
  real_T c24_y;
  emlrtMsgIdentifier c24_thisId;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_Relay_48V),
    &c24_thisId);
  sf_mex_destroy(&c24_Relay_48V);
  return c24_y;
}

static real_T c24_b_emlrt_marshallIn(SFc24_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId)
{
  real_T c24_y;
  real_T c24_d0;
  (void)chartInstance;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), &c24_d0, 1, 0, 0U, 0, 0U, 0);
  c24_y = c24_d0;
  sf_mex_destroy(&c24_u);
  return c24_y;
}

static void c24_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_Relay_48V;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  real_T c24_y;
  SFc24_FSAC2021_V1InstanceStruct *chartInstance;
  chartInstance = (SFc24_FSAC2021_V1InstanceStruct *)chartInstanceVoid;
  c24_Relay_48V = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_Relay_48V),
    &c24_thisId);
  sf_mex_destroy(&c24_Relay_48V);
  *(real_T *)c24_outData = c24_y;
  sf_mex_destroy(&c24_mxArrayInData);
}

static const mxArray *c24_b_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  uint8_T c24_u;
  const mxArray *c24_y = NULL;
  SFc24_FSAC2021_V1InstanceStruct *chartInstance;
  chartInstance = (SFc24_FSAC2021_V1InstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  c24_u = *(uint8_T *)c24_inData;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", &c24_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, false);
  return c24_mxArrayOutData;
}

const mxArray *sf_c24_FSAC2021_V1_get_eml_resolved_functions_info(void)
{
  const mxArray *c24_nameCaptureInfo = NULL;
  c24_nameCaptureInfo = NULL;
  sf_mex_assign(&c24_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c24_nameCaptureInfo;
}

static const mxArray *c24_c_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  int32_T c24_u;
  const mxArray *c24_y = NULL;
  SFc24_FSAC2021_V1InstanceStruct *chartInstance;
  chartInstance = (SFc24_FSAC2021_V1InstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  c24_u = *(int32_T *)c24_inData;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", &c24_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, false);
  return c24_mxArrayOutData;
}

static int32_T c24_c_emlrt_marshallIn(SFc24_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId)
{
  int32_T c24_y;
  int32_T c24_i0;
  (void)chartInstance;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), &c24_i0, 1, 6, 0U, 0, 0U, 0);
  c24_y = c24_i0;
  sf_mex_destroy(&c24_u);
  return c24_y;
}

static void c24_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_b_sfEvent;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  int32_T c24_y;
  SFc24_FSAC2021_V1InstanceStruct *chartInstance;
  chartInstance = (SFc24_FSAC2021_V1InstanceStruct *)chartInstanceVoid;
  c24_b_sfEvent = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_b_sfEvent),
    &c24_thisId);
  sf_mex_destroy(&c24_b_sfEvent);
  *(int32_T *)c24_outData = c24_y;
  sf_mex_destroy(&c24_mxArrayInData);
}

static uint8_T c24_d_emlrt_marshallIn(SFc24_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c24_b_is_active_c24_FSAC2021_V1, const char_T
  *c24_identifier)
{
  uint8_T c24_y;
  emlrtMsgIdentifier c24_thisId;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c24_b_is_active_c24_FSAC2021_V1), &c24_thisId);
  sf_mex_destroy(&c24_b_is_active_c24_FSAC2021_V1);
  return c24_y;
}

static uint8_T c24_e_emlrt_marshallIn(SFc24_FSAC2021_V1InstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId)
{
  uint8_T c24_y;
  uint8_T c24_u0;
  (void)chartInstance;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), &c24_u0, 1, 3, 0U, 0, 0U, 0);
  c24_y = c24_u0;
  sf_mex_destroy(&c24_u);
  return c24_y;
}

static void init_dsm_address_info(SFc24_FSAC2021_V1InstanceStruct *chartInstance)
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

void sf_c24_FSAC2021_V1_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(998472718U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(999960016U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2208647461U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3429342731U);
}

mxArray *sf_c24_FSAC2021_V1_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("IiNba8GVVHT8xJuaL0LZsD");
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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

mxArray *sf_c24_FSAC2021_V1_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c24_FSAC2021_V1_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c24_FSAC2021_V1(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"Relay_48V\",},{M[8],M[0],T\"is_active_c24_FSAC2021_V1\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c24_FSAC2021_V1_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc24_FSAC2021_V1InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc24_FSAC2021_V1InstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _FSAC2021_V1MachineNumber_,
           24,
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
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"LVMS");
          _SFD_SET_DATA_PROPS(1,2,0,1,"Relay_48V");
          _SFD_SET_DATA_PROPS(2,1,1,0,"ASMS");
          _SFD_SET_DATA_PROPS(3,1,1,0,"ASSI_State");
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
        _SFD_CV_INIT_EML(0,1,1,2,0,0,0,0,0,6,2);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,208);
        _SFD_CV_INIT_EML_IF(0,1,0,72,97,-1,208);
        _SFD_CV_INIT_EML_IF(0,1,1,117,180,-1,203);

        {
          static int condStart[] = { 75, 88 };

          static int condEnd[] = { 84, 97 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,75,97,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        {
          static int condStart[] = { 120, 133, 146, 165 };

          static int condEnd[] = { 129, 142, 161, 180 };

          static int pfixExpr[] = { 0, 1, -2, 2, -2, 3, -2 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,120,180,4,2,&(condStart[0]),&(condEnd[0]),
                                7,&(pfixExpr[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c24_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c24_sf_marshallOut,(MexInFcnForType)c24_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c24_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c24_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          uint8_T *c24_LVMS;
          real_T *c24_Relay_48V;
          uint8_T *c24_ASMS;
          uint8_T *c24_ASSI_State;
          c24_ASSI_State = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c24_ASMS = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c24_Relay_48V = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c24_LVMS = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c24_LVMS);
          _SFD_SET_DATA_VALUE_PTR(1U, c24_Relay_48V);
          _SFD_SET_DATA_VALUE_PTR(2U, c24_ASMS);
          _SFD_SET_DATA_VALUE_PTR(3U, c24_ASSI_State);
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
  return "Qx94S3WBxp3tgsYIfzQafC";
}

static void sf_opaque_initialize_c24_FSAC2021_V1(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc24_FSAC2021_V1InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c24_FSAC2021_V1((SFc24_FSAC2021_V1InstanceStruct*)
    chartInstanceVar);
  initialize_c24_FSAC2021_V1((SFc24_FSAC2021_V1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c24_FSAC2021_V1(void *chartInstanceVar)
{
  enable_c24_FSAC2021_V1((SFc24_FSAC2021_V1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c24_FSAC2021_V1(void *chartInstanceVar)
{
  disable_c24_FSAC2021_V1((SFc24_FSAC2021_V1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c24_FSAC2021_V1(void *chartInstanceVar)
{
  sf_gateway_c24_FSAC2021_V1((SFc24_FSAC2021_V1InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c24_FSAC2021_V1(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c24_FSAC2021_V1
    ((SFc24_FSAC2021_V1InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c24_FSAC2021_V1();/* state var info */
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

extern void sf_internal_set_sim_state_c24_FSAC2021_V1(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c24_FSAC2021_V1();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c24_FSAC2021_V1((SFc24_FSAC2021_V1InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c24_FSAC2021_V1(SimStruct* S)
{
  return sf_internal_get_sim_state_c24_FSAC2021_V1(S);
}

static void sf_opaque_set_sim_state_c24_FSAC2021_V1(SimStruct* S, const mxArray *
  st)
{
  sf_internal_set_sim_state_c24_FSAC2021_V1(S, st);
}

static void sf_opaque_terminate_c24_FSAC2021_V1(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc24_FSAC2021_V1InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_FSAC2021_V1_optimization_info();
    }

    finalize_c24_FSAC2021_V1((SFc24_FSAC2021_V1InstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc24_FSAC2021_V1((SFc24_FSAC2021_V1InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c24_FSAC2021_V1(SimStruct *S)
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
    initialize_params_c24_FSAC2021_V1((SFc24_FSAC2021_V1InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c24_FSAC2021_V1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_FSAC2021_V1_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      24);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,24,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,24,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,24);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,24,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,24,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,24);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3902806223U));
  ssSetChecksum1(S,(2562632568U));
  ssSetChecksum2(S,(1068452263U));
  ssSetChecksum3(S,(411535711U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c24_FSAC2021_V1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c24_FSAC2021_V1(SimStruct *S)
{
  SFc24_FSAC2021_V1InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc24_FSAC2021_V1InstanceStruct *)utMalloc(sizeof
    (SFc24_FSAC2021_V1InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc24_FSAC2021_V1InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c24_FSAC2021_V1;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c24_FSAC2021_V1;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c24_FSAC2021_V1;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c24_FSAC2021_V1;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c24_FSAC2021_V1;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c24_FSAC2021_V1;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c24_FSAC2021_V1;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c24_FSAC2021_V1;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c24_FSAC2021_V1;
  chartInstance->chartInfo.mdlStart = mdlStart_c24_FSAC2021_V1;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c24_FSAC2021_V1;
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

void c24_FSAC2021_V1_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c24_FSAC2021_V1(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c24_FSAC2021_V1(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c24_FSAC2021_V1(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c24_FSAC2021_V1_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
