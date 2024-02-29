/*******************************************************************************
* File Name: Offset_PM.c  
* Version 1.90
*
* Description:
*  This file provides the power management source code to API for the
*  VDAC8.  
*
* Note:
*  None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Offset.h"

static Offset_backupStruct Offset_backup;


/*******************************************************************************
* Function Name: Offset_SaveConfig
********************************************************************************
* Summary:
*  Save the current user configuration
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
*******************************************************************************/
void Offset_SaveConfig(void) 
{
    if (!((Offset_CR1 & Offset_SRC_MASK) == Offset_SRC_UDB))
    {
        Offset_backup.data_value = Offset_Data;
    }
}


/*******************************************************************************
* Function Name: Offset_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:  
*  void
*
* Return: 
*  void
*
*******************************************************************************/
void Offset_RestoreConfig(void) 
{
    if (!((Offset_CR1 & Offset_SRC_MASK) == Offset_SRC_UDB))
    {
        if((Offset_Strobe & Offset_STRB_MASK) == Offset_STRB_EN)
        {
            Offset_Strobe &= (uint8)(~Offset_STRB_MASK);
            Offset_Data = Offset_backup.data_value;
            Offset_Strobe |= Offset_STRB_EN;
        }
        else
        {
            Offset_Data = Offset_backup.data_value;
        }
    }
}


/*******************************************************************************
* Function Name: Offset_Sleep
********************************************************************************
* Summary:
*  Stop and Save the user configuration
*
* Parameters:  
*  void:  
*
* Return: 
*  void
*
* Global variables:
*  Offset_backup.enableState:  Is modified depending on the enable 
*  state  of the block before entering sleep mode.
*
*******************************************************************************/
void Offset_Sleep(void) 
{
    /* Save VDAC8's enable state */    
    if(Offset_ACT_PWR_EN == (Offset_PWRMGR & Offset_ACT_PWR_EN))
    {
        /* VDAC8 is enabled */
        Offset_backup.enableState = 1u;
    }
    else
    {
        /* VDAC8 is disabled */
        Offset_backup.enableState = 0u;
    }
    
    Offset_Stop();
    Offset_SaveConfig();
}


/*******************************************************************************
* Function Name: Offset_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*  
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Offset_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Offset_Wakeup(void) 
{
    Offset_RestoreConfig();
    
    if(Offset_backup.enableState == 1u)
    {
        /* Enable VDAC8's operation */
        Offset_Enable();

        /* Restore the data register */
        Offset_SetValue(Offset_Data);
    } /* Do nothing if VDAC8 was disabled before */    
}


/* [] END OF FILE */
