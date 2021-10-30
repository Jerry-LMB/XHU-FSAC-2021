/*
 * Code generated for Simulink model Gas_Calibration.
 *
 * FILE    : can.h
 *
 * VERSION : 1.1
 *
 * DATE    : Sat Oct 02 12:32:17 2021
 *
 * Copyright 2011-2012 ECUCoder. All Rights Reserved.
 */

#ifndef RTW_HEADER_can_h_
#define RTW_HEADER_can_h_
#include "MPC5554.h"
#include "Std_Types.h"
#include "ccp.h"
#define CANAENABLE                     1
#define CANBENABLE                     1
#define CANCENABLE                     1
#define FLEXCAN_A                      0
#define FLEXCAN_B                      1
#define FLEXCAN_C                      2
#define FLEXCANA_BASEADDR              0xFFFC0000UL
#define FLEXCAN_OFFSET                 0x00004000UL
#define FLEXCAN(controller)            (*( struct FLEXCAN2_tag *) (FLEXCANA_BASEADDR+FLEXCAN_OFFSET*controller))
#define CAN_NORMAL_MODE                0x00000000                /* Normal Mode */
#define NUM_OF_ENABLED_MB              0x0000003F                /* Enable all 64 message buffers */
#define CAN_BOFF_ERRMSK                0x0000C000                /* Bus off interrupt & Error interrupt enabled */
#define CAN_ERRINT                     0x00000002                /* Error interrupt flag */
#define CAN_BOFFINT                    0x00000004                /* Bus Off interrupt flag */
#define RX_MB_CODE_NOTACITVE           0x0
#define RX_MB_CODE_FULL                0x2
#define RX_MB_CODE_BUSY_TOEMPTY        0x3
#define RX_MB_CODE_EMPTY               0x4
#define RX_MB_CODE_OVERRUN             0x6
#define RX_MB_CODE_BUSY_TOOVERRUNFULL  0x7
#define TX_MB_CODE_INACITVE            0x8
#define TX_MB_CODE_TRANSMIT            0xC
#define TX_MB_CODE_RESPOND_REMOTE      0xA
#define MB_IDType_ST                   0
#define MB_IDType_EX                   1
#define NumCanMaxMB                    64
#define NumCanRxMB                     48

typedef struct {
  uint32 MBCS[64];
} CAN_Initialization;

typedef struct {
  uint32 CanCR;
  uint32 CanIMRH;
  uint32 CanIMRL;
} CAN_Int;

typedef enum {
  CAN_NOT_OK=0,
  CAN_OK,
  CAN_BUSY
} CAN_Return;

extern void ec_cana_init(CAN_Initialization* caninit);
extern void ec_canb_init(CAN_Initialization* caninit);
extern void ec_canc_init(CAN_Initialization* caninit);
extern void ec_buffer_init(uint8 Module,uint8 BufNum,uint8 IdType,uint32 Id);
extern void ec_bufint_init(uint8 Module,uint8 BufNum);
extern void ec_can_disableinterrupts(uint8 Module);
extern void ec_can_enableinterrupts(uint8 Module);
extern CAN_Return ec_can_receive(uint8 Module,uint8 BufNum,uint8 Rx_Buffer[]);
extern CAN_Return ec_can_receiveall(uint8 Module,uint32 *Id,uint8 *Dlc,uint8
  Rx_Buffer[]);
extern CAN_Return ec_can_transmit(uint8 Module,uint8 BufNum,uint8 IdType,uint32
  Id,uint8 DataLength,uint8 Tx_Buffer[]);
extern CAN_Initialization CANINIT[3];
extern CAN_Int CANIF;

#endif                                 /* RTW_HEADER_can_h_ */

/* File trailer for ECUCoder generated file can.h.
 *
 * [EOF]
 */
