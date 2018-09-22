# Off Board Blink
## Details
This folder contains one file that shows how to blink two LEDs using the MSP430G2553 on a breadboard. In this file, the microcontroller has it specific pins that output the signals to turn on and off both LEDs but are set at different delay cycles. The lab requires a breadboard with two mounted LEDs (Red and Green), one 1nF capacitor for bypassing, and two different resistor values of 990 ohms. The pins P1.0 and P1.6 are connected through the resistors and LEDs on the breadboard, respectively. The power supply comes from the 3.3 V pin of the developing board and the ground is connected from the breadboard to the developing board pin GND. The capacitor is connected between the ground and the input pins so it blocks the DC from entering it and instead accepts AC noise that may be on the DC line and shunts or bypasses it to ground. 

### MSP430G2553
**Description** : The purpose of this lab is to take the MSP43030G2553 and two of its LEDs blink on and off at a visible rate. Both LEDs will blink at different rates and will be delay using cycles to see the pattern. The LEDs are pin P1.0 and P1.6. The watchdog will be disable to not allow an automatic reset and disrupt the functions of the LEDs. P1DIR0 and P1DIR6 will be "on" to let the GPIO be outputs.

### Watchdog Timers
Both are set to have their watchdog timers off so that the controllers do not reset everytime when they're looping. In fact, watchdog timers keeps track of any abnormal behavior from the program. If the program fails and it "crashes," then the watchdog timer will trigger a reset and force the program back to the beginning. This needs to be disable so that the function of the code works.

### While Loop
Both controllers contain a while loop to infinitely make the LED blink after running the code. The loop contains the pin value of the LED and a XOR logic to toggle the pin value "high" and "low" or "ON" or "OFF".
