/*******************************************************************************
* File Name: VRef.h  
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

#if !defined(CY_PINS_VRef_H) /* Pins VRef_H */
#define CY_PINS_VRef_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "VRef_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 VRef__PORT == 15 && ((VRef__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    VRef_Write(uint8 value);
void    VRef_SetDriveMode(uint8 mode);
uint8   VRef_ReadDataReg(void);
uint8   VRef_Read(void);
void    VRef_SetInterruptMode(uint16 position, uint16 mode);
uint8   VRef_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the VRef_SetDriveMode() function.
     *  @{
     */
        #define VRef_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define VRef_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define VRef_DM_RES_UP          PIN_DM_RES_UP
        #define VRef_DM_RES_DWN         PIN_DM_RES_DWN
        #define VRef_DM_OD_LO           PIN_DM_OD_LO
        #define VRef_DM_OD_HI           PIN_DM_OD_HI
        #define VRef_DM_STRONG          PIN_DM_STRONG
        #define VRef_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define VRef_MASK               VRef__MASK
#define VRef_SHIFT              VRef__SHIFT
#define VRef_WIDTH              1u

/* Interrupt constants */
#if defined(VRef__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in VRef_SetInterruptMode() function.
     *  @{
     */
        #define VRef_INTR_NONE      (uint16)(0x0000u)
        #define VRef_INTR_RISING    (uint16)(0x0001u)
        #define VRef_INTR_FALLING   (uint16)(0x0002u)
        #define VRef_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define VRef_INTR_MASK      (0x01u) 
#endif /* (VRef__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define VRef_PS                     (* (reg8 *) VRef__PS)
/* Data Register */
#define VRef_DR                     (* (reg8 *) VRef__DR)
/* Port Number */
#define VRef_PRT_NUM                (* (reg8 *) VRef__PRT) 
/* Connect to Analog Globals */                                                  
#define VRef_AG                     (* (reg8 *) VRef__AG)                       
/* Analog MUX bux enable */
#define VRef_AMUX                   (* (reg8 *) VRef__AMUX) 
/* Bidirectional Enable */                                                        
#define VRef_BIE                    (* (reg8 *) VRef__BIE)
/* Bit-mask for Aliased Register Access */
#define VRef_BIT_MASK               (* (reg8 *) VRef__BIT_MASK)
/* Bypass Enable */
#define VRef_BYP                    (* (reg8 *) VRef__BYP)
/* Port wide control signals */                                                   
#define VRef_CTL                    (* (reg8 *) VRef__CTL)
/* Drive Modes */
#define VRef_DM0                    (* (reg8 *) VRef__DM0) 
#define VRef_DM1                    (* (reg8 *) VRef__DM1)
#define VRef_DM2                    (* (reg8 *) VRef__DM2) 
/* Input Buffer Disable Override */
#define VRef_INP_DIS                (* (reg8 *) VRef__INP_DIS)
/* LCD Common or Segment Drive */
#define VRef_LCD_COM_SEG            (* (reg8 *) VRef__LCD_COM_SEG)
/* Enable Segment LCD */
#define VRef_LCD_EN                 (* (reg8 *) VRef__LCD_EN)
/* Slew Rate Control */
#define VRef_SLW                    (* (reg8 *) VRef__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define VRef_PRTDSI__CAPS_SEL       (* (reg8 *) VRef__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define VRef_PRTDSI__DBL_SYNC_IN    (* (reg8 *) VRef__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define VRef_PRTDSI__OE_SEL0        (* (reg8 *) VRef__PRTDSI__OE_SEL0) 
#define VRef_PRTDSI__OE_SEL1        (* (reg8 *) VRef__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define VRef_PRTDSI__OUT_SEL0       (* (reg8 *) VRef__PRTDSI__OUT_SEL0) 
#define VRef_PRTDSI__OUT_SEL1       (* (reg8 *) VRef__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define VRef_PRTDSI__SYNC_OUT       (* (reg8 *) VRef__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(VRef__SIO_CFG)
    #define VRef_SIO_HYST_EN        (* (reg8 *) VRef__SIO_HYST_EN)
    #define VRef_SIO_REG_HIFREQ     (* (reg8 *) VRef__SIO_REG_HIFREQ)
    #define VRef_SIO_CFG            (* (reg8 *) VRef__SIO_CFG)
    #define VRef_SIO_DIFF           (* (reg8 *) VRef__SIO_DIFF)
#endif /* (VRef__SIO_CFG) */

/* Interrupt Registers */
#if defined(VRef__INTSTAT)
    #define VRef_INTSTAT            (* (reg8 *) VRef__INTSTAT)
    #define VRef_SNAP               (* (reg8 *) VRef__SNAP)
    
	#define VRef_0_INTTYPE_REG 		(* (reg8 *) VRef__0__INTTYPE)
#endif /* (VRef__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_VRef_H */


/* [] END OF FILE */
