# **Project Description**



* This project consists of representing a count-up (0 to 31), a countdown(31 to 0), and a count-up of powers of two Numbers(1->2->4->8->16->1->2->4...) using 5 external LEDs representing 5 bits and programmed with HAL drivers.
* Each LED flashing represents a bit set(equal to 1), a LED off represents a bit equals 0.
* Two external push buttons are used to enable each of the use cases: count-up(0 to 31), countdown(31 to 0), and count-up power of two numbers(1-2-4-8-16).



# **Hardware used**



* 1x STM32 Nucleo-64 development board with STM32F401RE MCU.
* 1x USB 2.0 A Male to USB 2.0 Mini B Male Down Angled, 3FT length, 480Mbps.
* 2x Momentary Pushbutton Switch - 12mm Square(SparkFun Accessories).
* 2x SparkFun Resistor 1/4W 10k ohm used with push buttons(Pull down).
* 5x LED(SparkFun Accessories) assorted with Resistor 5mm.
* 1x Full Sized Breadboard(Adafruit Accessories).
* 1x PC Windows 11.
* Multiple Female-Male and Male-Female jumper wires(Adafruit Accessories).





# **Detailed Use Case**



At the beginning, all 5 LEDs blink twice at the same time if nothing is pushed to inform you that you can start using the buttons. This event appear once in the beginning if nothing is pushed.



Here is a description of all the cases you may fall into after a normal starting "twice blinking".



1. No button pushed **(See Demo Video)**--> nothing happens, LEDS stay all off.
   
2. Left button(LB) pushed **(See Demo Video)** --> Enabling count-up(0 to 31) while pushed. Pushing the left button(LB) again will resume the count-up from the last value shown from the last time (LB) was pressed, incremented by one.
   

   **Example:** Last number shown while pushing LB is 8(0b01000), then after using other button or stop triggering LB, and resume pushing LB, you will see the value 9(01001) directly.

   /!\\ When arriving at value 31(0b11111), the count returns to 0 and continues the same normal count-up behaviour.
   

3. Right button(RB) pushed **(See Demo Video)**--> Enabling countdown(31 to 0) while pushed. Pushing the right button(RB) again will resume the countdown from the last value shown last time (RB) was pressed, minus one.
   

   **Example:** Last number shown while pushing LB is 10(0b01010), then after using other button or stop triggering LB, and resume pushing LB, you will see the value 9(01001) directly.

   /!\\ When arriving at value 0(0b0), the count returns to 31 and continues the same normal countdown behaviour.
   

4. Both LB and RB pushed **(See Demo Video)**--> Enabling count-up for power of two numbers(1->2->4->8->16->1->2...) while pushed. Pushing both buttons again will resume count-up from the last value shown while pressing buttons(LB \& RB) multiplied by 2.

   **Example:** Last number shown while pushing (LB \& RB) is 4(0b00100), then after using other button or stop triggering LB \& RB, and resume pushing them you will see directly value 8(0b01000), and continue on the same behaviour-->16...

   /!\\ When arriving at value 16(0b10000), the count returns to 0(0b0) and continues the same normal count-up behaviour for power of two numbers.

   

   

   # **Main Points of the program**

   

* GPIOA Pins 4,5,6,7, and 8 are configured for LED output.

  

* GPIOB Pins 8(Left Push button) and 9(Right Push button) are configured for push button Input.

  

* Delay function implemented with a for loop.

  

* Each of the main 3 if statements reads the state of pins PB8(LB) and PB9(RB) and enables one of the use cases detailed in the precedent title(Detailed use case) and the last if statement(else) is for both buttons pushed(LB \& RB).

  

* Verified functionality on the target board**(See Demo Video).**

  

  

  

  ##### 

