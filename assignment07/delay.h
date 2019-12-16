#ifndef __DELAY_H
#define __DELAY_H
#include "stdint.h"
#include "stm32f401xe.h"

void delay(unsigned int iteration);

void resetCounterSeconds(void);
void incCounterSeconds(void);
void delayMsec(uint32_t delayInMilliseconds);

#endif