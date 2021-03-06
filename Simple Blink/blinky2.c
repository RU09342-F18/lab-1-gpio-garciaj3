/* Rowan University
 * File: blinky2.c
 * Author: Jan Garcia
 * Course: Intro to Embedded Systems
 * Section: 1
 * Creation Data: 9/15/18
 * Lab 1 - Simple Blink using the MSP430FR2311
 *
 * Description: The purpose of this lab is to take the MSP430FR2311 and make the
 * a LED blink on and off at a visible rate. This LED is tie with a
 * special pin called "P2.0". This pin must be set as an output pin by setting
 * a bit in a special register called "P2DIR". Setting the first bit
 * from pin "P2DIR" as a value of 1 lets it become an output and setting first
 * bit from the pin as a bit value of 0 lets it become an input.
 *
 */

  // Lets the compiler set up special names for the msp430.
  #include <msp430.h>

  // BITO is defined as 0x01

    int main()  // Main function
    {
        PM5CTL0 &= ~LOCKLPM5; // Unlocks pins

       /*
       * Watchdog Timer - keeps track of any abnormal behavior from the program.
       * If the program fails and it "crashes," then the watchdog timer will
       * trigger a reset and force the program back to the beginning.
       *
       */
        WDTCTL = WDTPW + WDTHOLD; // Watchdog timer must be off.
      
        P2DIR |= BIT0; // P2.0 set as output.

        while(1) // Infinite loop.
        {
            // Using XOR toggles the pin value and enables
            // port pin P2.0 for output.
            P2OUT ^= BIT0;
            // Adding delay cycles to slows down the blinking of the LED.
            __delay_cycles(1000000);
        }
        return 0;
    }
