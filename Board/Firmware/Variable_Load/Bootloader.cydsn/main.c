/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

void putString(const char *buffer);


//#define USBFS_BTLDR_OUT_EP_1 0x03
//#define USBFS_BTLDR_IN_EP_1  0x02

//static uint8  USBFS_started = 0u;

int main(void)
{
    CyGlobalIntEnable;
   // Bootloader_Start();
    if (Bootloader_GET_RUN_TYPE == Bootloader_START_BTLDR)
    {
        Bootloader_Start();
    }
    else 
    {
        Bootloader_SET_RUN_TYPE(Bootloader_START_APP);
        CySoftwareReset();
    }
    for(;;)
    {
        
    }
}

#if 0
void putString(const char *buffer)
{
  if (0 != (USBFS_LINE_CONTROL_DTR & USBFS_GetLineControl()) )
  {
    while (0u == USBFS_CDCIsReady());
    USBFS_PutString(buffer);
  }
}

void CyBtldrCommStart(void)
{
  USBFS_Start(0, USBFS_5V_OPERATION);
}

void CyBtldrCommStop(void)
{
  USBFS_Stop();
}

void CyBtldrCommReset(void)
{
  USBFS_Init();
}

/*cystatus CyBtldrCommWrite(uint8* pData, uint16 size, uint16 *count, uint8 timeOut) CYSMALL       */
cystatus CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 *count, uint8 timeOut) CYSMALL                                                     
{
    cystatus retCode;
    uint16 timeoutMs;
	uint16 bufIndex = 0;
	uint8 transfer_Size;
	*count = 0;
    timeoutMs = ((uint16) 10u * timeOut);  /* Convert from 10mS check to number 1mS checks */
    while(bufIndex < size)
	{
		if ((size -bufIndex) >  USBFS_BTLDR_SIZEOF_READ_BUFFER)
		{
			transfer_Size = USBFS_BTLDR_SIZEOF_READ_BUFFER;
		}
		else 
		{
			transfer_Size = (size -bufIndex);
		}
		/* Enable IN transfer */
    	USBFS_LoadInEP(USBFS_BTLDR_IN_EP_1, &pData[bufIndex], transfer_Size);
		/* Wait for the master to read it. */
   		while ((USBFS_GetEPState(USBFS_BTLDR_IN_EP_1) == USBFS_IN_BUFFER_FULL) &&
           (0u != timeoutMs))
    	{
        	CyDelay(1);
        	timeoutMs--;
    	}
		if (USBFS_GetEPState(USBFS_BTLDR_IN_EP_1) == USBFS_IN_BUFFER_FULL)
    	{
        	retCode = CYRET_TIMEOUT;
			break; 
    	}
	    else
	    {
	        *count += transfer_Size;
	        retCode = CYRET_SUCCESS;
			bufIndex  += transfer_Size;
	    }
	}
		
    return(retCode);
}

cystatus CyBtldrCommRead(uint8* pData, uint16 size, uint16 *count, uint8 timeOut) CYSMALL
                                                            
{
    cystatus retCode;
    uint16 timeoutMs;

    timeoutMs = ((uint16) 10u * timeOut);  /* Convert from 10mS check to number 1mS checks */
    
    if (size > USBFS_BTLDR_SIZEOF_WRITE_BUFFER)
    {
        size = USBFS_BTLDR_SIZEOF_WRITE_BUFFER;
    }

    /* Wait on enumeration in first time */
    if (0u != USBFS_started)
    {
        /* Wait for Device to enumerate */
        while ((0u ==USBFS_GetConfiguration()) && (0u != timeoutMs))
        {
            CyDelay(1);
            timeoutMs--;
        }
        
        /* Enable first OUT, if enumeration complete */
        if (0u != USBFS_GetConfiguration())
        {
            (void) USBFS_IsConfigurationChanged();  /* Clear configuration changes state status */
            CyBtldrCommReset();
            USBFS_started = 0u;
        }
    }
    else /* Check for configuration changes, has been done by Host */
    {
        if (0u != USBFS_IsConfigurationChanged()) /* Host could send double SET_INTERFACE request or RESET */
        {
            if (0u != USBFS_GetConfiguration())   /* Init OUT endpoints when device reconfigured */
            {
                CyBtldrCommReset();
            }
        }
    }
    
    timeoutMs = ((uint16) 10u * timeOut); /* Re-arm timeout */
    
    /* Wait on next packet */
    while((USBFS_GetEPState(USBFS_BTLDR_OUT_EP_1) != USBFS_OUT_BUFFER_FULL) && \
          (0u != timeoutMs))
    {
        CyDelay(1);
        timeoutMs--;
    }

    /* OUT EP has completed */
    if (USBFS_GetEPState(USBFS_BTLDR_OUT_EP_1) == USBFS_OUT_BUFFER_FULL)
    {
        *count = USBFS_ReadOutEP(USBFS_BTLDR_OUT_EP_1, pData, size);
        retCode = CYRET_SUCCESS;
    }
    else
    {
        *count = 0u;
        retCode = CYRET_TIMEOUT;
    }
    
    return(retCode);
}

#endif









/*
cystatus CyBtldrCommRead(uint8 *buffer,
                         uint16 size,
                         uint16 *count,
                         uint8 timeOut)
{
  uint8 timer = 0;
  
  if (0u != USBFS_GetConfiguration())
  {
    while (timer++ < timeOut)
    {
      if (0u != USBFS_DataIsReady())
      {
        *count += USBFS_GetAll(buffer);
        if (*count >= size) return CYRET_SUCCESS;
        else timer = 0;
      }
    }
  }
  return CYRET_TIMEOUT;
}

cystatus CyBtldrCommWrite(uint8* buffer, 
                          uint16 size, 
                          uint16* count, 
                          uint8 timeOut)
{
  uint8 timer = 0;
  if (0u != USBFS_GetConfiguration())
  {
    while (timer++ < timeOut) 
    {
      if (USBFS_CDCIsReady())
      {
        if (size > 64)
        {
          *count += 64;
          size -= 64;
          
          USBFS_PutData(buffer + *count, 64);
        }
        else
        {
          USBFS_PutData(buffer + *count, size);
          while (USBFS_CDCIsReady() == 0)
          {}
          USBFS_PutData(NULL, 0);
          return CYRET_SUCCESS;
        }
      }
    }
  }
  return CYRET_TIMEOUT;
}*/