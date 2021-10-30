/*
 * Code generated for the formwork and Simulink model.
 *
 * FILE    : interrupts.c
 *
 * VERSION : 1.000
 *
 * DATE    : Fri Feb 10 12:50:20 2012
 *
 * Copyright 2011-2012 ECUCoder. All Rights Reserved.
 */

#include "interrupts.h"

/**************************************************************************
 * FUNCTION :    ec_interrupts_init                                        *
 *                                                                         *
 * DESCRIPTION : Initialize the interrupt controller                       *
 *                                                                         *
 * PARAMETERS :  None                                                      *
 *                                                                         *
 * RETURN :      None                                                      *
 ***************************************************************************/
void ec_interrupts_init(void)
{
    INTC.MCR.B.HVEN = 0;       /* Software vector mode */
    INTC.MCR.B.VTES = 0;       /* 4 bytes */
    INTC.CPR.B.PRI = 0;        /* Proprity 0(lowest proprity) */   
}
  
/**************************************************************************
 * FUNCTION :    ec_interrupts_allintreg                                   *
 *                                                                         *
 * DESCRIPTION : Initialize the interrupt source                           *
 *                                                                         *
 * PARAMETERS :  None                                                      *
 *                                                                         *
 * RETURN :      None                                                      *
 ***************************************************************************/
void ec_interrupts_allintreg(void)
{
    INTC_InstallINTCInterruptHandler( ISR_Rti_CH23, SOFT_INT_VEC_EMIOS_GFR_F23, RTI_INTC_PRIORITY );    
}

