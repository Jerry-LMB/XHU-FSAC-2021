/*
 * Code generated for Simulink model untitled.
 *
 * FILE    : untitled.c
 *
 * VERSION : 1.0
 *
 * DATE    : Fri Jul 23 01:50:15 2021
 *
 * Copyright 2011-2012 ECUCoder. All Rights Reserved.
 */

#include "untitled.h"
#include "untitled_private.h"

/* #include "myinclude.h" */
uint16 TLE6232DIA[12]= { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 };

/* Block signals (auto storage) */
B_untitled_T untitled_B;

/* Real-time model */
RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;
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
  /* Call the system: <S3>/Function-Call Subsystem */
  {
    /* Output and update for function-call system: '<S3>/Function-Call Subsystem' */

    /* S-Function (ec55xx_canreceiveslb): '<S8>/CANReceive1' */

    /* Receive CAN message */
    {
      uint8 CAN2BUF1RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

      uint8 can2buf1looprx= 0;
      untitled_B.CANReceive1_o3= 278;
      untitled_B.CANReceive1_o5= 8;
      untitled_B.CANReceive1_o2= ec_can_receive(2,1, CAN2BUF1RX);
      untitled_B.CANReceive1_o4[0]= CAN2BUF1RX[can2buf1looprx];
      can2buf1looprx++;
      untitled_B.CANReceive1_o4[1]= CAN2BUF1RX[can2buf1looprx];
      can2buf1looprx++;
      untitled_B.CANReceive1_o4[2]= CAN2BUF1RX[can2buf1looprx];
      can2buf1looprx++;
      untitled_B.CANReceive1_o4[3]= CAN2BUF1RX[can2buf1looprx];
      can2buf1looprx++;
      untitled_B.CANReceive1_o4[4]= CAN2BUF1RX[can2buf1looprx];
      can2buf1looprx++;
      untitled_B.CANReceive1_o4[5]= CAN2BUF1RX[can2buf1looprx];
      can2buf1looprx++;
      untitled_B.CANReceive1_o4[6]= CAN2BUF1RX[can2buf1looprx];
      can2buf1looprx++;
      untitled_B.CANReceive1_o4[7]= CAN2BUF1RX[can2buf1looprx];
      can2buf1looprx++;
    }

    /* Call the system: <S8>/Function-Call Subsystem */

    /* Output and update for function-call system: '<S8>/Function-Call Subsystem' */

    /* If: '<S9>/If' incorporates:
     *  Constant: '<S10>/Constant'
     *  Constant: '<S11>/Constant'
     *  Constant: '<S12>/Constant'
     *  Constant: '<S14>/Constant'
     *  RelationalOperator: '<S10>/Compare'
     *  RelationalOperator: '<S11>/Compare'
     *  RelationalOperator: '<S12>/Compare'
     *  Sum: '<S9>/Add'
     */
    if (((int32_T)((uint32_T)(untitled_B.CANReceive1_o4[0] == 83) +
                   (untitled_B.CANReceive1_o4[5] == 84)) == 2) > 0) {
      /* Outputs for IfAction SubSystem: '<S9>/If Action Subsystem' incorporates:
       *  ActionPort: '<S13>/Action Port'
       */

      /* S-Function (ec55xx_bootloaderslb): '<S13>/BootLoader' */
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

      /* S-Function (ec55xx_cpuresetslb): '<S13>/CPUReset' */

      /* Perform a microcontroller reset */
      ec_cpu_reset();

      /* End of Outputs for SubSystem: '<S9>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S9>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S14>/Action Port'
       */

      /* S-Function (ec55xx_cantransmitslb): '<S14>/CANTransmit' */

      /*Transmit CAN message*/
      {
        uint8 CAN2BUF9TX[1];
        uint8 can2buf9looptx= 0;
        CAN2BUF9TX[can2buf9looptx]= ((uint8_T)1U);
        can2buf9looptx++;
        untitled_B.CANTransmit_h= ec_can_transmit(2, 9, 0, 593U, 1, CAN2BUF9TX);
      }

      /* End of Outputs for SubSystem: '<S9>/If Action Subsystem1' */
    }

    /* End of If: '<S9>/If' */
  }

  FLEXCAN(2).IFRL.B.BUF01I = 1;        /* Clear CAN interrupt flag by writing it to 1 */
}

void ISR_FlexCAN_2_MB0(void)
{
  /* Call the system: <S7>/CCPReceive */
  {
    /* Output and update for function-call system: '<S7>/CCPReceive' */

    /* S-Function (ec55xx_canreceiveslb): '<S22>/CANReceive' */

    /* Receive CAN message */
    {
      uint8 CAN2BUF0RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

      uint8 can2buf0looprx= 0;
      untitled_B.CANReceive_o3= 256;
      untitled_B.CANReceive_o5= 8;
      untitled_B.CANReceive_o2= ec_can_receive(2,0, CAN2BUF0RX);
      untitled_B.CANReceive_o4[0]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      untitled_B.CANReceive_o4[1]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      untitled_B.CANReceive_o4[2]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      untitled_B.CANReceive_o4[3]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      untitled_B.CANReceive_o4[4]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      untitled_B.CANReceive_o4[5]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      untitled_B.CANReceive_o4[6]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      untitled_B.CANReceive_o4[7]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
    }

    /* Nothing to do for system: <S22>/Nothing */
  }

  FLEXCAN(2).IFRL.B.BUF00I = 1;        /* Clear CAN interrupt flag by writing it to 1 */
}

void ISR_FlexCAN_2_MB8(void)
{
  /* Call the system: <S7>/CCPTransmit */
  {
    /* Output and update for function-call system: '<S7>/CCPTransmit' */

    /* S-Function (ec55xx_ccpslb2): '<S23>/CCPTXConfirmation' */
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
void untitled_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(untitled_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(untitled_M, 2));
  eventFlags[3] = ((boolean_T)rtmStepTask(untitled_M, 3));
  eventFlags[4] = ((boolean_T)rtmStepTask(untitled_M, 4));
  eventFlags[5] = ((boolean_T)rtmStepTask(untitled_M, 5));
  eventFlags[6] = ((boolean_T)rtmStepTask(untitled_M, 6));
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
  (untitled_M->Timing.TaskCounters.TID[1])++;
  if ((untitled_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.001s, 0.0s] */
    untitled_M->Timing.TaskCounters.TID[1] = 0;
  }

  (untitled_M->Timing.TaskCounters.TID[2])++;
  if ((untitled_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.005s, 0.0s] */
    untitled_M->Timing.TaskCounters.TID[2] = 0;
  }

  (untitled_M->Timing.TaskCounters.TID[3])++;
  if ((untitled_M->Timing.TaskCounters.TID[3]) > 19) {/* Sample time: [0.01s, 0.0s] */
    untitled_M->Timing.TaskCounters.TID[3] = 0;
  }

  (untitled_M->Timing.TaskCounters.TID[4])++;
  if ((untitled_M->Timing.TaskCounters.TID[4]) > 99) {/* Sample time: [0.05s, 0.0s] */
    untitled_M->Timing.TaskCounters.TID[4] = 0;
  }

  (untitled_M->Timing.TaskCounters.TID[5])++;
  if ((untitled_M->Timing.TaskCounters.TID[5]) > 199) {/* Sample time: [0.1s, 0.0s] */
    untitled_M->Timing.TaskCounters.TID[5] = 0;
  }

  (untitled_M->Timing.TaskCounters.TID[6])++;
  if ((untitled_M->Timing.TaskCounters.TID[6]) > 999) {/* Sample time: [0.5s, 0.0s] */
    untitled_M->Timing.TaskCounters.TID[6] = 0;
  }
}

/* Model step function for TID0 */
void untitled_step0(void)              /* Sample time: [0.0005s, 0.0s] */
{
  {                                    /* Sample time: [0.0005s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void untitled_step1(void)              /* Sample time: [0.001s, 0.0s] */
{
  /* S-Function (fcncallgen): '<S7>/Function-Call Generator' incorporates:
   *  SubSystem: '<S7>/CCPBackground'
   */

  /* S-Function (ec55xx_ccpslb): '<S21>/CCPBackground' */
  ccpBackground();
}

/* Model step function for TID2 */
void untitled_step2(void)              /* Sample time: [0.005s, 0.0s] */
{
  /* S-Function (fcncallgen): '<S4>/5ms' incorporates:
   *  SubSystem: '<S4>/daq5ms'
   */

  /* S-Function (ec55xx_ccpslb1): '<S18>/CCPDAQ' */
  ccpDaq(0);
}

/* Model step function for TID3 */
void untitled_step3(void)              /* Sample time: [0.01s, 0.0s] */
{
  /* S-Function (fcncallgen): '<S4>/10ms' incorporates:
   *  SubSystem: '<S4>/daq10ms'
   */

  /* S-Function (ec55xx_ccpslb1): '<S16>/CCPDAQ' */
  ccpDaq(1);

  /* S-Function (fcncallgen): '<S6>/10ms' incorporates:
   *  SubSystem: '<S6>/10mstask'
   */

  /* S-Function (ec55xx_pdsdslb1): '<S20>/PDSD' */
  ec_tle6232_diag();
}

/* Model step function for TID4 */
void untitled_step4(void)              /* Sample time: [0.05s, 0.0s] */
{
  /* S-Function (ec55xx_cantransmitslb): '<Root>/CANTransmit' */

  /*Transmit CAN message*/
  {
    uint8 CAN0BUF8TX[8];
    uint8 can0buf8looptx= 0;
    CAN0BUF8TX[can0buf8looptx]= ((uint8_T)0U);
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= ((uint8_T)0U);
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= ((uint8_T)0U);
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= ((uint8_T)0U);
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= ((uint8_T)0U);
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= ((uint8_T)0U);
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= ((uint8_T)0U);
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= ((uint8_T)0U);
    can0buf8looptx++;
    untitled_B.CANTransmit= ec_can_transmit(0, 8, 0, 353U, 8, CAN0BUF8TX);
  }

  /* S-Function (fcncallgen): '<S4>/50ms' incorporates:
   *  SubSystem: '<S4>/daq50ms'
   */

  /* S-Function (ec55xx_ccpslb1): '<S17>/CCPDAQ' */
  ccpDaq(2);
}

/* Model step function for TID5 */
void untitled_step5(void)              /* Sample time: [0.1s, 0.0s] */
{
  /* S-Function (fcncallgen): '<S4>/100ms' incorporates:
   *  SubSystem: '<S4>/daq100ms'
   */

  /* S-Function (ec55xx_ccpslb1): '<S15>/CCPDAQ' */
  ccpDaq(3);
}

/* Model step function for TID6 */
void untitled_step6(void)              /* Sample time: [0.5s, 0.0s] */
{
  /* S-Function (fcncallgen): '<S5>/500ms' incorporates:
   *  SubSystem: '<S5>/FlashOperation'
   */

  /* S-Function (ec55xx_flashoslb): '<S19>/FlashOperatin' */
#if defined EC_FLASH_ENABLE

  /* Operate the flash module on the MPC5554 */
  ec_flash_operation();

#endif

}

/* Model step wrapper function for compatibility with a static main program */
void untitled_step(int_T tid)
{
  switch (tid) {
   case 0 :
    untitled_step0();
    break;

   case 1 :
    untitled_step1();
    break;

   case 2 :
    untitled_step2();
    break;

   case 3 :
    untitled_step3();
    break;

   case 4 :
    untitled_step4();
    break;

   case 5 :
    untitled_step5();
    break;

   case 6 :
    untitled_step6();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Start for S-Function (ec55xx_cantransmitslb): '<Root>/CANTransmit' */
  ec_buffer_init(0,8,0,353U);

  /* Start for S-Function (ec55xx_caninterruptslb1): '<S3>/ReceiveandTransmitInterrupt' incorporates:
   *  Start for SubSystem: '<S3>/Function-Call Subsystem'
   */
  /* Start for function-call system: '<S3>/Function-Call Subsystem' */

  /* Start for S-Function (ec55xx_canreceiveslb): '<S8>/CANReceive1' incorporates:
   *  Start for SubSystem: '<S8>/Function-Call Subsystem'
   */
  /* Start for function-call system: '<S8>/Function-Call Subsystem' */

  /* Start for IfAction SubSystem: '<S9>/If Action Subsystem1' */

  /* Start for S-Function (ec55xx_cantransmitslb): '<S14>/CANTransmit' */
  ec_buffer_init(2,9,0,593U);

  /* End of Start for SubSystem: '<S9>/If Action Subsystem1' */

  /* Start for S-Function (ec55xx_canreceiveslb): '<S8>/CANReceive1' */
  ec_buffer_init(2,1,0,278);

  /* Start for S-Function (ec55xx_caninterruptslb1): '<S3>/ReceiveandTransmitInterrupt' */
  ec_bufint_init(2,1);
  INTC_InstallINTCInterruptHandler( ISR_FlexCAN_2_MB1, SW_INT_VEC_CAN2_IFRL_BUF1,
    CAN2_INTC_PRIORITY );

  /* Start for S-Function (fcncallgen): '<S7>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S7>/CCPBackground'
   */
  /* Start for S-Function (ec55xx_ccpslb): '<S21>/CCPBackground' */
  ccpInit();

  /* Start for S-Function (ec55xx_caninterruptslb1): '<S7>/ReceiveandTransmitInterrupt' incorporates:
   *  Start for SubSystem: '<S7>/CCPReceive'
   */
  /* Start for function-call system: '<S7>/CCPReceive' */

  /* Start for S-Function (ec55xx_canreceiveslb): '<S22>/CANReceive' */
  ec_buffer_init(2,0,0,CCP_CRO_ID);

  /* Start for S-Function (ec55xx_caninterruptslb1): '<S7>/ReceiveandTransmitInterrupt' */
  ec_bufint_init(2,0);
  INTC_InstallINTCInterruptHandler( ISR_FlexCAN_2_MB0, SW_INT_VEC_CAN2_IFRL_BUF0,
    CAN2_INTC_PRIORITY );

  /* Start for S-Function (ec55xx_caninterruptslb1): '<S7>/ReceiveandTransmitInterrupt1' */
  ec_bufint_init(2,8);
  INTC_InstallINTCInterruptHandler( ISR_FlexCAN_2_MB8, SW_INT_VEC_CAN2_IFRL_BUF8,
    CAN2_INTC_PRIORITY );

  /* Start for S-Function (ec55xx_adcbsb): '<S2>/ADC' */
  ec_adc_init();

  /* Start for S-Function (ec55xx_rtibsb): '<S2>/RTI' */
  ec_rti_init(500);
}

/* File trailer for ECUCoder generated file untitled.c.
 *
 * [EOF]
 */
