# Simple Blink
### Preview
This folder contains two files that shows how to blink one LED from an MSP430G2553 and MSP430FR2311 development board. The MSP430G2553 c.file is named blinky1.c and the MSP430FR2311 c.file is named blinky2.c. In these files, each microcontroller has it specific pins that  output the signal to turn on the LED but are set at different delay cycles. 

### MSP430G2553
**Description** : The purpose of this lab is to take the MSP43030G2553 and make the pin P1.0 LED blink on and off at a visible rate. The Red LED is tie with a special pin called "P1.0". This pin must be set as an output pin by setting a bit in a special register called "P1DIR". Setting the first bit from pin "P1DIR" as a value of 1 lets it become an output and setting first bit from the pin as a bit value of 0 lets become an input.

### MSP430FR2311
**Description** : The purpose of this lab is to take the MSP430F5529 and make the pin P4.7 LED blink on and off at a visible rate. The second LED is tie with a special pin called "P4.7". This pin must be set as an output pin by setting a bit in a special register called "P4DIR". Setting the first bit from pin "P4DIR" as a value of 1 lets it become an output and setting first bit from the pin as a bit value of 0 lets become an input.

### Watchdog Timers
Both are set to have their watchdog timers off so that the controllers do not reset everytime when they're looping. In fact, watchdog timers keeps track of any abnormal behavior from the program. If the program fails and it "crashes," then the watchdog timer will trigger a reset and force the program back to the beginning. This needs to be disable so that the function of the code works.

### While Loop
The loop infinitely makes the LED blink until the program is stopped in the debugging. The loop contains the pin value of the LED and a XOR logic to toggle the pin value "high" and "low" or "ON" or "OFF". 
