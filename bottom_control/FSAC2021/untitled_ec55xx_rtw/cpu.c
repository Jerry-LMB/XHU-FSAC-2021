/*
 * Code generated for Simulink model untitled.
 *
 * FILE    : cpu.c
 *
 * VERSION : 1.0
 *
 * DATE    : Fri Jul 23 01:50:15 2021
 *
 * Copyright 2011-2012 ECUCoder. All Rights Reserved.
 */

#include "cpu.h"

/**************************************************************************
 * FUNCTION :    ec_cpu_init                                               *
 *                                                                         *
 * DESCRIPTION : Initialize the configuration of CPU, including seting     *
 *               the PLL and the system clock                              *
 *                                                                         *
 * PARAMETERS :  None                                                      *
 *                                                                         *
 * RETURN :      None                                                      *
 ***************************************************************************/
void ec_cpu_init(void)
{
  FMPLL.SYNCR.B.PREDIV = 0;            /* Divide by: (x+1) */
  FMPLL.SYNCR.B.MFD = 6;               /* Multiply by: (x+4) */
  FMPLL.SYNCR.B.RFD = 1;               /* Divide by 2^1 */
  while (FMPLL.SYNSR.B.LOCK != 1) {
  }

  FMPLL.SYNCR.B.RFD = 0;               /* Divide by 2^0 */
}

/**************************************************************************
 * FUNCTION :    ec_cpu_reset                                              *
 *                                                                         *
 * DESCRIPTION : Perform a microcontroller reset by using the hardware     *
 *               feature of the microcontroller                            *
 *                                                                         *
 * PARAMETERS :  None                                                      *
 *                                                                         *
 * RETURN :      None                                                      *
 ***************************************************************************/
void ec_cpu_reset(void)
{
  SIU.SRCR.B.SSR = SIU_SRCR_SSR;       /* Generate a software system reset */
}

#if 0

/**************************************************************************
 * FUNCTION :    ec_wdg_init                                               *
 *                                                                         *
 * DESCRIPTION : Initialize the watchdog                                   *
 *                                                                         *
 * PARAMETERS :  -WdgEnable: 0 or 1                                        *
 *                                                                         *
 * RETURN :      None                                                      *
 ***************************************************************************/
void ec_wdg_init(boolean WdgEnable)
{
  if (WdgEnable == 1) {
    /* asm
       {
       mfspr   r14,TCR

       lis     r15,0x0FE1
       ori     r15,r15,0xFFFF
       and     r14,r14,r15

       lis     r15,40980
       or      r14,r14,r15
       mtspr   TCR, r14

       mfspr   r14,HID0
       ori     r14,r14,TSR_WIS_BIT
       mtspr   HID0, r14
       } */
  }
}

/**************************************************************************
 * FUNCTION :    ec_wdg_feed                                               *
 *                                                                         *
 * DESCRIPTION : Clear the TSR[WIS] bit to feed the watchdog               *
 *                                                                         *
 * PARAMETERS :  None                                                      *
 *                                                                         *
 * RETURN :      None                                                      *
 ***************************************************************************/
void ec_wdg_feed(void)
{
  /* asm
     {
     lis     r6,TSR_WIS_BIT
     mtspr   TSR,r6
     blr
     }	*/
}

#endif

/* File trailer for ECUCoder generated file cpu.c.
 *
 * [EOF]
 */
