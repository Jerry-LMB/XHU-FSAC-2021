/*
 * Code generated for Simulink model FSAC2021_V1.
 *
 * FILE    : can.c
 *
 * VERSION : 1.219
 *
 * DATE    : Sat Oct 30 18:49:46 2021
 *
 * Copyright 2011-2012 ECUCoder. All Rights Reserved.
 */

#include "can.h"
#if 1

/**************************************************************************
 * FUNCTION :    ec_cana_init                                              *
 *                                                                         *
 * DESCRIPTION : Initialize FlexCANA module                                *
 *                                                                         *
 * PARAMETERS :  -*caninit: pointer to configuration set                   *
 *                                                                         *
 * RETURN:       None                                                      *
 ***************************************************************************/
void ec_cana_init(CAN_Initialization* caninit)
{
  uint8 i,j;
  CAN_A.MCR.R = 0x5000003F;            /* 64 message buffers in use */
  FLEXCAN(0).CR.B.PRESDIV = 0;         /* Prescaler division factor */
  FLEXCAN(0).CR.B.RJW = 1;             /* Synchronization jump width */
  FLEXCAN(0).CR.B.PSEG1 = 3;           /* Phase segment 1 */
  FLEXCAN(0).CR.B.PSEG2 = 3;           /* Phase segment 2 */
  FLEXCAN(0).CR.B.BOFFMSK = 0;         /* 1: Bus off interrupt enabled; 0: Bus off interrupt disabled */
  FLEXCAN(0).CR.B.ERRMSK = 0;          /* 1: Error interrupt enabled; 0: Error interrupt disabled */
  FLEXCAN(0).CR.B.CLKSRC = 0;          /* CAN engine clock source. 0: oscillator clock; 1: system clock */
  FLEXCAN(0).CR.B.LPB = 0;             /* Loop back disabled */
  FLEXCAN(0).CR.B.SMP = 0;             /* Number of samples */
  FLEXCAN(0).CR.B.BOFFREC = 0;         /* 0: Automatic recovering from bus off state enabled;1: disable */
  FLEXCAN(0).CR.B.TSYN = 0;            /* 0: Timer sync feature disabled;1: enable */
  FLEXCAN(0).CR.B.LBUF = 0;            /* 0: Buffer with lowest ID is transmitted first
                                          1: Lowest number buffer is transmitted first */
  FLEXCAN(0).CR.B.LOM = 0;             /* Listen-only mode disable */
  FLEXCAN(0).CR.B.PROPSEG = 6;         /* Defines the length of the propagation segment in the bit time */
  for (i=0; i<NumCanMaxMB; i++)        /* Initialize message buffer for receive or transmit */
  {
    FLEXCAN(0).BUF[i].CS.R = caninit->MBCS[i];
    for (j=0; j<8; j++) {
      FLEXCAN(0).BUF[i].DATA.B[j] = 0;
    }
  }

  FLEXCAN(0).BUF[14].ID.R = 0;
  FLEXCAN(0).RXGMASK.R = 0x1FFFFFFF;
  FLEXCAN(0).RX14MASK.R = 0x1FFFFFFF;
  FLEXCAN(0).RX15MASK.R = 0x1FFFFFFF;
  FLEXCAN(0).ECR.R = 0;
  FLEXCAN(0).IMRH.R = 0;
  FLEXCAN(0).IFRH.R = 0xFFFFFFFF;      /* Clear interruput flag */
  FLEXCAN(0).IFRL.R = 0xFFFFFFFF;      /* Clear interruput flag */
  FLEXCAN(0).ESR.R = CAN_ERRINT|CAN_BOFFINT;/* Error interrupt flag & Bus off interrupt flag */
  FLEXCAN(0).MCR.R = CAN_NORMAL_MODE|NUM_OF_ENABLED_MB;/* Normal mode */
  FLEXCAN(0).MCR.B.HALT = 0;           /* FlexCAN2 attempts to synchronize with the CAN bus */
}

#endif

#if 1

/**************************************************************************
 * FUNCTION :    ec_canb_init                                              *
 *                                                                         *
 * DESCRIPTION : Initialize FlexCANB module                                *
 *                                                                         *
 * PARAMETERS :  -*caninit: pointer to configuration set                   *
 *                                                                         *
 * RETURN:       None                                                      *
 ***************************************************************************/
void ec_canb_init(CAN_Initialization* caninit)
{
  uint8 i,j;
  CAN_B.MCR.R = 0x5000003F;            /* 64 message buffers in use */
  FLEXCAN(1).CR.B.PRESDIV = 0;         /* Prescaler division factor */
  FLEXCAN(1).CR.B.RJW = 1;             /* Synchronization jump width */
  FLEXCAN(1).CR.B.PSEG1 = 3;           /* Phase segment 1 */
  FLEXCAN(1).CR.B.PSEG2 = 3;           /* Phase segment 2 */
  FLEXCAN(1).CR.B.BOFFMSK = 0;         /* 1: Bus off interrupt enabled; 0: Bus off interrupt disabled */
  FLEXCAN(1).CR.B.ERRMSK = 0;          /* 1: Error interrupt enabled; 0: Error interrupt disabled */
  FLEXCAN(1).CR.B.CLKSRC = 0;          /* CAN engine clock source. 0: oscillator clock; 1: system clock */
  FLEXCAN(1).CR.B.LPB = 0;             /* 0: Loop back disabled */
  FLEXCAN(1).CR.B.SMP = 0;             /* Number of samples */
  FLEXCAN(1).CR.B.BOFFREC = 0;         /* 0: Automatic recovering from bus off state enabled; 1: disable */
  FLEXCAN(1).CR.B.TSYN = 0;            /* 0: Timer sync feature disabled; 1: enable */
  FLEXCAN(1).CR.B.LBUF = 0;            /* 0: Buffer with lowest ID is transmitted first
                                          1: Lowest number buffer is transmitted first */
  FLEXCAN(1).CR.B.LOM = 0;             /* Listen-only mode disable */
  FLEXCAN(1).CR.B.PROPSEG = 6;         /* Defines the length of the propagation segment in the bit time */
  for (i=0; i<NumCanMaxMB; i++)        /* Initialize message buffer for receive or transmit  */
  {
    FLEXCAN(1).BUF[i].CS.R = caninit->MBCS[i];
    for (j=0; j<8; j++) {
      FLEXCAN(1).BUF[i].DATA.B[j] = 0;
    }
  }

  FLEXCAN(1).BUF[14].ID.R = 0;
  FLEXCAN(1).RXGMASK.R = 0x1FFFFFFF;
  FLEXCAN(1).RX14MASK.R = 0x1FFFFFFF;
  FLEXCAN(1).RX15MASK.R = 0x1FFFFFFF;
  FLEXCAN(1).ECR.R = 0;
  FLEXCAN(1).IMRH.R = 0;
  FLEXCAN(1).IFRH.R = 0xFFFFFFFF;      /* Clear interruput flag */
  FLEXCAN(1).IFRL.R = 0xFFFFFFFF;      /* Clear interruput flag */
  FLEXCAN(1).ESR.R = CAN_ERRINT|CAN_BOFFINT;/* Error interrupt flag & Bus off interrupt flag */
  FLEXCAN(1).MCR.R = CAN_NORMAL_MODE|NUM_OF_ENABLED_MB;/* Normal mode */
  FLEXCAN(1).MCR.B.HALT = 0;           /* FlexCAN2 attempts to synchronize with the CAN bus */
}

#endif

#if 1

/**************************************************************************
 * FUNCTION :    ec_canc_init                                              *
 *                                                                         *
 * DESCRIPTION : Initialize FlexCANC module                                *
 *                                                                         *
 * PARAMETERS :  -*caninit: pointer to configuration set                   *
 *                                                                         *
 * RETURN :      None                                                      *
 ***************************************************************************/
void ec_canc_init(CAN_Initialization* caninit)
{
  uint8 i,j;
  CAN_C.MCR.R = 0x5000003F;            /* 64 message buffers in use */
  FLEXCAN(2).CR.B.PRESDIV = 0;         /* Prescaler division factor */
  FLEXCAN(2).CR.B.RJW = 1;             /* Synchronization jump width */
  FLEXCAN(2).CR.B.PSEG1 = 3;           /* Phase segment 1 */
  FLEXCAN(2).CR.B.PSEG2 = 3;           /* Phase segment 2 */
  FLEXCAN(2).CR.B.BOFFMSK = 0;         /* 1: Bus off interrupt enabled; 0: Bus off interrupt disabled */
  FLEXCAN(2).CR.B.ERRMSK = 0;          /* 1: Error interrupt enabled; 0: Error interrupt disabled */
  FLEXCAN(2).CR.B.CLKSRC = 0;          /* CAN engine clock source. 0: oscillator clock; 1: system clock */
  FLEXCAN(2).CR.B.LPB = 0;             /* 0: Loop back disabled */
  FLEXCAN(2).CR.B.SMP = 0;             /* Number of samples */
  FLEXCAN(2).CR.B.BOFFREC = 0;         /* 0: Automatic recovering from bus off state enabled; 1: disable */
  FLEXCAN(2).CR.B.TSYN = 0;            /* 0: Timer sync feature disabled; 1: enable */
  FLEXCAN(2).CR.B.LBUF = 0;            /* 0: Buffer with lowest ID is transmitted first
                                          1: Lowest number buffer is transmitted first */
  FLEXCAN(2).CR.B.LOM = 0;             /* Listen-only mode disable */
  FLEXCAN(2).CR.B.PROPSEG = 6;         /* Defines the length of the propagation segment in the bit time */
  for (i=0; i<NumCanMaxMB; i++)        /* Initialize message buffer for receive or transmit */
  {
    FLEXCAN(2).BUF[i].CS.R = caninit->MBCS[i];
    for (j=0; j<8; j++) {
      FLEXCAN(2).BUF[i].DATA.B[j] = 0;
    }
  }

  FLEXCAN(2).BUF[14].ID.R = 0;
  FLEXCAN(2).RXGMASK.R = 0x1FFFFFFF;
  FLEXCAN(2).RX14MASK.R = 0x1FFFFFFF;
  FLEXCAN(2).RX15MASK.R = 0x1FFFFFFF;
  FLEXCAN(2).ECR.R = 0;
  FLEXCAN(2).IMRH.R = 0;
  FLEXCAN(2).IFRH.R = 0xFFFFFFFF;      /* Clear interruput flag */
  FLEXCAN(2).IFRL.R = 0xFFFFFFFF;      /* Clear interruput flag */
  FLEXCAN(2).ESR.R = CAN_ERRINT|CAN_BOFFINT;/* Error interrupt flag & Bus off interrupt flag */
  FLEXCAN(2).MCR.R = CAN_NORMAL_MODE|NUM_OF_ENABLED_MB;/* Normal mode */
  FLEXCAN(2).MCR.B.HALT = 0;           /* FlexCAN2 attempts to synchronize with the CAN bus */
}

#endif

#if CANAENABLE||CANBENABLE||CANCENABLE

/**************************************************************************
 * FUNCTION :    ec_buffer_init                                            *
 *                                                                         *
 * DESCRIPTION : Initializes CAN buffer for CAN Controller                 *
 *                                                                         *
 * PARAMETERS :  -Module: FLEXCAN_A, FLEXCAN_B or FLEXCAN_C                *
 *               -BufNum: buffer number                                    *
 *               -IdType: standard or extended ID type                     *
 *               -Id: CAN message ID                                       *
 *                                                                         *
 * RETURN :      None                                                      *
 ***************************************************************************/
void ec_buffer_init(uint8 Module,uint8 BufNum,uint8 IdType,uint32 Id)
{
  FLEXCAN(Module).MCR.R = 0x5000003F;  /* 64 message buffers in use */
  if ((BufNum < 8)||(BufNum > 15)) {
    if (IdType == 0) {
      FLEXCAN(Module).BUF[BufNum].ID.B.STD_ID = Id;
    } else {
      FLEXCAN(Module).BUF[BufNum].ID.R = Id;
    }
  } else {
  }

  if (BufNum == 14) {
    FLEXCAN(Module).RX14MASK.R = 0x10000000;
  } else {
  }

  FLEXCAN(Module).MCR.R = CAN_NORMAL_MODE|NUM_OF_ENABLED_MB;/* Normal mode */
  FLEXCAN(Module).MCR.B.HALT= 0;       /* FlexCAN attempts to synchronize with the CAN bus */
}

/**************************************************************************
 * FUNCTION :    ec_bufint_init                                            *
 *                                                                         *
 * DESCRIPTION : Initializes CAN buffer interrupts for CAN Controller      *
 *                                                                         *
 * PARAMETERS :  -Module: FLEXCAN_A, FLEXCAN_B or FLEXCAN_C                *
 *               -BufNum: buffer number                                    *
 *                                                                         *
 * RETURN :      None                                                      *
 ***************************************************************************/
void ec_bufint_init(uint8 Module,uint8 BufNum)
{
  FLEXCAN(Module).MCR.R = 0x5000003F;  /* 64 message buffers in use */
  switch (BufNum)
  {
   case 0:
    FLEXCAN(Module).IMRL.B.BUF00M = 1;
    break;

   case 1:
    FLEXCAN(Module).IMRL.B.BUF01M = 1;
    break;

   case 2:
    FLEXCAN(Module).IMRL.B.BUF02M = 1;
    break;

   case 3:
    FLEXCAN(Module).IMRL.B.BUF03M = 1;
    break;

   case 4:
    FLEXCAN(Module).IMRL.B.BUF04M = 1;
    break;

   case 5:
    FLEXCAN(Module).IMRL.B.BUF05M = 1;
    break;

   case 6:
    FLEXCAN(Module).IMRL.B.BUF06M = 1;
    break;

   case 7:
    FLEXCAN(Module).IMRL.B.BUF07M = 1;
    break;

   case 8:
    FLEXCAN(Module).IMRL.B.BUF08M = 1;
    break;

   case 9:
    FLEXCAN(Module).IMRL.B.BUF09M = 1;
    break;

   case 10:
    FLEXCAN(Module).IMRL.B.BUF10M = 1;
    break;

   case 11:
    FLEXCAN(Module).IMRL.B.BUF11M = 1;
    break;

   case 12:
    FLEXCAN(Module).IMRL.B.BUF12M = 1;
    break;

   case 13:
    FLEXCAN(Module).IMRL.B.BUF13M = 1;
    break;

   case 14:
    FLEXCAN(Module).IMRL.B.BUF14M = 1;
    break;

   case 15:
    FLEXCAN(Module).IMRL.B.BUF15M = 1;
    break;

   default:
    break;
  }

  FLEXCAN(Module).MCR.R = CAN_NORMAL_MODE|NUM_OF_ENABLED_MB;/* Normal mode */
  FLEXCAN(Module).MCR.B.HALT = 0;      /* FlexCAN attempts to synchronize with the CAN bus */
}

/**************************************************************************
 * FUNCTION :    ec_can_disableinterrupts                                  *
 *                                                                         *
 * DESCRIPTION : Disable all Can Interrupts                                *
 *                                                                         *
 * PARAMETERS :  -Module: FLEXCAN_A, FLEXCAN_B or FLEXCAN_C                *
 *                                                                         *
 * RETURN :      None                                                      *
 ***************************************************************************/
void ec_can_disableinterrupts(uint8 Module)
{
  CANIF.CanCR = FLEXCAN(Module).CR.R;
  CANIF.CanIMRH = FLEXCAN(Module).IMRH.R;
  CANIF.CanIMRL = FLEXCAN(Module).IMRL.R;
  FLEXCAN(Module).CR.R &= (uint32)~((uint32)CAN_BOFF_ERRMSK);/* Disabled bus off interrupt & error interrupt */
  FLEXCAN(Module).IMRH.R = 0;          /* Disabled interrupt masks high (MB32-63) */
  FLEXCAN(Module).IMRL.R = 0;          /* Disabled interrupt masks low (MB0-31) */
}

/**************************************************************************
 * FUNCTION :    ec_can_enableinterrupts(uint8 Module)                     *
 *                                                                         *
 * DESCRIPTION : Restore all Can Interrupts                                *
 *                                                                         *
 * PARAMETERS :  -Module: FLEXCAN_A, FLEXCAN_B or FLEXCAN_C                *
 *                                                                         *
 * RETURN :      None                                                      *
 ***************************************************************************/
void ec_can_enableinterrupts(uint8 Module)
{
  FLEXCAN(Module).IMRH.R = CANIF.CanIMRH;/* Restore interrupt masks high */
  FLEXCAN(Module).IMRL.R = CANIF.CanIMRL;/* Restore interrupt masks low */
  FLEXCAN(Module).CR.R |= (CANIF.CanCR & CAN_BOFF_ERRMSK);/* Restore bus off interrupt & error interrupt */
}

/**************************************************************************
 * FUNCTION :    ec_can_receive                                            *
 *                                                                         *
 * DESCRIPTION : Receive CAN message and copy message to Rx_Buffer[]       *
 *                                                                         *
 * PARAMETERS :  -Module: FLEXCAN_A, FLEXCAN_B or FLEXCAN_C                *
 *               -BufNum: buffer number for receive                        *
 *               -Rx_Buffer: a pointer pointing to the buffer used to      *
 *                save the data received by CAN                            *
 *                                                                         *
 * RETURN :      -result: CAN_NOT_OK or CAN_OK                             *
 ***************************************************************************/
CAN_Return ec_can_receive(uint8 Module,uint8 BufNum,uint8 Rx_Buffer[])
{
  uint8 DataNum,Code,Length;
  uint16 FrameTime;
  uint32 i;
  CAN_Return result = CAN_NOT_OK;
  if (BufNum<32) {
    if (((FLEXCAN(Module).IFRL.R>>BufNum)&0x01) == 0x01) {
      Code = (uint8)FLEXCAN(Module).BUF[BufNum].CS.B.CODE;
      Length = (uint8)FLEXCAN(Module).BUF[BufNum].CS.B.LENGTH;
      FrameTime = (uint16)FLEXCAN(Module).BUF[BufNum].CS.B.TIMESTAMP;
      for (DataNum=0; DataNum<FLEXCAN(Module).BUF[BufNum].CS.B.LENGTH; DataNum++)
      {
        Rx_Buffer[DataNum] = (uint8)FLEXCAN(Module).BUF[BufNum].DATA.B[DataNum];
      }

      ec_can_applrxindication(Module,BufNum,Rx_Buffer);
      i = FLEXCAN(Module).TIMER.R;
      FLEXCAN(Module).IFRL.R = (uint32)0x01<<BufNum;
      result = CAN_OK;
    }
  } else {
    if (((FLEXCAN(Module).IFRH.R>>(BufNum-32))&0x01) == 0x01) {
      Code = (uint8)FLEXCAN(Module).BUF[BufNum].CS.B.CODE;
      Length = (uint8)FLEXCAN(Module).BUF[BufNum].CS.B.LENGTH;
      FrameTime = (uint16)FLEXCAN(Module).BUF[BufNum].CS.B.TIMESTAMP;
      for (DataNum=0; DataNum<FLEXCAN(Module).BUF[BufNum].CS.B.LENGTH; DataNum++)
      {
        Rx_Buffer[DataNum] = (uint8)FLEXCAN(Module).BUF[BufNum].DATA.B[DataNum];
      }

      ec_can_applrxindication(Module,BufNum,Rx_Buffer);
      i = FLEXCAN(Module).TIMER.R;
      FLEXCAN(Module).IFRH.R = (uint32)0x01<<(BufNum-32);
      result = CAN_OK;
    }
  }

  return result;
}

/**************************************************************************
 * FUNCTION :    ec_can_receiveall                                         *
 *                                                                         *
 * DESCRIPTION : Receive CAN message and copy message to Rx_Buffer[]       *
 *                                                                         *
 * PARAMETERS :  -Module: FLEXCAN_A, FLEXCAN_B or FLEXCAN_C                *
 *               -*Id: CAN message ID                                      *
 *               -*Dlc: CAN message length                                 *
 *               -Rx_Buffer: a pointer pointing to the buffer used to      *
 *                save the data received by CAN                            *
 *                                                                         *
 * RETURN :      -result: CAN_NOT_OK or CAN_OK                             *
 ***************************************************************************/
CAN_Return ec_can_receiveall(uint8 Module,uint32 *Id,uint8 *Dlc,uint8 Rx_Buffer[])
{
  uint8 DataNum,Code;
  uint16 FrameTime;
  uint32 i;
  CAN_Return result = CAN_NOT_OK;
  if (((FLEXCAN(Module).IFRL.R>>14)&0x01) == 0x01) {
    Code = (uint8)FLEXCAN(Module).BUF[14].CS.B.CODE;
    *Dlc = (uint8)FLEXCAN(Module).BUF[14].CS.B.LENGTH;
    if (FLEXCAN(Module).BUF[14].CS.B.IDE == MB_IDType_EX) {
      *Id = (uint32)FLEXCAN(Module).BUF[14].ID.R;
    } else {
      *Id = (uint32)FLEXCAN(Module).BUF[14].ID.B.STD_ID;
    }

    FrameTime = (uint16)FLEXCAN(Module).BUF[14].CS.B.TIMESTAMP;
    for (DataNum=0; DataNum<FLEXCAN(Module).BUF[14].CS.B.LENGTH; DataNum++) {
      Rx_Buffer[DataNum] = (uint8)FLEXCAN(Module).BUF[14].DATA.B[DataNum];
    }

    i = FLEXCAN(Module).TIMER.R;
    FLEXCAN(Module).IFRL.R = (uint32)0x01<<14;
    result = CAN_OK;
  }

  return result;
}

/**************************************************************************
 * FUNCTION :    ec_can_transmit                                           *
 *                                                                         *
 * DESCRIPTION : Copy CAN Tx_Buffer to CAN Message Buffer and then         *
 *               transmit message to CAN bus                               *
 *                                                                         *
 * PARAMETERS :  -Module: FLEXCAN_A, FLEXCAN_B or FLEXCAN_C                *
 *               -BufNum: buffer number for transmit                       *
 *               -IdType: 0 means standard format;1 means entend format    *
 *               -Id: the message ID to be transmitted                     *
 *               -DataLength: data length of the frame data                *
 *               -Tx_Buffer: the data array to be transmitted              *
 *                                                                         *
 * RETURN :      -result: CAN_BUSY or CAN_OK.                              *
 ***************************************************************************/
CAN_Return ec_can_transmit(uint8 Module,uint8 BufNum,uint8 IdType,uint32 Id,
  uint8 DataLength,uint8 Tx_Buffer[])
{
  uint8 i;
  CAN_Return result = CAN_BUSY;
  if (BufNum<8)
    BufNum = 8;
  else if ((BufNum>15)&(BufNum<56))
    BufNum = 15;
  else if (BufNum>63)
    BufNum = 63;
  else {
    if (FLEXCAN(Module).BUF[BufNum].CS.B.CODE == TX_MB_CODE_TRANSMIT) {
      result = CAN_BUSY;
    } else {
      if (IdType == 0) {
        FLEXCAN(Module).BUF[BufNum].CS.B.IDE = MB_IDType_ST;
        FLEXCAN(Module).BUF[BufNum].ID.B.STD_ID = Id;
        FLEXCAN(Module).BUF[BufNum].CS.B.SRR = 0;
      } else {
        FLEXCAN(Module).BUF[BufNum].CS.B.IDE = MB_IDType_EX;
        FLEXCAN(Module).BUF[BufNum].ID.R = (uint32)(Id&0x1FFFFFFF);
        FLEXCAN(Module).BUF[BufNum].CS.B.SRR = 1;
      }

      FLEXCAN(Module).BUF[BufNum].CS.B.RTR = 0;
      for (i=0; i<DataLength; i++) {
        FLEXCAN(Module).BUF[BufNum].DATA.B[i] = Tx_Buffer[i];
      }

      FLEXCAN(Module).BUF[BufNum].CS.B.LENGTH = DataLength;
      FLEXCAN(Module).BUF[BufNum].CS.B.CODE = TX_MB_CODE_TRANSMIT;
      result = CAN_OK;
    }
  }

  return(result);
}

CAN_Return ec_remote_transmit(uint8 Module,uint8 BufNum,uint8 IdType,uint32 Id)
{
  CAN_Return result = CAN_BUSY;
  if (BufNum<8)
    BufNum = 8;
  else if ((BufNum>15)&(BufNum<56))
    BufNum = 15;
  else if (BufNum>63)
    BufNum = 63;
  else {
    if (FLEXCAN(Module).BUF[BufNum].CS.B.CODE == TX_MB_CODE_TRANSMIT) {
      result = CAN_BUSY;
    } else {
      if (IdType == 0) {
        FLEXCAN(Module).BUF[BufNum].CS.B.IDE = MB_IDType_ST;
        FLEXCAN(Module).BUF[BufNum].ID.B.STD_ID = Id;
        FLEXCAN(Module).BUF[BufNum].CS.B.SRR = 0;
      } else {
        FLEXCAN(Module).BUF[BufNum].CS.B.IDE = MB_IDType_EX;
        FLEXCAN(Module).BUF[BufNum].ID.R = (uint32)(Id&0x1FFFFFFF);
        FLEXCAN(Module).BUF[BufNum].CS.B.SRR = 1;
      }

      FLEXCAN(Module).BUF[BufNum].CS.B.RTR = 1;
      FLEXCAN(Module).BUF[BufNum].CS.B.LENGTH = 8;
      FLEXCAN(Module).BUF[BufNum].CS.B.CODE = TX_MB_CODE_TRANSMIT;
      result = CAN_OK;
    }
  }

  return(result);
}

#endif

/* File trailer for ECUCoder generated file can.c.
 *
 * [EOF]
 */
