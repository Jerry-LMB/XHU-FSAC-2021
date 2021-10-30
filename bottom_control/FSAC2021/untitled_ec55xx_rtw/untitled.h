/*
 * Code generated for Simulink model untitled.
 *
 * FILE    : untitled.h
 *
 * VERSION : 1.0
 *
 * DATE    : Fri Jul 23 01:50:15 2021
 *
 * Copyright 2011-2012 ECUCoder. All Rights Reserved.
 */

#ifndef RTW_HEADER_untitled_h_
#define RTW_HEADER_untitled_h_
#include "etpu_util.h"
#include "etpu_ic.h"
#include "etpu_pwm.h"
#include "etpu_gpio.h"
#include "etpu_ppa.h"
#include "MPC5554.h"
#include "Std_Types.h"
#include "interrupts.h"
#include "siu.h"
#include "flash_app.h"
#ifndef untitled_COMMON_INCLUDES_
# define untitled_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* untitled_COMMON_INCLUDES_ */

#include "untitled_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#define EnableInterrupts()             asm(" wrteei 1")
#define DisableInterrupts()            asm(" wrteei 0")

/* Block signals (auto storage) */
typedef struct {
  uint32_T CANReceive_o3;              /* '<S22>/CANReceive' */
  uint32_T CANReceive1_o3;             /* '<S8>/CANReceive1' */
  uint8_T CANTransmit;                 /* '<Root>/CANTransmit' */
  uint8_T CANReceive_o2;               /* '<S22>/CANReceive' */
  uint8_T CANReceive_o4[8];            /* '<S22>/CANReceive' */
  uint8_T CANReceive_o5;               /* '<S22>/CANReceive' */
  uint8_T CANReceive1_o2;              /* '<S8>/CANReceive1' */
  uint8_T CANReceive1_o4[8];           /* '<S8>/CANReceive1' */
  uint8_T CANReceive1_o5;              /* '<S8>/CANReceive1' */
  uint8_T CANTransmit_h;               /* '<S14>/CANTransmit' */
} B_untitled_T;

/* Real-time Model Data Structure */
struct tag_RTM_untitled_T {
  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[7];
    } TaskCounters;
  } Timing;
};

/* Block signals (auto storage) */
extern B_untitled_T untitled_B;

/* External function called from main */
extern void untitled_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void untitled_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void untitled_initialize(void);
extern void untitled_step(int_T tid);
extern uint8_T ECUCoderModelBaseCounter;
extern uint8_T AfterRunFlags[2];

/* Real-time Model object */
extern RT_MODEL_untitled_T *const untitled_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'untitled'
 * '<S1>'   : 'untitled/BCU_MTR_ENABLE'
 * '<S2>'   : 'untitled/RapidECUSetting'
 * '<S3>'   : 'untitled/RapidECUSetting/BL'
 * '<S4>'   : 'untitled/RapidECUSetting/DAQ'
 * '<S5>'   : 'untitled/RapidECUSetting/Flash'
 * '<S6>'   : 'untitled/RapidECUSetting/PD'
 * '<S7>'   : 'untitled/RapidECUSetting/Polling'
 * '<S8>'   : 'untitled/RapidECUSetting/BL/Function-Call Subsystem'
 * '<S9>'   : 'untitled/RapidECUSetting/BL/Function-Call Subsystem/Function-Call Subsystem'
 * '<S10>'  : 'untitled/RapidECUSetting/BL/Function-Call Subsystem/Function-Call Subsystem/Com0'
 * '<S11>'  : 'untitled/RapidECUSetting/BL/Function-Call Subsystem/Function-Call Subsystem/Com1'
 * '<S12>'  : 'untitled/RapidECUSetting/BL/Function-Call Subsystem/Function-Call Subsystem/Com2'
 * '<S13>'  : 'untitled/RapidECUSetting/BL/Function-Call Subsystem/Function-Call Subsystem/If Action Subsystem'
 * '<S14>'  : 'untitled/RapidECUSetting/BL/Function-Call Subsystem/Function-Call Subsystem/If Action Subsystem1'
 * '<S15>'  : 'untitled/RapidECUSetting/DAQ/daq100ms'
 * '<S16>'  : 'untitled/RapidECUSetting/DAQ/daq10ms'
 * '<S17>'  : 'untitled/RapidECUSetting/DAQ/daq50ms'
 * '<S18>'  : 'untitled/RapidECUSetting/DAQ/daq5ms'
 * '<S19>'  : 'untitled/RapidECUSetting/Flash/FlashOperation'
 * '<S20>'  : 'untitled/RapidECUSetting/PD/10mstask'
 * '<S21>'  : 'untitled/RapidECUSetting/Polling/CCPBackground'
 * '<S22>'  : 'untitled/RapidECUSetting/Polling/CCPReceive'
 * '<S23>'  : 'untitled/RapidECUSetting/Polling/CCPTransmit'
 * '<S24>'  : 'untitled/RapidECUSetting/Polling/CCPReceive/Nothing'
 */
#endif                                 /* RTW_HEADER_untitled_h_ */

/* File trailer for ECUCoder generated file untitled.h.
 *
 * [EOF]
 */
