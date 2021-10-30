/*
 * Code generated for Simulink model FSAC2021.
 *
 * FILE    : icu.h
 *
 * VERSION : 1.157
 *
 * DATE    : Wed Sep 01 03:10:55 2021
 *
 * Copyright 2011-2012 ECUCoder. All Rights Reserved.
 */

#ifndef RTW_HEADER_icu_h_
#define RTW_HEADER_icu_h_
#include "MPC5554.h"
#include "Std_Types.h"
#define ICU_FALLING_EDGE               0
#define ICU_RISING_EDGE                1
#define ICU_BOTH_EDGES                 2

extern void ec_icu_init(uint8 Chn, uint8 IniCapture, boolean IcIntEnable);
extern uint32 ec_icu_inputcaptureread(uint8 Chn);

#endif                                 /* RTW_HEADER_icu_h_ */

/* File trailer for ECUCoder generated file icu.h.
 *
 * [EOF]
 */
