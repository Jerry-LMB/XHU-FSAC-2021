/*
 * Code generated for the formwork and Simulink model.
 *
 * FILE    : siu.c
 *
 * VERSION : 1.000
 *
 * DATE    : Mon Mar 12 10:37:43 2012
 *
 * Copyright 2011-2012 ECUCoder. All Rights Reserved.
 */
 
#include "siu.h"

/******************************************************************
 * FUNCTION :    ec_pad_init                                       *
 *                                                                 *
 * DESCRIPTION : Initialize the pad configuration register         *
 *                                                                 *
 * INPUTS :      -ConfigPtr: pointer to configuration set          *
 *                                                                 *
 * OUTPUTS :     None                                              *
 *******************************************************************/

void ec_pad_init(const Pad_ConfigType* ConfigPtr)
{
    uint8 pad = 0;    /* Pad Index: from 0 to 230 */       
    for (pad; pad<(ConfigPtr->numPads); pad++)
    {
        SIU.PCR[pad].R = ConfigPtr->Pad_PinConfiguration[pad];
    }
}

