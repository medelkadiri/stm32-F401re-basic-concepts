# **Project Description**



* This project enables toggling the LED using an integrated push button on the STM32 Nucleo-64 development board with the STM32F401RE MCU.



# **Main Points of the program**



* GPIOA Pin 5 configured for LED output.



* GPIOC Pin 13 configured for push button Input(GPIOC Pin 13).



* Toggle the LED once each time the push button is triggered (if the condition on the value read in GPIOC pin 13 is met, and use a flag value to make sure the LED doesn't toggle infinitely while activating the push button).



* Verified functionality on the target board.









##### 



