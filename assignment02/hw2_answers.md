1. Inject 0x7FFFFFFF for the “counter” value in the variable window, then step thru the program only once to increment “counter”.
   1. What is the value of the “counter” from the “Locals” window?
   *The value is -2147483648.*
   1. What is the value of the “counter” in the “Register” window?
   *The value is 0x90000000.*
   1. Please note if the N and/or V flags are set in the APSR register? Explain why?
   *The N and V flags are both set to "1". The reason is the most significant bit, the sign bit, is set to 1 due to adding one to 0x7FFFFFFF; thus, the result is negative and overflow has occurred.*
   
2. If your write all Fs (0XFFFFFFFF) in the Register value for “counter” then step thru the program once to increment “counter”.
   1. What is the value of “counter” in the “Locals” window after incrementing for each value?
   *The value is zero.*
   1. Please note if the N and/or V flags are set in the APSR register? Explain why?
   *The N and V flags are not set. The N flag isn't set because adding 1 to the large negative value 0xFFFFFFFF caused the sign bit to be zero. The V flag isn't set because no overflow occurred.*
   
3. Change the “counter” variable type in your code to “unsigned”. Inject the values “0x7FFFFFFF” then step through the program to increment the “counter” once.
   1. What is the value of “counter” in the “Locals” window after incrementing for each value?
   *The value is 2147483648.*
   1. Please note if the N and/or V flags are set in the APSR register? Explain why?
   *The N flag is set because although the result is positive but the sign bit is 1. The V flag is set to 1 is probably the most significant bit is considered as sign bit; thus, the result is considered to be overflowed.*
   
4. Change the “counter” variable type in your code to “unsigned”. Inject the values “0xFFFFFFFF” then step through the program to increment the “counter” once.
   1. What is the value of “counter” in the “Locals” window after incrementing for each value?
   *The value is zero.*
   1. Please note if the N and/or V flags are set in the APSR register? Explain why?
   *Both of the N and V flags are not set. Assuming the most significant bit is considered the sign bit, increasing by 1 caused the bit to be set to 0. thus, the result is positive and the N flag is not set. Since the result is zero, no overflow occurred.*
   
5. Move the “counter" variable outside of main (at the top of the file).
   1. What is the scope of the variable “counter”?
   *The scope is global.*
   1. Is it still visible in the “Locals” view?
   *No, it isn't.*
   1. In which window view can we track “counter” now?
   *In Memory window.*
   1. What is the address of the “counter” variable in memory?
   *The address is 0x20000000.*
   
6. Pointer
   1. What is the value of “counter” at the end of the program (halting at the return 0 statement)?
   *The value of "counter" is 4.*
   1. Explain why the counter value has changed?
   *The counter value changed because the int pointer p_int is pointed to its memory location. The value of the counter is exposed by de-referencing the pointer p_int. The pre-increment of the de-referenced pointer p_int changed the counter's value.*
   
7. Run the pointer variable program on evaluation board
   1. What is the address where “counter” is stored?
   *The address is 0x20000000.*
   1. Is the “counter” variable stored in RAM or ROM?
   *The counter variable is stored in RAM.*
   1. What is the value of “counter” at the end of the program (halting at the return 0 statement).
   *The value is 4."
   

   