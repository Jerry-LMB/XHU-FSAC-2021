/*
 * Code generated for Simulink model untitled.
 *
 * FILE    : rti.h
 *
 * VERSION : 1.0
 *
 * DATE    : Fri Jul 23 01:50:15 2021
 *
 * Copyright 2011-2012 ECUCoder. All Rights Reserved.
 */

#ifndef RTW_HEADER_rti_h_
#define RTW_HEADER_rti_h_
#include "MPC5554.h"
#include "Std_Types.h"
#define RTI_TIMER_VALUE_MIN            12
#define RTI_TIMER_VALUE_MAX            10000000

extern void ec_rti_init(uint32 Counter);
extern void ISR_Rti_CH23(void);

#endif                                 /* RTW_HEADER_rti_h_ */

/* File trailer for ECUCoder generated file rti.h.
 *
 * [EOF]
 */
