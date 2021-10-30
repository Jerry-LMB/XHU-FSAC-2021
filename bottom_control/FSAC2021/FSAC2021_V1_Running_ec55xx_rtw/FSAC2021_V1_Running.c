/*
 * Code generated for Simulink model FSAC2021_V1_Running.
 *
 * FILE    : FSAC2021_V1_Running.c
 *
 * VERSION : 1.179
 *
 * DATE    : Sun Sep 26 20:42:00 2021
 *
 * Copyright 2011-2012 ECUCoder. All Rights Reserved.
 */

#include "FSAC2021_V1_Running.h"
#include "FSAC2021_V1_Running_private.h"

/* #include "myinclude.h" */

/* Named constants for Chart: '<S129>/Chart2' */
#define FSAC2021_V1_Running_IN_Off     ((uint8_T)1U)
#define FSAC2021_V1_Running_IN_On      ((uint8_T)2U)
#define FSAC2021_V1_Running_IN_Wait    ((uint8_T)3U)

/* Named constants for Chart: '<S149>/Chart' */
#define FSAC2021_V1_Running_IN_Normal  ((uint8_T)1U)
#define FSAC2021_V1_Running_IN_ON      ((uint8_T)2U)
#define FSAC2021_V1_Running_IN_Off_i   ((uint8_T)3U)
#define FSAC2021_V1_Running_IN_On_b    ((uint8_T)4U)

/* Named constants for Chart: '<S149>/Chart1' */
#define FSAC2021_V1_Running_IN_Normal_b ((uint8_T)1U)
#define FSAC2021_V1_Running_IN_ON_b    ((uint8_T)2U)
#define FSAC2021_V1_Running_IN_Off_k   ((uint8_T)3U)
#define FSAC2021_V1_Running_IN_On_a    ((uint8_T)4U)

/* Named constants for Chart: '<S153>/Chart4' */
#define FSAC2021_V1_Running_IN_Normal_h ((uint8_T)1U)
#define FSAC2021_V1_Running_IN_ON_j    ((uint8_T)2U)
#define FSAC2021_V1_Running_IN_Off_g   ((uint8_T)3U)
#define FSAC2021_V1_Running_IN_On_az   ((uint8_T)4U)

/* Named constants for Chart: '<S171>/Chart1' */
#define FSAC2021_V1_Running_IN_Normal_l ((uint8_T)1U)
#define FSAC2021_V1_Running_IN_ON_n    ((uint8_T)2U)
#define FSAC2021_V1_Running_IN_Off_c   ((uint8_T)3U)
#define FSAC2021_V1_Running_IN_On_p    ((uint8_T)4U)

/* Named constants for Chart: '<S78>/Chart' */
#define FSAC2021_V1_R_IN_Start_Horn_OFF ((uint8_T)1U)
#define FSAC2021_V1_Ru_IN_Start_Horn_ON ((uint8_T)2U)
#define FSAC2021_V_IN_NO_ACTIVE_CHILD_n ((uint8_T)0U)

/* Named constants for Chart: '<S77>/Chart' */
#define FSAC2021_V1_Run_IN_EBS_Horn_OFF ((uint8_T)1U)
#define FSAC2021_V1_Run_IN_EBS_Horn_ON1 ((uint8_T)2U)
#define FSAC2021_V1_Runn_IN_EBS_Horn_ON ((uint8_T)1U)
#define FSAC2021_V1_Running_IN_Horn    ((uint8_T)2U)

/* Named constants for Chart: '<S66>/Chart' */
#define FSAC2021_V1_R_IN_Origin_Pos_Set ((uint8_T)2U)
#define FSAC2021_V1_Run_IN_Motor_Enable ((uint8_T)2U)
#define FSAC2021_V1_Run_IN_Motor_Stanby ((uint8_T)4U)
#define FSAC2021_V1_Runn_IN_Aciton_Move ((uint8_T)1U)
#define FSAC2021_V1_Runni_IN_Motor_Move ((uint8_T)3U)
#define FSAC2021_V1_Running_IN_Encoder1 ((uint8_T)1U)
#define FSAC2021_V1_Running_IN_First   ((uint8_T)1U)
#define FSAC2021_V1_Running_IN_Goto    ((uint8_T)1U)
#define FSAC2021_V1_Running_IN_Init    ((uint8_T)1U)
#define FSAC2021_V1_Running_IN_Move    ((uint8_T)2U)
#define FSAC2021_V1_Running_IN_Second  ((uint8_T)2U)
#define FSAC2021_V1_Running_IN_Wait_l  ((uint8_T)5U)
#define FSAC2021_V_IN_Move_Position_Set ((uint8_T)2U)
#define FSAC2021_V_IN_NO_ACTIVE_CHILD_b ((uint8_T)0U)
#define FSAC2021__IN_Origin_Aciton_Move ((uint8_T)1U)
#define FSAC2021__IN_Pre_Operation_Mode ((uint8_T)3U)

/* Named constants for Chart: '<S64>/BCU_Strategy' */
#define FSAC2021_V1_Runni_IN_BackOrigin ((uint8_T)1U)
#define FSAC2021_V1_Running_IN_Idle    ((uint8_T)1U)
#define FSAC2021_V1_Running_IN_Init_g  ((uint8_T)2U)
#define FSAC2021_V1_Running_IN_Move_k  ((uint8_T)3U)
#define FSAC2021_V1_Running_IN_RunMode ((uint8_T)2U)
#define FSAC2021_V1_Running_IN_Tozeros ((uint8_T)4U)

/* Named constants for Chart: '<S94>/Chart' */
#define FSAC2021_V1_Ru_IN_Visuality_Off ((uint8_T)1U)
#define FSAC2021_V1_Run_IN_Visuality_On ((uint8_T)2U)

/* Named constants for Chart: '<S63>/AS_Machine' */
#define FSAC2021_V1_R_IN_Manual_Driving ((uint8_T)6U)
#define FSAC2021_V1_Run_IN_AS_Emergency ((uint8_T)2U)
#define FSAC2021_V1_Runn_IN_AS_Finished ((uint8_T)3U)
#define FSAC2021_V1_Runni_IN_AS_Driving ((uint8_T)1U)
#define FSAC2021_V1_Running_IN_AS_Off  ((uint8_T)4U)
#define FSAC2021_V1_Running_IN_AS_Ready ((uint8_T)5U)

/* Named constants for Chart: '<S93>/Chart' */
#define FSAC2021_V1_Runni_IN_Driverless ((uint8_T)1U)
#define FSAC2021_V1_Running_IN_Manul   ((uint8_T)2U)
#define FSAC2021_V1_Running_IN_Task    ((uint8_T)3U)
#define FSAC2021_V1_Running_IN_init    ((uint8_T)4U)

/* Named constants for Chart: '<S110>/Chart' */
#define FSAC2021_V1_Running_IN_IN      ((uint8_T)1U)
#define FSAC2021_V1_Running_IN_Move_c  ((uint8_T)1U)
#define FSAC2021_V1_Running_IN_end     ((uint8_T)2U)
#define FSAC2021_V1_Running_IN_init_g  ((uint8_T)3U)

uint16 TLE6232DIA[12]= { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 };

/* Exported data definition */

/* Definition for custom storage class: Default */
real32_T ACC;
uint8_T AMI;
uint8_T AMI_HEART;
uint8_T AMI_NODE;
uint8_T AMI_State;
boolean_T ASMS_Read;
uint8_T ASMS_VALUE;
uint8_T ASSI_state;
uint8_T BMS;
boolean_T BMS_LIGHT;
uint8_T BRAKE;
uint8_T BUC_Enable_Flag;
real32_T Back_Angle;
uint8_T Brk_Enable_Flag;
boolean_T Buzzer_pin;
boolean_T Compare_Voltage;
boolean_T EBS;
boolean_T EBS_Rel_Switch;
uint8_T EBS_Status;
uint8_T ENCODER_SEND;
boolean_T HVMS_Read;
boolean_T HV_LIGHT;
boolean_T IMD;
boolean_T IMD_BENDER;
boolean_T LVMS_Read;
uint8_T MNT_SEND;
real_T MODE;
uint8_T MOTEC;
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
uint16_T Read_Brk_Liquid_Prs;
uint16_T Read_EBS_Gas_Prs1;
uint16_T Read_EBS_Gas_Prs2;
uint16_T Read_Lft_Acc_Disp;
uint16_T Read_Right_Acc_Disp1;
real32_T Read_compare_OutVolt;
boolean_T START;
uint8_T STRSNR;
boolean_T Stafe_Relay_pin;
real_T Steer_Origin_Flag;
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
uint8_T brake_node;
boolean_T enable;
real_T enflag;
real_T flag;
real_T ipc_strr;
boolean_T light_blue;
uint8_T motec_node;
uint8_T motor;
uint8_T motor_node;
uint8_T res_ebs1;
boolean_T res_ebs_value;
uint8_T res_go;
boolean_T sensor_erroe;
uint8_T strsr_node;

/* Block signals (auto storage) */
B_FSAC2021_V1_Running_T FSAC2021_V1_Running_B;

/* Block states (auto storage) */
DW_FSAC2021_V1_Running_T FSAC2021_V1_Running_DW;

/* Real-time model */
RT_MODEL_FSAC2021_V1_Running_T FSAC2021_V1_Running_M_;
RT_MODEL_FSAC2021_V1_Running_T *const FSAC2021_V1_Running_M =
  &FSAC2021_V1_Running_M_;
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
  /* Call the system: <S378>/Function-Call Subsystem */
  {
    /* Output and update for function-call system: '<S378>/Function-Call Subsystem' */

    /* S-Function (ec55xx_canreceiveslb): '<S383>/CANReceive1' */

    /* Receive CAN message */
    {
      uint8 CAN2BUF1RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

      uint8 can2buf1looprx= 0;
      FSAC2021_V1_Running_B.CANReceive1_o3= 278;
      FSAC2021_V1_Running_B.CANReceive1_o5= 8;
      FSAC2021_V1_Running_B.CANReceive1_o2= ec_can_receive(2,1, CAN2BUF1RX);
      FSAC2021_V1_Running_B.CANReceive1_o4[0]= CAN2BUF1RX[can2buf1looprx];
      can2buf1looprx++;
      FSAC2021_V1_Running_B.CANReceive1_o4[1]= CAN2BUF1RX[can2buf1looprx];
      can2buf1looprx++;
      FSAC2021_V1_Running_B.CANReceive1_o4[2]= CAN2BUF1RX[can2buf1looprx];
      can2buf1looprx++;
      FSAC2021_V1_Running_B.CANReceive1_o4[3]= CAN2BUF1RX[can2buf1looprx];
      can2buf1looprx++;
      FSAC2021_V1_Running_B.CANReceive1_o4[4]= CAN2BUF1RX[can2buf1looprx];
      can2buf1looprx++;
      FSAC2021_V1_Running_B.CANReceive1_o4[5]= CAN2BUF1RX[can2buf1looprx];
      can2buf1looprx++;
      FSAC2021_V1_Running_B.CANReceive1_o4[6]= CAN2BUF1RX[can2buf1looprx];
      can2buf1looprx++;
      FSAC2021_V1_Running_B.CANReceive1_o4[7]= CAN2BUF1RX[can2buf1looprx];
      can2buf1looprx++;
    }

    /* Call the system: <S383>/Function-Call Subsystem */

    /* Output and update for function-call system: '<S383>/Function-Call Subsystem' */

    /* If: '<S384>/If' incorporates:
     *  Constant: '<S385>/Constant'
     *  Constant: '<S386>/Constant'
     *  Constant: '<S387>/Constant'
     *  Constant: '<S389>/Constant'
     *  RelationalOperator: '<S385>/Compare'
     *  RelationalOperator: '<S386>/Compare'
     *  RelationalOperator: '<S387>/Compare'
     *  Sum: '<S384>/Add'
     */
    if (((int32_T)((uint32_T)(FSAC2021_V1_Running_B.CANReceive1_o4[0] == 83) +
                   (FSAC2021_V1_Running_B.CANReceive1_o4[5] == 84)) == 2) > 0) {
      /* Outputs for IfAction SubSystem: '<S384>/If Action Subsystem' incorporates:
       *  ActionPort: '<S388>/Action Port'
       */

      /* S-Function (ec55xx_bootloaderslb): '<S388>/BootLoader' */
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

      /* S-Function (ec55xx_cpuresetslb): '<S388>/CPUReset' */

      /* Perform a microcontroller reset */
      ec_cpu_reset();

      /* End of Outputs for SubSystem: '<S384>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S384>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S389>/Action Port'
       */

      /* S-Function (ec55xx_cantransmitslb): '<S389>/CANTransmit' */

      /*Transmit CAN message*/
      {
        uint8 CAN2BUF9TX[1];
        uint8 can2buf9looptx= 0;
        CAN2BUF9TX[can2buf9looptx]= ((uint8_T)1U);
        can2buf9looptx++;
        FSAC2021_V1_Running_B.CANTransmit= ec_can_transmit(2, 9, 0, 593U, 1,
          CAN2BUF9TX);
      }

      /* End of Outputs for SubSystem: '<S384>/If Action Subsystem1' */
    }

    /* End of If: '<S384>/If' */
  }

  FLEXCAN(2).IFRL.B.BUF01I = 1;        /* Clear CAN interrupt flag by writing it to 1 */
}

void ISR_FlexCAN_2_MB0(void)
{
  /* Call the system: <S382>/CCPReceive */
  {
    /* Output and update for function-call system: '<S382>/CCPReceive' */

    /* S-Function (ec55xx_canreceiveslb): '<S397>/CANReceive' */

    /* Receive CAN message */
    {
      uint8 CAN2BUF0RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

      uint8 can2buf0looprx= 0;
      FSAC2021_V1_Running_B.CANReceive_o3= 256;
      FSAC2021_V1_Running_B.CANReceive_o5= 8;
      FSAC2021_V1_Running_B.CANReceive_o2= ec_can_receive(2,0, CAN2BUF0RX);
      FSAC2021_V1_Running_B.CANReceive_o4[0]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      FSAC2021_V1_Running_B.CANReceive_o4[1]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      FSAC2021_V1_Running_B.CANReceive_o4[2]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      FSAC2021_V1_Running_B.CANReceive_o4[3]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      FSAC2021_V1_Running_B.CANReceive_o4[4]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      FSAC2021_V1_Running_B.CANReceive_o4[5]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      FSAC2021_V1_Running_B.CANReceive_o4[6]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      FSAC2021_V1_Running_B.CANReceive_o4[7]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
    }

    /* Nothing to do for system: <S397>/Nothing */
  }

  FLEXCAN(2).IFRL.B.BUF00I = 1;        /* Clear CAN interrupt flag by writing it to 1 */
}

void ISR_FlexCAN_2_MB8(void)
{
  /* Call the system: <S382>/CCPTransmit */
  {
    /* Output and update for function-call system: '<S382>/CCPTransmit' */

    /* S-Function (ec55xx_ccpslb2): '<S398>/CCPTXConfirmation' */
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
void FSAC2021_V1_Running_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(FSAC2021_V1_Running_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(FSAC2021_V1_Running_M, 2));
  eventFlags[3] = ((boolean_T)rtmStepTask(FSAC2021_V1_Running_M, 3));
  eventFlags[4] = ((boolean_T)rtmStepTask(FSAC2021_V1_Running_M, 4));
  eventFlags[5] = ((boolean_T)rtmStepTask(FSAC2021_V1_Running_M, 5));
  eventFlags[6] = ((boolean_T)rtmStepTask(FSAC2021_V1_Running_M, 6));
  eventFlags[7] = ((boolean_T)rtmStepTask(FSAC2021_V1_Running_M, 7));
  eventFlags[8] = ((boolean_T)rtmStepTask(FSAC2021_V1_Running_M, 8));
  eventFlags[9] = ((boolean_T)rtmStepTask(FSAC2021_V1_Running_M, 9));
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
  if (FSAC2021_V1_Running_M->Timing.TaskCounters.TID[1] == 0) {
    FSAC2021_V1_Running_M->Timing.RateInteraction.TID1_7 =
      (FSAC2021_V1_Running_M->Timing.TaskCounters.TID[7] == 0);
  }

  /* tid 3 shares data with slower tid rate: 7 */
  if (FSAC2021_V1_Running_M->Timing.TaskCounters.TID[3] == 0) {
    FSAC2021_V1_Running_M->Timing.RateInteraction.TID3_7 =
      (FSAC2021_V1_Running_M->Timing.TaskCounters.TID[7] == 0);
  }

  /* tid 6 shares data with slower tid rate: 7 */
  if (FSAC2021_V1_Running_M->Timing.TaskCounters.TID[6] == 0) {
    FSAC2021_V1_Running_M->Timing.RateInteraction.TID6_7 =
      (FSAC2021_V1_Running_M->Timing.TaskCounters.TID[7] == 0);
  }

  /* tid 7 shares data with slower tid rate: 9 */
  if (FSAC2021_V1_Running_M->Timing.TaskCounters.TID[7] == 0) {
    FSAC2021_V1_Running_M->Timing.RateInteraction.TID7_9 =
      (FSAC2021_V1_Running_M->Timing.TaskCounters.TID[9] == 0);
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (FSAC2021_V1_Running_M->Timing.TaskCounters.TID[1])++;
  if ((FSAC2021_V1_Running_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.001s, 0.0s] */
    FSAC2021_V1_Running_M->Timing.TaskCounters.TID[1] = 0;
  }

  (FSAC2021_V1_Running_M->Timing.TaskCounters.TID[2])++;
  if ((FSAC2021_V1_Running_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.005s, 0.0s] */
    FSAC2021_V1_Running_M->Timing.TaskCounters.TID[2] = 0;
  }

  (FSAC2021_V1_Running_M->Timing.TaskCounters.TID[3])++;
  if ((FSAC2021_V1_Running_M->Timing.TaskCounters.TID[3]) > 19) {/* Sample time: [0.01s, 0.0s] */
    FSAC2021_V1_Running_M->Timing.TaskCounters.TID[3] = 0;
  }

  (FSAC2021_V1_Running_M->Timing.TaskCounters.TID[4])++;
  if ((FSAC2021_V1_Running_M->Timing.TaskCounters.TID[4]) > 39) {/* Sample time: [0.02s, 0.0s] */
    FSAC2021_V1_Running_M->Timing.TaskCounters.TID[4] = 0;
  }

  (FSAC2021_V1_Running_M->Timing.TaskCounters.TID[5])++;
  if ((FSAC2021_V1_Running_M->Timing.TaskCounters.TID[5]) > 59) {/* Sample time: [0.03s, 0.0s] */
    FSAC2021_V1_Running_M->Timing.TaskCounters.TID[5] = 0;
  }

  (FSAC2021_V1_Running_M->Timing.TaskCounters.TID[6])++;
  if ((FSAC2021_V1_Running_M->Timing.TaskCounters.TID[6]) > 99) {/* Sample time: [0.05s, 0.0s] */
    FSAC2021_V1_Running_M->Timing.TaskCounters.TID[6] = 0;
  }

  (FSAC2021_V1_Running_M->Timing.TaskCounters.TID[7])++;
  if ((FSAC2021_V1_Running_M->Timing.TaskCounters.TID[7]) > 199) {/* Sample time: [0.1s, 0.0s] */
    FSAC2021_V1_Running_M->Timing.TaskCounters.TID[7] = 0;
  }

  (FSAC2021_V1_Running_M->Timing.TaskCounters.TID[8])++;
  if ((FSAC2021_V1_Running_M->Timing.TaskCounters.TID[8]) > 399) {/* Sample time: [0.2s, 0.0s] */
    FSAC2021_V1_Running_M->Timing.TaskCounters.TID[8] = 0;
  }

  (FSAC2021_V1_Running_M->Timing.TaskCounters.TID[9])++;
  if ((FSAC2021_V1_Running_M->Timing.TaskCounters.TID[9]) > 999) {/* Sample time: [0.5s, 0.0s] */
    FSAC2021_V1_Running_M->Timing.TaskCounters.TID[9] = 0;
  }
}

/*
 * Initial conditions for atomic system:
 *    '<S196>/LPF'
 *    '<S196>/LPF1'
 *    '<S196>/LPF2'
 *    '<S196>/LPF3'
 */
void FSAC2021_V1_Runni_LPF_Init(DW_LPF_FSAC2021_V1_Running_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S197>/Unit Delay' */
  localDW->UnitDelay_DSTATE = 1.0F;
}

/*
 * Output and update for atomic system:
 *    '<S196>/LPF'
 *    '<S196>/LPF1'
 *    '<S196>/LPF2'
 *    '<S196>/LPF3'
 */
void FSAC2021_V1_Running_LPF(real32_T rtu_Filter, B_LPF_FSAC2021_V1_Running_T
  *localB, DW_LPF_FSAC2021_V1_Running_T *localDW)
{
  /* Sum: '<S197>/Add1' incorporates:
   *  Constant: '<S197>/Constant'
   *  Product: '<S197>/Product'
   *  Sum: '<S197>/Add'
   *  UnitDelay: '<S197>/Unit Delay'
   */
  localB->Add1 = (rtu_Filter - localDW->UnitDelay_DSTATE) * 0.5F +
    localDW->UnitDelay_DSTATE;

  /* Update for UnitDelay: '<S197>/Unit Delay' */
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

/* Output and update for atomic system: '<S202>/Round' */
void FSAC2021_V1_Running_Round(real32_T rtu_Origin_Precision)
{
  /* Gain: '<S207>/Gain2' incorporates:
   *  Gain: '<S207>/Gain1'
   */
  Vel_spd = (real32_T)(uint8_T)rt_roundf_snf(10.0F * rtu_Origin_Precision) *
    0.1F;
}

/*
 * Output and update for atomic system:
 *    '<S196>/Whl_Spd_Hz2RPM'
 *    '<S196>/Whl_Spd_Hz2RPM1'
 */
void FSAC2021_V1_Whl_Spd_Hz2RPM(uint32_T rtu_Whl_Spd_Hz,
  B_Whl_Spd_Hz2RPM_FSAC2021_V1__T *localB)
{
  /* Gain: '<S203>/rps2rpm' incorporates:
   *  Constant: '<S203>/Constant'
   *  Product: '<S203>/Divide'
   */
  localB->rps2rpm = (real32_T)rtu_Whl_Spd_Hz / 60.0F * 60.0F;
}

/*
 * Output and update for atomic system:
 *    '<S196>/Whl_Spd_Hz2RPM2'
 *    '<S196>/Whl_Spd_Hz2RPM3'
 */
void FSAC2021_V_Whl_Spd_Hz2RPM2(uint32_T rtu_Whl_Spd_Hz,
  B_Whl_Spd_Hz2RPM2_FSAC2021_V1_T *localB)
{
  /* Gain: '<S205>/rps2rpm' incorporates:
   *  Constant: '<S205>/Constant'
   *  Product: '<S205>/Divide'
   */
  localB->rps2rpm = (real32_T)rtu_Whl_Spd_Hz / 30.0F * 60.0F;
}

/* Output and update for function-call system: '<S13>/MOTEC_CONTROL' */
void FSAC2021_V1__MOTEC_CONTROL(real32_T rtu_Abs_or_Rel_Ctrl_in, real32_T
  rtu_Fault_Reset_in, real32_T rtu_Enable_Voltage_Ctrl_in, real32_T
  rtu_New_Pos_Set_in, real32_T rtu_Enable_Operation_Ctrl_in, real32_T
  rtu_Switch_On_Ctrl_in, real32_T rtu_Quick_Stop_Ctrl_in, real32_T
  rtu_Halt_Ctrl_in, real32_T rtu_Position_set_in,
  B_MOTEC_CONTROL_FSAC2021_V1_R_T *localB)
{
  uint32_T rtb_Position_set_L;
  real32_T rtb_Position_setRon;
  real32_T rtu_Enable_Voltage_Ctrl_in_0;
  real32_T rtu_New_Pos_Set_in_0;
  real32_T rtu_Enable_Operation_Ctrl_in_0;
  real32_T rtu_Abs_or_Rel_Ctrl_in_0;
  real32_T rtu_Switch_On_Ctrl_in_0;
  real32_T rtu_Quick_Stop_Ctrl_in_0;

  /* Saturate: '<S48>/Fault_Reset_sat' */
  if (rtu_Fault_Reset_in > 1.0F) {
    rtb_Position_setRon = 1.0F;
  } else if (rtu_Fault_Reset_in < 0.0F) {
    rtb_Position_setRon = 0.0F;
  } else {
    rtb_Position_setRon = rtu_Fault_Reset_in;
  }

  /* Saturate: '<S47>/Enable_Voltage_Ctrl_sat' */
  if (rtu_Enable_Voltage_Ctrl_in > 1.0F) {
    rtu_Enable_Voltage_Ctrl_in_0 = 1.0F;
  } else if (rtu_Enable_Voltage_Ctrl_in < 0.0F) {
    rtu_Enable_Voltage_Ctrl_in_0 = 0.0F;
  } else {
    rtu_Enable_Voltage_Ctrl_in_0 = rtu_Enable_Voltage_Ctrl_in;
  }

  /* Saturate: '<S50>/New_Pos_Set_sat' */
  if (rtu_New_Pos_Set_in > 1.0F) {
    rtu_New_Pos_Set_in_0 = 1.0F;
  } else if (rtu_New_Pos_Set_in < 0.0F) {
    rtu_New_Pos_Set_in_0 = 0.0F;
  } else {
    rtu_New_Pos_Set_in_0 = rtu_New_Pos_Set_in;
  }

  /* Saturate: '<S46>/Enable_Operation_Ctrl_sat' */
  if (rtu_Enable_Operation_Ctrl_in > 1.0F) {
    rtu_Enable_Operation_Ctrl_in_0 = 1.0F;
  } else if (rtu_Enable_Operation_Ctrl_in < 0.0F) {
    rtu_Enable_Operation_Ctrl_in_0 = 0.0F;
  } else {
    rtu_Enable_Operation_Ctrl_in_0 = rtu_Enable_Operation_Ctrl_in;
  }

  /* Saturate: '<S45>/Abs_or_Rel_Ctrl_sat' */
  if (rtu_Abs_or_Rel_Ctrl_in > 1.0F) {
    rtu_Abs_or_Rel_Ctrl_in_0 = 1.0F;
  } else if (rtu_Abs_or_Rel_Ctrl_in < 0.0F) {
    rtu_Abs_or_Rel_Ctrl_in_0 = 0.0F;
  } else {
    rtu_Abs_or_Rel_Ctrl_in_0 = rtu_Abs_or_Rel_Ctrl_in;
  }

  /* Saturate: '<S53>/Switch_On_Ctrl_sat' */
  if (rtu_Switch_On_Ctrl_in > 1.0F) {
    rtu_Switch_On_Ctrl_in_0 = 1.0F;
  } else if (rtu_Switch_On_Ctrl_in < 0.0F) {
    rtu_Switch_On_Ctrl_in_0 = 0.0F;
  } else {
    rtu_Switch_On_Ctrl_in_0 = rtu_Switch_On_Ctrl_in;
  }

  /* Saturate: '<S52>/Quick_Stop_Ctrl_sat' */
  if (rtu_Quick_Stop_Ctrl_in > 1.0F) {
    rtu_Quick_Stop_Ctrl_in_0 = 1.0F;
  } else if (rtu_Quick_Stop_Ctrl_in < 0.0F) {
    rtu_Quick_Stop_Ctrl_in_0 = 0.0F;
  } else {
    rtu_Quick_Stop_Ctrl_in_0 = rtu_Quick_Stop_Ctrl_in;
  }

  /* DataTypeConversion: '<S37>/Conv1' incorporates:
   *  ArithShift: '<S45>/Abs_or_Rel_Ctrl_S'
   *  ArithShift: '<S46>/Enable_Operation_Ctrl_S'
   *  ArithShift: '<S47>/Enable_Voltage_Ctrl_S'
   *  ArithShift: '<S48>/Fault_Reset_S'
   *  ArithShift: '<S50>/New_Pos_Set_S'
   *  ArithShift: '<S52>/Quick_Stop_Ctrl_S'
   *  DataTypeConversion: '<S45>/Abs_or_Rel_Ctrl_Convert'
   *  DataTypeConversion: '<S45>/Abs_or_Rel_Ctrl_Convert1'
   *  DataTypeConversion: '<S46>/Enable_Operation_Ctrl_Convert'
   *  DataTypeConversion: '<S46>/Enable_Operation_Ctrl_Convert1'
   *  DataTypeConversion: '<S47>/Enable_Voltage_Ctrl_Convert'
   *  DataTypeConversion: '<S47>/Enable_Voltage_Ctrl_Convert1'
   *  DataTypeConversion: '<S48>/Fault_Reset_Convert'
   *  DataTypeConversion: '<S48>/Fault_Reset_Convert1'
   *  DataTypeConversion: '<S50>/New_Pos_Set_Convert'
   *  DataTypeConversion: '<S50>/New_Pos_Set_Convert1'
   *  DataTypeConversion: '<S52>/Quick_Stop_Ctrl_Convert'
   *  DataTypeConversion: '<S52>/Quick_Stop_Ctrl_Convert1'
   *  DataTypeConversion: '<S53>/Switch_On_Ctrl_Convert'
   *  DataTypeConversion: '<S53>/Switch_On_Ctrl_Convert1'
   *  Rounding: '<S45>/Abs_or_Rel_CtrlRon'
   *  Rounding: '<S46>/Enable_Operation_CtrlRon'
   *  Rounding: '<S47>/Enable_Voltage_CtrlRon'
   *  Rounding: '<S48>/Fault_ResetRon'
   *  Rounding: '<S50>/New_Pos_SetRon'
   *  Rounding: '<S52>/Quick_Stop_CtrlRon'
   *  Rounding: '<S53>/Switch_On_CtrlRon'
   *  S-Function (sfix_bitop): '<S37>/or1'
   *  S-Function (sfix_bitop): '<S45>/Abs_or_Rel_Ctrl_L'
   *  S-Function (sfix_bitop): '<S46>/Enable_Operation_Ctrl_L'
   *  S-Function (sfix_bitop): '<S47>/Enable_Voltage_Ctrl_L'
   *  S-Function (sfix_bitop): '<S48>/Fault_Reset_L'
   *  S-Function (sfix_bitop): '<S50>/New_Pos_Set_L'
   *  S-Function (sfix_bitop): '<S52>/Quick_Stop_Ctrl_L'
   *  S-Function (sfix_bitop): '<S53>/Switch_On_Ctrl_L'
   *  Saturate: '<S45>/Abs_or_Rel_Ctrl_1sat'
   *  Saturate: '<S45>/Abs_or_Rel_Ctrl_sat'
   *  Saturate: '<S46>/Enable_Operation_Ctrl_1sat'
   *  Saturate: '<S46>/Enable_Operation_Ctrl_sat'
   *  Saturate: '<S47>/Enable_Voltage_Ctrl_1sat'
   *  Saturate: '<S47>/Enable_Voltage_Ctrl_sat'
   *  Saturate: '<S48>/Fault_Reset_1sat'
   *  Saturate: '<S48>/Fault_Reset_sat'
   *  Saturate: '<S50>/New_Pos_Set_1sat'
   *  Saturate: '<S50>/New_Pos_Set_sat'
   *  Saturate: '<S52>/Quick_Stop_Ctrl_1sat'
   *  Saturate: '<S52>/Quick_Stop_Ctrl_sat'
   *  Saturate: '<S53>/Switch_On_Ctrl_1sat'
   *  Saturate: '<S53>/Switch_On_Ctrl_sat'
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

  /* Saturate: '<S49>/Halt_Ctrl_sat' */
  if (rtu_Halt_Ctrl_in > 1.0F) {
    rtb_Position_setRon = 1.0F;
  } else if (rtu_Halt_Ctrl_in < 0.0F) {
    rtb_Position_setRon = 0.0F;
  } else {
    rtb_Position_setRon = rtu_Halt_Ctrl_in;
  }

  /* DataTypeConversion: '<S37>/Conv2' incorporates:
   *  DataTypeConversion: '<S49>/Halt_Ctrl_Convert'
   *  DataTypeConversion: '<S49>/Halt_Ctrl_Convert1'
   *  Rounding: '<S49>/Halt_CtrlRon'
   *  S-Function (sfix_bitop): '<S49>/Halt_Ctrl_L'
   *  Saturate: '<S49>/Halt_Ctrl_1sat'
   *  Saturate: '<S49>/Halt_Ctrl_sat'
   */
  localB->Conv2 = (uint8_T)((uint32_T)rt_roundf_snf(rtb_Position_setRon) & 1U);

  /* Saturate: '<S51>/Position_set_sat' */
  if (rtu_Position_set_in > 3.8654705E+6F) {
    rtb_Position_setRon = 3.8654705E+6F;
  } else if (rtu_Position_set_in < -3.8654705E+6F) {
    rtb_Position_setRon = -3.8654705E+6F;
  } else {
    rtb_Position_setRon = rtu_Position_set_in;
  }

  /* Rounding: '<S51>/Position_setRon' incorporates:
   *  Constant: '<S51>/Position_set_F'
   *  Product: '<S51>/Position_set_D'
   *  Saturate: '<S51>/Position_set_sat'
   */
  rtb_Position_setRon = rt_roundf_snf(rtb_Position_setRon / 0.00144F);

  /* Switch: '<S51>/Position_setSW' incorporates:
   *  Abs: '<S51>/Position_setABS'
   *  RelationalOperator: '<S51>/Position_setROP'
   *  Sum: '<S51>/Position_setsubcon'
   */
  if (rtb_Position_setRon < 0.0F) {
    rtb_Position_setRon = 4.2949673E+9F - (real32_T)fabs(rtb_Position_setRon);
  }

  /* End of Switch: '<S51>/Position_setSW' */

  /* Saturate: '<S51>/Position_set_1sat' */
  if (rtb_Position_setRon > 4.2949673E+9F) {
    rtb_Position_setRon = 4.2949673E+9F;
  }

  /* End of Saturate: '<S51>/Position_set_1sat' */

  /* S-Function (sfix_bitop): '<S51>/Position_set_L' incorporates:
   *  DataTypeConversion: '<S51>/Position_set_Convert'
   */
  rtb_Position_set_L = (uint32_T)rtb_Position_setRon;

  /* DataTypeConversion: '<S37>/Conv3' incorporates:
   *  Constant: '<S51>/Position_set_And2_C'
   *  DataTypeConversion: '<S51>/Position_setBitCov2'
   *  S-Function (sfix_bitop): '<S51>/Position_set_And2'
   */
  localB->Conv3 = (uint8_T)(rtb_Position_set_L & 255U);

  /* DataTypeConversion: '<S37>/Conv4' incorporates:
   *  Constant: '<S51>/Position_setoutput4_C'
   *  DataTypeConversion: '<S51>/Position_setCOV2'
   *  Product: '<S51>/Position_set_D3'
   *  S-Function (sfix_bitop): '<S51>/Position_set_And1'
   */
  localB->Conv4 = (uint8_T)((real_T)((int32_T)rtb_Position_set_L & 65535) /
    256.0);

  /* DataTypeConversion: '<S37>/Conv5' incorporates:
   *  Constant: '<S51>/Position_setoutput5_C'
   *  DataTypeConversion: '<S51>/Position_setCOV1'
   *  Product: '<S51>/Position_set_D2'
   *  S-Function (sfix_bitop): '<S51>/Position_set_And'
   */
  localB->Conv5 = (uint8_T)((real_T)((int32_T)rtb_Position_set_L & 16777215) /
    65536.0);

  /* DataTypeConversion: '<S37>/Conv6' incorporates:
   *  Constant: '<S51>/Position_setoutput6_C'
   *  DataTypeConversion: '<S51>/Position_setCOV'
   *  Product: '<S51>/Position_set_D1'
   */
  localB->Conv6 = (uint8_T)((real_T)rtb_Position_set_L / 1.6777216E+7);
}

/*
 * Enable for atomic system:
 *    '<S129>/Chart2'
 *    '<S129>/Chart3'
 *    '<S129>/Chart4'
 *    '<S129>/Chart5'
 *    '<S129>/Chart6'
 */
void FSAC2021_V1__Chart2_Enable(RT_MODEL_FSAC2021_V1_Running_T * const
  FSAC2021_V1_Running_M, DW_Chart2_FSAC2021_V1_Running_T *localDW)
{
  localDW->presentTicks = FSAC2021_V1_Running_M->Timing.clockTick7;
  localDW->previousTicks = localDW->presentTicks;
}

/*
 * Disable for atomic system:
 *    '<S129>/Chart2'
 *    '<S129>/Chart3'
 *    '<S129>/Chart4'
 *    '<S129>/Chart5'
 *    '<S129>/Chart6'
 */
void FSAC2021_V1_Chart2_Disable(RT_MODEL_FSAC2021_V1_Running_T * const
  FSAC2021_V1_Running_M, DW_Chart2_FSAC2021_V1_Running_T *localDW)
{
  localDW->presentTicks = FSAC2021_V1_Running_M->Timing.clockTick7;
  localDW->elapsedTicks = localDW->presentTicks - localDW->previousTicks;
  localDW->previousTicks = localDW->presentTicks;
  if (localDW->temporalCounter_i1 + localDW->elapsedTicks <= 31U) {
    localDW->temporalCounter_i1 = (uint8_T)(localDW->temporalCounter_i1 +
      localDW->elapsedTicks);
  } else {
    localDW->temporalCounter_i1 = 31U;
  }
}

/*
 * Output and update for atomic system:
 *    '<S129>/Chart2'
 *    '<S129>/Chart3'
 *    '<S129>/Chart4'
 *    '<S129>/Chart5'
 *    '<S129>/Chart6'
 */
void FSAC2021_V1_Running_Chart2(RT_MODEL_FSAC2021_V1_Running_T * const
  FSAC2021_V1_Running_M, uint8_T rtu_Non_Debounce,
  B_Chart2_FSAC2021_V1_Running_T *localB, DW_Chart2_FSAC2021_V1_Running_T
  *localDW)
{
  localDW->presentTicks = FSAC2021_V1_Running_M->Timing.clockTick7;
  localDW->elapsedTicks = localDW->presentTicks - localDW->previousTicks;
  localDW->previousTicks = localDW->presentTicks;
  if (localDW->temporalCounter_i1 + localDW->elapsedTicks <= 31U) {
    localDW->temporalCounter_i1 = (uint8_T)(localDW->temporalCounter_i1 +
      localDW->elapsedTicks);
  } else {
    localDW->temporalCounter_i1 = 31U;
  }

  /* Gateway: DIAG/DIAG/Analog_Sensor_Diag/Chart2 */
  /* During: DIAG/DIAG/Analog_Sensor_Diag/Chart2 */
  if (localDW->bitsForTID7.is_active_c15_FSAC2021_V1_Runni == 0U) {
    /* Entry: DIAG/DIAG/Analog_Sensor_Diag/Chart2 */
    localDW->bitsForTID7.is_active_c15_FSAC2021_V1_Runni = 1U;

    /* Entry Internal: DIAG/DIAG/Analog_Sensor_Diag/Chart2 */
    /* Transition: '<S138>:4' */
    localDW->bitsForTID7.is_c15_FSAC2021_V1_Running = FSAC2021_V1_Running_IN_Off;

    /* Entry 'Off': '<S138>:3' */
    localB->Debounce = 0U;
  } else {
    switch (localDW->bitsForTID7.is_c15_FSAC2021_V1_Running) {
     case FSAC2021_V1_Running_IN_Off:
      /* During 'Off': '<S138>:3' */
      if (rtu_Non_Debounce > 0) {
        /* Transition: '<S138>:7' */
        localDW->bitsForTID7.is_c15_FSAC2021_V1_Running =
          FSAC2021_V1_Running_IN_Wait;
        localDW->temporalCounter_i1 = 0U;
      }
      break;

     case FSAC2021_V1_Running_IN_On:
      /* During 'On': '<S138>:5' */
      if (rtu_Non_Debounce == 0) {
        /* Transition: '<S138>:10' */
        localDW->bitsForTID7.is_c15_FSAC2021_V1_Running =
          FSAC2021_V1_Running_IN_Off;

        /* Entry 'Off': '<S138>:3' */
        localB->Debounce = 0U;
      }
      break;

     default:
      /* During 'Wait': '<S138>:6' */
      if (rtu_Non_Debounce == 0) {
        /* Transition: '<S138>:11' */
        localDW->bitsForTID7.is_c15_FSAC2021_V1_Running =
          FSAC2021_V1_Running_IN_Off;

        /* Entry 'Off': '<S138>:3' */
        localB->Debounce = 0U;
      } else {
        if (localDW->temporalCounter_i1 >= 20U) {
          /* Transition: '<S138>:8' */
          localDW->bitsForTID7.is_c15_FSAC2021_V1_Running =
            FSAC2021_V1_Running_IN_On;

          /* Entry 'On': '<S138>:5' */
          localB->Debounce = 1U;
        }
      }
      break;
    }
  }
}

/* Enable for atomic system: '<S149>/Chart' */
void FSAC2021_V1_R_Chart_Enable(RT_MODEL_FSAC2021_V1_Running_T * const
  FSAC2021_V1_Running_M, DW_Chart_FSAC2021_V1_Running_T *localDW)
{
  localDW->presentTicks = FSAC2021_V1_Running_M->Timing.clockTick7;
  localDW->previousTicks = localDW->presentTicks;
}

/* Disable for atomic system: '<S149>/Chart' */
void FSAC2021_V1__Chart_Disable(RT_MODEL_FSAC2021_V1_Running_T * const
  FSAC2021_V1_Running_M, DW_Chart_FSAC2021_V1_Running_T *localDW)
{
  localDW->presentTicks = FSAC2021_V1_Running_M->Timing.clockTick7;
  localDW->elapsedTicks = localDW->presentTicks - localDW->previousTicks;
  localDW->previousTicks = localDW->presentTicks;
  if (localDW->temporalCounter_i1 + localDW->elapsedTicks <= 31U) {
    localDW->temporalCounter_i1 = (uint8_T)(localDW->temporalCounter_i1 +
      localDW->elapsedTicks);
  } else {
    localDW->temporalCounter_i1 = 31U;
  }
}

/* Output and update for atomic system: '<S149>/Chart' */
void FSAC2021_V1_Running_Chart(RT_MODEL_FSAC2021_V1_Running_T * const
  FSAC2021_V1_Running_M, uint8_T rtu_Input, B_Chart_FSAC2021_V1_Running_T
  *localB, DW_Chart_FSAC2021_V1_Running_T *localDW)
{
  localDW->presentTicks = FSAC2021_V1_Running_M->Timing.clockTick7;
  localDW->elapsedTicks = localDW->presentTicks - localDW->previousTicks;
  localDW->previousTicks = localDW->presentTicks;
  if (localDW->temporalCounter_i1 + localDW->elapsedTicks <= 31U) {
    localDW->temporalCounter_i1 = (uint8_T)(localDW->temporalCounter_i1 +
      localDW->elapsedTicks);
  } else {
    localDW->temporalCounter_i1 = 31U;
  }

  /* Gateway: DIAG/DIAG/CAN_NODE_LOSTCOM/B_M_S_Check/Chart */
  /* During: DIAG/DIAG/CAN_NODE_LOSTCOM/B_M_S_Check/Chart */
  if (localDW->bitsForTID7.is_active_c4_FSAC2021_V1_Runnin == 0U) {
    /* Entry: DIAG/DIAG/CAN_NODE_LOSTCOM/B_M_S_Check/Chart */
    localDW->bitsForTID7.is_active_c4_FSAC2021_V1_Runnin = 1U;

    /* Entry Internal: DIAG/DIAG/CAN_NODE_LOSTCOM/B_M_S_Check/Chart */
    /* Transition: '<S155>:21' */
    localDW->bitsForTID7.is_c4_FSAC2021_V1_Running =
      FSAC2021_V1_Running_IN_Normal;
    localDW->temporalCounter_i1 = 0U;

    /* Entry 'Normal': '<S155>:13' */
    localB->Output = 1U;
  } else {
    switch (localDW->bitsForTID7.is_c4_FSAC2021_V1_Running) {
     case FSAC2021_V1_Running_IN_Normal:
      /* During 'Normal': '<S155>:13' */
      if ((rtu_Input == 0) && (localDW->temporalCounter_i1 >= 5U)) {
        /* Transition: '<S155>:16' */
        localDW->bitsForTID7.is_c4_FSAC2021_V1_Running =
          FSAC2021_V1_Running_IN_ON;
        localDW->temporalCounter_i1 = 0U;
      }
      break;

     case FSAC2021_V1_Running_IN_ON:
      /* During 'ON': '<S155>:14' */
      if (rtu_Input == 1) {
        /* Transition: '<S155>:17' */
        localDW->bitsForTID7.is_c4_FSAC2021_V1_Running =
          FSAC2021_V1_Running_IN_Off_i;
      } else {
        if (localDW->temporalCounter_i1 >= 20U) {
          /* Transition: '<S155>:20' */
          localDW->bitsForTID7.is_c4_FSAC2021_V1_Running =
            FSAC2021_V1_Running_IN_On_b;

          /* Entry 'On': '<S155>:15' */
          localB->Output = 0U;
        }
      }
      break;

     case FSAC2021_V1_Running_IN_Off_i:
      /* During 'Off': '<S155>:12' */
      if (rtu_Input == 0) {
        /* Transition: '<S155>:19' */
        localDW->bitsForTID7.is_c4_FSAC2021_V1_Running =
          FSAC2021_V1_Running_IN_ON;
        localDW->temporalCounter_i1 = 0U;
      }
      break;

     default:
      /* During 'On': '<S155>:15' */
      break;
    }
  }
}

/*
 * Enable for atomic system:
 *    '<S149>/Chart1'
 *    '<S154>/Chart2'
 *    '<S154>/Chart3'
 *    '<S154>/Chart4'
 */
void FSAC2021_V1__Chart1_Enable(RT_MODEL_FSAC2021_V1_Running_T * const
  FSAC2021_V1_Running_M, DW_Chart1_FSAC2021_V1_Running_T *localDW)
{
  localDW->presentTicks = FSAC2021_V1_Running_M->Timing.clockTick7;
  localDW->previousTicks = localDW->presentTicks;
}

/*
 * Disable for atomic system:
 *    '<S149>/Chart1'
 *    '<S154>/Chart2'
 *    '<S154>/Chart3'
 *    '<S154>/Chart4'
 */
void FSAC2021_V1_Chart1_Disable(RT_MODEL_FSAC2021_V1_Running_T * const
  FSAC2021_V1_Running_M, DW_Chart1_FSAC2021_V1_Running_T *localDW)
{
  localDW->presentTicks = FSAC2021_V1_Running_M->Timing.clockTick7;
  localDW->elapsedTicks = localDW->presentTicks - localDW->previousTicks;
  localDW->previousTicks = localDW->presentTicks;
  if (localDW->temporalCounter_i1 + localDW->elapsedTicks <= 31U) {
    localDW->temporalCounter_i1 = (uint8_T)(localDW->temporalCounter_i1 +
      localDW->elapsedTicks);
  } else {
    localDW->temporalCounter_i1 = 31U;
  }
}

/*
 * Output and update for atomic system:
 *    '<S149>/Chart1'
 *    '<S154>/Chart2'
 *    '<S154>/Chart3'
 *    '<S154>/Chart4'
 */
void FSAC2021_V1_Running_Chart1(RT_MODEL_FSAC2021_V1_Running_T * const
  FSAC2021_V1_Running_M, uint8_T rtu_Input, B_Chart1_FSAC2021_V1_Running_T
  *localB, DW_Chart1_FSAC2021_V1_Running_T *localDW)
{
  localDW->presentTicks = FSAC2021_V1_Running_M->Timing.clockTick7;
  localDW->elapsedTicks = localDW->presentTicks - localDW->previousTicks;
  localDW->previousTicks = localDW->presentTicks;
  if (localDW->temporalCounter_i1 + localDW->elapsedTicks <= 31U) {
    localDW->temporalCounter_i1 = (uint8_T)(localDW->temporalCounter_i1 +
      localDW->elapsedTicks);
  } else {
    localDW->temporalCounter_i1 = 31U;
  }

  /* Gateway: DIAG/DIAG/CAN_NODE_LOSTCOM/B_M_S_Check/Chart1 */
  /* During: DIAG/DIAG/CAN_NODE_LOSTCOM/B_M_S_Check/Chart1 */
  if (localDW->bitsForTID7.is_active_c6_FSAC2021_V1_Runnin == 0U) {
    /* Entry: DIAG/DIAG/CAN_NODE_LOSTCOM/B_M_S_Check/Chart1 */
    localDW->bitsForTID7.is_active_c6_FSAC2021_V1_Runnin = 1U;

    /* Entry Internal: DIAG/DIAG/CAN_NODE_LOSTCOM/B_M_S_Check/Chart1 */
    /* Transition: '<S156>:21' */
    localDW->bitsForTID7.is_c6_FSAC2021_V1_Running =
      FSAC2021_V1_Running_IN_Normal_b;

    /* Entry 'Normal': '<S156>:13' */
    localB->Output = 1U;
  } else {
    switch (localDW->bitsForTID7.is_c6_FSAC2021_V1_Running) {
     case FSAC2021_V1_Running_IN_Normal_b:
      /* During 'Normal': '<S156>:13' */
      if (rtu_Input == 0) {
        /* Transition: '<S156>:16' */
        localDW->bitsForTID7.is_c6_FSAC2021_V1_Running =
          FSAC2021_V1_Running_IN_ON_b;
        localDW->temporalCounter_i1 = 0U;
      }
      break;

     case FSAC2021_V1_Running_IN_ON_b:
      /* During 'ON': '<S156>:14' */
      if (rtu_Input == 1) {
        /* Transition: '<S156>:17' */
        localDW->bitsForTID7.is_c6_FSAC2021_V1_Running =
          FSAC2021_V1_Running_IN_Off_k;
      } else {
        if (localDW->temporalCounter_i1 >= 20U) {
          /* Transition: '<S156>:20' */
          localDW->bitsForTID7.is_c6_FSAC2021_V1_Running =
            FSAC2021_V1_Running_IN_On_a;

          /* Entry 'On': '<S156>:15' */
          localB->Output = 0U;
        }
      }
      break;

     case FSAC2021_V1_Running_IN_Off_k:
      /* During 'Off': '<S156>:12' */
      if (rtu_Input == 0) {
        /* Transition: '<S156>:19' */
        localDW->bitsForTID7.is_c6_FSAC2021_V1_Running =
          FSAC2021_V1_Running_IN_ON_b;
        localDW->temporalCounter_i1 = 0U;
      }
      break;

     default:
      /* During 'On': '<S156>:15' */
      break;
    }
  }
}

/* Enable for atomic system: '<S153>/Chart4' */
void FSAC2021_V1__Chart4_Enable(RT_MODEL_FSAC2021_V1_Running_T * const
  FSAC2021_V1_Running_M, DW_Chart4_FSAC2021_V1_Running_T *localDW)
{
  localDW->presentTicks = FSAC2021_V1_Running_M->Timing.clockTick7;
  localDW->previousTicks = localDW->presentTicks;
}

/* Disable for atomic system: '<S153>/Chart4' */
void FSAC2021_V1_Chart4_Disable(RT_MODEL_FSAC2021_V1_Running_T * const
  FSAC2021_V1_Running_M, DW_Chart4_FSAC2021_V1_Running_T *localDW)
{
  localDW->presentTicks = FSAC2021_V1_Running_M->Timing.clockTick7;
  localDW->elapsedTicks = localDW->presentTicks - localDW->previousTicks;
  localDW->previousTicks = localDW->presentTicks;
  if (localDW->temporalCounter_i1 + localDW->elapsedTicks <= 31U) {
    localDW->temporalCounter_i1 = (uint8_T)(localDW->temporalCounter_i1 +
      localDW->elapsedTicks);
  } else {
    localDW->temporalCounter_i1 = 31U;
  }
}

/* Output and update for atomic system: '<S153>/Chart4' */
void FSAC2021_V1_Running_Chart4(RT_MODEL_FSAC2021_V1_Running_T * const
  FSAC2021_V1_Running_M, uint8_T rtu_Input, DW_Chart4_FSAC2021_V1_Running_T
  *localDW)
{
  localDW->presentTicks = FSAC2021_V1_Running_M->Timing.clockTick7;
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
  if (localDW->bitsForTID7.is_active_c11_FSAC2021_V1_Runni == 0U) {
    /* Entry: DIAG/DIAG/CAN_NODE_LOSTCOM/Subsystem/Chart4 */
    localDW->bitsForTID7.is_active_c11_FSAC2021_V1_Runni = 1U;

    /* Entry Internal: DIAG/DIAG/CAN_NODE_LOSTCOM/Subsystem/Chart4 */
    /* Transition: '<S159>:21' */
    localDW->bitsForTID7.is_c11_FSAC2021_V1_Running =
      FSAC2021_V1_Running_IN_Normal_h;

    /* Entry 'Normal': '<S159>:13' */
    motor = 1U;
  } else {
    switch (localDW->bitsForTID7.is_c11_FSAC2021_V1_Running) {
     case FSAC2021_V1_Running_IN_Normal_h:
      /* During 'Normal': '<S159>:13' */
      if (rtu_Input == 0) {
        /* Transition: '<S159>:16' */
        localDW->bitsForTID7.is_c11_FSAC2021_V1_Running =
          FSAC2021_V1_Running_IN_ON_j;
        localDW->temporalCounter_i1 = 0U;
      }
      break;

     case FSAC2021_V1_Running_IN_ON_j:
      /* During 'ON': '<S159>:14' */
      if (rtu_Input == 1) {
        /* Transition: '<S159>:17' */
        localDW->bitsForTID7.is_c11_FSAC2021_V1_Running =
          FSAC2021_V1_Running_IN_Off_g;
      } else {
        if (localDW->temporalCounter_i1 >= 20U) {
          /* Transition: '<S159>:20' */
          localDW->bitsForTID7.is_c11_FSAC2021_V1_Running =
            FSAC2021_V1_Running_IN_On_az;

          /* Entry 'On': '<S159>:15' */
          motor = 0U;
        }
      }
      break;

     case FSAC2021_V1_Running_IN_Off_g:
      /* During 'Off': '<S159>:12' */
      if (rtu_Input == 0) {
        /* Transition: '<S159>:19' */
        localDW->bitsForTID7.is_c11_FSAC2021_V1_Running =
          FSAC2021_V1_Running_IN_ON_j;
        localDW->temporalCounter_i1 = 0U;
      }
      break;

     default:
      /* During 'On': '<S159>:15' */
      break;
    }
  }
}

/* Enable for atomic system: '<S171>/Chart1' */
void FSAC2021_V_Chart1_c_Enable(RT_MODEL_FSAC2021_V1_Running_T * const
  FSAC2021_V1_Running_M, DW_Chart1_FSAC2021_V1_Runni_n_T *localDW)
{
  localDW->presentTicks = FSAC2021_V1_Running_M->Timing.clockTick7;
  localDW->previousTicks = localDW->presentTicks;
}

/* Disable for atomic system: '<S171>/Chart1' */
void FSAC2021__Chart1_n_Disable(RT_MODEL_FSAC2021_V1_Running_T * const
  FSAC2021_V1_Running_M, DW_Chart1_FSAC2021_V1_Runni_n_T *localDW)
{
  localDW->presentTicks = FSAC2021_V1_Running_M->Timing.clockTick7;
  localDW->elapsedTicks = localDW->presentTicks - localDW->previousTicks;
  localDW->previousTicks = localDW->presentTicks;
  if (localDW->temporalCounter_i1 + localDW->elapsedTicks <= 31U) {
    localDW->temporalCounter_i1 = (uint8_T)(localDW->temporalCounter_i1 +
      localDW->elapsedTicks);
  } else {
    localDW->temporalCounter_i1 = 31U;
  }
}

/* Output and update for atomic system: '<S171>/Chart1' */
void FSAC2021_V1_Runni_Chart1_g(RT_MODEL_FSAC2021_V1_Running_T * const
  FSAC2021_V1_Running_M, real_T rtu_Input, B_Chart1_FSAC2021_V1_Runnin_d_T
  *localB, DW_Chart1_FSAC2021_V1_Runni_n_T *localDW)
{
  localDW->presentTicks = FSAC2021_V1_Running_M->Timing.clockTick7;
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
  if (localDW->bitsForTID7.is_active_c1_FSAC2021_V1_Runnin == 0U) {
    /* Entry: DIAG/DIAG/Res_Diag/Subsystem/Chart1 */
    localDW->bitsForTID7.is_active_c1_FSAC2021_V1_Runnin = 1U;

    /* Entry Internal: DIAG/DIAG/Res_Diag/Subsystem/Chart1 */
    /* Transition: '<S172>:21' */
    localDW->bitsForTID7.is_c1_FSAC2021_V1_Running =
      FSAC2021_V1_Running_IN_Normal_l;

    /* Entry 'Normal': '<S172>:13' */
    localB->Output = 0U;
  } else {
    switch (localDW->bitsForTID7.is_c1_FSAC2021_V1_Running) {
     case FSAC2021_V1_Running_IN_Normal_l:
      /* During 'Normal': '<S172>:13' */
      if (rtu_Input == 1.0) {
        /* Transition: '<S172>:16' */
        localDW->bitsForTID7.is_c1_FSAC2021_V1_Running =
          FSAC2021_V1_Running_IN_ON_n;
        localDW->temporalCounter_i1 = 0U;
      }
      break;

     case FSAC2021_V1_Running_IN_ON_n:
      /* During 'ON': '<S172>:14' */
      if (rtu_Input == 0.0) {
        /* Transition: '<S172>:17' */
        localDW->bitsForTID7.is_c1_FSAC2021_V1_Running =
          FSAC2021_V1_Running_IN_Off_c;
      } else {
        if (localDW->temporalCounter_i1 >= 20U) {
          /* Transition: '<S172>:20' */
          localDW->bitsForTID7.is_c1_FSAC2021_V1_Running =
            FSAC2021_V1_Running_IN_On_p;

          /* Entry 'On': '<S172>:15' */
          localB->Output = 1U;
        }
      }
      break;

     case FSAC2021_V1_Running_IN_Off_c:
      /* During 'Off': '<S172>:12' */
      if (rtu_Input == 1.0) {
        /* Transition: '<S172>:19' */
        localDW->bitsForTID7.is_c1_FSAC2021_V1_Running =
          FSAC2021_V1_Running_IN_ON_n;
        localDW->temporalCounter_i1 = 0U;
      }
      break;

     default:
      /* During 'On': '<S172>:15' */
      break;
    }
  }
}

/*
 * Output and update for enable system:
 *    '<S136>/Subsystem'
 *    '<S136>/Subsystem1'
 *    '<S136>/Subsystem2'
 */
void FSAC2021_V1_Runn_Subsystem(boolean_T rtu_Enable, real32_T
  rtu_Compare_Volt_mv, boolean_T *rty_TS_Error)
{
  /* Outputs for Enabled SubSystem: '<S136>/Subsystem' incorporates:
   *  EnablePort: '<S179>/Enable'
   */
  if (rtu_Enable) {
    /* RelationalOperator: '<S182>/Compare' incorporates:
     *  Constant: '<S182>/Constant'
     */
    *rty_TS_Error = (rtu_Compare_Volt_mv < 2.0F);
  }

  /* End of Outputs for SubSystem: '<S136>/Subsystem' */
}

/*
 * Output and update for action system:
 *    '<S67>/ON'
 *    '<S68>/ON'
 *    '<S69>/off'
 */
void FSAC2021_V1_Running_ON(uint8_T *rty_Out1)
{
  /* SignalConversion: '<S73>/OutportBufferForOut1' incorporates:
   *  Constant: '<S73>/Constant'
   */
  *rty_Out1 = 0U;
}

/*
 * Output and update for action system:
 *    '<S67>/OFF'
 *    '<S68>/OFF'
 */
void FSAC2021_V1_Running_OFF(uint8_T *rty_Out1)
{
  /* SignalConversion: '<S72>/OutportBufferForOut1' incorporates:
   *  Constant: '<S72>/Constant'
   */
  *rty_Out1 = 1U;
}

/*
 * Output and update for action system:
 *    '<S67>/BLINK '
 *    '<S68>/BLINK'
 */
void FSAC2021_V1_Running_BLINK(uint8_T *rty_Out1, DW_BLINK_FSAC2021_V1_Running_T
  *localDW)
{
  uint8_T rtb_DataTypeConversion_k;

  /* DataTypeConversion: '<S71>/Data Type Conversion' incorporates:
   *  Logic: '<S71>/Logical Operator'
   *  UnitDelay: '<S71>/Unit Delay'
   */
  rtb_DataTypeConversion_k = (uint8_T)!(localDW->UnitDelay_DSTATE != 0);

  /* SignalConversion: '<S71>/OutportBufferForOut1' */
  *rty_Out1 = rtb_DataTypeConversion_k;

  /* Update for UnitDelay: '<S71>/Unit Delay' */
  localDW->UnitDelay_DSTATE = rtb_DataTypeConversion_k;
}

/* Output and update for atomic system: '<S62>/Light_Subsystem' */
void FSAC2021_V_Light_Subsystem(uint8_T rtu_Light_Status,
  DW_Light_Subsystem_FSAC2021_V_T *localDW)
{
  /* local block i/o variables */
  uint8_T rtb_Merge;

  /* If: '<S67>/If' */
  if (rtu_Light_Status == 0) {
    /* Outputs for IfAction SubSystem: '<S67>/ON' incorporates:
     *  ActionPort: '<S73>/Action Port'
     */
    FSAC2021_V1_Running_ON(&rtb_Merge);

    /* End of Outputs for SubSystem: '<S67>/ON' */
  } else if (rtu_Light_Status == 1) {
    /* Outputs for IfAction SubSystem: '<S67>/OFF' incorporates:
     *  ActionPort: '<S72>/Action Port'
     */
    FSAC2021_V1_Running_OFF(&rtb_Merge);

    /* End of Outputs for SubSystem: '<S67>/OFF' */
  } else {
    /* Outputs for IfAction SubSystem: '<S67>/BLINK ' incorporates:
     *  ActionPort: '<S71>/Action Port'
     */
    FSAC2021_V1_Running_BLINK(&rtb_Merge, &localDW->BLINK);

    /* End of Outputs for SubSystem: '<S67>/BLINK ' */
  }

  /* End of If: '<S67>/If' */

  /* DataTypeConversion: '<S67>/Data Type Conversion' */
  blue = rtb_Merge;
}

/* Output and update for atomic system: '<S62>/Light_Subsystem1' */
void FSAC2021__Light_Subsystem1(uint8_T rtu_Light_Status,
  B_Light_Subsystem1_FSAC2021_V_T *localB, DW_Light_Subsystem1_FSAC2021__T
  *localDW)
{
  /* local block i/o variables */
  uint8_T rtb_Merge_c;

  /* If: '<S68>/If' */
  if (rtu_Light_Status == 0) {
    /* Outputs for IfAction SubSystem: '<S68>/ON' incorporates:
     *  ActionPort: '<S76>/Action Port'
     */
    FSAC2021_V1_Running_ON(&rtb_Merge_c);

    /* End of Outputs for SubSystem: '<S68>/ON' */
  } else if (rtu_Light_Status == 1) {
    /* Outputs for IfAction SubSystem: '<S68>/OFF' incorporates:
     *  ActionPort: '<S75>/Action Port'
     */
    FSAC2021_V1_Running_OFF(&rtb_Merge_c);

    /* End of Outputs for SubSystem: '<S68>/OFF' */
  } else {
    /* Outputs for IfAction SubSystem: '<S68>/BLINK' incorporates:
     *  ActionPort: '<S74>/Action Port'
     */
    FSAC2021_V1_Running_BLINK(&rtb_Merge_c, &localDW->BLINK);

    /* End of Outputs for SubSystem: '<S68>/BLINK' */
  }

  /* End of If: '<S68>/If' */

  /* DataTypeConversion: '<S68>/Data Type Conversion' */
  localB->DataTypeConversion = rtb_Merge_c;
}

/* Disable for atomic system: '<S62>/Light_Subsystem2' */
void F_Light_Subsystem2_Disable(RT_MODEL_FSAC2021_V1_Running_T * const
  FSAC2021_V1_Running_M, DW_Light_Subsystem2_FSAC2021__T *localDW)
{
  /* Disable for If: '<S69>/If' */
  switch (localDW->If_ActiveSubsystem) {
   case 0:
    break;

   case 1:
    /* Disable for Chart: '<S78>/Chart' */
    localDW->presentTicks_p = FSAC2021_V1_Running_M->Timing.clockTick8;
    localDW->elapsedTicks_n = localDW->presentTicks_p - localDW->previousTicks_j;
    localDW->previousTicks_j = localDW->presentTicks_p;
    if (localDW->temporalCounter_i1_n + localDW->elapsedTicks_n <= 15U) {
      localDW->temporalCounter_i1_n = (uint8_T)(localDW->temporalCounter_i1_n +
        localDW->elapsedTicks_n);
    } else {
      localDW->temporalCounter_i1_n = 15U;
    }

    /* End of Disable for Chart: '<S78>/Chart' */
    break;

   case 2:
    /* Disable for Chart: '<S77>/Chart' */
    localDW->presentTicks = FSAC2021_V1_Running_M->Timing.clockTick8;
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

    /* End of Disable for Chart: '<S77>/Chart' */
    break;
  }

  localDW->If_ActiveSubsystem = -1;

  /* End of Disable for If: '<S69>/If' */
}

/* Start for atomic system: '<S62>/Light_Subsystem2' */
void FSA_Light_Subsystem2_Start(DW_Light_Subsystem2_FSAC2021__T *localDW)
{
  /* Start for If: '<S69>/If' */
  localDW->If_ActiveSubsystem = -1;
}

/* Output and update for atomic system: '<S62>/Light_Subsystem2' */
void FSAC2021__Light_Subsystem2(RT_MODEL_FSAC2021_V1_Running_T * const
  FSAC2021_V1_Running_M, uint8_T rtu_Buzzer_Flag,
  B_Light_Subsystem2_FSAC2021_V_T *localB, DW_Light_Subsystem2_FSAC2021__T
  *localDW)
{
  /* local block i/o variables */
  uint8_T rtb_Merge_l;
  int8_T rtPrevAction;
  int8_T rtAction;

  /* If: '<S69>/If' */
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
      /* Disable for Chart: '<S78>/Chart' */
      localDW->presentTicks_p = FSAC2021_V1_Running_M->Timing.clockTick8;
      localDW->elapsedTicks_n = localDW->presentTicks_p -
        localDW->previousTicks_j;
      localDW->previousTicks_j = localDW->presentTicks_p;
      if (localDW->temporalCounter_i1_n + localDW->elapsedTicks_n <= 15U) {
        localDW->temporalCounter_i1_n = (uint8_T)(localDW->temporalCounter_i1_n
          + localDW->elapsedTicks_n);
      } else {
        localDW->temporalCounter_i1_n = 15U;
      }

      /* End of Disable for Chart: '<S78>/Chart' */
      break;

     case 2:
      /* Disable for Chart: '<S77>/Chart' */
      localDW->presentTicks = FSAC2021_V1_Running_M->Timing.clockTick8;
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

      /* End of Disable for Chart: '<S77>/Chart' */
      break;
    }
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S69>/off' incorporates:
     *  ActionPort: '<S79>/Action Port'
     */
    FSAC2021_V1_Running_ON(&rtb_Merge_l);

    /* End of Outputs for SubSystem: '<S69>/off' */
    break;

   case 1:
    if (rtAction != rtPrevAction) {
      /* Enable for IfAction SubSystem: '<S69>/Start_Horn' incorporates:
       *  Enable for ActionPort: '<S78>/Action Port'
       */
      /* Enable for If: '<S69>/If' incorporates:
       *  Enable for Chart: '<S78>/Chart'
       */
      localDW->presentTicks_p = FSAC2021_V1_Running_M->Timing.clockTick8;
      localDW->previousTicks_j = localDW->presentTicks_p;

      /* End of Enable for SubSystem: '<S69>/Start_Horn' */
    }

    /* Outputs for IfAction SubSystem: '<S69>/Start_Horn' incorporates:
     *  ActionPort: '<S78>/Action Port'
     */
    /* Chart: '<S78>/Chart' */
    localDW->presentTicks_p = FSAC2021_V1_Running_M->Timing.clockTick8;
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
    if (localDW->bitsForTID8.is_active_c7_FSAC2021_V1_Runnin == 0U) {
      /* Entry: Controller/200ms_Duty/Light_Subsystem2/Start_Horn/Chart */
      localDW->bitsForTID8.is_active_c7_FSAC2021_V1_Runnin = 1U;

      /* Entry Internal: Controller/200ms_Duty/Light_Subsystem2/Start_Horn/Chart */
      /* Transition: '<S81>:2' */
      localDW->bitsForTID8.is_c7_FSAC2021_V1_Running =
        FSAC2021_V1_Ru_IN_Start_Horn_ON;
      localDW->temporalCounter_i1_n = 0U;

      /* Entry 'Start_Horn_ON': '<S81>:3' */
      localB->Buzzer_Pin_o = 1U;
    } else if ((localDW->bitsForTID8.is_c7_FSAC2021_V1_Running !=
                FSAC2021_V1_R_IN_Start_Horn_OFF) &&
               (localDW->temporalCounter_i1_n >= 10U)) {
      /* During 'Start_Horn_ON': '<S81>:3' */
      /* Transition: '<S81>:8' */
      localDW->bitsForTID8.is_c7_FSAC2021_V1_Running =
        FSAC2021_V1_R_IN_Start_Horn_OFF;

      /* Entry 'Start_Horn_OFF': '<S81>:1' */
      localB->Buzzer_Pin_o = 0U;
    } else {
      /* During 'Start_Horn_OFF': '<S81>:1' */
    }

    /* End of Chart: '<S78>/Chart' */

    /* SignalConversion: '<S78>/OutportBufferForOut1' */
    rtb_Merge_l = localB->Buzzer_Pin_o;

    /* End of Outputs for SubSystem: '<S69>/Start_Horn' */
    break;

   case 2:
    if (rtAction != rtPrevAction) {
      /* Enable for IfAction SubSystem: '<S69>/EBS_Horn' incorporates:
       *  Enable for ActionPort: '<S77>/Action Port'
       */
      /* Enable for If: '<S69>/If' incorporates:
       *  Enable for Chart: '<S77>/Chart'
       */
      localDW->presentTicks = FSAC2021_V1_Running_M->Timing.clockTick8;
      localDW->previousTicks = localDW->presentTicks;

      /* End of Enable for SubSystem: '<S69>/EBS_Horn' */
    }

    /* Outputs for IfAction SubSystem: '<S69>/EBS_Horn' incorporates:
     *  ActionPort: '<S77>/Action Port'
     */
    /* Chart: '<S77>/Chart' */
    localDW->presentTicks = FSAC2021_V1_Running_M->Timing.clockTick8;
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
    if (localDW->bitsForTID8.is_active_c8_FSAC2021_V1_Runnin == 0U) {
      /* Entry: Controller/200ms_Duty/Light_Subsystem2/EBS_Horn/Chart */
      localDW->bitsForTID8.is_active_c8_FSAC2021_V1_Runnin = 1U;

      /* Entry Internal: Controller/200ms_Duty/Light_Subsystem2/EBS_Horn/Chart */
      /* Transition: '<S80>:16' */
      localDW->bitsForTID8.is_c8_FSAC2021_V1_Running =
        FSAC2021_V1_Running_IN_Horn;
      localDW->temporalCounter_i2 = 0U;

      /* Entry Internal 'Horn': '<S80>:14' */
      /* Transition: '<S80>:2' */
      localDW->bitsForTID8.is_Horn = FSAC2021_V1_Runn_IN_EBS_Horn_ON;
      localDW->temporalCounter_i1 = 0U;

      /* Entry 'EBS_Horn_ON': '<S80>:3' */
      localB->Buzzer_Pin = 1U;
    } else if (localDW->bitsForTID8.is_c8_FSAC2021_V1_Running !=
               FSAC2021_V1_Run_IN_EBS_Horn_OFF) {
      /* During 'Horn': '<S80>:14' */
      if (localDW->temporalCounter_i2 >= 45U) {
        /* Transition: '<S80>:15' */
        /* Exit Internal 'Horn': '<S80>:14' */
        localDW->bitsForTID8.is_Horn = FSAC2021_V_IN_NO_ACTIVE_CHILD_n;
        localDW->bitsForTID8.is_c8_FSAC2021_V1_Running =
          FSAC2021_V1_Run_IN_EBS_Horn_OFF;

        /* Entry 'EBS_Horn_OFF': '<S80>:1' */
        localB->Buzzer_Pin = 0U;
        localB->Buzzer_Overflag = 1U;
      } else if (localDW->bitsForTID8.is_Horn == FSAC2021_V1_Runn_IN_EBS_Horn_ON)
      {
        /* During 'EBS_Horn_ON': '<S80>:3' */
        if (localDW->temporalCounter_i1 >= 1U) {
          /* Transition: '<S80>:12' */
          localDW->bitsForTID8.is_Horn = FSAC2021_V1_Run_IN_EBS_Horn_ON1;
          localDW->temporalCounter_i1 = 0U;

          /* Entry 'EBS_Horn_ON1': '<S80>:11' */
          localB->Buzzer_Pin = 0U;
        }
      } else {
        /* During 'EBS_Horn_ON1': '<S80>:11' */
        if (localDW->temporalCounter_i1 >= 1U) {
          /* Transition: '<S80>:13' */
          localDW->bitsForTID8.is_Horn = FSAC2021_V1_Runn_IN_EBS_Horn_ON;
          localDW->temporalCounter_i1 = 0U;

          /* Entry 'EBS_Horn_ON': '<S80>:3' */
          localB->Buzzer_Pin = 1U;
        }
      }
    } else {
      /* During 'EBS_Horn_OFF': '<S80>:1' */
    }

    /* End of Chart: '<S77>/Chart' */

    /* SignalConversion: '<S77>/OutportBufferForBuzzer_Pin' */
    rtb_Merge_l = localB->Buzzer_Pin;

    /* End of Outputs for SubSystem: '<S69>/EBS_Horn' */
    break;
  }

  /* End of If: '<S69>/If' */

  /* DataTypeConversion: '<S69>/Data Type Conversion' */
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
void FSAC2021_V1_Running_step0(void)   /* Sample time: [0.0005s, 0.0s] */
{
  {                                    /* Sample time: [0.0005s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void FSAC2021_V1_Running_step1(void)   /* Sample time: [0.001s, 0.0s] */
{
  /* RateTransition: '<S3>/RateTransition22' */
  if (FSAC2021_V1_Running_M->Timing.RateInteraction.TID1_7) {
    FSAC2021_V1_Running_B.RateTransition22 = 0U;
  }

  /* End of RateTransition: '<S3>/RateTransition22' */
  /* S-Function (fcncallgen): '<S382>/Function-Call Generator' incorporates:
   *  SubSystem: '<S382>/CCPBackground'
   */

  /* S-Function (ec55xx_ccpslb): '<S396>/CCPBackground' */
  ccpBackground();
}

/* Model step function for TID2 */
void FSAC2021_V1_Running_step2(void)   /* Sample time: [0.005s, 0.0s] */
{
  /* S-Function (fcncallgen): '<S379>/5ms' incorporates:
   *  SubSystem: '<S379>/daq5ms'
   */

  /* S-Function (ec55xx_ccpslb1): '<S393>/CCPDAQ' */
  ccpDaq(0);
}

/* Model step function for TID3 */
void FSAC2021_V1_Running_step3(void)   /* Sample time: [0.01s, 0.0s] */
{
  /* S-Function (ec55xx_cantransmitslb): '<S11>/CANTransmit6' */

  /*Transmit CAN message*/
  {
    uint8 CAN0BUF59TX[2];
    uint8 can0buf59looptx= 0;
    CAN0BUF59TX[can0buf59looptx]=
      FSAC2021_V1_Running_ConstB.status_reg_addr_start_Con_k;
    can0buf59looptx++;
    CAN0BUF59TX[can0buf59looptx]=
      FSAC2021_V1_Running_ConstB.status_reg_num_Convert;
    can0buf59looptx++;
    Read_BCU= ec_can_transmit(0, 59, 0, 382U, 2, CAN0BUF59TX);
  }

  /* RateTransition: '<S2>/Rate Transition41' */
  FSAC2021_V1_Running_B.RateTransition41 =
    FSAC2021_V1_Running_DW.RateTransition41_Buffer0;

  /* RateTransition: '<S5>/Rate Transition15' */
  FSAC2021_V1_Running_B.RateTransition15 =
    FSAC2021_V1_Running_DW.RateTransition15_Buffer0;

  /* S-Function (ec55xx_canreceiveslb): '<S401>/Steer_Sensor' */

  /* Receive CAN message */
  {
    uint8 CAN0BUF38RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can0buf38looprx= 0;
    FSAC2021_V1_Running_B.Steer_Sensor_o3= 485;
    FSAC2021_V1_Running_B.Steer_Sensor_o5= 8;
    strsr_node= ec_can_receive(0,38, CAN0BUF38RX);
    FSAC2021_V1_Running_B.Steer_Sensor_o4[0]= CAN0BUF38RX[can0buf38looprx];
    can0buf38looprx++;
    FSAC2021_V1_Running_B.Steer_Sensor_o4[1]= CAN0BUF38RX[can0buf38looprx];
    can0buf38looprx++;
    FSAC2021_V1_Running_B.Steer_Sensor_o4[2]= CAN0BUF38RX[can0buf38looprx];
    can0buf38looprx++;
    FSAC2021_V1_Running_B.Steer_Sensor_o4[3]= CAN0BUF38RX[can0buf38looprx];
    can0buf38looprx++;
    FSAC2021_V1_Running_B.Steer_Sensor_o4[4]= CAN0BUF38RX[can0buf38looprx];
    can0buf38looprx++;
    FSAC2021_V1_Running_B.Steer_Sensor_o4[5]= CAN0BUF38RX[can0buf38looprx];
    can0buf38looprx++;
    FSAC2021_V1_Running_B.Steer_Sensor_o4[6]= CAN0BUF38RX[can0buf38looprx];
    can0buf38looprx++;
    FSAC2021_V1_Running_B.Steer_Sensor_o4[7]= CAN0BUF38RX[can0buf38looprx];
    can0buf38looprx++;
  }

  /* Call the system: <S401>/STEER_SENSOR_INFO1 */

  /* Output and update for function-call system: '<S401>/STEER_SENSOR_INFO1' */
  {
    int32_T rtb_Str_Sensor_Curr_Angle_L;
    real32_T u0;

    /* S-Function (sfix_bitop): '<S426>/Str_Sensor_Curr_Angle_L' incorporates:
     *  Constant: '<S426>/Str_Sensor_Curr_Angleinput2_C'
     *  Product: '<S426>/Str_Sensor_Curr_Angleinput2_P'
     *  Sum: '<S426>/Str_Sensor_Curr_Angleinput2_Ad'
     */
    rtb_Str_Sensor_Curr_Angle_L = (FSAC2021_V1_Running_B.Steer_Sensor_o4[1] << 8)
      + FSAC2021_V1_Running_B.Steer_Sensor_o4[2];

    /* Switch: '<S426>/Str_Sensor_Curr_AngleSW' incorporates:
     *  Constant: '<S426>/Str_Sensor_Curr_Angleinput2_C'
     *  DataTypeConversion: '<S426>/Str_Sensor_Curr_Anglecv'
     *  Product: '<S426>/Str_Sensor_Curr_Angleinput2_P'
     *  RelationalOperator: '<S426>/Str_Sensor_Curr_AngleROP'
     *  Sum: '<S426>/Str_Sensor_Curr_Angleinput2_Ad'
     *  Sum: '<S426>/Str_Sensor_Curr_Anglesubcon'
     *  UnaryMinus: '<S426>/Str_Sensor_Curr_AngleMinus'
     */
    if ((FSAC2021_V1_Running_B.Steer_Sensor_o4[1] << 8) +
        FSAC2021_V1_Running_B.Steer_Sensor_o4[2] >= 32768) {
      u0 = -(65536.0F - (real32_T)rtb_Str_Sensor_Curr_Angle_L);
    } else {
      u0 = (real32_T)rtb_Str_Sensor_Curr_Angle_L;
    }

    /* End of Switch: '<S426>/Str_Sensor_Curr_AngleSW' */

    /* Gain: '<S426>/Str_Sensor_Curr_Angle_F' */
    u0 *= 0.0625F;

    /* Saturate: '<S426>/Str_Sensor_Curr_Angle_sat' */
    if (u0 > 900.0F) {
      Steer_sensor_angle = 900.0F;
    } else if (u0 < -900.0F) {
      Steer_sensor_angle = -900.0F;
    } else {
      Steer_sensor_angle = u0;
    }

    /* End of Saturate: '<S426>/Str_Sensor_Curr_Angle_sat' */
  }

  /* UnitDelay: '<S9>/Unit Delay1' */
  FSAC2021_V1_Running_B.UnitDelay1 = FSAC2021_V1_Running_DW.UnitDelay1_DSTATE_l;

  /* S-Function (ec55xx_canreceiveslb): '<S401>/MOTEC_MOTION1' */

  /* Receive CAN message */
  {
    uint8 CAN0BUF41RX[3]= { 0, 0, 0 };

    uint8 can0buf41looprx= 0;
    FSAC2021_V1_Running_B.MOTEC_MOTION1_o3= 256;
    FSAC2021_V1_Running_B.MOTEC_MOTION1_o5= 3;
    FSAC2021_V1_Running_B.MOTEC_MOTION1_o2= ec_can_receive(0,41, CAN0BUF41RX);
    FSAC2021_V1_Running_B.MOTEC_MOTION1_o4[0]= CAN0BUF41RX[can0buf41looprx];
    can0buf41looprx++;
    FSAC2021_V1_Running_B.MOTEC_MOTION1_o4[1]= CAN0BUF41RX[can0buf41looprx];
    can0buf41looprx++;
    FSAC2021_V1_Running_B.MOTEC_MOTION1_o4[2]= CAN0BUF41RX[can0buf41looprx];
    can0buf41looprx++;
  }

  /* Call the system: <S401>/IPC_CMD1 */

  /* Output and update for function-call system: '<S401>/IPC_CMD1' */

  /* Saturate: '<S416>/IPC_Acc_sat' incorporates:
   *  DataTypeConversion: '<S416>/IPC_Acc_Convert'
   *  DataTypeConversion: '<S416>/IPC_Acccv'
   */
  if (FSAC2021_V1_Running_B.MOTEC_MOTION1_o4[0] > 100.0F) {
    FSAC2021_V1_Running_B.IPC_Acc_sat = 100.0F;
  } else {
    FSAC2021_V1_Running_B.IPC_Acc_sat = FSAC2021_V1_Running_B.MOTEC_MOTION1_o4[0];
  }

  /* End of Saturate: '<S416>/IPC_Acc_sat' */

  /* Saturate: '<S416>/IPC_Brk_sat' incorporates:
   *  DataTypeConversion: '<S416>/IPC_Brk_Convert'
   *  DataTypeConversion: '<S416>/IPC_Brkcv'
   */
  if (FSAC2021_V1_Running_B.MOTEC_MOTION1_o4[1] > 100.0F) {
    FSAC2021_V1_Running_B.IPC_Brk_sat = 100.0F;
  } else {
    FSAC2021_V1_Running_B.IPC_Brk_sat = FSAC2021_V1_Running_B.MOTEC_MOTION1_o4[1];
  }

  /* End of Saturate: '<S416>/IPC_Brk_sat' */

  /* Saturate: '<S416>/IPC_Steer_sat' incorporates:
   *  Constant: '<S416>/IPC_Steer_O'
   *  DataTypeConversion: '<S416>/IPC_Steer_Convert'
   *  DataTypeConversion: '<S416>/IPC_Steercv'
   *  Sum: '<S416>/IPC_Steer_Ad'
   */
  FSAC2021_V1_Running_B.IPC_Steer_sat = (real32_T)
    FSAC2021_V1_Running_B.MOTEC_MOTION1_o4[2] + -120.0F;

  /* Outputs for Enabled SubSystem: '<S401>/Subsystem' incorporates:
   *  EnablePort: '<S428>/Enable'
   */
  if (FSAC2021_V1_Running_B.MOTEC_MOTION1_o2 > 0) {
    /* DataTypeConversion: '<S428>/Data Type Conversion22' */
    FSAC2021_V1_Running_B.DataTypeConversion22 =
      FSAC2021_V1_Running_B.IPC_Steer_sat;

    /* DataTypeConversion: '<S428>/Data Type Conversion24' */
    FSAC2021_V1_Running_B.DataTypeConversion24 =
      FSAC2021_V1_Running_B.IPC_Brk_sat;

    /* DataTypeConversion: '<S428>/Data Type Conversion23' */
    FSAC2021_V1_Running_B.DataTypeConversion23 =
      FSAC2021_V1_Running_B.IPC_Acc_sat;
  }

  /* End of Outputs for SubSystem: '<S401>/Subsystem' */

  /* S-Function (ec55xx_cantransmitslb): '<S12>/CANTransmit5' */

  /*Transmit CAN message*/
  {
    uint8 CAN1BUF56TX[8];
    uint8 can1buf56looptx= 0;
    CAN1BUF56TX[can1buf56looptx]= ((uint8_T)0U);
    can1buf56looptx++;
    CAN1BUF56TX[can1buf56looptx]= ((uint8_T)0U);
    can1buf56looptx++;
    CAN1BUF56TX[can1buf56looptx]= ((uint8_T)0U);
    can1buf56looptx++;
    CAN1BUF56TX[can1buf56looptx]= ((uint8_T)0U);
    can1buf56looptx++;
    CAN1BUF56TX[can1buf56looptx]= ((uint8_T)0U);
    can1buf56looptx++;
    CAN1BUF56TX[can1buf56looptx]= ((uint8_T)0U);
    can1buf56looptx++;
    CAN1BUF56TX[can1buf56looptx]= ((uint8_T)0U);
    can1buf56looptx++;
    CAN1BUF56TX[can1buf56looptx]= ((uint8_T)0U);
    can1buf56looptx++;
    FSAC2021_V1_Running_B.CANTransmit5= ec_can_transmit(1, 56, 1, 2181107875U, 8,
      CAN1BUF56TX);
  }

  /* S-Function (ec55xx_canreceiveslb): '<S401>/BCU_MTR_STATUS' */

  /* Receive CAN message */
  {
    uint8 CAN0BUF21RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can0buf21looprx= 0;
    FSAC2021_V1_Running_B.BCU_MTR_STATUS_o3= 257;
    FSAC2021_V1_Running_B.BCU_MTR_STATUS_o5= 8;
    brake_node= ec_can_receive(0,21, CAN0BUF21RX);
    FSAC2021_V1_Running_B.BCU_MTR_STATUS_o4[0]= CAN0BUF21RX[can0buf21looprx];
    can0buf21looprx++;
    FSAC2021_V1_Running_B.BCU_MTR_STATUS_o4[1]= CAN0BUF21RX[can0buf21looprx];
    can0buf21looprx++;
    FSAC2021_V1_Running_B.BCU_MTR_STATUS_o4[2]= CAN0BUF21RX[can0buf21looprx];
    can0buf21looprx++;
    FSAC2021_V1_Running_B.BCU_MTR_STATUS_o4[3]= CAN0BUF21RX[can0buf21looprx];
    can0buf21looprx++;
    FSAC2021_V1_Running_B.BCU_MTR_STATUS_o4[4]= CAN0BUF21RX[can0buf21looprx];
    can0buf21looprx++;
    FSAC2021_V1_Running_B.BCU_MTR_STATUS_o4[5]= CAN0BUF21RX[can0buf21looprx];
    can0buf21looprx++;
    FSAC2021_V1_Running_B.BCU_MTR_STATUS_o4[6]= CAN0BUF21RX[can0buf21looprx];
    can0buf21looprx++;
    FSAC2021_V1_Running_B.BCU_MTR_STATUS_o4[7]= CAN0BUF21RX[can0buf21looprx];
    can0buf21looprx++;
  }

  /* Call the system: <S401>/BCU_MTR_STATUS1 */

  /* Output and update for function-call system: '<S401>/BCU_MTR_STATUS1' */

  /* Saturate: '<S414>/Brake_cmd_fault_flag_sat' incorporates:
   *  ArithShift: '<S414>/Brake_cmd_fault_flag_S'
   *  DataTypeConversion: '<S414>/Brake_cmd_fault_flag_Convert'
   *  DataTypeConversion: '<S414>/Brake_cmd_fault_flagcv'
   *  S-Function (sfix_bitop): '<S414>/Brake_cmd_fault_flag_L'
   */
  FSAC2021_V1_Running_B.Brake_cmd_fault_flag_sat = (real32_T)(int32_T)
    ((FSAC2021_V1_Running_B.BCU_MTR_STATUS_o4[6] & 2U) >> 1);

  /* Saturate: '<S414>/Brake_encoder_fault_sts_sat' incorporates:
   *  DataTypeConversion: '<S414>/Brake_encoder_fault_sts_Convert'
   *  DataTypeConversion: '<S414>/Brake_encoder_fault_stscv'
   *  S-Function (sfix_bitop): '<S414>/Brake_encoder_fault_sts_L'
   */
  FSAC2021_V1_Running_B.Brake_encoder_fault_sts_sat = (real32_T)
    (FSAC2021_V1_Running_B.BCU_MTR_STATUS_o4[4] & 1);

  /* Saturate: '<S414>/Brake_hd_fault_sts_sat' incorporates:
   *  ArithShift: '<S414>/Brake_hd_fault_sts_S'
   *  DataTypeConversion: '<S414>/Brake_hd_fault_sts_Convert'
   *  DataTypeConversion: '<S414>/Brake_hd_fault_stscv'
   *  S-Function (sfix_bitop): '<S414>/Brake_hd_fault_sts_L'
   */
  FSAC2021_V1_Running_B.Brake_hd_fault_sts_sat = (real32_T)(int32_T)
    ((FSAC2021_V1_Running_B.BCU_MTR_STATUS_o4[7] & 64U) >> 6);

  /* Saturate: '<S414>/Brake_lowvolt_prtct_sts_sat' incorporates:
   *  ArithShift: '<S414>/Brake_lowvolt_prtct_sts_S'
   *  DataTypeConversion: '<S414>/Brake_lowvolt_prtct_sts_Convert'
   *  DataTypeConversion: '<S414>/Brake_lowvolt_prtct_stscv'
   *  S-Function (sfix_bitop): '<S414>/Brake_lowvolt_prtct_sts_L'
   */
  FSAC2021_V1_Running_B.Brake_lowvolt_prtct_sts_sat = (real32_T)(int32_T)
    ((FSAC2021_V1_Running_B.BCU_MTR_STATUS_o4[5] & 64U) >> 6);

  /* Saturate: '<S414>/Brake_mtr_enable_flag_sat' incorporates:
   *  ArithShift: '<S414>/Brake_mtr_enable_flag_S'
   *  DataTypeConversion: '<S414>/Brake_mtr_enable_flag_Convert'
   *  DataTypeConversion: '<S414>/Brake_mtr_enable_flagcv'
   *  S-Function (sfix_bitop): '<S414>/Brake_mtr_enable_flag_L'
   */
  FSAC2021_V1_Running_B.Brake_mtr_enable_flag_sat = (real32_T)(int32_T)
    ((FSAC2021_V1_Running_B.BCU_MTR_STATUS_o4[6] & 32U) >> 5);

  /* Saturate: '<S414>/Brake_overcurrt_prtct_sts_sat' incorporates:
   *  ArithShift: '<S414>/Brake_overcurrt_prtct_sts_S'
   *  DataTypeConversion: '<S414>/Brake_overcurrt_prtct_sts_Convert'
   *  DataTypeConversion: '<S414>/Brake_overcurrt_prtct_stscv'
   *  S-Function (sfix_bitop): '<S414>/Brake_overcurrt_prtct_sts_L'
   */
  FSAC2021_V1_Running_B.Brake_overcurrt_prtct_sts_sat = (real32_T)(int32_T)
    ((FSAC2021_V1_Running_B.BCU_MTR_STATUS_o4[5] & 32U) >> 5);

  /* Saturate: '<S414>/Brake_overheat_prtct_sts_sat' incorporates:
   *  ArithShift: '<S414>/Brake_overheat_prtct_sts_S'
   *  DataTypeConversion: '<S414>/Brake_overheat_prtct_sts_Convert'
   *  DataTypeConversion: '<S414>/Brake_overheat_prtct_stscv'
   *  S-Function (sfix_bitop): '<S414>/Brake_overheat_prtct_sts_L'
   */
  FSAC2021_V1_Running_B.Brake_overheat_prtct_sts_sat = (real32_T)(int32_T)
    ((FSAC2021_V1_Running_B.BCU_MTR_STATUS_o4[5] & 16U) >> 4);

  /* Saturate: '<S414>/Brake_reg_rw_fault_flag_sat' incorporates:
   *  ArithShift: '<S414>/Brake_reg_rw_fault_flag_S'
   *  DataTypeConversion: '<S414>/Brake_reg_rw_fault_flag_Convert'
   *  DataTypeConversion: '<S414>/Brake_reg_rw_fault_flagcv'
   *  S-Function (sfix_bitop): '<S414>/Brake_reg_rw_fault_flag_L'
   */
  FSAC2021_V1_Running_B.Brake_reg_rw_fault_flag_sat = (real32_T)(int32_T)
    ((FSAC2021_V1_Running_B.BCU_MTR_STATUS_o4[6] & 4U) >> 2);

  /* DataTypeConversion: '<S401>/Data Type Conversion10' */
  FSAC2021_V1_Running_B.DataTypeConversion10 =
    FSAC2021_V1_Running_B.Brake_reg_rw_fault_flag_sat;

  /* DataTypeConversion: '<S401>/Data Type Conversion11' */
  FSAC2021_V1_Running_B.DataTypeConversion11 =
    FSAC2021_V1_Running_B.Brake_overheat_prtct_sts_sat;

  /* DataTypeConversion: '<S401>/Data Type Conversion12' */
  FSAC2021_V1_Running_B.DataTypeConversion12 =
    FSAC2021_V1_Running_B.Brake_overcurrt_prtct_sts_sat;

  /* DataTypeConversion: '<S401>/Data Type Conversion17' */
  FSAC2021_V1_Running_B.DataTypeConversion17 =
    FSAC2021_V1_Running_B.Brake_lowvolt_prtct_sts_sat;

  /* DataTypeConversion: '<S401>/Data Type Conversion18' */
  FSAC2021_V1_Running_B.DataTypeConversion18 =
    FSAC2021_V1_Running_B.Brake_hd_fault_sts_sat;

  /* DataTypeConversion: '<S401>/Data Type Conversion20' */
  FSAC2021_V1_Running_B.DataTypeConversion20 =
    FSAC2021_V1_Running_B.Brake_encoder_fault_sts_sat;

  /* DataTypeConversion: '<S401>/Data Type Conversion21' */
  FSAC2021_V1_Running_B.DataTypeConversion21 =
    FSAC2021_V1_Running_B.Brake_cmd_fault_flag_sat;

  /* RateTransition: '<S3>/RateTransition24' */
  if (FSAC2021_V1_Running_M->Timing.RateInteraction.TID3_7) {
    FSAC2021_V1_Running_B.RateTransition24 =
      FSAC2021_V1_Running_B.RateTransition41;
  }

  /* End of RateTransition: '<S3>/RateTransition24' */

  /* S-Function (ec55xx_canreceiveslb): '<S401>/MOTEC_MOTION2' */

  /* Receive CAN message */
  {
    uint8 CAN0BUF35RX[1]= { 0 };

    uint8 can0buf35looprx= 0;
    FSAC2021_V1_Running_B.MOTEC_MOTION2_o3= 279;
    FSAC2021_V1_Running_B.MOTEC_MOTION2_o5= 1;
    RES__ok= ec_can_receive(0,35, CAN0BUF35RX);
    FSAC2021_V1_Running_B.MOTEC_MOTION2_o4= CAN0BUF35RX[can0buf35looprx];
    can0buf35looprx++;
  }

  /* Call the system: <S401>/Res_Message1 */

  /* Output and update for function-call system: '<S401>/Res_Message1' */

  /* Saturate: '<S425>/Res_Run_Status_sat' incorporates:
   *  ArithShift: '<S425>/Res_Run_Status_S'
   *  DataTypeConversion: '<S425>/Res_Run_Status_Convert'
   *  DataTypeConversion: '<S425>/Res_Run_Statuscv'
   *  S-Function (sfix_bitop): '<S425>/Res_Run_Status_L'
   */
  RES_Value = (real32_T)(int32_T)((FSAC2021_V1_Running_B.MOTEC_MOTION2_o4 & 62U)
    >> 1);

  /* RateTransition: '<S3>/RateTransition26' */
  if (FSAC2021_V1_Running_M->Timing.RateInteraction.TID3_7) {
    FSAC2021_V1_Running_B.RateTransition26 = RES_Value;
  }

  /* End of RateTransition: '<S3>/RateTransition26' */

  /* S-Function (fcncallgen): '<S379>/10ms' incorporates:
   *  SubSystem: '<S379>/daq10ms'
   */

  /* S-Function (ec55xx_ccpslb1): '<S391>/CCPDAQ' */
  ccpDaq(1);

  /* S-Function (fcncallgen): '<S381>/10ms' incorporates:
   *  SubSystem: '<S381>/10mstask'
   */

  /* S-Function (ec55xx_pdsdslb1): '<S395>/PDSD' */
  ec_tle6232_diag();

  /* Update for UnitDelay: '<S9>/Unit Delay1' incorporates:
   *  DataTypeConversion: '<S401>/Data Type Conversion16'
   */
  FSAC2021_V1_Running_DW.UnitDelay1_DSTATE_l = (uint8_T)
    FSAC2021_V1_Running_B.Brake_mtr_enable_flag_sat;
}

/* Model step function for TID4 */
void FSAC2021_V1_Running_step4(void)   /* Sample time: [0.02s, 0.0s] */
{
  /* local block i/o variables */
  real32_T rtb_Gain_n;
  uint32_T rtb_RateTransition18_l;
  uint32_T rtb_RateTransition19_d;
  uint32_T rtb_RateTransition25;
  uint32_T rtb_RateTransition26;
  uint16_T rtb_RateTransition22_m;
  uint16_T rtb_RateTransition23_e;
  uint16_T rtb_RateTransition14;
  uint16_T rtb_RateTransition24;
  real_T u0;

  /* RateTransition: '<S5>/Rate Transition18' */
  rtb_RateTransition18_l = FSAC2021_V1_Running_DW.RateTransition18_Buffer0;

  /* RateTransition: '<S5>/Rate Transition19' */
  rtb_RateTransition19_d = FSAC2021_V1_Running_DW.RateTransition19_Buffer0;

  /* RateTransition: '<S5>/Rate Transition25' */
  rtb_RateTransition25 = FSAC2021_V1_Running_DW.RateTransition25_Buffer0;

  /* RateTransition: '<S5>/Rate Transition26' */
  rtb_RateTransition26 = FSAC2021_V1_Running_DW.RateTransition26_Buffer0;

  /* RateTransition: '<S5>/Rate Transition22' */
  rtb_RateTransition22_m = FSAC2021_V1_Running_DW.RateTransition22_Buffer0;

  /* RateTransition: '<S5>/Rate Transition23' */
  rtb_RateTransition23_e = FSAC2021_V1_Running_DW.RateTransition23_Buffer0;

  /* RateTransition: '<S5>/Rate Transition14' */
  rtb_RateTransition14 = FSAC2021_V1_Running_DW.RateTransition14_Buffer0;

  /* RateTransition: '<S5>/Rate Transition24' */
  rtb_RateTransition24 = FSAC2021_V1_Running_DW.RateTransition24_Buffer0;

  /* S-Function (fcncallgen): '<S8>/Function-Call Generator' incorporates:
   *  SubSystem: '<S5>/KL_Sig_Process'
   */

  /* Outputs for Atomic SubSystem: '<S196>/Whl_Spd_Hz2RPM' */
  FSAC2021_V1_Whl_Spd_Hz2RPM(rtb_RateTransition18_l,
    &FSAC2021_V1_Running_B.Whl_Spd_Hz2RPM);

  /* End of Outputs for SubSystem: '<S196>/Whl_Spd_Hz2RPM' */

  /* Outputs for Atomic SubSystem: '<S196>/LPF' */
  FSAC2021_V1_Running_LPF(FSAC2021_V1_Running_B.Whl_Spd_Hz2RPM.rps2rpm,
    &FSAC2021_V1_Running_B.LPF, &FSAC2021_V1_Running_DW.LPF);

  /* End of Outputs for SubSystem: '<S196>/LPF' */

  /* Outputs for Atomic SubSystem: '<S196>/Whl_Spd_Hz2RPM1' */
  FSAC2021_V1_Whl_Spd_Hz2RPM(rtb_RateTransition19_d,
    &FSAC2021_V1_Running_B.Whl_Spd_Hz2RPM1);

  /* End of Outputs for SubSystem: '<S196>/Whl_Spd_Hz2RPM1' */

  /* Outputs for Atomic SubSystem: '<S196>/LPF1' */
  FSAC2021_V1_Running_LPF(FSAC2021_V1_Running_B.Whl_Spd_Hz2RPM1.rps2rpm,
    &FSAC2021_V1_Running_B.LPF1, &FSAC2021_V1_Running_DW.LPF1);

  /* End of Outputs for SubSystem: '<S196>/LPF1' */

  /* Outputs for Atomic SubSystem: '<S196>/Whl_Spd_Hz2RPM2' */
  FSAC2021_V_Whl_Spd_Hz2RPM2(rtb_RateTransition25,
    &FSAC2021_V1_Running_B.Whl_Spd_Hz2RPM2);

  /* End of Outputs for SubSystem: '<S196>/Whl_Spd_Hz2RPM2' */

  /* Outputs for Atomic SubSystem: '<S196>/LPF2' */
  FSAC2021_V1_Running_LPF(FSAC2021_V1_Running_B.Whl_Spd_Hz2RPM2.rps2rpm,
    &FSAC2021_V1_Running_B.LPF2, &FSAC2021_V1_Running_DW.LPF2);

  /* End of Outputs for SubSystem: '<S196>/LPF2' */

  /* Outputs for Atomic SubSystem: '<S196>/Whl_Spd_Hz2RPM3' */
  FSAC2021_V_Whl_Spd_Hz2RPM2(rtb_RateTransition26,
    &FSAC2021_V1_Running_B.Whl_Spd_Hz2RPM3);

  /* End of Outputs for SubSystem: '<S196>/Whl_Spd_Hz2RPM3' */

  /* Outputs for Atomic SubSystem: '<S196>/LPF3' */
  FSAC2021_V1_Running_LPF(FSAC2021_V1_Running_B.Whl_Spd_Hz2RPM3.rps2rpm,
    &FSAC2021_V1_Running_B.LPF3, &FSAC2021_V1_Running_DW.LPF3);

  /* End of Outputs for SubSystem: '<S196>/LPF3' */

  /* Gain: '<S209>/Gain' incorporates:
   *  Gain: '<S208>/Gain6'
   *  Sum: '<S208>/Add3'
   */
  rtb_Gain_n = (((FSAC2021_V1_Running_B.LPF.Add1 +
                  FSAC2021_V1_Running_B.LPF1.Add1) +
                 FSAC2021_V1_Running_B.LPF2.Add1) +
                FSAC2021_V1_Running_B.LPF3.Add1) * 0.25F * 0.0882159248F;

  /* Outputs for Atomic SubSystem: '<S202>/Round' */
  FSAC2021_V1_Running_Round(rtb_Gain_n);

  /* End of Outputs for SubSystem: '<S202>/Round' */

  /* Sum: '<S195>/Add1' incorporates:
   *  Constant: '<S195>/Acc_Right_Offset'
   *  Constant: '<S195>/Constant1'
   *  Product: '<S195>/Divide1'
   */
  u0 = (real_T)rtb_RateTransition22_m * -0.08333 + 408.33;

  /* Saturate: '<S195>/Saturation1' */
  if (u0 > 100.0) {
    u0 = 100.0;
  } else {
    if (u0 < 0.0) {
      u0 = 0.0;
    }
  }

  /* Saturate: '<S195>/Saturation2' incorporates:
   *  Gain: '<S195>/Gain'
   *  Saturate: '<S195>/Saturation1'
   */
  FSAC2021_V1_Running_B.Saturation2 = 15.0 * u0;

  /* Sum: '<S195>/Add3' incorporates:
   *  Constant: '<S195>/Brk_Liquid_Prs_Factor'
   *  Product: '<S195>/Divide3'
   */
  FSAC2021_V1_Running_B.Add3 = (real_T)rtb_RateTransition23_e * 0.001;

  /* Sum: '<S195>/Add4' incorporates:
   *  Constant: '<S195>/EBS_GAS_Prs_1_Factor'
   *  Product: '<S195>/Divide4'
   */
  FSAC2021_V1_Running_B.Add4 = (real_T)rtb_RateTransition14 * 0.000303;

  /* Sum: '<S195>/Add5' incorporates:
   *  Constant: '<S195>/EBS_GAS_Prs_2_Factor'
   *  Product: '<S195>/Divide5'
   */
  FSAC2021_V1_Running_B.Add5 = (real_T)rtb_RateTransition24 * 0.000303;

  /* Update for RateTransition: '<S5>/Rate Transition15' */
  FSAC2021_V1_Running_DW.RateTransition15_Buffer0 = Vel_spd;
}

/* Model step function for TID5 */
void FSAC2021_V1_Running_step5(void)   /* Sample time: [0.03s, 0.0s] */
{
  int32_T rtb_Battery_Volt_L;
  real_T rtb_RateTransition10;
  real32_T rtb_RateTransition13;
  uint8_T rtb_RateTransition14_o;
  real32_T rtb_RateTransition16;

  /* UnitDelay: '<S1>/Unit Delay6' */
  Vspd = FSAC2021_V1_Running_DW.UnitDelay6_DSTATE_p;

  /* Saturate: '<S33>/vspd_sat' */
  if (Vspd > 255.0F) {
    rtb_RateTransition13 = 255.0F;
  } else if (Vspd < 0.0F) {
    rtb_RateTransition13 = 0.0F;
  } else {
    rtb_RateTransition13 = Vspd;
  }

  /* DataTypeConversion: '<S33>/vspd_Convert' incorporates:
   *  DataTypeConversion: '<S33>/vspd_Convert1'
   *  Rounding: '<S33>/vspdRon'
   *  S-Function (sfix_bitop): '<S33>/vspd_L'
   *  Saturate: '<S33>/vspd_1sat'
   *  Saturate: '<S33>/vspd_sat'
   */
  FSAC2021_V1_Running_B.vspd_Convert = (uint8_T)((uint32_T)rt_roundf_snf
    (rtb_RateTransition13) & 255U);

  /* UnitDelay: '<S1>/Unit Delay1' */
  Motor_Spd = FSAC2021_V1_Running_DW.UnitDelay1_DSTATE;

  /* Saturate: '<S32>/mtr_rpm_sat' */
  if (Motor_Spd > 65535.0F) {
    rtb_RateTransition13 = 65535.0F;
  } else if (Motor_Spd < 0.0F) {
    rtb_RateTransition13 = 0.0F;
  } else {
    rtb_RateTransition13 = Motor_Spd;
  }

  /* S-Function (sfix_bitop): '<S32>/mtr_rpm_L' incorporates:
   *  DataTypeConversion: '<S32>/mtr_rpm_Convert'
   *  Rounding: '<S32>/mtr_rpmRon'
   *  Saturate: '<S32>/mtr_rpm_1sat'
   *  Saturate: '<S32>/mtr_rpm_sat'
   */
  rtb_Battery_Volt_L = (int32_T)((uint32_T)rt_roundf_snf(rtb_RateTransition13) &
    65535U);

  /* DataTypeConversion: '<S32>/mtr_rpmCOV' incorporates:
   *  Constant: '<S32>/mtr_rpmoutput2_C'
   *  Product: '<S32>/mtr_rpm_D1'
   */
  FSAC2021_V1_Running_B.mtr_rpmCOV = (uint8_T)((real_T)rtb_Battery_Volt_L /
    256.0);

  /* DataTypeConversion: '<S32>/mtr_rpmBitCov' incorporates:
   *  Constant: '<S32>/mtr_rpm_And_C'
   *  S-Function (sfix_bitop): '<S32>/mtr_rpm_And'
   */
  FSAC2021_V1_Running_B.mtr_rpmBitCov = (uint8_T)(rtb_Battery_Volt_L & 255U);

  /* UnitDelay: '<S1>/Unit Delay2' */
  ASSI_state = FSAC2021_V1_Running_DW.UnitDelay2_DSTATE;

  /* DataTypeConversion: '<S31>/assi_status_Convert' incorporates:
   *  Rounding: '<S31>/assi_statusRon'
   *  Saturate: '<S31>/assi_status_1sat'
   *  Sum: '<S31>/assi_status_st'
   */
  FSAC2021_V1_Running_B.assi_status_Convert = (uint8_T)rt_roundf_snf((real32_T)
    ASSI_state);

  /* UnitDelay: '<S1>/Unit Delay5' */
  Voltage = FSAC2021_V1_Running_DW.UnitDelay5_DSTATE;

  /* Saturate: '<S30>/Battery_Volt_sat' */
  if (Voltage > 6553.5) {
    rtb_RateTransition10 = 6553.5;
  } else if (Voltage < 0.0) {
    rtb_RateTransition10 = 0.0;
  } else {
    rtb_RateTransition10 = Voltage;
  }

  /* S-Function (sfix_bitop): '<S30>/Battery_Volt_L' incorporates:
   *  DataTypeConversion: '<S30>/Battery_Volt_Convert'
   *  Product: '<S30>/Battery_Volt_D'
   *  Rounding: '<S30>/Battery_VoltRon'
   *  Saturate: '<S30>/Battery_Volt_1sat'
   *  Saturate: '<S30>/Battery_Volt_sat'
   */
  rtb_Battery_Volt_L = (int32_T)((uint32_T)rt_roundd_snf(rtb_RateTransition10 /
    0.10000000149011612) & 65535U);

  /* DataTypeConversion: '<S30>/Battery_VoltCOV' incorporates:
   *  Constant: '<S30>/Battery_Voltoutput5_C'
   *  Product: '<S30>/Battery_Volt_D1'
   */
  FSAC2021_V1_Running_B.Battery_VoltCOV = (uint8_T)((real_T)rtb_Battery_Volt_L /
    256.0);

  /* DataTypeConversion: '<S30>/Battery_VoltBitCov' incorporates:
   *  Constant: '<S30>/Battery_Volt_And_C'
   *  S-Function (sfix_bitop): '<S30>/Battery_Volt_And'
   */
  FSAC2021_V1_Running_B.Battery_VoltBitCov = (uint8_T)(rtb_Battery_Volt_L & 255U);

  /* S-Function (ec55xx_cantransmitslb): '<S11>/CANTransmit7' */

  /*Transmit CAN message*/
  {
    uint8 CAN0BUF60TX[8];
    uint8 can0buf60looptx= 0;
    CAN0BUF60TX[can0buf60looptx]= FSAC2021_V1_Running_B.vspd_Convert;
    can0buf60looptx++;
    CAN0BUF60TX[can0buf60looptx]= FSAC2021_V1_Running_B.mtr_rpmCOV;
    can0buf60looptx++;
    CAN0BUF60TX[can0buf60looptx]= FSAC2021_V1_Running_B.mtr_rpmBitCov;
    can0buf60looptx++;
    CAN0BUF60TX[can0buf60looptx]= FSAC2021_V1_Running_B.assi_status_Convert;
    can0buf60looptx++;
    CAN0BUF60TX[can0buf60looptx]= FSAC2021_V1_Running_B.Battery_VoltCOV;
    can0buf60looptx++;
    CAN0BUF60TX[can0buf60looptx]= FSAC2021_V1_Running_B.Battery_VoltBitCov;
    can0buf60looptx++;
    CAN0BUF60TX[can0buf60looptx]= ((uint8_T)0U);
    can0buf60looptx++;
    CAN0BUF60TX[can0buf60looptx]= ((uint8_T)0U);
    can0buf60looptx++;
    To_AMI_OK= ec_can_transmit(0, 60, 0, 1161U, 8, CAN0BUF60TX);
  }

  /* RateTransition: '<S1>/Rate Transition10' */
  rtb_RateTransition10 = FSAC2021_V1_Running_DW.RateTransition10_Buffer0;

  /* RateTransition: '<S1>/Rate Transition13' */
  rtb_RateTransition13 = FSAC2021_V1_Running_DW.RateTransition13_Buffer0;

  /* RateTransition: '<S1>/Rate Transition14' */
  rtb_RateTransition14_o = FSAC2021_V1_Running_B.RateTransition41;

  /* RateTransition: '<S1>/Rate Transition16' */
  rtb_RateTransition16 = FSAC2021_V1_Running_B.RateTransition15;

  /* Update for UnitDelay: '<S1>/Unit Delay6' */
  FSAC2021_V1_Running_DW.UnitDelay6_DSTATE_p = rtb_RateTransition16;

  /* Update for UnitDelay: '<S1>/Unit Delay1' */
  FSAC2021_V1_Running_DW.UnitDelay1_DSTATE = rtb_RateTransition13;

  /* Update for UnitDelay: '<S1>/Unit Delay2' */
  FSAC2021_V1_Running_DW.UnitDelay2_DSTATE = rtb_RateTransition14_o;

  /* Update for UnitDelay: '<S1>/Unit Delay5' */
  FSAC2021_V1_Running_DW.UnitDelay5_DSTATE = rtb_RateTransition10;
}

/* Model step function for TID6 */
void FSAC2021_V1_Running_step6(void)   /* Sample time: [0.05s, 0.0s] */
{
  /* local block i/o variables */
  real32_T rtb_Gain_i;
  int8_T rtb_Gain_p;
  boolean_T rtb_Equal2;
  int32_T rtb_Drive_Speed_Control_L;
  uint8_T rtb_RateTransition17_f;
  uint8_T rtb_RateTransition18_o;
  uint8_T rtb_RateTransition19_j;
  real32_T rtb_RateTransition46;
  uint8_T rtb_RateTransition59;
  uint8_T rtb_RateTransition60;
  uint8_T rtb_RateTransition57;
  real_T rtb_RateTransition4;
  real_T rtb_RateTransition3;
  real_T rtb_RateTransition5;
  real32_T rtb_RateTransition11;
  uint8_T rtb_UnitDelay5;
  uint8_T rtb_RateTransition24_e;
  boolean_T rtb_RateTransition31_j;
  boolean_T rtb_RateTransition32_e;
  boolean_T rtb_RateTransition50;
  real_T rtb_RateTransition77;
  real_T rtb_RateTransition78;
  real_T rtb_RateTransition80;
  uint8_T rtb_RateTransition47;
  uint8_T rtb_RateTransition46_e;
  real_T rtb_RateTransition6;
  uint8_T rtb_RateTransition19_i;
  int32_T rtb_DataTypeConversion13;
  int32_T rtb_DataTypeConversion14;
  int32_T rtb_DataTypeConversion16;
  uint8_T rtb_UnitDelay2;
  boolean_T LogicalOperator_p;
  boolean_T LogicalOperator_nw;

  /* UnitDelay: '<S1>/Unit Delay4' */
  ACC = FSAC2021_V1_Running_DW.UnitDelay4_DSTATE;

  /* Saturate: '<S29>/Drive_Speed_Control_sat' */
  if (ACC > 1500.0F) {
    rtb_RateTransition46 = 1500.0F;
  } else if (ACC < 0.0F) {
    rtb_RateTransition46 = 0.0F;
  } else {
    rtb_RateTransition46 = ACC;
  }

  /* S-Function (sfix_bitop): '<S29>/Drive_Speed_Control_L' incorporates:
   *  DataTypeConversion: '<S29>/Drive_Speed_Control_Convert'
   *  Rounding: '<S29>/Drive_Speed_ControlRon'
   *  Saturate: '<S29>/Drive_Speed_Control_1sat'
   *  Saturate: '<S29>/Drive_Speed_Control_sat'
   */
  rtb_Drive_Speed_Control_L = (int32_T)((uint32_T)rt_roundf_snf
    (rtb_RateTransition46) & 65535U);

  /* DataTypeConversion: '<S29>/BitCov' incorporates:
   *  Constant: '<S29>/Drive_Speed_Control_And_C'
   *  S-Function (sfix_bitop): '<S29>/Drive_Speed_Control_And'
   */
  FSAC2021_V1_Running_B.BitCov = (uint8_T)(rtb_Drive_Speed_Control_L & 255U);

  /* DataTypeConversion: '<S29>/Drive_Speed_ControlCOV' incorporates:
   *  Constant: '<S29>/Drive_Speed_Controloutput2_C'
   *  Product: '<S29>/Drive_Speed_Control_D1'
   */
  FSAC2021_V1_Running_B.Drive_Speed_ControlCOV = (uint8_T)((real_T)
    rtb_Drive_Speed_Control_L / 256.0);

  /* S-Function (ec55xx_cantransmitslb): '<S11>/CANTransmit4' */

  /*Transmit CAN message*/
  {
    uint8 CAN1BUF15TX[2];
    uint8 can1buf15looptx= 0;
    CAN1BUF15TX[can1buf15looptx]= FSAC2021_V1_Running_B.BitCov;
    can1buf15looptx++;
    CAN1BUF15TX[can1buf15looptx]= FSAC2021_V1_Running_B.Drive_Speed_ControlCOV;
    can1buf15looptx++;
    To_MOTOR_OK= ec_can_transmit(1, 15, 1, 2197885092U, 2, CAN1BUF15TX);
  }

  /* RateTransition: '<S2>/Rate Transition17' */
  rtb_RateTransition17_f = FSAC2021_V1_Running_DW.RateTransition17_Buffer0;

  /* RateTransition: '<S2>/Rate Transition18' */
  rtb_RateTransition18_o = FSAC2021_V1_Running_DW.RateTransition18_Buffer0_d;

  /* RateTransition: '<S2>/Rate Transition19' */
  rtb_RateTransition19_j = FSAC2021_V1_Running_DW.RateTransition19_Buffer0_e;

  /* UnitDelay: '<S2>/Unit Delay4' */
  FSAC2021_V1_Running_B.UnitDelay4 = FSAC2021_V1_Running_DW.UnitDelay4_DSTATE_i;

  /* RateTransition: '<S2>/Rate Transition46' */
  rtb_RateTransition46 = Steer_sensor_angle;

  /* RateTransition: '<S2>/Rate Transition59' */
  rtb_RateTransition59 = FSAC2021_V1_Running_DW.RateTransition59_Buffer0;

  /* RateTransition: '<S2>/Rate Transition60' */
  rtb_RateTransition60 = FSAC2021_V1_Running_B.RateTransition41;

  /* RateTransition: '<S2>/Rate Transition63' */
  Brk_Enable_Flag = FSAC2021_V1_Running_B.UnitDelay1;

  /* RateTransition: '<S2>/Rate Transition57' */
  rtb_RateTransition57 = FSAC2021_V1_Running_B.RateTransition41;

  /* RateTransition: '<S5>/Rate Transition4' */
  rtb_RateTransition4 = FSAC2021_V1_Running_B.Add4;

  /* RateTransition: '<S5>/Rate Transition3' */
  rtb_RateTransition3 = FSAC2021_V1_Running_B.Add5;

  /* RateTransition: '<S5>/Rate Transition5' */
  rtb_RateTransition5 = FSAC2021_V1_Running_B.Add3;

  /* RateTransition: '<S2>/Rate Transition11' */
  rtb_RateTransition11 = FSAC2021_V1_Running_B.RateTransition15;

  /* UnitDelay: '<S9>/Unit Delay5' */
  rtb_UnitDelay5 = FSAC2021_V1_Running_DW.UnitDelay5_DSTATE_e;

  /* RateTransition: '<S2>/Rate Transition8' */
  AMI_State = rtb_UnitDelay5;

  /* RateTransition: '<S3>/Rate Transition24' */
  rtb_RateTransition24_e = FSAC2021_V1_Running_DW.RateTransition24_Buffer0_n;

  /* RateTransition: '<S2>/Rate Transition24' */
  RES_EBS = rtb_RateTransition24_e;

  /* RateTransition: '<S2>/Rate Transition25' */
  rtb_UnitDelay5 = FSAC2021_V1_Running_DW.RateTransition25_Buffer0_c;

  /* RateTransition: '<S2>/Rate Transition31' */
  rtb_RateTransition31_j = FSAC2021_V1_Running_DW.RateTransition31_Buffer0;

  /* RateTransition: '<S2>/Rate Transition32' */
  rtb_RateTransition32_e = FSAC2021_V1_Running_DW.RateTransition32_Buffer0;

  /* RateTransition: '<S2>/Rate Transition50' */
  rtb_RateTransition50 = FSAC2021_V1_Running_DW.RateTransition50_Buffer0;

  /* UnitDelay: '<S2>/Unit Delay3' */
  rtb_RateTransition24_e = FSAC2021_V1_Running_DW.UnitDelay3_DSTATE;

  /* RateTransition: '<S2>/Rate Transition77' */
  rtb_RateTransition77 = FSAC2021_V1_Running_B.DataTypeConversion22;

  /* RateTransition: '<S2>/Rate Transition78' */
  rtb_RateTransition78 = FSAC2021_V1_Running_B.DataTypeConversion24;

  /* RateTransition: '<S2>/Rate Transition80' */
  rtb_RateTransition80 = FSAC2021_V1_Running_B.DataTypeConversion23;

  /* UnitDelay: '<S3>/Unit Delay2' */
  rtb_UnitDelay2 = FSAC2021_V1_Running_DW.UnitDelay2_DSTATE_h;

  /* RateTransition: '<S3>/Rate Transition47' */
  rtb_RateTransition47 = FSAC2021_V1_Running_DW.RateTransition47_Buffer0;

  /* RateTransition: '<S3>/Rate Transition46' */
  rtb_RateTransition46_e = FSAC2021_V1_Running_DW.RateTransition46_Buffer0;

  /* RateTransition: '<S5>/Rate Transition6' */
  rtb_RateTransition6 = FSAC2021_V1_Running_B.Saturation2;

  /* UnitDelay: '<S2>/Unit Delay7' */
  Steer_Origin_Flag = FSAC2021_V1_Running_DW.UnitDelay7_DSTATE;

  /* RateTransition: '<S1>/Rate Transition19' */
  rtb_RateTransition19_i = FSAC2021_V1_Running_B.RateTransition41;

  /* DataTypeConversion: '<S13>/Data Type Conversion8' incorporates:
   *  UnitDelay: '<S13>/Unit Delay6'
   */
  FSAC2021_V1_Running_B.DataTypeConversion8 = (real32_T)
    FSAC2021_V1_Running_DW.UnitDelay6_DSTATE_n;

  /* UnitDelay: '<S13>/Unit Delay8' */
  FSAC2021_V1_Running_B.UnitDelay8 = FSAC2021_V1_Running_DW.UnitDelay8_DSTATE;

  /* DataTypeConversion: '<S13>/Data Type Conversion6' incorporates:
   *  UnitDelay: '<S13>/Unit Delay4'
   */
  FSAC2021_V1_Running_B.DataTypeConversion6 =
    FSAC2021_V1_Running_DW.UnitDelay4_DSTATE_g;

  /* DataTypeConversion: '<S13>/Data Type Conversion9' incorporates:
   *  UnitDelay: '<S13>/Unit Delay7'
   */
  FSAC2021_V1_Running_B.DataTypeConversion9 =
    FSAC2021_V1_Running_DW.UnitDelay7_DSTATE_g;

  /* DataTypeConversion: '<S13>/Data Type Conversion7' incorporates:
   *  UnitDelay: '<S13>/Unit Delay5'
   */
  FSAC2021_V1_Running_B.DataTypeConversion7 =
    FSAC2021_V1_Running_DW.UnitDelay5_DSTATE_p;

  /* DataTypeConversion: '<S13>/Data Type Conversion2' incorporates:
   *  UnitDelay: '<S13>/Unit Delay'
   */
  FSAC2021_V1_Running_B.DataTypeConversion2 =
    FSAC2021_V1_Running_DW.UnitDelay_DSTATE;

  /* DataTypeConversion: '<S13>/Data Type Conversion4' incorporates:
   *  UnitDelay: '<S13>/Unit Delay2'
   */
  FSAC2021_V1_Running_B.DataTypeConversion4 =
    FSAC2021_V1_Running_DW.UnitDelay2_DSTATE_o;

  /* DataTypeConversion: '<S13>/Data Type Conversion3' incorporates:
   *  UnitDelay: '<S13>/Unit Delay1'
   */
  FSAC2021_V1_Running_B.DataTypeConversion3 =
    FSAC2021_V1_Running_DW.UnitDelay1_DSTATE_n;

  /* DataTypeConversion: '<S13>/Data Type Conversion5' incorporates:
   *  UnitDelay: '<S13>/Unit Delay3'
   */
  FSAC2021_V1_Running_B.DataTypeConversion5 =
    FSAC2021_V1_Running_DW.UnitDelay3_DSTATE_p;

  /* S-Function (fcncallgen): '<S8>/Function-Call Generator1' incorporates:
   *  SubSystem: '<S2>/SteerCtr'
   */
  /* Sum: '<S127>/Real_steer_angle' incorporates:
   *  Constant: '<S127>/Constant'
   */
  Back_Angle = rtb_RateTransition46 - -341.0F;

  /* DataTypeConversion: '<S66>/Data Type Conversion2' incorporates:
   *  UnitDelay: '<S2>/Unit Delay6'
   */
  Str = (int8_T)floor(FSAC2021_V1_Running_DW.UnitDelay6_DSTATE);

  /* Chart: '<S66>/Chart' */
  FSAC2021_V1_Running_DW.presentTicks_nm =
    FSAC2021_V1_Running_M->Timing.clockTick6;
  FSAC2021_V1_Running_DW.elapsedTicks_c = FSAC2021_V1_Running_DW.presentTicks_nm
    - FSAC2021_V1_Running_DW.previousTicks_c;
  FSAC2021_V1_Running_DW.previousTicks_c =
    FSAC2021_V1_Running_DW.presentTicks_nm;
  if (FSAC2021_V1_Running_DW.temporalCounter_i1_m +
      FSAC2021_V1_Running_DW.elapsedTicks_c <= 15U) {
    FSAC2021_V1_Running_DW.temporalCounter_i1_m = (uint8_T)
      (FSAC2021_V1_Running_DW.temporalCounter_i1_m +
       FSAC2021_V1_Running_DW.elapsedTicks_c);
  } else {
    FSAC2021_V1_Running_DW.temporalCounter_i1_m = 15U;
  }

  /* Gateway: Controller/SteerCtr/Chart */
  /* During: Controller/SteerCtr/Chart */
  if (FSAC2021_V1_Running_DW.bitsForTID6.is_active_c14_FSAC2021_V1_Runni == 0U)
  {
    /* Entry: Controller/SteerCtr/Chart */
    FSAC2021_V1_Running_DW.bitsForTID6.is_active_c14_FSAC2021_V1_Runni = 1U;

    /* Entry Internal: Controller/SteerCtr/Chart */
    /* Transition: '<S122>:2' */
    FSAC2021_V1_Running_DW.bitsForTID6.is_c14_FSAC2021_V1_Running =
      FSAC2021_V1_Running_IN_Init;
  } else {
    switch (FSAC2021_V1_Running_DW.bitsForTID6.is_c14_FSAC2021_V1_Running) {
     case FSAC2021_V1_Running_IN_Init:
      /* During 'Init': '<S122>:100' */
      /* Transition: '<S122>:101' */
      FSAC2021_V1_Running_DW.bitsForTID6.is_c14_FSAC2021_V1_Running =
        FSAC2021__IN_Pre_Operation_Mode;

      /* Entry 'Pre_Operation_Mode': '<S122>:1' */
      FSAC2021_V1_Running_B.NMT_nodeorder = 1U;

      /* 开启远程节点。 */
      FSAC2021_V1_Running_B.NMT_nodectrl = 0U;
      break;

     case FSAC2021_V1_Running_IN_Move:
      /* During 'Move': '<S122>:233' */
      switch (FSAC2021_V1_Running_DW.bitsForTID6.is_Move) {
       case FSAC2021_V1_Running_IN_Goto:
        /* Outputs for Function Call SubSystem: '<S13>/MOTEC_CONTROL' */

        /* During 'Goto': '<S122>:13' */
        /* Event: '<S122>:165' */
        FSAC2021_V1__MOTEC_CONTROL(FSAC2021_V1_Running_B.DataTypeConversion7,
          FSAC2021_V1_Running_B.DataTypeConversion8,
          FSAC2021_V1_Running_B.DataTypeConversion3,
          FSAC2021_V1_Running_B.DataTypeConversion6,
          FSAC2021_V1_Running_B.DataTypeConversion5,
          FSAC2021_V1_Running_B.DataTypeConversion2,
          FSAC2021_V1_Running_B.DataTypeConversion4,
          FSAC2021_V1_Running_B.DataTypeConversion9,
          FSAC2021_V1_Running_B.UnitDelay8, &FSAC2021_V1_Running_B.MOTEC_CONTROL);

        /* End of Outputs for SubSystem: '<S13>/MOTEC_CONTROL' */
        FSAC2021_V1_Running_B.Fault_Resrt = 0.0;
        FSAC2021_V1_Running_B.Enable_Operation_Ctrl = 1U;

        /* 允许操作。 */
        if (FSAC2021_V1_Running_DW.bitsForTID6.is_Goto ==
            FSAC2021__IN_Origin_Aciton_Move) {
          /* During 'Origin_Aciton_Move': '<S122>:27' */
          if ((real32_T)fabs(Back_Angle) <= 2.0F) {
            /* Transition: '<S122>:217' */
            FSAC2021_V1_Running_DW.bitsForTID6.is_Goto =
              FSAC2021_V_IN_NO_ACTIVE_CHILD_b;
            FSAC2021_V1_Running_DW.bitsForTID6.is_Move =
              FSAC2021_V1_Running_IN_Wait_l;
            FSAC2021_V1_Running_DW.temporalCounter_i1_m = 0U;
          } else {
            /* Transition: '<S122>:216' */
            FSAC2021_V1_Running_DW.bitsForTID6.is_Goto =
              FSAC2021_V1_R_IN_Origin_Pos_Set;

            /* Entry 'Origin_Pos_Set': '<S122>:25' */
            FSAC2021_V1_Running_B.Position_set = Back_Angle;

            /* 电机回位角度赋值。 */
            FSAC2021_V1_Running_B.New_Set_Point_Ctrl = 0U;
          }
        } else {
          /* During 'Origin_Pos_Set': '<S122>:25' */
          /* Transition: '<S122>:215' */
          FSAC2021_V1_Running_DW.bitsForTID6.is_Goto =
            FSAC2021__IN_Origin_Aciton_Move;

          /* Entry 'Origin_Aciton_Move': '<S122>:27' */
          FSAC2021_V1_Running_B.New_Set_Point_Ctrl = 1U;

          /* 设置新位置点。 */
          FSAC2021_V1_Running_B.Abs_or_Rel_Ctrl = 0U;

          /* 相对位置移动。 */
        }
        break;

       case FSAC2021_V1_Run_IN_Motor_Enable:
        /* Outputs for Function Call SubSystem: '<S13>/MOTEC_CONTROL' */

        /* During 'Motor_Enable': '<S122>:65' */
        /* Event: '<S122>:165' */
        FSAC2021_V1__MOTEC_CONTROL(FSAC2021_V1_Running_B.DataTypeConversion7,
          FSAC2021_V1_Running_B.DataTypeConversion8,
          FSAC2021_V1_Running_B.DataTypeConversion3,
          FSAC2021_V1_Running_B.DataTypeConversion6,
          FSAC2021_V1_Running_B.DataTypeConversion5,
          FSAC2021_V1_Running_B.DataTypeConversion2,
          FSAC2021_V1_Running_B.DataTypeConversion4,
          FSAC2021_V1_Running_B.DataTypeConversion9,
          FSAC2021_V1_Running_B.UnitDelay8, &FSAC2021_V1_Running_B.MOTEC_CONTROL);

        /* End of Outputs for SubSystem: '<S13>/MOTEC_CONTROL' */
        if (FSAC2021_V1_Running_DW.bitsForTID6.is_Motor_Enable ==
            FSAC2021_V1_Running_IN_First) {
          /* During 'First': '<S122>:60' */
          /* Transition: '<S122>:63' */
          FSAC2021_V1_Running_DW.bitsForTID6.is_Motor_Enable =
            FSAC2021_V1_Running_IN_Second;

          /* Entry 'Second': '<S122>:61' */
          FSAC2021_V1_Running_B.Switch_On_Ctrl = 1U;

          /*  伺服使能 */
        } else {
          /* During 'Second': '<S122>:61' */
          /* Transition: '<S122>:14' */
          FSAC2021_V1_Running_DW.bitsForTID6.is_Motor_Enable =
            FSAC2021_V_IN_NO_ACTIVE_CHILD_b;
          FSAC2021_V1_Running_DW.bitsForTID6.is_Move =
            FSAC2021_V1_Running_IN_Goto;

          /* Entry Internal 'Goto': '<S122>:13' */
          /* Transition: '<S122>:185' */
          FSAC2021_V1_Running_DW.bitsForTID6.is_Goto =
            FSAC2021_V1_R_IN_Origin_Pos_Set;

          /* Entry 'Origin_Pos_Set': '<S122>:25' */
          FSAC2021_V1_Running_B.Position_set = Back_Angle;

          /* 电机回位角度赋值。 */
          FSAC2021_V1_Running_B.New_Set_Point_Ctrl = 0U;
        }
        break;

       case FSAC2021_V1_Runni_IN_Motor_Move:
        /* Outputs for Function Call SubSystem: '<S13>/MOTEC_CONTROL' */

        /* During 'Motor_Move': '<S122>:39' */
        /* Event: '<S122>:165' */
        FSAC2021_V1__MOTEC_CONTROL(FSAC2021_V1_Running_B.DataTypeConversion7,
          FSAC2021_V1_Running_B.DataTypeConversion8,
          FSAC2021_V1_Running_B.DataTypeConversion3,
          FSAC2021_V1_Running_B.DataTypeConversion6,
          FSAC2021_V1_Running_B.DataTypeConversion5,
          FSAC2021_V1_Running_B.DataTypeConversion2,
          FSAC2021_V1_Running_B.DataTypeConversion4,
          FSAC2021_V1_Running_B.DataTypeConversion9,
          FSAC2021_V1_Running_B.UnitDelay8, &FSAC2021_V1_Running_B.MOTEC_CONTROL);

        /* End of Outputs for SubSystem: '<S13>/MOTEC_CONTROL' */
        enflag = 1.0;
        if (FSAC2021_V1_Running_DW.bitsForTID6.is_Motor_Move ==
            FSAC2021_V1_Runn_IN_Aciton_Move) {
          /* During 'Aciton_Move': '<S122>:41' */
          /* Transition: '<S122>:43' */
          FSAC2021_V1_Running_DW.bitsForTID6.is_Motor_Move =
            FSAC2021_V_IN_Move_Position_Set;

          /* Entry 'Move_Position_Set': '<S122>:36' */
          FSAC2021_V1_Running_B.Enable_Operation_Ctrl = 1U;

          /* 允许操作。 */
          FSAC2021_V1_Running_B.Position_set = (real32_T)Str;

          /* 期望电机角度赋值 */
          FSAC2021_V1_Running_B.New_Set_Point_Ctrl = 0U;
          FSAC2021_V1_Running_B.Abs_or_Rel_Ctrl = 0U;

          /* 相对位置移动。 */
        } else {
          /* During 'Move_Position_Set': '<S122>:36' */
          /* Transition: '<S122>:42' */
          FSAC2021_V1_Running_DW.bitsForTID6.is_Motor_Move =
            FSAC2021_V1_Runn_IN_Aciton_Move;

          /* Entry 'Aciton_Move': '<S122>:41' */
          FSAC2021_V1_Running_B.New_Set_Point_Ctrl = 1U;

          /* 设置新位置点。 */
          FSAC2021_V1_Running_B.Abs_or_Rel_Ctrl = 1U;

          /* 绝对位置移动。 */
        }
        break;

       case FSAC2021_V1_Run_IN_Motor_Stanby:
        /* Outputs for Function Call SubSystem: '<S13>/MOTEC_ENCODER1' */
        /* Saturate: '<S54>/Str_Encoder1_sat' incorporates:
         *  UnitDelay: '<S13>/Unit Delay11'
         */
        /* During 'Motor_Stanby': '<S122>:35' */
        /* Event: '<S122>:166' */
        if (FSAC2021_V1_Running_DW.UnitDelay11_DSTATE > 255.0F) {
          rtb_RateTransition46 = 255.0F;
        } else if (FSAC2021_V1_Running_DW.UnitDelay11_DSTATE < 0.0F) {
          rtb_RateTransition46 = 0.0F;
        } else {
          rtb_RateTransition46 = FSAC2021_V1_Running_DW.UnitDelay11_DSTATE;
        }

        /* DataTypeConversion: '<S38>/Conv1' incorporates:
         *  DataTypeConversion: '<S54>/Str_Encoder1_Convert'
         *  DataTypeConversion: '<S54>/Str_Encoder1_Convert1'
         *  Rounding: '<S54>/Str_Encoder1Ron'
         *  S-Function (sfix_bitop): '<S54>/Str_Encoder1_L'
         *  Saturate: '<S54>/Str_Encoder1_1sat'
         *  Saturate: '<S54>/Str_Encoder1_sat'
         */
        FSAC2021_V1_Running_B.Conv1 = (uint8_T)((uint32_T)rt_roundf_snf
          (rtb_RateTransition46) & 255U);

        /* Saturate: '<S55>/Str_Encoder2_sat' incorporates:
         *  UnitDelay: '<S13>/Unit Delay12'
         */
        if (FSAC2021_V1_Running_DW.UnitDelay12_DSTATE > 255.0F) {
          rtb_RateTransition46 = 255.0F;
        } else if (FSAC2021_V1_Running_DW.UnitDelay12_DSTATE < 0.0F) {
          rtb_RateTransition46 = 0.0F;
        } else {
          rtb_RateTransition46 = FSAC2021_V1_Running_DW.UnitDelay12_DSTATE;
        }

        /* DataTypeConversion: '<S38>/Conv2' incorporates:
         *  DataTypeConversion: '<S55>/Str_Encoder2_Convert'
         *  DataTypeConversion: '<S55>/Str_Encoder2_Convert1'
         *  Rounding: '<S55>/Str_Encoder2Ron'
         *  S-Function (sfix_bitop): '<S55>/Str_Encoder2_L'
         *  Saturate: '<S55>/Str_Encoder2_1sat'
         *  Saturate: '<S55>/Str_Encoder2_sat'
         */
        FSAC2021_V1_Running_B.Conv2 = (uint8_T)((uint32_T)rt_roundf_snf
          (rtb_RateTransition46) & 255U);

        /* Saturate: '<S56>/Str_Encoder3_sat' incorporates:
         *  UnitDelay: '<S13>/Unit Delay13'
         */
        if (FSAC2021_V1_Running_DW.UnitDelay13_DSTATE > 255.0F) {
          rtb_RateTransition46 = 255.0F;
        } else if (FSAC2021_V1_Running_DW.UnitDelay13_DSTATE < 0.0F) {
          rtb_RateTransition46 = 0.0F;
        } else {
          rtb_RateTransition46 = FSAC2021_V1_Running_DW.UnitDelay13_DSTATE;
        }

        /* DataTypeConversion: '<S38>/Conv3' incorporates:
         *  DataTypeConversion: '<S56>/Str_Encoder3_Convert'
         *  DataTypeConversion: '<S56>/Str_Encoder3_Convert1'
         *  Rounding: '<S56>/Str_Encoder3Ron'
         *  S-Function (sfix_bitop): '<S56>/Str_Encoder3_L'
         *  Saturate: '<S56>/Str_Encoder3_1sat'
         *  Saturate: '<S56>/Str_Encoder3_sat'
         */
        FSAC2021_V1_Running_B.Conv3 = (uint8_T)((uint32_T)rt_roundf_snf
          (rtb_RateTransition46) & 255U);

        /* Saturate: '<S57>/Str_Encoder4_sat' incorporates:
         *  UnitDelay: '<S13>/Unit Delay14'
         */
        if (FSAC2021_V1_Running_DW.UnitDelay14_DSTATE > 255.0F) {
          rtb_RateTransition46 = 255.0F;
        } else if (FSAC2021_V1_Running_DW.UnitDelay14_DSTATE < 0.0F) {
          rtb_RateTransition46 = 0.0F;
        } else {
          rtb_RateTransition46 = FSAC2021_V1_Running_DW.UnitDelay14_DSTATE;
        }

        /* DataTypeConversion: '<S38>/Conv4' incorporates:
         *  DataTypeConversion: '<S57>/Str_Encoder4_Convert'
         *  DataTypeConversion: '<S57>/Str_Encoder4_Convert1'
         *  Rounding: '<S57>/Str_Encoder4Ron'
         *  S-Function (sfix_bitop): '<S57>/Str_Encoder4_L'
         *  Saturate: '<S57>/Str_Encoder4_1sat'
         *  Saturate: '<S57>/Str_Encoder4_sat'
         */
        FSAC2021_V1_Running_B.Conv4 = (uint8_T)((uint32_T)rt_roundf_snf
          (rtb_RateTransition46) & 255U);

        /* End of Outputs for SubSystem: '<S13>/MOTEC_ENCODER1' */

        /* Switch: '<S13>/Switch' incorporates:
         *  Constant: '<S13>/Constant'
         *  Constant: '<S36>/Constant'
         *  RelationalOperator: '<S36>/Compare'
         *  UnitDelay: '<S13>/Unit Delay15'
         */
        if (rtb_RateTransition19_i >= 3) {
          rtb_RateTransition19_i = 0U;
        } else {
          rtb_RateTransition19_i = FSAC2021_V1_Running_DW.UnitDelay15_DSTATE;
        }

        /* End of Switch: '<S13>/Switch' */

        /* Outputs for Function Call SubSystem: '<S13>/MOTEC_ENCODER1' */
        /* DataTypeConversion: '<S38>/Conv5' incorporates:
         *  DataTypeConversion: '<S58>/Str_Encoder5_Convert'
         *  Rounding: '<S58>/Str_Encoder5Ron'
         *  Saturate: '<S58>/Str_Encoder5_1sat'
         *  Sum: '<S58>/Str_Encoder5_st'
         */
        FSAC2021_V1_Running_B.Conv5 = (uint8_T)rt_roundf_snf((real32_T)
          rtb_RateTransition19_i);

        /* Saturate: '<S59>/Str_Encoder6_sat' incorporates:
         *  UnitDelay: '<S13>/Unit Delay16'
         */
        if (FSAC2021_V1_Running_DW.UnitDelay16_DSTATE > 255.0F) {
          rtb_RateTransition46 = 255.0F;
        } else if (FSAC2021_V1_Running_DW.UnitDelay16_DSTATE < 0.0F) {
          rtb_RateTransition46 = 0.0F;
        } else {
          rtb_RateTransition46 = FSAC2021_V1_Running_DW.UnitDelay16_DSTATE;
        }

        /* DataTypeConversion: '<S38>/Conv6' incorporates:
         *  DataTypeConversion: '<S59>/Str_Encoder6_Convert'
         *  DataTypeConversion: '<S59>/Str_Encoder6_Convert1'
         *  Rounding: '<S59>/Str_Encoder6Ron'
         *  S-Function (sfix_bitop): '<S59>/Str_Encoder6_L'
         *  Saturate: '<S59>/Str_Encoder6_1sat'
         *  Saturate: '<S59>/Str_Encoder6_sat'
         */
        FSAC2021_V1_Running_B.Conv6 = (uint8_T)((uint32_T)rt_roundf_snf
          (rtb_RateTransition46) & 255U);

        /* End of Outputs for SubSystem: '<S13>/MOTEC_ENCODER1' */
        FSAC2021_V1_Running_B.Original_Flag = 1.0;

        /* During 'Encoder1': '<S122>:69' */
        if (rtb_RateTransition60 == 3) {
          /* Transition: '<S122>:37' */
          /* Exit 'Encoder1': '<S122>:69' */
          FSAC2021_V1_Running_B.Encoder_Msg_Data[4] = (uint8_T)0x00;
          FSAC2021_V1_Running_DW.bitsForTID6.is_Motor_Stanby =
            FSAC2021_V_IN_NO_ACTIVE_CHILD_b;
          FSAC2021_V1_Running_DW.bitsForTID6.is_Move =
            FSAC2021_V1_Runni_IN_Motor_Move;

          /* Entry Internal 'Motor_Move': '<S122>:39' */
          /* Transition: '<S122>:79' */
          FSAC2021_V1_Running_DW.bitsForTID6.is_Motor_Move =
            FSAC2021_V_IN_Move_Position_Set;

          /* Entry 'Move_Position_Set': '<S122>:36' */
          FSAC2021_V1_Running_B.Enable_Operation_Ctrl = 1U;

          /* 允许操作。 */
          FSAC2021_V1_Running_B.Position_set = (real32_T)Str;

          /* 期望电机角度赋值 */
          FSAC2021_V1_Running_B.New_Set_Point_Ctrl = 0U;
          FSAC2021_V1_Running_B.Abs_or_Rel_Ctrl = 0U;

          /* 相对位置移动。 */
        } else {
          FSAC2021_V1_Running_B.Encoder_Msg_Data[0] = (uint8_T)0x2B;
          FSAC2021_V1_Running_B.Encoder_Msg_Data[1] = (uint8_T)0x04;

          /* 2004对象字典 */
          FSAC2021_V1_Running_B.Encoder_Msg_Data[2] = (uint8_T)0x20;
          FSAC2021_V1_Running_B.Encoder_Msg_Data[3] = (uint8_T)0x00;
          FSAC2021_V1_Running_B.Encoder_Msg_Data[4] = (uint8_T)0x01;

          /* 编码器清零标志位为1 */
          FSAC2021_V1_Running_B.Encoder_Msg_Data[5] = (uint8_T)0x00;

          /* 编码器清零标志位为0 */
        }
        break;

       default:
        /* During 'Wait': '<S122>:238' */
        if ((real32_T)fabs(Back_Angle) > 2.0F) {
          /* Transition: '<S122>:240' */
          FSAC2021_V1_Running_DW.bitsForTID6.is_Move =
            FSAC2021_V1_Running_IN_Goto;
          FSAC2021_V1_Running_DW.bitsForTID6.is_Goto =
            FSAC2021__IN_Origin_Aciton_Move;

          /* Entry 'Origin_Aciton_Move': '<S122>:27' */
          FSAC2021_V1_Running_B.New_Set_Point_Ctrl = 1U;

          /* 设置新位置点。 */
          FSAC2021_V1_Running_B.Abs_or_Rel_Ctrl = 0U;

          /* 相对位置移动。 */
        } else {
          if (FSAC2021_V1_Running_DW.temporalCounter_i1_m >= 10U) {
            /* Transition: '<S122>:241' */
            FSAC2021_V1_Running_DW.bitsForTID6.is_Move =
              FSAC2021_V1_Run_IN_Motor_Stanby;

            /* Entry Internal 'Motor_Stanby': '<S122>:35' */
            /* Transition: '<S122>:171' */
            FSAC2021_V1_Running_DW.bitsForTID6.is_Motor_Stanby =
              FSAC2021_V1_Running_IN_Encoder1;
          }
        }
        break;
      }
      break;

     default:
      /* During 'Pre_Operation_Mode': '<S122>:1' */
      if (rtb_RateTransition59 != 0) {
        /* Transition: '<S122>:8' */
        FSAC2021_V1_Running_DW.bitsForTID6.is_c14_FSAC2021_V1_Running =
          FSAC2021_V1_Running_IN_Move;

        /* Entry Internal 'Move': '<S122>:233' */
        /* Transition: '<S122>:80' */
        FSAC2021_V1_Running_DW.bitsForTID6.is_Move =
          FSAC2021_V1_Run_IN_Motor_Enable;

        /* Entry Internal 'Motor_Enable': '<S122>:65' */
        /* Transition: '<S122>:64' */
        FSAC2021_V1_Running_DW.bitsForTID6.is_Motor_Enable =
          FSAC2021_V1_Running_IN_First;

        /* Entry 'First': '<S122>:60' */
        FSAC2021_V1_Running_B.Switch_On_Ctrl = 0U;

        /*   */
        FSAC2021_V1_Running_B.Enable_Voltage_Ctrl = 1U;

        /* 允许通电。 */
        FSAC2021_V1_Running_B.Quick_Stop_Ctrl = 1U;

        /* 禁用快速停止。 */
      } else {
        /* Outputs for Function Call SubSystem: '<S13>/MOTEC_NMT' */
        /* DataTypeConversion: '<S39>/Conv1' incorporates:
         *  DataTypeConversion: '<S13>/Data Type Conversion'
         *  DataTypeConversion: '<S61>/NMT_nodeorder_Convert'
         *  Rounding: '<S61>/NMT_nodeorderRon'
         *  Saturate: '<S61>/NMT_nodeorder_1sat'
         *  Saturate: '<S61>/NMT_nodeorder_sat'
         *  UnitDelay: '<S13>/Unit Delay10'
         */
        /* 连接所有节点。 */
        /* Event: '<S122>:164' */
        FSAC2021_V1_Running_B.Conv1_p = (uint8_T)rt_roundf_snf((real32_T)
          FSAC2021_V1_Running_DW.UnitDelay10_DSTATE);

        /* DataTypeConversion: '<S39>/Conv2' incorporates:
         *  DataTypeConversion: '<S13>/Data Type Conversion1'
         *  DataTypeConversion: '<S60>/NMT_nodectrl_Convert'
         *  Rounding: '<S60>/NMT_nodectrlRon'
         *  Saturate: '<S60>/NMT_nodectrl_1sat'
         *  Saturate: '<S60>/NMT_nodectrl_sat'
         *  UnitDelay: '<S13>/Unit Delay9'
         */
        FSAC2021_V1_Running_B.Conv2_l = (uint8_T)rt_roundf_snf((real32_T)
          FSAC2021_V1_Running_DW.UnitDelay9_DSTATE);

        /* End of Outputs for SubSystem: '<S13>/MOTEC_NMT' */
      }
      break;
    }
  }

  /* End of Chart: '<S66>/Chart' */

  /* S-Function (fcncallgen): '<S8>/Function-Call Generator1' incorporates:
   *  SubSystem: '<S10>/Read_VCU_Freq(WheelSpeed)'
   */

  /* S-Function (ec55xx_ffrslb): '<S570>/Read_RL_WhlSpd' */

  /* Read the last frequency */
  FSAC2021_V1_Running_B.Read_RL_WhlSpd= ec_etpu_get_ppa_freq(13);

  /* S-Function (ec55xx_ffrslb): '<S570>/Read_RR_WhlSpd' */

  /* Read the last frequency */
  FSAC2021_V1_Running_B.Read_RR_WhlSpd= ec_etpu_get_ppa_freq(14);

  /* S-Function (fcncallgen): '<S8>/Function-Call Generator1' incorporates:
   *  SubSystem: '<S2>/BCU_Controller'
   */
  /* Chart: '<S64>/BCU_Strategy' */
  FSAC2021_V1_Running_DW.presentTicks_c =
    FSAC2021_V1_Running_M->Timing.clockTick6;
  FSAC2021_V1_Running_DW.elapsedTicks_f = FSAC2021_V1_Running_DW.presentTicks_c
    - FSAC2021_V1_Running_DW.previousTicks_i;
  FSAC2021_V1_Running_DW.previousTicks_i = FSAC2021_V1_Running_DW.presentTicks_c;
  if (FSAC2021_V1_Running_DW.temporalCounter_i1_o +
      FSAC2021_V1_Running_DW.elapsedTicks_f <= 15U) {
    FSAC2021_V1_Running_DW.temporalCounter_i1_o = (uint8_T)
      (FSAC2021_V1_Running_DW.temporalCounter_i1_o +
       FSAC2021_V1_Running_DW.elapsedTicks_f);
  } else {
    FSAC2021_V1_Running_DW.temporalCounter_i1_o = 15U;
  }

  /* Gateway: Controller/BCU_Controller/BCU_Strategy */
  /* During: Controller/BCU_Controller/BCU_Strategy */
  if (FSAC2021_V1_Running_DW.bitsForTID6.is_active_c22_FSAC2021_V1_Runni == 0U)
  {
    /* Entry: Controller/BCU_Controller/BCU_Strategy */
    FSAC2021_V1_Running_DW.bitsForTID6.is_active_c22_FSAC2021_V1_Runni = 1U;

    /* Entry Internal: Controller/BCU_Controller/BCU_Strategy */
    /* Transition: '<S113>:38' */
    FSAC2021_V1_Running_DW.bitsForTID6.is_c22_FSAC2021_V1_Running =
      FSAC2021_V1_Running_IN_Idle;
  } else if (FSAC2021_V1_Running_DW.bitsForTID6.is_c22_FSAC2021_V1_Running ==
             FSAC2021_V1_Running_IN_Idle) {
    /* During 'Idle': '<S113>:63' */
    /* Transition: '<S113>:31' */
    FSAC2021_V1_Running_DW.bitsForTID6.is_c22_FSAC2021_V1_Running =
      FSAC2021_V1_Running_IN_RunMode;

    /* Entry Internal 'RunMode': '<S113>:9' */
    /* Transition: '<S113>:64' */
    FSAC2021_V1_Running_DW.bitsForTID6.is_RunMode =
      FSAC2021_V1_Running_IN_Init_g;

    /* Entry 'Init': '<S113>:1' */
    /* Event: '<S113>:58' */
    /* /制动电机使能 */
  } else {
    /* During 'RunMode': '<S113>:9' */
    switch (FSAC2021_V1_Running_DW.bitsForTID6.is_RunMode) {
     case FSAC2021_V1_Runni_IN_BackOrigin:
      /* During 'BackOrigin': '<S113>:6' */
      if (rtb_RateTransition57 == 3) {
        /* Transition: '<S113>:86' */
        FSAC2021_V1_Running_DW.bitsForTID6.is_RunMode =
          FSAC2021_V1_Running_IN_Tozeros;
        FSAC2021_V1_Running_DW.temporalCounter_i1_o = 0U;

        /* Entry 'Tozeros': '<S113>:88' */
        FSAC2021_V1_Running_B.Brk_Ctrl_State = 2U;

        /* 制动占用 */
      }
      break;

     case FSAC2021_V1_Running_IN_Init_g:
      /* During 'Init': '<S113>:1' */
      if ((Brk_Enable_Flag != 0) && (rtb_RateTransition57 == 2)) {
        /* Transition: '<S113>:8' */
        FSAC2021_V1_Running_DW.bitsForTID6.is_RunMode =
          FSAC2021_V1_Runni_IN_BackOrigin;

        /* Entry 'BackOrigin': '<S113>:6' */
        /* Event: '<S113>:11' */
        /* /转向电机回位 */
        FSAC2021_V1_Running_B.Brk_Ctrl_State = 1U;

        /* 制动占用 */
      }
      break;

     case FSAC2021_V1_Running_IN_Move_k:
      /* During 'Move': '<S113>:75' */
      break;

     default:
      /* During 'Tozeros': '<S113>:88' */
      if (FSAC2021_V1_Running_DW.temporalCounter_i1_o >= 10U) {
        /* Transition: '<S113>:89' */
        FSAC2021_V1_Running_DW.bitsForTID6.is_RunMode =
          FSAC2021_V1_Running_IN_Move_k;

        /* Entry 'Move': '<S113>:75' */
        FSAC2021_V1_Running_B.Brk_Ctrl_State = 3U;
      }
      break;
    }
  }

  /* End of Chart: '<S64>/BCU_Strategy' */

  /* Outputs for Enabled SubSystem: '<S114>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S116>/Enable'
   */
  /* RelationalOperator: '<S114>/Equal' incorporates:
   *  Constant: '<S114>/Constant'
   */
  if (FSAC2021_V1_Running_B.Brk_Ctrl_State == 1) {
    /* SignalConversion: '<S116>/OutportBufferForEngaged_Angle' */
    FSAC2021_V1_Running_B.OutportBufferForEngaged_Angle = 10;
  }

  /* End of RelationalOperator: '<S114>/Equal' */
  /* End of Outputs for SubSystem: '<S114>/Enabled Subsystem' */

  /* Outputs for Enabled SubSystem: '<S114>/Enabled Subsystem1' incorporates:
   *  EnablePort: '<S117>/Enable'
   */
  /* RelationalOperator: '<S114>/Equal1' incorporates:
   *  Constant: '<S114>/Constant1'
   */
  if (FSAC2021_V1_Running_B.Brk_Ctrl_State == 2) {
    /* Gain: '<S117>/Gain' */
    rtb_Gain_p = (int8_T)-FSAC2021_V1_Running_B.OutportBufferForEngaged_Angle;
  }

  /* End of RelationalOperator: '<S114>/Equal1' */
  /* End of Outputs for SubSystem: '<S114>/Enabled Subsystem1' */

  /* RelationalOperator: '<S114>/Equal2' incorporates:
   *  Constant: '<S114>/Constant2'
   */
  rtb_Equal2 = (FSAC2021_V1_Running_B.Brk_Ctrl_State == 3);

  /* Outputs for Enabled SubSystem: '<S114>/Enabled Subsystem2' incorporates:
   *  EnablePort: '<S118>/Enable'
   */
  if (rtb_Equal2) {
    /* Gain: '<S118>/Gain' incorporates:
     *  Gain: '<S118>/Brk_Prop2Angle'
     */
    rtb_Gain_i = -((real32_T)(FSAC2021_V1_Running_B.DataTypeConversion9_l << 7) *
                   0.0078125F);
  }

  /* End of Outputs for SubSystem: '<S114>/Enabled Subsystem2' */

  /* S-Function (fcncallgen): '<S8>/Function-Call Generator1' incorporates:
   *  SubSystem: '<S2>/50ms_Duty'
   */
  /* RelationalOperator: '<S96>/Compare' incorporates:
   *  Constant: '<S96>/Constant'
   */
  Compare_Voltage = (Read_compare_OutVolt >= 2.0F);

  /* DataTypeConversion: '<S85>/Data Type Conversion' incorporates:
   *  Logic: '<S85>/Logical Operator'
   *  Logic: '<S85>/Logical Operator1'
   *  Logic: '<S85>/Logical Operator4'
   */
  TS_Flag = (uint8_T)(Compare_Voltage &&
                      ((FSAC2021_V1_Running_B.DataTypeConversion26_g != 0) &&
                       (FSAC2021_V1_Running_B.DataTypeConversion1_j != 0) &&
                       ((FSAC2021_V1_Running_B.DataTypeConversion15 != 0) ||
                        (FSAC2021_V1_Running_B.DataTypeConversion24_k != 0))));

  /* Chart: '<S63>/AS_Machine' incorporates:
   *  UnitDelay: '<S63>/Unit Delay5'
   */
  FSAC2021_V1_Running_DW.presentTicks_b =
    FSAC2021_V1_Running_M->Timing.clockTick6;
  FSAC2021_V1_Running_DW.elapsedTicks_l = FSAC2021_V1_Running_DW.presentTicks_b
    - FSAC2021_V1_Running_DW.previousTicks_a;
  FSAC2021_V1_Running_DW.previousTicks_a = FSAC2021_V1_Running_DW.presentTicks_b;
  if (FSAC2021_V1_Running_DW.temporalCounter_i1_p +
      FSAC2021_V1_Running_DW.elapsedTicks_l <= 127U) {
    FSAC2021_V1_Running_DW.temporalCounter_i1_p = (uint8_T)
      (FSAC2021_V1_Running_DW.temporalCounter_i1_p +
       FSAC2021_V1_Running_DW.elapsedTicks_l);
  } else {
    FSAC2021_V1_Running_DW.temporalCounter_i1_p = 127U;
  }

  /* Gateway: Controller/50ms_Duty/AS_Machine */
  /* During: Controller/50ms_Duty/AS_Machine */
  if (FSAC2021_V1_Running_DW.bitsForTID6.is_active_c3_FSAC2021_V1_Runnin == 0U)
  {
    /* Entry: Controller/50ms_Duty/AS_Machine */
    FSAC2021_V1_Running_DW.bitsForTID6.is_active_c3_FSAC2021_V1_Runnin = 1U;

    /* Entry Internal: Controller/50ms_Duty/AS_Machine */
    /* Transition: '<S83>:85' */
    FSAC2021_V1_Running_DW.bitsForTID6.is_c3_FSAC2021_V1_Running =
      FSAC2021_V1_Running_IN_AS_Off;

    /* Entry 'AS_Off': '<S83>:2' */
    FSAC2021_V1_Running_B.ASSI_State = 1U;
    FSAC2021_V1_Running_B.System_48V_Relay = 0U;
    FSAC2021_V1_Running_B.Blue_Light = 0U;
    FSAC2021_V1_Running_B.Yellow_Light = 0U;
    FSAC2021_V1_Running_B.VCU_Valve = 1U;
  } else {
    switch (FSAC2021_V1_Running_DW.bitsForTID6.is_c3_FSAC2021_V1_Running) {
     case FSAC2021_V1_Runni_IN_AS_Driving:
      /* During 'AS_Driving': '<S83>:7' */
      if ((rtb_RateTransition11 <= 1.0F) &&
          (FSAC2021_V1_Running_DW.UnitDelay5_DSTATE_h != 0)) {
        /* Transition: '<S83>:10' */
        FSAC2021_V1_Running_DW.bitsForTID6.is_c3_FSAC2021_V1_Running =
          FSAC2021_V1_Runn_IN_AS_Finished;

        /* Entry 'AS_Finished': '<S83>:9' */
        FSAC2021_V1_Running_B.ASSI_State = 4U;
        FSAC2021_V1_Running_B.R2D = 0U;
        FSAC2021_V1_Running_B.Safety_Circuit_Relay = 1U;

        /* ON */
        FSAC2021_V1_Running_B.System_48V_Relay = 0U;
        FSAC2021_V1_Running_B.Blue_Light = 1U;

        /* ON */
        FSAC2021_V1_Running_B.Yellow_Light = 0U;
      } else {
        if (RES_EBS == 1) {
          /* Transition: '<S83>:13' */
          /* Transition: '<S83>:70' */
          FSAC2021_V1_Running_DW.bitsForTID6.is_c3_FSAC2021_V1_Running =
            FSAC2021_V1_Run_IN_AS_Emergency;

          /* Entry 'AS_Emergency': '<S83>:11' */
          FSAC2021_V1_Running_B.ASSI_State = 5U;
          FSAC2021_V1_Running_B.R2D = 0U;
          FSAC2021_V1_Running_B.Yellow_Light = 0U;
          FSAC2021_V1_Running_B.Blue_Light = 2U;
          FSAC2021_V1_Running_B.Buzzer = 2U;
        }
      }
      break;

     case FSAC2021_V1_Run_IN_AS_Emergency:
      /* During 'AS_Emergency': '<S83>:11' */
      if ((!(FSAC2021_V1_Running_B.DataTypeConversion4_f != 0)) &&
          (rtb_RateTransition24_e != 0) && (RES_EBS == 0)) {
        /* Transition: '<S83>:18' */
        FSAC2021_V1_Running_DW.bitsForTID6.is_c3_FSAC2021_V1_Running =
          FSAC2021_V1_Running_IN_AS_Off;

        /* Entry 'AS_Off': '<S83>:2' */
        FSAC2021_V1_Running_B.ASSI_State = 1U;
        FSAC2021_V1_Running_B.System_48V_Relay = 0U;
        FSAC2021_V1_Running_B.Blue_Light = 0U;
        FSAC2021_V1_Running_B.Yellow_Light = 0U;
        FSAC2021_V1_Running_B.VCU_Valve = 1U;
      }
      break;

     case FSAC2021_V1_Runn_IN_AS_Finished:
      /* During 'AS_Finished': '<S83>:9' */
      if (RES_EBS != 0) {
        /* Transition: '<S83>:14' */
        FSAC2021_V1_Running_DW.bitsForTID6.is_c3_FSAC2021_V1_Running =
          FSAC2021_V1_Run_IN_AS_Emergency;

        /* Entry 'AS_Emergency': '<S83>:11' */
        FSAC2021_V1_Running_B.ASSI_State = 5U;
        FSAC2021_V1_Running_B.R2D = 0U;
        FSAC2021_V1_Running_B.Yellow_Light = 0U;
        FSAC2021_V1_Running_B.Blue_Light = 2U;
        FSAC2021_V1_Running_B.Buzzer = 2U;
      } else {
        /* Transition: '<S83>:68' */
        if (!(FSAC2021_V1_Running_B.DataTypeConversion4_f != 0)) {
          /* Transition: '<S83>:15' */
          /* Transition: '<S83>:67' */
          FSAC2021_V1_Running_DW.bitsForTID6.is_c3_FSAC2021_V1_Running =
            FSAC2021_V1_Running_IN_AS_Off;

          /* Entry 'AS_Off': '<S83>:2' */
          FSAC2021_V1_Running_B.ASSI_State = 1U;
          FSAC2021_V1_Running_B.System_48V_Relay = 0U;
          FSAC2021_V1_Running_B.Blue_Light = 0U;
          FSAC2021_V1_Running_B.Yellow_Light = 0U;
          FSAC2021_V1_Running_B.VCU_Valve = 1U;
        }
      }
      break;

     case FSAC2021_V1_Running_IN_AS_Off:
      /* During 'AS_Off': '<S83>:2' */
      if ((AMI_State == 6) && (TS_Flag != 0) &&
          (!(FSAC2021_V1_Running_B.DataTypeConversion4_f != 0)) &&
          (FSAC2021_V1_Running_B.DataTypeConversion25_m != 0)) {
        /* Transition: '<S83>:16' */
        FSAC2021_V1_Running_DW.bitsForTID6.is_c3_FSAC2021_V1_Running =
          FSAC2021_V1_R_IN_Manual_Driving;

        /* Entry 'Manual_Driving': '<S83>:12' */
        FSAC2021_V1_Running_B.R2D = 1U;
        FSAC2021_V1_Running_B.ASSI_State = 6U;
      } else if ((FSAC2021_V1_Running_B.DataTypeConversion19 != 0) &&
                 (FSAC2021_V1_Running_B.DataTypeConversion4_f != 0) && (TS_Flag
                  != 0) && (AMI_State != 0)) {
        /* Transition: '<S83>:5' */
        FSAC2021_V1_Running_DW.bitsForTID6.is_c3_FSAC2021_V1_Running =
          FSAC2021_V1_Running_IN_AS_Ready;
        FSAC2021_V1_Running_DW.temporalCounter_i1_p = 0U;

        /* Entry 'AS_Ready': '<S83>:3' */
        FSAC2021_V1_Running_B.ASSI_State = 2U;
        FSAC2021_V1_Running_B.System_48V_Relay = 1U;
        FSAC2021_V1_Running_B.Yellow_Light = 1U;
        FSAC2021_V1_Running_B.Blue_Light = 0U;
      } else {
        /* Outputs for Function Call SubSystem: '<S63>/Visuality Check' */
        /* Chart: '<S94>/Chart' */
        /* Event: '<S83>:79' */
        /* Event: '<S83>:87' */
        FSAC2021_V1_Running_DW.presentTicks_n =
          FSAC2021_V1_Running_M->Timing.clockTick6;
        FSAC2021_V1_Running_DW.elapsedTicks_d =
          FSAC2021_V1_Running_DW.presentTicks_n -
          FSAC2021_V1_Running_DW.previousTicks_l;
        FSAC2021_V1_Running_DW.previousTicks_l =
          FSAC2021_V1_Running_DW.presentTicks_n;
        if (FSAC2021_V1_Running_DW.temporalCounter_i1_e +
            FSAC2021_V1_Running_DW.elapsedTicks_d <= 63U) {
          FSAC2021_V1_Running_DW.temporalCounter_i1_e = (uint8_T)
            (FSAC2021_V1_Running_DW.temporalCounter_i1_e +
             FSAC2021_V1_Running_DW.elapsedTicks_d);
        } else {
          FSAC2021_V1_Running_DW.temporalCounter_i1_e = 63U;
        }

        /* Gateway: Controller/50ms_Duty/Visuality Check/Chart */
        /* During: Controller/50ms_Duty/Visuality Check/Chart */
        if (FSAC2021_V1_Running_DW.bitsForTID6.is_active_c2_FSAC2021_V1_Runnin ==
            0U) {
          /* Entry: Controller/50ms_Duty/Visuality Check/Chart */
          FSAC2021_V1_Running_DW.bitsForTID6.is_active_c2_FSAC2021_V1_Runnin =
            1U;

          /* Entry Internal: Controller/50ms_Duty/Visuality Check/Chart */
          /* Transition: '<S112>:2' */
          FSAC2021_V1_Running_DW.bitsForTID6.is_c2_FSAC2021_V1_Running =
            FSAC2021_V1_Run_IN_Visuality_On;
          FSAC2021_V1_Running_DW.temporalCounter_i1_e = 0U;

          /* Entry 'Visuality_On': '<S112>:1' */
          FSAC2021_V1_Running_B.Visual_Lights[0] = 1U;
          FSAC2021_V1_Running_B.Visual_Lights[1] = 1U;
          FSAC2021_V1_Running_B.Visual_Lights[2] = 1U;
          FSAC2021_V1_Running_B.Visual_Flag = 1U;
        } else if ((FSAC2021_V1_Running_DW.bitsForTID6.is_c2_FSAC2021_V1_Running
                    != FSAC2021_V1_Ru_IN_Visuality_Off) &&
                   (FSAC2021_V1_Running_DW.temporalCounter_i1_e >= 40U)) {
          /* During 'Visuality_On': '<S112>:1' */
          /* Transition: '<S112>:4' */
          FSAC2021_V1_Running_DW.bitsForTID6.is_c2_FSAC2021_V1_Running =
            FSAC2021_V1_Ru_IN_Visuality_Off;

          /* Entry 'Visuality_Off': '<S112>:3' */
          FSAC2021_V1_Running_B.Visual_Lights[0] = 0U;
          FSAC2021_V1_Running_B.Visual_Lights[1] = 0U;
          FSAC2021_V1_Running_B.Visual_Lights[2] = 0U;
          FSAC2021_V1_Running_B.Visual_Flag = 0U;
        } else {
          /* During 'Visuality_Off': '<S112>:3' */
        }

        /* End of Chart: '<S94>/Chart' */
        /* End of Outputs for SubSystem: '<S63>/Visuality Check' */
      }
      break;

     case FSAC2021_V1_Running_IN_AS_Ready:
      /* During 'AS_Ready': '<S83>:3' */
      if ((FSAC2021_V1_Running_DW.temporalCounter_i1_p >= 100U) &&
          (rtb_UnitDelay5 != 0)) {
        /* Transition: '<S83>:8' */
        FSAC2021_V1_Running_DW.bitsForTID6.is_c3_FSAC2021_V1_Running =
          FSAC2021_V1_Runni_IN_AS_Driving;

        /* Entry 'AS_Driving': '<S83>:7' */
        FSAC2021_V1_Running_B.R2D = 1U;
        FSAC2021_V1_Running_B.ASSI_State = 3U;
        FSAC2021_V1_Running_B.Yellow_Light = 2U;
        FSAC2021_V1_Running_B.Blue_Light = 0U;
        FSAC2021_V1_Running_B.Buzzer = 1U;
      } else if (!(FSAC2021_V1_Running_B.DataTypeConversion4_f != 0)) {
        /* Transition: '<S83>:6' */
        FSAC2021_V1_Running_DW.bitsForTID6.is_c3_FSAC2021_V1_Running =
          FSAC2021_V1_Running_IN_AS_Off;

        /* Entry 'AS_Off': '<S83>:2' */
        FSAC2021_V1_Running_B.ASSI_State = 1U;
        FSAC2021_V1_Running_B.System_48V_Relay = 0U;
        FSAC2021_V1_Running_B.Blue_Light = 0U;
        FSAC2021_V1_Running_B.Yellow_Light = 0U;
        FSAC2021_V1_Running_B.VCU_Valve = 1U;
      } else {
        if (RES_EBS == 2) {
          /* Transition: '<S83>:19' */
          FSAC2021_V1_Running_DW.bitsForTID6.is_c3_FSAC2021_V1_Running =
            FSAC2021_V1_Run_IN_AS_Emergency;

          /* Entry 'AS_Emergency': '<S83>:11' */
          FSAC2021_V1_Running_B.ASSI_State = 5U;
          FSAC2021_V1_Running_B.R2D = 0U;
          FSAC2021_V1_Running_B.Yellow_Light = 0U;
          FSAC2021_V1_Running_B.Blue_Light = 2U;
          FSAC2021_V1_Running_B.Buzzer = 2U;
        }
      }
      break;

     default:
      /* During 'Manual_Driving': '<S83>:12' */
      if (!(TS_Flag != 0)) {
        /* Transition: '<S83>:17' */
        FSAC2021_V1_Running_DW.bitsForTID6.is_c3_FSAC2021_V1_Running =
          FSAC2021_V1_Running_IN_AS_Off;

        /* Entry 'AS_Off': '<S83>:2' */
        FSAC2021_V1_Running_B.ASSI_State = 1U;
        FSAC2021_V1_Running_B.System_48V_Relay = 0U;
        FSAC2021_V1_Running_B.Blue_Light = 0U;
        FSAC2021_V1_Running_B.Yellow_Light = 0U;
        FSAC2021_V1_Running_B.VCU_Valve = 1U;
      }
      break;
    }
  }

  /* End of Chart: '<S63>/AS_Machine' */

  /* Logic: '<S82>/Logical Operator' */
  LogicalOperator_p = (FSAC2021_V1_Running_B.System_48V_Relay != 0);

  /* Switch: '<S86>/Switch' */
  if (FSAC2021_V1_Running_B.Visual_Flag > 0) {
    rtb_RateTransition47 = FSAC2021_V1_Running_B.Visual_Lights[0];
  }

  if (FSAC2021_V1_Running_B.Visual_Flag > 0) {
    rtb_UnitDelay2 = FSAC2021_V1_Running_B.Visual_Lights[1];
  }

  if (FSAC2021_V1_Running_B.Visual_Flag > 0) {
    rtb_RateTransition46_e = FSAC2021_V1_Running_B.Visual_Lights[2];
  }

  /* End of Switch: '<S86>/Switch' */

  /* Logic: '<S91>/Logical Operator' incorporates:
   *  Logic: '<S91>/Logical Operator1'
   */
  LogicalOperator_nw = ((FSAC2021_V1_Running_B.R2D != 0) &&
                        (!rtb_RateTransition50));

  /* Logic: '<S92>/Logical Operator' */
  rtb_RateTransition50 = ((FSAC2021_V1_Running_B.Safety_Circuit_Relay != 0) ||
    rtb_RateTransition31_j || rtb_RateTransition32_e);

  /* Chart: '<S93>/Chart' */
  /* Gateway: Controller/50ms_Duty/Subsystem/Chart */
  /* During: Controller/50ms_Duty/Subsystem/Chart */
  if (FSAC2021_V1_Running_DW.bitsForTID6.is_active_c5_FSAC2021_V1_Runnin == 0U)
  {
    /* Entry: Controller/50ms_Duty/Subsystem/Chart */
    FSAC2021_V1_Running_DW.bitsForTID6.is_active_c5_FSAC2021_V1_Runnin = 1U;

    /* Entry Internal: Controller/50ms_Duty/Subsystem/Chart */
    /* Transition: '<S98>:7' */
    FSAC2021_V1_Running_DW.bitsForTID6.is_c5_FSAC2021_V1_Running =
      FSAC2021_V1_Running_IN_init;
  } else {
    switch (FSAC2021_V1_Running_DW.bitsForTID6.is_c5_FSAC2021_V1_Running) {
     case FSAC2021_V1_Runni_IN_Driverless:
      /* During 'Driverless': '<S98>:4' */
      MODE = 2.0;

      /* %无人驾驶模式 */
      break;

     case FSAC2021_V1_Running_IN_Manul:
      /* During 'Manul': '<S98>:2' */
      /* Transition: '<S98>:9' */
      if ((AMI_State == 1) || (AMI_State == 2) || (AMI_State == 3) || (AMI_State
           == 5)) {
        /* Transition: '<S98>:11' */
        FSAC2021_V1_Running_DW.bitsForTID6.is_c5_FSAC2021_V1_Running =
          FSAC2021_V1_Runni_IN_Driverless;
      } else {
        MODE = 1.0;

        /* 手动模式 */
      }
      break;

     case FSAC2021_V1_Running_IN_Task:
      /* During 'Task': '<S98>:14' */
      MODE = 3.0;

      /* %车检任务 */
      break;

     default:
      /* During 'init': '<S98>:1' */
      if (AMI_State == 6) {
        /* Transition: '<S98>:3' */
        FSAC2021_V1_Running_DW.bitsForTID6.is_c5_FSAC2021_V1_Running =
          FSAC2021_V1_Running_IN_Manul;
      } else if ((AMI_State == 1) || (AMI_State == 2) || (AMI_State == 3) ||
                 (AMI_State == 5)) {
        /* Transition: '<S98>:10' */
        FSAC2021_V1_Running_DW.bitsForTID6.is_c5_FSAC2021_V1_Running =
          FSAC2021_V1_Runni_IN_Driverless;
      } else {
        if (AMI_State == 4) {
          /* Transition: '<S98>:16' */
          /* Transition: '<S98>:17' */
          FSAC2021_V1_Running_DW.bitsForTID6.is_c5_FSAC2021_V1_Running =
            FSAC2021_V1_Running_IN_Task;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S93>/Chart' */

  /* Outputs for Enabled SubSystem: '<S93>/Subsystem1' incorporates:
   *  EnablePort: '<S109>/Enable'
   */
  /* RelationalOperator: '<S100>/Compare' incorporates:
   *  Constant: '<S100>/Constant'
   *  Inport: '<S109>/IPC_Str_Cmd'
   */
  if (MODE == 2.0) {
    /* Gain: '<S109>/Gain1' */
    rtb_RateTransition78 *= 0.11;

    /* Saturate: '<S109>/Saturation' */
    if (rtb_RateTransition78 > 11.0) {
      FSAC2021_V1_Running_B.Saturation = 11.0;
    } else if (rtb_RateTransition78 < 0.0) {
      FSAC2021_V1_Running_B.Saturation = 0.0;
    } else {
      FSAC2021_V1_Running_B.Saturation = rtb_RateTransition78;
    }

    /* End of Saturate: '<S109>/Saturation' */
    ipc_strr = rtb_RateTransition77;

    /* Gain: '<S109>/Gain' incorporates:
     *  Inport: '<S109>/IPC_Str_Cmd'
     */
    FSAC2021_V1_Running_B.Merge = 15.0 * rtb_RateTransition80;
  }

  /* End of RelationalOperator: '<S100>/Compare' */
  /* End of Outputs for SubSystem: '<S93>/Subsystem1' */

  /* Outputs for Enabled SubSystem: '<S93>/Subsystem' incorporates:
   *  EnablePort: '<S108>/Enable'
   */
  /* RelationalOperator: '<S99>/Compare' incorporates:
   *  Constant: '<S99>/Constant'
   */
  if (MODE == 1.0) {
    /* Gain: '<S108>/Gain' */
    rtb_RateTransition78 = 15.0 * rtb_RateTransition6;

    /* Saturate: '<S108>/Saturation' */
    if (rtb_RateTransition78 > 1500.0) {
      FSAC2021_V1_Running_B.Merge = 1500.0;
    } else if (rtb_RateTransition78 < 0.0) {
      FSAC2021_V1_Running_B.Merge = 0.0;
    } else {
      FSAC2021_V1_Running_B.Merge = rtb_RateTransition78;
    }

    /* End of Saturate: '<S108>/Saturation' */
  }

  /* End of RelationalOperator: '<S99>/Compare' */
  /* End of Outputs for SubSystem: '<S93>/Subsystem' */

  /* Logic: '<S93>/Logical Operator' incorporates:
   *  Constant: '<S101>/Constant'
   *  Constant: '<S103>/Constant'
   *  Constant: '<S104>/Constant'
   *  RelationalOperator: '<S101>/Compare'
   *  RelationalOperator: '<S103>/Compare'
   *  RelationalOperator: '<S104>/Compare'
   */
  enable = ((MODE == 3.0) && (Steer_Origin_Flag == 1.0) &&
            (FSAC2021_V1_Running_B.ASSI_State >= 3));

  /* Outputs for Enabled SubSystem: '<S93>/Subsystem2' incorporates:
   *  EnablePort: '<S110>/Enable'
   */
  if (enable) {
    if (!FSAC2021_V1_Running_DW.Subsystem2_MODE) {
      /* Enable for Chart: '<S110>/Chart' */
      FSAC2021_V1_Running_DW.presentTicks =
        FSAC2021_V1_Running_M->Timing.clockTick6;
      FSAC2021_V1_Running_DW.previousTicks = FSAC2021_V1_Running_DW.presentTicks;
      FSAC2021_V1_Running_DW.Subsystem2_MODE = true;
    }

    /* Chart: '<S110>/Chart' */
    FSAC2021_V1_Running_DW.presentTicks =
      FSAC2021_V1_Running_M->Timing.clockTick6;
    FSAC2021_V1_Running_DW.elapsedTicks = FSAC2021_V1_Running_DW.presentTicks -
      FSAC2021_V1_Running_DW.previousTicks;
    FSAC2021_V1_Running_DW.previousTicks = FSAC2021_V1_Running_DW.presentTicks;
    if (FSAC2021_V1_Running_DW.temporalCounter_i1 +
        FSAC2021_V1_Running_DW.elapsedTicks <= 1023U) {
      FSAC2021_V1_Running_DW.temporalCounter_i1 = (uint16_T)
        (FSAC2021_V1_Running_DW.temporalCounter_i1 +
         FSAC2021_V1_Running_DW.elapsedTicks);
    } else {
      FSAC2021_V1_Running_DW.temporalCounter_i1 = 1023U;
    }

    /* Gateway: Controller/50ms_Duty/Subsystem/Subsystem2/Chart */
    /* During: Controller/50ms_Duty/Subsystem/Subsystem2/Chart */
    if (FSAC2021_V1_Running_DW.bitsForTID6.is_active_c9_FSAC2021_V1_Runnin == 0U)
    {
      /* Entry: Controller/50ms_Duty/Subsystem/Subsystem2/Chart */
      FSAC2021_V1_Running_DW.bitsForTID6.is_active_c9_FSAC2021_V1_Runnin = 1U;

      /* Entry Internal: Controller/50ms_Duty/Subsystem/Subsystem2/Chart */
      /* Transition: '<S111>:33' */
      FSAC2021_V1_Running_DW.bitsForTID6.is_c9_FSAC2021_V1_Running =
        FSAC2021_V1_Running_IN_init_g;

      /* Entry 'init': '<S111>:26' */
      FSAC2021_V1_Running_B.SteerCmd = 0.0;
      FSAC2021_V1_Running_B.ACC_b = 200.0;
    } else {
      switch (FSAC2021_V1_Running_DW.bitsForTID6.is_c9_FSAC2021_V1_Running) {
       case FSAC2021_V1_Running_IN_IN:
        /* During 'IN': '<S111>:30' */
        if (FSAC2021_V1_Running_DW.temporalCounter_i1 >= 540U) {
          /* Transition: '<S111>:32' */
          /* Exit Internal 'IN': '<S111>:30' */
          FSAC2021_V1_Running_DW.bitsForTID6.is_IN =
            FSAC2021_V_IN_NO_ACTIVE_CHILD_b;
          FSAC2021_V1_Running_DW.bitsForTID6.is_c9_FSAC2021_V1_Running =
            FSAC2021_V1_Running_IN_end;

          /* Entry 'end': '<S111>:34' */
          FSAC2021_V1_Running_B.ACC_b = 0.0;
          FSAC2021_V1_Running_B.SteerCmd = 0.0;
          FSAC2021_V1_Running_B.Mission_Flag = 1U;
        } else if (FSAC2021_V1_Running_DW.bitsForTID6.is_IN ==
                   FSAC2021_V1_Running_IN_Move_c) {
          /* During 'Move': '<S111>:28' */
          if (FSAC2021_V1_Running_B.SteerCmd >= 110.0) {
            /* Transition: '<S111>:25' */
            FSAC2021_V1_Running_DW.bitsForTID6.is_IN =
              FSAC2021_V1_Running_IN_Second;
          } else {
            FSAC2021_V1_Running_B.SteerCmd += 4.5;
          }
        } else {
          /* During 'Second': '<S111>:27' */
          if (FSAC2021_V1_Running_B.SteerCmd <= -110.0) {
            /* Transition: '<S111>:29' */
            FSAC2021_V1_Running_DW.bitsForTID6.is_IN =
              FSAC2021_V1_Running_IN_Move_c;
          } else {
            FSAC2021_V1_Running_B.SteerCmd -= 4.5;
          }
        }
        break;

       case FSAC2021_V1_Running_IN_end:
        /* During 'end': '<S111>:34' */
        break;

       default:
        /* During 'init': '<S111>:26' */
        /* Transition: '<S111>:35' */
        FSAC2021_V1_Running_DW.bitsForTID6.is_c9_FSAC2021_V1_Running =
          FSAC2021_V1_Running_IN_IN;
        FSAC2021_V1_Running_DW.temporalCounter_i1 = 0U;

        /* Entry 'IN': '<S111>:30' */
        /* Entry Internal 'IN': '<S111>:30' */
        /* Transition: '<S111>:31' */
        FSAC2021_V1_Running_DW.bitsForTID6.is_IN = FSAC2021_V1_Running_IN_Move_c;
        break;
      }
    }

    /* End of Chart: '<S110>/Chart' */

    /* SignalConversion: '<S110>/OutportBufferForACC' */
    FSAC2021_V1_Running_B.Merge = FSAC2021_V1_Running_B.ACC_b;

    /* SignalConversion: '<S110>/OutportBufferForSteerCmd' */
    ipc_strr = FSAC2021_V1_Running_B.SteerCmd;
  } else {
    if (FSAC2021_V1_Running_DW.Subsystem2_MODE) {
      /* Disable for Chart: '<S110>/Chart' */
      FSAC2021_V1_Running_DW.presentTicks =
        FSAC2021_V1_Running_M->Timing.clockTick6;
      FSAC2021_V1_Running_DW.elapsedTicks = FSAC2021_V1_Running_DW.presentTicks
        - FSAC2021_V1_Running_DW.previousTicks;
      FSAC2021_V1_Running_DW.previousTicks = FSAC2021_V1_Running_DW.presentTicks;
      if (FSAC2021_V1_Running_DW.temporalCounter_i1 +
          FSAC2021_V1_Running_DW.elapsedTicks <= 1023U) {
        FSAC2021_V1_Running_DW.temporalCounter_i1 = (uint16_T)
          (FSAC2021_V1_Running_DW.temporalCounter_i1 +
           FSAC2021_V1_Running_DW.elapsedTicks);
      } else {
        FSAC2021_V1_Running_DW.temporalCounter_i1 = 1023U;
      }

      /* End of Disable for Chart: '<S110>/Chart' */
      FSAC2021_V1_Running_DW.Subsystem2_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S93>/Subsystem2' */

  /* DataTypeConversion: '<S93>/Data Type Conversion10' */
  rtb_RateTransition46 = (real32_T)FSAC2021_V1_Running_B.Merge;

  /* DataTypeConversion: '<S93>/Data Type Conversion9' */
  FSAC2021_V1_Running_B.DataTypeConversion9_l = (uint8_T)
    FSAC2021_V1_Running_B.Saturation;

  /* Truth Table: '<S84>/Truth Table' incorporates:
   *  RelationalOperator: '<S84>/Relational Operator'
   *  RelationalOperator: '<S84>/Relational Operator1'
   *  RelationalOperator: '<S84>/Relational Operator2'
   */
  /* Truth Table Function 'Controller/50ms_Duty/EBS_Judge/Truth Table': '<S95>:1' */
  /*  No gas in 1 */
  /* Condition '#1': '<S95>:1:10' */
  rtb_RateTransition31_j = ((rtb_RateTransition4 <= 0.40000000596046448) == 0);

  /*  No gas in 2 */
  /* Condition '#2': '<S95>:1:14' */
  rtb_RateTransition32_e = ((rtb_RateTransition3 <= 0.40000000596046448) == 0);

  /*  No Prs in Luquid */
  /* Condition '#3': '<S95>:1:18' */
  if (rtb_RateTransition31_j && rtb_RateTransition32_e) {
    /* Decision 'D1': '<S95>:1:20' */
    /*  EBS DISABLE */
    /* Action '1': '<S95>:1:34' */
    EBS_Status = 0U;
  } else if ((!rtb_RateTransition31_j) && rtb_RateTransition32_e) {
    /* Decision 'D2': '<S95>:1:22' */
    /*  EBS Armed */
    /* Action '2': '<S95>:1:40' */
    EBS_Status = 1U;
  } else if ((!rtb_RateTransition31_j) && (!rtb_RateTransition32_e) &&
             (!((rtb_RateTransition5 <= 2.7999999523162842) == 0))) {
    /* Decision 'D3': '<S95>:1:24' */
    /*  EBS Enable */
    /* Action '3': '<S95>:1:46' */
    EBS_Status = 2U;
  } else {
    /* Decision 'D4': '<S95>:1:24' */
    /* Decision 'D4': '<S95>:1:26' */
    /*  Default */
    /*  Keep */
    /* Action '4': '<S95>:1:52' */
    EBS_Status = 3U;
  }

  /* End of Truth Table: '<S84>/Truth Table' */

  /* Update for UnitDelay: '<S63>/Unit Delay5' */
  FSAC2021_V1_Running_DW.UnitDelay5_DSTATE_h =
    FSAC2021_V1_Running_B.Mission_Flag;

  /* S-Function (fcncallgen): '<S8>/Function-Call Generator1' incorporates:
   *  SubSystem: '<S10>/Read_VCU_DigInput'
   */

  /* S-Function (ec55xx_swislb): '<S569>/LVMS_Read' */

  /* Read the the value of the specified switch input */
  LVMS_Read= ec_gpio_read(159);

  /* DataTypeConversion: '<S569>/Data Type Conversion19' */
  FSAC2021_V1_Running_B.DataTypeConversion19 = (uint8_T)LVMS_Read;

  /* S-Function (ec55xx_swislb): '<S569>/HVMS_Read' */

  /* Read the the value of the specified switch input */
  HVMS_Read= ec_gpio_read(161);

  /* DataTypeConversion: '<S569>/Data Type Conversion1' */
  FSAC2021_V1_Running_B.DataTypeConversion1_j = (uint8_T)HVMS_Read;

  /* S-Function (ec55xx_swislb): '<S569>/On_Out_Switch' */

  /* Read the the value of the specified switch input */
  On_Out_Switch= ec_gpio_read(157);

  /* DataTypeConversion: '<S569>/Data Type Conversion15' */
  FSAC2021_V1_Running_B.DataTypeConversion15 = (uint8_T)On_Out_Switch;

  /* S-Function (ec55xx_swislb): '<S569>/START' */

  /* Read the the value of the specified switch input */
  START= ec_gpio_read(154);

  /* DataTypeConversion: '<S569>/Data Type Conversion25' */
  FSAC2021_V1_Running_B.DataTypeConversion25_m = (uint8_T)START;

  /* S-Function (ec55xx_swislb): '<S569>/On_In_Switch' */

  /* Read the the value of the specified switch input */
  On_IN_Switch= ec_gpio_read(156);

  /* DataTypeConversion: '<S569>/Data Type Conversion24' */
  FSAC2021_V1_Running_B.DataTypeConversion24_k = (uint8_T)On_IN_Switch;

  /* S-Function (ec55xx_swislb): '<S569>/HV_LIGHT' */

  /* Read the the value of the specified switch input */
  HV_LIGHT= ec_gpio_read(160);

  /* DataTypeConversion: '<S569>/Data Type Conversion26' */
  FSAC2021_V1_Running_B.DataTypeConversion26_g = (uint8_T)HV_LIGHT;

  /* S-Function (ec55xx_swislb): '<S569>/IMD_BENDER' */

  /* Read the the value of the specified switch input */
  IMD_BENDER= ec_gpio_read(173);

  /* DataTypeConversion: '<S569>/Data Type Conversion2' */
  rtb_RateTransition24_e = (uint8_T)IMD_BENDER;

  /* S-Function (ec55xx_swislb): '<S569>/ASMS_Read' */

  /* Read the the value of the specified switch input */
  ASMS_Read= ec_gpio_read(158);

  /* DataTypeConversion: '<S569>/Data Type Conversion4' */
  FSAC2021_V1_Running_B.DataTypeConversion4_f = (uint8_T)ASMS_Read;

  /* S-Function (ec55xx_swislb): '<S569>/EBS_Rel_Switch' */

  /* Read the the value of the specified switch input */
  EBS_Rel_Switch= ec_gpio_read(169);

  /* S-Function (fcncallgen): '<S8>/Function-Call Generator1' incorporates:
   *  SubSystem: '<S10>/Read_VCU_AnaInput'
   */

  /* S-Function (ec55xx_asislb): '<S568>/Read_Lft_Acc_Disp' */

  /* Read the ADC conversion result of the analog signal */
  Read_Lft_Acc_Disp= ec_adc_readresult(25);

  /* S-Function (ec55xx_asislb): '<S568>/Read_Right_Acc_Disp1' */

  /* Read the ADC conversion result of the analog signal */
  Read_Right_Acc_Disp1= ec_adc_readresult(14);

  /* S-Function (ec55xx_asislb): '<S568>/Read_Compare' */

  /* Read the ADC conversion result of the analog signal */
  FSAC2021_V1_Running_B.Read_Compare= ec_adc_readresult(5);

  /* Gain: '<S568>/Gain' */
  Read_compare_OutVolt = 0.001F * (real32_T)FSAC2021_V1_Running_B.Read_Compare;

  /* S-Function (ec55xx_asislb): '<S568>/Read_Brk_Liquid_Prs' */

  /* Read the ADC conversion result of the analog signal */
  Read_Brk_Liquid_Prs= ec_adc_readresult(22);

  /* S-Function (ec55xx_asislb): '<S568>/Read_EBS_Gas_Prs1' */

  /* Read the ADC conversion result of the analog signal */
  Read_EBS_Gas_Prs1= ec_adc_readresult(17);

  /* S-Function (ec55xx_asislb): '<S568>/Read_EBS_Gas_Prs2' */

  /* Read the ADC conversion result of the analog signal */
  Read_EBS_Gas_Prs2= ec_adc_readresult(27);

  /* S-Function (fcncallgen): '<S8>/Function-Call Generator1' incorporates:
   *  SubSystem: '<S9>/PCANB(BMS、DRIVE_MOTOR)'
   */

  /* S-Function (ec55xx_canreceiveslb): '<S402>/BMS_HCU_MAXT' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF18RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf18looprx= 0;
    FSAC2021_V1_Running_B.BMS_HCU_MAXT_o3= -1738391309;
    FSAC2021_V1_Running_B.BMS_HCU_MAXT_o5= 8;
    FSAC2021_V1_Running_B.BMS_HCU_MAXT_o2= ec_can_receive(1,18, CAN1BUF18RX);
    FSAC2021_V1_Running_B.BMS_HCU_MAXT_o4[0]= CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    FSAC2021_V1_Running_B.BMS_HCU_MAXT_o4[1]= CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    FSAC2021_V1_Running_B.BMS_HCU_MAXT_o4[2]= CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    FSAC2021_V1_Running_B.BMS_HCU_MAXT_o4[3]= CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    FSAC2021_V1_Running_B.BMS_HCU_MAXT_o4[4]= CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    FSAC2021_V1_Running_B.BMS_HCU_MAXT_o4[5]= CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    FSAC2021_V1_Running_B.BMS_HCU_MAXT_o4[6]= CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
    FSAC2021_V1_Running_B.BMS_HCU_MAXT_o4[7]= CAN1BUF18RX[can1buf18looprx];
    can1buf18looprx++;
  }

  /* Nothing to do for system: <S402>/BMS_HCU_MAXT1 */

  /* S-Function (ec55xx_canreceiveslb): '<S402>/BMS_HCU_MAXV' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF16RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf16looprx= 0;
    FSAC2021_V1_Running_B.BMS_HCU_MAXV_o3= -1738456845;
    FSAC2021_V1_Running_B.BMS_HCU_MAXV_o5= 8;
    FSAC2021_V1_Running_B.BMS_HCU_MAXV_o2= ec_can_receive(1,16, CAN1BUF16RX);
    FSAC2021_V1_Running_B.BMS_HCU_MAXV_o4[0]= CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    FSAC2021_V1_Running_B.BMS_HCU_MAXV_o4[1]= CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    FSAC2021_V1_Running_B.BMS_HCU_MAXV_o4[2]= CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    FSAC2021_V1_Running_B.BMS_HCU_MAXV_o4[3]= CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    FSAC2021_V1_Running_B.BMS_HCU_MAXV_o4[4]= CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    FSAC2021_V1_Running_B.BMS_HCU_MAXV_o4[5]= CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    FSAC2021_V1_Running_B.BMS_HCU_MAXV_o4[6]= CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
    FSAC2021_V1_Running_B.BMS_HCU_MAXV_o4[7]= CAN1BUF16RX[can1buf16looprx];
    can1buf16looprx++;
  }

  /* Nothing to do for system: <S402>/BMS_HCU_MAXV  */

  /* S-Function (ec55xx_canreceiveslb): '<S402>/BMS_RELAY' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF51RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf51looprx= 0;
    FSAC2021_V1_Running_B.BMS_RELAY_o3= -1738325773;
    FSAC2021_V1_Running_B.BMS_RELAY_o5= 8;
    FSAC2021_V1_Running_B.BMS_RELAY_o2= ec_can_receive(1,51, CAN1BUF51RX);
    FSAC2021_V1_Running_B.BMS_RELAY_o4[0]= CAN1BUF51RX[can1buf51looprx];
    can1buf51looprx++;
    FSAC2021_V1_Running_B.BMS_RELAY_o4[1]= CAN1BUF51RX[can1buf51looprx];
    can1buf51looprx++;
    FSAC2021_V1_Running_B.BMS_RELAY_o4[2]= CAN1BUF51RX[can1buf51looprx];
    can1buf51looprx++;
    FSAC2021_V1_Running_B.BMS_RELAY_o4[3]= CAN1BUF51RX[can1buf51looprx];
    can1buf51looprx++;
    FSAC2021_V1_Running_B.BMS_RELAY_o4[4]= CAN1BUF51RX[can1buf51looprx];
    can1buf51looprx++;
    FSAC2021_V1_Running_B.BMS_RELAY_o4[5]= CAN1BUF51RX[can1buf51looprx];
    can1buf51looprx++;
    FSAC2021_V1_Running_B.BMS_RELAY_o4[6]= CAN1BUF51RX[can1buf51looprx];
    can1buf51looprx++;
    FSAC2021_V1_Running_B.BMS_RELAY_o4[7]= CAN1BUF51RX[can1buf51looprx];
    can1buf51looprx++;
  }

  /* Nothing to do for system: <S402>/BMS_RELAY  */

  /* S-Function (ec55xx_canreceiveslb): '<S402>/BMS_HCU_POWER' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF52RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf52looprx= 0;
    FSAC2021_V1_Running_B.BMS_HCU_POWER_o3= -1738260237;
    FSAC2021_V1_Running_B.BMS_HCU_POWER_o5= 8;
    FSAC2021_V1_Running_B.BMS_HCU_POWER_o2= ec_can_receive(1,52, CAN1BUF52RX);
    FSAC2021_V1_Running_B.BMS_HCU_POWER_o4[0]= CAN1BUF52RX[can1buf52looprx];
    can1buf52looprx++;
    FSAC2021_V1_Running_B.BMS_HCU_POWER_o4[1]= CAN1BUF52RX[can1buf52looprx];
    can1buf52looprx++;
    FSAC2021_V1_Running_B.BMS_HCU_POWER_o4[2]= CAN1BUF52RX[can1buf52looprx];
    can1buf52looprx++;
    FSAC2021_V1_Running_B.BMS_HCU_POWER_o4[3]= CAN1BUF52RX[can1buf52looprx];
    can1buf52looprx++;
    FSAC2021_V1_Running_B.BMS_HCU_POWER_o4[4]= CAN1BUF52RX[can1buf52looprx];
    can1buf52looprx++;
    FSAC2021_V1_Running_B.BMS_HCU_POWER_o4[5]= CAN1BUF52RX[can1buf52looprx];
    can1buf52looprx++;
    FSAC2021_V1_Running_B.BMS_HCU_POWER_o4[6]= CAN1BUF52RX[can1buf52looprx];
    can1buf52looprx++;
    FSAC2021_V1_Running_B.BMS_HCU_POWER_o4[7]= CAN1BUF52RX[can1buf52looprx];
    can1buf52looprx++;
  }

  /* Nothing to do for system: <S402>/BMS_HCU_POWER  */

  /* S-Function (ec55xx_canreceiveslb): '<S402>/Motor_Current_Speed ' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF21RX[2]= { 0, 0 };

    uint8 can1buf21looprx= 0;
    FSAC2021_V1_Running_B.Motor_Current_Speed_o3= -2147413853;
    FSAC2021_V1_Running_B.Motor_Current_Speed_o5= 2;
    motor_node= ec_can_receive(1,21, CAN1BUF21RX);
    FSAC2021_V1_Running_B.Motor_Current_Speed_o4[0]= CAN1BUF21RX[can1buf21looprx];
    can1buf21looprx++;
    FSAC2021_V1_Running_B.Motor_Current_Speed_o4[1]= CAN1BUF21RX[can1buf21looprx];
    can1buf21looprx++;
  }

  /* Call the system: <S402>/MOTOR_CURRENT_SPEED */

  /* Output and update for function-call system: '<S402>/MOTOR_CURRENT_SPEED' */
  {
    real32_T u0;

    /* Saturate: '<S485>/Motor_Currt_Speed_sat' incorporates:
     *  Constant: '<S485>/Motor_Currt_Speedinput2_C'
     *  Product: '<S485>/Motor_Currt_Speedinput2_P'
     *  Sum: '<S485>/Motor_Currt_Speedinput2_Ad'
     */
    u0 = (real32_T)((FSAC2021_V1_Running_B.Motor_Current_Speed_o4[1] << 8) +
                    FSAC2021_V1_Running_B.Motor_Current_Speed_o4[0]);
    if (u0 > 2500.0F) {
      FSAC2021_V1_Running_B.Motor_Currt_Speed_sat = 2500.0F;
    } else {
      FSAC2021_V1_Running_B.Motor_Currt_Speed_sat = u0;
    }

    /* End of Saturate: '<S485>/Motor_Currt_Speed_sat' */
  }

  /* S-Function (ec55xx_canreceiveslb): '<S402>/BMS_ALARM' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF50RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf50looprx= 0;
    FSAC2021_V1_Running_B.BMS_ALARM_o3= -1738194701;
    FSAC2021_V1_Running_B.BMS_ALARM_o5= 8;
    FSAC2021_V1_Running_B.BMS_ALARM_o2= ec_can_receive(1,50, CAN1BUF50RX);
    FSAC2021_V1_Running_B.BMS_ALARM_o4[0]= CAN1BUF50RX[can1buf50looprx];
    can1buf50looprx++;
    FSAC2021_V1_Running_B.BMS_ALARM_o4[1]= CAN1BUF50RX[can1buf50looprx];
    can1buf50looprx++;
    FSAC2021_V1_Running_B.BMS_ALARM_o4[2]= CAN1BUF50RX[can1buf50looprx];
    can1buf50looprx++;
    FSAC2021_V1_Running_B.BMS_ALARM_o4[3]= CAN1BUF50RX[can1buf50looprx];
    can1buf50looprx++;
    FSAC2021_V1_Running_B.BMS_ALARM_o4[4]= CAN1BUF50RX[can1buf50looprx];
    can1buf50looprx++;
    FSAC2021_V1_Running_B.BMS_ALARM_o4[5]= CAN1BUF50RX[can1buf50looprx];
    can1buf50looprx++;
    FSAC2021_V1_Running_B.BMS_ALARM_o4[6]= CAN1BUF50RX[can1buf50looprx];
    can1buf50looprx++;
    FSAC2021_V1_Running_B.BMS_ALARM_o4[7]= CAN1BUF50RX[can1buf50looprx];
    can1buf50looprx++;
  }

  /* Call the system: <S402>/BMS_ALARM  */

  /* Output and update for function-call system: '<S402>/BMS_ALARM ' */

  /* DataTypeConversion: '<S480>/Data Type Conversion39' incorporates:
   *  ArithShift: '<S487>/ALM_LEAK_OC_S'
   *  DataTypeConversion: '<S487>/ALM_LEAK_OC_Convert'
   *  DataTypeConversion: '<S487>/ALM_LEAK_OCcv'
   *  S-Function (sfix_bitop): '<S487>/ALM_LEAK_OC_L'
   *  Saturate: '<S487>/ALM_LEAK_OC_sat'
   */
  FSAC2021_V1_Running_B.DataTypeConversion39 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_Running_B.BMS_ALARM_o4[4] & 96U) >> 5);

  /* DataTypeConversion: '<S480>/Data Type Conversion40' incorporates:
   *  ArithShift: '<S487>/ALM_PRECHRG_FAIL_S'
   *  DataTypeConversion: '<S487>/ALM_PRECHRG_FAIL_Convert'
   *  DataTypeConversion: '<S487>/ALM_PRECHRG_FAILcv'
   *  S-Function (sfix_bitop): '<S487>/ALM_PRECHRG_FAIL_L'
   *  Saturate: '<S487>/ALM_PRECHRG_FAIL_sat'
   */
  FSAC2021_V1_Running_B.DataTypeConversion40 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_Running_B.BMS_ALARM_o4[4] & 16U) >> 4);

  /* DataTypeConversion: '<S480>/Data Type Conversion41' incorporates:
   *  ArithShift: '<S487>/ALM_HVREL_FAIL_S'
   *  DataTypeConversion: '<S487>/ALM_HVREL_FAIL_Convert'
   *  DataTypeConversion: '<S487>/ALM_HVREL_FAILcv'
   *  S-Function (sfix_bitop): '<S487>/ALM_HVREL_FAIL_L'
   *  Saturate: '<S487>/ALM_HVREL_FAIL_sat'
   */
  FSAC2021_V1_Running_B.DataTypeConversion41 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_Running_B.BMS_ALARM_o4[5] & 128U) >> 7);

  /* DataTypeConversion: '<S480>/Data Type Conversion43' incorporates:
   *  ArithShift: '<S487>/ALM_DSCH_OCT_S'
   *  DataTypeConversion: '<S487>/ALM_DSCH_OCT_Convert'
   *  DataTypeConversion: '<S487>/ALM_DSCH_OCTcv'
   *  S-Function (sfix_bitop): '<S487>/ALM_DSCH_OCT_L'
   *  Saturate: '<S487>/ALM_DSCH_OCT_sat'
   */
  FSAC2021_V1_Running_B.DataTypeConversion43 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_Running_B.BMS_ALARM_o4[3] & 12U) >> 2);

  /* DataTypeConversion: '<S480>/Data Type Conversion47' incorporates:
   *  DataTypeConversion: '<S487>/ALM_BSU_OFFLINE_Convert'
   *  DataTypeConversion: '<S487>/ALM_BSU_OFFLINEcv'
   *  S-Function (sfix_bitop): '<S487>/ALM_BSU_OFFLINE_L'
   *  Saturate: '<S487>/ALM_BSU_OFFLINE_sat'
   */
  FSAC2021_V1_Running_B.DataTypeConversion47 = (uint8_T)(real32_T)
    (FSAC2021_V1_Running_B.BMS_ALARM_o4[3] & 3);

  /* DataTypeConversion: '<S480>/Data Type Conversion48' incorporates:
   *  ArithShift: '<S487>/ALM_BSU_FAULT_S'
   *  DataTypeConversion: '<S487>/ALM_BSU_FAULT_Convert'
   *  DataTypeConversion: '<S487>/ALM_BSU_FAULTcv'
   *  S-Function (sfix_bitop): '<S487>/ALM_BSU_FAULT_L'
   *  Saturate: '<S487>/ALM_BSU_FAULT_sat'
   */
  FSAC2021_V1_Running_B.DataTypeConversion48 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_Running_B.BMS_ALARM_o4[4] & 128U) >> 7);

  /* DataTypeConversion: '<S480>/Data Type Conversion49' incorporates:
   *  ArithShift: '<S487>/ALM_BMU_FAIL_S'
   *  DataTypeConversion: '<S487>/ALM_BMU_FAIL_Convert'
   *  DataTypeConversion: '<S487>/ALM_BMU_FAILcv'
   *  S-Function (sfix_bitop): '<S487>/ALM_BMU_FAIL_L'
   *  Saturate: '<S487>/ALM_BMU_FAIL_sat'
   */
  FSAC2021_V1_Running_B.DataTypeConversion49 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_Running_B.BMS_ALARM_o4[4] & 4U) >> 2);

  /* DataTypeConversion: '<S480>/Data Type Conversion50' incorporates:
   *  ArithShift: '<S487>/ALM_BATT_UC_S'
   *  DataTypeConversion: '<S487>/ALM_BATT_UC_Convert'
   *  DataTypeConversion: '<S487>/ALM_BATT_UCcv'
   *  S-Function (sfix_bitop): '<S487>/ALM_BATT_UC_L'
   *  Saturate: '<S487>/ALM_BATT_UC_sat'
   */
  FSAC2021_V1_Running_B.DataTypeConversion50 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_Running_B.BMS_ALARM_o4[2] & 12U) >> 2);

  /* DataTypeConversion: '<S480>/Data Type Conversion51' incorporates:
   *  ArithShift: '<S487>/ALM_BATT_OC_S'
   *  DataTypeConversion: '<S487>/ALM_BATT_OC_Convert'
   *  DataTypeConversion: '<S487>/ALM_BATT_OCcv'
   *  S-Function (sfix_bitop): '<S487>/ALM_BATT_OC_L'
   *  Saturate: '<S487>/ALM_BATT_OC_sat'
   */
  FSAC2021_V1_Running_B.DataTypeConversion51 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_Running_B.BMS_ALARM_o4[2] & 48U) >> 4);

  /* DataTypeConversion: '<S480>/Data Type Conversion52' incorporates:
   *  ArithShift: '<S487>/ALM_AUX_FAIL_S'
   *  DataTypeConversion: '<S487>/ALM_AUX_FAIL_Convert'
   *  DataTypeConversion: '<S487>/ALM_AUX_FAILcv'
   *  S-Function (sfix_bitop): '<S487>/ALM_AUX_FAIL_L'
   *  Saturate: '<S487>/ALM_AUX_FAIL_sat'
   */
  FSAC2021_V1_Running_B.DataTypeConversion52 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_Running_B.BMS_ALARM_o4[4] & 8U) >> 3);

  /* DataTypeConversion: '<S480>/Data Type Conversion53' incorporates:
   *  ArithShift: '<S487>/ALM_BATT_UV_S'
   *  DataTypeConversion: '<S487>/ALM_BATT_UV_Convert'
   *  DataTypeConversion: '<S487>/ALM_BATT_UVcv'
   *  S-Function (sfix_bitop): '<S487>/ALM_BATT_UV_L'
   *  Saturate: '<S487>/ALM_BATT_UV_sat'
   */
  FSAC2021_V1_Running_B.DataTypeConversion53 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_Running_B.BMS_ALARM_o4[2] & 192U) >> 6);

  /* DataTypeConversion: '<S480>/Data Type Conversion54' incorporates:
   *  DataTypeConversion: '<S487>/ALM_BATT_OV_Convert'
   *  DataTypeConversion: '<S487>/ALM_BATT_OVcv'
   *  S-Function (sfix_bitop): '<S487>/ALM_BATT_OV_L'
   *  Saturate: '<S487>/ALM_BATT_OV_sat'
   */
  FSAC2021_V1_Running_B.DataTypeConversion54 = (uint8_T)(real32_T)
    (FSAC2021_V1_Running_B.BMS_ALARM_o4[1] & 3);

  /* DataTypeConversion: '<S480>/Data Type Conversion55' incorporates:
   *  ArithShift: '<S487>/ALM_BATT_DT_S'
   *  DataTypeConversion: '<S487>/ALM_BATT_DT_Convert'
   *  DataTypeConversion: '<S487>/ALM_BATT_DTcv'
   *  S-Function (sfix_bitop): '<S487>/ALM_BATT_DT_L'
   *  Saturate: '<S487>/ALM_BATT_DT_sat'
   */
  FSAC2021_V1_Running_B.DataTypeConversion55 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_Running_B.BMS_ALARM_o4[1] & 12U) >> 2);

  /* DataTypeConversion: '<S480>/Data Type Conversion56' incorporates:
   *  ArithShift: '<S487>/ALM_BATT_DV_S'
   *  DataTypeConversion: '<S487>/ALM_BATT_DV_Convert'
   *  DataTypeConversion: '<S487>/ALM_BATT_DVcv'
   *  S-Function (sfix_bitop): '<S487>/ALM_BATT_DV_L'
   *  Saturate: '<S487>/ALM_BATT_DV_sat'
   */
  FSAC2021_V1_Running_B.DataTypeConversion56 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_Running_B.BMS_ALARM_o4[1] & 48U) >> 4);

  /* DataTypeConversion: '<S480>/Data Type Conversion57' incorporates:
   *  ArithShift: '<S487>/ALM_CELL_TBK_S'
   *  DataTypeConversion: '<S487>/ALM_CELL_TBK_Convert'
   *  DataTypeConversion: '<S487>/ALM_CELL_TBKcv'
   *  S-Function (sfix_bitop): '<S487>/ALM_CELL_TBK_L'
   *  Saturate: '<S487>/ALM_CELL_TBK_sat'
   */
  FSAC2021_V1_Running_B.DataTypeConversion57 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_Running_B.BMS_ALARM_o4[1] & 64U) >> 6);

  /* DataTypeConversion: '<S480>/Data Type Conversion58' incorporates:
   *  ArithShift: '<S487>/ALM_CELL_IBK_S'
   *  DataTypeConversion: '<S487>/ALM_CELL_IBK_Convert'
   *  DataTypeConversion: '<S487>/ALM_CELL_IBKcv'
   *  S-Function (sfix_bitop): '<S487>/ALM_CELL_IBK_L'
   *  Saturate: '<S487>/ALM_CELL_IBK_sat'
   */
  FSAC2021_V1_Running_B.DataTypeConversion58 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_Running_B.BMS_ALARM_o4[1] & 128U) >> 7);

  /* DataTypeConversion: '<S480>/Data Type Conversion59' incorporates:
   *  DataTypeConversion: '<S487>/ALM_CELL_UT_Convert'
   *  DataTypeConversion: '<S487>/ALM_CELL_UTcv'
   *  S-Function (sfix_bitop): '<S487>/ALM_CELL_UT_L'
   *  Saturate: '<S487>/ALM_CELL_UT_sat'
   */
  FSAC2021_V1_Running_B.DataTypeConversion59 = (uint8_T)(real32_T)
    (FSAC2021_V1_Running_B.BMS_ALARM_o4[0] & 3);

  /* DataTypeConversion: '<S480>/Data Type Conversion60' incorporates:
   *  ArithShift: '<S487>/ALM_CELL_OT_S'
   *  DataTypeConversion: '<S487>/ALM_CELL_OT_Convert'
   *  DataTypeConversion: '<S487>/ALM_CELL_OTcv'
   *  S-Function (sfix_bitop): '<S487>/ALM_CELL_OT_L'
   *  Saturate: '<S487>/ALM_CELL_OT_sat'
   */
  FSAC2021_V1_Running_B.DataTypeConversion60 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_Running_B.BMS_ALARM_o4[0] & 12U) >> 2);

  /* DataTypeConversion: '<S480>/Data Type Conversion61' incorporates:
   *  ArithShift: '<S487>/ALM_CELL_UV_S'
   *  DataTypeConversion: '<S487>/ALM_CELL_UV_Convert'
   *  DataTypeConversion: '<S487>/ALM_CELL_UVcv'
   *  S-Function (sfix_bitop): '<S487>/ALM_CELL_UV_L'
   *  Saturate: '<S487>/ALM_CELL_UV_sat'
   */
  FSAC2021_V1_Running_B.DataTypeConversion61 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_Running_B.BMS_ALARM_o4[0] & 48U) >> 4);

  /* DataTypeConversion: '<S480>/Data Type Conversion62' incorporates:
   *  ArithShift: '<S487>/ALM_CELL_OV_S'
   *  DataTypeConversion: '<S487>/ALM_CELL_OV_Convert'
   *  DataTypeConversion: '<S487>/ALM_CELL_OVcv'
   *  S-Function (sfix_bitop): '<S487>/ALM_CELL_OV_L'
   *  Saturate: '<S487>/ALM_CELL_OV_sat'
   */
  FSAC2021_V1_Running_B.DataTypeConversion62 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_Running_B.BMS_ALARM_o4[0] & 192U) >> 6);

  /* S-Function (fcncallgen): '<S8>/Function-Call Generator1' incorporates:
   *  SubSystem: '<S4>/Subsystem'
   */
  /* DataTypeConversion: '<S185>/Data Type Conversion' */
  light_blue = (rtb_RateTransition17_f != 0);

  /* S-Function (ec55xx_pdsslb): '<S185>/Blue_Pin' */

  /* Set level light_blue for the specified power driver switch */
  ec_gpio_write(195,light_blue);

  /* DataTypeConversion: '<S185>/Data Type Conversion1' */
  FSAC2021_V1_Running_B.DataTypeConversion1_h = (rtb_RateTransition18_o != 0);

  /* S-Function (ec55xx_pdsslb): '<S185>/Yellow_Pin' */

  /* Set level FSAC2021_V1_Running_B.DataTypeConversion1_h for the specified power driver switch */
  ec_gpio_write(198,FSAC2021_V1_Running_B.DataTypeConversion1_h);

  /* DataTypeConversion: '<S185>/Data Type Conversion2' */
  Buzzer_pin = (rtb_RateTransition19_j != 0);

  /* S-Function (ec55xx_pdsslb): '<S185>/Buzzer_Pin' */

  /* Set level Buzzer_pin for the specified power driver switch */
  ec_gpio_write(193,Buzzer_pin);

  /* DataTypeConversion: '<S185>/Data Type Conversion3' */
  Stafe_Relay_pin = rtb_RateTransition50;

  /* S-Function (ec55xx_pdsslb): '<S185>/Safety_Relay ' */

  /* Set level Stafe_Relay_pin for the specified power driver switch */
  ec_gpio_write(179,Stafe_Relay_pin);

  /* DataTypeConversion: '<S185>/Data Type Conversion4' */
  V48_relay = FSAC2021_V1_Running_B.UnitDelay4;

  /* S-Function (ec55xx_pdsslb): '<S185>/48V_Relay' */

  /* Set level V48_relay for the specified power driver switch */
  ec_gpio_write(181,V48_relay);

  /* DataTypeConversion: '<S185>/Data Type Conversion6' */
  R2D_Voltage = LogicalOperator_nw;

  /* S-Function (ec55xx_pdsslb): '<S185>/R2D_Pin' */

  /* Set level R2D_Voltage for the specified power driver switch */
  ec_gpio_write(197,R2D_Voltage);

  /* DataTypeConversion: '<S185>/Data Type Conversion5' */
  FSAC2021_V1_Running_B.DataTypeConversion5_i = (FSAC2021_V1_Running_B.VCU_Valve
    != 0);

  /* S-Function (ec55xx_pdsslb): '<S185>/VCU_Valve' */

  /* Set level FSAC2021_V1_Running_B.DataTypeConversion5_i for the specified power driver switch */
  ec_gpio_write(182,FSAC2021_V1_Running_B.DataTypeConversion5_i);

  /* DataTypeConversion: '<S185>/Data Type Conversion8' */
  IMD = (rtb_RateTransition47 != 0);

  /* S-Function (ec55xx_pdsslb): '<S185>/VCU_Valve1' */

  /* Set level IMD for the specified power driver switch */
  ec_gpio_write(190,IMD);

  /* S-Function (fcncallgen): '<S8>/Function-Call Generator1' incorporates:
   *  SubSystem: '<S2>/50ms_Duty'
   */
  /* DataTypeConversion: '<S185>/Data Type Conversion9' incorporates:
   *  SignalConversion: '<S63>/OutportBufferForEBS_Light_Sts'
   */
  EBS = (rtb_UnitDelay2 != 0);

  /* S-Function (ec55xx_pdsslb): '<S185>/VCU_Valve2' */

  /* Set level EBS for the specified power driver switch */
  ec_gpio_write(187,EBS);

  /* S-Function (fcncallgen): '<S8>/Function-Call Generator1' incorporates:
   *  SubSystem: '<S2>/50ms_Duty'
   */
  /* DataTypeConversion: '<S185>/Data Type Conversion10' incorporates:
   *  SignalConversion: '<S63>/OutportBufferForBMS_Light_Sts'
   */
  BMS_LIGHT = (rtb_RateTransition46_e != 0);

  /* S-Function (ec55xx_pdsslb): '<S185>/VCU_Valve3' */

  /* Set level BMS_LIGHT for the specified power driver switch */
  ec_gpio_write(188,BMS_LIGHT);

  /* S-Function (ec55xx_cantransmitslb): '<S13>/CANTransmit' */

  /*Transmit CAN message*/
  {
    uint8 CAN0BUF63TX[6];
    uint8 can0buf63looptx= 0;
    CAN0BUF63TX[can0buf63looptx]= FSAC2021_V1_Running_B.MOTEC_CONTROL.Conv1;
    can0buf63looptx++;
    CAN0BUF63TX[can0buf63looptx]= FSAC2021_V1_Running_B.MOTEC_CONTROL.Conv2;
    can0buf63looptx++;
    CAN0BUF63TX[can0buf63looptx]= FSAC2021_V1_Running_B.MOTEC_CONTROL.Conv3;
    can0buf63looptx++;
    CAN0BUF63TX[can0buf63looptx]= FSAC2021_V1_Running_B.MOTEC_CONTROL.Conv4;
    can0buf63looptx++;
    CAN0BUF63TX[can0buf63looptx]= FSAC2021_V1_Running_B.MOTEC_CONTROL.Conv5;
    can0buf63looptx++;
    CAN0BUF63TX[can0buf63looptx]= FSAC2021_V1_Running_B.MOTEC_CONTROL.Conv6;
    can0buf63looptx++;
    Metoc_Move= ec_can_transmit(0, 63, 0, 513U, 6, CAN0BUF63TX);
  }

  /* S-Function (ec55xx_cantransmitslb): '<S13>/CANTransmit1' */

  /*Transmit CAN message*/
  {
    uint8 CAN0BUF62TX[2];
    uint8 can0buf62looptx= 0;
    CAN0BUF62TX[can0buf62looptx]= FSAC2021_V1_Running_B.Conv1_p;
    can0buf62looptx++;
    CAN0BUF62TX[can0buf62looptx]= FSAC2021_V1_Running_B.Conv2_l;
    can0buf62looptx++;
    MNT_SEND= ec_can_transmit(0, 62, 0, 0U, 2, CAN0BUF62TX);
  }

  /* S-Function (ec55xx_cantransmitslb): '<S13>/CANTransmit2' */

  /*Transmit CAN message*/
  {
    uint8 CAN0BUF61TX[6];
    uint8 can0buf61looptx= 0;
    CAN0BUF61TX[can0buf61looptx]= FSAC2021_V1_Running_B.Conv1;
    can0buf61looptx++;
    CAN0BUF61TX[can0buf61looptx]= FSAC2021_V1_Running_B.Conv2;
    can0buf61looptx++;
    CAN0BUF61TX[can0buf61looptx]= FSAC2021_V1_Running_B.Conv3;
    can0buf61looptx++;
    CAN0BUF61TX[can0buf61looptx]= FSAC2021_V1_Running_B.Conv4;
    can0buf61looptx++;
    CAN0BUF61TX[can0buf61looptx]= FSAC2021_V1_Running_B.Conv5;
    can0buf61looptx++;
    CAN0BUF61TX[can0buf61looptx]= FSAC2021_V1_Running_B.Conv6;
    can0buf61looptx++;
    ENCODER_SEND= ec_can_transmit(0, 61, 0, 1537U, 6, CAN0BUF61TX);
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion11' */
  rtb_RateTransition11 = FSAC2021_V1_Running_B.Encoder_Msg_Data[0];

  /* DataTypeConversion: '<S13>/Data Type Conversion12' */
  rtb_Drive_Speed_Control_L = FSAC2021_V1_Running_B.Encoder_Msg_Data[1];

  /* DataTypeConversion: '<S13>/Data Type Conversion13' */
  rtb_DataTypeConversion13 = FSAC2021_V1_Running_B.Encoder_Msg_Data[2];

  /* DataTypeConversion: '<S13>/Data Type Conversion14' */
  rtb_DataTypeConversion14 = FSAC2021_V1_Running_B.Encoder_Msg_Data[3];

  /* DataTypeConversion: '<S13>/Data Type Conversion16' */
  rtb_DataTypeConversion16 = FSAC2021_V1_Running_B.Encoder_Msg_Data[5];

  /* Outputs for Atomic SubSystem: '<S13>/Brk_Mtr_Enbale' */

  /* S-Function (ec55xx_cantransmitslb): '<S35>/CANTransmit' */

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

  /* End of Outputs for SubSystem: '<S13>/Brk_Mtr_Enbale' */

  /* RateTransition: '<S2>/Rate Transition15' */
  rtb_UnitDelay5 = FSAC2021_V1_Running_DW.RateTransition15_Buffer0_e;

  /* S-Function (ec55xx_canreceiveslb): '<S401>/AMI1' */

  /* Receive CAN message */
  {
    uint8 CAN0BUF26RX[1]= { 0 };

    uint8 can0buf26looprx= 0;
    FSAC2021_V1_Running_B.AMI1_o3= 1168;
    FSAC2021_V1_Running_B.AMI1_o5= 1;
    AMI_HEART= ec_can_receive(0,26, CAN0BUF26RX);
    FSAC2021_V1_Running_B.AMI1_o4= CAN0BUF26RX[can0buf26looprx];
    can0buf26looprx++;
  }

  /* Nothing to do for system: <S401>/Heartt */

  /* RateTransition: '<S3>/RateTransition21' */
  if (FSAC2021_V1_Running_M->Timing.RateInteraction.TID6_7) {
    FSAC2021_V1_Running_B.RateTransition21 =
      FSAC2021_V1_Running_B.DataTypeConversion51;

    /* RateTransition: '<S3>/RateTransition17' */
    FSAC2021_V1_Running_B.RateTransition17 =
      FSAC2021_V1_Running_B.DataTypeConversion52;

    /* RateTransition: '<S3>/RateTransition16' */
    FSAC2021_V1_Running_B.RateTransition16 =
      FSAC2021_V1_Running_B.DataTypeConversion53;

    /* RateTransition: '<S3>/RateTransition2' */
    FSAC2021_V1_Running_B.RateTransition2 =
      FSAC2021_V1_Running_B.DataTypeConversion54;

    /* RateTransition: '<S3>/RateTransition18' */
    FSAC2021_V1_Running_B.RateTransition18 =
      FSAC2021_V1_Running_B.DataTypeConversion55;

    /* RateTransition: '<S3>/RateTransition19' */
    FSAC2021_V1_Running_B.RateTransition19 =
      FSAC2021_V1_Running_B.DataTypeConversion56;

    /* RateTransition: '<S3>/RateTransition20' */
    FSAC2021_V1_Running_B.RateTransition20 =
      FSAC2021_V1_Running_B.DataTypeConversion57;

    /* RateTransition: '<S3>/RateTransition9' */
    FSAC2021_V1_Running_B.RateTransition9 =
      FSAC2021_V1_Running_B.DataTypeConversion58;

    /* RateTransition: '<S3>/RateTransition7' */
    FSAC2021_V1_Running_B.RateTransition7 =
      FSAC2021_V1_Running_B.DataTypeConversion59;

    /* RateTransition: '<S3>/RateTransition6' */
    FSAC2021_V1_Running_B.RateTransition6 =
      FSAC2021_V1_Running_B.DataTypeConversion60;

    /* RateTransition: '<S3>/RateTransition11' */
    FSAC2021_V1_Running_B.RateTransition11 =
      FSAC2021_V1_Running_B.DataTypeConversion61;

    /* RateTransition: '<S3>/RateTransition8' */
    FSAC2021_V1_Running_B.RateTransition8 =
      FSAC2021_V1_Running_B.DataTypeConversion62;

    /* RateTransition: '<S3>/RateTransition10' */
    FSAC2021_V1_Running_B.RateTransition10 =
      FSAC2021_V1_Running_B.DataTypeConversion50;

    /* RateTransition: '<S3>/RateTransition3' */
    FSAC2021_V1_Running_B.RateTransition3 =
      FSAC2021_V1_Running_B.DataTypeConversion40;

    /* RateTransition: '<S3>/RateTransition13' */
    FSAC2021_V1_Running_B.RateTransition13 =
      FSAC2021_V1_Running_B.DataTypeConversion39;

    /* RateTransition: '<S3>/RateTransition12' */
    FSAC2021_V1_Running_B.RateTransition12 =
      FSAC2021_V1_Running_B.DataTypeConversion41;

    /* RateTransition: '<S3>/RateTransition5' */
    FSAC2021_V1_Running_B.RateTransition5 =
      FSAC2021_V1_Running_B.DataTypeConversion43;

    /* RateTransition: '<S3>/RateTransition4' */
    FSAC2021_V1_Running_B.RateTransition4 =
      FSAC2021_V1_Running_B.DataTypeConversion47;

    /* RateTransition: '<S3>/RateTransition14' */
    FSAC2021_V1_Running_B.RateTransition14 =
      FSAC2021_V1_Running_B.DataTypeConversion48;

    /* RateTransition: '<S3>/RateTransition15' */
    FSAC2021_V1_Running_B.RateTransition15_b =
      FSAC2021_V1_Running_B.DataTypeConversion49;

    /* RateTransition: '<S3>/RateTransition23' */
    FSAC2021_V1_Running_B.RateTransition23 = rtb_RateTransition24_e;

    /* RateTransition: '<S3>/RateTransition1' */
    FSAC2021_V1_Running_B.RateTransition1 = Read_compare_OutVolt;

    /* RateTransition: '<S3>/RateTransition27' */
    ASMS_VALUE = FSAC2021_V1_Running_B.DataTypeConversion4_f;
  }

  /* End of RateTransition: '<S3>/RateTransition21' */

  /* RateTransition: '<S3>/Rate Transition44' */
  rtb_RateTransition24_e = FSAC2021_V1_Running_DW.RateTransition44_Buffer0;

  /* S-Function (fcncallgen): '<S379>/50ms' incorporates:
   *  SubSystem: '<S379>/daq50ms'
   */

  /* S-Function (ec55xx_ccpslb1): '<S392>/CCPDAQ' */
  ccpDaq(2);

  /* S-Function (ec55xx_canreceiveslb): '<S401>/AMI' */

  /* Receive CAN message */
  {
    uint8 CAN0BUF16RX[1]= { 0 };

    uint8 can0buf16looprx= 0;
    FSAC2021_V1_Running_B.AMI_o3= 1169;
    FSAC2021_V1_Running_B.AMI_o5= 1;
    FSAC2021_V1_Running_B.AMI_o2= ec_can_receive(0,16, CAN0BUF16RX);
    FSAC2021_V1_Running_B.AMI_o4= CAN0BUF16RX[can0buf16looprx];
    can0buf16looprx++;
  }

  /* Call the system: <S401>/AMI_DUTY */

  /* Output and update for function-call system: '<S401>/AMI_DUTY' */

  /* Saturate: '<S413>/assi_status_sat' incorporates:
   *  DataTypeConversion: '<S413>/assi_status_Convert'
   *  DataTypeConversion: '<S413>/assi_statuscv'
   */
  FSAC2021_V1_Running_B.assi_status_sat = FSAC2021_V1_Running_B.AMI_o4;

  /* DataTypeConversion: '<S401>/Data Type Conversion' */
  AMI = (uint8_T)FSAC2021_V1_Running_B.assi_status_sat;

  /* Update for UnitDelay: '<S1>/Unit Delay4' */
  FSAC2021_V1_Running_DW.UnitDelay4_DSTATE = rtb_RateTransition46;

  /* Update for RateTransition: '<S1>/Rate Transition13' */
  FSAC2021_V1_Running_DW.RateTransition13_Buffer0 =
    FSAC2021_V1_Running_B.Motor_Currt_Speed_sat;

  /* Update for RateTransition: '<S2>/Rate Transition41' */
  FSAC2021_V1_Running_DW.RateTransition41_Buffer0 =
    FSAC2021_V1_Running_B.ASSI_State;

  /* Update for UnitDelay: '<S2>/Unit Delay4' */
  FSAC2021_V1_Running_DW.UnitDelay4_DSTATE_i = LogicalOperator_p;

  /* Update for UnitDelay: '<S2>/Unit Delay6' */
  FSAC2021_V1_Running_DW.UnitDelay6_DSTATE = ipc_strr;

  /* Update for RateTransition: '<S5>/Rate Transition18' */
  FSAC2021_V1_Running_DW.RateTransition18_Buffer0 =
    FSAC2021_V1_Running_B.Read_RL_WhlSpd;

  /* Update for RateTransition: '<S5>/Rate Transition19' */
  FSAC2021_V1_Running_DW.RateTransition19_Buffer0 =
    FSAC2021_V1_Running_B.Read_RR_WhlSpd;

  /* Update for RateTransition: '<S5>/Rate Transition25' */
  FSAC2021_V1_Running_DW.RateTransition25_Buffer0 =
    FSAC2021_V1_Running_B.Read_RL_WhlSpd;

  /* Update for RateTransition: '<S5>/Rate Transition26' */
  FSAC2021_V1_Running_DW.RateTransition26_Buffer0 =
    FSAC2021_V1_Running_B.Read_RR_WhlSpd;

  /* Update for RateTransition: '<S5>/Rate Transition22' */
  FSAC2021_V1_Running_DW.RateTransition22_Buffer0 = Read_Right_Acc_Disp1;

  /* Update for RateTransition: '<S5>/Rate Transition23' */
  FSAC2021_V1_Running_DW.RateTransition23_Buffer0 = Read_Brk_Liquid_Prs;

  /* Update for RateTransition: '<S5>/Rate Transition14' */
  FSAC2021_V1_Running_DW.RateTransition14_Buffer0 = Read_EBS_Gas_Prs1;

  /* Update for RateTransition: '<S5>/Rate Transition24' */
  FSAC2021_V1_Running_DW.RateTransition24_Buffer0 = Read_EBS_Gas_Prs2;

  /* Update for UnitDelay: '<S9>/Unit Delay5' */
  FSAC2021_V1_Running_DW.UnitDelay5_DSTATE_e = AMI;

  /* Update for UnitDelay: '<S2>/Unit Delay3' */
  FSAC2021_V1_Running_DW.UnitDelay3_DSTATE = rtb_UnitDelay5;

  /* Update for UnitDelay: '<S3>/Unit Delay2' */
  FSAC2021_V1_Running_DW.UnitDelay2_DSTATE_h = rtb_RateTransition24_e;

  /* Update for UnitDelay: '<S2>/Unit Delay7' */
  FSAC2021_V1_Running_DW.UnitDelay7_DSTATE = FSAC2021_V1_Running_B.Original_Flag;

  /* Update for UnitDelay: '<S13>/Unit Delay10' */
  FSAC2021_V1_Running_DW.UnitDelay10_DSTATE =
    FSAC2021_V1_Running_B.NMT_nodeorder;

  /* Update for UnitDelay: '<S13>/Unit Delay9' */
  FSAC2021_V1_Running_DW.UnitDelay9_DSTATE = FSAC2021_V1_Running_B.NMT_nodectrl;

  /* Update for UnitDelay: '<S13>/Unit Delay11' */
  FSAC2021_V1_Running_DW.UnitDelay11_DSTATE = rtb_RateTransition11;

  /* Update for UnitDelay: '<S13>/Unit Delay12' */
  FSAC2021_V1_Running_DW.UnitDelay12_DSTATE = (real32_T)
    rtb_Drive_Speed_Control_L;

  /* Update for UnitDelay: '<S13>/Unit Delay13' */
  FSAC2021_V1_Running_DW.UnitDelay13_DSTATE = (real32_T)rtb_DataTypeConversion13;

  /* Update for UnitDelay: '<S13>/Unit Delay14' */
  FSAC2021_V1_Running_DW.UnitDelay14_DSTATE = (real32_T)rtb_DataTypeConversion14;

  /* Update for UnitDelay: '<S13>/Unit Delay15' */
  FSAC2021_V1_Running_DW.UnitDelay15_DSTATE =
    FSAC2021_V1_Running_B.Encoder_Msg_Data[4];

  /* Update for UnitDelay: '<S13>/Unit Delay16' */
  FSAC2021_V1_Running_DW.UnitDelay16_DSTATE = (real32_T)rtb_DataTypeConversion16;

  /* Update for UnitDelay: '<S13>/Unit Delay6' */
  FSAC2021_V1_Running_DW.UnitDelay6_DSTATE_n = FSAC2021_V1_Running_B.Fault_Resrt;

  /* Update for UnitDelay: '<S13>/Unit Delay8' */
  FSAC2021_V1_Running_DW.UnitDelay8_DSTATE = FSAC2021_V1_Running_B.Position_set;

  /* Update for UnitDelay: '<S13>/Unit Delay4' */
  FSAC2021_V1_Running_DW.UnitDelay4_DSTATE_g =
    FSAC2021_V1_Running_B.New_Set_Point_Ctrl;

  /* Update for UnitDelay: '<S13>/Unit Delay7' */
  FSAC2021_V1_Running_DW.UnitDelay7_DSTATE_g = FSAC2021_V1_Running_B.Halt_Ctrl;

  /* Update for UnitDelay: '<S13>/Unit Delay5' */
  FSAC2021_V1_Running_DW.UnitDelay5_DSTATE_p =
    FSAC2021_V1_Running_B.Abs_or_Rel_Ctrl;

  /* Update for UnitDelay: '<S13>/Unit Delay' */
  FSAC2021_V1_Running_DW.UnitDelay_DSTATE = FSAC2021_V1_Running_B.Switch_On_Ctrl;

  /* Update for UnitDelay: '<S13>/Unit Delay2' */
  FSAC2021_V1_Running_DW.UnitDelay2_DSTATE_o =
    FSAC2021_V1_Running_B.Quick_Stop_Ctrl;

  /* Update for UnitDelay: '<S13>/Unit Delay1' */
  FSAC2021_V1_Running_DW.UnitDelay1_DSTATE_n =
    FSAC2021_V1_Running_B.Enable_Voltage_Ctrl;

  /* Update for UnitDelay: '<S13>/Unit Delay3' */
  FSAC2021_V1_Running_DW.UnitDelay3_DSTATE_p =
    FSAC2021_V1_Running_B.Enable_Operation_Ctrl;

  /* Update absolute time */
  /* The "clockTick6" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.05, which is the step size
   * of the task. Size of "clockTick6" ensures timer will not overflow during the
   * application lifespan selected.
   */
  FSAC2021_V1_Running_M->Timing.clockTick6++;
}

/* Model step function for TID7 */
void FSAC2021_V1_Running_step7(void)   /* Sample time: [0.1s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_DataTypeConversion1;
  uint8_T rtb_RateTransition32;
  uint8_T rtb_RateTransition31;
  uint8_T rtb_RateTransition42;
  uint8_T rtb_RateTransition41;
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
  uint16_T rtb_RateTransition36;
  uint16_T rtb_RateTransition37;
  uint16_T rtb_RateTransition38;
  real_T rtb_RateTransition17;
  real_T rtb_RateTransition18;
  real_T rtb_RateTransition19;
  real_T rtb_RateTransition20;
  real_T rtb_RateTransition21;
  real_T rtb_RateTransition22;
  real_T rtb_RateTransition23;
  boolean_T rtb_RateTransition43;
  boolean_T rtb_Compare_hp;
  boolean_T rtb_Compare_b;
  boolean_T rtb_LogicalOperator;
  int32_T rtb_Switch;
  uint8_T EBS_Failure_Flag;
  int32_T rtb_RateTransition43_0;

  /* RateTransition: '<S3>/Rate Transition34' */
  rtb_RateTransition34 = Read_Lft_Acc_Disp;

  /* RateTransition: '<S3>/Rate Transition35' */
  rtb_RateTransition35 = Read_Right_Acc_Disp1;

  /* RateTransition: '<S3>/Rate Transition36' */
  rtb_RateTransition36 = Read_Brk_Liquid_Prs;

  /* RateTransition: '<S3>/Rate Transition37' */
  rtb_RateTransition37 = Read_EBS_Gas_Prs1;

  /* RateTransition: '<S3>/Rate Transition38' */
  rtb_RateTransition38 = Read_EBS_Gas_Prs2;

  /* S-Function (ec55xx_canreceiveslb): '<S401>/Str_Error' */

  /* Receive CAN message */
  {
    uint8 CAN0BUF4RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can0buf4looprx= 0;
    FSAC2021_V1_Running_B.Str_Error_o3= 129;
    FSAC2021_V1_Running_B.Str_Error_o5= 8;
    FSAC2021_V1_Running_B.Str_Error_o2= ec_can_receive(0,4, CAN0BUF4RX);
    FSAC2021_V1_Running_B.Str_Error_o4[0]= CAN0BUF4RX[can0buf4looprx];
    can0buf4looprx++;
    FSAC2021_V1_Running_B.Str_Error_o4[1]= CAN0BUF4RX[can0buf4looprx];
    can0buf4looprx++;
    FSAC2021_V1_Running_B.Str_Error_o4[2]= CAN0BUF4RX[can0buf4looprx];
    can0buf4looprx++;
    FSAC2021_V1_Running_B.Str_Error_o4[3]= CAN0BUF4RX[can0buf4looprx];
    can0buf4looprx++;
    FSAC2021_V1_Running_B.Str_Error_o4[4]= CAN0BUF4RX[can0buf4looprx];
    can0buf4looprx++;
    FSAC2021_V1_Running_B.Str_Error_o4[5]= CAN0BUF4RX[can0buf4looprx];
    can0buf4looprx++;
    FSAC2021_V1_Running_B.Str_Error_o4[6]= CAN0BUF4RX[can0buf4looprx];
    can0buf4looprx++;
    FSAC2021_V1_Running_B.Str_Error_o4[7]= CAN0BUF4RX[can0buf4looprx];
    can0buf4looprx++;
  }

  /* Call the system: <S401>/Str_Emergency  */

  /* Output and update for function-call system: '<S401>/Str_Emergency ' */

  /* DataTypeConversion: '<S427>/Data Type Conversion22' incorporates:
   *  ArithShift: '<S463>/Str_UnderVolt_Warning_S'
   *  DataTypeConversion: '<S463>/Str_UnderVolt_Warning_Convert'
   *  DataTypeConversion: '<S463>/Str_UnderVolt_Warningcv'
   *  S-Function (sfix_bitop): '<S463>/Str_UnderVolt_Warning_L'
   *  Saturate: '<S463>/Str_UnderVolt_Warning_sat'
   */
  FSAC2021_V1_Running_B.DataTypeConversion22_b = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_Running_B.Str_Error_o4[1] & 8U) >> 3);

  /* DataTypeConversion: '<S427>/Data Type Conversion23' incorporates:
   *  DataTypeConversion: '<S463>/Str_System_Error_Convert'
   *  DataTypeConversion: '<S463>/Str_System_Errorcv'
   *  S-Function (sfix_bitop): '<S463>/Str_System_Error_L'
   *  Saturate: '<S463>/Str_System_Error_sat'
   */
  FSAC2021_V1_Running_B.DataTypeConversion23_i = (uint8_T)(real32_T)
    (FSAC2021_V1_Running_B.Str_Error_o4[1] & 1);

  /* DataTypeConversion: '<S427>/Data Type Conversion24' incorporates:
   *  ArithShift: '<S463>/Str_Spd_Over_Alam_S'
   *  DataTypeConversion: '<S463>/Str_Spd_Over_Alam_Convert'
   *  DataTypeConversion: '<S463>/Str_Spd_Over_Alamcv'
   *  S-Function (sfix_bitop): '<S463>/Str_Spd_Over_Alam_L'
   *  Saturate: '<S463>/Str_Spd_Over_Alam_sat'
   */
  FSAC2021_V1_Running_B.DataTypeConversion24_f = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_Running_B.Str_Error_o4[0] & 16U) >> 4);

  /* DataTypeConversion: '<S427>/Data Type Conversion25' incorporates:
   *  ArithShift: '<S463>/Str_PwrMod_TempHigh_Warning_S'
   *  DataTypeConversion: '<S463>/Str_PwrMod_TempHigh_Warning_Convert'
   *  DataTypeConversion: '<S463>/Str_PwrMod_TempHigh_Warningcv'
   *  S-Function (sfix_bitop): '<S463>/Str_PwrMod_TempHigh_Warning_L'
   *  Saturate: '<S463>/Str_PwrMod_TempHigh_Warning_sat'
   */
  FSAC2021_V1_Running_B.DataTypeConversion25 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_Running_B.Str_Error_o4[0] & 4U) >> 2);

  /* DataTypeConversion: '<S427>/Data Type Conversion26' incorporates:
   *  ArithShift: '<S463>/Str_PwrMod_TempHigh_Alarm_S'
   *  DataTypeConversion: '<S463>/Str_PwrMod_TempHigh_Alarm_Convert'
   *  DataTypeConversion: '<S463>/Str_PwrMod_TempHigh_Alarmcv'
   *  S-Function (sfix_bitop): '<S463>/Str_PwrMod_TempHigh_Alarm_L'
   *  Saturate: '<S463>/Str_PwrMod_TempHigh_Alarm_sat'
   */
  FSAC2021_V1_Running_B.DataTypeConversion26 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_Running_B.Str_Error_o4[0] & 8U) >> 3);

  /* DataTypeConversion: '<S427>/Data Type Conversion27' incorporates:
   *  ArithShift: '<S463>/Str_Para_Error_S'
   *  DataTypeConversion: '<S463>/Str_Para_Error_Convert'
   *  DataTypeConversion: '<S463>/Str_Para_Errorcv'
   *  S-Function (sfix_bitop): '<S463>/Str_Para_Error_L'
   *  Saturate: '<S463>/Str_Para_Error_sat'
   */
  FSAC2021_V1_Running_B.DataTypeConversion27 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_Running_B.Str_Error_o4[1] & 4U) >> 2);

  /* DataTypeConversion: '<S427>/Data Type Conversion28' incorporates:
   *  ArithShift: '<S463>/Str_Overvolt_Warning_S'
   *  DataTypeConversion: '<S463>/Str_Overvolt_Warning_Convert'
   *  DataTypeConversion: '<S463>/Str_Overvolt_Warningcv'
   *  S-Function (sfix_bitop): '<S463>/Str_Overvolt_Warning_L'
   *  Saturate: '<S463>/Str_Overvolt_Warning_sat'
   */
  FSAC2021_V1_Running_B.DataTypeConversion28 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_Running_B.Str_Error_o4[1] & 16U) >> 4);

  /* DataTypeConversion: '<S427>/Data Type Conversion29' incorporates:
   *  ArithShift: '<S463>/Str_Over_TopCurr_S'
   *  DataTypeConversion: '<S463>/Str_Over_TopCurr_Convert'
   *  DataTypeConversion: '<S463>/Str_Over_TopCurrcv'
   *  S-Function (sfix_bitop): '<S463>/Str_Over_TopCurr_L'
   *  Saturate: '<S463>/Str_Over_TopCurr_sat'
   */
  FSAC2021_V1_Running_B.DataTypeConversion29 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_Running_B.Str_Error_o4[1] & 64U) >> 6);

  /* DataTypeConversion: '<S427>/Data Type Conversion30' incorporates:
   *  ArithShift: '<S463>/Str_Over_SpdError_S'
   *  DataTypeConversion: '<S463>/Str_Over_SpdError_Convert'
   *  DataTypeConversion: '<S463>/Str_Over_SpdErrorcv'
   *  S-Function (sfix_bitop): '<S463>/Str_Over_SpdError_L'
   *  Saturate: '<S463>/Str_Over_SpdError_sat'
   */
  FSAC2021_V1_Running_B.DataTypeConversion30 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_Running_B.Str_Error_o4[0] & 2U) >> 1);

  /* DataTypeConversion: '<S427>/Data Type Conversion31' incorporates:
   *  ArithShift: '<S463>/Str_Over_PosError_S'
   *  DataTypeConversion: '<S463>/Str_Over_PosError_Convert'
   *  DataTypeConversion: '<S463>/Str_Over_PosErrorcv'
   *  S-Function (sfix_bitop): '<S463>/Str_Over_PosError_L'
   *  Saturate: '<S463>/Str_Over_PosError_sat'
   */
  FSAC2021_V1_Running_B.DataTypeConversion31 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_Running_B.Str_Error_o4[1] & 128U) >> 7);

  /* DataTypeConversion: '<S427>/Data Type Conversion32' incorporates:
   *  ArithShift: '<S463>/Str_Limit_Pos_Alarm_S'
   *  DataTypeConversion: '<S463>/Str_Limit_Pos_Alarm_Convert'
   *  DataTypeConversion: '<S463>/Str_Limit_Pos_Alarmcv'
   *  S-Function (sfix_bitop): '<S463>/Str_Limit_Pos_Alarm_L'
   *  Saturate: '<S463>/Str_Limit_Pos_Alarm_sat'
   */
  FSAC2021_V1_Running_B.DataTypeConversion32 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_Running_B.Str_Error_o4[0] & 128U) >> 7);

  /* DataTypeConversion: '<S427>/Data Type Conversion33' incorporates:
   *  ArithShift: '<S463>/Str_I2t_Warning_S'
   *  DataTypeConversion: '<S463>/Str_I2t_Warning_Convert'
   *  DataTypeConversion: '<S463>/Str_I2t_Warningcv'
   *  S-Function (sfix_bitop): '<S463>/Str_I2t_Warning_L'
   *  Saturate: '<S463>/Str_I2t_Warning_sat'
   */
  FSAC2021_V1_Running_B.DataTypeConversion33 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_Running_B.Str_Error_o4[1] & 2U) >> 1);

  /* DataTypeConversion: '<S427>/Data Type Conversion34' incorporates:
   *  ArithShift: '<S463>/Str_I2t_Alarm_S'
   *  DataTypeConversion: '<S463>/Str_I2t_Alarm_Convert'
   *  DataTypeConversion: '<S463>/Str_I2t_Alarmcv'
   *  S-Function (sfix_bitop): '<S463>/Str_I2t_Alarm_L'
   *  Saturate: '<S463>/Str_I2t_Alarm_sat'
   */
  FSAC2021_V1_Running_B.DataTypeConversion34 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_Running_B.Str_Error_o4[1] & 32U) >> 5);

  /* DataTypeConversion: '<S427>/Data Type Conversion35' incorporates:
   *  ArithShift: '<S463>/Str_Flash_Error_S'
   *  DataTypeConversion: '<S463>/Str_Flash_Error_Convert'
   *  DataTypeConversion: '<S463>/Str_Flash_Errorcv'
   *  S-Function (sfix_bitop): '<S463>/Str_Flash_Error_L'
   *  Saturate: '<S463>/Str_Flash_Error_sat'
   */
  FSAC2021_V1_Running_B.DataTypeConversion35 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_Running_B.Str_Error_o4[0] & 32U) >> 5);

  /* DataTypeConversion: '<S427>/Data Type Conversion36' incorporates:
   *  DataTypeConversion: '<S463>/Str_Encoder_Error_Convert'
   *  DataTypeConversion: '<S463>/Str_Encoder_Errorcv'
   *  S-Function (sfix_bitop): '<S463>/Str_Encoder_Error_L'
   *  Saturate: '<S463>/Str_Encoder_Error_sat'
   */
  FSAC2021_V1_Running_B.DataTypeConversion36 = (uint8_T)(real32_T)
    (FSAC2021_V1_Running_B.Str_Error_o4[0] & 1);

  /* DataTypeConversion: '<S427>/Data Type Conversion37' incorporates:
   *  ArithShift: '<S463>/Str_Curr_Error_Fault_S'
   *  DataTypeConversion: '<S463>/Str_Curr_Error_Fault_Convert'
   *  DataTypeConversion: '<S463>/Str_Curr_Error_Faultcv'
   *  S-Function (sfix_bitop): '<S463>/Str_Curr_Error_Fault_L'
   *  Saturate: '<S463>/Str_Curr_Error_Fault_sat'
   */
  FSAC2021_V1_Running_B.DataTypeConversion37 = (uint8_T)(real32_T)(int32_T)
    ((FSAC2021_V1_Running_B.Str_Error_o4[0] & 64U) >> 6);

  /* RateTransition: '<S3>/Rate Transition17' */
  rtb_RateTransition17 = FSAC2021_V1_Running_B.DataTypeConversion10;

  /* RateTransition: '<S3>/Rate Transition18' */
  rtb_RateTransition18 = FSAC2021_V1_Running_B.DataTypeConversion11;

  /* RateTransition: '<S3>/Rate Transition19' */
  rtb_RateTransition19 = FSAC2021_V1_Running_B.DataTypeConversion12;

  /* RateTransition: '<S3>/Rate Transition20' */
  rtb_RateTransition20 = FSAC2021_V1_Running_B.DataTypeConversion17;

  /* RateTransition: '<S3>/Rate Transition21' */
  rtb_RateTransition21 = FSAC2021_V1_Running_B.DataTypeConversion18;

  /* RateTransition: '<S3>/Rate Transition22' */
  rtb_RateTransition22 = FSAC2021_V1_Running_B.DataTypeConversion20;

  /* RateTransition: '<S3>/Rate Transition23' */
  rtb_RateTransition23 = FSAC2021_V1_Running_B.DataTypeConversion21;

  /* RateTransition: '<S3>/Rate Transition32' */
  rtb_RateTransition32 = brake_node;

  /* RateTransition: '<S3>/Rate Transition31' */
  rtb_RateTransition31 = AMI_HEART;

  /* RateTransition: '<S3>/Rate Transition42' */
  rtb_RateTransition42 = strsr_node;

  /* RateTransition: '<S3>/Rate Transition43' */
  rtb_RateTransition43 = FSAC2021_V1_Running_B.UnitDelay4;

  /* S-Function (fcncallgen): '<S9>/Function-Call Generator' incorporates:
   *  SubSystem: '<S9>/Subsystem'
   */

  /* S-Function (ec55xx_canreceiveslb): '<S403>/BMS_HCU_INFO' */

  /* Receive CAN message */
  {
    uint8 CAN1BUF54RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can1buf54looprx= 0;
    FSAC2021_V1_Running_B.BMS_HCU_INFO_o3= -1738522381;
    FSAC2021_V1_Running_B.BMS_HCU_INFO_o5= 8;
    bms_node= ec_can_receive(1,54, CAN1BUF54RX);
    FSAC2021_V1_Running_B.BMS_HCU_INFO_o4[0]= CAN1BUF54RX[can1buf54looprx];
    can1buf54looprx++;
    FSAC2021_V1_Running_B.BMS_HCU_INFO_o4[1]= CAN1BUF54RX[can1buf54looprx];
    can1buf54looprx++;
    FSAC2021_V1_Running_B.BMS_HCU_INFO_o4[2]= CAN1BUF54RX[can1buf54looprx];
    can1buf54looprx++;
    FSAC2021_V1_Running_B.BMS_HCU_INFO_o4[3]= CAN1BUF54RX[can1buf54looprx];
    can1buf54looprx++;
    FSAC2021_V1_Running_B.BMS_HCU_INFO_o4[4]= CAN1BUF54RX[can1buf54looprx];
    can1buf54looprx++;
    FSAC2021_V1_Running_B.BMS_HCU_INFO_o4[5]= CAN1BUF54RX[can1buf54looprx];
    can1buf54looprx++;
    FSAC2021_V1_Running_B.BMS_HCU_INFO_o4[6]= CAN1BUF54RX[can1buf54looprx];
    can1buf54looprx++;
    FSAC2021_V1_Running_B.BMS_HCU_INFO_o4[7]= CAN1BUF54RX[can1buf54looprx];
    can1buf54looprx++;
  }

  /* Call the system: <S403>/BMS_HCU_INFO  */

  /* Output and update for function-call system: '<S403>/BMS_HCU_INFO ' */
  {
    real32_T u0;

    /* Gain: '<S544>/BatVoltage_F' incorporates:
     *  Constant: '<S544>/BatVoltageinput1_C'
     *  Product: '<S544>/BatVoltageinput1_P'
     *  Sum: '<S544>/BatVoltageinput1_Ad'
     */
    u0 = (real32_T)((FSAC2021_V1_Running_B.BMS_HCU_INFO_o4[0] << 8) +
                    FSAC2021_V1_Running_B.BMS_HCU_INFO_o4[1]) * 0.1F;

    /* Saturate: '<S544>/BatVoltage_sat' */
    if (u0 > 900.0F) {
      /* DataTypeConversion: '<S542>/Data Type Conversion84' */
      FSAC2021_V1_Running_B.DataTypeConversion84 = 900.0;
    } else {
      /* DataTypeConversion: '<S542>/Data Type Conversion84' */
      FSAC2021_V1_Running_B.DataTypeConversion84 = u0;
    }

    /* End of Saturate: '<S544>/BatVoltage_sat' */
  }

  /* RateTransition: '<S3>/Rate Transition41' */
  rtb_RateTransition41 = bms_node;

  /* RateTransition: '<S3>/Rate Transition30' */
  rtb_RateTransition30 = motor_node;

  /* RateTransition: '<S3>/RateTransition25' */
  if (FSAC2021_V1_Running_M->Timing.RateInteraction.TID7_9) {
    FSAC2021_V1_Running_B.RateTransition25 =
      FSAC2021_V1_Running_DW.RateTransition25_Buffer0_d;
  }

  /* End of RateTransition: '<S3>/RateTransition25' */

  /* S-Function (fcncallgen): '<S8>/Function-Call Generator2' incorporates:
   *  SubSystem: '<S3>/DIAG'
   */
  /* DataTypeConversion: '<S129>/Data Type Conversion1' incorporates:
   *  Constant: '<S143>/Constant'
   *  RelationalOperator: '<S143>/Compare'
   */
  rtb_DataTypeConversion1_e = (uint8_T)(rtb_RateTransition34 <= 10);

  /* Chart: '<S129>/Chart2' */
  FSAC2021_V1_Running_Chart2(FSAC2021_V1_Running_M, rtb_DataTypeConversion1_e,
    &FSAC2021_V1_Running_B.sf_Chart2, &FSAC2021_V1_Running_DW.sf_Chart2);

  /* DataTypeConversion: '<S129>/Data Type Conversion2' incorporates:
   *  Constant: '<S144>/Constant'
   *  RelationalOperator: '<S144>/Compare'
   */
  rtb_DataTypeConversion2 = (uint8_T)(rtb_RateTransition35 <= 10);

  /* Chart: '<S129>/Chart3' */
  FSAC2021_V1_Running_Chart2(FSAC2021_V1_Running_M, rtb_DataTypeConversion2,
    &FSAC2021_V1_Running_B.sf_Chart3, &FSAC2021_V1_Running_DW.sf_Chart3);

  /* DataTypeConversion: '<S129>/Data Type Conversion3' incorporates:
   *  Constant: '<S145>/Constant'
   *  RelationalOperator: '<S145>/Compare'
   */
  rtb_DataTypeConversion3 = (uint8_T)(rtb_RateTransition36 <= 10);

  /* Chart: '<S129>/Chart4' */
  FSAC2021_V1_Running_Chart2(FSAC2021_V1_Running_M, rtb_DataTypeConversion3,
    &FSAC2021_V1_Running_B.sf_Chart4, &FSAC2021_V1_Running_DW.sf_Chart4);

  /* DataTypeConversion: '<S129>/Data Type Conversion4' incorporates:
   *  Constant: '<S146>/Constant'
   *  RelationalOperator: '<S146>/Compare'
   */
  rtb_DataTypeConversion4 = (uint8_T)(rtb_RateTransition37 <= 10);

  /* Chart: '<S129>/Chart5' */
  FSAC2021_V1_Running_Chart2(FSAC2021_V1_Running_M, rtb_DataTypeConversion4,
    &FSAC2021_V1_Running_B.sf_Chart5, &FSAC2021_V1_Running_DW.sf_Chart5);

  /* DataTypeConversion: '<S129>/Data Type Conversion5' incorporates:
   *  Constant: '<S147>/Constant'
   *  RelationalOperator: '<S147>/Compare'
   */
  rtb_DataTypeConversion5 = (uint8_T)(rtb_RateTransition38 <= 10);

  /* Chart: '<S129>/Chart6' */
  FSAC2021_V1_Running_Chart2(FSAC2021_V1_Running_M, rtb_DataTypeConversion5,
    &FSAC2021_V1_Running_B.sf_Chart6, &FSAC2021_V1_Running_DW.sf_Chart6);

  /* Logic: '<S129>/Logical Operator8' */
  sensor_erroe = ((FSAC2021_V1_Running_B.sf_Chart2.Debounce != 0) ||
                  (FSAC2021_V1_Running_B.sf_Chart3.Debounce != 0) ||
                  (FSAC2021_V1_Running_B.sf_Chart4.Debounce != 0) ||
                  (FSAC2021_V1_Running_B.sf_Chart5.Debounce != 0) ||
                  (FSAC2021_V1_Running_B.sf_Chart6.Debounce != 0));

  /* Outputs for Enabled SubSystem: '<S132>/B_M_S_Check' incorporates:
   *  EnablePort: '<S149>/Enable'
   */
  if (rtb_RateTransition43) {
    if (!FSAC2021_V1_Running_DW.B_M_S_Check_MODE) {
      /* Enable for Chart: '<S149>/Chart' */
      FSAC2021_V1_R_Chart_Enable(FSAC2021_V1_Running_M,
        &FSAC2021_V1_Running_DW.sf_Chart_o4);

      /* Enable for Chart: '<S149>/Chart1' */
      FSAC2021_V1__Chart1_Enable(FSAC2021_V1_Running_M,
        &FSAC2021_V1_Running_DW.sf_Chart1);
      FSAC2021_V1_Running_DW.B_M_S_Check_MODE = true;
    }

    /* Chart: '<S149>/Chart' */
    FSAC2021_V1_Running_Chart(FSAC2021_V1_Running_M,
      FSAC2021_V1_Running_B.RateTransition25, &FSAC2021_V1_Running_B.sf_Chart_o4,
      &FSAC2021_V1_Running_DW.sf_Chart_o4);

    /* Chart: '<S149>/Chart1' */
    FSAC2021_V1_Running_Chart1(FSAC2021_V1_Running_M, rtb_RateTransition32,
      &FSAC2021_V1_Running_B.sf_Chart1, &FSAC2021_V1_Running_DW.sf_Chart1);

    /* SignalConversion: '<S149>/TmpSignal ConversionAtChart1Outport1' */
    BRAKE = FSAC2021_V1_Running_B.sf_Chart1.Output;

    /* SignalConversion: '<S149>/TmpSignal ConversionAtChartOutport1' */
    MOTEC = FSAC2021_V1_Running_B.sf_Chart_o4.Output;

    /* Logic: '<S149>/Logical Operator' */
    FSAC2021_V1_Running_B.LogicalOperator_n = ((BRAKE != 0) && (MOTEC != 0));
  } else {
    if (FSAC2021_V1_Running_DW.B_M_S_Check_MODE) {
      /* Disable for Chart: '<S149>/Chart' */
      FSAC2021_V1__Chart_Disable(FSAC2021_V1_Running_M,
        &FSAC2021_V1_Running_DW.sf_Chart_o4);

      /* Disable for Chart: '<S149>/Chart1' */
      FSAC2021_V1_Chart1_Disable(FSAC2021_V1_Running_M,
        &FSAC2021_V1_Running_DW.sf_Chart1);
      FSAC2021_V1_Running_DW.B_M_S_Check_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S132>/B_M_S_Check' */

  /* RelationalOperator: '<S150>/Compare' incorporates:
   *  Constant: '<S150>/Constant'
   */
  rtb_Compare_hp = (FSAC2021_V1_Running_B.RateTransition24 >= 3);

  /* RelationalOperator: '<S151>/Compare' incorporates:
   *  Constant: '<S151>/Constant'
   */
  rtb_Compare_b = (FSAC2021_V1_Running_B.RateTransition24 <= 5);

  /* Switch: '<S132>/Switch' incorporates:
   *  Constant: '<S132>/Constant2'
   */
  if (rtb_RateTransition43) {
    rtb_Switch = (int32_T)FSAC2021_V1_Running_B.LogicalOperator_n;
  } else {
    rtb_Switch = 1;
  }

  /* End of Switch: '<S132>/Switch' */

  /* Chart: '<S154>/Chart2' */
  FSAC2021_V1_Running_Chart1(FSAC2021_V1_Running_M, rtb_RateTransition42,
    &FSAC2021_V1_Running_B.sf_Chart2_h, &FSAC2021_V1_Running_DW.sf_Chart2_h);

  /* SignalConversion: '<S154>/TmpSignal ConversionAtChart2Outport1' */
  STRSNR = FSAC2021_V1_Running_B.sf_Chart2_h.Output;

  /* Chart: '<S154>/Chart3' */
  FSAC2021_V1_Running_Chart1(FSAC2021_V1_Running_M, rtb_RateTransition41,
    &FSAC2021_V1_Running_B.sf_Chart3_h, &FSAC2021_V1_Running_DW.sf_Chart3_h);

  /* SignalConversion: '<S154>/TmpSignal ConversionAtChart3Outport1' */
  BMS = FSAC2021_V1_Running_B.sf_Chart3_h.Output;

  /* Chart: '<S154>/Chart4' */
  FSAC2021_V1_Running_Chart1(FSAC2021_V1_Running_M, rtb_RateTransition31,
    &FSAC2021_V1_Running_B.sf_Chart4_k, &FSAC2021_V1_Running_DW.sf_Chart4_k);

  /* SignalConversion: '<S154>/TmpSignal ConversionAtChart4Outport1' */
  AMI_NODE = FSAC2021_V1_Running_B.sf_Chart4_k.Output;

  /* Logic: '<S154>/Logical Operator' */
  rtb_LogicalOperator = ((STRSNR != 0) && (BMS != 0) && (AMI_NODE != 0));

  /* Logic: '<S132>/Logical Operator1' */
  rtb_RateTransition43 = (rtb_Compare_hp && rtb_Compare_b);

  /* Outputs for Enabled SubSystem: '<S132>/Subsystem' incorporates:
   *  EnablePort: '<S153>/Enable'
   */
  /* Switch: '<S132>/Switch1' incorporates:
   *  Constant: '<S132>/Constant1'
   */
  if (rtb_RateTransition43) {
    if (!FSAC2021_V1_Running_DW.Subsystem_MODE) {
      /* Enable for Chart: '<S153>/Chart4' */
      FSAC2021_V1__Chart4_Enable(FSAC2021_V1_Running_M,
        &FSAC2021_V1_Running_DW.sf_Chart4_p);
      FSAC2021_V1_Running_DW.Subsystem_MODE = true;
    }

    /* Chart: '<S153>/Chart4' */
    FSAC2021_V1_Running_Chart4(FSAC2021_V1_Running_M, rtb_RateTransition30,
      &FSAC2021_V1_Running_DW.sf_Chart4_p);
    rtb_RateTransition43_0 = motor;
  } else {
    if (FSAC2021_V1_Running_DW.Subsystem_MODE) {
      /* Disable for Chart: '<S153>/Chart4' */
      FSAC2021_V1_Chart4_Disable(FSAC2021_V1_Running_M,
        &FSAC2021_V1_Running_DW.sf_Chart4_p);
      FSAC2021_V1_Running_DW.Subsystem_MODE = false;
    }

    rtb_RateTransition43_0 = 1;
  }

  /* End of Switch: '<S132>/Switch1' */
  /* End of Outputs for SubSystem: '<S132>/Subsystem' */

  /* Logic: '<S132>/Logical Operator3' incorporates:
   *  Logic: '<S132>/Logical Operator'
   */
  Node_Lost = !((rtb_Switch != 0) && rtb_LogicalOperator &&
                (rtb_RateTransition43_0 != 0));

  /* Truth Table: '<S133>/Truth Table' */
  /* Truth Table Function 'DIAG/DIAG/EBS_Diag/Truth Table': '<S167>:1' */
  /*  Ready or Driving */
  if ((FSAC2021_V1_Running_B.RateTransition24 == 2) ||
      (FSAC2021_V1_Running_B.RateTransition24 == 3)) {
    /* Condition '#1': '<S167>:1:12' */
    rtb_RateTransition43 = true;
  } else {
    /* Condition '#1': '<S167>:1:12' */
    rtb_RateTransition43 = false;
  }

  /* Condition '#2': '<S167>:1:15' */
  /* Condition '#3': '<S167>:1:18' */
  rtb_Compare_hp = (rtb_RateTransition37 >= 0.4);

  /* Condition '#4': '<S167>:1:21' */
  rtb_Compare_b = (rtb_RateTransition38 <= 0.4);

  /* Condition '#5': '<S167>:1:24' */
  if (rtb_RateTransition43 && (rtb_RateTransition37 < 0.4) && rtb_Compare_b) {
    /* Condition '#1': '<S167>:1:12' */
    /* Decision 'D1': '<S167>:1:26' */
    /*  EBS_Failure */
    /* Action '1': '<S167>:1:40' */
    EBS_Failure_Flag = 1U;
  } else {
    /* Decision 'D2': '<S167>:1:26' */
    if (rtb_RateTransition43 && rtb_Compare_hp && rtb_Compare_b) {
      /* Condition '#1': '<S167>:1:12' */
      /* Decision 'D2': '<S167>:1:28' */
      /*  EBS_Normal */
      /* Action '2': '<S167>:1:46' */
      EBS_Failure_Flag = 0U;
    } else {
      /* Decision 'D3': '<S167>:1:28' */
      if (rtb_RateTransition43 && rtb_Compare_hp && (rtb_RateTransition38 > 0.4))
      {
        /* Condition '#1': '<S167>:1:12' */
        /* Decision 'D3': '<S167>:1:30' */
        /*  EBS_Failure */
        /* Action '1': '<S167>:1:40' */
        EBS_Failure_Flag = 1U;
      } else {
        /* Decision 'D4': '<S167>:1:30' */
        /* Decision 'D4': '<S167>:1:32' */
        /*  Default */
        /*  EBS_Normal */
        /* Action '2': '<S167>:1:46' */
        EBS_Failure_Flag = 0U;
      }
    }
  }

  /* End of Truth Table: '<S133>/Truth Table' */

  /* SignalConversion: '<S136>/HiddenBuf_InsertedFor_Subsystem1_at_inport_1' incorporates:
   *  Constant: '<S177>/Constant'
   *  RelationalOperator: '<S177>/Compare'
   */
  rtb_HiddenBuf_InsertedFor_Subsy = (FSAC2021_V1_Running_B.RateTransition24 == 3);

  /* SignalConversion: '<S136>/HiddenBuf_InsertedFor_Subsystem2_at_inport_1' incorporates:
   *  Constant: '<S178>/Constant'
   *  RelationalOperator: '<S178>/Compare'
   */
  rtb_HiddenBuf_InsertedFor_Sub_m = (FSAC2021_V1_Running_B.RateTransition24 == 6);

  /* SignalConversion: '<S136>/HiddenBuf_InsertedFor_Subsystem_at_inport_1' incorporates:
   *  Constant: '<S176>/Constant'
   *  RelationalOperator: '<S176>/Compare'
   */
  rtb_HiddenBuf_InsertedFor_Sub_i = (FSAC2021_V1_Running_B.RateTransition24 == 2);

  /* Outputs for Enabled SubSystem: '<S136>/Subsystem' */
  FSAC2021_V1_Runn_Subsystem(rtb_HiddenBuf_InsertedFor_Sub_i,
    FSAC2021_V1_Running_B.RateTransition1, &FSAC2021_V1_Running_B.Merge_j);

  /* End of Outputs for SubSystem: '<S136>/Subsystem' */

  /* Outputs for Enabled SubSystem: '<S136>/Subsystem1' */
  FSAC2021_V1_Runn_Subsystem(rtb_HiddenBuf_InsertedFor_Subsy,
    FSAC2021_V1_Running_B.RateTransition1, &FSAC2021_V1_Running_B.Merge_j);

  /* End of Outputs for SubSystem: '<S136>/Subsystem1' */

  /* Outputs for Enabled SubSystem: '<S136>/Subsystem2' */
  FSAC2021_V1_Runn_Subsystem(rtb_HiddenBuf_InsertedFor_Sub_m,
    FSAC2021_V1_Running_B.RateTransition1, &FSAC2021_V1_Running_B.Merge_j);

  /* End of Outputs for SubSystem: '<S136>/Subsystem2' */

  /* Logic: '<S135>/Logical Operator' */
  rtb_RateTransition43 = ((FSAC2021_V1_Running_B.DataTypeConversion22_b != 0) ||
                          (FSAC2021_V1_Running_B.DataTypeConversion23_i != 0) ||
                          (FSAC2021_V1_Running_B.DataTypeConversion36 != 0) ||
    (FSAC2021_V1_Running_B.DataTypeConversion37 != 0) ||
    (FSAC2021_V1_Running_B.DataTypeConversion24_f != 0) ||
    (FSAC2021_V1_Running_B.DataTypeConversion25 != 0) ||
    (FSAC2021_V1_Running_B.DataTypeConversion26 != 0) ||
    (FSAC2021_V1_Running_B.DataTypeConversion27 != 0) ||
    (FSAC2021_V1_Running_B.DataTypeConversion28 != 0) ||
    (FSAC2021_V1_Running_B.DataTypeConversion29 != 0) ||
    (FSAC2021_V1_Running_B.DataTypeConversion30 != 0) ||
    (FSAC2021_V1_Running_B.DataTypeConversion31 != 0) ||
    (FSAC2021_V1_Running_B.DataTypeConversion32 != 0) ||
    (FSAC2021_V1_Running_B.DataTypeConversion33 != 0) ||
    (FSAC2021_V1_Running_B.DataTypeConversion34 != 0) ||
    (FSAC2021_V1_Running_B.DataTypeConversion35 != 0));

  /* Outputs for Enabled SubSystem: '<S134>/Subsystem' incorporates:
   *  EnablePort: '<S171>/Enable'
   */
  if (ASMS_VALUE > 0) {
    if (!FSAC2021_V1_Running_DW.Subsystem_MODE_p) {
      /* Enable for Chart: '<S171>/Chart1' */
      FSAC2021_V_Chart1_c_Enable(FSAC2021_V1_Running_M,
        &FSAC2021_V1_Running_DW.sf_Chart1_g);
      FSAC2021_V1_Running_DW.Subsystem_MODE_p = true;
    }

    /* RelationalOperator: '<S174>/Compare' incorporates:
     *  Constant: '<S174>/Constant'
     */
    res_ebs_value = (FSAC2021_V1_Running_B.RateTransition26 == 0.0F);

    /* DataTypeConversion: '<S171>/Data Type Conversion1' */
    rtb_DataTypeConversion1 = (real_T)res_ebs_value;

    /* Chart: '<S171>/Chart1' */
    FSAC2021_V1_Runni_Chart1_g(FSAC2021_V1_Running_M, rtb_DataTypeConversion1,
      &FSAC2021_V1_Running_B.sf_Chart1_g, &FSAC2021_V1_Running_DW.sf_Chart1_g);

    /* DataTypeConversion: '<S171>/Data Type Conversion22' incorporates:
     *  Constant: '<S173>/Constant'
     *  RelationalOperator: '<S173>/Compare'
     */
    res_go = (uint8_T)(FSAC2021_V1_Running_B.RateTransition26 == 8.0F);

    /* DataTypeConversion: '<S171>/Data Type Conversion23' */
    res_ebs1 = FSAC2021_V1_Running_B.sf_Chart1_g.Output;
  } else {
    if (FSAC2021_V1_Running_DW.Subsystem_MODE_p) {
      /* Disable for Chart: '<S171>/Chart1' */
      FSAC2021__Chart1_n_Disable(FSAC2021_V1_Running_M,
        &FSAC2021_V1_Running_DW.sf_Chart1_g);
      FSAC2021_V1_Running_DW.Subsystem_MODE_p = false;
    }
  }

  /* End of Outputs for SubSystem: '<S134>/Subsystem' */

  /* Logic: '<S130>/Logical Operator' incorporates:
   *  DataTypeConversion: '<S130>/Data Type Conversion'
   *  DataTypeConversion: '<S130>/Data Type Conversion1'
   *  DataTypeConversion: '<S130>/Data Type Conversion10'
   *  DataTypeConversion: '<S130>/Data Type Conversion11'
   *  DataTypeConversion: '<S130>/Data Type Conversion12'
   *  DataTypeConversion: '<S130>/Data Type Conversion13'
   *  DataTypeConversion: '<S130>/Data Type Conversion14'
   *  DataTypeConversion: '<S130>/Data Type Conversion15'
   *  DataTypeConversion: '<S130>/Data Type Conversion16'
   *  DataTypeConversion: '<S130>/Data Type Conversion19'
   *  DataTypeConversion: '<S130>/Data Type Conversion2'
   *  DataTypeConversion: '<S130>/Data Type Conversion22'
   *  DataTypeConversion: '<S130>/Data Type Conversion23'
   *  DataTypeConversion: '<S130>/Data Type Conversion3'
   *  DataTypeConversion: '<S130>/Data Type Conversion4'
   *  DataTypeConversion: '<S130>/Data Type Conversion5'
   *  DataTypeConversion: '<S130>/Data Type Conversion6'
   *  DataTypeConversion: '<S130>/Data Type Conversion7'
   *  DataTypeConversion: '<S130>/Data Type Conversion8'
   *  DataTypeConversion: '<S130>/Data Type Conversion9'
   */
  rtb_Compare_hp = ((FSAC2021_V1_Running_B.RateTransition3 != 0) ||
                    (FSAC2021_V1_Running_B.RateTransition13 != 0) ||
                    (FSAC2021_V1_Running_B.RateTransition12 != 0) ||
                    (FSAC2021_V1_Running_B.RateTransition5 != 0) ||
                    (FSAC2021_V1_Running_B.RateTransition4 != 0) ||
                    (FSAC2021_V1_Running_B.RateTransition14 != 0) ||
                    (FSAC2021_V1_Running_B.RateTransition15_b != 0) ||
                    (FSAC2021_V1_Running_B.RateTransition10 != 0) ||
                    (FSAC2021_V1_Running_B.RateTransition21 != 0) ||
                    (FSAC2021_V1_Running_B.RateTransition17 != 0) ||
                    (FSAC2021_V1_Running_B.RateTransition16 != 0) ||
                    (FSAC2021_V1_Running_B.RateTransition2 != 0) ||
                    (FSAC2021_V1_Running_B.RateTransition18 != 0) ||
                    (FSAC2021_V1_Running_B.RateTransition19 != 0) ||
                    (FSAC2021_V1_Running_B.RateTransition20 != 0) ||
                    (FSAC2021_V1_Running_B.RateTransition9 != 0) ||
                    (FSAC2021_V1_Running_B.RateTransition7 != 0) ||
                    (FSAC2021_V1_Running_B.RateTransition6 != 0) ||
                    (FSAC2021_V1_Running_B.RateTransition11 != 0) ||
                    (FSAC2021_V1_Running_B.RateTransition8 != 0));

  /* Logic: '<S137>/Logical Operator' */
  rtb_Compare_b = ((FSAC2021_V1_Running_B.RateTransition22 != 0) &&
                   (FSAC2021_V1_Running_B.RateTransition23 != 0));

  /* S-Function (fcncallgen): '<S379>/100ms' incorporates:
   *  SubSystem: '<S379>/daq100ms'
   */

  /* S-Function (ec55xx_ccpslb1): '<S390>/CCPDAQ' */
  ccpDaq(3);

  /* S-Function (fcncallgen): '<S9>/Function-Call Generator2' incorporates:
   *  SubSystem: '<S9>/Subsystem2'
   */

  /* S-Function (ec55xx_canreceiveslb): '<S405>/MOTEC_STATUS' */

  /* Receive CAN message */
  {
    uint8 CAN0BUF6RX[2]= { 0, 0 };

    uint8 can0buf6looprx= 0;
    FSAC2021_V1_Running_B.MOTEC_STATUS_o3= 385;
    FSAC2021_V1_Running_B.MOTEC_STATUS_o5= 2;
    Steer_Status= ec_can_receive(0,6, CAN0BUF6RX);
    FSAC2021_V1_Running_B.MOTEC_STATUS_o4[0]= CAN0BUF6RX[can0buf6looprx];
    can0buf6looprx++;
    FSAC2021_V1_Running_B.MOTEC_STATUS_o4[1]= CAN0BUF6RX[can0buf6looprx];
    can0buf6looprx++;
  }

  /* Nothing to do for system: <S405>/MOTEC_STATUS  */

  /* Update for RateTransition: '<S1>/Rate Transition10' */
  FSAC2021_V1_Running_DW.RateTransition10_Buffer0 =
    FSAC2021_V1_Running_B.DataTypeConversion84;

  /* Update for RateTransition: '<S2>/Rate Transition59' */
  FSAC2021_V1_Running_DW.RateTransition59_Buffer0 = Steer_Status;

  /* Update for RateTransition: '<S3>/Rate Transition24' */
  FSAC2021_V1_Running_DW.RateTransition24_Buffer0_n = res_ebs1;

  /* Update for RateTransition: '<S2>/Rate Transition25' */
  FSAC2021_V1_Running_DW.RateTransition25_Buffer0_c = res_go;

  /* Update for RateTransition: '<S2>/Rate Transition31' */
  FSAC2021_V1_Running_DW.RateTransition31_Buffer0 = rtb_RateTransition43;

  /* S-Function (fcncallgen): '<S8>/Function-Call Generator2' incorporates:
   *  SubSystem: '<S3>/DIAG'
   */
  /* Update for RateTransition: '<S2>/Rate Transition32' incorporates:
   *  Logic: '<S131>/Logical Operator'
   */
  FSAC2021_V1_Running_DW.RateTransition32_Buffer0 = ((rtb_RateTransition17 !=
    0.0) || (rtb_RateTransition18 != 0.0) || (rtb_RateTransition19 != 0.0) ||
    (rtb_RateTransition20 != 0.0) || (rtb_RateTransition21 != 0.0) ||
    (rtb_RateTransition22 != 0.0) || (rtb_RateTransition23 != 0.0));

  /* Update for RateTransition: '<S2>/Rate Transition50' */
  FSAC2021_V1_Running_DW.RateTransition50_Buffer0 =
    FSAC2021_V1_Running_B.Merge_j;

  /* S-Function (fcncallgen): '<S8>/Function-Call Generator2' incorporates:
   *  SubSystem: '<S3>/DIAG'
   */
  /* Update for RateTransition: '<S3>/Rate Transition47' incorporates:
   *  DataTypeConversion: '<S137>/Data Type Conversion'
   */
  FSAC2021_V1_Running_DW.RateTransition47_Buffer0 = rtb_Compare_b;

  /* Update for RateTransition: '<S3>/Rate Transition46' incorporates:
   *  DataTypeConversion: '<S130>/Data Type Conversion17'
   */
  FSAC2021_V1_Running_DW.RateTransition46_Buffer0 = rtb_Compare_hp;

  /* Update for RateTransition: '<S3>/Rate Transition44' */
  FSAC2021_V1_Running_DW.RateTransition44_Buffer0 = EBS_Failure_Flag;

  /* Update absolute time */
  /* The "clockTick7" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick7" ensures timer will not overflow during the
   * application lifespan selected.
   */
  FSAC2021_V1_Running_M->Timing.clockTick7++;
}

/* Model step function for TID8 */
void FSAC2021_V1_Running_step8(void)   /* Sample time: [0.2s, 0.0s] */
{
  /* local block i/o variables */
  uint8_T rtb_RateTransition20_o;
  uint8_T rtb_RateTransition21_m;
  uint8_T rtb_RateTransition22_g;
  uint8_T rtb_UnitDelay;
  uint8_T rtb_RateTransition13;
  uint8_T rtb_RateTransition6;

  /* UnitDelay: '<S2>/Unit Delay' */
  rtb_UnitDelay = FSAC2021_V1_Running_DW.UnitDelay_DSTATE_d;

  /* RateTransition: '<S2>/Rate Transition20' */
  rtb_RateTransition20_o = rtb_UnitDelay;

  /* UnitDelay: '<S2>/Unit Delay1' */
  rtb_UnitDelay = FSAC2021_V1_Running_DW.UnitDelay1_DSTATE_c;

  /* RateTransition: '<S2>/Rate Transition21' */
  rtb_RateTransition21_m = rtb_UnitDelay;

  /* UnitDelay: '<S2>/Unit Delay2' */
  rtb_UnitDelay = FSAC2021_V1_Running_DW.UnitDelay2_DSTATE_i;

  /* RateTransition: '<S2>/Rate Transition22' */
  rtb_RateTransition22_g = rtb_UnitDelay;

  /* S-Function (fcncallgen): '<S8>/Function-Call Generator3' incorporates:
   *  SubSystem: '<S2>/200ms_Duty'
   */

  /* Outputs for Atomic SubSystem: '<S62>/Light_Subsystem' */
  FSAC2021_V_Light_Subsystem(rtb_RateTransition20_o,
    &FSAC2021_V1_Running_DW.Light_Subsystem);

  /* End of Outputs for SubSystem: '<S62>/Light_Subsystem' */

  /* Outputs for Atomic SubSystem: '<S62>/Light_Subsystem1' */
  FSAC2021__Light_Subsystem1(rtb_RateTransition21_m,
    &FSAC2021_V1_Running_B.Light_Subsystem1,
    &FSAC2021_V1_Running_DW.Light_Subsystem1);

  /* End of Outputs for SubSystem: '<S62>/Light_Subsystem1' */

  /* Outputs for Atomic SubSystem: '<S62>/Light_Subsystem2' */
  FSAC2021__Light_Subsystem2(FSAC2021_V1_Running_M, rtb_RateTransition22_g,
    &FSAC2021_V1_Running_B.Light_Subsystem2,
    &FSAC2021_V1_Running_DW.Light_Subsystem2);

  /* End of Outputs for SubSystem: '<S62>/Light_Subsystem2' */

  /* RateTransition: '<S2>/Rate Transition12' */
  rtb_UnitDelay = FSAC2021_V1_Running_B.Yellow_Light;

  /* RateTransition: '<S2>/Rate Transition13' */
  rtb_RateTransition13 = FSAC2021_V1_Running_B.Buzzer;

  /* RateTransition: '<S2>/Rate Transition6' */
  rtb_RateTransition6 = FSAC2021_V1_Running_B.Blue_Light;

  /* Update for RateTransition: '<S2>/Rate Transition17' */
  FSAC2021_V1_Running_DW.RateTransition17_Buffer0 = blue;

  /* Update for RateTransition: '<S2>/Rate Transition18' */
  FSAC2021_V1_Running_DW.RateTransition18_Buffer0_d =
    FSAC2021_V1_Running_B.Light_Subsystem1.DataTypeConversion;

  /* Update for RateTransition: '<S2>/Rate Transition19' */
  FSAC2021_V1_Running_DW.RateTransition19_Buffer0_e =
    FSAC2021_V1_Running_B.Light_Subsystem2.DataTypeConversion;

  /* Update for UnitDelay: '<S2>/Unit Delay' */
  FSAC2021_V1_Running_DW.UnitDelay_DSTATE_d = rtb_RateTransition6;

  /* Update for UnitDelay: '<S2>/Unit Delay1' */
  FSAC2021_V1_Running_DW.UnitDelay1_DSTATE_c = rtb_UnitDelay;

  /* Update for UnitDelay: '<S2>/Unit Delay2' */
  FSAC2021_V1_Running_DW.UnitDelay2_DSTATE_i = rtb_RateTransition13;

  /* Update for RateTransition: '<S2>/Rate Transition15' */
  FSAC2021_V1_Running_DW.RateTransition15_Buffer0_e =
    FSAC2021_V1_Running_B.Light_Subsystem2.Buzzer_Overflag;

  /* Update absolute time */
  /* The "clockTick8" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.2, which is the step size
   * of the task. Size of "clockTick8" ensures timer will not overflow during the
   * application lifespan selected.
   */
  FSAC2021_V1_Running_M->Timing.clockTick8++;
}

/* Model step function for TID9 */
void FSAC2021_V1_Running_step9(void)   /* Sample time: [0.5s, 0.0s] */
{
  /* S-Function (fcncallgen): '<S380>/500ms' incorporates:
   *  SubSystem: '<S380>/FlashOperation'
   */

  /* S-Function (ec55xx_flashoslb): '<S394>/FlashOperatin' */
#if defined EC_FLASH_ENABLE

  /* Operate the flash module on the MPC5554 */
  ec_flash_operation();

#endif

  /* S-Function (fcncallgen): '<S9>/Function-Call Generator1' incorporates:
   *  SubSystem: '<S9>/Subsystem1'
   */

  /* S-Function (ec55xx_canreceiveslb): '<S404>/HEARTBEAT' */

  /* Receive CAN message */
  {
    uint8 CAN0BUF3RX[1]= { 0 };

    uint8 can0buf3looprx= 0;
    FSAC2021_V1_Running_B.HEARTBEAT_o3= 1793;
    FSAC2021_V1_Running_B.HEARTBEAT_o5= 1;
    motec_node= ec_can_receive(0,3, CAN0BUF3RX);
    FSAC2021_V1_Running_B.HEARTBEAT_o4= CAN0BUF3RX[can0buf3looprx];
    can0buf3looprx++;
  }

  /* Nothing to do for system: <S404>/HEARTBEAT  */

  /* S-Function (ec55xx_canreceiveslb): '<S401>/MOTEC_MOTION' */

  /* Receive CAN message */
  {
    uint8 CAN0BUF5RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can0buf5looprx= 0;
    FSAC2021_V1_Running_B.MOTEC_MOTION_o3= 641;
    FSAC2021_V1_Running_B.MOTEC_MOTION_o5= 8;
    FSAC2021_V1_Running_B.MOTEC_MOTION_o2= ec_can_receive(0,5, CAN0BUF5RX);
    FSAC2021_V1_Running_B.MOTEC_MOTION_o4[0]= CAN0BUF5RX[can0buf5looprx];
    can0buf5looprx++;
    FSAC2021_V1_Running_B.MOTEC_MOTION_o4[1]= CAN0BUF5RX[can0buf5looprx];
    can0buf5looprx++;
    FSAC2021_V1_Running_B.MOTEC_MOTION_o4[2]= CAN0BUF5RX[can0buf5looprx];
    can0buf5looprx++;
    FSAC2021_V1_Running_B.MOTEC_MOTION_o4[3]= CAN0BUF5RX[can0buf5looprx];
    can0buf5looprx++;
    FSAC2021_V1_Running_B.MOTEC_MOTION_o4[4]= CAN0BUF5RX[can0buf5looprx];
    can0buf5looprx++;
    FSAC2021_V1_Running_B.MOTEC_MOTION_o4[5]= CAN0BUF5RX[can0buf5looprx];
    can0buf5looprx++;
    FSAC2021_V1_Running_B.MOTEC_MOTION_o4[6]= CAN0BUF5RX[can0buf5looprx];
    can0buf5looprx++;
    FSAC2021_V1_Running_B.MOTEC_MOTION_o4[7]= CAN0BUF5RX[can0buf5looprx];
    can0buf5looprx++;
  }

  /* Nothing to do for system: <S401>/MOTEC_MOTION  */

  /* Update for RateTransition: '<S3>/RateTransition25' */
  FSAC2021_V1_Running_DW.RateTransition25_Buffer0_d = motec_node;
}

/* Model step wrapper function for compatibility with a static main program */
void FSAC2021_V1_Running_step(int_T tid)
{
  switch (tid) {
   case 0 :
    FSAC2021_V1_Running_step0();
    break;

   case 1 :
    FSAC2021_V1_Running_step1();
    break;

   case 2 :
    FSAC2021_V1_Running_step2();
    break;

   case 3 :
    FSAC2021_V1_Running_step3();
    break;

   case 4 :
    FSAC2021_V1_Running_step4();
    break;

   case 5 :
    FSAC2021_V1_Running_step5();
    break;

   case 6 :
    FSAC2021_V1_Running_step6();
    break;

   case 7 :
    FSAC2021_V1_Running_step7();
    break;

   case 8 :
    FSAC2021_V1_Running_step8();
    break;

   case 9 :
    FSAC2021_V1_Running_step9();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void FSAC2021_V1_Running_initialize(void)
{
  /* Start for S-Function (ec55xx_cantransmitslb): '<S11>/CANTransmit4' */
  ec_buffer_init(1,15,1,2197885092U);

  /* Start for S-Function (ec55xx_cantransmitslb): '<S11>/CANTransmit7' */
  ec_buffer_init(0,60,0,1161U);

  /* Start for S-Function (ec55xx_cantransmitslb): '<S11>/CANTransmit6' */
  ec_buffer_init(0,59,0,382U);

  /* Start for S-Function (ec55xx_canreceiveslb): '<S401>/Steer_Sensor' */
  ec_buffer_init(0,38,0,485);

  /* Start for S-Function (ec55xx_canreceiveslb): '<S401>/MOTEC_MOTION1' */
  ec_buffer_init(0,41,0,256);

  /* Start for S-Function (fcncallgen): '<S8>/Function-Call Generator1' incorporates:
   *  Start for SubSystem: '<S10>/Read_VCU_Freq(WheelSpeed)'
   */
  /* Start for S-Function (ec55xx_ffrslb): '<S570>/Read_RL_WhlSpd' */
  SIU.PCR[127].R = 0x0500;
  fs_etpu_ppa_p_init(13,FS_ETPU_PRIORITY_MIDDLE,FS_ETPU_PPA_P_INIT,
                     FS_ETPU_PPA_RISING_EDGE);

  /* Start for S-Function (ec55xx_ffrslb): '<S570>/Read_RR_WhlSpd' */
  SIU.PCR[128].R = 0x0500;
  fs_etpu_ppa_p_init(14,FS_ETPU_PRIORITY_MIDDLE,FS_ETPU_PPA_P_INIT,
                     FS_ETPU_PPA_RISING_EDGE);

  /* Start for S-Function (fcncallgen): '<S8>/Function-Call Generator1' incorporates:
   *  Start for SubSystem: '<S2>/BCU_Controller'
   */
  /* Start for Enabled SubSystem: '<S114>/Enabled Subsystem' */
  /* Start for SignalConversion: '<S116>/OutportBufferForEngaged_Angle' */
  FSAC2021_V1_Running_B.OutportBufferForEngaged_Angle = 10;

  /* End of Start for SubSystem: '<S114>/Enabled Subsystem' */

  /* Start for S-Function (fcncallgen): '<S8>/Function-Call Generator1' incorporates:
   *  Start for SubSystem: '<S9>/PCANB(BMS、DRIVE_MOTOR)'
   */
  /* Start for S-Function (ec55xx_canreceiveslb): '<S402>/BMS_HCU_MAXT' */
  ec_buffer_init(1,18,1,-1738391309);

  /* Start for S-Function (ec55xx_canreceiveslb): '<S402>/BMS_HCU_MAXV' */
  ec_buffer_init(1,16,1,-1738456845);

  /* Start for S-Function (ec55xx_canreceiveslb): '<S402>/BMS_RELAY' */
  ec_buffer_init(1,51,1,-1738325773);

  /* Start for S-Function (ec55xx_canreceiveslb): '<S402>/BMS_HCU_POWER' */
  ec_buffer_init(1,52,1,-1738260237);

  /* Start for S-Function (ec55xx_canreceiveslb): '<S402>/Motor_Current_Speed ' */
  ec_buffer_init(1,21,1,-2147413853);

  /* Start for S-Function (ec55xx_canreceiveslb): '<S402>/BMS_ALARM' */
  ec_buffer_init(1,50,1,-1738194701);

  /* Start for S-Function (ec55xx_cantransmitslb): '<S13>/CANTransmit' */
  ec_buffer_init(0,63,0,513U);

  /* Start for S-Function (ec55xx_cantransmitslb): '<S13>/CANTransmit1' */
  ec_buffer_init(0,62,0,0U);

  /* Start for S-Function (ec55xx_cantransmitslb): '<S13>/CANTransmit2' */
  ec_buffer_init(0,61,0,1537U);

  /* Start for Atomic SubSystem: '<S13>/Brk_Mtr_Enbale' */

  /* Start for S-Function (ec55xx_cantransmitslb): '<S35>/CANTransmit' */
  ec_buffer_init(0,8,0,353U);

  /* End of Start for SubSystem: '<S13>/Brk_Mtr_Enbale' */

  /* Start for S-Function (ec55xx_cantransmitslb): '<S12>/CANTransmit5' */
  ec_buffer_init(1,56,1,2181107875U);

  /* Start for S-Function (fcncallgen): '<S8>/Function-Call Generator3' incorporates:
   *  Start for SubSystem: '<S2>/200ms_Duty'
   */

  /* Start for Atomic SubSystem: '<S62>/Light_Subsystem2' */
  FSA_Light_Subsystem2_Start(&FSAC2021_V1_Running_DW.Light_Subsystem2);

  /* End of Start for SubSystem: '<S62>/Light_Subsystem2' */

  /* Start for S-Function (ec55xx_canreceiveslb): '<S401>/Str_Error' */
  ec_buffer_init(0,4,0,129);

  /* Start for S-Function (ec55xx_canreceiveslb): '<S401>/BCU_MTR_STATUS' */
  ec_buffer_init(0,21,0,257);

  /* Start for S-Function (ec55xx_canreceiveslb): '<S401>/AMI1' */
  ec_buffer_init(0,26,0,1168);

  /* Start for S-Function (fcncallgen): '<S9>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S9>/Subsystem'
   */
  /* Start for S-Function (ec55xx_canreceiveslb): '<S403>/BMS_HCU_INFO' */
  ec_buffer_init(1,54,1,-1738522381);

  /* Start for S-Function (ec55xx_canreceiveslb): '<S401>/MOTEC_MOTION2' */
  ec_buffer_init(0,35,0,279);

  /* Start for S-Function (ec55xx_caninterruptslb1): '<S378>/ReceiveandTransmitInterrupt' incorporates:
   *  Start for SubSystem: '<S378>/Function-Call Subsystem'
   */
  /* Start for function-call system: '<S378>/Function-Call Subsystem' */

  /* Start for S-Function (ec55xx_canreceiveslb): '<S383>/CANReceive1' incorporates:
   *  Start for SubSystem: '<S383>/Function-Call Subsystem'
   */
  /* Start for function-call system: '<S383>/Function-Call Subsystem' */

  /* Start for IfAction SubSystem: '<S384>/If Action Subsystem1' */

  /* Start for S-Function (ec55xx_cantransmitslb): '<S389>/CANTransmit' */
  ec_buffer_init(2,9,0,593U);

  /* End of Start for SubSystem: '<S384>/If Action Subsystem1' */

  /* Start for S-Function (ec55xx_canreceiveslb): '<S383>/CANReceive1' */
  ec_buffer_init(2,1,0,278);

  /* Start for S-Function (ec55xx_caninterruptslb1): '<S378>/ReceiveandTransmitInterrupt' */
  ec_bufint_init(2,1);
  INTC_InstallINTCInterruptHandler( ISR_FlexCAN_2_MB1, SW_INT_VEC_CAN2_IFRL_BUF1,
    CAN2_INTC_PRIORITY );

  /* Start for S-Function (fcncallgen): '<S382>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S382>/CCPBackground'
   */
  /* Start for S-Function (ec55xx_ccpslb): '<S396>/CCPBackground' */
  ccpInit();

  /* Start for S-Function (ec55xx_caninterruptslb1): '<S382>/ReceiveandTransmitInterrupt' incorporates:
   *  Start for SubSystem: '<S382>/CCPReceive'
   */
  /* Start for function-call system: '<S382>/CCPReceive' */

  /* Start for S-Function (ec55xx_canreceiveslb): '<S397>/CANReceive' */
  ec_buffer_init(2,0,0,CCP_CRO_ID);

  /* Start for S-Function (ec55xx_caninterruptslb1): '<S382>/ReceiveandTransmitInterrupt' */
  ec_bufint_init(2,0);
  INTC_InstallINTCInterruptHandler( ISR_FlexCAN_2_MB0, SW_INT_VEC_CAN2_IFRL_BUF0,
    CAN2_INTC_PRIORITY );

  /* Start for S-Function (ec55xx_caninterruptslb1): '<S382>/ReceiveandTransmitInterrupt1' */
  ec_bufint_init(2,8);
  INTC_InstallINTCInterruptHandler( ISR_FlexCAN_2_MB8, SW_INT_VEC_CAN2_IFRL_BUF8,
    CAN2_INTC_PRIORITY );

  /* Start for S-Function (ec55xx_adcbsb): '<S7>/ADC' */
  ec_adc_init();

  /* Start for S-Function (ec55xx_rtibsb): '<S7>/RTI' */
  ec_rti_init(500);

  /* Start for S-Function (fcncallgen): '<S9>/Function-Call Generator1' incorporates:
   *  Start for SubSystem: '<S9>/Subsystem1'
   */
  /* Start for S-Function (ec55xx_canreceiveslb): '<S404>/HEARTBEAT' */
  ec_buffer_init(0,3,0,1793);

  /* Start for S-Function (fcncallgen): '<S9>/Function-Call Generator2' incorporates:
   *  Start for SubSystem: '<S9>/Subsystem2'
   */
  /* Start for S-Function (ec55xx_canreceiveslb): '<S405>/MOTEC_STATUS' */
  ec_buffer_init(0,6,0,385);

  /* Start for S-Function (ec55xx_canreceiveslb): '<S401>/MOTEC_MOTION' */
  ec_buffer_init(0,5,0,641);

  /* Start for S-Function (ec55xx_canreceiveslb): '<S401>/AMI' */
  ec_buffer_init(0,16,0,1169);

  /* InitializeConditions for S-Function (fcncallgen): '<S8>/Function-Call Generator' incorporates:
   *  InitializeConditions for SubSystem: '<S5>/KL_Sig_Process'
   */

  /* InitializeConditions for Atomic SubSystem: '<S196>/LPF' */
  FSAC2021_V1_Runni_LPF_Init(&FSAC2021_V1_Running_DW.LPF);

  /* End of InitializeConditions for SubSystem: '<S196>/LPF' */

  /* InitializeConditions for Atomic SubSystem: '<S196>/LPF1' */
  FSAC2021_V1_Runni_LPF_Init(&FSAC2021_V1_Running_DW.LPF1);

  /* End of InitializeConditions for SubSystem: '<S196>/LPF1' */

  /* InitializeConditions for Atomic SubSystem: '<S196>/LPF2' */
  FSAC2021_V1_Runni_LPF_Init(&FSAC2021_V1_Running_DW.LPF2);

  /* End of InitializeConditions for SubSystem: '<S196>/LPF2' */

  /* InitializeConditions for Atomic SubSystem: '<S196>/LPF3' */
  FSAC2021_V1_Runni_LPF_Init(&FSAC2021_V1_Running_DW.LPF3);

  /* End of InitializeConditions for SubSystem: '<S196>/LPF3' */

  /* Enable for S-Function (fcncallgen): '<S8>/Function-Call Generator1' incorporates:
   *  Enable for SubSystem: '<S2>/SteerCtr'
   */
  /* Enable for Chart: '<S66>/Chart' */
  FSAC2021_V1_Running_DW.presentTicks_nm =
    FSAC2021_V1_Running_M->Timing.clockTick6;
  FSAC2021_V1_Running_DW.previousTicks_c =
    FSAC2021_V1_Running_DW.presentTicks_nm;

  /* Enable for S-Function (fcncallgen): '<S8>/Function-Call Generator1' incorporates:
   *  Enable for SubSystem: '<S2>/BCU_Controller'
   */
  /* Enable for Chart: '<S64>/BCU_Strategy' */
  FSAC2021_V1_Running_DW.presentTicks_c =
    FSAC2021_V1_Running_M->Timing.clockTick6;
  FSAC2021_V1_Running_DW.previousTicks_i = FSAC2021_V1_Running_DW.presentTicks_c;

  /* Enable for S-Function (fcncallgen): '<S8>/Function-Call Generator1' incorporates:
   *  Enable for SubSystem: '<S2>/50ms_Duty'
   */
  /* Enable for Chart: '<S63>/AS_Machine' incorporates:
   *  Enable for SubSystem: '<S63>/Visuality Check'
   */
  /* Enable for Chart: '<S94>/Chart' */
  FSAC2021_V1_Running_DW.presentTicks_n =
    FSAC2021_V1_Running_M->Timing.clockTick6;
  FSAC2021_V1_Running_DW.previousTicks_l = FSAC2021_V1_Running_DW.presentTicks_n;
  FSAC2021_V1_Running_DW.presentTicks_b =
    FSAC2021_V1_Running_M->Timing.clockTick6;
  FSAC2021_V1_Running_DW.previousTicks_a = FSAC2021_V1_Running_DW.presentTicks_b;

  /* Enable for S-Function (fcncallgen): '<S8>/Function-Call Generator2' incorporates:
   *  Enable for SubSystem: '<S3>/DIAG'
   */
  /* Enable for Chart: '<S129>/Chart2' */
  FSAC2021_V1__Chart2_Enable(FSAC2021_V1_Running_M,
    &FSAC2021_V1_Running_DW.sf_Chart2);

  /* Enable for Chart: '<S129>/Chart3' */
  FSAC2021_V1__Chart2_Enable(FSAC2021_V1_Running_M,
    &FSAC2021_V1_Running_DW.sf_Chart3);

  /* Enable for Chart: '<S129>/Chart4' */
  FSAC2021_V1__Chart2_Enable(FSAC2021_V1_Running_M,
    &FSAC2021_V1_Running_DW.sf_Chart4);

  /* Enable for Chart: '<S129>/Chart5' */
  FSAC2021_V1__Chart2_Enable(FSAC2021_V1_Running_M,
    &FSAC2021_V1_Running_DW.sf_Chart5);

  /* Enable for Chart: '<S129>/Chart6' */
  FSAC2021_V1__Chart2_Enable(FSAC2021_V1_Running_M,
    &FSAC2021_V1_Running_DW.sf_Chart6);

  /* Enable for Chart: '<S154>/Chart2' */
  FSAC2021_V1__Chart1_Enable(FSAC2021_V1_Running_M,
    &FSAC2021_V1_Running_DW.sf_Chart2_h);

  /* Enable for Chart: '<S154>/Chart3' */
  FSAC2021_V1__Chart1_Enable(FSAC2021_V1_Running_M,
    &FSAC2021_V1_Running_DW.sf_Chart3_h);

  /* Enable for Chart: '<S154>/Chart4' */
  FSAC2021_V1__Chart1_Enable(FSAC2021_V1_Running_M,
    &FSAC2021_V1_Running_DW.sf_Chart4_k);
}

/* File trailer for ECUCoder generated file FSAC2021_V1_Running.c.
 *
 * [EOF]
 */
