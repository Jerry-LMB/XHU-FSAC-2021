/*
 * Code generated for Simulink model Gas_Calibration.
 *
 * FILE    : gpio.c
 *
 * VERSION : 1.1
 *
 * DATE    : Sat Oct 02 12:32:17 2021
 *
 * Copyright 2011-2012 ECUCoder. All Rights Reserved.
 */

#include "gpio.h"
#if 1

/**************************************************************************
 * FUNCTION :    ec_gpio_read                                              *
 *                                                                         *
 * DESCRIPTION : Read the value of the specified GPIO channel              *
 *                                                                         *
 * PARAMETERS :  -ChannelNo: GPIO channel                                  *
 *                                                                         *
 * RETURN :      None                                                      *
 ***************************************************************************/
boolean ec_gpio_read(uint8 ChannelNo)
{
  return(SIU.GPDI[ChannelNo].B.PDI);
}

/**************************************************************************
 * FUNCTION :    ec_gpio_write                                             *
 *                                                                         *
 * DESCRIPTION : Set the specified level for the specified channel         *
 *                                                                         *
 * PARAMETERS :  -ChannelNo: GPIO channel                                  *
 *                                                                         *
 * RETURN :      None                                                      *
 ***************************************************************************/
void ec_gpio_write(uint8 ChannelNo, boolean Level)
{
  SIU.GPDO[ChannelNo].B.PDO = Level;
}

#endif

/* File trailer for ECUCoder generated file gpio.c.
 *
 * [EOF]
 */