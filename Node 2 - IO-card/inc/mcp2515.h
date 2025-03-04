/*********************************************************
 *             CAN Controller: MCP2515                   *
 *                                                       *
 * This is the CAN Driver for controlling the CAN Bus.   *
 * It used an SPI driver to function with the Atmega2560 *
 * By: Marius C. K. Gulbrandsen and Daniel Rahme         *
 *********************************************************/

// Header Guard
//---------------------------------------------------
#ifndef __MCP2515_H_            
#define __MCP2515_H__

// Includes
//---------------------------------------------------
#include <avr/io.h>
#include <stdbool.h>
#include <stdio.h>

// Function Prototypes
//---------------------------------------------------
uint8_t MCP_Init(uint8_t mode);
void    MCP_Reset();
uint8_t MCP_Read(uint8_t address);
void    MCP_Write(uint8_t address, uint8_t data); 
void    MCP_Rts(uint8_t transmitt); 
uint8_t MCP_Read_Status();
void    MCP_Bit_Mod(uint8_t address, uint8_t mask, uint8_t data);
void    MCP_Activate();
void    MCP_Deactivate();

#endif 