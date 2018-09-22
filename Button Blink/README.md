## Preview
This folder contains two files that shows how to button blink one LED from an MSP430G2553 and MSP430F5529 development board. The MSP430G2553 c.file is named switch1.c and the MSP430F5529 c.file is named switch2.c. In these files, each microcontroller has it specific pins that output the signals to turn on and off their LED using a switch, and are set at different delay cycles to compansate for the switch debouncing effect.

### MSP430G2553
**Description** : The purpose of this lab is to take the MSP430G2553 and make the Red LED blink on and off using a switch. The Red LED is tie with a special pin called "P1.0". This pin must be set as an output pin by setting a bit in a special register called "P1DIR". Setting the first bit from pin "P1DIR" as a value of 1 lets it become an output and setting the first bit from the pin as a bit value of 0 lets become an input. The switching is done by checking the bit value from the P1IN register using an if statement. Pressing the switch on the board toggles the Red LED with a delay; the delay compensates the switch debouncing effect.

### MSP430F5529
**Description** : The purpose of this lab is to take the MSP430F5529 and make the Red LED blink on and off using a switch. The Red LED is tie with a special pin called "P1.0". This pin must be set as an output pin by setting a bit in a special register called "P1DIR". Setting the first bit from pin "P1DIR" as a value of 1 lets it become an output and setting the first bit from the pin as a bit value of 0 lets become an input. The switching is done by checking the bit value from the P1IN register using an if statement. Pressing the switch on the board toggles the Red LED with a delay; the delay compensate the switch debouncing effect. For this microprocessor, the pullup resistor has to be enable so that the pin does not "float" when the button is not press.

### Continuous Switches 
Both switches have delays too compansate the switch debouncing effect but do turn on continuously when the button is hold. Both LEDs from both controllers turn ON and OFF at speed of 2 secs.  

### Watchdog Timers
Both are set to have their watchdog timers off so that the controllers do not reset everytime when they're looping. In fact, watchdog timers keeps track of any abnormal behavior from the program. If the program fails and it "crashes," then the watchdog timer will trigger a reset and force the program back to the beginning. This needs to be disable so that the function of the code works.

### While Loop
Both controllers contain a while loop to infinitely make the LED blink after running the code. The loop contains the pin value of the LED and a XOR logic to toggle the pin value "high" and "low" or "ON" or "OFF".
