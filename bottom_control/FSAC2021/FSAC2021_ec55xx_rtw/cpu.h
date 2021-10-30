/*
 * Code generated for Simulink model FSAC2021.
 *
 * FILE    : cpu.h
 *
 * VERSION : 1.157
 *
 * DATE    : Wed Sep 01 03:10:55 2021
 *
 * Copyright 2011-2012 ECUCoder. All Rights Reserved.
 */

#ifndef RTW_HEADER_cpu_h_
#define RTW_HEADER_cpu_h_
#include "MPC5554.h"
#include "Std_Types.h"
#define SIU_SRCR_SSR                   1                         /* Software system reset */
#define TSR_WIS_BIT                    0x4000

extern void ec_cpu_init(void);
extern void ec_cpu_reset(void);
extern void ec_wdg_init(boolean WdgEnable);
extern void ec_wdg_feed(void);

#endif                                 /* RTW_HEADER_cpu_h_ */

/* File trailer for ECUCoder generated file cpu.h.
 *
 * [EOF]
 */
