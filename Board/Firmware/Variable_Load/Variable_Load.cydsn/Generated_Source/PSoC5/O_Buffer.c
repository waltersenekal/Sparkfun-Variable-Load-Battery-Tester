/*******************************************************************************
* File Name: O_Buffer.c
* Version 1.90
*
* Description:
*  This file provides the source code to the API for OpAmp (Analog Buffer) 
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

#include "O_Buffer.h"

uint8 O_Buffer_initVar = 0u;


/*******************************************************************************   
* Function Name: O_Buffer_Init
********************************************************************************
*
* Summary:
*  Initialize component's parameters to the parameters set by user in the 
*  customizer of the component placed onto schematic. Usually called in 
*  O_Buffer_Start().
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void O_Buffer_Init(void) 
{
    O_Buffer_SetPower(O_Buffer_DEFAULT_POWER);
}


/*******************************************************************************   
* Function Name: O_Buffer_Enable
********************************************************************************
*
* Summary:
*  Enables the OpAmp block operation
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void O_Buffer_Enable(void) 
{
    /* Enable negative charge pumps in ANIF */
    O_Buffer_PUMP_CR1_REG  |= (O_Buffer_PUMP_CR1_CLKSEL | O_Buffer_PUMP_CR1_FORCE);

    /* Enable power to buffer in active mode */
    O_Buffer_PM_ACT_CFG_REG |= O_Buffer_ACT_PWR_EN;

    /* Enable power to buffer in alternative active mode */
    O_Buffer_PM_STBY_CFG_REG |= O_Buffer_STBY_PWR_EN;
}


/*******************************************************************************
* Function Name:   O_Buffer_Start
********************************************************************************
*
* Summary:
*  The start function initializes the Analog Buffer with the default values and 
*  sets the power to the given level. A power level of 0, is same as 
*  executing the stop function.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  O_Buffer_initVar: Used to check the initial configuration, modified 
*  when this function is called for the first time.
*
*******************************************************************************/
void O_Buffer_Start(void) 
{
    if(O_Buffer_initVar == 0u)
    {
        O_Buffer_initVar = 1u;
        O_Buffer_Init();
    }

    O_Buffer_Enable();
}


/*******************************************************************************
* Function Name: O_Buffer_Stop
********************************************************************************
*
* Summary:
*  Powers down amplifier to lowest power state.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void O_Buffer_Stop(void) 
{
    /* Disable power to buffer in active mode template */
    O_Buffer_PM_ACT_CFG_REG &= (uint8)(~O_Buffer_ACT_PWR_EN);

    /* Disable power to buffer in alternative active mode template */
    O_Buffer_PM_STBY_CFG_REG &= (uint8)(~O_Buffer_STBY_PWR_EN);
    
    /* Disable negative charge pumps for ANIF only if all ABuf is turned OFF */
    if(O_Buffer_PM_ACT_CFG_REG == 0u)
    {
        O_Buffer_PUMP_CR1_REG &= (uint8)(~(O_Buffer_PUMP_CR1_CLKSEL | O_Buffer_PUMP_CR1_FORCE));
    }
}


/*******************************************************************************
* Function Name: O_Buffer_SetPower
********************************************************************************
*
* Summary:
*  Sets power level of Analog buffer.
*
* Parameters: 
*  power: PSoC3: Sets power level between low (1) and high power (3).
*         PSoC5: Sets power level High (0)
*
* Return:
*  void
*
**********************************************************************************/
void O_Buffer_SetPower(uint8 power) 
{
    #if (CY_PSOC3 || CY_PSOC5LP)
        O_Buffer_CR_REG &= (uint8)(~O_Buffer_PWR_MASK);
        O_Buffer_CR_REG |= power & O_Buffer_PWR_MASK;      /* Set device power */
    #else
        CYASSERT(O_Buffer_HIGHPOWER == power);
    #endif /* CY_PSOC3 || CY_PSOC5LP */
}


/* [] END OF FILE */
