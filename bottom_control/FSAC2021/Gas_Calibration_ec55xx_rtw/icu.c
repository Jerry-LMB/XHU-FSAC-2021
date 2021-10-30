/*
 * Code generated for Simulink model Gas_Calibration.
 *
 * FILE    : icu.c
 *
 * VERSION : 1.1
 *
 * DATE    : Sat Oct 02 12:32:17 2021
 *
 * Copyright 2011-2012 ECUCoder. All Rights Reserved.
 */

#include "icu.h"
#if 0

/**************************************************************************
 * FUNCTION :    ec_icu_init                                               *
 *                                                                         *
 * DESCRIPTION : Initialize the eMIOS moudule as input capture unit        *
 *                                                                         *
 * PARAMETERS :  -Chn: eMIOS channel for input capture                     *
 *               -IniCapture: define the mode of input capture             *
 *               -IcIntEnable: enable input capture interrupt              *
 *                                                                         *
 * RETURN :      None                                                      *
 ***************************************************************************/
void ec_icu_init(uint8 Chn, uint8 IniCapture, boolean IcIntEnable)
{
  SIU.PCR[179+Chn].R = 0x0500;         /* Initialize pad */
  EMIOS.CH[Chn].CCR.B.MODE = 0x02;     /* Set the input capture mode */
  EMIOS.CH[Chn].CCR.B.BSL = 0x3;       /* All channels: internal counter */
  EMIOS.CH[Chn].CCR.B.UCPRE = 0;       /* Prescaler=0, Divide Ratio=1 */
  EMIOS.CH[Chn].CCR.B.UCPREN = 1;      /* Prescaler enabled */
  EMIOS.CH[Chn].CCR.B.FEN = IcIntEnable;/* Enable interupt */
  EMIOS.CH[Chn].CCR.B.DMA = 0;         /* FLAG assigned to interrupt request */
  if (ICU_FALLING_EDGE == IniCapture) {
    EMIOS.CH[Chn].CCR.B.EDSEL = 0x0;
    EMIOS.CH[Chn].CCR.B.EDPOL = 0x0;
  } else if (ICU_RISING_EDGE == IniCapture) {
    EMIOS.CH[Chn].CCR.B.EDSEL = 0x0;
    EMIOS.CH[Chn].CCR.B.EDPOL = 0x1;
  } else {
    EMIOS.CH[Chn].CCR.B.EDSEL = 0x1;
  }
}

/**************************************************************************
 * FUNCTION :    ec_icu_inputcaptureread                                   *
 *                                                                         *
 * DESCRIPTION : Read the counter values on the edges                      *
 *                                                                         *
 * PARAMETERS :  -Chn: eMIOS channel for input capture                     *
 *                                                                         *
 * RETURN :      -counter: the counter value present                       *
 ***************************************************************************/
uint32 ec_icu_inputcaptureread(uint8 Chn)
{
  uint32 counter = 0;
  while (0 == EMIOS.CH[Chn].CSR.B.FLAG) {
  }

  counter = EMIOS.CH[Chn].CADR.R;
  return counter;
}

#endif

/* File trailer for ECUCoder generated file icu.c.
 *
 * [EOF]
 */
