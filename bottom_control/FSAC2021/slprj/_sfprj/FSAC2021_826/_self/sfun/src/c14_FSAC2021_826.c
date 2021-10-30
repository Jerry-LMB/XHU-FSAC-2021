/* Include files */

#include <stddef.h>
#include "blas.h"
#include "FSAC2021_826_sfun.h"
#include "c14_FSAC2021_826.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "FSAC2021_826_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c14_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c14_IN_Init                    ((uint8_T)1U)
#define c14_IN_Move                    ((uint8_T)2U)
#define c14_IN_Pre_Operation_Mode      ((uint8_T)3U)
#define c14_IN_Goto                    ((uint8_T)1U)
#define c14_IN_Motor_Enable            ((uint8_T)2U)
#define c14_IN_Motor_Move              ((uint8_T)3U)
#define c14_IN_Motor_Stanby            ((uint8_T)4U)
#define c14_IN_Wait                    ((uint8_T)5U)
#define c14_IN_Origin_Aciton_Move      ((uint8_T)1U)
#define c14_IN_Origin_Pos_Set          ((uint8_T)2U)
#define c14_IN_First                   ((uint8_T)1U)
#define c14_IN_Second                  ((uint8_T)2U)
#define c14_IN_Aciton_Move             ((uint8_T)1U)
#define c14_IN_Move_Position_Set       ((uint8_T)2U)
#define c14_IN_Encoder1                ((uint8_T)1U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;

/* Function Declarations */
static void initialize_c14_FSAC2021_826(SFc14_FSAC2021_826InstanceStruct
  *chartInstance);
static void initialize_params_c14_FSAC2021_826(SFc14_FSAC2021_826InstanceStruct *
  chartInstance);
static void enable_c14_FSAC2021_826(SFc14_FSAC2021_826InstanceStruct
  *chartInstance);
static void disable_c14_FSAC2021_826(SFc14_FSAC2021_826InstanceStruct
  *chartInstance);
static void c14_update_debugger_state_c14_FSAC2021_826
  (SFc14_FSAC2021_826InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c14_FSAC2021_826
  (SFc14_FSAC2021_826InstanceStruct *chartInstance);
static void set_sim_state_c14_FSAC2021_826(SFc14_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c14_st);
static void c14_set_sim_state_side_effects_c14_FSAC2021_826
  (SFc14_FSAC2021_826InstanceStruct *chartInstance);
static void finalize_c14_FSAC2021_826(SFc14_FSAC2021_826InstanceStruct
  *chartInstance);
static void sf_gateway_c14_FSAC2021_826(SFc14_FSAC2021_826InstanceStruct
  *chartInstance);
static void initSimStructsc14_FSAC2021_826(SFc14_FSAC2021_826InstanceStruct
  *chartInstance);
static void c14_Move(SFc14_FSAC2021_826InstanceStruct *chartInstance);
static void c14_Wait(SFc14_FSAC2021_826InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c14_machineNumber, uint32_T
  c14_chartNumber, uint32_T c14_instanceNumber);
static const mxArray *c14_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static int32_T c14_emlrt_marshallIn(SFc14_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static const mxArray *c14_b_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static uint8_T c14_b_emlrt_marshallIn(SFc14_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c14_b_tp_Pre_Operation_Mode, const char_T
  *c14_identifier);
static uint8_T c14_c_emlrt_marshallIn(SFc14_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static const mxArray *c14_c_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static real32_T c14_d_emlrt_marshallIn(SFc14_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c14_Position_set, const char_T *c14_identifier);
static real32_T c14_e_emlrt_marshallIn(SFc14_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static const mxArray *c14_d_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static void c14_f_emlrt_marshallIn(SFc14_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c14_Encoder_Msg_Data, const char_T
  *c14_identifier, uint8_T c14_y[6]);
static void c14_g_emlrt_marshallIn(SFc14_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  uint8_T c14_y[6]);
static void c14_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static const mxArray *c14_e_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static real_T c14_h_emlrt_marshallIn(SFc14_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c14_Original_Flag, const char_T *c14_identifier);
static real_T c14_i_emlrt_marshallIn(SFc14_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static const mxArray *c14_f_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static uint32_T c14_j_emlrt_marshallIn(SFc14_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c14_b_previousTicks, const char_T
  *c14_identifier);
static uint32_T c14_k_emlrt_marshallIn(SFc14_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static const mxArray *c14_l_emlrt_marshallIn(SFc14_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c14_b_setSimStateSideEffectsInfo, const char_T *
  c14_identifier);
static const mxArray *c14_m_emlrt_marshallIn(SFc14_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void init_dsm_address_info(SFc14_FSAC2021_826InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c14_FSAC2021_826(SFc14_FSAC2021_826InstanceStruct
  *chartInstance)
{
  int32_T c14_i0;
  uint8_T *c14_NMT_nodeorder;
  uint8_T *c14_NMT_nodectrl;
  uint8_T *c14_Enable_Operation_Ctrl;
  uint8_T *c14_Quick_Stop_Ctrl;
  uint8_T *c14_Enable_Voltage_Ctrl;
  uint8_T *c14_Halt_Ctrl;
  uint8_T *c14_Switch_On_Ctrl;
  uint8_T *c14_Abs_or_Rel_Ctrl;
  uint8_T *c14_New_Set_Point_Ctrl;
  real32_T *c14_Position_set;
  real_T *c14_Original_Flag;
  real_T *c14_Fault_Resrt;
  real_T *c14_flag;
  real_T *c14_enflag;
  uint8_T (*c14_Encoder_Msg_Data)[6];
  c14_enflag = (real_T *)ssGetOutputPortSignal(chartInstance->S, 15);
  c14_flag = (real_T *)ssGetOutputPortSignal(chartInstance->S, 14);
  c14_Fault_Resrt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
  c14_Original_Flag = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c14_Encoder_Msg_Data = (uint8_T (*)[6])ssGetOutputPortSignal(chartInstance->S,
    11);
  c14_Position_set = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c14_New_Set_Point_Ctrl = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c14_Abs_or_Rel_Ctrl = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c14_Switch_On_Ctrl = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c14_Halt_Ctrl = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c14_Enable_Voltage_Ctrl = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c14_Quick_Stop_Ctrl = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c14_Enable_Operation_Ctrl = (uint8_T *)ssGetOutputPortSignal(chartInstance->S,
    3);
  c14_NMT_nodectrl = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c14_NMT_nodeorder = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c14_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c14_doSetSimStateSideEffects = 0U;
  chartInstance->c14_setSimStateSideEffectsInfo = NULL;
  chartInstance->c14_tp_Init = 0U;
  chartInstance->c14_is_Move = c14_IN_NO_ACTIVE_CHILD;
  chartInstance->c14_tp_Move = 0U;
  chartInstance->c14_is_Goto = c14_IN_NO_ACTIVE_CHILD;
  chartInstance->c14_tp_Goto = 0U;
  chartInstance->c14_tp_Origin_Aciton_Move = 0U;
  chartInstance->c14_tp_Origin_Pos_Set = 0U;
  chartInstance->c14_is_Motor_Enable = c14_IN_NO_ACTIVE_CHILD;
  chartInstance->c14_tp_Motor_Enable = 0U;
  chartInstance->c14_tp_First = 0U;
  chartInstance->c14_tp_Second = 0U;
  chartInstance->c14_is_Motor_Move = c14_IN_NO_ACTIVE_CHILD;
  chartInstance->c14_tp_Motor_Move = 0U;
  chartInstance->c14_tp_Aciton_Move = 0U;
  chartInstance->c14_tp_Move_Position_Set = 0U;
  chartInstance->c14_is_Motor_Stanby = c14_IN_NO_ACTIVE_CHILD;
  chartInstance->c14_tp_Motor_Stanby = 0U;
  chartInstance->c14_tp_Encoder1 = 0U;
  chartInstance->c14_tp_Wait = 0U;
  chartInstance->c14_temporalCounter_i1 = 0U;
  chartInstance->c14_tp_Pre_Operation_Mode = 0U;
  chartInstance->c14_is_active_c14_FSAC2021_826 = 0U;
  chartInstance->c14_is_c14_FSAC2021_826 = c14_IN_NO_ACTIVE_CHILD;
  if (!(sf_get_output_port_reusable(chartInstance->S, 1) != 0)) {
    *c14_NMT_nodeorder = 0U;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 2) != 0)) {
    *c14_NMT_nodectrl = 0U;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 3) != 0)) {
    *c14_Enable_Operation_Ctrl = 0U;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 4) != 0)) {
    *c14_Quick_Stop_Ctrl = 0U;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 5) != 0)) {
    *c14_Enable_Voltage_Ctrl = 0U;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 6) != 0)) {
    *c14_Halt_Ctrl = 0U;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 7) != 0)) {
    *c14_Switch_On_Ctrl = 0U;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 8) != 0)) {
    *c14_Abs_or_Rel_Ctrl = 0U;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 9) != 0)) {
    *c14_New_Set_Point_Ctrl = 0U;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 10) != 0)) {
    *c14_Position_set = 0.0F;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 11) != 0)) {
    for (c14_i0 = 0; c14_i0 < 6; c14_i0++) {
      (*c14_Encoder_Msg_Data)[c14_i0] = 0U;
    }
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 12) != 0)) {
    *c14_Original_Flag = 0.0;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 13) != 0)) {
    *c14_Fault_Resrt = 0.0;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 14) != 0)) {
    *c14_flag = 0.0;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 15) != 0)) {
    *c14_enflag = 0.0;
  }

  chartInstance->c14_presentTicks = 0U;
  chartInstance->c14_elapsedTicks = 0U;
  chartInstance->c14_previousTicks = 0U;
}

static void initialize_params_c14_FSAC2021_826(SFc14_FSAC2021_826InstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c14_FSAC2021_826(SFc14_FSAC2021_826InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  sf_call_output_fcn_enable(chartInstance->S, 0, "TmtNMTCAN", 0);
  sf_call_output_fcn_enable(chartInstance->S, 1, "TmtRPDO1CAN", 0);
  sf_call_output_fcn_enable(chartInstance->S, 2, "TmtSDOCAN", 0);
  chartInstance->c14_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ /
    0.05 + 0.5);
  chartInstance->c14_previousTicks = chartInstance->c14_presentTicks;
}

static void disable_c14_FSAC2021_826(SFc14_FSAC2021_826InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c14_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ /
    0.05 + 0.5);
  chartInstance->c14_elapsedTicks = chartInstance->c14_presentTicks -
    chartInstance->c14_previousTicks;
  chartInstance->c14_previousTicks = chartInstance->c14_presentTicks;
  if ((uint32_T)chartInstance->c14_temporalCounter_i1 +
      chartInstance->c14_elapsedTicks <= 31U) {
    chartInstance->c14_temporalCounter_i1 = (uint8_T)((uint32_T)
      chartInstance->c14_temporalCounter_i1 + chartInstance->c14_elapsedTicks);
  } else {
    chartInstance->c14_temporalCounter_i1 = 31U;
  }

  sf_call_output_fcn_disable(chartInstance->S, 0, "TmtNMTCAN", 0);
  sf_call_output_fcn_disable(chartInstance->S, 1, "TmtRPDO1CAN", 0);
  sf_call_output_fcn_disable(chartInstance->S, 2, "TmtSDOCAN", 0);
}

static void c14_update_debugger_state_c14_FSAC2021_826
  (SFc14_FSAC2021_826InstanceStruct *chartInstance)
{
  uint32_T c14_prevAniVal;
  c14_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c14_is_active_c14_FSAC2021_826 == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 12U, chartInstance->c14_sfEvent);
  }

  if (chartInstance->c14_is_c14_FSAC2021_826 == c14_IN_Pre_Operation_Mode) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c14_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c14_sfEvent);
  }

  if (chartInstance->c14_is_c14_FSAC2021_826 == c14_IN_Init) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c14_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c14_sfEvent);
  }

  if (chartInstance->c14_is_c14_FSAC2021_826 == c14_IN_Move) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c14_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c14_sfEvent);
  }

  if (chartInstance->c14_is_Move == c14_IN_Goto) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c14_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c14_sfEvent);
  }

  if (chartInstance->c14_is_Goto == c14_IN_Origin_Pos_Set) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c14_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c14_sfEvent);
  }

  if (chartInstance->c14_is_Goto == c14_IN_Origin_Aciton_Move) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c14_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c14_sfEvent);
  }

  if (chartInstance->c14_is_Move == c14_IN_Motor_Enable) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c14_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c14_sfEvent);
  }

  if (chartInstance->c14_is_Motor_Enable == c14_IN_First) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c14_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c14_sfEvent);
  }

  if (chartInstance->c14_is_Motor_Enable == c14_IN_Second) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c14_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c14_sfEvent);
  }

  if (chartInstance->c14_is_Move == c14_IN_Motor_Move) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c14_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c14_sfEvent);
  }

  if (chartInstance->c14_is_Motor_Move == c14_IN_Move_Position_Set) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c14_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c14_sfEvent);
  }

  if (chartInstance->c14_is_Motor_Move == c14_IN_Aciton_Move) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c14_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c14_sfEvent);
  }

  if (chartInstance->c14_is_Move == c14_IN_Wait) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c14_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c14_sfEvent);
  }

  if (chartInstance->c14_is_Move == c14_IN_Motor_Stanby) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c14_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c14_sfEvent);
  }

  if (chartInstance->c14_is_Motor_Stanby == c14_IN_Encoder1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c14_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c14_sfEvent);
  }

  _SFD_SET_ANIMATION(c14_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c14_FSAC2021_826
  (SFc14_FSAC2021_826InstanceStruct *chartInstance)
{
  const mxArray *c14_st;
  const mxArray *c14_y = NULL;
  uint8_T c14_hoistedGlobal;
  uint8_T c14_u;
  const mxArray *c14_b_y = NULL;
  uint8_T c14_b_hoistedGlobal;
  uint8_T c14_b_u;
  const mxArray *c14_c_y = NULL;
  uint8_T c14_c_hoistedGlobal;
  uint8_T c14_c_u;
  const mxArray *c14_d_y = NULL;
  int32_T c14_i1;
  uint8_T c14_d_u[6];
  const mxArray *c14_e_y = NULL;
  real_T c14_d_hoistedGlobal;
  real_T c14_e_u;
  const mxArray *c14_f_y = NULL;
  uint8_T c14_e_hoistedGlobal;
  uint8_T c14_f_u;
  const mxArray *c14_g_y = NULL;
  uint8_T c14_f_hoistedGlobal;
  uint8_T c14_g_u;
  const mxArray *c14_h_y = NULL;
  uint8_T c14_g_hoistedGlobal;
  uint8_T c14_h_u;
  const mxArray *c14_i_y = NULL;
  uint8_T c14_h_hoistedGlobal;
  uint8_T c14_i_u;
  const mxArray *c14_j_y = NULL;
  real_T c14_i_hoistedGlobal;
  real_T c14_j_u;
  const mxArray *c14_k_y = NULL;
  real32_T c14_j_hoistedGlobal;
  real32_T c14_k_u;
  const mxArray *c14_l_y = NULL;
  uint8_T c14_k_hoistedGlobal;
  uint8_T c14_l_u;
  const mxArray *c14_m_y = NULL;
  uint8_T c14_l_hoistedGlobal;
  uint8_T c14_m_u;
  const mxArray *c14_n_y = NULL;
  real_T c14_m_hoistedGlobal;
  real_T c14_n_u;
  const mxArray *c14_o_y = NULL;
  real_T c14_n_hoistedGlobal;
  real_T c14_o_u;
  const mxArray *c14_p_y = NULL;
  uint8_T c14_o_hoistedGlobal;
  uint8_T c14_p_u;
  const mxArray *c14_q_y = NULL;
  uint8_T c14_p_hoistedGlobal;
  uint8_T c14_q_u;
  const mxArray *c14_r_y = NULL;
  uint8_T c14_q_hoistedGlobal;
  uint8_T c14_r_u;
  const mxArray *c14_s_y = NULL;
  uint8_T c14_r_hoistedGlobal;
  uint8_T c14_s_u;
  const mxArray *c14_t_y = NULL;
  uint8_T c14_s_hoistedGlobal;
  uint8_T c14_t_u;
  const mxArray *c14_u_y = NULL;
  uint8_T c14_t_hoistedGlobal;
  uint8_T c14_u_u;
  const mxArray *c14_v_y = NULL;
  uint8_T c14_u_hoistedGlobal;
  uint8_T c14_v_u;
  const mxArray *c14_w_y = NULL;
  uint8_T c14_v_hoistedGlobal;
  uint8_T c14_w_u;
  const mxArray *c14_x_y = NULL;
  uint32_T c14_w_hoistedGlobal;
  uint32_T c14_x_u;
  const mxArray *c14_y_y = NULL;
  uint8_T *c14_Abs_or_Rel_Ctrl;
  uint8_T *c14_Enable_Operation_Ctrl;
  uint8_T *c14_Enable_Voltage_Ctrl;
  real_T *c14_Fault_Resrt;
  uint8_T *c14_Halt_Ctrl;
  uint8_T *c14_NMT_nodectrl;
  uint8_T *c14_NMT_nodeorder;
  uint8_T *c14_New_Set_Point_Ctrl;
  real_T *c14_Original_Flag;
  real32_T *c14_Position_set;
  uint8_T *c14_Quick_Stop_Ctrl;
  uint8_T *c14_Switch_On_Ctrl;
  real_T *c14_enflag;
  real_T *c14_flag;
  uint8_T (*c14_Encoder_Msg_Data)[6];
  c14_enflag = (real_T *)ssGetOutputPortSignal(chartInstance->S, 15);
  c14_flag = (real_T *)ssGetOutputPortSignal(chartInstance->S, 14);
  c14_Fault_Resrt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
  c14_Original_Flag = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c14_Encoder_Msg_Data = (uint8_T (*)[6])ssGetOutputPortSignal(chartInstance->S,
    11);
  c14_Position_set = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c14_New_Set_Point_Ctrl = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c14_Abs_or_Rel_Ctrl = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c14_Switch_On_Ctrl = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c14_Halt_Ctrl = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c14_Enable_Voltage_Ctrl = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c14_Quick_Stop_Ctrl = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c14_Enable_Operation_Ctrl = (uint8_T *)ssGetOutputPortSignal(chartInstance->S,
    3);
  c14_NMT_nodectrl = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c14_NMT_nodeorder = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c14_st = NULL;
  c14_st = NULL;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_createcellmatrix(24, 1), false);
  c14_hoistedGlobal = *c14_Abs_or_Rel_Ctrl;
  c14_u = c14_hoistedGlobal;
  c14_b_y = NULL;
  sf_mex_assign(&c14_b_y, sf_mex_create("y", &c14_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c14_y, 0, c14_b_y);
  c14_b_hoistedGlobal = *c14_Enable_Operation_Ctrl;
  c14_b_u = c14_b_hoistedGlobal;
  c14_c_y = NULL;
  sf_mex_assign(&c14_c_y, sf_mex_create("y", &c14_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c14_y, 1, c14_c_y);
  c14_c_hoistedGlobal = *c14_Enable_Voltage_Ctrl;
  c14_c_u = c14_c_hoistedGlobal;
  c14_d_y = NULL;
  sf_mex_assign(&c14_d_y, sf_mex_create("y", &c14_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c14_y, 2, c14_d_y);
  for (c14_i1 = 0; c14_i1 < 6; c14_i1++) {
    c14_d_u[c14_i1] = (*c14_Encoder_Msg_Data)[c14_i1];
  }

  c14_e_y = NULL;
  sf_mex_assign(&c14_e_y, sf_mex_create("y", c14_d_u, 3, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_setcell(c14_y, 3, c14_e_y);
  c14_d_hoistedGlobal = *c14_Fault_Resrt;
  c14_e_u = c14_d_hoistedGlobal;
  c14_f_y = NULL;
  sf_mex_assign(&c14_f_y, sf_mex_create("y", &c14_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c14_y, 4, c14_f_y);
  c14_e_hoistedGlobal = *c14_Halt_Ctrl;
  c14_f_u = c14_e_hoistedGlobal;
  c14_g_y = NULL;
  sf_mex_assign(&c14_g_y, sf_mex_create("y", &c14_f_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c14_y, 5, c14_g_y);
  c14_f_hoistedGlobal = *c14_NMT_nodectrl;
  c14_g_u = c14_f_hoistedGlobal;
  c14_h_y = NULL;
  sf_mex_assign(&c14_h_y, sf_mex_create("y", &c14_g_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c14_y, 6, c14_h_y);
  c14_g_hoistedGlobal = *c14_NMT_nodeorder;
  c14_h_u = c14_g_hoistedGlobal;
  c14_i_y = NULL;
  sf_mex_assign(&c14_i_y, sf_mex_create("y", &c14_h_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c14_y, 7, c14_i_y);
  c14_h_hoistedGlobal = *c14_New_Set_Point_Ctrl;
  c14_i_u = c14_h_hoistedGlobal;
  c14_j_y = NULL;
  sf_mex_assign(&c14_j_y, sf_mex_create("y", &c14_i_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c14_y, 8, c14_j_y);
  c14_i_hoistedGlobal = *c14_Original_Flag;
  c14_j_u = c14_i_hoistedGlobal;
  c14_k_y = NULL;
  sf_mex_assign(&c14_k_y, sf_mex_create("y", &c14_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c14_y, 9, c14_k_y);
  c14_j_hoistedGlobal = *c14_Position_set;
  c14_k_u = c14_j_hoistedGlobal;
  c14_l_y = NULL;
  sf_mex_assign(&c14_l_y, sf_mex_create("y", &c14_k_u, 1, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c14_y, 10, c14_l_y);
  c14_k_hoistedGlobal = *c14_Quick_Stop_Ctrl;
  c14_l_u = c14_k_hoistedGlobal;
  c14_m_y = NULL;
  sf_mex_assign(&c14_m_y, sf_mex_create("y", &c14_l_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c14_y, 11, c14_m_y);
  c14_l_hoistedGlobal = *c14_Switch_On_Ctrl;
  c14_m_u = c14_l_hoistedGlobal;
  c14_n_y = NULL;
  sf_mex_assign(&c14_n_y, sf_mex_create("y", &c14_m_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c14_y, 12, c14_n_y);
  c14_m_hoistedGlobal = *c14_enflag;
  c14_n_u = c14_m_hoistedGlobal;
  c14_o_y = NULL;
  sf_mex_assign(&c14_o_y, sf_mex_create("y", &c14_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c14_y, 13, c14_o_y);
  c14_n_hoistedGlobal = *c14_flag;
  c14_o_u = c14_n_hoistedGlobal;
  c14_p_y = NULL;
  sf_mex_assign(&c14_p_y, sf_mex_create("y", &c14_o_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c14_y, 14, c14_p_y);
  c14_o_hoistedGlobal = chartInstance->c14_is_active_c14_FSAC2021_826;
  c14_p_u = c14_o_hoistedGlobal;
  c14_q_y = NULL;
  sf_mex_assign(&c14_q_y, sf_mex_create("y", &c14_p_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c14_y, 15, c14_q_y);
  c14_p_hoistedGlobal = chartInstance->c14_is_c14_FSAC2021_826;
  c14_q_u = c14_p_hoistedGlobal;
  c14_r_y = NULL;
  sf_mex_assign(&c14_r_y, sf_mex_create("y", &c14_q_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c14_y, 16, c14_r_y);
  c14_q_hoistedGlobal = chartInstance->c14_is_Goto;
  c14_r_u = c14_q_hoistedGlobal;
  c14_s_y = NULL;
  sf_mex_assign(&c14_s_y, sf_mex_create("y", &c14_r_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c14_y, 17, c14_s_y);
  c14_r_hoistedGlobal = chartInstance->c14_is_Motor_Stanby;
  c14_s_u = c14_r_hoistedGlobal;
  c14_t_y = NULL;
  sf_mex_assign(&c14_t_y, sf_mex_create("y", &c14_s_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c14_y, 18, c14_t_y);
  c14_s_hoistedGlobal = chartInstance->c14_is_Motor_Move;
  c14_t_u = c14_s_hoistedGlobal;
  c14_u_y = NULL;
  sf_mex_assign(&c14_u_y, sf_mex_create("y", &c14_t_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c14_y, 19, c14_u_y);
  c14_t_hoistedGlobal = chartInstance->c14_is_Motor_Enable;
  c14_u_u = c14_t_hoistedGlobal;
  c14_v_y = NULL;
  sf_mex_assign(&c14_v_y, sf_mex_create("y", &c14_u_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c14_y, 20, c14_v_y);
  c14_u_hoistedGlobal = chartInstance->c14_is_Move;
  c14_v_u = c14_u_hoistedGlobal;
  c14_w_y = NULL;
  sf_mex_assign(&c14_w_y, sf_mex_create("y", &c14_v_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c14_y, 21, c14_w_y);
  c14_v_hoistedGlobal = chartInstance->c14_temporalCounter_i1;
  c14_w_u = c14_v_hoistedGlobal;
  c14_x_y = NULL;
  sf_mex_assign(&c14_x_y, sf_mex_create("y", &c14_w_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c14_y, 22, c14_x_y);
  c14_w_hoistedGlobal = chartInstance->c14_previousTicks;
  c14_x_u = c14_w_hoistedGlobal;
  c14_y_y = NULL;
  sf_mex_assign(&c14_y_y, sf_mex_create("y", &c14_x_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c14_y, 23, c14_y_y);
  sf_mex_assign(&c14_st, c14_y, false);
  return c14_st;
}

static void set_sim_state_c14_FSAC2021_826(SFc14_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c14_st)
{
  const mxArray *c14_u;
  uint8_T c14_uv0[6];
  int32_T c14_i2;
  uint8_T *c14_Abs_or_Rel_Ctrl;
  uint8_T *c14_Enable_Operation_Ctrl;
  uint8_T *c14_Enable_Voltage_Ctrl;
  real_T *c14_Fault_Resrt;
  uint8_T *c14_Halt_Ctrl;
  uint8_T *c14_NMT_nodectrl;
  uint8_T *c14_NMT_nodeorder;
  uint8_T *c14_New_Set_Point_Ctrl;
  real_T *c14_Original_Flag;
  real32_T *c14_Position_set;
  uint8_T *c14_Quick_Stop_Ctrl;
  uint8_T *c14_Switch_On_Ctrl;
  real_T *c14_enflag;
  real_T *c14_flag;
  uint8_T (*c14_Encoder_Msg_Data)[6];
  c14_enflag = (real_T *)ssGetOutputPortSignal(chartInstance->S, 15);
  c14_flag = (real_T *)ssGetOutputPortSignal(chartInstance->S, 14);
  c14_Fault_Resrt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
  c14_Original_Flag = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c14_Encoder_Msg_Data = (uint8_T (*)[6])ssGetOutputPortSignal(chartInstance->S,
    11);
  c14_Position_set = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c14_New_Set_Point_Ctrl = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c14_Abs_or_Rel_Ctrl = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c14_Switch_On_Ctrl = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c14_Halt_Ctrl = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c14_Enable_Voltage_Ctrl = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c14_Quick_Stop_Ctrl = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c14_Enable_Operation_Ctrl = (uint8_T *)ssGetOutputPortSignal(chartInstance->S,
    3);
  c14_NMT_nodectrl = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c14_NMT_nodeorder = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c14_u = sf_mex_dup(c14_st);
  *c14_Abs_or_Rel_Ctrl = c14_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c14_u, 0)), "Abs_or_Rel_Ctrl");
  *c14_Enable_Operation_Ctrl = c14_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c14_u, 1)), "Enable_Operation_Ctrl");
  *c14_Enable_Voltage_Ctrl = c14_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c14_u, 2)), "Enable_Voltage_Ctrl");
  c14_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c14_u, 3)),
    "Encoder_Msg_Data", c14_uv0);
  for (c14_i2 = 0; c14_i2 < 6; c14_i2++) {
    (*c14_Encoder_Msg_Data)[c14_i2] = c14_uv0[c14_i2];
  }

  *c14_Fault_Resrt = c14_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c14_u, 4)), "Fault_Resrt");
  *c14_Halt_Ctrl = c14_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c14_u, 5)), "Halt_Ctrl");
  *c14_NMT_nodectrl = c14_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c14_u, 6)), "NMT_nodectrl");
  *c14_NMT_nodeorder = c14_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c14_u, 7)), "NMT_nodeorder");
  *c14_New_Set_Point_Ctrl = c14_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c14_u, 8)), "New_Set_Point_Ctrl");
  *c14_Original_Flag = c14_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c14_u, 9)), "Original_Flag");
  *c14_Position_set = c14_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c14_u, 10)), "Position_set");
  *c14_Quick_Stop_Ctrl = c14_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c14_u, 11)), "Quick_Stop_Ctrl");
  *c14_Switch_On_Ctrl = c14_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c14_u, 12)), "Switch_On_Ctrl");
  *c14_enflag = c14_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c14_u, 13)), "enflag");
  *c14_flag = c14_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c14_u, 14)), "flag");
  chartInstance->c14_is_active_c14_FSAC2021_826 = c14_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c14_u, 15)),
     "is_active_c14_FSAC2021_826");
  chartInstance->c14_is_c14_FSAC2021_826 = c14_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c14_u, 16)), "is_c14_FSAC2021_826");
  chartInstance->c14_is_Goto = c14_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c14_u, 17)), "is_Goto");
  chartInstance->c14_is_Motor_Stanby = c14_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c14_u, 18)), "is_Motor_Stanby");
  chartInstance->c14_is_Motor_Move = c14_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c14_u, 19)), "is_Motor_Move");
  chartInstance->c14_is_Motor_Enable = c14_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c14_u, 20)), "is_Motor_Enable");
  chartInstance->c14_is_Move = c14_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c14_u, 21)), "is_Move");
  chartInstance->c14_temporalCounter_i1 = c14_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c14_u, 22)), "temporalCounter_i1");
  chartInstance->c14_previousTicks = c14_j_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c14_u, 23)), "previousTicks");
  sf_mex_assign(&chartInstance->c14_setSimStateSideEffectsInfo,
                c14_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c14_u, 24)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c14_u);
  chartInstance->c14_doSetSimStateSideEffects = 1U;
  c14_update_debugger_state_c14_FSAC2021_826(chartInstance);
  sf_mex_destroy(&c14_st);
}

static void c14_set_sim_state_side_effects_c14_FSAC2021_826
  (SFc14_FSAC2021_826InstanceStruct *chartInstance)
{
  if (chartInstance->c14_doSetSimStateSideEffects != 0) {
    if (chartInstance->c14_is_c14_FSAC2021_826 == c14_IN_Init) {
      chartInstance->c14_tp_Init = 1U;
    } else {
      chartInstance->c14_tp_Init = 0U;
    }

    if (chartInstance->c14_is_c14_FSAC2021_826 == c14_IN_Move) {
      chartInstance->c14_tp_Move = 1U;
    } else {
      chartInstance->c14_tp_Move = 0U;
    }

    if (chartInstance->c14_is_Move == c14_IN_Goto) {
      chartInstance->c14_tp_Goto = 1U;
    } else {
      chartInstance->c14_tp_Goto = 0U;
    }

    if (chartInstance->c14_is_Goto == c14_IN_Origin_Aciton_Move) {
      chartInstance->c14_tp_Origin_Aciton_Move = 1U;
    } else {
      chartInstance->c14_tp_Origin_Aciton_Move = 0U;
    }

    if (chartInstance->c14_is_Goto == c14_IN_Origin_Pos_Set) {
      chartInstance->c14_tp_Origin_Pos_Set = 1U;
    } else {
      chartInstance->c14_tp_Origin_Pos_Set = 0U;
    }

    if (chartInstance->c14_is_Move == c14_IN_Motor_Enable) {
      chartInstance->c14_tp_Motor_Enable = 1U;
    } else {
      chartInstance->c14_tp_Motor_Enable = 0U;
    }

    if (chartInstance->c14_is_Motor_Enable == c14_IN_First) {
      chartInstance->c14_tp_First = 1U;
    } else {
      chartInstance->c14_tp_First = 0U;
    }

    if (chartInstance->c14_is_Motor_Enable == c14_IN_Second) {
      chartInstance->c14_tp_Second = 1U;
    } else {
      chartInstance->c14_tp_Second = 0U;
    }

    if (chartInstance->c14_is_Move == c14_IN_Motor_Move) {
      chartInstance->c14_tp_Motor_Move = 1U;
    } else {
      chartInstance->c14_tp_Motor_Move = 0U;
    }

    if (chartInstance->c14_is_Motor_Move == c14_IN_Aciton_Move) {
      chartInstance->c14_tp_Aciton_Move = 1U;
    } else {
      chartInstance->c14_tp_Aciton_Move = 0U;
    }

    if (chartInstance->c14_is_Motor_Move == c14_IN_Move_Position_Set) {
      chartInstance->c14_tp_Move_Position_Set = 1U;
    } else {
      chartInstance->c14_tp_Move_Position_Set = 0U;
    }

    if (chartInstance->c14_is_Move == c14_IN_Motor_Stanby) {
      chartInstance->c14_tp_Motor_Stanby = 1U;
    } else {
      chartInstance->c14_tp_Motor_Stanby = 0U;
    }

    if (chartInstance->c14_is_Motor_Stanby == c14_IN_Encoder1) {
      chartInstance->c14_tp_Encoder1 = 1U;
    } else {
      chartInstance->c14_tp_Encoder1 = 0U;
    }

    if (chartInstance->c14_is_Move == c14_IN_Wait) {
      chartInstance->c14_tp_Wait = 1U;
      if (sf_mex_sub(chartInstance->c14_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 15) == 0.0) {
        chartInstance->c14_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c14_tp_Wait = 0U;
    }

    if (chartInstance->c14_is_c14_FSAC2021_826 == c14_IN_Pre_Operation_Mode) {
      chartInstance->c14_tp_Pre_Operation_Mode = 1U;
    } else {
      chartInstance->c14_tp_Pre_Operation_Mode = 0U;
    }

    chartInstance->c14_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c14_FSAC2021_826(SFc14_FSAC2021_826InstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c14_setSimStateSideEffectsInfo);
}

static void sf_gateway_c14_FSAC2021_826(SFc14_FSAC2021_826InstanceStruct
  *chartInstance)
{
  int32_T c14_i3;
  boolean_T c14_out;
  uint8_T *c14_NMT_nodeorder;
  uint8_T *c14_NMT_nodectrl;
  uint8_T *c14_Enable_Operation_Ctrl;
  uint8_T *c14_Quick_Stop_Ctrl;
  uint8_T *c14_Enable_Voltage_Ctrl;
  uint8_T *c14_Halt_Ctrl;
  uint8_T *c14_Switch_On_Ctrl;
  uint8_T *c14_Abs_or_Rel_Ctrl;
  uint8_T *c14_New_Set_Point_Ctrl;
  real32_T *c14_Position_set;
  real_T *c14_Original_Flag;
  real32_T *c14_Origin_Back_Angle;
  int8_T *c14_Steer_Go_Angle;
  uint8_T *c14_ASSI_State;
  uint8_T *c14_Str_Status;
  real_T *c14_Fault_Resrt;
  real_T *c14_flag;
  real_T *c14_enflag;
  uint8_T (*c14_Encoder_Msg_Data)[6];
  c14_enflag = (real_T *)ssGetOutputPortSignal(chartInstance->S, 15);
  c14_flag = (real_T *)ssGetOutputPortSignal(chartInstance->S, 14);
  c14_Fault_Resrt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
  c14_Str_Status = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c14_ASSI_State = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c14_Steer_Go_Angle = (int8_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c14_Origin_Back_Angle = (real32_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c14_Original_Flag = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c14_Encoder_Msg_Data = (uint8_T (*)[6])ssGetOutputPortSignal(chartInstance->S,
    11);
  c14_Position_set = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c14_New_Set_Point_Ctrl = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c14_Abs_or_Rel_Ctrl = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c14_Switch_On_Ctrl = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c14_Halt_Ctrl = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c14_Enable_Voltage_Ctrl = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c14_Quick_Stop_Ctrl = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c14_Enable_Operation_Ctrl = (uint8_T *)ssGetOutputPortSignal(chartInstance->S,
    3);
  c14_NMT_nodectrl = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c14_NMT_nodeorder = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c14_set_sim_state_side_effects_c14_FSAC2021_826(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c14_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ /
    0.05 + 0.5);
  chartInstance->c14_elapsedTicks = chartInstance->c14_presentTicks -
    chartInstance->c14_previousTicks;
  chartInstance->c14_previousTicks = chartInstance->c14_presentTicks;
  if ((uint32_T)chartInstance->c14_temporalCounter_i1 +
      chartInstance->c14_elapsedTicks <= 31U) {
    chartInstance->c14_temporalCounter_i1 = (uint8_T)((uint32_T)
      chartInstance->c14_temporalCounter_i1 + chartInstance->c14_elapsedTicks);
  } else {
    chartInstance->c14_temporalCounter_i1 = 31U;
  }

  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 12U, chartInstance->c14_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*c14_NMT_nodeorder, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)*c14_NMT_nodectrl, 1U);
  _SFD_DATA_RANGE_CHECK((real_T)*c14_Enable_Operation_Ctrl, 2U);
  _SFD_DATA_RANGE_CHECK((real_T)*c14_Quick_Stop_Ctrl, 3U);
  _SFD_DATA_RANGE_CHECK((real_T)*c14_Enable_Voltage_Ctrl, 4U);
  _SFD_DATA_RANGE_CHECK((real_T)*c14_Halt_Ctrl, 5U);
  _SFD_DATA_RANGE_CHECK((real_T)*c14_Switch_On_Ctrl, 6U);
  _SFD_DATA_RANGE_CHECK((real_T)*c14_Abs_or_Rel_Ctrl, 7U);
  _SFD_DATA_RANGE_CHECK((real_T)*c14_New_Set_Point_Ctrl, 8U);
  _SFD_DATA_RANGE_CHECK((real_T)*c14_Position_set, 9U);
  for (c14_i3 = 0; c14_i3 < 6; c14_i3++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c14_Encoder_Msg_Data)[c14_i3], 10U);
  }

  _SFD_DATA_RANGE_CHECK(*c14_Original_Flag, 11U);
  _SFD_DATA_RANGE_CHECK((real_T)*c14_Origin_Back_Angle, 12U);
  _SFD_DATA_RANGE_CHECK((real_T)*c14_Steer_Go_Angle, 13U);
  _SFD_DATA_RANGE_CHECK((real_T)*c14_ASSI_State, 14U);
  _SFD_DATA_RANGE_CHECK((real_T)*c14_Str_Status, 15U);
  _SFD_DATA_RANGE_CHECK(*c14_Fault_Resrt, 16U);
  _SFD_DATA_RANGE_CHECK(*c14_flag, 17U);
  _SFD_DATA_RANGE_CHECK(*c14_enflag, 18U);
  chartInstance->c14_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 12U, chartInstance->c14_sfEvent);
  if (chartInstance->c14_is_active_c14_FSAC2021_826 == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 12U, chartInstance->c14_sfEvent);
    chartInstance->c14_is_active_c14_FSAC2021_826 = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c14_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c14_sfEvent);
    chartInstance->c14_is_c14_FSAC2021_826 = c14_IN_Init;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c14_sfEvent);
    chartInstance->c14_tp_Init = 1U;
  } else {
    switch (chartInstance->c14_is_c14_FSAC2021_826) {
     case c14_IN_Init:
      CV_CHART_EVAL(12, 0, 1);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c14_sfEvent);
      chartInstance->c14_tp_Init = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c14_sfEvent);
      chartInstance->c14_is_c14_FSAC2021_826 = c14_IN_Pre_Operation_Mode;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c14_sfEvent);
      chartInstance->c14_tp_Pre_Operation_Mode = 1U;
      *c14_NMT_nodeorder = 1U;
      _SFD_DATA_RANGE_CHECK((real_T)*c14_NMT_nodeorder, 0U);
      *c14_NMT_nodectrl = 0U;
      _SFD_DATA_RANGE_CHECK((real_T)*c14_NMT_nodectrl, 1U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c14_sfEvent);
      break;

     case c14_IN_Move:
      CV_CHART_EVAL(12, 0, 2);
      c14_Move(chartInstance);
      break;

     case c14_IN_Pre_Operation_Mode:
      CV_CHART_EVAL(12, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c14_sfEvent);
      c14_out = (CV_TRANSITION_EVAL(1U, (int32_T)_SFD_CCP_CALL(1U, 0,
        *c14_Str_Status != 0U, chartInstance->c14_sfEvent)) != 0);
      if (c14_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c14_sfEvent);
        chartInstance->c14_tp_Pre_Operation_Mode = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c14_sfEvent);
        chartInstance->c14_is_c14_FSAC2021_826 = c14_IN_Move;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c14_sfEvent);
        chartInstance->c14_tp_Move = 1U;
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c14_sfEvent);
        chartInstance->c14_is_Move = c14_IN_Motor_Enable;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c14_sfEvent);
        chartInstance->c14_tp_Motor_Enable = 1U;
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c14_sfEvent);
        chartInstance->c14_is_Motor_Enable = c14_IN_First;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c14_sfEvent);
        chartInstance->c14_tp_First = 1U;
        *c14_Switch_On_Ctrl = 0U;
        _SFD_DATA_RANGE_CHECK((real_T)*c14_Switch_On_Ctrl, 6U);
        *c14_Enable_Voltage_Ctrl = 1U;
        _SFD_DATA_RANGE_CHECK((real_T)*c14_Enable_Voltage_Ctrl, 4U);
        *c14_Quick_Stop_Ctrl = 1U;
        _SFD_DATA_RANGE_CHECK((real_T)*c14_Quick_Stop_Ctrl, 3U);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 14U,
                     chartInstance->c14_sfEvent);
        sf_call_output_fcn_call(chartInstance->S, 0, "TmtNMTCAN", 0);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c14_sfEvent);
      break;

     default:
      CV_CHART_EVAL(12, 0, 0);
      chartInstance->c14_is_c14_FSAC2021_826 = c14_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c14_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c14_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_FSAC2021_826MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc14_FSAC2021_826(SFc14_FSAC2021_826InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c14_Move(SFc14_FSAC2021_826InstanceStruct *chartInstance)
{
  boolean_T c14_out;
  boolean_T c14_b_out;
  int32_T c14_i4;
  int32_T c14_i5;
  int32_T c14_i6;
  int32_T c14_i7;
  int32_T c14_i8;
  int32_T c14_i9;
  int32_T c14_i10;
  real_T *c14_Fault_Resrt;
  uint8_T *c14_Enable_Operation_Ctrl;
  real32_T *c14_Origin_Back_Angle;
  real32_T *c14_Position_set;
  uint8_T *c14_New_Set_Point_Ctrl;
  uint8_T *c14_Abs_or_Rel_Ctrl;
  uint8_T *c14_Switch_On_Ctrl;
  real_T *c14_enflag;
  int8_T *c14_Steer_Go_Angle;
  real_T *c14_Original_Flag;
  uint8_T *c14_ASSI_State;
  uint8_T (*c14_Encoder_Msg_Data)[6];
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  c14_enflag = (real_T *)ssGetOutputPortSignal(chartInstance->S, 15);
  c14_Fault_Resrt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
  c14_ASSI_State = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c14_Steer_Go_Angle = (int8_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c14_Origin_Back_Angle = (real32_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c14_Original_Flag = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c14_Encoder_Msg_Data = (uint8_T (*)[6])ssGetOutputPortSignal(chartInstance->S,
    11);
  c14_Position_set = (real32_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c14_New_Set_Point_Ctrl = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c14_Abs_or_Rel_Ctrl = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c14_Switch_On_Ctrl = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c14_Enable_Operation_Ctrl = (uint8_T *)ssGetOutputPortSignal(chartInstance->S,
    3);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c14_sfEvent);
  switch (chartInstance->c14_is_Move) {
   case c14_IN_Goto:
    CV_STATE_EVAL(1, 0, 1);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c14_sfEvent);
    sf_call_output_fcn_call(chartInstance->S, 1, "TmtRPDO1CAN", 0);
    *c14_Fault_Resrt = 0.0;
    _SFD_DATA_RANGE_CHECK(*c14_Fault_Resrt, 16U);
    *c14_Enable_Operation_Ctrl = 1U;
    _SFD_DATA_RANGE_CHECK((real_T)*c14_Enable_Operation_Ctrl, 2U);
    guard2 = false;
    switch (chartInstance->c14_is_Goto) {
     case c14_IN_Origin_Aciton_Move:
      CV_STATE_EVAL(2, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 15U,
                   chartInstance->c14_sfEvent);
      c14_out = (CV_TRANSITION_EVAL(15U, (int32_T)_SFD_CCP_CALL(15U, 0,
        muSingleScalarAbs(*c14_Origin_Back_Angle) <= 2.0F != 0U,
        chartInstance->c14_sfEvent)) != 0);
      if (c14_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c14_sfEvent);
        chartInstance->c14_tp_Origin_Aciton_Move = 0U;
        chartInstance->c14_is_Goto = c14_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c14_sfEvent);
        chartInstance->c14_tp_Goto = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c14_sfEvent);
        chartInstance->c14_is_Move = c14_IN_Wait;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c14_sfEvent);
        chartInstance->c14_temporalCounter_i1 = 0U;
        chartInstance->c14_tp_Wait = 1U;
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c14_sfEvent);
        chartInstance->c14_tp_Origin_Aciton_Move = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c14_sfEvent);
        chartInstance->c14_is_Goto = c14_IN_Origin_Pos_Set;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c14_sfEvent);
        chartInstance->c14_tp_Origin_Pos_Set = 1U;
        *c14_Position_set = *c14_Origin_Back_Angle;
        _SFD_DATA_RANGE_CHECK((real_T)*c14_Position_set, 9U);
        *c14_New_Set_Point_Ctrl = 0U;
        _SFD_DATA_RANGE_CHECK((real_T)*c14_New_Set_Point_Ctrl, 8U);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c14_sfEvent);
      if (chartInstance->c14_is_Move != c14_IN_Goto) {
      } else {
        guard2 = true;
      }
      break;

     case c14_IN_Origin_Pos_Set:
      CV_STATE_EVAL(2, 0, 2);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c14_sfEvent);
      chartInstance->c14_tp_Origin_Pos_Set = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c14_sfEvent);
      chartInstance->c14_is_Goto = c14_IN_Origin_Aciton_Move;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c14_sfEvent);
      chartInstance->c14_tp_Origin_Aciton_Move = 1U;
      *c14_New_Set_Point_Ctrl = 1U;
      _SFD_DATA_RANGE_CHECK((real_T)*c14_New_Set_Point_Ctrl, 8U);
      *c14_Abs_or_Rel_Ctrl = 0U;
      _SFD_DATA_RANGE_CHECK((real_T)*c14_Abs_or_Rel_Ctrl, 7U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c14_sfEvent);
      guard2 = true;
      break;

     default:
      CV_STATE_EVAL(2, 0, 0);
      chartInstance->c14_is_Goto = c14_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c14_sfEvent);
      guard2 = true;
      break;
    }

    if (guard2 == true) {
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c14_sfEvent);
    }
    break;

   case c14_IN_Motor_Enable:
    CV_STATE_EVAL(1, 0, 2);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c14_sfEvent);
    sf_call_output_fcn_call(chartInstance->S, 1, "TmtRPDO1CAN", 0);
    guard1 = false;
    switch (chartInstance->c14_is_Motor_Enable) {
     case c14_IN_First:
      CV_STATE_EVAL(5, 0, 1);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c14_sfEvent);
      chartInstance->c14_tp_First = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c14_sfEvent);
      chartInstance->c14_is_Motor_Enable = c14_IN_Second;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c14_sfEvent);
      chartInstance->c14_tp_Second = 1U;
      *c14_Switch_On_Ctrl = 1U;
      _SFD_DATA_RANGE_CHECK((real_T)*c14_Switch_On_Ctrl, 6U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c14_sfEvent);
      guard1 = true;
      break;

     case c14_IN_Second:
      CV_STATE_EVAL(5, 0, 2);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c14_sfEvent);
      chartInstance->c14_tp_Second = 0U;
      chartInstance->c14_is_Motor_Enable = c14_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c14_sfEvent);
      chartInstance->c14_tp_Motor_Enable = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c14_sfEvent);
      chartInstance->c14_is_Move = c14_IN_Goto;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c14_sfEvent);
      chartInstance->c14_tp_Goto = 1U;
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c14_sfEvent);
      chartInstance->c14_is_Goto = c14_IN_Origin_Pos_Set;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c14_sfEvent);
      chartInstance->c14_tp_Origin_Pos_Set = 1U;
      *c14_Position_set = *c14_Origin_Back_Angle;
      _SFD_DATA_RANGE_CHECK((real_T)*c14_Position_set, 9U);
      *c14_New_Set_Point_Ctrl = 0U;
      _SFD_DATA_RANGE_CHECK((real_T)*c14_New_Set_Point_Ctrl, 8U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c14_sfEvent);
      if (chartInstance->c14_is_Move != c14_IN_Motor_Enable) {
      } else {
        guard1 = true;
      }
      break;

     default:
      CV_STATE_EVAL(5, 0, 0);
      chartInstance->c14_is_Motor_Enable = c14_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c14_sfEvent);
      guard1 = true;
      break;
    }

    if (guard1 == true) {
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c14_sfEvent);
    }
    break;

   case c14_IN_Motor_Move:
    CV_STATE_EVAL(1, 0, 3);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c14_sfEvent);
    sf_call_output_fcn_call(chartInstance->S, 1, "TmtRPDO1CAN", 0);
    *c14_enflag = 1.0;
    _SFD_DATA_RANGE_CHECK(*c14_enflag, 18U);
    switch (chartInstance->c14_is_Motor_Move) {
     case c14_IN_Aciton_Move:
      CV_STATE_EVAL(8, 0, 1);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c14_sfEvent);
      chartInstance->c14_tp_Aciton_Move = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c14_sfEvent);
      chartInstance->c14_is_Motor_Move = c14_IN_Move_Position_Set;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c14_sfEvent);
      chartInstance->c14_tp_Move_Position_Set = 1U;
      *c14_Enable_Operation_Ctrl = 1U;
      _SFD_DATA_RANGE_CHECK((real_T)*c14_Enable_Operation_Ctrl, 2U);
      *c14_Position_set = (real32_T)*c14_Steer_Go_Angle;
      _SFD_DATA_RANGE_CHECK((real_T)*c14_Position_set, 9U);
      *c14_New_Set_Point_Ctrl = 0U;
      _SFD_DATA_RANGE_CHECK((real_T)*c14_New_Set_Point_Ctrl, 8U);
      *c14_Abs_or_Rel_Ctrl = 0U;
      _SFD_DATA_RANGE_CHECK((real_T)*c14_Abs_or_Rel_Ctrl, 7U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c14_sfEvent);
      break;

     case c14_IN_Move_Position_Set:
      CV_STATE_EVAL(8, 0, 2);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c14_sfEvent);
      chartInstance->c14_tp_Move_Position_Set = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c14_sfEvent);
      chartInstance->c14_is_Motor_Move = c14_IN_Aciton_Move;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c14_sfEvent);
      chartInstance->c14_tp_Aciton_Move = 1U;
      *c14_New_Set_Point_Ctrl = 1U;
      _SFD_DATA_RANGE_CHECK((real_T)*c14_New_Set_Point_Ctrl, 8U);
      *c14_Abs_or_Rel_Ctrl = 1U;
      _SFD_DATA_RANGE_CHECK((real_T)*c14_Abs_or_Rel_Ctrl, 7U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c14_sfEvent);
      break;

     default:
      CV_STATE_EVAL(8, 0, 0);
      chartInstance->c14_is_Motor_Move = c14_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c14_sfEvent);
      break;
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c14_sfEvent);
    break;

   case c14_IN_Motor_Stanby:
    CV_STATE_EVAL(1, 0, 4);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 11U,
                 chartInstance->c14_sfEvent);
    sf_call_output_fcn_call(chartInstance->S, 2, "TmtSDOCAN", 0);
    *c14_Original_Flag = 1.0;
    _SFD_DATA_RANGE_CHECK(*c14_Original_Flag, 11U);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                 chartInstance->c14_sfEvent);
    c14_b_out = (CV_TRANSITION_EVAL(3U, (int32_T)_SFD_CCP_CALL(3U, 0,
      *c14_ASSI_State == 3 != 0U, chartInstance->c14_sfEvent)) != 0);
    if (c14_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c14_sfEvent);
      chartInstance->c14_tp_Encoder1 = 0U;
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 12U,
                   chartInstance->c14_sfEvent);
      (*c14_Encoder_Msg_Data)[4] = (uint8_T)0x00;
      for (c14_i4 = 0; c14_i4 < 6; c14_i4++) {
        _SFD_DATA_RANGE_CHECK((real_T)(*c14_Encoder_Msg_Data)[c14_i4], 10U);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c14_sfEvent);
      chartInstance->c14_is_Motor_Stanby = c14_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c14_sfEvent);
      chartInstance->c14_tp_Motor_Stanby = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c14_sfEvent);
      chartInstance->c14_is_Move = c14_IN_Motor_Move;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c14_sfEvent);
      chartInstance->c14_tp_Motor_Move = 1U;
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c14_sfEvent);
      chartInstance->c14_is_Motor_Move = c14_IN_Move_Position_Set;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c14_sfEvent);
      chartInstance->c14_tp_Move_Position_Set = 1U;
      *c14_Enable_Operation_Ctrl = 1U;
      _SFD_DATA_RANGE_CHECK((real_T)*c14_Enable_Operation_Ctrl, 2U);
      *c14_Position_set = (real32_T)*c14_Steer_Go_Angle;
      _SFD_DATA_RANGE_CHECK((real_T)*c14_Position_set, 9U);
      *c14_New_Set_Point_Ctrl = 0U;
      _SFD_DATA_RANGE_CHECK((real_T)*c14_New_Set_Point_Ctrl, 8U);
      *c14_Abs_or_Rel_Ctrl = 0U;
      _SFD_DATA_RANGE_CHECK((real_T)*c14_Abs_or_Rel_Ctrl, 7U);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 12U,
                   chartInstance->c14_sfEvent);
      (*c14_Encoder_Msg_Data)[0] = (uint8_T)0x2B;
      for (c14_i5 = 0; c14_i5 < 6; c14_i5++) {
        _SFD_DATA_RANGE_CHECK((real_T)(*c14_Encoder_Msg_Data)[c14_i5], 10U);
      }

      (*c14_Encoder_Msg_Data)[1] = (uint8_T)0x04;
      for (c14_i6 = 0; c14_i6 < 6; c14_i6++) {
        _SFD_DATA_RANGE_CHECK((real_T)(*c14_Encoder_Msg_Data)[c14_i6], 10U);
      }

      (*c14_Encoder_Msg_Data)[2] = (uint8_T)0x20;
      for (c14_i7 = 0; c14_i7 < 6; c14_i7++) {
        _SFD_DATA_RANGE_CHECK((real_T)(*c14_Encoder_Msg_Data)[c14_i7], 10U);
      }

      (*c14_Encoder_Msg_Data)[3] = (uint8_T)0x00;
      for (c14_i8 = 0; c14_i8 < 6; c14_i8++) {
        _SFD_DATA_RANGE_CHECK((real_T)(*c14_Encoder_Msg_Data)[c14_i8], 10U);
      }

      (*c14_Encoder_Msg_Data)[4] = (uint8_T)0x01;
      for (c14_i9 = 0; c14_i9 < 6; c14_i9++) {
        _SFD_DATA_RANGE_CHECK((real_T)(*c14_Encoder_Msg_Data)[c14_i9], 10U);
      }

      (*c14_Encoder_Msg_Data)[5] = (uint8_T)0x00;
      for (c14_i10 = 0; c14_i10 < 6; c14_i10++) {
        _SFD_DATA_RANGE_CHECK((real_T)(*c14_Encoder_Msg_Data)[c14_i10], 10U);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c14_sfEvent);
    if (chartInstance->c14_is_Move != c14_IN_Motor_Stanby) {
    } else {
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c14_sfEvent);
    }
    break;

   case c14_IN_Wait:
    CV_STATE_EVAL(1, 0, 5);
    c14_Wait(chartInstance);
    break;

   default:
    CV_STATE_EVAL(1, 0, 0);
    chartInstance->c14_is_Move = c14_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c14_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c14_sfEvent);
}

static void c14_Wait(SFc14_FSAC2021_826InstanceStruct *chartInstance)
{
  boolean_T c14_out;
  boolean_T c14_b_out;
  real32_T *c14_Origin_Back_Angle;
  uint8_T *c14_New_Set_Point_Ctrl;
  uint8_T *c14_Abs_or_Rel_Ctrl;
  c14_Origin_Back_Angle = (real32_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c14_New_Set_Point_Ctrl = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c14_Abs_or_Rel_Ctrl = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 16U, chartInstance->c14_sfEvent);
  c14_out = (CV_TRANSITION_EVAL(16U, (int32_T)_SFD_CCP_CALL(16U, 0,
    muSingleScalarAbs(*c14_Origin_Back_Angle) > 2.0F != 0U,
    chartInstance->c14_sfEvent)) != 0);
  if (c14_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c14_sfEvent);
    chartInstance->c14_tp_Wait = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c14_sfEvent);
    chartInstance->c14_is_Move = c14_IN_Goto;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c14_sfEvent);
    chartInstance->c14_tp_Goto = 1U;
    chartInstance->c14_is_Goto = c14_IN_Origin_Aciton_Move;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c14_sfEvent);
    chartInstance->c14_tp_Origin_Aciton_Move = 1U;
    *c14_New_Set_Point_Ctrl = 1U;
    _SFD_DATA_RANGE_CHECK((real_T)*c14_New_Set_Point_Ctrl, 8U);
    *c14_Abs_or_Rel_Ctrl = 0U;
    _SFD_DATA_RANGE_CHECK((real_T)*c14_Abs_or_Rel_Ctrl, 7U);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 17U,
                 chartInstance->c14_sfEvent);
    c14_b_out = (CV_TRANSITION_EVAL(17U, (int32_T)_SFD_CCP_CALL(17U, 0,
      chartInstance->c14_temporalCounter_i1 >= 20U != 0U,
      chartInstance->c14_sfEvent)) != 0);
    if (c14_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c14_sfEvent);
      chartInstance->c14_tp_Wait = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c14_sfEvent);
      chartInstance->c14_is_Move = c14_IN_Motor_Stanby;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c14_sfEvent);
      chartInstance->c14_tp_Motor_Stanby = 1U;
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c14_sfEvent);
      chartInstance->c14_is_Motor_Stanby = c14_IN_Encoder1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c14_sfEvent);
      chartInstance->c14_tp_Encoder1 = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 13U,
                   chartInstance->c14_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c14_sfEvent);
}

static void init_script_number_translation(uint32_T c14_machineNumber, uint32_T
  c14_chartNumber, uint32_T c14_instanceNumber)
{
  (void)c14_machineNumber;
  (void)c14_chartNumber;
  (void)c14_instanceNumber;
}

const mxArray *sf_c14_FSAC2021_826_get_eml_resolved_functions_info(void)
{
  const mxArray *c14_nameCaptureInfo = NULL;
  c14_nameCaptureInfo = NULL;
  sf_mex_assign(&c14_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c14_nameCaptureInfo;
}

static const mxArray *c14_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_u;
  const mxArray *c14_y = NULL;
  SFc14_FSAC2021_826InstanceStruct *chartInstance;
  chartInstance = (SFc14_FSAC2021_826InstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_u = *(int32_T *)c14_inData;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, false);
  return c14_mxArrayOutData;
}

static int32_T c14_emlrt_marshallIn(SFc14_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  int32_T c14_y;
  int32_T c14_i11;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_i11, 1, 6, 0U, 0, 0U, 0);
  c14_y = c14_i11;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_b_sfEvent;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  int32_T c14_y;
  SFc14_FSAC2021_826InstanceStruct *chartInstance;
  chartInstance = (SFc14_FSAC2021_826InstanceStruct *)chartInstanceVoid;
  c14_b_sfEvent = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_b_sfEvent),
    &c14_thisId);
  sf_mex_destroy(&c14_b_sfEvent);
  *(int32_T *)c14_outData = c14_y;
  sf_mex_destroy(&c14_mxArrayInData);
}

static const mxArray *c14_b_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  uint8_T c14_u;
  const mxArray *c14_y = NULL;
  SFc14_FSAC2021_826InstanceStruct *chartInstance;
  chartInstance = (SFc14_FSAC2021_826InstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_u = *(uint8_T *)c14_inData;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, false);
  return c14_mxArrayOutData;
}

static uint8_T c14_b_emlrt_marshallIn(SFc14_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c14_b_tp_Pre_Operation_Mode, const char_T
  *c14_identifier)
{
  uint8_T c14_y;
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c14_b_tp_Pre_Operation_Mode), &c14_thisId);
  sf_mex_destroy(&c14_b_tp_Pre_Operation_Mode);
  return c14_y;
}

static uint8_T c14_c_emlrt_marshallIn(SFc14_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  uint8_T c14_y;
  uint8_T c14_u0;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_u0, 1, 3, 0U, 0, 0U, 0);
  c14_y = c14_u0;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_b_tp_Pre_Operation_Mode;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  uint8_T c14_y;
  SFc14_FSAC2021_826InstanceStruct *chartInstance;
  chartInstance = (SFc14_FSAC2021_826InstanceStruct *)chartInstanceVoid;
  c14_b_tp_Pre_Operation_Mode = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c14_b_tp_Pre_Operation_Mode), &c14_thisId);
  sf_mex_destroy(&c14_b_tp_Pre_Operation_Mode);
  *(uint8_T *)c14_outData = c14_y;
  sf_mex_destroy(&c14_mxArrayInData);
}

static const mxArray *c14_c_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  real32_T c14_u;
  const mxArray *c14_y = NULL;
  SFc14_FSAC2021_826InstanceStruct *chartInstance;
  chartInstance = (SFc14_FSAC2021_826InstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_u = *(real32_T *)c14_inData;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 1, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, false);
  return c14_mxArrayOutData;
}

static real32_T c14_d_emlrt_marshallIn(SFc14_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c14_Position_set, const char_T *c14_identifier)
{
  real32_T c14_y;
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_Position_set),
    &c14_thisId);
  sf_mex_destroy(&c14_Position_set);
  return c14_y;
}

static real32_T c14_e_emlrt_marshallIn(SFc14_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  real32_T c14_y;
  real32_T c14_f0;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_f0, 1, 1, 0U, 0, 0U, 0);
  c14_y = c14_f0;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_Position_set;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  real32_T c14_y;
  SFc14_FSAC2021_826InstanceStruct *chartInstance;
  chartInstance = (SFc14_FSAC2021_826InstanceStruct *)chartInstanceVoid;
  c14_Position_set = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_Position_set),
    &c14_thisId);
  sf_mex_destroy(&c14_Position_set);
  *(real32_T *)c14_outData = c14_y;
  sf_mex_destroy(&c14_mxArrayInData);
}

static const mxArray *c14_d_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_i12;
  uint8_T c14_b_inData[6];
  int32_T c14_i13;
  uint8_T c14_u[6];
  const mxArray *c14_y = NULL;
  SFc14_FSAC2021_826InstanceStruct *chartInstance;
  chartInstance = (SFc14_FSAC2021_826InstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  for (c14_i12 = 0; c14_i12 < 6; c14_i12++) {
    c14_b_inData[c14_i12] = (*(uint8_T (*)[6])c14_inData)[c14_i12];
  }

  for (c14_i13 = 0; c14_i13 < 6; c14_i13++) {
    c14_u[c14_i13] = c14_b_inData[c14_i13];
  }

  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", c14_u, 3, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, false);
  return c14_mxArrayOutData;
}

static void c14_f_emlrt_marshallIn(SFc14_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c14_Encoder_Msg_Data, const char_T
  *c14_identifier, uint8_T c14_y[6])
{
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_Encoder_Msg_Data),
    &c14_thisId, c14_y);
  sf_mex_destroy(&c14_Encoder_Msg_Data);
}

static void c14_g_emlrt_marshallIn(SFc14_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  uint8_T c14_y[6])
{
  uint8_T c14_uv1[6];
  int32_T c14_i14;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), c14_uv1, 1, 3, 0U, 1, 0U, 1, 6);
  for (c14_i14 = 0; c14_i14 < 6; c14_i14++) {
    c14_y[c14_i14] = c14_uv1[c14_i14];
  }

  sf_mex_destroy(&c14_u);
}

static void c14_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_Encoder_Msg_Data;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  uint8_T c14_y[6];
  int32_T c14_i15;
  SFc14_FSAC2021_826InstanceStruct *chartInstance;
  chartInstance = (SFc14_FSAC2021_826InstanceStruct *)chartInstanceVoid;
  c14_Encoder_Msg_Data = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_Encoder_Msg_Data),
    &c14_thisId, c14_y);
  sf_mex_destroy(&c14_Encoder_Msg_Data);
  for (c14_i15 = 0; c14_i15 < 6; c14_i15++) {
    (*(uint8_T (*)[6])c14_outData)[c14_i15] = c14_y[c14_i15];
  }

  sf_mex_destroy(&c14_mxArrayInData);
}

static const mxArray *c14_e_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  real_T c14_u;
  const mxArray *c14_y = NULL;
  SFc14_FSAC2021_826InstanceStruct *chartInstance;
  chartInstance = (SFc14_FSAC2021_826InstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_u = *(real_T *)c14_inData;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, false);
  return c14_mxArrayOutData;
}

static real_T c14_h_emlrt_marshallIn(SFc14_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c14_Original_Flag, const char_T *c14_identifier)
{
  real_T c14_y;
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_Original_Flag),
    &c14_thisId);
  sf_mex_destroy(&c14_Original_Flag);
  return c14_y;
}

static real_T c14_i_emlrt_marshallIn(SFc14_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  real_T c14_y;
  real_T c14_d0;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_d0, 1, 0, 0U, 0, 0U, 0);
  c14_y = c14_d0;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_Original_Flag;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  real_T c14_y;
  SFc14_FSAC2021_826InstanceStruct *chartInstance;
  chartInstance = (SFc14_FSAC2021_826InstanceStruct *)chartInstanceVoid;
  c14_Original_Flag = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_Original_Flag),
    &c14_thisId);
  sf_mex_destroy(&c14_Original_Flag);
  *(real_T *)c14_outData = c14_y;
  sf_mex_destroy(&c14_mxArrayInData);
}

static const mxArray *c14_f_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int8_T c14_u;
  const mxArray *c14_y = NULL;
  SFc14_FSAC2021_826InstanceStruct *chartInstance;
  chartInstance = (SFc14_FSAC2021_826InstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_u = *(int8_T *)c14_inData;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, false);
  return c14_mxArrayOutData;
}

static uint32_T c14_j_emlrt_marshallIn(SFc14_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c14_b_previousTicks, const char_T
  *c14_identifier)
{
  uint32_T c14_y;
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_b_previousTicks),
    &c14_thisId);
  sf_mex_destroy(&c14_b_previousTicks);
  return c14_y;
}

static uint32_T c14_k_emlrt_marshallIn(SFc14_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  uint32_T c14_y;
  uint32_T c14_u1;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_u1, 1, 7, 0U, 0, 0U, 0);
  c14_y = c14_u1;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static const mxArray *c14_l_emlrt_marshallIn(SFc14_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c14_b_setSimStateSideEffectsInfo, const char_T *
  c14_identifier)
{
  const mxArray *c14_y = NULL;
  emlrtMsgIdentifier c14_thisId;
  c14_y = NULL;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  sf_mex_assign(&c14_y, c14_m_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c14_b_setSimStateSideEffectsInfo), &c14_thisId), false);
  sf_mex_destroy(&c14_b_setSimStateSideEffectsInfo);
  return c14_y;
}

static const mxArray *c14_m_emlrt_marshallIn(SFc14_FSAC2021_826InstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  const mxArray *c14_y = NULL;
  (void)chartInstance;
  (void)c14_parentId;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_duplicatearraysafe(&c14_u), false);
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void init_dsm_address_info(SFc14_FSAC2021_826InstanceStruct
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

void sf_c14_FSAC2021_826_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1327441989U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1831466380U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(702465016U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1284221625U);
}

mxArray *sf_c14_FSAC2021_826_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("YO1ENp4gJoE9OjnrnE86fH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(4));
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,15,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,14,"type",mxType);
    }

    mxSetField(mxData,14,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c14_FSAC2021_826_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c14_FSAC2021_826_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c14_FSAC2021_826(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[158],T\"Abs_or_Rel_Ctrl\",},{M[1],M[153],T\"Enable_Operation_Ctrl\",},{M[1],M[155],T\"Enable_Voltage_Ctrl\",},{M[1],M[162],T\"Encoder_Msg_Data\",},{M[1],M[176],T\"Fault_Resrt\",},{M[1],M[156],T\"Halt_Ctrl\",},{M[1],M[152],T\"NMT_nodectrl\",},{M[1],M[151],T\"NMT_nodeorder\",},{M[1],M[160],T\"New_Set_Point_Ctrl\",},{M[1],M[163],T\"Original_Flag\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[161],T\"Position_set\",},{M[1],M[154],T\"Quick_Stop_Ctrl\",},{M[1],M[157],T\"Switch_On_Ctrl\",},{M[1],M[242],T\"enflag\",},{M[1],M[182],T\"flag\",},{M[8],M[0],T\"is_active_c14_FSAC2021_826\",},{M[9],M[0],T\"is_c14_FSAC2021_826\",},{M[9],M[13],T\"is_Goto\",},{M[9],M[35],T\"is_Motor_Stanby\",},{M[9],M[39],T\"is_Motor_Move\",}}",
    "100 S1x4'type','srcId','name','auxInfo'{{M[9],M[65],T\"is_Motor_Enable\",},{M[9],M[233],T\"is_Move\",},{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"at\",M[238],M[1]}}},{M[13],M[0],T\"previousTicks\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 24, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c14_FSAC2021_826_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc14_FSAC2021_826InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc14_FSAC2021_826InstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _FSAC2021_826MachineNumber_,
           14,
           15,
           18,
           0,
           19,
           3,
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
            3,
            3,
            3);
          _SFD_SET_DATA_PROPS(0,2,0,1,"NMT_nodeorder");
          _SFD_SET_DATA_PROPS(1,2,0,1,"NMT_nodectrl");
          _SFD_SET_DATA_PROPS(2,2,0,1,"Enable_Operation_Ctrl");
          _SFD_SET_DATA_PROPS(3,2,0,1,"Quick_Stop_Ctrl");
          _SFD_SET_DATA_PROPS(4,2,0,1,"Enable_Voltage_Ctrl");
          _SFD_SET_DATA_PROPS(5,2,0,1,"Halt_Ctrl");
          _SFD_SET_DATA_PROPS(6,2,0,1,"Switch_On_Ctrl");
          _SFD_SET_DATA_PROPS(7,2,0,1,"Abs_or_Rel_Ctrl");
          _SFD_SET_DATA_PROPS(8,2,0,1,"New_Set_Point_Ctrl");
          _SFD_SET_DATA_PROPS(9,2,0,1,"Position_set");
          _SFD_SET_DATA_PROPS(10,2,0,1,"Encoder_Msg_Data");
          _SFD_SET_DATA_PROPS(11,2,0,1,"Original_Flag");
          _SFD_SET_DATA_PROPS(12,1,1,0,"Origin_Back_Angle");
          _SFD_SET_DATA_PROPS(13,1,1,0,"Steer_Go_Angle");
          _SFD_SET_DATA_PROPS(14,1,1,0,"ASSI_State");
          _SFD_SET_DATA_PROPS(15,1,1,0,"Str_Status");
          _SFD_SET_DATA_PROPS(16,2,0,1,"Fault_Resrt");
          _SFD_SET_DATA_PROPS(17,2,0,1,"flag");
          _SFD_SET_DATA_PROPS(18,2,0,1,"enflag");
          _SFD_EVENT_SCOPE(0,2);
          _SFD_EVENT_SCOPE(1,2);
          _SFD_EVENT_SCOPE(2,2);
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(8,0,0);
          _SFD_STATE_INFO(9,0,0);
          _SFD_STATE_INFO(10,0,0);
          _SFD_STATE_INFO(11,0,0);
          _SFD_STATE_INFO(12,0,0);
          _SFD_STATE_INFO(13,0,0);
          _SFD_STATE_INFO(14,0,0);
          _SFD_CH_SUBSTATE_COUNT(3);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,14);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,5);
          _SFD_ST_SUBSTATE_INDEX(1,0,2);
          _SFD_ST_SUBSTATE_INDEX(1,1,5);
          _SFD_ST_SUBSTATE_INDEX(1,2,8);
          _SFD_ST_SUBSTATE_INDEX(1,3,11);
          _SFD_ST_SUBSTATE_INDEX(1,4,13);
          _SFD_ST_SUBSTATE_COUNT(2,2);
          _SFD_ST_SUBSTATE_INDEX(2,0,3);
          _SFD_ST_SUBSTATE_INDEX(2,1,4);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,2);
          _SFD_ST_SUBSTATE_INDEX(5,0,6);
          _SFD_ST_SUBSTATE_INDEX(5,1,7);
          _SFD_ST_SUBSTATE_COUNT(6,0);
          _SFD_ST_SUBSTATE_COUNT(7,0);
          _SFD_ST_SUBSTATE_COUNT(8,2);
          _SFD_ST_SUBSTATE_INDEX(8,0,9);
          _SFD_ST_SUBSTATE_INDEX(8,1,10);
          _SFD_ST_SUBSTATE_COUNT(9,0);
          _SFD_ST_SUBSTATE_COUNT(10,0);
          _SFD_ST_SUBSTATE_COUNT(11,1);
          _SFD_ST_SUBSTATE_INDEX(11,0,12);
          _SFD_ST_SUBSTATE_COUNT(12,0);
          _SFD_ST_SUBSTATE_COUNT(13,0);
          _SFD_ST_SUBSTATE_COUNT(14,0);
        }

        _SFD_CV_INIT_CHART(3,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,5,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,2,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(5,2,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(6,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(7,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(8,2,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(9,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(10,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(11,1,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(12,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(13,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(14,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 26 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(15,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 27 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(16,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(17,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 21 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(3,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 11 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(1,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_b_sf_marshallOut,(MexInFcnForType)
          c14_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_b_sf_marshallOut,(MexInFcnForType)
          c14_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_b_sf_marshallOut,(MexInFcnForType)
          c14_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_b_sf_marshallOut,(MexInFcnForType)
          c14_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_b_sf_marshallOut,(MexInFcnForType)
          c14_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_b_sf_marshallOut,(MexInFcnForType)
          c14_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_b_sf_marshallOut,(MexInFcnForType)
          c14_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_b_sf_marshallOut,(MexInFcnForType)
          c14_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_b_sf_marshallOut,(MexInFcnForType)
          c14_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_c_sf_marshallOut,(MexInFcnForType)
          c14_c_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_UINT8,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c14_d_sf_marshallOut,(MexInFcnForType)
            c14_d_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_e_sf_marshallOut,(MexInFcnForType)
          c14_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_INT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_f_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_e_sf_marshallOut,(MexInFcnForType)
          c14_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_e_sf_marshallOut,(MexInFcnForType)
          c14_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_e_sf_marshallOut,(MexInFcnForType)
          c14_e_sf_marshallIn);

        {
          uint8_T *c14_NMT_nodeorder;
          uint8_T *c14_NMT_nodectrl;
          uint8_T *c14_Enable_Operation_Ctrl;
          uint8_T *c14_Quick_Stop_Ctrl;
          uint8_T *c14_Enable_Voltage_Ctrl;
          uint8_T *c14_Halt_Ctrl;
          uint8_T *c14_Switch_On_Ctrl;
          uint8_T *c14_Abs_or_Rel_Ctrl;
          uint8_T *c14_New_Set_Point_Ctrl;
          real32_T *c14_Position_set;
          real_T *c14_Original_Flag;
          real32_T *c14_Origin_Back_Angle;
          int8_T *c14_Steer_Go_Angle;
          uint8_T *c14_ASSI_State;
          uint8_T *c14_Str_Status;
          real_T *c14_Fault_Resrt;
          real_T *c14_flag;
          real_T *c14_enflag;
          uint8_T (*c14_Encoder_Msg_Data)[6];
          c14_enflag = (real_T *)ssGetOutputPortSignal(chartInstance->S, 15);
          c14_flag = (real_T *)ssGetOutputPortSignal(chartInstance->S, 14);
          c14_Fault_Resrt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 13);
          c14_Str_Status = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c14_ASSI_State = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c14_Steer_Go_Angle = (int8_T *)ssGetInputPortSignal(chartInstance->S,
            1);
          c14_Origin_Back_Angle = (real32_T *)ssGetInputPortSignal
            (chartInstance->S, 0);
          c14_Original_Flag = (real_T *)ssGetOutputPortSignal(chartInstance->S,
            12);
          c14_Encoder_Msg_Data = (uint8_T (*)[6])ssGetOutputPortSignal
            (chartInstance->S, 11);
          c14_Position_set = (real32_T *)ssGetOutputPortSignal(chartInstance->S,
            10);
          c14_New_Set_Point_Ctrl = (uint8_T *)ssGetOutputPortSignal
            (chartInstance->S, 9);
          c14_Abs_or_Rel_Ctrl = (uint8_T *)ssGetOutputPortSignal
            (chartInstance->S, 8);
          c14_Switch_On_Ctrl = (uint8_T *)ssGetOutputPortSignal(chartInstance->S,
            7);
          c14_Halt_Ctrl = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 6);
          c14_Enable_Voltage_Ctrl = (uint8_T *)ssGetOutputPortSignal
            (chartInstance->S, 5);
          c14_Quick_Stop_Ctrl = (uint8_T *)ssGetOutputPortSignal
            (chartInstance->S, 4);
          c14_Enable_Operation_Ctrl = (uint8_T *)ssGetOutputPortSignal
            (chartInstance->S, 3);
          c14_NMT_nodectrl = (uint8_T *)ssGetOutputPortSignal(chartInstance->S,
            2);
          c14_NMT_nodeorder = (uint8_T *)ssGetOutputPortSignal(chartInstance->S,
            1);
          _SFD_SET_DATA_VALUE_PTR(0U, c14_NMT_nodeorder);
          _SFD_SET_DATA_VALUE_PTR(1U, c14_NMT_nodectrl);
          _SFD_SET_DATA_VALUE_PTR(2U, c14_Enable_Operation_Ctrl);
          _SFD_SET_DATA_VALUE_PTR(3U, c14_Quick_Stop_Ctrl);
          _SFD_SET_DATA_VALUE_PTR(4U, c14_Enable_Voltage_Ctrl);
          _SFD_SET_DATA_VALUE_PTR(5U, c14_Halt_Ctrl);
          _SFD_SET_DATA_VALUE_PTR(6U, c14_Switch_On_Ctrl);
          _SFD_SET_DATA_VALUE_PTR(7U, c14_Abs_or_Rel_Ctrl);
          _SFD_SET_DATA_VALUE_PTR(8U, c14_New_Set_Point_Ctrl);
          _SFD_SET_DATA_VALUE_PTR(9U, c14_Position_set);
          _SFD_SET_DATA_VALUE_PTR(10U, *c14_Encoder_Msg_Data);
          _SFD_SET_DATA_VALUE_PTR(11U, c14_Original_Flag);
          _SFD_SET_DATA_VALUE_PTR(12U, c14_Origin_Back_Angle);
          _SFD_SET_DATA_VALUE_PTR(13U, c14_Steer_Go_Angle);
          _SFD_SET_DATA_VALUE_PTR(14U, c14_ASSI_State);
          _SFD_SET_DATA_VALUE_PTR(15U, c14_Str_Status);
          _SFD_SET_DATA_VALUE_PTR(16U, c14_Fault_Resrt);
          _SFD_SET_DATA_VALUE_PTR(17U, c14_flag);
          _SFD_SET_DATA_VALUE_PTR(18U, c14_enflag);
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
  return "hpds2ukzApV05LBxQq6wlG";
}

static void sf_opaque_initialize_c14_FSAC2021_826(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc14_FSAC2021_826InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c14_FSAC2021_826((SFc14_FSAC2021_826InstanceStruct*)
    chartInstanceVar);
  initialize_c14_FSAC2021_826((SFc14_FSAC2021_826InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c14_FSAC2021_826(void *chartInstanceVar)
{
  enable_c14_FSAC2021_826((SFc14_FSAC2021_826InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c14_FSAC2021_826(void *chartInstanceVar)
{
  disable_c14_FSAC2021_826((SFc14_FSAC2021_826InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c14_FSAC2021_826(void *chartInstanceVar)
{
  sf_gateway_c14_FSAC2021_826((SFc14_FSAC2021_826InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c14_FSAC2021_826(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c14_FSAC2021_826
    ((SFc14_FSAC2021_826InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c14_FSAC2021_826();/* state var info */
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

extern void sf_internal_set_sim_state_c14_FSAC2021_826(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c14_FSAC2021_826();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c14_FSAC2021_826((SFc14_FSAC2021_826InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c14_FSAC2021_826(SimStruct* S)
{
  return sf_internal_get_sim_state_c14_FSAC2021_826(S);
}

static void sf_opaque_set_sim_state_c14_FSAC2021_826(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c14_FSAC2021_826(S, st);
}

static void sf_opaque_terminate_c14_FSAC2021_826(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc14_FSAC2021_826InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_FSAC2021_826_optimization_info();
    }

    finalize_c14_FSAC2021_826((SFc14_FSAC2021_826InstanceStruct*)
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
  initSimStructsc14_FSAC2021_826((SFc14_FSAC2021_826InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c14_FSAC2021_826(SimStruct *S)
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
    initialize_params_c14_FSAC2021_826((SFc14_FSAC2021_826InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c14_FSAC2021_826(SimStruct *S)
{
  ssSetNeedAbsoluteTime(S,1);
  ssSetModelReferenceSampleTimeDisallowInheritance(S);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_FSAC2021_826_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      14);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,14,"RTWCG"));
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,14,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,14);
    sf_mark_output_events_with_multiple_callers(S,sf_get_instance_specialization
      (),infoStruct,14,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,14,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,14,15);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=15; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,14);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(82788789U));
  ssSetChecksum1(S,(3064512114U));
  ssSetChecksum2(S,(3145219692U));
  ssSetChecksum3(S,(3776363938U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c14_FSAC2021_826(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c14_FSAC2021_826(SimStruct *S)
{
  SFc14_FSAC2021_826InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc14_FSAC2021_826InstanceStruct *)utMalloc(sizeof
    (SFc14_FSAC2021_826InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc14_FSAC2021_826InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c14_FSAC2021_826;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c14_FSAC2021_826;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c14_FSAC2021_826;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c14_FSAC2021_826;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c14_FSAC2021_826;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c14_FSAC2021_826;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c14_FSAC2021_826;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c14_FSAC2021_826;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c14_FSAC2021_826;
  chartInstance->chartInfo.mdlStart = mdlStart_c14_FSAC2021_826;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c14_FSAC2021_826;
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

void c14_FSAC2021_826_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c14_FSAC2021_826(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c14_FSAC2021_826(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c14_FSAC2021_826(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c14_FSAC2021_826_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
