/*
 * Code generated for the formwork and Simulink model.
 *
 * FILE    : siu.h
 *
 * VERSION : 1.000
 *
 * DATE    : Mon Mar 12 10:37:43 2012
 *
 * Copyright 2011-2012 ECUCoder. All Rights Reserved.
 */

#ifndef RTW_HEADER_siu_h_
#define RTW_HEADER_siu_h_

#include "Std_Types.h"
#include "MPC5554.h"
#include "pcr.h"

typedef struct 
{   
    uint8 numPads;                              /* Number of pads Configured */
    const uint16 *Pad_PinConfiguration;
} Pad_ConfigType;

extern void ec_pad_init(const Pad_ConfigType* ConfigPtr);


extern const Pad_ConfigType Pad_ConfigurationPB;


#endif /* RTW_HEADER_siu_h_ */                                       
