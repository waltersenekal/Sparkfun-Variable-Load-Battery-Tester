/*******************************************************************************
* File Name: GateDrive.h  
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

#if !defined(CY_PINS_GateDrive_H) /* Pins GateDrive_H */
#define CY_PINS_GateDrive_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "GateDrive_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 GateDrive__PORT == 15 && ((GateDrive__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    GateDrive_Write(uint8 value);
void    GateDrive_SetDriveMode(uint8 mode);
uint8   GateDrive_ReadDataReg(void);
uint8   GateDrive_Read(void);
void    GateDrive_SetInterruptMode(uint16 position, uint16 mode);
uint8   GateDrive_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the GateDrive_SetDriveMode() function.
     *  @{
     */
        #define GateDrive_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define GateDrive_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define GateDrive_DM_RES_UP          PIN_DM_RES_UP
        #define GateDrive_DM_RES_DWN         PIN_DM_RES_DWN
        #define GateDrive_DM_OD_LO           PIN_DM_OD_LO
        #define GateDrive_DM_OD_HI           PIN_DM_OD_HI
        #define GateDrive_DM_STRONG          PIN_DM_STRONG
        #define GateDrive_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define GateDrive_MASK               GateDrive__MASK
#define GateDrive_SHIFT              GateDrive__SHIFT
#define GateDrive_WIDTH              1u

/* Interrupt constants */
#if defined(GateDrive__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in GateDrive_SetInterruptMode() function.
     *  @{
     */
        #define GateDrive_INTR_NONE      (uint16)(0x0000u)
        #define GateDrive_INTR_RISING    (uint16)(0x0001u)
        #define GateDrive_INTR_FALLING   (uint16)(0x0002u)
        #define GateDrive_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define GateDrive_INTR_MASK      (0x01u) 
#endif /* (GateDrive__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define GateDrive_PS                     (* (reg8 *) GateDrive__PS)
/* Data Register */
#define GateDrive_DR                     (* (reg8 *) GateDrive__DR)
/* Port Number */
#define GateDrive_PRT_NUM                (* (reg8 *) GateDrive__PRT) 
/* Connect to Analog Globals */                                                  
#define GateDrive_AG                     (* (reg8 *) GateDrive__AG)                       
/* Analog MUX bux enable */
#define GateDrive_AMUX                   (* (reg8 *) GateDrive__AMUX) 
/* Bidirectional Enable */                                                        
#define GateDrive_BIE                    (* (reg8 *) GateDrive__BIE)
/* Bit-mask for Aliased Register Access */
#define GateDrive_BIT_MASK               (* (reg8 *) GateDrive__BIT_MASK)
/* Bypass Enable */
#define GateDrive_BYP                    (* (reg8 *) GateDrive__BYP)
/* Port wide control signals */                                                   
#define GateDrive_CTL                    (* (reg8 *) GateDrive__CTL)
/* Drive Modes */
#define GateDrive_DM0                    (* (reg8 *) GateDrive__DM0) 
#define GateDrive_DM1                    (* (reg8 *) GateDrive__DM1)
#define GateDrive_DM2                    (* (reg8 *) GateDrive__DM2) 
/* Input Buffer Disable Override */
#define GateDrive_INP_DIS                (* (reg8 *) GateDrive__INP_DIS)
/* LCD Common or Segment Drive */
#define GateDrive_LCD_COM_SEG            (* (reg8 *) GateDrive__LCD_COM_SEG)
/* Enable Segment LCD */
#define GateDrive_LCD_EN                 (* (reg8 *) GateDrive__LCD_EN)
/* Slew Rate Control */
#define GateDrive_SLW                    (* (reg8 *) GateDrive__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define GateDrive_PRTDSI__CAPS_SEL       (* (reg8 *) GateDrive__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define GateDrive_PRTDSI__DBL_SYNC_IN    (* (reg8 *) GateDrive__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define GateDrive_PRTDSI__OE_SEL0        (* (reg8 *) GateDrive__PRTDSI__OE_SEL0) 
#define GateDrive_PRTDSI__OE_SEL1        (* (reg8 *) GateDrive__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define GateDrive_PRTDSI__OUT_SEL0       (* (reg8 *) GateDrive__PRTDSI__OUT_SEL0) 
#define GateDrive_PRTDSI__OUT_SEL1       (* (reg8 *) GateDrive__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define GateDrive_PRTDSI__SYNC_OUT       (* (reg8 *) GateDrive__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(GateDrive__SIO_CFG)
    #define GateDrive_SIO_HYST_EN        (* (reg8 *) GateDrive__SIO_HYST_EN)
    #define GateDrive_SIO_REG_HIFREQ     (* (reg8 *) GateDrive__SIO_REG_HIFREQ)
    #define GateDrive_SIO_CFG            (* (reg8 *) GateDrive__SIO_CFG)
    #define GateDrive_SIO_DIFF           (* (reg8 *) GateDrive__SIO_DIFF)
#endif /* (GateDrive__SIO_CFG) */

/* Interrupt Registers */
#if defined(GateDrive__INTSTAT)
    #define GateDrive_INTSTAT            (* (reg8 *) GateDrive__INTSTAT)
    #define GateDrive_SNAP               (* (reg8 *) GateDrive__SNAP)
    
	#define GateDrive_0_INTTYPE_REG 		(* (reg8 *) GateDrive__0__INTTYPE)
#endif /* (GateDrive__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_GateDrive_H */


/* [] END OF FILE */
