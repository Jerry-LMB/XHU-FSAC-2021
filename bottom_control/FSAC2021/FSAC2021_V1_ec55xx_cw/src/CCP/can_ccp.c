/*
 * Code generated for the formwork and Simulink model.
 *
 * FILE    : can_ccp.c
 *
 * VERSION : 1.000
 *
 * DATE    : Tue Feb 07 10:32:43 2012
 *
 * Copyright 2011-2012 ECUCoder. All Rights Reserved.
 */

#include "ccp.h"
#if defined ( C_ENABLE_CCP )

/*----------------------------------------------------------------------------*/
#if defined ( CCP_PROGRAM )
#include "flash_app.h"
#endif

#if defined ( CCP_WRITE_EEPROM )
#include "eeprom.h"
#endif

/*----------------------------------------------------------------------------*/

/* CCP_CAN_CHANNEL defines in ccppar.h (CANgen) the used CAN channel for CCP */
#if defined ( C_SINGLE_RECEIVE_BUFFER ) || defined ( C_MULTIPLE_RECEIVE_BUFFER )
# if defined ( CCP_CAN_CHANNEL )
#  if ( CCP_CAN_CHANNEL == 0 )
#  define CanTransmit                  CanTransmit_0
#   if defined ( C_ENABLE_TRANSMIT_QUEUE_0 )
#    define C_ENABLE_TRANSMIT_QUEUE
#   endif
#  endif

#  if ( CCP_CAN_CHANNEL == 1 )
#  define CanTransmit                  CanTransmit_1
#   if defined ( C_ENABLE_TRANSMIT_QUEUE_1 )
#    define C_ENABLE_TRANSMIT_QUEUE
#   endif
#  endif

#  if ( CCP_CAN_CHANNEL == 2 )
#  define CanTransmit                  CanTransmit_2
#   if defined ( C_ENABLE_TRANSMIT_QUEUE_2 )
#    define C_ENABLE_TRANSMIT_QUEUE
#   endif
#  endif

#  if ( CCP_CAN_CHANNEL == 3 )
#  define CanTransmit                  CanTransmit_3
#   if defined ( C_ENABLE_TRANSMIT_QUEUE_3 )
#    define C_ENABLE_TRANSMIT_QUEUE
#  endif
#  endif

#  if ( CCP_CAN_CHANNEL == 4 )
#  define CanTransmit                  CanTransmit_4
#   if defined ( C_ENABLE_TRANSMIT_QUEUE_4 )
#    define C_ENABLE_TRANSMIT_QUEUE
#   endif
#  endif

# else
#  if (kCanNumberOfChannels > 1)
#   error "! CCP only available in one instance - use CCP_CAN_CHANNEL !"
#  endif
# endif                                /*CCP_CAN_CHANNEL*/
#endif                                 /*C_SINGLE_RECEIVE_BUFFER || C_MULTIPLE_RECEIVE_BUFFER*/

/*----------------------------------------------------------------------------*/
#if defined ( CCP_SEED_KEY )

static CCP_BYTE ccpResourceMask;
static CCP_DWORD ccpLastSeed;

#endif

#if defined ( CCP_CALPAGE )

static CCP_BYTE ccpCalPage;

#endif

#if defined ( CCP_WRITE_EEPROM )

void ccpCheckPendingEEPROM( void );

#endif

#if defined ( CCP_PROGRAM )
# if defined ( CCP_BOOTLOADER )
# else

CCP_DWORD size_notprog = 0;
CCP_DWORD a_address = 0;
CCP_DWORD last_a_address = 0;
CCP_DWORD prog_address = 0;
CCP_BYTE buf_flsdata[32];
CCP_BYTEPTR ptr_flsdata;
CCP_DWORD pushpos;
CCP_DWORD poppos;
CCP_BYTE data_size= 0;
CCP_BYTE resetflag = 0;

#endif
#endif

/*ccpSend(),ccpUserBackground() may use this variable:ccpTxData[8]*/
static CCP_BYTE ccpTxData[8];

/*CCP_CRO_Indication(),ccpBackground()may use this variable:ccpRxData[8]*/
CCP_BYTE ccpRxData[8];

/******************************************************************************/
/* The following functions are the interface between CCP and the CAN driver   */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* Basic initialization of the CCP on CAN driver */
void ccpCanInit(void)
{

#if defined ( CCP_CALPAGE )

  ccpCalPage = 0;

#endif

#if defined ( CCP_SEED_KEY )

  ccpResourceMask = 0;
  ccpLastSeed = 0;

#endif

}

/*----------------------------------------------------------------------------*/
/* Indication function for rx message CRO */
void CCP_CRO_Indication(uint8 Rx_Buffer[])
{
  /* CCP message received, data has been copied */
  /* Argument is pointer to copied data */
  /* Copy to a CCP_DWORD aligned location */
  ccpRxData[0] = Rx_Buffer[0];
  ccpRxData[1] = Rx_Buffer[1];
  ccpRxData[2] = Rx_Buffer[2];
  ccpRxData[3] = Rx_Buffer[3];
  ccpRxData[4] = Rx_Buffer[4];
  ccpRxData[5] = Rx_Buffer[5];
  ccpRxData[6] = Rx_Buffer[6];
  ccpRxData[7] = Rx_Buffer[7];

  /* Handle CCP commands on application level in ccpBackground */
#if defined ( CCP_CMD_NOT_IN_INTERRUPT )

  ccp.SendStatus |= CCP_CMD_PENDING;

  /* Handle CCP commands on CAN interrupt level */
#else

  ccpCommand(ccpRxData);

#endif

#if defined ( V_ENABLE_USE_DUMMY_STATEMENT )

  /* avoid compiler warning due to unused parameters */
  Rx_Buffer = Rx_Buffer;

#endif

}

/*----------------------------------------------------------------------------*/
/*  Confirmation function of tx message CCP_DTO is configured in generation tool */
void CCP_DTO_Confirmation(void)        //(CanTransmitHandle txObject)
{

#if defined ( V_ENABLE_USE_DUMMY_STATEMENT )

  /* avoid compiler warning due to unused parameters */
  //txObject = txObject;
#endif

#if defined ( CCP_PROGRAM )

  if (1 == resetflag) {
    resetflag = 0;

    //Mcu_PerformReset();
  }

#endif

  (void)ccpSendCallBack();
}

/*----------------------------------------------------------------------------*/
/*  Transmit the CCP message */
/* Id is CCP_DTO_ID, which is configured at compile time */
void ccpSend(CCP_BYTEPTR msg)
{

#if defined ( C_ENABLE_TRANSMIT_QUEUE )

  if (ec_can_transmit(CCP_CAN_MODULE,CCP_CAN_TX_BUFNUM,
                      CCP_CANID_TYPE,CCP_DTO_ID,8,msg) != CAN_OK) {
    /* Fatal Error, should never fail */
    ccpInit();
  }

#else

  ccpTxData[0]= msg[0];
  ccpTxData[1]= msg[1];
  ccpTxData[2]= msg[2];
  ccpTxData[3]= msg[3];
  ccpTxData[4]= msg[4];
  ccpTxData[5]= msg[5];
  ccpTxData[6]= msg[6];
  ccpTxData[7]= msg[7];
  if (ec_can_transmit(CCP_CAN_MODULE,CCP_CAN_TX_BUFNUM,
                      CCP_CANID_TYPE,CCP_DTO_ID,8,ccpTxData) != CAN_OK) {
    /* Set transmission request flag */
    ccp.SendStatus |= CCP_TX_PENDING;
  }

#endif

}

/*----------------------------------------------------------------------------*/
/*  Perform backgound calculation if needed */
void ccpUserBackground(void)
{
  /* Try to retransmit if CAN driver transmit queue is not enabled */
#if defined ( C_ENABLE_TRANSMIT_QUEUE )
#else

  if (ccp.SendStatus & CCP_TX_PENDING) {
    if (ec_can_transmit(CCP_CAN_MODULE,CCP_CAN_TX_BUFNUM,
                        CCP_CANID_TYPE,CCP_DTO_ID,8,ccpTxData) == CAN_OK) {
      ccp.SendStatus &= ~CCP_TX_PENDING;
    }
  }

#endif

  /* Check if a pending EEPROM write access is finished */
#if defined ( CCP_WRITE_EEPROM )

  ccpCheckPendingEEPROM();

#endif

  /* ... */
  /* Insert any other user actions here */
  /* Call ccpSendCrm() to finish pending EEPROM or FLASH cycles */
}

/******************************************************************************/
/* The following functions must be individually implemented if required       */
/* There are samples available for C16x, HC12, SH7055                              */
/******************************************************************************/

/*----------------------------------------------------------------------------*/

/*
   ccpGetPointer

   Convert a memory address from CCP 8/32bit into a C pointer
   used for memory transfers like DNLOAD, UPLOAD (MTA)
 */
#if defined ( ccpGetPointer )
#else

CCP_MTABYTEPTR ccpGetPointer(CCP_BYTE addr_ext, CCP_DWORD addr)
{

#if defined ( V_ENABLE_USE_DUMMY_STATEMENT )

  /* avoid compiler warning due to unused parameters */
  addr_ext = addr_ext;

#endif

  /* Example C16x: DDP1 used for CCP_RAM/CCP_ROM selection */
#if defined ( CANBOX ) || defined ( PHYTEC_MM167 )
#if defined ( CCP_CALPAGE )

  if ((ccpCalPage == 1) && (addr >= 0x14000) && (addr < 0x18000)) {/* CALRAM */
    return (CCP_MTABYTEPTR)(addr + 0x30000UL);
  }

#endif
#endif

  return (CCP_MTABYTEPTR) addr;
}

#endif

/*
   ccpGetDaqPointer

   Convert a memory address from CCP 8/32bit into a address
   stored in the ODT entries for DAQ.

   This is for reducing memory space used for DAQ lists.
   For example on a 32 bit microcontroller, a DAQ pointer may be stored as 16 bit
   value. DAQ will add the base address CCP_DAQ_BASE_ADDR before dereferencing the
   pointer. This will limit data acquisition to a single 64K memory range, but it
   will save 50% memory used for DAQ lists.

   Note: It must be possible to calculate the final address for DAQ like
   value = * (CCP_DAQ_BASE_ADDR + addr);
 */
#if defined ( CCP_DAQ_BASE_ADDR )

CCP_DAQBYTEPTR ccpGetDaqPointer(CCP_BYTE addr_ext, CCP_DWORD addr)
{
  return (CCP_DAQBYTEPTR)(ccpGetPointer(addr_ext, addr) - CCP_DAQ_BASE_ADDR);
}

#endif

#if defined ( CCP_ENABLE_MEM_ACCESS_BY_APPL )

CCP_BYTE ccpRead( CCP_DWORD addr )
{
  return *((CCP_BYTEPTR)addr);
}

void CCP_FAR ccpWrite( CCP_DWORD addr, CCP_BYTE data )
{
  *((CCP_BYTEPTR)addr) = data;
}

#endif

/*----------------------------------------------------------------------------*/
/* Check addresses for valid write access */
/* Used only if Write Protection is required */
/* Returns false if access denied */
#if defined ( CCP_WRITE_PROTECTION )

CCP_BYTE ccpCheckWriteAccess(CCP_MTABYTEPTR a, CCP_BYTE s)
{
  /* Protect CCP */
  if ((a+s>=(CCP_MTABYTEPTR)(CCP_CAL_RAM_END))||(a<(CCP_MTABYTEPTR)
       (CCP_CAL_RAM_BEGIN))) {
    return 0;
  }

  return 1;
}

#endif

/*----------------------------------------------------------------------------*/
/* Flash Kernel Download */
/* Used only of Download of the Flash Kernel is required */
#if defined ( CCP_BOOTLOADER_DOWNLOAD )

CCP_BYTE ccpDisableNormalOperation(CCP_MTABYTEPTR a, CCP_WORD s)
{

#if defined ( V_ENABLE_USE_DUMMY_STATEMENT )

  /* avoid compiler warning due to unused parameters */
  a = a;
  s = s;

#endif

  /* CANape attempts to download the flash kernel to CCP_RAM */
  /* Address is a */
  /* Size is s bytes */

  /* ... */

  /* return 0; */
  /* Refused */
  return 1;                            /* Ok */
}

#endif

/*----------------------------------------------------------------------------*/
/* Example: Flash Programming */
/* Used only if integrated Flash Programming is required */
#if defined ( CCP_PROGRAM )
# if defined ( CCP_BOOTLOADER )
# else

CCP_BYTE ccpFlashClear(CCP_MTABYTEPTR a, CCP_DWORD size)
{
  uint32 flashret = H7F_OK;

#if defined ( CANBOX ) || defined ( PHYTEC_MM167 )
#if defined ( CCP_CALPAGE )

  if (a >= (CCP_MTABYTEPTR)0x40000) {
    a -= 0x30000;                      /* Compensate CCP_RAM/CCP_ROM mapping */
  }

#endif
#endif

  /*check of the CAL_FLASH range*/
  if ((a<(CCP_MTABYTEPTR)CCP_CAL_FLS_BEGIN)||((a+size)>(CCP_MTABYTEPTR)
       CCP_CAL_FLS_END)) {
    return CCP_WRITE_DENIED;
  }

  /*Erase High Block 10 */
  CCP_DISABLE_GLOBAL_INTERRUPT;        /* Disable global interrupts */
  flashret = pFlashErase( &ssdConfig, FALSE, 0x00000000, 0x00000000, 0x00000800,
    NULL_CALLBACK );
  CCP_ENABLE_GLOBAL_INTERRUPT;         /* Enable global interrupts */

  /*end of Erase High Block 10*/
  if (flashret != H7F_OK ) {
    return CCP_WRITE_ERROR;
  }

  return CCP_WRITE_OK;
}

CCP_BYTE ccpFlashProgramm(CCP_BYTEPTR data, CCP_MTABYTEPTR a, CCP_BYTE size)
{
  CCP_BYTE ret = CCP_WRITE_OK;
  uint32 flashret = H7F_OK;

#if defined ( CANBOX ) || defined ( PHYTEC_MM167 )
#if defined ( CCP_CALPAGE )

  if (a >= (CCP_MTABYTEPTR)0x40000) {
    a -= 0x30000;                      /* Compensate CCP_RAM/CCP_ROM mapping */
  }

#endif
#endif

  if (size == 0) {                     /* End of programing sequence */
    /* Software Reset */
    if (0!=size_notprog) {
      /*if total size is not integer multiple of 8,
         at the end of flash programme,Fill the remaining bytes 0xff*/
      for (data_size = 0;data_size < (8-size_notprog) ;data_size++) {
        *ptr_flsdata = 0xff;
        pushpos ++;
        if (pushpos <32) {
          ptr_flsdata++;
        } else {
          pushpos = 0;
          ptr_flsdata = buf_flsdata;
        }
      }

      /* Program */
      CCP_DISABLE_GLOBAL_INTERRUPT;    /* Disable global interrupts */
      flashret = pFlashProgram( &ssdConfig, prog_address, 8,(uint32)(buf_flsdata
        + poppos) , NULL_CALLBACK );
      CCP_ENABLE_GLOBAL_INTERRUPT;     /* Enable global interrupts */

      /* Program */
    }

    resetflag = 1;
  }

  a_address = (uint32)a;
  if (0 == last_a_address)             /*first time to assignment the value*/
  {
    prog_address = a_address;
    pushpos = 0;
    poppos = 0;
    size_notprog = 0;
    ptr_flsdata = buf_flsdata;
  }

  for (data_size = 0;data_size < size ;data_size++)/*save the data to the buffer*/
  {
    *ptr_flsdata = *data;
    pushpos ++;
    if (pushpos <32) {
      ptr_flsdata++;
    } else {
      pushpos = 0;
      ptr_flsdata = buf_flsdata;
    }

    data++;
  }

  if ((a_address == last_a_address) ||(0 == last_a_address ) )/*consecutive flash address following the previous command*/
  {
    size_notprog += size;
    if (size_notprog >=8) {
      /* Program */
      CCP_DISABLE_GLOBAL_INTERRUPT;    /* Disable global interrupts */
      flashret = pFlashProgram( &ssdConfig, prog_address, 8,(uint32)(buf_flsdata
        + poppos) , NULL_CALLBACK );
      CCP_ENABLE_GLOBAL_INTERRUPT;     /* Enable global interrupts */

      /*Program */
      if (H7F_OK != flashret ) {
        ret = CCP_WRITE_ERROR;
      } else {
        size_notprog -= 8;
        prog_address += 8;
        poppos = (poppos+8)%32;
        last_a_address = a_address + size;/*next consecutive flash address*/
      }
    } else {
      last_a_address = a_address + size;/*next consecutive flash address*/
    }
  } else                               /*send the new command SET_MTA */
  {
    prog_address = a_address;
    size_notprog = size;
    last_a_address = a_address + size; /*next consecutive flash address*/
  }

  return ret;
}

# endif                                /* CCP_BOOTLOADER */
#endif                                 /* CCP_PROGRAM */

/*----------------------------------------------------------------------------*/
/* Example: Calibration CCP_RAM/CCP_ROM Selection */
/* Used if Flash Programming is required */
#if defined ( CCP_CALPAGE ) || defined ( CCP_PROGRAM )

CCP_DWORD ccpGetCalPage(void)
{
  return (CCP_DWORD)ccpCalPage;
}

void ccpSetCalPage(CCP_DWORD a)
{
  ccpCalPage = (CCP_BYTE)a;
  if (1 == ccpCalPage) {
    appCalData = &ccpRAMData;
  } else {
    appCalData = &ccpFlashData;
  }

#if defined ( CANBOX ) || defined ( PHYTEC_MM167 )

  if (ccpCalPage==1) {                 /* CCP_RAM */

#pragma asm

    mov DPP1,#11h
#pragma endasm

  } else {                             /* CCP_ROM */

#pragma asm

    mov DPP1,#05h
#pragma endasm

  }

#endif

}

void ccpInitCalPage(void)
{

#if defined ( CANBOX ) || defined ( PHYTEC_MM167 )
#define CALROM_ADDR                    0x14000
#define CALRAM_ADDR                    0x44000

  huge CCP_BYTE *p1 = (huge CCP_BYTE *)CALROM_ADDR;
  huge CCP_BYTE *p2 = (huge CCP_BYTE *)CALRAM_ADDR;
  unsigned int i;
  for (i = 0; i < 0x200; i++) {
    *p2++ = *p1++;
  }

#else

  CCP_BYTE *p1 = ( CCP_BYTE *)&ccpFlashData;
  CCP_BYTE *p2 = ( CCP_BYTE *)&ccpRAMData;
  unsigned int i;
  for (i = 0; i < sizeof(tCcpData); i++) {
    *p2++ = *p1++;
  }

#endif

}

#endif

/*----------------------------------------------------------------------------*/
/* Example: Seed&Key*/
/* Used only if Seed&Key is required */
#if defined ( CCP_SEED_KEY )

CCP_DWORD ccpGetSeed(CCP_BYTE resourceMask)
{
  ccpResourceMask = resourceMask;
  ccpLastSeed = 0;

  /* Generate a seed */

  /* Example: */
  /* Optimum would be a number which never appears twice */
#if defined ( CCP_TIMESTAMPING )

  ccpLastSeed = ccpGetTimestamp() * ccpGetTimestamp();

#endif

  ccpLastSeed = ccpGetRandomNum() * ccpGetRandomNum();
  return ccpLastSeed;
}

CCP_BYTE ccpUnlock(CCP_BYTEPTR key)
{
  /* Check the key */
  CCP_DWORD dwKey;

  /* Since key is not aligned to dword the bytes are copied individually. */
  ((uint8*)(&dwKey))[0] = key[0];
  ((uint8*)(&dwKey))[1] = key[1];
  ((uint8*)(&dwKey))[2] = key[2];
  ((uint8*)(&dwKey))[3] = key[3];

  /* Example: */
  ccpLastSeed = (ccpLastSeed>>(uint8)5u) | (ccpLastSeed<<(uint8)23u);
  ccpLastSeed *= 7;
  ccpLastSeed ^= (uint32)0x26031961u;
  if (dwKey != ccpLastSeed) {
    return 0;
  } else {
    /* Reset resource protection bit */
    return ccpResourceMask;
  }
}

#endif

/*----------------------------------------------------------------------------*/
/* Example: EEPROM write access */
/* Used only if required */
#if defined ( CCP_WRITE_EEPROM )

/* Pending EEPROM write cycle */
CCP_BYTE ccpEEPROMState = 0;

/* EEPROM write */
/* Return values for ccpCheckWriteEEPROM:
   CCP_WRITE_OK      - EEPROM written
   CCP_WRITE_DENIED  - This address is not in EEPROM
   CCP_WRITE_PENDING - EEPROM write in progress, call ccpSendCrm() when done
   CCP_WRITE_ERROR   - EEPROM write failed
 */
CCP_BYTE ccpCheckWriteEEPROM(CCP_MTABYTEPTR addr, CCP_BYTE size, CCP_BYTEPTR
  data)
{
  /* Check address for EEPROM */
  if (addr<EEPROM_START || addr>EEPROM_END) {
    /* Not EEPROM */
    /* Let the CCP driver perform a standard CCP_RAM write access */
    return CCP_WRITE_DENIED;
  }

  /* Alternative 1: */
  /* Initiate EEPROM write */
  /* When finished, call ccpSendCrm() */
  eeWrite(addr,data,size);
  return CCP_WRITE_OK;
}

/* Check for EEPROM write finished */
void ccpCheckPendingEEPROM( void )
{
}

#endif

#if defined ( CCP_READ_EEPROM )

/* EEPROM read */
/* Return values for ccpCheckReadEEPROM:
   0 (FALSE)    - This address is not in EEPROM
   1 (TRUE)     - EEPROM read
 */
CCP_BYTE ccpCheckReadEEPROM( CCP_MTABYTEPTR addr, CCP_BYTE size, CCP_BYTEPTR
  data )
{
  /* Read EEPROM */
  return 0;
}

#endif
#endif                                 /* C_ENABLE_CCP */

