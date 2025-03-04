/*********************************************************
 *                  GPIO Definitions                     *
 *                                                       *
 *  These are the definitions of registers, ports, pins  *
 *  used in the Atmega2560. It also includes function-   *
 *  definitions for setting/clearing pins and ports.     *
 *														 *
 * By: Marius C. K. Gulbrandsen and Daniel Rahme         *
 *********************************************************/

// Header Guard
//---------------------------------------------------
#ifndef __GPIO_DEFINES_H__
#define __GPIO_DEFINES_H__

// Includes
//---------------------------------------------------
#include <avr/io.h>
#include <stdio.h>

// Definitions
//---------------------------------------------------

// Set PORTs and PINs
#define SET_OUTPUT(reg, pin) (reg |= (1 << pin))   // Set PORTx to output
#define SET_INPUT(reg, pin) (reg &= ~(1 << pin))   // Set PORTx to input
#define SET_PIN(port, pin) (port |= (1 << pin))    // Set PINx to HIGH
#define CLEAR_PIN(port, pin) (port &= ~(1 << pin)) // Set PINx to LOW

// Pin definitions
#define PIN_LED PB0     // Status LED
#define PIN_LBUT PB1    // Left push button on board
#define PIN_RBUT PB2    // Right push button on board
#define PIN_JBUT PB3    // Joystick push button on board
#define PIN_MCP_INT PB4 // MCP2515 output interrupt pin

// Values used for PORTs and PINs
#define OUTPUT 1 // Decides to define pin as OUTPUT
#define INPUT 0  // Decides to define pin as INPUT
#define HIGH 1   // Decides to define pin as HIGH
#define LOW 0    // Decides to define pin as LOW

/* Sets the port to either output or input and also sets it to HIGH or LOW.*/
#define SET_PORT(reg, io, port, pin, val) \
    ({                                    \
        /*OUTPUT was selected*/           \
        if ((io) == OUTPUT)               \
        {                                 \
            SET_OUTPUT(reg, pin);         \
                                          \
            /*Set HIGH OR LOW*/           \
            if (val == HIGH)              \
                SET_PIN(port, pin);       \
            else                          \
                CLEAR_PIN(port, pin);     \
        }                                 \
                                          \
        /*INPUT was selected*/            \
        else if ((io) == INPUT)           \
        {                                 \
            SET_INPUT(reg, pin);          \
                                          \
            /*Set HIGH OR LOW*/           \
            if (val == HIGH)              \
                SET_PIN(port, pin);       \
            else                          \
                CLEAR_PIN(port, pin);     \
        }                                 \
    })

// Definitions of pins
//---------------------------------------------------

// Motor related
#define MJ1_REG     DDRH
#define MJ1			PORTH   // The port where motor pins are connected
#define MJ1_OE		PH5  // Encoder pin
#define MJ1_SEL		PH3 // Select pin
#define MJ1_RST		PH6 // Reset pin
#define MJ1_EN		PH4  // Enable pin
#define MJ1_DIR		PH1 // Direction pin

// Motor direction
#define LEFT 0
#define RIGHT 1

// Motor output
#define MJ2 PORTK
#define MJ2_DOUT PINK

// Solenoid
#define SOL_REG DDRD
#define SOL_PORT PORTD
#define SOL_PIN PD2

#endif
