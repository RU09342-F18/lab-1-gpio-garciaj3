/* Rowan University
 * File: blinky1.c
 * Author: Jan Garcia
 * Course: Intro to Embedded Systems
 * Section: 1
 * Creation Data: 9/15/18
 * Lab 1 - Simple Blink using the MSP430G2553
 *
 * Description: The purpose of this lab is to take the MSP43030G2553 and make the
 * first LED blink on and off at a visible rate. The Red LED is tie with a
 * special pin called "P1.0". This pin must be set as an output pin by setting
 * a bit in a special register called "P1DIR". Setting the first bit
 * from pin "P1DIR" as a value of 1 lets it become an output and setting first
 * bit from the pin as a bit value of 0 lets become an input.
 *
 */

  // Lets the compiler set up special names for the msp430.
  #include <msp430.h>

  // BITO is defined as 0x01


    int main()  // Main function
    {
       /*
       * Watchdog Timer - keeps track of any abnormal behavior from the program.
       * If the program fails and it "crashes," then the watchdog timer will
       * trigger a reset and force the program back to the beginning.
       *
       */
        WDTCTL = WDTPW + WDTHOLD; // Watchdog timer must be off.

        //P1SEL &= ~BIT0; // Setting "P1SEL" 1st bit  as 0 selects GPIO mode.
        P1DIR |= BIT0; // P1.0 set as output.

        while(1) // Infinite loop.
        {
            // Using XOR toggles the pin value and enables
            // port pin P1.0 for output.
            P1OUT ^= BIT0;
            // Adding a delay to slow down the blinking of the LED.
            __delay_cycles(500000);
        }
        return 0;
    }
