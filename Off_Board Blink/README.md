# Off Board Blink
## Preview
This folder contains two files that shows how to multi-blink two LEDs from an MSP430G2553 and MSP430F5529 development board. The MSP430G2553 c.file is named multiblink1.c and the MSP430F5529 c.file is named multiblink2.c. In these files, each microcontroller has it specific pins that output the signals to turn on and off both LEDs but are set at different delay cycles.

### MSP430G2553
**Description** : The purpose of this lab is to take the MSP43030G2553 and two of its LEDs blink on and off at a visible rate. Both LEDs will blink at different rates and will be delay using cycles to see the pattern. The LEDs are pin P1.0 and P1.6. The watchdog will be disable to not allow an automatic reset and disrupt the functions of the LEDs. P1DIR0 and P1DIR6 will be "on" to let the GPIO be outputs.

### MSP430F5529
**Description** : The purpose of this lab is to take the MSP430F5529 and two of its LEDs blink on and off at a visible rate. Both LEDs will blink at different rates and will be delay using cycles to see the pattern. The LEDs are pin P1.0 and P4.7. The watchdog will be disable to not allow an automatic reset and disrupt the functions of the LEDs. P1DIR0 and P4DIR7 will be "on" to let the GPIO be outputs.

### Watchdog Timers
Both are set to have their watchdog timers off so that the controllers do not reset everytime when they're looping. In fact, watchdog timers keeps track of any abnormal behavior from the program. If the program fails and it "crashes," then the watchdog timer will trigger a reset and force the program back to the beginning. This needs to be disable so that the function of the code works.

### While Loop
Both controllers contain a while loop to infinitely make the LED blink after running the code. The loop contains the pin value of the LED and a XOR logic to toggle the pin value "high" and "low" or "ON" or "OFF".
