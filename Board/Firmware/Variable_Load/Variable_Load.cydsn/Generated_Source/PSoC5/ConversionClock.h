/*******************************************************************************
* File Name: ConversionClock.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_ConversionClock_H)
#define CY_CLOCK_ConversionClock_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void ConversionClock_Start(void) ;
void ConversionClock_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void ConversionClock_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void ConversionClock_StandbyPower(uint8 state) ;
void ConversionClock_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 ConversionClock_GetDividerRegister(void) ;
void ConversionClock_SetModeRegister(uint8 modeBitMask) ;
void ConversionClock_ClearModeRegister(uint8 modeBitMask) ;
uint8 ConversionClock_GetModeRegister(void) ;
void ConversionClock_SetSourceRegister(uint8 clkSource) ;
uint8 ConversionClock_GetSourceRegister(void) ;
#if defined(ConversionClock__CFG3)
void ConversionClock_SetPhaseRegister(uint8 clkPhase) ;
uint8 ConversionClock_GetPhaseRegister(void) ;
#endif /* defined(ConversionClock__CFG3) */

#define ConversionClock_Enable()                       ConversionClock_Start()
#define ConversionClock_Disable()                      ConversionClock_Stop()
#define ConversionClock_SetDivider(clkDivider)         ConversionClock_SetDividerRegister(clkDivider, 1u)
#define ConversionClock_SetDividerValue(clkDivider)    ConversionClock_SetDividerRegister((clkDivider) - 1u, 1u)
#define ConversionClock_SetMode(clkMode)               ConversionClock_SetModeRegister(clkMode)
#define ConversionClock_SetSource(clkSource)           ConversionClock_SetSourceRegister(clkSource)
#if defined(ConversionClock__CFG3)
#define ConversionClock_SetPhase(clkPhase)             ConversionClock_SetPhaseRegister(clkPhase)
#define ConversionClock_SetPhaseValue(clkPhase)        ConversionClock_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(ConversionClock__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define ConversionClock_CLKEN              (* (reg8 *) ConversionClock__PM_ACT_CFG)
#define ConversionClock_CLKEN_PTR          ((reg8 *) ConversionClock__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define ConversionClock_CLKSTBY            (* (reg8 *) ConversionClock__PM_STBY_CFG)
#define ConversionClock_CLKSTBY_PTR        ((reg8 *) ConversionClock__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define ConversionClock_DIV_LSB            (* (reg8 *) ConversionClock__CFG0)
#define ConversionClock_DIV_LSB_PTR        ((reg8 *) ConversionClock__CFG0)
#define ConversionClock_DIV_PTR            ((reg16 *) ConversionClock__CFG0)

/* Clock MSB divider configuration register. */
#define ConversionClock_DIV_MSB            (* (reg8 *) ConversionClock__CFG1)
#define ConversionClock_DIV_MSB_PTR        ((reg8 *) ConversionClock__CFG1)

/* Mode and source configuration register */
#define ConversionClock_MOD_SRC            (* (reg8 *) ConversionClock__CFG2)
#define ConversionClock_MOD_SRC_PTR        ((reg8 *) ConversionClock__CFG2)

#if defined(ConversionClock__CFG3)
/* Analog clock phase configuration register */
#define ConversionClock_PHASE              (* (reg8 *) ConversionClock__CFG3)
#define ConversionClock_PHASE_PTR          ((reg8 *) ConversionClock__CFG3)
#endif /* defined(ConversionClock__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define ConversionClock_CLKEN_MASK         ConversionClock__PM_ACT_MSK
#define ConversionClock_CLKSTBY_MASK       ConversionClock__PM_STBY_MSK

/* CFG2 field masks */
#define ConversionClock_SRC_SEL_MSK        ConversionClock__CFG2_SRC_SEL_MASK
#define ConversionClock_MODE_MASK          (~(ConversionClock_SRC_SEL_MSK))

#if defined(ConversionClock__CFG3)
/* CFG3 phase mask */
#define ConversionClock_PHASE_MASK         ConversionClock__CFG3_PHASE_DLY_MASK
#endif /* defined(ConversionClock__CFG3) */

#endif /* CY_CLOCK_ConversionClock_H */


/* [] END OF FILE */
