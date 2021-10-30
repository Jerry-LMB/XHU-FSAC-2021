/*
 * Code generated for Simulink model FSAC2021_V1_Running.
 *
 * FILE    : pwm.c
 *
 * VERSION : 1.179
 *
 * DATE    : Sun Sep 26 20:42:00 2021
 *
 * Copyright 2011-2012 ECUCoder. All Rights Reserved.
 */

#include "pwm.h"
#if 1

/**************************************************************************
 * FUNCTION :    ec_pwm_init                                               *
 *                                                                         *
 * DESCRIPTION : Initialize eMIOS moudule as PWM                           *
 *                                                                         *
 * PARAMETERS :  -Chn: range from 0 to 22                                  *
 *                                                                         *
 * RETURN :      None                                                      *
 ***************************************************************************/
void ec_pwm_init(uint8 Chn)
{
  SIU.PCR[179+Chn].R = 0x0602;         /* Initialize pad */
  EMIOS.CH[Chn].CBDR.R = 100;          /* Initialize period */
  EMIOS.CH[Chn].CADR.R = 0;            /* Initialize duty cycle */
  EMIOS.CH[Chn].CCR.B.UCPRE = 0;       /* Prescaler=0, Divide Ratio=1 */
  EMIOS.CH[Chn].CCR.B.UCPREN = 1;      /* Prescaler enabled */
  EMIOS.CH[Chn].CCR.B.EDPOL = 1;       /* Polarity is active high */
  EMIOS.CH[Chn].CCR.B.MODE = 0x19;     /* Mode is OPWFM */
}

/**************************************************************************
 * FUNCTION :    ec_pwm_output                                             *
 *                                                                         *
 * DESCRIPTION : Set channel, period and dutycycle                         *
 *                                                                         *
 * PARAMETERS :  -Chn: range from 0 to 22                                  *
 *               -Period: type uint32                                      *
 *               -DutyCycle: type uint32                                   *
 *                                                                         *
 * RETURN :      None                                                      *
 ***************************************************************************/
void ec_pwm_output(uint8 Chn, uint32 Period, uint32 DutyCycle)
{
  if (0 == Period) {
    EMIOS.CH[Chn].CBDR.R = 0;
    EMIOS.CH[Chn].CADR.R = 0;
    EMIOS.CH[Chn].CCR.B.FORCMA = 1;
    EMIOS.CH[Chn].CCR.B.FORCMB = 1;
  } else {
    if (0 == DutyCycle) {
      EMIOS.CH[Chn].CBDR.R = Period;
      EMIOS.CH[Chn].CADR.R = 0;
      EMIOS.CH[Chn].CCR.B.FORCMA = 1;
      EMIOS.CH[Chn].CCR.B.FORCMB = 1;
    } else if (DutyCycle >= Period) {
      EMIOS.CH[Chn].CBDR.R = Period;
      EMIOS.CH[Chn].CADR.R = Period;
      EMIOS.CH[Chn].CCR.B.FORCMA = 1;
    } else {
      EMIOS.CH[Chn].CBDR.R = Period;
      EMIOS.CH[Chn].CADR.R = Period-DutyCycle;
      if (99999 >= Period) {
        EMIOS.CH[Chn].CCR.B.FORCMA = 1;
        EMIOS.CH[Chn].CCR.B.FORCMB = 1;
      } else {
      }
    }
  }
}

#endif

/* File trailer for ECUCoder generated file pwm.c.
 *
 * [EOF]
 */
