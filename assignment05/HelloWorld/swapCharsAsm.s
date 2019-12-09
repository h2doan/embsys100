/*******************************************************************************
File name       : swapCharsAsm.s
Description     : Assembly language function for swapping two chars.
*******************************************************************************/   

    EXTERN PrintString      // PrintString is defined outside this file.
    EXTERN myCstrSwapChars  // myCstrSwapChars defined outside this file.
    
    PUBLIC swapCharsAsm     // Exports symbols to other modules
                            // Making swapCharsAsm available to other modules.
    
// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables. The syntax for declaring bss section is -
//      The text section is used for keeping the actual code.

// CODE: Interprets subsequent instructions as Arm or Thumb instructions, 
// depending on the setting of related assembler options.

// NOREORDER (the default mode) starts a new fragment in the section
// with the given name, or a new section if no such section exists.
// REORDER starts a new section with the given name.

// NOROOT means that the section fragment is discarded by the linker if
// no symbols in this section fragment are referred to. Normally, all
// section fragments except startup code and interrupt vectors should
// set this flag.

// The (2) is for the (align)
// The power of two to which the address should be aligned.
// The permitted range is 0 to 8. 
// Code aligned at 4 Bytes.

    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : swapCharsAsm
Description     : Calls C code to print a string; 
                  swap the content of the first and second char pointer
                  parameters. 
C Prototype     : int swapCharsAsm(char *aVar, char *bVar)
                : Where aVar and bVar are pointer to char.
Parameters      : R0 contains the address of the first char,
                : R1 contains the address of the second char.
Return value    : R0 is 0 if both value of the parameters are the same.
                : R0 is 1 if they are different.
*******************************************************************************/  
  
swapCharsAsm
    PUSH {R0-R6,LR}      // Save input arguments and return address
    LDR R0,=myCstrSwapChars // Load (global) address of address of string into R0
    LDR R0,[R0]         // Load address of string into R0
    BL  PrintString     // Call PrintString to print the string
    POP {R0-R6,LR}      // Restore input arguments and return address

    PUSH {R4-R6}        // Save R4-R6 per AAPCS standard.
    MOV R2, R0          // Store the first parameter, the address of the
                        // first char pointer pointing, to R2.
                        
    MOV R0, #0x0        // Store the return result, default value 0 to R0.
    
    MOV R3, #0x0        // Initialize the local temporary variable with 0.
    
    LDRB R4, [R2]       // Read the value at the memory location stored in R2
                        // which is the content of the address which the 
                        // first char pointer is pointing. Store the value in
                        // R4. This is tempVar = *aVar.
                        
    LDRB R5, [R1]       // Read the value at the memory location stored in R1
                        // which is the content of the address which the
                        // second char pointer is pointing. Store the value in
                        // R5. This is R5 = *bVar.
                        
    STRB R5, [R2]       // Write the value stored in R5, which is the second
                        // char, to the memory location stored in R2.
                        // This is *aVar = *bVar.
                        
    STRB R4, [R1]       // Write the value stored in R4, which is the first
                        // char, to the memory location stored in R1.
                        // This is *bVar = tempVar. The swapping is completed.
        
    LDRB R5, [R2]       // Read the content of the memory location stored at R2.
    LDRB R6, [R1]       // Read the content of the memory location stored at R1.
    CMP  R5, R6         // Compare R5 and R6.
    BEQ.N SameChars     // If they are the same, go to label SameChars.
        
    MOV  R3, #0x1       // The two values are different, returns 1.
    MOV  R0, R3         // Store the content of R3, which is 1, to R0.

SameChars:
    POP  {R4-R6}        // Restore saved registers.
    BX LR               // return (with function result in R0)

    END
