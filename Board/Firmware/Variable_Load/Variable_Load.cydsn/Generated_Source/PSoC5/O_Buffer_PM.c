/*******************************************************************************
* File Name: O_Buffer_PM.c
* Version 1.90
*
* Description:
*  This file provides the power management source code to the API for the 
*  OpAmp (Analog Buffer) component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "O_Buffer.h"

static O_Buffer_BACKUP_STRUCT  O_Buffer_backup;


/*******************************************************************************  
* Function Name: O_Buffer_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration registers.
* 
* Parameters:
*  void
* 
* Return:
*  void
*
*******************************************************************************/
void O_Buffer_SaveConfig(void) 
{
    /* Nothing to save as registers are System reset on retention flops */
}


/*******************************************************************************  
* Function Name: O_Buffer_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration registers.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void O_Buffer_RestoreConfig(void) 
{
    /* Nothing to restore */
}


/*******************************************************************************   
* Function Name: O_Buffer_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves its configuration. Should be called 
*  just prior to entering sleep.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  O_Buffer_backup: The structure field 'enableState' is modified 
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void O_Buffer_Sleep(void) 
{
    /* Save OpAmp enable state */
    if((O_Buffer_PM_ACT_CFG_REG & O_Buffer_ACT_PWR_EN) != 0u)
    {
        /* Component is enabled */
        O_Buffer_backup.enableState = 1u;
         /* Stops the component */
         O_Buffer_Stop();
    }
    else
    {
        /* Component is disabled */
        O_Buffer_backup.enableState = 0u;
    }
    /* Saves the configuration */
    O_Buffer_SaveConfig();
}


/*******************************************************************************  
* Function Name: O_Buffer_Wakeup
********************************************************************************
*
* Summary:
*  Enables block's operation and restores its configuration. Should be called
*  just after awaking from sleep.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  O_Buffer_backup: The structure field 'enableState' is used to 
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void O_Buffer_Wakeup(void) 
{
    /* Restore the user configuration */
    O_Buffer_RestoreConfig();

    /* Enables the component operation */
    if(O_Buffer_backup.enableState == 1u)
    {
        O_Buffer_Enable();
    } /* Do nothing if component was disable before */
}


/* [] END OF FILE */
