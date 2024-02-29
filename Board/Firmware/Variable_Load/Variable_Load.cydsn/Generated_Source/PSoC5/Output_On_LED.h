/*******************************************************************************
* File Name: Output_On_LED.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Output_On_LED_H) /* Pins Output_On_LED_H */
#define CY_PINS_Output_On_LED_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Output_On_LED_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Output_On_LED__PORT == 15 && ((Output_On_LED__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Output_On_LED_Write(uint8 value);
void    Output_On_LED_SetDriveMode(uint8 mode);
uint8   Output_On_LED_ReadDataReg(void);
uint8   Output_On_LED_Read(void);
void    Output_On_LED_SetInterruptMode(uint16 position, uint16 mode);
uint8   Output_On_LED_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Output_On_LED_SetDriveMode() function.
     *  @{
     */
        #define Output_On_LED_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Output_On_LED_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Output_On_LED_DM_RES_UP          PIN_DM_RES_UP
        #define Output_On_LED_DM_RES_DWN         PIN_DM_RES_DWN
        #define Output_On_LED_DM_OD_LO           PIN_DM_OD_LO
        #define Output_On_LED_DM_OD_HI           PIN_DM_OD_HI
        #define Output_On_LED_DM_STRONG          PIN_DM_STRONG
        #define Output_On_LED_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Output_On_LED_MASK               Output_On_LED__MASK
#define Output_On_LED_SHIFT              Output_On_LED__SHIFT
#define Output_On_LED_WIDTH              1u

/* Interrupt constants */
#if defined(Output_On_LED__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Output_On_LED_SetInterruptMode() function.
     *  @{
     */
        #define Output_On_LED_INTR_NONE      (uint16)(0x0000u)
        #define Output_On_LED_INTR_RISING    (uint16)(0x0001u)
        #define Output_On_LED_INTR_FALLING   (uint16)(0x0002u)
        #define Output_On_LED_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Output_On_LED_INTR_MASK      (0x01u) 
#endif /* (Output_On_LED__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Output_On_LED_PS                     (* (reg8 *) Output_On_LED__PS)
/* Data Register */
#define Output_On_LED_DR                     (* (reg8 *) Output_On_LED__DR)
/* Port Number */
#define Output_On_LED_PRT_NUM                (* (reg8 *) Output_On_LED__PRT) 
/* Connect to Analog Globals */                                                  
#define Output_On_LED_AG                     (* (reg8 *) Output_On_LED__AG)                       
/* Analog MUX bux enable */
#define Output_On_LED_AMUX                   (* (reg8 *) Output_On_LED__AMUX) 
/* Bidirectional Enable */                                                        
#define Output_On_LED_BIE                    (* (reg8 *) Output_On_LED__BIE)
/* Bit-mask for Aliased Register Access */
#define Output_On_LED_BIT_MASK               (* (reg8 *) Output_On_LED__BIT_MASK)
/* Bypass Enable */
#define Output_On_LED_BYP                    (* (reg8 *) Output_On_LED__BYP)
/* Port wide control signals */                                                   
#define Output_On_LED_CTL                    (* (reg8 *) Output_On_LED__CTL)
/* Drive Modes */
#define Output_On_LED_DM0                    (* (reg8 *) Output_On_LED__DM0) 
#define Output_On_LED_DM1                    (* (reg8 *) Output_On_LED__DM1)
#define Output_On_LED_DM2                    (* (reg8 *) Output_On_LED__DM2) 
/* Input Buffer Disable Override */
#define Output_On_LED_INP_DIS                (* (reg8 *) Output_On_LED__INP_DIS)
/* LCD Common or Segment Drive */
#define Output_On_LED_LCD_COM_SEG            (* (reg8 *) Output_On_LED__LCD_COM_SEG)
/* Enable Segment LCD */
#define Output_On_LED_LCD_EN                 (* (reg8 *) Output_On_LED__LCD_EN)
/* Slew Rate Control */
#define Output_On_LED_SLW                    (* (reg8 *) Output_On_LED__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Output_On_LED_PRTDSI__CAPS_SEL       (* (reg8 *) Output_On_LED__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Output_On_LED_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Output_On_LED__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Output_On_LED_PRTDSI__OE_SEL0        (* (reg8 *) Output_On_LED__PRTDSI__OE_SEL0) 
#define Output_On_LED_PRTDSI__OE_SEL1        (* (reg8 *) Output_On_LED__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Output_On_LED_PRTDSI__OUT_SEL0       (* (reg8 *) Output_On_LED__PRTDSI__OUT_SEL0) 
#define Output_On_LED_PRTDSI__OUT_SEL1       (* (reg8 *) Output_On_LED__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Output_On_LED_PRTDSI__SYNC_OUT       (* (reg8 *) Output_On_LED__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Output_On_LED__SIO_CFG)
    #define Output_On_LED_SIO_HYST_EN        (* (reg8 *) Output_On_LED__SIO_HYST_EN)
    #define Output_On_LED_SIO_REG_HIFREQ     (* (reg8 *) Output_On_LED__SIO_REG_HIFREQ)
    #define Output_On_LED_SIO_CFG            (* (reg8 *) Output_On_LED__SIO_CFG)
    #define Output_On_LED_SIO_DIFF           (* (reg8 *) Output_On_LED__SIO_DIFF)
#endif /* (Output_On_LED__SIO_CFG) */

/* Interrupt Registers */
#if defined(Output_On_LED__INTSTAT)
    #define Output_On_LED_INTSTAT            (* (reg8 *) Output_On_LED__INTSTAT)
    #define Output_On_LED_SNAP               (* (reg8 *) Output_On_LED__SNAP)
    
	#define Output_On_LED_0_INTTYPE_REG 		(* (reg8 *) Output_On_LED__0__INTTYPE)
#endif /* (Output_On_LED__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Output_On_LED_H */


/* [] END OF FILE */
