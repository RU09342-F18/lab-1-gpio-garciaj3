/* Rowan University
 * File: main.c
 * Author: Jan Garcia
 * Course: Intro to Embedded Systems
 * Section: 1
 * Creation Data: 9/15/18
 * Lab 1 - Button Blink using the MSP430F5529
 *
 * Description: The purpose of this lab is to take the MSP430F5529 and make the
 * Red LED blink on and off using a switch. The Red LED is tie with a
 * special pin called "P1.0". This pin must be set as an output pin by setting
 * a bit in a special register called "P1DIR". Setting the first bit
 * from pin "P1DIR" as a value of 1 lets it become an output and setting the first
 * bit from the pin as a bit value of 0 lets become an input. The switching is done
 * by checking the bit value from the P1IN register using an if statement.
 * Pressing the switch on the board toggles the Red LED with a delay;
 * the delay compensate the switch debouncing effect. For this microprocessor,
 * the pullup resistor has to enable so that the pin does not "float" when the
 * button is not press.
 *
 */

#include <msp430.h> 
// BITO is defined as 0x01


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW + WDTHOLD; // Stops the watchdog timer
   // P1SEL &= ~BIT0; // Setting "P1SEL" 1st bit  as 0 selects GPIO mode.
    P1DIR |= BIT0; // P1.0 set as output - .

    // Input is connected to resistor
    P2REN |= BIT1; // Enable resistor for P2.1.
    P2OUT &= BIT1; // Enable P2.1 as a pullup resistor


    while(1) // Infinte loop
    {
       if((P2IN & BIT1) == 0) // Checks pin P2.1 if it has been reset then toggles the LED.
       {
           P1OUT ^= BIT0; // Using XOR toggles the pin value and enables port pin P1.0 for output.
           __delay_cycles(400000); // Add delay for each toggle.
       }
    }


    return 0;
}
