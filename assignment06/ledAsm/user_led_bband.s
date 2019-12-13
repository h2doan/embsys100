/*******************************************************************************
File name       : user_led.s
Description     : Assembly language function for controlling the user LED
*******************************************************************************/   

    EXTERN delay  // delay() is defined outside this file.

    PUBLIC control_user_bb_led         // Exports symbols to other modules

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

// bit_word_addr = bit_band_base + (byte_offset x 32) + (bit_number x 4)
//               = 0x42000000 + (0x20014 x 32) + (5 x 4)
//               = 0x42000000 + 0x400280 + 0x14
//               = 0x42000000 + 0x400294 = 0x42400294
//GPIOA_BASE_ADDR   EQU  0x40020000
GPIOA_ODR_BBAND   EQU  0x42400294

/*******************************************************************************
Function Name   : control_user_bb_led
Description     : - Uses bit band region at base 0x4200.0000
                    to set GPIOA Output Data Register.
                  - Calls another assembly function delay to insert
                    delay loop

C Prototype     : void control_user_led(uint8_t state, uint32_t duration)
                : Where state indicates if LED should be on or off.
Parameters      : R0: uint8_t state
                : R1: uint32_t duration
Return value    : None
*******************************************************************************/  

control_user_bb_led
    
    PUSH  {R4-R11}   // Save R4-R11 registers per AAPCS standard.
    PUSH  {LR}       // Save the input arguments as needed and LR
    MOV   R3, R0     // Copy first parameter to R3 so R0 may be used as return value.
    MOV   R0, R1     // Copy the second parameter, duration of the delay, to R0
                     // to pass it as argument to the function delay.
    BL    delay      // Call delay function to slow down the flashing of LED.
    POP   {LR}       // Restore Registers and LR.
    
    LDR   R2, =GPIOA_ODR_BBAND     // Load the GPIOA_ODR_BBAND address to R2.
                
    STR   R3, [R2]                 // Turn on or off the LED based on the
                                   // parameter state's value. The state's 
                                   // value is written into the memory location
                                   // stored in R2 register.
                                   
    POP   {R4-R11}                 // Restore registers.
    BX    LR                       // Return to calling user.

    END
