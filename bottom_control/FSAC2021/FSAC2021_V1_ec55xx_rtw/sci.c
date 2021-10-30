/*
 * Code generated for Simulink model FSAC2021_V1.
 *
 * FILE    : sci.c
 *
 * VERSION : 1.219
 *
 * DATE    : Sat Oct 30 18:49:46 2021
 *
 * Copyright 2011-2012 ECUCoder. All Rights Reserved.
 */

#include "sci.h"
#if 0

/**************************************************************************
 * FUNCTION :    ec_scia_init                                              *
 *                                                                         *
 * DESCRIPTION : Initialize eSCIA module                                   *
 *                                                                         *
 * PARAMETERS :  None                                                      *
 *                                                                         *
 * RETURN :      None                                                      *
 ***************************************************************************/
void ec_scia_init(void)
{
  ESCI(0).CR2.B.MDIS = !0;             /* Module is enabled */
  ESCI(0).CR2.B.FBR = 0;               /* Bit errors will be detected on a per byte basis */
  ESCI(0).CR2.B.BSTP = 1;              /* Bit error/physical bus error stop */
  ESCI(0).CR2.B.IEBERR = 0;            /* Disable bit error interrupt */
  ESCI(0).CR1.B.SBR = 520;             /* Set baudrate */
  ESCI(0).CR1.B.M = 0;                 /* M=0 for 1 start bit, 8 data bits, 1 stop bit; M=1 for 9 data bits */
  ESCI(0).CR1.B.PE = 0;                /* PE=0 for disabled Parity function; PE=1 for enabled */
  ESCI(0).CR1.B.PT = 0;                /* PT=0 for even parity; PT=1 for odd parity */
  ESCI(0).CR1.B.TE = 1;                /* Transmitter enable */
  ESCI(0).CR1.B.RE = 1;                /* Receiver enable */
  ESCI(0).CR1.B.TIE = 0;               /* Transmitter interrupt */
  ESCI(0).CR1.B.RIE = 0;               /* Receiver full interrupt */
  SIU.PCR[89].R = 0x0600;              /* Configure pad for primary function: TxDA */
  SIU.PCR[90].R = 0x0500;              /* Configure pad for primary function: RxDA */
}

void ec_lin_init(void)
{
  ESCI(0).CR2.B.FBR = 1;
  ESCI(0).CR2.B.BESM13 = 1;
  ESCI(0).CR2.B.BRK13 = 1;
  ESCI(0).CR2.B.BSTP = 1;
  ESCI(0).CR2.B.SBSTP = 1;
  ESCI(0).LCR.B.LIN = 1;
  ESCI(0).LCR.B.LDBG = 0;
}

#endif

#if 0

/**************************************************************************
 * FUNCTION :    ec_scib_init                                              *
 *                                                                         *
 * DESCRIPTION : Initialize eSCIB module                                   *
 *                                                                         *
 * PARAMETERS :  None                                                      *
 *                                                                         *
 * RETURN :      None                                                      *
 ***************************************************************************/
void ec_scib_init(void)
{
  ESCI(1).CR2.B.MDIS = !0;             /* Module is enabled */
  ESCI(1).CR2.B.FBR = 0;               /* Bit errors will be detected on a per byte basis */
  ESCI(1).CR2.B.BSTP = 1;              /* Bit error/physical bus error stop */
  ESCI(1).CR2.B.IEBERR = 0;            /* Disable bit error interrupt. */
  ESCI(1).CR1.B.SBR = 520;             /* Set baudrate */
  ESCI(1).CR1.B.M = 0;                 /* M=0 for 1 start bit, 8 data bits, 1 stop bit; M=1 for 9 data bits */
  ESCI(1).CR1.B.PE = 0;                /* PE=0 for disabled Parity function; PE=1 for enabled */
  ESCI(1).CR1.B.PT = 0;                /* PT=0 for even parity; PT=1 for odd parity */
  ESCI(1).CR1.B.TE = 1;                /* Transmitter enable */
  ESCI(1).CR1.B.RE = 1;                /* Receiver enable */
  ESCI(1).CR1.B.TIE = 0;               /* Transmitter interrupt */
  ESCI(1).CR1.B.RIE = 0;               /* Receiver full interrupt */
  SIU.PCR[91].R = 0x0600;              /* Configure pad for primary function: TxDA */
  SIU.PCR[92].R = 0x0500;              /* Configure pad for primary function: RxDA */
}

#endif

#if (SCIAENABLE||SCIBENABLE)

/**************************************************************************
 * FUNCTION :    ec_sci_receive                                            *
 *                                                                         *
 * DESCRIPTION : Read the received data                                    *
 *                                                                         *
 * PARAMETERS :  -Module: can be eSCIA, eSCIB                              *
 *                                                                         *
 * RETURN :      -data: the data received by eSCI                          *
 ***************************************************************************/
uint8 ec_sci_receive(uint8 Module)
{
  uint8 data = 0;
  while (ESCI(Module).SR.B.RDRF == 0) {
  }                                    /* Wait for receive data reg full = 1 */

  ESCI(Module).SR.R = 0x20000000;      /* Clear RDRF flag */
  data = ESCI(Module).DR.B.D;          /* Read byte of data */
  return data;
}

/**************************************************************************
 * FUNCTION :    ec_sci_transmit                                           *
 *                                                                         *
 * DESCRIPTION : Transmit the given data                                   *
 *                                                                         *
 * PARAMETERS :  -Module: can be eSCIA,eSCIB                               *
 *               -Datalength: can be 1~8 bytes                             *
 *               -Tx_Buffer: a pointer pointing to the data                *
 *                to be transmitted                                        *
 *                                                                         *
 * RETURN :      None                                                      *
 ***************************************************************************/
void ec_sci_transmit(uint8 Module, uint8 Datalength, uint8 Tx_Buffer[])
{
  uint8 i;
  for (i=0; i<Datalength; i++) {
    while (ESCI(Module).SR.B.TDRE == 0) {
    }                                  /* Wait for transmit data reg empty = 1 */

    ESCI(Module).SR.R = 0x80000000;    /* Clear TDRE flag */
    ESCI(Module).DR.B.D = Tx_Buffer[i];/* Transmit 8 bits data */
  }
}

#endif

/* File trailer for ECUCoder generated file sci.c.
 *
 * [EOF]
 */
