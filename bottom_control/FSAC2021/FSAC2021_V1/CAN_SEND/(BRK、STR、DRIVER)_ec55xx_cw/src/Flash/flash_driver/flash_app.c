#include "flash_app.h"


/* Assign function pointers */
pFLASHINIT     pFlashInit     = (pFLASHINIT)     FlashInit_C;
pFLASHERASE    pFlashErase    = (pFLASHERASE)    FlashErase_C;
pBLANKCHECK    pBlankCheck    = (pBLANKCHECK)    BlankCheck_C;
pFLASHPROGRAM  pFlashProgram  = (pFLASHPROGRAM)  FlashProgram_C;
pPROGRAMVERIFY pProgramVerify = (pPROGRAMVERIFY) ProgramVerify_C;
pCHECKSUM      pCheckSum      = (pCHECKSUM)      CheckSum_C;
pGETLOCK       pGetLock       = (pGETLOCK)       GetLock_C;
pSETLOCK       pSetLock       = (pSETLOCK)       SetLock_C;
pFLASHSUSPEND  pFlashSuspend  = (pFLASHSUSPEND)  FlashSuspend_C;
pFLASHRESUME   pFlashResume   = (pFLASHRESUME)   FlashResume_C;

SSD_CONFIG ssdConfig = {
    H7F_REG_BASE,           /* H7F control register base */
    MAIN_ARRAY_BASE,        /* base of main array */
    0,                      /* size of main array */
    SHADOW_ROW_BASE,        /* base of shadow row */
    SHADOW_ROW_SIZE,        /* size of shadow row */
    0,                      /* block number in low address space */
    0,                      /* block number in middle address space */
    0,                      /* block number in high address space */
    FLASH_PAGE_SIZE,        /* flash page size selection */
    FALSE                   /* debug mode selection */
};

void Fls_Init(void)
{
    FLASH.MCR.B.STOP=0;                              /* User mode */ 
    FLASH.LMLR.R=0xA1A11111;                         /* Set password to write enable */ 
    while(FLASH.LMLR.B.LME!=1){}                     /* Wait until LME is high */
    FLASH.LMLR.R=0x00100000;                         /* Unlock low/mid address space,Shadow block is still locked */ 
    FLASH.SLMLR.R=0xC3C33333;                        /* Set password to write enable */ 
    while(FLASH.SLMLR.B.SLE!=1){}                    /* Wait until SLE is high */
    FLASH.SLMLR.R=0x00100000;                        /* Unlock Secondary low/mid address space,Shadow block
                                                        is still locked */ 
    FLASH.HLR.R=0xB2B22222;                          /* Set password to write enable */ 
    while(FLASH.HLR.B.HBE!=1){}                      /* Wait until HBE is high */
    FLASH.HLR.R=0x00000000;                          /* Unlock high address space */ 
    FLASH.BIUAPR.R=0xffffffff;
    FLASH.BIUCR.R=0x25fd;
        
}
	
UINT32 CCP_FlashInit(void) 
{
	uint32 flashret = H7F_OK; 
	BOOL   blkLockEnabled;       /* block lock enabled state */
	UINT32 blkLockState;         /* block lock status to be retrieved */
	FLASH.BIUCR.R = 0x0000FF00; 
	
	
	FLS_DISABLE_GLOBAL_INTERRUPT;
	
  
    flashret = pFlashInit( &ssdConfig );
    if ( H7F_OK != flashret )
    {
      //return;
    }
    			

    /**************HIGH ONLY BLOCK 10 UNLOCK************/
    
     flashret = pGetLock( &ssdConfig, LOCK_HIGH, &blkLockEnabled, &blkLockState );
        
     if ( H7F_OK != flashret )
     {
         return;
     }
   
     if ((blkLockState & 0x00000FFF) != 0)
     {
         flashret = pSetLock( &ssdConfig, LOCK_HIGH, (blkLockState & 0xFFFFF3FF), FLASH_HLR_PASSWORD);
           
         if ( H7F_OK != flashret )
         {
            return;
         }
       
     }
     
  
     flashret = pGetLock( &ssdConfig, LOCK_HIGH, &blkLockEnabled, &blkLockState );
     if ( H7F_OK != flashret )
     {
        return;
     }
     if ((blkLockState & 0x00000800) != 0)
     {
        return;
     }
     
    /**************HIGH ONLY BLOCK 10 UNLOCK************/
   
	FLS_ENABLE_GLOBAL_INTERRUPT;

	return flashret;
}

Std_ReturnType Fls_Read(uint32 SourceAddress,uint8* TargetAddressPtr, uint32 Length)
{
	uint8 result;
	uint32 StartAddress;
	uint32 EndAddress;
	uint32 i;
	StartAddress=FLASH_START+SourceAddress;
	EndAddress=FLASH_START+SourceAddress+Length;
	if(StartAddress<FLASH_START||StartAddress>FLASH_END)
    {
    	result=2; 
    }
    else if(Length<1||EndAddress>FLASH_END)
    {
    	result=3;
    }
    else if(FLASH.MCR.B.ERS==1)
    {
    	result=6; 
    }
    else
    {
		for(i=0;i<Length;i++)
		{
			*(TargetAddressPtr+i)=R8(StartAddress);
			StartAddress++;
			if(i==Length-1)
			{
				result=E_OK;
			}
			else
			{
			}
		}

    }
	
	return result;
}
