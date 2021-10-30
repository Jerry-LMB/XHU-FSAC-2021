/*
 * Code generated for Simulink model Gas_Calibration.
 *
 * FILE    : Gas_Calibration.c
 *
 * VERSION : 1.1
 *
 * DATE    : Sat Oct 02 12:32:17 2021
 *
 * Copyright 2011-2012 ECUCoder. All Rights Reserved.
 */

#include "Gas_Calibration.h"
#include "Gas_Calibration_private.h"

/* #include "myinclude.h" */
uint16 TLE6232DIA[12]= { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 };

/* Exported data definition */

/* Definition for custom storage class: Default */
uint16_T Gas1;
uint16_T Gas2;

/* Block signals (auto storage) */
B_Gas_Calibration_T Gas_Calibration_B;

/* Real-time model */
RT_MODEL_Gas_Calibration_T Gas_Calibration_M_;
RT_MODEL_Gas_Calibration_T *const Gas_Calibration_M = &Gas_Calibration_M_;
static void rate_monotonic_scheduler(void);

/* TLE6240 control function */
void ec_tle6232_diag(void)
{
  int i;
  uint16 RD_DIAG[1] = { 0x8000 };      //Read DIAG Register

  uint16 RD_DIAG_RX1[1] = { 0x0000 };  //Read DIAG Register--returned value, chip1

  uint16 RD_DIAG_RX2[1] = { 0x0000 };  //Read DIAG Register--returned value, chip2

  ec_spi_masterwriteread(0, 1, 1, RD_DIAG, RD_DIAG_RX1);
  i= 10;
  while (i--) {
    ;
  }

  for (i=0; i<6; i++) {
    TLE6232DIA[i] = ((RD_DIAG_RX1[0] & (0x0003<<(i*2))))>>(i*2);
  }

  ec_spi_masterwriteread(0, 2, 1, RD_DIAG, RD_DIAG_RX2);
  i= 10;
  while (i--) {
    ;
  }

  for (i=0; i<6; i++) {
    TLE6232DIA[i+6] = ((RD_DIAG_RX2[0] & (0x0003<<(i*2))))>>(i*2);
  }
}

void ISR_Rti_CH23(void)
{
  EMIOS.CH[23].CSR.B.FLAG = 0x1;       /* Clear interrupt flag */
  ECUCoderModelBaseCounter++;
  rate_monotonic_scheduler();
}

void ISR_FlexCAN_2_MB1(void)
{
  /* Call the system: <S4>/Function-Call Subsystem */
  {
    /* Output and update for function-call system: '<S4>/Function-Call Subsystem' */

    /* S-Function (ec55xx_canreceiveslb): '<S9>/CANReceive1' */

    /* Receive CAN message */
    {
      uint8 CAN2BUF1RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

      uint8 can2buf1looprx= 0;
      Gas_Calibration_B.CANReceive1_o3= 278;
      Gas_Calibration_B.CANReceive1_o5= 8;
      Gas_Calibration_B.CANReceive1_o2= ec_can_receive(2,1, CAN2BUF1RX);
      Gas_Calibration_B.CANReceive1_o4[0]= CAN2BUF1RX[can2buf1looprx];
      can2buf1looprx++;
      Gas_Calibration_B.CANReceive1_o4[1]= CAN2BUF1RX[can2buf1looprx];
      can2buf1looprx++;
      Gas_Calibration_B.CANReceive1_o4[2]= CAN2BUF1RX[can2buf1looprx];
      can2buf1looprx++;
      Gas_Calibration_B.CANReceive1_o4[3]= CAN2BUF1RX[can2buf1looprx];
      can2buf1looprx++;
      Gas_Calibration_B.CANReceive1_o4[4]= CAN2BUF1RX[can2buf1looprx];
      can2buf1looprx++;
      Gas_Calibration_B.CANReceive1_o4[5]= CAN2BUF1RX[can2buf1looprx];
      can2buf1looprx++;
      Gas_Calibration_B.CANReceive1_o4[6]= CAN2BUF1RX[can2buf1looprx];
      can2buf1looprx++;
      Gas_Calibration_B.CANReceive1_o4[7]= CAN2BUF1RX[can2buf1looprx];
      can2buf1looprx++;
    }

    /* Call the system: <S9>/Function-Call Subsystem */

    /* Output and update for function-call system: '<S9>/Function-Call Subsystem' */

    /* If: '<S10>/If' incorporates:
     *  Constant: '<S11>/Constant'
     *  Constant: '<S12>/Constant'
     *  Constant: '<S13>/Constant'
     *  Constant: '<S15>/Constant'
     *  RelationalOperator: '<S11>/Compare'
     *  RelationalOperator: '<S12>/Compare'
     *  RelationalOperator: '<S13>/Compare'
     *  Sum: '<S10>/Add'
     */
    if (((int32_T)((uint32_T)(Gas_Calibration_B.CANReceive1_o4[0] == 83) +
                   (Gas_Calibration_B.CANReceive1_o4[5] == 84)) == 2) > 0) {
      /* Outputs for IfAction SubSystem: '<S10>/If Action Subsystem' incorporates:
       *  ActionPort: '<S14>/Action Port'
       */

      /* S-Function (ec55xx_bootloaderslb): '<S14>/BootLoader' */
      {
        uint16 i= 0;
        uint8 CAN2BUF9TX[]= { 11, 12, 12, 13 };

        uint8 returnCode1= 0;
        uint8 bootflag[]= { 1, 0, 0, 0, 0, 0, 0, 0 };

        DisableInterrupts();
        returnCode1 = pFlashErase( &ssdConfig, FALSE, 0x00000000, 0x00000000,
          0x00000800, NULL_CALLBACK );
        if (returnCode1 != H7F_OK ) {
          while (1) {
            ;
          }
        }

        pFlashProgram( &ssdConfig, 0x1ffff0, 8,(uint32)bootflag, NULL_CALLBACK );
        i= 1000;
        while (i--) {
          ;
        }

        ec_can_transmit(2, 9, 0, 593, 4, CAN2BUF9TX);
        i= 10000;
        while (i--) {
          ;
        }
      }

      /* S-Function (ec55xx_cpuresetslb): '<S14>/CPUReset' */

      /* Perform a microcontroller reset */
      ec_cpu_reset();

      /* End of Outputs for SubSystem: '<S10>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S10>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S15>/Action Port'
       */

      /* S-Function (ec55xx_cantransmitslb): '<S15>/CANTransmit' */

      /*Transmit CAN message*/
      {
        uint8 CAN2BUF9TX[1];
        uint8 can2buf9looptx= 0;
        CAN2BUF9TX[can2buf9looptx]= ((uint8_T)1U);
        can2buf9looptx++;
        Gas_Calibration_B.CANTransmit= ec_can_transmit(2, 9, 0, 593U, 1,
          CAN2BUF9TX);
      }

      /* End of Outputs for SubSystem: '<S10>/If Action Subsystem1' */
    }

    /* End of If: '<S10>/If' */
  }

  FLEXCAN(2).IFRL.B.BUF01I = 1;        /* Clear CAN interrupt flag by writing it to 1 */
}

void ISR_FlexCAN_2_MB0(void)
{
  /* Call the system: <S8>/CCPReceive */
  {
    /* Output and update for function-call system: '<S8>/CCPReceive' */

    /* S-Function (ec55xx_canreceiveslb): '<S23>/CANReceive' */

    /* Receive CAN message */
    {
      uint8 CAN2BUF0RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

      uint8 can2buf0looprx= 0;
      Gas_Calibration_B.CANReceive_o3= 256;
      Gas_Calibration_B.CANReceive_o5= 8;
      Gas_Calibration_B.CANReceive_o2= ec_can_receive(2,0, CAN2BUF0RX);
      Gas_Calibration_B.CANReceive_o4[0]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      Gas_Calibration_B.CANReceive_o4[1]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      Gas_Calibration_B.CANReceive_o4[2]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      Gas_Calibration_B.CANReceive_o4[3]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      Gas_Calibration_B.CANReceive_o4[4]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      Gas_Calibration_B.CANReceive_o4[5]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      Gas_Calibration_B.CANReceive_o4[6]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      Gas_Calibration_B.CANReceive_o4[7]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
    }

    /* Nothing to do for system: <S23>/Nothing */
  }

  FLEXCAN(2).IFRL.B.BUF00I = 1;        /* Clear CAN interrupt flag by writing it to 1 */
}

void ISR_FlexCAN_2_MB8(void)
{
  /* Call the system: <S8>/CCPTransmit */
  {
    /* Output and update for function-call system: '<S8>/CCPTransmit' */

    /* S-Function (ec55xx_ccpslb2): '<S24>/CCPTXConfirmation' */
    ec_can_appltxconfirmation(FLEXCAN_C,8);
  }

  FLEXCAN(2).IFRL.B.BUF08I = 1;        /* Clear CAN interrupt flag by writing it to 1 */
}

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Gas_Calibration_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Gas_Calibration_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(Gas_Calibration_M, 2));
  eventFlags[3] = ((boolean_T)rtmStepTask(Gas_Calibration_M, 3));
  eventFlags[4] = ((boolean_T)rtmStepTask(Gas_Calibration_M, 4));
  eventFlags[5] = ((boolean_T)rtmStepTask(Gas_Calibration_M, 5));
  eventFlags[6] = ((boolean_T)rtmStepTask(Gas_Calibration_M, 6));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Gas_Calibration_M->Timing.TaskCounters.TID[1])++;
  if ((Gas_Calibration_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.001s, 0.0s] */
    Gas_Calibration_M->Timing.TaskCounters.TID[1] = 0;
  }

  (Gas_Calibration_M->Timing.TaskCounters.TID[2])++;
  if ((Gas_Calibration_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.005s, 0.0s] */
    Gas_Calibration_M->Timing.TaskCounters.TID[2] = 0;
  }

  (Gas_Calibration_M->Timing.TaskCounters.TID[3])++;
  if ((Gas_Calibration_M->Timing.TaskCounters.TID[3]) > 19) {/* Sample time: [0.01s, 0.0s] */
    Gas_Calibration_M->Timing.TaskCounters.TID[3] = 0;
  }

  (Gas_Calibration_M->Timing.TaskCounters.TID[4])++;
  if ((Gas_Calibration_M->Timing.TaskCounters.TID[4]) > 99) {/* Sample time: [0.05s, 0.0s] */
    Gas_Calibration_M->Timing.TaskCounters.TID[4] = 0;
  }

  (Gas_Calibration_M->Timing.TaskCounters.TID[5])++;
  if ((Gas_Calibration_M->Timing.TaskCounters.TID[5]) > 199) {/* Sample time: [0.1s, 0.0s] */
    Gas_Calibration_M->Timing.TaskCounters.TID[5] = 0;
  }

  (Gas_Calibration_M->Timing.TaskCounters.TID[6])++;
  if ((Gas_Calibration_M->Timing.TaskCounters.TID[6]) > 999) {/* Sample time: [0.5s, 0.0s] */
    Gas_Calibration_M->Timing.TaskCounters.TID[6] = 0;
  }
}

/* Model step function for TID0 */
void Gas_Calibration_step0(void)       /* Sample time: [0.0005s, 0.0s] */
{
  {                                    /* Sample time: [0.0005s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void Gas_Calibration_step1(void)       /* Sample time: [0.001s, 0.0s] */
{
  /* S-Function (ec55xx_asislb): '<Root>/AnalogInput' */

  /* Read the ADC conversion result of the analog signal */
  Gas1= ec_adc_readresult(22);

  /* S-Function (ec55xx_asislb): '<Root>/AnalogInput1' */

  /* Read the ADC conversion result of the analog signal */
  Gas2= ec_adc_readresult(17);

  /* S-Function (fcncallgen): '<S8>/Function-Call Generator' incorporates:
   *  SubSystem: '<S8>/CCPBackground'
   */

  /* S-Function (ec55xx_ccpslb): '<S22>/CCPBackground' */
  ccpBackground();
}

/* Model step function for TID2 */
void Gas_Calibration_step2(void)       /* Sample time: [0.005s, 0.0s] */
{
  /* S-Function (fcncallgen): '<S5>/5ms' incorporates:
   *  SubSystem: '<S5>/daq5ms'
   */

  /* S-Function (ec55xx_ccpslb1): '<S19>/CCPDAQ' */
  ccpDaq(0);
}

/* Model step function for TID3 */
void Gas_Calibration_step3(void)       /* Sample time: [0.01s, 0.0s] */
{
  /* S-Function (fcncallgen): '<S5>/10ms' incorporates:
   *  SubSystem: '<S5>/daq10ms'
   */

  /* S-Function (ec55xx_ccpslb1): '<S17>/CCPDAQ' */
  ccpDaq(1);

  /* S-Function (fcncallgen): '<S7>/10ms' incorporates:
   *  SubSystem: '<S7>/10mstask'
   */

  /* S-Function (ec55xx_pdsdslb1): '<S21>/PDSD' */
  ec_tle6232_diag();
}

/* Model step function for TID4 */
void Gas_Calibration_step4(void)       /* Sample time: [0.05s, 0.0s] */
{
  /* S-Function (fcncallgen): '<S5>/50ms' incorporates:
   *  SubSystem: '<S5>/daq50ms'
   */

  /* S-Function (ec55xx_ccpslb1): '<S18>/CCPDAQ' */
  ccpDaq(2);
}

/* Model step function for TID5 */
void Gas_Calibration_step5(void)       /* Sample time: [0.1s, 0.0s] */
{
  /* S-Function (fcncallgen): '<S5>/100ms' incorporates:
   *  SubSystem: '<S5>/daq100ms'
   */

  /* S-Function (ec55xx_ccpslb1): '<S16>/CCPDAQ' */
  ccpDaq(3);
}

/* Model step function for TID6 */
void Gas_Calibration_step6(void)       /* Sample time: [0.5s, 0.0s] */
{
  /* S-Function (fcncallgen): '<S6>/500ms' incorporates:
   *  SubSystem: '<S6>/FlashOperation'
   */

  /* S-Function (ec55xx_flashoslb): '<S20>/FlashOperatin' */
#if defined EC_FLASH_ENABLE

  /* Operate the flash module on the MPC5554 */
  ec_flash_operation();

#endif

}

/* Model step wrapper function for compatibility with a static main program */
void Gas_Calibration_step(int_T tid)
{
  switch (tid) {
   case 0 :
    Gas_Calibration_step0();
    break;

   case 1 :
    Gas_Calibration_step1();
    break;

   case 2 :
    Gas_Calibration_step2();
    break;

   case 3 :
    Gas_Calibration_step3();
    break;

   case 4 :
    Gas_Calibration_step4();
    break;

   case 5 :
    Gas_Calibration_step5();
    break;

   case 6 :
    Gas_Calibration_step6();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void Gas_Calibration_initialize(void)
{
  /* Start for S-Function (ec55xx_caninterruptslb1): '<S4>/ReceiveandTransmitInterrupt' incorporates:
   *  Start for SubSystem: '<S4>/Function-Call Subsystem'
   */
  /* Start for function-call system: '<S4>/Function-Call Subsystem' */

  /* Start for S-Function (ec55xx_canreceiveslb): '<S9>/CANReceive1' incorporates:
   *  Start for SubSystem: '<S9>/Function-Call Subsystem'
   */
  /* Start for function-call system: '<S9>/Function-Call Subsystem' */

  /* Start for IfAction SubSystem: '<S10>/If Action Subsystem1' */

  /* Start for S-Function (ec55xx_cantransmitslb): '<S15>/CANTransmit' */
  ec_buffer_init(2,9,0,593U);

  /* End of Start for SubSystem: '<S10>/If Action Subsystem1' */

  /* Start for S-Function (ec55xx_canreceiveslb): '<S9>/CANReceive1' */
  ec_buffer_init(2,1,0,278);

  /* Start for S-Function (ec55xx_caninterruptslb1): '<S4>/ReceiveandTransmitInterrupt' */
  ec_bufint_init(2,1);
  INTC_InstallINTCInterruptHandler( ISR_FlexCAN_2_MB1, SW_INT_VEC_CAN2_IFRL_BUF1,
    CAN2_INTC_PRIORITY );

  /* Start for S-Function (fcncallgen): '<S8>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S8>/CCPBackground'
   */
  /* Start for S-Function (ec55xx_ccpslb): '<S22>/CCPBackground' */
  ccpInit();

  /* Start for S-Function (ec55xx_caninterruptslb1): '<S8>/ReceiveandTransmitInterrupt' incorporates:
   *  Start for SubSystem: '<S8>/CCPReceive'
   */
  /* Start for function-call system: '<S8>/CCPReceive' */

  /* Start for S-Function (ec55xx_canreceiveslb): '<S23>/CANReceive' */
  ec_buffer_init(2,0,0,CCP_CRO_ID);

  /* Start for S-Function (ec55xx_caninterruptslb1): '<S8>/ReceiveandTransmitInterrupt' */
  ec_bufint_init(2,0);
  INTC_InstallINTCInterruptHandler( ISR_FlexCAN_2_MB0, SW_INT_VEC_CAN2_IFRL_BUF0,
    CAN2_INTC_PRIORITY );

  /* Start for S-Function (ec55xx_caninterruptslb1): '<S8>/ReceiveandTransmitInterrupt1' */
  ec_bufint_init(2,8);
  INTC_InstallINTCInterruptHandler( ISR_FlexCAN_2_MB8, SW_INT_VEC_CAN2_IFRL_BUF8,
    CAN2_INTC_PRIORITY );

  /* Start for S-Function (ec55xx_adcbsb): '<S3>/ADC' */
  ec_adc_init();

  /* Start for S-Function (ec55xx_rtibsb): '<S3>/RTI' */
  ec_rti_init(500);
}

/* File trailer for ECUCoder generated file Gas_Calibration.c.
 *
 * [EOF]
 */
