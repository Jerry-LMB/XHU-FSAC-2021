/*
 * Code generated for Simulink model untitled.
 *
 * FILE    : ccppar.h
 *
 * VERSION : 1.0
 *
 * DATE    : Fri Jul 23 01:50:15 2021
 *
 * Copyright 2011-2012 ECUCoder. All Rights Reserved.
 */

#ifndef RTW_HEADER_ccppar_h_
#define RTW_HEADER_ccppar_h_
#include "can.h"
#define C_ENABLE_CCP
#define V_ENABLE_USE_DUMMY_STATEMENT
#define CCP_BYTE                       uint8
#define CCP_WORD                       uint16
#define CCP_DWORD                      uint32
#define CCP_BYTEPTR                    uint8*
#define CCP_MOTOROLA

/* Check for pending CCP commands in ccpBackground() */
#define CCP_CMD_NOT_IN_INTERRUPT

/* Enable EEPROM Read/Write Access */
/** #define CCP_WRITE_EEPROM **/
/** #define CCP_READ_EEPROM **/

/* Implement the memory checksum feature */
/* The checksum will be calculated in ccpBackground() */
/* This may be implementation specific */
#define CCP_CHECKSUM

/*CPUTYPE will determine CHECKSUM size's max range*/
#define CCP_CPUTYPE_32BIT
#define CCP_CHECKSUM_TYPE              CCP_WORD

/* Use a 16 bit CRC algorithm */
/* Note:
   This will need additional 512 byte of ROM
   CCP_CHECKSUM_TYPE has to be WORD !
 */
#define CCP_CHECKSUM_CCITT                                       /****/

/* Use GET_SEED and UNLOCK */
/**#define CCP_SEED_KEY**/

/* Enable Memory Write Protection */
#define CCP_WRITE_PROTECTION                                     /****/

/* CCP Data Acuisition Parameters */
#define CCP_DAQ
#define CCP_MAX_DAQ                    (5)
#define CCP_MAX_ODT                    (30)

/* Allow an ODT entry size >1 */
/* Not recommended for CANape, this will only need additional RAM space */
#define CCP_ODT_ENTRY_SIZE

/* Use the transmit queue in CCP.C */
/* Complete sampling is done in ccpDaq(x) and the messages are written into the queue */
#define CCP_SEND_QUEUE
#define CCP_SEND_QUEUE_SIZE            (0x20U)

/* Indicate queue overruns in the msb of pid */
/* Will be displayed in CANape's status bar if CANAPE.INI: [asap1a] check_overflow=1 */
/* #define CCP_SEND_QUEUE_OVERRUN_INDICATION */

/* Transmit only one message in one call to ccpDaq() */
/** #define CCP_SEND_SINGLE **/
#define CCP_DISABLE_INTERRUPT                                    //Can_DisableControllerInterrupts(CCP_CAN_CHANNEL)
#define CCP_ENABLE_INTERRUPT                                     //Can_EnableControllerInterrupts(CCP_CAN_CHANNEL)
#define CCP_DISABLE_GLOBAL_INTERRUPT   asm(" wrteei 0");
#define CCP_ENABLE_GLOBAL_INTERRUPT    asm(" wrteei 1");
#define CCP_CANID_TYPE                 MB_IDType_ST
#define CCP_CAN_MODULE                 FLEXCAN_C
#define CCP_CAN_RX_BUFNUM              (0x00)
#define CCP_CAN_TX_BUFNUM              (0x08)
#define CCP_CRO_ID                     (256)
#define CCP_DTO_ID                     (257)
#define CCP_CAL_FLS_BEGIN              (0x1E0000U)
#define CCP_CAL_FLS_END                (0x1FFFFFU)
#define CCP_CAL_RAM_BEGIN              (0x40000000U)
#define CCP_CAL_RAM_END                (0x4000FFFFU)
#define CCP_STATION_ID                 "V1.0"
#define CCP_STATION_ADDR               (0)
#define ccpGetRandomNum()              (AppGetRandomNum())

typedef struct {
  CCP_BYTE ccpflag[4];
  CCP_WORD ccpData0[256];
  CCP_WORD ccpData1;
  CCP_WORD ccpData2;
  CCP_DWORD ccpData3;
  CCP_BYTE ccpmap[4][6];
} tCcpData;

extern tCcpData ccpRAMData;
extern tCcpData ccpFlashData;
extern tCcpData* appCalData;
extern CCP_BYTE resetflag;
extern CCP_BYTE ccpRxData[8];

#endif                                 /* RTW_HEADER_ccppar_h_ */

/* File trailer for ECUCoder generated file ccppar.h.
 *
 * [EOF]
 */
