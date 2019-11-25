1. Bit-band region
   1. Convert the Blinking Led demo to use the corresponding bit-band address instead of the register address used in the peripheral region. *Please see file main.c in folder assignment04/blinkingLED*
   1. What instructions does the compiler produce in assembly for the “writing” to the GPIO bit when using bit-band address? The instructions were:
   * LDR.N  R1, [PC, #0x28]
   * MOVS   R2, #1
   * STR    R2, [R1]

   1. What were the instructions produced when writing to the GPIOx_ODR bit[5] directly? The instructions were:
   * LDR.N  R1, [PC, #0x30]
   * LDR    R2, [R1]
   * ORRS.W R2, R2, #32
   * STR    R2, [R1]

1. Create a function with multiple arguments (5 arguments for example) and call that function from within another function. Trace through the assembler and note:
   1. How does the calling function pass the values to the called function?
   *The calling function stores the values in to R0, R1, R2, R3 and R4.*
   
   1. What extra code did the compiler generate before calling the function with the multiple arguments?
   *TR R4, [SP]*
   
   1. What extra code did the compiler generate inside the called function with the multiple list of arguments?
   *PUSH {R4}*
   *R4, [SP, #0x4],*
   *...,*
   *POP  {R4}*
   
1. Any other observations?
   *At the end of the calling function, R2 and R3 appeared not be popped as shown by the following statement:
   POP {R0, R1, R4, PC}*
   
1. Following the queue data structure approach, design, implement and test a stack data structure.
*Please see files in folder assignment04/stack*

1. Bonus: Using the power of pointers and type casting, create a function that can determine if a computer is big-endian or little-endian.
*Please see file main.c in folder assignment04/bonus*
