/*************************************************************************
 *            (c) Copyright Motorola 2005, All Rights Reserved           *
 *************************************************************************
 *                                                                       *
 *   Motorola reserves the right to make changes without further notice  *
 *   to any product herein to improve reliability, function or design.   *
 *   Motorola does not assume any liability arising out of the           *
 *   application or use of any product, circuit, or software described   *
 *   herein; neither does it convey any license under its patent rights  *
 *   nor the rights of others.                                           *
 *                                                                       *
 *   Motorola products are not designed, intended, or authorized for     *
 *   use as components in systems intended for surgical implant into     *
 *   the body, or other applications intended to support life, or for    *
 *   any other application in which the failure of the Motorola product  *
 *   could create a situation where personal injury or death may occur.  *
 *                                                                       *
 *   Should Buyer purchase or use Motorola products for any such         *
 *   unintended or unauthorized application, Buyer shall indemnify and   *
 *   hold Motorola and its officers, employees, subsidiaries,            *
 *   affiliates, and distributors harmless against all claims costs,     *
 *   damages, and expenses, and reasonable attorney fees arising out     *
 *   of, directly or indirectly, any claim of personal injury or death   *
 *   associated with such unintended or unauthorized use, even if such   *
 *   claim alleges that Motorola was negligent regarding the design      *
 *   or manufacture of the part.                                         *
 *                                                                       *
 *   Motorola and the Motorola logo* are registered trademarks of        *
 *   Motorola Ltd.                                                       *
 *                                                                       *
 *************************************************************************

 *************************************************************************
 *                                                                       *
 *               Standard Software H7F Driver for MPC55xx                *
 *                            Demo Header File                           *
 *                                                                       *
 * FILE NAME     :  demo.h                                               *
 * DATE          :  June 23, 2005                                        *
 *                                                                       *
 * AUTHOR        :  Flash Team,                                          *
 *                  Global Software Group, China, Motorola Inc.          *
 * E-mail        :  flash@sc.mcel.mot.com                                *
 *                                                                       *
 *************************************************************************/

/******************************* CHANGES *********************************
 1.00   2005.06.23       Cloud Li        Initial Version
 1.01	2005.07.19		 Chen He		 Add #define to support multiple MCUs
 *************************************************************************/

#ifndef _DEMO_H_
#define _DEMO_H_

#ifdef FLS_EXTERN_H
    #define FLS_EXTERN
#else
    #define FLS_EXTERN extern
#endif

#include   "ssd_types.h"
#include   "ssd_h7f.h"
#include   "Std_Types.h"
#include   "MPC5554.h"
#define MPC5554      1

#define FLASH_SSD_ERROR_TRAP 1
/* The maximum time of suspend operation allowed in the callback functions */
#define    MAX_SUSPEND_COUNT               4

#if ((MPC5554 + MPC5534) > 1)
	#error	"Err:  Cannot define multiple MCUs simultaneously!!!"
#endif
 
#define H7F_REG_BASE                    0xC3F88000
#define MAIN_ARRAY_BASE                 0x00000000

#if MPC5554
#define SHADOW_ROW_BASE                 0x00FFFC00
#define SHADOW_ROW_SIZE                 0x00000400
#define FLASH_PAGE_SIZE                 H7FA_PAGE_SIZE
#endif

#if MPC5534
#define SHADOW_ROW_BASE                 0x00FF8000
#define SHADOW_ROW_SIZE                 0x00008000
#define FLASH_PAGE_SIZE                 H7FB_PAGE_SIZE
#endif

#define BUFFER_SIZE_BYTE                0x200
#define BUFFER2_SIZE_BYTE               0x100
/* Low space block 0 */
#define OFFSET_LOW_BLOCK0               0x00000000 /* Offset of low block 0 */
#define LOW_BLOCK0_SIZE                 0x4000     /* 16KB size */

/* Low space block 1 */
#define OFFSET_LOW_BLOCK1               0x00004000 /* Offset of low block 1, in same partition with block 0 */
#define LOW_BLOCK1_SIZE                 0xC000     /* 48KB size */

/* Low space block 2 */
#define OFFSET_LOW_BLOCK2               0x00010000 /* Offset of low block 2, in same partition with block 0 and 1 */
#define LOW_BLOCK2_SIZE                 0xC000     /* 48KB size */

/* Low space block 3 */
#define OFFSET_LOW_BLOCK3               0x0001C000 /* Offset of low block 3, in same partition with block 0, 1 and 2 */
#define LOW_BLOCK3_SIZE                 0x4000     /* 16KB size */

/* Low space block 4 */
#define OFFSET_LOW_BLOCK4               0x00020000 /* Offset of low block 4, in same partition with block 0, 1 and 2 */
#define LOW_BLOCK4_SIZE                 0x10000     /* 64KB size */

/* Low space block 5 */
#define OFFSET_LOW_BLOCK5               0x00030000 /* Offset of low block 4, in same partition with block 0, 1 and 2 */
#define LOW_BLOCK5_SIZE                 0x10000     /* 64KB size */



/* Middle space block 0 */
#define OFFSET_MID_BLOCK0               0x00040000 /* Offset of middle block 0 */
#define MID_BLOCK0_SIZE                 0x20000    /* 128KB size */

/* Middle space block 1 */
#define OFFSET_MID_BLOCK1               0x00060000 /* Offset of middle block 1 */
#define MID_BLOCK1_SIZE                 0x20000    /* 128KB size */




/* High space block 0 */
#define OFFSET_HIGH_BLOCK0              0x00080000 /* Offset of high block 0 */
#define HIGH_BLOCK0_SIZE                0x20000    /* 128KB size */

/* High space block 1 */
#define OFFSET_HIGH_BLOCK1              0x000A0000 /* Offset of high block 1 */
#define HIGH_BLOCK1_SIZE                0x20000    /* 128KB size */

/* High space block 2 */
#define OFFSET_HIGH_BLOCK2              0x000C0000 /* Offset of high block 2 */
#define HIGH_BLOCK2_SIZE                0x20000    /* 128KB size */

/* High space block 3 */
#define OFFSET_HIGH_BLOCK3              0x000E0000 /* Offset of high block 3 */
#define HIGH_BLOCK3_SIZE                0x20000    /* 128KB size */

/* High space block 4 */
#define OFFSET_HIGH_BLOCK4              0x00100000 /* Offset of high block 4 */
#define HIGH_BLOCK4_SIZE                0x20000    /* 128KB size */

/* High space block 5 */
#define OFFSET_HIGH_BLOCK5              0x00120000 /* Offset of high block 5 */
#define HIGH_BLOCK5_SIZE                0x20000    /* 128KB size */

/* High space block 6 */
#define OFFSET_HIGH_BLOCK6              0x00140000 /* Offset of high block 6 */
#define HIGH_BLOCK6_SIZE                0x20000    /* 128KB size */

/* High space block 7 */
#define OFFSET_HIGH_BLOCK7              0x00160000 /* Offset of high block 7 */
#define HIGH_BLOCK7_SIZE                0x20000    /* 128KB size */

/* High space block 8 */
#define OFFSET_HIGH_BLOCK8              0x00180000 /* Offset of high block 8 */
#define HIGH_BLOCK8_SIZE                0x20000    /* 128KB size */

/* High space block 9 */
#define OFFSET_HIGH_BLOCK9              0x001A0000 /* Offset of high block 9 */
#define HIGH_BLOCK9_SIZE                0x20000    /* 128KB size */

/* High space block 10 */
#define OFFSET_HIGH_BLOCK10              0x001C0000 /* Offset of high block 10 */
#define HIGH_BLOCK10_SIZE                0x20000    /* 128KB size */

/* High space block 11 */
#define OFFSET_HIGH_BLOCK11              0x001E0000 /* Offset of high block 11 */
#define HIGH_BLOCK11_SIZE                0x20000    /* 128KB size */

/* Password to unlock space array */
#define FLASH_LMLR_PASSWORD             0xA1A11111  /* Low/Mid address lock enabled password */
#define FLASH_HLR_PASSWORD              0xB2B22222  /* High address lock enabled password */
#define FLASH_SLMLR_PASSWORD            0xC3C33333  /* Secondary low and middle address lock enabled password */

#define DEMO_PASS                       0x00
#define DEMO_FAIL                       0xFF

/* Define the ECC error return code */
#define DEMO_DATA_EXCEPTION             0xEA

/* Enable/Disable global interrupts */
#define FLS_DISABLE_GLOBAL_INTERRUPT	 asm(" wrteei 0");
#define FLS_ENABLE_GLOBAL_INTERRUPT	     asm(" wrteei 1");

#define R8(addr)                  (*((uint8 *) (addr)))

FLS_EXTERN SSD_CONFIG ssdConfig;



/* Funciton array */
FLS_EXTERN const unsigned int FlashInit_C[];
FLS_EXTERN const unsigned int FlashErase_C[];
FLS_EXTERN const unsigned int BlankCheck_C[];
FLS_EXTERN const unsigned int FlashProgram_C[];
FLS_EXTERN const unsigned int ProgramVerify_C[];
FLS_EXTERN const unsigned int CheckSum_C[];
FLS_EXTERN const unsigned int GetLock_C[];
FLS_EXTERN const unsigned int SetLock_C[];
FLS_EXTERN const unsigned int FlashSuspend_C[];
FLS_EXTERN const unsigned int FlashResume_C[];

/* Assign function pointers */
FLS_EXTERN pFLASHINIT     pFlashInit;
FLS_EXTERN pFLASHERASE    pFlashErase;
FLS_EXTERN pBLANKCHECK    pBlankCheck;
FLS_EXTERN pFLASHPROGRAM  pFlashProgram;
FLS_EXTERN pPROGRAMVERIFY pProgramVerify;
FLS_EXTERN pCHECKSUM      pCheckSum;
FLS_EXTERN pGETLOCK       pGetLock ;
FLS_EXTERN pSETLOCK       pSetLock;
FLS_EXTERN pFLASHSUSPEND  pFlashSuspend;
FLS_EXTERN pFLASHRESUME   pFlashResume;

FLS_EXTERN UINT32 CCP_FlashInit(void);


#endif