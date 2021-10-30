/*
 * Code generated for Simulink model Gas_Calibration.
 *
 * FILE    : rti.c
 *
 * VERSION : 1.1
 *
 * DATE    : Sat Oct 02 12:32:17 2021
 *
 * Copyright 2011-2012 ECUCoder. All Rights Reserved.
 */

#include "rti.h"

/**************************************************************************
 * FUNCTION :    ec_rti_init                                               *
 *                                                                         *
 * DESCRIPTION : Initialize the RTI module                                 *
 *               Define the eMIOS channel 23 for Rti                       *
 *                                                                         *
 * PARAMETERS :  -Counter: range from 12 to 10000000, us                   *
 *                                                                         *
 * RETURN :      None                                                      *
 ***************************************************************************/
void ec_rti_init(uint32 Counter)
{
  EMIOS.MCR.B.MDIS = 0;                /* EMIOS module enter normal mode */
  EMIOS.MCR.B.GPRE = 79;               /* Divide 80 MHz sysclk for eMIOS clock */
  EMIOS.MCR.B.ETB = 0;                 /* External time base is disabled; Ch 23 drives counter bus A */
  EMIOS.MCR.B.GTBE = 1;                /* Enable global time base */
  EMIOS.MCR.B.GPREN = 1;               /* Enable eMIOS clock */
  if (Counter < RTI_TIMER_VALUE_MIN ) {
    Counter = RTI_TIMER_VALUE_MIN;
  } else if (Counter > RTI_TIMER_VALUE_MAX ) {
    Counter = RTI_TIMER_VALUE_MAX;
  } else {
  }

  EMIOS.CH[23].CADR.R = Counter-1;
  EMIOS.CH[23].CCR.B.MODE = 0x10;      /* Modulus counter */
  EMIOS.CH[23].CCR.B.BSL = 0x3;        /* All channels: internal counter */
  EMIOS.CH[23].CCR.B.UCPRE = 0;        /* Prescaler=0, divide ratio=1 */
  EMIOS.CH[23].CCR.B.UCPREN = 1;       /* Prescaler enabled */
  EMIOS.CH[23].CCR.B.FEN = 1;          /* Enable interupt */
  EMIOS.CH[23].CCR.B.DMA = 0;          /* FLAG assigned to interrupt request */
}

void ec_pit_init(uint32 Counter)
{
  if (Counter < RTI_TIMER_VALUE_MIN ) {
    Counter = RTI_TIMER_VALUE_MIN;
  } else if (Counter > RTI_TIMER_VALUE_MAX ) {
    Counter = RTI_TIMER_VALUE_MAX;
  } else {
  }

  EMIOS.CH[22].CADR.R = Counter-1;
  EMIOS.CH[22].CCR.B.MODE = 0x10;      /* Modulus counter */
  EMIOS.CH[22].CCR.B.BSL = 0x3;        /* All channels: internal counter */
  EMIOS.CH[22].CCR.B.UCPRE = 0;        /* Prescaler=0, divide ratio=1 */
  EMIOS.CH[22].CCR.B.UCPREN = 1;       /* Prescaler enabled */
  EMIOS.CH[22].CCR.B.FEN = 1;          /* Enable interupt */
  EMIOS.CH[22].CCR.B.DMA = 0;          /* FLAG assigned to interrupt request */
}

/* File trailer for ECUCoder generated file rti.c.
 *
 * [EOF]
 */
