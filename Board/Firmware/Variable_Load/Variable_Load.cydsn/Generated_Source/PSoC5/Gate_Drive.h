/*******************************************************************************
* File Name: Gate_Drive.h  
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

#if !defined(CY_PINS_Gate_Drive_H) /* Pins Gate_Drive_H */
#define CY_PINS_Gate_Drive_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Gate_Drive_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Gate_Drive__PORT == 15 && ((Gate_Drive__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Gate_Drive_Write(uint8 value);
void    Gate_Drive_SetDriveMode(uint8 mode);
uint8   Gate_Drive_ReadDataReg(void);
uint8   Gate_Drive_Read(void);
void    Gate_Drive_SetInterruptMode(uint16 position, uint16 mode);
uint8   Gate_Drive_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Gate_Drive_SetDriveMode() function.
     *  @{
     */
        #define Gate_Drive_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Gate_Drive_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Gate_Drive_DM_RES_UP          PIN_DM_RES_UP
        #define Gate_Drive_DM_RES_DWN         PIN_DM_RES_DWN
        #define Gate_Drive_DM_OD_LO           PIN_DM_OD_LO
        #define Gate_Drive_DM_OD_HI           PIN_DM_OD_HI
        #define Gate_Drive_DM_STRONG          PIN_DM_STRONG
        #define Gate_Drive_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Gate_Drive_MASK               Gate_Drive__MASK
#define Gate_Drive_SHIFT              Gate_Drive__SHIFT
#define Gate_Drive_WIDTH              1u

/* Interrupt constants */
#if defined(Gate_Drive__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Gate_Drive_SetInterruptMode() function.
     *  @{
     */
        #define Gate_Drive_INTR_NONE      (uint16)(0x0000u)
        #define Gate_Drive_INTR_RISING    (uint16)(0x0001u)
        #define Gate_Drive_INTR_FALLING   (uint16)(0x0002u)
        #define Gate_Drive_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Gate_Drive_INTR_MASK      (0x01u) 
#endif /* (Gate_Drive__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Gate_Drive_PS                     (* (reg8 *) Gate_Drive__PS)
/* Data Register */
#define Gate_Drive_DR                     (* (reg8 *) Gate_Drive__DR)
/* Port Number */
#define Gate_Drive_PRT_NUM                (* (reg8 *) Gate_Drive__PRT) 
/* Connect to Analog Globals */                                                  
#define Gate_Drive_AG                     (* (reg8 *) Gate_Drive__AG)                       
/* Analog MUX bux enable */
#define Gate_Drive_AMUX                   (* (reg8 *) Gate_Drive__AMUX) 
/* Bidirectional Enable */                                                        
#define Gate_Drive_BIE                    (* (reg8 *) Gate_Drive__BIE)
/* Bit-mask for Aliased Register Access */
#define Gate_Drive_BIT_MASK               (* (reg8 *) Gate_Drive__BIT_MASK)
/* Bypass Enable */
#define Gate_Drive_BYP                    (* (reg8 *) Gate_Drive__BYP)
/* Port wide control signals */                                                   
#define Gate_Drive_CTL                    (* (reg8 *) Gate_Drive__CTL)
/* Drive Modes */
#define Gate_Drive_DM0                    (* (reg8 *) Gate_Drive__DM0) 
#define Gate_Drive_DM1                    (* (reg8 *) Gate_Drive__DM1)
#define Gate_Drive_DM2                    (* (reg8 *) Gate_Drive__DM2) 
/* Input Buffer Disable Override */
#define Gate_Drive_INP_DIS                (* (reg8 *) Gate_Drive__INP_DIS)
/* LCD Common or Segment Drive */
#define Gate_Drive_LCD_COM_SEG            (* (reg8 *) Gate_Drive__LCD_COM_SEG)
/* Enable Segment LCD */
#define Gate_Drive_LCD_EN                 (* (reg8 *) Gate_Drive__LCD_EN)
/* Slew Rate Control */
#define Gate_Drive_SLW                    (* (reg8 *) Gate_Drive__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Gate_Drive_PRTDSI__CAPS_SEL       (* (reg8 *) Gate_Drive__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Gate_Drive_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Gate_Drive__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Gate_Drive_PRTDSI__OE_SEL0        (* (reg8 *) Gate_Drive__PRTDSI__OE_SEL0) 
#define Gate_Drive_PRTDSI__OE_SEL1        (* (reg8 *) Gate_Drive__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Gate_Drive_PRTDSI__OUT_SEL0       (* (reg8 *) Gate_Drive__PRTDSI__OUT_SEL0) 
#define Gate_Drive_PRTDSI__OUT_SEL1       (* (reg8 *) Gate_Drive__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Gate_Drive_PRTDSI__SYNC_OUT       (* (reg8 *) Gate_Drive__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Gate_Drive__SIO_CFG)
    #define Gate_Drive_SIO_HYST_EN        (* (reg8 *) Gate_Drive__SIO_HYST_EN)
    #define Gate_Drive_SIO_REG_HIFREQ     (* (reg8 *) Gate_Drive__SIO_REG_HIFREQ)
    #define Gate_Drive_SIO_CFG            (* (reg8 *) Gate_Drive__SIO_CFG)
    #define Gate_Drive_SIO_DIFF           (* (reg8 *) Gate_Drive__SIO_DIFF)
#endif /* (Gate_Drive__SIO_CFG) */

/* Interrupt Registers */
#if defined(Gate_Drive__INTSTAT)
    #define Gate_Drive_INTSTAT            (* (reg8 *) Gate_Drive__INTSTAT)
    #define Gate_Drive_SNAP               (* (reg8 *) Gate_Drive__SNAP)
    
	#define Gate_Drive_0_INTTYPE_REG 		(* (reg8 *) Gate_Drive__0__INTTYPE)
#endif /* (Gate_Drive__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Gate_Drive_H */


/* [] END OF FILE */
