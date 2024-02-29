/*******************************************************************************
* File Name: Offset_Gain_PM.c  
* Version 2.0
*
* Description:
*  This file provides the power manager source code to the API for PGA 
*  Component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Offset_Gain.h"

static Offset_Gain_BACKUP_STRUCT  Offset_Gain_backup;


/*******************************************************************************
* Function Name: Offset_Gain_SaveConfig
********************************************************************************
*
* Summary:
*  Save the current user register configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void Offset_Gain_SaveConfig(void) 
{
    /* Nothing to save as registers are System reset on retention flops */
}


/*******************************************************************************  
* Function Name: Offset_Gain_RestoreConfig
********************************************************************************
*
* Summary:
*  Restore the register configurations.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void Offset_Gain_RestoreConfig(void) 
{
    /* Nothing to restore */
}


/*******************************************************************************   
* Function Name: Offset_Gain_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves its configuration. Should be called 
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  Offset_Gain_backup: The structure field 'enableState' is modified 
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void Offset_Gain_Sleep(void) 
{
    /* Save PGA enable state */
    if((Offset_Gain_PM_ACT_CFG_REG & Offset_Gain_ACT_PWR_EN) != 0u)
    {
        /* Component is enabled */
        Offset_Gain_backup.enableState = 1u;
        /* Stop the configuration */
        Offset_Gain_Stop();
    }
    else
    {
        /* Component is disabled */
        Offset_Gain_backup.enableState = 0u;
    }
    /* Save the configuration */
    Offset_Gain_SaveConfig();
}


/*******************************************************************************
* Function Name: Offset_Gain_Wakeup
********************************************************************************
*
* Summary:
*  Enables block's operation and restores its configuration. Should be called
*  just after awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  void
*
* Global variables:
*  Offset_Gain_backup: The structure field 'enableState' is used to 
*  restore the enable state of block after wakeup from sleep mode.
* 
*******************************************************************************/
void Offset_Gain_Wakeup(void) 
{
    /* Restore the configurations */
    Offset_Gain_RestoreConfig();
     /* Enables the component operation */
    if(Offset_Gain_backup.enableState == 1u)
    {
        Offset_Gain_Enable();
    } /* Do nothing if component was disable before */
}


/* [] END OF FILE */
