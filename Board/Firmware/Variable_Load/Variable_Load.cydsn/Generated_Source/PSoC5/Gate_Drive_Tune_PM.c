/*******************************************************************************
* File Name: Gate_Drive_Tune_PM.c  
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

#include "Gate_Drive_Tune.h"

static Gate_Drive_Tune_backupStruct Gate_Drive_Tune_backup;


/*******************************************************************************
* Function Name: Gate_Drive_Tune_SaveConfig
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
void Gate_Drive_Tune_SaveConfig(void) 
{
    if (!((Gate_Drive_Tune_CR1 & Gate_Drive_Tune_SRC_MASK) == Gate_Drive_Tune_SRC_UDB))
    {
        Gate_Drive_Tune_backup.data_value = Gate_Drive_Tune_Data;
    }
}


/*******************************************************************************
* Function Name: Gate_Drive_Tune_RestoreConfig
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
void Gate_Drive_Tune_RestoreConfig(void) 
{
    if (!((Gate_Drive_Tune_CR1 & Gate_Drive_Tune_SRC_MASK) == Gate_Drive_Tune_SRC_UDB))
    {
        if((Gate_Drive_Tune_Strobe & Gate_Drive_Tune_STRB_MASK) == Gate_Drive_Tune_STRB_EN)
        {
            Gate_Drive_Tune_Strobe &= (uint8)(~Gate_Drive_Tune_STRB_MASK);
            Gate_Drive_Tune_Data = Gate_Drive_Tune_backup.data_value;
            Gate_Drive_Tune_Strobe |= Gate_Drive_Tune_STRB_EN;
        }
        else
        {
            Gate_Drive_Tune_Data = Gate_Drive_Tune_backup.data_value;
        }
    }
}


/*******************************************************************************
* Function Name: Gate_Drive_Tune_Sleep
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
*  Gate_Drive_Tune_backup.enableState:  Is modified depending on the enable 
*  state  of the block before entering sleep mode.
*
*******************************************************************************/
void Gate_Drive_Tune_Sleep(void) 
{
    /* Save VDAC8's enable state */    
    if(Gate_Drive_Tune_ACT_PWR_EN == (Gate_Drive_Tune_PWRMGR & Gate_Drive_Tune_ACT_PWR_EN))
    {
        /* VDAC8 is enabled */
        Gate_Drive_Tune_backup.enableState = 1u;
    }
    else
    {
        /* VDAC8 is disabled */
        Gate_Drive_Tune_backup.enableState = 0u;
    }
    
    Gate_Drive_Tune_Stop();
    Gate_Drive_Tune_SaveConfig();
}


/*******************************************************************************
* Function Name: Gate_Drive_Tune_Wakeup
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
*  Gate_Drive_Tune_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Gate_Drive_Tune_Wakeup(void) 
{
    Gate_Drive_Tune_RestoreConfig();
    
    if(Gate_Drive_Tune_backup.enableState == 1u)
    {
        /* Enable VDAC8's operation */
        Gate_Drive_Tune_Enable();

        /* Restore the data register */
        Gate_Drive_Tune_SetValue(Gate_Drive_Tune_Data);
    } /* Do nothing if VDAC8 was disabled before */    
}


/* [] END OF FILE */
