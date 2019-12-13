1. Use the CMSIS to implement code that blinks the user LED on the STM32 board.
   * Please see file assignment06/cmsis/main.c.
   
1. Convert the blinking led program into assembly code.
   * Please see the following files 
     * assignment06/ledAsm/main.c
	 * assignment06/ledAsm/delay.s
	 * assignment06/ledAsm/user_led.s
	 
1. Generate the map file for your program and provide details on:

    1. How much total ROM your program is occupying?
	   *  CMSIS version occupies 268 bytes.
	   *  Assembly version occupies 304 bytes.
	   
	1. How much total RAM your program is using?
	   * In both CMSIS and assembly versions, the program uses 8,192 bytes.
	   
	1. What part of your program is using the most ROM?
	   * In both CMSIS and assembly versions, the vector_table_M.o uses the most with 66 bytes.
	   
1. Bonus: Anything that can be done to optimize the usage of ROM or RAM resources? Explain any options.

    * Apparently, the external functions increase the amount of ROM. Perhaps, declare and define functions that have file scope would help to reduce the amount of ROM usage.
	
	* For RAM, reducing the amount of CSTACK may help with optimization.
	
1. Bonus: Re-implement the control_user_led to use the bit-band region for accessing the Output Data Register (ODR) for GPIOA in order to toggle the LED ON/OFF.

    * Please see file assignment06/ledAsm/user_led_bband.s
