/*
 * Code generated for Simulink model FSAC2021.
 *
 * FILE    : can_hook.c
 *
 * VERSION : 1.157
 *
 * DATE    : Wed Sep 01 03:10:55 2021
 *
 * Copyright 2011-2012 ECUCoder. All Rights Reserved.
 */

#include "can.h"

void ec_can_applrxindication(uint8 Module,uint8 BufNum,uint8 Rx_Buffer[])
{
  if (Module == CCP_CAN_MODULE) {
    if (CCP_CAN_RX_BUFNUM == BufNum) {
      CCP_CRO_Indication(Rx_Buffer);
    }
  }
}

void ec_can_appltxconfirmation(uint8 Module,uint8 BufNum)
{
  if (Module == CCP_CAN_MODULE) {
    if (CCP_CAN_TX_BUFNUM == BufNum) {
      CCP_DTO_Confirmation();
    }
  }
}

/* File trailer for ECUCoder generated file can_hook.c.
 *
 * [EOF]
 */
