/***************************************************************************
* File Name: SourceDMA_dma.c  
* Version 1.70
*
*  Description:
*   Provides an API for the DMAC component. The API includes functions
*   for the DMA controller, DMA channels and Transfer Descriptors.
*
*
*   Note:
*     This module requires the developer to finish or fill in the auto
*     generated funcions and setup the dma channel and TD's.
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/
#include <CYLIB.H>
#include <CYDMAC.H>
#include <SourceDMA_dma.H>



/****************************************************************************
* 
* The following defines are available in Cyfitter.h
* 
* 
* 
* SourceDMA__DRQ_CTL_REG
* 
* 
* SourceDMA__DRQ_NUMBER
* 
* Number of TD's used by this channel.
* SourceDMA__NUMBEROF_TDS
* 
* Priority of this channel.
* SourceDMA__PRIORITY
* 
* True if SourceDMA_TERMIN_SEL is used.
* SourceDMA__TERMIN_EN
* 
* TERMIN interrupt line to signal terminate.
* SourceDMA__TERMIN_SEL
* 
* 
* True if SourceDMA_TERMOUT0_SEL is used.
* SourceDMA__TERMOUT0_EN
* 
* 
* TERMOUT0 interrupt line to signal completion.
* SourceDMA__TERMOUT0_SEL
* 
* 
* True if SourceDMA_TERMOUT1_SEL is used.
* SourceDMA__TERMOUT1_EN
* 
* 
* TERMOUT1 interrupt line to signal completion.
* SourceDMA__TERMOUT1_SEL
* 
****************************************************************************/


/* Zero based index of SourceDMA dma channel */
uint8 SourceDMA_DmaHandle = DMA_INVALID_CHANNEL;

/*********************************************************************
* Function Name: uint8 SourceDMA_DmaInitalize
**********************************************************************
* Summary:
*   Allocates and initialises a channel of the DMAC to be used by the
*   caller.
*
* Parameters:
*   BurstCount.
*       
*       
*   ReqestPerBurst.
*       
*       
*   UpperSrcAddress.
*       
*       
*   UpperDestAddress.
*       
*
* Return:
*   The channel that can be used by the caller for DMA activity.
*   DMA_INVALID_CHANNEL (0xFF) if there are no channels left. 
*
*
*******************************************************************/
uint8 SourceDMA_DmaInitialize(uint8 BurstCount, uint8 ReqestPerBurst, uint16 UpperSrcAddress, uint16 UpperDestAddress) 
{

    /* Allocate a DMA channel. */
    SourceDMA_DmaHandle = (uint8)SourceDMA__DRQ_NUMBER;

    /* Configure the channel. */
    (void)CyDmaChSetConfiguration(SourceDMA_DmaHandle,
                                  BurstCount,
                                  ReqestPerBurst,
                                  (uint8)SourceDMA__TERMOUT0_SEL,
                                  (uint8)SourceDMA__TERMOUT1_SEL,
                                  (uint8)SourceDMA__TERMIN_SEL);

    /* Set the extended address for the transfers */
    (void)CyDmaChSetExtendedAddress(SourceDMA_DmaHandle, UpperSrcAddress, UpperDestAddress);

    /* Set the priority for this channel */
    (void)CyDmaChPriority(SourceDMA_DmaHandle, (uint8)SourceDMA__PRIORITY);
    
    return SourceDMA_DmaHandle;
}

/*********************************************************************
* Function Name: void SourceDMA_DmaRelease
**********************************************************************
* Summary:
*   Frees the channel associated with SourceDMA.
*
*
* Parameters:
*   void.
*
*
*
* Return:
*   void.
*
*******************************************************************/
void SourceDMA_DmaRelease(void) 
{
    /* Disable the channel */
    (void)CyDmaChDisable(SourceDMA_DmaHandle);
}

