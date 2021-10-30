/*
 * Code generated for Simulink model FSAC2021_V1.
 *
 * FILE    : FSAC2021_V1.c
 *
 * VERSION : 1.219
 *
 * DATE    : Sat Oct 30 18:49:46 2021
 *
 * Copyright 2011-2012 ECUCoder. All Rights Reserved.
 */

#include "FSAC2021_V1.h"
#include "FSAC2021_V1_private.h"

/* #include "myinclude.h" */

/* Named constants for Chart: '<S137>/Chart1' */
#define FSAC2021_V1_IN_Normal          ((uint8_T)1U)
#define FSAC2021_V1_IN_ON              ((uint8_T)2U)
#define FSAC2021_V1_IN_Off             ((uint8_T)3U)
#define FSAC2021_V1_IN_On              ((uint8_T)4U)

/* Named constants for Chart: '<S169>/Chart4' */
#define FSAC2021_V1_IN_Normal_h        ((uint8_T)1U)
#define FSAC2021_V1_IN_ON_j            ((uint8_T)2U)
#define FSAC2021_V1_IN_Off_g           ((uint8_T)3U)
#define FSAC2021_V1_IN_On_a            ((uint8_T)4U)

/* Named constants for Chart: '<S183>/Chart1' */
#define FSAC2021_V1_IN_Normal_a        ((uint8_T)1U)
#define FSAC2021_V1_IN_ON_h            ((uint8_T)2U)
#define FSAC2021_V1_IN_Off_a           ((uint8_T)3U)
#define FSAC2021_V1_IN_On_b            ((uint8_T)4U)

/* Named constants for Chart: '<S79>/Chart' */
#define FSAC2021_V1_IN_Start_Horn_OFF  ((uint8_T)1U)
#define FSAC2021_V1_IN_Start_Horn_ON   ((uint8_T)2U)
#define FSAC2021_V_IN_NO_ACTIVE_CHILD_n ((uint8_T)0U)

/* Named constants for Chart: '<S78>/Chart' */
#define FSAC2021_V1_IN_EBS_Horn_OFF    ((uint8_T)1U)
#define FSAC2021_V1_IN_EBS_Horn_ON     ((uint8_T)1U)
#define FSAC2021_V1_IN_EBS_Horn_ON1    ((uint8_T)2U)
#define FSAC2021_V1_IN_Horn            ((uint8_T)2U)

/* Named constants for Chart: '<S67>/Chart' */
#define FSAC2021_V1_IN_Aciton_Move     ((uint8_T)1U)
#define FSAC2021_V1_IN_Encoder1        ((uint8_T)1U)
#define FSAC2021_V1_IN_First           ((uint8_T)1U)
#define FSAC2021_V1_IN_Goto            ((uint8_T)1U)
#define FSAC2021_V1_IN_Init            ((uint8_T)1U)
#define FSAC2021_V1_IN_Motor_Enable    ((uint8_T)2U)
#define FSAC2021_V1_IN_Motor_Move      ((uint8_T)3U)
#define FSAC2021_V1_IN_Motor_Stanby    ((uint8_T)4U)
#define FSAC2021_V1_IN_Move            ((uint8_T)2U)
#define FSAC2021_V1_IN_Origin_Pos_Set  ((uint8_T)2U)
#define FSAC2021_V1_IN_Second          ((uint8_T)2U)
#define FSAC2021_V1_IN_Wait            ((uint8_T)5U)
#define FSAC2021_V_IN_Move_Position_Set ((uint8_T)2U)
#define FSAC2021_V_IN_NO_ACTIVE_CHILD_b ((uint8_T)0U)
#define FSAC2021__IN_Origin_Aciton_Move ((uint8_T)1U)
#define FSAC2021__IN_Pre_Operation_Mode ((uint8_T)3U)

/* Named constants for Chart: '<S66>/BCU_Strategy' */
#define FSAC2021_V1_IN_BackOrigin      ((uint8_T)1U)
#define FSAC2021_V1_IN_Idle            ((uint8_T)1U)
#define FSAC2021_V1_IN_Init_g          ((uint8_T)2U)
#define FSAC2021_V1_IN_Move_k          ((uint8_T)3U)
#define FSAC2021_V1_IN_RunMode         ((uint8_T)2U)
#define FSAC2021_V1_IN_Tozeros         ((uint8_T)4U)

/* Named constants for Chart: '<S95>/Chart' */
#define FSAC2021_V1_IN_Visuality_Off   ((uint8_T)1U)
#define FSAC2021_V1_IN_Visuality_On    ((uint8_T)2U)

/* Named constants for Chart: '<S65>/AS_Machine' */
#define FSAC2021_V1_IN_AS_Driving      ((uint8_T)1U)
#define FSAC2021_V1_IN_AS_Emergency    ((uint8_T)2U)
#define FSAC2021_V1_IN_AS_Finished     ((uint8_T)3U)
#define FSAC2021_V1_IN_AS_Off          ((uint8_T)4U)
#define FSAC2021_V1_IN_AS_Ready        ((uint8_T)5U)
#define FSAC2021_V1_IN_Manual_Driving  ((uint8_T)6U)
#define FSAC2021_V1_IN_Origin          ((uint8_T)2U)

/* Named constants for Chart: '<S93>/Chart' */
#define FSAC2021_V1_IN_Driverless      ((uint8_T)1U)
#define FSAC2021_V1_IN_Manul           ((uint8_T)2U)
#define FSAC2021_V1_IN_Task            ((uint8_T)3U)
#define FSAC2021_V1_IN_init            ((uint8_T)4U)

/* Named constants for Chart: '<S116>/Chart' */
#define FSAC2021_V1_IN_IN              ((uint8_T)1U)
#define FSAC2021_V1_IN_Move_c          ((uint8_T)1U)
#define FSAC2021_V1_IN_end             ((uint8_T)2U)
#define FSAC2021_V1_IN_init_g          ((uint8_T)3U)

/* Named constants for Chart: '<S147>/Chart' */
#define FSAC2021_V1_IN_Action          ((uint8_T)1U)
#define FSAC2021_V1_IN_Action1         ((uint8_T)2U)
#define FSAC2021_V1_IN_Init_d          ((uint8_T)3U)

uint16 TLE6232DIA[12]= { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 };

/* Exported data definition */

/* Definition for custom storage class: Default */
real32_T ACC;
real_T AMI;
uint8_T AMI_HEART;
real_T AMI_State;
boolean_T ASMS_Read;
uint8_T ASMS_VALUE;
uint8_T ASSI_state;
boolean_T BMS_LIGHT;
uint8_T BUC_Enable_Flag;
real32_T Back_Angle;
uint8_T Brk_Enable_Flag;
boolean_T Buzzer_pin;
boolean_T Compare_Voltage;
boolean_T EBS;
boolean_T EBS_Rel_Switch;
boolean_T EBS_Sensor_light;
uint8_T EBS_Status;
uint8_T EBS_light;
uint8_T ENCODER_SEND;
boolean_T HVMS_Read;
boolean_T HV_LIGHT;
boolean_T IMD;
boolean_T LVMS_Read;
uint8_T MNT_SEND;
real_T MODE;
uint8_T Metoc_Move;
real32_T Motor_Spd;
boolean_T Node_Lost;
boolean_T On_IN_Switch;
boolean_T On_Out_Switch;
boolean_T R2D_Voltage;
uint8_T RES_EBS;
real32_T RES_Value;
uint8_T RES__ok;
uint8_T Read_BCU;
uint16_T Read_EBS_Gas_Prs1;
uint16_T Read_EBS_Gas_Prs2;
uint16_T Read_Lft_Acc_Disp;
uint16_T Read_Right_Acc_Disp1;
real32_T Read_compare_OutVolt;
uint16_T Read_liquid_presuress;
boolean_T START;
boolean_T Stafe_Relay_pin;
uint8_T Steer_Status;
real32_T Steer_sensor_angle;
int8_T Str;
uint8_T TS_Flag;
uint8_T To_AMI_OK;
uint8_T To_MOTOR_OK;
boolean_T V48_relay;
real32_T Vel_spd;
real_T Voltage;
real32_T Vspd;
uint8_T blue;
uint8_T bms_node;
boolean_T brake_light;
uint8_T brake_node;
boolean_T enable;
real_T enflag;
uint8_T error_gas1;
uint8_T error_gas2;
uint8_T error_left;
uint8_T error_liquid;
uint8_T error_right;
real_T flag;
boolean_T light_blue;
uint8_T motec_node;
uint8_T motor;
uint8_T motor_node;
real_T pulses;
uint8_T read_speed;
uint8_T res_ebs_value;
uint8_T res_go;
boolean_T sensor_erroe;
uint8_T strsr_node;

/* Block signals (auto storage) */
B_FSAC2021_V1_T FSAC2021_V1_B;

/* Block states (auto storage) */
DW_FSAC2021_V1_T FSAC2021_V1_DW;

/* Real-time model */
RT_MODEL_FSAC2021_V1_T FSAC2021_V1_M_;
RT_MODEL_FSAC2021_V1_T *const FSAC2021_V1_M = &FSAC2021_V1_M_;
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
  /* Call the system: <S225>/Function-Call Subsystem */
  {
    /* Output and update for function-call system: '<S225>/Function-Call Subsystem' */

    /* S-Function (ec55xx_canreceiveslb): '<S230>/CANReceive1' */

    /* Receive CAN message */
    {
      uint8 CAN2BUF1RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

      uint8 can2buf1looprx= 0;
      FSAC2021_V1_B.CANReceive1_o3= 278;
      FSAC2021_V1_B.CANReceive1_o5= 8;
      FSAC2021_V1_B.CANReceive1_o2= ec_can_receive(2,1, CAN2BUF1RX);
      FSAC2021_V1_B.CANReceive1_o4[0]= CAN2BUF1RX[can2buf1looprx];
      can2buf1looprx++;
      FSAC2021_V1_B.CANReceive1_o4[1]= CAN2BUF1RX[can2buf1looprx];
      can2buf1looprx++;
      FSAC2021_V1_B.CANReceive1_o4[2]= CAN2BUF1RX[can2buf1looprx];
      can2buf1looprx++;
      FSAC2021_V1_B.CANReceive1_o4[3]= CAN2BUF1RX[can2buf1looprx];
      can2buf1looprx++;
      FSAC2021_V1_B.CANReceive1_o4[4]= CAN2BUF1RX[can2buf1looprx];
      can2buf1looprx++;
      FSAC2021_V1_B.CANReceive1_o4[5]= CAN2BUF1RX[can2buf1looprx];
      can2buf1looprx++;
      FSAC2021_V1_B.CANReceive1_o4[6]= CAN2BUF1RX[can2buf1looprx];
      can2buf1looprx++;
      FSAC2021_V1_B.CANReceive1_o4[7]= CAN2BUF1RX[can2buf1looprx];
      can2buf1looprx++;
    }

    /* Call the system: <S230>/Function-Call Subsystem */

    /* Output and update for function-call system: '<S230>/Function-Call Subsystem' */

    /* If: '<S231>/If' incorporates:
     *  Constant: '<S232>/Constant'
     *  Constant: '<S233>/Constant'
     *  Constant: '<S234>/Constant'
     *  Constant: '<S236>/Constant'
     *  RelationalOperator: '<S232>/Compare'
     *  RelationalOperator: '<S233>/Compare'
     *  RelationalOperator: '<S234>/Compare'
     *  Sum: '<S231>/Add'
     */
    if (((int32_T)((uint32_T)(FSAC2021_V1_B.CANReceive1_o4[0] == 83) +
                   (FSAC2021_V1_B.CANReceive1_o4[5] == 84)) == 2) > 0) {
      /* Outputs for IfAction SubSystem: '<S231>/If Action Subsystem' incorporates:
       *  ActionPort: '<S235>/Action Port'
       */

      /* S-Function (ec55xx_bootloaderslb): '<S235>/BootLoader' */
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

      /* S-Function (ec55xx_cpuresetslb): '<S235>/CPUReset' */

      /* Perform a microcontroller reset */
      ec_cpu_reset();

      /* End of Outputs for SubSystem: '<S231>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S231>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S236>/Action Port'
       */

      /* S-Function (ec55xx_cantransmitslb): '<S236>/CANTransmit' */

      /*Transmit CAN message*/
      {
        uint8 CAN2BUF9TX[1];
        uint8 can2buf9looptx= 0;
        CAN2BUF9TX[can2buf9looptx]= ((uint8_T)1U);
        can2buf9looptx++;
        FSAC2021_V1_B.CANTransmit= ec_can_transmit(2, 9, 0, 593U, 1, CAN2BUF9TX);
      }

      /* End of Outputs for SubSystem: '<S231>/If Action Subsystem1' */
    }

    /* End of If: '<S231>/If' */
  }

  FLEXCAN(2).IFRL.B.BUF01I = 1;        /* Clear CAN interrupt flag by writing it to 1 */
}

void ISR_FlexCAN_2_MB0(void)
{
  /* Call the system: <S229>/CCPReceive */
  {
    /* Output and update for function-call system: '<S229>/CCPReceive' */

    /* S-Function (ec55xx_canreceiveslb): '<S244>/CANReceive' */

    /* Receive CAN message */
    {
      uint8 CAN2BUF0RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

      uint8 can2buf0looprx= 0;
      FSAC2021_V1_B.CANReceive_o3= 256;
      FSAC2021_V1_B.CANReceive_o5= 8;
      FSAC2021_V1_B.CANReceive_o2= ec_can_receive(2,0, CAN2BUF0RX);
      FSAC2021_V1_B.CANReceive_o4[0]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      FSAC2021_V1_B.CANReceive_o4[1]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      FSAC2021_V1_B.CANReceive_o4[2]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      FSAC2021_V1_B.CANReceive_o4[3]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      FSAC2021_V1_B.CANReceive_o4[4]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      FSAC2021_V1_B.CANReceive_o4[5]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      FSAC2021_V1_B.CANReceive_o4[6]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      FSAC2021_V1_B.CANReceive_o4[7]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
    }

    /* Nothing to do for system: <S244>/Nothing */
  }

  FLEXCAN(2).IFRL.B.BUF00I = 1;        /* Clear CAN interrupt flag by writing it to 1 */
}

void ISR_FlexCAN_2_MB8(void)
{
  /* Call the system: <S229>/CCPTransmit */
  {
    /* Output and update for function-call system: '<S229>/CCPTransmit' */

    /* S-Function (ec55xx_ccpslb2): '<S245>/CCPTXConfirmation' */
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
void FSAC2021_V1_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(FSAC2021_V1_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(FSAC2021_V1_M, 2));
  eventFlags[3] = ((boolean_T)rtmStepTask(FSAC2021_V1_M, 3));
  eventFlags[4] = ((boolean_T)rtmStepTask(FSAC2021_V1_M, 4));
  eventFlags[5] = ((boolean_T)rtmStepTask(FSAC2021_V1_M, 5));
  eventFlags[6] = ((boolean_T)rtmStepTask(FSAC2021_V1_M, 6));
  eventFlags[7] = ((boolean_T)rtmStepTask(FSAC2021_V1_M, 7));
  eventFlags[8] = ((boolean_T)rtmStepTask(FSAC2021_V1_M, 8));
  eventFlags[9] = ((boolean_T)rtmStepTask(FSAC2021_V1_M, 9));
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
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 7 */
  if (FSAC2021_V1_M->Timing.TaskCounters.TID[1] == 0) {
    FSAC2021_V1_M->Timing.RateInteraction.TID1_7 =
      (FSAC2021_V1_M->Timing.TaskCounters.TID[7] == 0);
  }

  /* tid 3 shares data with slower tid rate: 7 */
  if (FSAC2021_V1_M->Timing.TaskCounters.TID[3] == 0) {
    FSAC2021_V1_M->Timing.RateInteraction.TID3_7 =
      (FSAC2021_V1_M->Timing.TaskCounters.TID[7] == 0);
  }

  /* tid 6 shares data with slower tid rate: 7 */
  if (FSAC2021_V1_M->Timing.TaskCounters.TID[6] == 0) {
    FSAC2021_V1_M->Timing.RateInteraction.TID6_7 =
      (FSAC2021_V1_M->Timing.TaskCounters.TID[7] == 0);
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (FSAC2021_V1_M->Timing.TaskCounters.TID[1])++;
  if ((FSAC2021_V1_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.001s, 0.0s] */
    FSAC2021_V1_M->Timing.TaskCounters.TID[1] = 0;
  }

  (FSAC2021_V1_M->Timing.TaskCounters.TID[2])++;
  if ((FSAC2021_V1_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.005s, 0.0s] */
    FSAC2021_V1_M->Timing.TaskCounters.TID[2] = 0;
  }

  (FSAC2021_V1_M->Timing.TaskCounters.TID[3])++;
  if ((FSAC2021_V1_M->Timing.TaskCounters.TID[3]) > 19) {/* Sample time: [0.01s, 0.0s] */
    FSAC2021_V1_M->Timing.TaskCounters.TID[3] = 0;
  }

  (FSAC2021_V1_M->Timing.TaskCounters.TID[4])++;
  if ((FSAC2021_V1_M->Timing.TaskCounters.TID[4]) > 39) {/* Sample time: [0.02s, 0.0s] */
    FSAC2021_V1_M->Timing.TaskCounters.TID[4] = 0;
  }

  (FSAC2021_V1_M->Timing.TaskCounters.TID[5])++;
  if ((FSAC2021_V1_M->Timing.TaskCounters.TID[5]) > 59) {/* Sample time: [0.03s, 0.0s] */
    FSAC2021_V1_M->Timing.TaskCounters.TID[5] = 0;
  }

  (FSAC2021_V1_M->Timing.TaskCounters.TID[6])++;
  if ((FSAC2021_V1_M->Timing.TaskCounters.TID[6]) > 99) {/* Sample time: [0.05s, 0.0s] */
    FSAC2021_V1_M->Timing.TaskCounters.TID[6] = 0;
  }

  (FSAC2021_V1_M->Timing.TaskCounters.TID[7])++;
  if ((FSAC2021_V1_M->Timing.TaskCounters.TID[7]) > 199) {/* Sample time: [0.1s, 0.0s] */
    FSAC2021_V1_M->Timing.TaskCounters.TID[7] = 0;
  }

  (FSAC2021_V1_M->Timing.TaskCounters.TID[8])++;
  if ((FSAC2021_V1_M->Timing.TaskCounters.TID[8]) > 399) {/* Sample time: [0.2s, 0.0s] */
    FSAC2021_V1_M->Timing.TaskCounters.TID[8] = 0;
  }

  (FSAC2021_V1_M->Timing.TaskCounters.TID[9])++;
  if ((FSAC2021_V1_M->Timing.TaskCounters.TID[9]) > 999) {/* Sample time: [0.5s, 0.0s] */
    FSAC2021_V1_M->Timing.TaskCounters.TID[9] = 0;
  }
}

/*
 * Initial conditions for atomic system:
 *    '<S210>/LPF'
 *    '<S210>/LPF1'
 *    '<S210>/LPF2'
 *    '<S210>/LPF3'
 */
void FSAC2021_V1_LPF_Init(DW_LPF_FSAC2021_V1_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S212>/Unit Delay' */
  localDW->UnitDelay_DSTATE = 1.0F;
}

/*
 * Output and update for atomic system:
 *    '<S210>/LPF'
 *    '<S210>/LPF1'
 *    '<S210>/LPF2'
 *    '<S210>/LPF3'
 */
void FSAC2021_V1_LPF(real32_T rtu_Filter, B_LPF_FSAC2021_V1_T *localB,
                     DW_LPF_FSAC2021_V1_T *localDW)
{
  /* Sum: '<S212>/Add1' incorporates:
   *  Constant: '<S212>/Constant'
   *  Product: '<S212>/Product'
   *  Sum: '<S212>/Add'
   *  UnitDelay: '<S212>/Unit Delay'
   */
  localB->Add1 = (rtu_Filter - localDW->UnitDelay_DSTATE) * 0.5F +
    localDW->UnitDelay_DSTATE;

  /* Update for UnitDelay: '<S212>/Unit Delay' */
  localDW->UnitDelay_DSTATE = localB->Add1;
}

real32_T rt_roundf_snf(real32_T u)
{
  real32_T y;
  if ((real32_T)fabs(u) < 8.388608E+6F) {
    if (u >= 0.5F) {
      y = (real32_T)floor(u + 0.5F);
    } else if (u > -0.5F) {
      y = u * 0.0F;
    } else {
      y = (real32_T)ceil(u - 0.5F);
    }
  } else {
    y = u;
  }

  return y;
}

/* Output and update for atomic system: '<S217>/Round' */
void FSAC2021_V1_Round(real32_T rtu_Origin_Precision)
{
  /* Gain: '<S222>/Gain2' incorporates:
   *  Gain: '<S222>/Gain1'
   */
  Vel_spd = (real32_T)(uint8_T)rt_roundf_snf(10.0F * rtu_Origin_Precision) *
    0.1F;
}

/*
 * Output and update for atomic system:
 *    '<S210>/Whl_Spd_Hz2RPM'
 *    '<S210>/Whl_Spd_Hz2RPM1'
 */
void FSAC2021_V1_Whl_Spd_Hz2RPM(uint32_T rtu_Whl_Spd_Hz,
  B_Whl_Spd_Hz2RPM_FSAC2021_V1_T *localB)
{
  /* Gain: '<S218>/rps2rpm' incorporates:
   *  Constant: '<S218>/Constant'
   *  Product: '<S218>/Divide'
   */
  localB->rps2rpm = (real32_T)rtu_Whl_Spd_Hz / 60.0F * 60.0F;
}

/*
 * Output and update for atomic system:
 *    '<S210>/Whl_Spd_Hz2RPM2'
 *    '<S210>/Whl_Spd_Hz2RPM3'
 */
void FSAC2021_V_Whl_Spd_Hz2RPM2(uint32_T rtu_Whl_Spd_Hz,
  B_Whl_Spd_Hz2RPM2_FSAC2021_V1_T *localB)
{
  /* Gain: '<S220>/rps2rpm' incorporates:
   *  Constant: '<S220>/Constant'
   *  Product: '<S220>/Divide'
   */
  localB->rps2rpm = (real32_T)rtu_Whl_Spd_Hz / 30.0F * 60.0F;
}

/* Output and update for function-call system: '<S11>/MOTEC_CONTROL' */
void FSAC2021_V1_MOTEC_CONTROL(real32_T rtu_Abs_or_Rel_Ctrl_in, real32_T
  rtu_Fault_Reset_in, real32_T rtu_Enable_Voltage_Ctrl_in, real32_T
  rtu_New_Pos_Set_in, real32_T rtu_Enable_Operation_Ctrl_in, real32_T
  rtu_Switch_On_Ctrl_in, real32_T rtu_Quick_Stop_Ctrl_in, real32_T
  rtu_Halt_Ctrl_in, real32_T rtu_Position_set_in, B_MOTEC_CONTROL_FSAC2021_V1_T *
  localB)
{
  uint32_T rtb_Position_set_L;
  real32_T rtb_Position_setRon;
  real32_T rtu_Enable_Voltage_Ctrl_in_0;
  real32_T rtu_New_Pos_Set_in_0;
  real32_T rtu_Enable_Operation_Ctrl_in_0;
  real32_T rtu_Abs_or_Rel_Ctrl_in_0;
  real32_T rtu_Switch_On_Ctrl_in_0;
  real32_T rtu_Quick_Stop_Ctrl_in_0;

  /* Saturate: '<S37>/Fault_Reset_sat' */
  if (rtu_Fault_Reset_in > 1.0F) {
    rtb_Position_setRon = 1.0F;
  } else if (rtu_Fault_Reset_in < 0.0F) {
    rtb_Position_setRon = 0.0F;
  } else {
    rtb_Position_setRon = rtu_Fault_Reset_in;
  }

  /* Saturate: '<S36>/Enable_Voltage_Ctrl_sat' */
  if (rtu_Enable_Voltage_Ctrl_in > 1.0F) {
    rtu_Enable_Voltage_Ctrl_in_0 = 1.0F;
  } else if (rtu_Enable_Voltage_Ctrl_in < 0.0F) {
    rtu_Enable_Voltage_Ctrl_in_0 = 0.0F;
  } else {
    rtu_Enable_Voltage_Ctrl_in_0 = rtu_Enable_Voltage_Ctrl_in;
  }

  /* Saturate: '<S39>/New_Pos_Set_sat' */
  if (rtu_New_Pos_Set_in > 1.0F) {
    rtu_New_Pos_Set_in_0 = 1.0F;
  } else if (rtu_New_Pos_Set_in < 0.0F) {
    rtu_New_Pos_Set_in_0 = 0.0F;
  } else {
    rtu_New_Pos_Set_in_0 = rtu_New_Pos_Set_in;
  }

  /* Saturate: '<S35>/Enable_Operation_Ctrl_sat' */
  if (rtu_Enable_Operation_Ctrl_in > 1.0F) {
    rtu_Enable_Operation_Ctrl_in_0 = 1.0F;
  } else if (rtu_Enable_Operation_Ctrl_in < 0.0F) {
    rtu_Enable_Operation_Ctrl_in_0 = 0.0F;
  } else {
    rtu_Enable_Operation_Ctrl_in_0 = rtu_Enable_Operation_Ctrl_in;
  }

  /* Saturate: '<S34>/Abs_or_Rel_Ctrl_sat' */
  if (rtu_Abs_or_Rel_Ctrl_in > 1.0F) {
    rtu_Abs_or_Rel_Ctrl_in_0 = 1.0F;
  } else if (rtu_Abs_or_Rel_Ctrl_in < 0.0F) {
    rtu_Abs_or_Rel_Ctrl_in_0 = 0.0F;
  } else {
    rtu_Abs_or_Rel_Ctrl_in_0 = rtu_Abs_or_Rel_Ctrl_in;
  }

  /* Saturate: '<S42>/Switch_On_Ctrl_sat' */
  if (rtu_Switch_On_Ctrl_in > 1.0F) {
    rtu_Switch_On_Ctrl_in_0 = 1.0F;
  } else if (rtu_Switch_On_Ctrl_in < 0.0F) {
    rtu_Switch_On_Ctrl_in_0 = 0.0F;
  } else {
    rtu_Switch_On_Ctrl_in_0 = rtu_Switch_On_Ctrl_in;
  }

  /* Saturate: '<S41>/Quick_Stop_Ctrl_sat' */
  if (rtu_Quick_Stop_Ctrl_in > 1.0F) {
    rtu_Quick_Stop_Ctrl_in_0 = 1.0F;
  } else if (rtu_Quick_Stop_Ctrl_in < 0.0F) {
    rtu_Quick_Stop_Ctrl_in_0 = 0.0F;
  } else {
    rtu_Quick_Stop_Ctrl_in_0 = rtu_Quick_Stop_Ctrl_in;
  }

  /* DataTypeConversion: '<S26>/Conv1' incorporates:
   *  ArithShift: '<S34>/Abs_or_Rel_Ctrl_S'
   *  ArithShift: '<S35>/Enable_Operation_Ctrl_S'
   *  ArithShift: '<S36>/Enable_Voltage_Ctrl_S'
   *  ArithShift: '<S37>/Fault_Reset_S'
   *  ArithShift: '<S39>/New_Pos_Set_S'
   *  ArithShift: '<S41>/Quick_Stop_Ctrl_S'
   *  DataTypeConversion: '<S34>/Abs_or_Rel_Ctrl_Convert'
   *  DataTypeConversion: '<S34>/Abs_or_Rel_Ctrl_Convert1'
   *  DataTypeConversion: '<S35>/Enable_Operation_Ctrl_Convert'
   *  DataTypeConversion: '<S35>/Enable_Operation_Ctrl_Convert1'
   *  DataTypeConversion: '<S36>/Enable_Voltage_Ctrl_Convert'
   *  DataTypeConversion: '<S36>/Enable_Voltage_Ctrl_Convert1'
   *  DataTypeConversion: '<S37>/Fault_Reset_Convert'
   *  DataTypeConversion: '<S37>/Fault_Reset_Convert1'
   *  DataTypeConversion: '<S39>/New_Pos_Set_Convert'
   *  DataTypeConversion: '<S39>/New_Pos_Set_Convert1'
   *  DataTypeConversion: '<S41>/Quick_Stop_Ctrl_Convert'
   *  DataTypeConversion: '<S41>/Quick_Stop_Ctrl_Convert1'
   *  DataTypeConversion: '<S42>/Switch_On_Ctrl_Convert'
   *  DataTypeConversion: '<S42>/Switch_On_Ctrl_Convert1'
   *  Rounding: '<S34>/Abs_or_Rel_CtrlRon'
   *  Rounding: '<S35>/Enable_Operation_CtrlRon'
   *  Rounding: '<S36>/Enable_Voltage_CtrlRon'
   *  Rounding: '<S37>/Fault_ResetRon'
   *  Rounding: '<S39>/New_Pos_SetRon'
   *  Rounding: '<S41>/Quick_Stop_CtrlRon'
   *  Rounding: '<S42>/Switch_On_CtrlRon'
   *  S-Function (sfix_bitop): '<S26>/or1'
   *  S-Function (sfix_bitop): '<S34>/Abs_or_Rel_Ctrl_L'
   *  S-Function (sfix_bitop): '<S35>/Enable_Operation_Ctrl_L'
   *  S-Function (sfix_bitop): '<S36>/Enable_Voltage_Ctrl_L'
   *  S-Function (sfix_bitop): '<S37>/Fault_Reset_L'
   *  S-Function (sfix_bitop): '<S39>/New_Pos_Set_L'
   *  S-Function (sfix_bitop): '<S41>/Quick_Stop_Ctrl_L'
   *  S-Function (sfix_bitop): '<S42>/Switch_On_Ctrl_L'
   *  Saturate: '<S34>/Abs_or_Rel_Ctrl_1sat'
   *  Saturate: '<S34>/Abs_or_Rel_Ctrl_sat'
   *  Saturate: '<S35>/Enable_Operation_Ctrl_1sat'
   *  Saturate: '<S35>/Enable_Operation_Ctrl_sat'
   *  Saturate: '<S36>/Enable_Voltage_Ctrl_1sat'
   *  Saturate: '<S36>/Enable_Voltage_Ctrl_sat'
   *  Saturate: '<S37>/Fault_Reset_1sat'
   *  Saturate: '<S37>/Fault_Reset_sat'
   *  Saturate: '<S39>/New_Pos_Set_1sat'
   *  Saturate: '<S39>/New_Pos_Set_sat'
   *  Saturate: '<S41>/Quick_Stop_Ctrl_1sat'
   *  Saturate: '<S41>/Quick_Stop_Ctrl_sat'
   *  Saturate: '<S42>/Switch_On_Ctrl_1sat'
   *  Saturate: '<S42>/Switch_On_Ctrl_sat'
   */
  localB->Conv1 = (uint8_T)((int32_T)((uint32_T)(real32_T)ldexp(rt_roundf_snf
    (rtb_Position_setRon), 7) & 128U) | (int32_T)((uint32_T)(real32_T)ldexp
    (rt_roundf_snf(rtu_Enable_Voltage_Ctrl_in_0), 1) & 2U) | (int32_T)((uint32_T)
                             (real32_T)ldexp(rt_roundf_snf(rtu_New_Pos_Set_in_0),
    4) & 16U) | (int32_T)((uint32_T)(real32_T)ldexp(rt_roundf_snf
    (rtu_Enable_Operation_Ctrl_in_0), 3) & 8U) | (int32_T)((uint32_T)(real32_T)
    ldexp(rt_roundf_snf(rtu_Abs_or_Rel_Ctrl_in_0), 6) & 64U) | (int32_T)
    ((uint32_T)rt_roundf_snf(rtu_Switch_On_Ctrl_in_0) & 1U) | (int32_T)
    ((uint32_T)(real32_T)ldexp(rt_roundf_snf(rtu_Quick_Stop_Ctrl_in_0), 2) & 4U));

  /* Saturate: '<S38>/Halt_Ctrl_sat' */
  if (rtu_Halt_Ctrl_in > 1.0F) {
    rtb_Position_setRon = 1.0F;
  } else if (rtu_Halt_Ctrl_in < 0.0F) {
    rtb_Position_setRon = 0.0F;
  } else {
    rtb_Position_setRon = rtu_Halt_Ctrl_in;
  }

  /* DataTypeConversion: '<S26>/Conv2' incorporates:
   *  DataTypeConversion: '<S38>/Halt_Ctrl_Convert'
   *  DataTypeConversion: '<S38>/Halt_Ctrl_Convert1'
   *  Rounding: '<S38>/Halt_CtrlRon'
   *  S-Function (sfix_bitop): '<S38>/Halt_Ctrl_L'
   *  Saturate: '<S38>/Halt_Ctrl_1sat'
   *  Saturate: '<S38>/Halt_Ctrl_sat'
   */
  localB->Conv2 = (uint8_T)((uint32_T)rt_roundf_snf(rtb_Position_setRon) & 1U);

  /* Saturate: '<S40>/Position_set_sat' */
  if (rtu_Position_set_in > 3.8654705E+6F) {
    rtb_Position_setRon = 3.8654705E+6F;
  } else if (rtu_Position_set_in < -3.8654705E+6F) {
    rtb_Position_setRon = -3.8654705E+6F;
  } else {
    rtb_Position_setRon = rtu_Position_set_in;
  }

  /* Rounding: '<S40>/Position_setRon' incorporates:
   *  Constant: '<S40>/Position_set_F'
   *  Product: '<S40>/Position_set_D'
   *  Saturate: '<S40>/Position_set_sat'
   */
  rtb_Position_setRon = rt_roundf_snf(rtb_Position_setRon / 0.00144F);

  /* Switch: '<S40>/Position_setSW' incorporates:
   *  Abs: '<S40>/Position_setABS'
   *  RelationalOperator: '<S40>/Position_setROP'
   *  Sum: '<S40>/Position_setsubcon'
   */
  if (rtb_Position_setRon < 0.0F) {
    rtb_Position_setRon = 4.2949673E+9F - (real32_T)fabs(rtb_Position_setRon);
  }

  /* End of Switch: '<S40>/Position_setSW' */

  /* Saturate: '<S40>/Position_set_1sat' */
  if (rtb_Position_setRon > 4.2949673E+9F) {
    rtb_Position_setRon = 4.2949673E+9F;
  }

  /* End of Saturate: '<S40>/Position_set_1sat' */

  /* S-Function (sfix_bitop): '<S40>/Position_set_L' incorporates:
   *  DataTypeConversion: '<S40>/Position_set_Convert'
   */
  rtb_Position_set_L = (uint32_T)rtb_Position_setRon;

  /* DataTypeConversion: '<S26>/Conv3' incorporates:
   *  Constant: '<S40>/Position_set_And2_C'
   *  DataTypeConversion: '<S40>/Position_setBitCov2'
   *  S-Function (sfix_bitop): '<S40>/Position_set_And2'
   */
  localB->Conv3 = (uint8_T)(rtb_Position_set_L & 255U);

  /* DataTypeConversion: '<S26>/Conv4' incorporates:
   *  Constant: '<S40>/Position_setoutput4_C'
   *  DataTypeConversion: '<S40>/Position_setCOV2'
   *  Product: '<S40>/Position_set_D3'
   *  S-Function (sfix_bitop): '<S40>/Position_set_And1'
   */
  localB->Conv4 = (uint8_T)((real_T)((int32_T)rtb_Position_set_L & 65535) /
    256.0);

  /* DataTypeConversion: '<S26>/Conv5' incorporates:
   *  Constant: '<S40>/Position_setoutput5_C'
   *  DataTypeConversion: '<S40>/Position_setCOV1'
   *  Product: '<S40>/Position_set_D2'
   *  S-Function (sfix_bitop): '<S40>/Position_set_And'
   */
  localB->Conv5 = (uint8_T)((real_T)((int32_T)rtb_Position_set_L & 16777215) /
    65536.0);

  /* DataTypeConversion: '<S26>/Conv6' incorporates:
   *  Constant: '<S40>/Position_setoutput6_C'
   *  DataTypeConversion: '<S40>/Position_setCOV'
   *  Product: '<S40>/Position_set_D1'
   */
  localB->Conv6 = (uint8_T)((real_T)rtb_Position_set_L / 1.6777216E+7);
}

/* Output and update for atomic system: '<S123>/Angle2Pulses' */
void FSAC2021_V1_Angle2Pulses(B_Angle2Pulses_FSAC2021_V1_T *localB,
  ConstB_Angle2Pulses_FSAC2021__T *localC)
{
  /* DataTypeConversion: '<S126>/Data Type Conversion' */
  localB->DataTypeConversion = (int16_T)floor(localC->Gain);
}

/* Output and update for atomic system: '<S124>/Angle2Pulses' */
void FSAC2021_V1_Angle2Pulses_p(int8_T rtu_Angle, B_Angle2Pulses_FSAC2021_V1_o_T
  *localB)
{
  /* DataTypeConversion: '<S127>/Data Type Conversion' incorporates:
   *  Gain: '<S127>/Angle2Circle'
   *  Gain: '<S127>/CircleTrans'
   *  Gain: '<S127>/Gain'
   */
  localB->DataTypeConversion = (int16_T)floor(0.00280761719F * (real32_T)
    rtu_Angle * 10.0 * 6400.0);
}

/* Output and update for atomic system: '<S125>/Angle2Pulses' */
void FSAC2021_V1_Angle2Pulses_b(real32_T rtu_Angle,
  B_Angle2Pulses_FSAC2021_V1_k_T *localB)
{
  /* DataTypeConversion: '<S128>/Data Type Conversion' incorporates:
   *  Gain: '<S128>/Angle2Circle'
   *  Gain: '<S128>/CircleTrans'
   *  Gain: '<S128>/Gain'
   */
  localB->DataTypeConversion = (int16_T)floor(0.0028F * rtu_Angle * 10.0 *
    6400.0);
}

/*
 * Enable for atomic system:
 *    '<S137>/Chart1'
 *    '<S137>/Chart2'
 *    '<S137>/Chart3'
 *    '<S137>/Chart4'
 *    '<S137>/Chart5'
 */
void FSAC2021_V1_Chart1_Enable(RT_MODEL_FSAC2021_V1_T * const FSAC2021_V1_M,
  DW_Chart1_FSAC2021_V1_T *localDW)
{
  localDW->presentTicks = FSAC2021_V1_M->Timing.clockTick7;
  localDW->previousTicks = localDW->presentTicks;
}

/*
 * Disable for atomic system:
 *    '<S137>/Chart1'
 *    '<S137>/Chart2'
 *    '<S137>/Chart3'
 *    '<S137>/Chart4'
 *    '<S137>/Chart5'
 */
void FSAC2021_V1_Chart1_Disable(RT_MODEL_FSAC2021_V1_T * const FSAC2021_V1_M,
  DW_Chart1_FSAC2021_V1_T *localDW)
{
  localDW->presentTicks = FSAC2021_V1_M->Timing.clockTick7;
  localDW->elapsedTicks = localDW->presentTicks - localDW->previousTicks;
  localDW->previousTicks = localDW->presentTicks;
  if (localDW->temporalCounter_i1 + localDW->elapsedTicks <= 7U) {
    localDW->temporalCounter_i1 = (uint8_T)(localDW->temporalCounter_i1 +
      localDW->elapsedTicks);
  } else {
    localDW->temporalCounter_i1 = 7U;
  }
}

/*
 * Output and update for atomic system:
 *    '<S137>/Chart1'
 *    '<S137>/Chart2'
 *    '<S137>/Chart3'
 *    '<S137>/Chart4'
 *    '<S137>/Chart5'
 */
void FSAC2021_V1_Chart1(RT_MODEL_FSAC2021_V1_T * const FSAC2021_V1_M, uint8_T
  rtu_Input, B_Chart1_FSAC2021_V1_T *localB, DW_Chart1_FSAC2021_V1_T *localDW)
{
  localDW->presentTicks = FSAC2021_V1_M->Timing.clockTick7;
  localDW->elapsedTicks = localDW->presentTicks - localDW->previousTicks;
  localDW->previousTicks = localDW->presentTicks;
  if (localDW->temporalCounter_i1 + localDW->elapsedTicks <= 7U) {
    localDW->temporalCounter_i1 = (uint8_T)(localDW->temporalCounter_i1 +
      localDW->elapsedTicks);
  } else {
    localDW->temporalCounter_i1 = 7U;
  }

  /* Gateway: DIAG/DIAG/Analog_Sensor_Diag/Chart1 */
  /* During: DIAG/DIAG/Analog_Sensor_Diag/Chart1 */
  if (localDW->bitsForTID7.is_active_c18_FSAC2021_V1 == 0U) {
    /* Entry: DIAG/DIAG/Analog_Sensor_Diag/Chart1 */
    localDW->bitsForTID7.is_active_c18_FSAC2021_V1 = 1U;

    /* Entry Internal: DIAG/DIAG/Analog_Sensor_Diag/Chart1 */
    /* Transition: '<S149>:21' */
    localDW->bitsForTID7.is_c18_FSAC2021_V1 = FSAC2021_V1_IN_Normal;

    /* Entry 'Normal': '<S149>:13' */
    localB->Output = 0U;
  } else {
    switch (localDW->bitsForTID7.is_c18_FSAC2021_V1) {
     case FSAC2021_V1_IN_Normal:
      /* During 'Normal': '<S149>:13' */
      if (rtu_Input == 1) {
        /* Transition: '<S149>:16' */
        localDW->bitsForTID7.is_c18_FSAC2021_V1 = FSAC2021_V1_IN_ON;
        localDW->temporalCounter_i1 = 0U;
      }
      break;

     case FSAC2021_V1_IN_ON:
      /* During 'ON': '<S149>:14' */
      if (rtu_Input == 0) {
        /* Transition: '<S149>:17' */
        localDW->bitsForTID7.is_c18_FSAC2021_V1 = FSAC2021_V1_IN_Off;
      } else {
        if (localDW->temporalCounter_i1 >= 5U) {
          /* Transition: '<S149>:20' */
          localDW->bitsForTID7.is_c18_FSAC2021_V1 = FSAC2021_V1_IN_On;

          /* Entry 'On': '<S149>:15' */
          localB->Output = 1U;
        }
      }
      break;

     case FSAC2021_V1_IN_Off:
      /* During 'Off': '<S149>:12' */
      if (rtu_Input == 1) {
        /* Transition: '<S149>:19' */
        localDW->bitsForTID7.is_c18_FSAC2021_V1 = FSAC2021_V1_IN_ON;
        localDW->temporalCounter_i1 = 0U;
      }
      break;

     default:
      /* During 'On': '<S149>:15' */
      break;
    }
  }
}

/* Enable for atomic system: '<S169>/Chart4' */
void FSAC2021_V1_Chart4_Enable(RT_MODEL_FSAC2021_V1_T * const FSAC2021_V1_M,
  DW_Chart4_FSAC2021_V1_T *localDW)
{
  localDW->presentTicks = FSAC2021_V1_M->Timing.clockTick7;
  localDW->previousTicks = localDW->presentTicks;
}

/* Disable for atomic system: '<S169>/Chart4' */
void FSAC2021_V1_Chart4_Disable(RT_MODEL_FSAC2021_V1_T * const FSAC2021_V1_M,
  DW_Chart4_FSAC2021_V1_T *localDW)
{
  localDW->presentTicks = FSAC2021_V1_M->Timing.clockTick7;
  localDW->elapsedTicks = localDW->presentTicks - localDW->previousTicks;
  localDW->previousTicks = localDW->presentTicks;
  if (localDW->temporalCounter_i1 + localDW->elapsedTicks <= 31U) {
    localDW->temporalCounter_i1 = (uint8_T)(localDW->temporalCounter_i1 +
      localDW->elapsedTicks);
  } else {
    localDW->temporalCounter_i1 = 31U;
  }
}

/* Output and update for atomic system: '<S169>/Chart4' */
void FSAC2021_V1_Chart4(RT_MODEL_FSAC2021_V1_T * const FSAC2021_V1_M, uint8_T
  rtu_Input, DW_Chart4_FSAC2021_V1_T *localDW)
{
  localDW->presentTicks = FSAC2021_V1_M->Timing.clockTick7;
  localDW->elapsedTicks = localDW->presentTicks - localDW->previousTicks;
  localDW->previousTicks = localDW->presentTicks;
  if (localDW->temporalCounter_i1 + localDW->elapsedTicks <= 31U) {
    localDW->temporalCounter_i1 = (uint8_T)(localDW->temporalCounter_i1 +
      localDW->elapsedTicks);
  } else {
    localDW->temporalCounter_i1 = 31U;
  }

  /* Gateway: DIAG/DIAG/CAN_NODE_LOSTCOM/Subsystem/Chart4 */
  /* During: DIAG/DIAG/CAN_NODE_LOSTCOM/Subsystem/Chart4 */
  if (localDW->bitsForTID7.is_active_c11_FSAC2021_V1 == 0U) {
    /* Entry: DIAG/DIAG/CAN_NODE_LOSTCOM/Subsystem/Chart4 */
    localDW->bitsForTID7.is_active_c11_FSAC2021_V1 = 1U;

    /* Entry Internal: DIAG/DIAG/CAN_NODE_LOSTCOM/Subsystem/Chart4 */
    /* Transition: '<S175>:21' */
    localDW->bitsForTID7.is_c11_FSAC2021_V1 = FSAC2021_V1_IN_Normal_h;

    /* Entry 'Normal': '<S175>:13' */
    motor = 1U;
  } else {
    switch (localDW->bitsForTID7.is_c11_FSAC2021_V1) {
     case FSAC2021_V1_IN_Normal_h:
      /* During 'Normal': '<S175>:13' */
      if (rtu_Input == 0) {
        /* Transition: '<S175>:16' */
        localDW->bitsForTID7.is_c11_FSAC2021_V1 = FSAC2021_V1_IN_ON_j;
        localDW->temporalCounter_i1 = 0U;
      }
      break;

     case FSAC2021_V1_IN_ON_j:
      /* During 'ON': '<S175>:14' */
      if (rtu_Input == 1) {
        /* Transition: '<S175>:17' */
        localDW->bitsForTID7.is_c11_FSAC2021_V1 = FSAC2021_V1_IN_Off_g;
      } else {
        if (localDW->temporalCounter_i1 >= 20U) {
          /* Transition: '<S175>:20' */
          localDW->bitsForTID7.is_c11_FSAC2021_V1 = FSAC2021_V1_IN_On_a;

          /* Entry 'On': '<S175>:15' */
          motor = 0U;
        }
      }
      break;

     case FSAC2021_V1_IN_Off_g:
      /* During 'Off': '<S175>:12' */
      if (rtu_Input == 0) {
        /* Transition: '<S175>:19' */
        localDW->bitsForTID7.is_c11_FSAC2021_V1 = FSAC2021_V1_IN_ON_j;
        localDW->temporalCounter_i1 = 0U;
      }
      break;

     default:
      /* During 'On': '<S175>:15' */
      break;
    }
  }
}

/* Enable for atomic system: '<S183>/Chart1' */
void FSAC2021_V_Chart1_n_Enable(RT_MODEL_FSAC2021_V1_T * const FSAC2021_V1_M,
  DW_Chart1_FSAC2021_V1_o_T *localDW)
{
  localDW->presentTicks = FSAC2021_V1_M->Timing.clockTick7;
  localDW->previousTicks = localDW->presentTicks;
}

/* Disable for atomic system: '<S183>/Chart1' */
void FSAC2021__Chart1_n_Disable(RT_MODEL_FSAC2021_V1_T * const FSAC2021_V1_M,
  DW_Chart1_FSAC2021_V1_o_T *localDW)
{
  localDW->presentTicks = FSAC2021_V1_M->Timing.clockTick7;
  localDW->elapsedTicks = localDW->presentTicks - localDW->previousTicks;
  localDW->previousTicks = localDW->presentTicks;
  if (localDW->temporalCounter_i1 + localDW->elapsedTicks <= 31U) {
    localDW->temporalCounter_i1 = (uint8_T)(localDW->temporalCounter_i1 +
      localDW->elapsedTicks);
  } else {
    localDW->temporalCounter_i1 = 31U;
  }
}

/* Output and update for atomic system: '<S183>/Chart1' */
void FSAC2021_V1_Chart1_b(RT_MODEL_FSAC2021_V1_T * const FSAC2021_V1_M, real_T
  rtu_Input, B_Chart1_FSAC2021_V1_e_T *localB, DW_Chart1_FSAC2021_V1_o_T
  *localDW)
{
  localDW->presentTicks = FSAC2021_V1_M->Timing.clockTick7;
  localDW->elapsedTicks = localDW->presentTicks - localDW->previousTicks;
  localDW->previousTicks = localDW->presentTicks;
  if (localDW->temporalCounter_i1 + localDW->elapsedTicks <= 31U) {
    localDW->temporalCounter_i1 = (uint8_T)(localDW->temporalCounter_i1 +
      localDW->elapsedTicks);
  } else {
    localDW->temporalCounter_i1 = 31U;
  }

  /* Gateway: DIAG/DIAG/Res_Diag/Subsystem/Chart1 */
  /* During: DIAG/DIAG/Res_Diag/Subsystem/Chart1 */
  if (localDW->bitsForTID7.is_active_c1_FSAC2021_V1 == 0U) {
    /* Entry: DIAG/DIAG/Res_Diag/Subsystem/Chart1 */
    localDW->bitsForTID7.is_active_c1_FSAC2021_V1 = 1U;

    /* Entry Internal: DIAG/DIAG/Res_Diag/Subsystem/Chart1 */
    /* Transition: '<S184>:21' */
    localDW->bitsForTID7.is_c1_FSAC2021_V1 = FSAC2021_V1_IN_Normal_a;

    /* Entry 'Normal': '<S184>:13' */
    localB->Output = 0U;
  } else {
    switch (localDW->bitsForTID7.is_c1_FSAC2021_V1) {
     case FSAC2021_V1_IN_Normal_a:
      /* During 'Normal': '<S184>:13' */
      if (rtu_Input == 1.0) {
        /* Transition: '<S184>:16' */
        localDW->bitsForTID7.is_c1_FSAC2021_V1 = FSAC2021_V1_IN_ON_h;
        localDW->temporalCounter_i1 = 0U;
      }
      break;

     case FSAC2021_V1_IN_ON_h:
      /* During 'ON': '<S184>:14' */
      if (rtu_Input == 0.0) {
        /* Transition: '<S184>:17' */
        localDW->bitsForTID7.is_c1_FSAC2021_V1 = FSAC2021_V1_IN_Off_a;
      } else {
        if (localDW->temporalCounter_i1 >= 20U) {
          /* Transition: '<S184>:20' */
          localDW->bitsForTID7.is_c1_FSAC2021_V1 = FSAC2021_V1_IN_On_b;

          /* Entry 'On': '<S184>:15' */
          localB->Output = 1U;
        }
      }
      break;

     case FSAC2021_V1_IN_Off_a:
      /* During 'Off': '<S184>:12' */
      if (rtu_Input == 1.0) {
        /* Transition: '<S184>:19' */
        localDW->bitsForTID7.is_c1_FSAC2021_V1 = FSAC2021_V1_IN_ON_h;
        localDW->temporalCounter_i1 = 0U;
      }
      break;

     default:
      /* During 'On': '<S184>:15' */
      break;
    }
  }
}

/*
 * Output and update for enable system:
 *    '<S144>/Subsystem'
 *    '<S144>/Subsystem1'
 *    '<S144>/Subsystem2'
 */
void FSAC2021_V1_Subsystem(boolean_T rtu_Enable, real32_T rtu_Compare_Volt_mv,
  boolean_T *rty_TS_Error)
{
  /* Outputs for Enabled SubSystem: '<S144>/Subsystem' incorporates:
   *  EnablePort: '<S191>/Enable'
   */
  if (rtu_Enable) {
    /* RelationalOperator: '<S194>/Compare' incorporates:
     *  Constant: '<S194>/Constant'
     */
    *rty_TS_Error = (rtu_Compare_Volt_mv < 2.0F);
  }

  /* End of Outputs for SubSystem: '<S144>/Subsystem' */
}

/*
 * Output and update for action system:
 *    '<S68>/ON'
 *    '<S69>/ON'
 *    '<S70>/off'
 */
void FSAC2021_V1_ON(uint8_T *rty_Out1)
{
  /* SignalConversion: '<S74>/OutportBufferForOut1' incorporates:
   *  Constant: '<S74>/Constant'
   */
  *rty_Out1 = 0U;
}

/*
 * Output and update for action system:
 *    '<S68>/OFF'
 *    '<S69>/OFF'
 */
void FSAC2021_V1_OFF(uint8_T *rty_Out1)
{
  /* SignalConversion: '<S73>/OutportBufferForOut1' incorporates:
   *  Constant: '<S73>/Constant'
   */
  *rty_Out1 = 1U;
}

/*
 * Output and update for action system:
 *    '<S68>/BLINK '
 *    '<S69>/BLINK'
 */
void FSAC2021_V1_BLINK(uint8_T *rty_Out1, DW_BLINK_FSAC2021_V1_T *localDW)
{
  uint8_T rtb_DataTypeConversion_k;

  /* DataTypeConversion: '<S72>/Data Type Conversion' incorporates:
   *  Logic: '<S72>/Logical Operator'
   *  UnitDelay: '<S72>/Unit Delay'
   */
  rtb_DataTypeConversion_k = (uint8_T)!(localDW->UnitDelay_DSTATE != 0);

  /* SignalConversion: '<S72>/OutportBufferForOut1' */
  *rty_Out1 = rtb_DataTypeConversion_k;

  /* Update for UnitDelay: '<S72>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rtb_DataTypeConversion_k;
}

/* Output and update for atomic system: '<S64>/Light_Subsystem' */
void FSAC2021_V_Light_Subsystem(uint8_T rtu_Light_Status,
  DW_Light_Subsystem_FSAC2021_V_T *localDW)
{
  /* local block i/o variables */
  uint8_T rtb_Merge;

  /* If: '<S68>/If' */
  if (rtu_Light_Status == 0) {
    /* Outputs for IfAction SubSystem: '<S68>/ON' incorporates:
     *  ActionPort: '<S74>/Action Port'
     */
    FSAC2021_V1_ON(&rtb_Merge);

    /* End of Outputs for SubSystem: '<S68>/ON' */
  } else if (rtu_Light_Status == 1) {
    /* Outputs for IfAction SubSystem: '<S68>/OFF' incorporates:
     *  ActionPort: '<S73>/Action Port'
     */
    FSAC2021_V1_OFF(&rtb_Merge);

    /* End of Outputs for SubSystem: '<S68>/OFF' */
  } else {
    /* Outputs for IfAction SubSystem: '<S68>/BLINK ' incorporates:
     *  ActionPort: '<S72>/Action Port'
     */
    FSAC2021_V1_BLINK(&rtb_Merge, &localDW->BLINK);

    /* End of Outputs for SubSystem: '<S68>/BLINK ' */
  }

  /* End of If: '<S68>/If' */

  /* DataTypeConversion: '<S68>/Data Type Conversion' */
  blue = rtb_Merge;
}

/* Output and update for atomic system: '<S64>/Light_Subsystem1' */
void FSAC2021__Light_Subsystem1(uint8_T rtu_Light_Status,
  B_Light_Subsystem1_FSAC2021_V_T *localB, DW_Light_Subsystem1_FSAC2021__T
  *localDW)
{
  /* local block i/o variables */
  uint8_T rtb_Merge_c;

  /* If: '<S69>/If' */
  if (rtu_Light_Status == 0) {
    /* Outputs for IfAction SubSystem: '<S69>/ON' incorporates:
     *  ActionPort: '<S77>/Action Port'
     */
    FSAC2021_V1_ON(&rtb_Merge_c);

    /* End of Outputs for SubSystem: '<S69>/ON' */
  } else if (rtu_Light_Status == 1) {
    /* Outputs for IfAction SubSystem: '<S69>/OFF' incorporates:
     *  ActionPort: '<S76>/Action Port'
     */
    FSAC2021_V1_OFF(&rtb_Merge_c);

    /* End of Outputs for SubSystem: '<S69>/OFF' */
  } else {
    /* Outputs for IfAction SubSystem: '<S69>/BLINK' incorporates:
     *  ActionPort: '<S75>/Action Port'
     */
    FSAC2021_V1_BLINK(&rtb_Merge_c, &localDW->BLINK);

    /* End of Outputs for SubSystem: '<S69>/BLINK' */
  }

  /* End of If: '<S69>/If' */

  /* DataTypeConversion: '<S69>/Data Type Conversion' */
  localB->DataTypeConversion = rtb_Merge_c;
}

/* Disable for atomic system: '<S64>/Light_Subsystem2' */
void F_Light_Subsystem2_Disable(RT_MODEL_FSAC2021_V1_T * const FSAC2021_V1_M,
  DW_Light_Subsystem2_FSAC2021__T *localDW)
{
  /* Disable for If: '<S70>/If' */
  switch (localDW->If_ActiveSubsystem) {
   case 0:
    break;

   case 1:
    /* Disable for Chart: '<S79>/Chart' */
    localDW->presentTicks_p = FSAC2021_V1_M->Timing.clockTick8;
    localDW->elapsedTicks_n = localDW->presentTicks_p - localDW->previousTicks_j;
    localDW->previousTicks_j = localDW->presentTicks_p;
    if (localDW->temporalCounter_i1_n + localDW->elapsedTicks_n <= 15U) {
      localDW->temporalCounter_i1_n = (uint8_T)(localDW->temporalCounter_i1_n +
        localDW->elapsedTicks_n);
    } else {
      localDW->temporalCounter_i1_n = 15U;
    }

    /* End of Disable for Chart: '<S79>/Chart' */
    break;

   case 2:
    /* Disable for Chart: '<S78>/Chart' */
    localDW->presentTicks = FSAC2021_V1_M->Timing.clockTick8;
    localDW->elapsedTicks = localDW->presentTicks - localDW->previousTicks;
    localDW->previousTicks = localDW->presentTicks;
    if (localDW->temporalCounter_i1 + localDW->elapsedTicks <= 3U) {
      localDW->temporalCounter_i1 = (uint8_T)(localDW->temporalCounter_i1 +
        localDW->elapsedTicks);
    } else {
      localDW->temporalCounter_i1 = 3U;
    }

    if (localDW->temporalCounter_i2 + localDW->elapsedTicks <= 63U) {
      localDW->temporalCounter_i2 = (uint8_T)(localDW->temporalCounter_i2 +
        localDW->elapsedTicks);
    } else {
      localDW->temporalCounter_i2 = 63U;
    }

    /* End of Disable for Chart: '<S78>/Chart' */
    break;
  }

  localDW->If_ActiveSubsystem = -1;

  /* End of Disable for If: '<S70>/If' */
}

/* Start for atomic system: '<S64>/Light_Subsystem2' */
void FSA_Light_Subsystem2_Start(DW_Light_Subsystem2_FSAC2021__T *localDW)
{
  /* Start for If: '<S70>/If' */
  localDW->If_ActiveSubsystem = -1;
}

/* Output and update for atomic system: '<S64>/Light_Subsystem2' */
void FSAC2021__Light_Subsystem2(RT_MODEL_FSAC2021_V1_T * const FSAC2021_V1_M,
  uint8_T rtu_Buzzer_Flag, B_Light_Subsystem2_FSAC2021_V_T *localB,
  DW_Light_Subsystem2_FSAC2021__T *localDW)
{
  /* local block i/o variables */
  uint8_T rtb_Merge_l;
  int8_T rtPrevAction;
  int8_T rtAction;

  /* If: '<S70>/If' */
  rtPrevAction = localDW->If_ActiveSubsystem;
  if (rtu_Buzzer_Flag == 0) {
    rtAction = 0;
  } else if (rtu_Buzzer_Flag == 1) {
    rtAction = 1;
  } else {
    rtAction = 2;
  }

  localDW->If_ActiveSubsystem = rtAction;
  if (rtPrevAction != rtAction) {
    switch (rtPrevAction) {
     case 0:
      break;

     case 1:
      /* Disable for Chart: '<S79>/Chart' */
      localDW->presentTicks_p = FSAC2021_V1_M->Timing.clockTick8;
      localDW->elapsedTicks_n = localDW->presentTicks_p -
        localDW->previousTicks_j;
      localDW->previousTicks_j = localDW->presentTicks_p;
      if (localDW->temporalCounter_i1_n + localDW->elapsedTicks_n <= 15U) {
        localDW->temporalCounter_i1_n = (uint8_T)(localDW->temporalCounter_i1_n
          + localDW->elapsedTicks_n);
      } else {
        localDW->temporalCounter_i1_n = 15U;
      }

      /* End of Disable for Chart: '<S79>/Chart' */
      break;

     case 2:
      /* Disable for Chart: '<S78>/Chart' */
      localDW->presentTicks = FSAC2021_V1_M->Timing.clockTick8;
      localDW->elapsedTicks = localDW->presentTicks - localDW->previousTicks;
      localDW->previousTicks = localDW->presentTicks;
      if (localDW->temporalCounter_i1 + localDW->elapsedTicks <= 3U) {
        localDW->temporalCounter_i1 = (uint8_T)(localDW->temporalCounter_i1 +
          localDW->elapsedTicks);
      } else {
        localDW->temporalCounter_i1 = 3U;
      }

      if (localDW->temporalCounter_i2 + localDW->elapsedTicks <= 63U) {
        localDW->temporalCounter_i2 = (uint8_T)(localDW->temporalCounter_i2 +
          localDW->elapsedTicks);
      } else {
        localDW->temporalCounter_i2 = 63U;
      }

      /* End of Disable for Chart: '<S78>/Chart' */
      break;
    }
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S70>/off' incorporates:
     *  ActionPort: '<S80>/Action Port'
     */
    FSAC2021_V1_ON(&rtb_Merge_l);

    /* End of Outputs for SubSystem: '<S70>/off' */
    break;

   case 1:
    if (rtAction != rtPrevAction) {
      /* Enable for IfAction SubSystem: '<S70>/Start_Horn' incorporates:
       *  Enable for ActionPort: '<S79>/Action Port'
       */
      /* Enable for If: '<S70>/If' incorporates:
       *  Enable for Chart: '<S79>/Chart'
       */
      localDW->presentTicks_p = FSAC2021_V1_M->Timing.clockTick8;
      localDW->previousTicks_j = localDW->presentTicks_p;

      /* End of Enable for SubSystem: '<S70>/Start_Horn' */
    }

    /* Outputs for IfAction SubSystem: '<S70>/Start_Horn' incorporates:
     *  ActionPort: '<S79>/Action Port'
     */
    /* Chart: '<S79>/Chart' */
    localDW->presentTicks_p = FSAC2021_V1_M->Timing.clockTick8;
    localDW->elapsedTicks_n = localDW->presentTicks_p - localDW->previousTicks_j;
    localDW->previousTicks_j = localDW->presentTicks_p;
    if (localDW->temporalCounter_i1_n + localDW->elapsedTicks_n <= 15U) {
      localDW->temporalCounter_i1_n = (uint8_T)(localDW->temporalCounter_i1_n +
        localDW->elapsedTicks_n);
    } else {
      localDW->temporalCounter_i1_n = 15U;
    }

    /* Gateway: Controller/200ms_Duty/Light_Subsystem2/Start_Horn/Chart */
    /* During: Controller/200ms_Duty/Light_Subsystem2/Start_Horn/Chart */
    if (localDW->bitsForTID8.is_active_c7_FSAC2021_V1 == 0U) {
      /* Entry: Controller/200ms_Duty/Light_Subsystem2/Start_Horn/Chart */
      localDW->bitsForTID8.is_active_c7_FSAC2021_V1 = 1U;

      /* Entry Internal: Controller/200ms_Duty/Light_Subsystem2/Start_Horn/Chart */
      /* Transition: '<S82>:2' */
      localDW->bitsForTID8.is_c7_FSAC2021_V1 = FSAC2021_V1_IN_Start_Horn_ON;
      localDW->temporalCounter_i1_n = 0U;

      /* Entry 'Start_Horn_ON': '<S82>:3' */
      localB->Buzzer_Pin_o = 1U;
    } else if ((localDW->bitsForTID8.is_c7_FSAC2021_V1 !=
                FSAC2021_V1_IN_Start_Horn_OFF) && (localDW->temporalCounter_i1_n
                >= 10U)) {
      /* During 'Start_Horn_ON': '<S82>:3' */
      /* Transition: '<S82>:8' */
      localDW->bitsForTID8.is_c7_FSAC2021_V1 = FSAC2021_V1_IN_Start_Horn_OFF;

      /* Entry 'Start_Horn_OFF': '<S82>:1' */
      localB->Buzzer_Pin_o = 0U;
    } else {
      /* During 'Start_Horn_OFF': '<S82>:1' */
    }

    /* End of Chart: '<S79>/Chart' */

    /* SignalConversion: '<S79>/OutportBufferForOut1' */
    rtb_Merge_l = localB->Buzzer_Pin_o;

    /* End of Outputs for SubSystem: '<S70>/Start_Horn' */
    break;

   case 2:
    if (rtAction != rtPrevAction) {
      /* Enable for IfAction SubSystem: '<S70>/EBS_Horn' incorporates:
       *  Enable for ActionPort: '<S78>/Action Port'
       */
      /* Enable for If: '<S70>/If' incorporates:
       *  Enable for Chart: '<S78>/Chart'
       */
      localDW->presentTicks = FSAC2021_V1_M->Timing.clockTick8;
      localDW->previousTicks = localDW->presentTicks;

      /* End of Enable for SubSystem: '<S70>/EBS_Horn' */
    }

    /* Outputs for IfAction SubSystem: '<S70>/EBS_Horn' incorporates:
     *  ActionPort: '<S78>/Action Port'
     */
    /* Chart: '<S78>/Chart' */
    localDW->presentTicks = FSAC2021_V1_M->Timing.clockTick8;
    localDW->elapsedTicks = localDW->presentTicks - localDW->previousTicks;
    localDW->previousTicks = localDW->presentTicks;
    if (localDW->temporalCounter_i1 + localDW->elapsedTicks <= 3U) {
      localDW->temporalCounter_i1 = (uint8_T)(localDW->temporalCounter_i1 +
        localDW->elapsedTicks);
    } else {
      localDW->temporalCounter_i1 = 3U;
    }

    if (localDW->temporalCounter_i2 + localDW->elapsedTicks <= 63U) {
      localDW->temporalCounter_i2 = (uint8_T)(localDW->temporalCounter_i2 +
        localDW->elapsedTicks);
    } else {
      localDW->temporalCounter_i2 = 63U;
    }

    /* Gateway: Controller/200ms_Duty/Light_Subsystem2/EBS_Horn/Chart */
    /* During: Controller/200ms_Duty/Light_Subsystem2/EBS_Horn/Chart */
    if (localDW->bitsForTID8.is_active_c8_FSAC2021_V1 == 0U) {
      /* Entry: Controller/200ms_Duty/Light_Subsystem2/EBS_Horn/Chart */
      localDW->bitsForTID8.is_active_c8_FSAC2021_V1 = 1U;

      /* Entry Internal: Controller/200ms_Duty/Light_Subsystem2/EBS_Horn/Chart */
      /* Transition: '<S81>:16' */
      localDW->bitsForTID8.is_c8_FSAC2021_V1 = FSAC2021_V1_IN_Horn;
      localDW->temporalCounter_i2 = 0U;

      /* Entry Internal 'Horn': '<S81>:14' */
      /* Transition: '<S81>:2' */
      localDW->bitsForTID8.is_Horn = FSAC2021_V1_IN_EBS_Horn_ON;
      localDW->temporalCounter_i1 = 0U;

      /* Entry 'EBS_Horn_ON': '<S81>:3' */
      localB->Buzzer_Pin = 1U;
    } else if (localDW->bitsForTID8.is_c8_FSAC2021_V1 !=
               FSAC2021_V1_IN_EBS_Horn_OFF) {
      /* During 'Horn': '<S81>:14' */
      if (localDW->temporalCounter_i2 >= 45U) {
        /* Transition: '<S81>:15' */
        /* Exit Internal 'Horn': '<S81>:14' */
        localDW->bitsForTID8.is_Horn = FSAC2021_V_IN_NO_ACTIVE_CHILD_n;
        localDW->bitsForTID8.is_c8_FSAC2021_V1 = FSAC2021_V1_IN_EBS_Horn_OFF;

        /* Entry 'EBS_Horn_OFF': '<S81>:1' */
        localB->Buzzer_Pin = 0U;
        localB->Buzzer_Overflag = 1U;
      } else if (localDW->bitsForTID8.is_Horn == FSAC2021_V1_IN_EBS_Horn_ON) {
        /* During 'EBS_Horn_ON': '<S81>:3' */
        if (localDW->temporalCounter_i1 >= 1U) {
          /* Transition: '<S81>:12' */
          localDW->bitsForTID8.is_Horn = FSAC2021_V1_IN_EBS_Horn_ON1;
          localDW->temporalCounter_i1 = 0U;

          /* Entry 'EBS_Horn_ON1': '<S81>:11' */
          localB->Buzzer_Pin = 0U;
        }
      } else {
        /* During 'EBS_Horn_ON1': '<S81>:11' */
        if (localDW->temporalCounter_i1 >= 1U) {
          /* Transition: '<S81>:13' */
          localDW->bitsForTID8.is_Horn = FSAC2021_V1_IN_EBS_Horn_ON;
          localDW->temporalCounter_i1 = 0U;

          /* Entry 'EBS_Horn_ON': '<S81>:3' */
          localB->Buzzer_Pin = 1U;
        }
      }
    } else {
      /* During 'EBS_Horn_OFF': '<S81>:1' */
    }

    /* End of Chart: '<S78>/Chart' */

    /* SignalConversion: '<S78>/OutportBufferForBuzzer_Pin' */
    rtb_Merge_l = localB->Buzzer_Pin;

    /* End of Outputs for SubSystem: '<S70>/EBS_Horn' */
    break;
  }

  /* End of If: '<S70>/If' */

  /* DataTypeConversion: '<S70>/Data Type Conversion' */
  localB->DataTypeConversion = rtb_Merge_l;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function for TID0 */
void FSAC2021_V1_step0(void)           /* Sample time: [0.0005s, 0.0s] */
{
  {                                    /* Sample time: [0.0005s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void FSAC2021_V1_step1(void)           /* Sample time: [0.001s, 0.0s] */
{
  /* RateTransition: '<S3>/RateTransition22' */
  if (FSAC2021_V1_M->Timing.RateInteraction.TID1_7) {
    FSAC2021_V1_B.RateTransition22 = 0.0;
  }

  /* End of RateTransition: '<S3>/RateTransition22' */
  /* S-Function (fcncallgen): '<S229>/Function-Call Generator' incorporates:
   *  SubSystem: '<S229>/CCPBackground'
   */

  /* S-Function (ec55xx_ccpslb): '<S243>/CCPBackground' */
  ccpBackground();
}

/* Model step function for TID2 */
void FSAC2021_V1_step2(void)           /* Sample time: [0.005s, 0.0s] */
{
  /* S-Function (fcncallgen): '<S226>/5ms' incorporates:
   *  SubSystem: '<S226>/daq5ms'
   */

  /* S-Function (ec55xx_ccpslb1): '<S240>/CCPDAQ' */
  ccpDaq(0);
}

/* Model step function for TID3 */
void FSAC2021_V1_step3(void)           /* Sample time: [0.01s, 0.0s] */
{
  uint8_T rtb_RateTransition41;
  uint8_T DataTypeConversion16;

  /* UnitDelay: '<S2>/Unit Delay8' */
  FSAC2021_V1_B.UnitDelay8_f = FSAC2021_V1_DW.UnitDelay8_DSTATE_f;

  /* RateTransition: '<S5>/Rate Transition15' */
  FSAC2021_V1_B.RateTransition15 = FSAC2021_V1_DW.RateTransition15_Buffer0;

  /* S-Function (fcncallgen): '<S7>/Function-Call Generator4' incorporates:
   *  SubSystem: '<S8>/PCANA(RES、AMI、MOTEC、BRAKE、STEER_SENSOR、IPC)'
   */

  /* S-Function (ec55xx_canreceiveslb): '<S247>/Steer_Sensor' */

  /* Receive CAN message */
  {
    uint8 CAN0BUF38RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can0buf38looprx= 0;
    FSAC2021_V1_B.Steer_Sensor_o3= 485;
    FSAC2021_V1_B.Steer_Sensor_o5= 8;
    strsr_node= ec_can_receive(0,38, CAN0BUF38RX);
    FSAC2021_V1_B.Steer_Sensor_o4[0]= CAN0BUF38RX[can0buf38looprx];
    can0buf38looprx++;
    FSAC2021_V1_B.Steer_Sensor_o4[1]= CAN0BUF38RX[can0buf38looprx];
    can0buf38looprx++;
    FSAC2021_V1_B.Steer_Sensor_o4[2]= CAN0BUF38RX[can0buf38looprx];
    can0buf38looprx++;
    FSAC2021_V1_B.Steer_Sensor_o4[3]= CAN0BUF38RX[can0buf38looprx];
    can0buf38looprx++;
    FSAC2021_V1_B.Steer_Sensor_o4[4]= CAN0BUF38RX[can0buf38looprx];
    can0buf38looprx++;
    FSAC2021_V1_B.Steer_Sensor_o4[5]= CAN0BUF38RX[can0buf38looprx];
    can0buf38looprx++;
    FSAC2021_V1_B.Steer_Sensor_o4[6]= CAN0BUF38RX[can0buf38looprx];
    can0buf38looprx++;
    FSAC2021_V1_B.Steer_Sensor_o4[7]= CAN0BUF38RX[can0buf38looprx];
    can0buf38looprx++;
  }

  /* Call the system: <S247>/STEER_SENSOR_INFO1 */

  /* Output and update for function-call system: '<S247>/STEER_SENSOR_INFO1' */
  {
    int32_T rtb_Str_Sensor_Curr_Angle_L;
    real32_T u0;

    /* S-Function (sfix_bitop): '<S260>/Str_Sensor_Curr_Angle_L' incorporates:
     *  Constant: '<S260>/Str_Sensor_Curr_Angleinput2_C'
     *  Product: '<S260>/Str_Sensor_Curr_Angleinput2_P'
     *  Sum: '<S260>/Str_Sensor_Curr_Angleinput2_Ad'
     */
    rtb_Str_Sensor_Curr_Angle_L = (FSAC2021_V1_B.Steer_Sensor_o4[1] << 8) +
      FSAC2021_V1_B.Steer_Sensor_o4[2];

    /* Switch: '<S260>/Str_Sensor_Curr_AngleSW' incorporates:
     *  Constant: '<S260>/Str_Sensor_Curr_Angleinput2_C'
     *  DataTypeConversion: '<S260>/Str_Sensor_Curr_Anglecv'
     *  Product: '<S260>/Str_Sensor_Curr_Angleinput2_P'
     *  RelationalOperator: '<S260>/Str_Sensor_Curr_AngleROP'
     *  Sum: '<S260>/Str_Sensor_Curr_Angleinput2_Ad'
     *  Sum: '<S260>/Str_Sensor_Curr_Anglesubcon'
     *  UnaryMinus: '<S260>/Str_Sensor_Curr_AngleMinus'
     */
    if ((FSAC2021_V1_B.Steer_Sensor_o4[1] << 8) + FSAC2021_V1_B.Steer_Sensor_o4
        [2] >= 32768) {
      u0 = -(65536.0F - (real32_T)rtb_Str_Sensor_Curr_Angle_L);
    } else {
      u0 = (real32_T)rtb_Str_Sensor_Curr_Angle_L;
    }

    /* End of Switch: '<S260>/Str_Sensor_Curr_AngleSW' */

    /* Gain: '<S260>/Str_Sensor_Curr_Angle_F' */
    u0 *= 0.0625F;

    /* Saturate: '<S260>/Str_Sensor_Curr_Angle_sat' */
    if (u0 > 900.0F) {
      Steer_sensor_angle = 900.0F;
    } else if (u0 < -900.0F) {
      Steer_sensor_angle = -900.0F;
    } else {
      Steer_sensor_angle = u0;
    }

    /* End of Saturate: '<S260>/Str_Sensor_Curr_Angle_sat' */
  }

  /* S-Function (ec55xx_canreceiveslb): '<S247>/BCU_MTR_STATUS' */

  /* Receive CAN message */
  {
    uint8 CAN0BUF21RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can0buf21looprx= 0;
    FSAC2021_V1_B.BCU_MTR_STATUS_o3= 257;
    FSAC2021_V1_B.BCU_MTR_STATUS_o5= 8;
    brake_node= ec_can_receive(0,21, CAN0BUF21RX);
    FSAC2021_V1_B.BCU_MTR_STATUS_o4[0]= CAN0BUF21RX[can0buf21looprx];
    can0buf21looprx++;
    FSAC2021_V1_B.BCU_MTR_STATUS_o4[1]= CAN0BUF21RX[can0buf21looprx];
    can0buf21looprx++;
    FSAC2021_V1_B.BCU_MTR_STATUS_o4[2]= CAN0BUF21RX[can0buf21looprx];
    can0buf21looprx++;
    FSAC2021_V1_B.BCU_MTR_STATUS_o4[3]= CAN0BUF21RX[can0buf21looprx];
    can0buf21looprx++;
    FSAC2021_V1_B.BCU_MTR_STATUS_o4[4]= CAN0BUF21RX[can0buf21looprx];
    can0buf21looprx++;
    FSAC2021_V1_B.BCU_MTR_STATUS_o4[5]= CAN0BUF21RX[can0buf21looprx];
    can0buf21looprx++;
    FSAC2021_V1_B.BCU_MTR_STATUS_o4[6]= CAN0BUF21RX[can0buf21looprx];
    can0buf21looprx++;
    FSAC2021_V1_B.BCU_MTR_STATUS_o4[7]= CAN0BUF21RX[can0buf21looprx];
    can0buf21looprx++;
  }

  /* Call the system: <S247>/BCU_MTR_STATUS1 */

  /* Output and update for function-call system: '<S247>/BCU_MTR_STATUS1' */

  /* Saturate: '<S252>/Brake_cmd_fault_flag_sat' incorporates:
   *  ArithShift: '<S252>/Brake_cmd_fault_flag_S'
   *  DataTypeConversion: '<S252>/Brake_cmd_fault_flag_Convert'
   *  DataTypeConversion: '<S252>/Brake_cmd_fault_flagcv'
   *  S-Function (sfix_bitop): '<S252>/Brake_cmd_fault_flag_L'
   */
  FSAC2021_V1_B.Brake_cmd_fault_flag_sat = (real32_T)(int32_T)
    ((FSAC2021_V1_B.BCU_MTR_STATUS_o4[6] & 2U) >> 1);

  /* Saturate: '<S252>/Brake_encoder_fault_sts_sat' incorporates:
   *  DataTypeConversion: '<S252>/Brake_encoder_fault_sts_Convert'
   *  DataTypeConversion: '<S252>/Brake_encoder_fault_stscv'
   *  S-Function (sfix_bitop): '<S252>/Brake_encoder_fault_sts_L'
   */
  FSAC2021_V1_B.Brake_encoder_fault_sts_sat = (real32_T)
    (FSAC2021_V1_B.BCU_MTR_STATUS_o4[4] & 1);

  /* Saturate: '<S252>/Brake_hd_fault_sts_sat' incorporates:
   *  ArithShift: '<S252>/Brake_hd_fault_sts_S'
   *  DataTypeConversion: '<S252>/Brake_hd_fault_sts_Convert'
   *  DataTypeConversion: '<S252>/Brake_hd_fault_stscv'
   *  S-Function (sfix_bitop): '<S252>/Brake_hd_fault_sts_L'
   */
  FSAC2021_V1_B.Brake_hd_fault_sts_sat = (real32_T)(int32_T)
    ((FSAC2021_V1_B.BCU_MTR_STATUS_o4[7] & 64U) >> 6);

  /* Saturate: '<S252>/Brake_lowvolt_prtct_sts_sat' incorporates:
   *  ArithShift: '<S252>/Brake_lowvolt_prtct_sts_S'
   *  DataTypeConversion: '<S252>/Brake_lowvolt_prtct_sts_Convert'
   *  DataTypeConversion: '<S252>/Brake_lowvolt_prtct_stscv'
   *  S-Function (sfix_bitop): '<S252>/Brake_lowvolt_prtct_sts_L'
   */
  FSAC2021_V1_B.Brake_lowvolt_prtct_sts_sat = (real32_T)(int32_T)
    ((FSAC2021_V1_B.BCU_MTR_STATUS_o4[5] & 64U) >> 6);

  /* Saturate: '<S252>/Brake_mtr_enable_flag_sat' incorporates:
   *  ArithShift: '<S252>/Brake_mtr_enable_flag_S'
   *  DataTypeConversion: '<S252>/Brake_mtr_enable_flag_Convert'
   *  DataTypeConversion: '<S252>/Brake_mtr_enable_flagcv'
   *  S-Function (sfix_bitop): '<S252>/Brake_mtr_enable_flag_L'
   */
  FSAC2021_V1_B.Brake_mtr_enable_flag_sat = (real32_T)(int32_T)
    ((FSAC2021_V1_B.BCU_MTR_STATUS_o4[6] & 32U) >> 5);

  /* Saturate: '<S252>/Brake_overcurrt_prtct_sts_sat' incorporates:
   *  ArithShift: '<S252>/Brake_overcurrt_prtct_sts_S'
   *  DataTypeConversion: '<S252>/Brake_overcurrt_prtct_sts_Convert'
   *  DataTypeConversion: '<S252>/Brake_overcurrt_prtct_stscv'
   *  S-Function (sfix_bitop): '<S252>/Brake_overcurrt_prtct_sts_L'
   */
  FSAC2021_V1_B.Brake_overcurrt_prtct_sts_sat = (real32_T)(int32_T)
    ((FSAC2021_V1_B.BCU_MTR_STATUS_o4[5] & 32U) >> 5);

  /* Saturate: '<S252>/Brake_overheat_prtct_sts_sat' incorporates:
   *  ArithShift: '<S252>/Brake_overheat_prtct_sts_S'
   *  DataTypeConversion: '<S252>/Brake_overheat_prtct_sts_Convert'
   *  DataTypeConversion: '<S252>/Brake_overheat_prtct_stscv'
   *  S-Function (sfix_bitop): '<S252>/Brake_overheat_prtct_sts_L'
   */
  FSAC2021_V1_B.Brake_overheat_prtct_sts_sat = (real32_T)(int32_T)
    ((FSAC2021_V1_B.BCU_MTR_STATUS_o4[5] & 16U) >> 4);

  /* Saturate: '<S252>/Brake_reg_rw_fault_flag_sat' incorporates:
   *  ArithShift: '<S252>/Brake_reg_rw_fault_flag_S'
   *  DataTypeConversion: '<S252>/Brake_reg_rw_fault_flag_Convert'
   *  DataTypeConversion: '<S252>/Brake_reg_rw_fault_flagcv'
   *  S-Function (sfix_bitop): '<S252>/Brake_reg_rw_fault_flag_L'
   */
  FSAC2021_V1_B.Brake_reg_rw_fault_flag_sat = (real32_T)(int32_T)
    ((FSAC2021_V1_B.BCU_MTR_STATUS_o4[6] & 4U) >> 2);

  /* DataTypeConversion: '<S247>/Data Type Conversion10' */
  FSAC2021_V1_B.DataTypeConversion10 = FSAC2021_V1_B.Brake_reg_rw_fault_flag_sat;

  /* DataTypeConversion: '<S247>/Data Type Conversion11' */
  FSAC2021_V1_B.DataTypeConversion11 =
    FSAC2021_V1_B.Brake_overheat_prtct_sts_sat;

  /* DataTypeConversion: '<S247>/Data Type Conversion12' */
  FSAC2021_V1_B.DataTypeConversion12 =
    FSAC2021_V1_B.Brake_overcurrt_prtct_sts_sat;

  /* DataTypeConversion: '<S247>/Data Type Conversion16' */
  DataTypeConversion16 = (uint8_T)FSAC2021_V1_B.Brake_mtr_enable_flag_sat;

  /* DataTypeConversion: '<S247>/Data Type Conversion17' */
  FSAC2021_V1_B.DataTypeConversion17 = FSAC2021_V1_B.Brake_lowvolt_prtct_sts_sat;

  /* DataTypeConversion: '<S247>/Data Type Conversion18' */
  FSAC2021_V1_B.DataTypeConversion18 = FSAC2021_V1_B.Brake_hd_fault_sts_sat;

  /* DataTypeConversion: '<S247>/Data Type Conversion20' */
  FSAC2021_V1_B.DataTypeConversion20 = FSAC2021_V1_B.Brake_encoder_fault_sts_sat;

  /* DataTypeConversion: '<S247>/Data Type Conversion21' */
  FSAC2021_V1_B.DataTypeConversion21 = FSAC2021_V1_B.Brake_cmd_fault_flag_sat;

  /* S-Function (ec55xx_canreceiveslb): '<S247>/MOTEC_MOTION1' */

  /* Receive CAN message */
  {
    uint8 CAN0BUF41RX[3]= { 0, 0, 0 };

    uint8 can0buf41looprx= 0;
    FSAC2021_V1_B.MOTEC_MOTION1_o3= 256;
    FSAC2021_V1_B.MOTEC_MOTION1_o5= 3;
    FSAC2021_V1_B.MOTEC_MOTION1_o2= ec_can_receive(0,41, CAN0BUF41RX);
    FSAC2021_V1_B.MOTEC_MOTION1_o4[0]= CAN0BUF41RX[can0buf41looprx];
    can0buf41looprx++;
    FSAC2021_V1_B.MOTEC_MOTION1_o4[1]= CAN0BUF41RX[can0buf41looprx];
    can0buf41looprx++;
    FSAC2021_V1_B.MOTEC_MOTION1_o4[2]= CAN0BUF41RX[can0buf41looprx];
    can0buf41looprx++;
  }

  /* Call the system: <S247>/IPC_CMD1 */

  /* Output and update for function-call system: '<S247>/IPC_CMD1' */

  /* Saturate: '<S253>/IPC_Acc_sat' incorporates:
   *  DataTypeConversion: '<S253>/IPC_Acc_Convert'
   *  DataTypeConversion: '<S253>/IPC_Acccv'
   */
  if (FSAC2021_V1_B.MOTEC_MOTION1_o4[0] > 100.0F) {
    FSAC2021_V1_B.IPC_Acc_sat = 100.0F;
  } else {
    FSAC2021_V1_B.IPC_Acc_sat = FSAC2021_V1_B.MOTEC_MOTION1_o4[0];
  }

  /* End of Saturate: '<S253>/IPC_Acc_sat' */

  /* Saturate: '<S253>/IPC_Brk_sat' incorporates:
   *  DataTypeConversion: '<S253>/IPC_Brk_Convert'
   *  DataTypeConversion: '<S253>/IPC_Brkcv'
   */
  if (FSAC2021_V1_B.MOTEC_MOTION1_o4[1] > 100.0F) {
    FSAC2021_V1_B.IPC_Brk_sat = 100.0F;
  } else {
    FSAC2021_V1_B.IPC_Brk_sat = FSAC2021_V1_B.MOTEC_MOTION1_o4[1];
  }

  /* End of Saturate: '<S253>/IPC_Brk_sat' */

  /* Saturate: '<S253>/IPC_Steer_sat' incorporates:
   *  Constant: '<S253>/IPC_Steer_O'
   *  DataTypeConversion: '<S253>/IPC_Steer_Convert'
   *  DataTypeConversion: '<S253>/IPC_Steercv'
   *  Sum: '<S253>/IPC_Steer_Ad'
   */
  FSAC2021_V1_B.IPC_Steer_sat = (real32_T)FSAC2021_V1_B.MOTEC_MOTION1_o4[2] +
    -120.0F;

  /* Outputs for Enabled SubSystem: '<S247>/Subsystem' incorporates:
   *  EnablePort: '<S261>/Enable'
   */
  if (FSAC2021_V1_B.MOTEC_MOTION1_o2 > 0) {
    /* DataTypeConversion: '<S261>/Data Type Conversion22' */
    FSAC2021_V1_B.DataTypeConversion22 = FSAC2021_V1_B.IPC_Steer_sat;

    /* DataTypeConversion: '<S261>/Data Type Conversion24' */
    FSAC2021_V1_B.DataTypeConversion24 = FSAC2021_V1_B.IPC_Brk_sat;

    /* DataTypeConversion: '<S261>/Data Type Conversion23' */
    FSAC2021_V1_B.DataTypeConversion23 = FSAC2021_V1_B.IPC_Acc_sat;
  }

  /* End of Outputs for SubSystem: '<S247>/Subsystem' */

  /* S-Function (ec55xx_canreceiveslb): '<S247>/MOTEC_MOTION2' */

  /* Receive CAN message */
  {
    uint8 CAN0BUF35RX[1]= { 0 };

    uint8 can0buf35looprx= 0;
    FSAC2021_V1_B.MOTEC_MOTION2_o3= 279;
    FSAC2021_V1_B.MOTEC_MOTION2_o5= 1;
    RES__ok= ec_can_receive(0,35, CAN0BUF35RX);
    FSAC2021_V1_B.MOTEC_MOTION2_o4= CAN0BUF35RX[can0buf35looprx];
    can0buf35looprx++;
  }

  /* Call the system: <S247>/Res_Message1 */

  /* Output and update for function-call system: '<S247>/Res_Message1' */

  /* Saturate: '<S259>/Res_Run_Status_sat' incorporates:
   *  ArithShift: '<S259>/Res_Run_Status_S'
   *  DataTypeConversion: '<S259>/Res_Run_Status_Convert'
   *  DataTypeConversion: '<S259>/Res_Run_Statuscv'
   *  S-Function (sfix_bitop): '<S259>/Res_Run_Status_L'
   */
  RES_Value = (real32_T)(int32_T)((FSAC2021_V1_B.MOTEC_MOTION2_o4 & 62U) >> 1);

  /* UnitDelay: '<S8>/Unit Delay1' */
  FSAC2021_V1_B.UnitDelay1 = FSAC2021_V1_DW.UnitDelay1_DSTATE_l;

  /* S-Function (ec55xx_cantransmitslb): '<S13>/CANTransmit6' */

  /*Transmit CAN message*/
  {
    uint8 CAN0BUF59TX[2];
    uint8 can0buf59looptx= 0;
    CAN0BUF59TX[can0buf59looptx]= FSAC2021_V1_ConstB.status_reg_addr_start_Con_k;
    can0buf59looptx++;
    CAN0BUF59TX[can0buf59looptx]= FSAC2021_V1_ConstB.status_reg_num_Convert;
    can0buf59looptx++;
    Read_BCU= ec_can_transmit(0, 59, 0, 382U, 2, CAN0BUF59TX);
  }

  /* RateTransition: '<S2>/Rate Transition41' */
  rtb_RateTransition41 = FSAC2021_V1_DW.RateTransition41_Buffer0;

  /* RateTransition: '<S3>/RateTransition24' */
  if (FSAC2021_V1_M->Timing.RateInteraction.TID3_7) {
    FSAC2021_V1_B.RateTransition24 = FSAC2021_V1_B.UnitDelay8_f;

    /* RateTransition: '<S3>/RateTransition26' */
    FSAC2021_V1_B.RateTransition26 = RES_Value;
  }

  /* End of RateTransition: '<S3>/RateTransition24' */

  /* S-Function (fcncallgen): '<S226>/10ms' incorporates:
   *  SubSystem: '<S226>/daq10ms'
   */

  /* S-Function (ec55xx_ccpslb1): '<S238>/CCPDAQ' */
  ccpDaq(1);

  /* S-Function (fcncallgen): '<S228>/10ms' incorporates:
   *  SubSystem: '<S228>/10mstask'
   */

  /* S-Function (ec55xx_pdsdslb1): '<S242>/PDSD' */
  ec_tle6232_diag();

  /* Update for UnitDelay: '<S2>/Unit Delay8' */
  FSAC2021_V1_DW.UnitDelay8_DSTATE_f = rtb_RateTransition41;

  /* Update for UnitDelay: '<S8>/Unit Delay1' */
  FSAC2021_V1_DW.UnitDelay1_DSTATE_l = DataTypeConversion16;
}

/* Model step function for TID4 */
void FSAC2021_V1_step4(void)           /* Sample time: [0.02s, 0.0s] */
{
  /* local block i/o variables */
  real32_T rtb_Gain_n;
  uint32_T rtb_RateTransition18_l;
  uint32_T rtb_RateTransition19_d;
  uint32_T rtb_RateTransition25_k;
  uint32_T rtb_RateTransition26;
  uint16_T rtb_RateTransition22_m;
  uint16_T rtb_RateTransition14;
  uint16_T rtb_RateTransition24;
  real_T u0;

  /* RateTransition: '<S5>/Rate Transition18' */
  rtb_RateTransition18_l = FSAC2021_V1_DW.RateTransition18_Buffer0;

  /* RateTransition: '<S5>/Rate Transition19' */
  rtb_RateTransition19_d = FSAC2021_V1_DW.RateTransition19_Buffer0;

  /* RateTransition: '<S5>/Rate Transition25' */
  rtb_RateTransition25_k = FSAC2021_V1_DW.RateTransition25_Buffer0_d;

  /* RateTransition: '<S5>/Rate Transition26' */
  rtb_RateTransition26 = FSAC2021_V1_DW.RateTransition26_Buffer0;

  /* RateTransition: '<S5>/Rate Transition22' */
  rtb_RateTransition22_m = FSAC2021_V1_DW.RateTransition22_Buffer0;

  /* RateTransition: '<S5>/Rate Transition14' */
  rtb_RateTransition14 = FSAC2021_V1_DW.RateTransition14_Buffer0;

  /* RateTransition: '<S5>/Rate Transition24' */
  rtb_RateTransition24 = FSAC2021_V1_DW.RateTransition24_Buffer0;

  /* S-Function (fcncallgen): '<S7>/Function-Call Generator' incorporates:
   *  SubSystem: '<S5>/KL_Sig_Process'
   */

  /* Outputs for Atomic SubSystem: '<S210>/Whl_Spd_Hz2RPM' */
  FSAC2021_V1_Whl_Spd_Hz2RPM(rtb_RateTransition18_l,
    &FSAC2021_V1_B.Whl_Spd_Hz2RPM);

  /* End of Outputs for SubSystem: '<S210>/Whl_Spd_Hz2RPM' */

  /* Outputs for Atomic SubSystem: '<S210>/LPF' */
  FSAC2021_V1_LPF(FSAC2021_V1_B.Whl_Spd_Hz2RPM.rps2rpm, &FSAC2021_V1_B.LPF,
                  &FSAC2021_V1_DW.LPF);

  /* End of Outputs for SubSystem: '<S210>/LPF' */

  /* Outputs for Atomic SubSystem: '<S210>/Whl_Spd_Hz2RPM1' */
  FSAC2021_V1_Whl_Spd_Hz2RPM(rtb_RateTransition19_d,
    &FSAC2021_V1_B.Whl_Spd_Hz2RPM1);

  /* End of Outputs for SubSystem: '<S210>/Whl_Spd_Hz2RPM1' */

  /* Outputs for Atomic SubSystem: '<S210>/LPF1' */
  FSAC2021_V1_LPF(FSAC2021_V1_B.Whl_Spd_Hz2RPM1.rps2rpm, &FSAC2021_V1_B.LPF1,
                  &FSAC2021_V1_DW.LPF1);

  /* End of Outputs for SubSystem: '<S210>/LPF1' */

  /* Outputs for Atomic SubSystem: '<S210>/Whl_Spd_Hz2RPM2' */
  FSAC2021_V_Whl_Spd_Hz2RPM2(rtb_RateTransition25_k,
    &FSAC2021_V1_B.Whl_Spd_Hz2RPM2);

  /* End of Outputs for SubSystem: '<S210>/Whl_Spd_Hz2RPM2' */

  /* Outputs for Atomic SubSystem: '<S210>/LPF2' */
  FSAC2021_V1_LPF(FSAC2021_V1_B.Whl_Spd_Hz2RPM2.rps2rpm, &FSAC2021_V1_B.LPF2,
                  &FSAC2021_V1_DW.LPF2);

  /* End of Outputs for SubSystem: '<S210>/LPF2' */

  /* Outputs for Atomic SubSystem: '<S210>/Whl_Spd_Hz2RPM3' */
  FSAC2021_V_Whl_Spd_Hz2RPM2(rtb_RateTransition26,
    &FSAC2021_V1_B.Whl_Spd_Hz2RPM3);

  /* End of Outputs for SubSystem: '<S210>/Whl_Spd_Hz2RPM3' */

  /* Outputs for Atomic SubSystem: '<S210>/LPF3' */
  FSAC2021_V1_LPF(FSAC2021_V1_B.Whl_Spd_Hz2RPM3.rps2rpm, &FSAC2021_V1_B.LPF3,
                  &FSAC2021_V1_DW.LPF3);

  /* End of Outputs for SubSystem: '<S210>/LPF3' */

  /* Gain: '<S224>/Gain' incorporates:
   *  Gain: '<S223>/Gain6'
   *  Sum: '<S223>/Add3'
   */
  rtb_Gain_n = (((FSAC2021_V1_B.LPF.Add1 + FSAC2021_V1_B.LPF1.Add1) +
                 FSAC2021_V1_B.LPF2.Add1) + FSAC2021_V1_B.LPF3.Add1) * 0.25F *
    0.0882159248F;

  /* Outputs for Atomic SubSystem: '<S217>/Round' */
  FSAC2021_V1_Round(rtb_Gain_n);

  /* End of Outputs for SubSystem: '<S217>/Round' */

  /* Switch: '<S209>/Switch' incorporates:
   *  Constant: '<S209>/Constant2'
   *  Constant: '<S211>/Constant'
   *  RelationalOperator: '<S211>/Compare'
   */
  if (rtb_RateTransition22_m <= 100) {
    FSAC2021_V1_B.Switch = 0.0;
  } else {
    /* Sum: '<S209>/Add1' incorporates:
     *  Constant: '<S209>/Acc_Right_Offset'
     *  Constant: '<S209>/Constant1'
     *  Product: '<S209>/Divide1'
     */
    u0 = (real_T)rtb_RateTransition22_m * -0.08333 + 408.33;

    /* Saturate: '<S209>/Saturation1' */
    if (u0 > 100.0) {
      FSAC2021_V1_B.Switch = 100.0;
    } else if (u0 < 0.0) {
      FSAC2021_V1_B.Switch = 0.0;
    } else {
      FSAC2021_V1_B.Switch = u0;
    }

    /* End of Saturate: '<S209>/Saturation1' */
  }

  /* End of Switch: '<S209>/Switch' */

  /* Gain: '<S209>/Gain' */
  u0 = 15.0 * FSAC2021_V1_B.Switch;

  /* Saturate: '<S209>/Saturation2' */
  if (u0 > 1500.0) {
    FSAC2021_V1_B.Saturation2 = 1500.0;
  } else if (u0 < 0.0) {
    FSAC2021_V1_B.Saturation2 = 0.0;
  } else {
    FSAC2021_V1_B.Saturation2 = u0;
  }

  /* End of Saturate: '<S209>/Saturation2' */

  /* Sum: '<S209>/Add4' incorporates:
   *  Product: '<S209>/Divide4'
   */
  FSAC2021_V1_B.Add4 = rtb_RateTransition14;

  /* Sum: '<S209>/Add5' incorporates:
   *  Product: '<S209>/Divide5'
   */
  FSAC2021_V1_B.Add5 = rtb_RateTransition24;

  /* Update for RateTransition: '<S5>/Rate Transition15' */
  FSAC2021_V1_DW.RateTransition15_Buffer0 = Vel_spd;
}

/* Model step function for TID5 */
void FSAC2021_V1_step5(void)           /* Sample time: [0.03s, 0.0s] */
{
  real_T rtb_RateTransition10;
  real32_T rtb_RateTransition13;
  uint8_T rtb_RateTransition14_o;
  real32_T rtb_RateTransition16;
  int32_T rtb_Battery_Volt_L;

  /* UnitDelay: '<S1>/Unit Delay5' */
  Voltage = FSAC2021_V1_DW.UnitDelay5_DSTATE;

  /* UnitDelay: '<S1>/Unit Delay1' */
  Motor_Spd = FSAC2021_V1_DW.UnitDelay1_DSTATE_m;

  /* UnitDelay: '<S1>/Unit Delay2' */
  ASSI_state = FSAC2021_V1_DW.UnitDelay2_DSTATE;

  /* UnitDelay: '<S1>/Unit Delay6' */
  Vspd = FSAC2021_V1_DW.UnitDelay6_DSTATE_p;

  /* S-Function (fcncallgen): '<S7>/Function-Call Generator5' incorporates:
   *  SubSystem: '<S1>/(BRK、STR、DRIVER)'
   */
  /* Saturate: '<S23>/vspd_sat' */
  if (Vspd > 255.0F) {
    rtb_RateTransition13 = 255.0F;
  } else if (Vspd < 0.0F) {
    rtb_RateTransition13 = 0.0F;
  } else {
    rtb_RateTransition13 = Vspd;
  }

  /* DataTypeConversion: '<S23>/vspd_Convert' incorporates:
   *  DataTypeConversion: '<S23>/vspd_Convert1'
   *  Rounding: '<S23>/vspdRon'
   *  S-Function (sfix_bitop): '<S23>/vspd_L'
   *  Saturate: '<S23>/vspd_1sat'
   *  Saturate: '<S23>/vspd_sat'
   */
  FSAC2021_V1_B.vspd_Convert = (uint8_T)((uint32_T)rt_roundf_snf
    (rtb_RateTransition13) & 255U);

  /* Saturate: '<S22>/mtr_rpm_sat' */
  if (Motor_Spd > 65535.0F) {
    rtb_RateTransition13 = 65535.0F;
  } else if (Motor_Spd < 0.0F) {
    rtb_RateTransition13 = 0.0F;
  } else {
    rtb_RateTransition13 = Motor_Spd;
  }

  /* S-Function (sfix_bitop): '<S22>/mtr_rpm_L' incorporates:
   *  DataTypeConversion: '<S22>/mtr_rpm_Convert'
   *  Rounding: '<S22>/mtr_rpmRon'
   *  Saturate: '<S22>/mtr_rpm_1sat'
   *  Saturate: '<S22>/mtr_rpm_sat'
   */
  rtb_Battery_Volt_L = (int32_T)((uint32_T)rt_roundf_snf(rtb_RateTransition13) &
    65535U);

  /* DataTypeConversion: '<S22>/mtr_rpmCOV' incorporates:
   *  Constant: '<S22>/mtr_rpmoutput2_C'
   *  Product: '<S22>/mtr_rpm_D1'
   */
  FSAC2021_V1_B.mtr_rpmCOV = (uint8_T)((real_T)rtb_Battery_Volt_L / 256.0);

  /* DataTypeConversion: '<S22>/mtr_rpmBitCov' incorporates:
   *  Constant: '<S22>/mtr_rpm_And_C'
   *  S-Function (sfix_bitop): '<S22>/mtr_rpm_And'
   */
  FSAC2021_V1_B.mtr_rpmBitCov = (uint8_T)(rtb_Battery_Volt_L & 255U);

  /* DataTypeConversion: '<S21>/assi_status_Convert' incorporates:
   *  Rounding: '<S21>/assi_statusRon'
   *  Saturate: '<S21>/assi_status_1sat'
   *  Sum: '<S21>/assi_status_st'
   */
  FSAC2021_V1_B.assi_status_Convert = (uint8_T)rt_roundf_snf((real32_T)
    ASSI_state);

  /* Saturate: '<S20>/Battery_Volt_sat' */
  if (Voltage > 6553.5) {
    rtb_RateTransition10 = 6553.5;
  } else if (Voltage < 0.0) {
    rtb_RateTransition10 = 0.0;
  } else {
    rtb_RateTransition10 = Voltage;
  }

  /* S-Function (sfix_bitop): '<S20>/Battery_Volt_L' incorporates:
   *  DataTypeConversion: '<S20>/Battery_Volt_Convert'
   *  Product: '<S20>/Battery_Volt_D'
   *  Rounding: '<S20>/Battery_VoltRon'
   *  Saturate: '<S20>/Battery_Volt_1sat'
   *  Saturate: '<S20>/Battery_Volt_sat'
   */
  rtb_Battery_Volt_L = (int32_T)((uint32_T)rt_roundd_snf(rtb_RateTransition10 /
    0.10000000149011612) & 65535U);

  /* DataTypeConversion: '<S20>/Battery_VoltCOV' incorporates:
   *  Constant: '<S20>/Battery_Voltoutput5_C'
   *  Product: '<S20>/Battery_Volt_D1'
   */
  FSAC2021_V1_B.Battery_VoltCOV = (uint8_T)((real_T)rtb_Battery_Volt_L / 256.0);

  /* DataTypeConversion: '<S20>/Battery_VoltBitCov' incorporates:
   *  Constant: '<S20>/Battery_Volt_And_C'
   *  S-Function (sfix_bitop): '<S20>/Battery_Volt_And'
   */
  FSAC2021_V1_B.Battery_VoltBitCov = (uint8_T)(rtb_Battery_Volt_L & 255U);

  /* S-Function (ec55xx_cantransmitslb): '<S10>/CANTransmit7' */

  /*Transmit CAN message*/
  {
    uint8 CAN0BUF60TX[8];
    uint8 can0buf60looptx= 0;
    CAN0BUF60TX[can0buf60looptx]= FSAC2021_V1_B.vspd_Convert;
    can0buf60looptx++;
    CAN0BUF60TX[can0buf60looptx]= FSAC2021_V1_B.mtr_rpmCOV;
    can0buf60looptx++;
    CAN0BUF60TX[can0buf60looptx]= FSAC2021_V1_B.mtr_rpmBitCov;
    can0buf60looptx++;
    CAN0BUF60TX[can0buf60looptx]= FSAC2021_V1_B.assi_status_Convert;
    can0buf60looptx++;
    CAN0BUF60TX[can0buf60looptx]= FSAC2021_V1_B.Battery_VoltCOV;
    can0buf60looptx++;
    CAN0BUF60TX[can0buf60looptx]= FSAC2021_V1_B.Battery_VoltBitCov;
    can0buf60looptx++;
    CAN0BUF60TX[can0buf60looptx]= ((uint8_T)0U);
    can0buf60looptx++;
    CAN0BUF60TX[can0buf60looptx]= ((uint8_T)0U);
    can0buf60looptx++;
    To_AMI_OK= ec_can_transmit(0, 60, 0, 1161U, 8, CAN0BUF60TX);
  }

  /* RateTransition: '<S1>/Rate Transition10' */
  rtb_RateTransition10 = FSAC2021_V1_DW.RateTransition10_Buffer0;

  /* RateTransition: '<S1>/Rate Transition13' */
  rtb_RateTransition13 = FSAC2021_V1_DW.RateTransition13_Buffer0;

  /* RateTransition: '<S1>/Rate Transition14' */
  rtb_RateTransition14_o = FSAC2021_V1_B.UnitDelay8_f;

  /* RateTransition: '<S1>/Rate Transition16' */
  rtb_RateTransition16 = FSAC2021_V1_B.RateTransition15;

  /* Update for UnitDelay: '<S1>/Unit Delay5' */
  FSAC2021_V1_DW.UnitDelay5_DSTATE = rtb_RateTransition10;

  /* Update for UnitDelay: '<S1>/Unit Delay1' */
  FSAC2021_V1_DW.UnitDelay1_DSTATE_m = rtb_RateTransition13;

  /* Update for UnitDelay: '<S1>/Unit Delay2' */
  FSAC2021_V1_DW.UnitDelay2_DSTATE = rtb_RateTransition14_o;

  /* Update for UnitDelay: '<S1>/Unit Delay6' */
  FSAC2021_V1_DW.UnitDelay6_DSTATE_p = rtb_RateTransition16;
}

/* Model step function for TID6 */
void FSAC2021_V1_step6(void)           /* Sample time: [0.05s, 0.0s] */
{
  /* local block i/o variables */
  real32_T rtb_Gain;
  int8_T rtb_Gain_p;
  boolean_T rtb_Equal2;
  uint8_T rtb_RateTransition17_f;
  uint8_T rtb_RateTransition18_o;
  uint8_T rtb_RateTransition19_j;
  real32_T rtb_RateTransition46;
  uint8_T rtb_RateTransition59;
  uint8_T rtb_RateTransition60;
  uint8_T rtb_RateTransition57;
  real_T rtb_RateTransition4;
  real_T rtb_RateTransition3;
  real32_T rtb_RateTransition11;
  uint8_T rtb_RateTransition24_e;
  uint8_T rtb_RateTransition25_f;
  boolean_T rtb_RateTransition31;
  boolean_T rtb_RateTransition32;
  boolean_T rtb_RateTransition33;
  boolean_T rtb_RateTransition50;
  real_T rtb_RateTransition77;
  real_T rtb_RateTransition78;
  real_T rtb_RateTransition80;
  uint8_T rtb_RateTransition47;
  uint8_T rtb_RateTransition46_e;
  real_T rtb_RateTransition6;
  boolean_T rtb_RateTransition42;
  real_T rtb_RateTransition25;
  real_T rtb_UnitDelay5;
  boolean_T rtb_RateTransition26_p;
  int32_T rtb_DataTypeConversion13;
  int32_T rtb_DataTypeConversion14;
  int32_T rtb_DataTypeConversion16;
  real_T rtb_UnitDelay7;
  boolean_T rtb_Nogas1Hasgas_o;
  uint32_T rtb_Drive_Speed_Control_And;
  int16_T MultiportSwitch;
  real32_T DataTypeConversion10_h;

  /* RateTransition: '<S2>/Rate Transition17' */
  rtb_RateTransition17_f = FSAC2021_V1_DW.RateTransition17_Buffer0;

  /* RateTransition: '<S2>/Rate Transition18' */
  rtb_RateTransition18_o = FSAC2021_V1_DW.RateTransition18_Buffer0_d;

  /* RateTransition: '<S2>/Rate Transition19' */
  rtb_RateTransition19_j = FSAC2021_V1_DW.RateTransition19_Buffer0_e;

  /* RateTransition: '<S2>/Rate Transition46' */
  rtb_RateTransition46 = Steer_sensor_angle;

  /* RateTransition: '<S2>/Rate Transition59' */
  rtb_RateTransition59 = FSAC2021_V1_DW.RateTransition59_Buffer0;

  /* RateTransition: '<S2>/Rate Transition60' */
  rtb_RateTransition60 = FSAC2021_V1_B.UnitDelay8_f;

  /* RateTransition: '<S2>/Rate Transition63' */
  Brk_Enable_Flag = FSAC2021_V1_B.UnitDelay1;

  /* RateTransition: '<S2>/Rate Transition57' */
  rtb_RateTransition57 = FSAC2021_V1_B.UnitDelay8_f;

  /* RateTransition: '<S5>/Rate Transition4' */
  rtb_RateTransition4 = FSAC2021_V1_B.Add4;

  /* RateTransition: '<S5>/Rate Transition3' */
  rtb_RateTransition3 = FSAC2021_V1_B.Add5;

  /* RateTransition: '<S2>/Rate Transition11' */
  rtb_RateTransition11 = FSAC2021_V1_B.RateTransition15;

  /* RateTransition: '<S3>/Rate Transition24' */
  rtb_RateTransition24_e = FSAC2021_V1_DW.RateTransition24_Buffer0_n;

  /* RateTransition: '<S2>/Rate Transition24' */
  RES_EBS = rtb_RateTransition24_e;

  /* RateTransition: '<S2>/Rate Transition25' */
  rtb_RateTransition25_f = FSAC2021_V1_DW.RateTransition25_Buffer0_c;

  /* RateTransition: '<S2>/Rate Transition31' */
  rtb_RateTransition31 = FSAC2021_V1_DW.RateTransition31_Buffer0;

  /* RateTransition: '<S2>/Rate Transition32' */
  rtb_RateTransition32 = FSAC2021_V1_DW.RateTransition32_Buffer0;

  /* RateTransition: '<S2>/Rate Transition33' */
  rtb_RateTransition33 = FSAC2021_V1_DW.RateTransition33_Buffer0;

  /* RateTransition: '<S2>/Rate Transition50' */
  rtb_RateTransition50 = FSAC2021_V1_DW.RateTransition50_Buffer0;

  /* RateTransition: '<S2>/Rate Transition77' */
  rtb_RateTransition77 = FSAC2021_V1_B.DataTypeConversion22;

  /* RateTransition: '<S2>/Rate Transition78' */
  rtb_RateTransition78 = FSAC2021_V1_B.DataTypeConversion24;

  /* RateTransition: '<S2>/Rate Transition80' */
  rtb_RateTransition80 = FSAC2021_V1_B.DataTypeConversion23;

  /* RateTransition: '<S3>/Rate Transition47' */
  rtb_RateTransition47 = FSAC2021_V1_DW.RateTransition47_Buffer0;

  /* RateTransition: '<S3>/Rate Transition46' */
  rtb_RateTransition46_e = FSAC2021_V1_DW.RateTransition46_Buffer0;

  /* RateTransition: '<S5>/Rate Transition6' */
  rtb_RateTransition6 = FSAC2021_V1_B.Saturation2;

  /* RateTransition: '<S2>/Rate Transition42' */
  rtb_RateTransition42 = FSAC2021_V1_DW.RateTransition42_Buffer0;

  /* UnitDelay: '<S2>/Unit Delay7' */
  rtb_UnitDelay7 = FSAC2021_V1_DW.UnitDelay7_DSTATE;

  /* RateTransition: '<S3>/Rate Transition25' */
  rtb_RateTransition25 = FSAC2021_V1_DW.RateTransition25_Buffer0;

  /* UnitDelay: '<S8>/Unit Delay5' */
  rtb_UnitDelay5 = FSAC2021_V1_DW.UnitDelay5_DSTATE_e;

  /* RateTransition: '<S2>/Rate Transition8' */
  AMI_State = rtb_UnitDelay5;

  /* RateTransition: '<S3>/Rate Transition26' */
  rtb_RateTransition26_p = FSAC2021_V1_DW.RateTransition26_Buffer0_d;

  /* RateTransition: '<S2>/Rate Transition34' */
  EBS_Sensor_light = rtb_RateTransition26_p;

  /* UnitDelay: '<S3>/Unit Delay2' */
  rtb_RateTransition24_e = FSAC2021_V1_DW.UnitDelay2_DSTATE_h;

  /* RateTransition: '<S2>/Rate Transition51' */
  EBS_light = rtb_RateTransition24_e;

  /* UnitDelay: '<S1>/Unit Delay3' */
  pulses = FSAC2021_V1_DW.UnitDelay3_DSTATE;

  /* UnitDelay: '<S1>/Unit Delay4' */
  ACC = FSAC2021_V1_DW.UnitDelay4_DSTATE;

  /* RateTransition: '<S1>/Rate Transition19' */
  rtb_RateTransition24_e = FSAC2021_V1_B.UnitDelay8_f;

  /* DataTypeConversion: '<S11>/Data Type Conversion8' incorporates:
   *  UnitDelay: '<S11>/Unit Delay6'
   */
  FSAC2021_V1_B.DataTypeConversion8 = (real32_T)
    FSAC2021_V1_DW.UnitDelay6_DSTATE_n;

  /* UnitDelay: '<S11>/Unit Delay8' */
  FSAC2021_V1_B.UnitDelay8 = FSAC2021_V1_DW.UnitDelay8_DSTATE;

  /* DataTypeConversion: '<S11>/Data Type Conversion6' incorporates:
   *  UnitDelay: '<S11>/Unit Delay4'
   */
  FSAC2021_V1_B.DataTypeConversion6 = FSAC2021_V1_DW.UnitDelay4_DSTATE_g;

  /* DataTypeConversion: '<S11>/Data Type Conversion9' incorporates:
   *  UnitDelay: '<S11>/Unit Delay7'
   */
  FSAC2021_V1_B.DataTypeConversion9 = FSAC2021_V1_DW.UnitDelay7_DSTATE_g;

  /* DataTypeConversion: '<S11>/Data Type Conversion7' incorporates:
   *  UnitDelay: '<S11>/Unit Delay5'
   */
  FSAC2021_V1_B.DataTypeConversion7 = FSAC2021_V1_DW.UnitDelay5_DSTATE_p;

  /* DataTypeConversion: '<S11>/Data Type Conversion2' incorporates:
   *  UnitDelay: '<S11>/Unit Delay'
   */
  FSAC2021_V1_B.DataTypeConversion2 = FSAC2021_V1_DW.UnitDelay_DSTATE;

  /* DataTypeConversion: '<S11>/Data Type Conversion4' incorporates:
   *  UnitDelay: '<S11>/Unit Delay2'
   */
  FSAC2021_V1_B.DataTypeConversion4 = FSAC2021_V1_DW.UnitDelay2_DSTATE_o;

  /* DataTypeConversion: '<S11>/Data Type Conversion3' incorporates:
   *  UnitDelay: '<S11>/Unit Delay1'
   */
  FSAC2021_V1_B.DataTypeConversion3 = FSAC2021_V1_DW.UnitDelay1_DSTATE_n;

  /* DataTypeConversion: '<S11>/Data Type Conversion5' incorporates:
   *  UnitDelay: '<S11>/Unit Delay3'
   */
  FSAC2021_V1_B.DataTypeConversion5 = FSAC2021_V1_DW.UnitDelay3_DSTATE_p;

  /* S-Function (fcncallgen): '<S7>/Function-Call Generator1' incorporates:
   *  SubSystem: '<S2>/SteerCtr'
   */
  /* Sum: '<S134>/Real_steer_angle' incorporates:
   *  Constant: '<S134>/Constant'
   */
  Back_Angle = rtb_RateTransition46 - -341.0F;

  /* DataTypeConversion: '<S67>/Data Type Conversion2' incorporates:
   *  UnitDelay: '<S2>/Unit Delay6'
   */
  Str = (int8_T)floor(FSAC2021_V1_DW.UnitDelay6_DSTATE);

  /* Chart: '<S67>/Chart' */
  FSAC2021_V1_DW.presentTicks_nm = FSAC2021_V1_M->Timing.clockTick6;
  FSAC2021_V1_DW.elapsedTicks_c = FSAC2021_V1_DW.presentTicks_nm -
    FSAC2021_V1_DW.previousTicks_c;
  FSAC2021_V1_DW.previousTicks_c = FSAC2021_V1_DW.presentTicks_nm;
  if (FSAC2021_V1_DW.temporalCounter_i1_m + FSAC2021_V1_DW.elapsedTicks_c <= 15U)
  {
    FSAC2021_V1_DW.temporalCounter_i1_m = (uint8_T)
      (FSAC2021_V1_DW.temporalCounter_i1_m + FSAC2021_V1_DW.elapsedTicks_c);
  } else {
    FSAC2021_V1_DW.temporalCounter_i1_m = 15U;
  }

  /* Gateway: Controller/SteerCtr/Chart */
  /* During: Controller/SteerCtr/Chart */
  if (FSAC2021_V1_DW.bitsForTID6.is_active_c14_FSAC2021_V1 == 0U) {
    /* Entry: Controller/SteerCtr/Chart */
    FSAC2021_V1_DW.bitsForTID6.is_active_c14_FSAC2021_V1 = 1U;

    /* Entry Internal: Controller/SteerCtr/Chart */
    /* Transition: '<S129>:2' */
    FSAC2021_V1_DW.bitsForTID6.is_c14_FSAC2021_V1 = FSAC2021_V1_IN_Init;
  } else {
    switch (FSAC2021_V1_DW.bitsForTID6.is_c14_FSAC2021_V1) {
     case FSAC2021_V1_IN_Init:
      /* During 'Init': '<S129>:100' */
      /* Transition: '<S129>:101' */
      FSAC2021_V1_DW.bitsForTID6.is_c14_FSAC2021_V1 =
        FSAC2021__IN_Pre_Operation_Mode;

      /* Entry 'Pre_Operation_Mode': '<S129>:1' */
      FSAC2021_V1_B.NMT_nodeorder = 1U;

      /* 开启远程节点。 */
      FSAC2021_V1_B.NMT_nodectrl = 0U;
      break;

     case FSAC2021_V1_IN_Move:
      /* During 'Move': '<S129>:233' */
      switch (FSAC2021_V1_DW.bitsForTID6.is_Move) {
       case FSAC2021_V1_IN_Goto:
        /* Outputs for Function Call SubSystem: '<S11>/MOTEC_CONTROL' */

        /* During 'Goto': '<S129>:13' */
        /* Event: '<S129>:165' */
        FSAC2021_V1_MOTEC_CONTROL(FSAC2021_V1_B.DataTypeConversion7,
          FSAC2021_V1_B.DataTypeConversion8, FSAC2021_V1_B.DataTypeConversion3,
          FSAC2021_V1_B.DataTypeConversion6, FSAC2021_V1_B.DataTypeConversion5,
          FSAC2021_V1_B.DataTypeConversion2, FSAC2021_V1_B.DataTypeConversion4,
          FSAC2021_V1_B.DataTypeConversion9, FSAC2021_V1_B.UnitDelay8,
          &FSAC2021_V1_B.MOTEC_CONTROL);

        /* End of Outputs for SubSystem: '<S11>/MOTEC_CONTROL' */
        FSAC2021_V1_B.Fault_Resrt = 0.0;
        FSAC2021_V1_B.Enable_Operation_Ctrl = 1U;

        /* 允许操作。 */
        if (FSAC2021_V1_DW.bitsForTID6.is_Goto ==
            FSAC2021__IN_Origin_Aciton_Move) {
          /* During 'Origin_Aciton_Move': '<S129>:27' */
          if ((real32_T)fabs(Back_Angle) <= 2.0F) {
            /* Transition: '<S129>:217' */
            FSAC2021_V1_DW.bitsForTID6.is_Goto = FSAC2021_V_IN_NO_ACTIVE_CHILD_b;
            FSAC2021_V1_DW.bitsForTID6.is_Move = FSAC2021_V1_IN_Wait;
            FSAC2021_V1_DW.temporalCounter_i1_m = 0U;
          } else {
            /* Transition: '<S129>:216' */
            FSAC2021_V1_DW.bitsForTID6.is_Goto = FSAC2021_V1_IN_Origin_Pos_Set;

            /* Entry 'Origin_Pos_Set': '<S129>:25' */
            FSAC2021_V1_B.Position_set = Back_Angle;

            /* 电机回位角度赋值。 */
            FSAC2021_V1_B.New_Set_Point_Ctrl = 0U;
          }
        } else {
          /* During 'Origin_Pos_Set': '<S129>:25' */
          /* Transition: '<S129>:215' */
          FSAC2021_V1_DW.bitsForTID6.is_Goto = FSAC2021__IN_Origin_Aciton_Move;

          /* Entry 'Origin_Aciton_Move': '<S129>:27' */
          FSAC2021_V1_B.New_Set_Point_Ctrl = 1U;

          /* 设置新位置点。 */
          FSAC2021_V1_B.Abs_or_Rel_Ctrl = 0U;

          /* 相对位置移动。 */
        }
        break;

       case FSAC2021_V1_IN_Motor_Enable:
        /* Outputs for Function Call SubSystem: '<S11>/MOTEC_CONTROL' */

        /* During 'Motor_Enable': '<S129>:65' */
        /* Event: '<S129>:165' */
        FSAC2021_V1_MOTEC_CONTROL(FSAC2021_V1_B.DataTypeConversion7,
          FSAC2021_V1_B.DataTypeConversion8, FSAC2021_V1_B.DataTypeConversion3,
          FSAC2021_V1_B.DataTypeConversion6, FSAC2021_V1_B.DataTypeConversion5,
          FSAC2021_V1_B.DataTypeConversion2, FSAC2021_V1_B.DataTypeConversion4,
          FSAC2021_V1_B.DataTypeConversion9, FSAC2021_V1_B.UnitDelay8,
          &FSAC2021_V1_B.MOTEC_CONTROL);

        /* End of Outputs for SubSystem: '<S11>/MOTEC_CONTROL' */
        if (FSAC2021_V1_DW.bitsForTID6.is_Motor_Enable == FSAC2021_V1_IN_First)
        {
          /* During 'First': '<S129>:60' */
          /* Transition: '<S129>:63' */
          FSAC2021_V1_DW.bitsForTID6.is_Motor_Enable = FSAC2021_V1_IN_Second;

          /* Entry 'Second': '<S129>:61' */
          FSAC2021_V1_B.Switch_On_Ctrl = 1U;

          /*  伺服使能 */
        } else {
          /* During 'Second': '<S129>:61' */
          /* Transition: '<S129>:14' */
          FSAC2021_V1_DW.bitsForTID6.is_Motor_Enable =
            FSAC2021_V_IN_NO_ACTIVE_CHILD_b;
          FSAC2021_V1_DW.bitsForTID6.is_Move = FSAC2021_V1_IN_Goto;

          /* Entry Internal 'Goto': '<S129>:13' */
          /* Transition: '<S129>:185' */
          FSAC2021_V1_DW.bitsForTID6.is_Goto = FSAC2021_V1_IN_Origin_Pos_Set;

          /* Entry 'Origin_Pos_Set': '<S129>:25' */
          FSAC2021_V1_B.Position_set = Back_Angle;

          /* 电机回位角度赋值。 */
          FSAC2021_V1_B.New_Set_Point_Ctrl = 0U;
        }
        break;

       case FSAC2021_V1_IN_Motor_Move:
        /* Outputs for Function Call SubSystem: '<S11>/MOTEC_CONTROL' */

        /* During 'Motor_Move': '<S129>:39' */
        /* Event: '<S129>:165' */
        FSAC2021_V1_MOTEC_CONTROL(FSAC2021_V1_B.DataTypeConversion7,
          FSAC2021_V1_B.DataTypeConversion8, FSAC2021_V1_B.DataTypeConversion3,
          FSAC2021_V1_B.DataTypeConversion6, FSAC2021_V1_B.DataTypeConversion5,
          FSAC2021_V1_B.DataTypeConversion2, FSAC2021_V1_B.DataTypeConversion4,
          FSAC2021_V1_B.DataTypeConversion9, FSAC2021_V1_B.UnitDelay8,
          &FSAC2021_V1_B.MOTEC_CONTROL);

        /* End of Outputs for SubSystem: '<S11>/MOTEC_CONTROL' */
        enflag = 1.0;
        if (FSAC2021_V1_DW.bitsForTID6.is_Motor_Move ==
            FSAC2021_V1_IN_Aciton_Move) {
          /* During 'Aciton_Move': '<S129>:41' */
          /* Transition: '<S129>:43' */
          FSAC2021_V1_DW.bitsForTID6.is_Motor_Move =
            FSAC2021_V_IN_Move_Position_Set;

          /* Entry 'Move_Position_Set': '<S129>:36' */
          FSAC2021_V1_B.Enable_Operation_Ctrl = 1U;

          /* 允许操作。 */
          FSAC2021_V1_B.Position_set = (real32_T)Str;

          /* 期望电机角度赋值 */
          FSAC2021_V1_B.New_Set_Point_Ctrl = 0U;
          FSAC2021_V1_B.Abs_or_Rel_Ctrl = 0U;

          /* 相对位置移动。 */
        } else {
          /* During 'Move_Position_Set': '<S129>:36' */
          /* Transition: '<S129>:42' */
          FSAC2021_V1_DW.bitsForTID6.is_Motor_Move = FSAC2021_V1_IN_Aciton_Move;

          /* Entry 'Aciton_Move': '<S129>:41' */
          FSAC2021_V1_B.New_Set_Point_Ctrl = 1U;

          /* 设置新位置点。 */
          FSAC2021_V1_B.Abs_or_Rel_Ctrl = 1U;

          /* 绝对位置移动。 */
        }
        break;

       case FSAC2021_V1_IN_Motor_Stanby:
        /* Outputs for Function Call SubSystem: '<S11>/MOTEC_ENCODER1' */
        /* Saturate: '<S43>/Str_Encoder1_sat' incorporates:
         *  UnitDelay: '<S11>/Unit Delay11'
         */
        /* During 'Motor_Stanby': '<S129>:35' */
        /* Event: '<S129>:166' */
        if (FSAC2021_V1_DW.UnitDelay11_DSTATE > 255.0F) {
          rtb_RateTransition46 = 255.0F;
        } else if (FSAC2021_V1_DW.UnitDelay11_DSTATE < 0.0F) {
          rtb_RateTransition46 = 0.0F;
        } else {
          rtb_RateTransition46 = FSAC2021_V1_DW.UnitDelay11_DSTATE;
        }

        /* DataTypeConversion: '<S27>/Conv1' incorporates:
         *  DataTypeConversion: '<S43>/Str_Encoder1_Convert'
         *  DataTypeConversion: '<S43>/Str_Encoder1_Convert1'
         *  Rounding: '<S43>/Str_Encoder1Ron'
         *  S-Function (sfix_bitop): '<S43>/Str_Encoder1_L'
         *  Saturate: '<S43>/Str_Encoder1_1sat'
         *  Saturate: '<S43>/Str_Encoder1_sat'
         */
        FSAC2021_V1_B.Conv1 = (uint8_T)((uint32_T)rt_roundf_snf
          (rtb_RateTransition46) & 255U);

        /* Saturate: '<S44>/Str_Encoder2_sat' incorporates:
         *  UnitDelay: '<S11>/Unit Delay12'
         */
        if (FSAC2021_V1_DW.UnitDelay12_DSTATE > 255.0F) {
          rtb_RateTransition46 = 255.0F;
        } else if (FSAC2021_V1_DW.UnitDelay12_DSTATE < 0.0F) {
          rtb_RateTransition46 = 0.0F;
        } else {
          rtb_RateTransition46 = FSAC2021_V1_DW.UnitDelay12_DSTATE;
        }

        /* DataTypeConversion: '<S27>/Conv2' incorporates:
         *  DataTypeConversion: '<S44>/Str_Encoder2_Convert'
         *  DataTypeConversion: '<S44>/Str_Encoder2_Convert1'
         *  Rounding: '<S44>/Str_Encoder2Ron'
         *  S-Function (sfix_bitop): '<S44>/Str_Encoder2_L'
         *  Saturate: '<S44>/Str_Encoder2_1sat'
         *  Saturate: '<S44>/Str_Encoder2_sat'
         */
        FSAC2021_V1_B.Conv2 = (uint8_T)((uint32_T)rt_roundf_snf
          (rtb_RateTransition46) & 255U);

        /* Saturate: '<S45>/Str_Encoder3_sat' incorporates:
         *  UnitDelay: '<S11>/Unit Delay13'
         */
        if (FSAC2021_V1_DW.UnitDelay13_DSTATE > 255.0F) {
          rtb_RateTransition46 = 255.0F;
        } else if (FSAC2021_V1_DW.UnitDelay13_DSTATE < 0.0F) {
          rtb_RateTransition46 = 0.0F;
        } else {
          rtb_RateTransition46 = FSAC2021_V1_DW.UnitDelay13_DSTATE;
        }

        /* DataTypeConversion: '<S27>/Conv3' incorporates:
         *  DataTypeConversion: '<S45>/Str_Encoder3_Convert'
         *  DataTypeConversion: '<S45>/Str_Encoder3_Convert1'
         *  Rounding: '<S45>/Str_Encoder3Ron'
         *  S-Function (sfix_bitop): '<S45>/Str_Encoder3_L'
         *  Saturate: '<S45>/Str_Encoder3_1sat'
         *  Saturate: '<S45>/Str_Encoder3_sat'
         */
        FSAC2021_V1_B.Conv3 = (uint8_T)((uint32_T)rt_roundf_snf
          (rtb_RateTransition46) & 255U);

        /* Saturate: '<S46>/Str_Encoder4_sat' incorporates:
         *  UnitDelay: '<S11>/Unit Delay14'
         */
        if (FSAC2021_V1_DW.UnitDelay14_DSTATE > 255.0F) {
          rtb_RateTransition46 = 255.0F;
        } else if (FSAC2021_V1_DW.UnitDelay14_DSTATE < 0.0F) {
          rtb_RateTransition46 = 0.0F;
        } else {
          rtb_RateTransition46 = FSAC2021_V1_DW.UnitDelay14_DSTATE;
        }

        /* DataTypeConversion: '<S27>/Conv4' incorporates:
         *  DataTypeConversion: '<S46>/Str_Encoder4_Convert'
         *  DataTypeConversion: '<S46>/Str_Encoder4_Convert1'
         *  Rounding: '<S46>/Str_Encoder4Ron'
         *  S-Function (sfix_bitop): '<S46>/Str_Encoder4_L'
         *  Saturate: '<S46>/Str_Encoder4_1sat'
         *  Saturate: '<S46>/Str_Encoder4_sat'
         */
        FSAC2021_V1_B.Conv4 = (uint8_T)((uint32_T)rt_roundf_snf
          (rtb_RateTransition46) & 255U);

        /* End of Outputs for SubSystem: '<S11>/MOTEC_ENCODER1' */

        /* Switch: '<S11>/Switch' incorporates:
         *  Constant: '<S25>/Constant'
         *  RelationalOperator: '<S25>/Compare'
         *  UnitDelay: '<S11>/Unit Delay15'
         *  UnitDelay: '<S11>/Unit Delay17'
         */
        if (rtb_RateTransition24_e >= 3) {
          rtb_RateTransition24_e = FSAC2021_V1_DW.UnitDelay17_DSTATE;
        } else {
          rtb_RateTransition24_e = FSAC2021_V1_DW.UnitDelay15_DSTATE;
        }

        /* End of Switch: '<S11>/Switch' */

        /* Outputs for Function Call SubSystem: '<S11>/MOTEC_ENCODER1' */
        /* DataTypeConversion: '<S27>/Conv5' incorporates:
         *  DataTypeConversion: '<S47>/Str_Encoder5_Convert'
         *  Rounding: '<S47>/Str_Encoder5Ron'
         *  Saturate: '<S47>/Str_Encoder5_1sat'
         *  Sum: '<S47>/Str_Encoder5_st'
         */
        FSAC2021_V1_B.Conv5 = (uint8_T)rt_roundf_snf((real32_T)
          rtb_RateTransition24_e);

        /* Saturate: '<S48>/Str_Encoder6_sat' incorporates:
         *  UnitDelay: '<S11>/Unit Delay16'
         */
        if (FSAC2021_V1_DW.UnitDelay16_DSTATE > 255.0F) {
          rtb_RateTransition46 = 255.0F;
        } else if (FSAC2021_V1_DW.UnitDelay16_DSTATE < 0.0F) {
          rtb_RateTransition46 = 0.0F;
        } else {
          rtb_RateTransition46 = FSAC2021_V1_DW.UnitDelay16_DSTATE;
        }

        /* DataTypeConversion: '<S27>/Conv6' incorporates:
         *  DataTypeConversion: '<S48>/Str_Encoder6_Convert'
         *  DataTypeConversion: '<S48>/Str_Encoder6_Convert1'
         *  Rounding: '<S48>/Str_Encoder6Ron'
         *  S-Function (sfix_bitop): '<S48>/Str_Encoder6_L'
         *  Saturate: '<S48>/Str_Encoder6_1sat'
         *  Saturate: '<S48>/Str_Encoder6_sat'
         */
        FSAC2021_V1_B.Conv6 = (uint8_T)((uint32_T)rt_roundf_snf
          (rtb_RateTransition46) & 255U);

        /* End of Outputs for SubSystem: '<S11>/MOTEC_ENCODER1' */
        FSAC2021_V1_B.Original_Flag = 1.0;

        /* During 'Encoder1': '<S129>:69' */
        if (rtb_RateTransition60 == 3) {
          /* Transition: '<S129>:37' */
          /* Exit 'Encoder1': '<S129>:69' */
          FSAC2021_V1_B.Encoder_Msg_Data[4] = (uint8_T)0x00;
          FSAC2021_V1_DW.bitsForTID6.is_Motor_Stanby =
            FSAC2021_V_IN_NO_ACTIVE_CHILD_b;
          FSAC2021_V1_DW.bitsForTID6.is_Move = FSAC2021_V1_IN_Motor_Move;

          /* Entry Internal 'Motor_Move': '<S129>:39' */
          /* Transition: '<S129>:79' */
          FSAC2021_V1_DW.bitsForTID6.is_Motor_Move =
            FSAC2021_V_IN_Move_Position_Set;

          /* Entry 'Move_Position_Set': '<S129>:36' */
          FSAC2021_V1_B.Enable_Operation_Ctrl = 1U;

          /* 允许操作。 */
          FSAC2021_V1_B.Position_set = (real32_T)Str;

          /* 期望电机角度赋值 */
          FSAC2021_V1_B.New_Set_Point_Ctrl = 0U;
          FSAC2021_V1_B.Abs_or_Rel_Ctrl = 0U;

          /* 相对位置移动。 */
        } else {
          FSAC2021_V1_B.Encoder_Msg_Data[0] = (uint8_T)0x2B;
          FSAC2021_V1_B.Encoder_Msg_Data[1] = (uint8_T)0x04;

          /* 2004对象字典 */
          FSAC2021_V1_B.Encoder_Msg_Data[2] = (uint8_T)0x20;
          FSAC2021_V1_B.Encoder_Msg_Data[3] = (uint8_T)0x00;
          FSAC2021_V1_B.Encoder_Msg_Data[4] = (uint8_T)0x01;

          /* 编码器清零标志位为1 */
          FSAC2021_V1_B.Encoder_Msg_Data[5] = (uint8_T)0x00;

          /* 编码器清零标志位为0 */
        }
        break;

       default:
        /* During 'Wait': '<S129>:238' */
        if ((real32_T)fabs(Back_Angle) > 2.0F) {
          /* Transition: '<S129>:240' */
          FSAC2021_V1_DW.bitsForTID6.is_Move = FSAC2021_V1_IN_Goto;
          FSAC2021_V1_DW.bitsForTID6.is_Goto = FSAC2021__IN_Origin_Aciton_Move;

          /* Entry 'Origin_Aciton_Move': '<S129>:27' */
          FSAC2021_V1_B.New_Set_Point_Ctrl = 1U;

          /* 设置新位置点。 */
          FSAC2021_V1_B.Abs_or_Rel_Ctrl = 0U;

          /* 相对位置移动。 */
        } else {
          if (FSAC2021_V1_DW.temporalCounter_i1_m >= 10U) {
            /* Transition: '<S129>:241' */
            FSAC2021_V1_DW.bitsForTID6.is_Move = FSAC2021_V1_IN_Motor_Stanby;

            /* Entry Internal 'Motor_Stanby': '<S129>:35' */
            /* Transition: '<S129>:171' */
            FSAC2021_V1_DW.bitsForTID6.is_Motor_Stanby = FSAC2021_V1_IN_Encoder1;
          }
        }
        break;
      }
      break;

     default:
      /* During 'Pre_Operation_Mode': '<S129>:1' */
      if (rtb_RateTransition59 != 0) {
        /* Transition: '<S129>:8' */
        FSAC2021_V1_DW.bitsForTID6.is_c14_FSAC2021_V1 = FSAC2021_V1_IN_Move;

        /* Entry Internal 'Move': '<S129>:233' */
        /* Transition: '<S129>:80' */
        FSAC2021_V1_DW.bitsForTID6.is_Move = FSAC2021_V1_IN_Motor_Enable;

        /* Entry Internal 'Motor_Enable': '<S129>:65' */
        /* Transition: '<S129>:64' */
        FSAC2021_V1_DW.bitsForTID6.is_Motor_Enable = FSAC2021_V1_IN_First;

        /* Entry 'First': '<S129>:60' */
        FSAC2021_V1_B.Switch_On_Ctrl = 0U;

        /*   */
        FSAC2021_V1_B.Enable_Voltage_Ctrl = 1U;

        /* 允许通电。 */
        FSAC2021_V1_B.Quick_Stop_Ctrl = 1U;

        /* 禁用快速停止。 */
      } else {
        /* Outputs for Function Call SubSystem: '<S11>/MOTEC_NMT' */
        /* DataTypeConversion: '<S28>/Conv1' incorporates:
         *  DataTypeConversion: '<S11>/Data Type Conversion'
         *  DataTypeConversion: '<S50>/NMT_nodeorder_Convert'
         *  Rounding: '<S50>/NMT_nodeorderRon'
         *  Saturate: '<S50>/NMT_nodeorder_1sat'
         *  Saturate: '<S50>/NMT_nodeorder_sat'
         *  UnitDelay: '<S11>/Unit Delay10'
         */
        /* 连接所有节点。 */
        /* Event: '<S129>:164' */
        FSAC2021_V1_B.Conv1_p = (uint8_T)rt_roundf_snf((real32_T)
          FSAC2021_V1_DW.UnitDelay10_DSTATE);

        /* DataTypeConversion: '<S28>/Conv2' incorporates:
         *  DataTypeConversion: '<S11>/Data Type Conversion1'
         *  DataTypeConversion: '<S49>/NMT_nodectrl_Convert'
         *  Rounding: '<S49>/NMT_nodectrlRon'
         *  Saturate: '<S49>/NMT_nodectrl_1sat'
         *  Saturate: '<S49>/NMT_nodectrl_sat'
         *  UnitDelay: '<S11>/Unit Delay9'
         */
        FSAC2021_V1_B.Conv2_l = (uint8_T)rt_roundf_snf((real32_T)
          FSAC2021_V1_DW.UnitDelay9_DSTATE);

        /* End of Outputs for SubSystem: '<S11>/MOTEC_NMT' */
      }
      break;
    }
  }

  /* End of Chart: '<S67>/Chart' */

  /* S-Function (fcncallgen): '<S7>/Function-Call Generator1' incorporates:
   *  SubSystem: '<S9>/Read_VCU_Freq(WheelSpeed)'
   */

  /* S-Function (ec55xx_ffrslb): '<S404>/Read_RL_WhlSpd' */

  /* Read the last frequency */
  FSAC2021_V1_B.Read_RL_WhlSpd= ec_etpu_get_ppa_freq(13);

  /* S-Function (ec55xx_ffrslb): '<S404>/Read_RR_WhlSpd' */

  /* Read the last frequency */
  FSAC2021_V1_B.Read_RR_WhlSpd= ec_etpu_get_ppa_freq(14);

  /* S-Function (fcncallgen): '<S7>/Function-Call Generator1' incorporates:
   *  SubSystem: '<S2>/BCU_Controller'
   */
  /* Chart: '<S66>/BCU_Strategy' */
  FSAC2021_V1_DW.presentTicks_c = FSAC2021_V1_M->Timing.clockTick6;
  FSAC2021_V1_DW.elapsedTicks_f = FSAC2021_V1_DW.presentTicks_c -
    FSAC2021_V1_DW.previousTicks_ip;
  FSAC2021_V1_DW.previousTicks_ip = FSAC2021_V1_DW.presentTicks_c;
  if (FSAC2021_V1_DW.temporalCounter_i1_ol + FSAC2021_V1_DW.elapsedTicks_f <=
      15U) {
    FSAC2021_V1_DW.temporalCounter_i1_ol = (uint8_T)
      (FSAC2021_V1_DW.temporalCounter_i1_ol + FSAC2021_V1_DW.elapsedTicks_f);
  } else {
    FSAC2021_V1_DW.temporalCounter_i1_ol = 15U;
  }

  /* Gateway: Controller/BCU_Controller/BCU_Strategy */
  /* During: Controller/BCU_Controller/BCU_Strategy */
  if (FSAC2021_V1_DW.bitsForTID6.is_active_c22_FSAC2021_V1 == 0U) {
    /* Entry: Controller/BCU_Controller/BCU_Strategy */
    FSAC2021_V1_DW.bitsForTID6.is_active_c22_FSAC2021_V1 = 1U;

    /* Entry Internal: Controller/BCU_Controller/BCU_Strategy */
    /* Transition: '<S120>:38' */
    FSAC2021_V1_DW.bitsForTID6.is_c22_FSAC2021_V1 = FSAC2021_V1_IN_Idle;
  } else if (FSAC2021_V1_DW.bitsForTID6.is_c22_FSAC2021_V1 ==
             FSAC2021_V1_IN_Idle) {
    /* During 'Idle': '<S120>:63' */
    /* Transition: '<S120>:31' */
    FSAC2021_V1_DW.bitsForTID6.is_c22_FSAC2021_V1 = FSAC2021_V1_IN_RunMode;

    /* Entry Internal 'RunMode': '<S120>:9' */
    /* Transition: '<S120>:64' */
    FSAC2021_V1_DW.bitsForTID6.is_RunMode = FSAC2021_V1_IN_Init_g;

    /* Entry 'Init': '<S120>:1' */
    /* Event: '<S120>:58' */
    /* /制动电机使能 */
  } else {
    /* During 'RunMode': '<S120>:9' */
    switch (FSAC2021_V1_DW.bitsForTID6.is_RunMode) {
     case FSAC2021_V1_IN_BackOrigin:
      /* During 'BackOrigin': '<S120>:6' */
      if (rtb_RateTransition57 == 3) {
        /* Transition: '<S120>:86' */
        FSAC2021_V1_DW.bitsForTID6.is_RunMode = FSAC2021_V1_IN_Tozeros;
        FSAC2021_V1_DW.temporalCounter_i1_ol = 0U;

        /* Entry 'Tozeros': '<S120>:88' */
        FSAC2021_V1_B.Brk_Ctrl_State = 2U;

        /* 制动回位 */
      }
      break;

     case FSAC2021_V1_IN_Init_g:
      /* During 'Init': '<S120>:1' */
      if ((Brk_Enable_Flag != 0) && (rtb_RateTransition57 == 2)) {
        /* Transition: '<S120>:8' */
        FSAC2021_V1_DW.bitsForTID6.is_RunMode = FSAC2021_V1_IN_BackOrigin;

        /* Entry 'BackOrigin': '<S120>:6' */
        /* Event: '<S120>:11' */
        /* /转向电机回位 */
        FSAC2021_V1_B.Brk_Ctrl_State = 1U;

        /* 制动占用 */
      }
      break;

     case FSAC2021_V1_IN_Move_k:
      /* During 'Move': '<S120>:75' */
      break;

     default:
      /* During 'Tozeros': '<S120>:88' */
      if (FSAC2021_V1_DW.temporalCounter_i1_ol >= 10U) {
        /* Transition: '<S120>:89' */
        FSAC2021_V1_DW.bitsForTID6.is_RunMode = FSAC2021_V1_IN_Move_k;

        /* Entry 'Move': '<S120>:75' */
        FSAC2021_V1_B.Allow_Ctrl_Flg = 1U;
        FSAC2021_V1_B.Brk_Ctrl_State = 3U;
      }
      break;
    }
  }

  /* End of Chart: '<S66>/BCU_Strategy' */

  /* Outputs for Enabled SubSystem: '<S121>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S123>/Enable'
   */
  /* RelationalOperator: '<S121>/Equal' incorporates:
   *  Constant: '<S121>/Constant'
   */
  if (FSAC2021_V1_B.Brk_Ctrl_State == 1) {
    /* Outputs for Atomic SubSystem: '<S123>/Angle2Pulses' */
    FSAC2021_V1_Angle2Pulses(&FSAC2021_V1_B.Angle2Pulses,
      (ConstB_Angle2Pulses_FSAC2021__T *)&FSAC2021_V1_ConstB.Angle2Pulses);

    /* End of Outputs for SubSystem: '<S123>/Angle2Pulses' */

    /* SignalConversion: '<S123>/OutportBufferForEngaged_Angle' */
    FSAC2021_V1_B.OutportBufferForEngaged_Angle = 8;
  }

  /* End of RelationalOperator: '<S121>/Equal' */
  /* End of Outputs for SubSystem: '<S121>/Enabled Subsystem' */

  /* Outputs for Enabled SubSystem: '<S121>/Enabled Subsystem1' incorporates:
   *  EnablePort: '<S124>/Enable'
   */
  /* RelationalOperator: '<S121>/Equal1' incorporates:
   *  Constant: '<S121>/Constant1'
   */
  if (FSAC2021_V1_B.Brk_Ctrl_State == 2) {
    /* Gain: '<S124>/Gain' */
    rtb_Gain_p = FSAC2021_V1_B.OutportBufferForEngaged_Angle;

    /* Outputs for Atomic SubSystem: '<S124>/Angle2Pulses' */
    FSAC2021_V1_Angle2Pulses_p(rtb_Gain_p, &FSAC2021_V1_B.Angle2Pulses_p);

    /* End of Outputs for SubSystem: '<S124>/Angle2Pulses' */
  }

  /* End of RelationalOperator: '<S121>/Equal1' */
  /* End of Outputs for SubSystem: '<S121>/Enabled Subsystem1' */

  /* RelationalOperator: '<S121>/Equal2' incorporates:
   *  Constant: '<S121>/Constant2'
   */
  rtb_Equal2 = (FSAC2021_V1_B.Brk_Ctrl_State == 3);

  /* Outputs for Enabled SubSystem: '<S121>/Enabled Subsystem2' incorporates:
   *  EnablePort: '<S125>/Enable'
   */
  if (rtb_Equal2) {
    /* Gain: '<S125>/Gain' */
    rtb_Gain = (real32_T)-FSAC2021_V1_B.Switch1;

    /* Outputs for Atomic SubSystem: '<S125>/Angle2Pulses' */
    FSAC2021_V1_Angle2Pulses_b(rtb_Gain, &FSAC2021_V1_B.Angle2Pulses_b);

    /* End of Outputs for SubSystem: '<S125>/Angle2Pulses' */
  }

  /* End of Outputs for SubSystem: '<S121>/Enabled Subsystem2' */

  /* MultiPortSwitch: '<S121>/Multiport Switch' */
  switch (FSAC2021_V1_B.Brk_Ctrl_State) {
   case 1:
    MultiportSwitch = FSAC2021_V1_B.Angle2Pulses.DataTypeConversion;
    break;

   case 2:
    MultiportSwitch = FSAC2021_V1_B.Angle2Pulses_p.DataTypeConversion;
    break;

   default:
    MultiportSwitch = FSAC2021_V1_B.Angle2Pulses_b.DataTypeConversion;
    break;
  }

  /* End of MultiPortSwitch: '<S121>/Multiport Switch' */

  /* S-Function (fcncallgen): '<S7>/Function-Call Generator1' incorporates:
   *  SubSystem: '<S2>/50ms_Duty'
   */
  /* RelationalOperator: '<S97>/Compare' incorporates:
   *  Constant: '<S97>/Constant'
   */
  Compare_Voltage = (Read_compare_OutVolt >= 2.0F);

  /* DataTypeConversion: '<S85>/Data Type Conversion' incorporates:
   *  Logic: '<S85>/Logical Operator'
   *  Logic: '<S85>/Logical Operator1'
   *  Logic: '<S85>/Logical Operator4'
   */
  TS_Flag = (uint8_T)(Compare_Voltage && ((FSAC2021_V1_B.DataTypeConversion26_g
    != 0) && (FSAC2021_V1_B.DataTypeConversion1_j != 0) &&
    ((FSAC2021_V1_B.DataTypeConversion15 != 0) ||
     (FSAC2021_V1_B.DataTypeConversion24_ki != 0))));

  /* DataTypeConversion: '<S65>/Data Type Conversion' incorporates:
   *  UnitDelay: '<S65>/Unit Delay1'
   */
  rtb_RateTransition59 = (uint8_T)FSAC2021_V1_DW.UnitDelay1_DSTATE;

  /* Chart: '<S65>/AS_Machine' incorporates:
   *  UnitDelay: '<S65>/Unit Delay5'
   */
  FSAC2021_V1_DW.presentTicks_p = FSAC2021_V1_M->Timing.clockTick6;
  FSAC2021_V1_DW.elapsedTicks_k = FSAC2021_V1_DW.presentTicks_p -
    FSAC2021_V1_DW.previousTicks_i;
  FSAC2021_V1_DW.previousTicks_i = FSAC2021_V1_DW.presentTicks_p;
  if (FSAC2021_V1_DW.temporalCounter_i1_h + FSAC2021_V1_DW.elapsedTicks_k <=
      127U) {
    FSAC2021_V1_DW.temporalCounter_i1_h = (uint8_T)
      (FSAC2021_V1_DW.temporalCounter_i1_h + FSAC2021_V1_DW.elapsedTicks_k);
  } else {
    FSAC2021_V1_DW.temporalCounter_i1_h = 127U;
  }

  /* Gateway: Controller/50ms_Duty/AS_Machine */
  /* During: Controller/50ms_Duty/AS_Machine */
  if (FSAC2021_V1_DW.bitsForTID6.is_active_c3_FSAC2021_V1 == 0U) {
    /* Entry: Controller/50ms_Duty/AS_Machine */
    FSAC2021_V1_DW.bitsForTID6.is_active_c3_FSAC2021_V1 = 1U;

    /* Entry Internal: Controller/50ms_Duty/AS_Machine */
    /* Transition: '<S83>:85' */
    FSAC2021_V1_DW.bitsForTID6.is_c3_FSAC2021_V1 = FSAC2021_V1_IN_AS_Off;

    /* Entry 'AS_Off': '<S83>:2' */
    FSAC2021_V1_B.ASSI_State = 1U;

    /* System_48V_Relay = DISABLE; */
    FSAC2021_V1_B.Blue_Light = 0U;
    FSAC2021_V1_B.Yellow_Light = 0U;
  } else {
    switch (FSAC2021_V1_DW.bitsForTID6.is_c3_FSAC2021_V1) {
     case FSAC2021_V1_IN_AS_Driving:
      /* During 'AS_Driving': '<S83>:7' */
      if ((rtb_RateTransition11 <= 1.0F) && (FSAC2021_V1_DW.UnitDelay5_DSTATE_h
           != 0)) {
        /* Transition: '<S83>:10' */
        FSAC2021_V1_DW.bitsForTID6.is_c3_FSAC2021_V1 =
          FSAC2021_V1_IN_AS_Finished;

        /* Entry 'AS_Finished': '<S83>:9' */
        FSAC2021_V1_B.ASSI_State = 4U;
        FSAC2021_V1_B.R2D = 0U;
        FSAC2021_V1_B.Safety_Circuit_Relay = 1U;

        /* System_48V_Relay = OFF; */
        FSAC2021_V1_B.Blue_Light = 1U;
        FSAC2021_V1_B.Yellow_Light = 0U;
      }
      break;

     case FSAC2021_V1_IN_AS_Emergency:
      /* During 'AS_Emergency': '<S83>:11' */
      break;

     case FSAC2021_V1_IN_AS_Finished:
      /* During 'AS_Finished': '<S83>:9' */
      if (RES_EBS != 0) {
        /* Transition: '<S83>:14' */
        FSAC2021_V1_DW.bitsForTID6.is_c3_FSAC2021_V1 =
          FSAC2021_V1_IN_AS_Emergency;

        /* Entry 'AS_Emergency': '<S83>:11' */
        FSAC2021_V1_B.ASSI_State = 5U;
        FSAC2021_V1_B.R2D = 0U;
        FSAC2021_V1_B.Yellow_Light = 0U;
        FSAC2021_V1_B.Blue_Light = 2U;
        FSAC2021_V1_B.Buzzer = 2U;
      } else {
        /* Transition: '<S83>:68' */
        if (!(FSAC2021_V1_B.DataTypeConversion4_f != 0)) {
          /* Transition: '<S83>:15' */
          /* Transition: '<S83>:67' */
          FSAC2021_V1_DW.bitsForTID6.is_c3_FSAC2021_V1 = FSAC2021_V1_IN_AS_Off;

          /* Entry 'AS_Off': '<S83>:2' */
          FSAC2021_V1_B.ASSI_State = 1U;

          /* System_48V_Relay = DISABLE; */
          FSAC2021_V1_B.Blue_Light = 0U;
          FSAC2021_V1_B.Yellow_Light = 0U;
        }
      }
      break;

     case FSAC2021_V1_IN_AS_Off:
      /* During 'AS_Off': '<S83>:2' */
      if ((rtb_RateTransition59 == 6) && (TS_Flag != 0) &&
          (!(FSAC2021_V1_B.DataTypeConversion4_f != 0)) &&
          (FSAC2021_V1_B.DataTypeConversion25_m != 0) && FSAC2021_V1_B.Compare)
      {
        /* Transition: '<S83>:16' */
        FSAC2021_V1_DW.bitsForTID6.is_c3_FSAC2021_V1 =
          FSAC2021_V1_IN_Manual_Driving;

        /* Entry 'Manual_Driving': '<S83>:12' */
        FSAC2021_V1_B.R2D = 1U;
        FSAC2021_V1_B.Buzzer = 1U;
        FSAC2021_V1_B.ASSI_State = 6U;
      } else if ((FSAC2021_V1_B.DataTypeConversion19 != 0) &&
                 (FSAC2021_V1_B.DataTypeConversion4_f != 0) && (TS_Flag != 0) &&
                 (rtb_RateTransition59 != 0) && (rtb_RateTransition59 != 6)) {
        /* Transition: '<S83>:5' */
        FSAC2021_V1_DW.bitsForTID6.is_c3_FSAC2021_V1 = FSAC2021_V1_IN_AS_Ready;

        /* Entry Internal 'AS_Ready': '<S83>:3' */
        /* Transition: '<S83>:98' */
        FSAC2021_V1_DW.bitsForTID6.is_AS_Ready = FSAC2021_V1_IN_Init;

        /* Entry 'Init': '<S83>:94' */
        FSAC2021_V1_B.ASSI_State = 2U;

        /* System_48V_Relay = ENABLE; */
      } else {
        /* Outputs for Function Call SubSystem: '<S65>/Visuality Check' */
        /* Chart: '<S95>/Chart' */
        /* VCU_Valve = ON; */
        /* Event: '<S83>:79' */
        /* Event: '<S83>:87' */
        FSAC2021_V1_DW.presentTicks_n = FSAC2021_V1_M->Timing.clockTick6;
        FSAC2021_V1_DW.elapsedTicks_d = FSAC2021_V1_DW.presentTicks_n -
          FSAC2021_V1_DW.previousTicks_l;
        FSAC2021_V1_DW.previousTicks_l = FSAC2021_V1_DW.presentTicks_n;
        if (FSAC2021_V1_DW.temporalCounter_i1_e + FSAC2021_V1_DW.elapsedTicks_d <=
            63U) {
          FSAC2021_V1_DW.temporalCounter_i1_e = (uint8_T)
            (FSAC2021_V1_DW.temporalCounter_i1_e + FSAC2021_V1_DW.elapsedTicks_d);
        } else {
          FSAC2021_V1_DW.temporalCounter_i1_e = 63U;
        }

        /* Gateway: Controller/50ms_Duty/Visuality Check/Chart */
        /* During: Controller/50ms_Duty/Visuality Check/Chart */
        if (FSAC2021_V1_DW.bitsForTID6.is_active_c2_FSAC2021_V1 == 0U) {
          /* Entry: Controller/50ms_Duty/Visuality Check/Chart */
          FSAC2021_V1_DW.bitsForTID6.is_active_c2_FSAC2021_V1 = 1U;

          /* Entry Internal: Controller/50ms_Duty/Visuality Check/Chart */
          /* Transition: '<S119>:2' */
          FSAC2021_V1_DW.bitsForTID6.is_c2_FSAC2021_V1 =
            FSAC2021_V1_IN_Visuality_On;
          FSAC2021_V1_DW.temporalCounter_i1_e = 0U;

          /* Entry 'Visuality_On': '<S119>:1' */
          FSAC2021_V1_B.Visual_Lights[0] = 1U;
          FSAC2021_V1_B.Visual_Lights[1] = 1U;
          FSAC2021_V1_B.Visual_Lights[2] = 1U;
          FSAC2021_V1_B.Visual_Flag = 1U;
        } else if ((FSAC2021_V1_DW.bitsForTID6.is_c2_FSAC2021_V1 !=
                    FSAC2021_V1_IN_Visuality_Off) &&
                   (FSAC2021_V1_DW.temporalCounter_i1_e >= 40U)) {
          /* During 'Visuality_On': '<S119>:1' */
          /* Transition: '<S119>:4' */
          FSAC2021_V1_DW.bitsForTID6.is_c2_FSAC2021_V1 =
            FSAC2021_V1_IN_Visuality_Off;

          /* Entry 'Visuality_Off': '<S119>:3' */
          FSAC2021_V1_B.Visual_Lights[0] = 0U;
          FSAC2021_V1_B.Visual_Lights[1] = 0U;
          FSAC2021_V1_B.Visual_Lights[2] = 0U;
          FSAC2021_V1_B.Visual_Flag = 0U;
        } else {
          /* During 'Visuality_Off': '<S119>:3' */
        }

        /* End of Chart: '<S95>/Chart' */
        /* End of Outputs for SubSystem: '<S65>/Visuality Check' */
      }
      break;

     case FSAC2021_V1_IN_AS_Ready:
      /* During 'AS_Ready': '<S83>:3' */
      if (!(FSAC2021_V1_B.DataTypeConversion4_f != 0)) {
        /* Transition: '<S83>:6' */
        /* Exit Internal 'AS_Ready': '<S83>:3' */
        FSAC2021_V1_DW.bitsForTID6.is_AS_Ready = FSAC2021_V_IN_NO_ACTIVE_CHILD_b;
        FSAC2021_V1_DW.bitsForTID6.is_c3_FSAC2021_V1 = FSAC2021_V1_IN_AS_Off;

        /* Entry 'AS_Off': '<S83>:2' */
        FSAC2021_V1_B.ASSI_State = 1U;

        /* System_48V_Relay = DISABLE; */
        FSAC2021_V1_B.Blue_Light = 0U;
        FSAC2021_V1_B.Yellow_Light = 0U;
      } else if (FSAC2021_V1_DW.bitsForTID6.is_AS_Ready == FSAC2021_V1_IN_Init)
      {
        /* During 'Init': '<S83>:94' */
        if (rtb_UnitDelay7 == 1.0) {
          /* Transition: '<S83>:96' */
          FSAC2021_V1_DW.bitsForTID6.is_AS_Ready = FSAC2021_V1_IN_Origin;
          FSAC2021_V1_DW.temporalCounter_i1_h = 0U;

          /* Entry 'Origin': '<S83>:93' */
          FSAC2021_V1_B.Yellow_Light = 1U;
          FSAC2021_V1_B.Blue_Light = 0U;
        }
      } else {
        /* During 'Origin': '<S83>:93' */
        if ((FSAC2021_V1_DW.temporalCounter_i1_h >= 100U) &&
            (rtb_RateTransition25_f != 0)) {
          /* Transition: '<S83>:8' */
          FSAC2021_V1_DW.bitsForTID6.is_AS_Ready =
            FSAC2021_V_IN_NO_ACTIVE_CHILD_b;
          FSAC2021_V1_DW.bitsForTID6.is_c3_FSAC2021_V1 =
            FSAC2021_V1_IN_AS_Driving;

          /* Entry 'AS_Driving': '<S83>:7' */
          FSAC2021_V1_B.R2D = 1U;
          FSAC2021_V1_B.ASSI_State = 3U;
          FSAC2021_V1_B.Yellow_Light = 2U;
          FSAC2021_V1_B.Blue_Light = 0U;
          FSAC2021_V1_B.Buzzer = 1U;
        }
      }
      break;

     default:
      /* During 'Manual_Driving': '<S83>:12' */
      if (!(TS_Flag != 0)) {
        /* Transition: '<S83>:17' */
        FSAC2021_V1_DW.bitsForTID6.is_c3_FSAC2021_V1 = FSAC2021_V1_IN_AS_Off;

        /* Entry 'AS_Off': '<S83>:2' */
        FSAC2021_V1_B.ASSI_State = 1U;

        /* System_48V_Relay = DISABLE; */
        FSAC2021_V1_B.Blue_Light = 0U;
        FSAC2021_V1_B.Yellow_Light = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<S65>/AS_Machine' */

  /* RelationalOperator: '<S84>/Relational Operator' */
  rtb_RateTransition26_p = (rtb_RateTransition4 <= 1000.0);

  /* RelationalOperator: '<S84>/Relational Operator1' */
  rtb_Nogas1Hasgas_o = (rtb_RateTransition3 <= 1000.0);

  /* MATLAB Function: '<S84>/MATLAB Function' */
  /* MATLAB Function 'Controller/50ms_Duty/EBS_Judge/MATLAB Function': '<S96>:1' */
  /* '<S96>:1:3' */
  rtb_RateTransition4 = 0.0;
  if (rtb_RateTransition26_p != 1) {
    if (rtb_Nogas1Hasgas_o == 1) {
      /* '<S96>:1:6' */
      /* '<S96>:1:7' */
      rtb_RateTransition4 = 1.0;

      /* %%armed */
    } else {
      if (rtb_Nogas1Hasgas_o == 0) {
        /* '<S96>:1:8' */
        /* '<S96>:1:9' */
        rtb_RateTransition4 = 2.0;

        /* %%enable */
      }
    }
  } else {
    /* '<S96>:1:4' */
    /* '<S96>:1:5' */
    /* %%disable */
  }

  /* End of MATLAB Function: '<S84>/MATLAB Function' */

  /* DataTypeConversion: '<S84>/Data Type Conversion' */
  EBS_Status = (uint8_T)rtb_RateTransition4;

  /* Switch: '<S86>/Switch' incorporates:
   *  DataTypeConversion: '<S86>/Data Type Conversion'
   *  Logic: '<S86>/Logical Operator'
   */
  if (FSAC2021_V1_B.Visual_Flag > 0) {
    rtb_RateTransition47 = FSAC2021_V1_B.Visual_Lights[0];
    rtb_RateTransition59 = FSAC2021_V1_B.Visual_Lights[1];
    rtb_RateTransition46_e = FSAC2021_V1_B.Visual_Lights[2];
  } else {
    rtb_RateTransition59 = (uint8_T)((EBS_light != 0) || EBS_Sensor_light);
  }

  /* End of Switch: '<S86>/Switch' */

  /* Logic: '<S91>/Logical Operator' incorporates:
   *  Logic: '<S91>/Logical Operator1'
   */
  rtb_Nogas1Hasgas_o = ((FSAC2021_V1_B.R2D != 0) && (!rtb_RateTransition50));

  /* Logic: '<S92>/Logical Operator' */
  rtb_RateTransition26_p = ((FSAC2021_V1_B.Safety_Circuit_Relay != 0) ||
    rtb_RateTransition31 || rtb_RateTransition32 || rtb_RateTransition42);

  /* Chart: '<S93>/Chart' */
  /* Gateway: Controller/50ms_Duty/Subsystem/Chart */
  /* During: Controller/50ms_Duty/Subsystem/Chart */
  if (FSAC2021_V1_DW.bitsForTID6.is_active_c5_FSAC2021_V1 == 0U) {
    /* Entry: Controller/50ms_Duty/Subsystem/Chart */
    FSAC2021_V1_DW.bitsForTID6.is_active_c5_FSAC2021_V1 = 1U;

    /* Entry Internal: Controller/50ms_Duty/Subsystem/Chart */
    /* Transition: '<S101>:19' */
    FSAC2021_V1_DW.bitsForTID6.is_c5_FSAC2021_V1 = FSAC2021_V1_IN_init;
  } else {
    switch (FSAC2021_V1_DW.bitsForTID6.is_c5_FSAC2021_V1) {
     case FSAC2021_V1_IN_Driverless:
      /* During 'Driverless': '<S101>:4' */
      MODE = 2.0;

      /* %无人驾驶模式 */
      break;

     case FSAC2021_V1_IN_Manul:
      /* During 'Manul': '<S101>:2' */
      MODE = 6.0;

      /* 手动模式 */
      break;

     case FSAC2021_V1_IN_Task:
      /* During 'Task': '<S101>:14' */
      MODE = 3.0;

      /* %车检任务 */
      break;

     default:
      /* During 'init': '<S101>:1' */
      if (AMI_State == 6.0) {
        /* Transition: '<S101>:3' */
        FSAC2021_V1_DW.bitsForTID6.is_c5_FSAC2021_V1 = FSAC2021_V1_IN_Manul;
      } else if ((AMI_State == 1.0) || (AMI_State == 2.0) || (AMI_State == 3.0) ||
                 (AMI_State == 5.0)) {
        /* Transition: '<S101>:10' */
        FSAC2021_V1_DW.bitsForTID6.is_c5_FSAC2021_V1 = FSAC2021_V1_IN_Driverless;
      } else {
        if (AMI_State == 4.0) {
          /* Transition: '<S101>:16' */
          /* Transition: '<S101>:17' */
          FSAC2021_V1_DW.bitsForTID6.is_c5_FSAC2021_V1 = FSAC2021_V1_IN_Task;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S93>/Chart' */

  /* Logic: '<S93>/Logical Operator' incorporates:
   *  Constant: '<S104>/Constant'
   *  Constant: '<S105>/Constant'
   *  Constant: '<S106>/Constant'
   *  Constant: '<S107>/Constant'
   *  RelationalOperator: '<S104>/Compare'
   *  RelationalOperator: '<S105>/Compare'
   *  RelationalOperator: '<S106>/Compare'
   *  RelationalOperator: '<S107>/Compare'
   */
  enable = ((MODE == 3.0) && (rtb_UnitDelay7 == 1.0) &&
            (FSAC2021_V1_B.Allow_Ctrl_Flg == 1) && (FSAC2021_V1_B.ASSI_State >=
             3));

  /* Outputs for Enabled SubSystem: '<S93>/Subsystem2' incorporates:
   *  EnablePort: '<S116>/Enable'
   */
  if (enable) {
    if (!FSAC2021_V1_DW.Subsystem2_MODE) {
      /* Enable for Chart: '<S116>/Chart' */
      FSAC2021_V1_DW.presentTicks_o = FSAC2021_V1_M->Timing.clockTick6;
      FSAC2021_V1_DW.previousTicks_e = FSAC2021_V1_DW.presentTicks_o;
      FSAC2021_V1_DW.Subsystem2_MODE = true;
    }

    /* Chart: '<S116>/Chart' */
    FSAC2021_V1_DW.presentTicks_o = FSAC2021_V1_M->Timing.clockTick6;
    FSAC2021_V1_DW.elapsedTicks_l = FSAC2021_V1_DW.presentTicks_o -
      FSAC2021_V1_DW.previousTicks_e;
    FSAC2021_V1_DW.previousTicks_e = FSAC2021_V1_DW.presentTicks_o;
    if (FSAC2021_V1_DW.temporalCounter_i1 + FSAC2021_V1_DW.elapsedTicks_l <=
        1023U) {
      FSAC2021_V1_DW.temporalCounter_i1 = (uint16_T)
        (FSAC2021_V1_DW.temporalCounter_i1 + FSAC2021_V1_DW.elapsedTicks_l);
    } else {
      FSAC2021_V1_DW.temporalCounter_i1 = 1023U;
    }

    /* Gateway: Controller/50ms_Duty/Subsystem/Subsystem2/Chart */
    /* During: Controller/50ms_Duty/Subsystem/Subsystem2/Chart */
    if (FSAC2021_V1_DW.bitsForTID6.is_active_c9_FSAC2021_V1 == 0U) {
      /* Entry: Controller/50ms_Duty/Subsystem/Subsystem2/Chart */
      FSAC2021_V1_DW.bitsForTID6.is_active_c9_FSAC2021_V1 = 1U;

      /* Entry Internal: Controller/50ms_Duty/Subsystem/Subsystem2/Chart */
      /* Transition: '<S117>:33' */
      FSAC2021_V1_DW.bitsForTID6.is_c9_FSAC2021_V1 = FSAC2021_V1_IN_init_g;

      /* Entry 'init': '<S117>:26' */
      FSAC2021_V1_B.SteerCmd = 0.0;
      FSAC2021_V1_B.ACC_b = 200.0;
    } else {
      switch (FSAC2021_V1_DW.bitsForTID6.is_c9_FSAC2021_V1) {
       case FSAC2021_V1_IN_IN:
        /* During 'IN': '<S117>:30' */
        if (FSAC2021_V1_DW.temporalCounter_i1 >= 540U) {
          /* Transition: '<S117>:32' */
          /* Exit Internal 'IN': '<S117>:30' */
          FSAC2021_V1_DW.bitsForTID6.is_IN = FSAC2021_V_IN_NO_ACTIVE_CHILD_b;
          FSAC2021_V1_DW.bitsForTID6.is_c9_FSAC2021_V1 = FSAC2021_V1_IN_end;

          /* Entry 'end': '<S117>:34' */
          FSAC2021_V1_B.ACC_b = 0.0;
          FSAC2021_V1_B.SteerCmd = 0.0;
          FSAC2021_V1_B.Mission_Flag = 1U;
        } else if (FSAC2021_V1_DW.bitsForTID6.is_IN == FSAC2021_V1_IN_Move_c) {
          /* During 'Move': '<S117>:28' */
          if (FSAC2021_V1_B.SteerCmd >= 110.0) {
            /* Transition: '<S117>:25' */
            FSAC2021_V1_DW.bitsForTID6.is_IN = FSAC2021_V1_IN_Second;
          } else {
            FSAC2021_V1_B.SteerCmd += 4.5;
          }
        } else {
          /* During 'Second': '<S117>:27' */
          if (FSAC2021_V1_B.SteerCmd <= -110.0) {
            /* Transition: '<S117>:29' */
            FSAC2021_V1_DW.bitsForTID6.is_IN = FSAC2021_V1_IN_Move_c;
          } else {
            FSAC2021_V1_B.SteerCmd -= 4.5;
          }
        }
        break;

       case FSAC2021_V1_IN_end:
        /* During 'end': '<S117>:34' */
        break;

       default:
        /* During 'init': '<S117>:26' */
        /* Transition: '<S117>:35' */
        FSAC2021_V1_DW.bitsForTID6.is_c9_FSAC2021_V1 = FSAC2021_V1_IN_IN;
        FSAC2021_V1_DW.temporalCounter_i1 = 0U;

        /* Entry 'IN': '<S117>:30' */
        /* Entry Internal 'IN': '<S117>:30' */
        /* Transition: '<S117>:31' */
        FSAC2021_V1_DW.bitsForTID6.is_IN = FSAC2021_V1_IN_Move_c;
        break;
      }
    }

    /* End of Chart: '<S116>/Chart' */

    /* SignalConversion: '<S116>/OutportBufferForACC' */
    FSAC2021_V1_B.Merge = FSAC2021_V1_B.ACC_b;

    /* SignalConversion: '<S116>/OutportBufferForSteerCmd' */
    FSAC2021_V1_B.Merge1 = FSAC2021_V1_B.SteerCmd;
  } else {
    if (FSAC2021_V1_DW.Subsystem2_MODE) {
      /* Disable for Chart: '<S116>/Chart' */
      FSAC2021_V1_DW.presentTicks_o = FSAC2021_V1_M->Timing.clockTick6;
      FSAC2021_V1_DW.elapsedTicks_l = FSAC2021_V1_DW.presentTicks_o -
        FSAC2021_V1_DW.previousTicks_e;
      FSAC2021_V1_DW.previousTicks_e = FSAC2021_V1_DW.presentTicks_o;
      if (FSAC2021_V1_DW.temporalCounter_i1 + FSAC2021_V1_DW.elapsedTicks_l <=
          1023U) {
        FSAC2021_V1_DW.temporalCounter_i1 = (uint16_T)
          (FSAC2021_V1_DW.temporalCounter_i1 + FSAC2021_V1_DW.elapsedTicks_l);
      } else {
        FSAC2021_V1_DW.temporalCounter_i1 = 1023U;
      }

      /* End of Disable for Chart: '<S116>/Chart' */
      FSAC2021_V1_DW.Subsystem2_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S93>/Subsystem2' */

  /* Outputs for Enabled SubSystem: '<S93>/Subsystem1' incorporates:
   *  EnablePort: '<S115>/Enable'
   */
  /* Logic: '<S93>/Logical Operator1' incorporates:
   *  Constant: '<S103>/Constant'
   *  Inport: '<S115>/IPC_Str_Cmd'
   *  RelationalOperator: '<S103>/Compare'
   */
  if ((MODE == 2.0) && (FSAC2021_V1_B.Allow_Ctrl_Flg != 0)) {
    /* Gain: '<S115>/Gain1' */
    rtb_RateTransition4 = 0.134 * rtb_RateTransition78;

    /* Saturate: '<S115>/Saturation' */
    if (rtb_RateTransition4 > 13.4) {
      /* DataTypeConversion: '<S115>/Data Type Conversion' */
      FSAC2021_V1_B.DataTypeConversion = 13.4;
    } else if (rtb_RateTransition4 < 0.0) {
      /* DataTypeConversion: '<S115>/Data Type Conversion' */
      FSAC2021_V1_B.DataTypeConversion = 0.0;
    } else {
      /* DataTypeConversion: '<S115>/Data Type Conversion' */
      FSAC2021_V1_B.DataTypeConversion = rtb_RateTransition4;
    }

    /* End of Saturate: '<S115>/Saturation' */
    FSAC2021_V1_B.Merge1 = rtb_RateTransition77;

    /* Gain: '<S115>/Gain' incorporates:
     *  Inport: '<S115>/IPC_Str_Cmd'
     */
    FSAC2021_V1_B.Merge = 15.0 * rtb_RateTransition80;
  }

  /* End of Logic: '<S93>/Logical Operator1' */
  /* End of Outputs for SubSystem: '<S93>/Subsystem1' */

  /* Outputs for Enabled SubSystem: '<S93>/Subsystem' incorporates:
   *  EnablePort: '<S114>/Enable'
   */
  /* RelationalOperator: '<S102>/Compare' incorporates:
   *  Constant: '<S102>/Constant'
   */
  if (MODE == 6.0) {
    /* Switch: '<S114>/Switch' incorporates:
     *  Constant: '<S114>/Constant'
     */
    if (rtb_RateTransition25 > 0.0) {
      FSAC2021_V1_B.Merge = 0.0;
    } else {
      FSAC2021_V1_B.Merge = rtb_RateTransition6;
    }

    /* End of Switch: '<S114>/Switch' */
  }

  /* End of RelationalOperator: '<S102>/Compare' */
  /* End of Outputs for SubSystem: '<S93>/Subsystem' */

  /* DataTypeConversion: '<S93>/Data Type Conversion10' */
  DataTypeConversion10_h = (real32_T)FSAC2021_V1_B.Merge;

  /* Switch: '<S93>/Switch1' incorporates:
   *  Constant: '<S109>/Constant'
   *  Constant: '<S110>/Constant'
   *  Constant: '<S111>/Constant'
   *  Constant: '<S93>/Constant2'
   *  DataTypeConversion: '<S93>/Data Type Conversion9'
   *  Logic: '<S93>/Logical Operator3'
   *  Logic: '<S93>/Logical Operator4'
   *  Logic: '<S93>/Logical Operator5'
   *  RelationalOperator: '<S109>/Compare'
   *  RelationalOperator: '<S110>/Compare'
   *  RelationalOperator: '<S111>/Compare'
   */
  if ((EBS_Sensor_light || (EBS_Status == 2)) && ((FSAC2021_V1_B.ASSI_State == 2)
       || (FSAC2021_V1_B.ASSI_State == 3))) {
    FSAC2021_V1_B.Switch1 = 8.0;
  } else {
    FSAC2021_V1_B.Switch1 = (uint8_T)FSAC2021_V1_B.DataTypeConversion;
  }

  /* End of Switch: '<S93>/Switch1' */

  /* MATLAB Function: '<S94>/MATLAB Function' */
  /* MATLAB Function 'Controller/50ms_Duty/Subsystem1/MATLAB Function': '<S118>:1' */
  /* '<S118>:1:3' */
  rtb_RateTransition4 = 0.0;
  if ((FSAC2021_V1_B.DataTypeConversion19 == 1) &&
      (FSAC2021_V1_B.DataTypeConversion4_f == 1)) {
    /* '<S118>:1:4' */
    /* '<S118>:1:5' */
    rtb_RateTransition4 = 1.0;
    if ((FSAC2021_V1_B.DataTypeConversion19 == 0) ||
        (FSAC2021_V1_B.DataTypeConversion4_f == 0) || (FSAC2021_V1_B.ASSI_State ==
         0) || (FSAC2021_V1_B.ASSI_State == 4)) {
      /* '<S118>:1:6' */
      /* '<S118>:1:7' */
      rtb_RateTransition4 = 0.0;
    }
  }

  /* End of MATLAB Function: '<S94>/MATLAB Function' */

  /* Update for UnitDelay: '<S65>/Unit Delay1' */
  FSAC2021_V1_DW.UnitDelay1_DSTATE = MODE;

  /* Switch: '<S93>/Switch' incorporates:
   *  Constant: '<S108>/Constant'
   *  Constant: '<S93>/Constant'
   *  Constant: '<S93>/Constant1'
   *  RelationalOperator: '<S108>/Compare'
   */
  if (rtb_RateTransition78 == 100.0) {
    rtb_DataTypeConversion13 = 1;
  } else {
    rtb_DataTypeConversion13 = 0;
  }

  /* End of Switch: '<S93>/Switch' */

  /* Update for UnitDelay: '<S65>/Unit Delay5' incorporates:
   *  DataTypeConversion: '<S93>/Data Type Conversion'
   *  Logic: '<S93>/Logical Operator2'
   */
  FSAC2021_V1_DW.UnitDelay5_DSTATE_h = (uint8_T)((FSAC2021_V1_B.Mission_Flag !=
    0) || (rtb_DataTypeConversion13 != 0));

  /* S-Function (fcncallgen): '<S7>/Function-Call Generator1' incorporates:
   *  SubSystem: '<S9>/Read_VCU_DigInput'
   */

  /* S-Function (ec55xx_swislb): '<S403>/LVMS_Read' */

  /* Read the the value of the specified switch input */
  LVMS_Read= ec_gpio_read(159);

  /* DataTypeConversion: '<S403>/Data Type Conversion19' */
  FSAC2021_V1_B.DataTypeConversion19 = (uint8_T)LVMS_Read;

  /* S-Function (ec55xx_swislb): '<S403>/HVMS_Read' */

  /* Read the the value of the specified switch input */
  HVMS_Read= ec_gpio_read(161);

  /* DataTypeConversion: '<S403>/Data Type Conversion1' */
  FSAC2021_V1_B.DataTypeConversion1_j = (uint8_T)HVMS_Read;

  /* S-Function (ec55xx_swislb): '<S403>/ASMS_Read' */

  /* Read the the value of the specified switch input */
  ASMS_Read= ec_gpio_read(158);

  /* DataTypeConversion: '<S403>/Data Type Conversion4' */
  FSAC2021_V1_B.DataTypeConversion4_f = (uint8_T)ASMS_Read;

  /* S-Function (ec55xx_swislb): '<S403>/On_Out_Switch' */

  /* Read the the value of the specified switch input */
  On_Out_Switch= ec_gpio_read(157);

  /* DataTypeConversion: '<S403>/Data Type Conversion15' */
  FSAC2021_V1_B.DataTypeConversion15 = (uint8_T)On_Out_Switch;

  /* S-Function (ec55xx_swislb): '<S403>/START' */

  /* Read the the value of the specified switch input */
  START= ec_gpio_read(154);

  /* DataTypeConversion: '<S403>/Data Type Conversion25' */
  FSAC2021_V1_B.DataTypeConversion25_m = (uint8_T)START;

  /* S-Function (ec55xx_swislb): '<S403>/On_In_Switch' */

  /* Read the the value of the specified switch input */
  On_IN_Switch= ec_gpio_read(156);

  /* DataTypeConversion: '<S403>/Data Type Conversion24' */
  FSAC2021_V1_B.DataTypeConversion24_ki = (uint8_T)On_IN_Switch;

  /* S-Function (ec55xx_swislb): '<S403>/HV_LIGHT' */

  /* Read the the value of the specified switch input */
  HV_LIGHT= ec_gpio_read(160);

  /* DataTypeConversion: '<S403>/Data Type Conversion26' */
  FSAC2021_V1_B.DataTypeConversion26_g = (uint8_T)HV_LIGHT;

  /* S-Function (ec55xx_swislb): '<S403>/EBS_Rel_Switch' */

  /* Read the the value of the specified switch input */
  EBS_Rel_Switch= ec_gpio_read(169);

  /* S-Function (fcncallgen): '<S7>/Function-Call Generator1' incorporates:
   *  SubSystem: '<S9>/Read_VCU_AnaInput'
   */

  /* S-Function (ec55xx_asislb): '<S402>/Read_Lft_Acc_Disp' */

  /* Read the ADC conversion result of the analog signal */
  Read_Lft_Acc_Disp= ec_adc_readresult(25);

  /* S-Function (ec55xx_asislb): '<S402>/Read_Right_Acc_Disp1' */

  /* Read the ADC conversion result of the analog signal */
  Read_Right_Acc_Disp1= ec_adc_readresult(14);

  /* S-Function (ec55xx_asislb): '<S402>/Read_Compare' */

  /* Read the ADC conversion result of the analog signal */
  FSAC2021_V1_B.Read_Compare= ec_adc_readresult(5);

  /* Gain: '<S402>/Gain' */
  Read_compare_OutVolt = 0.001F * (real32_T)FSAC2021_V1_B.Read_Compare;

  /* S-Function (ec55xx_asislb): '<S402>/Read_EBS_Gas_Prs1' */

  /* Read the ADC conversion result of the analog signal */
  Read_EBS_Gas_Prs1= ec_adc_readresult(22);

  /* S-Function (ec55xx_asislb): '<S402>/Read_EBS_Gas_Prs2' */

  /* Read the ADC conversion result of the analog signal */
  Read_EBS_Gas_Prs2= ec_adc_readresult(17);

  /* S-Function (ec55xx_asislb): '<S402>/Read_EBS_Gas_Prs3' */

  /* Read the ADC conversion result of the analog signal */
  FSAC2021_V1_B.Read_EBS_Gas_Prs3= ec_adc_readresult(4);

  /* RelationalOperator: '<S405>/Compare' incorporates:
   *  Constant: '<S405>/Constant'
   */
  FSAC2021_V1_B.Compare = (FSAC2021_V1_B.Read_EBS_Gas_Prs3 >= 3000);

  /* S-Function (ec55xx_asislb): '<S402>/Read_EBS_Gas_Prs4' */

  /* Read the ADC conversion result of the analog signal */
  Read_liquid_presuress= ec_adc_readresult(10);

  /* S-Function (fcncallgen): '<S7>/Function-Call Generator1' incorporates:
   *  SubSystem: '<S8>/PCANB(BMS、DRIVE_MOTOR)'
   */

  /* S-Function (ec55xx_canreceiveslb): '<S248>/BMS_HCU_MAXT' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF18RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf18looprx= 0;
    FSAC2021_V1_B.BMS_HCU_MAXT_o3= -1738391309;
    FSAC2021_V1_B.BMS_HCU_MAXT_o5= 8;
    FSAC2021_V1_B.BMS_HCU_MAXT_o2= ec_can_receive(1,18, CAN1BUF18RX);
    FSAC2021_V1_B.BMS_HCU_MAXT_o4[0]= CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    FSAC2021_V1_B.BMS_HCU_MAXT_o4[1]= CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    FSAC2021_V1_B.BMS_HCU_MAXT_o4[2]= CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    FSAC2021_V1_B.BMS_HCU_MAXT_o4[3]= CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    FSAC2021_V1_B.BMS_HCU_MAXT_o4[4]= CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    FSAC2021_V1_B.BMS_HCU_MAXT_o4[5]= CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    FSAC2021_V1_B.BMS_HCU_MAXT_o4[6]= CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    FSAC2021_V1_B.BMS_HCU_MAXT_o4[7]= CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
  }

  /* Nothing to do for system: <S248>/BMS_HCU_MAXT1 */

  /* S-Function (ec55xx_canreceiveslb): '<S248>/BMS_HCU_MAXV' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF16RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf16looprx= 0;
    FSAC2021_V1_B.BMS_HCU_MAXV_o3= -1738456845;
    FSAC2021_V1_B.BMS_HCU_MAXV_o5= 8;
    FSAC2021_V1_B.BMS_HCU_MAXV_o2= ec_can_receive(1,16, CAN1BUF16RX);
    FSAC2021_V1_B.BMS_HCU_MAXV_o4[0]= CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    FSAC2021_V1_B.BMS_HCU_MAXV_o4[1]= CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    FSAC2021_V1_B.BMS_HCU_MAXV_o4[2]= CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    FSAC2021_V1_B.BMS_HCU_MAXV_o4[3]= CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    FSAC2021_V1_B.BMS_HCU_MAXV_o4[4]= CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    FSAC2021_V1_B.BMS_HCU_MAXV_o4[5]= CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    FSAC2021_V1_B.BMS_HCU_MAXV_o4[6]= CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    FSAC2021_V1_B.BMS_HCU_MAXV_o4[7]= CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
  }

  /* Nothing to do for system: <S248>/BMS_HCU_MAXV  */

  /* S-Function (ec55xx_canreceiveslb): '<S248>/BMS_RELAY' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF51RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf51looprx= 0;
    FSAC2021_V1_B.BMS_RELAY_o3= -1738325773;
    FSAC2021_V1_B.BMS_RELAY_o5= 8;
    FSAC2021_V1_B.BMS_RELAY_o2= ec_can_receive(1,51, CAN1BUF51RX);
    FSAC2021_V1_B.BMS_RELAY_o4[0]= CAN1BUF51RX[can1buf51looprx];
    can1buf51looprx++;
    FSAC2021_V1_B.BMS_RELAY_o4[1]= CAN1BUF51RX[can1buf51looprx];
    can1buf51looprx++;
    FSAC2021_V1_B.BMS_RELAY_o4[2]= CAN1BUF51RX[can1buf51looprx];
    can1buf51looprx++;
    FSAC2021_V1_B.BMS_RELAY_o4[3]= CAN1BUF51RX[can1buf51looprx];
    can1buf51looprx++;
    FSAC2021_V1_B.BMS_RELAY_o4[4]= CAN1BUF51RX[can1buf51looprx];
    can1buf51looprx++;
    FSAC2021_V1_B.BMS_RELAY_o4[5]= CAN1BUF51RX[can1buf51looprx];
    can1buf51looprx++;
    FSAC2021_V1_B.BMS_RELAY_o4[6]= CAN1BUF51RX[can1buf51looprx];
    can1buf51looprx++;
    FSAC2021_V1_B.BMS_RELAY_o4[7]= CAN1BUF51RX[can1buf51looprx];
    can1buf51looprx++;
  }

  /* Nothing to do for system: <S248>/BMS_RELAY  */

  /* S-Function (ec55xx_canreceiveslb): '<S248>/BMS_HCU_POWER' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF52RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf52looprx= 0;
    FSAC2021_V1_B.BMS_HCU_POWER_o3= -1738260237;
    FSAC2021_V1_B.BMS_HCU_POWER_o5= 8;
    FSAC2021_V1_B.BMS_HCU_POWER_o2= ec_can_receive(1,52, CAN1BUF52RX);
    FSAC2021_V1_B.BMS_HCU_POWER_o4[0]= CAN1BUF52RX[can1buf52looprx];
    can1buf52looprx++;
    FSAC2021_V1_B.BMS_HCU_POWER_o4[1]= CAN1BUF52RX[can1buf52looprx];
    can1buf52looprx++;
    FSAC2021_V1_B.BMS_HCU_POWER_o4[2]= CAN1BUF52RX[can1buf52looprx];
    can1buf52looprx++;
    FSAC2021_V1_B.BMS_HCU_POWER_o4[3]= CAN1BUF52RX[can1buf52looprx];
    can1buf52looprx++;
    FSAC2021_V1_B.BMS_HCU_POWER_o4[4]= CAN1BUF52RX[can1buf52looprx];
    can1buf52looprx++;
    FSAC2021_V1_B.BMS_HCU_POWER_o4[5]= CAN1BUF52RX[can1buf52looprx];
    can1buf52looprx++;
    FSAC2021_V1_B.BMS_HCU_POWER_o4[6]= CAN1BUF52RX[can1buf52looprx];
    can1buf52looprx++;
    FSAC2021_V1_B.BMS_HCU_POWER_o4[7]= CAN1BUF52RX[can1buf52looprx];
    can1buf52looprx++;
  }

  /* Nothing to do for system: <S248>/BMS_HCU_POWER  */

  /* S-Function (ec55xx_canreceiveslb): '<S248>/Motor_Current_Speed ' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF21RX[2]= { 0, 0 };

    uint8 can1buf21looprx= 0;
    FSAC2021_V1_B.Motor_Current_Speed_o3= -2147413853;
    FSAC2021_V1_B.Motor_Current_Speed_o5= 2;
    motor_node= ec_can_receive(1,21, CAN1BUF21RX);
    FSAC2021_V1_B.Motor_Current_Speed_o4[0]= CAN1BUF21RX[can1buf21looprx];
    can1buf21looprx++;
    FSAC2021_V1_B.Motor_Current_Speed_o4[1]= CAN1BUF21RX[can1buf21looprx];
    can1buf21looprx++;
  }

  /* Call the system: <S248>/MOTOR_CURRENT_SPEED */

  /* Output and update for function-call system: '<S248>/MOTOR_CURRENT_SPEED' */
  {
    real32_T u0;

    /* Saturate: '<S297>/Motor_Currt_Speed_sat' incorporates:
     *  Constant: '<S297>/Motor_Currt_Speedinput2_C'
     *  Product: '<S297>/Motor_Currt_Speedinput2_P'
     *  Sum: '<S297>/Motor_Currt_Speedinput2_Ad'
     */
    u0 = (real32_T)((FSAC2021_V1_B.Motor_Current_Speed_o4[1] << 8) +
                    FSAC2021_V1_B.Motor_Current_Speed_o4[0]);
    if (u0 > 2500.0F) {
      FSAC2021_V1_B.Motor_Currt_Speed_sat = 2500.0F;
    } else {
      FSAC2021_V1_B.Motor_Currt_Speed_sat = u0;
    }

    /* End of Saturate: '<S297>/Motor_Currt_Speed_sat' */
  }

  /* S-Function (ec55xx_canreceiveslb): '<S248>/BMS_ALARM' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF50RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf50looprx= 0;
    FSAC2021_V1_B.BMS_ALARM_o3= -1738194701;
    FSAC2021_V1_B.BMS_ALARM_o5= 8;
    FSAC2021_V1_B.BMS_ALARM_o2= ec_can_receive(1,50, CAN1BUF50RX);
    FSAC2021_V1_B.BMS_ALARM_o4[0]= CAN1BUF50RX[can1buf50looprx];
    can1buf50looprx++;
    FSAC2021_V1_B.BMS_ALARM_o4[1]= CAN1BUF50RX[can1buf50looprx];
    can1buf50looprx++;
    FSAC2021_V1_B.BMS_ALARM_o4[2]= CAN1BUF50RX[can1buf50looprx];
    can1buf50looprx++;
    FSAC2021_V1_B.BMS_ALARM_o4[3]= CAN1BUF50RX[can1buf50looprx];
    can1buf50looprx++;
    FSAC2021_V1_B.BMS_ALARM_o4[4]= CAN1BUF50RX[can1buf50looprx];
    can1buf50looprx++;
    FSAC2021_V1_B.BMS_ALARM_o4[5]= CAN1BUF50RX[can1buf50looprx];
    can1buf50looprx++;
    FSAC2021_V1_B.BMS_ALARM_o4[6]= CAN1BUF50RX[can1buf50looprx];
    can1buf50looprx++;
    FSAC2021_V1_B.BMS_ALARM_o4[7]= CAN1BUF50RX[can1buf50looprx];
    can1buf50looprx++;
  }

  /* Call the system: <S248>/BMS_ALARM  */

  /* Output and update for function-call system: '<S248>/BMS_ALARM ' */

  /* DataTypeConversion: '<S291>/Data Type Conversion39' incorporates:
   *  ArithShift: '<S303>/ALM_LEAK_OC_S'
   *  DataTypeConversion: '<S303>/ALM_LEAK_OC_Convert'
   *  DataTypeConversion: '<S303>/ALM_LEAK_OCcv'
   *  S-Function (sfix_bitop): '<S303>/ALM_LEAK_OC_L'
   *  Saturate: '<S303>/ALM_LEAK_OC_sat'
   */
  FSAC2021_V1_B.DataTypeConversion39 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_B.BMS_ALARM_o4[4] & 96U) >> 5);

  /* DataTypeConversion: '<S291>/Data Type Conversion40' incorporates:
   *  ArithShift: '<S303>/ALM_PRECHRG_FAIL_S'
   *  DataTypeConversion: '<S303>/ALM_PRECHRG_FAIL_Convert'
   *  DataTypeConversion: '<S303>/ALM_PRECHRG_FAILcv'
   *  S-Function (sfix_bitop): '<S303>/ALM_PRECHRG_FAIL_L'
   *  Saturate: '<S303>/ALM_PRECHRG_FAIL_sat'
   */
  FSAC2021_V1_B.DataTypeConversion40 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_B.BMS_ALARM_o4[4] & 16U) >> 4);

  /* DataTypeConversion: '<S291>/Data Type Conversion41' incorporates:
   *  ArithShift: '<S303>/ALM_HVREL_FAIL_S'
   *  DataTypeConversion: '<S303>/ALM_HVREL_FAIL_Convert'
   *  DataTypeConversion: '<S303>/ALM_HVREL_FAILcv'
   *  S-Function (sfix_bitop): '<S303>/ALM_HVREL_FAIL_L'
   *  Saturate: '<S303>/ALM_HVREL_FAIL_sat'
   */
  FSAC2021_V1_B.DataTypeConversion41 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_B.BMS_ALARM_o4[5] & 128U) >> 7);

  /* DataTypeConversion: '<S291>/Data Type Conversion43' incorporates:
   *  ArithShift: '<S303>/ALM_DSCH_OCT_S'
   *  DataTypeConversion: '<S303>/ALM_DSCH_OCT_Convert'
   *  DataTypeConversion: '<S303>/ALM_DSCH_OCTcv'
   *  S-Function (sfix_bitop): '<S303>/ALM_DSCH_OCT_L'
   *  Saturate: '<S303>/ALM_DSCH_OCT_sat'
   */
  FSAC2021_V1_B.DataTypeConversion43 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_B.BMS_ALARM_o4[3] & 12U) >> 2);

  /* DataTypeConversion: '<S291>/Data Type Conversion47' incorporates:
   *  DataTypeConversion: '<S303>/ALM_BSU_OFFLINE_Convert'
   *  DataTypeConversion: '<S303>/ALM_BSU_OFFLINEcv'
   *  S-Function (sfix_bitop): '<S303>/ALM_BSU_OFFLINE_L'
   *  Saturate: '<S303>/ALM_BSU_OFFLINE_sat'
   */
  FSAC2021_V1_B.DataTypeConversion47 = (uint8_T)(real32_T)
    (FSAC2021_V1_B.BMS_ALARM_o4[3] & 3);

  /* DataTypeConversion: '<S291>/Data Type Conversion48' incorporates:
   *  ArithShift: '<S303>/ALM_BSU_FAULT_S'
   *  DataTypeConversion: '<S303>/ALM_BSU_FAULT_Convert'
   *  DataTypeConversion: '<S303>/ALM_BSU_FAULTcv'
   *  S-Function (sfix_bitop): '<S303>/ALM_BSU_FAULT_L'
   *  Saturate: '<S303>/ALM_BSU_FAULT_sat'
   */
  FSAC2021_V1_B.DataTypeConversion48 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_B.BMS_ALARM_o4[4] & 128U) >> 7);

  /* DataTypeConversion: '<S291>/Data Type Conversion49' incorporates:
   *  ArithShift: '<S303>/ALM_BMU_FAIL_S'
   *  DataTypeConversion: '<S303>/ALM_BMU_FAIL_Convert'
   *  DataTypeConversion: '<S303>/ALM_BMU_FAILcv'
   *  S-Function (sfix_bitop): '<S303>/ALM_BMU_FAIL_L'
   *  Saturate: '<S303>/ALM_BMU_FAIL_sat'
   */
  FSAC2021_V1_B.DataTypeConversion49 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_B.BMS_ALARM_o4[4] & 4U) >> 2);

  /* DataTypeConversion: '<S291>/Data Type Conversion50' incorporates:
   *  ArithShift: '<S303>/ALM_BATT_UC_S'
   *  DataTypeConversion: '<S303>/ALM_BATT_UC_Convert'
   *  DataTypeConversion: '<S303>/ALM_BATT_UCcv'
   *  S-Function (sfix_bitop): '<S303>/ALM_BATT_UC_L'
   *  Saturate: '<S303>/ALM_BATT_UC_sat'
   */
  FSAC2021_V1_B.DataTypeConversion50 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_B.BMS_ALARM_o4[2] & 12U) >> 2);

  /* DataTypeConversion: '<S291>/Data Type Conversion51' incorporates:
   *  ArithShift: '<S303>/ALM_BATT_OC_S'
   *  DataTypeConversion: '<S303>/ALM_BATT_OC_Convert'
   *  DataTypeConversion: '<S303>/ALM_BATT_OCcv'
   *  S-Function (sfix_bitop): '<S303>/ALM_BATT_OC_L'
   *  Saturate: '<S303>/ALM_BATT_OC_sat'
   */
  FSAC2021_V1_B.DataTypeConversion51 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_B.BMS_ALARM_o4[2] & 48U) >> 4);

  /* DataTypeConversion: '<S291>/Data Type Conversion52' incorporates:
   *  ArithShift: '<S303>/ALM_AUX_FAIL_S'
   *  DataTypeConversion: '<S303>/ALM_AUX_FAIL_Convert'
   *  DataTypeConversion: '<S303>/ALM_AUX_FAILcv'
   *  S-Function (sfix_bitop): '<S303>/ALM_AUX_FAIL_L'
   *  Saturate: '<S303>/ALM_AUX_FAIL_sat'
   */
  FSAC2021_V1_B.DataTypeConversion52 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_B.BMS_ALARM_o4[4] & 8U) >> 3);

  /* DataTypeConversion: '<S291>/Data Type Conversion53' incorporates:
   *  ArithShift: '<S303>/ALM_BATT_UV_S'
   *  DataTypeConversion: '<S303>/ALM_BATT_UV_Convert'
   *  DataTypeConversion: '<S303>/ALM_BATT_UVcv'
   *  S-Function (sfix_bitop): '<S303>/ALM_BATT_UV_L'
   *  Saturate: '<S303>/ALM_BATT_UV_sat'
   */
  FSAC2021_V1_B.DataTypeConversion53 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_B.BMS_ALARM_o4[2] & 192U) >> 6);

  /* DataTypeConversion: '<S291>/Data Type Conversion54' incorporates:
   *  DataTypeConversion: '<S303>/ALM_BATT_OV_Convert'
   *  DataTypeConversion: '<S303>/ALM_BATT_OVcv'
   *  S-Function (sfix_bitop): '<S303>/ALM_BATT_OV_L'
   *  Saturate: '<S303>/ALM_BATT_OV_sat'
   */
  FSAC2021_V1_B.DataTypeConversion54 = (uint8_T)(real32_T)
    (FSAC2021_V1_B.BMS_ALARM_o4[1] & 3);

  /* DataTypeConversion: '<S291>/Data Type Conversion55' incorporates:
   *  ArithShift: '<S303>/ALM_BATT_DT_S'
   *  DataTypeConversion: '<S303>/ALM_BATT_DT_Convert'
   *  DataTypeConversion: '<S303>/ALM_BATT_DTcv'
   *  S-Function (sfix_bitop): '<S303>/ALM_BATT_DT_L'
   *  Saturate: '<S303>/ALM_BATT_DT_sat'
   */
  FSAC2021_V1_B.DataTypeConversion55 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_B.BMS_ALARM_o4[1] & 12U) >> 2);

  /* DataTypeConversion: '<S291>/Data Type Conversion56' incorporates:
   *  ArithShift: '<S303>/ALM_BATT_DV_S'
   *  DataTypeConversion: '<S303>/ALM_BATT_DV_Convert'
   *  DataTypeConversion: '<S303>/ALM_BATT_DVcv'
   *  S-Function (sfix_bitop): '<S303>/ALM_BATT_DV_L'
   *  Saturate: '<S303>/ALM_BATT_DV_sat'
   */
  FSAC2021_V1_B.DataTypeConversion56 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_B.BMS_ALARM_o4[1] & 48U) >> 4);

  /* DataTypeConversion: '<S291>/Data Type Conversion57' incorporates:
   *  ArithShift: '<S303>/ALM_CELL_TBK_S'
   *  DataTypeConversion: '<S303>/ALM_CELL_TBK_Convert'
   *  DataTypeConversion: '<S303>/ALM_CELL_TBKcv'
   *  S-Function (sfix_bitop): '<S303>/ALM_CELL_TBK_L'
   *  Saturate: '<S303>/ALM_CELL_TBK_sat'
   */
  FSAC2021_V1_B.DataTypeConversion57 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_B.BMS_ALARM_o4[1] & 64U) >> 6);

  /* DataTypeConversion: '<S291>/Data Type Conversion58' incorporates:
   *  ArithShift: '<S303>/ALM_CELL_IBK_S'
   *  DataTypeConversion: '<S303>/ALM_CELL_IBK_Convert'
   *  DataTypeConversion: '<S303>/ALM_CELL_IBKcv'
   *  S-Function (sfix_bitop): '<S303>/ALM_CELL_IBK_L'
   *  Saturate: '<S303>/ALM_CELL_IBK_sat'
   */
  FSAC2021_V1_B.DataTypeConversion58 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_B.BMS_ALARM_o4[1] & 128U) >> 7);

  /* DataTypeConversion: '<S291>/Data Type Conversion59' incorporates:
   *  DataTypeConversion: '<S303>/ALM_CELL_UT_Convert'
   *  DataTypeConversion: '<S303>/ALM_CELL_UTcv'
   *  S-Function (sfix_bitop): '<S303>/ALM_CELL_UT_L'
   *  Saturate: '<S303>/ALM_CELL_UT_sat'
   */
  FSAC2021_V1_B.DataTypeConversion59 = (uint8_T)(real32_T)
    (FSAC2021_V1_B.BMS_ALARM_o4[0] & 3);

  /* DataTypeConversion: '<S291>/Data Type Conversion60' incorporates:
   *  ArithShift: '<S303>/ALM_CELL_OT_S'
   *  DataTypeConversion: '<S303>/ALM_CELL_OT_Convert'
   *  DataTypeConversion: '<S303>/ALM_CELL_OTcv'
   *  S-Function (sfix_bitop): '<S303>/ALM_CELL_OT_L'
   *  Saturate: '<S303>/ALM_CELL_OT_sat'
   */
  FSAC2021_V1_B.DataTypeConversion60 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_B.BMS_ALARM_o4[0] & 12U) >> 2);

  /* DataTypeConversion: '<S291>/Data Type Conversion61' incorporates:
   *  ArithShift: '<S303>/ALM_CELL_UV_S'
   *  DataTypeConversion: '<S303>/ALM_CELL_UV_Convert'
   *  DataTypeConversion: '<S303>/ALM_CELL_UVcv'
   *  S-Function (sfix_bitop): '<S303>/ALM_CELL_UV_L'
   *  Saturate: '<S303>/ALM_CELL_UV_sat'
   */
  FSAC2021_V1_B.DataTypeConversion61 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_B.BMS_ALARM_o4[0] & 48U) >> 4);

  /* DataTypeConversion: '<S291>/Data Type Conversion62' incorporates:
   *  ArithShift: '<S303>/ALM_CELL_OV_S'
   *  DataTypeConversion: '<S303>/ALM_CELL_OV_Convert'
   *  DataTypeConversion: '<S303>/ALM_CELL_OVcv'
   *  S-Function (sfix_bitop): '<S303>/ALM_CELL_OV_L'
   *  Saturate: '<S303>/ALM_CELL_OV_sat'
   */
  FSAC2021_V1_B.DataTypeConversion62 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_B.BMS_ALARM_o4[0] & 192U) >> 6);

  /* S-Function (ec55xx_canreceiveslb): '<S248>/Str_Error' */

  /* Receive CAN message */
  {
    uint8 CAN0BUF4RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can0buf4looprx= 0;
    FSAC2021_V1_B.Str_Error_o3= 129;
    FSAC2021_V1_B.Str_Error_o5= 8;
    FSAC2021_V1_B.Str_Error_o2= ec_can_receive(0,4, CAN0BUF4RX);
    FSAC2021_V1_B.Str_Error_o4[0]= CAN0BUF4RX[can0buf4looprx];
    can0buf4looprx++;
    FSAC2021_V1_B.Str_Error_o4[1]= CAN0BUF4RX[can0buf4looprx];
    can0buf4looprx++;
    FSAC2021_V1_B.Str_Error_o4[2]= CAN0BUF4RX[can0buf4looprx];
    can0buf4looprx++;
    FSAC2021_V1_B.Str_Error_o4[3]= CAN0BUF4RX[can0buf4looprx];
    can0buf4looprx++;
    FSAC2021_V1_B.Str_Error_o4[4]= CAN0BUF4RX[can0buf4looprx];
    can0buf4looprx++;
    FSAC2021_V1_B.Str_Error_o4[5]= CAN0BUF4RX[can0buf4looprx];
    can0buf4looprx++;
    FSAC2021_V1_B.Str_Error_o4[6]= CAN0BUF4RX[can0buf4looprx];
    can0buf4looprx++;
    FSAC2021_V1_B.Str_Error_o4[7]= CAN0BUF4RX[can0buf4looprx];
    can0buf4looprx++;
  }

  /* Call the system: <S248>/Str_Emergency  */

  /* Output and update for function-call system: '<S248>/Str_Emergency ' */

  /* DataTypeConversion: '<S301>/Data Type Conversion22' incorporates:
   *  ArithShift: '<S359>/Str_UnderVolt_Warning_S'
   *  DataTypeConversion: '<S359>/Str_UnderVolt_Warning_Convert'
   *  DataTypeConversion: '<S359>/Str_UnderVolt_Warningcv'
   *  S-Function (sfix_bitop): '<S359>/Str_UnderVolt_Warning_L'
   *  Saturate: '<S359>/Str_UnderVolt_Warning_sat'
   */
  FSAC2021_V1_B.DataTypeConversion22_f = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_B.Str_Error_o4[1] & 8U) >> 3);

  /* DataTypeConversion: '<S301>/Data Type Conversion23' incorporates:
   *  DataTypeConversion: '<S359>/Str_System_Error_Convert'
   *  DataTypeConversion: '<S359>/Str_System_Errorcv'
   *  S-Function (sfix_bitop): '<S359>/Str_System_Error_L'
   *  Saturate: '<S359>/Str_System_Error_sat'
   */
  FSAC2021_V1_B.DataTypeConversion23_c = (uint8_T)(real32_T)
    (FSAC2021_V1_B.Str_Error_o4[1] & 1);

  /* DataTypeConversion: '<S301>/Data Type Conversion24' incorporates:
   *  ArithShift: '<S359>/Str_Spd_Over_Alam_S'
   *  DataTypeConversion: '<S359>/Str_Spd_Over_Alam_Convert'
   *  DataTypeConversion: '<S359>/Str_Spd_Over_Alamcv'
   *  S-Function (sfix_bitop): '<S359>/Str_Spd_Over_Alam_L'
   *  Saturate: '<S359>/Str_Spd_Over_Alam_sat'
   */
  FSAC2021_V1_B.DataTypeConversion24_k = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_B.Str_Error_o4[0] & 16U) >> 4);

  /* DataTypeConversion: '<S301>/Data Type Conversion25' incorporates:
   *  ArithShift: '<S359>/Str_PwrMod_TempHigh_Warning_S'
   *  DataTypeConversion: '<S359>/Str_PwrMod_TempHigh_Warning_Convert'
   *  DataTypeConversion: '<S359>/Str_PwrMod_TempHigh_Warningcv'
   *  S-Function (sfix_bitop): '<S359>/Str_PwrMod_TempHigh_Warning_L'
   *  Saturate: '<S359>/Str_PwrMod_TempHigh_Warning_sat'
   */
  FSAC2021_V1_B.DataTypeConversion25 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_B.Str_Error_o4[0] & 4U) >> 2);

  /* DataTypeConversion: '<S301>/Data Type Conversion26' incorporates:
   *  ArithShift: '<S359>/Str_PwrMod_TempHigh_Alarm_S'
   *  DataTypeConversion: '<S359>/Str_PwrMod_TempHigh_Alarm_Convert'
   *  DataTypeConversion: '<S359>/Str_PwrMod_TempHigh_Alarmcv'
   *  S-Function (sfix_bitop): '<S359>/Str_PwrMod_TempHigh_Alarm_L'
   *  Saturate: '<S359>/Str_PwrMod_TempHigh_Alarm_sat'
   */
  FSAC2021_V1_B.DataTypeConversion26 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_B.Str_Error_o4[0] & 8U) >> 3);

  /* DataTypeConversion: '<S301>/Data Type Conversion27' incorporates:
   *  ArithShift: '<S359>/Str_Para_Error_S'
   *  DataTypeConversion: '<S359>/Str_Para_Error_Convert'
   *  DataTypeConversion: '<S359>/Str_Para_Errorcv'
   *  S-Function (sfix_bitop): '<S359>/Str_Para_Error_L'
   *  Saturate: '<S359>/Str_Para_Error_sat'
   */
  FSAC2021_V1_B.DataTypeConversion27 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_B.Str_Error_o4[1] & 4U) >> 2);

  /* DataTypeConversion: '<S301>/Data Type Conversion28' incorporates:
   *  ArithShift: '<S359>/Str_Overvolt_Warning_S'
   *  DataTypeConversion: '<S359>/Str_Overvolt_Warning_Convert'
   *  DataTypeConversion: '<S359>/Str_Overvolt_Warningcv'
   *  S-Function (sfix_bitop): '<S359>/Str_Overvolt_Warning_L'
   *  Saturate: '<S359>/Str_Overvolt_Warning_sat'
   */
  FSAC2021_V1_B.DataTypeConversion28 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_B.Str_Error_o4[1] & 16U) >> 4);

  /* DataTypeConversion: '<S301>/Data Type Conversion29' incorporates:
   *  ArithShift: '<S359>/Str_Over_TopCurr_S'
   *  DataTypeConversion: '<S359>/Str_Over_TopCurr_Convert'
   *  DataTypeConversion: '<S359>/Str_Over_TopCurrcv'
   *  S-Function (sfix_bitop): '<S359>/Str_Over_TopCurr_L'
   *  Saturate: '<S359>/Str_Over_TopCurr_sat'
   */
  FSAC2021_V1_B.DataTypeConversion29 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_B.Str_Error_o4[1] & 64U) >> 6);

  /* DataTypeConversion: '<S301>/Data Type Conversion30' incorporates:
   *  ArithShift: '<S359>/Str_Over_SpdError_S'
   *  DataTypeConversion: '<S359>/Str_Over_SpdError_Convert'
   *  DataTypeConversion: '<S359>/Str_Over_SpdErrorcv'
   *  S-Function (sfix_bitop): '<S359>/Str_Over_SpdError_L'
   *  Saturate: '<S359>/Str_Over_SpdError_sat'
   */
  FSAC2021_V1_B.DataTypeConversion30 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_B.Str_Error_o4[0] & 2U) >> 1);

  /* DataTypeConversion: '<S301>/Data Type Conversion31' incorporates:
   *  ArithShift: '<S359>/Str_Over_PosError_S'
   *  DataTypeConversion: '<S359>/Str_Over_PosError_Convert'
   *  DataTypeConversion: '<S359>/Str_Over_PosErrorcv'
   *  S-Function (sfix_bitop): '<S359>/Str_Over_PosError_L'
   *  Saturate: '<S359>/Str_Over_PosError_sat'
   */
  FSAC2021_V1_B.DataTypeConversion31 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_B.Str_Error_o4[1] & 128U) >> 7);

  /* DataTypeConversion: '<S301>/Data Type Conversion32' incorporates:
   *  ArithShift: '<S359>/Str_Limit_Pos_Alarm_S'
   *  DataTypeConversion: '<S359>/Str_Limit_Pos_Alarm_Convert'
   *  DataTypeConversion: '<S359>/Str_Limit_Pos_Alarmcv'
   *  S-Function (sfix_bitop): '<S359>/Str_Limit_Pos_Alarm_L'
   *  Saturate: '<S359>/Str_Limit_Pos_Alarm_sat'
   */
  FSAC2021_V1_B.DataTypeConversion32 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_B.Str_Error_o4[0] & 128U) >> 7);

  /* DataTypeConversion: '<S301>/Data Type Conversion33' incorporates:
   *  ArithShift: '<S359>/Str_I2t_Warning_S'
   *  DataTypeConversion: '<S359>/Str_I2t_Warning_Convert'
   *  DataTypeConversion: '<S359>/Str_I2t_Warningcv'
   *  S-Function (sfix_bitop): '<S359>/Str_I2t_Warning_L'
   *  Saturate: '<S359>/Str_I2t_Warning_sat'
   */
  FSAC2021_V1_B.DataTypeConversion33 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_B.Str_Error_o4[1] & 2U) >> 1);

  /* DataTypeConversion: '<S301>/Data Type Conversion34' incorporates:
   *  ArithShift: '<S359>/Str_I2t_Alarm_S'
   *  DataTypeConversion: '<S359>/Str_I2t_Alarm_Convert'
   *  DataTypeConversion: '<S359>/Str_I2t_Alarmcv'
   *  S-Function (sfix_bitop): '<S359>/Str_I2t_Alarm_L'
   *  Saturate: '<S359>/Str_I2t_Alarm_sat'
   */
  FSAC2021_V1_B.DataTypeConversion34 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_B.Str_Error_o4[1] & 32U) >> 5);

  /* DataTypeConversion: '<S301>/Data Type Conversion35' incorporates:
   *  ArithShift: '<S359>/Str_Flash_Error_S'
   *  DataTypeConversion: '<S359>/Str_Flash_Error_Convert'
   *  DataTypeConversion: '<S359>/Str_Flash_Errorcv'
   *  S-Function (sfix_bitop): '<S359>/Str_Flash_Error_L'
   *  Saturate: '<S359>/Str_Flash_Error_sat'
   */
  FSAC2021_V1_B.DataTypeConversion35 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_B.Str_Error_o4[0] & 32U) >> 5);

  /* DataTypeConversion: '<S301>/Data Type Conversion36' incorporates:
   *  DataTypeConversion: '<S359>/Str_Encoder_Error_Convert'
   *  DataTypeConversion: '<S359>/Str_Encoder_Errorcv'
   *  S-Function (sfix_bitop): '<S359>/Str_Encoder_Error_L'
   *  Saturate: '<S359>/Str_Encoder_Error_sat'
   */
  FSAC2021_V1_B.DataTypeConversion36 = (uint8_T)(real32_T)
    (FSAC2021_V1_B.Str_Error_o4[0] & 1);

  /* DataTypeConversion: '<S301>/Data Type Conversion37' incorporates:
   *  ArithShift: '<S359>/Str_Curr_Error_Fault_S'
   *  DataTypeConversion: '<S359>/Str_Curr_Error_Fault_Convert'
   *  DataTypeConversion: '<S359>/Str_Curr_Error_Faultcv'
   *  S-Function (sfix_bitop): '<S359>/Str_Curr_Error_Fault_L'
   *  Saturate: '<S359>/Str_Curr_Error_Fault_sat'
   */
  FSAC2021_V1_B.DataTypeConversion37 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_B.Str_Error_o4[0] & 64U) >> 6);

  /* S-Function (ec55xx_canreceiveslb): '<S248>/AMI' */

  /* Receive CAN message */
  {
    uint8 CAN0BUF16RX[1]= { 0 };

    uint8 can0buf16looprx= 0;
    FSAC2021_V1_B.AMI_o3= 1169;
    FSAC2021_V1_B.AMI_o5= 1;
    FSAC2021_V1_B.AMI_o2= ec_can_receive(0,16, CAN0BUF16RX);
    FSAC2021_V1_B.AMI_o4= CAN0BUF16RX[can0buf16looprx];
    can0buf16looprx++;
  }

  /* Call the system: <S248>/AMI_DUTY */

  /* Output and update for function-call system: '<S248>/AMI_DUTY' */

  /* Saturate: '<S290>/assi_status_sat' incorporates:
   *  DataTypeConversion: '<S290>/assi_status_Convert'
   *  DataTypeConversion: '<S290>/assi_statuscv'
   */
  FSAC2021_V1_B.assi_status_sat = FSAC2021_V1_B.AMI_o4;

  /* DataTypeConversion: '<S248>/Data Type Conversion' */
  AMI = FSAC2021_V1_B.assi_status_sat;

  /* S-Function (ec55xx_canreceiveslb): '<S248>/AMI1' */

  /* Receive CAN message */
  {
    uint8 CAN0BUF26RX[1]= { 0 };

    uint8 can0buf26looprx= 0;
    FSAC2021_V1_B.AMI1_o3= 1168;
    FSAC2021_V1_B.AMI1_o5= 1;
    AMI_HEART= ec_can_receive(0,26, CAN0BUF26RX);
    FSAC2021_V1_B.AMI1_o4= CAN0BUF26RX[can0buf26looprx];
    can0buf26looprx++;
  }

  /* Nothing to do for system: <S248>/Heartt */

  /* S-Function (fcncallgen): '<S7>/Function-Call Generator1' incorporates:
   *  SubSystem: '<S4>/Subsystem'
   */
  /* DataTypeConversion: '<S197>/Data Type Conversion' */
  light_blue = (rtb_RateTransition17_f != 0);

  /* S-Function (ec55xx_pdsslb): '<S197>/Blue_Pin' */

  /* Set level light_blue for the specified power driver switch */
  ec_gpio_write(195,light_blue);

  /* DataTypeConversion: '<S197>/Data Type Conversion1' */
  FSAC2021_V1_B.DataTypeConversion1_h = (rtb_RateTransition18_o != 0);

  /* S-Function (ec55xx_pdsslb): '<S197>/Yellow_Pin' */

  /* Set level FSAC2021_V1_B.DataTypeConversion1_h for the specified power driver switch */
  ec_gpio_write(198,FSAC2021_V1_B.DataTypeConversion1_h);

  /* DataTypeConversion: '<S197>/Data Type Conversion2' */
  Buzzer_pin = (rtb_RateTransition19_j != 0);

  /* S-Function (ec55xx_pdsslb): '<S197>/Buzzer_Pin' */

  /* Set level Buzzer_pin for the specified power driver switch */
  ec_gpio_write(193,Buzzer_pin);

  /* DataTypeConversion: '<S197>/Data Type Conversion3' */
  Stafe_Relay_pin = rtb_RateTransition26_p;

  /* S-Function (ec55xx_pdsslb): '<S197>/Safety_Relay ' */

  /* Set level Stafe_Relay_pin for the specified power driver switch */
  ec_gpio_write(179,Stafe_Relay_pin);

  /* DataTypeConversion: '<S197>/Data Type Conversion4' */
  V48_relay = (rtb_RateTransition4 != 0.0);

  /* S-Function (ec55xx_pdsslb): '<S197>/48V_Relay' */

  /* Set level V48_relay for the specified power driver switch */
  ec_gpio_write(181,V48_relay);

  /* S-Function (fcncallgen): '<S7>/Function-Call Generator1' incorporates:
   *  SubSystem: '<S2>/50ms_Duty'
   */
  /* DataTypeConversion: '<S197>/Data Type Conversion6' incorporates:
   *  Logic: '<S65>/Logical Operator'
   *  Logic: '<S65>/Logical Operator1'
   */
  R2D_Voltage = ((!rtb_RateTransition33) && rtb_Nogas1Hasgas_o);

  /* S-Function (ec55xx_pdsslb): '<S197>/R2D_Pin' */

  /* Set level R2D_Voltage for the specified power driver switch */
  ec_gpio_write(182,R2D_Voltage);

  /* DataTypeConversion: '<S197>/Data Type Conversion8' */
  IMD = (rtb_RateTransition47 != 0);

  /* S-Function (ec55xx_pdsslb): '<S197>/VCU_Valve1' */

  /* Set level IMD for the specified power driver switch */
  ec_gpio_write(190,IMD);

  /* S-Function (fcncallgen): '<S7>/Function-Call Generator1' incorporates:
   *  SubSystem: '<S2>/50ms_Duty'
   */
  /* DataTypeConversion: '<S197>/Data Type Conversion9' incorporates:
   *  SignalConversion: '<S65>/OutportBufferForEBS_Light_Sts'
   */
  EBS = (rtb_RateTransition59 != 0);

  /* S-Function (ec55xx_pdsslb): '<S197>/VCU_Valve2' */

  /* Set level EBS for the specified power driver switch */
  ec_gpio_write(187,EBS);

  /* S-Function (fcncallgen): '<S7>/Function-Call Generator1' incorporates:
   *  SubSystem: '<S2>/50ms_Duty'
   */
  /* DataTypeConversion: '<S197>/Data Type Conversion10' incorporates:
   *  SignalConversion: '<S65>/OutportBufferForBMS_Light_Sts'
   */
  BMS_LIGHT = (rtb_RateTransition46_e != 0);

  /* S-Function (ec55xx_pdsslb): '<S197>/VCU_Valve3' */

  /* Set level BMS_LIGHT for the specified power driver switch */
  ec_gpio_write(188,BMS_LIGHT);

  /* Switch: '<S197>/Switch' incorporates:
   *  Constant: '<S198>/Constant'
   *  DataTypeConversion: '<S197>/Data Type Conversion7'
   *  RelationalOperator: '<S198>/Compare'
   */
  brake_light = (Read_liquid_presuress >= 30);

  /* S-Function (ec55xx_pdsslb): '<S197>/VCU_Valve4' */

  /* Set level brake_light for the specified power driver switch */
  ec_gpio_write(197,brake_light);

  /* S-Function (fcncallgen): '<S7>/Function-Call Generator1' incorporates:
   *  SubSystem: '<S1>/Subsystem2'
   */
  /* Saturate: '<S56>/Brake_mtr_goalpos_sat' incorporates:
   *  DataTypeConversion: '<S12>/Data Type Conversion17'
   */
  if ((real32_T)pulses > 2.14748365E+9F) {
    rtb_RateTransition46 = 2.14748365E+9F;
  } else if ((real32_T)pulses < -2.14748365E+9F) {
    rtb_RateTransition46 = -2.14748365E+9F;
  } else {
    rtb_RateTransition46 = (real32_T)pulses;
  }

  /* Rounding: '<S56>/Brake_mtr_goalposRon' incorporates:
   *  Saturate: '<S56>/Brake_mtr_goalpos_sat'
   */
  rtb_RateTransition46 = rt_roundf_snf(rtb_RateTransition46);

  /* Saturate: '<S56>/Brake_mtr_goalpossatAbs' incorporates:
   *  Abs: '<S56>/Brake_mtr_goalposABS'
   */
  rtb_RateTransition11 = (real32_T)fabs(rtb_RateTransition46);

  /* RelationalOperator: '<S56>/Brake_mtr_goalposROP' */
  rtb_RateTransition26_p = (rtb_RateTransition46 < 0.0F);

  /* Switch: '<S56>/Brake_mtr_goalposSW' incorporates:
   *  Sum: '<S56>/Brake_mtr_goalpossubcon'
   *  Switch: '<S56>/Brake_mtr_goalpos_swtsig'
   */
  if (rtb_RateTransition26_p) {
    rtb_RateTransition11 = 4.2949673E+9F - rtb_RateTransition11;
  }

  /* End of Switch: '<S56>/Brake_mtr_goalposSW' */

  /* S-Function (sfix_bitop): '<S56>/Brake_mtr_goalpos_L' incorporates:
   *  DataTypeConversion: '<S56>/Brake_mtr_goalpos_Convert'
   */
  rtb_Drive_Speed_Control_And = (uint32_T)rtb_RateTransition11;

  /* DataTypeConversion: '<S56>/Brake_mtr_goalposBitCov2' incorporates:
   *  Constant: '<S56>/Brake_mtr_goalpos_And2_C'
   *  S-Function (sfix_bitop): '<S56>/Brake_mtr_goalpos_And2'
   */
  FSAC2021_V1_B.Brake_mtr_goalposBitCov2 = (uint8_T)(rtb_Drive_Speed_Control_And
    & 255U);

  /* DataTypeConversion: '<S56>/Brake_mtr_goalposCOV' incorporates:
   *  Constant: '<S56>/Brake_mtr_goalposoutput4_C'
   *  Product: '<S56>/Brake_mtr_goalpos_D1'
   */
  FSAC2021_V1_B.Brake_mtr_goalposCOV = (uint8_T)((real_T)
    rtb_Drive_Speed_Control_And / 1.6777216E+7);

  /* DataTypeConversion: '<S56>/Brake_mtr_goalposCOV1' incorporates:
   *  Constant: '<S56>/Brake_mtr_goalposoutput3_C'
   *  Product: '<S56>/Brake_mtr_goalpos_D2'
   *  S-Function (sfix_bitop): '<S56>/Brake_mtr_goalpos_And'
   */
  FSAC2021_V1_B.Brake_mtr_goalposCOV1 = (uint8_T)((real_T)((int32_T)
    rtb_Drive_Speed_Control_And & 16777215) / 65536.0);

  /* DataTypeConversion: '<S56>/Brake_mtr_goalposCOV2' incorporates:
   *  Constant: '<S56>/Brake_mtr_goalposoutput2_C'
   *  Product: '<S56>/Brake_mtr_goalpos_D3'
   *  S-Function (sfix_bitop): '<S56>/Brake_mtr_goalpos_And1'
   */
  FSAC2021_V1_B.Brake_mtr_goalposCOV2 = (uint8_T)((real_T)((int32_T)
    rtb_Drive_Speed_Control_And & 65535) / 256.0);

  /* S-Function (ec55xx_cantransmitslb): '<S12>/CANTransmit3' */

  /*Transmit CAN message*/
  {
    uint8 CAN0BUF58TX[4];
    uint8 can0buf58looptx= 0;
    CAN0BUF58TX[can0buf58looptx]= FSAC2021_V1_B.Brake_mtr_goalposCOV;
    can0buf58looptx++;
    CAN0BUF58TX[can0buf58looptx]= FSAC2021_V1_B.Brake_mtr_goalposCOV1;
    can0buf58looptx++;
    CAN0BUF58TX[can0buf58looptx]= FSAC2021_V1_B.Brake_mtr_goalposCOV2;
    can0buf58looptx++;
    CAN0BUF58TX[can0buf58looptx]= FSAC2021_V1_B.Brake_mtr_goalposBitCov2;
    can0buf58looptx++;
    FSAC2021_V1_B.CANTransmit3= ec_can_transmit(0, 58, 0, 358U, 4, CAN0BUF58TX);
  }

  /* Saturate: '<S57>/Drive_Speed_Control_sat' */
  if (ACC > 1500.0F) {
    rtb_RateTransition46 = 1500.0F;
  } else if (ACC < 0.0F) {
    rtb_RateTransition46 = 0.0F;
  } else {
    rtb_RateTransition46 = ACC;
  }

  /* S-Function (sfix_bitop): '<S57>/Drive_Speed_Control_L' incorporates:
   *  DataTypeConversion: '<S57>/Drive_Speed_Control_Convert'
   *  Rounding: '<S57>/Drive_Speed_ControlRon'
   *  Saturate: '<S57>/Drive_Speed_Control_1sat'
   *  Saturate: '<S57>/Drive_Speed_Control_sat'
   */
  rtb_Drive_Speed_Control_And = (uint32_T)rt_roundf_snf(rtb_RateTransition46) &
    65535U;

  /* DataTypeConversion: '<S57>/BitCov' incorporates:
   *  Constant: '<S57>/Drive_Speed_Control_And_C'
   *  S-Function (sfix_bitop): '<S57>/Drive_Speed_Control_And'
   */
  FSAC2021_V1_B.BitCov = (uint8_T)(rtb_Drive_Speed_Control_And & 255U);

  /* DataTypeConversion: '<S57>/Drive_Speed_ControlCOV' incorporates:
   *  Constant: '<S57>/Drive_Speed_Controloutput2_C'
   *  Product: '<S57>/Drive_Speed_Control_D1'
   */
  FSAC2021_V1_B.Drive_Speed_ControlCOV = (uint8_T)((real_T)
    rtb_Drive_Speed_Control_And / 256.0);

  /* S-Function (ec55xx_cantransmitslb): '<S12>/CANTransmit4' */

  /*Transmit CAN message*/
  {
    uint8 CAN1BUF15TX[2];
    uint8 can1buf15looptx= 0;
    CAN1BUF15TX[can1buf15looptx]= FSAC2021_V1_B.BitCov;
    can1buf15looptx++;
    CAN1BUF15TX[can1buf15looptx]= FSAC2021_V1_B.Drive_Speed_ControlCOV;
    can1buf15looptx++;
    To_MOTOR_OK= ec_can_transmit(1, 15, 1, 2197885092U, 2, CAN1BUF15TX);
  }

  /* S-Function (ec55xx_cantransmitslb): '<S11>/CANTransmit' */

  /*Transmit CAN message*/
  {
    uint8 CAN0BUF63TX[6];
    uint8 can0buf63looptx= 0;
    CAN0BUF63TX[can0buf63looptx]= FSAC2021_V1_B.MOTEC_CONTROL.Conv1;
    can0buf63looptx++;
    CAN0BUF63TX[can0buf63looptx]= FSAC2021_V1_B.MOTEC_CONTROL.Conv2;
    can0buf63looptx++;
    CAN0BUF63TX[can0buf63looptx]= FSAC2021_V1_B.MOTEC_CONTROL.Conv3;
    can0buf63looptx++;
    CAN0BUF63TX[can0buf63looptx]= FSAC2021_V1_B.MOTEC_CONTROL.Conv4;
    can0buf63looptx++;
    CAN0BUF63TX[can0buf63looptx]= FSAC2021_V1_B.MOTEC_CONTROL.Conv5;
    can0buf63looptx++;
    CAN0BUF63TX[can0buf63looptx]= FSAC2021_V1_B.MOTEC_CONTROL.Conv6;
    can0buf63looptx++;
    Metoc_Move= ec_can_transmit(0, 63, 0, 513U, 6, CAN0BUF63TX);
  }

  /* S-Function (ec55xx_cantransmitslb): '<S11>/CANTransmit1' */

  /*Transmit CAN message*/
  {
    uint8 CAN0BUF62TX[2];
    uint8 can0buf62looptx= 0;
    CAN0BUF62TX[can0buf62looptx]= FSAC2021_V1_B.Conv1_p;
    can0buf62looptx++;
    CAN0BUF62TX[can0buf62looptx]= FSAC2021_V1_B.Conv2_l;
    can0buf62looptx++;
    MNT_SEND= ec_can_transmit(0, 62, 0, 0U, 2, CAN0BUF62TX);
  }

  /* S-Function (ec55xx_cantransmitslb): '<S11>/CANTransmit2' */

  /*Transmit CAN message*/
  {
    uint8 CAN0BUF61TX[6];
    uint8 can0buf61looptx= 0;
    CAN0BUF61TX[can0buf61looptx]= FSAC2021_V1_B.Conv1;
    can0buf61looptx++;
    CAN0BUF61TX[can0buf61looptx]= FSAC2021_V1_B.Conv2;
    can0buf61looptx++;
    CAN0BUF61TX[can0buf61looptx]= FSAC2021_V1_B.Conv3;
    can0buf61looptx++;
    CAN0BUF61TX[can0buf61looptx]= FSAC2021_V1_B.Conv4;
    can0buf61looptx++;
    CAN0BUF61TX[can0buf61looptx]= FSAC2021_V1_B.Conv5;
    can0buf61looptx++;
    CAN0BUF61TX[can0buf61looptx]= FSAC2021_V1_B.Conv6;
    can0buf61looptx++;
    ENCODER_SEND= ec_can_transmit(0, 61, 0, 1537U, 6, CAN0BUF61TX);
  }

  /* DataTypeConversion: '<S11>/Data Type Conversion11' */
  rtb_RateTransition46 = FSAC2021_V1_B.Encoder_Msg_Data[0];

  /* DataTypeConversion: '<S11>/Data Type Conversion12' */
  rtb_RateTransition11 = FSAC2021_V1_B.Encoder_Msg_Data[1];

  /* DataTypeConversion: '<S11>/Data Type Conversion13' */
  rtb_DataTypeConversion13 = FSAC2021_V1_B.Encoder_Msg_Data[2];

  /* DataTypeConversion: '<S11>/Data Type Conversion14' */
  rtb_DataTypeConversion14 = FSAC2021_V1_B.Encoder_Msg_Data[3];

  /* DataTypeConversion: '<S11>/Data Type Conversion16' */
  rtb_DataTypeConversion16 = FSAC2021_V1_B.Encoder_Msg_Data[5];

  /* Outputs for Atomic SubSystem: '<S11>/Brk_Mtr_Enbale' */

  /* S-Function (ec55xx_cantransmitslb): '<S24>/CANTransmit' */

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
    BUC_Enable_Flag= ec_can_transmit(0, 8, 0, 353U, 8, CAN0BUF8TX);
  }

  /* End of Outputs for SubSystem: '<S11>/Brk_Mtr_Enbale' */

  /* S-Function (ec55xx_cantransmitslb): '<S13>/CANTransmit1' */

  /*Transmit CAN message*/
  {
    uint8 CAN1BUF13TX[8];
    uint8 can1buf13looptx= 0;
    CAN1BUF13TX[can1buf13looptx]= FSAC2021_V1_ConstB.DataTypeConversion[0];
    can1buf13looptx++;
    CAN1BUF13TX[can1buf13looptx]= FSAC2021_V1_ConstB.DataTypeConversion[1];
    can1buf13looptx++;
    CAN1BUF13TX[can1buf13looptx]= FSAC2021_V1_ConstB.DataTypeConversion[2];
    can1buf13looptx++;
    CAN1BUF13TX[can1buf13looptx]= FSAC2021_V1_ConstB.DataTypeConversion[3];
    can1buf13looptx++;
    CAN1BUF13TX[can1buf13looptx]= FSAC2021_V1_ConstB.DataTypeConversion[4];
    can1buf13looptx++;
    CAN1BUF13TX[can1buf13looptx]= FSAC2021_V1_ConstB.DataTypeConversion[5];
    can1buf13looptx++;
    CAN1BUF13TX[can1buf13looptx]= FSAC2021_V1_ConstB.DataTypeConversion[6];
    can1buf13looptx++;
    CAN1BUF13TX[can1buf13looptx]= FSAC2021_V1_ConstB.DataTypeConversion[7];
    can1buf13looptx++;
    read_speed= ec_can_transmit(1, 13, 1, 2181107875U, 8, CAN1BUF13TX);
  }

  /* RateTransition: '<S2>/Rate Transition15' */
  rtb_RateTransition24_e = FSAC2021_V1_DW.RateTransition15_Buffer0_e;

  /* RateTransition: '<S3>/RateTransition21' */
  if (FSAC2021_V1_M->Timing.RateInteraction.TID6_7) {
    FSAC2021_V1_B.RateTransition21 = FSAC2021_V1_B.DataTypeConversion51;

    /* RateTransition: '<S3>/RateTransition17' */
    FSAC2021_V1_B.RateTransition17 = FSAC2021_V1_B.DataTypeConversion52;

    /* RateTransition: '<S3>/RateTransition16' */
    FSAC2021_V1_B.RateTransition16 = FSAC2021_V1_B.DataTypeConversion53;

    /* RateTransition: '<S3>/RateTransition2' */
    FSAC2021_V1_B.RateTransition2 = FSAC2021_V1_B.DataTypeConversion54;

    /* RateTransition: '<S3>/RateTransition18' */
    FSAC2021_V1_B.RateTransition18 = FSAC2021_V1_B.DataTypeConversion55;

    /* RateTransition: '<S3>/RateTransition19' */
    FSAC2021_V1_B.RateTransition19 = FSAC2021_V1_B.DataTypeConversion56;

    /* RateTransition: '<S3>/RateTransition20' */
    FSAC2021_V1_B.RateTransition20 = FSAC2021_V1_B.DataTypeConversion57;

    /* RateTransition: '<S3>/RateTransition9' */
    FSAC2021_V1_B.RateTransition9 = FSAC2021_V1_B.DataTypeConversion58;

    /* RateTransition: '<S3>/RateTransition7' */
    FSAC2021_V1_B.RateTransition7 = FSAC2021_V1_B.DataTypeConversion59;

    /* RateTransition: '<S3>/RateTransition6' */
    FSAC2021_V1_B.RateTransition6 = FSAC2021_V1_B.DataTypeConversion60;

    /* RateTransition: '<S3>/RateTransition11' */
    FSAC2021_V1_B.RateTransition11 = FSAC2021_V1_B.DataTypeConversion61;

    /* RateTransition: '<S3>/RateTransition8' */
    FSAC2021_V1_B.RateTransition8 = FSAC2021_V1_B.DataTypeConversion62;

    /* RateTransition: '<S3>/RateTransition10' */
    FSAC2021_V1_B.RateTransition10 = FSAC2021_V1_B.DataTypeConversion50;

    /* RateTransition: '<S3>/RateTransition3' */
    FSAC2021_V1_B.RateTransition3 = FSAC2021_V1_B.DataTypeConversion40;

    /* RateTransition: '<S3>/RateTransition13' */
    FSAC2021_V1_B.RateTransition13 = FSAC2021_V1_B.DataTypeConversion39;

    /* RateTransition: '<S3>/RateTransition12' */
    FSAC2021_V1_B.RateTransition12 = FSAC2021_V1_B.DataTypeConversion41;

    /* RateTransition: '<S3>/RateTransition5' */
    FSAC2021_V1_B.RateTransition5 = FSAC2021_V1_B.DataTypeConversion43;

    /* RateTransition: '<S3>/RateTransition4' */
    FSAC2021_V1_B.RateTransition4 = FSAC2021_V1_B.DataTypeConversion47;

    /* RateTransition: '<S3>/RateTransition14' */
    FSAC2021_V1_B.RateTransition14 = FSAC2021_V1_B.DataTypeConversion48;

    /* RateTransition: '<S3>/RateTransition15' */
    FSAC2021_V1_B.RateTransition15_b = FSAC2021_V1_B.DataTypeConversion49;

    /* RateTransition: '<S3>/RateTransition1' */
    FSAC2021_V1_B.RateTransition1 = Read_compare_OutVolt;

    /* RateTransition: '<S3>/RateTransition27' */
    ASMS_VALUE = FSAC2021_V1_B.DataTypeConversion4_f;

    /* RateTransition: '<S3>/RateTransition23' */
    FSAC2021_V1_B.RateTransition23 = Read_liquid_presuress;
  }

  /* End of RateTransition: '<S3>/RateTransition21' */

  /* RateTransition: '<S3>/Rate Transition44' */
  rtb_RateTransition59 = FSAC2021_V1_DW.RateTransition44_Buffer0;

  /* S-Function (fcncallgen): '<S226>/50ms' incorporates:
   *  SubSystem: '<S226>/daq50ms'
   */

  /* S-Function (ec55xx_ccpslb1): '<S239>/CCPDAQ' */
  ccpDaq(2);

  /* Update for RateTransition: '<S1>/Rate Transition13' */
  FSAC2021_V1_DW.RateTransition13_Buffer0 = FSAC2021_V1_B.Motor_Currt_Speed_sat;

  /* Update for UnitDelay: '<S2>/Unit Delay6' */
  FSAC2021_V1_DW.UnitDelay6_DSTATE = FSAC2021_V1_B.Merge1;

  /* Update for RateTransition: '<S5>/Rate Transition18' */
  FSAC2021_V1_DW.RateTransition18_Buffer0 = FSAC2021_V1_B.Read_RL_WhlSpd;

  /* Update for RateTransition: '<S5>/Rate Transition19' */
  FSAC2021_V1_DW.RateTransition19_Buffer0 = FSAC2021_V1_B.Read_RR_WhlSpd;

  /* Update for RateTransition: '<S5>/Rate Transition25' */
  FSAC2021_V1_DW.RateTransition25_Buffer0_d = FSAC2021_V1_B.Read_RL_WhlSpd;

  /* Update for RateTransition: '<S5>/Rate Transition26' */
  FSAC2021_V1_DW.RateTransition26_Buffer0 = FSAC2021_V1_B.Read_RR_WhlSpd;

  /* Update for RateTransition: '<S5>/Rate Transition22' */
  FSAC2021_V1_DW.RateTransition22_Buffer0 = Read_Right_Acc_Disp1;

  /* Update for RateTransition: '<S5>/Rate Transition14' */
  FSAC2021_V1_DW.RateTransition14_Buffer0 = Read_EBS_Gas_Prs1;

  /* Update for RateTransition: '<S5>/Rate Transition24' */
  FSAC2021_V1_DW.RateTransition24_Buffer0 = Read_EBS_Gas_Prs2;

  /* Update for UnitDelay: '<S2>/Unit Delay3' */
  FSAC2021_V1_DW.UnitDelay3_DSTATE_i = rtb_RateTransition24_e;

  /* Update for UnitDelay: '<S2>/Unit Delay7' */
  FSAC2021_V1_DW.UnitDelay7_DSTATE = FSAC2021_V1_B.Original_Flag;

  /* Update for UnitDelay: '<S8>/Unit Delay5' */
  FSAC2021_V1_DW.UnitDelay5_DSTATE_e = AMI;

  /* Update for UnitDelay: '<S3>/Unit Delay2' */
  FSAC2021_V1_DW.UnitDelay2_DSTATE_h = rtb_RateTransition59;

  /* Update for UnitDelay: '<S1>/Unit Delay3' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   */
  FSAC2021_V1_DW.UnitDelay3_DSTATE = MultiportSwitch;

  /* Update for UnitDelay: '<S1>/Unit Delay4' */
  FSAC2021_V1_DW.UnitDelay4_DSTATE = DataTypeConversion10_h;

  /* Update for UnitDelay: '<S11>/Unit Delay10' */
  FSAC2021_V1_DW.UnitDelay10_DSTATE = FSAC2021_V1_B.NMT_nodeorder;

  /* Update for UnitDelay: '<S11>/Unit Delay9' */
  FSAC2021_V1_DW.UnitDelay9_DSTATE = FSAC2021_V1_B.NMT_nodectrl;

  /* Update for UnitDelay: '<S11>/Unit Delay11' */
  FSAC2021_V1_DW.UnitDelay11_DSTATE = rtb_RateTransition46;

  /* Update for UnitDelay: '<S11>/Unit Delay12' */
  FSAC2021_V1_DW.UnitDelay12_DSTATE = rtb_RateTransition11;

  /* Update for UnitDelay: '<S11>/Unit Delay13' */
  FSAC2021_V1_DW.UnitDelay13_DSTATE = (real32_T)rtb_DataTypeConversion13;

  /* Update for UnitDelay: '<S11>/Unit Delay14' */
  FSAC2021_V1_DW.UnitDelay14_DSTATE = (real32_T)rtb_DataTypeConversion14;

  /* Update for UnitDelay: '<S11>/Unit Delay17' incorporates:
   *  Constant: '<S11>/Constant'
   */
  FSAC2021_V1_DW.UnitDelay17_DSTATE = 0U;

  /* Update for UnitDelay: '<S11>/Unit Delay15' */
  FSAC2021_V1_DW.UnitDelay15_DSTATE = FSAC2021_V1_B.Encoder_Msg_Data[4];

  /* Update for UnitDelay: '<S11>/Unit Delay16' */
  FSAC2021_V1_DW.UnitDelay16_DSTATE = (real32_T)rtb_DataTypeConversion16;

  /* Update for UnitDelay: '<S11>/Unit Delay6' */
  FSAC2021_V1_DW.UnitDelay6_DSTATE_n = FSAC2021_V1_B.Fault_Resrt;

  /* Update for UnitDelay: '<S11>/Unit Delay8' */
  FSAC2021_V1_DW.UnitDelay8_DSTATE = FSAC2021_V1_B.Position_set;

  /* Update for UnitDelay: '<S11>/Unit Delay4' */
  FSAC2021_V1_DW.UnitDelay4_DSTATE_g = FSAC2021_V1_B.New_Set_Point_Ctrl;

  /* Update for UnitDelay: '<S11>/Unit Delay7' */
  FSAC2021_V1_DW.UnitDelay7_DSTATE_g = FSAC2021_V1_B.Halt_Ctrl;

  /* Update for UnitDelay: '<S11>/Unit Delay5' */
  FSAC2021_V1_DW.UnitDelay5_DSTATE_p = FSAC2021_V1_B.Abs_or_Rel_Ctrl;

  /* Update for UnitDelay: '<S11>/Unit Delay' */
  FSAC2021_V1_DW.UnitDelay_DSTATE = FSAC2021_V1_B.Switch_On_Ctrl;

  /* Update for UnitDelay: '<S11>/Unit Delay2' */
  FSAC2021_V1_DW.UnitDelay2_DSTATE_o = FSAC2021_V1_B.Quick_Stop_Ctrl;

  /* Update for UnitDelay: '<S11>/Unit Delay1' */
  FSAC2021_V1_DW.UnitDelay1_DSTATE_n = FSAC2021_V1_B.Enable_Voltage_Ctrl;

  /* Update for UnitDelay: '<S11>/Unit Delay3' */
  FSAC2021_V1_DW.UnitDelay3_DSTATE_p = FSAC2021_V1_B.Enable_Operation_Ctrl;

  /* Update for RateTransition: '<S2>/Rate Transition41' */
  FSAC2021_V1_DW.RateTransition41_Buffer0 = FSAC2021_V1_B.ASSI_State;

  /* Update absolute time */
  /* The "clockTick6" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.05, which is the step size
   * of the task. Size of "clockTick6" ensures timer will not overflow during the
   * application lifespan selected.
   */
  FSAC2021_V1_M->Timing.clockTick6++;
}

/* Model step function for TID7 */
void FSAC2021_V1_step7(void)           /* Sample time: [0.1s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_DataTypeConversion1;
  uint8_T rtb_RateTransition30;
  uint8_T rtb_DataTypeConversion1_e;
  uint8_T rtb_DataTypeConversion2;
  uint8_T rtb_DataTypeConversion3;
  uint8_T rtb_DataTypeConversion4;
  uint8_T rtb_DataTypeConversion5;
  boolean_T rtb_HiddenBuf_InsertedFor_Subsy;
  boolean_T rtb_HiddenBuf_InsertedFor_Sub_m;
  boolean_T rtb_HiddenBuf_InsertedFor_Sub_i;
  uint16_T rtb_RateTransition34;
  uint16_T rtb_RateTransition35;
  uint16_T rtb_RateTransition37;
  uint16_T rtb_RateTransition38;
  uint8_T rtb_RateTransition1_g;
  uint8_T rtb_RateTransition2;
  uint8_T rtb_RateTransition3;
  uint8_T rtb_RateTransition4;
  uint8_T rtb_RateTransition5;
  uint8_T rtb_RateTransition6;
  uint8_T rtb_RateTransition7;
  uint8_T rtb_RateTransition8;
  uint8_T rtb_RateTransition9;
  uint8_T rtb_RateTransition10;
  uint8_T rtb_RateTransition11;
  uint8_T rtb_RateTransition12_j;
  uint8_T rtb_RateTransition13;
  uint8_T rtb_RateTransition14;
  uint8_T rtb_RateTransition15_d;
  uint8_T rtb_RateTransition16;
  real_T rtb_RateTransition17;
  real_T rtb_RateTransition18;
  real_T rtb_RateTransition19;
  real_T rtb_RateTransition20;
  real_T rtb_RateTransition21;
  real_T rtb_RateTransition22;
  real_T rtb_RateTransition23;
  real_T rtb_RateTransition1;
  boolean_T rtb_LogicalOperator1;
  uint8_T DataTypeConversion_e;
  boolean_T LogicalOperator1;

  /* RateTransition: '<S3>/Rate Transition34' */
  rtb_RateTransition34 = Read_Lft_Acc_Disp;

  /* RateTransition: '<S3>/Rate Transition35' */
  rtb_RateTransition35 = Read_Right_Acc_Disp1;

  /* RateTransition: '<S3>/Rate Transition37' */
  rtb_RateTransition37 = Read_EBS_Gas_Prs1;

  /* RateTransition: '<S3>/Rate Transition38' */
  rtb_RateTransition38 = Read_EBS_Gas_Prs2;

  /* RateTransition: '<S3>/Rate Transition1' */
  rtb_RateTransition1_g = FSAC2021_V1_B.DataTypeConversion22_f;

  /* RateTransition: '<S3>/Rate Transition2' */
  rtb_RateTransition2 = FSAC2021_V1_B.DataTypeConversion23_c;

  /* RateTransition: '<S3>/Rate Transition3' */
  rtb_RateTransition3 = FSAC2021_V1_B.DataTypeConversion24_k;

  /* RateTransition: '<S3>/Rate Transition4' */
  rtb_RateTransition4 = FSAC2021_V1_B.DataTypeConversion25;

  /* RateTransition: '<S3>/Rate Transition5' */
  rtb_RateTransition5 = FSAC2021_V1_B.DataTypeConversion26;

  /* RateTransition: '<S3>/Rate Transition6' */
  rtb_RateTransition6 = FSAC2021_V1_B.DataTypeConversion27;

  /* RateTransition: '<S3>/Rate Transition7' */
  rtb_RateTransition7 = FSAC2021_V1_B.DataTypeConversion28;

  /* RateTransition: '<S3>/Rate Transition8' */
  rtb_RateTransition8 = FSAC2021_V1_B.DataTypeConversion29;

  /* RateTransition: '<S3>/Rate Transition9' */
  rtb_RateTransition9 = FSAC2021_V1_B.DataTypeConversion30;

  /* RateTransition: '<S3>/Rate Transition10' */
  rtb_RateTransition10 = FSAC2021_V1_B.DataTypeConversion31;

  /* RateTransition: '<S3>/Rate Transition11' */
  rtb_RateTransition11 = FSAC2021_V1_B.DataTypeConversion32;

  /* RateTransition: '<S3>/Rate Transition12' */
  rtb_RateTransition12_j = FSAC2021_V1_B.DataTypeConversion33;

  /* RateTransition: '<S3>/Rate Transition13' */
  rtb_RateTransition13 = FSAC2021_V1_B.DataTypeConversion34;

  /* RateTransition: '<S3>/Rate Transition14' */
  rtb_RateTransition14 = FSAC2021_V1_B.DataTypeConversion35;

  /* RateTransition: '<S3>/Rate Transition15' */
  rtb_RateTransition15_d = FSAC2021_V1_B.DataTypeConversion36;

  /* RateTransition: '<S3>/Rate Transition16' */
  rtb_RateTransition16 = FSAC2021_V1_B.DataTypeConversion37;

  /* RateTransition: '<S3>/Rate Transition17' */
  rtb_RateTransition17 = FSAC2021_V1_B.DataTypeConversion10;

  /* RateTransition: '<S3>/Rate Transition18' */
  rtb_RateTransition18 = FSAC2021_V1_B.DataTypeConversion11;

  /* RateTransition: '<S3>/Rate Transition19' */
  rtb_RateTransition19 = FSAC2021_V1_B.DataTypeConversion12;

  /* RateTransition: '<S3>/Rate Transition20' */
  rtb_RateTransition20 = FSAC2021_V1_B.DataTypeConversion17;

  /* RateTransition: '<S3>/Rate Transition21' */
  rtb_RateTransition21 = FSAC2021_V1_B.DataTypeConversion18;

  /* RateTransition: '<S3>/Rate Transition22' */
  rtb_RateTransition22 = FSAC2021_V1_B.DataTypeConversion20;

  /* RateTransition: '<S3>/Rate Transition23' */
  rtb_RateTransition23 = FSAC2021_V1_B.DataTypeConversion21;

  /* RateTransition: '<S3>/Rate Transition30' */
  rtb_RateTransition30 = motor_node;

  /* RateTransition: '<S5>/Rate Transition1' */
  rtb_RateTransition1 = FSAC2021_V1_B.Switch;

  /* S-Function (fcncallgen): '<S7>/Function-Call Generator2' incorporates:
   *  SubSystem: '<S3>/DIAG'
   */
  /* Outputs for Enabled SubSystem: '<S136>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S147>/Enable'
   */
  /* RelationalOperator: '<S146>/Compare' incorporates:
   *  Constant: '<S146>/Constant'
   */
  if (FSAC2021_V1_B.RateTransition24 == 6) {
    if (!FSAC2021_V1_DW.EnabledSubsystem_MODE) {
      /* Enable for Chart: '<S147>/Chart' */
      FSAC2021_V1_DW.presentTicks = FSAC2021_V1_M->Timing.clockTick7;
      FSAC2021_V1_DW.previousTicks = FSAC2021_V1_DW.presentTicks;
      FSAC2021_V1_DW.EnabledSubsystem_MODE = true;
    }

    /* Chart: '<S147>/Chart' */
    FSAC2021_V1_DW.presentTicks = FSAC2021_V1_M->Timing.clockTick7;
    FSAC2021_V1_DW.elapsedTicks = FSAC2021_V1_DW.presentTicks -
      FSAC2021_V1_DW.previousTicks;
    FSAC2021_V1_DW.previousTicks = FSAC2021_V1_DW.presentTicks;
    if (FSAC2021_V1_DW.temporalCounter_i1_o + FSAC2021_V1_DW.elapsedTicks <= 7U)
    {
      FSAC2021_V1_DW.temporalCounter_i1_o = (uint8_T)
        (FSAC2021_V1_DW.temporalCounter_i1_o + FSAC2021_V1_DW.elapsedTicks);
    } else {
      FSAC2021_V1_DW.temporalCounter_i1_o = 7U;
    }

    /* Gateway: DIAG/DIAG/ACC/Enabled
       Subsystem/Chart */
    /* During: DIAG/DIAG/ACC/Enabled
       Subsystem/Chart */
    if (FSAC2021_V1_DW.bitsForTID7.is_active_c23_FSAC2021_V1 == 0U) {
      /* Entry: DIAG/DIAG/ACC/Enabled
         Subsystem/Chart */
      FSAC2021_V1_DW.bitsForTID7.is_active_c23_FSAC2021_V1 = 1U;

      /* Entry Internal: DIAG/DIAG/ACC/Enabled
         Subsystem/Chart */
      /* Transition: '<S148>:3' */
      FSAC2021_V1_DW.bitsForTID7.is_c23_FSAC2021_V1 = FSAC2021_V1_IN_Init_d;
      FSAC2021_V1_DW.temporalCounter_i1_o = 0U;

      /* Entry 'Init': '<S148>:1' */
      FSAC2021_V1_B.Acc_Flag = 0.0;
    } else {
      switch (FSAC2021_V1_DW.bitsForTID7.is_c23_FSAC2021_V1) {
       case FSAC2021_V1_IN_Action:
        /* During 'Action': '<S148>:2' */
        if (rtb_RateTransition1 <= 5.0) {
          /* Transition: '<S148>:6' */
          FSAC2021_V1_DW.bitsForTID7.is_c23_FSAC2021_V1 = FSAC2021_V1_IN_Action1;
          FSAC2021_V1_DW.temporalCounter_i1_o = 0U;

          /* Entry 'Action1': '<S148>:5' */
          FSAC2021_V1_B.Acc_Flag = 0.0;
        }
        break;

       case FSAC2021_V1_IN_Action1:
        /* During 'Action1': '<S148>:5' */
        if ((FSAC2021_V1_B.RateTransition23 > 200) && (rtb_RateTransition1 >=
             25.0) && (FSAC2021_V1_DW.temporalCounter_i1_o >= 5U)) {
          /* Transition: '<S148>:10' */
          FSAC2021_V1_DW.bitsForTID7.is_c23_FSAC2021_V1 = FSAC2021_V1_IN_Action;

          /* Entry 'Action': '<S148>:2' */
          FSAC2021_V1_B.Acc_Flag = 1.0;
        }
        break;

       default:
        /* During 'Init': '<S148>:1' */
        if ((FSAC2021_V1_B.RateTransition23 > 200) && (rtb_RateTransition1 >=
             25.0) && (FSAC2021_V1_DW.temporalCounter_i1_o >= 5U)) {
          /* Transition: '<S148>:4' */
          FSAC2021_V1_DW.bitsForTID7.is_c23_FSAC2021_V1 = FSAC2021_V1_IN_Action;

          /* Entry 'Action': '<S148>:2' */
          FSAC2021_V1_B.Acc_Flag = 1.0;
        }
        break;
      }
    }

    /* End of Chart: '<S147>/Chart' */
  } else {
    if (FSAC2021_V1_DW.EnabledSubsystem_MODE) {
      /* Disable for Chart: '<S147>/Chart' */
      FSAC2021_V1_DW.presentTicks = FSAC2021_V1_M->Timing.clockTick7;
      FSAC2021_V1_DW.elapsedTicks = FSAC2021_V1_DW.presentTicks -
        FSAC2021_V1_DW.previousTicks;
      FSAC2021_V1_DW.previousTicks = FSAC2021_V1_DW.presentTicks;
      if (FSAC2021_V1_DW.temporalCounter_i1_o + FSAC2021_V1_DW.elapsedTicks <=
          7U) {
        FSAC2021_V1_DW.temporalCounter_i1_o = (uint8_T)
          (FSAC2021_V1_DW.temporalCounter_i1_o + FSAC2021_V1_DW.elapsedTicks);
      } else {
        FSAC2021_V1_DW.temporalCounter_i1_o = 7U;
      }

      /* End of Disable for Chart: '<S147>/Chart' */
      FSAC2021_V1_DW.EnabledSubsystem_MODE = false;
    }
  }

  /* End of RelationalOperator: '<S146>/Compare' */
  /* End of Outputs for SubSystem: '<S136>/Enabled Subsystem' */

  /* DataTypeConversion: '<S137>/Data Type Conversion1' incorporates:
   *  Constant: '<S154>/Constant'
   *  RelationalOperator: '<S154>/Compare'
   */
  rtb_DataTypeConversion1_e = (uint8_T)(rtb_RateTransition34 <= 100);

  /* Chart: '<S137>/Chart2' */
  FSAC2021_V1_Chart1(FSAC2021_V1_M, rtb_DataTypeConversion1_e,
                     &FSAC2021_V1_B.sf_Chart2, &FSAC2021_V1_DW.sf_Chart2);

  /* DataTypeConversion: '<S137>/Data Type Conversion2' incorporates:
   *  Constant: '<S155>/Constant'
   *  RelationalOperator: '<S155>/Compare'
   */
  rtb_DataTypeConversion2 = (uint8_T)(rtb_RateTransition35 <= 100);

  /* Chart: '<S137>/Chart3' */
  FSAC2021_V1_Chart1(FSAC2021_V1_M, rtb_DataTypeConversion2,
                     &FSAC2021_V1_B.sf_Chart3, &FSAC2021_V1_DW.sf_Chart3);

  /* SignalConversion: '<S137>/TmpSignal ConversionAtChart2Outport1' */
  error_left = FSAC2021_V1_B.sf_Chart2.Output;

  /* SignalConversion: '<S137>/TmpSignal ConversionAtChart3Outport1' */
  error_right = FSAC2021_V1_B.sf_Chart3.Output;

  /* Logic: '<S137>/Logical Operator8' */
  sensor_erroe = ((error_left != 0) || (error_right != 0));

  /* DataTypeConversion: '<S137>/Data Type Conversion3' incorporates:
   *  Constant: '<S156>/Constant'
   *  RelationalOperator: '<S156>/Compare'
   */
  rtb_DataTypeConversion3 = (uint8_T)(FSAC2021_V1_B.RateTransition23 <= 8);

  /* Chart: '<S137>/Chart1' */
  FSAC2021_V1_Chart1(FSAC2021_V1_M, rtb_DataTypeConversion3,
                     &FSAC2021_V1_B.sf_Chart1, &FSAC2021_V1_DW.sf_Chart1);

  /* DataTypeConversion: '<S137>/Data Type Conversion4' incorporates:
   *  Constant: '<S157>/Constant'
   *  RelationalOperator: '<S157>/Compare'
   */
  rtb_DataTypeConversion4 = (uint8_T)(rtb_RateTransition37 <= 100);

  /* Chart: '<S137>/Chart4' */
  FSAC2021_V1_Chart1(FSAC2021_V1_M, rtb_DataTypeConversion4,
                     &FSAC2021_V1_B.sf_Chart4, &FSAC2021_V1_DW.sf_Chart4);

  /* DataTypeConversion: '<S137>/Data Type Conversion5' incorporates:
   *  Constant: '<S158>/Constant'
   *  RelationalOperator: '<S158>/Compare'
   */
  rtb_DataTypeConversion5 = (uint8_T)(rtb_RateTransition38 <= 100);

  /* Chart: '<S137>/Chart5' */
  FSAC2021_V1_Chart1(FSAC2021_V1_M, rtb_DataTypeConversion5,
                     &FSAC2021_V1_B.sf_Chart5, &FSAC2021_V1_DW.sf_Chart5);

  /* SignalConversion: '<S137>/TmpSignal ConversionAtChart1Outport1' */
  error_liquid = FSAC2021_V1_B.sf_Chart1.Output;

  /* SignalConversion: '<S137>/TmpSignal ConversionAtChart4Outport1' */
  error_gas1 = FSAC2021_V1_B.sf_Chart4.Output;

  /* SignalConversion: '<S137>/TmpSignal ConversionAtChart5Outport1' */
  error_gas2 = FSAC2021_V1_B.sf_Chart5.Output;

  /* Logic: '<S137>/Logical Operator1' */
  LogicalOperator1 = ((error_liquid != 0) || (error_gas1 != 0) || (error_gas2 !=
    0));

  /* Logic: '<S140>/Logical Operator1' incorporates:
   *  Constant: '<S166>/Constant'
   *  Constant: '<S167>/Constant'
   *  RelationalOperator: '<S166>/Compare'
   *  RelationalOperator: '<S167>/Compare'
   */
  rtb_LogicalOperator1 = ((FSAC2021_V1_B.RateTransition24 >= 3) &&
    (FSAC2021_V1_B.RateTransition24 <= 5));

  /* Outputs for Enabled SubSystem: '<S140>/Subsystem' incorporates:
   *  EnablePort: '<S169>/Enable'
   */
  /* Switch: '<S140>/Switch1' */
  if (rtb_LogicalOperator1) {
    if (!FSAC2021_V1_DW.Subsystem_MODE) {
      /* Enable for Chart: '<S169>/Chart4' */
      FSAC2021_V1_Chart4_Enable(FSAC2021_V1_M, &FSAC2021_V1_DW.sf_Chart4_p);
      FSAC2021_V1_DW.Subsystem_MODE = true;
    }

    /* Chart: '<S169>/Chart4' */
    FSAC2021_V1_Chart4(FSAC2021_V1_M, rtb_RateTransition30,
                       &FSAC2021_V1_DW.sf_Chart4_p);

    /* Logic: '<S140>/Logical Operator3' */
    Node_Lost = !(motor != 0);
  } else {
    if (FSAC2021_V1_DW.Subsystem_MODE) {
      /* Disable for Chart: '<S169>/Chart4' */
      FSAC2021_V1_Chart4_Disable(FSAC2021_V1_M, &FSAC2021_V1_DW.sf_Chart4_p);
      FSAC2021_V1_DW.Subsystem_MODE = false;
    }

    /* Logic: '<S140>/Logical Operator3' incorporates:
     *  Constant: '<S140>/Constant1'
     */
    Node_Lost = false;
  }

  /* End of Switch: '<S140>/Switch1' */
  /* End of Outputs for SubSystem: '<S140>/Subsystem' */

  /* MATLAB Function: '<S141>/MATLAB Function' */
  /* MATLAB Function 'DIAG/DIAG/EBS_Diag/MATLAB Function': '<S180>:1' */
  /* '<S180>:1:3' */
  rtb_RateTransition1 = 0.0;
  if ((FSAC2021_V1_B.RateTransition24 == 2) || (FSAC2021_V1_B.RateTransition24 ==
       3)) {
    /* '<S180>:1:4' */
    if (rtb_RateTransition37 < 1000) {
      /* '<S180>:1:5' */
      /* '<S180>:1:6' */
      rtb_RateTransition1 = 1.0;
    } else {
      if ((rtb_RateTransition37 > 1000) && (rtb_RateTransition38 > 1000)) {
        /* '<S180>:1:7' */
        /* '<S180>:1:8' */
        rtb_RateTransition1 = 1.0;
      }
    }
  }

  /* End of MATLAB Function: '<S141>/MATLAB Function' */

  /* SignalConversion: '<S144>/HiddenBuf_InsertedFor_Subsystem1_at_inport_1' incorporates:
   *  Constant: '<S189>/Constant'
   *  RelationalOperator: '<S189>/Compare'
   */
  rtb_HiddenBuf_InsertedFor_Subsy = (FSAC2021_V1_B.RateTransition24 == 3);

  /* SignalConversion: '<S144>/HiddenBuf_InsertedFor_Subsystem2_at_inport_1' incorporates:
   *  Constant: '<S190>/Constant'
   *  RelationalOperator: '<S190>/Compare'
   */
  rtb_HiddenBuf_InsertedFor_Sub_m = (FSAC2021_V1_B.RateTransition24 == 6);

  /* SignalConversion: '<S144>/HiddenBuf_InsertedFor_Subsystem_at_inport_1' incorporates:
   *  Constant: '<S188>/Constant'
   *  RelationalOperator: '<S188>/Compare'
   */
  rtb_HiddenBuf_InsertedFor_Sub_i = (FSAC2021_V1_B.RateTransition24 == 2);

  /* Outputs for Enabled SubSystem: '<S144>/Subsystem' */
  FSAC2021_V1_Subsystem(rtb_HiddenBuf_InsertedFor_Sub_i,
                        FSAC2021_V1_B.RateTransition1, &FSAC2021_V1_B.Merge_j);

  /* End of Outputs for SubSystem: '<S144>/Subsystem' */

  /* Outputs for Enabled SubSystem: '<S144>/Subsystem1' */
  FSAC2021_V1_Subsystem(rtb_HiddenBuf_InsertedFor_Subsy,
                        FSAC2021_V1_B.RateTransition1, &FSAC2021_V1_B.Merge_j);

  /* End of Outputs for SubSystem: '<S144>/Subsystem1' */

  /* Outputs for Enabled SubSystem: '<S144>/Subsystem2' */
  FSAC2021_V1_Subsystem(rtb_HiddenBuf_InsertedFor_Sub_m,
                        FSAC2021_V1_B.RateTransition1, &FSAC2021_V1_B.Merge_j);

  /* End of Outputs for SubSystem: '<S144>/Subsystem2' */

  /* Outputs for Enabled SubSystem: '<S142>/Subsystem' incorporates:
   *  EnablePort: '<S183>/Enable'
   */
  if (ASMS_VALUE > 0) {
    if (!FSAC2021_V1_DW.Subsystem_MODE_p) {
      /* Enable for Chart: '<S183>/Chart1' */
      FSAC2021_V_Chart1_n_Enable(FSAC2021_V1_M, &FSAC2021_V1_DW.sf_Chart1_b);
      FSAC2021_V1_DW.Subsystem_MODE_p = true;
    }

    /* DataTypeConversion: '<S183>/Data Type Conversion1' incorporates:
     *  Constant: '<S186>/Constant'
     *  RelationalOperator: '<S186>/Compare'
     */
    rtb_DataTypeConversion1 = (FSAC2021_V1_B.RateTransition26 == 0.0F);

    /* Chart: '<S183>/Chart1' */
    FSAC2021_V1_Chart1_b(FSAC2021_V1_M, rtb_DataTypeConversion1,
                         &FSAC2021_V1_B.sf_Chart1_b, &FSAC2021_V1_DW.sf_Chart1_b);

    /* DataTypeConversion: '<S183>/Data Type Conversion22' incorporates:
     *  Constant: '<S185>/Constant'
     *  RelationalOperator: '<S185>/Compare'
     */
    res_go = (uint8_T)(FSAC2021_V1_B.RateTransition26 == 8.0F);

    /* DataTypeConversion: '<S183>/Data Type Conversion23' */
    res_ebs_value = FSAC2021_V1_B.sf_Chart1_b.Output;
  } else {
    if (FSAC2021_V1_DW.Subsystem_MODE_p) {
      /* Disable for Chart: '<S183>/Chart1' */
      FSAC2021__Chart1_n_Disable(FSAC2021_V1_M, &FSAC2021_V1_DW.sf_Chart1_b);
      FSAC2021_V1_DW.Subsystem_MODE_p = false;
    }
  }

  /* End of Outputs for SubSystem: '<S142>/Subsystem' */

  /* Logic: '<S138>/Logical Operator' incorporates:
   *  DataTypeConversion: '<S138>/Data Type Conversion'
   *  DataTypeConversion: '<S138>/Data Type Conversion1'
   *  DataTypeConversion: '<S138>/Data Type Conversion10'
   *  DataTypeConversion: '<S138>/Data Type Conversion11'
   *  DataTypeConversion: '<S138>/Data Type Conversion12'
   *  DataTypeConversion: '<S138>/Data Type Conversion13'
   *  DataTypeConversion: '<S138>/Data Type Conversion14'
   *  DataTypeConversion: '<S138>/Data Type Conversion15'
   *  DataTypeConversion: '<S138>/Data Type Conversion16'
   *  DataTypeConversion: '<S138>/Data Type Conversion19'
   *  DataTypeConversion: '<S138>/Data Type Conversion2'
   *  DataTypeConversion: '<S138>/Data Type Conversion22'
   *  DataTypeConversion: '<S138>/Data Type Conversion23'
   *  DataTypeConversion: '<S138>/Data Type Conversion3'
   *  DataTypeConversion: '<S138>/Data Type Conversion4'
   *  DataTypeConversion: '<S138>/Data Type Conversion5'
   *  DataTypeConversion: '<S138>/Data Type Conversion6'
   *  DataTypeConversion: '<S138>/Data Type Conversion7'
   *  DataTypeConversion: '<S138>/Data Type Conversion8'
   *  DataTypeConversion: '<S138>/Data Type Conversion9'
   */
  rtb_LogicalOperator1 = ((FSAC2021_V1_B.RateTransition3 != 0) ||
    (FSAC2021_V1_B.RateTransition13 != 0) || (FSAC2021_V1_B.RateTransition12 !=
    0) || (FSAC2021_V1_B.RateTransition5 != 0) || (FSAC2021_V1_B.RateTransition4
    != 0) || (FSAC2021_V1_B.RateTransition14 != 0) ||
    (FSAC2021_V1_B.RateTransition15_b != 0) || (FSAC2021_V1_B.RateTransition10
    != 0) || (FSAC2021_V1_B.RateTransition21 != 0) ||
    (FSAC2021_V1_B.RateTransition17 != 0) || (FSAC2021_V1_B.RateTransition16 !=
    0) || (FSAC2021_V1_B.RateTransition2 != 0) ||
    (FSAC2021_V1_B.RateTransition18 != 0) || (FSAC2021_V1_B.RateTransition19 !=
    0) || (FSAC2021_V1_B.RateTransition20 != 0) ||
    (FSAC2021_V1_B.RateTransition9 != 0) || (FSAC2021_V1_B.RateTransition7 != 0)
    || (FSAC2021_V1_B.RateTransition6 != 0) || (FSAC2021_V1_B.RateTransition11
    != 0) || (FSAC2021_V1_B.RateTransition8 != 0));

  /* DataTypeConversion: '<S145>/Data Type Conversion' */
  DataTypeConversion_e = (uint8_T)FSAC2021_V1_B.RateTransition22;

  /* S-Function (fcncallgen): '<S226>/100ms' incorporates:
   *  SubSystem: '<S226>/daq100ms'
   */

  /* S-Function (ec55xx_ccpslb1): '<S237>/CCPDAQ' */
  ccpDaq(3);

  /* S-Function (fcncallgen): '<S8>/Function-Call Generator' incorporates:
   *  SubSystem: '<S8>/Subsystem'
   */

  /* S-Function (ec55xx_canreceiveslb): '<S249>/BMS_HCU_INFO' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF54RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf54looprx= 0;
    FSAC2021_V1_B.BMS_HCU_INFO_o3= -1738522381;
    FSAC2021_V1_B.BMS_HCU_INFO_o5= 8;
    bms_node= ec_can_receive(1,54, CAN1BUF54RX);
    FSAC2021_V1_B.BMS_HCU_INFO_o4[0]= CAN1BUF54RX[can1buf54looprx];
    can1buf54looprx++;
    FSAC2021_V1_B.BMS_HCU_INFO_o4[1]= CAN1BUF54RX[can1buf54looprx];
    can1buf54looprx++;
    FSAC2021_V1_B.BMS_HCU_INFO_o4[2]= CAN1BUF54RX[can1buf54looprx];
    can1buf54looprx++;
    FSAC2021_V1_B.BMS_HCU_INFO_o4[3]= CAN1BUF54RX[can1buf54looprx];
    can1buf54looprx++;
    FSAC2021_V1_B.BMS_HCU_INFO_o4[4]= CAN1BUF54RX[can1buf54looprx];
    can1buf54looprx++;
    FSAC2021_V1_B.BMS_HCU_INFO_o4[5]= CAN1BUF54RX[can1buf54looprx];
    can1buf54looprx++;
    FSAC2021_V1_B.BMS_HCU_INFO_o4[6]= CAN1BUF54RX[can1buf54looprx];
    can1buf54looprx++;
    FSAC2021_V1_B.BMS_HCU_INFO_o4[7]= CAN1BUF54RX[can1buf54looprx];
    can1buf54looprx++;
  }

  /* Call the system: <S249>/BMS_HCU_INFO  */

  /* Output and update for function-call system: '<S249>/BMS_HCU_INFO ' */
  {
    real32_T u0;

    /* Gain: '<S378>/BatVoltage_F' incorporates:
     *  Constant: '<S378>/BatVoltageinput1_C'
     *  Product: '<S378>/BatVoltageinput1_P'
     *  Sum: '<S378>/BatVoltageinput1_Ad'
     */
    u0 = (real32_T)((FSAC2021_V1_B.BMS_HCU_INFO_o4[0] << 8) +
                    FSAC2021_V1_B.BMS_HCU_INFO_o4[1]) * 0.1F;

    /* Saturate: '<S378>/BatVoltage_sat' */
    if (u0 > 900.0F) {
      /* DataTypeConversion: '<S376>/Data Type Conversion84' */
      FSAC2021_V1_B.DataTypeConversion84 = 900.0;
    } else {
      /* DataTypeConversion: '<S376>/Data Type Conversion84' */
      FSAC2021_V1_B.DataTypeConversion84 = u0;
    }

    /* End of Saturate: '<S378>/BatVoltage_sat' */
  }

  /* S-Function (fcncallgen): '<S8>/Function-Call Generator2' incorporates:
   *  SubSystem: '<S8>/Subsystem2'
   */

  /* S-Function (ec55xx_canreceiveslb): '<S251>/MOTEC_STATUS' */

  /* Receive CAN message */
  {
    uint8 CAN0BUF6RX[2]= { 0, 0 };

    uint8 can0buf6looprx= 0;
    FSAC2021_V1_B.MOTEC_STATUS_o3= 385;
    FSAC2021_V1_B.MOTEC_STATUS_o5= 2;
    Steer_Status= ec_can_receive(0,6, CAN0BUF6RX);
    FSAC2021_V1_B.MOTEC_STATUS_o4[0]= CAN0BUF6RX[can0buf6looprx];
    can0buf6looprx++;
    FSAC2021_V1_B.MOTEC_STATUS_o4[1]= CAN0BUF6RX[can0buf6looprx];
    can0buf6looprx++;
  }

  /* Nothing to do for system: <S251>/MOTEC_STATUS  */

  /* Update for RateTransition: '<S1>/Rate Transition10' */
  FSAC2021_V1_DW.RateTransition10_Buffer0 = FSAC2021_V1_B.DataTypeConversion84;

  /* Update for RateTransition: '<S2>/Rate Transition59' */
  FSAC2021_V1_DW.RateTransition59_Buffer0 = Steer_Status;

  /* Update for RateTransition: '<S3>/Rate Transition24' */
  FSAC2021_V1_DW.RateTransition24_Buffer0_n = res_ebs_value;

  /* Update for RateTransition: '<S2>/Rate Transition25' */
  FSAC2021_V1_DW.RateTransition25_Buffer0_c = res_go;

  /* S-Function (fcncallgen): '<S7>/Function-Call Generator2' incorporates:
   *  SubSystem: '<S3>/DIAG'
   */
  /* Update for RateTransition: '<S2>/Rate Transition31' incorporates:
   *  Logic: '<S143>/Logical Operator'
   */
  FSAC2021_V1_DW.RateTransition31_Buffer0 = ((rtb_RateTransition1_g != 0) ||
    (rtb_RateTransition2 != 0) || (rtb_RateTransition15_d != 0) ||
    (rtb_RateTransition16 != 0) || (rtb_RateTransition3 != 0) ||
    (rtb_RateTransition4 != 0) || (rtb_RateTransition5 != 0) ||
    (rtb_RateTransition6 != 0) || (rtb_RateTransition7 != 0) ||
    (rtb_RateTransition8 != 0) || (rtb_RateTransition9 != 0) ||
    (rtb_RateTransition10 != 0) || (rtb_RateTransition11 != 0) ||
    (rtb_RateTransition12_j != 0) || (rtb_RateTransition13 != 0) ||
    (rtb_RateTransition14 != 0));

  /* Update for RateTransition: '<S2>/Rate Transition32' incorporates:
   *  Logic: '<S139>/Logical Operator'
   */
  FSAC2021_V1_DW.RateTransition32_Buffer0 = ((rtb_RateTransition17 != 0.0) ||
    (rtb_RateTransition18 != 0.0) || (rtb_RateTransition19 != 0.0) ||
    (rtb_RateTransition20 != 0.0) || (rtb_RateTransition21 != 0.0) ||
    (rtb_RateTransition22 != 0.0) || (rtb_RateTransition23 != 0.0));

  /* Update for RateTransition: '<S2>/Rate Transition33' */
  FSAC2021_V1_DW.RateTransition33_Buffer0 = sensor_erroe;

  /* Update for RateTransition: '<S2>/Rate Transition50' */
  FSAC2021_V1_DW.RateTransition50_Buffer0 = FSAC2021_V1_B.Merge_j;

  /* Update for RateTransition: '<S3>/Rate Transition47' */
  FSAC2021_V1_DW.RateTransition47_Buffer0 = DataTypeConversion_e;

  /* S-Function (fcncallgen): '<S7>/Function-Call Generator2' incorporates:
   *  SubSystem: '<S3>/DIAG'
   */
  /* Update for RateTransition: '<S3>/Rate Transition46' incorporates:
   *  DataTypeConversion: '<S138>/Data Type Conversion17'
   */
  FSAC2021_V1_DW.RateTransition46_Buffer0 = rtb_LogicalOperator1;

  /* Update for RateTransition: '<S2>/Rate Transition42' */
  FSAC2021_V1_DW.RateTransition42_Buffer0 = Node_Lost;

  /* Update for RateTransition: '<S3>/Rate Transition25' */
  FSAC2021_V1_DW.RateTransition25_Buffer0 = FSAC2021_V1_B.Acc_Flag;

  /* Update for RateTransition: '<S3>/Rate Transition26' */
  FSAC2021_V1_DW.RateTransition26_Buffer0_d = LogicalOperator1;

  /* S-Function (fcncallgen): '<S7>/Function-Call Generator2' incorporates:
   *  SubSystem: '<S3>/DIAG'
   */
  /* Update for RateTransition: '<S3>/Rate Transition44' incorporates:
   *  DataTypeConversion: '<S141>/Data Type Conversion'
   */
  FSAC2021_V1_DW.RateTransition44_Buffer0 = (uint8_T)rtb_RateTransition1;

  /* Update absolute time */
  /* The "clockTick7" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick7" ensures timer will not overflow during the
   * application lifespan selected.
   */
  FSAC2021_V1_M->Timing.clockTick7++;
}

/* Model step function for TID8 */
void FSAC2021_V1_step8(void)           /* Sample time: [0.2s, 0.0s] */
{
  /* local block i/o variables */
  uint8_T rtb_RateTransition20_o;
  uint8_T rtb_RateTransition21_m;
  uint8_T rtb_RateTransition22_g;
  uint8_T rtb_UnitDelay;
  uint8_T rtb_RateTransition13;
  uint8_T rtb_RateTransition6;

  /* UnitDelay: '<S2>/Unit Delay' */
  rtb_UnitDelay = FSAC2021_V1_DW.UnitDelay_DSTATE_d;

  /* RateTransition: '<S2>/Rate Transition20' */
  rtb_RateTransition20_o = rtb_UnitDelay;

  /* UnitDelay: '<S2>/Unit Delay1' */
  rtb_UnitDelay = FSAC2021_V1_DW.UnitDelay1_DSTATE_c;

  /* RateTransition: '<S2>/Rate Transition21' */
  rtb_RateTransition21_m = rtb_UnitDelay;

  /* UnitDelay: '<S2>/Unit Delay2' */
  rtb_UnitDelay = FSAC2021_V1_DW.UnitDelay2_DSTATE_i;

  /* RateTransition: '<S2>/Rate Transition22' */
  rtb_RateTransition22_g = rtb_UnitDelay;

  /* S-Function (fcncallgen): '<S7>/Function-Call Generator3' incorporates:
   *  SubSystem: '<S2>/200ms_Duty'
   */

  /* Outputs for Atomic SubSystem: '<S64>/Light_Subsystem' */
  FSAC2021_V_Light_Subsystem(rtb_RateTransition20_o,
    &FSAC2021_V1_DW.Light_Subsystem);

  /* End of Outputs for SubSystem: '<S64>/Light_Subsystem' */

  /* Outputs for Atomic SubSystem: '<S64>/Light_Subsystem1' */
  FSAC2021__Light_Subsystem1(rtb_RateTransition21_m,
    &FSAC2021_V1_B.Light_Subsystem1, &FSAC2021_V1_DW.Light_Subsystem1);

  /* End of Outputs for SubSystem: '<S64>/Light_Subsystem1' */

  /* Outputs for Atomic SubSystem: '<S64>/Light_Subsystem2' */
  FSAC2021__Light_Subsystem2(FSAC2021_V1_M, rtb_RateTransition22_g,
    &FSAC2021_V1_B.Light_Subsystem2, &FSAC2021_V1_DW.Light_Subsystem2);

  /* End of Outputs for SubSystem: '<S64>/Light_Subsystem2' */

  /* RateTransition: '<S2>/Rate Transition12' */
  rtb_UnitDelay = FSAC2021_V1_B.Yellow_Light;

  /* RateTransition: '<S2>/Rate Transition13' */
  rtb_RateTransition13 = FSAC2021_V1_B.Buzzer;

  /* RateTransition: '<S2>/Rate Transition6' */
  rtb_RateTransition6 = FSAC2021_V1_B.Blue_Light;

  /* Update for RateTransition: '<S2>/Rate Transition17' */
  FSAC2021_V1_DW.RateTransition17_Buffer0 = blue;

  /* Update for RateTransition: '<S2>/Rate Transition18' */
  FSAC2021_V1_DW.RateTransition18_Buffer0_d =
    FSAC2021_V1_B.Light_Subsystem1.DataTypeConversion;

  /* Update for RateTransition: '<S2>/Rate Transition19' */
  FSAC2021_V1_DW.RateTransition19_Buffer0_e =
    FSAC2021_V1_B.Light_Subsystem2.DataTypeConversion;

  /* Update for UnitDelay: '<S2>/Unit Delay' */
  FSAC2021_V1_DW.UnitDelay_DSTATE_d = rtb_RateTransition6;

  /* Update for UnitDelay: '<S2>/Unit Delay1' */
  FSAC2021_V1_DW.UnitDelay1_DSTATE_c = rtb_UnitDelay;

  /* Update for UnitDelay: '<S2>/Unit Delay2' */
  FSAC2021_V1_DW.UnitDelay2_DSTATE_i = rtb_RateTransition13;

  /* Update for RateTransition: '<S2>/Rate Transition15' */
  FSAC2021_V1_DW.RateTransition15_Buffer0_e =
    FSAC2021_V1_B.Light_Subsystem2.Buzzer_Overflag;

  /* Update absolute time */
  /* The "clockTick8" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.2, which is the step size
   * of the task. Size of "clockTick8" ensures timer will not overflow during the
   * application lifespan selected.
   */
  FSAC2021_V1_M->Timing.clockTick8++;
}

/* Model step function for TID9 */
void FSAC2021_V1_step9(void)           /* Sample time: [0.5s, 0.0s] */
{
  /* S-Function (fcncallgen): '<S227>/500ms' incorporates:
   *  SubSystem: '<S227>/FlashOperation'
   */

  /* S-Function (ec55xx_flashoslb): '<S241>/FlashOperatin' */
#if defined EC_FLASH_ENABLE

  /* Operate the flash module on the MPC5554 */
  ec_flash_operation();

#endif

  /* S-Function (fcncallgen): '<S8>/Function-Call Generator1' incorporates:
   *  SubSystem: '<S8>/Subsystem1'
   */

  /* S-Function (ec55xx_canreceiveslb): '<S250>/HEARTBEAT' */

  /* Receive CAN message */
  {
    uint8 CAN0BUF3RX[1]= { 0 };

    uint8 can0buf3looprx= 0;
    FSAC2021_V1_B.HEARTBEAT_o3= 1793;
    FSAC2021_V1_B.HEARTBEAT_o5= 1;
    motec_node= ec_can_receive(0,3, CAN0BUF3RX);
    FSAC2021_V1_B.HEARTBEAT_o4= CAN0BUF3RX[can0buf3looprx];
    can0buf3looprx++;
  }

  /* Nothing to do for system: <S250>/HEARTBEAT  */
}

/* Model step wrapper function for compatibility with a static main program */
void FSAC2021_V1_step(int_T tid)
{
  switch (tid) {
   case 0 :
    FSAC2021_V1_step0();
    break;

   case 1 :
    FSAC2021_V1_step1();
    break;

   case 2 :
    FSAC2021_V1_step2();
    break;

   case 3 :
    FSAC2021_V1_step3();
    break;

   case 4 :
    FSAC2021_V1_step4();
    break;

   case 5 :
    FSAC2021_V1_step5();
    break;

   case 6 :
    FSAC2021_V1_step6();
    break;

   case 7 :
    FSAC2021_V1_step7();
    break;

   case 8 :
    FSAC2021_V1_step8();
    break;

   case 9 :
    FSAC2021_V1_step9();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void FSAC2021_V1_initialize(void)
{
  /* Start for S-Function (fcncallgen): '<S7>/Function-Call Generator5' incorporates:
   *  Start for SubSystem: '<S1>/(BRK、STR、DRIVER)'
   */
  /* Start for S-Function (ec55xx_cantransmitslb): '<S10>/CANTransmit7' */
  ec_buffer_init(0,60,0,1161U);

  /* Start for S-Function (fcncallgen): '<S7>/Function-Call Generator4' incorporates:
   *  Start for SubSystem: '<S8>/PCANA(RES、AMI、MOTEC、BRAKE、STEER_SENSOR、IPC)'
   */
  /* Start for S-Function (ec55xx_canreceiveslb): '<S247>/Steer_Sensor' */
  ec_buffer_init(0,38,0,485);

  /* Start for S-Function (ec55xx_canreceiveslb): '<S247>/BCU_MTR_STATUS' */
  ec_buffer_init(0,21,0,257);

  /* Start for S-Function (ec55xx_canreceiveslb): '<S247>/MOTEC_MOTION1' */
  ec_buffer_init(0,41,0,256);

  /* Start for S-Function (ec55xx_canreceiveslb): '<S247>/MOTEC_MOTION2' */
  ec_buffer_init(0,35,0,279);

  /* Start for S-Function (fcncallgen): '<S7>/Function-Call Generator1' incorporates:
   *  Start for SubSystem: '<S9>/Read_VCU_Freq(WheelSpeed)'
   */
  /* Start for S-Function (ec55xx_ffrslb): '<S404>/Read_RL_WhlSpd' */
  SIU.PCR[127].R = 0x0500;
  fs_etpu_ppa_p_init(13,FS_ETPU_PRIORITY_MIDDLE,FS_ETPU_PPA_P_INIT,
                     FS_ETPU_PPA_RISING_EDGE);

  /* Start for S-Function (ec55xx_ffrslb): '<S404>/Read_RR_WhlSpd' */
  SIU.PCR[128].R = 0x0500;
  fs_etpu_ppa_p_init(14,FS_ETPU_PRIORITY_MIDDLE,FS_ETPU_PPA_P_INIT,
                     FS_ETPU_PPA_RISING_EDGE);

  /* Start for S-Function (fcncallgen): '<S7>/Function-Call Generator1' incorporates:
   *  Start for SubSystem: '<S2>/BCU_Controller'
   */
  /* Start for Enabled SubSystem: '<S121>/Enabled Subsystem' */
  /* Start for SignalConversion: '<S123>/OutportBufferForEngaged_Angle' */
  FSAC2021_V1_B.OutportBufferForEngaged_Angle = 8;

  /* End of Start for SubSystem: '<S121>/Enabled Subsystem' */

  /* Start for S-Function (fcncallgen): '<S7>/Function-Call Generator1' incorporates:
   *  Start for SubSystem: '<S8>/PCANB(BMS、DRIVE_MOTOR)'
   */
  /* Start for S-Function (ec55xx_canreceiveslb): '<S248>/BMS_HCU_MAXT' */
  ec_buffer_init(1,18,1,-1738391309);

  /* Start for S-Function (ec55xx_canreceiveslb): '<S248>/BMS_HCU_MAXV' */
  ec_buffer_init(1,16,1,-1738456845);

  /* Start for S-Function (ec55xx_canreceiveslb): '<S248>/BMS_RELAY' */
  ec_buffer_init(1,51,1,-1738325773);

  /* Start for S-Function (ec55xx_canreceiveslb): '<S248>/BMS_HCU_POWER' */
  ec_buffer_init(1,52,1,-1738260237);

  /* Start for S-Function (ec55xx_canreceiveslb): '<S248>/Motor_Current_Speed ' */
  ec_buffer_init(1,21,1,-2147413853);

  /* Start for S-Function (ec55xx_canreceiveslb): '<S248>/BMS_ALARM' */
  ec_buffer_init(1,50,1,-1738194701);

  /* Start for S-Function (ec55xx_canreceiveslb): '<S248>/Str_Error' */
  ec_buffer_init(0,4,0,129);

  /* Start for S-Function (ec55xx_canreceiveslb): '<S248>/AMI' */
  ec_buffer_init(0,16,0,1169);

  /* Start for S-Function (ec55xx_canreceiveslb): '<S248>/AMI1' */
  ec_buffer_init(0,26,0,1168);

  /* Start for S-Function (fcncallgen): '<S7>/Function-Call Generator1' incorporates:
   *  Start for SubSystem: '<S1>/Subsystem2'
   */
  /* Start for S-Function (ec55xx_cantransmitslb): '<S12>/CANTransmit3' */
  ec_buffer_init(0,58,0,358U);

  /* Start for S-Function (ec55xx_cantransmitslb): '<S12>/CANTransmit4' */
  ec_buffer_init(1,15,1,2197885092U);

  /* Start for S-Function (ec55xx_cantransmitslb): '<S11>/CANTransmit' */
  ec_buffer_init(0,63,0,513U);

  /* Start for S-Function (ec55xx_cantransmitslb): '<S11>/CANTransmit1' */
  ec_buffer_init(0,62,0,0U);

  /* Start for S-Function (ec55xx_cantransmitslb): '<S11>/CANTransmit2' */
  ec_buffer_init(0,61,0,1537U);

  /* Start for Atomic SubSystem: '<S11>/Brk_Mtr_Enbale' */

  /* Start for S-Function (ec55xx_cantransmitslb): '<S24>/CANTransmit' */
  ec_buffer_init(0,8,0,353U);

  /* End of Start for SubSystem: '<S11>/Brk_Mtr_Enbale' */

  /* Start for S-Function (ec55xx_cantransmitslb): '<S13>/CANTransmit6' */
  ec_buffer_init(0,59,0,382U);

  /* Start for S-Function (ec55xx_cantransmitslb): '<S13>/CANTransmit1' */
  ec_buffer_init(1,13,1,2181107875U);

  /* Start for S-Function (fcncallgen): '<S7>/Function-Call Generator3' incorporates:
   *  Start for SubSystem: '<S2>/200ms_Duty'
   */

  /* Start for Atomic SubSystem: '<S64>/Light_Subsystem2' */
  FSA_Light_Subsystem2_Start(&FSAC2021_V1_DW.Light_Subsystem2);

  /* End of Start for SubSystem: '<S64>/Light_Subsystem2' */

  /* Start for S-Function (ec55xx_caninterruptslb1): '<S225>/ReceiveandTransmitInterrupt' incorporates:
   *  Start for SubSystem: '<S225>/Function-Call Subsystem'
   */
  /* Start for function-call system: '<S225>/Function-Call Subsystem' */

  /* Start for S-Function (ec55xx_canreceiveslb): '<S230>/CANReceive1' incorporates:
   *  Start for SubSystem: '<S230>/Function-Call Subsystem'
   */
  /* Start for function-call system: '<S230>/Function-Call Subsystem' */

  /* Start for IfAction SubSystem: '<S231>/If Action Subsystem1' */

  /* Start for S-Function (ec55xx_cantransmitslb): '<S236>/CANTransmit' */
  ec_buffer_init(2,9,0,593U);

  /* End of Start for SubSystem: '<S231>/If Action Subsystem1' */

  /* Start for S-Function (ec55xx_canreceiveslb): '<S230>/CANReceive1' */
  ec_buffer_init(2,1,0,278);

  /* Start for S-Function (ec55xx_caninterruptslb1): '<S225>/ReceiveandTransmitInterrupt' */
  ec_bufint_init(2,1);
  INTC_InstallINTCInterruptHandler( ISR_FlexCAN_2_MB1, SW_INT_VEC_CAN2_IFRL_BUF1,
    CAN2_INTC_PRIORITY );

  /* Start for S-Function (fcncallgen): '<S229>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S229>/CCPBackground'
   */
  /* Start for S-Function (ec55xx_ccpslb): '<S243>/CCPBackground' */
  ccpInit();

  /* Start for S-Function (ec55xx_caninterruptslb1): '<S229>/ReceiveandTransmitInterrupt' incorporates:
   *  Start for SubSystem: '<S229>/CCPReceive'
   */
  /* Start for function-call system: '<S229>/CCPReceive' */

  /* Start for S-Function (ec55xx_canreceiveslb): '<S244>/CANReceive' */
  ec_buffer_init(2,0,0,CCP_CRO_ID);

  /* Start for S-Function (ec55xx_caninterruptslb1): '<S229>/ReceiveandTransmitInterrupt' */
  ec_bufint_init(2,0);
  INTC_InstallINTCInterruptHandler( ISR_FlexCAN_2_MB0, SW_INT_VEC_CAN2_IFRL_BUF0,
    CAN2_INTC_PRIORITY );

  /* Start for S-Function (ec55xx_caninterruptslb1): '<S229>/ReceiveandTransmitInterrupt1' */
  ec_bufint_init(2,8);
  INTC_InstallINTCInterruptHandler( ISR_FlexCAN_2_MB8, SW_INT_VEC_CAN2_IFRL_BUF8,
    CAN2_INTC_PRIORITY );

  /* Start for S-Function (ec55xx_adcbsb): '<S6>/ADC' */
  ec_adc_init();

  /* Start for S-Function (ec55xx_rtibsb): '<S6>/RTI' */
  ec_rti_init(500);

  /* Start for S-Function (fcncallgen): '<S8>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S8>/Subsystem'
   */
  /* Start for S-Function (ec55xx_canreceiveslb): '<S249>/BMS_HCU_INFO' */
  ec_buffer_init(1,54,1,-1738522381);

  /* Start for S-Function (fcncallgen): '<S8>/Function-Call Generator1' incorporates:
   *  Start for SubSystem: '<S8>/Subsystem1'
   */
  /* Start for S-Function (ec55xx_canreceiveslb): '<S250>/HEARTBEAT' */
  ec_buffer_init(0,3,0,1793);

  /* Start for S-Function (fcncallgen): '<S8>/Function-Call Generator2' incorporates:
   *  Start for SubSystem: '<S8>/Subsystem2'
   */
  /* Start for S-Function (ec55xx_canreceiveslb): '<S251>/MOTEC_STATUS' */
  ec_buffer_init(0,6,0,385);

  /* InitializeConditions for S-Function (fcncallgen): '<S7>/Function-Call Generator' incorporates:
   *  InitializeConditions for SubSystem: '<S5>/KL_Sig_Process'
   */

  /* InitializeConditions for Atomic SubSystem: '<S210>/LPF' */
  FSAC2021_V1_LPF_Init(&FSAC2021_V1_DW.LPF);

  /* End of InitializeConditions for SubSystem: '<S210>/LPF' */

  /* InitializeConditions for Atomic SubSystem: '<S210>/LPF1' */
  FSAC2021_V1_LPF_Init(&FSAC2021_V1_DW.LPF1);

  /* End of InitializeConditions for SubSystem: '<S210>/LPF1' */

  /* InitializeConditions for Atomic SubSystem: '<S210>/LPF2' */
  FSAC2021_V1_LPF_Init(&FSAC2021_V1_DW.LPF2);

  /* End of InitializeConditions for SubSystem: '<S210>/LPF2' */

  /* InitializeConditions for Atomic SubSystem: '<S210>/LPF3' */
  FSAC2021_V1_LPF_Init(&FSAC2021_V1_DW.LPF3);

  /* End of InitializeConditions for SubSystem: '<S210>/LPF3' */

  /* Enable for S-Function (fcncallgen): '<S7>/Function-Call Generator1' incorporates:
   *  Enable for SubSystem: '<S2>/SteerCtr'
   */
  /* Enable for Chart: '<S67>/Chart' */
  FSAC2021_V1_DW.presentTicks_nm = FSAC2021_V1_M->Timing.clockTick6;
  FSAC2021_V1_DW.previousTicks_c = FSAC2021_V1_DW.presentTicks_nm;

  /* Enable for S-Function (fcncallgen): '<S7>/Function-Call Generator1' incorporates:
   *  Enable for SubSystem: '<S2>/BCU_Controller'
   */
  /* Enable for Chart: '<S66>/BCU_Strategy' */
  FSAC2021_V1_DW.presentTicks_c = FSAC2021_V1_M->Timing.clockTick6;
  FSAC2021_V1_DW.previousTicks_ip = FSAC2021_V1_DW.presentTicks_c;

  /* Enable for S-Function (fcncallgen): '<S7>/Function-Call Generator1' incorporates:
   *  Enable for SubSystem: '<S2>/50ms_Duty'
   */
  /* Enable for Chart: '<S65>/AS_Machine' incorporates:
   *  Enable for SubSystem: '<S65>/Visuality Check'
   */
  /* Enable for Chart: '<S95>/Chart' */
  FSAC2021_V1_DW.presentTicks_n = FSAC2021_V1_M->Timing.clockTick6;
  FSAC2021_V1_DW.previousTicks_l = FSAC2021_V1_DW.presentTicks_n;
  FSAC2021_V1_DW.presentTicks_p = FSAC2021_V1_M->Timing.clockTick6;
  FSAC2021_V1_DW.previousTicks_i = FSAC2021_V1_DW.presentTicks_p;

  /* Enable for S-Function (fcncallgen): '<S7>/Function-Call Generator2' incorporates:
   *  Enable for SubSystem: '<S3>/DIAG'
   */
  /* Enable for Chart: '<S137>/Chart2' */
  FSAC2021_V1_Chart1_Enable(FSAC2021_V1_M, &FSAC2021_V1_DW.sf_Chart2);

  /* Enable for Chart: '<S137>/Chart3' */
  FSAC2021_V1_Chart1_Enable(FSAC2021_V1_M, &FSAC2021_V1_DW.sf_Chart3);

  /* Enable for Chart: '<S137>/Chart1' */
  FSAC2021_V1_Chart1_Enable(FSAC2021_V1_M, &FSAC2021_V1_DW.sf_Chart1);

  /* Enable for Chart: '<S137>/Chart4' */
  FSAC2021_V1_Chart1_Enable(FSAC2021_V1_M, &FSAC2021_V1_DW.sf_Chart4);

  /* Enable for Chart: '<S137>/Chart5' */
  FSAC2021_V1_Chart1_Enable(FSAC2021_V1_M, &FSAC2021_V1_DW.sf_Chart5);
}

/* File trailer for ECUCoder generated file FSAC2021_V1.c.
 *
 * [EOF]
 */
