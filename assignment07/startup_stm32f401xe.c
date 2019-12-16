#include "stm32f401xe.h"
#include "delay.h"

extern int CSTACK$$Limit;
extern void __iar_program_start;

void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);

int const __vector_table[] @ ".intvec" = {
  (int) &CSTACK$$Limit,          // SP address
  (int) &__iar_program_start,    // PC address
  (int) &NMI_Handler,
  (int) &HardFault_Handler,
  (int) &MemManage_Handler,
  (int) &BusFault_Handler,
  (int) &UsageFault_Handler,
  0,                             // Reserved
  0,                             // Reserved
  0,                             // Reserved
  0,                             // Reserved
  (int) &SVC_Handler,
  (int) &DebugMon_Handler,
  0,                             // Reserved
  (int) &PendSV_Handler,
  (int) &SysTick_Handler
};

void NMI_Handler(void) {
  while (1) {
  }
}

void HardFault_Handler(void) {
  while (1) {
  }
}

void MemManage_Handler(void) {
  while (1) {
  }
}

void BusFault_Handler(void) {
  while (1) {
  }
}

void UsageFault_Handler(void) {
  while (1) {
  }
}

void SVC_Handler(void) {
}

void DebugMon_Handler(void) {
}

void PendSV_Handler(void) {
}

void SysTick_Handler(void) {
  GPIOA->ODR ^= GPIO_ODR_OD5;
  
  // Bonus problem.  Interrupt every 1 msec.
  //incCounterSeconds();
}
