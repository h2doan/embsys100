1. Swapping of two pointers
   1. Explain what the “main” function does to the CSTACK in order setup the input arguments prior to calling the swap_pointer() function?
      * It stores variables onto CSTACK.*
   
   1. And what are the values in R0 & R1 when swap_pointer() is called?
      * R0 has the value 0x200003F0 which is the address of variable y.*
      * R1 has the value 0x200003E8 which is the address of int pointer variable yPtr.*
   
   1. Share a screen shot of the local variables inside of “main” after the function swap_pointer() returns, showing the values of the pointers and what they are pointing to.
      * Please see the following image *
   ![result](https://github.com/h2doan/embsys100/tree/master/assignment05/images/embSysHW5-1c.PNG)

1. Run sqrAsm code from the class demo:
   * Run your program on the board, and capture a snapshot image of the output from TeraTerm.*
      * Please see files sqrAsm.s, main.c and the following image *
   ![result](https://github.com/h2doan/embsys100/tree/master/assignment05/images/embSysHW5-2e.PNG)
   
1. Create a new file div2Asm.s and add the file to the same HelloWorld project above.
   * In the main.c, invoke dev2Asm(foo) and capture the screen output from TeraTerm.*
      * Please see files div2Asm.s, main.c and the following image *
   ![result](https://github.com/h2doan/embsys100/tree/master/assignment05/images/embSysHW5-3d.PNG)   
   
1. Implement a swap function in assembly and call it “swapCharsAsm”
   * Bonus: Returns 0 if the two chars are identical; otherwise, return 1.*
      * Please see files swapCharsAsm.s, main.c and the following image *
   ![result](https://github.com/h2doan/embsys100/tree/master/assignment05/images/embSysHW5-4.PNG)

