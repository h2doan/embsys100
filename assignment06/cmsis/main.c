#include "stm32f401xe.h"

void delay(unsigned int iteration);

void delay(unsigned int iteration)
{
  while (iteration > 0)
  {
    iteration--;
  }
}

int main(void) {
  // RCC Base Address: 0x40023800
  // RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
  // Address offset: 0x30
  // Set bit[0] to 1
  // 1. Enable clock to Peripheral
  //*((unsigned int*)(0x40023800+0x30)) |= 0x1;
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
  
  // GPIOA Base Address: 0x40020000
  // GPIO port mode register (GPIOx_MODER ) (x = A..E and H)
  // Address offset: 0x00
  // Set bit[11:10] to 0x01 so ----> 0x400; To enable Port5 as output
  //*((unsigned int*)(0x40020000+0x00)) |= 0x400;
  GPIOA->MODER |= GPIO_MODER_MODE5_0;
  
  // GPIOA Base Address: 0x40020000
  // GPIO port output data register (GPIOx_ODR ) (x = A..E and H)
  // Address offset: 0x14
  // Set bit[5] to 1 ----> 0x20; Turn LED ON
  // Set bit[5] to 0 ----> 0x00; Turn LED OFF
  while(1)
  {
    delay(1000000);
    //*((unsigned int*)(0x40020000+0x14)) |= (1<<5);
    GPIOA->ODR |= GPIO_ODR_OD5;
    
    delay(1000000);
    //*((unsigned int*)(0x40020000+0x14)) &= ~(1<<5);
    GPIOA->ODR &= ~GPIO_ODR_OD5;
  }
  return 0;
}