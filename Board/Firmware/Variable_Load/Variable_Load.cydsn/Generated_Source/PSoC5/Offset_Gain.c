/*******************************************************************************
* File Name: Offset_Gain.c  
* Version 2.0
*
* Description:
*  This file provides the source code to the API for the PGA 
*  User Module.
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

#if (!CY_PSOC5A)
    #if (CYDEV_VARIABLE_VDDA == 1u)
        #include "CyScBoostClk.h"
    #endif /* (CYDEV_VARIABLE_VDDA == 1u) */
#endif /* (!CY_PSOC5A) */

#if (CY_PSOC5A)
    static Offset_Gain_BACKUP_STRUCT  Offset_Gain_P5backup;
#endif /* (CY_ PSOC5A) */

uint8 Offset_Gain_initVar = 0u;


/*******************************************************************************   
* Function Name: Offset_Gain_Init
********************************************************************************
*
* Summary:
*  Initialize component's parameters to the parameters set by user in the 
*  customizer of the component placed onto schematic. Usually called in 
*  Offset_Gain_Start().
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void Offset_Gain_Init(void) 
{
    /* Set PGA mode */
    Offset_Gain_CR0_REG = Offset_Gain_MODE_PGA;      
    /* Set non-inverting PGA mode and reference mode */
    Offset_Gain_CR1_REG |= Offset_Gain_PGA_NINV;  
    /* Set default gain and ref mode */
    Offset_Gain_CR2_REG = Offset_Gain_VREF_MODE;
    /* Set gain and compensation */
    Offset_Gain_SetGain(Offset_Gain_DEFAULT_GAIN);
    /* Set power */
    Offset_Gain_SetPower(Offset_Gain_DEFAULT_POWER);
}


/*******************************************************************************   
* Function Name: Offset_Gain_Enable
********************************************************************************
*
* Summary:
*  Enables the PGA block operation.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void Offset_Gain_Enable(void) 
{
    /* This is to restore the value of register CR1 and CR2 which is saved 
      in prior to the modifications in stop() API */
    #if (CY_PSOC5A)
        if(Offset_Gain_P5backup.enableState == 1u)
        {
            Offset_Gain_CR1_REG = Offset_Gain_P5backup.scCR1Reg;
            Offset_Gain_CR2_REG = Offset_Gain_P5backup.scCR2Reg;
            Offset_Gain_P5backup.enableState = 0u;
        }
    #endif /* CY_PSOC5A */   

    /* Enable power to the Amp in Active mode*/
    Offset_Gain_PM_ACT_CFG_REG |= Offset_Gain_ACT_PWR_EN;

    /* Enable power to the Amp in Alternative Active mode*/
    Offset_Gain_PM_STBY_CFG_REG |= Offset_Gain_STBY_PWR_EN;
    
    Offset_Gain_PUMP_CR1_REG |= Offset_Gain_PUMP_CR1_SC_CLKSEL;
    
    #if (!CY_PSOC5A)
        #if (CYDEV_VARIABLE_VDDA == 1u)
            if(CyScPumpEnabled == 1u)
            {
                Offset_Gain_BSTCLK_REG &= (uint8)(~Offset_Gain_BST_CLK_INDEX_MASK);
                Offset_Gain_BSTCLK_REG |= Offset_Gain_BST_CLK_EN | CyScBoostClk__INDEX;
                Offset_Gain_SC_MISC_REG |= Offset_Gain_PUMP_FORCE;
                CyScBoostClk_Start();
            }
            else
            {
                Offset_Gain_BSTCLK_REG &= (uint8)(~Offset_Gain_BST_CLK_EN);
                Offset_Gain_SC_MISC_REG &= (uint8)(~Offset_Gain_PUMP_FORCE);
            }
        #endif /* (CYDEV_VARIABLE_VDDA == 1u) */
    #endif /* (!CY_PSOC5A) */
}


/*******************************************************************************
* Function Name: Offset_Gain_Start
********************************************************************************
*
* Summary:
*  The start function initializes the PGA with the default values and sets
*  the power to the given level. A power level of 0, is same as executing
*  the stop function.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void Offset_Gain_Start(void) 
{

    /* This is to restore the value of register CR1 and CR2 which is saved 
      in prior to the modification in stop() API */

    if(Offset_Gain_initVar == 0u)
    {
        Offset_Gain_Init();
        Offset_Gain_initVar = 1u;
    }

    Offset_Gain_Enable();
}


/*******************************************************************************
* Function Name: Offset_Gain_Stop
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
void Offset_Gain_Stop(void) 
{ 
    /* Disble power to the Amp in Active mode template */
    Offset_Gain_PM_ACT_CFG_REG &= (uint8)(~Offset_Gain_ACT_PWR_EN);

    /* Disble power to the Amp in Alternative Active mode template */
    Offset_Gain_PM_STBY_CFG_REG &= (uint8)(~Offset_Gain_STBY_PWR_EN);

    #if (!CY_PSOC5A)
        #if (CYDEV_VARIABLE_VDDA == 1u)
            Offset_Gain_BSTCLK_REG &= (uint8)(~Offset_Gain_BST_CLK_EN);
            /* Disable pumps only if there aren't any SC block in use */
            if ((Offset_Gain_PM_ACT_CFG_REG & Offset_Gain_PM_ACT_CFG_MASK) == 0u)
            {
                Offset_Gain_SC_MISC_REG &= (uint8)(~Offset_Gain_PUMP_FORCE);
                Offset_Gain_PUMP_CR1_REG &= (uint8)(~Offset_Gain_PUMP_CR1_SC_CLKSEL);
                CyScBoostClk_Stop();
            }
        #endif /* CYDEV_VARIABLE_VDDA == 1u */
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */

    /* This sets PGA in zero current mode and output routes are valid */
    #if (CY_PSOC5A)
        Offset_Gain_P5backup.scCR1Reg = Offset_Gain_CR1_REG;
        Offset_Gain_P5backup.scCR2Reg = Offset_Gain_CR2_REG;
        Offset_Gain_CR1_REG = 0x00u;
        Offset_Gain_CR2_REG = 0x00u;
        Offset_Gain_P5backup.enableState = 1u;
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: Offset_Gain_SetPower
********************************************************************************
*
* Summary:
*  Set the power of the PGA.
*
* Parameters:
*  power: Sets power level between (0) and (3) high power
*
* Return:
*  void
*
*******************************************************************************/
void Offset_Gain_SetPower(uint8 power) 
{
    uint8 tmpCR;

    tmpCR = Offset_Gain_CR1_REG & (uint8)(~Offset_Gain_DRIVE_MASK);
    tmpCR |= (power & Offset_Gain_DRIVE_MASK);
    Offset_Gain_CR1_REG = tmpCR;  
}


/*******************************************************************************
* Function Name: Offset_Gain_SetGain
********************************************************************************
*
* Summary:
*  This function sets values of the input and feedback resistors to set a 
*  specific gain of the amplifier.
*
* Parameters:
*  gain: Gain value of PGA (See header file for gain values.)
*
* Return:
*  void 
*
*******************************************************************************/
void Offset_Gain_SetGain(uint8 gain) 
{
    /* Constant array for gain settings */
    const uint8 Offset_Gain_GainArray[9] = { 
        (Offset_Gain_RVAL_0K   | Offset_Gain_R20_40B_40K | Offset_Gain_BIAS_LOW), /* G=1  */
        (Offset_Gain_RVAL_40K  | Offset_Gain_R20_40B_40K | Offset_Gain_BIAS_LOW), /* G=2  */
        (Offset_Gain_RVAL_120K | Offset_Gain_R20_40B_40K | Offset_Gain_BIAS_LOW), /* G=4  */
        (Offset_Gain_RVAL_280K | Offset_Gain_R20_40B_40K | Offset_Gain_BIAS_LOW), /* G=8  */
        (Offset_Gain_RVAL_600K | Offset_Gain_R20_40B_40K | Offset_Gain_BIAS_LOW), /* G=16 */
        (Offset_Gain_RVAL_460K | Offset_Gain_R20_40B_40K | Offset_Gain_BIAS_LOW), /* G=24, Sets Rin as 20k */
        (Offset_Gain_RVAL_620K | Offset_Gain_R20_40B_20K | Offset_Gain_BIAS_LOW), /* G=32 */
        (Offset_Gain_RVAL_470K | Offset_Gain_R20_40B_20K | Offset_Gain_BIAS_LOW), /* G=48, Sets Rin as 10k */
        (Offset_Gain_RVAL_490K | Offset_Gain_R20_40B_20K | Offset_Gain_BIAS_LOW)  /* G=50, Sets Rin as 10k */
    };
    
    /* Constant array for gain compenstion settings */
    const uint8 Offset_Gain_GainComp[9] = { 
        ( Offset_Gain_COMP_4P35PF  | (uint8)( Offset_Gain_REDC_00 >> 2 )), /* G=1  */
        ( Offset_Gain_COMP_4P35PF  | (uint8)( Offset_Gain_REDC_01 >> 2 )), /* G=2  */
        ( Offset_Gain_COMP_3P0PF   | (uint8)( Offset_Gain_REDC_01 >> 2 )), /* G=4  */
        ( Offset_Gain_COMP_3P0PF   | (uint8)( Offset_Gain_REDC_01 >> 2 )), /* G=8  */
        ( Offset_Gain_COMP_3P6PF   | (uint8)( Offset_Gain_REDC_01 >> 2 )), /* G=16 */
        ( Offset_Gain_COMP_3P6PF   | (uint8)( Offset_Gain_REDC_11 >> 2 )), /* G=24 */
        ( Offset_Gain_COMP_3P6PF   | (uint8)( Offset_Gain_REDC_11 >> 2 )), /* G=32 */
        ( Offset_Gain_COMP_3P6PF   | (uint8)( Offset_Gain_REDC_00 >> 2 )), /* G=48 */
        ( Offset_Gain_COMP_3P6PF   | (uint8)( Offset_Gain_REDC_00 >> 2 ))  /* G=50 */
    };
    
    /* Only set new gain if it is a valid gain */
    if( gain <= Offset_Gain_GAIN_MAX)
    {
        /* Clear resistors, redc, and bias */
        Offset_Gain_CR2_REG &= (uint8)(~(Offset_Gain_RVAL_MASK | Offset_Gain_R20_40B_MASK | 
                                Offset_Gain_REDC_MASK | Offset_Gain_BIAS_MASK ));

        /* Set gain value resistors, redc comp, and bias */
        Offset_Gain_CR2_REG |= (Offset_Gain_GainArray[gain] |
                                ((uint8)(Offset_Gain_GainComp[gain] << 2 ) & Offset_Gain_REDC_MASK));

        /* Clear sc_comp  */
        Offset_Gain_CR1_REG &= (uint8)(~Offset_Gain_COMP_MASK);
        /* Set sc_comp  */
        Offset_Gain_CR1_REG |= ( Offset_Gain_GainComp[gain] | Offset_Gain_COMP_MASK );
    }
}


/* [] END OF FILE */
