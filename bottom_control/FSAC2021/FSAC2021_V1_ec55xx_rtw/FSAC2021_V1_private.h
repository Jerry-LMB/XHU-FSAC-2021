/*
 * Code generated for Simulink model FSAC2021_V1.
 *
 * FILE    : FSAC2021_V1_private.h
 *
 * VERSION : 1.219
 *
 * DATE    : Sat Oct 30 18:49:46 2021
 *
 * Copyright 2011-2012 ECUCoder. All Rights Reserved.
 */

#ifndef RTW_HEADER_FSAC2021_V1_private_h_
#define RTW_HEADER_FSAC2021_V1_private_h_
#include "rtwtypes.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error "Code was generated for compiler with different sized uchar/char. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compiler's limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, which will disable the preprocessor word size checks."
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error "Code was generated for compiler with different sized ushort/short. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error "Code was generated for compiler with different sized uint/int. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error "Code was generated for compiler with different sized ulong/long. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif

#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#endif                                 /* __RTWTYPES_H__ */

/* #define mydefine 100.0 */
extern real32_T rt_roundf_snf(real32_T u);
extern real_T rt_roundd_snf(real_T u);
extern void FSAC2021_V1_LPF_Init(DW_LPF_FSAC2021_V1_T *localDW);
extern void FSAC2021_V1_LPF(real32_T rtu_Filter, B_LPF_FSAC2021_V1_T *localB,
  DW_LPF_FSAC2021_V1_T *localDW);
extern void FSAC2021_V1_Round(real32_T rtu_Origin_Precision);
extern void FSAC2021_V1_Whl_Spd_Hz2RPM(uint32_T rtu_Whl_Spd_Hz,
  B_Whl_Spd_Hz2RPM_FSAC2021_V1_T *localB);
extern void FSAC2021_V_Whl_Spd_Hz2RPM2(uint32_T rtu_Whl_Spd_Hz,
  B_Whl_Spd_Hz2RPM2_FSAC2021_V1_T *localB);
extern void FSAC2021_V1_MOTEC_CONTROL(real32_T rtu_Abs_or_Rel_Ctrl_in, real32_T
  rtu_Fault_Reset_in, real32_T rtu_Enable_Voltage_Ctrl_in, real32_T
  rtu_New_Pos_Set_in, real32_T rtu_Enable_Operation_Ctrl_in, real32_T
  rtu_Switch_On_Ctrl_in, real32_T rtu_Quick_Stop_Ctrl_in, real32_T
  rtu_Halt_Ctrl_in, real32_T rtu_Position_set_in, B_MOTEC_CONTROL_FSAC2021_V1_T *
  localB);
extern void FSAC2021_V1_Angle2Pulses(B_Angle2Pulses_FSAC2021_V1_T *localB,
  ConstB_Angle2Pulses_FSAC2021__T *localC);
extern void FSAC2021_V1_Angle2Pulses_p(int8_T rtu_Angle,
  B_Angle2Pulses_FSAC2021_V1_o_T *localB);
extern void FSAC2021_V1_Angle2Pulses_b(real32_T rtu_Angle,
  B_Angle2Pulses_FSAC2021_V1_k_T *localB);
extern void FSAC2021_V1_Chart1_Enable(RT_MODEL_FSAC2021_V1_T * const
  FSAC2021_V1_M, DW_Chart1_FSAC2021_V1_T *localDW);
extern void FSAC2021_V1_Chart1_Disable(RT_MODEL_FSAC2021_V1_T * const
  FSAC2021_V1_M, DW_Chart1_FSAC2021_V1_T *localDW);
extern void FSAC2021_V1_Chart1(RT_MODEL_FSAC2021_V1_T * const FSAC2021_V1_M,
  uint8_T rtu_Input, B_Chart1_FSAC2021_V1_T *localB, DW_Chart1_FSAC2021_V1_T
  *localDW);
extern void FSAC2021_V1_Chart4_Enable(RT_MODEL_FSAC2021_V1_T * const
  FSAC2021_V1_M, DW_Chart4_FSAC2021_V1_T *localDW);
extern void FSAC2021_V1_Chart4_Disable(RT_MODEL_FSAC2021_V1_T * const
  FSAC2021_V1_M, DW_Chart4_FSAC2021_V1_T *localDW);
extern void FSAC2021_V1_Chart4(RT_MODEL_FSAC2021_V1_T * const FSAC2021_V1_M,
  uint8_T rtu_Input, DW_Chart4_FSAC2021_V1_T *localDW);
extern void FSAC2021_V_Chart1_n_Enable(RT_MODEL_FSAC2021_V1_T * const
  FSAC2021_V1_M, DW_Chart1_FSAC2021_V1_o_T *localDW);
extern void FSAC2021__Chart1_n_Disable(RT_MODEL_FSAC2021_V1_T * const
  FSAC2021_V1_M, DW_Chart1_FSAC2021_V1_o_T *localDW);
extern void FSAC2021_V1_Chart1_b(RT_MODEL_FSAC2021_V1_T * const FSAC2021_V1_M,
  real_T rtu_Input, B_Chart1_FSAC2021_V1_e_T *localB, DW_Chart1_FSAC2021_V1_o_T *
  localDW);
extern void FSAC2021_V1_Subsystem(boolean_T rtu_Enable, real32_T
  rtu_Compare_Volt_mv, boolean_T *rty_TS_Error);
extern void FSAC2021_V1_ON(uint8_T *rty_Out1);
extern void FSAC2021_V1_OFF(uint8_T *rty_Out1);
extern void FSAC2021_V1_BLINK(uint8_T *rty_Out1, DW_BLINK_FSAC2021_V1_T *localDW);
extern void FSAC2021_V_Light_Subsystem(uint8_T rtu_Light_Status,
  DW_Light_Subsystem_FSAC2021_V_T *localDW);
extern void FSAC2021__Light_Subsystem1(uint8_T rtu_Light_Status,
  B_Light_Subsystem1_FSAC2021_V_T *localB, DW_Light_Subsystem1_FSAC2021__T
  *localDW);
extern void FSA_Light_Subsystem2_Start(DW_Light_Subsystem2_FSAC2021__T *localDW);
extern void F_Light_Subsystem2_Disable(RT_MODEL_FSAC2021_V1_T * const
  FSAC2021_V1_M, DW_Light_Subsystem2_FSAC2021__T *localDW);
extern void FSAC2021__Light_Subsystem2(RT_MODEL_FSAC2021_V1_T * const
  FSAC2021_V1_M, uint8_T rtu_Buzzer_Flag, B_Light_Subsystem2_FSAC2021_V_T
  *localB, DW_Light_Subsystem2_FSAC2021__T *localDW);
extern void FSAC2021_V1_step0(void);
extern void FSAC2021_V1_step1(void);
extern void FSAC2021_V1_step2(void);
extern void FSAC2021_V1_step3(void);
extern void FSAC2021_V1_step4(void);
extern void FSAC2021_V1_step5(void);
extern void FSAC2021_V1_step6(void);
extern void FSAC2021_V1_step7(void);
extern void FSAC2021_V1_step8(void);
extern void FSAC2021_V1_step9(void);

#endif                                 /* RTW_HEADER_FSAC2021_V1_private_h_ */

/* File trailer for ECUCoder generated file FSAC2021_V1_private.h.
 *
 * [EOF]
 */
