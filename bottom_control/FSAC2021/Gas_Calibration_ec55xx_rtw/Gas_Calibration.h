/*
 * Code generated for Simulink model Gas_Calibration.
 *
 * FILE    : Gas_Calibration.h
 *
 * VERSION : 1.1
 *
 * DATE    : Sat Oct 02 12:32:17 2021
 *
 * Copyright 2011-2012 ECUCoder. All Rights Reserved.
 */

#ifndef RTW_HEADER_Gas_Calibration_h_
#define RTW_HEADER_Gas_Calibration_h_
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
#ifndef Gas_Calibration_COMMON_INCLUDES_
# define Gas_Calibration_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Gas_Calibration_COMMON_INCLUDES_ */

#include "Gas_Calibration_types.h"

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
  uint32_T CANReceive_o3;              /* '<S23>/CANReceive' */
  uint32_T CANReceive1_o3;             /* '<S9>/CANReceive1' */
  uint8_T CANReceive_o2;               /* '<S23>/CANReceive' */
  uint8_T CANReceive_o4[8];            /* '<S23>/CANReceive' */
  uint8_T CANReceive_o5;               /* '<S23>/CANReceive' */
  uint8_T CANReceive1_o2;              /* '<S9>/CANReceive1' */
  uint8_T CANReceive1_o4[8];           /* '<S9>/CANReceive1' */
  uint8_T CANReceive1_o5;              /* '<S9>/CANReceive1' */
  uint8_T CANTransmit;                 /* '<S15>/CANTransmit' */
} B_Gas_Calibration_T;

/* Real-time Model Data Structure */
struct tag_RTM_Gas_Calibration_T {
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
extern B_Gas_Calibration_T Gas_Calibration_B;

/* External function called from main */
extern void Gas_Calibration_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void Gas_Calibration_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void Gas_Calibration_initialize(void);
extern void Gas_Calibration_step(int_T tid);
extern uint8_T ECUCoderModelBaseCounter;
extern uint8_T AfterRunFlags[2];

/* Exported data declaration */

/* Declaration for custom storage class: Default */
extern uint16_T Gas1;
extern uint16_T Gas2;

/* Real-time Model object */
extern RT_MODEL_Gas_Calibration_T *const Gas_Calibration_M;

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
 * '<Root>' : 'Gas_Calibration'
 * '<S1>'   : 'Gas_Calibration/MeaModule'
 * '<S2>'   : 'Gas_Calibration/MeaModule1'
 * '<S3>'   : 'Gas_Calibration/RapidECUSetting'
 * '<S4>'   : 'Gas_Calibration/RapidECUSetting/BL'
 * '<S5>'   : 'Gas_Calibration/RapidECUSetting/DAQ'
 * '<S6>'   : 'Gas_Calibration/RapidECUSetting/Flash'
 * '<S7>'   : 'Gas_Calibration/RapidECUSetting/PD'
 * '<S8>'   : 'Gas_Calibration/RapidECUSetting/Polling'
 * '<S9>'   : 'Gas_Calibration/RapidECUSetting/BL/Function-Call Subsystem'
 * '<S10>'  : 'Gas_Calibration/RapidECUSetting/BL/Function-Call Subsystem/Function-Call Subsystem'
 * '<S11>'  : 'Gas_Calibration/RapidECUSetting/BL/Function-Call Subsystem/Function-Call Subsystem/Com0'
 * '<S12>'  : 'Gas_Calibration/RapidECUSetting/BL/Function-Call Subsystem/Function-Call Subsystem/Com1'
 * '<S13>'  : 'Gas_Calibration/RapidECUSetting/BL/Function-Call Subsystem/Function-Call Subsystem/Com2'
 * '<S14>'  : 'Gas_Calibration/RapidECUSetting/BL/Function-Call Subsystem/Function-Call Subsystem/If Action Subsystem'
 * '<S15>'  : 'Gas_Calibration/RapidECUSetting/BL/Function-Call Subsystem/Function-Call Subsystem/If Action Subsystem1'
 * '<S16>'  : 'Gas_Calibration/RapidECUSetting/DAQ/daq100ms'
 * '<S17>'  : 'Gas_Calibration/RapidECUSetting/DAQ/daq10ms'
 * '<S18>'  : 'Gas_Calibration/RapidECUSetting/DAQ/daq50ms'
 * '<S19>'  : 'Gas_Calibration/RapidECUSetting/DAQ/daq5ms'
 * '<S20>'  : 'Gas_Calibration/RapidECUSetting/Flash/FlashOperation'
 * '<S21>'  : 'Gas_Calibration/RapidECUSetting/PD/10mstask'
 * '<S22>'  : 'Gas_Calibration/RapidECUSetting/Polling/CCPBackground'
 * '<S23>'  : 'Gas_Calibration/RapidECUSetting/Polling/CCPReceive'
 * '<S24>'  : 'Gas_Calibration/RapidECUSetting/Polling/CCPTransmit'
 * '<S25>'  : 'Gas_Calibration/RapidECUSetting/Polling/CCPReceive/Nothing'
 */
#endif                                 /* RTW_HEADER_Gas_Calibration_h_ */

/* File trailer for ECUCoder generated file Gas_Calibration.h.
 *
 * [EOF]
 */
