/*******************************************************************************
* File Name: Gate_Drive_Tune.c  
* Version 1.90
*
* Description:
*  This file provides the source code to the API for the 8-bit Voltage DAC 
*  (VDAC8) User Module.
*
* Note:
*  Any unusual or non-standard behavior should be noted here. Other-
*  wise, this section should remain blank.
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Gate_Drive_Tune.h"

#if (CY_PSOC5A)
#include <CyLib.h>
#endif /* CY_PSOC5A */

uint8 Gate_Drive_Tune_initVar = 0u;

#if (CY_PSOC5A)
    static uint8 Gate_Drive_Tune_restoreVal = 0u;
#endif /* CY_PSOC5A */

#if (CY_PSOC5A)
    static Gate_Drive_Tune_backupStruct Gate_Drive_Tune_backup;
#endif /* CY_PSOC5A */


/*******************************************************************************
* Function Name: Gate_Drive_Tune_Init
********************************************************************************
* Summary:
*  Initialize to the schematic state.
* 
* Parameters:
*  void:
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void Gate_Drive_Tune_Init(void) 
{
    Gate_Drive_Tune_CR0 = (Gate_Drive_Tune_MODE_V );

    /* Set default data source */
    #if(Gate_Drive_Tune_DEFAULT_DATA_SRC != 0 )
        Gate_Drive_Tune_CR1 = (Gate_Drive_Tune_DEFAULT_CNTL | Gate_Drive_Tune_DACBUS_ENABLE) ;
    #else
        Gate_Drive_Tune_CR1 = (Gate_Drive_Tune_DEFAULT_CNTL | Gate_Drive_Tune_DACBUS_DISABLE) ;
    #endif /* (Gate_Drive_Tune_DEFAULT_DATA_SRC != 0 ) */

    /* Set default strobe mode */
    #if(Gate_Drive_Tune_DEFAULT_STRB != 0)
        Gate_Drive_Tune_Strobe |= Gate_Drive_Tune_STRB_EN ;
    #endif/* (Gate_Drive_Tune_DEFAULT_STRB != 0) */

    /* Set default range */
    Gate_Drive_Tune_SetRange(Gate_Drive_Tune_DEFAULT_RANGE); 

    /* Set default speed */
    Gate_Drive_Tune_SetSpeed(Gate_Drive_Tune_DEFAULT_SPEED);
}


/*******************************************************************************
* Function Name: Gate_Drive_Tune_Enable
********************************************************************************
* Summary:
*  Enable the VDAC8
* 
* Parameters:
*  void
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void Gate_Drive_Tune_Enable(void) 
{
    Gate_Drive_Tune_PWRMGR |= Gate_Drive_Tune_ACT_PWR_EN;
    Gate_Drive_Tune_STBY_PWRMGR |= Gate_Drive_Tune_STBY_PWR_EN;

    /*This is to restore the value of register CR0 ,
    which is modified  in Stop API , this prevents misbehaviour of VDAC */
    #if (CY_PSOC5A)
        if(Gate_Drive_Tune_restoreVal == 1u) 
        {
             Gate_Drive_Tune_CR0 = Gate_Drive_Tune_backup.data_value;
             Gate_Drive_Tune_restoreVal = 0u;
        }
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: Gate_Drive_Tune_Start
********************************************************************************
*
* Summary:
*  The start function initializes the voltage DAC with the default values, 
*  and sets the power to the given level.  A power level of 0, is the same as
*  executing the stop function.
*
* Parameters:
*  Power: Sets power level between off (0) and (3) high power
*
* Return:
*  void 
*
* Global variables:
*  Gate_Drive_Tune_initVar: Is modified when this function is called for the 
*  first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void Gate_Drive_Tune_Start(void)  
{
    /* Hardware initiazation only needs to occure the first time */
    if(Gate_Drive_Tune_initVar == 0u)
    { 
        Gate_Drive_Tune_Init();
        Gate_Drive_Tune_initVar = 1u;
    }

    /* Enable power to DAC */
    Gate_Drive_Tune_Enable();

    /* Set default value */
    Gate_Drive_Tune_SetValue(Gate_Drive_Tune_DEFAULT_DATA); 
}


/*******************************************************************************
* Function Name: Gate_Drive_Tune_Stop
********************************************************************************
*
* Summary:
*  Powers down DAC to lowest power state.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void Gate_Drive_Tune_Stop(void) 
{
    /* Disble power to DAC */
    Gate_Drive_Tune_PWRMGR &= (uint8)(~Gate_Drive_Tune_ACT_PWR_EN);
    Gate_Drive_Tune_STBY_PWRMGR &= (uint8)(~Gate_Drive_Tune_STBY_PWR_EN);

    /* This is a work around for PSoC5A  ,
    this sets VDAC to current mode with output off */
    #if (CY_PSOC5A)
        Gate_Drive_Tune_backup.data_value = Gate_Drive_Tune_CR0;
        Gate_Drive_Tune_CR0 = Gate_Drive_Tune_CUR_MODE_OUT_OFF;
        Gate_Drive_Tune_restoreVal = 1u;
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: Gate_Drive_Tune_SetSpeed
********************************************************************************
*
* Summary:
*  Set DAC speed
*
* Parameters:
*  power: Sets speed value
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void Gate_Drive_Tune_SetSpeed(uint8 speed) 
{
    /* Clear power mask then write in new value */
    Gate_Drive_Tune_CR0 &= (uint8)(~Gate_Drive_Tune_HS_MASK);
    Gate_Drive_Tune_CR0 |=  (speed & Gate_Drive_Tune_HS_MASK);
}


/*******************************************************************************
* Function Name: Gate_Drive_Tune_SetRange
********************************************************************************
*
* Summary:
*  Set one of three current ranges.
*
* Parameters:
*  Range: Sets one of Three valid ranges.
*
* Return:
*  void 
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void Gate_Drive_Tune_SetRange(uint8 range) 
{
    Gate_Drive_Tune_CR0 &= (uint8)(~Gate_Drive_Tune_RANGE_MASK);      /* Clear existing mode */
    Gate_Drive_Tune_CR0 |= (range & Gate_Drive_Tune_RANGE_MASK);      /*  Set Range  */
    Gate_Drive_Tune_DacTrim();
}


/*******************************************************************************
* Function Name: Gate_Drive_Tune_SetValue
********************************************************************************
*
* Summary:
*  Set 8-bit DAC value
*
* Parameters:  
*  value:  Sets DAC value between 0 and 255.
*
* Return: 
*  void 
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void Gate_Drive_Tune_SetValue(uint8 value) 
{
    #if (CY_PSOC5A)
        uint8 Gate_Drive_Tune_intrStatus = CyEnterCriticalSection();
    #endif /* CY_PSOC5A */

    Gate_Drive_Tune_Data = value;                /*  Set Value  */

    /* PSOC5A requires a double write */
    /* Exit Critical Section */
    #if (CY_PSOC5A)
        Gate_Drive_Tune_Data = value;
        CyExitCriticalSection(Gate_Drive_Tune_intrStatus);
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: Gate_Drive_Tune_DacTrim
********************************************************************************
*
* Summary:
*  Set the trim value for the given range.
*
* Parameters:
*  range:  1V or 4V range.  See constants.
*
* Return:
*  void
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void Gate_Drive_Tune_DacTrim(void) 
{
    uint8 mode;

    mode = (uint8)((Gate_Drive_Tune_CR0 & Gate_Drive_Tune_RANGE_MASK) >> 2) + Gate_Drive_Tune_TRIM_M7_1V_RNG_OFFSET;
    Gate_Drive_Tune_TR = CY_GET_XTND_REG8((uint8 *)(Gate_Drive_Tune_DAC_TRIM_BASE + mode));
}


/* [] END OF FILE */
