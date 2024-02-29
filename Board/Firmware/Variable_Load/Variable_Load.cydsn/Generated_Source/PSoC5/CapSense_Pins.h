/*******************************************************************************
* File Name: CapSense_Pins.h
* Version 3.50
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2008-2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CAPSENSE_CSD_Pins_CapSense_H)
#define CY_CAPSENSE_CSD_Pins_CapSense_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CapSense.h"


/***************************************
*        Function Prototypes
***************************************/

void CapSense_SetAllSensorsDriveMode(uint8 mode) ;
void CapSense_SetAllCmodsDriveMode(uint8 mode) ;
#if (CapSense_CURRENT_SOURCE == CapSense_EXTERNAL_RB)
    void CapSense_SetAllRbsDriveMode(uint8 mode) ;    
#endif  /* (CapSense_CURRENT_SOURCE == CapSense_EXTERNAL_RB) */   


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define CapSense_DM_ALG_HIZ         (PIN_DM_ALG_HIZ)
#define CapSense_DM_DIG_HIZ         (PIN_DM_DIG_HIZ)
#define CapSense_DM_RES_UP          (PIN_DM_RES_UP)
#define CapSense_DM_RES_DWN         (PIN_DM_RES_DWN)
#define CapSense_DM_OD_LO           (PIN_DM_OD_LO)
#define CapSense_DM_OD_HI           (PIN_DM_OD_HI)
#define CapSense_DM_STRONG          (PIN_DM_STRONG)
#define CapSense_DM_RES_UPDWN       (PIN_DM_RES_UPDWN)

/* PC registers defines for sensors */
#define CapSense_PortCH0__BACK__BTN  CapSense_PortCH0__BACK__BTN__PC
#define CapSense_PortCH0__ENTER__BTN  CapSense_PortCH0__ENTER__BTN__PC
#define CapSense_PortCH0__DOWN__BTN  CapSense_PortCH0__DOWN__BTN__PC
#define CapSense_PortCH0__UP__BTN  CapSense_PortCH0__UP__BTN__PC
/* For Cmods*/
#define CapSense_CmodCH0_Cmod_CH0       CapSense_CmodCH0__Cmod_CH0__PC


#endif /* (CY_CAPSENSE_CSD_Pins_CapSense_H) */


/* [] END OF FILE */
