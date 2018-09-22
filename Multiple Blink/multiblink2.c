 /* Rowan University
 * File: multiblink2.c
 * Author: Jan Garcia
 * Course: Intro to Embedded Systems
 * Section: 1
 * Creation Data: 9/15/18
 * Lab 1 - MultiBlink using the MSP430F5529
 *
 * Description: The purpose of this lab is to take the MSP430F5529 and two of its
 *  LEDs blink on and off at a visible rate. Both LEDs will blink at different rates
 *  and will be delay using cycles to see the pattern. The LEDs are pin P1.0 and
 *  P4.7. The watchdog will be disable to not allow an automatic reset and disrupt the
 *  functions of the LEDs. P1DIR0 and P4DIR7 will be "on" to let the GPIO be outputs.
 *
// Lets the compiler set up special names for the msp430.
  #include <msp430.h>

  // BITO is defined as 0x01

  // Main function
    int main()
    {
    /*
     * Watchdog Timer - keeps track of any abnormal behavior from the program.
     * If the program fails and it "crashes," then the watchdog timer will
     * trigger a reset and force the program back to the beginning.
     *
     */
      WDTCTL = WDTPW + WDTHOLD; // the watchdog timer must be turn off.
     /*
     * Special Function Registers: PXSEL and P1DIR are registers selects and
     * are chosen whether the pins operate in GPIO mode or are used for some other
     * configuration describe in its peripheral.
     *
     */
      P1SEL &= ~BIT0; // Setting "P1SEL" 1st bit  as 0 selects GPIO mode.

      P1DIR |= BIT0; // Setting "P1DIR" bit as 1, lets the pin P1.0 be an output.
      P4DIR |= BIT7; // Setting "P4DIR" bit as 1, lets the pin P4.7 be an output.

      // infinite loop.
      while(1)
      {
        // Using XOR toggles the pin value and enables
        // port pin P4.7 for output.
        P4OUT ^= BIT7;

        // Adding a delay to slows down the blinking of the LED.
        __delay_cycles(150000);

        // Using XOR toggles the pin value and enables
        // port pin P1.0 for output.
        P1OUT ^= BIT0;

        // Adding a delay to slows down the blinking of the LED.
        __delay_cycles(250000);

      }

      return 0;
  }
