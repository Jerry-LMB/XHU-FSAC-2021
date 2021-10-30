/*
 * Code generated for Simulink model FSAC2021.
 *
 * FILE    : spi.h
 *
 * VERSION : 1.157
 *
 * DATE    : Wed Sep 01 03:10:55 2021
 *
 * Copyright 2011-2012 ECUCoder. All Rights Reserved.
 */

#ifndef RTW_HEADER_spi_h_
#define RTW_HEADER_spi_h_
#include "MPC5554.h"
#include "Std_Types.h"
#define SPIAENABLE                     1
#define SPIBENABLE                     0
#define SPICENABLE                     0
#define SPIDENABLE                     0
#define DBR0                           0b0
#define DBR1                           0b1
#define PCS_0                          0
#define PCS_1                          1
#define PCS_2                          2
#define PCS_3                          3
#define PCS_4                          4
#define PCS_5                          5
#define DSPI(DSPIn)                    (*( struct DSPI_tag *) (0xFFF90000+DSPIn*0x4000))

extern void ec_spi_delay(uint8 DSPIn,uint32 us);
extern void ec_spia_init(void);
extern void ec_spib_init(void);
extern void ec_spic_init(void);
extern void ec_spid_init(void);
extern void ec_spi_masterwriteread(uint8 DSPIn,uint8 PCSn,uint8 Length, uint16
  Tx_Buffer[], uint16 Rx_Buffer[]);
extern uint16 ec_spi_slavereadwrite(uint8 DSPIn, uint16 Tx_Data);

#endif                                 /* RTW_HEADER_spi_h_ */

/* File trailer for ECUCoder generated file spi.h.
 *
 * [EOF]
 */
