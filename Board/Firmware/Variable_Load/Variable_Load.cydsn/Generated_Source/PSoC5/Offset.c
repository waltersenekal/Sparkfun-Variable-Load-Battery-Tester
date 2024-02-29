/*******************************************************************************
* File Name: Offset.c  
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
#include "Offset.h"

#if (CY_PSOC5A)
#include <CyLib.h>
#endif /* CY_PSOC5A */

uint8 Offset_initVar = 0u;

#if (CY_PSOC5A)
    static uint8 Offset_restoreVal = 0u;
#endif /* CY_PSOC5A */

#if (CY_PSOC5A)
    static Offset_backupStruct Offset_backup;
#endif /* CY_PSOC5A */


/*******************************************************************************
* Function Name: Offset_Init
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
void Offset_Init(void) 
{
    Offset_CR0 = (Offset_MODE_V );

    /* Set default data source */
    #if(Offset_DEFAULT_DATA_SRC != 0 )
        Offset_CR1 = (Offset_DEFAULT_CNTL | Offset_DACBUS_ENABLE) ;
    #else
        Offset_CR1 = (Offset_DEFAULT_CNTL | Offset_DACBUS_DISABLE) ;
    #endif /* (Offset_DEFAULT_DATA_SRC != 0 ) */

    /* Set default strobe mode */
    #if(Offset_DEFAULT_STRB != 0)
        Offset_Strobe |= Offset_STRB_EN ;
    #endif/* (Offset_DEFAULT_STRB != 0) */

    /* Set default range */
    Offset_SetRange(Offset_DEFAULT_RANGE); 

    /* Set default speed */
    Offset_SetSpeed(Offset_DEFAULT_SPEED);
}


/*******************************************************************************
* Function Name: Offset_Enable
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
void Offset_Enable(void) 
{
    Offset_PWRMGR |= Offset_ACT_PWR_EN;
    Offset_STBY_PWRMGR |= Offset_STBY_PWR_EN;

    /*This is to restore the value of register CR0 ,
    which is modified  in Stop API , this prevents misbehaviour of VDAC */
    #if (CY_PSOC5A)
        if(Offset_restoreVal == 1u) 
        {
             Offset_CR0 = Offset_backup.data_value;
             Offset_restoreVal = 0u;
        }
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: Offset_Start
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
*  Offset_initVar: Is modified when this function is called for the 
*  first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void Offset_Start(void)  
{
    /* Hardware initiazation only needs to occure the first time */
    if(Offset_initVar == 0u)
    { 
        Offset_Init();
        Offset_initVar = 1u;
    }

    /* Enable power to DAC */
    Offset_Enable();

    /* Set default value */
    Offset_SetValue(Offset_DEFAULT_DATA); 
}


/*******************************************************************************
* Function Name: Offset_Stop
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
void Offset_Stop(void) 
{
    /* Disble power to DAC */
    Offset_PWRMGR &= (uint8)(~Offset_ACT_PWR_EN);
    Offset_STBY_PWRMGR &= (uint8)(~Offset_STBY_PWR_EN);

    /* This is a work around for PSoC5A  ,
    this sets VDAC to current mode with output off */
    #if (CY_PSOC5A)
        Offset_backup.data_value = Offset_CR0;
        Offset_CR0 = Offset_CUR_MODE_OUT_OFF;
        Offset_restoreVal = 1u;
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: Offset_SetSpeed
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
void Offset_SetSpeed(uint8 speed) 
{
    /* Clear power mask then write in new value */
    Offset_CR0 &= (uint8)(~Offset_HS_MASK);
    Offset_CR0 |=  (speed & Offset_HS_MASK);
}


/*******************************************************************************
* Function Name: Offset_SetRange
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
void Offset_SetRange(uint8 range) 
{
    Offset_CR0 &= (uint8)(~Offset_RANGE_MASK);      /* Clear existing mode */
    Offset_CR0 |= (range & Offset_RANGE_MASK);      /*  Set Range  */
    Offset_DacTrim();
}


/*******************************************************************************
* Function Name: Offset_SetValue
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
void Offset_SetValue(uint8 value) 
{
    #if (CY_PSOC5A)
        uint8 Offset_intrStatus = CyEnterCriticalSection();
    #endif /* CY_PSOC5A */

    Offset_Data = value;                /*  Set Value  */

    /* PSOC5A requires a double write */
    /* Exit Critical Section */
    #if (CY_PSOC5A)
        Offset_Data = value;
        CyExitCriticalSection(Offset_intrStatus);
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: Offset_DacTrim
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
void Offset_DacTrim(void) 
{
    uint8 mode;

    mode = (uint8)((Offset_CR0 & Offset_RANGE_MASK) >> 2) + Offset_TRIM_M7_1V_RNG_OFFSET;
    Offset_TR = CY_GET_XTND_REG8((uint8 *)(Offset_DAC_TRIM_BASE + mode));
}


/* [] END OF FILE */
