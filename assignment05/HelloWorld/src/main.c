/*******************************************************************************
FILE NAME   : main.c
DESCRIPTION : Where all the magic begins.
	      

Copyright   : David Allegre
            : 2015
	    : All Rights Reserved
*******************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "nucleoboard.h"
#include "hw_init.h"
#include "print.h"

char clr_scrn[] = { 27, 91, 50, 74, 0 };              // esc[2J
/* Public variables ----------------------------------------------------------*/
__IO uint32_t timer;
PRINT_DEFINEBUFFER();           /* required for lightweight sprintf */
/* Private prototype ---------------------------------------------------------*/
void delay(uint32_t time);

// HW5: Prototype of external assembly code functions.
extern int sqrAsm(int value);
extern int div2Asm(int value);
extern int swapCharsAsm(char *aVar, char *bVar);

//HW5: Declare and define myCstr so sqrAsm can print it.
char *myCstr = "Hello from sqrAsm!\n";
char *myCstrDiv = "Hello from div2Asm and before dividing.\n";
char *myCstrSwapChars = "Hello from swapCharsAsm and before swapping.\n";

/*******************************************************************************
Function Name   : main
Description     : 
Parameters      :
Return value    :               */
void main() {
uint8_t foo;
  // HW5: Variables for passing argument and storing the result.
  int operResult = 0;
  int argValue = 0;
  char aChar = 'A';
  char bChar = 'B';
  
  foo = 10;
  Hw_init();
  

  PrintString(clr_scrn); /* Clear entire screen */
  // Change [My name] to your name      //
  PrintString("Huan Doan's Nucleo STM32F401 is ... alive!!!\n");
  RETAILMSG(1, ("Programming Assignment #1: Built %s %s.\r\n\r\n",
              __DATE__,
              __TIME__));  

  //HW5: Call sqrAsm passing in the value to be squared and print the result.
  argValue = 2;
  operResult = sqrAsm(argValue);
  RETAILMSG(1, ("Square of %d is %d\n\n", argValue, operResult));
  
  //HW5: Call div2Asm passing in the value to be divided and print the result.
  argValue = 8;
  operResult = div2Asm(argValue);
  RETAILMSG(1, ("Quotient of %d / 2 is %d\n\n", argValue, operResult));
  
  //HW5: Call swapCharsAsm passing values to be swapped and print the result.
  RETAILMSG(1, ("B4 swapping: aChar= %c, bChar= %c\n", aChar, bChar));
  operResult = swapCharsAsm(&aChar, &bChar);
  RETAILMSG(1, ("After swapping: aChar= %c, bChar= %c, return code= %d\n\n",
                aChar, bChar, operResult));
    
  
  while (foo) {
    GPIO_ToggleBits(GPIO_PORT_LD2, GPIO_PIN_LD2);
    PrintString("EMBSYS CP100A: University of Washington - UART Test Application \n");
    
    delay(1000);
    GPIO_ToggleBits(GPIO_PORT_LD2, GPIO_PIN_LD2);
    
    delay(1000);
    foo--;
  }
  while (1) {
    // loop forever
    asm("nop");
  }
}


void delay(uint32_t time) {
  
  timer = time;
  while(timer) {}
}
void SystemInit(void) {
  // System init is called from the assembly .s file
  // We will configure the clocks in hw_init
  asm("nop");
}
  